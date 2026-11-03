"""Original metadata/COFF fixtures; no game, compiler, service or image input."""
import argparse
import gzip
import json
from pathlib import Path
import struct
import sys
import tempfile
from types import SimpleNamespace
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/rebuild'))
import eh_ownership as eh


def synthetic_coff():
    # Parent relocations deliberately visit sections 3 then 2. The oracle emits
    # pieces by sorted section index, not relocation or original-VA order.
    sections = [(b'.text', bytes(12), [(0, 2, 6), (4, 1, 20)]),
                (b'.text$x', bytes(8), []), (b'.text$x', bytes(8), [])]
    symbols = [(b'_parent', 0, 1), (b'_tailA', 0, 2), (b'_tailB', 0, 3),
               (b'_cutA', 4, 2), (b'_cutB', 4, 3)]
    cursor = 20 + 40 * len(sections)
    headers, payload = [], bytearray()
    for name, data, relocs in sections:
        raw = cursor; payload.extend(data); cursor += len(data)
        relptr = cursor if relocs else 0
        for reloc in relocs: payload.extend(struct.pack('<IIH', *reloc)); cursor += 10
        headers.append(struct.pack('<8sIIIIIIHHI', name, 0, 0, len(data), raw, relptr, 0,
                                   len(relocs), 0, 0x60000020))
    data = struct.pack('<HHIIIHH', 0x14c, len(sections), 0, cursor, len(symbols), 0, 0)
    data += b''.join(headers) + payload
    for name, value, section in symbols:
        data += struct.pack('<8sIhHBB', name, value, section, 0x20, 2, 0)
    return data + struct.pack('<I', 4)


class EHOwnershipTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory(); self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name); (self.root/'build').mkdir()
        (self.root/'unit.obj').write_bytes(synthetic_coff())
        (self.root/'fixture.cpp').write_text('void original_fixture() {}\n')
        self.recipe = dict(source='fixture.cpp', compiler='sp1', flags=[], symbols={},
                           functions=[dict(symbol='_parent', address='0x00400100', size=12)])
        recipe_hash = eh.unit_hash(self.recipe)
        self.unit = dict(recipe_index=0, recipe_id='0000-'+recipe_hash[:16], recipe=self.recipe,
                         source='fixture.cpp', compiler='sp1', status='compiled', object='unit.obj',
                         object_sha256=eh.digest(self.root/'unit.obj'), source_sha256=eh.digest(self.root/'fixture.cpp'))
        self.write('recipes', dict(units=[self.recipe]))
        self.manifest = dict(schema_version=1, kind='fnv-retained-objects',
            recipe_manifest_sha256=self.hash('recipes'), units=[self.unit])
        self.write('manifest', self.manifest)
        # Same-size pieces have noncontiguous original placement. A and B
        # overlap in original space and must remain separate alternatives.
        self.receipt_unit = dict(recipe_index=0, recipe_id=self.unit['recipe_id'],
            recipe_unit_sha256=recipe_hash, object_sha256=self.unit['object_sha256'],
            source_sha256_recorded=self.unit['source_sha256'], source_sha256_current=self.unit['source_sha256'],
            status='ok', verified_functions=[dict(self.recipe['functions'][0], section=1, value=0, verdict='match')],
            eh_sections=[[0x400200, 0x400204, True, '0x00400100', []],
                         [0x400300, 0x400304, True, '0x00400100', ['_helper']],
                         [0x400200, 0x400204, True, '0x00400100', []],
                         [0x400400, 0x400404, False, '0x00400100', []]], eh_errors=[])
        self.receipt = dict(schema_version=1, kind='fnv-retained-object-verification',
            scope=dict(full_authoritative=True), inputs=dict(retained_manifest_sha256=self.hash('manifest'),
            recipe_sha256=self.hash('recipes'), function_index_present=False, function_index_sha256=None,
            tools_sha256={n: eh.digest(eh.ROOT/n) for n in ('tools/build_and_match.py',
                        'tools/compare.py', 'tools/rebuild/verify_objects.py')}),
            units=[self.receipt_unit], **{k: True for k in ('retained_verification_pass',
            'function_byte_verification_pass', 'global_listed_eh_coverage_pass',
            'original_oracle_parity_pass', 'evidence_stable')})
        self.write('retained', self.receipt)
        detail = self.root/'detail.gz'
        self.rows = [[4, 0x202, 'other-code', 0, 4, 'raw', []],
                     [8, 0x202, 'other-code', 0, 4, 'raw', []],
                     [12, 0x301, 'EH-interior-ambiguous', 0, 4, 'raw', []],
                     [16, 0x999, 'other-code', 0, 4, 'raw', []]]
        with gzip.open(detail, 'wt') as f:
            for row in self.rows: f.write(json.dumps(row)+'\n')
        self.plan = dict(kind='fnv-private-data-analysis', runtime_ready=False, detail_columns=eh.COLUMNS,
            image=dict(base=0x400000, size=0x1000), recipe_sha256=self.hash('recipes'),
            detail_sha256=eh.digest(detail), fixups=dict(nonexec_data_sites=4,
            by_target={'other-code': 3, 'EH-interior-ambiguous': 1}))
        self.write('plan', self.plan)
        self.ledger = dict(kind='fnv-runtime-gaps-ledger', status='analysis-only', inputs=dict(
            data_plan_sha256=self.hash('plan'), detail_sha256=self.plan['detail_sha256'],
            recipe_sha256=self.hash('recipes'), retained_sha256=self.hash('retained')), targets=[
                dict(target_va='0x00400202', occurrences=2, class_occurrences={'other-code': 2}),
                dict(target_va='0x00400301', occurrences=1, class_occurrences={'EH-interior-ambiguous': 1}),
                dict(target_va='0x00400999', occurrences=1, class_occurrences={'other-code': 1})])
        self.write('ledger', self.ledger)
        self.args = argparse.Namespace(root=self.root, detail=detail, recipes=self.root/'recipes.json',
                                        out=self.root/'report.json', details_gz=self.root/'observations.gz')
        for name in ('ledger', 'plan', 'retained', 'manifest'):
            setattr(self.args, name, self.root/(name+'.json'))
            setattr(self.args, name+'_sha256', self.hash(name))

    def write(self, name, data): (self.root/(name+'.json')).write_text(json.dumps(data))
    def hash(self, name): return eh.digest(self.root/(name+'.json'))

    def rebind_receipt(self):
        self.write('retained', self.receipt); self.args.retained_sha256 = self.hash('retained')
        self.ledger['inputs']['retained_sha256'] = self.hash('retained')
        self.write('ledger', self.ledger); self.args.ledger_sha256 = self.hash('ledger')

    def test_overlap_repeats_interior_and_unmatched_preserved(self):
        report = eh.run(self.args)
        self.assertEqual(report['summary']['candidate_observations'], 3)
        self.assertEqual(report['summary']['by_class']['other-code']['covered_targets'], 1)
        self.assertEqual(report['summary']['by_class']['other-code']['covered_occurrences'], 2)
        self.assertEqual(report['summary']['multiple_observation_targets'], 1)
        with gzip.open(self.args.details_gz, 'rt') as f: rows = [json.loads(x) for x in f]
        self.assertEqual([r['section'] for r in rows[:2]], [2, 3])
        self.assertEqual([r['target_native_offset'] for r in rows], [2, 2, 5])
        self.assertTrue(all(r['target_position'] == 'interior' for r in rows))
        self.assertTrue(report['targets'][1]['input_EH_ambiguity'])
        self.assertFalse(report['targets'][2]['piece_coverage'])
        self.assertTrue(all(not r['runtime_eligible'] and not r['selected_provider'] for r in rows))
        self.assertTrue(all(r['physical_associative_parent']['status'] == 'unknown-no-associative-parent' for r in rows))

    def test_diagnostics_and_absent_index_are_explicit(self):
        self.receipt_unit['eh_errors'] = ['synthetic local diagnostic']; self.rebind_receipt()
        report = eh.run(self.args)
        self.assertEqual(report['summary']['diagnostic_bearing_targets'], 2)
        self.assertEqual(report['optional_index_status'], 'absent-original-oracle-limitation')
        self.assertFalse(report['runtime_eligible'])

    def test_altered_actual_object_rejected(self):
        with (self.root/'unit.obj').open('ab') as f: f.write(b'changed')
        with self.assertRaisesRegex(ValueError, 'object hash'): eh.run(self.args)

    def test_altered_source_rejected(self):
        (self.root/'fixture.cpp').write_text('void changed_fixture() {}')
        with self.assertRaisesRegex(ValueError, 'source record hash'): eh.run(self.args)

    def test_swapped_same_length_receipt_rejects_stale_trusted_hash(self):
        self.receipt_unit['eh_sections'][0], self.receipt_unit['eh_sections'][1] = self.receipt_unit['eh_sections'][1], self.receipt_unit['eh_sections'][0]
        self.write('retained', self.receipt)
        with self.assertRaisesRegex(ValueError, 'SHA-256'): eh.run(self.args)

    def test_rebound_receipt_conflicting_object_identity_rejected(self):
        self.receipt_unit['object_sha256'] = '0'*64; self.rebind_receipt()
        with self.assertRaisesRegex(ValueError, 'identity conflict'): eh.run(self.args)

    def test_wrong_parent_and_piece_length_rejected(self):
        for key, value in ((1, 0x400205), (3, '0x00400101')):
            with self.subTest(key=key):
                old = self.receipt_unit['eh_sections'][0][key]
                self.receipt_unit['eh_sections'][0][key] = value; self.rebind_receipt()
                with self.assertRaisesRegex(ValueError, 'piece identity'): eh.run(self.args)
                self.receipt_unit['eh_sections'][0][key] = old

    def test_stale_manifest_and_recipe_conflict_rejected(self):
        self.manifest['units'][0]['source'] = 'wrong.cpp'; self.write('manifest', self.manifest)
        with self.assertRaisesRegex(ValueError, 'SHA-256'): eh.run(self.args)
        self.args.manifest_sha256 = self.hash('manifest')
        with self.assertRaisesRegex(ValueError, 'reconciliation'): eh.run(self.args)

    def test_optional_index_presence_change_rejected(self):
        (self.root/'build/function_index.json').write_text('{}')
        with self.assertRaisesRegex(ValueError, 'index presence'): eh.run(self.args)

    def test_output_overwrite_and_input_alias_rejected(self):
        eh.run(self.args)
        with self.assertRaisesRegex(ValueError, 'output exists'): eh.run(self.args)
        self.args.out = self.root/'fresh.json'; self.args.details_gz = self.args.ledger
        with self.assertRaisesRegex(ValueError, 'overwrite'): eh.run(self.args)
        self.assertFalse(self.args.out.exists())

    def test_detail_identity_and_duplicate_site_rejected(self):
        with self.args.detail.open('ab') as f: f.write(b'changed')
        with self.assertRaisesRegex(ValueError, 'SHA-256'): eh.run(self.args)
        with gzip.open(self.args.detail, 'wt') as f:
            for row in [self.rows[0], self.rows[0]]: f.write(json.dumps(row)+'\n')
        with self.assertRaisesRegex(ValueError, 'duplicate'): eh.groups_from_detail(self.plan, self.args.detail)

    def test_inline_candidates_preserve_every_observation(self):
        self.args.details_gz = None
        report = eh.run(self.args)
        self.assertEqual(sum(len(x['candidates']) for x in report['candidate_details']), 3)

    def test_physical_parent_is_separate_and_unlisted_copy_stays_unverified(self):
        inventory = SimpleNamespace(sections={1: dict(selection='no_duplicates', association=0),
                                              2: dict(selection='associative', association=1)},
            symbols={0: dict(section=1, name='_physical', value=0, type=0x20)})
        parent = eh.physical_parent(inventory, 2, [])
        self.assertEqual(parent['section'], 1)
        self.assertFalse(parent['exact_body_verified_same_object'])
        verified = [dict(section=1, value=0, symbol='_physical', verdict='match')]
        parent = eh.physical_parent(inventory, 2, verified)
        self.assertTrue(parent['exact_body_verified_same_object'])
        self.assertFalse(parent['frame_contract_verified'])
        inventory.sections[1] = dict(selection='associative', association=2)
        with self.assertRaisesRegex(ValueError, 'cyclic'): eh.physical_parent(inventory, 2, verified)

    def test_stale_producer_tool_identity_rejected(self):
        self.receipt['inputs']['tools_sha256']['tools/build_and_match.py'] = '0'*64
        self.rebind_receipt()
        with self.assertRaisesRegex(ValueError, 'tool identity'): eh.run(self.args)


if __name__ == '__main__': unittest.main()
