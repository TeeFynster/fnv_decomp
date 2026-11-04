"""Synthetic complete-cohort IAT identity checks, without native operations."""
import copy,sys,unittest
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import application_wave9_inputs as inputs
from test_application_frontier_inputs import census27

def census31():
    proposals,fields,catalog,libraries=copy.deepcopy(census27())
    for number in range(4):
        va='0x%08x'%(0x20000000+number*4);name='Extra%d'%number;offset=9000+number*100
        canonical='_fnv_undefined_'+inputs.digest(inputs.diagnostic.canonical(dict(original_base=va,role='iat-cell')))
        catalog['imports'].append(dict(original_IAT_va=va,dll='EXTRA.dll',export=dict(kind='name',name=name,hint=number),import_id=900+number))
        proposal=copy.deepcopy(proposals[0]);proposal.update(canonical_IAT_symbol=canonical,original_IAT_va=va,dll='EXTRA.dll',export=dict(kind='name',name=name),member_offset=offset,proposed_pointer_symbol='__imp__'+name)
        proposals.append(proposal)
        field=copy.deepcopy(fields[0]);field.update(canonical=canonical,member=name+'.obj');field['proof'].update(original_base=va,original_target=va,import_id=900+number);fields.append(field)
        libraries['fixture.lib']['imports'].append(dict(dll='EXTRA.dll',export=dict(kind='name',name=name),machine=0x14c,import_type=0,name_type=2,symbol='_'+name,pointer_symbol='__imp__'+name,member_offset=offset))
        libraries['fixture.lib']['index']+= [dict(symbol='_'+name,member_offset=offset),dict(symbol='__imp__'+name,member_offset=offset)]
    return proposals,fields,catalog,libraries

class Tests(unittest.TestCase):
    def test_full_thirty_one_includes_new_last_cell(self):
        result=inputs.wave9_alias_census(*census31())
        self.assertEqual(len(result),31);self.assertTrue(all(r['enabled'] for r in result));self.assertEqual(result[-1]['positive_import_identity'],('EXTRA.dll','name','Extra3'))
    def test_old_cardinality_and_duplicate_rejected(self):
        with self.assertRaises(ValueError):inputs.wave9_alias_census(*census27())
        args=list(census31());args[0][-1]=copy.deepcopy(args[0][0])
        with self.assertRaises(ValueError):inputs.wave9_alias_census(*args)
    def test_one_unproved_use_disables_only_its_global_cell(self):
        args=list(census31());extra=copy.deepcopy(args[1][-1]);extra['member']='bad.obj';extra['proof']['addend_bits']=4;args[1].append(extra)
        rows=inputs.wave9_alias_census(*args)
        self.assertTrue(all(r['enabled'] for r in rows[:-1]));self.assertFalse(rows[-1]['enabled']);self.assertEqual(rows[-1]['use_count'],2)
    def test_changed_native_export_or_original_DLL_disables_cell(self):
        for change in ('native','DLL'):
            args=list(census31())
            if change=='native':args[3]['fixture.lib']['imports'][-1]['export']['name']='Other'
            else:args[2]['imports'][-1]['dll']='OTHER.dll'
            rows=inputs.wave9_alias_census(*args);self.assertFalse(rows[-1]['enabled'])
if __name__=='__main__':unittest.main()
