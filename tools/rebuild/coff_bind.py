"""Explicit fixture-only per-object EXTERNAL symbol binding; never selects game providers."""
from __future__ import annotations
import copy
import json
from pathlib import Path
import struct
import tempfile
from coff_inventory import Coff
from coff_rewrite import digest, hash_value, strict_object


def require(ok, message):
    if not ok:
        raise ValueError(message)


def name_ok(name):
    return isinstance(name, str) and bool(name) and all(33 <= ord(c) <= 126 for c in name) and not name.startswith(('__imp_', '_imp__'))


def _transform(path, plan):
    require(plan.get('schema_version') == 1 and plan.get('kind') == 'fnv-coff-bind-plan' and
            plan.get('approved') is True and plan.get('scope') == 'original-fixture-only', 'unapproved mapping')
    coff, symptr, strptr, strlen = strict_object(path)
    require(hash_value(plan.get('object_sha256')) and digest(coff.data) == plan['object_sha256'], 'input object hash differs')
    # These identities cannot be safely mapped by this deliberately narrow mechanism.
    require(all(s['storage'] != 105 and not (s['storage'] == 2 and s['section'] == 0 and s['value'])
                for s in coff.symbols.values()), 'unsupported weak or common symbol')
    bindings = plan.get('bindings')
    require(isinstance(bindings, list) and 0 < len(bindings) <= 64, 'explicit bounded bindings required')
    names = {s['name'] for s in coff.symbols.values()}
    seen, targets, edits = set(), set(), []
    result = bytearray(coff.data)
    additions = bytearray()
    for row in bindings:
        old, new = row.get('old_name'), row.get('new_name')
        require(name_ok(old) and name_ok(new) and old != new, 'invalid or import-pointer name')
        require(row.get('source_kind') in ('function', 'data') and row.get('target_kind') == row['source_kind'], 'incorrect source/target kind')
        matches = [s for s in coff.symbols.values() if s['name'] == old]
        require(len(matches) == 1, 'missing or duplicate symbol')
        symbol = matches[0]
        require(type(row.get('symbol_index')) is int and row['symbol_index'] == symbol['index'] and symbol['index'] not in seen, 'symbol index missing, wrong or duplicate')
        require(symbol['storage'] == 2 and symbol['section'] >= 0 and not symbol['aux_count'], 'unsupported EXTERNAL definition/reference or auxiliary')
        if symbol['section'] > 0:
            executable = bool(coff.sections[symbol['section']]['flags'] & 0x20000020)
            require(executable == (row['source_kind'] == 'function'), 'defined source kind differs from section')
        require(new not in names and new not in targets, 'target collision')
        # Symbol-bearing directives are outside scope. CRT default libraries are safe.
        require(all(d.lower().startswith(('/defaultlib:', '/failifmismatch:')) and old not in d and new not in d
                    for d in coff.directives), 'unsafe directive name reference or unsupported directive')
        offset = symptr + symbol['index'] * 18
        struct.pack_into('<II', result, offset, 0, strlen + len(additions))
        additions.extend(new.encode('ascii') + b'\0')
        seen.add(symbol['index']); targets.add(new)
        edits.append(dict(row, name_field_offset=offset, section=symbol['section'], value=symbol['value'], type=symbol['type']))
    require(strlen + len(additions) <= 0xffffffff, 'string table overflow')
    struct.pack_into('<I', result, strptr, strlen + len(additions))
    result.extend(additions)
    verify_bytes(coff.data, bytes(result), edits, strptr)
    return bytes(result), edits, strptr


def verify_bytes(before, after, edits, strptr):
    allowed = set(range(strptr, strptr + 4))
    for edit in edits:
        allowed.update(range(edit['name_field_offset'], edit['name_field_offset'] + 8))
    require(len(after) >= len(before) and all(a == b or i in allowed for i, (a, b) in enumerate(zip(before, after))), 'changed payload, relocation or other non-name byte')


FIXTURE_ROOT = Path(__file__).resolve().parents[2]/'runtime/probes'
FIXTURE_SOURCES = {str((FIXTURE_ROOT/('binding_'+unit+'_'+side+'.cpp')).resolve())
                   for unit in ('caller', 'provider') for side in ('a', 'b')}


def bind_object(input_path, output_path, receipt_path, plan_path, expected_plan_sha256, *, fixture_context):
    """Operational guard: only the original fixture runner's fresh build context.

    This context is observed local evidence, not an authentication boundary.
    """
    inp, out, receipt, pp = [Path(p).resolve() for p in (input_path, output_path, receipt_path, plan_path)]
    require(len({inp, out, receipt, pp}) == 4, 'input/output collision')
    require(not out.exists() and not receipt.exists(), 'output already exists')
    raw = pp.read_bytes()
    require(hash_value(expected_plan_sha256) and digest(raw) == expected_plan_sha256, 'mapping hash differs')
    plan = json.loads(raw)
    source = Path(plan['source'])
    source = (pp.parent/source).resolve() if not source.is_absolute() else source.resolve()
    require(source not in (out, receipt), 'output/source collision')
    require(hash_value(plan.get('source_sha256')) and digest(source.read_bytes()) == plan['source_sha256'], 'source hash differs')
    require(isinstance(fixture_context, dict) and fixture_context.get('policy') == 'original-binding-fixture-v1'
            and fixture_context.get('fresh_compile_observed') is True
            and fixture_context.get('compiler_version') == '15.00.30729.01'
            and hash_value(fixture_context.get('compiler_sha256')), 'fresh fixture build context required')
    require(str(source) in FIXTURE_SOURCES, 'source outside exact original fixture set')
    observation = fixture_context.get('objects', {}).get(str(inp))
    require(isinstance(observation, dict) and observation == dict(source=str(source), source_sha256=plan['source_sha256'],
            object_sha256=plan['object_sha256']), 'object absent from fresh fixture build context')
    transformed, edits, strptr = _transform(inp, plan)
    before = Coff(inp)
    out.parent.mkdir(parents=True, exist_ok=True)
    staging = None
    try:
        with tempfile.NamedTemporaryFile(dir=out.parent, suffix='.obj', delete=False) as stage:
            staging = Path(stage.name)
            stage.write(transformed)
        after, _, _, _ = strict_object(staging)
        expected = copy.deepcopy(before.symbols)
        for edit in edits:
            expected[edit['symbol_index']]['name'] = edit['new_name']
        require(after.symbols == expected and after.sections == before.sections and after.directives == before.directives, 'independent reparse differs')
    finally:
        if staging is not None:
            staging.unlink(missing_ok=True)
    require(digest(inp.read_bytes()) == plan['object_sha256'] and digest(source.read_bytes()) == plan['source_sha256'] and pp.read_bytes() == raw, 'input changed during binding')
    report = dict(schema_version=1, kind='fnv-coff-binding', status='pass', plan_sha256=expected_plan_sha256,
        input_sha256=plan['object_sha256'], output_sha256=digest(transformed), source_sha256=plan['source_sha256'], edits=edits,
        provenance='Observed source and object hashes; association caller-declared, not execution or compiler causality proof.',
        verification=dict(non_name_object_bytes_equal=True, independent_reparse=True, symbol_indices_preserved=True),
        game_mapping_approved=False, execution_performed=False)
    created = []
    try:
        for p, content in ((out, transformed), (receipt, (json.dumps(report, indent=2)+'\n').encode())):
            p.parent.mkdir(parents=True, exist_ok=True)
            with p.open('xb') as f:
                created.append(p); f.write(content)
    except BaseException:
        for p in created:
            p.unlink(missing_ok=True)
        raise
    return report

