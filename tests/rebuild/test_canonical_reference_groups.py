"""Original synthetic COFF only; no native tools or application observation."""
import copy
import hashlib
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import Mock

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/rebuild'))
import canonical_reference_groups as groups


def fixture():
    payload = bytes(16)
    directives = b'/DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES" '
    relocations = struct.pack('<IIHIIH', 0, 1, 20, 4, 2, 20)
    symbols = b''.join(struct.pack('<8sIhHBB', name.ljust(8, b'\0'), value, section, typ, storage, aux)
        for name, value, section, typ, storage, aux in
        [(b'root', 0, 2, 32, 2, 0), (b'alpha', 0, 0, 32, 2, 0),
         (b'beta', 0, 0, 32, 2, 0), (b'.text', 0, 2, 0, 3, 1)])
    symbols += struct.pack('<IHHIhBBH', 16, 2, 0, 0, 0, 1, 0, 0)
    symbols += struct.pack('<8sIhHBB', b'.drectve', 0, 1, 0, 3, 0)
    symbols += struct.pack('<8sIhHBB', b'@comp.id', 1, -1, 0, 3, 0)
    data = struct.pack('<HHIIIHH', 0x14c, 2, 0, 136 + len(directives), 7, 0, 0)
    data += struct.pack('<8sIIIIIIHHI', b'.drectve', 0, 0, len(directives), 136, 0, 0, 0, 0, 0x100a00)
    data += struct.pack('<8sIIIIIIHHI', b'.text', 0, 0, 16, 100, 116, 0, 2, 0, 0x60501020)
    data += payload + relocations + directives + symbols + struct.pack('<I', 4)
    root = dict(recipe_id='synthetic', original_address='0x00401000', symbol_index=0,
                section=2, value=0, size=16)
    identity = dict(recipe_id='provider', object_sha256='a' * 64, symbol_index=8)
    group = dict(members=[1, 2], role='code', original_base='0x00500000', original_target='0x00500000',
        selected_provider_identity=identity, selected_provider_original_address='0x00500000',
        selected_provider_record=dict(address='0x00500000', offset=0),
        selection_sha256='b' * 64, binding_details_sha256='c' * 64)
    name = groups.canonical(identity)
    proofs = []
    for offset, index, symbol in [(0, 1, 'alpha'), (4, 2, 'beta')]:
        proofs.append(dict(source_field_offset=offset, function_va=root['original_address'],
            recipe_id='synthetic', physical_section=2, physical_offset=offset,
            coff_relocation=dict(offset=offset, symbol_index=index, kind=20, symbol=symbol,
                symbol_section=0, symbol_value=0, symbol_storage=2, symbol_type=32, width=4, addend=0),
            classification='SELECTED_CODE_ENTRY', source_resolution_basis='OWN_RECIPE_BINDING',
            proof_consistency='EXACT_OWN_SOURCE_RESOLUTION', exact_original_target_va='0x00500000',
            derived_source_symbol_base_va='0x00500000', expected_original_target_va='0x00500000',
            physical_field_overlap_count=1, code_ownership_ambiguous=False,
            original_field_va='0x%08x' % (0x401000 + offset), original_operand=0x500000 - (0x401000 + offset + 4),
            code_owners=[dict(address='0x00500000', offset=0)]))
    request = dict(schema_version=1, kind='compatible-undefined-reference-request',
        object_sha256=hashlib.sha256(data).hexdigest(), root=root, retained_symbol_indices=[0, 1, 2, 3, 5, 6],
        namespace_plan=[dict(physical_index=i, serialized_index=i, name=n)
                        for i, n in enumerate(['root_unique', name, name, '.text'])] +
                        [dict(physical_index=5, serialized_index=5, name='.drectve'),
                         dict(physical_index=6, serialized_index=6, name='@comp.id')],
        group=group, field_proofs=proofs)
    request['input_sha256'] = dict.fromkeys(groups.MAIN_PINS, 'e' * 64)
    request['input_sha256'].update(object=request['object_sha256'], selection='b' * 64, binding_details='c' * 64)
    request['field_proof_identities'] = [dict(ordinal=i, sha256=groups.digest(row)) for i, row in enumerate(proofs, 1)]
    request['root_closure'] = dict(schema_version=1, policy_id=groups.ROOT_POLICY,
        closure_observed=True, status='observed', blockers=[], recipe_id='synthetic', roots=[root],
        graph_observation_complete=True, root_closure_candidate=True, full_serialization_eligible=False,
        canonical_namespace_collisions_resolved=False,
        retained_runtime_section_indices=[2], retained_section_indices=[1, 2],
        retained_primary_indices=[0, 1, 2, 3, 5, 6], retained_physical_slots=list(range(7)))
    request['root_closure_sha256'] = groups.digest(request['root_closure'])
    return data, request


