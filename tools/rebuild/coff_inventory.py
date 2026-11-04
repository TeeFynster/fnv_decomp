#!/usr/bin/env python3
"""Private, evidence-only link inventory of retained i386 COFF objects.

No game image, instruction decoding, linking, source rewriting or provider guessing.
Unlike the comparison parser, this preserves auxiliary entries and storage classes.
"""
from __future__ import annotations

import argparse
from collections import Counter, defaultdict
import gzip
import hashlib
import json
from pathlib import Path
import re
import struct
import time

COMDAT = 0x1000
SELECTIONS = {0: "none", 1: "no_duplicates", 2: "any", 3: "same_size",
              4: "exact_match", 5: "associative", 6: "largest", 7: "newest"}
RELOCATIONS = {0: "ABSOLUTE", 1: "DIR16", 2: "REL16", 6: "DIR32",
               7: "DIR32NB", 9: "SEG12", 10: "SECTION", 11: "SECREL",
               12: "TOKEN", 13: "SECREL7", 20: "REL32"}


class CoffError(ValueError):
    pass


def peak_memory_bytes():
    """Process peak RSS/working set, for private resource evidence only."""
    try:
        import os
        if os.name == 'nt':
            import ctypes
            from ctypes import wintypes
            class Counters(ctypes.Structure):
                _fields_ = [('cb', wintypes.DWORD), ('faults', wintypes.DWORD)] + [
                    (name, ctypes.c_size_t) for name in ('peak', 'working', 'peak_paged',
                    'paged', 'peak_nonpaged', 'nonpaged', 'pagefile', 'peak_pagefile')]
            counters = Counters()
            counters.cb = ctypes.sizeof(counters)
            if ctypes.windll.psapi.GetProcessMemoryInfo(ctypes.c_void_p(-1),
                    ctypes.byref(counters), counters.cb):
                return counters.peak
        else:
            import resource
            import sys
            amount = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
            return amount if sys.platform == 'darwin' else amount * 1024
    except (AttributeError, OSError, ImportError):
        pass
    return None


