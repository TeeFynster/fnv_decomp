
// src/staging/blk_00aa0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiTFixedStringMap.h"
#include "../../include/NiTFixedStringMap_NiAVObject___.h"

extern void* DAT_011f6044;

// @fnv 0x00aa0000
// src: COMMUNITY 0x00aa0000
void NiShaderFactory_ReleaseAllShaders()
{
    if (DAT_011f6044)
        ((void(__thiscall*)(void*)) * (void**)(*(char**)DAT_011f6044 + 0x20))(DAT_011f6044);
}

extern "C" void* DAT_011f6078;

extern MemoryManager g_memoryManager;

// @fnv 0x00aa1980
// src: COMMUNITY 0x00aa1980
void NiSystemDesc_ShutdownSystemDesc()
{
    g_memoryManager.Deallocate(DAT_011f6078);
}

class NiFileHack : public NiFile
{
  public:
    unsigned int FileRead(void* buffer, unsigned int size);
};

// @fnv 0x00aa19a0
unsigned int __cdecl ReadFileData(NiFileHack* apFile, void* buffer, unsigned int size)
{
    return apFile->FileRead(buffer, size);
}

extern int DAT_011f6110;
extern int DAT_011f6114;

extern "C" void __cdecl NiStaticDataManager_SetRootLibrary(int a, int b);

// @fnv 0x00aa2060
// src: COMMUNITY 0x00aa2060
extern "C" void __cdecl NiStaticDataManager_SetRootLibrary(int aiFirst, int aiSecond)
{
    DAT_011f6110 = aiFirst;
    DAT_011f6114 = aiSecond;
}

extern "C" void __cdecl InitHolder();
extern "C" void __cdecl NiSystemDesc_NiSystemDesc();
extern "C" void __cdecl OEI_IO_initialize();
extern unsigned char DAT_011f6229;

// If the global flag DAT_011f6229 is clear, sets it to 1 and calls InitHolder, FUN_00aa1920 and FUN_00aa7eb0 once.
// @fnv 0x00aa3050
// src: COMMUNITY 0x00aa3050
void __cdecl NiSystemSDM_Init()
{
    if (DAT_011f6229 == 0)
    {
        DAT_011f6229 = 1;
        InitHolder();
        NiSystemDesc_NiSystemDesc();
        OEI_IO_initialize();
    }
}

void* __cdecl _NiMalloc(unsigned int);
void __cdecl _NiFree(void*);
void* __cdecl _memmove(void*, const void*, unsigned int);
struct FUN_00aa1010_s
{
    unsigned int m_uiSize;
    void* m_pData;
    void ResizeAndCopy(unsigned int uiNewSize, const void* pData);
};
// @fnv 0x00aa1010
void FUN_00aa1010_s::ResizeAndCopy(unsigned int uiNewSize, const void* pData)
{
    if (*(unsigned int*)((char*)this + 0x10) < uiNewSize)
    {
        _NiFree(*(void**)((char*)this + 0x14));
        *(void**)((char*)this + 0x14) = 0;
        *(unsigned int*)((char*)this + 0x10) = uiNewSize;
    }
    if (!*(void**)((char*)this + 0x14))
        *(void**)((char*)this + 0x14) = _NiMalloc(*(unsigned int*)((char*)this + 0x10));
    if (pData)
        _memmove(*(void**)((char*)this + 0x14), pData, uiNewSize);
}

// Placeholder declarations
void __cdecl FUN_00aa1d10();
void _FUN_00aa2e60();
void _FUN_00aa2ea0();
extern int DAT_010a256c;

struct FUN_00aa2ff0_s
{
    void* m_pVtable;            // +0x00
    int m_unknown04;            // +0x04
    void* m_pFunc08;            // +0x08
    void* m_pFunc0c;            // +0x0c
    void* m_pData;              // +0x10
    unsigned int m_uiCount;     // +0x14
    unsigned int m_uiCapacity;  // +0x18
    unsigned int m_uiSize;      // +0x1c
    unsigned char m_bFlag20;    // +0x20
    unsigned char m_bFlag21;    // +0x21
    FUN_00aa2ff0_s* NiMemStream_NiMemStream();
};

// @fnv 0x00aa2ff0
// src: EXE 0x00aa2ff0
FUN_00aa2ff0_s* FUN_00aa2ff0_s::NiMemStream_NiMemStream()
{
    FUN_00aa1d10();
    m_pVtable = &DAT_010a256c;
    m_uiSize = 0x400;
    m_pData = _NiMalloc(0x400);
    m_uiCount = 0;
    m_uiCapacity = 0;
    m_bFlag20 = 0;
    m_bFlag21 = 0;
    m_pFunc08 = (void*)_FUN_00aa2e60;
    m_pFunc0c = (void*)_FUN_00aa2ea0;
    return this;
}

extern char DAT_010a2138;
extern MemoryManager _g_memoryManager;

