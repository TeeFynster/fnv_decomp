"""Authored synthetic omission tests; no original objects or image accesses."""
import copy
from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT/'tools/rebuild'), str(ROOT/'tests/rebuild')]
import ordinary_initialized_data_omission as witness
import coff_code_archive as coff
import root_code_closure as ordinary
import scalableordinary_root_collect as collector
from test_scalableordinary_root_collect import fixture
from test_coff_code_archive import section, symbol, aux, object_bytes


def context(flags=0x40300040, name='.rdata', incoming=False, outgoing=False,
            alias=False, special=False, selection=0, retained=False):
    raw, unit, proof, requested, _, _, bindings = fixture()
    obj = coff.parse(raw)
    sections = list(obj['sections'].values())
    symbols = [symbol(s['name'], s['section'], s['value'], s['type'], s['storage'], s['aux'])
               for s in obj['symbols'].values()]
    payload = b'authored unused readonly value'
    sections.append(section(name, payload, flags, [(0, 2, 6)] if outgoing else []))
    symbols += [symbol(name, 4, storage=3, auxiliary=aux(len(payload), int(outgoing), selection)),
                symbol('__ehfuncinfo$bad' if special else '_datum', 4, storage=3)]
    if incoming:
        sections[0 if retained else 1]['relocs'] = [(0, 11, 6)]
        symbols[0 if retained else 2] = symbol('.text', 1 if retained else 2,
                                                storage=3, auxiliary=aux(16 if retained else 8, 1, 1))
    if alias: symbols.append(symbol('_datum', 0))
    raw = object_bytes(sections, symbols)
    unit['object_sha256'] = proof['object_sha256'] = coff.digest(raw)
    for row in requested: row['object_sha256'] = coff.digest(raw)
    provenance = dict(object_sha256=coff.digest(raw), source_sha256=unit['source_sha256'],
                      recipe_id=unit['recipe_id'], recipe_index=unit['recipe_index'])
    contract = collector.build_contract(unit, proof, requested[:1], bindings, {}, provenance)
    cert = ordinary.assess_object(coff.parse(raw), contract)
    return raw, contract, cert, [4]


