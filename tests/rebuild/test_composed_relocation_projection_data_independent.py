"""Independent authored DATA-witness consumer corruption cases; no game inputs."""
import copy
from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT/'tools/rebuild'), str(ROOT/'tests/rebuild')]
from test_ordinary_relocation_projection import authored
from test_coff_code_archive import object_bytes, section, symbol, aux
import coff_code_archive as coff
import root_code_closure as ordinary
import runtime_code_pool as pool
import ordinary_initialized_data_omission as data_omission
import root_certificate_composer as composer
import composed_relocation_projection as projection


def authored_data(*, payload=b'authored readonly constant', two_sections=False):
    raw, contract, _, roots, providers = copy.deepcopy(authored(6, 4, 'data'))
    obj = coff.parse(raw)
    sections = list(obj['sections'].values())
    symbols = [symbol(s['name'], s['section'], s['value'], s['type'], s['storage'], s['aux'])
               for s in obj['symbols'].values()]
    sections.append(section('.rdata', payload, 0x40300040))
    symbols += [symbol('.rdata', 4, storage=3, auxiliary=aux(len(payload), selection=0)),
                symbol('_authored_isolated_data', 4, storage=3)]
    sections[1]['relocs'] = [(0, 12, 6)]
    symbols[2] = symbol('.text', 2, storage=3, auxiliary=aux(8, 1, selection=1))
    candidates = [4]
    if two_sections:
        extra = b'second authored constant'
        sections.append(section('.rdata', extra, 0x40300040))
        symbols += [symbol('.rdata', 5, storage=3, auxiliary=aux(len(extra), selection=0)),
                    symbol('_authored_second_data', 5, storage=3)]
        candidates.append(5)
    raw = object_bytes(sections, symbols)
    h = coff.digest(raw)
    contract['provenance']['object_sha256'] = h
    roots[0]['object_sha256'] = h
    providers[roots[0]['original_address']]['object_sha256'] = h
    base = ordinary.assess_object(coff.parse(raw), contract)
    witness = data_omission.observe_omitted_initialized_data(raw, contract, base, candidates)
    composed = composer.compose(raw, contract, base, [witness], policy_id=composer.POLICY)
    assert not base['closure_observed'] and witness['witness_complete']
    assert composed['composed_omission_complete']
    return [raw, contract, base, [witness], composed, roots, providers]


def compose(values, witnesses):
    return composer.compose(values[0], values[1], values[2], witnesses, policy_id=composer.POLICY)


def project(values, **kwargs):
    return projection.project_member(*values, existing_exports=kwargs.pop('existing_exports', ()),
                                     policy_id=kwargs.pop('policy_id', projection.POLICY), **kwargs)


