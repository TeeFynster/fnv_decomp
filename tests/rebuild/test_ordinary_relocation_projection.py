"""Authored COFF only; no original image/object, process or publication."""
import copy
import hashlib
from pathlib import Path
import struct
import sys
import unittest

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT/'tools/rebuild'), str(ROOT/'tests/rebuild')]
import ordinary_relocation_projection as projection
import scalableordinary_root_collect as collector
import root_code_closure as ordinary
import coff_code_archive as coff
import runtime_code_pool as pool
from test_scalableordinary_root_collect import fixture


def authored(kind=20, addend=0, role='crt-contract'):
    raw, unit, proof, roots, _, _, buckets = fixture(field=True)
    roots = roots[:1]
    obj = coff.parse(raw)
    # Mutate the authored fixture using its independently parsed physical fields.
    blob = bytearray(raw)
    sec = obj['sections'][1]
    header = struct.unpack_from('<8sIIIIIIHHI', raw, 20)
    struct.pack_into('<I', blob, header[4]+4, addend & 0xffffffff)
    struct.pack_into('<H', blob, header[5]+8, kind)
    index = 9
    if role != 'crt-contract':
        struct.pack_into('<H', blob, obj['symbol_pointer'] + index*18 + 14, 32 if role == 'code' else 0)
    raw = bytes(blob); native = coff.parse(raw)
    object_hash = hashlib.sha256(raw).hexdigest()
    unit['object_sha256'] = object_hash; roots[0]['object_sha256'] = object_hash
    proof['object_sha256'] = object_hash
    row = buckets['0x00500000']['fields'][0]
    target = native['symbols'][index]
    base = '0x00600000'
    signed = addend & 0xffffffff
    if kind == 20 and signed >= 0x80000000: signed -= 0x100000000
    final = '0x%08x' % ((int(base, 16) + signed) & 0xffffffff)
    row.update(recipe_index=0, function_symbol='_alpha', source_resolution_basis='OWN_RECIPE_BINDING',
        expected_original_target_va=final, exact_original_target_va=final,
        original_operand=((int(final, 16)-0x00500008) if kind == 20 else int(final,16)) & 0xffffffff,
        code_owners=[dict(address=base, offset=0)] if role == 'code' else [], code_ownership_ambiguous=False)
    row['coff_relocation'].update(kind=kind, width=4, addend=addend & 0xffffffff,
        symbol_type=target['type'], symbol_storage=target['storage'])
    row['classification'] = {'data':'ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER',
        'code':'SELECTED_CODE_ENTRY','crt-contract':'EXPLICIT_NORMAL_CRT_CONTRACT_CANDIDATE'}[role]
    contract = collector.build_contract(unit, proof, roots, buckets, {},
        dict(object_sha256=object_hash, source_sha256=unit['source_sha256'], recipe_id=unit['recipe_id'], recipe_index=0))
    cert = ordinary.assess_object(native, contract)
    providers = {roots[0]['original_address']:{k:roots[0][k] for k in ('recipe_id','object_sha256','symbol_index')}}
    if role == 'code': providers[base] = dict(recipe_id='other', object_sha256='d'*64, symbol_index=7)
    return raw, contract, cert, roots, providers


def project(values, **kwargs):
    return projection.project_member(*values, existing_exports=kwargs.pop('existing_exports',()), **kwargs)


