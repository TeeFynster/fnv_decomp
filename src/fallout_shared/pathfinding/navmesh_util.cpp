// fallout_shared/pathfinding/navmesh_util.cpp: NavMesh, std, CircularArc, ASC and more (100 functions)

#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../../include/NiPointer.h"
#undef FNV64_NIPOINTER_INLINE_BODIES
#include "../../../include/NavMeshGrid.h"
#include "../../../include/NavMeshTriangle.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/FindTriangleForLocationFilter.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NavMeshInfo.h"
#include "../../../include/NavMeshClosedDoorInfo.h"
#include "../../../include/NavMeshEdgeData.h"
#include "../../../include/NavMeshEdgeVertexPair.h"
#include "../../../include/NavMeshPOVData.h"
// NavMeshVertexMap_navmesh_util: local type (was include/NavMeshVertexMap.h, which had no evidence of one real class); its methods are 0x004b9ba0 NiTMapBase<DFALL<NiTMapItem<char const *,Setting *> >,char const *,Setting *>::GetFirstPos, 0x0069b3d0 NiTMapBase<DFALL<NiTMapItem<FastNavMeshVertHandle,POVVertexData *> >,FastNavMeshVertHandle,POVVertexData *>::SetAt, 0x0069b4d0 NiTMapBase<DFALL<NiTMapItem<FastNavMeshVertHandle,POVVertexData *> >,FastNavMeshVertHandle,POVVertexData *>::GetAt, 0x0069b560 NiTMapBase<DFALL<NiTMapItem<FastNavMeshVertHandle,POVVertexData *> >,FastNavMeshVertHandle,POVVertexData *>::GetNext
#include "../../../include/TwoIntRecord.h"

class NavMeshVertexEdgeData;

class NavMeshVertexMap_navmesh_util
{
public:
    void* vtable;
    unsigned int hashSize;
    void* table;
    unsigned int count;

    NavMeshVertexMap_navmesh_util(unsigned int);
    ~NavMeshVertexMap_navmesh_util();
    void* GetFirstPos();
    bool NiTMapBase_DFALL_NiTMapItem_FastNavMeshVertHandle_POVVertexData_FastNavMeshVertHandle_POVVertexData_GetAt(TwoIntRecord, NavMeshVertexEdgeData*&);
    void SetKeyValue(TwoIntRecord, NavMeshVertexEdgeData*);
    void GetNextEntry(void*&, TwoIntRecord&, NavMeshVertexEdgeData*&);
};
#include "../../../include/NavMeshPtr.h"
#include "../../../include/NavMeshSearch.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiTPointerMap.h"
#include "../../../include/NiTMap.h"
#include "../../../include/ObstacleData.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/TwoIntRecord.h"

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
namespace std {
float abs(float);
}
bool NavMeshMath_IsPointInsideTriangle(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&, float&, float, float);

class NavMeshVertexEdgeData
{
  public:
    TwoIntRecord m_kVertexKey;
    BSSimpleArray<NavMeshEdgeData> Edges, m_kOutgoingEdges;
    NavMeshVertexEdgeData();
    ~NavMeshVertexEdgeData();
};
// NavMesh::POVPointerArray is NiTMap<unsigned short,NavMeshPOVData> (NavMesh.h names its instantiation).
typedef NiTMap<unsigned short, NavMeshPOVData> NavMeshPOVMap;

class SineCosine
{
  public:
    float sine, cosine;
    SineCosine operator-(const SineCosine&) const;
    float AngleSinCos_GetAngle() const;
};
class CircularArc
{
  public:
    SineCosine Start, End;
    int Dir;
    float GetLength(float);
};

#include "../../../include/GO.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/TESForm.h"
#include "../../../include/NiPoint2.h"

// @fnv 0x006971e0
NiPoint3 NavMesh::GetPlaneNormal(unsigned short triangleIndex)
{
    NavMeshTriangle* triangle = GetTriangle(triangleIndex);
    struct LineSegment
    {
        NiPoint3 first, second;
    } edges = {GetVertex_0068f0a0(triangle->GetVert_005582d0(1)) - GetVertex_0068f0a0(triangle->GetVert_005582d0(0)),
               GetVertex_0068f0a0(triangle->GetVert_005582d0(2)) - GetVertex_0068f0a0(triangle->GetVert_005582d0(0))};
    return edges.first.CrossProduct(edges.second);
}

// Wraps a NavMesh pointer in a NiPointer<NavMesh> and returns it.
// @fnv 0x00464fc0
NiPointer<NavMesh> MakeNavMeshPointer(NavMesh* mesh)
{
    return NiPointer<NavMesh>(mesh);
}

// Scans the closed-door info list for an entry whose triangle index matches triangleIndex and returns a pointer to it, or null if none matches.
// @fnv 0x00699af0
NavMeshClosedDoorInfo* NavMesh::GetClosedDoorInfo(unsigned short triangleIndex)
{
    for (unsigned int i = 0; i < m_kClosedDoorInfo.GetSize(); i++)
    {
        if (m_kClosedDoorInfo.GetElement(i).m_usDoorTriangleIndex == triangleIndex)
            return &m_kClosedDoorInfo.GetElement(i);
    }
    return 0;
}

// Computes the arc length from the angle between Start and End, wrapping negative angles by 2*pi and inverting when Dir is nonzero, scaled by radius.
// @fnv 0x006a07a0
float CircularArc::GetLength(float radius)
{
    SineCosine difference = End - Start;
    float angle = difference.AngleSinCos_GetAngle();
    if (Dir == 0)
    {
        if (angle < 0.0)
            return (angle + 6.2831854820251465) * radius;
        else
            return angle * radius;
    }
    else
    {
        if (angle < 0.0)
            return -angle * radius;
        else
            return (6.2831854820251465 - angle) * radius;
    }
}

// Gets the triangle's three vertices, converts them, and tests the point against them to compute height within the above/below range.
// @fnv 0x00697730
bool NavMesh::FindHeightOnTriangle(unsigned short triangleIndex, const NiPoint3& point, float& height, float above,
                                   float below)
{
    NiPoint3 first, second, third;
    NavMeshTriangle* pNavTriangle;
    pNavTriangle = GetTriangle(triangleIndex);
    first = GetVertex_0068f0a0(pNavTriangle->GetVert_005582d0(0));
    second = GetVertex_0068f0a0(pNavTriangle->GetVert_005582d0(1));
    third = GetVertex_0068f0a0(pNavTriangle->GetVert_005582d0(2));
    return NavMeshMath_IsPointInsideTriangle(first, second, third, point, height, above, below);
}

// Computes an offset from the obstacle extent, gathers triangles via FUN_006987d0, and marks each triangle closed for the given door unless already recorded.
// @fnv 0x006997e0
bool NavMesh::AddDoorObstacle(unsigned int doorID, ObstacleData* obstacle)
{
    struct DoorBounds
    {
        NiPoint3 extent, offset;
    } geometry = {obstacle->kMaxPoint - obstacle->kMinBoundsCur, NiPoint3::ZERO};
    if (std::abs(geometry.extent.x) < std::abs(geometry.extent.y))
    {
        if (std::abs(geometry.extent.x) < std::abs(geometry.extent.z))
            geometry.offset.x = -std::abs(geometry.extent.x) * 0.49000000953674316;
        else
            geometry.offset.z = -std::abs(geometry.extent.z) * 0.49000000953674316;
    }
    else
    {
        if (std::abs(geometry.extent.y) < std::abs(geometry.extent.z))
            geometry.offset.y = -std::abs(geometry.extent.y) * 0.49000000953674316;
        else
            geometry.offset.z = -std::abs(geometry.extent.z) * 0.49000000953674316;
    }
    BSSimpleArray<unsigned short> triangles;
    GetOverlappedTriangleList(obstacle, geometry.offset, &triangles);
    for (unsigned int i = 0; i < triangles.GetSize(); i++)
    {
        NavMeshClosedDoorInfo* existing = GetClosedDoorInfo(triangles.GetBufferEntry(i));
        if (!existing || existing->m_uiDoorFormID != doorID)
        {
            GetTriangle(triangles.GetBufferEntry(i))->SetFlag_00691570(0x1000);
            // Scalar storage avoids /GS instrumentation for the shared type's padding array.
            unsigned __int64 entryStorage;
            reinterpret_cast<NavMeshClosedDoorInfo*>(&entryStorage)->NavMeshClosedDoorInfo::NavMeshClosedDoorInfo();
            reinterpret_cast<NavMeshClosedDoorInfo*>(&entryStorage)->m_uiDoorFormID = doorID;
            reinterpret_cast<NavMeshClosedDoorInfo*>(&entryStorage)->m_usDoorTriangleIndex = triangles.GetBufferEntry(i);
            m_kClosedDoorInfo.Append(*reinterpret_cast<NavMeshClosedDoorInfo*>(&entryStorage));
        }
    }
    return true;
}

void __fastcall hkpShapeRayCastCollectorOutput_hkpShapeRayCastCollectorOutput(void* pThis);
void __fastcall hkpShapeRayCastOutput__reset(void* pThis);

// @fnv 0x004a3d20
// src: XBOX_PDB 0x004a3d20
void* __fastcall hkpShapeRayCastOutput_hkpShapeRayCastOutput(void* pThis)
{
    hkpShapeRayCastCollectorOutput_hkpShapeRayCastCollectorOutput(pThis);
    hkpShapeRayCastOutput__reset(pThis);
    return pThis;
}

struct FUN_005eeda0_this
{
    int pad0;
    unsigned short* pBuffer;
    unsigned short& GetBufferEntry(unsigned int aiIndex);
};

// @fnv 0x005eeda0
unsigned short& FUN_005eeda0_this::GetBufferEntry(unsigned int aiIndex)
{
    return pBuffer[aiIndex];
}

extern int DAT_010159d4;

struct Dummy0042f800
{
    void FUN_0042fcb0(int, int);
};

// @fnv 0x006917d0
// src: EXE 0x006917d0
void* __fastcall BSSimpleArray_unsigned_short_1024_BSSimpleArray(int** pThis)
{
    *pThis = &DAT_010159d4;
    reinterpret_cast<Dummy0042f800*>(pThis)->FUN_0042fcb0(0, 0);
    return pThis;
}

struct DummyA8
{
    void GetVectors(NiPoint3*, NiPoint3*);
};

// @fnv 0x006969e0
// src: COMMUNITY 0x006969e0
bool NavMesh::GetBounds_006969e0(NiPoint3* aRetMin, NiPoint3* aRetMax)
{
    reinterpret_cast<DummyA8*>(&m_kGrid)->GetVectors(aRetMin, aRetMax);
    return true;
}

struct FUN_00698580_S
{
    NiPoint3 a;
    NiPoint3 b;
    FUN_00698580_S* Segment_Segment(const NiPoint3* p, const NiPoint3* q);
};
// @fnv 0x00698580
// src: COMMUNITY 0x00698580
FUN_00698580_S* FUN_00698580_S::Segment_Segment(const NiPoint3* p, const NiPoint3* q)
{
    a = *p;
    b = *q;
    return this;
}

void __stdcall compiler_vector_constructor_iterator(void*, unsigned int, int, void*);
void FUN_006d5320();

// @fnv 0x006985c0
void* __fastcall ConstructWithVector(void* apObject)
{
    compiler_vector_constructor_iterator((char*)apObject + 4, 0x10, 2, &FUN_006d5320);
    return apObject;
}

struct FUN_006985f0_shell : public SineCosine
{
    SineCosine* CopyFloatPair(void*);
};

// Copies the first two floats from p into this object and returns this.
// @fnv 0x006985f0
SineCosine* FUN_006985f0_shell::CopyFloatPair(void* apSource)
{
    reinterpret_cast<float*>(this)[0] = static_cast<const float*>(apSource)[0];
    reinterpret_cast<float*>(this)[1] = static_cast<const float*>(apSource)[1];
    return this;
}

struct ASC
{
    float s, c;
    void _ref_006815c0();
    ASC& operator=(const ASC&);
    ASC* Multiply(ASC* out, const ASC* o);
};
// Computes the product of this ASC and another ASC into out, combining s and c with the given formulas, and returns out.
// @fnv 0x00698620
ASC* ASC::Multiply(ASC* out, const ASC* apOther)
{
    ASC ret;
    ret._ref_006815c0();
    ret.s = s * apOther->s + c * apOther->c;
    ret.c = c * apOther->s - s * apOther->c;
    out->operator=(ret);
    return out;
}

// @fnv 0x00698680
int __fastcall GetSignFlags(float* afValues)
{
    int res = 0;
    if (afValues[1] < 0.0)
        res ^= 3;
    if (afValues[0] < 0.0)
        res ^= 1;
    return res;
}

struct Sub
{
    int z[4];
    Sub();
    ~Sub();
};
struct FUN_00699450_S
{
    Sub a;
    Sub b;
    FUN_00699450_S();
};
// Constructs the object by default-constructing its two Sub members.
// @fnv 0x00699450
FUN_00699450_S::FUN_00699450_S()
{}

struct FUN_0069af60
{
    int pad[4];
    ~FUN_0069af60();
};

struct FUN_006994b0
{
    FUN_0069af60 a;
    FUN_0069af60 b;
    ~FUN_006994b0();
};

// @fnv 0x006994b0
FUN_006994b0::~FUN_006994b0()
{}

// @fnv 0x0069a660
TwoIntRecord::TwoIntRecord(NavMesh* apMesh, unsigned short ausVertex)
{
    a = reinterpret_cast<int>(apMesh);
    *reinterpret_cast<unsigned short*>(&b) = ausVertex;
}

void __fastcall InitializeNavMeshEdgeBase(NavMeshEdgeData*);

// @fnv 0x0069a6c0
NavMeshEdgeData::NavMeshEdgeData(NavMesh* apNav, unsigned short ausTri, int aiEdge)
{
    InitializeNavMeshEdgeBase(this);
    m_pLocationNavMesh = apNav;
    m_usTriangleID = ausTri;
    m_iEdgeIndex = aiEdge;
}

struct FUN_0069a700_shell : public NavMeshTriangleHandle
{
    void NavMeshPOVEdge_Set(void*);
};

// Builds a 16-bit value from bits 0-13 of the word at aEdge+4 and bits 0-1 of the word at aEdge+8 shifted left 14, storing it at this.
// @fnv 0x0069a700
// src: COMMUNITY 0x0069a700
void FUN_0069a700_shell::NavMeshPOVEdge_Set(void* aEdge)
{
    *(unsigned short*)this =
        ((*(unsigned short*)((char*)aEdge + 4) & 0x3fff) | ((*(unsigned short*)((char*)aEdge + 8) & 3) << 14));
}

extern int DAT_0106b1b8;

struct Dummy_0069af30
{
    void* vtable;
    void ResetAndWrite(int, int);
};

// Sets the vtable pointer and calls ResetAndWrite with 0, 0, then returns pThis.
// @fnv 0x0069af30
// src: XBOX_PDB 0x0069af30
Dummy_0069af30* __fastcall BSSimpleArray_NavMeshEdgeHandle_1024_BSSimpleArray_NavMeshEdgeHandle_1024(Dummy_0069af30* pThis)
{
    pThis->vtable = &DAT_0106b1b8;
    pThis->ResetAndWrite(0, 0);
    return pThis;
}

extern int DAT_0106b1b8;

class GlobalObject_00869f00
{
  public:
    void Clear(bool);
};

// @fnv 0x0069af60
// src: GUESS 0x0069af60 (confidence: medium)
void __fastcall Object_ResetVirtualTableAndClear_0069af60(GlobalObject_00869f00* apObject)
{
    *(int**)apObject = &DAT_0106b1b8;
    apObject->Clear(true);
}

struct FUN_0069b030_S
{
    int pad;
    TwoIntRecord* data;
    unsigned int BSSimpleArray_NiPoint2_1024_AddUninitialized();
    void ConstructPairCells(TwoIntRecord*, int);
    unsigned int Append(const TwoIntRecord* v);
};
// @fnv 0x0069b030
unsigned int FUN_0069b030_S::Append(const TwoIntRecord* apValue)
{
    unsigned int i = BSSimpleArray_NiPoint2_1024_AddUninitialized();
    ConstructPairCells(&data[i], 1);
    data[i] = *apValue;
    return i;
}

struct FUN_0069b310_S
{
    int pad;
    NavMeshEdgeData* data;
    unsigned int BSSimpleArray_NiPoint3_1024_AddUninitialized();
    void ConstructBounds(NavMeshEdgeData*, int);
    unsigned int AppendElement(const NavMeshEdgeData* v);
};
// Gets the current count, grows the data array by one element, copies the given element into the new slot, and returns its index.
// @fnv 0x0069b310
unsigned int FUN_0069b310_S::AppendElement(const NavMeshEdgeData* apElement)
{
    unsigned int i = BSSimpleArray_NiPoint3_1024_AddUninitialized();
    ConstructBounds(&data[i], 1);
    data[i] = *apElement;
    return i;
}

