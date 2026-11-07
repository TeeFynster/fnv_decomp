// fallout/misc/saveload/bgssaveloadfile.cpp: BGSSaveLoadFileEntry, SaveLoadFile, BGSSaveLoadManager (23 functions)

// The generated layout support has an enum-only NiFile declaration.
// Keep it separate from the shared BSFile base class.
#include <windows.h> // before layout_support.h: the shared BGSSaveLoadFileEntry.h needs the SDK's FILETIME
#include "layout_support.h"

#include "../../../../include/NiTexture.h"
#include "bgssaveloadfile_types_BGSSaveLoadFile.h"
#include "bgssaveloadfile_types_BGSSaveLoadFileEntry.h"
#include "../../../../include/BGSSaveLoadManager.h"
#include "bgssaveloadfile_types_BGSSaveLoadHeader.h"
#include "MemoryManager.h"
#include "../../../../include/BSFile.h"

extern BGSSaveLoadManager* DAT_011de134;

// These two operations are not declared by the shared manager yet.
struct SaveLoadManagerFileOperations : public BGSSaveLoadManager
{
    void DeleteWeaponFile(unsigned int, int);
    void RemoveAndDelete(void*);
};
extern int DAT_010a2480;

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
void __cdecl ReadSaveFileHeader(void*, void*);
NiTexture* __cdecl LoadTextureFromFile(SaveLoadHeader*, unsigned int, unsigned int, unsigned int);
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
template <class T> unsigned int __cdecl BSStringLength(const T*);

// @fnv 0x00846b10
bool BGSSaveLoadFileEntry::IsAutoSave()
{
    return DAT_011de134->IsAutoSaveFileName(pFileName);
}

// @fnv 0x00846b30
bool BGSSaveLoadFileEntry::IsSaveEntryValid()
{
    if (m_bSaveEntryValid)
        return true;
    ReadTypedData();
    return m_bSaveEntryValid;
}

// Forwards a read of size bytes into buffer to the object's pFile stream and returns the result.
// @fnv 0x00846300
unsigned int SaveLoadFile::Read(void* buffer, unsigned int size)
{
    return pFile->Read(buffer, size);
}

// @fnv 0x00846400
unsigned int SaveLoadFile::GetFilePosition()
{
    if (DAT_011de134->InterfaceManager_GetMenuMode())
        return m_uiFilePosition;
    return pFile->GetFilePosition();
}

// @fnv 0x00846440
void SaveLoadFile::SetFilePosition(int position)
{
    if (DAT_011de134->InterfaceManager_GetMenuMode())
        m_uiFilePosition = position;
    else
        pFile->Seek(position, DAT_010a2480);
}

// @fnv 0x00846820
NiTexture* BGSSaveLoadFileEntry::ReadScreenshotFromFile()
{
    NiTexture* screenshot = 0;
    void* header = DAT_011de134->ReadHeaderFromFile(pFileName, 0, 0, m_iScreenshotOffset);
    if (!header)
        return 0;
    if (!m_bHeaderParsed)
    {
        ReadSaveFileHeader(header, this);
        if (!m_uiHeaderRecordValue && !m_uiFileSize)
            m_bSaveEntryValid = true;
        if (!pLocation)
            m_bSaveEntryValid = true;
        m_bHeaderParsed = true;
    }
    if (m_uiHeaderRecordValue && m_uiFileSize)
        screenshot =
            LoadTextureFromFile((SaveLoadHeader*)header, SaveFileMetadata, m_uiHeaderRecordValue, m_uiFileSize);
    DAT_011de134->CloseSaveFile((SaveLoadHeader*)header, 0);
    return screenshot;
}

// @fnv 0x008461e0
SaveLoadFile::SaveLoadFile(const char* fileName, bool flag, unsigned int size)
{
    pFile = 0;
    m_uiBufferSize = 0;
    m_uiFilePosition = 0;
    m_cFileName[0] = 0;
    if (!DAT_011de134->InterfaceManager_GetMenuMode())
        pFile = new BSFile(fileName, flag ? 1 : 0, size, false);
}

