"""Authored metadata fixtures only; no Game inputs or native operations."""
import copy,sys,unittest
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import application_link_wave10 as wave

def fixture():
    wrappers=[];members=[];records=[]
    for n in range(68):
        name='member%d.obj'%n;root={'original_address':'0x%08x'%(0x1000+n*256)};fields=[];compact=[]
        for i in range(10 if n<17 else 9):
            field=dict(function_va=root['original_address'],physical_section=n+1,physical_offset=i*4,
                coff_relocation=dict(offset=i*4,kind=6,symbol_index=i+100))
            fields.append(field);compact.append(dict(field_proof_sha256=wave.digest(field),section=n+1,offset=i*4,kind=6,symbol_index=i+100))
        authority={'record_sha256':str(n)};common=dict(authority=authority,certificate_sha256='cert'+str(n),contract_identity_sha256='contract'+str(n),central_record_sha256='central'+str(n))
        wrapper=dict(schema_version=1,source_evidence_enriched=False,member=name,requested_root=root,output_object_sha256='object'+str(n),fields=fields,fields_sha256=wave.digest(fields),**common)
        projection=dict(requested_roots=[root],output_sha256=wrapper['output_object_sha256'],fields=compact,**common)
        record=dict(member=name,root=root,member_sha256=wrapper['output_object_sha256'],field_proof_ordinal=n+1,
            field_proof_record_sha256=wave.digest(wrapper),original_fields_sha256=wrapper['fields_sha256'],fields=len(fields),**common)
        wrappers.append(wrapper);members.append(dict(name=name,projection=projection));records.append(record)
    return wrappers,members,dict(records=records)

class Tests(unittest.TestCase):
    def test_all_629_fullproofs_and_68_original_wrappers(self):self.assertEqual(len(wave.verify_proof_ledger(*fixture())),629)
    def test_missing_extra_or_duplicate_ordinal_rejected(self):
        for mode in ('missing','extra','duplicate'):
            args=list(fixture())
            if mode=='missing':args[0].pop()
            elif mode=='extra':args[0].append(copy.deepcopy(args[0][0]))
            else:args[2]['records'][-1]['field_proof_ordinal']=1
            with self.assertRaises(ValueError):wave.verify_proof_ledger(*args)
    def test_modified_fullproof_or_reordered_fields_rejected(self):
        for mode in ('field','order'):
            args=list(fixture())
            if mode=='field':args[0][0]['fields'][0]['physical_offset']=1000
            else:args[0][0]['fields'].reverse()
            with self.assertRaises(ValueError):wave.verify_proof_ledger(*args)
    def test_changed_member_root_or_output_ancestry_rejected(self):
        for mode in ('root','output','authority'):
            args=copy.deepcopy(fixture());p=args[1][0]['projection']
            if mode=='root':p['requested_roots']=[{'original_address':'0xffff'}]
            elif mode=='output':p['output_sha256']='other'
            else:p['authority']={'record_sha256':'other'}
            with self.assertRaises(ValueError):wave.verify_proof_ledger(*args)
    def test_compact_symbol_or_fieldproof_mismatch_rejected(self):
        for key,value in [('symbol_index',999),('field_proof_sha256','wrong')]:
            args=list(fixture());args[1][0]['projection']['fields'][0][key]=value
            with self.assertRaises(ValueError):wave.verify_proof_ledger(*args)
if __name__=='__main__':unittest.main()
