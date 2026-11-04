"""Observe the entry's selected CODE dependency closure from saved metadata only."""
from __future__ import annotations

import argparse
from collections import Counter, defaultdict, deque
import gzip
import hashlib
import json
import os
from pathlib import Path
import re

PINS = {
    'selection': '48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1',
    'binding': '275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804',
    'inventory': '02a77cce3f43c1786cd027e72ffb17e76ffe6766c2823872254015b6e40549f6',
}
ENTRY = '0x0086a850'
FALSE = dict(runtime_eligible=False, provider_selected=False, ABI_verified=False,
             link_ready=False, runtime_closure_verified=False, emission_performed=False)
CLASSES = {
    'SELECTED_CODE_ENTRY': 'selected_entry',
    'UNIQUE_CODE_INTERIOR_OR_LOCAL_LABEL_NOT_CALLABLE_APPROVAL': 'interior_owner_retention',
    'IAT_POINTER_CELL_NOT_FUNCTION_BODY': 'import_pointer',
    'COMPILER_LOCAL_EH_METADATA_OR_HELPER_CANDIDATE': 'runtime_EH_candidate',
    'EXPLICIT_NORMAL_CRT_CONTRACT_CANDIDATE': 'runtime_CRT_candidate',
    'COMPILER_LITERAL_FULL_READONLY_NONPOINTER_EQUALITY': 'literal_projection',
    'ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER': 'data_owner_unselected',
    'STATIC_TLS_INDEX_REQUIRES_CANONICAL_OWNER': 'TLS_owner_unselected',
    'UNSELECTED_EXECUTABLE_TARGET_UNCLASSIFIED': 'generated_or_unselected_code_unknown',
    'UNSUPPORTED_OR_UNMAPPED': 'unknown_target',
    'COMPILER_TLS_ARRAY_OFFSET_CANDIDATE_NOT_PROCESS_VA': 'TLS_numeric_offset',
    'STATIC_TLS_SECREL_REQUIRES_OWNER': 'TLS_section_offset',
    'MISSING_SOURCE_RELOCATION_NO_SYNTHESIS': 'missing_source_field',
}


def require(condition, message):
    if not condition:
        raise ValueError(message)


def canonical(value):
    return json.dumps(value, sort_keys=True, separators=(',', ':'), ensure_ascii=True).encode('ascii')


def digest(value):
    return hashlib.sha256(canonical(value)).hexdigest()


