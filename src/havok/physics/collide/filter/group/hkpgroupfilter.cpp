// src/havok/physics/collide/filter/group/hkpgroupfilter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/filter/group/hkpgroupfilter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkpGroupFilter.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpCdBody.h"
#include "../../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../../include/hkpCollidable.h"
#include "../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../include/hkpShapeCollection.h"
#include "../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../include/hkpShapeCollectionFilter.h"

inline const hkpShape* hkpCdBody::getShape() const
{
    return m_pCollisionShape;
}

inline unsigned int hkpCdBody::getShapeKey() const
{
    return m_uiCollisionShapeKey;
}

inline const hkpCdBody* hkpCdBody::getParent() const
{
    return m_parent;
}

__forceinline const hkpCollidable* hkpCdBody::getRootCollidable() const
{
    const hkpCdBody* body = this;
    while (body->m_parent)
        body = body->m_parent;
    return reinterpret_cast<const hkpCollidable*>(body);
}

__forceinline unsigned int hkpCollidable::GetFilterInfoForKey() const
{
    return m_kBroadPhaseHandle.m_uiCollisionFilterData;
}

inline hkBool32 hkpCollisionDispatcher::hasAlternateType(hkpShapeType type, hkpShapeType alternateType)
{
    return m_auiAlternateTypeFlags[type] & (1 << alternateType);
}

inline hkpShapeType hkpShape::getType() const
{
    return reinterpret_cast<const hkpShapeType&>(m_type);
}

extern int DAT_0102e388;
extern int DAT_010c3b80;
extern int DAT_010c3b8c;
extern int DAT_010c3b98;
extern int DAT_010c3bac;

struct FUN_00e48a80_struct
{
    int* p0;
    int* p1;
    int* p2;
    int* p3;
    int* p4;
    int* p5;
    void InitGroupFilterPointers();
};

// @fnv 0x00e48a80
void FUN_00e48a80_struct::InitGroupFilterPointers()
{
    p5 = &DAT_010c3b8c;
    p4 = &DAT_010c3bac;
    p3 = &DAT_010c3b98;
    p2 = &DAT_010c3b80;
    p0 = &DAT_0102e388;
}

// Local extension: the shared group header lacks ClearMaskedBits.
struct CollisionGroupMaskDisabler : public hkpGroupFilter
{
    void ClearMaskedBits(unsigned int, unsigned int);
};

// @fnv 0x00e48970
void CollisionGroupMaskDisabler::ClearMaskedBits(unsigned int auiMaskA, unsigned int auiMaskB)
{
    unsigned int* mask = m_uiCollisionGroupMasks;

    unsigned int bit = 1;
    unsigned int count = 32;

    do
    {
        if (auiMaskA & bit)
            *mask &= ~auiMaskB;

        if (auiMaskB & bit)
            *mask &= ~auiMaskA;

        ++mask;
        bit = (bit << 1) | (bit >> 31);
    } while (--count);
}

struct FUN_00e48830_class
{
    void ShouldCollide(int* value, int value0, int value1);
};

struct FUN_00e48b60_arg1
{
    int unknown_00[9];
    int value_24;
};

struct FUN_00e48b60_class
{
    int* ApplyWorldAndCollidableFilters(int* value, FUN_00e48b60_arg1* arg1, hkpCollidable* arg2);
};

// Applies the world-ray filter info and collidable filter info using the owner at this-0x14.
// @fnv 0x00e48b60
// src: GUESS 0x00e48b60 (confidence: medium)
int* FUN_00e48b60_class::ApplyWorldAndCollidableFilters(int* value, FUN_00e48b60_arg1* arg1, hkpCollidable* arg2)
{
    reinterpret_cast<FUN_00e48830_class*>(reinterpret_cast<char*>(this) - 0x14)
        ->ShouldCollide(value, arg1->value_24, arg2->GetFilterInfoForKey());
    return value;
}

// Local extension: the shared group header lacks ShouldCollide.
class GroupFilter : public hkpGroupFilter
{
  public:
    hkBool ShouldCollide(unsigned int infoA, unsigned int infoB);
};

