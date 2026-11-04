"""Authored publication, authority and immutable-reference boundaries."""
import copy
from pathlib import Path
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

ROOT=Path(__file__).resolve().parents[2]
sys.path[:0]=[str(ROOT/'tools/rebuild'),str(ROOT/'tests/rebuild')]
import composed_relocation_factory as factory
from test_prepared_code_exclusions_independent import epoch_fixture


class FactoryTests(unittest.TestCase):
    def test_all_prepared_records_rebuild_and_unknown_authority_refused(self):
        ordinary,application,providers,bindings=epoch_fixture()
        manifest=factory.prepared.build_manifest(ordinary,application,providers,bindings)
        manifest.update(provider_map_sha256=factory.prior.MAP_PIN,provider_map_review_sha256=factory.prior.MAP_REVIEW[1],
            source_epoch_artifacts={k:h for k,(_,h) in factory.prepared.INPUTS.items()},
            authority_state='requires-successful-producer-receipt-and-independent-outcome-review')
        self.assertEqual(len(factory.validate_prepared(manifest,providers)),14333)
        for key,value in [('unknown',True),('authority_state','selected'),('ordinary_names',manifest['ordinary_names'][:-1])]:
            changed=copy.deepcopy(manifest);changed[key]=value
            with self.assertRaises(ValueError):factory.validate_prepared(changed,providers)
    def test_saved_highlow_strings_are_strict_and_distinct(self):
        self.assertEqual(factory.highlow_sites(['0x00400001','0x00400005']),{0x400001,0x400005})
        for values in [[0x400001],['0x0040000A'],['0x00400001']*2,['400001']]:
            with self.assertRaises(ValueError):factory.highlow_sites(values)
    def test_missing_phase_rejected_before_any_output(self):
        with tempfile.TemporaryDirectory() as td:
            args=SimpleNamespace(review=Path(td)/'missing.json',review_sha256='0'*64)
            with self.assertRaises(OSError):factory.review_gate(args,{})
            self.assertEqual(list(Path(td).iterdir()),[])

    def test_false_review_cannot_pin_or_open_producer(self):
        with patch.object(factory.base,'observe',return_value=Path('review.json')),patch.object(factory.base,'load_json',return_value={}):
            with self.assertRaises(ValueError):factory.review_gate(SimpleNamespace(review=Path('review.json'),review_sha256='0'*64),{})

    def test_verified_snapshot_read_bounds_and_no_stream_reads(self):
        snapshot=object.__new__(factory.SnapshotPe);snapshot.verified_buffer=b'authored'
        self.assertEqual(snapshot.read(1,3),b'uth')
        for offset,size in [(-1,1),(1,99),(True,1),(1,False)]:
            with self.assertRaises(ValueError):snapshot.read(offset,size)

    def test_label_envelope_rejects_unknown_and_borrowed_scalar(self):
        pure={'authored':'composition'};witness={'authored':'witness'}
        record={'record_sha256':'a'*64,'lane':1,'ordinal':29}
        central={'lane_artifacts':{'1':{'sha256':'b'*64}}}
        saved=dict(pure,central_receipt_sha256=factory.core.composer.CENTRAL_PIN,
            central_record_sha256='a'*64,input_stability=True,lane=1,lane_record_ordinal=29,
            lane_sha256='b'*64,optional_function_index_present=False,
            producer_sha256=factory.PINS['tools/rebuild/root_certificate_composer.py'],typed_witnesses=[witness])
        self.assertEqual(factory.normalize_label_composition(saved,pure,record,witness,central),pure)
        for key,value in [('extra',1),('lane',True),('lane_record_ordinal',28),('input_stability',False),('typed_witnesses',[])]:
            changed=copy.deepcopy(saved);changed[key]=value
            with self.assertRaises(ValueError):factory.normalize_label_composition(changed,pure,record,witness,central)


if __name__=='__main__':unittest.main()
