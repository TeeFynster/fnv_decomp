"""Prepare the fixed broader diagnostic cohort; no native tool invocation."""
import argparse
import gzip
import importlib
import json
from pathlib import Path

import application_link_diagnostic as diagnostic
import application_frontier_inputs as joins
import normal_import_archive as import_archive
import iat_field_annotations as iat_annotations

ROOT = Path(__file__).resolve().parents[2]
PINS = {
 'docs/rebuild/APPLICATION-WAVE8-DIAGNOSTIC.md':'4263e6e30d1a50f565751bfe522a1d1d1c580ce0e76ec19bd41c562da7707dd7',
 'docs/rebuild/APPLICATION-FRONTIER-DIAGNOSTIC.md':'84947d0d852d0f8098c7bf67c9cbabc3b30b488e90d4082e4150b4291fb387a4',
 'tools/rebuild/application_frontier_inputs.py':'2f47fc9ec0893b1be1168c328f4418be8df340a6aec4c39354bf4fce32406cd2',
 'tests/rebuild/test_application_frontier_inputs.py':'fccd1ae08d51fb0969922552aa8d92afbe0dd872d305e0bfa1d4f321932f6514',
 'tools/rebuild/import_kernel32_nine.py':'696903fd3d5affaf0158da5ccbed7278f05a3b1f3da775c331b72eab22cd3864',
 'tools/rebuild/normal_import_archive.py':'42a0eff5852d89aaadb1f239baf3884e7a2dcd4216870407d7e8510a6d68bf28',
 'tools/rebuild/application_link_diagnostic.py':'74cca67c3ec414931f4bfb26403338734f87da5eb28952e2327d008cbb79b379',
 'tools/rebuild/iat_field_annotations.py':'5ce0b3ae5069cde206b334bddc94515b308e611ef1cc269783cbd386fd778ae6',
 'tests/rebuild/test_iat_field_annotations.py':'fb8efec99e6e72761e7969997ba3665896c4afcfdea8dbb4e1a205c831da091b',
 'build/rebuild/application-wave8-cohort-observation-v1/receipt.json':'7939cdc2912317a9cb1bca0027feba50fa511111fe842308c8f7d8805af28741',
 'build/rebuild/application-wave8-cohort-observation-v1/independent-outcome-review.json':'09ae566d99b1bbf58273ce4d3d5252d49411df80cddd30191615de27bef4bbdb',
 'build/rebuild/application-wave8-cohort-observation-v1/fields.json.gz':'2e5cb28f81cf5042c31ae80f7db49ef003df693cf428fb678d7f116a907425bf',
 'build/rebuild/application-link-diagnostic-v7-frontier/receipt.json':'0dd1b0791b4717b8c3d827f5e17af863200da659eca275f6d3290093f682fdfa',
 'build/rebuild/application-link-diagnostic-v7-frontier/link.rsp':'43e80956de8840eabc1c5c928e11d5dee2aea8f48d4b0ceb15d6f486fc2efc4d',
 'build/rebuild/application-link-diagnostic-v7-frontier/link-receipt.json':'05fab245e57474faaecdba76c94b2ed7da3228f5229d2509800360252c6a218f',
 'build/rebuild/application-link-diagnostic-v7-frontier/independent-outcome-review.json':'578dded065c35f922c55a62299594847ade4f91e371a2a56f1f965ad1e79cf64',
 'build/rebuild/frontier-code59-native-conformance-v1/receipt.json':'8c70779205139a05732092274e67b1643eacfbd6713dcf51387800557d8c2c6f',
 'build/rebuild/frontier-code59-native-conformance-v1/independent-outcome-review.json':'bdaddb0f27949b60a7820c2d402ff0081a5c8ea2bdf48d1808835c07dcea76f0',
 'build/rebuild/model-loader-native-conformance-v1/receipt.json':'d84b5d5b2dd8b22713b28a2d12341b181f84bfc0bdd3892b10ea45779b32dfa5',
 'build/rebuild/model-loader-native-conformance-v1/independent-outcome-review.json':'ad81b07634c82dce89e77cc02158efe5aa3bac74ecd4bd484809ce7ad76f1710',
 'build/rebuild/import-kernel32-nine-v1/preparation.json':'92a5dc7185a95e1afac5856fba651322e48086ef20df11beca0e68afbf09d176',
 'build/rebuild/import-kernel32-nine-native-v1/collection.json':'a80e16739a2393a068d0da8ed5d9e4a1d165ccbfc5495e9e41830add98d35e0b',
 'build/rebuild/import-kernel32-nine-native-v1/kernel32-nine.lib':'fe222155feda5664e45f41014ecc9f5e08b91f436b7f2114293b72d457a7043e',
 'build/rebuild/import-kernel32-nine-native-v1/independent-outcome-review.json':'59f5cda6743dcffaa643a95e0d04b03cdf28fa771cfa75ccc526d8b65050e605',
}
CRT_PATHS = {
 'crt_plan':'build/rebuild/application-crt-v8-four-contract-v1.json',
 'crt_review':'build/rebuild/application-crt-v8-four-contract-peer-v1.json',
 'crt_response':'build/rebuild/application-crt-v8-four-proposal-v1.rsp',
 'crt_consumer':'tools/rebuild/crt_v8_four_alias_contract.py',
 'crt_consumer_tests':'tests/rebuild/test_crt_v8_four_alias_contract.py',
 'crt_producer':'tools/rebuild/crt_v8_four_alias_plan.py',
 'crt_producer_tests':'tests/rebuild/test_crt_v8_four_alias_plan.py',
 'crt_consumer_peer':'build/rebuild/crt-v8-four-consumer-peer-v1.json',
}

