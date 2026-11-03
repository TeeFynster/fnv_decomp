"""Authored metadata/COFF only; no original image, object or native command."""
import copy
import gzip
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT=Path(__file__).resolve().parents[2]
sys.path[:0]=[str(ROOT/'tools/rebuild'),str(ROOT/'tests/rebuild')]
import ordinary_relocation_factory as factory
from test_scalableordinary_root_collect import fixture
from test_ordinary_relocation_projection import authored


def planned_map():
    raw,unit,proof,roots,selections,_,_=fixture()
    providers={}
    for root in roots:
        identity={k:root[k] for k in ('recipe_id','object_sha256','symbol_index')}
        providers[root['original_address']]=dict(identity,**{k:root[k] for k in ('source_sha256','section','value','size','symbol')},
            planned_canonical_name=factory.base.pool.canonical(identity))
    owner=dict(summary=dict(events={'SOURCE_CODE_PROVIDER_OBLIGATION':2}))
    data=dict(schema_version=1,policy_id='selected-physical-provider-map-v1',kind='typed-provider-map',inputs=factory.MAP_INPUTS,
        producer_sha256=factory.MAP_PRODUCER,providers=providers,census=dict(events=owner['summary']['events'],sequence_sha256=factory.OWNER_SEQUENCE,selected_owners=2),
        provider_identity_is_planned_namespace=True,materialized_exports=0,input_stability=True,optional_function_index_present=False,
        **{key:False for key in factory.MAP_FALSE})
    return data,selections,{unit['recipe_id']:unit},{proof['recipe_id']:proof},owner


def exports_fixture():
    names=['_fnv_code_'+format(i,'064x') for i in range(14326)]
    old=[dict(exports=[]) for _ in range(1019)];union=[dict(exports=[]) for _ in range(185)]
    old[0]['exports']=names[:12946];union[0]['exports']=names[12946:14318]
    leaves=[dict(projection=dict(exports=[name])) for name in names[14318:]]
    return old,union,leaves,names


def coverage_fixture(status='HISTORICAL_BLOCKED',prepared=False):
    root=fixture()[3][0];original=dict(original_address=root['original_address'],status=status,
        physical_identity={k:root[k] for k in ('recipe_id','object_sha256','symbol_index')},
        selected_native={k:root[k] for k in factory.base.NATIVE_KEYS})
    mapping={'EMITTED':'UPSTREAM_EMITTED_UNCHANGED','BLOCKED_UNION':'STILL_UNION_BLOCKED','HISTORICAL_BLOCKED':'UPSTREAM_HISTORICAL_BLOCKED'}
    union=dict(original_address=original['original_address'],physical_identity=original['physical_identity'],original_status=status,
        status='NEW_UNION_V3_PROJECTED' if prepared and status=='BLOCKED_UNION' else mapping[status],
        original_coverage_row=dict(ordinal=1,sha256=factory.digest(original)))
    leaf=dict(original,baseline_status_preserved=True,ordinary_projection_status='EMITTED_ORDINARY_NO_RELOCATION' if prepared and status=='HISTORICAL_BLOCKED' else 'NOT_REQUESTED')
    return original,union,leaf


