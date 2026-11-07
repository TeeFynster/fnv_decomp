
// src/bssystem/bsfile_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/bssystem/bsfile.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "bsfile_decls.h"

extern "C" __declspec(thread) int tls_memContext;

inline int GetMemContext()
{
    return tls_memContext;
}
inline void SetMemContext(int aiMemoryContext)
{
    tls_memContext = aiMemoryContext;
}

struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = GetMemContext();
        SetMemContext(aiMemoryContext);
    }
    ~MemContextGuard()
    {
        SetMemContext(m_iSaved);
    }
};

struct GlobalAllocator
{
    void* __thiscall Game_DoHeapAlloc(unsigned int uiSize);
};
extern GlobalAllocator DAT_011f6238;
inline void* FileAlloc(unsigned int uiSize)
{
    return DAT_011f6238.Game_DoHeapAlloc(uiSize);
}

class FileObject
{
  public:
    virtual ~FileObject();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual unsigned int GetFileSize();

    unsigned int unk04;
    void* m_pReadHandler;
    void* m_pWriteHandler;
    unsigned int m_uiBufferAllocSize;
    unsigned int m_uiBufferReadSize;
    unsigned int m_uiPos;
    unsigned int unk1c;
    char* m_pBuffer;
    void* m_pFile;
    unsigned int m_eMode;
    bool m_bGood;

    bool IsOpen() const
    {
        return m_pFile != 0;
    }
    unsigned int FUN_00aa1570(void* pBuffer, unsigned int uiBytes);
    void BSFile_CheckIsGood();
};

// @fnv 0x00aff490
// src: XBOX_PDB 0x00aff490
void FileObject::BSFile_CheckIsGood()
{
    if (IsOpen())
    {
        m_bGood = true;
        if (m_uiBufferAllocSize > 0 && m_pBuffer == 0)
        {
            MemContextGuard kGuard(0x17);
            bool bReadAllX = (m_uiBufferAllocSize == 0xffffffff);
            unsigned int uiRead;
            if (bReadAllX)
                m_uiBufferAllocSize = GetFileSize();
            void* pMem2 = FileAlloc(m_uiBufferAllocSize);
            m_pBuffer = (char*)pMem2;
            if (bReadAllX)
            {
                m_uiBufferReadSize = m_uiBufferAllocSize;
                m_uiPos = 0;
                uiRead = FUN_00aa1570(m_pBuffer, m_uiBufferAllocSize);
                if (uiRead != m_uiBufferAllocSize)
                    m_bGood = false;
            }
        }
    }
    else
    {
        m_bGood = false;
    }
}

#include <string.h>
struct StreamString
{
    const char* data;
    unsigned short length;
    __forceinline const char* Buffer() const
    {
        const char* buffer = data;
        return buffer;
    }
    __forceinline unsigned int Length() const
    {
        return length == 0xffff ? strlen(Buffer()) : length;
    }
};
struct BinaryWriter;
typedef unsigned int(__cdecl* WriteCallback)(BinaryWriter*, const char*, unsigned int, unsigned int*, unsigned int);
struct BinaryWriter
{
    int unk00;
    unsigned int absolutePosition;
    int unk08;
    WriteCallback unk0c;

    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    unsigned int filePosition;

    __forceinline unsigned int BinaryWrite(const char* data, unsigned int bytes, unsigned int* components,
                                           unsigned int count)
    {
        unsigned int written = unk0c(this, data, bytes, components, count);
        absolutePosition += written;
        return written;
    }
    __forceinline unsigned int Write(const char* data, unsigned int bytes)
    {
        unsigned int componentSize = 1;
        unsigned int result = BinaryWrite(data, bytes, &componentSize, 1);
        return result;
    }
    __forceinline unsigned int WriteString(const StreamString& string, bool abWriteNullTerminator)
    {
        return Write(string.Buffer(), string.Length() + (abWriteNullTerminator != 0));
    }
    unsigned int BSFile_Write_00affbb0(const StreamString* string, bool abWriteNullTerminator);
};
// @fnv 0x00affbb0
// src: XBOX_PDB 0x00affbb0
unsigned int BinaryWriter::BSFile_Write_00affbb0(const StreamString* string, bool abWriteNullTerminator)
{
    unsigned int result = WriteString(*string, abWriteNullTerminator);
    filePosition += result;
    return result;
}
