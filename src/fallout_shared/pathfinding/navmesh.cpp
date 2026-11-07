#include "../../../include/PathingAvoidNode.h"
#include "../../../include/NavMeshInfo.h"
#include "../../../include/NavMeshTriangle.h"
#include "../../../include/NavMeshStaticAvoidNode.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/NavMeshClosedDoorInfo.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NavMeshEdgeData.h"
#include "../../../include/ActorMover.h"
#include "../../../include/BGSCameraPath.h"
#include "../../../include/MiddleHighProcess.h"
#include "../../../include/NavMeshGrid.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiTMap.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/TES.h"
#include "../../../include/TESEffectShader.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESRecipe.h"
#include "../../../include/TESWorldSpace.h"
#include "../../../include/ExtraNavMeshPortal.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/StrMem.h"
#include "../../../include/TwoIntRecord.h"
// Preserve point object representations without calling NiPoint3::operator=.
template <unsigned int Size> struct ObjectBytes
{
    unsigned char data[Size];
};

// fallout_shared/pathfinding/navmesh.cpp: NavMesh, ActorMover, BGSCameraPath, TESEffectShader and more (97 functions)


class TESObjectCELL;

class CoordinateTriple
{
  public:
    NiPoint3 Point;
    TESForm* m_pPathingCell;
};



class EdgeExtraInfo
{
  public:
    int type;
    int portal;
    int reserved;
    bool IsEdgeFlagSet();
    unsigned short GetEdgeExtraInfo_0068f2c0();
};


// @fnv 0x0059bb30
unsigned int ActorMover::GetCurrentMoveModeType()
{
    return preferredMoveMode;
}

// @fnv 0x005f36f0
BGSCameraPath* BGSCameraPath::GetPrevPath()
{
    return m_pSecondCameraPath;
}

// @fnv 0x005a29b0
BGSDebris* TESEffectShader::GetAddonModels()
{
    return Data.pAddonModels;
}

// @fnv 0x008d81e0
InventoryStackRecord* MiddleHighProcess::GetActiveWeapon() const
{
    return pWeapon;
}

// @fnv 0x0042fb00
NavMeshStaticAvoidNode* NavMesh::GetStaticAvoidNodeData()
{
    NiPointer_NavMesh_NiPointer_NavMesh_0042fd70(0);
    return (NavMeshStaticAvoidNode*)this;
}

// @fnv 0x00691660
bool NavMesh::GetStaticAvoidNodesForTriangle(unsigned short triangle,
                                             BSSimpleArray<NavMeshStaticAvoidNode*, 1024>& arOutput)
{
    unsigned int i = 0;
    for (; i < m_kStaticAvoidNodes.GetSize(); ++i)
    {
        if (m_kStaticAvoidNodes.GetAt((int)i).GetShortValueAtOffset24() == triangle)
        {
            NavMeshStaticAvoidNode* node = &m_kStaticAvoidNodes.GetAt((int)i);
            arOutput.Add(node);
        }
    }
    return !arOutput.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
}

// Initializes a PathingLocation from a location, NavMeshInfo and triangle index, storing the navmesh's cell or location key and marking all meshes reachable.
// @fnv 0x006dd010
PathingLocation::PathingLocation(const CoordinateTriple& location, NavMeshInfo* navMesh, unsigned short triangle)
{
    reinterpret_cast<ObjectBytes<sizeof(NiPoint3)>&>(Location) =
        reinterpret_cast<const ObjectBytes<sizeof(NiPoint3)>&>(location.Point);
    uiFlags = 0;
    m_pLocationNavMesh = navMesh;
    pNavMeshInfoArray = 0;
    m_pContainingWorldspace = navMesh->GetParentWorldSpace();
    if (m_pContainingWorldspace)
    {
        pCell = 0;
        m_uiPathingFlags = navMesh->m_uiPathingFlags;
    }
    else
    {
        pCell = navMesh->GetInteriorCell();
        m_uiPathingFlags = 0xdeaddead;
    }
    SetAllMeshesReachable(true);
    m_usTriangleID = triangle;
}

extern int DAT_01014618;
// @fnv 0x00416ad0
ExtraNavMeshPortal::ExtraNavMeshPortal(TwoIntRecord v) : BSExtraData(0x5a), handle(v)
{}

// If the stored object pointer is non-null, calls FUN_00401970 on the NiAVObject at offset 0x1c within it.
// @fnv 0x0042fda0
// src: GUESS 0x0042fda0 (confidence: medium)
void __fastcall Object_ReleaseReferencedObject(int* pObjectPtr)
{
    if (*pObjectPtr != 0)
    {
        ((NiAVObject*)(*pObjectPtr + 0x1c))->NiRefObject_DecRefCount();
    }
}



#include "../../../include/NiMemObject.h"


// Calls the NavMesh destructor and, when bit 0 of flags is set, frees this with NiMemObject::operator delete; returns this.
// @fnv 0x0068ed30
void* NavMesh::DestroyNavMesh(unsigned int flags)
{
    FUN_0068ed70();
    if (flags & 1)
    {
        NiMemObject::operator delete(this, 0x108);
    }
    return this;
}


// @fnv 0x0068efb0
// src: XBOX_PDB 0x0068efb0
const NavMeshInfo* NavMesh::GetNavMeshInfo_0068efb0()
{
    return m_pNavigationMesh;
}

struct EdgeT
{
    unsigned short a;
    unsigned short b;
};
struct EdgeV
{
    const NiPoint3* a;
    const NiPoint3* b;
};
struct FloatValueProvider : public NavMesh
{
    EdgeV NavMesh_GetEdgeVertices_0(unsigned short tri, int idx);
};
// Fetches the edge indices for a triangle via FUN_0068efd0 and returns pointers to the two edge vertices from FUN_0068f0a0.
// @fnv 0x0068f040
// src: COMMUNITY 0x0068f040
EdgeV FloatValueProvider::NavMesh_GetEdgeVertices_0(unsigned short ausTriIndex, int aiEdgeIndex)
{
    EdgeT edge;
    EdgeV ev;
    GetEdge_0068efd0(&edge, ausTriIndex, aiEdgeIndex);
    ev.a = &GetVertex_0068f0a0(edge.a);
    ev.b = &GetVertex_0068f0a0(edge.b);
    return ev;
}


// @fnv 0x0068f0a0
// src: XBOX_PDB 0x0068f0a0
const NiPoint3& NavMesh::GetVertex_0068f0a0(unsigned short asVertexIndex)
{
    return *reinterpret_cast<const NiPoint3*>(&Vertices.GetAt((unsigned int)asVertexIndex));
}


// @fnv 0x0068f230
// src: XBOX_PDB 0x0068f230
EdgeExtraInfo* NavMesh::GetEdgeExtraInfo(unsigned short ausTriangleIndex, int aiEdgeIndex)
{
    if (Triangles.GetAt((int)ausTriangleIndex).IsEdgeFlagSet(aiEdgeIndex) &&
        Triangles.GetAt((int)ausTriangleIndex).GetEdgeExtraInfo_0068f2c0(aiEdgeIndex) != 0xFFFF)
        return &m_kEdgeExtraInfo.GetAt((unsigned int)Triangles.GetAt((int)ausTriangleIndex).GetEdgeExtraInfo_0068f2c0(aiEdgeIndex));
    else
        return 0;
}

// @fnv 0x0068f320
// src: XBOX_PDB 0x0068f320
bool __fastcall NavMeshInfo_GetDisabled(const NavMeshInfo* apNavMeshInfo)
{
    return (apNavMeshInfo->uiFlags & 0x10) != 0;
}

TESForm* __fastcall NavMeshInfo_GetParentSpace(const NavMeshInfo*);

// Casts the result of FUN_00690830(_this) to TESWorldSpace* and returns it.
// @fnv 0x00690800
// src: XBOX_PDB 0x00690800
TESWorldSpace* __fastcall NavMeshInfo_GetWorldSpace(const NavMeshInfo* apNavMeshInfo)
{
    return dynamic_cast<TESWorldSpace*>(NavMeshInfo_GetParentSpace(apNavMeshInfo));
}

TESForm* __cdecl _ref_004839c0(unsigned int);

