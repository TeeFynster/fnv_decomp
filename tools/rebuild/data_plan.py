"""Read-only PE32 data/fixup analysis. Never extracts bytes or approves runtime data."""
import argparse
import bisect
from collections import Counter
import gzip
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import tempfile

ROOT = Path(__file__).resolve().parents[2]
EXECUTE, CODE = 0x20000000, 0x20


class PlanError(ValueError):
    pass


def canonical(value):
    return json.dumps(value, sort_keys=True, separators=(',', ':')).encode('utf-8')


def file_hash(path):
    digest = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(1024*1024), b''):
            digest.update(block)
    return digest.hexdigest()


class Pe:
    """Small random-access reader; executable payloads are not read for data analysis."""
    def __init__(self, path):
        self.path = Path(path)
        self.stream = self.path.open('rb')
        try:
            self.length = self.path.stat().st_size
            if self.read(0, 2) != b'MZ':
                raise PlanError('missing DOS signature')
            pe, = self.unpack('<I', 0x3c)
            if self.read(pe, 4) != b'PE\0\0':
                raise PlanError('missing PE signature')
            machine, count, _, _, _, opts, flags = self.unpack('<HHIIIHH', pe + 4)
            if machine != 0x14c or not 1 <= count <= 96 or opts < 224:
                raise PlanError('requires bounded standard i386 PE32 headers')
            optional = self.read(pe + 24, opts)
            if struct.unpack_from('<H', optional)[0] != 0x10b:
                raise PlanError('requires PE32 optional header')
            self.base, = struct.unpack_from('<I', optional, 28)
            self.image_size, self.header_size = struct.unpack_from('<II', optional, 56)
            if not self.image_size or self.base + self.image_size > 0x100000000:
                raise PlanError('invalid PE32 image address bounds')
            self.dll_flags, = struct.unpack_from('<H', optional, 70)
            header_end = pe + 24 + opts + 40*count
            if not header_end <= self.header_size <= min(self.length,self.image_size):
                raise PlanError('SizeOfHeaders does not contain the complete PE section table')
            count_dirs, = struct.unpack_from('<I', optional, 92)
            if count_dirs < 13 or count_dirs > (opts - 96) // 8:
                raise PlanError('invalid data-directory count')
            self.directories = [struct.unpack_from('<II', optional, 96 + 8*i) for i in range(count_dirs)]
            self.sections = []
            self.section_headers = []
            for i in range(count):
                raw_header = self.read(pe + 24 + opts + 40*i,40)
                self.section_headers.append(raw_header)
                row = struct.unpack('<8sIIIIIIHHI',raw_header)
                name, virtual, rva, raw_size, raw = row[:5]
                size = virtual or raw_size
                if not size or rva < self.header_size or rva + max(size, raw_size) > self.image_size:
                    raise PlanError('invalid section virtual bounds')
                if raw_size:
                    if raw < self.header_size:
                        raise PlanError('section overlaps file headers')
                    self.bounds(raw, raw_size)
                self.sections.append(dict(index=i, name=name.rstrip(b'\0').decode('ascii', errors='replace'),
                    rva=rva, virtual_size=virtual, extent=size, raw_size=raw_size, raw_offset=raw,
                    flags=row[-1], executable=bool(row[-1] & (EXECUTE | CODE))))
            self.nonoverlap([(s['rva'], s['rva'] + max(s['extent'], s['raw_size'])) for s in self.sections], 'virtual sections')
            self.nonoverlap([(s['raw_offset'], s['raw_offset']+s['raw_size']) for s in self.sections if s['raw_size']], 'raw sections')
            for i, (rva, size) in enumerate(self.directories):
                if bool(rva) != bool(size):
                    raise PlanError('incomplete data directory')
                if rva and i != 4:  # certificate directory uses file offsets
                    self.section(rva, size, required=True)
                elif rva:
                    self.bounds(rva, size)
        except Exception:
            self.close()
            raise

    @staticmethod
    def nonoverlap(ranges, description):
        ordered = sorted(ranges)
        if any(a[1] > b[0] for a, b in zip(ordered, ordered[1:])):
            raise PlanError('overlapping ' + description)

    def close(self):
        self.stream.close()

    def bounds(self, offset, size):
        if offset < 0 or size < 0 or offset + size > self.length:
            raise PlanError('read exceeds PE file bounds')

    def read(self, offset, size):
        self.bounds(offset, size)
        self.stream.seek(offset)
        data = self.stream.read(size)
        if len(data) != size:
            raise PlanError('short PE read')
        return data

    def unpack(self, fmt, offset):
        return struct.unpack(fmt, self.read(offset, struct.calcsize(fmt)))

    def section(self, rva, size=1, required=False):
        for section in self.sections:
            if section['rva'] <= rva and rva + size <= section['rva'] + section['extent']:
                return section
        if required:
            raise PlanError('RVA range outside a single logical section')
        return None

    def read_rva(self, rva, size, allow_code=False):
        section = self.section(rva, size, required=True)
        if section['executable'] and not allow_code:
            raise PlanError('executable payload is excluded from data reads')
        offset = rva - section['rva']
        if offset + size > section['raw_size']:
            raise PlanError('RVA range is not wholly raw-backed')
        return self.read(section['raw_offset'] + offset, size)

    def nonexec_identity(self):
        rows = []
        for s in self.sections:
            if s['executable']:
                continue
            digest = hashlib.sha256()
            for offset in range(0, s['raw_size'], 1024*1024):
                digest.update(self.read(s['raw_offset'] + offset, min(1024*1024, s['raw_size']-offset)))
            rows.append(dict(name=s['name'], rva=s['rva'], virtual_size=s['virtual_size'],
                             raw_size=s['raw_size'], flags=s['flags'], sha256=digest.hexdigest()))
        return rows, hashlib.sha256(canonical(rows)).hexdigest()

    def relocations(self):
        rva, size = self.directories[5]
        if not rva:
            return
        if size > 8*1024*1024:
            raise PlanError('relocation directory exceeds the bounded 8 MiB analysis limit')
        data = self.read_rva(rva, size)
        position, seen = 0, set()
        while position < size:
            if size-position < 8:
                raise PlanError('truncated relocation block')
            page, length = struct.unpack_from('<II', data, position)
            if page % 4096 or length < 8 or length % 2 or position+length > size:
                raise PlanError('invalid relocation block extent/alignment')
            for offset in range(position+8, position+length, 2):
                value, = struct.unpack_from('<H', data, offset)
                kind, site = value >> 12, page + (value & 4095)
                if kind == 0:
                    continue
                if kind != 3:
                    raise PlanError('unsupported PE32 relocation kind: %d' % kind)
                self.section(site, 4, required=True)
                if any(site + delta in seen for delta in range(-3, 4)):
                    raise PlanError('overlapping HIGHLOW fixup fields')
                seen.add(site)
                if len(seen)>1000000:
                    raise PlanError('HIGHLOW count exceeds the bounded one-million-site limit')
                yield site
            position += length