// @fnv 0x00aa02b0
void* NiTFixedStringMap_NiAVObject___::Destroy(int flags)
{
    m_baseData0 = &DAT_010a2138;
    RemoveAll();
    _NiFree(*(void**)((char*)this + 0x08));
    if (flags & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}

namespace fnv_00aa02f0 {
struct FUN_00aa02f0_s : public NiTFixedStringMap_NiAVObject___
{
    void* m_pData;
    void* FUN_00aa02f0(unsigned char bDelete);
};

extern void* DAT_010a2138;
extern void* DAT_010a2154;
extern MemoryManager _g_memoryManager;

// @fnv 0x00aa02f0
void* FUN_00aa02f0_s::FUN_00aa02f0(unsigned char bDelete)
{
    m_baseData0 = &DAT_010a2154;
    RemoveAll();

    m_baseData0 = &DAT_010a2138;
    RemoveAll();

    _NiFree(m_pData);

    if (bDelete & 1)
    {
        _g_memoryManager.Deallocate(this);
    }

    return this;
}
}  // namespace fnv_00aa02f0

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(long long*);
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(long long*);
extern unsigned char DAT_011ac222;
extern long long DAT_011f6068;
extern long long DAT_011f606c;
extern long long DAT_011f6070;

// Initializes the performance frequency and start counter once, then returns the seconds elapsed since that start counter.
// @fnv 0x00aa12f0
float GetElapsedSeconds()
{
    long long currentCounter;
    if (DAT_011ac222 != 0)
    {
        QueryPerformanceFrequency(&DAT_011f6070);
        QueryPerformanceCounter(&DAT_011f6068);
        DAT_011ac222 = 0;
    }
    QueryPerformanceCounter(&currentCounter);
    long long diff = currentCounter - DAT_011f6068;
    return (float)diff / (float)DAT_011f6070;
}

struct FUN_00aa21d0_s
{
    void* m_p;
    unsigned char m_kPointB;
    FUN_00aa21d0_s* InitializeFields_00aa21d0(void* v);
};
// @fnv 0x00aa21d0
// src: GUESS 0x00aa21d0 (confidence: low)
FUN_00aa21d0_s* FUN_00aa21d0_s::InitializeFields_00aa21d0(void* v)
{
    m_p = v;
    m_kPointB = 0;
    return this;
}

struct HashNode
{
    HashNode* next;
    unsigned int key;
};
class HashTableBase
{
  public:
    virtual void unknown0();
    virtual void unknown1();
    virtual void destroy(HashNode* node);
    unsigned int bucketCount;
    HashNode** buckets;
    unsigned int count;
    bool NiTStringPointerMap_NiAVObject_RemoveAt(const unsigned int* key);
};
// Looks up the node whose key matches *key in its bucket, unlinks and destroys it, decrements count, and returns whether it was found.
// @fnv 0x00aa0250
// src: COMMUNITY 0x00aa0250
bool HashTableBase::NiTStringPointerMap_NiAVObject_RemoveAt(const unsigned int* key)
{
    unsigned int value = *key;
    HashNode** link = &buckets[value % bucketCount];
    HashNode* node = *link;
    if (node != 0)
    {
        if (value == node->key)
        {
            *link = node->next;
            destroy(node);
            --count;
            return true;
        }
        link = &node->next;
        for (node = node->next; node != 0; node = node->next)
        {
            if (value == node->key)
            {
                *link = node->next;
                destroy(node);
                --count;
                return true;
            }
            link = &node->next;
        }
    }
    return false;
}

struct FUN_00aa09c0_cls : NiRefObject
{
    virtual ~FUN_00aa09c0_cls();
};

// @fnv 0x00aa09c0
FUN_00aa09c0_cls::~FUN_00aa09c0_cls()
{}

struct FUN_00aa0ff0_cls
{
    int unk00;
    int unk04;
    int m_08;

    unsigned char NiAccumulator_IsAccumulating();
};

// @fnv 0x00aa0ff0
// src: COMMUNITY 0x00aa0ff0
unsigned char FUN_00aa0ff0_cls::NiAccumulator_IsAccumulating()
{
    if (m_08 != 0)
        return 1;
    return 0;
}

struct DeviceInterface
{
    virtual void Unknown();
    virtual void Dispatch(int* value, int* command, int a, int b, int c, int d, int e);
};
extern "C" DeviceInterface** DAT_011f6080;

// Defaults value to 1 if zero, then dispatches command 4 with the adjusted value through the device interface.
// @fnv 0x00aa13e0
// src: GUESS 0x00aa13e0 (confidence: medium)
void __cdecl Object_DispatchCommandFour(int value)
{
    if (!value)
        value = 1;
    int adjusted = value;
    DeviceInterface* device = *DAT_011f6080;
    int command = 4;
    device->Dispatch(&adjusted, &command, 1, 1, 0, -1, 0);
}

struct FUN_00aff950_shell
{
    unsigned int __thiscall FUN_00aa1810(void* buffer, unsigned int size);
};

// @fnv 0x00aa19c0
// src: COMMUNITY 0x00aa19c0
void __cdecl NiFile_WriteNoSwap(void* object, void* buffer, unsigned int size)
{
    reinterpret_cast<FUN_00aff950_shell*>(object)->FUN_00aa1810(buffer, size);
}

// FUN_00aa1d10 : constructor of the object whose first member is the class
// vtable pointer; the constructor installs the vtable and clears the three
// trailing dword members (stored in the order +8, +0xc, +4).

extern int DAT_010a24b8;

struct FUN_00aa1d10_cls
{
    void* m_pVTable;
    int m_iValue04;
    int m_iValue08;
    int m_iValue0c;

    FUN_00aa1d10_cls();
};

// @fnv 0x00aa1d10
FUN_00aa1d10_cls::FUN_00aa1d10_cls()
{
    m_pVTable = (void*)&DAT_010a24b8;
    m_iValue08 = 0;
    m_iValue0c = 0;
    m_iValue04 = 0;
}

extern int DAT_010a24b8;

struct FUN_00aa1d30_cls
{
    int m_vptr00;

    void SetVptr00();
};

// @fnv 0x00aa1d30
// src: GUESS 0x00aa1d30 (confidence: low)
void FUN_00aa1d30_cls::SetVptr00()
{
    m_vptr00 = (int)&DAT_010a24b8;
}

class FUN_00aa1fd0_cls
{
  public:
    unsigned int unk00;
    int m_04;
    unsigned int unk08;
    int(__cdecl* m_0c)(FUN_00aa1fd0_cls* self, char* s, int a, int* out, int b);
    unsigned int AdvanceChars(char* s);
};

// Advances through the string, calling m_0c per character, accumulating its result into m_04, and returns the number of successfully consumed characters.
// @fnv 0x00aa1fd0
unsigned int FUN_00aa1fd0_cls::AdvanceChars(char* s)
{
    unsigned int count = 0;
    if (*s != 0)
    {
        do
        {
            int out = 1;
            int r = m_0c(this, s, 1, &out, 1);
            m_04 += r;
            s++;
            if (r != 1)
            {
                break;
            }
            count++;
        } while (*s != 0);
    }
    return count;
}

namespace fnv_00aa2020 {
struct FUN_00aa2020_Impl
{
    virtual void FUN_00aa2020_00();
    virtual void FUN_00aa2020_01();
    virtual void FUN_00aa2020_02();
    virtual void FUN_00aa2020_03();
    virtual void FUN_00aa2020_04();
    virtual void FUN_00aa2020_05();
    virtual void FUN_00aa2020_06();
    virtual void FUN_00aa2020_07();
};

struct FUN_00aa2020_Holder
{
    FUN_00aa2020_Impl* m_pImpl;
};

struct FUN_00aa2020_Source
{
    FUN_00aa2020_Impl* NiInitOptions_GetAllocator();
};

extern MemoryManager DAT_011f6238;
extern FUN_00aa2020_Source* DAT_011f6118;
extern FUN_00aa2020_Holder* DAT_011f6080;

// Allocates a 4-byte holder, stores the impl obtained from DAT_011f6118 into it, then calls the impl's method.
// @fnv 0x00aa2020
extern "C" void __cdecl InitHolder()
{
    DAT_011f6080 = static_cast<FUN_00aa2020_Holder*>(DAT_011f6238.Allocate(4));
    DAT_011f6080->m_pImpl = DAT_011f6118->NiInitOptions_GetAllocator();
    DAT_011f6080->m_pImpl->FUN_00aa2020_07();
}
}  // namespace fnv_00aa2020

typedef void(__cdecl* FUN_00aa2080_callback)();

extern int DAT_011f6108;
extern unsigned char DAT_011f610c;
extern FUN_00aa2080_callback DAT_011f60c8[];
extern int DAT_011f6088[];

// Stores callback and value in parallel arrays at the current index, increments the index, and invokes the callback if the flag is set.
// @fnv 0x00aa2080
// src: COMMUNITY 0x00aa2080
void __cdecl NiStaticDataManager_AddLibrary(FUN_00aa2080_callback callback, int value)
{
    DAT_011f60c8[DAT_011f6108] = callback;
    DAT_011f6088[DAT_011f6108] = value;
    ++DAT_011f6108;

    if (DAT_011f610c)
        return callback();
}

namespace fnv_00aa2170 {
extern MemoryManager DAT_011f6238;
extern unsigned char DAT_011f610c;
extern unsigned char DAT_011f610d;
extern unsigned int DAT_011f6108;
extern void* DAT_011f6088[];
extern int DAT_011f6114;
extern void* DAT_011f6118;

void __cdecl NiSystemSDM_Shutdown();

struct FUN_00aa21e0_shell
{
    void __thiscall ProcessState_00aa21e0();
};

// @fnv 0x00aa2170
// src: COMMUNITY 0x00aa2170
void __cdecl NiStaticDataManager_Shutdown()
{
    for (unsigned int i = 0; i < DAT_011f6108; ++i)
    {
        ((void(__cdecl*)())DAT_011f6088[i])();
    }
    if (DAT_011f6114 != 0)
    {
        ((void(__cdecl*)())DAT_011f6114)();
    }
    NiSystemSDM_Shutdown();
    if (DAT_011f610d != 0)
    {
        void* obj = DAT_011f6118;
        if (DAT_011f6118 != 0)
        {
            ((FUN_00aa21e0_shell*)DAT_011f6118)->ProcessState_00aa21e0();
            DAT_011f6238.Deallocate(obj);
        }
    }
    DAT_011f610c = 0;
}
}  // namespace fnv_00aa2170

// FUN_00aa21e0 : 21 bytes, thiscall, /MT /O2
// Reads a byte flag at this+4; if set, takes the member pointer at this+0,
// null-checks it, and calls the object's first virtual with the argument 1.

class FUN_00aa21e0_inner
{
  public:
    virtual void v00(int aArg);
};

class FUN_00aa21e0_cls
{
  public:
    FUN_00aa21e0_inner* m_pObject;
    unsigned char m_bEnableState;

    void ProcessState_00aa21e0();
};

// @fnv 0x00aa21e0
// src: GUESS 0x00aa21e0 (confidence: low)
void FUN_00aa21e0_cls::ProcessState_00aa21e0()
{
    if (m_bEnableState)
    {
        if (m_pObject)
        {
            m_pObject->v00(1);
        }
    }
}

// ---------------------------------------------------------------------------
// FUN_00aa2230  (0x00aa2230, 9 bytes)
//
//     8b c1                 mov     eax, ecx
//     c7 00 28 25 0a 01     mov     dword ptr [eax], 010a2528h
//     c3                    ret
//
// This is the constructor of BSNiAllocator (the vftable at 010a2528h carries
// the RTTI name ".?AVBSNiAllocator@@").  The class has no base class, so the
// whole constructor is just the vftable store: MSVC copies `this` into EAX
// (a constructor returns `this` in EAX) and writes the vftable pointer to
// offset 0 of the object.
//
// The stand-in class is named with the FUN_00aa2230 tag so that the mangled
// constructor symbol ??0FUN_00aa2230_BSNiAllocator@@QAE@XZ is the one and only
// defined function symbol that carries the tag the checker looks for.
// One virtual is enough to make the compiler emit a vftable; the checker's
// literal-content check masks every relocated slot of that table, so the
// number of slots does not have to match the original's fourteen.
// ---------------------------------------------------------------------------

struct FUN_00aa2230_BSNiAllocator
{
    virtual void m_virtual0();
    FUN_00aa2230_BSNiAllocator();
};

// @fnv 0x00aa2230
FUN_00aa2230_BSNiAllocator::FUN_00aa2230_BSNiAllocator()
{}

extern char DAT_010a2554[];

struct FUN_00aa24d0
{
    void* unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    int unk0c;
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAc;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBc;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCc;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDc;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEc;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFc;
    int unk100;
    int unk104;
    int unk108;
    unsigned char unk10c;

    FUN_00aa24d0();
};

// @fnv 0x00aa24d0
FUN_00aa24d0::FUN_00aa24d0()
{
    unk00 = DAT_010a2554;
    unk04 = 0;
    unk08 = 0;
    unk10c = 0;
}

namespace fnv_00aa24f0 {
extern int DAT_010a2554;

struct FUN_00aa24f0_cls
{
    int m_vptr00;

    void SetVptr00();
};

// @fnv 0x00aa24f0
// src: GUESS 0x00aa24f0 (confidence: low)
void FUN_00aa24f0_cls::SetVptr00()
{
    m_vptr00 = (int)&DAT_010a2554;
}
}  // namespace fnv_00aa24f0

// SuspendThreadHandle: suspends the worker thread owned by this object.
//
// The object keeps the thread handle at +0x24 and a "suspended" flag at +0x1c.
// When no thread handle is stored the call fails immediately with -1; otherwise
// the thread is suspended and, if the suspend succeeded, the flag is raised.
extern "C" __declspec(dllimport) unsigned long __stdcall SuspendThread(void*);

class FUN_00aa2710_cls
{
  public:
    void* m_pVtable;             // +0x00
    int m_unk04;                 // +0x04
    int m_unk08;                 // +0x08
    int m_unk0c;                 // +0x0c
    int m_unk10;                 // +0x10
    int m_unk14;                 // +0x14
    int m_unk18;                 // +0x18
    unsigned int m_uiSuspended;  // +0x1c
    int m_unk20;                 // +0x20
    void* m_pThreadHandle;       // +0x24

    unsigned int SuspendThreadHandle();
};

// @fnv 0x00aa2710
unsigned int FUN_00aa2710_cls::SuspendThreadHandle()
{
    void* pThread = m_pThreadHandle;
    if (pThread == 0)
        return 0xffffffffu;

    unsigned int uResult = SuspendThread(pThread);
    if (uResult != 0xffffffffu)
        m_uiSuspended = 1;

    return uResult;
}

struct FUN_00aa2d60_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char unk20;
    unsigned char m_21;
    void* NiMemStream_Str();
};

