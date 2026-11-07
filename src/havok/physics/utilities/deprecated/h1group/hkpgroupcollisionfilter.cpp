// src/havok/physics/utilities/deprecated/h1group/hkpgroupcollisionfilter.cpp
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../../include/hkpShapeCollectionFilter.h"
#include "../../../../../../include/hkpRayCollidableFilter.h"
#include "../../../../../../include/hkpRayShapeCollectionFilter.h"
#include "../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../include/hkpCdBody.h"
#include "../../../../../../include/hkpCollidable.h"

struct hkBoolRet
{
    hkBool m_cBooleanValue;
};

// No shared hkpShapeRayCastInput header is available; filter info is at +0x20 in 0x00e45950.
struct hkpShapeRayCastInput
{
    float m_vFrom[4];
    float m_vTo[4];
    unsigned int m_uiFilterInfo;
};

// No shared hkpGroupCollisionFilter header is available; members match the reflected +0x30/+0x34 layout.
class hkpGroupCollisionFilter : public hkReferencedObject,
                                public hkpCollidableCollidableFilter,
                                public hkpShapeCollectionFilter,
                                public hkpRayShapeCollectionFilter,
                                public hkpRayCollidableFilter
{
public:
    virtual hkBool IsCollisionEnabled(const hkpCollidable& kFirst, const hkpCollidable& kSecond) const;
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& kInput, const hkpCdBody& kFirst,
                                     const hkpCdBody& kSecond, const hkpShapeContainer& kContainer,
                                     hkpShapeKey uKey) const;
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& kInput, const hkpCdBody& kFirst,
                                     const hkpCdBody& kSecond, const hkpShapeContainer& kContainerA,
                                     const hkpShapeContainer& kContainerB, hkpShapeKey uKeyA,
                                     hkpShapeKey uKeyB) const;
    virtual hkBoolRet IsCollisionEnabled(const ShapeRayCastQuery& kInput, const hkpShapeCollection& kShape,
                                     const hkpShapeContainer& kContainer, unsigned int uKey) const;
    virtual hkBool IsCollisionEnabled(const WorldRayCastInput& kInput, const hkpCollidable& kBody) const;
    hkBool isCollisionEnabled(int iMask, int iValue) const;

    unsigned int m_uiPreTypePadding[2];
    unsigned int m_type;
    unsigned int m_uiPostTypePadding[3];
    hkBool m_bEnableCollisionTable;
    char pad31[3];
    unsigned int m_uiCollisionTable[32];
};

// Returns m_bEnableCollisionTable if mask or value is zero, otherwise ORs selected m_uiCollisionTable entries per mask bits and returns whether value overlaps the result.
// @fnv 0x00e455f0
// src: HAVOK_LIB 0x00e455f0
hkBool hkpGroupCollisionFilter::isCollisionEnabled(int mask, int value) const
{
    if (mask == 0 || value == 0)
    {
        return m_bEnableCollisionTable;
    }
    int iAccumulatedMask = 0;
    if (mask & 0xff)
    {
        iAccumulatedMask = (mask & 0x1) ? m_uiCollisionTable[0] : 0;
        iAccumulatedMask |= (mask & 0x2) ? m_uiCollisionTable[1] : 0;
        iAccumulatedMask |= (mask & 0x4) ? m_uiCollisionTable[2] : 0;
        iAccumulatedMask |= (mask & 0x8) ? m_uiCollisionTable[3] : 0;
        iAccumulatedMask |= (mask & 0x10) ? m_uiCollisionTable[4] : 0;
        iAccumulatedMask |= (mask & 0x20) ? m_uiCollisionTable[5] : 0;
        iAccumulatedMask |= (mask & 0x40) ? m_uiCollisionTable[6] : 0;
        iAccumulatedMask |= (mask & 0x80) ? m_uiCollisionTable[7] : 0;
    }
    if (mask & 0xff00)
    {
        iAccumulatedMask |= (mask & 0x100) ? m_uiCollisionTable[8] : 0;
        iAccumulatedMask |= (mask & 0x200) ? m_uiCollisionTable[9] : 0;
        iAccumulatedMask |= (mask & 0x400) ? m_uiCollisionTable[10] : 0;
        iAccumulatedMask |= (mask & 0x800) ? m_uiCollisionTable[11] : 0;
        iAccumulatedMask |= (mask & 0x1000) ? m_uiCollisionTable[12] : 0;
        iAccumulatedMask |= (mask & 0x2000) ? m_uiCollisionTable[13] : 0;
        iAccumulatedMask |= (mask & 0x4000) ? m_uiCollisionTable[14] : 0;
        iAccumulatedMask |= (mask & 0x8000) ? m_uiCollisionTable[15] : 0;
    }
    if (mask & 0xff0000)
    {
        iAccumulatedMask |= (mask & 0x10000) ? m_uiCollisionTable[16] : 0;
        iAccumulatedMask |= (mask & 0x20000) ? m_uiCollisionTable[17] : 0;
        iAccumulatedMask |= (mask & 0x40000) ? m_uiCollisionTable[18] : 0;
        iAccumulatedMask |= (mask & 0x80000) ? m_uiCollisionTable[19] : 0;
        iAccumulatedMask |= (mask & 0x100000) ? m_uiCollisionTable[20] : 0;
        iAccumulatedMask |= (mask & 0x200000) ? m_uiCollisionTable[21] : 0;
        iAccumulatedMask |= (mask & 0x400000) ? m_uiCollisionTable[22] : 0;
        iAccumulatedMask |= (mask & 0x800000) ? m_uiCollisionTable[23] : 0;
    }
    if (mask & 0xff000000)
    {
        iAccumulatedMask |= (mask & 0x1000000) ? m_uiCollisionTable[24] : 0;
        iAccumulatedMask |= (mask & 0x2000000) ? m_uiCollisionTable[25] : 0;
        iAccumulatedMask |= (mask & 0x4000000) ? m_uiCollisionTable[26] : 0;
        iAccumulatedMask |= (mask & 0x8000000) ? m_uiCollisionTable[27] : 0;
        iAccumulatedMask |= (mask & 0x10000000) ? m_uiCollisionTable[28] : 0;
        iAccumulatedMask |= (mask & 0x20000000) ? m_uiCollisionTable[29] : 0;
        iAccumulatedMask |= (mask & 0x40000000) ? m_uiCollisionTable[30] : 0;
        iAccumulatedMask |= (mask & 0x80000000u) ? m_uiCollisionTable[31] : 0;
    }
    return (value & iAccumulatedMask) != 0;
}


