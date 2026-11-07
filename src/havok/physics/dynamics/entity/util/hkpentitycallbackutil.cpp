#include "../../../../../../include/hkArray.h"

// src/havok/physics/dynamics/entity/util/hkpentitycallbackutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/entity/util/hkpentitycallbackutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMonitorStream.h"

struct CFF9B0SmallArray
{
    void** m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        for (int i = index; i < m_iElementCount; i++)
            m_data[i] = m_data[i + 1];
    }
};

// Iterates the array backwards and removes every entry whose pointer is null via removeAtAndCopy.
// @fnv 0x00cff9b0
// src: GUESS 0x00cff9b0 (confidence: high)
static void Hkpentitycallbackutil_RemoveNullEntries(CFF9B0SmallArray& cleanupArray)
{
    for (int i = cleanupArray.m_iElementCount - 1; i >= 0; i--)
    {
        if (cleanupArray.m_data[i] == 0)
            cleanupArray.removeAtAndCopy(i);
    }
}

// Callers so the file-static helper is emitted with its register calling convention.
void CFF9B0CleanupListeners(CFF9B0SmallArray* a, CFF9B0SmallArray* b)
{
    Hkpentitycallbackutil_RemoveNullEntries(*a);
    Hkpentitycallbackutil_RemoveNullEntries(*b);
}

extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class ContactPointEvent;
class ContactPointListener
{
  public:
    virtual void HandleContactPointEvent(ContactPointEvent*);
};
struct Array833
{
    ContactPointListener** data;
    unsigned short size;
    unsigned short capacity;
};
struct World833
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    Array833 contactPointListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
// src: GUESS 0x00cff9b0 (confidence: high)
static __declspec(noinline) void Hkpentitycallbackutil_RemoveNullEntries(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
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
    Timer833* command = (Timer833*)stream->m_end.val();
    if ((char*)command < stream->m_capacityMinus16.val())
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->m_end.m_storage = (char*)(command + 1);
    }
}
// Invokes HandleContactPointEvent on each non-null contact point listener in world->contactPointListeners, then removes null entries via FUN_00cff9b0.
// @fnv 0x00cfff00
// src: HAVOK_LIB 0x00cfff00
void __cdecl hkpEntityCallbackUtil_fireContactPointCallbackInternal(World833* world, ContactPointEvent* event)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = world->contactPointListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtcpCb", beginTicks);
            listeners.data[i]->HandleContactPointEvent(event);
            TimerEvent833("Et", endTicks);
        }
    }
    Hkpentitycallbackutil_RemoveNullEntries(listeners);
}

namespace fnv_00d00060 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class ContactPointEvent;
class ContactPointListener
{
  public:
    virtual void HandleContactPointEvent(ContactPointEvent*);
    virtual void newCollisionCallback(ContactPointEvent*);
    virtual void finishedCollisionCallback(ContactPointEvent*);
};
struct Array833
{
    ContactPointListener** data;
    unsigned short size;
    unsigned short capacity;
};
struct World833
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    Array833 contactPointListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
// src: GUESS 0x00cff9b0 (confidence: high)
static __declspec(noinline) void Hkpentitycallbackutil_RemoveNullEntries(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            for (int destination = index; destination < listeners.size; ++destination)
                listeners.data[destination] = listeners.data[destination + 1];
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
    Timer833* command = (Timer833*)stream->m_end.val();
    if ((char*)command < stream->m_capacityMinus16.val())
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->m_end.m_storage = (char*)(command + 1);
    }
}
// Iterates world->contactPointListeners, calls finishedCollisionCallback on each non-null listener, then removes null entries via FUN_00cff9b0.
// @fnv 0x00d00060
// src: HAVOK_LIB 0x00d00060
void __cdecl hkpEntityCallbackUtil_fireContactConstraintRemovedCallback(World833* world, ContactPointEvent* event)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = world->contactPointListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtFinCollCb", beginTicks);
            listeners.data[i]->finishedCollisionCallback(event);
            TimerEvent833("Et", endTicks);
        }
    }
    Hkpentitycallbackutil_RemoveNullEntries(listeners);
}
}  // namespace fnv_00d00060

