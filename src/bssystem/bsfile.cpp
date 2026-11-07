// bssystem/bsfile.cpp: BSFile, BSFileW (21 functions)

#include "bsfile_decls.h"

// @fnv 0x00affc60
bool BSFile::Write()
{
    return FUN_00ecbf05(pFileName, 0) != -1;
}

// @fnv 0x00afb780
unsigned int BSFile::GetFilePosition()
{
    return m_uiValueId;
}

// Reads +0x168, past the end of BSFile (0x158 bytes): the owner is another class.
struct FUN_00afc0a0_Owner
{
    unsigned char unk000[0x168];
    unsigned int unk168;
    unsigned int GetValue168();
};

// @fnv 0x00afc0a0
unsigned int FUN_00afc0a0_Owner::GetValue168()
{
    return unk168;
}

// Flushes and closes m_pFile when m_bGood and m_pFile are set, then deallocates m_pBuffer and clears m_pBuffer and m_pFile.
// @fnv 0x00affd10
void BSFile::Close()
{
    if (m_bGood && m_pFile)
    {
        Flush();
        _fclose_nolock(m_pFile);
    }
    void* buffer = m_pBuffer;
    g_memoryManager.Deallocate(buffer);
    m_pBuffer = 0;
    m_pFile = 0;
}

// @fnv 0x00aff240
BSFile::~BSFile()
{
    Close();
}

// Sets readHandler and writeHandler to one of two handler pairs depending on doSwap.
// @fnv 0x00aff990
void BSFile::SetEndianSwap(bool doSwap)
{
    if (doSwap)
    {
        m_pfnRead = reinterpret_cast<NIBINARYSTREAM_READFN>(0x00affa10);
        m_pfnWrite = reinterpret_cast<NIBINARYSTREAM_WRITEFN>(0x00affa60);
    }
    else
    {
        m_pfnRead = reinterpret_cast<NIBINARYSTREAM_READFN>(0x00aff9d0);
        m_pfnWrite = reinterpret_cast<NIBINARYSTREAM_WRITEFN>(0x00aff9f0);
    }
}

// Opens the file if m_pFile is null, reads bytes into buffer via NiFile::FileRead, adds the result to m_uiBufferSize and returns it.
// @fnv 0x00b00650
unsigned int BSFile::Read(void* buffer, unsigned int bytes)
{
    if (!static_cast<bool>(static_cast<int>(m_pFile != 0)))
        Open(false, false);
    unsigned int result = NiFile::FileRead(buffer, bytes);
    m_uiBufferSize += result;
    return result;
}

// Resets the buffer position and end, allocates m_pBuffer of bufferSize if needed, sets m_bGood, and returns m_bGood.
// @fnv 0x00afb5f0
bool BSFile::AttachFileStream(bool, bool)
{
    void* buffer;
    if (m_pBuffer)
        return true;
    m_uiPos = 0;
    m_uiBufferReadSize = 0;
    m_pBuffer = 0;
    if (m_uiBufferAllocSize > 0 && !m_pBuffer)
    {
        unsigned int uiSize = m_uiBufferAllocSize;
        buffer = g_memoryManager.Allocate(uiSize);
        m_pBuffer = (char*)buffer;
    }
    m_bGood = true;
    return m_bGood;
}

// BSFile vftable slot 10.
// @fnv 0x00b004e0
unsigned int BSFile::GetSize()
{
    m_uiValueId = 0;
    if (m_eMode == 1)
        Flush();
    Open(false, false);
    if (static_cast<bool>(static_cast<int>(m_pFile != 0)))
    {
        long position = ftell(m_pFile);
        fseek(m_pFile, 0, 2);
        m_uiValueId = ftell(m_pFile);
        fseek(m_pFile, position, 0);
    }
    return m_uiValueId;
}

// @fnv 0x00aff300
bool BSFile::Open(bool, bool textMode)
{
    if (static_cast<bool>(static_cast<int>(m_pFile != 0)))
        return true;
    m_uiPos = 0;
    m_uiBufferReadSize = 0;
    m_pBuffer = 0;
    const char* fallbackMode;
    const char* mode = 0;
    switch (m_eMode)
    {
    case 0:
        mode = textMode ? "rt" : "rb";
        break;
    case 1:
        mode = textMode ? "r+t" : "r+b";
        break;
    default:
        mode = textMode ? "a+t" : "a+b";
        break;
    }
    m_pFile = 0;
    fopen_s(&m_pFile, pFileName, mode);
    if (!m_pFile && m_eMode == 1)
    {
        m_pFile = 0;
        if (textMode)
            fallbackMode = "wt";
        else
            fallbackMode = "wb";
        fopen_s(&m_pFile, pFileName, fallbackMode);
        if (m_pFile)
            _fclose_nolock(m_pFile);
        m_pFile = 0;
        fopen_s(&m_pFile, pFileName, mode);
    }
    CheckIsGood();
    return m_bGood;
}

