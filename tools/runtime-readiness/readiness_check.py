"""Read-only runtime readiness checker for a future private rebuild.

It answers one question: which inputs for a later, separately approved test
are present, missing or still unknown? It never answers "ready to launch".

What it does:
  * reads explicitly supplied paths (command line or a declarative manifest);
  * performs bounded, top-level metadata checks (one lstat per named entry,
    at most two path levels below a supplied root, plus a capped entry count
    for the isolated profile); nothing is opened, hashed or copied except the
    small JSON inputs the user hands it;
  * keeps confirmed requirements (user-supplied, with provenance) apart from
    observed evidence (the inventory snapshot and the original's imports);
  * reports every necessary contract that nobody has evidence for as unknown.

What it never does: launch or load anything, run compiler or linker probes,
read executable or asset contents, follow links or junctions, scan
directories recursively, touch Steam or user configuration, use the network,
or write anywhere except the explicit --out report.
"""
import argparse
import errno
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import re
import stat
import sys

HERE = Path(__file__).resolve().parent
INVENTORY_PATH = HERE / 'observed-inventory.json'

REPORT_SCHEMA = 'fnv-runtime-readiness-report'
MANIFEST_SCHEMA = 'fnv-runtime-readiness-manifest'
REQUIREMENTS_SCHEMA = 'fnv-runtime-readiness-requirements'
INVENTORY_SCHEMA = 'fnv-runtime-readiness-observed-inventory'
SCHEMA_VERSION = 1
TOOLCHAIN_SCHEMA_VERSION = 1  # tools/rebuild/toolchain.py report, schema_version 1
TOOLCHAIN_NAMES = ('sp1', 'rtm', 'vc8')

MAX_JSON_BYTES = 1024 * 1024
MAX_REQUIREMENTS = 512
MAX_PROVIDERS = 16
MAX_PROTECTED = 32
MAX_PROFILE_ENTRIES = 1000
MAX_DEPTH = 2

PRESENT, MISSING, UNKNOWN = 'present', 'missing', 'unknown'

PLACEHOLDERS = {
    'installation': '<owned-game-data>',
    'executable': '<private-built-exe>',
    'executable_directory': '<application-directory>',
    'working_directory': '<working-directory>',
    'isolated_profile': '<isolated-config-and-saves>',
    'dll_provider': '<verified-dll-providers>',
    'protected_path': '<protected-path>',
}
PATH_ROLES = ('installation', 'executable', 'working_directory', 'isolated_profile')
REQUIREMENT_ROLES = ('installation', 'executable_directory', 'working_directory',
                     'isolated_profile', 'dll_provider')

# Necessary contracts this checker cannot observe. They stay unknown unless a
# user supplies an attestation with provenance; even then the verdict is only
# "attested-pending-review", never ready or pass.
CONTRACTS = [
    ('build_gates_closed', 'Source link, CRT/TLS, ABI, resource and provider gates are independently closed and reviewed.'),
    ('platform_x86_windows_gui', 'The rebuilt executable is an x86 Windows GUI program (prospective target, not inspected here).'),
    ('rebuilt_dependency_set', "The rebuilt executable's own import set is known; the original's 17 imports are evidence only."),
    ('dll_versions_and_exports', 'Each provider DLL is x86, exports what the build imports, and has a reviewed version and licence.'),
    ('transitive_and_dynamic_loads', 'Transitive and runtime-selected (dynamically loaded) dependencies are identified.'),
    ('loader_search_policy', 'A private, verified DLL search policy is defined; no untrusted directory is on the search path.'),
    ('resource_identity', 'The rebuilt executable supplies or deliberately handles group icon 101 and any manifest/version needs.'),
    ('config_and_save_paths', 'Default and per-user INI locations, writable save/config locations and first-run behavior are known.'),
    ('working_directory_and_asset_lookup', 'The expected working directory and relative asset lookups are known.'),
    ('data_addons_localization', 'The Data archives, add-ons and localization needed for the chosen test are identified.'),
    ('steam_and_ownership_integration', 'Steam availability and integration needs are established through supported mechanisms only.'),
]
CONTRACT_IDS = {c for c, _ in CONTRACTS}


class InputError(Exception):
    """A supplied input cannot be used; the message never contains a path."""


# --------------------------------------------------------------------------
# small helpers

def _err_name(error):
    code = getattr(error, 'errno', None)
    return errno.errorcode.get(code, 'OSError') if code else type(error).__name__


def _norm(path):
    # Lexical only: no filesystem access and no link resolution. A link inside
    # a supplied path could therefore hide an overlap; supplied roots that are
    # links are reported as unknown instead of being followed.
    return Path(os.path.normcase(os.path.abspath(str(path))))


def _within(child, parent):
    child, parent = _norm(child), _norm(parent)
    return child == parent or parent in child.parents


_RESERVED = re.compile(r'^(con|prn|aux|nul|com[0-9¹²³]|lpt[0-9¹²³]|conin\$|conout\$)(\..*)?$', re.IGNORECASE)


def safe_input_path(value, label):
    """Refuse paths that could reach the network or a device instead of a local file."""
    text = str(value)
    if '\x00' in text:
        raise InputError('%s contains a NUL character' % label)
    if text.startswith(('\\\\', '//')):
        raise InputError('%s is a UNC or device path (\\\\server, \\\\?\\, \\\\.\\); only local paths are accepted' % label)
    for part in re.split(r'[\\/]', text):
        if _RESERVED.match(part.strip().rstrip('. ')):
            raise InputError('%s names a reserved Windows device; refusing' % label)
    return Path(text)


