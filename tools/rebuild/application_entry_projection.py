"""Bounded application-entry projection, never an executable or runtime provider.

The frozen namespace writer remains unchanged. This separately versioned applier
permits only an exactly certified all-undefined duplicate group for one root.
Operational publication requires independent source review and explicit opt-in.
"""
from __future__ import annotations
import argparse
import json
import os
from pathlib import Path
import struct
import time
import coff_code_archive as coff
import canonical_reference_groups as references
import runtime_code_pool as pool

ROOT = Path(__file__).resolve().parents[2]
POLICY = 'application-entry-unresolved-projection-v1'
OWNED = ('tools/rebuild/application_entry_projection.py',
         'tests/rebuild/test_application_entry_projection.py',
         'runtime/code-pools/application-entry.json', 'docs/rebuild/APPLICATION-ENTRY-PROJECTION.md')
require = coff.require
sha = references.file_hash
digest = references.digest
FALSE = dict(runtime_eligible=False, provider_selected=False, ABI_verified=False, link_ready=False,
             materialization_approved=False, executable_linked=False, native_tools_run=False)


def guarded_namespace(data, plan, certificate):
    """Name-only edit with one same-root, all-undefined duplicate exception."""
    obj = coff.parse(data); symbols = obj['symbols']
    require(certificate['object_sha256'] == coff.digest(data) and
            certificate['kind'] == 'compatible-undefined-reference-certificate-candidate', 'reference object/kind')
    require(certificate['namespace_plan'] == plan and
            certificate['duplicate_undefined_records_retained'] is True and
            certificate['coalescing_allowed'] is False and certificate['relocation_retargeting_allowed'] is False,
            'reference namespace scope differs')
    group = certificate['group']; members = group['members']
    require(group['role'] == 'code' and group['original_base'] == group['original_target'] ==
            group['selected_provider_original_address'], 'mixed reference role/base/provider')
    name = references.canonical(group['selected_provider_identity'])
    require(len(members) >= 2 and members == sorted(set(members)), 'duplicate group members')
    types = set()
    for index in members:
        s = symbols[index]
        require(s['storage'] == 2 and s['section'] == s['value'] == 0 and not s['aux_count'] and
                s['type'] in (0, 32) and not s['name'].startswith(('__imp_', '_imp__')),
                'only compatible ordinary undefined CODE records')
        types.add(s['type'])
    require(len(types) == 1, 'mixed reference type status')
    targets = {}; seen = set()
    for row in plan:
        index = row['physical_index']; new = row['name']
        require(type(index) is int and index in symbols and index not in seen, 'duplicate/absent namespace index')
        require(isinstance(new, str) and new and all(33 <= ord(c) <= 126 for c in new), 'invalid namespace')
        seen.add(index); targets.setdefault(new, []).append(index)
    require(targets.get(name) == members, 'hidden/missing certified duplicate index')
    require(all(len(indices) == 1 or (new == name and indices == members) for new, indices in targets.items()),
            'uncertified duplicate namespace')
    root = certificate['root']; sec = obj['sections'][root['section']]
    physical = sorted([offset, index, kind] for offset, index, kind in sec['relocs'] if index in members)
    require(physical == certificate['exact_fields'] and physical, 'missing/repeated/retargeted group field')
    require({r[1] for r in physical} == set(members), 'unused duplicate group record')
    for offset, _, kind in physical:
        require(kind == 20 and struct.unpack_from('<i', sec['payload'], offset)[0] == 0,
                'duplicate field must remain zero-addend REL32')
    original_names = {s['name'] for s in symbols.values()}
    result = bytearray(data); extra = bytearray(); changed = []; expected = {i: dict(s) for i, s in symbols.items()}
    for row in plan:
        index, new = row['physical_index'], row['name']; source = symbols[index]
        if source['name'] == new:
            continue
        require(source['storage'] in (2, 3) and source['section'] >= 0 and not source['aux_count'],
                'unsupported name-only source record')
        require(new not in original_names, 'preexisting canonical name collision')
        struct.pack_into('<II', result, obj['symbol_pointer'] + 18 * index, 0, obj['string_length'] + len(extra))
        extra += new.encode('ascii') + b'\0'; expected[index]['name'] = new; changed.append(index)
    struct.pack_into('<I', result, obj['string_pointer'], obj['string_length'] + len(extra)); result += extra
    after = coff.parse(bytes(result))
    require(after['symbols'] == expected and after['sections'] == obj['sections'], 'name-only metadata/payload drift')
    allowed = set(range(obj['string_pointer'], obj['string_pointer'] + 4))
    for index in changed:
        allowed.update(range(obj['symbol_pointer'] + 18 * index, obj['symbol_pointer'] + 18 * index + 8))
    require(all(a == b or offset in allowed for offset, (a, b) in enumerate(zip(data, result))),
            'non-name byte changed')
    return bytes(result)


