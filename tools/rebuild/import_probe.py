"""Demonstrate reviewed x86 import-pointer aliases in a standalone program."""
from __future__ import annotations
import argparse
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import toolchain
from runtime_probe import pe_machine

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / 'runtime/probes/import_alias_probe.cpp'
ALIASES = {
    '__imp_?FetchCommandLineW@@YGPA_WXZ': '__imp__GetCommandLineW@0',
    '__imp_?ReadCurrentProcessId@@YGKXZ': '__imp__GetCurrentProcessId@0',
}
EXPECTED = {'schema': 1, 'wide_command_line_valid': 1, 'process_id_valid': 1, 'checks_ok': 1}
COMPILE = ['/nologo', '/c', '/MT', '/Od', '/GS', '/EHsc', '/Gy']
LINK = ['/nologo', '/machine:x86', '/subsystem:console']


def validate_aliases(aliases):
    if aliases != ALIASES or any(not s.startswith('__imp_?') or not t.startswith('__imp__') for s, t in aliases.items()):
        raise ValueError('only the two reviewed import-pointer aliases are permitted')
    return ['/alternatename:' + source + '=' + target for source, target in aliases.items()]


def check_relocations(text, aliases):
    for name in list(aliases) + list(aliases.values()):
        if not any('DIR32' in line and name in line for line in text.splitlines()):
            raise ValueError('expected import-pointer relocation missing')


def check_imports(text):
    match = re.search(r'(?ims)^\s*KERNEL32\.dll\s*$([\s\S]*?)(?=^\s*\S+\.dll\s*$|^\s*Summary\s*$|\Z)', text)
    if not match:
        raise ValueError('KERNEL32 import descriptor missing')
    block = match.group(1)
    for name in ('GetCommandLineW', 'GetCurrentProcessId'):
        if not re.search(r'(?m)^\s*[0-9A-F]+\s+' + name + r'\s*$', block):
            raise ValueError('required canonical import missing')
    if re.search(r'\b(?:FetchCommandLineW|ReadCurrentProcessId)\b', text):
        raise ValueError('unexpected synthetic import name')


def parse_receipt(stdout, stderr, code):
    if code != 0 or stderr:
        raise ValueError('probe process failed')
    try:
        lines = [line for line in stdout.splitlines() if line.strip()]
        if len(lines) != 1:
            raise ValueError('expected one receipt')
        result = json.loads(lines[0])
    except (json.JSONDecodeError, TypeError) as exc:
        raise ValueError('invalid receipt') from exc
    if result != EXPECTED or any(type(result[k]) is not int for k in EXPECTED):
        raise ValueError('API checks failed')
    return result