def require(ok, message):
    if not ok: raise ValueError(message)

def source_pins(*groups):
    result={}
    for group in groups:
        for name,sha in group.items():
            require(name not in result or result[name]==sha,'conflicting reviewed source pin: '+name)
            result[name]=sha
    return result

def native_scope(receipt,label,kind,sha,members,relocations):
    require(type(receipt.get('schema_version')) is int and receipt['schema_version']==1 and receipt.get('kind')==kind and
        receipt.get('status')=='pass' and receipt.get('input_stability_verified') is True and
        all(receipt.get(flag) is False for flag in joins.FALSE_OPERATIONS),'native wave8 conformance state differs')
    rows=receipt.get('components',[])
    require(len(rows)==1 and rows[0].get('label')==label and rows[0].get('input_sha256')==sha and
        rows[0].get('native_metadata_matches') is True,'exact native wave8 input required')
    row=rows[0];facts=row.get('facts',{})
    if members:
        objects=facts.get('objects',[])
        require(row.get('kind')=='archive' and facts.get('complete_native_linker_index') is True and
            facts.get('members')==facts.get('exports')==len(objects)==members and
            all(obj.get('all_native_metadata_matches') is True for obj in objects) and
            sum(obj.get('relocations',-1) for obj in objects)==relocations,'native CODE59 metadata/counts differ')
    else:
        require(row.get('kind')=='object' and facts.get('all_native_metadata_matches') is True and
            facts.get('sections')==5 and facts.get('primary_records')==40 and facts.get('auxiliary_records')==5 and
            facts.get('relocations')==relocations,'native ModelLoader metadata/counts differ')
    return row

def wave8_alias_census(proposals,fields,catalog,libraries):
    view=iat_annotations.census_view(fields,catalog)
    result=joins.frontier_alias_census(proposals,view,catalog,libraries)
    for row in result:
        # Keep published normative rows in the receipt. The temporary evaluation
        # view restores only tags authenticated by the full original proof.
        row['evaluation_view_sha256']=diagnostic.digest(diagnostic.canonical(row['complete_actual_uses']))
        uses=[field for field in fields if field['canonical']==row['canonical']]
        require(len(uses)==row['use_count'],'normative/evaluation IAT census differs')
        row['complete_actual_uses']=uses
        row['compact_proofs_preserved']=True
    return result

