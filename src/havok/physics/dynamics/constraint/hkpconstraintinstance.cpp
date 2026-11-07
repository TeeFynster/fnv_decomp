
// src/havok/physics/dynamics/constraint/hkpconstraintinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/hkpconstraintinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// VC9 treats the SDK's integer SIMD lanes as /GS buffers. This unit uses only float lanes.
#define _INCLUDED_MM2
// Exe 0x00cf30f0 FUN_00cf30f0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;

#include "../../../../../include/hkpConstraintInstance.h"
#include "../../../../../include/hkpEntity.h"
#include "../../../../../include/hkpWorld.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkpConstraintData.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkStringPtr.h"
#include "../../../../../include/hkpModifierConstraintAtom.h"

void __cdecl EnableConstraintsAndZeroArrays(void* a, void* b);

// @fnv 0x00cf3d90
// src: COMMUNITY 0x00cf3d90
__declspec(noinline) void __fastcall hkpConstraintInstance_enable(hkpConstraintInstance* self)
{
    EnableConstraintsAndZeroArrays(self, self->m_pOwnerObject);
}

// @fnv 0x00cf3070
void __fastcall SetActive(hkpConstraintInstance* self, int, bool active)
{
    self->m_priority = active;
    void* p = self->m_pConstraintInternal;
    if (p)
        *(char*)((char*)p + 0x13) = active;
}

void __cdecl hkpWorldOperationUtil_removeConstraintImmediately(void* a, void* b, int c);

// If the owner is set, calls FUN_00cb3dd0 with the pointer at arg+8, this, and 1.
// @fnv 0x00cf3090
void hkpConstraintInstance::vf04(void* arg)
{
    if (m_pOwnerObject)
        hkpWorldOperationUtil_removeConstraintImmediately(*(void**)((char*)arg + 8), this, 1);
}

void __cdecl hkpResponseModifier_disableConstraint(void*, void*);
// @fnv 0x00cf3da0
// src: COMMUNITY 0x00cf3da0
__declspec(noinline) void __fastcall hkpConstraintInstance_disable(hkpConstraintInstance* self)
{
    hkpResponseModifier_disableConstraint(self, self->m_pOwnerObject);
}

// @fnv 0x00cf3000
void __fastcall ReplaceReference(hkpConstraintInstance* self, int, void* apOldRef, void* apNewRef)
{
    int idx = (apOldRef != self->m_kActorEntries[0]) ? 1 : 0;
    ((hkReferencedObject*)apNewRef)->addReference();
    if (apOldRef)
        ((hkReferencedObject*)apOldRef)->removeReference();
    self->m_kActorEntries[idx] = static_cast<hkpEntity*>(apNewRef);
}

namespace fnv_00cf3040 {

// Scans two pointers at this+0x14 and, when one matches the pointer at arg+0x24, calls removeReference on it and clears that slot.
// @fnv 0x00cf3040
void __fastcall RemoveReferenceFromSlots(hkpConstraintInstance* self, int, void* arg)
{
    for (int i = 0; i < 2; ++i)
    {
        hkReferencedObject* p = (hkReferencedObject*)*(reinterpret_cast<void**>(self->m_kActorEntries) + i);
        if (p == *(hkReferencedObject**)((char*)arg + 0x24))
        {
            p->removeReference();
            self->m_kActorEntries[i] = 0;
        }
    }
}
}  // namespace fnv_00cf3040

namespace fnv_00cf3e60 {

// @fnv 0x00cf3e60
// src: HAVOK_LIB 0x00cf3e60
void __fastcall hkpConstraintInstance_pointNullsToFixedRigidBody(hkpConstraintInstance* self)
{
    for (int i = 0; i < 2; ++i)
    {
        if (self->m_kActorEntries[i] == 0)
        {
            void* other = reinterpret_cast<void*>(reinterpret_cast<unsigned int>(self->m_kActorEntries[1]) ^
                                                  reinterpret_cast<unsigned int>(self->m_kActorEntries[0]) ^
                                                  reinterpret_cast<unsigned int>(self->m_kActorEntries[i]));

            if (other != 0)
            {
                void* constraint = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(other) + 0x08);

                if (constraint != 0)
                {
                    void* referenced = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(constraint) + 0x24);

                    self->m_kActorEntries[i] = static_cast<hkpEntity*>(referenced);
                    reinterpret_cast<hkReferencedObject*>(referenced)->addReference();
                }
            }
        }
    }
}
}  // namespace fnv_00cf3e60

