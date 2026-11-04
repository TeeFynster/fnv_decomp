"""Serial manifest-only inventory of every retained object's CRT metadata.

No game image, directory walk, compiler, linker, registration or execution.
Null, unbound, variant and malformed slots remain explicit observations.
"""
from __future__ import annotations
import argparse
from collections import Counter
import gzip
import hashlib
import json
from pathlib import Path
import struct

from coff_inventory import Coff
from data_plan import file_hash
from game_initializers import PINS

ROOT = Path(__file__).resolve().parents[2]
SOURCES = ('tools/rebuild/game_crt_inventory.py', 'tests/rebuild/test_game_crt_inventory.py',
           'tools/rebuild/coff_inventory.py', 'tools/rebuild/data_plan.py',
           'tools/rebuild/game_initializers.py')


def require(value, message):
    if not value:
        raise ValueError(message)


def source_manifest():
    return {name: file_hash(ROOT / name) for name in SOURCES}


def observe_object(coff, unit, selections):
    bindings = dict(unit['recipe']['symbols'])
    for function in unit['recipe']['functions']:
        for name in [function['symbol']] + function.get('fold_aliases', []):
            bindings[name] = function['address']
    sections = []
    for section in coff.sections.values():
        if section['name'] != '.CRT' and not section['name'].startswith('.CRT$'):
            continue
        raw = struct.unpack_from('<I', coff.data, 20 + (section['index'] - 1) * 40 + 20)[0]
        payload = coff.take(raw, section['size']) if raw else b''
        relocations = []
        for offset, index, kind in section['relocs']:
            symbol = coff.symbols[index]
            errors, addend, target, selected = [], None, None, None
            if kind != 6:
                errors.append('not a DIR32 pointer relocation')
            if offset % 4 or not 0 <= offset <= section['size'] - 4:
                errors.append('not one aligned complete pointer slot')
            if 0 <= offset <= len(payload) - 4:
                addend = struct.unpack_from('<i', payload, offset)[0]
                if addend:
                    errors.append('nonzero/interior addend needs separate proof')
            else:
                errors.append('relocation field lacks native raw storage')
            bound = bindings.get(symbol['name'])
            if bound is not None and addend is not None and kind == 6:
                target = (int(bound, 0) + addend) & 0xffffffff
                selected = selections.get('0x%08x' % target)
            if symbol['type'] != 32 or symbol['section'] <= 0:
                errors.append('target is not a defined native function')
            physical = bool(selected and selected['recipe_id'] == unit['recipe_id'] and
                selected['section'] == symbol['section'] and selected['value'] == symbol['value'])
            relocations.append(dict(offset=offset, relocation_kind=kind, symbol_index=index,
                symbol=symbol['name'], symbol_type=symbol['type'], symbol_section=symbol['section'],
                symbol_value=symbol['value'], symbol_storage=symbol['storage'],
                source_binding=bound, native_addend=addend, original_target_candidate=target,
                selected_owner=selected, selected_same_physical_location=physical,
                selected_same_symbol=bool(selected and selected['symbol'] == symbol['name']),
                errors=errors, registration_approved=False))
        occupied = Counter(row['offset'] for row in relocations)
        for row in relocations:
            if occupied[row['offset']] != 1:
                row['errors'].append('duplicate relocation at slot')
            if any(other != row['offset'] and abs(other - row['offset']) < 4 for other in occupied):
                row['errors'].append('overlapping relocation field')
        unrelocated = []
        for offset in range(0, section['size'] - 3, 4):
            if not any(offset < other + 4 and other < offset + 4 for other in occupied):
                unrelocated.append(dict(offset=offset,
                    native_zero=payload[offset:offset + 4] == bytes(4),
                    native_raw_backed=offset + 4 <= len(payload)))
        sections.append(dict(index=section['index'], name=section['name'], size=section['size'],
            flags=section['flags'], comdat=section['comdat'], selection=section['selection'],
            association=section['association'], payload_sha256=section['payload_sha256'],
            trailing_partial_bytes=section['size'] % 4, relocations=relocations,
            unrelocated_slots=unrelocated, table_stage_or_original_order_verified=False))
    return dict(recipe_index=unit['recipe_index'], recipe_id=unit['recipe_id'],
        source_sha256=unit['source_sha256'], object_sha256=unit['object_sha256'],
        sections=sections, runtime_provider_approved=False)