class Spans:
    def __init__(self, pairs, allow_overlap=False):
        self.sizes = {}
        for address, size in pairs:
            if size < 1 or address < 0 or address + size > 0x100000000:
                raise PlanError('invalid recipe span')
            if address in self.sizes and self.sizes[address] != size:
                raise PlanError('conflicting recipe span sizes')
            self.sizes[address] = size
        self.starts = sorted(self.sizes)
        ranges = [(a, a+self.sizes[a]) for a in self.starts]
        self.overlaps = sum(a[1] > b[0] for a,b in zip(ranges,ranges[1:]))
        if not allow_overlap:
            Pe.nonoverlap(ranges, 'recipe spans')
        self.prefix_end = []
        for a,b in ranges:
            self.prefix_end.append(max(b,self.prefix_end[-1] if self.prefix_end else 0))

    def locate(self, address):
        if address in self.sizes:
            return address, 0
        i = bisect.bisect_right(self.starts, address)-1
        candidates = []
        while i >= 0 and self.prefix_end[i] > address:
            start = self.starts[i]
            if address < start+self.sizes[start]:
                candidates.append((start,address-start))
            i -= 1
        return candidates[0] if len(candidates)==1 else ('ambiguous',None) if candidates else None


def recipe_spans(path):
    units = json.loads(Path(path).read_text(encoding='utf-8'))['units']
    functions = Spans((int(f['address'], 0), f['size']) for u in units for f in u['functions'])
    tails = Spans(((int(f['address'], 0), f['size']) for u in units for f in u.get('eh_tails', [])), allow_overlap=True)
    return units, functions, tails


