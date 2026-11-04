"""One named CRT member comparison and opt-in original contract fixture."""
from __future__ import annotations
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'tools'))
from compare import Coff, Pe
from build_and_match import image_ok
import toolchain

SOURCE = ROOT/'runtime/probes/crt_purecall_probe.cpp'
TARGET = 0x00ec60fa
DEPENDENCIES = {'___pPurecall', '__decode_pointer', '__NMSG_WRITE', '__set_abort_behavior', '_abort'}
RELOCATION_SHAPE = [(2, 6, '___pPurecall'), (7, 20, '__decode_pointer'), (21, 20, '__NMSG_WRITE'),
                    (30, 20, '__set_abort_behavior'), (38, 20, '_abort')]
MODES = ('state', 'exit-hook', 'default', 'state')


def require(ok, message):
    if not ok: raise ValueError(message)


def sha(path): return toolchain.sha256(path)


def read_bound(path, expected):
    require(isinstance(expected, str) and re.fullmatch('[0-9a-f]{64}', expected), 'invalid trusted hash')
    require(sha(path) == expected, 'SHA-256 identity mismatch')
    return json.loads(Path(path).read_text(encoding='utf-8'))


def save_new(path, value):
    path = Path(path); path.parent.mkdir(parents=True, exist_ok=True)
    with path.open('x', encoding='utf-8') as f: json.dump(value, f, indent=2); f.write('\n')


def archive_member(path, symbol='__purecall'):
    """Use the first linker symbol table to locate exactly one member."""
    require(Path(path).stat().st_size <= 32*1024*1024, 'archive exceeds limit')
    data = Path(path).read_bytes()
    require(data[:8] == b'!<arch>\n', 'not a COFF archive')
    def member(offset):
        require(8 <= offset <= len(data)-60, 'invalid archive member offset')
        header = data[offset:offset+60]
        require(header[58:] == b'`\n', 'invalid archive member header')
        length = int(header[48:58]); require(0 <= length <= len(data)-offset-60, 'truncated member')
        return header[:16].decode('ascii').strip(), data[offset+60:offset+60+length]
    name, linker = member(8)
    require(name == '/' and len(linker) >= 4, 'first archive member is not linker table')
    count = struct.unpack_from('>I', linker)[0]
    require(count <= 100000 and 4+count*4 <= len(linker), 'invalid linker symbol count')
    offsets = struct.unpack_from('>'+str(count)+'I', linker, 4)
    names = linker[4+count*4:].split(b'\0')
    require(len(names) >= count+1 and names[count] == b'', 'truncated linker symbol names')
    found = [offsets[i] for i in range(count) if names[i] == symbol.encode('ascii')]
    require(len(found) == 1, 'named archive symbol is absent or ambiguous')
    name, payload = member(found[0])
    require(len(payload) <= 1024*1024, 'member exceeds bound')
    return payload, dict(archive_sha256=hashlib.sha256(data).hexdigest(), member_header_offset=found[0],
                        member_name_field=name, member_sha256=hashlib.sha256(payload).hexdigest(), member_size=len(payload))


def member_contract(payload, reference_bytes, address=TARGET):
    # Existing COFF reader accepts files. This temporary member is private and
    # removed on exit; no library bytes are retained in reports or the checkout.
    with tempfile.TemporaryDirectory(prefix='fnv_crt_member_') as tmp:
        path = Path(tmp)/'member.obj'; path.write_bytes(payload); coff = Coff(path)
    symbol = coff.named('__purecall'); section = coff.sections[symbol['section']]
    require(symbol['value'] == 0 and len(section['data']) == 42 and len(reference_bytes) == 42,
            'named member shape differs from bounded 42-byte contract')
    masks, relocations = set(), []
    for offset, index, kind in section['relocs']:
        require(kind in (6, 20) and 0 <= offset <= 38 and not masks.intersection(range(offset, offset+4)),
                'unsupported or overlapping purecall relocation')
        target = coff.symbols[index]
        require(target['section'] == 0 and target['name'] in DEPENDENCIES, 'unexpected dependency relocation')
        addend = struct.unpack_from('<I' if kind == 6 else '<i', section['data'], offset)[0]
        observed = struct.unpack_from('<I' if kind == 6 else '<i', reference_bytes, offset)[0]
        target_va = (observed - addend + (address+offset+4 if kind == 20 else 0)) & 0xffffffff
        relocations.append(dict(offset=offset, kind=kind, symbol=target['name'], addend=addend,
                               original_target_va=f'0x{target_va:08x}', target_identity_verified=False))
        masks.update(range(offset, offset+4))
    require(len(relocations) == 5 and {r['symbol'] for r in relocations} == DEPENDENCIES,
            'incomplete dependency set')
    require([(r['offset'], r['kind'], r['symbol']) for r in relocations] == RELOCATION_SHAPE,
            'changed relocation shape')
    require(all(section['data'][i] == reference_bytes[i] for i in range(42) if i not in masks),
            'nonrelocation byte identity failed')
    return dict(symbol='__purecall', reference_entry=f'0x{address:08x}', size=42,
                section=symbol['section'], value=0, nonrelocation_bytes_equal=True,
                compared_nonrelocation_bytes=42-len(masks), relocations=relocations,
                complete_relocation_identity_verified=False, runtime_provider_selected=False)