struct DummyVTable_00aff9d0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual int v44(int, int);
};

// @fnv 0x00aff9d0
int __cdecl ForwardVTableCall(DummyVTable_00aff9d0* apObject, int aiArg1, int aiArg2)
{
    return apObject->v44(aiArg1, aiArg2);
}

struct FUN_005d43c0_
{
    void* BSFile_GetDevice();
};

// @fnv 0x005d43c0
// src: XBOX_PDB 0x005d43c0
void* FUN_005d43c0_::BSFile_GetDevice()
{
    return (char*)this + 0x44;
}

struct FUN_00afbf60_shell
{
    char pad[0x158];
    int field_158;
    bool IsField158NonZero();
};

// @fnv 0x00afbf60
bool FUN_00afbf60_shell::IsField158NonZero()
{
    return field_158 != 0;
}

// @fnv 0x00afc410
// src: XBOX_PDB 0x00afc410
bool __fastcall CompressedArchiveFile_Exist(void* this_ptr)
{
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(this_ptr) + 0x158) != 0;
}

// @fnv 0x00aff9f0
void __cdecl CallVirtualMethodAtOffset48(void* apObject, int aiArg1, int aiArg2)
{
    (*(void(__thiscall**)(void*, int, int))(*(char**)apObject + 0x48))(apObject, aiArg1, aiArg2);
}

struct FUN_00affa10_V
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17(void*, unsigned int);
};

int __cdecl SwapBufferBySizes(void*, unsigned int, void*, void*);

// If p3 is positive, calls p1->v17(p2, p3), then if p4 is set calls SwapBufferBySizes(p2, p3, p4, p5), and returns the v17 result.
// @fnv 0x00affa10
// src: COMMUNITY 0x00affa10
int __cdecl BSFile_ReadAndSwap(FUN_00affa10_V* p1, void* apData, unsigned int auiSize, void* apExtra, void* apExtraArg)
{
    if (auiSize <= 0)
        return 0;
    int result = p1->v17(apData, auiSize);
    if (apExtra)
        SwapBufferBySizes(apData, auiSize, apExtra, apExtraArg);
    return result;
}

struct Base17
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual unsigned int Read(void*, unsigned int);
};
struct FUN_00affc90_t : public Base17
{
    unsigned int ReadUntilTerminator(char*, unsigned int, unsigned short);
};
// Reads bytes one at a time into buf until term or maxLen-1 is reached, null-terminates buf, and returns the total bytes read.
// @fnv 0x00affc90
unsigned int FUN_00affc90_t::ReadUntilTerminator(char* pBuffer, unsigned int maxLen, unsigned short usTerminator)
{
    unsigned int ibytesRead;
    unsigned int itotal;
    unsigned int ibuffer;
    char ch;
    itotal = 0;
    ibuffer = 0;
    while (ibuffer + 1 < maxLen)
    {
        ibytesRead = Read(&ch, 1);
        itotal = itotal + ibytesRead;
        if (ibytesRead != 1 || ch == usTerminator)
            break;
        pBuffer[ibuffer] = ch;
        ibuffer = ibuffer + 1;
    }
    pBuffer[ibuffer] = 0;
    return itotal;
}

struct S_00aff2a0_Class
{
    virtual void v00();

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    unsigned char unk2c;

    void BSFile_CheckIsGood();
    unsigned char __thiscall BSFile_OpenByFilePointer(int);
};

// If unk24 is already set returns 1; otherwise clears unk18, unk14 and unk20, stores a1 in unk24, calls FUN_00aff490 and returns unk2c.
// @fnv 0x00aff2a0
// src: XBOX_PDB 0x00aff2a0
unsigned char __thiscall S_00aff2a0_Class::BSFile_OpenByFilePointer(int a1)
{
    if ((bool)(int)(unk24 != 0))
    {
        return 1;
    }

    unk18 = 0;
    unk14 = 0;
    unk20 = 0;
    unk24 = a1;

    BSFile_CheckIsGood();

    return unk2c;
}

struct VTableV18_b7074
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual int v18(void* p, unsigned int n);
};

void __cdecl FUN_00ec44d0(void* p, unsigned int a, unsigned int b);
int __cdecl SwapBufferBySizes(void*, unsigned int, void*, void*);

