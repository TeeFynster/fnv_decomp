"""Fixed IOTask expanded-retention metadata observer; no transform/native API."""
from __future__ import annotations
from collections import Counter,defaultdict,deque
import copy
import hashlib
from pathlib import Path
import re
import struct
import root_code_closure as ordinary

EXPANDED_EH_INTERFACE='root-code-closure-expanded-eh-v2'
ORDINARY_PIN='4bfdb5001380a3d7e5db7517033285d49ab211be68e2fcba15964f0ad5b03c53'
PARSER_PIN='76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64'
require=ordinary.require
digest=ordinary.digest
public_metadata=ordinary.public_metadata
ROOT=dict(original_address='0x00440540',symbol='??0IOTask@@QAE@W4IO_TASK_PRIORITY@@@Z',symbol_index=8,section=3,value=0,size=101)
SECTIONS=[dict(section=i,role=role,parent=parent,extent=extent) for i,role,parent,extent in
    ((1,'directives',None,'whole'),(3,'ordinary-parent',None,101),(4,'parent-eh-code',3,35),(6,'parent-eh-state',3,44),(16,'whole-safeseh-index',None,4))]
LOCALS=[dict(symbol_index=i,section=sn,value=value,type=typ,storage=3,aux_count=0,role=role) for i,sn,value,typ,role in
    ((12,4,0,32,'cleanup'),(19,4,8,32,'handler'),(24,6,8,0,'funcinfo'),(25,6,0,0,'unwind-map'))]
BOUNDARY=dict(symbol_index=16,section=5,value=4,symbol='??_7IOTask@@6B@',original_base='0x01016c10',role='data',semantic_domain='data',contract_kind='vtable-view',storage_defined=False)
PARENT_FIELDS=[(6,19,6),(19,18,6),(42,17,20),(58,16,6),(70,13,20)]
DEPENDENCY_FIELDS={4:[(4,9,20),(21,21,20),(26,24,6),(31,20,20)],6:[(4,12,6),(16,25,6)]}
EXTERNAL={9:('code','code','ordinary-function'),13:('code','code','ordinary-function'),16:('data','data','vtable-view'),
    17:('code','code','ordinary-function'),18:('data','data','security-cookie'),20:('crt-contract','code','cxx-frame-handler'),
    21:('crt-contract','code','security-cookie-check')}
EXTERNAL_NAMES={9:'??1?$BSTask@_J@@UAE@XZ',13:'?SetIOTaskPriority@IOTask@@QAEXW4IO_TASK_PRIORITY@@@Z',16:'??_7IOTask@@6B@',17:'??0?$BSTask@_J@@QAE@XZ',18:'___security_cookie',20:'___CxxFrameHandler3',21:'@__security_check_cookie@4'}
FALSE=dict(closure_observed=False,root_closure_candidate=False,serialization_candidate=False,full_serialization_eligible=False,
    emission_performed=False,runtime_eligible=False,provider_selected=False,ABI_verified=False,link_ready=False,namespace_approved=False)


def valid_hash(value):return isinstance(value,str) and re.fullmatch('[0-9a-f]{64}',value) is not None


def dependency_observations(obj):
    """Physical fields only. Original targets/state semantics require EH replay."""
    rows=[]
    for sn in (4,6):
        for off,idx,kind in obj['sections'][sn]['relocs']:
            target=obj['symbols'][idx]
            rows.append(dict(section=sn,offset=off,target_index=idx,kind=kind,
                addend_bits=struct.unpack_from('<I',obj['sections'][sn]['payload'],off)[0],
                target_symbol={k:target[k] for k in ('name','section','value','type','storage','aux_count')},identity_status='pending-eh-adapter'))
    return rows


def section_aux(obj,sn):
    sec=obj['sections'][sn]
    entries=[(i,s) for i,s in obj['symbols'].items() if (s['name'],s['section'],s['value'],s['type'],s['storage'],s['aux_count'])==(sec['name'],sn,0,0,3,1)]
    require(len(entries)==1,'unique known section auxiliary required')
    i,s=entries[0];a=struct.unpack('<IHHIhBBH',s['aux'])
    require(a[0]==sec['size'] and a[1]==len(sec['relocs']) and not a[2] and not a[6] and not a[7],'unknown section auxiliary fields')
    return i,a


