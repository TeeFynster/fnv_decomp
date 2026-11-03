"""Extract one approved scalar COMDAT and its two source-emitted literals only.

This is a fixed reviewed component policy, not a general game-data extractor.
Every extraction directly revalidates the selected ownership and reference proof.
"""
from __future__ import annotations
import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile

from coff_rewrite import strict_object
from toolchain import sha256 as sha

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'tools'))
import compare as oracle
from build_and_match import image_ok

POLICY = 'game-scalar-0703-literals-v1'
PARENT = '?GetWeaponHealthConditionMultiplier@@YAMM@Z'
LITERALS = {25: '__real@3fe570a3e0000000', 26: '__real@3fe8000000000000'}
EDGES = [(9, LITERALS[26], 6), (31, LITERALS[26], 6), (37, LITERALS[25], 6)]
DEFAULTS = ['/DEFAULTLIB:"LIBCMT"', '/DEFAULTLIB:"OLDNAMES"']
ADDRESS, RECIPE_ID = '0x00646d00', '0703-3a582158246b390e'
PINS = dict(recipe='62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c',
    manifest='bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb',
    selection='48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1',
    verification='04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297',
    image='df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7',
    object='211a7bcbb50adc39d9aad96dba73f2229609d53cd93a0e2f44470fe0c99cbb31',
    source='64e0d987b3b5c12e7327e698d51e390a3801f8cf2d1686e2655b164de80f32ec')
SELECTED = dict(recipe_id=RECIPE_ID, recipe_index=703, symbol=PARENT, section=24,
    value=0, size=55, selection_status='CODE_OWNERSHIP_SELECTED', runtime_eligible=False, link_ready=False)
SPEC = dict(address=ADDRESS, symbol=PARENT, size=55)


def require(ok, message):
    if not ok:
        raise ValueError(message)


def payload(coff, index):
    row = struct.unpack_from('<8sIIIIIIHHI', coff.data, 20+(index-1)*40)
    return coff.data[row[4]:row[4]+row[3]]


def save(path, value):
    with Path(path).open('x', encoding='utf-8') as stream:
        json.dump(value, stream, indent=2)
        stream.write('\n')


def compare_component(path, image, unit):
    pe = oracle.Pe(image)
    report = oracle.compare(oracle.Coff(path), pe,
        dict(functions=[SPEC], symbols=unit.get('symbols', {}), literal_symbols=unit.get('literal_symbols', [])))[0]
    require(report['verdict'] == 'match' and report['compiled_extent'] == 55 and
            not report['errors'] and not report['byte_differences'], 'unchanged scalar comparison failed')
    require([(r['offset'], r['symbol'], r['kind']) for r in report['relocations']] == EDGES and
            all(r['match'] for r in report['relocations']), 'reference relocation contract differs')
    return {k: v for k, v in report.items() if k != 'byte_differences'}


