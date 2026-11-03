"""One finite supervised invocation of the frozen all-current Python producer.

No COFF, namespace, selection, compiler, native reader or game logic. Resource
thresholds are sampled abort controls, not OS-enforced quotas. No auto retry.
"""
from __future__ import annotations
import argparse
import ctypes
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import time

ROOT=Path(__file__).resolve().parents[2]
PRODUCER='tools/rebuild/bulk_code_pool.py'
PRODUCER_SHA256='4e6d697c1881c56c4c3f6a84788df6e0e2617b284d8e0226805828829bce49ed'
CHILD_SOURCES=(PRODUCER,'tests/rebuild/test_bulk_code_pool.py','docs/rebuild/BULK-CODE-POOL.md','runtime/code-pools/recipe-0000-pilot.json')
OWNED=('tools/rebuild/bulk_code_supervisor.py','tests/rebuild/test_bulk_code_supervisor.py','docs/rebuild/BULK-CODE-SUPERVISOR.md')
INPUTS=('selection','manifest','retained','recipes','binding','owners','eh','inventory','inventory_details',
        'historical_writer','binding_details','owner_details','reference')
LIMITS=dict(wall_seconds=1800,poll_seconds=2,working_set_bytes=1536*1024**2,private_bytes=2*1024**3,
            spool_bytes=128*1024**2,output_bytes=512*1024**2,free_start_bytes=2*1024**3,free_floor_bytes=1024**3,log_bytes=16*1024**2)


def require(ok,message):
    if not ok:raise ValueError(message)


def sha(path):
    h=hashlib.sha256()
    with Path(path).open('rb') as f:
        for part in iter(lambda:f.read(1048576),b''):h.update(part)
    return h.hexdigest()


def canonical(value):return json.dumps(value,sort_keys=True,separators=(',',':')).encode()


def save(path,value):
    with Path(path).open('xb') as f:f.write((json.dumps(value,indent=2)+'\n').encode());f.flush();os.fsync(f.fileno())


def pin(path,expected,observed):
    path=Path(path).resolve();require(sha(path)==expected,'input/source fingerprint differs: '+path.name);observed[str(path)]=expected


def preflight(paths,review_path,review_sha256,run_dir,observed=None):
    require(set(paths)==set(INPUTS),'exact producer argument set required')
    if observed is None:observed={}
    pin(review_path,review_sha256,observed);r=json.loads(Path(review_path).read_text())
    require(r.get('phase')=='bulk-code-pool-all-current-emission' and r.get('mode')=='all-current' and
            all(r.get(k) is True for k in ('approved','independent_source_schema_review_pass','root_authorized','supervisor_source_review_pass')),
            'all-current producer/supervisor review and root go required')
    require(not r.get('reference_certificates'),'no reference certificates allowed')
    require(r.get('supervision_limits')==LIMITS,'exact reviewed resource limits required')
    require(set(r.get('source_sha256',{}))==set(CHILD_SOURCES) and set(r.get('supervisor_source_sha256',{}))==set(OWNED),'complete reviewed source sets required')
    require(r['source_sha256'][PRODUCER]==PRODUCER_SHA256,'frozen producer pin differs')
    for name,h in {**r['source_sha256'],**r['supervisor_source_sha256']}.items():pin(ROOT/name,h,observed)
    pin(sys.executable,r['python_executable_sha256'],observed)
    for p in [Path(review_path),*[Path(v) for v in paths.values()]]:
        require(not p.resolve().is_relative_to(run_dir),'input inside new run directory')
    command=[sys.executable,'-E','-s','-B',str((ROOT/PRODUCER).resolve())]
    for name in INPUTS:command.extend(['--'+name.replace('_','-'),str(Path(paths[name]).resolve())])
    command.extend(['--mode','all-current','--review',str(Path(review_path).resolve()),'--review-sha256',review_sha256,'--output-dir',str(run_dir/'production')])
    return r,observed,command