// Checks whether two collision filter infos may collide, using group/subgroup masks or the group filter table.
// @fnv 0x00e48830
hkBool GroupFilter::ShouldCollide(unsigned int infoA, unsigned int infoB)
{
    if (((infoA ^ infoB) & 0xffff0000) == 0 && (infoA & 0xffff0000) != 0)
    {
        if ((((infoB >> 5) ^ infoA) & 0x3e0) == 0)
            return false;

        if ((((infoA >> 5) ^ infoB) & 0x3e0) == 0)
            return false;

        return true;
    }

    return (m_uiCollisionGroupMasks[infoA & 0x1f] & (1 << (infoB & 0x1f))) != 0;
}

struct FUN_00e488a0_data
{
    int unknown00;
    int unknown04;
    int unknown08;
    int unknown0c;
    int unknown10;
    int unknown14;
    int unknown18;
    int unknown1c;
    int value20;
};

struct FUN_00e488a0_class
{
    int* CallGetValueAndDispatch(int* value, FUN_00e488a0_data* data, int unused, hkpShapeContainer* object,
                                 int input);
};

// Applies the shape-key filter info and ray filter info using the owner at this-16.
// @fnv 0x00e488a0
int* FUN_00e488a0_class::CallGetValueAndDispatch(int* value, FUN_00e488a0_data* data, int unused,
                                                 hkpShapeContainer* object, int input)
{
    int result = object->GetFilterInfoForKey(input);
    FUN_00e48830_class* owner = reinterpret_cast<FUN_00e48830_class*>(reinterpret_cast<char*>(this) - 16);
    owner->ShouldCollide(value, data->value20, result);
    return value;
}

// Local extension: the shared group header lacks DisableCollisionPair.
class CollisionLayerMaskEditor : public hkpGroupFilter
{
public:
    void DisableCollisionPair(int iLayerA, int iLayerB);
};

// Clears the collision bit for iLayerB in row iLayerA and the bit for iLayerA in row iLayerB of the layer mask table.
// @fnv 0x00e48940
void CollisionLayerMaskEditor::DisableCollisionPair(int iLayerA, int iLayerB)
{
    m_uiCollisionGroupMasks[iLayerA] &= ~(1 << iLayerB);
    m_uiCollisionGroupMasks[iLayerB] &= ~(1 << iLayerA);
}

struct FUN_00e48ab0_class
{
    int* __thiscall EvaluateValue_00e48ab0(int* value, hkpCollidable* arg2, hkpCollidable* arg3);
};

// Applies the two collidable filter infos using the owner at this-8.
// @fnv 0x00e48ab0
// src: GUESS 0x00e48ab0 (confidence: low)
int* FUN_00e48ab0_class::EvaluateValue_00e48ab0(int* value, hkpCollidable* pFirstValue, hkpCollidable* pSecondValue)
{
    reinterpret_cast<FUN_00e48830_class*>(reinterpret_cast<char*>(this) - 8)
        ->ShouldCollide(value, pFirstValue->GetFilterInfoForKey(), pSecondValue->GetFilterInfoForKey());
    return value;
}

// The helper at 0x00d2d4b0 takes this 512-byte aligned scratch area; no shared buffer definition exists.
typedef __declspec(align(16)) unsigned int ShapeCollectionScratchBuffer[128];

// Only the dispatcher pointer at +0 is known here; no approved collision-input header exists.
class CollisionAgentContext
{
public:
    hkpCollisionDispatcher* m_pCollisionDispatcher;
};

const hkpShapeContainer* __cdecl Hkpbvtreeagent3_ForwardCall_00d2d4b0(const hkpCdBody* pkBody, ShapeCollectionScratchBuffer& kBuffer) throw();

// Local extension: the shared group class lacks ShouldCollide and collection-filter overrides.
class CollectionBodyCollisionFilter : public hkpGroupFilter
{
  public:
    hkBool ShouldCollide(hkUint32 uiInfoA, hkUint32 uiInfoB) const throw();
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& kInput, const hkpCdBody& kA,
                                             const hkpCdBody& kB, const hkpShapeContainer& kBContainer,
                                             hkUint32 uiBKey) const throw();
};

