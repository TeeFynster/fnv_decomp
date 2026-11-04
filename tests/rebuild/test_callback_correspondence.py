"""Synthetic correspondence/scoping evidence; no original or native inputs."""
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools' / 'rebuild'))
import callback_correspondence as correspondence


def native(member=1, family='family'):
    return dict(family=family, definition=dict(member_header_offset=member, member_sha256=str(member)))


class CorrespondenceTests(unittest.TestCase):
    def test_external_names_form_consistency_hypotheses_not_static_aliases(self):
        field = dict(symbol='_atexit', symbol_storage=2, symbol_index=3)
        self.assertEqual(correspondence.linkage_key(native(1), field), correspondence.linkage_key(native(2), field))
        field['symbol_storage'] = 3
        self.assertNotEqual(correspondence.linkage_key(native(1), field), correspondence.linkage_key(native(2), field))

    def test_public_literal_names_and_weak_records_stay_physical(self):
        field = dict(symbol='??_C@literal', symbol_storage=2, symbol_index=3)
        self.assertNotEqual(correspondence.linkage_key(native(1), field), correspondence.linkage_key(native(2), field))
        field.update(symbol='_weak', symbol_storage=105)
        self.assertNotEqual(correspondence.linkage_key(native(1), field), correspondence.linkage_key(native(2), field))

    def test_same_named_body_profiles_preserve_alternatives_without_approval(self):
        callback = dict(stage='xi', original_target_va=100)
        rows = [dict(symbol='init', family=f, full_nonrelocation_span_equal=True) for f in ('one', 'two')]
        result = correspondence.classify_callback(callback, rows)
        self.assertEqual(result['classification'], 'NAMED_NATIVE_BODY_CORRESPONDENCE')
        self.assertEqual(len(result['matching_profiles']), 2)
        self.assertFalse(result['original_function_identity_approved'])
        self.assertFalse(result['relocation_identities_closed'])

    def test_distinct_matching_symbols_stay_ambiguous(self):
        rows = [dict(symbol=name, full_nonrelocation_span_equal=True) for name in ('init', 'other')]
        result = correspondence.classify_callback(dict(stage='xp'), rows)
        self.assertEqual(result['classification'], 'AMBIGUOUS_NATIVE_BODY_CORRESPONDENCE')
        self.assertFalse(result['runtime_provider_approved'])

    def test_failed_signatures_do_not_become_named_correspondence(self):
        result = correspondence.classify_callback(dict(stage='xc'),
            [dict(symbol='init', full_nonrelocation_span_equal=False)])
        self.assertEqual(result['classification'], 'NO_SAVED_SOURCE_BODY_CORRESPONDENCE')
        self.assertEqual(result['matching_profiles'], [])


if __name__ == '__main__': unittest.main()