def windows_memory(process):
    """Only the owned Popen handle; no system process enumeration or PID lookup."""
    require(os.name=='nt','Windows memory adapter required')
    from ctypes import wintypes
    class Counters(ctypes.Structure):
        _fields_=[('cb',wintypes.DWORD),('faults',wintypes.DWORD)]+[(n,ctypes.c_size_t) for n in
            ('peak_working','working','peak_paged','paged','peak_nonpaged','nonpaged','pagefile','peak_pagefile','private')]
    c=Counters();c.cb=ctypes.sizeof(c)
    function=ctypes.WinDLL('psapi',use_last_error=True).GetProcessMemoryInfo
    function.argtypes=(wintypes.HANDLE,ctypes.c_void_p,wintypes.DWORD);function.restype=wintypes.BOOL
    require(function(wintypes.HANDLE(int(process._handle)),ctypes.byref(c),c.cb),'owned-process memory query failed')
    return dict(working=int(c.working),private=int(c.private),peak_working=int(c.peak_working))


def regular_size(path,root):
    path=Path(path)
    require(path.resolve().is_relative_to(root.resolve()),'output path escapes owned run')
    if not path.exists():return 0
    stat=path.stat(follow_symlinks=False)
    require(not path.is_symlink() and not getattr(stat,'st_file_attributes',0)&0x400 and path.is_file(),'nonregular/reparse output path')
    return stat.st_size


def output_usage(run_dir):
    """Shallow walk of this one new child directory plus exact snapshot paths."""
    run_dir=Path(run_dir);child=run_dir/'production';total=0
    for name in ('supervisor-progress.jsonl','child-output.log','stop.request','supervisor-receipt.json'):
        total+=regular_size(run_dir/name,run_dir)
    if child.exists():
        require(child.resolve()==child.absolute() and not child.is_symlink() and
                not getattr(child.stat(follow_symlinks=False),'st_file_attributes',0)&0x400,'child directory reparse')
        count=0
        with os.scandir(child) as entries:
            for entry in entries:
                count+=1;require(count<=4096,'owned output entry budget')
                if entry.name=='source-snapshots':continue
                total+=regular_size(Path(entry.path),run_dir)
    for name in CHILD_SOURCES:total+=regular_size(child/'source-snapshots'/name,run_dir)
    for name in OWNED:total+=regular_size(run_dir/'supervisor-snapshots'/name,run_dir)
    return dict(total=total,spool=regular_size(child/'members.spool',run_dir),log=regular_size(run_dir/'child-output.log',run_dir))


def monitor(process,run_dir,note,*,clock=time.monotonic,sleep=time.sleep,memory=windows_memory,usage=output_usage,free=None):
    free=free or (lambda path:shutil.disk_usage(path).free)
    start=clock();samples=0;peak=dict(working=0,private=0,output=0,spool=0,log=0);minimum_free=None
    while True:
        code=process.poll();elapsed=clock()-start
        mem=memory(process) if code is None else dict(working=0,private=0,peak_working=0)
        require(all(type(mem[k]) is int and mem[k]>=0 for k in ('working','private','peak_working')),'invalid memory sample')
        sizes=usage(run_dir);available=free(run_dir)
        require(type(available) is int and available>=0 and all(type(sizes[k]) is int and sizes[k]>=0 for k in ('total','spool','log')),'invalid disk sample')
        peak['working']=max(peak['working'],mem['working'],mem['peak_working']);peak['private']=max(peak['private'],mem['private'])
        for key,source in [('output','total'),('spool','spool'),('log','log')]:peak[key]=max(peak[key],sizes[source])
        minimum_free=available if minimum_free is None else min(minimum_free,available);samples+=1
        sample=dict(state='sample',elapsed_seconds=round(elapsed,3),returncode=code,memory=mem,bytes=sizes,free_bytes=available)
        note(sample)
        reason=('operator-stop' if (run_dir/'stop.request').exists() else
                'wall-threshold' if elapsed>=LIMITS['wall_seconds'] else
                'working-set-threshold' if peak['working']>LIMITS['working_set_bytes'] else
                'private-memory-threshold' if peak['private']>LIMITS['private_bytes'] else
                'spool-threshold' if sizes['spool']>LIMITS['spool_bytes'] else
                'output-threshold' if sizes['total']>LIMITS['output_bytes'] else
                'log-threshold' if sizes['log']>LIMITS['log_bytes'] else
                'free-space-threshold' if available<LIMITS['free_floor_bytes'] else None)
        result=dict(reason=reason,returncode=code,elapsed_seconds=elapsed,samples=samples,peak=peak,minimum_free_bytes=minimum_free)
        if reason or code is not None:return result
        sleep(min(LIMITS['poll_seconds'],max(0,LIMITS['wall_seconds']-elapsed)))