def _is_link(st):
    if stat.S_ISLNK(st.st_mode):
        return True
    return bool(getattr(st, 'st_file_attributes', 0) & getattr(stat, 'FILE_ATTRIBUTE_REPARSE_POINT', 0x400))


def _link_in_path(path, include_leaf=True):
    """Reject symlink/reparse ancestors before any descendant access.

    This is a best-effort preflight, not an atomic guarantee against concurrent
    filesystem replacement; callers must use a trusted, stable local tree.
    """
    path = Path(os.path.abspath(str(path)))
    chain = list(reversed(path.parents)) + ([path] if include_leaf else [])
    for part in chain:
        try:
            st = os.lstat(part)
        except FileNotFoundError:
            break
        if _is_link(st):
            return True
    return False


def _read_json(path, label):
    """Read a small JSON input. Errors name the label, never the path."""
    try:
        if _link_in_path(path):
            raise InputError('%s traverses a link or reparse point' % label)
        st = os.lstat(path)
        if not stat.S_ISREG(st.st_mode):
            raise InputError('%s is not a regular file' % label)
        if st.st_size > MAX_JSON_BYTES:
            raise InputError('%s is larger than %d bytes; refusing to read it' % (label, MAX_JSON_BYTES))
        with open(path, 'rb') as stream:
            data = stream.read(MAX_JSON_BYTES + 1)
    except InputError:
        raise
    except OSError as error:
        raise InputError('%s could not be read (%s)' % (label, _err_name(error)))
    if len(data) > MAX_JSON_BYTES:
        raise InputError('%s is larger than %d bytes; refusing to read it' % (label, MAX_JSON_BYTES))
    try:
        value = json.loads(data.decode('utf-8-sig'))
    except (UnicodeDecodeError, ValueError, RecursionError):
        raise InputError('%s is not valid UTF-8 JSON (or is nested too deeply)' % label)
    return value, hashlib.sha256(data).hexdigest()


def _is_version(value, expected):
    return type(value) is int and value == expected  # rejects True, 1.0 and "1"


def _check_schema(document, schema, label):
    if not isinstance(document, dict):
        raise InputError('%s must be a JSON object' % label)
    if document.get('schema') != schema or not _is_version(document.get('schema_version'), SCHEMA_VERSION):
        raise InputError('%s has an unrecognized schema; expected "%s" version %d'
                         % (label, schema, SCHEMA_VERSION))


def _relative_entry(text):
    """Validate a bounded relative entry such as 'Data/FalloutNV.esm'."""
    if not isinstance(text, str) or not text.strip():
        raise ValueError('path must be a non-empty string')
    text = text.replace('\\', '/')
    if '\x00' in text:
        raise ValueError('path contains a NUL character')
    if any(_RESERVED.match(p.strip().rstrip('. ')) for p in text.split('/')):
        raise ValueError('path names a reserved Windows device')
    pure = PurePosixPath(text)
    if pure.is_absolute() or ':' in text or text.startswith('//'):
        raise ValueError('path must be relative to its role root')
    parts = pure.parts
    # Check the raw segments: PurePosixPath silently drops '.' and empty ones.
    if any(p in ('', '.', '..') for p in text.split('/')):
        raise ValueError('path may not contain "." or ".." segments')
    if any(ch in text for ch in '*?[]'):
        raise ValueError('wildcards are not supported; name each entry')
    if len(parts) > MAX_DEPTH:
        raise ValueError('path is deeper than %d levels; only top-level metadata is checked' % MAX_DEPTH)
    return '/'.join(parts)


def _provenance_ok(value):
    return (isinstance(value, dict) and isinstance(value.get('source'), str) and value['source'].strip()
            and isinstance(value.get('basis'), str) and value['basis'].strip())


def _clean_provenance(value):
    keep = ('source', 'basis', 'author', 'model_or_tool_attribution', 'date', 'reference')
    return {k: scrub(value[k])[:500] for k in keep if isinstance(value.get(k), str)}


def probe_under(root, relative, kind):
    """Probe ``root/relative`` without following a link at any intermediate level."""
    parts = PurePosixPath(relative).parts
    current = Path(root)
    for part in parts[:-1]:
        current = current / part
        status, reason, evidence = probe(current, 'directory')
        if status != PRESENT:
            if evidence.get('link'):
                return UNKNOWN, 'parent "%s" is a link, junction or reparse point; not followed' % part, {}
            return status, 'parent "%s": %s' % (part, reason), {}
    return probe(current / parts[-1], kind)


def probe(path, kind):
    """One lstat of one entry. Returns (status, reason, evidence)."""
    try:
        if _link_in_path(path, include_leaf=False):
            return UNKNOWN, 'ancestor is a link, junction or reparse point; not followed', {'link': True}
        st = os.lstat(path)
    except (FileNotFoundError, NotADirectoryError):
        return MISSING, 'not found', {}
    except PermissionError:
        return UNKNOWN, 'metadata not readable (permission denied)', {}
    except OSError as error:
        return UNKNOWN, 'metadata not readable (%s)' % _err_name(error), {}
    except ValueError:
        return UNKNOWN, 'path not usable', {}
    if _is_link(st):
        return UNKNOWN, 'symbolic link, junction or reparse point; not followed', {'link': True}
    if stat.S_ISDIR(st.st_mode):
        found = 'directory'
    elif stat.S_ISREG(st.st_mode):
        found = 'file'
    else:
        return UNKNOWN, 'not a regular file or directory', {}
    evidence = {'kind': found}
    if found == 'file':
        evidence['size_bytes'] = st.st_size
    if found != kind:
        return MISSING, 'found a %s where a %s is expected' % (found, kind), evidence
    return PRESENT, 'top-level metadata observed', evidence


