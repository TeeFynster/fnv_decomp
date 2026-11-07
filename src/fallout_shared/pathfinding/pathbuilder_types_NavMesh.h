// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NAVMESH_TYPES_H
#define FNV_NAVMESH_TYPES_H

#include "NiPoint3.h"
#include "NiRefObject.h"
#include "TESChildCell.h"
#include "TESForm.h"
#include "TESObjectREFR.h"
class EdgeExtraInfo;
class NavMeshClosedDoorInfo;
class NavMeshPOVData;
class NavMeshTriangleHandle;
class NavMeshStaticAvoidNode;
class NavMeshTriangle;
class NavMeshTriangleDoorPortal;
class NavMeshInfoTriangleReference;
class NavMeshVertex;
class NiTMap_unsigned_short_NiPointer_ObstacleData___;
class ObstacleUndoData;
class PathingAvoidNode;
#include "../../../include/EDGE_EXTRA_INFO_TYPE.h"
enum PathingAvoidNode__AVOID_NODE_TYPE
{
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_SPHERE = 0,
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_CYLINDER = 1,
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_SPHERE_ACTOR = 2
};
#pragma pack(push, 4)
class NavMeshVertex
{
  public:
    NiPoint3 Location;  // +0x0, 12 bytes
    // void __cdecl NavMeshVertex::*()
    // void __cdecl NavMeshVertex::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NavMeshVertex) == 12);
FNV_STATIC_ASSERT(offsetof(NavMeshVertex, Location) == 0);
#pragma pack(push, 4)
class NavMeshTriangle
{
  public:
    bool NavMeshTriangle_IsWater();
    bool IsNoLargeCreature();
    bool FUN_00691140(unsigned int);
    unsigned short Vertices[3];      // +0x0, 6 bytes
    unsigned short Triangles[3];     // +0x6, 6 bytes
    unsigned int m_uiTriangleFlags;  // +0xC, 4 bytes
    // void __cdecl NavMeshTriangle::*()
    // bool __cdecl NavMeshTriangle::*()
    // bool __cdecl NavMeshTriangle::*()
    // void __cdecl NavMeshTriangle::*()
    // bool __cdecl NavMeshTriangle::*()
    // void __cdecl NavMeshTriangle::*()
    // bool __cdecl NavMeshTriangle::*()
    // void __cdecl NavMeshTriangle::*()
    // void __cdecl NavMeshTriangle::*(unsigned short&, unsigned short&, unsigned short&)
    // void __cdecl NavMeshTriangle::*(unsigned short&, unsigned short&, unsigned short&)
    // void __cdecl NavMeshTriangle::*(unsigned short, unsigned short, unsigned short)
    // void __cdecl NavMeshTriangle::*(unsigned short, unsigned short, unsigned short)
    // bool __cdecl NavMeshTriangle::*(int)
    // void __cdecl NavMeshTriangle::*(int)
    // void __cdecl NavMeshTriangle::*(int)
    // unsigned int __cdecl NavMeshTriangle::*()
    // void __cdecl NavMeshTriangle::*(unsigned int)
    // unsigned short __cdecl NavMeshTriangle::*(unsigned int)
    // void __cdecl NavMeshTriangle::*(unsigned int, unsigned short)
    // unsigned short __cdecl NavMeshTriangle::*(unsigned int)
    // void __cdecl NavMeshTriangle::*(unsigned int, unsigned short)
    // bool __cdecl NavMeshTriangle::*(int)
    // unsigned short __cdecl NavMeshTriangle::*(int)
    // void __cdecl NavMeshTriangle::*(int, unsigned short)
    // void __cdecl NavMeshTriangle::*(int)
    // bool __cdecl NavMeshTriangle::*()
    // bool __cdecl NavMeshTriangle::*(int)
    // unsigned short __cdecl NavMeshTriangle::*(int)
    // void __cdecl NavMeshTriangle::*(int, unsigned short)
    // unsigned short __cdecl NavMeshTriangle::*()
    // void __cdecl NavMeshTriangle::*(unsigned short)
    // void __cdecl NavMeshTriangle::*()
    // HasCover
    // bool __cdecl NavMeshTriangle::*()
    // bool __cdecl NavMeshTriangle::*()
    // HasCoverOrWallFlags
    // bool __cdecl NavMeshTriangle::*()
    // bool __cdecl NavMeshTriangle::*()
    // bool __cdecl NavMeshTriangle::*(unsigned short)
    // bool __cdecl NavMeshTriangle::*(unsigned short)
    // unsigned short __cdecl NavMeshTriangle::*(unsigned short)
    // bool __cdecl NavMeshTriangle::*(unsigned short, bool&, bool&)
    // GetEdgeCoverData
    // void __cdecl NavMeshTriangle::*()
    // SetEdgeCover
    // int __cdecl NavMeshTriangle::*(int)
    // bool __cdecl NavMeshTriangle::*()
    // unsigned int __cdecl NavMeshTriangle::*(float, bool, bool)
    // float __cdecl NavMeshTriangle::*(unsigned int)
    // void __cdecl NavMeshTriangle::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NavMeshTriangle) == 16);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangle, Vertices) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangle, Triangles) == 6);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangle, m_uiTriangleFlags) == 12);
#pragma pack(push, 4)
class NavMeshInfoTriangleReference
{
  public:
    NavMeshInfo* m_pNavMeshInfo;            // +0x0, 4 bytes
    unsigned short m_usTriangleIdentifier;  // +0x4, 2 bytes
    unsigned char layoutPadding6[2];
    // NavMeshInfoTriangleReference
    // int __cdecl NavMeshInfoTriangleReference::*()
    // void __cdecl NavMeshInfoTriangleReference::*(char*)
    // void __cdecl NavMeshInfoTriangleReference::*(TESForm*, TESFile*, char*)
    // void __cdecl NavMeshInfoTriangleReference::*()
    // bool __cdecl NavMeshInfoTriangleReference::*()
    // NavMeshInfoTriangleReference& __cdecl NavMeshInfoTriangleReference::*(const NavMeshInfoTriangleReference&)
    // bool __cdecl NavMeshInfoTriangleReference::*(const NavMeshInfoTriangleReference&)
    // bool __cdecl NavMeshInfoTriangleReference::*(const NavMeshInfoTriangleReference&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NavMeshInfoTriangleReference) == 8);
FNV_STATIC_ASSERT(offsetof(NavMeshInfoTriangleReference, m_pNavMeshInfo) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshInfoTriangleReference, m_usTriangleIdentifier) == 4);
#pragma pack(push, 4)
class EdgeExtraInfo
{
  public:
    EDGE_EXTRA_INFO_TYPE eType;           // +0x0, 4 bytes
    NavMeshInfoTriangleReference Portal;  // +0x4, 8 bytes
    // EdgeExtraInfo
    // EdgeExtraInfo& __cdecl EdgeExtraInfo::*(const EdgeExtraInfo&)
    // void __cdecl EdgeExtraInfo::*()
    // int __cdecl EdgeExtraInfo::*()
    // int __cdecl EdgeExtraInfo::*()
    // void __cdecl EdgeExtraInfo::*(char*)
    // void __cdecl EdgeExtraInfo::*(TESFile*, char*)
    // void __cdecl EdgeExtraInfo::*(TESFile*, char*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(EdgeExtraInfo) == 12);
FNV_STATIC_ASSERT(offsetof(EdgeExtraInfo, eType) == 0);
FNV_STATIC_ASSERT(offsetof(EdgeExtraInfo, Portal) == 4);
#pragma pack(push, 4)
class NavMeshTriangleDoorPortal
{
  public:
    TESObjectREFR* NavMeshDoorPortalData;  // +0x0, 4 bytes
    unsigned short m_usDoorPortalIndex;    // +0x4, 2 bytes
    unsigned char layoutPadding6[2];
    // NavMeshTriangleDoorPortal
    // void __cdecl NavMeshTriangleDoorPortal::*()
    // void __cdecl NavMeshTriangleDoorPortal::*()
    // bool __cdecl NavMeshTriangleDoorPortal::*()
    // NavMeshTriangleDoorPortal& __cdecl NavMeshTriangleDoorPortal::*(const NavMeshTriangleDoorPortal&)
    // bool __cdecl NavMeshTriangleDoorPortal::*(const NavMeshTriangleDoorPortal&)
    // bool __cdecl NavMeshTriangleDoorPortal::*(const NavMeshTriangleDoorPortal&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NavMeshTriangleDoorPortal) == 8);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleDoorPortal, NavMeshDoorPortalData) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleDoorPortal, m_usDoorPortalIndex) == 4);
#pragma pack(push, 4)
class NavMeshClosedDoorInfo
{
  public:
    unsigned int m_uiDoorFormID;           // +0x0, 4 bytes
    unsigned short m_usDoorTriangleIndex;  // +0x4, 2 bytes
    unsigned char layoutPadding6[2];
    // NavMeshClosedDoorInfo
    // NavMeshClosedDoorInfo& __cdecl NavMeshClosedDoorInfo::*(const NavMeshClosedDoorInfo&)
    // bool __cdecl NavMeshClosedDoorInfo::*(const NavMeshClosedDoorInfo&)
    // bool __cdecl NavMeshClosedDoorInfo::*(const NavMeshClosedDoorInfo&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NavMeshClosedDoorInfo) == 8);
FNV_STATIC_ASSERT(offsetof(NavMeshClosedDoorInfo, m_uiDoorFormID) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshClosedDoorInfo, m_usDoorTriangleIndex) == 4);
#pragma pack(push, 4)
class NavMeshTriangleHandle
{
  public:
    unsigned short m_usIndex;  // +0x0, 2 bytes
    // unsigned short __cdecl NavMeshTriangleHandle::*()
    // int __cdecl NavMeshTriangleHandle::*()
    // Set
    // void __cdecl NavMeshTriangleHandle::*(unsigned short)
    // void __cdecl NavMeshTriangleHandle::*(unsigned short)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NavMeshTriangleHandle) == 2);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleHandle, m_usIndex) == 0);
#pragma pack(push, 4)
class NavMeshPOVData
{
  public:
    NavMeshTriangleHandle m_kFirstEdge;   // +0x0, 2 bytes
    NavMeshTriangleHandle m_kSecondEdge;  // +0x2, 2 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NavMeshPOVData) == 4);
FNV_STATIC_ASSERT(offsetof(NavMeshPOVData, m_kFirstEdge) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshPOVData, m_kSecondEdge) == 2);
#pragma pack(push, 4)
class PathingAvoidNode
{
  public:
    NavMeshTriangle* GetAvoidanceAtPoint(unsigned short);
    NiPoint3 m_kLocation;                          // +0x0, 12 bytes
    NiPoint3 TwoComponentVector;              // +0xC, 12 bytes
    float fRadius;                            // +0x18, 4 bytes
    float m_fPathingCostCur;                              // +0x1C, 4 bytes
    PathingAvoidNode__AVOID_NODE_TYPE eType;  // +0x20, 4 bytes
    // PathingAvoidNode
    // float __cdecl PathingAvoidNode::*(NiPoint3&)
    // PathingAvoidNode::AVOID_NODE_TYPE __cdecl PathingAvoidNode::*()
    // const NiPoint3& __cdecl PathingAvoidNode::*()
    // const NiPoint3& __cdecl PathingAvoidNode::*()
    // float __cdecl PathingAvoidNode::*()
    // float __cdecl PathingAvoidNode::*()
    // void __cdecl PathingAvoidNode::*(BGSSaveFormBuffer*)
    // void __cdecl PathingAvoidNode::*(BGSLoadFormBuffer*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingAvoidNode) == 36);
FNV_STATIC_ASSERT(offsetof(PathingAvoidNode, m_kLocation) == 0);
FNV_STATIC_ASSERT(offsetof(PathingAvoidNode, TwoComponentVector) == 12);
FNV_STATIC_ASSERT(offsetof(PathingAvoidNode, fRadius) == 24);
FNV_STATIC_ASSERT(offsetof(PathingAvoidNode, m_fPathingCostCur) == 28);
FNV_STATIC_ASSERT(offsetof(PathingAvoidNode, eType) == 32);
#pragma pack(push, 4)
class NavMeshStaticAvoidNode : public PathingAvoidNode
{
  public:
    // base PathingAvoidNode at +0x0, size 36
    unsigned short m_usTriangleID;  // +0x24, 2 bytes
    unsigned char layoutPadding26[2];
    // NavMeshStaticAvoidNode
    // unsigned short __cdecl NavMeshStaticAvoidNode::*()
    // void __cdecl NavMeshStaticAvoidNode::*(float)
    // void __cdecl NavMeshStaticAvoidNode::*(float)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NavMeshStaticAvoidNode) == 40);
FNV_STATIC_ASSERT(offsetof(NavMeshStaticAvoidNode, m_usTriangleID) == 36);
#endif
