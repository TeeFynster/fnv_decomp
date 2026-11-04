"""One reviewed, compile-only pass over two synthetic RTTI fixture units."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import stat
import time

ROOT = Path(__file__).resolve().parents[2]
SOURCES = ('tools/rtti-abi/fixture/rtti_abi_fixture.h', 'tools/rtti-abi/fixture/rtti_producer.cpp',
           'tools/rtti-abi/fixture/rtti_consumer.cpp')
FLAGS = ('/nologo', '/c', '/TP', '/X', '/GR', '/EHsc', '/W4', '/Od', '/MT')


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def include_digest(path):
    root = Path(path)
    records = []
    root_stat = os.lstat(root)
    if stat.S_ISLNK(root_stat.st_mode) or getattr(root_stat, 'st_file_attributes', 0) & 0x400:
        raise ValueError('linked include root')
    def walk_error(error):
        raise error
    for directory, dirs, files in os.walk(root, followlinks=False, onerror=walk_error):
        for name in sorted(dirs + files):
            p = Path(directory) / name
            st = os.lstat(p)
            if stat.S_ISLNK(st.st_mode) or getattr(st, 'st_file_attributes', 0) & 0x400:
                raise ValueError('linked include input')
            if stat.S_ISREG(st.st_mode):
                records.append((p.relative_to(root).as_posix(), sha(p)))
    records.sort()
    return hashlib.sha256(json.dumps(records, separators=(',', ':')).encode()).hexdigest()


def checked(request, review, allow_existing=False):
    if review.get('kind') != 'rtti-compile-review' or review.get('approved') is not True or not review.get('reviewer') or not review.get('cpu_lease'):
        raise ValueError('independent review absent')
    if review.get('request_sha256') != sha(request):
        raise ValueError('request review differs')
    data = json.loads(Path(request).read_text())
    if data.get('kind') != 'synthetic-rtti-two-tu-compile-only' or data.get('driver_sha256') != sha(__file__):
        raise ValueError('request or driver identity differs')
    if data.get('source_sha256') != {p: sha(ROOT / p) for p in SOURCES}:
        raise ValueError('source identities differ')
    doctor = Path(data['doctor']); d = json.loads(doctor.read_text())['toolchains']['sp1']
    if sha(doctor) != data['doctor_sha256'] or not d['ready'] or d['version'] != '15.00.30729.01':
        raise ValueError('doctor identity differs')
    compiler = Path(d['root']) / 'VC/bin/cl.exe'; include = Path(d['root']) / 'VC/include'
    if str(compiler) != data['compiler'] or str(include) != data['include'] or sha(compiler) != d['cl_sha256'] or sha(compiler) != data['compiler_sha256'] or include_digest(include) != data['include_sha256']:
        raise ValueError('compiler or include identity differs')
    for path, digest in data['compiler_support'].items():
        if sha(path) != digest: raise ValueError('compiler support identity differs')
    if set(Path(p).resolve() for p in data['compiler_support']) != {(compiler.parent / n).resolve() for n in ('c1xx.dll', 'c2.dll', 'mspdb80.dll')}:
        raise ValueError('compiler support identities incomplete')
    out = Path(data['output'])
    if (out.exists() and not allow_existing) or not out.parent.is_dir() or out.parent.resolve() != (ROOT / 'build/rebuild').resolve():
        raise ValueError('output is not a new private directory')
    if data['path'] != str(compiler.parent) + os.pathsep + str(Path(data['systemroot']) / 'System32'):
        raise ValueError('compiler search path differs')
    if data['systemroot'] != os.environ.get('SystemRoot'):
        raise ValueError('system root differs')
    expected = [[str(compiler), '/nologo', '/c', '/TP', '/X', '/I'+str(include), *FLAGS[4:],
                 '/Fo'+str(out / (name+'.obj')), str(ROOT / SOURCES[index])]
                for name,index in (('rtti_producer',1),('rtti_consumer',2))]
    if data['argv'] != expected or data['cwd'] != str(ROOT):
        raise ValueError('argument vector or working directory differs')
    return data


def run(request, review_path):
    review = json.loads(Path(review_path).read_text())
    d = checked(request, review)
    lease_file = ROOT / 'build/rebuild/application-frontier-dispatch-v1/resource-leases.json'
    def lease_active():
        records = json.loads(lease_file.read_text())['leases']
        return any(x.get('owner') == '/root/rebuild_game_environment' and x.get('resource') == 'CPU_heavy'
                   and x.get('state') in ('reserved-awaiting-process-identity', 'active') and x.get('slot') == review['cpu_lease']
                   and x.get('review_sha256') == sha(review_path) for x in records)
    if not lease_active(): raise ValueError('review-bound CPU lease absent')
    out = Path(d['output']); out.mkdir()
    journal = out / 'journal.jsonl'
    def log(row):
        with journal.open('a', encoding='utf-8') as f:
            f.write(json.dumps(row)+'\n'); f.flush(); os.fsync(f.fileno())
    env = {'PATH': d['path'], 'TMP': str(out), 'TEMP': str(out), 'SystemRoot': d['systemroot']}
    results = []
    request_hash, review_hash, driver_hash = sha(request), sha(review_path), sha(__file__)
    def stable():
        if (not lease_active() or sha(request) != request_hash or sha(review_path) != review_hash or sha(__file__) != driver_hash
                or checked(request, json.loads(Path(review_path).read_text()), allow_existing=True) != d):
            raise ValueError('reviewed input changed')
    status = 'complete'
    for index, argv in enumerate(d['argv']):
        stable()
        log({'step': index, 'state': 'starting'})
        stdout = out / ('step%d.stdout' % index); stderr = out / ('step%d.stderr' % index)
        with stdout.open('xb') as so, stderr.open('xb') as se:
            child = subprocess.Popen(argv, cwd=ROOT, env=env, stdin=subprocess.DEVNULL,
                                     stdout=so, stderr=se,
                                     creationflags=getattr(subprocess, 'CREATE_NO_WINDOW', 0))
            try:
                log({'step': index, 'state': 'started', 'pid': child.pid})
                deadline = time.monotonic() + 60
                reason = None
                while child.poll() is None:
                    if time.monotonic() >= deadline:
                        reason = 'timeout'
                    elif os.fstat(so.fileno()).st_size + os.fstat(se.fileno()).st_size > 1024 * 1024:
                        reason = 'output_limit'
                    if reason:
                        child.kill(); child.wait(); break
                    time.sleep(0.05)
                code = child.wait()
                if os.fstat(so.fileno()).st_size + os.fstat(se.fileno()).st_size > 1024 * 1024:
                    reason = 'output_limit'
            finally:
                if child.poll() is None:
                    child.kill()
                child.wait()
        obj = out / (('rtti_producer','rtti_consumer')[index]+'.obj')
        record = dict(step=index, pid=child.pid, returncode=code, termination=reason,
                      stdout_sha256=sha(stdout), stderr_sha256=sha(stderr),
                      object_sha256=sha(obj) if obj.is_file() else None)
        results.append(record); log(dict(record, state='finished'))
        try:
            stable()
        except Exception:
            status = 'input_drift'; log({'step': index, 'state': status}); break
        if reason or code != 0 or record['object_sha256'] is None:
            status = 'failed'; break
    report = dict(kind='synthetic-rtti-compile-outcome', status=status, request_sha256=request_hash,
                  review_sha256=review_hash, driver_sha256=driver_hash, results=results,
                  link_performed=False, fixture_executed=False, game_runtime_proved=False)
    with (out / 'receipt.json').open('x', encoding='utf-8') as f: json.dump(report, f, indent=2); f.write('\n')
    return report


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--request', required=True)
    parser.add_argument('--review', required=True)
    args = parser.parse_args()
    run(args.request, args.review)