// @fnv 0x00cf2f90
// src: COMMUNITY 0x00cf2f90
void __stdcall nullsub_55(int)
{}

// @fnv 0x00cf2fa0
// src: COMMUNITY 0x00cf2fa0
void __stdcall nullsub_56(int)
{}

// @fnv 0x00cf2fb0
// src: HAVOK_LIB 0x00cf2fb0
__declspec(noinline) hkBool hkpConstraintInstance::isConstrainedToWorld() const throw()
{
    return m_kActorEntries[1] == 0 ||
           (m_kActorEntries[0]->m_pOwningWorld &&
            m_kActorEntries[1] == static_cast<hkpWorld*>(m_kActorEntries[0]->m_pOwningWorld)->m_pFixedRigidBody);
}

namespace fnv_00cf2fe0 {

int __cdecl FindModifierConstraintAtom(const void* pvObject, int iType);

// @fnv 0x00cf2fe0
// src: HAVOK_LIB 0x00cf2fe0
hkBool* __fastcall hkpConstraintInstance_isEnabled(const hkpConstraintInstance* self, int, hkBool* result)
{
    result->m_cBooleanValue = FindModifierConstraintAtom(self, 0x1b) == 0;
    return result;
}
}  // namespace fnv_00cf2fe0

static inline int FindListenerIndex(const hkpConstraintInstance* self, void* item)
{
    for (int i = 0; i < self->m_kListeners.m_iElementCount; ++i)
    {
        if (static_cast<void**>(self->m_kListeners.m_data)[i] == item)
            return i;
    }
    return -1;
}

// Clears the matching listener slot.
// @fnv 0x00cf30b0
// src: HAVOK_LIB 0x00cf30b0
void __fastcall hkpConstraintInstance_removeConstraintListener(hkpConstraintInstance* self, int, void* apItem)
{
    static_cast<void**>(self->m_kListeners.m_data)[FindListenerIndex(self, apItem)] = 0;
}

// @fnv 0x00cf3dd0
// src: HAVOK_LIB 0x00cf3dd0
int __fastcall hkpConstraintInstance_getSimulationIsland(const hkpConstraintInstance* self)
{
    const hkpEntity* pkEntity = self->m_kActorEntries[0];
    if (*reinterpret_cast<const unsigned char*>(&pkEntity->m_pMotionState.m_type) != 5)
        return reinterpret_cast<int>(pkEntity->m_pSimulationIsland);
    return reinterpret_cast<int>(self->m_kActorEntries[1]->m_pSimulationIsland);
}

// The per-thread router at 0x00c85750 is shared as hkMemoryRouter; its heap is at +0x10.

hkpConstraintData* __cdecl hkpConstraintDataCloningUtil_deepClone(const hkpConstraintData* pkData) throw();
hkpConstraintData* __cdecl hkpConstraintDataCloningUtil_cloneIfCanHaveMotors(const hkpConstraintData* pkData) throw();

class FUN_00cf3ea0 : public hkpConstraintInstance
{
  public:
    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        void* p = hkMemoryRouter::getInstance().heap().blockAlloc(uiSize);
        ((unsigned short*)p)[2] = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();
    FUN_00cf3ea0(hkpEntity* pkEntityA, hkpEntity* pkEntityB, hkpConstraintData* pkData,
                 ConstraintPriority ePriority) throw();
};

// The shared getData() returns const data; cloning also needs the mutable reference.
static inline hkpConstraintData* getCloneData(const hkpConstraintInstance* instance)
{
    return instance->m_data;
}