// @fnv 0x00e45890
hkBool hkpGroupCollisionFilter::IsCollisionEnabled(const hkpCollidable& a, const hkpCollidable& b) const
{
    return isCollisionEnabled(a.m_kBroadPhaseHandle.m_uiCollisionFilterData, b.m_kBroadPhaseHandle.m_uiCollisionFilterData);
}

// @fnv 0x00e458c0
hkBool hkpGroupCollisionFilter::IsCollisionEnabled(const CollisionAgentContext& input, const hkpCdBody& a,
                                                const hkpCdBody& b, const hkpShapeContainer& container,
                                                hkpShapeKey key) const
{
    unsigned int info = container.GetFilterInfoForKey(key);
    const hkpCdBody* root = &a;
    while (root->m_parent)
        root = root->m_parent;
    return isCollisionEnabled(reinterpret_cast<const hkpCollidable*>(root)->m_kBroadPhaseHandle.m_uiCollisionFilterData, info);
}

// @fnv 0x00e45910
hkBool hkpGroupCollisionFilter::IsCollisionEnabled(const CollisionAgentContext& input, const hkpCdBody& a,
                                                const hkpCdBody& b, const hkpShapeContainer& containerA,
                                                const hkpShapeContainer& containerB, hkpShapeKey keyA,
                                                hkpShapeKey keyB) const
{
    unsigned int infoA = containerA.GetFilterInfoForKey(keyA);
    unsigned int infoB = containerB.GetFilterInfoForKey(keyB);
    return isCollisionEnabled(infoA, infoB);
}

// @fnv 0x00e45950
hkBoolRet hkpGroupCollisionFilter::IsCollisionEnabled(const ShapeRayCastQuery& input, const hkpShapeCollection& shape,
                                                const hkpShapeContainer& container, unsigned int key) const
{
    unsigned int info = container.GetFilterInfoForKey(key);
    hkBoolRet result = { isCollisionEnabled(reinterpret_cast<const hkpShapeRayCastInput&>(input).m_uiFilterInfo, info) };
    return result;
}

// @fnv 0x00e45990
hkBool hkpGroupCollisionFilter::IsCollisionEnabled(const WorldRayCastInput& input, const hkpCollidable& body) const
{
    return isCollisionEnabled(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(&input) + 0x24),
                      body.m_kBroadPhaseHandle.m_uiCollisionFilterData);
}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00cbfc00();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00cbfc00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00cbfc00
// src: GUESS 0x00cbfc00 (confidence: low)
    virtual void AdjustThisAndForward_00cbfc00();
};

Derived::Derived()
{}
