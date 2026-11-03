"""Prepare one normal x86 GUI LINK diagnostic; never execute its output.

Default operation is Python-only preparation. --link-once is the separately
root-authorized native operation. Unresolved errors are evidence, not waivers.
"""
from __future__ import annotations
import argparse
from collections import Counter, defaultdict
import gzip
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import time

import application_link_inputs as partial
import coff_code_archive as coff
import toolchain

ROOT = Path(__file__).resolve().parents[2]
V3_RECEIPT = ('application-link-diagnostic-v3/receipt.json',
              '909e3a591ce812c0303a6aff4e47493e582a504dc2760df12b98ce7250f714dc')
PINS = {
    'partial': ('application-link-inputs-v2/manifest.json', 'e90657a950019c000a930f9b152ab8275ac08cd6ae955642cb21252079299fc5'),
    'code': ('bulk-code-pool-all-current-v1/production/code-pool-0000.lib', '1d5d9ae7ba169f2389a3e9928a46fcbeb8f25b829bcdaee627db3f43e9d89aa5'),
    'unions': ('bulk-code-pool-all-current-v1/production/unions.jsonl.gz', 'fd3b319cf25bea35c6523ebd7a734441804670943200547724d1d87c8a6a1b64'),
    'code_native': ('bulk-code-pool-all-current-native-v1/receipt.json', 'b78ab291de0298b0bfb53ce03f1f440eadad7822e256abc11a5b3bb9c1c55978'),
    'entry': ('application-entry-projection-v1/receipt.json', 'b46ffd72903c4363f545884d3dbb5cbb3bcf355d1ef8e84171c8fae1861eeb6b'),
    'imports': ('import-plan-native-v3.json', 'e39b8db63ef73aea57b5dd4963ff29310524644ca36e137cd8b5461a3c90a23f'),
    'doctor': ('doctor-all.json', '9b24d10209fe0361a5e6b16b11a072e8e0ebc6505cd4b5e1bd782fe23854f29f'),
    'dependency_evidence': ('application-link-diagnostic-v2/failure-reconciliation.json', '811201bfd40619eba92ba1def2332549bbcba2e2075bf0a87fa6ed1608f42dd7'),
}
SOURCE_PINS = {
    'tools/rebuild/application_link_inputs.py': 'e1669081b88f43144f71c3a48f9bd2ff159f9be33a2c16052c6fbd850cfafd8f',
    'tools/rebuild/coff_code_archive.py': '76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64',
    'tools/rebuild/coff_inventory.py': '3518c044738046e7cd9c8be37a3b1077af750fb2e7a19db793b09999a07ee0d2',
    'tools/rebuild/game_startup_host.py': 'ef32b867ea948c96f416d94dc26d0fef2010f0323cfa65560a0cad77c0998867',
    'tools/rebuild/toolchain.py': '9cb837b0a11d9e5fa8db98dbf195b3d54b1cfeebed7d7531f97a0e29d03436fd',
    'tests/rebuild/test_application_link_diagnostic.py': 'da503119ede83b7fba00e1a9c7b5aa3840e52dd4bf6939885d96404b5b649b2b',
    'docs/rebuild/APPLICATION-LINK-DIAGNOSTIC.md': '92e2bb6c263a64b16d7048a0e1baac220c132fd35e435adb9a51b3e6e76f2eeb',
}
FLAGS = ['/NOLOGO', '/MACHINE:X86', '/SUBSYSTEM:WINDOWS', '/INCREMENTAL:NO',
         '/OPT:REF', '/OPT:NOICF', '/VERBOSE:LIB']
UNION_ROW_LIMIT = 64 * 1024 * 1024
require = partial.require
digest = partial.digest


def file_hash(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(1048576), b''):
            h.update(block)
    return h.hexdigest()


def canonical(value):
    return json.dumps(value, sort_keys=True, separators=(',', ':'), ensure_ascii=True).encode()


def union_stream_bound(ordinal, characters):
    require(1 <= ordinal <= 10000 and 0 < characters <= UNION_ROW_LIMIT, 'union stream bound')


