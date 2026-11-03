"""Source-only conditional CRT traversal witnesses and proposed table-read bounds.

Reads pinned native CRT code, saved observation receipts and data-plan geometry.
There is no original-image argument/read, execution, table payload, provider or
registration output. Full-caller/helper identities and reachability stay open.
"""
from __future__ import annotations
import argparse
import json
from pathlib import Path

import capstone
from capstone.x86 import X86_OP_REG, X86_OP_IMM, X86_OP_MEM
import crt_table_boundaries as base
import crt_boundary_helpers as helpers
from data_plan import file_hash
from game_initializers import PINS

HELPER_RECEIPT = '46a32adedeed001defb64c68ef59a1df6ba4506c8ce0f5b85bb04d890ad005df'
CRT_REPORT = 'ae4aa835090331446ec05d73330b6a9979d9e6a1b07393669817c28705cf0a3f'
MAX_TABLE_BYTES = 1024 * 1024


def require(value, message):
    if not value:
        raise ValueError(message)


def reg(name): return ('reg', name)
def imm(value): return ('imm', value)
def sym(name): return ('symbol', name)
def mem(name, displacement=0): return ('mem', name, '', 1, displacement, 4)


def source_manifest():
    result = helpers.source_manifest()
    for name in ('tools/rebuild/crt_traversal_plan.py', 'tests/rebuild/test_crt_traversal_plan.py'):
        result[name] = file_hash(base.ROOT / name)
    return result


def decode_native(code, relocations):
    """Decode the legitimate native-library span; output abstract operands only."""
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    decoder.detail = True
    instructions, field_joins, consumed = {}, [], 0
    for ins in decoder.disasm(code, 0):
        require(ins.address == consumed, 'undecoded native section gap')
        consumed += ins.size
        operands = []
        local = [r for r in relocations if ins.address <= r['offset'] < ins.address + ins.size]
        immediate = next((r for r in local if r['offset'] == ins.address + ins.imm_offset and ins.imm_size == 4), None)
        displacement = next((r for r in local if r['offset'] == ins.address + ins.disp_offset and ins.disp_size == 4), None)
        for row in local:
            require(row is immediate or row is displacement, 'relocation is not an exact native operand field')
            require(row['kind'] in (6, 20), 'unsupported operand relocation')
            require(row['kind'] != 20 or (row is immediate and ins.mnemonic in ('call', 'jmp')),
                    'REL32 does not target a direct call/jump operand')
            field_joins.append(dict(offset=row['offset'], instruction_offset=ins.address,
                operand_kind='immediate' if row is immediate else 'displacement',
                relocation_kind=row['kind'], symbol=row['symbol'],
                source_operand_shape_verified=True, independent_target_identity_verified=False))
        for operand in ins.operands:
            if operand.type == X86_OP_REG:
                operands.append(reg(ins.reg_name(operand.reg)))
            elif operand.type == X86_OP_IMM:
                operands.append(sym(immediate['symbol']) if immediate else imm(operand.imm))
            elif operand.type == X86_OP_MEM:
                m = operand.mem
                require(not m.segment, 'unexpected segment override in modelled native span')
                if displacement:
                    operands.append(('mem-symbol', displacement['symbol'], ins.reg_name(m.base) if m.base else '',
                                     ins.reg_name(m.index) if m.index else '', m.scale, operand.size))
                else:
                    operands.append(('mem', ins.reg_name(m.base) if m.base else '',
                                     ins.reg_name(m.index) if m.index else '', m.scale, m.disp, operand.size))
            else:
                raise ValueError('unsupported native operand kind')
        instructions[ins.address] = (ins.mnemonic, *operands)
    require(consumed == len(code) and len(field_joins) == len(relocations), 'incomplete native decode/relocation join')
    return instructions, field_joins