class Coff:
    """Bounds-checked standard COFF reader; rejects bigobj and archive inputs."""
    def __init__(self, path):
        self.data = Path(path).read_bytes()
        machine, count, _, symptr, symcount, opts, _ = self.unpack('<HHIIIHH', 0)
        if machine != 0x14c or opts:
            raise CoffError('expected standard i386 COFF (not PE, bigobj or archive)')
        self.take(20, count * 40)
        if symcount and not symptr:
            raise CoffError('symbol count with no symbol table')
        self.take(symptr, symcount * 18)
        if symptr:
            strptr = symptr + symcount * 18
            strlen, = self.unpack('<I', strptr)
            if strlen < 4:
                raise CoffError('invalid string table length')
            self.strings = self.take(strptr, strlen)
        else:
            self.strings = b'\x04\0\0\0'
        self.sections = {}
        for i in range(count):
            name, _, _, size, raw, relptr, _, relcount, _, flags = self.unpack(
                '<8sIIIIIIHHI', 20 + i * 40)
            name = name.rstrip(b'\0')
            if name.startswith(b'/'):
                try:
                    section_name = self.string(int(name[1:]))
                except ValueError as exc:
                    raise CoffError('invalid long section name') from exc
            else:
                section_name = name.decode('utf-8', errors='replace')
            payload = self.take(raw, size) if raw else b''
            reloc_start = 0
            if flags & 0x1000000:
                if relcount != 0xffff or not relptr:
                    raise CoffError('invalid extended relocation table')
                total, marker_symbol, marker_type = self.unpack('<IIH', relptr)
                if total < 1 or marker_symbol or marker_type:
                    raise CoffError('invalid extended relocation marker')
                relcount, reloc_start = total, 1
            if relcount and not relptr:
                raise CoffError('relocations without table pointer')
            self.take(relptr, relcount * 10)
            self.sections[i + 1] = dict(index=i + 1, name=section_name, size=size,
                flags=flags, comdat=bool(flags & COMDAT),
                selection=None, association=None,
                payload_sha256=hashlib.sha256(payload).hexdigest(),
                relocs=[self.unpack('<IIH', relptr + j * 10)
                        for j in range(reloc_start, relcount)])
        self.symbols = {}
        i = 0
        while i < symcount:
            rawname, value, section, typ, storage, aux = self.unpack(
                '<8sIhHBB', symptr + i * 18)
            if i + aux >= symcount:
                raise CoffError('auxiliary symbol entries exceed symbol table')
            if section > count or section < -2:
                raise CoffError('symbol has invalid section index')
            name = (self.string(struct.unpack_from('<I', rawname, 4)[0])
                    if rawname[:4] == b'\0' * 4 else
                    rawname.rstrip(b'\0').decode('utf-8', errors='replace'))
            entry = dict(index=i, name=name, value=value, section=section,
                         type=typ, storage=storage, aux_count=aux)
            if aux and storage == 3 and section > 0 and typ == 0 and value == 0:
                # IMAGE_AUX_SYMBOL.Section; not a function's auxiliary record.
                length, nreloc, nline, checksum, assoc, selection, _, high = self.unpack(
                    '<IHHIhBBH', symptr + (i + 1) * 18)
                entry['section_aux'] = dict(length=length, relocation_count=nreloc,
                    checksum=checksum, association=(assoc & 0xffff) | (high << 16),
                    selection=selection)
                sec = self.sections[section]
                if name == sec['name']:
                    sec['selection'] = SELECTIONS.get(selection, f'unknown_{selection}')
                    sec['association'] = entry['section_aux']['association']
            if storage == 105:
                if section != 0 or value or aux != 1:
                    raise CoffError('malformed weak external')
                fallback, search = self.unpack('<II', symptr + (i + 1) * 18)
                entry['weak'] = dict(fallback_index=fallback, search=search)
            self.symbols[i] = entry
            i += 1 + aux
        for entry in self.symbols.values():
            if 'weak' in entry:
                target = self.symbols.get(entry['weak']['fallback_index'])
                if target is None:
                    raise CoffError('weak fallback points outside primary symbols')
                entry['weak']['fallback'] = target['name']
        for sec in self.sections.values():
            for _, index, _ in sec['relocs']:
                if index not in self.symbols:
                    raise CoffError('relocation references absent or auxiliary symbol')
        self.directives = []
        for sec in self.sections.values():
            if sec['name'] == '.drectve':
                # Keep directive evidence without interpreting a linker command line.
                row = self.unpack('<8sIIIIIIHHI', 20 + (sec['index'] - 1) * 40)
                raw = self.take(row[4], row[3]) if row[4] else b''
                self.directives.extend(re.findall(r'(?:[^\s"\x00]+|"[^"]*")+',
                                                  raw.decode('utf-8', errors='replace')))

    def take(self, offset, length):
        if offset < 0 or length < 0 or offset + length > len(self.data):
            raise CoffError('truncated or out-of-bounds COFF record')
        return self.data[offset:offset + length]

    def unpack(self, fmt, offset):
        return struct.unpack(fmt, self.take(offset, struct.calcsize(fmt)))

    def string(self, offset):
        if offset < 4 or offset >= len(self.strings):
            raise CoffError('string table offset outside table')
        end = self.strings.find(b'\0', offset)
        if end < 0:
            raise CoffError('unterminated string table name')
        return self.strings[offset:end].decode('utf-8', errors='replace')


def symbol_kind(symbol):
    if symbol['storage'] == 105:
        return 'weak_external'
    if symbol['storage'] != 2:
        return 'local_or_debug'
    if symbol['section'] > 0:
        return 'external_definition'
    if symbol['section'] == -1:
        return 'absolute_definition'
    if symbol['section'] == 0:
        return 'common_definition' if symbol['value'] else 'undefined_external'
    return 'debug'


