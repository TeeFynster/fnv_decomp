"""Prepare/review/execute exactly one retained scalar game-code/literal component."""
from __future__ import annotations
import argparse
from fractions import Fraction
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys

import coff_literal_extract as extract
from data_plan import Pe
import toolchain

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT/'runtime/probes/game_scalar_probe.cpp'
TOOLS = [Path(__file__), ROOT/'tools/rebuild/coff_literal_extract.py', ROOT/'tools/rebuild/coff_rewrite.py',
         ROOT/'tools/rebuild/coff_inventory.py', ROOT/'tools/rebuild/data_plan.py', ROOT/'tools/rebuild/toolchain.py']
COMPILE = ['/nologo', '/c', '/MT', '/Od', '/Oy-', '/GS', '/EHsc', '/Gy', '/W4']
LINK = ['/nologo', '/machine:x86', '/subsystem:console', '/opt:ref', '/opt:noicf', '/safeseh',
        '/dynamicbase:no', '/fixed:no', '/incremental:no']
INPUT_BITS = (0, 0x3e800000, 0x3f000000, 0x3f400000, 0x3f600000, 0x3f800000,
              0x3f3fffff, 0x3f400001, 0xbe800000)
CW_DEFAULT = 0x9001f
EXPECTED = dict(schema=1, cases=9, rounds=1024, calls=9216, sentinels_ok=True,
                x87_before=CW_DEFAULT, x87_after=CW_DEFAULT)
sha, require, save = extract.sha, extract.require, extract.save


def binary32_fraction(bits):
    require(type(bits) is int and 0 <= bits <= 0xffffffff, 'invalid binary32 bits')
    exponent, mantissa = (bits >> 23) & 255, bits & 0x7fffff
    require(exponent != 255, 'nonfinite golden input outside scope')
    value = Fraction(mantissa if exponent == 0 else 0x800000+mantissa)
    power = -149 if exponent == 0 else exponent-127-23
    value = value*(1 << power) if power >= 0 else value/Fraction(1 << -power)
    return -value if bits >> 31 else value


def nearest_even(numerator, denominator):
    quotient, remainder = divmod(numerator, denominator)
    return quotient + (2*remainder > denominator or (2*remainder == denominator and quotient % 2 == 1))


def round_binary32(value):
    """Exact integer quotient/remainder rounding; no host floating arithmetic."""
    value = Fraction(value)
    sign = 0x80000000 if value < 0 else 0
    value = abs(value)
    if not value:
        return sign
    n, d = value.numerator, value.denominator
    exponent = n.bit_length()-d.bit_length()
    if (n < d*(1 << exponent)) if exponent >= 0 else (n*(1 << -exponent) < d):
        exponent -= 1
    if exponent < -126:
        mantissa = nearest_even(n << 149, d)
        require(mantissa <= 0x800000, 'subnormal golden rounding overflow')
        return sign+mantissa
    power = 23-exponent
    mantissa = nearest_even(n << power, d) if power >= 0 else nearest_even(n, d << -power)
    if mantissa == 0x1000000:
        exponent += 1
        mantissa >>= 1
    require(exponent <= 127, 'golden overflow outside finite scope')
    return sign+((exponent+127) << 23)+(mantissa-0x800000)


def golden_cases():
    # Algebraically derived affine form C + K*x, separate from the source's
    # subtraction/multiplication evaluation. K is the exact source-emitted
    # binary64 literal, itself exactly the promoted binary32 0.67 coefficient.
    coefficient = Fraction(11240735, 16777216)
    intercept = Fraction(1)-Fraction(3, 4)*coefficient
    result = []
    for bits in INPUT_BITS:
        value = binary32_fraction(bits)
        exact = Fraction(1) if value > Fraction(3, 4) else intercept+coefficient*value
        result.append(dict(input_bits=bits, expected_bits=round_binary32(exact),
                           exact_numerator=exact.numerator, exact_denominator=exact.denominator))
    return result


def golden_header(cases):
    return ('// Original exact rational golden inputs/results; not extracted game data.\n'
            'struct ScalarGolden { unsigned input, expected; };\n'
            'static const ScalarGolden scalar_cases[] = {\n'+
            ''.join('    {0x%08xu, 0x%08xu},\n' % (c['input_bits'], c['expected_bits']) for c in cases)+
            '};\nstatic const unsigned scalar_case_count = sizeof(scalar_cases)/sizeof(scalar_cases[0]);\n')