// @fnv 0x00690830
// src: XBOX_PDB 0x00690830
TESForm* __fastcall NavMeshInfo_GetParentSpace(const NavMeshInfo* pThis)
{
    if (pThis->m_pParentSpace)
        return pThis->m_pParentSpace;
    else
        return _ref_004839c0(pThis->m_uiParentSpaceID);
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
typedef char _sizecheck_PathingAvoidNode[sizeof(PathingAvoidNode) == 36 ? 1 : -1];

void __fastcall _ref_006815c0(NiPoint3*);


// The shared constructor invokes NiPoint3 constructors; this entry only copies and initializes the fields.
struct PathingAvoidNodeInitializer : public PathingAvoidNode
{
    PathingAvoidNode* Initialize(const NiPoint3&, float, float);
};

// @fnv 0x006915d0
PathingAvoidNode* PathingAvoidNodeInitializer::Initialize(const NiPoint3& arPoint, float afRadius, float afCost)
{
    reinterpret_cast<ObjectBytes<sizeof(NiPoint3)>&>(m_kLocation) =
        reinterpret_cast<const ObjectBytes<sizeof(NiPoint3)>&>(arPoint);
    _ref_006815c0(&TwoComponentVector);
    fRadius = afRadius;
    m_fPathingCostCur = afCost;
    eType = 0;
    return this;
}

extern int DAT_01031fac;

struct FUN_006916f0_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_006916f0_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x006916f0
// src: EXE 0x006916f0
int* __fastcall NiTMap_unsigned_short_NiPointer_ObstacleData_NiTMap(int* self, FUN_006916f0_arg a)
{
    FUN_005890c0(self, a);
    *self = (int)&DAT_01031fac;
    return self;
}

namespace fnv_00691720 {
extern int DAT_01031fac;

struct FUN_00691720_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_00691720_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00691720
// src: EXE 0x00691720
int* __fastcall NiTMap_unsigned_short_NavMeshPOVData_NiTMap(int* self, FUN_00691720_arg a)
{
    FUN_005890c0(self, a);
    *self = (int)&DAT_01031fac;
    return self;
}
}  // namespace fnv_00691720

// @fnv 0x00691750
template <> NavMeshStaticAvoidNode& BSSimpleArray<NavMeshStaticAvoidNode, 1024>::GetAt(int aiIndex)
{
    return pBuffer[aiIndex];
}



// @fnv 0x00691800
template <> BSSimpleArray<unsigned short, 1024>::~BSSimpleArray()
{
    Clear(true);
}

// @fnv 0x00691a60
template <> BSSimpleArray<NavMeshVertex, 1024>::BSSimpleArray()
{
    _InitialSetup(0, 0);
}

// @fnv 0x00691b10
template <> BSSimpleArray<NavMeshTriangle, 1024>::BSSimpleArray()
{
    _InitialSetup(0, 0);
}

// @fnv 0x00691bc0
template <> BSSimpleArray<EdgeExtraInfo, 1024>::BSSimpleArray()
{
    _InitialSetup(0, 0);
}

// @fnv 0x00691d40
template <> BSSimpleArray<NavMeshTriangleDoorPortal, 1024>::BSSimpleArray()
{
    _InitialSetup(0, 0);
}

// @fnv 0x00691d90
template <> BSSimpleArray<NavMeshClosedDoorInfo, 1024>::BSSimpleArray()
{
    _InitialSetup(0, 0);
}

// @fnv 0x00691f60
template <> BSSimpleArray<NiPointer<ObstacleUndoData>, 1024>::BSSimpleArray()
{
    BSSimpleArray_NiPointer_ObstacleUndoData_1024_InitialSetup(0, false);
}

// @fnv 0x00691fb0
template <> BSSimpleArray<NavMeshStaticAvoidNode, 1024>::BSSimpleArray()
{
    _InitialSetup(0, 0);
}

typedef char _sizecheck_NavMeshClosedDoorInfo[sizeof(NavMeshClosedDoorInfo) == 8 ? 1 : -1];

// @fnv 0x00692870
NavMeshClosedDoorInfo::NavMeshClosedDoorInfo()
{
    m_uiDoorFormID = 0;
    m_usDoorTriangleIndex = 0xFFFF;
}

struct G00559a40
{
    void NiRefObject_IncRefCount();
};
struct Holder42
{
    char* p;
    Holder42* NiPointer_NavMesh_NiPointer_NavMesh_0042fd70(char*);
};
// Stores v in p and, when v is non-null, calls FUN_0040f6e0 on the object at v+0x1c; returns this.
// @fnv 0x0042fd70
// src: XBOX_PDB 0x0042fd70
Holder42* Holder42::NiPointer_NavMesh_NiPointer_NavMesh_0042fd70(char* v)
{
    p = v;
    if (p)
    {
        ((G00559a40*)(p + 0x1c))->NiRefObject_IncRefCount();
    }
    return this;
}

// Looks up the two vertex indices of the given triangle edge and writes their positions into p0 and p1, returning true.
// @fnv 0x0068f0c0
// src: COMMUNITY 0x0068f0c0
bool NavMesh::GetEdgeVertices_0068f0c0(unsigned short ausTriIndex, int aiEdgeIndex, NiPoint3* pStartVertex,
                                      NiPoint3* pEndVertex)
{
    int iNext;
    unsigned short v1;
    unsigned short v0;
    v1 = GetTriangle(ausTriIndex)->GetVert_005582d0(aiEdgeIndex);
    iNext = (aiEdgeIndex + 1) % 3;
    v0 = GetTriangle(ausTriIndex)->GetVert_005582d0(iNext);
    reinterpret_cast<ObjectBytes<sizeof(NiPoint3)>&>(*pStartVertex) =
        reinterpret_cast<const ObjectBytes<sizeof(NiPoint3)>&>(GetVertex_0068f0a0(v1));
    reinterpret_cast<ObjectBytes<sizeof(NiPoint3)>&>(*pEndVertex) =
        reinterpret_cast<const ObjectBytes<sizeof(NiPoint3)>&>(GetVertex_0068f0a0(v0));
    return true;
}


struct FUN_00690e10_shell
{
    char _pad0c[0x0c];
    unsigned int flags;
    bool __thiscall NavMeshTriangle_HasEdgeExtraInfo();
};

// @fnv 0x00690e10
// src: COMMUNITY 0x00690e10
bool __thiscall FUN_00690e10_shell::NavMeshTriangle_HasEdgeExtraInfo()
{
    return (flags & 7) != 0;
}

struct FUN_00691000_shell
{
    char _pad38[0x38];
    void BSSimpleArray_NavMeshTriangle_1024_Add(int);
    void NavMesh_AddTriangle(int arg);
};

// @fnv 0x00691000
// src: COMMUNITY 0x00691000
void FUN_00691000_shell::NavMesh_AddTriangle(int arg)
{
    ((FUN_00691000_shell*)((char*)this + 0x38))->BSSimpleArray_NavMeshTriangle_1024_Add(arg);
}

struct FUN_00691020_shell
{
    char _pad48[0x48];
    void BSSimpleArray_EdgeExtraInfo_1024_Add(int);
    void NavMesh_AddEdgeInfo(int a);
};

// @fnv 0x00691020
// src: COMMUNITY 0x00691020
void FUN_00691020_shell::NavMesh_AddEdgeInfo(int a)
{
    ((FUN_00691020_shell*)((char*)this + 0x48))->BSSimpleArray_EdgeExtraInfo_1024_Add(a);
}

// Exe 0x00691620: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct NavmeshOffset08View
{
    unsigned int GetFlags();
};


// @fnv 0x00691620
// src: COMMUNITY 0x00691620
unsigned int NavMesh::GetAvoidNodeCount()
{
    return m_kStaticAvoidNodes.GetSize();
}

struct FUN_00691640_shell : NavMesh
{
    NavMeshStaticAvoidNode* NavMesh_GetAvoidNode(int index);
};

// @fnv 0x00691640
// src: COMMUNITY 0x00691640
NavMeshStaticAvoidNode* FUN_00691640_shell::NavMesh_GetAvoidNode(int index)
{
    return &m_kStaticAvoidNodes.GetAt(index);
}

// @fnv 0x00691a90
template <> BSSimpleArray<NavMeshVertex, 1024>::~BSSimpleArray()
{
    Clear(true);
}

// @fnv 0x00691d70
template <> BSSimpleArray<NavMeshTriangleDoorPortal, 1024>::~BSSimpleArray()
{
    Clear(true);
}

// RTTI: NavMesh::POVPointerArray is NiTMap<unsigned short,NavMeshPOVData> (vftable 0x0106abc4) over
// NiTMapBase<DFALL<...>,unsigned short,NavMeshPOVData> (vftable 0x0106ac7c, IsKeysEqual 0x00691e50).
typedef NiTMapBase<DFALL<NiTMapItem<unsigned short, NavMeshPOVData> >, unsigned short, NavMeshPOVData> NavMeshPOVMapBase;

// @fnv 0x00691e50
template <> bool NavMeshPOVMapBase::IsKeysEqual(unsigned short ausLeft, unsigned short ausRight) const
{
    return ausLeft == ausRight;
}

extern "C" void _NiFreeAlias(void*);

// Sets the vtable pointer to "p!i", removes all entries from the map, and frees the member pointer.
// @fnv 0x00691f00
template <> NavMeshPOVMapBase::~NiTMapBase()
{
    RemoveAll();
    _NiFreeAlias(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8));
}

// @fnv 0x00691f90
template <> BSSimpleArray<NiPointer<ObstacleUndoData>, 1024>::~BSSimpleArray()
{
    RemoveAll(true);
}

