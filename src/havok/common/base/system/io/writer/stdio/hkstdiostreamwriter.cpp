
// src/havok/common/base/system/io/writer/stdio/hkstdiostreamwriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/writer/stdio/hkstdiostreamwriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00d2bef0
// src: HAVOK_SRC 0x00d2bef0
void __stdcall hkStdioStreamWriter_seekTellSupported(char* p)
{
    *p = 1;
}

extern "C" long __cdecl _fseek(void* stream, long offset, int whence);

struct FUN_00d2bf00_class
{
    char m0[8];
    void* m8;
    bool Seek(long offset, int whence);
};

// @fnv 0x00d2bf00
bool FUN_00d2bf00_class::Seek(long offset, int whence)
{
    return _fseek(m8, offset, whence) != 0;
}

extern int DAT_010ce6f4;
extern int DAT_0102e388;

struct FUN_00d2bfb0_class
{
    int* vtbl;
    void fclose_00d2bfb0();
    void __thiscall FUN_00d2be50();
};

// @fnv 0x00d2bfb0
// src: XBOX_PDB 0x00d2bfb0
void __thiscall FUN_00d2bfb0_class::fclose_00d2bfb0()
{
    vtbl = &DAT_010ce6f4;
    FUN_00d2be50();
    vtbl = &DAT_0102e388;
}

void __cdecl FUN_00ecda70(void*);
// @fnv 0x00d2bec0
// src: HAVOK_LIB 0x00d2bec0
void __fastcall hkStdioStreamWriter_flush(void* self, int)
{
    void* p = *(void**)((char*)self + 8);
    if (p)
        FUN_00ecda70(p);
}

long __cdecl _ftell(void*);
struct FUN_00d2bf20_class
{
    char m0[8];
    void* m8;
    long hkStdioStreamWriter_tell();
};
// @fnv 0x00d2bf20
// src: HAVOK_LIB 0x00d2bf20
long FUN_00d2bf20_class::hkStdioStreamWriter_tell()
{
    return _ftell(m8);
}

struct FUN_00d2bf30
{
    int* vtable;
    unsigned short unk04;
    unsigned short unk06;
    void* m8;
    unsigned char unk0c;
    FUN_00d2bf30(int mode);
};
extern void* __cdecl FUN_00ecdf44();
// Sets the vtable and flags, then stores a pointer into the block returned by FUN_00ecdf44, offset by 0x40 when mode is 2 and 0x20 otherwise.
// @fnv 0x00d2bf30
FUN_00d2bf30::FUN_00d2bf30(int mode)
{
    unk06 = 1;
    vtable = &DAT_010ce6f4;
    unk0c = 0;
    char* base = static_cast<char*>(FUN_00ecdf44());
    if (mode == 2)
    {
        base += 0x40;
        m8 = base;
    }
    else
    {
        base += 0x20;
        m8 = base;
    }
}

struct FUN_00d2be30
{
    void SetFile(const char* fileName, const char* mode);
};
extern const unsigned char DAT_0106e798[];
struct Candidate : FUN_00d2be30
{
    volatile int* vtable;
    unsigned short unk04;
    volatile unsigned short flags;
    volatile void* file;
    volatile unsigned char opened;
    void* OpenFile(const char* fileName);
};
// Sets flags to 1, installs the vtable, clears file, marks opened, and if fileName is non-null calls SetFile with DAT_0106e798 as mode; returns this.
// @fnv 0x00d2bf70
void* Candidate::OpenFile(const char* fileName)
{
    flags = 1;
    vtable = &DAT_010ce6f4;
    file = 0;
    opened = 1;
    if (fileName != 0)
        SetFile(fileName, (const char*)DAT_0106e798);
    return this;
}

int __cdecl FUN_00ecb086(char* buf, int size, int count, void* stream);

struct FUN_00d2be80_cls
{
    int* vtbl;
    unsigned int unk04;
    void* m8;
    void FUN_00d2be50();
    int ReadBytes(char* p, int n);
};

// Reads n bytes from m8 into p via FUN_00ecb086; if the read returns <= 0, calls FUN_00d2be50, and returns the byte count (0 when m8 is null).
// @fnv 0x00d2be80
int FUN_00d2be80_cls::ReadBytes(char* apBuffer, int aiCount)
{
    void* stream = m8;
    if (stream != 0)
    {
        int result = FUN_00ecb086(apBuffer, 1, aiCount, stream);
        if (result <= 0)
        {
            FUN_00d2be50();
        }
        return result;
    }
    return 0;
}

struct FUN_00d2bed0_cls
{
    int unk00;
    int unk04;
    int m_08;
    unsigned char* GetFlagAsByte(unsigned char* out);
};

// @fnv 0x00d2bed0
unsigned char* FUN_00d2bed0_cls::GetFlagAsByte(unsigned char* out)
{
    *out = m_08 != 0;
    return out;
}

// @fnv 0x00d2bee0
// src: HAVOK_SRC 0x00d2bee0
void __stdcall hkStdioStreamWriter_markSupported(unsigned char* output)
{
    *output = 1;
}

struct S_00d2bfd0_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void ReleaseBlock(void* p, int nbytes);
};
struct S_00d2bfd0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d2bfd0_Heap* m_pStreamAllocator;
    static S_00d2bfd0_Router& GetMonitorStream();
    S_00d2bfd0_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};
struct S_00d2bfd0_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00d2bfd0_RefObj();
    void operator delete(void* p)
    {
        S_00d2bfd0_RefObj* b = static_cast<S_00d2bfd0_RefObj*>(p);
        S_00d2bfd0_Router::GetMonitorStream().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};
struct FUN_00d2bfd0 : S_00d2bfd0_RefObj
{
    FUN_00d2bfd0();
    virtual ~FUN_00d2bfd0();
};
// Default constructor for FUN_00d2bfd0; its body is empty.
// @fnv 0x00d2bfd0
FUN_00d2bfd0::FUN_00d2bfd0()
{}
