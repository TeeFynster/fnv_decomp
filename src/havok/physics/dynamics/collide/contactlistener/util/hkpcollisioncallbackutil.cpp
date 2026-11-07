
// src/havok/physics/dynamics/collide/contactlistener/util/hkpcollisioncallbackutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/collide/contactlistener/util/hkpcollisioncallbackutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/Data.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkThreadMemory.h"

struct FUN_00d0b1e0
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    void* unk0c;
    int unk10;
    struct Base
    {
        void FUN_00d0b0d0();
    };
    FUN_00d0b1e0(int flags);
};
extern int DAT_0102e388;
extern int DAT_010cb1e4;
extern int DAT_010cb1c4;
extern "C" void* __cdecl hkMemoryRouter_getInstance();
struct CallbackInterface
{
    virtual void f0();
    virtual void f1();
    virtual void callback(void*, unsigned short);
};
struct Manager
{
    int unk00[4];
    CallbackInterface* interface10;
};
// Initializes the object's base subobject and pointers, then if flags bit 0 is set calls callback on the manager's interface with this and unk04.
// @fnv 0x00d0b1e0
FUN_00d0b1e0::FUN_00d0b1e0(int flags)
{
    ((Base*)((char*)this + 0x14))->FUN_00d0b0d0();
    unk0c = &DAT_010cb1c4;
    unk08 = &DAT_010cb1e4;
    unk00 = &DAT_0102e388;
    if (flags & 1)
    {
        Manager* manager = (Manager*)hkMemoryRouter_getInstance();
        manager->interface10->callback(this, unk04);
    }
}

struct CallbackTarget
{
    void hkpWorld_removeConstraintListener(void* apValue);
    void hkpWorld_removeWorldDeletionListener(void* apValue);
};

struct OuterRefHolder
{
    int unk00;
    int unk04;
    int unk08;

    void FUN_00c905b0();
};

struct SubEntry
{
    int unk00;

    void ClearValue_Thunk_00d9e280(CallbackTarget* apTarget);
};

struct FUN_00d0ae30_cls
{
    int unk00;
    int unk04;
    SubEntry m_08;

    void hkpCollisionCallbackUtil_worldDeletedCallback(CallbackTarget* apTarget);
};

// @fnv 0x00d0ae30
// src: HAVOK_LIB 0x00d0ae30
void FUN_00d0ae30_cls::hkpCollisionCallbackUtil_worldDeletedCallback(CallbackTarget* apTarget)
{
    m_08.ClearValue_Thunk_00d9e280(apTarget);
    apTarget->hkpWorld_removeConstraintListener(((char*)this - 0xc) != 0 ? (char*)this - 4 : 0);
    apTarget->hkpWorld_removeWorldDeletionListener(((char*)this - 0xc) != 0 ? (char*)this : 0);
    ((OuterRefHolder*)((char*)this - 0xc))->FUN_00c905b0();
}

extern int DAT_010cb1e4;
extern int DAT_010cb1c4;
extern int DAT_010cd33c;
extern int DAT_010cd31c;
extern int DAT_010cd30c;

struct FUN_00d0b180_sub
{
    void FUN_00d9e860();
};

struct FUN_00d0b180_cls
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    void* unk0c;
    int unk10;
    FUN_00d0b180_sub unk14;
    FUN_00d0b180_cls* Initialize();
};

// Sets the object's fields to point at the given globals, sets unk06 and unk10 to 1, calls FUN_00d9e860 on unk14, and returns this.
// @fnv 0x00d0b180
FUN_00d0b180_cls* FUN_00d0b180_cls::Initialize()
{
    *(volatile unsigned short*)&unk06 = 1;
    *(void* volatile*)&unk08 = &DAT_010cb1e4;
    *(void* volatile*)&unk0c = &DAT_010cb1c4;
    FUN_00d0b180_sub* sub = &unk14;
    unk00 = &DAT_010cd33c;
    unk08 = &DAT_010cd31c;
    unk0c = &DAT_010cd30c;
    unk10 = 1;
    sub->FUN_00d9e860();
    return this;
}