namespace fnv_0042fd40 {
struct G00559a40
{
    void NiRefObject_IncRefCount();
};

struct FUN_0042fd40_shell
{
    void* NiPointer_NavMesh_NiPointer_NavMesh(void* arg);
};

// Copies the value from arg into this and, if non-zero, calls FUN_0040f6e0 on the object at offset 0x1c of that value; returns this.
// @fnv 0x0042fd40
// src: COMMUNITY 0x0042fd40
void* FUN_0042fd40_shell::NiPointer_NavMesh_NiPointer_NavMesh(void* apSource)
{
    *reinterpret_cast<unsigned int*>(this) = *reinterpret_cast<unsigned int*>(apSource);
    if (*reinterpret_cast<unsigned int*>(this) != 0)
    {
        reinterpret_cast<G00559a40*>(*reinterpret_cast<unsigned int*>(this) + 0x1c)->NiRefObject_IncRefCount();
    }
    return this;
}
}  // namespace fnv_0042fd40

// Looks up the triangle for a1 and writes pointers to the positions of its three vertices into a2, a3 and a4.
// @fnv 0x0068f160
void NavMesh::GetTriangleVertexPositions(unsigned short ausTriangleIndex, unsigned int* pVertex0, unsigned int* pVertex1,
                                    unsigned int* pVertex2)
{
    NavMeshTriangle* tri = GetTriangle(ausTriangleIndex);
    *pVertex0 = reinterpret_cast<unsigned int>(&this->GetVertex_0068f0a0(tri->GetVert_005582d0(0)));
    *pVertex1 = reinterpret_cast<unsigned int>(&this->GetVertex_0068f0a0(tri->GetVert_005582d0(1)));
    *pVertex2 = reinterpret_cast<unsigned int>(&this->GetVertex_0068f0a0(tri->GetVert_005582d0(2)));
}


struct FUN_00690df0_shell
{
    unsigned short pArray[1];
    void SetArrayElement(unsigned int index, unsigned short value);
};

// @fnv 0x00690df0
void FUN_00690df0_shell::SetArrayElement(unsigned int index, unsigned short value)
{
    pArray[index] = value;
}

struct FUN_00691160_shell
{
    unsigned short a[6];
    int b;
    void NavMeshTriangle_Clear();
};

// Sets all six elements of the array a to 0xffff and clears b to 0.
// @fnv 0x00691160
// src: COMMUNITY 0x00691160
void FUN_00691160_shell::NavMeshTriangle_Clear()
{
    a[0] = 0xffff;
    a[1] = 0xffff;
    a[2] = 0xffff;
    a[3] = 0xffff;
    a[4] = 0xffff;
    a[5] = 0xffff;
    b = 0;
}

// @fnv 0x00691b40
template <> BSSimpleArray<NavMeshTriangle, 1024>::~BSSimpleArray()
{
    Clear(true);
}

// @fnv 0x00691dc0
template <> BSSimpleArray<NavMeshClosedDoorInfo, 1024>::~BSSimpleArray()
{
    Clear(true);
}

struct FUN_00691e70_shell
{
    void UpdateState_00691e70(unsigned char* param1, unsigned short param2, unsigned int param3);
};

// Stores a 16-bit value at offset 4 and a 32-bit value at offset 6 of the given buffer.
// @fnv 0x00691e70
// src: GUESS 0x00691e70 (confidence: low)
void __thiscall FUN_00691e70_shell::UpdateState_00691e70(unsigned char* pBuffer, unsigned short usValue, unsigned int uiValue)
{
    *reinterpret_cast<unsigned short*>(pBuffer + 4) = usValue;
    *reinterpret_cast<unsigned int*>(pBuffer + 6) = uiValue;
}

// Calls FUN_0042ffa0(0) on each of the count elements of arr.
// @fnv 0x0042fb20
template <> void BSSimpleArray<NavMeshPtr, 1024>::ReleaseElements(NavMeshPtr* apItems, unsigned int count)
{
    for (int i = 0; i < count; ++i)
        apItems[i].FUN_0042ffa0(0);
}

void __fastcall FreeNavMeshPtrArrayBuffer(BSSimpleArray<NavMeshPtr, 1024>* array);
// @fnv 0x0042fc00
template <> void BSSimpleArray<NavMeshPtr, 1024>::ReallocateStorage(unsigned int requested, unsigned int key)
{
    if (pBuffer)
    {
        if (key == SimpleArrayStorage)
        {
            pBuffer = _Reallocate(pBuffer, requested);
        }
        else
        {
            NavMeshPtr* result = _Allocate(requested);
            UpdateEntryValue(result, pBuffer, key);
            FreeNavMeshPtrArrayBuffer(this);
            pBuffer = result;
        }
    }
    else
    {
        pBuffer = _Allocate(requested);
        SimpleArrayStorage = requested;
    }
}

// @fnv 0x0042fcb0
template <> void BSSimpleArray<NavMeshPtr, 1024>::_InitialSetup(unsigned int requested, unsigned int savedSize)
{
    pBuffer = 0;
    iSize = 0;
    SimpleArrayStorage = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        pBuffer = _Allocate(requested);
        SimpleArrayStorage = requested;
    }
    if (savedSize > 0)
    {
        InitializeItems(pBuffer, savedSize);
        iSize = savedSize;
    }
}

// @fnv 0x0068f2c0
// src: XBOX_PDB 0x0068f2c0
unsigned short NavMeshTriangle::GetEdgeExtraInfo_0068f2c0(int index)
{
    return ((unsigned short*)((char*)this + 6))[index];
}

// Calls the match helper with the input's _f4 and _f8, writing the resulting NavMesh pointer, _f4 and _f8 into the output.
// @fnv 0x0068f670
bool NavMesh::MatchNavMesh(const NavMeshEdgeData& pIn, NavMeshEdgeData& pOut)
{
    return FindAdjacentTriangle(pIn.m_usTriangleID, pIn.m_iEdgeIndex, pOut.m_pLocationNavMesh, pOut.m_usTriangleID, pOut.m_iEdgeIndex);
}

void __cdecl AddPoint(unsigned int);
struct FUN_00690fe0_shell
{
    void __thiscall NavMesh_AddVertex(unsigned int state);
};
// @fnv 0x00690fe0
// src: COMMUNITY 0x00690fe0
void __thiscall FUN_00690fe0_shell::NavMesh_AddVertex(unsigned int state)
{
    ((void(__thiscall*)(void*, unsigned int))AddPoint)(this + 0x28, state);
}

struct FUN_00691040_shell
{
    void GetPackedFlags(unsigned short, unsigned short*, bool*, bool*);
};
// Extracts a 4-bit value and two flag bits from the 32-bit field at offset 0xc, shifted by a1*6+16, writing them to a2, a3 and a4.
// @fnv 0x00691040
void FUN_00691040_shell::GetPackedFlags(unsigned short ausIndex, unsigned short* a2, bool* pbFlag16, bool* pbFlag32)
{
    unsigned int shift = ausIndex * 6 + 16;
    unsigned int uiBits = *(unsigned int*)((char*)this + 0xc) >> shift;
    *a2 = uiBits & 15;
    *pbFlag16 = 0 < (uiBits & 16);
    *pbFlag32 = 0 < (uiBits & 32);
}

struct Flt
{
    operator unsigned int();
};
struct S006911c0
{
    char _pad[0xA8];
    Flt _f;
    unsigned int NavMesh_GetGridCellCount();
};
// Returns the product of the float member converted to unsigned int with itself.
// @fnv 0x006911c0
// src: COMMUNITY 0x006911c0
unsigned int S006911c0::NavMesh_GetGridCellCount()
{
    return (unsigned int)_f * (unsigned int)_f;
}

struct FUN_006911f0_shell
{
    void NavMeshGrid_GetTrianglesForGridCell(int);
    void NavMesh_GetTrianglesForGridCell(int a);
};
// @fnv 0x006911f0
// src: COMMUNITY 0x006911f0
void FUN_006911f0_shell::NavMesh_GetTrianglesForGridCell(int a)
{
    ((FUN_006911f0_shell*)((char*)this + 0xa8))->NavMeshGrid_GetTrianglesForGridCell(a);
}

// Converts a point to grid coordinates via GetCellCoords and returns the linear cell index x * m_uiGridIndex + y.
// @fnv 0x00691260
int NavMeshGrid::GetCellIndex(NiPoint3 const& aPoint)
{
    unsigned int x = 0;
    {
        unsigned int y = 0;
        GetCellCoords(aPoint, x, y);
        return x * m_uiGridIndex + y;
    }
}

struct Dummy914e0
{
    int fld0;
    void NavMeshGrid_IsTriangleInGridCell_0(unsigned short, int);
    void NavMeshGrid_IsTriangleInGridCell(unsigned short, int, int);
};
// Calls FUN_0069da10 with a and b plus c multiplied by fld0.
// @fnv 0x006914e0
// src: COMMUNITY 0x006914e0
void Dummy914e0::NavMeshGrid_IsTriangleInGridCell(unsigned short a, int b, int c)
{
    NavMeshGrid_IsTriangleInGridCell_0(a, c * fld0 + b);
}

