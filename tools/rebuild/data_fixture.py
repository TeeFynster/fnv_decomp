"""Original fixed-layout fixture only: PE data -> symbolic COFF -> normal CRT.

No user-selected PE extraction interface and no game-data approval. Preparation
compiles the three named original sources; execution needs independent review.
"""
from __future__ import annotations
import argparse
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys

import toolchain
from data_plan import Pe, PlanError
from coff_rewrite import strict_object

ROOT = Path(__file__).resolve().parents[2]
SOURCES = [ROOT/'runtime/probes'/n for n in
           ('data_fixture.hpp', 'data_fixture_producer.cpp', 'data_fixture_consumer.cpp')]
TOOLS = [
    Path(__file__), ROOT/'tools/rebuild/toolchain.py', ROOT/'tools/rebuild/data_plan.py',
    ROOT/'tools/rebuild/coff_rewrite.py', ROOT/'tools/rebuild/coff_inventory.py']
POLICY = 'original-data-fixture-v1'
PAYLOAD, ZERO, CALLBACK = '_fixture_payload', '_fixture_zero', '_fixture_callback'
SIZE, ZERO_SIZE = 32, 8192
FIELDS = {16: (PAYLOAD, 10), 20: (CALLBACK, 0)}
COMPILE = ['/nologo', '/c', '/MT', '/Od', '/GS', '/W4']
LINK = ['/nologo', '/machine:x86', '/subsystem:console', '/opt:noref', '/opt:noicf',
        '/safeseh', '/dynamicbase:no', '/fixed:no', '/incremental:no']
EXPECTED = dict(schema=1, scalar_checks=4, byte_checks=8, callback_calls=65,
                zero_checks=8192, write_checks=8192, interior_identity=True)
sha = toolchain.sha256


def require(ok, message):
    if not ok:
        raise ValueError(message)


def save(path, value):
    with Path(path).open('x', encoding='utf-8') as stream:
        json.dump(value, stream, indent=2)
        stream.write('\n')


def map_rows(text):
    rows = {}
    for line in text.splitlines():
        match = re.match(r'^\s+[0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{8})\s+(.+?)\s*$', line)
        if match:
            rows.setdefault(match[1], []).append(dict(address=int(match[2], 16), provider=match[3]))
    return rows


def mapped(rows, name, provider):
    values = rows.get(name, [])
    require(len(values) == 1, 'missing or duplicate map symbol: '+name)
    row = values[0]
    # Exact final object token, with optional linker function flag before it.
    require(row['provider'].split()[-1].lower() == provider.lower(), 'wrong map provider: '+name)
    return row['address']


def expected_payload(interior, callback):
    return struct.pack('<Ii8BIIII', 0x13579bdf, -1234567,
                       3, 17, 29, 43, 59, 71, 89, 101,
                       interior, callback, 0x00401234, 0x2468ace0)


def source_object(path):
    """Check source-emitted ownership, fixed extent and two semantic fields."""
    coff, _, _, _ = strict_object(path)
    definitions = {}
    for name, size in ((PAYLOAD, SIZE), (ZERO, ZERO_SIZE)):
        matches = [s for s in coff.symbols.values() if s['name'] == name and s['section'] > 0 and s['storage'] == 2]
        require(len(matches) == 1, 'producer definition missing or duplicate')
        symbol = matches[0]
        section = coff.sections[symbol['section']]
        require(not section['flags'] & 0x20000020, 'producer owned range is executable/mixed code')
        require(symbol['value'] + size <= section['size'], 'source-owned extent exceeds object')
        definitions[name] = (symbol, section)
    symbol, section = definitions[PAYLOAD]
    require(symbol['value'] == 0 and section['size'] == SIZE, 'payload source section is not isolated')
    require(len(section['relocs']) == 2, 'source pointer-field evidence differs')
    for offset, index, kind in section['relocs']:
        require(offset in FIELDS and kind == 6, 'unsupported source data relocation')
        require(coff.symbols[index]['name'] == FIELDS[offset][0], 'source relocation target differs')
    return dict(object_sha256=sha(path), symbols={name: dict(section=sec['name'], offset=sym['value'], size=size)
        for name, size in ((PAYLOAD, SIZE), (ZERO, ZERO_SIZE)) for sym, sec in [definitions[name]]})


def loader_bytes(pe, rva, size):
    section = pe.section(rva, size, required=True)
    require(not section['executable'], 'owned range is executable/mixed code')
    offset = rva-section['rva']
    raw_count = max(0, min(size, section['raw_size']-offset))
    data = pe.read_rva(rva, raw_count) if raw_count else b''
    return data + bytes(size-raw_count), size-raw_count