// Creates a new constraint instance from this one according to eMode, copying the name and returning the new instance.
// @fnv 0x00cf3fa0
// src: HAVOK_LIB 0x00cf3fa0
hkpConstraintInstance* hkpConstraintInstance::clone_00cf3fa0(hkpEntity* pkEntityA, hkpEntity* pkEntityB,
                                                               int eCloneMode) const throw()
{
    hkpConstraintInstance* pkInstance;
    if (eCloneMode == CLONE_INSTANCES_ONLY)
    {
        if (isConstrainedToWorld().m_cBooleanValue)
        {
            hkpConstraintData* pkData = hkpConstraintDataCloningUtil_deepClone(getCloneData(this));
            pkInstance = new FUN_00cf3ea0(pkEntityA, 0, pkData, getPriority());
            pkData->removeReference();
        }
        else
            pkInstance = new FUN_00cf3ea0(pkEntityA, pkEntityB, getCloneData(this), getPriority());
    }
    else if (eCloneMode == CLONE_DATAS_WITH_MOTORS)
    {
        hkpConstraintData* pkData = hkpConstraintDataCloningUtil_cloneIfCanHaveMotors(getCloneData(this));
        if (!pkData)
        {
            pkData = getCloneData(this);
            pkData->FUN_00c90510();
        }
        pkInstance = new FUN_00cf3ea0(pkEntityA, pkEntityB, pkData, getPriority());
        pkData->removeReference();
    }
    else
        pkInstance = new FUN_00cf3ea0(pkEntityA, pkEntityB, getCloneData(this), getPriority());
    pkInstance->m_name.Assign((const char*)((hkUlong)m_name.m_pcText & ~1));
    return pkInstance;
}

namespace fnv_00cf40b0 {
extern void* DAT_010cc040;
extern void* DAT_0102e388;

void __cdecl hkpConstraintCallbackUtil_fireConstraintDeleted(void*) throw();
static inline void hkDeallocate(void* p, int size) throw()
{
    hkMemoryRouter::getInstance().heap().blockFree(p, size);
}

// @fnv 0x00cf40b0
// src: GUESS 0x00cf40b0 (confidence: low)
__declspec(noinline) void __fastcall hkpConstraintInstance_ProcessEntries_00cf40b0(hkpConstraintInstance* self)
{
    *(void**)self = &DAT_010cc040;
    hkpConstraintCallbackUtil_fireConstraintDeleted(self);
    if (self->m_kActorEntries[0])
        reinterpret_cast<hkReferencedObject*>(self->m_kActorEntries[0])->removeReference();
    if (self->m_kActorEntries[1])
        reinterpret_cast<hkReferencedObject*>(self->m_kActorEntries[1])->removeReference();
    hkpModifierConstraintAtom* mod = self->m_pConstraintModifier;
    if (mod != 0 && mod->m_type >= 0x17)
    {
        do
        {
            hkpModifierConstraintAtom* cur = mod;
            mod = cur->m_pChildAtom;
            hkDeallocate(cur, cur->m_usModifierAtomSize);
        } while (mod->m_type >= 0x17);
    }
    if (self->m_data)
        self->m_data->removeReference();
    self->m_name.release();
    if ((self->m_kListeners.m_iCapacityState & 0x8000) == 0)
    {
        int capacity = self->m_kListeners.m_iCapacityState & 0x3fff;
        hkDeallocate(self->m_kListeners.m_data, capacity * 4);
    }
    *(void**)self = &DAT_0102e388;
}
}  // namespace fnv_00cf40b0

namespace fnv_00cf4160 {

// Destructs the object, then frees it via operator delete when uiFlags has bit 0 set, and returns this.
// @fnv 0x00cf4160
hkpConstraintInstance* __fastcall FUN_00cf4160(hkpConstraintInstance* self, int, unsigned int uiFlags) throw()
{
    fnv_00cf40b0::hkpConstraintInstance_ProcessEntries_00cf40b0(self);
    if (uiFlags & 1)
        hkMemoryRouter::getInstance().heap().blockFree(self, self->m_usMemSizeAndFlags);
    return self;
}
}  // namespace fnv_00cf4160

// Walks the modifier atom chain of a constraint instance and returns the first atom whose m_type equals type, or null if none matches.
// @fnv 0x00d277c0
hkpModifierConstraintAtom* __cdecl FindModifierConstraintAtom(hkpConstraintInstance* aConstraintInstance,
                                                              unsigned int type)
{
    hkpModifierConstraintAtom* atom = aConstraintInstance->m_pConstraintModifier;
    if (!atom)
        return 0;

    while (atom->m_type != type)
    {
        if (atom->m_pChildAtom->m_type < 0x17)
            return 0;
        atom = atom->m_pChildAtom;
    }
    return atom;
}