struct EH;
struct S5460
{
    unsigned int BSSimpleArray_NiPoint3_1024_AddUninitialized();
};
struct FUN_0069b310_S
{
    int _pad0;
    NiPoint3* pElementBuffer;
    void ConstructBounds(EH*, int);
    unsigned int AddPoint(const NiPoint3&);
};
// @fnv 0x00691ab0
unsigned int FUN_0069b310_S::AddPoint(const NiPoint3& aPoint)
{
    unsigned int index = ((S5460*)this)->BSSimpleArray_NiPoint3_1024_AddUninitialized();
    ConstructBounds((EH*)&pElementBuffer[index], 1);
    reinterpret_cast<ObjectBytes<sizeof(NiPoint3)>&>(pElementBuffer[index]) =
        reinterpret_cast<const ObjectBytes<sizeof(NiPoint3)>&>(aPoint);
    return index;
}

struct Elem16
{
    int a0;
    int a1;
    int a2;
    int a3;
};
struct Arr16
{
    int _pad0;
    Elem16* buffer;
    unsigned int BSSimpleArray_TeleportLink_1024_AddUninitialized();
    void BSSimpleArray_NavMeshTriangle_1024_ConstructItems(void*, int);
    unsigned int BSSimpleArray_NavMeshTriangle_1024_Add(Elem16*);
};
// @fnv 0x00691b60
// src: COMMUNITY 0x00691b60
unsigned int Arr16::BSSimpleArray_NavMeshTriangle_1024_Add(Elem16* apElement)
{
    unsigned int idx = BSSimpleArray_TeleportLink_1024_AddUninitialized();
    BSSimpleArray_NavMeshTriangle_1024_ConstructItems(&buffer[idx], 1);
    buffer[idx] = *apElement;
    return idx;
}

extern "C" void* __cdecl _NiMalloc(unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern const char $SG3635[];

// @fnv 0x00691de0
template <> NavMeshPOVMapBase::NiTMapBase(unsigned int count)
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) = count;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 12) = 0;
    unsigned int byteCount = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) * 4;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8) = _NiMalloc(byteCount);
    memset(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8), 0, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) * 4);
}

struct Unk65
{
    void FUN_0065de30(int);
};
struct Unk6b
{
    void FreeMemory(void*);
};
struct UnkParam
{
    char _pad[6];
    Unk65 f;
};
struct UnkHost
{
    char _pad[12];
    Unk6b f2;
    void ProcessState_00691f30(UnkParam*);
};
// Calls FUN_0065de30(0) on a1->f, then passes a1 to f2.FreeMemory.
// @fnv 0x00691f30
// src: GUESS 0x00691f30 (confidence: low)
void UnkHost::ProcessState_00691f30(UnkParam* pParam)
{
    pParam->f.FUN_0065de30(0);
    f2.FreeMemory(pParam);
}

namespace fnv_006dc990 {
// Exe 0x006dc990: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct NavmeshOffset08View
{
    unsigned int GetFlags();
};
struct Node680
{
    float EvaluateFalloff(int);
};
struct S3e60
{
    Node680* BSSimpleArray_PathingAvoidNode_1024_GetAt(unsigned int);
};
struct Sdc990
{
    float SumNodeValues(int);
};
// Sums the values returned by EvaluateFalloff(a1) over all nodes obtained from FUN_006a1400 up to GetFlags() count.
// @fnv 0x006dc990
float Sdc990::SumNodeValues(int a1)
{
    float fSum = 0.0f;
    unsigned int cnt = ((NavmeshOffset08View*)this)->GetFlags();
    unsigned int idx = 0;
    Node680* pNode;
    for (; idx < cnt; idx++)
    {
        pNode = ((S3e60*)this)->BSSimpleArray_PathingAvoidNode_1024_GetAt(idx);
        fSum += pNode->EvaluateFalloff(a1);
    }
    return fSum;
}
}  // namespace fnv_006dc990

struct DoorH
{
    TESForm* GetParentWorldSpace();
};
struct NavMeshProxy
{
    char _pad[0x24];
    DoorH* m_pOwningCell;
    TESForm* GetDoorForm();
};
// @fnv 0x0068ef70
TESForm* NavMeshProxy::GetDoorForm()
{
    if (m_pOwningCell)
    {
        if (m_pOwningCell->GetParentWorldSpace())
            return m_pOwningCell->GetParentWorldSpace();
        else
            return (TESForm*)m_pOwningCell;
    }
    else
    {
        return 0;
    }
}

struct NavMeshInfoProxy
{
    char _pad[0x54];
    void* field54;
    bool NavMeshInfo_GetDisabled() const;
    bool NavMeshInfo_GetNavMesh_0(void**);
};
// If FUN_0068f320() is true, sets *p to null and returns false; otherwise stores field54 in *p and returns whether field54 is non-null.
// @fnv 0x0068f2e0
// src: COMMUNITY 0x0068f2e0
bool NavMeshInfoProxy::NavMeshInfo_GetNavMesh_0(void** apOut)
{
    if (NavMeshInfo_GetDisabled())
    {
        *apOut = 0;
        return false;
    }
    *apOut = field54;
    return field54 != 0;
}

struct FUN_00844160_shell
{
    FUN_00844160_shell* BSSimpleArray_GroupMemberData_1024_GetAt(int);
};

// src: XBOX_PDB 0x00844160
FUN_00844160_shell* FUN_00844160_shell::BSSimpleArray_GroupMemberData_1024_GetAt(int index)
{
    return this;
}


// @fnv 0x0068f6b0
NavMeshEdgeExtra* NavMesh::GetEdge(unsigned short index)
{
    return reinterpret_cast<NavMeshEdgeExtra*>(((FUN_00844160_shell*)&m_kDoorPortals)->BSSimpleArray_GroupMemberData_1024_GetAt(index));
}

// Clears bit idx in fieldC and sets the corresponding entry of field6 to 0xffff.
// @fnv 0x00690790
void NavMeshTriangle::ClearFlag(int aiIndex)
{
    m_uiTriangleFlags &= ~(1 << aiIndex);
    Triangles[aiIndex] = 0xffff;
}

// Calls ClearFlag with a, then stores b into arr at index a.
// @fnv 0x006907d0
void NavMeshTriangle::SetArrayValue(int aiIndex, unsigned short ausValue)
{
    ClearFlag(aiIndex);
    Triangles[aiIndex] = ausValue;
}

struct Unk00690e30
{
    char _pad[6];
    unsigned short arr[3];
    unsigned int flags;
    void SetSlotValue(int, unsigned short);
};
// Sets bit a in flags and stores b into arr[a].
// @fnv 0x00690e30
void Unk00690e30::SetSlotValue(int aiIndex, unsigned short ausValue)
{
    flags |= (1 << aiIndex);
    arr[aiIndex] = ausValue;
}

struct FUN_00690e70_shell
{
    char _pad0c[0x0c];
    unsigned int field_c;
    bool IsFlag400Set();
};

// @fnv 0x00690e70
bool FUN_00690e70_shell::IsFlag400Set()
{
    return 0 < (field_c & 0x400);
}

struct S691210
{
    unsigned int m0;
    char _pad[32];
    int mBase;
    int NavMeshGrid_GetTrianglesForGridCell(unsigned int);
};
// Returns 0 if idx is outside m0*m0, otherwise returns idx*16 plus mBase.
// @fnv 0x00691210
// src: COMMUNITY 0x00691210
int S691210::NavMeshGrid_GetTrianglesForGridCell(unsigned int uiIndex)
{
    if (uiIndex >= m0 * m0)
    {
        return 0;
        goto done;
    }
    return uiIndex * 16 + mBase;
done:;
}

struct FUN_00691240_shell
{
    char _pad_a8[0xa8];
    struct Inner
    {
        void GetCellIndex(int);
    };
    Inner inner;
    void ForwardToInner(int arg);
};

// @fnv 0x00691240
void __thiscall FUN_00691240_shell::ForwardToInner(int arg)
{
    inner.GetCellIndex(arg);
}

namespace fnv_00691590 {
struct FUN_006915d0_helper
{
    char _pad[36];
    unsigned short field24;
    PathingAvoidNode* FUN_006915d0(NiPoint3 const&, float, float);
    FUN_006915d0_helper* NavMeshStaticAvoidNode_NavMeshStaticAvoidNode_0(NiPoint3 const&, unsigned short, float, float);
};
// Calls FUN_006915d0 with the position and two floats, stores the unsigned short in field24, and returns this.
// @fnv 0x00691590
// src: COMMUNITY 0x00691590
FUN_006915d0_helper* FUN_006915d0_helper::NavMeshStaticAvoidNode_NavMeshStaticAvoidNode_0(NiPoint3 const& akPosition, unsigned short ausValue, float c,
                                                       float d)
{
    FUN_006915d0(akPosition, c, d);
    field24 = ausValue;
    return this;
}
}  // namespace fnv_00691590