extern unsigned long DAT_0126835c;


static __forceinline void timerBegin(const char* name, volatile unsigned int& tb)
{
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* cur = stream->m_end.m_storage;
    if (cur < stream->m_capacityMinus16.m_storage)
    {
        *(const char**)cur = name;
        _ReadWriteBarrier();
        volatile unsigned int& t_begin = tb;
        t_begin = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = t_begin;
        stream->m_end.m_storage = cur + 12;
    }
}

static __forceinline void timerEnd(const char* name)
{
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* cur = stream->m_end.m_storage;
    if (cur < stream->m_capacityMinus16.m_storage)
    {
        *(const char**)cur = name;
        _ReadWriteBarrier();
        volatile unsigned int t_end = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = (unsigned int)t_end;
        stream->m_end.m_storage = cur + 12;
    }
}

struct Class_00cffab0;

struct Listener1
{
    virtual void vfn0() = 0;
    virtual void vfn1() = 0;
    virtual void vfn2(Class_00cffab0* obj) = 0;
};

struct Listener2
{
    virtual void vfn0() = 0;
    virtual void vfn1() = 0;
    virtual void vfn2() = 0;
    virtual void vfn3() = 0;
    virtual void vfn4(Class_00cffab0* obj) = 0;
};

struct Listener4
{
    virtual void vfn0() = 0;
    virtual void vfn1() = 0;
    virtual void vfn2() = 0;
    virtual void vfn3() = 0;
    virtual void vfn4() = 0;
    virtual void vfn5() = 0;
    virtual void vfn6(Class_00cffab0* obj) = 0;
};

struct Container_00cffab0
{
    int unk00;
    int unk04;
    CFF9B0SmallArray listeners;
};



struct Class_00cffab0
{
    int unk00;
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
    CFF9B0SmallArray m_smallArrayAC;
    hkArrayBase<Listener2*> m_arrayB4;
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
    CFF9B0SmallArray m_smallArray208;
    int unk210;
    Container_00cffab0* m_container214;

    void UpdateNodeSlotIndices();
};

// Calls vfn2 on the container's listeners, then vfn4 / vfn6 on the other listener arrays until each is empty, with UpdateNodeSlotIndices in between.
// @fnv 0x00cffab0
// src: HAVOK_LIB 0x00cffab0
void __cdecl hkpEntityCallbackUtil_fireEntityRemoved(Class_00cffab0* obj)
{
    Container_00cffab0* container = obj->m_container214;
    volatile unsigned int tb;
    if (container)
    {
        for (int i = container->listeners.m_iElementCount - 1; i >= 0; --i)
        {
            if (container->listeners.m_data[i])
            {
                timerBegin("TtentRemCb", tb);
                ((Listener1*)container->listeners.m_data[i])->vfn2(obj);
                timerEnd("Et");
            }
        }
    }

    while (obj->m_smallArrayAC.m_iElementCount)
    {
        timerBegin("TtentRemCb", tb);
        ((Listener2*)obj->m_smallArrayAC.m_data[0])->vfn4(obj);
        timerEnd("Et");
    }

    obj->UpdateNodeSlotIndices();

    while (obj->m_arrayB4.m_iElementCount)
    {
        timerBegin("TtentRemCb", tb);
        obj->m_arrayB4.m_data[0]->vfn4(obj);
        timerEnd("Et");
    }

    while (obj->m_smallArray208.m_iElementCount)
    {
        timerBegin("TtentRemCb", tb);
        ((Listener4*)obj->m_smallArray208.m_data[0])->vfn6(obj);
        timerEnd("Et");
    }
}

#include <windows.h>
#include "../../../../../../include/hkMonitorStream.h"
struct CFFCF0TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};


extern DWORD g_CFFCF0TlsIndex;

__forceinline hkMonitorStream& CFFCF0GetMonitorStream()
{
    return *(hkMonitorStream*)TlsGetValue(g_CFFCF0TlsIndex);
}

