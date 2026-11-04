"""Synthetic metadata only: no original image, compiler, linker or objects."""
import copy
from collections import Counter, defaultdict
import importlib.util
from pathlib import Path
import unittest

PATH = Path(__file__).resolve().parents[2] / 'tools/rebuild/entry_dependencies.py'
SPEC = importlib.util.spec_from_file_location('entry_dependencies', PATH)
m = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(m)
A, B, C, D = ['0x%08x' % n for n in (4096, 8192, 12288, 16384)]


def choice(n=0):
    return dict(recipe_id='recipe', recipe_index=n, symbol='source', section=1,
                size=32, value=0, runtime_eligible=False, link_ready=False)


def field(src=A, target=B, offset=0, interior=False):
    return dict(event='SELECTED_FUNCTION_COFF_RELOCATION', recipe_id='recipe',recipe_index=0,
        function_va=src,function_symbol='source',source_field_offset=0,physical_section=1,
        physical_offset=0,original_field_va=src, coff_relocation=dict(kind=20,symbol_index=7,conservative_extent=4),
        runtime_eligible=False,provider_selected=False,proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',
        classification='UNIQUE_CODE_INTERIOR_OR_LOCAL_LABEL_NOT_CALLABLE_APPROVAL' if interior else 'SELECTED_CODE_ENTRY',
        exact_original_target_va='0x%08x'%(int(target,16)+offset),code_ownership_ambiguous=False,
        selected_address=target,code_owners=[dict(address=target,offset=offset)])


def census(rows):
    return dict(events=dict(Counter(r['event'] for r in rows)),
        target_classes=dict(Counter(r['classification'] for r in rows)),
        relocation_kinds=dict(Counter(str(r['coff_relocation']['kind']) for r in rows if r['coff_relocation'])),
        proof_consistency=dict(Counter(r['proof_consistency'] for r in rows if r['coff_relocation'])))


def assessment(src, fields, selections):
    c=selections[src]
    return dict(event='SELECTED_CODE_SERIALIZATION_ASSESSMENT',original_address=src,
        selected_native=dict(original_address=src,**{k:c[k] for k in ('symbol','section','size','value')}),
        physical_identity=dict(recipe_id=c['recipe_id']),runtime_eligible=False,
        binding_row_references=[dict(ordinal=f[0],sha256=f[1]) for f in fields.get(src,[])],
        binding_fields=len(fields.get(src,[])),original_missing_fields=0,
        category='BLOCKED_RECIPE_WIDE_POLICY',serialization_candidate=False,
        blockers=[dict(code='SAFESEH_REQUIRES_CLOSURE')],
        same_parent_piece_observations=0,same_parent_false_piece_observations=0)