def project(data, closure, reference, policy):
    """Pure synthetic/core transform. Disk driver independently re-observes evidence."""
    require(len(data) <= 16 * 1024 * 1024 and policy['policy_id'] == POLICY and
            policy['object_sha256'] == coff.digest(data), 'policy/object mismatch')
    require(digest(closure) == policy['root_certificate_canonical_sha256'] == reference['root_closure_sha256'] and
            digest(reference) == policy['reference_certificate_canonical_sha256'], 'wrong root/reference certificate')
    require(closure['closure_observed'] is True and closure['graph_observation_complete'] is True and
            closure['root_closure_candidate'] is True and closure['blockers'] == [] and
            closure['full_serialization_eligible'] is False and closure['canonical_namespace_collisions_resolved'] is False,
            'root closure is incomplete or already over-promoted')
    root = reference['root']; require(root == policy['root'], 'different root namespace proof')
    require(len(closure['roots']) == 1 and all(closure['roots'][0][k] == v for k, v in root.items() if k != 'recipe_id'),
            'root-set mismatch')
    require(closure['retained_section_indices'] == policy['retained_sections'] and
            closure['retained_runtime_section_indices'] == policy['runtime_sections'], 'wrong retained/runtime sections')
    require(reference['group']['members'] == policy['reference_members'], 'wrong duplicate group')
    require(len(reference['primary_bijection']) == policy['primary_records'] and
            len(reference['auxiliary_bijection']) == policy['auxiliary_records'], 'physical record census differs')
    require([row[0] for row in reference['primary_bijection']] == closure['retained_primary_indices'],
            'retained symbols are not exact root scope')
    obj = coff.parse(data); keep = closure['retained_primary_indices']; names = reference['namespace_plan']
    require({row['physical_index'] for row in names} == set(keep) and len(names) == len(keep), 'incomplete namespace')
    named = guarded_namespace(data, names, reference)
    conversions = [row['symbol_index'] for row in closure['omitted_definition_conversions']]
    require(not set(conversions).intersection(policy['reference_members']), 'undefined group converted/coalesced')
    output, mapping = coff.serialize(named, policy['retained_sections'], keep, conversions)
    require(sorted([list(row) for row in mapping['symbol_map'].items()]) == reference['primary_bijection'] and
            sorted([list(row) for row in mapping['auxiliary_map'].items()]) == reference['auxiliary_bijection'],
            'serialized primary/aux bijection differs')
    require(len(set(mapping['symbol_map'].values())) == len(keep), 'serialized index coalescing')
    after = coff.parse(output); fields = []
    for old_section in policy['retained_sections']:
        source = obj['sections'][old_section]; projected = after['sections'][mapping['section_map'][old_section]]
        require(projected['payload'] == source['payload'] and projected['flags'] == source['flags'], 'payload/flags drift')
        require(projected['relocs'] == [(offset, mapping['symbol_map'][index], kind)
                for offset, index, kind in source['relocs']], 'physical relocation retargeting')
        fields += [dict(original_section=old_section, offset=offset, physical_symbol_index=index,
                       serialized_symbol_index=mapping['symbol_map'][index], kind=kind,
                       addend_bits=struct.unpack_from('<I', source['payload'], offset)[0])
                   for offset, index, kind in source['relocs']]
    require(len(fields) == policy['relocations'] and
            sum(after['sections'][mapping['section_map'][i]]['size'] for i in policy['runtime_sections']) == policy['code_bytes'],
            'field/code size census differs')
    exported = coff.exports(output); expected_export = next(r['name'] for r in names if r['physical_index'] == root['symbol_index'])
    require(exported == [expected_export], 'extra/unselected export')
    undefined = [dict(physical_index=old, serialized_index=new, name=after['symbols'][new]['name'])
                 for old, new in mapping['symbol_map'].items()
                 if after['symbols'][new]['storage'] == 2 and after['symbols'][new]['section'] == 0]
    require(len(undefined) == policy['undefined_records'] and len({r['name'] for r in undefined}) == policy['undefined_names'],
            'undefined identity census differs')
    archived = coff.archive([(policy['member_name'], output)])
    require(len(output) <= 2 * 1024 * 1024 and len(archived) <= 2 * 1024 * 1024, 'bounded entry output exceeded')
    recovered = coff.read_archive(archived)
    require(recovered['members'] == [(policy['member_name'], output)] and
            recovered['index'] == [(expected_export, policy['member_name'])], 'archive recovery/export mismatch')
    return output, archived, dict(policy_id=POLICY, mapping=mapping, fields=fields, undefined_records=undefined,
        exported_symbols=exported, member_sha256=coff.digest(output), archive_sha256=coff.digest(archived),
        original_field_obligations=closure['references'], original_object_sha256=coff.digest(data),
        root_certificate_canonical_sha256=digest(closure), reference_certificate_canonical_sha256=digest(reference),
        physical_records_preserved=True, duplicate_undefined_records_preserved=True,
        coalescing_performed=False, relocation_retargeting_performed=False, **FALSE)


