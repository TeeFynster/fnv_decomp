#pragma once

// The 0x24-byte BSA file header (the 'BSA\0' record at the start of every archive). In Archive it is the
// BSArchive base at +0x160; Archive's constructor (0x00af7eb0) reads 0x24 bytes into it after its
// constructor 0x00afd8b0 sets tag 'BSA', version 0x68, header size 0x24 and zeroes the rest.
class BSArchiveHeader
{
public:
    BSArchiveHeader();  // 0x00afd8b0

    // Inline helpers of Archive's constructor (0x00af7eb0, /Ob1).
    unsigned int GetDirectoryCount()
    {
        return m_uiDirectoryCount;
    }
    unsigned int GetDirectoryNamesLength()
    {
        return m_uiDirectoryNamesLength;
    }
    unsigned int GetFileNamesLength()
    {
        return m_uiFileNamesLength;
    }
    unsigned int GetVersion()
    {
        return m_uiVersion;
    }
    bool IsValid()
    {
        return m_uiTag == 0x415342;
    }
    bool IsVersionSupported()
    {
        return m_uiVersion <= 0x68;
    }
    bool HasArchiveFlag(unsigned int auiFlag)
    {
        return (m_uiArchiveFlags & auiFlag) != 0;
    }
    static void SetFlag(unsigned int& auiField, unsigned int auiMask, bool abValue)
    {
        auiField = abValue ? auiField | auiMask : auiField & ~auiMask;
    }
    // Archives older than version 0x68 do not have archive flag 0x100.
    void ClearVersionFlag()
    {
        SetFlag(m_uiArchiveFlags, 0x100, false);
    }

    unsigned int m_uiTag;                   // +0x00 0x00415342 ('BSA')
    unsigned int m_uiVersion;               // +0x04 (0x68 here; the loader accepts <= 0x68)
    unsigned int m_uiHeaderSize;            // +0x08 (0x24)
    // +0x0c archive flags: 1 directory names, 2 file names, 8/0x10/0x20 per-type cache requests,
    // 0x80 always cache, 0x100 (version 0x68 only)
    unsigned int m_uiArchiveFlags;
    unsigned int m_uiDirectoryCount;        // +0x10
    unsigned int m_uiFileCount;             // +0x14
    unsigned int m_uiDirectoryNamesLength;  // +0x18
    unsigned int m_uiFileNamesLength;       // +0x1c
    unsigned short m_usFlags;               // +0x20 archive type flags (1 << ARCHIVE_TYPE)
    unsigned short m_usReserved;            // +0x22
};