def roots_and_fields(member, row):
    """Join every actual member field; undefined uses require saved obligations."""
    obj = coff.parse(member)
    receipt, plan = row['receipt'], row['receipt']['plan']
    require(digest(member) == row['member']['sha256'] == receipt['output_sha256'], 'CODE member hash differs')
    require(plan['eligible'] is True and receipt['original_binding_details_sha256'] ==
        '4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826', 'CODE proof identity differs')
    sm, ym = receipt['maps']['section_map'], receipt['maps']['symbol_map']
    reverse_symbols = {new: int(old) for old, new in ym.items()}
    require(len(reverse_symbols) == len(ym), 'CODE physical symbol map is not bijective')
    namespace = {r['serialized_index']: r for r in plan['namespace_plan']}
    require(len(namespace) == len(plan['namespace_plan']) and set(namespace) == set(obj['symbols']) and
        all(obj['symbols'][new]['name'] == r['name'] and reverse_symbols[new] == r['physical_index']
            for new, r in namespace.items()), 'CODE namespace/physical indices differ')
    roots = {}
    for root in plan['roots']:
        section = sm[str(root['section'])]
        index = ym[str(root['symbol_index'])]
        name = obj['symbols'][index]['name']
        require(name in receipt['exports'] and root['original_address'] not in roots, 'CODE root/export differs')
        roots[root['original_address']] = dict(root, canonical=name, serialized_section=section,
            recipe_id=plan['recipe_id'], object_sha256=plan['object_sha256'])
    obligations = {}
    for obligation in plan['obligations']:
        section = sm[str(obligation['physical_section'])]
        key = (section, obligation['field_offset'])
        require(key not in obligations, 'duplicate CODE field obligation')
        obligations[key] = obligation
    fields = []
    for section, sec in obj['sections'].items():
        for offset, index, kind in sec['relocs']:
            target = obj['symbols'][index]
            owners = [r for r in roots.values() if r['serialized_section'] == section and
                      r['value'] <= offset < r['value'] + r['size']]
            require(len(owners) == 1, 'actual CODE field lacks exact selected root')
            root = owners[0]
            row_field = dict(component='current-CODE', member=row['member']['name'],
                member_sha256=digest(member), recipe_id=plan['recipe_id'], object_sha256=plan['object_sha256'],
                root=root['original_address'], caller=root['canonical'], section=section,
                offset=offset, kind=kind, symbol_index=index, physical_symbol_index=reverse_symbols[index],
                canonical=target['name'], undefined=target['section'] == 0,
                binding_reference_group=row['member']['name'] + ':' + root['original_address'])
            obligation = obligations.pop((section, offset), None)
            if target['section'] == 0:
                require(obligation is not None and ym[str(obligation['symbol_index'])] == index and
                    obligation['kind'] == kind and obligation['canonical_name'] == target['name'] and
                    obligation['original_address'] == root['original_address'], 'CODE actual undefined/proof differs')
                width = {6: 4, 20: 4}.get(kind)
                require(width == 4 and struct.unpack_from('<I', sec['payload'], offset)[0] == obligation['addend_bits'], 'CODE actual field addend differs')
                row_field['proof'] = obligation
            else:
                require(obligation is None and target['name'] in plan['comparison_base_view'], 'retained CODE field proof differs')
                row_field['proof'] = dict(role='retained', original_base=plan['comparison_base_view'][target['name']])
            fields.append(row_field)
    require(not obligations and len(fields) == plan['counts']['fields'], 'CODE complete field census differs')
    return roots, fields, obj


def main_fields(entry_bytes, entry_receipt, manifest):
    meta = partial.standard_metadata(entry_bytes)
    rows = partial.join_fields(meta, entry_receipt['projection'])
    return [dict(component='actual-entry', member='application-entry.lib',
        member_sha256=digest(entry_bytes), recipe_id=partial.IDENTITY['recipe_id'],
        object_sha256=partial.IDENTITY['object_sha256'], root='0x0086a850', caller=partial.CANONICAL,
        section=r['section'], offset=r['offset'], kind=r['kind'], symbol_index=r['symbol_index'],
        physical_symbol_index=r['physical_symbol_index'], canonical=r['symbol'], undefined=True,
        proof=dict(r, classification='IAT_POINTER_CELL_NOT_FUNCTION_BODY' if r['role'] == 'iat-cell' else None))
        for r in rows]


