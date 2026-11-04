import copy,sys,unittest,tempfile,hashlib
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import application_wave9_diagnostic as prep

def fixture():
    prior=['/ALTERNATENAME:cell%d=pointer%d'%(n,n) for n in range(27)]
    crt=['/ALTERNATENAME:crt%d=provider%d'%(n,n) for n in range(4)]
    allowed=prior+['/ALTERNATENAME:new%d=newptr%d'%(n,n) for n in range(4)]
    tokens=['/OUT:'+str(Path('old')/'diagnostic.exe'),'/MAP:'+str(Path('old')/'diagnostic.map'),'old-kernel.lib','old-user.lib','other.lib']+prior+crt
    return ['\n'.join('"'+t+'"' for t in tokens),Path('old'),Path('new'),[('old-kernel.lib','new-kernel.lib'),('old-user.lib','new-user.lib')],'three.lib',prior,crt,allowed,allowed,crt]

class Tests(unittest.TestCase):
    def test_exact_two_library_replacements_one_archive_and_35_aliases(self):
        args=fixture();tokens=prep.response_tokens(*args)
        self.assertEqual(len(tokens),41);self.assertIn('other.lib',tokens);self.assertNotIn('old-kernel.lib',tokens)
        self.assertEqual(sum(t.startswith('/ALTERNATENAME:') for t in tokens),35)
    def test_disabled_old_aliases_actually_removed(self):
        args=fixture();args[8]=args[7][:-1];args[9]=[]
        tokens=prep.response_tokens(*args);self.assertNotIn(args[6][0],tokens);self.assertNotIn(args[7][-1],tokens)
    def test_changed_old_pointer_identity_rejected(self):
        args=fixture();args[7]=list(args[7]);args[7][0]+='changed'
        with self.assertRaises(ValueError):prep.response_tokens(*args)
    def test_unreviewed_new_alias_rejected(self):
        args=fixture();args[8]=args[8]+['/ALTERNATENAME:surprise=other']
        with self.assertRaises(ValueError):prep.response_tokens(*args)
    def test_duplicate_library_or_archive_rejected(self):
        for mode in ('library','archive'):
            args=fixture()
            if mode=='library':args[3]=[args[3][0],args[3][0]]
            else:args[4]='other.lib'
            with self.assertRaises(ValueError):prep.response_tokens(*args)
    def test_extra_inherited_alias_rejected(self):
        args=fixture();args[0]+='\n"/ALTERNATENAME:extra=unreviewed"'
        with self.assertRaises(ValueError):prep.response_tokens(*args)
class NativeEvidenceTests(unittest.TestCase):
    def fixture(self):
        from test_import_v8_four_successor import request_and_parses
        import import_v8_four_successor as producer
        request,parsed=request_and_parses();sources={'synthetic-reviewed-producer':'b'*64}
        request['inputs']={key+'_sha256':value for key,value in producer.PINS.items()};request['source_sha256']=sources
        receipt=producer.reconcile(request,parsed,'c'*64);receipt['all_inputs_tools_sources_stable']=True
        return receipt,request,'c'*64,parsed,producer,sources
    def test_exact_two_actual_libraries_replay(self):
        result=prep.native_import_evidence(*self.fixture());self.assertEqual(len(result['libraries']),2);self.assertEqual(len(result['proposed_pointer_aliases']),31)
    def test_stale_failed_promoted_or_unrelated_native_receipt_rejected(self):
        for key,value in [('request_sha256','a'*64),('status','failed'),('alias_applied',True),('old_27_pointer_identities_preserved',False),('all_inputs_tools_sources_stable',False)]:
            args=list(self.fixture());args[0][key]=value
            with self.assertRaises(ValueError):prep.native_import_evidence(*args)
    def test_changed_actual_library_or_source_evidence_rejected(self):
        for kind in ('bytes','pointer','source','inputs'):
            args=list(self.fixture())
            if kind=='bytes':args[3]['kernel32-twelve.lib']['archive_bytes']+=1
            if kind=='pointer':args[3]['kernel32-twelve.lib']['imports'][0]['pointer_symbol']='__imp__Other'
            if kind=='source':args[1]['source_sha256']={}
            if kind=='inputs':args[1]['inputs']={}
            with self.assertRaises(ValueError):prep.native_import_evidence(*args)
class SelectedLibraryTests(unittest.TestCase):
    def exercise(self,mode):
        with tempfile.TemporaryDirectory() as folder:
            root=Path(folder).resolve();specs=[('KERNEL32.dll','build/rebuild/import-kernel32-nine-native-v1/kernel32-nine.lib','kernel_library'),('USER32.dll','build/rebuild/application-link-inputs-v2/provider-003.lib','user_library')]
            rows=[];bindings=[];text=[];paths={}
            for dll,relative,key in specs:
                p=root/relative;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(dll.encode());sha=hashlib.sha256(p.read_bytes()).hexdigest()
                rows.append(dict(dll=dll,old_library=p.name,old_library_sha256=sha));bindings.append(dict(requested_path=str(p),path=str(p),sha256=sha));text.append('"'+str(p)+'"');paths[key]=root/(key+'.lib')
            original=root/'build/rebuild/import-native-main-v2/provider-003.lib';original.parent.mkdir(parents=True);original.write_bytes(b'USER32.dll')
            if mode=='provenance':bindings[-1]['requested_path']=bindings[-1]['path']=str(original)
            if mode=='bytes':(root/specs[-1][1]).write_bytes(b'changed')
            if mode=='token':text[-1]='"'+str(original)+'"'
            result=prep.selected_import_replacements(root,paths,dict(replacements=rows),'\n'.join(text),bindings)
            self.assertEqual(result[-1][0],str(root/'build/rebuild/application-link-inputs-v2/provider-003.lib'))
    def test_exact_selected_partial_input_copy_not_original_native_path(self):self.exercise('valid')
    def test_same_bytes_without_selected_physical_provenance_rejected(self):
        with self.assertRaises(ValueError):self.exercise('provenance')
    def test_changed_selected_bytes_or_original_instead_of_selected_token_rejected(self):
        for mode in ('bytes','token'):
            with self.assertRaises(ValueError):self.exercise(mode)
if __name__=='__main__':unittest.main()