def inspect_object(path, unit):
    coff = Coff(path)
    recipe = unit.get('recipe', {})
    addresses = defaultdict(set)
    def normalized_address(value):
        return '0x%08x' % (int(value, 0) if isinstance(value, str) else value)
    for name, address in recipe.get('symbols', {}).items():
        addresses[name].add(normalized_address(address))
    for function in recipe.get('functions', []):
        for name in [function['symbol']] + function.get('fold_aliases', []):
            addresses[name].add(normalized_address(function['address']))

    def address_evidence(name):
        values = sorted(addresses.get(name, ()))
        result = dict(original_addresses=values)
        if len(values) == 1:
            result['original_address'] = values[0]
        return result
    objects = dict(recipe_id=unit['recipe_id'], recipe_index=unit.get('recipe_index'),
                   source=unit.get('source'), sections=[], symbols=[], relocations=[],
                   defined_aliases=[], directives=coff.directives)
    aliases = defaultdict(list)
    for sec in coff.sections.values():
        objects['sections'].append({k: v for k, v in sec.items() if k != 'relocs'})
    for symbol in coff.symbols.values():
        entry = dict(symbol, kind=symbol_kind(symbol))
        entry['import_pointer'] = symbol['name'].startswith(('__imp_', '_imp__'))
        entry.update(address_evidence(symbol['name']))
        if symbol['section'] > 0:
            sec = coff.sections[symbol['section']]
            entry['section_name'] = sec['name']
            entry['comdat'] = sec['comdat']
            entry['selection'] = sec['selection']
            if entry['kind'] == 'external_definition':
                aliases[symbol['section'], symbol['value']].append(symbol['name'])
        objects['symbols'].append(entry)
    for (section, offset), names in aliases.items():
        if len(names) > 1:
            objects['defined_aliases'].append(dict(section=section, offset=offset,
                                                   names=names))
    for sec in coff.sections.values():
        for offset, index, typ in sec['relocs']:
            target = coff.symbols[index]
            target_sec = coff.sections.get(target['section'])
            objects['relocations'].append(dict(section=sec['index'], offset=offset,
                relocation_type=RELOCATIONS.get(typ, f'UNKNOWN_{typ}'), type_number=typ,
                target_index=index, target=target['name'], target_kind=symbol_kind(target),
                origin_kind='code' if sec['flags'] & 0x20 else 'data_or_metadata',
                target_section_kind=('code' if target_sec['flags'] & 0x20 else 'data_or_metadata')
                    if target_sec else None,
                import_pointer=target['name'].startswith(('__imp_', '_imp__')),
                **address_evidence(target['name'])))
    return objects


def summarize(objects):
    definitions, references, weaks = defaultdict(list), defaultdict(list), defaultdict(list)
    relocation_references = defaultdict(list)
    for obj in objects:
        for relocation in obj['relocations']:
            if relocation['target_kind'] in ('undefined_external', 'weak_external'):
                relocation_references[relocation['target']].append(dict(
                    recipe_id=obj['recipe_id'], **relocation))
        for symbol in obj['symbols']:
            location = dict(recipe_id=obj['recipe_id'], source=obj['source'], **symbol)
            if symbol['kind'] in ('external_definition', 'absolute_definition', 'common_definition'):
                definitions[symbol['name']].append(location)
            elif symbol['kind'] == 'weak_external':
                weaks[symbol['name']].append(location)
            elif symbol['kind'] == 'undefined_external':
                references[symbol['name']].append(location)
    duplicates = []
    for name, defs in sorted(definitions.items()):
        if len(defs) < 2:
            continue
        if all(d['kind'] == 'common_definition' for d in defs):
            category = 'common_storage_merge_review'
        elif all(d['kind'] == 'external_definition' and d.get('comdat') for d in defs):
            choices = {d.get('selection') for d in defs}
            if 'no_duplicates' in choices:
                category = 'comdat_no_duplicates_conflict'
            elif len(choices) == 1 and choices <= {'any', 'same_size', 'exact_match', 'largest', 'newest', 'associative'}:
                category = 'comdat_policy_review_required'
            else:
                category = 'comdat_incompatible_or_unknown_policy'
        elif all(d['kind'] == 'absolute_definition' for d in defs) and len({d['value'] for d in defs}) == 1:
            category = 'equal_absolute_definitions_review'
        else:
            category = 'multiple_strong_definitions'
        original_addresses = sorted({address for d in defs for address in d.get('original_addresses', [])})
        duplicates.append(dict(name=name, category=category, definitions=defs,
                               original_addresses=original_addresses,
                               multi_address_metadata=len(original_addresses) > 1))
    unresolved = []
    for name, refs in sorted(references.items()):
        if name in definitions:
            continue
        category = ('import_library_provider_required' if name.startswith(('__imp_', '_imp__'))
                    else 'external_provider_not_in_retained_objects')
        unresolved.append(dict(name=name, category=category, references=refs,
                               relocations=relocation_references.get(name, []),
                               weak_fallbacks=weaks.get(name, [])))
    return dict(definition_names=len(definitions), undefined_names=len(references),
                duplicates=duplicates, unresolved=unresolved,
                weak_externals=[dict(name=k, occurrences=v) for k, v in sorted(weaks.items())])