def review_gate(path, expected, sources):
    require(file_hash(path) == expected, 'review identity differs')
    review = json.loads(Path(path).read_text())
    require(review.get('kind') == 'fnv-game-crt-inventory-source-review' and
            review.get('status') == 'approved' and review.get('reviewer') and
            review.get('sources') == sources and review.get('allow_metadata_inventory') is True and
            review.get('allow_image_read') is False and review.get('allow_execute') is False and
            review.get('manifest_sha256') == PINS['manifest'], 'review does not authorize exact metadata collector')


def run(args):
    paths = {name: Path(getattr(args, name)) for name in ('manifest', 'selection', 'recipes')}
    sources = source_manifest()
    for name, path in paths.items():
        require(file_hash(path) == PINS[name], 'input differs: ' + name)
    review_gate(args.review, args.review_sha256, sources)
    manifest, selection, recipes = [json.loads(paths[n].read_text())
                                   for n in ('manifest', 'selection', 'recipes')]
    require(len(manifest['units']) == len(recipes['units']) == 2988 and
            manifest['selection']['complete'] is True, 'not the complete exact manifest')
    destination = Path(args.out_dir)
    require(not destination.exists(), 'output directory exists')
    destination.mkdir()
    observed, protected, counts = 0, [], Counter()
    section_names = Counter()
    try:
        with gzip.open(destination / 'details.jsonl.gz', 'xt', encoding='utf-8') as stream:
            for index, unit in enumerate(manifest['units']):
                require(unit['recipe_index'] == index and unit['recipe'] == recipes['units'][index],
                        'recipe identity differs')
                obj = paths['manifest'].parent / unit['object']
                source = Path(args.source_root) / unit['source']
                coff = Coff(obj)
                require(hashlib.sha256(coff.data).hexdigest() == unit['object_sha256'], 'object differs')
                require(file_hash(source) == unit['source_sha256'], 'source differs')
                protected.extend(((obj, unit['object_sha256']), (source, unit['source_sha256'])))
                row = observe_object(coff, unit, selection['selections'])
                stream.write(json.dumps(row, separators=(',', ':')) + '\n')
                observed += 1
                counts['objects'] += 1
                counts['objects_with_CRT'] += bool(row['sections'])
                for section in row['sections']:
                    section_names[section['name']] += 1
                    counts['sections'] += 1
                    counts['relocations'] += len(section['relocations'])
                    counts['unrelocated_slots'] += len(section['unrelocated_slots'])
                    for field in section['relocations']:
                        counts['bound_target_candidates'] += field['original_target_candidate'] is not None
                        counts['selected_same_physical_location'] += field['selected_same_physical_location']
                        counts['relocations_with_issues'] += bool(field['errors'])
        for path, expected in protected:
            require(file_hash(path) == expected, 'protected object/source changed')
        for name, path in paths.items():
            require(file_hash(path) == PINS[name], 'input changed: ' + name)
        require(source_manifest() == sources, 'implementation changed')
        require(file_hash(args.review) == args.review_sha256, 'review changed')
        report = dict(schema_version=1, kind='fnv-all-retained-crt-metadata', status='analysis-only',
            inputs={name: PINS[name] for name in paths}, sources=sources,
            review_sha256=args.review_sha256, summary=dict(counts), section_names=dict(section_names),
            detail_sha256=file_hash(destination / 'details.jsonl.gz'),
            game_image_read=False, original_table_order_verified=False,
            registration_approved=False, runtime_provider_approved=False, executed=False)
        with (destination / 'report.json').open('x', encoding='utf-8') as stream:
            json.dump(report, stream, separators=(',', ':'))
        return report['summary']
    except Exception:
        with (destination / 'failed.json').open('x', encoding='utf-8') as stream:
            json.dump(dict(status='failed', observed_objects=observed,
                           complete=False, runtime_provider_approved=False), stream)
        raise


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('manifest', 'selection', 'recipes', 'source_root', 'review', 'review_sha256', 'out_dir'):
        parser.add_argument('--' + name.replace('_', '-'), required=True)
    print(json.dumps(run(parser.parse_args()), sort_keys=True))


if __name__ == '__main__':
    main()