def import_identity(dll, export):
    """Positive import identity; hint is documented named-import metadata only."""
    require(isinstance(dll, str) and 0 < len(dll) <= 260, 'invalid exact DLL spelling')
    require(isinstance(export, dict), 'invalid export record')
    if export.get('kind') == 'name':
        require(set(export) in ({'kind', 'name'}, {'kind', 'name', 'hint'}) and
            isinstance(export['name'], str) and 0 < len(export['name']) <= 1024,
            'unknown named-export fields or invalid exact name')
        if 'hint' in export:
            require(type(export['hint']) is int and 0 <= export['hint'] <= 65535,
                'invalid documented import hint')
        return (dll, 'name', export['name'])
    require(set(export) == {'kind', 'ordinal'} and export.get('kind') == 'ordinal' and
        type(export['ordinal']) is int and 0 <= export['ordinal'] <= 65535,
        'unknown ordinal-export fields or invalid exact ordinal')
    return (dll, 'ordinal', export['ordinal'])


def native_pointer_proof(proposal, native_libraries):
    require(proposal['library'] in native_libraries, 'native library missing')
    library = native_libraries[proposal['library']]
    matches = [row for row in library['imports'] if row['member_offset'] == proposal['member_offset']]
    require(len(matches) == 1, 'native pointer member missing or ambiguous')
    row = matches[0]
    require(import_identity(proposal['dll'], proposal['export']) == import_identity(row['dll'], row['export']) and
        row['machine'] == 0x14c and row['import_type'] == 0 and row['name_type'] == 2 and
        row['pointer_symbol'] == proposal['proposed_pointer_symbol'] and
        row['pointer_symbol'] == '__imp_' + row['symbol'] and row['pointer_symbol'] != row['symbol'] and
        sorted(item['symbol'] for item in library['index'] if item['member_offset'] == row['member_offset']) ==
            sorted([row['symbol'], row['pointer_symbol']]), 'native pointer/member/export identity conflict')
    return dict(library=proposal['library'], **row)


def alias_census(proposals, fields, catalog, native_libraries):
    """Each global alias is scoped to the complete actual use set of that name."""
    cells = {row['original_IAT_va']: row for row in catalog['imports']}
    require(len(cells) == len(catalog['imports']), 'duplicate original import catalog cell')
    result = []
    for proposal in proposals:
        name, va = proposal['canonical_IAT_symbol'], proposal['original_IAT_va']
        uses = [r for r in fields if r['canonical'] == name]
        blockers = []
        cell = cells.get(va)
        expected_name = '_fnv_undefined_' + digest(canonical(dict(original_base=va, role='iat-cell')))
        positive_identity = None
        native_proof = None
        try:
            require(cell is not None, 'original IAT catalog cell missing')
            positive_identity = import_identity(cell['dll'], cell['export'])
            require(positive_identity == import_identity(proposal['dll'], proposal['export']),
                'exact DLL/export identity changed')
            native_proof = native_pointer_proof(proposal, native_libraries)
        except ValueError as error:
            blockers.append('ORIGINAL_DLL_EXPORT_OR_POINTER_IDENTITY_CONFLICT:' + str(error))
        if not (name == expected_name and proposal['pointer_indirection_preserved'] is True and
                proposal['proposed_pointer_symbol'].startswith('__imp_') and
                proposal['alias_applied'] is False and proposal['runtime_provider_adopted'] is False):
            blockers.append('ORIGINAL_DLL_EXPORT_OR_POINTER_IDENTITY_CONFLICT')
        if not uses:
            blockers.append('NO_ACTUAL_INCLUDED_USE')
        for use in uses:
            proof = use['proof']
            import_id_ok = cell is not None and (use['component'] == 'actual-entry' or
                                                proof.get('import_id') == cell.get('import_id'))
            if not (use['undefined'] and use['kind'] == 6 and proof.get('role') == 'iat-cell' and
                proof.get('original_base') == proof.get('original_target') == va and
                proof.get('addend_bits') == 0 and proof.get('classification') == 'IAT_POINTER_CELL_NOT_FUNCTION_BODY' and
                import_id_ok):
                blockers.append('UNPROVED_INCLUDED_FIELD:' + use['component'] + ':' + use['member'] + ':' + str(use['offset']))
        result.append(dict(canonical=name, native_pointer=proposal['proposed_pointer_symbol'],
            dll=proposal['dll'], export=proposal['export'], original_IAT_va=va,
            library=proposal['library'], native_member_offset=proposal['member_offset'],
            complete_actual_uses=uses, use_count=len(uses), blockers=blockers,
            positive_import_identity=positive_identity,
            catalog_export_observation=cell['export'] if cell else None,
            documented_catalog_hint=cell['export'].get('hint') if cell else None,
            proposal_export_observation=proposal['export'], native_pointer_proof=native_proof,
            enabled=not blockers, scope='LINK identity diagnostic only', ABI_approved=False, provider_adopted=False))
    require(len(result) == len({row['canonical'] for row in result}) == 25, 'exact 25 distinct proposed cells required')
    return result