def check_provenance(contract):
    p=contract['provenance'];require(p['recipe_id']==contract['recipe_id'] and p['recipe_index']==69,'provenance recipe differs')
    for key in ('object_sha256','source_sha256','recipe_unit_sha256','recipe_manifest_sha256','producer_manifest_sha256','retained_proof_sha256',
        'selection_sha256','binding_sha256','binding_details_sha256','reference_identity_sha256','observer_sha256'):
        require(valid_hash(p.get(key)),'missing source/proof/reference/producer provenance: '+key)
    require(p.get('optional_function_index_present')is False,'optional-index evidence differs')
    tools=p['dependency_tools_sha256'];require(isinstance(tools,dict) and tools and all(valid_hash(h) for h in tools.values()),'missing dependency tool provenance')
    require(tools.get('tools/rebuild/root_code_closure.py')==ORDINARY_PIN and tools.get('tools/rebuild/coff_code_archive.py')==PARSER_PIN,'ordinary/parser dependency pin differs')
    own=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    require(p['observer_sha256']==own and tools.get('tools/rebuild/expanded_root_code_closure.py')==own,'expanded producer source identity differs')


def external_ledger(expanded):
    rows=expanded['external_reference_contracts'];require([r['symbol_index'] for r in rows]==sorted(EXTERNAL),'external physical identity set/order differs')
    shared=expanded['shared_base_identities'];require(isinstance(shared,list) and shared,'missing shared base identities')
    by_base={}
    for row in shared:
        require(type(row['base'])is int and 0<=row['base']<=0xffffffff and row['identity_consistency']=='EXACT_BASE_ROLE_RESOLUTION','unproved shared identity')
        role,domain,kind=row['role'],row['semantic_domain'],row['contract_kind']
        require(role in ('code','data','crt-contract') and domain in {'code':{'code'},'data':{'data'},'crt-contract':{'code','data'}}[role] and isinstance(kind,str) and kind,'unsupported shared identity')
        identity=(role,domain,kind);require(by_base.setdefault(row['base'],identity)==identity,'conflicting shared base role/domain/subtype')
    result={}
    for row in rows:
        i=row['symbol_index'];identity=(row['role'],row['semantic_domain'],row['contract_kind'])
        require(identity==EXTERNAL[i] and row['proof_consistency']=='EXACT_OWN_SOURCE_RESOLUTION','external semantic boundary differs')
        require(type(row['base'])is int and by_base.get(row['base'])==identity,'missing compatible shared original base')
        result[i]=row
    require(result[16]['base']==0x1016c10,'DATA view original identity differs')
    return result


def extension_obligations(observations):
    rows=[]
    for sn,role,size in ((4,'parent-eh-code',35),(6,'parent-eh-state',44)):
        fields=[r for r in observations if r['section']==sn]
        rows.append(dict(code='RETAINED_PARENT_EH_OR_UNKNOWN_CHILD',evidence=dict(parent=3,child=sn,requested_role=role,full_extent=size,
            field_keys=[[r['section'],r['offset'],r['target_index'],r['kind']] for r in fields],field_observation_sha256=digest(fields))))
    rows.append(dict(code='LIVE_SAFESEH_HANDLER_REQUIRES_ADAPTER',evidence=dict(section=16,offset=0,symbol_index=19,target_section=4,target_value=8,record_count=1,retention_mode='whole-table')))
    for row in rows:row['blocker_id']=digest(dict(code=row['code'],evidence=row['evidence']))
    return rows


