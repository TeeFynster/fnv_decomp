#include "../../../../../../include/hkArray.h"

#include "../../../../../../include/hkpWorld.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkpEntityListener.h"
#include "../../../../../../include/hkpPhantomListener.h"
#include "../../../../../../include/hkpActionListener.h"

// src/havok/physics/dynamics/world/util/hkpworldcallbackutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldcallbackutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" unsigned long _tls_index;
struct AudioTlsState
{
    unsigned unk0;
    unsigned unk4;
    unsigned unk8;
    unsigned unkC;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1C;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2C;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3C;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4C;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5C;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6C;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7C;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8C;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9C;
    unsigned unkA0;
    unsigned unkA4;
    unsigned unkA8;
    unsigned unkAC;
    unsigned unkB0;
    unsigned unkB4;
    unsigned unkB8;
    unsigned unkBC;
    unsigned unkC0;
    unsigned unkC4;
    unsigned unkC8;
    unsigned unkCC;
    unsigned unkD0;
    unsigned unkD4;
    unsigned unkD8;
    unsigned unkDC;
    unsigned unkE0;
    unsigned unkE4;
    unsigned unkE8;
    unsigned unkEC;
    unsigned unkF0;
    unsigned unkF4;
    unsigned unkF8;
    unsigned unkFC;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10C;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11C;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12C;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13C;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14C;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15C;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16C;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17C;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18C;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19C;
    unsigned unk1A0;
    unsigned unk1A4;
    unsigned unk1A8;
    unsigned unk1AC;
    unsigned unk1B0;
    unsigned unk1B4;
    unsigned unk1B8;
    unsigned unk1BC;
    unsigned unk1C0;
    unsigned unk1C4;
    unsigned unk1C8;
    unsigned unk1CC;
    unsigned unk1D0;
    unsigned unk1D4;
    unsigned unk1D8;
    unsigned unk1DC;
    unsigned unk1E0;
    unsigned unk1E4;
    unsigned unk1E8;
    unsigned unk1EC;
    unsigned unk1F0;
    unsigned unk1F4;
    unsigned unk1F8;
    unsigned unk1FC;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20C;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21C;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22C;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23C;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    unsigned unk24C;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25C;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26C;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27C;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28C;
    unsigned unk290;
    unsigned unk294;
    unsigned unk298;
    unsigned unk29C;
    unsigned unk2A0;
    unsigned unk2A4;
    unsigned unk2A8;
    unsigned unk2AC;
    unsigned unk2B0;
    unsigned m_uiMemoryContext;
};
__declspec(thread) AudioTlsState threadData;
struct ScopedContext
{
    unsigned previous;
    __forceinline ScopedContext(unsigned value)
    {
        previous = threadData.m_uiMemoryContext;
        threadData.m_uiMemoryContext = value;
    }
    __forceinline ~ScopedContext()
    {
        threadData.m_uiMemoryContext = previous;
    }
};
struct Metadata
{
    int unk00, unk04, unk08, unk0C, unk10;
    unsigned char flags;
};
struct Reference
{
    int unk00, unk04, unk08;
    Metadata* metadata;
    void FUN_00c905b0();
};
extern void hkpWorld_removePhantomBatch();

__forceinline void RemoveWorldReferences(hkpWorld* world, Reference** references, unsigned count)
{
    union
    {
        void (*address)();
        void (hkpWorld::*method)(Reference**, unsigned);
    } operation;
    operation.address = hkpWorld_removePhantomBatch;
    (world->*operation.method)(references, count);
}
void* FUN_00ec61c0(void*, int, unsigned);
struct Owner
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual hkpWorld* GetWorld();
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    Reference** references;
    unsigned count;
    void ClearReferences();
};
// @fnv 0x00c67bc0
void Owner::ClearReferences()
{
    ScopedContext scope(16);
    if (count > 0)
    {
        if (count >= 200)
            count = 200;
        hkpWorld* world = GetWorld();
        if (world)
        {
            RemoveWorldReferences(world, references, count);
            for (unsigned i = 0; i < count; ++i)
            {
                Reference* reference = references[i];
                if (reference)
                {
                    Metadata* metadata = reference->metadata;
                    if (metadata)
                        metadata->flags &= ~32;
                }
                references[i]->FUN_00c905b0();
            }
            FUN_00ec61c0(references, 0, count * 4);
            count = 0;
        }
    }
}

static __forceinline void D00370Array_removeAtAndCopy(hkArrayBase<void*>& self, int index);

static __forceinline void D00370Array_removeAtAndCopy(hkArrayBase<void*>& self, int index)
{
        self.m_iElementCount--;
        char* dst = (char*)&self.m_data[index];
        const char* src = (const char*)&self.m_data[index + 1];
        int nbytes = (self.m_iElementCount - index) * 4;
        for (int i = 0; i < nbytes; i += 4)
            *(int*)(dst + i) = *(const int*)(src + i);
    }

// Iterates cleanupArray backwards and removes every null element via removeAtAndCopy.
// @fnv 0x00d00370
// src: HAVOK_LIB 0x00d00370
static __declspec(noinline) void worldCallbackUtil_cleanupNullPointers(hkArrayBase<void*>& cleanupArray)
{
    for (int i = cleanupArray.m_iElementCount - 1; i >= 0; i--)
    {
        if (cleanupArray.m_data[i] == 0)
            D00370Array_removeAtAndCopy(cleanupArray, i);
    }
}

// Callers so the file-static helper is emitted with its register calling convention.
void D00370CleanupBoth(hkArrayBase<void*>* a, hkArrayBase<void*>* b)
{
    worldCallbackUtil_cleanupNullPointers(*a);
    worldCallbackUtil_cleanupNullPointers(*b);
}

// RemoveZeroEntries - removes the NULL entries of a small array.

struct FNV_SmallArray_00d00320
{
    int* m_pItems;
    unsigned short m_uiItemCount;
};

// Removes every zero element from the array by shifting later items down and decrementing the count.
// @fnv 0x00d00320
static __declspec(noinline) void RemoveZeroEntries(FNV_SmallArray_00d00320* pArray)
{
    unsigned short nCount = pArray->m_uiItemCount;
    for (int i = (int)nCount - 1; i >= 0; i--)
    {
        if (pArray->m_pItems[i] == 0)
        {
            pArray->m_uiItemCount = (unsigned short)(pArray->m_uiItemCount - 1);
            for (int j = i; j < (int)pArray->m_uiItemCount; j++)
            {
                pArray->m_pItems[j] = pArray->m_pItems[j + 1];
            }
        }
    }
}

void KeepAlive_00d00320(FNV_SmallArray_00d00320* pArray)
{
    RemoveZeroEntries(pArray);
}

extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class hkpAction;
struct Array833
{
    hkpActionListener** data;
    int size;
    int capacity;
};

// src: HAVOK_LIB 0x00d00370
static __declspec(noinline) void worldCallbackUtil_cleanupNullPointers(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(hkpActionListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(hkpActionListener*))
                *(hkpActionListener**)(destination + offset) = *(hkpActionListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream* stream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    hkMonitorStream::TimerCommand* command = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream->m_end.m_storage);
    if (reinterpret_cast<char*>(command) < stream->m_capacityMinus16.m_storage)
    {
        command->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->m_time0 = ticks;
        stream->m_end.m_storage = reinterpret_cast<char*>(command + 1);
    }
}
// Invokes ActionAddedCallback on each non-null hkpActionListener in world->m_kActionListeners, then removes null entries from the array.
// @fnv 0x00d003c0
void __cdecl NotifyActionAdded(hkpWorld* world, hkpAction* action)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = (Array833&)world->m_kActionListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtactAddCb", beginTicks);
            listeners.data[i]->ActionAddedCallback(action);
            TimerEvent833("Et", endTicks);
        }
    }
    worldCallbackUtil_cleanupNullPointers(listeners);
}

namespace fnv_00d00500 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
struct Array833
{
    hkpEntityListener** data;
    int size;
    int capacity;
};