def unresolved_groups(receipt):
    """Actual LNK target groups; included provenance is not extraction evidence."""
    grouped = defaultdict(list)
    for error in receipt['errors']:
        if error['code'] not in ('LNK2001', 'LNK2019') or error['severity'] == 'warning':
            continue
        match = re.search(r'unresolved external symbol (.*?)(?: referenced in function |$)', error['text'])
        require(match is not None and match[1], 'unparsed actual unresolved diagnostic')
        grouped[match[1]].append(error)
    result = []
    labels = {'code': 'CODE', 'data': 'DATA', 'crt-contract': 'CRT', 'iat-cell': 'IAT'}
    for name, errors in sorted(grouped.items()):
        observations = receipt['provenance'].get(name, [])
        fields = [row for row in observations if row.get('proof')]
        roles = sorted({row['proof']['role'] for row in fields})
        classification = labels.get(roles[0], 'UNKNOWN') if len(roles) == 1 else 'CONFLICT_OR_UNKNOWN'
        callers = sorted({match[1] for error in errors for match in
            [re.search(r' referenced in function (.+)$', error['text'])] if match})
        result.append(dict(symbol=name, classification=classification, observed_roles=roles,
            canonical_namespace='physical-CODE-owner' if name.startswith('_fnv_code_') else
                'original-base-and-role' if name.startswith('_fnv_undefined_') else 'native-or-unknown',
            error_occurrences=len(errors), error_records=errors, reported_reference_callers=callers,
            original_bases=sorted({row['proof']['original_base'] for row in fields if row['proof'].get('original_base')}),
            original_targets=sorted({row['proof']['original_target'] for row in fields if row['proof'].get('original_target')}),
            included_input_provenance=fields,
            reported_caller_provenance=[row for row in fields if row.get('caller') in callers],
            definition_observations=[row for row in observations if not row.get('proof')],
            included_provenance_is_extraction_proof=False))
    totals = dict(Counter(row['classification'] for row in result))
    return dict(kind='actual-unresolved-LNK-target-groups', groups=result,
        unique_unresolved_symbols=len(result), error_occurrences=sum(row['error_occurrences'] for row in result),
        classifications=totals, executable_execution=False, runtime_eligible=False)


def diagnostic_errors(text, provenance):
    rows = []
    for number, line in enumerate(text.splitlines(), 1):
        code = re.search(r'\b(fatal error|error|warning) (LNK\d+)\b', line)
        if code:
            names = re.findall(r'_fnv_(?:code|undefined)_[0-9a-f]{64}', line)
            rows.append(dict(line=number, severity=code[1], code=code[2], text=line,
                canonical_records={name: dict(provenance_key=name,
                    observations=len(provenance.get(name, []))) for name in dict.fromkeys(names)}))
    return rows


def classify(returncode, errors):
    if returncode == 0:
        return 'unexpected-link-success-not-runtime-approved'
    failures = [row['code'] for row in errors if row.get('severity', 'error') != 'warning']
    if failures and all(code in ('LNK2001', 'LNK2019', 'LNK1120') for code in failures):
        return 'expected-unresolved-link-diagnostic'
    return 'other-link-failure-requires-review'