def run_probe(root, out):
    out = Path(out)
    if out.exists():
        raise ValueError('output directory already exists')
    out.mkdir(parents=True)
    report = {'schema_version': 1, 'kind': 'standalone-import-alias-probe', 'status': 'error',
              'scope': 'Original standalone proof; no game entry, ABI closure, or gameplay claim.',
              'aliases': ALIASES, 'compiler': {}, 'inputs': {}, 'stages': {},
              'commands': {'compile_flags': COMPILE, 'link_flags': LINK}}
    try:
        if os.name != 'nt': raise ValueError('native probe requires Windows')
        if not root: raise ValueError('set FNV_MSVC9_ROOT or --sp1-root')
        if os.environ.get('LINK') or os.environ.get('_LINK_'):
            raise ValueError('unset implicit LINK and _LINK_ options')
        alias_args = validate_aliases(ALIASES)
        root, sdk = toolchain.layout(root)
        cl, link, dumpbin = (root / 'VC/bin' / n for n in ('cl.exe', 'link.exe', 'dumpbin.exe'))
        for name, path in {'cl_sha256': cl, 'link_sha256': link, 'dumpbin_sha256': dumpbin,
                           'libcmt_sha256': root / 'VC/lib/libcmt.lib', 'kernel32_sha256': sdk / 'Lib/kernel32.lib'}.items():
            report['compiler'][name] = toolchain.sha256(path)
        report['inputs']['source_sha256'] = toolchain.sha256(SOURCE)
        _, banner = toolchain.run([cl], root, out, timeout=30)
        version = re.search(r'Version\s+([\d.]+)', banner)
        report['compiler']['version'] = version.group(1) if version else None
        if report['compiler']['version'] != toolchain.VERSIONS['sp1']: raise ValueError('wrong compiler version')
        obj, exe, before_exe, mapfile = (out / n for n in ('probe.obj', 'probe.exe', 'before.exe', 'probe.map'))
        code, output = toolchain.run([cl] + COMPILE + [SOURCE, '/Fo' + str(obj)], root, out, timeout=120)
        (out / 'compile.log').write_text(output, encoding='utf-8')
        report['stages']['compile'] = {'returncode': code, 'object_present': obj.is_file()}
        if code or not obj.is_file(): raise ValueError('compile failed')
        original_hash = toolchain.sha256(obj)
        report['inputs']['object_sha256'] = original_hash
        code, output = toolchain.run([dumpbin, '/relocations', obj], root, out, timeout=30)
        (out / 'relocations.log').write_text(output, encoding='utf-8')
        if code: raise ValueError('relocation inspection failed')
        check_relocations(output, ALIASES)
        code, output = toolchain.run([dumpbin, '/symbols', obj], root, out, timeout=30)
        (out / 'symbols.log').write_text(output, encoding='utf-8')
        if code or any(not any('UNDEF' in line and name in line for line in output.splitlines()) for name in ALIASES):
            raise ValueError('expected undefined alias symbols missing')
        report['stages']['object'] = {'undefined_aliases': list(ALIASES), 'pointer_relocations_verified': True}
        command = [link] + LINK + ['/out:' + str(before_exe), obj]
        code, output = toolchain.run(command, root, out, timeout=120)
        (out / 'link-before.log').write_text(output, encoding='utf-8')
        if code == 0 or any(name not in output for name in ALIASES):
            raise ValueError('baseline must fail with both expected unresolved aliases')
        report['stages']['link_before'] = {'returncode': code, 'unresolved_aliases': list(ALIASES)}
        command = [link] + LINK + alias_args + ['/out:' + str(exe), '/map:' + str(mapfile), obj]
        code, output = toolchain.run(command, root, out, timeout=120)
        (out / 'link-after.log').write_text(output, encoding='utf-8')
        report['stages']['link_after'] = {'returncode': code, 'executable_present': exe.is_file(), 'map_present': mapfile.is_file()}
        if code or not exe.is_file() or not mapfile.is_file(): raise ValueError('alias link failed')
        report['stages']['link_after']['unresolved_aliases'] = []
        if toolchain.sha256(obj) != original_hash: raise ValueError('object changed across link')
        if pe_machine(exe) != 0x14c: raise ValueError('output is not x86')
        report['inputs']['executable_sha256'] = toolchain.sha256(exe)
        report['inputs']['map_sha256'] = toolchain.sha256(mapfile)
        code, output = toolchain.run([dumpbin, '/imports', exe], root, out, timeout=30)
        (out / 'imports.log').write_text(output, encoding='utf-8')
        if code: raise ValueError('import inspection failed')
        check_imports(output)
        report['stages']['imports'] = {'dll': 'KERNEL32.dll', 'names': ['GetCommandLineW', 'GetCurrentProcessId'], 'synthetic_names_absent': True}
        result = subprocess.run([str(exe)], cwd=out, env=toolchain.environment(root), stdin=subprocess.DEVNULL,
                                stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, errors='replace', timeout=30)
        (out / 'execution.stdout.log').write_text(result.stdout, encoding='utf-8')
        (out / 'execution.stderr.log').write_text(result.stderr, encoding='utf-8')
        report['stages']['execute'] = {'returncode': result.returncode}
        report['observed'] = parse_receipt(result.stdout, result.stderr, result.returncode)
        report['status'] = 'pass'
    except (OSError, ValueError, subprocess.TimeoutExpired) as exc:
        report['error'] = type(exc).__name__ + ': ' + (str(exc) if isinstance(exc, ValueError) else 'tool or process failed; inspect private logs')
    (out / 'receipt.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    return report


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--sp1-root', default=os.environ.get('FNV_MSVC9_ROOT'))
    parser.add_argument('--out', type=Path, default=ROOT / 'build/rebuild/import-probe')
    args = parser.parse_args(argv)
    try:
        result = run_probe(args.sp1_root, args.out.resolve())
    except (OSError, ValueError) as exc:
        parser.exit(2, 'probe could not start: %s\n' % type(exc).__name__)
    print('Import alias probe: ' + result['status'])
    return 0 if result['status'] == 'pass' else 1


if __name__ == '__main__': sys.exit(main())