// src: HAVOK_LIB 0x00d00370
static __declspec(noinline) void worldCallbackUtil_cleanupNullPointers(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(hkpEntityListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(hkpEntityListener*))
                *(hkpEntityListener**)(destination + offset) = *(hkpEntityListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream* stream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    hkMonitorStream::TimerCommand* command = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream->m_end.m_storage);
    if (reinterpret_cast<char*>(command) < stream->m_capacityMinus16.m_storage)
    {
        command->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->m_time0 = ticks;
        stream->m_end.m_storage = reinterpret_cast<char*>(command + 1);
    }
}
// Invokes EntityAddedCallback on each non-null hkpEntityListener in the world's listener array, then compacts the array to remove null entries.
// @fnv 0x00d00500
void __cdecl NotifyEntityAdded(hkpWorld* world, hkpEntity* entity)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = (Array833&)world->m_kEntityListenerArray;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtentAddCb", beginTicks);
            listeners.data[i]->EntityAddedCallback(entity);
            TimerEvent833("Et", endTicks);
        }
    }
    worldCallbackUtil_cleanupNullPointers(listeners);
}
}  // namespace fnv_00d00500

namespace fnv_00d006e0 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
struct Array833
{
    hkpEntityListener** data;
    int size;
    int capacity;
};

// src: HAVOK_LIB 0x00d00370
static __declspec(noinline) void worldCallbackUtil_cleanupNullPointers(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(hkpEntityListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(hkpEntityListener*))
                *(hkpEntityListener**)(destination + offset) = *(hkpEntityListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream* stream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    hkMonitorStream::TimerCommand* command = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream->m_end.m_storage);
    if (reinterpret_cast<char*>(command) < stream->m_capacityMinus16.m_storage)
    {
        command->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->m_time0 = ticks;
        stream->m_end.m_storage = reinterpret_cast<char*>(command + 1);
    }
}
// Invokes entitySetMotionTypeCallback on each non-null listener in world->m_kEntityListenerArray, then compacts the listener array via FUN_00d00370.
// @fnv 0x00d006e0
void __cdecl NotifyEntitySetMotionType(hkpWorld* world, hkpEntity* entity)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = (Array833&)world->m_kEntityListenerArray;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtsetMotionTypeCb", beginTicks);
            listeners.data[i]->entitySetMotionTypeCallback(entity);
            TimerEvent833("Et", endTicks);
        }
    }
    worldCallbackUtil_cleanupNullPointers(listeners);
}
}  // namespace fnv_00d006e0

namespace fnv_00d00780 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
struct Array833
{
    hkpPhantomListener** data;
    int size;
    int capacity;
};

// src: HAVOK_LIB 0x00d00370
static __declspec(noinline) void worldCallbackUtil_cleanupNullPointers(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(hkpPhantomListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(hkpPhantomListener*))
                *(hkpPhantomListener**)(destination + offset) = *(hkpPhantomListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream* stream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    hkMonitorStream::TimerCommand* command = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream->m_end.m_storage);
    if (reinterpret_cast<char*>(command) < stream->m_capacityMinus16.m_storage)
    {
        command->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->m_time0 = ticks;
        stream->m_end.m_storage = reinterpret_cast<char*>(command + 1);
    }
}
// Invokes PhantomAddedCallback on each non-null hkpPhantomListener in world->m_kPhantomListeners, then removes null entries via FUN_00d00370.
// @fnv 0x00d00780
void __cdecl NotifyPhantomAdded(hkpWorld* world, hkpPhantom* phantom)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = (Array833&)world->m_kPhantomListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtphntAddCb", beginTicks);
            listeners.data[i]->PhantomAddedCallback(phantom);
            TimerEvent833("Et", endTicks);
        }
    }
    worldCallbackUtil_cleanupNullPointers(listeners);
}
}  // namespace fnv_00d00780

#include <windows.h>

extern DWORD DAT_0126835c;
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

struct ListenerBase
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void OnEvent(void* apParam);
};

struct ListenerList
{
    ListenerBase** m_ppItems;
    int m_iArrayLength;
};


// Iterates the listener list in apOwner in reverse, calling OnEvent on each non-null item with tracing, then calls FUN_00d00370 on the list.
// @fnv 0x00d00bf0
// src: HAVOK_LIB 0x00d00bf0
void __cdecl hkpWorldCallbackUtil_fireConstraintRepaired(hkpWorld* apOwner, void* apParam)
{
    struct State
    {
        volatile DWORD endTick;
        hkArrayBase<void*>* list;
    } state;
    volatile DWORD beginTick;
    state.list =  (hkArrayBase<void*>*)&apOwner->m_kConstraintListeners;
    int i = state.list->m_iElementCount - 1;
    if (i >= 0)
    {
        LPVOID(WINAPI * pfnTls)(DWORD) = TlsGetValue;
        do
        {
            ListenerBase* pItem = (ListenerBase*)state.list->m_data[i];
            if (pItem != 0)
            {
                hkMonitorStream* pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
                hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                if (reinterpret_cast<char*>(pRec) < pBuf->m_capacityMinus16.m_storage)
                {
                    pRec->m_commandAndMonitor = "TtconRepairedCb";
                    _ReadWriteBarrier();
                    beginTick = (DWORD)__rdtsc();
                    pRec->m_time0 = beginTick;
                    pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
                }
                pItem->OnEvent(apParam);
                hkMonitorStream* pBuf2 = (hkMonitorStream*)pfnTls(DAT_0126835c);
                hkMonitorStream::TimerCommand* pRec2 = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf2->m_end.m_storage);
                if (reinterpret_cast<char*>(pRec2) < pBuf2->m_capacityMinus16.m_storage)
                {
                    pRec2->m_commandAndMonitor = "Et";
                    _ReadWriteBarrier();
                    state.endTick = (DWORD)__rdtsc();
                    pRec2->m_time0 = state.endTick;
                    pBuf2->m_end.m_storage = reinterpret_cast<char*>(pRec2 + 1);
                }
            }
        } while (--i >= 0);
    }
    worldCallbackUtil_cleanupNullPointers(*state.list);
}

extern DWORD g_D00CA0TlsIndex;

__forceinline hkMonitorStream& D00CA0GetMonitorStream()
{
    return *(hkMonitorStream*)TlsGetValue(g_D00CA0TlsIndex);
}

__forceinline void D00CA0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream& mStream = D00CA0GetMonitorStream();
    if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_time0 = ticks;
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}

struct D00CA0Listener
{
    virtual void entityCallback(void* entity);
};



// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D00CA0CleanupNullPointers(hkArrayBase<D00CA0Listener*>& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}


extern const char g_D00CA0TimerEntityCb[];
extern const char g_D00CA0TimerEnd[];

// Invokes entityCallback on each non-null listener in the world's entity listener array, then removes null entries.
// @fnv 0x00d00ca0
// src: HAVOK_LIB 0x00d00ca0
void __cdecl hkpWorldCallbackUtil_fireContactPointCallback(hkpWorld* world, void* entity)
{
    hkArrayBase<D00CA0Listener*>& listeners = (hkArrayBase<D00CA0Listener*>&)world->m_kContactListeners;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D00CA0TimerBegin(g_D00CA0TimerEntityCb, beginTicks);
            listeners.m_data[i]->entityCallback(entity);
            D00CA0TimerBegin(g_D00CA0TimerEnd, endTicks);
        }
    }
    D00CA0CleanupNullPointers(listeners);
}

namespace fnv_00d00d40 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class CollisionEvent;
class NewCollisionListener
{
  public:
    virtual ~NewCollisionListener();
    virtual void newCollisionCallback(CollisionEvent*);
};
struct Array833
{
    NewCollisionListener** data;
    int size;
    int capacity;
};