def inspect_data(image, mapfile, provider, base, callback_provider=None, require_zero=True):
    """Read only the two exact original-fixture data ranges and PE metadata."""
    rows = map_rows(Path(mapfile).read_text(encoding='utf-8'))
    addresses = {n: mapped(rows, n, callback_provider or provider if n == CALLBACK else provider)
                 for n in (PAYLOAD, ZERO, CALLBACK)}
    pe = Pe(image)
    try:
        require(pe.base == base, 'unexpected preferred fixture image base')
        require(not pe.directories[9][0], 'TLS is outside this fixture policy')
        ranges = [(addresses[n]-base, addresses[n]-base+size) for n, size in ((PAYLOAD, SIZE), (ZERO, ZERO_SIZE))]
        Pe.nonoverlap(ranges, 'owned fixture ranges')
        for lo, hi in ranges:
            sec = pe.section(lo, hi-lo, required=True)
            require(not sec['executable'] and sec['flags'] & 0x80000000, 'owned data must be writable and non-executable')
            for index, (rva, size) in enumerate(pe.directories):
                if index != 4 and rva:
                    require(hi <= rva or lo >= rva+size, 'owned range intersects PE metadata/IAT/TLS')
        callback_sec = pe.section(addresses[CALLBACK]-base, required=True)
        require(callback_sec['executable'], 'callback map symbol is not source-built code')
        payload, payload_zeros = loader_bytes(pe, ranges[0][0], SIZE)
        require(not payload_zeros, 'initialized payload crosses raw/zero boundary')
        require(payload == expected_payload(addresses[PAYLOAD]+10, addresses[CALLBACK]), 'fixture scalar or pointer values differ')
        zeros, virtual_count = loader_bytes(pe, ranges[1][0], ZERO_SIZE)
        require(zeros == bytes(ZERO_SIZE), 'source zero storage is not loader-zero')
        require(not require_zero or virtual_count > 0, 'fixture has no actual PE virtual-zero storage')
        sites = list(pe.relocations())
        owned_sites = []
        for site in sites:
            for lo, hi in ranges:
                if site < hi and site+4 > lo:
                    require(lo <= site and site+4 <= hi, 'boundary-crossing owned relocation')
                    owned_sites.append(site)
        expected = [ranges[0][0]+off for off in FIELDS]
        require(sorted(owned_sites) == sorted(expected), 'unknown or missing owned pointer relocation')
        return payload, dict(addresses=addresses, image_base=base, owned_ranges=[
            dict(symbol=n, address=addresses[n], size=size, virtual_zero_bytes=z)
            for n, size, z in ((PAYLOAD, SIZE, payload_zeros), (ZERO, ZERO_SIZE, virtual_count))],
            pointer_sites=[dict(offset=off, target=n, addend=addend) for off, (n, addend) in FIELDS.items()],
            unknown_owned_relocations=0, numeric_field_preserved=True)
    finally:
        pe.close()


def coff_bytes(payload):
    """Minimal standard i386 DATA-only writer; no executable content allowed."""
    require(len(payload) == SIZE, 'wrong payload extent')
    normalized = bytearray(payload)
    for offset, (_, addend) in FIELDS.items():
        struct.pack_into('<I', normalized, offset, addend)
    names = [PAYLOAD, ZERO, CALLBACK, '@feat.00']
    strings = bytearray(b'\0\0\0\0')
    symbols = bytearray()
    for name, value, section, typ, storage in [(PAYLOAD, 0, 1, 0, 2), (ZERO, 0, 2, 0, 2),
                                               (CALLBACK, 0, 0, 0x20, 2), ('@feat.00', 1, -1, 0, 3)]:
        encoded = name.encode('ascii')
        if len(encoded) > 8:
            rawname = struct.pack('<II', 0, len(strings))
            strings += encoded+b'\0'
        else:
            rawname = encoded.ljust(8, b'\0')
        symbols += struct.pack('<8sIhHBB', rawname, value, section, typ, storage, 0)
    struct.pack_into('<I', strings, 0, len(strings))
    raw = 100
    reloc = raw+SIZE
    symptr = reloc+20
    header = struct.pack('<HHIIIHH', 0x14c, 2, 0, symptr, len(names), 0, 0)
    sections = struct.pack('<8sIIIIIIHHI', b'.data', 0, 0, SIZE, raw, reloc, 0, 2, 0, 0xc0300040)
    sections += struct.pack('<8sIIIIIIHHI', b'.bss', 0, 0, ZERO_SIZE, 0, 0, 0, 0, 0, 0xc0300080)
    relocs = b''.join(struct.pack('<IIH', off, names.index(target), 6) for off, (target, _) in FIELDS.items())
    return header+sections+normalized+relocs+symbols+strings