extern "C" void __cdecl hkSmallArrayUtil__reserveMore(void* apvArray, int iSizeElem);
extern "C" void _ReadWriteBarrier();

static __forceinline void PutListener(hkpConstraintInstanceSmallArraySerializeOverrideType* array, void* a)
{
        unsigned short n = array->m_iElementCount;

        int i = 0;
        if (i < n)
        {
            void** d = static_cast<void**>(array->m_data);
            void** p = d;
            do
            {
                if (*p == 0)
                {
                    if (i >= 0)
                    {
                        d[i] = a;
                        return;
                    }
                    break;
                }
                _ReadWriteBarrier();
                i++;
                p++;
            } while (i < array->m_iElementCount);
        }
        if (n == (array->m_iCapacityState & 0x3fff))
            hkSmallArrayUtil__reserveMore(array, 4);
        static_cast<void**>(array->m_data)[array->m_iElementCount++] = a;
    }

// Adds the given pointer to the listener array.
// @fnv 0x00cf3df0
void __fastcall AddListener(hkpConstraintInstance* self, int, void* apItem)
{
    PutListener(&self->m_kListeners, apItem);
}

extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, LocalM128);
struct Matrix4f;
struct CVector
{
    LocalM128 m;
    void setTransformedPos_00c7f640(Matrix4f*, CVector*);
    void hkVector4_setRotatedDir(Matrix4f*, CVector*);
};
struct __declspec(align(16)) Matrix4f
{
    CVector c0, c1, c2, c3;
};
struct ConstraintReference;
struct ConstraintReferencedBase
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual unsigned getType() const;
    unsigned unk04;
};
struct ConstraintReference : ConstraintReferencedBase
{
    unsigned unk08, unk0c, unk10, unk14;
    ConstraintReference* child18;
    unsigned unk1c;
    Matrix4f a, b, c, d;
    unsigned unk120;
    ConstraintReference* hkpMalleableConstraintData_getWrappedConstraintData();
    void InitializeFields_00d541b0(CVector*, CVector*);
    void SetConstraintPivotFrames(CVector*, CVector*, CVector*, CVector*);
    void FUN_00cb8da0(CVector*, CVector*, CVector*, CVector*, CVector*, CVector*);
    void SetBasis(CVector*, CVector*, CVector*);
    void FUN_00d4fba0(CVector*, CVector*, CVector*, CVector*, CVector*, CVector*);
    void FUN_00cded30(CVector*, CVector*, CVector*, CVector*, CVector*, CVector*);
    void FUN_00d4e960(CVector*, CVector*, CVector*, CVector*, CVector*, CVector*);
};
struct CPlaneData
{
    void* vptr;
    unsigned unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Matrix4f a;
    CVector axes[3];
    CVector position;
    unsigned char unkA0, unkA1, axis, unkA3;
};
struct CDirectData
{
    void* vptr;
    unsigned unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    CVector axis, position;
    float unk40, value;
};
struct CInstance
{
    unsigned unk00, unk04, unk08;
    ConstraintReference* data;
    hkBool isConstrainedToWorld();
    void ApplyTransformToWorldConstraint(Matrix4f*);
};
static __forceinline void point(CVector& v, Matrix4f* t)
{
    v.setTransformedPos_00c7f640(t, &v);
}
static __forceinline void rotate(CVector& v, Matrix4f* t)
{
    v.hkVector4_setRotatedDir(t, &v);
}
static __forceinline CVector getVector(const CVector& s)
{
    return s;
}
static __forceinline void copyTransform(Matrix4f& d, const Matrix4f& s)
{
    CVector c0 = s.c0, c1 = s.c1, c2 = s.c2, c3 = s.c3;
    d.c0.m = c0.m;
    d.c1.m = c1.m;
    d.c2.m = c2.m;
    d.c3.m = c3.m;
}

