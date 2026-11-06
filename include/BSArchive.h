#pragma once

#include "BSArchiveHeader.h"

// A BSA folder or file record (0x10). Folder records: name hash, file count, and (once loaded by Archive's
// constructor 0x00af7eb0) the folder's file records; file records: name hash, size, data offset.
class ArchiveEntry
{
public:
    ArchiveEntry()
    {
        m_uiCount = 0;
        m_pFiles = 0;
    }
    void SetFiles(ArchiveEntry* apFiles)
    {
        m_pFiles = apFiles;
    }
    // 0x00af7400 passes +0x08 to FUN_00aa5230 as a name id.
    int GetNameID()
    {
        return m_uiCount;
    }

    unsigned int m_uiHashLow;   // +0x00
    unsigned int m_uiHashHigh;  // +0x04
    unsigned int m_uiCount;     // +0x08 folder: file count; file: size
    ArchiveEntry* m_pFiles;     // +0x0c folder: its file records; file: data offset
};

// RTTI: BSArchive has the single base BSArchiveHeader. Archive's constructor (0x00af7eb0) builds it at +0x160:
// the BSArchiveHeader constructor 0x00afd8b0, then the folder record array at +0x24 set to 0.
class BSArchive : public BSArchiveHeader
{
public:
    BSArchive()
    {
        pEntries = 0;
    }
    void SetFiles(unsigned int auiIndex, ArchiveEntry* apFiles)
    {
        pEntries[auiIndex].SetFiles(apFiles);
    }
    unsigned int GetFileCount(unsigned int auiIndex)
    {
        return pEntries[auiIndex].m_uiCount;
    }

    ArchiveEntry* pEntries;  // +0x24 folder records (0x10 each)
};