def _item(item_id, category, status, necessary, basis, reason, **extra):
    entry = dict(id=item_id, category=category, status=status, necessary=necessary,
                 basis=basis, reason=reason)
    entry.update(extra)
    return entry


# --------------------------------------------------------------------------
# inputs

def load_manifest(path):
    document, digest = _read_json(path, 'manifest')
    _check_schema(document, MANIFEST_SCHEMA, 'manifest')
    allowed = {'schema', 'schema_version', 'description', 'paths', 'protected_paths', 'launch'}
    unknown = sorted(set(document) - allowed)
    if unknown:
        raise InputError('manifest has unsupported keys')
    base = Path(os.path.abspath(str(path))).parent
    paths = document.get('paths', {})
    if not isinstance(paths, dict):
        raise InputError('manifest "paths" must be an object')
    unknown = sorted(set(paths) - set(PATH_ROLES) - {'dll_providers'})
    if unknown:
        raise InputError('manifest paths has unsupported keys')

    def resolve(value, label):
        if not isinstance(value, str) or not value.strip():
            raise InputError('manifest %s must be a non-empty string' % label)
        candidate = safe_input_path(value, 'manifest ' + label)  # no environment-variable or ~ expansion
        return candidate if candidate.is_absolute() else base / candidate

    result = {role: resolve(paths[role], role) for role in PATH_ROLES if paths.get(role) is not None}
    providers = paths.get('dll_providers', [])
    protected = document.get('protected_paths', [])
    for label, values in (('dll_providers', providers), ('protected_paths', protected)):
        if not isinstance(values, list):
            raise InputError('manifest %s must be a list' % label)
    result['dll_providers'] = [resolve(v, 'dll_providers entry') for v in providers]
    result['protected_paths'] = [resolve(v, 'protected_paths entry') for v in protected]
    launch = document.get('launch', {})
    if isinstance(launch, dict) and set(launch) - {'arguments'}:
        raise InputError('manifest launch has unsupported keys')
    if not isinstance(launch, dict) or not isinstance(launch.get('arguments', []), list) \
            or not all(isinstance(a, str) for a in launch.get('arguments', [])):
        raise InputError('manifest "launch.arguments" must be a list of strings')
    result['arguments'] = list(launch.get('arguments', []))
    return result, digest


def load_requirements(path):
    """Return (requirements, attestations, provenance, digest, rejected)."""
    document, digest = _read_json(path, 'requirements file')
    _check_schema(document, REQUIREMENTS_SCHEMA, 'requirements file')
    provenance = document.get('provenance')
    if not _provenance_ok(provenance):
        raise InputError('requirements file needs a top-level "provenance" with "source" and "basis"')
    entries = document.get('requirements', [])
    attestations = document.get('attestations', [])
    if not isinstance(entries, list) or not isinstance(attestations, list):
        raise InputError('"requirements" and "attestations" must be lists')
    if len(entries) > MAX_REQUIREMENTS:
        raise InputError('more than %d requirements; refusing' % MAX_REQUIREMENTS)
    accepted, rejected, seen = [], [], set()
    allowed = {'id', 'role', 'path', 'kind', 'min_size_bytes', 'expected_size_bytes', 'provenance', 'note'}
    for index, entry in enumerate(entries):
        label = 'requirement[%d]' % index
        try:
            if not isinstance(entry, dict):
                raise ValueError('must be an object')
            label = str(entry.get('id') or label)
            extra = sorted(set(entry) - allowed)
            if extra:
                raise ValueError('unsupported keys')
            if not isinstance(entry.get('id'), str) or not entry['id'].strip():
                raise ValueError('needs an "id"')
            if entry['id'] in seen:
                raise ValueError('duplicate id')
            if entry.get('role') not in REQUIREMENT_ROLES:
                raise ValueError('role must be one of %s' % ', '.join(REQUIREMENT_ROLES))
            if entry.get('kind') not in ('file', 'directory'):
                raise ValueError('kind must be "file" or "directory"')
            relative = _relative_entry(entry.get('path'))
            for key in ('min_size_bytes', 'expected_size_bytes'):
                if key in entry and (not isinstance(entry[key], int) or isinstance(entry[key], bool) or entry[key] < 0):
                    raise ValueError('%s must be a non-negative integer' % key)
            own = entry.get('provenance')
            if own is not None and not _provenance_ok(own):
                raise ValueError('per-item provenance needs "source" and "basis"')
            seen.add(entry['id'])
            accepted.append(dict(entry, path=relative, provenance=_clean_provenance(own or provenance)))
        except ValueError as problem:
            rejected.append((label, str(problem)))
    clean_attestations, attestation_rejects = [], []
    for index, entry in enumerate(attestations):
        if (not isinstance(entry, dict) or not isinstance(entry.get('contract'), str)
                or entry['contract'] not in CONTRACT_IDS):
            attestation_rejects.append('attestation[%d]: unknown contract id' % index)
        elif not isinstance(entry.get('statement'), str) or not entry['statement'].strip():
            attestation_rejects.append('attestation[%d]: needs a "statement"' % index)
        elif not _provenance_ok(entry.get('provenance')):
            attestation_rejects.append('attestation[%d]: needs provenance with "source" and "basis"' % index)
        else:
            clean_attestations.append(dict(contract=entry['contract'], statement=scrub(entry['statement'])[:1000],
                                           provenance=_clean_provenance(entry['provenance'])))
    return accepted, clean_attestations, _clean_provenance(provenance), digest, rejected, attestation_rejects


