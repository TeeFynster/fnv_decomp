// fallout_shared/pathfinding/pathingsolution.cpp: pathing solutions and spline helpers (34 functions)

#include "PointStorage.h"
#include "../../../include/PathingSolution.h"
#include "../../../include/PathingInfo.h"
#include "pathingsolution_types_PathingSolution.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSLoadGameBuffer.h"
#include "../../../include/PathingAvoidNodeArray.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/PathingAvoidNode.h"

// Initializes the PathingSolution object by setting two local sentinel values to -1 and clearing the boolean member.
// @fnv 0x006e7650
PathingSolution::PathingSolution()
{
    volatile int first;
    volatile int second;
    second = -1;
    first = -1;
    m_bHasValidPath = false;
}

// @fnv 0x006e7800
float PathingSolution::CalculatePathLength()
{
// distinct from Stack: exe 0x006e7800 uses three PointStorage locals and traversal state, not items/top.
    struct PathLengthFrameView
    {
        PointStorage thirdPoint;
        PointStorage secondPoint;
        PointStorage firstPoint;
        unsigned int index;
        unsigned int count;
        PacketNodeRecord* second;
        PacketNodeRecord* first;
        float distance;
    } stack;
    stack.distance = 0.0f;
    stack.count = GetVirtualNodeCount();
    for (stack.index = 1; stack.index < stack.count; ++stack.index)
    {
        stack.first = GetVirtualNode(stack.index - 1);
        if (stack.first->IsDoor())
            continue;
        stack.second = GetVirtualNode(stack.index);
        stack.distance += stack.second
                              ->GetPosition(reinterpret_cast<NiPoint3&>(stack.firstPoint), reinterpret_cast<NiPoint3&>(stack.thirdPoint),
                                            stack.first->GetPosition(reinterpret_cast<NiPoint3&>(stack.secondPoint))->GetLocation())
                              ->GetLocation()
                              ->GetDoorPathingPoint()
                              ->GetDistance();
    }
    return stack.distance;
}

struct PSClearStub
{
    void Clear(bool);
};
struct PSNodeStub
{
    void FUN_006cf120(bool);
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};

// Clears the three members of the pathing solution, sets member1's two values to -1 and clears the flag.
// @fnv 0x006e77b0
void __fastcall ResetPathingSolution(PathingSolution* self)
{
    ((PSClearStub*)&self->member1)->Clear(true);
    ((PSNodeStub*)&self->member2)->FUN_006cf120(true);
    ((GlobalObject_00869f00*)&self->member3)->Clear(true);
    self->member1.firstValue = -1;
    self->member1.secondValue = -1;
    self->m_bHasValidPath = false;
}

// SolutionNodePool: unit-local view of PathingSolution's node pool (member1), not PathBuilder: 0x006e78b0 and 0x006e8f60 call its slot lookup 0x006e8f40
struct SolutionNodePool
{
    void* GetElementAddress30_006e8f40(void*);
};

// @fnv 0x006e78b0
// src: XBOX_PDB 0x006e78b0
LocationDescriptor* PathingSolution::GetVirtualNode_006e78b0(unsigned int aiIndex)
{
    return (LocationDescriptor*)((SolutionNodePool*)&member1)->GetElementAddress30_006e8f40((void*)aiIndex);
}

struct Dummy_006e8f80
{
    void* GetPathingGraphNodeAddress(unsigned int aiIndex);
};

// @fnv 0x006e7970
// src: XBOX_PDB 0x006e7970
const PathingGraphNode* PathingSolution::GetNode_006e7970(unsigned int aiIndex)
{
    return (const PathingGraphNode*)((Dummy_006e8f80*)&member2)->GetPathingGraphNodeAddress(aiIndex);
}

struct FUN_00457990_shell
{
    float FUN_00457990();
};

// Returns 0.0f if the index is at or past the last element, otherwise computes a value from the positions of the element at the index and the next one.
// @fnv 0x006e7990
// src: COMMUNITY 0x006e7990
float PathingSolution::ComputeSplineLength(int aiIndex)
{
    if (aiIndex >= (int)GetObjectFlags() - 1)
        return 0.0f;
    PointStorage loc1;
    PointStorage loc2;
    PointStorage loc3;
    return ((FUN_00457990_shell*)((PacketNodeRecord*)GetNode_006e7970(aiIndex))
                ->GetPosition(reinterpret_cast<NiPoint3&>(loc3), reinterpret_cast<NiPoint3&>(loc2), ((PacketNodeRecord*)GetNode_006e7970(aiIndex + 1))->GetPosition(reinterpret_cast<NiPoint3&>(loc1))->GetLocation())
                ->GetLocation()
                ->GetDoorPathingPoint())
        ->FUN_00457990();
}

struct BaseS
{
    char pad[0x14];
    BaseS();
    ~BaseS();
};
struct MemS
{
    char pad[0x18];
    MemS();
};
struct FUN_006e7b60 : BaseS
{
    MemS m1;
    MemS m2;
    FUN_006e7b60();
};
// Constructs the object by running the BaseS constructor and default-constructing its two MemS members.
// @fnv 0x006e7b60
FUN_006e7b60::FUN_006e7b60()
{}

extern NiPoint3 _NiPoint3_ZERO;

// Sets two NiPoint3 values at offsets 0 and 0xc of pThis to _NiPoint3_ZERO and returns pThis.
// @fnv 0x006e7bd0
void* __fastcall InitZeroPoints(void* pThis)
{
    *(NiPoint3*)pThis = _NiPoint3_ZERO;
    *(NiPoint3*)((char*)pThis + 0xc) = _NiPoint3_ZERO;
    return pThis;
}

