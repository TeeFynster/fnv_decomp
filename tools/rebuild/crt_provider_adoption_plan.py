"""Saved-evidence CRT function and paired-cookie diagnostic binding proposal.

No image/library/object reads, native tools, alias application or execution.
The response files are reviewable proposals, consumable only by a separately
reviewed diagnostic successor whose complete input-field census agrees.
"""
from __future__ import annotations
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
PINS={
 'application-frontier-dispatch-v1/index.json':'9db04c24f9030ba7bae153e54c01ef9475a4a1a203268bcbc3edc88136565ae9',
 'application-frontier-dispatch-v1/crt-frontier-lane-01.json':'488c95630eba6d549b41c52eabb7617341f2524cee5e4051b22fcff76d33fcfc',
 'application-frontier-dispatch-v1/crt-frontier-lane-02.json':'8b006fbb9d5097bc696873c7bd2df80e35318cd012d069617b0df02f53b0389c',
 'application-frontier-dispatch-v1/crt-frontier-lane-03.json':'adb0668f8389fa904bf7c68904cc7e44ef67f47adb25c040511f5fec1544f801',
 'application-frontier-dispatch-v1/crt-frontier-lane-04.json':'382f6153c8276f4ffec750eb6b97d0612fb285d966812a7e29f20619b52cec28',
 'application-link-diagnostic-v4/receipt.json':'08b3330fd12f626d776fa037e4444ba89daff02f5126f8265d439f5c1b7c22ba',
 'application-link-diagnostic-v4/unresolved-groups.json':'763d7f206b9c838184364071ea035fe9c352dbf25d2a5fb597e7523587ca1a31',
 'application-cohort-observation-v1/receipt.json':'9848b08bfd51244412700d25cd9cc53136253e90117a4c3b67b03c347961586b',
 'entry-crt-link-plan-native-v1.json':'99e16d2120d7b8249136fde98a78fb2c08f1c268f8cb4d424ab33216dad57082',
 'entry-crt-inclusion-census-v1.json':'3485973616caa132364c053d43e61eb71ff84c92e70ea69f47aab80cdf90dece',
 'entry-crt-provider-evidence-v1.json':'f18aed478641b9502a262b608421757c9c9707f9f4f730d2b152db93bc5891f1',
 'crt-bootstrap-native-v3/prepare.json':'11c875c4badb25e80e50e3c1a194de5e26133986c1d7df62d776aef18545ff6b',
 'crt-frontier-lane01-candidates-v1.json':'22022a3beb0cd331c75c252101871252695a5236f9a7cc7f1922312d87104219',
 'crt-lane01-observation-v1.json':'1ff45ec87caada27f3101508008e9d0763832bc400ffdbbd4fb2016b29c92d22',
 'crt-lane01-outcome-review-lane04-v1.json':'dc7e11c4649b5a3dba549f8d905821a862826de6deb37aee2a75e223d6fa8733',
 'crt-lane02-link-contracts-v1.json':'b46f023c5228c06d15c83b29e9c025e401f9b94a146594e1ceb2e99b44c32ac4',
 'crt-lane02-observation-v1.json':'8b2484c22a5810bd78d92353652298c2f1564b3c87290c9c2f830ecd23a5d79c',
 'crt-lane02-outcome-review-by-lane03-v1.json':'e7916e8c24c0180c9ef8d0b38856cfe5d2311e7f963c0c3ffe6707d9b5cf8fbc',
 'crt-lane03-link-contracts-v1.json':'57b28c34a30fcec1c1cf3626c7790dc8d171e922dc72a4a1a497276ad1852d73',
 'crt-lane03-observation-v1.json':'be96828b689345d269eaadf5edd7c6b79fa86a28e5208a4d9fd04020b42a091a',
 'crt-lane03-outcome-review-by-lane02-v1.json':'097e30e41dd40f22c051d626187f24c8ea724f66ac5a4a4358cfbdf73d250cf2',
 'crt-lane04-link-contracts-v1.json':'e9494c9ecf50566dbdabf9fe5332fb218dd957703a6ea5f4cddd1e5cd2b33e49',
 'crt-lane04-observation-v1.json':'fcca50ae0ec7c9183b567716ef8c4ec276807d43ca16e51ad6cb8890ba0e1334',
 'crt-lane04-outcome-review-lane01-v1.json':'3f3978eea791725b504b0b87f47eef3d6e0fbfa3228c4ca21ab691bdf51efea3',
}
UNITS='62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c'
LIBRARY='bd9700d126d378f31f32736abc0c88cb08a8e0f0914acb6e2c8cbfd1ab99f411'
BINDINGS=(('0x00ec408c','crt-contract','@__security_check_cookie@4',20),
          ('0x011c16bc','data','___security_cookie',6),
          ('0x00ecc071','code','__wcsicmp',20),
          ('0x00406d50','code','_strcat_s',20))