float __cdecl cos(float);
float __cdecl sin_004e44b0(float);

struct FUN_006a04e0_helper : public SineCosine
{
    void* SetFromAngle(float afAngle);
};

// Stores cos(afAngle) and FUN_004e44b0(afAngle) into the first two floats of this object and returns this.
// @fnv 0x006a04e0
void* FUN_006a04e0_helper::SetFromAngle(float afAngle)
{
    ((float*)this)[0] = cos(afAngle);
    ((float*)this)[1] = sin_004e44b0(afAngle);
    return this;
}

// @fnv 0x006bc870
NavMeshEdgeData& NavMeshEdgeData::operator=(const NavMeshEdgeData& edge)
{
    m_pLocationNavMesh = edge.m_pLocationNavMesh;
    m_usTriangleID = edge.m_usTriangleID;
    m_iEdgeIndex = edge.m_iEdgeIndex;
    return *this;
}

struct NiP2
{
    float x, y;
    NiP2();
};
struct USW
{
    unsigned short v;
};
struct IW
{
    int v;
};
bool __cdecl NavMeshMath_Find2DIntersection_006b9e90(NiP2*, NiP2*, int, int, int);
// Builds the triangle's three 2D vertices and returns the first edge index (skipping edge) for which FUN_006b9e90 succeeds, else -1.
// @fnv 0x00698060
int __fastcall FindTriangleEdge(NavMesh* self, USW usTri, IW iSkipEdge, IW a3, IW a4, IW a5)
{
    NiP2 verts[3];
    NiPoint3 pt;
    for (int i = 0; i < 3; i++)
    {
        pt = self->GetVertex_0068f0a0(self->GetTriangle(usTri.v)->GetVert_005582d0(i));
        verts[i].x = pt.x;
        verts[i].y = pt.y;
    }
    for (int j = 0; j < 3; j++)
    {
        if (j == iSkipEdge.v)
            continue;
        int k = j + 1;
        if (k == 3)
            k = 0;
        if (NavMeshMath_Find2DIntersection_006b9e90(&verts[j], &verts[k], a3.v, a4.v, a5.v))
            return j;
    }
    return -1;
}

// @fnv 0x0069a690
TwoIntRecord::TwoIntRecord(const TwoIntRecord& other)
{
    a = other.a;
    *reinterpret_cast<unsigned short*>(&b) = *reinterpret_cast<const unsigned short*>(&other.b);
}

extern unsigned int _data_011c16bc;
// @fnv 0x0069a730
NavMeshVertexEdgeData::NavMeshVertexEdgeData()
{}

struct IT
{
    IT* next;
    TwoIntRecord key;
    NavMeshVertexEdgeData* val;
};
// Looks up key in the hash table; if found, overwrites its value, otherwise allocates a new item, inserts it at the bucket head and increments count.
// @fnv 0x0069b3d0
void NavMeshVertexMap_navmesh_util::SetKeyValue(TwoIntRecord key, NavMeshVertexEdgeData* val)
{
    IT* pkItem;
    unsigned int uiIndex;
    unsigned int uiDepth;
    typedef unsigned int (__thiscall* HashFunction)(NavMeshVertexMap_navmesh_util*, TwoIntRecord);
    typedef bool (__thiscall* KeyEqualFunction)(NavMeshVertexMap_navmesh_util*, TwoIntRecord, TwoIntRecord);
    typedef IT* (__thiscall* NewItemFunction)(NavMeshVertexMap_navmesh_util*);
    typedef void (__thiscall* SetValueFunction)(NavMeshVertexMap_navmesh_util*, IT*, TwoIntRecord, NavMeshVertexEdgeData*);
    uiIndex = reinterpret_cast<HashFunction*>(vtable)[1](this, key);
    pkItem = static_cast<IT**>(table)[uiIndex];
    uiDepth = 0;
    while (pkItem)
    {
        uiDepth++;
        if (reinterpret_cast<KeyEqualFunction*>(vtable)[2](this, key, pkItem->key))
        {
            pkItem->val = val;
            return;
        }
        pkItem = pkItem->next;
    }
    pkItem = reinterpret_cast<NewItemFunction*>(vtable)[5](this);
    reinterpret_cast<SetValueFunction*>(vtable)[3](this, pkItem, key, val);
    pkItem->next = static_cast<IT**>(table)[uiIndex];
    static_cast<IT**>(table)[uiIndex] = pkItem;
    count++;
}

// Looks up key in the hash table and, if an equal entry is found, stores its value through val and returns true; otherwise returns false.
// @fnv 0x0069b4d0
// src: COMMUNITY 0x0069b4d0
bool NavMeshVertexMap_navmesh_util::NiTMapBase_DFALL_NiTMapItem_FastNavMeshVertHandle_POVVertexData_FastNavMeshVertHandle_POVVertexData_GetAt(TwoIntRecord key, NavMeshVertexEdgeData*& aOutValue)
{
    IT* pkItem;
    typedef unsigned int (__thiscall* HashFunction)(NavMeshVertexMap_navmesh_util*, TwoIntRecord);
    typedef bool (__thiscall* KeyEqualFunction)(NavMeshVertexMap_navmesh_util*, TwoIntRecord, TwoIntRecord);
    unsigned int uiIndex = reinterpret_cast<HashFunction*>(vtable)[1](this, key);
    pkItem = static_cast<IT**>(table)[uiIndex];
    while (pkItem)
    {
        if (reinterpret_cast<KeyEqualFunction*>(vtable)[2](this, key, pkItem->key))
        {
            aOutValue = pkItem->val;
            return true;
        }
        pkItem = pkItem->next;
    }
    return false;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0069a7a0(unsigned int flags);
};
// Calls the destructor on this object, frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0069a7a0
void* DelStandIn::FUN_0069a7a0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

bool __cdecl AreWideCharsEqual(const unsigned short& a, const unsigned short& b);

struct NavMeshTriList : public BSSimpleArray<unsigned short>
{
    unsigned int GetSize() const;
    const unsigned short& BSSimpleArray_unsigned_short_1024_GetAt(unsigned int auiIndex) const;
    int FindMatchingIndex(const unsigned short& arItem, unsigned int auiStart,
                          bool(__cdecl* apCompare)(const unsigned short&, const unsigned short&));
};


float __cdecl BSMIN(float a, float b);
float __cdecl BSMAX_00404010(float a, float b);
NiPoint3 __cdecl NiPoint3_TransformByMatrix3(const NiPoint3& arPt, const float* apRot);
bool __cdecl DoBoundsOverlap(const NiPoint3& a, const NiPoint3& b, const NiPoint3& c, const NiPoint3& d);
bool __cdecl NavMeshObstacleManager_IsPointInBox(const NiPoint3& arCenter, const NiPointer<ObstacleData>& arObstacle, float afHeight, float afFudge);
bool __cdecl NavMeshMath_Find2DIntersection(const NiPoint3& a, const NiPoint3& b, const NiPoint3& c, const NiPoint3& d);
extern const float DAT_01015f5c;

// @fnv 0x006987d0
// src: COMMUNITY 0x006987d0
void NavMesh::GetOverlappedTriangleList(const NiPointer<ObstacleData>& apObstacle, const NiPoint3& afFudge,
                                  NavMeshTriList* apRetTriangles)
{
    unsigned int istartRow = 0;
    unsigned int istartCol = 0;
    unsigned int iendRow = 0;
    unsigned int iendCol = 0;

    m_kGrid.GetCellCoords(reinterpret_cast<const NiPoint3*>(apObstacle->pad58)[0], istartRow, istartCol);
    m_kGrid.GetCellCoords(reinterpret_cast<const NiPoint3*>(apObstacle->pad58)[1], iendRow, iendCol);

    NiPoint3 cornersLocalSpace[4];
    cornersLocalSpace[0] = NiPoint3(apObstacle->kMinBoundsCur.x - afFudge.x, apObstacle->kMinBoundsCur.y - afFudge.y,
                                      apObstacle->kMinBoundsCur.z);
    cornersLocalSpace[1] = NiPoint3(apObstacle->kMinBoundsCur.x - afFudge.x, apObstacle->kMaxPoint.y + afFudge.y,
                                      apObstacle->kMinBoundsCur.z);
    cornersLocalSpace[2] = NiPoint3(apObstacle->kMaxPoint.x + afFudge.x, apObstacle->kMaxPoint.y + afFudge.y,
                                      apObstacle->kMinBoundsCur.z);
    cornersLocalSpace[3] = NiPoint3(apObstacle->kMaxPoint.x + afFudge.x, apObstacle->kMinBoundsCur.y - afFudge.y,
                                      apObstacle->kMinBoundsCur.z);

    float fzheight = reinterpret_cast<const NiPoint3*>(apObstacle->pad58)[1].z - reinterpret_cast<const NiPoint3*>(apObstacle->pad58)[0].z;

    for (unsigned int r = istartRow; r <= iendRow; r++)
    {
        for (unsigned int c = istartCol; c <= iendCol; c++)
        {
            NavMeshTriList* parray = m_kGrid.NavMeshGrid_GetTriangleArray(c, r);
            if (parray)
            {
                for (unsigned int i = 0; i < parray->GetSize(); i++)
                {
                    if (apRetTriangles->FindMatchingIndex(parray->BSSimpleArray_unsigned_short_1024_GetAt(i), 0, AreWideCharsEqual) != -1)
                        continue;
                    NavMeshTriangle* ptri = GetTriangle(parray->BSSimpleArray_unsigned_short_1024_GetAt(i));
                    if (ptri->GetFlag(0x20))
                        continue;

                    NiPoint3 wtriMin(3.402823466e+38f, 3.402823466e+38f, 3.402823466e+38f);
                    NiPoint3 wtriMax(DAT_01015f5c, DAT_01015f5c, DAT_01015f5c);
                    for (int v = 0; v < 3; v++)
                    {
                        const NiPoint3* vertLocation = &GetVertex_0068f0a0(ptri->GetVert_005582d0(v));
                        wtriMin.x = BSMIN(wtriMin.x, vertLocation->x);
                        wtriMin.y = BSMIN(wtriMin.y, vertLocation->y);
                        wtriMin.z = BSMIN(wtriMin.z, vertLocation->z);
                        wtriMax.x = BSMAX_00404010(wtriMax.x, vertLocation->x);
                        wtriMax.y = BSMAX_00404010(wtriMax.y, vertLocation->y);
                        wtriMax.z = BSMAX_00404010(wtriMax.z, vertLocation->z);
                    }
                    wtriMax.z += 128.0;

                    if (!DoBoundsOverlap(reinterpret_cast<const NiPoint3*>(apObstacle->pad58)[0] - afFudge, reinterpret_cast<const NiPoint3*>(apObstacle->pad58)[1] + afFudge, wtriMin,
                                         wtriMax))
                        continue;

                    bool bOverlap = false;
                    float fdontCare;
                    if (NavMeshObstacleManager_IsPointInBox(GetNavMeshData(parray->BSSimpleArray_unsigned_short_1024_GetAt(i)), apObstacle, fzheight, 128.0f))
                    {
                        bOverlap = true;
                    }
                    else if (FindHeightOnTriangle(parray->BSSimpleArray_unsigned_short_1024_GetAt(i),
                                                  apObstacle->kTranslate, fdontCare, fzheight,
                                                  128.0f))
                    {
                        bOverlap = true;
                    }
                    else
                    {
                        for (unsigned int triv = 0; triv < 3; triv++)
                        {
                            unsigned int triw = triv + 1;
                            if (triw == 3)
                                triw = 0;
                            NiPoint3 vert1 = NiPoint3_TransformByMatrix3(GetVertex_0068f0a0(ptri->GetVert_005582d0(triv)) -
                                                              apObstacle->kTranslate,
                                                          (const float*)apObstacle->acRotate);
                            NiPoint3 vert2 = NiPoint3_TransformByMatrix3(GetVertex_0068f0a0(ptri->GetVert_005582d0(triw)) -
                                                              apObstacle->kTranslate,
                                                          (const float*)apObstacle->acRotate);
                            for (unsigned int boxv = 0; boxv < 4; boxv++)
                            {
                                unsigned int boxw = boxv + 1;
                                if (boxw == 4)
                                    boxw = 0;
                                NiPoint3 box1 = cornersLocalSpace[boxv];
                                NiPoint3 box2 = cornersLocalSpace[boxw];
                                if (NavMeshMath_Find2DIntersection(vert1, vert2, box1, box2))
                                {
                                    bOverlap = true;
                                    break;
                                }
                            }
                            if (bOverlap)
                                break;
                        }
                    }
                    if (bOverlap)
                        apRetTriangles->ReserveIndex(parray->BSSimpleArray_unsigned_short_1024_GetAt(i));
                }
            }
        }
    }
}

struct VertMapItem
{
    VertMapItem* m_pkNext;
    TwoIntRecord m_key;
    NavMeshVertexEdgeData* m_val;
};

// Reads the key and value from the item at pos, then advances pos to the next item in the chain or the next non-empty hash bucket, or null.
// @fnv 0x0069b560
void NavMeshVertexMap_navmesh_util::GetNextEntry(void*& pos, TwoIntRecord& arKey, NavMeshVertexEdgeData*& val)
{
    VertMapItem* pkItem = (VertMapItem*)pos;
    arKey = pkItem->m_key;
    val = pkItem->m_val;
    if (pkItem->m_pkNext)
    {
        pos = pkItem->m_pkNext;
        return;
    }
    typedef unsigned int (__thiscall* HashFunction)(NavMeshVertexMap_navmesh_util*, TwoIntRecord);
    unsigned int i = reinterpret_cast<HashFunction*>(vtable)[1](this, pkItem->m_key);
    for (++i; i < hashSize; ++i)
    {
        pkItem = static_cast<VertMapItem**>(table)[i];
        if (pkItem)
        {
            pos = pkItem;
            return;
        }
    }
    pos = 0;
}

struct FUN_0069b120_stub
{
    void RemoveArrayRange(int a, int b);
};

// Calls FUN_0069b120 on the stub at this+0xd0 with arg and 1.
// @fnv 0x00699590
void NavMesh::ForwardToStub(int arg)
{
    reinterpret_cast<FUN_0069b120_stub*>(&m_kObstacleUndoData)->RemoveArrayRange(arg, 1);
}

struct Flt
{
    operator unsigned int() const;
};

struct Arr
{
    Flt* GetAt(int);
};

// @fnv 0x00699630
// src: COMMUNITY 0x00699630
int NavMesh::GetUndoDataIndexForObstacle(int param1, unsigned int* apuiValue)
{
    int idx = this->FindEntryIndex(param1);
    if (idx != -1)
    {
        *apuiValue = reinterpret_cast<Arr*>(&m_kObstacleUndoData)->GetAt(idx)->operator unsigned int();
        return idx;
    }
    *apuiValue = 0;
    return -1;
}

struct FUN_00699790_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    unsigned int m_iFourthElementInteger;  // offset 0xc
    int GetBits13To15();
};

// @fnv 0x00699790
int FUN_00699790_shell::GetBits13To15()
{
    return (m_iFourthElementInteger & 0xe000) >> 13;
}

struct FUN_0069af80_shell
{
    void* __thiscall BSSimpleArray_NavMeshSearchLink_1024_Allocate(int count);
};
// Allocates a new byte array of count * 12 bytes and returns a pointer to it.
// @fnv 0x0069af80
// src: COMMUNITY 0x0069af80
void* __thiscall FUN_0069af80_shell::BSSimpleArray_NavMeshSearchLink_1024_Allocate(int count)
{
    return new unsigned char[count * 12];
}

namespace std {
float __cdecl abs(float);
}

extern double _gModifierZero;