// src: HAVOK_LIB 0x00d00370
static __declspec(noinline) void worldCallbackUtil_cleanupNullPointers(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(NewCollisionListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(NewCollisionListener*))
                *(NewCollisionListener**)(destination + offset) = *(NewCollisionListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream* stream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    hkMonitorStream::TimerCommand* command = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream->m_end.m_storage);
    if (reinterpret_cast<char*>(command) < stream->m_capacityMinus16.m_storage)
    {
        command->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->m_time0 = ticks;
        stream->m_end.m_storage = reinterpret_cast<char*>(command + 1);
    }
}
// Invokes newCollisionCallback on each valid collision listener in world->m_kContactListeners, then compacts the array by removing null entries.
// @fnv 0x00d00d40
void __cdecl DispatchCollisionEvents(hkpWorld* world, CollisionEvent* simulation)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = (Array833&)world->m_kContactListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtNewCollCb", beginTicks);
            listeners.data[i]->newCollisionCallback(simulation);
            TimerEvent833("Et", endTicks);
        }
    }
    worldCallbackUtil_cleanupNullPointers(listeners);
}
}  // namespace fnv_00d00d40

extern DWORD g_D00DE0TlsIndex;

__forceinline hkMonitorStream& D00DE0GetMonitorStream()
{
    return *(hkMonitorStream*)TlsGetValue(g_D00DE0TlsIndex);
}

__forceinline void D00DE0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream& mStream = D00DE0GetMonitorStream();
    if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_time0 = ticks;
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}

struct D00DE0Listener
{
    virtual void unk00();
    virtual void unk04();
    virtual void entityCallback(void* entity);
};



// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D00DE0CleanupNullPointers(hkArrayBase<D00DE0Listener*>& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}


extern const char g_D00DE0TimerEntityCb[];
extern const char g_D00DE0TimerEnd[];

// Invokes entityCallback on each non-null listener in the world's entity listener array, then removes null entries.
// @fnv 0x00d00de0
// src: HAVOK_LIB 0x00d00de0
void __cdecl hkpWorldCallbackUtil_fireContactConstraintRemovedCallback(hkpWorld* world, void* entity)
{
    hkArrayBase<D00DE0Listener*>& listeners = (hkArrayBase<D00DE0Listener*>&)world->m_kContactListeners;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D00DE0TimerBegin(g_D00DE0TimerEntityCb, beginTicks);
            listeners.m_data[i]->entityCallback(entity);
            D00DE0TimerBegin(g_D00DE0TimerEnd, endTicks);
        }
    }
    D00DE0CleanupNullPointers(listeners);
}

extern DWORD g_D00E80TlsIndex;

__forceinline hkMonitorStream& D00E80GetMonitorStream()
{
    return *(hkMonitorStream*)TlsGetValue(g_D00E80TlsIndex);
}

__forceinline void D00E80TimerBegin(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream& mStream = D00E80GetMonitorStream();
    if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_time0 = ticks;
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}


struct D00E80Listener
{
    virtual void unk00();
    virtual void actionCallback(hkpWorld* pkWorld);
};



// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D00E80CleanupNullPointers(hkArrayBase<D00E80Listener*>& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}

struct D00E80TickPair
{
    volatile unsigned int m_uiBegin;
    volatile unsigned int m_uiEndTick;
};


extern const char g_D00E80TimerActionCb[];
extern const char g_D00E80TimerEnd[];

// Iterates the world's entity listener array in reverse, calling each non-null listener's actionCallback with the world, then compacts out null entries.
// @fnv 0x00d00e80
// src: HAVOK_LIB 0x00d00e80
void __cdecl hkpWorldCallbackUtil_fireWorldDeleted(hkpWorld* world)
{
    D00E80TickPair kTicks;
    hkArrayBase<D00E80Listener*>& listeners = (hkArrayBase<D00E80Listener*>&)world->m_kWorldDeletionListeners;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            D00E80TimerBegin(g_D00E80TimerActionCb, kTicks.m_uiBegin);
            listeners.m_data[i]->actionCallback(world);
            D00E80TimerBegin(g_D00E80TimerEnd, kTicks.m_uiEndTick);
        }
    }
    D00E80CleanupNullPointers(listeners);
}

class hkpPhantom;
namespace fnv_00d00f30 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class WorldDeletionListener
{
  public:
    virtual ~WorldDeletionListener();
    virtual void unknown04();
    virtual void WorldDeletedCallback(void*);
};
struct Array833
{
    WorldDeletionListener** data;
    int size;
    int capacity;
};

// src: HAVOK_LIB 0x00d00370
static __declspec(noinline) void worldCallbackUtil_cleanupNullPointers(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(WorldDeletionListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(WorldDeletionListener*))
                *(WorldDeletionListener**)(destination + offset) = *(WorldDeletionListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream* stream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    hkMonitorStream::TimerCommand* command = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream->m_end.m_storage);
    if (reinterpret_cast<char*>(command) < stream->m_capacityMinus16.m_storage)
    {
        command->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->m_time0 = ticks;
        stream->m_end.m_storage = reinterpret_cast<char*>(command + 1);
    }
}
// Invokes WorldDeletedCallback on each non-null entry in world->m_kWorldDeletionListeners, then compacts the array via FUN_00d00370.
// @fnv 0x00d00f30
void __cdecl NotifyWorldDeleted(hkpWorld* world)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = (Array833&)world->m_kWorldDeletionListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtworldDelCb", beginTicks);
            listeners.data[i]->WorldDeletedCallback(world);
            TimerEvent833("Et", endTicks);
        }
    }
    worldCallbackUtil_cleanupNullPointers(listeners);
}
}  // namespace fnv_00d00f30

class hkpPhantom;
namespace fnv_00d01380 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class PostSimulationListener
{
  public:
    virtual ~PostSimulationListener();
    virtual void postSimulationCallback(void*);
};
struct Array833
{
    PostSimulationListener** data;
    int size;
    int capacity;
};

// src: HAVOK_LIB 0x00d00370
static __declspec(noinline) void worldCallbackUtil_cleanupNullPointers(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(PostSimulationListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(PostSimulationListener*))
                *(PostSimulationListener**)(destination + offset) = *(PostSimulationListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream* stream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    hkMonitorStream::TimerCommand* command = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream->m_end.m_storage);
    if (reinterpret_cast<char*>(command) < stream->m_capacityMinus16.m_storage)
    {
        command->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->m_time0 = ticks;
        stream->m_end.m_storage = reinterpret_cast<char*>(command + 1);
    }
}
// Iterates postSimulationListeners, calling postSimulationCallback on each non-null entry, then compacts the array via FUN_00d00370.
// @fnv 0x00d01380
// src: HAVOK_LIB 0x00d01380
void __cdecl hkpWorldCallbackUtil_firePostSimulationCallback(hkpWorld* world)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = (Array833&)world->m_kWorldPostSimulationListeners;
    int previousSize = listeners.size;
    int i = previousSize - 1;
    for (; i >= 0; --i)
    {
        if (previousSize > listeners.size)
        {

            i += listeners.size - previousSize;
            previousSize = listeners.size;
        }
        if (listeners.data[i])
        {
            TimerEvent833("TtpostSimCb", beginTicks);
            listeners.data[i]->postSimulationCallback(world);
            TimerEvent833("Et", endTicks);
        }
    }
    worldCallbackUtil_cleanupNullPointers(listeners);
}
}  // namespace fnv_00d01380

class hkpPhantom;
namespace fnv_00d01440 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class PostIntegrationListener
{
  public:
    virtual ~PostIntegrationListener();
    virtual void postIntegrationCallback(void*, void*);
};
struct Array833
{
    PostIntegrationListener** data;
    int size;
    int capacity;
};