class CompactSummary:
    """Global name index with capped evidence samples, never per-relocation lists."""
    def __init__(self):
        self.definitions = {}
        self.references = {}
        self.weak_count = 0
        self.symbol_kinds = Counter()
        self.relocation_count = 0
        self.directive_counts = Counter()

    def add(self, obj):
        self.directive_counts.update(d.split(':', 1)[0].lower() for d in obj['directives'])
        for symbol in obj['symbols']:
            kind = symbol['kind']
            self.symbol_kinds[kind] += 1
            name = symbol['name']
            if kind in ('external_definition', 'absolute_definition', 'common_definition'):
                entry = self.definitions.setdefault(name, dict(count=0, kinds=set(), selections=set(),
                    all_comdat=True, addresses=set(), values=set(), examples=[]))
                entry['count'] += 1
                entry['kinds'].add(kind)
                entry['selections'].add(symbol.get('selection'))
                entry['all_comdat'] &= bool(symbol.get('comdat'))
                entry['addresses'].update(symbol['original_addresses'])
                entry['values'].add(symbol['value'])
                if len(entry['examples']) < 3:
                    entry['examples'].append(dict(recipe_id=obj['recipe_id'], source=obj['source'],
                        index=symbol['index'], section=symbol['section'], value=symbol['value'],
                        kind=kind, selection=symbol.get('selection'),
                        original_addresses=symbol['original_addresses']))
            elif kind == 'undefined_external':
                entry = self.references.setdefault(name, dict(occurrences=0, relocations=0, examples=[]))
                entry['occurrences'] += 1
                if len(entry['examples']) < 3:
                    entry['examples'].append(dict(recipe_id=obj['recipe_id'], index=symbol['index'],
                                                  original_addresses=symbol['original_addresses']))
            elif kind == 'weak_external':
                self.weak_count += 1
        self.relocation_count += len(obj['relocations'])
        for relocation in obj['relocations']:
            if relocation['target_kind'] == 'undefined_external':
                self.references[relocation['target']]['relocations'] += 1

    def result(self):
        duplicates = []
        for name, entry in self.definitions.items():
            if entry['count'] < 2:
                continue
            kinds, selections = entry['kinds'], entry['selections']
            if kinds == {'common_definition'}:
                category = 'common_storage_merge_review'
            elif kinds == {'external_definition'} and entry['all_comdat']:
                if 'no_duplicates' in selections:
                    category = 'comdat_no_duplicates_conflict'
                elif len(selections) == 1 and selections <= {'any', 'same_size', 'exact_match', 'largest', 'newest', 'associative'}:
                    category = 'comdat_policy_review_required'
                else:
                    category = 'comdat_incompatible_or_unknown_policy'
            elif kinds == {'absolute_definition'} and len(entry['values']) == 1:
                category = 'equal_absolute_definitions_review'
            else:
                category = 'multiple_strong_definitions'
            duplicates.append(dict(name=name, category=category, occurrences=entry['count'],
                original_addresses=sorted(entry['addresses']),
                multi_address_metadata=len(entry['addresses']) > 1,
                examples=entry['examples'], examples_truncated=entry['count'] > len(entry['examples'])))
        unresolved = []
        for name, entry in self.references.items():
            if name not in self.definitions:
                unresolved.append(dict(name=name, **entry, category='import_library_provider_required'
                    if name.startswith(('__imp_', '_imp__')) else 'external_provider_not_in_retained_objects'))
        categories = dict(Counter(d['category'] for d in duplicates))
        unresolved_categories = dict(Counter(d['category'] for d in unresolved))
        return dict(format='compact-aggregate-with-bounded-examples',
            symbol_kinds=dict(self.symbol_kinds), relocation_count=self.relocation_count,
            definition_names=len(self.definitions), undefined_names=len(self.references),
            weak_external_occurrences=self.weak_count, directive_counts=dict(self.directive_counts),
            duplicate_name_count=len(duplicates), duplicate_categories=categories,
            multi_address_duplicate_count=sum(d['multi_address_metadata'] for d in duplicates),
            duplicate_examples=sorted(duplicates, key=lambda d: (-d['occurrences'], d['name']))[:100],
            unresolved_name_count=len(unresolved), unresolved_categories=unresolved_categories,
            unresolved_with_relocations=sum(bool(d['relocations']) for d in unresolved),
            unresolved_examples=sorted(unresolved, key=lambda d: (-d['relocations'], d['name']))[:100])


