"""One accepted IOTask EH COFF projection. No compiler, linker or execution API."""
from __future__ import annotations
import argparse
import json
import os
from pathlib import Path
import struct
import sys
import tempfile
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
import build_and_match as oracle
import eh_code_closure as eh
from runtime_code_inventory import public_metadata
from coff_inventory import Coff as IndependentCoff
require=eh.require


def protected_inputs(observation,operation):
    argv=operation['argv'];require(len(argv)>2 and Path(argv[1]).resolve()==ROOT/'tools/rebuild/eh_code_observe.py','unexpected metadata collector identity')
    allowed={'manifest','retained','recipes','selection','binding','binding-details','handler-field-evidence','image','out','policy-sha256','expected-tool'};values={};tool_args=[]
    require((len(argv)-2)%2==0,'malformed saved operation arguments')
    for key,value in zip(argv[2::2],argv[3::2]):
        require(key.startswith('--') and key[2:] in allowed,'unknown saved operation argument')
        name=key[2:]
        if name=='expected-tool':tool_args.append(value)
        else:require(name not in values,'duplicate saved operation argument');values[name]=value
    require(set(values)==allowed-{'expected-tool'},'incomplete saved operation')
    require(observation['tools_sha256']==operation['tools_sha256'],'observer tool identities disagree')
    from eh_code_observe import parse_tools,CURRENT_HEADERS
    require(parse_tools(tool_args)==operation['tools_sha256'],'saved explicit tool identities disagree')
    paths={name:Path(values[name]).resolve() for name in ('manifest','retained','recipes','selection','binding','binding-details','handler-field-evidence','image')}
    pins={paths[name]:observation['inputs'][name] for name in ('manifest','retained','recipes','selection','binding')}
    pins.update({ROOT/name:value for name,value in operation['tools_sha256'].items()})
    policy=ROOT/'runtime/code-pools/iotask69-eh.json';pins[policy]=observation['inputs']['policy_sha256'];require(values['policy-sha256']==pins[policy],'policy identities disagree')
    def load(name):
        path=paths[name];require(eh.file_sha(path)==pins[path],'protected metadata changed');return json.loads(path.read_text())
    manifest=load('manifest');proof=load('retained');binding=load('binding')
    unit=[u for u in manifest['units'] if u['recipe_index']==69];require(len(unit)==1,'unique fixed unit required');unit=unit[0]
    require(unit['recipe_id']==observation['plan']['recipe_id'] and unit['object_sha256']==observation['plan']['object_sha256'] and unit['source_sha256']==observation['plan']['source_sha256'],'native projection identity differs')
    require(eh.file_sha(policy)==pins[policy],'current policy changed');fixed=json.loads(policy.read_text());eh.validate_policy(fixed)
    require(observation['plan']['selected']==fixed['selected'] and observation['plan']['retained_sections']==fixed['retained_sections'] and unit['object_sha256']==fixed['object_sha256'],'projection scope differs from fixed policy')
    native=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve();source=(ROOT/unit['source']).resolve();require(source.is_relative_to(ROOT),'foreign source context')
    pins.update({native:unit['object_sha256'],source:unit['source_sha256'],paths['image']:proof['inputs']['image_sha256'],paths['binding-details']:binding['details_sha256'],ROOT/'build/image_check.json':proof['inputs']['image_check_sha256']})
    from eh_field_witness import AUDIT_SHA256
    pins[paths['handler-field-evidence']]=AUDIT_SHA256
    for name,value in proof['inputs']['tools_sha256'].items():
        path=(ROOT/name).resolve();require(path.is_relative_to(ROOT/'tools'),'foreign protected producer path')
        require(path not in pins or pins[path]==value,'conflicting protected producer identities');pins[path]=value
    pins.update({ROOT/name:value for name,value in CURRENT_HEADERS.items()})
    require(proof['inputs']['function_index_present']is False and observation['optional_function_index_present']is False,'optional index evidence differs')
    return pins,native,paths['image']


def stable(pins):
    require(not (ROOT/'build/function_index.json').exists(),'optional index appeared')
    require(all(eh.file_sha(path)==value for path,value in pins.items()),'projection input/tool drift')


