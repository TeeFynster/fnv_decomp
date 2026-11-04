"""Prepare V9 plus exact CODE68; no native operations."""
import argparse,gzip,importlib,json
from pathlib import Path
import application_link_diagnostic as diagnostic
import application_wave8_diagnostic as foundation
import application_wave9_diagnostic as predecessor
import application_wave9_inputs as joins
import normal_import_archive as import_archive
ROOT=Path(__file__).resolve().parents[2]

def require(ok,message):
    if not ok:raise ValueError(message)

def response_tokens(text,old_out,out,addition,prior_IAT,prior_CRT,new_IAT,new_CRT):
    lines=text.splitlines();require(all(len(t)>2 and t.startswith('"') and t.endswith('"') for t in lines),'exact quoted baseline response required')
    tokens=[t[1:-1] for t in lines]
    for old,new in [('/OUT:'+str(old_out/'diagnostic.exe'),'/OUT:'+str(out/'diagnostic.exe')),('/MAP:'+str(old_out/'diagnostic.map'),'/MAP:'+str(out/'diagnostic.map'))]:
        require(tokens.count(old)==1 and new not in tokens,'exact old output/fresh successor required');tokens[tokens.index(old)]=new
    require(len(prior_IAT)==31 and len(prior_CRT)==4 and len(set(prior_IAT+prior_CRT))==35 and
        len(set(new_IAT))==len(new_IAT) and set(new_IAT).issubset(prior_IAT) and len(set(new_CRT))==len(new_CRT) and set(new_CRT).issubset(prior_CRT),'only existing enabled alias subsets permitted')
    inherited=prior_IAT+prior_CRT;require(all(tokens.count(t)==1 for t in inherited),'exact inherited aliases required')
    tokens=[t for t in tokens if t not in inherited]
    require(not any(t.startswith('/ALTERNATENAME:') for t in tokens) and addition not in tokens,'unreviewed alias or duplicate archive')
    aliases=new_IAT+new_CRT
    require(all(t.startswith('/ALTERNATENAME:') and t.count('=')==1 for t in aliases) and len({t.split('=',1)[0] for t in aliases})==len(aliases),'conflicting successor aliases')
    tokens += [addition]+aliases;diagnostic.response_text(tokens);return tokens

