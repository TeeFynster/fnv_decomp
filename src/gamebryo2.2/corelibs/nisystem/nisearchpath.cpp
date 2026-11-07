
// src/gamebryo2.2/corelibs/nisystem/nisearchpath.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nisystem/nisearchpath.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiSearchPath.h"

// @fnv 0x00aa2500
// src: XBOX_PDB 0x00aa2500
void NiSearchPath::Reset_00aa2500()
{
    m_uiSearchPathValue = 0;
}

extern void _fnv_StandardizeFilePath(char*);
extern void _fnv_CopyFilePath(char*, int, const char*, int);

// Copies pcFilePath into the buffer at offset 8 and standardizes it, or clears that buffer when pcFilePath is null or empty.
// @fnv 0x00aa2540
void NiSearchPath::SetPath(const char* pcFilePath)
{
    if (pcFilePath && *pcFilePath)
    {
        _fnv_CopyFilePath(m_acFilePathBuffer, 0x104, pcFilePath, 0x103);
        _fnv_StandardizeFilePath(m_acFilePathBuffer);
    }
    else
    {
        m_acFilePathBuffer[0] = 0;
    }
}

int _strcpy_s(char* dst, unsigned int size, const char* src);
void _fnv_StandardizeFilePath(char* path);
extern char DAT_011f6120[];
struct FileNameComponents
{
    char m_acFolderPath[256];
    char m_acDriveLetter[3];
    char m_acBaseName[256];
    char m_acExtension[256];
    char m_acPlatformSubDir[256];
    FileNameComponents(const char* pcFullPath);
    void NiFilename_GetFullPath(char* pcFullPath, unsigned int uiStringLen);
    void SetDrive(const char* pc)
    {
        _strcpy_s(m_acDriveLetter, 3, pc);
    }
    void SetDir(const char* pc)
    {
        _strcpy_s(m_acFolderPath, 256, pc);
    }
    void SetPlatformSubDir(const char* pc)
    {
        _strcpy_s(m_acPlatformSubDir, 256, pc);
    }
    const char* GetDir() const
    {
        return m_acFolderPath;
    }
};
// Builds a full path from the stored path and search-path mode, writes it to pcPath, standardizes it, and advances the mode counter.
// @fnv 0x00aa2580
bool NiSearchPath::ResolveSearchPath(char* pcOutPath, unsigned int uiOutLen)
{
    FileNameComponents kFullPath(m_acFilePathBuffer);
    switch (m_uiSearchPathValue)
    {
    case 0:
        break;
    case 1:
        kFullPath.SetDrive("");
        kFullPath.SetDir("");
        break;
    case 2: {
        kFullPath.SetDrive("");
        kFullPath.SetDir(m_acResolvedPath);
        FileNameComponents inputURL(m_acFilePathBuffer);
        kFullPath.SetPlatformSubDir(inputURL.GetDir());
    }
    break;
    case 3:
        kFullPath.SetDrive("");
        kFullPath.SetDir(m_acResolvedPath);
        kFullPath.SetPlatformSubDir("");
        break;
    case 4:
        if (DAT_011f6120[0] == 0)
            return false;
        kFullPath.SetDrive("");
        kFullPath.SetDir(DAT_011f6120);
        break;
    default:
        return false;
    }
    kFullPath.NiFilename_GetFullPath(pcOutPath, uiOutLen);
    _fnv_StandardizeFilePath(pcOutPath);
    m_uiSearchPathValue++;
    return true;
}

extern MemoryManager g_memoryManager;
inline void NiSearchPath::operator delete(void* p)
{
    g_memoryManager.Deallocate(p);
}
// @fnv 0x00aa2510
NiSearchPath::~NiSearchPath()
{}
