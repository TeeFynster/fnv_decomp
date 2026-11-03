"""Fixed source-built getter extraction and authored-storage symbolic TLS view.

No game PE payload is emitted; the old game TLS contribution is never retained.
"""
from __future__ import annotations
import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile

from coff_rewrite import strict_object
import tls_owner_fixture as tls
import toolchain

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'tools'))
import compare as oracle
from build_and_match import image_ok

sha, require, save = toolchain.sha256, tls.require, tls.save
POLICY = 'game-tls-getter-0781-v1'
PARENT, FIELD = '?GetTlsField@@YAHXZ', '?DAT_tls_field@@3HA'
ADDRESS, RECIPE_ID = '0x00404f50', '0781-3b6aac24065e157e'
EDGES = [(4, '__tls_index', 6), (11, '__tls_array', 6), (20, FIELD, 11)]
DEFAULTS = ['/DEFAULTLIB:"LIBCMT"', '/DEFAULTLIB:"OLDNAMES"']
DROP_ALIASES = [
    '/alternatename:?EffectSetting_GetArchetype@@YIHPAUEffectSetting@@@Z=?GetArchetype@EffectSetting@@QAEHXZ',
    '/alternatename:?EffectSetting_GetArchetype@@YIHAAVEffectSetting@@@Z=?GetArchetype@EffectSetting@@QAEHXZ']
ALIAS_ENDPOINTS = {name for directive in DROP_ALIASES for name in directive.split(':', 1)[1].split('=')}
PINS = dict(recipe='62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c',
    manifest='bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb',
    selection='48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1',
    verification='04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297',
    image='df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7',
    object='ab8a41852bfdda260348209f47ddc6ed125fd68a5228216f2b6656745cc15310',
    source='716b704c5f9e3893014f9458ad8020ddf47c1fdacd628fac62cf3a8fd6c96358')
CL_SHA = '2954bed141f2f283e3109b2187406704a2d5cb6378cb3074f1b09bc5045d65c1'
SPEC = dict(address=ADDRESS, symbol=PARENT, size=26)
SELECTED = dict(recipe_id=RECIPE_ID, recipe_index=781, symbol=PARENT, section=56, value=0, size=26,
                selection_status='CODE_OWNERSHIP_SELECTED', runtime_eligible=False, link_ready=False)
OWNER_PINS = {
    'tls_owner_fixture.hpp': 'e6205b276e450b144fd6fb3d18f0d48eac5e558241fcaee54559b4434608e785',
    'tls_owner_storage.cpp': '07ecac6f17a7eb18d9be8f74ff5e7ac66764f2249b60cce6251e7d4cb21a1b1f',
    'tls_owner_callback.cpp': 'ac6dda8e5c6c3d5d1195733155d5dc5e978c1803d9524072309946e8e23a5a05'}
VIEW = dict(symbol=FIELD, owner=tls.OWNER, source_member='context', offset=0x2b0, size=4, alignment=4)


def comparison(path, image, unit):
    report = oracle.compare(oracle.Coff(path), oracle.Pe(image), dict(functions=[SPEC], symbols=unit.get('symbols', {})))[0]
    require(report['verdict'] == 'match' and report['compiled_extent'] == 26 and not report['errors'] and not report['byte_differences'], 'unchanged getter comparison failed')
    require([(r['offset'], r['symbol'], r['kind']) for r in report['relocations']] == EDGES and all(r['match'] for r in report['relocations']), 'getter reference edges differ')
    return {k: v for k, v in report.items() if k != 'byte_differences'}