void __fastcall PathingSpline_ComputeHermiteBasis(void* pThis, float arg);

// @fnv 0x006e7c20
// src: COMMUNITY 0x006e7c20
void __fastcall PathingSpline_SetParameter(void* pThis, float arg)
{
    PathingSpline_ComputeHermiteBasis(pThis, arg);
}

extern double DAT_0106d4c8;
struct HermiteStub
{
    float t;
    float a;
    float b;
    float c;
    float d;
    void PathingSpline_ComputeHermiteBasis(float t);
};
// @fnv 0x006e7c40
// src: COMMUNITY 0x006e7c40
void HermiteStub::PathingSpline_ComputeHermiteBasis(float tp)
{
    float t2;
    float t3;
    float tt;
    t = tp;
    tt = tp;
    t2 = tt * tt;
    t3 = t2 * tt;
    c = t3 * DAT_0106d4c8 + t2 * 3.0;
    a = -c + 1.0;
    d = t3 - t2;
    b = d - t2 + tt;
}

struct SubS
{
    void PathingSolution_CopyVectorPair(int);
};
struct RetS
{
    float v[3];
};
struct OwnS
{
    char pad[0x14];
    SubS s1;
    char pad2[0x17];
    SubS s2;
    RetS PathingSpline_InterpolateNoZ(int, int);
    RetS PathingSpline_Interpolate(int a, int b);
};
// Calls FUN_006e7d10 on s1 with a and on s2 with b, then returns FUN_006e7d60(a, b).
// @fnv 0x006e7cc0
// src: COMMUNITY 0x006e7cc0
RetS OwnS::PathingSpline_Interpolate(int aiFirst, int aiSecond)
{
    s1.PathingSolution_CopyVectorPair(aiFirst);
    s2.PathingSolution_CopyVectorPair(aiSecond);
    return PathingSpline_InterpolateNoZ(aiFirst, aiSecond);
}

struct _S_006e7d10
{
    NiPoint3 a;
    NiPoint3 b;
};

struct _Arg_006e7d10
{
    const _S_006e7d10* p;
};

// Copies the two vector members a and b from the pointed-to struct into this struct and returns this.
// @fnv 0x006e7d10
// src: GUESS 0x006e7d10 (confidence: medium)
_S_006e7d10* __fastcall PathingSolution_CopyVectorPair(_S_006e7d10* this_ptr, _Arg_006e7d10 aSource)
{
    this_ptr->a = aSource.p->a;
    this_ptr->b = aSource.p->b;
    return this_ptr;
}

struct NP3S
{
    float x;
    float y;
    float z;
};
struct LocS
{
    NP3S GetLocation();
};
struct M24
{
    NP3S a;
    NP3S b;
    M24();
    M24(const M24&);
};
struct OwnS2
{
    char pad[4];
    LocS loc;
    char pad2[0x27];
    NP3S tangent;
    M24 GetLocationAndTangent();
};
// Builds an M24 from the object's location and tangent and returns it.
// @fnv 0x006e7e10
M24 OwnS2::GetLocationAndTangent()
{
    M24 m;
    m.a = loc.GetLocation();
    m.b = tangent;
    return m;
}

struct blob12
{
    char b[12];
};
struct SplineInterpolator
{
    void SetParameter(float);
    void SetKeyData(void*, void*);
    struct blob12 Interpolate();
    struct blob12 Interpolate(float);
    struct blob12 Interpolate(void*, void*, float);
    struct blob12 Interpolate(void*, void*);
    bool FindPointOnSpline(float, float, bool, float*, NiPoint3*, float);
    float ApproxLength(float, float, unsigned int);
    struct blob12 InterpolateNoZ(void*, void*);
    void* __vecDelDtor(unsigned int);
    char SplinePath[20];
    char Key1[24];
    char Key2[24];
};
typedef char _sizecheck_PathingSpline[sizeof(SplineInterpolator) == 68 ? 1 : -1];
struct PathingControlPoint
{
    NiPoint3 Location;
    NiPoint3 Tangent;
};
typedef char _sizecheck_PathingSplineKey[sizeof(PathingControlPoint) == 24 ? 1 : -1];
struct FUN_006e8450_shell : public SplineInterpolator
{
    void PathingSpline_SetKeys(void*, void*);
};

struct FUN_006e7d10_caller
{
    void PathingSolution_CopyVectorPair(void*);
};

// Forwards each of the two key arguments to the corresponding key object's FUN_006e7d10 method.
// @fnv 0x006e8450
// src: COMMUNITY 0x006e8450
void FUN_006e8450_shell::PathingSpline_SetKeys(void* aKey1, void* aKey2)
{
    reinterpret_cast<FUN_006e7d10_caller*>(this->Key1)->PathingSolution_CopyVectorPair(aKey1);
    reinterpret_cast<FUN_006e7d10_caller*>(this->Key2)->PathingSolution_CopyVectorPair(aKey2);
}

namespace fnv_006e8f60 {
// SolutionNodePool: as above (0x006e8f60 forwards to 0x006e8f40)
class SolutionNodePool
{
  public:
    void* GetElementAddress30_006e8f40(void*);
    void* BSSimpleArray_VirtualPathingNode_1024_GetAt(void* a1);
};

// @fnv 0x006e8f60
// src: XBOX_PDB 0x006e8f60
void* SolutionNodePool::BSSimpleArray_VirtualPathingNode_1024_GetAt(void* apArg)
{
    return GetElementAddress30_006e8f40(apArg);
}
}  // namespace fnv_006e8f60