// Builds per-vertex edge lists from triangle edges, pairs edges into portals, and assigns each triangle the nearest portal vertex within a radius.
// @fnv 0x00699b60
void NavMesh::BuildPortalPOVs()
{
    reinterpret_cast<NavMeshPOVMap&>(POVPointerArray).RemoveAll();
    m_kAdditionalIndexList.Clear(true);
    NavMeshVertexMap_navmesh_util kNavMeshVertexLookup(37);
    unsigned int itriCount = NavMesh_GetTriangleCount();
    void* it;
    for (unsigned int i = 0; i < itriCount; ++i)
    {
        NavMeshTriangle* ptri = GetTriangle(i);
        for (int e = 0; e < 3; ++e)
        {
            if (ptri->GetEdgeExtraInfo_0068f2c0(e) == 0xFFFF)
            {
                NavMeshEdgeData hedge(this, i, e);
                TwoIntRecord hvert1(this, ptri->GetVert_005582d0(e));
                NavMeshVertexEdgeData* pdata1;
                if (!kNavMeshVertexLookup.NiTMapBase_DFALL_NiTMapItem_FastNavMeshVertHandle_POVVertexData_FastNavMeshVertHandle_POVVertexData_GetAt(hvert1, pdata1))
                {
                    pdata1 = new NavMeshVertexEdgeData;
                    pdata1->m_kVertexKey = hvert1;
                    kNavMeshVertexLookup.SetKeyValue(hvert1, pdata1);
                }
                pdata1->Edges.AppendElement(hedge);
                TwoIntRecord hvert2(this, ptri->GetVert_005582d0((e + 1) % 3));
                NavMeshVertexEdgeData* pdata2;
                if (!kNavMeshVertexLookup.NiTMapBase_DFALL_NiTMapItem_FastNavMeshVertHandle_POVVertexData_FastNavMeshVertHandle_POVVertexData_GetAt(hvert2, pdata2))
                {
                    pdata2 = new NavMeshVertexEdgeData;
                    pdata2->m_kVertexKey = hvert2;
                    kNavMeshVertexLookup.SetKeyValue(hvert2, pdata2);
                }
                pdata2->Edges.AppendElement(hedge);
            }
            else if (ptri->IsEdgeFlagSet(e))
            {
                NavMeshEdgeData hedge(this, i, e);
                TwoIntRecord hvert1(this, ptri->GetVert_005582d0(e));
                NavMeshVertexEdgeData* pdata1;
                if (!kNavMeshVertexLookup.NiTMapBase_DFALL_NiTMapItem_FastNavMeshVertHandle_POVVertexData_FastNavMeshVertHandle_POVVertexData_GetAt(hvert1, pdata1))
                {
                    pdata1 = new NavMeshVertexEdgeData;
                    pdata1->m_kVertexKey = hvert1;
                    kNavMeshVertexLookup.SetKeyValue(hvert1, pdata1);
                }
                pdata1->m_kOutgoingEdges.AppendElement(hedge);
                TwoIntRecord hvert2(this, ptri->GetVert_005582d0((e + 1) % 3));
                NavMeshVertexEdgeData* pdata2;
                if (!kNavMeshVertexLookup.NiTMapBase_DFALL_NiTMapItem_FastNavMeshVertHandle_POVVertexData_FastNavMeshVertHandle_POVVertexData_GetAt(hvert2, pdata2))
                {
                    pdata2 = new NavMeshVertexEdgeData;
                    pdata2->m_kVertexKey = hvert2;
                    kNavMeshVertexLookup.SetKeyValue(hvert2, pdata2);
                }
                pdata2->m_kOutgoingEdges.AppendElement(hedge);
            }
        }
    }

    it = kNavMeshVertexLookup.GetFirstPos();
    while (it)
    {
        TwoIntRecord hvert;
        NavMeshVertexEdgeData* pdata;
        kNavMeshVertexLookup.GetNextEntry(it, hvert, pdata);
        unsigned int iedgeCount = pdata->Edges.GetSize();
        unsigned int iportalEdgeCount = pdata->m_kOutgoingEdges.GetSize();
        if (iedgeCount + iportalEdgeCount == 2)
        {
            NavMeshEdgeData hdataEdge0;
            NavMeshEdgeData hdataEdge1;
            if (iedgeCount == 2)
            {
                hdataEdge0 = pdata->Edges.Object_GetIndexedValue_006a1440(0);
                hdataEdge1 = pdata->Edges.Object_GetIndexedValue_006a1440(1);
            }
            else if (iedgeCount == 1)
            {
                hdataEdge0 = pdata->Edges.Object_GetIndexedValue_006a1440(0);
                hdataEdge1 = pdata->m_kOutgoingEdges.Object_GetIndexedValue_006a1440(0);
            }
            else
            {
                continue;
            }
            NavMeshEdgeData hedge1;
            NavMeshEdgeData hedge2;
            const NiPoint3* pverts[3];
            NavMeshEdgeVertexPair verts1 = NavMesh_GetEdgeVertices_0(hdataEdge0.m_usTriangleID, hdataEdge0.m_iEdgeIndex);
            NavMeshEdgeVertexPair verts2 = NavMesh_GetEdgeVertices_0(hdataEdge1.m_usTriangleID, hdataEdge1.m_iEdgeIndex);
            if (verts1.p1 == verts2.p2)
            {
                hedge1 = hdataEdge0;
                hedge2 = hdataEdge1;
                pverts[0] = verts1.p2;
                pverts[1] = verts1.p1;
                pverts[2] = verts2.p1;
            }
            else if (verts1.p2 == verts2.p1)
            {
                hedge1 = hdataEdge1;
                hedge2 = hdataEdge0;
                pverts[0] = verts2.p2;
                pverts[1] = verts2.p1;
                pverts[2] = verts1.p1;
            }
            else
            {
                continue;
            }
            NiPoint3 edge1 = *pverts[0] - *pverts[1];
            NiPoint3 edge2 = *pverts[2] - *pverts[1];
            edge1.z = 0;
            edge2.z = 0;
            edge1.ComputeMagnitude();
            edge2.ComputeMagnitude();
            NiPoint3 cross = edge1.Cross(edge2);
            float fdot = edge1.DotProduct(edge2);
            bool badd = false;
            if (fdot > _gModifierZero)
            {
                if (cross.z < (double)0.1f)
                {
                    badd = true;
                    if (cross.z > _gModifierZero)
                    {
                        NiPoint3 temp = edge1;
                        edge1 = edge2;
                        edge2 = temp;
                    }
                }
            }
            else if (cross.z < -(double)0.1f)
            {
                badd = true;
            }
            if (badd || iedgeCount == 1)
            {
                NavMeshPOVData pov;
                pov.m_kFirstEdge.Set(hedge1);
                pov.m_kSecondEdge.Set(hedge2);
                reinterpret_cast<NavMeshPOVMap&>(POVPointerArray).SetAt(*reinterpret_cast<const unsigned short*>(&hvert.b), pov);
            }
        }
    }

    it = kNavMeshVertexLookup.GetFirstPos();
    while (it)
    {
        TwoIntRecord hvert;
        NavMeshVertexEdgeData* pdata;
        kNavMeshVertexLookup.GetNextEntry(it, hvert, pdata);
        delete pdata;
    }

    const float afValueAfterThirdFloat = 128.0f;
    for (unsigned int i = 0; i < itriCount; ++i)
    {
        NiPoint3 circumCenter = GetCircumCenter(i);
        NiPoint3 vertLoc = GetVertex_0068f0a0(GetTriangle(i)->GetVert_005582d0(0));
        float fradius = (vertLoc - circumCenter).NiPoint3_XYLength();
        float fmaxRadius = fradius + afValueAfterThirdFloat;
        float fmaxRadiusSqr = fmaxRadius * fmaxRadius;
        unsigned short iClosestPOV = 0xFFFF;
        float fclosestPOVSqrDist = fmaxRadiusSqr * fmaxRadiusSqr;
        void* it = reinterpret_cast<NavMeshPOVMap&>(POVPointerArray).GetFirstPos();
        while (it)
        {
            unsigned short usCurrentVertexIndex;
            NavMeshPOVData data;
            reinterpret_cast<NavMeshPOVMap&>(POVPointerArray).GetNext(it, usCurrentVertexIndex, data);
            NiPoint3 delta = GetVertex_0068f0a0(usCurrentVertexIndex) - circumCenter;
            float fsqrDist = delta.GetSquaredXYLength();
            if (fsqrDist < fclosestPOVSqrDist && std::abs(delta.z) < 180.0)
            {
                fclosestPOVSqrDist = fsqrDist;
                iClosestPOV = usCurrentVertexIndex;
            }
        }
        m_kAdditionalIndexList.ReserveIndex(iClosestPOV);
    }
}

extern "C" void __cdecl NavMeshMath_Find2DIntersection_006ba010(const NiPoint2& a, const NiPoint2& b, const NiPoint2& c, const NiPoint2& d);

// @fnv 0x00696540
// src: XBOX_PDB 0x00696540
void NavMeshMath_Find2DIntersection(const NiPoint3* aSegment1Start, const NiPoint3* aSegment2Start, const NiPoint3* aSegment1End,
                  const NiPoint3* aSegment2End)
{
    NavMeshMath_Find2DIntersection_006ba010(NiPoint2(aSegment1Start->x, aSegment1Start->y), NiPoint2(aSegment2Start->x, aSegment2Start->y),
                 NiPoint2(aSegment1End->x, aSegment1End->y), NiPoint2(aSegment2End->x, aSegment2End->y));
}

struct FUN_006967c0_shell
{
    int f0;
    char pad[32];
    int f24;
    int NavMeshGrid_GetTriangleArray(int a, int b);
};
// @fnv 0x006967c0
// src: COMMUNITY 0x006967c0
int FUN_006967c0_shell::NavMeshGrid_GetTriangleArray(int a, int b)
{
    int t = b * f0 + a;
    return (t << 4) + f24;
}

struct Vec00696a10
{
    int v0;
    int v1;
    int v2;
};
struct Obj00696a10
{
    char pad[12];
    Vec00696a10 m1;
    Vec00696a10 m2;
    void GetVectors(Vec00696a10*, Vec00696a10*);
};
// Copies the object's two Vec00696a10 members into the caller-supplied output vectors.
// @fnv 0x00696a10
void Obj00696a10::GetVectors(Vec00696a10* pVec1, Vec00696a10* pVec2)
{
    *pVec1 = m1;
    *pVec2 = m2;
}

struct Holder
{
    void FUN_004a3c90(Holder*);
    Holder* hkpShapeRayCastCollectorOutput_hkpShapeRayCastCollectorOutput_00696ca0(Holder*);
};
// Copies the float at offset 0x10, the int at 0x14 and the 64-bit value at 0x18 from p into this after calling FUN_004a3c90, then returns this.
// @fnv 0x00696ca0
// src: XBOX_PDB 0x00696ca0
Holder* Holder::hkpShapeRayCastCollectorOutput_hkpShapeRayCastCollectorOutput_00696ca0(Holder* apSource)
{
    this->FUN_004a3c90(apSource);
    *(float*)((char*)this + 0x10) = *(float*)((char*)apSource + 0x10);
    *(int*)((char*)this + 0x14) = *(int*)((char*)apSource + 0x14);
    *(__int64*)((char*)this + 0x18) = *(__int64*)((char*)apSource + 0x18);
    return this;
}

// Returns true if FindTriangleForLocation finds a triangle (result not 0xFFFF) for the given position and filter.
// @fnv 0x00697670
bool NavMesh::IsLocationOnNavMesh(const NiPoint3& aPos, FindTriangleForLocationFilter* apFilter)
{
    if (FindTriangleForLocation(aPos, apFilter) != 0xFFFF)
        return true;
    else
        return false;
}

struct Dummy698030
{
    int _p[3];
    unsigned int f12;
    unsigned int NavMeshTriangle_GetEdgeCover(unsigned short a1);
};
// Shifts f12 right by a1*6+0x10 and returns the low 4 bits of the result.
// @fnv 0x00698030
// src: XBOX_PDB 0x00698030
unsigned int Dummy698030::NavMeshTriangle_GetEdgeCover(unsigned short ausIndex)
{
    unsigned int result;
    {
        unsigned int shift = ausIndex * 6 + 0x10;
        result = f12 >> shift;
    }
    return result & 0xF;
}

struct FUN_00698300_shell
{
    void _ref_006815c0();
    FUN_00698300_shell* ProcessAndReturnValue_00698300();
};
// @fnv 0x00698300
// src: GUESS 0x00698300 (confidence: low)
FUN_00698300_shell* FUN_00698300_shell::ProcessAndReturnValue_00698300()
{
    ((FUN_00698300_shell*)((char*)this + 8))->_ref_006815c0();
    return this;
}

// Looks up an index for a via FUN_00699630 and, if found, forwards it with b to UndoToPosition and returns the result.

// @fnv 0x00698fc0
// src: COMMUNITY 0x00698fc0
bool NavMesh::RemoveObstacle(int a, int b)
{
    int idx;
    {
        unsigned int tmp;
        idx = GetUndoDataIndexForObstacle(a, &tmp);
    }
    if (idx == -1)
        return false;
    return UndoToPosition(idx, b);
}

// Returns the larger of the two unsigned arguments.
// @fnv 0x00699760
unsigned int MaxUnsigned(unsigned int auiValue, unsigned short ausValue)
{
    unsigned int c;
    if (auiValue > ausValue)
        c = auiValue;
    else
        c = ausValue;
    return c;
}

struct S0069afb0
{
    int ProcessEntries_0069afb0(unsigned short, int);
};

// The shared one-argument bool overload cannot represent this two-argument integer entry.
// @fnv 0x006997b0
int __fastcall ForwardTriangleObstacle(NavMesh* self, USW a, IW b)
{
    return reinterpret_cast<S0069afb0*>(self->pTriangleToObstacleMap)->ProcessEntries_0069afb0(a.v, b.v);
}

// Exe 0x00699a30: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct NavmeshOffset08View
{
    unsigned int GetFlags();
};
struct ActorAvoidanceDataArray
{
    void FUN_00983720(unsigned int, unsigned int);
};
struct BSXFlags_shell
{
    void ClearFlags(unsigned int);
};
struct S006950d0
{
    NavMeshClosedDoorInfo* GetElement(unsigned int);
};

// @fnv 0x00699a30
// src: COMMUNITY 0x00699a30
bool NavMesh::Navmesh_RemoveClosedDoor(unsigned int doorID)
{
    unsigned int i = 0;
    for (; i < reinterpret_cast<NavmeshOffset08View*>(&m_kClosedDoorInfo)->GetFlags(); ++i)
    {
        if (reinterpret_cast<S006950d0*>(&m_kClosedDoorInfo)->GetElement(i)->m_uiDoorFormID == doorID)
        {
            if (reinterpret_cast<S006950d0*>(&m_kClosedDoorInfo)->GetElement(i)->m_usDoorTriangleIndex < NavMesh_GetTriangleCount())
            {
                ((BSXFlags_shell*)GetTriangle(reinterpret_cast<S006950d0*>(&m_kClosedDoorInfo)->GetElement(i)->m_usDoorTriangleIndex))
                    ->ClearFlags(0x1000);
            }
            reinterpret_cast<ActorAvoidanceDataArray*>(&m_kClosedDoorInfo)->FUN_00983720(i, 1);
            --i;
        }
    }
    return true;
}

struct FUN_0069b2f0
{
    int _d[4];
    ~FUN_0069b2f0();
};
struct FUN_0069a7d0
{
    int _pad[2];
    FUN_0069b2f0 m1;
    FUN_0069b2f0 m2;
    ~FUN_0069a7d0();
};
// Destructor for the object; it destroys the two embedded members and returns.
// @fnv 0x0069a7d0
FUN_0069a7d0::~FUN_0069a7d0()
{}

namespace fnv_0069a940 {
bool __cdecl AreWideCharsEqual(const unsigned short&, const unsigned short&);

struct NavMeshTriList
{
    int FindMatchingIndex(const unsigned short&, unsigned int,
                          bool(__cdecl*)(const unsigned short&, const unsigned short&));
};

struct GlobalObject_00869f00
{
    void Clear(bool);
    BSSimpleArray<unsigned short> m_kAdditionalIndexList;
};

}  // namespace fnv_0069a940

// Clears object, then for each of the triangle's three vertices appends it to object's array if found in the tri list, returning the count.
// @fnv 0x0069a940
// src: GUESS 0x0069a940 (confidence: medium)
unsigned int NavMesh::AppendTriangleVerticesInList(unsigned short triangle, BSSimpleArray<unsigned short>* object)
{
    object->Clear(false);
    unsigned int count4 = 0;
    NavMeshTriangle* navMeshTriangle = GetTriangle(triangle);
    for (int i3 = 0; i3 < 3; ++i3)
    {
        unsigned short vertex3 = navMeshTriangle->GetVert_005582d0(i3);
        if (reinterpret_cast<fnv_0069a940::NavMeshTriList*>(&m_kAdditionalData)
                ->FindMatchingIndex(vertex3, 0, fnv_0069a940::AreWideCharsEqual) != -1)
        {
            object->ReserveIndex(vertex3);
            ++count4;
        }
    }
    return count4;
}

struct FUN_0069b0a0_shell
{
    void LookupValue(unsigned short, unsigned int);
};

// @fnv 0x0069a9d0
// src: GUESS 0x0069a9d0 (confidence: medium)
void NavMesh::LookupPOVValueWithInitialization(unsigned short a1, unsigned int a2)
{
    if (reinterpret_cast<NavMeshPOVMap*>(&POVPointerArray)->IsEmpty())
        InitializeNavMeshData();
    reinterpret_cast<FUN_0069b0a0_shell*>(&POVPointerArray)->LookupValue(a1, a2);
}

