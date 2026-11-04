"""Authored synthetic COFF only. No Game object, image or native process."""
import copy
import gzip
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/rebuild'))
import union_reference_groups_v2 as v2
from test_bulk_code_pool import fixture_parts, make
from test_coff_code_archive import symbol, aux, section


def fixture(mixed=False, literal=False):
    sections, symbols = fixture_parts()
    symbols[5] = symbol('_original_ref_a', 0, typ=32)
    symbols.append(symbol('_original_ref_b', 0, typ=32))
    sections[1]['relocs'] = [(0, 11 if mixed else 8, 20)]
    if mixed:
        sections[2]['relocs'] = []
        symbols[3] = symbol('.text', 3, storage=3, auxiliary=aux(8, 0))
    else:
        sections[2]['relocs'] = [(0, 11, 20)]
    if literal:
        assert not mixed
        sections[1]['payload'] = bytes(8)
        sections[1]['relocs'].append((4, 14, 6))
        symbols[1] = symbol('.text', 2, storage=3, auxiliary=aux(8, 2))
        sections.append(section('.rdata', b'AUTHORED', flags=0x40401040))
        symbols.extend([symbol('.rdata', 4, storage=3, auxiliary=aux(8, selection=2)), symbol('_authored_literal', 4)])
    data, contracts = make(sections, symbols)
    identity = (contracts[1]['provider_identities']['0x00402000'] if mixed else
                dict(recipe_id='external-selected-owner', object_sha256='b' * 64, symbol_index=21))
    base = '0x00402000' if mixed else '0x00500000'
    for contract in contracts:
        contract['provider_identities'][base] = identity
        if literal and contract['selected']['section'] == 2: contract['literal_sections'] = [4]
        for row in contract['fields']:
            relocation = row['coff_relocation']; relocation.update(width=4, conservative_extent=4)
            is_literal = relocation['symbol_index'] == 14
            target = '0x01002000' if is_literal else base
            row.update(classification='COMPILER_LITERAL_FULL_READONLY_NONPOINTER_EQUALITY' if is_literal else 'SELECTED_CODE_ENTRY', derived_source_symbol_base_va=target,
                exact_original_target_va=target, expected_original_target_va=target,
                original_field_va='0x%08x' % (int(row['function_va'], 16) + row['source_field_offset']),
                code_ownership_ambiguous=False, code_owners=[] if is_literal else [dict(address=target, offset=0)],
                source_resolution_basis='OWN_RECIPE_BINDING')
            row['original_operand'] = (int(target, 16) - (int(row['original_field_va'], 16) + 4 if relocation['kind'] == 20 else 0)) & 0xffffffff
            if is_literal:
                row['literal'] = dict(extent=8, payload_sha256=v2.coff.digest(b'AUTHORED'), full_extent_equal=True,
                    source_and_original_readonly=True, no_source_relocations_or_original_HIGHLOW=True)
    plan = v2.bulk.plan_union(data, contracts)
    providers = {v2.pool.canonical(identity): [dict(original_address=base, identity=identity,
        inventory_row=dict(ordinal=1, sha256='c' * 64))]}
    return data, contracts, plan, providers