struct S3e60
{
    bool GetFlag(unsigned int) const;
    bool BSSimpleArray_PathingNode_1024_GetAt(unsigned int f);
};
// @fnv 0x006e8fa0
// src: XBOX_PDB 0x006e8fa0
bool S3e60::BSSimpleArray_PathingNode_1024_GetAt(unsigned int auiFlag)
{
    return GetFlag(auiFlag);
}

// @fnv 0x006e7720
PathingSolution::~PathingSolution()
{
    ResetPathingSolution(this);
}

namespace fnv_006e78d0 {
struct NiPoint3H
{
    float Length() const;
};
// Sums the lengths of the segments between consecutive path nodes and returns the total length.
} // namespace fnv_006e78d0
// @fnv 0x006e78d0
float PathingSolution::GetTotalPathLength()
{
    float ftotalLength = 0.0f;
    PacketNodeRecord* plastNode;
    PacketNodeRecord* pnextNode;
    unsigned int isize = GetObjectFlags();
    for (unsigned int i = 1; i < isize; i++)
    {
        plastNode = (PacketNodeRecord*)GetNode_006e7970(i - 1);
        pnextNode = (PacketNodeRecord*)GetNode_006e7970(i);
        PointStorage a;
        PointStorage b;
        PointStorage c;
        ftotalLength += ((fnv_006e78d0::NiPoint3H*)pnextNode->GetPosition(reinterpret_cast<NiPoint3&>(a), reinterpret_cast<NiPoint3&>(c), plastNode->GetPosition(reinterpret_cast<NiPoint3&>(b))->GetLocation())
                             ->GetLocation()
                             ->GetDoorPathingPoint())
                            ->Length();
    }
    return ftotalLength;
}

struct FUN_006e7d60_stub
{
    float ComputeWeightedSum(float*, float*, float*, float*);
    NiPoint3 PathingSpline_InterpolateNoZ(char* p3, char* p4);
};
// Computes a vector from two structures by calling ComputeWeightedSum on each of the x, y and z component pairs.
// @fnv 0x006e7d60
// src: COMMUNITY 0x006e7d60
NiPoint3 FUN_006e7d60_stub::PathingSpline_InterpolateNoZ(char* pFirst, char* pSecond)
{
    NiPoint3 vecResult;
    vecResult.x = ComputeWeightedSum((float*)pFirst, (float*)pSecond, (float*)(pFirst + 0xc), (float*)(pSecond + 0xc));
    vecResult.y = ComputeWeightedSum((float*)(pFirst + 4), (float*)(pSecond + 4), (float*)(pFirst + 0x10),
                                     (float*)(pSecond + 0x10));
    {
        float a = 0.0f;
        float b = 0.0f;
        vecResult.z = ComputeWeightedSum((float*)(pFirst + 8), (float*)(pSecond + 8), &b, &a);
    }
    return vecResult;
}

struct FUN_006e8f40_shell
{
    int GetElementAddress30_006e8f40(int a) const;
};

// @fnv 0x006e8f40
// src: GUESS 0x006e8f40 (confidence: low)
int FUN_006e8f40_shell::GetElementAddress30_006e8f40(int aiIndex) const
{
    return aiIndex * 0x30 + *(int*)((char*)this + 4);
}