// Applies the given Matrix4f transform to the constraint data referenced by this instance, dispatching on the constraint type.
// @fnv 0x00cf30f0
// src: GUESS 0x00cf30f0 (confidence: medium)
void CInstance::ApplyTransformToWorldConstraint(Matrix4f* apTransform)
{
    if (!isConstrainedToWorld())
        return;
    ConstraintReference* p = data;
    for (;;)
        switch (p->getType())
        {
        case 12:
            p = p->child18;
            break;
        case 13:
            p = p->hkpMalleableConstraintData_getWrappedConstraintData();
            break;
        case 0:
            point(p->a.c1, apTransform);
            p->InitializeFields_00d541b0(&p->a.c0, &p->a.c1);
            return;
        case 1: {
            Matrix4f a, b;
            copyTransform(a, p->a);
            copyTransform(b, p->b);
            CVector ax = a.c0, bx = b.c0;
            point(b.c3, apTransform);
            rotate(bx, apTransform);
            p->SetConstraintPivotFrames(&a.c3, &b.c3, &ax, &bx);
            return;
        }
        case 2: {
            Matrix4f a, b;
            copyTransform(a, p->a);
            copyTransform(b, p->b);
            CVector ax = a.c0, bx = b.c0, ay = a.c1, by = b.c1;
            point(b.c3, apTransform);
            rotate(bx, apTransform);
            rotate(by, apTransform);
            p->FUN_00cb8da0(&a.c3, &b.c3, &ax, &bx, &ay, &by);
            return;
        }
        case 14: {
            CPlaneData* __restrict q = (CPlaneData*)p;
            CVector a = q->a.c3, b = q->position, axis = q->axes[q->axis];
            point(b, apTransform);
            rotate(axis, apTransform);
            p->SetBasis(&a, &b, &axis);
            return;
        }
        case 6: {
            Matrix4f a, b;
            copyTransform(a, p->a);
            copyTransform(b, p->b);
            CVector ap = a.c0, aa = a.c1, at = a.c3, bp = b.c0, ba = b.c1, bt = b.c3;
            point(bt, apTransform);
            rotate(bp, apTransform);
            rotate(ba, apTransform);
            p->FUN_00d4fba0(&at, &bt, &ap, &bp, &aa, &ba);
            return;
        }
        case 7: {
            Matrix4f a, b;
            copyTransform(a, p->a);
            copyTransform(b, p->b);
            Matrix4f& ta = p->a;
            Matrix4f& tb = p->b;
            CVector& b1 = tb.c1;
            point(b.c3, apTransform);
            rotate(b1, apTransform);
            rotate(tb.c0, apTransform);
            p->FUN_00cded30(&a.c3, &b.c3, &ta.c1, &b1, &ta.c0, &tb.c0);
            return;
        }
        case 8: {
            CDirectData* q = (CDirectData*)p;
            CVector axis = q->axis, position = q->position;
            float value = q->value;
            point(position, apTransform);
            q->axis.m = axis.m;
            q->position.m = position.m;
            q->value = value;
            return;
        }
        case 9: {
            CVector a = p->a.c3, b = p->b.c3, ax = p->b.c0, ay = p->c.c3, by = p->d.c2;
            point(b, apTransform);
            CVector az = p->d.c3;
            rotate(ax, apTransform);
            rotate(by, apTransform);
            rotate(az, apTransform);
            p->FUN_00d4e960(&a, &b, &ay, &by, &ax, &az);
            return;
        }
        default:
            return;
        }
}

extern "C"
{
    hkVector4* __cdecl GetDispatchTarget(void* obj);
    hkVector4* __cdecl GetShapeData(void* obj);
}

struct TargetObj
{
    char pad[0x18];
    void* unk18;
};

struct ReceiverObj
{
    void setTransformedPos_00c7f640(void* pTarget, hkVector4* pVec);
};

class FUN_00cf3c90_cls
{
  public:
    char pad0[0xc];
    void* m_obj0C;
    char pad1[4];
    TargetObj* m_target14;
    TargetObj* m_target18;

    void hkpConstraintInstance_getPivotsInWorld(ReceiverObj* first, ReceiverObj* second);
};

// Copies two vectors obtained from m_obj0C, then calls FUN_00c7f640 on first and second with m_target14->unk18 and m_target18->unk18 and the matching vector.
// @fnv 0x00cf3c90
// src: XBOX_PDB 0x00cf3c90
void FUN_00cf3c90_cls::hkpConstraintInstance_getPivotsInWorld(ReceiverObj* apFirstReceiver, ReceiverObj* apSecondReceiver)
{
    LocalM128 vFirstVec = *(LocalM128*)GetDispatchTarget(m_obj0C);
    LocalM128 vSecondVec = *(LocalM128*)GetShapeData(m_obj0C);

    void* pSecondTargetPtr = m_target18->unk18;
    apFirstReceiver->setTransformedPos_00c7f640(m_target14->unk18, reinterpret_cast<hkVector4*>(&vFirstVec));
    apSecondReceiver->setTransformedPos_00c7f640(pSecondTargetPtr, reinterpret_cast<hkVector4*>(&vSecondVec));
}

