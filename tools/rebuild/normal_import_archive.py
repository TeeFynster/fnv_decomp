"""Bounded pure x86 normal-import archive reader; no native operation."""
import hashlib
import struct
from pathlib import Path


def require(ok, message):
    if not ok:
        raise ValueError(message)


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def read_archive(path):
    """Reader derived from the accepted original native-v2 collection tooling."""
    path = Path(path)
    require(path.stat().st_size <= 4*1024*1024, 'archive size bound')
    data = path.read_bytes()
    require(len(data) <= 4*1024*1024 and data[:8] == b'!<arch>\n', 'archive format/size')
    pos, members = 8, []
    while pos < len(data):
        require(pos+60 <= len(data) and data[pos+58:pos+60] == b'`\n', 'archive member header')
        name = data[pos:pos+16].decode('ascii').rstrip()
        size = int(data[pos+48:pos+58]); start = pos+60
        require(0 <= size <= len(data)-start, 'member bounds')
        members.append(dict(offset=pos, name=name, data=data[start:start+size]))
        pos = start+size
        if pos & 1:
            require(data[pos:pos+1] == b'\n', 'padding'); pos += 1
    require(pos == len(data) and len(members) >= 2 and
            members[0]['name'] == members[1]['name'] == '/', 'archive linker members')
    byoff = {m['offset']: m for m in members[2:]}

    def strings(raw, count):
        pieces = raw.split(b'\0')
        require(len(pieces) == count+1 and pieces[-1] == b'', 'index string count')
        return [v.decode('ascii') for v in pieces[:-1]]

    one = members[0]['data']
    require(len(one) >= 4, 'first index header')
    count = struct.unpack_from('>I', one)[0]
    require(count <= 1000 and 4+4*count <= len(one), 'first index count')
    offsets = struct.unpack_from('>'+str(count)+'I', one, 4)
    names = strings(one[4+4*count:], count); first = list(zip(names, offsets))
    two = members[1]['data']
    require(len(two) >= 4, 'second index header')
    mcount = struct.unpack_from('<I', two)[0]
    require(mcount <= 1000 and 8+4*mcount <= len(two), 'second index count')
    offsets2 = struct.unpack_from('<'+str(mcount)+'I', two, 4)
    at = 4+4*mcount; n = struct.unpack_from('<I', two, at)[0]; at += 4
    require(n == count and at+2*n <= len(two), 'second symbol count')
    indices = struct.unpack_from('<'+str(n)+'H', two, at); at += 2*n
    names2 = strings(two[at:], n)
    require(all(1 <= i <= mcount for i in indices), 'second ordinal')
    second = [(name, offsets2[i-1]) for name, i in zip(names2, indices)]
    require(sorted(first) == sorted(second) and all(off in byoff for name, off in first)
            and len(set(names)) == len(names), 'archive indexes disagree')
    require(all(off in byoff for off in offsets2) and len(set(offsets2)) == len(offsets2),
            'archive member table differs')
    imports, ordinary = [], []
    for member in members[2:]:
        raw = member['data']
        if member['name'] == '//':
            continue
        if raw[:4] == b'\x00\x00\xff\xff':
            require(len(raw) >= 20, 'short import header')
            sig1, sig2, version, machine, stamp, size, hint, info = struct.unpack_from('<HHHHIIHH', raw)
            require(version == 0 and machine == 0x14c and len(raw) == 20+size and info >> 5 == 0,
                    'short import bounds/machine')
            parts = raw[20:].split(b'\0')
            require(len(parts) == 3 and not parts[-1], 'short import strings')
            symbol, dll = (v.decode('ascii') for v in parts[:2])
            require(0 < len(symbol) <= 1024 and 0 < len(dll) <= 260 and
                    all(32 <= ord(c) <= 126 for c in symbol+dll) and
                    not any(c in dll for c in '/\\:'), 'invalid short import identity')
            name_type, import_type = (info >> 2) & 7, info & 3
            require(import_type == 0 and name_type in (0, 1, 2, 3), 'unsupported import encoding')
            if name_type == 0:
                identity = dict(kind='ordinal', ordinal=hint)
            else:
                export = symbol
                if name_type in (2, 3) and export[:1] in ('_', '@', '?'):
                    export = export[1:]
                if name_type == 3:
                    export = export.split('@', 1)[0]
                require(bool(export), 'empty decoded export')
                identity = dict(kind='name', name=export)
            pointer = '__imp_'+symbol
            indexed = {name for name, off in first if off == member['offset']}
            require(pointer in indexed and symbol in indexed and len(indexed) == 2,
                    'import pointer index mismatch')
            imports.append(dict(member_offset=member['offset'], machine=machine, symbol=symbol,
                                pointer_symbol=pointer, dll=dll, export=identity, name_type=name_type,
                                import_type=import_type, hint_or_ordinal=hint,
                                member_sha256=hashlib.sha256(raw).hexdigest()))
        else:
            require(len(raw) >= 20 and struct.unpack_from('<H', raw)[0] == 0x14c,
                    'ordinary member machine')
            ordinary.append(dict(member_offset=member['offset'], machine=0x14c,
                                 member_sha256=hashlib.sha256(raw).hexdigest()))
    require(imports, 'no short imports')
    return dict(archive_sha256=sha(path), archive_bytes=len(data), member_count=len(members)-2,
                imports=imports, ordinary_members=ordinary,
                index=[dict(symbol=n, member_offset=o) for n, o in first], both_indexes_agree=True)