def fingerprint(pe, spec):
    rows = []
    for address, size, expected in json.loads(Path(spec).read_text(encoding='utf-8'))['probes']:
        observed = hashlib.sha256(pe.read_rva(int(address, 0)-pe.base, size, allow_code=True)).hexdigest()
        rows.append([address, size, observed, observed == expected])
    hits = sum(x[3] for x in rows)
    if not rows or hits < min(12, len(rows)):
        raise PlanError('reference failed existing image fingerprint threshold')
    return dict(hits=hits, probes=len(rows), digest=hashlib.sha256(canonical(rows)).hexdigest(),
                meaning='existing bounded code probes; not a complete image attestation')


def target_kind(pe, value, functions, tails, tls):
    rva = value-pe.base
    iat, size = pe.directories[12]
    if iat and iat <= rva < iat+size:
        return 'import-IAT', rva-iat
    resource, size = pe.directories[2]
    if resource and resource <= rva < resource+size:
        return 'resource', rva-resource
    if tls and tls[0] <= value < tls[1]:
        return 'TLS-template', value-tls[0]
    if tls and value == tls[2]:
        return 'TLS-index', 0
    section = pe.section(rva)
    if not section:
        return ('outside-image' if rva < 0 or rva >= pe.image_size else 'unmapped'), None
    if section['executable']:
        for label, spans in [('ordinary', functions), ('EH', tails)]:
            point = spans.locate(value)
            if point:
                if point[0] == 'ambiguous':
                    return label+'-interior-ambiguous', None
                return label + ('-entry' if point[1] == 0 else '-interior'), point[1]
        return 'other-code', None
    if section['name'] in ('.reloc', '.rsrc'):
        return 'unmapped-metadata', None
    return 'data', rva-section['rva']


def analyze(image, recipes, reference=None, image_check=None, details=None):
    units, functions, tails = recipe_spans(recipes)
    pe = Pe(image)
    try:
        identities, digest = pe.nonexec_identity()
        provenance = dict(nonexec_sections=identities, nonexec_digest=digest,
                          state='raw on-disk bytes; process-initial-state semantics unproved',
                          owned_image_executable_payloads_read=False)
        if reference:
            other = Pe(reference)
            try:
                reference_identities, reference_digest = other.nonexec_identity()
                if (pe.base != other.base or pe.image_size != other.image_size or
                        pe.section_headers != other.section_headers or pe.dll_flags != other.dll_flags):
                    raise PlanError('owned image/reference section headers differ')
                if identities != reference_identities:
                    raise PlanError('owned image/reference non-executable identities differ')
                provenance.update(reference_headers_equal=True, reference_nonexec_equal=True,
                                  reference_nonexec_digest=reference_digest)
                if image_check:
                    provenance['reference_fingerprint'] = fingerprint(other, image_check)
            finally:
                other.close()
        tls = None
        tls_rva, tls_size = pe.directories[9]
        if tls_rva:
            if tls_size < 24:
                raise PlanError('truncated TLS directory')
            start, end, index, callbacks, fill, characteristics = struct.unpack('<IIIIII', pe.read_rva(tls_rva, 24))
            if end < start:
                raise PlanError('reversed TLS template')
            if end > start:
                pe.section(start-pe.base, end-start, required=True)
            pe.section(index-pe.base, 4, required=True)
            tls = start, end, index
        selected, excluded = [], []
        for s in pe.sections:
            if s['executable'] or s['name'] in ('.reloc', '.rsrc') or not s['flags'] & (0x40 | 0x80):
                excluded.append(dict(s, reason='executable, metadata/resource, or unsupported section kind'))
            else:
                selected.append(dict(s, zero_fill=max(s['extent']-s['raw_size'], 0),
                                     raw_padding=max(s['raw_size']-s['extent'], 0)))
        selected_indices = {s['index'] for s in selected}
        counts, source_counts, issues = Counter(), Counter(), Counter()
        total, inspected = 0, 0
        for site in pe.relocations():
            total += 1
            section = pe.section(site, 4, required=True)
            if section['index'] not in selected_indices:
                continue
            inspected += 1
            offset = site-section['rva']
            if offset+4 <= section['raw_size']:
                value, = struct.unpack('<I', pe.read_rva(site, 4))
                backing = 'raw'
            elif offset >= section['raw_size']:
                value, backing = 0, 'virtual-zero-fill'
            else:
                raise PlanError('fixup field straddles raw/zero-fill boundary')
            kind, target_offset = target_kind(pe, value, functions, tails, tls)
            flags = ['semantic-field-type-unproved', 'canonical-provider-unapproved']
            if kind in ('other-code', 'outside-image', 'unmapped', 'unmapped-metadata') or kind.endswith('-ambiguous'):
                flags.append('target-unresolved')
            if kind == 'import-IAT':
                flags.append('preserve-IAT-indirection')
                if target_offset % 4:
                    flags.append('interior-IAT-target-unapproved')
            if backing != 'raw':
                flags.append('zero-fill-fixup-unapproved')
            iat, iat_size = pe.directories[12]
            if iat and site < iat+iat_size and site+4 > iat:
                flags.append('loader-owned-IAT-site')
            for flag in flags:
                issues[flag] += 1
            counts[kind] += 1
            source_counts[section['name']] += 1
            if details:
                # Values are addresses only; no raw payload or instruction bytes.
                details.write(json.dumps([site, value-pe.base, kind, target_offset, 4, backing, flags], separators=(',', ':'))+'\n')
        return dict(schema_version=1, kind='fnv-private-data-analysis', runtime_ready=False,
            status='analysis-only', provenance=provenance, recipe_sha256=file_hash(recipes),
            recipe_units=len(units), ordinary_spans=len(functions.starts), EH_spans=len(tails.starts),
            EH_adjacent_interval_overlaps=tails.overlaps,
            inferred_baseline_bindings=dict(consumed=False, reason='no pre-execution hash-bound oracle receipt supplied; legacy JSON is observational'),
            image=dict(base=pe.base, size=pe.image_size, dynamic_base=bool(pe.dll_flags & 0x40)),
            selected_sections=selected, excluded_sections=excluded,
            fixups=dict(HIGHLOW_total=total, nonexec_data_sites=inspected, by_target=dict(counts),
                        by_source_section=dict(source_counts), blockers=dict(issues),
                        approved_semantic_fixups=0, unapproved_semantic_fixups=inspected,
                        field_width=4, site_bounds_and_nonoverlap_checked=True),
            detail_columns=['site_rva', 'target_rva', 'target_class', 'target_offset', 'width', 'backing', 'blockers'],
            limitations=['Address classification is not a proved C++ field type, object extent, lifetime, or approved target provider.',
                         'RVA/relative/encoded/runtime-populated pointers outside base relocations are not inventoried.',
                         'No code/data partition of executable sections, data extraction, runtime generation or linking.'])
    finally:
        pe.close()


