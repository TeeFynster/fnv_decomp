"""Original source-authored TLS owner fixture; prepare/review/execute are separate.

No game input, template materialization, object rewriting or generic TLS provider.
"""
from __future__ import annotations
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
from unittest.mock import patch

from coff_inventory import Coff
from data_plan import Pe
from crt_provider import archive_member
from import_plan import parse_imports
import toolchain

ROOT = Path(__file__).resolve().parents[2]
SOURCES = [ROOT/'runtime/probes'/name for name in ('tls_owner_fixture.hpp', 'tls_owner_storage.cpp',
    'tls_owner_callback.cpp', 'tls_owner_main.cpp')]
TOOLS = [Path(__file__), ROOT/'tools/rebuild/coff_inventory.py', ROOT/'tools/rebuild/data_plan.py',
         ROOT/'tools/rebuild/crt_provider.py', ROOT/'tools/rebuild/toolchain.py', ROOT/'tools/compare.py',
         ROOT/'tools/rebuild/import_plan.py', ROOT/'tools/rebuild/runtime_gaps.py',
         ROOT/'tools/build_and_match.py', ROOT/'tools/function_spans.py']
POLICY = 'original-loader-owned-tls-v1'
OWNER = '?fixture_tls@@3UFixtureTlsStorage@@A'
CALLBACK, ENTRY = '_FixtureTlsCallback@12', '_fixture_tls_callback_entry'
INFRA = ('__tls_index', '__tls_start', '__tls_end', '__tls_used', '___xl_a', '___xl_z', '__tls_array')
COMPILE = ['/nologo', '/c', '/MT', '/Od', '/Oy-', '/GS', '/EHsc', '/Gy', '/W4']
LINK = ['/nologo', '/machine:x86', '/subsystem:console', '/opt:noref', '/opt:noicf', '/safeseh',
        '/dynamicbase:no', '/fixed:no', '/incremental:no', '/verbose:lib']
SOURCE_DIRECTIVES = ['/DEFAULTLIB:"uuid.lib"', '/DEFAULTLIB:"uuid.lib"',
                     '/DEFAULTLIB:"LIBCMT"', '/DEFAULTLIB:"OLDNAMES"']
# Explicit imports observed in the hash-bound saved normal CRT/TLS probe,
# plus the exact original-fixture source API additions. No DLL-wide wildcard.
CRT_APIS = frozenset('''CloseHandle CreateEventA CreateFileA CreateThread DeleteCriticalSection
EnterCriticalSection ExitProcess FlushFileBuffers FreeEnvironmentStringsA FreeEnvironmentStringsW
GetACP GetCPInfo GetCommandLineA GetConsoleCP GetConsoleMode GetConsoleOutputCP GetCurrentProcess
GetCurrentProcessId GetCurrentThreadId GetEnvironmentStrings GetEnvironmentStringsW GetExitCodeThread
GetFileType GetLastError GetLocaleInfoA GetModuleFileNameA GetModuleHandleW GetOEMCP GetProcAddress
GetStartupInfoA GetStdHandle GetStringTypeA GetStringTypeW GetSystemTimeAsFileTime GetTickCount
HeapAlloc HeapCreate HeapFree HeapReAlloc HeapSize InitializeCriticalSectionAndSpinCount
InterlockedDecrement InterlockedIncrement IsDebuggerPresent IsValidCodePage LCMapStringA LCMapStringW
LeaveCriticalSection LoadLibraryA MultiByteToWideChar QueryPerformanceCounter RtlUnwind SetEvent
SetFilePointer SetHandleCount SetLastError SetStdHandle SetUnhandledExceptionFilter Sleep
TerminateProcess TlsAlloc TlsFree TlsGetValue TlsSetValue UnhandledExceptionFilter VirtualAlloc
VirtualFree WaitForMultipleObjects WaitForSingleObject WideCharToMultiByte WriteConsoleA
WriteConsoleW WriteFile'''.split())
SOURCE_APIS = frozenset('''CloseHandle CreateEventA CreateThread DuplicateHandle GetCurrentProcess
GetCurrentThreadId GetExitCodeThread GetStdHandle InterlockedExchange InterlockedIncrement
SetErrorMode SetEvent WaitForMultipleObjects WaitForSingleObject WriteFile'''.split())
REQUIRED_APIS = SOURCE_APIS-{'InterlockedExchange', 'InterlockedIncrement'}  # May be compiler intrinsics.
CRT_LIBRARY_SHA256 = 'bd9700d126d378f31f32736abc0c88cb08a8e0f0914acb6e2c8cbfd1ab99f411'
# Independently joined from v2's exact linked map to relocation targets in
# these members of the pinned normal CRT. No wildcard or extra DLL allowance.
REVIEWED_CRT_API_MEMBERS = {
    'CompareStringA': ('a_cmp.obj',), 'CompareStringW': ('a_cmp.obj',),
    'EnumSystemLocalesA': ('getqloc.obj',), 'GetUserDefaultLCID': ('getqloc.obj',),
    'IsValidLocale': ('getqloc.obj',), 'FatalAppExitA': ('mlock.obj',),
    'FreeLibrary': ('rand_s.obj',), 'GetCurrentThread': ('tidtable.obj',),
    'GetDateFormatA': ('strftime.obj',), 'GetTimeFormatA': ('strftime.obj',),
    'GetLocaleInfoW': ('w_loc.obj', 'a_loc.obj'), 'GetTimeZoneInformation': ('tzset.obj',),
    'HeapDestroy': ('heapinit.obj',), 'SetConsoleCtrlHandler': ('winsig.obj',),
    'SetEnvironmentVariableA': ('setenv.obj',)}