def save_new(path, value):
    with Path(path).open('x', encoding='utf-8') as target:
        json.dump(value, target, sort_keys=True, separators=(',', ':')); target.write('\n'); target.flush(); os.fsync(target.fileno())


def independent_projection(original_path, projected_path, reference, projection):
    """Check every mapped fact through the separately pinned inventory reader."""
    from coff_rewrite import strict_object
    original, original_symbols_at, _, _ = strict_object(original_path)
    projected, projected_symbols_at, _, _ = strict_object(projected_path)
    require(coff.digest(original.data) == projection['original_object_sha256'] and
            coff.digest(projected.data) == projection['member_sha256'], 'independent object identity differs')
    sm = projection['mapping']['section_map']; ym = projection['mapping']['symbol_map']
    am = projection['mapping']['auxiliary_map']; conversions = set(projection['mapping']['undefined_conversions'])
    require(set(projected.sections) == set(sm.values()) and set(projected.symbols) == set(ym.values()),
            'independent extra/missing section or primary')
    require(sorted([list(row) for row in ym.items()]) == reference['primary_bijection'] and
            sorted([list(row) for row in am.items()]) == reference['auxiliary_bijection'],
            'independent physical mapping differs')
    names = {r['physical_index']: r['name'] for r in reference['namespace_plan']}
    for old, new in sm.items():
        a, b = original.sections[old], projected.sections[new]
        require(all(a[k] == b[k] for k in ('name', 'size', 'flags', 'payload_sha256', 'comdat', 'selection')) and
                b['relocs'] == [(offset, ym[index], kind) for offset, index, kind in a['relocs']],
                'independent section/payload/relocation mismatch')
    for old, new in ym.items():
        a, b = original.symbols[old], projected.symbols[new]
        expected = dict(name=names[old], value=0 if old in conversions else a['value'],
            section=0 if old in conversions else sm.get(a['section'], a['section']), type=a['type'],
            storage=2 if old in conversions else a['storage'], aux_count=a['aux_count'])
        require(all(b[k] == value for k, value in expected.items()), 'independent symbol metadata mismatch')
        before = original.take(original_symbols_at + 18 * (old + 1), a['aux_count'] * 18)
        after = projected.take(projected_symbols_at + 18 * (new + 1), b['aux_count'] * 18)
        # This fixed main has ordinary section auxiliaries and no association.
        require(not a.get('section_aux', {}).get('association') and before == after,
                'independent auxiliary/checksum drift or unsupported association')
    return dict(independent_sections=len(projected.sections), independent_primary_records=len(projected.symbols),
                independent_auxiliary_records=len(am), independent_relocations=sum(len(s['relocs']) for s in projected.sections.values()),
                complete_metadata_and_mapping_match=True)