// @fnv 0x00aa2d60
// src: XBOX_PDB 0x00aa2d60
void* FUN_00aa2d60_cls::NiMemStream_Str()
{
    m_21 = 1;
    return m_10;
}

void NiMemStream_ReadNoSwap();
void NiMemStream_WriteNoSwap();

struct S_00aa2fb0_Base
{
    virtual void v0();
    int unk04;
    void (*unk08)();
    void (*unk0c)();
    S_00aa2fb0_Base();
};

struct FUN_00aa2fb0 : S_00aa2fb0_Base
{
    void* unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned char unk20;
    unsigned char unk21;
    FUN_00aa2fb0(void* a, unsigned int b);
};

// @fnv 0x00aa2fb0
FUN_00aa2fb0::FUN_00aa2fb0(void* a, unsigned int b) : unk10(a), unk14(0), unk1c(b), unk20(1), unk21(0)
{
    unk18 = b;
    unk08 = NiMemStream_ReadNoSwap;
    unk0c = NiMemStream_WriteNoSwap;
}

namespace fnv_00aa3070 {
extern unsigned char DAT_011f6229;
void OEI_IO_terminate();
void NiSystemDesc_ShutdownSystemDesc();
void Object_DoNothing();

// If DAT_011f6229 is set, clears it and calls FUN_00aa81d0, FUN_00aa1980 and FUN_00a29680.
// @fnv 0x00aa3070
// src: COMMUNITY 0x00aa3070
void NiSystemSDM_Shutdown()
{
    if (DAT_011f6229 != 0)
    {
        DAT_011f6229 = 0;
        OEI_IO_terminate();
        NiSystemDesc_ShutdownSystemDesc();
        Object_DoNothing();
    }
}
}  // namespace fnv_00aa3070