def reconcile_recipes(manifest, recipe_path):
    """Verify exact recipe coverage independently of the builder declaration."""
    if recipe_path is None:
        return dict(verified=False, errors=['authoritative recipe manifest not supplied'])
    path = Path(recipe_path)
    data = path.read_bytes()
    recipes = json.loads(data.decode('utf-8-sig'))['units']
    errors = []
    digest = hashlib.sha256(data).hexdigest()
    if manifest.get('recipe_manifest_sha256') != digest:
        errors.append('recipe manifest fingerprint mismatch')
    seen = set()
    for unit in manifest['units']:
        index = unit.get('recipe_index')
        if type(index) is not int or index < 0 or index >= len(recipes):
            errors.append('invalid recipe_index for ' + unit['recipe_id'])
            continue
        if index in seen:
            errors.append('duplicate recipe_index: ' + str(index))
        seen.add(index)
        expected = recipes[index]
        canonical = json.dumps(expected, sort_keys=True, separators=(',', ':'),
                               ensure_ascii=True).encode('ascii')
        identity = '%04d-%s' % (index, hashlib.sha256(canonical).hexdigest()[:16])
        if unit['recipe_id'] != identity or unit.get('recipe') != expected:
            errors.append('recipe metadata or identity mismatch at index ' + str(index))
        if unit.get('source') != expected['source'] or unit.get('compiler') != expected['compiler']:
            errors.append('source/compiler mismatch at index ' + str(index))
    missing = sorted(set(range(len(recipes))) - seen)
    if missing:
        errors.append('missing recipe indices')
    return dict(verified=not errors, authoritative_recipe_count=len(recipes),
                authoritative_recipe_sha256=digest, missing_recipe_indices=missing, errors=errors)


def inventory(manifest_path, recipe_path=None, *, compact=False, detail_stream=None):
    manifest_path = Path(manifest_path)
    manifest = json.loads(manifest_path.read_text(encoding='utf-8-sig'))
    if manifest.get('schema_version') != 1 or manifest.get('kind') != 'fnv-retained-objects':
        raise ValueError('expected fnv-retained-objects manifest schema_version 1')
    if not isinstance(manifest.get('units'), list) or not manifest['units']:
        raise ValueError('expected nonempty retained-object units list')
    objects, errors, omitted = [], [], []
    compact_summary = CompactSummary() if compact else None
    retained_count = 0
    seen = set()
    seen_paths = set()
    for unit in manifest['units']:
        identity = unit['recipe_id']
        if identity in seen:
            raise ValueError('duplicate recipe_id: ' + identity)
        seen.add(identity)
        if unit['status'] != 'compiled':
            omitted.append(dict(recipe_id=identity, status=unit['status']))
            continue
        try:
            path = manifest_path.parent / manifest.get('object_root_relative', '.') / unit['object']
            resolved = path.resolve()
            if resolved in seen_paths:
                raise CoffError('compiled recipes reuse the same retained object path')
            seen_paths.add(resolved)
            if hashlib.sha256(path.read_bytes()).hexdigest() != unit['object_sha256']:
                raise CoffError('retained object hash does not match manifest')
            obj = inspect_object(path, unit)
            retained_count += 1
            if detail_stream is not None:
                detail_stream.write(json.dumps(obj, separators=(',', ':')) + '\n')
            if compact:
                compact_summary.add(obj)
            else:
                objects.append(obj)
        except (OSError, ValueError, struct.error) as exc:
            errors.append(dict(recipe_id=identity, error=str(exc)))
    return dict(schema_version=1, kind='fnv-coff-link-inventory',
        scope='retained objects only; not a link or a matching verdict',
        supplied_manifest_complete=not errors and not omitted,
        recipe_selection=manifest.get('selection'),
        full_recipe_coverage_declared=manifest.get('selection', {}).get('complete', False),
        recipe_reconciliation=reconcile_recipes(manifest, recipe_path),
        recipe_manifest_sha256=manifest.get('recipe_manifest_sha256'),
        retained_manifest_sha256=hashlib.sha256(manifest_path.read_bytes()).hexdigest(),
        retained_object_count=retained_count, manifest_recipe_count=len(manifest['units']),
        errors=errors, omitted=omitted,
        summary=compact_summary.result() if compact else summarize(objects), objects=objects)