// src: HAVOK_LIB 0x00d00370
static __declspec(noinline) void worldCallbackUtil_cleanupNullPointers(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(PostIntegrationListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(PostIntegrationListener*))
                *(PostIntegrationListener**)(destination + offset) =
                    *(PostIntegrationListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream* stream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    hkMonitorStream::TimerCommand* command = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream->m_end.m_storage);
    if (reinterpret_cast<char*>(command) < stream->m_capacityMinus16.m_storage)
    {
        command->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->m_time0 = ticks;
        stream->m_end.m_storage = reinterpret_cast<char*>(command + 1);
    }
}
// Iterates the world's postIntegrationListeners, calling each non-null listener's postIntegrationCallback with world and stepInfo, then compacts the array.
// @fnv 0x00d01440
// src: HAVOK_LIB 0x00d01440
void __cdecl hkpWorldCallbackUtil_firePostIntegrateCallback(hkpWorld* world, void* stepInfo)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = (Array833&)world->m_kWorldPostIntegrateListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtpostIntCb", beginTicks);
            listeners.data[i]->postIntegrationCallback(world, stepInfo);
            TimerEvent833("Et", endTicks);
        }
    }
    worldCallbackUtil_cleanupNullPointers(listeners);
}
}  // namespace fnv_00d01440

extern DWORD g_D014F0TlsIndex;

__forceinline hkMonitorStream& D014F0GetMonitorStream()
{
    return *(hkMonitorStream*)TlsGetValue(g_D014F0TlsIndex);
}

__forceinline void D014F0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream& mStream = D014F0GetMonitorStream();
    if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_time0 = ticks;
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}


struct D014F0Listener
{
    virtual void unk00();
    virtual void collisionAddedCallback(hkpWorld* pkWorld, void* pvEvent);
};



// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D014F0CleanupNullPointers(hkArrayBase<D014F0Listener*>& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}

struct D014F0TickPair
{
    volatile unsigned int m_uiBegin;
    volatile unsigned int m_uiEndTick;
};


extern const char g_D014F0TimerCollisionAddedCb[];
extern const char g_D014F0TimerEnd[];

// Iterates the world's entity listener array, invoking collisionAddedCallback on each non-null listener with timing markers, then removes null entries.
// @fnv 0x00d014f0
// src: HAVOK_LIB 0x00d014f0
void __cdecl hkpWorldCallbackUtil_firePostCollideCallback(hkpWorld* world, void* pvEvent)
{
    D014F0TickPair kTicks;
    hkArrayBase<D014F0Listener*>& listeners = (hkArrayBase<D014F0Listener*>&)world->m_kWorldPostCollideListeners;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            D014F0TimerBegin(g_D014F0TimerCollisionAddedCb, kTicks.m_uiBegin);
            listeners.m_data[i]->collisionAddedCallback(world, pvEvent);
            D014F0TimerBegin(g_D014F0TimerEnd, kTicks.m_uiEndTick);
        }
    }
    D014F0CleanupNullPointers(listeners);
}

extern DWORD g_D015A0TlsIndex;

__forceinline hkMonitorStream& D015A0GetMonitorStream()
{
    return *(hkMonitorStream*)TlsGetValue(g_D015A0TlsIndex);
}

__forceinline void D015A0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream& mStream = D015A0GetMonitorStream();
    if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_time0 = ticks;
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}

struct D015A0Listener
{
    virtual void unk00();
    virtual void contactCallback(void* pkCurrentObject, void* pkSecond);
};



// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D015A0CleanupNullPointers(hkArrayBase<D015A0Listener*>& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}


extern const char g_D015A0TimerContactCb[];
extern const char g_D015A0TimerEnd[];

// Invokes contactCallback on each non-null listener in world->m_kIslandPostIntegrateListeners, then removes null entries from the array.
// @fnv 0x00d015a0
// src: HAVOK_LIB 0x00d015a0
void __cdecl hkpWorldCallbackUtil_fireIslandPostIntegrateCallback(hkpWorld* world, void* apFirst, void* pkSecond)
{
    hkArrayBase<D015A0Listener*>& listeners = (hkArrayBase<D015A0Listener*>&)world->m_kIslandPostIntegrateListeners;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D015A0TimerBegin(g_D015A0TimerContactCb, beginTicks);
            listeners.m_data[i]->contactCallback(apFirst, pkSecond);
            D015A0TimerBegin(g_D015A0TimerEnd, endTicks);
        }
    }
    D015A0CleanupNullPointers(listeners);
}

extern DWORD g_D01650TlsIndex;

__forceinline hkMonitorStream& D01650GetMonitorStream()
{
    return *(hkMonitorStream*)TlsGetValue(g_D01650TlsIndex);
}

__forceinline void D01650TimerBegin(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream& mStream = D01650GetMonitorStream();
    if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_time0 = ticks;
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}

struct D01650Listener
{
    virtual void unk00();
    virtual void collisionAddedCallback(void* pvEvent, void* pvContext);
};



// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D01650CleanupNullPointers(hkArrayBase<D01650Listener*>& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}


extern const char g_D01650TimerCollisionAddedCb[];
extern const char g_D01650TimerEnd[];

// Invokes collisionAddedCallback on each non-null listener in the array, then removes null entries.
// @fnv 0x00d01650
// src: HAVOK_LIB 0x00d01650
void __cdecl hkpWorldCallbackUtil_fireIslandPostCollideCallback(hkpWorld* world, void* pvEvent, void* pvContext)
{
    hkArrayBase<D01650Listener*>& listeners = (hkArrayBase<D01650Listener*>&)world->m_kIslandPostCollideListeners;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D01650TimerBegin(g_D01650TimerCollisionAddedCb, beginTicks);
            listeners.m_data[i]->collisionAddedCallback(pvEvent, pvContext);
            D01650TimerBegin(g_D01650TimerEnd, endTicks);
        }
    }
    D01650CleanupNullPointers(listeners);
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;

struct Listener
{
    virtual void vfunc0();
    virtual void vfunc1(void* a1, void* a2);
};

struct ListenerArray
{
    Listener** m_data;
    int m_iElementCount;
    int m_pRayCursor;
};


// src: HAVOK_LIB 0x00d00370
__declspec(noinline) static void worldCallbackUtil_cleanupNullPointers(ListenerArray* arr)
{
    for (int i = arr->m_iElementCount - 1; i >= 0; --i)
    {
        if (!arr->m_data[i])
        {
            arr->m_iElementCount--;
            int count = arr->m_iElementCount - i;
            if (count > 0)
            {
                memmove(&arr->m_data[i], &arr->m_data[i + 1], count * sizeof(Listener*));
            }
        }
    }
}

static __forceinline void writeTimestamp(char* cur, const char* tag, volatile unsigned int& t)
{
    *(const char**)cur = tag;
    _ReadWriteBarrier();
    t = (unsigned int)__rdtsc();
    *(unsigned int*)(cur + 4) = t;
}

// Iterates hkpWorld listener array, writes start/end timestamps to TLS buffer, invokes each listener, then compacts the array.
// @fnv 0x00d01700
// src: HAVOK_LIB 0x00d01700
void __cdecl hkpWorldCallbackUtil_fireContactImpulseLimitBreached(hkpWorld* world, void* a1, void* a2)
{
    volatile unsigned int uiStartTsc;
    volatile unsigned int t1;
    ListenerArray* arr = (ListenerArray*)&world->m_kContactImpulseLimitBreachedListeners;
    for (int i = arr->m_iElementCount - 1; i >= 0; --i)
    {
        if (arr->m_data[i])
        {
            hkMonitorStream* ms = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
            char* cur = ms->m_end.m_storage;
            if (cur < ms->m_capacityMinus16.m_storage)
            {
                writeTimestamp(cur, "TtimpLimitCb", uiStartTsc);
                ms->m_end.m_storage = cur + 12;
            }
            arr->m_data[i]->vfunc1(a1, a2);
            ms = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
            cur = ms->m_end.m_storage;
            if (cur < ms->m_capacityMinus16.m_storage)
            {
                writeTimestamp(cur, "Et", t1);
                ms->m_end.m_storage = cur + 12;
            }
        }
    }
    worldCallbackUtil_cleanupNullPointers(arr);
}

extern DWORD g_D017B0TlsIndex;

__forceinline hkMonitorStream& D017B0GetMonitorStream()
{
    return *(hkMonitorStream*)TlsGetValue(g_D017B0TlsIndex);
}