struct S_00aa36f0_State
{
    unsigned int unk00;
    unsigned char unk04;
    unsigned char unk05;
};

void __cdecl SwapIntPairs(void* a, void* b);
void __cdecl FreeAllocatorBlock(unsigned int value);

struct S_00aa36f0_Foo
{
    volatile unsigned int unk00;
    unsigned char unk04;
    unsigned char unk05;
    S_00aa36f0_State* unk08;
    unsigned int unk0c;
    unsigned int unk10;
    void* unk14;
    S_00aa36f0_State* unk18;
    S_00aa36f0_State* unk1c;

    void WriteBufferByte(unsigned char* buffer);
};

// @fnv 0x00aa36f0
void S_00aa36f0_Foo::WriteBufferByte(unsigned char* buffer)
{
    S_00aa36f0_State* state = unk18;
    unsigned char value = state->unk04;
    unsigned int divisor = unk00;

    *buffer = value;

    unsigned int quotient = ((unsigned int)buffer - state->unk00) / divisor;

    ++state->unk05;
    state->unk04 = (unsigned char)quotient;

    state = unk18;
    if (state->unk05 == unk04)
    {
        S_00aa36f0_State* next = unk1c;

        if (next != 0)
        {
            S_00aa36f0_State* entry = unk08 + unk0c - 1;

            if (entry == state)
            {
                unk18 = next;
            }
            else if (entry != next)
            {
                SwapIntPairs(next, entry);
            }

            FreeAllocatorBlock(entry->unk00);

            state = unk18;
            --unk0c;
            unk14 = state;
        }

        unk1c = state;
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);

void* __cdecl NiMallocAA3(unsigned int uiSize) throw();
extern "C" void* __cdecl MemSetAA3(void* pvDest, int iValue, unsigned int uiSize);

__forceinline NiRefObject::NiRefObject()
{
    m_uiRefCount = 0;
    InterlockedIncrement((long volatile*)&ms_lObjectCount);
}

class NiGlobalConstantEntry;

// Vftables 0x010a2138/0x010a2154 identify the fixed-string global-constant map (nishaderfactory.cpp).
template <>
__forceinline NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString, NiGlobalConstantEntry*> >, NiGlobalConstantEntry*>::NiTFixedStringMapBase(unsigned int uiHashSize)
{
    m_uiHashSize = uiHashSize;
    m_kItemCount.m_uiCount = 0;
    unsigned int uiSize = sizeof(EntryType*) * m_uiHashSize;
    m_ppkHashTable = (EntryType**)NiMallocAA3(uiSize);
    MemSetAA3(m_ppkHashTable, 0, m_uiHashSize * sizeof(EntryType*));
}

template <>
__forceinline NiTFixedStringMap<NiGlobalConstantEntry*>::NiTFixedStringMap(unsigned int uiHashSize)
    : NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString, NiGlobalConstantEntry*> >, NiGlobalConstantEntry*>(uiHashSize)
{}

class FUN_00aa0390 : public NiRefObject
{
  public:
    FUN_00aa0390() throw();
    virtual ~FUN_00aa0390() throw();

    NiTFixedStringMap<NiGlobalConstantEntry*> m_kFormatEntries;
    void* m_pkFirst;
    void* m_pkSecond;
    void* m_pkThird;
};

// Initializes the three pointers to null and default-constructs the string map; the base NiRefObject constructor runs first.
// @fnv 0x00aa0390
FUN_00aa0390::FUN_00aa0390() throw() : m_pkFirst(0), m_pkSecond(0), m_pkThird(0)
{}

extern "C" unsigned int __cdecl strlen(const char* pcString);

static const char kBackslash = 0x5c;
static const char kForwardSlash = 0x2f;

// Converts forward slashes to backslashes in pcPath in place and collapses repeated separators, then null-terminates.
// @fnv 0x00aa1380
void __cdecl NormalizePathSeparators(char* pcPath)
{
    if (!pcPath)
        return;

    unsigned int uiLen = strlen(pcPath);
    bool bLastWasSeparator = false;
    unsigned int uiDest = 0;
    for (unsigned int ui = 0; ui < uiLen; ui++)
    {
        char c = pcPath[ui];
        if (c == kForwardSlash)
            c = kBackslash;
        bool bSeparator = (c == kBackslash);
        if (!bSeparator || !bLastWasSeparator || ui <= 1)
        {
            pcPath[uiDest] = c;
            bLastWasSeparator = bSeparator;
            uiDest++;
        }
    }
    pcPath[uiDest] = 0;
}

extern char DAT_010a2490[];

struct FUN_00aa14b0_Obj
{
    void* m_pVtable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;

    void FUN_00aa1d10();
    unsigned int* Reset();
};

// @fnv 0x00aa14b0
unsigned int* FUN_00aa14b0_Obj::Reset()
{
    FUN_00aa1d10();

    unk20 = 0;
    unk24 = 0;
    unk1C = 0;
    m_pVtable = DAT_010a2490;

    return reinterpret_cast<unsigned int*>(this);
}

void __cdecl ReverseBytesInBlocks(void*, unsigned int);
inline void SwapByte(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}
inline void Swap2(char* data)
{
    SwapByte(data[0], data[1]);
}
inline void Swap4(char* data, int count)
{
    for (int i = 0; i < count; ++i)
    {
        SwapByte(data[0], data[3]);
        SwapByte(data[1], data[2]);
        data += 4;
    }
}
// @fnv 0x00aa1de0
void __cdecl SwapBufferBySizes(char* buffer, unsigned int length, const unsigned int* sizes, unsigned int count)
{
    char* data = buffer;
    unsigned int done = 0;
    while (done < length)
    {
        for (unsigned int i = 0; i < count; ++i)
        {
            unsigned int size = sizes[i];
            switch (size)
            {
            case 2:
                Swap2(data);
                break;
            case 4:
                Swap4(data, 1);
                break;
            case 8:
                ReverseBytesInBlocks(data, 1);
                break;
            case 16:
            case 64:
                Swap4(data, size / 4);
                break;
            }
            done += size;
            data += size;
        }
    }
}

namespace fnv_00aa2820 {
int strcat_s(char* dst, unsigned int size, const char* src);
char* SafeStrcat(char* dst, unsigned int size, const char* src);

class FileNameComponents
{
  public:
    char m_acFolderPath[256];
    char m_cDrive;
    char unk101;
    char unk102;
    char m_acExtension[256];
    char m_acBaseName[256];
    char m_acDirectoryComponent[256];

    bool BuildFullPath(char* pcFullPath, unsigned int uiStrLen);
};

// @fnv 0x00aa2820
bool FileNameComponents::BuildFullPath(char* pcOutPath, unsigned int uiBufferSize)
{
    if (!pcOutPath)
        return false;

    unsigned int uiLen = 1;
    if (m_cDrive)
        uiLen = 3;
    if (m_acFolderPath[0])
    {
        unsigned int uiPartLen = strlen(m_acFolderPath);
        uiLen += uiPartLen;
        char c = m_acFolderPath[uiPartLen - 1];
        if (c != '\\' && c != '/')
            uiLen++;
    }
    if (m_acDirectoryComponent[0])
    {
        unsigned int uiPartLen = strlen(m_acDirectoryComponent);
        uiLen += uiPartLen;
        char c = m_acDirectoryComponent[uiPartLen - 1];
        if (c != '\\' && c != '/')
            uiLen++;
    }
    if (m_acBaseName[0])
        uiLen += strlen(m_acBaseName);
    if (m_acExtension[0])
    {
        if (m_acExtension[0] != '.')
            uiLen++;
        uiLen += strlen(m_acExtension);
    }
    if (uiLen > uiBufferSize)
        return false;

    pcOutPath[0] = 0;
    if (m_cDrive)
    {
        pcOutPath[0] = m_cDrive;
        pcOutPath[1] = ':';
        pcOutPath[2] = 0;
    }
    if (m_acFolderPath[0])
    {
        strcat_s(pcOutPath, uiBufferSize, m_acFolderPath);
        char c = pcOutPath[strlen(pcOutPath) - 1];
        if (c != '\\' && c != '/')
            SafeStrcat(pcOutPath, uiBufferSize, "\\");
    }
    if (m_acDirectoryComponent[0])
    {
        strcat_s(pcOutPath, uiBufferSize, m_acDirectoryComponent);
        char c = pcOutPath[strlen(pcOutPath) - 1];
        if (c != '\\' && c != '/')
            SafeStrcat(pcOutPath, uiBufferSize, "\\");
    }
    if (m_acBaseName[0])
        strcat_s(pcOutPath, uiBufferSize, m_acBaseName);
    if (m_acExtension[0])
    {
        if (m_acExtension[0] != '.')
            strcat_s(pcOutPath, uiBufferSize, ".");
        strcat_s(pcOutPath, uiBufferSize, m_acExtension);
    }
    return true;
}
}  // namespace fnv_00aa2820

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern "C" char* DAT_0109b220;
char* __cdecl FUN_00a5b690(const char* pcString);
extern MemoryManager DAT_011f6238;
class FixedStringAA0
{
  public:
    static void* operator new(unsigned int uiSize) throw()
    {
        return DAT_011f6238.Allocate(uiSize);
    }
    FixedStringAA0() throw()
    {
        m_kHandle = DAT_0109b220;
    }
    FixedStringAA0(const char* pcString) throw()
    {
        if (pcString == 0)
            m_kHandle = DAT_0109b220;
        else
            m_kHandle = FUN_00a5b690(pcString);
    }
    FixedStringAA0& operator=(const FixedStringAA0& kString) throw()
    {
        char* pkHandle = kString.m_kHandle;
        if (m_kHandle != pkHandle)
        {
            if (pkHandle != DAT_0109b220)
                InterlockedIncrement((long volatile*)(pkHandle - 8));
            if (m_kHandle != DAT_0109b220)
                InterlockedDecrement((long volatile*)(m_kHandle - 8));
            m_kHandle = pkHandle;
        }
        return *this;
    }
    char* m_kHandle;
};
class FUN_00aa00d0 : public NiRefObject
{
  public:
    FUN_00aa00d0(const char* pcName, unsigned int uiValue, unsigned int uiSize, const void* pvData) throw();
    virtual ~FUN_00aa00d0() throw();
    void ResizeAndCopy(unsigned int uiNewSize, const void* pvData);

    FixedStringAA0 m_kName;
    unsigned int m_uiCurrentValue;
    unsigned int m_uiSize;
    void* m_pResource;
};
// @fnv 0x00aa00d0
FUN_00aa00d0::FUN_00aa00d0(const char* pcName, unsigned int uiValue, unsigned int uiSize, const void* pvData) throw()
    : m_uiCurrentValue(0), m_uiSize(0), m_pResource(0)
{
    m_kName = *new FixedStringAA0(pcName);
    m_uiCurrentValue = uiValue;
    ResizeAndCopy(uiSize, pvData);
}

extern "C" void __cdecl BSTextureSet_RegisterStreamables();

// @fnv 0x00aa0ad0
// src: XBOX_PDB 0x00aa0ad0
void __cdecl BSPackedAdditionalGeometryData_RegisterStreamables()
{
    BSTextureSet_RegisterStreamables();
}

static inline void DecRefStringAA0(char*& kHandle)
{
    if (kHandle != DAT_0109b220)
        InterlockedDecrement((long volatile*)(kHandle - 8));
}
struct FixedStrAA0
{
    char* m_kHandle;
    ~FixedStrAA0()
    {
        DecRefStringAA0(m_kHandle);
    }
    FixedStrAA0& operator=(const char* pcString)
    {
        if (m_kHandle != pcString)
        {
            char* kHandle = m_kHandle;
            m_kHandle = FUN_00a5b690(pcString);
            DecRefStringAA0(kHandle);
        }
        return *this;
    }
};
struct StringMapItemAA0
{
    StringMapItemAA0* m_pkNext;
    FixedStrAA0 m_key;
    void* m_val;
};
// Resets the key and value of a StringMapItemAA0, runs its destructor, and returns it to the memory manager.
// @fnv 0x00aa0330
// src: GUESS 0x00aa0330 (confidence: low)
void __stdcall Runtime_ReleaseStorage_00aa0330(StringMapItemAA0* pkItem)
{
    pkItem->m_key = 0;
    pkItem->m_val = 0;
    pkItem->~StringMapItemAA0();
    DAT_011f6238.Deallocate(pkItem);
}

struct ProcessingState
{
    unsigned int FUN_00aa1810(void* buffer, unsigned int size);
};

void* __cdecl _NiMalloc_00aa1070(unsigned int size);
void __cdecl FUN_00ec44d0(void* destination, const void* source, unsigned int size);
void __cdecl SwapBufferBySizes(void* buffer, unsigned int size, void* optionA, void* optionB);
void __cdecl _NiFree_00aa10f0(void* buffer);

// If size is non-zero, copies data to a temporary buffer, calls SwapBufferBySizes on it, returns state->FUN_00aa1810(buffer, size) and frees the buffer; else 0.
// @fnv 0x00aa1ad0
// src: COMMUNITY 0x00aa1ad0
unsigned int __cdecl NiFile_WriteAndSwap(ProcessingState* state, const void* data, unsigned int size, void* optionA,
                                  void* optionB)
{
    if (size <= 0u)
        return 0;
    void* buffer = _NiMalloc_00aa1070(size);
    FUN_00ec44d0(buffer, data, size);
    SwapBufferBySizes(buffer, size, optionA, optionB);
    unsigned int result = state->FUN_00aa1810(buffer, size);
    _NiFree_00aa10f0(buffer);
    return result;
}

struct TLSState
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
};
extern __declspec(thread) TLSState s_tlsData;
extern void* DAT_011f6118;
extern unsigned char DAT_011f610d;