def verify_basis(manifest, selection, verification, image):
    paths = dict(manifest=Path(manifest).resolve(), selection=Path(selection).resolve(), verification=Path(verification).resolve(),
                 image=Path(image).resolve(), recipe=ROOT/'build/units.json', source=ROOT/'src/fallout_shared/magic/effectitem.cpp')
    require(len(set(paths.values())) == len(paths) and all(sha(path) == PINS[name] for name, path in paths.items()), 'stale/colliding fixed getter proof input')
    m, s, v = [json.loads(paths[key].read_text()) for key in ('manifest', 'selection', 'verification')]
    unit = json.loads(paths['recipe'].read_text())['units'][781]
    mu = [row for row in m['units'] if row['recipe_index'] == 781]
    vu = [row for row in v['units'] if row['recipe_index'] == 781]
    require(len(mu) == len(vu) == 1, 'missing/duplicate getter producer proof')
    mu, vu = mu[0], vu[0]
    require(m['kind'] == 'fnv-retained-objects' and m['recipe_manifest_sha256'] == PINS['recipe'] and
            mu['recipe'] == unit and mu['recipe_id'] == vu['recipe_id'] == RECIPE_ID and mu['status'] == 'compiled' and vu['status'] == 'ok', 'getter producer recipe differs')
    require(unit['compiler'] == 'sp1' and unit['flags'] == ['/MT', '/Od', '/Oy-', '/GS', '/EHsc', '/Gy', '/GF'] and
            m['toolchains']['sp1']['version'] == '15.00.30729.01' and m['toolchains']['sp1']['cl_sha256'] == CL_SHA, 'getter compiler/flags identity differs')
    require(mu['object_sha256'] == vu['object_sha256'] == PINS['object'] and
            mu['source_sha256'] == vu['source_sha256_recorded'] == vu['source_sha256_current'] == PINS['source'], 'getter source/object binding differs')
    require(s['kind'] == 'fnv-function-code-ownership-selection' and s['selections'].get(ADDRESS) == SELECTED and
            s['input_sha256']['recipe'] == PINS['recipe'] and s['input_sha256']['manifest'] == PINS['manifest'] and
            s['input_sha256']['receipt'] == PINS['verification'], 'selected getter ownership differs')
    require(v['kind'] == 'fnv-retained-object-verification' and v['scope']['full_authoritative'] is True and
            all(v.get(key) is True for key in ('retained_verification_pass', 'function_byte_verification_pass',
                'global_listed_eh_coverage_pass', 'original_oracle_parity_pass', 'evidence_stable')), 'getter verification gate absent')
    require(v['inputs']['retained_manifest_sha256'] == PINS['manifest'] and v['inputs']['recipe_sha256'] == PINS['recipe'] and
            v['inputs']['image_sha256'] == PINS['image'] and dict(SPEC, section=56, value=0, verdict='match') in vu['verified_functions'] and
            not vu.get('eh_errors') and not vu.get('mismatches'), 'specific getter proof absent/diagnosed')
    require(not v['inputs']['function_index_present'] and v['inputs']['function_index_sha256'] is None and
            not s['function_index_present'] and not (ROOT/'build/function_index.json').exists(), 'optional function index state changed')
    for name, expected in v['inputs']['tools_sha256'].items():
        path = (ROOT/name).resolve()
        require(path.is_relative_to(ROOT) and sha(path) == expected, 'original proof tool changed')
        paths['tool:'+name] = path
    path = ROOT/'build/image_check.json'
    require(sha(path) == v['inputs']['image_check_sha256'], 'image fingerprint specification changed')
    paths['image_check'] = path
    obj = (paths['manifest'].parent/mu['object']).resolve()
    require(obj.is_relative_to(paths['manifest'].parent) and sha(obj) == PINS['object'], 'getter object changed/escaped')
    native,_,_,_=strict_object(obj)
    select(native)  # Exact directive/closure policy is checked before fresh compilation.
    paths['object'] = obj
    for path in (Path(__file__), ROOT/'tools/rebuild/coff_rewrite.py', ROOT/'tools/rebuild/toolchain.py'):
        paths['extractor:'+path.name] = path
    gate = image_ok(oracle.Pe(paths['image']))
    require(gate[0], 'unchanged image fingerprint gate failed')
    checked = comparison(obj, paths['image'], unit)
    return dict(inputs={str(p): sha(p) for p in paths.values()}, object=str(obj), image=str(paths['image']), unit=unit,
                selected=SELECTED, image_gate=dict(passed=gate[0], matching=gate[1], total=gate[2]), comparison=checked,
                directives=dict(original=native.directives,output=DEFAULTS,dropped_exact_unrelated=DROP_ALIASES))