// @fnv 0x00846900
void BGSSaveLoadFileEntry::ReadTypedData()
{
    if (m_bHeaderParsed || m_bSaveEntryValid)
        return;
    void* header = DAT_011de134->ReadHeaderFromFile(pFileName, 0, 1, m_iScreenshotOffset);
    if (!header)
    {
        m_bSaveEntryValid = true;
        return;
    }
    ReadSaveFileHeader(header, this);
    if (!m_uiHeaderRecordValue && !m_uiFileSize)
        m_bSaveEntryValid = true;
    if (!pLocation)
        m_bSaveEntryValid = true;
    if (DAT_011de134->IsSaveFileNameCustom(pFileName))
    {
        char* location = pLocation;
        operator delete(location);
        unsigned int length = BSStringLength(pFileName) + 1;
        char* pAllocatedPath = (char*)operator new(length);
        pLocation = pAllocatedPath;
        TaskQueueInterface::CopyStringToBuffer(pLocation, length, pFileName);
    }
    DAT_011de134->CloseSaveFile((SaveLoadHeader*)header, 0);
    m_bHeaderParsed = true;
}

// Deletes the BSFile object stored at offset 0x104 of pThis.
// @fnv 0x008462c0
// src: GUESS 0x008462c0 (confidence: low)
void __fastcall Object_ProcessState_008462c0(char* pThis)
{
    delete *reinterpret_cast<BSFile**>(pThis + 0x104);
}

struct UnknownOwner008463c0
{
    char pad[0x104];
    BSFile* unk104;
};

// @fnv 0x008463c0
// src: COMMUNITY 0x008463c0
bool __fastcall BGSSaveLoadFile_Open(UnknownOwner008463c0* _this)
{
    if (DAT_011de134->InterfaceManager_GetMenuMode())
        return true;
    return _this->unk104->Open(false, false);
}

extern int DAT_010a2484;

struct FUN_00846490_t
{
    char pad_000[0x104];
    BSFile* file;
    int unk_108;
    int pos_10c;
    void AdvancePosition(int offset);
};

// If DAT_011de134->FUN_00424940() is true, adds offset to pos_10c; otherwise seeks file by offset using DAT_010a2484.
// @fnv 0x00846490
void FUN_00846490_t::AdvancePosition(int offset)
{
    if (DAT_011de134->InterfaceManager_GetMenuMode())
    {
        pos_10c += offset;
    }
    else
    {
        file->Seek(offset, DAT_010a2484);
    }
}

struct FUN_008464f0_arg
{
    const char* str;
};

// @fnv 0x008464f0
// src: COMMUNITY 0x008464f0
void __fastcall BGSSaveLoadFile_SetSaveFileName(char* pThis, FUN_008464f0_arg aStringArg)
{
    TaskQueueInterface::CopyStringToBuffer(pThis, 0x104, aStringArg.str);
}

// Allocates and constructs a new object from a name string, a bool flag and an unsigned int value, returning the new instance.
// @fnv 0x00846520
// src: COMMUNITY 0x00846520
SaveLoadFile* __cdecl BGSSaveLoadFile_Create(const char* apName, bool abFlag, unsigned int auiValue)
{
    return new SaveLoadFile(apName, abFlag, auiValue);
}

// Deletes the objects stored at indices 0, 6, 5, 3 and 4 of the array pointed to by pThis.
// @fnv 0x00846690
// src: GUESS 0x00846690 (confidence: low)
void __fastcall Bgssaveloadfile_ReleaseStorage_00846690(void** pThis)
{
    delete pThis[0];
    delete pThis[6];
    delete pThis[5];
    delete pThis[3];
    delete pThis[4];
}

struct FUN_008467b0_shell : public BGSSaveLoadFileEntry
{
    bool LoadSaveEntry();
};

// @fnv 0x008467b0
bool FUN_008467b0_shell::LoadSaveEntry()
{
    return DAT_011de134->LoadGame(*(const char**)this, *(int*)((char*)this + 0x34), false, false);
}

