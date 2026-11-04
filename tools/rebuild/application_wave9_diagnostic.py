"""Prepare the exact V9 diagnostic cohort; no native operations."""
import application_link_diagnostic as diagnostic

def require(ok,message):
    if not ok:raise ValueError(message)

def response_tokens(text,old_out,out,replacements,addition,prior_IAT,prior_CRT,allowed_IAT,new_IAT,new_CRT):
    lines=text.splitlines()
    require(all(len(line)>2 and line.startswith('"') and line.endswith('"') for line in lines),'malformed baseline response')
    tokens=[line[1:-1] for line in lines]
    for old,new in [('/OUT:'+str(old_out/'diagnostic.exe'),'/OUT:'+str(out/'diagnostic.exe')),('/MAP:'+str(old_out/'diagnostic.map'),'/MAP:'+str(out/'diagnostic.map'))]+list(replacements):
        require(tokens.count(old)==1 and new not in tokens,'one exact old token and fresh replacement required')
        tokens[tokens.index(old)]=new
    require(len(replacements)==2 and len({old for old,new in replacements})==len({new for old,new in replacements})==2,'exact two library replacements required')
    require(len(prior_IAT)==27 and len(prior_CRT)==4 and len(allowed_IAT)==31 and len(set(allowed_IAT))==31 and
        set(prior_IAT).issubset(allowed_IAT) and set(new_IAT).issubset(allowed_IAT) and len(set(new_IAT))==len(new_IAT) and
        len(new_CRT)<=4 and len(set(new_CRT))==len(new_CRT) and set(new_CRT).issubset(prior_CRT),'only reviewed successor enabled subsets permitted')
    inherited=prior_IAT+prior_CRT
    require(len(set(inherited))==31 and all(tokens.count(token)==1 for token in inherited),'exact inherited aliases required')
    tokens=[token for token in tokens if token not in inherited]
    require(not any(token.startswith('/ALTERNATENAME:') for token in tokens),'unreviewed inherited alias')
    require(addition not in tokens,'duplicate additional CODE archive')
    aliases=new_IAT+new_CRT
    require(all(token.startswith('/ALTERNATENAME:') and token.count('=')==1 for token in aliases) and
        len({token.split('=',1)[0] for token in aliases})==len(aliases),'conflicting successor aliases')
    tokens += [addition]+aliases
    diagnostic.response_text(tokens)
    return tokens