def distinct_outputs(inputs, outputs):
    norm = lambda p: os.path.normcase(str(Path(p).resolve()))
    reserved = {norm(p) for p in inputs if p}
    for output in outputs:
        if not output:
            continue
        key = norm(output)
        if key in reserved or Path(output).exists():
            raise PlanError('output must be new and distinct from every input/output')
        reserved.add(key)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--image', type=Path, required=True, help='private owned on-disk PE')
    parser.add_argument('--recipes', type=Path, default=ROOT/'build/units.json')
    parser.add_argument('--reference', type=Path, help='optional compatible private checker image')
    parser.add_argument('--image-check', type=Path, default=ROOT/'build/image_check.json')
    parser.add_argument('--out', type=Path, required=True, help='new private compact JSON report')
    parser.add_argument('--details-gz', type=Path, help='optional new streamed JSONL.gz address/fixup detail')
    args = parser.parse_args()
    try:
        distinct_outputs([args.image, args.recipes, args.reference, args.image_check], [args.out, args.details_gz])
        for output in [args.out, args.details_gz]:
            if output:
                output.parent.mkdir(parents=True, exist_ok=True)
        if args.details_gz:
            # Stream to an automatically closed temporary file while validating.
            # Failed analysis never publishes a partial evidence artifact.
            with tempfile.TemporaryFile(dir=args.details_gz.parent) as pending:
                with gzip.GzipFile(fileobj=pending, mode='wb', mtime=0) as compressed:
                    import io
                    with io.TextIOWrapper(compressed, encoding='utf-8') as detail:
                        report = analyze(args.image, args.recipes, args.reference, args.image_check, detail)
                pending.seek(0)
                with args.details_gz.open('xb') as published:
                    shutil.copyfileobj(pending,published,length=1024*1024)
            report['detail_sha256'] = file_hash(args.details_gz)
        else:
            report = analyze(args.image, args.recipes, args.reference, args.image_check)
        with args.out.open('x', encoding='utf-8') as stream:
            json.dump(report, stream, indent=2)
            stream.write('\n')
        print(json.dumps(dict(report=str(args.out), status=report['status'], fixups=report['fixups'])))
        return 0
    except (OSError, ValueError, KeyError, TypeError, struct.error) as error:
        print(json.dumps(dict(status='rejected', error=str(error))))
        return 1


if __name__ == '__main__':
    raise SystemExit(main())
