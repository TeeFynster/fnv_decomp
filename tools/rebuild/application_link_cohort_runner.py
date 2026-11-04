"""Expanded diagnostic planner around frozen source/COFF integration helpers.

Default preparation is Python-only. --link-once delegates one separately
authorized native diagnostic; it never executes an output image. No new
provider is adopted and no blocked DATA bridge is an input.
"""
from __future__ import annotations
import argparse
import copy
import json
from pathlib import Path

import application_link_diagnostic as diagnostic
import application_link_cohort as cohort
import coff_code_archive as coff

require = diagnostic.require
digest = diagnostic.digest

OBSERVATION = ('application-cohort-observation-v1/receipt.json',
    '9848b08bfd51244412700d25cd9cc53136253e90117a4c3b67b03c347961586b')
V4_RECEIPT = ('application-link-diagnostic-v4/receipt.json',
    '08b3330fd12f626d776fa037e4444ba89daff02f5126f8265d439f5c1b7c22ba')
INTERLOCKED_CELL = '0x00fdf1c4'
ROOT = Path(__file__).resolve().parents[2]
SOURCE_PINS = dict(diagnostic.SOURCE_PINS, **{
    'tools/rebuild/application_link_diagnostic.py': '74cca67c3ec414931f4bfb26403338734f87da5eb28952e2327d008cbb79b379',
    'tools/rebuild/application_link_cohort.py': 'a5feab657f68e7e0e0243250128d477358311d36dc10c23c5d71c88e0959ee32',
    'tests/rebuild/test_application_link_cohort.py': 'fcd4e767dd60fb9ce25b699e8baa0d72c93ca89de978316091e4f39bb28ca300',
    'docs/rebuild/APPLICATION-LINK-COHORT.md': 'f783e86ff883d838f2a9647ade4b8e0758b5d6045929583398c0d0464552cdd6',
    'tests/rebuild/test_application_link_cohort_runner.py': '8bbba9135ca15a5556a18216332a4b8ba93702b73ecec47e1d0088594cc9019e',
    'docs/rebuild/APPLICATION-LINK-COHORT-RUNNER.md': '5216e734e9f7b7f72ab9abe328ae42f60b3598fafdd9addd7f7f9eef330382a5'})


def conformance_scope(receipt):
    required = {cohort.COMPONENT_PINS[key][1] for key in
        ['reference_archive', 'generic_archive', 'overlay_archive', 'EH_object', 'DATA_0', 'DATA_1']}
    rows = receipt.get('components', [])
    false_flags = ['compiler_performed', 'archive_generated', 'object_rewritten', 'executable_linked',
        'Game_execution', 'provider_selected', 'runtime_eligible', 'ABI_verified']
    require(type(receipt.get('schema_version')) is int and receipt['schema_version'] == 1 and
        receipt.get('kind') == 'application-supplement-native-conformance-v1' and
        receipt.get('status') == 'pass' and receipt.get('input_stability_verified') is True and
        all(receipt.get(flag) is False for flag in false_flags) and
        len(rows) == 6 and {row['input_sha256'] for row in rows} == required and
        all(row.get('native_metadata_matches') is True for row in rows),
        'native component conformance scope differs')
    return {row['input_sha256']: row for row in rows}