EXPECTED = dict(schema=1, constructor=1, destructor=1, threads=2, initial_checks=3, alias_checks=3,
    main_preserved=True, callbacks=5, callbacks_ok=True, indices_ok=True, blocks_distinct=True,
    owner_offset=4, flag_offset=616, context_offset=692, checks_ok=True)
DETACH = dict(schema=1, event='process_detach', checks_ok=True)
sha = toolchain.sha256


def require(ok, message):
    if not ok:
        raise ValueError(message)


def save(path, value):
    with Path(path).open('x', encoding='utf-8') as stream:
        json.dump(value, stream, indent=2)
        stream.write('\n')


def authored_owner():
    data = bytearray(704)
    data[0x264] = 1
    struct.pack_into('<i', data, 0x2b0, 37)
    return bytes(data)


def section_payload(coff, index):
    h = coff.unpack('<8sIIIIIIHHI', 20+(index-1)*40)
    return coff.take(h[4], h[3]) if h[4] else bytes(h[3])


def named(coff, name):
    rows = [s for s in coff.symbols.values() if s['name'] == name]
    require(len(rows) == 1, 'missing or duplicate COFF symbol: '+name)
    return rows[0]


def source_contract(objects):
    """Inspect source-built storage/metadata/TLS sites without modifying objects."""
    result = []
    tls_owners, callbacks = 0, 0
    for label, path in objects.items():
        coff = Coff(path)
        require(coff.directives == SOURCE_DIRECTIVES, 'unknown source linker directive')
        require(not any(s.get('weak') or (s['section'] == 0 and s['value']) for s in coff.symbols.values()), 'weak/common source owner unsupported')
        feature = named(coff, '@feat.00')
        require((feature['section'], feature['value']) == (-1, 1), 'source SafeSEH metadata differs')
        require(not any(s['name'] in INFRA and s['section'] != 0 for s in coff.symbols.values()), 'duplicate TLS infrastructure owner')
        observations, code_sections = [], []
        for sec in coff.sections.values():
            if sec['name'].startswith('.tls'):
                tls_owners += 1
                owner = named(coff, OWNER)
                require(label == 'storage' and sec['name'] == '.tls$' and sec['size'] == 704 and
                        sec['flags'] == 0xc0300040 and not sec['relocs'] and
                        (owner['section'], owner['value'], owner['storage']) == (sec['index'], 0, 2) and
                        section_payload(coff, sec['index']) == authored_owner(), 'authored TLS owner extent/alignment/initial data differs')
            if sec['name'] == '.CRT$XLB':
                callbacks += 1
                entry = named(coff, ENTRY)
                require(label == 'callback' and sec['size'] == 4 and sec['flags'] == 0x40300040 and
                        (entry['section'], entry['value']) == (sec['index'], 0) and
                        [(o, coff.symbols[i]['name'], t) for o, i, t in sec['relocs']] == [(0, CALLBACK, 6)] and
                        section_payload(coff, sec['index']) == bytes(4), 'wrong callback owner/identity')
            elif sec['name'].startswith('.CRT$XL'):
                raise ValueError('second callback sentinel/infrastructure owner')
            if sec['flags'] & 0x20 and sec['size']:
                anchors = [s for s in coff.symbols.values() if s['section'] == sec['index'] and s['type'] & 0x20 and s['value'] == 0]
                require(len(anchors) == 1, 'source code section has ambiguous function anchor')
                require(all(kind in (6, 20, 11) and off+4 <= sec['size'] for off, _, kind in sec['relocs']), 'unknown/crossing source code relocation')
                code_sections.append(dict(function=anchors[0]['name'], section=sec['index'], size=sec['size'], payload_sha256=sec['payload_sha256']))
                tls = [(off, coff.symbols[index], kind) for off, index, kind in sec['relocs']
                       if coff.symbols[index]['name'] in (OWNER, '__tls_index', '__tls_array')]
                if tls:
                    require(len(anchors) == 1, 'TLS code section has ambiguous function anchor')
                    data = section_payload(coff, sec['index'])
                    for off, target, kind in tls:
                        require(off+4 <= sec['size'], 'TLS relocation crosses code boundary')
                        expected_kind = 11 if target['name'] == OWNER else 6
                        require(kind == expected_kind, 'wrong TLS relocation semantics')
                        addend = struct.unpack_from('<I', data, off)[0]
                        require(target['name'] == OWNER or addend == 0, 'nonzero TLS infrastructure addend')
                        require(target['name'] != OWNER or addend < 704, 'TLS owner addend exceeds authored storage')
                        observations.append(dict(function=anchors[0]['name'], offset=off, target=target['name'], kind=kind, addend=addend))
        result.append(dict(name=label, object=str(Path(path).resolve()), object_sha256=sha(path), tls_fields=observations, code_sections=code_sections))
    require(tls_owners == callbacks == 1 and any(r['tls_fields'] for r in result), 'missing/duplicate authored TLS or callback contribution')
    return result