class CompatibleReferenceTests(unittest.TestCase):
    def rehash(self, request):
        request['field_proof_identities'] = [dict(ordinal=i, sha256=groups.digest(row))
            for i, row in enumerate(request['field_proofs'], 1)]

    def test_exact_group_preserves_both_primary_and_aux_indices(self):
        data, request = fixture(); before = bytes(data)
        result = groups.certify(data, request)
        self.assertEqual(data, before)
        self.assertEqual(result['primary_bijection'], [[0, 0], [1, 1], [2, 2], [3, 3], [5, 5], [6, 6]])
        self.assertEqual(result['auxiliary_bijection'], [[4, 4]])
        self.assertEqual(result['exact_fields'], [[0, 1, 20], [4, 2, 20]])
        for key in ('emission_performed', 'runtime_eligible', 'provider_selected', 'ABI_verified',
                    'link_ready', 'coalescing_allowed', 'relocation_retargeting_allowed'):
            self.assertFalse(result[key])

    def test_role_base_provider_and_ambiguous_owner_rejected(self):
        for change in ('data', 'IAT', 'base', 'provider', 'ambiguity'):
            data, request = fixture()
            if change in ('data', 'IAT'): request['group']['role'] = change
            elif change == 'base': request['field_proofs'][1]['derived_source_symbol_base_va'] = '0x00500004'
            elif change == 'provider': request['field_proofs'][1]['code_owners'][0]['address'] = '0x00500004'
            else: request['field_proofs'][1]['code_ownership_ambiguous'] = True
            self.rehash(request)
            with self.subTest(change=change), self.assertRaises(ValueError): groups.certify(data, request)

    def test_definition_common_weak_and_type_status_rejected(self):
        for field, value in [('section', 1), ('value', 4), ('storage', 105), ('type', 0)]:
            data, request = fixture(); obj = groups.coff.parse(data); changed = bytearray(data)
            pos = obj['symbol_pointer'] + 18
            formats = dict(section=('<h', 12), value=('<I', 8), storage=('<B', 16), type=('<H', 14))
            fmt, offset = formats[field]; struct.pack_into(fmt, changed, pos + offset, value)
            request['object_sha256'] = hashlib.sha256(changed).hexdigest()
            request['input_sha256']['object'] = request['object_sha256']
            with self.subTest(field=field), self.assertRaises(ValueError): groups.certify(bytes(changed), request)

    def test_hidden_index_missing_bijection_and_retarget_rejected(self):
        for change in ('hidden', 'missing', 'coalesced', 'retarget'):
            data, request = fixture()
            if change == 'hidden': request['namespace_plan'][0]['name'] = request['namespace_plan'][1]['name']
            elif change == 'missing': request['retained_symbol_indices'].remove(2)
            elif change == 'coalesced': request['namespace_plan'][2]['serialized_index'] = 1
            else: request['field_proofs'][1]['coff_relocation']['symbol_index'] = 1
            self.rehash(request)
            with self.subTest(change=change), self.assertRaises(ValueError): groups.certify(data, request)

    def test_original_displacement_and_input_identities_are_checked(self):
        for change in ('operand', 'producer', 'field_hash', 'closure_hash', 'incomplete_namespace'):
            data, request = fixture()
            if change == 'operand':
                request['field_proofs'][1]['original_operand'] += 4
                self.rehash(request)
            elif change == 'producer': request['input_sha256']['selection'] = '0' * 64
            elif change == 'field_hash': request['field_proof_identities'][0]['sha256'] = '0' * 64
            elif change == 'closure_hash': request['root_closure_sha256'] = '0' * 64
            else: request['namespace_plan'].pop()
            with self.subTest(change=change), self.assertRaises(ValueError): groups.certify(data, request)

    def test_observer_rejects_missing_input_set_before_reading_objects(self):
        with self.assertRaisesRegex(ValueError, 'input set'):
            groups.observe_main({}, Path('not-read'), '0' * 64)

    def test_dropped_directive_metadata_section_aux_or_aux_slot_is_rejected(self):
        for change in ('directive_section', 'directive_symbol', 'metadata', 'section_aux', 'aux_slot'):
            data, request = fixture(); closure = request['root_closure']
            if change == 'directive_section': closure['retained_section_indices'].remove(1)
            elif change == 'aux_slot': closure['retained_physical_slots'].remove(4)
            else:
                index = {'directive_symbol': 5, 'metadata': 6, 'section_aux': 3}[change]
                closure['retained_primary_indices'].remove(index)
                request['retained_symbol_indices'] = list(closure['retained_primary_indices'])
                request['namespace_plan'] = [r for r in request['namespace_plan'] if r['physical_index'] != index]
            request['root_closure_sha256'] = groups.digest(closure)
            with self.subTest(change=change), self.assertRaises(ValueError): groups.certify(data, request)

    def test_before_after_source_and_dependency_hashes_cannot_be_relabelled(self):
        with tempfile.TemporaryDirectory() as tmp:
            source = Path(tmp) / 'adapter.py'; dependency = Path(tmp) / 'observer.py'
            source.write_bytes(b'original source'); dependency.write_bytes(b'original dependency')
            observations = {source: groups.file_hash(source), dependency: groups.file_hash(dependency)}
            groups.verify_stable(observations)
            for path in (source, dependency):
                before = path.read_bytes(); path.write_bytes(b'changed')
                with self.assertRaisesRegex(ValueError, 'implementation changed'):
                    groups.verify_stable(observations)
                path.write_bytes(before)

    def test_self_hashed_fabricated_observation_fails_full_recomputation(self):
        contract = dict(original_source_evidence='synthetic contract')
        true = dict(contract_identity_sha256=groups.digest(contract), edges=[dict(kind='kept_edge')],
                    provenance=dict(producer='pinned observer'))
        observer = Mock(); observer.assess_object.return_value = true
        groups.verify_root_recomputation(observer, {}, contract, true)
        for key in ('edges', 'provenance', 'contract_identity_sha256'):
            forged = copy.deepcopy(true)
            forged[key] = [] if key == 'edges' else {} if key == 'provenance' else '0' * 64
            # A newly computed caller hash does not validate this changed body.
            self.assertNotEqual(groups.digest(forged), groups.digest(true))
            with self.subTest(key=key), self.assertRaisesRegex(ValueError, 'recomputation differs'):
                groups.verify_root_recomputation(observer, {}, contract, forged)

    def test_current_optional_index_must_be_absent_before_and_after(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp); (root / 'build').mkdir()
            groups.require_index_absent(root)
            # A newly appeared current index cannot be excused by a historical
            # receipt that said the optional index was absent.
            (root / 'build/function_index.json').write_text('{}')
            with self.assertRaisesRegex(ValueError, 'current optional function index'):
                groups.require_index_absent(root)

    def test_ordinary_v2_omission_inputs_preserve_full_unit_group_order(self):
        def row(storage, name):
            return dict(coff_relocation=dict(symbol_storage=storage, symbol=name))
        label = row(6, '$LN1'); ordinary = row(2, 'ordinary')
        iat = row(2, '__imp__GetForegroundWindow@0'); unrelated = row(2, '__imp__Other@0')
        grouped = {'second-address-first-observed': dict(fields=[ordinary, label], row_identities=[{'ordinal': 4}, {'ordinal': 5}]),
                   'first-address-later-observed': dict(fields=[iat, unrelated], row_identities=[{'ordinal': 6}, {'ordinal': 7}])}
        fields, identities = groups.omission_inputs(grouped)
        self.assertEqual(fields, [label, iat])
        self.assertEqual(identities, [{'ordinal': 4}, {'ordinal': 5}, {'ordinal': 6}, {'ordinal': 7}])
        # The complete provenance includes ordinary and unrelated rows too.
        self.assertEqual(len(identities), 4)

    def test_old_observer_policy_rejected_even_with_updated_caller_digest(self):
        data, request = fixture()
        request['root_closure']['policy_id'] = 'root-code-closure-observation-v1'
        request['root_closure_sha256'] = groups.digest(request['root_closure'])
        with self.assertRaisesRegex(ValueError, 'root closure binding'):
            groups.certify(data, request)

    def test_missing_repeated_wrong_kind_nonzero_addend_and_stale_proof_rejected(self):
        for change in ('missing', 'repeated', 'kind', 'addend', 'proof', 'object', 'closure'):
            data, request = fixture()
            if change == 'missing': request['field_proofs'].pop()
            elif change == 'repeated': request['field_proofs'][1] = copy.deepcopy(request['field_proofs'][0])
            elif change == 'kind': request['field_proofs'][0]['coff_relocation']['kind'] = 6
            elif change == 'addend': request['field_proofs'][0]['coff_relocation']['addend'] = 1
            elif change == 'proof': request['field_proofs'][0]['proof_consistency'] = 'UNKNOWN'
            elif change == 'object': request['object_sha256'] = '0' * 64
            else: request['root_closure']['roots'][0] = dict(request['root'], section=1)
            with self.subTest(change=change), self.assertRaises(ValueError): groups.certify(data, request)


if __name__ == '__main__':
    unittest.main()