def kernel32_native_evidence(receipt, preparation, preparation_sha256, library_bytes):
    require(type(receipt.get('schema_version')) is int and receipt['schema_version'] == 1 and
        receipt.get('kind') == 'fnv-kernel32-import-extension-native-collection' and
        receipt.get('status') == 'collected-awaiting-independent-conformance', 'native import collection kind/status differs')
    require(type(preparation.get('schema_version')) is int and preparation['schema_version'] == 1 and
        preparation.get('kind') == 'fnv-kernel32-import-extension-request' and
        receipt.get('request_sha256') == preparation_sha256, 'native import request identity differs')
    source = preparation.get('source_sha256')
    require(isinstance(source, dict) and source and receipt.get('source_sha256') == source and
        all(isinstance(pin, str) and len(pin) == 64 and all(c in '0123456789abcdef' for c in pin) for pin in source.values()),
        'native import source identities differ')
    library = receipt.get('library', {})
    require(library.get('file') == 'kernel32-eight.lib' and library.get('sha256') == digest(library_bytes) and
        type(library.get('bytes')) is int and library['bytes'] == len(library_bytes), 'native import produced library differs')
    require(receipt.get('native_library_generated') is True and receipt.get('replacement_identity_verified') is True and
        receipt.get('old_seven_pointer_identities_preserved') is True and receipt.get('all_inputs_tools_sources_stable') is True,
        'native import generation/stability proof incomplete')
    false_flags = ['alias_applied', 'source_ABI_verified', 'runtime_provider_adopted', 'executable_link_performed',
        'compiler_performed', 'DLL_load_performed', 'imported_API_call_performed', 'runtime_eligible', 'provider_selected']
    require(all(receipt.get(flag) is False and preparation.get(flag) is False for flag in false_flags) and
        preparation.get('native_library_generated') is False and
        preparation.get('global_caller_census_verified') is False and receipt.get('global_caller_census_verified') is False,
        'native import unexpected promotion or operation')
    replacement = preparation.get('replacement', {})
    require(replacement == dict(old_library='provider-001.lib',
        old_library_sha256=diagnostic.partial.INPUTS['import_1'][1], new_library='kernel32-eight.lib',
        old_import_count=7, new_import_count=8), 'native import replacement scope differs')
    expected_inputs = dict(import_plan_sha256=diagnostic.PINS['imports'][1],
        previous_preparation_sha256=diagnostic.partial.INPUTS['import_preparation'][1],
        previous_native_collection_sha256=diagnostic.partial.INPUTS['import_receipt'][1])
    require(preparation.get('inputs') == expected_inputs, 'native import original evidence differs')
    require(receipt.get('inputs') == expected_inputs and receipt.get('replacement') == replacement,
        'native import collection ancestry differs')
    require(receipt.get('unchanged_libraries') == preparation.get('unchanged_libraries') and
        isinstance(preparation.get('unchanged_libraries'), list) and len(preparation['unchanged_libraries']) == 3,
        'native import unchanged-library contract differs')
    actual = diagnostic.partial.native_archive(library_bytes)
    parsed = receipt.get('parsed_archive', {})
    require(len(actual['imports']) == 8 and parsed.get('archive_sha256') == digest(library_bytes) and
        parsed.get('archive_bytes') == len(library_bytes) and parsed.get('member_count') == actual['member_count'] and
        parsed.get('imports') == actual['imports'] and
        diagnostic.partial.index_multiset(parsed.get('index')) == diagnostic.partial.index_multiset(actual['index']),
        'native import declared member/index facts differ from actual library')
    require(sorted((r['member_offset'], r['member_sha256']) for r in parsed.get('ordinary_members', [])) ==
        sorted((r['member_offset'], r['member_sha256']) for r in actual['support_members']),
        'native import descriptor member facts differ')
    return actual


def replacement_imports(manifest, catalog, replacement_bytes):
    """New eight-export library replaces, rather than accompanies, old seven."""
    old = manifest['native_import_libraries']
    previous = old['provider-001.lib']['imports']
    require(len(previous) == 7, 'exact prior seven KERNEL32 exports required')
    cell = [row for row in catalog['imports'] if row['original_IAT_va'] == INTERLOCKED_CELL]
    require(len(cell) == 1 and cell[0]['import_id'] == 102, 'exact additional original cell required')
    cell = cell[0]
    identity = diagnostic.import_identity(cell['dll'], cell['export'])
    require(identity == ('KERNEL32.dll', 'name', 'InterlockedDecrement'), 'additional cell identity differs')
    expected = {diagnostic.import_identity(row['dll'], row['export']) for row in previous}
    require(len(expected) == 7 and identity not in expected and
        all(key[0] == 'KERNEL32.dll' for key in expected), 'prior KERNEL32 identity set differs')
    native = diagnostic.partial.native_archive(replacement_bytes)
    lookup = {diagnostic.import_identity(row['dll'], row['export']): row for row in native['imports']}
    require(len(lookup) == len(native['imports']) == 8 and set(lookup) == expected | {identity},
        'replacement must contain exactly original seven plus one export')
    label = 'KERNEL32-eight-export'
    libraries = {name: copy.deepcopy(value) for name, value in old.items() if name != 'provider-001.lib'}
    libraries[label] = native
    proposals = []
    for original in manifest['import_pointer_proposals']:
        proposal = copy.deepcopy(original)
        if proposal['library'] == 'provider-001.lib':
            row = lookup[diagnostic.import_identity(proposal['dll'], proposal['export'])]
            require(row['pointer_symbol'] == proposal['proposed_pointer_symbol'], 'prior pointer identity changed')
            proposal.update(library=label, member_offset=row['member_offset'], proposed_pointer_symbol=row['pointer_symbol'])
        diagnostic.native_pointer_proof(proposal, libraries)
        proposals.append(proposal)
    row = lookup[identity]
    canonical = '_fnv_undefined_' + digest(diagnostic.canonical(dict(original_base=INTERLOCKED_CELL, role='iat-cell')))
    proposals.append(dict(canonical_IAT_symbol=canonical, original_IAT_va=INTERLOCKED_CELL,
        dll=identity[0], export=dict(kind='name', name=identity[2]), library=label,
        member_offset=row['member_offset'], proposed_pointer_symbol=row['pointer_symbol'],
        alias_applied=False, runtime_provider_adopted=False, source_ABI_approved=False,
        pointer_indirection_preserved=True))
    require(len(proposals) == len({row['canonical_IAT_symbol'] for row in proposals}) == 26,
        'exact 26 distinct candidate pointer cells required')
    return proposals, libraries


