"""Prepare an exact reviewed source byte form in a disposable checkout.

This opt-in utility does not alter consumers or attestations. It assumes a
stable output tree controlled by the caller during execution.
"""
import argparse
import ast
import hashlib
import os
import re
from pathlib import Path
import stat

# key: (reviewed LF, reviewed CRLF, required output form)
PAIRS = {
    'ordinary-v2': ('cb1fc1dfbb8f22ba7f2f545cf71b5899fa76f506e8db2b68c5a0aa54b6423a78',
                    '4bfdb5001380a3d7e5db7517033285d49ab211be68e2fcba15964f0ad5b03c53', 'crlf'),
    'omission-v1': ('1a0e8aa2271218f59c11497c1363b41f099bb259791e19adac7d80718e7a5d7b',
                    '73f056858ab4c6fd1a3ee4c977d3df76406ad56c7ed7cef8482ddb540a9158e3', 'lf'),
    'coff-archive-v1': ('76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64',
                        '98d97151b51368bb16cf60dabb38ee86c10934e226dda7453ef1fab4e07be14f', 'lf'),
}


def _sha(data):
    return hashlib.sha256(data).hexdigest()


def reviewed_bytes(data, identity):
    """Accept only both explicitly identified byte forms of a reviewed source."""
    lf_hash, crlf_hash, output_form = PAIRS[identity]
    digest = _sha(data)
    if digest == lf_hash:
        lf = data
        if b'\r' in lf or lf.startswith(b'\xef\xbb\xbf'):
            raise ValueError('invalid LF source form')
        crlf = lf.replace(b'\n', b'\r\n')
    elif digest == crlf_hash:
        crlf = data
        lf = crlf.replace(b'\r\n', b'\n')
        if b'\r' in lf or lf.startswith(b'\xef\xbb\xbf'):
            raise ValueError('invalid CRLF source form')
    else:
        raise ValueError('unreviewed source identity')
    if (_sha(lf) != lf_hash or _sha(crlf) != crlf_hash or
            crlf.replace(b'\r\n', b'\n') != lf or lf.replace(b'\n', b'\r\n') != crlf):
        raise ValueError('source forms do not match the reviewed pair')
    if ast.dump(ast.parse(lf), include_attributes=True) != ast.dump(ast.parse(crlf), include_attributes=True):
        raise ValueError('source forms have different syntax trees')
    return {'lf': lf, 'crlf': crlf}[output_form]


def _plain_directory(path):
    info = path.lstat()
    if (stat.S_ISLNK(info.st_mode) or
            getattr(info, 'st_file_attributes', 0) & getattr(stat, 'FILE_ATTRIBUTE_REPARSE_POINT', 0x400) or
            not stat.S_ISDIR(info.st_mode)):
        raise ValueError('output path traverses a link, reparse point, or non-directory')


def materialize(source, output_root, relative_destination, identity):
    """Create a new file under a trusted, stable, existing disposable root."""
    data = reviewed_bytes(Path(source).read_bytes(), identity)
    root = Path(os.path.abspath(output_root))
    relative = Path(relative_destination)
    if relative.is_absolute() or relative.drive or not relative.parts or any(p in ('.', '..') for p in relative.parts):
        raise ValueError('destination must be a relative path inside output root')
    # Reject Windows ADS, device names and names silently rewritten by Win32,
    # on every platform so the policy has the same meaning in a checkout.
    for part in relative.parts:
        stem = part.split('.', 1)[0].upper()
        if (':' in part or part.endswith((' ', '.')) or
                re.fullmatch(r'(CON|PRN|AUX|NUL|CONIN\$|CONOUT\$|COM[1-9¹²³]|LPT[1-9¹²³])', stem) or
                any(ord(ch) < 32 or ch in '<>\"|?*' for ch in part)):
            raise ValueError('ambiguous or reserved destination component')
    # Reject links/reparse points in root ancestors as well as inside the root.
    for parent in reversed((root, *root.parents)):
        _plain_directory(parent)
    current = root
    for part in relative.parts[:-1]:
        current = current / part
        _plain_directory(current)
    destination = current / relative.parts[-1]
    # lexists includes dangling links; exclusive creation also rejects existing files.
    if os.path.lexists(destination):
        raise FileExistsError(str(destination))
    with destination.open('xb') as output:
        output.write(data)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('identity', choices=PAIRS)
    parser.add_argument('source', type=Path)
    parser.add_argument('output_root', type=Path, help='trusted existing disposable checkout root')
    parser.add_argument('relative_destination', type=Path, help='new path relative to output root')
    args = parser.parse_args()
    materialize(args.source, args.output_root, args.relative_destination, args.identity)


if __name__ == '__main__':
    main()