def response_tokens(text, old_out, out, additions, prior_IAT, prior_CRT, new_IAT, new_CRT):
    lines=text.splitlines()
    require(all(len(line)>2 and line.startswith('"') and line.endswith('"') for line in lines),'malformed baseline response')
    tokens=[line[1:-1] for line in lines]
    for old,new in [('/OUT:'+str(old_out/'diagnostic.exe'),'/OUT:'+str(out/'diagnostic.exe')),
                    ('/MAP:'+str(old_out/'diagnostic.map'),'/MAP:'+str(out/'diagnostic.map'))]:
        require(tokens.count(old)==1,'one exact baseline library/output token required')
        tokens[tokens.index(old)]=new
    require(len(prior_IAT)==27 and len(prior_CRT)==4 and set(new_IAT).issubset(prior_IAT) and
        len(new_CRT)<=4 and set(new_CRT).issubset(prior_CRT),'only existing IAT/CRT enabled subsets permitted')
    removed=prior_IAT+prior_CRT
    require(len(set(removed))==31 and all(tokens.count(token)==1 for token in removed),'previous alias response differs')
    tokens=[token for token in tokens if token not in removed]
    require(not any(token.startswith('/ALTERNATENAME:') for token in tokens),'unreviewed baseline alias')
    require(len(additions)==2 and len(set(additions))==2 and not set(additions).intersection(tokens),'additional component duplicate')
    aliases=new_IAT+new_CRT
    require(len({token.split('=',1)[0] for token in aliases})==len(aliases) and all(token.startswith('/ALTERNATENAME:') and '=' in token for token in aliases),'duplicate/conflicting successor alias')
    tokens += additions + aliases
    diagnostic.response_text(tokens)
    return tokens