struct FUN_0069b240_Holder
{
    int field_0;
    unsigned short* field_4;
    unsigned int field_8;
    int FindMatchingIndex(int, unsigned int, bool(__cdecl*)(unsigned short*, int));
};
// Scans field_4 from start to field_8, calling func on each element with a, and returns the first matching index or -1.
// @fnv 0x0069b240
int FUN_0069b240_Holder::FindMatchingIndex(int aiValue, unsigned int start, bool(__cdecl* func)(unsigned short*, int))
{
    unsigned int i;
    for (i = start; i < field_8; ++i)
    {
        if (field_4 && func(field_4 + i, aiValue))
            return (int)i;
    }
    return -1;
}

namespace fnv_006b39a0 {
struct EH
{
    int a;
    int b;
    int c;
    EH& operator=(EH const&);
};
struct C006b39a0
{
    C006b39a0& CopyFields_006b39a0(C006b39a0 const&);
};
// Copies the first field, an EH at offset 8, and three ints at offsets 0x14, 0x18 and 0x1c from rhs into this, returning *this.
// @fnv 0x006b39a0
// src: GUESS 0x006b39a0 (confidence: medium)
C006b39a0& C006b39a0::CopyFields_006b39a0(C006b39a0 const& rhs)
{
    *(TwoIntRecord*)this = *(TwoIntRecord*)&rhs;
    *(EH*)((char*)this + 8) = *(EH*)((char*)&rhs + 8);
    *(int*)((char*)this + 0x14) = *(int*)((char*)&rhs + 0x14);
    *(int*)((char*)this + 0x18) = *(int*)((char*)&rhs + 0x18);
    *(int*)((char*)this + 0x1c) = *(int*)((char*)&rhs + 0x1c);
    return *this;
}
}  // namespace fnv_006b39a0

typedef char _sizecheck_PathingLocation[sizeof(PathingLocation) == 40 ? 1 : -1];

// @fnv 0x006dcee0
PathingLocation::PathingLocation(const NiPoint3& a1, TESObjectCELL* apCell, TESWorldSpace* apWorldspace)
{
    SetLocationData(a1, apCell, apWorldspace);
}

// Computes index as c * m0 + b and calls the array element's method with a.
// @fnv 0x00696500
// src: COMMUNITY 0x00696500
void NavMeshGrid::SetTriangleData(unsigned short ausValue, unsigned int b, unsigned int c)
{
    int index = c * m_uiGridIndex + b;
    TESFileRecordLoader[index].ReserveIndex(ausValue);
}

struct Sub0069d4b0
{
    void __thiscall NavMeshGrid_GetTriangleDataForAABB(int a, int b, int c);
};

// The shared header has no three-argument grid forwarding member yet.
// @fnv 0x00696c00
void __fastcall ForwardNavMeshGrid(NavMesh* self, IW aiArg1, IW aiArg2, IW aiArg3)
{
    reinterpret_cast<Sub0069d4b0&>(self->m_kGrid).NavMeshGrid_GetTriangleDataForAABB(aiArg1.v, aiArg2.v, aiArg3.v);
}

struct S50
{
    char _pad[0x50];
    int f50;
    void AssignFrom(S50* p);
    S50* hkpWorldRayCastOutput_hkpWorldRayCastOutput_00696c30(S50* p);
};
// Calls AssignFrom on p, copies p->f50 into this->f50, and returns this.
// @fnv 0x00696c30
// src: XBOX_PDB 0x00696c30
S50* S50::hkpWorldRayCastOutput_hkpWorldRayCastOutput_00696c30(S50* apSource)
{
    AssignFrom(apSource);
    f50 = apSource->f50;
    return this;
}

struct MidCopy
{
    char _pad[32];
    struct Inner
    {
        unsigned int d[8];
    } inner;
    unsigned int tail;
    MidCopy& hkpShapeRayCastCollectorOutput_hkpShapeRayCastCollectorOutput_00696ca0(const MidCopy&);
    MidCopy& AssignFrom(const MidCopy&);
};
// @fnv 0x00696c60
MidCopy& MidCopy::AssignFrom(const MidCopy& other)
{
    hkpShapeRayCastCollectorOutput_hkpShapeRayCastCollectorOutput_00696ca0(other);
    inner = other.inner;
    tail = other.tail;
    return *this;
}

extern void* DAT_0106b1f4;
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);

struct FUN_0069b360_shell
{
    void* __thiscall ConstructBuffer(unsigned int a);
};

// @fnv 0x0069b360
void* __thiscall FUN_0069b360_shell::ConstructBuffer(unsigned int a)
{
    *(void**)this = &DAT_0106b1f4;
    *(unsigned int*)((char*)this + 4) = a;
    *(unsigned int*)((char*)this + 0xc) = 0;
    unsigned int uiSize = *(unsigned int*)((char*)this + 4) * 4;
    *(void**)((char*)this + 8) = _NiMalloc(uiSize);
    memset(*(void**)((char*)this + 8), 0, *(unsigned int*)((char*)this + 4) * 4);
    return this;
}

// Tests arPoint against triangle ausTri, computes arZ, and if a callback is given calls its Test with the point raised by arZ.
// @fnv 0x00697810
bool NavMesh::TestPointOnTriangle(unsigned short ausTri, const NiPoint3& arPoint, float& arZ,
                                         FindTriangleForLocationFilter* apCallback)
{
    if (!apCallback)
        return FindHeightOnTriangle(ausTri, arPoint, arZ, 3.4028234663852886e+38f, 3.4028234663852886e+38f);
    NiPoint3 v1;
    bool bResult;
    {
        NiPoint3 v0;
        NiPoint3 v2;
        NavMeshTriangle* ptri = GetTriangle(ausTri);
        v1 = GetVertex_0068f0a0(ptri->GetVert_005582d0(0));
        v0 = GetVertex_0068f0a0(ptri->GetVert_005582d0(1));
        v2 = GetVertex_0068f0a0(ptri->GetVert_005582d0(2));
        bResult = NavMeshMath_IsPointInsideTriangle(*(const NiPoint3*)&v1, *(const NiPoint3*)&v0, *(const NiPoint3*)&v2, arPoint, arZ,
                               3.4028234663852886e+38f, 3.4028234663852886e+38f);
    }
    if (bResult && apCallback)
    {
        NiPoint3 p = arPoint;
        p.z += arZ;
        // The shared vf00 declaration does not yet describe this callback's signature.
        typedef bool(__thiscall* TriangleFilterTest)(FindTriangleForLocationFilter*, const NiPoint3&, NavMesh*,
                                                   unsigned short, NiPoint3&);
        return (*reinterpret_cast<TriangleFilterTest**>(apCallback))[0](apCallback, arPoint, this, ausTri, p);
    }
    else
    {
        return bResult;
    }
}

