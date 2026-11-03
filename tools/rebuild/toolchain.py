"""Native Windows compiler discovery and executable compile/link probes.

Private roots come from command options or the existing msvc.py environment
variables. Nothing installs software or accepts licence terms.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import tempfile

ROOT_VARS = {'sp1': 'FNV_MSVC9_ROOT', 'rtm': 'FNV_MSVC9_RTM_ROOT', 'vc8': 'FNV_MSVC8_ROOT'}
VERSIONS = {'sp1': '15.00.30729.01', 'rtm': '15.00.21022.08', 'vc8': '14.00.50727.762'}


def sha256(path):
    digest = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            digest.update(block)
    return digest.hexdigest()


def add_arguments(parser):
    for name, variable in ROOT_VARS.items():
        parser.add_argument('--' + name + '-root', default=os.environ.get(variable),
                            help='private compiler root (or %s)' % variable)


def layout(root):
    root = Path(root).resolve()
    sdk = root / 'SDK'
    if not sdk.is_dir():
        sdk = root / 'VC/PlatformSDK'
    return root, sdk


def environment(root):
    root, sdk = layout(root)
    env = os.environ.copy()
    # CL/_CL_ are implicit options and would silently change manifest recipes.
    env.pop('CL', None)
    env.pop('_CL_', None)
    env.update(INCLUDE=';'.join(map(str, [root / 'VC/include', sdk / 'Include'])),
               LIB=';'.join(map(str, [root / 'VC/lib', sdk / 'Lib'])))
    paths = [root / 'VC/bin', root / 'Common7/IDE',
             root / 'VC/redist/x86/Microsoft.VC90.CRT',
             root / 'VC/bin/Microsoft.VC80.CRT']
    env['PATH'] = os.pathsep.join(map(str, paths)) + os.pathsep + env.get('PATH', '')
    return env


def run(command, root, cwd, timeout=180):
    result = subprocess.run([str(x) for x in command], cwd=cwd, env=environment(root),
                            stdin=subprocess.DEVNULL, stdout=subprocess.PIPE,
                            stderr=subprocess.STDOUT, text=True, errors='replace', timeout=timeout)
    return result.returncode, result.stdout


def inspect(name, supplied_root):
    report = dict(compiler=name, expected_version=VERSIONS[name], ready=False)
    if os.name != 'nt':
        return dict(report, error='native rebuild currently requires Windows; existing matcher supports Wine')
    if not supplied_root:
        return dict(report, error='set %s or --%s-root' % (ROOT_VARS[name], name))
    root, sdk = layout(supplied_root)
    report.update(root=str(root), sdk=str(sdk))
    required = ['VC/bin/cl.exe', 'VC/bin/link.exe', 'VC/include', 'VC/lib']
    missing = [x for x in required if not (root / x).exists()]
    missing += [str(x) for x in [sdk / 'Include', sdk / 'Lib'] if not x.is_dir()]
    if missing:
        return dict(report, error='missing compiler/SDK paths', missing=missing)
    cl = root / 'VC/bin/cl.exe'
    report['cl_sha256'] = sha256(cl)
    report['link_sha256'] = sha256(root / 'VC/bin/link.exe')
    try:
        _, banner = run([cl], root, root, timeout=30)
        version = re.search(r'Version\s+([\d.]+)', banner)
        report['version'] = version.group(1) if version else None
        report['banner'] = banner[:1000]
        if report['version'] != VERSIONS[name]:
            return dict(report, error='compiler version does not match recipe requirement')
        with tempfile.TemporaryDirectory(prefix='fnv_native_doctor_') as temporary:
            work = Path(temporary)
            source, obj, exe = [work / x for x in ['probe.cpp', 'probe.obj', 'probe.exe']]
            source.write_text('extern "C" int probe_entry() { return 0; }\n', encoding='ascii')
            command = [cl, '/nologo', '/c', '/GS-', source, '/Fo' + str(obj)]
            code, output = run(command, root, work, timeout=30)
            report['compile_probe'] = dict(returncode=code, output=output[-2000:])
            if code or not obj.exists():
                return dict(report, error='native compile probe failed')
            # This checks linker execution and x86 output, not CRT/game startup.
            command = [root / 'VC/bin/link.exe', '/nologo', '/machine:x86', '/subsystem:console',
                       '/nodefaultlib', '/entry:probe_entry', '/out:' + str(exe), obj]
            code, output = run(command, root, work, timeout=30)
            report['link_probe'] = dict(returncode=code, output=output[-2000:])
            if code or not exe.exists():
                return dict(report, error='native linker probe failed')
        report['ready'] = True
        return report
    except (OSError, subprocess.TimeoutExpired) as error:
        return dict(report, error=str(error))


def doctor(roots):
    return {name: inspect(name, roots.get(name)) for name in ROOT_VARS}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    add_arguments(parser)
    parser.add_argument('--out', type=Path, help='private JSON report')
    args = parser.parse_args()
    report = dict(schema_version=1, toolchains=doctor({n: getattr(args, n + '_root') for n in ROOT_VARS}))
    rendered = json.dumps(report, indent=2) + '\n'
    if args.out:
        args.out.parent.mkdir(parents=True, exist_ok=True)
        args.out.write_text(rendered, encoding='utf-8')
    print(rendered, end='')
    return 0 if all(x['ready'] for x in report['toolchains'].values()) else 1


if __name__ == '__main__':
    raise SystemExit(main())
