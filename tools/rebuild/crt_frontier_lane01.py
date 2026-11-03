"""Lane 01 named-library metadata and exact-target observation proposal only.

No image access, native process, alias application, or object emission. Output is
private metadata, never an assertion that a source alias identifies a provider.
"""
from __future__ import annotations
import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from compare import Coff
from crt_provider import archive_member

PACKET = '488c95630eba6d549b41c52eabb7617341f2524cee5e4051b22fcff76d33fcfc'
DOCTOR = '9b24d10209fe0361a5e6b16b11a072e8e0ebc6505cd4b5e1bd782fe23854f29f'
LIBS = {'sp1': 'bd9700d126d378f31f32736abc0c88cb08a8e0f0914acb6e2c8cbfd1ab99f411',
        'rtm': 'bd8fe9fa475deb84014af41870182b447bb969c91661d7012ae8d1b26bb6a86c',
        'vc8': '3bc6c5b90f8507964839fd0264d8565c3b766d01f9efcad336532a11e8f06ac3'}
# Explicit hypotheses from this lane's physical aliases, never global lookup.
NAMES = {
 '0x00406d50': ('_strcat_s',),
 '0x00ec7230': ('_memmove', '_memcpy'),
 '0x00ec6cde': ('_fabs',), '0x00ec6e30': ('_strrchr',),
 '0x00ec67aa': ('_tolower', '__tolower'),
 '0x00ec8d5f': ('_strncpy_s',),
 '0x00ec4835': ('_memcmp',), '0x00ec7595': ('__finite',),
 '0x00eca573': ('_atof',), '0x00ec9907': ('_fclose', '__fclose_nolock'),
 '0x00ec30b0': ('__Xlen',), '0x00ec9a47': ('_fopen',),
 '0x00ec62f6': ('__ftol2',), '0x00ecbc5b': ('__strlwr_s',),
 '0x00462d40': ('__splitpath_s',), '0x00ec825b': ('__makepath_s',),
 '0x00ec9650': ('__CIasin',), '0x004b7580': ('_memcpy_s',),
 '0x00ec77e0': ('__allshr',), '0x00ec86e1': ('_isalpha',),
 '0x00ec9610': ('_asin',), '0x00ecadda': ('__time64', '___time64'),
 '0x00ecd291': ('_free',), '0x00ec913a': ('__CIfmod',),
 '0x00eca6bd': ('_atol',), '0x00eccf5d': ('_realloc',),
 '0x00ec8244': ('__mbscmp',), '0x00ecddf1': ('__vsnprintf',),
}

def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()

def check(ok, msg):
    if not ok:
        raise ValueError(msg)

def metadata(library, name):
    payload, identity = archive_member(library, name)
    with tempfile.TemporaryDirectory(prefix='fnv_lane01_metadata_') as folder:
        obj = Path(folder) / 'member.obj'
        obj.write_bytes(payload)
        coff = Coff(obj)
    definition = coff.named(name)
    section = coff.sections[definition['section']]
    check(section['flags'] & 0x20000000, 'named export is not executable')
    raw = section['data']
    fields, masked = [], set()
    for offset, index, kind in section['relocs']:
        check(kind in (6, 20) and 0 <= offset <= len(raw)-4,
              'unsupported or out-of-range relocation')
        check(not masked.intersection(range(offset, offset+4)), 'overlapping field')
        masked.update(range(offset, offset+4))
        fields.append(dict(offset=offset, kind=kind,
            addend=struct.unpack_from('<i', raw, offset)[0],
            symbol_index=index, **coff.symbols[index]))
    peers = [s for s in coff.symbols.values() if
             s['section'] == definition['section'] and s['type'] == 32]
    return dict(export=name, identity=identity, section=definition['section'],
        value=definition['value'], complete_section_size=len(raw),
        complete_section_sha256=hashlib.sha256(raw).hexdigest(),
        nonrelocation_sha256=hashlib.sha256(bytes(b for i,b in enumerate(raw) if i not in masked)).hexdigest(),
        nonrelocation_bytes=len(raw)-len(masked), all_relocations=fields,
        section_function_symbols=peers,
        member_undefineds=sorted({s['name'] for s in coff.symbols.values() if
            s['section'] == 0 and s['storage'] == 2}),
        bounded_comparison_eligible=0 < len(raw) <= 4096,
        symbol_entry_proven=False, original_dependency_identity_proven=False)

def main():
    packet_path = ROOT/'build/rebuild/application-frontier-dispatch-v1/crt-frontier-lane-01.json'
    doctor_path = ROOT/'build/rebuild/doctor-all.json'
    check(sha(packet_path) == PACKET and sha(doctor_path) == DOCTOR, 'input pin differs')
    packet = json.loads(packet_path.read_text())
    doctor = json.loads(doctor_path.read_text())
    libs = {k: Path(doctor['toolchains'][k]['root'])/'VC/lib/libcmt.lib' for k in LIBS}
    for k,p in libs.items():
        check(sha(p) == LIBS[k], 'library pin differs: '+k)
    symbols = sorted({n for ns in NAMES.values() for n in ns})
    records = {}
    for compiler, lib in libs.items():
        for symbol in symbols:
            try:
                records[compiler+':'+symbol] = metadata(lib, symbol)
            except ValueError as error:
                records[compiler+':'+symbol] = dict(export=symbol, unavailable=str(error))
    targets = []
    for target in packet['targets']:
        va = target['original_target']; uses = target['field_uses']
        names = NAMES.get(va, ())
        aliases = sorted({u['coff_relocation']['symbol'] for u in uses})
        paths = sorted({u['source_path'] for u in uses})
        source_records = []
        for path in paths:
            expected = {u['source_sha256'] for u in uses if u['source_path'] == path}
            check(len(expected) == 1 and sha(ROOT/path) in expected, 'source pin differs: '+path)
            # Record input identity, not source bodies or guessed demangling.
            source_records.append(dict(path=path, sha256=next(iter(expected))))
        targets.append(dict(original_target=va, field_count=len(uses),
            physical_aliases=aliases, field_proofs=uses, source_inputs=source_records,
            hypotheses=list(names), members={k:records[k] for k in records
                if k.split(':',1)[1] in names},
            actual_link_unresolved_group_count=len(target['actual_V4_unresolved_groups']),
            disposition='candidate-needs-exact-target-comparison-and-caller-contract' if names else
                        'blocked-no-specific-normal-CRT-provider-evidence',
            provider_selected=False, original_identity_proven=False, ABI_approved=False))
    for k,p in libs.items():
        check(sha(p) == LIBS[k], 'library changed: '+k)
    check(sha(packet_path) == PACKET and sha(doctor_path) == DOCTOR, 'input changed')
    out = ROOT/'build/rebuild/crt-frontier-lane01-metadata-v2.json'
    report = dict(schema_version=1, kind='crt-frontier-lane01-named-member-proposals',
        producer_sha256=sha(__file__), packet_sha256=PACKET, doctor_sha256=DOCTOR,
        library_sha256=LIBS, target_count=len(targets), field_count=sum(t['field_count'] for t in targets),
        targets=targets, original_image_read=False, native_process_invoked=False,
        runtime_eligible=False, provider_selected=False)
    with out.open('x', encoding='utf-8') as stream:
        json.dump(report, stream, indent=2); stream.write('\n')
    print(json.dumps(dict(output=str(out), sha256=sha(out), targets=len(targets),
        fields=report['field_count'], named_symbols=len(symbols))))

if __name__ == '__main__':
    main()
