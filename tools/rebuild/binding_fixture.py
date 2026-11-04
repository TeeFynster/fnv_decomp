"""Prepare/review/execute an original per-unit COFF binding fixture only."""
from __future__ import annotations
import argparse
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import toolchain
import coff_bind
from data_fixture import map_rows, mapped, save, require
from coff_rewrite import strict_object

ROOT = Path(__file__).resolve().parents[2]
NAMES = ['binding_caller_a', 'binding_caller_b', 'binding_provider_a', 'binding_provider_b', 'binding_main']
SOURCES = [ROOT/'runtime/probes'/n for n in ['binding_fixture.hpp']+[n+'.cpp' for n in NAMES]]
TOOLS = [Path(__file__), ROOT/'tools/rebuild/coff_bind.py', ROOT/'tools/rebuild/coff_rewrite.py', ROOT/'tools/rebuild/coff_inventory.py', ROOT/'tools/rebuild/toolchain.py', ROOT/'tools/rebuild/data_fixture.py']
POLICY = 'original-binding-fixture-v1'
COMPILE = ['/nologo', '/c', '/MT', '/Od', '/GS', '/W4']
LINK = ['/nologo', '/machine:x86', '/subsystem:console', '/opt:noref', '/opt:noicf', '/safeseh', '/dynamicbase:no', '/fixed:no', '/incremental:no']
CHECKS = ('non_name_bytes', 'provider_identities', 'duplicate_link_failure', 'normal_crt', 'map_and_imports')
EXPECTED = dict(schema=1, calls=131, distinct_data=True, writable_isolated=True)
sha = toolchain.sha256