def validate_object(path):
    coff, _, _, _ = strict_object(path)
    require([s['name'] for s in coff.sections.values()] == ['.data', '.bss'], 'unexpected emitted sections')
    require(all(not s['flags'] & 0x20000020 for s in coff.sections.values()), 'executable output forbidden')
    require([(s['name'], s['section'], s['value']) for s in coff.symbols.values()] ==
            [(PAYLOAD, 1, 0), (ZERO, 2, 0), (CALLBACK, 0, 0), ('@feat.00', -1, 1)], 'unexpected emitted symbols')
    require(coff.sections[1]['relocs'] == [(16, 0, 6), (20, 2, 6)], 'emitted relocations differ')
    return dict(object_sha256=sha(path), sections=2, code_sections=0, initialized_bytes=SIZE,
                zero_storage_bytes=ZERO_SIZE, relocations=2, undefined_symbols=[CALLBACK])


def prepare(doctor, out):
    doctor, out = Path(doctor).resolve(), Path(out).resolve()
    require(os.name == 'nt' and not out.exists(), 'new native private output directory required')
    require(not os.environ.get('LINK') and not os.environ.get('_LINK_'), 'implicit linker options forbidden')
    tc = json.loads(doctor.read_text())['toolchains']['sp1']
    root, sdk = toolchain.layout(tc['root'])
    cl, link, dump = [root/'VC/bin'/name for name in ('cl.exe', 'link.exe', 'dumpbin.exe')]
    require(tc['ready'] and tc['version'] == toolchain.VERSIONS['sp1'] and
            sha(cl) == tc['cl_sha256'] and sha(link) == tc['link_sha256'], 'doctor compiler identity differs')
    trusted = [cl, link, dump, root/'VC/lib/libcmt.lib', root/'VC/lib/oldnames.lib', sdk/'Lib/kernel32.lib']
    inputs = {str(p.resolve()): sha(p) for p in SOURCES+TOOLS+trusted+[doctor]}
    require(all(out != p and out not in p.parents for p in map(Path, inputs)), 'output/input collision')
    out.mkdir(parents=True)
    commands = []
    def run(command, name):
        commands.append([str(x) for x in command])
        code, text = toolchain.run(command, root, out, timeout=120)
        (out/name).write_text(text, encoding='utf-8')
        require(code == 0, 'native build/inspection failed: '+name)
        return text
    _, banner = toolchain.run([cl], root, out, timeout=30)
    require(re.search(r'Version\s+15\.00\.30729\.01\b', banner), 'compiler version differs')
    producer, consumer, selected = [out/n for n in ('producer.obj', 'consumer.obj', 'selected-data.obj')]
    run([cl]+COMPILE+[SOURCES[1], '/Fo'+str(producer)], 'producer-compile.log')
    object_evidence = source_object(producer)
    producer_exe, producer_map = out/'producer.exe', out/'producer.map'
    run([link]+LINK+['/base:0x400000', '/out:'+str(producer_exe), '/map:'+str(producer_map), producer], 'producer-link.log')
    payload, producer_evidence = inspect_data(producer_exe, producer_map, 'producer.obj', 0x400000)
    with selected.open('xb') as stream:
        stream.write(coff_bytes(payload))
    selected_evidence = validate_object(selected)
    run([dump, '/headers', '/symbols', '/relocations', selected], 'selected-dump.log')
    run([cl]+COMPILE+[SOURCES[2], '/Fo'+str(consumer)], 'consumer-compile.log')
    exe, mp = out/'consumer.exe', out/'consumer.map'
    run([link]+LINK+['/base:0x600000', '/filealign:1024', '/out:'+str(exe), '/map:'+str(mp), consumer, selected], 'consumer-link.log')
    _, linked_evidence = inspect_data(exe, mp, 'selected-data.obj', 0x600000, 'consumer.obj', require_zero=True)
    require(all(linked_evidence['addresses'][n] != producer_evidence['addresses'][n]
                for n in (PAYLOAD, ZERO, CALLBACK)), 'fixture targets did not move')
    imports = run([dump, '/imports', exe], 'consumer-imports.log')
    dlls = re.findall(r'(?im)^\s*([a-zA-Z0-9_.-]+\.dll)\s*$', imports)
    require({s.lower() for s in dlls} == {'kernel32.dll'}, 'unexpected direct imports')
    rows = map_rows(mp.read_text())
    crt = {}
    for name in ('_mainCRTStartup', '_printf', '_exit'):
        values = rows.get(name, [])
        require(len(values) == 1 and 'libcmt:' in values[0]['provider'].lower(), 'normal static CRT provider missing: '+name)
        crt[name] = values[0]
    sysdir = Path(os.environ['SystemRoot'])/'SysWOW64'
    osdeps = {str(sysdir/n): sha(sysdir/n) for n in ('kernel32.dll', 'KernelBase.dll', 'ntdll.dll')}
    artifacts = {str(p): sha(p) for p in out.iterdir() if p.is_file()}
    require(all(sha(p) == h for p, h in inputs.items()), 'input changed during preparation')
    report = dict(schema_version=1, kind='original-data-fixture-prepared', policy=POLICY,
        status='prepared_pending_independent_review', execution_performed=False, inputs=inputs,
        artifacts=artifacts, os_dependencies=osdeps, commands=commands,
        source_object=object_evidence, producer=producer_evidence, selected=selected_evidence,
        consumer=linked_evidence, exe=str(exe), exe_sha256=sha(exe), map=str(mp), map_sha256=sha(mp),
        crt_providers=crt, direct_imports=dlls,
        limits='Original fixed-layout fixture only; no game data. Command observations and hashes do not prove compiler causality or the full transitive OS loader graph.')
    save(out/'prepare.json', report)
    return report