class ProviderAndCoverageTests(unittest.TestCase):
    def test_expanded_complete_map_is_only_planned_three_key_identity(self):
        values=planned_map();identities=factory.validate_provider_map(*values)
        self.assertEqual(set(identities),set(values[1]))
        self.assertEqual(set(identities['0x00500000']),{'recipe_id','object_sha256','symbol_index'})
        self.assertEqual(identities['0x00500000']['symbol_index'],2)

    def test_map_source_scope_and_authority_cannot_be_promoted(self):
        for change in ('count','missing','name','source','producer','promotion','index','extra'):
            values=list(planned_map());data=copy.deepcopy(values[0]);values[0]=data
            if change=='count':data['census']['selected_owners']=1
            elif change=='missing':del data['providers']['0x00500100']
            elif change=='name':data['providers']['0x00500000']['planned_canonical_name']='_guessed'
            elif change=='source':data['providers']['0x00500000']['source_sha256']='f'*64
            elif change=='producer':data['producer_sha256']='f'*64
            elif change=='promotion':data['provider_selected']=True
            elif change=='index':data['providers']['0x00500000']['symbol_index']=True
            else:data['unreviewed_provider_policy']=True
            with self.subTest(change=change),self.assertRaises(ValueError):factory.validate_provider_map(*values)

    def test_full_prepared_export_census_and_cross_pool_collision(self):
        old,union,leaf,names=exports_fixture();self.assertEqual(factory.combine_exports(old,union,leaf),set(names))
        leaf[0]['projection']['exports']=[names[0]]
        with self.assertRaises(ValueError):factory.combine_exports(old,union,leaf)

    def test_member_count_does_not_replace_export_count_or_namespace(self):
        old,union,leaf,_=exports_fixture();old[0]['exports'].pop()
        with self.assertRaises(ValueError):factory.combine_exports(old,union,leaf)
        old,union,leaf,_=exports_fixture();union[0]['exports'][0]='_unproved_alias'
        with self.assertRaises(ValueError):factory.combine_exports(old,union,leaf)

    def test_coverage_preserves_each_distinct_prepared_lane(self):
        for status,prepared,expected in [('EMITTED',False,'BASELINE_PREPARED'),('BLOCKED_UNION',True,'UNION_V3_PREPARED'),
                ('HISTORICAL_BLOCKED',True,'FIRST8_PREPARED'),('HISTORICAL_BLOCKED',False,'UNPREPARED')]:
            self.assertEqual(factory.check_coverage_triplet(*coverage_fixture(status,prepared),1),expected)

    def test_coverage_cannot_replace_owner_or_change_original_row(self):
        original,union,leaf=coverage_fixture('BLOCKED_UNION',True)
        leaf['ordinary_projection_status']='EMITTED_ORDINARY_NO_RELOCATION'
        with self.assertRaises(ValueError):factory.check_coverage_triplet(original,union,leaf,1)
        original,union,leaf=coverage_fixture();union['original_coverage_row']['sha256']='f'*64
        with self.assertRaises(ValueError):factory.check_coverage_triplet(original,union,leaf,1)
        original,union,leaf=coverage_fixture();leaf['physical_identity']=dict(leaf['physical_identity'],symbol_index=99)
        with self.assertRaises(ValueError):factory.check_coverage_triplet(original,union,leaf,1)


class MemberBoundaryTests(unittest.TestCase):
    def test_real_core_and_second_reader_on_authored_dir32_addend(self):
        values=authored(6,4,'data')
        with tempfile.TemporaryDirectory() as td:
            path=Path(td)/'member.obj';out,receipt=factory.project_and_verify(*values,[],path)
            self.assertEqual(path.read_bytes(),out);self.assertEqual(receipt['fields'][0]['addend_bits'],4)
            self.assertFalse(receipt['provider_selected'])

    def test_comparison_failure_is_fatal_and_not_a_policy_quarantine(self):
        values=authored()
        with tempfile.TemporaryDirectory() as td:
            path=Path(td)/'stage.obj'
            with patch.object(factory.base.bulk,'compare_functions',side_effect=ValueError('authored comparison failed')):
                with self.assertRaises(ValueError):factory.verify_member(*values,[],Path(td)/'original.obj',path,object(),{})
            self.assertFalse(path.exists())

    def test_exact_source_review_is_required_before_artifact_operation(self):
        with tempfile.TemporaryDirectory() as td:
            path=Path(td)/'review.json';factory.base.save_json(path,dict(schema_version=1,kind='ordinary-relocation-factory-review-v1',approved=True))
            from types import SimpleNamespace
            args=SimpleNamespace(review=path,review_sha256=factory.base.file_hash(path),request_sha256='a'*64,central_receipt_sha256='b'*64,provider_map_sha256=factory.MAP_PIN)
            with self.assertRaises(ValueError):factory.review_gate(args,{})


if __name__=='__main__':unittest.main()