def models():
    return {
        '__initterm': (True, {
            0: ('mov', reg('edi'), reg('edi')), 2: ('push', reg('ebp')),
            3: ('mov', reg('ebp'), reg('esp')), 5: ('push', reg('esi')),
            6: ('mov', reg('esi'), reg('eax')), 8: ('jmp', imm(21)),
            10: ('mov', reg('eax'), mem('esi')), 12: ('test', reg('eax'), reg('eax')),
            14: ('je', imm(18)), 16: ('call', reg('eax')), 18: ('add', reg('esi'), imm(4)),
            21: ('cmp', reg('esi'), mem('ebp', 8)), 24: ('jb', imm(10)),
            26: ('pop', reg('esi')), 27: ('pop', reg('ebp')), 28: ('ret',)}),
        '__initterm_e': (True, {
            0: ('mov', reg('edi'), reg('edi')), 2: ('push', reg('ebp')),
            3: ('mov', reg('ebp'), reg('esp')), 5: ('push', reg('esi')),
            6: ('mov', reg('esi'), mem('ebp', 8)), 9: ('xor', reg('eax'), reg('eax')),
            11: ('jmp', imm(28)), 13: ('test', reg('eax'), reg('eax')), 15: ('jne', imm(33)),
            17: ('mov', reg('ecx'), mem('esi')), 19: ('test', reg('ecx'), reg('ecx')),
            21: ('je', imm(25)), 23: ('call', reg('ecx')), 25: ('add', reg('esi'), imm(4)),
            28: ('cmp', reg('esi'), mem('ebp', 12)), 31: ('jb', imm(13)),
            33: ('pop', reg('esi')), 34: ('pop', reg('ebp')), 35: ('ret',)}),
        '__cinit': (False, {
            44: ('push', sym('___xi_z')), 49: ('push', sym('___xi_a')),
            54: ('call', sym('__initterm_e')), 59: ('pop', reg('ecx')), 60: ('pop', reg('ecx')),
            61: ('test', reg('eax'), reg('eax')), 63: ('jne', imm(131)),
            65: ('push', sym('__RTC_Terminate')), 70: ('call', sym('_atexit')),
            75: ('mov', reg('eax'), sym('___xc_a')),
            80: ('mov', mem('esp'), sym('___xc_z')), 87: ('call', sym('__initterm')),
            129: ('xor', reg('eax'), reg('eax')), 131: ('pop', reg('ebp')), 132: ('ret',)}),
        '_doexit': (False, {
            53: ('cmp', mem('ebp', 12), imm(0)), 57: ('jne', imm(220)),
            204: ('push', sym('___xp_z')), 209: ('mov', reg('eax'), sym('___xp_a')),
            214: ('call', sym('__initterm')), 219: ('pop', reg('ecx')),
            220: ('push', sym('___xt_z')), 225: ('mov', reg('eax'), sym('___xt_a')),
            230: ('call', sym('__initterm')), 235: ('pop', reg('ecx'))}),
    }


def validate_model(instructions, expected, complete):
    require(all(instructions.get(offset) == value for offset, value in expected.items()),
            'native register/stack/branch model differs')
    if complete:
        require(set(instructions) == set(expected), 'leaf traversal model does not cover every instruction')


def original_candidate(saved, name):
    observations = [r for r in saved['observations'] if r['identity'] == 'sp1:' + name]
    require(len(observations) == 1 and len(observations[0]['candidates']) == 1,
            'saved native witness is not unique in the reported search')
    candidate = observations[0]['candidates'][0]
    require(candidate['full_nonrelocation_span_equal'] is True, 'saved fixed-span observation failed')
    return candidate


def operand(candidate, name, expected_kind):
    fields = [r for r in candidate['relocations'] if r['symbol'] == name]
    require(fields and len({r['original_symbol_base_candidate'] for r in fields}) == 1,
            'absent/conflicting named operand')
    require(all(r['kind'] == expected_kind and r['addend'] == 0 and not r['errors'] for r in fields),
            'named operand relocation/addend/provenance failed')
    require(all(r['field_highlow'] == (expected_kind == 6) for r in fields), 'wrong HIGHLOW role')
    return fields[0]['original_symbol_base_candidate']


def table_request(stage, begin, end, data_plan):
    require(begin <= end and begin % 4 == end % 4 == 0, 'invalid operand-derived array interval')
    length = end - begin
    require(length + 4 <= MAX_TABLE_BYTES, 'individual table exceeds byte budget')
    image_base = data_plan['image']['base']
    containing = [s for s in data_plan['selected_sections'] if
        image_base + s['rva'] <= begin and end + 4 <= image_base + s['rva'] + min(s['extent'], s['raw_size'])]
    require(len(containing) == 1 and not containing[0]['flags'] & 0x20000020,
            'proposed complete interval/sentinel is not in one raw non-executable arena')
    return dict(stage=stage, begin_operand=begin, end_operand=end,
        traversal_interval=[begin, end], interval_semantics='begin-inclusive/end-exclusive',
        cell_width=4, traversed_cells=length // 4,
        proposed_traversal_bytes=length, proposed_end_cell_bytes=4,
        aggregate_requested_bytes=length + 4, arena_name=containing[0]['name'],
        identity_basis='conditional native call argument and leaf walker witness, never null/run proximity',
        preserve_every_cell=True, preserve_nulls_and_unknown_targets=True,
        copy_original_bytes=False, runtime_provider_approved=False)


