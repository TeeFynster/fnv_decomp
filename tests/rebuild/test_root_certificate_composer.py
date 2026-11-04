"""Original synthetic COFF/metadata; no native tools or original object reads."""
import copy
import io
import gzip
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch
ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT/'tools/rebuild'), str(ROOT/'tests/rebuild')]
import root_certificate_composer as c
import ordinary_initialized_data_omission as data
import root_code_closure as ordinary
from test_ordinary_initialized_data_omission import context
from test_scalableordinary_root_collect import fixture


def data_case(**kwargs):
    raw, contract, base, sections = context(**kwargs)
    return raw, contract, base, [data.observe_omitted_initialized_data(raw,contract,base,sections)]


def map_case():
    raw,u,p,roots,selections,providers,_ = fixture()
    rows=[]
    for r in roots:
        ident=providers[r['original_address']]
        rows.append(dict(event='SOURCE_CODE_PROVIDER_OBLIGATION',identity=ident,provider_id=c.digest(ident),
            source_sha256=u['source_sha256'],original_start=int(r['original_address'],16),
            original_end=int(r['original_address'],16)+r['size'],native_section=r['section'],native_value=r['value'],verified_span=r['size'],
            runtime_eligible=False,provider_selected=False,materialization_approved=False))
    return rows,dict(summary=dict(events={'SOURCE_CODE_PROVIDER_OBLIGATION':2})),selections,dict(units=[u]),dict(units=[p])


def map_run(args):
    rows,*rest=args; sequence=__import__('hashlib').sha256()
    for i,r in enumerate(rows,1): sequence.update(c.canonical([i,c.digest(r)]))
    return c.provider_map(io.StringIO(''.join(json.dumps(r)+'\n' for r in rows)),*rest,
                          expected_count=2,expected_sequence=sequence.hexdigest())


