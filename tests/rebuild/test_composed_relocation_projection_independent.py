"""Independent typed LABEL/field cases; original authored COFF only."""
import copy
import hashlib
import json
from pathlib import Path
import sys
import struct
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT / 'tools/rebuild'), str(ROOT / 'tests/rebuild')]
import coff_code_archive as coff
import root_code_closure as ordinary
import root_certificate_composer as composer
import local_label_projection as labels
import runtime_code_pool as pool
import bulk_code_pool as bulk
import composed_relocation_projection as projection
from test_local_label_projection import decoder_fixture
from test_coff_code_archive import object_bytes, symbol


def typed_label_context(addend=0, source_basis='EXACT_LOCAL_FUNCTION_CONTAINMENT', owner_offset_delta=0):
    raw, evidence, contract, _ = decoder_fixture()
    contract['provenance'].update(recipe_id='authored', recipe_index=0)
    if addend:
        obj = coff.parse(raw)
        sections = list(obj['sections'].values())
        payload = bytearray(sections[1]['payload'])
        struct.pack_into('<I', payload, 0, addend & 0xffffffff)
        sections[1] = dict(sections[1], payload=bytes(payload))
        symbols = [symbol(s['name'], s['section'], s['value'], s['type'], s['storage'], s['aux'])
                   for s in obj['symbols'].values()]
        raw = object_bytes(sections, symbols)
        evidence['object_sha256'] = hashlib.sha256(raw).hexdigest()
        contract['provenance']['object_sha256'] = evidence['object_sha256']
        field = next(f for f in evidence['fields'] if f['physical_section'] == 2 and f['physical_offset'] == 0)
        field['coff_relocation']['addend'] = addend & 0xffffffff
        field['exact_original_target_va'] = '0x%08x' % ((int(field['derived_source_symbol_base_va'], 16) + addend) & 0xffffffff)
        field['original_operand'] = int(field['exact_original_target_va'], 16)
    for field in evidence['fields']:
        field.update(recipe_index=0, function_symbol='_root' if field['physical_section'] == 2 else '_omitted',
                     source_resolution_basis=source_basis, code_ownership_ambiguous=False,
                     code_owners=[dict(address=field['function_va'], offset=int(field['exact_original_target_va'], 16) -
                                      int(field['function_va'], 16) + owner_offset_delta)],
                     expected_original_target_va=field['exact_original_target_va'])
        field['coff_relocation']['conservative_extent'] = 4
    evidence['contract_sha256'] = composer.digest(contract)
    base = ordinary.assess_object(coff.parse(raw), contract)
    certificate = labels.prove_labels(raw, evidence)
    witnesses = [dict(kind='typed-local-label-omission-witness', evidence_json=certificate.evidence_json,
                      decision_json=certificate.decision_json,
                      decoded=labels.decode_label_policy(raw, contract, base, certificate))]
    composed = composer.compose(raw, contract, base, witnesses, policy_id=composer.POLICY)
    root = dict(contract['roots'][0], recipe_id='authored', recipe_index=0,
                object_sha256=hashlib.sha256(raw).hexdigest(), source_sha256=evidence['source_sha256'])
    providers = {root['original_address']: {k: root[k] for k in ('recipe_id', 'object_sha256', 'symbol_index')}}
    return raw, contract, base, witnesses, composed, [root], providers


def assess(values, **kwargs):
    return projection.assess_member(*values, existing_exports=kwargs.pop('existing_exports', set()),
                                     policy_id=kwargs.pop('policy_id', projection.POLICY), **kwargs)


def project(values, **kwargs):
    return projection.project_member(*values, existing_exports=kwargs.pop('existing_exports', set()),
                                      policy_id=kwargs.pop('policy_id', projection.POLICY), **kwargs)