def verify_basis(manifest, selection, verification, image):
    """Directly check fixed trusted inputs, exact owner and unchanged oracle."""
    paths = dict(manifest=Path(manifest).resolve(), selection=Path(selection).resolve(),
                 verification=Path(verification).resolve(), image=Path(image).resolve(),
                 recipe=ROOT/'build/units.json', source=ROOT/'src/fallout_shared/combatformulas.cpp')
    require(len(set(paths.values())) == len(paths), 'proof input collision')
    require(all(sha(path) == PINS[name] for name, path in paths.items()), 'stale approved input hash')
    recipes = json.loads(paths['recipe'].read_text())['units']
    unit = recipes[703]
    m = json.loads(paths['manifest'].read_text())
    s = json.loads(paths['selection'].read_text())
    v = json.loads(paths['verification'].read_text())
    require(m.get('kind') == 'fnv-retained-objects' and m.get('recipe_manifest_sha256') == PINS['recipe'], 'manifest recipe binding differs')
    mu = [x for x in m['units'] if x['recipe_index'] == 703]
    vu = [x for x in v['units'] if x['recipe_index'] == 703]
    require(len(mu) == len(vu) == 1, 'missing or duplicate owner proof')
    mu, vu = mu[0], vu[0]
    require(mu['recipe_id'] == vu['recipe_id'] == RECIPE_ID and mu['recipe'] == unit and
            mu['status'] == 'compiled' and vu['status'] == 'ok', 'recipe/compiled owner identity differs')
    require(mu['object_sha256'] == vu['object_sha256'] == PINS['object'] and
            mu['source_sha256'] == vu['source_sha256_recorded'] == vu['source_sha256_current'] == PINS['source'], 'object/source proof differs')
    require(s.get('kind') == 'fnv-function-code-ownership-selection' and s['selections'].get(ADDRESS) == SELECTED and
            s['input_sha256']['recipe'] == PINS['recipe'] and s['input_sha256']['manifest'] == PINS['manifest'] and
            s['input_sha256']['receipt'] == PINS['verification'] and s['runtime_eligible'] is False and s['link_ready'] is False,
            'selected owner differs')
    require(v.get('kind') == 'fnv-retained-object-verification' and v['scope']['full_authoritative'] is True and
            all(v.get(k) is True for k in ('retained_verification_pass', 'function_byte_verification_pass',
                'global_listed_eh_coverage_pass', 'original_oracle_parity_pass', 'evidence_stable')), 'v3 proof gate missing')
    require(v['inputs']['retained_manifest_sha256'] == PINS['manifest'] and v['inputs']['recipe_sha256'] == PINS['recipe'] and
            v['inputs']['image_sha256'] == PINS['image'], 'verification bindings differ')
    require(not v['inputs']['function_index_present'] and v['inputs']['function_index_sha256'] is None and
            not s['function_index_present'] and not (ROOT/'build/function_index.json').exists(), 'optional function-index state differs')
    require(dict(SPEC, section=24, value=0, verdict='match') in vu['verified_functions'] and
            not vu.get('eh_errors') and not vu.get('mismatches'), 'exact function proof absent or local diagnostics present')
    for name, expected in v['inputs']['tools_sha256'].items():
        path = (ROOT/name).resolve()
        require(path.is_relative_to(ROOT) and sha(path) == expected, 'unchanged proof tool differs')
        paths['tool:'+name] = path
    require(sha(ROOT/'build/image_check.json') == v['inputs']['image_check_sha256'], 'image fingerprint specification differs')
    paths['image_check'] = ROOT/'build/image_check.json'
    obj = (paths['manifest'].parent/mu['object']).resolve()
    require(obj.is_relative_to(paths['manifest'].parent) and sha(obj) == PINS['object'], 'retained object differs or escapes manifest directory')
    paths['object'] = obj
    for name in ('coff_literal_extract.py', 'coff_rewrite.py', 'toolchain.py'):
        paths['extractor_tool:'+name] = ROOT/'tools/rebuild'/name
    pe = oracle.Pe(paths['image'])
    gate = image_ok(pe)
    require(gate[0], 'unchanged image fingerprint gate failed')
    report = compare_component(obj, paths['image'], unit)
    inputs = {str(p): sha(p) for p in paths.values()}
    return dict(schema_version=1, kind='game-scalar-component-basis', policy=POLICY,
                inputs=inputs, object=str(obj), unit=unit, selected=SELECTED, image=str(paths['image']),
                image_gate=dict(passed=gate[0], matching=gate[1], total=gate[2]), comparison=report)


