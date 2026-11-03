"""Original synthetic archive/COFF and no-launch guards for CRT contract tooling."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import crt_provider as crt


def member(shape=None):
    shape = crt.RELOCATION_SHAPE if shape is None else shape
    strings = bytearray(struct.pack('<I', 4)); symbols = []
    for name, section in [('__purecall', 1)] + [(name, 0) for _, _, name in shape]:
        offset = len(strings); strings.extend(name.encode()+b'\0')
        symbols.append(struct.pack('<IIIhHBB', 0, offset, 0, section, 0x20, 2, 0))
    struct.pack_into('<I', strings, 0, len(strings))
    raw, relptr = 60, 102
    relocs = b''.join(struct.pack('<IIH', offset, i+1, kind) for i, (offset, kind, _) in enumerate(shape))
    header = struct.pack('<HHIIIHH', 0x14c, 1, 0, relptr+len(relocs), len(symbols), 0, 0)
    section = struct.pack('<8sIIIIIIHHI', b'.text', 0, 0, 42, raw, relptr, 0, len(shape), 0, 0x60000020)
    return header+section+bytes(42)+relocs+b''.join(symbols)+strings


def archive(payload):
    def row(name, data):
        h = f'{name:<16}{0:<12}{0:<6}{0:<6}{0:<8}{len(data):<10}`\n'.encode()
        return h+data+(b'\n' if len(data)%2 else b'')
    link_size = 8+len(b'__purecall\0'); offset = 8+60+link_size+(link_size%2)
    return b'!<arch>\n'+row('/', struct.pack('>II', 1, offset)+b'__purecall\0')+row('fixture.obj/', payload)


class CRTProviderTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory(); self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)

    def test_exact_named_member_and_bounded_contract(self):
        path = self.root/'fixture.lib'; path.write_bytes(archive(member()))
        data, meta = crt.archive_member(path)
        self.assertEqual(meta['member_sha256'], hashlib.sha256(member()).hexdigest())
        report = crt.member_contract(data, bytes(42))
        self.assertEqual(report['compared_nonrelocation_bytes'], 22)
        self.assertEqual(len(report['relocations']), 5)
        self.assertFalse(report['complete_relocation_identity_verified'])
        self.assertFalse(report['runtime_provider_selected'])

    def test_changed_nonrelocation_byte_and_relocation_rejected(self):
        reference = bytearray(42); reference[0] = 1
        with self.assertRaisesRegex(ValueError, 'nonrelocation'): crt.member_contract(member(), reference)
        shape = list(crt.RELOCATION_SHAPE); shape[0] = (3, 6, '___pPurecall')
        with self.assertRaisesRegex(ValueError, 'shape'): crt.member_contract(member(shape), bytes(42))

    def test_unsupported_dependency_and_overlap_rejected(self):
        shape = list(crt.RELOCATION_SHAPE); shape[0] = (2, 6, '_unknown')
        with self.assertRaisesRegex(ValueError, 'dependency'): crt.member_contract(member(shape), bytes(42))
        shape[0] = (7, 6, '___pPurecall')
        with self.assertRaisesRegex(ValueError, 'overlapping'): crt.member_contract(member(shape), bytes(42))

    def test_archive_bounds_and_missing_symbol(self):
        path = self.root/'fixture.lib'; path.write_bytes(archive(member()))
        with self.assertRaisesRegex(ValueError, 'absent'): crt.archive_member(path, '_absent')
        path.write_bytes(b'!<arch>\n'+bytes(60))
        with self.assertRaises(ValueError): crt.archive_member(path)

    def test_stale_library_and_reference_rejected_before_image_read(self):
        for name in ('reference', 'sp1_lib', 'rtm_lib'):
            (self.root/name).write_bytes(b'original-fixture')
        args = argparse.Namespace(out=self.root/'report.json', **{n:self.root/n for n in ('reference','sp1_lib','rtm_lib')})
        args.reference_sha256 = crt.sha(args.reference)
        args.sp1_library_sha256 = crt.sha(args.sp1_lib); args.rtm_library_sha256 = crt.sha(args.rtm_lib)
        for path in (args.reference, args.sp1_lib, args.rtm_lib):
            with self.subTest(path=path), patch.object(crt, 'Pe') as reader:
                path.write_bytes(b'changed')
                with self.assertRaisesRegex(ValueError, 'stale'): crt.audit(args)
                reader.assert_not_called(); path.write_bytes(b'original-fixture')

    def test_supported_modes_and_failure_semantics_are_distinct(self):
        good = [('state', 0, 'fresh-null-handler\nset-restored-null\n', ''),
                ('exit-hook', 73, 'fresh-null-handler\nbefore-exit-hook\nhook-exit-73\n', ''),
                ('default', 3, 'fresh-null-handler\nbefore-default-abort\n', 'R6025 - pure virtual function call')]
        for mode, code, out, err in good:
            crt.parse_mode(mode, SimpleNamespace(returncode=code, stdout=out, stderr=err))
        with self.assertRaises(ValueError): crt.parse_mode('default', SimpleNamespace(returncode=73, stdout=good[1][2], stderr=''))
        with self.assertRaisesRegex(ValueError, 'unsafe'): crt.parse_mode('returning-hook', SimpleNamespace(stdout='', stderr='', returncode=0))

    def test_no_optin_or_missing_review_never_launches(self):
        args = argparse.Namespace(allow_execute=False)
        with patch.object(crt.subprocess, 'run') as launch:
            with self.assertRaisesRegex(ValueError, 'explicit'): crt.execute(args)
            launch.assert_not_called()
        proof = self.root/'prepare.json'
        proof.write_text(json.dumps(dict(kind='original-purecall-fixture-preparation', status='prepared-not-executed', modes=list(crt.MODES))))
        args = argparse.Namespace(allow_execute=True, out=self.root/'result.json', proof=proof,
            proof_sha256=crt.sha(proof), review=None, review_sha256=None)
        with patch.object(crt.subprocess, 'run') as launch:
            with self.assertRaisesRegex(ValueError, 'review required'): crt.execute(args)
            launch.assert_not_called()

    def make_proofs(self):
        exe, mapping = self.root/'probe.exe', self.root/'probe.map'
        exe.write_bytes(b'not-an-executable'); mapping.write_text('original fixture map')
        proof = dict(kind='original-purecall-fixture-preparation', status='prepared-not-executed', modes=list(crt.MODES),
            inputs={str(p.resolve()):crt.sha(p) for p in (exe, mapping, Path(crt.__file__), crt.SOURCE)})
        path = self.root/'prepare.json'; path.write_text(json.dumps(proof))
        review = dict(schema_version=1, kind='crt-purecall-fixture-independent-review', status='approved', reviewer='synthetic reviewer',
            prepare_sha256=crt.sha(path), executable_sha256=crt.sha(exe), map_sha256=crt.sha(mapping),
            checks={k:True for k in ('source_no_virtual_dispatch', 'bounded_child_suppression',
                'normal_static_CRT_providers', 'hash_bound_inputs', 'expected_modes_and_failure_semantics')})
        reviewpath = self.root/'review.json'; reviewpath.write_text(json.dumps(review))
        return argparse.Namespace(allow_execute=True, out=self.root/'execution.json', proof=path,
            proof_sha256=crt.sha(path), review=reviewpath, review_sha256=crt.sha(reviewpath))

    def test_stale_proof_review_or_prepared_input_never_launches(self):
        for target in ('prepare.json', 'review.json', 'probe.exe', 'probe.map'):
            with self.subTest(target=target):
                args = self.make_proofs(); (self.root/target).write_text('changed')
                with patch.object(crt.subprocess, 'run') as launch:
                    with self.assertRaises(ValueError): crt.execute(args)
                    launch.assert_not_called()

    def test_revalidation_before_every_child_stops_changed_input(self):
        args = self.make_proofs()
        def child(*a, **kw):
            (self.root/'probe.map').write_text('changed during child')
            return SimpleNamespace(returncode=0, stdout='fresh-null-handler\nset-restored-null\n', stderr='')
        with patch.object(crt.subprocess, 'CREATE_NO_WINDOW', 0, create=True), patch.object(crt.subprocess, 'run', side_effect=child) as launch:
            report = crt.execute(args)
        self.assertEqual(launch.call_count, 1)
        self.assertEqual(report['status'], 'fail')
        self.assertIn('stale', report['error'])

    def test_output_is_exclusive(self):
        path = self.root/'report.json'; crt.save_new(path, {'original':True})
        with self.assertRaises(FileExistsError): crt.save_new(path, {})


if __name__ == '__main__': unittest.main()