def map_rows(text):
    result = {}
    for line in text.splitlines():
        m = re.match(r'^\s+[0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{8})\s+(.+?)\s*$', line)
        if m:
            result.setdefault(m[1], []).append(dict(address=int(m[2], 16), provider=m[3]))
    return result


def linked_inspection(exe, mapfile, selected, expected_base):
    rows = map_rows(Path(mapfile).read_text())
    def mapped(name, owner=None):
        matches = rows.get(name, [])
        require(len(matches) == 1, 'linked symbol absent or duplicate: '+name)
        if owner:
            require(matches[0]['provider'].split()[-1].lower() == owner, 'wrong selected map provider: '+name)
        return matches[0]
    coff, _, _, _ = extract.strict_object(selected)
    names = [extract.PARENT]+list(extract.LITERALS.values())
    addresses = {name: mapped(name, 'selected.obj')['address'] for name in names}
    require({name for name, values in rows.items() if any(v['provider'].split()[-1].lower() == 'selected.obj' for v in values)} == set(names),
            'unexpected retained game map provider')
    pe = Pe(exe)
    try:
        require(pe.base == expected_base and not pe.directories[9][0], 'linked base/TLS differs')
        sites = set(pe.relocations())
        checked = []
        for symbol in coff.symbols.values():
            if symbol['name'] not in names:
                continue
            sec = coff.sections[symbol['section']]
            at = addresses[symbol['name']]
            dest = pe.section(at-pe.base, sec['size'], required=True)
            require(bool(dest['flags'] & 0x20000000) == (symbol['name'] == extract.PARENT) and
                    bool(dest['flags'] & 0x20) == (symbol['name'] == extract.PARENT) and not dest['flags'] & 0x80000000,
                    'linked component protections differ')
            require(dest['flags'] & 0x40000000, 'linked component is not readable')
            alignment = 16 if symbol['name'] == extract.PARENT else 8
            require(at % alignment == 0, 'linked component alignment differs')
            original = extract.payload(coff, symbol['section'])
            actual = pe.read_rva(at-pe.base, sec['size'], allow_code=True)
            mask, edges = set(), []
            for offset, index, kind in sec['relocs']:
                target = coff.symbols[index]['name']
                require(kind == 6 and target in addresses and struct.unpack_from('<I', original, offset)[0] == 0,
                        'unexpected linked component edge')
                require(struct.unpack_from('<I', actual, offset)[0] == addresses[target] and at-pe.base+offset in sites,
                        'linked DIR32 target or HIGHLOW differs')
                mask.update(range(offset, offset+4))
                edges.append(dict(offset=offset, target=target, address=addresses[target], kind=kind, addend=0))
            require(all(a == b for i, (a, b) in enumerate(zip(original, actual)) if i not in mask), 'linked component payload differs')
            touching = sorted(site for site in sites if at-pe.base-3 <= site < at-pe.base+sec['size'])
            require(touching == sorted(at-pe.base+offset for offset, _, _ in sec['relocs']), 'unexpected linked base relocation')
            if symbol['name'] != extract.PARENT:
                require(not any(at-pe.base-3 <= site < at-pe.base+8 for site in sites), 'literal contains pointer fixup')
            checked.append(dict(symbol=symbol['name'], address=at, size=sec['size'], flags=dest['flags'],
                retained_payload_sha256=sec['payload_sha256'], nonrelocated_payload_equal=True, edges=edges))
        crt = {}
        for name in ('_mainCRTStartup', '_printf', '_exit', '__control87', '___security_cookie', '@__security_check_cookie@4'):
            row = mapped(name)
            require('libcmt:' in row['provider'].lower(), 'normal CRT provider missing: '+name)
            crt[name] = row
        return dict(image_base=pe.base, addresses=addresses, sections=checked, crt_providers=crt,
                    only_selected_game_providers=True, no_tls=True)
    finally:
        pe.close()