def validate_review(prepared, review, prepare_sha256):
    require(prepared.get('schema_version') == 1 and prepared.get('kind') == 'original-data-fixture-prepared' and
            prepared.get('policy') == POLICY and prepared.get('execution_performed') is False and
            prepared.get('status') == 'prepared_pending_independent_review', 'unrecognized preparation')
    require(review.get('schema_version') == 1 and review.get('kind') == 'original-data-fixture-review' and
            review.get('approved') is True and review.get('prepare_sha256') == prepare_sha256 and
            review.get('reviewer'), 'independent review missing or stale')
    require(review.get('exe_sha256') == prepared['exe_sha256'] and
            review.get('map_sha256') == prepared['map_sha256'], 'review artifacts differ')
    require(all(review.get('checks', {}).get(k) is True for k in
                ('data_ownership', 'linked_fixups', 'virtual_zero', 'normal_crt', 'map_and_imports')), 'review checks incomplete')


def execute(prepared, review, review_sha256, receipt):
    pp, rp, out = [Path(p).resolve() for p in (prepared, review, receipt)]
    require(len({pp, rp, out}) == 3 and not out.exists() and sha(rp) == review_sha256, 'new receipt and exact review required')
    ph = sha(pp)
    p, r = [json.loads(x.read_text()) for x in (pp, rp)]
    validate_review(p, r, ph)
    protected = {**p['inputs'], **p['artifacts'], **p['os_dependencies']}
    require(str(out) not in protected, 'receipt collides with protected input')
    report = dict(schema_version=1, kind='original-data-fixture-execution', status='error',
                  prepare_sha256=ph, review_sha256=review_sha256)
    try:
        require(sha(pp) == ph and sha(rp) == review_sha256 and all(sha(x) == h for x, h in protected.items()), 'reviewed input changed')
        proc = subprocess.run([p['exe']], cwd=pp.parent, stdin=subprocess.DEVNULL,
            stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, errors='replace', timeout=20,
            creationflags=getattr(subprocess, 'CREATE_NO_WINDOW', 0))
        report.update(returncode=proc.returncode, stdout=proc.stdout, stderr=proc.stderr)
        require(proc.returncode == 0 and not proc.stderr and len(proc.stdout.splitlines()) == 1, 'consumer failed')
        observed = json.loads(proc.stdout)
        require(observed == EXPECTED and all(type(observed[k]) is type(v) for k, v in EXPECTED.items()), 'consumer assertions differ')
        report.update(status='pass', observed=observed)
    except (ValueError, OSError, subprocess.TimeoutExpired) as error:
        report['error'] = str(error)
    save(out, report)
    return report


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest='action', required=True)
    prep = sub.add_parser('prepare')
    prep.add_argument('--doctor', type=Path, required=True)
    prep.add_argument('--out', type=Path, required=True)
    exe = sub.add_parser('execute')
    for name in ('prepare', 'review', 'review-sha256', 'receipt'):
        exe.add_argument('--'+name, required=True)
    args = parser.parse_args()
    result = prepare(args.doctor, args.out) if args.action == 'prepare' else execute(args.prepare, args.review, args.review_sha256, args.receipt)
    print(result['status'])
    sys.exit(0 if result['status'] in ('pass', 'prepared_pending_independent_review') else 1)