def require(ok,message):
    if not ok:raise ValueError(message)

def canonical(value):return json.dumps(value,sort_keys=True,separators=(',',':')).encode('utf-8')
def digest(value):return hashlib.sha256(canonical(value)).hexdigest()
def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def undefined(base,role):return '_fnv_undefined_'+digest(dict(original_base=base,role=role))

def field_key(row):
    return (row['component'],row['member'],row['caller'],row['section'],row['offset'])

def census(fields,base,role,kind):
    name=undefined(base,role); result=[];seen=set()
    for row in fields:
        if row.get('canonical')!=name:continue
        p=row['proof']
        require(p['original_base']==base and p['role']==role and
            int(p['original_target'],0)==int(base,0),'role/base/target collision')
        require(row['kind']==p['kind']==kind and p['addend_bits']==0,
                'unsupported relocation kind/addend')
        require(row['physical_symbol_index']==p.get('physical_symbol_index',p['symbol_index']) and row['undefined'] is True,
                'physical symbol proof differs')
        require(field_key(row) not in seen,'duplicate physical field')
        seen.add(field_key(row));result.append(row)
    return sorted(result,key=field_key)

def response(bindings):
    require(len({row['canonical_undefined'] for row in bindings})==len(bindings),
        'duplicate or conflicting canonical aliases')
    rows=[]
    for row in bindings:
        for value in (row['canonical_undefined'],row['normal_export']):
            require(value and not any(c.isspace() for c in value) and
                    all(c not in value for c in '"=/\\'),'unsafe response token')
        rows.append('/ALTERNATENAME:'+row['canonical_undefined']+'='+row['normal_export'])
    return '\n'.join(rows)+'\n'

def private_outputs(folder):
    require(folder.resolve()==folder,'private rebuild output root redirects')
    paths=(folder/'application-crt-adoption-plan-v1.json',folder/'application-crt-adoption-v4-proposal-v1.rsp')
    require(all(p.resolve().is_relative_to(folder) and not p.exists() for p in paths),
        'exclusive new private outputs required')
    return paths

def cookie_recipe_proofs(fields,units):
    proofs=[]
    for row in fields:
        unit=units[int(row['recipe_id'].split('-')[0])]
        names=sorted(n for n,a in unit['symbols'].items() if int(a,0)==0x011c16bc)
        require(names==['___security_cookie'],'cookie cell recipe identity is ambiguous')
        proofs.append(dict(recipe_id=row['recipe_id'],root=row['root'],field=field_key(row),
            original_base='0x011c16bc',source=unit['source'],source_symbol='___security_cookie',
            normal_storage_width=4,normal_storage_owner='SP1 libcmt gs_cookie.obj'))
    return proofs

def cohort(fields,groups,providers,units,expected_counts):
    rows=[]
    for base,role,export,kind in BINDINGS:
        name=undefined(base,role); uses=census(fields,base,role,kind)
        require(len(uses)==expected_counts[base],'complete alias census differs: '+base)
        group=groups[name]
        require(group['original_bases']==[base] and group['observed_roles']==[role] and
            not group['definition_observations'],'canonical name is not an undefined exact role key')
        provider=providers[(base,role)]
        require(provider['export']==export and provider['archive_sha256']==LIBRARY,
                'named normal provider differs')
        row=dict(original_base=base,role=role,canonical_undefined=name,normal_export=export,
            normal_family='sp1',normal_provider=provider,fields=uses,field_count=len(uses),
            distinct_input_callers=len({x['caller'] for x in uses}),
            field_census_sha256=digest(uses),actual_V4_error_records=group['error_records'],
            reported_LINK_callers=group['reported_reference_callers'],
            input_provenance_is_extraction_proof=False,diagnostic_binding_eligible=True,
            runtime_ABI_approved=False,provider_adopted=False)
        if role=='data':row['recipe_cookie_proofs']=cookie_recipe_proofs(uses,units)
        rows.append(row)
    require({x['original_base'] for x in rows if 'cookie' in x['normal_export']}==
        {'0x011c16bc','0x00ec408c'},'cookie data/helper must be paired')
    return rows