// Computes the collision filter info for both bodies, walking up the parent chain for alternate shape types, then tests the pair with ShouldCollide.
// @fnv 0x00e48b90
hkBool CollectionBodyCollisionFilter::IsCollisionEnabled(const CollisionAgentContext& kInput, const hkpCdBody& kA,
                                                     const hkpCdBody& kB, const hkpShapeContainer& kBContainer,
                                                     hkUint32 uiBKey) const throw()
{
    hkUint32 uiInfoB = kBContainer.GetFilterInfoForKey(uiBKey);
    if (uiInfoB == 0xffffffff)
        uiInfoB = kB.getRootCollidable()->GetFilterInfoForKey();

    hkUint32 uiInfoA;
    if (kA.getParent() == 0)
    {
        uiInfoA = kA.getRootCollidable()->GetFilterInfoForKey();
    }
    else
    {
        const hkpCdBody* pkChild = &kA;
        const hkpCdBody* pkParent = kA.getParent();
        do
        {
            const hkpShapeType iType = pkParent->getShape()->getType();
            if (kInput.m_pCollisionDispatcher->hasAlternateType(iType, static_cast<hkpShapeType>(7)))
            {
                const hkpShapeCollection* pkCollection =
                    static_cast<const hkpShapeCollection*>(pkParent->getShape());
                uiInfoA = pkCollection->GetFilterInfoForKey(pkChild->getShapeKey());
                goto done;
            }
            else if (kInput.m_pCollisionDispatcher->hasAlternateType(iType, static_cast<hkpShapeType>(8)))
            {
                ShapeCollectionScratchBuffer kBuffer;
                const hkpShapeContainer* pkContainer = Hkpbvtreeagent3_ForwardCall_00d2d4b0(pkParent, kBuffer);
                uiInfoA = pkContainer->GetFilterInfoForKey(pkChild->getShapeKey());
                goto done;
            }
            else if (kInput.m_pCollisionDispatcher->hasAlternateType(iType, static_cast<hkpShapeType>(21)))
            {
                uiInfoA = kA.getRootCollidable()->GetFilterInfoForKey();
                goto done;
            }
            else if (kInput.m_pCollisionDispatcher->hasAlternateType(iType, static_cast<hkpShapeType>(22)))
            {
                return true;
            }
            pkChild = pkParent;
            pkParent = pkParent->getParent();
        } while (pkParent);
        uiInfoA = reinterpret_cast<const hkpCollidable*>(pkChild)->GetFilterInfoForKey();
    }
done:
    return ShouldCollide(uiInfoA, uiInfoB);
}

// Local extension: the shared group class lacks ShouldCollide and collection-filter overrides.
class CollectionPairCollisionFilter : public hkpGroupFilter
{
  public:
    enum
    {
        USE_COLLIDABLE_FILTER_INFO = 0xffffffff
    };
    hkBool ShouldCollide(unsigned int infoA, unsigned int infoB) const;
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& input, const hkpCdBody& a, const hkpCdBody& b,
                                   const hkpShapeContainer& containerShapeA,
                                   const hkpShapeContainer& containerShapeB, unsigned int keyA,
                                   unsigned int keyB) const;
};
// Resolves per-shape or root-collidable filter info for two shapes and returns whether they should collide via ShouldCollide.
// @fnv 0x00e48ae0
hkBool CollectionPairCollisionFilter::IsCollisionEnabled(const CollisionAgentContext& input, const hkpCdBody& a,
                                          const hkpCdBody& b, const hkpShapeContainer& containerShapeA,
                                          const hkpShapeContainer& containerShapeB, unsigned int keyA,
                                          unsigned int keyB) const
{
    unsigned int infoA = containerShapeA.GetFilterInfoForKey(keyA);
    if (infoA == USE_COLLIDABLE_FILTER_INFO)
        infoA = a.getRootCollidable()->GetFilterInfoForKey();
    unsigned int infoB = containerShapeB.GetFilterInfoForKey(keyB);
    if (infoB == USE_COLLIDABLE_FILTER_INFO)
        infoB = b.getRootCollidable()->GetFilterInfoForKey();
    return ShouldCollide(infoA, infoB);
}

// Local extension: the shared group header lacks the collision-group enabling method.
class CollisionGroupMaskEnabler : public hkpGroupFilter
{
  public:
    void hkpGroupFilter_enableCollisionsUsingBitfield(hkUint32 infoA, hkUint32 infoB);
};

