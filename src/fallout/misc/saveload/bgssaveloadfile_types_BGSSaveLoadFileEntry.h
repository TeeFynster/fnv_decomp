// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSSAVELOADFILEENTRY_H
#define FNV_BGSSAVELOADFILEENTRY_H

#include "layout_support.h"
#include "../../../../include/BGSSaveLoadFileEntry.h"
#include "_FILETIME.h"
class BGSSaveLoadFileEntry;
#pragma pack(push, 4)
#pragma pack(pop)
// (the Xbox PDB size is 124; on PC the screenshot pointer is at +0x40: 0x007d5280)
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, pFileName) == 0);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, m_bHeaderParsed) == 4);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, m_bSaveEntryValid) == 5);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, PathMetadataRecord) == 8);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, m_pStringBeforeSaveFileName) == 12);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, m_pSaveFileName) == 16);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, pLocation) == 20);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, m_pStringAfterLocation) == 24);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, StringIntegerRecord) == 28);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, m_uiHeaderRecordValue) == 32);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, m_uiFileSize) == 36);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, SaveFileMetadata) == 40);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, FileTime) == 44);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, m_iScreenshotOffset) == 52);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadFileEntry, iVersion) == 56);
#endif
