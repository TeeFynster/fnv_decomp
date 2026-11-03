"""Original synthetic metadata only; no native tools or game object reads."""
from collections import Counter
import copy
import hashlib
import io
import json
from pathlib import Path
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import Mock
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import runtime_code_inventory as d


def choice(address='0x00500000',section=1):
    return dict(recipe_id='fixture',recipe_index=0,symbol='_original'+str(section),section=section,value=0,size=16,
        selection_status='CODE_OWNERSHIP_SELECTED',runtime_eligible=False,link_ready=False)


def field(address='0x00500000',offset=4,kind=6,addend=0xfffffff8):
    return dict(event='SELECTED_FUNCTION_COFF_RELOCATION',recipe_id='fixture',recipe_index=0,function_va=address,
        function_symbol='_original1',source_field_offset=offset,physical_section=1,physical_offset=offset,
        original_field_va='0x%08x'%(int(address,16)+offset),coff_relocation=dict(symbol_index=2,kind=kind,conservative_extent=4,addend=addend),
        classification='SELECTED_CODE_ENTRY',proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',runtime_eligible=False,provider_selected=False)


def reader(rows,selections=None):
    summary=dict(events=dict(Counter(r['event'] for r in rows)),target_classes=dict(Counter(r['classification'] for r in rows)),
        relocation_kinds=dict(Counter(str(r['coff_relocation']['kind']) for r in rows if r['coff_relocation'])),
        proof_consistency=dict(Counter(r['proof_consistency'] for r in rows if r['coff_relocation'])))
    return d.BindingReader([json.dumps(r) for r in rows],summary,selections or {'0x00500000':choice()})


class InventoryTests(unittest.TestCase):
    def test_all_size_boundaries_without_cap(self):
        self.assertEqual([d.size_band(s) for s in (1,255,256,511,512,26620)],['1-255','1-255','256-511','256-511','512+','512+'])
        for bad in (0,-1,True,1.5):
            with self.assertRaises(ValueError):d.size_band(bad)

    def test_field_preserves_physical_identity_and_signed_bits(self):
        row=field();r=reader([row]);self.assertEqual(r.take(0)['0x00500000']['fields'],[row])
        self.assertEqual(r.finish(0,0)['events'],{'SELECTED_FUNCTION_COFF_RELOCATION':1})
        self.assertEqual(row['coff_relocation']['addend'],0xfffffff8)

    def test_binding_recipe_gaps_and_missing_accounting(self):
        row=field();row.update(coff_relocation=None,event='MISSING_ORIGINAL_HIGHLOW_SOURCE_MIGRATION_BLOCKER',classification='MISSING_SOURCE_RELOCATION_NO_SYNTHESIS')
        r=reader([row]);bucket=r.take(0)['0x00500000'];self.assertEqual(bucket['row_identities'],[dict(ordinal=1,sha256=d.digest(row))])
        self.assertEqual(r.take(1),{});self.assertEqual(r.finish(1,1)['missing_functions'],1)

    def test_duplicate_field_rejected(self):
        r=reader([field(),field()])
        with self.assertRaisesRegex(ValueError,'duplicate'):r.take(0)

    def test_stale_physical_field_and_bad_span(self):
        for key,value in [('physical_section',2),('physical_offset',5),('source_field_offset',14),('function_symbol','_wrong')]:
            row=field();row[key]=value
            with self.assertRaises(ValueError):reader([row])

    def test_unconsumed_or_wrong_summary_fails(self):
        r=reader([field()])
        with self.assertRaises(ValueError):r.finish(0,0)
        r.take(0);r.summary['events']={}
        with self.assertRaises(ValueError):r.finish(0,0)

    def test_binding_false_runtime_guard(self):
        row=field();row['runtime_eligible']=True
        with self.assertRaises(ValueError):reader([row])

    def test_owner_exact_coverage_and_flags(self):
        e=dict(event='SOURCE_CODE_PROVIDER_OBLIGATION',original_start=0x500000,identity=dict(recipe_id='fixture',object_sha256='a'*64,symbol_index=0),
            native_section=1,native_value=0,verified_span=16,runtime_eligible=False,provider_selected=False,materialization_approved=False)
        report=dict(summary=dict(events={e['event']:1}));selections={'0x00500000':choice()}
        providers,_=d.owner_providers([json.dumps(e)],report,selections);self.assertEqual(providers['0x00500000'],e['identity'])
        for update in ({'verified_span':4},{'provider_selected':True},{'native_section':2}):
            bad=dict(e,**update)
            with self.assertRaises(ValueError):d.owner_providers([json.dumps(bad)],report,selections)
        with self.assertRaises(ValueError):d.owner_providers([],dict(summary=dict(events={})),selections)

    def fixture(self,two=False,blockers=None,missing=False,failed=False,extra_section=False):
        data=b'original authored metadata fixture';h=hashlib.sha256(data).hexdigest()
        choices=[dict(choice(),original_address='0x00500000')]
        if two:choices.append(dict(choice('0x00500100',2),original_address='0x00500100'))
        obj=dict(symbol_count=len(choices),symbols={i:dict(name=c['symbol'],section=c['section'],value=0,type=0x20,storage=2,aux=b'',aux_count=0)
            for i,c in enumerate(choices)},sections={i+1:dict(name='.text',size=16,flags=0x60000020,payload=b'private',relocs=[]) for i in range(len(choices))})
        unit=dict(recipe_id='fixture',recipe_index=0,object_sha256=h,source_sha256='b'*64)
        proof=dict(eh_errors=['unrelated exact diagnostic'],eh_sections=[[0,4,False,'0x00500000',[]]] if failed else [])
        providers={c['original_address']:dict(recipe_id='fixture',object_sha256=h,symbol_index=i) for i,c in enumerate(choices)}
        bindings={'0x00500000':dict(fields=[],missing_fields=[dict(site=10)] if missing else [],row_identities=[])}
        def assess(obj,contract):
            return dict(schema_version=1,policy_id='synthetic',candidate_eligible=not blockers,blockers=blockers or [],obligations=[],
                observations=dict(selected=contract['selected'],whole_section_extent=True),extraction_plan=dict(sections=[contract['selected']['section']]+([99] if extra_section else [])))
        writer=SimpleNamespace(index_object=lambda obj:dict(aux={},children={},problems=[],directives=[],metadata=[]),POLICY_ID='synthetic',coff=SimpleNamespace(parse=Mock(return_value=obj)),assess_parsed=Mock(side_effect=assess))
        return data,unit,proof,choices,bindings,providers,writer

    def test_once_per_object_parser_and_all_roots_no_payload(self):
        args=self.fixture(two=True);meta=[];rows=d.assess_unit(*args,emit_metadata=meta.append)
        self.assertEqual(args[-1].coff.parse.call_count,1);self.assertEqual(args[-1].assess_parsed.call_count,2)
        self.assertEqual(len(rows),2);self.assertTrue(all(r['serialization_candidate'] for r in rows))
        self.assertEqual(len(meta),1);self.assertNotIn('private',json.dumps(meta));self.assertNotIn('extraction_plan',json.dumps(rows))

    def test_duplicate_spelling_keeps_physical_identity(self):
        args=self.fixture();obj=args[-1].coff.parse.return_value
        obj['symbols'][5]=dict(obj['symbols'][0],section=2);obj['symbol_count']=6
        row=d.assess_unit(*args)[0]
        self.assertEqual(row['physical_identity']['symbol_index'],0);self.assertTrue(row['serialization_candidate'])

    def test_missing_and_failed_eh_override_candidate(self):
        for mode,code in [('missing','INVENTORY_MISSING_SOURCE_RELOCATION'),('failed','INVENTORY_FAILED_PARENT_EH')]:
            row=d.assess_unit(*self.fixture(**{mode:True}))[0]
            self.assertFalse(row['serialization_candidate']);self.assertIn(code,[x['code'] for x in row['blockers']])

    def test_unrelated_global_weak_policy_stays_explicit(self):
        row=d.assess_unit(*self.fixture(blockers=[dict(code='WEAK_OR_COMMON_RECORD',evidence=33)]))[0]
        self.assertEqual(row['category'],'BLOCKED_RECIPE_WIDE_POLICY');self.assertFalse(row['runtime_eligible'])

    def test_placeholder_data_never_retained(self):
        row=d.assess_unit(*self.fixture(extra_section=True))[0]
        self.assertFalse(row['serialization_candidate']);self.assertEqual(row['category'],'BLOCKED_SECTION_OR_SYMBOL')

    def test_stale_object_and_physical_owner(self):
        args=list(self.fixture());args[0]+=b'changed'
        with self.assertRaisesRegex(ValueError,'stale input'):d.assess_unit(*args)
        args=list(self.fixture());args[5]['0x00500000']['symbol_index']=3
        with self.assertRaises(ValueError):d.assess_unit(*args)

    def test_unsupported_parser_keeps_all_owners(self):
        args=self.fixture(two=True);args[-1].coff.parse.side_effect=ValueError('opaque input')
        rows=d.assess_unit(*args);self.assertEqual(len(rows),2)
        self.assertEqual({r['category'] for r in rows},{'BLOCKED_OBJECT_FORMAT'})

    def test_eh_notes_not_false_piece_waiver(self):
        unit=dict(recipe_id='fixture',recipe_index=0,object_sha256='a'*64,source_sha256='b'*64)
        proof=dict(eh_errors=['note']*95,eh_sections=[[0,4,False,'0x00500000',[]],[4,8,True,'0x00500000',[]]])
        e=d.unit_eh_evidence(unit,proof);self.assertEqual(len(e['diagnostics']),95);self.assertEqual(e['false_pieces'],1)
        self.assertFalse(e['diagnostics_imply_complete_frame_closure'])

    def test_no_bytes_or_private_paths_in_metadata(self):
        with self.assertRaises(ValueError):d.public_metadata(dict(payload=b'code'))
        self.assertNotIn('Users',json.dumps(d.public_metadata('C:\\Users\\person\\file')))

    def test_outputs_exclusive_and_no_input_collision(self):
        with tempfile.TemporaryDirectory() as tmp:
            p=Path(tmp);a,b=p/'a',p/'b'
            with self.assertRaises(ValueError):d.output_paths(a,b,{a.resolve():'a'*64})
            with self.assertRaises(ValueError):d.output_paths(a,a,{})
            a.write_text('old')
            with self.assertRaises(ValueError):d.output_paths(a,b,{})

    def test_pin_and_stability_detect_dependency_mutation(self):
        with tempfile.TemporaryDirectory() as tmp:
            p=Path(tmp)/'reader.py';p.write_bytes(b'initial');obs={};h=hashlib.sha256(p.read_bytes()).hexdigest()
            d.pin(p,h,obs);d.stable(obs);p.write_bytes(b'changed')
            with self.assertRaises(ValueError):d.stable(obs)
            with self.assertRaises(ValueError):d.pin(p,h,{})

    def test_exact_selected_proof_not_source_placeholder(self):
        c=choice();f=dict(symbol=c['symbol'],address='0x00500000',size=16,section=1,value=0,verdict='match')
        unit=dict(recipe_id='fixture',recipe_index=0)
        self.assertEqual(len(d.selected_rows(unit,dict(verified_functions=[f]),{'0x00500000':c})),1)
        bad=dict(c,size=4)
        with self.assertRaises(ValueError):d.selected_rows(unit,dict(verified_functions=[f]),{'0x00500000':bad})


if __name__=='__main__':unittest.main()
