"""Compile and run an independent VC9 SP1 CRT/TLS probe, not a game build."""
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

import toolchain

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / 'runtime/probes/crt_tls_probe.cpp'
EXPECTED = {'schema': 1, 'constructor': 1, 'destructor': 1,
            'main_initial': 37, 'main_final': 99,
            'thread_initial': [37, 37], 'thread_final': [101, 102], 'checks_ok': 1}
COMPILE_FLAGS = ['/nologo', '/c', '/MT', '/EHsc', '/GS', '/W4']
LINK_FLAGS = ['/nologo', '/machine:x86', '/subsystem:console']


def parse_receipt(output, returncode):
    """Require one exact CRT exit receipt and a successful process exit."""
    if returncode != 0:
        raise ValueError('probe process returned nonzero')
    try:
        lines = [line for line in output.splitlines() if line.strip()]
        if len(lines) != 1:
            raise ValueError('expected exactly one receipt')
        observed = json.loads(lines[0])
    except (json.JSONDecodeError, TypeError) as exc:
        raise ValueError('invalid probe receipt') from exc
    if observed != EXPECTED or any(type(observed[k]) is not type(v) for k, v in EXPECTED.items()):
        raise ValueError('probe receipt checks failed')
    return observed


def pe_machine(path):
    with path.open('rb') as stream:
        if stream.read(2) != b'MZ':
            raise ValueError('output is not a PE executable')
        stream.seek(0x3c)
        offset_data = stream.read(4)
        if len(offset_data) != 4:
            raise ValueError('truncated PE header')
        offset = struct.unpack('<I', offset_data)[0]
        if offset > 1024 * 1024:
            raise ValueError('invalid PE header offset')
        stream.seek(offset)
        if stream.read(4) != b'PE\0\0':
            raise ValueError('invalid PE signature')
        value = stream.read(2)
        if len(value) != 2:
            raise ValueError('truncated PE machine')
        return struct.unpack('<H', value)[0]


def run_probe(root, out):
    """Run serially; caller is responsible for sharing the compile slot budget."""
    out = Path(out)
    if out.exists():
        raise ValueError('output directory already exists; choose a new directory')
    out.mkdir(parents=True)
    report = {'schema_version': 1, 'kind': 'standalone-crt-tls-probe', 'status': 'error',
              'scope': 'Independent test only; no game startup, link closure, or gameplay claim.',
              'compiler': {}, 'inputs': {}, 'commands': {'compile_flags': COMPILE_FLAGS, 'link_flags': LINK_FLAGS},
              'stages': {}}
    try:
        if os.name != 'nt':
            raise ValueError('native probe requires Windows')
        if not root:
            raise ValueError('set FNV_MSVC9_ROOT or --sp1-root')
        if os.environ.get('LINK') or os.environ.get('_LINK_'):
            raise ValueError('unset LINK and _LINK_ implicit linker options before running')
        root, sdk = toolchain.layout(root)
        cl, link = root / 'VC/bin/cl.exe', root / 'VC/bin/link.exe'
        # Hash the explicit default static CRT and Win32 import library as well as tools.
        files = {'cl_sha256': cl, 'link_sha256': link, 'libcmt_sha256': root / 'VC/lib/libcmt.lib',
                 'kernel32_sha256': sdk / 'Lib/kernel32.lib'}
        report['inputs']['source_sha256'] = toolchain.sha256(SOURCE)
        for key, path in files.items():
            report['compiler'][key] = toolchain.sha256(path)
        code, banner = toolchain.run([cl], root, out, timeout=30)
        match = re.search(r'Version\s+([\d.]+)', banner)
        version = match.group(1) if match else None
        report['compiler']['version'] = version
        if version != toolchain.VERSIONS['sp1']:
            raise ValueError('compiler version does not match SP1 requirement')
        obj, exe, mapfile = (out / x for x in ['crt_tls_probe.obj', 'crt_tls_probe.exe', 'crt_tls_probe.map'])
        command = [cl] + COMPILE_FLAGS + [SOURCE, '/Fo' + str(obj)]
        code, output = toolchain.run(command, root, out, timeout=120)
        (out / 'compile.log').write_text(output, encoding='utf-8')
        report['stages']['compile'] = {'returncode': code, 'object_present': obj.is_file()}
        if code or not obj.is_file():
            raise ValueError('compile failed')
        report['inputs']['object_sha256'] = toolchain.sha256(obj)
        command = [link] + LINK_FLAGS + ['/out:' + str(exe), '/map:' + str(mapfile), obj]
        code, output = toolchain.run(command, root, out, timeout=120)
        (out / 'link.log').write_text(output, encoding='utf-8')
        report['stages']['link'] = {'returncode': code, 'executable_present': exe.is_file(), 'map_present': mapfile.is_file()}
        if code or not exe.is_file() or not mapfile.is_file():
            raise ValueError('link failed')
        if pe_machine(exe) != 0x14c:
            raise ValueError('output is not x86')
        report['inputs']['executable_sha256'] = toolchain.sha256(exe)
        report['inputs']['map_sha256'] = toolchain.sha256(mapfile)
        result = subprocess.run([str(exe)], cwd=out, env=toolchain.environment(root),
                                stdin=subprocess.DEVNULL, stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE, text=True, errors='replace', timeout=35)
        (out / 'execution.stdout.log').write_text(result.stdout, encoding='utf-8')
        (out / 'execution.stderr.log').write_text(result.stderr, encoding='utf-8')
        report['stages']['execute'] = {'returncode': result.returncode}
        if result.stderr:
            raise ValueError('probe emitted unexpected stderr')
        report['observed'] = parse_receipt(result.stdout, result.returncode)
        report['status'] = 'pass'
    except (OSError, ValueError, subprocess.TimeoutExpired) as exc:
        # Private logs contain details; avoid echoing private compiler paths into the report.
        report['error'] = type(exc).__name__ + ': ' + (str(exc) if isinstance(exc, ValueError) else 'tool or process failed; inspect private logs')
    (out / 'receipt.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    return report


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--sp1-root', default=os.environ.get('FNV_MSVC9_ROOT'), help='private VC9 SP1 root')
    parser.add_argument('--out', type=Path, default=ROOT / 'build/rebuild/runtime-probe', help='new private output directory')
    args = parser.parse_args(argv)
    try:
        report = run_probe(args.sp1_root, args.out.resolve())
    except (OSError, ValueError) as exc:
        parser.exit(2, 'probe could not start: %s\n' % type(exc).__name__)
    print('Runtime probe: ' + report['status'])
    return 0 if report['status'] == 'pass' else 1


if __name__ == '__main__':
    sys.exit(main())
