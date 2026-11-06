#pragma once

#include <cstddef>
#include "FinishingFlag.h"
#include "hkpCdBody.h"
#include "hkpCollidableBoundingVolumeData.h"
#include "hkpTypedBroadPhaseHandle.h"

class hkAabbUint32;
class hkClass;
class hkpShape;
struct ClassMemberDescriptor;
struct hkFinishLoadedObjectFlagCD2C;

class hkpCollidable
{
public:
    enum ForceCollideOntoPpuReasons
    {
        FORCE_PPU_USER_REQUEST = 1,
        FORCE_PPU_SHAPE_REQUEST = 2,
        FORCE_PPU_MODIFIER_REQUEST = 4
    };

    struct BoundingVolumeData_S
    {
        static const ClassMemberDescriptor Members[];
        static const hkClass& __cdecl staticClass();
        struct DefaultStruct;
        class CommandArgument;

        BoundingVolumeData_S();
        BoundingVolumeData_S(FinishingFlag flag);
        __forceinline bool hasAllocations() const;
        void deallocate();
        void allocate(int numChildShapes);
        __forceinline void invalidate()
        {
            m_kMinimumCorner[0] = 1;
            m_kMaximumCorner[0] = 0;
        }
        __forceinline bool isValid() const
        {
            return m_kMinimumCorner[0] <= m_kMaximumCorner[0];
        }

        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* placement);
        static void __cdecl operator delete[](void* p, void* placement);

        unsigned int m_kMinimumCorner[3];
        unsigned char m_ucExpansionMin[3];
        unsigned char m_ucExpansionShift;
        unsigned int m_kMaximumCorner[3];
        unsigned char m_ucExpansionMax[3];
        unsigned char m_ucUnknownByte;
        unsigned short m_uiNumChildShapeAabbs;
        unsigned short m_uiCapacityChildShapeAabbs;
        hkAabbUint32* m_pChildShapeAabbs;
        unsigned int* m_pChildShapeKeys;
    };

    typedef BoundingVolumeData_S BoundingVolumeData;

    static const ClassMemberDescriptor Members[];

    hkpCollidable(const void* shape, const void* motionState, int type) throw();
    hkpCollidable(const hkpShape* shape, const hkTransform* transform, int type = 0);
    hkpCollidable(hkFinishLoadedObjectFlagCD2C flag);
    void SetOwnerPointer(void* pvOwner);
    void* getOwner() const;
    const hkpShape* getShape() const;
    __forceinline unsigned int GetFilterInfoForKey() const;

    __forceinline const hkTransform& getTransform() const
    {
        return *static_cast<const hkTransform*>(m_pMotionState);
    }

    __forceinline unsigned int getShapeKey() const
    {
        return m_uiCollisionShapeKey;
    }

    __forceinline const hkMotionState* GetMotionState() const
    {
        return static_cast<const hkMotionState*>(m_pMotionState);
    }

    __forceinline const hkpCdBody* getParent() const
    {
        return m_parent;
    }

    const hkpCollidable* getRootCollidable() const;
    void SetCollisionShapeAndKey(const hkpShape* shape, unsigned int key);
    void SetCollisionShapeAndKey(const hkpShapeV* shape, unsigned int key);

    const hkpShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBody* m_parent;
    signed char m_iOwnerOffset;
    unsigned char m_uiForceCollideOntoPpu;
    unsigned short m_uiShapeSizeOnSpu;
    hkpTypedBroadPhaseHandle m_kBroadPhaseHandle;
    hkpCollidableBoundingVolumeData m_kBoundingVolumeData;
    float m_fAllowedPenetrationDepth;
};
