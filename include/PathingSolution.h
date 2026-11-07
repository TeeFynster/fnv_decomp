#pragma once

#include "NiRefObject.h"
#include "NiPoint3.h"


class BaseProcess;
class BGSLoadFormBuffer;
class LocationDescriptor;
class PacketNodeRecord;
class PathingGraphNode;
class PathingInfoEntry;
class PathingLocation;
class TESObjectREFR;

class PathingSolutionMember1
{
public:
    PacketNodeRecord* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    int firstValue;
    int secondValue;

    PathingSolutionMember1();
    virtual ~PathingSolutionMember1();
    void SetSize(unsigned int, bool);
    PacketNodeRecord* GetAt(int);
};

class PathingSolutionMember2
{
public:
    PathingGraphNode* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    PathingSolutionMember2();
    virtual ~PathingSolutionMember2();
    void SetSize(unsigned int, bool);
    PathingGraphNode* GetAt(int);
};

class PathingSolutionMember3
{
public:
    unsigned int* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    PathingSolutionMember3();
    virtual ~PathingSolutionMember3();
    void SetSize(unsigned int, bool);
    void* GetAt(int);
};

class PathingSolution : public NiRefObject
{
public:
    PathingSolution();
    virtual ~PathingSolution();

    void LoadGame(BGSLoadFormBuffer*);
    float CalculatePathLength();
    unsigned int GetVirtualNodeCount();
    PacketNodeRecord* GetVirtualNode(unsigned int);
    unsigned int GetNodeCount();
    PathingGraphNode* GetNode(unsigned int);
    PathingGraphNode& GetLastNode();
    float GetTotalPathLength();
    void GetLocationAtSplineParameter(float, NiPoint3*);
    void GetLocationAtSplineParameter(float, NiPoint3&);
    float FindSegmentAtFraction(float, float, unsigned int*);
    float GetSplineLengthAtParameter(float);
    unsigned int GetObjectFlags();
    void SetByteAtOffset40(int);
    void ConstructThing(void*);
    void CreatePathNode(const PathingLocation&, int);
    void AddPathingItem(void*, void*);
    unsigned int AddPathingItem(void*, TESObjectREFR*);
    void ReserveIndex(const PathingLocation&, const NiPoint3&);
    void Clear(bool);
    void TrimNodes(int);
    PathingInfoEntry* GetPathingInfoEntry(PathingInfoEntry&);
    NiPoint3 GetPointAtDistance(float, float);
    unsigned int IsValid();
    void GetPoint(float, NiPoint3&);
    void IncRefCount();
    void DecRefCount();
    bool IsEmpty() const;

    unsigned int FUN_00441110();
    unsigned int PathingSolution_GetVirtualNodeCount();
    PathingGraphNode* PathingSolution_GetLastNode();
    bool IsIncomplete();
    void* FUN_006c90d0(const PathingLocation&);
    void RemoveLastNode();
    void PathingSolution_ClearCurrentDetailedPath();
    LocationDescriptor* GetVirtualNode_006e78b0(unsigned int);
    BaseProcess* GetVirtualNode_006e78b0(unsigned int, NiPoint3&);
    const PathingGraphNode* GetNode_006e7970(unsigned int);
    float ComputeSplineLength(int);
    bool FindPointOnPath(float, float, bool, float*, NiPoint3*);
    bool FindPointOnPath(float, float, int, int*, NiPoint3*);
    bool FindPointOnPath(float, float, int, float*, NiPoint3*);
    int NiAVObject_GetParent();
    bool PathingSolution_IsValid();

    union
    {
        struct
        {
            PathingSolutionMember1 member1;
            PathingSolutionMember2 member2;
            PathingSolutionMember3 member3;
        };
        struct
        {
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
        };
    };
    bool m_bHasValidPath;
    unsigned char unk41;
    unsigned short unk42;
};
