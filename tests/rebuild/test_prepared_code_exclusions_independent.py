"""Independent full-count authored epoch/namespace tests; metadata only."""
import copy
import hashlib
from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/rebuild'))
import prepared_code_exclusions as prepared


def sha(text):
    return hashlib.sha256(text.encode()).hexdigest()


def epoch_fixture():
    cohorts = dict(prepared.COUNTS)
    bindings = {cohort: sha('authored-ledger-' + cohort) for cohort in cohorts}
    bindings.update(entry_receipt=sha('authored-entry-receipt'),
                    application_observation=sha('authored-application-receipt'))
    ordinary, application, providers = [], [], {}
    index = 0
    def record(cohort, category, mode, source_key, *, alternate=False, physical_only=False):
        nonlocal index
        index += 1
        address = '0x%08x' % (0x00500000 + 16 * index)
        logical = dict(recipe_id='authored-original', object_sha256='a' * 64, symbol_index=index)
        physical = dict(logical, object_sha256='b' * 64) if alternate else dict(logical)
        if physical_only:
            physical = dict(recipe_id='authored-EH-physical', object_sha256='e' * 64, symbol_index=88)
            namespace = physical
        else:
            namespace = logical
            providers[address] = dict(logical, planned_canonical_name=prepared.base.pool.canonical(logical))
        result = dict(canonical=prepared.base.pool.canonical(namespace), original_address=address,
            cohort=cohort, category=category, identity_mode=mode, namespace_identity=namespace,
            origin_identity=physical, member='authored-%05d.obj' % index,
            member_sha256=None if category == 'application-candidate' else sha('authored-member-%d' % index),
            source_ledger_sha256=bindings[source_key], source_record_ordinal=index,
            source_record_sha256=sha('authored-source-record-%d' % index), logical_binding_applied=not physical_only)
        if physical_only:
            result['prospective_logical_demand'] = prepared.base.pool.unresolved(address, 'code')
        return result
    for cohort, count in cohorts.items():
        ordinary.extend(record(cohort, 'ordinary', 'original-selected-physical', cohort) for _ in range(count))
    entry = record('application-entry', 'application-candidate', 'original-selected-physical', 'entry_receipt')
    # This versioned cohort has one fixed known startup address.
    entry_provider = providers.pop(entry['original_address'])
    entry['original_address'] = '0x0086a850'
    providers[entry['original_address']] = entry_provider
    application.append(entry)
    application.extend(record('overlay-alternate', 'application-candidate',
                       'original-selected-logical-alternate-object', 'application_observation', alternate=True) for _ in range(2))
    application.append(record('EH-physical-candidate', 'application-candidate',
                       'physical-only-unbound-logical-demand', 'application_observation', physical_only=True))
    return ordinary, application, providers, bindings


class IndependentPreparedEpochTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.context = epoch_fixture()

    def test_equal_counts_are_different_prepared_sets_and_no_application_adoption(self):
        manifest = prepared.build_manifest(*self.context)
        ordinary, application, _, _ = self.context
        startup = {r['canonical'] for r in ordinary if r['cohort'] != 'ordinary-relocation-first3'}
        startup.update(r['canonical'] for r in application if r['cohort'] != 'EH-physical-candidate')
        self.assertEqual(len(startup), manifest['ordinary_prepared_count'])
        self.assertEqual(len(startup), 14329)
        self.assertNotEqual(startup, set(manifest['ordinary_names']))
        self.assertEqual(len(manifest['exclusion_names']), 14333)
        self.assertIsNone(manifest['application_selected_code_count'])
        self.assertFalse(manifest['application_selection_inferred_from_counts'])
        self.assertFalse(manifest['application_manifest_adopted'])
        self.assertFalse(manifest['provider_selected'])

    def test_unbound_eh_physical_name_is_not_the_old_logical_demand(self):
        manifest = prepared.build_manifest(*self.context)
        eh = next(r for r in manifest['records'] if r['cohort'] == 'EH-physical-candidate')
        self.assertFalse(eh['logical_binding_applied'])
        self.assertEqual(eh['namespace_identity'], eh['origin_identity'])
        self.assertNotEqual(eh['canonical'], eh['prospective_logical_demand'])
        self.assertNotIn(eh['canonical'], manifest['ordinary_names'])
        self.assertIn(eh['canonical'], manifest['exclusion_names'])

    def test_overlay_namespace_keeps_original_logical_hash_and_separate_physical_hash(self):
        manifest = prepared.build_manifest(*self.context)
        for row in manifest['records']:
            if row['cohort'] != 'overlay-alternate': continue
            self.assertNotEqual(row['origin_identity'], row['namespace_identity'])
            self.assertEqual(row['canonical'], prepared.base.pool.canonical(row['namespace_identity']))
            self.assertNotEqual(row['canonical'], prepared.base.pool.canonical(row['origin_identity']))

    def test_old_epoch_missing_first3_cannot_authorize_current_manifest(self):
        values = copy.deepcopy(self.context)
        values[0][:] = [r for r in values[0] if r['cohort'] != 'ordinary-relocation-first3']
        with self.assertRaises(ValueError): prepared.build_manifest(*values)

    def test_duplicate_canonical_and_unknown_planned_namespace_fail_closed(self):
        for change in ('duplicate', 'unknown'):
            values = copy.deepcopy(self.context)
            if change == 'duplicate': values[0][1] = copy.deepcopy(values[0][0])
            else:
                row = values[0][0]
                values[2].pop(row['original_address'])
            with self.subTest(change=change), self.assertRaises(ValueError): prepared.build_manifest(*values)

    def test_borrowed_cohort_ledger_cannot_relabel_a_record(self):
        values = copy.deepcopy(self.context)
        values[0][0]['source_ledger_sha256'] = values[3]['ordinary-relocation-first3']
        with self.assertRaises(ValueError): prepared.build_manifest(*values)

    def test_unknown_application_identity_mode_and_entry_origin_conflict_are_rejected(self):
        for change in ('mode', 'entry-origin', 'promoted-EH'):
            values = copy.deepcopy(self.context)
            if change == 'mode': values[1][0]['identity_mode'] = 'invented-provider-equivalence'
            elif change == 'entry-origin': values[1][0]['origin_identity']['object_sha256'] = 'f' * 64
            else: values[1][-1]['logical_binding_applied'] = True
            with self.subTest(change=change), self.assertRaises(ValueError): prepared.build_manifest(*values)


if __name__ == '__main__':
    unittest.main()