def response_text(arguments):
    require(all('"' not in arg and '\n' not in arg and '\r' not in arg for arg in arguments), 'unsafe response token')
    forbidden = ('/ENTRY', '/FORCE', '/IGNORE', '/NODEFAULTLIB', '/WHOLEARCHIVE')
    require(not any(arg.upper().startswith(forbidden) for arg in arguments), 'forbidden diagnostic linker policy')
    return '\n'.join('"' + arg + '"' for arg in arguments) + '\n'


def identity(path):
    requested = Path(path).absolute()
    path = requested.resolve(strict=True); stat = path.stat()
    require(path.is_file(), 'bound input is not a file')
    return dict(requested_path=str(requested), path=str(path), sha256=file_hash(path), size=stat.st_size,
                device=stat.st_dev, inode=stat.st_ino)


def stable(bindings):
    require(all(identity(row['requested_path']) == row for row in bindings), 'bound input identity drift')


def sources(repository, expected_self):
    pins = dict(SOURCE_PINS, **{'tools/rebuild/application_link_diagnostic.py': expected_self})
    require(all(file_hash(repository / name) == pin for name, pin in pins.items()), 'reviewed source/dependency drift')
    return [identity(repository / name) for name in pins]


def select_libraries(out, vc, sdk):
    libraries = {'libcmt.lib': vc / 'libcmt.lib', 'oldnames.lib': vc / 'oldnames.lib',
        'kernel32.lib': sdk / 'kernel32.lib', 'uuid.lib': sdk / 'uuid.lib'}
    for name, expected in libraries.items():
        candidates = [root / name for root in [out, vc, sdk] if (root / name).is_file()]
        require(candidates and candidates[0].resolve() == expected.resolve(), 'shadowed/default library: ' + name)
    return {name: identity(path) for name, path in libraries.items()}


def native_dependency_candidates(compiler):
    """Exact observed local support candidates; not a loaded-DLL closure claim."""
    relatives = ['VC/bin/mspdb80.dll', 'VC/bin/mspdbcore.dll', 'VC/bin/mspdbsrv.exe',
        'VC/bin/Microsoft.VC90.CRT/msvcr90.dll',
        'VC/redist/x86/Microsoft.VC90.CRT/msvcr90.dll']
    return [identity(Path(compiler) / relative) for relative in relatives]