import argparse,gzip,importlib,json
from pathlib import Path
import application_wave8_diagnostic as previous
import application_wave9_inputs as joins
import normal_import_archive as import_archive
import iat_field_annotations as annotations
ROOT=Path(__file__).resolve().parents[2]
PINS={'tools/rebuild/application_frontier_inputs.py': '2f47fc9ec0893b1be1168c328f4418be8df340a6aec4c39354bf4fce32406cd2', 'tests/rebuild/test_application_frontier_inputs.py': 'fccd1ae08d51fb0969922552aa8d92afbe0dd872d305e0bfa1d4f321932f6514', 'tools/rebuild/import_kernel32_nine.py': '696903fd3d5affaf0158da5ccbed7278f05a3b1f3da775c331b72eab22cd3864', 'tools/rebuild/normal_import_archive.py': '42a0eff5852d89aaadb1f239baf3884e7a2dcd4216870407d7e8510a6d68bf28', 'tools/rebuild/application_link_diagnostic.py': '74cca67c3ec414931f4bfb26403338734f87da5eb28952e2327d008cbb79b379', 'tools/rebuild/iat_field_annotations.py': '5ce0b3ae5069cde206b334bddc94515b308e611ef1cc269783cbd386fd778ae6', 'tests/rebuild/test_iat_field_annotations.py': 'fb8efec99e6e72761e7969997ba3665896c4afcfdea8dbb4e1a205c831da091b', 'docs/rebuild/APPLICATION-WAVE9-DIAGNOSTIC.md': 'ec879116da4120b942d066185e16e0dc88ae70a1b87c0f911ce26bfd287b1322', 'tools/rebuild/application_wave8_diagnostic.py': '5643730f3031086829286d14c102e7a374da10f16cec187532a6ab89c3e09669', 'tools/rebuild/application_wave9_inputs.py': '27aab788d3b2ab887a2ff3eca2ba2cba98894110d261a71b0868b40e5cc8f596', 'tests/rebuild/test_application_wave9_inputs.py': '751926e1d81a8b191a896f2a35340dc91fd0f635307606abb85ba82162646d44', 'build/rebuild/application-wave9-inputs-source-review.json': '1885f90e2f92da5636fdf03f1c35bcbc7cb4c32a7820b33da0a0eefbbbb41519', 'build/rebuild/application-wave9-cohort-observation-v1/receipt.json': '1aa0c183db889f70dd9af88d934b61f8cc82297924656c5fe7483ebca4c16410', 'build/rebuild/application-wave9-cohort-observation-v1/fields.json.gz': '36c69324f6ebf5113610b4de20bed24476eb2122bd02a585d2eaec773c228976', 'build/rebuild/application-wave9-cohort-observation-v1/independent-outcome-review.json': '7ce0cd49abd728ffc64521193faccbcbe54114904cb3889811cf725327bffae4', 'build/rebuild/application-link-diagnostic-v8-wave/receipt.json': 'b53dcae11fd4b9e26def8ba82feebe4393da93098a87dfa01005a96e17c0b86a', 'build/rebuild/application-link-diagnostic-v8-wave/link.rsp': '640cd3b768e320ea45bf70005392bbfc4e7749c6fd3c286818426b01d5e3460d', 'build/rebuild/application-link-diagnostic-v8-wave/link-receipt.json.gz': 'c364d56e6a24ada784073740c778cb3adc6e3170cf79f12812e9c0f7e9a7d38c', 'build/rebuild/application-link-diagnostic-v8-wave/independent-outcome-review.json': '3effbc9c6ca7176b5b6a0179d6e9a0b51e29b87d1e2b19dbc7de64172bdfee15', 'build/rebuild/frontier-wave7-native-conformance-v1/receipt.json': '8421d0ccf4793c5a7f52d7b7f6e9af6ea21c9d87b6e76abf9eae6c0227b0dd27', 'build/rebuild/frontier-wave7-native-conformance-v1/independent-outcome-review.json': '549fbbdd249fa13045f6ac365159dc68a7aa9b59fd9d66760930813b19dd25aa', 'tools/rebuild/import_projection.py': 'b13a2e805950ff4dc79fdaa1a8d12b00bb8a9c171853d77180ddb069857df865', 'tools/rebuild/import_kernel32_extension.py': '15177c10e9b6469e0abab5c54e0ec6ef18afb9829cc275bef831795e9f358307', 'tools/rebuild/runtime_code_pool.py': '729f189e2893c7f3a3e3cd97df7d7381ac115169e1d75cf664e6bbc1c587b277'}
INPUT_PATHS={'crt_plan': 'build/rebuild/application-crt-v9-four-contract-v1.json', 'crt_review': 'build/rebuild/application-crt-v9-four-contract-peer-v1.json', 'crt_response': 'build/rebuild/application-crt-v9-four-proposal-v1.rsp', 'crt_consumer': 'tools/rebuild/crt_v9_four_alias_contract.py', 'crt_consumer_tests': 'tests/rebuild/test_crt_v9_four_alias_contract.py', 'crt_producer': 'tools/rebuild/crt_v9_four_alias_plan.py', 'crt_producer_tests': 'tests/rebuild/test_crt_v9_four_alias_plan.py', 'crt_consumer_peer': 'build/rebuild/crt-v9-four-consumer-peer-v1.json', 'import_producer': 'tools/rebuild/import_v8_four_successor.py', 'import_producer_tests': 'tests/rebuild/test_import_v8_four_successor.py', 'import_request': 'build/rebuild/import-v8-four-v1/preparation.json', 'import_request_peer': 'build/rebuild/import-v8-four-v1/independent-source-input-review.json', 'import_native': 'build/rebuild/import-v8-four-native-v1/collection.json', 'import_native_peer': 'build/rebuild/import-v8-four-native-v1/independent-outcome-review.json', 'kernel_library': 'build/rebuild/import-v8-four-native-v1/kernel32-twelve.lib', 'user_library': 'build/rebuild/import-v8-four-native-v1/user32-sixteen.lib'}
IMPORT_ANCESTRY={'catalog': 'build/rebuild/import-plan-native-v3.json', 'assessment': 'build/rebuild/v8-four-import-assessment-v1/assessment.json', 'assessment_review': 'build/rebuild/v8-four-import-assessment-v1/independent-outcome-review.json', 'prior_native': 'build/rebuild/import-kernel32-nine-native-v1/collection.json', 'prior_review': 'build/rebuild/import-kernel32-nine-native-v1/independent-outcome-review.json', 'fields': 'build/rebuild/application-wave8-cohort-observation-v1/fields.json.gz'}

