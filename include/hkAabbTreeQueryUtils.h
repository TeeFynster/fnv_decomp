#pragma once

typedef unsigned short hkUint16;
typedef float hkReal;

class hkAabb;
class voidWriteIterator;

#include "hkArray.h"

class hkAabbTreeData
{
public:
    struct RayQueryAabb;
    struct QuantizedAabb;
    struct SweptBoxQuery;

    typedef RayQueryAabb hkAabbTreeAabb;
    typedef QuantizedAabb hkAabbTreeAabb16;
};

template <typename BOUNDING_VOLUME, typename hkIdxType = hkUint16>
class hkAabbTree
{
public:
    struct Node;
};

template <typename BOUNDING_VOLUME, typename hkIdxType = hkUint16>
class hkAabbTreeQueryUtils
{
public:
    struct AabbTreeNodePair
    {
        AabbTreeNodePair();
        AabbTreeNodePair(
            typename hkAabbTree<BOUNDING_VOLUME, hkIdxType>::Node* a,
            typename hkAabbTree<BOUNDING_VOLUME, hkIdxType>::Node* b);

        typename hkAabbTree<BOUNDING_VOLUME, hkIdxType>::Node* m_kPointA;
        typename hkAabbTree<BOUNDING_VOLUME, hkIdxType>::Node* m_kPointB;
    };

    struct Collector
    {
        virtual ~Collector();
        virtual hkReal GetHitDistance(
            const typename hkAabbTree<BOUNDING_VOLUME, hkIdxType>::Node* leaf) = 0;
    };

    static int __cdecl CastSweptAabb(
        const hkAabbTree<BOUNDING_VOLUME, hkIdxType>* tree,
        const hkAabb& queryVolume,
        hkAabbTreeData::SweptBoxQuery& input,
        Collector* collector,
        hkReal aabbCheckTolerance = 0.0f,
        void** hitArray = 0,
        int hitCapacity = 0);

    static int __cdecl GetAabbHits(
        const hkAabbTree<BOUNDING_VOLUME, hkIdxType>* tree,
        const hkAabb& aabb,
        Collector* collector);

private:
    static int __cdecl CollectAabbHitsIntoBuffers(
        const hkAabbTree<BOUNDING_VOLUME, hkIdxType>* tree,
        const hkAabb& aabb,
        Collector* collector,
        hkArray<void*>* ptrArray,
        voidWriteIterator* hitArray,
        int hitCapacity);
};
