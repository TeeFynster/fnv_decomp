"""Link one reviewed retained leaf to an original fixture; execute only after map review."""
from __future__ import annotations

import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess

from coff_inventory import Coff, symbol_kind
from coff_rewrite import rewrite
from runtime_probe import pe_machine
import toolchain

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / 'runtime/probes/game_leaf_probe.cpp'
OLD = '?FUN_00be0b90@FnvCpu_FUN_00be0b90_CpuObject@@QAEHXZ'
NEW = '?ReadValue@GameLeafFixture@@QAEHXZ'
ADDRESS = '0x00be0b90'
EXPECTED = dict(schema=1, cases=7, calls=7168, checks_ok=1)
COMPILE = ['/nologo', '/c', '/MT', '/Od', '/GS', '/EHsc', '/Gy', '/W4']
LINK = ['/nologo', '/machine:x86', '/subsystem:console', '/opt:ref', '/opt:noicf']


def sha(path):
    return toolchain.sha256(Path(path))


def audit_object(path, name=OLD):
    coff = Coff(path)
    if set(coff.directives) != {'/DEFAULTLIB:"LIBCMT"', '/DEFAULTLIB:"OLDNAMES"'}:
        raise ValueError('unreviewed object linker directives')
    if any(s['name'] not in ('.text', '.debug$F', '.debug$S', '.drectve') for s in coff.sections.values()):
        raise ValueError('unreviewed object data, initializer, TLS or metadata section')
    code = [s for s in coff.sections.values() if s['flags'] & 0x20]
    if any(not s['comdat'] or s['selection'] != 'no_duplicates' for s in code):
        raise ValueError('unreviewed code selection policy')
    matches = [s for s in coff.symbols.values() if s['name'] == name]
    if len(matches) != 1 or symbol_kind(matches[0]) != 'external_definition':
        raise ValueError('leaf definition is not unique')
    symbol = matches[0]
    sec = coff.sections[symbol['section']]
    if symbol['value'] != 0 or sec['size'] != 4 or sec['relocs'] or not symbol['type'] & 0x20:
        raise ValueError('leaf body or relocation contract changed')
    children = [s for s in coff.sections.values() if s['selection'] == 'associative' and s['association'] == symbol['section']]
    if any(s['name'] != '.debug$F' or s['size'] != 16 or
           s['relocs'] != [(0, symbol['index'], 7)] for s in children):
        raise ValueError('unreviewed leaf associative closure')
    return dict(symbol_index=symbol['index'], section=symbol['section'], value=symbol['value'],
        size=sec['size'], payload_sha256=sec['payload_sha256'], relocation_count=0,
        associative_children=[dict(section=s['index'], name=s['name'], size=s['size'],
            self_debug_reference=dict(offset=0, target_index=symbol['index'], type=7)) for s in children],
        whole_object_sections=sorted({s['name'] for s in coff.sections.values()}),
        directives=coff.directives, no_initializer_tls_eh_roots=True)


def verify_basis(manifest, verification, expected_receipt_hash, receipt_path):
    if sha(receipt_path) != expected_receipt_hash:
        raise ValueError('retained verification receipt hash differs')
    if verification.get('kind') != 'fnv-retained-object-verification' or verification.get('schema_version') != 1:
        raise ValueError('unsupported retained verification receipt')
    for field in ('retained_verification_pass', 'function_byte_verification_pass',
                  'global_listed_eh_coverage_pass', 'original_oracle_parity_pass', 'evidence_stable'):
        if verification.get(field) is not True:
            raise ValueError('retained verification gate not passed')
    if verification.get('scope', {}).get('full_authoritative') is not True:
        raise ValueError('full retained verification scope required')
    unit = next((u for u in manifest['units'] if u['recipe_index'] == 0), None)
    checked = next((u for u in verification['units'] if u['recipe_index'] == 0), None)
    if not unit or not checked or unit['object_sha256'] != checked.get('object_sha256') or unit['recipe_id'] != checked.get('recipe_id'):
        raise ValueError('leaf object lacks exact retained hash-bound comparison')
    wanted = dict(symbol=OLD, address=ADDRESS, size=4, section=13, value=0, verdict='match')
    if wanted not in checked.get('verified_functions', []) or checked.get('eh_errors'):
        raise ValueError('specific leaf proof absent or provider has local EH notes')
    return unit