__forceinline void D017B0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream& mStream = D017B0GetMonitorStream();
    if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_time0 = ticks;
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}

struct D017B0Listener
{
    virtual void unk00();
    virtual void unk04();
    virtual void EntityRemovedCallback(void* entity);
};



// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D017B0CleanupNullPointers(hkArrayBase<D017B0Listener*>& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}


extern const char g_D017B0TimerEntityRemovedCb[];
extern const char g_D017B0TimerEnd[];

// Invokes EntityRemovedCallback on each non-null listener in the world's entity listener array, then removes null entries.
// @fnv 0x00d017b0
void __cdecl NotifyEntityRemoved(hkpWorld* world, void* entity)
{
    hkArrayBase<D017B0Listener*>& listeners = (hkArrayBase<D017B0Listener*>&)world->m_kWorldPostSimulationListeners;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D017B0TimerBegin(g_D017B0TimerEntityRemovedCb, beginTicks);
            listeners.m_data[i]->EntityRemovedCallback(entity);
            D017B0TimerBegin(g_D017B0TimerEnd, endTicks);
        }
    }
    D017B0CleanupNullPointers(listeners);
}

extern DWORD g_D019B0TlsIndex;

__forceinline hkMonitorStream& D019B0GetMonitorStream()
{
    return *(hkMonitorStream*)TlsGetValue(g_D019B0TlsIndex);
}

__forceinline void D019B0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream& mStream = D019B0GetMonitorStream();
    if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_time0 = ticks;
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}

struct D019B0Listener
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void shapeSetCallback(void* entity);
};



// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D019B0CleanupNullPointers(hkArrayBase<D019B0Listener*>& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}


extern const char g_D019B0TimerSetShapeCb[];
extern const char g_D019B0TimerEnd[];

struct D019B0Event
{
    int unk00;
    int unk04;
    int m_result;
};

// Invokes shapeSetCallback on each non-null entity listener in the world's listener array, then removes any null entries.
// @fnv 0x00d019b0
void __cdecl NotifyShapeSetListeners(hkpWorld* world, D019B0Event* event)
{
    event->m_result = 0;
    hkArrayBase<D019B0Listener*>& listeners = (hkArrayBase<D019B0Listener*>&)world->m_kContactListeners;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D019B0TimerBegin(g_D019B0TimerSetShapeCb, beginTicks);
            listeners.m_data[i]->shapeSetCallback(event);
            D019B0TimerBegin(g_D019B0TimerEnd, endTicks);
        }
    }
    D019B0CleanupNullPointers(listeners);
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern char DAT_010cca74[];
extern char DAT_010c41f8[];
static inline void TimerWriteV(const char* name, volatile unsigned int& t)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)s->m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        h->m_time0 = t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}
struct ActionListener
{
    virtual void v00();
    virtual void v04();
    virtual void ActionRemovedCallback(void* action);
};
// Iterates world->m_kActionListeners in reverse, calling ActionRemovedCallback on each non-null listener, then calls FUN_00d00370 on the array.
// @fnv 0x00d00460
void __cdecl NotifyActionRemoved(hkpWorld* world, void* action)
{
    hkArrayBase<void*>& listen = (hkArrayBase<void*>&)world->m_kActionListeners;
    for (int i = listen.m_iElementCount - 1; i >= 0; i--)
    {
        if (listen.m_data[i] != 0)
        {
            volatile unsigned int t1;
            volatile unsigned int t2;
            TimerWriteV(DAT_010cca74, t1);
            ((ActionListener*)listen.m_data[i])->ActionRemovedCallback(action);
            TimerWriteV(DAT_010c41f8, t2);
        }
    }
    worldCallbackUtil_cleanupNullPointers(listen);
}

extern DWORD g_D005A0TlsIndex;

__forceinline hkMonitorStream& D005A0GetMonitorStream()
{
    return *(hkMonitorStream*)TlsGetValue(g_D005A0TlsIndex);
}

__forceinline void D005A0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream& mStream = D005A0GetMonitorStream();
    if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_time0 = ticks;
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}



// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D005A0CleanupNullPointers(hkArrayBase<hkpEntityListener*>& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}


extern const char g_D005A0TimerEntityAddedCb[];
extern const char g_D005A0TimerEnd[];

// Iterates the world's entity listener array, calling EntityRemovedCallback on each non-null listener, then removes null entries.
// @fnv 0x00d005a0
// src: HAVOK_LIB 0x00d005a0
void __cdecl hkpWorldCallbackUtil_fireEntityRemoved(hkpWorld* world, void* entity)
{
    hkArrayBase<hkpEntityListener*>& listeners = (hkArrayBase<hkpEntityListener*>&)world->m_kEntityListenerArray;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D005A0TimerBegin(g_D005A0TimerEntityAddedCb, beginTicks);
            listeners.m_data[i]->EntityRemovedCallback((hkpEntity*)entity);
            D005A0TimerBegin(g_D005A0TimerEnd, endTicks);
        }
    }
    D005A0CleanupNullPointers(listeners);
}

extern DWORD g_D00640TlsIndex;

__forceinline hkMonitorStream& D00640GetMonitorStream()
{
    return *(hkMonitorStream*)TlsGetValue(g_D00640TlsIndex);
}

__forceinline void D00640TimerBegin(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream& mStream = D00640GetMonitorStream();
    if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_time0 = ticks;
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}



// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D00640CleanupNullPointers(hkArrayBase<hkpEntityListener*>& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}


extern const char g_D00640TimerSetShapeCb[];
extern const char g_D00640TimerEnd[];

// Iterates the entity listener array, calls shapeSetCallback on each non-null listener, then compacts out null entries.
// @fnv 0x00d00640
void __cdecl NotifyShapeSet(hkpWorld* world, void* entity)
{
    hkArrayBase<hkpEntityListener*>& listeners = (hkArrayBase<hkpEntityListener*>&)world->m_kEntityListenerArray;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D00640TimerBegin(g_D00640TimerSetShapeCb, beginTicks);
            listeners.m_data[i]->EntityShapeSetCallback((hkpEntity*)entity);
            D00640TimerBegin(g_D00640TimerEnd, endTicks);
        }
    }
    D00640CleanupNullPointers(listeners);
}

extern DWORD g_D00820TlsIndex;

__forceinline hkMonitorStream& D00820GetMonitorStream()
{
    return *(hkMonitorStream*)TlsGetValue(g_D00820TlsIndex);
}

__forceinline void D00820TimerBegin(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream& mStream = D00820GetMonitorStream();
    if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_time0 = ticks;
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}



// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D00820CleanupNullPointers(hkArrayBase<hkpPhantomListener*>& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}


extern const char g_D00820TimerSetShapeCb[];
extern const char g_D00820TimerEnd[];

// Iterates the world's entity listener array, calls entityCallback on each non-null listener with the entity, then removes null entries.
// @fnv 0x00d00820
// src: HAVOK_LIB 0x00d00820
void __cdecl hkpWorldCallbackUtil_firePhantomRemoved(hkpWorld* world, void* entity)
{
    hkArrayBase<hkpPhantomListener*>& listeners = (hkArrayBase<hkpPhantomListener*>&)world->m_kPhantomListeners;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D00820TimerBegin(g_D00820TimerSetShapeCb, beginTicks);
            listeners.m_data[i]->PhantomRemovedCallback((hkpPhantom*)entity);
            D00820TimerBegin(g_D00820TimerEnd, endTicks);
        }
    }
    D00820CleanupNullPointers(listeners);
}

extern DWORD g_D008C0TlsIndex;

__forceinline hkMonitorStream& D008C0GetMonitorStream()
{
    return *(hkMonitorStream*)TlsGetValue(g_D008C0TlsIndex);
}

__forceinline void D008C0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream& mStream = D008C0GetMonitorStream();
    if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_time0 = ticks;
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}



// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D008C0CleanupNullPointers(hkArrayBase<hkpPhantomListener*>& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}


extern const char g_D008C0TimerSetShapeCb[];
extern const char g_D008C0TimerEnd[];

// Iterates the world's entity listener array in reverse, invoking shapeSetCallback on each non-null listener, then compacts the array to remove null entries.
// @fnv 0x00d008c0
// src: HAVOK_LIB 0x00d008c0
void __cdecl hkpWorldCallbackUtil_firePhantomShapeSet(hkpWorld* world, void* entity)
{
    hkArrayBase<hkpPhantomListener*>& listeners = (hkArrayBase<hkpPhantomListener*>&)world->m_kPhantomListeners;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D008C0TimerBegin(g_D008C0TimerSetShapeCb, beginTicks);
            listeners.m_data[i]->phantomShapeSetCallback((hkpPhantom*)entity);
            D008C0TimerBegin(g_D008C0TimerEnd, endTicks);
        }
    }
    D008C0CleanupNullPointers(listeners);
}

extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
unsigned __int64 __cdecl __rdtsc(void);
class ProfTarget
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(unsigned a1);
    virtual void v3();
    virtual void v4();
};
__forceinline void ProfMark(const char* name, volatile DWORD& outTick)
{
    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        outTick = (DWORD)__rdtsc();
        pRec->m_time0 = outTick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }
}
// Iterates m_kTargets in reverse, calling v2 on each non-null ProfTarget with a2, then calls FUN_00d00370 on the array.
// @fnv 0x00d00a00
void __cdecl NotifyTargets(hkpWorld* pOwner, DWORD a2)
{
    volatile DWORD beginTick, endTick;
    hkArrayBase<void*>& targets = (hkArrayBase<void*>&)pOwner->m_kConstraintListeners;
    int i = (int)targets.m_iElementCount - 1;
    if (i >= 0)
    {
        do
        {
            if (((ProfTarget**)targets.m_data)[i] != 0)
            {
                ProfMark("TtconRemCb", beginTick);
                ((ProfTarget**)targets.m_data)[i]->v2(a2);
                ProfMark("Et", endTick);
            }
        } while (--i >= 0);
    }
    worldCallbackUtil_cleanupNullPointers(targets);
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern char DAT_010ccab0[];
extern char DAT_010c41f8[];
struct Phantom
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(int a);
};
// Iterates owner's m_kListeners in reverse, calling v10 with a2 on each non-null listener between timer samples, then calls FUN_00d00370 on the array.
// @fnv 0x00d00aa0
// src: HAVOK_LIB 0x00d00aa0
void __cdecl hkpWorldCallbackUtil_fireConstraintViolated(hkpWorld* owner, int a2)
{
    hkArrayBase<void*>& listen = (hkArrayBase<void*>&)owner->m_kConstraintListeners;
    for (int i = listen.m_iElementCount - 1; i >= 0; i--)
    {
        if (listen.m_data[i] != 0)
        {
            volatile unsigned int t1;
            volatile unsigned int t2;
            TimerWriteV(DAT_010ccab0, t1);
            ((Phantom*)listen.m_data[i])->v10(a2);
            TimerWriteV(DAT_010c41f8, t2);
        }
    }
    worldCallbackUtil_cleanupNullPointers(listen);
}

extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned long DAT_0126835c;
extern "C" char str_010ccaf8;
extern "C" char str_010ccaec;
extern "C" char str_010c41f8;
struct Scene;
struct Entity;
struct Callback
{
    virtual void unused();
    virtual void invoke(Scene*);
    virtual void execute(Entity*);
};
struct CallbackList
{
    Callback** slots;
    unsigned short count;
};
struct Entity
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    CallbackList* field214;
};
struct Scene
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    Entity** field48;
    int field4c;
};
static __declspec(noinline) void RemoveZeroEntries(CallbackList* list)
{
    for (int i = (int)list->count - 1; i >= 0; --i)
    {
        if (!list->slots[i])
        {
            list->count--;
            for (int k = i; k < (int)list->count; ++k)
            {
                list->slots[k] = list->slots[k + 1];
            }
        }
    }
}
// Calls game->m_kIslandActivationListeners callbacks with scene, then each scene entity's callbacks, bracketed by a field94 inc/dec; at zero may call FUN_00c91120 or FUN_00c91140.
// @fnv 0x00d00fe0
void __cdecl ProcessSceneCallbacks(hkpWorld* game, Scene* scene)
{
    struct
    {
        volatile unsigned int tick1;
        volatile unsigned int tick2;
    } timer;
    ++game->m_iCriticalOperationsLockCount;
    _ReadWriteBarrier();
    int i = game->m_kIslandActivationListeners.m_iElementCount - 1;
    hkArrayBase<void*>* pSlots = (hkArrayBase<void*>*)&game->m_kIslandActivationListeners;
    for (; i >= 0; --i)
    {
        if (pSlots->m_data[i])
        {
            {
                hkMonitorStream* log = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
                unsigned int* current = (unsigned int*)log->m_end.m_storage;
                if (current < (unsigned int*)log->m_capacityMinus16.m_storage)
                {
                    current[0] = (unsigned int)&str_010ccaf8;
                    _ReadWriteBarrier();
                    timer.tick1 = (unsigned int)__rdtsc();
                    current[1] = timer.tick1;
                    log->m_end.m_storage = (char*)(current + 3);
                }
            }
            ((Callback*)pSlots->m_data[i])->invoke(scene);
            {
                hkMonitorStream* log = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
                unsigned int* current = (unsigned int*)log->m_end.m_storage;
                if (current < (unsigned int*)log->m_capacityMinus16.m_storage)
                {
                    current[0] = (unsigned int)&str_010c41f8;
                    _ReadWriteBarrier();
                    timer.tick2 = (unsigned int)__rdtsc();
                    current[1] = timer.tick2;
                    log->m_end.m_storage = (char*)(current + 3);
                }
            }
        }
    }
    worldCallbackUtil_cleanupNullPointers(*pSlots);
    for (int i = 0; i < scene->field4c; ++i)
    {
        Entity* ent = scene->field48[i];
        if (ent->field214)
        {
            CallbackList* callbacks = ent->field214;
            for (int j = (int)callbacks->count - 1; j >= 0; --j)
            {
                if (callbacks->slots[j])
                {
                    {
                        hkMonitorStream* log = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
                        unsigned int* current = (unsigned int*)log->m_end.m_storage;
                        if (current < (unsigned int*)log->m_capacityMinus16.m_storage)
                        {
                            current[0] = (unsigned int)&str_010ccaec;
                            _ReadWriteBarrier();
                            timer.tick2 = (unsigned int)__rdtsc();
                            current[1] = timer.tick2;
                            log->m_end.m_storage = (char*)(current + 3);
                        }
                    }
                    callbacks->slots[j]->execute(scene->field48[i]);
                    {
                        hkMonitorStream* log = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
                        unsigned int* current = (unsigned int*)log->m_end.m_storage;
                        if (current < (unsigned int*)log->m_capacityMinus16.m_storage)
                        {
                            current[0] = (unsigned int)&str_010c41f8;
                            _ReadWriteBarrier();
                            timer.tick1 = (unsigned int)__rdtsc();
                            current[1] = timer.tick1;
                            log->m_end.m_storage = (char*)(current + 3);
                        }
                    }
                }
            }
            RemoveZeroEntries(callbacks);
        }
    }
    if (--game->m_iCriticalOperationsLockCount == 0 && !game->m_bBlockExecutingPendingOperations)
    {
        if (game->m_iPendingOperationCount)
            game->FUN_00c91120();
        if (game->m_iPendingOperationQueueCount == 1 && game->m_iQueuedOperationCount)
            game->UpdateFields_00c91140();
    }
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern char DAT_010cca50[];
extern char DAT_010c41f8[];
struct ContactListener
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void HandleContactEvent(void* event);
};
struct RemovedEvent
{
    int m_00, m_04, m_08, m_0c;
    void* m_iUnknownValue;
};
// Iterates world->m_kContactListeners in reverse, calling HandleContactEvent(&event) on each non-null listener between timer samples, then calls FUN_00d00370.
// @fnv 0x00d01900
// src: HAVOK_LIB 0x00d01900
void __cdecl hkpWorldCallbackUtil_fireContactPointRemoved(hkpWorld* world, RemovedEvent& event)
{
    hkArrayBase<void*>& listen = (hkArrayBase<void*>&)world->m_kContactListeners;
    event.m_iUnknownValue = 0;
    for (int i = listen.m_iElementCount - 1; i >= 0; i--)
    {
        if (listen.m_data[i] != 0)
        {
            volatile unsigned int t1;
            volatile unsigned int t2;
            TimerWriteV(DAT_010cca50, t1);
            ((ContactListener*)listen.m_data[i])->HandleContactEvent(&event);
            TimerWriteV(DAT_010c41f8, t2);
        }
    }
    worldCallbackUtil_cleanupNullPointers(listen);
}