def crt_contract(library):
    require(sha(library) == CRT_LIBRARY_SHA256, 'reviewed whole CRT archive identity differs')
    expected = {'__tls_used': '103a8d4b812cb3a44bb65274690e3d279c4cd73839a42a4de3c3fb73c1f576b3',
                '__tls_array': 'ec20c7c83e332edfc1f2c23e8e31f358f498a18a3af610a00a198cc13a52df7f'}
    result = {}
    for symbol, fingerprint in expected.items():
        data, report = archive_member(library, symbol)
        require(report['member_sha256'] == fingerprint, 'reviewed normal CRT TLS member differs')
        # Parse the selected archive buffer in memory; write no member file.
        with patch.object(Path, 'read_bytes', return_value=data):
            coff = Coff('in-memory-original-crt-member')
        require(named(coff, '@feat.00')['value'] == 1, 'normal CRT SafeSEH feature differs')
        if symbol == '__tls_array':
            s = named(coff, symbol)
            require((s['section'], s['value'], s['storage']) == (-1, 44, 2), 'TLS array is not normal CRT absolute offset')
        else:
            for name, secname, size, flags in [('__tls_start', '.tls', 1, 0xc0100040),
                ('__tls_end', '.tls$ZZZ', 1, 0xc0100040), ('__tls_index', '.bss', 4, 0xc0300080),
                ('___xl_a', '.CRT$XLA', 4, 0x40300040), ('___xl_z', '.CRT$XLZ', 4, 0x40300040)]:
                s = named(coff, name); sec = coff.sections[s['section']]
                require((s['value'], sec['name'], sec['size'], sec['flags']) == (0, secname, size, flags) and
                        not sec['relocs'] and section_payload(coff, sec['index']) == bytes(size), 'normal CRT TLS marker/index contract differs')
            directory = named(coff, '__tls_used'); sec = coff.sections[directory['section']]
            require(sec['size'] == 24 and [(o, coff.symbols[i]['name'], t) for o, i, t in sec['relocs']] ==
                    [(0, '__tls_start', 6), (4, '__tls_end', 6), (8, '__tls_index', 6), (12, '___xl_a', 6)] and
                    struct.unpack('<6I', section_payload(coff, sec['index'])) == (0, 0, 0, 4, 0, 0), 'normal CRT directory/callback contract differs')
        result[symbol] = report
    return result


def map_rows(text):
    result = {}
    for line in text.splitlines():
        m = re.match(r'^\s+[0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{8})\s+(.+?)\s*$', line)
        if m:
            result.setdefault(m[1], []).append(dict(address=int(m[2], 16), provider=m[3]))
    return result


def loader_bytes(pe, address, size):
    rva = address-pe.base
    sec = pe.section(rva, size, required=True)
    offset = rva-sec['rva']
    raw = max(0, min(size, sec['raw_size']-offset))
    return (pe.read_rva(rva, raw) if raw else b'')+bytes(size-raw)


def include_paths(text, roots):
    paths = set()
    for line in text.splitlines():
        match = re.match(r'^\s*Note: including file:\s*(.+?)\s*$', line)
        if match:
            path = Path(match[1]).resolve()
            require(path.is_file() and any(path.is_relative_to(root) for root in roots), 'included header escapes approved source/VC/SDK roots')
            paths.add(path)
    require(paths and len(paths) <= 4096, 'missing/oversized actual include trace')
    return sorted(paths)


def check_stable(inputs):
    require(all(sha(path) == digest for path, digest in inputs.items()), 'compiler/header/protected input changed')


def validate_imports(records):
    names = []
    for record in records:
        identity = record['export']
        require(record['dll'].lower() == 'kernel32.dll' and identity['kind'] == 'name' and
                identity['name'] in CRT_APIS | SOURCE_APIS | REVIEWED_CRT_API_MEMBERS.keys(), 'unexpected fixture DLL/API/ordinal import')
        names.append(identity['name'])
    require(len(names) == len(set(names)) and REQUIRED_APIS <= set(names), 'missing/duplicate source-required API import')
    return sorted(names)