// @fnv 0x00affa60
// src: COMMUNITY 0x00affa60
int __cdecl BSFile_WriteAndSwap(VTableV18_b7074* self, unsigned int a1, unsigned int auiSize, void* apExtra, void* a4)
{
    if (auiSize <= 0)
    {
        return 0;
    }
    void* p;
    int kRet;
    {
        void* tmp = g_memoryManager.Allocate(auiSize);
        p = tmp;
    }
    FUN_00ec44d0(p, a1, auiSize);
    if (apExtra != 0)
    {
        SwapBufferBySizes(p, auiSize, apExtra, a4);
    }
    kRet = self->v18(p, auiSize);
    {
        void* tmp2 = p;
        g_memoryManager.Deallocate(tmp2);
    }
    return kRet;
}

struct FUN_00affaf0_H
{
    unsigned int handle;
    unsigned short index;
};

int __cdecl FUN_00ecdb00(unsigned int handle);

struct FUN_00affaf0_W
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int(__cdecl* m_pfnWrite)(void* self, unsigned int h, unsigned int n, int* flag, int x);
};

struct FUN_00affaf0_cls : public BSFile
{
    unsigned int BSFile_Write(FUN_00affaf0_H* a1, bool b);
};

// @fnv 0x00affaf0
// src: XBOX_PDB 0x00affaf0
unsigned int FUN_00affaf0_cls::BSFile_Write(FUN_00affaf0_H* pEntry, bool bIncrement)
{
    unsigned int key;
    unsigned int h4;
    int flag;
    unsigned int r3 = ((FUN_00affaf0_W*)this)
                          ->m_pfnWrite(this, (h4 = pEntry->handle, flag = 1, h4),
                                       ((pEntry->index == 0xffff ? FUN_00ecdb00(key = pEntry->handle) : pEntry->index) +
                                        (bIncrement ? 1 : 0)) *
                                           2,
                                       &flag, 1);
    *(unsigned int*)((char*)this + 4) += r3;
    unsigned int t = r3;
    unsigned int s = t;
    this->m_uiBufferSize += s;
    return s >> 1;
}

typedef unsigned int(__cdecl* ReadFn)(void* stream, void* buffer, unsigned int bytes, unsigned int* componentSizes,
                                      unsigned int numComponents);
struct WStrOut
{
    void AddChunkText(const wchar_t* text);
    void SetChunkText(const wchar_t* text, unsigned int length);
};
struct AnsiConvState
{
    int s00;
    int s01;
    int s02;
    int s03;
    int s04;
    int s05;
    int s06;
    int s07;
    int s08;
    int s09;
    int s10;
    int s11;
    int s12;
    int s13;
    int s14;
    int s15;
    int s16;
    int s17;
    int s18;
    int s19;
    int s20;
    int s21;
    int s22;
    int s23;
};
struct BSFileW
{
    virtual ~BSFileW();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual bool Open(bool, bool);
    unsigned int absolutePos;
    void* readHandler;
    void* writeHandler;
    unsigned int bufferSize;
    unsigned int bufferPosition;
    unsigned int bufferEnd;
    unsigned int field1c;
    void* m_pBuffer;
    void* m_pFile;
    unsigned int ReadWideString(WStrOut* out, unsigned int maxBytes);
};
// @fnv 0x00aff640
unsigned int BSFileW::ReadWideString(WStrOut* out, unsigned int maxBytes)
{
    if (!((bool)(int)(m_pFile != 0)))
        Open(false, false);
    unsigned int count = 0;
    unsigned int kTotal = 0;
    unsigned int bytesReadB = 0;
    wchar_t buffer_[260];
    for (;;)
    {
        wchar_t ch_;
        unsigned int got4;
        {
            unsigned int uiSize4 = 1;
            unsigned int readRet;
            {
                unsigned int uiRead3 = ((ReadFn)readHandler)(this, &ch_, 2, &uiSize4, 1);
                absolutePos += uiRead3;
                readRet = uiRead3;
            }
            {
                AnsiConvState strBuf8;
                unsigned int chunk5;
                (void)strBuf8;
                (void)chunk5;
            }
            got4 = readRet;
        }
        bytesReadB += got4;
        if (got4 != 2)
            ch_ = 0;
        if (bytesReadB > maxBytes)
            ch_ = 0;
        buffer_[count] = ch_;
        count++;
        if (count == 260 || ch_ == 0)
        {
            if (kTotal)
                out->AddChunkText(buffer_);
            else
                out->SetChunkText(buffer_, 0);
            kTotal += count;
            if (ch_ == 0)
                break;
            count = 0;
        }
    }
    return bytesReadB >> 1;
}