__forceinline void CFFCF0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    hkMonitorStream& mStream = CFFCF0GetMonitorStream();
    if (mStream.m_end.val() < mStream.m_capacityMinus16.val())
    {
        CFFCF0TimerCommand* h = (CFFCF0TimerCommand*)mStream.m_end.val();
        h->m_pCommandName = name;
        h->setTime(ticks);
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}

struct CFFCF0TimerTicks
{
    unsigned int m_pRayStart;
    unsigned int m_kRayEnd;
};

struct CFFCF0Owner;

struct CFFCF0Listener
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void callback(CFFCF0Owner* owner);
};

struct CFFCF0ListenerList
{
    int unk00;
    int unk04;
    CFFCF0Listener** m_kListeners;
    unsigned short m_uiItemCount;
};

struct CFFCF0Owner
{
    char unk000[0x214];
    CFFCF0ListenerList* m_listenerList;
};

extern const char g_CFFCF0TimerBegin[];
extern const char g_CFFCF0TimerEnd[];

// Iterates the owner's listener list in reverse and invokes each non-null listener's callback, bracketing each call with timer begin/end markers.
// @fnv 0x00cffcf0
// src: HAVOK_LIB 0x00cffcf0
void __cdecl hkpEntityCallbackUtil_fireEntityShapeSet(CFFCF0Owner* owner)
{
    volatile CFFCF0TimerTicks ticks;
    CFFCF0ListenerList* list = owner->m_listenerList;
    if (list)
    {
        for (int i = list->m_uiItemCount - 1; i >= 0; i--)
        {
            if (list->m_kListeners[i] != 0)
            {
                CFFCF0TimerBegin(g_CFFCF0TimerBegin, ticks.m_pRayStart);
                list->m_kListeners[i]->callback(owner);
                CFFCF0TimerBegin(g_CFFCF0TimerEnd, ticks.m_kRayEnd);
            }
        }
    }
}

extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);



class TaskObj
{
  public:
    virtual void vtbl00(void);
    virtual void vtbl04(void);
    virtual void vtbl08(void);
    virtual void vtbl0C(void);
    virtual void vtbl10(void* pOwner);
};

struct TaskList
{
    DWORD unk00;
    DWORD unk04;
    TaskObj** m_ppItems;
    unsigned short m_nCount;
};

struct TaskOwner
{
    DWORD unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    DWORD unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    DWORD unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    DWORD unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    DWORD unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    DWORD unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    DWORD unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    DWORD unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    DWORD unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    DWORD unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    DWORD unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    DWORD unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    DWORD unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    DWORD unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    DWORD unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    DWORD unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    DWORD unk200, unk204, unk208, unk20C, unk210;
    TaskList* m_pEntries;
};

typedef LPVOID(WINAPI* PFN_TlsGetValue)(DWORD dwTlsIndex);

// Iterates the task list in reverse, profiling and calling vtbl10 on each non-null TaskObj with the owner.
// @fnv 0x00cffda0
void __cdecl InvokeMotionTypeCallbacks(TaskOwner* pOwner)
{
    volatile DWORD ticks[2];
    TaskList* pList = pOwner->m_pEntries;
    if (pList != 0)
    {
        int i = (int)pList->m_nCount - 1;
        if (i >= 0)
        {
            PFN_TlsGetValue pfnTls = TlsGetValue;
            do
            {
                if (pList->m_ppItems[i] != 0)
                {
                    hkMonitorStream* pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
                    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
                    {
                        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                        pRec->m_commandAndMonitor = "TtsetMotionTypeCb";
                        _ReadWriteBarrier();
                        ticks[0] = (DWORD)__rdtsc();
                        pRec->m_time0 = ticks[0];
                        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
                    }

                    pList->m_ppItems[i]->vtbl10(pOwner);

                    pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
                    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
                    {
                        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                        pRec->m_commandAndMonitor = "Et";
                        _ReadWriteBarrier();
                        ticks[1] = (DWORD)__rdtsc();
                        pRec->m_time0 = ticks[1];
                        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
                    }
                }
                i--;
            } while (i >= 0);
        }
    }
}

extern DWORD DAT_0126835c;
extern "C" void _ReadWriteBarrier(void);

unsigned __int64 __cdecl __rdtsc(void);