class ComposerTests(unittest.TestCase):
    def test_exact_data_omission_preserves_false_base_and_all_identity(self):
        args=data_case(); before=copy.deepcopy(args)
        result=c.compose(*args,policy_id=c.POLICY)
        self.assertTrue(result['composed_omission_complete'])
        self.assertFalse(result['base_closure_observed'])
        self.assertEqual(result['base_certificate'],args[2]);self.assertEqual(args,before)
        self.assertEqual(len(result['discharged_blockers']),1)
        self.assertEqual(result['retained_physical_slots'],args[2]['retained_physical_slots'])
        for flag in c.FALSE:self.assertIs(result[flag],False)

    def test_no_opt_in_and_unknown_family_rejected(self):
        args=data_case()
        with self.assertRaises(ValueError):c.compose(*args,policy_id=ordinary.POLICY)
        args=list(args);args[3]=[dict(kind='ignore-all')]
        with self.assertRaises(ValueError):c.compose(*args,policy_id=c.POLICY)

    def test_unknown_blocker_is_retained(self):
        raw,k,_,_=data_case();k['missing_fields']=[dict(authored_missing=True)]
        b=ordinary.assess_object(c.coff.parse(raw),k)
        w=data.observe_omitted_initialized_data(raw,k,b,[4])
        r=c.compose(raw,k,b,[w],policy_id=c.POLICY)
        self.assertFalse(r['composed_omission_complete'])
        self.assertIn('ORIGINAL_MISSING_FIELDS',{x['code'] for x in r['remaining_blockers']})

    def test_repeated_authoritative_directive_occurrences_preserved(self):
        from test_coff_code_archive import symbol,aux,object_bytes
        raw,k,_,_=data_case();obj=c.coff.parse(raw);secs=list(obj['sections'].values())
        directives=secs[2]['payload']+b' /DEFAULTLIB:"uuid.lib" /DEFAULTLIB:"uuid.lib"'
        secs[2]=dict(secs[2],payload=directives,size=len(directives))
        symbols=[symbol(s['name'],s['section'],s['value'],s['type'],s['storage'],s['aux']) for s in obj['symbols'].values()]
        symbols[4]=symbol('.drectve',3,storage=3,auxiliary=aux(len(directives),selection=0))
        raw=object_bytes(secs,symbols);k['provenance']['object_sha256']=c.coff.digest(raw)
        b=ordinary.assess_object(c.coff.parse(raw),k)
        original=[x for x in b['blockers'] if x['code']=='UNSUPPORTED_IMPLICIT_LINKER_DIRECTIVE']
        self.assertEqual(len(original),2);self.assertEqual(original[0]['blocker_id'],original[1]['blocker_id'])
        w=data.observe_omitted_initialized_data(raw,k,b,[4])
        r=c.compose(raw,k,b,[w],policy_id=c.POLICY)
        remain=[x for x in r['remaining_blocker_occurrences'] if x['blocker']['code']=='UNSUPPORTED_IMPLICIT_LINKER_DIRECTIVE']
        self.assertEqual([x['blocker'] for x in remain],original)
        self.assertNotEqual(remain[0]['base_blocker_ordinal'],remain[1]['base_blocker_ordinal'])
        self.assertFalse(r['composed_omission_complete']);self.assertEqual(r['base_certificate'],b)

    def test_incomplete_witness_cannot_discharge(self):
        r=c.compose(*data_case(outgoing=True),policy_id=c.POLICY)
        self.assertFalse(r['composed_omission_complete']);self.assertEqual(r['discharged_blockers'],[])

    def test_stale_raw_contract_or_base_rejected(self):
        for target in ('raw','contract','base'):
            raw,k,b,w=data_case()
            if target=='raw':raw+=b'changed'
            if target=='contract':k['provenance']['source_sha256']='e'*64
            if target=='base':b['blockers']=[]
            with self.subTest(target=target),self.assertRaises(ValueError):c.compose(raw,k,b,w,policy_id=c.POLICY)

    def test_forged_witness_discharge_or_graph_rejected(self):
        for key,val in [('discharge_blocker_ids',['fake']),('protected_directed_graph_sha256','f'*64),('witness_complete',False)]:
            raw,k,b,w=data_case();w[0][key]=val
            with self.subTest(key=key),self.assertRaises(ValueError):c.compose(raw,k,b,w,policy_id=c.POLICY)

    def test_duplicate_and_overlapping_witnesses_rejected(self):
        raw,k,b,w=data_case()
        with self.assertRaises(ValueError):c.compose(raw,k,b,w+w,policy_id=c.POLICY)

    def test_typed_discharge_of_ambiguous_occurrence_fails(self):
        raw,k,b,w=data_case();b['blockers'].append(copy.deepcopy(b['blockers'][0]))
        with patch.object(ordinary,'assess_object',return_value=b),\
             patch.object(data,'observe_omitted_initialized_data',return_value=w[0]),self.assertRaises(ValueError):
            c.compose(raw,k,b,w,policy_id=c.POLICY)

    def test_dependency_mutation_rejected(self):
        args=data_case();real=c.file_hash
        with patch.object(c,'file_hash',side_effect=lambda p:'0'*64 if str(p).endswith('root_code_closure.py') else real(p)):
            with self.assertRaises(ValueError):c.compose(*args,policy_id=c.POLICY)

    def test_label_family_not_guessed_without_reviewed_pin(self):
        raw,k,b,_=data_case()
        with patch.object(c,'LABEL_PIN',None),self.assertRaises(ValueError):
            c.compose(raw,k,b,[dict(kind='typed-local-label-omission-witness')],policy_id=c.POLICY)

    def test_reviewed_label_decoder_composes_exact_ids(self):
        from test_local_label_projection import decoder_fixture
        import local_label_projection as labels
        raw,e,k,b=decoder_fixture();cert=labels.prove_labels(raw,e)
        witness=dict(kind='typed-local-label-omission-witness',evidence_json=cert.evidence_json,
                     decision_json=cert.decision_json,decoded=labels.decode_label_policy(raw,k,b,cert))
        r=c.compose(raw,k,b,[witness],policy_id=c.POLICY)
        self.assertTrue(r['composed_omission_complete']);self.assertEqual(len(r['discharged_blockers']),7)
        witness['decoded']['discharged_blocker_ids']=[]
        with self.assertRaises(ValueError):c.compose(raw,k,b,[witness],policy_id=c.POLICY)

    def test_two_typed_families_compose_without_editing_base(self):
        from test_local_label_projection import decoder_fixture
        from test_coff_code_archive import section,symbol,aux,object_bytes
        import local_label_projection as labels
        raw,e,k,_=decoder_fixture();obj=c.coff.parse(raw)
        sections=list(obj['sections'].values())+[section('.rdata',b'authored',0x40300040)]
        symbols=[symbol(s['name'],s['section'],s['value'],s['type'],s['storage'],s['aux']) for s in obj['symbols'].values()]
        symbols += [symbol('.rdata',4,storage=3,auxiliary=aux(8,selection=0)),symbol('_unused',4,storage=3)]
        raw=object_bytes(sections,symbols);e['object_sha256']=c.coff.digest(raw);k['provenance']['object_sha256']=e['object_sha256']
        k['provenance'].update(recipe_id='authored',recipe_index=0)
        e['contract_sha256']=c.digest(k);b=ordinary.assess_object(c.coff.parse(raw),k)
        cert=labels.prove_labels(raw,e)
        ws=[data.observe_omitted_initialized_data(raw,k,b,[4]),dict(kind='typed-local-label-omission-witness',
            evidence_json=cert.evidence_json,decision_json=cert.decision_json,decoded=labels.decode_label_policy(raw,k,b,cert))]
        self.assertFalse(b['closure_observed'])
        r=c.compose(raw,k,b,ws,policy_id=c.POLICY)
        self.assertTrue(r['composed_omission_complete'])
        self.assertEqual(len(r['discharged_blockers']),8)
        self.assertEqual(r['base_certificate'],b)

    def test_unused_label_dependency_drift_does_not_waive_data_dependencies(self):
        real=c.file_hash
        with patch.object(c,'LABEL_PIN','0'*64):
            self.assertTrue(c.compose(*data_case(),policy_id=c.POLICY)['composed_omission_complete'])
            from test_local_label_projection import decoder_fixture
            import local_label_projection as labels
            raw,e,k,b=decoder_fixture();cert=labels.prove_labels(raw,e)
            w=dict(kind='typed-local-label-omission-witness',evidence_json=cert.evidence_json,
                   decision_json=cert.decision_json,decoded=labels.decode_label_policy(raw,k,b,cert))
            with self.assertRaises(ValueError):c.compose(raw,k,b,[w],policy_id=c.POLICY)
        with patch.object(c,'file_hash',side_effect=lambda p:'0'*64 if str(p).endswith('ordinary_initialized_data_omission.py') else real(p)):
            with self.assertRaises(ValueError):c.compose(*data_case(),policy_id=c.POLICY)


