
// src/havok/common/visualize/hkcommandrouter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkcommandrouter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00dd95b0_Source
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual int GetBytes(const char** bytes, int* count);
};
struct FUN_00cb18f0_t
{
    int unk00;
    int unk04;
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(int value);
};
struct FUN_00dd95b0_Outer
{
    int unk00;
    int unk04;
    FUN_00cb18f0_t output;
    void hkCommandRouter_unregisterProcess(FUN_00dd95b0_Source* source);
};
// Gets a byte buffer and count from source and feeds each byte to output.FUN_00cb1fb0.
// @fnv 0x00dd95b0
// src: HAVOK_LIB 0x00dd95b0
void FUN_00dd95b0_Outer::hkCommandRouter_unregisterProcess(FUN_00dd95b0_Source* source)
{
    int count;
    const char* bytes;
    bytes = 0;
    count = 0;
    source->GetBytes(&bytes, &count);
    for (int i = 0; i < count; ++i)
        output.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove((unsigned char)bytes[i]);
}

struct InputProvider
{
    virtual void reserved0();
    virtual void reserved1();
    virtual void GetData(unsigned char** data, int* length);
};
struct MessageContext
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* active;
};
MessageContext* __cdecl hkMemoryRouter_getInstance();
struct MessageSink
{
    void __thiscall hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(void* active, unsigned int value, InputProvider* source);
};
struct MessageProcessor
{
    void* unk00;
    void* unk04;
    MessageSink sink;
    void __thiscall ProcessInputData(InputProvider* source);
};
// Reads a byte buffer from source and, for each byte, fetches a MessageContext and passes its active pointer with the byte to sink.FUN_00cb1870.
// @fnv 0x00dd9600
void MessageProcessor::ProcessInputData(InputProvider* source)
{
    unsigned char* bytes = 0;
    int length = 0;
    source->GetData(&bytes, &length);
    for (int i = 0; i < length; ++i)
    {
        unsigned char value = bytes[i];
        MessageContext* context = hkMemoryRouter_getInstance();
        sink.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(context->active, value, source);
    }
}

// Havok Visual Debugger: server-side command dispatch loop (hkServerProcessHandler-style).

typedef unsigned char hkUint8;
typedef unsigned __int64 hkUint64;

struct S_00dd9660_Bool
{
    char m_cBooleanValue;
    S_00dd9660_Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct __declspec(align(16)) S_00dd9660_Vector4
{
    float x;
    float y;
    float z;
    float w;
};

struct S_00dd9660_Heap
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct S_00dd9660_Router
{
    int unk00;
    int unk04;
    int unk08;
    S_00dd9660_Heap* m_pStreamAllocator;

    static S_00dd9660_Router& _FUN_00c85750() throw();
    S_00dd9660_Heap& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};

int __cdecl hkArrayUtil__reserve(S_00dd9660_Heap& alloc, void* arr, int reqCapacity, int elemSize) throw();

struct S_00dd9660_CharArrayLocalForm
{ // local form of hkArray: 0x00dd9660 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(S_00dd9660_Heap& alloc, int n) throw()
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, this, newSize, sizeof(char));
        }
    }
    __forceinline void _setSize(S_00dd9660_Heap& alloc, int n) throw()
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n) throw()
    {
        _setSize(S_00dd9660_Router::_FUN_00c85750().heap(), n);
    }
    __forceinline void _clearAndDeallocate(S_00dd9660_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(char));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline ~S_00dd9660_CharArrayLocalForm() throw()
    {
        _clearAndDeallocate(S_00dd9660_Router::_FUN_00c85750().heap());
    }
    char& operator[](int i)
    {
        return m_data[i];
    }
};

struct S_00dd9660_InplaceCharArray : S_00dd9660_CharArrayLocalForm
{
    // 128 chars of inline storage, as words so /GS treats it like Havok's build (no cookie)
    unsigned int m_kStorage[32];

    __forceinline S_00dd9660_InplaceCharArray() throw()
    {
        m_data = (char*)m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 128 | 0x80000000;
    }
};

struct S_00dd9660_StringBuf
{
    S_00dd9660_InplaceCharArray m_kStringBuffer;

    __forceinline S_00dd9660_StringBuf() throw()
    {
        m_kStringBuffer.SetSizeAndGrow(1);
        m_kStringBuffer[0] = 0;
    }
    __forceinline void clear() throw()
    {
        m_kStringBuffer[0] = 0;
    }
    void hkStringBuf_printf(const char* fmt, ...) throw();
};

struct S_00dd9660_StreamReader;

struct S_00dd9660_IArchive
{
    int unk00;
    int unk04;
    S_00dd9660_StreamReader* m_pStreamReader;
    char m_bStreamResult;

    void hkIArchive_readArrayGeneric(void* buf, int elemSize, int nelem);
    void readQuadVector4(S_00dd9660_Vector4& v);
    S_00dd9660_Bool GetStreamResult();

    __forceinline hkUint8 read8u()
    {
        hkUint8 c;
        hkIArchive_readArrayGeneric(&c, 1, 1);
        return c;
    }
    __forceinline hkUint64 read64u()
    {
        hkUint64 c;
        hkIArchive_readArrayGeneric(&c, 8, 1);
        return c;
    }
};

struct S_00dd9660_Process
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void ExecuteCommand(hkUint8 command);
};

struct S_00dd9660_CommandMap
{
    int LookupBucketValue(unsigned long key, S_00dd9660_Process** out);
};

struct S_00dd9660_Handler
{
    int unk00;
    int unk04;
    S_00dd9660_CommandMap m_kCommandMap;

    S_00dd9660_Bool ReadCommands(S_00dd9660_IArchive* stream);
};

// @fnv 0x00dd9660
S_00dd9660_Bool S_00dd9660_Handler::ReadCommands(S_00dd9660_IArchive* stream)
{
    hkUint8 command;
    do
    {
        command = stream->read8u();
        if (command != 0xf0)
        {
            S_00dd9660_Process* p;
            if (m_kCommandMap.LookupBucketValue(command, &p) == 0 && p)
            {
                p->ExecuteCommand(command);
            }
            else
            {
                S_00dd9660_Vector4 v;
                if (command == 0xb0)
                {
                    stream->readQuadVector4(v);
                    hkUint64 id = stream->read64u();
                }
                else if (command == 0xb1)
                {
                    stream->readQuadVector4(v);
                }
                S_00dd9660_StringBuf buf;
                buf.clear();
                buf.hkStringBuf_printf("VDB: Found a command (%x) with no handler. Could corrupt the stream.", command);
            }
        }
    } while (stream->GetStreamResult() && command != 0xf0);
    return true;
}
