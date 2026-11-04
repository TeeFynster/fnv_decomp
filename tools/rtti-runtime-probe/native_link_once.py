"""One reviewed normal SP1 link of three synthetic RTTI runtime objects."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time
import re
import sys
sys.path.insert(0, str(Path(__file__).resolve().parents[2] / "tools/rebuild"))
from coff_inventory import Coff

ROOT = Path(__file__).resolve().parents[2]
COMPILE = ROOT / 'build/rebuild/rtti-runtime-sp1-compile-v1'
DOCTOR = ROOT / 'build/rebuild/doctor-all.json'


def sha(path): return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def checked(request, review, allow_existing=False):
    if review.get('kind') != 'rtti-runtime-link-review' or review.get('approved') is not True or not review.get('reviewer') or not review.get('cpu_lease') or review.get('request_sha256') != sha(request):
        raise ValueError('exact link review absent')
    d = json.loads(Path(request).read_text())
    if d.get('kind') != 'synthetic-rtti-runtime-link-only' or d.get('driver_sha256') != sha(__file__): raise ValueError('driver identity differs')
    if d['compile_receipt'] != str(COMPILE / 'receipt.json') or d['compile_sha256'] != sha(COMPILE / 'receipt.json'): raise ValueError('compile receipt differs')
    compile_review = ROOT / 'build/rebuild/rtti-runtime-sp1-compile-v1-outcome-review.json'
    if d['compile_review_sha256'] != sha(compile_review): raise ValueError('compile review differs')
    verified = json.loads(compile_review.read_text())
    if verified.get('approved') is not True or verified.get('compile_receipt_sha256') != d['compile_sha256']: raise ValueError('compile review not approved')
    compile_request = ROOT / 'build/rebuild/rtti-runtime-sp1-compile-v1-request.json'
    compiled = json.loads((COMPILE / 'receipt.json').read_text())
    if sha(compile_request) != compiled['request_sha256']: raise ValueError('compile request differs')
    original = json.loads(compile_request.read_text())
    if original['source_sha256'] != {name: sha(ROOT / name) for name in original['source_sha256']}: raise ValueError('compiled sources differ')
    if compiled['status'] != 'complete' or len(compiled['results']) != 3 or any(x['returncode'] != 0 or not x['object_sha256'] for x in compiled['results']): raise ValueError('compile not complete')
    objects = [COMPILE / (n + '.obj') for n in ('rtti_producer','rtti_consumer','rtti_probe_main')]
    parser = ROOT / 'tools/rebuild/coff_inventory.py'
    if sha(parser) != d['coff_parser_sha256']: raise ValueError('COFF parser differs')
    expected_directives = ['/DEFAULTLIB:"libcpmt"', '/DEFAULTLIB:"LIBCMT"', '/DEFAULTLIB:"OLDNAMES"']
    if any(Coff(p).directives != expected_directives for p in objects): raise ValueError('object directives differ')
    if [sha(p) for p in objects] != [x['object_sha256'] for x in compiled['results']]: raise ValueError('object identity differs')
    doctor = json.loads(DOCTOR.read_text())['toolchains']['sp1']
    linker = Path(doctor['root']) / 'VC/bin/link.exe'; vc = Path(doctor['root']) / 'VC/lib'; sdk = Path(doctor['sdk']) / 'Lib'
    if sha(DOCTOR) != d['doctor_sha256'] or not doctor['ready'] or doctor['version'] != '15.00.30729.01' or sha(linker) != doctor['link_sha256'] or d['linker_sha256'] != sha(linker): raise ValueError('linker or doctor differs')
    inputs = [linker.parent / 'mspdb80.dll']
    for folder in (vc, sdk):
        for p in folder.iterdir():
            if p.suffix.lower() == '.lib':
                if p.is_symlink() or getattr(os.lstat(p), 'st_file_attributes', 0) & 0x400: raise ValueError('linked library input')
                if not p.is_file(): raise ValueError('non-file library input')
                inputs.append(p)
    if d['support'] != {str(p):sha(p) for p in inputs}: raise ValueError('link dependencies differ')
    out = Path(d['output'])
    if (out.exists() and not allow_existing) or out.parent.resolve() != (ROOT/'build/rebuild').resolve(): raise ValueError('output differs')
    if d['systemroot'] != os.environ.get('SystemRoot') or d['path'] != str(linker.parent)+os.pathsep+str(Path(d['systemroot'])/'System32'): raise ValueError('environment differs')
    argv = [str(linker),'/NOLOGO','/VERBOSE:LIB','/MAP:'+str(out/'rtti_probe.map'),'/MACHINE:X86','/SUBSYSTEM:CONSOLE','/INCREMENTAL:NO','/MANIFEST:NO', '/OUT:'+str(out/'rtti_probe.exe'),'/LIBPATH:'+str(vc),'/LIBPATH:'+str(sdk),*[str(p) for p in objects]]
    if d['argv'] != argv or d['cwd'] != str(out): raise ValueError('link command differs')
    return d


def run(request, review_path):
    review = json.loads(Path(review_path).read_text());d=checked(request,review)
    lease=ROOT/'build/rebuild/application-frontier-dispatch-v1/resource-leases.json'
    def lease_active():
        return any(x.get('owner')=='/root/rebuild_game_environment' and x.get('resource')=='CPU_heavy' and x.get('state') in ('reserved-awaiting-process-identity','active') and x.get('slot')==review['cpu_lease'] and x.get('review_sha256')==sha(review_path) for x in json.loads(lease.read_text())['leases'])
    if not lease_active(): raise ValueError('review-bound CPU lease absent')
    out=Path(d['output']);out.mkdir();request_hash=sha(request);review_hash=sha(review_path);driver_hash=sha(__file__)
    def stable():
        if not lease_active() or sha(request)!=request_hash or sha(review_path)!=review_hash or sha(__file__)!=driver_hash or checked(request,json.loads(Path(review_path).read_text()),True)!=d: raise ValueError('reviewed input changed')
    journal=out/'journal.jsonl'
    def log(row):
        with journal.open('a',encoding='utf-8') as f:f.write(json.dumps(row)+'\n');f.flush();os.fsync(f.fileno())
    stable();log(dict(state='starting'));env={'PATH':d['path'],'TMP':str(out),'TEMP':str(out),'SystemRoot':d['systemroot']}
    with (out/'stdout').open('xb') as so,(out/'stderr').open('xb') as se:
        child=subprocess.Popen(d['argv'],cwd=out,env=env,stdin=subprocess.DEVNULL,stdout=so,stderr=se,creationflags=getattr(subprocess,'CREATE_NO_WINDOW',0))
        try:
            log(dict(state='started',pid=child.pid));deadline=time.monotonic()+120;reason=None
            while child.poll() is None:
                if time.monotonic()>=deadline:reason='timeout'
                elif os.fstat(so.fileno()).st_size>=65536 or os.fstat(se.fileno()).st_size>=16384:reason='output_limit'
                if reason:child.kill();child.wait();break
                time.sleep(.05)
            code=child.wait()
            if os.fstat(so.fileno()).st_size>=65536 or os.fstat(se.fileno()).st_size>=16384:reason='output_limit'
        finally:
            if child.poll() is None:child.kill()
            child.wait()
    exe=out/'rtti_probe.exe';status='complete' if code==0 and reason is None and exe.is_file() else 'failed'
    # Native verbose library records are reviewed after this operation. Unknown
    # or absent provenance blocks execution; it is not an automatic success.
    text = (out/'stdout').read_text(errors='replace')
    searches = re.findall(r'^\s*Searching\s+(.+?\.lib)\s*:', text, re.I | re.M)
    loaded = re.findall(r'^\s*Loaded\s+(.+?\.lib)\(', text, re.I | re.M)
    allowed = {str(Path(p).resolve()).lower() for p in d['support'] if p.lower().endswith('.lib')}
    absolute = all(Path(p).is_absolute() for p in searches + loaded)
    searched = {str(Path(p).resolve()).lower() for p in searches}
    loaded_paths = {str(Path(p).resolve()).lower() for p in loaded}
    required = {'libcmt.lib','libcpmt.lib','kernel32.lib'}
    search_verified = bool(searches) and absolute and searched.issubset(allowed) and loaded_paths.issubset(allowed) and required.issubset({Path(p).name.lower() for p in searched})
    map_file = out/'rtti_probe.map'
    if status == 'complete' and (not search_verified or not map_file.is_file()): status = 'library_search_unverified'
    record=dict(pid=child.pid,returncode=code,termination=reason,stdout_sha256=sha(out/'stdout'),stderr_sha256=sha(out/'stderr'),executable_sha256=sha(exe) if exe.is_file() else None,map_sha256=sha(map_file) if map_file.is_file() else None,library_search_verified=search_verified,selected_members_observed=bool(loaded),searched_library_count=len(searches),loaded_member_count=len(loaded))
    log(dict(state='finished',**record))
    try:stable()
    except Exception:status='input_drift';log(dict(state='input_drift'))
    report=dict(kind='synthetic-rtti-runtime-link-outcome',status=status,request_sha256=request_hash,review_sha256=review_hash,driver_sha256=driver_hash,result=record,fixture_executed=False,game_runtime_proved=False)
    with (out/'receipt.json').open('x',encoding='utf-8') as f:json.dump(report,f,indent=2);f.write('\n')
    return report

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--request',required=True);p.add_argument('--review',required=True);a=p.parse_args();run(a.request,a.review)
