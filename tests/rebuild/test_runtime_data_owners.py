"""Original metadata fixtures only; no game bytes, compiler or native execution."""
import argparse
from collections import Counter
import copy
import gzip
import json
from pathlib import Path
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import runtime_data_owners as d


def plan():
    return dict(kind='fnv-private-data-analysis',schema_version=1,runtime_ready=False,image=dict(base=0x400000),
        fixups=dict(approved_semantic_fixups=0),provenance=dict(nonexec_sections=[dict(name='.data',sha256='a'*64)]),
        selected_sections=[dict(index=2,name='.data',rva=0x1000,extent=32,raw_size=16,zero_fill=16,raw_padding=0,
                                flags=0xc0000040,executable=False)])


def code_row(offset=4,addend=-4):
    return dict(event='SELECTED_FUNCTION_COFF_RELOCATION',recipe_id='fixture',recipe_index=0,function_va='0x00500000',
        function_symbol='_original',source_field_offset=offset,physical_section=1,physical_offset=offset,original_field_va=d.va(0x500000+offset),
        coff_relocation=dict(symbol_index=2,kind=20,conservative_extent=4,addend=addend),classification='SELECTED_CODE_ENTRY',
        exact_original_target_va='0x00500000',derived_source_symbol_base_va='0x00500004',proof_consistency='EXACT_OWN_SOURCE_RESOLUTION')


