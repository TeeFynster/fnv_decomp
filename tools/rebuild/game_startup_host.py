"""Offline compile/closure plan for an original GUI-to-game adapter.

Never invokes a compiler, linker, application, or native tool. Native preparation
requires a subsequent source-reviewed runner and separate coordinator go.
"""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
HOST = 'runtime/startup/game_startup_host.cpp'
SOURCE = 'src/fallout/misc/main.cpp'
SOURCE_HASH = '89d09f8b4ba6d9758fca0ac3ebd32e18c9cc82c68a739c044457ed5c005ae3c5'
RECIPE_HASH = '62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c'
IDENTITY = dict(recipe_id='0576-dd603b7071c482c6',
    object_sha256='a6c310961921f70eea2c70b9c18dba3d85ac19bffdfe3164922e9c3462ab425b',
    symbol_index=1215)
CANONICAL = '_fnv_code_a6aec00b5758b2c5c1dd3e4ad43d42c70a7d4b3ba314830a56d8d21afb4e93f2'
FLAGS = ['/nologo', '/c', '/MT', '/Od', '/Oy-', '/GS', '/EHsc', '/W4', '/WX']
GATES = ['typed_host_reference_binding', 'normal_GUI_CRT_provider',
    'cookie_before_protected_initialization', 'game_initializer_retention_and_order',
    'single_exit_registry_and_shutdown', 'game_TLS_owner_and_loader_contract',
    'entry_CODE_and_transitive_providers', 'entry_DATA_and_resources',
    'all_import_signatures_and_pointer_cells', 'callee_ABI_EH_and_allocation']


def sha256(path):
    digest = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            digest.update(block)
    return digest.hexdigest()


def require(ok, message):
    if not ok:
        raise ValueError(message)


def source_manifest(repository=ROOT):
    return {name: sha256(Path(repository) / name) for name in
        [HOST, 'tools/rebuild/game_startup_host.py',
         'tests/rebuild/test_game_startup_host.py', 'docs/rebuild/GAME-STARTUP-HOST.md']}


def build_plan(doctor_path, doctor_sha256, repository=ROOT):
    """Read only exact explicit files; approval booleans can never be promoted."""
    repository, doctor_path = Path(repository).resolve(), Path(doctor_path).resolve()
    require(sha256(doctor_path) == doctor_sha256, 'doctor hash mismatch')
    doctor = json.loads(doctor_path.read_text(encoding='utf-8'))
    require(doctor.get('schema_version') == 1, 'unknown doctor schema')
    sp1 = doctor['toolchains']['sp1']
    require(sp1.get('ready') is True and sp1.get('compiler') == 'sp1' and
        sp1.get('version') == '15.00.30729.01' and
        sp1.get('expected_version') == '15.00.30729.01', 'SP1 doctor not ready')
    compiler_root, sdk = Path(sp1['root']).resolve(), Path(sp1['sdk']).resolve()
    cl, link = compiler_root / 'VC/bin/cl.exe', compiler_root / 'VC/bin/link.exe'
    require(sha256(cl) == sp1['cl_sha256'], 'compiler drift')
    require(sha256(link) == sp1['link_sha256'], 'linker drift')
    for directory in [compiler_root / 'VC/include', sdk / 'Include']:
        require(directory.is_dir(), 'missing explicit include root')
    require(sha256(repository / 'build/units.json') == RECIPE_HASH, 'reference recipe drift')
    require(sha256(repository / SOURCE) == SOURCE_HASH, 'entry source drift')
    canonical = '_fnv_code_' + hashlib.sha256(json.dumps(IDENTITY,
        sort_keys=True, separators=(',', ':')).encode()).hexdigest()
    require(canonical == CANONICAL, 'physical identity canonical spelling drift')
    sources = source_manifest(repository)
    plan = dict(schema_version=1, kind='game-startup-host-offline-plan',
        status='source-review-required', sources=sources,
        doctor_sha256=doctor_sha256,
        entry=dict(identity=IDENTITY.copy(), source=SOURCE, source_sha256=SOURCE_HASH,
            symbol='?FUN_0086a850@@YGHIIII@Z', section=199, value=0, size=4532,
            calling_convention='x86-stdcall', return_type='int32',
            argument_types=['uint32'] * 4, canonical_export=CANONICAL,
            original_caller_verified=False, application_ABI_approved=False),
        host=dict(source=HOST, defined_GUI_symbol='_WinMain@16',
            undefined_typed_symbol='_fnv_game_application_entry@16',
            proposed_identity_only_binding=CANONICAL, binding_approved=False,
            forwards=['HINSTANCE bits', 'previous HINSTANCE bits',
                      'borrowed ANSI command-tail pointer bits', 'show-state modulo 2^32']),
        compile_plan=dict(compiler=str(cl), compiler_sha256=sp1['cl_sha256'],
            flags=list(FLAGS), source=str(repository / HOST),
            output_basename='game_startup_host.obj',
            include_roots=[str(compiler_root / 'VC/include'), str(sdk / 'Include')],
            actual_includes_discovered=False, native_input_closure_verified=False),
        eventual_link_policy=dict(subsystem='windows', machine='x86',
            entry_override=None, normal_CRT_GUI_entry_required=True,
            candidate_static_CRT='SP1 LIBCMT; not adopted for game'),
        closure_gates={gate: False for gate in GATES},
        approvals=dict(compile=False, remap=False, link=False, execute=False,
                       provider=False, runnable_game=False))
    # Catch drift within observation; this is not a native tool closure attestation.
    require(source_manifest(repository) == sources, 'source drift during plan')
    require(sha256(doctor_path) == doctor_sha256 and
        sha256(cl) == sp1['cl_sha256'] and sha256(link) == sp1['link_sha256'],
        'doctor/tool drift during plan')
    return plan


def write_plan(plan, out, repository=ROOT):
    out, repository = Path(out).resolve(), Path(repository).resolve()
    if out.is_relative_to(repository):
        require(out.is_relative_to(repository / 'build/rebuild'), 'output must remain private')
    out.parent.mkdir(parents=True, exist_ok=True)
    with out.open('x', encoding='utf-8') as stream:
        json.dump(plan, stream, sort_keys=True, indent=2)
        stream.write('\n')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--doctor', type=Path, required=True)
    parser.add_argument('--doctor-sha256', required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    write_plan(build_plan(args.doctor, args.doctor_sha256), args.out)
    print('Offline startup plan written; no native preparation or execution approved.')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