def main():
    parser = argparse.ArgumentParser(__doc__)
    parser.add_argument('--policy', type=Path, required=True)
    parser.add_argument('--policy-sha256', required=True)
    parser.add_argument('--inputs', type=Path, required=True, help='private JSON paths for exact policy evidence keys')
    parser.add_argument('--review', type=Path, required=True)
    parser.add_argument('--review-sha256', required=True)
    parser.add_argument('--allow-private-emission', action='store_true')
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    require(args.allow_private_emission, 'private emission requires root opt-in and source review')
    require(sha(args.policy) == args.policy_sha256 and sha(args.review) == args.review_sha256, 'stale policy/review')
    policy = json.loads(args.policy.read_text(encoding='utf-8')); review = json.loads(args.review.read_text(encoding='utf-8'))
    sources = {relative: sha(ROOT / relative) for relative in OWNED}
    require(args.policy_sha256 == sources[OWNED[2]], 'policy is not the reviewed owned policy')
    require(review.get('schema_version') == 1 and review.get('kind') == 'application-entry-projection-source-review' and
            review.get('status') == 'approved' and review.get('reviewer') and review.get('allow_private_emission') is True and
            review.get('allow_native') is False and review.get('sources') == sources and
            review.get('evidence_sha256') == policy['evidence_sha256'], 'unapproved source/evidence review')
    paths = {key: Path(value).resolve() for key, value in json.loads(args.inputs.read_text(encoding='utf-8')).items()}
    require(set(paths) == set(policy['evidence_sha256']), 'complete exact evidence paths required')
    observations = {path: policy['evidence_sha256'][key] for key, path in paths.items()}
    observations.update({ROOT / relative: value for relative, value in sources.items()})
    observations.update({args.review.resolve(): args.review_sha256, args.policy.resolve(): args.policy_sha256,
                         args.inputs.resolve(): sha(args.inputs)})
    for relative, value in policy['producer_sha256'].items(): observations[ROOT / relative] = value
    references.verify_stable(observations); references.require_index_absent(ROOT)
    out = args.out.resolve()
    private = (ROOT / 'build/rebuild').resolve()
    require(out != private and out.is_relative_to(private) and not out.exists(), 'fresh private output directory required')
    out.mkdir(parents=True)
    for relative in OWNED:
        with (out / Path(relative).name).open('xb') as target: target.write((ROOT / relative).read_bytes())
    result = dict(schema_version=1, kind='application-entry-projection-receipt', status='error', emission_performed=False,
                  policy_sha256=args.policy_sha256, source_review_sha256=args.review_sha256, **FALSE)
    start = time.monotonic()
    with (out / 'progress.jsonl').open('x', encoding='utf-8') as journal:
        def note(value): journal.write(json.dumps(value) + '\n'); journal.flush(); os.fsync(journal.fileno())
        note(dict(state='started',policy_id=POLICY))
        try:
            root_review = json.loads(paths['root_review'].read_text(encoding='utf-8'))
            require(root_review['accepted'] is True and root_review['summary_sha256'] == policy['evidence_sha256']['root_report'] and
                    root_review['detail_sha256'] == policy['evidence_sha256']['root_details'], 'root outcome review differs')
            certificate = json.loads(paths['reference_certificate'].read_text(encoding='utf-8'))
            reference_receipt = json.loads(paths['reference_receipt'].read_text(encoding='utf-8'))
            require(reference_receipt['status'] == 'candidate-certificate-observed' and
                    reference_receipt['certificate_sha256'] == policy['evidence_sha256']['reference_certificate'] and
                    reference_receipt['root_outcome_review_sha256'] == policy['evidence_sha256']['root_review'] and
                    reference_receipt['input_stability_verified'] is True, 'reference outcome binding differs')
            current = references.observe_main({key: paths[key] for key in references.MAIN_PINS}, paths['root_report'],
                policy['evidence_sha256']['root_report'], paths['root_details'], policy['evidence_sha256']['root_details'])
            require(digest(current) == digest(certificate) == policy['reference_certificate_canonical_sha256'],
                    'reference certificate recomputation differs')
            closures = [row for _, row in references.records(paths['root_details']) if row['recipe_id'] == policy['root']['recipe_id']]
            require(len(closures) == 1, 'root certificate count'); closure = closures[0]
            data = paths['object'].read_bytes()
            member, archive, projection = project(data, closure, certificate, policy)
            note(dict(state='projected-in-memory', member_sha256=projection['member_sha256']))
            # A separately scoped unchanged oracle lane; no compiler/native process.
            manifest = json.loads(paths['manifest'].read_text(encoding='utf-8'))
            unit = next(r['recipe'] for r in manifest['units'] if r['recipe_id'] == policy['root']['recipe_id'])
            selected = dict(symbol=next(r['symbol'] for r in closure['roots']), original_address=policy['root']['original_address'],
                            symbol_index=policy['root']['symbol_index'], size=policy['code_bytes'])
            contract = dict(selected=selected, fields=[])
            original_before = pool.compare_member(paths['object'], paths['reference'], contract, unit)
            # Persist staged source-built bytes only in this fresh private directory.
            stage = out / policy['member_name']
            with stage.open('xb') as target: target.write(member); target.flush(); os.fsync(target.fileno())
            independent_stage = independent_projection(paths['object'], stage, certificate, projection)
            names = {r['physical_index']: r['name'] for r in certificate['namespace_plan']}
            source_symbols = dict(unit.get('symbols', {}))
            source_symbols[names[policy['root']['symbol_index']]] = policy['root']['original_address']
            for row in closure['references']:
                index = row['symbol_index']; source_symbols[names[index]] = row['original_base']
            canonical_unit = dict(symbols=source_symbols)
            canonical_contract = dict(selected=dict(selected, symbol=names[selected['symbol_index']]), fields=[])
            projected_after = pool.compare_member(stage, paths['reference'], canonical_contract, canonical_unit)
            archive_path = out / 'application-entry.lib'
            with archive_path.open('xb') as target: target.write(archive); target.flush(); os.fsync(target.fileno())
            recovered = coff.read_archive(archive_path.read_bytes()); require(recovered['members'][0][1] == member, 'disk archive recovery')
            recovered_path = out / 'recovered-entry.obj'
            with recovered_path.open('xb') as target: target.write(recovered['members'][0][1]); target.flush(); os.fsync(target.fileno())
            independent_recovered = independent_projection(paths['object'], recovered_path, certificate, projection)
            references.verify_stable(observations); references.require_index_absent(ROOT)
            result.update(status='unresolved-source-entry-projected', projection=projection,
                          comparison_before=original_before, comparison_after=projected_after,
                          independent_stage=independent_stage, independent_recovered=independent_recovered, emission_performed=True,
                          observed_input_sha256={str(path): value for path, value in observations.items()},
                          input_stability_verified=True, native_conformance_verified=False)
            note(dict(state='complete', member_sha256=sha(stage), archive_sha256=sha(archive_path)))
        except Exception as error:
            result['error'] = type(error).__name__ + ': ' + str(error); note(dict(state='failed', error=result['error']))
        result['elapsed_seconds'] = time.monotonic() - start
        save_new(out / 'receipt.json', result)
    print(result['status'])
    if result['status'] == 'error': raise SystemExit(1)


if __name__ == '__main__': main()
