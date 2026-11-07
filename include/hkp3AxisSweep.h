#pragma once

#include "hkpBroadPhase.h"

class SweepEntry;
class UnkHandle;
class FourIntegerBlock;
class UnsignedShortPair;
class OverlappingMarkerInfo;
class BroadPhasePairArray;
class PairVec;
class EventList;
class SweepRecord;
class SweepNodeX;
class SweepPairsX;
class Node16;
class Input;
class PairArr;
class ItemList;
class Blk;
class RemovedHandleList;

class hkp3AxisSweep : public hkpBroadPhase
{
public:
    struct NodeArray
    {
        FourIntegerBlock* m_data;
        int m_iElementCount;
        int m_iCapacityState;
    };

    struct Axis
    {
        UnsignedShortPair* m_data;
        int m_iElementCount;
        int m_iCapacityState;
    };

    struct Node
    {
        unsigned short m_usValue00;
        unsigned short m_usValue02;
        unsigned short m_usValue04;
        unsigned short m_usValue06;
        unsigned short m_usValue08;
        unsigned short m_usValue0A;
        unsigned int unk0C;
    };

    struct EndPoint
    {
        unsigned short m_uiFilterValue;
        unsigned short m_usIndex;
    };

    hkp3AxisSweep();
    hkp3AxisSweep(const int* low, const int* high, int count);
    virtual ~hkp3AxisSweep() throw();
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual BroadPhaseType getType() const;
    virtual void addObject(hkpBroadPhaseHandle* object, const hkAabbUint32& aabb, hkArray<BroadPhaseCastCollector>& pairsOut);
    virtual void addObject(hkpBroadPhaseHandle* object, const hkAabb& aabb, hkArray<BroadPhaseCastCollector>& pairsOut);
    virtual void UpdatePairs(const hkArrayBase<hkpBroadPhaseHandle*>& addObjectList, const hkArrayBase<hkAabb>& addAabbList, hkArray<BroadPhaseCastCollector>& newPairs);
    virtual void RemoveBroadPhaseObject(hkpBroadPhaseHandle* object, hkArray<BroadPhaseCastCollector>& pairsOut);
    virtual void RemoveObjectBatch(const hkArrayBase<hkpBroadPhaseHandle*>& removeObjectList, hkArray<BroadPhaseCastCollector>& delPairsOut);
    virtual int GetBroadphaseType() const;
    virtual void UpdateAabbs(hkpBroadPhaseHandle* objects[], const hkAabb* aabbs, int numObjects, hkArray<BroadPhaseCastCollector>& addedPairs, hkArray<BroadPhaseCastCollector>& removedPairs);
    virtual void UpdateAabbsUint32(hkpBroadPhaseHandle* objects[], const hkAabbUint32* aabbs, int numObjects, hkArray<BroadPhaseCastCollector>& addedPairs, hkArray<BroadPhaseCastCollector>& removedPairs);
    virtual void Defragment();
    virtual void ClearBroadPhase();
    virtual void GetAllAabbs(hkArray<hkAabb>& allAabbs) const;
    virtual void getAabb(const hkpBroadPhaseHandle* object, hkAabb& aabb) const;
    virtual void GetWorldExtents(hkVector4& worldMinOut, hkVector4& worldMaxOut) const;
    virtual void FindOverlappingPairs(const hkAabb& aabb, hkArray<BroadPhaseCastCollector>& pairs_out) const;
    virtual void ReQuerySingleObject(const hkpBroadPhaseHandle* object, hkArray<BroadPhaseCastCollector>& pairs_out) const;
    virtual bool AreAabbsOverlapping(const hkpBroadPhaseHandle* bhA, const hkpBroadPhaseHandle* bhB) const;
    virtual void ShiftAllObjects(const hkVector4& shiftDistance, hkVector4& effectiveShiftDistanceOut, hkArray<BroadPhaseCastCollector>& newCollisionPairs);
    virtual void ShiftBroadPhase(const hkVector4& shiftDistance, hkVector4& effectiveShiftDistanceOut, hkArray<BroadPhaseCastCollector>& newCollisionPairs);
    virtual void GetOffsetLowHigh32Bit(hkVector4& offsetLow32bit, hkVector4& offsetHigh32bit) const;
    virtual void RayCast(const RayCastBatchInput& input, hkpBroadPhaseCastCollector* collectorBase, int collectorStriding) const;
    virtual int GetAabbCacheSize() const;
    virtual void CalcAabbCache(const hkAabb& aabb, hkpBroadPhaseAabbCache* aabbCacheOut) const;
    virtual void CalcAabbCache(const hkArrayBase<hkpCollidable*>& overlappingCollidables, hkpBroadPhaseAabbCache* aabbCacheOut) const;
    virtual void CastSweptAabb(const AabbSweepInput& input, hkpBroadPhaseCastCollector& collector) const;
    virtual void Set32BitOffsetAndScale(const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale);
    virtual void CollectAabbCastResults(const hkAabb& aabb, hkpBroadPhaseCastCollector* collector) const;