def reviewed_crt_import_members(apis, rows):
    providers = {v['provider'].split()[-1].lower() for values in rows.values() for v in values}
    result = {}
    for api in set(apis) & REVIEWED_CRT_API_MEMBERS.keys():
        present = [name for name in REVIEWED_CRT_API_MEMBERS[api] if 'libcmt:'+name in providers]
        require(present, 'reviewed API CRT member absent from actual map: '+api)
        result[api] = present
    return result


def export_table(path):
    """Read only bounded i386 PE export metadata; never load a DLL or read code."""
    fingerprint = sha(path)
    pe = Pe(path)
    try:
        # OS linkers may merge export metadata into an executable section.
        # Read only directory/table/string locations, never export code bodies.
        def metadata(rva, size):
            return pe.read_rva(rva, size, allow_code=True)
        def text(rva):
            result = bytearray()
            for i in range(512):
                value = metadata(rva+i, 1)[0]
                if value == 0:
                    require(result, 'empty OS export string')
                    return result.decode('ascii')
                require(32 <= value <= 126, 'non-ASCII OS export string')
                result.append(value)
            raise ValueError('unterminated OS export string')
        rva, size = pe.directories[0]
        require(40 <= size <= 4*1024*1024, 'OS export directory missing/oversized')
        header = struct.unpack('<IIHHIIIIIII', metadata(rva, 40))
        ordinal_base, count, names, funcs, pointers, ordinals = header[5:]
        require(0 < count <= 65536 and names <= count, 'OS export count unsupported')
        function_rvas = struct.unpack('<'+'I'*count, metadata(funcs, count*4))
        name_rvas = struct.unpack('<'+'I'*names, metadata(pointers, names*4)) if names else ()
        name_ordinals = struct.unpack('<'+'H'*names, metadata(ordinals, names*2)) if names else ()
        by_ordinal, by_name = {}, {}
        for i, target in enumerate(function_rvas):
            if not target:
                continue
            if rva <= target < rva+size:
                row = dict(ordinal=ordinal_base+i, forwarder=text(target))
            else:
                row = dict(ordinal=ordinal_base+i, rva=target, executable=pe.section(target, required=True)['executable'])
            by_ordinal[ordinal_base+i] = row
        for pointer, index in zip(name_rvas, name_ordinals):
            require(index < count and ordinal_base+index in by_ordinal, 'OS export name/ordinal invalid')
            name = text(pointer)
            require(name not in by_name, 'duplicate OS export name')
            by_name[name] = by_ordinal[ordinal_base+index]
        require(sha(path) == fingerprint, 'OS export file changed while reading metadata')
        return dict(sha256=fingerprint, image_base=pe.base, exports=by_name, ordinals=by_ordinal)
    finally:
        pe.close()


def os_export_identities(sysdir, apis):
    """Bind actual SysWOW64 files and named forwarding chains, not loader claims."""
    sysdir = Path(sysdir).resolve(); modules, chains = {}, {}
    def module(name):
        require(re.fullmatch(r'[A-Za-z0-9_-]+(?:\.dll)?', name, flags=re.IGNORECASE), 'unsafe forwarded module identity')
        name = name.lower()
        if not name.endswith('.dll'):
            name += '.dll'
        if name not in modules:
            require(len(modules) < 16, 'OS forwarding module count exceeds bound')
            path = (sysdir/name).resolve()
            require(path.parent == sysdir and path.is_file(), 'forwarded OS module not resolved as an actual SysWOW64 file')
            modules[name] = dict(path=str(path), **export_table(path))
        return modules[name]
    for api in apis:
        name, identity, seen, chain = 'kernel32.dll', api, set(), []
        for _ in range(16):
            key = (name.lower(), identity)
            require(key not in seen, 'OS export forwarder cycle')
            seen.add(key); selected = module(name)
            row = selected['ordinals'].get(int(identity[1:])) if identity.startswith('#') and identity[1:].isdigit() else selected['exports'].get(identity)
            require(row is not None, 'OS imported/forwarded export absent')
            chain.append(dict(module=Path(selected['path']).name, export=identity, **row))
            if 'forwarder' not in row:
                require(row.get('executable') is True, 'imported OS export is data, not executable code')
                break
            name, separator, identity = row['forwarder'].rpartition('.')
            require(separator and identity and (not identity.startswith('#') or identity[1:].isdigit()), 'malformed OS forwarder')
        else:
            raise ValueError('OS forwarder depth exceeds bound')
        chains[api] = chain
    for name in ('kernel32.dll', 'kernelbase.dll', 'ntdll.dll'):
        module(name)
    dependencies = {row['path']: row['sha256'] for row in modules.values()}
    check_stable(dependencies)
    return dependencies, dict(modules=[dict(name=name, path=row['path'], sha256=row['sha256'], image_base=row['image_base'])
        for name, row in sorted(modules.items())], named_forwarding_chains=chains,
        scope='Actual on-disk SysWOW64 export/forwarder identities; not in-memory KnownDLL identity, dynamic call trace or complete transitive OS import graph.')