class OrdinaryRelocationProjectionTests(unittest.TestCase):
    def test_rel32_crt_undefined_and_exact_target_map(self):
        values = authored(); self.assertTrue(values[2]['closure_observed'])
        output, receipt = project(values)
        parsed = coff.parse(output)
        self.assertEqual(receipt['exports'], [pool.canonical(values[4]['0x00500000'])])
        name = pool.unresolved('0x00600000', 'crt-contract')
        self.assertEqual(receipt['comparison_base_view'][name], '0x00600000')
        self.assertEqual(receipt['undefined'][0]['name'], name)
        self.assertEqual(sum(len(s['relocs']) for s in parsed['sections'].values()), 1)
        self.assertFalse(receipt['provider_selected'])

    def test_dir32_data_positive_addend_and_rel32_negative_crt_preserved(self):
        for kind, addend, role in [(6,4,'data'),(20,-4,'crt-contract')]:
            values = authored(kind,addend,role); output, receipt = project(values)
            self.assertEqual(coff.parse(values[0])['sections'][1]['payload'],
                coff.parse(output)['sections'][receipt['maps']['section_map'][1]]['payload'])
            self.assertEqual(receipt['fields'][0]['addend_bits'], addend & 0xffffffff)

    def test_code_uses_original_selected_physical_provider(self):
        values = authored(role='code'); _, receipt = project(values)
        self.assertEqual(receipt['undefined'][0]['name'],pool.canonical(values[4]['0x00600000']))

    def test_missing_or_wrong_root_provider_refused(self):
        values = list(authored()); values[4] = {}
        with self.assertRaises(ValueError): project(values)

    def test_original_operand_geometry_not_only_certificate_label(self):
        values = list(authored()); values[1]['fields'][0]['original_operand'] ^= 1
        values[2] = ordinary.assess_object(coff.parse(values[0]),values[1])
        self.assertTrue(values[2]['closure_observed'])
        with self.assertRaises(ValueError):project(values)

    def test_existing_baseline_or_successor_export_cannot_be_replaced(self):
        values=authored(); name=pool.canonical(values[4]['0x00500000'])
        with self.assertRaises(ValueError):project(values,existing_exports=[name])

    def test_strict_root_and_certificate_identity(self):
        for mutate in ('index','bool','extra','hash','certificate'):
            values=list(authored())
            if mutate=='index':values[3][0]['symbol_index']=5
            elif mutate=='bool':values[3][0]['recipe_index']=False
            elif mutate=='extra':values[3][0]['approved']=True
            elif mutate=='hash':values[3][0]['object_sha256']='f'*64
            else:values[2]['runtime_eligible']=True
            with self.subTest(mutate=mutate),self.assertRaises(ValueError):project(values)

    def test_complete_field_proof_and_no_reference_certificate_waiver(self):
        values=authored()
        with self.assertRaises(ValueError):project(values,reference_groups={'approved':True})
        values=list(authored());values[1]['fields']=[]
        with self.assertRaises(ValueError):project(values)

    def test_structured_assessment_never_catches_integrity_failure(self):
        values=authored()
        assessed=projection.assess_member(*values,existing_exports=())
        self.assertTrue(assessed['eligible']);self.assertFalse(assessed['serialization_performed'])
        values=list(authored());values[1]['fields'][0]['original_operand']^=1
        values[2]=ordinary.assess_object(coff.parse(values[0]),values[1])
        with self.assertRaises(ValueError):projection.assess_member(*values,existing_exports=())

    def test_unsupported_field_type_is_explicit_bound_policy_result(self):
        values=list(authored(role='data'))
        # Rebuild the authored TYPE and its complete field observation coherently;
        # the root omission proof remains positive but DATA-function TYPE is outside scope.
        raw=bytearray(values[0]);parsed=coff.parse(values[0])
        struct.pack_into('<H',raw,parsed['symbol_pointer']+9*18+14,32)
        values[0]=bytes(raw);h=hashlib.sha256(values[0]).hexdigest()
        values[1]['provenance']['object_sha256']=h;values[3][0]['object_sha256']=h
        values[4]['0x00500000']['object_sha256']=h
        values[1]['fields'][0]['coff_relocation']['symbol_type']=32
        values[2]=ordinary.assess_object(coff.parse(values[0]),values[1])
        self.assertTrue(values[2]['closure_observed'])
        assessed=projection.assess_member(*values,existing_exports=())
        self.assertFalse(assessed['eligible'])
        self.assertEqual(assessed['blockers'][0]['code'],'UNSUPPORTED_DATA_TYPE_OR_CLASS')
        self.assertEqual(assessed['contract_identity_sha256'],projection.digest(values[1]))
        with self.assertRaises(projection.UnsupportedRoot):project(values)


if __name__=='__main__':unittest.main()
