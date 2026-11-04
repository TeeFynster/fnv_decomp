"""Source-only LIBCPMT roster and separately reviewed exact 19-byte XI probe.

The single remaining XI target is compared only to the three named native
__InitCPLocHash definitions registered in .CRT$XID. No XC, code search,
startup/entry investigation, runtime provider or execution route exists.
"""
from __future__ import annotations
import argparse
import hashlib
import json
import os
from pathlib import Path

import crt_stage_callback_probe as common
import crt_callback_roster as roster_tool
from crt_bootstrap_contract import ArchiveEvidence, file_identity
from data_plan import Pe, file_hash

DOCTOR = common.base.DOCTOR
PRIOR = '290c279d409029dec63dc4d8a6a4ccbb4a34afb7c7c3dcf3240f7543595c5525'
CPP_LIBS = dict(sp1='8acc4d01bf3902fff75f751d8e7a90488d836abdb7ec34eead15713deadcb59a',
    rtm='e310db1d24bbec63f3ff2c64408f425afc30acc506eb032672d54656e210f02a',
    vc8='e1b17cb213bfcf77e3c0988f8cb33ec8be143872d1c52de62c5da07ea1eb8031')
TARGET = 0x00ec3b9a
SYMBOL = '__InitCPLocHash'
BYTES = 19


def require(value, message):
    if not value: raise ValueError(message)


def source_manifest():
    result = common.source_manifest()
    for n in ('tools/rebuild/cpp_crt_callback_probe.py', 'tests/rebuild/test_cpp_crt_callback_probe.py'):
        result[n] = file_hash(common.base.ROOT / n)
    return result


def remaining_XI(prior):
    missing = [row for row in prior['observations'] if row['stage'] == 'xi' and not row['positive_source_patterns']]
    require(len(missing) == 1 and missing[0]['original_target'] == TARGET and
        prior['read_bytes'] == 1754 and prior['runtime_provider_approved'] is False,
        'saved unmatched XI scope differs')
    return missing[0]


def select_candidates(families):
    result = []
    for family, data in families.items():
        slots = [r for r in data['records'] if r['category'] == '.CRT$XID' and r['target_symbol'] == SYMBOL]
        require(len(slots) == 1 and slots[0]['kind'] == 6 and slots[0]['addend'] == 0,
                'named native C-initializer contribution differs')
        slot = slots[0]
        require(len(slot['native_definition_candidates']) == 1, 'ambiguous native callback definition')
        definition = slot['native_definition_candidates'][0]
        require(not definition['errors'] and definition['section_size'] == BYTES and definition['value'] == 0,
                'native full-section callback probe geometry differs')
        identity = dict(family=family, archive_sha256=CPP_LIBS[family],
            member_header_offset=definition['member_header_offset'], symbol_index=definition['symbol_index'])
        result.append(dict(candidate_id=hashlib.sha256(json.dumps(identity, sort_keys=True, separators=(',', ':')).encode()).hexdigest(),
            family=family, symbol=SYMBOL, definition=definition,
            native_origin_slot={k: slot[k] for k in ('category', 'section', 'offset', 'member_header_offset', 'member_sha256')},
            original_identity_approved=False))
    require(set(families) == set(CPP_LIBS) and len(result) == 3, 'native CPP witness population differs')
    return result


def review_gate(path, expected, sources, catalog_sha256, candidates):
    require(file_hash(path) == expected, 'peer review hash differs')
    r = json.loads(Path(path).read_text())
    require(r.get('kind') == 'fnv-cpp-crt-callback-probe-source-review' and r.get('status') == 'approved' and
        r.get('reviewer') and r.get('sources') == sources and r.get('catalog_sha256') == catalog_sha256 and
        r.get('prior_sha256') == PRIOR and r.get('doctor_sha256') == DOCTOR and r.get('CPP_libraries') == CPP_LIBS and
        r.get('candidate_ids') == sorted(c['candidate_id'] for c in candidates) and
        r.get('reference_sha256') == common.base.REFERENCE and r.get('original_target') == TARGET and
        r.get('read_bytes') == BYTES and r.get('allow_original_code_read') is True and
        r.get('allow_execute') is False and r.get('allow_recursive_probes') is False and
        r.get('XC_targets_in_scope') == 0 and r.get('candidate_only') is True,
        'peer review does not authorize exact native CPP callback probe')


