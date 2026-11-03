"""Source/policy fixtures only; these tests never invoke a compiler."""
import copy
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/rebuild'))
import eh_type_overlay as overlay


def spec():return json.loads(overlay.SPEC.read_text())

def comparison_pair(s):
    pieces=[[100+n*10,110+n*10,n in (0,4),s['parent'],[]] for n in range(5)]
    state=dict(state_count=4,transitions=[dict(state=n,to_state=n-1) for n in range(4)])
    root=dict(role='parent',size=166,flags=1,selection='no_duplicates',payload_sha256='same',relocations=[dict(offset=1,kind=20,symbol='??0SubObjB@@QAE@H@Z',expected=0x633c90,observed=0x633c90,match=True),dict(offset=2,kind=20,symbol='??0SubObjB@@QAE@H@Z',expected=0x633c90,observed=0x633c90,match=True)])
    eh=dict(role='eh_code',size=68,flags=1,selection='associative',payload_sha256='same',relocations=[dict(offset=26,kind=20,symbol='??1SubObjB@@QAE@XZ',expected=0x488ff0,observed=0x40c110,match=False),dict(offset=37,kind=20,symbol='??1SubObjB@@QAE@XZ',expected=0x488ff0,observed=0x45cec0,match=False)])
    before=dict(ordinary=dict(verdict='match',size=166,compiled_extent=166),pieces=pieces,states=state,handler_offset=41,diagnostics=['SubObjA differs','SubObjB differs','SubObjB differs'],definitions=['parent'],runtime_sections=[],undefined=['??0SubObjB@@QAE@H@Z','??1SubObjB@@QAE@XZ'],sections=[root,eh,dict(role='metadata',size=68,flags=2,selection='associative',payload_sha256='same-meta',relocations=[])])
    after=copy.deepcopy(before);after['pieces'][2][2]=after['pieces'][3][2]=True;after['diagnostics']=['SubObjA differs'];after['undefined']=[]
    for n,v in enumerate(s['views']):
        ctor,dtor=overlay.view_symbols(v);after['sections'][0]['relocations'][n]['symbol']=ctor;after['sections'][1]['relocations'][n].update(symbol=dtor,expected=int(v['destructor_original'],16),match=True);after['undefined'] += [ctor,dtor]
    return before,after