class EntryDependenciesTests(unittest.TestCase):
    def setUp(self):
        self.s={A:choice(),B:choice(),C:choice(),D:choice()}

    def test_entry_and_interior_are_separate(self):
        rows=[field(),field(B,C,4,True)]
        fields,_=m.consume_binding(rows,self.s,census(rows))
        assessments={a:dict(category='blocked',blocker_codes=['quarantine']) for a in self.s}
        result=m.analyze(self.s,fields,assessments,[A])
        self.assertEqual(result['reachable_addresses'],[A,B,C])
        self.assertEqual(result['entry_edge_only_reachable_owners'],2)
        self.assertEqual(result['unreachable_selected_owners'],1)
        self.assertEqual(result['serialization_categories'],{'blocked':3})

    def test_repeated_fields_not_distinct_targets(self):
        row=field(); second=copy.deepcopy(row)
        second.update(source_field_offset=4,physical_offset=4,original_field_va='0x00001004')
        rows=[row,second]; fields,_=m.consume_binding(rows,self.s,census(rows))
        a={v:dict(category='candidate',blocker_codes=[]) for v in self.s}
        result=m.analyze(self.s,fields,a,[A])
        self.assertEqual(result['role_occurrences']['selected_entry'],2)
        self.assertEqual(result['distinct_ordinary_targets_by_role']['selected_entry'],1)
        self.assertEqual(result['unique_selected_owner_pairs'],1)

    def test_boundary_does_not_expand(self):
        row=field();row['classification']='UNSELECTED_EXECUTABLE_TARGET_UNCLASSIFIED'
        fields,_=m.consume_binding([row],self.s,census([row]))
        a={v:dict(category='blocked',blocker_codes=[]) for v in self.s}
        result=m.analyze(self.s,fields,a,[A])
        self.assertEqual(result['reachable_addresses'],[A])
        self.assertEqual(result['role_occurrences'],{'generated_or_unselected_code_unknown':1})

    def test_duplicate_field_rejected(self):
        rows=[field(),field()]
        with self.assertRaisesRegex(ValueError,'duplicate'):m.consume_binding(rows,self.s,census(rows))

    def test_source_join_mutations_rejected(self):
        for key,value in [('function_va',D),('recipe_id','stale'),('function_symbol','other'),
                          ('physical_section',9),('physical_offset',5),('source_field_offset',31),
                          ('original_field_va',B),('runtime_eligible',True)]:
            row=field();row[key]=value
            with self.subTest(key=key),self.assertRaises(ValueError):m.consume_binding([row],self.s,census([row]))

    def test_missing_source_rejected(self):
        row=field();del self.s[A]
        with self.assertRaisesRegex(ValueError,'source'):m.consume_binding([row],self.s,census([row]))

    def test_selected_destination_missing_rejected(self):
        row=field();del self.s[B]
        with self.assertRaisesRegex(ValueError,'target'):m.consume_binding([row],self.s,census([row]))

    def test_owner_evidence_mutations_rejected(self):
        for updates in [dict(code_ownership_ambiguous=True),dict(code_owners=[]),
                        dict(exact_original_target_va=C),dict(selected_address=C)]:
            row=field();row.update(updates)
            with self.subTest(updates=updates),self.assertRaises(ValueError):m.graph_target(row,self.s)

    def test_unknown_classification_rejected(self):
        row=field();row['classification']='NEW_UNREVIEWED_CLASS'
        with self.assertRaisesRegex(ValueError,'schema review'):m.graph_target(row,self.s)

    def test_census_drift_rejected(self):
        row=field();summary=census([row]);summary['events']={}
        with self.assertRaisesRegex(ValueError,'census'):m.consume_binding([row],self.s,summary)

    def test_inventory_exact_reference_hash_and_coverage(self):
        fields,sequence=m.consume_binding([field()],self.s,census([field()]))
        rows=[assessment(a,fields,self.s) for a in self.s]
        summary=dict(summary=dict(selected=4,events={'SELECTED_CODE_SERIALIZATION_ASSESSMENT':4}),
                     binding_provenance=dict(sequence_sha256=sequence))
        self.assertEqual(set(m.consume_inventory(rows,self.s,fields,summary,sequence)),set(self.s))
        bad=copy.deepcopy(rows);bad[0]['binding_row_references'][0]['sha256']='0'*64
        with self.assertRaisesRegex(ValueError,'references'):m.consume_inventory(bad,self.s,fields,summary,sequence)
        with self.assertRaisesRegex(ValueError,'coverage'):m.consume_inventory(rows[:-1],self.s,fields,summary,sequence)

    def test_missing_root_fails(self):
        with self.assertRaisesRegex(ValueError,'root'):m.analyze(self.s,{}, {},['0x00000001'])

    def test_iterative_SCC_long_chain_and_cycles(self):
        graph=defaultdict(set)
        for n in range(5000):graph[str(n)].add(str(n+1))
        graph['5000'].add('4999')
        groups=m.components(graph,set(map(str,range(5001))))
        self.assertEqual(len(groups),5000)
        self.assertIn(['4999','5000'],groups)

    def test_scc_self_loop(self):
        graph=defaultdict(set,{A:{A,B},B:{C},C:{B},D:set()})
        self.assertEqual(m.components(graph,{A,B,C,D}),[[A],[B,C],[D]])


if __name__=='__main__':unittest.main()