def selected_import_replacements(repository,paths,request,baseline_text,baseline_bindings):
    specs={'KERNEL32.dll':('build/rebuild/import-kernel32-nine-native-v1/kernel32-nine.lib','kernel_library','kernel32-nine.lib'),
        'USER32.dll':('build/rebuild/application-link-inputs-v2/provider-003.lib','user_library','provider-003.lib')}
    require(len(request['replacements'])==2 and {r['dll'] for r in request['replacements']}==set(specs),'exact replacement DLL set required')
    result=[]
    for row in request['replacements']:
        relative,key,old_name=specs[row['dll']];selected=repository/relative
        require(row['old_library']==old_name and selected.resolve()==selected and baseline_text.splitlines().count('"'+str(selected)+'"')==1,
            'exact inherited selected library token required')
        require(any(b.get('requested_path')==str(selected) and b.get('path')==str(selected) and b.get('sha256')==row['old_library_sha256'] for b in baseline_bindings),
            'selected library physical provenance missing')
        require(diagnostic.file_hash(selected)==row['old_library_sha256'],'selected library bytes differ from native ancestry')
        result.append((str(selected),str(paths[key])))
    return result

def native_import_evidence(receipt,request,request_sha256,parsed,producer,expected_sources):
    require(request.get('inputs')=={key+'_sha256':value for key,value in producer.PINS.items()} and
        request.get('source_sha256')==expected_sources,'successor import evidence/source ancestry differs')
    expected=producer.reconcile(request,parsed,request_sha256)
    require(all(key in receipt and receipt[key]==value for key,value in expected.items()),'native two-library producer replay differs')
    require(receipt.get('all_inputs_tools_sources_stable') is True,'native library input/tool/source stability required')
    return expected