_VERSION_TEXT = re.compile(r'^[0-9]{1,5}(\.[0-9]{1,6}){0,3}$', re.ASCII)


def load_toolchain_report(path):
    """Consume an existing toolchain doctor report as data; never re-run probes."""
    base = dict(id='evidence.toolchain_report', category='supplementary-evidence', necessary=False,
                basis='user-supplied-report')
    try:
        document, digest = _read_json(path, 'toolchain report')
    except InputError as problem:
        return dict(base, status=UNKNOWN, reason=str(problem))
    toolchains = document.get('toolchains') if isinstance(document, dict) else None
    if (not isinstance(document, dict) or not _is_version(document.get('schema_version'), TOOLCHAIN_SCHEMA_VERSION)
            or not isinstance(toolchains, dict) or set(toolchains) != set(TOOLCHAIN_NAMES)
            or not all(isinstance(v, dict) and isinstance(v.get('ready'), bool) for v in toolchains.values())):
        return dict(base, status=UNKNOWN, sha256=digest,
                    reason='unrecognized toolchain report schema (expected schema_version %d with %s)'
                           % (TOOLCHAIN_SCHEMA_VERSION, '/'.join(TOOLCHAIN_NAMES)))
    summary = {}
    for name in TOOLCHAIN_NAMES:
        entry = toolchains[name]
        version = entry.get('version')
        summary[name] = dict(ready=entry['ready'],
                             reported_version=version if isinstance(version, str) and _VERSION_TEXT.match(version) else None)
    not_ready = [n for n in TOOLCHAIN_NAMES if not summary[n]['ready']]
    return dict(base, status=MISSING if not_ready else PRESENT, sha256=digest, toolchains=summary,
                reason=('report says not ready: %s' % ', '.join(not_ready)) if not_ready else
                'report says all compiler probes passed when it was written',
                caveat='Self-reported build-environment evidence, not re-run or authenticated; '
                       'says nothing about runtime readiness. Private roots and banners are not copied.')


def load_inventory():
    document, digest = _read_json(INVENTORY_PATH, 'observed inventory')
    _check_schema(document, INVENTORY_SCHEMA, 'observed inventory')
    return document, digest


# --------------------------------------------------------------------------
# checks

_PRIVATE_PATH = re.compile(r'(?:\b[A-Za-z]:[\\/]|\\\\[^\\/\s]|/(?:home|Users|mnt|root|media|var|tmp)/)\S*')


def scrub(text):
    """Replace anything that looks like an absolute local path in free text."""
    return _PRIVATE_PATH.sub('<redacted-path>', text) if isinstance(text, str) else text


def _redact_argument(argument):
    return scrub(argument)