class TypeOverlayTests(unittest.TestCase):
    def test_exact_generated_views_declarations_and_parent_body(self):
        s=spec();text=(ROOT/s['source']).read_text()
        a,acpp=overlay.generate(s,text,'baseline');b,bcpp=overlay.generate(s,text,'overlay')
        self.assertIn('SubObjB m_30;',a);self.assertIn('Overlay0043fd40Member30 m_30;',b)
        self.assertIn('Overlay0043fd40Member34 m_34;',b)
        self.assertIn('~Overlay0043fd40Member30();',b);self.assertIn('~Overlay0043fd40Member34();',b)
        self.assertEqual(acpp.split('// Constructs')[1],bcpp.split('// Constructs')[1])
        self.assertNotIn('throw()',b);self.assertNotIn('noexcept',b)
        self.assertIn('offsetof(FUN_0043fd40, m_34) == 52',bcpp)
        self.assertIn('sizeof(SpawnedBase) == 40',bcpp)
    def test_scope_and_merged_views_reject(self):
        for field,value in [('parent','0x0043fd50'),('size',165),('runtime_eligible',True)]:
            s=spec();s[field]=value
            with self.assertRaises(ValueError):overlay.validate_spec(s)
        s=spec();s['views'][1]=copy.deepcopy(s['views'][0])
        with self.assertRaises(ValueError):overlay.validate_spec(s)
    def test_source_and_slice_drift_reject(self):
        s=spec();text=(ROOT/s['source']).read_text()
        with self.assertRaises(ValueError):overlay.generate(s,text+'// drift','overlay')
        s['slice']['first_line']+=1
        with self.assertRaises(ValueError):overlay.generate(s,text,'overlay')
    def test_layout_diagnostics_and_padding_ledger(self):
        contracts=overlay.layouts(spec(),'overlay');text=''
        for name,c in contracts.items():
            text+=f'class {name} size({c["size"]}):\n'
            if name=='SpawnedBase':text+=' 0 | {vfptr}\n'
            if name=='FUN_0043fd40':text+=' 0 | +--- (base class SpawnedBase)\n'
        result=overlay.parse_layout(text,contracts)
        self.assertEqual(result['padding']['parent_tail'],0)
        with self.assertRaises(ValueError):overlay.parse_layout(text.replace('size(60)','size(64)'),contracts)
        with self.assertRaises(ValueError):overlay.parse_layout(text.replace(' 0 | {vfptr}',' 4 | {vfptr}'),contracts)
        with self.assertRaises(ValueError):overlay.parse_layout('',contracts)
    def test_real_unnumbered_base_subsection_is_scoped(self):
        contracts=overlay.layouts(spec(),'baseline');text=''
        for name,c in contracts.items():
            text+=f'class {name} size({c["size"]}):\n'
            if name=='SpawnedBase':text+=' 0 | {vfptr}\n'
            if name=='FUN_0043fd40':text+=' | +--- (base class SpawnedBase)\n 0 | | {vfptr}\n 4 | | unk04\n36 | | unk24\n | +---\n'
        overlay.parse_layout(text,contracts)
        for altered in (text.replace(' 4 | | unk04',' 8 | | unk04'),text.replace(' | +--- (base class SpawnedBase)',' | +--- (base class WrongBase)'),text.replace(' 0 | | {vfptr}',' 4 | | {vfptr}'),text.replace(' 0 | | {vfptr}','')+' 0 | | {vfptr}\n'):
            with self.assertRaises(ValueError):overlay.parse_layout(altered,contracts)
    def test_interleaved_include_notes_keep_exact_allowlist(self):
        with tempfile.TemporaryDirectory() as d:
            folder=Path(d);header=folder/'view.hpp';other=folder/'crt.h';p=dict(inputs={str(other):'hash'})
            log='42 | LayoutNote: including file: '+str(header)+'\n64 | LeafNote: including file: '+str(other)+'\n'
            self.assertEqual(len(overlay.includes(log,p,folder)),2)
            for bad in (log+'Note: including file: '+str(folder/'unknown.h')+'\n',log+'Note: including file: '+str(header)+' Note: including file: '+str(other),log+'including file: '+str(header)):
                with self.assertRaises(ValueError):overlay.includes(bad,p,folder)
    def test_targeted_improvement_retains_one_failure(self):
        s=spec();a,b=comparison_pair(s);overlay.validate_improvement(a,b,s)
    def test_matched_padding_extent_is_rejected_for_both_inputs(self):
        for mode in ('baseline','overlay'):
            s=spec();a,b=comparison_pair(s)
            (a if mode=='baseline' else b)['ordinary']['compiled_extent']=170
            with self.assertRaises(ValueError):overlay.validate_improvement(a,b,s)
    def test_ordinary_extra_reference_and_adapter_reject(self):
        for mode in ('ordinary','reference','adapter','payload','other_runtime'):
            s=spec();a,b=comparison_pair(s)
            if mode=='ordinary':b['ordinary']['verdict']='wip'
            if mode=='reference':b['undefined'].append('extra')
            if mode=='adapter':b['definitions'].append('adapter')
            if mode=='payload':b['sections'][0]['payload_sha256']='changed'
            if mode=='other_runtime':b['runtime_sections'].append(dict(name='.data',relocations=[]))
            with self.assertRaises(ValueError):overlay.validate_improvement(a,b,s)
    def test_subobja_failure_and_states_cannot_be_hidden(self):
        for mode in ('failure','transition','placement','merged'):
            s=spec();a,b=comparison_pair(s)
            if mode=='failure':b['pieces'][1][2]=True;b['diagnostics']=[]
            if mode=='transition':b['states']['transitions'].pop()
            if mode=='placement':b['pieces'][2][0]+=1
            if mode=='merged':b['sections'][1]['relocations'][1]['symbol']=b['sections'][1]['relocations'][0]['symbol']
            with self.assertRaises(ValueError):overlay.validate_improvement(a,b,s)
    def test_review_exact_sources_required(self):
        p=dict(schema_version=1,kind='fnv-eh-type-overlay-prepared',policy=overlay.POLICY,compile_performed=False,status='source-only-pending-review',runtime_eligible=False,provider_selected=False,link_eligible=False,generated={'a':'hash'})
        r=dict(schema_version=1,kind='fnv-eh-type-overlay-source-review',prepare_sha256='hash',approved=True,reviewer='reviewer',generated={'a':'hash'},checks={k:True for k in ('source_slice','declaration_only_views','layout_checks','comparison_only_bindings','compile_only_runner')})
        overlay.validate_review(p,r,'hash')
        for key in r['checks']:
            changed=copy.deepcopy(r);changed['checks'][key]=False
            with self.assertRaises(ValueError):overlay.validate_review(p,changed,'hash')
        r['generated']['a']='changed'
        with self.assertRaises(ValueError):overlay.validate_review(p,r,'hash')
    def test_stability_no_compilation(self):
        with tempfile.TemporaryDirectory() as d:
            p=Path(d)/'source';p.write_text('original');observations={str(p):overlay.sha(p)}
            overlay.stable(observations,{})
            p.write_text('changed')
            with self.assertRaises(ValueError):overlay.stable(observations,{})
    def test_bad_review_never_calls_compiler(self):
        with tempfile.TemporaryDirectory() as d:
            folder=Path(d);p=folder/'prepared';p.write_text('{}');r=folder/'review';r.write_text('{}')
            with patch.object(overlay.toolchain,'run') as run:
                with self.assertRaises(ValueError):overlay.compile_only(p,r,'0'*64,folder/'image',folder/'out')
                run.assert_not_called()
    def test_private_output_policy_and_stale_inputs(self):
        with self.assertRaises(ValueError):overlay.private_output(ROOT/'runtime'/'new-artifacts')
        with tempfile.TemporaryDirectory() as d:
            p=Path(d)/'input';p.write_text('{}')
            with self.assertRaises(ValueError):overlay.bound(p,'0'*64)

if __name__=='__main__':unittest.main()