def select(coff):
    require(coff.directives == DEFAULTS, 'unknown linker directive')
    require(not any(s['name'].startswith(('.CRT', '.tls', '.pdata', '.xdata')) or s['name'] == '.sxdata'
                    for s in coff.sections.values()), 'hidden initialization/TLS/EH record')
    symbols = list(coff.symbols.values())
    for index in coff.sections:
        header = struct.unpack_from('<8sIIIIIIHHI', coff.data, 20+(index-1)*40)
        require(header[1] == header[2] == header[6] == header[8] == 0, 'unknown section address/line record')
    require(not any(s.get('weak') or (s['section'] == 0 and s['value']) for s in symbols), 'weak/common symbol unsupported')
    def unique(name):
        found = [s for s in symbols if s['name'] == name]
        require(len(found) == 1, 'missing or duplicate symbol: '+name)
        return found[0]
    parent = unique(PARENT)
    require((parent['section'], parent['value'], parent['type'], parent['storage'], parent['aux_count']) == (24, 0, 32, 2, 0), 'selected code owner differs')
    dr = [s for s in coff.sections.values() if s['name'] == '.drectve']
    require(len(dr) == 1 and dr[0]['index'] == 1, 'directive owner differs')
    keep = [1, 24, 25, 26]
    require(not any(s['association'] in keep for s in coff.sections.values()), 'hidden associated child')
    expected = {1: ('.drectve', 47, 0x00100a00, 'none', set()),
                24: ('.text', 55, 0x60501020, 'no_duplicates', {PARENT}),
                25: ('.rdata', 8, 0x40401040, 'any', {LITERALS[25]}),
                26: ('.rdata', 8, 0x40401040, 'any', {LITERALS[26]})}
    for index, (name, size, flags, selection, owners) in expected.items():
        sec = coff.sections.get(index)
        require(sec and (sec['name'], sec['size'], sec['flags'], sec['selection'], sec['association']) ==
                (name, size, flags, selection, 0), 'section extent/protection/COMDAT differs')
        members = [s for s in symbols if s['section'] == index]
        sections = [s for s in members if 'section_aux' in s]
        require(len(sections) == 1, 'required section auxiliary missing')
        st = sections[0]
        require((st['name'], st['value'], st['type'], st['storage'], st['aux_count']) == (name, 0, 0, 3, 1), 'section symbol differs')
        require(st['section_aux']['relocation_count'] == len(sec['relocs']), 'section auxiliary relocation count differs')
        others = [s for s in members if s is not st]
        require(len(others) == len(owners) and {s['name'] for s in others} == owners and
                all(not s['aux_count'] and s['storage'] == 2 and s['value'] == 0 and
                    s['type'] == (32 if index == 24 else 0) for s in others), 'shared section/alias or hidden record')
    require([(off, coff.symbols[idx]['name'], kind) for off, idx, kind in coff.sections[24]['relocs']] == EDGES,
            'unknown or changed runtime edge')
    require(all(struct.unpack_from('<I', payload(coff, 24), off)[0] == 0 for off, _, _ in EDGES), 'nonzero relocation addend')
    for index, name in LITERALS.items():
        target = unique(name)
        require(target['section'] == index and not coff.sections[index]['relocs'] and
                payload(coff, index) == bytes.fromhex(name.split('@')[1])[::-1], 'missing/malformed/nonliteral target')
    require(not coff.sections[1]['relocs'], 'directive relocation unsupported')
    for name, value in (('@feat.00', 1), ('@comp.id', 8681481)):
        feature = unique(name)
        require((feature['section'], feature['value'], feature['type'], feature['storage'], feature['aux_count']) ==
                (-1, value, 0, 3, 0), 'feature/compiler metadata differs')
    indices = [s['index'] for s in symbols if s['section'] in keep or s['name'] in ('@feat.00', '@comp.id')]
    return keep, indices


def transform(path):
    coff, symptr, _, _ = strict_object(path)
    keep, indices = select(coff)
    sections = {old: new+1 for new, old in enumerate(keep)}
    symbols, count = {}, 0
    for index in indices:
        symbols[index] = count
        count += 1+coff.symbols[index]['aux_count']
    strings, records = bytearray(4), bytearray()
    for index in indices:
        s = coff.symbols[index]
        name = s['name'].encode('ascii')
        if len(name) > 8:
            rawname = struct.pack('<II', 0, len(strings))
            strings += name+b'\0'
        else:
            rawname = name.ljust(8, b'\0')
        records += struct.pack('<8sIhHBB', rawname, s['value'], sections.get(s['section'], s['section']), s['type'], s['storage'], s['aux_count'])
        if s['aux_count']:
            aux = coff.data[symptr+(index+1)*18:symptr+(index+2)*18]
            require(not struct.unpack_from('<H', aux, 6)[0] and aux[12:14] == bytes(2) and aux[15:] == bytes(3), 'unknown section auxiliary fields')
            records += aux
    cursor = 20+40*len(keep)
    headers, body, ledger = bytearray(), bytearray(), []
    for old in keep:
        sec = coff.sections[old]
        data = payload(coff, old)
        raw = cursor
        body += data
        cursor += len(data)
        relptr = cursor if sec['relocs'] else 0
        for off, index, kind in sec['relocs']:
            require(index in symbols, 'runtime edge escapes selected component')
            body += struct.pack('<IIH', off, symbols[index], kind)
            cursor += 10
        headers += struct.pack('<8sIIIIIIHHI', sec['name'].encode().ljust(8, b'\0'), 0, 0, len(data), raw, relptr, 0, len(sec['relocs']), 0, sec['flags'])
        ledger.append(dict(input_section=old, output_section=sections[old], name=sec['name'], size=sec['size'], flags=sec['flags'],
                           selection=sec['selection'], payload_sha256=sec['payload_sha256']))
    struct.pack_into('<I', strings, 0, len(strings))
    result = struct.pack('<HHIIIHH', 0x14c, len(keep), 0, cursor, count, 0, 0)+headers+body+records+strings
    return result, dict(section_map=sections, symbol_map=symbols, sections=ledger,
        omitted_sections=[dict(section=i, name=s['name'], reason='unselected whole-object content') for i, s in coff.sections.items() if i not in keep])