def reference_check(raw,plan,reference,*,maps=None):
    """Unchanged original core + exhaustive code/state original field checks."""
    obj=eh.coff.parse(raw);mapped=maps is not None
    sm=maps['section_map'] if mapped else {i:i for i in obj['sections']};ym=maps['symbol_map'] if mapped else {i:i for i in obj['symbols']}
    locations={3:int(plan['selected']['original_address'],16),4:plan['unchanged_core']['eh_sections'][0][0]}
    handler_original=plan['unchanged_core']['eh_sections'][1][0]
    info_value=struct.unpack('<I',reference.read(handler_original+18,4))[0];locations[6]=info_value-8
    bindings={row['symbol_index']:row for row in plan['external_obligations']}
    symbols={obj['symbols'][ym[i]]['name']:hex(row['base']) for i,row in bindings.items()}
    symbols[obj['symbols'][ym[19]]['name']]=hex(handler_original)
    function=dict(address=plan['selected']['original_address'],symbol=obj['symbols'][ym[8]]['name'],size=101)
    recipe=dict(functions=[function],symbols=symbols)
    with tempfile.TemporaryDirectory(prefix='eh-project-core-') as temporary:
        path=Path(temporary)/'component.obj';path.write_bytes(raw);core=oracle.Coff(path)
        rows=oracle.compare(core,reference,recipe,None);pieces,inferred,errors=oracle.eh_sections(core,reference,recipe,rows,{})
    require(len(rows)==1 and rows[0]['verdict']=='match' and rows[0]['compiled_extent']==101,'mandatory original ordinary comparison failed')
    require(not errors and [p[:4] for p in pieces]==[p[:4] for p in plan['unchanged_core']['eh_sections']] and all(p[2]is True for p in pieces),'mandatory original EH comparison failed')
    comparisons=[];fields=[]
    for old in (3,4,6):
        section=obj['sections'][sm[old]];expected=[f for f in plan['fields'] if f['section']==old]
        require(section['relocs']==[(f['offset'],ym[f['target_index']],f['kind']) for f in expected],'changed/extra projected relocation')
        size={3:101,4:35,6:44}[old];native=section['payload'];require(len(native)==size,'projected complete extent differs');original=reference.read(locations[old],size);mask=set()
        for field in expected:
            offset=field['offset'];target_index=field['target_index'];kind=field['kind'];target=obj['symbols'][ym[target_index]]
            addend=struct.unpack_from('<i' if kind==20 else '<I',native,offset)[0]
            if target_index in bindings:base=bindings[target_index]['base']
            else:
                owned=[sn for sn in (3,4,6) if sm[sn]==target['section']];require(len(owned)==1,'foreign projected local target');base=locations[owned[0]]+target['value']
            actual=(locations[old]+offset+4+struct.unpack_from('<i',original,offset)[0])&0xffffffff if kind==20 else struct.unpack_from('<I',original,offset)[0]
            require(addend==field['addend'] and base==field['original_base'] and actual==field['original_target']==(base+addend)&0xffffffff,'projected original relocation identity differs')
            fields.append(dict(section=old,output_section=sm[old],offset=offset,target_index=target_index,output_target_index=ym[target_index],kind=kind,original_base=base,original_target=actual,addend=addend));mask.update(range(offset,offset+4))
        differences=sum(a!=b for i,(a,b) in enumerate(zip(native,original)) if i not in mask);require(differences==0,'projected code/state nonfield differs')
        comparisons.append(dict(section=old,output_section=sm[old],size=size,nonfield_differences=differences,payload_sha256=eh.sha(native)))
    require(len(fields)==11,'incomplete projected graph')
    sx=obj['sections'][sm[16]];require(sx['payload']==struct.pack('<I',ym[19]) and not sx['relocs'],'wrong projected SafeSEH index')
    require(obj['symbols'][ym[19]]['storage']==3 and obj['symbols'][ym[19]]['section']==sm[4] and obj['symbols'][ym[19]]['value']==8,'SafeSEH lost parent-owned local handler')
    return dict(ordinary=rows,eh_sections=pieces,eh_errors=errors,inferred=inferred,fields=fields,comparisons=comparisons,comparison_bindings_only=symbols,provider_selected=False,runtime_eligible=False)


def output_directory(path):
    path=Path(path).resolve();private=(ROOT/'build/rebuild').resolve();require(path.is_relative_to(private) and path!=private and not path.exists(),'fresh private projection directory required');return path