// For each of 32 collision groups, if infoA has the bit set, OR infoB into the group mask, and if infoB has the bit set, OR infoA into it.
// @fnv 0x00e488e0
// src: HAVOK_LIB 0x00e488e0
void CollisionGroupMaskEnabler::hkpGroupFilter_enableCollisionsUsingBitfield(hkUint32 infoA, hkUint32 infoB)
{
    hkUint32 mask = 1;
    hkUint32* pGroupMask = m_uiCollisionGroupMasks;
    int count = 32;

    do
    {
        if (infoA & mask)
            *pGroupMask |= infoB;
        if (infoB & mask)
            *pGroupMask |= infoA;

        ++pGroupMask;
        mask = (mask << 1) | (mask >> 31);
        --count;
    } while (count);
}

class S00e489b0_A
{
  public:
    S00e489b0_A();  // FUN_00cbfba0
    virtual void vfA();
    int unk04;
};

class __declspec(novtable) S00e489b0_B
{
  public:
    virtual void vfB();
};
class __declspec(novtable) S00e489b0_C
{
  public:
    virtual void vfC();
};
class __declspec(novtable) S00e489b0_D
{
  public:
    virtual void vfD();
};
class __declspec(novtable) S00e489b0_E
{
  public:
    virtual void vfE();
    int unk18;
    int unk1C;
};

// Retained constructor layout: the shared group header lacks its default constructor and virtual overrides.
class FUN_00e489b0 : public S00e489b0_A, public S00e489b0_B, public S00e489b0_C, public S00e489b0_D, public S00e489b0_E
{
  public:
    FUN_00e489b0();
    virtual void vfA();
    virtual void vfB();
    virtual void vfC();
    virtual void vfD();
    virtual void vfE();

    int m_iMode;
    int unk24;
    int unk28;
    int unk2C;
    int m_iArrayLength;
    int m_aiSlots[32];
};

// @fnv 0x00e489b0
FUN_00e489b0::FUN_00e489b0()
{
    m_iMode = 2;
    for (int i = 0; i < 32; i++)
        m_aiSlots[i] = -1;
    m_iArrayLength = 0;
}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk for a virtual declared by both bases.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00e00c00();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00e00c00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e00c00
// src: GUESS 0x00e00c00 (confidence: low)
    virtual void AdjustThisAndForward_00e00c00();
};

Derived::Derived()
{}

namespace fnv_00e00c10 {
// sub ecx,0x14; jmp target  ==  MSVC adjustor thunk (multiple inheritance, primary base size 0x14).
// Derived overrides a virtual that both of its bases declare, so the second base's vtable slot
// gets a thunk that moves `this` back by the size of the first base (0x14) and tail-jumps to
// the derived implementation. Only the constructor is defined, so the vtables (and the thunk)
// get emitted.
struct PrimaryBase
{
    virtual void FUN_00e00c10();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00e00c10();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e00c10
    virtual void FUN_00e00c10();
};

Derived::Derived()
{}
}  // namespace fnv_00e00c10

namespace fnv_00e00c20 {
// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00e00c20();
    int unk04;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00e00c20();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e00c20
// src: GUESS 0x00e00c20 (confidence: low)
    virtual void AdjustThisAndForward_00e00c20();
};

Derived::Derived()
{}
}  // namespace fnv_00e00c20

// FUN_00e00c30 : MSVC this-adjusting thunk  (sub ecx, 0x0c ; jmp <impl>)
struct A1_00e00c30
{
    A1_00e00c30();
    virtual void FUN_00e00c30();
    char pad[0x08];
};
struct A2_00e00c30
{
    A2_00e00c30();
    virtual void FUN_00e00c30();
};
struct Own_00e00c30 : A1_00e00c30, A2_00e00c30
{
    Own_00e00c30();
    virtual void key_fn();
// @fnv 0x00e00c30
    void FUN_00e00c30();
};
Own_00e00c30::Own_00e00c30()
{}
void Own_00e00c30::key_fn()
{}
Own_00e00c30* make_00e00c30()
{
    static Own_00e00c30 o;
    return &o;
}