def prepare(doctor, out):
    doctor, out = Path(doctor).resolve(), Path(out).resolve()
    require(os.name == 'nt' and not out.exists(), 'new native output directory required')
    require(not any(os.environ.get(n) for n in ('LINK', '_LINK_', 'CL', '_CL_')), 'implicit compiler/linker options forbidden')
    tc = json.loads(doctor.read_text())['toolchains']['sp1']
    root, sdk = toolchain.layout(tc['root'])
    cl, link, dump = [root/'VC/bin'/n for n in ('cl.exe', 'link.exe', 'dumpbin.exe')]
    require(tc['ready'] and tc['version'] == toolchain.VERSIONS['sp1'] and sha(cl) == tc['cl_sha256'] and sha(link) == tc['link_sha256'], 'doctor compiler identity differs')
    trusted = [cl, link, dump, root/'VC/lib/libcmt.lib', root/'VC/lib/oldnames.lib', sdk/'Lib/kernel32.lib']
    inputs = {str(p.resolve()): sha(p) for p in SOURCES+TOOLS+trusted+[doctor]}
    require(all(out != p and out not in p.parents for p in map(Path, inputs)), 'output/input collision')
    out.mkdir(parents=True)
    commands = []
    def run(command, name, fail=False):
        entry = dict(command=[str(x) for x in command], log=name, state='started')
        commands.append(entry)
        # Append-only progress leaves evidence even if the process is interrupted.
        with (out/'progress.jsonl').open('a', encoding='utf-8') as f:
            f.write(json.dumps(entry)+'\n'); f.flush(); os.fsync(f.fileno())
        code, text = toolchain.run(command, root, out, timeout=120)
        save_log = out/name
        with save_log.open('x', encoding='utf-8') as f:
            f.write(text)
        entry.update(returncode=code, state='finished')
        with (out/'progress.jsonl').open('a', encoding='utf-8') as f:
            f.write(json.dumps(entry)+'\n'); f.flush(); os.fsync(f.fileno())
        require(code != 0 if fail else code == 0, 'unexpected command result: '+name)
        return text
    banner = run([cl], 'compiler-version.log')
    require(re.search(r'Version\s+15\.00\.30729\.01\b', banner), 'compiler version differs')
    objects = []
    for n in NAMES:
        obj = out/(n+'.obj')
        run([cl]+COMPILE+[ROOT/'runtime/probes'/(n+'.cpp'), '/Fo'+str(obj)], n+'-compile.log')
        objects.append(obj)
    failed = run([link]+LINK+['/out:'+str(out/'duplicate.exe')]+objects, 'expected-duplicate-link.log', fail=True)
    require('LNK2005' in failed and '_binding_shared' in failed and '_binding_data' in failed and 'LNK1169' in failed, 'failure does not prove both duplicate definitions')
    fixture_context = dict(policy=POLICY, fresh_compile_observed=True, compiler_version=tc['version'],
        compiler_sha256=sha(cl), objects={str(obj): dict(source=str(ROOT/'runtime/probes'/(n+'.cpp')),
            source_sha256=inputs[str((ROOT/'runtime/probes'/(n+'.cpp')).resolve())], object_sha256=sha(obj))
            for n, obj in zip(NAMES[:4], objects[:4])})
    save(out/'fresh-build-context.json', fixture_context)
    bound, bindings = [], []
    for n, obj in zip(NAMES[:4], objects[:4]):
        unit = n[-1]
        coff, _, _, _ = strict_object(obj)
        rows = []
        for old, kind in (('_binding_shared', 'function'), ('_binding_data', 'data')):
            matches = [s for s in coff.symbols.values() if s['name'] == old]
            require(len(matches) == 1, 'fixture source identity differs')
            rows.append(dict(symbol_index=matches[0]['index'], old_name=old, new_name=old+'_'+unit,
                             source_kind=kind, target_kind=kind))
        plan = dict(schema_version=1, kind='fnv-coff-bind-plan', approved=True, scope='original-fixture-only',
                    object_sha256=sha(obj), source=str(ROOT/'runtime/probes'/(n+'.cpp')),
                    source_sha256=sha(ROOT/'runtime/probes'/(n+'.cpp')), bindings=rows)
        pp, target, rp = out/(n+'-plan.json'), out/(n+'-bound.obj'), out/(n+'-receipt.json')
        save(pp, plan)
        report = coff_bind.bind_object(obj, target, rp, pp, sha(pp), fixture_context=fixture_context)
        bindings.append(report); bound.append(target)
        run([dump, '/headers', '/symbols', '/relocations', target], n+'-dump.log')
    exe, mp = out/'binding.exe', out/'binding.map'
    run([link]+LINK+['/base:0x680000', '/filealign:1024', '/out:'+str(exe), '/map:'+str(mp)]+bound+[objects[4]], 'bound-link.log')
    rows = map_rows(mp.read_text())
    providers = {}
    for unit in ('a', 'b'):
        for name in ('_binding_shared_', '_binding_data_'):
            providers[name+unit] = dict(address=mapped(rows, name+unit, 'binding_provider_'+unit+'-bound.obj'), provider='binding_provider_'+unit+'-bound.obj')
    require(len({r['address'] for r in providers.values()}) == 4, 'provider identities collide')
    for unit in ('a', 'b'):
        for name in ('_binding_call_', '_binding_address_'):
            mapped(rows, name+unit, 'binding_caller_'+unit+'-bound.obj')
    require(not rows.get('_binding_shared') and not rows.get('_binding_data'), 'unbound identity remains')
    imports = run([dump, '/imports', exe], 'imports.log')
    dlls = re.findall(r'(?im)^\s*([a-zA-Z0-9_.-]+\.dll)\s*$', imports)
    require({s.lower() for s in dlls} == {'kernel32.dll'}, 'unexpected direct imports')
    crt = {}
    for name in ('_mainCRTStartup', '_printf', '_exit'):
        values = rows.get(name, [])
        require(len(values) == 1 and 'libcmt:' in values[0]['provider'].lower(), 'normal static CRT provider missing')
        crt[name] = values[0]
    sysdir = Path(os.environ['SystemRoot'])/'SysWOW64'
    osdeps = {str(sysdir/n): sha(sysdir/n) for n in ('kernel32.dll', 'KernelBase.dll', 'ntdll.dll')}
    artifacts = {str(p): sha(p) for p in out.iterdir() if p.is_file()}
    require(all(sha(p) == h for p, h in inputs.items()), 'input changed during preparation')
    report = dict(schema_version=1, kind='original-binding-fixture-prepared', policy=POLICY,
        status='prepared_pending_independent_review', execution_performed=False, inputs=inputs, artifacts=artifacts,
        os_dependencies=osdeps, commands=commands, fresh_build_context=fixture_context, bindings=bindings, providers=providers,
        exe=str(exe), exe_sha256=sha(exe), map=str(mp), map_sha256=sha(mp), crt_providers=crt, direct_imports=dlls,
        duplicate_link_failed=True, provenance='Source/object hashes and build command observations; no cryptographic compiler-causality proof.',
        game_mapping_approved=False, runtime_closure=False)
    save(out/'prepare.json', report)
    return report


