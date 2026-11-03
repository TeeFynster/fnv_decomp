"""Bounded private parent-EH COFF publication; no compiler/link/native API."""
from __future__ import annotations
import argparse
import gzip
import json
import os
from pathlib import Path
import sys
import time
import parent_eh_collect as collector
import parent_eh_project as projector

ROOT=collector.ROOT
adapter=collector.adapter
require=collector.require
TOOLS=collector.TOOLS+('tools/rebuild/parent_eh_project.py','tools/rebuild/parent_eh_publish.py')


def parse_pins(values):
    pins={}
    for value in values:
        name,separator,h=value.partition('=')
        require(separator and name in TOOLS and name not in pins and len(h)==64 and all(c in '0123456789abcdef' for c in h),'INVALID_PROJECTOR_TOOL_PIN')
        pins[name]=h
    require(set(pins)==set(TOOLS),'INCOMPLETE_PROJECTOR_TOOL_PINS');return pins


def saved_arguments(request):
    argv=request['argv'];require(len(argv)>2 and Path(argv[1]).resolve()==ROOT/'tools/rebuild/parent_eh_collect.py' and (len(argv)-2)%2==0,'UNKNOWN_SAVED_COLLECTOR')
    allowed={'policy','read-scope','central','request','link-groups','lane-evidence','manifest','retained','recipes','selection','reference','out-dir','policy-sha256','read-scope-sha256','expected-tool'}
    values={};tools=[]
    for key,value in zip(argv[2::2],argv[3::2]):
        require(key.startswith('--') and key[2:] in allowed,'UNKNOWN_SAVED_ARGUMENT');key=key[2:]
        if key=='expected-tool':tools.append(value)
        else:require(key not in values,'DUPLICATE_SAVED_ARGUMENT');values[key]=value
    require(set(values)==allowed-{'expected-tool'},'INCOMPLETE_SAVED_ARGUMENTS')
    require(collector.tool_pins(tools)==request['tools_sha256'],'SAVED_TOOL_IDENTITY_DIFFERS')
    return values


def load_record(path,receipt,parent):
    require(path.stat().st_size<=8*1024**2 and collector.file_hash(path)==receipt['details_sha256'],'DETAIL_IDENTITY_OR_BOUND')
    rows=[]
    with gzip.open(path,'rb') as stream:
        for ordinal in range(receipt['roots']):
            line=stream.readline(64*1024**2+1);require(0<len(line)<=64*1024**2 and line.endswith(b'\n'),'DETAIL_RECORD_BOUND')
            row=json.loads(line);outcome=receipt['outcomes'][ordinal]
            require(adapter.digest(row)==outcome['record_sha256'] and row['root']==outcome['root'],'DETAIL_OUTCOME_JOIN')
            if row['root']['original_address']==parent:rows.append(row)
        require(stream.read(1)==b'','EXTRA_DETAIL_RECORD')
    require(len(rows)==1 and rows[0]['result']['structural_projection_candidate'] is True,'MISSING_POSITIVE_SELECTED_PARENT')
    return rows[0]


def load_envelopes(paths,expected):
    # Check every small envelope before any read/hash allocation.
    require(all(0<path.stat().st_size<=8*1024**2 for path in paths.values()),'PROJECTION_ENVELOPE_BOUND')
    return {name:collector.read_bound(path,expected[name]) for name,path in paths.items()}


def publish_outputs(directory,emitted,report,start,pins,make_result,note):
    """Exclusive late-stability publication; retain no success on failure."""
    owned=[]
    try:
        output=directory/'component.obj'
        with output.open('xb') as target:
            stat=os.fstat(target.fileno());owned.append((output,stat.st_dev,stat.st_ino));target.write(emitted);target.flush();os.fsync(target.fileno())
        require(collector.file_hash(output)==report['output_sha256'],'PUBLISHED_OUTPUT_DRIFT');collector.stable(pins);collector.check_budget(start)
        result=make_result();require(all(result[k] is False for k in adapter.FALSE),'PUBLICATION_RUNTIME_PROMOTION')
        path=directory/'projection.json'
        with path.open('x',encoding='utf-8') as target:
            stat=os.fstat(target.fileno());owned.append((path,stat.st_dev,stat.st_ino));json.dump(result,target,sort_keys=True);target.write('\n');target.flush();os.fsync(target.fileno())
        collector.stable(pins);collector.check_budget(start)
        require(sum(p.stat().st_size for p in (directory/'component.staged.obj',output,path,directory/'progress.jsonl'))<=128*1024**2,'TOTAL_PROJECTION_OUTPUT_BOUND')
        require(collector.file_hash(output)==report['output_sha256'],'LATE_OUTPUT_DRIFT')
        note(dict(state='complete',receipt_sha256=collector.file_hash(path),object_sha256=report['output_sha256']));return result
    except BaseException:
        for path,device,inode in owned:
            if path.exists():
                current=path.stat()
                if (current.st_dev,current.st_ino)==(device,inode):path.unlink()
        raise