// The /Od game units call the /Od copy of the inline NiRefObject destructor (0x00496910) as the
// NiRefObject base cleanup; the NiMain libraries call the /O2 copy (0x00a5d3d0). The recipe binds
// ??1NiRefObject@@UAE@XZ to 0x00496910 for this unit.
// @fnv 0x0068ed70
NavMesh::~NavMesh()
{
    Vertices.Clear(true);
    Triangles.Clear(true);
    m_kEdgeExtraInfo.Clear(true);
    m_kDoorPortals.Clear(true);
    m_kIndexList.Clear(true);
    m_kGrid.Clear_0069d2d0();
    if (m_pNavigationMesh)
        ((TESRecipe*)m_pNavigationMesh)->SetCategory(0u);
    if (pTriangleToObstacleMap)
        delete (NiTMap<unsigned short, NiPointer<ObstacleData> >*)pTriangleToObstacleMap;
}


void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);


// Copies n 4-byte elements from b to a, choosing forward or backward iteration based on the relative addresses of a and b.
// @fnv 0x0042fb60
template <> void BSSimpleArray<NavMeshPtr, 1024>::UpdateEntryValue(NavMeshPtr* pDst, NavMeshPtr* pSrc, unsigned int n)
{
    if (n <= 0)
        return;
    if ((unsigned int)pDst < (unsigned int)pSrc)
    {
        for (unsigned int i = 0; i < n; ++i)
            FUN_00ec7230(reinterpret_cast<char*>(pDst) + i * 4, reinterpret_cast<const char*>(pSrc) + i * 4, 4);
    }
    else if ((unsigned int)pDst > (unsigned int)pSrc)
    {
        for (int i = (int)n - 1; i >= 0; --i)
            FUN_00ec7230(reinterpret_cast<char*>(pDst) + i * 4, reinterpret_cast<const char*>(pSrc) + i * 4, 4);
    }
}

namespace fnv_00690d50 {
struct FUN_0069d2d0_s
{
    void Clear_0069d2d0();
};
struct FUN_006b6a00_s
{
    void ActivateNavigationEntry();
};
struct FUN_0084e3a0_s
{
    void* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
extern TES g_TES;
struct FUN_00690d50_shell
{
    void NavMesh_ClearNavMesh(bool abCheckout);
};
// @fnv 0x00690d50
// src: COMMUNITY 0x00690d50
void FUN_00690d50_shell::NavMesh_ClearNavMesh(bool abCheckout)
{
    ((BSSimpleArray<NavMeshVertex, 1024>*)((char*)this + 0x28))->Clear(true);
    ((BSSimpleArray<NavMeshTriangle, 1024>*)((char*)this + 0x38))->Clear(true);
    ((BSSimpleArray<EdgeExtraInfo, 1024>*)((char*)this + 0x48))->Clear(true);
    ((FUN_0069d2d0_s*)((char*)this + 0xa8))->Clear_0069d2d0();
    ((BSSimpleArray<unsigned short, 1024>*)((char*)this + 0x78))->Clear(true);
    ((BSSimpleArray<NiPointer<ObstacleUndoData>, 1024>*)((char*)this + 0xd0))->RemoveAll(true);
    ((BSSimpleArray<NavMeshTriangleDoorPortal, 1024>*)((char*)this + 0x58))->Clear(true);
    if (*(void**)((char*)this + 0x104))
    {
        ((FUN_006b6a00_s*)((TES*)*(int*)&g_TES)->GetActiveCell(((FUN_0084e3a0_s*)this)->GetHavokWorldObjectCountInSceneGraph_0084e3a0()))
            ->ActivateNavigationEntry();
    }
}
}  // namespace fnv_00690d50

// @fnv 0x006910a0
void NavMesh::RebuildTriangleList()
{
    unsigned int i;
    unsigned int isize2;
    m_kIndexList.Clear(false);
    isize2 = Triangles.GetSize();
    for (i = 0; i < isize2; i++)
    {
        if (!GetTriangle(i)->GetFlag(0x20) && GetTriangle(i)->HasFlags())
        {
            m_kIndexList.ReserveIndex(i);
        }
    }
}


struct FUN_0069b030_S
{
    virtual ~FUN_0069b030_S();
    virtual int Write(unsigned int);
    void ConstructPairCells(int, unsigned int);
    void UpdateFields_00692520(unsigned int requested, unsigned int savedSize);
};

// @fnv 0x00692520
// src: GUESS 0x00692520 (confidence: low)
void FUN_0069b030_S::UpdateFields_00692520(unsigned int requested, unsigned int savedSize)
{
    ((int*)this)[1] = 0;
    ((int*)this)[2] = 0;
    ((int*)this)[3] = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        ((int*)this)[1] = Write(requested);
        ((int*)this)[3] = requested;
    }
    if (savedSize > 0)
    {
        ConstructPairCells(((int*)this)[1], savedSize);
        ((int*)this)[2] = savedSize;
    }
}

namespace fnv_00690e90 {
struct FUN_00690e10_shell
{
    bool NavMeshTriangle_HasEdgeExtraInfo();
};
struct Unk00690e30
{
    void SetSlotValue(int, unsigned short);
};
}  // namespace fnv_00690e90

// @fnv 0x00690e90
void NavMesh::UpdateTriangleExtraInfo(unsigned short aiExtraInfo)
{
    unsigned int i;
    unsigned int itriSize4;
    unsigned int t;

    m_kEdgeExtraInfo.RemoveAt(aiExtraInfo, 1u);
    itriSize4 = Triangles.GetSize();
    for (i = 0; i < itriSize4; ++i)
    {
        if (reinterpret_cast<fnv_00690e90::FUN_00690e10_shell*>(&Triangles.GetAt((int)i))->NavMeshTriangle_HasEdgeExtraInfo())
        {
            for (t = 0; t < 3; ++t)
            {
                if (Triangles.GetAt((int)i).IsEdgeFlagSet(t))
                {
                    if (Triangles.GetAt((int)i).GetEdgeExtraInfo_0068f2c0(t) == aiExtraInfo)
                    {
                        Triangles.GetAt((int)i).ClearFlag(t);
                    }
                    else if (Triangles.GetAt((int)i).GetEdgeExtraInfo_0068f2c0(t) == m_kEdgeExtraInfo.GetSize())
                    {
                        reinterpret_cast<fnv_00690e90::Unk00690e30*>(&Triangles.GetAt((int)i))
                            ->SetSlotValue(t, aiExtraInfo);
                    }
                }
            }
        }
    }
}

struct InfoView
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void FillCellName(StrMem*);
    unsigned int FUN_0054ddd0();
};


struct MeshView
{
    char* Modelloader_GetReferencedThis();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    unsigned int NavMesh_GetTriangleCount();
    unsigned int NavMeshInfo_GetWorldSpace();
    bool FUN_00690860(NavMeshPtr*);
};

struct EdgeInfoView
{
    int m_00;
    MeshView* m_04;
    unsigned short m_08;
    unsigned short m_0a;
};

extern double DAT_0106ab98;
extern const char DAT_0106ab40[];
extern const char DAT_0106aae8[];
extern const char DAT_0106aa90[];
extern const char DAT_0106aa28[];
extern const char DAT_0106a9c0[];
extern const char DAT_0106a960[];
extern const char DAT_0106a8f0[];
extern const char DAT_0106a860[];
extern const char DAT_0106a7d8[];
extern const char DAT_0106a770[];
extern const char DAT_0106a708[];
extern const char DAT_0106a6a0[];
extern const char DAT_0106a640[];
extern const char DAT_0106a5e0[];
extern const char DAT_0106a580[];
extern const char DAT_0106a520[];
extern const char DAT_0106a480[];
extern const char DAT_0106a418[];
extern const char DAT_0106a3b0[];
extern const char DAT_0106a330[];
extern const char DAT_0106a2c8[];
extern const char DAT_0106a260[];
extern const char DAT_0106a1f0[];

void __cdecl Warning_005b5e40(const char* fmt, ...);
int __cdecl FUN_00ec7595(double);
double __cdecl FUN_00408840(float);