def prepare(repository,out,source_sha256,tests_sha256,input_path,input_sha256):
    repository=Path(repository).resolve();out=Path(out).absolute();input_path=Path(input_path).absolute()
    require(out.resolve()==out and out.parent==repository/'build/rebuild' and not out.exists(),'exclusive direct private output required')
    require(input_path.resolve()==input_path and input_path.parent==repository/'build/rebuild' and diagnostic.file_hash(input_path)==input_sha256,'exact private input request required')
    bindings=[]
    def bind(path,expected):
        path=Path(path)
        require(diagnostic.file_hash(path)==expected,'bound source/input differs: '+str(path))
        bindings.append(diagnostic.identity(path));return path
    pins=source_pins(diagnostic.SOURCE_PINS,PINS,joins.nine.HELPER_PINS)
    pins.update({'tools/rebuild/application_wave8_diagnostic.py':source_sha256,'tests/rebuild/test_application_wave8_diagnostic.py':tests_sha256})
    for name,sha in pins.items():bind(repository/name,sha)
    bind(input_path,input_sha256);request=json.loads(input_path.read_text())
    require(request.get('kind')=='fixed-wave8-diagnostic-CRT-inputs' and request.get('schema_version')==1 and set(request.get('inputs',{}))==set(CRT_PATHS),'fixed reviewed CRT input request required')
    paths={}
    for key,relative in CRT_PATHS.items():
        row=request['inputs'][key]
        require(set(row)=={'path','sha256'} and row['path']==relative,'fixed CRT input path required')
        paths[key]=bind(repository/relative,row['sha256'])
    # Both newly imported CRT modules are bound before import, including the
    # producer imported by its pure consumer. They never invoke native tools.
    contract=importlib.import_module('crt_v8_four_alias_contract')
    obs=json.loads((repository/'build/rebuild/application-wave8-cohort-observation-v1/receipt.json').read_text())
    diagnostic.stable(obs['input_bindings']);bindings.extend(obs['input_bindings'])
    with gzip.open(repository/'build/rebuild/application-wave8-cohort-observation-v1/fields.json.gz','rt') as stream:fields=json.load(stream)
    require(len(fields)==obs['complete_field_count']==45315 and obs['selected_Game_function_candidates']==14405 and obs['ordinary_prepared_count']==14400,'exact broader field/provider census required')
    require(diagnostic.digest(diagnostic.canonical(sorted(fields,key=diagnostic.canonical)))==obs['fields_canonical_sha256'],'full field fingerprint differs')
    gate=contract.validate(paths['crt_plan'].read_bytes(),paths['crt_review'].read_bytes(),paths['crt_response'].read_bytes(),fields,obs['provider_namespace']['symbols'])
    require(len(gate['tokens'])<=4 and gate['alias_field_count']==202,'reviewed broader CRT alias scope required')
    crt_plan=json.loads(paths['crt_plan'].read_text())
    for name,sha in crt_plan['inputs'].items():
        path=repository/'build/rebuild'/name
        require(path.resolve().is_relative_to(repository/'build/rebuild'),'CRT ancestry outside exact private metadata')
        bind(path,sha)
    for name,sha in crt_plan['sources'].items():bind(repository/name,sha)
    bind(repository/'build/units.json',crt_plan['units_sha256'])
    require(isinstance(crt_plan.get('own_sources'),dict) and len(crt_plan['own_sources'])==2,'both new own-source identities required')
    for name,sha in crt_plan['own_sources'].items():
        path=repository/name;require(path.resolve().is_relative_to(repository/'src'),'own source outside authored source tree');bind(path,sha)
    conformance=json.loads((repository/'build/rebuild/frontier-code59-native-conformance-v1/receipt.json').read_text())
    native_scope(conformance,'code59','frontier-code59-native-conformance-v1','48c1bd32c18ac802aac6cd6781912b73205a43b9c4115d1df538ca0b5af77ebd',59,723)
    model_native=json.loads((repository/'build/rebuild/model-loader-native-conformance-v1/receipt.json').read_text())
    native_scope(model_native,'model-loader','model-loader-native-conformance-v1','c7ee32f03ebc9acb559b6516f526ca515733564035259e15271f6f3b1029afc9',0,52)
    nine_request=json.loads((repository/'build/rebuild/import-kernel32-nine-v1/preparation.json').read_text())
    nine_receipt=json.loads((repository/'build/rebuild/import-kernel32-nine-native-v1/collection.json').read_text())
    library=repository/'build/rebuild/import-kernel32-nine-native-v1/kernel32-nine.lib'
    parsed=import_archive.read_archive(library)
    native=joins.native_nine_evidence(nine_receipt,nine_request,PINS['build/rebuild/import-kernel32-nine-v1/preparation.json'],parsed)
    catalog=json.loads((repository/'build/rebuild'/diagnostic.PINS['imports'][0]).read_text())
    require(diagnostic.file_hash(repository/'build/rebuild'/diagnostic.PINS['imports'][0])==diagnostic.PINS['imports'][1],'original import catalog differs')
    bind(repository/'build/rebuild'/diagnostic.PINS['imports'][0],diagnostic.PINS['imports'][1])
    native_libraries={'kernel32-nine.lib':diagnostic.partial.native_archive(library.read_bytes())}
    for row in native['unchanged_libraries']:
        path=repository/'build/rebuild/import-native-main-v2'/row['library'];bind(path,row['sha256'])
        native_libraries[row['library']]=diagnostic.partial.native_archive(path.read_bytes())
    aliases=wave8_alias_census(native['proposed_pointer_aliases'],fields,catalog,native_libraries)
    require(len(aliases)==27 and sum(row['proof'].get('role')=='iat-cell' for row in fields)==409,'complete IAT candidate/cohort scope differs')
    old_out=repository/'build/rebuild/application-link-diagnostic-v7-frontier';report=json.loads((old_out/'receipt.json').read_text())
    diagnostic.stable(report['input_bindings']);bindings.extend(report['input_bindings'])
    require(gate['inherited_tokens_to_remove']==report['CRT_diagnostic_bindings']['tokens'],'CRT inherited-token removal scope differs')
    require(all(binding['normal_provider']['archive_sha256']==report['default_libraries']['libcmt.lib']['sha256']
        for binding in crt_plan['bindings']),'broader CRT provider differs from selected normal LIBCMT')
    prior_IAT=['/ALTERNATENAME:'+row['canonical']+'='+row['native_pointer'] for row in report['aliases'] if row['enabled']]
    new_IAT=['/ALTERNATENAME:'+row['canonical']+'='+row['native_pointer'] for row in aliases if row['enabled']]
    added=[repository/'build/rebuild/frontier-code-production-v5-v1/frontier-code.lib',repository/'build/rebuild/parent-eh-model-loader-projection-v1/component.obj']
    tokens=response_tokens((old_out/'link.rsp').read_text(),old_out,out,list(map(str,added)),prior_IAT,report['CRT_diagnostic_bindings']['tokens'],new_IAT,gate['tokens'])
    provenance={name:[row for row in group if not row.get('proof')] for name,group in report['provenance'].items()}
    for provider in obs['extra_providers']:provenance.setdefault(provider['canonical'],[]).append(provider)
    for field in fields:provenance.setdefault(field['canonical'],[]).append(field)
    report.update(kind='fixed-wave8-CODE59-ModelLoader-link-diagnostic',status='prepared-no-native-LINK',input_bindings=bindings,
        command=[report['command'][0],'@'+str(out/'link.rsp')],provenance=provenance,aliases=aliases,
        selected_supplementary_providers=report['selected_supplementary_providers']+obs['extra_providers'],
        selected_game_function_provider_count=14405,ordinary_prepared_count=14400,full_included_field_count=45315,
        CRT_diagnostic_bindings=gate,native_LINK_performed=False,executable_execution=False,runtime_eligible=False,
        provider_adopted=False,link_ready=False,whole_DATA_included=False,unreviewed_CRT_aliases=[],
        namespace_only=True,logical_CODE_address_only_aliases=[],IOTask_included=False,ModelLoader_included=True,IAT_actual_fields=409,
        additional_native_conformance_sha256=PINS['build/rebuild/frontier-code59-native-conformance-v1/receipt.json'],
        kernel32_native_receipt_sha256=PINS['build/rebuild/import-kernel32-nine-native-v1/collection.json'],
        kernel32_preparation_sha256=PINS['build/rebuild/import-kernel32-nine-v1/preparation.json'],
        observation_sha256=PINS['build/rebuild/application-wave8-cohort-observation-v1/receipt.json'],
        baseline_V7_actual_receipt_sha256=PINS['build/rebuild/application-link-diagnostic-v7-frontier/link-receipt.json'],
        input_request_sha256=input_sha256,
        deferred_components=[dict(component='IOTask-EH',selected=False,reason='outside fixed cohort')])
    diagnostic.stable(bindings);out.mkdir();(out/'link.rsp').write_text(diagnostic.response_text(tokens),encoding='utf-8')
    report['response_sha256']=diagnostic.file_hash(out/'link.rsp')
    with (out/'receipt.json').open('x') as stream:json.dump(report,stream,separators=(',',':'))
    diagnostic.stable(bindings);return report

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('source-sha256','tests-sha256','inputs','inputs-sha256','out'):parser.add_argument('--'+name,required=True)
    args=parser.parse_args();r=prepare(ROOT,args.out,args.source_sha256,args.tests_sha256,args.inputs,args.inputs_sha256)
    print(json.dumps(dict(status=r['status'],native_LINK_performed=False,eligible_IAT_cells=sum(row['enabled'] for row in r['aliases']),CRT_bindings=len(r['CRT_diagnostic_bindings']['tokens']),fields=45315)))

if __name__=='__main__':main()