namespace fnv_00846a20 {
struct FileTimeValue
{
    unsigned int dwLowDateTime;
    unsigned int dwHighDateTime;
};

struct _WIN32_FIND_DATAA_
{
    unsigned int dwFileAttributes;
    FileTimeValue ftCreationTime;
    FileTimeValue ftLastAccessTime;
    FileTimeValue ftLastWriteTime;
    unsigned int nFileSizeHigh;
    unsigned int nFileSizeLow;
    unsigned int dwReserved0;
    unsigned int dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};

__declspec(dllimport) void* __stdcall FindFirstFileA(const char*, _WIN32_FIND_DATAA_*);
__declspec(dllimport) int __stdcall FindClose(void*);

// @fnv 0x00846a20
void __fastcall UpdateFileWriteTime(char* pThis)
{
    if (*(unsigned int*)(pThis + 0x30) == 0 && *(unsigned int*)(pThis + 0x2c) == 0)
    {
        char path[260];
        _WIN32_FIND_DATAA_ findData;
        DAT_011de134->GetFullPath(*(char**)pThis, path, false);
        void* hFind = FindFirstFileA(path, &findData);
        if (hFind != (void*)-1)
        {
            *(FileTimeValue*)(pThis + 0x2c) = findData.ftLastWriteTime;
        }
        FindClose(hFind);
    }
}
}  // namespace fnv_00846a20

namespace fnv_00846ad0 {
// @fnv 0x00846ad0
// src: XBOX_PDB 0x00846ad0
bool __fastcall BGSSaveLoadFileEntry_IsQuicksave(const char** pThis)
{
    return DAT_011de134->IsQuickSaveFileName(*pThis);
}
}  // namespace fnv_00846ad0

namespace fnv_00846af0 {
// @fnv 0x00846af0
bool __fastcall IsLegacyAutosaveFileName(const char** apFileName)
{
    return DAT_011de134->IsSaveFileNameLegacyAutosave(*apFileName);
}
}  // namespace fnv_00846af0

struct MemoryManagerStatic
{
    static void* __cdecl Allocate(unsigned int);
};
void* __cdecl memset(void*, int, unsigned int);
int __cdecl strcpy_s(char*, unsigned int, const char*);
unsigned int __cdecl _strlen(const char*);
struct FUN_008465b0_stub
{
    char* name;
    char f4;
    char f5;
    int f8, fc, f10, f14, f18, f1c, f20, f24, f28;
    char blk[8];
    int f34;
    FUN_008465b0_stub(const char* src, int p);
};
// Zeroes the fields, stores p in f34, allocates a buffer for src, copies src into name, and clears blk.
// @fnv 0x008465b0
FUN_008465b0_stub::FUN_008465b0_stub(const char* pcName, int p)
{
    f4 = 0;
    f5 = 0;
    f8 = 0;
    fc = 0;
    f10 = 0;
    f14 = 0;
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    f34 = p;
    memset(blk, 0, 8);
    unsigned int len = _strlen(pcName);
    char* buf = (char*)MemoryManagerStatic::Allocate(len + 1);
    name = buf;
    strcpy_s(name, len + 1, pcName);
}

struct FUN_00846330_shell
{
    unsigned int WriteToFile(const void* apBuffer, unsigned int aiBytes);
};
// @fnv 0x00846330
unsigned int FUN_00846330_shell::WriteToFile(const void* apBuffer, unsigned int aiBytes)
{
    if (DAT_011de134->InterfaceManager_GetMenuMode())
    {
        unsigned int ifileSizePositionDiff =
            *(unsigned int*)((char*)this + 0x108) - *(unsigned int*)((char*)this + 0x10c);
        if (aiBytes > ifileSizePositionDiff)
            *(unsigned int*)((char*)this + 0x108) += aiBytes - ifileSizePositionDiff;
        *(unsigned int*)((char*)this + 0x10c) += aiBytes;
        return aiBytes;
    }
    return (*reinterpret_cast<BSFile**>((char*)this + 0x104))->NiBinaryStream_Write((const char*)apBuffer, aiBytes);
}

