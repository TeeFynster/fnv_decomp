#pragma once

#include "BSArchive.h"
#include "BSFile.h"
#include "NiRefObject.h"
#include <windows.h>

class ArchiveFile;
class ArchiveFileEntry;
class BSFileEntry;

// A CRITICAL_SECTION owned by its object: constructor 0x0044fae0 (InitializeCriticalSection; inline in /Ob1
// code), destructor 0x0044fb00 (DeleteCriticalSection), 0x18 bytes. Archive's constructor (0x00af7eb0) has an
// EH state for it at +0x19c (unwind funclet 0x00f2351f calls 0x0044fb00). The same pair is used by other game
// classes (ImpactSound::ImpactTimer, ObstacleManagerBase among them); the real name is not known.
class FUN_0044fae0_CriticalSection
{
public:
    FUN_0044fae0_CriticalSection()
    {
        InitializeCriticalSection(&m_kCriticalSection);
    }
    ~FUN_0044fae0_CriticalSection();

    CRITICAL_SECTION m_kCriticalSection;
};

// RTTI (vftables 0x010a45ac, 0x010a459c at +0x158): BSFile at 0, NiRefObject at 0x158, BSArchive at 0x160
// (MSVC places the bases with vftables first). Allocation size 0x1d0.
class Archive : public BSArchive, public BSFile, public NiRefObject
{
public:
    // 0x00af7eb0: opens the archive and reads its header, folder and file records and (if cached) names.
    Archive(const char* apPath, int aiMode, bool abHeaderOnly, bool abPrepare);
    virtual ~Archive();

    // NiRefObject's NiMemObject allocators, not BSFile's: the deleting destructor 0x00afc680 frees through 0x00aa1460
    // with 0x1d0.
    using NiRefObject::operator new;
    using NiRefObject::operator delete;

    unsigned int GetFlags() { return m_usFlags; }
    ArchiveEntry* GetEntry(int index);
    bool HasNameTable() { return m_ucStatus & 0x20; }  // implicit bool conversion, as 0x00af7400 tests it
    void Lock();
    void Unlock();
    unsigned short HasType(unsigned int i)
    {
        return static_cast<unsigned short>(m_usFlags & (1 << i));
    }
    unsigned long BufferSize();
    bool SetBufferSize(unsigned int);
    void* OpenFile(unsigned int auiFolderIndex, unsigned int auiFileIndex,
                   unsigned int auiBufferSize, const char* apFileName);
    unsigned short HasArchiveTypeFlags(unsigned int auiFlags)
    {
        return static_cast<unsigned short>(m_usFlags & auiFlags);
    }
    unsigned short HasArchiveType(int aeArchiveTypeIndex)
    {
        return static_cast<unsigned short>(m_usFlags & (1 << aeArchiveTypeIndex));
    }
    bool IsFlag();
    // 0x00af9bf0: finds the folder and file indices of a directory/file hash pair.
    bool FindFile_00af9bf0(int arDirHash, int arFileHash, int* apFolderIndex, int apFileIndex, int apFileName);
    // 0x00afa6e0: returns the file record of a directory/file hash pair, or 0.
    int GetFileEntryForFile(int arDirectoryHash, int arFileNameHash, int apFileName);
    ArchiveFile* CreateArchiveFile(BSFileEntry*, unsigned int, unsigned int);
    const char* Archive_GetFileNameForFileEntry(ArchiveFileEntry* pkEntry);
    int Archive_GetFileString(int, unsigned int);
    void FUN_00865e50(void* apData, unsigned int aSize, int aFlags);
    // 0x00af8f10: (re)reads the name table; called on every archive of the global archive list (0x00af59f0).
    void LoadNames();
    // 0x00afd020: whether the names are to be cached (global switches, archive flags 0x80/8/0x10/0x20,
    // the per-type cache modes).
    bool GetLoadStrings();
    // 0x00afb170: whether a per-type cache request (archive flag) is met under cache mode aiMode.
    bool Archive_CheckRetain(bool abRequested, int aiMode);
    // 0x00afad00
    void ClearMatchedEntries();

    // Inline helpers of the constructor (0x00af7eb0, /Ob1).
    bool IsFileGood()
    {
        return m_bGood;
    }
    template <int Mask> void SetStatus(bool abValue)
    {
        if (abValue)
            m_ucStatus |= Mask;
        else
            m_ucStatus &= ~Mask;
    }
    bool HasStatus(int aiMask)
    {
        return (m_ucStatus & aiMask) ? true : false;
    }
    unsigned int GetTruePosition()
    {
        return m_iBufferSize != -1 ? m_iBufferSize : m_uiBufferSize;
    }

    struct TimeStamp
    {
        unsigned int uiLow, uiHigh;
    };

    // +0x160..+0x187: BSArchive (BSArchiveHeader + folder records).
    TimeStamp m_kTimeStamp;               // +0x188 the archive file's modification time (stat)
    unsigned int m_uiFileNamesOffset;     // +0x190 file position of the file name block
    unsigned int m_uiCacheIndex;          // +0x194 -1 from the constructor
    unsigned int m_uiCacheOffset;         // +0x198 -1 from the constructor
    FUN_0044fae0_CriticalSection m_kLock; // +0x19c
    // +0x1b4 status: 1 bad header, 8 header only, 0x10 directory names cached, 0x20 file names cached
    unsigned char m_ucStatus;
    unsigned char unk1B5;
    short unk1B6;
    char* m_pDirectoryNames;              // +0x1b8
    unsigned int* m_puiDirectoryNameOffsets;  // +0x1bc
    char* m_pFileNames;                   // +0x1c0
    unsigned int** m_ppuiFileNameOffsets; // +0x1c4 per folder
    unsigned int m_uiID;                  // +0x1c8 from a global counter
    int unk1CC;
};
