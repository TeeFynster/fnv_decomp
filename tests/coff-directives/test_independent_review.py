"""Independent API-integrity regressions using only synthetic payloads."""
import copy
import dataclasses
import unittest
from test_coff_directives import cd, run, DEFAULT

class ReviewTests(unittest.TestCase):
    def test_nested_witness_access_and_to_dict_are_defensive(self):
        result = run(DEFAULT)
        before = cd.canonical_json(result.to_dict())
        exposed = result.to_dict()
        exposed['inputs']['context']['raw_size'] += 1
        exposed['existing_contract_observation']['raw_tokens_equal_existing_default'] = False
        exposed['reviewable_conjunct']['ordered_families'].append('fabricated')
        result.inputs['context']['raw_size'] += 1
        result.existing_contract_observation['relocation_count_zero'] = False
        result.reviewable_conjunct['ordered_families'].append('fabricated')
        self.assertEqual(cd.canonical_json(result.to_dict()), before)
        self.assertEqual(cd.compute_binding(result.inputs), result.binding_sha256)

    def test_constructor_detaches_nested_input_references(self):
        original = run(DEFAULT)
        supplied = copy.deepcopy(original.inputs)
        candidate = dataclasses.replace(original, inputs=supplied)
        before = cd.canonical_json(candidate.to_dict())
        supplied['context']['raw_size'] += 1
        self.assertEqual(cd.canonical_json(candidate.to_dict()), before)
        self.assertEqual(cd.compute_binding(candidate.inputs), candidate.binding_sha256)