def controlled_libraries(work, vc, sdk):
    """Exact default search order supplied by toolchain.environment, no LIBPATH."""
    expected = {'libcmt.lib': vc/'libcmt.lib', 'oldnames.lib': vc/'oldnames.lib',
                'kernel32.lib': sdk/'kernel32.lib', 'uuid.lib': sdk/'uuid.lib'}
    roots = (Path(work).resolve(), Path(vc).resolve(), Path(sdk).resolve())
    result = {}
    for name, target in expected.items():
        candidates = [(root/name).resolve() for root in roots if (root/name).is_file()]
        require(candidates and candidates[0] == target.resolve(), 'earlier competing/missing default library: '+name)
        result[name] = str(candidates[0])
    return result


def verify_library_log(text, expected):
    searches = re.findall(r'^\s*Searching\s+(.+?\.lib):\s*$', text, flags=re.MULTILINE | re.IGNORECASE)
    observed = {}
    for raw in searches:
        require(Path(raw).is_absolute(), 'linker library resolution lacks absolute path')
        path = Path(raw).resolve(); name = path.name.lower()
        require(name in expected and path == Path(expected[name]).resolve(), 'actual linker library search used unbound provider')
        observed[name] = str(path)
    require(set(observed) == set(expected), 'linker library resolution evidence incomplete')
    return observed


def inspect_link(image, mapfile, contracts, base):
    rows = map_rows(Path(mapfile).read_text())
    def at(name, owner=None):
        found = rows.get(name, [])
        require(len(found) == 1, 'missing/duplicate linked owner: '+name)
        row = found[0]
        if owner:
            require(owner in row['provider'].lower(), 'wrong linked provider: '+name)
        return row['address']
    pe = Pe(image)
    try:
        require(pe.base == base, 'fixture base differs')
        rva, size = pe.directories[9]
        require(size == 24, 'TLS directory extent differs')
        start, end, index, callbacks, zero, chars = struct.unpack('<6I', pe.read_rva(rva, 24))
        require((start, end, index) == (at('__tls_start', 'libcmt:tlssup.obj'), at('__tls_end', 'libcmt:tlssup.obj'), at('__tls_index', 'libcmt:tlssup.obj')),
                'directory has duplicate/wrong TLS infrastructure owner')
        require(end-start == 708 and zero == chars == 0, 'wrong TLS template extent/alignment/zero fill')
        owner = at(OWNER, 'storage.obj')
        require(owner-start == 4, 'source owner shifted relative to module template')
        require(owner+704 == end, 'source owner/end marker relation differs')
        sec = pe.section(start-pe.base, 709, required=True)
        require(sec['name'] == '.tls' and sec['virtual_size'] == 709 and sec['flags'] == 0xc0000040,
                'linked TLS logical extent/protection differs')
        require(pe.read_rva(start-pe.base, 708) == bytes(4)+authored_owner() and loader_bytes(pe, end, 1) == bytes(1), 'authored initial template/marker bytes differ')
        require(loader_bytes(pe, index, 4) == bytes(4), 'fresh CRT index initial data differs')
        a, z = at('___xl_a', 'libcmt:tlssup.obj'), at('___xl_z', 'libcmt:tlssup.obj')
        entry, callback = at(ENTRY, 'callback.obj'), at(CALLBACK, 'callback.obj')
        require(callbacks == a+4 == entry and z == entry+4 and
                struct.unpack('<3I', pe.read_rva(a-pe.base, 12)) == (0, callback, 0), 'wrong callback identity/order/termination')
        require(at('__tls_used', 'libcmt:tlssup.obj') == pe.base+rva, 'TLS directory map identity differs')
        require(at('__tls_array', '<absolute>') == 44, 'TLS array was treated as process VA')
        cbsec = pe.section(callback-pe.base, required=True)
        require(cbsec['executable'] and not cbsec['flags'] & 0x80000000, 'callback code protection differs')
        require(pe.section(callbacks-pe.base, 8, required=True)['flags'] == 0x40000040, 'callback array protection differs')
        sites = set(pe.relocations())
        require(not any(start-pe.base-3 <= s < end-pe.base for s in sites), 'template has pointer/base fixup')
        require(all(rva+off in sites for off in (0, 4, 8, 12)) and entry-pe.base in sites, 'directory/callback HIGHLOW missing')
        checked, code_checked = [], []
        for contract in contracts:
            coff = Coff(contract['object'])
            require(sha(contract['object']) == contract['object_sha256'], 'source object changed before link inspection')
            for source in contract['code_sections']:
                address = at(source['function'], contract['name']+'.obj')
                sec = pe.section(address-pe.base, source['size'], required=True)
                require(sec['executable'] and sec['flags'] & 0x40000000 and not sec['flags'] & 0x80000000, 'source code protection differs')
                original = section_payload(coff, source['section'])
                actual = pe.read_rva(address-pe.base, source['size'], allow_code=True)
                masked = {i for off, _, _ in coff.sections[source['section']]['relocs'] for i in range(off, off+4)}
                require(all(a == b for i, (a, b) in enumerate(zip(original, actual)) if i not in masked), 'source code payload changed after linking')
                code_checked.append(dict(function=source['function'], size=source['size'], normalized_payload_equal=True))
            for field in contract['tls_fields']:
                address = at(field['function'], contract['name']+'.obj')+field['offset']
                value = struct.unpack('<I', pe.read_rva(address-pe.base, 4, allow_code=True))[0]
                expected = 4+field['addend'] if field['kind'] == 11 else index if field['target'] == '__tls_index' else 44
                require(value == expected, 'wrong linked SECREL/module offset or TLS operand')
                require((address-pe.base in sites) == (field['target'] == '__tls_index'), 'TLS field base-relocation semantics differ')
                checked.append(dict(function=field['function'], offset=field['offset'], target=field['target'], kind=field['kind'], observed=value))
        config_rva, config_size = pe.directories[10]
        # Reviewed VC9 links advertise 64 while the raw-backed self-sized
        # structure is 72 bytes. Both extents must be proved independently.
        require(config_size in (64, 72), 'SafeSEH load configuration extent unsupported')
        config = pe.read_rva(config_rva, 72)
        table, count = struct.unpack_from('<II', config, 64)
        require(struct.unpack_from('<I', config)[0] == 72 and table and table % 4 == 0 and
                0 < count < 10000 and not pe.dll_flags & 0x400, 'SafeSEH table invalid')
        table_section = pe.section(table-pe.base, count*4, required=True)
        require(table_section['flags'] & 0x40000000 and not table_section['flags'] & 0xa0000000 and
                config_rva+64 in sites, 'SafeSEH table protection/pointer relocation differs')
        handlers = struct.unpack('<'+'I'*count, pe.read_rva(table-pe.base, count*4))
        require(list(handlers) == sorted(set(handlers)) and all(pe.section(h, required=True)['executable'] for h in handlers), 'SafeSEH handlers malformed')
        crt = {}
        for name in ('_mainCRTStartup', '_printf', '_exit', '___security_cookie', '@__security_check_cookie@4'):
            crt[name] = dict(address=at(name, 'libcmt:'), provider=rows[name][0]['provider'])
        return dict(image_base=base, template_start=start, template_end=end, template_size=708,
            owner_offset=owner-start, flag_offset=owner-start+0x264, context_offset=owner-start+0x2b0,
            template_sha256=hashlib.sha256(bytes(4)+authored_owner()).hexdigest(), index=index,
            callbacks=callbacks, callback=callback, markers=dict(start_bytes=1, alignment_padding=3, end_bytes=1),
            static_tls_fields=checked, normalized_source_code=code_checked, safe_seh_count=count,
            safe_seh_advertised_size=config_size, safe_seh_structure_size=72, crt_providers=crt,
            tls_array_absolute_constant=44, fresh_index_initial_zero=True)
    finally:
        pe.close()


