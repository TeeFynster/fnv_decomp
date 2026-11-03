"""Extract one explicitly proven zero-relocation code COMDAT; not a general linker."""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import struct
import tempfile

from coff_inventory import Coff, reconcile_recipes, symbol_kind
from coff_rewrite import strict_object

ROOT = Path(__file__).resolve().parents[2]
DEFAULTS = {'/DEFAULTLIB:"LIBCMT"', '/DEFAULTLIB:"OLDNAMES"'}


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def select_layout(coff, proof):
    """Return a new COFF plus an explicit drop ledger, without provider inference."""
    matches = [s for s in coff.symbols.values() if s['name'] == proof['symbol']]
    if len(matches) != 1 or symbol_kind(matches[0]) != 'external_definition':
        raise ValueError('root must have one external definition')
    root = matches[0]
    sec = coff.sections[root['section']]
    if (root['section'], root['value']) != (proof['section'], proof['value']) or proof['verdict'] != 'match':
        raise ValueError('native entry differs from retained proof')
    if root['value'] or sec['size'] != proof['size'] or root['aux_count'] or not root['type'] & 0x20:
        raise ValueError('root span is not exactly one whole function')
    if not sec['comdat'] or sec['selection'] == 'associative' or not sec['flags'] & 0x20:
        raise ValueError('root must be a non-associative code COMDAT')
    if sec['selection'] not in ('no_duplicates', 'any', 'same_size', 'exact_match', 'largest', 'newest'):
        raise ValueError('unsupported root COMDAT policy')
    if sec['relocs']:
        raise ValueError('runtime-relocated roots are outside the initial scope')
    members = [s for s in coff.symbols.values() if s['section'] == root['section']]
    section_symbols = [s for s in members if s['name'] == sec['name'] and s['storage'] == 3 and s['value'] == 0 and 'section_aux' in s]
    if len(section_symbols) != 1 or len(members) != 2:
        raise ValueError('shared section or extra local symbols require separate closure review')
    if sec['name'] != '.text' or set(coff.directives) != DEFAULTS:
        raise ValueError('unrecognized section or linker directives')
    children, frontier = [], [root['section']]
    while frontier:
        parent = frontier.pop()
        for child in coff.sections.values():
            if child['selection'] == 'associative' and child['association'] == parent:
                if child['index'] in children or child['index'] == root['section']:
                    raise ValueError('cyclic associative closure')
                if not child['name'].startswith('.debug') or child['flags'] & (0x20 | 0x20000000):
                    raise ValueError('non-debug associative closure is unsupported')
                children.append(child['index'])
                frontier.append(child['index'])
    omitted = []
    for item in coff.sections.values():
        if item['index'] == root['section'] or item['name'] == '.drectve':
            continue
        if item['name'].startswith('.debug') and not item['flags'] & (0x20 | 0x20000000):
            reason = 'explicitly dropped debug-only associative child' if item['index'] in children else 'explicitly dropped standalone debug metadata'
        elif item['name'] == '.text' and item['comdat'] and item['selection'] != 'associative':
            reason = 'unselected independent code COMDAT; no root runtime relocation reaches it'
        else:
            raise ValueError('unrecognized EH, data, initializer, TLS or shared runtime section')
        omitted.append(dict(section=item['index'], name=item['name'], reason=reason,
            size=item['size'], relocation_count=len(item['relocs']), association=item['association']))
    directive = [s for s in coff.sections.values() if s['name'] == '.drectve']
    if len(directive) != 1 or directive[0]['relocs'] or directive[0]['comdat']:
        raise ValueError('unsupported directive section structure')
    # Header pointers are rebuilt; source code and directive payloads are copied.
    def payload(section):
        row = struct.unpack_from('<8sIIIIIIHHI', coff.data, 20 + (section['index'] - 1) * 40)
        return coff.data[row[4]:row[4] + row[3]]
    ddata, code = payload(directive[0]), payload(sec)
    strings = bytearray(b'\0' * 4)
    name = root['name'].encode('ascii')
    rawname = struct.pack('<II', 0, 4)
    strings.extend(name + b'\0')
    struct.pack_into('<I', strings, 0, len(strings))
    static = section_symbols[0]
    original_symptr = struct.unpack_from('<I', coff.data, 8)[0]
    aux_start = original_symptr + (static['index'] + 1) * 18
    aux = coff.data[aux_start:aux_start + 18]
    if len(aux) != 18 or static['aux_count'] != 1 or any((static['section_aux']['association'], static['section_aux']['relocation_count'], struct.unpack_from('<H', aux, 6)[0])):
        raise ValueError('unsupported root auxiliary metadata')
    records = (struct.pack('<8sIhHBB', b'.text\0\0\0', 0, 2, 0, 3, 1) + aux +
               struct.pack('<8sIhHBB', rawname, root['value'], 2, root['type'], root['storage'], 0))
    dptr, cptr = 100, 100 + len(ddata)
    symptr = cptr + len(code)
    result = (struct.pack('<HHIIIHH', 0x14c, 2, 0, symptr, 3, 0, 0) +
        struct.pack('<8sIIIIIIHHI', b'.drectve', 0, 0, len(ddata), dptr, 0, 0, 0, 0, directive[0]['flags']) +
        struct.pack('<8sIIIIIIHHI', b'.text\0\0\0', 0, 0, len(code), cptr, 0, 0, 0, 0, sec['flags']) +
        ddata + code + records + strings)
    return result, dict(input_section=root['section'], output_section=2, output_symbol_index=2,
        symbol=root['name'], size=sec['size'], payload_sha256=hashlib.sha256(code).hexdigest(),
        characteristics=sec['flags'], selection=sec['selection'], runtime_relocations=0,
        dropped_sections=omitted, debug_associative_children_dropped=children,
        directives_preserved=coff.directives)