def observe_requested_dependency_retention(obj,contract,*,requested_dependency_retention):
    """Complete physical omission graph; all EH semantic/candidate flags stay false.

    This pure API consumes claimed hash-bound metadata. A separately reviewed
    collector/consumer must reconstruct inputs and independently replay EH proof.
    """
    require(hashlib.sha256(Path(ordinary.__file__).read_bytes()).hexdigest()==ORDINARY_PIN,'frozen ordinary producer changed')
    require(contract['recipe_id']=='0069-3b6fc41592bb705f' and contract['roots']==[ROOT],'fixed IOTask parent differs')
    require(requested_dependency_retention==[1,3,4,6,16],'unsupported expanded retained set')
    require(contract['export_policy']==ordinary.EXPORT_POLICY and all(contract.get(k)is True for k in ('verified_match','fields_complete','missing_fields_complete','unit_proofs_complete')),'incomplete root evidence')
    check_provenance(contract)
    require(contract['missing_fields']==[],'original missing fields cannot be discharged as EH')
    pieces=contract['parent_eh'];require(len(pieces)==2 and all(p[2]is True and p[3]=='0x00440540' for p in pieces),'false/unowned/missing parent EH pieces')
    require([p[1]-p[0] for p in pieces]==[8,27] and pieces[1][0]==pieces[0][0]+8,'parent piece spans differ')
    expanded=contract['expanded_retention_contract']
    require(set(expanded)=={'interface','requested_sections','local_symbols','data_boundary','dependency_field_observations','external_reference_contracts','shared_base_identities'},'unknown expanded contract keys')
    require(expanded['interface']==EXPANDED_EH_INTERFACE and expanded['requested_sections']==SECTIONS and expanded['local_symbols']==LOCALS and expanded['data_boundary']==BOUNDARY,'requested physical/owner/DATA contract differs')
    sec=obj['sections'];sym=obj['symbols'];keep={1,3,4,6,16};runtime={3,4,6}
    expected={1:('.drectve',0x100a00),3:('.text',0x60501020),4:('.text$x',0x60501020),6:('.xdata$x',0x40301040),16:('.sxdata',0x300200)}
    for sn,(name,flags) in expected.items():require(sn in sec and (sec[sn]['name'],sec[sn]['flags'])==(name,flags),'requested section metadata differs')
    require([sec[i]['size'] for i in (3,4,6,16)]==[101,35,44,4],'whole requested extents differ')
    require(sec[3]['relocs']==PARENT_FIELDS and all(sec[sn]['relocs']==keys for sn,keys in DEPENDENCY_FIELDS.items()),'eleven physical fields differ')
    require(sec[16]['payload']==struct.pack('<I',19) and not sec[16]['relocs'] and [i for i,s in sec.items() if s['name']=='.sxdata']==[16],'whole SafeSEH record differs')
    require((sym[8]['name'],sym[8]['section'],sym[8]['value'],sym[8]['type'],sym[8]['storage'],sym[8]['aux_count'])==(ROOT['symbol'],3,0,32,2,0),'parent physical identity differs')
    local_names={12:'__unwindfunclet$'+ROOT['symbol']+'$0',19:'__ehhandler$'+ROOT['symbol'],24:'__ehfuncinfo$'+ROOT['symbol'],25:'__unwindtable$'+ROOT['symbol']}
    for row in LOCALS:
        s=sym[row['symbol_index']]
        require(all(s[k]==row[k] for k in ('section','value','type','storage','aux_count')) and s['name']==local_names[row['symbol_index']],'private parent symbol differs')
    boundary=sym[16];require((boundary['name'],boundary['section'],boundary['value'],boundary['type'],boundary['storage'],boundary['aux_count'])==(BOUNDARY['symbol'],5,4,0,2,0),'unproved omitted DATA definition')
    observations=dependency_observations(obj);require(observations==expanded['dependency_field_observations'],'six dependency field observations differ')
    externals=external_ledger(expanded)
    for i,row in externals.items():
        s=sym[i];require(s['name']==EXTERNAL_NAMES[i],'unproved external source spelling')
        require(s['storage']==2 and not s['aux_count'],'external boundary record is weak/common/opaque')
        if i!=16:require(s['section']==0 and s['value']==0 and s['type']==(0 if row['semantic_domain']=='data' else 32),'undefined external boundary metadata differs')
    # Existing ordinary metadata validation remains unchanged. Only precise scoped
    # root-only obstacles are explained by the new pending EH retention graph.
    model=ordinary.assess_object(obj,contract);fatal=[];explained=[]
    def block(code,evidence):fatal.append(dict(code=code,evidence=public_metadata(evidence)))
    for b in model['blockers']:
        code,e=b['code'],b['evidence']
        scoped=((code=='RETAINED_PARENT_EH_OR_UNKNOWN_CHILD' and e in ({'parent':3,'child':4},{'parent':3,'child':6})) or
            (code=='SPECIAL_RUNTIME_REFERENCE' and e==[3,6,19,6]) or
            (code=='SPECIAL_OMITTED_TARGET_CONVERSION' and e==19) or
            (code=='PARENT_EH_REQUIRES_CLOSURE_ADAPTER' and e==pieces) or
            (code=='LIVE_SAFESEH_HANDLER_REQUIRES_ADAPTER' and e==dict(section=16,offset=0,symbol_index=19,target_section=4,target_value=8,omission_reason='handler outside retained and name-resolution closure')))
        if scoped:explained.append(copy.deepcopy(b))
        else:fatal.append(dict(code=code,evidence=e))
    # Independently verify required association closure and exact section members.
    required={8,12,19,24,25}|set(externals);association_rows=[]
    for sn in sorted(keep):
        si,a=section_aux(obj,sn);required.add(si)
        if sn in (4,6):require((a[4],a[5])==(3,5),'EH child association differs')
        elif sn==3:require((a[4],a[5])==(0,1),'ordinary parent COMDAT differs')
        else:require((a[4],a[5])==(0,0),'special section has hidden association')
        members={i for i,s in sym.items() if s['section']==sn}
        expected_members={si,8} if sn==3 else {si,12,19} if sn==4 else {si,24,25} if sn==6 else {si}
        require(members==expected_members,'unproved additional retained entry/alias')
    for i,s in sym.items():
        if s['aux_count']==1 and s['storage']==3 and s['section']>0 and s['name']==sec[s['section']]['name']:
            a=struct.unpack('<IHHIhBBH',s['aux'])
            if a[5]==5:
                association_rows.append(dict(child=s['section'],parent=a[4],symbol_index=i))
                if a[4] in keep and s['section'] not in keep:block('UNKNOWN_EXPANDED_ASSOCIATIVE_DEPENDENCY',dict(parent=a[4],child=s['section']))
                if s['section'] in keep and a[4] not in keep:block('EXPANDED_CHILD_ESCAPES_PARENT',dict(parent=a[4],child=s['section']))
        if s['name'] in ('@comp.id','@feat.00'):required.add(i)
    # Five original parent fields still validate exact original source identities.
    require(len(contract['fields'])==5,'five mandatory parent binding rows required')
    for row in contract['fields']:
        cr=row['coff_relocation'];i=cr['symbol_index'];base=int(row['derived_source_symbol_base_va'],16)
        if i==19:require(base==pieces[0][0]+8,'parent handler original identity differs')
        else:require(i in externals and base==externals[i]['base'],'parent original boundary base differs')
    # All eleven runtime references and the retained index table seed a freshly
    # computed closure; static whole-object graph edges never imply liveness.
    edges=[copy.deepcopy(e) for e in model['edges'] if e['kind'] not in ('RETAINED_RELOCATION','LIVE_NAME_RESOLUTION','LIVE_WEAK_FALLBACK','PROVED_REDUNDANT_UNDEFINED_IAT_NAME_RELATIONSHIP')]
    def edge(kind,source,target):edges.append(dict(kind=kind,source=source,target=target))
    physical_fields=[]
    for sn in sorted(runtime):
        for off,i,kind in sec[sn]['relocs']:
            required.add(i);edge('RETAINED_RELOCATION',dict(section=sn,offset=off,kind=kind),i)
            physical_fields.append(dict(section=sn,offset=off,target_index=i,kind=kind,addend_bits=struct.unpack_from('<I',sec[sn]['payload'],off)[0],
                identity_status='parent-final-binding' if sn==3 else 'pending-eh-adapter'))
    edge('RETAINED_SAFESEH_INDEX',dict(section=16,offset=0),19);required.add(19)
    names=defaultdict(list);weak={}
    for i,s in sym.items():
        is_section=s['storage']==3 and s['section']>0 and s['type']==0 and s['value']==0 and s['name']==sec[s['section']]['name']
        if not is_section and s['storage']!=103 and s['name'] not in ('@comp.id','@feat.00') and (s['storage'] in (2,105) or s['type']==32):names[s['name']].append(i)
        if s['storage']==105 and s['aux_count']==1 and len(s['aux'])==18:weak[i]=struct.unpack_from('<I',s['aux'])[0]
    live=set(required);queue=deque(sorted(live))
    for e in edges:
        if e['kind']=='DIRECTIVE_NAME_RESOLUTION':
            for i in e['target']['symbol_indices']:
                if i not in live:live.add(i);queue.append(i)
    while queue:
        i=queue.popleft();adjacent=list(names.get(sym[i]['name'],[]))
        if i in weak:adjacent.append(weak[i])
        for j in adjacent:
            edge('LIVE_WEAK_FALLBACK' if i in weak and j==weak[i] else 'LIVE_NAME_RESOLUTION',i,j)
            if j not in live:live.add(j);queue.append(j)
    for i in sorted(live):
        s=sym[i]
        if s['storage']==105:block('REACHABLE_EXPANDED_WEAK_REQUIRES_POLICY',i)
        if s['section']==0 and s['value']:block('REACHABLE_EXPANDED_COMMON_REQUIRES_OWNER',i)
        if i not in required:block('UNPROVED_EXPANDED_NAME_ALIAS',i)
    require(55 in weak and weak[55]==54 and struct.unpack_from('<I',sym[55]['aux'],4)[0]==2,'required weak fallback metadata differs')
    if 55 in live or 54 in live:block('REQUIRED_WEAK_OMISSION_NOT_PROVED',dict(symbol_index=55,fallback_index=54))
    for i in required:
        if sym[i]['section']>0 and sym[i]['section'] not in keep and i!=16:block('UNPROVED_EXPANDED_DEFINITION_CONVERSION',i)
    sections=copy.deepcopy(model['sections']);symbols=copy.deepcopy(model['symbols'])
    for row in sections:
        i=row['index'];row['disposition']='RETAIN_EH_PENDING_RUNTIME_SECTION' if i in (4,6) else 'RETAIN_WHOLE_SAFESEH_PENDING_ADAPTER' if i==16 else 'RETAIN_ORDINARY_PARENT_CODE' if i==3 else 'RETAIN_EXACT_DIRECTIVES' if i==1 else 'EXCLUDE_NONEXPORTED_SECTION'
    for row in symbols:
        i=row['index'];s=sym[i]
        if i in required:
            row['disposition']='RETAIN_EXPANDED_SECTION_SYMBOL' if s['section'] in keep else 'CONVERT_EXACT_DATA_VIEW_TO_UNDEFINED' if i==16 else 'RETAIN_ABSOLUTE_METADATA' if s['section']==-1 else 'RETAIN_EXACT_UNDEFINED_REFERENCE'
        elif s['storage']==105:row['disposition']='OMIT_UNREACHABLE_WEAK_CANDIDATE'
        elif s['section']==0 and s['value']:row['disposition']='OMIT_UNREACHABLE_COMMON_CANDIDATE'
    slots=sorted(j for i in required for j in range(i,i+1+sym[i]['aux_count']))
    universe=dict(section_indices=sorted(sec),primary_indices=sorted(sym),physical_slots=list(range(obj['symbol_count'])))
    require(sorted(j for i,s in sym.items() for j in range(i,i+1+s['aux_count']))==universe['physical_slots'],'incomplete metadata universe')
    obligations=extension_obligations(observations)
    for b in fatal:b['blocker_id']=digest(dict(code=b['code'],evidence=b['evidence']))
    blockers=obligations+fatal;complete=not fatal
    scope=dict(policy_id=EXPANDED_EH_INTERFACE,export_policy=contract['export_policy'],roots=contract['roots'],requested_dependency_retention=requested_dependency_retention,
        retained_section_indices=sorted(keep),retained_primary_indices=sorted(required),retained_physical_slots=slots,object_sha256=contract['provenance']['object_sha256'],
        provenance_sha256=digest(contract['provenance']),contract_identity_sha256=digest(contract),expanded_retention_contract_sha256=digest(expanded),
        physical_universe_sha256=digest(universe),edges_sha256=digest(edges))
    ids=[b['blocker_id'] for b in blockers]
    sub=dict(policy_id=EXPANDED_EH_INTERFACE,scope=scope,scope_sha256=digest(scope),graph_observation_complete=complete,
        disposition_sha256=digest(dict(sections=sections,symbols=symbols)),unresolved_blocker_ids=ids,
        exact_EH_SafeSEH_extension_obligation_ids=[b['blocker_id'] for b in obligations],omission_approved=False)
    return public_metadata(dict(schema_version=1,policy_id=EXPANDED_EH_INTERFACE,expanded_interface=EXPANDED_EH_INTERFACE,status='eh-semantics-pending' if complete else 'blocked',
        graph_observation_complete=complete,contract_identity_sha256=digest(contract),provenance=contract['provenance'],roots=contract['roots'],recipe_id=contract['recipe_id'],
        requested_dependency_retention=requested_dependency_retention,retained_section_indices=sorted(keep),retained_runtime_section_indices=[3,4,6],
        retained_primary_indices=sorted(required),retained_physical_slots=slots,exported_primary_indices=[8],physical_universe=universe,
        sections=sections,symbols=symbols,edges=edges,retained_physical_fields=physical_fields,dependency_field_observations=observations,parent_EH=pieces,
        external_reference_contracts=expanded['external_reference_contracts'],shared_base_identities=expanded['shared_base_identities'],
        omitted_definition_conversions=[dict(symbol_index=16,original_section=5,original_value=4,original_base='0x01016c10',role='data',storage_defined=False)],
        blockers=blockers,omission_subcertificate=sub,ordinary_observation_sha256=digest(model),ordinary_scoped_obligations=explained,
        summary=dict(retained_relocations=len(physical_fields),dependency_relocations=len(observations),retained_primary_symbols=len(required),physical_slots=len(slots),
            graph_edges=dict(Counter(e['kind'] for e in edges)),fatal_blockers=len(fatal)),**FALSE))