def check(inputs, requirements_path=None, toolchain_report=None):
    """Build the report dict. ``inputs`` maps roles to Path or None."""
    items, safety, notes = [], [], []
    installation = inputs.get('installation')
    executable = inputs.get('executable')
    working = inputs.get('working_directory')
    profile = inputs.get('isolated_profile')
    providers = list(inputs.get('dll_providers') or [])
    protected = list(inputs.get('protected_paths') or [])
    if len(providers) > MAX_PROVIDERS or len(protected) > MAX_PROTECTED:
        raise InputError('too many provider or protected paths (limits %d and %d)' % (MAX_PROVIDERS, MAX_PROTECTED))
    root_status = {}

    # --- supplied locations
    specs = [('installation', installation, 'directory', 'owned installation'),
             ('executable', executable, 'file', 'prospective private rebuilt executable'),
             ('working_directory', working, 'directory', 'intended working directory'),
             ('isolated_profile', profile, 'directory', 'isolated config/save location')]
    for role, path, kind, label in specs:
        if path is None:
            status, reason, evidence = UNKNOWN, 'not supplied', {}
            if role == 'executable':
                reason = 'not supplied; no rebuilt executable exists yet'
        else:
            status, reason, evidence = probe(path, kind)
            if role == 'executable' and status == MISSING:
                reason += '; a rebuilt executable is required before any launch plan'
        root_status[role] = status
        extra = {}
        if role == 'executable':
            extra['caveat'] = ('Only file metadata was observed. Contents, PE headers, platform, imports and '
                               'resources were not inspected; a non-empty file is not evidence of a working build.')
        items.append(_item('input.' + role, 'supplied-location', status, True, 'checker-observed',
                           reason, label=label, location=PLACEHOLDERS[role], evidence=evidence, **extra))

    if not providers:
        items.append(_item('input.dll_providers', 'supplied-location', UNKNOWN, True, 'checker-observed',
                           'no DLL provider locations supplied; which providers the rebuild needs is unverified',
                           location=PLACEHOLDERS['dll_provider']))
    provider_ok = []
    for index, path in enumerate(providers):
        status, reason, evidence = probe(path, 'directory')
        provider_ok.append(status == PRESENT)
        items.append(_item('input.dll_provider[%d]' % index, 'supplied-location', status, True,
                           'checker-observed', reason, location='%s[%d]' % (PLACEHOLDERS['dll_provider'], index),
                           evidence=evidence,
                           caveat='Presence of a directory proves nothing about the x86 compatibility, '
                                  'exports, version or licence of the DLLs in it.'))

    # --- safety and isolation (lexical comparisons plus stat-based identity only)
    def block(finding_id, reason):
        safety.append(dict(id=finding_id, severity='block', reason=reason))

    def warn(finding_id, reason):
        safety.append(dict(id=finding_id, severity='warn', reason=reason))

    if executable is not None and installation is not None:
        original = Path(installation) / 'FalloutNV.exe'
        same = False
        try:  # lstat identity: does not follow links
            same = os.path.samestat(os.lstat(executable), os.lstat(original))
        except (OSError, ValueError):
            pass
        if same or _norm(executable) == _norm(original):
            block('executable-is-original', 'The supplied executable is the original FalloutNV.exe. '
                  'The original stays untouched and is not a runtime provider for the rebuild.')
        elif _within(executable, installation):
            block('executable-inside-installation', 'The rebuilt executable is inside the owned installation. '
                  'Keep it in a private location outside the installation so the installation is never modified.')
    if profile is not None:
        if installation is not None and (_within(profile, installation) or _within(installation, profile)):
            block('profile-overlaps-installation', 'The isolated config/save location overlaps the installation.')
        for index, path in enumerate(protected):
            if _within(profile, path) or _within(path, profile):
                block('profile-overlaps-protected[%d]' % index, 'The isolated config/save location overlaps '
                      'protected path %d (existing user configuration or saves).' % index)
        if executable is not None and _within(executable, profile):
            warn('executable-inside-profile', 'The executable is inside the isolated profile; keep build output separate.')
        if root_status.get('isolated_profile') == PRESENT:
            try:
                count, capped = 0, False
                with os.scandir(profile) as entries:
                    for _ in entries:
                        count += 1
                        if count >= MAX_PROFILE_ENTRIES:
                            capped = True
                            break
                writable = os.access(profile, os.W_OK)
                for entry in items:
                    if entry['id'] == 'input.isolated_profile':
                        entry['evidence'].update(top_level_entries=count, count_capped=capped,
                                                 writable_by_access_check=writable)
                if count:
                    warn('profile-not-empty', 'The isolated location already has %s%d top-level entries; '
                         'confirm none are existing user saves or configuration.' % ('>=' if capped else '', count))
                if not writable:
                    warn('profile-not-writable', 'os.access reports the isolated location is not writable.')
            except OSError as error:
                warn('profile-not-listable', 'Could not count isolated location entries (%s).' % _err_name(error))
    if working is not None and installation is not None and _within(working, installation):
        warn('working-directory-inside-installation', 'The working directory is inside the installation; '
             'relative writes by a future build could land there. Expected writes are unverified.')
    if working is not None and executable is not None and _norm(working) == _norm(Path(executable).parent):
        notes.append('The working directory equals the executable directory; the test record must still list them separately.')
    for index, path in enumerate(providers):
        if installation is not None and _within(path, installation):
            warn('provider-in-installation[%d]' % index, 'DLL provider %d is inside the installation. Game-local '
                 'libraries are unverified for the rebuild and the installation does not supply system components.' % index)
        if working is not None and _norm(path) == _norm(working):
            warn('provider-is-working-directory[%d]' % index, 'DLL provider %d is the working directory; avoid '
                 'adding the working directory to the DLL search path.' % index)
    for index, path in enumerate(protected):
        if installation is not None and _within(path, installation):
            notes.append('Protected path %d lies inside the installation.' % index)
        if working is not None and (_within(working, path) or _within(path, working)):
            block('working-directory-overlaps-protected[%d]' % index, 'The working directory overlaps protected '
                  'path %d; relative writes by a future build could change existing configuration or saves.' % index)
        if executable is not None and _within(executable, path):
            warn('executable-inside-protected[%d]' % index, 'The executable is inside protected path %d.' % index)
        for provider_index, provider in enumerate(providers):
            if _within(provider, path):
                warn('provider-inside-protected[%d]' % provider_index,
                     'DLL provider %d is inside protected path %d.' % (provider_index, index))
    if profile is not None and not protected:
        warn('protected-paths-not-supplied', 'No --protected-path was supplied, so overlap between the isolated '
             'location and existing user configuration or saves could not be checked.')

    # --- user-supplied requirements (confirmed only by their stated provenance)
    requirements_info = dict(supplied=False)
    attestations = []
    if requirements_path is not None:
        accepted, attestations, provenance, digest, rejected, attestation_rejects = load_requirements(requirements_path)
        requirements_info = dict(supplied=True, sha256=digest, provenance=provenance,
                                 accepted=len(accepted), rejected=len(rejected),
                                 rejected_attestations=attestation_rejects)
        roots = {'installation': installation, 'working_directory': working, 'isolated_profile': profile,
                 'executable_directory': Path(executable).parent if executable is not None else None}
        root_ok = {'installation': root_status.get('installation') == PRESENT,
                   'working_directory': root_status.get('working_directory') == PRESENT,
                   'isolated_profile': root_status.get('isolated_profile') == PRESENT,
                   'executable_directory': root_status.get('executable') == PRESENT}
        for label, problem in rejected:
            items.append(_item('requirement.' + scrub(label), 'user-requirement', UNKNOWN, True, 'user-supplied',
                               'requirement rejected as untrusted: ' + scrub(problem)))
        for entry in accepted:
            role, relative = entry['role'], entry['path']
            location = '%s/%s' % (PLACEHOLDERS[role], relative)
            extra = dict(location=location, provenance=entry['provenance'])
            if entry.get('note'):
                extra['note'] = scrub(str(entry['note']))[:500]
            if role == 'dll_provider':
                observations = [probe_under(p, relative, entry['kind'])[0] if provider_ok[i] else UNKNOWN
                                for i, p in enumerate(providers)]
                found = [i for i, status in enumerate(observations) if status == PRESENT]
                if not providers or not any(provider_ok):
                    status, reason = UNKNOWN, 'no present DLL provider location to check'
                elif found:
                    status, reason = PRESENT, 'name observed in provider location(s) %s' % found
                elif UNKNOWN in observations:
                    status, reason = UNKNOWN, 'not found in readable providers; another candidate is unknown'
                else:
                    status, reason = MISSING, 'not found in any supplied provider location'
                items.append(_item('requirement.' + scrub(entry['id']), 'user-requirement', status, True, 'user-supplied',
                                   reason, caveat='Filename presence does not prove compatibility.', **extra))
                continue
            if roots[role] is None or not root_ok[role]:
                items.append(_item('requirement.' + scrub(entry['id']), 'user-requirement', UNKNOWN, True, 'user-supplied',
                                   'role root not supplied or not present', **extra))
                continue
            status, reason, evidence = probe_under(roots[role], relative, entry['kind'])
            size = evidence.get('size_bytes')
            if status == PRESENT and size is not None:
                if 'min_size_bytes' in entry and size < entry['min_size_bytes']:
                    status, reason = MISSING, 'smaller than the supplied minimum size'
                if 'expected_size_bytes' in entry and size != entry['expected_size_bytes']:
                    status, reason = MISSING, 'size differs from the supplied expected size'
            items.append(_item('requirement.' + scrub(entry['id']), 'user-requirement', status, True, 'user-supplied',
                               reason, evidence=evidence, **extra))

    # --- contracts the checker cannot observe
    attested = {}
    for entry in attestations:
        attested.setdefault(entry['contract'], []).append(entry)
    for contract_id, description in CONTRACTS:
        if contract_id in attested:
            items.append(_item('contract.' + contract_id, 'contract', PRESENT, True, 'user-attested',
                               'attested by the user; not verified by this checker',
                               description=description, attestations=attested[contract_id]))
        else:
            items.append(_item('contract.' + contract_id, 'contract', UNKNOWN, True, 'none',
                               'no evidence supplied; cannot be established from filenames or source symbols',
                               description=description))

    # --- observed evidence (never requirements)
    inventory, inventory_digest = load_inventory()
    observed = []
    names = list(inventory['installation_entries'])
    stems = inventory['addon_stems']
    for stem in stems['main_only'] + stems['with_sounds']:
        for suffix in ('.esm', '.nam', ' - Main.bsa'):
            names.append(dict(path='Data/%s%s' % (stem, suffix), kind='file'))
    for stem in stems['with_sounds']:
        names.append(dict(path='Data/%s - Sounds.bsa' % stem, kind='file'))
    install_ok = root_status.get('installation') == PRESENT
    for entry in names:
        if not install_ok:
            status, reason, evidence = UNKNOWN, 'installation not supplied or not present', {}
        else:
            status, reason, evidence = probe_under(installation, entry['path'], entry['kind'])
        record = _item('observed.' + entry['path'], 'observed-snapshot', status, False, 'observed-snapshot',
                       reason, location='%s/%s' % (PLACEHOLDERS['installation'], entry['path']),
                       confirmed_requirement=False)
        if 'observed_size' in entry and 'size_bytes' in evidence:
            record['size_matches_snapshot'] = evidence['size_bytes'] == entry['observed_size']
        if entry.get('note'):
            record['note'] = entry['note']
        observed.append(record)

    leads = []
    for dll in inventory['original_normal_imports']['dlls'] + [
            dict(name=n, dynamic=True) for n in inventory['original_normal_imports']['optional_dynamic_loads']['names']]:
        seen_in = [i for i, p in enumerate(providers) if provider_ok[i]
                   and probe_under(p, dll['name'], 'file')[0] == PRESENT]
        leads.append(dict(id='lead.' + dll['name'], category='investigation-lead', status=UNKNOWN, necessary=False,
                          basis='original-dynamic-load-evidence' if dll.get('dynamic') else 'original-import-evidence',
                          reason='imported or dynamically tried by the ORIGINAL executable; whether the rebuild needs '
                                 'it, and which compatible x86 provider supplies it, is unverified',
                          filename_seen_in_providers=seen_in, original_slots=dll.get('slots')))

    # --- verdict: never "ready" or "pass"
    necessary = [i for i in items if i['necessary']]
    blocked = [s for s in safety if s['severity'] == 'block']
    missing = [i['id'] for i in necessary if i['status'] == MISSING]
    unknown = [i['id'] for i in necessary if i['status'] == UNKNOWN]
    if blocked or missing:
        verdict = 'not-ready'
        statement = 'Necessary inputs are missing or a safety rule is violated.'
    elif unknown:
        verdict = 'unknown'
        statement = 'Necessary contracts or inputs are unknown; readiness cannot be claimed.'
    else:
        verdict = 'attested-pending-review'
        statement = ('Every necessary item is present or user-attested. This is not a verified readiness '
                     'result and does not authorize a launch; attestations need independent review.')
    executable_absent = root_status.get('executable') != PRESENT

    return dict(
        schema=REPORT_SCHEMA, schema_version=SCHEMA_VERSION,
        tool='tools/runtime-readiness/readiness_check.py',
        mode='read-only top-level metadata',
        overall=dict(verdict=verdict, statement=statement, launch_authorized=False,
                     executable_absent=executable_absent,
                     counts=dict(necessary=len(necessary), missing=len(missing), unknown=len(unknown),
                                 present=len(necessary) - len(missing) - len(unknown),
                                 present_checker_observed=sum(1 for i in necessary if i['status'] == PRESENT
                                                              and i['basis'] == 'checker-observed'),
                                 present_user_supplied=sum(1 for i in necessary if i['status'] == PRESENT
                                                           and i['basis'] == 'user-supplied'),
                                 present_user_attested_only=sum(1 for i in necessary if i['status'] == PRESENT
                                                                and i['basis'] == 'user-attested'),
                                 safety_blocks=len(blocked))),
        missing_necessary=missing, unknown_necessary=unknown,
        safety_findings=safety, notes=notes,
        items=items,
        observed_inventory=dict(provenance=inventory['provenance'], sha256=inventory_digest,
                                statement='Observed names only; not requirements. Missing entries do not fail the check.',
                                entries=observed),
        investigation_leads=dict(statement=inventory['original_normal_imports']['statement'], entries=leads),
        requirements=requirements_info,
        toolchain_report=toolchain_report,
        launch=dict(arguments=[_redact_argument(a) for a in inputs.get('arguments') or []],
                    working_directory=PLACEHOLDERS['working_directory'],
                    application_directory=PLACEHOLDERS['executable_directory']),
        privacy=dict(local_paths_included=False,
                     statement='Locations are role placeholders; no absolute paths, file contents or hashes of game files.'),
    )


