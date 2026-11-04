"""One reviewed execution of a hash-bound synthetic RTTI fixture program."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import time

ROOT=Path(__file__).resolve().parents[2]
LINK=ROOT/'build/rebuild/rtti-runtime-sp1-link-v1'
META=ROOT/'tools/rtti-abi/fixture/fixture-metadata.json'
CHECKER=ROOT/'tools/rtti-runtime-probe/rtti_probe_check.py'


def sha(path): return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def checked(request,review,allow_existing=False):
    if review.get('kind')!='rtti-runtime-execution-review' or review.get('approved') is not True or not review.get('reviewer') or not review.get('cpu_lease') or review.get('request_sha256')!=sha(request):raise ValueError('exact run review absent')
    d=json.loads(Path(request).read_text());cycles=d.get('cycles')
    if d.get('kind')!='synthetic-rtti-runtime-execution' or cycles not in (1,3) or d.get('driver_sha256')!=sha(__file__):raise ValueError('request or driver differs')
    link_receipt=LINK/'receipt.json';link_review=ROOT/'build/rebuild/rtti-runtime-sp1-link-v1-outcome-review.json'
    if d['link_receipt_sha256']!=sha(link_receipt) or d['link_review_sha256']!=sha(link_review):raise ValueError('link evidence differs')
    lr=json.loads(link_receipt.read_text());peer=json.loads(link_review.read_text())
    if lr['status']!='complete' or not lr['result']['library_search_verified'] or peer.get('approved') is not True or peer.get('link_receipt_sha256')!=sha(link_receipt) or peer.get('selected_provider_evidence') is not True or peer.get('executable_synthetic_x86_evidence') is not True:raise ValueError('link not independently accepted')
    if sha(LINK/'rtti_probe.map') != lr['result']['map_sha256'] or peer.get('map_sha256') != lr['result']['map_sha256']: raise ValueError('map evidence differs')
    exe=LINK/'rtti_probe.exe'
    if sha(exe)!=lr['result']['executable_sha256'] or d['executable_sha256']!=sha(exe):raise ValueError('fixture executable differs')
    if d['checker_sha256']!=sha(CHECKER) or d['metadata_sha256']!=sha(META):raise ValueError('checker or metadata differs')
    out=Path(d['output']);expected=ROOT/('build/rebuild/rtti-runtime-sp1-run-%d-v1'%cycles)
    if out!=expected or (out.exists() and not allow_existing):raise ValueError('output differs')
    if d['systemroot']!=os.environ.get('SystemRoot') or d['argv']!=[str(exe),'--cycles',str(cycles)] or d['cwd']!=str(out):raise ValueError('command or environment differs')
    return d


def run(request,review_path):
    review=json.loads(Path(review_path).read_text());d=checked(request,review);lease=ROOT/'build/rebuild/application-frontier-dispatch-v1/resource-leases.json'
    def lease_active():
        return any(x.get('owner')=='/root/rebuild_game_environment' and x.get('resource')=='CPU_heavy' and x.get('state') in ('reserved-awaiting-process-identity','active') and x.get('slot')==review['cpu_lease'] and x.get('review_sha256')==sha(review_path) for x in json.loads(lease.read_text())['leases'])
    if not lease_active():raise ValueError('review-bound CPU lease absent')
    out=Path(d['output']);out.mkdir();request_hash=sha(request);review_hash=sha(review_path);driver_hash=sha(__file__)
    def stable():
        if not lease_active() or sha(request)!=request_hash or sha(review_path)!=review_hash or sha(__file__)!=driver_hash or checked(request,json.loads(Path(review_path).read_text()),True)!=d:raise ValueError('reviewed input changed')
    journal=out/'journal.jsonl'
    def log(row):
        with journal.open('a',encoding='utf-8') as f:f.write(json.dumps(row)+'\n');f.flush();os.fsync(f.fileno())
    stable();log(dict(state='starting'))
    with (out/'stdout.json').open('xb') as so,(out/'stderr.txt').open('xb') as se:
        child=subprocess.Popen(d['argv'],cwd=out,env={'SystemRoot':d['systemroot']},stdin=subprocess.DEVNULL,stdout=so,stderr=se,creationflags=getattr(subprocess,'CREATE_NO_WINDOW',0))
        try:
            log(dict(state='started',pid=child.pid));deadline=time.monotonic()+30;reason=None
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
    result=dict(pid=child.pid,returncode=code,termination=reason,stdout_sha256=sha(out/'stdout.json'),stderr_sha256=sha(out/'stderr.txt'))
    log(dict(state='finished',**result));status='failed';check=None
    if reason is None and (out/'stderr.txt').stat().st_size==0:
        try:
            spec=importlib.util.spec_from_file_location('rtti_probe_check',CHECKER);module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
            doc=module.parse_json_bytes((out/'stdout.json').read_bytes());meta=module.parse_json_bytes(META.read_bytes(),module.MAX_METADATA_BYTES)
            check=module.check_report(doc,meta)
            if code==doc['driver_exit_code'] and code==0 and doc['cycles_requested']==d['cycles'] and check['verdict']=='PASS':status='complete'
        except Exception as exc:
            check=dict(verdict='INVALID',error_type=type(exc).__name__)
    try:stable()
    except Exception:status='input_drift';log(dict(state='input_drift'))
    report=dict(kind='synthetic-rtti-runtime-execution-outcome',status=status,request_sha256=request_hash,review_sha256=review_hash,driver_sha256=driver_hash,result=result,checker=check,game_runtime_proved=False)
    with (out/'receipt.json').open('x',encoding='utf-8') as f:json.dump(report,f,indent=2);f.write('\n')
    return report

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--request',required=True);p.add_argument('--review',required=True);a=p.parse_args();run(a.request,a.review)
