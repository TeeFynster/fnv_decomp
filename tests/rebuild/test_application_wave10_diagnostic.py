"""Synthetic response edits only; no Game input or native invocation."""
import sys,unittest
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import application_wave10_diagnostic as prep

def fixture():
    prior=['/ALTERNATENAME:cell%d=pointer%d'%(n,n) for n in range(31)];crt=['/ALTERNATENAME:crt%d=provider%d'%(n,n) for n in range(4)]
    tokens=['/OUT:'+str(Path('old')/'diagnostic.exe'),'/MAP:'+str(Path('old')/'diagnostic.map'),'kernel-selected.lib','user-selected.lib','other.lib']+prior+crt
    return ['\n'.join('"'+t+'"' for t in tokens),Path('old'),Path('new'),'CODE68.lib',prior,crt,prior,crt]

class Tests(unittest.TestCase):
    def test_add_one_archive_preserves_all_selected_libraries_and_35_aliases(self):
        args=fixture();result=prep.response_tokens(*args)
        self.assertEqual(len(result),41);self.assertEqual(result.count('CODE68.lib'),1);self.assertIn('kernel-selected.lib',result);self.assertIn('user-selected.lib',result)
        self.assertEqual(sum(t.startswith('/ALTERNATENAME:') for t in result),35)
    def test_disabled_aliases_removed_before_enabled_subsets(self):
        args=fixture();args[6]=args[4][:-1];args[7]=[];result=prep.response_tokens(*args)
        self.assertNotIn(args[4][-1],result);self.assertNotIn(args[5][0],result)
    def test_unreviewed_new_IAT_or_CRT_alias_rejected(self):
        for index in (6,7):
            args=fixture();args[index]=args[index]+['/ALTERNATENAME:extra=other']
            with self.assertRaises(ValueError):prep.response_tokens(*args)
    def test_duplicate_archive_or_inherited_alias_rejected(self):
        for mode in ('archive','alias'):
            args=fixture()
            if mode=='archive':args[3]='other.lib'
            else:args[0]+='\n"'+args[4][0]+'"'
            with self.assertRaises(ValueError):prep.response_tokens(*args)
    def test_unreviewed_baseline_alias_or_FORCED_policy_rejected(self):
        for extra in ('/ALTERNATENAME:bad=other','/FORCE'):
            args=fixture();args[0]+='\n"'+extra+'"'
            with self.assertRaises(ValueError):prep.response_tokens(*args)
if __name__=='__main__':unittest.main()
