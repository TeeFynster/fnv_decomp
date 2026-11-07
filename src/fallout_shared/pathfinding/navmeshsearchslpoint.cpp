#include "../../../include/BSScrapArray.h"
class NavMeshSearchNode;
class NavMeshSearchLink;
// RTTI 0x0106b88c/0x0106b8b4: 0x006ad1b0/0x006ad250 construct BSScrapArray<NavMeshSearchNode/NavMeshSearchLink,1024>, 0x14 bytes.

// src/fallout_shared/pathfinding/navmeshsearchslpoint.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshsearchslpoint.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/NavMeshSearch.h"
#include "../../../include/PathingRequest.h"
#include "../../../include/NiPoint3.h"

extern "C" void __cdecl Deallocate(void*);

struct FUN_006ac1b0_shell
{
    void __thiscall FUN_006ac1b0();
    void* __thiscall Destroy(unsigned int flags);
};

// Calls FUN_006ac1b0, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006ac180
void* __thiscall FUN_006ac1b0_shell::Destroy(unsigned int flags)
{
    FUN_006ac1b0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_006ac340_shell : NavMeshSearch
{
    PathingLocation pLocation;
    bool BuildPathingLocationAndSearch(PathingRequest* request, NavMeshTriangleReference const& start,
                                       NavMeshTriangleReference const& end,
                                       BSSimpleArray<NavMeshTriangleReference, 1024>* nodes,
                                       BSSimpleArray<NavMeshTriangleEdgeReference, 1024>* links);
};
// Copies the request's rotation and radius-derived values into pLocation and runs the navmesh search with the given start, end, nodes and links.
// @fnv 0x006ac340
bool FUN_006ac340_shell::BuildPathingLocationAndSearch(PathingRequest* request, NavMeshTriangleReference const& start,
                                                       NavMeshTriangleReference const& end,
                                                       BSSimpleArray<NavMeshTriangleReference, 1024>* nodes,
                                                       BSSimpleArray<NavMeshTriangleEdgeReference, 1024>* links)
{
    pLocation = *(PathingLocation const*)((char*)&request->GetRotate());
    *(float*)((char*)this + 0x20f8) = request->GetCenterRadius();
    *(float*)((char*)this + 0x20f4) = request->GetFieldB4Float() + request->GetCenterRadius();
    *(float*)((char*)this + 0x20f0) = request->GetFloatAtOffsetB0() + request->GetCenterRadius();
    *(float*)((char*)this + 0x20fc) = request->GetFloatAtOffset68();
    return ComputePath(request, start, end, nodes, links, 0);
}

#include "../../../include/BSSimpleArray.h"
struct FUN_006ac220_shell : NavMeshSearch
{
    PathingLocation pLocation;
    int unk20CC, unk20D0, unk20D4,
        unk20D8, unk20DC, unk20E0, unk20E4, unk20E8, unk20EC;
    float fUpperBound;
    float fLowerBound;
    float m_fCenterRadius;
    float fUnk20FC;
    bool SearchPath(PathingRequest* request, NavMeshTriangleReference const& start,
                    NavMeshTriangleReference const& end);
};

// Copies the request's location and radius bounds into the search object, then runs the path search between start and end using fresh node and link arrays.
// @fnv 0x006ac220
bool FUN_006ac220_shell::SearchPath(PathingRequest* request, NavMeshTriangleReference const& start,
                                    NavMeshTriangleReference const& end)
{
    pLocation = *request->NiAVObject_GetRotate_006a9540();
    m_fCenterRadius = request->GetCenterRadius();
    fLowerBound = request->GetFieldB4Float() + request->GetCenterRadius();
    fUpperBound = request->GetFloatAtOffsetB0() + request->GetCenterRadius();
    fUnk20FC = request->GetFloatAtOffset68();
    BSScrapArray<NavMeshSearchNode, 1024> nodes(0x20, 0, 0);
    BSScrapArray<NavMeshSearchLink, 1024> links(0x20, 0, 0);
    return ComputePath(request, start, end, reinterpret_cast<BSSimpleArray<NavMeshTriangleReference, 1024>*>(&nodes), reinterpret_cast<BSSimpleArray<NavMeshTriangleEdgeReference, 1024>*>(&links), 0);
}

struct Tri
{
    unsigned short Vertex(int);
};
struct Mesh
{
    void Center(unsigned short, NiPoint3*);
    Tri* Triangle(unsigned short);
    const NiPoint3& Vertex(unsigned short);
    void Vertices(unsigned short, const NiPoint3*&, const NiPoint3*&, const NiPoint3*&);
};
struct Loc
{
    NiPoint3 Location() const;
};
struct Ref
{
    Mesh* mesh;
    unsigned short triangle;
    NiPoint3 Center();
};
struct Node
{
    int unk00, unk04;
    Ref ref;
};
float ceilf(float);
struct Search : NavMeshSearch
{
    Loc location;
    int unk20a8, unk20ac, unk20b0, unk20b4, unk20b8, unk20bc, unk20c0, unk20c4, unk20c8;
    NiPoint3 result, direction, origin;
    float lower, upper, radius, step;
    bool Test(const NiPoint3&, const NiPoint3&, Mesh*, NiPoint3&);
    bool TestNode(Node*);
};
// Tests whether a node's mesh triangle intersects the search volume, sampling along the direction when the triangle is large enough, and stores the hit in result.
// @fnv 0x006ac3f0
bool Search::TestNode(Node* node)
{
    Mesh* mesh7 = node->ref.mesh;
    unsigned short triangle = node->ref.triangle;
    NiPoint3 position3 = location.Location();
    NiPoint3 delta = position3;
    NiPoint3 center5;
    mesh7->Center(triangle, &center5);
    delta -= center5;
    float distanceSquared3 = delta.GetSquaredXYLength();
    NiPoint3 vertex = mesh7->Vertex(mesh7->Triangle(triangle)->Vertex(0));
    vertex -= center5;
    float triangleRadius = vertex.Length();
    float outer5 = upper + triangleRadius;
    float outerSquared5 = outer5 * outer5;
    if (distanceSquared3 <= outerSquared5)
    {
        float inner = lower - triangleRadius;
        if (inner > 0.0 && distanceSquared3 < inner * inner)
            return false;
        NiPoint3 target = node->ref.Center();
        NiPoint3 hit_2;
        if (Test(target, position3, mesh7, hit_2))
        {
            result = hit_2;
            return true;
        }
        if (triangleRadius > step)
        {
            const NiPoint3* vertices5[3];
            mesh7->Vertices(triangle, vertices5[0], vertices5[1], vertices5[2]);
            NiPoint3 difference6 = *vertices5[0];
            difference6 -= position3;
            float minProjection3 = static_cast<const NiPoint3&>(difference6).Dot(direction);
            float maxProjection = minProjection3;
            for (int index = 1; index < 3; index++)
            {
                difference6 = *vertices5[index];
                difference6 -= position3;
                float projection = static_cast<const NiPoint3&>(difference6).Dot(direction);
                if (projection > minProjection3)
                    minProjection3 = projection;
                else if (projection < maxProjection)
                    maxProjection = projection;
            }
            NiPoint3 start2 = origin + direction * maxProjection;
            NiPoint3 end3 = origin + direction * minProjection3;
            NiPoint3 segment = end3;
            segment -= start2;
            float length4 = segment.FUN_00457910();  // 0x00457910: normalizes and returns the length
            float countFloat = length4 / step;
            float countRounded9 = ceilf(countFloat);
            int count0 = (int)countRounded9;
            float spacing2 = length4 / countRounded9;
            float offset8 = spacing2 * 0.5;
            NiPoint3 sampleX;
            for (int sampleIndex = 0; sampleIndex < count0; sampleIndex++)
            {
                sampleX = segment * offset8;
                sampleX += start2;
                if (Test(sampleX, position3, mesh7, hit_2))
                {
                    result = hit_2;
                    return true;
                }
                offset8 += spacing2;
            }
        }
    }
    return false;
}

struct FUN_006ac1b0_sub
{
    ~FUN_006ac1b0_sub();
};

struct FUN_006ac1b0_cls : NavMeshSearch
{
    FUN_006ac1b0_sub m_20a4;
    virtual ~FUN_006ac1b0_cls();
};

// The destructor body is empty.
// @fnv 0x006ac1b0
FUN_006ac1b0_cls::~FUN_006ac1b0_cls()
{}