namespace fnv_006e7e70 {

// Exe 0x006e7e70: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct PathingsolutionOffset08View
{
    unsigned int GetFlags();
};
struct FUN_0052d240_obj
{
    ~FUN_0052d240_obj();
};
PathingGraphNode* __fastcall FUN_006e8480(PathingSolution*);
// 0x006e7e10 returns a 24-byte location/tangent value; this ABI-only POD has no PathingSplineKey constructors.
struct SplineLocationTangent
{
    float fData[6];
};
struct OwnS2
{
    SplineLocationTangent GetLocationAndTangent();
};
struct Dummy_006e8f80
{
    void* GetPathingGraphNodeAddress(unsigned int);
};
struct PathingLocationExt
{
    NiPoint3 FUN_005c3420() const;
};
PathingLocationExt& __fastcall FUN_00717e50(PathingGraphNode*);
// 0x006e7c40 writes t and four Hermite weights here: plain coefficient storage, without BSSpline methods.
struct CubicHermiteWeights
{
    float t, a, b, c, d;
};
struct FUN_006e7b60
{
    FUN_006e7b60();
    ~FUN_006e7b60();
    void PathingSpline_SetKeys(const SplineLocationTangent&, const SplineLocationTangent&);
    bool FindPointAtDistance(float, float, bool, float*, NiPoint3*, float);
    float MeasurePathLength(float, float, unsigned int);
    CubicHermiteWeights SplinePath;
    SplineLocationTangent Key1;
    SplineLocationTangent Key2;
};

// Walks the spline segments forward or backward from afCurrentParameter by afDist, writing the resulting parameter and point to the output pointers.
} // namespace fnv_006e7e70
// @fnv 0x006e7e70
// src: XBOX_PDB 0x006e7e70
bool PathingSolution::FindPointOnPath(float afCurrentParameter, float afDist, bool abForward, float* apNewParameter,
                                      NiPoint3* apNewPoint)
{
    if (!GetObjectFlags())
        return false;
    if (abForward)
    {
        bool bfound;
        int isize = GetObjectFlags() - 1;
        if (afCurrentParameter >= isize)
        {
            if (apNewParameter)
                *apNewParameter = isize;
            if (apNewPoint)
                *apNewPoint = fnv_006e7e70::FUN_00717e50(PathingSolution_GetLastNode()).FUN_005c3420();
            return false;
        }
        int icurrentSpline = (int)afCurrentParameter;
        float fcurrentParam = afCurrentParameter;
        float fdist = afDist;
        fnv_006e7e70::FUN_006e7b60 spline;
        spline.PathingSpline_SetKeys(
            ((fnv_006e7e70::OwnS2*)((fnv_006e7e70::Dummy_006e8f80*)&member2)->GetPathingGraphNodeAddress(icurrentSpline))->GetLocationAndTangent(),
            ((fnv_006e7e70::OwnS2*)((fnv_006e7e70::Dummy_006e8f80*)&member2)->GetPathingGraphNodeAddress(icurrentSpline + 1))->GetLocationAndTangent());
        bfound = spline.FindPointAtDistance(fcurrentParam - icurrentSpline, fdist, abForward, apNewParameter,
                                            apNewPoint, 1.0f);
        while (!bfound)
        {
            fdist -= spline.MeasurePathLength(fcurrentParam - icurrentSpline, 1.0f, 2);
            ++icurrentSpline;
            fcurrentParam = icurrentSpline;
            if (icurrentSpline >= isize - 1)
            {
                if (apNewParameter)
                    *apNewParameter = isize;
                if (apNewPoint)
                    *apNewPoint = fnv_006e7e70::FUN_00717e50(PathingSolution_GetLastNode()).FUN_005c3420();
                return false;
            }
            spline.PathingSpline_SetKeys(
                ((fnv_006e7e70::OwnS2*)((fnv_006e7e70::Dummy_006e8f80*)&member2)->GetPathingGraphNodeAddress(icurrentSpline))->GetLocationAndTangent(),
                ((fnv_006e7e70::OwnS2*)((fnv_006e7e70::Dummy_006e8f80*)&member2)->GetPathingGraphNodeAddress(icurrentSpline + 1))->GetLocationAndTangent());
            bfound = spline.FindPointAtDistance(0.0f, fdist, abForward, apNewParameter, apNewPoint, 1.0f);
        }
        if (apNewParameter)
            *apNewParameter += icurrentSpline;
        return true;
    }
    else
    {
        bool bfound;
        int isize = GetObjectFlags() - 1;
        if (afCurrentParameter <= 0.0)
        {
            if (apNewParameter)
                *apNewParameter = 0.0f;
            if (apNewPoint)
                *apNewPoint = fnv_006e7e70::FUN_00717e50(fnv_006e7e70::FUN_006e8480(this)).FUN_005c3420();
            return false;
        }
        int icurrentSpline = (int)afCurrentParameter;
        if (icurrentSpline < 0)
            icurrentSpline = 0;
        if (icurrentSpline >= (int)((fnv_006e7e70::PathingsolutionOffset08View*)&member2)->GetFlags() - 1)
            --icurrentSpline;
        float fcurrentParam = afCurrentParameter;
        float fdist = afDist;
        fnv_006e7e70::FUN_006e7b60 spline;
        spline.PathingSpline_SetKeys(
            ((fnv_006e7e70::OwnS2*)((fnv_006e7e70::Dummy_006e8f80*)&member2)->GetPathingGraphNodeAddress(icurrentSpline))->GetLocationAndTangent(),
            ((fnv_006e7e70::OwnS2*)((fnv_006e7e70::Dummy_006e8f80*)&member2)->GetPathingGraphNodeAddress(icurrentSpline + 1))->GetLocationAndTangent());
        bfound = spline.FindPointAtDistance(fcurrentParam - icurrentSpline, fdist, abForward, apNewParameter,
                                            apNewPoint, 1.0f);
        while (!bfound)
        {
            fdist -= spline.MeasurePathLength(0.0f, fcurrentParam - icurrentSpline, 2);
            --icurrentSpline;
            fcurrentParam = icurrentSpline + 1;
            if (icurrentSpline < 0)
            {
                if (apNewParameter)
                    *apNewParameter = 0.0f;
                if (apNewPoint)
                    *apNewPoint = fnv_006e7e70::FUN_00717e50(fnv_006e7e70::FUN_006e8480(this)).FUN_005c3420();
                return false;
            }
            spline.PathingSpline_SetKeys(
                ((fnv_006e7e70::OwnS2*)((fnv_006e7e70::Dummy_006e8f80*)&member2)->GetPathingGraphNodeAddress(icurrentSpline))->GetLocationAndTangent(),
                ((fnv_006e7e70::OwnS2*)((fnv_006e7e70::Dummy_006e8f80*)&member2)->GetPathingGraphNodeAddress(icurrentSpline + 1))->GetLocationAndTangent());
            bfound = spline.FindPointAtDistance(1.0f, fdist, abForward, apNewParameter, apNewPoint, 1.0f);
        }
        if (apNewParameter)
            *apNewParameter += icurrentSpline;
        return true;
    }
}

struct ArrHelper
{
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty() const;
    int BSSimpleArray_PathingNode_1024_GetHead();
};
// The shared header has no first-node accessor declaration; keep the accessor as a free function.
// @fnv 0x006e8480
int __fastcall FirstPathingNode(PathingSolution* self)
{
    if (((ArrHelper*)&self->member2)->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        return 0;
    }
    return ((ArrHelper*)&self->member2)->BSSimpleArray_PathingNode_1024_GetHead();
}