def project(args):
    require(eh.file_sha(__file__)==args.projector_sha256,'unreviewed projector source')
    observation_path=Path(args.observation).resolve();operation_path=Path(args.operation).resolve()
    require(eh.file_sha(observation_path)==args.observation_sha256 and eh.file_sha(operation_path)==args.operation_sha256,'accepted metadata identity drift')
    observation=json.loads(observation_path.read_text());operation=json.loads(operation_path.read_text())
    require(observation['kind']=='fnv-iotask-eh-metadata-observation' and observation['input_stability']is True and observation['emission_performed']is False,'invalid actual metadata receipt')
    plan=observation['plan'];decision=observation['composition'];require(decision['source_files_verified']is True and decision['serialization_plan_ready']is True and all(decision[k]is False for k in eh.FALSE),'unapproved projection plan')
    pins,native_path,image_path=protected_inputs(observation,operation);pins.update({observation_path:args.observation_sha256,operation_path:args.operation_sha256,Path(__file__).resolve():args.projector_sha256})
    stable(pins);directory=output_directory(args.out_dir);require(not any(path.is_relative_to(directory) for path in pins),'projection outputs collide with protected inputs')
    directory.mkdir();journal=directory/'progress.jsonl';published=[]
    with journal.open('x',encoding='utf-8') as stream:
        def note(record):stream.write(json.dumps(public_metadata(record),sort_keys=True)+'\n');stream.flush();os.fsync(stream.fileno())
        note(dict(state='started',observation_sha256=args.observation_sha256))
        try:
            raw=native_path.read_bytes();reference=oracle.Pe(image_path);require(eh.sha(raw)==plan['object_sha256'] and eh.sha(reference.data)==decision['proof']['contract']['provenance']['reference_identity_sha256'] and oracle.image_ok(reference)[0],'loaded native/reference changed')
            before=reference_check(raw,plan,reference)
            emitted,serialization=eh.serialize_component(raw,plan,decision)
            stage=directory/'component.staged.obj'
            with stage.open('xb') as target:target.write(emitted);target.flush();os.fsync(target.fileno())
            staged=stage.read_bytes();require(eh.sha(staged)==serialization['output_sha256'],'staged output changed')
            after=reference_check(staged,plan,reference,maps=serialization['maps']);independent=IndependentCoff(stage)
            require(len(independent.sections)==5 and len(independent.symbols)==19 and sum(1+s['aux_count'] for s in independent.symbols.values())==24,'independent projected physical count differs')
            require(eh.file_sha(stage)==serialization['output_sha256'],'staged file drift during verification')
            stable(pins);note(dict(state='staged-verified',object_sha256=eh.sha(staged),fields=11,original_oracle_before_after=True))
            output=directory/'component.obj'
            with output.open('xb') as target:identity=os.fstat(target.fileno());published.append((output,identity.st_dev,identity.st_ino));target.write(staged);target.flush();os.fsync(target.fileno())
            require(eh.file_sha(output)==eh.sha(staged),'published object changed');stable(pins)
            receipt=dict(schema_version=1,kind='fnv-iotask-eh-coff-projection',observation_sha256=args.observation_sha256,operation_sha256=args.operation_sha256,projector_sha256=args.projector_sha256,
                input_object_sha256=eh.sha(raw),output_object_sha256=eh.sha(staged),output_bytes=len(staged),output_file='component.obj',serialization=serialization,original_before=before,original_after=after,
                independent_reparse=True,input_stability=True,optional_function_index_present=False,protected_input_sha256={path.relative_to(ROOT).as_posix() if path.is_relative_to(ROOT) else 'private-reference':value for path,value in pins.items()},
                emitted_objects=1,unresolved_obligations=plan['external_obligations'],runtime_eligible=False,provider_selected=False,ABI_verified=False,link_ready=False,namespace_approved=False,native_execution=False)
            receipt=public_metadata(receipt);path=directory/'projection.json'
            with path.open('x',encoding='utf-8') as target:identity=os.fstat(target.fileno());published.append((path,identity.st_dev,identity.st_ino));json.dump(receipt,target,sort_keys=True);target.write('\n');target.flush();os.fsync(target.fileno())
            stable(pins);require(eh.file_sha(output)==receipt['output_object_sha256'],'late object drift');note(dict(state='complete',receipt_sha256=eh.file_sha(path),object_sha256=eh.file_sha(output)))
            return receipt
        except BaseException as error:
            for path,device,inode in published:
                if path.exists():
                    current=path.stat()
                    if (current.st_dev,current.st_ino)==(device,inode):path.unlink()
            note(dict(state='failed',reason=public_metadata(str(error)),error_type=type(error).__name__));raise


def main(argv=None):
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('observation','operation','out-dir'):parser.add_argument('--'+name,type=Path,required=True)
    for name in ('observation-sha256','operation-sha256','projector-sha256'):parser.add_argument('--'+name,required=True)
    result=project(parser.parse_args(argv));print(json.dumps(dict(status='private-unresolved-coff',object_sha256=result['output_object_sha256'],runtime_eligible=False)));return 0

if __name__=='__main__':raise SystemExit(main())
