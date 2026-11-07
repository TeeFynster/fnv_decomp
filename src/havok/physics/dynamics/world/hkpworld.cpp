#include "../../../../../include/BSThreadCriticalSectionPC.h"
#include "../../../../../include/hkArray.h"

// src/havok/physics/dynamics/world/hkpworld.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/hkpworld.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstddef>
#include "../../../../../include/hkCriticalSection.h"
#include "../../../../../include/hkArray.h"
// QueuedOp_hkpworld: local type (was include/QueuedOp.h, which had no evidence of one real class); no method of it is bound to a named game function
class QueuedOp_hkpworld
{
public:
    unsigned char m_ucOperationType;
    int m_p;
    short m_kPointA;
    unsigned char m_kPointB;
};
// hkpWorld_MemUsageOut_hkpworld: local type (was include/hkpWorld_MemUsageOut.h, which had no evidence of one real class); no method of it is bound to a named game function
class hkpWorld_MemUsageOut_hkpworld {
public:
    int m_maxSize;
    int m_totalSize;
    void* m_maxObject;
};
#include "../../../../../include/hkBool.h"
#define _INCLUDED_MM2
// Exe 0x00c96a20 FUN_00c96a20: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; } __m128, LocalM128;
extern "C" LocalM128 __cdecl _mm_load_ss(const float*);
extern "C" void __cdecl _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 __cdecl _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 __cdecl _mm_shuffle_ps(LocalM128, LocalM128, int);
#include "../../../../../include/hkSimdReal.h"
#pragma pack(push, 1)
#define hkSimdRealParameter SharedSimdRealParameter
// Preserve public value-type ABI tags and packing while using shared members.
#define class struct
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkRotation.h"
#include "../../../../../include/hkQuaternion.h"
#include "../../../../../include/hkQsTransform.h"
#undef class
#pragma pack(pop)
#include "../../../../../include/hkaAnimation.h"
#include "../../../../../include/hkpWorld.h"
typedef short hkInt16;
typedef unsigned short hkUint16;
typedef unsigned char hkUint8;
#include "../../../../../include/hkMonitorStream.h"
#include "../../../../../include/MemoryManager.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMonitorStream.h"
#include "../../../../../include/NiBinaryStream.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMultiThreadCheck.h"
#include "../../../../../include/hkReferencedObject.h"
#define class struct
#include "../../../../../include/Pair.h"
#undef class
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkAabb.h"
#include "../../../../../include/hkDebugDisplayHandler.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkBaseObject.h"
#include "../../../../../include/AutoMemContext.h"
#include "../../../../../include/MEM_CONTEXT.h"
#include "../../../../../include/hkSingleton.h"
#include "../../../../../include/hkThreadMemory.h"
#include "../../../../../include/hkpBroadPhaseHandle.h"
#include "../../../../../include/hkpCdBody.h"
#include "../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../include/hkpShapeCollectionFilter.h"
#include "../../../../../include/hkpRayShapeCollectionFilter.h"
#include "../../../../../include/hkpRayCollidableFilter.h"
#define class struct
#include "../../../../../include/hkpCollisionFilter.h"
#undef class
#include "../../../../../include/hkpConstraintData.h"
#include "../../../../../include/hkpSimulationIsland.h"
#undef hkSimdRealParameter
#include "../../../../../include/NiStream.h"
#include "../../../../../include/bhkRefObject.h"
#include "../../../../../include/bhkWorld.h"
#include "../../../../../include/NiPoint3.h"
#include "../../../../../include/hkStackMemory.h"
#include "../../../../../include/hkVector4_S.h"
#include "../../../../../include/hkDebugDisplay.h"
#include "../../../../../include/hkpAction.h"
#include "../../../../../include/hkpEntity.h"
#include "../../../../../include/hkpPhantom.h"
#include "../../../../../include/hkpPhysicsSystem.h"
#include "../../../../../include/hkpLimitedHingeConstraintData.h"
inline void* hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* p = static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(nbytes));
    p->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
    return p;
}
inline void hkReferencedObject::operator delete(void* p, unsigned int nbytes)
{
    hkMemoryRouter::getInstance().heap().blockFree(p, nbytes);
}
inline void hkReferencedObject::operator delete(void* p)
{
    hkMemoryRouter::getInstance().heap().blockFree(p, static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags);
}
inline hkMultiThreadCheck::hkMultiThreadCheck() : m_uiThreadId(0xfffffff1), m_usMarkedForWrite(0x8000) {}

template <typename T>
__forceinline void hkMemoryAllocator::_bufFree(void* p, int numElem)
{
    bufFree(p, numElem * (int)sizeof(T));
}

// Allocator-dependent hkArray bodies are supplied by each unit using the shared declarations.


__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}

template <typename T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    this->_clearAndDeallocate(Allocator().get(this));
}

template <typename T>
__forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
        m_data[index] = m_data[m_iElementCount];
}

template <typename T>
__forceinline void hkArrayUtil::constructWithCopy(T* p, int n, const T& t, hkTypeIsPod)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <typename T>
__forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
        hkArrayUtil::_reserveMore(alloc, this, sizeof(T));
    hkArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, hkTypeIsPod());
    m_iElementCount++;
}

inline Pair::Pair() throw() {}
inline hkRotation::hkRotation() {}
inline hkQuaternion::hkQuaternion() {}

inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int written = (*(NIBINARYSTREAM_WRITEFN*)((char*)this + 12))(this, buffer, bytes, sizes, count);
    *(unsigned int*)((char*)this + 4) += written;
    return written;
}


struct FUN_00cf7c10 {
    void __thiscall PerformThisObjectOperation();
};

struct FUN_00c91120 {
    void __thiscall ExecutePendingOperations();
};

// @fnv 0x00c91120
void __thiscall FUN_00c91120::ExecutePendingOperations()
{
    *(int*)((char*)this + 0x8c) = 0;
    ((FUN_00cf7c10*)*(void**)((char*)this + 0x88))->PerformThisObjectOperation();
}

struct FUN_00c91180_Class {
    void EnterTlsGuard();
    void IncrementCounter();
};

// @fnv 0x00c91180
void FUN_00c91180_Class::IncrementCounter()
{
    EnterTlsGuard();
    ++(*(int*)((char*)this + 0xbc));
}

struct FUN_00c91250_Class {
    void* m_p;
    void hkpWorld_markTreeDirty();
};

// @fnv 0x00c91250
// src: HAVOK_LIB 0x00c91250
void FUN_00c91250_Class::hkpWorld_markTreeDirty()
{
    if (*(void**)((char*)this + 0x5c))
        ((void (__thiscall*)(void*, int))(*(void***)*(void**)((char*)this + 0x5c))[5])(*(void**)((char*)this + 0x5c), 0);
}

struct FUN_00cf6d20_Class {
    void __thiscall hkMultiThreadCheck_disableChecks();
};
struct FUN_00cf6d30_Class {
    void __thiscall ResetThreadCheck();
};
struct FUN_00c91280_Class {
    void __thiscall hkpWorld_setMultithreadedAccessChecking(int);
};
// Calls ResetThreadCheck on this+0xa8 and on the object at this+0x58+8 when a is zero, otherwise calls FUN_00cf6d20 on both.
// @fnv 0x00c91280
// src: HAVOK_LIB 0x00c91280
void __thiscall FUN_00c91280_Class::hkpWorld_setMultithreadedAccessChecking(int a)
{
    if (!a) {
        ((FUN_00cf6d30_Class*)((char*)this + 0xa8))->ResetThreadCheck();
        ((FUN_00cf6d30_Class*)(*(char**)((char*)this + 0x58) + 8))->ResetThreadCheck();
    } else {
        ((FUN_00cf6d20_Class*)((char*)this + 0xa8))->hkMultiThreadCheck_disableChecks();
        ((FUN_00cf6d20_Class*)(*(char**)((char*)this + 0x58) + 8))->hkMultiThreadCheck_disableChecks();
    }
}


struct Blk40 { float f[16]; };
template <class T> inline unsigned int WriteBinaryArray(NiBinaryStream& binstream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return binstream.BinaryWrite(pValue, uiNumEls * sizeof(T), &uiSize, uiNumEls);
}
template <class T> inline void SerializeValue(NiStream& kStream, const T& tValue)
{
    WriteBinaryArray(**(NiBinaryStream**)(((char*)&kStream + 4) + 0x24c), &tValue, 1);
}
// Two 0x40-byte constraint transforms at +0x20/+0x60 and a motor at +0xb0; unlike the 0x10-byte include/Data.h record.
struct ConstraintStreamStorage {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    Blk40 m_20;
    Blk40 m_60;
    unsigned char unkA0;
    unsigned char unkA1;
    char m_a2;
    unsigned char unkA3;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    int m_b0;
    unsigned int unkB4;
    unsigned int unkB8;
    int m_bc;
    unsigned int unkC0;
    int m_c4;
    int m_c8;
};

struct FUN_00caa840_shell {
    void* m_iWordAt00;
    ConstraintStreamStorage* m_data;
    void hkConstraintCinfo_SaveBinary(NiStream* ctx);
    void SaveShape(int n, NiStream* ctx);
    void WriteToStream(void* streamContext);
};

// @fnv 0x00caa840
void FUN_00caa840_shell::WriteToStream(void* streamContext)
{
    NiStream* ctx = (NiStream*)streamContext;
    hkConstraintCinfo_SaveBinary(ctx);
    ConstraintStreamStorage* d = m_data;
    SerializeValue(*ctx, d->m_20);
    SerializeValue(*ctx, d->m_60);
    SerializeValue(*ctx, d->m_c4);
    SerializeValue(*ctx, d->m_c8);
    SerializeValue(*ctx, d->m_bc);
    SaveShape(d->m_b0, ctx);
    if (d->m_b0)
        SerializeValue(*ctx, d->m_a2);
}

// Calls the virtual at offset 0x18 with "hkpContactMgrFactory", then the virtual at offset 0x1c on self.
// @fnv 0x00c90e40
// src: XBOX_PDB 0x00c90e40
void __stdcall hkpContactMgrFactory_calcContentStatistics(void* self, int arg)
{
    (*(void (__thiscall**)(void*, const char*))(*(unsigned int*)self + 0x18))(self, "hkpContactMgrFactory");
    (*(void (__thiscall**)(void*))(*(unsigned int*)self + 0x1c))(self);
}

struct FUN_00cf86e0_class {
    void hkpSimulation_setFrameTimeMarker(float);
};
// @fnv 0x00c91040
// src: HAVOK_LIB 0x00c91040
void __fastcall hkpWorld_setFrameTimeMarker(void* p, int edx, float afValue)
{
    ((FUN_00cf86e0_class*)*((char**)p + 2))->hkpSimulation_setFrameTimeMarker(afValue);
}

struct RefObj { void FUN_00c90510(); };
struct DDCC60World { void removeReference(); };
struct FUN_00c910d0_Class {
    void* m_iWordAt00; void* m_iWordAt04; void* m_8; void* m_iThirdValue; void* m_10; void* m_14; void* m_18;
    void* m_1c; void* m_20; void* m_24; void* m_28; void* m_2c; void* m_30; void* m_34;
    void* m_38; void* m_3c; void* m_40; void* m_44; void* m_48; void* m_4c; void* m_50;
    void* m_54; void* m_58; void* m_5c; void* m_60; void* m_64; void* m_68; void* m_6c;
    void* m_70; void* m_74; void* m_78; void* m_7c; void* m_80; void* m_84; void* m_88;
    void* m_8c; void* m_90; void* m_94; void* m_98; void* m_9c; void* m_a0; void* m_a4;
    void* m_a8; void* m_ac; void* m_b0; void* m_b4; void* m_b8; void* m_bc; void* m_c0;
    void* m_c4; void* m_c8; void* m_cc; void* m_d0; void* m_d4; void* m_d8; void* m_dc;
    void* m_e0; void* m_e4; void* m_e8; void* m_ec; void* m_f0; void* m_f4; void* m_f8;
    void* m_fc; void* m_100; void* m_104; void* m_108; void* m_10c; void* m_110; void* m_114;
    void* m_118; void* m_11c; void* m_120; void* m_124; void* m_128; void* m_12c; void* m_130;
    void* m_134; void* m_138; void* m_13c; void* m_140; void* m_144; void* m_148; void* m_14c;
    void* m_150; void* m_154; void* m_158; void* m_15c; void* m_160; void* m_164; void* m_168;
    void* m_16c; void* m_170; void* m_174; void* m_178; void* m_17c; void* m_180; void* m_184;
    void* m_188; void* m_18c; void* m_190; void* m_194; void* m_198; void* m_19c; void* m_1a0;
    void* m_1a4; void* m_1a8; void* m_1ac; void* m_1b0; void* m_1b4; void* m_1b8;
    void* m_1bc;
    void SetRefObject(void*);
};
// @fnv 0x00c910d0
void FUN_00c910d0_Class::SetRefObject(void* p)
{
    void* old = m_1bc;
    if (old) {
        (*(void (__thiscall*)(void*))(*(void***)old)[4])(old);
        ((DDCC60World*)m_1bc)->removeReference();
    }
    m_1bc = p;
    if (p) ((RefObj*)p)->FUN_00c90510();
}

struct FUN_00cf7ae0_Class {
    void hkpWorldOperationQueue_executeAllPendingBodyOperations();
};
struct FUN_00c91140_Class {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3C;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4C;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5C;
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6C;
    unsigned int m_70;
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7C;
    unsigned int m_80;
    unsigned int m_84;
    unsigned int m_88;
    unsigned int m_8C;
    int m_90;
    void UpdateFields_00c91140();
};
// @fnv 0x00c91140
// src: GUESS 0x00c91140 (confidence: low)
void FUN_00c91140_Class::UpdateFields_00c91140()
{
    m_90 = 0;
    ((FUN_00cf7ae0_Class*)m_88)->hkpWorldOperationQueue_executeAllPendingBodyOperations();
}

struct S_00cf7540_Ref {
    void* m_p;
};
struct S_00cf7540 {
    void __thiscall AddEntry(S_00cf7540_Ref*, S_00cf7540_Ref*, int, int);
};
struct FUN_00c91170_Class {
    void hkpWorld_addBodyOperation(S_00cf7540_Ref*, S_00cf7540_Ref*, int, int);
};
// @fnv 0x00c91170
// src: COMMUNITY 0x00c91170
void FUN_00c91170_Class::hkpWorld_addBodyOperation(S_00cf7540_Ref* a, S_00cf7540_Ref* b, int c, int d)
{
    (*(S_00cf7540**)((char*)this + 0x88))->AddEntry(a, b, c, d);
}

void __cdecl hkReferencedObject_unlockAll();
struct FUN_00c91190_Class {
    void __thiscall hkpWorld_unlock();
};
// @fnv 0x00c91190
// src: XBOX_PDB 0x00c91190
void __thiscall FUN_00c91190_Class::hkpWorld_unlock()
{
    --*(int*)((char*)this + 0xbc);
    hkReferencedObject_unlockAll();
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);

struct FUN_00c911d0_Class {
    void __thiscall EnterLock(void*);
};

// @fnv 0x00c911d0
void __thiscall FUN_00c911d0_Class::EnterLock(void* unused)
{
    void* cs = *(void**)(this + 0xb8);
    if (cs)
    {
        EnterCriticalSection(cs);
        return;
    }
}

extern void (__stdcall *DAT_00fdf05c)(void*);

struct FUN_00c911f0_Class {
    void UpdateState_00c911f0(void*);
};

// @fnv 0x00c911f0
// src: GUESS 0x00c911f0 (confidence: low)
void FUN_00c911f0_Class::UpdateState_00c911f0(void* p)
{
    void* pStoredKey = *(void**)((char*)this + 0xb8);
    if (pStoredKey)
        DAT_00fdf05c(pStoredKey);
}

namespace fnv_00c91f40 {
struct RefObj { void RetainReference(); void removeReference(); };
struct FUN_00c91f40_Class {
    void SetRefObj(RefObj* obj);
};
// @fnv 0x00c91f40
void FUN_00c91f40_Class::SetRefObj(RefObj* apRefObj)
{
    if (apRefObj) apRefObj->RetainReference();
    RefObj* old = *(RefObj**)((char*)this + 0x50);
    if (old) old->removeReference();
    *(RefObj**)((char*)this + 0x50) = apRefObj;
}
}  // namespace fnv_00c91f40


struct FUN_00c928c0_ActionList
{
    hkpAction** m_ppActions;
    int m_uiItemCount;
};

struct FUN_00c928c0_ActionOwner
{
    unsigned char m_auiShapeKeys[0x38];
    FUN_00c928c0_ActionList m_actionList;
};

struct FUN_00c928c0_Context
{
    unsigned char m_pad00[0x28];
    FUN_00c928c0_ActionOwner** m_owners1;
    unsigned int m_ownerCount1;
    unsigned char m_pad30[0x04];
    FUN_00c928c0_ActionOwner** m_owners2;
    unsigned int m_ownerCount2;
};

// Iterates both owner arrays in context and calls physicsSystem->FUN_00d06590 on every action in each owner's action list.
// @fnv 0x00c928c0
// src: HAVOK_LIB 0x00c928c0
void enumerateAllActionsInWorld(
    FUN_00c928c0_Context* context,
    hkpPhysicsSystem* physicsSystem)
{
    FUN_00c928c0_ActionOwner** owner = context->m_owners1;
    FUN_00c928c0_ActionOwner** end = owner + context->m_ownerCount1;

    while (owner != end)
    {
        FUN_00c928c0_ActionList* actions = &(*owner)->m_actionList;
        int action = 0;

        while (action < actions->m_uiItemCount)
        {
            physicsSystem->hkpPhysicsSystem_addAction(actions->m_ppActions[action]);
            ++action;
        }

        ++owner;
        end = context->m_owners1 + context->m_ownerCount1;
    }

    owner = context->m_owners2;
    end = owner + context->m_ownerCount2;

    while (owner != end)
    {
        FUN_00c928c0_ActionList* actions = &(*owner)->m_actionList;
        int action = 0;

        while (action < actions->m_uiItemCount)
        {
            physicsSystem->hkpPhysicsSystem_addAction(actions->m_ppActions[action]);
            ++action;
        }

        ++owner;
        end = context->m_owners2 + context->m_ownerCount2;
    }
}


struct FUN_00c92b50_Class {
    char pad[0x28];
    void* m_data;   // +0x28
    int m_iElementCount;     // +0x2c
    void __thiscall ComputeMemoryUsage(hkpWorld_MemUsageOut_hkpworld* out);
};

// Accumulates per-object memory sizes into out->m_totalSize and tracks the largest object in out->m_maxSize/m_maxObject.
// @fnv 0x00c92b50
void FUN_00c92b50_Class::ComputeMemoryUsage(hkpWorld_MemUsageOut_hkpworld* out)
{
    out->m_maxSize = 0;
    out->m_totalSize = 0;
    out->m_maxObject = 0;

    for (int i = m_iElementCount - 1; i >= 0; --i) {
        void* obj = ((void**)m_data)[i];
        int a = *(int*)((char*)obj + 0x1c);
        int b = *(int*)((char*)obj + 0x4c);
        int q = a / 80;
        int r = (q + q + 8);
        int size = r * 3 + *(int*)((char*)obj + 0x14);
        int size2 = (r + b * 8 + 10) << 4;
        size = ((size * 4 + 0x17) & 0xfffffff0) + size2 + *(int*)((char*)obj + 0xc);
        out->m_totalSize += size;
        if (size > out->m_maxSize) {
            out->m_maxSize = size;
            out->m_maxObject = obj;
        }
    }
}

struct CA8B80Command {
    unsigned char m_bType;
    void* m_p;
};
struct CA8B80Queue {
    void __thiscall Push(CA8B80Command*);
};
struct FUN_00c97510 {
    void __thiscall ProcessPointer(void*);
};
struct FUN_00c97f50_Class {
    void DispatchOrQueue(void* p);
};
// @fnv 0x00c97f50
void FUN_00c97f50_Class::DispatchOrQueue(void* p)
{
    if (*(unsigned int*)((char*)this + 0x94)) {
        CA8B80Command cmd;
        cmd.m_bType = 0xb;
        cmd.m_p = p;
        ((CA8B80Queue*)this)->Push(&cmd);
    } else {
        ((FUN_00c97510*)this)->ProcessPointer(p);
    }
}

extern int DAT_010c3bb8;
struct FUN_00c98350_Class {
    void* m_p;
    void* __thiscall InitAndMaybeFree(int);
};
void __cdecl _Deallocate(void*);
// @fnv 0x00c98350
void* __thiscall FUN_00c98350_Class::InitAndMaybeFree(int flags)
{
    m_p = &DAT_010c3bb8;
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct FUN_00c983e0_Class {
    void ForEachCall(int a, int b, int c, int d, int e);
};

// Locks the critical section, calls the second virtual method of each object in the array with the five arguments, then unlocks.
// @fnv 0x00c983e0
void FUN_00c983e0_Class::ForEachCall(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5)
{
    EnterCriticalSection(*(void**)((char*)this + 0x14));
    for (int i = 0; i < *(int*)((char*)this + 0xc); ++i) {
        void* obj = *(void**)(*(char**)((char*)this + 8) + i * 4);
        void** vtbl = *(void***)obj;
        typedef void (__thiscall* Fn)(void*, int, int, int, int, int);
        ((Fn)vtbl[1])(obj, aiArg1, aiArg2, aiArg3, aiArg4, aiArg5);
    }
    LeaveCriticalSection(*(void**)((char*)this + 0x14));
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct FUN_00c984a0_Class {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    void hkDebugDisplay_setGeometryColor(int a1, int a2, int a3);
};

// Locks the critical section, calls virtual method slot 3 on each of unk0C objects in the unk08 array with a1, a2, a3, then unlocks.
// @fnv 0x00c984a0
// src: HAVOK_LIB 0x00c984a0
void FUN_00c984a0_Class::hkDebugDisplay_setGeometryColor(int aiArg1, int aiArg2, int aiArg3)
{
    EnterCriticalSection((void*)unk14);
    for (int i = 0; i < unk0C; ++i) {
        void* obj = *(void**)((char*)unk08 + i * 4);
        void** vtbl = *(void***)obj;
        ((void (__thiscall*)(void*, int, int, int))vtbl[3])(obj, aiArg1, aiArg2, aiArg3);
    }
    LeaveCriticalSection((void*)unk14);
}

struct FUN_00c98540_Class {
    void CallAllWithArgs(int a, int b, int c);
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

// @fnv 0x00c98540
void FUN_00c98540_Class::CallAllWithArgs(int aiArg1, int aiArg2, int aiArg3)
{
    void* pLock = *(void**)((char*)this + 0x14);
    EnterCriticalSection(pLock);
    int i = 0;
    if (*(int*)((char*)this + 0xc) > 0) {
        do {
            void* obj = *(void**)(*(int*)((char*)this + 8) + i * 4);
            void** vtbl = *(void***)obj;
            void (__thiscall* fn)(void*, int, int, int) = (void (__thiscall*)(void*, int, int, int))vtbl[5];
            fn(obj, aiArg1, aiArg2, aiArg3);
            ++i;
        } while (i < *(int*)((char*)this + 0xc));
    }
    void* pLock2 = *(void**)((char*)this + 0x14);
    LeaveCriticalSection(pLock2);
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection);

struct FUN_00c98600_Class {
    unsigned int unk00;
    unsigned int unk04;
    void* m_ppData;      // +0x08
    int m_uiItemCount;        // +0x0C
    unsigned int unk10;
    void* m_cs;         // +0x14
    void CallVirtualOnAll(int a, int b, int c, int d, int e, int f, int g, int h);
};

// @fnv 0x00c98600
void FUN_00c98600_Class::CallVirtualOnAll(int aiArg0, int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5, int aiArg6, int aiArg7)
{
    EnterCriticalSection(m_cs);
    for (int i = 0; i < m_uiItemCount; ++i) {
        void** arr = (void**)m_ppData;
        void* obj = arr[i];
        void** vtbl = *(void***)obj;
        typedef void (__thiscall* Fn)(void*, int, int, int, int, int, int, int, int);
        Fn fn = (Fn)vtbl[7];
        fn(obj, aiArg0, aiArg1, aiArg2, aiArg3, aiArg4, aiArg5, aiArg6, aiArg7);
    }
    LeaveCriticalSection(m_cs);
}

struct FUN_00c990b0_Class {
    void hkDebugDisplay_displayText(int a, int b, int c, int d);
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

// Locks the critical section, calls virtual method at vtable offset 0x2c on each element of the array, then unlocks.
// @fnv 0x00c990b0
// src: HAVOK_LIB 0x00c990b0
void FUN_00c990b0_Class::hkDebugDisplay_displayText(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    EnterCriticalSection(*(void**)((char*)this + 0x14));
    int i = 0;
    if (*(int*)((char*)this + 0xc) > 0) {
        do {
            void* obj = *(void**)(*(int*)((char*)this + 8) + i * 4);
            void** ppVtable = *(void***)obj;
            void (__thiscall* fn)(void*, int, int, int, int) = (void (__thiscall*)(void*, int, int, int, int))ppVtable[0x2c / 4];
            fn(obj, aiArg1, aiArg2, aiArg3, aiArg4);
            ++i;
        } while (i < *(int*)((char*)this + 0xc));
    }
    LeaveCriticalSection(*(void**)((char*)this + 0x14));
}

extern "C" __declspec(dllimport) void __stdcall FUN_00fdf05c(void*);
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf100(void*);

struct FUN_00c995f0_Class {
    void hkDebugDisplay_clear();
};

// Calls FUN_00fdf05c and FUN_00fdf100 on the pointer at offset 0x14 and clears the int at offset 0xc.
// @fnv 0x00c995f0
// src: HAVOK_LIB 0x00c995f0
void FUN_00c995f0_Class::hkDebugDisplay_clear()
{
    void* p = *(void**)((char*)this + 0x14);
    FUN_00fdf05c(p);
    p = *(void**)((char*)this + 0x14);
    *(int*)((char*)this + 0xc) = 0;
    FUN_00fdf100(p);
}

struct FUN_00c90f30_Class {
    int unk00;
    void* __thiscall SetUnk00();
};
// @fnv 0x00c90f30
// src: GUESS 0x00c90f30 (confidence: low)
void* FUN_00c90f30_Class::SetUnk00() { unk00 = 70; return this; }

struct CpuScalar {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    float value;
};
struct CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    CpuScalar* value;
    float hkpWorld_getCurrentTime();
};
// @fnv 0x00c91020
// src: XBOX_PDB 0x00c91020
float CpuObject::hkpWorld_getCurrentTime()
{
    return value->value;
}

namespace fnv_00c91030 {
struct CpuScalar {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    float value;
};
struct CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    CpuScalar* value;
    float hkpWorld_getCurrentPsiTime();
};
// @fnv 0x00c91030
// src: COMMUNITY 0x00c91030
float CpuObject::hkpWorld_getCurrentPsiTime()
{
    return value->value;
}
}  // namespace fnv_00c91030

struct FUN_00cf86f0_Class {
    void __thiscall IsFieldEqual();
};

struct FUN_00c91060_Class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    FUN_00cf86f0_Class* m_8;
    void __thiscall hkpWorld_isSimulationAtMarker();
};

// @fnv 0x00c91060
// src: COMMUNITY 0x00c91060
void __thiscall FUN_00c91060_Class::hkpWorld_isSimulationAtMarker()
{
    m_8->IsFieldEqual();
}

struct Inner
{
    void Tail();
};

struct FUN_00c91070_cls
{
    int unk00;
    int unk04;
    Inner* m_08;
    void ForwardCall_00c91070();
};

// @fnv 0x00c91070
// src: GUESS 0x00c91070 (confidence: low)
void FUN_00c91070_cls::ForwardCall_00c91070()
{
    m_08->Tail();
}

namespace fnv_00c91080 {
struct Inner
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int Tail(int a);
};

struct FUN_00c91080_cls
{
    int unk00;
    int unk04;
    Inner* m_08;
    int InvokeVirtualMethod_00c91080(int a);
};

// @fnv 0x00c91080
// src: GUESS 0x00c91080 (confidence: low)
int FUN_00c91080_cls::InvokeVirtualMethod_00c91080(int a)
{
    return m_08->Tail(a);
}
}  // namespace fnv_00c91080

struct FnvCpu_FUN_00c91090_CpuInterface {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00c91090_CpuOwner {
    unsigned int unk00;
    unsigned int unk04;
    FnvCpu_FUN_00c91090_CpuInterface* target;
    void ForwardCall_00c91090(int arg0);
};
// @fnv 0x00c91090
// src: GUESS 0x00c91090 (confidence: low)
void FnvCpu_FUN_00c91090_CpuOwner::ForwardCall_00c91090(int arg0)
{
    target->Invoke(arg0);
}

namespace fnv_00c91110 {
struct CpuObject {
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
    int value;
    int GetValue();
};
// @fnv 0x00c91110
// src: GUESS 0x00c91110 (confidence: low)
int CpuObject::GetValue()
{
    return value;
}
}  // namespace fnv_00c91110

struct PendingOperations {
    void __thiscall FUN_00cf7690();
};

struct WorldWithPending : hkpWorld {
    void __thiscall hkpWorld_queueOperation();
};

// @fnv 0x00c91160
// src: XBOX_PDB 0x00c91160
void __thiscall WorldWithPending::hkpWorld_queueOperation()
{
    ((PendingOperations*)m_pPendingOperations)->FUN_00cf7690();
}

struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void Forward(int a);
};

struct FUN_00c91270_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    Target* m_5C;
    void ahkpWorld_updateKdTree(int a);
};

// @fnv 0x00c91270
// src: COMMUNITY 0x00c91270
void FUN_00c91270_cls::ahkpWorld_updateKdTree(int a)
{
    m_5C->Forward(a);
}

struct FUN_00c98250_Class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* __thiscall hkpNullContactMgrFactory_createContactMgr(int, int, int);
};

// @fnv 0x00c98250
// src: XBOX_PDB 0x00c98250
void* __thiscall FUN_00c98250_Class::hkpNullContactMgrFactory_createContactMgr(int, int, int)
{
    return (void*)((char*)this + 8);
}

// @fnv 0x00c982a0
// src: GUESS 0x00c982a0 (confidence: low)
void __stdcall Object_UpdateFields_00c982a0(char* pFlag, int a2, int a3, int a4, int a5, int a6)
{
    *pFlag = 1;
}

// FUN_00c982b0: stdcall with 8 stack parameters; writes 1 through the first parameter pointer.
// @fnv 0x00c982b0
// src: GUESS 0x00c982b0 (confidence: high)
void __stdcall hkpWorld_SetOutputFlag(unsigned char* flag, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    *flag = 1;
}

extern __declspec(thread) int g_tlsMemContext;
extern unsigned int DAT_011afe7c;

struct ScopedMemContext {
    int m_saved;
    ScopedMemContext(int ctx) { m_saved = g_tlsMemContext; g_tlsMemContext = ctx; }
    ~ScopedMemContext() { g_tlsMemContext = m_saved; }
};

struct C67Owner {
    int unk00;
    int unk04;
    int unk08;
    struct C67Flags* unk0C;
};

struct C67Flags {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int unk10;
    void clearFlag20() { unk10 &= ~0x20; }
};
struct C67Collidable {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char m_type;
    C67Owner* getOwner() { return (C67Owner*)((char*)this + m_iOwnerOffset); }
};

struct C67Entry {
    void removeReference();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C67Collidable m_kCollidable;
};

inline C67Owner* getEntityOwner(C67Collidable* coll)
{
    if (coll->m_type == 1)
        return coll->getOwner();
    return 0;
}

struct C67Sink {
    void RemoveEntities(C67Entry** entries, unsigned int count);
};

class FUN_00c67aa0_Class {
public:
    virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03();
    virtual void vf04(); virtual void vf05(); virtual void vf06(); virtual void vf07();
    virtual void vf08(); virtual void vf09(); virtual void vf10(); virtual void vf11();
    virtual void vf12(); virtual void vf13(); virtual void vf14(); virtual void vf15();
    virtual void vf16(); virtual void vf17(); virtual void vf18(); virtual void vf19();
    virtual void vf20(); virtual void vf21(); virtual void vf22(); virtual void vf23();
    virtual void vf24(); virtual void vf25(); virtual void vf26(); virtual void vf27();
    virtual void vf28(); virtual void vf29(); virtual void vf30(); virtual void vf31();
    virtual void vf32(); virtual void vf33(); virtual void vf34(); virtual void vf35();
    virtual void vf36();
    virtual C67Sink* getSink();
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48;
    C67Entry** m_entries;
    unsigned int m_iNumberOfEntries;
    void FlushEntries();
};

// @fnv 0x00c67aa0
void FUN_00c67aa0_Class::FlushEntries()
{
    ScopedMemContext ctx(0x10);
    if (m_iNumberOfEntries > 0) {
        if (m_iNumberOfEntries >= 3000)
            m_iNumberOfEntries = 3000;
        unsigned int count = m_iNumberOfEntries;
        unsigned int num = DAT_011afe7c;
        if (count < num)
            num = count;
        unsigned int start = count - num;
        C67Sink* sink = getSink();
        if (sink) {
            sink->RemoveEntities(&m_entries[start], num);
            for (unsigned int i = start; i < m_iNumberOfEntries; i++) {
                C67Owner* owner = getEntityOwner(&m_entries[i]->m_kCollidable);
                if (owner) {
                    C67Flags* f = owner->unk0C;
                    if (f)
                        f->clearFlag20();
                }
                m_entries[i]->removeReference();
                m_entries[i] = 0;
            }
            m_iNumberOfEntries = start;
        }
    }
}

struct WorldExt : public hkpWorld {
    float hkpWorld_getCurrentTime() throw();
    void hkpWorld_setFrameTimeMarker(float f) throw();
    void hkpWorld_advanceTime() throw();
    bool hkpWorld_isSimulationAtMarker() throw();
    float hkpWorld_getCurrentPsiTime() throw();
    void hkpWorld_stepDeltaTime(float f) throw();
    void hkpWorld_stepMultithreaded(int a, int b, float f) throw();
    void FUN_00c91120() throw();
    void UpdateFields_00c91140() throw();
};

struct Class_012677d0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void EnsureObjectsCreated(unsigned char val) throw();
};

extern float DAT_012677c4;
extern char DAT_012677a0;
extern int DAT_012677c8;
extern unsigned char DAT_012677a2;
extern unsigned int DAT_011afe80;
extern float DAT_011afe68;
extern unsigned char DAT_01267b2c;
extern Class_012677d0* DAT_012677d0;
extern float DAT_01267b38;
extern float DAT_011ac3a0;
extern float DAT_012677ac;
extern float DAT_011afe64;
extern char DAT_012677cd;

// This world operation uses the existing slot-37 dispatch.
inline WorldExt* bhkWorld::GetHkpWorld() throw()
{
    typedef WorldExt* (__thiscall* GetWorld)(bhkWorld*);
    return ((GetWorld)(*(void***)this)[37])(this);
}

// Operations not yet declared by the shared world header.
struct BhkWorldOperations : bhkWorld {
    void bhkWorld_AddEntities(void* p, unsigned int count) throw();
    void bhkWorld_AddBatchedActions() throw();
    void bhkWorld_UpdateActions(float f) throw();
    void bhkWorld_ScaleSolverInfo() throw();
    void bhkWorld_UpdateListeners(float f) throw();
    void bhkWorld_UpdateDebugger() throw();
};

// @fnv 0x00c6ae70
bool bhkWorld::StepSimulation() {
    DAT_012677c4 = 0.0f;
    DAT_012677a0 = 1;
    DAT_012677c8 = 0;
    bool result = false;

    if (this->m_uiValueAt30 > 0) {
        if (!DAT_012677a2) {
            if (this->m_uiValueAt30 >= 0xbb8) {
                this->m_uiValueAt30 = 0xbb8;
            }
            unsigned int val = this->m_uiValueAt30;
            unsigned int count = DAT_011afe80;
            if (val < count) {
                count = val;
            }
            unsigned int remaining = val - count;
            ((BhkWorldOperations*)this)->bhkWorld_AddEntities(&((void**)this->m_pObjectAt2C)[remaining], count);
            this->m_uiValueAt30 = remaining;
            DAT_012677a2 = 1;
        }
        this->ProcessConstraints();
        ((BhkWorldOperations*)this)->bhkWorld_AddBatchedActions();
    }

    if (this->bEnabled != 0 && DAT_011afe68 > 0.0f) {
        WorldExt* world = this->GetHkpWorld();
        bool isMultithreaded = (world->m_iMaxEntriesPerNarrowphaseToiTask == 3);
        if (isMultithreaded) {
            DAT_012677d0->EnsureObjectsCreated(DAT_01267b2c);
        }
        DAT_012677ac = DAT_011ac3a0 * DAT_01267b38;
        ((BhkWorldOperations*)this)->bhkWorld_UpdateActions(DAT_011afe64);
        ((BhkWorldOperations*)this)->bhkWorld_ScaleSolverInfo();

        this->GetHkpWorld();
        if (world->m_iCriticalOperationsLockCount == 0 && world->m_bBlockExecutingPendingOperations == 0) {
            if (world->m_iPendingOperationCount != 0) {
                world->FUN_00c91120();
            }
            if (world->m_iPendingOperationQueueCount == 1 && world->m_iQueuedOperationCount != 0) {
                world->UpdateFields_00c91140();
            }
        }

        this->GetHkpWorld();
        world->hkpWorld_getCurrentTime();
        world->hkpWorld_setFrameTimeMarker(DAT_011afe64);
        world->hkpWorld_advanceTime();
        while (!world->hkpWorld_isSimulationAtMarker()) {
            world->hkpWorld_getCurrentPsiTime();
            if (!isMultithreaded) {
                world->hkpWorld_stepDeltaTime(DAT_012677ac);
            } else {
                world->hkpWorld_stepMultithreaded(DAT_012677d0->unk14, DAT_012677d0->unk18, DAT_012677ac);
            }
        }

        ((BhkWorldOperations*)this)->bhkWorld_UpdateListeners(DAT_011afe68);
        ((BhkWorldOperations*)this)->bhkWorld_UpdateDebugger();
        result = true;
    }

    if (this->m_uiValueAt50 > 0) {
        this->FlushEntries();
    }

    if (DAT_012677cd != 0) {
        this->SetProcessEnabled(1);
        DAT_012677cd = 0;
    }

    DAT_012677a0 = 0;
    return result;
}

// 0x00c910a0  ret 4
// @fnv 0x00c910a0
// src: COMMUNITY 0x00c910a0
void __stdcall nullsub_5(int) {
}

// @fnv 0x00c911a0
// src: GUESS 0x00c911a0 (confidence: high)
void Object_DoNothing_00c911a0()
{
}

extern void (__stdcall *DAT_00fdf100)(void*);

struct FUN_00c91230_World : hkpWorld {
    void __thiscall ProcessState_00c91230(void* param);
};

// @fnv 0x00c91230
// src: GUESS 0x00c91230 (confidence: low)
void __thiscall FUN_00c91230_World::ProcessState_00c91230(void* param) {
    if (m_pModifyConstraintCriticalSection != 0) {
        DAT_00fdf100(m_pModifyConstraintCriticalSection);
    }
}

struct FUN_00c912c0_Class : hkpWorld {
    unsigned int hkpWorld_getMultithreadedAccessChecking();
};
// @fnv 0x00c912c0
// src: HAVOK_LIB 0x00c912c0
unsigned int FUN_00c912c0_Class::hkpWorld_getMultithreadedAccessChecking()
{
    volatile unsigned short* markCount = &m_kMultiThreadCheck.m_usMarkedForWrite;
    unsigned char highBit = static_cast<unsigned char>(*markCount >> 15);
    return highBit & 1;
}

struct Comparator {
    virtual void unused_00();
    virtual void unused_01();
    virtual void unused_02();
    virtual void unused_03();
    virtual void unused_04();
    virtual void unused_05();
    virtual void unused_06();
    virtual void unused_07();
    virtual void unused_08();
    virtual void unused_09();
    virtual void unused_0a();
    virtual void unused_0b();
    virtual void unused_0c();
    virtual void unused_0d();
    virtual void unused_0e();
    virtual void unused_0f();
    virtual void unused_10();
    virtual void unused_11();
    virtual void unused_12();
    virtual bool accepts(const void* left, const void* right);
};
struct FilterCore {
    virtual void reserved();
    virtual unsigned char* evaluate(unsigned char* answer, const void* left, const void* right);
};
struct FilterOwner {
    void* unknown_00;
    void* unknown_04;
    FilterCore core;
};

struct OpPacket {
    unsigned char opcode;
    const void* left;
    const void* right;
};
struct EventSink {
    void hkpTypedBroadPhaseDispatcher_addPairs(const Pair* p, int action, FilterCore* core);
};
int __cdecl FindEntryValue(const void*, const void*);
struct FUN_00c913b0_Class {
    void* unknown_00;
    void* unknown_04;
    void* unknown_08;
    void* unknown_0c;
    void* unknown_10;
    void* unknown_14;
    void* unknown_18;
    void* unknown_1c;
    void* unknown_20;
    void* unknown_24;
    void* unknown_28;
    void* unknown_2c;
    void* unknown_30;
    void* unknown_34;
    void* unknown_38;
    void* unknown_3c;
    void* unknown_40;
    void* unknown_44;
    void* unknown_48;
    void* unknown_4c;
    void* unknown_50;
    void* unknown_54;
    Comparator* m_comparator;
    void* unknown_5c;
    void* unknown_60;
    EventSink* m_callback;
    void* unknown_68;
    void* unknown_6c;
    void* unknown_70;
    void* unknown_74;
    void* unknown_78;
    FilterOwner* m_iFilter;
    void* unknown_80;
    void* unknown_84;
    void* unknown_88;
    void* unknown_8c;
    void* unknown_90;
    void* m_pDataAtOffset94;
    void hkpWorld_queueOperation(const OpPacket* packet);
    void ProcessPair(const void* left, const void* right);
};
// @fnv 0x00c913b0
void FUN_00c913b0_Class::ProcessPair(const void* left, const void* right)
{
    OpPacket command;
    int pairStorage[2];
    Pair& pair = *reinterpret_cast<Pair*>(pairStorage);
    if (m_pDataAtOffset94) {
        command.opcode = 0x13;
        command.left = left;
        command.right = right;
        hkpWorld_queueOperation(&command);
        return;
    }

    const char* a = static_cast<const char*>(left);
    const char* b = static_cast<const char*>(right);
    const void* primaryB = b + 0x24;
    const void* primaryA = a + 0x24;
    if (m_comparator->accepts(primaryA, primaryB)) {
        unsigned char answer;
        const void* secondaryB = b + 0x10;
        const void* secondaryA = a + 0x10;
        if (*m_iFilter->core.evaluate(&answer, secondaryA, secondaryB)) {
            if (!FindEntryValue(secondaryA, secondaryB)) {
                pair.a = (int)primaryA;
                pair.b = (int)primaryB;
                m_callback->hkpTypedBroadPhaseDispatcher_addPairs(&pair, 1, m_iFilter ? &m_iFilter->core : 0);
            }
        }
    }
}

struct Sh00c91160 { void hkpWorld_queueOperation(void* rec); };


struct SimVtbl
{
    void* slot[12];
    void (__thiscall* invoke)(void*, int, int, void*, int);   // +0x30
};

struct Sim
{
    SimVtbl* m_vtbl;
};

struct WorldQ
{
    char pad0[8];
    Sim* m_pSimulation;                              // +0x08
    char pad_c[0x94 - 0xc];
    int m_iCriticalOperationsLockCount;               // +0x94

    void __thiscall DispatchOp(int a0, int a1, int a2);
};

// @fnv 0x00c91470
void WorldQ::DispatchOp(int aiArg0, int aiArg1, int aiArg2)
{
    if (m_iCriticalOperationsLockCount)
    {
        QueuedOp_hkpworld op;
        op.m_ucOperationType = 0x17;
        op.m_p = aiArg0;
        op.m_kPointA = (short)aiArg1;
        op.m_kPointB = (unsigned char)aiArg2;
        ((Sh00c91160*)this)->hkpWorld_queueOperation(&op);
        return;
    }
    Sim* sim = m_pSimulation;
    sim->m_vtbl->invoke(sim, aiArg0, aiArg1, this, aiArg2);
}

class hkpWorldC914;

void __cdecl hkSweptTransformUtil_setTimeInformation(float fA, float fB, int* piOut) throw();

struct hkpCollidableQualityC914 {
    void SetFlagBits(unsigned char ucA, unsigned char ucB, unsigned char ucC) throw();
};

// The shared layout is complete; this unit still needs this call declaration.
struct EntityWorldAccess : hkpEntity {
    void UpdateBoundingVolume(hkpWorldC914* world, const void* shape) throw();
};

struct hkWorldOperationBaseC914 {
    unsigned char m_type;
};

struct hkWorldOperationAddEntityC914 : public hkWorldOperationBaseC914 {
    hkpEntity* m_pEntity;
    int m_iActivationState;

    hkWorldOperationAddEntityC914() { m_type = 1; }
};

class hkpWorldC914 {
public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_98;
    bool m_bBlockExecutingPendingOperations;
    bool m_bBlockExecutingPendingOperationQueues;
    char m_9e;
    char m_9f;
    int m_a0;
    int m_iPendingOperationQueueCount;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    int m_uiLastEntityUid;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    int m_198;
    int m_19c;
    int m_1a0;
    int m_1a4;
    int m_1a8;
    int m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    int m_1d0;
    int m_1d4;
    int m_1d8;
    int m_1dc;
    int m_1e0;
    int m_1e4;
    int m_1e8;
    int m_1ec;
    int m_1f0;
    int m_1f4;
    int m_1f8;
    int m_1fc;
    int m_200;
    int m_204;
    int m_208;
    int m_20c;
    int m_210;
    int m_214;
    int m_218;
    int m_21c;
    int m_220;
    int m_224;
    int m_228;
    int m_22c;
    int m_230;
    int m_234;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    int m_248;
    int m_24c;
    int m_250;
    int m_254;
    int m_258;
    int m_25c;
    int m_260;
    int m_264;
    int m_268;
    int m_26c;
    int m_270;
    int m_274;
    int m_278;
    int m_27c;
    int m_280;
    int m_284;
    int m_288;
    int m_28c;
    int m_290;
    int m_294;
    int m_298;
    int m_29c;
    int m_2a0;
    int m_2a4;
    int m_2a8;
    int m_2ac;
    int m_2b0;
    int m_2b4;
    int m_2b8;
    int m_2bc;
    int m_2c0;
    int m_2c4;
    int m_2c8;
    int m_2cc;
    int m_2d0;
    int m_2d4;
    int m_2d8;
    int m_2dc;
    int m_2e0;
    int m_2e4;
    int m_2e8;
    int m_2ec;
    int m_2f0;
    int m_2f4;
    int m_2f8;
    int m_2fc;
    int m_300;
    char m_304;
    unsigned char m_305;
    unsigned char m_306;
    unsigned char m_307;

    bool areCriticalOperationsLocked() const { return m_iCriticalOperationsLockCount != 0; }
    void lockCriticalOperations() { m_iCriticalOperationsLockCount++; }
    void unlockAndAttemptToExecutePendingOperations()
    {
        m_iCriticalOperationsLockCount--;
        if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
            if (m_iPendingOperationCount)
                FUN_00c91120();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
                UpdateFields_00c91140();
        }
    }

    void FUN_00c91120() throw();
    void UpdateFields_00c91140() throw();
    void hkpWorld_queueOperation(const hkWorldOperationBaseC914& kOperation) throw();

    hkpEntity* hkpWorld_addEntity(hkpEntity* pkEntity, int iInitialActivationState) throw();
};

void __cdecl hkpWorldOperationUtil_addEntitySI(hkpWorldC914* pkWorld, hkpEntity* pkEntity, int iInitialActivationState) throw();
void __cdecl hkpWorldOperationUtil_addEntityBP(hkpWorldC914* pkWorld, hkpEntity* pkEntity) throw();
void __cdecl NotifyEntityAdded(hkpWorldC914* pkWorld, hkpEntity* pkEntity) throw();
void __cdecl hkpEntityCallbackUtil_fireEntityAdded(hkpEntity* pkEntity) throw();

// @fnv 0x00c914d0
// src: HAVOK_LIB 0x00c914d0
hkpEntity* hkpWorldC914::hkpWorld_addEntity(hkpEntity* pkEntity, int iInitialActivationState) throw()
{
    if (areCriticalOperationsLocked()) {
        hkWorldOperationAddEntityC914 kOp;
        kOp.m_pEntity = pkEntity;
        kOp.m_iActivationState = iInitialActivationState;
        hkpWorld_queueOperation(kOp);
        return 0;
    }

    ((EntityWorldAccess*)pkEntity)->UpdateBoundingVolume(this, pkEntity->m_kCollidable.m_pCollisionShape);
    if (pkEntity->m_kCollidable.m_pMotionState == 0)
        pkEntity->m_kCollidable.m_pMotionState = (*(const void* (__thiscall**)(hkpEntity*))(*(char**)pkEntity + 0x10))(pkEntity);

    hkSweptTransformUtil_setTimeInformation(0.0f, 0.0f, (int*)&pkEntity->m_pMotionState.m_kMotionState.m_kMotionTransform);
    pkEntity->m_pMotionState.m_ausDeactivationNumInactiveFrames[0] = 0;
    pkEntity->m_pMotionState.m_ausDeactivationNumInactiveFrames[1] = 0;
    m_bBlockExecutingPendingOperationQueues = false;
    pkEntity->m_uiUniqueId = ++m_uiLastEntityUid;
    pkEntity->addReference();
    hkpWorldOperationUtil_addEntitySI(this, pkEntity, iInitialActivationState);
    ((hkpCollidableQualityC914*)&pkEntity->m_pMotionState)->SetFlagBits(m_305, m_306, m_307);

    lockCriticalOperations();
    m_bBlockExecutingPendingOperationQueues = true;
    hkpWorldOperationUtil_addEntityBP(this, pkEntity);
    NotifyEntityAdded(this, pkEntity);
    hkpEntityCallbackUtil_fireEntityAdded(pkEntity);
    unlockAndAttemptToExecutePendingOperations();
    return pkEntity;
}

struct PointerArray {
    void** elements;
    int size;
    __forceinline int Find(void* target) const {
        for(int index=0;index<size;++index) {
            if(elements[index]==target) return index;
        }
        return -1;
    }
};
struct ObjectTable {
    unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
unsigned int unk080;
unsigned int unk084;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
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
    PointerArray pointers;
    void RemovePointer(void* value);
};
// Finds value in the pointers array and clears its slot to null.
// @fnv 0x00c91840
void ObjectTable::RemovePointer(void* value) {
    int index=pointers.Find(value);
    pointers.elements[index]=0;
}

struct SearchArray {
unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
unsigned int unk080;
unsigned int unk084;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
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
int* items;
int count;
void ClearValue(int value);
int find(int value) const { for(int i=0;i<count;++i){if(items[i]==value)return i;}return -1;}
};
// Finds value in items and sets the matching entry to 0.
// @fnv 0x00c918e0
void SearchArray::ClearValue(int value){items[find(value)]=0;}

struct EntryListNode {
    int* volatile entries;
    int count;
    int findIndex(int value) const {
        int total = count;
        int index = 0;
        if (total > 0) {
            int* cursor = entries;
            do {
                if (*cursor == value)
                    return index;
                ++index;
                ++cursor;
            } while (index < total);
        }
        return -1;
    }
};
struct FUN_00c919d0_Class {
    void hkpWorld_removeIslandPostIntegrateListener(int value);
};
// @fnv 0x00c919d0
// src: HAVOK_LIB 0x00c919d0
void FUN_00c919d0_Class::hkpWorld_removeIslandPostIntegrateListener(int value) {
    EntryListNode& list=*(EntryListNode*)((char*)this+0x188);
    list.entries[list.findIndex(value)]=0;
}

struct CD22Registry {
    void __thiscall IncrementCounter();
    void __thiscall hkpWorld_unlock();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
    int hkpWorld_collide();
};

// @fnv 0x00c91ba0
// src: HAVOK_LIB 0x00c91ba0
int CD22Registry::hkpWorld_collide()
{
    IncrementCounter();
    int r = ((CD22Registry*)*(void**)((char*)this + 8))->v5();
    hkpWorld_unlock();
    return r;
}

struct hkShapeC927 {
    unsigned short m_type;
    unsigned short unk02;
    int unk04[4];
    hkShapeC927* m_pChildAtom;
};

struct hkRecordC927 {
    void* m_object;
    int unk04[2];
    hkShapeC927* m_pCollisionShape;
    int unk10[8];
};

struct hkRecordListC927 {
    hkRecordC927* m_data;
    unsigned short m_iElementCount;
};

struct hkEntityC927 {
    char unk00[0xac];
    hkRecordListC927 m_records;
};

struct hkWorldC927 {
    int unk00[0x12];
    hkEntityC927** m_kActorEntries;
    int m_iActorEntryCount;
};

class hkSetC927 : public hkpPhysicsSystem {
public:
    void hkpPhysicsSystem_addConstraint(void* object);
};

// @fnv 0x00c927f0
// src: HAVOK_LIB 0x00c927f0
void __cdecl enumerateAllConstraintsInIsland(hkWorldC927* world, hkSetC927* set)
{
    for (int i = 0; i < world->m_iActorEntryCount; i++) {
        hkRecordListC927* list = &world->m_kActorEntries[i]->m_records;
        for (int j = 0; j < list->m_iElementCount; j++) {
            hkRecordC927& rec = list->m_data[j];
            const hkShapeC927* shape = rec.m_pCollisionShape;
            while (shape->m_type >= 0x17)
                shape = shape->m_pChildAtom;
            if (shape->m_type != 0x16)
                set->hkpPhysicsSystem_addConstraint(rec.m_object);
        }
    }
}

// the pointer arrays below are hkArray<void*> (include/hkArray.h)


struct PendingOps { 
    void* m_vtbl; void* m_04; void* m_08; void* m_0c; 
    hkArray<void*> m_10; hkArray<void*> m_1c;
};
struct HandlerRegistration { void* data; void* other; HandlerRegistration* next; };
struct WorldSave {
    void* m_vtbl; unsigned short m_usMemSizeAndFlags; short m_sReferenceCount;
    void* m_pSimulation; unsigned int m_unknown0c;
    hkVector4 m_kGravity;
    void* m_pFixedIsland; void* m_pFixedRigidBody;
    hkArray<void*> m_kActiveSimulationIslands;
    hkArray<void*> m_kInactiveSimulationIslands;
    hkArray<void*> m_kDirtySimulationIslands;
    void* m_pMaintenanceManager; void* m_pMemoryWatchDog;
    unsigned char m_bAssertOnRunningOutOfSolverMemory;
    void* m_pJobSemaphore; void* m_pKdTreeManager;
    unsigned char m_bUseKdTree;
    void* m_pBroadPhaseDispatcher; void* m_pPhantomBroadPhaseListener;
    void* m_pEntityEntityBroadPhaseListener; void* m_pBroadPhaseBorderListener;
    void* m_pMultithreadedSimulationJobData;
    void* m_pCollisionInput; void* m_pCollisionFilter; void* m_pDispatcher;
    void* m_pConvexListCollisionFilter; PendingOps* m_pPendingOperations;
    int m_iPendingOperationCount; int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount; int m_iCriticalOperationsLockCountForPhantoms;
    unsigned char m_bBlockExecutingPendingOperations; unsigned char m_bBlockExecutingPendingOperationQueues;
    HandlerRegistration* m_pPendingOperationQueues; int m_iPendingOperationQueueCount;
    hkMultiThreadCheck m_kMultiThreadCheck;
    unsigned char m_bProcessActionsInSingleThread;
    unsigned char m_bAllowUnconstrainedIslandJob;
    unsigned int m_uiMinDesiredIslandSize;
    void* m_pModifyConstraintCriticalSection; int m_iIsLocked;
    void* m_pIslandDirtyListCriticalSection; void* m_pPropertyMasterLock;
    unsigned char m_bWantSimulationIslands;
    float m_fSnapCollisionToConvexEdgeThreshold; float m_fSnapCollisionToConcaveEdgeThreshold;
    unsigned char m_bEnableToiWeldRejection; unsigned char m_bWantDeactivation;
    unsigned char m_bActivateOnBodyTransformChange;
    float m_fDeactivationReferenceDistance; float m_fToiCollisionResponseRotateNormal;
    int m_iMaxSectorsPerMidphaseTask; unsigned char m_bProcessToisMultithreaded;
    int m_iMaxSectorsPerNarrowphaseTask; int m_iMaxEntriesPerMidphaseToiTask;
    int m_iMaxEntriesPerNarrowphaseToiTask;
    float m_fSimplifiedToiPenetrationThreshold; float m_fToiPenetrationThreshold;
    float m_fHigherToiPenetrationThreshold; float m_fForcedToiPenetrationThreshold;
    unsigned int m_uiLastEntityUid; unsigned int m_uiLastIslandUid; unsigned int m_uiLastConstraintUid;
    hkArray<void*> m_kPhantoms; hkArray<void*> m_kActionListeners; hkArray<void*> m_kEntityListenerArray;
    hkArray<void*> m_kPhantomListeners; hkArray<void*> m_kConstraintListeners; hkArray<void*> m_kWorldDeletionListeners;
    hkArray<void*> m_kIslandActivationListeners; hkArray<void*> m_kWorldPostSimulationListeners;
    hkArray<void*> m_kWorldPostIntegrateListeners; hkArray<void*> m_kWorldPostCollideListeners;
    hkArray<void*> m_kIslandPostIntegrateListeners; hkArray<void*> m_kIslandPostCollideListeners;
    hkArray<void*> m_kContactListeners; hkArray<void*> m_kContactImpulseLimitBreachedListeners;
    void* m_pViolatedConstraintArray; void* m_pBroadPhaseBorder;
    void hkpWorld_calcContentStatistics(struct ObjectWriter* writer, void* unused);
};
struct ObjectWriter {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void WriteValue(char* name, void* value, int flags);
    virtual void slot10();
    virtual void WriteArray(int kind, char* name, void* array, int length, void* bounded);
    virtual void OpenBlock(char* name);
    virtual void CloseBlock();
    int m_unknown04;
    void* m_reference08;
    int m_unknown0c;
    unsigned char m_writeAll10;
    void DispatchWithMode(char* name, void* value, unsigned int length, int flags);
};
void* __cdecl hkStatisticsCollector_getAllocatedSize(void* array, unsigned int bytes);
extern char str_010c6700;
extern char str_0109c938;
extern char str_010c66f0;
extern char str_010c66e4;
extern char str_010c6084;
extern char str_010c66d8;
extern char str_010c41a4;
extern char str_010c66b8;
extern char str_010c6698;
extern char str_010c6684;
extern char str_010c6664;
extern char str_010c664c;
extern char str_010c6630;
extern char str_010c6624;
extern char str_010c6618;
extern char str_010c660c;
extern char str_010c6600;
extern char str_010c65f8;
extern char str_010c65e8;
extern char str_010c65d8;
extern char str_010c65c4;
extern char str_010c65bc;
extern char str_010c65b0;
extern char str_010c65a4;
extern char str_010c6598;
extern char str_010c6580;
extern char str_010c6578;
extern char str_010c6564;
extern char str_010c6558;
extern char str_010c654c;
extern char str_010c6540;
extern char str_010c6534;
extern char str_010c6524;
extern char str_010c6514;
extern char str_010c6504;
extern char str_010c64f4;
extern char str_010c64e4;
extern char str_010c64d4;
extern char str_010c64c8;
static __forceinline void SaveArray(ObjectWriter* writer,hkArray<void*>& array,char* name,unsigned int stride) {
    if ((array.m_iCapacityState & 0x80000000u) == 0 || writer->m_writeAll10) {
        void* ptr = array.m_data;
         unsigned int capacity = (array.m_iCapacityState & 0x3fffffff);
         void* bounded = hkStatisticsCollector_getAllocatedSize(ptr, capacity * stride);
        writer->WriteArray(3, name, array.m_data, array.m_iElementCount * stride, bounded);
    }
}
static __forceinline void SaveBlob(ObjectWriter* writer,char* name,void* address,unsigned int length) {
    writer->DispatchWithMode(name,address,length,0);
}

// Serializes the WorldSave to the writer: writes arrays, blobs and nested blocks for its members, then clears the writer reference.
// @fnv 0x00c92db0
// src: XBOX_PDB 0x00c92db0
void WorldSave::hkpWorld_calcContentStatistics(ObjectWriter* writer,void* unused) {
    writer->m_reference08 = m_pCollisionInput;
    SaveArray(writer, m_kActiveSimulationIslands, &str_010c6700, 4);
    for (int i = m_kActiveSimulationIslands.m_iElementCount - 1; i >= 0; --i) writer->WriteValue(&str_0109c938, m_kActiveSimulationIslands.m_data[i], 0);
    SaveArray(writer, m_kInactiveSimulationIslands, &str_010c66f0, 4);
    for (int i = m_kInactiveSimulationIslands.m_iElementCount - 1; i >= 0; --i) writer->WriteValue(&str_010c66e4, m_kInactiveSimulationIslands.m_data[i], 0);
    writer->WriteValue(&str_010c6084, reinterpret_cast<void*>(m_pFixedIsland), 0);
    SaveArray(writer, m_kPhantoms, &str_010c66d8, 4);
    for (int i = 0; i < m_kPhantoms.m_iElementCount; ++i) writer->WriteValue(&str_010c41a4, m_kPhantoms.m_data[i], 0);
    if (m_pModifyConstraintCriticalSection) {    SaveBlob(writer,&str_010c66b8, reinterpret_cast<void*>(m_pModifyConstraintCriticalSection), 0x18);}
    SaveBlob(writer,&str_010c6698, reinterpret_cast<void*>(m_pIslandDirtyListCriticalSection), 0x18);
    if (m_pPropertyMasterLock) {    SaveBlob(writer,&str_010c6684, reinterpret_cast<void*>(m_pPropertyMasterLock), 0x18);}
    SaveBlob(writer,&str_010c6664, reinterpret_cast<void*>(m_pMultithreadedSimulationJobData), 0x120);
    if (m_pPendingOperationQueues) {
       HandlerRegistration* position = m_pPendingOperationQueues;
       do {
    SaveBlob(writer,&str_010c664c, reinterpret_cast<void*>(m_pPendingOperationQueues), 0x10);
          if (m_pPendingOperationQueues->data) {
              hkArray<void*>* batch = static_cast<hkArray<void*>*>(m_pPendingOperationQueues->data);
    SaveArray(writer, (*batch), &str_010c6630, 20);
          }
          position = position->next;
       } while (position);
    }
    writer->OpenBlock(&str_010c6624);
    writer->WriteValue(&str_010c6618, reinterpret_cast<void*>(m_pSimulation), 0);
    SaveArray(writer, m_kDirtySimulationIslands, &str_010c660c, 4);
    writer->WriteValue(&str_010c6600, reinterpret_cast<void*>(m_pMaintenanceManager), 0);
    SaveBlob(writer,&str_010c65f8, reinterpret_cast<void*>(m_pPendingOperations), 0x28);
    writer->OpenBlock(&str_010c65f8);
    SaveArray(writer, m_pPendingOperations->m_10, &str_010c65e8, 20);
    SaveArray(writer, m_pPendingOperations->m_1c, &str_010c65d8, 16);
    writer->CloseBlock();
    writer->WriteValue(&str_010c65c4, reinterpret_cast<void*>(m_pBroadPhaseBorder), 0);
    writer->OpenBlock(&str_010c65bc);
    writer->WriteValue(&str_010c65b0, reinterpret_cast<void*>(m_pJobSemaphore), 0);
    SaveBlob(writer,&str_010c65a4, reinterpret_cast<void*>(m_pBroadPhaseDispatcher), 0x10c);
    SaveBlob(writer,&str_010c65a4, reinterpret_cast<void*>(m_pEntityEntityBroadPhaseListener), 0x10);
    SaveBlob(writer,&str_010c65a4, reinterpret_cast<void*>(m_pPhantomBroadPhaseListener), 0xc);
    SaveBlob(writer,&str_010c65a4, reinterpret_cast<void*>(m_pBroadPhaseBorderListener), 0xc);
    SaveBlob(writer,&str_010c6598, reinterpret_cast<void*>(m_pCollisionInput), 0x80);
    if (m_pCollisionInput) {
      SaveBlob(writer,&str_010c6580,*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(m_pCollisionInput)+0x70),0x10);
    }
    writer->WriteValue(&str_010c6578, reinterpret_cast<void*>(m_pCollisionFilter), 0);
    writer->WriteValue(&str_010c6564, reinterpret_cast<void*>(m_pConvexListCollisionFilter), 0);
    writer->WriteValue(&str_010c6558, reinterpret_cast<void*>(m_pDispatcher), 0);
    writer->CloseBlock(); writer->CloseBlock();
    writer->OpenBlock(&str_010c654c);
    SaveArray(writer, m_kEntityListenerArray, &str_010c6540, 4);
    SaveArray(writer, m_kPhantomListeners, &str_010c6534, 4);
    SaveArray(writer, m_kConstraintListeners, &str_010c6524, 4);
    SaveArray(writer, m_kWorldDeletionListeners, &str_010c6514, 4);
    SaveArray(writer, m_kIslandActivationListeners, &str_010c6504, 4);
    SaveArray(writer, m_kWorldPostSimulationListeners, &str_010c64f4, 4);
    SaveArray(writer, m_kWorldPostIntegrateListeners, &str_010c64e4, 4);
    SaveArray(writer, m_kWorldPostCollideListeners, &str_010c64d4, 4);
    SaveArray(writer, m_kIslandPostIntegrateListeners, &str_010c64e4, 4);
    SaveArray(writer, m_kContactListeners, &str_010c64c8, 4);
    writer->CloseBlock();
    writer->m_reference08 = 0;
}

struct WorldWatchDogHolder : hkpWorld {
    void* __thiscall hkpWorld_getMemoryWatchDog();
};

// @fnv 0x00c93570
// src: XBOX_PDB 0x00c93570
void* WorldWatchDogHolder::hkpWorld_getMemoryWatchDog() {
    return m_pMemoryWatchDog;
}

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
inline void __cdecl operator delete(void*, void*) { }


struct ThreadMemHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_alloc;
};

void* hkMemoryRouter_getInstance();
void ResizeAudioStream(void* alloc, void* array, int elemSize);
void QueryEntityIntoBuffer(hkpWorld* world, hkpPhantom* phantom);
void NotifyPhantomAdded(hkpWorld* world, hkpPhantom* phantom);

struct PendingOperation {
    unsigned char m_type;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    hkpPhantom* m_pPhantom;
};


struct FUN_00c936a0_World : hkpWorld {
    void hkpWorld_queueOperation(PendingOperation* op);
    void FUN_00c91120();
    void UpdateFields_00c91140();

    hkpPhantom* hkpWorld_addPhantom(hkpPhantom* phantom);
};

// @fnv 0x00c936a0
// src: HAVOK_LIB 0x00c936a0
hkpPhantom* FUN_00c936a0_World::hkpWorld_addPhantom(hkpPhantom* phantom)
{
    if (m_iCriticalOperationsLockCount + m_iCriticalOperationsLockCountForPhantoms) {
        PendingOperation op;
        op.m_type = 0xD;
        op.m_pPhantom = phantom;
        hkpWorld_queueOperation(&op);
        return 0;
    }

    m_iCriticalOperationsLockCount++;

    if (!phantom->m_kCollidable.m_pMotionState) {
        phantom->m_kCollidable.m_pMotionState = (*(const void* (__thiscall**)(hkpPhantom*))(*(char**)phantom + 0x10))(phantom);
    }

    phantom->m_pOwningWorld = this;
    ((RefObj*)phantom)->FUN_00c90510();

    hkArray<hkpPhantom*>& phantoms = m_kPhantoms;
    ThreadMemHolder* mem = (ThreadMemHolder*)hkMemoryRouter_getInstance();
    if (phantoms.m_iElementCount == (phantoms.m_iCapacityState & 0x3FFFFFFF)) {
        ResizeAudioStream(mem->m_alloc, &phantoms, 4);
    }

    void* p = phantoms.m_data + phantoms.m_iElementCount;
    __assume(p != 0);
    new (p) hkpPhantom*(phantom);
    phantoms.m_iElementCount++;

    QueryEntityIntoBuffer(this, phantom);
    NotifyPhantomAdded(this, phantom);
    phantom->firePhantomAdded();

    if (--m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
        if (m_iPendingOperationCount) {
            FUN_00c91120();
        }
        if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount) {
            UpdateFields_00c91140();
        }
    }

    return phantom;
}

namespace fnv_00c937e0 {

class hkpEntityListenerXc937e0;

class hkpWorldXc937e0 {
public:
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
    hkArray<void*> m_kEntityListenerArray;

    void hkpWorld_addConstraintListener(hkpEntityListenerXc937e0* pkListener);
};

// Appends pkListener to the world's entity listener array, growing it if needed.
// @fnv 0x00c937e0
// src: HAVOK_LIB 0x00c937e0
void hkpWorldXc937e0::hkpWorld_addConstraintListener(hkpEntityListenerXc937e0* pkListener)
{
    m_kEntityListenerArray.pushBack(pkListener);
}
}  // namespace fnv_00c937e0

namespace fnv_00c93820 {
class hkpEntityListenerC938;

class hkpWorldC938 {
public:
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
    hkArray<void*> m_kEntityListenerArray;

    void hkpWorld_addEntityListener(hkpEntityListenerC938* pkListener);
};

// @fnv 0x00c93820
// src: HAVOK_LIB 0x00c93820
void hkpWorldC938::hkpWorld_addEntityListener(hkpEntityListenerC938* pkListener)
{
    m_kEntityListenerArray.pushBack(pkListener);
}
}  // namespace fnv_00c93820

namespace fnv_00c93860 {

class hkpEntityListenerXc93860;

class hkpWorldXc93860 {
public:
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
    hkArray<void*> m_kEntityListenerArray;

    void hkpWorld_addPhantomListener(hkpEntityListenerXc93860* pkListener);
};

// @fnv 0x00c93860
// src: HAVOK_LIB 0x00c93860
void hkpWorldXc93860::hkpWorld_addPhantomListener(hkpEntityListenerXc93860* pkListener)
{
    m_kEntityListenerArray.pushBack(pkListener);
}
}  // namespace fnv_00c93860

namespace fnv_00c938a0 {

class hkpEntityListenerXc938a0;

class hkpWorldXc938a0 {
public:
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
    hkArray<void*> m_kEntityListenerArray;

    void hkpWorld_addIslandActivationListener(hkpEntityListenerXc938a0* pkListener);
};

// Appends pkListener to the world's entity listener array, growing it if needed.
// @fnv 0x00c938a0
// src: HAVOK_LIB 0x00c938a0
void hkpWorldXc938a0::hkpWorld_addIslandActivationListener(hkpEntityListenerXc938a0* pkListener)
{
    m_kEntityListenerArray.pushBack(pkListener);
}
}  // namespace fnv_00c938a0

namespace fnv_00c938e0 {
class hkpWorldPostCollideListenerC938;

class hkpWorldC938 {
public:
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
    hkArray<void*> m_kEntityListenerArray;
    hkArray<void*> m_kPhantomListeners;
    hkArray<void*> m_kConstraintListeners;
    hkArray<void*> m_kWorldDeletionListeners;
    hkArray<void*> m_kIslandActivationListeners;
    hkArray<void*> m_kWorldPostSimulationListeners;
    hkArray<void*> m_kWorldPostIntegrateListeners;
    hkArray<void*> m_kWorldPostCollideListeners;

    void AddPostCollideListener(hkpWorldPostCollideListenerC938* pkListener);
};

// Appends pkListener to the world's post-collide listener array.
// @fnv 0x00c938e0
void hkpWorldC938::AddPostCollideListener(hkpWorldPostCollideListenerC938* pkListener)
{
    m_kWorldPostCollideListeners.pushBack(pkListener);
}
}  // namespace fnv_00c938e0

namespace fnv_00c93920 {

class hkpEntityListenerXc93920;

class hkpWorldXc93920 {
public:
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
    hkArray<void*> m_kEntityListenerArray;

    void hkpWorld_addWorldPostSimulationListener(hkpEntityListenerXc93920* pkListener);
};

// Appends pkListener to the world's entity listener array, growing it if needed.
// @fnv 0x00c93920
// src: HAVOK_LIB 0x00c93920
void hkpWorldXc93920::hkpWorld_addWorldPostSimulationListener(hkpEntityListenerXc93920* pkListener)
{
    m_kEntityListenerArray.pushBack(pkListener);
}
}  // namespace fnv_00c93920

namespace fnv_00c93960 {
class hkpWorldPostIntegrateListenerC939;

class hkpWorldC939 {
public:
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
    hkArray<void*> m_kEntityListenerArray;
    hkArray<void*> m_kPhantomListeners;
    hkArray<void*> m_kConstraintListeners;
    hkArray<void*> m_kWorldDeletionListeners;
    hkArray<void*> m_kIslandActivationListeners;
    hkArray<void*> m_kWorldPostSimulationListeners;
    hkArray<void*> m_kWorldPostIntegrateListeners;

    void hkpWorld_addWorldPostIntegrateListener(hkpWorldPostIntegrateListenerC939* pkListener);
};

// Appends pkListener to the world's post-integrate listener array.
// @fnv 0x00c93960
// src: HAVOK_LIB 0x00c93960
void hkpWorldC939::hkpWorld_addWorldPostIntegrateListener(hkpWorldPostIntegrateListenerC939* pkListener)
{
    m_kWorldPostIntegrateListeners.pushBack(pkListener);
}
}  // namespace fnv_00c93960

namespace fnv_00c939e0 {
class hkpIslandPostIntegrateListenerC939;

class hkpWorldC939 {
public:
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
    hkArray<void*> m_kEntityListenerArray;
    hkArray<void*> m_kPhantomListeners;
    hkArray<void*> m_kConstraintListeners;
    hkArray<void*> m_kWorldDeletionListeners;
    hkArray<void*> m_kIslandActivationListeners;
    hkArray<void*> m_kWorldPostSimulationListeners;
    hkArray<void*> m_kWorldPostIntegrateListeners;
    hkArray<void*> m_kWorldPostCollideListeners;
    hkArray<void*> m_kIslandPostIntegrateListeners;

    void hkpWorld_addIslandPostIntegrateListener(hkpIslandPostIntegrateListenerC939* pkListener);
};

// Appends pkListener to the world's post-integrate listener array.
// @fnv 0x00c939e0
// src: HAVOK_LIB 0x00c939e0
void hkpWorldC939::hkpWorld_addIslandPostIntegrateListener(hkpIslandPostIntegrateListenerC939* pkListener)
{
    m_kIslandPostIntegrateListeners.pushBack(pkListener);
}
}  // namespace fnv_00c939e0

namespace fnv_00c93a20 {

class hkpEntityListenerXc93a20;

class hkpWorldXc93a20 {
public:
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
    hkArray<void*> m_kEntityListenerArray;

    void hkpWorld_addContactListener(hkpEntityListenerXc93a20* pkListener);
};

// Appends pkListener to the world's entity listener array, growing it if it is full.
// @fnv 0x00c93a20
// src: HAVOK_LIB 0x00c93a20
void hkpWorldXc93a20::hkpWorld_addContactListener(hkpEntityListenerXc93a20* pkListener)
{
    m_kEntityListenerArray.pushBack(pkListener);
}
}  // namespace fnv_00c93a20

struct FUN_00c93ae0_Vt {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c(void* p, int n);
    virtual void slot10();
};

struct FUN_00c93ae0_Dtm {
    void hkJobQueue_processAllJobs();
};

struct FUN_00c93ae0_Cb {
    int hkpWorld_initMtStep(void* p, float f);
};

struct FUN_00c93ae0_Pair {
    void hkpWorld_finishMtStep(void* a, void* b);
};

struct FUN_00c93ae0_class {
    void hkpWorld_stepMultithreaded(void* p1, void* p2, float f);
};

// Calls FUN_00c92d70 on this with p1 and f; if it returns 0, invokes slot0c(p1, 11), FUN_00d051b0 on p1, slot10, then FUN_00c91c00(p1, p2).
// @fnv 0x00c93ae0
// src: HAVOK_LIB 0x00c93ae0
void FUN_00c93ae0_class::hkpWorld_stepMultithreaded(void* p1, void* p2, float fValue) {
    if (reinterpret_cast<FUN_00c93ae0_Cb*>(this)->hkpWorld_initMtStep(p1, fValue)) {
        return;
    }
    FUN_00c93ae0_Vt* o = reinterpret_cast<FUN_00c93ae0_Vt*>(p2);
    o->slot0c(p1, 11);
    reinterpret_cast<FUN_00c93ae0_Dtm*>(p1)->hkJobQueue_processAllJobs();
    o->slot10();
    reinterpret_cast<FUN_00c93ae0_Pair*>(this)->hkpWorld_finishMtStep(p1, p2);
}






class FUN_00c93d10 : public hkReferencedObject {
public:
    void* m_pSimulation;
    char m_padC[0x4];
    // Gravity is untouched by this finishing constructor.
    float m_kGravity[4];
    void* m_pFixedIsland;
    void* m_pFixedRigidBody;
    hkArray<void*> m_kActiveSimulationIslands;
    hkArray<void*> m_kInactiveSimulationIslands;
    hkArray<void*> m_kDirtySimulationIslands;
    void* m_pMaintenanceManager;
    void* m_pMemoryWatchDog;
    char m_pad54[0x54];
    hkMultiThreadCheck m_kMultiThreadCheck;
    char m_padB0[0x6c];
    hkArray<void*> m_kPhantoms;
    hkArray<void*> m_kActionListeners;
    hkArray<void*> m_kEntityListenerArray;
    hkArray<void*> m_kPhantomListeners;
    hkArray<void*> m_kConstraintListeners;
    hkArray<void*> m_kWorldDeletionListeners;
    hkArray<void*> m_kIslandActivationListeners;
    hkArray<void*> m_kWorldPostSimulationListeners;
    hkArray<void*> m_kWorldPostIntegrateListeners;
    hkArray<void*> m_kWorldPostCollideListeners;
    hkArray<void*> m_kIslandPostIntegrateListeners;
    hkArray<void*> m_kIslandPostCollideListeners;
    hkArray<void*> m_kContactListeners;

    FUN_00c93d10(int iUnused) throw();
    virtual void calcContentStatistics() throw();
};

// Initializes the object by setting the pointer member at offset 0x50 to null.
// @fnv 0x00c93d10
FUN_00c93d10::FUN_00c93d10(int iUnused) throw()
    : m_pMemoryWatchDog(0)
{
}

namespace fnv_00c976a0 {
template <typename T>
struct hkSmallArrayC976 {
    T* m_data;
    hkUint16 m_iElementCount;
    hkUint16 m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int iIndex)
    {
        m_iElementCount--;
        m_data[iIndex] = m_data[m_iElementCount];
    }
};

class hkpActionC976;

class hkpSimulationIslandC976 {
public:
    char m_acUnk00[0x20];
    hkUint16 m_usStorageIndex;
    char m_acUnk22[0x3];
    hkUint8 m_bSplitCheckRequested : 1;
    hkUint8 m_isSparse : 1;

    bool isFixed() const { return m_usStorageIndex == 0xffff; }
    void RemoveEntry(hkpActionC976* pkAction) throw();
    void AddItem(hkpActionC976* pkAction) throw();
};


class hkpActionC976 {
public:
    virtual ~hkpActionC976() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void GetEntities(hkArray<hkpEntity*>& kEntitiesOut) throw();
    int m_iUnk04;
    void* m_pOwningWorld;
    hkpSimulationIslandC976* m_pCurrentSimulationIsland;

    hkpSimulationIslandC976* GetSimulationIsland() const { return m_pCurrentSimulationIsland; }
};

// @fnv 0x00c976a0
void __stdcall RemoveActionFromEntity(hkpActionC976* pkAction, hkpEntity* pkEntity) throw()
{
    pkEntity->m_ppActions.removeAt(pkEntity->m_ppActions.indexOf((hkpAction*)pkAction));
    hkpSimulationIslandC976* pkIsland = (hkpSimulationIslandC976*)pkEntity->m_pSimulationIsland;
    pkIsland->m_bSplitCheckRequested = true;
    pkIsland->m_isSparse = false;

    hkInplaceArray<hkpEntity*, 4> kEntities;
    pkAction->GetEntities(kEntities);

    hkpSimulationIslandC976* pkNewIsland = 0;
    for (int i = 0; i < kEntities.GetLogicalSize(); i++) {
        if (kEntities[i] != pkEntity) {
            pkNewIsland = (hkpSimulationIslandC976*)kEntities[i]->m_pSimulationIsland;
            if (!pkNewIsland->isFixed())
                break;
        }
    }
    if (pkNewIsland != pkAction->GetSimulationIsland()) {
        pkAction->GetSimulationIsland()->RemoveEntry(pkAction);
        pkNewIsland->AddItem(pkAction);
    }
}
}  // namespace fnv_00c976a0

struct SystemObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    void* owner;
    void* attachment;
};


struct ActiveFlag {
    char value;
    operator bool() const { return value != 0; }
};
inline ActiveFlag PhysicsSystemIsActive(const hkpPhysicsSystem* system)
{
    return *(const ActiveFlag*)&system->m_bSlotEnabled;
}
template <class T> inline int findNull(const hkArray<T>& values) {
    for (int i = 0; i < values.m_iElementCount; ++i) {
        if (values.m_data[i] == 0)
            return i;
    }
    return -1;
}
struct SystemWorld : hkpWorld {
    void hkpWorld_addEntityBatch(void**, int, int);
    void hkpWorld_addEntity(void*, int);
    void hkpWorld_addPhantomBatch(void**, int);
    void hkpWorld_addPhantom(void*);
    void hkpWorld_addAction(void*);
    void hkpWorld_addConstraint(SystemObject*);
    void hkpWorld_addPhysicsSystem(hkpPhysicsSystem* system);
};
// Updates the physics system's entities, phantoms, actions and constraints, using bulk calls when no null entries are present and per-entry calls otherwise.
// @fnv 0x00c97f80
// src: HAVOK_LIB 0x00c97f80
void SystemWorld::hkpWorld_addPhysicsSystem(hkpPhysicsSystem* system) {
    if (system->m_ppRigidBodies.m_iElementCount > 0) {
        if (findNull(system->m_ppRigidBodies) == -1) {
            hkpWorld_addEntityBatch((void**)system->m_ppRigidBodies.m_data, system->m_ppRigidBodies.m_iElementCount, PhysicsSystemIsActive(system) ? 1 : 0);
        } else {
            for (int i = 0; i < system->m_ppRigidBodies.m_iElementCount; ++i) {
                if (system->m_ppRigidBodies.m_data[i])
                    hkpWorld_addEntity(system->m_ppRigidBodies.m_data[i], PhysicsSystemIsActive(system) ? 1 : 0);
            }
        }
    }
    if (system->m_kPhantoms.m_iElementCount > 0) {
        if (findNull(system->m_kPhantoms) == -1) {
            hkpWorld_addPhantomBatch((void**)system->m_kPhantoms.m_data, system->m_kPhantoms.m_iElementCount);
        } else {
            for (int i = 0; i < system->m_kPhantoms.m_iElementCount; ++i) {
                if (system->m_kPhantoms.m_data[i])
                    hkpWorld_addPhantom(system->m_kPhantoms.m_data[i]);
            }
        }
    }
    for (int i = 0; i < system->m_ppActions.m_iElementCount; ++i) {
        if (system->m_ppActions.m_data[i])
            hkpWorld_addAction(system->m_ppActions.m_data[i]);
    }
    for (int i = 0; i < system->m_ppConstraints.m_iElementCount; ++i) {
        if (system->m_ppConstraints.m_data[i] &&
            (((SystemObject*)system->m_ppConstraints.m_data[i])->owner || ((SystemObject*)system->m_ppConstraints.m_data[i])->attachment))
            hkpWorld_addConstraint((SystemObject*)system->m_ppConstraints.m_data[i]);
    }
}

class hkpConstraintInstanceC980;
class hkpActionC980;
class hkpRigidBodyC980;

template <class T>
inline int ArrayIndexOfC980(const hkArray<T>& array, T value, int startIdx = 0, int endIdx = -1)
{
    if (endIdx < 0)
        endIdx = array.m_iElementCount;
    for (int i = startIdx; i < endIdx; ++i) {
        if (array.m_data[i] == value)
            return i;
    }
    return -1;
}

struct hkBoolRetC980 {
    char m_cBooleanValue;
    hkBoolRetC980() throw() {}
};


class hkpWorldC980 {
public:
    hkBoolRetC980 hkpWorld_removeConstraint(hkpConstraintInstanceC980* pkConstraint) throw();
    void DispatchOrQueue(hkpActionC980* pkAction) throw();
    void RemoveEntities(hkpEntity* const* ppkEntityBatch, int iNumEntities) throw();
    hkBoolRetC980 ProcessTarget(hkpEntity* pkEntity) throw();
    void hkpWorld_removePhantomBatch(hkpPhantom* const* ppkPhantomBatch, int iNumPhantoms) throw();
    void hkpWorld_removePhantom(hkpPhantom* pkPhantom) throw();

    void hkpWorld_removePhysicsSystem(const hkpPhysicsSystem* pkSys) throw();
};

// @fnv 0x00c980d0
// src: HAVOK_LIB 0x00c980d0
void hkpWorldC980::hkpWorld_removePhysicsSystem(const hkpPhysicsSystem* pkSys) throw()
{
    for (int c = 0; c < pkSys->m_ppConstraints.m_iElementCount; ++c) {
        if (pkSys->m_ppConstraints.m_data[c])
            hkpWorld_removeConstraint((hkpConstraintInstanceC980*)pkSys->m_ppConstraints.m_data[c]);
    }
    for (int a = 0; a < pkSys->m_ppActions.m_iElementCount; ++a) {
        if (pkSys->m_ppActions.m_data[a])
            DispatchOrQueue((hkpActionC980*)pkSys->m_ppActions.m_data[a]);
    }
    if (ArrayIndexOfC980(pkSys->m_ppRigidBodies, (hkpRigidBody*)0) == -1) {
        RemoveEntities((hkpEntity* const*)pkSys->m_ppRigidBodies.m_data, pkSys->m_ppRigidBodies.m_iElementCount);
    } else {
        for (int r = 0; r < pkSys->m_ppRigidBodies.m_iElementCount; ++r) {
            if (pkSys->m_ppRigidBodies.m_data[r])
                ProcessTarget((hkpEntity*)pkSys->m_ppRigidBodies.m_data[r]);
        }
    }
    if (ArrayIndexOfC980(pkSys->m_kPhantoms, (hkpPhantom*)0) == -1) {
        hkpWorld_removePhantomBatch(pkSys->m_kPhantoms.m_data, pkSys->m_kPhantoms.m_iElementCount);
    } else {
        for (int p = 0; p < pkSys->m_kPhantoms.m_iElementCount; ++p) {
            if (pkSys->m_kPhantoms.m_data[p])
                hkpWorld_removePhantom(pkSys->m_kPhantoms.m_data[p]);
        }
    }
}

namespace fnv_00c98260 {



extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();



class hkPrimaryC982 : public hkReferencedObject {
};

class hkSecondaryC982 : public hkReferencedObject {
};

class hkListenerPairC982 : public hkPrimaryC982, public hkSecondaryC982 {
public:
    hkListenerPairC982* DestroyAndMaybeFree(unsigned int uiFlags) throw();
};

// Destroys the object, then frees it via hkPrimaryC982::operator delete when uiFlags has bit 0 set, and returns this.
// @fnv 0x00c98260
hkListenerPairC982* hkListenerPairC982::DestroyAndMaybeFree(unsigned int uiFlags) throw()
{
    this->hkListenerPairC982::~hkListenerPairC982();
    if (uiFlags & 1)
        hkPrimaryC982::operator delete(this);
    return this;
}
}  // namespace fnv_00c98260

namespace fnv_00c982e0 {



extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

class FUN_00cfa860 {
public:
    virtual void V0() throw();
    ~FUN_00cfa860() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        hkMemoryRouter_getInstance().heap().blockFree(p, static_cast<FUN_00cfa860*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00cfa860* hkpNullCollisionFilter_Destroy(unsigned int uiFlags) throw();
};

// Runs the destructor, then frees the object through operator delete when bit 0 of uiFlags is set, and returns this.
// @fnv 0x00c982e0
// src: COMMUNITY 0x00c982e0
FUN_00cfa860* FUN_00cfa860::hkpNullCollisionFilter_Destroy(unsigned int uiFlags) throw()
{
    this->FUN_00cfa860::~FUN_00cfa860();
    if (uiFlags & 1)
        FUN_00cfa860::operator delete(this);
    return this;
}
}  // namespace fnv_00c982e0

namespace fnv_00c98370 {



extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();



class hkPrimaryC983 : public hkReferencedObject {
};

class hkSecondaryC983 {
public:
    virtual ~hkSecondaryC983() throw() {}
    int m_0c;
};

class hkListenerPairC983 : public hkPrimaryC983, public hkSecondaryC983 {
public:
    hkListenerPairC983* FUN_00c98370(unsigned int uiFlags) throw();
};

// Destroys the object and, when bit 0 of uiFlags is set, frees its memory via operator delete; returns this.
// @fnv 0x00c98370
hkListenerPairC983* hkListenerPairC983::FUN_00c98370(unsigned int uiFlags) throw()
{
    this->hkListenerPairC983::~hkListenerPairC983();
    if (uiFlags & 1)
        hkPrimaryC983::operator delete(this);
    return this;
}
}  // namespace fnv_00c98370

namespace fnv_00c983b0 {
struct FnvCpu_FUN_00c983b0_CpuAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00c983b0_CpuAllocatorHolder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00c983b0_CpuAllocator* allocator;
};
FnvCpu_FUN_00c983b0_CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00c983b0_CpuObject {
    unsigned int unk00;
    unsigned short size;
    void FUN_00c93e50();
    FnvCpu_FUN_00c983b0_CpuObject* FUN_00c983b0(unsigned int flags);
};
// @fnv 0x00c983b0
FnvCpu_FUN_00c983b0_CpuObject* FnvCpu_FUN_00c983b0_CpuObject::FUN_00c983b0(unsigned int flags)
{
    FUN_00c93e50();
    if (flags & 1) {
        FnvCpu_FUN_00c983b0_CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00c983b0

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

class hkListenerC984 {
public:
    virtual void v00();
    virtual void v04();
    virtual void onEvent(int a, int b, int c, int d, int e);
};

class hkDispatcherC984 {
public:
    int unk00;
    int unk04;
    hkListenerC984** m_kListeners;
    int m_numListeners;
    int unk10;
    void* m_kCriticalSection;

    void DispatchEvent(int a, int b, int c, int d, int e);
};

// Locks the critical section, calls onEvent on every registered listener with the five arguments, then unlocks it.
// @fnv 0x00c98440
void hkDispatcherC984::DispatchEvent(int aiArg0, int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    EnterCriticalSection(m_kCriticalSection);
    for (int i = 0; i < m_numListeners; i++)
        m_kListeners[i]->onEvent(aiArg0, aiArg1, aiArg2, aiArg3, aiArg4);
    LeaveCriticalSection(m_kCriticalSection);
}

namespace fnv_00c984f0 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs) throw();

struct hkListenerC984 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(void* a, void* b, void* c);
};

struct hkObjC984 {
    int unk00;
    int unk04;
    hkListenerC984** m_kListeners;
    int m_numListeners;
    int unk10;
    void* m_kCriticalSection;

    void hkDebugDisplay_updateGeometry(void* a, void* b, void* c);
};

// Enters the critical section, calls v10 on each listener with the three arguments, then leaves the critical section.
// @fnv 0x00c984f0
// src: HAVOK_LIB 0x00c984f0
void hkObjC984::hkDebugDisplay_updateGeometry(void* a, void* b, void* c)
{
    EnterCriticalSection(m_kCriticalSection);
    for (int i = 0; i < m_numListeners; i++)
        m_kListeners[i]->v10(a, b, c);
    LeaveCriticalSection(m_kCriticalSection);
}
}  // namespace fnv_00c984f0

extern void(__stdcall* DAT_00fdf05c)(void* pvSection);
extern void(__stdcall* DAT_00fdf100)(void* pvSection);

struct hkVector3C985 {
    float x;
    float y;
    float z;
};

class hkListenerC985 {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void notify(void* a, void* b, void* c, float x, float y, float z, void* d);
};

class hkDispatcherC985 {
public:
    int unk00;
    int unk04;
    hkListenerC985** m_kListeners;
    int m_numListeners;
    int unk10;
    hkCriticalSection* m_lock;

    void hkDebugDisplay_updateCamera(void* a, void* b, void* c, float x, float y, float z, void* d);
};

// @fnv 0x00c98590
// src: HAVOK_LIB 0x00c98590
void hkDispatcherC985::hkDebugDisplay_updateCamera(void* apArg1, void* apArg2, void* apArg3, float x, float y, float z, void* apArg4)
{
    m_lock->enter();
    for (int i = 0; i < m_numListeners; i++)
        m_kListeners[i]->notify(apArg1, apArg2, apArg3, x, y, z, apArg4);
    m_lock->leave();
}

class hkpListenerC986 {
public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void notify(int a, int b, int c, int d) throw();
};

class hkpListenerListC986 {
public:
    int unk00;
    int unk04;
    hkpListenerC986** m_data;
    int m_iElementCount;
    int unk10;
    void* m_pWorldLock;

    void hkDebugDisplay_displayPoint(int a, int b, int c, int d);
};

// @fnv 0x00c98670
// src: HAVOK_LIB 0x00c98670
void hkpListenerListC986::hkDebugDisplay_displayPoint(int aiArg0, int aiArg1, int aiArg2, int aiArg3)
{
    EnterCriticalSection(m_pWorldLock);
    for (int i = 0; i < m_iElementCount; i++)
        m_data[i]->notify(aiArg0, aiArg1, aiArg2, aiArg3);
    LeaveCriticalSection(m_pWorldLock);
}

class hkpListenerC98B {
public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void V8() throw();
    virtual void notify(int a, int b, int c, int d, int e) throw();
};

class hkpListenerListC98B {
public:
    int unk00;
    int unk04;
    hkpListenerC98B** m_data;
    int m_iElementCount;
    int unk10;
    void* m_pWorldLock;

    void hkDebugDisplay_displayLine(int a, int b, int c, int d, int e);
};

// @fnv 0x00c986c0
// src: HAVOK_LIB 0x00c986c0
void hkpListenerListC98B::hkDebugDisplay_displayLine(int aiArg0, int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    EnterCriticalSection(m_pWorldLock);
    for (int i = 0; i < m_iElementCount; i++)
        m_data[i]->notify(aiArg0, aiArg1, aiArg2, aiArg3, aiArg4);
    LeaveCriticalSection(m_pWorldLock);
}

// 0x00c98720  unit_74447a602ec8.cpp  /MT /O2 /GS /EHsc /Gy
// thiscall, 6 stack args (ret 0x18): lock pointer at this+0x14, walk the array at
// this+8 for this->count0c elements, call vtable slot 0x28 with the six args, unlock.
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct Listener00c98720 {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28(int, int, int, int, int, int);
};

struct C00c98720 {
    char pad00[0x8];
    Listener00c98720** arr08;
    int count0c;
    char pad10[0x4];
    void* pCS14;

    void hkDebugDisplay_displayTriangle(int a, int b, int c, int d, int e, int f);
};

// Locks the critical section, calls s28 with the six arguments on each listener in arr08, then unlocks it.
// @fnv 0x00c98720
// src: HAVOK_LIB 0x00c98720
void C00c98720::hkDebugDisplay_displayTriangle(int aiArg0, int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5) {
    EnterCriticalSection(pCS14);
    for (int i = 0; i < count0c; ++i) {
        arr08[i]->s28(aiArg0, aiArg1, aiArg2, aiArg3, aiArg4, aiArg5);
    }
    LeaveCriticalSection(pCS14);
}


extern "C" LocalM128 __cdecl _mm_setzero_ps(void);
extern "C" LocalM128 __cdecl _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 __cdecl _mm_sub_ps(LocalM128 a, LocalM128 b);

struct FUN_00c986c0_Obj {
    void hkDebugDisplay_displayLine(LocalM128* a, LocalM128* b, int c, int d, int e);
};

struct FUN_00c98b60_Class {
    void DrawAxisLines(LocalM128* v, float f, int c, int d, int e);
};

// For each of the first three axes, builds a vector with f on that axis and calls FUN_00c986c0 with the sum and difference against *v.
// @fnv 0x00c98b60
// src: GUESS 0x00c98b60 (confidence: medium)
void FUN_00c98b60_Class::DrawAxisLines(LocalM128* v, float f, int c, int d, int e)
{
    int i = 0;
    LocalM128 vecZero = _mm_setzero_ps();
    for (; i < 3; ++i) {
        union {
            LocalM128 v;
            float f[4];
        } vecAxis;
        vecAxis.v = vecZero;
        vecAxis.f[i] = f;
        LocalM128 vecSum = _mm_add_ps(*v, vecAxis.v);
        LocalM128 diff = _mm_sub_ps(*v, vecAxis.v);
        reinterpret_cast<FUN_00c986c0_Obj*>(this)->hkDebugDisplay_displayLine(&vecSum, &diff, c, d, e);
    }
}

struct IListener {
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c(void* a1, void* a2, void* a3, void* a4, void* a5);
};

struct ListenerManager {
    int unk00;
    int unk04;
    IListener** m_kListeners;
    int m_uiItemCount;
    int unk10;
    void* m_cs;

    void hkDebugDisplay_display3dText(void* a1, void* a2, void* a3, void* a4, void* a5);
};

// @fnv 0x00c99100
// src: HAVOK_LIB 0x00c99100
void ListenerManager::hkDebugDisplay_display3dText(void* apArg1, void* apArg2, void* apArg3, void* apArg4, void* apArg5) {
    EnterCriticalSection(m_cs);
    for (int i = 0; i < m_uiItemCount; ++i) {
        m_kListeners[i]->v0c(apArg1, apArg2, apArg3, apArg4, apArg5);
    }
    LeaveCriticalSection(m_cs);
}

extern "C" __declspec(dllimport) void __stdcall FUN_00fdf05c(void*);
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf100(void*);
struct FUN_00c99160_Dispatch {
    virtual void fn00();
    virtual void fn04();
    virtual void fn08();
    virtual void fn0c();
    virtual void fn10();
    virtual void fn14();
    virtual void fn18();
    virtual void fn1c();
    virtual void fn20();
    virtual void fn24();
    virtual void fn28();
    virtual void fn2c();
    virtual void fn30();
    virtual void fn34();
    virtual void fn38();
    virtual void fn3c(int a, int b, int c, int d, int e);
};
struct FUN_00c99160_Owner {
    int unk00;
    int unk04;
    FUN_00c99160_Dispatch** listeners;
    int listenerCount;
    int unk10;
    void* mutex;
    void DispatchToListeners(int a, int b, int c, int d, int e);
};
// @fnv 0x00c99160
void FUN_00c99160_Owner::DispatchToListeners(int aiArg0, int aiArg1, int aiArg2, int aiArg3, int aiArg4) {
    FUN_00fdf05c(mutex);
    for(int i = 0; i < listenerCount; ++i) {
        listeners[i]->fn3c(aiArg0, aiArg1, aiArg2, aiArg3, aiArg4);
    }
    FUN_00fdf100(mutex);
}

struct FUN_00c991c0_Interface {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void __thiscall slot38(int, int, int, int);
};

struct FUN_00c991c0_Class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    FUN_00c991c0_Interface** m_8;
    int m_iThirdValue;
    void* m_10;
    void* m_14;

    void __thiscall DispatchToSlots(int, int, int, int);
};

extern void (__stdcall *DAT_00fdf05c)(void*);
extern void (__stdcall *DAT_00fdf100)(void*);

// @fnv 0x00c991c0
void __thiscall FUN_00c991c0_Class::DispatchToSlots(int aiArg1, int aiArg2, int aiArg3, int aiArg4) {
    FUN_00c991c0_Class* self = this;

    DAT_00fdf05c(self->m_14);

    int index = 0;
    while (index < self->m_iThirdValue) {
        FUN_00c991c0_Interface* object = self->m_8[index];
        object->slot38(aiArg1, aiArg2, aiArg3, aiArg4);
        ++index;
    }

    DAT_00fdf100(self->m_14);
}

struct HavokHelper {
    void DrawAxes(const hkRotation& rot, float a2, int a3, int a4);
    void hkDebugDisplayHandler_displayFrame(const hkQuaternion& a1, float a2, int a3, int a4);
};

struct __declspec(align(16)) AlignedRotation : hkRotation {
    void SetFromInput_Thunk(const hkQuaternion& a1);
};

// Builds an aligned rotation from the quaternion a1 and forwards it with a2, a3 and a4 to DrawAxes.
// @fnv 0x00c99870
// src: HAVOK_LIB 0x00c99870
void HavokHelper::hkDebugDisplayHandler_displayFrame(const hkQuaternion& aQuat, float afValue, int aiArg3, int aiArg4) {
    struct __declspec(align(16)) { LocalM128 x, y, z; } rotationStorage;
    AlignedRotation& rot = *(AlignedRotation*)&rotationStorage;
    rot.SetFromInput_Thunk(aQuat);
    DrawAxes(rot, afValue, aiArg3, aiArg4);
}

namespace fnv_00c99eb0 {
struct FNV_Allocator {
    virtual void reserved();
    virtual void* allocate(unsigned int bytes);
};
struct FNV_AllocatorContext {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    FNV_Allocator* allocator;
};
FNV_AllocatorContext* __cdecl hkMemoryRouter_getInstance();
struct FNV_Subobject {
    void* ProcessAndReturnValue_00cf6da0(unsigned int value);
};
extern void* DAT_010c69cc;
struct FUN_00c99eb0 {
    void* m_ppVirtualMethodTable;
    unsigned short m_04;
    unsigned short m_flag06;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    void* m_14;
    FUN_00c99eb0();
};
// Initialises the object's fields, allocates 0x18 bytes from the allocator and stores the result of FUN_00cf6da0(1000) in m_14.
// @fnv 0x00c99eb0
FUN_00c99eb0::FUN_00c99eb0() {
    m_flag06 = 1;
    m_ppVirtualMethodTable = &DAT_010c69cc;
    m_08 = 0;
    m_0C = 0;
    m_10 = 0x80000000u;
    FNV_AllocatorContext* context = hkMemoryRouter_getInstance();
    void* memory = context->allocator->allocate(0x18);
    void* pSubobject = memory
        ? static_cast<FNV_Subobject*>(memory)->ProcessAndReturnValue_00cf6da0(1000)
        : 0;
    m_14 = pSubobject;
}
}  // namespace fnv_00c99eb0

struct FUN_00ca8420_Local {
    unsigned char unk00;
    unsigned int unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
};

struct FUN_00ca8420_Target {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    int unk90;
    int unk94;

    void __thiscall hkpWorld_queueOperation(FUN_00ca8420_Local* local);
};

struct FUN_00ca8420_Class {
    void* unk00;
    void* unk04;
    FUN_00ca8420_Target* unk08;

    void __thiscall hkpRigidBody_setMotionType(int param2, int param3, int param4);
};

void __cdecl hkpWorldOperationUtil_setRigidBodyMotionType(void* param1, int param2, int param3, int param4);
void __cdecl NotifyEntitySetMotionType(void* param1, void* param2);
void __cdecl InvokeMotionTypeCallbacks(void* param1);

// @fnv 0x00ca8420
// src: HAVOK_LIB 0x00ca8420
void __thiscall FUN_00ca8420_Class::hkpRigidBody_setMotionType(int aiArg1, int aiArg2, int aiArg3)
{
    if (unk08 != 0 && unk08->unk94 != 0) {
        FUN_00ca8420_Local local;
        local.unk08 = (unsigned char)aiArg1;
        local.unk09 = (unsigned char)aiArg2;
        local.unk00 = 4;
        local.unk04 = (unsigned int)this;
        local.unk0A = (unsigned char)aiArg3;
        unk08->hkpWorld_queueOperation(&local);
        return;
    }

    hkpWorldOperationUtil_setRigidBodyMotionType(this, aiArg1, aiArg2, aiArg3);

    if (unk08 != 0) {
        NotifyEntitySetMotionType(unk08, this);
    }

    InvokeMotionTypeCallbacks(this);
}

struct hkVector3CA8A {
    float x;
    float y;
    float z;
};

struct hkWorldOperationBaseCA8A {
    unsigned char m_type;
};


struct hkSetVelocityOpCA8A : public hkWorldOperationBaseCA8A {
    hkpEntity* m_pEntity;
    float m_fVelocity[3];

    hkSetVelocityOpCA8A() { m_type = 0x1b; }
};

class hkpWorldCA8A {
public:
    int unk00[0x25];
    int m_iCriticalOperationsLockCount;

    bool areCriticalOperationsLocked() const { return m_iCriticalOperationsLockCount != 0; }
    void hkpWorld_queueOperation(const hkWorldOperationBaseCA8A& kOperation) throw();
};


class hkpMotionCA8A {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void SetTranslationalVelocity(const hkVector3CA8A& v);
};

// Keep the velocity entry point on the shared entity layout.
class EntityVelocityAccess : public hkpEntity {
public:
    void hkpRigidBody_applyLinearImpulseAsCriticalOperation(const hkVector3CA8A& velocity);
};

// @fnv 0x00ca8a80
// src: HAVOK_LIB 0x00ca8a80
void EntityVelocityAccess::hkpRigidBody_applyLinearImpulseAsCriticalOperation(const hkVector3CA8A& akVelocity)
{
    if (m_pOwningWorld && ((hkpWorldCA8A*)m_pOwningWorld)->areCriticalOperationsLocked()) {
        hkSetVelocityOpCA8A kOp;
        kOp.m_pEntity = this;
        kOp.m_fVelocity[0] = akVelocity.x;
        kOp.m_fVelocity[1] = akVelocity.y;
        kOp.m_fVelocity[2] = akVelocity.z;
        ((hkpWorldCA8A*)m_pOwningWorld)->hkpWorld_queueOperation(kOp);
        return;
    }
    activate_00c9c1d0();
    ((hkpMotionCA8A*)&m_pMotionState)->SetTranslationalVelocity(akVelocity);
}

struct FUN_00ca94c0_Ctx {
    void* self;
    unsigned int arg;
    unsigned int result;
};
struct FUN_00ca94c0_Elem {
    virtual void Visit(FUN_00ca94c0_Ctx* ctx);
};
struct FUN_00ca94c0_Class {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    FUN_00ca94c0_Elem** m_pElements;
    int m_uiItemCount;
    int hkpPhantom_fireCollidableAdded(unsigned int arg);
};
// Iterates the element array backwards, calling Visit on each non-null element with a context holding self and arg, and returns the accumulated result.
// @fnv 0x00ca94c0
// src: HAVOK_LIB 0x00ca94c0
int FUN_00ca94c0_Class::hkpPhantom_fireCollidableAdded(unsigned int arg) {
    FUN_00ca94c0_Ctx ctx;
    ctx.self = this;
    ctx.arg = arg;
    ctx.result = 0;
    int i = m_uiItemCount - 1;
    if (i >= 0) {
        do {
            if (m_pElements[i]) {
                FUN_00ca94c0_Elem** slot = &m_pElements[i];
                (*slot)->Visit(&ctx);
            }
        } while (--i >= 0);
    }
    return ctx.result;
}

struct Allocator9 { void* __thiscall Game_DoHeapAlloc(unsigned int size); };
extern Allocator9 DAT_011f6238;
extern "C" int DAT_010c5dc0;
extern __declspec(thread) unsigned char threadContext9;
struct Guard9 {
    int previous;
    Guard9() {
        int* flag = (int*)((char*)&threadContext9 + 0x2b4);
        previous = *flag;
        *flag = 16;
    }
    ~Guard9() {
        int* flag = (int*)((char*)&threadContext9 + 0x2b4);
        *flag = previous;
    }
};
struct Node9 { void* vtable; int value; int references; int previous; int next; };
struct Class9 {
    void* unk00; void* unk04; int callbackFlag; int* data;
    void __thiscall CopyFromSource(Node9* node);
    int* __thiscall GetOrCreateData(unsigned char* wasEmpty);
};
// @fnv 0x00caa5d0
int* Class9::GetOrCreateData(unsigned char* wasEmpty) {
    Guard9 guard;
    *wasEmpty = (data == 0);
    if (*wasEmpty) {
        Node9* allocated = (Node9*)DAT_011f6238.Game_DoHeapAlloc(20);
        int* nextData;
        if (allocated) {
            int* contents = &allocated->value;
            allocated->references = 1;
            allocated->previous = 0;
            allocated->next = 0;
            allocated->vtable = &DAT_010c5dc0;
            *contents = 0;
            nextData = contents;
        } else nextData = 0;
        data = nextData;
        if (callbackFlag) CopyFromSource(data ? (Node9*)((char*)data - 4) : 0);
    }
    return data;
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

typedef unsigned int (__cdecl* ReadFn)(NiBinaryStream* pThis, void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);

inline unsigned int BinaryRead(NiBinaryStream* stream, void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes = 0, unsigned int uiNumComponents = 0)
{
    unsigned int uiBytes = ((ReadFn)*(ReadFn*)((char*)stream + 8))(stream, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *(unsigned int*)((char*)stream + 4) += uiBytes;
    return uiBytes;
}


template <class T>
inline unsigned int NiBinaryStreamLoad(NiBinaryStream* binstream, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    return BinaryRead(binstream, pValue, uiNumEls * sizeof(T), &uiSize, uiNumEls);
}

template <class T>
inline void ReadBinaryValue(NiStream& stream, T& value)
{
    NiBinaryStreamLoad(*(NiBinaryStream**)(((char*)&stream + 4) + 0x248), &value, 1);
}

extern "C" void __cdecl SwapEndianBlocks(void* p);

inline void SwapDword(unsigned long& val) {
    val = _byteswap_ulong(val);
}

inline void ByteSwapBlk(Blk40& blk)
{
    unsigned long* u = (unsigned long*)&blk;
    SwapDword(u[12]);
    SwapDword(u[13]);
    SwapDword(u[14]);
    SwapDword(u[15]);
    SwapEndianBlocks(&blk);
}

struct FUN_00d1df70 {
    void removeReference();
};

// The motor setter binds to 0x00cb8ac0, also used by ShapeCAA, rather than any include/Data.h method.
struct MotorConstraintStreamStorage : ConstraintStreamStorage {
    void SetReferencedObject(hkReferencedObject* obj);
};

struct FUN_00d53200_class {
    void* m_unk00;
    MotorConstraintStreamStorage* m_data;

    void hkConstraintCinfo_LoadBinary(NiStream& stream);
    hkReferencedObject* hkConstraintCinfo_LoadMotor(NiStream& stream);

    void ReadFromStream(void* streamContext);
};

// Reads the object's data blocks and floats from the stream, byte-swaps them when needed, and loads a referenced object for stream versions above 0x1d.
// @fnv 0x00caa6a0
void FUN_00d53200_class::ReadFromStream(void* streamContext)
{
    NiStream& stream = *(NiStream*)streamContext;
    hkConstraintCinfo_LoadBinary(stream);

    MotorConstraintStreamStorage* const data = m_data;

    BinaryRead(*(NiBinaryStream**)(((char*)&stream + 4) + 0x248), &data->m_20, 0x40);
    BinaryRead(*(NiBinaryStream**)(((char*)&stream + 4) + 0x248), &data->m_60, 0x40);
    ReadBinaryValue(stream, data->m_c4);
    ReadBinaryValue(stream, data->m_c8);
    float* const pDefaultFloat = (float*)&data->m_bc;
    ReadBinaryValue(stream, *pDefaultFloat);

    if (((char*)&stream + 4)[0x1e1] != 1) {
        ByteSwapBlk(data->m_20);
        ByteSwapBlk(data->m_60);
    }

    if (*(unsigned int*)((char*)&stream + 4) > 0x1d) {
        hkReferencedObject* obj = hkConstraintCinfo_LoadMotor(stream);
        data->SetReferencedObject(obj);
        if (obj) {
            ReadBinaryValue(stream, data->m_a2);
            ((FUN_00d1df70*)obj)->removeReference();
        }
    }

    if (*pDefaultFloat == 0.0f) {
        *pDefaultFloat = 100.0f;
    }
}

struct AudioTlsState {
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
 int unk200;
 int unk204;
 int unk208;
 int unk20C;
 int unk210;
 int unk214;
 int unk218;
 int unk21C;
 int unk220;
 int unk224;
 int unk228;
 int unk22C;
 int unk230;
 int unk234;
 int unk238;
 int unk23C;
 int unk240;
 int unk244;
 int unk248;
 int unk24C;
 int unk250;
 int unk254;
 int unk258;
 int unk25C;
 int unk260;
 int unk264;
 int unk268;
 int unk26C;
 int unk270;
 int unk274;
 int unk278;
 int unk27C;
 int unk280;
 int unk284;
 int unk288;
 int unk28C;
 int unk290;
 int unk294;
 int unk298;
 int unk29C;
 int unk2A0;
 int unk2A4;
 int unk2A8;
 int unk2AC;
 int unk2B0;
 int unk2B4;
};
__declspec(thread) AudioTlsState threadData;
struct MemoryScope {
 int previous;
 MemoryScope() {previous=threadData.unk2B4;threadData.unk2B4=16;}
 ~MemoryScope() {threadData.unk2B4=previous;}
};

NiPoint3& HK2NINS(NiPoint3&,const hkVector4&);
char* NiGetViewerString_00a7d550(const char*,float);
char* NiGetViewerString_00a7d5e0(const char*,const char*);
struct Strings {
 void* unk00; char** unk04;
 unsigned short unk08,unk0A,unk0C,unk0E;
 void FUN_0096ad30(unsigned);
 void FUN_0096ae90(unsigned,char*&);
 void Append(char* text) {
  unsigned n=unk0A;
  if(n>=unk08) FUN_0096ad30(n+unk0E);
  FUN_0096ae90(n,text);
 }
};
struct Constraint {
 int unk00;
 int unk04;
 int unk08;
 int unk0C;
 int unk10;
 int unk14;
 int unk18;
 int unk1C;
 int unk20;
 int unk24;
 int unk28;
 int unk2C;
 hkVector4 unk30;
 hkVector4 unk40;
 hkVector4 unk50;
 hkVector4 unk60;
 int unk70;
 int unk74;
 int unk78;
 int unk7C;
 int unk80;
 int unk84;
 int unk88;
 int unk8C;
 hkVector4 unk90;
 unsigned short unkA0; unsigned char unkA2,unkA3;
 int unkA4;
 int unkA8;
 float unkAC;
 int unkB0;
 int unkB4;
 int unkB8;
 float unkBC;
 int unkC0;
 float unkC4;
 float unkC8;
};
struct Owner {
 int unk00; Constraint* unk04;
 void hkConstraintCinfo_GetViewerStrings(Strings*);
 void AppendConstraintToStrings(Strings*);
};
// @fnv 0x00caa960
void Owner::AppendConstraintToStrings(Strings* strings) {
 MemoryScope scope;
 hkConstraintCinfo_GetViewerStrings(strings);
 Constraint* constraint=unk04;
 if(constraint) {
  NiPoint3 temp;
  HK2NINS(temp,constraint->unk50);
  strings->Append(temp.GetViewerString_00a59af0("PivotInA"));
  HK2NINS(temp,constraint->unk90);
  strings->Append(temp.GetViewerString_00a59af0("PivotInB"));
  HK2NINS(temp,constraint->unk60);
  strings->Append(temp.GetViewerString_00a59af0("AxleInB"));
  HK2NINS(temp,constraint->unk30);
  strings->Append(temp.GetViewerString_00a59af0("Perp2AxleInA1"));
  HK2NINS(temp,constraint->unk40);
  strings->Append(temp.GetViewerString_00a59af0("Perp2AxleInA2"));
  strings->Append(NiGetViewerString_00a7d550("MinAngle",float(constraint->unkC4*57.2957763671875)));
  strings->Append(NiGetViewerString_00a7d550("MaxAngle",float(constraint->unkC8*57.2957763671875)));
  strings->Append(NiGetViewerString_00a7d550("MaxFrictionTrq",constraint->unkBC));
  strings->Append(NiGetViewerString_00a7d5e0("Motor",constraint->unkA2 ? "Active" : "Inactive"));
  float motorAngle=constraint->unkAC;
  strings->Append(NiGetViewerString_00a7d550("MotorAngle",float(motorAngle*57.2957763671875)));
 }
}

class hkRefObjCBFB {
public:
    virtual ~hkRefObjCBFB() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjCBFB() { m_sReferenceCount = 1; }
};

class hkListenerACBFB {
public:
    virtual void a0() = 0;
};

class hkListenerBCBFB {
public:
    virtual void b0() = 0;
};

class hkListenerCCBFB {
public:
    virtual void c0() = 0;
};

class hkListenerDCBFB {
public:
    virtual void d0() = 0;
};

class FUN_00cbfba0 : public hkRefObjCBFB, public hkListenerACBFB, public hkListenerBCBFB, public hkListenerCCBFB, public hkListenerDCBFB {
public:
    int unk18;
    int unk1C;
    int m_20;

    FUN_00cbfba0() throw();
    virtual ~FUN_00cbfba0() throw();
    virtual void a0();
    virtual void b0();
    virtual void c0();
    virtual void d0();
};

// Initializes the object's m_20 field to 0.
// @fnv 0x00cbfba0
FUN_00cbfba0::FUN_00cbfba0() throw()
    : m_20(0)
{
}

// Reconstructed ClearIndexedValues (FNV 1.4.0.525, /MT /O2 /GS /EHsc /Gy).
// Stand-in declarations; unknown fields are named by their byte offset.
// External callees keep the pack's FUN_ names and bind through relocations.

struct Tls676 { char m_pad0000[0x2b4]; int m_2b4; };
__declspec(thread) Tls676 g_tls676;

struct Elem676;
struct Sub676 { char m_pad0000[0x14]; unsigned char m_14; };
struct Elem676 { char m_pad0000[0xc]; Sub676* m_iThirdValue; void removeReference(); };

struct Q676 {
    void hkpWorld_addPhantomBatch(Elem676** arr, int count);
    void hkpWorld_removePhantom(Elem676* e);
};

struct GC676 { void* m_p; int m_unused; };

struct Tmp676 { float m_f; unsigned char b0, b1, b2, b3, b4; };

struct GCObj676 {
    virtual void *g00(void*);
    virtual void *g01(void*);
    virtual void *g02(void*);
    virtual void *g03(void*);
    virtual void *g04(void*);
    virtual void *g05(void*);
    virtual void *g06(void*);
    virtual void *g07(void*);
    virtual void *g08(void*);
    virtual void *g09(void*);
    virtual void *g10(void*);
    virtual void *g11(void*);
    virtual void *g12(void*);
    virtual void *g13(void*);
    virtual void *g14(void*);
    virtual void *g15(void*);
    virtual void *g16(void*);
    virtual void *g17(void*);
    virtual void *g18(void*);
    virtual void *g19(void*);
    virtual void *g20(void*);
    virtual void *g21(void*);
    virtual void *g22(void*);
    virtual void *g23(void*);
    virtual void *g24(void*);
    virtual void *g25(void*);
    virtual void *g26(void*);
    virtual void *g27(void*);
    virtual void *g28(void*);
    virtual void *g29(void*);
    virtual void *g30(void*);
    virtual void *g31(void*);
    virtual void *g32(void*);
    virtual void *g33(void*);
    virtual void *g34(void*);
    virtual void *g35(void*);
    virtual void g36(void*);
};

struct This676 {
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void* v37();
    char m_pad0004[0x30];
    Elem676** m_aiIndexedValues;              // +0x34
    unsigned int m_uiItemCount;         // +0x38
    void ClearIndexedValues();
};

// Scoped override of the thread-local context field (0x10 during the operation).
struct Guard676 {
    int m_saved;
    Guard676() { m_saved = g_tls676.m_2b4; g_tls676.m_2b4 = 0x10; }
    ~Guard676() { g_tls676.m_2b4 = m_saved; }
};

extern GC676* bhkWorldObject_GetProperty(GC676* out, Elem676* obj, void* rtti);
extern void* FUN_00ec61c0(void* dst, int value, unsigned int size);
extern unsigned char DAT_01267b70;

// Caps the count at 200, then for each array element updates it via the v37 queue, calls g36, removes its reference, and finally zeroes the array and count.
// @fnv 0x00c676e0
void This676::ClearIndexedValues()
{
    Guard676 guard;
    if (m_uiItemCount > 0u)
    {
        if (m_uiItemCount >= 200u) m_uiItemCount = 200u;
        Q676* q = (Q676*)v37();
        if (q != 0)
        {
            q->hkpWorld_addPhantomBatch(m_aiIndexedValues, (int)m_uiItemCount);
            for (unsigned int i = 0; i < m_uiItemCount; i++)
            {
                Elem676* e = m_aiIndexedValues[i];
                if (e != 0)
                {
                    Sub676* c = e->m_iThirdValue;
                    if (c != 0)
                    {
                        c->m_14 &= 0xef;
                        goto body_cont;
                    }
                }
                q->hkpWorld_removePhantom(e);
body_cont:
                ;
                Elem676* e2 = m_aiIndexedValues[i];
                GC676 slot;
                GC676* r = bhkWorldObject_GetProperty(&slot, e2, &DAT_01267b70);
                GCObj676* o = (GCObj676*)r->m_p;
                if (o != 0)
                {
                    Tmp676 tmp = { 0.0f, 0, 0, 0, 0, 0 };
                    o->g36(&tmp);
                }
                m_aiIndexedValues[i]->removeReference();
            }
            FUN_00ec61c0(m_aiIndexedValues, 0, m_uiItemCount * 4);
            m_uiItemCount = 0;
        }
    }
}

struct BoolC68BF0 {
    char m_cBooleanValue;
};
struct HkEntityC68BF0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m_uiValue1;
};
struct EntityC68BF0;
struct HkWorldC68BF0 {
    BoolC68BF0 ProcessTarget(EntityC68BF0* pkEntity);
};
struct EntityC68BF0 {
    void FUN_00c90510();
    int unk00;
    int unk04;
    int unk08;
    HkEntityC68BF0* m_pkHkEntity;
};
struct WorldC68BF0 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual HkWorldC68BF0* GetHavokWorld();
    void ProcessPendingItems();
    void ReleaseBodies();
    void ClearReferences();
    void FlushEntries();
    bool bhkWorld_Remove(EntityC68BF0* pkEntity);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiBatchDepth;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    EntityC68BF0** m_ppkPendingAdds;
    unsigned int m_uiNumPendingAdds;
};

// While batching, queues pkEntity in the pending-adds array (flushing at 3000); otherwise calls ProcessTarget on the Havok world; true if skipped or added.
// @fnv 0x00c68bf0
// src: XBOX_PDB 0x00c68bf0
bool WorldC68BF0::bhkWorld_Remove(EntityC68BF0* pkEntity)
{
    bool bResult = false;
    HkWorldC68BF0* pkWorld = GetHavokWorld();
    if (pkWorld && pkEntity)
    {
        if (m_uiBatchDepth > 0)
        {
            HkEntityC68BF0* pkHkEntity = pkEntity->m_pkHkEntity;
            if (!pkHkEntity || (pkHkEntity->m_uiValue1 & 0x30))
                return true;
            pkHkEntity->m_uiValue1 |= 0x20;
            if (m_uiNumPendingAdds >= 3000)
            {
                ProcessPendingItems();
                ReleaseBodies();
                ClearReferences();
                FlushEntries();
            }
            pkEntity->FUN_00c90510();
            m_ppkPendingAdds[m_uiNumPendingAdds] = pkEntity;
            m_uiNumPendingAdds++;
            bResult = true;
        }
        else
        {
            HkEntityC68BF0* pkHkEntity = pkEntity->m_pkHkEntity;
            if (!pkHkEntity || (pkHkEntity->m_uiValue1 & 0x30))
                return true;
            bResult = pkWorld->ProcessTarget(pkEntity).m_cBooleanValue != 0;
        }
    }
    return bResult;
}

struct FUN_00c91000_Class
{
    LocalM128 m_iWordAt00;
    LocalM128 m_10;

    void __thiscall UpdateFields_00c91000(const LocalM128* value);
};

// @fnv 0x00c91000
// src: GUESS 0x00c91000 (confidence: low)
void FUN_00c91000_Class::UpdateFields_00c91000(const LocalM128* value)
{
    m_10 = *value;
}

struct FUN_00c91620_Target;

struct FUN_00c91620_Args {
    unsigned char type;
    FUN_00c91620_Target* target;
};

struct FUN_00c91620_Aux {
    void* m_00; void* m_04; void* m_08; void* m_0c;
    void* m_10; void* m_14; void* m_18; void* m_1c; void* m_20;
    void FreeStorage();
};

struct FUN_00c91620_Target {
    virtual void vf00(); virtual void vf04(); virtual void vf08();
    virtual void vf0c(); virtual void vf10(); virtual void vf14();

    unsigned short m_04;
    void* m_08; void* m_0c; void* m_10; void* m_14;
    void* m_18; void* m_1c; void* m_20; void* m_24;
    void* m_28; void* m_2c;
    FUN_00c91620_Aux m_30;
    int m_54;

    void FUN_00c905b0();
};

struct FUN_00c91620_Class {
    void* m_00; void* m_04; void* m_08; void* m_0c;
    void* m_10; void* m_14; void* m_18; void* m_1c;
    void* m_20; void* m_24; void* m_28; void* m_2c;
    void* m_30; void* m_34; void* m_38; void* m_3c;
    void* m_40; void* m_44; void* m_48; void* m_4c;
    void* m_50; void* m_54; void* m_58; void* m_5c;
    void* m_60; void* m_64; void* m_68; void* m_6c;
    void* m_70; void* m_74; void* m_78; void* m_7c;
    void* m_80; void* m_84; void* m_88; void* m_8c;
    void* m_90;
    int m_94;
    void* m_98;
    unsigned char m_9c;
    unsigned char m_9d;
    void* m_a0;
    int m_a4;
    void hkpWorld_queueOperation(FUN_00c91620_Args* args);
    void FUN_00c91120();
    void UpdateFields_00c91140();
    unsigned char* ProcessTarget(unsigned char* result, FUN_00c91620_Target* target);
};

void __cdecl hkpWorldOperationUtil_removeEntityBP(FUN_00c91620_Class* self, FUN_00c91620_Target* target);
void __cdecl hkpWorldCallbackUtil_fireEntityRemoved(FUN_00c91620_Class* self, FUN_00c91620_Target* target);
void __cdecl hkpEntityCallbackUtil_fireEntityRemoved(FUN_00c91620_Target* target);
void __cdecl hkpWorldOperationUtil_removeEntitySI(FUN_00c91620_Class* self, FUN_00c91620_Target* target);

// If m_94 is nonzero, calls FUN_00c91160 with type 2 and writes 0 to *result; otherwise runs the helper calls on target and writes 1 to *result.
// @fnv 0x00c91620
unsigned char* FUN_00c91620_Class::ProcessTarget(
    unsigned char* result, FUN_00c91620_Target* target)
{
    if (m_94 != 0) {
        FUN_00c91620_Args args;
        args.type = 2;
        args.target = target;
        hkpWorld_queueOperation(&args);
        *result = 0;
        return result;
    }

    m_94 = 1;
    hkpWorldOperationUtil_removeEntityBP(this, target);
    hkpWorldCallbackUtil_fireEntityRemoved(this, target);
    hkpEntityCallbackUtil_fireEntityRemoved(target);
    m_9d = 0;
    hkpWorldOperationUtil_removeEntitySI(this, target);

    if (target->m_54 != 0) {
        target->m_30.FreeStorage();
    }

    if (target->m_04 == 0) {
        target->vf14();
    }
    target->FUN_00c905b0();

    --m_94;
    m_9d = 1;

    if (m_94 == 0 && m_9c == 0) {
        if (m_8c != 0)
            FUN_00c91120();
        if (m_a4 == 1 && m_90 != 0)
            UpdateFields_00c91140();
    }
    *result = 1;
    return result;
}


class hkWorldXc91700 {
public:
    int unk000[71];
    hkArray<void*> m_entries;

    void hkpWorld_removeActionListener(void* entry);
};

// Sets the array slot containing the given entry to null by looking up its index in m_entries.
// @fnv 0x00c91700
// src: HAVOK_LIB 0x00c91700
void hkWorldXc91700::hkpWorld_removeActionListener(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}


class hkWorldC9175 {
public:
    int unk000[80];
    hkArray<void*> m_entries;

    void hkpWorld_removeConstraintListener(void* entry);
};

// Sets the entry at the index found by indexOf to 0, clearing it from the m_entries array.
// @fnv 0x00c91750
// src: HAVOK_LIB 0x00c91750
void hkWorldC9175::hkpWorld_removeConstraintListener(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}


class hkWorldC917 {
public:
    int unk000[74];
    hkArray<void*> m_entries;

    void hkpWorld_removeEntityListener(void* entry);
};

// Sets the m_entries slot at indexOf(entry) to null.
// @fnv 0x00c917a0
// src: HAVOK_LIB 0x00c917a0
void hkWorldC917::hkpWorld_removeEntityListener(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}


class hkWorldC91F {
public:
    int unk000[77];
    hkArray<void*> m_entries;

    void hkpWorld_removePhantomListener(void* entry);
};

// Sets the array slot containing the given entry to null.
// @fnv 0x00c917f0
// src: HAVOK_LIB 0x00c917f0
void hkWorldC91F::hkpWorld_removePhantomListener(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}


class hkWorldC918 {
public:
    int unk000[95];
    hkArray<void*> m_entries;

    void hkpWorld_removeWorldPostCollideListener(void* entry);
};

// Sets the array slot at indexOf(entry) to 0, clearing the entry from m_entries.
// @fnv 0x00c91890
// src: HAVOK_LIB 0x00c91890
void hkWorldC918::hkpWorld_removeWorldPostCollideListener(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}


class hkWorldXc91930 {
public:
    int unk000[92];
    hkArray<void*> m_entries;

    void hkpWorld_removeWorldPostIntegrateListener(void* entry);
};

// Sets the entry at the index found by indexOf to 0, clearing the slot in the m_entries array.
// @fnv 0x00c91930
// src: HAVOK_LIB 0x00c91930
void hkWorldXc91930::hkpWorld_removeWorldPostIntegrateListener(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}


class hkWorldXc91980 {
public:
    int unk000[101];
    hkArray<void*> m_entries;

    void hkpWorld_removeIslandPostCollideListener(void* entry);
};

// Sets the entry at the index found by indexOf to 0, clearing it from the m_entries array.
// @fnv 0x00c91980
// src: HAVOK_LIB 0x00c91980
void hkWorldXc91980::hkpWorld_removeIslandPostCollideListener(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}


class hkWorldXc91a20 {
public:
    int unk000[104];
    hkArray<void*> m_entries;

    void hkpWorld_removeContactListener(void* entry);
};

// Sets the entry at the index found by indexOf to 0, clearing the slot in m_entries.
// @fnv 0x00c91a20
// src: HAVOK_LIB 0x00c91a20
void hkWorldXc91a20::hkpWorld_removeContactListener(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}


class hkWorldXc91a70 {
public:
    int unk000[83];
    hkArray<void*> m_entries;

    void hkpWorld_removeWorldDeletionListener(void* entry);
};

// Sets the m_entries slot at indexOf(entry) to null.
// @fnv 0x00c91a70
// src: HAVOK_LIB 0x00c91a70
void hkWorldXc91a70::hkpWorld_removeWorldDeletionListener(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}


class hkWorldXc91ac0 {
public:
    int unk000[107];
    hkArray<void*> m_entries;

    void hkpWorld_removeContactImpulseLimitBreachedListener(void* entry);
};

// Sets the entry at the index found by indexOf to null.
// @fnv 0x00c91ac0
// src: HAVOK_LIB 0x00c91ac0
void hkWorldXc91ac0::hkpWorld_removeContactImpulseLimitBreachedListener(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}

struct Allocator {
    virtual void v00();
    virtual void* Allocate(int size);
    virtual void Deallocate(void* p, int size);
};

struct ThreadStorage {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Allocator* m_pThreadAllocator;
};

void* hkMemoryRouter_getInstance();
int __fastcall hkSemaphore_acquire(void*);

struct JobHeader {
    unsigned char m_eJobType;
    unsigned char m_ucSubType;
    unsigned char m_executionFlags;
    unsigned char unk03;
    unsigned short m_jobSize;
    short m_iAffinity;

    JobHeader(unsigned char type, unsigned char subType, unsigned short size, short affinity = -1)
        : m_eJobType(type), m_ucSubType(subType), m_jobSize(size), m_iAffinity(affinity) {}
};

struct RayCastCommand {
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    int m_uiFilterInfo;
    int m_ulUserData;
    void* m_pResultBuffer;
    int m_iResultCount;
    int m_iResultCapacity;
    int unk34;
    int unk38;
    int unk3C;
};

struct JobDoneHeader {
    int m_iJobId;
    int unk04;
    int unk08;
    int unk0C;
};

struct JobBase {
    JobHeader m_kHeader;
    int unk08;
    int unk0C;
    void* m_pCompletionSemaphore;
    JobDoneHeader* m_pJobDoneHeader;
    int unk18;

    __forceinline JobBase(unsigned char subType, unsigned short size)
        : m_kHeader(1, subType, size)
    {
        unk18 = 0;
        m_kHeader.m_executionFlags = 1;
    }
};

__declspec(align(16)) struct Job : JobBase {
    void* m_pCollisionInput;
    int m_iFirstIndex;
    RayCastCommand* m_pCommands;
    int m_iCommandCount;
    int unk2C;
    int unk30;
    void* m_pJobSemaphore;
    int unk38;
    void* m_kdTreeUnk0C;
    void* m_kdTreeUnk10;
    int unk44;
    int unk48;
    int unk4C;

    __forceinline Job(void* input, JobDoneHeader* jobHeader, RayCastCommand* commandArray, int numCommands, void* broadphase, void* semaphore)
        : JobBase(3, sizeof(Job))
    {
        m_pJobDoneHeader = jobHeader;
        m_pCollisionInput = input;
        m_pCompletionSemaphore = semaphore;
        m_iFirstIndex = sizeof(RayCastCommand);
        m_pCommands = commandArray;
        m_iCommandCount = numCommands;
        m_pJobSemaphore = broadphase;
        m_pJobDoneHeader->m_iJobId = (numCommands == 0) ? 1 : (numCommands - 1) / 64 + 1;
        unk38 = 0;
        m_kdTreeUnk0C = 0;
        m_kdTreeUnk10 = 0;
        unk2C = 0;
        unk30 = 0;
    }
};

struct JobQueue {
    void AddObjectCopy(const Job& job, int priority);
};

struct ThreadPool {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void processWork(JobQueue* queue, int type);
    virtual void RunWorkerThread();
};

struct KdTreeManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual bool isTreeActive();
    int unk04;
    int unk08;
    void* m_treeData0C;
    void* m_treeData10;
};

struct hkpWorldHelper : hkpWorld {
    void ExecuteRayCastJobs(RayCastCommand* commandArray, int numCommands, JobQueue* jobQueue, ThreadPool* threadPool, void* semaphore, int numCommandsPerJob);
};

// Splits the commands into jobs of numCommandsPerJob queued on jobQueue, runs the thread pool, then calls FUN_00d04380 on semaphore.
// @fnv 0x00c92110
void hkpWorldHelper::ExecuteRayCastJobs(RayCastCommand* commandArray, int numCommands, JobQueue* jobQueue, ThreadPool* threadPool, void* semaphore, int numCommandsPerJob) {
    ThreadStorage* ts = (ThreadStorage*)hkMemoryRouter_getInstance();
    JobDoneHeader* jobHeader = (JobDoneHeader*)ts->m_pThreadAllocator->Allocate(sizeof(JobDoneHeader));

    Job job(m_pCollisionInput, jobHeader, commandArray, numCommands, m_pJobSemaphore, semaphore);

    if (m_pKdTreeManager && ((KdTreeManager*)m_pKdTreeManager)->isTreeActive()) {
        KdTreeManager* kd = (KdTreeManager*)m_pKdTreeManager;
        job.m_kdTreeUnk0C = kd->m_treeData0C;
        job.m_kdTreeUnk10 = kd->m_treeData10;
        job.m_pJobSemaphore = 0;
    }

    while (job.m_iCommandCount > 0) {
        Job subJob = job;
        subJob.m_iCommandCount = (job.m_iCommandCount < numCommandsPerJob) ? job.m_iCommandCount : numCommandsPerJob;
        job.m_pCommands += numCommandsPerJob;
        job.m_iCommandCount -= numCommandsPerJob;
        jobQueue->AddObjectCopy(subJob, 1);
    }

    threadPool->processWork(jobQueue, 0xb);
    threadPool->RunWorkerThread();

    hkSemaphore_acquire(semaphore);

    ts = (ThreadStorage*)hkMemoryRouter_getInstance();
    ts->m_pThreadAllocator->Deallocate(jobHeader, sizeof(JobDoneHeader));
}

namespace fnv_00c92290 {
struct Allocator {
    virtual void v00();
    virtual void* Allocate(int size);
    virtual void Deallocate(void* p, int size);
};

struct ThreadStorage {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Allocator* m_pThreadAllocator;
};

void* hkMemoryRouter_getInstance();
int __fastcall hkSemaphore_acquire(void*);

struct CollisionInput {
    int unk00;
    int unk04;
    float m_fScalar;
};

struct JobHeader {
    unsigned char m_ucSubType;
    unsigned char m_eJobType;
    unsigned char m_eSpuType;
    unsigned char unk03;
    unsigned short m_iElementCount;
    short m_iAffinity;

    JobHeader(unsigned char subType, unsigned char type, unsigned short size, unsigned char spuType)
        : m_ucSubType(subType), m_eJobType(type), m_eSpuType(spuType), m_iElementCount(size), m_iAffinity(-1) {}
};

struct ClosestPointsCommand {
    int unk00;
    int unk04;
    int unk08;
    int m_iResultCapacity;
};

struct JobDoneHeader {
    int m_iJobId;
    int unk04;
    int unk08;
    int unk0C;
};

struct CollisionQueryJob {
    JobHeader m_kHeader;
    int unk08;
    int unk0C;
    void* m_pCompletionSemaphore;
    JobDoneHeader* m_pJobDoneHeader;
    CollisionInput* m_pCollisionInput;
    int unk1C;

    __forceinline CollisionQueryJob(unsigned char subType, unsigned short size)
        : m_kHeader(subType, 2, size, 2)
    {
        unk1C = 0;
    }
};

__declspec(align(16)) struct ClosestPointsJob : CollisionQueryJob {
    void* m_pJobSemaphore;
    void* m_kdTreeUnk0C;
    void* m_kdTreeUnk10;
    float m_fScalar;
    int m_maxNumResults;
    ClosestPointsCommand* m_pCommands;
    int m_iCommandCount;
    int unk3C;

    __forceinline ClosestPointsJob(CollisionInput* input, JobDoneHeader* jobHeader, ClosestPointsCommand* commandArray, int numCommands, void* broadphase, float tolerance, void* semaphore)
        : CollisionQueryJob(2, sizeof(ClosestPointsJob))
    {
        for (int i = 0; i < numCommands; i++)
        {
            commandArray[i].m_iResultCapacity = 0;
        }
        m_iCommandCount = numCommands;
        m_pCollisionInput = input;
        m_pJobSemaphore = broadphase;
        m_fScalar = tolerance;
        m_pCompletionSemaphore = semaphore;
        m_pCommands = commandArray;
        m_pJobDoneHeader = jobHeader;
        m_maxNumResults = 0x40;
        jobHeader->m_iJobId = (numCommands - 1) / 64 + 1;
        m_kdTreeUnk0C = 0;
        m_kdTreeUnk10 = 0;
    }

    void nullsub_9();
};

struct JobQueue {
    void AddObjectCopy(const ClosestPointsJob& job, int priority);
};

struct ThreadPool {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void processWork(JobQueue* queue, int type);
    virtual void RunWorkerThread();
};

struct KdTreeManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual bool isTreeActive();
    int unk04;
    int unk08;
    void* m_treeData0C;
    void* m_treeData10;
};

struct hkpWorldHelper : hkpWorld {
    void SubmitClosestPointsJobs(ClosestPointsCommand* commandArray, int numCommands, JobQueue* jobQueue, ThreadPool* threadPool, void* semaphore, int numCommandsPerJob);
};

// Splits commandArray into ClosestPointsJob batches, queues them on jobQueue, runs threadPool, calls FUN_00d04380(semaphore), and frees the job header.
// @fnv 0x00c92290
void hkpWorldHelper::SubmitClosestPointsJobs(ClosestPointsCommand* commandArray, int numCommands, JobQueue* jobQueue, ThreadPool* threadPool, void* semaphore, int numCommandsPerJob) {
    ThreadStorage* ts = (ThreadStorage*)hkMemoryRouter_getInstance();
    JobDoneHeader* jobHeader = (JobDoneHeader*)ts->m_pThreadAllocator->Allocate(sizeof(JobDoneHeader));

    CollisionInput* input = (CollisionInput*)m_pCollisionInput;
    ClosestPointsJob job(input, jobHeader, commandArray, numCommands, m_pJobSemaphore, input->m_fScalar, semaphore);
    job.nullsub_9();

    if (m_pKdTreeManager && ((KdTreeManager*)m_pKdTreeManager)->isTreeActive()) {
        KdTreeManager* kd = (KdTreeManager*)m_pKdTreeManager;
        job.m_kdTreeUnk0C = kd->m_treeData0C;
        job.m_kdTreeUnk10 = kd->m_treeData10;
        job.m_pJobSemaphore = 0;
    }

    while (job.m_iCommandCount > 0) {
        ClosestPointsJob subJob = job;
        subJob.m_iCommandCount = (job.m_iCommandCount < numCommandsPerJob) ? job.m_iCommandCount : numCommandsPerJob;
        job.m_pCommands += numCommandsPerJob;
        job.m_iCommandCount -= numCommandsPerJob;
        jobQueue->AddObjectCopy(subJob, 1);
    }

    threadPool->processWork(jobQueue, 0xb);
    threadPool->RunWorkerThread();

    hkSemaphore_acquire(semaphore);

    ts = (ThreadStorage*)hkMemoryRouter_getInstance();
    ts->m_pThreadAllocator->Deallocate(jobHeader, sizeof(JobDoneHeader));
}
}  // namespace fnv_00c92290

extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern unsigned int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int);
extern const char str_010c64b8[];
extern const char str_010c41f8[];
extern void* DAT_010c6488;
extern float DAT_0104da4c;
struct TimerEntry { const char* name; unsigned int ticks; unsigned int unk08; };
struct TimerBuffer { unsigned int unk00; TimerEntry* current; unsigned int unk08; TimerEntry* end; };
struct __declspec(align(16)) LinearCaster {
    void* unk00;
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
    float unk80;
    void ComputeValues_00cfaed0(void*,void*,void*,void*,void*,int,int,void*,void*);
};
struct QueryTree {
    virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0C();
    virtual bool enabled();
    virtual void slot14(); virtual void slot18(); virtual void slot1C();
    virtual void cast(void*,void*,void*,void*,int,void*,void*);
};
struct CollisionInput {
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
    int unk70;
};
struct WorldQuery : hkpWorld { void hkpWorld_linearCast(void*,void*,void*,void*); };
// Records a timer, then performs a collision cast via the KD-tree manager if enabled, otherwise via a linear caster, and records a second timer.
// @fnv 0x00c92430
// src: COMMUNITY 0x00c92430
void WorldQuery::hkpWorld_linearCast(void* a,void* b,void* c,void* d) {
    TimerBuffer* timer = (TimerBuffer*)TlsGetValue(DAT_0126835c);
    TimerEntry* entry = timer->current;
    if (entry < timer->end) {
        entry->name = str_010c64b8;
        _ReadWriteBarrier();
        volatile unsigned int ticks = (unsigned int)__rdtsc();
        entry->ticks = ticks;
        timer->current = entry + 1;
    }
    if (m_pKdTreeManager && ((QueryTree*)m_pKdTreeManager)->enabled()) {
        void* filter = m_pCollisionFilter ? (char*)m_pCollisionFilter+8 : 0;
        CollisionInput* input = (CollisionInput*)m_pCollisionInput;
        ((QueryTree*)m_pKdTreeManager)->cast(a,b,filter,input,input->unk70,c,d);
    } else {
        LinearCaster caster;
        caster.unk80 = DAT_0104da4c;
        caster.unk00 = &DAT_010c6488;
        caster.unk24 = 0;
        caster.ComputeValues_00cfaed0(m_pJobSemaphore,a,b,m_pCollisionFilter ? (char*)m_pCollisionFilter+8 : 0,m_pCollisionInput,((CollisionInput*)m_pCollisionInput)->unk70,0,c,d);
    }
    timer = (TimerBuffer*)TlsGetValue(DAT_0126835c);
    entry = timer->current;
    if (entry < timer->end) {
        entry->name = str_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned int ticks = (unsigned int)__rdtsc();
        entry->ticks = ticks;
        timer->current = entry + 1;
    }
}

namespace fnv_00c92540 {
struct Allocator {
    virtual void v00();
    virtual void* Allocate(int size);
    virtual void Deallocate(void* p, int size);
};

struct ThreadStorage {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Allocator* m_pThreadAllocator;
};

void* hkMemoryRouter_getInstance();
int __fastcall hkSemaphore_acquire(void*);

struct JobHeader {
    unsigned char m_eJobType;
    unsigned char m_ucSubType;
    unsigned char m_executionFlags;
    unsigned char unk03;
    unsigned short m_jobSize;
    short m_iAffinity;

    JobHeader(unsigned char type, unsigned char subType, unsigned short size, short affinity = -1)
        : m_eJobType(type), m_ucSubType(subType), m_jobSize(size), m_iAffinity(affinity) {}
};

struct LinearCastCommand {
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    int m_uiFilterInfo;
    void* m_pResultBuffer;
    int m_iResultCount;
    int m_iResultCapacity;
};

struct JobDoneHeader {
    int m_iJobId;
    int unk04;
    int unk08;
    int unk0C;
};

struct JobBase {
    JobHeader m_kHeader;
    int unk08;
    int unk0C;
    void* m_pCompletionSemaphore;
    JobDoneHeader* m_pJobDoneHeader;
    void* m_pCollisionInput;
    int unk1C;

    __forceinline JobBase(unsigned char subType, unsigned short size)
        : m_kHeader(4, subType, size)
    {
        unk1C = 0;
    }
};

__declspec(align(16)) struct Job : JobBase {
    int m_maxNumResults;
    LinearCastCommand* m_pCommands;
    int m_iCommandCount;
    void* m_pJobSemaphore;
    int unk30;
    void* m_kdTreeUnk0C;
    void* m_kdTreeUnk10;
    int unk3C;

    __forceinline Job(void* input, JobDoneHeader* jobHeader, LinearCastCommand* commandArray, int numCommands, void* broadphase, void* semaphore)
        : JobBase(2, sizeof(Job))
    {
        m_pJobDoneHeader = jobHeader;
        m_pCollisionInput = input;
        m_maxNumResults = 0x40;
        m_pCompletionSemaphore = semaphore;
        m_pCommands = commandArray;
        m_iCommandCount = numCommands;
        m_pJobSemaphore = broadphase;
        jobHeader->m_iJobId = (numCommands - 1) / 64 + 1;
        unk30 = 0;
        m_kdTreeUnk0C = 0;
        m_kdTreeUnk10 = 0;
    }
};

struct JobQueue {
    void AddObjectCopy(const Job& job, int priority);
};

struct ThreadPool {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void processWork(JobQueue* queue, int type);
    virtual void RunWorkerThread();
};

struct KdTreeManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual bool isTreeActive();
    int unk04;
    int unk08;
    void* m_treeData0C;
    void* m_treeData10;
};

struct hkpWorldHelper : hkpWorld {
    void ExecuteLinearCastCommands(LinearCastCommand* commandArray, int numCommands, JobQueue* jobQueue, ThreadPool* threadPool, void* semaphore, int numCommandsPerJob);
};

// Splits the commands into jobs of numCommandsPerJob queued on jobQueue, runs the thread pool, then calls FUN_00d04380 on semaphore.
// @fnv 0x00c92540
void hkpWorldHelper::ExecuteLinearCastCommands(LinearCastCommand* commandArray, int numCommands, JobQueue* jobQueue, ThreadPool* threadPool, void* semaphore, int numCommandsPerJob) {
    ThreadStorage* ts = (ThreadStorage*)hkMemoryRouter_getInstance();
    JobDoneHeader* jobHeader = (JobDoneHeader*)ts->m_pThreadAllocator->Allocate(sizeof(JobDoneHeader));

    Job job(m_pCollisionInput, jobHeader, commandArray, numCommands, m_pJobSemaphore, semaphore);

    if (m_pKdTreeManager && ((KdTreeManager*)m_pKdTreeManager)->isTreeActive()) {
        KdTreeManager* kd = (KdTreeManager*)m_pKdTreeManager;
        job.m_pJobSemaphore = 0;
        job.m_kdTreeUnk0C = kd->m_treeData0C;
        job.m_kdTreeUnk10 = kd->m_treeData10;
    }
    job.m_kHeader.m_executionFlags = 1;

    while (job.m_iCommandCount > 0) {
        Job subJob = job;
        subJob.m_iCommandCount = (job.m_iCommandCount < numCommandsPerJob) ? job.m_iCommandCount : numCommandsPerJob;
        job.m_pCommands += numCommandsPerJob;
        job.m_iCommandCount -= numCommandsPerJob;
        jobQueue->AddObjectCopy(subJob, 1);
    }

    threadPool->processWork(jobQueue, 0xb);
    threadPool->RunWorkerThread();

    hkSemaphore_acquire(semaphore);

    ts = (ThreadStorage*)hkMemoryRouter_getInstance();
    ts->m_pThreadAllocator->Deallocate(jobHeader, sizeof(JobDoneHeader));
}
}  // namespace fnv_00c92540

extern "C" void __cdecl enumerateAllConstraintsInIsland(void* object, void* value);

struct zzVal_c92860 { void* v; };

// Calls FUN_00c927f0 on each owner in m_owners1 and m_owners2 with the given value.
// @fnv 0x00c92860
static __declspec(noinline) void InvokeOnAllOwners(FUN_00c928c0_Context* ctx, zzVal_c92860 value)
{
    void* v = value.v;
    FUN_00c928c0_ActionOwner** p = ctx->m_owners1;
    while (p != ctx->m_owners1 + ctx->m_ownerCount1)
    {
        enumerateAllConstraintsInIsland(*p, v);
        ++p;
    }

    p = ctx->m_owners2;
    while (p != ctx->m_owners2 + ctx->m_ownerCount2)
    {
        enumerateAllConstraintsInIsland(*p, v);
        ++p;
    }
}

FUN_00c928c0_Context* volatile zz_ctx_c92860 = 0;
void* volatile zz_val_c92860 = 0;

void zz_call_c92860(void)
{
    zzVal_c92860 s;
    s.v = zz_val_c92860;
    InvokeOnAllOwners(zz_ctx_c92860, s);
}

void __cdecl hkSmallArrayUtil__reserveMore(void* apvArray, int iSizeElem);

class EntityC92B;

class IslandC92B {
public:
    void RemoveEntry(EntityC92B* pkEntity);
    void AddItem(EntityC92B* pkEntity);
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned short m_usStorageIndex;
    unsigned short unk22;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int** m_pEntities;
};

class EntityC92B {
public:
    int unk00, unk04, unk08;
    IslandC92B* m_pSimulationIsland;
};

template <class T>
struct hkSmallArrayC92B {
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fff; }
    void AddBack(const T& e)
    {
        if (m_iElementCount == getCapacity())
            hkSmallArrayUtil__reserveMore(this, sizeof(T));
        m_data[m_iElementCount++] = e;
    }
};

class WorldC92B {
public:
    int unk00[0xcc / 4];
    IslandC92B* m_pFixedIsland;
    int unkD0[(0xe8 - 0xd0) / 4];
    unsigned char m_iMaxEntriesPerNarrowphaseToiTask;
    unsigned char unkE9[0x208 - 0xe9];
    hkSmallArrayC92B<EntityC92B*> m_kActorEntries;
};

class ListenerC92B {
public:
    void hkpWorld_attachActionToEntity(EntityC92B* pkEntity, WorldC92B* pkWorld);
};

void __cdecl hkpWorldOperationUtil_mergeIslands(ListenerC92B* pkThis, WorldC92B* pkWorld, int* pkCurrentObject);

// Appends pkEntity to m_kActorEntries; moves it to the fixed island if its island's storage index is 0xffff, else calls FUN_00cb5570 if islands differ.
// @fnv 0x00c92bd0
// src: HAVOK_LIB 0x00c92bd0
void ListenerC92B::hkpWorld_attachActionToEntity(EntityC92B* pkEntity, WorldC92B* pkWorld)
{
    pkWorld->m_kActorEntries.AddBack(pkEntity);
    IslandC92B* pkIsland = pkEntity->m_pSimulationIsland;
    if (pkIsland->m_usStorageIndex == 0xffff && pkWorld->m_iMaxEntriesPerNarrowphaseToiTask != 5) {
        pkIsland->RemoveEntry(pkEntity);
        pkWorld->m_pFixedIsland->AddItem(pkEntity);
        return;
    }
    if (pkWorld->m_pFixedIsland != pkIsland && pkWorld->m_iMaxEntriesPerNarrowphaseToiTask != 5)
        hkpWorldOperationUtil_mergeIslands(this, pkWorld, pkIsland->m_pEntities[0]);
}




class WorldC92C;
void __cdecl hkpWorldCallbackUtil_firePhantomRemoved(WorldC92C* pkWorld, hkpPhantom* pkAction);
void __cdecl hkpWorldOperationUtil_removePhantomBP(WorldC92C* pkWorld, hkpPhantom* pkAction);

struct RemoveActionOpC92C {
    unsigned char m_type;
    hkpPhantom* m_pAction;
};

class WorldC92C {
public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_iCriticalOperationsLockCountForPhantoms;
    bool m_bBlockExecutingPendingOperations;
    char unk09D[3];
    int unkA0;
    int m_iPendingOperationQueueCount;
    int unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC, unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4;
    int unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104;
    int unk108, unk10C;
    hkArray<hkpPhantom*> m_ppActions;

    bool areCriticalOperationsLocked() const
    {
        return m_iCriticalOperationsLockCount + m_iCriticalOperationsLockCountForPhantoms != 0;
    }
    void lockCriticalOperations() { m_iCriticalOperationsLockCount++; }
    void unlockCriticalOperations()
    {
        if (--m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
            if (m_iPendingOperationCount)
                FUN_00c91120();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
                UpdateFields_00c91140();
        }
    }
    void FUN_00c91120();
    void UpdateFields_00c91140();
    void hkpWorld_queueOperation(const RemoveActionOpC92C& kOp);
    void hkpWorld_removePhantom(hkpPhantom* pkAction);
};

// Removes pkAction from the world's action list, either by queueing a deferred removal or by executing it immediately under a critical lock.
// @fnv 0x00c92c70
// src: HAVOK_LIB 0x00c92c70
void WorldC92C::hkpWorld_removePhantom(hkpPhantom* pkAction)
{
    if (areCriticalOperationsLocked()) {
        RemoveActionOpC92C kOp;
        kOp.m_type = 0xe;
        kOp.m_pAction = pkAction;
        hkpWorld_queueOperation(kOp);
        return;
    }
    lockCriticalOperations();
    hkpWorldCallbackUtil_firePhantomRemoved(this, pkAction);
    pkAction->firePhantomRemoved();
    hkpWorldOperationUtil_removePhantomBP(this, pkAction);
    m_ppActions.removeAt(m_ppActions.indexOf(pkAction));
    pkAction->m_pOwningWorld = 0;
    if (pkAction->m_usMemSizeAndFlags == 0)
        pkAction->FreeListenerArrays();
    pkAction->removeReference();
    unlockCriticalOperations();
}




void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);


template <int SIZE>
__forceinline void copyAlignedWords(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

class hkOwnerXc937a0 {
public:
    int unk00[71];
    hkArray<void*> m_kNode;

    void hkpWorld_addActionListener(void* item);
};

// @fnv 0x00c937a0
// src: HAVOK_LIB 0x00c937a0
void hkOwnerXc937a0::hkpWorld_addActionListener(void* item)
{
    m_kNode.pushBack(item);
}










template <typename T> struct hkRefPtrC93 {
    __forceinline ~hkRefPtrC93() throw()
    {
        if (m_pRetainedObject) m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    __forceinline void operator=(T* e) throw()
    {
        if (e) e->addReference();
        if (m_pRetainedObject) m_pRetainedObject->removeReference();
        m_pRetainedObject = e;
    }
    T* m_pRetainedObject;
};

class WorldDeletableC93 {
public:
    virtual ~WorldDeletableC93() throw();
};

struct ChunkBufferC93 {
    __forceinline ~ChunkBufferC93() throw()
    {
        if (m_pBuffer) hkMemoryRouter::getInstance().heap().blockFree(m_pBuffer, 0x200);
    }
    void* m_pBuffer;
};

struct MtSimulationJobDataC93 {
    __forceinline void operator delete(void* p) throw() { if (p) hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(MtSimulationJobDataC93)); }
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
    ChunkBufferC93 m_kBuffer;
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
};

struct CollisionAgentConfigC93 {
    __forceinline void operator delete(void* p) throw() { if (p) hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(CollisionAgentConfigC93)); }
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

struct ProcessCollisionInputC93 {
    __forceinline void operator delete(void* p) throw() { if (p) hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(ProcessCollisionInputC93)); }
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    ChunkBufferC93 m_kBuffer;
    unsigned int unk68;
    unsigned int unk6c;
    CollisionAgentConfigC93* m_pConfiguration;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
};


extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(BSThreadCriticalSectionPC* pkSection);

struct CriticalSectionC93 {
    __forceinline void operator delete(void* p) throw() { if (p) hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(CriticalSectionC93)); }
    __forceinline ~CriticalSectionC93() throw() { DeleteCriticalSection(&m_kCriticalSection); }
    BSThreadCriticalSectionPC m_kCriticalSection;
};

struct BroadPhaseDispatcherC93 {
    __forceinline void operator delete(void* p) throw() { if (p) hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(BroadPhaseDispatcherC93)); }
    ~BroadPhaseDispatcherC93() throw();
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
};

struct WorldOperationQueueC93 {
    __forceinline void operator delete(void* p) throw() { if (p) hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(WorldOperationQueueC93)); }
    ~WorldOperationQueueC93() throw();
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
};

struct ViolatedConstraintArrayC93 {
    __forceinline void operator delete(void* p) throw() { if (p) hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(ViolatedConstraintArrayC93)); }
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
};


class FUN_00c93e50 : public hkReferencedObject {
public:
    virtual ~FUN_00c93e50() throw();
    void hkpWorld_removeAll() throw();
    hkBool IsEntityAdded(void* pkEntity) throw();

    hkReferencedObject* m_pSimulation;
    unsigned int unk0c;
    float m_gravityX;
    float m_gravityY;
    float m_gravityZ;
    float m_gravityW;
    WorldDeletableC93* m_pFixedIsland;
    void* m_pFixedRigidBody;
    hkArray<void*> m_kActiveSimulationIslands;
    hkArray<void*> m_kInactiveSimulationIslands;
    hkArray<void*> m_kDirtySimulationIslands;
    hkReferencedObject* m_pMaintenanceManager;
    hkRefPtrC93<hkReferencedObject> m_pMemoryWatchDog;
    bool m_bAssertOnRunningOutOfSolverMemory;
    hkReferencedObject* m_pJobSemaphore;
    hkReferencedObject* m_pKdTreeManager;
    bool m_bUseKdTree;
    BroadPhaseDispatcherC93* m_pBroadPhaseDispatcher;
    WorldDeletableC93* m_pPhantomBroadPhaseListener;
    WorldDeletableC93* m_pEntityEntityBroadPhaseListener;
    WorldDeletableC93* m_pBroadPhaseBorderListener;
    MtSimulationJobDataC93* m_pMultithreadedSimulationJobData;
    ProcessCollisionInputC93* m_pCollisionInput;
    hkReferencedObject* m_pCollisionFilter;
    hkReferencedObject* m_pDispatcher;
    hkReferencedObject* m_pConvexListCollisionFilter;
    WorldOperationQueueC93* m_pPendingOperations;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_iCriticalOperationsLockCountForPhantoms;
    bool m_bBlockExecutingPendingOperations;
    bool m_bBlockExecutingPendingOperationQueues;
    void* m_pPendingOperationQueues;
    int m_iPendingOperationQueueCount;
    unsigned int m_multiThreadCheckThreadId;
    unsigned int m_multiThreadCheckMarks;
    bool m_bProcessActionsInSingleThread;
    bool m_bAllowUnconstrainedIslandJob;
    unsigned int m_uiMinDesiredIslandSize;
    CriticalSectionC93* m_pModifyConstraintCriticalSection;
    int m_iIsLocked;
    CriticalSectionC93* m_pIslandDirtyListCriticalSection;
    CriticalSectionC93* m_pPropertyMasterLock;
    bool m_bWantSimulationIslands;
    float m_fSnapCollisionToConvexEdgeThreshold;
    float m_fSnapCollisionToConcaveEdgeThreshold;
    bool m_bEnableToiWeldRejection;
    bool m_bWantDeactivation;
    bool m_bActivateOnBodyTransformChange;
    float m_fDeactivationReferenceDistance;
    float m_fToiCollisionResponseRotateNormal;
    int m_iMaxSectorsPerMidphaseTask;
    bool m_bProcessToisMultithreaded;
    int m_iMaxSectorsPerNarrowphaseTask;
    int m_iMaxEntriesPerMidphaseToiTask;
    int m_iMaxEntriesPerNarrowphaseToiTask;
    float m_fSimplifiedToiPenetrationThreshold;
    float m_fToiPenetrationThreshold;
    float m_fHigherToiPenetrationThreshold;
    float m_fForcedToiPenetrationThreshold;
    unsigned int m_uiLastEntityUid;
    unsigned int m_uiLastIslandUid;
    unsigned int m_uiLastConstraintUid;
    hkArray<void*> m_kPhantoms;
    hkArray<void*> m_kActionListeners;
    hkArray<void*> m_kEntityListenerArray;
    hkArray<void*> m_kPhantomListeners;
    hkArray<void*> m_kConstraintListeners;
    hkArray<void*> m_kWorldDeletionListeners;
    hkArray<void*> m_kIslandActivationListeners;
    hkArray<void*> m_kWorldPostSimulationListeners;
    hkArray<void*> m_kWorldPostIntegrateListeners;
    hkArray<void*> m_kWorldPostCollideListeners;
    hkArray<void*> m_kIslandPostIntegrateListeners;
    hkArray<void*> m_kIslandPostCollideListeners;
    hkArray<void*> m_kContactListeners;
    hkArray<void*> m_kContactImpulseLimitBreachedListeners;
    ViolatedConstraintArrayC93* m_pViolatedConstraintArray;
    hkReferencedObject* m_pBroadPhaseBorder;
};

void __cdecl ClearSlotReference(FUN_00c93e50* pkWorld, WorldDeletableC93* pkIsland) throw();
void __cdecl hkpWorldCallbackUtil_fireWorldDeleted(FUN_00c93e50* pkWorld) throw();

// Releases owned resources, removes references to simulation components, and calls FUN_00c93580 and FUN_00d00e80 during cleanup.
// @fnv 0x00c93e50
FUN_00c93e50::~FUN_00c93e50() throw()
{
    delete m_pMultithreadedSimulationJobData;

    m_pMaintenanceManager->removeReference();
    m_pMaintenanceManager = 0;

    if (m_pModifyConstraintCriticalSection) {
        delete m_pModifyConstraintCriticalSection;
        m_pModifyConstraintCriticalSection = 0;
    }
    if (m_pPropertyMasterLock) {
        delete m_pPropertyMasterLock;
        m_pPropertyMasterLock = 0;
    }
    if (m_pIslandDirtyListCriticalSection) {
        delete m_pIslandDirtyListCriticalSection;
        m_pIslandDirtyListCriticalSection = 0;
    }

    m_pMemoryWatchDog = 0;

    hkpWorld_removeAll();

    IsEntityAdded(m_pFixedRigidBody);
    m_pFixedRigidBody = 0;

    ClearSlotReference(this, m_pFixedIsland);
    delete m_pFixedIsland;
    m_pFixedIsland = 0;

    hkpWorldCallbackUtil_fireWorldDeleted(this);

    m_pJobSemaphore->removeReference();
    m_pJobSemaphore = 0;
    m_pDispatcher->removeReference();
    m_pDispatcher = 0;

    delete m_pBroadPhaseDispatcher;

    if (m_pBroadPhaseBorder) m_pBroadPhaseBorder->removeReference();

    delete m_pPhantomBroadPhaseListener;
    delete m_pEntityEntityBroadPhaseListener;
    delete m_pBroadPhaseBorderListener;

    m_pCollisionFilter->removeReference();
    m_pConvexListCollisionFilter->removeReference();

    delete m_pCollisionInput->m_pConfiguration;
    delete m_pCollisionInput;

    m_pSimulation->removeReference();

    delete m_pPendingOperations;

    if (m_pKdTreeManager) m_pKdTreeManager->removeReference();

    delete m_pViolatedConstraintArray;
}

struct hkSmallArrayUtilC97 {
    static void __cdecl GrowArray(void* apvArray, int iSizeElem) throw();
};
template <typename T> struct hkSmallArrayC97 {
    int getCapacity() const { return m_iCapacityState & 0x3fff; }
    void AddBack(const T& t) throw()
    {
        if (m_iElementCount == getCapacity())
            hkSmallArrayUtilC97::GrowArray(this, sizeof(T));
        m_data[m_iElementCount++] = t;
    }
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
};

class hkpActionC97;
class hkpWorldC97;

class hkpSimulationIslandC97 {
public:
    bool isFixed() const { return m_usStorageIndex == 0xffff; }
    void RegisterAction(hkpActionC97* pkAction) throw();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned short m_usStorageIndex;
};


class hkpActionC97 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void GetEntities(hkArray<hkpEntity*>& kEntitiesOut) throw();
    void RetainReference() const throw();
    void setWorld(hkpWorldC97* pkWorld) { m_pOwningWorld = pkWorld; }
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkpWorldC97* m_pOwningWorld;
};

struct hkWorldOperationC97 {
    enum Type { ADD_ACTION = 0xa };
    struct TypeTag {
        TypeTag(Type eType) : m_type(static_cast<unsigned char>(eType)) {}
        unsigned char m_type;
    };
    struct AddActionCommand : public TypeTag {
        AddActionCommand() : TypeTag(ADD_ACTION) {}
        hkpActionC97* m_pAction;
    };
};

struct hkpWorldOperationUtilC97 {
    static void __cdecl ReenableCollisionBetweenEntityPair(hkpWorldC97* pkWorld, hkpEntity* pkEntityA, hkpEntity* pkEntityB) throw();
};
struct hkpWorldCallbackUtilC97 {
    static void __cdecl FireActionAdded(hkpWorldC97* pkWorld, hkpActionC97* pkAction) throw();
};

class hkpWorldC97 {
public:
    bool areCriticalOperationsLocked() const { return m_iCriticalOperationsLockCount != 0; }
    void lockCriticalOperations() { m_iCriticalOperationsLockCount++; }
    void unlockCriticalOperations() { m_iCriticalOperationsLockCount--; }
    __forceinline void attemptToExecutePendingOperations()
    {
        if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
            if (m_iPendingOperationCount)
                ExecutePendingOperations();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
                ExecutePendingOperationQueues();
        }
    }
    __forceinline void unlockAndAttemptToExecutePendingOperations()
    {
        unlockCriticalOperations();
        attemptToExecutePendingOperations();
    }
    void AddWorldOperation(const hkWorldOperationC97::TypeTag& kOperation) throw();
    void ExecutePendingOperations() throw();
    void ExecutePendingOperationQueues() throw();
    hkpActionC97* hkpWorld_addAction(hkpActionC97* pkAction) throw();

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
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_iCriticalOperationsLockCountForPhantoms;
    bool m_bBlockExecutingPendingOperations;
    bool m_bBlockExecutingPendingOperationQueues;
    void* m_pPendingOperationQueues;
    int m_iPendingOperationQueueCount;
};

// @fnv 0x00c97370
// src: HAVOK_LIB 0x00c97370
hkpActionC97* hkpWorldC97::hkpWorld_addAction(hkpActionC97* pkAction) throw()
{
    if (areCriticalOperationsLocked()) {
        hkWorldOperationC97::AddActionCommand kOp;
        kOp.m_pAction = pkAction;
        AddWorldOperation(kOp);
        return 0;
    }

    pkAction->RetainReference();
    lockCriticalOperations();

    hkInplaceArray<hkpEntity*, 4> kEntities;
    pkAction->GetEntities(kEntities);
    pkAction->setWorld(this);

    hkpEntity* pkFirstMovableEntity = 0;
    for (int i = 0; i < kEntities.GetLogicalSize(); i++) {
        ((hkSmallArrayC97<hkpAction*>*)&kEntities[i]->m_ppActions)->AddBack((hkpAction*)pkAction);

        hkpSimulationIslandC97* pkIsland = (hkpSimulationIslandC97*)kEntities[i]->m_pSimulationIsland;
        if (!pkIsland->isFixed()) {
            if (pkFirstMovableEntity == 0) {
                pkFirstMovableEntity = kEntities[i];
                pkIsland->RegisterAction(pkAction);
            } else if (pkFirstMovableEntity->m_pSimulationIsland != (hkpSimulationIsland*)pkIsland) {
                hkpWorldOperationUtilC97::ReenableCollisionBetweenEntityPair(this, pkFirstMovableEntity, kEntities[i]);
            }
        }
    }

    if (pkFirstMovableEntity == 0) {
        ((hkpSimulationIslandC97*)kEntities[0]->m_pSimulationIsland)->RegisterAction(pkAction);
    }

    unlockAndAttemptToExecutePendingOperations();
    hkpWorldCallbackUtilC97::FireActionAdded(this, pkAction);
    return pkAction;
}




namespace hkRouterC97E {
    extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}



struct InfoC97E {
    int unk00;
    int unk04;
    int m_08;
};

class FUN_00cf3ea0 : public hkReferencedObject {
public:
    int unk08[9];
    int m_2c;
    int unk30[2];

    FUN_00cf3ea0(void* a1, void* a2, InfoC97E* a3, bool a4) throw();
};

class FUN_00c97e30_C {
public:
    void hkpWorld_addConstraint(FUN_00cf3ea0* p);
    FUN_00cf3ea0* Create(void* a1, void* a2, InfoC97E* a3);
};

// Allocates a FUN_00cf3ea0 built from the arguments, copies a3->m_08 into its m_2c, passes it to FUN_00c97d30, and returns it.
// @fnv 0x00c97e30
FUN_00cf3ea0* FUN_00c97e30_C::Create(void* a1, void* a2, InfoC97E* apInfo)
{
    FUN_00cf3ea0* p = new FUN_00cf3ea0(a1, a2, apInfo, true);
    p->m_2c = apInfo->m_08;
    hkpWorld_addConstraint(p);
    return p;
}

struct C97E80PendingOperation {
    unsigned char m_type;
    void* m_pAction;
};
struct C97E80Action {
    virtual void function00();
    virtual void function04();
    virtual void function08();
    virtual void function0C();
    virtual void function10();
    virtual void function14();
    virtual int getReferenceCount();
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    void* m_owner44;
};
struct C97E80Owner {
    int unk00, unk04;
    hkpWorld* m_pOwningWorld;
};
struct C97E80PendingShell {
    void __thiscall hkpWorld_queueOperation(C97E80PendingOperation* operation);
};
struct C97E80RemoveShell {
    void __thiscall RemoveActionFromWorld(void* owner);
};
struct C97E80ActionChangeShell {
    void __thiscall RemoveReferenceFromSlots(hkpWorld* world);
};
struct C97E80ReleaseShell {
    void __thiscall FUN_00c905b0();
};
struct C97E80CleanupShell {
    void __thiscall FUN_00c91120();
    void __thiscall UpdateFields_00c91140();
};
void __cdecl hkpWorldOperationUtil_removeConstraintImmediately(hkpWorld* world, C97E80Action* action, int flags);
struct C97E80Return { bool m_iResultCode; };
struct C97E80World : hkpWorld {
    C97E80Return __thiscall hkpWorld_removeConstraint(C97E80Action* action);
};
// If m_iCriticalOperationsLockCount is nonzero, queues a type-9 pending operation and returns false; otherwise runs helper calls on action and returns true.
// @fnv 0x00c97e80
// src: HAVOK_LIB 0x00c97e80
C97E80Return __thiscall C97E80World::hkpWorld_removeConstraint(C97E80Action* action) {
    if (m_iCriticalOperationsLockCount) {
        C97E80PendingOperation operation;
        operation.m_type = 9;
        operation.m_pAction = action;
        ((C97E80PendingShell*)this)->hkpWorld_queueOperation(&operation);
        C97E80Return r = {false};
        return r;
    }

    m_iCriticalOperationsLockCount = 1;
    if (action->getReferenceCount() == 1 &&
        ((C97E80Owner*)action->m_owner44)->m_pOwningWorld == this) {
        ((C97E80RemoveShell*)this)->RemoveActionFromWorld(action->m_owner44);
    }
    ((RefObj*)action)->FUN_00c90510();
    hkpWorldOperationUtil_removeConstraintImmediately(this, action, 1);
    ((C97E80ActionChangeShell*)action)->RemoveReferenceFromSlots(this);
    ((C97E80ReleaseShell*)action)->FUN_00c905b0();
    --m_iCriticalOperationsLockCount;
    if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
        if (m_iPendingOperationCount) {
            ((C97E80CleanupShell*)this)->FUN_00c91120();
        }
        if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount) {
            ((C97E80CleanupShell*)this)->UpdateFields_00c91140();
        }
    }
    C97E80Return r = {true};
    return r;
}

// Returns the larger of fA and fB.
// @fnv 0x00c98210
// src: GAMEBRYO_LIB 0x00c98210
float __cdecl NiMax(float fA, float fB)
{
    return (fA > fB) ? fA : fB;
}

struct __declspec(align(16)) FUN_00c987e0_Pose {
    hkVector4 translation;
    hkQuaternion rotation;
    hkVector4 scale;
    void SetFromInput_Thunk(int a1);
};
struct FUN_00c98780_Obj {
    void hkDebugDisplay_displayLineModelSpace(FUN_00c987e0_Pose* pose, int a2,int a3,int a4,int a5,int a6);
};
struct FUN_00c987e0_Cls {
    void UpdateFields_00c987e0(int a1,int a2,int a3,int a4,int a5,int a6);
};
// Builds a pose via FUN_00ce52e0(a1) and passes its address with a2 through a6 to FUN_00c98780 on this.
// @fnv 0x00c987e0
// src: GUESS 0x00c987e0 (confidence: low)
void FUN_00c987e0_Cls::UpdateFields_00c987e0(int a1,int a2,int a3,int a4,int a5,int a6)
{
    struct __declspec(align(16)) { LocalM128 x, y, z; } poseStorage;
    FUN_00c987e0_Pose& pose = *(FUN_00c987e0_Pose*)&poseStorage;
    pose.SetFromInput_Thunk(a1);
    reinterpret_cast<FUN_00c98780_Obj*>(this)->hkDebugDisplay_displayLineModelSpace(&pose,a2,a3,a4,a5,a6);
}

struct __declspec(align(16)) EC98BE0Vector {
    float x;
    float y;
    float z;
    float w;
    void __thiscall FUN_00c7f7a0(int a, int b);
};
struct EC98BE0Owner {
    void __thiscall DrawAxisLines(EC98BE0Vector* position, float scalar, int a, int b, int c);
    void __thiscall DrawAxisLinesAtPosition(int x, int y, float scalar, int a, int b, int c);
};
// Constructs a position vector from x and y, then calls FUN_00c98b60 with that position, scalar, and the remaining arguments.
// @fnv 0x00c98be0
// src: GUESS 0x00c98be0 (confidence: medium)
void EC98BE0Owner::DrawAxisLinesAtPosition(int x, int y, float scalar, int a, int b, int c)
{
    EC98BE0Vector position;
    position.FUN_00c7f7a0(x, y);
    DrawAxisLines(&position, scalar, a, b, c);
}

struct __declspec(align(16)) FUN_00c7f640_Class {
    void setTransformedPos_00c7f640(const void* m, const void* p);
};

struct FUN_00c98c30_Class {
    void DrawAxisLines(const void* p, float c, int d, int e, int f);
    void ProcessState_00c98c30(const void* a, const void* b, float c, int d, int e, int f);
};

// Builds a temporary via FUN_00c7f640(a, b), then calls FUN_00c98b60 with its address and c, d, e, f.
// @fnv 0x00c98c30
// src: GUESS 0x00c98c30 (confidence: low)
void FUN_00c98c30_Class::ProcessState_00c98c30(const void* a, const void* b, float c, int d, int e, int f)
{
    FUN_00c7f640_Class v;
    v.setTransformedPos_00c7f640(a, b);
    DrawAxisLines(&v, c, d, e, f);
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);


class hkListenerListC995 {
public:
    int unk00;
    int unk04;
    hkArray<void*> m_kListeners;
    void* m_pWorldLock;

    void RemoveListener(void* listener);
};

// Removes the given listener from m_kListeners under m_pWorldLock.
// @fnv 0x00c99590
void hkListenerListC995::RemoveListener(void* listener)
{
    EnterCriticalSection(m_pWorldLock);
    int i = m_kListeners.indexOf(listener);
    if (i >= 0) {
        m_kListeners.removeAt(i);
    }
    LeaveCriticalSection(m_pWorldLock);
}

namespace fnv_00c99ce0 {
extern void (__stdcall* DAT_00fdf100)(int* pLock);




void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);


class hkOwnerXc99ce0 {
public:
    int unk00[2];
    hkArray<void*> m_kNode;
    int* m_lock;

    void Add(void* item);
};

// @fnv 0x00c99ce0
void hkOwnerXc99ce0::Add(void* item)
{
    DAT_00fdf05c(m_lock);
    m_kNode.pushBack(item);
    DAT_00fdf100(m_lock);
}
}  // namespace fnv_00c99ce0

class Ce52e0Helper
{
public:
    void SetFromInput(int*, int);
    void SetFromInput_Thunk(int a);
};

// @fnv 0x00ce52e0
// src: GUESS 0x00ce52e0 (confidence: medium)
void Ce52e0Helper::SetFromInput_Thunk(int a)
{
    SetFromInput(&a, a);
}

class hkpWorldD0AD;

class hkMemberD0AD {
public:
    void ClearValue_Thunk_00d9e280(hkpWorldD0AD* pkWorld);
};

class hkListenerAD0AD {
public:
    virtual void onA();
};

class hkListenerBD0AD {
public:
    virtual void onB();
};



class hkSharedD0AD : public hkReferencedObject, public hkListenerAD0AD, public hkListenerBD0AD {
public:
    int m_useCount;
    hkMemberD0AD m_kMemberDescriptor;
};

class hkpWorldD0AD {
public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC;
    hkSharedD0AD* m_pSharedObject;

    void hkpWorld_removeConstraintListener(hkListenerAD0AD* pkListener);
    void hkpWorld_removeWorldDeletionListener(hkListenerBD0AD* pkListener);
};

// Decrements the shared object's m_useCount and at zero calls FUN_00d9e280 on its member, FUN_00c91750 and FUN_00c91a70 on the world, then FUN_00c905b0.
// @fnv 0x00d0adf0
void __cdecl ReleaseSharedObject(hkpWorldD0AD* pkWorld)
{
    hkSharedD0AD* pkShared = pkWorld->m_pSharedObject;
    if (--pkShared->m_useCount == 0) {
        pkShared->m_kMemberDescriptor.ClearValue_Thunk_00d9e280(pkWorld);
        pkWorld->hkpWorld_removeConstraintListener(pkShared);
        pkWorld->hkpWorld_removeWorldDeletionListener(pkShared);
        pkShared->removeReference();
    }
}

class FlagState {
public:
    unsigned int unk00, unk04;
    unsigned char unk08, state;
    unsigned short first, second;
    void SetFlagBits(unsigned int a, unsigned int b, int code);
};
// Sets the top two bits of first from a and of second from b, inverting a if (code & 3) < (state & 3) and b if code < state.
// @fnv 0x00c90ed0
void FlagState::SetFlagBits(unsigned int a, unsigned int b, int code) {
    int previous = state;
    unsigned int x = ((unsigned int)(code & 3) < (unsigned int)(previous & 3) ? ~a : a);
    unsigned int y = b;
    x <<= 14;
    if (code < previous) y = ~y;
    first = (unsigned short)((first & 0x3fff) | x);
    second = (unsigned short)((second & 0x3fff) | (y << 14));
}

struct OverlapResult {
    char value;
    OverlapResult() {}
};
struct OverlapPhantom;
struct OverlapCollidable {
    int unk00, unk04, unk08, unk0c;
    signed char ownerOffset;
    char unk11, unk12, unk13;
    int unk14;
    char type;
    OverlapPhantom* owner() {
        return reinterpret_cast<OverlapPhantom*>(reinterpret_cast<char*>(this) + ownerOffset);
    }
};
// Retained: the shared phantom lacks these typed virtual overlap methods.
struct OverlapPhantom {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void add(OverlapCollidable*);
    virtual OverlapResult overlaps(OverlapCollidable*);
    virtual void remove(OverlapCollidable*);
    int unk04, unk08, unk0c;
    OverlapCollidable collidable;
};
struct OverlapFilter {
    virtual void v00();
    virtual OverlapResult enabled(OverlapCollidable*, OverlapCollidable*);
};
struct OverlapContext {
    int unk00, unk04;
    OverlapFilter filter;
};
// Adds or removes other from phantom and, when other is type 2, mirrors the change on other's owner based on the filter result.
// @fnv 0x00c90f40
static __declspec(noinline) void SyncOverlap(OverlapPhantom* phantom, OverlapCollidable* other, OverlapContext* context)
{
    OverlapResult old = phantom->overlaps(other);
    if (context->filter.enabled(&phantom->collidable, other).value) {
        if (!old.value)
            phantom->add(other);
        if (other->type == 2) {
            OverlapResult otherOld = other->owner()->overlaps(&phantom->collidable);
            if (!otherOld.value)
                other->owner()->add(&phantom->collidable);
        }
    } else {
        if (old.value)
            phantom->remove(other);
        if (other->type == 2) {
            OverlapResult otherOld = other->owner()->overlaps(&phantom->collidable);
            if (otherOld.value)
                other->owner()->remove(&phantom->collidable);
        }
    }
}
OverlapPhantom* volatile overlapPhantom;
OverlapCollidable* volatile overlapOther;
OverlapContext* volatile overlapContext;
void invokeOverlap() {
    SyncOverlap(overlapPhantom, overlapOther, overlapContext);
}

// @fnv 0x00c910b0
// src: COMMUNITY 0x00c910b0
void nullsub_6()
{
}

// @fnv 0x00c911b0
// src: XBOX_PDB 0x00c911b0
void __cdecl hkpWorld_unlockReadOnly(void)
{
}

namespace c912 { inline hkMemoryRouter* router() { return (hkMemoryRouter*)hkMemoryRouter_getInstance(); } }
extern int DAT_010c6420;
extern int DAT_010c6378;

struct CFB240ContactMgrFactory {
    virtual ~CFB240ContactMgrFactory();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* operator new(unsigned int n) {
        CFB240ContactMgrFactory* b = static_cast<CFB240ContactMgrFactory*>(((hkMemoryAllocator*)c912::router()->m_heap)->blockAlloc(n));
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    void operator delete(void*) {}
    void removeReference() throw();
    CFB240ContactMgrFactory() throw() { m_sReferenceCount = 1; }
};
struct FUN_00cfd450 : CFB240ContactMgrFactory {
    int unk08;
    FUN_00cfd450(void*) throw();
};
struct FUN_00cfca20 : CFB240ContactMgrFactory {
    int unk08;
    FUN_00cfca20(void*) throw();
};
struct OtherC912 {
    void* vtable; short unknown; short refs; int kind;
    OtherC912() throw() { refs = 1; kind = 3; vtable = &DAT_010c6378; }
};
struct FactoryThreeC912 : CFB240ContactMgrFactory {
    OtherC912 other;
    virtual ~FactoryThreeC912();
    FactoryThreeC912() throw()
    {
    }
};
struct CFB240Dispatcher {
    void SetContactMgrFactory(CFB240ContactMgrFactory*, int);
};

// Creates two factories from world and a third, registers them with the dispatcher at slots 1, 2 and 3, then releases the local references.
// @fnv 0x00c912e0
static void RegisterContactMgrFactories(CFB240Dispatcher* dispatcher, void* world)
{
    FUN_00cfd450* first = new FUN_00cfd450(world);
    FUN_00cfca20* second = new FUN_00cfca20(world);
    FactoryThreeC912* third = new FactoryThreeC912;
    dispatcher->SetContactMgrFactory(first, 1);
    dispatcher->SetContactMgrFactory(second, 2);
    dispatcher->SetContactMgrFactory(third, 3);
    ((FUN_00d1df70*)first)->removeReference();
    ((FUN_00d1df70*)second)->removeReference();
    ((FUN_00d1df70*)third)->removeReference();
}

void c912e0_caller(CFB240Dispatcher* d, void* w)
{
    RegisterContactMgrFactories(d, w);
}

struct Shape64 {};
struct Container64 {
    void __thiscall AddShape(Shape64* shape);
};
struct Shape64List {
    Shape64** data;
    int count;
};
struct Element64 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44;
    Shape64List shapes;
};
struct Context64 {
    int unk00; int unk04; int unk08; int unk0C; int unk10;
    int unk14; int unk18; int unk1C; int unk20; int unk24;
    Element64** elements;
    int elementCount;
};
// Adds every shape of every element in context to container, then stores whether elementCount is greater than zero in result.
// @fnv 0x00c92760
unsigned char* __cdecl CollectShapes(unsigned char* pbHasElements, Context64* context, Container64* volatile container)
{
    Element64** element = context->elements;
    if (element != context->elements + context->elementCount)
    {
        do
        {
            Shape64List* shapes = &(*element)->shapes;
            int index = 0;
            if (shapes->count > 0)
            {
                do
                {
                    container->AddShape(shapes->data[index]);
                    ++index;
                } while (index < shapes->count);
            }
            ++element;
        } while (element != context->elements + context->elementCount);
    }
    *pbHasElements = context->elementCount > 0;
    return pbHasElements;
}

struct BorderSet {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    hkpPhantom* p18;
    hkpPhantom* p1c;
    hkpPhantom* p20;
    hkpPhantom* p24;
    hkpPhantom* p28;
    hkpPhantom* p2c;
};
struct PhantomWorld : hkpWorld {
    BorderSet* GetValue();
};
struct PhantomSink {
    void hkpPhysicsSystem_addPhantom(hkpPhantom* p);
};
// Iterates the world's phantoms and sends each to out->FUN_00d064f0, skipping the six border phantoms when a BorderSet is present.
// @fnv 0x00c92950
// src: HAVOK_LIB 0x00c92950
static __declspec(noinline) void enumerateAllPhantomsInWorld(PhantomWorld* world, PhantomSink* apSink)
{
    BorderSet* border = world->GetValue();
    if (border) {
        for (int i = 0; i < world->m_kPhantoms.m_iElementCount; ++i) {
            hkpPhantom* p = world->m_kPhantoms.m_data[i];
            if (p != border->p18 && p != border->p1c &&
                p != border->p20 && p != border->p24 &&
                p != border->p28 && p != border->p2c)
                apSink->hkpPhysicsSystem_addPhantom(p);
        }
    } else {
        for (int i = 0; i < world->m_kPhantoms.m_iElementCount; ++i)
            apSink->hkpPhysicsSystem_addPhantom(world->m_kPhantoms.m_data[i]);
    }
}
PhantomWorld* volatile g_world;
PhantomSink* volatile g_out;
void invokePhantomCopy() { enumerateAllPhantomsInWorld(g_world, g_out); }


struct MonitorRecord {
    const char* name;
    unsigned int time;
    unsigned int unused;
};
__forceinline void timer(const char* name, const char* first = 0) {
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* current = stream->m_end.m_storage;
    if (current < stream->m_capacityMinus16.m_storage) {
        volatile MonitorRecord* record = (volatile MonitorRecord*)current;
        record->name = name;
        if (first) *(const char* volatile*)(current + sizeof(MonitorRecord)) = first;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        record->time = stamp;
        stream->m_end.m_storage = current + (first ? 16 : 12);
    }
}
struct CollisionObject;
struct BroadphaseHandle {
    unsigned int id;
    unsigned char type;
    signed char ownerOffset;
    signed char quality;
    unsigned char flags;
};
struct CollisionObject {
    unsigned int shape;
    unsigned int shapeKey;
    unsigned int motion;
    unsigned int parent;
    signed char ownerOffset;
    unsigned char forceCollideOntoPpu;
    unsigned short shapeSize;
    BroadphaseHandle handle;
    unsigned int boundingVolume;
    void UpdateCollisionIndices();
    hkArray<struct CollisionAgentEntry>* hkpLinkedCollidable_getCollisionEntriesDeterministicUnchecked_00d081e0();
};
struct EntityState {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned char tail;
    unsigned char flags;
};


struct FilterBool {
    char value;
    FilterBool() {}
    FilterBool(bool enabled) : value(enabled) {}
};
// Retained: this overlap helper needs the original typed virtual interface.
struct PhantomInterface {
    virtual void unused00(); virtual void unused04();
    virtual void unused08(); virtual void unused0c();
    virtual void unused10(); virtual void unused14();
    virtual void unused18();
    virtual void addOverlap(CollisionObject*);
    virtual FilterBool hasOverlap(CollisionObject*);
    virtual void removeOverlap(CollisionObject*);
    virtual void unused28(); virtual void unused2c();
    virtual void refresh();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CollisionObject collidable;
};
struct OverlapPair { BroadphaseHandle* first; BroadphaseHandle* second; OverlapPair() {} };
struct PairArray {
    OverlapPair* data;
    int size;
    int capacityAndFlags;
    OverlapPair storage[128];
    __forceinline void init() { data = storage; size = 0; capacityAndFlags = 0x80000080; }
};
struct Broadphase {
    virtual void unused00(); virtual void unused04();
    virtual void unused08(); virtual void unused0c();
    virtual void unused10(); virtual void unused14();
    virtual void unused18(); virtual void unused1c();
    virtual void unused20(); virtual void unused24();
    virtual void unused28(); virtual void unused2c();
    virtual void unused30(); virtual void unused34();
    virtual void unused38(); virtual void unused3c();
    virtual void unused40(); virtual void unused44();
    virtual void query(BroadphaseHandle*, PairArray*);
};
struct CollisionFilterInterface {
    virtual void unused00();
    virtual FilterBool enabled(CollisionObject*, CollisionObject*);
};
struct CollisionFilter {
    unsigned int unk00;
    unsigned int unk04;
    CollisionFilterInterface filter;
};
struct CollisionDispatcher {
    unsigned int unk0000;     unsigned int unk0004;     unsigned int unk0008;     unsigned int unk000C;
    unsigned int unk0010;     unsigned int unk0014;     unsigned int unk0018;     unsigned int unk001C;
    unsigned int unk0020;     unsigned int unk0024;     unsigned int unk0028;     unsigned int unk002C;
    unsigned int unk0030;     unsigned int unk0034;     unsigned int unk0038;     unsigned int unk003C;
    unsigned int unk0040;     unsigned int unk0044;     unsigned int unk0048;     unsigned int unk004C;
    unsigned int unk0050;     unsigned int unk0054;     unsigned int unk0058;     unsigned int unk005C;
    unsigned int unk0060;     unsigned int unk0064;     unsigned int unk0068;     unsigned int unk006C;
    unsigned int unk0070;     unsigned int unk0074;     unsigned int unk0078;     unsigned int unk007C;
    unsigned int unk0080;     unsigned int unk0084;     unsigned int unk0088;     unsigned int unk008C;
    unsigned int unk0090;     unsigned int unk0094;     unsigned int unk0098;     unsigned int unk009C;
    unsigned int unk00A0;     unsigned int unk00A4;     unsigned int unk00A8;     unsigned int unk00AC;
    unsigned int unk00B0;     unsigned int unk00B4;     unsigned int unk00B8;     unsigned int unk00BC;
    unsigned int unk00C0;     unsigned int unk00C4;     unsigned int unk00C8;     unsigned int unk00CC;
    unsigned int unk00D0;     unsigned int unk00D4;     unsigned int unk00D8;     unsigned int unk00DC;
    unsigned int unk00E0;     unsigned int unk00E4;     unsigned int unk00E8;     unsigned int unk00EC;
    unsigned int unk00F0;     unsigned int unk00F4;     unsigned int unk00F8;     unsigned int unk00FC;
    unsigned int unk0100;     unsigned int unk0104;     unsigned int unk0108;     unsigned int unk010C;
    unsigned int unk0110;     unsigned int unk0114;     unsigned int unk0118;     unsigned int unk011C;
    unsigned int unk0120;     unsigned int unk0124;     unsigned int unk0128;     unsigned int unk012C;
    unsigned int unk0130;     unsigned int unk0134;     unsigned int unk0138;     unsigned int unk013C;
    unsigned int unk0140;     unsigned int unk0144;     unsigned int unk0148;     unsigned int unk014C;
    unsigned int unk0150;     unsigned int unk0154;     unsigned int unk0158;     unsigned int unk015C;
    unsigned int unk0160;     unsigned int unk0164;     unsigned int unk0168;     unsigned int unk016C;
    unsigned int unk0170;     unsigned int unk0174;     unsigned int unk0178;     unsigned int unk017C;
    unsigned int unk0180;     unsigned int unk0184;     unsigned int unk0188;     unsigned int unk018C;
    unsigned int unk0190;     unsigned int unk0194;     unsigned int unk0198;     unsigned int unk019C;
    unsigned int unk01A0;     unsigned int unk01A4;     unsigned int unk01A8;     unsigned int unk01AC;
    unsigned int unk01B0;     unsigned int unk01B4;     unsigned int unk01B8;     unsigned int unk01BC;
    unsigned int unk01C0;     unsigned int unk01C4;     unsigned int unk01C8;     unsigned int unk01CC;
    unsigned int unk01D0;     unsigned int unk01D4;     unsigned int unk01D8;     unsigned int unk01DC;
    unsigned int unk01E0;     unsigned int unk01E4;     unsigned int unk01E8;     unsigned int unk01EC;
    unsigned int unk01F0;     unsigned int unk01F4;     unsigned int unk01F8;     unsigned int unk01FC;
    unsigned int unk0200;     unsigned int unk0204;     unsigned int unk0208;     unsigned int unk020C;
    unsigned int unk0210;     unsigned int unk0214;     unsigned int unk0218;     unsigned int unk021C;
    unsigned int unk0220;     unsigned int unk0224;     unsigned int unk0228;     unsigned int unk022C;
    unsigned int unk0230;     unsigned int unk0234;     unsigned int unk0238;     unsigned int unk023C;
    unsigned int unk0240;     unsigned int unk0244;     unsigned int unk0248;     unsigned int unk024C;
    unsigned int unk0250;     unsigned int unk0254;     unsigned int unk0258;     unsigned int unk025C;
    unsigned int unk0260;     unsigned int unk0264;     unsigned int unk0268;     unsigned int unk026C;
    unsigned int unk0270;     unsigned int unk0274;     unsigned int unk0278;     unsigned int unk027C;
    unsigned int unk0280;     unsigned int unk0284;     unsigned int unk0288;     unsigned int unk028C;
    unsigned int unk0290;     unsigned int unk0294;     unsigned int unk0298;     unsigned int unk029C;
    unsigned int unk02A0;     unsigned int unk02A4;     unsigned int unk02A8;     unsigned int unk02AC;
    unsigned int unk02B0;     unsigned int unk02B4;     unsigned int unk02B8;     unsigned int unk02BC;
    unsigned int unk02C0;     unsigned int unk02C4;     unsigned int unk02C8;     unsigned int unk02CC;
    unsigned int unk02D0;     unsigned int unk02D4;     unsigned int unk02D8;     unsigned int unk02DC;
    unsigned int unk02E0;     unsigned int unk02E4;     unsigned int unk02E8;     unsigned int unk02EC;
    unsigned int unk02F0;     unsigned int unk02F4;     unsigned int unk02F8;     unsigned int unk02FC;
    unsigned int unk0300;     unsigned int unk0304;     unsigned int unk0308;     unsigned int unk030C;
    unsigned int unk0310;     unsigned int unk0314;     unsigned int unk0318;     unsigned int unk031C;
    unsigned int unk0320;     unsigned int unk0324;     unsigned int unk0328;     unsigned int unk032C;
    unsigned int unk0330;     unsigned int unk0334;     unsigned int unk0338;     unsigned int unk033C;
    unsigned int unk0340;     unsigned int unk0344;     unsigned int unk0348;     unsigned int unk034C;
    unsigned int unk0350;     unsigned int unk0354;     unsigned int unk0358;     unsigned int unk035C;
    unsigned int unk0360;     unsigned int unk0364;     unsigned int unk0368;     unsigned int unk036C;
    unsigned int unk0370;     unsigned int unk0374;     unsigned int unk0378;     unsigned int unk037C;
    unsigned int unk0380;     unsigned int unk0384;     unsigned int unk0388;     unsigned int unk038C;
    unsigned int unk0390;     unsigned int unk0394;     unsigned int unk0398;     unsigned int unk039C;
    unsigned int unk03A0;     unsigned int unk03A4;     unsigned int unk03A8;     unsigned int unk03AC;
    unsigned int unk03B0;     unsigned int unk03B4;     unsigned int unk03B8;     unsigned int unk03BC;
    unsigned int unk03C0;     unsigned int unk03C4;     unsigned int unk03C8;     unsigned int unk03CC;
    unsigned int unk03D0;     unsigned int unk03D4;     unsigned int unk03D8;     unsigned int unk03DC;
    unsigned int unk03E0;     unsigned int unk03E4;     unsigned int unk03E8;     unsigned int unk03EC;
    unsigned int unk03F0;     unsigned int unk03F4;     unsigned int unk03F8;     unsigned int unk03FC;
    unsigned int unk0400;     unsigned int unk0404;     unsigned int unk0408;     unsigned int unk040C;
    unsigned int unk0410;     unsigned int unk0414;     unsigned int unk0418;     unsigned int unk041C;
    unsigned int unk0420;     unsigned int unk0424;     unsigned int unk0428;     unsigned int unk042C;
    unsigned int unk0430;     unsigned int unk0434;     unsigned int unk0438;     unsigned int unk043C;
    unsigned int unk0440;     unsigned int unk0444;     unsigned int unk0448;     unsigned int unk044C;
    unsigned int unk0450;     unsigned int unk0454;     unsigned int unk0458;     unsigned int unk045C;
    unsigned int unk0460;     unsigned int unk0464;     unsigned int unk0468;     unsigned int unk046C;
    unsigned int unk0470;     unsigned int unk0474;     unsigned int unk0478;     unsigned int unk047C;
    unsigned int unk0480;     unsigned int unk0484;     unsigned int unk0488;     unsigned int unk048C;
    unsigned int unk0490;     unsigned int unk0494;     unsigned int unk0498;     unsigned int unk049C;
    unsigned int unk04A0;     unsigned int unk04A4;     unsigned int unk04A8;     unsigned int unk04AC;
    unsigned int unk04B0;     unsigned int unk04B4;     unsigned int unk04B8;     unsigned int unk04BC;
    unsigned int unk04C0;     unsigned int unk04C4;     unsigned int unk04C8;     unsigned int unk04CC;
    unsigned int unk04D0;     unsigned int unk04D4;     unsigned int unk04D8;     unsigned int unk04DC;
    unsigned int unk04E0;     unsigned int unk04E4;     unsigned int unk04E8;     unsigned int unk04EC;
    unsigned int unk04F0;     unsigned int unk04F4;     unsigned int unk04F8;     unsigned int unk04FC;
    unsigned int unk0500;     unsigned int unk0504;     unsigned int unk0508;     unsigned int unk050C;
    unsigned int unk0510;     unsigned int unk0514;     unsigned int unk0518;     unsigned int unk051C;
    unsigned int unk0520;     unsigned int unk0524;     unsigned int unk0528;     unsigned int unk052C;
    unsigned int unk0530;     unsigned int unk0534;     unsigned int unk0538;     unsigned int unk053C;
    unsigned int unk0540;     unsigned int unk0544;     unsigned int unk0548;     unsigned int unk054C;
    unsigned int unk0550;     unsigned int unk0554;     unsigned int unk0558;     unsigned int unk055C;
    unsigned int unk0560;     unsigned int unk0564;     unsigned int unk0568;     unsigned int unk056C;
    unsigned int unk0570;     unsigned int unk0574;     unsigned int unk0578;     unsigned int unk057C;
    unsigned int unk0580;     unsigned int unk0584;     unsigned int unk0588;     unsigned int unk058C;
    unsigned int unk0590;     unsigned int unk0594;     unsigned int unk0598;     unsigned int unk059C;
    unsigned int unk05A0;     unsigned int unk05A4;     unsigned int unk05A8;     unsigned int unk05AC;
    unsigned int unk05B0;     unsigned int unk05B4;     unsigned int unk05B8;     unsigned int unk05BC;
    unsigned int unk05C0;     unsigned int unk05C4;     unsigned int unk05C8;     unsigned int unk05CC;
    unsigned int unk05D0;     unsigned int unk05D4;     unsigned int unk05D8;     unsigned int unk05DC;
    unsigned int unk05E0;     unsigned int unk05E4;     unsigned int unk05E8;     unsigned int unk05EC;
    unsigned int unk05F0;     unsigned int unk05F4;     unsigned int unk05F8;     unsigned int unk05FC;
    unsigned int unk0600;     unsigned int unk0604;     unsigned int unk0608;     unsigned int unk060C;
    unsigned int unk0610;     unsigned int unk0614;     unsigned int unk0618;     unsigned int unk061C;
    unsigned int unk0620;     unsigned int unk0624;     unsigned int unk0628;     unsigned int unk062C;
    unsigned int unk0630;     unsigned int unk0634;     unsigned int unk0638;     unsigned int unk063C;
    unsigned int unk0640;     unsigned int unk0644;     unsigned int unk0648;     unsigned int unk064C;
    unsigned int unk0650;     unsigned int unk0654;     unsigned int unk0658;     unsigned int unk065C;
    unsigned int unk0660;     unsigned int unk0664;     unsigned int unk0668;     unsigned int unk066C;
    unsigned int unk0670;     unsigned int unk0674;     unsigned int unk0678;     unsigned int unk067C;
    unsigned int unk0680;     unsigned int unk0684;     unsigned int unk0688;     unsigned int unk068C;
    unsigned int unk0690;     unsigned int unk0694;     unsigned int unk0698;     unsigned int unk069C;
    unsigned int unk06A0;     unsigned int unk06A4;     unsigned int unk06A8;     unsigned int unk06AC;
    unsigned int unk06B0;     unsigned int unk06B4;     unsigned int unk06B8;     unsigned int unk06BC;
    unsigned int unk06C0;     unsigned int unk06C4;     unsigned int unk06C8;     unsigned int unk06CC;
    unsigned int unk06D0;     unsigned int unk06D4;     unsigned int unk06D8;     unsigned int unk06DC;
    unsigned int unk06E0;     unsigned int unk06E4;     unsigned int unk06E8;     unsigned int unk06EC;
    unsigned int unk06F0;     unsigned int unk06F4;     unsigned int unk06F8;     unsigned int unk06FC;
    unsigned int unk0700;     unsigned int unk0704;     unsigned int unk0708;     unsigned int unk070C;
    unsigned int unk0710;     unsigned int unk0714;     unsigned int unk0718;     unsigned int unk071C;
    unsigned int unk0720;     unsigned int unk0724;     unsigned int unk0728;     unsigned int unk072C;
    unsigned int unk0730;     unsigned int unk0734;     unsigned int unk0738;     unsigned int unk073C;
    unsigned int unk0740;     unsigned int unk0744;     unsigned int unk0748;     unsigned int unk074C;
    unsigned int unk0750;     unsigned int unk0754;     unsigned int unk0758;     unsigned int unk075C;
    unsigned int unk0760;     unsigned int unk0764;     unsigned int unk0768;     unsigned int unk076C;
    unsigned int unk0770;     unsigned int unk0774;     unsigned int unk0778;     unsigned int unk077C;
    unsigned int unk0780;     unsigned int unk0784;     unsigned int unk0788;     unsigned int unk078C;
    unsigned int unk0790;     unsigned int unk0794;     unsigned int unk0798;     unsigned int unk079C;
    unsigned int unk07A0;     unsigned int unk07A4;     unsigned int unk07A8;     unsigned int unk07AC;
    unsigned int unk07B0;     unsigned int unk07B4;     unsigned int unk07B8;     unsigned int unk07BC;
    unsigned int unk07C0;     unsigned int unk07C4;     unsigned int unk07C8;     unsigned int unk07CC;
    unsigned int unk07D0;     unsigned int unk07D4;     unsigned int unk07D8;     unsigned int unk07DC;
    unsigned int unk07E0;     unsigned int unk07E4;     unsigned int unk07E8;     unsigned int unk07EC;
    unsigned int unk07F0;     unsigned int unk07F4;     unsigned int unk07F8;     unsigned int unk07FC;
    unsigned int unk0800;     unsigned int unk0804;     unsigned int unk0808;     unsigned int unk080C;
    unsigned int unk0810;     unsigned int unk0814;     unsigned int unk0818;     unsigned int unk081C;
    unsigned int unk0820;     unsigned int unk0824;     unsigned int unk0828;     unsigned int unk082C;
    unsigned int unk0830;     unsigned int unk0834;     unsigned int unk0838;     unsigned int unk083C;
    unsigned int unk0840;     unsigned int unk0844;     unsigned int unk0848;     unsigned int unk084C;
    unsigned int unk0850;     unsigned int unk0854;     unsigned int unk0858;     unsigned int unk085C;
    unsigned int unk0860;     unsigned int unk0864;     unsigned int unk0868;     unsigned int unk086C;
    unsigned int unk0870;     unsigned int unk0874;     unsigned int unk0878;     unsigned int unk087C;
    unsigned int unk0880;     unsigned int unk0884;     unsigned int unk0888;     unsigned int unk088C;
    unsigned int unk0890;     unsigned int unk0894;     unsigned int unk0898;     unsigned int unk089C;
    unsigned int unk08A0;     unsigned int unk08A4;     unsigned int unk08A8;     unsigned int unk08AC;
    unsigned int unk08B0;     unsigned int unk08B4;     unsigned int unk08B8;     unsigned int unk08BC;
    unsigned int unk08C0;     unsigned int unk08C4;     unsigned int unk08C8;     unsigned int unk08CC;
    unsigned int unk08D0;     unsigned int unk08D4;     unsigned int unk08D8;     unsigned int unk08DC;
    unsigned int unk08E0;     unsigned int unk08E4;     unsigned int unk08E8;     unsigned int unk08EC;
    unsigned int unk08F0;     unsigned int unk08F4;     unsigned int unk08F8;     unsigned int unk08FC;
    unsigned int unk0900;     unsigned int unk0904;     unsigned int unk0908;     unsigned int unk090C;
    unsigned int unk0910;     unsigned int unk0914;     unsigned int unk0918;     unsigned int unk091C;
    unsigned int unk0920;     unsigned int unk0924;     unsigned int unk0928;     unsigned int unk092C;
    unsigned int unk0930;     unsigned int unk0934;     unsigned int unk0938;     unsigned int unk093C;
    unsigned int unk0940;     unsigned int unk0944;     unsigned int unk0948;     unsigned int unk094C;
    unsigned int unk0950;     unsigned int unk0954;     unsigned int unk0958;     unsigned int unk095C;
    unsigned int unk0960;     unsigned int unk0964;     unsigned int unk0968;     unsigned int unk096C;
    unsigned int unk0970;     unsigned int unk0974;     unsigned int unk0978;     unsigned int unk097C;
    unsigned int unk0980;     unsigned int unk0984;     unsigned int unk0988;     unsigned int unk098C;
    unsigned int unk0990;     unsigned int unk0994;     unsigned int unk0998;     unsigned int unk099C;
    unsigned int unk09A0;     unsigned int unk09A4;     unsigned int unk09A8;     unsigned int unk09AC;
    unsigned int unk09B0;     unsigned int unk09B4;     unsigned int unk09B8;     unsigned int unk09BC;
    unsigned int unk09C0;     unsigned int unk09C4;     unsigned int unk09C8;     unsigned int unk09CC;
    unsigned int unk09D0;     unsigned int unk09D4;     unsigned int unk09D8;     unsigned int unk09DC;
    unsigned int unk09E0;     unsigned int unk09E4;     unsigned int unk09E8;     unsigned int unk09EC;
    unsigned int unk09F0;     unsigned int unk09F4;     unsigned int unk09F8;     unsigned int unk09FC;
    unsigned int unk0A00;     unsigned int unk0A04;     unsigned int unk0A08;     unsigned int unk0A0C;
    unsigned int unk0A10;     unsigned int unk0A14;     unsigned int unk0A18;     unsigned int unk0A1C;
    unsigned int unk0A20;     unsigned int unk0A24;     unsigned int unk0A28;     unsigned int unk0A2C;
    unsigned int unk0A30;     unsigned int unk0A34;     unsigned int unk0A38;     unsigned int unk0A3C;
    unsigned int unk0A40;     unsigned int unk0A44;     unsigned int unk0A48;     unsigned int unk0A4C;
    unsigned int unk0A50;     unsigned int unk0A54;     unsigned int unk0A58;     unsigned int unk0A5C;
    unsigned int unk0A60;     unsigned int unk0A64;     unsigned int unk0A68;     unsigned int unk0A6C;
    unsigned int unk0A70;     unsigned int unk0A74;     unsigned int unk0A78;     unsigned int unk0A7C;
    unsigned int unk0A80;     unsigned int unk0A84;     unsigned int unk0A88;     unsigned int unk0A8C;
    unsigned int unk0A90;     unsigned int unk0A94;     unsigned int unk0A98;     unsigned int unk0A9C;
    unsigned int unk0AA0;     unsigned int unk0AA4;     unsigned int unk0AA8;     unsigned int unk0AAC;
    unsigned int unk0AB0;     unsigned int unk0AB4;     unsigned int unk0AB8;     unsigned int unk0ABC;
    unsigned int unk0AC0;     unsigned int unk0AC4;     unsigned int unk0AC8;     unsigned int unk0ACC;
    unsigned int unk0AD0;     unsigned int unk0AD4;     unsigned int unk0AD8;     unsigned int unk0ADC;
    unsigned int unk0AE0;     unsigned int unk0AE4;     unsigned int unk0AE8;     unsigned int unk0AEC;
    unsigned int unk0AF0;     unsigned int unk0AF4;     unsigned int unk0AF8;     unsigned int unk0AFC;
    unsigned int unk0B00;     unsigned int unk0B04;     unsigned int unk0B08;     unsigned int unk0B0C;
    unsigned int unk0B10;     unsigned int unk0B14;     unsigned int unk0B18;     unsigned int unk0B1C;
    unsigned int unk0B20;     unsigned int unk0B24;     unsigned int unk0B28;     unsigned int unk0B2C;
    unsigned int unk0B30;     unsigned int unk0B34;     unsigned int unk0B38;     unsigned int unk0B3C;
    unsigned int unk0B40;     unsigned int unk0B44;     unsigned int unk0B48;     unsigned int unk0B4C;
    unsigned int unk0B50;     unsigned int unk0B54;     unsigned int unk0B58;     unsigned int unk0B5C;
    unsigned int unk0B60;     unsigned int unk0B64;     unsigned int unk0B68;     unsigned int unk0B6C;
    unsigned int unk0B70;     unsigned int unk0B74;     unsigned int unk0B78;     unsigned int unk0B7C;
    unsigned int unk0B80;     unsigned int unk0B84;     unsigned int unk0B88;     unsigned int unk0B8C;
    unsigned int unk0B90;     unsigned int unk0B94;     unsigned int unk0B98;     unsigned int unk0B9C;
    unsigned int unk0BA0;     unsigned int unk0BA4;     unsigned int unk0BA8;     unsigned int unk0BAC;
    unsigned int unk0BB0;     unsigned int unk0BB4;     unsigned int unk0BB8;     unsigned int unk0BBC;
    unsigned int unk0BC0;     unsigned int unk0BC4;     unsigned int unk0BC8;     unsigned int unk0BCC;
    unsigned int unk0BD0;     unsigned int unk0BD4;     unsigned int unk0BD8;     unsigned int unk0BDC;
    unsigned int unk0BE0;     unsigned int unk0BE4;     unsigned int unk0BE8;     unsigned int unk0BEC;
    unsigned int unk0BF0;     unsigned int unk0BF4;     unsigned int unk0BF8;     unsigned int unk0BFC;
    unsigned int unk0C00;     unsigned int unk0C04;     unsigned int unk0C08;     unsigned int unk0C0C;
    unsigned int unk0C10;     unsigned int unk0C14;     unsigned int unk0C18;     unsigned int unk0C1C;
    unsigned int unk0C20;     unsigned int unk0C24;     unsigned int unk0C28;     unsigned int unk0C2C;
    unsigned int unk0C30;     unsigned int unk0C34;     unsigned int unk0C38;     unsigned int unk0C3C;
    unsigned int unk0C40;     unsigned int unk0C44;     unsigned int unk0C48;     unsigned int unk0C4C;
    unsigned int unk0C50;     unsigned int unk0C54;     unsigned int unk0C58;     unsigned int unk0C5C;
    unsigned int unk0C60;     unsigned int unk0C64;     unsigned int unk0C68;     unsigned int unk0C6C;
    unsigned int unk0C70;     unsigned int unk0C74;     unsigned int unk0C78;     unsigned int unk0C7C;
    unsigned int unk0C80;     unsigned int unk0C84;     unsigned int unk0C88;     unsigned int unk0C8C;
    unsigned int unk0C90;     unsigned int unk0C94;     unsigned int unk0C98;     unsigned int unk0C9C;
    unsigned int unk0CA0;     unsigned int unk0CA4;     unsigned int unk0CA8;     unsigned int unk0CAC;
    unsigned int unk0CB0;     unsigned int unk0CB4;     unsigned int unk0CB8;     unsigned int unk0CBC;
    unsigned int unk0CC0;     unsigned int unk0CC4;     unsigned int unk0CC8;     unsigned int unk0CCC;
    unsigned int unk0CD0;     unsigned int unk0CD4;     unsigned int unk0CD8;     unsigned int unk0CDC;
    unsigned int unk0CE0;     unsigned int unk0CE4;     unsigned int unk0CE8;     unsigned int unk0CEC;
    unsigned int unk0CF0;     unsigned int unk0CF4;     unsigned int unk0CF8;     unsigned int unk0CFC;
    unsigned int unk0D00;     unsigned int unk0D04;     unsigned int unk0D08;     unsigned int unk0D0C;
    unsigned int unk0D10;     unsigned int unk0D14;     unsigned int unk0D18;     unsigned int unk0D1C;
    unsigned int unk0D20;     unsigned int unk0D24;     unsigned int unk0D28;     unsigned int unk0D2C;
    unsigned int unk0D30;     unsigned int unk0D34;     unsigned int unk0D38;     unsigned int unk0D3C;
    unsigned int unk0D40;     unsigned int unk0D44;     unsigned int unk0D48;     unsigned int unk0D4C;
    unsigned int unk0D50;     unsigned int unk0D54;     unsigned int unk0D58;     unsigned int unk0D5C;
    unsigned int unk0D60;     unsigned int unk0D64;     unsigned int unk0D68;     unsigned int unk0D6C;
    unsigned int unk0D70;     unsigned int unk0D74;     unsigned int unk0D78;     unsigned int unk0D7C;
    unsigned int unk0D80;     unsigned int unk0D84;     unsigned int unk0D88;     unsigned int unk0D8C;
    unsigned int unk0D90;     unsigned int unk0D94;     unsigned int unk0D98;     unsigned int unk0D9C;
    unsigned int unk0DA0;     unsigned int unk0DA4;     unsigned int unk0DA8;     unsigned int unk0DAC;
    unsigned int unk0DB0;     unsigned int unk0DB4;     unsigned int unk0DB8;     unsigned int unk0DBC;
    unsigned int unk0DC0;     unsigned int unk0DC4;     unsigned int unk0DC8;     unsigned int unk0DCC;
    unsigned int unk0DD0;     unsigned int unk0DD4;     unsigned int unk0DD8;     unsigned int unk0DDC;
    unsigned int unk0DE0;     unsigned int unk0DE4;     unsigned int unk0DE8;     unsigned int unk0DEC;
    unsigned int unk0DF0;     unsigned int unk0DF4;     unsigned int unk0DF8;     unsigned int unk0DFC;
    unsigned int unk0E00;     unsigned int unk0E04;     unsigned int unk0E08;     unsigned int unk0E0C;
    unsigned int unk0E10;     unsigned int unk0E14;     unsigned int unk0E18;     unsigned int unk0E1C;
    unsigned int unk0E20;     unsigned int unk0E24;     unsigned int unk0E28;     unsigned int unk0E2C;
    unsigned int unk0E30;     unsigned int unk0E34;     unsigned int unk0E38;     unsigned int unk0E3C;
    unsigned int unk0E40;     unsigned int unk0E44;     unsigned int unk0E48;     unsigned int unk0E4C;
    unsigned int unk0E50;     unsigned int unk0E54;     unsigned int unk0E58;     unsigned int unk0E5C;
    unsigned int unk0E60;     unsigned int unk0E64;     unsigned int unk0E68;     unsigned int unk0E6C;
    unsigned int unk0E70;     unsigned int unk0E74;     unsigned int unk0E78;     unsigned int unk0E7C;
    unsigned int unk0E80;     unsigned int unk0E84;     unsigned int unk0E88;     unsigned int unk0E8C;
    unsigned int unk0E90;     unsigned int unk0E94;     unsigned int unk0E98;     unsigned int unk0E9C;
    unsigned int unk0EA0;     unsigned int unk0EA4;     unsigned int unk0EA8;     unsigned int unk0EAC;
    unsigned int unk0EB0;     unsigned int unk0EB4;     unsigned int unk0EB8;     unsigned int unk0EBC;
    unsigned int unk0EC0;     unsigned int unk0EC4;     unsigned int unk0EC8;     unsigned int unk0ECC;
    unsigned int unk0ED0;     unsigned int unk0ED4;     unsigned int unk0ED8;     unsigned int unk0EDC;
    unsigned int unk0EE0;     unsigned int unk0EE4;     unsigned int unk0EE8;     unsigned int unk0EEC;
    unsigned int unk0EF0;     unsigned int unk0EF4;     unsigned int unk0EF8;     unsigned int unk0EFC;
    unsigned int unk0F00;     unsigned int unk0F04;     unsigned int unk0F08;     unsigned int unk0F0C;
    unsigned int unk0F10;     unsigned int unk0F14;     unsigned int unk0F18;     unsigned int unk0F1C;
    unsigned int unk0F20;     unsigned int unk0F24;     unsigned int unk0F28;     unsigned int unk0F2C;
    unsigned int unk0F30;     unsigned int unk0F34;     unsigned int unk0F38;     unsigned int unk0F3C;
    unsigned int unk0F40;     unsigned int unk0F44;     unsigned int unk0F48;     unsigned int unk0F4C;
    unsigned int unk0F50;     unsigned int unk0F54;     unsigned int unk0F58;     unsigned int unk0F5C;
    unsigned int unk0F60;     unsigned int unk0F64;     unsigned int unk0F68;     unsigned int unk0F6C;
    unsigned int unk0F70;     unsigned int unk0F74;     unsigned int unk0F78;     unsigned int unk0F7C;
    unsigned int unk0F80;     unsigned int unk0F84;     unsigned int unk0F88;     unsigned int unk0F8C;
    unsigned int unk0F90;     unsigned int unk0F94;     unsigned int unk0F98;     unsigned int unk0F9C;
    unsigned int unk0FA0;     unsigned int unk0FA4;     unsigned int unk0FA8;     unsigned int unk0FAC;
    unsigned int unk0FB0;     unsigned int unk0FB4;     unsigned int unk0FB8;     unsigned int unk0FBC;
    unsigned int unk0FC0;     unsigned int unk0FC4;     unsigned int unk0FC8;     unsigned int unk0FCC;
    unsigned int unk0FD0;     unsigned int unk0FD4;     unsigned int unk0FD8;     unsigned int unk0FDC;
    unsigned int unk0FE0;     unsigned int unk0FE4;     unsigned int unk0FE8;     unsigned int unk0FEC;
    unsigned int unk0FF0;     unsigned int unk0FF4;     unsigned int unk0FF8;     unsigned int unk0FFC;
    unsigned int unk1000;     unsigned int unk1004;     unsigned int unk1008;     unsigned int unk100C;
    unsigned int unk1010;     unsigned int unk1014;     unsigned int unk1018;     unsigned int unk101C;
    unsigned int unk1020;     unsigned int unk1024;     unsigned int unk1028;     unsigned int unk102C;
    unsigned int unk1030;     unsigned int unk1034;     unsigned int unk1038;     unsigned int unk103C;
    unsigned int unk1040;     unsigned int unk1044;     unsigned int unk1048;     unsigned int unk104C;
    unsigned int unk1050;     unsigned int unk1054;     unsigned int unk1058;     unsigned int unk105C;
    unsigned int unk1060;     unsigned int unk1064;     unsigned int unk1068;     unsigned int unk106C;
    unsigned int unk1070;     unsigned int unk1074;     unsigned int unk1078;     unsigned int unk107C;
    unsigned int unk1080;     unsigned int unk1084;     unsigned int unk1088;     unsigned int unk108C;
    unsigned int unk1090;     unsigned int unk1094;     unsigned int unk1098;     unsigned int unk109C;
    unsigned int unk10A0;     unsigned int unk10A4;     unsigned int unk10A8;     unsigned int unk10AC;
    unsigned int unk10B0;     unsigned int unk10B4;     unsigned int unk10B8;     unsigned int unk10BC;
    unsigned int unk10C0;     unsigned int unk10C4;     unsigned int unk10C8;     unsigned int unk10CC;
    unsigned int unk10D0;     unsigned int unk10D4;     unsigned int unk10D8;     unsigned int unk10DC;
    unsigned int unk10E0;     unsigned int unk10E4;     unsigned int unk10E8;     unsigned int unk10EC;
    unsigned int unk10F0;     unsigned int unk10F4;     unsigned int unk10F8;     unsigned int unk10FC;
    unsigned int unk1100;     unsigned int unk1104;     unsigned int unk1108;     unsigned int unk110C;
    unsigned int unk1110;     unsigned int unk1114;     unsigned int unk1118;     unsigned int unk111C;
    unsigned int unk1120;     unsigned int unk1124;     unsigned int unk1128;     unsigned int unk112C;
    unsigned int unk1130;     unsigned int unk1134;     unsigned int unk1138;     unsigned int unk113C;
    unsigned int unk1140;     unsigned int unk1144;     unsigned int unk1148;     unsigned int unk114C;
    unsigned int unk1150;     unsigned int unk1154;     unsigned int unk1158;     unsigned int unk115C;
    unsigned int unk1160;     unsigned int unk1164;     unsigned int unk1168;     unsigned int unk116C;
    unsigned int unk1170;     unsigned int unk1174;     unsigned int unk1178;     unsigned int unk117C;
    unsigned int unk1180;     unsigned int unk1184;     unsigned int unk1188;     unsigned int unk118C;
    unsigned int unk1190;     unsigned int unk1194;     unsigned int unk1198;     unsigned int unk119C;
    unsigned int unk11A0;     unsigned int unk11A4;     unsigned int unk11A8;     unsigned int unk11AC;
    unsigned int unk11B0;     unsigned int unk11B4;     unsigned int unk11B8;     unsigned int unk11BC;
    unsigned int unk11C0;     unsigned int unk11C4;     unsigned int unk11C8;     unsigned int unk11CC;
    unsigned int unk11D0;     unsigned int unk11D4;     unsigned int unk11D8;     unsigned int unk11DC;
    unsigned int unk11E0;     unsigned int unk11E4;     unsigned int unk11E8;     unsigned int unk11EC;
    unsigned int unk11F0;     unsigned int unk11F4;     unsigned int unk11F8;     unsigned int unk11FC;
    unsigned int unk1200;     unsigned int unk1204;     unsigned int unk1208;     unsigned int unk120C;
    unsigned int unk1210;     unsigned int unk1214;     unsigned int unk1218;     unsigned int unk121C;
    unsigned int unk1220;     unsigned int unk1224;     unsigned int unk1228;     unsigned int unk122C;
    unsigned int unk1230;     unsigned int unk1234;     unsigned int unk1238;     unsigned int unk123C;
    unsigned int unk1240;     unsigned int unk1244;     unsigned int unk1248;     unsigned int unk124C;
    unsigned int unk1250;     unsigned int unk1254;     unsigned int unk1258;     unsigned int unk125C;
    unsigned int unk1260;     unsigned int unk1264;     unsigned int unk1268;     unsigned int unk126C;
    unsigned int unk1270;     unsigned int unk1274;     unsigned int unk1278;     unsigned int unk127C;
    unsigned int unk1280;     unsigned int unk1284;     unsigned int unk1288;     unsigned int unk128C;
    unsigned int unk1290;     unsigned int unk1294;     unsigned int unk1298;     unsigned int unk129C;
    unsigned int unk12A0;     unsigned int unk12A4;     unsigned int unk12A8;     unsigned int unk12AC;
    unsigned int unk12B0;     unsigned int unk12B4;     unsigned int unk12B8;     unsigned int unk12BC;
    unsigned int unk12C0;     unsigned int unk12C4;     unsigned int unk12C8;     unsigned int unk12CC;
    unsigned int unk12D0;     unsigned int unk12D4;     unsigned int unk12D8;     unsigned int unk12DC;
    unsigned int unk12E0;     unsigned int unk12E4;     unsigned int unk12E8;     unsigned int unk12EC;
    unsigned int unk12F0;     unsigned int unk12F4;     unsigned int unk12F8;     unsigned int unk12FC;
    unsigned int unk1300;     unsigned int unk1304;     unsigned int unk1308;     unsigned int unk130C;
    unsigned int unk1310;     unsigned int unk1314;     unsigned int unk1318;     unsigned int unk131C;
    unsigned int unk1320;     unsigned int unk1324;     unsigned int unk1328;     unsigned int unk132C;
    unsigned int unk1330;     unsigned int unk1334;     unsigned int unk1338;     unsigned int unk133C;
    unsigned int unk1340;     unsigned int unk1344;     unsigned int unk1348;     unsigned int unk134C;
    unsigned int unk1350;     unsigned int unk1354;     unsigned int unk1358;     unsigned int unk135C;
    unsigned int unk1360;     unsigned int unk1364;     unsigned int unk1368;     unsigned int unk136C;
    unsigned int unk1370;     unsigned int unk1374;     unsigned int unk1378;     unsigned int unk137C;
    unsigned int unk1380;     unsigned int unk1384;     unsigned int unk1388;     unsigned int unk138C;
    unsigned int unk1390;     unsigned int unk1394;     unsigned int unk1398;     unsigned int unk139C;
    unsigned int unk13A0;     unsigned int unk13A4;     unsigned int unk13A8;     unsigned int unk13AC;
    unsigned int unk13B0;     unsigned int unk13B4;     unsigned int unk13B8;     unsigned int unk13BC;
    unsigned int unk13C0;     unsigned int unk13C4;     unsigned int unk13C8;     unsigned int unk13CC;
    unsigned int unk13D0;     unsigned int unk13D4;     unsigned int unk13D8;     unsigned int unk13DC;
    unsigned int unk13E0;     unsigned int unk13E4;     unsigned int unk13E8;     unsigned int unk13EC;
    unsigned int unk13F0;     unsigned int unk13F4;     unsigned int unk13F8;     unsigned int unk13FC;
    unsigned int unk1400;     unsigned int unk1404;     unsigned int unk1408;     unsigned int unk140C;
    unsigned int unk1410;     unsigned int unk1414;     unsigned int unk1418;     unsigned int unk141C;
    unsigned int unk1420;     unsigned int unk1424;     unsigned int unk1428;     unsigned int unk142C;
    unsigned int unk1430;     unsigned int unk1434;     unsigned int unk1438;     unsigned int unk143C;
    unsigned int unk1440;     unsigned int unk1444;     unsigned int unk1448;     unsigned int unk144C;
    unsigned int unk1450;     unsigned int unk1454;     unsigned int unk1458;     unsigned int unk145C;
    unsigned int unk1460;     unsigned int unk1464;     unsigned int unk1468;     unsigned int unk146C;
    unsigned int unk1470;     unsigned int unk1474;     unsigned int unk1478;     unsigned int unk147C;
    unsigned int unk1480;     unsigned int unk1484;     unsigned int unk1488;     unsigned int unk148C;
    unsigned int unk1490;     unsigned int unk1494;     unsigned int unk1498;     unsigned int unk149C;
    unsigned int unk14A0;     unsigned int unk14A4;     unsigned int unk14A8;     unsigned int unk14AC;
    unsigned int unk14B0;     unsigned int unk14B4;     unsigned int unk14B8;     unsigned int unk14BC;
    unsigned int unk14C0;     unsigned int unk14C4;     unsigned int unk14C8;     unsigned int unk14CC;
    unsigned int unk14D0;     unsigned int unk14D4;     unsigned int unk14D8;     unsigned int unk14DC;
    unsigned int unk14E0;     unsigned int unk14E4;     unsigned int unk14E8;     unsigned int unk14EC;
    unsigned int unk14F0;     unsigned int unk14F4;     unsigned int unk14F8;     unsigned int unk14FC;
    unsigned int unk1500;     unsigned int unk1504;     unsigned int unk1508;     unsigned int unk150C;
    unsigned int unk1510;     unsigned int unk1514;     unsigned int unk1518;     unsigned int unk151C;
    unsigned int unk1520;     unsigned int unk1524;     unsigned int unk1528;     unsigned int unk152C;
    unsigned int unk1530;     unsigned int unk1534;     unsigned int unk1538;     unsigned int unk153C;
    unsigned int unk1540;     unsigned int unk1544;     unsigned int unk1548;     unsigned int unk154C;
    unsigned int unk1550;     unsigned int unk1554;     unsigned int unk1558;     unsigned int unk155C;
    unsigned int unk1560;     unsigned int unk1564;     unsigned int unk1568;     unsigned int unk156C;
    unsigned int unk1570;     unsigned int unk1574;     unsigned int unk1578;     unsigned int unk157C;
    unsigned int unk1580;     unsigned int unk1584;     unsigned int unk1588;     unsigned int unk158C;
    unsigned int unk1590;     unsigned int unk1594;     unsigned int unk1598;     unsigned int unk159C;
    unsigned int unk15A0;     unsigned int unk15A4;     unsigned int unk15A8;     unsigned int unk15AC;
    unsigned int unk15B0;     unsigned int unk15B4;     unsigned int unk15B8;     unsigned int unk15BC;
    unsigned int unk15C0;     unsigned int unk15C4;     unsigned int unk15C8;     unsigned int unk15CC;
    unsigned int unk15D0;     unsigned int unk15D4;     unsigned int unk15D8;     unsigned int unk15DC;
    unsigned int unk15E0;     unsigned int unk15E4;     unsigned int unk15E8;     unsigned int unk15EC;
    unsigned int unk15F0;     unsigned int unk15F4;     unsigned int unk15F8;     unsigned int unk15FC;
    unsigned int unk1600;     unsigned int unk1604;     unsigned int unk1608;     unsigned int unk160C;
    unsigned int unk1610;     unsigned int unk1614;     unsigned int unk1618;     unsigned int unk161C;
    unsigned int unk1620;     unsigned int unk1624;     unsigned int unk1628;     unsigned int unk162C;
    unsigned int unk1630;     unsigned int unk1634;     unsigned int unk1638;     unsigned int unk163C;
    unsigned int unk1640;     unsigned int unk1644;     unsigned int unk1648;     unsigned int unk164C;
    unsigned int unk1650;     unsigned int unk1654;     unsigned int unk1658;     unsigned int unk165C;
    unsigned int unk1660;     unsigned int unk1664;     unsigned int unk1668;     unsigned int unk166C;
    unsigned int unk1670;     unsigned int unk1674;     unsigned int unk1678;     unsigned int unk167C;
    unsigned int unk1680;     unsigned int unk1684;     unsigned int unk1688;     unsigned int unk168C;
    unsigned int unk1690;     unsigned int unk1694;     unsigned int unk1698;     unsigned int unk169C;
    unsigned int unk16A0;     unsigned int unk16A4;     unsigned int unk16A8;     unsigned int unk16AC;
    unsigned int unk16B0;     unsigned int unk16B4;     unsigned int unk16B8;     unsigned int unk16BC;
    unsigned int unk16C0;     unsigned int unk16C4;     unsigned int unk16C8;     unsigned int unk16CC;
    unsigned int unk16D0;     unsigned int unk16D4;     unsigned int unk16D8;     unsigned int unk16DC;
    unsigned int unk16E0;     unsigned int unk16E4;     unsigned int unk16E8;     unsigned int unk16EC;
    unsigned int unk16F0;     unsigned int unk16F4;     unsigned int unk16F8;     unsigned int unk16FC;
    unsigned int unk1700;     unsigned int unk1704;     unsigned int unk1708;     unsigned int unk170C;
    unsigned int unk1710;     unsigned int unk1714;     unsigned int unk1718;     unsigned int unk171C;
    unsigned int unk1720;     unsigned int unk1724;     unsigned int unk1728;     unsigned int unk172C;
    unsigned int unk1730;     unsigned int unk1734;     unsigned int unk1738;     unsigned int unk173C;
    unsigned int unk1740;     unsigned int unk1744;     unsigned int unk1748;     unsigned int unk174C;
    unsigned int unk1750;     unsigned int unk1754;     unsigned int unk1758;     unsigned int unk175C;
    unsigned int unk1760;     unsigned int unk1764;     unsigned int unk1768;     unsigned int unk176C;
    unsigned int unk1770;     unsigned int unk1774;     unsigned int unk1778;     unsigned int unk177C;
    unsigned int unk1780;     unsigned int unk1784;     unsigned int unk1788;     unsigned int unk178C;
    unsigned int unk1790;     unsigned int unk1794;     unsigned int unk1798;     unsigned int unk179C;
    unsigned int unk17A0;     unsigned int unk17A4;     unsigned int unk17A8;     unsigned int unk17AC;
    unsigned int unk17B0;     unsigned int unk17B4;     unsigned int unk17B8;     unsigned int unk17BC;
    unsigned int unk17C0;     unsigned int unk17C4;     unsigned int unk17C8;     unsigned int unk17CC;
    unsigned int unk17D0;     unsigned int unk17D4;     unsigned int unk17D8;     unsigned int unk17DC;
    unsigned int unk17E0;     unsigned int unk17E4;     unsigned int unk17E8;     unsigned int unk17EC;
    unsigned int unk17F0;     unsigned int unk17F4;     unsigned int unk17F8;     unsigned int unk17FC;
    unsigned int unk1800;     unsigned int unk1804;     unsigned int unk1808;     unsigned int unk180C;
    unsigned int unk1810;     unsigned int unk1814;     unsigned int unk1818;     unsigned int unk181C;
    unsigned int unk1820;     unsigned int unk1824;     unsigned int unk1828;     unsigned int unk182C;
    unsigned int unk1830;     unsigned int unk1834;     unsigned int unk1838;     unsigned int unk183C;
    unsigned int unk1840;     unsigned int unk1844;     unsigned int unk1848;     unsigned int unk184C;
    unsigned int unk1850;     unsigned int unk1854;     unsigned int unk1858;     unsigned int unk185C;
    unsigned int unk1860;     unsigned int unk1864;     unsigned int unk1868;     unsigned int unk186C;
    unsigned int unk1870;     unsigned int unk1874;     unsigned int unk1878;     unsigned int unk187C;
    unsigned int unk1880;     unsigned int unk1884;     unsigned int unk1888;     unsigned int unk188C;
    unsigned int unk1890;     unsigned int unk1894;     unsigned int unk1898;     unsigned int unk189C;
    unsigned int unk18A0;     unsigned int unk18A4;     unsigned int unk18A8;     unsigned int unk18AC;
    unsigned int unk18B0;     unsigned int unk18B4;     unsigned int unk18B8;     unsigned int unk18BC;
    unsigned int unk18C0;     unsigned int unk18C4;     unsigned int unk18C8;     unsigned int unk18CC;
    unsigned int unk18D0;     unsigned int unk18D4;     unsigned int unk18D8;     unsigned int unk18DC;
    unsigned int unk18E0;     unsigned int unk18E4;     unsigned int unk18E8;     unsigned int unk18EC;
    unsigned int unk18F0;     unsigned int unk18F4;     unsigned int unk18F8;     unsigned int unk18FC;
    unsigned int unk1900;     unsigned int unk1904;     unsigned int unk1908;     unsigned int unk190C;
    unsigned int unk1910;     unsigned int unk1914;     unsigned int unk1918;     unsigned int unk191C;
    unsigned int unk1920;     unsigned int unk1924;     unsigned int unk1928;     unsigned int unk192C;
    unsigned int unk1930;     unsigned int unk1934;     unsigned int unk1938;     unsigned int unk193C;
    unsigned int unk1940;     unsigned int unk1944;     unsigned int unk1948;     unsigned int unk194C;
    unsigned int unk1950;     unsigned int unk1954;     unsigned int unk1958;     unsigned int unk195C;
    unsigned int unk1960;     unsigned int unk1964;     unsigned int unk1968;     unsigned int unk196C;
    unsigned int unk1970;     unsigned int unk1974;     unsigned int unk1978;     unsigned int unk197C;
    unsigned int unk1980;     unsigned int unk1984;     unsigned int unk1988;     unsigned int unk198C;
    unsigned int unk1990;     unsigned int unk1994;     unsigned int unk1998;     unsigned int unk199C;
    unsigned int unk19A0;     unsigned int unk19A4;     unsigned int unk19A8;     unsigned int unk19AC;
    unsigned int unk19B0;     unsigned int unk19B4;     unsigned int unk19B8;     unsigned int unk19BC;
    unsigned int unk19C0;     unsigned int unk19C4;     unsigned int unk19C8;     unsigned int unk19CC;
    unsigned int unk19D0;     unsigned int unk19D4;     unsigned int unk19D8;     unsigned int unk19DC;
    unsigned int unk19E0;     unsigned int unk19E4;     unsigned int unk19E8;     unsigned int unk19EC;
    unsigned int unk19F0;     unsigned int unk19F4;     unsigned int unk19F8;     unsigned int unk19FC;
    unsigned int unk1A00;     unsigned int unk1A04;     unsigned int unk1A08;     unsigned int unk1A0C;
    unsigned int unk1A10;     unsigned int unk1A14;     unsigned int unk1A18;     unsigned int unk1A1C;
    unsigned int unk1A20;     unsigned int unk1A24;     unsigned int unk1A28;     unsigned int unk1A2C;
    unsigned int unk1A30;     unsigned int unk1A34;     unsigned int unk1A38;     unsigned int unk1A3C;
    unsigned int unk1A40;     unsigned int unk1A44;     unsigned int unk1A48;     unsigned int unk1A4C;
    unsigned int unk1A50;     unsigned int unk1A54;     unsigned int unk1A58;     unsigned int unk1A5C;
    unsigned int unk1A60;     unsigned int unk1A64;     unsigned int unk1A68;     unsigned int unk1A6C;
    unsigned int unk1A70;     unsigned int unk1A74;     unsigned int unk1A78;     unsigned int unk1A7C;
    unsigned int unk1A80;     unsigned int unk1A84;     unsigned int unk1A88;     unsigned int unk1A8C;
    unsigned int unk1A90;     unsigned int unk1A94;     unsigned int unk1A98;     unsigned int unk1A9C;
    unsigned int unk1AA0;     unsigned int unk1AA4;     unsigned int unk1AA8;     unsigned int unk1AAC;
    unsigned int unk1AB0;     unsigned int unk1AB4;     unsigned int unk1AB8;     unsigned int unk1ABC;
    unsigned int unk1AC0;     unsigned int unk1AC4;     unsigned int unk1AC8;     unsigned int unk1ACC;
    unsigned int unk1AD0;     unsigned int unk1AD4;     unsigned int unk1AD8;     unsigned int unk1ADC;
    unsigned int unk1AE0;     unsigned int unk1AE4;     unsigned int unk1AE8;     unsigned int unk1AEC;
    unsigned int unk1AF0;     unsigned int unk1AF4;     unsigned int unk1AF8;     unsigned int unk1AFC;
    unsigned int unk1B00;     unsigned int unk1B04;     unsigned int unk1B08;     unsigned int unk1B0C;
    unsigned int unk1B10;     unsigned int unk1B14;     unsigned int unk1B18;     unsigned int unk1B1C;
    unsigned int unk1B20;     unsigned int unk1B24;     unsigned int unk1B28;     unsigned int unk1B2C;
    unsigned int unk1B30;     unsigned int unk1B34;     unsigned int unk1B38;     unsigned int unk1B3C;
    unsigned int unk1B40;     unsigned int unk1B44;     unsigned int unk1B48;     unsigned int unk1B4C;
    unsigned int unk1B50;     unsigned int unk1B54;     unsigned int unk1B58;     unsigned int unk1B5C;
    unsigned int unk1B60;     unsigned int unk1B64;     unsigned int unk1B68;     unsigned int unk1B6C;
    unsigned int unk1B70;     unsigned int unk1B74;     unsigned int unk1B78;     unsigned int unk1B7C;
    unsigned int unk1B80;     unsigned int unk1B84;     unsigned int unk1B88;     unsigned int unk1B8C;
    unsigned int unk1B90;     unsigned int unk1B94;     unsigned int unk1B98;     unsigned int unk1B9C;
    unsigned int unk1BA0;     unsigned int unk1BA4;     unsigned int unk1BA8;     unsigned int unk1BAC;
    unsigned char qualityEnabled[10][10];
};
struct Agent {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CollisionObject* first;
    CollisionObject* second;
};
struct CollisionAgentEntry { Agent* agent; CollisionObject* other; };
struct OverlapAllocator {
    virtual void unused00(); virtual void unused04();
    virtual void unused08(); virtual void unused0c();
    virtual void freeBlock(void*, int);
};


void ResizeAudioStream(void*, void*, int);
static __declspec(noinline) void __cdecl SyncOverlap(PhantomInterface* phantom, CollisionObject* other, CollisionFilter* filter) {
    FilterBool overlapping = phantom->hasOverlap(other);
    CollisionObject* self = &phantom->collidable;
    if (filter->filter.enabled(self, other).value) {
        if (!overlapping.value) phantom->addOverlap(other);
        if (other->handle.type == 2) {
            FilterBool reverseOverlap = ((PhantomInterface*)((char*)other + other->ownerOffset))->hasOverlap(self);
            if (!reverseOverlap.value) ((PhantomInterface*)((char*)other + other->ownerOffset))->addOverlap(self);
        }
    } else {
        if (overlapping.value) phantom->removeOverlap(other);
        if (other->handle.type == 2) {
            FilterBool reverseOverlap = ((PhantomInterface*)((char*)other + other->ownerOffset))->hasOverlap(self);
            if (reverseOverlap.value) ((PhantomInterface*)((char*)other + other->ownerOffset))->removeOverlap(self);
        }
    }
}
void hkpWorldAgentUtil_removeAgentAndItsToiEvents(Agent*);
void _hkAgentNnMachine_UpdateShapeCollectionFilter(Agent*, void*, EntityState*);
void hkpTypedBroadPhaseDispatcher_removeDuplicates(PairArray*, PairArray*);
struct BroadphaseDispatcher {
    void hkpTypedBroadPhaseDispatcher_addPairs(OverlapPair*, int, CollisionFilterInterface*);
};
struct FilterCommand {
    unsigned char type;
    hkpEntity* entity;
    unsigned char updateCollection;
    unsigned char updateShape;
};
struct CallRet : hkpWorld {
    void hkpWorld_updateCollisionFilterOnEntity(hkpEntity*, int, int);
    void hkpWorld_queueOperation(FilterCommand*);
    void FUN_00c91120();
    void UpdateFields_00c91140();
};
__forceinline void releasePairs(PairArray& pairs) {
hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
OverlapAllocator* heap = (OverlapAllocator*)router->m_heap;
pairs.size=0;
if ((pairs.capacityAndFlags & 0x80000000)==0) heap->freeBlock(pairs.data,(pairs.capacityAndFlags & 0x3fffffff)*sizeof(OverlapPair));
}

__forceinline void constructPairs(OverlapPair* p,int n) { for(int j=0;j<n;++j) new(p+j) OverlapPair; }
__forceinline OverlapPair& expandOverlapPair(PairArray& pairs) {
hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
if (pairs.size == (pairs.capacityAndFlags & 0x3fffffff)) ResizeAudioStream(router->m_heap,&pairs,sizeof(OverlapPair));
constructPairs(pairs.data+pairs.size,1);
return pairs.data[pairs.size++];
}
// Updates collision filter state for entity, syncing phantom overlaps and agent pairs, then dispatches new collision pairs.
// @fnv 0x00c946e0
// src: HAVOK_LIB 0x00c946e0
void CallRet::hkpWorld_updateCollisionFilterOnEntity(hkpEntity* entity, int updateCollection, int updateShape) {
    if (m_iCriticalOperationsLockCount) {
        FilterCommand command;
        command.type = 0x12;
        command.entity = entity;
        command.updateCollection = (unsigned char)updateCollection;
        command.updateShape = (unsigned char)updateShape;
        hkpWorld_queueOperation(&command);
        return;
    }
    timer("LtUpdateFilterOnEntity", "Stinit");
    ++m_iCriticalOperationsLockCount;
    if ((*(unsigned char*)&entity->m_pMotionState.m_type) == 5) ((CollisionObject*)&entity->m_kCollidable)->UpdateCollisionIndices();
    PairArray pairs;
    pairs.init();
    if (updateCollection == 0) {
        timer("Stbroadphase");
        ((Broadphase*)m_pJobSemaphore)->query(&((CollisionObject*)&entity->m_kCollidable)->handle, &pairs);
        timer("Stphantom");
        for (int i = 0; i < pairs.size; ++i) {
            BroadphaseHandle* handle = pairs.data[i].second;
            CollisionObject* object = (CollisionObject*)((char*)handle + handle->ownerOffset);
            if (object->handle.type == 2) {
                PhantomInterface* phantom = (PhantomInterface*)((char*)object + object->ownerOffset);
                if (phantom) {
                    CollisionObject* collidable = (CollisionObject*)&entity->m_kCollidable;
                    SyncOverlap(phantom, collidable, (CollisionFilter*)m_pCollisionFilter);
                    if (updateShape != 0) phantom->refresh();
                    --pairs.size;
                    if (pairs.size != i) {
copyAlignedWords<sizeof(OverlapPair)>(&pairs.data[i], &pairs.data[pairs.size]);
                    }
                    --i;
                }
            }
        }
        hkArray<CollisionAgentEntry>* agents = ((CollisionObject*)&entity->m_kCollidable)->hkpLinkedCollidable_getCollisionEntriesDeterministicUnchecked_00d081e0();
        PairArray existing;
        existing.init();
        for (int i = 0; i < agents->m_iElementCount; ++i) {
            OverlapPair& pair = expandOverlapPair(existing);
            pair.first = &agents->m_data[i].agent->first->handle;
            pair.second = &agents->m_data[i].agent->second->handle;
        }
        hkpTypedBroadPhaseDispatcher_removeDuplicates(&existing, &pairs);
        releasePairs(existing);
    }
    timer("StcheckAgts");
    int quality = ((CollisionObject*)&entity->m_kCollidable)->handle.quality;
    CollisionObject* collidable = (CollisionObject*)&entity->m_kCollidable;
    hkArray<CollisionAgentEntry>* agents = collidable->hkpLinkedCollidable_getCollisionEntriesDeterministicUnchecked_00d081e0();
    for (int i = 0; i < agents->m_iElementCount; ++i) {
        CollisionAgentEntry& entry = agents->m_data[i];
CollisionObject* other; if(!((CollisionFilter*)m_pCollisionFilter)->filter.enabled(collidable, entry.other).value) goto ResetAgent; other=entry.other; if(!((CollisionDispatcher*)m_pDispatcher)->qualityEnabled[quality][other->handle.quality]) goto ResetAgent; if(updateShape==1) { EntityState* state; if((*(unsigned char*)&entity->m_pMotionState.m_type)==5) state=((EntityState*)((hkpEntity*)((char*)other + other->ownerOffset))->m_pSimulationIsland); else state=((EntityState*)entity->m_pSimulationIsland); _hkAgentNnMachine_UpdateShapeCollectionFilter(entry.agent,m_pCollisionInput,state); } goto nextAgent; ResetAgent: hkpWorldAgentUtil_removeAgentAndItsToiEvents(entry.agent); --i; ((EntityState*)entity->m_pSimulationIsland)->flags = (((EntityState*)entity->m_pSimulationIsland)->flags & ~2) | 1; nextAgent:;
    }
    if (pairs.size > 0) {
        timer("StaddAgts");
        CollisionFilter* filter = (CollisionFilter*)m_pCollisionFilter;
        ((BroadphaseDispatcher*)m_pBroadPhaseDispatcher)->hkpTypedBroadPhaseDispatcher_addPairs(pairs.data, pairs.size, filter ? &filter->filter : 0);
    }
    if (--m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
        if (m_iPendingOperationCount) FUN_00c91120();
        if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount) UpdateFields_00c91140();
    }
    releasePairs(pairs);
    timer("lt");
}


PhantomInterface* volatile probePhantom;
CollisionObject* volatile probeObject;
CollisionFilter* volatile probeFilter;
void probeOverlapCaller() { SyncOverlap(probePhantom, probeObject, probeFilter); }

extern "C" LocalM128 __cdecl _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 __cdecl _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 __cdecl _mm_shuffle_ps(LocalM128, LocalM128, int);
extern LocalM128 DAT_010c71e0;

struct RotationInput {
    LocalM128 translation;
    LocalM128 rotation;
};
struct VectorTemporary {
    union { LocalM128 value; float components[4]; };
    void FUN_00c7f7a0(const RotationInput*, const LocalM128*);
};
struct RotationOwner {
    void ProcessEntries_00c98820(const VectorTemporary*, const LocalM128*, int, int, int);
    void ApplyRotation(const RotationInput*, const LocalM128*, const LocalM128*, int, int, int);
};
// Transforms position via FUN_00c7f7a0, rotates direction by the transform's quaternion, then calls FUN_00c98820 with both plus a, b and c.
// @fnv 0x00c99610
void RotationOwner::ApplyRotation(const RotationInput* transform, const LocalM128* position,
    const LocalM128* direction, int a, int b, int c)
{
    VectorTemporary worldPosition;
    LocalM128 worldDirection;
    worldPosition.FUN_00c7f7a0(transform, position);
    LocalM128 q = transform->rotation;
    LocalM128 v = *direction;
    LocalM128 w = _mm_shuffle_ps(q, q, 0xff);
    LocalM128 product = _mm_mul_ps(v, q);
    LocalM128 sum01 = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    LocalM128 dot3 = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum01);
    LocalM128 crossA = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2));
    LocalM128 crossB = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9));
    LocalM128 cross = _mm_sub_ps(crossB, crossA);
    cross = _mm_mul_ps(cross, w);
    LocalM128 square = _mm_mul_ps(w, w);
    LocalM128 weighted = _mm_mul_ps(_mm_add_ps(square, DAT_010c71e0), v);
    LocalM128 projected = _mm_mul_ps(_mm_shuffle_ps(dot3, dot3, 0), q);
    LocalM128 rotated = _mm_add_ps(cross, _mm_add_ps(weighted, projected));
    worldDirection = _mm_add_ps(rotated, rotated);
    ProcessEntries_00c98820(&worldPosition, &worldDirection, a, b, c);
}

extern "C" LocalM128 __cdecl _mm_setr_ps(float, float, float, float);

struct hkTransformC997;

struct __declspec(align(16)) hkVector4C997 {
    float x, y, z, w;
    const LocalM128& getQuad() const { return *(const LocalM128*)&x; }
    LocalM128& getQuad() { return *(LocalM128*)&x; }
    void setZero4() { getQuad() = _mm_setzero_ps(); }
    void set(float a, float b, float c, float d = 0.0f)
    {
        getQuad() = _mm_setr_ps(a, b, c, d);
    }
    void setSub4(const hkVector4C997& a, const hkVector4C997& b) { getQuad() = _mm_sub_ps(*(LocalM128*)&a.x, *(LocalM128*)&b.x); }
    void FUN_00c7f7a0(const hkTransformC997& kTransform, const hkVector4C997& kVector) throw();
};


// The helper at 0x00c98880 is hkDebugDisplay::RenderLine, identifying this owner as hkDebugDisplay.
// Transforms a local origin and three axis vectors by kWorldFromLocal, then draws red, green, and blue debug lines from the origin along each axis.
// @fnv 0x00c99720
void hkDebugDisplay::displayFrame(const hkTransform_S& kWorldFromLocal, float afLength, int aiSoundId, int aiAllocationTag)
{
    hkVector4C997 kTemp;
    kTemp.setZero4();
    hkVector4C997 akStart;
    akStart.FUN_00c7f7a0(reinterpret_cast<const hkTransformC997&>(kWorldFromLocal), kTemp);

    hkVector4C997 akAxes[3];
    kTemp.set(afLength, 0.0f, 0.0f);
    akAxes[0].FUN_00c7f7a0(reinterpret_cast<const hkTransformC997&>(kWorldFromLocal), kTemp);
    kTemp.set(0.0f, afLength, 0.0f);
    akAxes[1].FUN_00c7f7a0(reinterpret_cast<const hkTransformC997&>(kWorldFromLocal), kTemp);
    kTemp.set(0.0f, 0.0f, afLength);
    akAxes[2].FUN_00c7f7a0(reinterpret_cast<const hkTransformC997&>(kWorldFromLocal), kTemp);

    hkVector4C997 akDirs[3];
    akDirs[0].setSub4(akAxes[0], akStart);
    akDirs[1].setSub4(akAxes[1], akStart);
    akDirs[2].setSub4(akAxes[2], akStart);

    RenderLine(reinterpret_cast<const hkVector4_S&>(akStart), reinterpret_cast<const hkVector4_S&>(akDirs[0]), 0xffff0000, aiSoundId, aiAllocationTag);
    RenderLine(reinterpret_cast<const hkVector4_S&>(akStart), reinterpret_cast<const hkVector4_S&>(akDirs[1]), 0xff008000, aiSoundId, aiAllocationTag);
    RenderLine(reinterpret_cast<const hkVector4_S&>(akStart), reinterpret_cast<const hkVector4_S&>(akDirs[2]), 0xff0000ff, aiSoundId, aiAllocationTag);
}

#include <stdarg.h>
struct RigidBody_s {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct RigidBodyList_s {
    RigidBody_s** m_apEntities;
    int m_uiItemCount;
};
struct Owner_s {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    RigidBodyList_s m_rigidBodyList;
};
struct System_s : hkpPhysicsSystem {
    void __thiscall addBody(RigidBody_s* body);
};
struct Context_s {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Owner_s* m_owner0;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    Owner_s** m_owners2;
    int m_ownerCount2;
};
struct BoolResult {
    char value;
    BoolResult(bool v) : value(v) {}
};
// Adds rigid bodies of m_owner0 and of each owner in m_owners2 to a3; returns true if m_ownerCount2 > 0 or m_owner0 has bodies.
// @fnv 0x00c926a0
static __declspec(noinline) BoolResult AddBodiesToSystem(Context_s* a2, ...) {
    va_list args;
    va_start(args, a2);
    System_s* a3 = va_arg(args, System_s*);
    va_end(args);
    bool flag = false;
    Owner_s* owner0 = a2->m_owner0;
    if (owner0) {
        for (int i = 0; i < owner0->m_rigidBodyList.m_uiItemCount; ++i) {
            if (i != 0 || owner0->m_rigidBodyList.m_apEntities[0]->unk10 != 0) {
                a3->addBody(owner0->m_rigidBodyList.m_apEntities[i]);
            }
        }
        flag = owner0->m_rigidBodyList.m_uiItemCount > 0;
    }
    for (Owner_s** it = a2->m_owners2; it != a2->m_owners2 + a2->m_ownerCount2; ++it) {
        RigidBodyList_s* list = &(*it)->m_rigidBodyList;
        for (int k = 0; k < list->m_uiItemCount; ++k) {
            a3->addBody(list->m_apEntities[k]);
        }
    }
    return BoolResult(a2->m_ownerCount2 > 0 || flag);
}

Context_s* volatile retry_context;
System_s* volatile retry_system;
volatile char retry_result;
void retryCaller() { retry_result = AddBodiesToSystem(retry_context, retry_system).value; }

// FUN_00c98240 : MSVC this-adjusting thunk  (sub ecx, 0x08 ; jmp <impl>)
struct A1_00c98240 {
    A1_00c98240();
    virtual void AdjustThisAndForward_00c98240();
    char pad[0x04];
};
struct A2_00c98240 {
    A2_00c98240();
    virtual void AdjustThisAndForward_00c98240();
};
struct Own_00c98240 : A1_00c98240, A2_00c98240 {
    Own_00c98240();
    virtual void key_fn();
// @fnv 0x00c98240
// src: GUESS 0x00c98240 (confidence: low)
    void AdjustThisAndForward_00c98240();
};
Own_00c98240::Own_00c98240() { }
void Own_00c98240::key_fn() { }
Own_00c98240* make_00c98240() { static Own_00c98240 o; return &o; }

// FUN_00c98310 : MSVC this-adjusting thunk  (sub ecx, 0x14 ; jmp <impl>)
struct A1_00c98310 {
    A1_00c98310();
    virtual void FUN_00c98310();
    char pad[0x10];
};
struct A2_00c98310 {
    A2_00c98310();
    virtual void FUN_00c98310();
};
struct Own_00c98310 : A1_00c98310, A2_00c98310 {
    Own_00c98310();
    virtual void key_fn();
// @fnv 0x00c98310
    void FUN_00c98310();
};
Own_00c98310::Own_00c98310() { }
void Own_00c98310::key_fn() { }
Own_00c98310* make_00c98310() { static Own_00c98310 o; return &o; }

// FUN_00c98320 : MSVC this-adjusting thunk  (sub ecx, 0x08 ; jmp <impl>)
struct A1_00c98320 {
    A1_00c98320();
    virtual void AdjustThisAndForward_00c98320();
    char pad[0x04];
};
struct A2_00c98320 {
    A2_00c98320();
    virtual void AdjustThisAndForward_00c98320();
};
struct Own_00c98320 : A1_00c98320, A2_00c98320 {
    Own_00c98320();
    virtual void key_fn();
// @fnv 0x00c98320
// src: GUESS 0x00c98320 (confidence: low)
    void AdjustThisAndForward_00c98320();
};
Own_00c98320::Own_00c98320() { }
void Own_00c98320::key_fn() { }
Own_00c98320* make_00c98320() { static Own_00c98320 o; return &o; }

// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00c98330();
    int unk04;
    int unk08;
};

struct SecondaryBase
{
    virtual void FUN_00c98330();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00c98330
    virtual void FUN_00c98330();
};

Derived::Derived()
{
}

// FUN_00c98340 : MSVC this-adjusting thunk  (sub ecx, 0x10 ; jmp <impl>)
struct A1_00c98340 {
    A1_00c98340();
    virtual void AdjustThisAndForward_00c98340();
    char pad[0x0c];
};
struct A2_00c98340 {
    A2_00c98340();
    virtual void AdjustThisAndForward_00c98340();
};
struct Own_00c98340 : A1_00c98340, A2_00c98340 {
    Own_00c98340();
    virtual void key_fn();
// @fnv 0x00c98340
// src: GUESS 0x00c98340 (confidence: low)
    void AdjustThisAndForward_00c98340();
};
Own_00c98340::Own_00c98340() { }
void Own_00c98340::key_fn() { }
Own_00c98340* make_00c98340() { static Own_00c98340 o; return &o; }

#include <math.h>


struct HkRefPtr {
    hkReferencedObject* m_p;
    HkRefPtr& operator=(HkRefPtr& rhs)
        {
            hkReferencedObject* pNew = rhs.m_p;
            if (pNew)
                pNew->addReference();
            if (m_p)
                m_p->removeReference();
            m_p = pNew;
            return *this;
        }
};

struct Sub_78_70 { float f00; int i04; };

struct Sub_78 {
    char pad00[0x6c];
    unsigned char b6c;
    unsigned char b6d;
    char pad6e[0x02];
    Sub_78_70* p70;
};

struct Sub_80 {
    char pad00[0x1e40];
    float f1e40;
    float f1e44;
};

struct Sub_08 {
    char pad00[0x24];
    float f24;
};

struct Dst_00c91c50 {
    char pad00[0x10];
    LocalM128 v10;
    int i_20;
    float f_24;
    unsigned char b_28;
    unsigned char b_29;
    char pad2a[0x06];
    LocalM128 v30;
    LocalM128 v40;
    unsigned char b_50;
    char pad51[0x02];
    unsigned char b_53;
    float f_54;
    HkRefPtr p58;
    HkRefPtr p5c;
    float f_60;
    int i_64;
    float f_68;
    HkRefPtr p6c;
    int i_70;
    unsigned char b_74;
    unsigned char b_75;
    char pad76[0x02];
    float f_78;
    float f_7c;
    int i_80;
    int i_84;
    float f_88;
    unsigned char b_8c;
    char pad8d[0x03];
    volatile float f_90;
    char pad94[0x04];
    unsigned char b_98;
    unsigned char b_99;
    char pad9a[0x02];
    float f_9c;
    int i_a0;
    unsigned char b_a4;
    unsigned char b_a5;
    unsigned char b_a6;
    unsigned char b_a7;
    float f_a8;
    float f_ac;
    int i_b0;
    unsigned char b_b4;
    char padb5[0x03];
    int i_b8;
    int i_bc;
    float f_c0;
    float f_c4;
    float f_c8;
    float f_cc;
    unsigned char b_d0;
    unsigned char b_d1;
    unsigned char b_d2;
    char padd3[0x01];
    int i_d4;
    unsigned char b_d8;
    unsigned char b_d9;
    char padda[0x02];
    float f_dc;
    unsigned char b_e0;
};

struct Src_00c91c50 {
    char pad00[0x08];
    Sub_08* p08;
    char pad0c[0x04];
    LocalM128 v10;
    char pad20[0x30];
    HkRefPtr p50;
    char pad54[0x08];
    int i5c;
    unsigned char b60;
    char pad61[0x17];
    Sub_78* p78;
    HkRefPtr p7c;
    Sub_80* p80;
    HkRefPtr p84;
    char pad88[0x28];
    unsigned char b_b0;
    unsigned char b_b1;
    char padb2[0x02];
    int i_b4;
    char padb8[0x10];
    unsigned char b_c8;
    char padc9[0x03];
    float f_cc;
    float f_d0;
    unsigned char b_d4;
    unsigned char b_d5;
    unsigned char b_d6;
    char padd7[0x01];
    float f_d8;
    float f_dc;
    int i_e0;
    unsigned char b_e4;
    char pade5[0x03];
    int i_e8;
    int i_ec;
    unsigned char b_f0;
    char padf1[0x03];
    float f_f4;
    float f_f8;
    float f_fc;
    float f_100;
    char pad104[0xb8];
    void* p_1bc;
    int i_1c0;
    char pad1c4[0x20];
    float f_1e4;
    float f_1e8;
    char pad1ec[0x54];
    float f_240;
    char pad244[0xb0];
    int i_2f4;
    int i_2f8;
    char pad2fc[0x08];
    unsigned char b_304;
    unsigned char b_305;
    unsigned char b_306;
    unsigned char b_307;
    float f_308;
    char pad30c[0x04];
    LocalM128 v_310;
    LocalM128 v_320;
    int i_330;
    int i_334;
    int i_338;
    char pad33c[0x04];
    unsigned char b_340;
    void hkpWorld_getCinfo(Dst_00c91c50* pOut);
};

// Copies fields from this into pOut, calling FUN_00c90510 on p50 and FUN_00c905b0 on pOut->p6c before transferring the reference.
// @fnv 0x00c91c50
// src: XBOX_PDB 0x00c91c50
void Src_00c91c50::hkpWorld_getCinfo(Dst_00c91c50* pOut)
{
    unsigned char unkZero;

    pOut->v10 = this->v10;
    pOut->i_20 = this->i_338;
    pOut->v30 = this->v_310;
    pOut->v40 = this->v_320;
    pOut->f_54 = *(float*)((char*)this->p78 + 8);
    pOut->p58 = this->p7c;
    pOut->p5c = this->p84;
    pOut->b_28 = (unsigned char)(this->p_1bc ? *(int*)((char*)this->p_1bc + 0x30) : 3);
        pOut->b_29 = *(this->p_1bc ? (unsigned char*)((char*)this->p_1bc + 0x34) : &(unkZero = 0));
    pOut->b_50 = (this->i5c != 0);
    pOut->b_53 = this->b60;
    pOut->f_60 = *(float*)((char*)this->p80 + 0x1e40);
    pOut->f_68 = *(float*)((char*)this->p80 + 0x1e44);
    pOut->f_90 = this->f_cc;
    pOut->f_90 = this->f_d0;
    pOut->b_98 = this->b_d4;
    if (this->p50.m_p)
        this->p50.m_p->addReference();
    if (pOut->p6c.m_p)
        pOut->p6c.m_p->removeReference();
    pOut->p6c.m_p = this->p50.m_p;
    pOut->i_70 = this->i_330;
    pOut->i_64 = this->i_334;
    pOut->b_74 = this->b_340;
    pOut->b_75 = this->p78->b6d;
    pOut->f_24 = this->f_240;
    pOut->f_78 = this->f_1e4;
    pOut->f_7c = this->f_1e8;
    pOut->i_80 = this->i_2f4;
    pOut->i_84 = this->i_2f8;
    pOut->f_88 = (float)sqrt(this->f_308);
    pOut->b_8c = this->b_304;
    pOut->b_a4 = this->b_305;
    pOut->b_a5 = this->b_306;
    pOut->b_a6 = this->b_307;
    pOut->f_9c = this->p78->p70->f00;
    pOut->i_a0 = this->p78->p70->i04;
    pOut->b_99 = this->p78->b6c;
    pOut->b_a7 = this->b_d6;
    pOut->f_ac = this->f_dc;
    pOut->i_b0 = this->i_e0;
    pOut->b_b4 = this->b_e4;
    pOut->i_b8 = this->i_e8;
    pOut->i_bc = this->i_ec;
    pOut->f_a8 = this->f_d8;
    pOut->f_c0 = this->f_f4;
    pOut->f_c4 = this->f_f8;
    pOut->f_c8 = this->f_fc;
    pOut->f_cc = this->f_100;
    pOut->b_d0 = this->b_d5;
    pOut->b_d1 = this->b_f0;
    pOut->f_dc = this->p08->f24;
    pOut->b_d2 = this->b_c8;
    pOut->b_d8 = this->b_b0;
    pOut->b_d9 = this->b_b1;
    pOut->i_d4 = this->i_b4;
    pOut->b_e0 = (this->i_1c0 != 0);
}

struct MatchAllocator {
    virtual void v00();
    virtual void* allocate(int size);
};
struct MatchRouter {
    int unk00, unk04, unk08, unk0C;
    MatchAllocator* heap;
};
// Retained: the shared physics system lacks the default constructor and phantom-add call.
struct FUN_00d065e0 {
    void* vtable;
    unsigned short memorySize;
    short referenceCount;
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
    unsigned char active;
    unsigned char unk41, unk42, unk43;
    FUN_00d065e0() throw();
    static void* operator new(unsigned int size)
    {
        MatchRouter* router = (MatchRouter*)::hkMemoryRouter_getInstance();
        FUN_00d065e0* memory = (FUN_00d065e0*)router->heap->allocate(size);
        memory->memorySize = (unsigned short)size;
        return memory;
    }
    void hkpPhysicsSystem_addPhantom(void* phantom);
};
struct MatchStatus {
    unsigned char value;
    MatchStatus(bool v) : value(v) {}
    operator bool() const { return value != 0; }
};
struct MatchPhantoms {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14;
    void* p18; void* p1C; void* p20; void* p24; void* p28; void* p2C;
};
struct MatchWorld {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    void** phantoms;
    int phantomCount;
    MatchPhantoms* GetValue();
    void __thiscall AddPhysicsSystem(hkArray<FUN_00d065e0*>* systems);
};
struct FUN_00d065e0Value { FUN_00d065e0* p; };
MatchStatus __cdecl AddBodiesToSystem(MatchWorld*, FUN_00d065e0*);
MatchStatus __cdecl CollectShapes(MatchWorld*, FUN_00d065e0*);
// src: HAVOK_LIB 0x00c92950
static __declspec(noinline) void enumerateAllPhantomsInWorld(MatchWorld* world, FUN_00d065e0* system)
{
    MatchPhantoms* excluded = world->GetValue();
    if (excluded) {
        for (int i=0; i<world->phantomCount; ++i) {
            void* p = world->phantoms[i];
            if (p != excluded->p18 && p != excluded->p1C && p != excluded->p20 &&
                p != excluded->p24 && p != excluded->p28 && p != excluded->p2C)
                system->hkpPhysicsSystem_addPhantom(p);
        }
    } else {
        for (int i=0; i<world->phantomCount; ++i)
            system->hkpPhysicsSystem_addPhantom(world->phantoms[i]);
    }
}
// Creates one or two FUN_00d065e0 objects, adds them to the systems array, then calls CollectShapes, FUN_00c92950, InvokeOnAllOwners and FUN_00c928c0 on the last.
// @fnv 0x00c93b30
void MatchWorld::AddPhysicsSystem(hkArray<FUN_00d065e0*>* systems)
{
    FUN_00d065e0* first = new FUN_00d065e0;
    FUN_00d065e0* system;
    if (AddBodiesToSystem(this, first)) {
        first->active = 0;
        systems->pushBack(first);
        system = new FUN_00d065e0;
    } else {
        system = first ? first : new FUN_00d065e0;
    }
    systems->pushBack(system);
    CollectShapes(this, system);
    enumerateAllPhantomsInWorld(this, system);
    zzVal_c92860 a = { system };
    InvokeOnAllOwners((FUN_00c928c0_Context*)this, a);
    enumerateAllActionsInWorld((FUN_00c928c0_Context*)this, (hkpPhysicsSystem*)system);
}

extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern unsigned int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int);
extern const char str_010c6758[];
extern const char str_010c6748[];
extern const char str_010c6734[];
extern const char str_010c6720[];
extern const char str_01076f38[];

struct TimerEntryC944 { const char* name; unsigned int ticks; unsigned int unk08; };
struct TimerEntryC9442 { const char* name; unsigned int ticks; unsigned int unk08; const char* name2; };
struct TimerBufferC944 { unsigned int unk00; void* current; unsigned int unk08; void* end; };

struct AllocatorC944 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Deallocate(void* p, int size);
};
struct ThreadAlloc {
    char* m_next;             // next free stack byte
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    AllocatorC944* m_pThreadAllocator;   // +0x10
};


class BroadPhaseC944 {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void updateOverlaps(struct HandleC944* a, struct TempArray* arr);   // vtable +0x48
};

struct WorldObjectC944; struct CollidableC944;
struct HandleC944 {
    unsigned int m_iOwnerObjectOffset;
    unsigned char m_type;
    signed char m_iOwnerOffset;
    unsigned char m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;
    CollidableC944* getOwner() { return reinterpret_cast<CollidableC944*>(reinterpret_cast<char*>(this) + m_iOwnerOffset); }
};

struct CollidableC944 : hkpCdBody {
    signed char m_iOwnerOffset;
    unsigned char m_uiForceCollideOntoPpu;
    unsigned short m_uiShapeSizeOnSpu;
    HandleC944 m_kBroadPhaseHandle;
    WorldObjectC944* getOwner() { return reinterpret_cast<WorldObjectC944*>(reinterpret_cast<char*>(this) + m_iOwnerOffset); }
};
struct FilterResult { char value; FilterResult() {} FilterResult(bool b) : value(b) {} FilterResult(const FilterResult& b) : value(b.value) {} };
struct WorldObjectC944 : hkReferencedObject {
    hkpWorld* m_pOwningWorld;
    unsigned int m_ulUserData;
    CollidableC944 m_kCollidable;
    virtual const hkClass* getClassType() const; virtual void calcContentStatistics(hkStatisticsCollector*, const hkClass*) const; virtual void v0c(); virtual void v10();
    virtual void v14(); virtual void v18();
};
// Retained: the shared phantom lacks the typed virtual overlap interface.
// Replacing this local helper's parameter type also changes its internal ABI.
class PhantomC944 : public WorldObjectC944 {
public:
    virtual void AddOverlappingCollidable(CollidableC944*);
    virtual FilterResult GetFilterResult(CollidableC944*);
    virtual void RemoveOverlappingObject(CollidableC944*);
    virtual void v28(); virtual void v2c();
    virtual void ProcessContactPoints();
};

struct BroadPhaseC944HandlePair { HandleC944* first; HandleC944* second; };

struct TempArray {
    BroadPhaseC944HandlePair* m_data; // +0x00
    int m_iElementCount;                // +0x04
    int m_iCapacityState;    // +0x08
    char* m_original;
    TempArray(int count) : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000u) {
        ThreadAlloc* storage = (ThreadAlloc*)hkMemoryRouter_getInstance();
        char* top = storage->m_next;
        storage->m_next = top + ((count * sizeof(BroadPhaseC944HandlePair) + 127) & ~127);
        m_data = (BroadPhaseC944HandlePair*)top;
        m_original = top;
        m_iCapacityState = count | 0x80000000u;
    }
    void releaseStack() {
        char* oldTop = m_original;
        if ((void*)oldTop == m_data) m_iElementCount = 0;
        ((ThreadAlloc*)hkMemoryRouter_getInstance())->m_next = oldTop;
    }
    void releaseHeap(AllocatorC944& heap) {
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000u))
            heap.Deallocate(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(BroadPhaseC944HandlePair));
        m_data = 0;
        m_iCapacityState = 0x80000000u;
    }
};

struct PendingOp {
    unsigned char m_type;      // +0x00
    void* m_p;                 // +0x04
    unsigned char m_flag;      // +0x08
};


static __declspec(noinline) void SyncOverlap(PhantomC944* phantom,CollidableC944* collidable,hkpCollisionFilter* filter)
{
    FilterResult added = phantom->GetFilterResult(collidable);
    typedef FilterResult (__thiscall* CollidableFilterCall)(hkpCollidableCollidableFilter*, const CollidableC944*, const CollidableC944*);
    if (((CollidableFilterCall)(*(void***)reinterpret_cast<hkpCollidableCollidableFilter*>((char*)filter + 8))[1])(reinterpret_cast<hkpCollidableCollidableFilter*>((char*)filter + 8), &phantom->m_kCollidable, collidable).value) {
        if (!added.value) phantom->AddOverlappingCollidable(collidable);
        if (collidable->m_kBroadPhaseHandle.m_type == 2) {
            if (!static_cast<PhantomC944*>(collidable->getOwner())->GetFilterResult(&phantom->m_kCollidable).value)
                static_cast<PhantomC944*>(collidable->getOwner())->AddOverlappingCollidable(&phantom->m_kCollidable);
        }
    } else {
        if (added.value) phantom->RemoveOverlappingObject(collidable);
        if (collidable->m_kBroadPhaseHandle.m_type == 2) {
            if (static_cast<PhantomC944*>(collidable->getOwner())->GetFilterResult(&phantom->m_kCollidable).value)
                static_cast<PhantomC944*>(collidable->getOwner())->RemoveOverlappingObject(&phantom->m_kCollidable);
        }
    }
}

struct PhantomArgC944 { PhantomC944* p; PhantomArgC944(PhantomC944* q) : p(q) {} };
struct WorldC944 : hkpWorld { void UpdatePhantom(PhantomC944*, int); void hkpWorld_queueOperation(PendingOp*); void FUN_00c91120(); void UpdateFields_00c91140(); };

// Queries broad phase for overlaps with a phantom, applies collision filters, and optionally processes contact points.
// @fnv 0x00c944a0
void WorldC944::UpdatePhantom(PhantomC944* apPhantom, int abProcessContacts)
{
    if (m_iCriticalOperationsLockCount != 0)
    {
        PendingOp op;
        op.m_type = 0x14;
        op.m_p = (PhantomC944*)apPhantom;
        op.m_flag = (unsigned char)abProcessContacts;
        hkpWorld_queueOperation(&op);
        return;
    }
    m_iCriticalOperationsLockCount = 1;

    TimerBufferC944* t1 = (TimerBufferC944*)TlsGetValue(DAT_0126835c);
    TimerEntryC9442* e1 = (TimerEntryC9442*)t1->current;
    if (e1 < t1->end)
    {
        e1->name = str_010c6758;
        e1->name2 = str_010c6748;
        _ReadWriteBarrier();
        volatile unsigned int ticks1 = (unsigned int)__rdtsc();
        e1->ticks = ticks1;
        t1->current = e1 + 1;
    }

    int queryCount = m_iBroadPhaseQuerySize;
    PhantomC944* ent = *(PhantomC944* volatile*)&apPhantom;
    TempArray arr(queryCount);
    ((BroadPhaseC944*)m_pJobSemaphore)->updateOverlaps(&ent->m_kCollidable.m_kBroadPhaseHandle, &arr);

    TimerBufferC944* t2 = (TimerBufferC944*)TlsGetValue(DAT_0126835c);
    TimerEntryC944* e2 = (TimerEntryC944*)t2->current;
    if (e2 < t2->end)
    {
        e2->name = str_010c6734;
        _ReadWriteBarrier();
        volatile unsigned int ticks2 = (unsigned int)__rdtsc();
        e2->ticks = ticks2;
        t2->current = e2 + 1;
    }

    unsigned int i = 0;
    if (arr.m_iElementCount > 0)
    {
        do
        {
            HandleC944* p = arr.m_data[i].second;
            if (p != &ent->m_kCollidable.m_kBroadPhaseHandle)
            {
                CollidableC944* q = p->getOwner();
                SyncOverlap(ent,q,static_cast<hkpCollisionFilter*>(m_pCollisionFilter));
            }
            i++;
        } while ((int)i < arr.m_iElementCount);
    }

    if (abProcessContacts != 0)
    {
        TimerBufferC944* t3 = (TimerBufferC944*)TlsGetValue(DAT_0126835c);
        TimerEntryC944* e3 = (TimerEntryC944*)t3->current;
        if (e3 < t3->end)
        {
            e3->name = str_010c6720;
                _ReadWriteBarrier();
        volatile unsigned int ticks3 = (unsigned int)__rdtsc();
            e3->ticks = ticks3;
            t3->current = e3 + 1;
        }
        ent->ProcessContactPoints();
    }

    if (--m_iCriticalOperationsLockCount == 0)
    {
        if (m_bBlockExecutingPendingOperations == 0)
        {
            if (m_iPendingOperationCount != 0)
                FUN_00c91120();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount != 0)
                UpdateFields_00c91140();
        }
    }

    TimerBufferC944* t4 = (TimerBufferC944*)TlsGetValue(DAT_0126835c);
    TimerEntryC944* e4 = (TimerEntryC944*)t4->current;
    if (e4 < t4->end)
    {
        e4->name = str_01076f38;
        _ReadWriteBarrier();
        volatile unsigned int ticks4 = (unsigned int)__rdtsc();
        e4->ticks = ticks4;
        t4->current = e4 + 1;
    }

    arr.releaseStack();
    arr.releaseHeap(*((ThreadAlloc*)hkMemoryRouter_getInstance())->m_pThreadAllocator);
}

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);


inline void* getMemoryRouter() throw() { return &hkMemoryRouter::getInstance(); }
extern "C" void __cdecl hkArrayUtil__reserve(void* inst, void* arr, int num, int elemSize) throw();
extern "C" void __cdecl hkpWorldCallbackUtil_fireEntityRemoved(hkpWorld* world, void* entity) throw();
extern "C" void __cdecl hkpEntityCallbackUtil_fireEntityRemoved(void* entity) throw();
extern "C" void __cdecl hkpWorldOperationUtil_removeEntitySI(hkpWorld* world, void* entity) throw();

struct MyPendingQueue {
    void __thiscall hkpWorld_queueOperation(void* op) throw();
};

struct FUN_00cf70f0_Class {
    void __thiscall DispatchPairs(void* data, int size) throw();
};

struct FUN_00d01a80_Class {
    void __thiscall FreeStorage() throw();
};



struct MyExecPending {
    void __thiscall ExecutePendingOperations() throw();
    void __thiscall FUN_00c91120() throw();
};

struct MyExecBodyPending {
    void __thiscall UpdateFields_00c91140() throw();
};

class hkpSimulation_00c951b0 {
public:
    virtual ~hkpSimulation_00c951b0() throw();
    virtual void slot04() throw();
    virtual void slot08() throw();
    virtual void slot0c() throw();
    virtual void slot10() throw();
    virtual void slot14() throw();
    virtual void slot18() throw();
    virtual void slot1c() throw();
    virtual void removeEntities(void* const* entities, int numEntities, hkpWorld* world, int unk) throw();
};

class hkpBroadPhase_00c951b0 {
public:
    virtual ~hkpBroadPhase_00c951b0() throw();
    virtual void slot04() throw();
    virtual void slot08() throw();
    virtual void slot0c() throw();
    virtual void slot10() throw();
    virtual void slot14() throw();
    virtual void slot18() throw();
    virtual void slot1c() throw();
    virtual void DispatchCollisionPairs(void* array, void* pairs) throw();
};

class hkMemory_00c951b0 {
public:
    virtual ~hkMemory_00c951b0() throw();
    virtual void slot04() throw();
    virtual void slot08() throw();
    virtual void slot0c() throw();
    virtual void deallocate(void* p, int numBytes) throw();
};

struct DummyCollidable_00c951b0 {
    void* m_pCollisionShape;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_kBroadPhaseHandle;
};

struct EntityMember {
    void* unk00; void* unk04; void* unk08; void* unk0c;
    void* unk10; void* unk14; void* unk18; void* unk1c; void* unk20;
    void FreeStorage() throw();
};


struct WorldOp_00c951b0 {
    unsigned char m_type;
    unsigned char pad0;
    unsigned short pad1;
    void* m_kActorEntries;
    short m_iActorEntryCount;
};

inline hkMonitorStream& hkMonitorStream::getInstance()
{
    return *static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
}

struct MonitorCommand {
    const char* name;
    unsigned int time;
    unsigned int timeHigh;
};
struct MonitorBeginCommand : MonitorCommand {
    const char* firstSub;
};
    inline void timerBeginList(hkMonitorStream* stream, const char* name, const char* firstSub, volatile unsigned int& stamp) throw() {
        MonitorBeginCommand* pos = (MonitorBeginCommand*)stream->m_end.m_storage;
        if ((char*)pos < stream->m_capacityMinus16.m_storage) {
            pos->name = name;
            pos->firstSub = firstSub;
            _ReadWriteBarrier();
            stamp = (unsigned int)__rdtsc();
            pos->time = stamp;
            stream->m_end.m_storage = (char*)(pos + 1);
        }
    }
    inline void timerSplitList(hkMonitorStream* stream, const char* name) throw() {
        MonitorCommand* pos = (MonitorCommand*)stream->m_end.m_storage;
        if ((char*)pos < stream->m_capacityMinus16.m_storage) {
            pos->name = name;
            _ReadWriteBarrier();
            volatile unsigned int stamp = (unsigned int)__rdtsc();
            pos->time = stamp;
            stream->m_end.m_storage = (char*)(pos + 1);
        }
    }
    inline void timerEndList(hkMonitorStream* stream, const char* name) throw() { timerSplitList(stream, name); }





template <class T>
struct MyArray {
    hkArray<T>& base;
    inline MyArray(hkArray<T>& b) throw() : base(b) { base.m_data=0; base.m_iElementCount=0; base.m_iCapacityState=0x80000000; }

    inline ~MyArray() throw() {
        hkMemoryRouter* tm = (hkMemoryRouter*)getMemoryRouter();
        hkMemory_00c951b0* memory = reinterpret_cast<hkMemory_00c951b0*>(tm->m_temp);
        base.m_iElementCount = 0;
        if ((base.m_iCapacityState & 0x80000000) == 0) {
            memory->deallocate(base.m_data, (base.m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }

    inline void reserve(void* tm, int num) throw() {
        if ((base.m_iCapacityState & 0x3fffffff) < num) {
            hkArrayUtil__reserve(((hkMemoryRouter*)tm)->m_temp, &base, num, sizeof(T));
        }
    }

    inline void pushBackUnchecked(const T& val) throw() {
        base.m_data[base.m_iElementCount++] = val;
    }
};

// Broad-phase output passed to DispatchPairs (0x00cf70f0): two handle pointers, unlike include/Pair.h's integers.
struct BroadPhaseHandlePair {
    void* a;
    void* b;
};

struct MyLocalArray : public hkArrayBase<BroadPhaseHandlePair> {
    BroadPhaseHandlePair* m_savedStack;

    inline MyLocalArray(int capacity) throw() {
        hkMemoryRouter* tm = (hkMemoryRouter*)getMemoryRouter();
        char* cur = static_cast<char*>(tm->m_stack.m_next.m_storage);
        tm->m_stack.m_next.m_storage = cur + ((capacity * sizeof(BroadPhaseHandlePair) + 127) & ~127);
        this->m_data = (BroadPhaseHandlePair*)cur;
        this->m_savedStack = (BroadPhaseHandlePair*)cur;
        this->m_iCapacityState = capacity | 0x80000000;
    }

    inline ~MyLocalArray() throw() {
        BroadPhaseHandlePair* savedStack = m_savedStack;
        if (savedStack == this->m_data) {
            this->m_iElementCount = 0;
        }
        hkMemoryRouter* stackRouter = (hkMemoryRouter*)getMemoryRouter();
        stackRouter->m_stack.m_next.m_storage = (char*)savedStack;
        hkMemoryRouter* tm = (hkMemoryRouter*)getMemoryRouter();
        hkMemory_00c951b0* memory = reinterpret_cast<hkMemory_00c951b0*>(tm->m_heap);
        this->m_iElementCount = 0;
        if ((this->m_iCapacityState & 0x80000000) == 0) {
            memory->deallocate(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(BroadPhaseHandlePair));
        }
    }
};

// The pending operation and the handle array (an hkArray<void*>, constructed by MyArray) share one stack slot.
union PendingOrHandles {
    WorldOp_00c951b0 operation;
    void* handles[sizeof(hkArray<void*>) / sizeof(void*)];
};
union TimerOrEnd { volatile unsigned int stamp; void* const* end; };
struct HostWorld_00c951b0 : hkpWorld {
    void RemoveEntities(void* const* entityBatch, int numEntities) throw();
};

// Removes a batch of entities from the simulation, dispatches broad-phase collision pairs, and invokes per-entity removal callbacks.
// @fnv 0x00c951b0
void HostWorld_00c951b0::RemoveEntities(void* const* entityBatch, int numEntities) throw()
{
    PendingOrHandles pendingOrHandles;
    if (numEntities < 1)
        return;

    if (m_iCriticalOperationsLockCount != 0)
    {
        {
        WorldOp_00c951b0& op = pendingOrHandles.operation;
        op.m_type = 7;
        op.m_kActorEntries = (void*)entityBatch;
        op.m_iActorEntryCount = (short)numEntities;
        ((MyPendingQueue*)this)->hkpWorld_queueOperation(&op);
        }
        return;
    }

    m_iCriticalOperationsLockCount = 1;
    void* const* it;
    TimerOrEnd timerOrEnd;

    timerBeginList((hkMonitorStream*)TlsGetValue(DAT_0126835c), "LtRemEntities", "StInit+CallBck", timerOrEnd.stamp);

    ((hkpSimulation_00c951b0*)m_pSimulation)->removeEntities(entityBatch, numEntities, this, 1);

    {
        MyArray<void*> array(reinterpret_cast<hkArray<void*>&>(pendingOrHandles.handles));
        array.reserve(getMemoryRouter(), numEntities);
        it = entityBatch;
        timerOrEnd.end = entityBatch + numEntities;

        for (; it != timerOrEnd.end; ++it)
        {
            DummyCollidable_00c951b0* coll = (DummyCollidable_00c951b0*)&((hkpEntity*)*it)->m_kCollidable;
            if (coll->m_pCollisionShape != 0)
            {
                array.pushBackUnchecked(&coll->m_kBroadPhaseHandle);
            }
        }

        if (array.base.m_iElementCount != 0)
        {
            timerSplitList((hkMonitorStream*)TlsGetValue(DAT_0126835c), "StBroadPhase");

            MyLocalArray pairs(m_iBroadPhaseQuerySize);

            ((hkpBroadPhase_00c951b0*)m_pJobSemaphore)->DispatchCollisionPairs(&array.base, &pairs);

            timerSplitList((hkMonitorStream*)TlsGetValue(DAT_0126835c), "StDelAgents");

            ((FUN_00cf70f0_Class*)m_pBroadPhaseDispatcher)->DispatchPairs(pairs.m_data, pairs.m_iElementCount);
        }
    }

    timerSplitList((hkMonitorStream*)TlsGetValue(DAT_0126835c), "StRemoveCb");

    for (it = entityBatch; it != timerOrEnd.end; ++it)
    {
        hkpWorldCallbackUtil_fireEntityRemoved(this, *it);
        hkpEntityCallbackUtil_fireEntityRemoved(*it);
        hkpWorldOperationUtil_removeEntitySI(this, *it);

        if (((hkpEntity*)*it)->m_kCollidable.m_kBoundingVolumeData.m_pChildShapeAabbs != 0)
        {
            ((EntityMember*)&((hkpEntity*)*it)->m_kCollidable.m_kBoundingVolumeData)->FreeStorage();
        }

        if (((hkpEntity*)*it)->m_usMemSizeAndFlags == 0)
        {
            ((hkpEntity*)*it)->vf05();
        }

        ((hkReferencedObject*)*it)->removeReference();
    }

    timerEndList((hkMonitorStream*)TlsGetValue(DAT_0126835c), "lt");

    --m_iCriticalOperationsLockCount;
    if (m_iCriticalOperationsLockCount == 0)
    {
        if (!m_bBlockExecutingPendingOperations)
        {
            if (m_iPendingOperationCount != 0)
            {
                ((MyExecPending*)this)->FUN_00c91120();
            }
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount != 0)
            {
                ((MyExecBodyPending*)this)->UpdateFields_00c91140();
            }
        }
    }
}

struct Op { char type; int p; };
struct Pt { unsigned short x; unsigned short pad; unsigned short y; };
struct Req { char k; Req(char c):k(c){} Req(const Req& o):k(o.k){} };
struct Info { int u0, u1, cnt; };
struct Sub {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
  virtual int T20();
  virtual void T24(Req r, Pt* out);
};
struct Item;
struct Dev {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
  virtual int T20();
  virtual void T24(Req r, Pt* out);
};
struct Item {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5();
  virtual int T18();
  virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
  virtual void T40();
  int u04, u08;
  struct Ctl3* m_0c;
  int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30;
  unsigned int m_34;
  int unk38; int unk3c; int unk40;
  Info* m_44;
  void hkpConstraintInstance_pointNullsToFixedRigidBody();
};
struct Ctl3 {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
  virtual int T20();
  virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
  virtual void T40();
  int unk04; int unk08; int unk0c; int unk10; int unk14;
  Sub* m_18; unsigned short m_1c, m_1e;
};
struct Mgr {
  void* unk00;
  void* unk04;
  void* unk08;
  void* unk0C;
  void* unk10;
  void* unk14;
  void* unk18;
  void* unk1C;
  void* unk20;
  void* unk24;
  void* unk28;
  void* unk2C;
  void* unk30;
  void* unk34;
  void* unk38;
  void* unk3C;
  void* unk40;
  void* unk44;
  void* unk48;
  void* unk4C;
  void* unk50;
  void* unk54;
  void* unk58;
  void* unk5C;
  void* unk60;
  void* unk64;
  void* unk68;
  void* unk6C;
  void* unk70;
  void* unk74;
  void* unk78;
  void* unk7C;
  void* unk80;
  void* unk84;
  void* unk88;
  void* m_8c; unsigned int m_90; unsigned int m_94; unsigned int m_98; char m_9c;
  char unk9d, unk9e, unk9f; int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; int unke0; int unke4; int unke8; int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108;
  unsigned int m_10c;
  void hkpWorld_queueOperation(Op* o);
  void FUN_00c91120();
  void hkpWorld_addAction(Info* i);
  void* hkpWorld_addConstraint(Item* it);
};
extern void* __cdecl hkpWorldOperationUtil_addConstraintImmediately(Mgr*, Item*, unsigned int);
// If m_94 is nonzero, queues an op of type 8 for it and returns 0; otherwise sets it up, calls FUN_00cb3ca0 and returns its result.
// @fnv 0x00c97d30
// src: HAVOK_LIB 0x00c97d30
void* Mgr::hkpWorld_addConstraint(Item* it)
{
  unsigned int v94 = m_94;
  if (v94) {
    Op o; o.type = 8; o.p = (int)it;
    hkpWorld_queueOperation(&o);
    return 0;
  }
  if (it->m_0c->T20() == 12) {
    Ctl3* c = it->m_0c;
    if (c->m_1c == 0) {
      Pt pt;
      c->m_18->T24(Req(1), &pt);
      c->m_1c = pt.x;
      c->m_1e = pt.y;
    }
  }
  m_9c = 1;
  it->hkpConstraintInstance_pointNullsToFixedRigidBody();
  it->m_34 = ++m_10c;
  void* res = hkpWorldOperationUtil_addConstraintImmediately(this, it, 1);
  if (it->T18() == 1) {
    if (it->m_44->cnt == 0)
      hkpWorld_addAction(it->m_44);
    it->m_0c->T40();
  }
  m_9c = 0;
  if (!m_94 && m_8c) FUN_00c91120();
  return res;
}

// Calls AddBodiesToSystem, stores the result of CollectShapes into system->active, and returns that value.
// @fnv 0x00c927c0
// src: HAVOK_LIB 0x00c927c0
static __declspec(noinline) unsigned char enumerateAllEntitiesInWorld(MatchWorld* world, FUN_00d065e0* system)
{
    AddBodiesToSystem(world, system);
    unsigned char active = CollectShapes(world, system).value;
    system->active = active;
    return active;
}

MatchWorld* volatile g_matchWorld;
FUN_00d065e0* volatile g_matchSystem;
volatile unsigned char g_matchResult;
void CallMatchSystem() { g_matchResult = enumerateAllEntitiesInWorld(g_matchWorld, g_matchSystem); }

namespace fnv_00c982c0 {
#include <windows.h>


// @fnv 0x00c982c0
// src: GUESS 0x00c982c0 (confidence: low)
void __stdcall Object_UpdateFields_00c982c0(unsigned char* out, int a1, int a2, int a3, int a4)
{
    *out = 1;
}
}  // namespace fnv_00c982c0


// @fnv 0x00c982d0
// src: GUESS 0x00c982d0 (confidence: low)
void __stdcall hkpWorld_UpdateState_00c982d0(unsigned char* out, int a2, int a3)
{
    *out = 1;
}

namespace fnv_00c96df0 {
extern double DAT_01012060;
extern const char str_010c68ec[];
extern const char str_010c6748[];
extern const char str_010c68dc[];
extern const char str_01076f38[];
extern "C" unsigned __int64 __rdtsc() throw();
extern "C" void _ReadWriteBarrier();


struct ThreadMemory {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m_pMemoryAllocator;
};

struct BroadPhaseHandle {
    int m_iOwnerObjectOffset;
    char m_type;
    signed char m_iOwnerOffset;
};

struct BroadPhaseHandlePair {
    void* m_kPointA;
    BroadPhaseHandle* m_kPointB;
};

template <class T, int N>
struct InplaceArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T m_kStorage[N];

    InplaceArray() throw() {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = N | 0x80000000;
    }

    ~InplaceArray() throw() {
        ThreadMemory* tm = (ThreadMemory*)hkMemoryRouter_getInstance();
        hkMemoryAllocator* mem = tm->m_pMemoryAllocator;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) {
            mem->bufFree(m_data, (cap & 0x3fffffff) * sizeof(T));
        }
    }
};

struct __declspec(align(16)) Aabb {
    float m_kMinimumCorner[4];
    float m_kMaximumCorner[4];
};

struct Shape {
    virtual void slot00() throw();
    virtual void slot04() throw();
    virtual void slot08() throw();
    virtual void slot0c() throw();
    virtual void slot10() throw();
    virtual void slot14() throw();
    virtual void slot18() throw();
    virtual void getAabb(const void* transform, float tol, Aabb& out) throw();
    int unk04;
    int unk08;
    int m_type;
};

struct Collidable {
    Shape* m_pCollisionShape;
    int unk04;
    void* m_kMotionTransform;
};

struct BroadPhase {
    virtual void slot00() throw();
    virtual void slot04() throw();
    virtual void slot08() throw();
    virtual void slot0c() throw();
    virtual void slot10() throw();
    virtual void slot14() throw();
    virtual void slot18() throw();
    virtual void slot1c() throw();
    virtual void slot20() throw();
    virtual void slot24() throw();
    virtual void slot28() throw();
    virtual void slot2c() throw();
    virtual void slot30() throw();
    virtual void slot34() throw();
    virtual void slot38() throw();
    virtual void slot3c() throw();
    virtual void slot40() throw();
    virtual void GetAabbHits(const Aabb& aabb, void* pairs);
};

struct FilterResult {
    char val;
    FilterResult() throw() {}
};

struct FilterBase {
    virtual void slot00() throw();
    int unk04;
};

struct FilterSub {
    virtual void slot00() throw();
    virtual FilterResult IsCollisionEnabled(const Collidable* a, const Collidable* b) throw();
};

struct C96CollisionFilter : public FilterBase, public FilterSub {
};

struct DispatcherAgentEntry {
    void (__cdecl* m_func)(const Collidable* a, const Collidable* b, const void* input, void* collector) throw();
    void* m_func1;
    void* m_func2;
    void* m_func3;
    void* m_func4;
};

struct C96CollisionDispatcher {
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
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    int m_iEntryCount;
    DispatcherAgentEntry m_entries[35];
};

struct QueryCollisionInput {
    C96CollisionDispatcher* m_pCollisionDispatcher;
    int unk04;
    float m_fScalar;
};

struct Collector {
    void* vtable;
    char m_earlyOutHit;
};

struct MonitorCommand {
    const char* m_name;
    unsigned int m_ticks;
    unsigned int m_extra;
    const char* m_category;
};



struct World {
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
    BroadPhase* m_pJobSemaphore;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    QueryCollisionInput* m_pCollisionInput;
    C96CollisionFilter* m_pCollisionFilter;

    void hkpWorld_getPenetrations(Collidable* collA, const QueryCollisionInput* input, Collector* collector) throw();
};

// @fnv 0x00c96df0
// src: EXE 0x00c96df0
void World::hkpWorld_getPenetrations(Collidable* collA, const QueryCollisionInput* input, Collector* collector) throw() {

    hkMonitorStream& ms1 = hkMonitorStream::getInstance();
    char* pos1 = ms1.m_end.m_storage;
    if (pos1 < ms1.m_capacityMinus16.m_storage) {
        ((MonitorCommand*)pos1)->m_name = str_010c68ec;
        ((MonitorCommand*)pos1)->m_category = str_010c6748;
        _ReadWriteBarrier();
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        ((MonitorCommand*)pos1)->m_ticks = t;
        ms1.m_end.m_storage = pos1 + 16;
    }

    float diff = input->m_fScalar - this->m_pCollisionInput->m_fScalar * 0.5;
    float tol = (diff < DAT_01012060) ? 0.0f : diff;

    Aabb aabb;
    collA->m_pCollisionShape->getAabb(collA->m_kMotionTransform, tol, aabb);

    InplaceArray<BroadPhaseHandlePair, 128> pairs;
    this->m_pJobSemaphore->GetAabbHits(aabb, &pairs);

    int typeA = collA->m_pCollisionShape->m_type;
    const BroadPhaseHandlePair* p = pairs.m_data;

    hkMonitorStream& ms2 = hkMonitorStream::getInstance();
    char* pos2 = ms2.m_end.m_storage;
    if (pos2 < ms2.m_capacityMinus16.m_storage) {
        ((MonitorCommand*)pos2)->m_name = str_010c68dc;
        _ReadWriteBarrier();
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        ((MonitorCommand*)pos2)->m_ticks = t;
        ms2.m_end.m_storage = pos2 + 12;
    }

    int count = pairs.m_iElementCount;
    while (--count >= 0) {
        BroadPhaseHandle* handleB = p->m_kPointB;
        Collidable* collB = (Collidable*)((char*)handleB + handleB->m_iOwnerOffset);
        if (collA != collB) {
            if (this->m_pCollisionFilter->IsCollisionEnabled(collA, collB).val) {
                Shape* shapeB = collB->m_pCollisionShape;
                if (shapeB) {
                    unsigned char agentType = input->m_pCollisionDispatcher->m_agent2TypeMap[typeA][shapeB->m_type];
                    input->m_pCollisionDispatcher->m_entries[agentType].m_func(collA, collB, input, collector);
                    if (collector->m_earlyOutHit) {
                        break;
                    }
                }
            }
        }
        ++p;
    }

    hkMonitorStream& ms3 = hkMonitorStream::getInstance();
    char* pos3 = ms3.m_end.m_storage;
    if (pos3 < ms3.m_capacityMinus16.m_storage) {
        ((MonitorCommand*)pos3)->m_name = str_01076f38;
        _ReadWriteBarrier();
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        ((MonitorCommand*)pos3)->m_ticks = t;
        ms3.m_end.m_storage = pos3 + 12;
    }
}
}  // namespace fnv_00c96df0

struct S96_BoolResult {char value;};
extern const char str_010c6908[];
struct S96_TimerEntry {const char* name; unsigned tick; unsigned unk08;};
struct S96_Timer {int unk00; S96_TimerEntry* unk04; int unk08; S96_TimerEntry* unk0C;};
struct S96_Allocator {virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void Free(void*,int);};
struct S96_AllocatorHolder {int unk00,unk04,unk08,unk0C; S96_Allocator* unk10;};
struct S96_Collidable {int unk00,unk04,unk08,unk0C,unk10,unk14; short unk18; signed char unk1A;};
struct S96_Constraint {unsigned char unk00,unk01,unk02,unk03; int unk04,unk08,unk0C; S96_Collidable* unk10; S96_Collidable* unk14;};
struct S96_EntityArray {void** data; int size; int capacity;};
struct S96_Island { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; unsigned char unk24,unk25; short unk26; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; S96_EntityArray unk48; int unk54; int unk58; S96_Constraint** unk5C; int unk60;};
struct S96_IslandArray {S96_Island** data; int size; int capacity;};
struct S96_FilterCheck {virtual void slot0(); virtual S96_BoolResult Check(S96_Collidable*,S96_Collidable*);};
struct S96_Filter {int unk00,unk04; S96_FilterCheck unk08;};
struct S96_Operation {unsigned char unk00,unk01,unk02,unk03;};
void __cdecl _hkAgentNnMachine_UpdateShapeCollectionFilter(S96_Constraint*,void*,S96_Island*);
void __cdecl hkpWorldAgentUtil_removeAgentAndItsToiEvents(S96_Constraint*);
struct S96_RemovalList {S96_Constraint** data; int size; int capacity; S96_Constraint* local[32]; void clear(){size=0;} int GetLogicalSize() const {return size;} S96_Constraint*& back(){return data[size-1];} void popBack(){--size;}};
struct S96_WorldShell : hkpWorld {
 void hkpWorld_queueOperation(const S96_Operation&); void hkpWorld_updateCollisionFilterOnEntity(void*,int,int); void UpdatePhantom(void*,int); void FUN_00c91120(); void UpdateFields_00c91140();
 __forceinline void S96_attempt() {
  if(!m_iCriticalOperationsLockCount && !(*(char*)&m_bBlockExecutingPendingOperations)) {
   if(m_iPendingOperationCount) FUN_00c91120();
   if(m_iPendingOperationQueueCount==1 && m_iQueuedOperationCount) UpdateFields_00c91140();
  }
 }
 static __forceinline void S96_TimerBegin(const char* name) {
  S96_Timer* timer=(S96_Timer*)TlsGetValue(DAT_0126835c);
  if(timer->unk04<timer->unk0C) {
   S96_TimerEntry* entry=timer->unk04;
   entry->name=name;
   unsigned tick;
   __asm {
    rdtsc
    mov dword ptr[tick], eax
   }
   entry->tick=tick;
   timer->unk04=entry+1;
  }
 }
 static __forceinline void S96_TimerEnd() {
  S96_Timer* timer=(S96_Timer*)TlsGetValue(DAT_0126835c);
  if(timer->unk04<timer->unk0C) {
   S96_TimerEntry* entry=timer->unk04;
   entry->name=str_010c41f8;
   unsigned tick;
   __asm {
    rdtsc
    mov dword ptr[tick], eax
   }
   entry->tick=tick;
   timer->unk04=entry+1;
  }
 }
 __forceinline bool S96_enabled(S96_Constraint* c) {
  return ((S96_Filter*)m_pCollisionFilter)->unk08.Check(c->unk10,c->unk14).value && ((char*)m_pDispatcher)[0x1bb0+c->unk10->unk1A*10+c->unk14->unk1A];
 }
 void hkpWorld_updateCollisionFilterOnWorld(int mode,int update);
};
// @fnv 0x00c96ff0
// src: HAVOK_LIB 0x00c96ff0
void S96_WorldShell::hkpWorld_updateCollisionFilterOnWorld(int mode,int update) {
 if(m_iCriticalOperationsLockCount) {
  S96_Operation op;
  op.unk00=21;
  op.unk01=(unsigned char)mode;
  op.unk02=(unsigned char)update;
  hkpWorld_queueOperation(op);
  return;
 }
 (*(char*)&m_bBlockExecutingPendingOperations)=true;
 S96_TimerBegin(str_010c6908);
 if(mode==0) {
  for(int i=0;i<m_kActiveSimulationIslands.m_iElementCount;++i) {
   S96_EntityArray& entities=((S96_Island*)m_kActiveSimulationIslands.m_data[i])->unk48;
   for(int j=0;j<entities.size;++j) hkpWorld_updateCollisionFilterOnEntity(entities.data[j],0,update);
  }
  for(int i=0;i<m_kInactiveSimulationIslands.m_iElementCount;++i) {
   S96_EntityArray& entities=((S96_Island*)m_kInactiveSimulationIslands.m_data[i])->unk48;
   for(int j=0;j<entities.size;++j) hkpWorld_updateCollisionFilterOnEntity(entities.data[j],0,update);
  }
  } else {
  ++m_iCriticalOperationsLockCount;
  S96_IslandArray* arrays[2]={(S96_IslandArray*)&m_kActiveSimulationIslands,(S96_IslandArray*)&m_kInactiveSimulationIslands};
  for(int a=0;a<2;++a) {
   S96_RemovalList removed;
   removed.data=removed.local;
   removed.size=0;
   removed.capacity=0x80000020;
   for(int i=0;i<arrays[a]->size;++i) {
    S96_Island* island=arrays[a]->data[i];
    removed.clear();
    int j=0;
    while(j<island->unk60) {
     S96_Constraint* current=island->unk5C[j++];
     S96_Constraint* end=(j==island->unk60)?(S96_Constraint*)((char*)current+island->unk58):(S96_Constraint*)((char*)current+512);
     for(;current<end;current=(S96_Constraint*)((char*)current+current->unk03)) {
      if(!S96_enabled(current)) {
       S96_AllocatorHolder* holder=(S96_AllocatorHolder*)hkMemoryRouter_getInstance();
       if(removed.size==(removed.capacity&0x3fffffff)) ResizeAudioStream(holder->unk10,&removed,4);
       removed.data[removed.size++]=current;
       island->unk25=(island->unk25&~2)|1;
      } else if(update==1) _hkAgentNnMachine_UpdateShapeCollectionFilter(current,(void*)m_pCollisionInput,island);
     }
    }
    while(removed.GetLogicalSize()) {
     S96_Constraint* c=removed.back();
     removed.popBack();
     hkpWorldAgentUtil_removeAgentAndItsToiEvents(c);
    }
   }
   S96_AllocatorHolder* holder=(S96_AllocatorHolder*)hkMemoryRouter_getInstance();
   S96_Allocator* alloc=holder->unk10;
   removed.size=0;
   if((removed.capacity&0x80000000)==0) alloc->Free(removed.data,(removed.capacity&0x3fffffff)*4);
  }
  --m_iCriticalOperationsLockCount;
 }
 if(mode==0) {
  for(int i=0;i<m_kPhantoms.m_iElementCount;++i) UpdatePhantom(m_kPhantoms.m_data[i],update);
 }
 (*(char*)&m_bBlockExecutingPendingOperations)=false;
 S96_attempt();
 S96_TimerEnd();
}

extern double DAT_01011588;
extern const char str_010c699c[];
extern const char str_010c698c[];
extern const char str_010c697c[];
extern const char str_010c6970[];
extern const char str_010c6964[];
extern const char str_010c6938[];
extern const char str_010c692c[];
extern const char str_010c6920[];
extern const char str_01076f38[];

struct S97_Bool {
    char m_cBooleanValue;
    inline S97_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); }
    inline operator bool() const { return m_cBooleanValue != 0; }
};

template <class T> struct S97_PadSpu {
    T m_kStorage;
    __forceinline T val() const { return m_kStorage; }
    __forceinline T operator->() const { return m_kStorage; }
    __forceinline void operator=(const T& t) { m_kStorage = t; }
};



static __forceinline void S97_timerList(const char* name1, const char* name2)
{
    hkMonitorStream& mStream = hkMonitorStream::getInstance();
    if ((mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)) {
        hkMonitorStream::TimerBeginListCommand* h = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.m_end.m_storage);
        h->m_commandAndMonitor = name1;
        h->m_nameOfFirstSplit = name2;
        h->setTime();
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}
static __forceinline void S97_timer(const char* name)
{
    hkMonitorStream& mStream = hkMonitorStream::getInstance();
    if ((mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)) {
        hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.m_end.m_storage);
        h->m_commandAndMonitor = name;
        h->setTime();
        mStream.m_end.m_storage = (char*)(h + 1);
    }
}



struct S97_HeapAllocator { __forceinline hkMemoryAllocator& get(const void*) { return hkMemoryRouter::getInstance().heap(); } };
struct S97_TempAllocator { __forceinline hkMemoryAllocator& get(void*) { return hkMemoryRouter::getInstance().temp(); } };

template <class T>
static __forceinline void S97_ArrayBase_clear(hkArrayBase<T>& self);

template <class T>
static __forceinline void S97_ArrayBase__clearAndDeallocate(hkArrayBase<T>& self, hkMemoryAllocator& alloc);

template <class T>
static __forceinline void S97_ArrayBase_clear(hkArrayBase<T>& self)
{ self.m_iElementCount = 0; }

template <class T>
static __forceinline void S97_ArrayBase__clearAndDeallocate(hkArrayBase<T>& self, hkMemoryAllocator& alloc)
{
        S97_ArrayBase_clear(self);
        if ((self.m_iCapacityState & 0x80000000) == 0) {
            alloc._bufFree<T>(self.m_data, self.getCapacity());
        }
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }
template <typename T, typename A> struct S97_Array : public hkArrayBase<T> {
    __forceinline S97_Array() {}
    __forceinline S97_Array(T* buffer, int size, int capacity) : hkArrayBase<T>(buffer, size, capacity) {}
    __forceinline void ClearAndRelease() { hkArrayBase<T>::_clearAndDeallocate(A().get(this)); }
};
template <typename T, unsigned N> struct S97_InplaceArray : public S97_Array<T, S97_HeapAllocator> {
    __forceinline explicit S97_InplaceArray(int size = 0) : S97_Array<T, S97_HeapAllocator>(m_kStorage, size, N) {}
    T m_kStorage[N];
};

struct S97_Aabb;
struct S97_Shape {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void getAabb(const void* localToWorld, float tolerance, S97_Aabb& out) const;
    int unk04; int unk08; int m_type;
    __forceinline int getType() const { return m_type; }
};
struct S97_Collidable {
    const S97_Shape* m_pCollisionShape; unsigned int m_uiCollisionShapeKey; const void* m_pMotionState; const void* m_parent;
    __forceinline const S97_Shape* getShape() const { return m_pCollisionShape; }
    __forceinline const void* getTransform() const { return m_pMotionState; }
};
struct S97_CollisionInput;
typedef void (__cdecl* S97_GetClosestPointsFunc)(const S97_Collidable&, const S97_Collidable&, const S97_CollisionInput&, void*);
struct S97_AgentFuncs { S97_GetClosestPointsFunc m_pGetPenetrationsFunc; int f04; int f08; int f0C; int f10; };
struct S97_DispatcherHead {
    int unk000; int unk004; int unk008; int unk00C;
};
struct S97_Dispatcher {
    __forceinline S97_GetClosestPointsFunc getGetClosestPointsFunc(int typeA, int typeB) const
    {
        const unsigned char (*agent2Types)[32] = (const unsigned char (*)[32])((const char*)this + 0x1a0);
        const S97_AgentFuncs* agent2Func = (const S97_AgentFuncs*)((const char*)this + 0x9a8);
        int idx = agent2Types[typeA][typeB];
        return agent2Func[idx].m_pGetPenetrationsFunc;
    }
};
struct S97_CollisionInput {
    S97_PadSpu<S97_Dispatcher*> m_pCollisionDispatcher;
    int unk04;
    float m_fScalar;
    __forceinline float getTolerance() const { return m_fScalar; }
};
struct S97_CcFilter {
    virtual void v00();
    virtual S97_Bool IsCollisionEnabled(const S97_Collidable& a, const S97_Collidable& b) const;
};
struct S97_RefObject { virtual ~S97_RefObject(); unsigned short m_usMemSizeAndFlags; short m_sReferenceCount; };
struct S97_CollisionFilter : public S97_RefObject, public S97_CcFilter {};
struct __declspec(align(16)) S97_Aabb { float m_kMinimumCorner[4]; float m_kMaximumCorner[4]; };
struct S97_TypedHandle {
    int m_iOwnerObjectOffset; signed char m_type; signed char m_iOwnerOffset;
    __forceinline void* getOwner() const { return const_cast<char*>(reinterpret_cast<const char*>(this) + m_iOwnerOffset); }
};
struct S97_HandlePair { S97_TypedHandle* m_kPointA; S97_TypedHandle* m_kPointB; };
struct S97_BroadPhase {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40();
    virtual void FindOverlappingPairs(const S97_Aabb& aabb, hkArrayBase<S97_HandlePair>& pairsOut) const;
};
struct S97_TreeWorldManager {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual bool isUpToDate() const;
    int unk04; int unk08; const void* m_pRayQueryAabbTree; const void* m_pKdTree;
    __forceinline const void* getAabbTree() const { return m_pRayQueryAabbTree; }
    __forceinline const void* getKdTree() const { return m_pKdTree; }
};

void __cdecl Object_CollectAABBTreeHits(const void* tree, const S97_Aabb* aabb, void* callback, hkArrayBase<void*>* hits, void* mask, void* context);
__declspec(noinline) void __cdecl CallWithDefaults(const void* tree, const S97_Aabb& aabb, hkArrayBase<void*>& hits) {
    if (tree) Object_CollectAABBTreeHits(tree, &aabb, 0, &hits, 0, 0);
}
void __cdecl hkKdTreeAabbQueryUtils_queryAabbIterative(const void* tree, const S97_Aabb& aabb, S97_Array<unsigned long, S97_TempAllocator>& hits);

struct S97_World {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54;
    S97_BroadPhase* m_pJobSemaphore;
    S97_TreeWorldManager* m_pKdTreeManager;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74;
    S97_CollisionInput* m_pCollisionInput;
    S97_CollisionFilter* m_pCollisionFilter;
    inline const S97_CollisionInput* getCollisionInput() const { return m_pCollisionInput; }
    inline const S97_CollisionFilter* getCollisionFilter() const { return m_pCollisionFilter; }
    void hkpWorld_getClosestPoints(const S97_Collidable* collA, const S97_CollisionInput& input, void* collector) const;
};

// @fnv 0x00c97850
// src: EXE 0x00c97850
void S97_World::hkpWorld_getClosestPoints(const S97_Collidable* collA, const S97_CollisionInput& input, void* collector) const
{
    S97_Aabb aabb;
    collA->getShape()->getAabb(collA->getTransform(), input.getTolerance() - getCollisionInput()->getTolerance() * DAT_01011588, aabb);

    if (m_pKdTreeManager && m_pKdTreeManager->isUpToDate()) {
        S97_timerList(str_010c699c, str_010c698c);
        const void* tree = m_pKdTreeManager->getAabbTree();
        const void* kdTree = m_pKdTreeManager->getKdTree();
        if (tree) {
            S97_InplaceArray<void*, 128> hits;
            CallWithDefaults(tree, aabb, hits);
            S97_timer(str_010c697c);
            int typeA = collA->getShape()->getType();
            for (int i = 0; i < hits.GetLogicalSize(); i++) {
                const S97_Collidable* collB = (const S97_Collidable*)hits[i];
                if (collA == collB) continue;
                if (!getCollisionFilter()->IsCollisionEnabled(*collA, *collB)) continue;
                const S97_Shape* shapeB = collB->getShape();
                if (!shapeB) continue;
                int typeB = shapeB->getType();
                S97_GetClosestPointsFunc func = input.m_pCollisionDispatcher->getGetClosestPointsFunc(typeA, typeB);
                func(*collA, *collB, input, collector);
            }
            hits.ClearAndRelease();
        }
        if (kdTree) {
            S97_timer(str_010c6970);
            S97_Array<unsigned long, S97_TempAllocator> hits;
            hkKdTreeAabbQueryUtils_queryAabbIterative(kdTree, aabb, hits);
            S97_timer(str_010c6964);
            int typeA = collA->getShape()->getType();
            for (int i = 0; i < hits.GetLogicalSize(); i++) {
                const S97_Collidable* collB = (const S97_Collidable*)hits[i];
                if (collA == collB) continue;
                if (!getCollisionFilter()->IsCollisionEnabled(*collA, *collB)) continue;
                const S97_Shape* shapeB = collB->getShape();
                if (!shapeB) continue;
                int typeB = shapeB->getType();
                S97_GetClosestPointsFunc func = input.m_pCollisionDispatcher->getGetClosestPointsFunc(typeA, typeB);
                func(*collA, *collB, input, collector);
            }
            hits.ClearAndRelease();
        }
        S97_timer(str_01076f38);
    } else {
        S97_timerList(str_010c6938, str_010c692c);
        S97_InplaceArray<S97_HandlePair, 128> hits;
        m_pJobSemaphore->FindOverlappingPairs(aabb, hits);
        S97_HandlePair* p = hits.begin();
        int typeA = collA->getShape()->getType();
        S97_timer(str_010c6920);
        for (int i = hits.GetLogicalSize() - 1; i >= 0; p++, i--) {
            const S97_TypedHandle* tp = p->m_kPointB;
            const S97_Collidable* collB = static_cast<const S97_Collidable*>(tp->getOwner());
            if (collA == collB) continue;
            if (!getCollisionFilter()->IsCollisionEnabled(*collA, *collB)) continue;
            const S97_Shape* shapeB = collB->getShape();
            if (!shapeB) continue;
            int typeB = shapeB->getType();
            S97_GetClosestPointsFunc func = input.m_pCollisionDispatcher->getGetClosestPointsFunc(typeA, typeB);
            func(*collA, *collB, input, collector);
        }
        S97_timer(str_01076f38);
        hits.ClearAndRelease();
    }
    }

namespace fnv_00c91f70 {
#pragma intrinsic(__rdtsc)
#pragma intrinsic(_ReadWriteBarrier)
extern "C" unsigned __int64 __rdtsc();

extern "C" void _ReadWriteBarrier();

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long g_monitorTls;
extern const char g_rayBegin[];
extern const char g_rayEnd[];
struct RayTimerEntry { const char* volatile name; unsigned int ticks; unsigned int secondCounter; };
struct RayMonitor { void* unk00; RayTimerEntry* current; void* unk08; RayTimerEntry* end; };
inline void RecordRayTimer(const char* name) {
    RayMonitor* monitor=(RayMonitor*)TlsGetValue(g_monitorTls);
    RayTimerEntry* entry=monitor->current;
    if(entry < monitor->end) {
        entry->name=name;
        _ReadWriteBarrier();
        volatile unsigned int ticks=(unsigned int)__rdtsc();
        entry->ticks=ticks;
        monitor->current=entry+1;
    }
}
struct RayManager {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual bool IsEnabled(); virtual void slot5();
    virtual void CastRay(const void*,void*,void*);
};
struct RayCaster {
    virtual void Process();
    int unk04,unk08,unk0c;
    float m_vRayOrigins[4],m_direction[4],m_inverseDirection[4];
    void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    RayCaster() : m_pCollisionShape(0),m_uiCollisionShapeKey(0) {}
    void CastRay(void*,const void*,void*,int,void*);
};
struct RayWorld : hkpWorld { void hkpWorld_castRay(const void* input,void* output); };
// Records ray timer markers, then dispatches the ray cast to the RayManager if enabled or to a local RayCaster otherwise.
// @fnv 0x00c91f70
// src: HAVOK_LIB 0x00c91f70
void RayWorld::hkpWorld_castRay(const void* input,void* output) {
    RecordRayTimer(g_rayBegin);
    if(m_pKdTreeManager && ((RayManager*)m_pKdTreeManager)->IsEnabled()) {
        ((RayManager*)m_pKdTreeManager)->CastRay(input,m_pCollisionFilter,output);
    } else {
        __declspec(align(16)) RayCaster caster;
        caster.CastRay(m_pJobSemaphore,input,m_pCollisionFilter,0,output);
    }
    RecordRayTimer(g_rayEnd);
}
}  // namespace fnv_00c91f70

namespace fnv_00c92040 {
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);

struct S00c92040_Rec {
    const char* name;
    unsigned int tsc;
    unsigned int unk08;
};

struct S00c92040_Pool {
    void* unk00;
    S00c92040_Rec* cur;
    void* unk08;
    S00c92040_Rec* end;
};

struct S00c92040_Ifc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool v4();
    virtual void v5(int, int, int);
    virtual void v6();
    virtual void v7(int, int, int);
};

struct __declspec(align(16)) S00c92040_Arg {
    const char* p00;
    unsigned int u04;
    unsigned int u08;
    unsigned int u0C;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
    unsigned int u1C;
    unsigned int u20;
    unsigned int u24;
    unsigned int u28;
    unsigned int u2C;
    int f30;
    int f34;
    int f38;
    int f3C;

    void RecordAndDispatch(void* p58, int a, int p7c, int zero, int b);
};

struct S00c92040_Obj {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* p58;
    S00c92040_Ifc* p5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    int p7C;

    void hkpWorld_castRay_00c92040(int a, int b);
};

// @fnv 0x00c92040
// src: HAVOK_LIB 0x00c92040
void S00c92040_Obj::hkpWorld_castRay_00c92040(int a, int b)
{
    extern void* DAT_00fdf044;
    extern unsigned long DAT_0126835c;
    extern const char str_010c64a8[];
    extern const char str_010c41f8[];
    extern const char DAT_010c647c[];

    typedef S00c92040_Pool* (__stdcall* AllocFn)(unsigned long);
    AllocFn alloc = (AllocFn)DAT_00fdf044;

    S00c92040_Pool* pool = alloc(DAT_0126835c);
    S00c92040_Rec* rec = pool->cur;

    if (rec < pool->end) {
        rec->name = str_010c64a8;
        _ReadWriteBarrier();
        volatile unsigned int ts = (unsigned int)__rdtsc();
        rec->tsc = ts;
        rec++;
        pool->cur = rec;
    }

    if (p5C != 0 && p5C->v4()) {
        p5C->v7(a, p7C, b);
    } else {
        S00c92040_Arg arg;
        arg.p00 = DAT_010c647c;
        arg.f30 = 0;
        arg.f34 = 0;
        arg.RecordAndDispatch(p58, a, p7C, 0, b);
    }

    pool = alloc(DAT_0126835c);
    rec = pool->cur;

    if (rec < pool->end) {
        rec->name = str_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned int ts = (unsigned int)__rdtsc();
        rec->tsc = ts;
        rec++;
        pool->cur = rec;
    }
}
}  // namespace fnv_00c92040

namespace fnv_00c93c30 {
struct FnvBody;

struct FnvBodyArrayEntry {
    void* unk00;
    FnvBody* unk04;
};

struct FnvBodyArray {
    FnvBodyArrayEntry* m_data;
    int m_uiItemCount;
    int m_pRayCursor;
};

struct FnvBody {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    signed char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    signed char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
};

struct FnvAdjustedBody {
    signed char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
};

struct FnvActionTarget {
    void __thiscall activate_00c9c1d0();
};

struct FnvAllocator {
    virtual void* vf00();
    virtual void* vf04(int size);
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(void* data, int size);
};

struct FnvAudioManager {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    FnvAllocator* unk10;
};

struct FnvBroadPhase {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44(int flags, FnvBodyArray* bodies);
};

FnvAudioManager* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkString_memCpy(void* data, void* owner, int size);

struct FnvMsg {
    unsigned char unk00;
    void* unk04;
};

struct FnvWorld : WorldWithPending {
    void __thiscall hkpWorld_queueOperation(FnvMsg* msg);
    void __thiscall hkpWorld_activateRegion(int flags);
};

// When locked, queues a message via FUN_00c91160; otherwise queries bodies from the broad phase and calls FUN_00c9c1d0 on each whose adjusted byte 0x18 is 1.
// @fnv 0x00c93c30
// src: HAVOK_LIB 0x00c93c30
void __thiscall FnvWorld::hkpWorld_activateRegion(int flags) {
    if (m_iCriticalOperationsLockCount != 0) {
        FnvMsg msg;
        msg.unk00 = 0x20;

        FnvAudioManager* audio = hkMemoryRouter_getInstance();
        void* buffer = audio->unk10->vf04(0x20);
        msg.unk04 = buffer;
        hkString_memCpy(buffer, (void*)flags, 0x20);
        this->hkpWorld_queueOperation(&msg);
        return;
    }

    FnvBroadPhase* broadPhase = (FnvBroadPhase*)m_pJobSemaphore;
    FnvBodyArray bodies;
    bodies.m_data = 0;
    bodies.m_uiItemCount = 0;
    bodies.m_pRayCursor = 0x80000000;

    broadPhase->vf44(flags, &bodies);

    int index = 0;
    while (index < bodies.m_uiItemCount) {
        FnvBody* body = bodies.m_data[index].unk04;
        unsigned char* pAdjusted = (unsigned char*)body + body->unk05;
        if (pAdjusted[0x18] == 1) {
            FnvActionTarget* target = (FnvActionTarget*)(pAdjusted + (signed char)pAdjusted[0x10]);
            if (target != 0)
                target->activate_00c9c1d0();
        }
        ++index;
    }

    FnvAudioManager* audio = hkMemoryRouter_getInstance();
    FnvAllocator* alloc = audio->unk10;
    bodies.m_uiItemCount = 0;
    if ((bodies.m_pRayCursor & 0x80000000) == 0)
        alloc->vf10(bodies.m_data, (bodies.m_pRayCursor & 0x3FFFFFFF) * 8);
}
}  // namespace fnv_00c93c30

namespace std{ class type_info; } typedef float TR;
typedef float TF32; typedef double TD64; typedef signed char TC; typedef signed char TI8;
typedef signed short TI16; typedef signed int TI32; typedef unsigned char TU; typedef unsigned char TU8;
typedef unsigned short TU16; typedef unsigned int TU32; typedef unsigned long __w64 TU1; typedef signed long __w64 TL;
typedef void*Tvl; enum TR1{ KS=0,KF=1} ;
typedef unsigned __int64 TU64; typedef __int64 TI64; typedef long TST2; typedef unsigned __w64 TS4;
typedef TU16 TOI; typedef TR TT; __forceinline TL __cdecl TGBO(const void*base,const void*pntr)throw(){ return TL(pntr)-TL(base);
} template<typename TYPE>__forceinline TYPE*__cdecl TABO(TYPE*base,TL offset)throw(){ return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base)+offset); }
class TFLOF{ public:TFLOF()throw():vf1(0){ } int vf1;
} ; class TC1; struct TV;
typedef int TB32; class TB{ public:typedef char CompileTimeTrueType; typedef int CompileTimeFalseType;
inline TB()throw(){ } inline TB(bool b)throw(){ vb1=static_cast<char>(b);
} inline operator bool()const{ return vb1!=0; }
inline TB&operator=(bool e)throw(){ vb1=static_cast<char>(e); return*this; }
inline TB operator==(bool e)const throw(){ return static_cast<int>(vb1)==static_cast<int>(e); } inline TB operator!=(bool e)const throw(){
return static_cast<int>(vb1)!=static_cast<int>(e); } private:char vb1; }
; class TH{ public:inline operator float()const; private:TI16 vv;
} ; extern"C"{ extern const TR TUF8iTR[256];
} class TUF8{ public:enum{ MAX_VALUE=256}
; inline operator float()const; public:TU8 vv; }
; extern"C"{ extern const TR TUI8TR[256]; }
template<typename ENUM,typename STORAGE>class TE1{ public:TE1()throw(){ } TE1(ENUM e)throw(){
vs8=static_cast<STORAGE>(e); } operator ENUM()const{ return static_cast<ENUM>(vs8);
} void operator=(ENUM e)throw(){ vs8=static_cast<STORAGE>(e); }
TB operator==(ENUM e)const throw(){ return vs8==static_cast<STORAGE>(e); } TB operator!=(ENUM e)const throw(){
return vs8!=static_cast<STORAGE>(e); } private:STORAGE vs8; }
; template<typename BITS,typename STORAGE>class TF; template<typename TYPE>class TPS{ public:__forceinline TPS()throw(){
} __forceinline TPS(TYPE e)throw():vs8(e){ } __forceinline void operator=(TYPE e)throw(){
vs8=e; } __forceinline TYPE val()const throw(){ return vs8;
} __forceinline TYPE operator->()const throw(){ return vs8; }
__forceinline operator TYPE()const{ return val(); } private:TYPE vs8;
} ; struct TCOBAC; enum KMC{
KMCR,KMCB,KMCC5,KMCCS1,KMCD4,KMCE1,KMCS1,KMCG,KMCD3,KMCM2,KMCSD,KMCV1,KMCD1,KMCU5,KMCA4,KMCB1,KMCC3,KMCA2,KMCT,KMCDF,KMCD,KMCU,KMCBC,KMCS6,KMCA5,KMCS4,KMCS,KMCS5,KMCM4,KMCM1,KMCT1,KMCH,KMCA1,KMCA3,KMCBP,KMCC7,KMCD2,KMCM,KMCS2,KMCC4,KMCC1,KMCM5,KMCA,KMCD5,KMCC6,KMCE,KMCM6,KMCW,KMCRB,KMCP1,KMCS3,KMCC,KMCC2,KMCV,KMCI,KMCAU,KMCAC1,KMCAD,KMCAM,KMCAR,KMCAC2,KMCAR1,KMCAC,KMCBR,KMCBD,KMCCR,KMCCD,KMCCS,KMCAN,KMCAA,KMCAS,KMCU1,KMCU2,KMCU3,KMCU4,KMCPA,KMCM3} ; template<typename T>class TTLD{ public:__forceinline T getData()const throw(){
return(T)(TU1)TlsGetValue(vsI1); } unsigned long vsI1; }
; typedef std::type_info TCTI; struct TCTIH; class TCRIU;
template<typename T>struct TSOTOV{ enum{ val=sizeof(T)} ;
} ; template<>struct TSOTOV<void>{ enum{
val=1} ; } ;
class TMA{ public:struct SixUnsignedValueRecord{ static const TS4 INFINITE_SIZE=(TS4(0)-1); TS4 va3;
TS4 viU; TS4 vpIU; TS4 va4; TS4 vtA;
TS4 vlB; } ; virtual~TMA()throw();
virtual void*AllocateMemoryBlock(int numBytes)throw()=0; virtual void ReleaseBlock(void*p,int numBytes)throw()=0; virtual void vs0()throw(); virtual void ReturnMemory(void*p,int numBytes)throw();
virtual void vs11()throw(); virtual void vs21()throw(); virtual void vs31()throw(); virtual void vs41()throw();
virtual void vs51()throw(); virtual void vs61()throw(); virtual void vs71()throw(); virtual void vs81()throw();
template<typename TYPE>inline void _bufFree(void*p,int numElem)throw(){ const int SIZE_ELEM=TSOTOV<TYPE>::val; ReturnMemory(p,numElem*SIZE_ELEM); }
public:enum MemoryState{ MEMORY_STATE_OK,MEMORY_STATE_OUT_OF_MEMORY} ; }
; namespace TMU{ template<unsigned int NBYTES>struct IntegerTypeByByteSize; template<>struct IntegerTypeByByteSize<1>;
template<>struct IntegerTypeByByteSize<2>; template<>struct IntegerTypeByByteSize<4>; template<>struct IntegerTypeByByteSize<8>; template<unsigned int NBYTES>struct IntegerTypeByByteSize;
} namespace TMU{ } struct TSM{
public:static TSM&GetMonitorStream()throw(); void*allocateStack(int numBytes,const char*what)throw(); __forceinline void deallocateStack(void*p)throw(); __forceinline void deallocateStack(int numBytes)throw();
__forceinline int getFreeStackSize()throw(){ return int(TGBO(vn1,ve)); } protected:TPS<void*>vn1;
TPS<void*>vs7; TPS<void*>ve; } ;
__forceinline void*TSM::allocateStack(int numBytes,const char*what)throw(){ ; if(numBytes>getFreeStackSize()){ ;
} void*current=vn1; vn1=TABO(current,numBytes); return current;
} void TSM::deallocateStack(void*p)throw(){ ; vn1=p;
} void TSM::deallocateStack(int numBytes)throw(){ vn1=TABO(vn1.val(),-numBytes); ;
} class TO1; class TMR{ public:typedef TMA Allocator;
static TMR&__cdecl hkMemoryRouter_getInstance()throw(); inline TSM&stack()throw(){ return vs6; }
inline Allocator&temp()throw(){ return*vt1; } inline Allocator&heap()throw(){
return*vh; } protected:TSM vs6; Allocator*vt1;
Allocator*vh; Allocator*vd2; Allocator*vs5; Allocator*vg;
void*vuD; } ; template<typename TYPE>__forceinline void __cdecl TDC(TYPE*ptr,int numberOfObjects,int cl)throw(){
TMR::hkMemoryRouter_getInstance().heap().ReleaseBlock(static_cast<void*>(ptr),numberOfObjects*TSOTOV<TYPE>::val); } template<typename TYPE>__forceinline TYPE*__cdecl TAS1(int n,const char*what=0)throw(){ TMR&mem=TMR::hkMemoryRouter_getInstance();
return static_cast<TYPE*>(mem.stack().allocateStack((((n*TSOTOV<TYPE>::val)+((128)-1))&(~((128)-1))),what)); } template<typename TYPE>__forceinline void __cdecl TDS(TYPE*ptr)throw(){ TMR::hkMemoryRouter_getInstance().stack().deallocateStack(static_cast<void*>(ptr));
} extern const TC1 TBOC; class TBO{ public:__forceinline virtual~TBO()throw();
public:} ; extern const TC1 TROC; class TSC3;
class TCS2; class TVCR; class TRO:public TBO{ public:virtual~TRO()throw();
void FUN_00c90510()const throw(); enum LockMode{ LOCK_MODE_NONE,LOCK_MODE_AUTO,LOCK_MODE_MANUAL} ;
virtual void vs9()const throw(); virtual void vs10()const throw(); public:enum{ MASK_MEMSIZE=0x7fff}
; TU16 vmSAF; mutable TI16 vrC; public:}
; template<typename T>class TS3; extern struct TSIN*TSIL; struct TSIN;
class TO1; class TSW; class TS6; class TSP;
class TSB1; class TMT; struct TCHA; template<typename T,typename A>class TA2;
class TO1; typedef TO1 TO; class TE2; class TES;
typedef void(__cdecl*TERF)(const char*s,void*errorReportObject); namespace TCE2{ template<bool b>struct BooleanTrueSpecialization; template<>struct BooleanTrueSpecialization<true>;
template<bool b>struct TrueOnlyTrait; template<>struct TrueOnlyTrait<true>; } template<class TYPE>class TRP{
public:__forceinline TYPE*val()const throw(); __forceinline operator TYPE*()const; private:TYPE*vp4; }
; template<class TYPE>__forceinline TYPE*TRP<TYPE>::val()const throw(){ return vp4; }
struct TPNA; inline void*operator new(TS4,TPNA*p){ return p; }
template<bool N>struct TTB{ typedef TTB<N>type; enum{ result=N}
; } ; typedef TTB<true>TTIP;
typedef TTB<false>TTIC; template<typename T>TB::CompileTimeFalseType operator==(const T&,const TTIP&)throw(); template<typename T>struct TIPT:public TTB<(sizeof(*static_cast<T*>(0)==*static_cast<const TTIP*>(0))==sizeof(TB::CompileTimeTrueType))>{ }
; template<>struct TIPT<bool>:public TTIP{ } ;
; template<>struct TIPT<TB>:public TTIP{ } ;
; template<>struct TIPT<char>:public TTIP{ } ;
; template<>struct TIPT<TI8>:public TTIP{ } ;
; template<>struct TIPT<TU8>:public TTIP{ } ;
; template<>struct TIPT<TI16>:public TTIP{ } ;
; template<>struct TIPT<TU16>:public TTIP{ } ;
; template<>struct TIPT<TI32>:public TTIP{ } ;
; template<>struct TIPT<TU32>:public TTIP{ } ;
; template<>struct TIPT<TI64>:public TTIP{ } ;
; template<>struct TIPT<TU64>:public TTIP{ } ;
; template<>struct TIPT<TL>:public TTIP{ } ;
; template<>struct TIPT<TU1>:public TTIP{ } ;
; template<>struct TIPT<TUF8>:public TTIP{ } ;
; template<>struct TIPT<TH>:public TTIP{ } ;
; template<>struct TIPT<TR>:public TTIP{ } ;
; template<>struct TIPT<TD64>:public TTIP{ } ;
; template<>struct TIPT<TV>:public TTIP{ } ;
; template<typename T>struct TIPT<T*>:public TTIP{ } ;
template<typename T,unsigned int N>struct TIPT<T[N]>:public TIPT<T>{ } ; class TAU{
public:template<typename T>static __forceinline void construct(T*t,int n,TTIP)throw(); template<typename T>static __forceinline void construct(T*t,int n,TTIC)throw(); template<typename T>static __forceinline void constructWithCopy(T*t,int n,const T&tcopy,TTIP)throw(); template<typename T>static __forceinline void constructWithCopy(T*t,int n,const T&tcopy,TTIC)throw();
template<typename T>static __forceinline void destruct(T*t,int n,TTIP)throw(); template<typename T>static __forceinline void destruct(T*t,int n,TTIC)throw(); static void __cdecl hkArrayUtil__reserve(TMA&a,void*,int reqElem,int sizeElem)throw(); static void __cdecl ResizeAudioStream(TMA&a,void*array,int sizeElem)throw();
} ; template<typename T>__forceinline void TAU::construct(T*t,int n,TTIP)throw(){ }
template<typename T>__forceinline void TAU::construct(T*t,int n,TTIC)throw(){ for(int i=0;i<n;++i){ ::new(reinterpret_cast<TPNA*>(t+i))T; }
} template<typename T>__forceinline void TAU::constructWithCopy(T*t,int n,const T&tcopy,TTIP)throw(){ for(int i=0;i<n;++i){ t[i]=tcopy;
} } template<typename T>__forceinline void TAU::constructWithCopy(T*t,int n,const T&tcopy,TTIC)throw(){ for(int i=0;i<n;++i){
::new(reinterpret_cast<TPNA*>(t+i))T(tcopy); } } template<typename T>__forceinline void TAU::destruct(T*t,int n,TTIP)throw(){
} template<typename T>__forceinline void TAU::destruct(T*t,int n,TTIC)throw(){ for(int i=0;i<n;++i){ static_cast<T*>(t)[i].~T();
} } struct TCTA{ TMA&get(void*)throw(){
return TMR::hkMemoryRouter_getInstance().temp(); } } ;
struct TCHA{ TMA&get(const void*)throw(){ return TMR::hkMemoryRouter_getInstance().heap(); }
} ; struct TCDA; template<int OFFSET>struct TCSA;
template<typename T>class TAB{ friend class TAU; friend class TAS2; public:typedef TAB<T>ThisType;
__forceinline TAB()throw(); __forceinline TAB(T*buffer,int size,int capacity)throw(); protected:public:__forceinline~TAB()throw(); __forceinline T&operator[](int i)throw();
__forceinline const T&operator[](int i)const throw(); __forceinline int GetLogicalSize()const throw(); __forceinline int getCapacity()const throw(); __forceinline void clear()throw();
__forceinline void _clearAndDeallocate(TMA&alloc)throw(); __forceinline void _pushBack(TMA&alloc,const T&e)throw(); __forceinline void pushBackUnchecked(const T&e)throw(); __forceinline void hkArrayUtil__reserve(TMA&alloc,int n)throw();
__forceinline void _reserveExactly(TMA&alloc,int n)throw(); __forceinline T*expandByUnchecked(int n)throw(); typedef T*iterator; typedef const T*const_iterator;
__forceinline iterator begin()throw(); __forceinline const_iterator begin()const throw(); protected:public:enum{ CAPACITY_MASK=int(0x3FFFFFFF),FLAG_MASK=int(0xC0000000),DONT_DEALLOCATE_FLAG=int(0x80000000),FORCE_SIGNED=-1}
; protected:friend class TSC3; T*vd1; int vs4;
int vcAF; public:} ; template<typename T,typename Allocator=TCHA>class TA2:public TAB<T>{
public:typedef Allocator AllocatorType; friend class TAU; typedef TA2<T,TCTA>Temp; typedef TA2<T,TCDA>Debug;
typedef TA2<T,TCHA>Heap; __forceinline TA2()throw():TAB<T>(){ } __forceinline~TA2()throw();
explicit __forceinline TA2(int size)throw(); __forceinline TA2(int size,const T&fill)throw(); protected:__forceinline TA2(const TA2&a)throw(); public:__forceinline void ClearAndRelease()throw(){
TAB<T>::_clearAndDeallocate(AllocatorType().get(this)); } __forceinline void AddBack(const T&e)throw(){ TAB<T>::_pushBack(AllocatorType().get(this),e);
} __forceinline void reserve(int size)throw(){ TAB<T>::hkArrayUtil__reserve(AllocatorType().get(this),size); }
__forceinline void reserveExactly(int size)throw(){ TAB<T>::_reserveExactly(AllocatorType().get(this),size); } }
; template<typename T,unsigned N,typename Allocator=TCHA>class TIA:public TA2<T,Allocator>{ public:typedef TIA<T,N,Allocator>mytype; __forceinline TB wasReallocated()const throw();
public:T vs8[N]; public:} ; template<typename T,unsigned N>class TIAA16;
template<typename T>__forceinline T&TAB<T>::operator[](int i)throw(){ ; return vd1[i]; }
template<typename T>__forceinline const T&TAB<T>::operator[](int i)const throw(){ ; return vd1[i]; }
template<typename T>__forceinline int TAB<T>::GetLogicalSize()const throw(){ return vs4; } template<typename T>__forceinline int TAB<T>::getCapacity()const throw(){
return(vcAF&static_cast<int>(CAPACITY_MASK)); } template<typename T>__forceinline void TAB<T>::_reserveExactly(TMA&alloc,int n)throw(){ if(getCapacity()<n){
TAU::hkArrayUtil__reserve(alloc,this,n,sizeof(T)); } }
// src: HAVOK_LIB 0x00c908c0
 template<typename T>__forceinline void TAB<T>::hkArrayUtil__reserve(TMA&alloc,int n)throw(){
const int capacity=getCapacity(); if(capacity<n){ int cap2=2*capacity; int newSize=(n<cap2)?cap2:n;
TAU::hkArrayUtil__reserve(alloc,this,newSize,sizeof(T)); } } template<typename T>__forceinline void TAB<T>::clear()throw(){
TAU::destruct(vd1,vs4,typename TIPT<T>::type()); vs4=0; } template<typename T>__forceinline TAB<T>::TAB()throw():vd1(0),vs4(0),vcAF(DONT_DEALLOCATE_FLAG){
} template<typename T>__forceinline TAB<T>::~TAB()throw(){ ; ;
} template<typename T>__forceinline void TAB<T>::_clearAndDeallocate(TMA&alloc)throw(){ clear(); if((vcAF&DONT_DEALLOCATE_FLAG)==0){
alloc._bufFree<T>(vd1,getCapacity()); } vd1=0; vcAF=DONT_DEALLOCATE_FLAG;
} template<typename T>__forceinline void TAB<T>::_pushBack(TMA&alloc,const T&t)throw(){ if(vs4==getCapacity()){ ;
TAU::ResizeAudioStream(alloc,this,sizeof(T)); } TAU::constructWithCopy(vd1+vs4,1,t,typename TIPT<T>::type()); vs4++;
} template<typename T>__forceinline void TAB<T>::pushBackUnchecked(const T&t)throw(){ ; TAU::constructWithCopy(vd1+vs4,1,t,typename TIPT<T>::type());
vs4++; } template<typename T>__forceinline T*TAB<T>::expandByUnchecked(int n)throw(){ ;
int oldsize=vs4; vs4=oldsize+n; TAU::construct(vd1+oldsize,vs4-oldsize,typename TIPT<T>::type()); return vd1+oldsize;
} template<typename T>typename TAB<T>::iterator TAB<T>::begin()throw(){ return vd1; }
template<typename T>typename TAB<T>::const_iterator TAB<T>::begin()const throw(){ return vd1; } template<typename T,typename Allocator>__forceinline TA2<T,Allocator>::~TA2()throw(){
ClearAndRelease(); } template<typename T,unsigned N,typename Allocator>TB TIA<T,N,Allocator>::wasReallocated()const throw(){ return this->vd1!=vs8;
} namespace TSAU{ void __cdecl hkArrayUtil__reserve(void*,int numElem,int sizeElem)throw(); void __cdecl ResizeAudioStream(void*array,int sizeElem)throw();
} template<typename T>class TSA1{ friend void __cdecl TSAU::hkArrayUtil__reserve(void*,int numElem,int sizeElem)throw(); friend void __cdecl TSAU::ResizeAudioStream(void*array,int sizeElem)throw();
public:__forceinline int GetLogicalSize()const throw(); __forceinline int getCapacity()const throw(); __forceinline void AddBack(const T&e)throw(); typedef T*iterator;
typedef const T*const_iterator; __forceinline iterator begin()throw(); __forceinline const_iterator begin()const throw(); __forceinline void reserve(int n)throw();
void ClearAndRelease()throw(); public:enum{ CAPACITY_MASK=TU16(0x3fff),FLAG_MASK=TU16(0xC000),DONT_DEALLOCATE_FLAG=TU16(0x8000),LOCKED_FLAG=TU16(0x4000),FORCE_SIGNED=-1} ;
protected:friend class TSC3; void releaseMemory()throw(); T*vd1; TU16 vs4;
TU16 vcAF; public:} ; template<typename T>__forceinline void TSA1<T>::ClearAndRelease()throw(){
releaseMemory(); vd1=0; vs4=0; vcAF=TU16(DONT_DEALLOCATE_FLAG|(vcAF&LOCKED_FLAG));
} template<typename T>__forceinline int TSA1<T>::GetLogicalSize()const throw(){ return vs4; }
template<typename T>__forceinline int TSA1<T>::getCapacity()const throw(){ return(vcAF&static_cast<int>(CAPACITY_MASK)); } template<typename T>__forceinline void TSA1<T>::releaseMemory()throw(){
if((vcAF&DONT_DEALLOCATE_FLAG)==0){ TDC(vd1,getCapacity(),KMCA5); } }
template<typename T>__forceinline void TSA1<T>::AddBack(const T&t)throw(){ if(vs4==getCapacity()){ TSAU::ResizeAudioStream(this,sizeof(T)); }
vd1[vs4++]=t; } template<typename T>typename TSA1<T>::iterator TSA1<T>::begin()throw(){ return vd1;
} template<typename T>typename TSA1<T>::const_iterator TSA1<T>::begin()const throw(){ return vd1; }
template<typename T>__forceinline void TSA1<T>::reserve(int n)throw(){ const int capacity=getCapacity(); if(capacity<n){ int cap2=2*capacity;
int newSize=(n<cap2)?cap2:n; TSAU::hkArrayUtil__reserve(this,newSize,sizeof(T)); } }
template<typename KEY>struct TMO; template<>struct TMO<int>; template<typename KEY,typename VAL=KEY,typename OPS=TMO<KEY> >class TMB; template<typename KEY,typename VAL=KEY,typename OPS=TMO<KEY>,typename Allocator=TCHA>class TM;
template<int N>struct TPMS; template<>struct TPMS<8>; template<typename K,typename V,typename Allocator=TCHA>class TPM; class TVCR;
class TRV; typedef float TR; typedef LocalM128 TQR; class TV4;
typedef const TV4&TV4P; union TQRU; class TSR{ public:operator TR()const;
private:TQR vr; } ; typedef const TSR&TSRP;
class TV4C; typedef const TV4C&TV4CP; class TV4C; typedef const TV4C&TV4CP;
class TV4C; extern const TQR TQRH; extern const TQR TQR3333; namespace TM2{
} namespace std{ } extern"C"{
} namespace TM2{ } extern const TQR TQR0000;
extern const TQR TQR1111; extern const TQR TQR1000; extern const TQR TQR0100; extern const TQR TQR0010;
extern const TQR TQR0001; extern const TQR TQR3333; extern const TQR TQRH; extern const TQR TQRMH;
extern const TQR TQRM; extern const TQR TQRE; class TV4; class TQ;
class TM3; class TR2; class TT1; class TQT;
class TV4{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ; __forceinline TV4()throw(){
} __forceinline TV4(TR x,TR y,TR z,TR w=0)throw(); __forceinline TV4(const TQR&q)throw(); __forceinline TV4(const TV4&v)throw();
private:TQR vq; public:operator TQR()const; } ;
class TQ{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ; public:TV4 vv1;
protected:} ; class TM3{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw();
; protected:TV4 vc0; TV4 vc1; TV4 vc2;
} ; extern"C"{ }
class __declspec(align(16))TR2:public TM3{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ; }
; class TT1{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ;
private:TR2 vr2; TV4 vt5; } ;
class TST1{ public:public:public:TV4 vcOM0; TV4 vcOM1; TQ vr0;
TQ vr11; TV4 vcOML; } ;
class TQT{ public:TB::CompileTimeTrueType operator==(const TTIP&)const throw(); ; enum IdentityInitializer{
IDENTITY,} ; enum ZeroInitializer{ ZERO,}
; public:TV4 vt5; TQ vr2; TV4 vs;
} ; class TM4; static const TQR g_vNearOneVector={
1.0f-1e-5f,1.0f-1e-5f,1.0f-1e-5f,1.0f-1e-5f} ; static const TQR g_vNearNegativeOneVector={ -(1.0f-1e-3f),-(1.0f-1e-3f),-(1.0f-1e-3f),-(1.0f-1e-3f)}
; class TS6{ public:enum ReplaceType{ REPLACE_ONE,REPLACE_ALL}
; private:} ; class TSP;
class TSB1; class TSP{ public:enum StringFlags{ OWNED_FLAG=0x1,}
; inline operator const char*()const; private:const char*vsAF1; }
; class TCE; class TC1; class TCA2;
extern const TC1 TCMC; class TypeMetadataClass; class TC1; class TSW;
class TCA2; extern const TC1 TCEC; extern const TC1 TCEIC; class TCE;
extern const TC1 TRRAC; struct TRRA; extern const TC1 TRI32AC; struct TRI32A;
extern const TC1 TUAC; struct TUA; extern const TC1 TGAC; struct TGA;
extern const TC1 TMNTAC; struct TMNTA; extern const TC1 TLAC; struct TLA;
extern const TC1 TSAC; struct TSA; extern const TC1 TDAC; struct TDA;
extern const TC1 TATAC; struct TATA; extern const TC1 TDOTAC; struct TDOTA;
extern const TC1 TDAC1; struct TDA1; class TMTC{ public:enum AccessType{
KAI=0,KAR=1,KAR1=2,} ; enum ReadMode{ THIS_OBJECT_ONLY,RECURSIVE}
; protected:public:enum{ MARKED_RO=0xffffffe1,MARKED_RO_SELF_ONLY=0xffffffc1,UNMARKED=0xfffffff1} ;
TU32 vtI; TU16 vmC; protected:TU16 vmBS; public:static class TCS2*vcS1;
} ; typedef TU16 TCPI; class TCP;
enum TST{ KSI=0,KSS,KFST=KSS,KSC3,KST1,KSB,KSC,KSCV,KSC1,KSBT,KSL,KSM,KSCT1,KSCT,KSSHF,KSEM,KST,KSCM,KSMIS=KSCM+1,KSC2,KSPCV,KSME,KSCP,KSMS,KSCL,KSTC,KSMR,KSHF,KSSR,KSB1,KSP,KSPC,KSU,KSU1,KSU2,KSMI,KSA=-1} ; class TCD;
class TCV; enum TBS{ KSBS=512} ;
typedef __declspec(align(16))char TSB[KSBS]; class TA; struct TSRCI; struct TSRCO;
struct TSRBCI; struct TSRBCO; class TRHC; class TCB;
class TSC2; class TS5; typedef TU16 TVI; typedef TU32 TSK;
class TSKP; extern const TC1 TSC; class TCS1; class TS1:public TRO{
public:__forceinline void getAabb(const TT1&localToWorld,TR tolerance,TA&out)const throw(); virtual void vs111()const throw(); virtual void vs12()const throw(); virtual void vs13()const throw();
struct PhysicsShape{ bool vmA3R; bool viFOK; bool vhDMS;
} ; virtual void vs14()const throw(); protected:virtual void CalculateAabb(const TT1&localToWorld,TR tolerance,TA&out)const throw()=0;
virtual void vs15()const throw(); virtual void vs16()const throw(); virtual void vs17()const throw(); public:typedef void(__cdecl*GetSupportingVertexFunc)(const void*thisObj,TV4P direction,TCV&supportVertex);
typedef void(__cdecl*ConvertVertexIdsToVerticesFunc)(const void*thisObj,const TVI*ids,int numIds,class TCV*verticesOut); typedef int(__cdecl*WeldContactPointFunc)(const void*thisObj,TVI*featurePoints,TU8&numFeaturePoints,TV4&contactPointWs,const TT1*thisObjTransform,const TCS1*collidingShape,const TT1*collidingTransform,TV4&separatingNormalInOut); typedef void(__cdecl*GetCentreFunc)(const void*thisObj,TV4&centreOut); typedef int(__cdecl*GetNumCollisionSpheresFunc)(const void*thisObj);
typedef const TS5*(__cdecl*GetCollisionSpheresFunc)(const void*thisObj,TS5*sphereBuffer); typedef void(__cdecl*GetAabbFunc)(const void*thisObj,const TT1&localToWorld,TR tolerance,TA&out); typedef TB(__cdecl*CastRayFunc)(const void*thisObj,const TSRCI&input,TSRCO&output); typedef void(__cdecl*CastRayWithCollectorFunc)(const void*thisObj,const TSRCI&input,const TCB&cdBody,TRHC&collector);
typedef TV4C(__cdecl*CastRayBundleFunc)(const void*thisObj,const TSRBCI&input,TSRBCO&output,TV4CP mask); typedef const TS1*(__cdecl*GetChildShapeFunc)(const void*thisObj,TSK key,TSB&buffer); typedef TU32(__cdecl*GetCollisionFilterInfoFunc)(const void*thisObj,TSK key); struct ShapeCallbackDispatchTable{
TPS<GetSupportingVertexFunc>vgSVF; TPS<ConvertVertexIdsToVerticesFunc>vcVITV; TPS<WeldContactPointFunc>vwCPF; TPS<GetCentreFunc>vgCF;
TPS<GetNumCollisionSpheresFunc>vgNCSF; TPS<GetCollisionSpheresFunc>vgCSF1; TPS<GetAabbFunc>vgAF; TPS<CastRayFunc>vcR;
TPS<CastRayWithCollectorFunc>vcRWC; TPS<CastRayBundleFunc>vcRB; TPS<GetChildShapeFunc>vgCSF; TPS<GetCollisionFilterInfoFunc>vgCFIF;
} ; struct AlignedShapeCallbackTable{ __declspec(align(64))GetSupportingVertexFunc vgSVF;
ConvertVertexIdsToVerticesFunc vcVITV; WeldContactPointFunc vwCPF; GetCentreFunc vgCF; GetNumCollisionSpheresFunc vgNCSF;
GetCollisionSpheresFunc vgCSF1; GetAabbFunc vgAF; CastRayFunc vcR; CastRayWithCollectorFunc vcRWC;
CastRayBundleFunc vcRB; GetChildShapeFunc vgCSF; GetCollisionFilterInfoFunc vgCFIF; }
; typedef void(__cdecl*RegisterFunc)(ShapeCallbackDispatchTable&sf); public:public:TU1 vuD; public:TE1<::TST,TU32>vt6;
public:} ; __declspec(align(16))class TAS; void TS1::getAabb(const TT1&localToWorld,TR tolerance,TA&out)const throw(){
CalculateAabb(localToWorld,tolerance,out); } class TS1; class TMS1;
class TC2; class TCB{ public:friend class TC2; __forceinline const TT1&getTransform()const throw();
__forceinline const TS1*getShape()const throw(); public:__forceinline const TMS1*GetMotionState()const throw(); __forceinline void setMotionState(const TMS1*state)throw(); public:const TS1*vs2;
TSK vsK; const void*vm3; const TCB*vp1; }
; const TT1&TCB::getTransform()const throw(){ ; return*static_cast<const TT1*>(vm3);
} const TMS1*TCB::GetMotionState()const throw(){ return static_cast<const TMS1*>(vm3); }
void TCB::setMotionState(const TMS1*state)throw(){ vm3=state; } const TS1*TCB::getShape()const throw(){
return vs2; } class TBPH{ public:TU32 vi;
public:} ; enum TCQT{ KCQI=-1,KCQF=0,KCQK,KCQD,KCQDST,KCQM1,KCQC1,KCQB,KCQU,KCQC,KCQKR,KCQM}
; class TTBPH:public TBPH{ public:protected:enum{ OFFSET_INVALID=127}
; friend class TBPB; TI8 vt6; TI8 voO;
public:TI8 voQT; TU32 vcFI; } ;
class TA; struct TAU32; class TS1; class TT1;
class TC2:public TCB{ public:inline const TS1*getShape()const throw(); inline const TTBPH*getBroadPhaseHandle()const throw(); inline TTBPH*getBroadPhaseHandle()throw();
public:public:struct BoundingVolumeData{ __forceinline void invalidate()throw(){ vm2[0]=1; vm1[0]=0;
} public:TU32 vm2[3]; TU8 veM1[3]; TU8 veS;
TU32 vm1[3]; TU8 veM[3]; TU8 vp; TU16 vnCSA;
TU16 vcCSA; TAU32*vcSA; TSK*vcSK; }
; enum ForceCollideOntoPpuReasons{ FORCE_PPU_USER_REQUEST=1,FORCE_PPU_SHAPE_REQUEST=2,FORCE_PPU_MODIFIER_REQUEST=4,} ;
protected:TI8 voO; public:TU8 vfCOP; TU16 vsSOS; class TTBPH vbPH;
public:struct BoundingVolumeData vbVD; TR vaPD; } ;
class TA{ public:TA()throw(){ } __forceinline TA(const TV4&min,const TV4&max)throw();
public:TV4 vm2; TV4 vm1; } ;
__declspec(align(16))struct TAU32; __forceinline const TS1*TC2::getShape()const throw(){ return vs2; }
inline const TTBPH*TC2::getBroadPhaseHandle()const throw(){ return&vbPH; } inline TTBPH*TC2::getBroadPhaseHandle()throw(){
return&vbPH; } struct TANE; class TLC:public TC2{
public:public:struct CollisionKeyEntry{ TANE*vaE; TLC*vp2; }
; protected:TA2<struct CollisionKeyEntry>vcE; } ;
extern const TC1 TPVC; extern const TC1 TPC; struct TPV; class CollisionRelatedClass;
class TW; class TS1; class TP; class TRB;
extern const TC1 TWOC; namespace TWO1{ enum Result{ POSTPONED,DONE}
; } class TWO:public TRO{ public:enum MtChecks{
MULTI_THREADING_CHECKS_ENABLE,MULTI_THREADING_CHECKS_IGNORE} ; inline TC2*getCollidableRw()throw(); inline const TC2*getCollidable()const throw();
virtual void vs18()throw(); public:enum BroadPhaseType{ BROAD_PHASE_INVALID,BROAD_PHASE_ENTITY,BROAD_PHASE_PHANTOM,BROAD_PHASE_BORDER,BROAD_PHASE_MAX_ID} ;
protected:friend class TW; friend class TWOU; inline void setWorld(TW*world)throw(); inline virtual~TWO()throw();
public:virtual class TMS1*GetMotionState()throw()=0; protected:TW*vw; TU1 vuD; protected:class TLC vc3;
protected:class TMTC vmTC; TSP vn; TA2<class CollisionRelatedClass>vp5; private:class TRO*vaD;
void*vtD; public:} ; inline TC2*TWO::getCollidableRw()throw(){
return&vc3; } inline const TC2*TWO::getCollidable()const throw(){ return&vc3;
} void TWO::setWorld(TW*world)throw(){ vw=world; }
extern const TC1 TMC; class TM1{ public:enum ResponseType{ RESPONSE_INVALID,RESPONSE_SIMPLE_CONTACT,RESPONSE_REPORTING,RESPONSE_NONE,RESPONSE_MAX_ID}
; private:TE1<ResponseType,TI8>vrT; TR vf2; TR vr1;
public:} ; class TSR1; struct TSI{
enum DeactivationClass{ DEACTIVATION_CLASS_INVALID,DEACTIVATION_CLASS_OFF,DEACTIVATION_CLASS_LOW,DEACTIVATION_CLASS_MEDIUM,DEACTIVATION_CLASS_HIGH,DEACTIVATION_CLASS_AGGRESSIVE,DEACTIVATION_CLASSES_END} ; struct FloatAndHalfRecord{
float vlVTI; float vaVTI; float vsOVM; float vrSVT;
float vmDS[2]; TH vmRS[2]; } ;
__declspec(align(16))float vo; float vt; float vd; float vfT;
TV4 vgAPSS; TV4 vgAPS; TV4 viVF; TV4 viIVF;
float vdDT; float vtDD; float vdDFT; float vfTDD;
float vcRV; FloatAndHalfRecord vdI[DEACTIVATION_CLASSES_END]; float vdT; float viDT;
int vnS; int vnMS; float viNMS; float viNS;
TB vfCCOIS; TU8 vdNIFSF[2]; TU8 vdIC; float vmCVS;
} ; struct T1dMSI; struct T3dAMSI;
struct TVCA; class TJS; class TVA; class TSDA;
class TSDR; class TCI2; class TSR1; struct TSET;
struct TILBE; struct TILBH; class TCI2; extern"C"{
} struct TCI1{ int vmSOS; int vsOS;
int vnSR; int vnSET; inline void clear()throw(){ vmSOS=0;
vsOS=0; vnSR=0; vnSET=0; }
} ; class TCQI1; class TCQO;
class TCO; class TCI2; extern const TC1 TCDC; extern const TC1 TCIC;
typedef void VoidTypeAlias; class TCD1; class TCD1; class TCD1;
class EntityBatchAccess; class TRB; class TCO; class FUN_00d07830;
class TCL; class TW; extern const TC1 TCIC1; typedef void VoidTypeAlias;
class TCI2; __declspec(align(16))struct TCI3; class TMS1{ public:inline TT1&getTransform()throw();
inline const TT1&getTransform()const throw(); protected:TT1 vt4; class TST1 vsT3; public:TV4 vdA;
TR voR; TR vlD; TR vaD1; TUF8 vmLV;
TUF8 vmAV; TU8 vdC; } ;
TT1&TMS1::getTransform()throw(){ return vt4; } const TT1&TMS1::getTransform()const throw(){
return vt4; } extern const TC1 TMC1; class TM5:public TRO{
public:enum MotionType{ MOTION_INVALID,MOTION_DYNAMIC,MOTION_SPHERE_INERTIA,MOTION_BOX_INERTIA,MOTION_KEYFRAMED,MOTION_FIXED,MOTION_THIN_BOX_INERTIA,MOTION_CHARACTER,MOTION_MAX_ID} ; public:virtual void vs19()throw();
virtual void vs20()throw(); virtual void vs211()const throw(); virtual void vs22()const throw(); virtual void vs23()throw();
virtual void vs24()throw(); virtual void vs25()const throw(); virtual void vs26()const throw(); virtual void vs27()throw();
inline TMS1*GetMotionState()throw(); inline const TMS1*GetMotionState()const throw(); virtual void vs28()throw(); virtual void vs29()throw();
virtual void vs30()throw(); inline const TT1&getTransform()const throw(); virtual void vs311()throw(); virtual void vs32()throw();
virtual void vs33()throw(); virtual void vs34()const throw(); virtual void vs35()throw(); virtual void vs36()throw();
virtual void vs37()throw(); virtual void vs38()throw(); virtual void vs39()throw(); virtual void vs40()throw();
public:virtual void vs411()throw(); inline void SynchronizeDeactivationCountersWithWorld(int worldFlag0,int worldFlag1,int worldDeactivationIntegrateCounter)throw(); public:enum{ NUM_INACTIVE_FRAMES_TO_DEACTIVATE=5}
; public:TE1<MotionType,TU8>vt6; TU8 vdIC; TU16 vdNIF[2];
class TMS1 vmS; TV4 viAMI; TV4 vlV; TV4 vaV;
TV4 vdRP[2]; TU32 vdRO[2]; class TMSM*vsM; TU16 vsQTI;
TH vgF; } ; class TRM:public TM5{
} ; TMS1*TM5::GetMotionState()throw(){ return&vmS;
} const TMS1*TM5::GetMotionState()const throw(){ return&vmS; }
const TT1&TM5::getTransform()const throw(){ return vmS.getTransform(); } void TM5::SynchronizeDeactivationCountersWithWorld(int worldFlag0,int worldFlag1,int worldDeactivationIntegrateCounter)throw(){
; ; if((((unsigned)worldDeactivationIntegrateCounter)%4)<(((unsigned)vdIC)%4)){ worldFlag0=(~worldFlag0)<<14;
} else{ worldFlag0<<=14; }
if(worldDeactivationIntegrateCounter<vdIC){ worldFlag1=(~worldFlag1)<<14; } else{
worldFlag1<<=14; } vdNIF[0]=TU16((vdNIF[0]&0x3fff)|worldFlag0); vdNIF[1]=TU16((vdNIF[1]&0x3fff)|worldFlag1);
} extern const TC1 TKRMC; class TKRM:public TM5{ public:virtual~TKRM()throw();
virtual void vs19()throw(); virtual void vs20()throw(); virtual void vs42()const throw(); virtual void vs23()throw();
virtual void vs22()const throw(); virtual void vs24()throw(); virtual void vs43()const throw(); virtual void vs26()const throw();
virtual void vs34()const throw(); virtual void vs35()throw(); virtual void vs36()throw(); virtual void vs37()throw();
virtual void vs38()throw(); virtual void vs39()throw(); virtual void vs40()throw(); protected:public:public:virtual void vs44()throw();
virtual void vs45()throw(); public:} ; class TMSM:public TKRM{
public:private:} ; class TEL; class TEAL;
class TCL1; class TM5; class FUN_00d07830; class TW;
class TCI2; class TA1; class TDCM; class TSCCU1;
class TLF; class TBB; class TdBB; extern const TC1 TEC;
// Batch-only operations on the shared entity layout.
class EntityBatchAccess : public ::hkpEntity {
public:
    void UpdateBoundingVolume(const TW* world, const TS1* shape) throw();
    __forceinline TM5* getMotion() throw() { return (TM5*)&m_pMotionState; }
    __forceinline TB isFixed() const throw() {
        return ((const TM5*)&m_pMotionState)->vt6 == TM5::MOTION_FIXED;
    }
    __forceinline TMS1* GetMotionState() throw() {
        return (*(TMS1* (__thiscall**)(EntityBatchAccess*))(*(char**)this + 0x10))(this);
    }
    __forceinline const TC2* getCollidable() const throw() { return (const TC2*)&m_kCollidable; }
    __forceinline TC2* getCollidableRw() throw() { return (TC2*)&m_kCollidable; }
    __forceinline void setWorld(TW* world) throw() { m_pOwningWorld = world; }
};
class TSI1{ public:public:__declspec(align(16))TPS<TT>vsT2; TPS<TT>veT;
TPS<TR>vdT; TPS<TR>viDT; } ;
class TS; typedef TS TSBW; class TW; class TSI1;
class FUN_00d07830; class EntityBatchAccess; class TB; struct TTD;
// A unit-local view: AddEntities reads the stream through hkThreadLocalData (OptMonitorStream__DAT_0126835c),
// while the rest of the unit uses TlsGetValue, so this one needs its own getInstance body.
struct hkMonitorStream_tld : hkMonitorStream { static hkMonitorStream& getInstance()throw(); };
__forceinline hkMonitorStream& hkMonitorStream_tld::getInstance()throw(){ extern TTLD<hkMonitorStream*>OptMonitorStream__DAT_0126835c; return*OptMonitorStream__DAT_0126835c.getData(); }
// src: HAVOK_SRC (shape): the Havok forceinline accessors
__forceinline char*__cdecl hkMonitorStream::getEnd(){ return m_end.val(); }
__forceinline char*__cdecl hkMonitorStream::getCapacityMinus16(){ return m_capacityMinus16.val(); }
__forceinline hkBool __cdecl hkMonitorStream::memoryAvailable(){ return getEnd()<getCapacityMinus16(); }
__forceinline void __cdecl hkMonitorStream::setEnd(char*ptr){ m_end=ptr; }
 __forceinline void hkMonitorStream::TimerCommand::setTime(){ unsigned int ticks;
__asm {
rdtsc
mov dword ptr[ticks], eax
}
 m_time0=ticks; } class TTFH; class TWMAWD;
class TCB; struct TCI; class TCLF; class TC2;
class TCCF{ public:virtual~TCCF()throw(); virtual void vs47()const throw(); }
; struct TWRCI; extern const TC1 TRCFC; class TRCF{
public:virtual~TRCF()throw(); virtual void vs48()const throw(); } ;
struct TCI; class TBTS; class TSCF{ public:virtual void vs49()const throw();
virtual void vs50()const throw(); virtual void vs511()const throw(); virtual~TSCF()throw(); }
; struct TSRCI; class TSC1; class TS1;
extern const TC1 TRSCFC; class TRSCF{ public:virtual void vs52()const throw(); virtual~TRSCF()throw();
} ; extern const TC1 TCFC; class TBTS;
class EnumIntegerValue:public TRO,public TCCF,public TSCF,public TRSCF,public TRCF{ public:enum TFT{ KFU=0,KFN=1,KFG=2,KFL=3,KFC1=4,KFP=5,KFC=6,} ;
public:virtual void vs47()const throw(); virtual void vs53()const throw(); virtual void vs50()const throw(); virtual void vs511()const throw();
virtual void vs54()const throw(); virtual void vs48()const throw(); public:TU32 unusedBefore0; TU32 unusedBefore1;
TE1<TFT,TU32>vt6; TU32 unusedAfter0; TU32 unusedAfter1; TU32 unusedAfter2;
public:} ; extern const TC1 TCFLC; class TCFL;
extern const class TC1 TWCC; class TWC:public TRO{ public:enum SolverType{ SOLVER_TYPE_INVALID,SOLVER_TYPE_2ITERS_SOFT,SOLVER_TYPE_2ITERS_MEDIUM,SOLVER_TYPE_2ITERS_HARD,SOLVER_TYPE_4ITERS_SOFT,SOLVER_TYPE_4ITERS_MEDIUM,SOLVER_TYPE_4ITERS_HARD,SOLVER_TYPE_8ITERS_SOFT,SOLVER_TYPE_8ITERS_MEDIUM,SOLVER_TYPE_8ITERS_HARD,SOLVER_TYPE_MAX_ID}
; enum SimulationType{ SIMULATION_TYPE_INVALID,SIMULATION_TYPE_DISCRETE,SIMULATION_TYPE_CONTINUOUS,SIMULATION_TYPE_MULTITHREADED,} ;
enum ContactPointGeneration{ CONTACT_POINT_ACCEPT_ALWAYS,CONTACT_POINT_REJECT_DUBIOUS,CONTACT_POINT_REJECT_MANY,} ; enum BroadPhaseBorderBehaviour{
BROADPHASE_BORDER_ASSERT,BROADPHASE_BORDER_FIX_ENTITY,BROADPHASE_BORDER_REMOVE_ENTITY,BROADPHASE_BORDER_DO_NOTHING,} ; public:TV4 vg1; TI32 vbPQS;
TR vcRV; TE1<BroadPhaseBorderBehaviour,TI8>vbPBB; TB vmPASBPBC; class TA vbPWA;
TB vuKT; TB vuMT; enum TreeUpdateType{ REBUILD_ACTIVE,REBUILD_ALL,}
; TE1<TreeUpdateType,TI8>vtUT; TB vaUKT; TR vcT;
TRP<class EnumIntegerValue>vcF; TRP<class TCLF>vcLF; TR veMLV; int vsOTEQ;
TR veMPDT; TRP<class TWMAWD>vmWD; TI32 vbPNM; TE1<ContactPointGeneration,TI8>vcPG;
TB vaTSCC; TR vsT1; TR vsD; TI32 vsI3;
TI32 vsM1; TR vmCV; TB vfCCOIS; TR vsCTCET1;
TR vsCTCET; TB veTWR; TB veDW; TR viLCEOD;
TI32 viLCMI; TU8 vdNIFSF0; TU8 vdNIFSF1; TU8 vdIC;
TB vsAORBTC; TR vdRD; TR vtCRRN; int vmSPCT;
TB vpTM; int vmEPTCT; int vmNTCPS; TR vnTTAPST;
TR vnTTAPT; TR vnTTAPTH; TR vnTTAPTF; TB veD;
TE1<SimulationType,TI8>vsT; TB veSI; TU32 vmDIS; TB vpAIST;
TB vaIOIWCIASJ; TR vfMPS; TB vfCC; virtual~TWC()throw();
} ; class EnumIntegerValue; class TCLF;
class TCD; class TC2; struct TCI; struct TPCI;
class TCL1; class TTBPD; struct TWRCI; struct TWRCO;
struct TLCI; class TRHC; class TCPC; class TCBPC;
class TBP; class TBPH; class TA; class TWO;
class EntityBatchAccess; class TEL; class TRB; class TP;
class TPL; class TPBPL; class TEEBPL; class TBPBL;
class TA1; class TAL; class TCI2; class TCD1;
class TCL; class TPS1; class FUN_00d07830; class TCMF;
struct TMTS; class TWPSL; class TWPIL; class TWPCL;
class TWDL; class TIAL; class TCILBL; class TIPIL;
class TIPCL; class TSI1; class TWPBF; class TS2;
class TWOQ; struct TDIOPOQ; class TWMM; class TWMAWD;
class TBO1; class TJQ; class TJTP; class TdW;
struct TWRCC; struct TWLCC; struct TWGCPC; namespace TWO1{
struct TypeTag; class TypeTagRelatedClass; } struct TOP;
extern"C"enum TUCFOWM{ KUFOWFC,KUFOWDEECO,} ; enum TUCFOEM{
KUFOEFC,KUFOEDEECO} ; enum TEA{ KEADNA,KEADA}
; enum TUCFM{ KUCFISC,KUCFPSC} ;
struct TWDSI{ TSI1 vsI4; TSI vsI2; }
; struct TMC2; enum TSR2{ KSRS,KSRMFBI,KSRMFDC,KSRMFDTS,}
; class TW:public TRO{ public:void hkpWorld_addEntityBatch(EntityBatchAccess*const*entityBatch,int numEntities,TEA initialActivationState=KEADA)throw(); enum ReintegrationRecollideMode{
RR_MODE_REINTEGRATE=1,RR_MODE_RECOLLIDE_BROADPHASE=2,RR_MODE_RECOLLIDE_NARROWPHASE=4,RR_MODE_ALL=7} ; struct ReintegrationCollisionRequest{ int vmRBS;
int vsRBS; FUN_00d07830*vlSI; } ;
enum MtAccessChecking{ MT_ACCESS_CHECKING_ENABLED=0,MT_ACCESS_CHECKING_DISABLED} ; inline const EnumIntegerValue*getCollisionFilter()const throw();
enum CachedAabbUpdate{ SHIFT_BROADPHASE_UPDATE_ENTITY_AABBS,SHIFT_BROADPHASE_IGNORE_ENTITY_AABBS} ; inline const TA2<FUN_00d07830*>&getActiveSimulationIslands()const throw();
public:__forceinline void lockCriticalOperations()throw(); __forceinline void unlockCriticalOperations()throw(); __forceinline int areCriticalOperationsLocked()const throw(); __forceinline void unlockAndAttemptToExecutePendingOperations()throw();
__forceinline void attemptToExecutePendingOperations(bool executeBodyOperations=true)throw(); void hkpWorld_queueOperation(const TWO1::TypeTag&operation)throw(); private:void FUN_00c91120()throw(); void UpdateFields_00c91140()throw();
public:public:TS2*vs3; TV4 vg1; FUN_00d07830*vfI; TRB*vfRB;
TA2<FUN_00d07830*>vaSI; TA2<FUN_00d07830*>viSI; TA2<FUN_00d07830*>vdSI; TWMM*vmM;
TRP<TWMAWD>vmWD; TB vaOROOSM; TBP*vbP; class TTWM*vkTM;
TB vaUT; TTBPD*vbPD; TPBPL*vpBPL; TEEBPL*veEBPL;
TBPBL*vbPBL; TMTS*vmSJD; TPCI*vcI; EnumIntegerValue*vcF;
TCD*vcD1; TCLF*vcLF; TWOQ*vpO; int vpOC;
int vpBOC; int vcOLC; int vcOLCFP; TB vbEPO;
TB vcOA; TDIOPOQ*vpOQ; int vpOQC; mutable class TMTC vmTC;
TB vpAIST; TB vaIOIWCIASJ; TU32 vmDIS; class TCS2*vmCCS;
int viL; class TCS2*viDLCS; class TCS2*vpML; TB vwSI;
TR vsCTCET1; TR vsCTCET; TB veTWR; TB vwD;
TB vsAORBTC; TR vdRD; TR vtCRRN; int vmSPCT;
TB vpTM; int vmEPTCT; int vmNTCPS; TE1<TWC::SimulationType,TI32>vsT;
TR vnTTAPST; TR vnTTAPT; TR vnTTAPTH; TR vnTTAPTF;
static TB vfMS; class TBHolder{ public:public:TB voFMSV; }
; public:TU32 vlEU; TU32 vlIU; public:TU32 vlCU;
friend class TWOU; friend class TWCU; friend class TS2; friend class THS;
friend class TCS; friend class TMTS1; friend class TSCCM; TA2<TP*>vp3;
TA2<TAL*>vaL; TA2<TEL*>veL; TA2<TPL*>vpL; TA2<TCL*>vcL;
TA2<TWDL*>vwDL; TA2<TIAL*>viAL; TA2<TWPSL*>vwPSL; TA2<TWPIL*>vwPIL;
TA2<TWPCL*>vwPCL; TA2<TIPIL*>viPIL; TA2<TIPCL*>viPCL; TA2<TCL1*>vcL1;
TA2<TCILBL*>vcILBL; TVCA*vvCA; class TBPB*vbPB; class TCCU*vcCU;
class TdW*vdW; public:struct TWDSI vdSI1; TV4 vbPE[2]; int vbPNM;
int vsOTEQ; TI32 vbPQS; TI32 vbPUS; TE1<TWC::ContactPointGeneration,TI8>vcPG;
} ; const TA2<FUN_00d07830*>&TW::getActiveSimulationIslands()const throw(){ return vaSI;
} inline const EnumIntegerValue*TW::getCollisionFilter()const throw(){ ; return vcF;
} void TW::lockCriticalOperations()throw(){ ; vcOLC++;
; } void TW::unlockCriticalOperations()throw(){ ;
vcOLC--; ; } int TW::areCriticalOperationsLocked()const throw(){
; ; return vcOLC; }
void TW::attemptToExecutePendingOperations(bool executeBodyOperations)throw(){ ; if(!vcOLC&&!vbEPO){ if(vpOC){
FUN_00c91120(); } if(vpOQC==1&&executeBodyOperations){ if(vpBOC){
UpdateFields_00c91140(); } } }
} void TW::unlockAndAttemptToExecutePendingOperations()throw(){ unlockCriticalOperations(); attemptToExecutePendingOperations();
} extern struct TCDU*g_checkDeterminismUtil; class TI; class TO1;
class TCS2; class TMT; struct TCDU; class TVA;
class TCO:public TRO{ public:public:virtual void vs55()throw(); virtual void vs56()throw(); virtual void vs57()throw();
virtual void vs58()throw(); public:TCI1 vcI1; } ;
class TCI2; class EntityBatchAccess; class TSI1; class TVA;
class FUN_00d07830; class TVA; class TVA; class TCQSI;
class TCQI1; struct TCSI; struct TBJTH; struct TBJT;
struct TBJTC; struct TSJTC; struct TBJTH; struct TSCBT;
struct TCSR; class TCSS; struct TPCI; class TCM2;
struct TPCO; struct TCQI; class TLC; class TCD;
class TCO; struct TCI; class TCB; class TCA;
struct TAE; typedef void TAD; struct TA3I; struct TA3PI;
namespace TA3{ typedef int AgentType; enum{ MIN_TOTAL_SIZE=16,MAX_MEMORY_INCREASE=80,MAX_TOTAL_SIZE=128}
; enum StreamCommand{ STREAM_NULL=0,STREAM_END=1,STREAM_CALL=2,STREAM_CALL_FLIPPED=3,STREAM_CALL_WITH_TIM=4,STREAM_CALL_WITH_TIM_FLIPPED=5,STREAM_CALL_AGENT=6,TRANSFORM_FLAG=0x08,STREAM_CALL_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL,STREAM_CALL_FLIPPED_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL_FLIPPED,STREAM_CALL_WITH_TIM_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL_WITH_TIM,STREAM_CALL_WITH_TIM_FLIPPED_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL_WITH_TIM_FLIPPED,STREAM_CALL_AGENT_WITH_TRANSFORM=TRANSFORM_FLAG|STREAM_CALL_AGENT,} ;
typedef TAD*(__cdecl*CreateFunc)(const TA3I&input,TAE*entry,TAD*agentData); typedef void(__cdecl*DestroyFunc)(TAE*entry,TAD*agentData,TCM2*mgr,TCO&constraintOwner,TCD*dispatcher); typedef TAD*(__cdecl*ProcessFunc)(const TA3PI&input,TAE*entry,TAD*agentData,TV4*separatingNormalOut,TPCO&result); enum Symmetric{
IS_SYMMETRIC,IS_NOT_SYMMETRIC,IS_NOT_SYMMETRIC_AND_FLIPPED} ; typedef void(__cdecl*SepNormalFunc)(const TA3I&input,TAE*entry,TAD*agentData,TV4&separatingNormalOut); typedef TAD*(__cdecl*CleanupFunc)(TAE*entry,TAD*agentData,TCM2*mgr,TCO&constraintOwner);
typedef void(__cdecl*RemovePointFunc)(TAE*entry,TAD*agentData,TCPI idToRemove); typedef void(__cdecl*CommitPotentialFunc)(TAE*entry,TAD*agentData,TCPI iContactPointId); typedef void(__cdecl*CreateZombieFunc)(TAE*entry,TAD*agentData,TCPI idTobecomeZombie); typedef void(__cdecl*UpdateFilterFunc)(TAE*entry,TAD*agentData,const TCB&bodyA,const TCB&bodyB,const TCI&input,TCM2*mgr,TCO&constraintOwner);
typedef void(__cdecl*CalcStatisticsFunc)(TAE*entry,TAD*agentData,const TCI&input,TSC3*collector); typedef void(__cdecl*InvalidateTimFunc)(TAE*entry,TAD*agentData,const TCI&input); typedef void(__cdecl*WarpTimeFunc)(TAE*entry,TAD*agentData,TT oldTime,TT newTime,const TCI&input); }
typedef void TAD; struct TANE; struct TANS; class TC2;
struct TANE; struct TANS; struct TANT{ TU32 vbUILS;
TIA<TANS*,1>vs1; } ; class TTBPHP;
class TBPL{ public:virtual~TBPL()throw(); virtual void vs59()throw(); virtual void vs60()throw();
} ; class TUF; class TA1;
class EntityBatchAccess; class TCI2; class TSI1; class TBP;
class TW; class TCD; struct TWDSI; class TBPHP;
struct TCI; struct TPCO; extern const TC1 FUN_00d07830Class; class FUN_00d07830:public TCO{
public:__forceinline void*__cdecl operator new(TS4 nbytes){ ; TRO*b=static_cast<TRO*>(TMR::hkMemoryRouter_getInstance().heap().AllocateMemoryBlock(static_cast<int>(nbytes))); b->vmSAF=static_cast<TU16>(nbytes);
; return b; } __forceinline void*__cdecl operator new(TS4,void*p){
return p; } inline TB isFixed()const throw(); virtual void vs9()const throw();
protected:friend class TW; friend class TWOU; friend class TWCU; friend class TS2;
friend class TCS; friend class TAMU; FUN_00d07830(TW*world)throw(); ~FUN_00d07830()throw();
void hkpSimulationIsland_internalAddEntity(EntityBatchAccess*entity)throw(); virtual void vs55()throw(); virtual void vs56()throw(); virtual void vs57()throw();
protected:public:public:public:public:TW*vw; int vnC1; TOI vsI5; TOI vdLI;
TU vsCFC; bool vsCR:2; bool vsE:2; bool vaLCN:2;
bool vaIL:2; bool viIAIA:2; bool vaM:2; bool vtTIISM:2;
bool viIJ:2; protected:mutable TMTC vmTC; public:TR vtSLHFC; TR vtSLLFC;
TA2<TA1*>va1; TT vtOD; TIA<EntityBatchAccess*,1>ve1; TANT vaT;
; ; } ;
inline TB FUN_00d07830::isFixed()const throw(){ return vsI5==0xffff; } class THC;
class TLF; class TRBC; extern const TC1 TRBC1; class TRB:public EntityBatchAccess{
public:virtual~TRB()throw(); inline const TT1&getTransform()const throw(); virtual void vs611()const throw(); public:inline TM5*getRigidMotion()const throw();
public:protected:virtual TMS1*GetMotionState()throw(); public:} ; inline TM5*TRB::getRigidMotion()const throw(){
return (TM5*)&m_pMotionState; } inline const TT1&TRB::getTransform()const throw(){ return getRigidMotion()->getTransform();
} class TCI2; class EntityBatchAccess; struct TANT;
class TCS; class TWOU; class TRB; class TBO1;
class TA; class TRB; class TWO; class TCI2;
class TS1; class TCCF1; namespace TWO1{ enum Type{
OPERATION_ID_ANY=0,OPERATION_ID_INVALID=0,ENTITY_ADD,ENTITY_REMOVE,ENTITY_UPDATE_BROAD_PHASE,RIGIDBODY_SET_MOTION_TYPE,WORLD_OBJECT_SET_SHAPE,ENTITY_BATCH_ADD,ENTITY_BATCH_REMOVE,CONSTRAINT_ADD,CONSTRAINT_REMOVE,ACTION_ADD,ACTION_REMOVE,ISLAND_MERGE,PHANTOM_ADD,PHANTOM_REMOVE,PHANTOM_BATCH_ADD,PHANTOM_BATCH_REMOVE,PHANTOM_UPDATE_BROAD_PHASE,UPDATE_FILTER_ENTITY,UPDATE_FILTER_ENTITY_PAIR,UPDATE_FILTER_PHANTOM,UPDATE_FILTER_WORLD,UPDATE_MOVED_BODY_INFO,ENTITY_BATCH_REINTEGRATE_AND_RECOLLIDE,RIGIDBODY_SET_POSITION_AND_ROTATION,RIGIDBODY_SET_LINEAR_VELOCITY,RIGIDBODY_SET_ANGULAR_VELOCITY,RIGIDBODY_APPLY_LINEAR_IMPULSE,RIGIDBODY_APPLY_POINT_IMPULSE,RIGIDBODY_APPLY_ANGULAR_IMPULSE,WORLD_OBJECT_ADD_REFERENCE,WORLD_OBJECT_REMOVE_REFERENCE,ACTIVATE_REGION,ACTIVATE_ENTITY,DEACTIVATE_ENTITY,CONSTRAINT_FILTER_BROKEN_EVENT,USER_CALLBACK} ; class TypeTagRelatedClass; struct TypeTag{
TypeTag(Type type)throw():vt6(type){ } TE1<Type,TU8>vt6; private:TypeTag()throw();
} ; struct HandleNode; struct UpdateEntity;
struct RigidBodyMotionTypeChange; struct WorldObjectShapeChange; struct EntityBatchAddPayload:public TypeTag{ EntityBatchAddPayload()throw():TypeTag(ENTITY_BATCH_ADD){
} EntityBatchAccess**ve1; TOI vnE; TE1<TEA,TU8>va2;
} ; struct WorldOperationBeforeAddConstraint; struct AddConstraint;
struct WorldOperationBeforeAddActionCommand; struct AddActionCommand; struct WorldOperationAfterAddActionCommand; struct WorldOperation;
struct ForwardDeclaredCommandType; struct ForwardDeclaredWorldOperation8; struct LaterForwardDeclaredCommandType; struct ForwardDeclaredWorldOperation10;
struct OperationBeforePhantomBroadphaseUpdate; struct PhantomBroadphaseUpdate; struct OperationAfterPhantomBroadphaseUpdate; struct SecondPostPhantomBroadphaseOperation;
struct ForwardDeclaredStructAtPositionThirteen; struct ForwardDeclaredStructAtPositionFourteen; struct PhysicsCommand; struct ForwardDeclaredStructAtPositionSixteen;
struct RigidBodyPositionRotationUpdate; struct FourteenthForwardDeclaredType; struct FifteenthForwardDeclaredType; struct ForwardDeclaredStructInSequence;
struct ForwardDeclaredTypeAtPositionThirteen; struct TrailingForwardDeclaredStruct; struct AddReference; struct RemoveReference;
struct ForwardStructAtPositionTwentyFive; struct ForwardStructAtPositionTwentySix; struct IncompleteStructType; struct ForwardDeclaredType;
struct StructAfterForwardDeclaredType; struct OpaqueStructType; } struct TBOE;
class TWOQ; struct TDIOPOQ; class TW; struct TCBE;
struct TCRE; class TSI1; class TP; class TCILBL;
class TCILBLI; class TSCCM; class TCE1; class TCP;
class TCPP; class FUN_00d07830; class TCPE; class TC2;
struct TCI; class TCM2; class TSC3:public TRO{ public:enum MemoryType{
MEM_OBJECT,MEM_NORMAL,MEM_ALLOCATED,MEM_ARRAY,MEM_OTHER,MEM_LAST,} ; enum Flag{ EXCLUDE_OBJECT_MEMORY=0x1,}
; virtual void vs62()throw(); virtual void vs63()throw(); virtual void vs64()throw();
virtual void vs65()throw(); virtual void vs66()throw(); protected:public:const void*vcD; TVCR*vvR;
bool viUAM; } ; class TCMF;
struct TPCP; struct TPCD; class TCB; struct TPCI;
struct TPCO; class TC2; class TGC; class TCPM;
struct TSCCA; class TCPP; __declspec(align(16))class TCPPWEUD16; class TCPPS;
; class TCQI1; class TCQO; class TCP;
class TCPP; struct TSCCA; class TSCCDI; class TSCCDII;
extern TR KCLERV; extern TR KCEERV; extern"C"{ }
; class TCP; class TCM1; class TCPPS;
struct TCA1; typedef void(__cdecl*TCABJF)(class TCD1*vcD2,const TCQI1&in,TCQO&out); struct TBCA; struct TBA;
struct TSCCA; struct TBSCA; struct TSSCA; struct TSLTCA;
struct TSLTCA1; struct TSLRCA; struct TOPCA; struct TLCA;
struct TLSCA; struct TLLCA; struct T2dACA; struct TACA;
struct TALCA; struct TTLCA; struct TCLCA; struct TAFCA;
struct TAMCA; struct TRMCA; struct TLFCA; struct TLMCA;
struct TPCA; struct TMCA; struct TSCMCA; struct TMCMCA;
struct TCOMCMCA; struct TVSMCA; struct TMSMCA; struct TIMCA;
class TCM2; class TCP; class TCPP; class TV4;
class TDCM; class TDCIM; class TSCCAU; class TCP;
class TSR1; class TRB; class TSCCM; class TSCCD;
class TW; extern const TC1 TSCCMC; class TSCCM; class TRB;
class TV4; class TCP; class TSCCU; struct TPCP;
class TCS1; class TTS; class TGC; __declspec(align(16))class TGC16;
enum{ KMCP=256} ; struct TAE;
struct TPCD; class TCM2; struct TPCO; class TC2;
struct TCI; struct TPCO; class EntityBatchAccess; class TDCM;
enum TCPA{ KCPA=0,KCPR=1} ; struct TTPAE;
struct TMPAE; struct TSCCA; struct TCPAE; struct TTPAE;
struct TMPAE; struct TCPCE; struct TCPRE; struct TCPE1;
class TCL1; class TWCU{ public:static void __cdecl NotifyEntityAdded(TW*world,EntityBatchAccess*entity)throw(); }
; class EntityBatchAccess; class TECU{ public:static void __cdecl hkpEntityCallbackUtil_fireEntityAdded(EntityBatchAccess*entity)throw();
protected:public:protected:} ; class TCD; class EnumIntegerValue;
class TCLF; struct TCAC; class TSCQD; struct TCI{
public:TR getTolerance()const throw(){ return vt3; } public:TPS<TCD*>vd3;
TPS<TB32>vwCP; TPS<TR>vt3; TPS<const EnumIntegerValue*>vf; TPS<const TCLF*>vcLF;
mutable TPS<TB32>vcPA; struct AabbBoundsAndScale{ TV4 vbOL; TV4 vbOH;
TV4 vbS; } ; AabbBoundsAndScale va32I;
} ; struct TA1nS; struct TCQI;
struct TA1nS; struct TPCI:public TCI{ public:public:TSI1 vsI4; mutable TPS<TCQI*>vcQI;
mutable TA1nS*vsAS; void*vdI1; TB veDW; TB vaTSCC;
TCAC*vc4; } ; class TBP;
class TBPH; class TBPHP; class TA; class TPCC;
class TBPCC; typedef char TBPAC; class TBP:public TRO{ public:enum BroadPhaseType{
BROADPHASE_16BIT,BROADPHASE_32BIT} ; virtual void vs67()const throw(); virtual void vs68()throw();
virtual void vs69()throw(); virtual void UpdatePairs(const TAB<TBPH*>&addObjectList,const TAB<TA>&addAabbList,TA2<TBPHP>&newPairs)throw()=0; virtual void vs70()throw(); virtual void vs711()throw();
virtual void vs72()const throw(); virtual void vs73()throw(); virtual void vs74()throw(); virtual void vs75()throw();
virtual void vs76()throw(); virtual void vs77()const throw(); virtual void getAabb(const TBPH*object,TA&aabb)const throw()=0; virtual void vs78()const throw();
virtual void vs79()const throw(); virtual void vs80()const throw(); virtual void vs811()const throw(); virtual void vs82()throw();
virtual void vs83()throw(); virtual void vs84()const throw(); struct TCRI{ TV4 vf3;
int vnC; const TV4*vtB; int vtS; const TBPAC*vaCI;
} ; virtual void vs85()const throw(); virtual void vs86()const throw();
virtual void vs87()const throw(); virtual void vs88()const throw(); struct TCAI{ TV4 vf3;
TV4 vt2; TV4 vhE; const TBPAC*vaCI; }
; virtual void vs89()const throw(); virtual void vs90()throw(); typedef TBP*(__cdecl*createBroadPhaseFunc)(const TV4&worldMin,const TV4&worldMax,int numMarkers);
static createBroadPhaseFunc vdCF; protected:protected:mutable TMTC vmTC; class TCS2*vcS1; public:class ScopedBroadPhaseFactoryOverride{
public:public:createBroadPhaseFunc voCBF; private:} ; }
; class TBPH; class TBPHP{ public:TBPH*va;
TBPH*vb; } ; class TNBPL:public TRO,public TBPL{
public:virtual void vs59()throw(); virtual void vs60()throw(); } ;
class TTBPHP; class TBPHP; class TBPL; class TTBPD{
public:void hkpTypedBroadPhaseDispatcher_addPairs(TTBPHP*newPairs,int numNewPairs,const TCCF*filter)const throw(); protected:TBPL*vbPL[8][8]; TNBPL vnBPL; }
; template<typename T>class TLA1:public TA2<T>{ public:__forceinline TLA1(int capacity)throw(){ this->vd1=TAS1<T>(capacity);
this->vcAF=capacity|TA2<T>::DONT_DEALLOCATE_FLAG; vlM=this->vd1; } __forceinline TB wasReallocated()const throw(){
return vlM!=this->vd1; } __forceinline~TLA1()throw(){ if(!wasReallocated()){
TA2<T>::clear(); } TDS<T>(vlM); }
T*vlM; } ; namespace TSTU{
// @fnv 0x00c94bd0
void __cdecl hkSweptTransformUtil_setTimeInformation(TT startTime,TR invDeltaTime,TMS1&motionState)throw(); extern const TQR g_vSimdVectorConstant; }
// src: HAVOK_LIB 0x00c94bd0
 void TW::hkpWorld_addEntityBatch(EntityBatchAccess*const*entities,int count,TEA activation)throw(){
if(count==0)return; if(areCriticalOperationsLocked()){ TWO1::EntityBatchAddPayload op; op.ve1=const_cast<EntityBatchAccess**>(entities);
op.vnE=(TU16)count; op.va2=activation; hkpWorld_queueOperation(op); return;
} { hkMonitorStream&mStream=hkMonitorStream_tld::getInstance(); if(mStream.memoryAvailable()){
hkMonitorStream::TimerBeginListCommand*h=reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.getEnd()); h->m_commandAndMonitor="L""t""AddEntities"; h->m_nameOfFirstSplit="S""t""init"; h->setTime();
mStream.setEnd((char*)(h+1)); } } ;
lockCriticalOperations(); TA2<TBPH*,TCTA>handles; handles.reserveExactly(count); TA2<TA,TCTA>bounds;
bounds.reserveExactly(count); bool used=false; FUN_00d07830*island; if(vwSI){
island=new FUN_00d07830(this); island->vsCR=true; if(activation==KEADA){ island->vsI5=(TOI)getActiveSimulationIslands().GetLogicalSize();
island->viIAIA=true; island->vaM=true; } else{
island->vsI5=(TOI)viSI.GetLogicalSize(); island->viIAIA=false; island->vaM=false; }
} else{ island=getActiveSimulationIslands()[0]; island->ve1.reserve(island->ve1.GetLogicalSize()+count);
} { TR radius=(TR)(0.5*vcI->getTolerance()); for(int i=0;i<count;++i){
EntityBatchAccess*entity=entities[i]; entity->m_uiUniqueId=++vlEU; entity->addReference(); if(!entity->getCollidable()->GetMotionState())entity->getCollidableRw()->setMotionState(entity->GetMotionState());
TMS1*ms=static_cast<TRB*>(entity)->getRigidMotion()->GetMotionState(); TSTU::hkSweptTransformUtil_setTimeInformation(0,0,*ms); entity->getMotion()->vdNIF[0]=0; entity->getMotion()->vdNIF[1]=0;
entity->setWorld(this); const TU8*flags=vdSI1.vsI2.vdNIFSF; entity->getMotion()->SynchronizeDeactivationCountersWithWorld(flags[0],flags[1],vdSI1.vsI2.vdIC); if(entity->isFixed())vfI->hkpSimulationIsland_internalAddEntity(entity);
else{ used=true; island->hkpSimulationIsland_internalAddEntity(entity); }
TC2*c=entity->getCollidableRw(); const TS1*shape=c->getShape(); c->vbVD.invalidate(); if(shape){
TA*aabb=bounds.expandByUnchecked(1); c->getShape()->getAabb(c->getTransform(),radius,*aabb); handles.pushBackUnchecked(c->getBroadPhaseHandle()); entity->UpdateBoundingVolume(this,shape);
} } } if(vwSI){
if(used){ island->vsCFC=(TU)island->ve1[0]->m_uiUniqueId; TA2<FUN_00d07830*>&islands=activation==KEADA?const_cast<TA2<FUN_00d07830*>&>(getActiveSimulationIslands()):viSI; islands.AddBack(island);
} else delete island; } TLA1<TBPHP>pairs(vbPQS);
{ hkMonitorStream&mStream=hkMonitorStream_tld::getInstance(); if(mStream.memoryAvailable()){ hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
h->m_commandAndMonitor="S""t""Broadphase"; h->setTime(); mStream.setEnd((char*)(h+1)); }
} ; vbP->UpdatePairs(handles,bounds,pairs); {
hkMonitorStream&mStream=hkMonitorStream_tld::getInstance(); if(mStream.memoryAvailable()){ hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor="S""t""CreateAgents";
h->setTime(); mStream.setEnd((char*)(h+1)); } }
; vbPD->hkpTypedBroadPhaseDispatcher_addPairs(reinterpret_cast<TTBPHP*>(pairs.begin()),pairs.GetLogicalSize(),getCollisionFilter()); { hkMonitorStream&mStream=hkMonitorStream_tld::getInstance();
if(mStream.memoryAvailable()){ hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor="S""t""AddedCb"; h->setTime();
mStream.setEnd((char*)(h+1)); } } ;
for(int j=0;j<count;++j){ EntityBatchAccess*entity=entities[j]; TWCU::NotifyEntityAdded(this,entity); TECU::hkpEntityCallbackUtil_fireEntityAdded(entity);
} unlockAndAttemptToExecutePendingOperations(); { hkMonitorStream&mStream=hkMonitorStream_tld::getInstance();
if(mStream.memoryAvailable()){ hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd()); h->m_commandAndMonitor="l""t"""; h->setTime();
mStream.setEnd((char*)(h+1)); } } ;
}

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void __movsd(unsigned long*, unsigned long const*, size_t);
extern const char str_010c68c8[];
extern const char str_010c41f8[];
struct Sbp_TimerEntry { const char* name; unsigned int tick; unsigned int unk08; };
struct Sbp_Timer { void* unk00; Sbp_TimerEntry* unk04; void* unk08; Sbp_TimerEntry* unk0C; };
struct Sbp_Allocator {
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void* BufAlloc(int& bytes);
    virtual void BufFree(void* p, int bytes);
};
struct Sbp_Router { int unk00; int unk04; int unk08; int unk0C; Sbp_Allocator* unk10; };
static inline Sbp_Router* Sbp_router() { return (Sbp_Router*)hkMemoryRouter_getInstance(); }
void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(void*, void*, int);
struct Sbp_Pair { void* a; void* b; };
template <class T> struct Sbp_Array {
    T* data; int size; int capacity;
    void destroy() { ClearAndRelease(Sbp_router()->unk10); }
    void ClearAndRelease(Sbp_Allocator* heap) {
        size = 0;
        if ((capacity & 0x80000000) == 0) heap->BufFree(data, (capacity & 0x3fffffff) * sizeof(T));
    }
};
struct Sbp_Vec {
    LocalM128 q;
    void add4(const Sbp_Vec& a) { q = _mm_add_ps(q, a.q); }
};
struct Sbp_BroadPhase {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void ShiftBroadPhase(const Sbp_Vec& shift, Sbp_Vec& effective, Sbp_Array<Sbp_Pair>& pairs);
    virtual void GetOffsetLowHigh32Bit(Sbp_Vec& low, Sbp_Vec& high);
};
struct Sbp_CollisionInput {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    Sbp_Vec m_kAabbMin;
    Sbp_Vec m_kAabbMaximum;
};
struct Sbp_Dispatcher { void hkpTypedBroadPhaseDispatcher_addPairs(Sbp_Pair* pairs, int count, void* filter); };

struct Sbp_AabbPhantom : hkpPhantom {
    char padAabb[0xb0 - sizeof(hkpPhantom)];
    Sbp_Vec m_aabbMin;
    Sbp_Vec m_aabbMax;
};
struct Sbp_ShapePhantom : hkpPhantom {
    char padTransform[0xe0 - sizeof(hkpPhantom)];
    Sbp_Vec m_vTranslation;
};
struct Sbp_Border {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    hkpPhantom* m_kPhantoms[6];
    void shiftPhantoms(LocalM128& raw);
};
static inline hkpPhantom* Sbp_getPhantom(Sbp_Border* b, const int& i) { return b->m_kPhantoms[i]; }
__forceinline void Sbp_Border::shiftPhantoms(LocalM128& raw) { Sbp_Vec& effective=(Sbp_Vec&)raw;
    hkpPhantom* const* phantoms = m_kPhantoms;
    for (int i = 0; i < 6; i++) {
        hkpPhantom* phantom = phantoms[i];
        switch (phantom->getType()) {
        case 0:
            ((Sbp_AabbPhantom*)phantom)->m_aabbMin.add4(effective);
            ((Sbp_AabbPhantom*)phantom)->m_aabbMax.q = _mm_add_ps(effective.q, ((Sbp_AabbPhantom*)phantom)->m_aabbMax.q);
            break;
        case 1:
        case 2:
            ((Sbp_ShapePhantom*)phantom)->m_vTranslation.add4(effective);
            break;
        }
    }
}

struct Sbp_Island {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44;
    Sbp_Array<hkpEntity*> m_kActorEntries;
};
template <class T> static __forceinline T* Sbp_bufAlloc(Sbp_Allocator* heap, int& n) {
    int bytes = n * sizeof(T);
    T* p = (T*)heap->BufAlloc(bytes);
    n = bytes / (int)sizeof(T);
    return p;
}
template <class T> static __forceinline void Sbp_freeArray(Sbp_Allocator* heap, T* data, int cap) {
    if ((cap & 0x80000000) == 0) heap->BufFree(data, (cap & 0x3fffffff) * sizeof(T));
}
template <class T> static inline void Sbp_copy(T* dst, const T* src, int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}
static __forceinline void Sbp_initArray(Sbp_Island**& data, int& size, int& cap, int n) {
    size = n;
    Sbp_Router* r = Sbp_router();
    Sbp_Allocator* heap = r->unk10;
    _ReadWriteBarrier();
    data = size ? Sbp_bufAlloc<Sbp_Island*>(heap, size) : 0;
    cap = size ? size : 0x80000000;
}

struct Sbp_World : hkpWorld {
    void hkpWorld_shiftBroadPhase(const LocalM128& rawShift, LocalM128& rawEffective, int update);
    void FUN_00c91120();
    void UpdateFields_00c91140();
};
static __forceinline void doShift(Sbp_World* self,const LocalM128& rawShift, LocalM128& rawEffective, int update){
    const Sbp_Vec& shift = (const Sbp_Vec&)rawShift;
    Sbp_Vec& effective = (Sbp_Vec&)rawEffective;


    {
        Sbp_Timer* timer = (Sbp_Timer*)TlsGetValue(DAT_0126835c);
        Sbp_TimerEntry* entry = timer->unk04;
        if (entry < timer->unk0C) {
            entry->name = str_010c68c8;
            unsigned int openingTick;
            __asm {
                rdtsc
                mov dword ptr[openingTick], eax
            }
            entry->tick = openingTick;
            timer->unk04 = entry + 1;
        }
    }
    Sbp_Array<Sbp_Pair> pairs;
    pairs.data = 0;
    pairs.size = 0;
    pairs.capacity = 0x80000000;
    ((Sbp_BroadPhase*)self->m_pJobSemaphore)->ShiftBroadPhase(shift, effective, pairs);
    Sbp_CollisionInput* input = (Sbp_CollisionInput*)self->m_pCollisionInput;
    ((Sbp_BroadPhase*)self->m_pJobSemaphore)->GetOffsetLowHigh32Bit(input->m_kAabbMin, input->m_kAabbMaximum);
    Sbp_Vec* ext = (Sbp_Vec*)self->m_kBroadPhaseAabb;
    ext[0].add4(effective);
    ext[1].add4(effective);
    ++self->m_iCriticalOperationsLockCount;
    ((Sbp_Dispatcher*)self->m_pBroadPhaseDispatcher)->hkpTypedBroadPhaseDispatcher_addPairs(pairs.data, pairs.size,
        self->m_pCollisionFilter ? (char*)self->m_pCollisionFilter + 8 : 0);
    Sbp_Border* border = (Sbp_Border*)self->m_pBroadPhaseBorder;
    if (border) border->shiftPhantoms(effective.q);
    if (update == 0) {
        Sbp_Array<hkpEntity*> entities;
        entities.data = 0;
        entities.size = 0;
        entities.capacity = 0x80000000;
        int numInactive = self->m_kInactiveSimulationIslands.m_iElementCount;
        void* fixedIsland = self->m_pFixedIsland;
        Sbp_Island** islandData;
        int numIslands; int islandCap;
        Sbp_initArray(islandData, numIslands, islandCap, numInactive + self->m_kActiveSimulationIslands.m_iElementCount + 1);
        int numFixed = fixedIsland != 0;
        void** src = fixedIsland ? &fixedIsland : 0;
        Sbp_copy(islandData, (Sbp_Island**)src, numFixed);
        Sbp_copy(islandData + numFixed, (Sbp_Island**)self->m_kActiveSimulationIslands.m_data, self->m_kActiveSimulationIslands.m_iElementCount);
        Sbp_copy(islandData + (self->m_kActiveSimulationIslands.m_iElementCount + numFixed), (Sbp_Island**)self->m_kInactiveSimulationIslands.m_data, self->m_kInactiveSimulationIslands.m_iElementCount);
        for (int i = 0; i < numIslands; i++) {
            Sbp_Island* island = islandData[i];
            for (int j = 0; j < island->m_kActorEntries.size; j++) {
                hkpEntity*& entity = island->m_kActorEntries.data[j];
                if (entity->m_kCollidable.m_pCollisionShape != 0) {
                    Sbp_Router* router = Sbp_router();
                    if (entities.size == (entities.capacity & 0x3fffffff)) ResizeAudioStream(router->unk10, &entities, 4);
                    entities.data[entities.size++] = entity;
                }
            }
        }
        hkpEntityAabbUtil_entityBatchRecalcAabb(self->m_pCollisionInput, entities.data, entities.size);
        {
            Sbp_freeArray(Sbp_router()->unk10, islandData, islandCap);
        }
        entities.destroy();
    }
    if (--self->m_iCriticalOperationsLockCount == 0 && !self->m_bBlockExecutingPendingOperations) {
        if (self->m_iPendingOperationCount) self->FUN_00c91120();
        if (self->m_iPendingOperationQueueCount == 1 && self->m_iQueuedOperationCount) self->UpdateFields_00c91140();
    }
    {
        Sbp_Timer* timer = (Sbp_Timer*)TlsGetValue(DAT_0126835c);
        Sbp_TimerEntry* entry = timer->unk04;
        if (entry < timer->unk0C) {
            entry->name = str_010c41f8;
            unsigned int closingTick;
            __asm {
                rdtsc
                mov dword ptr[closingTick], eax
            }
            entry->tick = closingTick;
            timer->unk04 = entry + 1;
        }
    }
    pairs.destroy();
}

// @fnv 0x00c96a20
// src: XBOX_PDB 0x00c96a20
void Sbp_World::hkpWorld_shiftBroadPhase(const LocalM128& rawShift, LocalM128& rawEffective, int update) { doShift(this,rawShift,rawEffective,update); }

namespace fnv_00c977c0 {




extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();






class hkpCollidableCollidableFilterC977 { public: virtual ~hkpCollidableCollidableFilterC977() throw(); };
class hkpShapeCollectionFilterC977 { public: virtual ~hkpShapeCollectionFilterC977() throw(); };
class hkpRayShapeCollectionFilterC977 { public: virtual ~hkpRayShapeCollectionFilterC977() throw(); };
class hkpRayCollidableFilterC977 { public: virtual ~hkpRayCollidableFilterC977() throw(); };

class FUN_00cbfba0 : public hkReferencedObject,
                     public hkpCollidableCollidableFilterC977,
                     public hkpShapeCollectionFilterC977,
                     public hkpRayShapeCollectionFilterC977,
                     public hkpRayCollidableFilterC977 {
public:
    FUN_00cbfba0() throw();
    int unk18;
    int unk1C;
    int m_type;
    int unk24;
    int unk28;
    int unk2C;

    static void* operator new(unsigned int nbytes)
    {
        hkReferencedObject* b = static_cast<hkReferencedObject*>(hkMemoryRouter_getInstance().heap().blockAlloc(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
};

class hkpNullCollisionFilterC977 : public FUN_00cbfba0 {
public:
    hkpNullCollisionFilterC977() throw() { m_type = 1; }
    virtual ~hkpNullCollisionFilterC977() throw();
};

struct hkpCollisionInputC977 {
    int unk00;
    int unk04;
    int unk08;
    FUN_00cbfba0* m_iFilter;
};

class hkpWorldC977 {
public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74;
    hkpCollisionInputC977* m_pCollisionInput;
    FUN_00cbfba0* m_pCollisionFilter;

    void hkpWorld_updateCollisionFilterOnWorld(int updateMode, int ProcessContactPoints);
    void hkpWorld_setCollisionFilter(FUN_00cbfba0* filter, hkBool runUpdate, int updateMode, int ProcessContactPoints);
};

// Uses filter, or a new hkpNullCollisionFilterC977 if null, as m_pCollisionFilter and in m_pCollisionInput, optionally calling FUN_00c96ff0 when runUpdate.
// @fnv 0x00c977c0
// src: HAVOK_LIB 0x00c977c0
void hkpWorldC977::hkpWorld_setCollisionFilter(FUN_00cbfba0* filter, hkBool runUpdate, int updateMode, int ProcessContactPoints)
{
    if (filter == 0)
        filter = new hkpNullCollisionFilterC977();
    else
        ((hkReferencedObject*)filter)->addReference();
    ((hkReferencedObject*)m_pCollisionFilter)->removeReference();
    m_pCollisionFilter = filter;
    m_pCollisionInput->m_iFilter = m_pCollisionFilter;
    if (runUpdate)
        hkpWorld_updateCollisionFilterOnWorld(updateMode, ProcessContactPoints);
}
}  // namespace fnv_00c977c0

typedef float hkReal_S;
typedef signed short hkInt16_S;
typedef unsigned short hkUint16_S;
typedef unsigned long __w64 hkUlong_S;
typedef unsigned __w64 hk_size_t;


// BooleanTypeConstant / hkTypeIsPod: include/hkTypeTraits.h (through hkaAnimation.h -> hkArray.h)


extern "C"{
extern LocalM128 _mm_add_ss(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_add_ps(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_sub_ps(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_mul_ps(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_sqrt_ss(LocalM128 _A);
extern LocalM128 _mm_unpackhi_ps(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_setr_ps(float _A,float _B,float _C,float _D);
extern void _mm_store_ss(float*_V,LocalM128 _A);};
typedef LocalM128 hkQuadReal;

typedef const hkVector4_S&hkVector4Parameter;
inline hkSimdReal::hkSimdReal(const LocalM128& x)
    : m_vValue(x)
{
}
inline hkSimdReal::operator float() const
{
    float scalar;
    _mm_store_ss(&scalar, m_vValue);
    return scalar;
}
__forceinline LocalM128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
__forceinline const LocalM128& hkSimdReal::getQuad() const
{
    return m_vValue;
}
typedef const hkSimdReal&hkSimdRealParameter;
extern const hkQuadReal g_vQuadRealConstant;
class hkTransform_S;

inline hkQuadReal&hkVector4_S::getQuad()
{
return m_vComponents;
}
inline void hkVector4_S::operator=(const hkVector4_S&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4_S::set(hkReal_S a,hkReal_S b,hkReal_S c,hkReal_S d)
{
m_vComponents=_mm_setr_ps(a,b,c,d);
}
inline void hkVector4_S::SetAllComponents(hkSimdRealParameter a)
{
m_vComponents=_mm_shuffle_ps(a.getQuad(),a.getQuad(),(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
inline void hkVector4_S::add4(const hkVector4_S&v)
{
m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4_S::setAdd4(const hkVector4_S&v0,const hkVector4_S&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4_S::sub4(const hkVector4_S&v)
{
m_vComponents=_mm_sub_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4_S::setSub4(const hkVector4_S&v0,const hkVector4_S&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4_S::setMul4(const hkVector4_S&a,const hkVector4_S&b)
{
m_vComponents=_mm_mul_ps(a.m_vComponents,b.m_vComponents);
}
inline void hkVector4_S::addMul4(hkSimdRealParameter r,const hkVector4_S&v1)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(r.broadcast(),v1.m_vComponents));
}
inline void hkVector4_S::addMul4(const hkVector4_S&x,const hkVector4_S&y)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(x.m_vComponents,y.m_vComponents));
}
inline void hkVector4_S::setAddMul4(const hkVector4_S&a,const hkVector4_S&x,const hkVector4_S&y)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(x.m_vComponents,y.m_vComponents));
}
inline void hkVector4_S::setCross(const hkVector4_S&v0,const hkVector4_S&v1)
{
hkQuadReal cross0;
cross0=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))));
hkQuadReal cross1;
cross1=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))));
m_vComponents=_mm_sub_ps(cross0,cross1);}
inline hkSimdReal hkVector4_S::dot3(const hkVector4_S&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline hkSimdReal hkVector4_S::length3()const
{
return _mm_sqrt_ss(this->dot3(*this).getQuad());
}
inline void hkVector4_S::setXYZW(const hkVector4_S&xyz,const hkVector4_S&w)
{
m_vComponents=_mm_shuffle_ps(xyz.m_vComponents,_mm_unpackhi_ps(xyz.m_vComponents,w.m_vComponents),(((3)<<6)|((0)<<4)|((1)<<2)|((0))));
}
inline hkSimdReal hkVector4_S::getSimdAt(int i)const
{
switch(i)
{
case 0:
return m_vComponents;
case 1:
return _mm_shuffle_ps(m_vComponents,m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
case 2:
return _mm_shuffle_ps(m_vComponents,m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
case 3:
default:
return _mm_shuffle_ps(m_vComponents,m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3))));
}
}
inline void hkVector4_S::broadcast(int i)
{
if(i==0)
{
m_vComponents=_mm_shuffle_ps(m_vComponents,m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
}
inline void hkVector4_S::setBroadcast(const hkVector4_S&v,int i)
{
if(i==0)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
else if(i==3)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3))));
}
}
__forceinline void hkVector4_S::SetRotatedDirection(const hkQuaternion_S&quat,const hkVector4_S&direction)
{
const hkVector4_S& imag = reinterpret_cast<const hkVector4_S&>(quat);
hkVector4_S minusHalf;minusHalf.getQuad()=g_vQuadRealConstant;
hkVector4_S qreal;
qreal.setBroadcast(imag,3);
hkVector4_S q2minus1;
q2minus1.setAddMul4(minusHalf,qreal,qreal);
hkVector4_S ret;
ret.setMul4(direction,q2minus1);
hkVector4_S imagDotDir;
imagDotDir.getQuad()=imag.dot3(direction).getQuad();
imagDotDir.broadcast(0);
ret.addMul4(imagDotDir,imag);
hkVector4_S imagCrossDir;
imagCrossDir.setCross(imag,direction);
ret.addMul4(qreal,imagCrossDir);
this->setAdd4(ret,ret);}
inline void hkQuaternion::SetProduct(const hkQuaternion& q0, const hkQuaternion& q1)
{
    const hkVector4_S& v0 = reinterpret_cast<const hkVector4_S&>(q0);
    const hkVector4_S& v1 = reinterpret_cast<const hkVector4_S&>(q1);
    hkVector4_S vec;
    vec.setCross(v0, v1);
    vec.addMul4(v0.getSimdAt(3), v1);
    hkVector4_S dot;
    dot.SetAllComponents(v0.dot3(v1));
    hkVector4_S w;
    w.sub4(dot);
    reinterpret_cast<hkVector4_S&>(*this).setXYZW(vec, w);
}
inline const hkVector4& hkQsTransform::getTranslation() const
{
    return m_vTranslation;
}
inline const hkQuaternion& hkQsTransform::getRotation() const
{
    return m_rotation;
}
class hkDisplayGeometry;


// Renders bone hierarchy lines and local axis frames for a skeleton pose by transforming model-space positions and rotations into world space.
// @fnv 0x00c998b0
// src: XBOX_PDB 0x00c998b0
void hkDebugDisplay::displayModelSpacePose(int numTransforms,const hkInt16_S*parentIndices,const hkQsTransform_S*modelSpacePose,const hkQsTransform_S&worldFromModel,int id,int tag,int color,hkReal_S boneAxisSize,hkBool_S showRootTranslation)
{
const hkQsTransform* pose = reinterpret_cast<const hkQsTransform*>(modelSpacePose);
const hkQsTransform& world = reinterpret_cast<const hkQsTransform&>(worldFromModel);
const hkInt16_S numBones=static_cast<hkInt16_S>(numTransforms);
for(hkInt16_S i=0;i<numBones;i++)
{
hkVector4_S p1;
p1.SetTransformedPoint(worldFromModel,reinterpret_cast<const hkVector4_S&>(pose[i].getTranslation()));
hkReal_S boneLen=1.0f;
const hkInt16_S parent=parentIndices[i];
if(parent==-1)
{
if(showRootTranslation)
{
hkVector4_S p2;
p2.set(0,0,0,0);
p2.SetTransformedPoint(worldFromModel,p2);
DisplayLine(p1,p2,color,id,tag);
}
}
else
{
hkVector4_S p2;
p2.SetTransformedPoint(worldFromModel,reinterpret_cast<const hkVector4_S&>(pose[parent].getTranslation()));
DisplayLine(p1,p2,color,id,tag);
hkVector4_S bone;
bone.setSub4(p1,p2);
boneLen=bone.length3();
boneLen=(boneLen>10.0f)? 10.0f:boneLen;
boneLen=(boneLen<0.1f)? 0.1f:boneLen;
}
const hkVector4_S worldPosition=p1;
__declspec(align(16)) hkQuaternion worldRotation;worldRotation.SetProduct(world.getRotation(),pose[i].getRotation());
{
hkVector4_S boneLocalFrame;
hkVector4_S p2;
p1=worldPosition;
boneLocalFrame.set(boneAxisSize*boneLen,0,0,0);
p2.SetRotatedDirection(reinterpret_cast<const hkQuaternion_S&>(worldRotation),boneLocalFrame);
p2.add4(p1);
DisplayLine(p1,p2,0x7fff0000,id,tag);
p1=worldPosition;
boneLocalFrame.set(0,boneAxisSize*boneLen,0,0);
p2.SetRotatedDirection(reinterpret_cast<const hkQuaternion_S&>(worldRotation),boneLocalFrame);
p2.add4(p1);
DisplayLine(p1,p2,0x7f00ff00,id,tag);
p1=worldPosition;
boneLocalFrame.set(0,0,boneAxisSize*boneLen,0);
p2.SetRotatedDirection(reinterpret_cast<const hkQuaternion_S&>(worldRotation),boneLocalFrame);
p2.add4(p1);
DisplayLine(p1,p2,0x7f0000ff,id,tag);
}
}
}

extern "C" LocalM128 __cdecl _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 __cdecl _mm_add_ss(LocalM128 a, LocalM128 b);


inline const hkVector4& hkQuaternion::getImag() const
{
    return *reinterpret_cast<const hkVector4*>(this);
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9), _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    const LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2), _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
__forceinline void hkVector4::setBroadcast3(const hkVector4& v)
{
    m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& v) const
{
    const LocalM128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
    const LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
}
__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction)
{
    __declspec(align(16)) hkVector4 qreal; qreal.setBroadcast3(quat.getImag());
    __declspec(align(16)) hkVector4 q2minus1; q2minus1.m_vComponents = _mm_add_ps(_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), DAT_010c71e0);
    __declspec(align(16)) hkVector4 ret; ret.setMul4(q2minus1, direction);
    __declspec(align(16)) hkVector4 imagDotDir; imagDotDir.m_vComponents = quat.getImag().dot3(direction).getQuad(); imagDotDir.m_vComponents = _mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    __declspec(align(16)) hkVector4 imagCrossDir; imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(imagDotDir, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}
__forceinline void hkQsTransform::SetProduct(const hkQsTransform& t1, const hkQsTransform& t2)
{
    __declspec(align(16)) hkVector4 temp;
    temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
    m_vTranslation.setAdd4(temp, t1.m_vTranslation);
    m_rotation.setMul(t1.m_rotation, t2.m_rotation);
    m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
}

extern const hkQsTransform DAT_01268700;





__forceinline void transformLocalPoseToModelPoseDAD(int numTransforms, const short* parentIndices, const hkQsTransform& worldFromModel, const hkQsTransform* poseLocal, hkQsTransform* poseModelOut)
{
    for (int i = 0; i < numTransforms; i++)
    {
        const int parentId = parentIndices[i];
        const hkQsTransform& worldFromParent = (-1 != parentId) ? poseModelOut[parentId] : worldFromModel;
        poseModelOut[i].SetProduct(worldFromParent, poseLocal[i]);
    }
}

class PoseUserDAD {
public:
    void displayModelSpacePose(int numBones, const short* parents, hkQsTransform* poseModel, int a4, int a5, int a6, int a7, float a8, int a9);
    void hkDebugDisplay_displayLocalSpacePose(int numBones, const short* parents, const hkQsTransform* poseLocal, int a4, int a5, int a6, int a7, float a8, int a9);
};

// Converts local bone poses to model space on the stack and forwards them to FUN_00c998b0.
// @fnv 0x00c99d40
// src: XBOX_PDB 0x00c99d40
void PoseUserDAD::hkDebugDisplay_displayLocalSpacePose(int numBones, const short* parents, const hkQsTransform* poseLocal, int a4, int a5, int a6, int a7, float a8, int a9)
{
    hkMemoryRouter* stack = &hkMemoryRouter::getInstance();
    hkQsTransform* poseModel = (hkQsTransform*)stack->m_stack.m_next.m_storage;
    stack->m_stack.m_next.m_storage = static_cast<char*>(stack->m_stack.m_next.m_storage) + ((numBones * sizeof(hkQsTransform) + 0x7f) & ~0x7f);

    transformLocalPoseToModelPoseDAD(numBones, parents, DAT_01268700, poseLocal, poseModel);
    displayModelSpacePose(numBones, parents, poseModel, a4, a5, a6, a7, a8, a9);

    hkMemoryRouter::getInstance().m_stack.m_next.m_storage = (char*)poseModel;
}

namespace HingeAllocation { hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
__forceinline hkMemoryAllocator& heap(hkMemoryRouter& router) { return *(hkMemoryAllocator*)router.m_heap; } }
inline void* hkpLimitedHingeConstraintData::operator new(unsigned int size)
{
    void* p = HingeAllocation::heap(HingeAllocation::hkMemoryRouter_getInstance()).blockAlloc(size);
    static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags = (unsigned short)size;
    return p;
}
inline void hkpLimitedHingeConstraintData::operator delete(void* p)
{
    HingeAllocation::heap(HingeAllocation::hkMemoryRouter_getInstance()).blockFree(p, 0xe0);
}

namespace fnv_00caa3f0 {


struct ThreadMemoryContext {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 unsigned int unk01c;
 unsigned int unk020;
 unsigned int unk024;
 unsigned int unk028;
 unsigned int unk02c;
 unsigned int unk030;
 unsigned int unk034;
 unsigned int unk038;
 unsigned int unk03c;
 unsigned int unk040;
 unsigned int unk044;
 unsigned int unk048;
 unsigned int unk04c;
 unsigned int unk050;
 unsigned int unk054;
 unsigned int unk058;
 unsigned int unk05c;
 unsigned int unk060;
 unsigned int unk064;
 unsigned int unk068;
 unsigned int unk06c;
 unsigned int unk070;
 unsigned int unk074;
 unsigned int unk078;
 unsigned int unk07c;
 unsigned int unk080;
 unsigned int unk084;
 unsigned int unk088;
 unsigned int unk08c;
 unsigned int unk090;
 unsigned int unk094;
 unsigned int unk098;
 unsigned int unk09c;
 unsigned int unk0a0;
 unsigned int unk0a4;
 unsigned int unk0a8;
 unsigned int unk0ac;
 unsigned int unk0b0;
 unsigned int unk0b4;
 unsigned int unk0b8;
 unsigned int unk0bc;
 unsigned int unk0c0;
 unsigned int unk0c4;
 unsigned int unk0c8;
 unsigned int unk0cc;
 unsigned int unk0d0;
 unsigned int unk0d4;
 unsigned int unk0d8;
 unsigned int unk0dc;
 unsigned int unk0e0;
 unsigned int unk0e4;
 unsigned int unk0e8;
 unsigned int unk0ec;
 unsigned int unk0f0;
 unsigned int unk0f4;
 unsigned int unk0f8;
 unsigned int unk0fc;
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
 unsigned int unk214;
 unsigned int unk218;
 unsigned int unk21c;
 unsigned int unk220;
 unsigned int unk224;
 unsigned int unk228;
 unsigned int unk22c;
 unsigned int unk230;
 unsigned int unk234;
 unsigned int unk238;
 unsigned int unk23c;
 unsigned int unk240;
 unsigned int unk244;
 unsigned int unk248;
 unsigned int unk24c;
 unsigned int unk250;
 unsigned int unk254;
 unsigned int unk258;
 unsigned int unk25c;
 unsigned int unk260;
 unsigned int unk264;
 unsigned int unk268;
 unsigned int unk26c;
 unsigned int unk270;
 unsigned int unk274;
 unsigned int unk278;
 unsigned int unk27c;
 unsigned int unk280;
 unsigned int unk284;
 unsigned int unk288;
 unsigned int unk28c;
 unsigned int unk290;
 unsigned int unk294;
 unsigned int unk298;
 unsigned int unk29c;
 unsigned int unk2a0;
 unsigned int unk2a4;
 unsigned int unk2a8;
 unsigned int unk2ac;
 unsigned int unk2b0;
 unsigned int m_uiMemoryContext;
};
extern __declspec(thread) ThreadMemoryContext threadMemoryContext;
struct AutoMemoryContext {
 unsigned int previous;
 AutoMemoryContext(unsigned int value):previous(threadMemoryContext.m_uiMemoryContext){threadMemoryContext.m_uiMemoryContext=value;}
 ~AutoMemoryContext(){threadMemoryContext.m_uiMemoryContext=previous;}
};
class LimitedHingeWrapper {
public: unsigned int unk00;hkpLimitedHingeConstraintData* data;
 unsigned int hkLimitedHingeConstraintCinfo_CreateData();
};
// Ensures the hkpLimitedHingeConstraintData is allocated and returns its size.
// @fnv 0x00caa3f0
// src: XBOX_PDB 0x00caa3f0
unsigned int LimitedHingeWrapper::hkLimitedHingeConstraintCinfo_CreateData()
{
 AutoMemoryContext context(0x10);
 if(!data) data=new hkpLimitedHingeConstraintData;
 return sizeof(hkpLimitedHingeConstraintData);
}
}  // namespace fnv_00caa3f0

extern "C" void _ReadWriteBarrier();

extern int DAT_0108febc;
extern int DAT_01268188;
extern int DAT_01268318;
void* Object_DispatchCommandFour(unsigned int size);
void bhkSerializable_CloneCritLock(void);
void bhkSerializable_CloneCritUnlock(void);

struct TlsBlk_caa4a0 {
    unsigned int m_0000;
    unsigned int m_0004;
    unsigned int m_0008;
    unsigned int m_000c;
    unsigned int m_0010;
    unsigned int m_0014;
    unsigned int m_0018;
    unsigned int m_001c;
    unsigned int m_0020;
    unsigned int m_0024;
    unsigned int m_0028;
    unsigned int m_002c;
    unsigned int m_0030;
    unsigned int m_0034;
    unsigned int m_0038;
    unsigned int m_003c;
    unsigned int m_0040;
    unsigned int m_0044;
    unsigned int m_0048;
    unsigned int m_004c;
    unsigned int m_0050;
    unsigned int m_0054;
    unsigned int m_0058;
    unsigned int m_005c;
    unsigned int m_0060;
    unsigned int m_0064;
    unsigned int m_0068;
    unsigned int m_006c;
    unsigned int m_0070;
    unsigned int m_0074;
    unsigned int m_0078;
    unsigned int m_007c;
    unsigned int m_0080;
    unsigned int m_0084;
    unsigned int m_0088;
    unsigned int m_008c;
    unsigned int m_0090;
    unsigned int m_0094;
    unsigned int m_0098;
    unsigned int m_009c;
    unsigned int m_00a0;
    unsigned int m_00a4;
    unsigned int m_00a8;
    unsigned int m_00ac;
    unsigned int m_00b0;
    unsigned int m_00b4;
    unsigned int m_00b8;
    unsigned int m_00bc;
    unsigned int m_00c0;
    unsigned int m_00c4;
    unsigned int m_00c8;
    unsigned int m_00cc;
    unsigned int m_00d0;
    unsigned int m_00d4;
    unsigned int m_00d8;
    unsigned int m_00dc;
    unsigned int m_00e0;
    unsigned int m_00e4;
    unsigned int m_00e8;
    unsigned int m_00ec;
    unsigned int m_00f0;
    unsigned int m_00f4;
    unsigned int m_00f8;
    unsigned int m_00fc;
    unsigned int m_0100;
    unsigned int m_0104;
    unsigned int m_0108;
    unsigned int m_010c;
    unsigned int m_0110;
    unsigned int m_0114;
    unsigned int m_0118;
    unsigned int m_011c;
    unsigned int m_0120;
    unsigned int m_0124;
    unsigned int m_0128;
    unsigned int m_012c;
    unsigned int m_0130;
    unsigned int m_0134;
    unsigned int m_0138;
    unsigned int m_013c;
    unsigned int m_0140;
    unsigned int m_0144;
    unsigned int m_0148;
    unsigned int m_014c;
    unsigned int m_0150;
    unsigned int m_0154;
    unsigned int m_0158;
    unsigned int m_015c;
    unsigned int m_0160;
    unsigned int m_0164;
    unsigned int m_0168;
    unsigned int m_016c;
    unsigned int m_0170;
    unsigned int m_0174;
    unsigned int m_0178;
    unsigned int m_017c;
    unsigned int m_0180;
    unsigned int m_0184;
    unsigned int m_0188;
    unsigned int m_018c;
    unsigned int m_0190;
    unsigned int m_0194;
    unsigned int m_0198;
    unsigned int m_019c;
    unsigned int m_01a0;
    unsigned int m_01a4;
    unsigned int m_01a8;
    unsigned int m_01ac;
    unsigned int m_01b0;
    unsigned int m_01b4;
    unsigned int m_01b8;
    unsigned int m_01bc;
    unsigned int m_01c0;
    unsigned int m_01c4;
    unsigned int m_01c8;
    unsigned int m_01cc;
    unsigned int m_01d0;
    unsigned int m_01d4;
    unsigned int m_01d8;
    unsigned int m_01dc;
    unsigned int m_01e0;
    unsigned int m_01e4;
    unsigned int m_01e8;
    unsigned int m_01ec;
    unsigned int m_01f0;
    unsigned int m_01f4;
    unsigned int m_01f8;
    unsigned int m_01fc;
    unsigned int m_0200;
    unsigned int m_0204;
    unsigned int m_0208;
    unsigned int m_020c;
    unsigned int m_0210;
    unsigned int m_0214;
    unsigned int m_0218;
    unsigned int m_021c;
    unsigned int m_0220;
    unsigned int m_0224;
    unsigned int m_0228;
    unsigned int m_022c;
    unsigned int m_0230;
    unsigned int m_0234;
    unsigned int m_0238;
    unsigned int m_023c;
    unsigned int m_0240;
    unsigned int m_0244;
    unsigned int m_0248;
    unsigned int m_024c;
    unsigned int m_0250;
    unsigned int m_0254;
    unsigned int m_0258;
    unsigned int m_025c;
    unsigned int m_0260;
    unsigned int m_0264;
    unsigned int m_0268;
    unsigned int m_026c;
    unsigned int m_0270;
    unsigned int m_0274;
    unsigned int m_0278;
    unsigned int m_027c;
    unsigned int m_0280;
    unsigned int m_0284;
    unsigned int m_0288;
    unsigned int m_028c;
    unsigned int m_0290;
    unsigned int m_0294;
    unsigned int m_0298;
    unsigned int m_029c;
    unsigned int m_02a0;
    unsigned int m_02a4;
    unsigned int m_02a8;
    unsigned int m_02ac;
    unsigned int m_02b0;
    int m_02b4;
};
__declspec(thread) TlsBlk_caa4a0 g_tlsBlock;

class TlsGuard_caa4a0 {
public:
    int m_saved;
    TlsGuard_caa4a0() { m_saved = g_tlsBlock.m_02b4; g_tlsBlock.m_02b4 = 0x10; }
    ~TlsGuard_caa4a0() { g_tlsBlock.m_02b4 = m_saved; }
};

// Keep the allocation alive only after its inline initialization succeeds.
struct RefObjectAllocationGuard
{
    void* allocation;
    ~RefObjectAllocationGuard() { if (allocation) ::operator delete(allocation); }
};
__forceinline bhkRefObject* CreateRefObject()
{
    bhkRefObject* obj = static_cast<bhkRefObject*>(Object_DispatchCommandFour(16));
    RefObjectAllocationGuard guard = { obj };
    if (obj != 0) {
        obj->Initialize();
        *(const void**)obj = (const void*)&DAT_0108febc;
        _ReadWriteBarrier();
        const int inc = 1;
        *(unsigned int*)((char*)obj + 12) = 0;
        DAT_01268188 += inc;
        _ReadWriteBarrier();
        *(const void**)obj = (const void*)0x10c5ce4;
        _ReadWriteBarrier();
        DAT_01268318 += inc;
    }
    else
        obj = 0;
    guard.allocation = 0;
    return obj;
}

struct caa4a0_TblHost { void* m_00; void* m_04; void* m_08; unsigned int* m_0c; };
struct caa4a0_TblFirst { unsigned int* m_00; };

class caa4a0_RefObj {
public:
    virtual void slot00();
    virtual void slot04(int a, unsigned int b);
};

class caa4a0_Target {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual unsigned int* slotb4(bool* flagOut);
    unsigned int unk04;
    caa4a0_TblHost* unk08;
    caa4a0_TblFirst* unk0c;
    void bhkConstraint_CopyMembers(bhkRefObject* obj, unsigned int param);
    bhkRefObject* bhkLimitedHingeConstraint_CreateClone(unsigned int param);
};

// Allocates a bhkRefObject, calls FUN_00c89730, and if a table entry is set, invokes slot04 on the object from slotb4.
// @fnv 0x00caa4a0
// src: XBOX_PDB 0x00caa4a0
bhkRefObject* caa4a0_Target::bhkLimitedHingeConstraint_CreateClone(unsigned int param) {
    TlsGuard_caa4a0 guard;
    bhkSerializable_CloneCritLock();
    bhkRefObject* obj = CreateRefObject();
    this->bhkConstraint_CopyMembers(obj, param);
    unsigned int* tbl = 0;
    if (this != 0 && this->unk08 != 0)
        tbl = this->unk08->m_0c;
    else if (this->unk0c != 0)
        tbl = this->unk0c->m_00;
    if (tbl != 0 && tbl[44] != 0) {
        bool b;
        unsigned int* p = this->slotb4(&b);
        caa4a0_RefObj* ref = (caa4a0_RefObj*)(p != 0 ? p - 1 : 0);
        ref->slot04(0, param);
    }
    bhkSerializable_CloneCritUnlock();
    return obj;
}

static inline void** AddBack(hkArray<void*>* arr, void* listener) {
    ThreadMemHolder* mem = (ThreadMemHolder*)hkMemoryRouter_getInstance();
    if (arr->m_iElementCount == (arr->m_iCapacityState & 0x3fffffff)) {
        ResizeAudioStream(mem->m_alloc, arr, 4);
    }
    void** p = &arr->m_data[arr->m_iElementCount];
    *p = listener;
    arr->m_iElementCount++;
    return p;
}

struct FUN_00c939a0_Class : hkpWorld {
    void** hkpWorld_addIslandPostCollideListener(void* listener);
};

// Adds the given listener to the island post-collide listener array and returns a pointer to the new slot.
// @fnv 0x00c939a0
// src: HAVOK_LIB 0x00c939a0
void** FUN_00c939a0_Class::hkpWorld_addIslandPostCollideListener(void* listener) {
    return AddBack(&m_kIslandPostCollideListeners, listener);
}


void ResizeAudioStream(void*, void*, int);

struct hkpWorld_Listener : hkpWorld {
    void*& hkpWorld_addWorldDeletionListener(void* listener);
};

// Appends a listener pointer to m_kWorldDeletionListeners, growing the array via FUN_00c90940 when full, and returns the stored pointer.
// @fnv 0x00c93a60
// src: HAVOK_LIB 0x00c93a60
void*& hkpWorld_Listener::hkpWorld_addWorldDeletionListener(void* listener) {
    hkArray<void*>* arr = &m_kWorldDeletionListeners;
    hkThreadMemory* mem = (hkThreadMemory*)hkMemoryRouter_getInstance();
    if (arr->m_iElementCount == (arr->m_iCapacityState & 0x3fffffff)) {
        ResizeAudioStream(*(void**)((char*)mem + 0x10), arr, 4);
    }
    void** slot = &arr->m_data[arr->m_iElementCount];
    *slot = listener;
    arr->m_iElementCount++;
    return *slot;
}

struct FUN_00c92c70_Class {
    void __thiscall hkpWorld_removePhantom(void* phantom);
};

struct FUN_00c936a0_Class {
    void __thiscall hkpWorld_addPhantom(void* phantom);
};

struct NiRTTI;


union __declspec(align(16)) PositionQuad {
    LocalM128 simd;
    signed char bytes[16];
};
struct __declspec(align(16)) SavedPosition {
    PositionQuad quad;
    SavedPosition() {}
    SavedPosition(const SavedPosition& other) { quad.simd = *(const LocalM128*)&other.quad.bytes[0]; }
};

struct ActionObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void AssignEntity(void* entity);
    void* unk04;
    FUN_00c92c70_Class* m_pOwningWorld;
    void* unk0C;
    void* m_pEntity;
};

struct FUN_00cac980_Holder {
    void* __thiscall hkpCharacterProxy_getShapePhantom();
};

struct FUN_00cac910_shell : FUN_00cac980_Holder {
    const SavedPosition& __thiscall hkpCharacterProxy_getPosition();
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    ActionObj* unk30;
};

struct ArgClass {
    void* unk00;
    void* unk04;
    void* unk08;
};

extern const SavedPosition zeroPosition;

struct HostClass : NiObject {
    FUN_00cac910_shell* unk08;
    __forceinline const SavedPosition& getPosition() {
        FUN_00cac910_shell* proxy = unk08;
        const SavedPosition* result = &zeroPosition;
        if (proxy) {
            this->NiObject::GetStreamableRTTI();
            result = &proxy->hkpCharacterProxy_getPosition();
            this->NiObject::GetStreamableRTTI();
        }
        return *result;
    }
    bool __thiscall bhkCharacterController_SetShape(ArgClass* a1, int a2);
};

// If the action's current entity differs from a1->unk08, calls world->FUN_00c92c70, a virtual with a1->unk08, then FUN_00c936a0; returns true if so.
// @fnv 0x00c6d3f0
// src: XBOX_PDB 0x00c6d3f0
bool __thiscall HostClass::bhkCharacterController_SetShape(ArgClass* a1, int aiUnused) {
    FUN_00cac910_shell* obj = this->unk08;
    if (obj) {
        ActionObj* action = (ActionObj*)obj->hkpCharacterProxy_getShapePhantom();
        if (action) {
            void* curEnt = action->m_pEntity;
            void* ent = a1 ? a1->unk08 : 0;
            if (curEnt != ent) {
                FUN_00c92c70_Class* world = action->m_pOwningWorld;
                SavedPosition position(getPosition());
                if (world) {
                    world->hkpWorld_removePhantom(action);
                }
                action->AssignEntity(a1 ? a1->unk08 : 0);
                if (world) {
                    ((FUN_00c936a0_Class*)world)->hkpWorld_addPhantom(action);
                }
                return true;
            }
        }
    }
    return false;
}

struct hkThreadMemoryQ {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pMemoryAllocator;
};

void ResizeAudioStream(void*, void*, int);

template <typename T>
inline T* hkArrayPushBack(hkArray<T>& arr, hkThreadMemoryQ* mem, const T& t) {
    if (arr.m_iElementCount == (arr.m_iCapacityState & 0x3fffffff)) {
        ResizeAudioStream(mem->m_pMemoryAllocator, &arr, sizeof(T));
    }
    T* p = &arr.m_data[arr.m_iElementCount];
    *p = t;
    arr.m_iElementCount++;
    return p;
}

struct FUN_00c93aa0_Class : hkpWorld {
    void* hkpWorld_addContactImpulseLimitBreachedListener(void* listener);
};

// Adds a listener to m_kContactImpulseLimitBreachedListeners via hkArrayPushBack and returns a pointer to the new element.
// @fnv 0x00c93aa0
// src: HAVOK_LIB 0x00c93aa0
void* FUN_00c93aa0_Class::hkpWorld_addContactImpulseLimitBreachedListener(void* listener) {
    hkArray<void*>* arr = &m_kContactImpulseLimitBreachedListeners;
    return hkArrayPushBack(*arr, (hkThreadMemoryQ*)hkMemoryRouter_getInstance(), listener);
}

struct PhantomBatchAllocator {
    virtual void slot00() throw();
    virtual void slot04() throw();
    virtual void slot08() throw();
    virtual void slot0C() throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct PhantomBatchRouter {
    void* m_aiEntries;
    void* unk04;
    void* unk08;
    void* unk0C;
    PhantomBatchAllocator* m_pStreamAllocator;
};


void __cdecl hkpWorldCallbackUtil_firePhantomRemoved(hkpWorld* world, hkpPhantom* phantom) throw();


struct BroadPhaseCastCollector {
    hkpBroadPhaseHandle* m_kPointA;
    hkpBroadPhaseHandle* m_kPointB;
};

template <class T>
struct PhantomBatchLocalArray : hkArrayBase<T> {
    T* m_pTrailingData;
    __forceinline PhantomBatchLocalArray(int n) throw() {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = (int)0x80000000;
        PhantomBatchRouter* mem = (PhantomBatchRouter*)hkMemoryRouter_getInstance();
        char* p = (char*)mem->m_aiEntries;
        int bytes = (n * (int)sizeof(T) + 0x7f) & ~0x7f;
        mem->m_aiEntries = p + bytes;
        this->m_data = (T*)p;
        this->m_iCapacityState = n | (int)0x80000000;
        m_pTrailingData = (T*)p;
    }
};

template <class T>
__forceinline void PhantomBatchLocalArray_release(PhantomBatchLocalArray<T>& a) throw() {
    if (a.m_pTrailingData == a.m_data) {
        a.m_iElementCount = 0;
    }
    T* local = a.m_pTrailingData;
    PhantomBatchRouter* stackRouter = (PhantomBatchRouter*)hkMemoryRouter_getInstance();
    stackRouter->m_aiEntries = local;

    PhantomBatchRouter* router = (PhantomBatchRouter*)hkMemoryRouter_getInstance();
    PhantomBatchAllocator* heap = router->m_pStreamAllocator;
    int cap = a.m_iCapacityState;
    a.m_iElementCount = 0;
    if (cap & (int)0x80000000) {
        return;
    }
    heap->ReturnMemory(a.m_data, (cap & 0x3fffffff) * (int)sizeof(T));
}

__forceinline int PhantomBatchIndexOf(const hkArray<hkpPhantom*>& arr, hkpPhantom* phantom) throw() {
    int count = arr.m_iElementCount;
    int idx = 0;
    if (count > 0) {
        hkpPhantom** cursor = arr.m_data;
        do {
            if (*cursor == phantom) {
                return idx;
            }
            ++idx;
            ++cursor;
        } while (idx < count);
    }
    return -1;
}

__forceinline void PhantomBatchRemoveAt(hkArray<hkpPhantom*>& arr, int index) throw() {
    --arr.m_iElementCount;
    if (arr.m_iElementCount != index) {
        arr.m_data[index] = arr.m_data[arr.m_iElementCount];
    }
}

struct RemovePhantomBatchOp {
    unsigned char m_type;
    hkpPhantom** m_kPhantoms;
    unsigned short m_iPhantomCount;
};

struct BroadPhaseVt {
    virtual void s00() throw();
    virtual void s04() throw();
    virtual void s08() throw();
    virtual void s0C() throw();
    virtual void s10() throw();
    virtual void s14() throw();
    virtual void s18() throw();
    virtual void s1C() throw();
    virtual void RemoveObjectBatch(hkArray<hkpBroadPhaseHandle*>& handles, hkArray<BroadPhaseCastCollector>& pairs) throw();
};

struct BroadPhaseDispatcher {
    void DispatchPairs(BroadPhaseCastCollector* data, int numPairs) throw();
};

struct World_RemovePhantomBatch : hkpWorld {
    void hkpWorld_queueOperation(RemovePhantomBatchOp* op) throw();
    void FUN_00c91120() throw();
    void UpdateFields_00c91140() throw();
    void hkpWorld_removePhantomBatch(hkpPhantom** phantomBatch, int numPhantoms);
};

// Removes a batch of phantoms from the world, updating broad-phase and phantom lists, and defers if a critical lock is held.
// @fnv 0x00c95800
// src: HAVOK_LIB 0x00c95800
void World_RemovePhantomBatch::hkpWorld_removePhantomBatch(hkpPhantom** phantomBatch, int numPhantoms) {
    if (m_iCriticalOperationsLockCount + m_iCriticalOperationsLockCountForPhantoms) {
        RemovePhantomBatchOp op;
        op.m_type = 0x10;
        op.m_kPhantoms = phantomBatch;
        op.m_iPhantomCount = (unsigned short)numPhantoms;
        hkpWorld_queueOperation(&op);
        return;
    }

    ++m_iCriticalOperationsLockCount;

    PhantomBatchLocalArray<hkpBroadPhaseHandle*> handles(numPhantoms);
    for (int ph = 0; ph < numPhantoms; ++ph) {
        hkpPhantom* phantom = phantomBatch[ph];
        hkpBroadPhaseHandle* const& handle = (hkpBroadPhaseHandle*)&phantom->m_kCollidable.m_kBroadPhaseHandle;
        handles.m_data[handles.m_iElementCount] = handle;
        handles.m_iElementCount++;
        hkpWorldCallbackUtil_firePhantomRemoved(this, phantom);
        phantom->firePhantomRemoved();
    }

    if (handles.m_iElementCount) {
        PhantomBatchLocalArray<BroadPhaseCastCollector> pairs(m_iBroadPhaseQuerySize);
        ((BroadPhaseVt*)m_pJobSemaphore)->RemoveObjectBatch(static_cast<hkArray<hkpBroadPhaseHandle*>&>(static_cast<hkArrayBase<hkpBroadPhaseHandle*>&>(handles)), static_cast<hkArray<BroadPhaseCastCollector>&>(static_cast<hkArrayBase<BroadPhaseCastCollector>&>(pairs)));
        ((BroadPhaseDispatcher*)m_pBroadPhaseDispatcher)->DispatchPairs(pairs.m_data, pairs.m_iElementCount);
        PhantomBatchLocalArray_release(pairs);
    }

    for (int i = 0; i < numPhantoms; ++i) {
        hkpPhantom* phantom = phantomBatch[i];
        phantom->m_pOwningWorld = 0;
        int idx = PhantomBatchIndexOf(m_kPhantoms, phantom);
        PhantomBatchRemoveAt(m_kPhantoms, idx);
        if (phantom->m_usMemSizeAndFlags == 0) {
            phantom->FreeListenerArrays();
        }
        ((FUN_00d1df70*)phantom)->removeReference();
    }

    if (--m_iCriticalOperationsLockCount == 0) {
        if (m_bBlockExecutingPendingOperations == 0) {
            if (m_iPendingOperationCount != 0) {
                FUN_00c91120();
            }
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount != 0) {
                UpdateFields_00c91140();
            }
        }
    }
    PhantomBatchLocalArray_release(handles);
}

struct __declspec(align(16)) Vec_00c98780 {
    LocalM128 q;
    void FUN_00c7f7a0(const hkTransform& tr, const hkVector4& v);
};

struct Cls_00c98780 {
    void hkDebugDisplay_displayLine(Vec_00c98780& a, Vec_00c98780& b, int x, int y, int z);
    void __thiscall hkDebugDisplay_displayLineModelSpace(const hkTransform& tr, const hkVector4& a, const hkVector4& b, int x, int y, int z);
};

// Builds two vectors from a and b with tr via FUN_00c7f7a0, then passes them with x, y and z to FUN_00c986c0.
// @fnv 0x00c98780
// src: HAVOK_LIB 0x00c98780
void Cls_00c98780::hkDebugDisplay_displayLineModelSpace(const hkTransform& tr, const hkVector4& a, const hkVector4& b, int x, int y, int z)
{
    Vec_00c98780 pa;
    pa.FUN_00c7f7a0(tr, a);
    Vec_00c98780 pb;
    pb.FUN_00c7f7a0(tr, b);
    hkDebugDisplay_displayLine(pa, pb, x, y, z);
}

extern const float DAT_01011d78;

struct Vec_00c98c80 {
    LocalM128 m_vComponents;
    void set(const float& x, const float& y, const float& z, const float& w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct Aabb_00c98c80 {
    Vec_00c98c80 m_kMinimumCorner;
    Vec_00c98c80 m_kMaximumCorner;
};

struct Line_00c98c80 {
    Vec_00c98c80 a;
    Vec_00c98c80 b;
};

struct Disp_00c98c80 {
    void hkDebugDisplay_displayLine(const Vec_00c98c80* a, const Vec_00c98c80* b, int p2, int p3, int p4);
    void DrawAABBEdges(const Aabb_00c98c80* box, int p2, int p3, int p4);
};

// Builds the 12 edge lines of the AABB box and draws each with FUN_00c986c0.
// @fnv 0x00c98c80
// src: GUESS 0x00c98c80 (confidence: medium)
void Disp_00c98c80::DrawAABBEdges(const Aabb_00c98c80* box, int p2, int p3, int p4)
{
    const float* pMin = box->m_kMinimumCorner.m_vComponents.m128_f32;
    const float* pMax = box->m_kMaximumCorner.m_vComponents.m128_f32;
    Line_00c98c80 aabbEdges[12];
    aabbEdges[0].a.set(pMin[0], pMin[1], pMin[2], DAT_01011d78);
    aabbEdges[0].b.set(pMin[0], pMax[1], pMin[2], DAT_01011d78);
    aabbEdges[1].a.set(pMin[0], pMin[1], pMin[2], DAT_01011d78);
    aabbEdges[1].b.set(pMin[0], pMin[1], pMax[2], DAT_01011d78);
    aabbEdges[2].a.set(pMin[0], pMin[1], pMin[2], DAT_01011d78);
    aabbEdges[2].b.set(pMax[0], pMin[1], pMin[2], DAT_01011d78);
    aabbEdges[3].a.set(pMax[0], pMax[1], pMax[2], DAT_01011d78);
    aabbEdges[3].b.set(pMax[0], pMax[1], pMin[2], DAT_01011d78);
    aabbEdges[4].a.set(pMax[0], pMax[1], pMax[2], DAT_01011d78);
    aabbEdges[4].b.set(pMin[0], pMax[1], pMax[2], DAT_01011d78);
    aabbEdges[5].a.set(pMax[0], pMax[1], pMax[2], DAT_01011d78);
    aabbEdges[5].b.set(pMax[0], pMin[1], pMax[2], DAT_01011d78);
    aabbEdges[6].a.set(pMin[0], pMax[1], pMin[2], DAT_01011d78);
    aabbEdges[6].b.set(pMax[0], pMax[1], pMin[2], DAT_01011d78);
    aabbEdges[7].a.set(pMin[0], pMax[1], pMin[2], DAT_01011d78);
    aabbEdges[7].b.set(pMin[0], pMax[1], pMax[2], DAT_01011d78);
    aabbEdges[8].a.set(pMax[0], pMax[1], pMin[2], DAT_01011d78);
    aabbEdges[8].b.set(pMax[0], pMin[1], pMin[2], DAT_01011d78);
    aabbEdges[9].a.set(pMin[0], pMax[1], pMax[2], DAT_01011d78);
    aabbEdges[9].b.set(pMin[0], pMin[1], pMax[2], DAT_01011d78);
    aabbEdges[10].a.set(pMin[0], pMin[1], pMax[2], DAT_01011d78);
    aabbEdges[10].b.set(pMax[0], pMin[1], pMax[2], DAT_01011d78);
    aabbEdges[11].a.set(pMax[0], pMin[1], pMax[2], DAT_01011d78);
    aabbEdges[11].b.set(pMax[0], pMin[1], pMin[2], DAT_01011d78);

    for (int i = 0; i < 12; i++)
    {
        hkDebugDisplay_displayLine(&aabbEdges[i].a, &aabbEdges[i].b, p2, p3, p4);
    }
}

struct Xf_00c996e0 {
    LocalM128 c0;
    LocalM128 c1;
    LocalM128 c2;
    void SetFromInput_Thunk(const hkQsTransform& a);
};

struct Pose_00c996e0 {
    void ApplyRotation(const Xf_00c996e0& t, int b, int c, int d, int e, int g);
    void ProcessState_00c996e0(const hkQsTransform& a, int b, int c, int d, int e, int g);
};

// Converts an hkQsTransform into a local Xf_00c996e0 and forwards it to ApplyRotation with the remaining parameters.
// @fnv 0x00c996e0
// src: GUESS 0x00c996e0 (confidence: low)
void Pose_00c996e0::ProcessState_00c996e0(const hkQsTransform& a, int b, int c, int d, int e, int g)
{
    Xf_00c996e0 t;
    t.SetFromInput_Thunk(a);
    ApplyRotation(t, b, c, d, e, g);
}

extern __declspec(thread) unsigned int t_uiMemContextCAA;

inline unsigned int GetMemContextCAA()
{
    return t_uiMemContextCAA;
}

inline void SetMemContextCAA(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextCAA = m_uiGeometryShaderFlags;
}

inline AutoMemContext::AutoMemContext(int context)
{
    m_eMemoryContext = static_cast<MEM_CONTEXT>(GetMemContextCAA());
    SetMemContextCAA(context);
}

inline AutoMemContext::~AutoMemContext()
{
    SetMemContextCAA(m_eMemoryContext);
}





struct __declspec(align(16)) hkVector4CAA {
    LocalM128 m_vComponents;
    inline hkVector4CAA& operator=(const hkVector4CAA& v) { m_vComponents = v.m_vComponents; return *this; }
};



class ShapeChildCAA {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual hkReferencedObject* v0C();
};

class ShapeCAA : public hkReferencedObject {
public:
    ShapeCAA(); // FUN_00cb9090
    static void operator delete(void* p, unsigned int nbytes)
    {
        hkReferencedObject::operator delete(p, nbytes);
    }

    void SetReferencedObject(hkReferencedObject* obj);

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4CAA m_v20;
    hkVector4CAA m_v30;
    hkVector4CAA m_v40;
    hkVector4CAA m_v50;
    hkVector4CAA m_v60;
    hkVector4CAA m_v70;
    hkVector4CAA m_v80;
    hkVector4CAA m_v90;
    unsigned char unkA0;
    unsigned char unkA1;
    unsigned char m_flagA2;
    unsigned char unkA3;
    int unkA4;
    int unkA8;
    int unkAC;
    ShapeChildCAA* m_pChildAtom;
    int unkB4;
    int unkB8;
    float m_fBC;
    float unkC0;
    float m_fC4;
    float m_fC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
};

struct ShapeCinfoCAA {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_vScale;
};

void __cdecl hkHingeConstraintCinfo_ApplyScale(float scale, ShapeCAA* shape);

class ShapeClonerCAA {
public:
    ShapeCAA* ReleaseObject(ShapeCAA* shape, ShapeCinfoCAA* cinfo);
    ShapeCAA* hkLimitedHingeConstraintCinfo_CloneData(ShapeCAA* dst, ShapeCinfoCAA* cinfo);

    int unk00;
    ShapeCAA* m_pCollisionShape;
};

// Copies fields from m_pCollisionShape into dst (new if null), applies cinfo->m_vScale if not 1.0, copies the child atom, and returns FUN_00c8a1b0(dst, cinfo).
// @fnv 0x00caa250
// src: XBOX_PDB 0x00caa250
ShapeCAA* ShapeClonerCAA::hkLimitedHingeConstraintCinfo_CloneData(ShapeCAA* apDstShape, ShapeCinfoCAA* cinfo)
{
    AutoMemContext kContext(0x10);
    ShapeCAA* src = m_pCollisionShape;
    if (!apDstShape)
    {
        apDstShape = new ShapeCAA;
    }
    apDstShape->m_v20 = src->m_v20;
    apDstShape->m_v30 = src->m_v30;
    apDstShape->m_v40 = src->m_v40;
    apDstShape->m_v50 = src->m_v50;
    apDstShape->m_v60 = src->m_v60;
    apDstShape->m_v70 = src->m_v70;
    apDstShape->m_v80 = src->m_v80;
    apDstShape->m_v90 = src->m_v90;
    apDstShape->m_fBC = src->m_fBC;
    apDstShape->m_fC4 = src->m_fC4;
    apDstShape->m_fC8 = src->m_fC8;
    float scale = cinfo->m_vScale;
    if (scale != 1.0f)
    {
        hkHingeConstraintCinfo_ApplyScale(scale, apDstShape);
    }
    ShapeChildCAA* pChildAtom = src->m_pChildAtom;
    if (pChildAtom)
    {
        hkReferencedObject* obj = pChildAtom->v0C();
        apDstShape->SetReferencedObject(obj);
        obj->removeReference();
        apDstShape->m_flagA2 = src->m_flagA2;
    }
    return ReleaseObject(apDstShape, cinfo);
}

class hkAabb;
namespace BatchAdd {
// Opaque tag preserves the existing external call signature.
class hkMemory {
public:
    virtual ~hkMemory() throw();
    virtual void m04() throw();
    virtual void m08() throw();
    virtual void m0C() throw();
    virtual void deallocateChunk(void* p, int nbytes) throw();
};


struct BroadPhaseCastCollector {
    void* m_kPointA;
    void* m_kPointB;
};

template <typename T>
class StackAllocatedArray : public hkArrayBase<T> {
public:
    void* m_initialBuffer;

    __forceinline StackAllocatedArray(int capacity) throw() {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
        hkThreadMemory* tm = (hkThreadMemory*)::hkMemoryRouter_getInstance();
        void* cur = *(void**)tm;
        int numBytes = (capacity * sizeof(T) + 0x7f) & ~0x7f;
        *(void**)tm = (char*)cur + numBytes;
        this->m_data = (T*)cur;
        this->m_iCapacityState = capacity | 0x80000000;
        this->m_initialBuffer = cur;
    }

    __forceinline void ClearAndRelease(hkThreadMemory* tm) throw() {
        hkMemory* mem = *(hkMemory**)((char*)tm + 0x10);
        int cap = this->m_iCapacityState;
        this->m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) {
            mem->deallocateChunk(this->m_data, (cap & 0x3fffffff) * sizeof(T));
        }
        this->m_data = 0;
        this->m_iCapacityState = 0x80000000;
    }

    __forceinline ~StackAllocatedArray() throw() {
        void* const initialBuffer = this->m_initialBuffer;
        if (initialBuffer == this->m_data) {
            this->m_iElementCount = 0;
        }
        *(void**)::hkMemoryRouter_getInstance() = initialBuffer;
        this->ClearAndRelease((hkThreadMemory*)::hkMemoryRouter_getInstance());
    }

    __forceinline void setSizeUnchecked(int size) throw() {
        this->m_iElementCount = size;
    }
};


// Only the missing AABB-update call needs a local declaration.
struct PhantomAabbAccess : public ::hkpPhantom {
    void hkpPhantom_setBoundingVolumeData(hkAabb* aabb) throw();
};


struct BroadPhase {
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0C() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void UpdatePairs(const hkArray<void*>& handles, const hkArray<::hkAabb>& aabbs, hkArray<BroadPhaseCastCollector>& pairs) throw();
};

struct BroadPhaseDispatcher {
    void __thiscall hkpTypedBroadPhaseDispatcher_addPairs(BroadPhaseCastCollector* pairs, int numPairs, void* filter) throw();
};

struct PendingOp {
    unsigned char m_type;
    unsigned char m_uiStandInValue;
    unsigned char m_iValueAfterStandIn;
    unsigned char m_pAuxiliaryObject;
    hkpPhantom* const* m_kPhantoms;
    short m_iPhantomCount;
    short m_pad3;
};

struct WorldHelper : public hkpWorld {
    void __thiscall hkpWorld_queueOperation(void* op) throw();
    void __thiscall FUN_00c91120() throw();
    void __thiscall UpdateFields_00c91140() throw();

    void hkpWorld_addPhantomBatch(hkpPhantom* const* phantomBatch, int numPhantoms) throw();
};

// Adds a batch of phantoms to the world (queued as a pending op if locked), updates broad phase pairs, and passes them to FUN_00cf7080.
// @fnv 0x00c954e0
// src: HAVOK_LIB 0x00c954e0
void WorldHelper::hkpWorld_addPhantomBatch(hkpPhantom* const* phantomBatch, int numPhantoms) throw() {
    if ((m_iCriticalOperationsLockCount + m_iCriticalOperationsLockCountForPhantoms) != 0) {
        PendingOp op;
        op.m_type = 0x0f;
        op.m_kPhantoms = phantomBatch;
        op.m_iPhantomCount = (short)numPhantoms;
        hkpWorld_queueOperation(&op);
        return;
    }

    m_iCriticalOperationsLockCount++;

    StackAllocatedArray<void*> handles(numPhantoms);
    StackAllocatedArray<::hkAabb> aabbs(numPhantoms);
    aabbs.setSizeUnchecked(numPhantoms);
    handles.setSizeUnchecked(numPhantoms);

    for (int i = 0; i < numPhantoms; i++) {
        hkArray<hkpPhantom*>* const phantoms = (hkArray<hkpPhantom*>*)&m_kPhantoms;
        hkpPhantom* phantom = phantomBatch[i];
        if (!phantom->m_kCollidable.m_pMotionState) {
            phantom->m_kCollidable.m_pMotionState = (*(const void* (__thiscall**)(hkpPhantom*))(*(char**)phantom + 0x10))(phantom);
        }
        phantom->m_pOwningWorld = this;
        handles.m_data[i] = &phantom->m_kCollidable.m_kBroadPhaseHandle;
        (*(void (__thiscall**)(hkpPhantom*, ::hkAabb*))(*(char**)phantom + 0x18))(phantom, &aabbs.m_data[i]);
        static_cast<PhantomAabbAccess*>(phantom)->hkpPhantom_setBoundingVolumeData((hkAabb*)&aabbs.m_data[i]);
        phantom->addReference();

        phantoms->pushBack(phantom);

        NotifyPhantomAdded(this, phantom);
        phantom->firePhantomAdded();
    }

    StackAllocatedArray<BroadPhaseCastCollector> pairs(m_iBroadPhaseQuerySize);
    ((BroadPhase*)m_pJobSemaphore)->UpdatePairs(static_cast<hkArray<void*>&>(static_cast<hkArrayBase<void*>&>(handles)), static_cast<hkArray<::hkAabb>&>(static_cast<hkArrayBase<::hkAabb>&>(aabbs)), static_cast<hkArray<BroadPhaseCastCollector>&>(static_cast<hkArrayBase<BroadPhaseCastCollector>&>(pairs)));

    void* filter = m_pCollisionFilter ? (char*)m_pCollisionFilter + 8 : 0;
    ((BroadPhaseDispatcher*)m_pBroadPhaseDispatcher)->hkpTypedBroadPhaseDispatcher_addPairs(pairs.m_data, pairs.m_iElementCount, filter);

    m_iCriticalOperationsLockCount--;
    if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
        if (m_iPendingOperationCount != 0) {
            FUN_00c91120();
        }
        if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount != 0) {
            UpdateFields_00c91140();
        }
    }
}

}

struct PendingCalls_00c97510 { void FUN_00c91120(); void UpdateFields_00c91140(); };


struct hkAllocQ70 {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void deallocate(void* p, int numBytes);
};


template <typename T>
inline void ConstructWithCopyC97510(T* pDst, int iCount, const T& kItem)
{
    for (int i = 0; i < iCount; ++i)
        pDst[i] = kItem;
}
template <typename T>
inline void PushBackC97510(::hkArray<T>& kArray, const T& kItem)
{
    ::hkThreadMemory* pkMemory = (::hkThreadMemory*)hkMemoryRouter_getInstance();
    if (kArray.m_iElementCount == (kArray.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(*(void**)((char*)pkMemory + 0x10), &kArray, sizeof(T));
    ConstructWithCopyC97510(kArray.m_data + kArray.m_iElementCount, 1, kItem);
    kArray.m_iElementCount++;
}

struct hkpWorldDecomp;

template <typename T>
struct InplaceArray4 : ::hkArrayBase<T> {
    T m_kStorage[4];

    InplaceArray4() {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000004;
    }

    void ClearAndRelease() {
        ::hkThreadMemory* tm = (::hkThreadMemory*)hkMemoryRouter_getInstance();
        hkAllocQ70* mem = (hkAllocQ70*)*(void**)((char*)tm + 0x10);
        int cap = this->m_iCapacityState;
        this->m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) {
            mem->deallocate(this->m_data, (cap & 0x3fffffff) * sizeof(T));
        }
    }
};


void __cdecl NotifyActionRemoved(::hkpWorld* world, hkpAction* action);

struct hkpWorldDecomp : ::hkpWorld {
    void RemoveActionFromWorld(hkpAction* action);
};


// Removes an hkpAction from its owning world, detaches it from its entities and island, then flushes pending operations if the critical lock count reaches zero.
// @fnv 0x00c97510
// src: GUESS 0x00c97510 (confidence: medium)
void hkpWorldDecomp::RemoveActionFromWorld(hkpAction* action)
{
    action->FUN_00c90510();
    this->m_iCriticalOperationsLockCount++;
    NotifyActionRemoved(this, action);

    {
        InplaceArray4<hkpEntity*> entities;
        action->GetEntities(static_cast<hkArray<hkpEntity*>&>(static_cast<hkArrayBase<hkpEntity*>&>(entities)));

        for (int i = 0; i < entities.m_iElementCount; ++i)
        {
            hkpEntity* entity = entities.m_data[i];
            int idx = entity->m_ppActions.indexOf(action);
            entity->m_ppActions.removeAt(idx);
        }

        hkpSimulationIsland* island = action->m_pCurrentSimulationIsland;
        island->RemoveEntry(action);

        action->m_pOwningWorld = 0;
        action->FUN_00c905b0();

        ::hkpWorld* w = *(::hkpWorld**)((char*)island + 0x18);
        if (*(unsigned short*)((char*)island + 0x22) == 0xffff)
        {
            *(unsigned short*)((char*)island + 0x22) = (unsigned short)w->m_kDirtySimulationIslands.m_iElementCount;
            PushBackC97510(w->m_kDirtySimulationIslands, (void*)island);
        }

        entities.ClearAndRelease();
    }

    this->m_iCriticalOperationsLockCount--;
    if (this->m_iCriticalOperationsLockCount == 0 && !this->m_bBlockExecutingPendingOperations)
    {
        if (this->m_iPendingOperationCount != 0)
        {
            ((PendingCalls_00c97510*)this)->FUN_00c91120();
        }
        if (this->m_iPendingOperationQueueCount == 1 && this->m_iQueuedOperationCount != 0)
        {
            ((PendingCalls_00c97510*)this)->UpdateFields_00c91140();
        }
    }

    action->FUN_00c905b0();
}

struct FUN_00c91210_Class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    void* m_40;
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    void* m_60;
    void* m_64;
    void* m_68;
    void* m_6c;
    void* m_70;
    void* m_74;
    void* m_78;
    void* m_7c;
    void* m_80;
    void* m_84;
    void* m_88;
    void* m_8c;
    void* m_90;
    void* m_94;
    void* m_98;
    void* m_9c;
    void* m_a0;
    void* m_a4;
    void* m_a8;
    void* m_ac;
    void* m_b0;
    void* m_b4;
    void* m_b8;
    void hkpWorld_unlockIslandForConstraintUpdate(void*);
};
// @fnv 0x00c91210
// src: XBOX_PDB 0x00c91210
void FUN_00c91210_Class::hkpWorld_unlockIslandForConstraintUpdate(void* cs)
{
    if (m_b8)
        LeaveCriticalSection(m_b8);
}

struct FUN_00c91180_Helper {
    void IncrementCounter();
    void hkpWorld_unlock();
};
struct FUN_00c91b70_Class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* hkpWorld_integrate(float f);
};
// Between FUN_00c91180 and FUN_00c91190, calls vtable entry 4 of the object at m_8 with f and returns its result.
// @fnv 0x00c91b70
// src: HAVOK_LIB 0x00c91b70
void* FUN_00c91b70_Class::hkpWorld_integrate(float afValue)
{
    ((FUN_00c91180_Helper*)this)->IncrementCounter();
    void* p = ((void* (__thiscall*)(void*, float))(*((void***)m_8))[4])(m_8, afValue);
    ((FUN_00c91180_Helper*)this)->hkpWorld_unlock();
    return p;
}

namespace AdvanceTimeDetail {
struct WorldLock {
    void __thiscall IncrementCounter();
    void __thiscall hkpWorld_unlock();
};

struct Simulation {
    virtual ~Simulation();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(void*, const hkClass*) const;
    virtual int SimulateForDeltaTime(float);
    virtual int integrate(float);
    virtual int collide();
    virtual int AdvanceSimulationTime();
};
}

struct WorldAdvanceEntry : hkpWorld {
    int hkpWorld_advanceTime();
};

// Calls FUN_00c91180, then a virtual method on m_pSimulation, then FUN_00c91190, and returns the virtual method's result.
// @fnv 0x00c91bd0
// src: HAVOK_LIB 0x00c91bd0
int WorldAdvanceEntry::hkpWorld_advanceTime()
{
    reinterpret_cast<AdvanceTimeDetail::WorldLock*>(this)->IncrementCounter();
    int result = reinterpret_cast<AdvanceTimeDetail::Simulation*>(m_pSimulation)->AdvanceSimulationTime();
    reinterpret_cast<AdvanceTimeDetail::WorldLock*>(this)->hkpWorld_unlock();
    return result;
}