struct HelperA
{
    char data[16];
    void BSSimpleArray_VirtualPathingNode_1024_Copy(void*);
};
struct HelperB
{
    char data[32];
    void BSSimpleArray_PathingNode_1024_Copy(void*);
};
struct SaveBuffer;
// Only the unsupported copy-to and save declarations live here; all fields come from the shared class.
struct PathingSolutionOperations : public PathingSolution
{
    void CopyTo(PathingSolution*);
    void SaveGame(SaveBuffer*);
};
// @fnv 0x006e8ab0
void PathingSolutionOperations::CopyTo(PathingSolution* apTarget)
{
    apTarget->member1.firstValue = member1.firstValue;
    apTarget->member1.secondValue = member1.secondValue;
    apTarget->m_bHasValidPath = m_bHasValidPath;
    ((HelperA*)&member1)->BSSimpleArray_VirtualPathingNode_1024_Copy(&apTarget->member1);
    ((HelperB*)&member2)->BSSimpleArray_PathingNode_1024_Copy(&apTarget->member2);
}

struct BSSimpleArray_PathingNode_1024
{
    int m_auiShapeKeys;
    int m_pBase;
    PathingGraphNode* GetPathingGraphNodeAddress(unsigned int aiIndex);
};
// @fnv 0x006e8f80
// src: GUESS 0x006e8f80 (confidence: medium)
PathingGraphNode* BSSimpleArray_PathingNode_1024::GetPathingGraphNodeAddress(unsigned int aiIndex)
{
    return (PathingGraphNode*)((char*)m_pBase + aiIndex * 0x3C);
}

namespace fnv_006e9ab0 {
void __fastcall PathingSpline_SetParameter(void*, float);
struct RetS
{
    int _a[3];
};
struct OwnS
{
    char _pad[48];
    RetS PathingSpline_Interpolate_1(float);
    RetS PathingSpline_InterpolateNoZ(int, int);
};
// @fnv 0x006e9ab0
// src: COMMUNITY 0x006e9ab0
RetS OwnS::PathingSpline_Interpolate_1(float f)
{
    PathingSpline_SetParameter(this, f);
    return PathingSpline_InterpolateNoZ((int)((char*)this + 0x14), (int)((char*)this + 0x2c));
}
}  // namespace fnv_006e9ab0

namespace fnv_006e7a10 {

struct StageItemNode;
StageItemNode* __fastcall FUN_00717e50(void*);
struct NP3S
{
    float x;
    float y;
    float z;
};
struct LocS
{
    NP3S GetLocation();
};
struct M24
{
    float k[6];
};
struct RetS
{
    float x;
    float y;
    float z;
};
struct OwnS2
{
    M24 GetLocationAndTangent();
};
void __fastcall PathingSpline_SetParameter(void*, float);
struct FUN_0052d240_obj
{
    ~FUN_0052d240_obj();
    int SplinePath[5];
    int Key1[6];
    int Key2[6];
};
struct FUN_006e7b60 : public FUN_0052d240_obj
{
    FUN_006e7b60();
};
struct OwnS
{
    RetS PathingSpline_Interpolate(const M24&, const M24&);
};

// Clamps the spline parameter to the last node and returns the interpolated location between the surrounding nodes into aOutLoc.
} // namespace fnv_006e7a10
// @fnv 0x006e7a10
void PathingSolution::GetLocationAtSplineParameter(float afCurrentSplineParameter, NiPoint3* aOutLoc)
{
    unsigned int uiNodeIndex = (int)afCurrentSplineParameter;
    float remainder = afCurrentSplineParameter - uiNodeIndex;
    int isize = GetObjectFlags() - 1;
    if ((int)uiNodeIndex >= isize)
    {
        *(fnv_006e7a10::NP3S*)aOutLoc = ((fnv_006e7a10::LocS*)fnv_006e7a10::FUN_00717e50((void*)GetNode_006e7970(isize)))->GetLocation();
        return;
    }
    fnv_006e7a10::FUN_006e7b60 spline;
    fnv_006e7a10::PathingSpline_SetParameter(&spline, remainder);
    *(fnv_006e7a10::RetS*)aOutLoc =
        ((fnv_006e7a10::OwnS*)&spline)
            ->PathingSpline_Interpolate(
                ((fnv_006e7a10::OwnS2*)GetNode_006e7970(uiNodeIndex))->GetLocationAndTangent(),
                ((fnv_006e7a10::OwnS2*)GetNode_006e7970(uiNodeIndex + 1))->GetLocationAndTangent());
}