struct FUN_00846710_cls : public BGSSaveLoadFileEntry
{
    void DispatchEvent();
    bool BGSSaveLoadFileEntry_DeleteSave();
};

// @fnv 0x00846710
// src: COMMUNITY 0x00846710
bool FUN_00846710_cls::BGSSaveLoadFileEntry_DeleteSave()
{
    if (DAT_011de134->IsSaveFileNameDefault(pFileName) ||
        DAT_011de134->IsSaveFileNameLegacyAutosave(pFileName))
    {
        if (DAT_011de134->SaveGame_008503b0(0, m_iScreenshotOffset, 0))
        {
            DispatchEvent();
            return true;
        }
    }
    else
    {
        if (DAT_011de134->SaveGame_008503b0(pFileName, m_iScreenshotOffset, 0))
        {
            static_cast<SaveLoadManagerFileOperations*>(DAT_011de134)->RemoveAndDelete(this);
            return true;
        }
    }
    return false;
}

class C8467E0Event
{
  public:
    unsigned int m_uiType;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int m_iData;

    void DispatchEvent();
};

// @fnv 0x008467e0
void C8467E0Event::DispatchEvent()
{
    static_cast<SaveLoadManagerFileOperations*>(DAT_011de134)->DeleteWeaponFile(m_uiType, m_iData);
    static_cast<SaveLoadManagerFileOperations*>(DAT_011de134)->RemoveAndDelete(this);
}

struct FUN_00850330_class
{
    char* FUN_00850330(unsigned int);
};
struct GlobalObject_0045cfe0
{
    int* Int();
};
extern GlobalObject_0045cfe0 DAT_011de2c8;
int __cdecl strcat_s(char*, unsigned int, const char*);
int __cdecl FUN_00ecbf05(const char*, int);
int __cdecl FUN_00ec862c(const char*, const char*);
__declspec(dllimport) int __stdcall DeleteFileA(const char*);
struct FUN_006815c0_Class
{
    void* FUN_006815c0();
};

// Builds successive .bak paths, deletes an existing destination, and calls FUN_00ec862c with source and destination paths.
// @fnv 0x00850100
// src: COMMUNITY 0x00850100
void BGSSaveLoadManager::CloseSaveFile(SaveLoadHeader* header, int abRotate)
{
    FUN_00850330_class* p2;
    FUN_00850330_class* p1;
    int inner4;
    char bufD_[260];
    char _bufE[260];
    int count2;
    char bufB[260];
    char bufC4[260];
    char bufA3[260];
    char* filename9;

    filename9 = (char*)((FUN_006815c0_Class*)header)->FUN_006815c0();
    strcpy_s(bufA3, 260, filename9);
    p1 = (FUN_00850330_class*)header;
    p2 = p1;
    (p2 ? p2->FUN_00850330(1) : (char*)0);
    if (*(unsigned char*)&abRotate)
    {
        GetFullPath(bufA3, bufB, *(bool*)&abRotate);
        strcpy_s(bufC4, 260, bufB);
        bufC4[BSStringLength(bufC4) - 4] = 0;
        for (count2 = *DAT_011de2c8.Int() - 1; count2 >= 0; count2--)
        {
            strcpy_s(bufD_, 260, bufC4);
            for (inner4 = 0; inner4 < count2; inner4++)
                strcat_s(bufD_, 260, ".bak");
            strcpy_s(_bufE, 260, bufD_);
            strcat_s(_bufE, 260, ".bak");
            if (FUN_00ecbf05(bufD_, 0) != -1)
            {
                if (FUN_00ecbf05(_bufE, 0) != -1)
                    DeleteFileA(_bufE);
                FUN_00ec862c(bufD_, _bufE);
            }
        }
        FUN_00ec862c(bufB, bufC4);
        strcpy_s(bufB, 260, bufC4);
    }
}
