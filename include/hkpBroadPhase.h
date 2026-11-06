#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "hkMultiThreadCheck.h"
#include "hkVector4.h"
#include "hkArray.h"

class hkAabb;
class hkAabbUint32;
class hkpBroadPhaseHandle;
class hkpBroadPhaseAabbCache;
class hkpBroadPhaseCastCollector;
class hkpCollidable;
class BroadPhaseCastCollector;

class hkpBroadPhase : public hkReferencedObject
{
public:
    hkpBroadPhase();
    ~hkpBroadPhase();   // 0x00d970c0 (out of line in Havok 7.1)

    enum BroadPhaseType
    {
        BROADPHASE_16BIT,
        BROADPHASE_32BIT
    };

    virtual BroadPhaseType getType() const = 0;
    virtual void addObject(hkpBroadPhaseHandle* pObject, const hkAabbUint32& kAabb, hkArray<BroadPhaseCastCollector>& kPairsOut) = 0;
    virtual void addObject(hkpBroadPhaseHandle* pObject, const hkAabb& kAabb, hkArray<BroadPhaseCastCollector>& kPairsOut) = 0;
    virtual void UpdatePairs(const hkArrayBase<hkpBroadPhaseHandle*>& kObjectList, const hkArrayBase<hkAabb>& kAabbList, hkArray<BroadPhaseCastCollector>& kNewPairs) = 0;
    virtual void RemoveBroadPhaseObject(hkpBroadPhaseHandle* pObject, hkArray<BroadPhaseCastCollector>& kPairsOut) = 0;
    virtual void RemoveObjectBatch(const hkArrayBase<hkpBroadPhaseHandle*>& kRemoveObjectList, hkArray<BroadPhaseCastCollector>& kDelPairsOut) = 0;
    virtual int GetBroadphaseType() const = 0;
    virtual void UpdateAabbs(hkpBroadPhaseHandle* pObjects[], const hkAabb* pAabbs, int iNumObjects, hkArray<BroadPhaseCastCollector>& kAddedPairs, hkArray<BroadPhaseCastCollector>& kRemovedPairs) = 0;
    virtual void UpdateAabbsUint32(hkpBroadPhaseHandle* pObjects[], const hkAabbUint32* pAabbs, int iNumObjects, hkArray<BroadPhaseCastCollector>& kAddedPairs, hkArray<BroadPhaseCastCollector>& kRemovedPairs) = 0;
    virtual void Defragment() = 0;
    virtual void ClearBroadPhase();
    virtual void GetAllAabbs(hkArray<hkAabb>& kAabbs) const = 0;
    virtual void getAabb(const hkpBroadPhaseHandle* pObject, hkAabb& kAabb) const = 0;
    virtual void GetWorldExtents(hkVector4& kWorldMinOut, hkVector4& kWorldMaxOut) const = 0;
    virtual void FindOverlappingPairs(const hkAabb& kAabb, hkArray<BroadPhaseCastCollector>& kPairs_out) const = 0;
    virtual void ReQuerySingleObject(const hkpBroadPhaseHandle* pObject, hkArray<BroadPhaseCastCollector>& kPairs_out) const = 0;
    virtual bool AreAabbsOverlapping(const hkpBroadPhaseHandle* pFirst, const hkpBroadPhaseHandle* pSecond) const = 0;
    virtual void ShiftAllObjects(const hkVector4& kShiftDistance, hkVector4& kEffectiveShiftDistanceOut, hkArray<BroadPhaseCastCollector>& kNewCollisionPairs) = 0;
    virtual void ShiftBroadPhase(const hkVector4& kShiftDistance, hkVector4& kEffectiveShiftDistanceOut, hkArray<BroadPhaseCastCollector>& kNewCollisionPairs) = 0;
    virtual void GetOffsetLowHigh32Bit(hkVector4& kOffsetLow32bit, hkVector4& kOffsetHigh32bit) const = 0;

    struct RayCastBatchInput
    {
        static void* __cdecl operator new(std::size_t uNbytes);
        static void __cdecl operator delete(void* pItem);
        static void* __cdecl operator new(std::size_t uCount, void* pItem);
        static void* __cdecl operator new[](std::size_t uCount, void* pItem);
        static void __cdecl operator delete(void* pItem, void* pPlace);
        static void __cdecl operator delete[](void* pItem, void* pPlace);
        class CommandArgument;

        hkVector4 m_vFrom;
        int m_iCastCount;
        const hkVector4* m_pCastEndpoints;
        int m_iEndpointStrideBytes;
        const hkpBroadPhaseAabbCache* m_pBroadPhaseAabbCache;

        RayCastBatchInput();
    };

    virtual void RayCast(const RayCastBatchInput& kInput, hkpBroadPhaseCastCollector* pCollectorBase, int iCollectorStriding) const = 0;
    virtual int GetAabbCacheSize() const = 0;
    virtual void CalcAabbCache(const hkAabb& kAabb, hkpBroadPhaseAabbCache* pAabbCacheOut) const = 0;
    virtual void CalcAabbCache(const hkArrayBase<hkpCollidable*>& kOverlappingCollidables, hkpBroadPhaseAabbCache* pAabbCacheOut) const = 0;

    struct AabbSweepInput
    {
        static void* __cdecl operator new(std::size_t uNbytes);
        static void __cdecl operator delete(void* pItem);
        static void* __cdecl operator new(std::size_t uCount, void* pItem);
        static void* __cdecl operator new[](std::size_t uCount, void* pItem);
        static void __cdecl operator delete(void* pItem, void* pPlace);
        static void __cdecl operator delete[](void* pItem, void* pPlace);
        class CommandArgument;

        hkVector4 m_vFrom;
        hkVector4 m_vTo;
        hkVector4 m_vHalfExtents;
        const hkpBroadPhaseAabbCache* m_pBroadPhaseAabbCache;

        AabbSweepInput();
    };

    virtual void CastSweptAabb(const AabbSweepInput& kInput, hkpBroadPhaseCastCollector& kCollector) const = 0;
    virtual void Set32BitOffsetAndScale(const hkVector4& kOffsetLow, const hkVector4& kOffsetHigh, const hkVector4& kScale) = 0;

    typedef hkpBroadPhase* (__cdecl* createBroadPhaseFunc)(const hkVector4& worldMin, const hkVector4& worldMax, int numMarkers);
    static createBroadPhaseFunc ms_pDefaultCreationFunction;

    void lock() throw();
    void unlock() throw();
    void lockImplementation() throw();
    void unlockImplementation() throw();
    mutable hkMultiThreadCheck m_kMultiThreadCheck;

    class ScopedBroadPhaseFactoryOverride
    {
    public:
        ScopedBroadPhaseFactoryOverride();
        ~ScopedBroadPhaseFactoryOverride();

        createBroadPhaseFunc pfnOriginalBroadPhaseCreator;

    private:
        static void* __cdecl operator new(std::size_t uNbytes);
        static void __cdecl operator delete(void* pItem);
        static void* __cdecl operator new(std::size_t uCount, void* pItem);
        static void* __cdecl operator new[](std::size_t uCount, void* pItem);
        static void __cdecl operator delete(void* pItem, void* pPlace);
        static void __cdecl operator delete[](void* pItem, void* pPlace);
        class CommandArgument;
    };
};
