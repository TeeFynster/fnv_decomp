
// src/havok/common/base/system/error/hkerror.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/error/hkerror.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl __debugbreak();
struct CharBuffer
{
    char* begin;
    char* end;
    unsigned int capacity;
};
struct FUN_00cb1600_class
{
    void FUN_00cb1600(char* storage, unsigned int size);
};
struct FUN_00cc01c0_class
{
    FUN_00cc01c0_class* ProcessAndReturnValue_00cc01c0(const char* text);
    FUN_00cc01c0_class* FUN_00cc0120(const void* value);
    FUN_00cc01c0_class* WriteInt(int value);
};
struct FUN_00cc00e0_class
{
    void FUN_00cc00e0();
};
struct ErrorReporter
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual int Report(int severity, unsigned int category, const char* text, const char* file, int line);
};
extern ErrorReporter* DAT_01268360;
// Builds a reference-count error message from object and context, reports it via DAT_01268360, and breaks if reporting returns nonzero.
// @fnv 0x00cb1660
void __cdecl ReportReferenceCountError(const void* object, const char* context)
{
    CharBuffer message;
    unsigned int storage[128];
    ((FUN_00cb1600_class*)&message)->FUN_00cb1600((char*)storage, 0x200);
    int referenceCount = *(const short*)((const char*)object + 6);
    ((FUN_00cc01c0_class*)&message)
        ->ProcessAndReturnValue_00cc01c0("Reference count error on object ")
        ->FUN_00cc0120(object)
        ->ProcessAndReturnValue_00cc01c0(" with ref count of ")
        ->WriteInt(referenceCount)
        ->ProcessAndReturnValue_00cc01c0(" in ")
        ->ProcessAndReturnValue_00cc01c0(context)
        ->ProcessAndReturnValue_00cc01c0(".\n")
        ->ProcessAndReturnValue_00cc01c0(" * Are you calling delete instead of removeReference?\n")
        ->ProcessAndReturnValue_00cc01c0(" * Have you called removeReference too many times?\n")
        ->ProcessAndReturnValue_00cc01c0(
            " * In a multithreaded environment, what is the hkReferencedObject lock mode you use (see setLockMode())?\n")
        ->ProcessAndReturnValue_00cc01c0(" * Is this a valid object?\n")
        ->ProcessAndReturnValue_00cc01c0(" * Do you have more than 32768 references? (unlikely)\n");
    if (DAT_01268360->Report(3, 0x2c66f2d8, (char*)storage, ".\\System\\Error\\hkError.cpp", 0x21))
        __debugbreak();
    ((FUN_00cc00e0_class*)&message)->FUN_00cc00e0();
}

struct CB1600Bool
{
    char m_cBooleanValue;

    CB1600Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class CB1600ReferencedObject
{
  public:
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void removeReference();
};

class CB1600MemoryStreamWriter : public CB1600ReferencedObject
{
  public:
    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }

    CB1600MemoryStreamWriter(void* buf, int bufSize, CB1600Bool isString);

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class CB1600StreamBase
{
  public:
    CB1600StreamBase(void* writer);
    virtual void unk00();

    int unk04;
    CB1600MemoryStreamWriter* m_pStreamWriter;
};

class FUN_00cb1600 : public CB1600StreamBase
{
  public:
    FUN_00cb1600(void* buf, int bufSize);
    virtual void unk00();
};

// Constructs a CB1600MemoryStreamWriter in place at the end of the buffer and stores it as the stream's writer, then removes its reference.
// @fnv 0x00cb1600
FUN_00cb1600::FUN_00cb1600(void* apBuffer, int aiBufferSize) : CB1600StreamBase(0)
{
    CB1600MemoryStreamWriter* writer =
        new (static_cast<char*>(apBuffer) + aiBufferSize - sizeof(CB1600MemoryStreamWriter))
            CB1600MemoryStreamWriter(apBuffer, aiBufferSize - sizeof(CB1600MemoryStreamWriter), true);
    m_pStreamWriter = writer;
    writer->removeReference();
}

struct S_00cb17b0_Allocator
{
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct S_00cb17b0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00cb17b0_Allocator* m_pStreamAllocator;
    S_00cb17b0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00cb17b0_Router* hkMemoryRouter_getInstance();
struct S_00cb17b0_RefObj
{
    virtual ~S_00cb17b0_RefObj();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void operator delete(void* p)
    {
        S_00cb17b0_RefObj* b = static_cast<S_00cb17b0_RefObj*>(p);
        hkMemoryRouter_getInstance()->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};
struct FUN_00cb17b0 : S_00cb17b0_RefObj
{
    FUN_00cb17b0();
    virtual ~FUN_00cb17b0();
};
// @fnv 0x00cb17b0
FUN_00cb17b0::FUN_00cb17b0()
{}

struct DiagBuffer
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_buf[128];
    void FUN_00cb1600(unsigned int* buf, unsigned int size) throw();
    void ProcessAndReturnValue_00cc01c0(const char* s) throw();
    void FUN_00cc00e0() throw();
};

struct DiagLogger
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Report(int level, unsigned int hash, const char* msg, const char* file, int line);
};

extern const char str_010c85ac[];

// @fnv 0x00cb1750
// src: HAVOK_LIB 0x00cb1750
void _hkErrorMessage(const char* apMsg)
{
    DiagBuffer buf;
    buf.FUN_00cb1600(buf.m_buf, 0x200);
    buf.ProcessAndReturnValue_00cc01c0(apMsg);
    if (((DiagLogger*)DAT_01268360)->Report(3, 0x2636fe25, (const char*)buf.m_buf, str_010c85ac, 0x28) != 0)
    {
        __debugbreak();
    }
    buf.FUN_00cc00e0();
}