def prepare(doctor, out):
    doctor, out = Path(doctor).resolve(), Path(out).resolve()
    require(os.name == 'nt' and not out.exists(), 'new native fixture output directory required')
    require(not os.environ.get('LINK') and not os.environ.get('_LINK_'), 'implicit linker options forbidden')
    tc = json.loads(doctor.read_text())['toolchains']['sp1']
    root, sdk = toolchain.layout(tc['root'])
    cl, link, dump = [root/'VC/bin'/name for name in ('cl.exe', 'link.exe', 'dumpbin.exe')]
    require(tc['ready'] and tc['version'] == toolchain.VERSIONS['sp1'] and sha(cl) == tc['cl_sha256'] and sha(link) == tc['link_sha256'], 'SP1 compiler identity differs')
    trusted = [cl, link, dump, root/'VC/bin/c1xx.dll', root/'VC/bin/c2.dll', root/'VC/lib/libcmt.lib',
               root/'VC/lib/oldnames.lib', sdk/'Lib/kernel32.lib', sdk/'Lib/uuid.lib', root/'VC/include/intrin.h']
    support = [root/'Common7/IDE/mspdb80.dll', root/'Common7/IDE/msobj80.dll', root/'VC/bin/1033/clui.dll',
               root/'VC/redist/x86/Microsoft.VC90.CRT/msvcr90.dll', root/'VC/redist/x86/Microsoft.VC90.CRT/msvcp90.dll']
    trusted += [path for path in support if path.is_file()]
    inputs = {str(p.resolve()): sha(p) for p in SOURCES+TOOLS+trusted+[doctor]}
    require(all(out != p and out not in p.parents for p in map(Path, inputs)), 'output/input collision')
    crt = crt_contract(root/'VC/lib/libcmt.lib')
    libraries = controlled_libraries(out, root/'VC/lib', sdk/'Lib')
    out.mkdir(parents=True)
    commands = []
    def run(command, log):
        check_stable(inputs)
        commands.append([str(x) for x in command])
        code, text = toolchain.run(command, root, out, timeout=120)
        (out/log).write_text(text, encoding='utf-8')
        require(code == 0, 'fixture build/inspection failed: '+log)
        check_stable(inputs)
        return text
    check_stable(inputs)
    _, banner = toolchain.run([cl], root, out, timeout=30)
    check_stable(inputs)
    require(re.search(r'Version\s+15\.00\.30729\.01\b', banner), 'compiler version differs')
    objects, included = {}, {}
    allowed = [SOURCES[0].parent.resolve(), (root/'VC/include').resolve(), (sdk/'Include').resolve()]
    for label, source in zip(('storage', 'callback', 'main'), SOURCES[1:]):
        objects[label] = out/(label+'.obj')
        trace = run([cl]+COMPILE+['/Zs', '/showIncludes', source], label+'-includes.log')
        headers = include_paths(trace, allowed)
        require(SOURCES[0].resolve() in headers, 'fixture header absent from include trace')
        header_hashes = {str(path): sha(path) for path in headers}
        require(all(path not in inputs or inputs[path] == digest for path, digest in header_hashes.items()), 'included input changed before compile')
        inputs.update(header_hashes)
        check_stable(inputs)
        compiled = run([cl]+COMPILE+['/showIncludes', source, '/Fo'+str(objects[label])], label+'-compile.log')
        require(include_paths(compiled, allowed) == headers and all(sha(path) == digest for path, digest in inputs.items()), 'actual header set/backend changed during compile')
        included[label] = header_hashes
        run([dump, '/headers', '/symbols', '/relocations', objects[label]], label+'-dump.log')
    contract = source_contract(objects)
    variants, all_apis = [], set()
    for name, base, order in [('normal', 0x400000, ['main', 'storage', 'callback']), ('moved', 0x600000, ['callback', 'storage', 'main'])]:
        exe, mp = out/(name+'.exe'), out/(name+'.map')
        extra = ['/filealign:1024'] if name == 'moved' else []
        require(controlled_libraries(out, root/'VC/lib', sdk/'Lib') == libraries, 'library search changed before link')
        linked = run([link]+LINK+extra+['/base:'+hex(base), '/out:'+str(exe), '/map:'+str(mp)]+[objects[label] for label in order], name+'-link.log')
        resolved = verify_library_log(linked, libraries)
        require(controlled_libraries(out, root/'VC/lib', sdk/'Lib') == libraries, 'library search changed during link')
        inspection = inspect_link(exe, mp, contract, base)
        imports = run([dump, '/imports', exe], name+'-imports.log')
        dlls = re.findall(r'(?im)^\s*([a-zA-Z0-9_.-]+\.dll)\s*$', imports)
        require({s.lower() for s in dlls} == {'kernel32.dll'}, 'unexpected direct fixture imports')
        import_pe = Pe(exe)
        try:
            apis = validate_imports(parse_imports(import_pe))
        finally:
            import_pe.close()
        provenance = reviewed_crt_import_members(apis, map_rows(mp.read_text()))
        all_apis.update(apis)
        run([dump, '/headers', '/loadconfig', exe], name+'-headers.log')
        variants.append(dict(name=name, exe=str(exe), exe_sha256=sha(exe), map=str(mp), map_sha256=sha(mp), inspection=inspection,
                             direct_imports=dlls, named_api_imports=apis, resolved_libraries=resolved, reviewed_crt_api_members=provenance))
    require(variants[0]['inspection']['template_start'] != variants[1]['inspection']['template_start'] and
            variants[0]['inspection']['callback'] != variants[1]['inspection']['callback'], 'fixture did not move')
    sysdir = Path(os.environ['SystemRoot'])/'SysWOW64'
    osdeps, os_exports = os_export_identities(sysdir, sorted(all_apis))
    artifacts = {str(p): sha(p) for p in out.iterdir() if p.is_file()}
    require(all(sha(p) == h for p, h in inputs.items()), 'fixture input changed during preparation')
    report = dict(schema_version=1, kind='original-tls-owner-prepared', policy=POLICY, status='prepared_pending_independent_review',
        execution_performed=False, inputs=inputs, artifacts=artifacts, os_dependencies=osdeps, os_export_evidence=os_exports, commands=commands,
        normal_crt=crt, source_contract=contract, included_headers=included,
        header_scope='Syntax-only include discovery; every actual object-compilation header is hashed beforehand and rechecked afterward with identical include set.',
        compiler_dependency_scope='Exact cl/link/dump, c1xx/c2 backends and named present support/runtime DLLs; transitive OS loader closure not claimed.',
        variants=variants, expected_main=EXPECTED, expected_detach=DETACH,
        limits='Original fixture only; command observations/hashes do not prove compiler causality or full transitive OS loader closure. No game TLS/provider approval.')
    save(out/'prepare.json', report)
    return report


