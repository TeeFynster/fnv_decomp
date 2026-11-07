
// src/havok/common/base/system/io/reader/stdio/hkstdiostreamreader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/reader/stdio/hkstdiostreamreader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" size_t __cdecl fread(void* ptr, size_t size, size_t count, void* stream);

struct FUN_00d2bcd0_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    char m_10;
    void ReadOrMarkFailed(void* buffer, unsigned int count);
};

// Reads count bytes from the stream at m_0c into buffer; if fread returns no bytes, sets m_10 to 0.
// @fnv 0x00d2bcd0
void FUN_00d2bcd0_class::ReadOrMarkFailed(void* buffer, unsigned int count)
{
    if ((int)fread(buffer, 1, count, m_0c) > 0)
        return;
    m_10 = 0;
}

extern int DAT_0102e388;
extern int DAT_010ce6c0;
extern int __cdecl _fclose(int);

struct FUN_00d2bda0_cls
{
    void __thiscall DestroyFileHandle();
};

// Resets the vtable pointers and closes the stored file handle if present.
// @fnv 0x00d2bda0
void __thiscall FUN_00d2bda0_cls::DestroyFileHandle()
{
    int file = *(int*)((char*)this + 0xc);
    *(int*)this = (int)&DAT_010ce6c0;
    if (file)
        _fclose(file);
    *(int*)this = (int)&DAT_0102e388;
}

long __cdecl _ftell(void*);
struct FUN_00d2bd50_cls
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    long hkStdioStreamReader_tell();
};
// @fnv 0x00d2bd50
// src: HAVOK_LIB 0x00d2bd50
long FUN_00d2bd50_cls::hkStdioStreamReader_tell()
{
    return _ftell(m_0c);
}

// @fnv 0x00d2bd10
// src: HAVOK_SRC 0x00d2bd10
void __stdcall hkStdioStreamReader_markSupported(unsigned char* output)
{
    *output = 1;
}

// @fnv 0x00d2bd20
// src: HAVOK_SRC 0x00d2bd20
void __stdcall hkStdioStreamReader_seekTellSupported(char* a1)
{
    *a1 = 1;
}

extern int __cdecl _fseek(void* stream, long offset, int origin);
struct FileObject
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* stream;
    int unk10;
    bool Seek(long offset, int origin);
};
// @fnv 0x00d2bd30
bool FileObject::Seek(long lOffset, int origin)
{
    return _fseek(stream, lOffset, origin) != 0;
}

struct ReaderWithPosition
{
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual int GetPosition() = 0;
    int unk04;
    int position;
    int SetPositionFromReader(int unused);
};
// @fnv 0x00d2bdd0
int ReaderWithPosition::SetPositionFromReader(int unused)
{
    int value = GetPosition();
    int failed = value == -1;
    position = value;
    return failed;
}

struct DispatchObject
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void invoke(void* value, int flag);
};
struct Owner : DispatchObject
{
    int unk04;
    void* unk08;
    void hkStdioStreamReader_rewindToMark();
};
// @fnv 0x00d2bdf0
// src: HAVOK_SRC 0x00d2bdf0
void Owner::hkStdioStreamReader_rewindToMark()
{
    invoke(unk08, 0);
}

extern int DAT_010cc2fc;
struct Prefix
{
    int vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ~Prefix();
};

struct FUN_00cb0a70_Class
{
    void ReturnSelf(int);
};
struct FUN_00d2c7e0_class : Prefix
{
    FUN_00cb0a70_Class sub;
    FUN_00d2c7e0_class(int value);
};
// Sets the vtable pointer and forwards value to the sub-object's FUN_00cb0a70.
// @fnv 0x00d2c7e0
FUN_00d2c7e0_class::FUN_00d2c7e0_class(int value)
{
    vtable = (int)&DAT_010cc2fc;
    sub.ReturnSelf(value);
}

struct FUN_00d2bd00_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned char unk10;
    void hkStdioStreamReader_isOk(unsigned char* out);
};

// @fnv 0x00d2bd00
// src: HAVOK_LIB 0x00d2bd00
void FUN_00d2bd00_cls::hkStdioStreamReader_isOk(unsigned char* volatile out)
{
    unsigned char value = unk10;
    *out = value;
}

extern "C" void _ReadWriteBarrier(void);
extern "C" void* __cdecl FUN_00ec9a47(const char* name, const char* mode);
extern int DAT_010ce6c0;
extern const char kModeReadBinary[];

struct StdioStreamReader
{
    int m_vptr;
    unsigned short unk04;
    unsigned short refCount;
    int lastSeek;
    void* handle;
    unsigned char IsStreamValid;
    StdioStreamReader* OpenFile(const char* fname);
};

// Initialises the stream object and opens fname in binary read mode, storing the handle and setting the flag to whether opening succeeded.
// @fnv 0x00d2bd60
StdioStreamReader* StdioStreamReader::OpenFile(const char* fname)
{
    refCount = 1;
    lastSeek = -1;
    m_vptr = (int)&DAT_010ce6c0;
    *(volatile unsigned char*)&IsStreamValid = 1;
    handle = FUN_00ec9a47(fname, kModeReadBinary);
    IsStreamValid = handle != 0;
    return this;
}

struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void DestroyFileHandle();
    CpuObject* FUN_00d2be00(unsigned int flags);
};
// @fnv 0x00d2be00
CpuObject* CpuObject::FUN_00d2be00(unsigned int flags)
{
    DestroyFileHandle();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