namespace fnv_006e84b0 {

struct M24
{
    float f[6];
};
struct OwnS2
{
    M24 GetLocationAndTangent();
};
struct FUN_006e7b60
{
    FUN_006e7b60();
    float fData[17];
};
struct FUN_0052d240_obj : public FUN_006e7b60
{
    FUN_0052d240_obj() : FUN_006e7b60()
    {}
    ~FUN_0052d240_obj();
};
struct FUN_006e8450_shell
{
    void PathingSpline_SetKeys(const M24&, const M24&);
};
struct FUN_006e9af0_S
{
    float MeasurePathLength(float, float, unsigned int);
};

} // namespace fnv_006e84b0
// @fnv 0x006e84b0
float PathingSolution::GetSplineLengthAtParameter(float afParameter)
{
    if (GetObjectFlags() == 0)
        return 0.0f;
    if (afParameter >= GetObjectFlags() - 1)
        return GetTotalPathLength();
    int inode = (int)afParameter;
    float ftotalLength = 0.0f;
    fnv_006e84b0::FUN_0052d240_obj spline;
    for (int i = 0; i < inode; ++i)
    {
        ((fnv_006e84b0::FUN_006e8450_shell*)&spline)
            ->PathingSpline_SetKeys(((fnv_006e84b0::OwnS2*)GetNode_006e7970(i))->GetLocationAndTangent(),
                           ((fnv_006e84b0::OwnS2*)GetNode_006e7970(i + 1))->GetLocationAndTangent());
        ftotalLength += ((fnv_006e84b0::FUN_006e9af0_S*)&spline)->MeasurePathLength(0.0f, 1.0f, 2);
    }
    ((fnv_006e84b0::FUN_006e8450_shell*)&spline)
        ->PathingSpline_SetKeys(((fnv_006e84b0::OwnS2*)GetNode_006e7970(inode))->GetLocationAndTangent(),
                       ((fnv_006e84b0::OwnS2*)GetNode_006e7970(inode + 1))->GetLocationAndTangent());
    ftotalLength += ((fnv_006e84b0::FUN_006e9af0_S*)&spline)->MeasurePathLength(0.0f, afParameter - inode, 2);
    return ftotalLength;
}

namespace fnv_006e8680 {
void __cdecl BSClamp_float(float&, float, float);
extern double _gModifierZero;
} // namespace fnv_006e8680
// @fnv 0x006e8680
float PathingSolution::FindSegmentAtFraction(float afPosition, float afScale, unsigned int* piNode)
{
    bool bFound;
    float fTotal;
    float fDistance;
    float fSequenceTimeRatio;
    fnv_006e8680::BSClamp_float(afPosition, 0.0f, 1.0f);
    fDistance = afPosition * afScale;
    fTotal = 0.0f;
    bFound = false;
    *piNode = 0;
    fSequenceTimeRatio = 0.0f;
    for (unsigned int i = 0; i < GetObjectFlags() - 1; ++i)
    {
        float fSeg = ComputeSplineLength(i);
        if (fTotal + fSeg >= fDistance)
        {
            *piNode = i;
            fSequenceTimeRatio = fSeg != fnv_006e8680::_gModifierZero ? (fDistance - fTotal) / fSeg : 0.0;
            bFound = true;
            break;
        }
        fTotal += fSeg;
    }
    if (!bFound)
    {
        *piNode = GetObjectFlags() - 2;
        fSequenceTimeRatio = 1.0f;
    }
    return *piNode + fSequenceTimeRatio;
}

struct BGSSaveFormBuffer;
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
typedef char _sizecheck_PathingAvoidNode[sizeof(PathingAvoidNode) == 36 ? 1 : -1];

struct FUN_006f5100_shell
{
    void VirtualPathingNode_LoadGame(BGSLoadFormBuffer*);
};
struct FUN_006e23b0_shell
{
    void PathingNode_LoadGame(BGSLoadFormBuffer*);
};
struct FUN_006e90a0_shell
{
    void FUN_006e90a0(unsigned int, bool);
    FUN_006f5100_shell* BSSimpleArray_VirtualPathingNode_1024_GetAt(unsigned int);
};
struct FUN_006e9280_shell
{
    void BSSimpleArray_PathingNode_1024_SetSize(unsigned int, bool);
    FUN_006e23b0_shell* BSSimpleArray_PathingNode_1024_GetAt(unsigned int);
};
struct _Mem_20a4
{
    void SetSize(unsigned int, bool);
};
struct FUN_006a7ad0_shell
{
    unsigned int& BSSimpleArray_NiAVObject_1024_GetAt(int);
};

// Loads pathing solution data from a BGSLoadFormBuffer: fixed fields, then virtual nodes, pathing nodes, avoid nodes, and door IDs when version >= 0x12.
// @fnv 0x006e8d50
void PathingSolution::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->BGSLoadGameBuffer::ReadTypedData((void*)&m_bHasValidPath, 1u);
    apLoadGameBuffer->BGSLoadGameBuffer::ReadTypedData((void*)&member1.firstValue, 4u);
    apLoadGameBuffer->BGSLoadGameBuffer::ReadTypedData((void*)&member1.secondValue, 4u);
    {
        unsigned int isaveGameCount = apLoadGameBuffer->BGSLoadGameBuffer::ReadElementCount();
        ((FUN_006e90a0_shell*)&member1)->FUN_006e90a0(isaveGameCount, true);
        for (unsigned int i = 0; i < isaveGameCount; i++)
        {
            FUN_006f5100_shell* virtualNode = ((FUN_006e90a0_shell*)&member1)->BSSimpleArray_VirtualPathingNode_1024_GetAt(i);
            virtualNode->VirtualPathingNode_LoadGame(apLoadGameBuffer);
        }
    }
    {
        unsigned int isaveGameCount = apLoadGameBuffer->BGSLoadGameBuffer::ReadElementCount();
        ((FUN_006e9280_shell*)&member2)->BSSimpleArray_PathingNode_1024_SetSize(isaveGameCount, true);
        for (unsigned int i = 0; i < isaveGameCount; i++)
        {
            FUN_006e23b0_shell* pathingNode = ((FUN_006e9280_shell*)&member2)->BSSimpleArray_PathingNode_1024_GetAt(i);
            pathingNode->PathingNode_LoadGame(apLoadGameBuffer);
        }
    }
    PathingAvoidNodeArray avoidNodeArray;
    {
        unsigned int isaveGameCount = apLoadGameBuffer->BGSLoadGameBuffer::ReadElementCount();
        avoidNodeArray.SetSize(isaveGameCount, true);
        for (unsigned int i = 0; i < isaveGameCount; i++)
        {
            PathingAvoidNode* avoidNode = avoidNodeArray.BSSimpleArray_PathingAvoidNode_1024_GetAt(i);
            avoidNode->LoadGame(apLoadGameBuffer);
        }
    }
    if (apLoadGameBuffer->GetVersion() >= 0x12)
    {
        unsigned int isaveGameCount = apLoadGameBuffer->BGSLoadGameBuffer::ReadElementCount();
        ((_Mem_20a4*)&member3)->SetSize(isaveGameCount, true);
        for (unsigned int i = 0; i < isaveGameCount; i++)
        {
            unsigned int* puiDoorID = &((FUN_006a7ad0_shell*)&member3)->BSSimpleArray_NiAVObject_1024_GetAt(i);
            apLoadGameBuffer->ReadFormIdentifier(puiDoorID);
        }
    }
}

