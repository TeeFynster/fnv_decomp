"""Synthetic original COFF only; no native compiler needed."""
import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch
sys.path.insert(0, str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
sys.path.insert(0, str(Path(__file__).parent))
import coff_bind
from coff_inventory import Coff
from test_coff_rewrite import fixture


class BindingTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory(); self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.inp, self.out, self.receipt, self.pp, self.source = [self.root/n for n in ('in.obj','out.obj','receipt.json','plan.json','source.cpp')]
        self.source = Path(__file__).resolve().parents[2]/'runtime/probes/binding_caller_a.cpp'
        self.inp.write_bytes(fixture())
        self.plan = dict(schema_version=1, kind='fnv-coff-bind-plan', approved=True, scope='original-fixture-only',
            object_sha256=coff_bind.digest(self.inp.read_bytes()), source=str(self.source), source_sha256=coff_bind.digest(self.source.read_bytes()),
            bindings=[dict(symbol_index=2,old_name='_old',new_name='_bound_definition',source_kind='function',target_kind='function'),
                      dict(symbol_index=3,old_name='_use',new_name='_bound_reference',source_kind='data',target_kind='data')])

    def run_bind(self, **kw):
        self.pp.write_text(json.dumps(self.plan))
        args = dict(input_path=self.inp,output_path=self.out,receipt_path=self.receipt,plan_path=self.pp,expected_plan_sha256=coff_bind.digest(self.pp.read_bytes()))
        args['fixture_context'] = dict(policy='original-binding-fixture-v1', fresh_compile_observed=True,
            compiler_version='15.00.30729.01', compiler_sha256='c'*64,
            objects={str(self.inp.resolve()):dict(source=str(self.source.resolve()),source_sha256=self.plan['source_sha256'],object_sha256=self.plan['object_sha256'])})
        args.update(kw)
        return coff_bind.bind_object(**args)

    def update_input(self, data):
        self.inp.write_bytes(data); self.plan['object_sha256']=coff_bind.digest(data)

    def test_definition_reference_and_every_non_name_byte_preserved(self):
        before=Coff(self.inp); report=self.run_bind(); after=Coff(self.out)
        self.assertEqual(before.sections,after.sections)
        self.assertEqual(after.symbols[2]['name'],'_bound_definition')
        self.assertEqual(after.symbols[3]['name'],'_bound_reference')
        self.assertTrue(report['verification']['non_name_object_bytes_equal'])
        self.assertEqual(report['input_sha256'],coff_bind.digest(before.data))
        self.assertFalse(report['execution_performed'])

    def test_wrong_object_plan_and_source_hash(self):
        self.plan['object_sha256']='0'*64
        with self.assertRaisesRegex(ValueError,'object hash'): self.run_bind()
        self.plan['object_sha256']=coff_bind.digest(self.inp.read_bytes())
        with self.assertRaisesRegex(ValueError,'mapping hash'): self.run_bind(expected_plan_sha256='0'*64)
        self.plan['source_sha256']='0'*64
        with self.assertRaisesRegex(ValueError,'source hash'): self.run_bind()

    def test_unapproved_and_wrong_kind(self):
        self.plan['approved']=False
        with self.assertRaisesRegex(ValueError,'unapproved'): self.run_bind()
        self.plan['approved']=True
        self.plan['bindings'][0]['target_kind']='data'
        with self.assertRaisesRegex(ValueError,'kind'): self.run_bind()

    def test_missing_duplicate_symbol_and_binding(self):
        self.plan['bindings'][0]['old_name']='_absent'
        with self.assertRaisesRegex(ValueError,'missing or duplicate'): self.run_bind()
        self.plan['bindings'][0]['old_name']='_old'
        self.update_input(fixture([('_old',0,1,2,[]),('_old',0,0,2,[])]))
        with self.assertRaisesRegex(ValueError,'missing or duplicate'): self.run_bind()
        self.update_input(fixture())
        self.plan['bindings']=[self.plan['bindings'][0]]*2
        with self.assertRaisesRegex(ValueError,'duplicate'): self.run_bind()

    def test_arbitrary_source_and_missing_fresh_context_rejected(self):
        with self.assertRaisesRegex(ValueError,'context'):
            self.run_bind(fixture_context={})
        source=self.root/'arbitrary_game_shaped.cpp'; source.write_text('int original;')
        self.source=source
        self.plan.update(source=str(source),source_sha256=coff_bind.digest(source.read_bytes()))
        with self.assertRaisesRegex(ValueError,'exact original fixture'):
            self.run_bind()

    def test_target_collision(self):
        self.plan['bindings'][0]['new_name']='_use'
        with self.assertRaisesRegex(ValueError,'collision'): self.run_bind()
        self.plan['bindings'][0]['new_name']='_bound_reference'
        with self.assertRaisesRegex(ValueError,'collision'): self.run_bind()

    def test_aux_common_weak_rejected(self):
        cases=[fixture([('_old',0,1,2,[bytes(18)]),('_use',0,0,2,[])]),
               fixture([('_old',0,1,2,[]),('_use',4,0,2,[])]),
               fixture([('_old',0,1,2,[]),('_use',0,0,105,[struct.pack('<II',2,3)+bytes(10)])])]
        for data in cases:
            with self.subTest(data=len(data)):
                self.update_input(data)
                with self.assertRaises(ValueError): self.run_bind()

    def test_iat_and_absolute_metadata_rejected(self):
        self.plan['bindings'][0]['new_name']='__imp__Api'
        with self.assertRaisesRegex(ValueError,'import-pointer'): self.run_bind()
        self.plan['bindings'][0]['new_name']='_safe'
        self.update_input(fixture([('_old',0,-1,2,[]),('_use',0,0,2,[])]))
        with self.assertRaisesRegex(ValueError,'EXTERNAL'): self.run_bind()

    def test_unsafe_directives_rejected(self):
        original=coff_bind.strict_object
        def with_directive(p):
            rows=original(p); rows[0].directives=['/include:_old']; return rows
        with patch.object(coff_bind,'strict_object',with_directive):
            with self.assertRaisesRegex(ValueError,'unsafe directive'): self.run_bind()

    def test_malformed_string_and_input_output_collision(self):
        self.update_input(fixture()[:-1])
        with self.assertRaises(ValueError): self.run_bind()
        self.update_input(fixture())
        with self.assertRaisesRegex(ValueError,'collision'): self.run_bind(output_path=self.inp)
        self.out.write_text('saved')
        with self.assertRaisesRegex(ValueError,'already exists'): self.run_bind()
        self.assertEqual(self.out.read_text(),'saved')

    def test_byte_guard_rejects_payload_and_relocation_mutation(self):
        data=self.inp.read_bytes()
        for offset in (60,64):
            changed=bytearray(data); changed[offset]^=1
            with self.assertRaisesRegex(ValueError,'changed payload'):
                coff_bind.verify_bytes(data,changed,[],len(data)-4)

    def test_output_failure_removes_new_only(self):
        original=Path.open
        def bad(p, mode='r', *args, **kw):
            if p==self.receipt and mode=='xb': raise OSError('receipt failure')
            return original(p,mode,*args,**kw)
        with patch.object(Path,'open',bad):
            with self.assertRaises(OSError): self.run_bind()
        self.assertFalse(self.out.exists()); self.assertFalse(self.receipt.exists())

if __name__=='__main__': unittest.main()