def caller_context(path, expected_hash):
    path = Path(path).resolve()
    require(sha(path) == expected_hash, 'fresh caller/storage context changed')
    proof = json.loads(path.read_text())
    require(proof.get('schema_version') == 1 and proof.get('kind') == 'game-tls-fresh-source-context' and
            proof.get('policy') == POLICY and proof.get('compiler_version') == '15.00.30729.01' and
            proof.get('compiler_sha256') == CL_SHA and proof.get('fresh_compile_observed') is True and proof.get('view') == VIEW,
            'unrecognized fresh storage/caller context')
    expected = {str((ROOT/'runtime/probes'/name).resolve()): digest for name, digest in OWNER_PINS.items()}
    main = ROOT/'runtime/probes/game_tls_probe.cpp'; expected[str(main.resolve())] = sha(main)
    require(proof.get('sources') == expected and all(sha(name) == digest for name, digest in expected.items()), 'caller/storage source identities differ')
    require(set(proof.get('objects', {})) == {'storage', 'callback', 'main'}, 'fresh source objects incomplete')
    observations = dict(expected); observations[str(path)] = expected_hash
    require(proof.get('compiler_inputs'), 'fresh compiler/header input context absent')
    for name, digest in proof['compiler_inputs'].items():
        require(sha(name) == digest, 'fresh compiler/header input changed')
        observations[name] = digest
    game_calls = []
    for role, row in proof['objects'].items():
        require(sha(row['path']) == row['sha256'], 'fresh source object changed')
        coff, _, _, _ = strict_object(row['path'])
        require(not ALIAS_ENDPOINTS.intersection(s['name'] for s in coff.symbols.values()), 'omitted alias endpoint appears in fresh caller/storage')
        require(not any(s['name'] == FIELD or (s['name'] == PARENT and s['section'] != 0) for s in coff.symbols.values()), 'fresh caller manufactures game field/function provider')
        for sec in coff.sections.values():
            for offset,index,kind in sec['relocs']:
                if coff.symbols[index]['name'] == PARENT:
                    require(sec['flags'] & 0x20 and kind == 20 and struct.unpack_from('<i',tls.section_payload(coff,sec['index']),offset)[0] == 0,
                            'fresh caller has unsupported game-call representation')
                    game_calls.append(role)
        observations[row['path']] = row['sha256']
    require(game_calls == ['main'], 'fresh caller must have exactly one direct selected-getter call site')
    tls.source_contract({role: row['path'] for role,row in proof['objects'].items()})
    return proof, observations


