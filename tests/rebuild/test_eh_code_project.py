"""Authored EH object projection tests; no actual reference or artifact input."""
import copy
from types import SimpleNamespace
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/rebuild'))
import eh_code_project as projector
import test_eh_code_closure as authored

class ProjectionTests(unittest.TestCase):
    def component(self):
        obj,raw,p,c,reference=authored.fixture();plan=authored.eh.observe_component(raw,p,c,reference);generic=authored.generic_for(plan,obj)
        decision=authored.eh.compose(plan,generic,copy.deepcopy(generic),authored.contract_for(plan))
        emitted,receipt=authored.eh.serialize_authored_component(raw,plan,decision)
        return obj,raw,plan,reference,emitted,receipt
    def test_original_core_and_all_fields_before_after(self):
        _,raw,plan,reference,emitted,receipt=self.component()
        before=projector.reference_check(raw,plan,reference);after=projector.reference_check(emitted,plan,reference,maps=receipt['maps'])
        self.assertEqual(before['ordinary'][0]['verdict'],'match');self.assertEqual(after['ordinary'][0]['compiled_extent'],101)
        self.assertEqual(len(after['fields']),11);self.assertEqual([p[:4] for p in before['eh_sections']],[p[:4] for p in after['eh_sections']])
        self.assertEqual([x['nonfield_differences'] for x in after['comparisons']],[0,0,0]);self.assertFalse(after['provider_selected'])
    def test_code_state_relocation_and_registry_changes_reject(self):
        for mode in ('code','state','reloc','registry','extent'):
            _,_,plan,reference,emitted,receipt=self.component();obj=authored.eh.coff.parse(emitted);sm=receipt['maps']['section_map']
            if mode=='code':data=bytearray(obj['sections'][sm[3]]['payload']);data[1]^=1;obj['sections'][sm[3]]['payload']=bytes(data)
            elif mode=='state':data=bytearray(obj['sections'][sm[6]]['payload']);data[0]^=1;obj['sections'][sm[6]]['payload']=bytes(data)
            elif mode=='reloc':obj['sections'][sm[4]]['relocs'].pop()
            elif mode=='registry':obj['sections'][sm[16]]['payload']=struct.pack('<I',0)
            else:obj['sections'][sm[3]]['payload']+=b'\x90';obj['sections'][sm[3]]['size']+=1
            changed=authored.encode(obj)
            with self.assertRaises(ValueError):projector.reference_check(changed,plan,reference,maps=receipt['maps'])
    def test_forged_original_target_is_not_accepted_by_equal_code(self):
        _,raw,plan,reference,emitted,receipt=self.component();plan['fields'][0]['original_target']+=1
        with self.assertRaises(ValueError):projector.reference_check(emitted,plan,reference,maps=receipt['maps'])
    def test_fresh_resolved_private_directory_only(self):
        with tempfile.TemporaryDirectory() as folder,patch.object(projector,'ROOT',Path(folder)):
            private=Path(folder)/'build/rebuild';private.mkdir(parents=True)
            self.assertEqual(projector.output_directory(private/'new'),private/'new')
            for bad in (Path(folder)/'public/new',private,private/'../../escape'):
                with self.assertRaises(ValueError):projector.output_directory(bad)
            (private/'existing').mkdir()
            with self.assertRaises(ValueError):projector.output_directory(private/'existing')
    def test_protected_index_and_input_drift_reject(self):
        with tempfile.TemporaryDirectory() as folder,patch.object(projector,'ROOT',Path(folder)):
            root=Path(folder);source=root/'source';source.write_text('stable');pins={source:authored.eh.file_sha(source)};projector.stable(pins)
            source.write_text('drift')
            with self.assertRaises(ValueError):projector.stable(pins)
            pins[source]=authored.eh.file_sha(source);(root/'build').mkdir();(root/'build/function_index.json').write_text('appeared')
            with self.assertRaises(ValueError):projector.stable(pins)

    def test_authored_project_pipeline_and_late_drift_cleanup(self):
        for fail in (False,True):
            obj,raw,p,c,reference=authored.fixture();reference.data=b'authored-reference'
            c['reference_identity_sha256']=authored.eh.sha(reference.data)
            plan=authored.eh.observe_component(raw,p,c,reference);generic=authored.generic_for(plan,obj)
            structural=authored.eh.compose(plan,generic,copy.deepcopy(generic),authored.contract_for(plan))
            decision=copy.deepcopy(structural);decision.update(source_files_verified=True,serialization_plan_ready=True,blockers=[])
            observation=dict(kind='fnv-iotask-eh-metadata-observation',input_stability=True,emission_performed=False,plan=plan,composition=decision)
            with tempfile.TemporaryDirectory() as folder,patch.object(projector,'ROOT',Path(folder)):
                directory=Path(folder);(directory/'build/rebuild').mkdir(parents=True)
                native=directory/'input.obj';native.write_bytes(raw);image=directory/'reference';image.write_bytes(reference.data)
                obs=directory/'observation.json';obs.write_text(json.dumps(observation));op=directory/'operation.json';op.write_text('{}')
                args=SimpleNamespace(observation=obs,observation_sha256=authored.eh.file_sha(obs),operation=op,operation_sha256=authored.eh.file_sha(op),projector_sha256=authored.eh.file_sha(projector.__file__),out_dir=directory/'build/rebuild/output')
                serialize=lambda data,observed_plan,observed_decision:authored.eh.serialize_authored_component(data,observed_plan,structural)
                calls=[]
                def final_stability(pins):
                    calls.append(len(calls)+1)
                    if fail and len(calls)==4:raise ValueError('injected final input drift')
                with patch.object(projector,'protected_inputs',return_value=({native:authored.eh.sha(raw)},native,image)),patch.object(projector.oracle,'Pe',return_value=reference),patch.object(projector.oracle,'image_ok',return_value=(True,16,16)),patch.object(projector.eh,'serialize_component',side_effect=serialize),patch.object(projector,'stable',side_effect=final_stability):
                    if fail:
                        with self.assertRaises(ValueError):projector.project(args)
                    else:receipt=projector.project(args);self.assertEqual(receipt['emitted_objects'],1)
                self.assertTrue((args.out_dir/'progress.jsonl').exists());self.assertTrue((args.out_dir/'component.staged.obj').exists())
                self.assertEqual((args.out_dir/'component.obj').exists(),not fail)
                self.assertEqual((args.out_dir/'projection.json').exists(),not fail)

if __name__=='__main__':unittest.main()