// @fnv 0x0068f6d0
bool NavMesh::Validate(int a0)
{
    bool hadError = false;
    StrMem p;
    reinterpret_cast<InfoView*>(GetParentCell())->FillCellName(&p);

    for (unsigned int i = 0; i < Vertices.GetSize(); i++)
    {
        if (FUN_00ec7595(reinterpret_cast<NiPoint3&>(Vertices.GetAt(i)).x) == 0 || FUN_00408840(reinterpret_cast<NiPoint3&>(Vertices.GetAt(i)).x) > DAT_0106ab98)
        {
            Warning_005b5e40(DAT_0106ab40, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis());
            hadError = true;
            break;
        }
        if (FUN_00ec7595(reinterpret_cast<NiPoint3&>(Vertices.GetAt(i)).y) == 0 || FUN_00408840(reinterpret_cast<NiPoint3&>(Vertices.GetAt(i)).y) > DAT_0106ab98)
        {
            Warning_005b5e40(DAT_0106aae8, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis());
            hadError = true;
            break;
        }
        if (FUN_00ec7595(reinterpret_cast<NiPoint3&>(Vertices.GetAt(i)).z) == 0 || FUN_00408840(reinterpret_cast<NiPoint3&>(Vertices.GetAt(i)).z) > DAT_0106ab98)
        {
            Warning_005b5e40(DAT_0106aa90, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis());
            hadError = true;
            break;
        }
    }

    if (Triangles.GetSize() >= 0x7d0)
    {
        Warning_005b5e40(DAT_0106aa28, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), Triangles.GetSize());
    }

    for (unsigned int j = 0; j < Triangles.GetSize(); j++)
    {
        NavMeshTriangle* triA = &Triangles.GetAt(j);
        for (long k = 0; k < 3; k++)
        {
            if (!triA->IsEdgeFlagSet(k) && triA->IsEdgeConnected(k) != 0 && triA->GetEdgeExtraInfo_0068f2c0(k) >= Triangles.GetSize())
            {
                Warning_005b5e40(DAT_0106a9c0, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), j, k);
                triA->SetArrayValue(k, 0xffff);
                hadError = true;
            }
        }
        NiPoint3 normal = FUN_006971e0((unsigned short)j);
        if (normal.z < 0.0f)
        {
            Warning_005b5e40(DAT_0106a960, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), j);
            SwapTriangleEdges((unsigned short)j);
            hadError = true;
        }
    }

    for (unsigned int b = 0; b < Triangles.GetSize(); b++)
    {
        NavMeshTriangle* sh = FUN_005582f0((unsigned short)b);
        for (long tri7 = 0; tri7 < 3; tri7++)
        {
            if (sh->IsEdgeFlagSet(tri7))
            {
                if (sh->GetEdgeExtraInfo_0068f2c0(tri7) >= m_kEdgeExtraInfo.GetSize())
                {
                    Warning_005b5e40(DAT_0106a8f0, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), b, tri7);
                    sh->ClearFlag(tri7);
                    hadError = true;
                    continue;
                }
                EdgeInfoView* pRetrievedObject = reinterpret_cast<EdgeInfoView*>(GetEdgeExtraInfo((unsigned short)b, tri7));
                if (pRetrievedObject->m_04 == 0)
                {
                    UpdateTriangleExtraInfo(sh->GetEdgeExtraInfo_0068f2c0(tri7));
                    hadError = true;
                    continue;
                }
                else if (pRetrievedObject->m_08 == 0xffff)
                {
                    UpdateTriangleExtraInfo(sh->GetEdgeExtraInfo_0068f2c0(tri7));
                    hadError = true;
                    continue;
                }
                else
                {
                    NavMeshPtr pTri;
                    if (pRetrievedObject->m_04->FUN_00690860(&pTri))
                    {
                        if (pRetrievedObject->m_08 >= ((MeshView*)pTri.Modelloader_GetReferencedThis())->NavMesh_GetTriangleCount())
                        {
                            Warning_005b5e40(DAT_0106a860, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), b, tri7,
                                         ((MeshView*)pTri.Modelloader_GetReferencedThis())->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), pRetrievedObject->m_08);
                            UpdateTriangleExtraInfo(sh->GetEdgeExtraInfo_0068f2c0(tri7));
                            hadError = true;
                            continue;
                        }
                    }
                    if (reinterpret_cast<InfoView*>(GetParentCell())->FUN_0054ddd0() != pRetrievedObject->m_04->NavMeshInfo_GetWorldSpace())
                    {
                        Warning_005b5e40(DAT_0106a7d8, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), b, tri7,
                                     pRetrievedObject->m_04->Modelloader_GetReferencedThis());
                        UpdateTriangleExtraInfo(sh->GetEdgeExtraInfo_0068f2c0(tri7));
                        hadError = true;
                        continue;
                    }
                }
            }
        }
    }

    for (unsigned int t4 = 0; t4 < Triangles.GetSize(); t4++)
    {
        NavMeshTriangle* tri4 = FUN_005582f0((unsigned short)t4);
        if (tri4->GetVert_005582d0(0) == tri4->GetVert_005582d0(1))
        {
            Warning_005b5e40(DAT_0106a770, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), t4, tri4->GetVert_005582d0(0));
            hadError = true;
        }
        if (tri4->GetVert_005582d0(0) == tri4->GetVert_005582d0(2))
        {
            Warning_005b5e40(DAT_0106a708, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), t4, tri4->GetVert_005582d0(0));
            hadError = true;
        }
        if (tri4->GetVert_005582d0(1) == tri4->GetVert_005582d0(2))
        {
            Warning_005b5e40(DAT_0106a6a0, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), t4, tri4->GetVert_005582d0(1));
            hadError = true;
        }
    }

    for (unsigned int e7 = 0; e7 < Triangles.GetSize(); e7++)
    {
        NavMeshTriangle* tri5 = FUN_005582f0((unsigned short)e7);
        if (tri5->GetEdgeExtraInfo_0068f2c0(0) == tri5->GetEdgeExtraInfo_0068f2c0(1) && tri5->GetEdgeExtraInfo_0068f2c0(0) != 0xffff &&
            tri5->IsEdgeFlagSet(0) == tri5->IsEdgeFlagSet(1))
        {
            Warning_005b5e40(DAT_0106a640, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), e7, tri5->GetEdgeExtraInfo_0068f2c0(0));
            hadError = true;
        }
        if (tri5->GetEdgeExtraInfo_0068f2c0(0) == tri5->GetEdgeExtraInfo_0068f2c0(2) && tri5->GetEdgeExtraInfo_0068f2c0(0) != 0xffff &&
            tri5->IsEdgeFlagSet(0) == tri5->IsEdgeFlagSet(2))
        {
            Warning_005b5e40(DAT_0106a5e0, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), e7, tri5->GetEdgeExtraInfo_0068f2c0(0));
            hadError = true;
        }
        if (tri5->GetEdgeExtraInfo_0068f2c0(1) == tri5->GetEdgeExtraInfo_0068f2c0(2) && tri5->GetEdgeExtraInfo_0068f2c0(1) != 0xffff &&
            tri5->IsEdgeFlagSet(1) == tri5->IsEdgeFlagSet(2))
        {
            Warning_005b5e40(DAT_0106a580, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), e7, tri5->GetEdgeExtraInfo_0068f2c0(1));
            hadError = true;
        }
    }

    for (unsigned int t6 = 0; t6 < Triangles.GetSize(); t6++)
    {
        NavMeshTriangle* tri6 = FUN_005582f0((unsigned short)t6);
        for (long e6 = 0; 3 > e6; e6++)
        {
            int edge = e6;
            unsigned int e = edge + 1;
            if (e == 3)
                e = 0;
            unsigned short vA = tri6->GetVert_005582d0(edge);
            unsigned short pForm = tri6->GetVert_005582d0(e);
            for (int tri3 = 0; tri3 < Triangles.GetSize(); tri3++)
            {
                if (tri3 == t6)
                    continue;
                NavMeshTriangle* tri = FUN_005582f0((unsigned short)tri3);
                for (int t5 = 0; t5 < 3; t5++)
                {
                    if (tri->GetVert_005582d0(t5) != pForm)
                        continue;
                    unsigned short tIn = (unsigned short)(t5 + 1);
                    if (tIn == 3)
                        tIn = 0;
                    for (int e8 = 0; 3 > e8; e8++)
                    {
                        if (e8 == t5)
                            continue;
                        if (tri->GetVert_005582d0(e8) != vA)
                            continue;
                        if (e8 != tIn)
                        {
                            Warning_005b5e40(DAT_0106a520, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), t6, tri3);
                            hadError = true;
                        }
                        if (!tri6->IsEdgeFlagSet(e6))
                        {
                            if (tri6->GetEdgeExtraInfo_0068f2c0(e6) != 0xffff)
                            {
                                if (tri->IsEdgeFlagSet(t5))
                                {
                                    Warning_005b5e40(DAT_0106a480, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), t6, e6, tri3, tri3,
                                                 t5);
                                    hadError = true;
                                }
                                if (tri6->GetEdgeExtraInfo_0068f2c0(e6) != tri3)
                                {
                                    Warning_005b5e40(DAT_0106a418, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), t6, e6, tri3);
                                    hadError = true;
                                }
                                if (tri->GetEdgeExtraInfo_0068f2c0(t5) != t6)
                                {
                                    Warning_005b5e40(DAT_0106a418, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), tri3, t5, t6);
                                    hadError = true;
                                }
                            }
                        }
                        else
                        {
                            if (!tri->IsEdgeFlagSet(t5))
                            {
                                Warning_005b5e40(DAT_0106a3b0, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), tri3, t5);
                                hadError = true;
                            }
                        }
                    }
                }
            }
        }
    }

    for (unsigned int e10 = 0; e10 < Triangles.GetSize(); e10++)
    {
        NavMeshTriangle* tri8 = FUN_005582f0((unsigned short)e10);
        for (int e9 = 0; 3 > e9; e9++)
        {
            if (!tri8->IsEdgeFlagSet(e9) && tri8->GetEdgeExtraInfo_0068f2c0(e9) != 0xffff)
            {
                NavMeshTriangle* h = FUN_005582f0(tri8->GetEdgeExtraInfo_0068f2c0(e9));
                bool s = false;
                int a;
                for (a = 0; 3 > a; a++)
                {
                    if (!h->IsEdgeFlagSet(a) && h->GetEdgeExtraInfo_0068f2c0(a) != 0xffff && h->GetEdgeExtraInfo_0068f2c0(a) == e10)
                    {
                        s = true;
                        break;
                    }
                }
                if (!s)
                {
                    Warning_005b5e40(DAT_0106a330, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), e10, tri8->GetEdgeExtraInfo_0068f2c0(e9),
                                 tri8->GetEdgeExtraInfo_0068f2c0(e9));
                    hadError = true;
                }
                if (a < 3)
                {
                    int bIdx = e9;
                    long c = e9 + 1;
                    if (c == 3)
                        c = 0;
                    int c2 = a;
                    int q = a + 1;
                    if (q == 3)
                        q = 0;
                    if (tri8->GetVert_005582d0(bIdx) != h->GetVert_005582d0(q) || tri8->GetVert_005582d0(c) != h->GetVert_005582d0(c2))
                    {
                        Warning_005b5e40(DAT_0106a2c8, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), e10, tri8->GetEdgeExtraInfo_0068f2c0(e9));
                        hadError = true;
                    }
                }
            }
        }
    }

    for (unsigned int ci = 0; ci < m_kIndexList.GetSize(); ci++)
    {
        unsigned short triC = m_kIndexList.GetBufferEntry(ci);
        NavMeshTriangle* coverTri = FUN_005582f0(triC);
        if (coverTri == 0)
        {
            Warning_005b5e40(DAT_0106a260, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), ci, triC);
            hadError = true;
        }
        else if (!coverTri->HasFlags())
        {
            Warning_005b5e40(DAT_0106a1f0, GetHavokWorldObjectCountInSceneGraph_0084e3a0(), p.Modelloader_GetReferencedThis(), ci, triC);
            hadError = true;
        }
    }

    CheckNeighborCells();
    return !hadError;
}


