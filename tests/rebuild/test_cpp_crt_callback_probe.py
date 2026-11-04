"""Synthetic source-role and peer-gate cases; no compiler/image inputs."""
import copy
import hashlib
import json
from pathlib import Path
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools' / 'rebuild'))
import cpp_crt_callback_probe as probe


def families():
    result = {}
    for family in probe.CPP_LIBS:
        definition = dict(errors=[], section_size=19, value=0, member_header_offset=100, symbol_index=3)
        slot = dict(category='.CRT$XID', target_symbol=probe.SYMBOL, kind=6, addend=0,
            section=2, offset=0, member_header_offset=200, member_sha256='hash',
            native_definition_candidates=[definition])
        result[family] = dict(records=[slot])
    return result


class CppCallbackProbeTests(unittest.TestCase):
    def test_only_one_saved_unmatched_XI_is_selected(self):
        prior = dict(observations=[dict(stage='xi', original_target=probe.TARGET, positive_source_patterns=[]),
                                  dict(stage='xi', original_target=0x401000, positive_source_patterns=['id'])],
            read_bytes=1754, runtime_provider_approved=False)
        self.assertEqual(probe.remaining_XI(prior)['original_target'], probe.TARGET)
        prior['observations'][0]['original_target'] += 1
        with self.assertRaises(ValueError): probe.remaining_XI(prior)

    def test_three_named_C_init_roles_are_not_original_identity(self):
        candidates = probe.select_candidates(families())
        self.assertEqual(len(candidates), 3)
        self.assertEqual(len({r['candidate_id'] for r in candidates}), 3)
        self.assertTrue(all(not r['original_identity_approved'] for r in candidates))

    def test_wrong_XCU_name_span_or_ambiguous_definition_rejected(self):
        for key, wrong in [('category', '.CRT$XCU'), ('target_symbol', 'other')]:
            data = families()
            data['sp1']['records'][0][key] = wrong
            with self.assertRaises(ValueError): probe.select_candidates(data)
        for key, wrong in [('value', 1), ('section_size', 20), ('errors', ['unsupported'])]:
            data = families()
            data['sp1']['records'][0]['native_definition_candidates'][0][key] = wrong
            with self.assertRaises(ValueError): probe.select_candidates(data)

    def test_review_cannot_expand_target_bytes_or_XC_scope(self):
        candidates = probe.select_candidates(families())
        review = dict(kind='fnv-cpp-crt-callback-probe-source-review', status='approved', reviewer='test',
            sources={'fixture': 'hash'}, catalog_sha256='catalog', prior_sha256=probe.PRIOR,
            doctor_sha256=probe.DOCTOR, CPP_libraries=probe.CPP_LIBS,
            candidate_ids=sorted(c['candidate_id'] for c in candidates),
            reference_sha256=probe.common.base.REFERENCE, original_target=probe.TARGET, read_bytes=19,
            allow_original_code_read=True, allow_execute=False, allow_recursive_probes=False,
            XC_targets_in_scope=0, candidate_only=True)
        with tempfile.TemporaryDirectory() as folder:
            path = Path(folder) / 'review.json'
            def check(value):
                path.write_text(json.dumps(value))
                probe.review_gate(path, hashlib.sha256(path.read_bytes()).hexdigest(),
                                  {'fixture': 'hash'}, 'catalog', candidates)
            check(review)
            for key, wrong in [('original_target', probe.TARGET + 1), ('read_bytes', 20),
                               ('XC_targets_in_scope', 1), ('allow_execute', True)]:
                changed = dict(review, **{key: wrong})
                with self.assertRaises(ValueError): check(changed)


if __name__ == '__main__': unittest.main()