    int getNumObjects();
    int getAabbCacheSize();
    void getAabb_00d119c0(UnkHandle* handle);
    void getAabbFromNode(const Node& node, hkAabb& aabb) const;
    void FixNodeEdges(unsigned int index);
    void FixNodeEdges(int index);
    void BuildBroadPhasePairs(Node* nodesA, int numNodesA, Node* nodesB, int numNodesB, int mode, BroadPhasePairArray& pairs);
    void queryBatchAabbSub(unsigned int* bits, PairVec* out, char flag);
    void getExtents(__m128* out0, __m128* out1);
    bool __thiscall areAabbsOverlapping(int* first, int* second);
    void defragment();
    void GetValues(__m128* out0, __m128* out1);
    void hkp3AxisSweep_setBitsBasedOnXInterval(int numRecords, unsigned short code, SweepRecord* rec, int index, void* buffer);
    void hkp3AxisSweep_setBitsBasedOnXInterval(int count, int key, SweepNodeX* node, unsigned int index, unsigned int* bits);
    void hkp3AxisSweep_setBitsBasedOnXInterval(int count, unsigned int key, Node16* node, int index, void* buffer);
    void hkp3AxisSweep_updateNodesAfterDelete(SweepNodeX* base, int count, SweepNodeX* node);
    void reQuerySingleObject(int* index, EventList* events);
    void removeObject(unsigned int* handle, SweepPairsX* pairs);
    void calcAabbCache(ItemList* items, unsigned int out);
    __declspec(noinline) void calcAabbCacheInternal(Blk* array, unsigned int out);
    __declspec(noinline) void Hkp3axissweepGsEhscNogsNoehsc_ProcessEntries_00d10b30(Node16* buf, int index, Node16* node);
    void addObject_00d142b0(int* handle, Input* input, PairArr* outPairs);
    void removeObjectBatch(RemovedHandleList* removed, int pairs);

    unsigned char unk10[0x10];
    int lowBound[4];
    int highBound[4];
    union { __m128 offset; __m128 m_negSrc; };
    __m128 offset2;
    union { __m128 scale; __m128 m_recipSrc; };
    __m128 m_v70;
    __m128 m_v80;
    __m128 unk90;
    union
    {
        NodeArray m_kNodeCollection;
        struct
        {
            union { SweepEntry* unkA0; Node* nodes; };
            union { int m_iA4; int nodeCount; int m_iArrayLength; };
            union { int unkA8; int nodeCapacity; };
        };
    };
    union
    {
        Axis m_kAxisEndPoints[3];
        struct
        {
            Axis m_axis0;
            Axis m_axis1;
            Axis m_axis2;
        };
        struct
        {
            EndPoint* axis0;
            int unkB0;
            int unkB4;
            EndPoint* axis1;
            int unkBC;
            int unkC0;
            EndPoint* axis2;
            int unkC8;
            int unkCC;
        };
    };
    union { int m_iMarkerCount; int m_numSubNodes; int markerCount; int m_iBase; int unkD0; };
    union
    {
        int unkD4;
        struct { unsigned short shiftBits; unsigned short unkD6; };
    };
    union { OverlappingMarkerInfo* m_pOverlappingMarkerInfo; void* unkD8; char* m_markerBase; };
    float correction;
};