class UnionReferenceV2Tests(unittest.TestCase):
    def certify(self, values):
        return v2.certify_union(*values, provenance=dict(kind='authored-synthetic-only'))

    def test_two_original_undefined_records_keep_distinct_indices(self):
        values = fixture(); data, contracts, plan, providers = values
        certificate = self.certify(values)
        self.assertEqual(certificate['groups'][0]['kind'], 'all-original-undefined')
        output, receipt = v2.serialize_union_v2(data, contracts, plan, providers, certificate)
        parsed = v2.coff.parse(output); mapping = receipt['maps']['symbol_map']
        self.assertNotEqual(mapping[8], mapping[11])
        self.assertEqual(parsed['symbols'][mapping[8]]['name'], parsed['symbols'][mapping[11]]['name'])
        self.assertEqual(parsed['sections'][2]['relocs'], [(0, mapping[8], 20)])
        self.assertEqual(parsed['sections'][3]['relocs'], [(0, mapping[11], 20)])
        self.assertFalse(receipt['coalescing_performed']); self.assertFalse(receipt['runtime_eligible'])

    def test_one_real_definition_and_undefined_preserve_both_records(self):
        data, contracts, plan, providers = fixture(True)
        certificate = self.certify((data, contracts, plan, providers))
        self.assertEqual(certificate['groups'][0]['kind'], 'one-selected-definition-and-undefined')
        output, receipt = v2.serialize_union_v2(data, contracts, plan, providers, certificate)
        obj = v2.coff.parse(output); ym = receipt['maps']['symbol_map']
        self.assertNotEqual(ym[7], ym[11])
        self.assertEqual(obj['symbols'][ym[7]]['section'], 3)
        self.assertEqual(obj['symbols'][ym[11]]['section'], 0)
        self.assertEqual(obj['symbols'][ym[7]]['name'], obj['symbols'][ym[11]]['name'])
        self.assertEqual(obj['sections'][2]['relocs'], [(0, ym[11], 20)])
        self.assertEqual(len(receipt['exports']), 2)

    def test_persisted_json_map_keys_recompute_without_remapping(self):
        data, contracts, plan, providers = fixture(True)
        persisted = json.loads(json.dumps(plan))
        self.assertEqual(v2.digest(plan), v2.digest(persisted))
        certificate = json.loads(json.dumps(self.certify((data, contracts, persisted, providers))))
        v2.serialize_union_v2(data, contracts, persisted, providers, certificate)
        with self.assertRaises(ValueError): v2.normalized({1: 1, '1': 2})

    def test_frozen_bulk_and_namespace_guards_are_not_weakened(self):
        data, contracts, plan, providers = fixture(True)
        self.assertFalse(plan['eligible'])
        with self.assertRaises(ValueError): v2.bulk.serialize_union(data, contracts, plan)
        with self.assertRaises(ValueError): v2.coff.namespace(data, plan['bindings'])
        self.certify((data, contracts, plan, providers))

    def test_missing_whole_root_or_field_and_forged_maps_fail(self):
        for change in ('root', 'field', 'map', 'namespace', 'group'):
            data, contracts, plan, providers = fixture()
            if change == 'root': contracts.pop()
            elif change == 'field': contracts[0]['fields'].clear()
            elif change == 'map': plan['symbol_map'][11] = plan['symbol_map'][8]
            elif change == 'namespace': plan['namespace_plan'].pop()
            else: plan['blockers'].clear()
            with self.subTest(change=change), self.assertRaises(ValueError):
                self.certify((data, contracts, plan, providers))

    def test_role_base_provider_interior_operand_and_type_fail(self):
        for change in ('data', 'IAT', 'target', 'ambiguous', 'operand', 'provider'):
            data, contracts, plan, providers = fixture()
            row = contracts[0]['fields'][0]
            if change in ('data', 'IAT'):
                row['classification'] = 'ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER' if change == 'data' else 'IAT_POINTER_CELL_NOT_FUNCTION_BODY'
            elif change == 'target': row['code_owners'] = [dict(address='0x00500000', offset=4)]
            elif change == 'ambiguous': row['code_ownership_ambiguous'] = True
            elif change == 'operand': row['original_operand'] += 4
            else: next(iter(providers.values()))[0]['original_address'] = '0x00500004'
            # Keep a fresh saved plan so the new semantic guard is exercised.
            fresh = v2.bulk.plan_union(data, contracts)
            with self.subTest(change=change), self.assertRaises(ValueError):
                self.certify((data, contracts, fresh, providers))

    def test_native_weak_common_definition_aux_and_type_shapes_fail(self):
        for change in ('weak', 'common', 'definition', 'type'):
            data, contracts, plan, providers = fixture(); obj = v2.coff.parse(data); altered = bytearray(data)
            offset = obj['symbol_pointer'] + 18 * 8
            if change == 'weak': struct.pack_into('<B', altered, offset + 16, 105)
            elif change == 'common': struct.pack_into('<I', altered, offset + 8, 4)
            elif change == 'definition': struct.pack_into('<h', altered, offset + 12, 2)
            else: struct.pack_into('<H', altered, offset + 14, 0)
            with self.subTest(change=change), self.assertRaises(ValueError):
                self.certify((bytes(altered), contracts, plan, providers))

    def test_two_strong_definitions_and_unknown_blockers_stay_blocked(self):
        data, contracts, plan, providers = fixture(True)
        forged = copy.deepcopy(plan)
        forged['blockers'].append(dict(code='FRESH_ROOT_BLOCKED', evidence='not waivable'))
        fields = [r for c in contracts for r in c['fields']]
        self.assertFalse(v2.assess_saved_union(forged, fields, providers)['metadata_candidate'])
        # Two roots advertised under the same canonical name cannot be hidden.
        forged = copy.deepcopy(plan); target = next(iter(providers))
        forged['bindings'] = [[i, target if i == 4 else name] for i, name in forged['bindings']]
        for row in forged['namespace_plan']:
            if row['physical_index'] == 4: row['name'] = target
        forged['blockers'][0]['evidence']['indices'].append(4)
        result = v2.assess_saved_union(forged, fields, providers)
        self.assertFalse(result['metadata_candidate'])
        self.assertIn('MULTIPLE_RETAINED_STRONG_DEFINITIONS', result['groups'][0]['reasons'])

    def test_certificate_or_serialized_payload_tampering_rejected(self):
        data, contracts, plan, providers = fixture(True); certificate = self.certify((data, contracts, plan, providers))
        forged = copy.deepcopy(certificate); forged['groups'][0]['members'] = [7]
        with self.assertRaises(ValueError): v2.namespace_union_v2(data, contracts, plan, providers, forged)
        real = v2.coff.serialize
        def corrupt(*args):
            output, maps = real(*args); altered = bytearray(output)
            ptr = struct.unpack_from('<I', altered, 20 + 40 + 20)[0]; altered[ptr] = 1
            return bytes(altered), maps
        with patch.object(v2.coff, 'serialize', side_effect=corrupt):
            with self.assertRaises(ValueError): v2.serialize_union_v2(data, contracts, plan, providers, certificate)

    def test_metadata_loader_does_not_accept_arbitrary_or_missing_inputs(self):
        with self.assertRaisesRegex(ValueError, 'exact saved-input'):
            v2.load_saved_metadata({})

    def test_unrelated_preproved_literal_export_is_preserved_not_guessed_by_count(self):
        data, contracts, plan, providers = fixture(literal=True)
        certificate = self.certify((data, contracts, plan, providers))
        output, receipt = v2.serialize_union_v2(data, contracts, plan, providers, certificate)
        self.assertEqual(len(receipt['exports']), 3)
        self.assertEqual(v2.coff.parse(output)['sections'][4]['payload'], b'AUTHORED')
        actual_exports = receipt['exports']
        with patch.object(v2.coff, 'exports', return_value=actual_exports[:-1] + ['_unrelated_wrong_definition']):
            with self.assertRaisesRegex(ValueError, 'strong export'):
                v2.serialize_union_v2(data, contracts, plan, providers, certificate)

    def test_nonzero_group_addend_cannot_gain_certificate(self):
        data, contracts, _, providers = fixture()
        contracts[0]['fields'][0]['coff_relocation']['addend'] = 4
        contracts[0]['fields'][0]['exact_original_target_va'] = '0x00500004'
        plan = v2.bulk.plan_union(data, contracts)
        with self.assertRaises(ValueError): self.certify((data, contracts, plan, providers))

    def test_stream_skips_large_emitted_metadata_without_losing_blocked_ordinal(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'unions.gz'
            with gzip.open(path, 'wt') as target:
                target.write(json.dumps(dict(event='EMITTED_RECIPE_UNION', receipt='x' * 150000), separators=(',', ':')) + '\n')
                target.write('{"event":"BLOCKED_RECIPE_UNION","plan":{}}\n')
            self.assertEqual(list(v2.saved_records(path, unions=True)), [(2, dict(event='BLOCKED_RECIPE_UNION', plan={}))])

    def test_policy_matches_fixed_input_and_producer_pins(self):
        root = Path(__file__).resolve().parents[2]
        policy = json.loads((root / 'runtime/code-pools/union-reference-groups-v2.json').read_text())
        self.assertEqual(policy['input_sha256'], v2.INPUT_PINS)
        self.assertEqual(policy['producer_sha256'], {'tools/rebuild/' + k: value for k, value in v2.PRODUCER_PINS.items()})
        self.assertFalse(policy['real_subset_emission_authorized'])
        self.assertEqual(policy['required_coff_type'], 32)

    def test_current_index_and_producer_change_fail_before_metadata_decode(self):
        with tempfile.TemporaryDirectory() as tmp:
            repository = Path(tmp); (repository / 'build').mkdir()
            (repository / 'build/function_index.json').write_text('{}')
            paths = {key: repository / key for key in v2.INPUT_PINS}
            def fixed_hash(path):
                name = Path(path).name
                return v2.INPUT_PINS.get(name, v2.PRODUCER_PINS.get(name, 'e' * 64))
            with patch.object(v2.pool, 'file_hash', side_effect=fixed_hash):
                with self.assertRaisesRegex(ValueError, 'current optional index'):
                    v2.load_saved_metadata(paths, repository=repository)
            def stale_hash(path):
                return '0' * 64 if Path(path).name == 'bulk_code_pool.py' else fixed_hash(path)
            with patch.object(v2.pool, 'file_hash', side_effect=stale_hash):
                with self.assertRaisesRegex(ValueError, 'stale producer'):
                    v2.load_saved_metadata(paths, repository=repository)


if __name__ == '__main__': unittest.main()
