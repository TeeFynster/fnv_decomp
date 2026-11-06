#pragma once

// PathingAvoidNode: real name (was PathingAvoidanceNode). Names DB PathingAvoidNode::* for its bound methods; ctor 0x00692710 is called after a 0x24-byte allocation at 0x006e3cf9.

#include "NiPoint3.h"

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class NavMeshTriangle;

class PathingAvoidNode
{
public:
    union
    {
        struct
        {
            unsigned int a;
            unsigned int b;
            unsigned int c;
            unsigned int d;
            unsigned int e;
            unsigned int f;
            unsigned int g;
            unsigned int h;
            unsigned int i;
        };
        struct
        {
            NiPoint3 m_kLocation;
            NiPoint3 TwoComponentVector;
            float fRadius;
            float m_fPathingCostCur;
            int eType;
        };
    };

    PathingAvoidNode(const NiPoint3&, float, float);
    float GetAvoidanceAtPoint(NiPoint3*);
    NavMeshTriangle* GetAvoidanceAtPoint(unsigned short);
    void LoadPathingAvoidNode(BGSLoadFormBuffer*);
    int GetType();
    void* GetPoint1();
    void* GetPoint2();
    float GetRadius();
    float GetCost();
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
};