class ListItem
{
  public:
    virtual void vtbl00(void);
    virtual void vtbl04(void);
    virtual void vtbl08(void);
    virtual void vtbl0C(void);
    virtual void vtbl10(void);
    virtual void vtbl14(void* pOwner);
};

struct ItemList
{
    DWORD unk00;
    DWORD unk04;
    ListItem** m_ppItems;
    WORD m_wCount;
};

struct ProfOwner
{
    DWORD unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    DWORD unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    DWORD unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    DWORD unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    DWORD unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    DWORD unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    DWORD unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    DWORD unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    DWORD unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    DWORD unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    DWORD unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    DWORD unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    DWORD unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    DWORD unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    DWORD unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    DWORD unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    DWORD unk200, unk204, unk208, unk20C, unk210;
    ItemList* m_pItems;
};

// Iterates pOwner->m_pItems, writing TtentDelCb/Et profiling ticks around each item's vtbl14(pOwner) call.
// @fnv 0x00cffe50
void __cdecl DeleteCallbacks(ProfOwner* pOwner)
{
    LPVOID(WINAPI * pfnTlsGetValue)(DWORD) = TlsGetValue;
    ItemList* pList = pOwner->m_pItems;
    int i;
    volatile DWORD ticks[2];

    if (pList != 0)
    {
        i = (int)pList->m_wCount - 1;
        if (i >= 0)
        {
            for (; i >= 0; i--)
            {
                if (pList->m_ppItems[i] != 0)
                {
                    hkMonitorStream* pBuf = (hkMonitorStream*)pfnTlsGetValue(DAT_0126835c);
                    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
                    {
                        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                        pRec->m_commandAndMonitor = "TtentDelCb";
                        _ReadWriteBarrier();
                        ticks[0] = (DWORD)__rdtsc();
                        pRec->m_time0 = ticks[0];
                        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
                    }
                    pList->m_ppItems[i]->vtbl14(pOwner);
                    hkMonitorStream* pBuf2 = (hkMonitorStream*)pfnTlsGetValue(DAT_0126835c);
                    if (pBuf2->m_end.m_storage < pBuf2->m_capacityMinus16.m_storage)
                    {
                        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf2->m_end.m_storage);
                        pRec->m_commandAndMonitor = "Et";
                        _ReadWriteBarrier();
                        ticks[1] = (DWORD)__rdtsc();
                        pRec->m_time0 = ticks[1];
                        pBuf2->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
                    }
                }
            }
        }
    }
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern char DAT_010cca44[];
extern char DAT_010c41f8[];
struct TimerEntry
{
    const char* m_name;
    unsigned int m_uiCommandId;
    unsigned int m_08;
};
static inline void TimerWriteV(const char* name, volatile unsigned int& t)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_end.val() < s->m_capacityMinus16.val())
    {
        TimerEntry* h = (TimerEntry*)s->m_end.val();
        h->m_name = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}