def prepare(repository, out, expected_self):
    repository, out = Path(repository).resolve(), Path(out).resolve()
    require(not out.exists() and (not out.is_relative_to(repository) or out.is_relative_to(repository / 'build/rebuild')), 'new private output required')
    bindings = sources(repository, expected_self)
    paths = {key: repository / 'build/rebuild' / pair[0] for key, pair in PINS.items()}
    for key, path in paths.items():
        require(file_hash(path) == PINS[key][1], 'accepted input differs: ' + key); bindings.append(identity(path))
    manifest = json.loads(paths['partial'].read_text())
    require(manifest['status'] == 'partial-inputs-with-unresolved-obligations' and manifest['link_ready'] is False and
        manifest['import_aliases_applied'] is False, 'partial manifest state differs')
    partial_dir = paths['partial'].parent
    for name, pin in manifest['outputs'].items():
        path = partial_dir / name
        require(path.name == name and file_hash(path) == pin, 'partial component differs'); bindings.append(identity(path))
    native = json.loads(paths['code_native'].read_text())
    require(native['native_read_only_conformance_verified'] is True and native['archive_sha256'] == PINS['code'][1], 'current CODE native conformance differs')
    recovered = coff.read_archive(paths['code'].read_bytes())
    members = dict(recovered['members']); seen = set(); fields = []; provenance = defaultdict(list)
    reference_groups = {}
    for name, definition in manifest['definitions'].items():
        provenance[name].append(dict(component='partial-selected-definition', definition=definition))
    for number, line in enumerate(gzip.open(paths['unions'], 'rt', encoding='utf-8'), 1):
        union_stream_bound(number, len(line))
        row = json.loads(line)
        if row.get('event') != 'EMITTED_RECIPE_UNION':
            continue
        name = row['member']['name']; require(name in members and name not in seen, 'CODE emitted member differs'); seen.add(name)
        roots, member_fields, obj = roots_and_fields(members[name], row); fields += member_fields
        for root, references in row['receipt']['binding_row_references'].items():
            reference_groups[name + ':' + root] = dict(
                original_binding_details_sha256=row['receipt']['original_binding_details_sha256'],
                references=references)
        directives = partial.standard_metadata(members[name])['directives']
        require(directives == ['/DEFAULTLIB:"LIBCMT"', '/DEFAULTLIB:"OLDNAMES"'], 'unexpected CODE default-library directives')
        for root in roots.values():
            require(root['canonical'] not in provenance, 'selected CODE/partial definition conflict')
            provenance[root['canonical']].append(dict(component='current-CODE-definition', member=name, **root))
    require(seen == set(members) and len(members) == 1019 and len(recovered['index']) == 12946 and
        len(fields) == 36839, 'complete accepted CODE census differs')
    entry_receipt = json.loads(paths['entry'].read_text())
    fields += main_fields((partial_dir / 'entry-evidence.obj').read_bytes(), entry_receipt, manifest)
    host_obj = coff.parse((partial_dir / 'host-bound.obj').read_bytes())
    host_fields = [(section, offset, index, kind) for section, sec in host_obj['sections'].items()
                   for offset, index, kind in sec['relocs']]
    require(host_fields == [tuple(row) for row in manifest['host_binding']['fields']] and
        len(host_fields) == 1 and host_obj['symbols'][host_fields[0][2]]['name'] == partial.CANONICAL,
        'actual bound host field differs')
    section, offset, index, kind = host_fields[0]
    fields.append(dict(component='original-host', member='host-bound.obj',
        member_sha256=manifest['outputs']['host-bound.obj'], root='WinMain', caller='_WinMain@16',
        section=section, offset=offset, kind=kind, symbol_index=index,
        physical_symbol_index=index, canonical=partial.CANONICAL, undefined=True,
        proof=dict(role='code', original_target='0x0086a850', addend_bits=0)))
    for field in fields:
        provenance[field['canonical']].append(field)
    catalog = json.loads(paths['imports'].read_text())
    aliases = alias_census(manifest['import_pointer_proposals'], fields, catalog, manifest['native_import_libraries'])
    doctor = json.loads(paths['doctor'].read_text())['toolchains']['sp1']
    require(doctor['ready'] is True and doctor['version'] == '15.00.30729.01', 'SP1 doctor differs')
    compiler, sdk = Path(doctor['root']).resolve(), Path(doctor['sdk']).resolve()
    link = compiler / 'VC/bin/link.exe'
    require(file_hash(link) == doctor['link_sha256'], 'SP1 linker drift')
    bindings.append(identity(link))
    dependency_evidence = json.loads(paths['dependency_evidence'].read_text())
    require(dependency_evidence['linker_sha256'] == doctor['link_sha256'] and
        dependency_evidence['direct_import_DLLs'] ==
            ['ADVAPI32.dll', 'KERNEL32.dll', 'MSVCR90.dll', 'USER32.dll', 'mspdb80.dll'] and
        dependency_evidence['msobj80_direct_import_present'] is False, 'direct linker dependency evidence differs')
    dependency_candidates = native_dependency_candidates(compiler)
    bindings += dependency_candidates
    libraries = select_libraries(out, compiler / 'VC/lib', sdk / 'Lib')
    bindings += list(libraries.values())
    args = list(FLAGS) + ['/OUT:' + str(out / 'diagnostic.exe'), '/MAP:' + str(out / 'diagnostic.map'),
        '/LIBPATH:' + str(compiler / 'VC/lib'), '/LIBPATH:' + str(sdk / 'Lib')]
    args += [str(partial_dir / name) for name in ['host-bound.obj', 'application-entry.lib', 'data-0.obj', 'data-1.obj']]
    args += [str(paths['code'])] + [str(partial_dir / f'provider-{n:03d}.lib') for n in range(4)]
    args += ['/ALTERNATENAME:' + row['canonical'] + '=' + row['native_pointer'] for row in aliases if row['enabled']]
    rsp = response_text(args)
    stable(bindings)
    out.mkdir(parents=True)
    (out / 'link.rsp').write_text(rsp, encoding='ascii')
    report = dict(schema_version=1, kind='expected-failure-application-link-diagnostic', status='prepared-no-native-LINK',
        input_bindings=bindings, default_libraries=libraries, response_sha256=file_hash(out / 'link.rsp'),
        command=[str(link), '@' + str(out / 'link.rsp')], compiler_root=str(compiler), sdk_root=str(sdk),
        aliases=aliases, provenance=dict(provenance), full_included_field_count=len(fields),
        original_binding_reference_groups=reference_groups,
        local_native_dependency_candidates=dependency_candidates,
        direct_linker_dependency_evidence_sha256=PINS['dependency_evidence'][1],
        transitive_or_loaded_DLL_closure_verified=False,
        complete_CODE_members=len(members), complete_CODE_exports=len(recovered['index']),
        normal_CRT_is_diagnostic_candidate_only=True, executable_execution=False,
        provider_adopted=False, runtime_eligible=False, link_ready=False,
        whole_DATA_included=False, unreviewed_CRT_aliases=[], native_LINK_performed=False)
    stable(bindings)
    return report