// @fnv 0x00690770
bool NavMeshTriangle::HasFlags()
{
    return (m_uiTriangleFlags & 0xfbe0000) > 0;
}

struct ProbeResult
{
    void* value;
    ~ProbeResult();
    void* AnimatingText_GetFullText();
};

struct ProbeArray
{
    unsigned int GetReferenceFlags();
    ProbeResult FUN_00464f60(unsigned int index);
};

struct ProbeHolder
{
    ProbeArray* DetailedActorPathHandler_GetCurrentNodeIndex();
};

struct ProbeCell
{
    ProbeHolder* FUN_005875a0();
};

struct ProbeGrid
{
    bool FUN_00425fd0();
    int FUN_00544c30();
    int FUN_00544c60();
    ProbeCell* FUN_0054ddd0(int x, int y);
};

bool __cdecl Cmd_Default_Execute(void* self, void* value, int mode, float x, float y);


// @fnv 0x006908f0
bool NavMesh::CheckNeighborCells()
{
    if (reinterpret_cast<ProbeGrid*>(GetParentCell())->FUN_00425fd0())
    {
        return true;
    }

    bool result = true;
    int cellX2 = reinterpret_cast<ProbeGrid*>(GetParentCell())->FUN_00544c30();
    int cellY8 = reinterpret_cast<ProbeGrid*>(GetParentCell())->FUN_00544c60();

    float xWorld = (float)(cellX2 << 12);
    ProbeHolder* kWest = reinterpret_cast<ProbeGrid*>(GetParentCell())->FUN_0054ddd0(cellX2 - 1, cellY8)->FUN_005875a0();
    if (kWest != 0 && kWest->DetailedActorPathHandler_GetCurrentNodeIndex() != 0)
    {
        for (unsigned int westIdx = 0; westIdx < kWest->DetailedActorPathHandler_GetCurrentNodeIndex()->GetReferenceFlags(); ++westIdx)
        {
            if (!Cmd_Default_Execute(this, kWest->DetailedActorPathHandler_GetCurrentNodeIndex()->FUN_00464f60(westIdx).AnimatingText_GetFullText(), 1, xWorld, 0.0f))
            {
                result = false;
            }
        }
    }

    xWorld = (float)(cellX2 << 12) + 4096.0;
    ProbeHolder* east = reinterpret_cast<ProbeGrid*>(GetParentCell())->FUN_0054ddd0(cellX2 + 1, cellY8)->FUN_005875a0();
    if (east != 0 && east->DetailedActorPathHandler_GetCurrentNodeIndex() != 0)
    {
        for (unsigned int eastIdx = 0; eastIdx < east->DetailedActorPathHandler_GetCurrentNodeIndex()->GetReferenceFlags(); ++eastIdx)
        {
            if (!Cmd_Default_Execute(this, east->DetailedActorPathHandler_GetCurrentNodeIndex()->FUN_00464f60(eastIdx).AnimatingText_GetFullText(), 1, xWorld, 0.0f))
            {
                result = false;
            }
        }
    }

    float yWorld = (float)(cellY8 << 12);
    ProbeHolder* southVal = reinterpret_cast<ProbeGrid*>(GetParentCell())->FUN_0054ddd0(cellX2, cellY8 - 1)->FUN_005875a0();
    if (southVal != 0 && southVal->DetailedActorPathHandler_GetCurrentNodeIndex() != 0)
    {
        for (unsigned int southIdx = 0; southIdx < southVal->DetailedActorPathHandler_GetCurrentNodeIndex()->GetReferenceFlags(); ++southIdx)
        {
            if (!Cmd_Default_Execute(this, southVal->DetailedActorPathHandler_GetCurrentNodeIndex()->FUN_00464f60(southIdx).AnimatingText_GetFullText(), 0, 0.0f, yWorld))
            {
                result = false;
            }
        }
    }

    yWorld = (float)(cellY8 << 12) + 4096.0;
    ProbeHolder* north2 = reinterpret_cast<ProbeGrid*>(GetParentCell())->FUN_0054ddd0(cellX2, cellY8 + 1)->FUN_005875a0();
    if (north2 != 0 && north2->DetailedActorPathHandler_GetCurrentNodeIndex() != 0)
    {
        for (unsigned int northIdx = 0; northIdx < north2->DetailedActorPathHandler_GetCurrentNodeIndex()->GetReferenceFlags(); ++northIdx)
        {
            if (!Cmd_Default_Execute(this, north2->DetailedActorPathHandler_GetCurrentNodeIndex()->FUN_00464f60(northIdx).AnimatingText_GetFullText(), 0, 0.0f, yWorld))
            {
                result = false;
            }
        }
    }

    return result;
}


// @fnv 0x00691140
bool NavMeshTriangle::GetFlag(int aFlag)
{
    return (aFlag & *(unsigned int*)((char*)this + 0xc)) != 0;
}

float __cdecl floorf(float x);
void __cdecl ClampInt(int* value, int lo, int hi);

// @fnv 0x006912a0
void NavMeshGrid::GetCellCoords(NiPoint3 const& point, unsigned int& outRow, unsigned int& outCol)
{
    float dxH = point.x - this->IndexedPointRecord.x;
    float dY0 = point.y - this->IndexedPointRecord.y;
    float gx1 = dxH / this->m_fFirstGridValue;
    float gY = dY0 / this->NavMeshPointEntry;

    int nCol = (int)floorf(gx1);
    ClampInt(&nCol, 0, (int)this->m_uiGridIndex - 1);
    outCol = nCol;

    int row = (int)floorf(gY);
    ClampInt(&row, 0, (int)this->m_uiGridIndex - 1);
    outRow = row;
}

struct GridStub
{
    int gridWidth;
    void GetCoords(const NiPoint3& pt, unsigned int& x, unsigned int& y);
    bool EmptyStructPlaceholder(unsigned short tri, int y, int x);
    int GetWidth();
};
struct OutArr
{
    void Clear(bool);
    unsigned int Add(int&);
    unsigned int GetSize();
};
unsigned int MaxU(unsigned int, unsigned int);
unsigned int MinU(unsigned int, unsigned int);
// @fnv 0x00691350
unsigned int NavMesh::CollectTriangleCells(unsigned short tri, OutArr& out)
{
    NavMeshTriangle* pTri6 = &Triangles.GetAt((int)tri);
    out.Clear(false);
    unsigned int maxX2 = 0;
    unsigned int minX7 = 0xFFFFFFFF;
    unsigned int maxY8 = 0;
    unsigned int minY7 = 0xFFFFFFFF;
    for (unsigned int i = 0; i < 3; i++)
    {
        const NiPoint3& pt2 = GetVertex_0068f0a0(pTri6->GetVert_005582d0(i));
        unsigned int x9 = 0;
        unsigned int y6 = 0;
        reinterpret_cast<GridStub*>(&m_kGrid)->GetCoords(pt2, x9, y6);
        maxX2 = MaxU(maxX2, x9);
        minX7 = MinU(minX7, x9);
        maxY8 = MaxU(maxY8, y6);
        minY7 = MinU(minY7, y6);
    }
    for (unsigned int xi2 = minX7; xi2 < maxX2 + 1; xi2++)
    {
        for (unsigned int yi = minY7; yi < maxY8 + 1; yi++)
        {
            if (reinterpret_cast<GridStub*>(&m_kGrid)->EmptyStructPlaceholder(tri, yi, xi2))
            {
                int cell = reinterpret_cast<GridStub*>(&m_kGrid)->GetWidth() * xi2 + yi;
                out.Add(cell);
            }
        }
    }
    return out.GetSize();
}