struct PathVec3
{
    float x;
    float y;
    float z;
};

struct PathVecHelper
{
    void Combine(PathVec3* a, PathVec3* b);
};

struct PathMagHelper
{
    float Measure();
};

void PathClampHelper(float* t, float lo, float hi);

class FUN_006e9af0_cls
{
  public:
    void Eval(PathVec3* out, float t);
    float MeasurePathLength(float a, float b, unsigned int n);
};

// @fnv 0x006e9af0
float FUN_006e9af0_cls::MeasurePathLength(float afStart, float afEnd, unsigned int uiSteps)
{
    float sum_2;
    PathVec3 p9;
    unsigned int idx;
    PathVec3 p3;
    PathVec3 p5;
    float t;

    this->Eval(&p9, afStart);
    sum_2 = 0.0f;
    for (idx = 0; idx < uiSteps; idx++)
    {
        t = (afEnd - afStart) * (float)(idx + 1) / (float)uiSteps + afStart;
        PathClampHelper(&t, 0.0f, 1.0f);
        this->Eval(&p5, t);
        ((PathVecHelper*)&p5)->Combine(&p3, &p9);
        sum_2 = sum_2 + ((PathMagHelper*)&p3)->Measure();
        p9 = p5;
    }
    return sum_2;
}

struct Key
{
    float x, y, z, tx, ty, tz;
    Key& PathingSolution_CopyVectorPair(const Key&);
};
struct Node
{
    Key GetLocationAndTangent();
};
struct Location
{
    NiPoint3 FUN_005c3420();
};
struct Tail
{
    Location* FUN_00717e50();
};
struct SplinePath
{
    float unk00, unk04, unk08, unk0c, unk10;
    SplinePath();
    ~SplinePath();
    Key first, second;

    void PathingSpline_SetKeys(Key*, Key*);
    float MeasurePathLength(float, float, unsigned int);
    bool FindPointOnSpline(float, float, bool, float*, NiPoint3*, float);
};
// Walks the spline nodes from the given position until the remaining distance is consumed, returning the interpolated point or the tail location.
// @fnv 0x006e8790
NiPoint3 PathingSolution::GetPointAtDistance(float position, float distance)
{
    if (!GetNodeCount())
        return _NiPoint3_ZERO;
    if (position >= GetNodeCount() - 1)
        return ((Tail*)PathingSolution_GetLastNode())->FUN_00717e50()->FUN_005c3420();
    float remaining7 = distance;
    int index = (int)position;
    float parameterTmp = position - index;
    Key next2 = ((Node*)GetNode_006e7970(index + 1))->GetLocationAndTangent();
    Key current = ((Node*)GetNode_006e7970(index))->GetLocationAndTangent();
    SplinePath spline3;
    ((SplinePath*)&spline3)->PathingSpline_SetKeys(&current, &next2);
    float lengthVal = ((SplinePath*)&spline3)->MeasurePathLength(parameterTmp, 1.0f, 2);
    while (index < (int)(GetNodeCount() - 2) && lengthVal < remaining7)
    {
        remaining7 -= lengthVal;
        index = index + 1;
        current.PathingSolution_CopyVectorPair(next2);
        next2.PathingSolution_CopyVectorPair(((Node*)GetNode_006e7970(index + 1))->GetLocationAndTangent());
        ((SplinePath*)&spline3)->PathingSpline_SetKeys(&current, &next2);
        parameterTmp = 0.0f;
        lengthVal = ((SplinePath*)&spline3)->MeasurePathLength(0.0f, 1.0f, 2);
    }
    if (lengthVal > remaining7)
    {
        float result6;
        NiPoint3 point2;
        if (!(int)((SplinePath*)&spline3)->FindPointOnSpline(parameterTmp, remaining7, true, &result6, &point2, 10.0f))
        {
            point2 = (const NiPoint3&)next2;
        }
        return (const NiPoint3&)point2;
    }
    else
    {
        return ((Tail*)PathingSolution_GetLastNode())->FUN_00717e50()->FUN_005c3420();
    }
}