def run(args):
    paths = {name: Path(getattr(args, name)) for name in ('doctor', 'candidates', 'helpers', 'data_plan', 'crt_report')}
    pins = dict(doctor=base.DOCTOR, candidates=helpers.CANDIDATES, helpers=HELPER_RECEIPT,
                data_plan=PINS['data_plan'], crt_report=CRT_REPORT)
    require(not Path(args.out).exists(), 'output exists')
    sources = source_manifest()
    decoder_engine = Path(capstone._cs._name)
    decoder_hashes = dict(module=file_hash(capstone.__file__), engine=file_hash(decoder_engine))
    for name, path in paths.items(): require(file_hash(path) == pins[name], 'input differs: ' + name)
    saved = json.loads(paths['candidates'].read_text())
    helper_report = json.loads(paths['helpers'].read_text())
    data_plan = json.loads(paths['data_plan'].read_text())
    contracts, patterns, libraries = base.load_contracts(paths['doctor'])
    witnesses = []
    for name, (complete, model) in models().items():
        contract = next(c for c in contracts if c['identity'] == 'sp1:' + name)
        decoded, joins = decode_native(patterns[contract['identity']], contract['relocations'])
        validate_model(decoded, model, complete)
        original = original_candidate(saved, name)
        witnesses.append(dict(native_symbol=name, original_candidate=original['address'],
            native_section_sha256=contract['span_sha256'], complete_instruction_model=complete,
            local_model_verified=True, relocation_instruction_joins=joins,
            conditional_on_control_reaching_callsite=True, whole_caller_identity_approved=False))
    cinit, doexit = original_candidate(saved, '__cinit'), original_candidate(saved, '_doexit')
    require(operand(cinit, '__initterm_e', 20) == original_candidate(saved, '__initterm_e')['address'] and
            operand(cinit, '__initterm', 20) == operand(doexit, '__initterm', 20) ==
            original_candidate(saved, '__initterm')['address'], 'actual direct walker target differs')
    requests = [table_request(stage, operand(caller, '___' + stage + '_a', 6),
        operand(caller, '___' + stage + '_z', 6), data_plan) for stage, caller in
        [('xi', cinit), ('xc', cinit), ('xp', doexit), ('xt', doexit)]]
    total = sum(r['aggregate_requested_bytes'] for r in requests)
    require(total <= MAX_TABLE_BYTES, 'aggregate proposed table-read budget exceeded')
    remaining = []
    for row in helper_report['observations']:
        require(row['full_nonrelocation_span_equal'] is True, 'saved helper fixed-span failed')
        for relocation in row['relocations']:
            remaining.append(dict(helper=row['symbol'], **relocation))
    require(source_manifest() == sources, 'source changed')
    require(decoder_hashes == dict(module=file_hash(capstone.__file__), engine=file_hash(decoder_engine)),
            'decoder implementation changed')
    for name, path in paths.items(): require(file_hash(path) == pins[name], 'input changed: ' + name)
    for path, expected in libraries: require(file_hash(path) == expected, 'native library/doctor changed')
    result = dict(schema_version=1, kind='fnv-conditional-crt-traversal-plan', sources=sources,
        inputs=pins, decoder_version=capstone.__version__, decoder_sha256=decoder_hashes,
        witnesses=witnesses, proposed_table_reads=requests, aggregate_proposed_bytes=total,
        remaining_helper_relocation_observations=remaining,
        remaining_core_relocation_observations=[dict(identity=o['identity'], caller=c['address'], **r)
            for o in saved['observations'] for c in o['candidates'] for r in c['relocations']],
        conditional_rules=['XI walker moves forward, skips nulls and returns first nonzero callback status',
            'XI nonzero return bypasses C++ traversal on this local caller path',
            'XC begin is EAX and end is the sole stack argument to the matched leaf walker',
            'XP precedes XT on the local normal path; nonzero EBP+12 flag branches directly to XT',
            'All caller reachability, initial-state gates, callback contracts and global registration remain unresolved'],
        table_read_performed=False, original_image_read=False,
        conditional_local_operand_witness=True, original_table_bounds_approved=False,
        original_startup_order_approved=False, whole_program_registration_approved=False,
        allow_table_read=False, runtime_provider_approved=False, executed=False)
    with Path(args.out).open('x', encoding='utf-8') as stream: json.dump(result, stream, separators=(',', ':'))
    return dict(witnesses=len(witnesses), proposed_bytes=total, original_image_read=False, allow_table_read=False)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('doctor', 'candidates', 'helpers', 'data_plan', 'crt_report', 'out'):
        parser.add_argument('--' + name.replace('_', '-'), required=True)
    print(json.dumps(run(parser.parse_args()), sort_keys=True))


if __name__ == '__main__': main()
