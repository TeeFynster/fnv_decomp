// fallout_shared/pathfinding/pathinglocation.cpp: PathingLocation and pathfinding helpers (34 functions)

#include "pathinglocation_decls.h"
#include "../../../include/BGSSaveFormBuffer.h"

// @fnv 0x004ff7e0
PathingLocation::~PathingLocation()
{
}

// @fnv 0x006dce10
PathingLocation::PathingLocation(const NiPoint3& location, TESObjectREFR* reference)
{
    SetLocationData(location, reinterpret_cast<TESObjectCELL*>(reinterpret_cast<LowProcess*>(reference)->LowProcess::GetTarget()),
                    reference->GetParentWorldSpace());
}

static const int kClearTriangleDataValue1 = 65535;

// @fnv 0x006ddbe0
void PathingLocation::ResetLocation()
{
    m_usTriangleID = kClearTriangleDataValue1;
}

// Copies Location, the Id fields, pCell and uiFlags from other into this PathingLocation and returns *this.
// @fnv 0x006dcce0
PathingLocation& PathingLocation::operator=(const PathingLocation& other)
{
    Location = other.Location;
    m_pLocationNavMesh = other.m_pLocationNavMesh;
    pNavMeshInfoArray = other.pNavMeshInfoArray;
    pCell = other.pCell;
    m_pContainingWorldspace = other.m_pContainingWorldspace;
    m_uiPathingFlags = other.m_uiPathingFlags;
    m_usTriangleID = other.m_usTriangleID;
    uiFlags = other.uiFlags;
    return *this;
}

// @fnv 0x006dd4f0
TESObjectCELL* PathingLocation::GetContainingCell()
{
    if (pCell)
        return pCell;
    else if (m_pContainingWorldspace)
    {
        TESObjectCELL* cell = m_pContainingWorldspace->GetCellByKey(m_uiPathingFlags);
        if (cell)
            return cell;
    }
    return 0;
}

// @fnv 0x006dd610
bool PathingLocation::ResolveNavMesh(NavMeshPtr& navMesh)
{
    if (m_pLocationNavMesh)
        return const_cast<NavMeshInfo*>(m_pLocationNavMesh)->ResolveNavMesh(navMesh);
    else
        return false;
}

// If a NavMeshInfo is set and its triangle index is valid, checks it against navMesh, writes the triangle index to triangle and returns true.
// @fnv 0x006dd640
bool PathingLocation::FindNavMeshTriangle(NavMeshPtr& navMesh, unsigned short& triangle)
{
    if (m_pLocationNavMesh)
    {
        if (m_usTriangleID == 0xFFFF)
            return false;
        if (!const_cast<NavMeshInfo*>(m_pLocationNavMesh)->ResolveNavMesh(navMesh))
            return false;
        triangle = m_usTriangleID;
        return true;
    }
    else
        return false;
}

// @fnv 0x006dd540
void* PathingLocation::GetAssociatedNavMesh()
{
    if (m_pLocationNavMesh)
        return const_cast<NavMeshInfo*>(m_pLocationNavMesh);
    else if (!pNavMeshInfoArray)
        return 0;
    else if (IsPathingLocationFlagSet())
        return (void*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(0);
    else
        return 0;
}

void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);
// Placement-constructs count PathingLocation objects in the items array.
// @fnv 0x006d00a0
void PathingLocationArray::ConstructItems(PathingLocation* items, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
        new (items + i) PathingLocation;
}

// Reads a PathingLocation from a load-game buffer: location, navmesh id, cell/worldspace, flags and optional mesh data.
// @fnv 0x006df010
void PathingLocation::LoadGame(BGSLoadGameBuffer* buffer)
{
    buffer->ReadDataBlock(&Location, 12);
    unsigned int navMeshID = 0;
    ((BGSLoadFormBuffer*)buffer)->ReadFormIdentifier(&navMeshID);
    m_pLocationNavMesh = g_TES->GetActiveCell(navMeshID)->FindReferenceByFormId();
    pCell = dynamic_cast<TESObjectCELL*>(TESForm::GetFormByID(buffer->ReadFormIdentifier()));
    m_pContainingWorldspace = dynamic_cast<TESWorldSpace*>(TESForm::GetFormByID(buffer->ReadFormIdentifier()));
    buffer->ReadDataBlock(&m_uiPathingFlags, 4);
    buffer->ReadDataBlock(&m_usTriangleID, 2);
    m_usTriangleID = kClearTriangleDataValue1;
    buffer->ReadDataBlock(&uiFlags, 1);
    bool hasMeshes = false;
    buffer->ReadDataBlock(&hasMeshes, 1);
    if (hasMeshes)
    {
        if (m_pContainingWorldspace)
            pNavMeshInfoArray = ForwardToPathing(m_pContainingWorldspace, m_uiPathingFlags);
        else if (pCell)
            pNavMeshInfoArray = Pathing_GetPotentialNavMeshInfoForLocation(pCell);
    }
}

