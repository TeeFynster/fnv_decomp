#pragma once

#include "BSSimpleArrayRefCounted.h"

class PathingAvoidNode;
class PathingAvoidNode;
class AvoidanceEntry;
class AvoidanceVectorData;
class TopicInfoRecord;
class NiPoint3;

class PathingAvoidNodeArray : public BSSimpleArrayRefCounted<PathingAvoidNode,1024>
{
public:
    PathingAvoidNodeArray();
    ~PathingAvoidNodeArray();

    // vftable 0x0106d1e4: the deleting destructor 0x006e3880 (slot 0, from BSSimpleArray's virtual destructor),
    // then these three.
    virtual PathingAvoidNode* AllocateBuffer(unsigned int);
    virtual void FreeBuffer(void*);
    virtual void* __thiscall Reallocate_Thunk_006e3c40(void*, unsigned int);


    void FUN_006e3960();
    void FUN_006e39d0();
    PathingAvoidNode* BSSimpleArray_PathingAvoidNode_1024_GetAt(unsigned int);
    void SetSize(unsigned int, bool);
    unsigned int AppendNode(const AvoidanceEntry&);
    void AppendNode(const AvoidanceVectorData&, float, float);
    void AppendNode(TopicInfoRecord*);
    float GetAvoidCost(const NiPoint3&, const NiPoint3&);
    float GetAvoidanceAtPoint(NiPoint3&);
};
