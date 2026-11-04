"""Finite central-contract no-catch EH metadata collector. No emission/execution."""
from __future__ import annotations
import argparse
import gzip
import hashlib
import json
import os
from pathlib import Path
import struct
import sys
import tempfile
import time
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
import build_and_match as oracle
import parent_eh_adapter as adapter
import coff_code_archive as coff
from coff_inventory import Coff as InventoryCoff,reconcile_recipes,peak_memory_bytes
from eh_ownership import native_pieces
from data_plan import Pe as MetadataPe
from runtime_code_inventory import EXPECTED,check_unit,public_metadata
from runtime_gaps import read_bound

TOOLS=('tools/rebuild/parent_eh_omission.py','tools/rebuild/ordinary_initialized_data_omission.py','tools/rebuild/parent_eh_collect.py','tools/rebuild/parent_eh_adapter.py','tools/rebuild/root_code_closure.py','tools/rebuild/coff_code_archive.py','tools/rebuild/coff_inventory.py','tools/rebuild/eh_ownership.py','tools/rebuild/eh_code_closure.py','tools/rebuild/runtime_code_inventory.py','tools/rebuild/runtime_bind_plan.py','tools/rebuild/relocation_audit.py','tools/rebuild/data_plan.py','tools/rebuild/import_plan.py','tools/rebuild/runtime_gaps.py','tools/rebuild/runtime_code_pool.py','tools/build_and_match.py','tools/compare.py','tools/function_spans.py')
require=adapter.guard
POLICY='parent-EH-central205-finite-collect-v1'


def file_hash(path):
    result=hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda:stream.read(1024*1024),b''):result.update(block)
    return result.hexdigest()
def tool_pins(values):
    result={}
    for value in values:
        name,sep,h=value.partition('=');require(sep and name in TOOLS and name not in result and len(h)==64 and all(c in '0123456789abcdef' for c in h),'INVALID_TOOL_PIN');result[name]=h
    require(set(result)==set(TOOLS),'INCOMPLETE_TOOL_PINS');return result

def private_directory(path):
    path=Path(path).resolve();private=(ROOT/'build/rebuild').resolve();require(path.is_relative_to(private) and path!=private and not path.exists(),'FRESH_PRIVATE_DIRECTORY_REQUIRED');return path

def stable(pins):
    require(not(ROOT/'build/function_index.json').exists(),'OPTIONAL_INDEX_APPEARED')
    for path,h in pins.items():require(file_hash(path)==h,'INPUT_OR_TOOL_DRIFT',path.name)

def check_budget(start):
    require(time.monotonic()-start<=540 and (peak_memory_bytes() or 0)<=1024**3,'COLLECTION_RESOURCE_BOUND')

def validate_read_scope(policy,scope,unit_proofs):
    require(scope['policy_sha256']==policy['_loaded_sha256'] and scope['retained_sha256']==EXPECTED['retained'],'READ_SCOPE_PROVENANCE')
    rows={r['parent']:r for r in scope['parents']};require(len(rows)==len(policy['targets']),'READ_SCOPE_ROOT_SET')
    for target in policy['targets']:
        root=target['root'];row=rows[root['original_address']];pieces=[p for p in unit_proofs[root['recipe_index']].get('eh_sections',[]) if p[3]==root['original_address']]
        skip=not pieces or any(p[2]is not True for p in pieces)
        expected=[] if skip else [[int(root['original_address'],16),int(root['original_address'],16)+root['size']]]+[[p[0],p[1]] for p in pieces]
        require(row['object_sha256']==root['object_sha256'] and row['source_sha256']==root['source_sha256'] and row['recipe_id']==root['recipe_id'] and row['parent_extent']==root['size'] and row['skip_native_reads']==skip and row['approved_code_spans']==expected and row['maximum_derived_state_bytes']==(0 if skip else 548),'EXACT_READ_SCOPE_JOIN')
    return rows


def validate_policy(policy):
    require(policy['schema_version']==1 and policy['policy_id']=='no-catch-parent-eh-central205-v1' and policy['source_only']is True,'UNKNOWN_FINITE_POLICY')
    targets=policy['targets'];require(0<len(targets)<=policy['bounds']['max_roots']<=32 and len({t['root']['original_address'] for t in targets})==len(targets),'FINITE_ROOT_SCOPE')
    require(len({t['root']['recipe_id'] for t in targets})<=policy['bounds']['max_recipes']<=32,'FINITE_RECIPE_SCOPE')
    require(all(policy[k]is False for k in ('runtime_eligible','provider_selected','ABI_verified','link_ready')),'POLICY_PROMOTION')