// Tests whether arPoint lies inside triangle ausTriangle in XY, writes the interpolated Z to apfZ, and checks the Z offset against afAbove/afBelow.
// @fnv 0x00697980
bool NavMesh::GetTriangleHeightAtPoint(unsigned short ausTriangle, const NiPoint3& arPoint, float afAbove,
                                              float afBelow, float* apfHeight)
{
    float fY0;
    {
        float fY2;
        {
            const NiPoint3* pVertex0;
            {
                float fWeight0;
                {
                    float fInvDet;
                    {
                        float fWeight1;
                        {
                            float fDZ;
                            {
                                float fC;
                                {
                                    float fDet;
                                    {
                                        float fX0;
                                        {
                                            const NiPoint3* pVertex2;
                                            {
                                                float fX2;
                                                {
                                                    float fX1;
                                                    {
                                                        float fY1;
                                                        {
                                                            NavMeshTriangle* pTri;
                                                            {
                                                                const NiPoint3* pVertex1;
                                                                pTri = GetTriangle(ausTriangle);
                                                                pVertex0 = &GetVertex_0068f0a0(pTri->GetVert_005582d0(0));
                                                                pVertex1 = &GetVertex_0068f0a0(pTri->GetVert_005582d0(1));
                                                                pVertex2 = &GetVertex_0068f0a0(pTri->GetVert_005582d0(2));
                                                                fDet = (pVertex1->x - pVertex0->x) *
                                                                           (pVertex2->y - pVertex0->y) -
                                                                       (pVertex2->x - pVertex0->x) *
                                                                           (pVertex1->y - pVertex0->y);
                                                                if (fDet == 0.0)
                                                                    return false;
                                                                fX1 = pVertex1->x - arPoint.x;
                                                                fX2 = pVertex2->x - arPoint.x;
                                                                fY1 = pVertex1->y - arPoint.y;
                                                                fY2 = pVertex2->y - arPoint.y;
                                                                fInvDet = 1.0f / fDet;
                                                                fWeight0 = (fX1 * fY2 - fX2 * fY1) * fInvDet;
                                                                if (fWeight0 < 0.0)
                                                                    return false;
                                                                fX0 = pVertex0->x - arPoint.x;
                                                                fY0 = pVertex0->y - arPoint.y;
                                                                fWeight1 = (fX2 * fY0 - fX0 * fY2) * fInvDet;
                                                                if (fWeight1 < 0.0)
                                                                    return false;
                                                                fC = (fX0 * fY1 - fX1 * fY0) * fInvDet;
                                                                if (fC < 0.0)
                                                                    return false;
                                                                *apfHeight = fWeight0 * pVertex0->z +
                                                                             fWeight1 * pVertex1->z + fC * pVertex2->z;
                                                                fDZ = arPoint.z - *apfHeight;
                                                                if (fDZ > afAbove)
                                                                    return false;
                                                                else if (-afBelow > fDZ)
                                                                    return false;
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

extern double DAT_01011588;
// Computes the circumcenter of the triangle's three vertices in the XY plane and returns it with Z set to the highest vertex Z.
// @fnv 0x00697290
// src: COMMUNITY 0x00697290
NiPoint3 NavMesh::GetCircumCenter(unsigned short apTriangle)
{
    float xdo;
    float a2;
    // Raw vector storage avoids default-constructor calls absent from the original.
    float circumcenter[3];
    float p1[3];
    float denominator;
    float p2[3];
    float ydo;
    float xao;
    float b2;
    float p0[3];
    float yao;
    float numerator;
    float Z;
    reinterpret_cast<NiPoint3&>(p0) = GetVertex_0068f0a0(GetTriangle(apTriangle)->GetVert_005582d0(0));
    reinterpret_cast<NiPoint3&>(p1) = GetVertex_0068f0a0(GetTriangle(apTriangle)->GetVert_005582d0(1));
    reinterpret_cast<NiPoint3&>(p2) = GetVertex_0068f0a0(GetTriangle(apTriangle)->GetVert_005582d0(2));
    xdo = reinterpret_cast<NiPoint3&>(p1).x - reinterpret_cast<NiPoint3&>(p0).x;
    ydo = reinterpret_cast<NiPoint3&>(p1).y - reinterpret_cast<NiPoint3&>(p0).y;
    xao = reinterpret_cast<NiPoint3&>(p2).x - reinterpret_cast<NiPoint3&>(p0).x;
    yao = reinterpret_cast<NiPoint3&>(p2).y - reinterpret_cast<NiPoint3&>(p0).y;
    a2 = xdo * xdo + ydo * ydo;
    b2 = xao * xao + yao * yao;
    numerator = xdo * yao - xao * ydo;
    denominator = DAT_01011588 / numerator;
    Z = reinterpret_cast<NiPoint3&>(p2).z;
    if (reinterpret_cast<NiPoint3&>(p0).z >= reinterpret_cast<NiPoint3&>(p1).z && reinterpret_cast<NiPoint3&>(p0).z >= reinterpret_cast<NiPoint3&>(p2).z)
        Z = reinterpret_cast<NiPoint3&>(p0).z;
    else if (reinterpret_cast<NiPoint3&>(p1).z >= reinterpret_cast<NiPoint3&>(p2).z)
        Z = reinterpret_cast<NiPoint3&>(p1).z;
    reinterpret_cast<NiPoint3&>(circumcenter).Set(reinterpret_cast<NiPoint3&>(p0).x - (ydo * b2 - yao * a2) * denominator, (xdo * b2 - xao * a2) * denominator + reinterpret_cast<NiPoint3&>(p0).y, Z);
    return reinterpret_cast<NiPoint3&>(circumcenter);
}

// Tests each triangle edge except aIgnoreEdge for intersection with the segment aStartPoint-aEndPoint and returns the first crossing edge index, or -1.
// @fnv 0x00698320
int NavMesh::FindCrossedEdge(unsigned short ausTri, int aIgnoreEdge, const NiPoint3* aStartPoint,
                                    const NiPoint3* aEndPoint)
{
    NiPoint3 edgeVerts[3];
    NavMeshTriangle* ptri = GetTriangle(ausTri);
    edgeVerts[0] = GetVertex_0068f0a0(ptri->GetVert_005582d0(0));
    edgeVerts[1] = GetVertex_0068f0a0(ptri->GetVert_005582d0(1));
    edgeVerts[2] = GetVertex_0068f0a0(ptri->GetVert_005582d0(2));
    for (int i = 0; i < 3; i++)
    {
        if (i == aIgnoreEdge)
            continue;
        int j = i + 1;
        if (j == 3)
            j = 0;
        float fa1 = (edgeVerts[i].x - aEndPoint->x) * (edgeVerts[j].y - aEndPoint->y) -
                    (edgeVerts[i].y - aEndPoint->y) * (edgeVerts[j].x - aEndPoint->x);
        float fa2 = (edgeVerts[i].x - aStartPoint->x) * (edgeVerts[j].y - aStartPoint->y) -
                    (edgeVerts[i].y - aStartPoint->y) * (edgeVerts[j].x - aStartPoint->x);
        float fa3 = (aStartPoint->x - edgeVerts[i].x) * (aEndPoint->y - edgeVerts[i].y) -
                    (aStartPoint->y - edgeVerts[i].y) * (aEndPoint->x - edgeVerts[i].x);
        float fa4 = (aStartPoint->x - edgeVerts[j].x) * (aEndPoint->y - edgeVerts[j].y) -
                    (aStartPoint->y - edgeVerts[j].y) * (aEndPoint->x - edgeVerts[j].x);
        if (fa1 * fa2 <= 0.0 && fa3 * fa4 <= 0.0)
        {
            if (fa1 == 0.0)
                continue;
            if (fa4 == 0.0)
                continue;
            return i;
        }
    }
    return -1;
}

namespace fnv_0069a830 {
// Exe 0x0069a830: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct NavmeshOffset08View
{
    unsigned int GetFlags();
};
struct DA00694f80
{
    unsigned short& GetAt(int);
};
struct FUN_0069b0a0_shell
{
    bool LookupValue(unsigned short, unsigned int);
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};

}  // namespace fnv_0069a830

// @fnv 0x0069a830
int NavMesh::CollectTrianglePOVs(unsigned short triangle, BSSimpleArray<unsigned short, 1024>* povs)
{
    if (reinterpret_cast<NavMeshPOVMap&>(POVPointerArray).IsEmpty())
        InitializeNavMeshData();
    ((fnv_0069a830::GlobalObject_00869f00*)povs)->Clear(false);
    int iAddedCount = 0;
    NavMeshTriangle* pNavTriangle = GetTriangle(triangle);
    for (int i = 0; i < 3; i++)
    {
        unsigned short m_usVertexId = pNavTriangle->GetVert_005582d0(i);
        unsigned int uiPOV;
        if (((fnv_0069a830::FUN_0069b0a0_shell*)&POVPointerArray)->LookupValue(m_usVertexId, (unsigned int)&uiPOV))
        {
            povs->ReserveIndex(m_usVertexId);
            iAddedCount++;
        }
    }
    if (triangle < ((fnv_0069a830::NavmeshOffset08View*)&m_kAdditionalIndexList)->GetFlags() &&
        ((fnv_0069a830::DA00694f80*)&m_kAdditionalIndexList)->GetAt(triangle) != 0xFFFF)
    {
        povs->ReserveIndex(((fnv_0069a830::DA00694f80*)&m_kAdditionalIndexList)->GetAt(triangle));
        iAddedCount++;
    }
    return iAddedCount;
}

struct Helper62d0
{
    void* operator=(const void*);
};

struct FUN_0069afb0_shell
{
    virtual void v0();
    virtual void* v1(unsigned short a);
    virtual bool v2(unsigned short a, unsigned short b);
    void* p;
    void** list;
    bool ProcessEntries_0069afb0(unsigned short a, Helper62d0& out);
};

// @fnv 0x0069afb0
// src: GUESS 0x0069afb0 (confidence: low)
bool FUN_0069afb0_shell::ProcessEntries_0069afb0(unsigned short a, Helper62d0& out)
{
    void* item = v1(a);
    void* node = list[*(unsigned int*)&item];
    while (node)
    {
        if (v2(a, *(unsigned short*)((char*)node + 4)))
        {
            out = (const char*)node + 8;
            return true;
        }
        node = *(void**)node;
    }
    return false;
}

namespace fnv_006be6f0 {
// Exe 0x006be6f0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct NavmeshOffset08View
{
    unsigned int GetFlags();
};
struct DA00694f80
{
    unsigned short& GetAt(int i);
};
struct NavMeshTriList
{
    int FindMatchingIndex(const unsigned short&, unsigned int,
                          bool(__cdecl*)(const unsigned short&, const unsigned short&));
    void BSSimpleArray_RemoveFast_1(int, bool);
};
bool __cdecl AreWideCharsEqual(const unsigned short&, const unsigned short&);
struct FUN_006be6f0_shell
{
    void MarkNavMeshTriangles();
};
// @fnv 0x006be6f0
void FUN_006be6f0_shell::MarkNavMeshTriangles()
{
    for (unsigned int i = 0; i < ((NavmeshOffset08View*)((char*)*(unsigned int**)((char*)this + 8) + 0x60))->GetFlags(); i++)
    {
        int idx = ((NavMeshTriList*)((char*)*(unsigned int**)((char*)this + 0) + 0xe4))
                      ->FindMatchingIndex(((DA00694f80*)((char*)*(unsigned int**)((char*)this + 8) + 0x60))->GetAt(i),
                                          0, AreWideCharsEqual);
        if (idx != -1)
            ((NavMeshTriList*)((char*)*(unsigned int**)((char*)this + 0) + 0xe4))->BSSimpleArray_RemoveFast_1(idx, true);
    }
}
}  // namespace fnv_006be6f0

namespace fnv_00697590 {
struct FUN_00690e10_shell
{
    bool NavMeshTriangle_HasEdgeExtraInfo(void);
};

}  // namespace fnv_00697590

// Clears the array, then adds each triangle index that has an edge whose linked door ID equals doorID, and returns whether any were added.
// @fnv 0x00697590
bool NavMesh::CollectTrianglesForDoor(unsigned int doorID, BSSimpleArray<unsigned int>* array)
{
    array->SetSize(0, true);
    array->GrowCapacity(100);

    for (unsigned int triangleIndex = 0;
         triangleIndex < Triangles.GetSize();
         ++triangleIndex)
    {
        NavMeshTriangle* triangle =
            GetTriangle(static_cast<unsigned short>(triangleIndex));

        if (reinterpret_cast<fnv_00697590::FUN_00690e10_shell*>(triangle)->NavMeshTriangle_HasEdgeExtraInfo())
        {
            for (int edgeIndex = 0; edgeIndex < 3; ++edgeIndex)
            {
                if (triangle->IsEdgeFlagSet(edgeIndex))
                {
                    if (reinterpret_cast<unsigned int*>(GetEdge(
                            triangle->GetEdgeExtraInfo_0068f2c0(edgeIndex)))[1] == doorID)
                    {
                        unsigned int value;
                        value = triangleIndex;
                        array->Add(value);
                        break;
                    }
                }
            }
        }
    }

    return 0 < array->GetSize();
}

namespace fnv_006995c0 {
// Exe 0x006995c0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct NavmeshOffset08View
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};

}  // namespace fnv_006995c0

// Scans the array at offset 0xd0 and compares the smart pointer at offset 0xc with arg, or returns -1.
// 0x004b0460 is NiPointer<NiAVObject>::operator==(const NiPointer&), also bound by navmeshobstacletask.cpp.
// @fnv 0x006995c0
int NavMesh::FindEntryIndex(void* apTarget)
{
    unsigned int i = 0;
    for (; i < reinterpret_cast<fnv_006995c0::NavmeshOffset08View*>(&m_kObstacleUndoData)->GetFlags(); ++i)
    {
        if (((NiPointer<NiAVObject>*)(((GO*)((char*)reinterpret_cast<fnv_006995c0::Arr*>(&m_kObstacleUndoData)->GetAt(i)))->operator unsigned int() + 0xc))
                ->
                operator==(*reinterpret_cast<const NiPointer<NiAVObject>*>(apTarget)))
            return i;
    }
    return -1;
}

namespace fnv_006bbb80 {
extern int _data_011c16bc;

struct FUN_006bbc30
{
    int padding[4];

    FUN_006bbc30();
    ~FUN_006bbc30();

    int _ref_006815c0();
};

struct FUN_006bf7d0
{
    int padding[5];

    FUN_006bf7d0(int, int, int);
    ~FUN_006bf7d0();
};

struct FUN_006bfa10
{
    int padding[5];

    FUN_006bfa10(int, int, int);
};

struct FUN_006bbb80
{
    int base;
    GO go;
    int gap;
    FUN_006bbc30 memberC;
    FUN_006bf7d0 member1C;
    FUN_006bfa10 member30;

    FUN_006bbb80();
};

// Initializes the object's members, constructing go with 0 and member1C and member30 with 0x100, 0, and the result of memberC._ref_006815c0().
// @fnv 0x006bbb80
FUN_006bbb80::FUN_006bbb80()
    : go(0), memberC(), member1C(0x100, 0, memberC._ref_006815c0()), member30(0x100, 0, memberC._ref_006815c0())
{}
}  // namespace fnv_006bbb80

struct SwapTriangle : NavMeshTriangle
{
    void SetArrayElement(int edge, unsigned short vertex);
    void SetSlotValue(int edge, unsigned short neighbor);
    void SetArrayValue(int edge, unsigned short neighbor);
    bool NavMeshTriangle_HasCoverOrWallFlags();
    void GetPackedFlags(int edge, unsigned short*, unsigned char*, unsigned char*);
    void SetPackedField(int edge, unsigned short, unsigned char, unsigned char);
};

// @fnv 0x00695660
void NavMesh::SwapTriangleEdges(unsigned short triangle)
{
    SwapTriangle* tri5 = reinterpret_cast<SwapTriangle*>(FUN_005582f0(triangle));
    unsigned short vertex8 = tri5->GetVert_005582d0(1);
    tri5->SetArrayElement(1, tri5->GetVert_005582d0(0));
    tri5->SetArrayElement(0, vertex8);
    bool firstExternal3 = tri5->IsEdgeFlagSet(0);
    bool secondExternalX = tri5->IsEdgeFlagSet(1);
    unsigned short neighbor;
    if (secondExternalX)
        neighbor = tri5->GetEdgeExtraInfo_0068f2c0(1);
    else
        neighbor = tri5->GetEdgeExtraInfo_0068f2c0(1);
    if (firstExternal3)
        tri5->SetSlotValue(1, tri5->GetEdgeExtraInfo_0068f2c0(0));
    else
        tri5->SetArrayValue(1, tri5->GetEdgeExtraInfo_0068f2c0(0));
    if (secondExternalX)
        tri5->SetSlotValue(0, neighbor);
    else
        tri5->SetArrayValue(0, neighbor);
    if (tri5->NavMeshTriangle_HasCoverOrWallFlags())
    {
        unsigned short aFirstLink;
        unsigned short secondLinkB;
        unsigned char firstEdge8;
        unsigned char secondEdge9;
        unsigned char firstFlags;
        unsigned char secondFlags;
        tri5->GetPackedFlags(0, &aFirstLink, &firstEdge8, &firstFlags);
        tri5->GetPackedFlags(1, &secondLinkB, &secondEdge9, &secondFlags);
        tri5->SetPackedField(0, secondLinkB, secondFlags, secondEdge9);
        tri5->SetPackedField(1, aFirstLink, firstFlags, firstEdge8);
    }
}

struct FUN_006957d0_Class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0C;
    bool NavMeshTriangle_HasCoverOrWallFlags();
};

// @fnv 0x006957d0
// src: COMMUNITY 0x006957d0
bool FUN_006957d0_Class::NavMeshTriangle_HasCoverOrWallFlags()
{
    return 0u < (unk0C & 0xFFF0000);
}

// @fnv 0x006957f0
void NavMesh::ComputeBounds(NiPoint3& outMin, NiPoint3& outMax)
{
    if (Triangles.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
        return;
    NiPoint3 kMinimum;
    NiPoint3 _maximum;
    NiPoint3 _point;
    NavMeshTriangle* triangle5 = FUN_005582f0(0);
    _maximum = GetVertex_0068f0a0(triangle5->GetVert_005582d0(0));
    kMinimum = _maximum;
    for (unsigned int i = 0; i < NavMesh_GetTriangleCount(); ++i)
    {
        triangle5 = FUN_005582f0(static_cast<unsigned short>(i));
        for (int j = 0; j < 3; ++j)
        {
            _point = GetVertex_0068f0a0(triangle5->GetVert_005582d0(j));
            if (_point.x < kMinimum.x)
                kMinimum.x = _point.x;
            else if (_point.x > _maximum.x)
                _maximum.x = _point.x;
            if (_point.y < kMinimum.y)
                kMinimum.y = _point.y;
            else if (_point.y > _maximum.y)
                _maximum.y = _point.y;
            if (_point.z < kMinimum.z)
                kMinimum.z = _point.z;
            else if (_point.z > _maximum.z)
                _maximum.z = _point.z;
        }
    }
    outMin = kMinimum;
    outMax = _maximum;
}

class NavTri
{
  public:
    bool IsEdgeSet(int aiEdge);
};

// @fnv 0x00697010
// src: COMMUNITY 0x00697010
bool NavMesh::FindClosestOpenEdgeForLocation(const NiPoint3& arPoint, float afRadius, unsigned short* apTri, int* apEdge, bool abFlip)
{
    unsigned short usBestTri5 = 0;
    int iBestEdge = -1;
    float fBest2 = 3.402823466e+38f;
    float fRadiusSq2 = afRadius * afRadius;
    float fMinZ8 = arPoint.z - 64.0;
    float fMaxZ7 = arPoint.z + 180.0;
    if (abFlip)
    {
        fMinZ8 = arPoint.z - 180.0;
        fMaxZ7 = arPoint.z + 64.0;
    }
    unsigned int uiCount5 = Triangles.GetSize();
    for (unsigned int i5 = 0; i5 < uiCount5; i5++)
    {
        NavTri* pTri_ = reinterpret_cast<NavTri*>(GetTriangle((unsigned short)i5));
        for (int jTmp = 0; jTmp < 3; jTmp++)
        {
            if (!pTri_->IsEdgeSet(jTmp))
            {
                NavMeshEdgeVertexPair verts8 = NavMesh_GetEdgeVertices_0((unsigned short)i5, jTmp);
                NiPoint3 mid3 =
                    (reinterpret_cast<const NiPoint3&>(*verts8.p1) + reinterpret_cast<const NiPoint3&>(*verts8.p2)) * 0.5f;
                NiPoint3 diff = mid3 - reinterpret_cast<const NiPoint3&>(arPoint);
                float fDist2D = diff.GetSquaredXYLength();
                float fDZ = diff.z * diff.z;
                float fDist_2 = fDist2D + fDZ;
                if (fDist2D < fBest2 && ((mid3.z < fMaxZ7 && mid3.z > fMinZ8) || fDist_2 <= fRadiusSq2 - fDZ))
                {
                    usBestTri5 = (unsigned short)i5;
                    iBestEdge = jTmp;
                    fBest2 = fDist_2;
                }
            }
        }
    }
    if (iBestEdge == -1)
        return false;
    *apTri = usBestTri5;
    *apEdge = iBestEdge;
    return true;
}

// Computes the 2D circumcenter of the triangle's three vertices and writes it into apCenter with z set to 0.
// @fnv 0x00697440
// src: XBOX_PDB 0x00697440
void NavMesh::GetCircumCenter2D(unsigned short ausTriangle, NiPoint3* apCenter)
{
    NiPoint3 kA = GetVertex_0068f0a0(GetTriangle(ausTriangle)->GetVert_005582d0(0));
    NiPoint3 kB9 = GetVertex_0068f0a0(GetTriangle(ausTriangle)->GetVert_005582d0(1));
    NiPoint3 kC2 = GetVertex_0068f0a0(GetTriangle(ausTriangle)->GetVert_005582d0(2));
    float fDX = kB9.x - kA.x;
    float fB8 = kB9.y - kA.y;
    float fC = kC2.x - kA.x;
    float fCy3 = kC2.y - kA.y;
    float fLenB = fDX * fDX + fB8 * fB8;
    float fLen8 = fC * fC + fCy3 * fCy3;
    float fDenom = fDX * fCy3 - fC * fB8;
    float fScale = 0.5 / fDenom;
    apCenter->x = kA.x - (fB8 * fLen8 - fCy3 * fLenB) * fScale;
    apCenter->y = (fDX * fLen8 - fC * fLenB) * fScale + kA.y;
    apCenter->z = 0.0f;
}

// NavMesh: get the extra info for a triangle edge, creating and linking a fresh record when missing,
// then reset its link fields.

struct EdgeExtraInfo
{
    int m_iType;
    void* m_pkPortal;
    unsigned short m_usLinkedTriangle;
    EdgeExtraInfo();
};

struct D76A0Triangle
{
    void SetEdgeExtraInfo(int m_iEdgeNumber, unsigned short usIndex);
};

struct D76A0TriangleArray
{
    D76A0Triangle& GetAt(int iIndex) const;
};

// Returns the edge extra info for a triangle edge, creating it if missing, then clears its portal and linked triangle.
// @fnv 0x006976a0
EdgeExtraInfo* NavMesh::GetOrCreateEdgeInfo(unsigned short m_usTriangleID, int m_iEdgeNumber)
{
    EdgeExtraInfo* pkInfo = GetEdgeInfo(m_usTriangleID, m_iEdgeNumber);
    if (!pkInfo)
    {
        EdgeExtraInfo kNewInfo;
        reinterpret_cast<D76A0TriangleArray&>(Triangles)
            .GetAt(m_usTriangleID)
            .SetEdgeExtraInfo(m_iEdgeNumber, AddEdgeInfo(kNewInfo));
        pkInfo = GetEdgeInfo(m_usTriangleID, m_iEdgeNumber);
    }
    pkInfo->m_pkPortal = 0;
    pkInfo->m_usLinkedTriangle = 0xffff;
    return pkInfo;
}

struct TriangleList
{
    unsigned int FUN_0044ddc0();
    const unsigned short& BSSimpleArray_unsigned_short_1024_GetAt(unsigned int index);
};

// Looks up the triangle list at point, tests each triangle with GetTriangleHeightAtPoint, and returns true on the first hit, writing z.
// @fnv 0x00697b70
bool NavMesh::FindTriangleZ(const NiPoint3& point, float above, float below, float* z)
{
    TriangleList* triangles = 0;
    m_kGrid.GetTriListAtPosition(point, reinterpret_cast<NavMeshTriList*&>(triangles));
    if (!triangles)
        return false;
    unsigned int count = triangles->FUN_0044ddc0();
    for (unsigned int index = 0; index < count; ++index)
    {
        unsigned short triangle = triangles->BSSimpleArray_unsigned_short_1024_GetAt(index);
        if (GetTriangleHeightAtPoint(triangle, point, above, below, z))
            return true;
    }
    return false;
}

// 0x006b5560 is not declared by the shared NavMeshInfo header yet.
void InitializeNavMeshInfoFromMesh();
typedef void (__thiscall* InitializeNavMeshInfoFromMeshFunction)(NavMeshInfo*, NavMesh*);

struct b9_nav
{
    NavMeshInfo* FUN_00693d70();
    void RegisterNavMeshInfo();
};

struct b9_tab
{
    b9_nav* TES_GetNavMeshInfoMap(void* p);
};

extern int DAT_011dea10;

// Keep the original bool result; the shared member is currently declared void.
// @fnv 0x006986d0
bool __fastcall InitializeNavMeshInfo(NavMesh* self)
{
    NavMeshInfo* r =
        ((b9_tab*)DAT_011dea10)->TES_GetNavMeshInfoMap(reinterpret_cast<void*>(self->GetHavokWorldObjectCountInSceneGraph_0084e3a0()))->FUN_00693d70();
    if (self->GetNavMeshInfo_0068efb0() == 0)
    {
        NavMeshInfo* q = new NavMeshInfo();
        reinterpret_cast<InitializeNavMeshInfoFromMeshFunction>(InitializeNavMeshInfoFromMesh)(q, self);
        self->PathingRequestCoveredMove_SetCombatCoverLocation(q);
        q->SetNavMesh(self);
        ((b9_tab*)DAT_011dea10)->TES_GetNavMeshInfoMap(q)->RegisterNavMeshInfo();
        return true;
    }
    else
    {
        reinterpret_cast<InitializeNavMeshInfoFromMeshFunction>(InitializeNavMeshInfoFromMesh)(r, self);
        return false;
    }
}

struct SearchContext
{
    unsigned int unk00;
    unsigned int unk04;
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
    unsigned int unk40;
    unsigned int unk44;
    SearchContext();
    ~SearchContext();
    bool NavMeshObstacleCutter_SplitNavMeshFromObstacle(void* owner, int first, int second);
};
// Builds a SearchContext and forwards the two ints and this to SearchContext::FUN_006bbd30, returning its result.
// @fnv 0x00698f40
bool NavMeshSearch::Search(int first, int second)
{
    SearchContext searchContext;
    bool result = searchContext.NavMeshObstacleCutter_SplitNavMeshFromObstacle(this, first, second);
    return result;
}

struct FUN_006993c0_sub
{
    int unk00, unk04, unk08, unk0c;
    ~FUN_006993c0_sub();
};

struct FUN_006993c0_local
{
    FUN_006993c0_sub a;
    FUN_006993c0_sub b;
    FUN_006993c0_local();
    ~FUN_006993c0_local();
};

struct Dummy0044ddc0_sub
{
    int FUN_0044ddc0();
};

// Walks the obstacle undo entries backwards, calling UndoToPosition with each index and a local object.
// @fnv 0x006993c0
// src: XBOX_PDB 0x006993c0
void NavMesh::ClearAllObstacles()
{
    FUN_006993c0_local local;
    for (int i = reinterpret_cast<Dummy0044ddc0_sub&>(m_kObstacleUndoData).FUN_0044ddc0() - 1; i != -1; i--)
    {
        UndoToPosition(static_cast<unsigned int>(i), &local);
    }
}

unsigned int __cdecl MaxUnsigned(unsigned int uiHash, unsigned short usValue);

class B99690Triangle
{
  public:
    unsigned short GetBits13To15();
};

class B99690IndexArray
{
  public:
    unsigned int GetSize();
    unsigned short& GetAt(int iIndex);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct B99690Edge
{
    unsigned short m_usTriangle;
};

class B99690EdgeArray
{
  public:
    unsigned int GetSize();
    B99690Edge* GetAt(unsigned int uiIndex);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

// The shared ComputeTriangleHash signature names NavMeshInfo, but 0x00699690 receives obstacle undo data:
// its triangle and edge arrays are at +0x20 and +0x30, not fields of the per-navmesh record.
// Hashes the triangle values of all triangles and edge triangles referenced by pkInfo and returns the accumulated hash.
// @fnv 0x00699690
unsigned int NavMesh::ComputeTriangleHash(NavMeshInfo* pkInfo)
{
    unsigned int uiHash = 0;
    for (unsigned int i = 0; i < reinterpret_cast<B99690IndexArray*>(reinterpret_cast<char*>(pkInfo) + 0x20)->GetSize(); i++)
        uiHash = MaxUnsigned(
            uiHash,
            reinterpret_cast<B99690Triangle*>(GetTriangle(
                reinterpret_cast<B99690IndexArray*>(reinterpret_cast<char*>(pkInfo) + 0x20)->GetAt(i)))->GetBits13To15());
    for (unsigned int j = 0; j < reinterpret_cast<B99690EdgeArray*>(reinterpret_cast<char*>(pkInfo) + 0x30)->GetSize(); j++)
        uiHash = MaxUnsigned(
            uiHash,
            reinterpret_cast<B99690Triangle*>(GetTriangle(
                reinterpret_cast<B99690EdgeArray*>(reinterpret_cast<char*>(pkInfo) + 0x30)->GetAt(j)->m_usTriangle))
                ->GetBits13To15());
    return uiHash;
}

struct FUN_0069b0a0_item
{
    FUN_0069b0a0_item* next;
    unsigned short key;
    unsigned char pad[2];
    unsigned int val;
};
struct U4v
{
    unsigned int v;
};
class FUN_0069b0a0_cls
{
  public:
    virtual unsigned int GetPad();
    virtual unsigned int KeyToHashIndex(unsigned short key);
    virtual bool IsKeyEqual(unsigned short a, unsigned short b);
    unsigned int m_uiHashSize;
    FUN_0069b0a0_item** m_ppkHashTable;
    unsigned int m_uiCount;
    bool LookupValue(unsigned short key, unsigned int* out);
};
// Hashes key, walks the bucket chain comparing keys, and on a match copies the item's value to out and returns true; otherwise returns false.
// @fnv 0x0069b0a0
bool FUN_0069b0a0_cls::LookupValue(unsigned short key, unsigned int* puiOut)
{
    unsigned int uiBucketIndex = KeyToHashIndex(key);
    FUN_0069b0a0_item* pItem = m_ppkHashTable[uiBucketIndex];
    while (pItem != 0)
    {
        if (IsKeyEqual(key, pItem->key))
        {
            *(U4v*)puiOut = *(U4v*)((char*)pItem + 6);
            return true;
        }
        pItem = pItem->next;
    }
    return false;
}

struct ItemResource
{
    void NiRefObject_DecRefCount();
};

struct ResourceHolder
{
    ItemResource* Modelloader_GetReferencedThis();
};

struct Item
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    ResourceHolder resource;
};

struct ItemPointer
{
    Item* item;
};

struct FUN_0045cec0
{
    int first;
    int second;
    ~FUN_0045cec0();
};

struct FUN_00982610
{
    int first;
    int second;
    int third;
    int fourth;
    ~FUN_00982610();
};

struct FUN_006bf890
{
    int first;
    int second;
    int third;
    int fourth;
    int fifth;
    ~FUN_006bf890();
};

struct FUN_006bfad0
{
    ItemPointer* entries;
    unsigned int count;
    unsigned int capacity;
    unsigned int flags;

    unsigned int FUN_0044ddc0();
    ItemPointer* FUN_00877a30(unsigned int index);
    ~FUN_006bfad0();
};

struct FUN_006bbc50
{
    int identifier;
    FUN_0045cec0 first;
    FUN_00982610 second;
    FUN_006bf890 third;
    FUN_006bfad0 fourth;
    ~FUN_006bbc50();
};

// Iterates the fourth container's entries and calls FUN_00401970 on each item's resource when FUN_00559450 returns non-null.
// @fnv 0x006bbc50
FUN_006bbc50::~FUN_006bbc50()
{
    for (unsigned int i = 0; i < fourth.FUN_0044ddc0(); ++i)
    {
        if (fourth.FUN_00877a30(i)->item->resource.Modelloader_GetReferencedThis())
        {
            fourth.FUN_00877a30(i)->item->resource.Modelloader_GetReferencedThis()->NiRefObject_DecRefCount();
        }
    }
}

extern const float DAT_0106b158;

struct FUN_006bf220_sub
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    BSSimpleArray<unsigned short> Items;
};

struct FUN_006bf220_cls
{
    NavMesh* m_00;
    int unk04;
    FUN_006bf220_sub* m_08;
    bool NavMeshObstacleCutter_IsPointInOverlappedArea(void* a1);
};

// @fnv 0x006bf220
// src: COMMUNITY 0x006bf220
bool FUN_006bf220_cls::NavMeshObstacleCutter_IsPointInOverlappedArea(void* a1)
{
    float local;
    for (unsigned int i = 0; i < m_08->Items.GetSize(); i++)
    {
        if (m_00->FUN_00697730(m_08->Items.GetBufferEntry(i), *static_cast<const NiPoint3*>(a1), local,
                              DAT_0106b158, DAT_0106b158))
        {
            return true;
        }
    }
    return false;
}

TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);
struct P507Array
{
    void* table;
    void* data;
    unsigned int size, capacity;
    unsigned int FUN_0044ddc0();
    void** FUN_00877a30(unsigned int);
    void BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(unsigned int, bool);
};
class SA0 : public P507Array
{
  public:
    SA0();
    ~SA0();
};
struct P507Info
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    P507Array first, second;
    unsigned int Modelloader_GetReferencedThis();
    bool FUN_00690860(NavMeshPtr&);
};
struct P507Manager
{
    void GetAllNavMeshInfo();
};
struct P507Global
{
    P507Manager* TES_GetNavMeshInfoMap(SA0*);
};

struct P507Edge
{
    int unk00;
    unsigned int owner;
};

// @fnv 0x006953b0
void __cdecl RemoveNavMeshId(unsigned int id)
{
    if (!id)
        return;
    SA0 infos;
    ((P507Global*)DAT_011dea10)->TES_GetNavMeshInfoMap(&infos)->GetAllNavMeshInfo();
    for (unsigned int i = 0; i < infos.FUN_0044ddc0(); ++i)
    {
        P507Info* firstCount = (P507Info*)*infos.FUN_00877a30(i);
        int info = firstCount->first.FUN_0044ddc0();
        int secondCount = firstCount->second.FUN_0044ddc0();
        for (int j = 0; j < info + secondCount; ++j)
        {
            unsigned int entry;
            if (j < info)
                entry = (unsigned int)*firstCount->first.FUN_00877a30(j);
            else
                entry = (unsigned int)*firstCount->second.FUN_00877a30(j - info);
            if (entry == id)
            {
                NavMeshPtr mesh;
                if (!firstCount->FUN_00690860(mesh))
                {
                    TESForm* nav = TESForm_GetFormByNumericID(firstCount->Modelloader_GetReferencedThis());
                    NavMesh* form = dynamic_cast<NavMesh*>(nav);
                    mesh = MakeNavMeshPointer(form);
                }
                if (mesh.AnimatingText_GetFullText())
                {
                    mesh.Modelloader_GetReferencedThis()->SetAltered(true);
                    for (unsigned int k = 0;
                         k < reinterpret_cast<P507Array&>(mesh.Modelloader_GetReferencedThis()->m_kEdgeExtraInfo).FUN_0044ddc0(); ++k)
                    {
                        P507Edge* edge =
                            reinterpret_cast<P507Edge*>(mesh.Modelloader_GetReferencedThis()->GetEdge((unsigned short)k));
                        if (edge->owner == id)
                        {
                            mesh.Modelloader_GetReferencedThis()->UpdateTriangleExtraInfo((unsigned short)k);
                            --k;
                        }
                    }
                }
                if (j < info)
                {
                    firstCount->first.BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(j, true);
                    --info;
                }
                else
                {
                    firstCount->second.BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(j - info, true);
                    --secondCount;
                }
                --j;
            }
        }
    }
}

extern const float DAT_01016970;
extern const float DAT_01015f5c;

struct NavMeshTriListAdd
{
    unsigned int Add(const unsigned short& arItem);
};

// For each triangle index in [ausStart, ausEnd], computes its XY bounds, maps them to grid rows/columns and adds the index to every overlapping cell list.
// @fnv 0x006965d0
bool NavMesh::AddTrianglesToGrid(unsigned short ausStart, unsigned short ausEnd)
{
    for (unsigned int i = ausStart; i <= ausEnd; i++)
    {
        NavMeshTriangle* pTri_ = GetTriangle((unsigned short)i);
        NiPoint3 kMinBoundsCur(DAT_01016970, DAT_01016970, 0.0f);
        NiPoint3 kMaxB(DAT_01015f5c, DAT_01015f5c, 0.0f);
        for (int jVal = 0; jVal < 3; jVal++)
        {
            const NiPoint3& _kPt = GetVertex_0068f0a0(pTri_->GetVert_005582d0(jVal));
            if (_kPt.x < kMinBoundsCur.x)
                kMinBoundsCur.x = _kPt.x;
            if (_kPt.x > kMaxB.x)
                kMaxB.x = _kPt.x;
            if (_kPt.y < kMinBoundsCur.y)
                kMinBoundsCur.y = _kPt.y;
            if (_kPt.y > kMaxB.y)
                kMaxB.y = _kPt.y;
        }
        unsigned int uiMinRow = 0;
        unsigned int kUiMinCol = 0;
        unsigned int uiMaxRow = 0;
        unsigned int uiMaxCol3 = 0;
        m_kGrid.GetCellCoords(kMinBoundsCur, uiMinRow, kUiMinCol);
        m_kGrid.GetCellCoords(kMaxB, uiMaxRow, uiMaxCol3);
        for (unsigned int uiRow = uiMinRow; uiRow <= uiMaxRow; uiRow++)
        {
            for (unsigned int uiCol9 = kUiMinCol; uiCol9 <= uiMaxCol3; uiCol9++)
            {
                NavMeshTriListAdd* pList5 = reinterpret_cast<NavMeshTriListAdd*>(m_kGrid.NavMeshGrid_GetTriangleArray(uiCol9, uiRow));
                if (!pList5)
                    continue;
                pList5->Add((unsigned short)i);
            }
        }
    }
    return true;
}

struct TriList2 : public NavMeshTriList
{
    void BSSimpleArray_RemoveFast_1(int idx, int n);
};
bool __cdecl Object_ComputeValue_0069b2a0(const unsigned short& a, const unsigned short& b);
extern const float DAT_01016970;

// For each triangle index from ausStart to ausEnd, computes its XY bounds, finds the grid cells it spans and marks the triangle in each cell's list.
// @fnv 0x006967f0
// src: GUESS 0x006967f0 (confidence: high)
bool NavMesh::AddTrianglesToXYGridCells(unsigned short ausStart, unsigned short ausEnd)
{
    unsigned int i;
    for (i = ausStart; i <= ausEnd; i++)
    {
        NavMeshTriangle* pTri = GetTriangle((unsigned short)i);
        NiPoint3 fStack_14(DAT_01016970, DAT_01016970, 0.0f);
        NiPoint3 f(DAT_01015f5c, DAT_01015f5c, 0.0f);
        for (int j = 0; j < 3; j++)
        {
            const NiPoint3* pV = &GetVertex_0068f0a0(pTri->GetVert_005582d0(j));
            if (pV->x < fStack_14.x)
                fStack_14.x = pV->x;
            if (pV->x > f.x)
                f.x = pV->x;
            if (pV->y < fStack_14.y)
                fStack_14.y = pV->y;
            if (pV->y > f.y)
                f.y = pV->y;
        }
        unsigned int j = 0, cf = 0, b = 0, p = 0;
        m_kGrid.GetCellCoords(fStack_14, j, cf);
        m_kGrid.GetCellCoords(f, b, p);
        for (unsigned int r = j; r <= b; r++)
        {
            for (unsigned int c = cf; c <= p; c++)
            {
                int idx;
                TriList2* pList = (TriList2*)m_kGrid.NavMeshGrid_GetTriangleArray(c, r);
                idx = pList->FindMatchingIndex(*(unsigned short*)&i, 0, Object_ComputeValue_0069b2a0);
                pList->BSSimpleArray_RemoveFast_1(idx, 1);
            }
        }
    }
    return true;
}

namespace fnv_00696a50 {
extern float DAT_01016970;
extern const double DAT_010240c0;

struct FUN_00696a50_HeightSource
{
    void CheckWaterHeight(const NiPoint3* apPos, float* apfHeight);
};

}  // namespace fnv_00696a50

// @fnv 0x00696a50
// src: XBOX_PDB 0x00696a50
unsigned short NavMesh::FindTriangleForLocation_00696a50(const NiPoint3* apPos, int aiArg)
{
    NavMeshTriList* pCell = 0;
    m_kGrid.GetTriListAtPosition(apPos, &pCell);
    unsigned short usBestTmp = 0xffff;
    if (!pCell)
        return 0xffff;
    unsigned int uiEntries = pCell->GetSize();
    float fPointHeight = fnv_00696a50::DAT_01016970;
    float m_fGlyphExtent = DAT_01015f5c;
    if (reinterpret_cast<fnv_00696a50::FUN_00696a50_HeightSource*>(m_pOwningCell))
        reinterpret_cast<fnv_00696a50::FUN_00696a50_HeightSource*>(m_pOwningCell)
            ->CheckWaterHeight(apPos, &m_fGlyphExtent);
    bool bBelowGround = apPos->z < (float)(m_fGlyphExtent + 50.0);
    for (unsigned int i = 0; i < uiEntries; i++)
    {
        unsigned short usTri = pCell->BSSimpleArray_unsigned_short_1024_GetAt(i);
        if (Triangles.GetAt(usTri).GetFlag(0x20))
            continue;
        float fDistance;
        if (TestPointOnTriangle(usTri, apPos, &fDistance, aiArg))
        {
            if (!bBelowGround && fDistance < -180.0)
                continue;
            if (fDistance > fnv_00696a50::DAT_010240c0)
                continue;
            fDistance = std::abs(fDistance);
            if (fDistance < fPointHeight)
            {
                if (fDistance < 40.0)
                    return usTri;
                usBestTmp = usTri;
                fPointHeight = fDistance;
            }
        }
    }
    return usBestTmp;
}

namespace fnv_00696cf0 {
extern float DAT_01016970;
struct TriArr696
{
    void* m_00;
    void* m_04;
    unsigned int m_08;
    unsigned int m_0c;
    NavMeshTriangle* GetElementAddress16(int idx);
    unsigned int FUN_0044ddc0();
};

}  // namespace fnv_00696cf0

// @fnv 0x00696cf0
// src: XBOX_PDB 0x00696cf0
bool NavMesh::FindClosestTriangleForLocation(const NiPoint3& point, unsigned short* outTri, bool* outFlag)
{
    unsigned short d2;
    unsigned short i;
    {
        float bestSq;
        TriangleList* q;
        bestSq = fnv_00696cf0::DAT_01016970;
        d2 = 0xffff;
        i = 0xffff;
        q = 0;
        m_kGrid.GetTriListAtPosition(point, reinterpret_cast<NavMeshTriList*&>(q));
        if (q)
        {
            unsigned int triSq = q->FUN_0044ddc0();
            float bestD = fnv_00696cf0::DAT_01016970;
            float f;
            unsigned int e;
            for (e = 0; e < (int)triSq; e++)
            {
                unsigned short pObj = q->BSSimpleArray_unsigned_short_1024_GetAt(e);
                if (reinterpret_cast<fnv_00696cf0::TriArr696&>(Triangles).GetElementAddress16(pObj)->GetFlag(0x20))
                    continue;
                if (FUN_00697730(pObj, point, f, 180.0f, 64.0f))
                {
                    f = std::abs(f);
                    if (f < bestD)
                    {
                        if (f < 40.0)
                        {
                            *outTri = pObj;
                            *outFlag = true;
                            return true;
                        }
                        i = pObj;
                        bestD = f;
                    }
                }
                else
                {
                    NiPoint3 bestD2 = FUN_00558220(pObj) - point;
                    float list = ((NiPoint3*)&bestD2)->FUN_004a7290();
                    if (list < bestSq)
                    {
                        d2 = pObj;
                        bestSq = list;
                    }
                }
            }
            if (i != 0xffff)
            {
                *outTri = i;
                *outFlag = true;
                return true;
            }
        }
        else
        {
            unsigned int nn = reinterpret_cast<fnv_00696cf0::TriArr696&>(Triangles).FUN_0044ddc0();
            unsigned int t;
            float n = fnv_00696cf0::DAT_01016970;
            float s;
            for (t = 0; t < (int)nn; t++)
            {
                if (FUN_00697730((unsigned short)t, point, s, 180.0f, 64.0f))
                {
                    s = std::abs(s);
                    if (s < n)
                    {
                        if (s < 40.0)
                        {
                            *outTri = (unsigned short)t;
                            *outFlag = true;
                            return true;
                        }
                        i = (unsigned short)t;
                        n = s;
                    }
                }
                else
                {
                    NiPoint3 count2 = FUN_00558220((unsigned short)t) - point;
                    float sq2;
                    sq2 = ((NiPoint3*)&count2)->FUN_004a7290();
                    if (sq2 < bestSq)
                    {
                        d2 = (unsigned short)t;
                        bestSq = sq2;
                    }
                }
            }
        }
        if (i != 0xffff)
        {
            *outTri = i;
            *outFlag = true;
            return true;
        }
    }
    if (d2 == 0xffff)
    {
        *outTri = 0xffff;
        *outFlag = false;
        return false;
    }
    *outTri = d2;
    *outFlag = false;
    return true;
}

float __cdecl NavMeshMath_DistanceFromLine(const NiPoint3& point, const NiPoint3& first, const NiPoint3& second);

// @fnv 0x00697d40
NiPoint3 NavMesh::AdjustPointToNavMesh(const NiPoint3& point, float radius)
{
    NiPoint3 adjusted = point;
    unsigned short triangle = FindTriangleForLocation(point, 0);
    if (triangle != 0xffff)
    {
        unsigned short neighbours[3];
        NavMeshTriangle* triangleData;
        {
            unsigned short count = 0;
            triangleData = GetTriangle(triangle);
            for (int edge = 0; edge < 3; ++edge)
            {
                unsigned short neighbour = 0xffff;
                if (!triangleData->IsEdgeFlagSet(edge))
                    neighbour = triangleData->GetEdgeExtraInfo_0068f2c0(edge);
                if (neighbour != 0xffff)
                {
                    neighbours[count] = neighbour;
                    ++count;
                }
                else
                {
                    NavMeshEdgeVertexPair vertices = NavMesh_GetEdgeVertices_0(triangle, edge);
                    float distance = NavMeshMath_DistanceFromLine(point, *vertices.p1, *vertices.p2);
                    if (distance < radius)
                    {
                        NiPoint3 normal = FUN_006971e0(triangle);
                        NiPoint3 direction = normal.Cross(*vertices.p1 - *vertices.p2);
                        direction.Unitize_004a0c10();
                        adjusted
                            .ComputeValue_0063c8a0(direction.ApplyScaled(radius - distance));
                    }
                }
            }
            for (unsigned int index = 0; index < count; ++index)
            {
                NavMeshTriangle* triangleData = GetTriangle(neighbours[index]);
                for (int edge = 0; edge < 3; ++edge)
                {
                    if (!triangleData->IsEdgeFlagSet(edge) && triangleData->GetEdgeExtraInfo_0068f2c0(edge) == 0xffff)
                    {
                        NavMeshEdgeVertexPair vertices = NavMesh_GetEdgeVertices_0(neighbours[index], edge);
                        float distance = NavMeshMath_DistanceFromLine(point, *vertices.p1, *vertices.p2);
                        if (distance < radius)
                        {
                            NiPoint3 normal = FUN_006971e0(neighbours[index]);
                            NiPoint3 direction = normal.Cross(*vertices.p1 - *vertices.p2);
                            direction.Unitize_004a0c10();
                            adjusted
                                .ComputeValue_0063c8a0(direction.ApplyScaled(radius - distance));
                        }
                    }
                }
            }
        }
    }
    return adjusted;
}

struct NavEdgeHit
{
    int iType;
    int m_iEdgeNumber;
    NiPoint3 kPoint;
    NavEdgeHit();
};

bool __cdecl NavMeshMath_Find2DIntersectionStable(const NiPoint3& start, const NiPoint3& end, const NiPoint3& from, const NiPoint3& to,
                          NiPoint3* out);

// Tests the triangle's edges (skipping aiSkipEdge) for an intersection with the segment arFrom-arTo and returns the hit edge index and point, or a type-0 miss.
// @fnv 0x00698160
NavEdgeHit NavMesh::FindEdgeIntersection(unsigned short ausTriangle, int aiSkipEdge, const NiPoint3& arFrom,
                                                const NiPoint3& arTo)
{
    NiPoint3 verts[3];
    NiPoint3 flat = arTo;
    flat.z = 0.0f;
    for (int i = 0; i < 3; i++)
    {
        verts[i] = GetVertex_0068f0a0(GetTriangle(ausTriangle)->GetVert_005582d0(i));
    }
    for (int j = 0; j < 3; j++)
    {
        if (j == aiSkipEdge)
            continue;
        int next = j + 1;
        if (next == 3)
            next = 0;
        if (verts[j].HasEqualComponents(verts[next]))
            continue;
        NavEdgeHit hit;
        if (NavMeshMath_Find2DIntersectionStable(verts[j], verts[next], arFrom, arTo, &hit.kPoint))
        {
            hit.iType = 3;
            hit.m_iEdgeNumber = j;
            return hit;
        }
    }
    NavEdgeHit none;
    none.iType = 0;
    none.m_iEdgeNumber = -1;
    return none;
}

struct SavedMesh
{
    void* object;
    SavedMesh();
    ~SavedMesh();
    SavedMesh& operator=(const SavedMesh&);
};
struct UndoEntry
{
    int unk00, unk04;
    int type;
    SavedMesh mesh;
};
struct UndoPtr
{
    UndoEntry* Get();
};
struct UndoArray
{
    UndoPtr& At(unsigned int);
    unsigned int Size();
};
struct UndoContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    UndoContext();
    ~UndoContext();
    void Restore(NavMesh*, UndoEntry*, void*);
    void Remove(NavMesh*, UndoEntry*);
    void Add(NavMesh*, const SavedMesh&, void*);
};

// @fnv 0x00699000
bool NavMesh::UndoToPosition(unsigned int position, void* output)
{
    UndoEntry* entry7 = reinterpret_cast<UndoArray&>(m_kObstacleUndoData).At(position).Get();
    if (position == reinterpret_cast<UndoArray&>(m_kObstacleUndoData).Size() - 1)
    {
        UndoContext context;
        if (entry7->type == 1)
            context.Restore(this, entry7, output);
        context.Remove(this, entry7);
        ForwardToStub(position);
    }
    else if (!ComputeTriangleHash(reinterpret_cast<NavMeshInfo*>(entry7)))
    {
        UndoContext context;
        if (entry7->type == 1)
            context.Restore(this, entry7, output);
    }
    else
    {
        SavedMesh saved2[100];
        unsigned int count3 = 0;
        UndoContext context;
        unsigned int index2;
        for (index2 = reinterpret_cast<UndoArray&>(m_kObstacleUndoData).Size() - 1; index2 != position - 1; --index2)
        {
            if (reinterpret_cast<UndoArray&>(m_kObstacleUndoData).At(index2).Get()->type == 1)
            {
                context.Restore(this, reinterpret_cast<UndoArray&>(m_kObstacleUndoData).At(index2).Get(), output);
                if (index2 > position)
                {
                    saved2[count3] = reinterpret_cast<UndoArray&>(m_kObstacleUndoData).At(index2).Get()->mesh;
                    ++count3;
                }
            }
            context.Remove(this, reinterpret_cast<UndoArray&>(m_kObstacleUndoData).At(index2).Get());
            ForwardToStub(index2);
        }
        for (; index2 != -1; --index2)
        {
            if (reinterpret_cast<UndoArray&>(m_kObstacleUndoData).At(index2).Get()->type == 3)
            {
                context.Remove(this, reinterpret_cast<UndoArray&>(m_kObstacleUndoData).At(index2).Get());
                ForwardToStub(index2);
            }
            else
                break;
        }
        for (unsigned int next3 = 0; next3 < count3; ++next3)
            context.Add(this, saved2[next3], output);
    }
    return true;
}

class ObstacleRegistry
{
  public:
    unsigned int BSSimpleArray_NiPointer_NiAVObject_1024_Add(const NiPointer<ObstacleData>& m_spRegisteredObstacle);
};

// @fnv 0x00699510
// src: COMMUNITY 0x00699510
unsigned int NavMesh::AddObstacleUndoData(ObstacleData* pkObstacle)
{
    unsigned int uiResult;
    {
        NiPointer<ObstacleData> m_spRegisteredObstacle(pkObstacle);
        uiResult = reinterpret_cast<ObstacleRegistry&>(m_kObstacleUndoData).BSSimpleArray_NiPointer_NiAVObject_1024_Add(m_spRegisteredObstacle);
    }
    return uiResult;
}

struct LinkInfo
{
    int type;
    NavMeshInfo* mesh;
    unsigned short triangle;
};
struct LinkedTriangle : NavMeshTriangle
{
    bool NavMeshTriangle_HasEdgeExtraInfo();
};

// @fnv 0x0069aa20
bool NavMesh::LinkMatchingEdges()
{
    for (unsigned int triangleIndex = 0; triangleIndex < NavMesh_GetTriangleCount(); ++triangleIndex)
    {
        LinkedTriangle* triangle = reinterpret_cast<LinkedTriangle*>(FUN_005582f0((unsigned short)triangleIndex));
        if (!triangle || !triangle->NavMeshTriangle_HasEdgeExtraInfo())
            continue;
        for (int edge = 0; edge < 3; ++edge)
        {
            if (!triangle->IsEdgeFlagSet(edge))
                continue;
            int edgeCount;
            int matchingEdge;
            {
                LinkInfo* link = reinterpret_cast<LinkInfo*>(GetEdge(triangle->GetEdgeExtraInfo_0068f2c0(edge)));
                {
                    NavMeshPtr otherMesh;
                    if (!link->mesh->ResolveNavMesh(otherMesh))
                        continue;
                    LinkedTriangle* otherTriangle =
                        reinterpret_cast<LinkedTriangle*>(otherMesh.Modelloader_GetReferencedThis()->FUN_005582f0(link->triangle));
                    if (!otherTriangle)
                        continue;
                    edgeCount = 0;
                    matchingEdge = -1;
                    for (int otherEdge = 0; otherEdge < 3; ++otherEdge)
                    {
                        if (otherTriangle->IsEdgeFlagSet(otherEdge))
                        {
                            ++edgeCount;
                            matchingEdge = otherEdge;
                        }
                    }
                    if (edgeCount != 0)
                    {
                        NiPoint3 edgeStart;
                        {
                            NiPoint3 edgeEnd;
                            GetEdgeVertices_0068f0c0((unsigned short)triangleIndex, edge, edgeStart, edgeEnd);
                            for (int candidateEdge = 0; candidateEdge < 3; ++candidateEdge)
                            {
                                NiPoint3 start, end;
                                otherMesh.Modelloader_GetReferencedThis()->GetEdgeVertices_0068f0c0(link->triangle, candidateEdge, start, end);
                                if ((edgeStart - end).FUN_004a7290() < 400.0 &&
                                    (edgeEnd - start).FUN_004a7290() < 400.0)
                                {
                                    matchingEdge = candidateEdge;
                                    edgeCount = 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (edgeCount == 1)
                    {
                        LinkInfo* reverse = reinterpret_cast<LinkInfo*>(
                            otherMesh.Modelloader_GetReferencedThis()->GetOrCreateEdgeInfo(link->triangle, matchingEdge));
                        reverse->mesh = const_cast<NavMeshInfo*>(GetNavMeshInfo_0068efb0());
                        reverse->triangle = (unsigned short)triangleIndex;
                        reverse->type = 3;
                    }
                }
            }
        }
    }
    return true;
}

float floorf(float afValue);


// If arPos lies inside the grid bounds, computes the cell column and row from the cell size and stores the cell's tri list in *appList; otherwise stores null.
// @fnv 0x0069d370
void NavMeshGrid::GetTriListAtPosition(const NiPoint3& arPos, NavMeshTriList** appList)
{
    if (arPos.x < IndexedPointRecord.x || arPos.x > IndexedPointData.x || arPos.y < IndexedPointRecord.y ||
        arPos.y > IndexedPointData.y)
    {
        *appList = 0;
    }
    else
    {
        float fDX2 = arPos.x - IndexedPointRecord.x;
        float fDYVal = arPos.y - IndexedPointRecord.y;
        float fCol = fDX2 / m_fFirstGridValue;
        float fRow = fDYVal / NavMeshPointEntry;
        unsigned int uiCol = (unsigned int)floorf(fCol);
        unsigned int uiRowA = (unsigned int)floorf(fRow);
        if (uiCol >= m_uiGridIndex)
        {
            uiCol = m_uiGridIndex - 1;
        }
        if (uiRowA >= m_uiGridIndex)
        {
            uiRowA = m_uiGridIndex - 1;
        }
        *appList = NavMeshGrid_GetTriangleArray(uiCol, uiRowA);
    }
}

// Projects a point onto a triangle in the XY plane via barycentric coordinates; if it lies inside,
// interpolates the triangle height there and accepts it when the height difference to the point
// is within [-fBelow, fAbove], returning the difference.
// @fnv 0x006b9cf0
// src: XBOX_PDB 0x006b9cf0
bool NavMeshMath_IsPointInsideTriangle(const NiPoint3& kP0, const NiPoint3& kP1, const NiPoint3& kP2, const NiPoint3& akPoint,
                  float& fHeightDiff, float fAbove, float fBelow)
{
    float fInvDenom;
    float fBary0;
    float fY2;
    float fDeltaY0;
    {
        float fY1;
        float fX1;
        float fX2Off;
        float fDeltaX0;
        float m_fGlyphExtent;
        float fDenom;
        float fW;
        float fProjectionAlongAim;
        float fV;

        fDenom = (kP1.x - kP0.x) * (kP2.y - kP0.y) - (kP2.x - kP0.x) * (kP1.y - kP0.y);
        if (fDenom == 0.0)
            return false;

        fX1 = kP1.x - akPoint.x;
        fX2Off = kP2.x - akPoint.x;
        fY1 = kP1.y - akPoint.y;
        fY2 = kP2.y - akPoint.y;
        fInvDenom = 1.0f / fDenom;

        fBary0 = (fX1 * fY2 - fX2Off * fY1) * fInvDenom;
        if (fBary0 < 0.0)
            return false;

        fDeltaX0 = kP0.x - akPoint.x;
        fDeltaY0 = kP0.y - akPoint.y;
        fV = (fX2Off * fDeltaY0 - fDeltaX0 * fY2) * fInvDenom;
        if (fV < 0.0)
            return false;

        fW = (fDeltaX0 * fY1 - fX1 * fDeltaY0) * fInvDenom;
        if (fW < 0.0)
            return false;

        m_fGlyphExtent = fBary0 * kP0.z + fV * kP1.z + fW * kP2.z;
        fProjectionAlongAim = m_fGlyphExtent - akPoint.z;
        if (fProjectionAlongAim > fAbove)
            return false;
        else if (fProjectionAlongAim < -fBelow)
            return false;

        fHeightDiff = fProjectionAlongAim;
        return true;
    }
}

struct NavObstacleObject
{
    void NiRefObject_DecRefCount();
};
struct NavObstaclePtr
{
    NavObstacleObject* object;
    NavObstaclePtr(int);
    NavObstaclePtr(const NavObstaclePtr&);
    ~NavObstaclePtr();
    void FUN_006e5cc0(const NavObstaclePtr&);
    NavObstacleObject* Modelloader_GetReferencedThis();
};
struct NavMap
{
    unsigned int unk00, unk04, unk08, unk0C;
    bool ProcessEntries_0069afb0(unsigned short, NavObstaclePtr&);
    void NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_NavMeshObstacleData_unsigned_short_NiPointer_NavMeshObstacleData_SetAt(unsigned short, NavObstaclePtr);
    void FUN_0049c250(unsigned short);
};
struct NavIndexArray
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int FUN_0044ddc0();
    unsigned short& GetBufferEntry(unsigned int);
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
};
struct NavResetVertices
{
    unsigned int unk00, unk04, unk08, unk0C;
    void FUN_00694890(unsigned int, bool);
};
struct NavResetTriangles
{
    unsigned int unk00, unk04, unk08, unk0C;
    void FUN_006949d0(unsigned int, bool);
};
struct NavTolerance
{
    float x, y, z;
    NavTolerance(float, float, float);
};
struct NavChange;

struct NavChange
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    virtual ~NavChange();
    unsigned int unk04, state;
    NavObstaclePtr obstacle;
    unsigned int oldVertices, newVertices, oldTriangles, newTriangles;
    NavIndexArray affected;
    float centerX, centerY, centerZ;
    unsigned int unk3C;
    NavMap obstacleMap;
    unsigned int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    NavChange();
};
struct NavItem
{
    unsigned int unk00;
    unsigned short unk04;
    bool enabled;
    char unk07;
    unsigned int unk08, unk0C, unk10, unk14, unk18;
    NavObstaclePtr obstacle;
};
struct NavItemArray
{
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    void FUN_008454f0(unsigned int);
    unsigned int FUN_0044ddc0();
    NavItem*& FUN_00877a30(unsigned int);
};
// Entry 0x00990a60 has no declaration in the shared NavMesh header yet.
unsigned int __fastcall NavMeshGetArrayFlags(NavMesh*);

struct NavChangeBuilder
{
    NavMesh* mesh;
    NavObstaclePtr obstacle;
    NavChange* change;
    unsigned int unk0C, unk10, unk14, unk18;
    NavItemArray items, previousItems;
    unsigned int count;
    unsigned int NavMeshObstacleCutter_GetTrianglesMaxObstacleCount();
    void CollectLinkedTriangles(float*);
    void BuildNavMeshEdges();
    void BuildQuad();
    void SplitCrossingEdges();
    bool NavMeshObstacleCutter_IsVertInObstacleArea(NavItem*);
    void NavMeshObstacleCutter_RemoveInvalidEdges();
    void FUN_006bde50();
    bool BuildTrianglesFromEdgePairs();
    void JoinAdjacentEdges();
    void ApplyEdgeSplits();
    void UpdateEdgeRecords(int);
    void NavMeshObstacleCutter_SetObstacleCount();
    void NavMeshObstacleCutter_AddNewTrianglesToNavMeshGrid();
    void NavMeshObstacleCutter_UpdateCoverArray();
    void NavMeshObstacleCutter_AddNewPOVs();
    bool NavMeshObstacleCutter_SplitNavMeshFromObstacle(NavMesh*, const NavObstaclePtr&, int);
};
// @fnv 0x006bbd30
// src: COMMUNITY 0x006bbd30
bool NavChangeBuilder::NavMeshObstacleCutter_SplitNavMeshFromObstacle(NavMesh* apMesh, const NavObstaclePtr& apObstacle, int flags)
{
    mesh = apMesh;
    obstacle.FUN_006e5cc0(apObstacle);
    items.FUN_008454f0(0);
    for (unsigned int i = 0; i < previousItems.FUN_0044ddc0(); ++i)
    {
        if (previousItems.FUN_00877a30(i)->obstacle.Modelloader_GetReferencedThis())
            previousItems.FUN_00877a30(i)->obstacle.Modelloader_GetReferencedThis()->NiRefObject_DecRefCount();
    }
    previousItems.FUN_008454f0(0);
    change = new NavChange;
    mesh->GetOverlappedTriangleList(reinterpret_cast<const NiPointer<ObstacleData>&>(apObstacle),
                      reinterpret_cast<const NiPoint3&>(NavTolerance(5.0f, 5.0f, 5.0f)),
                      reinterpret_cast<BSSimpleArray<unsigned short>*>(&change->affected));
    if (change->affected.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        delete change;
        return false;
    }
    change->state = 1;
    change->obstacle.FUN_006e5cc0(apObstacle);
    change->oldVertices = NavMeshGetArrayFlags(mesh);
    change->oldTriangles = mesh->NavMesh_GetTriangleCount();
    count = NavMeshObstacleCutter_GetTrianglesMaxObstacleCount();
    CollectLinkedTriangles(&change->centerX);
    for (unsigned int j = 0; j < change->affected.FUN_0044ddc0(); ++j)
        mesh->FUN_005582f0(change->affected.GetBufferEntry(j))->SetFlag_00691570(0x20);
    BuildNavMeshEdges();
    for (unsigned int k = 0; k < change->affected.FUN_0044ddc0(); ++k)
    {
        unsigned short index = change->affected.GetBufferEntry(k);
        NavObstaclePtr entry(0);
        if (reinterpret_cast<NavMap*>(mesh->pTriangleToObstacleMap)->ProcessEntries_0069afb0(index, entry))
        {
            change->obstacleMap.NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_NavMeshObstacleData_unsigned_short_NiPointer_NavMeshObstacleData_SetAt(index, entry);
            reinterpret_cast<NavMap*>(mesh->pTriangleToObstacleMap)->FUN_0049c250(index);
        }
    }
    BuildQuad();
    SplitCrossingEdges();
    for (unsigned int n = 0; n < items.FUN_0044ddc0(); ++n)
    {
        if (NavMeshObstacleCutter_IsVertInObstacleArea(items.FUN_00877a30(n)))
            items.FUN_00877a30(n)->enabled = true;
    }
    NavMeshObstacleCutter_RemoveInvalidEdges();
    FUN_006bde50();
    if (!BuildTrianglesFromEdgePairs())
    {
        reinterpret_cast<NavResetVertices&>(mesh->Vertices).FUN_00694890(change->oldVertices, true);
        reinterpret_cast<NavResetTriangles&>(mesh->Triangles).FUN_006949d0(change->oldTriangles, true);
        delete change;
        return false;
    }
    JoinAdjacentEdges();
    BuildTrianglesFromEdgePairs();
    ApplyEdgeSplits();
    UpdateEdgeRecords(flags);
    change->newVertices = NavMeshGetArrayFlags(mesh) - change->oldVertices;
    change->newTriangles = mesh->NavMesh_GetTriangleCount() - change->oldTriangles;
    NavMeshObstacleCutter_SetObstacleCount();
    for (unsigned int t = change->oldTriangles; t < change->oldTriangles + change->newTriangles; ++t)
        reinterpret_cast<NavMap*>(mesh->pTriangleToObstacleMap)->NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_NavMeshObstacleData_unsigned_short_NiPointer_NavMeshObstacleData_SetAt((unsigned short)t, obstacle);
    NavMeshObstacleCutter_AddNewTrianglesToNavMeshGrid();
    NavMeshObstacleCutter_UpdateCoverArray();
    NavMeshObstacleCutter_AddNewPOVs();
    mesh->AddObstacleUndoData(reinterpret_cast<ObstacleData*>(change));
    return true;
}

float __cdecl RandomFloat(float fMin, float fScaledValue);
float __cdecl sqrt_004019b0(float fValue);
extern const float runtimeFloatSettingDefault1020;

// @fnv 0x00697c10
// src: COMMUNITY 0x00697c10
bool NavMesh::FindRandomPointWithinRadius(const NiPoint3& aPosition, float aRadius, NiPoint3* pkOut)
{
    bool bFound = false;
    NiPoint3 kIntersectionOffset = NiPoint3::ZERO;
    for (unsigned int i = 0; i < 8 && !bFound; i++)
    {
        float fX = RandomFloat(-aRadius, aRadius);
        float fY = sqrt_004019b0(aRadius * aRadius - fX * fX);
        fY = RandomFloat(-fY, fY);
        kIntersectionOffset.x = fX;
        kIntersectionOffset.y = fY;
        bFound = IsLocationOnNavMesh(kIntersectionOffset.FUN_00439e90(aPosition), 0);
    }
    if (!bFound)
    {
        pkOut = 0;
        return false;
    }
    kIntersectionOffset.ComputeValue_0063c8a0(aPosition);
    *pkOut = AdjustPointToNavMesh(kIntersectionOffset, runtimeFloatSettingDefault1020);
    return true;
}

extern const float DAT_01016970;
extern const float DAT_01015f5c;
float __cdecl floorf(float);
bool __cdecl NavMeshMath_Find2DIntersection(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&);

struct GridCell
{
    unsigned int x, y;
};

// Adds each triangle to grid cells containing its vertices, containing cell corners, or intersecting its edges.
// @fnv 0x006959b0
// src: COMMUNITY 0x006959b0
void NavMesh::CreateGrid()
{
    int count2 = NavMesh_GetTriangleCount();
    m_kGrid.Clear_0069d2d0();
    if (count2 == 0)
        return;
    NiPoint3 boundsMin5, boundsMaxX;
    ComputeBounds(boundsMin5, boundsMaxX);
    m_kGrid.InitFromPoints(boundsMin5, boundsMaxX, count2);
    unsigned int dimensionB_ = m_kGrid.Modelloader_GetReferencedThis();
    float width8 = m_kGrid.m_fFirstGridValue;
    float heightSquared9 = m_kGrid.NavMeshPointEntry;
    NiPoint3 corner1, right3, upper3, upperRight4, point12;
    NiPoint3 verticesCheck6[3];
    int triangle;
    NavMeshTriangle* triA4;
    float minX7, minYA, maxx6, maxy3;
    GridCell cellsVal[3];
    unsigned int maxX2, minCellX4, maxCellYVal, minY2;
    bool addedX;
    for (triangle = 0; triangle < count2; triangle++)
    {
        triA4 = GetTriangle((unsigned short)triangle);
        minX7 = minYA = DAT_01016970;
        maxx6 = maxy3 = DAT_01015f5c;
        for (int vertex = 0; vertex < 3; vertex++)
        {
            point12 = GetVertex_0068f0a0(triA4->GetVert_005582d0(vertex));
            verticesCheck6[vertex] = point12;
            if (point12.x < minX7)
                minX7 = point12.x;
            if (point12.x > maxx6)
                maxx6 = point12.x;
            if (point12.y < minYA)
                minYA = point12.y;
            if (point12.y > maxy3)
                maxy3 = point12.y;
            cellsVal[vertex].x = (unsigned int)floorf((point12.x - boundsMin5.x) / width8);
            cellsVal[vertex].y = (unsigned int)floorf((point12.y - boundsMin5.y) / heightSquared9);
            if (cellsVal[vertex].x >= dimensionB_)
                cellsVal[vertex].x = dimensionB_ - 1;
            if (cellsVal[vertex].y >= dimensionB_)
                cellsVal[vertex].y = dimensionB_ - 1;
        }
        minCellX4 = maxX2 = cellsVal[0].x;
        minY2 = maxCellYVal = cellsVal[0].y;
        for (int vertex2 = 1; vertex2 < 3; vertex2++)
        {
            if (cellsVal[vertex2].x < minCellX4)
                minCellX4 = cellsVal[vertex2].x;
            if (cellsVal[vertex2].x > maxX2)
                maxX2 = cellsVal[vertex2].x;
            if (cellsVal[vertex2].y < minY2)
                minY2 = cellsVal[vertex2].y;
            if (cellsVal[vertex2].y > maxCellYVal)
                maxCellYVal = cellsVal[vertex2].y;
        }
        addedX = false;
        if (minCellX4 == maxX2 && minY2 == maxCellYVal)
        {
            m_kGrid.SetTriangleData((unsigned short)triangle, minCellX4, minY2);
            addedX = true;
        }
        else
        {
            for (unsigned int x = minCellX4; x <= maxX2; x++)
            {
                for (unsigned int y = minY2; y <= maxCellYVal; y++)
                {
                    if ((cellsVal[0].x == x && cellsVal[0].y == y) || (cellsVal[1].x == x && cellsVal[1].y == y) ||
                        (cellsVal[2].x == x && cellsVal[2].y == y))
                    {
                        m_kGrid.SetTriangleData((unsigned short)triangle, x, y);
                        addedX = true;
                        continue;
                    }
                    corner1 = m_kGrid.NavMeshGrid_GetGridPosition(x, y);
                    right3 = m_kGrid.NavMeshGrid_GetGridPosition(x + 1, y);
                    upper3 = m_kGrid.NavMeshGrid_GetGridPosition(x, y + 1);
                    upperRight4 = m_kGrid.NavMeshGrid_GetGridPosition(x + 1, y + 1);
                    if ((verticesCheck6[0].x <= upperRight4.x && verticesCheck6[0].y <= upperRight4.y &&
                         verticesCheck6[0].x >= corner1.x && verticesCheck6[0].y >= corner1.y) ||
                        (verticesCheck6[1].x <= upperRight4.x && verticesCheck6[1].y <= upperRight4.y &&
                         verticesCheck6[1].x >= corner1.x && verticesCheck6[2].y >= corner1.y) ||
                        (verticesCheck6[2].x <= upperRight4.x && verticesCheck6[2].y <= upperRight4.y &&
                         verticesCheck6[2].x >= corner1.x && verticesCheck6[2].y >= corner1.y))
                    {
                        m_kGrid.SetTriangleData((unsigned short)triangle, x, y);
                        addedX = true;
                        continue;
                    }
                    float zl;
                    if (FUN_00697730((unsigned short)triangle, corner1, zl, DAT_01016970, 180.0f) ||
                        FUN_00697730((unsigned short)triangle, right3, zl, DAT_01016970, 180.0f) ||
                        FUN_00697730((unsigned short)triangle, upper3, zl, DAT_01016970, 180.0f) ||
                        FUN_00697730((unsigned short)triangle, upperRight4, zl, DAT_01016970, 180.0f))
                    {
                        m_kGrid.SetTriangleData((unsigned short)triangle, x, y);
                        addedX = true;
                        continue;
                    }
                    NiPoint3 cellStart3, cellEnd5, triStart6, triEndX;
                    bool intersects3 = false;
                    for (int edge = 0; edge < 4 && !intersects3; edge++)
                    {
                        switch (edge)
                        {
                        case 0:
                            cellStart3 = corner1;
                            cellEnd5 = right3;
                            break;
                        case 1:
                            cellStart3 = right3;
                            cellEnd5 = upperRight4;
                            break;
                        case 2:
                            cellStart3 = upperRight4;
                            cellEnd5 = upper3;
                            break;
                        case 3:
                            cellStart3 = upper3;
                            cellEnd5 = corner1;
                            break;
                        }
                        for (int triEdge = 0; triEdge < 3; triEdge++)
                        {
                            switch (triEdge)
                            {
                            case 0:
                                triStart6 = verticesCheck6[0];
                                triEndX = verticesCheck6[1];
                                break;
                            case 1:
                                triStart6 = verticesCheck6[1];
                                triEndX = verticesCheck6[2];
                                break;
                            case 2:
                                triStart6 = verticesCheck6[2];
                                triEndX = verticesCheck6[0];
                                break;
                            }
                            if (NavMeshMath_Find2DIntersection(cellStart3, cellEnd5, triStart6, triEndX))
                            {
                                intersects3 = true;
                                break;
                            }
                        }
                    }
                    if (intersects3)
                    {
                        m_kGrid.SetTriangleData((unsigned short)triangle, x, y);
                        addedX = true;
                    }
                }
            }
        }
    }
}