def run():
    folder=ROOT/'build/rebuild';paths={folder/n:h for n,h in PINS.items()};paths[ROOT/'build/units.json']=UNITS
    out,rsp=private_outputs(folder)
    implementation={p:sha(ROOT/p) for p in ('tools/rebuild/crt_provider_adoption_plan.py',
            'tests/rebuild/test_crt_provider_adoption_plan.py')}
    for p,h in paths.items():require(sha(p)==h,'saved input pin differs: '+p.name)
    saved={n:json.loads((folder/n).read_text()) for n in PINS}
    units=json.loads((ROOT/'build/units.json').read_text())['units']
    baseline=saved['application-link-diagnostic-v4/receipt.json']
    require(baseline['returncode']!=0 and not baseline['executable_execution'], 'not failed V4 diagnostic')
    fields=[r for group in baseline['provenance'].values() for r in group if r.get('proof')]
    require(len(fields)==baseline['full_included_field_count']==37282,'baseline complete field census differs')
    groups={g['symbol']:g for g in saved['application-link-diagnostic-v4/unresolved-groups.json']['groups']}
    prior=saved['entry-crt-link-plan-native-v1.json']
    providers={(p['original_base'],p['role']):p['proposed_provider'] for p in prior['provider_candidates']
               if p['proposed_provider']}
    boot=saved['crt-bootstrap-native-v3/prepare.json']; cookie=boot['layouts']['mixed']['map_contributors']['___security_cookie']
    require(cookie['kind']=='archive-member' and cookie['member']=='gs_cookie.obj' and
        cookie['symbol_index_join'] is True and cookie['archive_sha256']==LIBRARY,
        'normal cookie map/member provenance differs')
    providers[('0x011c16bc','data')]=dict(compiler_family='sp1',export='___security_cookie',
        library='libcmt.lib',**boot['normal_cookie_member'],map_contributor=cookie,
        normal_storage_width=4,original_storage_identity_required=False)
    v4=cohort(fields,groups,providers,units,{'0x00ec408c':58,'0x011c16bc':54,'0x00ecc071':1,'0x00406d50':3})
    expanded=saved['application-cohort-observation-v1/receipt.json']
    supplement=[r for r in expanded['supplementary_fields'] if r['component']!='IOTask-EH']
    require(len(supplement)==7071 and expanded['baseline_receipt_sha256']==PINS['application-link-diagnostic-v4/receipt.json'],
        'prospective cohort identity differs')
    prospective=cohort(fields+supplement,groups,providers,units,
        {'0x00ec408c':99,'0x011c16bc':93,'0x00ecc071':1,'0x00406d50':3})
    # Keep all accepted model evidence and unknowns as bound saved inputs. These
    # rows are not added to the four-action response by names or address alone.
    models={name:saved[name] for name in ('crt-frontier-lane01-candidates-v1.json',
        'crt-lane02-link-contracts-v1.json','crt-lane03-link-contracts-v1.json','crt-lane04-link-contracts-v1.json')}
    frontier=[]
    for lane in range(1,5):
        packet=saved['application-frontier-dispatch-v1/crt-frontier-lane-%02d.json'%lane]
        for target in packet['targets']:
            frontier.append(dict(lane=lane,original_target=target['original_target'],
                field_count=len(target['field_uses']),field_proofs=target['field_uses'],
                actual_V4_unresolved_groups=target['actual_V4_unresolved_groups'],
                names_are_hypotheses_only=True,provider_selected=False))
    require(len(frontier)==190 and len({t['original_target'] for t in frontier})==190 and
        sum(t['field_count'] for t in frontier)==2631,'complete frontier partition differs')
    plan=dict(kind='exact-normal-CRT-diagnostic-adoption-plan',schema_version=1,
        inputs={n:h for n,h in PINS.items()},units_sha256=UNITS,
        sources=implementation,
        current_actual_V4=dict(complete_input_fields=37282,bindings=v4,binding_count=4,
            alias_field_count=116,remaining_actual_targets_before=255,
            expected_resolved_target_names=[r['canonical_undefined'] for r in v4],
            response_text=response(v4),native_operation_authorized=False),
        prospective_expanded_cohort=dict(complete_input_fields=44353,bindings=prospective,
            binding_count=4,alias_field_count=196,excluded_component='IOTask-EH',
            future_freeze_requires_independent_identity_review=True,native_operation_authorized=False),
        accepted_four_lane_models=models,
        complete_190_target_frontier=frontier,
        normal_runtime_owner=dict(family='sp1',library='libcmt.lib',archive_sha256=LIBRARY,
            startup='normal WinMainCRTStartup with fresh startup/init/termination',
            cookie='one normal cookie/complement initialized before source-owned protected frames',
            FILE='one fresh CRT owns open/read/write/seek/tell/buffering/descriptor/lock/EOF/error/close',
            heap='one allocation family owns malloc/new/calloc/realloc/free/delete and failure policy',
            locale_errno_invalid_parameter='normal fresh locale,per-thread errno and invalid-parameter policy',
            original_numeric_state_addresses_must_equal_normal=False,
            no_original_state_copy_or_alias=True),
        function_contracts={
            '@__security_check_cookie@4':dict(boundary='x86 fastcall ECX cookie word, normal return or failure',
                coupling='paired normal ___security_cookie alias; bootstrap cookie/complement/init owner',
                remaining_runtime_gates=['actual game frame and every generated consumer startup/lifetime compatibility']),
            '___security_cookie':dict(boundary='writable four-byte normal CRT scalar',
                recipe_identity='every included own recipe uniquely binds ___security_cookie to the original cell',
                coupling='normal gs_cookie.obj complement and normal ___security_init_cookie',
                remaining_runtime_gates=['no stronger original arena definition may supersede alias','normal startup before protected call']),
            '__wcsicmp':dict(boundary='cdecl two readable UTF16 string pointers; signed int result',
                coupling='normal CRT owns locale/errno/invalid-parameter dependencies internally',
                remaining_runtime_gates=['terminated second operand original placeholder DATA extent/lifetime','source argument lifetime']),
            '_strcat_s':dict(boundary='cdecl char destination,size_t32 capacity,const char source;errno_t32 result',
                coupling='accepted transparent three-stack-word wrapper elision; normal CRT errno/invalid-parameter owner',
                remaining_runtime_gates=['terminated valid char260 local destinations','borrowed source lifetime and overlap rules'])},
        earlier_fread_component=prior['source_owned_file_component'],
        consumer_requirements=['separate independently reviewed diagnostic successor only; frozen V5 unchanged',
            'rehash all plan/provider inputs and verify exact complete field census for selected cohort',
            'reject any strong definition collision for any canonical alias; especially cookie data',
            'append four exact ALTERNATENAME tokens to normal SP1 library diagnostic response',
            'no FORCE,stub,duplicate suppression,old-code forwarding,or pointer-cell/function interchange',
            'retain native failure/log/map; compare unresolved namespaces before/after',
            'check selected normal CRT map/archive owners if map exists; failure is not runtime approval',
            'no application execution'],
        alias_applied=False,provider_adopted=False,runtime_ABI_approved=False,runtime_eligible=False)
    for p,h in paths.items():require(sha(p)==h,'saved input changed: '+p.name)
    for p,h in implementation.items():require(sha(ROOT/p)==h,'implementation changed')
    with out.open('x',encoding='utf-8') as stream:json.dump(plan,stream,indent=2);stream.write('\n')
    with rsp.open('x',encoding='ascii') as stream:stream.write(response(v4))
    print(json.dumps(dict(plan=str(out),plan_sha256=sha(out),response=str(rsp),response_sha256=sha(rsp),
        binding_count=4,current_alias_fields=116,prospective_alias_fields=196)))

if __name__=='__main__':run()