def validate_review(p, r, ph):
    require(p.get('schema_version') == 1 and p.get('kind') == 'original-binding-fixture-prepared' and p.get('policy') == POLICY and p.get('execution_performed') is False and p.get('status') == 'prepared_pending_independent_review', 'unrecognized preparation')
    require(r.get('schema_version') == 1 and r.get('kind') == 'original-binding-fixture-review' and r.get('approved') is True and r.get('prepare_sha256') == ph and r.get('reviewer'), 'independent review missing or stale')
    require(r.get('exe_sha256') == p['exe_sha256'] and r.get('map_sha256') == p['map_sha256'], 'review artifacts differ')
    require(all(r.get('checks', {}).get(k) is True for k in CHECKS), 'review checks incomplete')


def execute(prepared, review, review_sha256, receipt):
    pp, rp, out = [Path(p).resolve() for p in (prepared, review, receipt)]
    require(len({pp, rp, out}) == 3 and not out.exists() and sha(rp) == review_sha256, 'new receipt and exact review required')
    ph = sha(pp)
    p, r = [json.loads(x.read_text()) for x in (pp, rp)]
    validate_review(p, r, ph)
    protected = {**p['inputs'], **p['artifacts'], **p['os_dependencies']}
    require(str(out) not in protected, 'receipt collides with protected input')
    require(p['artifacts'].get(p['exe']) == p['exe_sha256'] and p['artifacts'].get(p['map']) == p['map_sha256'], 'execution identity absent from protected artifacts')
    report = dict(schema_version=1, kind='original-binding-fixture-execution', status='error', prepare_sha256=ph, review_sha256=review_sha256, game_runtime_proven=False)
    try:
        require(sha(pp) == ph and sha(rp) == review_sha256 and all(sha(x) == h for x, h in protected.items()), 'reviewed input changed')
        proc = subprocess.run([p['exe']], cwd=pp.parent, stdin=subprocess.DEVNULL, stdout=subprocess.PIPE,
            stderr=subprocess.PIPE, text=True, errors='replace', timeout=20, creationflags=getattr(subprocess, 'CREATE_NO_WINDOW', 0))
        report.update(returncode=proc.returncode, stdout=proc.stdout, stderr=proc.stderr)
        require(proc.returncode == 0 and not proc.stderr and len(proc.stdout.splitlines()) == 1, 'fixture failed')
        observed = json.loads(proc.stdout)
        require(observed == EXPECTED and all(type(observed[k]) is type(v) for k, v in EXPECTED.items()), 'fixture assertions differ')
        report.update(status='pass', observed=observed)
    except (ValueError, OSError, subprocess.TimeoutExpired) as error:
        report['error'] = str(error)
    save(out, report)
    return report


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    sub = p.add_subparsers(dest='action', required=True)
    prep = sub.add_parser('prepare')
    prep.add_argument('--doctor', required=True); prep.add_argument('--out', required=True)
    exe = sub.add_parser('execute')
    for n in ('prepare', 'review', 'review-sha256', 'receipt'):
        exe.add_argument('--'+n, required=True)
    a = p.parse_args()
    result = prepare(a.doctor, a.out) if a.action == 'prepare' else execute(a.prepare, a.review, a.review_sha256, a.receipt)
    print(result['status'])
    sys.exit(0 if result['status'] in ('pass', 'prepared_pending_independent_review') else 1)

