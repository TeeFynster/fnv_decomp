"""Original synthetic COFF only; real entry emission is separately gated."""
import copy
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/rebuild'))
import application_entry_projection as entry
import canonical_reference_groups as groups
from test_canonical_reference_groups import fixture


def projection_fixture():
    data, request = fixture(); closure = request['root_closure']
    closure.update(omitted_definition_conversions=[], references=[dict(section=2,
        offset=row['source_field_offset'], symbol_index=row['coff_relocation']['symbol_index'], kind=20,
        addend_bits=0, original_base='0x00500000', original_target='0x00500000', role='code')
        for row in request['field_proofs']])
    request['root_closure_sha256'] = groups.digest(closure)
    reference = groups.certify(data, request)
    policy = dict(policy_id=entry.POLICY, object_sha256=entry.coff.digest(data), root=request['root'],
        root_certificate_canonical_sha256=groups.digest(closure), reference_certificate_canonical_sha256=groups.digest(reference),
        retained_sections=[1, 2], runtime_sections=[2], primary_records=6, auxiliary_records=1,
        relocations=2, code_bytes=16, reference_members=[1, 2], undefined_records=2, undefined_names=1,
        member_name='original-synthetic-entry.obj')
    return data, closure, reference, policy


class EntryProjectionTests(unittest.TestCase):
    def test_name_only_projection_preserves_distinct_indices_and_archive(self):
        data, closure, reference, policy = projection_fixture(); original = bytes(data)
        member, archive, receipt = entry.project(data, closure, reference, policy)
        self.assertEqual(data, original)
        parsed = entry.coff.parse(member)
        self.assertEqual(parsed['symbols'][1]['name'], parsed['symbols'][2]['name'])
        self.assertEqual(parsed['sections'][2]['relocs'], [(0, 1, 20), (4, 2, 20)])
        self.assertEqual([receipt['mapping']['symbol_map'][i] for i in (1, 2)], [1, 2])
        self.assertEqual(entry.coff.read_archive(archive)['members'], [(policy['member_name'], member)])
        self.assertEqual(receipt['exported_symbols'], ['root_unique'])
        self.assertFalse(receipt['coalescing_performed']); self.assertFalse(receipt['runtime_eligible'])

    def test_frozen_global_duplicate_check_remains_unchanged(self):
        data, _, reference, _ = projection_fixture()
        bindings = [(row['physical_index'], row['name']) for row in reference['namespace_plan']
                    if row['name'] != entry.coff.parse(data)['symbols'][row['physical_index']]['name']]
        with self.assertRaisesRegex(ValueError, 'namespace collision'): entry.coff.namespace(data, bindings)
        entry.guarded_namespace(data, reference['namespace_plan'], reference)

    def test_different_root_certificate_or_missing_group_rejected(self):
        for change in ('root', 'reference', 'members', 'sections', 'slots'):
            data, closure, reference, policy = projection_fixture()
            if change == 'root': policy['root']['section'] = 1
            elif change == 'reference': policy['reference_certificate_canonical_sha256'] = '0' * 64
            elif change == 'members': policy['reference_members'] = [1]
            elif change == 'sections': policy['retained_sections'] = [2]
            else: reference['primary_bijection'][2][1] = 1
            with self.subTest(change=change), self.assertRaises(ValueError): entry.project(data, closure, reference, policy)

    def test_hidden_duplicate_definition_IAT_or_nonzero_field_rejected(self):
        for change in ('hidden', 'definition', 'IAT', 'addend', 'retarget', 'weak', 'mixed_type', 'IAT_spelling', 'different_provider'):
            data, _, reference, _ = projection_fixture(); plan = copy.deepcopy(reference['namespace_plan'])
            if change == 'hidden': plan[0]['name'] = plan[1]['name']; reference['namespace_plan'] = plan
            elif change == 'IAT': reference['group']['role'] = 'iat'
            elif change == 'different_provider': reference['group']['selected_provider_identity']['symbol_index'] = 99
            else:
                obj = entry.coff.parse(data); changed = bytearray(data)
                if change == 'definition': struct.pack_into('<h', changed, obj['symbol_pointer'] + 18 + 12, 2)
                elif change == 'addend': struct.pack_into('<I', changed, 100, 1)
                elif change == 'weak': struct.pack_into('<B', changed, obj['symbol_pointer'] + 18 + 16, 105)
                elif change == 'mixed_type': struct.pack_into('<H', changed, obj['symbol_pointer'] + 18 + 14, 0)
                elif change == 'IAT_spelling': changed[obj['symbol_pointer'] + 18:obj['symbol_pointer'] + 26] = b'__imp_x\0'
                else: struct.pack_into('<I', changed, 116 + 10 + 4, 1)
                data = bytes(changed); reference['object_sha256'] = entry.coff.digest(data)
            with self.subTest(change=change), self.assertRaises(ValueError): entry.guarded_namespace(data, plan, reference)

    def test_payload_and_relocation_drift_rejected_after_serializer(self):
        data, closure, reference, policy = projection_fixture(); real = entry.coff.serialize
        for change in ('payload', 'target'):
            def corrupt(*args):
                member, mapping = real(*args); obj = entry.coff.parse(member); altered = bytearray(member)
                header = 20 + 40
                ptr = struct.unpack_from('<I', member, header + (20 if change == 'payload' else 24))[0]
                if change == 'payload': altered[ptr] = 1
                else: struct.pack_into('<I', altered, ptr + 4, mapping['symbol_map'][2])
                return bytes(altered), mapping
            with self.subTest(change=change), patch.object(entry.coff, 'serialize', side_effect=corrupt):
                with self.assertRaises(ValueError): entry.project(data, closure, reference, policy)

    def test_no_opt_in_never_observes_or_emits(self):
        args = ['entry', '--policy', 'not-read', '--policy-sha256', '0' * 64, '--inputs', 'not-read',
                '--review', 'not-read', '--review-sha256', '0' * 64, '--out', 'never-created']
        with patch.object(sys, 'argv', args), patch.object(entry.references, 'observe_main') as observe:
            with self.assertRaisesRegex(ValueError, 'root opt-in'): entry.main()
            observe.assert_not_called()

    def test_independent_reader_checks_staged_and_recovered_facts(self):
        data, closure, reference, policy = projection_fixture()
        member, archive, receipt = entry.project(data, closure, reference, policy)
        with tempfile.TemporaryDirectory() as tmp:
            original = Path(tmp) / 'original.obj'; stage = Path(tmp) / 'stage.obj'; recovered = Path(tmp) / 'recovered.obj'
            original.write_bytes(data); stage.write_bytes(member)
            recovered.write_bytes(entry.coff.read_archive(archive)['members'][0][1])
            for path in (stage, recovered):
                facts = entry.independent_projection(original, path, reference, receipt)
                self.assertTrue(facts['complete_metadata_and_mapping_match'])
                self.assertEqual(facts['independent_primary_records'], 6)

    def test_independent_reader_rejects_aux_symbol_and_target_forgery(self):
        data, closure, reference, policy = projection_fixture()
        member, _, receipt = entry.project(data, closure, reference, policy)
        for change in ('aux', 'symbol', 'relocation'):
            altered = bytearray(member); obj = entry.coff.parse(member)
            if change == 'aux': struct.pack_into('<I', altered, obj['symbol_pointer'] + 18 * 4 + 8, 123)
            elif change == 'symbol': struct.pack_into('<H', altered, obj['symbol_pointer'] + 18 + 14, 0)
            else:
                relocations_at = struct.unpack_from('<I', altered, 20 + 40 + 24)[0]
                struct.pack_into('<I', altered, relocations_at + 4, 2)
            forged = copy.deepcopy(receipt); forged['member_sha256'] = entry.coff.digest(altered)
            with tempfile.TemporaryDirectory() as tmp:
                original = Path(tmp) / 'original.obj'; stage = Path(tmp) / 'stage.obj'
                original.write_bytes(data); stage.write_bytes(altered)
                with self.subTest(change=change), self.assertRaises(ValueError):
                    entry.independent_projection(original, stage, reference, forged)

    def test_whole_operation_dependency_pins_detect_oracle_and_reader_drift(self):
        policy = json.loads((entry.ROOT / entry.OWNED[2]).read_text(encoding='utf-8'))
        required = {'tools/compare.py', 'tools/function_spans.py', 'tools/build_and_match.py',
                    'tools/rebuild/coff_inventory.py', 'tools/rebuild/coff_rewrite.py'}
        self.assertTrue(required <= set(policy['producer_sha256']))
        self.assertTrue(set(groups.ROOT_DEPENDENCY_PINS) <= set(policy['producer_sha256']))
        with tempfile.TemporaryDirectory() as tmp:
            files = {Path(tmp) / Path(name).name: b'reviewed producer' for name in required}
            for path, data in files.items(): path.write_bytes(data)
            observations = {path: entry.sha(path) for path in files}
            for path in files:
                path.write_bytes(b'changed during comparison')
                with self.assertRaises(ValueError): entry.references.verify_stable(observations)
                path.write_bytes(files[path])

    def test_wrong_source_review_never_reobserves_or_creates_output(self):
        with tempfile.TemporaryDirectory() as tmp:
            review = Path(tmp) / 'review.json'
            review.write_text(json.dumps(dict(schema_version=1, kind='application-entry-projection-source-review',
                status='approved', reviewer='synthetic', allow_private_emission=True, allow_native=False, sources={})))
            policy = entry.ROOT / entry.OWNED[2]
            argv = ['entry', '--policy', str(policy), '--policy-sha256', entry.sha(policy), '--inputs', 'not-read',
                    '--review', str(review), '--review-sha256', entry.sha(review), '--out', 'never-created', '--allow-private-emission']
            with patch.object(sys, 'argv', argv), patch.object(entry.references, 'observe_main') as observe:
                with self.assertRaisesRegex(ValueError, 'unapproved source'): entry.main()
                observe.assert_not_called()


if __name__ == '__main__': unittest.main()