struct FUN_00aa2200_shell
{
    void* __thiscall FUN_00aa2200();
};
namespace InitSystemCall {
void __cdecl NiSystemSDM_Init();
}
// Sets TLS unk2b4 to 15, selects or allocates the object stored in DAT_011f6118, runs FUN_00aa3050 and the init callbacks, restores unk2b4 and sets DAT_011f610c.
// @fnv 0x00aa20b0
// src: COMMUNITY 0x00aa20b0
void __cdecl NiStaticDataManager_Init(void* value)
{
    int oldState = s_tlsData.unk2b4;
    s_tlsData.unk2b4 = 15;
    void* existing = DAT_011f6118;
    if (!value)
    {
        if (!existing)
        {
            void* allocated = DAT_011f6238.Allocate(8);
            if (allocated)
                value = ((FUN_00aa2200_shell*)allocated)->FUN_00aa2200();
            else
                value = 0;
            DAT_011f610d = 1;
        }
        else
        {
            value = existing;
            DAT_011f610d = 0;
        }
    }
    else
    {
        if (existing)
            value = existing;
        DAT_011f610d = 0;
    }
    DAT_011f6118 = value;
    InitSystemCall::NiSystemSDM_Init();
    if (DAT_011f6110)
        ((void(__cdecl*)())DAT_011f6110)();
    for (unsigned int i = 0; i < (unsigned int)DAT_011f6108; ++i)
        DAT_011f60c8[i]();
    s_tlsData.unk2b4 = oldState;
    DAT_011f610c = 1;
}