struct AvoidNodeDescription
{
    float point1[3], point2[3];
    float radius, cost;
    unsigned int type, flags;
    void NavMeshStaticAvoidNode_NavMeshStaticAvoidNode_0(void* source, unsigned short triangle, float radius, float cost);
};
struct StaticAvoidOps : BSSimpleArray<NavMeshStaticAvoidNode, 1024>
{
    void AddData(AvoidNodeDescription* node);
};
// @fnv 0x00691510
void NavMesh::AddAvoidNode(void* source, unsigned short triangle, float radius, float cost)
{
    AvoidNodeDescription avoidNode;
    avoidNode.NavMeshStaticAvoidNode_NavMeshStaticAvoidNode_0(source, triangle, radius, cost);
    Triangles.GetAt((int)triangle).SetFlag_00691570(0x80000000u);
    reinterpret_cast<StaticAvoidOps*>(&m_kStaticAvoidNodes)->AddData(&avoidNode);
}


// @fnv 0x00691570
// src: COMMUNITY 0x00691570
void NavMeshTriangle::SetFlag_00691570(unsigned int aFlag)
{
    *(unsigned int*)((char*)this + 0xc) |= aFlag;
}

// @fnv 0x0068efd0
// src: COMMUNITY 0x0068efd0
EdgeT* NavMesh::GetEdge_0068efd0(EdgeT* out, unsigned short tri, int idx)
{
    EdgeT r;
    r.a = FUN_005582f0(tri)->GetVert_005582d0(idx);
    int m2 = (idx + 1) % 3;
    r.b = FUN_005582f0(tri)->GetVert_005582d0(m2);
    *out = r;
    return out;
}


// Returns true if the bit at aiEdgeIndex is set in the 32-bit flags word at offset 0xc of this NavMeshTriangle.
// @fnv 0x0068f1d0
bool NavMeshTriangle::IsEdgeFlagSet(int aiEdgeIndex)
{
    return ((1 << aiEdgeIndex) & *(unsigned int*)((char*)this + 0xc)) != 0;
}


// Returns true if the triangle's edge entry at aiEdgeIndex is not 0xFFFF.
// @fnv 0x0068f200
// src: XBOX_PDB 0x0068f200
unsigned char NavMeshTriangle::IsEdgeConnected(int aiEdgeIndex)
{
    return (unsigned int)(((unsigned short*)((char*)this + 6))[aiEdgeIndex] != 0xFFFF);
}

extern float DAT_01016970;
class D2d0Elem
{
  public:
    virtual ~D2d0Elem();
    int m_04;
};
struct D2d0Cls
{
    int m_00;
    int m_04, m_08;
    float m_0c;
    int m_10, m_14, m_18, m_1c, m_20;
    D2d0Elem* m_24;
    void Clear_0069d2d0();
};
// Deletes the m_24 array and clears it, resets m_00 to 0 and sets m_0c to DAT_01016970.
// @fnv 0x0069d2d0
// src: COMMUNITY 0x0069d2d0
void D2d0Cls::Clear_0069d2d0()
{
    if (m_24)
    {
        delete[] m_24;
        m_24 = 0;
    }
    m_00 = 0;
    m_0c = DAT_01016970;
}

NiPointer<NavMesh> MakeNavMeshPointer(NavMesh* pMesh);
// @fnv 0x0068f3b0
// src: XBOX_PDB 0x0068f3b0
bool NavMesh::GetMatchingEdge(unsigned short usTri, int m_iEdgeNumber, NiPointer<NavMesh>& apMeshOut, int a4,
                                    int a5)
{
    NavMesh* pMesh = 0;
    if (FindAdjacentEdge(usTri, m_iEdgeNumber, &pMesh, a4, a5))
    {
        apMeshOut = MakeNavMeshPointer(pMesh);
        return true;
    }
    else
    {
        return false;
    }
}

struct ProxyX
{
    bool NavMeshInfo_GetNavMesh_0(void** appOut);
};

struct EInfoX
{
    int type;
    ProxyX* portal;
    unsigned short tri;
    unsigned short pad;
};



// Finds the mesh, triangle and edge adjacent to aTri/aEdge, following a portal or the triangle's neighbour, and writes them to the out parameters.
// @fnv 0x0068f460
bool NavMesh::FindAdjacentEdge(unsigned short aTri, int aEdge, NavMesh** appOutMesh, unsigned short* apTri, int* apEdge)
{
    if (aTri >= this->NavMesh_GetTriangleCount())
        return false;
    NavMeshTriangle* pTri = this->GetTriangle(aTri);
    if (pTri->IsEdgeConnected(aEdge))
    {
        if (pTri->IsEdgeFlagSet(aEdge))
        {
            EInfoX* pEdgeInfo = reinterpret_cast<EInfoX*>(this->GetEdgeInfo(aTri, aEdge));
            if (!pEdgeInfo->portal)
            {
                return false;
            }
            else
            {
                NavMesh* pMesh;
                if (pEdgeInfo->portal->NavMeshInfo_GetNavMesh_0((void**)&pMesh))
                {
                    unsigned short usPortalTri = pEdgeInfo->tri;
                    if (usPortalTri >= pMesh->NavMesh_GetTriangleCount())
                        return false;
                    NavMeshTriangle* pAdjTriangle = pMesh->GetTriangle(usPortalTri);
                    int q;
                    for (q = 0; q < 3; q++)
                    {
                        if (pAdjTriangle->IsEdgeFlagSet(q))
                        {
                            EInfoX* pE = reinterpret_cast<EInfoX*>(pMesh->GetEdgeInfo(usPortalTri, q));
                            if (!pE)
                                continue;
                            if (reinterpret_cast<const void*>(pE->portal) == this->GetNavMeshInfo_0068efb0() && pE->tri == aTri)
                                break;
                        }
                    }
                    if (q == 3)
                    {
                        return false;
                    }
                    else
                    {
                        *appOutMesh = pMesh;
                        *apTri = usPortalTri;
                        *apEdge = q;
                        return true;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            *appOutMesh = this;
            *apTri = pTri->GetEdgeExtraInfo_0068f2c0(aEdge);
            NavMeshTriangle* pAdjTriangle = this->GetTriangle(*apTri);
            int r;
            for (r = 0; r < 3; r++)
            {
                if (!pAdjTriangle->IsEdgeFlagSet(r) && pAdjTriangle->GetEdgeExtraInfo_0068f2c0(r) == aTri)
                    break;
            }
            if (r >= 3)
                return false;
            *apEdge = r;
            return true;
        }
    }
    else
    {
        return false;
    }
}


class NavMeshEdgeRef
{
public:
    int unk00;
    unsigned short m_usTriangleID;
    unsigned short unk06;
    int m_iEdgeNumber;
};

class NavMeshEdgeOut
{
public:
    const NavMeshInfo* m_pNavigationMesh;
    unsigned short m_usTriangleID;
    unsigned short unk06;
    int m_iEdgeNumber;
};

// On success, stores the adjacent mesh's navigation info, triangle ID, and edge number in pkOut.
// @fnv 0x0068f340
// src: COMMUNITY 0x0068f340
bool NavMesh::GetMatchingEdge_1(const NavMeshEdgeRef* pkRef, NavMeshEdgeOut* pkOut)
{
    NavMesh* m_pLocationNavMesh = 0;
    int edgeIndex = -1;
    unsigned short triangle;
    if (FindAdjacentEdge(pkRef->m_usTriangleID, pkRef->m_iEdgeNumber, &m_pLocationNavMesh, &triangle, &edgeIndex))
    {
        pkOut->m_pNavigationMesh = m_pLocationNavMesh->GetNavMeshInfo_0068efb0();
        pkOut->m_usTriangleID = triangle;
        pkOut->m_iEdgeNumber = edgeIndex;
        return true;
    }
    else
    {
        return false;
    }
}

class FUN_00691f00
{
  public:
    virtual ~FUN_00691f00();

    void FUN_00438af0();
};

class FUN_00691ea0 : public FUN_00691f00
{
  public:
    virtual ~FUN_00691ea0();
};

// @fnv 0x00691ea0
FUN_00691ea0::~FUN_00691ea0()
{
    FUN_00438af0();
}
