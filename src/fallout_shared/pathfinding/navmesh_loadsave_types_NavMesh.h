// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NAVMESH_TYPES_H
#define FNV_NAVMESH_TYPES_H

#include "navmesh_loadsave_layout_support.h"
#include "navmesh_loadsave_NiPoint3.h"
#include "navmesh_loadsave_NiRefObject.h"
#include "navmesh_loadsave_TESChildCell.h"
#include "navmesh_loadsave_TESForm.h"
#include "navmesh_loadsave_TESObjectREFR.h"
#include "navmesh_loadsave_layout_support.h"
class DFALL_NiTMapItem_unsigned_short_NavMeshPOVData___;
class EdgeExtraInfo;
class NavMesh;
class NavMeshClosedDoorInfo;
class NavMeshGrid;
class NavMeshPOVData;
class NavMeshTriangleHandle;
class NavMeshStaticAvoidNode;
class NavMeshTriangle;
class NavMeshTriangleDoorPortal;
class NavMeshInfoTriangleReference;
class NavMeshVertex;
class NiTMap_unsigned_short_NavMeshPOVData_;
class NiTMap_unsigned_short_NiPointer_ObstacleData___;
class NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData____unsigned_short_NavMeshPOVData_;
class NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData____unsigned_short_NavMeshPOVData___AntiBloatAllocator;
class ObstacleUndoData;
class PathingAvoidNode;
#include "../../../include/EDGE_EXTRA_INFO_TYPE.h"
enum PathingAvoidNode__AVOID_NODE_TYPE
{
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_SPHERE = 0,
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_CYLINDER = 1,
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_SPHERE_ACTOR = 2
};
class NavMeshVertex
{
  public:
    NiPoint3 Location;  // +0x0, 12 bytes
    // void __cdecl NavMeshVertex::*()
    // void __cdecl NavMeshVertex::*()
};
FNV_STATIC_ASSERT(sizeof(NavMeshVertex) == 12);
FNV_STATIC_ASSERT(offsetof(NavMeshVertex, Location) == 0);
class NavMeshTriangle
{
  public:
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
FNV_STATIC_ASSERT(sizeof(NavMeshTriangle) == 16);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangle, Vertices) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangle, Triangles) == 6);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangle, m_uiTriangleFlags) == 12);
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
FNV_STATIC_ASSERT(sizeof(NavMeshInfoTriangleReference) == 8);
FNV_STATIC_ASSERT(offsetof(NavMeshInfoTriangleReference, m_pNavMeshInfo) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshInfoTriangleReference, m_usTriangleIdentifier) == 4);
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
FNV_STATIC_ASSERT(sizeof(EdgeExtraInfo) == 12);
FNV_STATIC_ASSERT(offsetof(EdgeExtraInfo, eType) == 0);
FNV_STATIC_ASSERT(offsetof(EdgeExtraInfo, Portal) == 4);
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
FNV_STATIC_ASSERT(sizeof(NavMeshTriangleDoorPortal) == 8);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleDoorPortal, NavMeshDoorPortalData) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleDoorPortal, m_usDoorPortalIndex) == 4);
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
FNV_STATIC_ASSERT(sizeof(NavMeshClosedDoorInfo) == 8);
FNV_STATIC_ASSERT(offsetof(NavMeshClosedDoorInfo, m_uiDoorFormID) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshClosedDoorInfo, m_usDoorTriangleIndex) == 4);
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
FNV_STATIC_ASSERT(sizeof(NavMeshTriangleHandle) == 2);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleHandle, m_usIndex) == 0);
class NavMeshPOVData
{
  public:
    NavMeshTriangleHandle m_kFirstEdge;   // +0x0, 2 bytes
    NavMeshTriangleHandle m_kSecondEdge;  // +0x2, 2 bytes
};
FNV_STATIC_ASSERT(sizeof(NavMeshPOVData) == 4);
FNV_STATIC_ASSERT(offsetof(NavMeshPOVData, m_kFirstEdge) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshPOVData, m_kSecondEdge) == 2);
class DFALL_NiTMapItem_unsigned_short_NavMeshPOVData___
{
  public:
    // void* __cdecl DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >::*()
    // void __cdecl DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >::*(void*)
};
FNV_STATIC_ASSERT(sizeof(DFALL_NiTMapItem_unsigned_short_NavMeshPOVData___) == 1);
class NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData____unsigned_short_NavMeshPOVData___AntiBloatAllocator
    : public DFALL_NiTMapItem_unsigned_short_NavMeshPOVData___
{
  public:
    // base DFALL<NiTMapItem<unsigned short,NavMeshPOVData> > at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
FNV_STATIC_ASSERT(
    sizeof(
        NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData____unsigned_short_NavMeshPOVData___AntiBloatAllocator) ==
    4);
FNV_STATIC_ASSERT(
    offsetof(
        NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData____unsigned_short_NavMeshPOVData___AntiBloatAllocator,
        m_uiCount) == 0);
class NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData____unsigned_short_NavMeshPOVData_
{
  public:
    void** m_ppVirtualMethodTable;                                              // +0x0, 4 bytes
    unsigned int m_uiHashSize;                                    // +0x4, 4 bytes
    NiTMapItem<unsigned short, NavMeshPOVData>** m_ppkHashTable;  // +0x8, 4 bytes
    NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData____unsigned_short_NavMeshPOVData___AntiBloatAllocator
        m_kItemCount;  // +0xC, 4 bytes
    // NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>
    // unsigned int __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>::*(unsigned short, NavMeshPOVData)
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>::*(unsigned short)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>::*(unsigned short, NavMeshPOVData&)
    // void* __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>::*(void*&, unsigned short&, NavMeshPOVData&)
    // NiTMapItem<unsigned short,NavMeshPOVData>* __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>::*(unsigned short)
    // NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>& __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>::*(const NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>&)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData>::*()
};
FNV_STATIC_ASSERT(sizeof(NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData____unsigned_short_NavMeshPOVData_) ==
                  16);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData____unsigned_short_NavMeshPOVData_,
                           m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData____unsigned_short_NavMeshPOVData_,
                           m_uiHashSize) == 4);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData____unsigned_short_NavMeshPOVData_,
                           m_ppkHashTable) == 8);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData____unsigned_short_NavMeshPOVData_,
                           m_kItemCount) == 12);