def selected_contracts(policy,central,lane_path):
    """One exact saved lane stream, no global binding or archive rescan."""
    targets={t['central_record_ordinal']:t for t in policy['targets']};found={}
    with gzip.open(lane_path,'rt',encoding='utf-8') as stream:
        for ordinal,line in enumerate(stream,1):
            require(ordinal<=1000 and len(line)<=64*1024*1024,'LANE_RECORD_BUDGET')
            if ordinal not in targets:continue
            row=json.loads(line);target=targets[ordinal];require(adapter.digest(row)==target['central_record_sha256'],'CENTRAL_RECORD_DRIFT')
            require(row['event']=='SINGLE_ROOT_OBSERVATION' and row['requested_roots']==[target['root']] and row['certificate_sha256']==target['central_certificate_sha256']==adapter.digest(row['certificate']) and row['contract_identity_sha256']==adapter.digest(row['contract']),'CENTRAL_CONTRACT_JOIN')
            found[target['root']['original_address']]=row
    require(len(found)==len(targets),'MISSING_FINITE_CONTRACT');return found

class ScopedReference:
    """Only approved selected code and bounded anchored data/literal reads."""
    def __init__(self,reference,metadata,code_spans,reads=None,data_spans=None):self.reference=reference;self.metadata=metadata;self.code_spans=list(code_spans);self.data_spans=[] if data_spans is None else data_spans;self.reads=[] if reads is None else reads
    def __getattr__(self,name):return getattr(self.reference,name)
    def add_data(self,address,size,reason):
        require(type(address)is int and 0<size<=4096,'DERIVED_DATA_BOUND')
        section=self.metadata.section(address-self.metadata.base,size,required=True);require(not section['executable'],'DERIVED_DATA_IS_EXECUTABLE')
        self.data_spans.append((address,address+size,reason))
    def read(self,address,size):
        require(type(address)is int and type(size)is int and 0<=size<=65536,'READ_BOUND')
        ranges=self.code_spans+[(a,b) for a,b,_ in self.data_spans]
        require(any(a<=address and address+size<=b for a,b in ranges),'UNAPPROVED_REFERENCE_RANGE',dict(address=address,size=size))
        item=dict(address=address,size=size,completed=False);self.reads.append(item);require(sum(r['size'] for r in self.reads)<=1048576 and len(self.reads)<=8192,'READ_BUDGET')
        result=self.reference.read(address,size);item['completed']=True;return result

def prepare_reference(raw,recipe,unit_proof,contract,reference,metadata,reads=None,data_spans=None,approved_code_spans=None):
    root=contract['roots'][0];parent=root['original_address'];pieces=contract['parent_eh'];skip=not pieces or any(p[2]is not True for p in pieces);code_spans=[] if skip else [(int(parent,16),int(parent,16)+root['size'])]+[(p[0],p[1]) for p in pieces]
    if approved_code_spans is not None:require([list(span) for span in code_spans]==approved_code_spans,'SCOPED_REFERENCE_CODE_DRIFT')
    scoped=ScopedReference(reference,metadata,code_spans,reads,data_spans)
    # A failed selected piece needs no native observation at all.
    if not pieces or any(p[2]is not True for p in pieces):return scoped
    obj=coff.parse(raw);symbols=obj['symbols'];names={s['name']:(i,s) for i,s in symbols.items() if s['section']>0}
    handler=names.get('__ehhandler$'+root['symbol']);info=names.get('__ehfuncinfo$'+root['symbol'])
    if handler is None or info is None:return scoped
    hi,h=handler;ii,f=info;state=obj['sections'][f['section']]
    if not(0<state['size']<=548):return scoped
    with tempfile.TemporaryDirectory(prefix='parent-EH-source-map-') as temporary:
        path=Path(temporary)/'native.obj';path.write_bytes(raw)
        # Guard before the unchanged comparison parser materializes BSS.
        require(sum(s['size'] for s in obj['sections'].values())<=256*1024*1024,'DECLARED_ORACLE_SECTION_BUDGET_EXCEEDED')
        core=oracle.Coff(path);mapped=list(native_pieces(core,recipe,unit_proof))
    handler_pieces=[(sn,a,b,p) for sn,a,b,p in mapped if p[3]==parent and sn==h['section'] and a==h['value']]
    if len(handler_pieces)!=1:return scoped
    sn,a,b,piece=handler_pieces[0];anchors=[r for r in obj['sections'][sn]['relocs'] if a<=r[0]<b and r[1]==ii and r[2]==6]
    if len(anchors)!=1:return scoped
    offset,_,_=anchors[0];field=piece[0]+offset-a;pointer=struct.unpack('<I',scoped.read(field,4))[0];addend=struct.unpack_from('<I',obj['sections'][sn]['payload'],offset)[0]
    base=(pointer-addend-f['value'])&0xffffffff;scoped.add_data(base,state['size'],'own-handler-FuncInfo-anchor')
    for row in contract['fields']:
        if row['classification']!='COMPILER_LITERAL_FULL_READONLY_NONPOINTER_EQUALITY':continue
        cr=row['coff_relocation'];s=symbols[cr['symbol_index']]
        if s['section']>0:
            section=obj['sections'][s['section']];extent=len(section['payload'])-s['value']
            if 0<extent<=4096:
                scoped.add_data(int(row['derived_source_symbol_base_va'],16),extent,'pinned-parent-literal-comparison-only')
                expected=recipe.get('symbols',{}).get(s['name'])
                if expected is not None and int(expected,0)!=int(row['derived_source_symbol_base_va'],16):scoped.add_data(int(expected,0),extent,'pinned-parent-literal-expected-comparison-only')
    return scoped