def publish(args):
    start=time.monotonic();tool_pins=parse_pins(args.expected_tool)
    paths={name:Path(getattr(args,name)).resolve() for name in ('input_request','observation','outcome_review')}
    expected={name:getattr(args,name+'_sha256') for name in paths}
    data=load_envelopes(paths,expected)
    request,receipt,review=[data[name] for name in ('input_request','observation','outcome_review')]
    require(receipt['input_stability'] is True and receipt['optional_function_index_present'] is False and receipt['emission_performed'] is False and receipt['native_execution'] is False,'INVALID_OBSERVATION_ENVELOPE')
    require(review['kind']=='independent-expanded-parent-EH-actual-outcome-review' and review['result'].startswith('PASS ') and review['receipt_sha256']==expected['observation'] and review['details_sha256']==receipt['details_sha256'] and review['approved_request_sha256']==expected['input_request'],'INDEPENDENT_OUTCOME_IDENTITY')
    require(all(receipt[k] is False for k in adapter.FALSE),'OBSERVATION_RUNTIME_PROMOTION')
    values=saved_arguments(request);require(request['tools_sha256']==receipt['tools_sha256'] and all(tool_pins[name]==h for name,h in receipt['tools_sha256'].items()),'OBSERVER_TOOL_DRIFT')
    image=Path(values['reference']).resolve();pins={paths[name]:expected[name] for name in paths}
    for name,h in receipt['protected_inputs'].items():
        path=image if name=='private-reference' else (ROOT/name).resolve()
        require(name=='private-reference' or path.is_relative_to(ROOT),'FOREIGN_PROTECTED_INPUT')
        require(path not in pins or pins[path]==h,'CONFLICTING_INPUT_PIN');pins[path]=h
    pins.update({ROOT/name:h for name,h in tool_pins.items()})
    details=paths['observation'].parent/'observations.jsonl.gz';pins[details]=receipt['details_sha256']
    collector.stable(pins);row=load_record(details,receipt,args.parent);root=row['root'];contract=row['central_contract']
    policy_path=Path(values['policy']).resolve()
    require(policy_path in pins and pins[policy_path]==values['policy-sha256'] and 0<policy_path.stat().st_size<=8*1024**2,'PROJECTION_POLICY_NOT_BOUND')
    policy=collector.read_bound(policy_path,values['policy-sha256']);collector.validate_policy(policy)
    targets=[t for t in policy['targets'] if t['root']==root]
    require(len(targets)==1,'EXACT_PROJECTION_POLICY_TARGET')
    require(adapter.digest(contract)==row['central_contract_sha256'] and root['original_address']==args.parent,'SELECTED_CONTRACT_DRIFT')
    manifest=collector.read_bound(Path(values['manifest']),collector.EXPECTED['manifest']);proof=collector.read_bound(Path(values['retained']),collector.EXPECTED['retained']);recipes=collector.read_bound(Path(values['recipes']),collector.EXPECTED['recipes']);selection=collector.read_bound(Path(values['selection']),collector.EXPECTED['selection'])
    unit=manifest['units'][root['recipe_index']];unit_proof=proof['units'][root['recipe_index']];collector.check_unit(unit,unit_proof)
    require(unit['recipe_id']==root['recipe_id'] and unit['object_sha256']==root['object_sha256'] and unit['source_sha256']==root['source_sha256'],'SELECTED_NATIVE_SOURCE_IDENTITY')
    require(all(selection['selections'][args.parent][key]==root[key] for key in ('recipe_id','recipe_index','symbol','section','value','size')),'SELECTED_ROOT_CHANGED')
    native=(Path(values['manifest']).parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
    require(native in pins and pins[native]==root['object_sha256'] and native.stat().st_size<=64*1024**2,'NATIVE_INPUT_NOT_PROTECTED')
    require((ROOT/unit['source']).resolve() in pins and proof['inputs']['image_sha256']==pins[image] and contract['provenance']['reference_identity_sha256']==pins[image],'SOURCE_REFERENCE_NOT_PROTECTED')
    scope=collector.read_bound(Path(values['read-scope']),values['read-scope-sha256']);scopes=[r for r in scope['parents'] if r['parent']==args.parent];require(len(scopes)==1,'SELECTED_REFERENCE_SCOPE')
    directory=collector.private_directory(args.out_dir);require(not any(p.is_relative_to(directory) for p in pins),'OUTPUT_INPUT_COLLISION');directory.mkdir();published=[]
    with (directory/'progress.jsonl').open('x',encoding='utf-8') as journal:
        def note(value):journal.write(json.dumps(value,sort_keys=True)+'\n');journal.flush();os.fsync(journal.fileno())
        note(dict(state='started',parent=args.parent,observation_sha256=expected['observation']))
        try:
            raw=native.read_bytes();require(adapter.sha(raw)==root['object_sha256'],'LOADED_NATIVE_DRIFT')
            reference=adapter.oracle.Pe(image);require(adapter.sha(reference.data)==pins[image] and adapter.oracle.image_ok(reference)[0],'ORIGINAL_IMAGE_GATE')
            metadata=collector.MetadataPe(image)
            try:
                highlow=[metadata.base+site for site in metadata.relocations()];exe=[(metadata.base+s['rva'],metadata.base+s['rva']+s['extent']) for s in metadata.sections if s['executable']]
                reads=[];derived=[];scoped=collector.prepare_reference(raw,unit['recipe'],unit_proof,contract,reference,metadata,reads,derived,scopes[0]['approved_code_spans'])
                inputs=dict(raw=raw,contract=contract,recipe=unit['recipe'],unit_proof=unit_proof,recipes=recipes['units'],reference=scoped,original_highlow_sites=highlow,executable_ranges=exe)
                emitted,report=projector.project_parent(inputs,row['result'])
                require(report['export']==targets[0]['actual_link_symbol'],'CANONICAL_EXPORT_NOT_EXACT_LINK_DEMAND')
            finally:metadata.close()
            collector.check_budget(start);require(len(emitted)<=8*1024**2,'PROJECTED_OUTPUT_BOUND')
            stage=directory/'component.staged.obj'
            with stage.open('xb') as target:target.write(emitted);target.flush();os.fsync(target.fileno())
            require(collector.file_hash(stage)==report['output_sha256'],'STAGED_OUTPUT_DRIFT')
            independent=projector.IndependentCoff(stage);require(len(independent.sections)==len(report['maps']['section_map']) and len(independent.symbols)==len(report['maps']['symbol_map']),'STAGED_REPARSE_COUNTS')
            collector.stable(pins);collector.check_budget(start);note(dict(state='staged-verified',object_sha256=report['output_sha256']))
            def make_result():return collector.public_metadata(dict(schema_version=1,kind='parent-owned-no-catch-EH-projection',parent=args.parent,observation_sha256=expected['observation'],input_request_sha256=expected['input_request'],independent_outcome_review_sha256=expected['outcome_review'],projection=report,reference_reads=reads,derived_data_spans=derived,protected_inputs={p.relative_to(ROOT).as_posix() if p.is_relative_to(ROOT) else 'private-reference':h for p,h in pins.items()},tools_sha256=tool_pins,input_stability=True,optional_function_index_present=False,COFF_objects_emitted=1,native_execution=False,elapsed_seconds=round(time.monotonic()-start,3),peak_memory_bytes=collector.peak_memory_bytes(),**adapter.FALSE))
            return publish_outputs(directory,emitted,report,start,pins,make_result,note)
        except BaseException as error:
            for path,device,inode in published:
                if path.exists():
                    current=path.stat()
                    if (current.st_dev,current.st_ino)==(device,inode):path.unlink()
            note(dict(state='failed',error_type=type(error).__name__,code=getattr(error,'code','PROJECTION_FAILURE')));raise


def main(argv=None):
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('input-request','observation','outcome-review','out-dir'):parser.add_argument('--'+name,type=Path,required=True)
    for name in ('input-request-sha256','observation-sha256','outcome-review-sha256','parent'):parser.add_argument('--'+name,required=True)
    parser.add_argument('--expected-tool',action='append',required=True)
    result=publish(parser.parse_args(argv));print(json.dumps(dict(parent=result['parent'],object_sha256=result['projection']['output_sha256'],runtime_eligible=False)));return 0


if __name__=='__main__':raise SystemExit(main())