def _local_strings(inputs):
    values = [inputs.get(r) for r in PATH_ROLES] + list(inputs.get('dll_providers') or []) \
        + list(inputs.get('protected_paths') or [])
    out = set()
    for value in values:
        if value is None:
            continue
        form = os.path.abspath(str(value))
        out.add(form)
        out.add(json.dumps(form)[1:-1])  # as it appears inside JSON strings
    return out


def finalize(report, inputs, include_local_paths):
    if include_local_paths:
        report['privacy'] = dict(local_paths_included=True,
                                 statement='PRIVATE REPORT: contains local absolute paths. Keep it outside the '
                                           'repository and never publish or share it.')
        report['local_detail'] = {role: os.path.abspath(str(inputs[role]))
                                  for role in PATH_ROLES if inputs.get(role) is not None}
        report['local_detail']['dll_providers'] = [os.path.abspath(str(p))
                                                   for p in inputs.get('dll_providers') or []]
        report['local_detail']['protected_paths'] = [os.path.abspath(str(p))
                                                     for p in inputs.get('protected_paths') or []]
        return report
    rendered = json.dumps(report)
    leaked = [s for s in _local_strings(inputs) if s in rendered]
    if leaked:  # defence in depth: never emit a private path by default
        raise RuntimeError('internal error: a local path reached the default report')
    return report