def expanded_alias_census(proposals, fields, catalog, libraries):
    """Scope extension of the frozen per-cell positive proof, without waivers."""
    require(len(proposals) == 26 and len({p['canonical_IAT_symbol'] for p in proposals}) == 26,
        'exact expanded 26-cell scope required')
    cells = {row['original_IAT_va']: row for row in catalog['imports']}
    require(len(cells) == len(catalog['imports']), 'duplicate original IAT catalog cell')
    result = []
    for proposal in proposals:
        name, va = proposal['canonical_IAT_symbol'], proposal['original_IAT_va']
        uses = [field for field in fields if field['canonical'] == name]
        blockers = []; positive = None; native = None; cell = cells.get(va)
        try:
            require(cell is not None, 'missing original cell')
            positive = diagnostic.import_identity(cell['dll'], cell['export'])
            require(positive == diagnostic.import_identity(proposal['dll'], proposal['export']), 'original import identity differs')
            native = diagnostic.native_pointer_proof(proposal, libraries)
        except ValueError as error:
            blockers.append('IMPORT_IDENTITY:' + str(error))
        expected = '_fnv_undefined_' + digest(diagnostic.canonical(dict(original_base=va, role='iat-cell')))
        if not (name == expected and proposal['pointer_indirection_preserved'] is True and
            proposal['alias_applied'] is False and proposal['runtime_provider_adopted'] is False and
            proposal['source_ABI_approved'] is False):
            blockers.append('POINTER_CELL_POLICY_CONFLICT')
        if not uses:
            blockers.append('NO_INCLUDED_USE')
        for use in uses:
            proof = use['proof']
            if not (use['undefined'] and use['kind'] == 6 and proof.get('role') == 'iat-cell' and
                proof.get('original_base') == proof.get('original_target') == va and proof.get('addend_bits') == 0 and
                proof.get('classification') == 'IAT_POINTER_CELL_NOT_FUNCTION_BODY' and cell is not None and
                (use['component'] == 'actual-entry' or proof.get('import_id') == cell['import_id'])):
                blockers.append('UNPROVED_USE:' + use['component'] + ':' + use['member'] + ':' + str(use['offset']))
        result.append(dict(canonical=name, native_pointer=proposal['proposed_pointer_symbol'],
            library=proposal['library'], original_IAT_va=va, positive_import_identity=positive,
            catalog_export_observation=cell['export'] if cell else None,
            documented_catalog_hint=cell['export'].get('hint') if cell else None,
            native_pointer_proof=native, complete_actual_uses=uses, use_count=len(uses),
            enabled=not blockers, blockers=blockers, scope='expanded diagnostic LINK identity only',
            ABI_approved=False, provider_adopted=False))
    return result


def selected_observation(observation):
    require(observation['status'] == 'metadata-observed-native-conformance-pending' and
        observation['total_game_function_providers'] == 14330 and observation['complete_field_count'] == 44364,
        'accepted observation count/scope differs')
    require(not observation['EH_logical_demand_uses'] and observation['EH_logical_binding_applied'] is False,
        'EH candidate scope requires separate binding review')
    providers = [row for row in observation['supplementary_providers'] if row['component'] != 'IOTask-EH']
    fields = [row for row in observation['supplementary_fields'] if row['component'] != 'IOTask-EH']
    require(len(providers) == 1382 and len(fields) == 7071, 'selected supplement count differs')
    return providers, fields, dict(component='IOTask-EH', selected=False,
        reason='No included logical demand; physical export remains a reviewed candidate, without forced EH helper retention.')


