"""Offline normal-import identity/DEF preparation; no native tools or providers."""
from __future__ import annotations
import argparse
from collections import Counter
import gzip
import hashlib
import json
from pathlib import Path
import re

from runtime_code_pool import unresolved

ROOT = Path(__file__).resolve().parents[2]
NAMESPACE_HELPER = Path(__file__).with_name('runtime_code_pool.py')
NAMESPACE_HELPER_PIN = '729f189e2893c7f3a3e3cd97df7d7381ac115169e1d75cf664e6bbc1c587b277'
PLAN_PIN = 'e39b8db63ef73aea57b5dd4963ff29310524644ca36e137cd8b5461a3c90a23f'
NAMESPACE_PIN = 'bd66830f9f879af1a53ca35156124f769d228f9a63dfda08591e959a7a1a82a9'
MAIN = dict(recipe_id='0576-dd603b7071c482c6', function_va='0x0086a850',
            object_sha256='a6c310961921f70eea2c70b9c18dba3d85ac19bffdfe3164922e9c3462ab425b',
            source_sha256='89d09f8b4ba6d9758fca0ac3ebd32e18c9cc82c68a739c044457ed5c005ae3c5')


def require(ok, message):
    if not ok:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def file_hash(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        while block := f.read(1024 * 1024):
            h.update(block)
    return h.hexdigest()


def check_helper():
    require(file_hash(NAMESPACE_HELPER) == NAMESPACE_HELPER_PIN, 'namespace helper changed')


def token(value):
    require(isinstance(value, str) and re.fullmatch(r'[A-Za-z0-9_?@$.-]{1,1024}', value),
            'identity cannot be represented safely in DEF')
    return value


def simple_export_token(value):
    require(isinstance(value, str) and re.fullmatch(r'[A-Za-z_][A-Za-z0-9_]{0,1023}', value),
            'export requires separate DEF syntax conformance')
    return value


def catalog(plan):
    require(plan.get('kind') == 'fnv-static-import-plan' and plan.get('schema_version') == 1,
            'unsupported import plan')
    require(plan.get('runtime_closure_verified') is False and plan.get('game_fixups_approved') == 0,
            'unexpected import-plan approval state')
    imports = plan['imports']
    require(0 < len(imports) <= 16384, 'invalid catalog count')
    result = {}
    ids = set()
    for item in imports:
        va = item['original_IAT_va']
        require(isinstance(va, str) and re.fullmatch('0x[0-9a-f]{8}', va) and int(va, 16) % 4 == 0,
                'invalid IAT cell')
        require(va not in result and type(item['import_id']) is int and item['import_id'] not in ids,
                'duplicate IAT cell/import id')
        require(item['representation'] == 'IAT_POINTER_CELL_NOT_FUNCTION_BODY', 'not an IAT pointer')
        dll = token(item['dll'])
        require(len(dll) <= 260 and dll not in ('.', '..'), 'invalid DLL identity')
        exp = item['export']
        if exp['kind'] == 'name':
            identity = dict(kind='name', name=token(exp['name']))
        else:
            require(exp['kind'] == 'ordinal' and type(exp.get('ordinal')) is int and
                    0 <= exp['ordinal'] <= 65535, 'invalid ordinal identity')
            identity = dict(kind='ordinal', ordinal=exp['ordinal'])
        expected = dict(dll=dll, export=identity)
        contract = item['required_provider_contract']
        require(contract['dll'] == dll and contract['export'] == identity and
                contract['runtime_provider_selected'] is False, 'identity/contract conflict')
        result[va] = dict(import_id=item['import_id'], original_IAT_va=va,
                          canonical_IAT_symbol=unresolved(va, 'iat-cell'), **expected)
        ids.add(item['import_id'])
    require(plan['summary']['imports'] == len(result), 'catalog summary conflict')
    return result


def prepare(plan, records, root):
    """Join original identity only. Source spellings are provenance, never providers."""
    cells = catalog(plan)
    fields = []
    seen = set()
    for ordinal, row in records:
        if row.get('recipe_id') != root['recipe_id']:
            continue
        observations = [f for f in row.get('verified_function_fields', [])
                        if f['function_va'] == root['function_va']]
        if not observations:
            continue
        require(len(observations) == 1, 'duplicate function observation')
        f = observations[0]
        va = row['original_IAT_va']
        require(va in cells and row['status'] == 'VERIFIED_FUNCTION_EXACT_IAT_USE' and
                row['relocation_kind'] == 6 and row['addend'] == 0 and
                row['recipe_binding_va'] == va and f['observed_operand'] == int(va, 16),
                'unproved exact pointer-cell use')
        require(all(row[key] == root[key] for key in ('object_sha256', 'source_sha256')),
                'root object/source conflict')
        require(row['section'] == f['function_section'] and
                row['relocation_offset'] == f['function_value'] + f['field_offset'] and
                int(f['original_field_va'], 16) == int(root['function_va'], 16) + f['field_offset'],
                'field coordinates conflict')
        key = (row['section'], row['relocation_offset'])
        require(key not in seen, 'duplicate physical field')
        seen.add(key)
        fields.append(dict(detail_ordinal=ordinal, detail_sha256=digest(json.dumps(row, sort_keys=True,
                           separators=(',', ':')).encode()), section=row['section'],
                           field_offset=f['field_offset'], symbol_index=row['symbol_index'],
                           source_symbol=row['symbol'], original_IAT_va=va,
                           canonical_IAT_symbol=cells[va]['canonical_IAT_symbol'],
                           relocation_kind=6, addend=0))
    selected = sorted({f['original_IAT_va'] for f in fields})
    require(selected, 'no selected IAT fields')
    # Keep one physical source index tied to one original cell, even for misleading names.
    by_symbol = {}
    for field in fields:
        index = field['symbol_index']
        require(index not in by_symbol or by_symbol[index] == field['original_IAT_va'],
                'physical symbol has conflicting original cells')
        by_symbol[index] = field['original_IAT_va']
    report = dict(schema_version=2, kind='fnv-normal-import-projection-preparation',
                  status='offline-preparation-only', root=root, catalog_cell_count=len(cells),
                  definition_syntax='vc9-unquoted-safe-export-tokens-v2',
                  selected_cells=[cells[v] for v in selected], fields=fields,
                  summary=dict(cells=len(selected), fields=len(fields), physical_symbols=len(by_symbol),
                               DLLs=dict(Counter(cells[v]['dll'] for v in selected))),
                  source_ABI_verified=False, runtime_provider_selected=False,
                  native_library_generated=False, executable_link_authorized=False,
                  canonical_link_aliases=[], native_pointer_symbol_names_verified=False,
                  blockers=['SOURCE_INDEPENDENT_REVIEW_AND_ROOT_GO_REQUIRED',
                            'NATIVE_IMPORT_MEMBER_POINTER_SYMBOLS_UNVERIFIED',
                            'SOURCE_CALL_ABI_AND_RUNTIME_PROVIDER_ADOPTION_UNVERIFIED'])
    return report


def definitions(report):
    """DEF names are actual exports. Ordinal tokens are local labels, not API names."""
    grouped = {}
    for cell in report['selected_cells']:
        grouped.setdefault(cell['dll'], []).append(cell['export'])
    files, manifests = {}, []
    for number, (dll, exports) in enumerate(sorted(grouped.items())):
        filename = f'provider-{number:03d}.def'
        lines = [f'LIBRARY "{token(dll)}"', 'EXPORTS']
        unique = {json.dumps(exp, sort_keys=True): exp for exp in exports}
        for _, exp in sorted(unique.items()):
            if exp['kind'] == 'name':
                # VC9 LIB preserves quotes here as part of the exported name.
                lines.append(f'    {simple_export_token(exp["name"])}')
            else:
                n = exp['ordinal']
                lines.append(f'    fnv_ordinal_{n:05d} @{n} NONAME')
        files[filename] = ('\n'.join(lines) + '\n').encode('ascii')
        manifests.append(dict(dll=dll, definition=filename, definition_sha256=digest(files[filename]),
                              planned_library=filename.replace('.def', '.lib'),
                              native_action='LIB /MACHINE:X86 /DEF:<definition> /OUT:<planned_library>',
                              native_action_authorized=False))
    report['definition_preparation'] = manifests
    return files


def join_namespace(report, certificate):
    require(report['root'] == MAIN and
            certificate.get('kind') == 'compatible-undefined-reference-certificate-candidate' and
            certificate.get('schema_version') == 1 and certificate['root']['recipe_id'] == MAIN['recipe_id'] and
            certificate['root']['original_address'] == MAIN['function_va'] and
            certificate['object_sha256'] == MAIN['object_sha256'] and
            certificate['input_sha256']['imports'] == PLAN_PIN and
            certificate['input_sha256']['source'] == MAIN['source_sha256'], 'namespace provenance differs')
    rows = certificate['namespace_plan']
    namespace = {row['physical_index']: row for row in rows}
    require(len(namespace) == len(rows), 'duplicate physical namespace records')
    pairs = [(row['physical_index'], row['serialized_index']) for row in rows]
    require(all(type(a) is int and type(b) is int and a >= 0 and b >= 0 for a, b in pairs) and
            len({b for a, b in pairs}) == len(pairs) and
            sorted(pairs) == sorted(map(tuple, certificate['primary_bijection'])),
            'namespace physical/serialized bijection differs')
    for field in report['fields']:
        row = namespace.get(field['symbol_index'])
        require(row is not None and row['name'] == field['canonical_IAT_symbol'],
                'canonical IAT namespace differs')
        field['planned_serialized_symbol_index'] = row['serialized_index']
    report['canonical_namespace_join_verified'] = True


def records(path):
    with gzip.open(path, 'rb') as stream:
        for ordinal in range(1, 100002):
            line = stream.readline(1024 * 1024 + 1)
            if not line:
                return
            require(ordinal <= 100000 and len(line) <= 1024 * 1024, 'detail bounds exceeded')
            yield ordinal, json.loads(line)


def run(args):
    plan_path, detail_path, namespace_path, out = (Path(v).resolve() for v in
                                                 (args.plan, args.details, args.namespace, args.out))
    require(not out.is_relative_to(ROOT) or out.is_relative_to(ROOT / 'build' / 'rebuild'),
            'private output must be under build/rebuild or outside checkout')
    check_helper()
    implementation_hash = file_hash(__file__)
    require(file_hash(plan_path) == PLAN_PIN, 'actual v3 import plan SHA-256 differs')
    require(plan_path.stat().st_size <= 64 * 1024 * 1024, 'oversized plan')
    plan = json.loads(plan_path.read_text(encoding='utf-8'))
    detail_hash = plan['details_sha256']
    require(file_hash(detail_path) == detail_hash, 'detail hash differs')
    report = prepare(plan, records(detail_path), MAIN)
    require(file_hash(namespace_path) == NAMESPACE_PIN and namespace_path.stat().st_size <= 64*1024*1024,
            'accepted namespace certificate differs')
    join_namespace(report, json.loads(namespace_path.read_text(encoding='utf-8')))
    require(report['summary']['cells'] == report['summary']['physical_symbols'] == 25 and
            report['summary']['fields'] == 30, 'actual main scope differs')
    files = definitions(report)
    report['inputs'] = dict(import_plan_sha256=PLAN_PIN, details_sha256=detail_hash,
                           canonical_namespace_sha256=NAMESPACE_PIN)
    report['implementation_sha256'] = implementation_hash
    report['namespace_helper_sha256'] = NAMESPACE_HELPER_PIN
    def check_stable():
        require(file_hash(plan_path) == PLAN_PIN and file_hash(detail_path) == detail_hash and
                file_hash(namespace_path) == NAMESPACE_PIN and
                file_hash(__file__) == implementation_hash,
                'input changed during preparation')
        check_helper()
    check_stable()
    out.mkdir(parents=True, exist_ok=False)
    created = []
    try:
        for name, data in files.items():
            with (out / name).open('xb') as dest:
                created.append(out / name)
                dest.write(data)
        check_stable()
        with (out / 'preparation.json').open('x', encoding='utf-8') as dest:
            created.append(out / 'preparation.json')
            json.dump(report, dest, indent=2, sort_keys=True)
            dest.write('\n')
    except BaseException:
        for path in reversed(created):
            path.unlink()
        out.rmdir()
        raise
    return report


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--plan', required=True)
    parser.add_argument('--details', required=True)
    parser.add_argument('--namespace', required=True)
    parser.add_argument('--out', required=True)
    arguments = parser.parse_args()
    result = run(arguments)
    print(json.dumps(dict(status=result['status'], summary=result['summary'])))