def link_once(report, out):
    """One native LINK invocation; cannot launch diagnostic.exe."""
    require(os.name == 'nt' and report['native_LINK_performed'] is False, 'fresh native Windows LINK only')
    out = Path(out).resolve()
    stable(report['input_bindings'])
    require(file_hash(out / 'link.rsp') == report['response_sha256'], 'response drift')
    libraries = select_libraries(out, Path(report['compiler_root']) / 'VC/lib', Path(report['sdk_root']) / 'Lib')
    require(libraries == report['default_libraries'], 'default library search drift')
    env = toolchain.environment(report['compiler_root'])
    for variable in ['CL', '_CL_', 'LINK', '_LINK_', 'LIBPATH']:
        env.pop(variable, None)
    env['LIB'] = ';'.join([str(Path(report['compiler_root']) / 'VC/lib'), str(Path(report['sdk_root']) / 'Lib')])
    report['environment_policy'] = dict(cleared=['CL', '_CL_', 'LINK', '_LINK_', 'LIBPATH'], LIB=env['LIB'])
    journal = out / 'progress.jsonl'
    def note(state, **data):
        with journal.open('a', encoding='utf-8') as stream:
            stream.write(json.dumps(dict(state=state, timestamp=time.time(), **data)) + '\n'); stream.flush(); os.fsync(stream.fileno())
    note('native-LINK-starting', command=report['command'])
    report['native_LINK_performed'] = True
    stdout, stderr = out / 'link.stdout.txt', out / 'link.stderr.txt'
    with stdout.open('xb') as out_stream, stderr.open('xb') as err_stream:
        try:
            result = subprocess.run(report['command'], cwd=out, env=env, stdin=subprocess.DEVNULL,
                stdout=out_stream, stderr=err_stream, timeout=180, creationflags=subprocess.CREATE_NO_WINDOW)
            report['returncode'] = result.returncode
        except subprocess.TimeoutExpired:
            report['status'] = 'native-LINK-timeout-requires-review'
            report['log_sha256'] = dict(stdout=file_hash(stdout), stderr=file_hash(stderr))
            note('native-LINK-timeout'); raise
    stable(report['input_bindings'])
    require(select_libraries(out, Path(report['compiler_root']) / 'VC/lib', Path(report['sdk_root']) / 'Lib') == libraries, 'default library drift after LINK')
    require(max(stdout.stat().st_size, stderr.stat().st_size) <= 128 * 1024 * 1024, 'retained LINK log exceeds parser bound')
    text = stdout.read_text(encoding='utf-8', errors='replace') + '\n' + stderr.read_text(encoding='utf-8', errors='replace')
    report['errors'] = diagnostic_errors(text, report['provenance'])
    report['status'] = classify(report['returncode'], report['errors'])
    report['log_sha256'] = dict(stdout=file_hash(stdout), stderr=file_hash(stderr))
    report['linker_error_codes'] = dict(Counter(row['code'] for row in report['errors'] if row['severity'] != 'warning'))
    report['linker_warning_codes'] = dict(Counter(row['code'] for row in report['errors'] if row['severity'] == 'warning'))
    report['outputs'] = {path.name: identity(path) for path in [out / 'diagnostic.exe', out / 'diagnostic.map'] if path.is_file()}
    report['library_observation_lines'] = [line for line in text.splitlines() if re.search(r'\b(?:Searching|Loaded|Found|Referenced in)\b', line)]
    report['loaded_member_enumeration_claimed'] = False
    note('native-LINK-finished', status=report['status'], returncode=report['returncode'])