def main():
    started = time.perf_counter()
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--manifest', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True, help='private JSON report path')
    parser.add_argument('--require-full', action='store_true',
                        help='fail unless --recipes independently proves full recipe coverage')
    parser.add_argument('--recipes', type=Path,
                        help='authoritative build/units.json for exact coverage reconciliation')
    parser.add_argument('--detail-gzip', type=Path,
                        help='optional private gzip NDJSON stream of complete per-object evidence')
    parser.add_argument('--full-detail-json', action='store_true',
                        help='legacy large JSON format; retains the full graph in memory')
    args = parser.parse_args()
    document = json.loads(args.manifest.read_text(encoding='utf-8-sig'))
    protected = {args.manifest.resolve()}
    if args.recipes:
        protected.add(args.recipes.resolve())
    base = args.manifest.parent / document.get('object_root_relative', '.')
    protected.update((base / unit['object']).resolve() for unit in document.get('units', [])
                     if 'object' in unit)
    del document
    if args.out.resolve() in protected or (args.detail_gzip and args.detail_gzip.resolve() in protected):
        parser.error('--out must not overwrite the retained manifest or any retained object')
    if args.detail_gzip and args.detail_gzip.resolve() == args.out.resolve():
        parser.error('--detail-gzip and --out must be different files')
    if args.out.exists() or (args.detail_gzip and args.detail_gzip.exists()):
        parser.error('outputs must be new paths; existing evidence will not be overwritten')
    if args.detail_gzip:
        args.detail_gzip.parent.mkdir(parents=True, exist_ok=True)
        created = False
        try:
            with gzip.open(args.detail_gzip, 'xt', encoding='utf-8') as stream:
                created = True
                report = inventory(args.manifest, args.recipes, compact=not args.full_detail_json,
                                   detail_stream=stream)
        except (OSError, ValueError, KeyError, TypeError):
            if created:
                args.detail_gzip.unlink(missing_ok=True)
            raise
        if report['errors'] or report['omitted']:
            args.detail_gzip.unlink(missing_ok=True)
    else:
        report = inventory(args.manifest, args.recipes, compact=not args.full_detail_json)
    report['resource_evidence'] = dict(elapsed_seconds=round(time.perf_counter() - started, 3),
                                     peak_process_memory_bytes=peak_memory_bytes())
    args.out.parent.mkdir(parents=True, exist_ok=True)
    with args.out.open('x', encoding='utf-8') as stream:
        stream.write(json.dumps(report, indent=2) + '\n')
    print(json.dumps(dict(retained_objects=report['retained_object_count'],
        errors=len(report['errors']), omitted=len(report['omitted']),
        duplicate_names=report['summary'].get('duplicate_name_count', len(report['summary'].get('duplicates', []))),
        unresolved_names=report['summary'].get('unresolved_name_count', len(report['summary'].get('unresolved', []))))))
    incomplete = args.require_full and not report['recipe_reconciliation']['verified']
    if args.recipes and not report['recipe_reconciliation']['verified']:
        incomplete = True
    return 1 if report['errors'] or report['omitted'] or incomplete else 0


if __name__ == '__main__':
    raise SystemExit(main())