def render_text(report):
    overall = report['overall']
    counts = overall['counts']
    lines = ['FNV runtime readiness (read-only metadata check)',
             'Verdict: %s  (launch authorized: no)' % overall['verdict'].upper(),
             overall['statement'],
             'Necessary items: %d present (%d observed by the checker, %d user-supplied, %d user-attested only), '
             '%d missing, %d unknown; safety blocks: %d'
             % (counts['present'], counts['present_checker_observed'], counts['present_user_supplied'],
                counts['present_user_attested_only'], counts['missing'], counts['unknown'], counts['safety_blocks'])]
    if overall['executable_absent']:
        lines.append('The rebuilt executable is absent or unconfirmed.')
    if report['safety_findings']:
        lines.append('')
        lines.append('Safety and isolation:')
        lines += ['  [%s] %s: %s' % (s['severity'], s['id'], s['reason']) for s in report['safety_findings']]
    lines.append('')
    lines.append('Necessary items:')
    for entry in report['items']:
        where = entry.get('location', '')
        lines.append('  %-8s %s%s  [%s] %s' % (entry['status'], entry['id'], ('  ' + where) if where else '',
                                              entry['basis'], entry['reason']))
    observed = report['observed_inventory']['entries']
    seen = sum(1 for e in observed if e['status'] == PRESENT)
    lines.append('')
    lines.append('Observed snapshot (evidence only, not requirements): %d of %d names present'
                 % (seen, len(observed)))
    leads = report['investigation_leads']['entries']
    lines.append('Investigation leads (original imports; all unknown for the rebuild): %d names, %d seen in providers'
                 % (len(leads), sum(1 for e in leads if e['filename_seen_in_providers'])))
    toolchain = report.get('toolchain_report')
    if toolchain:
        lines.append('Toolchain report (supplementary): %s - %s' % (toolchain['status'], toolchain['reason']))
    for note in report['notes']:
        lines.append('Note: ' + note)
    lines.append('')
    lines.append(report['privacy']['statement'])
    return '\n'.join(lines) + '\n'


# No verdict exits 0: nothing this tool can observe proves readiness.
EXIT_CODES = {'unknown': 1, 'not-ready': 3, 'attested-pending-review': 4}
EXIT_INPUT_ERROR = 2


class _Parser(argparse.ArgumentParser):
    def error(self, message):
        # argparse would echo the offending value, which may be a private path.
        self.exit(EXIT_INPUT_ERROR, 'error: invalid command line (see --help)\n')


def _same_file(a, b):
    try:
        return os.path.samestat(os.lstat(a), os.lstat(b))
    except (OSError, ValueError):
        return False


