import hashlib
import json
from pathlib import Path
import sys
import unittest
from unittest.mock import patch
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import crt_adoption_consumer_contract as gate

class ConsumerContractTests(unittest.TestCase):
    def fields_and_bindings(self):
        fields=[];bindings=[]
        for index,(base,role,export,kind) in enumerate(gate.planner.BINDINGS):
            name=gate.planner.undefined(base,role)
            row=dict(component='example',member='example.obj',caller='caller',section=2,offset=index*4,
                physical_symbol_index=index,symbol_index=index,kind=kind,canonical=name,undefined=True,
                recipe_id='0000-test',object_sha256='1'*64,source_sha256='2'*64,
                proof=dict(original_base=base,original_target=base,role=role,kind=kind,
                           addend_bits=0,symbol_index=index))
            fields.append(row);bindings.append(dict(original_base=base,role=role,normal_export=export,
                canonical_undefined=name,fields=[row],field_count=1,field_census_sha256=gate.planner.digest([row])))
        return fields,bindings
    def test_complete_snapshot_order_independent_but_identity_exact(self):
        fields,_=self.fields_and_bindings(); digest=gate.planner.digest(sorted(fields,key=gate.planner.canonical))
        gate.complete_fields(list(reversed(fields)),4,digest)
        fields[0]['object_sha256']='3'*64
        with self.assertRaises(ValueError):gate.complete_fields(fields,4,digest)
    def test_all_four_function_and_cookie_fields_pass_without_promotion(self):
        fields,bindings=self.fields_and_bindings()
        self.assertEqual(len(gate.binding_uses(bindings,fields,{})),4)
    def test_cookie_or_function_strong_definition_blocks(self):
        fields,bindings=self.fields_and_bindings()
        for row in bindings:
            with self.assertRaises(ValueError):gate.binding_uses(bindings,fields,{row['canonical_undefined']:{'kind':'data-or-code'}})
    def test_missing_extra_or_changed_canonical_site_blocks(self):
        fields,bindings=self.fields_and_bindings()
        with self.assertRaises(ValueError):gate.binding_uses(bindings,fields[1:],{})
        extra=dict(fields[0]);extra['offset']=99
        with self.assertRaises(ValueError):gate.binding_uses(bindings,fields+[extra],{})
        # Freeze independent expected records as the real JSON parser does.
        fields,bindings=self.fields_and_bindings();bindings=json.loads(json.dumps(bindings));fields[0]['source_sha256']='4'*64
        with self.assertRaises(ValueError):gate.binding_uses(bindings,fields,{})
    def test_half_cookie_pair_wrong_role_and_unknown_scope_block(self):
        fields,bindings=self.fields_and_bindings()
        with self.assertRaises(ValueError):gate.binding_uses(bindings[1:],fields,{})
        bindings[0]['role']='code'
        with self.assertRaises(ValueError):gate.binding_uses(bindings,fields,{})
        with self.assertRaises(ValueError):gate.validate(b'',b'',b'','arbitrary-next',[],{})
    def test_unbound_json_and_response_cannot_be_substituted(self):
        with self.assertRaises(ValueError):gate.bound_json(b'{}',gate.PLAN,'plan')
        with self.assertRaises(ValueError):gate.validate(b'{}',b'{}',b'/FORCE\n','current_actual_V4',[],{})
    def test_end_to_end_returns_exact_tokens_without_native_permission(self):
        fields,bindings=self.fields_and_bindings()
        digest=gate.planner.digest(sorted(fields,key=gate.planner.canonical))
        plan=dict(kind='exact-normal-CRT-diagnostic-adoption-plan',alias_applied=False,provider_adopted=False,
            runtime_ABI_approved=False,runtime_eligible=False,current_actual_V4=dict(
                bindings=bindings,complete_input_fields=4,binding_count=4,alias_field_count=4))
        plan_bytes=json.dumps(plan).encode();plan_sha=hashlib.sha256(plan_bytes).hexdigest()
        response=gate.planner.response(bindings).replace('\n','\r\n').encode();response_sha=hashlib.sha256(response).hexdigest()
        review=dict(kind='application-crt-adoption-plan-artifact-review',
            status='approved-for-separate-diagnostic-successor-preparation',reviewer='independent',
            plan_sha256=plan_sha,response_sha256=response_sha)
        review_bytes=json.dumps(review).encode();review_sha=hashlib.sha256(review_bytes).hexdigest()
        with patch.multiple(gate,PLAN=plan_sha,REVIEW=review_sha,RESPONSE=response_sha,
                            COHORTS={'current_actual_V4':(4,4,digest)}):
            result=gate.validate(plan_bytes,review_bytes,response,'current_actual_V4',fields,{})
            self.assertEqual(result['tokens'],response.decode().splitlines())
            self.assertFalse(result['native_operation_authorized']);self.assertFalse(result['runtime_ABI_approved'])

if __name__=='__main__':unittest.main()