def response_arguments(old_response, replacements, additions, out, aliases):
    lines = old_response.splitlines()
    require(lines and all(line.startswith('"') and line.endswith('"') and len(line) > 2 for line in lines),
        'unexpected saved response syntax')
    args = [line[1:-1] for line in lines]
    args = [arg for arg in args if not arg.upper().startswith('/ALTERNATENAME:')]
    for prefix, filename in [('/OUT:', 'diagnostic.exe'), ('/MAP:', 'diagnostic.map')]:
        hits = [index for index, arg in enumerate(args) if arg.upper().startswith(prefix)]
        require(len(hits) == 1, 'saved output option count differs')
        args[hits[0]] = prefix + str(Path(out) / filename)
    for old, new in replacements.items():
        require(args.count(old) == 1, 'selected predecessor input missing/duplicated')
        args[args.index(old)] = new
    require(len(additions) == len(set(additions)) and not (set(additions) & set(args)), 'duplicate added link input')
    args += additions
    args += ['/ALTERNATENAME:' + row['canonical'] + '=' + row['native_pointer'] for row in aliases if row['enabled']]
    diagnostic.response_text(args)
    return args


def bound_relative_input(repository, record):
    require(set(record) == {'path', 'sha256'} and isinstance(record['path'], str), 'invalid scoped input record')
    supplied = Path(record['path'])
    require(not supplied.is_absolute(), 'component input must use scoped relative path')
    path = (repository / supplied).resolve(strict=True)
    require(path.is_relative_to(repository / 'build/rebuild') and diagnostic.file_hash(path) == record['sha256'],
        'scoped input identity differs')
    return path, diagnostic.identity(repository / supplied)


