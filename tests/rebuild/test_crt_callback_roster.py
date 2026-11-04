"""Source-authored metadata fixtures; no CRT library/image/native invocation."""
import struct
from types import SimpleNamespace
from pathlib import Path
import sys
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools' / 'rebuild'))
import crt_callback_roster as roster


def headers(name=b'.text', long_name=None):
    data = bytearray(64)
    struct.pack_into('<HHIIIHH', data, 0, 0x14c, 1, 0, 60, 0, 0, 0)
    data[20:28] = name.ljust(8, b'\0')
    if long_name:
        strings = struct.pack('<I', 5 + len(long_name)) + long_name + b'\0'
        data[60:] = strings
    else:
        struct.pack_into('<I', data, 60, 4)
    return bytes(data)


class RosterTests(unittest.TestCase):
    def test_header_only_short_and_long_section_names(self):
        self.assertEqual(roster.section_names(headers(b'.CRT$XIC')), ['.CRT$XIC'])
        self.assertEqual(roster.section_names(headers(b'/4', b'.CRT$XPXA')), ['.CRT$XPXA'])

    def test_invalid_header_or_string_table_preserves_failure(self):
        for data in [bytes(19), bytes(64), headers(b'/999'), headers(b'/bad')]:
            with self.assertRaises(ValueError): roster.section_names(data)

    def test_noncrt_members_are_not_parsed_as_code(self):
        payload = headers()
        archive = SimpleNamespace(names={8: 'fixture.obj'}, members={8: ('fixture', 0, len(payload))}, data=payload)
        with patch.object(roster, 'read_member', side_effect=AssertionError('must remain header-only')):
            result = roster.roster_for_archive(archive)
        self.assertEqual(result['summary']['no_CRT_sections_by_header'], 1)
        self.assertEqual(result['records'], [])

    def test_short_import_is_recorded_without_coff_decode(self):
        archive = SimpleNamespace(names={8: 'import'}, members={8: ('import', 0, 4)}, data=b'\0\0\xff\xff')
        result = roster.roster_for_archive(archive)
        self.assertEqual(result['summary']['short_import_members'], 1)

    def test_unsupported_header_keeps_explicit_incomplete_coverage(self):
        archive = SimpleNamespace(names={8: 'invalid'}, members={8: ('invalid', 0, 4)}, data=b'bad!')
        result = roster.roster_for_archive(archive)
        self.assertEqual(result['summary']['header_unsupported'], 1)
        self.assertFalse(result['member_issues'][0]['CRT_header_coverage_verified'])

    def test_unsupported_named_definition_is_not_silently_dropped(self):
        archive = SimpleNamespace(index={'fixture': [8]}, names={8: 'fixture.obj'})
        with patch.object(roster, 'read_member', side_effect=ValueError('unsupported')):
            result = roster.definition_candidates(archive, None, {}, dict(section=0, name='fixture'))
        self.assertEqual(len(result), 1)
        self.assertTrue(result[0]['errors'])
        self.assertFalse(result[0]['independent_original_identity_verified'])


if __name__ == '__main__': unittest.main()