class ProviderMapTests(unittest.TestCase):
    def test_complete_exact_identity_map_is_only_planned(self):
        args=map_case();r=map_run(args)
        self.assertEqual(len(r['providers']),2);self.assertEqual(r['materialized_exports'],0)
        for va,p in r['providers'].items():
            ident={k:p[k] for k in ('recipe_id','object_sha256','symbol_index')}
            self.assertEqual(p['planned_canonical_name'],'_fnv_code_'+c.digest(ident))
            self.assertEqual(p['section'],args[2][va]['section'])
        for flag in c.FALSE:self.assertIs(r[flag],False)

    def test_missing_duplicate_and_physical_conflict_fail(self):
        for mutate in (lambda r:r.pop(),lambda r:r.append(copy.deepcopy(r[0])),
                       lambda r:r[1]['identity'].update(symbol_index=r[0]['identity']['symbol_index'])):
            args=map_case();mutate(args[0])
            with self.assertRaises(ValueError):map_run(args)

    def test_wrong_source_recipe_span_and_proof_location_fail(self):
        for target,key,val in [('row','source_sha256','f'*64),('row','native_section',2),('proof','section',2),('proof','value',4)]:
            args=map_case()
            if target=='row':args[0][0][key]=val
            else:args[4]['units'][0]['verified_functions'][0][key]=val
            with self.subTest(target=target,key=key),self.assertRaises(ValueError):map_run(args)

    def test_promoted_row_and_wrong_census_fail(self):
        args=map_case();args[0][0]['provider_selected']=True
        with self.assertRaises(ValueError):map_run(args)
        args=map_case();args[1]['summary']['events']={}
        with self.assertRaises(ValueError):map_run(args)

    def test_truncated_sequence_is_not_accepted(self):
        args=map_case();rows,*rest=args
        with self.assertRaises(ValueError):c.provider_map(io.StringIO('\n'.join(map(json.dumps,rows))),*rest,
                                                        expected_count=2,expected_sequence='0'*64)

    def test_publication_drift_cleanup_and_collision(self):
        with tempfile.TemporaryDirectory() as d:
            inp=Path(d)/'input';out=Path(d)/'out';inp.write_bytes(b'original')
            with patch.object(c,'file_hash',return_value='changed'),self.assertRaises(ValueError):
                c.publish(out,{}, {inp:c.coff.digest(b'original')})
            self.assertFalse(out.exists())
            with self.assertRaises(ValueError):c.publish(inp,{}, {inp:c.coff.digest(b'original')})

    def test_exclusive_creation_race_never_deletes_competing_output(self):
        with tempfile.TemporaryDirectory() as d:
            out=Path(d)/'out';real_open=Path.open
            def racing_open(path,mode='r',*args,**kwargs):
                if path==out and mode=='xb':
                    with real_open(out,'wb') as f:f.write(b'other owner')
                    raise FileExistsError('competing creator')
                return real_open(path,mode,*args,**kwargs)
            with patch.object(Path,'open',racing_open),self.assertRaises(FileExistsError):c.publish(out,{}, {})
            self.assertEqual(out.read_bytes(),b'other owner')