#include <windows.h>
extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);

typedef LPVOID(WINAPI* PFN_TlsGetValue)(DWORD dwTlsIndex);

struct Collider
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int v20();
    void* unk04;
    void* unk08;
    void* GetBase();
};

struct Node
{
    void* unk00;
    void* unk04;
    void* unk08;
};

struct Params
{
    void* unk00;
    void* unk04;
    void* unk08;
    Collider* unk0c;
    void* unk10;
    Node* unk14;
    void* unk18;
};

extern "C" void __cdecl DispatchCollisionEvents(void* obj, Data* data);
extern "C" void __cdecl hkpEntityCallbackUtil_fireContactConstraintAddedCallback(void* obj, Data* data);

// Records a profiler tick, then if pObj->v20() is 11 calls DispatchCollisionEvents once and FUN_00cfffb0 twice with a Data record, and records an end tick.
// @fnv 0x00d0ae80
// src: XBOX_PDB 0x00d0ae80
void __stdcall hkpCollisionCallbackUtil_constraintAddedCallback(Params* p)
{
    PFN_TlsGetValue pfnTls = TlsGetValue;
    // Collision records use uninitialized storage; Data's unrelated lifecycle is not invoked.
    unsigned int dataStorage[sizeof(Data) / sizeof(unsigned int)];
    Data& data = *(Data*)dataStorage;
    volatile DWORD tickEnter;
    {
        hkMonitorStream* pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
        if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
            pRec->m_commandAndMonitor = "TtCollLtUtil";
            _ReadWriteBarrier();
            tickEnter = (DWORD)__rdtsc();
            pRec->m_time0 = tickEnter;
            pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
        }
    }

    Collider* pCollider = p->unk0c;
    if (pCollider->v20() == 11)
    {
        *(void**)&data.uiSubCategoryID = pCollider->GetBase();
        Node* a = p->unk14;
        void* b = p->unk18;
        data.eReqSkill = (ActorValue::Index)2;
        *(Node**)&data.iReqSkillLevel = a;
        *(void**)&data.uiCategoryID = b;
        DispatchCollisionEvents(a->unk08, &data);
        data.eReqSkill = (ActorValue::Index)0;
        hkpEntityCallbackUtil_fireContactConstraintAddedCallback(a, &data);
        data.eReqSkill = (ActorValue::Index)1;
        hkpEntityCallbackUtil_fireContactConstraintAddedCallback(b, &data);
    }

    volatile DWORD tickExit;
    {
        hkMonitorStream* pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
        if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
            pRec->m_commandAndMonitor = "Et";
            _ReadWriteBarrier();
            tickExit = (DWORD)__rdtsc();
            pRec->m_time0 = tickExit;
            pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
        }
    }
}

extern DWORD hkMonitorStreamTls;

static inline void S_00d0af60_Timer(const char* name)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)s->m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_time0 = t;
        s->m_end.m_storage = reinterpret_cast<char*>(h + 1);
    }
}

struct S_00d0af60_Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int getType();
    void* hkpSimpleContactConstraintData_getSimpleConstraintContactMgr();
};

struct S_00d0af60_Entity
{
    int unk0;
    int unk4;
    void* unk8;
};

struct S_00d0af60_Input
{
    int unk0;
    int unk4;
    int unk8;
    S_00d0af60_Shape* unkC;
    int unk10;
    S_00d0af60_Entity* unk14;
    S_00d0af60_Entity* unk18;
};

void hkpWorldCallbackUtil_fireContactConstraintRemovedCallback(void*, Data*);
void hkpEntityCallbackUtil_fireContactConstraintRemovedCallback(S_00d0af60_Entity*, Data*);