def run(args):
    sources = source_manifest()
    require(file_hash(args.doctor) == DOCTOR and file_hash(args.prior) == PRIOR, 'source input identity differs')
    doctor = json.loads(Path(args.doctor).read_text())
    prior = json.loads(Path(args.prior).read_text())
    remaining_XI(prior)
    libraries, archives = {}, {}
    for family, expected in CPP_LIBS.items():
        path = Path(doctor['toolchains'][family]['root']) / 'VC/lib/libcpmt.lib'
        require(file_hash(path) == expected, 'exact doctor-root LIBCPMT identity differs')
        libraries[family] = (path, expected)
        archives[family] = ArchiveEvidence(file_identity(path))
    if args.mode == 'catalog':
        require(not Path(args.out).exists(), 'catalog output exists')
        families = {family: dict(archive_sha256=CPP_LIBS[family], **roster_tool.roster_for_archive(archive))
                    for family, archive in archives.items()}
        candidates = select_candidates(families)
        result = dict(schema_version=1, kind='fnv-native-cpp-crt-callback-roster', sources=sources,
            doctor_sha256=DOCTOR, prior_sha256=PRIOR, libraries=CPP_LIBS, families=families,
            proposed_original_target=TARGET, proposed_read_bytes=BYTES, candidates=candidates,
            original_image_read=False, library_provider_adopted=False, allow_original_probe=False,
            original_library_version_identity_proven=False, runtime_provider_approved=False)
    else:
        require(args.catalog and args.catalog_sha256 and args.review and args.review_sha256 and args.reference,
                'probe requires peer-reviewed catalog and reference identities')
        require(file_hash(args.catalog) == args.catalog_sha256, 'catalog hash differs')
        catalog = json.loads(Path(args.catalog).read_text())
        require(catalog['sources'] == sources and catalog['libraries'] == CPP_LIBS and
            catalog['original_image_read'] is False, 'catalog source/scope differs')
        candidates = select_candidates(catalog['families'])
        require(candidates == catalog['candidates'], 'catalog candidate linkage differs')
        review_gate(args.review, args.review_sha256, sources, args.catalog_sha256, candidates)
        require(file_hash(args.reference) == common.base.REFERENCE, 'reference differs')
        patterns = {c['candidate_id']: common.load_pattern(archives[c['family']], c) for c in candidates}
        destination = Path(args.out)
        require(not destination.exists(), 'probe output directory exists')
        destination.mkdir()
        def journal(state, **details):
            with (destination / 'progress.jsonl').open('a') as output:
                output.write(json.dumps(dict(state=state, **details), separators=(',', ':')) + '\n')
                output.flush()
                os.fsync(output.fileno())
        journal('started', bytes=BYTES, target=TARGET, XC_targets=0, allow_execute=False)
        pe = None
        try:
            pe = Pe(args.reference)
            require(pe.base == 0x400000 and [s for s in pe.sections if s['name'] == '.text'] == [common.base.TEXT],
                    'pinned text geometry differs')
            lo, hi = pe.base + common.base.TEXT['rva'], pe.base + common.base.TEXT['rva'] + common.base.TEXT['extent']
            require(lo <= TARGET < TARGET + BYTES <= hi, 'exact probe outside allowed text')
            highlow = set(pe.relocations())
            buffer = pe.read_rva(TARGET - pe.base, BYTES, allow_code=True)
            comparisons = [common.compare_buffer(buffer, TARGET, TARGET, c, patterns[c['candidate_id']], pe, highlow)
                           for c in candidates]
            require(file_hash(args.reference) == common.base.REFERENCE and file_hash(args.review) == args.review_sha256 and
                file_hash(args.catalog) == args.catalog_sha256, 'probe input changed')
            result = dict(schema_version=1, kind='fnv-native-cpp-crt-callback-observation', sources=sources,
                doctor_sha256=DOCTOR, prior_sha256=PRIOR, catalog_sha256=args.catalog_sha256,
                review_sha256=args.review_sha256, reference_sha256=common.base.REFERENCE,
                original_target=TARGET, read_bytes=BYTES, comparisons=comparisons,
                original_window_sha256=hashlib.sha256(buffer).hexdigest(), original_identity_approved=False,
                callback_ABI_approved=False, original_startup_reachability_proven=False,
                original_table_bounds_approved=False, runtime_provider_approved=False, executed=False)
        except Exception:
            journal('failed-or-unknown', complete=False)
            raise
        finally:
            if pe is not None: pe.close()
    require(source_manifest() == sources and file_hash(args.doctor) == DOCTOR and file_hash(args.prior) == PRIOR,
            'source metadata inputs changed')
    for path, expected in libraries.values(): require(file_hash(path) == expected, 'native CPP library changed')
    output_path = Path(args.out) if args.mode == 'catalog' else Path(args.out) / 'report.json'
    with output_path.open('x') as output: json.dump(result, output, separators=(',', ':'))
    if args.mode == 'probe': journal('completed', report_sha256=file_hash(output_path), bytes=BYTES)
    return dict(mode=args.mode, original_bytes=0 if args.mode == 'catalog' else BYTES,
                positive_patterns=sum(c['full_nonrelocation_span_equal'] for c in result.get('comparisons', [])),
                runtime_provider_approved=False)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--mode', choices=('catalog', 'probe'), required=True)
    for n in ('doctor', 'prior', 'out'): p.add_argument('--' + n, required=True)
    for n in ('catalog', 'catalog_sha256', 'review', 'review_sha256', 'reference'):
        p.add_argument('--' + n.replace('_', '-'))
    print(json.dumps(run(p.parse_args()), sort_keys=True))


if __name__ == '__main__': main()