struct SaveBuffer
{
    void SaveData(void*, unsigned int, int);
    void SaveVariableSizedValue(unsigned int);
    void FUN_00865db0(unsigned int, int);
};
struct SaveEntryA
{
    void VirtualPathingNode_Save(SaveBuffer*);
};
struct SaveEntryB
{
    void SaveState_006e2350(SaveBuffer*);
};
struct CountView
{
    unsigned int Count();
};
struct SaveArrayA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SaveEntryA* BSSimpleArray_VirtualPathingNode_1024_GetAt(unsigned int);
};
struct SaveArrayB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SaveEntryB* GetEntry(unsigned int);
};
struct SaveArrayD
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int& GetEntry(unsigned int);
};
// Writes flags, unk18 and unk1c to the buffer, then serializes the counts and entries of first, second, a local PathingAvoidNodeArray and fourth.
// @fnv 0x006e8b10
void PathingSolutionOperations::SaveGame(SaveBuffer* buffer)
{
    buffer->SaveData(&m_bHasValidPath, 1, 0);
    buffer->SaveData(&member1.firstValue, 4, 0);
    buffer->SaveData(&member1.secondValue, 4, 0);
    unsigned int countA9 = &member1 ? ((CountView*)&member1)->Count() : 0;
    buffer->SaveVariableSizedValue(countA9);
    for (unsigned int indexA = 0; indexA < countA9; ++indexA)
    {
        SaveEntryA* entryA8 = ((SaveArrayA*)&member1)->BSSimpleArray_VirtualPathingNode_1024_GetAt(indexA);
        entryA8->VirtualPathingNode_Save(buffer);
    }
    {
        unsigned int countB8 = &member2 ? ((CountView*)&member2)->Count() : 0;
        buffer->SaveVariableSizedValue(countB8);
        for (unsigned int indexB6 = 0; indexB6 < countB8; ++indexB6)
        {
            SaveEntryB* entryB9 = ((SaveArrayB*)&member2)->GetEntry(indexB6);
            entryB9->SaveState_006e2350(buffer);
        }
    }
    PathingAvoidNodeArray avoided5;
    {
        unsigned int countCA = &avoided5 ? ((CountView*)&avoided5)->Count() : 0;
        buffer->SaveVariableSizedValue(countCA);
        for (unsigned int indexC5 = 0; indexC5 < countCA; ++indexC5)
        {
            PathingAvoidNode* entryC2 = avoided5.BSSimpleArray_PathingAvoidNode_1024_GetAt(indexC5);
            entryC2->SaveGame((BGSSaveFormBuffer*)buffer);
        }
    }
    {
        unsigned int countD8 = &member3 ? ((CountView*)&member3)->Count() : 0;
        buffer->SaveVariableSizedValue(countD8);
        for (unsigned int indexD = 0; indexD < countD8; ++indexD)
        {
            unsigned int& entryD3 = ((SaveArrayD*)&member3)->GetEntry(indexD);
            buffer->FUN_00865db0(entryD3, 0);
        }
    }
}

void __cdecl BSClamp_float(float& arfValue, float afMin, float afMax);

struct FUN_004a7290_point
{
    float FUN_004a7290() const;
};

struct FUN_006e9830_shell
{
    char pad[0x14];
    NiPoint3 kStart;
    char padCur[0x2c - 0x20];
    NiPoint3 kEnd;
    NiPoint3 PathingSpline_Interpolate_1(float afT);
    bool FindPointAtDistance(float afT, float afDistance, bool abForward, float* apfOutT, NiPoint3* apkOutPoint,
                             float afTolerance);
};

// Binary-searches the segment parameter so the point is within tolerance of afDistance from the point at afT, writing the found t and point to the outputs.
// @fnv 0x006e9830
bool FUN_006e9830_shell::FindPointAtDistance(float afT, float afDistance, bool abForward, float* apfOutT,
                                             NiPoint3* apkOutPoint, float afTolerance)
{
    if (afDistance <= afTolerance)
    {
        *apkOutPoint = PathingSpline_Interpolate_1(afT);
        *apfOutT = afT;
        return true;
    }

    float kFMaxSqr = (afDistance + afTolerance) * (afDistance + afTolerance);
    float fNewMinSqr = (afDistance - afTolerance) * (afDistance - afTolerance);
    BSClamp_float(afT, 0.0f, 1.0f);

    float fMin;
    float fHigh2;
    float fCurrentAmountNext;
    if (abForward)
    {
        fMin = afT;
        fCurrentAmountNext = fHigh2 = 1.0f;
    }
    else
    {
        fMin = 0.0f;
        fHigh2 = afT;
        fCurrentAmountNext = fMin;
    }

    NiPoint3 _kOrigin = PathingSpline_Interpolate_1(afT);
    NiPoint3 kPoint = abForward ? kEnd : kStart;
    bool bFound = false;
    while (!bFound)
    {
        kPoint = PathingSpline_Interpolate_1(fCurrentAmountNext);
        float _fLength = ((const FUN_004a7290_point*)&(_kOrigin - kPoint))->FUN_004a7290();
        if ((_fLength < fNewMinSqr && abForward) || (_fLength > kFMaxSqr && !abForward))
        {
            if (fCurrentAmountNext >= 0.99f)
            {
                bFound = false;
                break;
            }
            else
                fMin = fCurrentAmountNext;
        }
        else if ((_fLength > kFMaxSqr && abForward) || (_fLength < fNewMinSqr && !abForward))
        {
            if (fCurrentAmountNext <= 0.01f)
            {
                bFound = false;
                break;
            }
            else
                fHigh2 = fCurrentAmountNext;
        }
        else
        {
            bFound = true;
            break;
        }
        fCurrentAmountNext = (fMin + fHigh2) * 0.5;
    }

    if (!bFound)
    {
        if (abForward)
        {
            *apfOutT = 1.0f;
            *apkOutPoint = kEnd;
        }
        else
        {
            *apfOutT = 0.0f;
            *apkOutPoint = kStart;
        }
        return false;
    }
    else
    {
        *apfOutT = fCurrentAmountNext;
        *apkOutPoint = kPoint;
        return true;
    }
}