def audit(args):
    require(not Path(args.out).exists(), 'output exists')
    inputs = dict(reference=sha(args.reference), sp1_library=sha(args.sp1_lib), rtm_library=sha(args.rtm_lib))
    for name in inputs: require(inputs[name] == getattr(args, name+'_sha256'), 'stale '+name+' hash')
    pe = Pe(args.reference)
    require(hashlib.sha256(pe.data).hexdigest() == inputs['reference'], 'reference changed while loading')
    passed, hits, probes = image_ok(pe)
    require(passed, 'reference image probes failed')
    reference = pe.read(TARGET, 42)
    members = {}
    for name in ('sp1', 'rtm'):
        payload, metadata = archive_member(getattr(args, name+'_lib'))
        members[name] = dict(metadata, **member_contract(payload, reference))
    require(members['sp1']['relocations'] == members['rtm']['relocations'], 'SP1/RTM relocation contracts differ')
    for name, path in [('reference', args.reference), ('sp1_library', args.sp1_lib), ('rtm_library', args.rtm_lib)]:
        require(sha(path) == inputs[name], 'input changed during comparison')
    report = dict(schema_version=1, kind='fnv-one-crt-member-contract', status='bounded-identity-observed',
        inputs=inputs, implementation_sha256=sha(__file__), image_gate=dict(hits=hits, probes=probes),
        members=members, game_fixups_approved=0, provider_selected=False,
        scope='One named 42-byte target; unresolved dependency target identity/ABI/state are not promoted.')
    save_new(args.out, report)
    return report


def parse_mode(mode, result):
    lines = result.stdout.splitlines()
    require(len(result.stdout) <= 4096 and len(result.stderr) <= 4096, 'unexpected output size')
    if mode == 'state':
        require(result.returncode == 0 and lines == ['fresh-null-handler', 'set-restored-null'] and not result.stderr,
                'state/set-restore fixture failed')
    elif mode == 'exit-hook':
        require(result.returncode == 73 and lines == ['fresh-null-handler', 'before-exit-hook', 'hook-exit-73']
                and not result.stderr, 'intentional hook-exit fixture failed')
    elif mode == 'default':
        require(result.returncode == 3 and lines == ['fresh-null-handler', 'before-default-abort']
                and 'R6025' in result.stderr and 'pure virtual function call' in result.stderr,
                'default null-hook termination differs from expected CRT abort exit 3')
    else: raise ValueError('unsafe unknown child mode')
    return dict(mode=mode, returncode=result.returncode, stdout=result.stdout, stderr=result.stderr)


