"""Two fixed existing-carrier source overlays; compile/compare only, never link."""
from __future__ import annotations
import argparse
from collections import Counter
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
import runtime_source_overlay as pilot
from coff_inventory import Coff
from data_plan import Pe, file_hash
from import_plan import ImagePe, image_ok, require
from compare import Coff as CompareCoff, compare as plain_compare
import toolchain

POLICY = ROOT / 'runtime/source-overlays/entry-existing-carriers.json'
POLICY_SHA = '5884f7d9d3cf13f28bbe767e35b871698d2ec63844c9e417037d213c23e64ff0'
INPUTS = {
    'triage': ('build/rebuild/absolute-triage-evidence-v1.json', '4e06af226997152e1a7097e93f3b96d92804b229f97139dd21c89e249c6f5a28'),
    'entry': ('build/rebuild/entry-dependencies-next-projects-v1.json', 'eca726d106f800b023c831280c7f2ce7eb3d448a00a570f827dcd264d7dfc803'),
}
INCLUDE = b'#include "../../include/layout_support.h"\r\n\r\n'


def digest(raw):
    return hashlib.sha256(raw).hexdigest()


def policy():
    raw = POLICY.read_bytes()
    require(digest(raw) == POLICY_SHA, 'fixed policy changed')
    return json.loads(raw)


def transform(raw, spec):
    require(spec in policy()['targets'], 'unauthorized target or transformation')
    require(digest(raw) == spec['source_sha256'], 'stale source')
    old = spec['old_statement'].encode()
    new = spec['new_statement'].encode()
    require(raw.count(old) == 1, 'statement missing or ambiguous')
    require(raw.count(INCLUDE) == 1, 'include context changed')
    result = raw.replace(old, new, 1)
    # Reuse the later global declaration without changing line counts. Explicit
    # global qualification prevents accidental binding to a function namespace.
    if spec['function_va'] == '0x0084ba20':
        require(raw.count(b'extern int DAT_0107f4e8;') == 1, 'carrier declaration changed')
        result = result.replace(INCLUDE, INCLUDE[:-2] + b'extern int DAT_0107f4e8;\r\n', 1)
    else:
        require(spec['function_va'] == '0x00c033c0', 'unknown fixed target')
        require(raw.index(b'extern int DAT_010bc8a4;') < raw.index(old), 'carrier not in scope')
    require(result.count(b'\n') == raw.count(b'\n') and result.count(b'\r\n') == raw.count(b'\r\n'), 'line context changed')
    require(re.findall(rb'(?m)^\s*#\s*include\s+([^\r\n]+)', raw) == [b'"../../include/layout_support.h"'], 'unexpected source includes')
    require(not re.search(rb'\b(__FILE__|__LINE__|__DATE__|__TIME__|__COUNTER__|__TIMESTAMP__)\b', raw), 'source macro context unsupported')
    return result


def function(coff, name, size):
    symbols = [s for s in coff.symbols.values() if s['name'] == name and s['section'] > 0]
    require(len(symbols) == 1, 'function identity ambiguous')
    symbol = symbols[0]
    section = coff.sections[symbol['section']]
    require(section['flags'] & 0x20000020 and 0 <= symbol['value'] <= section['size'] - size, 'function extent invalid')
    header = coff.unpack('<8sIIIIIIHHI', 20 + (symbol['section'] - 1) * 40)
    raw = coff.take(header[4] + symbol['value'], size)
    refs = []
    for off, idx, kind in section['relocs']:
        if symbol['value'] <= off < symbol['value'] + size:
            require(off + 4 <= symbol['value'] + size, 'straddling relocation')
            target = coff.symbols[idx]
            refs.append(dict(offset=off-symbol['value'], kind=kind,
                             symbol=target['name'], section=target['section'], value=target['value'],
                             storage=target['storage'], type=target['type'], aux_count=target['aux_count'],
                             addend=struct.unpack_from('<I', raw, off-symbol['value'])[0]))
    return raw, refs


def geometry(before, after, spec):
    require(spec in policy()['targets'], 'unauthorized geometry contract')
    size = spec['selection']['size']
    old, oldrefs = function(before, spec['function'], size)
    new, newrefs = function(after, spec['function'], size)
    off = spec['function_offset']
    name = spec['same_unit_target_names'][0]
    require(struct.unpack_from('<I', old, off)[0] == int(spec['target_va'], 16), 'original target changed')
    require(not any(r['offset'] < off+4 and r['offset']+4 > off for r in oldrefs), 'original field not missing')
    expected = dict(offset=off, kind=6, symbol=name, section=0, value=0, storage=2, type=0, aux_count=0, addend=0)
    require(newrefs.count(expected) == 1 and len(newrefs) == len(oldrefs)+1, 'new DIR32 geometry wrong')
    require([r for r in newrefs if r != expected] == oldrefs, 'other relocations changed')
    carriers = [s for s in after.symbols.values() if s['name'] == name]
    require(len(carriers) == 1 and all(carriers[0][k] == v for k, v in dict(section=0, value=0, storage=2, type=0, aux_count=0).items()), 'carrier not exactly one undefined external')
    require(all(a == b for i, (a, b) in enumerate(zip(old, new)) if not off <= i < off+4), 'non-field bytes changed')
    return dict(new_reference=expected, non_field_bytes_equal=True, extent=size,
                original_status='MISSING_COFF_RELOCATION', overlay_status='EXACT_DIR32')