PINS={'tools/rebuild/application_frontier_inputs.py': '2f47fc9ec0893b1be1168c328f4418be8df340a6aec4c39354bf4fce32406cd2', 'tests/rebuild/test_application_frontier_inputs.py': 'fccd1ae08d51fb0969922552aa8d92afbe0dd872d305e0bfa1d4f321932f6514', 'tools/rebuild/import_kernel32_nine.py': '696903fd3d5affaf0158da5ccbed7278f05a3b1f3da775c331b72eab22cd3864', 'tools/rebuild/normal_import_archive.py': '42a0eff5852d89aaadb1f239baf3884e7a2dcd4216870407d7e8510a6d68bf28', 'tools/rebuild/application_link_diagnostic.py': '74cca67c3ec414931f4bfb26403338734f87da5eb28952e2327d008cbb79b379', 'tools/rebuild/iat_field_annotations.py': '5ce0b3ae5069cde206b334bddc94515b308e611ef1cc269783cbd386fd778ae6', 'tests/rebuild/test_iat_field_annotations.py': 'fb8efec99e6e72761e7969997ba3665896c4afcfdea8dbb4e1a205c831da091b', 'docs/rebuild/APPLICATION-WAVE9-DIAGNOSTIC.md': 'ec879116da4120b942d066185e16e0dc88ae70a1b87c0f911ce26bfd287b1322', 'tools/rebuild/application_wave8_diagnostic.py': '5643730f3031086829286d14c102e7a374da10f16cec187532a6ab89c3e09669', 'tools/rebuild/application_wave9_inputs.py': '27aab788d3b2ab887a2ff3eca2ba2cba98894110d261a71b0868b40e5cc8f596', 'tests/rebuild/test_application_wave9_inputs.py': '751926e1d81a8b191a896f2a35340dc91fd0f635307606abb85ba82162646d44', 'build/rebuild/application-wave9-inputs-source-review.json': '1885f90e2f92da5636fdf03f1c35bcbc7cb4c32a7820b33da0a0eefbbbb41519', 'build/rebuild/application-wave9-cohort-observation-v1/receipt.json': '1aa0c183db889f70dd9af88d934b61f8cc82297924656c5fe7483ebca4c16410', 'build/rebuild/application-wave9-cohort-observation-v1/fields.json.gz': '36c69324f6ebf5113610b4de20bed24476eb2122bd02a585d2eaec773c228976', 'build/rebuild/application-wave9-cohort-observation-v1/independent-outcome-review.json': '7ce0cd49abd728ffc64521193faccbcbe54114904cb3889811cf725327bffae4', 'build/rebuild/application-link-diagnostic-v8-wave/receipt.json': 'b53dcae11fd4b9e26def8ba82feebe4393da93098a87dfa01005a96e17c0b86a', 'build/rebuild/application-link-diagnostic-v8-wave/link.rsp': '640cd3b768e320ea45bf70005392bbfc4e7749c6fd3c286818426b01d5e3460d', 'build/rebuild/application-link-diagnostic-v8-wave/link-receipt.json.gz': 'c364d56e6a24ada784073740c778cb3adc6e3170cf79f12812e9c0f7e9a7d38c', 'build/rebuild/application-link-diagnostic-v8-wave/independent-outcome-review.json': '3effbc9c6ca7176b5b6a0179d6e9a0b51e29b87d1e2b19dbc7de64172bdfee15', 'build/rebuild/frontier-wave7-native-conformance-v1/receipt.json': '8421d0ccf4793c5a7f52d7b7f6e9af6ea21c9d87b6e76abf9eae6c0227b0dd27', 'build/rebuild/frontier-wave7-native-conformance-v1/independent-outcome-review.json': '549fbbdd249fa13045f6ac365159dc68a7aa9b59fd9d66760930813b19dd25aa', 'tools/rebuild/import_projection.py': 'b13a2e805950ff4dc79fdaa1a8d12b00bb8a9c171853d77180ddb069857df865', 'tools/rebuild/import_kernel32_extension.py': '15177c10e9b6469e0abab5c54e0ec6ef18afb9829cc275bef831795e9f358307', 'tools/rebuild/runtime_code_pool.py': '729f189e2893c7f3a3e3cd97df7d7381ac115169e1d75cf664e6bbc1c587b277', 'docs/rebuild/APPLICATION-WAVE10-DIAGNOSTIC.md': 'c4fd89dbd1658456b8adc2917bb143de28f5facdfec4f00fe8f920fd6515098f', 'tools/rebuild/application_wave9_diagnostic.py': 'd54916fcb1880eea03217cf5067684cd9ddc02af18bfaab6fc5b63a3b0e65cc7', 'tools/rebuild/iat_code68_annotations.py': '199e3d51b1ce2eb0e64cb1f780b81c2231cbd8b91a5fdc0460d196b07d7beed9', 'tests/rebuild/test_iat_code68_annotations.py': '4bc339bfa55ac5c1fc18cb3449ccdbdf1e37f8dcad7c54b1d241e5a0214254e0', 'tools/rebuild/application_link_wave10.py': '0370d085d4c2eb411a927abef1e149623859b077c907146a4106e24903893c68', 'tests/rebuild/test_application_link_wave10.py': 'b108ef03889fba6c2374570034537393ff97cdf552116f632a25c822a514a8d0', 'build/rebuild/application-wave10-cohort-observation-v1/receipt.json': 'd002831408a68ca88fe6adfedeb7288c0092bf7b818ea0be7d63a032994d0351', 'build/rebuild/application-wave10-cohort-observation-v1/fields.json.gz': '03c64e17917dfdacefbea440431fe52442da2bc0ea93fc2c19f4526044d78978', 'build/rebuild/application-wave10-cohort-observation-v1/independent-outcome-review.json': '8f093e34ada6f7c9e22900987ffbbfbf5182b5129b44e5ec838952a33443040f', 'build/rebuild/application-link-diagnostic-v9-wave-v2/receipt.json': 'b8c9ff1638cd57d5fb4d8d09f0bceb1931b93eeed00f1103e624b63fa831391f', 'build/rebuild/application-link-diagnostic-v9-wave-v2/link.rsp': '3bb4887d1cbb994e356984a6ee908df378074ae122cade7eb1c01845030db426', 'build/rebuild/application-link-diagnostic-v9-wave-v2/link-receipt.json.gz': '942a09a029c92f94e17ff78652f26c2c17318f42bf16e2c54320143089e79acc', 'build/rebuild/application-link-diagnostic-v9-wave-v2/independent-outcome-review.json': '13228b73f81177b3114b6090921a76575d13cc8c486c8d76be57813a8a3ecb80', 'build/rebuild/frontier-wave8-native-conformance-v1/receipt.json': 'cc1a7ac843c882d8a802db878ed7aa709108fa1fb781f93d38b0c5c6517d2043', 'build/rebuild/frontier-wave8-native-conformance-v1/independent-outcome-review.json': 'bee2b9b21515d72ddbd4b2d8e91d3ee4b8b926c013db7651074804a1ed24e647', 'build/rebuild/application-wave9-diagnostic-inputs-v1.json': 'ce407ed65118ae317a6edc95a7495fa8233337e7bf74080a72a48dc4776b147f'}
CRT_PATHS={'crt_plan': 'build/rebuild/application-crt-v10-four-contract-v1.json', 'crt_review': 'build/rebuild/application-crt-v10-four-contract-peer-v1.json', 'crt_response': 'build/rebuild/application-crt-v10-four-proposal-v1.rsp', 'crt_consumer': 'tools/rebuild/crt_v10_four_alias_contract.py', 'crt_consumer_tests': 'tests/rebuild/test_crt_v10_four_alias_contract.py', 'crt_producer': 'tools/rebuild/crt_v10_four_alias_plan.py', 'crt_producer_tests': 'tests/rebuild/test_crt_v10_four_alias_plan.py', 'crt_consumer_peer': 'build/rebuild/crt-v10-four-consumer-peer-v1.json'}