def select(coff):
    require(coff.directives == DROP_ALIASES+DEFAULTS, 'unknown/changed original directive token')
    require(not ALIAS_ENDPOINTS.intersection({PARENT, FIELD, '__tls_index', '__tls_array', tls.OWNER, tls.CALLBACK, tls.ENTRY}), 'omitted directive endpoint belongs to retained closure')
    parent = tls.named(coff, PARENT); sec = coff.sections[parent['section']]
    require((parent['section'], parent['value'], parent['type'], parent['storage'], parent['aux_count']) == (56, 0, 32, 2, 0) and
            (sec['name'], sec['size'], sec['flags'], sec['selection'], sec['association']) == ('.text', 26, 0x60501020, 'no_duplicates', 0), 'getter parent/shared code policy differs')
    require(not any(s['association'] == 56 for s in coff.sections.values()), 'getter has hidden associated child')
    members = [s for s in coff.symbols.values() if s['section'] == 56]
    require(len(members) == 2 and sum('section_aux' in s for s in members) == 1, 'getter has extra alias/local/EH record')
    section_symbol = next(s for s in members if 'section_aux' in s)
    require((section_symbol['name'],section_symbol['value'],section_symbol['type'],section_symbol['storage'],section_symbol['aux_count']) ==
            ('.text',0,0,3,1), 'getter section symbol differs')
    header=coff.unpack('<8sIIIIIIHHI',20+55*40)
    require(header[1]==header[2]==header[6]==header[8]==0,'unknown getter section address/line record')
    symptr=struct.unpack_from('<I',coff.data,8)[0]
    aux=coff.data[symptr+(section_symbol['index']+1)*18:symptr+(section_symbol['index']+2)*18]
    require(struct.unpack_from('<H',aux,6)[0]==0 and aux[15:]==bytes(3),'unknown getter auxiliary line/reserved field')
    require(section_symbol['section_aux']['relocation_count'] == 3, 'getter auxiliary relocation count differs')
    require([(o, coff.symbols[i]['name'], t) for o, i, t in sec['relocs']] == EDGES and
            all(struct.unpack_from('<I', tls.section_payload(coff, 56), offset)[0] == 0 for offset, _, _ in EDGES), 'getter edge/kind/addend changed')
    for name in ('__tls_index', '__tls_array'):
        symbol = tls.named(coff, name)
        require((symbol['section'], symbol['value'], symbol['storage'], symbol['type'], symbol['aux_count']) == (0, 0, 2, 0, 0), 'getter infrastructure reference role differs')
    field = tls.named(coff, FIELD); storage = coff.sections[field['section']]
    require((field['section'], field['value'], field['storage'], field['type'], field['aux_count']) == (4, 0x2b8, 2, 0, 0) and
            (storage['name'], storage['size'], storage['flags']) == ('.tls$', 700, 0xc0400040) and not storage['relocs'] and
            struct.unpack_from('<i', tls.section_payload(coff, 4), field['value'])[0] == 59, 'original field/source initializer evidence differs')
    for name, value in (('@comp.id', 8681481), ('@feat.00', 1)):
        s = tls.named(coff, name)
        require((s['section'], s['value'], s['storage'], s['type'], s['aux_count']) == (-1, value, 3, 0, 0), 'getter feature/producer metadata differs')
    return section_symbol


def getter_bytes(path):
    coff, _, _, _ = strict_object(path); selected = select(coff)
    directives = (' '+' '.join(DEFAULTS)+' ').encode('ascii')
    code = tls.section_payload(coff, 56)
    strings, records = bytearray(4), bytearray()
    def symbol(name, value, section, typ, storage, aux=b''):
        raw = name.encode('ascii')
        if len(raw) > 8:
            field = struct.pack('<II', 0, len(strings)); strings.extend(raw+b'\0')
        else:
            field = raw.ljust(8, b'\0')
        records.extend(struct.pack('<8sIhHBB', field, value, section, typ, storage, bool(aux))); records.extend(aux)
    symbol('@comp.id',8681481,-1,0,3); symbol('@feat.00',1,-1,0,3)
    symbol('.drectve',0,1,0,3,struct.pack('<IHHIhBBH',len(directives),0,0,0,0,0,0,0))
    a = selected['section_aux']
    symbol('.text',0,2,0,3,struct.pack('<IHHIhBBH',26,3,0,a['checksum'],0,1,0,0))
    symbol(PARENT,0,2,32,2)
    for name in ('__tls_index','__tls_array',FIELD):symbol(name,0,0,0,2)
    # Record indices include the two section auxiliaries: 7,8,9 are undefineds.
    raw1, raw2 = 100, 100+len(directives); relptr = raw2+26; symptr = relptr+30
    sections = struct.pack('<8sIIIIIIHHI',b'.drectve',0,0,len(directives),raw1,0,0,0,0,0x00100a00)
    sections += struct.pack('<8sIIIIIIHHI',b'.text',0,0,26,raw2,relptr,0,3,0,0x60501020)
    relocs = b''.join(struct.pack('<IIH',off,7+i,kind) for i,(off,_,kind) in enumerate(EDGES))
    struct.pack_into('<I',strings,0,len(strings))
    data = struct.pack('<HHIIIHH',0x14c,2,0,symptr,10,0,0)+sections+directives+code+relocs+records+strings
    return data, dict(original_directives=coff.directives, output_directives=DEFAULTS, dropped_unrelated_directives=DROP_ALIASES,
        original_native_field_offset=0x2b8, output_field_role='undefined symbolic SECREL field',
        omitted_sections=[dict(section=i,name=s['name']) for i,s in coff.sections.items() if i != 56])