def map_leaf(text):
    rows = []
    for line in text.splitlines():
        found = re.match(r'^\s+[0-9A-Fa-f]{4}:[0-9A-Fa-f]{8}\s+(\S+)\s+([0-9A-Fa-f]{8})\s+.*\bleaf\.obj\s*$', line)
        if found:
            rows.append((found.group(1), int(found.group(2), 16)))
    if len(rows) != 1 or rows[0][0] != NEW:
        raise ValueError('linked map retains unexpected game-object public providers')
    return rows[0][1]


def link_blockers(text, bindings):
    names = []
    for line in text.splitlines():
        if 'LNK2019' not in line and 'LNK2001' not in line:
            continue
        prefix = line.split(' referenced in function ', 1)[0].strip()
        match = re.search(r'\((\S+)\)$', prefix)
        if match and match.group(1) not in names:
            names.append(match.group(1))
    return [dict(symbol=name, original_binding=bindings.get(name),
                 classification='unresolved direct-object member dependency; provider not selected') for name in names]


def prepare(compiler_root, manifest_path, verification_path, verification_sha256, out,
            *, extract_reviewed_leaf=False, image_path=None):
    out = Path(out).resolve()
    if out.exists():
        raise ValueError('output directory already exists')
    if not compiler_root or os.name != 'nt' or os.environ.get('LINK') or os.environ.get('_LINK_'):
        raise ValueError('explicit native compiler root and clean linker environment required')
    manifest_path, verification_path = Path(manifest_path).resolve(), Path(verification_path).resolve()
    manifest = json.loads(manifest_path.read_text(encoding='utf-8-sig'))
    verification = json.loads(verification_path.read_text(encoding='utf-8-sig'))
    unit = verify_basis(manifest, verification, verification_sha256, verification_path)
    if verification['inputs']['retained_manifest_sha256'] != sha(manifest_path) or verification['inputs']['recipe_sha256'] != sha(ROOT / 'build/units.json'):
        raise ValueError('retained receipt does not bind current manifest and recipes')
    for relative, value in verification['inputs']['tools_sha256'].items():
        if sha(ROOT / relative) != value:
            raise ValueError('verified comparison tool changed')
    original = manifest_path.parent / manifest.get('object_root_relative', '.') / unit['object']
    if sha(original) != unit['object_sha256'] or sha(ROOT / unit['source']) != unit['source_sha256']:
        raise ValueError('retained object or recorded source changed')
    before = audit_object(original)
    out.mkdir(parents=True)
    report = dict(schema_version=1, kind='source-built-game-leaf-link-probe', status='error',
        scope='one actual source-built field-read body with synthetic fixture; not game class/runtime/gameplay proof',
        verification_sha256=verification_sha256, original_object_sha256=unit['object_sha256'],
        source_sha256=sha(SOURCE), recipe_id=unit['recipe_id'], object_audit=before, stages={})
    try:
        root, sdk = toolchain.layout(compiler_root)
        cl, link, dumpbin = (root / 'VC/bin' / n for n in ('cl.exe', 'link.exe', 'dumpbin.exe'))
        report['tool_hashes'] = {n: sha(p) for n, p in [('cl', cl), ('link', link), ('dumpbin', dumpbin),
            ('libcmt', root / 'VC/lib/libcmt.lib'), ('kernel32', sdk / 'Lib/kernel32.lib')]}
        _, banner = toolchain.run([cl], root, out, timeout=30)
        if not re.search(r'Version\s+' + re.escape(toolchain.VERSIONS['sp1']) + r'\b', banner):
            raise ValueError('wrong compiler version')
        prov = out / 'provenance.json'
        selected = original
        if extract_reviewed_leaf:
            if image_path is None:
                raise ValueError('owned matching image required for unchanged extracted-body comparison')
            from coff_extract import extract
            selected = out / 'selected.obj'
            extracted = extract(original, selected, out / 'extract-receipt.json', manifest_path,
                ROOT / 'build/units.json', verification_path, verification_sha256, unit['recipe_id'], OLD)
            report['extraction_receipt_sha256'] = sha(out / 'extract-receipt.json')
            report['selected_object_sha256'] = extracted['output_sha256']
        selected_audit = audit_object(selected)
        prov.write_text(json.dumps(dict(schema_version=1, kind='fnv-coff-rename-provenance',
            recipe_id=unit['recipe_id'], object_sha256=sha(selected),
            source=str(ROOT / unit['source']), source_sha256=unit['source_sha256'])), encoding='utf-8')
        leaf = out / 'leaf.obj'
        rename = rewrite(selected, leaf, out / 'rename-receipt.json', prov, sha(selected), OLD, NEW)
        after = audit_object(leaf, NEW)
        if selected_audit != after or before['payload_sha256'] != after['payload_sha256']:
            raise ValueError('renamed object section closure changed')
        if extract_reviewed_leaf:
            import sys
            sys.path.insert(0, str(ROOT / 'tools'))
            import build_and_match as oracle
            if sha(image_path) != verification['inputs']['image_sha256']:
                raise ValueError('owned reference image differs from retained verification')
            pe = oracle.Pe(image_path)
            if not oracle.image_ok(pe)[0]:
                raise ValueError('unchanged image gate rejected comparison input')
            index = ROOT / 'build/function_index.json'
            spans = oracle.FunctionSpans.from_index(pe, index) if index.exists() else None
            rows = oracle.compare(oracle.Coff(leaf), pe, dict(symbols={}, functions=[
                dict(symbol=NEW, address=ADDRESS, size=4)]), spans)
            if len(rows) != 1 or rows[0]['verdict'] != 'match':
                raise ValueError('unchanged comparator rejected extracted/renamed body')
            report['extracted_body_reference_check'] = dict(verdict='match', bytes=4, relocations=0, differences=0)
            report['selection_mode'] = 'explicit reviewed zero-relocation leaf extraction'
        fixture, exe, mapfile = (out / n for n in ('fixture.obj', 'probe.exe', 'probe.map'))
        code, log = toolchain.run([cl] + COMPILE + [SOURCE, '/Fo' + str(fixture)], root, out, timeout=120)
        (out / 'compile.log').write_text(log, encoding='utf-8')
        if code or not fixture.is_file():
            raise ValueError('fixture compile failed')
        fixture_coff = Coff(fixture)
        if any(s['name'].startswith(('.CRT$', '.tls', '.sxdata')) for s in fixture_coff.sections.values()):
            raise ValueError('unreviewed fixture runtime initializer metadata')
        code, log = toolchain.run([link] + LINK + ['/out:' + str(exe), '/map:' + str(mapfile), fixture, leaf], root, out, timeout=120)
        (out / 'link.log').write_text(log, encoding='utf-8')
        report['stages']['link'] = dict(returncode=code)
        if code:
            report['unresolved'] = link_blockers(log, unit['recipe'].get('symbols', {}))
            raise ValueError('normal whole-object link failed; no stubs or extraction attempted')
        address = map_leaf(mapfile.read_text(encoding='utf-8'))
        if pe_machine(exe) != 0x14c:
            raise ValueError('linked image is not x86')
        code, log = toolchain.run([dumpbin, '/imports', exe], root, out, timeout=30)
        (out / 'imports.log').write_text(log, encoding='utf-8')
        dlls = re.findall(r'(?im)^\s*([A-Za-z0-9_.-]+\.dll)\s*$', log)
        if code or not dlls or {x.lower() for x in dlls} != {'kernel32.dll'}:
            raise ValueError('unexpected linked imports')
        import sys
        sys.path.insert(0, str(ROOT / 'tools'))
        from compare import Pe
        pe = Pe(exe)
        if hashlib.sha256(pe.read(address, 4)).hexdigest() != before['payload_sha256']:
            raise ValueError('linked leaf payload differs')
        if sha(original) != unit['object_sha256'] or sha(leaf) != rename['output_sha256']:
            raise ValueError('object inputs changed during link')
        report.update(status='linked_pending_independent_map_review', executed=False,
            linked_leaf_address=hex(address), leaf_object_sha256=sha(leaf), fixture_object_sha256=sha(fixture),
            executable_sha256=sha(exe), map_sha256=sha(mapfile), imports_sha256=sha(out / 'imports.log'),
            linked_leaf_payload_unchanged=True, no_other_game_public_providers=True, dlls=dlls)
    except (OSError, ValueError, subprocess.TimeoutExpired) as error:
        report['error'] = str(error) if isinstance(error, ValueError) else type(error).__name__
    (out / 'link-receipt.json').write_text(json.dumps(report, indent=2), encoding='utf-8')
    return report