def prepare(args):
    require(os.name == 'nt', 'native Windows required')
    out = Path(args.out).resolve(); require(not out.exists(), 'output directory exists')
    require(not os.environ.get('LINK') and not os.environ.get('_LINK_'), 'implicit linker flags not allowed')
    root, sdk = toolchain.layout(args.sp1_root)
    audited = read_bound(args.audit, args.audit_sha256)
    require(audited.get('kind') == 'fnv-one-crt-member-contract' and not audited['provider_selected'], 'invalid audit proof')
    require(sha(root/'VC/lib/libcmt.lib') == audited['inputs']['sp1_library'], 'stale audited SP1 library')
    paths = [SOURCE, Path(__file__), ROOT/'tools/rebuild/toolchain.py', ROOT/'tools/compare.py',
             ROOT/'tools/build_and_match.py', ROOT/'tools/function_spans.py', ROOT/'build/image_check.json',
             root/'VC/bin/cl.exe', root/'VC/bin/link.exe', root/'VC/bin/dumpbin.exe',
             root/'VC/lib/libcmt.lib', root/'VC/lib/oldnames.lib', sdk/'Lib/kernel32.lib',
             root/'VC/include/stdlib.h', sdk/'Include/werapi.h', Path(args.audit).resolve()]
    os_kernel = Path(os.environ['SystemRoot'])/'SysWOW64/kernel32.dll'
    require(os_kernel.is_file(), 'x86 OS dependency not found')
    paths.append(os_kernel)
    inputs = {str(p.resolve()): sha(p) for p in paths}
    out.mkdir(parents=True)
    cl, link, dump = root/'VC/bin/cl.exe', root/'VC/bin/link.exe', root/'VC/bin/dumpbin.exe'
    code, banner = toolchain.run([cl], root, out, timeout=30)
    require(re.search(r'Version\s+'+re.escape(toolchain.VERSIONS['sp1'])+r'\b', banner), 'not VC9 SP1 compiler')
    obj, exe, mapfile = [out/x for x in ('probe.obj', 'probe.exe', 'probe.map')]
    code, log = toolchain.run([cl, '/nologo', '/c', '/MT', '/EHsc', '/GS', '/W4', SOURCE, '/Fo'+str(obj)], root, out, timeout=60)
    (out/'compile.log').write_text(log)
    require(code == 0 and obj.is_file(), 'fixture compile failed')
    code, log = toolchain.run([link, '/nologo', '/machine:x86', '/subsystem:console', '/out:'+str(exe),
                              '/map:'+str(mapfile), obj], root, out, timeout=60)
    (out/'link.log').write_text(log)
    require(code == 0 and exe.is_file() and mapfile.is_file(), 'fixture link failed')
    mapping = mapfile.read_text()
    required = ['__purecall', '__set_purecall_handler', '__get_purecall_handler', '__decode_pointer',
                '__encode_pointer', '___pPurecall', '__set_abort_behavior', '__NMSG_WRITE',
                '___security_cookie', '___security_init_cookie', '_abort']
    providers = {}
    for symbol in required:
        rows = [line for line in mapping.splitlines() if symbol in line.split()]
        require(len(rows) == 1 and 'libcmt:' in rows[0].lower(), 'normal static CRT provider not proved: '+symbol)
        providers[symbol] = rows[0].strip()
    require('__imp___purecall' not in mapping, 'purecall IAT provider is not allowed')
    code, imports = toolchain.run([dump, '/nologo', '/imports', exe], root, out, timeout=30)
    (out/'imports.log').write_text(imports)
    require(code == 0, 'import inspection failed')
    dlls = sorted(set(re.findall(r'^\s+([A-Za-z0-9_.-]+\.dll)\s*$', imports, re.M|re.I)))
    require(dlls and all(d.upper() == 'KERNEL32.DLL' for d in dlls), 'unexpected direct DLL dependency')
    for p in (obj, exe, mapfile, out/'compile.log', out/'link.log', out/'imports.log'):
        inputs[str(p)] = sha(p)
    for p, h in inputs.items(): require(sha(p) == h, 'preparation input changed')
    report = dict(schema_version=1, kind='original-purecall-fixture-preparation', status='prepared-not-executed',
        audit_sha256=args.audit_sha256, inputs=inputs, compiler_version=toolchain.VERSIONS['sp1'],
        providers=providers, direct_dlls=dlls, direct_OS_dependency_sha256=sha(os_kernel),
        direct_OS_dependency_scope='x86 kernel32.dll; forwarded/transitive OS modules not claimed',
        modes=list(MODES), source_has_no_virtual_dispatch=True,
        game_execution=False, game_fixups_approved=0, runtime_provider_selected=False,
        suppression='per-child CRT stderr/abort flags, SetErrorMode, checked WerSetFlags/WerGetFlags(NO_UI)',
        expected=dict(state_exit=0, intentional_hook_exit=73, null_hook_abort_exit=3, timeout_seconds=10))
    save_new(out/'prepare.json', report)
    return report