def validate_review(prepared, review, prepare_sha256):
    require(prepared.get('schema_version') == 1 and prepared.get('kind') == 'original-tls-owner-prepared' and
            prepared.get('policy') == POLICY and prepared.get('status') == 'prepared_pending_independent_review' and
            prepared.get('execution_performed') is False and prepared.get('expected_main') == EXPECTED and prepared.get('expected_detach') == DETACH,
            'unrecognized TLS preparation')
    require(review.get('schema_version') == 1 and review.get('kind') == 'original-tls-owner-review' and
            review.get('approved') is True and review.get('reviewer') and review.get('prepare_sha256') == prepare_sha256,
            'independent TLS artifact approval missing/stale')
    variants = [{k: v[k] for k in ('name', 'exe_sha256', 'map_sha256')} for v in prepared['variants']]
    require([v['name'] for v in variants] == ['normal', 'moved'] and review.get('variants') == variants, 'TLS reviewed variants differ')
    require(len({str(Path(v[k]).resolve()) for v in prepared['variants'] for k in ('exe', 'map')}) == 4, 'TLS variants reuse an artifact')
    require(all(prepared['artifacts'].get(v[k]) == v[k+'_sha256'] for v in prepared['variants'] for k in ('exe', 'map')),
            'TLS variant artifact binding missing')
    require(all(review.get('checks', {}).get(k) is True for k in ('source_and_crt', 'template_layout', 'secrel_and_module_offsets',
            'callback_identity_and_safety', 'safe_seh', 'map_imports', 'os_export_identities', 'protected_artifacts')), 'TLS review checks incomplete')


