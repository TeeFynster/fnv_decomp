"""Offline collector boundary tests; no native input or collector run."""
import copy
import tempfile
from pathlib import Path
import sys
import unittest
from unittest.mock import patch
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/rebuild'))
import eh_code_observe as collector
import test_eh_code_closure as authored

class CollectorBoundaryTests(unittest.TestCase):
    def test_complete_review_tool_set_and_duplicates(self):
        values=[name+'='+'a'*64 for name in collector.TOOLS]
        self.assertEqual(set(collector.parse_tools(values)),set(collector.TOOLS))
        for bad in (values[:-1],values+[values[0]],values+['../foreign='+'a'*64]):
            with self.assertRaises(ValueError):collector.parse_tools(bad)
    def test_stability_and_absent_to_appeared_index(self):
        with tempfile.TemporaryDirectory() as folder:
            path=Path(folder)/'source';path.write_text('original');index=Path(folder)/'optional-index'
            pins={path:collector.eh.file_sha(path)};collector.stable(pins,index)
            path.write_text('changed')
            with self.assertRaises(ValueError):collector.stable(pins,index)
            pins[path]=collector.eh.file_sha(path);index.write_text('appeared')
            with self.assertRaises(ValueError):collector.stable(pins,index)
    def test_failed_final_stability_removes_only_own_report(self):
        with tempfile.TemporaryDirectory() as folder:
            out=Path(folder)/'metadata.json';index=Path(folder)/'index'
            with patch.object(collector,'stable',side_effect=ValueError('injected final drift')):
                with self.assertRaises(ValueError):collector.publish_metadata(out,{'input_stability':True},{},index)
            self.assertFalse(out.exists())
            out.write_text('foreign existing report')
            with self.assertRaises(FileExistsError):collector.publish_metadata(out,{}, {},index)
            self.assertEqual(out.read_text(),'foreign existing report')

    def test_image_gate_identity_missing_or_drift_rejected(self):
        with tempfile.TemporaryDirectory() as folder,patch.object(collector,'ROOT',Path(folder)):
            gate=Path(folder)/'build/image_check.json';gate.parent.mkdir();gate.write_text('authored gate')
            proof={'inputs':{'image_check_sha256':collector.eh.file_sha(gate)}};pins={}
            collector.bind_image_gate(proof,pins);self.assertEqual(pins,{gate:collector.eh.file_sha(gate)})
            collector.stable(pins,Path(folder)/'optional-index')
            gate.write_text('changed gate')
            with self.assertRaises(ValueError):collector.stable(pins,Path(folder)/'optional-index')
            gate.unlink()
            with self.assertRaises(OSError):collector.stable(pins,Path(folder)/'optional-index')
            with self.assertRaises(KeyError):collector.bind_image_gate({'inputs':{}},{})

    def test_private_output_and_journal_containment(self):
        with tempfile.TemporaryDirectory() as folder,patch.object(collector,'ROOT',Path(folder)):
            private=Path(folder)/'build/rebuild';private.mkdir(parents=True)
            out,journal=collector.private_outputs(private/'fresh/report.json')
            self.assertTrue(out.is_relative_to(private));self.assertTrue(journal.is_relative_to(private))
            for outside in (Path(folder)/'src/report.json',private/'../../public.json'):
                with self.assertRaises(ValueError):collector.private_outputs(outside)
    def test_symlink_output_escape_rejected(self):
        with tempfile.TemporaryDirectory() as folder,patch.object(collector,'ROOT',Path(folder)):
            private=Path(folder)/'build/rebuild';private.mkdir(parents=True);outside=Path(folder)/'public';outside.mkdir()
            try:(private/'escape').symlink_to(outside,target_is_directory=True)
            except OSError:self.skipTest('directory symlinks unavailable to this test process')
            with self.assertRaises(ValueError):collector.private_outputs(private/'escape/report.json')

    def test_external_filter_then_real_final_index_and_publication(self):
        obj,raw,p,c,reference=authored.fixture()
        with tempfile.TemporaryDirectory() as folder:
            directory=Path(folder);function_index_path=directory/'absent-function-index'
            source=directory/'source';source.write_text('stable source');pins={source:collector.eh.file_sha(source)}
            candidates=collector.external_base_candidates(obj,p,reference,c['parent_proof']['address'],c['eh_pieces'])
            self.assertEqual(candidates,{b['base'] for b in c['external_bindings'].values()})
            collector.stable(pins,function_index_path)
            out=directory/'metadata.json'
            collector.publish_metadata(out,{'candidate_count':len(candidates),'input_stability':True},pins,function_index_path)
            self.assertEqual(__import__('json').loads(out.read_text())['candidate_count'],7)
            self.assertFalse(function_index_path.exists())

    def context(self):
        obj,raw,p,c,r=authored.fixture();p['external_identities']['18']['role']='data';c['external_bindings']['18']['role']='data';bindings=c['external_bindings'];names={obj['symbols'][int(i)]['name']:b['base'] for i,b in bindings.items()}
        fields=[];shared={}
        for i,b in bindings.items():
            idx=int(i);domain=b['semantic_domain'];role=b['role'];cls='EXPLICIT_NORMAL_CRT_CONTRACT_CANDIDATE' if role=='crt-contract' else 'SELECTED_CODE_ENTRY' if role=='code' else 'ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER'
            row=dict(coff_relocation=dict(symbol_index=idx,symbol=obj['symbols'][idx]['name'],symbol_type=32 if domain=='code' else 0),proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',derived_source_symbol_base_va=hex(b['base']),classification=cls)
            shared[b['base']]=[row]
            if idx in (13,16,17,18):fields.append(row)
        return obj,p,names,fields,shared
    def test_exact_source_bindings_require_shared_witnesses(self):
        obj,p,names,fields,shared=self.context()
        bindings,ledger=collector.external_context(obj,p,fields,{},names,{},shared)
        self.assertEqual(len(bindings),7);self.assertEqual(len(ledger),7)
        collector.eh.validate_external_identities({int(k):v for k,v in bindings.items()},{int(k):v for k,v in p['external_identities'].items()},ledger)
    def test_unknown_conflicting_or_ambiguous_shared_identity_stays_blocked(self):
        for mode in ('missing','role','domain','proof','source-conflict','unknown-class','subtype'):
            obj,p,names,fields,shared=self.context();base=next(iter(shared))
            if mode=='missing':shared.pop(base)
            elif mode=='role':shared[base][0]['classification']='ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER'
            elif mode=='unknown-class':shared[base][0]['classification']='UNSUPPORTED_OR_UNMAPPED'
            elif mode=='subtype':
                shared[base][0].update(classification='EXPLICIT_NORMAL_CRT_CONTRACT_CANDIDATE');shared[base][0]['coff_relocation']['symbol']='___CxxFrameHandler3'
            elif mode=='domain':shared[base][0]['coff_relocation']['symbol_type']=0
            elif mode=='proof':shared[base][0]['proof_consistency']='guess'
            else:
                field=copy.deepcopy(fields[0]);field['derived_source_symbol_base_va']='0x12345678';fields.append(field)
            with self.assertRaises(ValueError):collector.external_context(obj,p,fields,{},names,{},shared)

if __name__=='__main__':unittest.main()
