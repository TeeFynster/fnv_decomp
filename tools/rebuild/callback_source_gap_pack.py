"""Saved-metadata source-ownership workpack, never a missing-function claim.

Joins remaining exact targets to address candidates and anchored native section
geometry. Affine section placement is explicitly a hypothesis, not ownership.
No object payload, image, code search, source stub or runtime output is read or
created. Unanchored sections and missing symbol-table details stay limitations.
"""
from __future__ import annotations
import argparse
import bisect
from collections import Counter, defaultdict
import gzip
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
PINS = dict(correspondence='8be8c6647f6019933e967461447790f9fd019c441d74662d3829ca1e6901a3a4',
    selection='48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1',
    manifest='bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb',
    inventory='91cdc91af6530e6e80e2104cdfeb9bd6928e17fa0f75bcf066734985248f1031',
    candidates='d9effec2d39f8bb0d962ae04c7bdec855ae31230be4b247c861075cd0e95d0ad')


def require(value, reason):
    if not value: raise ValueError(reason)


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for part in iter(lambda: stream.read(1024 * 1024), b''): h.update(part)
    return h.hexdigest()


def affine_leads(section, anchors, targets):
    bases = {address - selected['value'] for address, selected in anchors}
    if len(bases) != 1: return [], False
    base = next(iter(bases))
    end = base + section['extent']
    require(base >= 0 and end <= 0x100000000, 'invalid native section geometry hypothesis')
    found = targets[bisect.bisect_left(targets, base):bisect.bisect_left(targets, end)]
    return [dict(original_target=target, native_section=section['index'], native_offset=target - base,
        native_section_extent=section['extent'], selected_anchor_count=len(anchors),
        affine_section_mapping_approved=False, function_symbol_at_offset_verified=False,
        source_ownership_approved=False) for target in found], True


def run(args):
    paths = {name: Path(getattr(args, name)) for name in PINS}
    sources = {n: sha(ROOT / n) for n in ('tools/rebuild/callback_source_gap_pack.py',
                                        'tests/rebuild/test_callback_source_gap_pack.py')}
    for name, path in paths.items(): require(sha(path) == PINS[name], 'input differs: ' + name)
    require(not Path(args.out).exists(), 'output exists')
    correspondence, selection, manifest = [json.loads(paths[name].read_text())
        for name in ('correspondence', 'selection', 'manifest')]
    callbacks = [row for row in correspondence['callbacks'] if row['stage'] == 'xc' and not row['native_source_symbols']]
    targets = sorted(row['original_target_va'] for row in callbacks)
    require(len(targets) == len(set(targets)) == 537, 'remaining conditional XC population differs')
    by_recipe = defaultdict(list)
    for address, selected in selection['selections'].items():
        by_recipe[selected['recipe_id']].append((int(address, 16), selected))
    objects = {unit['recipe_id']: unit for unit in manifest['units']}
    geometry, address_groups, counts = defaultdict(list), defaultdict(list), Counter()
    seen = set()
    with gzip.open(paths['inventory'], 'rt') as stream:
        for line in stream:
            record = json.loads(line)
            if record['event'] != 'RECIPE_COFF_METADATA': continue
            identity = record['recipe_id']
            require(identity in objects and identity not in seen and
                record['object_sha256'] == objects[identity]['object_sha256'], 'native metadata object coverage differs')
            seen.add(identity)
            counts['recipe_metadata_records'] += 1
            if not record['parse_supported']:
                counts['parser_unsupported_objects'] += 1
                continue
            anchors = defaultdict(list)
            for address, selected in by_recipe[identity]: anchors[selected['section']].append((address, selected))
            for section in record['sections']:
                if not section['flags'] & 0x20000020: continue
                if section['index'] not in anchors:
                    counts['unanchored_native_code_sections'] += 1
                    continue
                leads, consistent = affine_leads(section, anchors[section['index']], targets)
                counts['affine_consistent_sections'] += consistent
                counts['nonaffine_sections'] += not consistent
                for lead in leads:
                    geometry[lead['original_target']].append(dict(lead, recipe_id=identity,
                        object_sha256=record['object_sha256']))
    require(len(seen) == len(objects) == 2988, 'incomplete metadata coverage')
    with gzip.open(paths['candidates'], 'rt') as stream:
        for ordinal, line in enumerate(stream):
            row = json.loads(line)
            counts['canonical_address_groups'] += 1
            address = int(row['address'], 16)
            if address in targets: address_groups[address].append(dict(row_ordinal=ordinal, record=row))
    require(counts['canonical_address_groups'] == 91176, 'candidate stream coverage differs')
    work = [dict(stage='xc', original_index=row['index'], original_site=row['original_site'],
        original_target_va=row['original_target_va'], exact_address_candidates=address_groups[row['original_target_va']],
        unapproved_native_section_geometry_leads=geometry[row['original_target_va']],
        instruction_boundary_proven=False, callback_extent_known=False, source_identity=None,
        missing_function_claim=False, allow_original_code_read=False, allow_stub_or_original_address_fallback=False,
        runtime_provider_approved=False) for row in callbacks]
    for name, path in paths.items(): require(sha(path) == PINS[name], 'input changed: ' + name)
    require(sources == {n: sha(ROOT / n) for n in sources}, 'source changed')
    result = dict(schema_version=1, kind='fnv-conditional-callback-source-workpack', inputs=PINS, sources=sources,
        summary=dict(callback_targets=537, with_exact_address_candidates=sum(bool(row['exact_address_candidates']) for row in work),
            with_native_geometry_leads=sum(bool(row['unapproved_native_section_geometry_leads']) for row in work), **dict(counts)),
        callbacks=work, limitations=['Only section geometry is saved; full unbound symbol tables are not present here',
            'An unanchored native section may contain relevant source, but has no verified original address',
            'No geometry/name failure proves source absence, missing functions, valid entries or startup reachability'],
        original_image_read=False, object_payload_read=False, code_search_performed=False,
        callback_identity_closed=False, source_or_registration_emitted=False, runtime_provider_approved=False)
    with Path(args.out).open('x') as output: json.dump(result, output, separators=(',', ':'))
    return result['summary']


def main():
    p = argparse.ArgumentParser(description=__doc__)
    for name in list(PINS) + ['out']: p.add_argument('--' + name, required=True)
    print(json.dumps(run(p.parse_args()), sort_keys=True))


if __name__ == '__main__': main()