union FUN_00cf3d00_Vec4
{
    LocalM128 m;
};

struct FUN_00cf3d00_Alloc
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    FUN_00cf3d00_Vec4 unk20;
    FUN_00cf3d00_Vec4 unk30;
};

struct FUN_00cf3d00_Buf
{
    unsigned short unk00;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    unsigned short unk10;
    unsigned short unk12;
    unsigned short unk14;
    unsigned short unk16;
    unsigned short unk18;
    unsigned short unk1A;
    unsigned short unk1C;
    unsigned short unk1E;
    FUN_00cf3d00_Vec4 unk20;
    FUN_00cf3d00_Vec4 unk30;
};

void* __cdecl FindModifierConstraintAtom(void* self, int size);
void __cdecl hkpWorldConstraintUtil_addModifier(void* a, void* b, void* c);

// Stores a and b in unk20 and unk30 of the atom found by FindModifierConstraintAtom(static_cast<void*>(self), 0x18), or of a new 0x40-byte buffer passed to FUN_00d27960.
// @fnv 0x00cf3d00
void __fastcall SetVec4Pair(hkpConstraintInstance* self, int, FUN_00cf3d00_Vec4* a, FUN_00cf3d00_Vec4* b)
{
    FUN_00cf3d00_Alloc* pAtom = (FUN_00cf3d00_Alloc*)FindModifierConstraintAtom(static_cast<void*>(self), 0x18);

    if (pAtom != 0)
    {
        pAtom->unk20.m = a->m;
        pAtom->unk30.m = b->m;
        return;
    }

    hkMemoryRouter* holder = &hkMemoryRouter::getInstance();
    FUN_00cf3d00_Buf* buf = (FUN_00cf3d00_Buf*)holder->m_heap->blockAlloc(0x40);

    if (buf != 0)
    {
        buf->unk00 = 0x18;
        buf->unk10 = 0x40;
    }
    else
    {
        buf = 0;
    }

    buf->unk20.m = a->m;
    buf->unk30.m = b->m;

    hkpWorldConstraintUtil_addModifier(self, self->m_pOwnerObject, buf);
}

extern char DAT_010cc040;

// Sets the vtable pointer, zeroes most fields, sets m_6 to 1, m_1c to flag, m_1d to 1, m_26 to 0x8000, m_34 to -16, and calls m_28.Init().
// @fnv 0x00cf3f40
// src: HAVOK_LIB 0x00cf3f40
hkpConstraintInstance* __fastcall hkpConstraintInstance_hkpConstraintInstance(hkpConstraintInstance* self, int, bool flag)
{
    int z = 0;
    *(void* volatile*)&*reinterpret_cast<void**>(self) = (void*)&DAT_010cc040;
    self->m_pOwnerObject = 0;
    self->m_pConstraintModifier = 0;
    *(volatile short*)&self->m_sReferenceCount = 1;
    *(volatile unsigned char*)&self->m_priority = flag;
    *(volatile unsigned char*)&self->m_bWantRuntime = 1;
    *(volatile unsigned char*)&self->m_eDestructionRemapInfo = z;
    _ReadWriteBarrier();
    *(volatile int*)&self->m_kListeners.m_data = z;
    self->m_kListeners.m_iElementCount = 0;
    self->m_kListeners.m_iCapacityState = 0x8000;
    self->m_name.Init();
    self->m_ulUserData = z;
    self->m_pConstraintInternal = 0;
    self->m_uiUniqueId = -16;
    return self;
}

// @fnv 0x00cf3db0
// src: HAVOK_LIB 0x00cf3db0
void __fastcall hkpConstraintInstance_setEnabled(hkpConstraintInstance* self, int, hkBool enabled)
{
    if (enabled)
    {
        hkpConstraintInstance_enable(self);
    }
    else
    {
        hkpConstraintInstance_disable(self);
    }
}