def execute(args):
    require(args.allow_execute is True, 'execution requires explicit --allow-execute')
    require(not Path(args.out).exists(), 'execution report exists')
    proof = read_bound(args.proof, args.proof_sha256)
    require(proof.get('kind') == 'original-purecall-fixture-preparation'
            and proof.get('status') == 'prepared-not-executed' and proof.get('modes') == list(MODES),
            'invalid preparation proof')
    require(args.review is not None and args.review_sha256 is not None, 'independent review required')
    review = read_bound(args.review, args.review_sha256)
    require(review.get('schema_version') == 1 and review.get('kind') == 'crt-purecall-fixture-independent-review'
            and review.get('status') == 'approved' and isinstance(review.get('reviewer'), str)
            and bool(review['reviewer'].strip()) and review.get('prepare_sha256') == args.proof_sha256,
            'invalid independent review')
    require(all(review.get('checks', {}).get(k) is True for k in
                ('source_no_virtual_dispatch', 'bounded_child_suppression', 'normal_static_CRT_providers',
                 'hash_bound_inputs', 'expected_modes_and_failure_semantics')), 'incomplete independent review')
    def revalidate():
        require(sha(args.proof) == args.proof_sha256 and sha(args.review) == args.review_sha256,
                'stale proof or review')
        for p, h in proof['inputs'].items(): require(sha(p) == h, 'stale prepared input')
    revalidate()
    require(proof['inputs'].get(str(Path(__file__).resolve())) == sha(__file__)
            and proof['inputs'].get(str(SOURCE.resolve())) == sha(SOURCE), 'unbound runner or fixture')
    exe = Path(args.proof).resolve().parent/'probe.exe'
    require(str(exe) in proof['inputs'], 'unbound executable')
    require(review.get('executable_sha256') == proof['inputs'][str(exe)]
            and review.get('map_sha256') == proof['inputs'][str(exe.parent/'probe.map')], 'review output identity differs')
    outcomes = []; report = dict(schema_version=1, kind='original-purecall-fixture-execution',
        proof_sha256=args.proof_sha256, review_sha256=args.review_sha256, status='fail', outcomes=outcomes, game_fixups_approved=0,
        runtime_provider_selected=False)
    try:
        for mode in MODES:
            revalidate()
            result = subprocess.run([str(exe), mode], cwd=exe.parent, stdin=subprocess.DEVNULL,
                stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, errors='replace', timeout=10,
                creationflags=subprocess.CREATE_NO_WINDOW)
            observed = dict(mode=mode, returncode=result.returncode, stdout=result.stdout, stderr=result.stderr)
            outcomes.append(observed); parse_mode(mode, result)
            revalidate()
        report['status'] = 'pass'
    except (ValueError, subprocess.TimeoutExpired, OSError) as error:
        report['error'] = str(error) if isinstance(error, ValueError) else type(error).__name__
    save_new(args.out, report)
    return report


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__); commands = p.add_subparsers(dest='command', required=True)
    a = commands.add_parser('audit')
    for name in ('reference', 'sp1-lib', 'rtm-lib'):
        a.add_argument('--'+name, required=True, type=Path)
        hashname = {'sp1-lib':'sp1-library', 'rtm-lib':'rtm-library'}.get(name, name)
        a.add_argument('--'+hashname+'-sha256', required=True)
    a.add_argument('--out', type=Path, required=True)
    a = commands.add_parser('prepare'); a.add_argument('--sp1-root', type=Path, required=True)
    a.add_argument('--audit', type=Path, required=True); a.add_argument('--audit-sha256', required=True)
    a.add_argument('--out', type=Path, required=True)
    a = commands.add_parser('execute'); a.add_argument('--proof', type=Path, required=True)
    a.add_argument('--proof-sha256', required=True); a.add_argument('--allow-execute', action='store_true')
    a.add_argument('--review', type=Path); a.add_argument('--review-sha256')
    a.add_argument('--out', type=Path, required=True)
    args = p.parse_args(argv)
    try: report = dict(audit=audit, prepare=prepare, execute=execute)[args.command](args)
    except (OSError, ValueError, KeyError, struct.error) as e: p.exit(2, 'CRT contract failed: '+str(e)+'\n')
    print(report['status']); return 0 if report['status'] != 'fail' else 1


if __name__ == '__main__': raise SystemExit(main())
