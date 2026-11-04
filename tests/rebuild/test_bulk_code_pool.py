"""Authored synthetic union/container tests; no game object or native tool reads."""
import copy
import io
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import bulk_code_pool as b
from test_coff_code_archive import section,symbol,aux,object_bytes,tiny


def fixture():
    direct=b' /DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES"'
    sections=[section('.drectve',direct,flags=0x100a00),
        section('.text',b'\0'*4+b'ONE!',relocs=[(0,8,6)]),section('.text',b'\0'*4+b'TWO!',relocs=[(0,8,6)])]
    symbols=[symbol('.drectve',1,storage=3,auxiliary=aux(len(direct),selection=0)),
        symbol('.text',2,storage=3,auxiliary=aux(8,1)),symbol('_root_one',2,typ=32),
        symbol('.text',3,storage=3,auxiliary=aux(8,1)),symbol('_root_two',3,typ=32),symbol('_shared_data',0),
        symbol('@comp.id',-1,value=8681481,storage=3),symbol('@feat.00',-1,value=1,storage=3)]
    return make(sections,symbols)


def make(sections,symbols):
    raw=object_bytes(sections,symbols);obj=b.coff.parse(raw);contracts=[]
    for sec,index,address in [(2,4,'0x00401000'),(3,7,'0x00402000')]:
        s=obj['symbols'][index];fields=[]
        for off,si,kind in obj['sections'][sec]['relocs']:
            target=obj['symbols'][si];base='0x01002000'
            if si==7:base='0x00402000'
            if si==4:base='0x00401000'
            if target['storage']==3 and not target['aux_count'] and target['section'] in (2,3):base='0x%08x'%(0x00401000+(target['section']-2)*0x1000+target['value'])
            bits=int.from_bytes(obj['sections'][sec]['payload'][off:off+4],'little');add=bits if kind==6 or bits<0x80000000 else bits-0x100000000
            row=dict(event='SELECTED_FUNCTION_COFF_RELOCATION',recipe_id='fixture-recipe',function_va=address,physical_section=sec,physical_offset=off,
                source_field_offset=off,coff_relocation=dict(offset=off,symbol_index=si,kind=kind,symbol=target['name'],symbol_section=target['section'],
                    symbol_value=target['value'],symbol_type=target['type'],symbol_storage=target['storage'],addend=bits),
                derived_source_symbol_base_va=base,exact_original_target_va='0x%08x'%((int(base,16)+add)&0xffffffff),
                classification='SELECTED_CODE_ENTRY' if si in (4,7) else 'ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER',
                proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',physical_field_overlap_count=1)
            fields.append(row)
        providers={'0x00401000':dict(recipe_id='fixture-recipe',object_sha256=b.raw_digest(raw),symbol_index=4),
                   '0x00402000':dict(recipe_id='fixture-recipe',object_sha256=b.raw_digest(raw),symbol_index=7)}
        contracts.append(dict(recipe_id='fixture-recipe',source_sha256='a'*64,object_sha256=b.raw_digest(raw),
            selected=dict(original_address=address,symbol=s['name'],symbol_index=index,section=sec,value=0,size=obj['sections'][sec]['size']),
            verified_match=True,fields_complete=True,missing_fields_complete=True,missing_fields=[],fields=fields,provider_identities=providers,literal_sections=[]))
    return raw,contracts


def fixture_parts():
    raw,_=fixture();obj=b.coff.parse(raw)
    sections=list(obj['sections'].values())
    symbols=[symbol(s['name'],s['section'],s['value'],s['type'],s['storage'],s['aux']) for s in obj['symbols'].values()]
    return sections,symbols


class UnionTests(unittest.TestCase):
    def codes(self,p):return {x['code'] for x in p['blockers']}

    def test_two_roots_shared_physical_reference_one_member(self):
        raw,contracts=fixture();p=b.plan_union(raw,contracts);self.assertTrue(p['eligible'],p['blockers'])
        self.assertEqual(p['counts'],dict(roots=2,code_bytes=16,literal_bytes=0,fields=2,unique_undefined_records=1))
        out,r=b.serialize_union(raw,contracts,p);obj=b.coff.parse(out)
        self.assertEqual(len(obj['sections']),3);self.assertEqual(len(r['exports']),2);self.assertEqual(len(r['undefined']),1)
        self.assertEqual(obj['sections'][2]['relocs'][0][1],obj['sections'][3]['relocs'][0][1])
        self.assertEqual([s['payload'] for i,s in obj['sections'].items() if i in (2,3)],[b'\0'*4+b'ONE!',b'\0'*4+b'TWO!'])
        with tempfile.TemporaryDirectory() as d:
            path=Path(d)/'union.obj';path.write_bytes(out);b.strict_reparse(path,out)

    def test_same_object_definition_wins_over_one_root_conversion(self):
        sections,symbols=fixture_parts();sections[1]['relocs']=[(0,7,20)]
        raw,contracts=make(sections,symbols);p=b.plan_union(raw,contracts)
        self.assertTrue(p['eligible'],p['blockers']);self.assertNotIn(7,p['undefined'])
        out,r=b.serialize_union(raw,contracts,p);target=b.coff.parse(out)['symbols'][r['maps']['symbol_map'][7]]
        self.assertEqual((target['section'],target['value']),(3,0))
        self.assertEqual(b.coff.parse(out)['sections'][2]['relocs'][0][2],20)

    def test_static_interior_label_keeps_real_offset(self):
        sections,symbols=fixture_parts();symbols.append(symbol('$inside',3,value=4,storage=3));sections[0]['payload']=sections[0]['payload']
        sections[1]['relocs']=[(0,11,6)]
        raw,contracts=make(sections,symbols);p=b.plan_union(raw,contracts);self.assertTrue(p['eligible'],p['blockers'])
        out,r=b.serialize_union(raw,contracts,p);label=b.coff.parse(out)['symbols'][r['maps']['symbol_map'][11]]
        self.assertEqual((label['section'],label['value'],label['storage']),(3,4,3));self.assertNotIn(label['name'],r['exports'])

    def test_placeholder_definition_converts_once_and_no_storage_retained(self):
        sections,symbols=fixture_parts();sections.append(section('.bss',b'UNOWNED',flags=0xc0300080));s=list(symbols[5]);s[2]=4;s[1]=2;symbols[5]=tuple(s)
        raw,contracts=make(sections,symbols);p=b.plan_union(raw,contracts);self.assertTrue(p['eligible'],p['blockers']);self.assertEqual(p['undefined'],[8])
        out,r=b.serialize_union(raw,contracts,p);obj=b.coff.parse(out)
        self.assertNotIn('.bss',[s['name'] for s in obj['sections'].values()]);self.assertEqual(obj['symbols'][r['maps']['symbol_map'][8]]['section'],0)

    def test_distinct_undefined_records_need_separate_certificate(self):
        sections,symbols=fixture_parts();symbols.append(symbol('_other_spelling',0));sections[2]['relocs']=[(0,11,6)]
        raw,contracts=make(sections,symbols);p=b.plan_union(raw,contracts)
        self.assertIn('REFERENCE_CERTIFICATE_REQUIRED',self.codes(p));self.assertFalse(p['eligible'])
        with self.assertRaisesRegex(ValueError,'blocked'):b.serialize_union(raw,contracts,p)
        bogus=dict(producer_sha256='b'*64,request={},certificate={},certificate_sha256='c'*64)
        self.assertIn('REFERENCE_CERTIFICATE_REQUIRED',self.codes(b.plan_union(raw,contracts,[bogus])))
        self.assertIn('CERTIFICATE_CONSUMPTION_FUTURE_SCOPE',self.codes(b.plan_union(raw,contracts,[bogus])))

    def test_real_producer_certificate_cannot_unlock_bulk_v1_or_old_candidate(self):
        # Use the certificate owner's actual authored fixture/schema, including
        # separate complete [1,2] and runtime [2] section sets. No guessed plan.
        from test_canonical_reference_groups import fixture as certificate_fixture
        import canonical_reference_groups as groups
        raw,request=certificate_fixture();certificate=groups.certify(raw,request)
        self.assertEqual(request['root_closure']['retained_section_indices'],[1,2])
        self.assertEqual(request['root_closure']['retained_runtime_section_indices'],[2])
        self.assertNotIn('symbol',certificate['root'])
        obj=b.coff.parse(raw);root=dict(request['root']);root.pop('recipe_id');root['symbol']=obj['symbols'][root['symbol_index']]['name']
        contract=dict(recipe_id=request['root']['recipe_id'],object_sha256=b.raw_digest(raw),source_sha256='a'*64,selected=root,
            verified_match=True,fields_complete=True,missing_fields_complete=True,fields=request['field_proofs'],missing_fields=[],literal_sections=[],
            provider_identities={request['group']['original_base']:request['group']['selected_provider_identity']})
        bundle=dict(request=request,certificate=certificate,certificate_sha256=groups.digest(certificate),producer_sha256=b.sha(Path(groups.__file__)))
        p=b.plan_union(raw,[contract],[bundle])
        self.assertFalse(p['eligible']);self.assertIn('CERTIFICATE_CONSUMPTION_FUTURE_SCOPE',self.codes(p))
        self.assertIn('FRESH_ROOT_BLOCKED',self.codes(p));self.assertIn('REFERENCE_CERTIFICATE_REQUIRED',self.codes(p))
        self.assertEqual(p['reference_certificates'],[])
        with self.assertRaisesRegex(ValueError,'blocked'):b.serialize_union(raw,[contract],p,[bundle])

    def test_mixed_definition_reference_group_remains_unsupported(self):
        sections,symbols=fixture_parts();symbols.append(symbol('_alias_to_second',0,typ=32));sections[1]['relocs']=[(0,11,20)]
        raw,contracts=make(sections,symbols);contracts[0]['fields'][0].update(classification='SELECTED_CODE_ENTRY',derived_source_symbol_base_va='0x00402000',exact_original_target_va='0x00402000')
        p=b.plan_union(raw,contracts);self.assertIn('MIXED_DEFINITION_REFERENCE_GROUP_UNSUPPORTED',self.codes(p))

    def test_conflicting_physical_base_is_not_cloned(self):
        raw,contracts=fixture();contracts[1]['fields'][0].update(derived_source_symbol_base_va='0x01003000',exact_original_target_va='0x01003000')
        p=b.plan_union(raw,contracts);self.assertIn('UNION_PHYSICAL_IDENTITY_CONFLICT',self.codes(p))

    def test_unsigned_and_signed_addends_survive(self):
        for kind,bits in [(6,0x100),(20,0xfffffff8)]:
            sections,symbols=fixture_parts();sections[1]['payload']=struct.pack('<I',bits)+b'ONE!';sections[1]['relocs']=[(0,8,kind)]
            raw,contracts=make(sections,symbols);out,r=b.serialize_union(raw,contracts)
            self.assertEqual(b.coff.parse(out)['sections'][2]['payload'],sections[1]['payload'])
            self.assertEqual(r['plan']['obligations'][0]['addend_bits'],bits)

    def test_whole_checked_literal_shared_by_two_roots_once(self):
        sections,symbols=fixture_parts();literal=b'AUTHORED';sections.append(section('.rdata',literal,flags=0x40401040))
        symbols.extend([symbol('.rdata',4,storage=3,auxiliary=aux(8,selection=2)),symbol('_literal',4)])
        # Existing primary slots9/10 are metadata; new section11,aux12,owner13.
        for section_ in sections[1:3]:section_['relocs']=[(0,13,6)]
        raw,contracts=make(sections,symbols)
        for c in contracts:
            c['literal_sections']=[4];c['fields'][0]['literal']=dict(extent=8,payload_sha256=b.raw_digest(literal),full_extent_equal=True,
                source_and_original_readonly=True,no_source_relocations_or_original_HIGHLOW=True)
            c['fields'][0]['classification']='COMPILER_LITERAL_FULL_READONLY_NONPOINTER_EQUALITY'
        out,r=b.serialize_union(raw,contracts);obj=b.coff.parse(out)
        self.assertEqual(len(obj['sections']),4);self.assertEqual(len(r['exports']),3);self.assertEqual(r['undefined'],[])
        self.assertEqual(r['plan']['counts']['literal_bytes'],8)
        bad=copy.deepcopy(contracts);bad[0]['fields'][0]['literal']['full_extent_equal']=False
        self.assertIn('FRESH_ROOT_BLOCKED',self.codes(b.plan_union(raw,bad)))

    def test_debug_exclusion_and_eh_association_block(self):
        for name,flags,blocked in [('.debug$F',0x42100,False),('.text$x',0x60501020,True)]:
            sections,symbols=fixture_parts();sections.append(section(name,b'metadata',flags=flags));symbols.append(symbol(name,4,storage=3,auxiliary=aux(8,selection=5,association=2)))
            raw,contracts=make(sections,symbols);p=b.plan_union(raw,contracts)
            self.assertEqual(p['eligible'],not blocked)
            if blocked:self.assertIn('UNION_ASSOCIATION_BLOCKED',self.codes(p))
            else:self.assertEqual(p['debug_exclusions'][0]['section'],4)

    def test_equal_literal_bytes_with_distinct_physical_owners_stay_distinct(self):
        sections,symbols=fixture_parts();literal=b'AUTHORED'
        for sec,name in [(4,'_literal_a'),(5,'_literal_b')]:
            sections.append(section('.rdata',literal,flags=0x40401040));symbols.extend([symbol('.rdata',sec,storage=3,auxiliary=aux(8,selection=2)),symbol(name,sec)])
        sections[1]['relocs']=[(0,13,6)];sections[2]['relocs']=[(0,16,6)]
        raw,contracts=make(sections,symbols)
        for i,c in enumerate(contracts):
            c['literal_sections']=[4+i];row=c['fields'][0];base='0x01002000' if i==0 else '0x01003000'
            row.update(derived_source_symbol_base_va=base,exact_original_target_va=base,classification='COMPILER_LITERAL_FULL_READONLY_NONPOINTER_EQUALITY',
                literal=dict(extent=8,payload_sha256=b.raw_digest(literal),full_extent_equal=True,source_and_original_readonly=True,no_source_relocations_or_original_HIGHLOW=True))
        out,r=b.serialize_union(raw,contracts);obj=b.coff.parse(out)
        self.assertEqual(len(r['exports']),4);self.assertEqual(len(set(r['exports'])),4)
        self.assertEqual(obj['sections'][4]['payload'],obj['sections'][5]['payload'])
        self.assertNotEqual(obj['symbols'][r['maps']['symbol_map'][13]]['name'],obj['symbols'][r['maps']['symbol_map'][16]]['name'])

    def test_stale_forged_plan_and_shared_section_fail(self):
        raw,contracts=fixture();p=b.plan_union(raw,contracts);p['bindings'][0][1]='_fnv_code_'+'0'*64
        with self.assertRaisesRegex(ValueError,'recompute'):b.serialize_union(raw,contracts,p)
        bad=copy.deepcopy(contracts);bad[1]['selected']['section']=2
        with self.assertRaisesRegex(ValueError,'shared selected'):b.plan_union(raw,bad)
        bad=copy.deepcopy(contracts);bad[1]['object_sha256']='b'*64
        with self.assertRaisesRegex(ValueError,'conflict'):b.plan_union(raw,bad)


class ContainerTests(unittest.TestCase):
    def members(self,root):
        spool=b.Spool(root/'spool',root/'members.jsonl')
        for i in range(5):spool.append('recipe%04d.obj'%i,tiny('_export%d'%i,b'authored'+bytes([i])),i,dict(root=i))
        rows=list(spool.members);spool.close();return rows

    def test_streamed_archive_identical_to_accepted_memory_writer(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);rows=self.members(root);b.inspect_spool(root/'spool',rows)
            result=b.write_shard(root/'spool',rows,root/'archive.lib');self.assertEqual(result['members'],5)
            with (root/'spool').open('rb') as f:
                members=[]
                for r in rows:f.seek(r['offset']);members.append((r['name'],f.read(r['length'])))
            self.assertEqual((root/'archive.lib').read_bytes(),b.coff.archive(members))
            self.assertEqual(result['exports'],b.coff.read_archive((root/'archive.lib').read_bytes())['index'])

    def test_deterministic_recipe_shards_and_global_export_collision(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);rows=self.members(root);a=b.shard_plan(rows,max_members=2);self.assertEqual([len(x) for x in a],[2,2,1])
            self.assertEqual(a,b.shard_plan(rows,max_members=2))
            cap=max(b.archive_layout([r])['size'] for r in rows)
            self.assertEqual(len(b.shard_plan(rows,max_bytes=cap)),5)
            bad=copy.deepcopy(rows);bad[4]['exports']=bad[0]['exports']
            with self.assertRaisesRegex(ValueError,'cross-shard'):b.shard_plan(bad,max_members=2)
            with self.assertRaisesRegex(ValueError,'indivisible'):b.shard_plan(rows,max_bytes=100)

    def test_member_number_and_offset_limits_without_filler_emission(self):
        # Metadata arithmetic only: these rows are never serialized as objects.
        rows=[dict(name='r%d.obj'%i,length=0,exports=['_e%d'%i],recipe_index=i) for i in range(65535)]
        self.assertEqual(len(b.archive_layout(rows)['offsets']),65535)
        with self.assertRaisesRegex(ValueError,'ordinal'):b.archive_layout(rows+[dict(rows[0],name='extra.obj')])
        with self.assertRaisesRegex(ValueError,'32-bit'):b.archive_layout([dict(name='huge.obj',length=0xffffffff,exports=['_x'])])
        with self.assertRaisesRegex(ValueError,'ceiling'):b.shard_plan([],max_members=65536)

    def test_spool_crash_tail_corruption_and_output_collision(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);rows=self.members(root)
            with self.assertRaisesRegex(ValueError,'exclusive'):b.Spool(root/'spool',root/'members.jsonl')
            with (root/'spool').open('ab') as f:f.write(b'uncommitted')
            with self.assertRaisesRegex(ValueError,'uncommitted'):b.inspect_spool(root/'spool',rows)
            with (root/'spool').open('r+b') as f:f.seek(rows[0]['offset']);f.write(b'X')
            with self.assertRaisesRegex(ValueError,'changed'):b.write_shard(root/'spool',rows,root/'partial.lib')
            self.assertTrue((root/'partial.lib').exists());self.assertFalse((root/'receipt.json').exists())
            with self.assertRaisesRegex(ValueError,'exclusive'):b.write_shard(root/'spool',rows,root/'partial.lib')

    def test_reparse_rejects_index_corruption_extra_bytes_and_padding(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);rows=self.members(root);path=root/'out.lib';b.write_shard(root/'spool',rows,path);raw=path.read_bytes()
            altered=bytearray(raw);struct.pack_into('>I',altered,72,0);path.write_bytes(altered)
            with self.assertRaisesRegex(ValueError,'member offsets'):b.verify_shard(path,rows)
            path.write_bytes(raw+b'x')
            with self.assertRaisesRegex(ValueError,'trailing'):b.verify_shard(path,rows)


class GateTests(unittest.TestCase):
    def test_review_gate_prevents_work_without_exact_source_schema(self):
        with tempfile.TemporaryDirectory() as d:
            path=Path(d)/'review';path.write_text('{}')
            with self.assertRaisesRegex(ValueError,'phase required'):b.review_gate(path,b.sha(path),'pilot',{})
            path.write_text(json.dumps(dict(phase='bulk-code-pool-pilot-emission',mode='pilot',approved=True,
                independent_source_schema_review_pass=True,root_authorized=True,source_sha256={})))
            with self.assertRaisesRegex(ValueError,'source set'):b.review_gate(path,b.sha(path),'pilot',{})
            with self.assertRaisesRegex(ValueError,'phase required'):b.review_gate(path,b.sha(path),'all-current',{})
            r=json.loads(path.read_text());r['source_sha256']=dict.fromkeys(b.OWNED,'a'*64);r['reference_certificates']=[dict(independent_review_pass=True,root_authorized=True)]
            path.write_text(json.dumps(r))
            with self.assertRaisesRegex(ValueError,'certificate consumption unsupported'):b.review_gate(path,b.sha(path),'pilot',{})

    def test_historical_current_function_AST_delta_and_rejection(self):
        source='\n'.join('def '+n+'():\n    return 1\n' for n in ('canonical','unresolved','index_object','assess_member','assess_parsed'))
        with tempfile.TemporaryDirectory() as d:
            old,new=Path(d)/'old',Path(d)/'new';old.write_text(source);new.write_text(source+'WRAPPER_PIN=1\n')
            with patch.dict(b.PINS,historical_writer=b.sha(old),writer=b.sha(new)):
                self.assertTrue(b.compatibility(old,new)['shared_assessment_AST_equal'])
            new.write_text(source.replace('return 1','return 2',1))
            with patch.dict(b.PINS,historical_writer=b.sha(old),writer=b.sha(new)):
                with self.assertRaisesRegex(ValueError,'assessment changed'):b.compatibility(old,new)

    def test_inventory_rows_keep_historical_blocker_and_reject_duplicate_owner(self):
        rows=[dict(event='RECIPE_COFF_METADATA',recipe_id='fixture'),dict(event='SELECTED_CODE_SERIALIZATION_ASSESSMENT',
            original_address='0x00401000',physical_identity=dict(recipe_id='fixture'),serialization_candidate=False,
            blockers=[dict(code='ORIGINAL_MISSING_RELOCATION',evidence=10)]),dict(event='RECIPE_EH_EVIDENCE',recipe_id='fixture')]
        reader=b.InventoryStream(io.StringIO('\n'.join(json.dumps(r) for r in rows)));group=reader.take('fixture')
        self.assertEqual(group['0x00401000'][1]['blockers'],rows[1]['blockers'])
        reader=b.InventoryStream(io.StringIO('\n'.join(json.dumps(r) for r in rows[:2]+[rows[1]]+rows[2:])))
        with self.assertRaisesRegex(ValueError,'duplicate'):reader.take('fixture')
        with self.assertRaisesRegex(ValueError,'scope'):b.InventoryStream(io.StringIO('\n'.join(json.dumps(r) for r in rows))).finish({},dict(summary={}))

    def test_exact_source_only_pilot_policy(self):
        p=json.loads((b.ROOT/'runtime/code-pools/recipe-0000-pilot.json').read_text())
        self.assertEqual(p['recipe_id'],'0000-674cf48524ad6cf3');self.assertEqual(len(p['roots']),6)
        self.assertEqual(sum(r['size'] for r in p['roots']),436);self.assertEqual(p['expected_counts']['fields'],14)
        self.assertEqual(p['expected_counts']['unique_undefined_records'],13)
        self.assertEqual(p['proposal_sha256'],b.PINS['proposal']);self.assertFalse(p['provider_selected'])

    def test_failed_operational_start_keeps_journal_without_success_receipt(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);private=root/'build/rebuild';private.mkdir(parents=True)
            policy=root/'runtime/code-pools/recipe-0000-pilot.json';policy.parent.mkdir(parents=True)
            policy.write_text(json.dumps(dict(kind='bulk-code-pool-recipe-pilot',policy_id=b.POLICY,proposal_sha256=b.PINS['proposal'],
                roots=[dict(original_address='0x%08x'%i) for i in range(6)])))
            out=private/'fresh'
            with patch.object(b,'ROOT',root),patch.object(b,'review_gate',return_value=dict(source_sha256={})),patch.object(b,'load_basis',return_value=({}, {}, {})):
                with self.assertRaises(KeyError):b.emit({},'pilot',root/'review','a'*64,out)
            self.assertTrue((out/'progress.jsonl').exists());self.assertIn('failed',(out/'progress.jsonl').read_text())
            self.assertFalse((out/'receipt.json').exists());self.assertFalse(list(out.glob('*.lib')))

    def test_fresh_comparison_requires_exact_row_identity(self):
        raw,contracts=fixture();rows=[dict(address=c['selected']['original_address'],symbol=c['selected']['symbol'],size=8,compiled_extent=8,
            verdict='match',errors=[],byte_differences=[],relocations=[]) for c in contracts]
        import compare as oracle
        with patch.object(oracle,'Coff'),patch.object(oracle,'compare',return_value=rows):
            self.assertEqual(len(b.compare_functions('synthetic',None,contracts,{})),2)
            rows[1]['address']=rows[0]['address']
            with self.assertRaisesRegex(ValueError,'comparison failed'):b.compare_functions('synthetic',None,contracts,{})


if __name__=='__main__':unittest.main()