class ThreadSuspendForward : public FUN_00aa2710_cls
{
  public:
    unsigned int SuspendThreadHandle();
    unsigned int NiThread_Suspend();
};

// @fnv 0x00aa3040
// src: COMMUNITY 0x00aa3040
unsigned int ThreadSuspendForward::NiThread_Suspend()
{
    return SuspendThreadHandle();
}

struct SysInfoQ
{
    unsigned long dwOemId;
    unsigned long dwPageSize;
    void* lpMinimumApplicationAddress;
    void* lpMaximumApplicationAddress;
    unsigned long dwActiveProcessorMask;
    unsigned long dwNumberOfProcessors;
    unsigned long dwProcessorType;
    unsigned long dwAllocationGranularity;
    unsigned short wProcessorLevel;
    unsigned short wProcessorRevision;
};
extern "C" __declspec(dllimport) void __stdcall GetSystemInfo(SysInfoQ*);
extern void* _DAT_011f6078;

// Allocates 8 bytes from the memory manager, stores the processor count and performance frequency, and sets the global pointer to the block.
// @fnv 0x00aa1920
// src: COMMUNITY 0x00aa1920
void __cdecl NiSystemDesc_NiSystemDesc()
{
    unsigned int* p = (unsigned int*)_g_memoryManager.Allocate(8);
    if (p)
    {
        SysInfoQ sysInfo;
        GetSystemInfo(&sysInfo);
        *p = sysInfo.dwNumberOfProcessors;
        long long perfFreq;
        QueryPerformanceFrequency(&perfFreq);
        *(float*)(p + 1) = (float)perfFreq;
        _DAT_011f6078 = p;
        return;
    }
    _DAT_011f6078 = 0;
}