def analyze_saved_v3(repository, out, expected_self):
    """Bounded existing evidence only: no CODE rewrite, native LINK or execution."""
    repository, out = Path(repository).resolve(), Path(out).resolve()
    require(not out.exists() and (not out.is_relative_to(repository) or out.is_relative_to(repository / 'build/rebuild')),
        'new private analysis output required')
    bindings = sources(repository, expected_self)
    requested = {'v3': V3_RECEIPT, 'partial': PINS['partial'], 'imports': PINS['imports']}
    paths = {key: repository / 'build/rebuild' / pair[0] for key, pair in requested.items()}
    for key, path in paths.items():
        require(file_hash(path) == requested[key][1], 'analysis input differs: ' + key)
        bindings.append(identity(path))
    receipt = json.loads(paths['v3'].read_text())
    manifest = json.loads(paths['partial'].read_text())
    catalog = json.loads(paths['imports'].read_text())
    native_libraries = {}
    for number in range(4):
        name = f'provider-{number:03d}.lib'
        path = paths['partial'].parent / name
        require(file_hash(path) == manifest['outputs'][name], 'actual native import library differs')
        bindings.append(identity(path))
        native_libraries[name] = partial.native_archive(path.read_bytes())
    fields = [row for observations in receipt['provenance'].values() for row in observations
              if 'canonical' in row and 'proof' in row]
    require(len(fields) == receipt['full_included_field_count'] == 37282, 'saved complete field census differs')
    aliases = alias_census(manifest['import_pointer_proposals'], fields, catalog, native_libraries)
    require(len(aliases) == 25 and all(row['enabled'] for row in aliases) and
        sum(row['use_count'] for row in aliases) == 32, 'actual all-25 positive identity reconciliation differs')
    groups = unresolved_groups(receipt)
    require(groups['unique_unresolved_symbols'] == 280 and groups['error_occurrences'] == 284,
        'actual v3 unresolved group census differs')
    stable(bindings)
    out.mkdir(parents=True)
    return dict(schema_version=1, kind='read-only-v3-identity-and-unresolved-analysis',
        status='all-25-identity-cells-and-280-unresolved-groups-reconciled',
        input_bindings=bindings, v3_receipt_sha256=V3_RECEIPT[1],
        positive_IAT_identity_cells=aliases, unresolved_groups=groups,
        full_included_field_count=len(fields), aliases_applied=False,
        native_LINK_performed=False, executable_execution=False, runtime_eligible=False,
        historical_v3_aliases_enabled=sum(row['enabled'] for row in receipt['aliases']))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source-sha256', required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--link-once', action='store_true', help='separate root-authorized native diagnostic only')
    parser.add_argument('--analyze-v3', action='store_true', help='existing v3 metadata only; no native operation')
    args = parser.parse_args()
    require(not (args.link_once and args.analyze_v3), 'analysis cannot request native LINK')
    report = analyze_saved_v3(ROOT, args.out, args.source_sha256) if args.analyze_v3 else prepare(ROOT, args.out, args.source_sha256)
    try:
        if args.link_once:
            link_once(report, args.out)
        if 'input_bindings' in report:
            stable(report['input_bindings'])
    except Exception as exc:
        report['status'] = 'error-requires-reconciliation'; report['error'] = type(exc).__name__ + ': ' + str(exc)
    with (args.out / 'receipt.json').open('x', encoding='utf-8') as stream:
        json.dump(report, stream, sort_keys=True, indent=2); stream.write('\n')
    print(json.dumps(dict(status=report['status'], native_LINK_performed=report['native_LINK_performed'],
        executable_execution=False, runtime_eligible=False)))


if __name__ == '__main__':
    main()