def reparse_getter(original, output):
    before, _, _, _ = strict_object(original); after, _, _, _ = strict_object(output)
    require(len(after.sections) == 2 and after.directives == DEFAULTS and
            [s['name'] for s in after.sections.values()] == ['.drectve','.text'], 'unexpected getter output section/directive')
    require(len(after.symbols) == 8 and {s['name'] for s in after.symbols.values()} ==
            {'@comp.id','@feat.00','.drectve','.text',PARENT,FIELD,'__tls_index','__tls_array'}, 'hidden getter output symbol')
    a,b = before.sections[56],after.sections[2]
    require(tls.section_payload(before,56) == tls.section_payload(after,2) and
            all(a[k] == b[k] for k in ('size','flags','selection','association')), 'getter code/policy changed')
    require([(o,after.symbols[i]['name'],kind) for o,i,kind in b['relocs']] == EDGES, 'getter relocation remap differs')
    definitions = [s['name'] for s in after.symbols.values() if s['section'] > 0 and s['storage'] == 2]
    require(definitions == [PARENT], 'other game definition survived')
    require({s['name'] for s in after.symbols.values() if s['section'] == 0} == {FIELD,'__tls_index','__tls_array'}, 'getter external provider set differs')
    for name in (FIELD,'__tls_index','__tls_array'):
        s=tls.named(after,name);require((s['value'],s['type'],s['storage'],s['aux_count']) == (0,0,2,0), 'getter undefined symbol role changed')
    require(tls.named(after,'@feat.00')['value'] == 1, 'getter SafeSEH metadata missing')
    for name,value in (('@feat.00',1),('@comp.id',8681481)):
        s=tls.named(after,name);require((s['section'],s['value'],s['type'],s['storage'],s['aux_count']) == (-1,value,0,3,0), 'getter feature/producer symbol changed')
    original_aux = next(s['section_aux'] for s in before.symbols.values() if s['section']==56 and 'section_aux' in s)
    require(tls.named(after,'.text')['section_aux'] == original_aux, 'getter code auxiliary changed')


def publish_pair(output, receipt, data, report):
    created = []
    try:
        for path,content in ((output,data),(receipt,(json.dumps(report,indent=2)+'\n').encode())):
            Path(path).parent.mkdir(parents=True,exist_ok=True)
            with Path(path).open('xb') as stream:created.append(Path(path));stream.write(content)
    except BaseException:
        for path in reversed(created):path.unlink(missing_ok=True)
        raise


def extract(manifest, selection, verification, image, context, context_sha256, output, receipt):
    out,rp = Path(output).resolve(),Path(receipt).resolve()
    require(out != rp and not out.exists() and not rp.exists(), 'new distinct getter outputs required')
    basis = verify_basis(manifest,selection,verification,image)
    _, observed = caller_context(context,context_sha256); observed.update(basis['inputs'])
    require(str(out) not in observed and str(rp) not in observed, 'getter output/input collision')
    data,ledger=getter_bytes(basis['object']);out.parent.mkdir(parents=True,exist_ok=True)
    with tempfile.NamedTemporaryFile(dir=out.parent,suffix='.obj',delete=False) as stream:stage=Path(stream.name);stream.write(data)
    try:
        reparse_getter(basis['object'],stage)
        checked=comparison(stage,basis['image'],basis['unit'])
        tls.check_stable(observed)
        require(not (ROOT/'build/function_index.json').exists(), 'optional index appeared during extraction')
        report=dict(schema_version=1,kind='game-tls-getter-extraction',policy=POLICY,status='pass',inputs=observed,
            input_sha256=PINS['object'],output_sha256=hashlib.sha256(data).hexdigest(),selected=SELECTED,
            reference_comparison=checked,selection=ledger,independent_reparse=True,game_tls_payload_emitted=False)
        publish_pair(out,rp,data,report);return report
    finally:stage.unlink(missing_ok=True)