def stop_owned(process):
    if process.poll() is None:process.kill()
    return process.wait(timeout=10)


def safe_output_hash(path,root,maximum):
    try:
        if Path(path).exists() and regular_size(path,root)<=maximum:return sha(path)
    except (OSError,ValueError):pass
    return None


def bind_child_receipt(run_dir,review_path,review_sha256):
    child=run_dir/'production';path=child/'receipt.json';require(path.exists() and regular_size(path,run_dir)<=32*1024**2,'missing/oversized child receipt')
    value=json.loads(path.read_text());require(value.get('kind')=='private-bulk-unresolved-code-pool' and value.get('mode')=='all-current' and
        value.get('status') in ('complete','incomplete') and value.get('inputs_stable') is True,'invalid child terminal scope')
    require(value['inputs'].get(str(Path(review_path).resolve()))==review_sha256,'child phase receipt differs')
    artifacts={}
    for name,key in [('members.spool','spool_sha256'),('members.jsonl','member_ledger_sha256'),('coverage.jsonl.gz','coverage_sha256'),('unions.jsonl.gz','unions_sha256')]:
        require(regular_size(child/name,run_dir)>=0 and sha(child/name)==value[key],'child artifact hash differs');artifacts[name]=value[key]
    require(len(value['shards'])<=1429,'child shard budget')
    for shard in value['shards']:
        name=shard['name'];require(re.fullmatch(r'code-pool-\d{4}\.lib',name) and name not in artifacts,'child shard path/duplicate')
        require(regular_size(child/name,run_dir)>=0 and sha(child/name)==shard['sha256'],'child shard hash differs');artifacts[name]=shard['sha256']
    return dict(path=str(path),sha256=sha(path),status=value['status'],requested=value['requested'],emitted=value['emitted'],artifacts=artifacts)