def prepare(repository,out,source_sha256,tests_sha256,input_path,input_sha256):
    repository=Path(repository).resolve();out=Path(out).absolute();input_path=Path(input_path).absolute()
    require(out.resolve()==out and out.parent==repository/'build/rebuild' and not out.exists(),'exclusive private output required')
    require(input_path.resolve()==input_path and input_path.parent==repository/'build/rebuild' and diagnostic.file_hash(input_path)==input_sha256,'exact private reviewed request required')
    bindings=[]
    def bind(path,expected):
        path=Path(path);require(diagnostic.file_hash(path)==expected,'bound input differs: '+str(path));bindings.append(diagnostic.identity(path));return path
    pins=previous.source_pins(diagnostic.SOURCE_PINS,PINS)
    pins.update({'tools/rebuild/application_wave9_diagnostic.py':source_sha256,'tests/rebuild/test_application_wave9_diagnostic.py':tests_sha256})
    for name,sha in pins.items():bind(repository/name,sha)
    request=json.loads(bind(input_path,input_sha256).read_text())
    require(request.get('kind')=='fixed-wave9-diagnostic-inputs' and request.get('schema_version')==1 and set(request.get('inputs',{}))==set(INPUT_PATHS),'exact successor input request required')
    paths={}
    for key,relative in INPUT_PATHS.items():
        row=request['inputs'][key];require(set(row)=={'path','sha256'} and row['path']==relative,'fixed successor input path required')
        paths[key]=bind(repository/relative,row['sha256'])
    # Bind the complete inherited source/dependency closure before any new dynamic
    # producer or consumer import reuses previously reviewed CRT modules.
    old_out=repository/'build/rebuild/application-link-diagnostic-v8-wave';report=json.loads((old_out/'receipt.json').read_text())
    diagnostic.stable(report['input_bindings']);bindings.extend(report['input_bindings'])
    producer=importlib.import_module('import_v8_four_successor')
    contract=importlib.import_module('crt_v9_four_alias_contract')
    for relative,sha in producer.HELPER_PINS.items():bind(repository/relative,sha)
    data={}
    for key,relative in IMPORT_ANCESTRY.items():
        path=bind(repository/relative,producer.PINS[key])
        if key!='fields':data[key]=json.loads(path.read_text())
    for relative,sha in data['assessment']['inputs'].items():
        path=repository/relative;require(path.resolve().is_relative_to(repository),'import assessment ancestry outside workspace');bind(path,sha)
    expected_sources=dict(producer.HELPER_PINS,**{'tools/rebuild/import_v8_four_successor.py':request['inputs']['import_producer']['sha256']})
    for relative,sha in data['assessment']['inputs'].items():
        if (repository/relative).is_relative_to(repository/'tools'):expected_sources[relative]=sha
    import_request=json.loads(paths['import_request'].read_text())
    require({row['definition']['file'] for row in import_request['replacements']}=={'kernel32-twelve.def','user32-sixteen.def'},'exact import definition inputs required')
    for row in import_request['replacements']:bind(paths['import_request'].parent/row['definition']['file'],row['definition']['sha256'])
    native_receipt=json.loads(paths['import_native'].read_text())
    parsed={paths[key].name:import_archive.read_archive(paths[key]) for key in ('kernel_library','user_library')}
    native=native_import_evidence(native_receipt,import_request,request['inputs']['import_request']['sha256'],parsed,producer,expected_sources)
    request_peer=json.loads(paths['import_request_peer'].read_text())
    require(request_peer.get('kind')=='fnv-v8-four-import-successor-source-input-review' and type(request_peer.get('schema_version')) is int and request_peer['schema_version']==1 and
        request_peer.get('status')=='accepted_source_and_prepared_inputs_only' and request_peer.get('request_sha256')==request['inputs']['import_request']['sha256'] and
        request_peer.get('source_sha256')==import_request['source_sha256'],'import source/input peer ancestry differs')
    import_peer=json.loads(paths['import_native_peer'].read_text())
    require(import_peer.get('kind')=='fnv-v8-four-import-successor-independent-outcome-review' and type(import_peer.get('schema_version')) is int and import_peer['schema_version']==1 and
        import_peer.get('status')=='accepted_metadata_conformance_only' and
        import_peer.get('collection_sha256')==request['inputs']['import_native']['sha256'] and
        import_peer.get('request_sha256')==request['inputs']['import_request']['sha256'],'import native peer ancestry differs')
    require(import_peer.get('libraries')==[{key:row[key] for key in ('file','sha256','bytes')} for row in native['libraries']],'import native peer library identities differ')
    obs=json.loads((repository/'build/rebuild/application-wave9-cohort-observation-v1/receipt.json').read_text())
    diagnostic.stable(obs['input_bindings']);bindings.extend(obs['input_bindings'])
    with gzip.open(repository/'build/rebuild/application-wave9-cohort-observation-v1/fields.json.gz','rt',encoding='utf-8') as stream:fields=json.load(stream)
    require(len(fields)==obs['complete_field_count']==45318 and obs['selected_Game_function_candidates']==14408 and obs['ordinary_prepared_count']==14403,'full successor field/provider scope differs')
    require(diagnostic.digest(diagnostic.canonical(sorted(fields,key=diagnostic.canonical)))==obs['fields_canonical_sha256'],'full successor field digest differs')
    gate=contract.validate(paths['crt_plan'].read_bytes(),paths['crt_review'].read_bytes(),paths['crt_response'].read_bytes(),fields,obs['provider_namespace']['symbols'])
    require(len(gate['tokens'])<=4 and gate['alias_field_count']==202,'existing-four CRT scope differs')
    crt_plan=json.loads(paths['crt_plan'].read_text())
    for name,sha in crt_plan['inputs'].items():
        path=repository/'build/rebuild'/name;require(path.resolve().is_relative_to(repository/'build/rebuild'),'CRT metadata ancestry outside private directory');bind(path,sha)
    for name,sha in crt_plan['sources'].items():bind(repository/name,sha)
    bind(repository/'build/units.json',crt_plan['units_sha256'])
    require(isinstance(crt_plan.get('own_sources'),dict) and len(crt_plan['own_sources'])==2,'exact two own-source identities required')
    for name,sha in crt_plan['own_sources'].items():
        path=repository/name;require(path.resolve().is_relative_to(repository/'src'),'own source outside source tree');bind(path,sha)
    code_native=json.loads((repository/'build/rebuild/frontier-wave7-native-conformance-v1/receipt.json').read_text())
    previous.native_scope(code_native,'wave7-code3','frontier-wave7-native-conformance-v1','aeb5920faa0be15c6c8d174cc0003be8876ebb1ecdfbfb0ae69e177703d7f11f',3,3)
    catalog=data['catalog']
    libraries={paths[key].name:diagnostic.partial.native_archive(paths[key].read_bytes()) for key in ('kernel_library','user_library')}
    for row in native['unchanged_libraries']:
        path=bind(repository/'build/rebuild/import-native-main-v2'/row['library'],row['sha256']);libraries[row['library']]=diagnostic.partial.native_archive(path.read_bytes())
    require(len(libraries)==4,'exact selected four import libraries required')
    aliases=joins.wave9_alias_census(native['proposed_pointer_aliases'],annotations.census_view(fields,catalog),catalog,libraries)
    require(len(aliases)==31 and sum(row['proof'].get('role')=='iat-cell' for row in fields)==409,'full IAT candidate scope differs')
    for row in aliases:
        row['evaluation_view_sha256']=diagnostic.digest(diagnostic.canonical(row['complete_actual_uses']))
        uses=[field for field in fields if field['canonical']==row['canonical']]
        require(len(uses)==row['use_count'],'normative/evaluation use count differs');row['complete_actual_uses']=uses;row['compact_proofs_preserved']=True
    require(gate['inherited_tokens_to_remove']==report['CRT_diagnostic_bindings']['tokens'],'CRT inherited token set differs')
    require(all(b['normal_provider']['archive_sha256']==report['default_libraries']['libcmt.lib']['sha256'] for b in crt_plan['bindings']),'selected normal CRT provider differs')
    prior_IAT=['/ALTERNATENAME:'+row['canonical']+'='+row['native_pointer'] for row in report['aliases'] if row['enabled']]
    allowed_IAT=['/ALTERNATENAME:'+row['canonical']+'='+row['native_pointer'] for row in aliases]
    new_IAT=['/ALTERNATENAME:'+row['canonical']+'='+row['native_pointer'] for row in aliases if row['enabled']]
    baseline_text=(old_out/'link.rsp').read_text()
    replacements=selected_import_replacements(repository,paths,import_request,baseline_text,report['input_bindings'])
    for old_path,new_path in replacements:
        row=next(row for row in import_request['replacements'] if row['new_library']==Path(new_path).name)
        bind(old_path,row['old_library_sha256'])
    addition=str(repository/'build/rebuild/frontier-wave-v7-production-v1/V7-code.lib')
    tokens=response_tokens(baseline_text,old_out,out,replacements,addition,prior_IAT,report['CRT_diagnostic_bindings']['tokens'],allowed_IAT,new_IAT,gate['tokens'])
    provenance={name:[row for row in group if not row.get('proof')] for name,group in report['provenance'].items()}
    for provider in obs['extra_providers']:provenance.setdefault(provider['canonical'],[]).append(provider)
    for field in fields:provenance.setdefault(field['canonical'],[]).append(field)
    report.update(kind='fixed-wave9-three-CODE-four-IAT-link-diagnostic',status='prepared-no-native-LINK',input_bindings=bindings,
        command=[report['command'][0],'@'+str(out/'link.rsp')],provenance=provenance,aliases=aliases,
        selected_supplementary_providers=report['selected_supplementary_providers']+obs['extra_providers'],selected_game_function_provider_count=14408,
        ordinary_prepared_count=14403,full_included_field_count=45318,CRT_diagnostic_bindings=gate,native_LINK_performed=False,executable_execution=False,
        runtime_eligible=False,provider_adopted=False,link_ready=False,whole_DATA_included=False,unreviewed_CRT_aliases=[],namespace_only=True,
        logical_CODE_address_only_aliases=[],IOTask_included=False,ModelLoader_included=True,IAT_actual_fields=409,
        additional_native_conformance_sha256=PINS['build/rebuild/frontier-wave7-native-conformance-v1/receipt.json'],
        import_native_receipt_sha256=request['inputs']['import_native']['sha256'],import_preparation_sha256=request['inputs']['import_request']['sha256'],
        observation_sha256=PINS['build/rebuild/application-wave9-cohort-observation-v1/receipt.json'],
        baseline_V8_actual_receipt_sha256=PINS['build/rebuild/application-link-diagnostic-v8-wave/link-receipt.json.gz'],input_request_sha256=input_sha256)
    diagnostic.stable(bindings);out.mkdir();(out/'link.rsp').write_text(diagnostic.response_text(tokens),encoding='utf-8')
    report['response_sha256']=diagnostic.file_hash(out/'link.rsp')
    with (out/'receipt.json').open('x',encoding='utf-8') as stream:json.dump(report,stream,separators=(',',':'))
    diagnostic.stable(bindings);return report

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('source-sha256','tests-sha256','inputs','inputs-sha256','out'):parser.add_argument('--'+name,required=True)
    args=parser.parse_args();r=prepare(ROOT,args.out,args.source_sha256,args.tests_sha256,args.inputs,args.inputs_sha256)
    print(json.dumps(dict(status=r['status'],native_LINK_performed=False,eligible_IAT_cells=sum(row['enabled'] for row in r['aliases']),CRT_bindings=len(r['CRT_diagnostic_bindings']['tokens']),fields=45318)))
if __name__=='__main__':main()