def extract(input_path, output_path, receipt_path, manifest_path, recipe_path, verification_path,
            verification_sha256, recipe_id, symbol):
    input_path, output, receipt, manifest_path, recipe_path, verification_path = [Path(p).resolve() for p in
        (input_path, output_path, receipt_path, manifest_path, recipe_path, verification_path)]
    inputs = {input_path, manifest_path, recipe_path, verification_path}
    if output == receipt or output in inputs or receipt in inputs or output.exists() or receipt.exists():
        raise ValueError('new distinct output and receipt paths are required')
    manifest = json.loads(manifest_path.read_text(encoding='utf-8-sig'))
    checked = json.loads(verification_path.read_text(encoding='utf-8-sig'))
    if sha(verification_path) != verification_sha256 or checked.get('kind') != 'fnv-retained-object-verification':
        raise ValueError('hash-bound retained receipt required')
    if not reconcile_recipes(manifest, recipe_path)['verified']:
        raise ValueError('complete exact retained recipe reconciliation required')
    for flag in ('retained_verification_pass', 'function_byte_verification_pass', 'original_oracle_parity_pass', 'global_listed_eh_coverage_pass', 'evidence_stable'):
        if checked.get(flag) is not True:
            raise ValueError('retained comparison gate not passed')
    if not checked['scope'].get('full_authoritative') or checked['inputs']['retained_manifest_sha256'] != sha(manifest_path) or checked['inputs']['recipe_sha256'] != sha(recipe_path):
        raise ValueError('retained scope or input fingerprint mismatch')
    unit = next((u for u in manifest['units'] if u['recipe_id'] == recipe_id), None)
    row = next((u for u in checked['units'] if u['recipe_id'] == recipe_id), None)
    if not unit or not row:
        raise ValueError('explicit recipe identity absent from retained evidence')
    declared_input = (manifest_path.parent / manifest.get('object_root_relative', '.') / unit['object']).resolve()
    if input_path != declared_input or sha(input_path) != unit['object_sha256'] or row['object_sha256'] != unit['object_sha256'] or row['status'] != 'ok' or row.get('eh_errors'):
        raise ValueError('exact selected object and local comparison proof required')
    fn = next((f for f in unit['recipe']['functions'] if f['symbol'] == symbol), None)
    if not fn:
        raise ValueError('root is not an explicitly selected recipe function')
    proofs = [f for f in row.get('verified_functions', []) if f['symbol'] == symbol and
              f['address'] == '0x%08x' % int(fn['address'], 16) and f['size'] == fn['size'] and f['verdict'] == 'match']
    if len(proofs) != 1:
        raise ValueError('specific selected function proof required')
    source = (Path(manifest['source_root']) / unit['source']).resolve()
    if source in (output, receipt) or sha(source) != unit['source_sha256']:
        raise ValueError('source observation changed or would be overwritten')
    coff, _, _, _ = strict_object(input_path)
    data, selection = select_layout(coff, proofs[0])
    output.parent.mkdir(parents=True, exist_ok=True)
    stage = None
    output_created = receipt_created = False
    try:
        with tempfile.NamedTemporaryFile(dir=output.parent, suffix='.obj', prefix='.coff-extract-', delete=False) as stream:
            stage = Path(stream.name)
            stream.write(data)
        after, _, _, _ = strict_object(stage)
        code = after.sections[2]
        if code['payload_sha256'] != selection['payload_sha256'] or code['flags'] != selection['characteristics'] or code['selection'] != selection['selection'] or code['relocs'] or after.directives != coff.directives:
            raise ValueError('independent output reparse changed selected bytes or policy')
        if sha(input_path) != unit['object_sha256'] or sha(verification_path) != verification_sha256:
            raise ValueError('evidence changed during extraction')
        report = dict(schema_version=1, kind='fnv-zero-relocation-comdat-extraction', status='pass',
            scope='one explicitly selected verified zero-relocation code COMDAT; not runtime/provider selection',
            recipe_id=recipe_id, verification_sha256=verification_sha256,
            input_sha256=unit['object_sha256'], output_sha256=hashlib.sha256(data).hexdigest(),
            function_proof=proofs[0], selection=selection, independent_reparse=True)
        receipt.parent.mkdir(parents=True, exist_ok=True)
        with output.open('xb') as stream:
            output_created = True
            stream.write(data)
        with receipt.open('x', encoding='utf-8') as stream:
            receipt_created = True
            json.dump(report, stream, indent=2)
        return report
    except BaseException:
        if receipt_created:
            receipt.unlink(missing_ok=True)
        if output_created:
            output.unlink(missing_ok=True)
        raise
    finally:
        if stage is not None:
            stage.unlink(missing_ok=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for option in ('input', 'output', 'receipt', 'manifest', 'recipes', 'verification'):
        parser.add_argument('--' + option, required=True, type=Path)
    for option in ('verification-sha256', 'recipe-id', 'symbol'):
        parser.add_argument('--' + option, required=True)
    args = parser.parse_args()
    report = extract(args.input, args.output, args.receipt, args.manifest, args.recipes,
                     args.verification, args.verification_sha256, args.recipe_id, args.symbol)
    print(json.dumps(dict(status=report['status'], output_sha256=report['output_sha256'])))


if __name__ == '__main__':
    main()