class IndependentComposedLabelTests(unittest.TestCase):
    def test_label_proof_keeps_false_original_base_and_exact_field_graph(self):
        values = typed_label_context()
        self.assertFalse(values[2]['closure_observed'])
        self.assertTrue(values[4]['composed_omission_complete'])
        before = copy.deepcopy(values)
        assessment = assess(values)
        self.assertTrue(assessment['eligible'])
        output, receipt = project(values)
        self.assertEqual(values, before)
        original, final = coff.parse(values[0]), coff.parse(output)
        maps = receipt['maps']; sm, ym = maps['section_map'], maps['symbol_map']
        for index, symbol in original['symbols'].items():
            if symbol['storage'] == 6 and index in ym:
                expected = dict(symbol, section=sm[symbol['section']])
                self.assertEqual(final['symbols'][ym[index]], expected)
        for old, new in sm.items():
            self.assertEqual(final['sections'][new]['payload'], original['sections'][old]['payload'])
            self.assertEqual(final['sections'][new]['relocs'],
                             [(off, ym[target], kind) for off, target, kind in original['sections'][old]['relocs']])
        identity = {k: values[5][0][k] for k in ('recipe_id', 'object_sha256', 'symbol_index')}
        self.assertEqual(coff.exports(output), [pool.canonical(identity)])
        self.assertFalse(receipt['runtime_eligible'])
        self.assertFalse(values[2]['closure_observed'])

    def test_explicit_typed_policy_required_and_no_boolean_positive_substitution(self):
        values = typed_label_context()
        for wrong in (ordinary.POLICY, composer.POLICY, 'unreviewed-policy'):
            with self.subTest(policy=wrong), self.assertRaises(ValueError): project(values, policy_id=wrong)
        changed = copy.deepcopy(values)
        changed[2]['closure_observed'] = True
        changed[2]['blockers'] = []
        with self.assertRaises(ValueError): project(changed)

    def test_stale_or_borrowed_label_evidence_cannot_authorize_projection(self):
        values = typed_label_context()
        for change in ('source', 'object', 'contract', 'base', 'decision', 'decoded', 'composition'):
            altered = copy.deepcopy(values)
            if change in ('source', 'object', 'contract'):
                evidence = json.loads(altered[3][0]['evidence_json'])
                evidence[change + '_sha256'] = 'f' * 64
                altered[3][0]['evidence_json'] = json.dumps(evidence, sort_keys=True, separators=(',', ':'))
            elif change == 'base': altered[2]['blockers'] = []
            elif change == 'decision': altered[3][0]['decision_json'] += ' '
            elif change == 'decoded': altered[3][0]['decoded']['discharged_blocker_ids'] = []
            else: altered[4]['composed_omission_complete'] = False
            with self.subTest(change=change), self.assertRaises(ValueError): project(altered)

    def test_frozen_writer_is_not_replaced_or_storage_class_normalized(self):
        values = typed_label_context()
        original_serialize = coff.serialize
        observed = []
        def frozen_writer(*args, **kwargs):
            obj = coff.parse(args[0])
            observed.append([s['storage'] for s in obj['symbols'].values()])
            return original_serialize(*args, **kwargs)
        with patch.object(coff, 'serialize', side_effect=frozen_writer):
            output, receipt = project(values)
        self.assertEqual(observed, [])  # Typed LABEL writer handles actual6 directly.
        mapped = receipt['maps']['symbol_map']
        self.assertTrue(any(s['storage'] == 6 for s in coff.parse(output)['symbols'].values()))
        self.assertNotIn(3, mapped)  # Omitted same-spelling local label stays omitted.

    def test_existing_logical_root_cannot_be_emitted_again(self):
        values = typed_label_context()
        identity = {k: values[5][0][k] for k in ('recipe_id', 'object_sha256', 'symbol_index')}
        with self.assertRaises(ValueError): project(values, existing_exports={pool.canonical(identity)})

    def test_label_containment_basis_does_not_authorize_guessed_binding(self):
        values = typed_label_context(source_basis='GUESSED_NEAREST_ENTRY')
        self.assertTrue(values[4]['composed_omission_complete'])
        with self.assertRaises(ValueError): project(values)

    def test_label_owner_offset_must_follow_final_target_not_symbol_base(self):
        values = typed_label_context(addend=4, owner_offset_delta=-4)
        self.assertTrue(values[4]['composed_omission_complete'])
        with self.assertRaises(ValueError): project(values)

    def test_mutated_cached_assessment_cannot_bypass_full_replay(self):
        values = typed_label_context()
        cached = assess(values)
        cached['eligible'] = True
        with self.assertRaises(TypeError): project(values, assessment=cached)
        altered = copy.deepcopy(values)
        altered[3][0]['decoded']['discharged_blocker_ids'] = []
        with self.assertRaises(ValueError): project(altered)

    def test_unchanged_comparator_resolves_nonzero_local_values_without_global_aliases(self):
        values = typed_label_context(addend=4)
        output, receipt = project(values)
        root = values[5][0]
        original = bytearray(coff.parse(values[0])['sections'][root['section']]['payload'])
        for field in values[1]['fields']:
            struct.pack_into('<I', original, field['source_field_offset'], field['original_operand'])
        # Original synthetic relocation targets, with no PE image or game input.
        pe = SimpleNamespace(read=lambda address, size: bytes(original) if
                             (address, size) == (int(root['original_address'], 16), root['size']) else b'')
        sys.path.insert(0, str(ROOT / 'tools'))
        contracts = [dict(selected={k: root[k] for k in ('original_address', 'symbol', 'symbol_index', 'section', 'value', 'size')})]
        plan = dict(bindings=receipt['namespace_bindings'], comparison_base_view=receipt['comparison_base_view'])
        self.assertFalse(set(plan['comparison_base_view']) & {'$LN1', '$LN2', '$LN3'})
        self.assertEqual(struct.unpack_from('<I', coff.parse(output)['sections'][1]['payload'], 0)[0], 4)
        with tempfile.TemporaryDirectory() as td:
            before, after = Path(td) / 'authored-before.obj', Path(td) / 'authored-after.obj'
            before.write_bytes(values[0]); after.write_bytes(output)
            first = bulk.compare_functions(before, pe, contracts, {})
            second = bulk.compare_functions(after, pe, contracts, {}, plan)
            self.assertEqual([r['verdict'] for r in first + second], ['match', 'match'])
            self.assertTrue(all(r['match'] for row in second for r in row['relocations']))
            wrong = copy.deepcopy(plan)
            wrong['comparison_base_view']['$LN1'] = root['original_address']
            with self.assertRaises(ValueError): bulk.compare_functions(after, pe, contracts, {}, wrong)


if __name__ == '__main__':
    unittest.main()