// Checks whether the location is reachable via its nav mesh or mesh array, pruning invalid meshes and updating reachability state.
// @fnv 0x006de250
bool PathingLocation::HasPathingLocation()
{
    if (PathingLocation_QUnused())
        return false;
    if (!m_pLocationNavMesh && !pNavMeshInfoArray)
        return false;
    else if (m_pLocationNavMesh)
    {
        if (m_pLocationNavMesh->NavMeshInfo_GetDisabled())
            return false;
        else
            return true;
    }
    else
    {
        PathBuilderDetailedPathInfos meshes;
        ((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->CopyTo((BSSimpleArray<unsigned int, 1024>*)&meshes);
        for (unsigned int i = 0; i < ((BSSimpleArray<SandboxProcedureData, 1024>*)&meshes)->GetSize(); ++i)
        {
            struct
            {
                NavMeshBounds* bounds;
                NavMeshInfo* info;
            } meshEntry;
            meshEntry.info = (NavMeshInfo*)((NiFormArray*)&meshes)->FUN_00877a30(i);
            meshEntry.bounds = meshEntry.info->GetBounds();
            if (meshEntry.bounds)
            {
                if (meshEntry.bounds->ContainsPoint(Location))
                {
                    ((BSSimpleArray<unsigned short, 1024>*)&meshes)->Clear(false);
                    ((BSSimpleArray<NavMeshInfo*, 1024>*)&meshes)->Add(meshEntry.info);
                    break;
                }
                else
                {
                    ((BSSimpleArray<TESLoadScreen*, 1024>*)&meshes)->UpdateEntryValue(i, 1);
                    --i;
                }
            }
            else
            {
                NavMeshPtr mesh;
                if (meshEntry.info->ResolveNavMesh(mesh) && static_cast<const TESForm*>(mesh.Modelloader_GetReferencedThis())->IsDeleted())
                {
                    ((BSSimpleArray<TESLoadScreen*, 1024>*)&meshes)->UpdateEntryValue(i, 1);
                    --i;
                }
            }
        }
        if (((BSSimpleArray<SandboxProcedureData, 1024>*)&meshes)->GetSize() == 1)
        {
            m_pLocationNavMesh = meshes.GetFirstForm();
            pNavMeshInfoArray = 0;
            SetAllMeshesReachable(true);
            return true;
        }
        else
        {
            SetAllMeshesReachable(GetAllMeshesReachable());
            return IsPathingLocationFlagSet();
        }
    }
}

// @fnv 0x006dd6f0
bool PathingLocation::FindContainingTriangle(FindTriangleForLocationFilter* filter)
{
    if (PathingLocation_QUnused())
        return false;
    if (!m_pLocationNavMesh && !pNavMeshInfoArray)
        return false;
    else if (m_pLocationNavMesh)
    {
        if (m_pLocationNavMesh->NavMeshInfo_GetDisabled())
            return false;
        if (m_usTriangleID == 0xffff)
        {
            NavMeshPtr mesh;
            if (const_cast<NavMeshInfo*>(m_pLocationNavMesh)->ResolveNavMesh(mesh))
                m_usTriangleID =
                    mesh.Modelloader_GetReferencedThis()->FindTriangleForLocation(Location, filter);
        }
        return true;
    }
    else if (GetContainingCell() && GetContainingCell()->IsOutdoorCell())
    {
        for (unsigned int i = 0; i < ((BSSimpleArray<SandboxProcedureData, 1024>*)pNavMeshInfoArray)->GetSize(); ++i)
        {
            NavMeshPtr mesh;
            if (((NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(static_cast<int>(i)))
                    ->ResolveNavMesh(mesh) &&
                !mesh.Modelloader_GetReferencedThis()->GetDisabled())
            {
                unsigned short triangle =
                    mesh.Modelloader_GetReferencedThis()->FindTriangleForLocation(Location, filter);
                if (triangle != 0xffff)
                {
                    m_pLocationNavMesh =
                        (NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(static_cast<int>(i));
                    pNavMeshInfoArray = 0;
                    m_usTriangleID = triangle;
                    SetAllMeshesReachable(true);
                    return true;
                }
            }
        }
        NiPoint3 savedLocation = Location;
        bool resolved = IsPathingLocationValid();
        m_usTriangleID = kClearTriangleDataValue1;
        Location = savedLocation;
        if (resolved)
            SetAllMeshesReachable(true);
        else
            SetAllMeshesReachable(IsPathingLocationFlagSet());
        return resolved;
    }
    else
    {
        for (unsigned int i = 0; i < ((BSSimpleArray<SandboxProcedureData, 1024>*)pNavMeshInfoArray)->GetSize(); ++i)
        {
            const NavMeshInfo* info = (NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(static_cast<int>(i));
            if (!info->NavMeshInfo_GetDisabled())
            {
                NavMeshBounds* bounds = const_cast<NavMeshInfo*>(info)->GetBounds();
                if (bounds && bounds->ContainsPoint(Location))
                {
                    m_pLocationNavMesh =
                        (NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(static_cast<int>(i));
                    pNavMeshInfoArray = 0;
                    NavMeshPtr mesh;
                    if (const_cast<NavMeshInfo*>(m_pLocationNavMesh)->ResolveNavMesh(mesh))
                        m_usTriangleID = mesh.Modelloader_GetReferencedThis()
                                             ->FindTriangleForLocation(Location, filter);
                    SetAllMeshesReachable(true);
                    return true;
                }
            }
        }
        struct
        {
            int noBoundsIndex;
            float minimumDistance;
            int closestIndex;
        } nearest;
        nearest.noBoundsIndex = -1;
        nearest.minimumDistance = 3.402823466e+38F;
        nearest.closestIndex = -1;
        for (unsigned int i = 0; i < ((BSSimpleArray<SandboxProcedureData, 1024>*)pNavMeshInfoArray)->GetSize(); ++i)
        {
            const NavMeshInfo* info = (NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(static_cast<int>(i));
            if (!info->NavMeshInfo_GetDisabled())
            {
                NavMeshBounds* bounds = const_cast<NavMeshInfo*>(info)->GetBounds();
                if (bounds)
                {
                    NiPoint3 delta = bounds->DistanceFromPointToBounds(Location);
                    float distance = delta.FUN_004a7290();
                    if (distance < nearest.minimumDistance)
                    {
                        nearest.minimumDistance = distance;
                        nearest.closestIndex = i;
                    }
                }
                else
                    nearest.noBoundsIndex = i;
            }
        }
        if (nearest.minimumDistance < DAT_0106cd60)
        {
            m_pLocationNavMesh =
                (NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(nearest.closestIndex);
            pNavMeshInfoArray = 0;
            m_usTriangleID = kClearTriangleDataValue1;
            SetAllMeshesReachable(true);
            return true;
        }
        else
        {
            m_pLocationNavMesh =
                (NavMeshInfo*)((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->GetAt(nearest.noBoundsIndex);
            pNavMeshInfoArray = 0;
            SetAllMeshesReachable(GetAllMeshesReachable());
            return IsPathingLocationFlagSet();
        }
    }
}

// Clears bit 0 of the byte at offset 0x26 and sets it to the low bit of aiVal.
// @fnv 0x006dcfe0
void PathingLocation::SetAllMeshesReachable(int aiVal)
{
    uiFlags &= ~1;
    uiFlags |= aiVal;
}

// @fnv 0x006dd5a0
int __fastcall IsPathingLocationFlagSet(PathingLocation* pThis)
{
    return pThis->uiFlags & 1;
}

// @fnv 0x006df160
TESForm*& __fastcall GetFirstForm(NiFormArray* pThis)
{
    return pThis->FUN_00877a30(0);
}

// @fnv 0x006dcc40
PathingLocation::PathingLocation(const PathingLocation& other)
{
    Location = other.Location;
    m_pLocationNavMesh = other.m_pLocationNavMesh;
    pNavMeshInfoArray = other.pNavMeshInfoArray;
    pCell = other.pCell;
    m_pContainingWorldspace = other.m_pContainingWorldspace;
    m_uiPathingFlags = other.m_uiPathingFlags;
    m_usTriangleID = other.m_usTriangleID;
    uiFlags = other.uiFlags;
}

// @fnv 0x006dcf20
PathingLocation::PathingLocation(const NiPoint3& location, const NavMeshInfo* info)
{
    Location = location;
    uiFlags = 0;
    m_pLocationNavMesh = info;
    pNavMeshInfoArray = 0;
    m_pContainingWorldspace = const_cast<NavMeshInfo*>(info)->GetParentWorldSpace();
    if (m_pContainingWorldspace)
    {
        pCell = 0;
        m_uiPathingFlags = info->m_uiPathingFlags;
    }
    else
    {
        pCell = const_cast<NavMeshInfo*>(info)->GetInteriorCell();
        m_uiPathingFlags = 0xdeaddead;
    }
    SetAllMeshesReachable(1);
    m_usTriangleID = kClearTriangleDataValue1;
}

// @fnv 0x006dce60
PathingLocation::PathingLocation(NiPoint3 const& a, TESObjectCELL* b)
{
    SetLocationData(a, b, 0);
}

// @fnv 0x006dd4d0
void PathingLocation::SetTriangleIndex(unsigned short value)
{
    m_usTriangleID = value;
}

// Appends the navmesh info, or copies the navmesh info array, into the output array.
// @fnv 0x006dd5c0
bool PathingLocation::IsOnNavMesh(void* array)
{
    if (m_pLocationNavMesh)
    {
        static_cast<BSSimpleArray<void*, 1024>*>(array)->Add(reinterpret_cast<void*&>(const_cast<NavMeshInfo*&>(m_pLocationNavMesh)));
        return true;
    }
    else
    {
        if (((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray))
        {
            ((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->CopyTo((BSSimpleArray<unsigned int, 1024>*)static_cast<BSSimpleArray<void*, 1024>*>(array));
            return true;
        }
        else
        {
            return false;
        }
    }
}

// Initializes a pathing location from a point, using the hint location's navmesh triangle if found, otherwise setting up from the point and cell/worldspace.
// @fnv 0x006dd0d0
PathingLocation::PathingLocation(const NiPoint3& location, const PathingLocation& hint)
{
    Location = location;
    uiFlags = 0;
    m_usTriangleID = kClearTriangleDataValue1;
    NavMeshPtr pFoundNavMesh;
    if (const_cast<PathingLocation&>(hint).ResolveNavMesh(pFoundNavMesh))
    {
        m_usTriangleID =
            pFoundNavMesh.Modelloader_GetReferencedThis()->FindTriangleForLocation(location, 0);
        if (m_usTriangleID != kClearTriangleDataValue1)
        {
            m_pLocationNavMesh = hint.m_pLocationNavMesh;
            pNavMeshInfoArray = 0;
            pCell = hint.pCell;
            m_pContainingWorldspace = hint.m_pContainingWorldspace;
            m_uiPathingFlags = hint.m_uiPathingFlags;
            return;
        }
    }
    SetLocationData(location, const_cast<PathingLocation&>(hint).GetContainingCell(),
                          const_cast<PathingLocation&>(hint).GetParentWorldspace());
}

// @fnv 0x006dd3e0
void PathingLocation::SetNavMeshInfo(void* meshData)
{
    pNavMeshInfoArray = 0;
    m_pLocationNavMesh = static_cast<const NavMeshInfo*>(meshData);
    m_pContainingWorldspace = static_cast<NavMeshInfo*>(meshData)->GetParentWorldSpace();
    if (m_pContainingWorldspace)
    {
        pCell = 0;
        m_uiPathingFlags = static_cast<const NavMeshInfo*>(meshData)->m_uiPathingFlags;
    }
    else
    {
        pCell = static_cast<NavMeshInfo*>(meshData)->GetInteriorCell();
        m_uiPathingFlags = 0xdeaddead;
    }
    SetAllMeshesReachable(true);
    m_usTriangleID = 65535;
}

// @fnv 0x006dd460
void PathingLocation::SetLocationSimple(void* point)
{
    Location = (*static_cast<const NiPoint3*>(point));
    m_usTriangleID = 65535;
    if (m_pContainingWorldspace)
    {
        int key = TESWorldSpace::GetKeyForWorldCoord(Location);
        if (key != m_uiPathingFlags)
            SetLocationData((*static_cast<const NiPoint3*>(point)), 0, m_pContainingWorldspace);
    }
}

// @fnv 0x006def40
void PathingLocation::SaveGame(BGSSaveGameBuffer* gameBuffer)
{
    bool bhadNavMeshesArray;

    reinterpret_cast<BGSSaveFormBuffer*>(gameBuffer)->SaveData(&Location, 12, 0);
    reinterpret_cast<BGSSaveFormBuffer*>(gameBuffer)->FUN_00865db0(m_pLocationNavMesh ? const_cast<NavMeshInfo*>(m_pLocationNavMesh)->GetNavMeshID() : 0, 0);
    reinterpret_cast<BGSSaveFormBuffer*>(gameBuffer)->SerializeFormData(pCell, 0);
    reinterpret_cast<BGSSaveFormBuffer*>(gameBuffer)->SerializeFormData(m_pContainingWorldspace, 0);
    reinterpret_cast<BGSSaveFormBuffer*>(gameBuffer)->SaveData(&m_uiPathingFlags, 4, 0);
    reinterpret_cast<BGSSaveFormBuffer*>(gameBuffer)->SaveData(&m_usTriangleID, 2, 0);
    reinterpret_cast<BGSSaveFormBuffer*>(gameBuffer)->SaveData(&uiFlags, 1, 0);

    bhadNavMeshesArray = pNavMeshInfoArray;
    reinterpret_cast<BGSSaveFormBuffer*>(gameBuffer)->SaveData(&bhadNavMeshesArray, 1, 0);
}

unsigned int TESWorldSpace_GetKeyForWorldCoord(const NiPoint3&);
unsigned int PackShortPair(int, int);
const BSSimpleArray<const NavMeshInfo*, 1024>* ForwardToPathing(TESWorldSpace*, unsigned int);
const BSSimpleArray<const NavMeshInfo*, 1024>* Pathing_GetPotentialNavMeshInfoForLocation(TESObjectCELL*);

// Stores the position, resolves the nav-mesh array from the world or cell, marks all meshes reachable when exactly one mesh exists, and sets flags.
// @fnv 0x006dd280
void PathingLocation::SetLocationData(const NiPoint3& position, TESObjectCELL* cell, TESWorldSpace* world)
{
    Location = position;
    uiFlags = 0;
    if (world)
    {
        m_pContainingWorldspace = world;
        m_uiPathingFlags = TESWorldSpace_GetKeyForWorldCoord(Location);
        pCell = 0;
        pNavMeshInfoArray = ForwardToPathing(m_pContainingWorldspace, m_uiPathingFlags);
    }
    else
    {
        pNavMeshInfoArray = Pathing_GetPotentialNavMeshInfoForLocation(cell);
        if (cell && !cell->IsInterior())
        {
            m_pContainingWorldspace = cell->GetParentWorldSpace();
            m_uiPathingFlags = PackShortPair(cell->GetCellGridX(), cell->GetCellGridY());
            pCell = 0;
        }
        else
        {
            pCell = cell;
            m_pContainingWorldspace = 0;
            m_uiPathingFlags = 0xDEADDEAD;
        }
    }
    if (pNavMeshInfoArray && const_cast<BSSimpleArray<const NavMeshInfo*, 1024>*>(pNavMeshInfoArray)->GetSize() == 1)
    {
        SetAllMeshesReachable(true);
        m_pLocationNavMesh = reinterpret_cast<const NavMeshInfo*>(
            const_cast<BSSimpleArray<const NavMeshInfo*, 1024>*>(pNavMeshInfoArray)->GetAt(0));
        pNavMeshInfoArray = 0;
    }
    else
    {
        SetAllMeshesReachable(false);
        m_pLocationNavMesh = 0;
    }
    m_usTriangleID = 0xFFFF;
}

// @fnv 0x006deeb0
bool PathingLocation::IsCloseTo(void* otherLocation, float dist)
{
    if (static_cast<const PathingLocation*>(otherLocation)->m_pContainingWorldspace != m_pContainingWorldspace)
    {
        return false;
    }
    if (m_pContainingWorldspace != 0)
    {
        if (static_cast<const PathingLocation*>(otherLocation)->m_uiPathingFlags != m_uiPathingFlags)
        {
            return false;
        }
    }
    else
    {
        if (static_cast<const PathingLocation*>(otherLocation)->pCell != pCell)
        {
            return false;
        }
    }
    if (static_cast<const PathingLocation*>(otherLocation)->Location.Sub(Location).FUN_004a7290() > dist * dist)
    {
        return false;
    }
    return true;
}

struct PathingLocationOwner
{
    void PathSmoother_AddPathingNode_0(PathingLocation* location);
    void PathSmoother_AddPathingNode(const NiPoint3& position, TESObjectREFR* reference);
};
// Constructs a pathing location from a position and reference, then passes it to the owner's location setter.
// @fnv 0x006ed730
// src: COMMUNITY 0x006ed730
void PathingLocationOwner::PathSmoother_AddPathingNode(const NiPoint3& position, TESObjectREFR* reference)
{
    PathingLocation location(position, reinterpret_cast<const NavMeshInfo*>(reference));
    PathSmoother_AddPathingNode_0(&location);
}

struct FUN_006f4da0
{
    unsigned int flags;
    PathingLocation path;
    int context;
    FUN_006f4da0(int, int);
};

// Initialises the path from source, stores contextValue, sets flags to 6 and adds bit 1 when the path check for 0 succeeds.
// @fnv 0x006f4da0
FUN_006f4da0::FUN_006f4da0(int source, int contextValue) : path()
{
    path = *reinterpret_cast<const PathingLocation*>(source);
    context = contextValue;
    flags = 6;
    if (path.FUN_006dd6f0(0))
        flags |= 1;
}

struct MeshTriangle
{
    unsigned short v0;
    unsigned short v1;
    unsigned short v2;
};
class MeshTriangleArray
{
  public:
    unsigned int FUN_0044ddc0();                 // GetSize
    MeshTriangle* FUN_0069ccf0(unsigned int i);  // GetAt
};
class MeshVertexArray
{
  public:
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();                      // IsEmpty
    NiPoint3* Object_GetIndexedValue_006a1440(unsigned int i);  // GetAt
};
bool __cdecl NavMeshMath_IsPointInsideTriangle(const NiPoint3* pkA, const NiPoint3* pkB, const NiPoint3* pkC, const NiPoint3* pkPoint,
                          float* pfHeight, float fAbove, float fBelow);

class MeshBounds
{
  public:
    NiPoint3 m_kMin;           // +0x00
    NiPoint3 m_kMax;           // +0x0c
    MeshTriangleArray m_kTris;  // +0x18
    int unk1c[3];
    MeshVertexArray m_kVerts;  // +0x28

    bool ContainsPoint(const NiPoint3* pkPoint);
};

// @fnv 0x0069bea0
bool MeshBounds::ContainsPoint(const NiPoint3* pkPoint)
{
    if (pkPoint->x >= m_kMin.x && pkPoint->x <= m_kMax.x && pkPoint->y >= m_kMin.y && pkPoint->y <= m_kMax.y &&
        m_kMin.z - 180.0 <= pkPoint->z && m_kMax.z + 180.0 >= pkPoint->z)
    {
        if (!m_kVerts.NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
        {
            float m_fGlyphExtent = m_kMax.z - m_kMin.z;
            float fOut;
            for (unsigned int i = 0; i < m_kTris.FUN_0044ddc0(); i++)
            {
                NiPoint3 kA = *m_kVerts.Object_GetIndexedValue_006a1440(m_kTris.FUN_0069ccf0(i)->v0);
                NiPoint3 kB = *m_kVerts.Object_GetIndexedValue_006a1440(m_kTris.FUN_0069ccf0(i)->v1);
                NiPoint3 kC = *m_kVerts.Object_GetIndexedValue_006a1440(m_kTris.FUN_0069ccf0(i)->v2);
                if (NavMeshMath_IsPointInsideTriangle(&kA, &kB, &kC, pkPoint, &fOut, m_fGlyphExtent, m_fGlyphExtent))
                    return true;
            }
        }
        else
        {
            return true;
        }
    }
    return false;
}

extern const char DAT_0106cdec[];
extern const char DAT_0106cdd8[];
int __cdecl BSsprintf(char*, unsigned int, const char*, ...);
int __cdecl FUN_00406d50(char*, unsigned int, const char*);
int __cdecl BSstrcmp(const char*, const char*);

// NavMeshInfo parent-space accessor at 0x006b7770; the shared header has no declaration.
TESForm* __fastcall GetNavMeshParentSpace(NavMeshInfo*);
struct DebugMeshes
{
    unsigned int FUN_0044ddc0();
    NavMeshInfo*& BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
};

// Writes a formatted description of the location's cell, world, mesh or mesh list and coordinates into out up to capacity.
// @fnv 0x006de790
void PathingLocation::WriteDebugString(char* acBuffer, int capacity)
{
    if (!m_pLocationNavMesh || (((DebugMeshes*)pNavMeshInfoArray) && !((DebugMeshes*)pNavMeshInfoArray)->FUN_0044ddc0()))
    {
        if (!m_pContainingWorldspace)
        {
            BSsprintf(acBuffer, capacity, "Cell %s, %.2f %.2f %.2f", pCell ? pCell->GetName() : "NONE", Location.x,
                         Location.y, Location.z);
        }
        else
        {
            int cellX2 = (int)Location.x >> 12;
            int y8 = (int)Location.y >> 12;
            TESForm* found8 = m_pContainingWorldspace->GetCellFromWorldCoord(Location);
            if (found8)
                BSsprintf(acBuffer, capacity, "Cell %s[%d,%d] %s,  %.2f %.2f %.2f", m_pContainingWorldspace->GetName(), cellX2, y8,
                             found8->GetName(), Location.x, Location.y, Location.z);
            else
                BSsprintf(acBuffer, capacity, "Cell %s[%d,%d], %.2f %.2f %.2f", m_pContainingWorldspace->GetName(), cellX2, y8,
                             Location.x, Location.y, Location.z);
        }
    }
    else
    {
        char meshName2[256];
        if (m_pLocationNavMesh)
        {
            if (m_usTriangleID != 65535)
                BSsprintf(acBuffer, capacity, DAT_0106cdec, meshName2, m_usTriangleID, Location.x, Location.y, Location.z);
            else
                BSsprintf(acBuffer, capacity, DAT_0106cdd8, meshName2, Location.x, Location.y, Location.z);
        }
        else
        {
            char list7[256];
            BSsprintf(list7, capacity, "[");
            {
                unsigned int i3;
                for (i3 = 0; i3 < ((DebugMeshes*)pNavMeshInfoArray)->FUN_0044ddc0(); i3++)
                {
                    char entry2[64];
                    BSsprintf(entry2, 64, "%08x", ((DebugMeshes*)pNavMeshInfoArray)->BSSimpleArray_NiAVObject_1024_GetAt(i3)->GetNavMeshID());
                    FUN_00406d50(list7, 256, entry2);
                    if (i3 < ((DebugMeshes*)pNavMeshInfoArray)->FUN_0044ddc0() - 1)
                        FUN_00406d50(list7, 256, ", ");
                }
                FUN_00406d50(list7, 256, "]");
                TESWorldSpace* listWorld4 = ((DebugMeshes*)pNavMeshInfoArray)->BSSimpleArray_NiAVObject_1024_GetAt(0)->GetParentWorldSpace();
                TESForm* listCell3 = GetNavMeshParentSpace(((DebugMeshes*)pNavMeshInfoArray)->BSSimpleArray_NiAVObject_1024_GetAt(0));
                if (!listWorld4)
                {
                    BSsprintf(acBuffer, capacity, "%s Cell %s, %.2f %.2f %.2f", list7, listCell3->GetName(),
                                 Location.x, Location.y, Location.z);
                }
                else
                {
                    int gx = (int)Location.x >> 12;
                    int gy2 = (int)Location.y >> 12;
                    if (listCell3 && BSstrcmp(listCell3->GetName(), ""))
                        BSsprintf(acBuffer, capacity, "%s Cell %s[%d, %d](%s), %.2f %.2f %.2f", list7,
                                     listWorld4->GetName(), gx, gy2, listCell3->GetName(), Location.x, Location.y,
                                     Location.z);
                    else
                        BSsprintf(acBuffer, capacity, "%s Cell %s[%d, %d], %.2f %.2f %.2f", list7,
                                     listWorld4->GetName(), gx, gy2, Location.x, Location.y, Location.z);
                }
            }
        }
    }
}

bool __cdecl PathingLocationTestPoint(PathingLocation* pLoc, NiPoint3* pPoint, int a, int b);

extern double _gModifierZero;

// @fnv 0x006ded70
bool PathingLocation::IsDistanceBelowThreshold(float afRadius)
{
    FUN_006dd6f0(0);
    if (!FUN_006dd6a0())
        return false;
    if (afRadius <= _gModifierZero)
        return true;
    NiPoint3 kLoc4 = FUN_005c3420();
    NiPoint3 kMinX2 = kLoc4;
    kMinX2.x -= afRadius;
    if (!PathingLocationTestPoint(this, &kMinX2, 0, 0))
        return false;
    NiPoint3 kMaxX7 = kLoc4;
    kMaxX7.x += afRadius;
    if (!PathingLocationTestPoint(this, &kMaxX7, 0, 0))
        return false;
    NiPoint3 kMinY = kLoc4;
    kMinY.y -= afRadius;
    if (!PathingLocationTestPoint(this, &kMinY, 0, 0))
        return false;
    NiPoint3 kMaxY6 = kLoc4;
    kMaxY6.y += afRadius;
    if (!PathingLocationTestPoint(this, &kMaxY6, 0, 0))
        return false;
    return true;
}

class NodeArr_cls
{
  public:
    void* unk00;
    NavMeshInfo** pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int GetCount();
    NavMeshInfo*& GetAt(unsigned int index);
    int Find(NavMeshInfo** item, unsigned int start, int (*pred)());
};

class Owner_cls : public NodeArr_cls
{
  public:
    bool Check();
    NavMeshInfo** GetNodeRef(unsigned int index);
};

class Snap_cls : public NodeArr_cls
{
  public:
    Snap_cls();
    ~Snap_cls();
    void Add(NavMeshInfo** item);
};

int Actor_AreReferencedValuesEqual();

// @fnv 0x006de490
bool PathingLocation::GetAllMeshesReachable()
{
    Snap_cls list;
    NavMeshInfo* itemB;
    NavMeshInfo* fCur;
    NavMeshInfo* item2;
    unsigned int aJ;
    unsigned int b;
    unsigned int iG;
    unsigned int j6;
    unsigned int k;
    bool changed2;
    int unk2C;

    if (m_pLocationNavMesh != 0)
    {
        return true;
    }
    else
    {
        if (((Owner_cls*)pNavMeshInfoArray) != 0 && !((Owner_cls*)pNavMeshInfoArray)->Check())
        {
            list.Add(((Owner_cls*)pNavMeshInfoArray)->GetNodeRef(0));
            aJ = (*((Owner_cls*)pNavMeshInfoArray)->GetNodeRef(0))->m_kConnectedNavMeshInfos.GetSize();
            b = (*((Owner_cls*)pNavMeshInfoArray)->GetNodeRef(0))->m_kPreferredConnections.GetSize();
            for (iG = 0; iG < aJ + b; iG++)
            {
                if (iG < aJ)
                {
                    itemB = (*((Owner_cls*)pNavMeshInfoArray)->GetNodeRef(0))->m_kConnectedNavMeshInfos.GetAt(iG);
                }
                else
                {
                    itemB = (*((Owner_cls*)pNavMeshInfoArray)->GetNodeRef(0))->m_kPreferredConnections.GetAt(iG - aJ);
                }
                if (((Owner_cls*)pNavMeshInfoArray)->Find(&itemB, 0, Actor_AreReferencedValuesEqual) != -1)
                {
                    list.Add(&itemB);
                }
            }
            if (list.GetCount() == ((Owner_cls*)pNavMeshInfoArray)->GetCount())
            {
                return true;
            }
            do
            {
                changed2 = false;
                for (k = 1; k < list.GetCount(); k++)
                {
                    fCur = list.GetAt(k);
                    aJ = fCur->m_kConnectedNavMeshInfos.GetSize();
                    b = fCur->m_kPreferredConnections.GetSize();
                    for (j6 = 0; j6 < fCur->m_kConnectedNavMeshInfos.GetSize(); j6++)
                    {
                        if (j6 < aJ)
                        {
                            item2 = fCur->m_kConnectedNavMeshInfos.GetAt(j6);
                        }
                        else
                        {
                            item2 = fCur->m_kPreferredConnections.GetAt(j6 - aJ);
                        }
                        if (((Owner_cls*)pNavMeshInfoArray)->Find(&item2, 0, Actor_AreReferencedValuesEqual) != -1)
                        {
                            if (list.Find(&item2, 0, Actor_AreReferencedValuesEqual) == -1)
                            {
                                list.Add(&item2);
                                changed2 = true;
                            }
                        }
                    }
                }
            } while (changed2);
            if (list.GetCount() == ((Owner_cls*)pNavMeshInfoArray)->GetCount())
            {
                return true;
            }
        }
    }
    return false;
}

struct NavEdgeHit
{
    int m_iEdgeNumber;
    int unk04;
    NiPoint3 kPoint;
};

class NLMeshInfoArray
{
  public:
    unsigned int FUN_0044ddc0();                      // GetSize
    NavMeshInfo*& BSSimpleArray_NiAVObject_1024_GetAt(unsigned int uiIndex);  // GetAt
};

extern TES* DAT_011dea10;
extern const float DAT_01016970;  // FLT_MAX

// @fnv 0x006ddc00
bool PathingLocation::IsPathingLocationValid()
{
    SetLocationData(Location, pCell, m_pContainingWorldspace);
    if (!m_pLocationNavMesh && !pNavMeshInfoArray)
        return false;
    if (m_pLocationNavMesh && m_usTriangleID != kClearTriangleDataValue1)
        return true;

    if (m_pLocationNavMesh)
    {
        bool bInside = false;
        NavMeshPtr kMeshPtr;
        if (const_cast<NavMeshInfo*>(m_pLocationNavMesh)->ResolveNavMesh(kMeshPtr))
        {
            if (kMeshPtr.Modelloader_GetReferencedThis()->FindClosestTriangleForLocation(Location, &m_usTriangleID, &bInside))
            {
                if (!bInside)
                {
                    NiPoint3 kTriCenter = kMeshPtr.Modelloader_GetReferencedThis()->FUN_00558220(m_usTriangleID);
                    NavEdgeHit kResult = kMeshPtr.Modelloader_GetReferencedThis()
                                            ->FindEdgeIntersection(m_usTriangleID, -1, kTriCenter, Location);
                    if (kResult.m_iEdgeNumber)
                        Location = kResult.kPoint.ApplyScaled(0.9f).FUN_00439e90(kTriCenter.ApplyScaled(0.1f));
                }
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
    {
        float fNearest = DAT_01016970;
        int iClosest = -1;
        unsigned short usBestTri = kClearTriangleDataValue1;
        bool bValidFound = false;
        unsigned int uiNumMeshes = ((NLMeshInfoArray*)pNavMeshInfoArray)->FUN_0044ddc0();
        bool bClose = false;
        if (DAT_011dea10->GetCellHeightAtPosition(reinterpret_cast<NiPoint3*>(&Location), reinterpret_cast<int>(pCell)) + 25.0 > Location.z)
            bClose = true;
        for (unsigned int i = 0; i < uiNumMeshes; i++)
        {
            unsigned short usTri = kClearTriangleDataValue1;
            bool bInTri = false;
            NavMeshPtr pFoundNavMesh;
            NavMeshInfo* pInfo = ((NLMeshInfoArray*)pNavMeshInfoArray)->BSSimpleArray_NiAVObject_1024_GetAt(i);
            if (!pInfo->NavMeshInfo_GetDisabled() && pInfo->ResolveNavMesh(pFoundNavMesh) &&
                !pFoundNavMesh.Modelloader_GetReferencedThis()->FindClosestTriangleForLocation(Location, &usTri, &bInTri))
                continue;
            if (bInTri)
            {
                m_pLocationNavMesh = ((NLMeshInfoArray*)pNavMeshInfoArray)->BSSimpleArray_NiAVObject_1024_GetAt(i);
                pNavMeshInfoArray = 0;
                m_usTriangleID = usTri;
                return true;
            }
            else if (pFoundNavMesh.AnimatingText_GetFullText())
            {
                NiPoint3 kToCenter =
                    Location.SubtractIntoVector(pFoundNavMesh.Modelloader_GetReferencedThis()->FUN_00558220(usTri));
                float fDist = kToCenter.GetSquaredXYLength();
                float m_fGlyphExtent = kToCenter.z;
                bool bGood = false;
                if ((bClose || m_fGlyphExtent < 180.0) && m_fGlyphExtent > -64.0)
                    bGood = true;
                if (bValidFound)
                {
                    if (bGood && fDist < fNearest)
                    {
                        fNearest = fDist;
                        usBestTri = usTri;
                        iClosest = i;
                    }
                }
                else if (bGood)
                {
                    fNearest = fDist;
                    usBestTri = usTri;
                    iClosest = i;
                    bValidFound = true;
                }
                else if (fDist < fNearest)
                {
                    fNearest = fDist;
                    usBestTri = usTri;
                    iClosest = i;
                }
            }
        }
        if (iClosest != -1)
        {
            m_pLocationNavMesh = ((NLMeshInfoArray*)pNavMeshInfoArray)->BSSimpleArray_NiAVObject_1024_GetAt(iClosest);
            pNavMeshInfoArray = 0;
            m_usTriangleID = usBestTri;
            NavMeshPtr spBest;
            if (const_cast<NavMeshInfo*>(m_pLocationNavMesh)->ResolveNavMesh(spBest))
            {
                NiPoint3 kTriCenter = spBest.Modelloader_GetReferencedThis()->FUN_00558220(usBestTri);
                NavEdgeHit kResult = spBest.Modelloader_GetReferencedThis()
                                        ->FindEdgeIntersection(usBestTri, -1, kTriCenter, Location);
                if (kResult.m_iEdgeNumber)
                    Location = kTriCenter.ApplyScaled(0.1f).FUN_00439e90(kResult.kPoint.ApplyScaled(0.9f));
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
}

class PathingRequest;
class PathingSolution;

#include "../../../include/PathBuilder.h"

// Creates a PathBuilder from pRequest and m_pOutputSolution, calls BuildPath, and returns its result.
// @fnv 0x006d0b10
// src: XBOX_PDB 0x006d0b10
bool __cdecl Pathing_Pathfind(PathingRequest* pRequest, PathingSolution* m_pOutputSolution)
{
    PathBuilder kBuilder(pRequest, m_pOutputSolution);
    bool bResult = kBuilder.BuildPath();
    return bResult;
}