extern void*(__stdcall* DAT_00fdf044)(unsigned long);
class ListenerObjQ
{
  public:
    virtual void v00(void);
    virtual void v01(void);
    virtual void v02(void);
    virtual void v03(void);
    virtual void v04(void);
    virtual void v05(unsigned long a1);
};
struct ListenerArrayQ
{
    ListenerObjQ** m_ppItems;
    unsigned long m_uiItemCount;
};
// Iterates pOwner's listener array, profiling each call to v05(a2), then calls FUN_00d00370 on the array.
// @fnv 0x00d00b40
// src: HAVOK_LIB 0x00d00b40
void __cdecl hkpWorldCallbackUtil_fireConstraintBroken(hkpWorld* pOwner, unsigned long a2)
{
    volatile unsigned long tick1;
    struct ProfileState
    {
        volatile unsigned long tick;
        ListenerArrayQ* arr;
    };
    ProfileState state;
    state.arr =  (ListenerArrayQ*)&pOwner->m_kConstraintListeners;
    int i = (int)state.arr->m_uiItemCount - 1;
    if (i >= 0)
    {
        void*(__stdcall * getBuf)(unsigned long) = DAT_00fdf044;
        do
        {
            ListenerObjQ* pItem = state.arr->m_ppItems[i];
            if (pItem != 0)
            {
                hkMonitorStream* pBuf = (hkMonitorStream*)getBuf(DAT_0126835c);
                if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
                {
                    hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                    pRec->m_commandAndMonitor = "TtconBrokenCb";
                    _ReadWriteBarrier();
                    tick1 = (unsigned long)__rdtsc();
                    pRec->m_time0 = tick1;
                    pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
                }

                pItem->v05(a2);

                pBuf = (hkMonitorStream*)getBuf(DAT_0126835c);
                if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
                {
                    hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                    pRec->m_commandAndMonitor = "Et";
                    _ReadWriteBarrier();
                    state.tick = (unsigned long)__rdtsc();
                    pRec->m_time0 = state.tick;
                    pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
                }
            }
            i--;
        } while (i >= 0);
    }
    worldCallbackUtil_cleanupNullPointers(*(hkArrayBase<void*>*)state.arr);
}

// Based on an unverified 2026-10-22 contribution.
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
extern LPVOID(WINAPI* DAT_00fdf044)(DWORD);
unsigned __int64 __cdecl __rdtsc(void);
struct S00d01850_Out
{
    int unk00, unk04, unk08;
    DWORD unk0C;
    DWORD m_i10;
};
class S00d01850_Item
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vtbl10(S00d01850_Out*);
    virtual void v5();
};
struct S00d01850_ItemList
{
    S00d01850_Item** m_ppItems;
    int m_iArrayLength;
};
// Zeroes pOut->unk0C, calls vtbl10(pOut) on each non-null list item from the end with profiler records, then calls FUN_00d00370 on the list.
// @fnv 0x00d01850
// src: HAVOK_LIB 0x00d01850
void __cdecl hkpWorldCallbackUtil_fireContactPointAdded(hkpWorld* pOwner, S00d01850_Out* pOut)
{
    volatile DWORD t1;
    volatile DWORD t2;
    volatile DWORD& rT2 = t2;
    hkArrayBase<void*>* pCallbacks = (hkArrayBase<void*>*)&pOwner->m_kContactListeners;
    pOut->unk0C = 0;
    int i = pCallbacks->m_iElementCount - 1;
    if (i >= 0)
    {
        LPVOID(WINAPI * pfnTls)(DWORD) = DAT_00fdf044;
        for (; i >= 0; --i)
        {
            if (pCallbacks->m_data[i] != 0)
            {
                hkMonitorStream* pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
                if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
                {
                    hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                    pRec->m_commandAndMonitor = "TtcpAddCb";
                    _ReadWriteBarrier();
                    t1 = (DWORD)__rdtsc();
                    pRec->m_time0 = t1;
                    pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
                }
                ((S00d01850_Item*)pCallbacks->m_data[i])->vtbl10(pOut);
                hkMonitorStream* pBuf2 = (hkMonitorStream*)pfnTls(DAT_0126835c);
                if (pBuf2->m_end.m_storage < pBuf2->m_capacityMinus16.m_storage)
                {
                    hkMonitorStream::TimerCommand* pRec2 = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf2->m_end.m_storage);
                    pRec2->m_commandAndMonitor = "Et";
                    _ReadWriteBarrier();
                    rT2 = (DWORD)__rdtsc();
                    pRec2->m_time0 = rT2;
                    pBuf2->m_end.m_storage = reinterpret_cast<char*>(pRec2 + 1);
                }
            }
        }
    }
    worldCallbackUtil_cleanupNullPointers(*pCallbacks);
}

#include <windows.h>

extern DWORD DAT_0126835c;
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern const char str_010ccb10[];
extern const char str_010ccb04[];

struct S011b0_Listener
{
    virtual void v00();
    virtual void v04(void* p);
    virtual void v08(void* p);
};

struct S011b0_Ext
{
    FNV_SmallArray_00d00320 m_kContactListenerArray;
};