struct ContactListener
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void callback(void* event);
};
struct ListenerEvent
{
    int m_00;
    int m_04;
    int m_08;
    void* m_pObservedSource;
};
struct ListenerOwner
{
    int m_000, m_004, m_008, m_00c, m_010, m_014, m_018, m_01c;
    int m_020, m_024, m_028, m_02c, m_030, m_034, m_038, m_03c;
    int m_040, m_044, m_048, m_04c, m_050, m_054, m_058, m_05c;
    int m_060, m_064, m_068, m_06c, m_070, m_074, m_078, m_07c;
    int m_080, m_084, m_088, m_08c, m_090, m_094, m_098, m_09c;
    int m_0a0, m_0a4, m_0a8, m_0ac, m_0b0, m_0b4, m_0b8, m_0bc;
    int m_0c0, m_0c4, m_0c8, m_0cc, m_0d0, m_0d4, m_0d8, m_0dc;
    int m_0e0, m_0e4, m_0e8, m_0ec, m_0f0, m_0f4, m_0f8, m_0fc;
    int m_100, m_104, m_108, m_10c, m_110, m_114, m_118, m_11c;
    int m_120, m_124, m_128, m_12c, m_130, m_134, m_138, m_13c;
    int m_140, m_144, m_148, m_14c, m_150, m_154, m_158, m_15c;
    int m_160, m_164, m_168, m_16c, m_170, m_174, m_178, m_17c;
    int m_180, m_184, m_188, m_18c, m_190, m_194, m_198, m_19c;
    int m_1a0, m_1a4, m_1a8, m_1ac, m_1b0, m_1b4, m_1b8, m_1bc;
    int m_1c0, m_1c4, m_1c8, m_1cc, m_1d0, m_1d4, m_1d8, m_1dc;
    int m_1e0, m_1e4, m_1e8, m_1ec, m_1f0, m_1f4, m_1f8, m_1fc;
    CFF9B0SmallArray m_kListeners;
};
// Sets event->m_pObservedSource to owner, calls callback on each non-null listener in reverse with timers, then calls FUN_00cff9b0 to remove null entries.
// @fnv 0x00d00110
// src: HAVOK_LIB 0x00d00110
void __cdecl hkpEntityCallbackUtil_fireContactPointAddedInternal(ListenerOwner* owner, ListenerEvent* event)
{
    CFF9B0SmallArray& kListeners = owner->m_kListeners;
    event->m_pObservedSource = owner;
    for (int i = kListeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (kListeners.m_data[i] != 0)
        {
            volatile unsigned int t1;
            volatile unsigned int uiTimerEnd;
            TimerWriteV(DAT_010cca44, t1);
            ((ContactListener*)kListeners.m_data[i])->callback(event);
            TimerWriteV(DAT_010c41f8, uiTimerEnd);
        }
    }
    Hkpentitycallbackutil_RemoveNullEntries(kListeners);
}

struct CEvent;
struct CFF9B0SmallArray;
struct CListener
{
    virtual void m00();
    virtual void m01();
    virtual void m02();
    virtual void m03();
    virtual void m04();
    virtual void m05(CEvent* ev);
};
struct CProfileMarker
{
    const char* m_name;
    unsigned int m_tsc;
    unsigned int m_unk08;
};
struct CEvent
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pOwnerObject;
};
extern unsigned int g_tcpTlsIndex;
static void __declspec(noinline) Hkpentitycallbackutil_RemoveNullEntries(CFF9B0SmallArray& a);
struct CManager
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    CFF9B0SmallArray m_kListeners;
};
// Sets ev->m_pOwnerObject to mgr, iterates mgr->m_kListeners in reverse calling m05 on each CListener with ev, then calls FUN_00cff9b0 on the listener array.
// @fnv 0x00d001c0
// src: HAVOK_LIB 0x00d001c0
void hkpEntityCallbackUtil_fireContactPointRemovedInternal(CManager* mgr, CEvent* ev)
{
    CFF9B0SmallArray* list = &mgr->m_kListeners;
    ev->m_pOwnerObject = mgr;

    for (int i = list->m_iElementCount - 1; i >= 0; i--)
    {
        if (!list->m_data[i])
            continue;

        {
            hkMonitorStream* tls = (hkMonitorStream*)TlsGetValue(g_tcpTlsIndex);
            if (tls->m_end.val() < tls->m_capacityMinus16.val())
            {
                CProfileMarker* marker = (CProfileMarker*)tls->m_end.val();
                marker->m_name = "TtcpRemCb";
                _ReadWriteBarrier();
                volatile unsigned int timestamp = (unsigned int)__rdtsc();
                marker->m_tsc = timestamp;
                tls->m_end.m_storage = (char*)(marker + 1);
            }
        }

        ((CListener*)list->m_data[i])->m05(ev);

        {
            hkMonitorStream* tls = (hkMonitorStream*)TlsGetValue(g_tcpTlsIndex);
            if (tls->m_end.val() < tls->m_capacityMinus16.val())
            {
                CProfileMarker* marker = (CProfileMarker*)tls->m_end.val();
                marker->m_name = "Et";
                _ReadWriteBarrier();
                volatile unsigned int timestamp = (unsigned int)__rdtsc();
                void* p = (void*)&timestamp;
                marker->m_tsc = timestamp;
                tls->m_end.m_storage = (char*)(marker + 1);
            }
        }
    }

    Hkpentitycallbackutil_RemoveNullEntries(*list);
}