def file_hash(path):
    h = hashlib.sha256()
    with open(path, 'rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def records(path):
    with gzip.open(path, 'rt', encoding='utf-8') as stream:
        for number in range(1, 1000002):
            line = stream.readline(4 * 1024 * 1024 + 1)
            if not line:
                return
            require(number <= 1000000 and len(line) <= 4 * 1024 * 1024,
                    'detail stream bounds exceeded')
            yield json.loads(line)


def address(value):
    require(isinstance(value, str) and re.fullmatch(r'0x[0-9a-f]{8}', value), 'invalid address')
    return value


def graph_target(row, selections):
    """Only explicit saved entry/interior-owner evidence can add a CODE edge."""
    role = CLASSES.get(row['classification'])
    require(role is not None, 'unknown classification requires schema review')
    if role not in ('selected_entry', 'interior_owner_retention'):
        return role, None
    owners = row['code_owners']
    require(not row['code_ownership_ambiguous'] and len(owners) == 1,
            'ambiguous selected CODE evidence')
    owner = owners[0]
    target = address(owner['address'])
    require(target in selections, 'selected target has no selected owner')
    offset = owner['offset']
    require(type(offset) is int and 0 <= offset < selections[target]['size'], 'invalid owner interior')
    require(int(row['exact_original_target_va'], 16) == int(target, 16) + offset,
            'target/owner offset differs')
    if role == 'selected_entry':
        require(offset == 0 and row['selected_address'] == target, 'entry mapping differs')
    else:
        require(offset > 0, 'interior evidence at entry')
    return role, target


def consume_binding(rows, selections, summary):
    fields = defaultdict(list)
    events, classes, kinds, consistency = Counter(), Counter(), Counter(), Counter()
    seen = set()
    sequence = hashlib.sha256()
    last_recipe = -1
    for ordinal, row in enumerate(rows, 1):
        require(ordinal <= 1000000, 'binding row bound')
        src = address(row['function_va'])
        choice = selections.get(src)
        require(choice is not None, 'binding source lacks selected mapping')
        rel = row['coff_relocation']
        width = rel['conservative_extent'] if rel else 4
        require(row['recipe_index'] >= last_recipe, 'binding recipe order differs')
        last_recipe = row['recipe_index']
        require(row['recipe_id'] == choice['recipe_id'] and row['recipe_index'] == choice['recipe_index']
                and row['function_symbol'] == choice['symbol'] and row['physical_section'] == choice['section']
                and row['physical_offset'] == choice['value'] + row['source_field_offset']
                and 0 <= row['source_field_offset'] <= choice['size'] - width
                and int(row['original_field_va'], 16) == int(src, 16) + row['source_field_offset'],
                'binding source/native identity differs')
        require(row.get('runtime_eligible') is False and row.get('provider_selected') is False,
                'binding has runtime approval')
        key = (src, row['event'], row['physical_offset'], None if rel is None else rel['kind'],
               None if rel is None else rel['symbol_index'])
        require(key not in seen, 'duplicate binding field')
        seen.add(key)
        if rel is None:
            require(row['event'] == 'MISSING_ORIGINAL_HIGHLOW_SOURCE_MIGRATION_BLOCKER', 'unknown missing event')
        else:
            require(row['event'] == 'SELECTED_FUNCTION_COFF_RELOCATION', 'unknown relocation event')
            kinds[str(rel['kind'])] += 1
            consistency[row['proof_consistency']] += 1
        role, dest = graph_target(row, selections)
        target = row.get('exact_original_target_va')
        if target is not None:
            address(target)
        h = digest(row)
        sequence.update(canonical([ordinal, h]))
        # Complete source field remains available through exact ordinal/hash.
        fields[src].append((ordinal, h, role, dest, target, row['classification']))
        events[row['event']] += 1
        classes[row['classification']] += 1
    require(dict(events) == summary['events'] and dict(classes) == summary['target_classes']
            and dict(kinds) == summary['relocation_kinds'] and dict(consistency) == summary['proof_consistency'],
            'binding census differs')
    return fields, sequence.hexdigest()


def consume_inventory(rows, selections, fields, summary, sequence):
    assessments = {}
    events = Counter()
    for row in rows:
        events[row['event']] += 1
        if row['event'] != 'SELECTED_CODE_SERIALIZATION_ASSESSMENT':
            require(row['event'] in ('RECIPE_COFF_METADATA', 'RECIPE_EH_EVIDENCE'), 'unknown inventory event')
            continue
        src = address(row['original_address'])
        require(src in selections and src not in assessments, 'duplicate or unselected inventory owner')
        choice, native = selections[src], row['selected_native']
        require(all(native[k] == choice[k] for k in ('symbol', 'section', 'size', 'value'))
                and native['original_address'] == src and row['physical_identity']['recipe_id'] == choice['recipe_id'],
                'inventory selected identity differs')
        require(all(row.get(k) is False for k in FALSE if k in row), 'inventory has runtime approval')
        refs = [dict(ordinal=f[0], sha256=f[1]) for f in fields.get(src, [])]
        require(row['binding_row_references'] == refs, 'inventory field references differ')
        require(row['binding_fields'] + row['original_missing_fields'] == len(refs), 'inventory field count differs')
        assessments[src] = dict(category=row['category'], serialization_candidate=row['serialization_candidate'],
            blocker_codes=sorted({b['code'] for b in row['blockers']}),
            original_missing_fields=row['original_missing_fields'],
            same_parent_piece_observations=row['same_parent_piece_observations'],
            same_parent_false_piece_observations=row['same_parent_false_piece_observations'],
            inventory_row_sha256=digest(row))
    require(set(assessments) == set(selections) and len(assessments) == summary['summary']['selected'],
            'incomplete inventory coverage')
    require(dict(events) == summary['summary']['events'], 'inventory census differs')
    require(summary['binding_provenance']['sequence_sha256'] == sequence, 'inventory binding sequence differs')
    return assessments


def reachable(graph, roots):
    visited, queue = set(roots), deque(roots)
    while queue:
        for dest in sorted(graph[queue.popleft()]):
            if dest not in visited:
                visited.add(dest)
                queue.append(dest)
    return visited


def components(graph, nodes):
    """Iterative Kosaraju: real graphs must not depend on Python recursion depth."""
    visited, order = set(), []
    for start in sorted(nodes):
        if start in visited:
            continue
        visited.add(start)
        stack = [(start, iter(sorted(graph[start] & nodes)))]
        while stack:
            node, children = stack[-1]
            child = next(children, None)
            if child is None:
                order.append(node)
                stack.pop()
            elif child not in visited:
                visited.add(child)
                stack.append((child, iter(sorted(graph[child] & nodes))))
    reverse = defaultdict(set)
    for src in nodes:
        for dest in graph[src] & nodes:
            reverse[dest].add(src)
    assigned, result = set(), []
    for start in reversed(order):
        if start in assigned:
            continue
        group, todo = [], [start]
        assigned.add(start)
        while todo:
            node = todo.pop()
            group.append(node)
            for child in sorted(reverse[node]):
                if child not in assigned:
                    assigned.add(child)
                    todo.append(child)
        result.append(sorted(group))
    return sorted(result, key=lambda group: group[0])


def analyze(selections, fields, assessments, roots):
    require(roots and len(set(roots)) == len(roots), 'roots empty or duplicate')
    require(all(r in selections for r in roots), 'root missing selected source mapping')
    graph, entry_graph = defaultdict(set), defaultdict(set)
    for src, values in fields.items():
        for _, _, role, dest, _, _ in values:
            if dest is not None:
                graph[src].add(dest)
                if role == 'selected_entry':
                    entry_graph[src].add(dest)
    nodes = reachable(graph, roots)
    entry_nodes = reachable(entry_graph, roots)
    sccs = components(graph, nodes)
    roles, targets, edge_counts, categories, blockers = Counter(), defaultdict(set), Counter(), Counter(), Counter()
    for src in nodes:
        categories[assessments[src]['category']] += 1
        blockers.update(assessments[src]['blocker_codes'])
        for _, _, role, dest, target, _ in fields.get(src, []):
            roles[role] += 1
            if target is not None:
                targets[role].add(target)
            if dest is not None:
                edge_counts[(src, dest, role)] += 1
    cyclic = [g for g in sccs if len(g) > 1 or g[0] in graph[g[0]]]
    return dict(roots=roots, selected_universe=len(selections), reachable_selected_owners=len(nodes),
        entry_edge_only_reachable_owners=len(entry_nodes), unreachable_selected_owners=len(selections)-len(nodes),
        observed_field_occurrences=sum(roles.values()), role_occurrences=dict(sorted(roles.items())),
        distinct_ordinary_targets_by_role={k: len(v) for k, v in sorted(targets.items())},
        selected_graph_edges=len(edge_counts), unique_selected_owner_pairs=len({(s,d) for s,d,_ in edge_counts}),
        serialization_categories=dict(sorted(categories.items())), blocker_codes_nonexclusive=dict(sorted(blockers.items())),
        SCC_count=len(sccs), cyclic_SCC_count=len(cyclic), largest_SCC=max(map(len, sccs)),
        reachable_addresses=sorted(nodes), SCCs=sccs,
        edges=[dict(source=s, destination=d, role=r, occurrences=n) for (s,d,r),n in sorted(edge_counts.items())])


def run(args):
    implementation = Path(__file__).resolve()
    implementation_hash = file_hash(implementation)
    require(implementation_hash == args.implementation_sha256, 'observer implementation pin differs')
    paths = {name: Path(getattr(args, name)).resolve() for name in PINS}
    paths.update(binding_details=Path(args.binding_details).resolve(), inventory_details=Path(args.inventory_details).resolve())
    out, detail = Path(args.out).resolve(), Path(args.details_gz).resolve()
    protected = set(paths.values()) | {implementation}
    require(out != detail and not ({out, detail} & protected), 'output/input collision')
    require(not out.exists() and not detail.exists(), 'output already exists')
    before = {k: file_hash(p) for k,p in paths.items()}
    require(all(before[k] == h for k,h in PINS.items()), 'native report pin differs')
    docs = {k: json.loads(paths[k].read_text(encoding='utf-8')) for k in PINS}
    selection, binding, inventory = docs['selection'], docs['binding'], docs['inventory']
    require(binding['inputs']['selection'] == before['selection'] and inventory['inputs']['selection'] == before['selection']
        and inventory['inputs']['binding'] == before['binding'], 'report input join differs')
    for key in ('manifest', 'retained', 'recipes'):
        require(binding['inputs'][key] == inventory['inputs'][key], 'report provenance differs')
    require(before['binding_details'] == binding['details_sha256'] == inventory['input_detail_sha256']['binding']
            and before['inventory_details'] == inventory['details_sha256'], 'compressed detail hash differs')
    require(selection['runtime_eligible'] is False and selection['link_ready'] is False, 'selection promoted')
    selections = selection['selections']
    require(len(selections) == selection['function_addresses'] == binding['summary']['selected_functions'], 'selected census differs')
    fields, sequence = consume_binding(records(paths['binding_details']), selections, binding['summary'])
    assessments = consume_inventory(records(paths['inventory_details']), selections, fields, inventory, sequence)
    result = analyze(selections, fields, assessments, [ENTRY])
    require(all(file_hash(paths[k]) == h for k,h in before.items()), 'input changed during observation')
    require(file_hash(implementation) == implementation_hash, 'observer changed during observation')
    summary = {k:v for k,v in result.items() if k not in ('reachable_addresses', 'SCCs', 'edges')}
    published = []
    try:
        detail.parent.mkdir(parents=True, exist_ok=True)
        with detail.open('xb') as raw:
            published.append(detail)
            with gzip.GzipFile(fileobj=raw, mode='wb', mtime=0) as stream:
                for src in result['reachable_addresses']:
                    row = dict(event='REACHABLE_SELECTED_OWNER', original_address=src, selected=selections[src],
                        assessment=assessments[src], binding_references=[dict(ordinal=f[0],sha256=f[1],role=f[2],
                            selected_owner=f[3],exact_target=f[4],classification=f[5]) for f in fields.get(src,[])], **FALSE)
                    stream.write(canonical(row)+b'\n')
                for edge in result['edges']:
                    stream.write(canonical(dict(event='SELECTED_OWNER_EDGE', **edge))+b'\n')
                for group in result['SCCs']:
                    stream.write(canonical(dict(event='SELECTED_OWNER_SCC',members=group))+b'\n')
            raw.flush()
            os.fsync(raw.fileno())
        require(all(file_hash(paths[k]) == h for k,h in before.items()), 'late input mutation')
        require(file_hash(implementation) == implementation_hash, 'late observer mutation')
        report = dict(schema_version=1, kind='fnv-entry-selected-dependency-observation', status='metadata-only',
            inputs=before, implementation_sha256=implementation_hash, details_sha256=file_hash(detail),
            producer_compilers=inventory['producer_compilers'], source_tools_sha256=inventory['tools_sha256'],
            binding_implementation_sha256=binding['implementation_sha256'],
            summary=summary, binding_row_sequence_sha256=sequence, unchanged_inputs=True,
            limitations=['This is saved selected-CODE field reachability, not complete application execution reachability.',
                'Includes explicit unique interior owner retention; those edges do not approve callable interior ABIs.',
                'Indirect calls, data-held pointers, initialization, callbacks and unselected executable targets remain open.',
                'Boundary classifications are per-use evidence, not provider choices; distinct target counts overlap.',
                'Serialization candidates remain separate from reachability and runtime eligibility.',
                'No source/object/image revalidation, compilation, disassembly, emission, linking or execution.'], **FALSE)
        out.parent.mkdir(parents=True, exist_ok=True)
        with out.open('x', encoding='utf-8') as stream:
            published.append(out)
            json.dump(report, stream, sort_keys=True, separators=(',',':'))
            stream.write('\n')
        return report
    except BaseException:
        for path in published:
            path.unlink(missing_ok=True)
        raise


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    for name in (*PINS, 'binding-details', 'inventory-details', 'out', 'details-gz'):
        parser.add_argument('--'+name, required=True, type=Path)
    parser.add_argument('--implementation-sha256', required=True)
    args = parser.parse_args(argv)
    try:
        result = run(args)
    except (ValueError, OSError, KeyError, TypeError) as error:
        parser.exit(2, 'entry dependency observation rejected: '+str(error)+'\n')
    print(json.dumps(result['summary'], sort_keys=True))
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