def prepare(repository,out,source_sha256,tests_sha256,input_path,input_sha256):
    repository=Path(repository).resolve();out=Path(out).absolute();input_path=Path(input_path).absolute()
    require(out.resolve()==out and out.parent==repository/'build/rebuild' and not out.exists(),'exclusive direct private output required')
    require(input_path.resolve()==input_path and input_path.parent==repository/'build/rebuild' and diagnostic.file_hash(input_path)==input_sha256,'exact reviewed input request required')
    bindings=[]
    def bind(path,expected):
        path=Path(path);require(diagnostic.file_hash(path)==expected,'bound source/input differs: '+str(path));bindings.append(diagnostic.identity(path));return path
    pins=foundation.source_pins(diagnostic.SOURCE_PINS,PINS)
    pins.update({'tools/rebuild/application_wave10_diagnostic.py':source_sha256,'tests/rebuild/test_application_wave10_diagnostic.py':tests_sha256})
    for name,sha in pins.items():bind(repository/name,sha)
    request=json.loads(bind(input_path,input_sha256).read_text())
    require(request.get('kind')=='fixed-wave10-diagnostic-CRT-inputs' and request.get('schema_version')==1 and set(request.get('inputs',{}))==set(CRT_PATHS),'fixed CRT request required')
    paths={}
    for key,relative in CRT_PATHS.items():
        row=request['inputs'][key];require(set(row)=={'path','sha256'} and row['path']==relative,'fixed CRT path required');paths[key]=bind(repository/relative,row['sha256'])
    old_out=repository/'build/rebuild/application-link-diagnostic-v9-wave-v2';report=json.loads((old_out/'receipt.json').read_text())
    diagnostic.stable(report['input_bindings']);bindings.extend(report['input_bindings'])
    obs=json.loads((repository/'build/rebuild/application-wave10-cohort-observation-v1/receipt.json').read_text())
    diagnostic.stable(obs['input_bindings']);bindings.extend(obs['input_bindings'])
    annotations=importlib.import_module('iat_code68_annotations');contract=importlib.import_module('crt_v10_four_alias_contract');producer=importlib.import_module('import_v8_four_successor')
    with gzip.open(repository/'build/rebuild/application-wave10-cohort-observation-v1/fields.json.gz','rt',encoding='utf-8') as stream:fields=json.load(stream)
    require(len(fields)==obs['complete_field_count']==45947 and obs['selected_Game_function_candidates']==14476 and obs['ordinary_prepared_count']==14471,'exact V10 source/field/provider census required')
    require(diagnostic.digest(diagnostic.canonical(sorted(fields,key=diagnostic.canonical)))==obs['fields_canonical_sha256'],'full V10 field digest differs')
    gate=contract.validate(paths['crt_plan'].read_bytes(),paths['crt_review'].read_bytes(),paths['crt_response'].read_bytes(),fields,obs['provider_namespace']['symbols'])
    require(gate['alias_field_count']==202 and len(gate['tokens'])<=4 and gate['inherited_tokens_to_remove']==report['CRT_diagnostic_bindings']['tokens'],'reviewed existing-four CRT scope differs')
    crt=json.loads(paths['crt_plan'].read_text())
    for name,sha in crt['inputs'].items():
        path=repository/'build/rebuild'/name;require(path.resolve().is_relative_to(repository/'build/rebuild'),'CRT metadata ancestry outside private directory');bind(path,sha)
    for name,sha in crt['sources'].items():bind(repository/name,sha)
    bind(repository/'build/units.json',crt['units_sha256']);require(isinstance(crt.get('own_sources'),dict) and len(crt['own_sources'])==2,'two own source identities required')
    for name,sha in crt['own_sources'].items():
        path=repository/name;require(path.resolve().is_relative_to(repository/'src'),'own source outside source tree');bind(path,sha)
    require(all(row['normal_provider']['archive_sha256']==report['default_libraries']['libcmt.lib']['sha256'] for row in crt['bindings']),'selected normal CRT library identity differs')
    code_native=json.loads((repository/'build/rebuild/frontier-wave8-native-conformance-v1/receipt.json').read_text())
    foundation.native_scope(code_native,'wave8-code68','frontier-wave8-native-conformance-v1','b1bbf2ec3c5f0040d5e88351e673499bd6c94a00e6c1e9a3c0c5bfb540323db3',68,629)
    previous_request=json.loads((repository/'build/rebuild/application-wave9-diagnostic-inputs-v1.json').read_text());imports={}
    for key,relative in predecessor.INPUT_PATHS.items():
        if key.startswith('crt_'):continue
        row=previous_request['inputs'][key];require(row['path']==relative,'unchanged import input path differs');imports[key]=bind(repository/relative,row['sha256'])
    native_request=json.loads(imports['import_request'].read_text());native_receipt=json.loads(imports['import_native'].read_text())
    ancestry={}
    for key,relative in predecessor.IMPORT_ANCESTRY.items():
        path=bind(repository/relative,producer.PINS[key])
        if key!='fields':ancestry[key]=json.loads(path.read_text())
    for relative,sha in ancestry['assessment']['inputs'].items():
        path=repository/relative;require(path.resolve().is_relative_to(repository),'import ancestry outside workspace');bind(path,sha)
    expected_sources=dict(producer.HELPER_PINS,**{'tools/rebuild/import_v8_four_successor.py':previous_request['inputs']['import_producer']['sha256']})
    for relative,sha in ancestry['assessment']['inputs'].items():
        if (repository/relative).is_relative_to(repository/'tools'):expected_sources[relative]=sha
    require(len(native_request['replacements'])==2 and {row['definition']['file'] for row in native_request['replacements']}=={'kernel32-twelve.def','user32-sixteen.def'},'exact existing two DEF inputs required')
    for row in native_request['replacements']:
        require(row['definition']['file'] in ('kernel32-twelve.def','user32-sixteen.def'),'fixed existing DEF required');bind(imports['import_request'].parent/row['definition']['file'],row['definition']['sha256'])
    parsed={imports[key].name:import_archive.read_archive(imports[key]) for key in ('kernel_library','user_library')}
    native=predecessor.native_import_evidence(native_receipt,native_request,previous_request['inputs']['import_request']['sha256'],parsed,producer,expected_sources)
    source_peer=json.loads(imports['import_request_peer'].read_text());native_peer=json.loads(imports['import_native_peer'].read_text())
    require(source_peer.get('kind')=='fnv-v8-four-import-successor-source-input-review' and type(source_peer.get('schema_version')) is int and source_peer['schema_version']==1 and source_peer.get('status')=='accepted_source_and_prepared_inputs_only' and
        source_peer.get('request_sha256')==previous_request['inputs']['import_request']['sha256'] and source_peer.get('source_sha256')==native_request['source_sha256'],'existing import source peer differs')
    require(native_peer.get('kind')=='fnv-v8-four-import-successor-independent-outcome-review' and type(native_peer.get('schema_version')) is int and native_peer['schema_version']==1 and native_peer.get('status')=='accepted_metadata_conformance_only' and
        native_peer.get('collection_sha256')==previous_request['inputs']['import_native']['sha256'] and native_peer.get('request_sha256')==previous_request['inputs']['import_request']['sha256'] and
        native_peer.get('libraries')==[{key:row[key] for key in ('file','sha256','bytes')} for row in native['libraries']],'existing native import peer differs')
    libraries={imports[key].name:diagnostic.partial.native_archive(imports[key].read_bytes()) for key in ('kernel_library','user_library')}
    for row in native['unchanged_libraries']:
        path=bind(repository/'build/rebuild/import-native-main-v2'/row['library'],row['sha256']);libraries[row['library']]=diagnostic.partial.native_archive(path.read_bytes())
    require(len(libraries)==4,'exact selected import library scope required')
    catalog=ancestry['catalog'];view=annotations.census_view(fields,catalog)
    aliases=joins.wave9_alias_census(native['proposed_pointer_aliases'],view,catalog,libraries)
    require(len(aliases)==31 and sum(row['proof'].get('role')=='iat-cell' for row in fields)==413,'existing31/fullIAT413 scope differs')
    for row in aliases:
        row['evaluation_view_sha256']=diagnostic.digest(diagnostic.canonical(row['complete_actual_uses']))
        uses=[field for field in fields if field['canonical']==row['canonical']]
        require(len(uses)==row['use_count'],'normative/evaluation per-cell count differs');row['complete_actual_uses']=uses;row['compact_proofs_preserved']=True
    prior_IAT=['/ALTERNATENAME:'+row['canonical']+'='+row['native_pointer'] for row in report['aliases'] if row['enabled']]
    require(set(prior_IAT)=={'/ALTERNATENAME:'+row['canonical']+'='+row['native_pointer'] for row in aliases},'existing native pointer token identities changed')
    new_IAT=['/ALTERNATENAME:'+row['canonical']+'='+row['native_pointer'] for row in aliases if row['enabled']]
    tokens=response_tokens((old_out/'link.rsp').read_text(),old_out,out,str(repository/'build/rebuild/frontier-wave-v8-production-v1/V8-code.lib'),prior_IAT,report['CRT_diagnostic_bindings']['tokens'],new_IAT,gate['tokens'])
    provenance={name:[row for row in group if not row.get('proof')] for name,group in report['provenance'].items()}
    for provider in obs['extra_providers']:provenance.setdefault(provider['canonical'],[]).append(provider)
    for field in fields:provenance.setdefault(field['canonical'],[]).append(field)
    mapped={row['canonical'] for row in aliases};unmapped={}
    for field in fields:
        if field['proof'].get('role')=='iat-cell' and field['canonical'] not in mapped:unmapped.setdefault(field['canonical'],[]).append(field)
    report.update(kind='fixed-wave10-CODE68-link-diagnostic',status='prepared-no-native-LINK',input_bindings=bindings,
        command=[report['command'][0],'@'+str(out/'link.rsp')],provenance=provenance,aliases=aliases,
        selected_supplementary_providers=report['selected_supplementary_providers']+obs['extra_providers'],selected_game_function_provider_count=14476,
        ordinary_prepared_count=14471,full_included_field_count=45947,CRT_diagnostic_bindings=gate,IAT_actual_fields=413,
        unmapped_IAT_cells=[dict(canonical=name,use_count=len(rows),original_bases=sorted({r['proof']['original_base'] for r in rows})) for name,rows in sorted(unmapped.items())],
        native_LINK_performed=False,executable_execution=False,runtime_eligible=False,provider_adopted=False,link_ready=False,whole_DATA_included=False,
        unreviewed_CRT_aliases=[],namespace_only=True,logical_CODE_address_only_aliases=[],IOTask_included=False,ModelLoader_included=True,
        additional_native_conformance_sha256=PINS['build/rebuild/frontier-wave8-native-conformance-v1/receipt.json'],
        observation_sha256=PINS['build/rebuild/application-wave10-cohort-observation-v1/receipt.json'],
        baseline_V9_actual_receipt_sha256=PINS['build/rebuild/application-link-diagnostic-v9-wave-v2/link-receipt.json.gz'],input_request_sha256=input_sha256)
    diagnostic.stable(bindings);out.mkdir();(out/'link.rsp').write_text(diagnostic.response_text(tokens),encoding='utf-8')
    report['response_sha256']=diagnostic.file_hash(out/'link.rsp')
    with (out/'receipt.json').open('x',encoding='utf-8') as stream:json.dump(report,stream,separators=(',',':'))
    diagnostic.stable(bindings);return report

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    for key in ('source-sha256','tests-sha256','inputs','inputs-sha256','out'):parser.add_argument('--'+key,required=True)
    args=parser.parse_args();report=prepare(ROOT,args.out,args.source_sha256,args.tests_sha256,args.inputs,args.inputs_sha256)
    print(json.dumps(dict(status=report['status'],eligible_IAT_cells=sum(row['enabled'] for row in report['aliases']),CRT_bindings=len(report['CRT_diagnostic_bindings']['tokens']),fields=45947,native_LINK_performed=False)))
if __name__=='__main__':main()