extern DWORD DAT_0126835c;
// string literals used inline
// (see below)

unsigned __int64 __cdecl __rdtsc(void);



class ListItem_cffa00
{
  public:
    virtual void vtbl00(void);
    virtual void vtbl04(void* pOwner);
};

struct ItemList_cffa00
{
    DWORD unk00;
    DWORD unk04;
    ListItem_cffa00** m_ppItems;
    WORD m_wCount;
};

struct ProfOwner_cffa00
{
    DWORD unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    DWORD unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    DWORD unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    DWORD unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    DWORD unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    DWORD unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    DWORD unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    DWORD unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    DWORD unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    DWORD unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    DWORD unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    DWORD unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    DWORD unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    DWORD unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    DWORD unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    DWORD unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    DWORD unk200, unk204, unk208, unk20C, unk210;
    ItemList_cffa00* m_pItems;
};

// Iterates pOwner->m_pItems in reverse, writing TtentAddCb/Et rdtsc ticks to the TLS hkMonitorStream and calling vtbl04 on each item.
// @fnv 0x00cffa00
// src: HAVOK_LIB 0x00cffa00
void __cdecl hkpEntityCallbackUtil_fireEntityAdded(ProfOwner_cffa00* pOwner)
{
    LPVOID(WINAPI * pfnTlsGetValue)(DWORD) = TlsGetValue;
    ItemList_cffa00* pList = pOwner->m_pItems;
    int i;
    volatile DWORD ticks[2];

    if (pList != 0)
    {
        i = (int)pList->m_wCount - 1;
        if (i >= 0)
        {
            for (; i >= 0; i--)
            {
                if (pList->m_ppItems[i] != 0)
                {
                    hkMonitorStream* pBuf = (hkMonitorStream*)pfnTlsGetValue(DAT_0126835c);
                    if (pBuf->m_end.val() < pBuf->m_capacityMinus16.val())
                    {
                        hkMonitorStream::TimerCommand* pRec = (hkMonitorStream::TimerCommand*)pBuf->m_end.val();
                        pRec->m_commandAndMonitor = "TtentAddCb";
                        _ReadWriteBarrier();
                        ticks[0] = (DWORD)__rdtsc();
                        pRec->m_time0 = ticks[0];
                        pBuf->m_end.m_storage = (char*)(pRec + 1);
                    }
                    pList->m_ppItems[i]->vtbl04(pOwner);
                    hkMonitorStream* pBuf2 = (hkMonitorStream*)pfnTlsGetValue(DAT_0126835c);
                    if (pBuf2->m_end.val() < pBuf2->m_capacityMinus16.val())
                    {
                        hkMonitorStream::TimerCommand* pRec = (hkMonitorStream::TimerCommand*)pBuf2->m_end.val();
                        pRec->m_commandAndMonitor = "Et";
                        _ReadWriteBarrier();
                        ticks[1] = (DWORD)__rdtsc();
                        pRec->m_time0 = ticks[1];
                        pBuf2->m_end.m_storage = (char*)(pRec + 1);
                    }
                }
            }
        }
    }
}

