"""Independent authored-COFF cases for typed local LABEL support; no game inputs."""
from pathlib import Path
import copy
import importlib
import hashlib
import struct
import sys
import unittest
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/rebuild'))
import coff_code_archive as frozen
from test_coff_code_archive import section,symbol,aux,object_bytes


def label_fixture():
    """Distinct old section/symbol indices exercise every retained field map."""
    offsets=list(range(0,28,4));values=list(range(32,60,4));indices=list(range(5,12))
    secs=[section('.unused',b'authored-unused'),
          section('.text',bytes(64),relocs=list(zip(offsets,indices,[6]*7))),
          section('.drectve',b' /DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES" ',0x100a00)]
    symbols=[symbol('.unused',1,storage=3,auxiliary=aux(len(secs[0]['payload']))),
             symbol('.text',2,storage=3,auxiliary=aux(64,7)),symbol('_root',2,typ=32)]
    symbols += [symbol('$LN'+str(10+i),2,value=value,storage=6 if i<5 else 3) for i,value in enumerate(values)]
    symbols += [symbol('.drectve',3,storage=3,auxiliary=aux(len(secs[2]['payload']),selection=0))]
    raw=object_bytes(secs,symbols)
    return raw,dict(root_index=4,label_indices=indices,storage6_indices=indices[:5],static3_indices=indices[5:],
        field_offsets=offsets,label_values=values,keep_sections=[2,3],keep_symbols=[2]+list(range(4,13)),
        original_address=0x00500000,original_highlow_fields=[0x00500000+o for o in offsets])


class AuthoredLabelFixtureTests(unittest.TestCase):
    def test_actual_labels_are_distinct_physical_records(self):
        raw,m=label_fixture();obj=frozen.parse(raw)
        self.assertEqual(obj['symbol_count'],14)
        self.assertEqual([obj['symbols'][i]['storage'] for i in m['label_indices']],[6]*5+[3]*2)
        self.assertEqual([obj['symbols'][i]['value'] for i in m['label_indices']],m['label_values'])
        self.assertTrue(all(obj['symbols'][i]['type']==0 and obj['symbols'][i]['aux_count']==0 for i in m['label_indices']))
        self.assertEqual(obj['sections'][2]['relocs'],list(zip(m['field_offsets'],m['label_indices'],[6]*7)))
        self.assertTrue(all(o+4<=32<=v<64 for o,v in zip(m['field_offsets'],m['label_values'])))

    def test_frozen_serializer_rejects_actual_storage6(self):
        raw,m=label_fixture()
        with self.assertRaises(ValueError):frozen.serialize(raw,m['keep_sections'],m['keep_symbols'])

    def test_frozen_namespace_refuses_label_normalization(self):
        raw,m=label_fixture()
        with self.assertRaises(ValueError):frozen.namespace(raw,[(m['storage6_indices'][0],'_fake_global')])



def evidence_for(raw,meta):
    obj=frozen.parse(raw);base=meta['original_address'];fields=[]
    for off,idx,kind in obj['sections'][2]['relocs']:
        label=obj['symbols'][idx];bits=int.from_bytes(obj['sections'][2]['payload'][off:off+4],'little');target=(base+label['value']+bits)&0xffffffff
        fields.append(dict(physical_section=2,physical_offset=off,function_va='0x%08x'%base,
            original_field_va='0x%08x'%(base+off),derived_source_symbol_base_va='0x%08x'%(base+label['value']),
            exact_original_target_va='0x%08x'%target,original_operand=target,
            proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',physical_field_overlap_count=1,
            coff_relocation=dict(offset=off,symbol_index=idx,kind=kind,symbol=label['name'],symbol_section=label['section'],
                symbol_value=label['value'],symbol_type=label['type'],symbol_storage=label['storage'],addend=bits,width=4)))
    return dict(object_sha256=hashlib.sha256(raw).hexdigest(),source_sha256='b'*64,authority_sha256='c'*64,contract_sha256='d'*64,
        keep_sections=meta['keep_sections'],keep_symbols=meta['keep_symbols'],
        unit_functions=[dict(address='0x%08x'%base,section=2,size=64,symbol='_root',value=0,verdict='match')],
        fields=fields,original_highlow_sites=['0x%08x'%v for v in meta['original_highlow_fields']])