def run(paths,review_path,review_sha256,run_dir,*,popen=subprocess.Popen,clock=time.monotonic,sleep=time.sleep,memory=windows_memory,usage=output_usage,free=None):
    """One attempt. Existing directories reject without touching their files."""
    run_dir=Path(run_dir).resolve();private=(ROOT/'build/rebuild').resolve()
    require(run_dir.is_relative_to(private) and run_dir!=private and not run_dir.exists(),'new exclusive private supervisor directory required')
    run_dir.mkdir();progress=(run_dir/'supervisor-progress.jsonl').open('x',encoding='utf-8');process=None;child_log=None
    observed={};command=None;monitor_result=None;child_result=None;reason=None;error=None;returncode=None
    free=free or (lambda path:shutil.disk_usage(path).free)
    def note(row):progress.write(canonical(row).decode()+'\n');progress.flush();os.fsync(progress.fileno())
    note(dict(state='preflight',review_sha256=review_sha256,limits=LIMITS))
    try:
        review,observed,command=preflight(paths,review_path,review_sha256,run_dir,observed)
        require(free(run_dir)>=LIMITS['free_start_bytes'],'insufficient initial free space')
        require(not (run_dir/'stop.request').exists(),'operator stop before launch')
        for relative,h in review['supervisor_source_sha256'].items():
            data=(ROOT/relative).read_bytes();require(hashlib.sha256(data).hexdigest()==h,'supervisor source changed before snapshot')
            snapshot=run_dir/'supervisor-snapshots'/relative;snapshot.parent.mkdir(parents=True,exist_ok=True)
            with snapshot.open('xb') as f:f.write(data);f.flush();os.fsync(f.fileno())
        child_log=(run_dir/'child-output.log').open('xb')
        process=popen(command,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=child_log,stderr=subprocess.STDOUT,creationflags=getattr(subprocess,'CREATE_NO_WINDOW',0))
        note(dict(state='child-started',pid=process.pid,command=command,command_sha256=hashlib.sha256(canonical(command)).hexdigest(),inputs=observed))
        monitor_result=monitor(process,run_dir,note,clock=clock,sleep=sleep,memory=memory,usage=usage,free=free)
        reason=monitor_result['reason']
        if reason:returncode=stop_owned(process)
        else:returncode=process.wait(timeout=10)
        child_log.close();child_log=None
        if not reason:
            require(returncode==0,'child returned nonzero')
            child_result=bind_child_receipt(run_dir,review_path,review_sha256)
            # Final sampled disk check includes closed logs and completed child files.
            sizes=usage(run_dir);require(sizes['total']<=LIMITS['output_bytes'] and sizes['spool']<=LIMITS['spool_bytes'] and sizes['log']<=LIMITS['log_bytes'],'post-exit output budget')
    except BaseException as e:
        reason=reason or 'supervision-error';error=dict(type=type(e).__name__,message=str(e))
        if process is not None:
            try:returncode=stop_owned(process)
            except BaseException as stop_error:error['stop_error']=dict(type=type(stop_error).__name__,message=str(stop_error))
    finally:
        if child_log is not None:child_log.close()
        try:stable=all(Path(p).exists() and sha(p)==h for p,h in observed.items())
        except OSError:stable=False
        if not stable:reason=reason or 'source-or-review-changed'
        child_receipt=run_dir/'production/receipt.json'
        candidate_hash=safe_output_hash(child_receipt,run_dir,32*1024**2)
        status='aborted' if reason else 'completed' if child_result and child_result['status']=='complete' else 'completed-incomplete'
        report=dict(schema_version=1,kind='finite-bulk-code-pool-supervision',status=status,abort_reason=reason,error=error,
            limits=LIMITS,thresholds_are_sampled=True,hard_OS_memory_or_disk_quota=False,command=command,returncode=returncode,
            owned_pid=None if process is None else process.pid,monitor=monitor_result,inputs=observed,inputs_stable=stable,
            review_path=str(Path(review_path).resolve()),review_expected_sha256=review_sha256,
            requested_input_paths={n:str(Path(p).resolve()) for n,p in paths.items()},
            child_receipt=child_result if not reason else None,unaccepted_child_receipt_sha256=candidate_hash if reason else None,
            child_output_log_sha256=safe_output_hash(run_dir/'child-output.log',run_dir,LIMITS['log_bytes']),
            retry_performed=False,child_python_producer_launched=process is not None,supervisor_namespace_or_selection_performed=False,compiler_performed=False,native_reader_performed=False,
            executable_link_performed=False,game_execution_performed=False,provider_selected=False,runtime_eligible=False,link_ready=False)
        save(run_dir/'supervisor-receipt.json',report);note(dict(state=status,abort_reason=reason,receipt_sha256=sha(run_dir/'supervisor-receipt.json')));progress.close()
    return report


def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in INPUTS:p.add_argument('--'+name.replace('_','-'),required=True,type=Path)
    p.add_argument('--review',required=True,type=Path);p.add_argument('--review-sha256',required=True);p.add_argument('--run-dir',required=True,type=Path)
    a=p.parse_args();result=run({n:getattr(a,n) for n in INPUTS},a.review,a.review_sha256,a.run_dir)
    print(json.dumps(dict(status=result['status'],abort_reason=result['abort_reason'],child_receipt=result['child_receipt'])))
    return 1 if result['status']=='aborted' else 0


if __name__=='__main__':raise SystemExit(main())