def execute_reviewed(out, reviewed_map_sha256):
    out = Path(out).resolve()
    receipt = out / 'link-receipt.json'
    report = json.loads(receipt.read_text(encoding='utf-8'))
    result_path = out / 'execution-receipt.json'
    if result_path.exists():
        raise ValueError('execution receipt already exists')
    if report.get('kind') != 'source-built-game-leaf-link-probe' or report.get('status') != 'linked_pending_independent_map_review' or report.get('map_sha256') != reviewed_map_sha256:
        raise ValueError('explicit independently reviewed map hash required')
    for name, key in [('probe.map', 'map_sha256'), ('probe.exe', 'executable_sha256'),
                      ('leaf.obj', 'leaf_object_sha256'), ('fixture.obj', 'fixture_object_sha256'), ('imports.log', 'imports_sha256')]:
        if sha(out / name) != report[key]:
            raise ValueError('reviewed artifact changed')
    if sha(SOURCE) != report['source_sha256']:
        raise ValueError('fixture source changed after link review')
    result = subprocess.run([str(out / 'probe.exe')], cwd=out, stdin=subprocess.DEVNULL,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, timeout=30)
    observed = json.loads(result.stdout)
    if result.returncode or result.stderr or observed != EXPECTED or any(type(v) is not int for v in observed.values()):
        raise ValueError('leaf runtime assertions failed')
    execution = dict(schema_version=1, kind='source-built-game-leaf-execution', status='pass',
        link_receipt_sha256=sha(receipt), reviewed_map_sha256=reviewed_map_sha256,
        executable_sha256=report['executable_sha256'], observed=observed,
        scope='one source-built leaf on original synthetic fixture; no game class/bootstrap/gameplay verdict')
    with result_path.open('x', encoding='utf-8') as stream:
        json.dump(execution, stream, indent=2)
    return execution


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--sp1-root', default=os.environ.get('FNV_MSVC9_ROOT'))
    parser.add_argument('--manifest', type=Path)
    parser.add_argument('--verification', type=Path)
    parser.add_argument('--verification-sha256')
    parser.add_argument('--out', required=True, type=Path)
    parser.add_argument('--reviewed-map-sha256', help='execute existing probe only after independent review')
    parser.add_argument('--extract-reviewed-leaf', action='store_true')
    parser.add_argument('--image', type=Path, help='private retained-proof image for extracted body comparison')
    args = parser.parse_args()
    if args.reviewed_map_sha256:
        report = execute_reviewed(args.out, args.reviewed_map_sha256)
    else:
        if not args.manifest or not args.verification or not args.verification_sha256:
            parser.error('manifest, verification and verification-sha256 required for build')
        report = prepare(args.sp1_root, args.manifest, args.verification, args.verification_sha256, args.out,
                         extract_reviewed_leaf=args.extract_reviewed_leaf, image_path=args.image)
    print(json.dumps(dict(status=report['status'])))
    return 0 if report['status'] in ('pass', 'linked_pending_independent_map_review') else 1


if __name__ == '__main__':
    raise SystemExit(main())
