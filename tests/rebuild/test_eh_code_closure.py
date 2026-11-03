"""Authored COFF/reference metadata only; no game input or native tool runs."""
import copy
import json
from pathlib import Path
import struct
import sys
import unittest
from unittest.mock import patch
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/rebuild'))
import eh_code_closure as eh


def fixture():
    p=json.loads((ROOT/'runtime/code-pools/iotask69-eh.json').read_text())
    sections={i:dict(name='.rdata',size=4,flags=0x40300040,payload=bytes(4),relocs=[]) for i in range(1,18)}
    d=b'/DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES"'
    for i,name,size,flags in [(1,'.drectve',len(d),0x100a00),(2,'.debug$S',4,0x42100040),(3,'.text',101,0x60501020),(4,'.text$x',35,0x60501020),(5,'.rdata',36,0x40301040),(6,'.xdata$x',44,0x40301040),(16,'.sxdata',4,0x300200),(17,'.text',44,0x60501020)]:sections[i]=dict(name=name,size=size,flags=flags,payload=bytes(size),relocs=[])
    sections[1]['payload']=d;sections[16]['payload']=struct.pack('<I',19);sections[6]['payload']=struct.pack('<11I',0xffffffff,0,0x19930522,1,0,0,0,0,0,0,1)
    sections[3]['relocs']=[(6,19,6),(19,18,6),(42,17,20),(58,16,6),(70,13,20)]
    sections[4]['relocs']=[(4,9,20),(21,21,20),(26,24,6),(31,20,20)];sections[6]['relocs']=[(4,12,6),(16,25,6)]
    symbols={};auxslots=set()
    def sym(i,name,section,value=0,typ=0,storage=2,aux=b''):
        symbols[i]=dict(name=name,section=section,value=value,type=typ,storage=storage,aux=aux,aux_count=len(aux)//18);auxslots.update(range(i+1,i+1+len(aux)//18))
    def secsym(i,sn,selection=0,parent=0):
        s=sections[sn];sym(i,s['name'],sn,storage=3,aux=struct.pack('<IHHIhBBH',s['size'],len(s['relocs']),0,123,parent,selection,0,0))
    sym(0,'@comp.id',-1,8681481,storage=3);sym(1,'@feat.00',-1,1,storage=3)
    secsym(2,1);secsym(4,2);secsym(6,3,1);sym(8,p['selected']['symbol'],3,typ=32)
    sym(9,'??1?$BSTask@_J@@UAE@XZ',0,typ=32);secsym(10,4,5,3)
    sym(12,'__unwindfunclet$'+p['selected']['symbol']+'$0',4,typ=32,storage=3)
    sym(13,'?SetIOTaskPriority@IOTask@@QAEXW4IO_TASK_PRIORITY@@@Z',0,typ=32);secsym(14,5,6)
    sym(16,p['data_boundary']['symbol'],5,4);sym(17,'??0?$BSTask@_J@@QAE@XZ',0,typ=32);sym(18,'___security_cookie',0)
    sym(19,'__ehhandler$'+p['selected']['symbol'],4,8,32,3);sym(20,'___CxxFrameHandler3',0,typ=32);sym(21,'@__security_check_cookie@4',0,typ=32);secsym(22,6,5,3)
    sym(24,'__ehfuncinfo$'+p['selected']['symbol'],6,8,storage=3);sym(25,'__unwindtable$'+p['selected']['symbol'],6,storage=3)
    sym(54,'_omitted_fallback',0,typ=32);sym(55,'_omitted_weak',0,typ=32,storage=105,aux=struct.pack('<II10s',54,2,bytes(10)))
    secsym(64,16);secsym(66,17,2);sym(68,'_omitted_deleting_destructor',17,typ=32)
    for i in range(71):
        if i not in symbols and i not in auxslots:sym(i,'_omitted_data_'+str(i),7)
    obj=dict(sections=sections,symbols=symbols,symbol_count=71)
    raw=encode(obj);p['object_sha256']=eh.sha(raw);p['source_sha256']='b'*64
    bindings={9:(0x4490e0,'code'),13:(0x4405b0,'code'),16:(0x1016c10,'data'),17:(0x449090,'code'),18:(0x11c16bc,'crt-contract'),20:(0x501200,'crt-contract'),21:(0x501100,'crt-contract')}
    context=dict(object_sha256=eh.sha(raw),source_sha256='b'*64,inputs=p['inputs'],fields_complete=True,missing_fields_complete=True,missing_fields=[],parent_proof=dict(symbol=p['selected']['symbol'],address='0x00440540',size=101,section=3,value=0,verdict='match'),eh_pieces=[[0xeec240,0xeec248,True,'0x00440540',[]],[0xeec248,0xeec263,True,'0x00440540',[]]],data_boundary_proof=dict(symbol_index=16,original_base='0x01016c10',role='data',semantic_domain='data',contract_kind='vtable-view',exact=True,storage_defined=False),external_bindings={str(i):dict(base=base,role=role,proof_consistency='EXACT_OWN_SOURCE_RESOLUTION') for i,(base,role) in bindings.items()})
    context['external_bindings']={str(i):dict(base=base,**p['external_identities'][str(i)],proof_consistency='EXACT_OWN_SOURCE_RESOLUTION') for i,(base,_) in bindings.items()}
    context['shared_base_identities']=[dict(base=b['base'],role=b['role'],semantic_domain=b['semantic_domain'],contract_kind=b['contract_kind'],identity_consistency='EXACT_BASE_ROLE_RESOLUTION') for b in context['external_bindings'].values()]
    context['core_unit']=dict(functions=[dict(address='0x00440540',symbol=p['selected']['symbol'],size=101)],symbols={symbols[i]['name']:hex(base) for i,(base,role) in bindings.items()})
    context['core_unit']['symbols'][symbols[19]['name']]='0x00eec248'
    context['core_names']={}
    context['reference_identity_sha256']='c'*64
    locations={3:0x440540,4:0xeec240,6:0x11401cc};chunks={}
    for sn in (3,4,6):
        data=bytearray(sections[sn]['payload'])
        for off,index,kind in sections[sn]['relocs']:
            target=symbols[index];base=bindings[index][0] if index in bindings else locations[target['section']]+target['value']
            value=(base-locations[sn]-off-4)&0xffffffff if kind==20 else base
            struct.pack_into('<I',data,off,value)
        chunks[locations[sn]]=bytes(data)
    class Reference:
        def read(self,at,size):
            for base,data in chunks.items():
                if base<=at and at+size<=base+len(data):return data[at-base:at-base+size]
            raise ValueError('authored reference bounds')
    return obj,raw,p,context,Reference()


def encode(obj):
    strings=bytearray(4);records=bytearray()
    def name(n):
        n=n.encode()
        if len(n)<=8:return n.ljust(8,b'\0')
        off=len(strings);strings.extend(n+b'\0');return struct.pack('<II',0,off)
    for i,s in sorted(obj['symbols'].items()):records.extend(struct.pack('<8sIhHBB',name(s['name']),s['value'],s['section'],s['type'],s['storage'],s['aux_count'])+s['aux'])
    pos=20+40*len(obj['sections']);headers=bytearray();body=bytearray()
    for sn,s in sorted(obj['sections'].items()):
        raw=pos;body.extend(s['payload']);pos+=len(s['payload']);rp=pos if s['relocs'] else 0
        for row in s['relocs']:body.extend(struct.pack('<IIH',*row));pos+=10
        headers.extend(struct.pack('<8sIIIIIIHHI',s['name'].encode().ljust(8,b'\0'),0,0,s['size'],raw,rp,0,len(s['relocs']),0,s['flags']))
    struct.pack_into('<I',strings,0,len(strings));return struct.pack('<HHIIIHH',0x14c,len(obj['sections']),0,pos,obj['symbol_count'],0,0)+headers+body+records+strings


def contract_for(plan):
    provenance=dict(object_sha256=plan['object_sha256'],source_sha256=plan['source_sha256'],recipe_id=plan['recipe_id'],recipe_index=69,
        producer_manifest_sha256=plan['inputs']['manifest'],retained_proof_sha256=plan['inputs']['retained'],recipe_manifest_sha256=plan['inputs']['recipes'],
        selection_sha256=plan['inputs']['selection'],binding_sha256=plan['inputs']['binding'],reference_identity_sha256=plan['reference_identity_sha256'],
        optional_function_index_present=False,generated_eh_field_witnesses_sha256=eh.digest(plan.get('generated_eh_field_witnesses',[])),observer_sha256='d'*64,dependency_tools_sha256={name:'d'*64 for name in ('tools/rebuild/expanded_root_code_closure.py','tools/rebuild/root_code_closure.py','tools/rebuild/coff_code_archive.py')},recipe_unit_sha256='f'*64,binding_details_sha256='a'*64)
    fields=[dict(physical_section=3,function_va=plan['selected']['original_address'],coff_relocation=dict(offset=f['offset'],symbol_index=f['target_index'],kind=f['kind'],addend=f['addend']&0xffffffff),
        derived_source_symbol_base_va=hex(f['original_base']),exact_original_target_va=hex(f['original_target']),proof_consistency='EXACT_OWN_SOURCE_RESOLUTION') for f in plan['fields'] if f['section']==3]
    return dict(recipe_id=plan['recipe_id'],roots=[plan['selected']],export_policy='selected-code-only-no-source-initializers-v1',
        expanded_retention_contract=eh.expanded_contract(plan),generated_eh_field_witnesses=copy.deepcopy(plan.get('generated_eh_field_witnesses',[])),parent_eh=plan['parent_EH'],missing_fields=[],fields=fields,
        verified_match=True,fields_complete=True,missing_fields_complete=True,unit_proofs_complete=True,provenance=provenance)


def generic_for(plan,obj):
    contract=contract_for(plan)
    edges=[dict(kind='AUTHORED_FULL_GRAPH',source=1,target=2)]
    scope=dict(policy_id=eh.EXPANDED,export_policy=contract['export_policy'],roots=[plan['selected']],requested_dependency_retention=plan['retained_sections'],
        retained_section_indices=plan['retained_sections'],retained_primary_indices=plan['retained_primary_indices'],retained_physical_slots=plan['retained_physical_slots'],
        object_sha256=plan['object_sha256'],provenance_sha256=eh.digest(contract['provenance']),contract_identity_sha256=eh.digest(contract),
        expanded_retention_contract_sha256=eh.digest(contract['expanded_retention_contract']),edges_sha256=eh.digest(edges),physical_universe_sha256=eh.digest(plan['universe']),generated_eh_field_witnesses_sha256=eh.digest(plan.get('generated_eh_field_witnesses',[])))
    sections=[dict(index=i,disposition='AUTHORED_RETAIN_OR_OMIT') for i in obj['sections']]
    symbols=[dict(index=i,disposition='AUTHORED_RETAIN_OR_OMIT') for i in obj['symbols']]
    next(s for s in symbols if s['index']==55).update(disposition='OMIT_UNREACHABLE_WEAK_CANDIDATE',decoded_auxiliary=dict(kind='WEAK_EXTERNAL',fallback=54,search=2))
    blockers=eh.extension_obligations(plan);ids=[b['blocker_id'] for b in blockers]
    return dict(schema_version=1,policy_id=eh.EXPANDED,expanded_interface=eh.EXPANDED,requested_dependency_retention=plan['retained_sections'],
        roots=[plan['selected']],physical_universe=plan['universe'],generated_eh_field_witnesses=copy.deepcopy(plan.get('generated_eh_field_witnesses',[])),external_reference_contracts=copy.deepcopy(plan['external_obligations']),shared_base_identities=copy.deepcopy(plan['shared_base_identities']),contract_identity_sha256=eh.digest(contract),provenance=contract['provenance'],
        retained_section_indices=plan['retained_sections'],retained_runtime_section_indices=[3,4,6],retained_primary_indices=plan['retained_primary_indices'],retained_physical_slots=plan['retained_physical_slots'],
        dependency_field_observations=plan['dependency_field_observations'],parent_EH=plan['parent_EH'],
        closure_observed=False,root_closure_candidate=False,serialization_candidate=False,full_serialization_eligible=False,emission_performed=False,
        graph_observation_complete=True,edges=edges,sections=sections,symbols=symbols,blockers=blockers,
        omission_subcertificate=dict(policy_id=eh.EXPANDED,scope=scope,scope_sha256=eh.digest(scope),graph_observation_complete=True,
        disposition_sha256=eh.digest(dict(sections=sections,symbols=symbols)),unresolved_blocker_ids=ids,exact_EH_SafeSEH_extension_obligation_ids=ids,omission_approved=False),**eh.FALSE)


class EHCodeClosureTests(unittest.TestCase):
    def observed(self):
        obj,raw,p,c,r=fixture();return obj,raw,p,c,r,eh.observe_component(raw,p,c,r)
    def test_parent_owned_graph_and_whole_registry(self):
        _,_,_,_,_,plan=self.observed();self.assertEqual(len(plan['fields']),11);self.assertEqual(plan['undefined_conversions'],[16]);self.assertEqual(plan['state_transitions'][0]['to_state'],-1);self.assertFalse(plan['runtime_eligible'])
    def test_roundtrip_bijections_registry_and_only_root_export(self):
        obj,raw,p,c,r,plan=self.observed();g=generic_for(plan,obj);decision=eh.compose(plan,g,copy.deepcopy(g),contract_for(plan));out,receipt=eh.serialize_authored_component(raw,plan,decision);parsed=eh.coff.parse(out)
        self.assertEqual(len(receipt['maps']['symbol_map'])+len(receipt['maps']['auxiliary_map']),parsed['symbol_count'])
        self.assertNotEqual(receipt['safeseh']['old_index'],receipt['safeseh']['new_index']);self.assertEqual(len(eh.coff.exports(out)),1)
        converted=parsed['symbols'][receipt['maps']['symbol_map'][16]];self.assertEqual((converted['section'],converted['value'],converted['storage']),(0,0,2))
        for old in (3,4,6):self.assertEqual(parsed['sections'][receipt['maps']['section_map'][old]]['payload'],obj['sections'][old]['payload'])
    def test_ordinary_v1_and_missing_recompute_stay_blocked(self):
        _,_,_,_,_,plan=self.observed()
        self.assertEqual(eh.compose(plan,dict(policy_id='root-code-closure-observation-v1'),None)['blockers'][0]['code'],'MISSING_EXPANDED_ROOT_CERTIFICATE')
        with patch.dict(sys.modules,{'expanded_root_code_closure':None}):
            self.assertFalse(eh.recompute_and_compose(plan,None,None,None)['serialization_plan_ready'])
    def test_changed_expanded_scope_or_recompute_rejected(self):
        obj,_,_,_,_,plan=self.observed();g=generic_for(plan,obj);bad=copy.deepcopy(g);bad['requested_dependency_retention']=[1,3]
        with self.assertRaises(ValueError):eh.compose(plan,g,bad,contract_for(plan))
        with self.assertRaises(ValueError):eh.compose(plan,bad,copy.deepcopy(bad),contract_for(plan))
    def test_no_blanket_discharge_of_unknown_or_other_blocker(self):
        for code in ('UNKNOWN_HIDDEN_AUXILIARY_INDICES','REACHABLE_WEAK_REQUIRES_POLICY','ORIGINAL_MISSING_FIELDS','CANONICAL_COLLISION'):
            obj,_,_,_,_,plan=self.observed();g=generic_for(plan,obj);b=dict(code=code,evidence=55);b['blocker_id']=eh.digest(b);g['blockers'].append(b)
            with self.assertRaises(ValueError):eh.compose(plan,g,copy.deepcopy(g),contract_for(plan))
    def test_missing_duplicate_or_wrong_blocker_identity_rejected(self):
        for mode in ('missing','duplicate','wrong'):
            obj,_,_,_,_,plan=self.observed();g=generic_for(plan,obj)
            if mode=='missing':g['blockers'].pop()
            elif mode=='duplicate':g['blockers'].append(copy.deepcopy(g['blockers'][0]))
            else:g['blockers'][0]['evidence']['child']=5;g['blockers'][0]['blocker_id']=eh.digest({k:v for k,v in g['blockers'][0].items() if k!='blocker_id'})
            with self.assertRaises(ValueError):eh.compose(plan,g,copy.deepcopy(g),contract_for(plan))
    def test_unproved_weak_omission_or_incomplete_disposition_rejected(self):
        for mode in ('weak','universe'):
            obj,_,_,_,_,plan=self.observed();g=generic_for(plan,obj)
            if mode=='weak':next(x for x in g['symbols'] if x['index']==55)['decoded_auxiliary']['fallback']=9
            else:g['symbols'].pop()
            g['omission_subcertificate']['disposition_sha256']=eh.digest(dict(sections=g['sections'],symbols=g['symbols']))
            with self.assertRaises(ValueError):eh.compose(plan,g,copy.deepcopy(g),contract_for(plan))
    def test_false_piece_without_text_warning_and_subobja_negative(self):
        _,raw,p,c,r=fixture();c['eh_pieces'][0][2]=False
        with self.assertRaisesRegex(ValueError,'FAILED_LOCAL_EH_PIECE'):eh.observe_component(raw,p,c,r)
        p['selected']['original_address']='0x0043fd40'
        with self.assertRaises(ValueError):eh.observe_component(raw,p,c,r)
    def test_missing_original_fields_and_data_boundary_rejected(self):
        for mode in ('missing','boundary'):
            _,raw,p,c,r=fixture()
            if mode=='missing':c['missing_fields']=[dict(offset=58)]
            else:c['data_boundary_proof']['exact']=False
            with self.assertRaises(ValueError):eh.observe_component(raw,p,c,r)
    def test_shared_registry_unknown_directive_and_wrong_index(self):
        for mode in ('mixed','directive','auxindex'):
            obj,raw,p,c,r=fixture()
            if mode=='mixed':obj['sections'][16].update(size=8,payload=struct.pack('<II',19,68))
            elif mode=='directive':obj['sections'][1]['payload']+=b' /ALTERNATENAME:a=b';obj['sections'][1]['size']=len(obj['sections'][1]['payload'])
            else:obj['sections'][16]['payload']=struct.pack('<I',11)
            raw=encode(obj);p['object_sha256']=c['object_sha256']=eh.sha(raw)
            with self.assertRaises(ValueError):eh.observe_component(raw,p,c,r)
    def test_stale_parent_association_and_missing_state_rejected(self):
        for mode in ('association','state'):
            obj,raw,p,c,r=fixture()
            if mode=='association':a=bytearray(obj['symbols'][10]['aux']);struct.pack_into('<h',a,12,5);obj['symbols'][10]['aux']=bytes(a)
            else:obj['sections'][6]['payload']=bytes(44)
            raw=encode(obj);p['object_sha256']=c['object_sha256']=eh.sha(raw)
            with self.assertRaises(ValueError):eh.observe_component(raw,p,c,r)
    def test_runtime_promotion_or_uncomposed_serialization_rejected(self):
        obj,raw,_,_,_,plan=self.observed();g=generic_for(plan,obj);decision=eh.compose(plan,g,copy.deepcopy(g),contract_for(plan));decision['runtime_eligible']=True
        with self.assertRaises(ValueError):eh.serialize_authored_component(raw,plan,decision)
        with self.assertRaises(ValueError):eh.serialize_authored_component(raw,plan,dict(serialization_plan_ready=False))
    def test_shared_canonical_identity_uses_only_shared_role(self):
        _,_,_,_,_,plan=self.observed();names=dict(plan['namespace'])
        for b in plan['external_obligations']:
            self.assertEqual(names[b['symbol_index']],eh.unresolved('0x%08x'%b['base'],b['role']))
        self.assertEqual(next(b for b in plan['external_obligations'] if b['symbol_index']==16)['role'],'data')
        crt=[b for b in plan['external_obligations'] if b['role']=='crt-contract']
        self.assertEqual({b['semantic_domain'] for b in crt},{'code'})
        cookie=next(b for b in plan['external_obligations'] if b['symbol_index']==18)
        self.assertEqual((cookie['role'],cookie['semantic_domain'],cookie['contract_kind']),('data','data','security-cookie'))
        self.assertEqual(len({b['contract_kind'] for b in crt}),2)
    def test_same_base_equal_identity_shares_name(self):
        declarations={1:dict(role='code',semantic_domain='code',contract_kind='ordinary-function'),2:dict(role='code',semantic_domain='code',contract_kind='ordinary-function')}
        bindings={i:dict(base=123,**d,proof_consistency='EXACT_OWN_SOURCE_RESOLUTION') for i,d in declarations.items()}
        shared=[dict(base=123,**declarations[1],identity_consistency='EXACT_BASE_ROLE_RESOLUTION')]
        eh.validate_external_identities(bindings,declarations,shared)
        self.assertEqual(eh.unresolved('0x0000007b',bindings[1]['role']),eh.unresolved('0x0000007b',bindings[2]['role']))
    def test_ambiguous_domain_subtype_and_unproved_shared_identity_rejected(self):
        for mode in ('role','domain','subtype','missing','unproved','unknown'):
            _,raw,p,c,r=fixture()
            if mode=='missing':c['shared_base_identities']=[]
            elif mode=='unproved':c['shared_base_identities'][0]['identity_consistency']='guess'
            else:
                row=copy.deepcopy(next(b for b in c['shared_base_identities'] if b['contract_kind']=='security-cookie'))
                if mode=='role':row['role']='crt-contract'
                elif mode=='domain':row['semantic_domain']='code'
                elif mode=='subtype':row['contract_kind']='security-cookie-check'
                else:row['role']='crt-data'
                c['shared_base_identities'].append(row)
            with self.assertRaises(ValueError):eh.observe_component(raw,p,c,r)

    def test_full_contract_missing_or_stale_parent_provenance_rejected(self):
        for mode in ('missing-contract','missing-parent','duplicate-parent','parent-target','reference','index','tools','source'):
            obj,_,_,_,_,plan=self.observed();g=generic_for(plan,obj);contract=contract_for(plan)
            if mode=='missing-contract':contract=None
            elif mode=='missing-parent':contract['fields'].pop()
            elif mode=='duplicate-parent':contract['fields'][1]=copy.deepcopy(contract['fields'][0])
            elif mode=='parent-target':contract['fields'][0]['exact_original_target_va']='0x12345678'
            elif mode=='reference':contract['provenance']['reference_identity_sha256']='b'*64
            elif mode=='index':contract['provenance']['optional_function_index_present']=True
            elif mode=='tools':contract['provenance']['dependency_tools_sha256']={}
            else:contract['provenance']['source_sha256']='a'*64
            with self.assertRaises(ValueError):eh.compose(plan,g,copy.deepcopy(g),contract)
    def test_exact_dependency_contract_and_unpromoted_generic_flags(self):
        for mode in ('field','target','parent','universe','scope','candidate','complete','contract-hash','witness-output','external-output','shared-output','witness-scope'):
            obj,_,_,_,_,plan=self.observed();g=copy.deepcopy(generic_for(plan,obj));contract=contract_for(plan)
            if mode=='field':contract['expanded_retention_contract']['dependency_field_observations'].pop()
            elif mode=='target':g['dependency_field_observations'][0]['target_symbol']['section']=6
            elif mode=='parent':g['parent_EH'][0][2]=False
            elif mode=='universe':g['physical_universe']['physical_slots'].pop()
            elif mode=='scope':g['omission_subcertificate']['scope']['expanded_retention_contract_sha256']='a'*64
            elif mode=='candidate':g['root_closure_candidate']=True
            elif mode=='complete':g['omission_subcertificate']['graph_observation_complete']=False
            elif mode=='witness-output':g['generated_eh_field_witnesses']=[dict(family='forged')]
            elif mode=='external-output':g['external_reference_contracts'][0]['role']='data'
            elif mode=='shared-output':g['shared_base_identities'].pop()
            elif mode=='witness-scope':
                g['omission_subcertificate']['scope']['generated_eh_field_witnesses_sha256']='a'*64
                g['omission_subcertificate']['scope_sha256']=eh.digest(g['omission_subcertificate']['scope'])
            else:g['contract_identity_sha256']='a'*64
            with self.assertRaises(ValueError):eh.compose(plan,g,copy.deepcopy(g),contract)
    def test_recompute_uses_separate_expanded_producer(self):
        import types
        obj,_,_,_,_,plan=self.observed();g=generic_for(plan,obj);contract=contract_for(plan);calls=[]
        def producer(observed_obj,observed_contract,requested_dependency_retention):
            calls.append((observed_obj,observed_contract,requested_dependency_retention));return copy.deepcopy(g)
        module=types.SimpleNamespace(__file__=str(ROOT/'tools/rebuild/expanded_root_code_closure.py'),EXPANDED_EH_INTERFACE=eh.EXPANDED,observe_requested_dependency_retention=producer)
        with patch.dict(sys.modules,{'expanded_root_code_closure':module}),patch.object(eh,'file_sha',return_value='d'*64):
            decision=eh.recompute_and_compose(plan,g,obj,contract)
        self.assertTrue(decision['structural_composition_complete']);self.assertTrue(decision['serialization_plan_ready']);self.assertTrue(decision['source_files_verified']);self.assertEqual(calls,[(obj,contract,[1,3,4,6,16])])
        self.assertFalse(g['closure_observed']);self.assertFalse(g['root_closure_candidate']);self.assertFalse(g['full_serialization_eligible'])

    def test_stale_or_swapped_producer_and_dependencies_rejected(self):
        import types
        for mode in ('module','observer','dependency','missing-dependencies'):
            obj,_,_,_,_,plan=self.observed();contract=contract_for(plan);g=generic_for(plan,obj)
            module=types.SimpleNamespace(__file__=str(ROOT/'tools/rebuild/expanded_root_code_closure.py'),EXPANDED_EH_INTERFACE=eh.EXPANDED,observe_requested_dependency_retention=lambda *a,**k:g)
            if mode=='module':module.__file__=str(ROOT/'tools/rebuild/foreign.py')
            elif mode=='observer':contract['provenance']['observer_sha256']='a'*64
            elif mode=='dependency':contract['provenance']['dependency_tools_sha256']['tools/rebuild/root_code_closure.py']='a'*64
            else:contract['provenance']['dependency_tools_sha256']={'tools/rebuild/expanded_root_code_closure.py':'d'*64}
            with patch.dict(sys.modules,{'expanded_root_code_closure':module}),patch.object(eh,'file_sha',return_value='d'*64):
                with self.assertRaises(ValueError):eh.recompute_and_compose(plan,g,obj,contract)
    def test_forged_decision_and_real_object_emission_rejected(self):
        obj,raw,_,_,_,plan=self.observed();g=generic_for(plan,obj);decision=eh.compose(plan,g,copy.deepcopy(g),contract_for(plan))
        self.assertFalse(decision['serialization_plan_ready']);self.assertEqual(decision['blockers'],[dict(code='PRODUCER_FILES_NOT_VERIFIED')])
        forged=dict(serialization_plan_ready=False,synthetic_serialization_plan_ready=True,plan_sha256=eh.digest(plan))
        with self.assertRaises(ValueError):eh.serialize_authored_component(raw,plan,forged)
        with self.assertRaises(ValueError):eh.serialize_component(raw,plan,forged)
        decision['proof']['contract']['fields'].pop()
        with self.assertRaises(ValueError):eh.serialize_authored_component(raw,plan,decision)
        with patch.object(eh,'sha',return_value=eh.NATIVE_OBJECT):
            with self.assertRaisesRegex(ValueError,'authored-only helper rejects real IOTask object'):eh.serialize_authored_component(raw,plan,forged)

    def test_old_cookie_crt_namespace_counterexample_stays_rejected(self):
        _,raw,p,c,r=fixture();c['external_bindings']['18']['role']='crt-contract'
        for row in c['shared_base_identities']:
            if row['contract_kind']=='security-cookie':row['role']='crt-contract'
        with self.assertRaises(ValueError):eh.observe_component(raw,p,c,r)

    def test_input_hash_and_payload_change_rejected(self):
        _,raw,p,c,r=fixture();raw=raw[:-1]+bytes([1])
        with self.assertRaises(ValueError):eh.observe_component(raw,p,c,r)

if __name__=='__main__':unittest.main()