class CachedDemonstrationTests(unittest.TestCase):
    def run_cached(self, directory, mutate=None):
        root=Path(directory);raw,k,_,_=data_case()
        src=root/'authored.cpp';src.write_bytes(b'original authored source')
        k['provenance'].update(source_sha256=c.file_hash(src),recipe_id='authored',recipe_index=0)
        b=ordinary.assess_object(c.coff.parse(raw),k)
        native=root/'native.obj';native.write_bytes(raw)
        u=dict(recipe_id='authored',recipe_index=0,object='native.obj',source='authored.cpp',
               object_sha256=c.coff.digest(raw),source_sha256=c.file_hash(src))
        requested=[dict(r,recipe_id='authored',recipe_index=0,object_sha256=u['object_sha256'],source_sha256=u['source_sha256']) for r in k['roots']]
        record=dict(recipe_id='authored',requested_roots=requested,contract=k,certificate=b,
                    contract_identity_sha256=c.digest(k),certificate_sha256=c.digest(b))
        lane=root/'lane.jsonl.gz'
        with gzip.open(lane,'wt') as f:f.write(json.dumps(record)+'\n')
        manifest=root/'manifest.json';manifest.write_text(json.dumps(dict(units=[u])))
        central=root/'central.json';central.write_text(json.dumps(dict(input_stability=True,optional_function_index_present=False,
            lane_artifacts={'1':dict(path=lane.name,sha256=c.file_hash(lane))},observations=[dict(lane=1,lane_record_ordinal=1,
                record_sha256=c.digest(record),certificate_sha256=c.digest(b))])))
        out=root/'output.json'
        factory=lambda raw,k,b:[data.observe_omitted_initialized_data(raw,k,b,[4])]
        with patch.object(c,'ROOT',root),patch.object(c,'CENTRAL_PIN',c.file_hash(central)),\
             patch.dict(c.INPUT_PINS,manifest=c.file_hash(manifest)),patch.object(c,'tools',return_value={}):
            if mutate:mutate(root,src)
            return c.demonstrate_cached_case(central,lane,manifest,1,factory,out)

    def test_exact_cached_metadata_envelope_and_native_hash(self):
        with tempfile.TemporaryDirectory() as d:
            r,h=self.run_cached(d)
            self.assertTrue(r['composed_omission_complete']);self.assertEqual(h,c.file_hash(Path(d)/'output.json'))
            self.assertTrue(r['input_stability']);self.assertFalse(r['emission_performed'])

    def test_wrong_current_source_and_appeared_optional_index_fail(self):
        for mutate in (lambda root,src:src.write_bytes(b'changed'),
                       lambda root,src:((root/'build').mkdir(),(root/'build/function_index.json').write_text('{}'))):
            with tempfile.TemporaryDirectory() as d,self.assertRaises(ValueError):self.run_cached(d,mutate)


if __name__=='__main__':unittest.main()