class NiTMap_unsigned_short_NavMeshPOVData_
    : public NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData____unsigned_short_NavMeshPOVData_
{
  public:
    // base NiTMapBase<DFALL<NiTMapItem<unsigned short,NavMeshPOVData> >,unsigned short,NavMeshPOVData> at +0x0, size 16
    // NiTMap<unsigned short,NavMeshPOVData>
    // void __cdecl NiTMap<unsigned short,NavMeshPOVData>::*()
    // NiTMapItem<unsigned short,NavMeshPOVData>* __cdecl NiTMap<unsigned short,NavMeshPOVData>::*()
    // void __cdecl NiTMap<unsigned short,NavMeshPOVData>::*(NiTMapItem<unsigned short,NavMeshPOVData>*)
    // NiTMap<unsigned short,NavMeshPOVData>& __cdecl NiTMap<unsigned short,NavMeshPOVData>::*(const NiTMap<unsigned short,NavMeshPOVData>&)
    // void __cdecl NiTMap<unsigned short,NavMeshPOVData>::*()
    // void __cdecl NiTMap<unsigned short,NavMeshPOVData>::*()
};
FNV_STATIC_ASSERT(sizeof(NiTMap_unsigned_short_NavMeshPOVData_) == 16);
class NavMeshGrid
{
  public:
    void CopyTo_0069dd50(NavMeshGrid*);
    unsigned int m_uiGridIndex;                                // +0x0, 4 bytes
    float m_fFirstGridValue;                                   // +0x4, 4 bytes
    float NavMeshPointEntry;                                   // +0x8, 4 bytes
    NiPoint3 IndexedPointRecord;                               // +0xC, 12 bytes
    NiPoint3 IndexedPointData;                                 // +0x18, 12 bytes
    BSSimpleArray<unsigned short, 1024>* TESFileRecordLoader;  // +0x24, 4 bytes
    // void __cdecl NavMeshGrid::*()
    // void __cdecl NavMeshGrid::*()
    // bool __cdecl NavMeshGrid::*()
    // void __cdecl NavMeshGrid::*(const NiPoint3&, unsigned int*, unsigned int*)
    // unsigned int __cdecl NavMeshGrid::*(const NiPoint3&)
    // void __cdecl NavMeshGrid::*(const NiPoint3&, const BSSimpleArray<unsigned short,1024>*&)
    // void __cdecl NavMeshGrid::*(const NiPoint3&, const NiPoint3&, BSSimpleArray<unsigned short,1024>*)
    // void __cdecl NavMeshGrid::*(const NiPoint3&, BSSimpleArray<BSSimpleArray<unsigned short,1024> const *,1024>*)
    // GetTriangleArray
    // IsTriangleInGridCell
    // void __cdecl NavMeshGrid::*(NiPoint3&, NiPoint3&)
    // unsigned int __cdecl NavMeshGrid::*()
    // NiPoint3 __cdecl NavMeshGrid::*(unsigned int, unsigned int)
    // void __cdecl NavMeshGrid::*(unsigned short, unsigned int, unsigned int)
    // void __cdecl NavMeshGrid::*(const NiPoint3&, const NiPoint3&, unsigned int)
    // unsigned int __cdecl NavMeshGrid::*()
    // void __cdecl NavMeshGrid::*(char*, unsigned int)
    // bool __cdecl NavMeshGrid::*(const char*, unsigned int, TESFile*)
    // void __cdecl NavMeshGrid::*(NavMeshGrid*)
};
FNV_STATIC_ASSERT(sizeof(NavMeshGrid) == 40);
FNV_STATIC_ASSERT(offsetof(NavMeshGrid, m_uiGridIndex) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshGrid, m_fFirstGridValue) == 4);
FNV_STATIC_ASSERT(offsetof(NavMeshGrid, NavMeshPointEntry) == 8);
FNV_STATIC_ASSERT(offsetof(NavMeshGrid, IndexedPointRecord) == 12);
FNV_STATIC_ASSERT(offsetof(NavMeshGrid, IndexedPointData) == 24);
FNV_STATIC_ASSERT(offsetof(NavMeshGrid, TESFileRecordLoader) == 36);
class PathingAvoidNode
{
  public:
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
FNV_STATIC_ASSERT(sizeof(PathingAvoidNode) == 36);
FNV_STATIC_ASSERT(offsetof(PathingAvoidNode, m_kLocation) == 0);
FNV_STATIC_ASSERT(offsetof(PathingAvoidNode, TwoComponentVector) == 12);
FNV_STATIC_ASSERT(offsetof(PathingAvoidNode, fRadius) == 24);
FNV_STATIC_ASSERT(offsetof(PathingAvoidNode, m_fPathingCostCur) == 28);
FNV_STATIC_ASSERT(offsetof(PathingAvoidNode, eType) == 32);
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
FNV_STATIC_ASSERT(sizeof(NavMeshStaticAvoidNode) == 40);
FNV_STATIC_ASSERT(offsetof(NavMeshStaticAvoidNode, m_usTriangleID) == 36);
class NavMesh : public TESForm, public TESChildCell, public NiRefObject
{
  public:
    void ForceSetFormID(unsigned int formID);
    void InitItem();
    void CopyNavMeshDataTo(class NavMeshPtr&);
    const NavMeshInfo* GetNavMeshInfo_0068efb0();
    void SetDeletionState(bool);
    void InitializeNavMeshData();
    // base TESForm at +0x0, size 24
    // base TESChildCell at +0x18, size 4
    // base NiRefObject at +0x1C, size 8
    TESObjectCELL* m_pOwningCell;                                               // +0x24, 4 bytes
    BSSimpleArray<NavMeshVertex, 1024> Vertices;                              // +0x28, 16 bytes
    BSSimpleArray<NavMeshTriangle, 1024> Triangles;                           // +0x38, 16 bytes
    BSSimpleArray<EdgeExtraInfo, 1024> m_kEdgeExtraInfo;                      // +0x48, 16 bytes
    BSSimpleArray<NavMeshTriangleDoorPortal, 1024> m_kDoorPortals;            // +0x58, 16 bytes
    BSSimpleArray<NavMeshClosedDoorInfo, 1024> m_kClosedDoorInfo;             // +0x68, 16 bytes
    BSSimpleArray<unsigned short, 1024> m_kIndexList;                         // +0x78, 16 bytes
    NiTMap_unsigned_short_NavMeshPOVData_ POVPointerArray;                    // +0x88, 16 bytes
    BSSimpleArray<unsigned short, 1024> m_kAdditionalIndexList;               // +0x98, 16 bytes
    NavMeshGrid m_kGrid;                                                      // +0xA8, 40 bytes
    BSSimpleArray<NiPointer<ObstacleUndoData>, 1024> m_kObstacleUndoData;     // +0xD0, 16 bytes
    NiTMap_unsigned_short_NiPointer_ObstacleData___* pTriangleToObstacleMap;  // +0xE0, 4 bytes
    BSSimpleArray<unsigned short, 1024> m_kAdditionalData;                    // +0xE4, 16 bytes
    BSSimpleArray<NavMeshStaticAvoidNode, 1024> m_kStaticAvoidNodes;          // +0xF4, 16 bytes
    NavMeshInfo* m_pNavigationMesh;                                           // +0x104, 4 bytes
    // NavMesh
    // void __cdecl NavMesh::*()
    // TESObjectCELL* __cdecl NavMesh::*()
    // void __cdecl NavMesh::*(TESObjectCELL*)
    // TESObjectCELL* __cdecl NavMesh::*()
    // TESForm* __cdecl NavMesh::*()
    // NavMeshInfo* __cdecl NavMesh::*()
    // void __cdecl NavMesh::*(NavMeshInfo*)
    // void __cdecl NavMesh::*(bool)
    // bool __cdecl NavMesh::*(bool)
    // bool __cdecl NavMesh::*(NavMesh*, NavMesh*, bool, float, float)
    // bool __cdecl NavMesh::*()
    // unsigned int __cdecl NavMesh::*()
    // unsigned int __cdecl NavMesh::*()
    // unsigned int __cdecl NavMesh::*()
    // unsigned int __cdecl NavMesh::*()
    // GetVertex
    // GetTriangle
    // EdgeExtraInfo* __cdecl NavMesh::*(unsigned short)
    // EdgeExtraInfo* __cdecl NavMesh::*(unsigned short, int)
    // void __cdecl NavMesh::*(unsigned short)
    // void __cdecl NavMesh::*(unsigned short)
    // void __cdecl NavMesh::*(unsigned short)
    // DeleteDoorPortalFromTriangle
    // void __cdecl NavMesh::*(unsigned int)
    // unsigned short __cdecl NavMesh::*(const NavMeshVertex&)
    // unsigned short __cdecl NavMesh::*(const NavMeshTriangle&)
    // unsigned short __cdecl NavMesh::*(const EdgeExtraInfo&)
    // unsigned int __cdecl NavMesh::*(const NavMeshTriangleDoorPortal&)
    // void __cdecl NavMesh::*(unsigned short, unsigned short, unsigned short, bool, bool)
    // unsigned short __cdecl NavMesh::*(unsigned short, unsigned short, bool&, bool&)
    // const BSSimpleArray<unsigned short,1024>* __cdecl NavMesh::*()
    // void __cdecl NavMesh::*()
    // void __cdecl NavMesh::*()
    // void __cdecl NavMesh::*()
    // GetTriangleVertices
    // GetMatchingTri
    // NavMeshInfoTriangleReference* __cdecl NavMesh::*(unsigned short, int)
    // NavMeshTriangleDoorPortal* __cdecl NavMesh::*(unsigned short)
    // NavMeshTriangleDoorPortal* __cdecl NavMesh::*(unsigned short)
    // int __cdecl NavMesh::*(unsigned short)
    // bool __cdecl NavMesh::*()
    // bool __cdecl NavMesh::*(TESFile*)
    // void __cdecl NavMesh::*()
    // void __cdecl NavMesh::*(bool)
    // void __cdecl NavMesh::*(bool)
    // bool __cdecl NavMesh::*()
    // void __cdecl NavMesh::*()
    // void __cdecl NavMesh::*(BSStringT<char>&)
    // void __cdecl NavMesh::*(BGSLoadFormBuffer*)
    // void __cdecl NavMesh::*(unsigned int)
    // void __cdecl NavMesh::*(NavMeshPtr&)
    // bool __cdecl NavMesh::*(unsigned int, bool)
    // unsigned short __cdecl NavMesh::*(unsigned short, unsigned short, unsigned short)
    // bool __cdecl NavMesh::*(const NavMeshInfo*, BSSimpleArray<int,1024>*)
    // void __cdecl NavMesh::*()
    // void __cdecl NavMesh::*()
    // void __cdecl NavMesh::*(unsigned short)
    // void __cdecl NavMesh::*()
    // void __cdecl NavMesh::*(NavMeshPtr&, bool)
    // void __cdecl NavMesh::*(const BSSimpleArray<unsigned short,1024>*, NavMeshPtr&)
    // void __cdecl NavMesh::*(BSSimpleArray<NavMeshPtr,1024>*)
    // void __cdecl NavMesh::*(unsigned short, BSSimpleArray<unsigned short,1024>*)
    // void __cdecl NavMesh::*(const BSSimpleArray<unsigned short,1024>*, BSSimpleArray<unsigned short,1024>*)
    // void __cdecl NavMesh::*(const BSSimpleArray<unsigned short,1024>*, BSSimpleArray<unsigned short,1024>*)
    // void __cdecl NavMesh::*(const BSSimpleArray<unsigned short,1024>*, BSSimpleArray<unsigned short,1024>*)
    // void __cdecl NavMesh::*(NavMeshPtr&, unsigned short)
    // void __cdecl NavMesh::*(NavMeshInfo*)
    // void __cdecl NavMesh::*(NavMeshPtr&, const BSSimpleArray<unsigned short,1024>*, NavMeshPtr&, const BSSimpleArray<unsigned short,1024>*)
    // void __cdecl NavMesh::*(unsigned short)
    // int __cdecl NavMesh::*(unsigned short)
    // void __cdecl NavMesh::*(NiPoint3*, NiPoint3*)
    // void __cdecl NavMesh::*()
    // bool __cdecl NavMesh::*(unsigned short)
    // bool __cdecl NavMesh::*(unsigned short, unsigned short)
    // bool __cdecl NavMesh::*(unsigned short)
    // bool __cdecl NavMesh::*(unsigned short, unsigned short)
    // bool __cdecl NavMesh::*(NiPoint3&, NiPoint3&)
    // NiPoint3 __cdecl NavMesh::*(unsigned short)
    // NiPoint3 __cdecl NavMesh::*(unsigned short)
    // char __cdecl NavMesh::*(unsigned short)
    // NiPoint3 __cdecl NavMesh::*(unsigned short)
    // void __cdecl NavMesh::*(unsigned short, NiPoint3&)
    // NiPoint3 __cdecl NavMesh::*(unsigned short, unsigned short)
    // float __cdecl NavMesh::*(TESObjectCELL*, const NiPoint3&, const NiPoint3&)
    // unsigned short __cdecl NavMesh::*(const NiPoint3&, FindTriangleForLocationFilter*)
    // void __cdecl NavMesh::*(const NiPoint3&, const NiPoint3&, BSSimpleArray<unsigned short,1024>*)
    // bool __cdecl NavMesh::*(const NiPoint3&, unsigned short*, bool*)
    // bool __cdecl NavMesh::*(const NiPoint3&, float, unsigned short*, int*, bool)
    // unsigned short __cdecl NavMesh::*(NiPoint3)
    // bool __cdecl NavMesh::*(const NiPoint3&, const NiPoint3&)
    // bool __cdecl NavMesh::*(const NiPoint3&, FindTriangleForLocationFilter*)
    // bool __cdecl NavMesh::*(unsigned short, const NiPoint3&, float&, float, float)
    // bool __cdecl NavMesh::*(unsigned short, const NiPoint3&, float&, FindTriangleForLocationFilter*)
    // bool __cdecl NavMesh::*(unsigned short, const NiPoint3&, float, float, float&)
    // bool __cdecl NavMesh::*(const NiPoint3&, float, float, float&)
    // bool __cdecl NavMesh::*(NiPoint3*)
    // bool __cdecl NavMesh::*(const NiPoint3&, float, NiPoint3*)
    // bool __cdecl NavMesh::*(const NiPoint3&, float, NiPoint3*)
    // NiPoint3 __cdecl NavMesh::*(const NiPoint3&, float)
    // void __cdecl NavMesh::*(unsigned short, int, TESObjectREFR*)
    // EdgeExtraInfo* __cdecl NavMesh::*(unsigned short, int)
    // void __cdecl NavMesh::*(unsigned short, int)
    // void __cdecl NavMesh::*(unsigned short)
    // bool __cdecl NavMesh::*(NiPoint3, NiPoint3, BSSimpleArray<NavMeshVertex *,1024>*)
    // bool __cdecl NavMesh::*(BSSimpleArray<NavMeshVertex *,1024>*, float, bool)
    // bool __cdecl NavMesh::*(BSSimpleArray<NavMeshVertex,1024>, BSSimpleArray<NavMeshVertex,1024>, BSSimpleArray<NavMeshVertex,1024>)
    // bool __cdecl NavMesh::*(BSSimpleArray<NavMeshVertex,1024>, BSSimpleArray<NavMeshVertex,1024>, BSSimpleArray<NavMeshVertex,1024>)
    // bool __cdecl NavMesh::*(unsigned short, const NiPoint3&, const NiPoint3&)
    // int __cdecl NavMesh::*(unsigned short, int, const NiPoint2&, const NiPoint2&, NiPoint2*)
    // int __cdecl NavMesh::*(unsigned short, int, const NiPoint3&, const NiPoint3&)
    // bool __cdecl NavMesh::*(unsigned short, int, const NiPoint2&, const NiPoint2&)
    // bool __cdecl NavMesh::*()
    // void __cdecl NavMesh::*()
    // void __cdecl NavMesh::*(const NiPointer<ObstacleData>&, const NiPoint3&, BSSimpleArray<unsigned short,1024>*)
    // unsigned int __cdecl NavMesh::*(ObstacleUndoData*)
    // void __cdecl NavMesh::*(unsigned int)
    // unsigned int __cdecl NavMesh::*()
    // NiPointer<ObstacleUndoData>& __cdecl NavMesh::*(unsigned int)
    // unsigned int __cdecl NavMesh::*(const NiPointer<ObstacleData>&)
    // unsigned int __cdecl NavMesh::*(const NiPointer<ObstacleData>&, ObstacleUndoData*&)
    // unsigned int __cdecl NavMesh::*(ObstacleUndoData*)
    // bool __cdecl NavMesh::*(unsigned short, NiPointer<ObstacleData>&)
    // bool __cdecl NavMesh::*(unsigned int, ObstacleData*)
    // bool __cdecl NavMesh::*(unsigned int)
    // NavMeshClosedDoorInfo* __cdecl NavMesh::*(unsigned short)
    // unsigned int __cdecl NavMesh::*()
    // GetTrianglesForGridCell
    // unsigned int __cdecl NavMesh::*(const NiPoint3&)
    // unsigned int __cdecl NavMesh::*(unsigned short, BSSimpleArray<unsigned int,1024>*)
    // void __cdecl NavMesh::*()
    // bool __cdecl NavMesh::*(unsigned short, NavMeshPOVData&)
    // unsigned int __cdecl NavMesh::*(unsigned short, BSSimpleArray<unsigned short,1024>&)
    // unsigned int __cdecl NavMesh::*(unsigned short, BSSimpleArray<unsigned short,1024>&)
    // void __cdecl NavMesh::*(const NiPoint3&, unsigned short, float, float)
    // unsigned int __cdecl NavMesh::*()
    // NavMeshStaticAvoidNode* __cdecl NavMesh::*(unsigned int)
    // bool __cdecl NavMesh::*(unsigned short, BSSimpleArray<NavMeshStaticAvoidNode *,1024>&)
    // NavMesh& __cdecl NavMesh::*(const NavMesh&)
    // void __cdecl NavMesh::*()
};
FNV_STATIC_ASSERT(sizeof(NavMesh) == 264);
FNV_STATIC_ASSERT(offsetof(NavMesh, m_pOwningCell) == 36);
FNV_STATIC_ASSERT(offsetof(NavMesh, Vertices) == 40);
FNV_STATIC_ASSERT(offsetof(NavMesh, Triangles) == 56);
FNV_STATIC_ASSERT(offsetof(NavMesh, m_kEdgeExtraInfo) == 72);
FNV_STATIC_ASSERT(offsetof(NavMesh, m_kDoorPortals) == 88);
FNV_STATIC_ASSERT(offsetof(NavMesh, m_kClosedDoorInfo) == 104);
FNV_STATIC_ASSERT(offsetof(NavMesh, m_kIndexList) == 120);
FNV_STATIC_ASSERT(offsetof(NavMesh, POVPointerArray) == 136);
FNV_STATIC_ASSERT(offsetof(NavMesh, m_kAdditionalIndexList) == 152);
FNV_STATIC_ASSERT(offsetof(NavMesh, m_kGrid) == 168);
FNV_STATIC_ASSERT(offsetof(NavMesh, m_kObstacleUndoData) == 208);
FNV_STATIC_ASSERT(offsetof(NavMesh, pTriangleToObstacleMap) == 224);
FNV_STATIC_ASSERT(offsetof(NavMesh, m_kAdditionalData) == 228);
FNV_STATIC_ASSERT(offsetof(NavMesh, m_kStaticAvoidNodes) == 244);
FNV_STATIC_ASSERT(offsetof(NavMesh, m_pNavigationMesh) == 260);
#endif