class InitializedDataOmissionTests(unittest.TestCase):
    def test_unused_exact_form_produces_only_typed_witness(self):
        args = context(); before = copy.deepcopy(args)
        result = witness.observe_omitted_initialized_data(*args)
        self.assertTrue(result['witness_complete'])
        self.assertEqual(len(result['discharge_blocker_ids']), 1)
        self.assertEqual(result['remaining_blockers'], [])
        self.assertEqual(args, before)
        for key in witness.FALSE: self.assertIs(result[key], False)
        self.assertFalse(result['adapted_root_certificate_created'])

    def test_second_exact_alignment_form_with_selection_one(self):
        result = witness.observe_omitted_initialized_data(*context(flags=0x40101040, selection=1))
        self.assertTrue(result['witness_complete'])

    def test_unknown_flags_special_names_and_mutable_data_not_generalized(self):
        for flags, name in [(0x40400040, '.rdata'), (0x40300040, '.xdata$x'),
                            (0x40300040, '.tls$'), (0x40300040, '.CRT$XCU'),
                            (0xc0300040, '.data'), (0x60300040, '.rdata')]:
            with self.subTest(flags=flags, name=name):
                self.assertFalse(witness.observe_omitted_initialized_data(*context(flags=flags, name=name))['witness_complete'])

    def test_outgoing_pointer_field_stays_blocked(self):
        result = witness.observe_omitted_initialized_data(*context(outgoing=True))
        self.assertFalse(result['witness_complete'])
        self.assertIn('CANDIDATE_OUTGOING_FIELDS_UNSUPPORTED', {b['code'] for b in result['rows'][0]['blockers']})

    def test_isolated_incoming_from_omitted_code_proves_only_local_omission(self):
        result = witness.observe_omitted_initialized_data(*context(incoming=True))
        self.assertTrue(result['witness_complete'])
        self.assertEqual(result['rows'][0]['original_data_field_classification'], 'NO_RETAINED_DATA_FIELDS_OMITTED_ONLY_PHYSICAL_USES')
        self.assertFalse(result['rows'][0]['original_data_type_or_base_binding_proved'])

    def test_incoming_from_retained_code_fails(self):
        result = witness.observe_omitted_initialized_data(*context(incoming=True, retained=True))
        self.assertFalse(result['witness_complete'])

    def test_name_alias_and_compiler_identity_fail(self):
        for kwargs in [dict(alias=True), dict(special=True)]:
            self.assertFalse(witness.observe_omitted_initialized_data(*context(**kwargs))['witness_complete'])

    def test_transitive_call_into_otherwise_omitted_code_protects_data(self):
        raw, contract, _, sections = context(incoming=True)
        obj = coff.parse(raw)
        sec = list(obj['sections'].values())
        symbols = [symbol(s['name'], s['section'], s['value'], s['type'], s['storage'], s['aux'])
                   for s in obj['symbols'].values()]
        sec[0]['relocs'] = [(4, 5, 20)]
        symbols[0] = symbol('.text', 1, storage=3, auxiliary=aux(16, 1, 1))
        raw = object_bytes(sec, symbols); contract['provenance']['object_sha256'] = coff.digest(raw)
        cert = ordinary.assess_object(coff.parse(raw), contract)
        result = witness.observe_omitted_initialized_data(raw, contract, cert, sections)
        self.assertFalse(result['witness_complete'])
        self.assertIn('INCOMING_USE_FROM_PROTECTED_CODE', {b['code'] for b in result['rows'][0]['blockers']})

    def test_compiler_runtime_and_rtti_families_are_not_ordinary_constants(self):
        for name in ['??_R0Authored', '__CxxFrameHandler3', '__security_cookie', '__SEH_handler',
                     '__RTC_state', '__tls_used', '__xc_a', '_load_config_used']:
            self.assertTrue(witness.special_symbol(name), name)

    def test_missing_source_lineage_does_not_become_authenticated(self):
        raw, contract, _, sections = context()
        contract['provenance'].pop('source_sha256')
        cert = ordinary.assess_object(coff.parse(raw), contract)
        with self.assertRaises(ValueError):
            witness.observe_omitted_initialized_data(raw, contract, cert, sections)

    def test_selection_two_not_supported_as_one(self):
        result = witness.observe_omitted_initialized_data(*context(flags=0x40101040, selection=2))
        self.assertFalse(result['witness_complete'])

    def test_stale_object_or_forged_certificate_fail_before_witness(self):
        raw, contract, cert, sections = context()
        with self.assertRaises(ValueError):
            witness.observe_omitted_initialized_data(raw+b'changed', contract, cert, sections)
        bad = copy.deepcopy(cert); bad['blockers'] = []
        with self.assertRaises(ValueError):
            witness.observe_omitted_initialized_data(raw, contract, bad, sections)

    def test_requested_section_set_is_exact_and_omitted(self):
        raw, contract, cert, _ = context()
        for invalid in [[], [4, 4], [False], [999]]:
            with self.subTest(invalid=invalid), self.assertRaises(ValueError):
                witness.observe_omitted_initialized_data(raw, contract, cert, invalid)
        self.assertFalse(witness.observe_omitted_initialized_data(raw, contract, cert, [1])['witness_complete'])

    def test_exact_original_blocker_required(self):
        result = witness.observe_omitted_initialized_data(*context(flags=0x40301040, selection=1))
        self.assertFalse(result['witness_complete'])
        self.assertIn('EXACT_ORIGINAL_SECTION_BLOCKER_REQUIRED', {b['code'] for b in result['rows'][0]['blockers']})


if __name__ == '__main__': unittest.main()