def reparse(before_path, after_path, ledger):
    before, _, _, _ = strict_object(before_path)
    after, _, _, _ = strict_object(after_path)
    require(len(after.sections) == 4 and after.directives == DEFAULTS, 'output contains unexpected sections/directives')
    for old, new in ledger['section_map'].items():
        a, b = before.sections[old], after.sections[new]
        require(payload(before, old) == payload(after, new) and
                all(a[k] == b[k] for k in ('name', 'size', 'flags', 'selection', 'association')), 'output payload/policy changed')
        require([(o, ledger['symbol_map'][i], t) for o, i, t in a['relocs']] == b['relocs'], 'output relocation remap differs')
    require(len(after.symbols) == len(ledger['symbol_map']), 'unexpected output symbols')
    for old, new in ledger['symbol_map'].items():
        a, b = before.symbols[old], after.symbols[new]
        require(all(a[k] == b[k] for k in ('name', 'value', 'type', 'storage', 'aux_count')) and
                ledger['section_map'].get(a['section'], a['section']) == b['section'], 'output symbol changed')
        if 'section_aux' in a:
            require(a['section_aux'] == b.get('section_aux'), 'output section auxiliary changed')


def extract(manifest, selection, verification, image, output, receipt):
    out, rp = Path(output).resolve(), Path(receipt).resolve()
    require(out != rp and not out.exists() and not rp.exists(), 'new distinct outputs required')
    basis = verify_basis(manifest, selection, verification, image)
    require(str(out) not in basis['inputs'] and str(rp) not in basis['inputs'], 'output/input collision')
    data, ledger = transform(basis['object'])
    out.parent.mkdir(parents=True, exist_ok=True)
    stage, created = None, []
    try:
        with tempfile.NamedTemporaryFile(dir=out.parent, suffix='.obj', delete=False) as stream:
            stage = Path(stream.name)
            stream.write(data)
        reparse(basis['object'], stage, ledger)
        checked = compare_component(stage, basis['image'], basis['unit'])
        require(all(sha(path) == expected for path, expected in basis['inputs'].items()) and
                not (ROOT/'build/function_index.json').exists(), 'proof/input changed during extraction')
        report = dict(schema_version=1, kind='game-scalar-literal-extraction', policy=POLICY, status='pass',
            inputs=basis['inputs'], selected=SELECTED, input_sha256=PINS['object'], output_sha256=hashlib.sha256(data).hexdigest(),
            tool_sha256=sha(__file__), selection=ledger, reference_comparison=checked, independent_reparse=True,
            proof_scope='Hash-bound observed retained proof and unchanged comparator; not compiler-causality or game-runtime proof.')
        rp.parent.mkdir(parents=True, exist_ok=True)
        for path, content in ((out, data), (rp, (json.dumps(report, indent=2)+'\n').encode())):
            with path.open('xb') as stream:
                created.append(path)
                stream.write(content)
        return report
    except BaseException:
        for path in reversed(created):
            path.unlink(missing_ok=True)
        raise
    finally:
        if stage:
            stage.unlink(missing_ok=True)