def symbol_mutation(raw,index,*,storage=None,typ=None,value=None,section_number=None):
    obj=frozen.parse(raw);out=bytearray(raw);at=obj['symbol_pointer']+18*index
    if storage is not None:out[at+16]=storage
    if typ is not None:struct.pack_into('<H',out,at+14,typ)
    if value is not None:struct.pack_into('<I',out,at+8,value)
    if section_number is not None:struct.pack_into('<h',out,at+12,section_number)
    return bytes(out)


class GuardedLabelProjectionTests(unittest.TestCase):
    def setUp(self):
        self.adapter=importlib.import_module('local_label_projection')
        self.raw,self.meta=label_fixture();self.evidence=evidence_for(self.raw,self.meta)

    def test_preserves_actual_storage6_and_every_staged_map(self):
        cert=self.adapter.prove_labels(self.raw,self.evidence)
        output,maps,receipt=self.adapter.serialize_labels(self.raw,self.meta['keep_sections'],self.meta['keep_symbols'],[],cert)
        old,new=frozen.parse(self.raw),frozen.parse(output)
        self.assertEqual(maps['section_map'],{2:1,3:2})
        self.assertEqual(maps['symbol_map'],{i:i-2 for i in [2]+list(range(4,13))})
        self.assertEqual(maps['auxiliary_map'],{3:1,13:11})
        self.assertEqual(new['sections'][1]['relocs'],[(o,i-2,6) for o,i in zip(self.meta['field_offsets'],self.meta['label_indices'])])
        self.assertEqual(new['sections'][1]['payload'],old['sections'][2]['payload'])
        for index in self.meta['label_indices']:
            a,b=old['symbols'][index],new['symbols'][maps['symbol_map'][index]]
            self.assertEqual({k:a[k] for k in ('name','value','type','storage','aux_count','aux')},{k:b[k] for k in ('name','value','type','storage','aux_count','aux')})
            self.assertEqual(b['section'],1)
        self.assertEqual(frozen.exports(output),['_root'])
        for key in ('provider_selected','runtime_eligible','emission_approved'):self.assertIs(receipt[key],False)

    def test_requires_all_physical_field_witnesses_and_unique_sites(self):
        for mutate in ('missing','duplicate','wrong_index','wrong_offset','wrong_section','wrong_storage'):
            e=copy.deepcopy(self.evidence)
            if mutate=='missing':e['fields'].pop()
            elif mutate=='duplicate':e['fields'].append(copy.deepcopy(e['fields'][0]))
            elif mutate=='wrong_index':e['fields'][0]['coff_relocation']['symbol_index']=6
            elif mutate=='wrong_offset':e['fields'][0]['coff_relocation']['offset']=1
            elif mutate=='wrong_section':e['fields'][0]['physical_section']=1
            else:e['fields'][0]['coff_relocation']['symbol_storage']=2
            with self.subTest(mutate=mutate),self.assertRaises(ValueError):self.adapter.prove_labels(self.raw,e)

    def test_exact_interior_target_operand_and_highlow_are_all_required(self):
        for mutate in ('target','base','operand','site','duplicate_site','function','overlap'):
            e=copy.deepcopy(self.evidence);row=e['fields'][0]
            if mutate=='target':row['exact_original_target_va']='0x00500021'
            elif mutate=='base':row['derived_source_symbol_base_va']='0x00500021'
            elif mutate=='operand':row['original_operand']+=1
            elif mutate=='site':e['original_highlow_sites'].pop(0)
            elif mutate=='duplicate_site':e['original_highlow_sites'].append(e['original_highlow_sites'][0])
            elif mutate=='function':row['function_va']='0x00500001'
            else:row['physical_field_overlap_count']=2
            with self.subTest(mutate=mutate),self.assertRaises(ValueError):self.adapter.prove_labels(self.raw,e)

    def test_full_owner_span_and_actual_label_geometry_required(self):
        for change in ('partial_size','bad_verdict','duplicate_owner','label_at_end','label_type','label_storage'):
            e=copy.deepcopy(self.evidence);raw=self.raw
            if change=='partial_size':e['unit_functions'][0]['size']=63
            elif change=='bad_verdict':e['unit_functions'][0]['verdict']='unknown'
            elif change=='duplicate_owner':e['unit_functions'].append(copy.deepcopy(e['unit_functions'][0]))
            elif change=='label_at_end':raw=symbol_mutation(raw,5,value=64);e=evidence_for(raw,self.meta)
            elif change=='label_type':raw=symbol_mutation(raw,5,typ=32);e=evidence_for(raw,self.meta)
            else:raw=symbol_mutation(raw,5,storage=105);e=evidence_for(raw,self.meta)
            with self.subTest(change=change),self.assertRaises(ValueError):self.adapter.prove_labels(raw,e)

    def test_rejects_forged_stale_certificate_or_selection_change(self):
        cert=self.adapter.prove_labels(self.raw,self.evidence)
        for raw,sections,symbols,undefined in [(self.raw+b'changed',[2,3],[2]+list(range(4,13)),[]),(self.raw,[2],[2]+list(range(4,13)),[]),(self.raw,[2,3],[2]+list(range(4,12)),[]),(self.raw,[2,3],[2]+list(range(4,13)),[5])]:
            with self.assertRaises(ValueError):self.adapter.serialize_labels(raw,sections,symbols,undefined,cert)
        forged=self.adapter.LabelCertificate(cert.evidence_json,cert.decision_json+' ')
        with self.assertRaises(ValueError):self.adapter.serialize_labels(self.raw,[2,3],[2]+list(range(4,13)),[],forged)

    def test_unsupported_external_label_spelling_is_not_global_provider(self):
        raw=symbol_mutation(self.raw,5,storage=2);e=evidence_for(raw,self.meta);e['fields']=e['fields'][1:]
        with self.assertRaises(ValueError):self.adapter.prove_labels(raw,e)

    def test_addend_cannot_escape_full_checked_interior(self):
        raw=bytearray(self.raw);obj=frozen.parse(self.raw)
        # Authored encoder puts the second section immediately after first payload.
        pointer=struct.unpack_from('<I',self.raw,20+40+20)[0]
        struct.pack_into('<I',raw,pointer,0x10000);raw=bytes(raw);e=evidence_for(raw,self.meta)
        with self.assertRaises(ValueError):self.adapter.prove_labels(raw,e)

    def test_malformed_label_auxiliary_and_global_name_collision_rejected(self):
        obj=frozen.parse(self.raw);bad=bytearray(self.raw);bad[obj['symbol_pointer']+18*5+17]=1
        e=copy.deepcopy(self.evidence);e['object_sha256']=hashlib.sha256(bad).hexdigest()
        with self.assertRaises(ValueError):self.adapter.prove_labels(bytes(bad),e)
        syms=[symbol(v['name'],v['section'],v['value'],v['type'],v['storage'],v['aux']) for v in obj['symbols'].values()]
        syms.append(symbol('$LN10',0,storage=2));raw=object_bytes(list(obj['sections'].values()),syms);e=evidence_for(raw,self.meta)
        with self.assertRaises(ValueError):self.adapter.prove_labels(raw,e)

    def test_reference_from_omitted_section_requires_complete_witness(self):
        obj=frozen.parse(self.raw);secs=list(obj['sections'].values());secs[0]=dict(secs[0],relocs=[(0,5,6)])
        syms=[]
        for i,v in obj['symbols'].items():
            auxiliary=aux(len(secs[0]['payload']),1) if i==0 else v['aux']
            syms.append(symbol(v['name'],v['section'],v['value'],v['type'],v['storage'],auxiliary))
        raw=object_bytes(secs,syms);e=evidence_for(raw,self.meta)
        with self.assertRaises(ValueError):self.adapter.prove_labels(raw,e)

    def test_boolean_metadata_cannot_masquerade_as_numeric_identity(self):
        for key in ('physical_offset','physical_field_overlap_count','offset','addend','symbol_type','owner_value'):
            e=copy.deepcopy(self.evidence)
            if key=='owner_value':e['unit_functions'][0]['value']=False
            elif key in ('offset','addend','symbol_type'):e['fields'][0]['coff_relocation'][key]=False
            else:e['fields'][0][key]=(key=='physical_field_overlap_count')
            with self.subTest(key=key),self.assertRaises(ValueError):self.adapter.prove_labels(self.raw,e)

    def test_missing_retained_label_is_not_silently_omitted(self):
        e=copy.deepcopy(self.evidence);e['keep_symbols'].remove(11)
        with self.assertRaises(ValueError):self.adapter.prove_labels(self.raw,e)

if __name__=='__main__':unittest.main()