def alias_bytes(path, view):
    require(view == VIEW, 'unreviewed TLS field view/extent/alignment')
    coff,symptr,strptr,strlen=strict_object(path)
    require(not any(s['name'] == FIELD for s in coff.symbols.values()), 'TLS field alias already exists')
    owner=tls.named(coff,tls.OWNER);sec=coff.sections[owner['section']]
    require((owner['value'],owner['storage'],owner['type'],owner['aux_count']) == (0,2,0,0) and
            (sec['name'],sec['size'],sec['flags']) == ('.tls$',704,0xc0300040) and not sec['relocs'] and
            tls.section_payload(coff,owner['section']) == tls.authored_owner(), 'authored storage owner payload/layout changed')
    require(view['offset'] % view['alignment'] == 0 and view['offset']+view['size'] <= sec['size'] and
            struct.unpack_from('<i',tls.section_payload(coff,owner['section']),view['offset'])[0] == 37, 'source-defined context view differs')
    count=struct.unpack_from('<I',coff.data,12)[0]
    record=struct.pack('<8sIhHBB',struct.pack('<II',0,strlen),view['offset'],owner['section'],0,2,0)
    result=bytearray(coff.data[:strptr]+record+coff.data[strptr:]+FIELD.encode()+b'\0')
    struct.pack_into('<I',result,12,count+1);struct.pack_into('<I',result,strptr+18,strlen+len(FIELD)+1)
    return bytes(result),dict(section=owner['section'],offset=view['offset'],size=4,alignment=4,original_symbol_count=count,
        owner=tls.OWNER,symbol=FIELD,original_source_payload_unchanged=True,source_initialized_value=37)


def reparse_alias(original, output, view):
    before,symptr,strptr,strlen=strict_object(original);after,after_symptr,after_strptr,after_strlen=strict_object(output)
    count=struct.unpack_from('<I',before.data,12)[0]
    require(after_symptr == symptr and after_strptr == strptr+18 and struct.unpack_from('<I',after.data,12)[0] == count+1, 'alias symbol table geometry changed')
    require(after_strlen == strlen+len(FIELD)+1 and after.data[after_strptr+strlen:] == FIELD.encode()+b'\0', 'alias string table additions differ')
    require(all(a == b or 12 <= i < 16 for i,(a,b) in enumerate(zip(before.data[:strptr],after.data[:strptr]))) and
            before.data[strptr+4:] == after.data[after_strptr+4:after_strptr+strlen], 'alias modified non-symbol storage/code/metadata')
    require(set(after.sections) == set(before.sections) and all(before.sections[i] == after.sections[i] for i in before.sections), 'alias changed section/payload/relocation policy')
    require(all(after.symbols[i] == s for i,s in before.symbols.items()) and len(after.symbols) == len(before.symbols)+1, 'alias changed original symbol records')
    symbol=tls.named(after,FIELD)
    require((symbol['index'],symbol['section'],symbol['value'],symbol['storage'],symbol['type'],symbol['aux_count']) ==
            (count,tls.named(before,tls.OWNER)['section'],view['offset'],2,0,0), 'alias is not the exact physical TLS interior symbol')


def alias_storage(context, context_sha256, output, receipt):
    out,rp=Path(output).resolve(),Path(receipt).resolve()
    require(out != rp and not out.exists() and not rp.exists(), 'new distinct storage-view outputs required')
    proof,observed=caller_context(context,context_sha256);inp=Path(proof['objects']['storage']['path']).resolve()
    require(str(out) not in observed and str(rp) not in observed, 'storage alias output/input collision')
    data,view=alias_bytes(inp,proof['view']);out.parent.mkdir(parents=True,exist_ok=True)
    with tempfile.NamedTemporaryFile(dir=out.parent,suffix='.obj',delete=False) as stream:stage=Path(stream.name);stream.write(data)
    try:
        reparse_alias(inp,stage,VIEW);tls.check_stable(observed)
        report=dict(schema_version=1,kind='game-tls-authored-storage-view',policy=POLICY,status='pass',inputs=observed,
            input_sha256=sha(inp),output_sha256=hashlib.sha256(data).hexdigest(),view=view,context_sha256=context_sha256,
            independent_reparse=True,game_tls_payload_emitted=False,role='symbolic TLS interior, never an absolute/process-VA alias')
        publish_pair(out,rp,data,report);return report
    finally:stage.unlink(missing_ok=True)