extern DWORD DAT_0126835c;
unsigned __int64 __cdecl __rdtsc(void);
struct TraceTick
{
    volatile DWORD value;
    __forceinline void Record()
    {
        value = (DWORD)__rdtsc();
    }
    __forceinline DWORD Read() const
    {
        return value;
    }
};
struct ItemObj
{
    virtual void v00();
    virtual void v04(void* pParam);
};
struct ItemTable
{
    ItemObj** m_ppItems;
    WORD m_wCount;
};
// Iterates the owner's item table in reverse, calling each item's v04 with apParam and recording TtNewCollCb and Et profiler ticks.
// @fnv 0x00cfffb0
// src: HAVOK_LIB 0x00cfffb0
void __cdecl hkpEntityCallbackUtil_fireContactConstraintAddedCallback(void* apOwner, void* apParam)
{
    ItemTable* pItemTable = (ItemTable*)((char*)apOwner + 0x200);
    int i = (int)pItemTable->m_wCount - 1;
    TraceTick tEnter;
    TraceTick tExit;

    if (i >= 0)
    {
        LPVOID(WINAPI * pfnTlsGetValue)(DWORD) = TlsGetValue;
        do
        {
            if (pItemTable->m_ppItems[i] != 0)
            {
                hkMonitorStream* pBuf = (hkMonitorStream*)pfnTlsGetValue(DAT_0126835c);
                if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
                {
                    hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                    pRec->m_commandAndMonitor = "TtNewCollCb";
                    _ReadWriteBarrier();
                    tEnter.Record();
                    pRec->m_time0 = tEnter.Read();
                    pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
                }

                pItemTable->m_ppItems[i]->v04(apParam);

                hkMonitorStream* pBuf2 = (hkMonitorStream*)pfnTlsGetValue(DAT_0126835c);
                if (pBuf2->m_end.m_storage < pBuf2->m_capacityMinus16.m_storage)
                {
                    hkMonitorStream::TimerCommand* pRec2 = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf2->m_end.m_storage);
                    pRec2->m_commandAndMonitor = "Et";
                    _ReadWriteBarrier();
                    tExit.Record();
                    pRec2->m_time0 = tExit.Read();
                    pBuf2->m_end.m_storage = reinterpret_cast<char*>(pRec2 + 1);
                }
            }
        } while (--i >= 0);
    }

    Hkpentitycallbackutil_RemoveNullEntries(*(CFF9B0SmallArray*)pItemTable);
}

extern DWORD DAT_0126835c;
extern LPVOID(WINAPI* DAT_00fdf044)(DWORD);
unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
struct TaskContext
{
    DWORD unk00;
    DWORD unk04;
    void* m_pSharedOwner;
};
class TaskObjV7
{
  public:
    virtual void v00(void);
    virtual void v01(void);
    virtual void v02(void);
    virtual void v03(void);
    virtual void v04(void);
    virtual void v05(void);
    virtual void v06(TaskContext* pContext);
};
extern const char str_010cca5c[];
extern const char str_010c41f8[];
typedef CFF9B0SmallArray TaskArray;
// Stores pOwner in pContext, calls v06(pContext) on each non-null entry of the array at pOwner+0x200 in reverse with profiler records, then calls FUN_00cff9b0.
// @fnv 0x00d00270
// src: HAVOK_LIB 0x00d00270
void __cdecl hkpEntityCallbackUtil_fireContactProcessInternal(void* pOwner, TaskContext* pContext)
{
    volatile DWORD t1;
    volatile DWORD* pEndTick = &t1;
    TaskArray* pArr = (TaskArray*)((char*)pOwner + 0x200);
    pContext->m_pSharedOwner = pOwner;
    int i = (int)pArr->m_iElementCount - 1;
    if (i >= 0)
    {
        LPVOID(WINAPI * pfnTls)(DWORD) = DAT_00fdf044;
        do
        {
            if (pArr->m_data[i] != 0)
            {
                hkMonitorStream* pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
                hkMonitorStream::TimerCommand* cur = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                if (reinterpret_cast<char*>(cur) < pBuf->m_capacityMinus16.m_storage)
                {
                    cur->m_commandAndMonitor = str_010cca5c;
                    _ReadWriteBarrier();
                    volatile DWORD dwStartTick = (DWORD)__rdtsc();
                    cur->m_time0 = dwStartTick;
                    cur++;
                    pBuf->m_end.m_storage = reinterpret_cast<char*>(cur);
                }
                ((TaskObjV7*)pArr->m_data[i])->v06(pContext);
                pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
                cur = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
                if (reinterpret_cast<char*>(cur) < pBuf->m_capacityMinus16.m_storage)
                {
                    cur->m_commandAndMonitor = str_010c41f8;
                    _ReadWriteBarrier();
                    *pEndTick = (DWORD)__rdtsc();
                    cur->m_time0 = *pEndTick;
                    cur++;
                    pBuf->m_end.m_storage = reinterpret_cast<char*>(cur);
                }
            }
            i--;
        } while (i >= 0);
    }
    Hkpentitycallbackutil_RemoveNullEntries(*pArr);
}
