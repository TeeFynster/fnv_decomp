"""Original invented metadata/COFF only; no actual Game observation/emission."""
import copy
from collections import Counter
import gzip
import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import data_arena_projection as arena


def fixture():
    policy=dict(schema_version=1,policy_id=arena.FORMAT,allowed_sections=arena.SECTIONS,
        roles=sorted(arena.ROLES),exact_target_addend=0,identity_bridges=[],adjacency_contracts=[],
        anchors_only=True,max_fragment_bytes=1024,selected_fragments=[],projection_enabled=False,
        normalized_evidence_sha256=None,input_pins={'reference':'a'*64},implementation_pins={},**arena.FALSE)
    a=dict(arena_id='section-1',section='.data',start=0x1000,size=32,raw_size=16,raw_backed=16,
        virtual_zero=16,raw_padding=0,flags=0xc0000040,alignment=16,raw_sha256='b'*64)
    domains=[dict(domain_id='raw',arena_id=a['arena_id'],start=0x1000,end=0x1010,backing='raw',
                  families=['ORDINARY_UNCLASSIFIED'],overlap=False),
             dict(domain_id='zero',arena_id=a['arena_id'],start=0x1010,end=0x1020,backing='virtual-zero',
                  families=['ORDINARY_UNCLASSIFIED'],overlap=False)]
    field=dict(field_id='field',arena_id=a['arena_id'],site=0x1004,target=0x2000,width=4,kind='HIGHLOW',
        roles=['data'],target_known=True,source_symbol_base=None,source_addend=None,
        base_basis='exact_highlow_target',addend=0,representation='absolute32')
    evidence=dict(schema_version=1,kind='normalized-data-arena-evidence',provenance=policy['input_pins'],
        optional_function_index_present=False,fields_complete=True,domains_complete=True,identity_bridges=[],
        arenas=[a],domains=domains,fields=[field],relationships=[],missing_fields=[])
    payload=struct.pack('<4I',0x401234,0x2000,0x12345678,9)
    return policy,evidence,payload


class ProjectionTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory();self.addCleanup(self.temp.cleanup);self.root=Path(self.temp.name)

    def plan(self):
        p,e,b=fixture();return p,arena.build_plan(e,p),b

    def gate(self,p,plan,selection=None):
        p=copy.deepcopy(p);p['projection_enabled']=True
        p['selected_fragments']=selection if selection is not None else [f['fragment_id'] for f in plan['fragments']]
        r=dict(kind='data-arena-private-projection-review',approved=True,reviewer='independent',root_authorized=True,
            plan_sha256=arena.digest(plan),policy_sha256=arena.digest(p),selected_fragments=p['selected_fragments'])
        return p,r

    def test_geometry_separate_raw_zero_no_typed_or_contiguous_claim(self):
        p,plan,_=self.plan();self.assertEqual(len(plan['fragments']),2)
        self.assertEqual([f['backing'] for f in plan['fragments']],['raw','virtual-zero'])
        self.assertTrue(all(f['object_extent'] is None and not f['adjacency_to_other_fragments_proved'] for f in plan['fragments']))
        self.assertEqual(plan['fields'][0]['state'],'symbolic-unresolved');arena.no_approval(plan)
        p2,r=self.gate(p,plan)
        self.assertEqual(arena.build_plan(fixture()[1],p2)['fragments'][0]['fragment_id'],plan['fragments'][0]['fragment_id'])

    def test_malformed_geometry_overlap_padding_protection_alignment(self):
        for change in ({'virtual_zero':15},{'raw_backed':15},{'raw_padding':1},{'flags':0xe0000060},
                       {'alignment':3},{'start':0x1001},{'section':'.text'}):
            p,e,_=fixture();e['arenas'][0].update(change)
            with self.subTest(change=change),self.assertRaises(ValueError):arena.build_plan(e,p)
        p,e,_=fixture();e['arenas'].append(dict(e['arenas'][0],arena_id='other'))
        with self.assertRaises(ValueError):arena.build_plan(e,p)

    def test_domain_gaps_overlaps_raw_zero_straddle_unknown_arena(self):
        for change in ({'start':0x1001},{'end':0x1011},{'backing':'virtual-zero'},{'arena_id':'unknown'}):
            p,e,_=fixture();e['domains'][0].update(change)
            with self.assertRaises(ValueError):arena.build_plan(e,p)

    def test_special_source_owner_and_conflict_are_quarantined(self):
        for family in ('FRESH_IAT_CELL','FRESH_NORMAL_CRT_STATE','STATIC_TLS','SOURCE_PROJECTION_CANDIDATE','LOADER_METADATA'):
            p,e,_=fixture();e['domains'][0]['families']=[family];plan=arena.build_plan(e,p)
            self.assertFalse(plan['fragments'][0]['admitted']);self.assertEqual(plan['fields'][0]['state'],'quarantined')
            enabled,review=self.gate(p,plan)
            with self.assertRaises(ValueError):arena.selected_plan(plan,enabled,review)
        p,e,_=fixture();e['domains'][0]['overlap']=True
        self.assertFalse(arena.build_plan(e,p)['fragments'][0]['admitted'])

    def test_exact_roles_remain_distinct_same_address(self):
        names=[]
        for role in sorted(arena.ROLES):
            p,e,_=fixture();e['fields'][0]['roles']=[role];f=arena.build_plan(e,p)['fields'][0]
            names.append(f['undefined']);self.assertEqual(f['role'],role)
            self.assertEqual(f['undefined'],arena.namespace.unresolved('0x00002000',role))
        self.assertEqual(len(set(names)),4)

    def test_ambiguous_unknown_target_role_and_nonabsolute_are_quarantined(self):
        for change in ({'roles':[]},{'roles':['data','iat-cell']},{'roles':['tls']},{'target_known':False},{'representation':'RVA'}):
            p,e,_=fixture();e['fields'][0].update(change);plan=arena.build_plan(e,p)
            self.assertEqual(plan['fields'][0]['state'],'quarantined')
            enabled,r=self.gate(p,plan)
            with self.assertRaises(ValueError):arena.selected_plan(plan,enabled,r)

    def test_fields_overlap_bounds_kind_and_zero_backing(self):
        for change in ({'site':0x100e},{'site':0x1020},{'width':8},{'kind':'DIR64'},{'addend':4},{'source_symbol_base':0x1ffc,'source_addend':4}):
            p,e,_=fixture();e['fields'][0].update(change)
            with self.assertRaises(ValueError):arena.build_plan(e,p)
        p,e,_=fixture();e['fields'].append(dict(e['fields'][0],field_id='other',site=0x1005))
        with self.assertRaises(ValueError):arena.build_plan(e,p)
        p,e,_=fixture();e['fields'][0]['site']=0x1010
        self.assertIn('virtual-zero HIGHLOW unexplained',arena.build_plan(e,p)['fields'][0]['blockers'])

    def test_bridges_adjacency_and_relationship_approval_rejected(self):
        for key in ('identity_bridges','adjacency_contracts'):
            p,e,_=fixture();p[key]=[{'proved':True}]
            with self.assertRaises(ValueError):arena.build_plan(e,p)
        p,e,_=fixture();e['relationships']=[dict(kind='cross-fragment',proved=True)]
        with self.assertRaises(ValueError):arena.build_plan(e,p)
        e['relationships'][0]['proved']=False
        self.assertFalse(arena.build_plan(e,p)['relationships'][0]['proved'])

    def test_stale_missing_index_and_false_approval_inputs(self):
        for key,value in (('provenance',{}),('optional_function_index_present',True),('fields_complete',False),('domains_complete',False)):
            p,e,_=fixture();e[key]=value
            with self.assertRaises(ValueError):arena.build_plan(e,p)
        p,e,_=fixture();p['runtime_eligible']=True
        with self.assertRaises(ValueError):arena.build_plan(e,p)

    def test_coff_raw_numeric_preserved_symbolic_fields_and_true_bss(self):
        p,plan,payload=self.plan()
        for f in plan['fragments']:
            fields=[r for r in plan['fields'] if r['fragment_id']==f['fragment_id']]
            data=payload if f['backing']=='raw' else b'';path=self.root/(f['backing']+'.obj')
            path.write_bytes(arena.object_bytes(f,fields,data));report=arena.validate_object(path,f,fields,data)
            self.assertEqual(report['size'],16)
            coff,_,_,_=arena.strict_object(path)
            if data:
                self.assertEqual(struct.unpack_from('<4I',coff.data,struct.unpack_from('<I',coff.data,40)[0]),(0x401234,0,0x12345678,9))
            else:self.assertEqual(struct.unpack_from('<I',coff.data,40)[0],0)

    def test_independent_reparse_rejects_payload_kind_symbol_geometry_drift(self):
        _,plan,payload=self.plan();f=plan['fragments'][0];fields=plan['fields'];original=arena.object_bytes(f,fields,payload)
        for offset,value in ((60,0),(60+len(payload)+8,20),(56,0x60)):
            data=bytearray(original);data[offset]=value;path=self.root/'bad.obj';path.write_bytes(data)
            with self.assertRaises(ValueError):arena.validate_object(path,f,fields,payload)
        bad=bytearray(original);struct.pack_into('<I',bad,64,0x2000);path.write_bytes(bad)
        with self.assertRaises(ValueError):arena.validate_object(path,f,fields,payload)

    def test_projection_disabled_stale_review_and_partial_metadata_preserved(self):
        p,plan,_=self.plan()
        with self.assertRaises(ValueError):arena.selected_plan(plan,p,{})
        enabled,r=self.gate(p,plan);self.assertEqual(len(arena.selected_plan(plan,enabled,r)),2)
        r['plan_sha256']='f'*64
        with self.assertRaises(ValueError):arena.selected_plan(plan,enabled,r)

    def test_synthetic_exclusive_publication_and_late_drift(self):
        p,plan,payload=self.plan();p,r=self.gate(p,plan);protected=self.root/'input';protected.write_bytes(b'original')
        bindings={str(protected):arena.sha(protected)};out=self.root/'projection'
        result=arena.project(plan,p,r,bindings,lambda f:payload,out)
        self.assertTrue(result['partial']);self.assertEqual(len(list(out.glob('*.obj'))),2)
        with self.assertRaises(ValueError):arena.project(plan,p,r,bindings,lambda f:payload,out)
        def drift(f):protected.write_bytes(b'changed');return payload
        with self.assertRaises(ValueError):arena.project(plan,p,r,bindings,drift,self.root/'late')
        self.assertFalse((self.root/'late').exists())

    def test_file_plan_requires_exact_normalized_evidence_and_collision_gate(self):
        p,e,_=fixture();ep,pp,out=[self.root/n for n in ('evidence.json','policy.json','plan.json')]
        ep.write_text(json.dumps(e));pp.write_text(json.dumps(p));bindings={str(ep):arena.sha(ep),str(pp):arena.sha(pp)}
        with self.assertRaises(ValueError):arena.publish_plan(ep,pp,out,bindings)
        p['normalized_evidence_sha256']=arena.sha(ep);pp.write_text(json.dumps(p));bindings[str(pp)]=arena.sha(pp)
        arena.publish_plan(ep,pp,out,bindings)
        with self.assertRaises(ValueError):arena.publish_plan(ep,pp,out,bindings)

    def test_actual_policy_defaults_to_empty_disabled_projection(self):
        path=Path(__file__).resolve().parents[2]/'runtime/data-arenas/unresolved-original-v1.json'
        p=json.loads(path.read_text());arena.policy_contract(p)
        self.assertFalse(p['projection_enabled']);self.assertEqual(p['selected_fragments'],[])

    def test_adapter_role_classification_preserves_special_and_conflicts(self):
        def row(families,classification='data',overlap=False):
            return dict(original_record=[0,0,classification,0,4,'raw',[]],target_view=dict(domain_evidence=[dict(families=families,unresolved_domain_overlap=overlap)]))
        self.assertEqual(arena.target_role(row(['FRESH_IAT_CELL'],'import-IAT')),['iat-cell'])
        self.assertEqual(arena.target_role(row(['FRESH_NORMAL_CRT_STATE'])),['crt-contract'])
        for families in (['STATIC_TLS'],['FRESH_IAT_CELL','FRESH_NORMAL_CRT_STATE']):self.assertEqual(arena.target_role(row(families)),[])
        self.assertEqual(arena.target_role(row(['ORDINARY_UNCLASSIFIED'],overlap=True)),[])

    def test_observation_gate_rejects_without_opening_any_pe(self):
        p,_,_=fixture()
        with patch.object(arena,'Pe') as reader:
            with self.assertRaises(ValueError):arena.adapt_saved({},p,'a'*64,self.root,{})
            reader.assert_not_called()

    def saved_adapter_inputs(self,*,bad_join=False,bad_counts=False):
        p,e,_=fixture();names=('ledger','ledger_details','data_plan','data_details','binding','binding_details',
            'recipes','manifest','retained','selection','imports','reference','image_check','owned_image')
        paths={n:self.root/n for n in names}
        for path in paths.values():path.write_text('{}')
        vals=[4,12,'data',0,4,'raw',[]]
        a=dict(event='ARENA_GEOMETRY',arena_id='section-1',section='.data',original_start=0x1000,
            logical_extent=32,raw_backed_extent=16,virtual_zero_extent=16,flags=0xc0000040,
            PE_section_alignment_observed=16,raw_padding_excluded=0,raw_section_sha256='b'*64)
        rows=[a]
        for d in e['domains']:
            rows.append(dict(event='DISJOINT_ARENA_DOMAIN',domain_id=d['domain_id'],arena_id='section-1',
                start=d['start'],end=d['end'],backing=d['backing'],families=d['families'],unresolved_domain_overlap=False))
        rows.append(dict(event='DATA_HIGHLOW_FIELD',site_identity=arena.digest(vals),original_record=vals,
            source_arena='section-1',original_site_va='0x00001004',original_target_va='0x0000100c',
            target_view=dict(domain_evidence=[],code_provider_candidates=[],code_ownership_ambiguous=False)))
        rows.append(dict(event='MISSING_FIELD_BLOCKER',original_missing_identity='unmodified'))
        rows.append(dict(event='UNRESOLVED_DOMAIN_OBLIGATIONS',obligations=['unproved lifecycle']))
        if bad_join:rows[3]['original_record']=list(vals);rows[3]['original_record'][1]+=4
        with gzip.open(paths['ledger_details'],'wt') as stream:
            for row in rows:stream.write(json.dumps(row)+'\n')
        with gzip.open(paths['data_details'],'wt') as stream:stream.write(json.dumps(vals)+'\n')
        identities=[dict(name='.data',sha256='b'*64)];probe=dict(hits=1,probes=1,digest='d'*64)
        dp=dict(image=dict(base=0x1000,size=32),detail_sha256=arena.sha(paths['data_details']),
            provenance=dict(nonexec_sections=identities,nonexec_digest='c'*64,reference_fingerprint=probe))
        paths['data_plan'].write_text(json.dumps(dp))
        paths['binding'].write_text(json.dumps(dict(details_sha256=arena.sha(paths['binding_details']))))
        paths['manifest'].write_text(json.dumps(dict(units=[],toolchains={})))
        paths['retained'].write_text(json.dumps(dict(inputs=dict(function_index_present=False,tools_sha256={}))))
        paths['selection'].write_text(json.dumps(dict(function_index_present=False)))
        pins={n:arena.sha(path) for n,path in paths.items() if n not in ('owned_image','ledger')}
        events=dict(Counter(row['event'] for row in rows))
        if bad_counts:events['DATA_HIGHLOW_FIELD']+=1
        ledger=dict(schema_version=1,kind='fnv-runtime-data-owner-ledger',status='analysis-only',
            inputs={n:pins[n] for n in ('data_plan','binding','recipes','manifest','retained','selection','imports','reference')},
            details_sha256=pins['ledger_details'],data_detail_sha256=pins['data_details'],binding_detail_sha256=pins['binding_details'],
            optional_function_index_present=False,summary=dict(events=events,data_fields=1,
                data_identity_sequence_sha256=hashlib.sha256(arena.canonical(vals)).hexdigest()),**arena.FALSE)
        paths['ledger'].write_text(json.dumps(ledger));pins['ledger']=arena.sha(paths['ledger']);p['input_pins']=pins
        review=dict(kind='data-arena-observation-review',approved=True,root_authorized=True,reviewer='independent',
            policy_sha256=arena.digest(p),source_sha256=arena.sha(arena.__file__),owned_image_sha256=arena.sha(paths['owned_image']))
        class FakePe:
            def __init__(self,path):
                self.base=0x1000;self.image_size=32;self.section_headers=[]
                self.sections=[dict(name='.data',rva=0,extent=32,raw_size=16,flags=0xc0000040,executable=False)]
            def nonexec_identity(self):return identities,'c'*64
            def unpack(self,fmt,offset):return (16,16) if fmt=='<II' else (0,)
            def close(self):pass
        return p,paths,review,FakePe,probe

    def test_saved_adapter_complete_synthetic_positive_preserves_events_and_fields(self):
        p,paths,review,reader,probe=self.saved_adapter_inputs()
        with patch.object(arena,'Pe',reader),patch.object(arena,'fingerprint',return_value=probe):
            e,bindings=arena.adapt_saved(paths,p,arena.sha(paths['owned_image']),self.root,review)
        plan=arena.build_plan(e,p)
        self.assertEqual(len(plan['fields']),1);self.assertEqual(len(plan['missing_fields']),1)
        self.assertEqual(plan['fields'][0]['original']['original']['ordinal'],4)
        self.assertEqual(e['retained_event_provenance']['fields_accounted'],1)
        self.assertEqual(len(e['retained_obligations']),2)
        self.assertEqual(len(plan['relationships']),5);arena.stable_inputs(bindings)

    def test_saved_adapter_rejects_missing_counts_original_field_join_and_image_geometry(self):
        for options in ({'bad_counts':True},{'bad_join':True}):
            p,paths,r,reader,probe=self.saved_adapter_inputs(**options)
            with patch.object(arena,'Pe',reader),patch.object(arena,'fingerprint',return_value=probe):
                with self.assertRaises(ValueError):arena.adapt_saved(paths,p,arena.sha(paths['owned_image']),self.root,r)
        p,paths,r,reader,probe=self.saved_adapter_inputs()
        class WrongPe(reader):
            def __init__(self,path):super().__init__(path);self.sections[0]['extent']=33
        with patch.object(arena,'Pe',WrongPe),patch.object(arena,'fingerprint',return_value=probe):
            with self.assertRaises(ValueError):arena.adapt_saved(paths,p,arena.sha(paths['owned_image']),self.root,r)


if __name__=='__main__':unittest.main()