def parse_result(stdout, stderr, returncode):
    require(returncode == 0 and not stderr and len(stdout.splitlines()) == 2, 'TLS own child failed or receipt sequence differs')
    records = [json.loads(line) for line in stdout.splitlines()]
    for actual, expected in zip(records, (EXPECTED, DETACH)):
        require(actual == expected and all(type(actual[k]) is type(v) for k, v in expected.items()), 'TLS initialization/threads/caller/callback checks failed')
    return records


def execute(prepared, review, review_sha256, receipt):
    pp, rp, out = [Path(p).resolve() for p in (prepared, review, receipt)]
    require(len({pp, rp, out}) == 3 and not out.exists() and sha(rp) == review_sha256, 'new execution receipt and exact TLS review required')
    ph = sha(pp); p, r = [json.loads(path.read_text()) for path in (pp, rp)]
    validate_review(p, r, ph)
    protected = {**p['inputs'], **p['artifacts'], **p['os_dependencies']}
    require(str(out) not in protected, 'execution receipt collides with protected input')
    report = dict(schema_version=1, kind='original-tls-owner-execution', status='error', prepare_sha256=ph, review_sha256=review_sha256, variants=[])
    def stable():
        return sha(pp) == ph and sha(rp) == review_sha256 and all(sha(path) == h for path, h in protected.items())
    try:
        for variant in p['variants']:
            require(stable(), 'reviewed TLS fixture input changed')
            try:
                child = subprocess.run([variant['exe']], cwd=pp.parent, stdin=subprocess.DEVNULL, stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE, text=True, errors='replace', timeout=45, creationflags=getattr(subprocess, 'CREATE_NO_WINDOW', 0))
            except subprocess.TimeoutExpired:
                report['variants'].append(dict(name=variant['name'], status='timeout'))
                raise
            observed = dict(name=variant['name'], returncode=child.returncode, stdout=child.stdout, stderr=child.stderr)
            report['variants'].append(observed)
            require(stable(), 'reviewed TLS fixture input changed during child')
            observed['observed'] = parse_result(child.stdout, child.stderr, child.returncode)
            observed['status'] = 'pass'
        report['status'] = 'pass'
    except (ValueError, OSError, subprocess.TimeoutExpired) as error:
        report['error'] = str(error)
    save(out, report)
    return report


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest='action', required=True)
    prep = commands.add_parser('prepare')
    prep.add_argument('--doctor', type=Path, required=True); prep.add_argument('--out', type=Path, required=True)
    run = commands.add_parser('execute')
    for name in ('prepare', 'review', 'review-sha256', 'receipt'):
        run.add_argument('--'+name, required=True)
    args = parser.parse_args()
    result = prepare(args.doctor, args.out) if args.action == 'prepare' else execute(args.prepare, args.review, args.review_sha256, args.receipt)
    print(result['status'])
    raise SystemExit(0 if result['status'] in ('pass', 'prepared_pending_independent_review') else 1)