def prepare(repository, out, source_sha256, request_path, request_sha256):
    repository, out, request_path = Path(repository).resolve(), Path(out).resolve(), Path(request_path).resolve()
    require(not out.exists() and (not out.is_relative_to(repository) or out.is_relative_to(repository / 'build/rebuild')),
        'new private cohort output required')
    source_pins = dict(SOURCE_PINS, **{'tools/rebuild/application_link_cohort_runner.py': source_sha256})
    require(all(diagnostic.file_hash(repository / name) == pin for name, pin in source_pins.items()),
        'reviewed cohort source/dependency differs')
    bindings = [diagnostic.identity(repository / name) for name in source_pins]
    require(diagnostic.file_hash(request_path) == request_sha256, 'input request hash differs')
    bindings.append(diagnostic.identity(request_path))
    request = json.loads(request_path.read_text())
    require(set(request) == {'schema_version', 'native_conformance', 'kernel32_library', 'kernel32_receipt', 'kernel32_preparation'} and
        type(request['schema_version']) is int and request['schema_version'] == 1, 'input request scope differs')
    supplied = {}
    for key in ['native_conformance', 'kernel32_library', 'kernel32_receipt', 'kernel32_preparation']:
        path, binding = bound_relative_input(repository, request[key]); supplied[key] = path; bindings.append(binding)
    conformance = json.loads(supplied['native_conformance'].read_text())
    conformance_scope(conformance)
    kernel_receipt = json.loads(supplied['kernel32_receipt'].read_text())
    kernel_preparation = json.loads(supplied['kernel32_preparation'].read_text())
    kernel32_native_evidence(kernel_receipt, kernel_preparation, request['kernel32_preparation']['sha256'],
        supplied['kernel32_library'].read_bytes())
    for relative, pin in kernel_preparation['source_sha256'].items():
        path = (repository / relative).resolve(strict=True)
        require(not Path(relative).is_absolute() and path.is_relative_to(repository / 'tools') and
            diagnostic.file_hash(path) == pin, 'native import generator source differs')
        bindings.append(diagnostic.identity(repository / relative))
    observation_path = repository / 'build/rebuild' / OBSERVATION[0]
    baseline_path = repository / 'build/rebuild' / V4_RECEIPT[0]
    require(diagnostic.file_hash(observation_path) == OBSERVATION[1] and
        diagnostic.file_hash(baseline_path) == V4_RECEIPT[1], 'accepted observation/baseline differs')
    bindings += [diagnostic.identity(observation_path), diagnostic.identity(baseline_path)]
    observation = json.loads(observation_path.read_text()); old = json.loads(baseline_path.read_text())
    diagnostic.stable(observation['input_bindings']); diagnostic.stable(old['input_bindings'])
    bindings += observation['input_bindings'] + old['input_bindings']
    providers, supplement_fields, excluded_EH = selected_observation(observation)
    fields = [row for observations in old['provenance'].values() for row in observations if 'canonical' in row and 'proof' in row]
    require(len(fields) == 37282, 'baseline actual field count differs')
    fields += supplement_fields
    require(len(fields) == 44353, 'selected complete field census differs')
    partial_dir = repository / 'build/rebuild/application-link-inputs-v2'
    manifest_path = partial_dir / 'manifest.json'
    require(diagnostic.file_hash(manifest_path) == diagnostic.PINS['partial'][1], 'partial input manifest differs')
    bindings.append(diagnostic.identity(manifest_path))
    manifest = json.loads(manifest_path.read_text())
    catalog_path = repository / 'build/rebuild' / diagnostic.PINS['imports'][0]
    require(diagnostic.file_hash(catalog_path) == diagnostic.PINS['imports'][1], 'original IAT catalog differs')
    bindings.append(diagnostic.identity(catalog_path)); catalog = json.loads(catalog_path.read_text())
    proposals, libraries = replacement_imports(manifest, catalog, supplied['kernel32_library'].read_bytes())
    aliases = expanded_alias_census(proposals, fields, catalog, libraries)
    provenance = copy.deepcopy(old['provenance'])
    for provider in providers:
        require(provider['canonical'] not in provenance or not any(
            not row.get('proof') for row in provenance[provider['canonical']]), 'duplicate selected provider at integration')
        provenance.setdefault(provider['canonical'], []).append(dict(provider, component=provider['component'] + '-definition'))
    for field in supplement_fields:
        provenance.setdefault(field['canonical'], []).append(field)
    old_response_path = baseline_path.parent / 'link.rsp'
    require(diagnostic.file_hash(old_response_path) == old['response_sha256'], 'saved baseline response differs')
    bindings.append(diagnostic.identity(old_response_path))
    component_path = lambda key: repository / 'build/rebuild' / cohort.COMPONENT_PINS[key][0]
    replacements = {str(partial_dir / 'data-0.obj'): str(component_path('DATA_0')),
        str(partial_dir / 'data-1.obj'): str(component_path('DATA_1')),
        str(partial_dir / 'provider-001.lib'): str(supplied['kernel32_library'])}
    additions = [str(component_path(key)) for key in ['reference_archive', 'generic_archive', 'overlay_archive']]
    args = response_arguments(old_response_path.read_text(), replacements, additions, out, aliases)
    diagnostic.stable(bindings)
    out.mkdir(parents=True)
    (out / 'link.rsp').write_text(diagnostic.response_text(args), encoding='ascii')
    report = dict(schema_version=1, kind='expanded-source-cohort-link-diagnostic', status='prepared-no-native-LINK',
        input_bindings=bindings, input_request_sha256=request_sha256,
        observation_sha256=OBSERVATION[1], baseline_v4_receipt_sha256=V4_RECEIPT[1],
        native_conformance_sha256=request['native_conformance']['sha256'],
        kernel32_native_receipt_sha256=request['kernel32_receipt']['sha256'],
        kernel32_preparation_sha256=request['kernel32_preparation']['sha256'],
        selected_supplementary_providers=providers, deferred_components=[excluded_EH],
        selected_game_function_provider_count=14329, full_included_field_count=len(fields),
        IAT_actual_fields=sum(row['proof']['role'] == 'iat-cell' for row in fields),
        aliases=aliases, provenance=provenance, original_binding_reference_groups=old['original_binding_reference_groups'],
        default_libraries=old['default_libraries'], compiler_root=old['compiler_root'], sdk_root=old['sdk_root'],
        command=[old['command'][0], '@' + str(out / 'link.rsp')], response_sha256=diagnostic.file_hash(out / 'link.rsp'),
        local_native_dependency_candidates=old['local_native_dependency_candidates'],
        native_LINK_performed=False, executable_execution=False, provider_adopted=False,
        runtime_eligible=False, link_ready=False, whole_DATA_included=False, unreviewed_CRT_aliases=[],
        DATA_section_name_successors=True, old_v4_warning_not_suppressed=True,
        native_descriptor_selection_claimed=False, transitive_or_loaded_DLL_closure_verified=False)
    diagnostic.stable(bindings)
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source-sha256', required=True)
    parser.add_argument('--inputs', type=Path, required=True)
    parser.add_argument('--inputs-sha256', required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--link-once', action='store_true')
    args = parser.parse_args()
    report = prepare(ROOT, args.out, args.source_sha256, args.inputs, args.inputs_sha256)
    try:
        if args.link_once: diagnostic.link_once(report, args.out)
        diagnostic.stable(report['input_bindings'])
    except Exception as error:
        report['status'] = 'error-requires-reconciliation'; report['error'] = type(error).__name__ + ': ' + str(error)
    with (args.out / 'receipt.json').open('x') as stream: json.dump(report, stream, separators=(',', ':'))
    print(json.dumps(dict(status=report['status'], native_LINK_performed=report['native_LINK_performed'],
        eligible_IAT_cells=sum(row['enabled'] for row in report['aliases']),
        executable_execution=False, runtime_eligible=False)))


if __name__ == '__main__': main()