struct S011b0_Entity
{
    DWORD unk0000;
    DWORD unk0004;
    DWORD unk0008;
    DWORD unk000C;
    DWORD unk0010;
    DWORD unk0014;
    DWORD unk0018;
    DWORD unk001C;
    DWORD unk0020;
    DWORD unk0024;
    DWORD unk0028;
    DWORD unk002C;
    DWORD unk0030;
    DWORD unk0034;
    DWORD unk0038;
    DWORD unk003C;
    DWORD unk0040;
    DWORD unk0044;
    DWORD unk0048;
    DWORD unk004C;
    DWORD unk0050;
    DWORD unk0054;
    DWORD unk0058;
    DWORD unk005C;
    DWORD unk0060;
    DWORD unk0064;
    DWORD unk0068;
    DWORD unk006C;
    DWORD unk0070;
    DWORD unk0074;
    DWORD unk0078;
    DWORD unk007C;
    DWORD unk0080;
    DWORD unk0084;
    DWORD unk0088;
    DWORD unk008C;
    DWORD unk0090;
    DWORD unk0094;
    DWORD unk0098;
    DWORD unk009C;
    DWORD unk00A0;
    DWORD unk00A4;
    DWORD unk00A8;
    DWORD unk00AC;
    DWORD unk00B0;
    DWORD unk00B4;
    DWORD unk00B8;
    DWORD unk00BC;
    DWORD unk00C0;
    DWORD unk00C4;
    DWORD unk00C8;
    DWORD unk00CC;
    DWORD unk00D0;
    DWORD unk00D4;
    DWORD unk00D8;
    DWORD unk00DC;
    DWORD unk00E0;
    DWORD unk00E4;
    DWORD unk00E8;
    DWORD unk00EC;
    DWORD unk00F0;
    DWORD unk00F4;
    DWORD unk00F8;
    DWORD unk00FC;
    DWORD unk0100;
    DWORD unk0104;
    DWORD unk0108;
    DWORD unk010C;
    DWORD unk0110;
    DWORD unk0114;
    DWORD unk0118;
    DWORD unk011C;
    DWORD unk0120;
    DWORD unk0124;
    DWORD unk0128;
    DWORD unk012C;
    DWORD unk0130;
    DWORD unk0134;
    DWORD unk0138;
    DWORD unk013C;
    DWORD unk0140;
    DWORD unk0144;
    DWORD unk0148;
    DWORD unk014C;
    DWORD unk0150;
    DWORD unk0154;
    DWORD unk0158;
    DWORD unk015C;
    DWORD unk0160;
    DWORD unk0164;
    DWORD unk0168;
    DWORD unk016C;
    DWORD unk0170;
    DWORD unk0174;
    DWORD unk0178;
    DWORD unk017C;
    DWORD unk0180;
    DWORD unk0184;
    DWORD unk0188;
    DWORD unk018C;
    DWORD unk0190;
    DWORD unk0194;
    DWORD unk0198;
    DWORD unk019C;
    DWORD unk01A0;
    DWORD unk01A4;
    DWORD unk01A8;
    DWORD unk01AC;
    DWORD unk01B0;
    DWORD unk01B4;
    DWORD unk01B8;
    DWORD unk01BC;
    DWORD unk01C0;
    DWORD unk01C4;
    DWORD unk01C8;
    DWORD unk01CC;
    DWORD unk01D0;
    DWORD unk01D4;
    DWORD unk01D8;
    DWORD unk01DC;
    DWORD unk01E0;
    DWORD unk01E4;
    DWORD unk01E8;
    DWORD unk01EC;
    DWORD unk01F0;
    DWORD unk01F4;
    DWORD unk01F8;
    DWORD unk01FC;
    DWORD unk0200;
    DWORD unk0204;
    DWORD unk0208;
    DWORD unk020C;
    DWORD unk0210;
    S011b0_Ext* m_pSub;
};

struct S011b0_Island
{
    DWORD unk0000;
    DWORD unk0004;
    DWORD unk0008;
    DWORD unk000C;
    DWORD unk0010;
    DWORD unk0014;
    DWORD unk0018;
    DWORD unk001C;
    DWORD unk0020;
    DWORD unk0024;
    DWORD unk0028;
    DWORD unk002C;
    DWORD unk0030;
    DWORD unk0034;
    DWORD unk0038;
    DWORD unk003C;
    DWORD unk0040;
    DWORD unk0044;
    S011b0_Entity** m_ppEnts;
    int m_nEnts;
};


// Calls the world's and each entity's listeners for isl with profiler records, then may run FUN_00c91120/FUN_00c91140 when w->m_iCriticalOperationsLockCount returns to 0 and m_9c is clear.
// @fnv 0x00d011b0
// src: HAVOK_LIB 0x00d011b0
void __cdecl hkpWorldCallbackUtil_fireIslandDeactivated(hkpWorld* apWorld, S011b0_Island* apIsland)
{
    struct
    {
        volatile DWORD first;
        volatile DWORD second;
    } timing;
    apWorld->m_iCriticalOperationsLockCount++;
    {
        hkArrayBase<void*>& list = (hkArrayBase<void*>&)apWorld->m_kIslandActivationListeners;
        for (int i = list.m_iElementCount - 1; i >= 0; i--)
        {
            if (list.m_data[i] != 0)
            {
                hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
                if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
                {
                    hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                    pRec->m_commandAndMonitor = str_010ccb10;
                    _ReadWriteBarrier();
                    timing.first = (DWORD)__rdtsc();
                    pRec->m_time0 = timing.first;
                    pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
                }
                ((S011b0_Listener*)list.m_data[i])->v08(apIsland);
                pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
                if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
                {
                    hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                    pRec->m_commandAndMonitor = &str_010c41f8;
                    _ReadWriteBarrier();
                    timing.second = (DWORD)__rdtsc();
                    pRec->m_time0 = timing.second;
                    pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
                }
            }
        }
        ::worldCallbackUtil_cleanupNullPointers(list);
    }
    for (int iEntity = 0; iEntity < apIsland->m_nEnts; iEntity++)
    {
        S011b0_Entity* ent = apIsland->m_ppEnts[iEntity];
        if (ent->m_pSub)
        {
            FNV_SmallArray_00d00320& l = ent->m_pSub->m_kContactListenerArray;
            for (int j = l.m_uiItemCount - 1; j >= 0; j--)
            {
                if (l.m_pItems[j] != 0)
                {
                    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
                    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
                    {
                        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                        pRec->m_commandAndMonitor = str_010ccb04;
                        _ReadWriteBarrier();
                        timing.second = (DWORD)__rdtsc();
                        pRec->m_time0 = timing.second;
                        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
                    }
                    ((S011b0_Listener*)l.m_pItems[j])->v04(apIsland->m_ppEnts[iEntity]);
                    pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
                    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
                    {
                        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                        pRec->m_commandAndMonitor = &str_010c41f8;
                        _ReadWriteBarrier();
                        timing.first = (DWORD)__rdtsc();
                        pRec->m_time0 = timing.first;
                        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
                    }
                }
            }
            ::RemoveZeroEntries(&l);
        }
    }
    if (--apWorld->m_iCriticalOperationsLockCount == 0 && !apWorld->m_bBlockExecutingPendingOperations)
    {
        if (apWorld->m_iPendingOperationCount)
            apWorld->FUN_00c91120();
        if (apWorld->m_iPendingOperationQueueCount == 1 && apWorld->m_iQueuedOperationCount)
            apWorld->UpdateFields_00c91140();
    }
}

struct D00960Listener
{
    virtual void method0();
    virtual void method1(void* arg);
};

// Iterates owner->m_kTargets, records TtconAddCb/Et profiler ticks around each D00960Listener::method1 call, then calls FUN_00d00370 on the list.
// @fnv 0x00d00960
// src: HAVOK_LIB 0x00d00960
void __cdecl hkpWorldCallbackUtil_fireConstraintAdded(::hkpWorld* owner, void* arg)
{
    volatile unsigned long uiEndTick;
    volatile unsigned long* pEndTick = &uiEndTick;
    ::hkArrayBase<void*>* list = (::hkArrayBase<void*>*)&owner->m_kConstraintListeners;
    int i = list->m_iElementCount;
    while (--i >= 0)
    {
        if (list->m_data[i])
        {
            ::hkMonitorStream* buf = (::hkMonitorStream*)::TlsGetValue(::DAT_0126835c);
            ::hkMonitorStream::TimerCommand* rec = reinterpret_cast<hkMonitorStream::TimerCommand*>(buf->m_end.m_storage);
            if (reinterpret_cast<char*>(rec) < buf->m_capacityMinus16.m_storage)
            {
                volatile unsigned long uiStartTick;
                rec->m_commandAndMonitor = "TtconAddCb";
                // Publish the marker name before sampling its timestamp.
                ::_ReadWriteBarrier();
                uiStartTick = (unsigned long)::__rdtsc();
                rec->m_time0 = uiStartTick;
                buf->m_end.m_storage = reinterpret_cast<char*>(rec + 1);
            }
            ((D00960Listener*)list->m_data[i])->method1(arg);
            buf = (::hkMonitorStream*)::TlsGetValue(::DAT_0126835c);
            rec = reinterpret_cast<hkMonitorStream::TimerCommand*>(buf->m_end.m_storage);
            if (reinterpret_cast<char*>(rec) < buf->m_capacityMinus16.m_storage)
            {
                rec->m_commandAndMonitor = "Et";
                // Publish the marker name before sampling its timestamp.
                ::_ReadWriteBarrier();
                *pEndTick = (unsigned long)::__rdtsc();
                rec->m_time0 = uiEndTick;
                buf->m_end.m_storage = reinterpret_cast<char*>(rec + 1);
            }
        }
    }
    ::worldCallbackUtil_cleanupNullPointers(*list);
}