// Between two profiler timers, if the shape's type is 11, builds an event and calls FUN_00d00de0 with a->unk8, then FUN_00d00060 for each entity.
// @fnv 0x00d0af60
// src: XBOX_PDB 0x00d0af60
void __stdcall hkpCollisionCallbackUtil_constraintRemovedCallback(S_00d0af60_Input* in)
{
    S_00d0af60_Timer("TtCollLfUtil");
    S_00d0af60_Shape* shape = in->unkC;
    if (shape->getType() == 11)
    {
        unsigned int eventStorage[sizeof(Data) / sizeof(unsigned int)];
        Data& ev = *(Data*)eventStorage;
        void* obj = shape->hkpSimpleContactConstraintData_getSimpleConstraintContactMgr();
        S_00d0af60_Entity* a = in->unk14;
        S_00d0af60_Entity* b = in->unk18;
        *(void**)&ev.uiSubCategoryID = obj;
        ev.eReqSkill = (ActorValue::Index)2;
        *(S_00d0af60_Entity**)&ev.iReqSkillLevel = a;
        *(S_00d0af60_Entity**)&ev.uiCategoryID = b;
        hkpWorldCallbackUtil_fireContactConstraintRemovedCallback(a->unk8, &ev);
        ev.eReqSkill = (ActorValue::Index)0;
        hkpEntityCallbackUtil_fireContactConstraintRemovedCallback(a, &ev);
        ev.eReqSkill = (ActorValue::Index)1;
        hkpEntityCallbackUtil_fireContactConstraintRemovedCallback(b, &ev);
    }
    S_00d0af60_Timer("Et");
}

// sub ecx,8; jmp target: MSVC adjustor thunk for the SecondaryBase slot of a
// class deriving from two bases; PrimaryBase is 8 bytes (vptr + one int).
struct AdjPrimaryBase
{
    virtual void AdjustThisAndForward_00d0b1c0();
    int unk04;
};

struct AdjSecondaryBase
{
    virtual void AdjustThisAndForward_00d0b1c0();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x00d0b1c0
// src: GUESS 0x00d0b1c0 (confidence: low)
    virtual void AdjustThisAndForward_00d0b1c0();
};

AdjDerived::AdjDerived()
{}

// sub ecx,0xc; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0xc).
struct PrimaryBase
{
    virtual void FUN_00d0b1d0();
    int unk04;
    int unk08;
};

struct SecondaryBase
{
    virtual void FUN_00d0b1d0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0b1d0
    virtual void FUN_00d0b1d0();
};

Derived::Derived()
{}

struct hkMemory
{
    virtual void unk00();
    virtual void* allocateChunk(int size);
};

namespace fnv_00d0b040 {
struct SubObj
{
    void __thiscall PassObjectToTarget(void* obj);
};

struct hkpCollisionCallbackUtil
{
    char pad00[4];
    unsigned short m_usMemSizeAndFlags;
    char pad06[2];
    void* field_08;
    void* field_0C;
    int m_sReferenceCount;
    SubObj field_14;

    hkpCollisionCallbackUtil* __thiscall Initialize();
};

struct TargetClass
{
    char pad00[0x1c0];
    hkpCollisionCallbackUtil* m_pCallbackData;

    void __thiscall hkpWorld_addWorldDeletionListener(void* p);
    void __thiscall hkpWorld_addConstraintListener(void* p);
};

// Increments the reference count of m_pCallbackData if present, otherwise allocates a 0x4c chunk, initializes it, and wires it into the object.
// @fnv 0x00d0b040
// src: HAVOK_LIB 0x00d0b040
void __cdecl hkpCollisionCallbackUtil_addCollisionCallbackUtil(TargetClass* obj)
{
    hkpCollisionCallbackUtil* util = obj->m_pCallbackData;
    if (util)
    {
        util->m_sReferenceCount++;
        return;
    }

    hkThreadMemory* threadMem = hkThreadMemory::GetMonitorStream();
    hkpCollisionCallbackUtil* mem = (hkpCollisionCallbackUtil*)threadMem->m_pMemoryAllocator->allocateChunk(0x4c);
    mem->m_usMemSizeAndFlags = 0x4c;
    util = mem->Initialize();
    obj->m_pCallbackData = util;

    obj->hkpWorld_addWorldDeletionListener(util ? &util->field_0C : 0);
    obj->hkpWorld_addConstraintListener(util ? &util->field_08 : 0);
    util->field_14.PassObjectToTarget(obj);
}
}  // namespace fnv_00d0b040