def collect(args):
    start=time.monotonic();policy_path=Path(args.policy).resolve();policy=read_bound(policy_path,args.policy_sha256);validate_policy(policy);policy['_loaded_sha256']=args.policy_sha256
    scope_path=Path(args.read_scope).resolve();read_scope=read_bound(scope_path,args.read_scope_sha256)
    central_path=Path(args.central).resolve();request_path=Path(args.request).resolve();link_path=Path(args.link_groups).resolve();lane_evidence_path=Path(args.lane_evidence).resolve()
    central=read_bound(central_path,policy['inputs']['central']);request=read_bound(request_path,policy['inputs']['request']);link=read_bound(link_path,policy['inputs']['link']);evidence=read_bound(lane_evidence_path,policy['inputs']['lane08'])
    require(central['request_sha256']==policy['inputs']['request'] and len(request['roots'])==205,'CENTRAL_REQUEST_JOIN')
    demand={g['symbol']:g for g in link['groups']};requested={r['original_address']:r for r in request['roots']};record_index={(r['lane'],r['lane_record_ordinal']):r for r in central['observations']}
    for target in policy['targets']:
        root=target['root'];require(root==requested[root['original_address']] and target['actual_link_symbol'] in demand and demand[target['actual_link_symbol']]['classification']=='CODE' and root['original_address'] in demand[target['actual_link_symbol']]['original_targets'],'ACTUAL_LINK_PRIORITY_JOIN')
        row=record_index[(target['central_lane'],target['central_record_ordinal'])];require(row['record_sha256']==target['central_record_sha256'] and row['certificate_sha256']==target['central_certificate_sha256'],'CENTRAL_INDEX_JOIN')
    lanes={t['central_lane'] for t in policy['targets']};require(len(lanes)==1,'INITIAL_ONE_SAVED_LANE_SCOPE');lane=next(iter(lanes));artifact=central['lane_artifacts'][str(lane)];lane_path=(central_path.parent/'lanes'/artifact['path']).resolve();require(lane_path.is_relative_to((central_path.parent/'lanes').resolve()),'FOREIGN_LANE_PATH')
    require(file_hash(lane_path)==artifact['sha256']==policy['central_lane_sha256'],'LANE_IDENTITY')
    names=('manifest','retained','recipes','selection');paths={name:Path(getattr(args,name)).resolve() for name in names};data={name:read_bound(paths[name],EXPECTED[name]) for name in names}
    require(all(central['inputs'][name]==EXPECTED[name] for name in names),'AUTHORITATIVE_INPUT_JOIN')
    manifest,proof,recipes,selection=[data[name] for name in names];require(reconcile_recipes(manifest,paths['recipes'])['verified'],'RECIPE_RECONCILIATION')
    require(all(proof[k]is True for k in ('retained_verification_pass','function_byte_verification_pass','global_listed_eh_coverage_pass','original_oracle_parity_pass','evidence_stable')) and proof['inputs']['function_index_present']is False and selection['function_index_present']is False,'BASELINE_GATES')
    tools=tool_pins(args.expected_tool);pins={policy_path:args.policy_sha256,scope_path:args.read_scope_sha256,central_path:policy['inputs']['central'],request_path:policy['inputs']['request'],link_path:policy['inputs']['link'],lane_evidence_path:policy['inputs']['lane08'],lane_path:artifact['sha256']}
    pins.update({paths[name]:EXPECTED[name] for name in names});pins.update({ROOT/name:h for name,h in tools.items()})
    for name,h in proof['inputs']['tools_sha256'].items():
        path=(ROOT/name).resolve();require(path.is_relative_to(ROOT/'tools') and (path not in pins or pins[path]==h),'PRODUCER_PIN_CONFLICT');pins[path]=h
    image=Path(args.reference).resolve();pins[image]=proof['inputs']['image_sha256'];pins[ROOT/'build/image_check.json']=proof['inputs']['image_check_sha256']
    units={u['recipe_index']:u for u in manifest['units']};proofs={u['recipe_index']:u for u in proof['units']};scope_rows=validate_read_scope(policy,read_scope,proofs);source_context={};object_paths={}
    for target in policy['targets']:
        r=target['root'];unit=units[r['recipe_index']];unit_proof=proofs[r['recipe_index']];check_unit(unit,unit_proof)
        require(unit['recipe_id']==r['recipe_id'] and unit['object_sha256']==r['object_sha256'] and unit['source_sha256']==r['source_sha256'],'FIXED_SOURCE_OBJECT_JOIN')
        native=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve();source=(ROOT/unit['source']).resolve();require(source.is_relative_to(ROOT),'FOREIGN_SOURCE');pins[native]=unit['object_sha256'];pins[source]=unit['source_sha256'];object_paths[r['recipe_index']]=native;source_context[unit['source']]=unit['source_sha256']
        choice=selection['selections'][r['original_address']];require(all(choice[key]==r[key] for key in ('recipe_id','recipe_index','symbol','section','value','size')),'CURRENT_SELECTED_PROVIDER_JOIN')
    stable(pins);contracts=selected_contracts(policy,central,lane_path);directory=private_directory(args.out_dir);require(not any(path.is_relative_to(directory) for path in pins),'OUTPUT_INPUT_COLLISION');directory.mkdir();journal=directory/'progress.jsonl';published=[]
    with journal.open('x',encoding='utf-8') as notes:
        def note(record):notes.write(json.dumps(public_metadata(record),sort_keys=True)+'\n');notes.flush();os.fsync(notes.fileno())
        note(dict(state='started',policy_sha256=args.policy_sha256,roots=len(policy['targets']),recipes=len(object_paths)))
        try:
            reference=oracle.Pe(image);require(adapter.sha(reference.data)==proof['inputs']['image_sha256'] and oracle.image_ok(reference)[0],'REFERENCE_IMAGE_GATE')
            metadata=MetadataPe(image)
            try:
                highlow=[metadata.base+site for site in metadata.relocations()];exe=[(metadata.base+s['rva'],metadata.base+s['rva']+s['extent']) for s in metadata.sections if s['executable']]
                outcomes=[];cache={};stage=directory/'observations.staged.jsonl.gz'
                with stage.open('xb') as output:
                    with gzip.GzipFile(fileobj=output,mode='wb',mtime=0) as stream:
                        for ordinal,target in enumerate(policy['targets'],1):
                            check_budget(start)
                            r=target['root'];idx=r['recipe_index'];unit=units[idx];unit_proof=proofs[idx]
                            if idx not in cache:
                                require(object_paths[idx].stat().st_size<=64*1024*1024,'RAW_OBJECT_BUDGET_EXCEEDED');cache[idx]=object_paths[idx].read_bytes()
                            raw=cache[idx];require(adapter.sha(raw)==r['object_sha256'],'LOADED_OBJECT_DRIFT')
                            row=contracts[r['original_address']];contract=row['contract'];require(contract['provenance']['reference_identity_sha256']==proof['inputs']['image_sha256'],'CONTRACT_REFERENCE_JOIN')
                            # Recompute the frozen ordinary certificate; retain every original blocker.
                            ordinary=adapter.ordinary.assess_object(coff.parse(raw),contract);require(adapter.digest(ordinary)==row['certificate_sha256'],'FROZEN_CENTRAL_CERTIFICATE_DRIFT')
                            reads=[];derived=[]
                            try:
                                scoped=prepare_reference(raw,unit['recipe'],unit_proof,contract,reference,metadata,reads,derived,scope_rows[r['original_address']]['approved_code_spans'])
                                result=adapter.observe_parent(raw,contract,unit['recipe'],unit_proof,recipes['units'],scoped,highlow,exe)
                                reads=scoped.reads;derived=scoped.data_spans
                            except (adapter.Blocked,ValueError,KeyError,IndexError,struct.error) as error:
                                result=dict(policy_id=adapter.POLICY,status='blocked-input-scope',structural_projection_candidate=False,semantic_graph_verified=False,blockers=[dict(code=error.code if isinstance(error,adapter.Blocked) else 'UNKNOWN_DERIVED_READ_SCOPE',evidence=public_metadata(getattr(error,'evidence',None)))],**adapter.FALSE)
                            require(not(target['must_remain_blocked'] and result['structural_projection_candidate']),'KNOWN_FAILED_PIECE_PROMOTED')
                            record=public_metadata(dict(schema_version=1,root=r,source=target['source'],central_record_sha256=target['central_record_sha256'],central_contract_sha256=row['contract_identity_sha256'],central_certificate_sha256=row['certificate_sha256'],central_contract=contract,result=result,reference_reads=reads,derived_data_spans=derived,source_context_causality_verified=False))
                            encoded=json.dumps(record,sort_keys=True,separators=(',',':')).encode();stream.write(encoded+b'\n');outcomes.append(dict(ordinal=ordinal,root=r,record_sha256=adapter.digest(record),candidate=result['structural_projection_candidate'],blockers=[b['code'] for b in result['blockers']],reference_read_bytes=sum(item['size'] for item in reads if item['completed'])))
                            note(dict(state='parent-complete',ordinal=ordinal,address=r['original_address'],candidate=result['structural_projection_candidate'],record_sha256=adapter.digest(record)));check_budget(start)
                    output.flush();os.fsync(output.fileno())
            finally:metadata.close()
            check_budget(start);require(stage.stat().st_size<=128*1024**2,'OUTPUT_BUDGET');stable(pins);check_budget(start);details=directory/'observations.jsonl.gz'
            with details.open('xb') as target_file:identity=os.fstat(target_file.fileno());published.append((details,identity.st_dev,identity.st_ino));target_file.write(stage.read_bytes());target_file.flush();os.fsync(target_file.fileno())
            require(file_hash(details)==file_hash(stage),'PUBLISHED_DETAIL_DRIFT');stable(pins);check_budget(start)
            receipt=public_metadata(dict(schema_version=1,policy_id=POLICY,policy_sha256=args.policy_sha256,status='metadata-only',outcomes=outcomes,roots=len(outcomes),recipes=len(object_paths),candidates=sum(r['candidate'] for r in outcomes),blocked=sum(not r['candidate'] for r in outcomes),details_sha256=file_hash(details),details_bytes=details.stat().st_size,tools_sha256=tools,protected_inputs={p.relative_to(ROOT).as_posix() if p.is_relative_to(ROOT) else 'private-reference':h for p,h in pins.items()},source_context_sha256=source_context,source_context_causality_verified=False,optional_function_index_present=False,input_stability=True,elapsed_seconds=round(time.monotonic()-start,3),peak_memory_bytes=peak_memory_bytes(),emission_performed=False,native_execution=False,**adapter.FALSE))
            out=directory/'receipt.json'
            with out.open('x',encoding='utf-8') as target_file:identity=os.fstat(target_file.fileno());published.append((out,identity.st_dev,identity.st_ino));json.dump(receipt,target_file,sort_keys=True);target_file.write('\n');target_file.flush();os.fsync(target_file.fileno())
            stable(pins);check_budget(start);require(sum(p.stat().st_size for p in (stage,details,out,journal))<=128*1024**2,'TOTAL_OUTPUT_BUDGET');note(dict(state='complete',receipt_sha256=file_hash(out),details_sha256=file_hash(details)));return receipt
        except BaseException as error:
            for path,device,inode in published:
                if path.exists():
                    stat=path.stat()
                    if (stat.st_dev,stat.st_ino)==(device,inode):path.unlink()
            note(dict(state='failed',error_type=type(error).__name__,code=getattr(error,'code','COLLECTION_FAILURE')));raise


def main(argv=None):
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('policy','read-scope','central','request','link-groups','lane-evidence','manifest','retained','recipes','selection','reference','out-dir'):parser.add_argument('--'+name,type=Path,required=True)
    parser.add_argument('--policy-sha256',required=True);parser.add_argument('--read-scope-sha256',required=True);parser.add_argument('--expected-tool',action='append',required=True)
    result=collect(parser.parse_args(argv));print(json.dumps(dict(roots=result['roots'],candidates=result['candidates'],blocked=result['blocked'])));return 0

if __name__=='__main__':raise SystemExit(main())