def prepare(doctor, manifest, selection, verification, image, out):
    doctor, out = Path(doctor).resolve(), Path(out).resolve()
    require(os.name == 'nt' and not out.exists(), 'new native private output directory required')
    require(not os.environ.get('LINK') and not os.environ.get('_LINK_'), 'implicit linker options forbidden')
    basis = extract.verify_basis(manifest, selection, verification, image)
    tc = json.loads(doctor.read_text())['toolchains']['sp1']
    root, sdk = toolchain.layout(tc['root'])
    cl, link, dump = [root/'VC/bin'/name for name in ('cl.exe', 'link.exe', 'dumpbin.exe')]
    require(tc['ready'] and tc['version'] == toolchain.VERSIONS['sp1'] and sha(cl) == tc['cl_sha256'] and
            sha(link) == tc['link_sha256'], 'compiler identity differs')
    trusted = [cl, link, dump, root/'VC/lib/libcmt.lib', root/'VC/lib/oldnames.lib', sdk/'Lib/kernel32.lib',
               root/'VC/include/float.h']
    inputs = dict(basis['inputs'])
    inputs.update({str(p.resolve()): sha(p) for p in [SOURCE]+TOOLS+trusted+[doctor]})
    require(all(out != p and out not in p.parents for p in map(Path, inputs)), 'output/input collision')
    out.mkdir(parents=True)
    cases = golden_cases()
    header = out/'scalar_goldens.hpp'
    with header.open('x', encoding='ascii') as stream:
        stream.write(golden_header(cases))
    commands = []
    def run(command, log):
        commands.append([str(x) for x in command])
        code, text = toolchain.run(command, root, out, timeout=120)
        (out/log).write_text(text, encoding='utf-8')
        require(code == 0, 'build/inspection failed: '+log)
        return text
    _, banner = toolchain.run([cl], root, out, timeout=30)
    require(re.search(r'Version\s+15\.00\.30729\.01\b', banner), 'compiler banner differs')
    selected, extraction_receipt = out/'selected.obj', out/'extract.json'
    er = extract.extract(manifest, selection, verification, image, selected, extraction_receipt)
    run([dump, '/headers', '/symbols', '/relocations', selected], 'selected-dump.log')
    caller = out/'caller.obj'
    run([cl]+COMPILE+['/I'+str(out), SOURCE, '/Fo'+str(caller)], 'caller-compile.log')
    variants = []
    for label, base, objects in [('normal', 0x400000, [caller, selected]), ('moved', 0x600000, [selected, caller])]:
        exe, mp = out/(label+'.exe'), out/(label+'.map')
        extra = ['/filealign:1024'] if label == 'moved' else []
        run([link]+LINK+extra+['/base:'+hex(base), '/out:'+str(exe), '/map:'+str(mp)]+objects, label+'-link.log')
        linked = linked_inspection(exe, mp, selected, base)
        imports = run([dump, '/imports', exe], label+'-imports.log')
        dlls = re.findall(r'(?im)^\s*([a-zA-Z0-9_.-]+\.dll)\s*$', imports)
        require({name.lower() for name in dlls} == {'kernel32.dll'}, 'unexpected direct imports')
        run([dump, '/headers', '/loadconfig', exe], label+'-headers.log')
        variants.append(dict(name=label, exe=str(exe), exe_sha256=sha(exe), map=str(mp), map_sha256=sha(mp),
                             inspection=linked, direct_imports=dlls))
    a, b = [v['inspection'] for v in variants]
    require(all(a['addresses'][n] != b['addresses'][n] for n in a['addresses']), 'component addresses did not move')
    require(any(a['addresses'][n]-a['image_base'] != b['addresses'][n]-b['image_base'] for n in a['addresses']), 'relative layout did not change')
    sysdir = Path(os.environ['SystemRoot'])/'SysWOW64'
    osdeps = {str(sysdir/n): sha(sysdir/n) for n in ('kernel32.dll', 'KernelBase.dll', 'ntdll.dll')}
    artifacts = {str(p): sha(p) for p in out.iterdir() if p.is_file()}
    require(all(sha(p) == h for p, h in inputs.items()) and not (ROOT/'build/function_index.json').exists(), 'input changed during preparation')
    report = dict(schema_version=1, kind='game-scalar-component-prepared', policy=extract.POLICY,
        status='prepared_pending_independent_review', execution_performed=False, inputs=inputs, artifacts=artifacts,
        os_dependencies=osdeps, commands=commands, variants=variants, golden_cases=cases,
        golden_method='Exact affine rational form and explicit binary32 nearest-even integer rounding; no host floating computation.',
        expected_result=EXPECTED, extraction_sha256=sha(extraction_receipt),
        basis_image_gate=basis['image_gate'], extracted_reference_comparison=er['reference_comparison'],
        limits='One scalar component only. Hash-bound observed commands do not prove compiler causality or full transitive OS loader closure.')
    save(out/'prepare.json', report)
    return report