def row_identities(rows):
    return Counter((r['address'], r['symbol'], r['size']) for r in rows)


def matches(rows, spec, expected):
    require(bool(expected) and row_identities(rows) == row_identities(expected), 'complete recipe comparison coverage differs')
    selected = [r for r in rows if r['symbol'] == spec['function']]
    require(len(selected) == 1 and selected[0]['size'] == spec['selection']['size'] and
            selected[0]['compiled_extent'] == spec['selection']['size'], 'selected extent differs')
    require(bool(rows) and all(r['verdict'] == 'match' for r in rows), 'plain same-unit comparison failed')


def run(args):
    require(args.compile_only is True, 'explicit compile-only operation required; no prepare mode')
    require(os.name == 'nt', 'native compiler requires Windows')
    spec = policy()
    observations = {POLICY: POLICY_SHA}
    data = {}
    for name, (relative, pin) in INPUTS.items():
        path = ROOT / relative
        data[name] = pilot.read_bound(path, pin)
        observations[path] = pin
    for name, path in pilot.DEFAULTS.items():
        data[name] = pilot.read_bound(path, pilot.PINS[name])
        observations[path] = pilot.PINS[name]
    reference = Path(args.reference).resolve()
    observations[reference] = pilot.PINS['reference']
    doctor = Path(args.doctor).resolve()
    tc = json.loads(doctor.read_text())['toolchains']['sp1']
    compiler_root, _ = toolchain.layout(tc['root'])
    require(tc['ready'] and tc['version'] == '15.00.30729.01', 'wrong compiler version')
    cl = compiler_root / 'VC/bin/cl.exe'
    require(tc['cl_sha256'] == data['manifest']['toolchains']['sp1']['cl_sha256'] == file_hash(cl), 'compiler differs')
    observations[doctor] = file_hash(doctor)
    for name in ('VC/bin/cl.exe', 'VC/bin/c1xx.dll', 'VC/bin/c2.dll'):
        path = compiler_root / name
        observations[path] = file_hash(path)
    for name, pin in spec['compiler_headers'].items():
        observations[compiler_root / name] = pin
    observations[ROOT / 'include/layout_support.h'] = spec['layout_header_sha256']
    # Existing retained proof and frozen helpers stay byte-for-byte unchanged.
    for name, pin in data['retained']['inputs']['tools_sha256'].items():
        observations[ROOT / name] = pin
    for name in pilot.TOOLS + ['tools/rebuild/entry_relocation_repair.py']:
        observations.setdefault(ROOT / name, file_hash(ROOT / name))
    index = ROOT / 'build/function_index.json'
    require(not index.exists() and data['retained']['inputs']['function_index_present'] is False, 'optional index differs')
    prepared = []
    for target in spec['targets']:
        idx = target['selection']['recipe_index']
        unit = data['manifest']['units'][idx]
        recipe = data['recipes']['units'][idx]
        require(unit['recipe_id'] == target['recipe_id'] and unit['recipe'] == recipe and recipe['source'] == target['source'] and recipe['compiler'] == 'sp1', 'recipe differs')
        require(recipe['symbols'][target['same_unit_target_names'][0]] == target['target_va'], 'own recipe carrier binding differs')
        require(data['selection']['selections'][target['function_va']] == target['selection'], 'selected owner differs')
        proof = data['retained']['units'][idx]
        require(proof['object_sha256'] == unit['object_sha256'] == target['object_sha256'], 'retained object differs')
        require(row_identities(proof['verified_functions']) == row_identities(recipe['functions']) and
                all(r['verdict'] == 'match' for r in proof['verified_functions']), 'complete retained recipe coverage differs')
        expected_row = dict(address=target['function_va'], symbol=target['function'], size=target['selection']['size'], section=target['selection']['section'], value=target['selection']['value'], verdict='match')
        require(expected_row in proof['verified_functions'], 'retained selected match absent')
        triage_row = {k: v for k, v in target.items() if k not in ('selection', 'old_statement', 'new_statement')}
        require(triage_row in data['triage']['rows'], 'triage provenance differs')
        missing = [r for r in data['entry']['original_missing_fields'] if r['recipe_id'] == target['recipe_id'] and r['function_va'] == target['function_va'] and r['source_field_offset'] == target['function_offset']]
        require(len(missing) == 1 and missing[0]['physical_section'] == target['physical_field']['section'] and missing[0]['physical_offset'] == target['physical_field']['offset'] and missing[0]['original_field_va'] == target['field_va'], 'reachable missing-field identity differs')
        source = ROOT / target['source']
        original = (pilot.DEFAULTS['manifest'].parent / data['manifest'].get('object_root_relative', '.') / unit['object']).resolve()
        observations[source] = target['source_sha256']
        observations[original] = target['object_sha256']
        prepared.append((target, recipe, original, transform(source.read_bytes(), target)))
    require(all(file_hash(p) == h for p, h in observations.items()), 'stale protected input')
    out = pilot.new_output(args.out, observations)
    out.mkdir(parents=True)
    report = dict(kind='fnv-entry-relocation-source-overlay-result', status='error', inputs={str(p): h for p, h in observations.items()},
                  game_execution=False, link_performed=False, provider_selected=False, runtime_eligible=False,
                  runtime_closure_verified=False, game_fixups_approved=0, units=[])
    def note(state, **fields):
        with (out / 'progress.jsonl').open('a', encoding='utf-8') as stream:
            stream.write(json.dumps(dict(state=state, **fields))+'\n'); stream.flush(); os.fsync(stream.fileno())
    note('started')
    try:
        image = ImagePe(reference)
        ok, hits, probes = image_ok(image)
        require(ok, 'image probes failed')
        for target, recipe, original, generated in prepared:
            folder = out / target['recipe_id']; folder.mkdir()
            source = folder / Path(target['source']).name
            obj = folder / 'overlay.obj'
            source.write_bytes(generated)
            command = [cl, '/c', '/nologo'] + recipe['flags'] + ['/I'+str((ROOT/target['source']).parent), '/I'+str(ROOT/'include'), '/showIncludes', source, '/Fo'+str(obj)]
            note('compile_started', recipe_id=target['recipe_id'])
            code, text = toolchain.run(command, compiler_root, ROOT, timeout=120)
            with (folder/'compile.log').open('x', encoding='utf-8') as stream: stream.write(text)
            require(code == 0 and obj.is_file(), 'overlay compilation failed')
            object_hash = file_hash(obj)
            require(file_hash(source) == digest(generated), 'generated source drift')
            includes = [Path(x.strip()).resolve() for x in re.findall(r'(?im)^Note: including file:\s*(.+)$', text)]
            allowed = {ROOT/'include/layout_support.h'} | {compiler_root/n for n in spec['compiler_headers']}
            require(bool(includes) and set(includes) <= {p.resolve() for p in allowed} and (ROOT/'include/layout_support.h').resolve() in includes, 'unexpected compiler include origin')
            before, after = Coff(original), Coff(obj)
            require(digest(after.data) == object_hash, 'object drift during geometry')
            observed = geometry(before, after, target)
            pe = Pe(reference)
            try:
                field = int(target['field_va'], 16)-pe.base
                require(field in set(pe.relocations()) and struct.unpack('<I', pe.read_rva(field, 4, allow_code=True))[0] == int(target['target_va'], 16), 'original HIGHLOW target differs')
            finally: pe.close()
            comparable = CompareCoff(obj)
            require(digest(comparable.data) == object_hash, 'object drift before comparison')
            rows = plain_compare(comparable, image, recipe)
            sanitized = [{k: v for k, v in r.items() if k != 'byte_differences'} | dict(byte_difference_offsets=[d['offset'] for d in r['byte_differences']]) for r in rows]
            pilot.save(folder/'comparison.json', dict(rows=sanitized))
            matches(rows, target, recipe['functions'])
            pilot.generated_stability(source, obj, digest(generated), object_hash)
            report['units'].append(dict(recipe_id=target['recipe_id'], function=target['function_va'], geometry=observed, generated_source_sha256=digest(generated), object_sha256=object_hash, plain_comparison_rows=len(rows), actual_includes=[str(p) for p in includes], original_recipe_flags=recipe['flags']))
            note('unit_verified', recipe_id=target['recipe_id'])
        del image
        require(not index.exists() and all(file_hash(p) == h for p, h in observations.items()), 'protected input drift')
        for target, recipe, original, generated in prepared:
            folder = out/target['recipe_id']
            record = next(r for r in report['units'] if r['recipe_id'] == target['recipe_id'])
            pilot.generated_stability(folder/Path(target['source']).name, folder/'overlay.obj', digest(generated), record['object_sha256'])
        report.update(status='pass_pending_independent_review', input_stability_verified=True, original_source_unchanged=True, image_gate=dict(hits=hits, probes=probes))
        note('verified_pending_review')
    except Exception as error:
        report['error'] = str(error)
        note('failed', error_type=type(error).__name__)
    pilot.save(out/'result.json', report)
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compile-only', action='store_true', required=True,
                        help='explicit native compile/compare intent; this command has no prepare-only mode')
    for name in ('reference', 'doctor', 'out'): parser.add_argument('--'+name, required=True, type=Path)
    args = parser.parse_args()
    try: result = run(args)
    except (ValueError, OSError, KeyError, TypeError) as error: parser.exit(2, 'overlay rejected: '+str(error)+'\n')
    print(result['status'])
    return 0 if result['status'] == 'pass_pending_independent_review' else 1


if __name__ == '__main__': raise SystemExit(main())
