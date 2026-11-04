# Opt-in pinned checkout preparation

`prepare_ordinary_v2_checkout.py` prepares three explicitly reviewed byte-form
pairs in a disposable checkout. It validates both SHA-256 hashes, exact reversible
line-ending conversion, and identical Python ASTs including locations. It accepts
no other source content. The target forms are the existing pins:

| Identity | LF SHA-256 | CRLF SHA-256 | Target |
| --- | --- | --- | --- |
| `ordinary-v2` | `cb1fc1dfbb8f22ba7f2f545cf71b5899fa76f506e8db2b68c5a0aa54b6423a78` | `4bfdb5001380a3d7e5db7517033285d49ab211be68e2fcba15964f0ad5b03c53` | CRLF |
| `coff-archive-v1` | `76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64` | `98d97151b51368bb16cf60dabb38ee86c10934e226dda7453ef1fab4e07be14f` | LF |
| `omission-v1` | `1a0e8aa2271218f59c11497c1363b41f099bb259791e19adac7d80718e7a5d7b` | `73f056858ab4c6fd1a3ee4c977d3df76406ad56c7ed7cef8482ddb540a9158e3` | LF |

Create an isolated tree omitting the relevant destination files and then call:

```
python tools/rebuild/prepare_ordinary_v2_checkout.py IDENTITY SOURCE OUTPUT_ROOT RELATIVE_DESTINATION
```

The output root and parent directories must already exist and must contain no
symlink or reparse traversal; the destination must be absent. Windows alternate
streams, reserved device names, and ambiguous path components are rejected. The caller must
control the output tree and keep it stable throughout execution: path checks are
not a defense against concurrent filesystem races. Each call creates one file.
The existing producers, consumers, evidence and exact-hash gates are unchanged;
these distinct identities do not create new attestations. Default Git checkout
and CI are not changed. Other dependency closure still needs independent checks.

The tests invoke no game inputs or native tools: `python -m unittest discover -s
tests/rebuild -p test_prepare_ordinary_v2_checkout.py`.