def _check_out(out, inputs, input_files, overwrite):
    """Refuse an --out that could change an input, an owned location or user data."""
    if overwrite:
        raise InputError('--overwrite is disabled; choose a new output file')
    try:
        if _link_in_path(out, include_leaf=False):
            raise InputError('--out parent traverses a link or reparse point')
    except OSError as error:
        raise InputError('--out parent metadata not readable (%s)' % _err_name(error))
    roots = [('installation', inputs.get('installation')), ('isolated profile', inputs.get('isolated_profile')),
             ('working directory', inputs.get('working_directory'))]
    if inputs.get('executable') is not None:
        roots.append(('executable directory', Path(inputs['executable']).parent))
    roots += [('DLL provider', p) for p in inputs.get('dll_providers') or []]
    roots += [('protected path', p) for p in inputs.get('protected_paths') or []]
    for label, root in roots:
        if root is not None and _within(out, root):
            raise InputError('--out may not be inside a %s' % label)
    for label, path in input_files:
        if path is not None and (_norm(out) == _norm(path) or _same_file(out, path)):
            raise InputError('--out may not replace the %s' % label)
    if _within(out, HERE):
        raise InputError('--out may not be inside the tool directory')
    if os.path.lexists(out):
        try:
            if _is_link(os.lstat(out)):
                raise InputError('--out is a link; refusing to write through it')
        except OSError as error:
            raise InputError('--out metadata not readable (%s)' % _err_name(error))
        if not overwrite:
            raise InputError('--out already exists; pass --overwrite to replace it')
        if not os.path.isfile(out):
            raise InputError('--out exists and is not a regular file')
    if not os.path.isdir(os.path.dirname(os.path.abspath(out))):
        raise InputError('--out directory does not exist; create it first')


def _ascii(text):
    return text.encode('ascii', 'backslashreplace').decode('ascii')


def main(argv=None, stdout=None):
    stdout = stdout or sys.stdout
    parser = _Parser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--manifest', type=Path, help='declarative JSON manifest (see examples/)')
    parser.add_argument('--installation', type=Path, help='owned installation directory')
    parser.add_argument('--executable', type=Path, help='prospective private rebuilt executable')
    parser.add_argument('--working-dir', type=Path, help='intended working directory')
    parser.add_argument('--isolated-profile', type=Path, help='isolated config/save location')
    parser.add_argument('--dll-provider', type=Path, action='append', default=[], help='DLL provider directory (repeatable)')
    parser.add_argument('--protected-path', type=Path, action='append', default=[],
                        help='existing config/save location that must not overlap the isolated profile, '
                             'working directory or --out (compared lexically; never opened or listed)')
    parser.add_argument('--requirements', type=Path, help='user-supplied requirements/attestations JSON with provenance')
    parser.add_argument('--toolchain-report', type=Path, help='existing tools/rebuild/toolchain.py JSON report (read as data)')
    parser.add_argument('--format', choices=('text', 'json'), default='text', help='stdout format')
    parser.add_argument('--out', type=Path, help='write the JSON report here (refuses to overwrite)')
    parser.add_argument('--overwrite', action='store_true', help='disabled; choose a new output file')
    parser.add_argument('--include-local-paths', action='store_true',
                        help='write absolute paths to a private local_detail section of --out only '
                             '(stdout stays redacted); keep that file private')
    args = parser.parse_args(argv)
    try:
        cli = [('--manifest', args.manifest), ('--installation', args.installation),
               ('--executable', args.executable), ('--working-dir', args.working_dir),
               ('--isolated-profile', args.isolated_profile), ('--requirements', args.requirements),
               ('--toolchain-report', args.toolchain_report), ('--out', args.out)]
        cli += [('--dll-provider', p) for p in args.dll_provider]
        cli += [('--protected-path', p) for p in args.protected_path]
        for label, value in cli:
            if value is not None:
                safe_input_path(value, label)
        if args.include_local_paths and not args.out:
            raise InputError('--include-local-paths needs --out; local paths are never printed')
        inputs = dict(arguments=[])
        manifest_digest = None
        if args.manifest:
            loaded, manifest_digest = load_manifest(args.manifest)
            inputs.update(loaded)
        overrides = dict(installation=args.installation, executable=args.executable,
                         working_directory=args.working_dir, isolated_profile=args.isolated_profile)
        inputs.update({k: v for k, v in overrides.items() if v is not None})
        if args.dll_provider:
            inputs['dll_providers'] = args.dll_provider
        if args.protected_path:
            inputs['protected_paths'] = list(inputs.get('protected_paths') or []) + args.protected_path
        if args.out:
            _check_out(args.out, inputs, [('manifest', args.manifest), ('requirements file', args.requirements),
                                          ('toolchain report', args.toolchain_report),
                                          ('observed inventory', INVENTORY_PATH)], args.overwrite)
        toolchain = load_toolchain_report(args.toolchain_report) if args.toolchain_report else None
        report = check(inputs, args.requirements, toolchain)
        report['manifest'] = dict(supplied=bool(args.manifest), sha256=manifest_digest)
        public = finalize(json.loads(json.dumps(report)), inputs, False)
        saved = finalize(report, inputs, True) if args.include_local_paths else public
        if args.out:
            try:
                with open(args.out, 'x', encoding='utf-8', newline='\n') as stream:
                    stream.write(json.dumps(saved, indent=2) + '\n')
            except OSError as error:
                raise InputError('--out could not be written (%s)' % _err_name(error))
    except InputError as problem:
        print('error: %s' % _ascii(str(problem)), file=sys.stderr)
        return EXIT_INPUT_ERROR
    except Exception as error:  # never surface an exception text, which may contain a path
        print('error: internal error (%s); no report produced' % type(error).__name__, file=sys.stderr)
        return EXIT_INPUT_ERROR
    stdout.write(json.dumps(public, indent=2) + '\n' if args.format == 'json' else _ascii(render_text(public)))
    return EXIT_CODES[public['overall']['verdict']]


if __name__ == '__main__':
    raise SystemExit(main())