def validate_review(prepared, review, prepare_sha256):
    require(prepared.get('schema_version') == 1 and prepared.get('kind') == 'game-scalar-component-prepared' and
            prepared.get('policy') == extract.POLICY and prepared.get('execution_performed') is False and
            prepared.get('status') == 'prepared_pending_independent_review' and prepared.get('expected_result') == EXPECTED and
            prepared.get('golden_cases') == golden_cases(),
            'unrecognized scalar preparation')
    require(review.get('schema_version') == 1 and review.get('kind') == 'game-scalar-component-review' and
            review.get('approved') is True and review.get('prepare_sha256') == prepare_sha256 and review.get('reviewer'),
            'independent scalar approval missing/stale')
    variants = [{k: v[k] for k in ('name', 'exe_sha256', 'map_sha256')} for v in prepared['variants']]
    require([v['name'] for v in variants] == ['normal', 'moved'] and review.get('variants') == variants, 'reviewed variants differ')
    paths = [str(Path(v[key]).resolve()) for v in prepared['variants'] for key in ('exe', 'map')]
    require(len(set(paths)) == 4 and all(prepared.get('artifacts', {}).get(v[key]) == v[key+'_sha256']
            for v in prepared['variants'] for key in ('exe', 'map')), 'variant artifact binding missing')
    require(all(review.get('checks', {}).get(k) is True for k in ('strict_coff', 'literal_ownership', 'linked_relocations',
            'map_crt_imports', 'golden_rounding', 'x87_policy', 'protected_artifacts')), 'independent scalar checks incomplete')


def parse_result(stdout, stderr, returncode):
    require(returncode == 0 and not stderr and len(stdout.splitlines()) == 1, 'native scalar child failed')
    observed = json.loads(stdout)
    require(observed == EXPECTED and all(type(observed[k]) is type(v) for k, v in EXPECTED.items()), 'native scalar assertions/control mode differ')
    return observed


def execute(prepared, review, review_sha256, receipt):
    pp, rp, out = [Path(p).resolve() for p in (prepared, review, receipt)]
    require(len({pp, rp, out}) == 3 and not out.exists() and sha(rp) == review_sha256, 'new receipt and exact review required')
    ph = sha(pp)
    p, r = [json.loads(path.read_text()) for path in (pp, rp)]
    validate_review(p, r, ph)
    protected = {**p['inputs'], **p['artifacts'], **p['os_dependencies']}
    require(str(out) not in protected, 'receipt collides with protected input')
    report = dict(schema_version=1, kind='game-scalar-component-execution', status='error',
                  prepare_sha256=ph, review_sha256=review_sha256, variants=[])
    def stable():
        return sha(pp) == ph and sha(rp) == review_sha256 and all(sha(path) == h for path, h in protected.items()) and not (ROOT/'build/function_index.json').exists()
    try:
        for variant in p['variants']:
            require(stable(), 'reviewed scalar input changed')
            try:
                proc = subprocess.run([variant['exe']], cwd=pp.parent, stdin=subprocess.DEVNULL,
                    stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, errors='replace', timeout=20,
                    creationflags=getattr(subprocess, 'CREATE_NO_WINDOW', 0))
            except subprocess.TimeoutExpired:
                report['variants'].append(dict(name=variant['name'], status='timeout'))
                raise
            result = dict(name=variant['name'], returncode=proc.returncode, stdout=proc.stdout, stderr=proc.stderr)
            report['variants'].append(result)
            require(stable(), 'reviewed scalar input changed during child')
            result['observed'] = parse_result(proc.stdout, proc.stderr, proc.returncode)
            result['status'] = 'pass'
        report['status'] = 'pass'
    except (ValueError, OSError, subprocess.TimeoutExpired) as error:
        report['error'] = str(error)
    save(out, report)
    return report


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest='action', required=True)
    prep = sub.add_parser('prepare')
    for name in ('doctor', 'manifest', 'selection', 'verification', 'image', 'out'):
        prep.add_argument('--'+name, type=Path, required=True)
    exe = sub.add_parser('execute')
    for name in ('prepare', 'review', 'review-sha256', 'receipt'):
        exe.add_argument('--'+name, required=True)
    args = parser.parse_args()
    result = prepare(args.doctor, args.manifest, args.selection, args.verification, args.image, args.out) if args.action == 'prepare' else execute(args.prepare, args.review, args.review_sha256, args.receipt)
    print(result['status'])
    sys.exit(0 if result['status'] in ('pass', 'prepared_pending_independent_review') else 1)