class DataOwnerTests(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory();self.addCleanup(self.tmp.cleanup);self.root=Path(self.tmp.name)
        self.arenas=d.arenas_from_plan(plan())

    def domains(self,ranges=()):
        p=d.partition_domains(self.arenas,ranges)
        return p,d.Intervals([(x['start'],x['end'],x) for x in p])

    def test_geometry_is_not_object_extent(self):
        a=self.arenas[0]
        self.assertEqual((a['logical_extent'],a['raw_backed_extent'],a['virtual_zero_extent']),(32,16,16))
        self.assertIsNone(a['object_extent']);self.assertFalse(a['materialization_approved'])

    def test_overlapping_arenas_rejected(self):
        p=plan();p['selected_sections']*=2
        with self.assertRaisesRegex(ValueError,'overlapping'):d.arenas_from_plan(p)

    def test_holes_have_explicit_ordinary_coverage(self):
        r=dict(range_id='runtime',start=0x401008,end=0x40100c,family='CRT')
        parts,index=self.domains([r])
        self.assertEqual(sum(p['end']-p['start'] for p in parts),32)
        self.assertEqual(d.view_at(0x401000,self.arenas,index)['domain_evidence'][0]['families'],['ORDINARY_UNCLASSIFIED'])
        self.assertEqual(d.view_at(0x401009,self.arenas,index)['domain_evidence'][0]['families'],['CRT'])

    def test_competing_specials_and_source_candidates_explicit_conflict(self):
        ranges=[dict(range_id='a',start=0x401004,end=0x40100c,family='CRT'),
                dict(range_id='b',start=0x401008,end=0x401010,family='SOURCE_PROJECTION_CANDIDATE')]
        parts,_=self.domains(ranges)
        self.assertTrue(next(p for p in parts if p['start']==0x401008)['unresolved_domain_overlap'])
        self.assertFalse(any(p['provider_selected'] for p in parts))

    def test_distinct_same_family_overlaps_remain_unresolved(self):
        for family in ('SOURCE_PROJECTION_CANDIDATE','FRESH_NORMAL_CRT_STATE'):
            ranges=[dict(range_id='owner-a',start=0x401004,end=0x40100c,family=family),
                    dict(range_id='owner-b',start=0x401008,end=0x401010,family=family)]
            parts,_=self.domains(ranges)
            self.assertTrue(next(p for p in parts if p['start']==0x401008)['unresolved_domain_overlap'])

    def test_interior_alias_does_not_invent_object_bounds(self):
        _,index=self.domains();v=d.view_at(0x401007,self.arenas,index)
        self.assertEqual(v['arena_offset'],7);self.assertIsNone(v['interior_object_offset']);self.assertIsNone(v['object_extent'])

    def test_external_resources_are_disjoint_obligations(self):
        ranges=[dict(range_id='resource',start=0x600000,end=0x600020,family='RESOURCE'),
                dict(range_id='rva',start=0x600008,end=0x600010,family='RVA_METADATA')]
        parts=d.external_domains(self.arenas,ranges)
        self.assertEqual(sum(p['end']-p['start'] for p in parts),32)
        self.assertTrue(any(p['unresolved_domain_overlap'] for p in parts))
        index=d.Intervals([(p['start'],p['end'],p) for p in parts])
        self.assertIn('RESOURCE',d.view_at(0x600000,self.arenas,index)['domain_evidence'][0]['families'])

    def test_per_site_identity_and_original_addend_unknown_preserved(self):
        _,index=self.domains();values=[0x1000,0x1007,'data',7,4,'raw',['unapproved']]
        record=d.data_field(values,self.arenas,index,0x400000)
        self.assertEqual(record['original_record'],values)
        self.assertIsNone(record['original_symbol_addend']);self.assertEqual(record['target_view']['arena_offset'],7)
        other=list(values);other[0]+=4
        self.assertNotEqual(record['site_identity'],d.data_field(other,self.arenas,index,0x400000)['site_identity'])

    def test_virtual_zero_and_straddling_fields(self):
        _,index=self.domains()
        record=d.data_field([0x1010,-0x400000,'unmapped',None,4,'virtual-zero-fill',[]],self.arenas,index,0x400000)
        self.assertEqual(record['original_target_va'],'0x00000000')
        for off in (0x100e,0x101f):
            with self.assertRaises(ValueError):d.data_field([off,0x1000,'data',0,4,'raw',[]],self.arenas,index,0x400000)

    def stream(self,rows,mutate_summary=False):
        path=self.root/'binding.gz'
        with gzip.open(path,'wt') as f:
            for e in rows:f.write(json.dumps(e)+'\n')
        events=Counter(e['event'] for e in rows);classes=Counter(e['classification'] for e in rows)
        kinds=Counter(str(e['coff_relocation']['kind']) for e in rows if e['coff_relocation'])
        consistency=Counter(e['proof_consistency'] for e in rows if e['coff_relocation'])
        summary=dict(events=dict(events),target_classes=dict(classes),relocation_kinds=dict(kinds),proof_consistency=dict(consistency),
                     exact_baseline_missing_field_identities=events['MISSING_ORIGINAL_HIGHLOW_SOURCE_MIGRATION_BLOCKER'])
        if mutate_summary:summary['target_classes']={'wrong':1}
        manifest=dict(units=[dict(recipe_id='fixture',object_sha256='b'*64,source_sha256='c'*64)])
        selection=dict(selections={'0x00500000':dict(recipe_id='fixture',symbol='_original',section=1,value=0,size=32)})
        output=[]
        result=d.binding_stream(path,dict(summary=summary),manifest,selection,output.append,required_missing=summary['exact_baseline_missing_field_identities'])
        return result,output

    def test_hash_linked_all_code_rows_and_signed_addend(self):
        rows=[code_row(4,-4),code_row(12,8)]
        (groups,_,_,provenance),_=self.stream(rows)
        self.assertEqual(groups['0x00500000']['ordinals'],[1,2]);self.assertEqual(provenance['records'],2)
        self.assertEqual(rows[0]['coff_relocation']['addend'],-4)

    def test_stale_counts_recipe_and_physical_join_rejected(self):
        with self.assertRaisesRegex(ValueError,'counts'):self.stream([code_row()],True)
        for key,value in (('recipe_id','wrong'),('physical_offset',9),('original_field_va','0x00500009')):
            row=code_row();row[key]=value
            with self.assertRaises(ValueError):self.stream([row])

    def test_missing_fields_remain_exact_separate_records(self):
        row=code_row();row.update(event='MISSING_ORIGINAL_HIGHLOW_SOURCE_MIGRATION_BLOCKER',coff_relocation=None,
            classification='MISSING_SOURCE_RELOCATION_NO_SYNTHESIS')
        (_,_,_,provenance),out=self.stream([row])
        self.assertEqual(len(out),1);self.assertEqual(out[0]['source_observation'],row)
        self.assertFalse(out[0]['materialization_approved']);self.assertEqual(provenance['records'],1)
        row['physical_offset']=5
        with self.assertRaisesRegex(ValueError,'physical'):self.stream([row])

    def lead_coff(self):
        name='?g_011dee84@@3VGlobalObject_00633c90@@A'
        return SimpleNamespace(symbols={27506:dict(name=name,index=27506,section=6424,value=120),
            13730:dict(name='??__Eg_011dee84@@YAXXZ',index=13730,section=3115,value=0)},
            sections={6424:dict(index=6424,size=13460,relocs=[]),6425:dict(index=6425,name='.CRT$XCU',relocs=[(11828,13730,6)])})

    def test_placeholder_observation_never_extent_proof_wrong_source_rejected(self):
        rows=[dict(function_va=d.va(f),source_field_offset=o,exact_original_target_va=d.va(d.LEAD),coff_relocation=dict(addend=0)) for f,o in d.LEAD_FIELDS]
        source='GlobalObject_00633c90 g_011dee84(0);';header='class GlobalObject_00633c90 { char storage[4]; };'
        edges=[dict(function_va=d.va(f),source_field_offset=o,exact_original_target_va=d.va(t),coff_relocation=dict(kind=k)) for f,o,k,t in d.ROOT_EDGE_CONTRACT]
        lead=dict(storage_rows=rows,root_edges=edges);sources=[dict(extent_or_lifetime_proof=False)]*4
        rec=d.lead_lifecycle(lead,self.lead_coff(),source,header,sources)
        self.assertIsNone(rec['object_extent']);self.assertFalse(rec['placeholder_is_extent_proof'])
        for s,h in (('// '+source,header),(source,header.replace('[4]','[64]'))):
            with self.assertRaisesRegex(ValueError,'placeholder'):d.lead_lifecycle(lead,self.lead_coff(),s,h,sources)

    def test_wrong_lifecycle_edges_and_source_statements_rejected(self):
        raw=b'actual_statement();\n';h=d.hashlib.sha256(raw).hexdigest()
        e=d.source_statement('original.cpp',raw,h,'actual_statement();','fixture')
        self.assertFalse(e['extent_or_lifetime_proof'])
        for body,expected in ((b'// actual_statement();\n',d.hashlib.sha256(b'// actual_statement();\n').hexdigest()),(raw,'0'*64)):
            with self.assertRaises(ValueError):d.source_statement('original.cpp',body,expected,'actual_statement();','fixture')
        with self.assertRaisesRegex(ValueError,'seven lifecycle'):
            d.lead_lifecycle(dict(storage_rows=[],root_edges=[]),self.lead_coff(),'','',[])

    def test_stale_unsupported_plan_rejected_before_readers(self):
        args=SimpleNamespace(root=self.root,**{n:self.root/(n+'.json') for n in ('data_plan','binding','recipes','manifest','retained','selection','imports','reference')})
        for n in ('data_plan','binding','recipes','manifest','retained','selection','imports','reference'):setattr(args,n+'_sha256','0'*64)
        with patch.object(d,'read_bound') as read:
            with self.assertRaisesRegex(ValueError,'exact data'):d.run(args)
            read.assert_not_called()

if __name__=='__main__':unittest.main()