class IndependentDataConsumerTests(unittest.TestCase):
    def test_complete_actual_typed_replay_preserves_negative_base_and_field(self):
        values = authored_data()
        before = copy.deepcopy(values)
        out, receipt = project(values)
        self.assertEqual(values, before)
        self.assertFalse(values[2]['closure_observed'])
        self.assertEqual(len(coff.exports(out)), 1)
        self.assertEqual(sum(len(s['relocs']) for s in coff.parse(out)['sections'].values()), 1)
        self.assertFalse(receipt['provider_selected'])
        self.assertFalse(receipt['runtime_eligible'])

    def test_borrowed_witness_from_another_object_is_fatal(self):
        values = authored_data(payload=b'another authored constant')
        other = authored_data()
        values[3] = other[3]
        with self.assertRaises(ValueError):
            project(values)

    def test_borrowed_composition_cannot_replace_fresh_replay(self):
        values = authored_data(payload=b'another authored constant')
        values[4] = authored_data()[4]
        with self.assertRaises(ValueError):
            project(values)

    def test_borrowed_source_contract_witness_rejected(self):
        values = authored_data()
        old_witnesses = copy.deepcopy(values[3])
        values[1]['provenance']['source_sha256'] = 'c'*64
        values[5][0]['source_sha256'] = 'c'*64
        values[2] = ordinary.assess_object(coff.parse(values[0]), values[1])
        fresh = data_omission.observe_omitted_initialized_data(values[0], values[1], values[2], [4])
        values[4] = compose(values, [fresh])
        values[3] = old_witnesses
        with self.assertRaises(ValueError):
            project(values)

    def test_legitimate_partial_witness_is_not_complete_root_authority(self):
        values = authored_data(two_sections=True)
        partial = data_omission.observe_omitted_initialized_data(values[0], values[1], values[2], [4])
        self.assertTrue(partial['witness_complete'])
        values[3] = [partial]
        values[4] = compose(values, values[3])
        self.assertFalse(values[4]['composed_omission_complete'])
        self.assertTrue(values[4]['remaining_blockers'])
        with self.assertRaises(ValueError):
            project(values)

    def test_partial_extra_row_cannot_hide_behind_complete_composer_result(self):
        values = authored_data(two_sections=True)
        obj = coff.parse(values[0])
        sections = list(obj['sections'].values())
        # The extra requested section is already a supported ordinary form and
        # has no base blocker. Its failed witness row still must not be ignored.
        sections[4]['flags'] = 0x40301040
        symbols = [symbol(s['name'], s['section'], s['value'], s['type'], s['storage'], s['aux'])
                   for s in obj['symbols'].values()]
        for i, record in enumerate(symbols):
            if record[0] == '.rdata' and record[2] == 5:
                symbols[i] = symbol('.rdata', 5, storage=3,
                                    auxiliary=aux(sections[4]['size'], selection=1))
        values[0] = object_bytes(sections, symbols)
        h = coff.digest(values[0])
        values[1]['provenance']['object_sha256'] = h
        values[5][0]['object_sha256'] = h
        values[6]['0x00500000']['object_sha256'] = h
        values[2] = ordinary.assess_object(coff.parse(values[0]), values[1])
        witness = data_omission.observe_omitted_initialized_data(values[0], values[1], values[2], [4, 5])
        values[3] = [witness]
        values[4] = compose(values, values[3])
        self.assertFalse(witness['witness_complete'])
        self.assertTrue(values[4]['composed_omission_complete'])
        with self.assertRaises(ValueError):
            project(values)

    def test_missing_witness_does_not_inherit_cached_positive_composition(self):
        values = authored_data()
        values[3] = []
        with self.assertRaises(ValueError):
            project(values)

    def test_proof_integrity_failures_are_not_assessment_quarantines(self):
        for mutation in ('missing', 'duplicate', 'borrowed_composition', 'promoted'):
            values = authored_data()
            if mutation == 'missing': values[3] = []
            elif mutation == 'duplicate': values[3] *= 2
            elif mutation == 'borrowed_composition':
                values[4] = authored_data(payload=b'different authored object')[4]
            else: values[3][0]['runtime_eligible'] = True
            with self.subTest(mutation=mutation), self.assertRaises(ValueError):
                projection.assess_member(*values, existing_exports=(), policy_id=projection.POLICY)

    def test_duplicate_and_distinct_overlapping_witnesses_are_fatal(self):
        values = authored_data()
        values[3] = [values[3][0], copy.deepcopy(values[3][0])]
        with self.assertRaises(ValueError):
            project(values)
        values = authored_data(two_sections=True)
        partial = data_omission.observe_omitted_initialized_data(values[0], values[1], values[2], [4])
        values[3] = [partial, values[3][0]]
        with self.assertRaises(ValueError):
            project(values)

    def test_partial_altered_duplicate_or_promoted_witness_evidence_rejected(self):
        for mutation in ('rows', 'duplicate_id', 'promoted', 'source'):
            values = authored_data()
            witness = values[3][0]
            if mutation == 'rows': witness['rows'] = []
            elif mutation == 'duplicate_id': witness['discharge_blocker_ids'] *= 2
            elif mutation == 'promoted': witness['provider_selected'] = True
            else: witness['source_sha256'] = 'f'*64
            with self.subTest(mutation=mutation), self.assertRaises(ValueError):
                project(values)

    def test_aborted_envelope_is_not_a_typed_witness(self):
        values = authored_data()
        values[3] = [dict(kind='partial-aborted-operation', status='aborted-no-retry',
                          witness=values[3][0], successful_observation=False)]
        with self.assertRaises(ValueError):
            project(values)

    def test_forged_bare_positive_cannot_feed_legacy_authority(self):
        values = authored_data()
        values[2]['closure_observed'] = True
        values[2]['blockers'] = []
        with self.assertRaises(ValueError):
            project(values)

    def test_unrelated_parent_eh_remains_blocked_after_data_discharge(self):
        values = authored_data()
        values[1]['parent_eh'] = [[1, 77, False, '0x00500000', []]]
        values[2] = ordinary.assess_object(coff.parse(values[0]), values[1])
        witness = data_omission.observe_omitted_initialized_data(values[0], values[1], values[2], [4])
        values[3] = [witness]
        values[4] = compose(values, values[3])
        self.assertTrue(witness['witness_complete'])
        self.assertFalse(values[4]['composed_omission_complete'])
        with self.assertRaises(ValueError):
            project(values)

    def test_explicit_new_policy_and_prepared_export_exclusion_required(self):
        values = authored_data()
        for policy in ('root-code-closure-observation-v2', None):
            with self.subTest(policy=policy), self.assertRaises(ValueError):
                project(values, policy_id=policy)
        export = pool.canonical(values[6]['0x00500000'])
        with self.assertRaises(ValueError):
            project(values, existing_exports=[export])


if __name__ == '__main__':
    unittest.main()
