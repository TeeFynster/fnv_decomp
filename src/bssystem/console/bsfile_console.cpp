// bssystem/console/bsfile_console.cpp: BSFile (6 functions)

#include "../../../include/BSFile.h"
#include "../../../include/BSStringT.h"
#include "../../../include/NiTPointerMap.h"
#include "bsfile_console_decls.h"
// Constructs a NiTPointerMap of unsigned int to TESFile* pairs, delegating to the base constructor with the given count.
// @fnv 0x004744a0
template <> NiTPointerMap<unsigned int, TESFile*>::NiTPointerMap(unsigned int count) : NiTMapBase<NiTPointerAllocator<unsigned int>, unsigned int, TESFile*>(count)
{}
// Seeks the file to a position computed from the offset and mode (set/current/end), updating position when it changes.
// @fnv 0x00b00590
void BSFile::Seek(int offset, int mode)
{
    int target;
    if (mode == DAT_010a2480)
    {
        target = offset;
        if (m_eMode == 0)
        {
            mode = DAT_010a2484;
            offset -= m_uiBufferSize;
        }
    }
    else if (mode == DAT_010a2484)
    {
        target = m_uiBufferSize + offset;
    }
    else if (mode == DAT_010a2488)
    {
        target = GetSize() - offset;
    }
    else
    {
        target = m_uiBufferSize;
    }
    if (target != m_uiBufferSize)
    {
        NiFile::Seek(offset, mode);
        m_uiBufferSize = target;
    }
}

// Retained until NiFile declares the write helper at 0x00aa1810.
struct FUN_00aff950_shell
{
    unsigned int FUN_00aa1810(void*, unsigned int);
    unsigned int BSFile_WriteF(void*, unsigned int);
};
// @fnv 0x00aff950
// src: XBOX_PDB 0x00aff950
unsigned int FUN_00aff950_shell::BSFile_WriteF(void* buffer, unsigned int size)
{
    unsigned int term = this->FUN_00aa1810(buffer, size);
    *(unsigned int*)((char*)this + 0x150) += term;
    return term;
}

struct S_00aff7c0_Pad
{
    int unk00;
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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
};

// @fnv 0x00aff7c0
unsigned int BSFile::Read(BSStringT<char>& out, unsigned int maxLen)
{
    if (!(bool)(m_pFile != 0 ? 1 : 0))
        Open(false, false);
    unsigned int idx3 = 0;
    unsigned int outLen7 = 0;
    unsigned int kTotal = 0;
    char ch_;
    char buf2[0x104];
    for (;;)
    {
        int want = 1;
        int got = m_pfnRead(this, &ch_, 1, reinterpret_cast<unsigned int*>(&want), 1);
        m_uiAbsoluteCurrentPos += got;
        int a2 = got;
        int b2 = a2;
        kTotal += b2;
        if (b2 != 1)
            ch_ = 0;
        if (kTotal > maxLen)
            ch_ = 0;
        buf2[idx3] = ch_;
        idx3++;
        if (idx3 == 0x103 || ch_ == 0)
        {
            buf2[idx3] = 0;
            if (outLen7)
                out += buf2;
            else
                out.Set(buf2, 0);
            outLen7 += idx3;
            if (!ch_)
                break;
            idx3 = 0;
        }
    }
    {
        S_00aff7c0_Pad pad;
    }
    return kTotal;
}

#include <string.h>
void __cdecl FUN_00ec65a6(char* dest, unsigned int size, const char* src);

// Initializes fields, copies pPath when its length is below 260, and calls helper functions depending on mode.
// @fnv 0x00b00260
BSFile::BSFile(const char* pPath, int mode, unsigned int bufferSize, bool abFlag)
{
    BSFile::SetEndianSwap(false);
    m_eMode = static_cast<NiFile::OpenMode>(mode);
    m_uiBufferAllocSize = bufferSize;
    m_uiBufferReadSize = 0;
    m_uiPos = 0;
    m_pBuffer = 0;
    m_pFile = 0;
    m_uiBufferSize = 0;
    m_uiBufferPosition = 0;
    iResult = 0;
    m_uiValueId = 0;
    m_bIsOpen = 0;
    m_pFileBuffer = 0;
    m_iBufferSize = 0xffffffff;
    m_uiFileSize = 0;
    m_uiFilePosition = 0;

    if (strlen(pPath) >= 0x104)
    {
        pFileName[0] = 0;
    }
    else
    {
        strcpy_s(pFileName, 0x104, pPath);
        if (mode == 1)
        {
            BSFile::Open(false, abFlag);
        }
    }
    if (mode == 0)
    {
        m_bGood = Write();
    }
}

#include <windows.h>
void* fnv_zlib_memset(void* dst, int c, int n);

// Retained until BSFile declares SYSTEMTIME GetLastWriteTime().
class B003C0File
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual const char* GetFileName();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    void* m_handle;

    SYSTEMTIME GetLastWriteTime();
};

// Returns the last write time of the file as local time, or zeroed SYSTEMTIME if m_handle is null.
// @fnv 0x00b003c0
SYSTEMTIME B003C0File::GetLastWriteTime()
{
    SYSTEMTIME localTime2;
    if (!(bool)(int)(m_handle != 0))
    {
        fnv_zlib_memset(&localTime2, 0, sizeof(localTime2));
        return localTime2;
    }
    WIN32_FIND_DATAA findData;
    FILETIME writeTime;
    SYSTEMTIME utcTime4;
    HANDLE find9 = FindFirstFileA(GetFileName(), &findData);
    if (find9 != INVALID_HANDLE_VALUE)
        writeTime = findData.ftLastWriteTime;
    FindClose(find9);
    FileTimeToSystemTime(&writeTime, &utcTime4);
    SystemTimeToTzSpecificLocalTime(0, &utcTime4, &localTime2);
    return localTime2;
}
