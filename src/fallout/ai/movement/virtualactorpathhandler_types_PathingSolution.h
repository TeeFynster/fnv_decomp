// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_PATHINGSOLUTION_H
#define FNV_PATHINGSOLUTION_H

#include "layout_support.h"
#include "NiPoint3.h"
#include "NiRefObject.h"
#include "PathingLocation.h"
#include "TESObjectREFR.h"
#include "layout_support.h"
class SineCosine;
class CircularArc;
class CompactNavMeshEdgeReference;
class NavMesh;
class NavMeshInfoSearchNode;
class NavMeshTrianglePathEntry;
class ParentSpaceNode;
class PathSmootherPOVDebugArcRecord;
class PathSmootherPOVDebugTests;
class PathSmootherPOVDebugSphereTest;
class PathSmootherPOVDebugRay;
class PathingInfo;
class PathingInfoEntry;
class PathingInfoParams;
class PathingGraphNode;
class PathingSolution;
class LocationDescriptor;
class BaseProcess;
class Sphere;
class TeleportLink;
class PathingPath;
class PacketNodeRecord;
#include "../../../../include/PATHING_INFO_TYPE.h"
#include "../../../../include/PATHING_MESSAGE_ID.h"
#include "../../../../include/PATHING_PARAMETER_ID.h"
enum PathSmootherPOVDebugRayTest__Result
{
    PathSmootherPOVDebugRayTest__Result_RESULT_PASS = 0,
    PathSmootherPOVDebugRayTest__Result_RESULT_FAIL = 1,
    PathSmootherPOVDebugRayTest__Result_RESULT_INFINITE_LOOP = 2
};
#include "../../../../include/ANGLE_DIRECTION.h"
enum PathSmootherPOVDebugArcTest__Result
{
    PathSmootherPOVDebugArcTest__Result_RESULT_PASS = 0,
    PathSmootherPOVDebugArcTest__Result_RESULT_FAIL = 1,
    PathSmootherPOVDebugArcTest__Result_RESULT_INFINITE_LOOP = 2
};
#pragma pack(push, 4)
class PathingInfoParams
{
  public:
    int ints[3];               // +0x0, 12 bytes
    PathingLocation location;  // +0xC, 40 bytes
    // PathingInfoParams
    // const PathingInfoParams& __cdecl PathingInfoParams::*(const PathingInfoParams&)
    // void __cdecl PathingInfoParams::*()
    // void __cdecl PathingInfoParams::*()
    // void* __cdecl PathingInfoParams::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingInfoParams) == 52);
FNV_STATIC_ASSERT(offsetof(PathingInfoParams, ints) == 0);
FNV_STATIC_ASSERT(offsetof(PathingInfoParams, location) == 12);
#pragma pack(push, 4)
class PathingInfoEntry
{
  public:
    PATHING_INFO_TYPE InfoType;    // +0x0, 4 bytes
    PATHING_MESSAGE_ID MessageID;  // +0x4, 4 bytes
    PATHING_PARAMETER_ID ParamID;  // +0x8, 4 bytes
    PathingInfoParams Params;      // +0xC, 52 bytes
    // PathingInfoEntry
    // PathingInfoEntry& __cdecl PathingInfoEntry::*(const PathingInfoEntry&)
    // void __cdecl PathingInfoEntry::*(IDebugText*)
    // void __cdecl PathingInfoEntry::*(char*, int)
    // void __cdecl PathingInfoEntry::*()
    // void* __cdecl PathingInfoEntry::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingInfoEntry) == 64);
FNV_STATIC_ASSERT(offsetof(PathingInfoEntry, InfoType) == 0);
FNV_STATIC_ASSERT(offsetof(PathingInfoEntry, MessageID) == 4);
FNV_STATIC_ASSERT(offsetof(PathingInfoEntry, ParamID) == 8);
FNV_STATIC_ASSERT(offsetof(PathingInfoEntry, Params) == 12);
#pragma pack(push, 4)
class ParentSpaceNode
{
  public:
    bool m_bIsWorldspace;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    TESWorldSpace* m_pContainingWorldspace;  // +0x4, 4 bytes
    TESObjectCELL* m_pReferenceCell;         // +0x8, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ParentSpaceNode) == 12);
FNV_STATIC_ASSERT(offsetof(ParentSpaceNode, m_bIsWorldspace) == 0);
FNV_STATIC_ASSERT(offsetof(ParentSpaceNode, m_pContainingWorldspace) == 4);
FNV_STATIC_ASSERT(offsetof(ParentSpaceNode, m_pReferenceCell) == 8);
#pragma pack(push, 4)
class TeleportLink
{
  public:
    TESObjectREFR* pPathNodeDoor;             // +0x0, 4 bytes
    NiPoint3 m_kDestinationPosition;  // +0x4, 12 bytes
    // void __cdecl TeleportLink::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TeleportLink) == 16);
FNV_STATIC_ASSERT(offsetof(TeleportLink, pPathNodeDoor) == 0);
FNV_STATIC_ASSERT(offsetof(TeleportLink, m_kDestinationPosition) == 4);
#pragma pack(push, 4)
class PathingPath
{
  public:
    BSSimpleArray<ParentSpaceNode, 1024> Spaces;  // +0x0, 16 bytes
    BSSimpleArray<TeleportLink, 1024> Doors;      // +0x10, 16 bytes
    NiPoint3 Start;                               // +0x20, 12 bytes
    NiPoint3 End;                                 // +0x2C, 12 bytes
    // PathingPath
    // void __cdecl PathingPath::*()
    // PathingPath& __cdecl PathingPath::*(const PathingPath&)
    // void __cdecl PathingPath::*()
    // float __cdecl PathingPath::*()
    // void* __cdecl PathingPath::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingPath) == 56);
FNV_STATIC_ASSERT(offsetof(PathingPath, Spaces) == 0);
FNV_STATIC_ASSERT(offsetof(PathingPath, Doors) == 16);
FNV_STATIC_ASSERT(offsetof(PathingPath, Start) == 32);
FNV_STATIC_ASSERT(offsetof(PathingPath, End) == 44);
#pragma pack(push, 4)
class PathingInfo
{
  public:
    BSSimpleArray<PathingInfoEntry, 1024> Items;                      // +0x0, 16 bytes
    unsigned int m_uiNavMeshInfoCount;                                // +0x10, 4 bytes
    BSSimpleArray<const NavMeshInfo*, 1024> NavMeshInfoPointerArray;  // +0x14, 16 bytes
    BSSimpleArray<TESObjectREFR*, 1024> TESObjectReferenceArray;      // +0x24, 16 bytes
    PathingPath NavMeshReferenceCollection;                           // +0x34, 56 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingInfo) == 108);
FNV_STATIC_ASSERT(offsetof(PathingInfo, Items) == 0);
FNV_STATIC_ASSERT(offsetof(PathingInfo, m_uiNavMeshInfoCount) == 16);
FNV_STATIC_ASSERT(offsetof(PathingInfo, NavMeshInfoPointerArray) == 20);
FNV_STATIC_ASSERT(offsetof(PathingInfo, TESObjectReferenceArray) == 36);
FNV_STATIC_ASSERT(offsetof(PathingInfo, NavMeshReferenceCollection) == 52);
#pragma pack(push, 4)
class NavMeshInfoSearchNode
{
  public:
    const NavMeshInfo* pInfo;  // +0x0, 4 bytes
    float m_fPathingCostCur;               // +0x4, 4 bytes
    float m_fCost;             // +0x8, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NavMeshInfoSearchNode) == 12);
FNV_STATIC_ASSERT(offsetof(NavMeshInfoSearchNode, pInfo) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshInfoSearchNode, m_fPathingCostCur) == 4);
FNV_STATIC_ASSERT(offsetof(NavMeshInfoSearchNode, m_fCost) == 8);
#pragma pack(push, 4)
class CompactNavMeshEdgeReference
{
  public:
    NavMesh* m_pLocationNavMesh;    // +0x0, 4 bytes
    unsigned short m_usTriangleID;  // +0x4, 2 bytes
    unsigned char layoutPadding6[2];
    // CompactNavMeshEdgeReference
    // CompactNavMeshEdgeReference& __cdecl CompactNavMeshEdgeReference::*(const CompactNavMeshEdgeReference&)
    // bool __cdecl CompactNavMeshEdgeReference::*(const CompactNavMeshEdgeReference&)
    // bool __cdecl CompactNavMeshEdgeReference::*(const CompactNavMeshEdgeReference&)
    // unsigned __int64 __cdecl CompactNavMeshEdgeReference::*()
    // void __cdecl CompactNavMeshEdgeReference::*(char*, unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(CompactNavMeshEdgeReference) == 8);
FNV_STATIC_ASSERT(offsetof(CompactNavMeshEdgeReference, m_pLocationNavMesh) == 0);
FNV_STATIC_ASSERT(offsetof(CompactNavMeshEdgeReference, m_usTriangleID) == 4);
#pragma pack(push, 4)
class NavMeshTrianglePathEntry
{
  public:
    CompactNavMeshEdgeReference Triangle;  // +0x0, 8 bytes
    float m_fPathingCostCur;                           // +0x8, 4 bytes
    float m_fCost;                         // +0xC, 4 bytes
    float NavMeshTrianglePathCostData;     // +0x10, 4 bytes
    int NavMeshPathCostData;               // +0x14, 4 bytes
    // NavMeshTrianglePathEntry
    // NavMeshTrianglePathEntry& __cdecl NavMeshTrianglePathEntry::*(const NavMeshTrianglePathEntry&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NavMeshTrianglePathEntry) == 24);
FNV_STATIC_ASSERT(offsetof(NavMeshTrianglePathEntry, Triangle) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshTrianglePathEntry, m_fPathingCostCur) == 8);
FNV_STATIC_ASSERT(offsetof(NavMeshTrianglePathEntry, m_fCost) == 12);
FNV_STATIC_ASSERT(offsetof(NavMeshTrianglePathEntry, NavMeshTrianglePathCostData) == 16);
FNV_STATIC_ASSERT(offsetof(NavMeshTrianglePathEntry, NavMeshPathCostData) == 20);
#pragma pack(push, 4)
class PathSmootherPOVDebugSphereTest
{
  public:
    NiPoint3 Center;            // +0x0, 12 bytes
    float fRadius;              // +0xC, 4 bytes
    unsigned short m_usResult;  // +0x10, 2 bytes
    unsigned char layoutPadding12[2];
    // void __cdecl PathSmootherPOVDebugSphereTest::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathSmootherPOVDebugSphereTest) == 20);
FNV_STATIC_ASSERT(offsetof(PathSmootherPOVDebugSphereTest, Center) == 0);
FNV_STATIC_ASSERT(offsetof(PathSmootherPOVDebugSphereTest, fRadius) == 12);
FNV_STATIC_ASSERT(offsetof(PathSmootherPOVDebugSphereTest, m_usResult) == 16);
#pragma pack(push, 4)
class PathSmootherPOVDebugRay
{
  public:
    NiPoint3 Start;                                 // +0x0, 12 bytes
    NiPoint3 End;                                   // +0xC, 12 bytes
    PathSmootherPOVDebugRayTest__Result m_kResult;  // +0x18, 4 bytes
    float m_fPathingCostCur;                                    // +0x1C, 4 bytes
    // void __cdecl PathSmootherPOVDebugRay::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathSmootherPOVDebugRay) == 32);
FNV_STATIC_ASSERT(offsetof(PathSmootherPOVDebugRay, Start) == 0);
FNV_STATIC_ASSERT(offsetof(PathSmootherPOVDebugRay, End) == 12);
FNV_STATIC_ASSERT(offsetof(PathSmootherPOVDebugRay, m_kResult) == 24);
FNV_STATIC_ASSERT(offsetof(PathSmootherPOVDebugRay, m_fPathingCostCur) == 28);
#pragma pack(push, 4)
class SineCosine
{
  public:
    float fCos;  // +0x0, 4 bytes
    float fSin;  // +0x4, 4 bytes
    // SineCosine
    // SineCosine& __cdecl SineCosine::*(const SineCosine&)
    // SineCosine __cdecl SineCosine::*(const SineCosine&)
    // SineCosine __cdecl SineCosine::*(const SineCosine&)
    // SineCosine& __cdecl SineCosine::*(const SineCosine&)
    // SineCosine& __cdecl SineCosine::*(const SineCosine&)
    // bool __cdecl SineCosine::*()
    // void __cdecl SineCosine::*(float)
    // float __cdecl SineCosine::*()
    // NiPoint2 __cdecl SineCosine::*(float)
    // NiPoint3 __cdecl SineCosine::*(float)
    // bool __cdecl SineCosine::*(const SineCosine&, const SineCosine&, float)
    // ANGLE_DIRECTION __cdecl SineCosine::*(const SineCosine&, const SineCosine&)
    // int __cdecl SineCosine::*()
    // bool __cdecl SineCosine::*(const SineCosine&)
    // bool __cdecl SineCosine::*(const SineCosine&)
    // bool __cdecl SineCosine::*(const SineCosine&)
    // bool __cdecl SineCosine::*(const SineCosine&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(SineCosine) == 8);
FNV_STATIC_ASSERT(offsetof(SineCosine, fCos) == 0);
FNV_STATIC_ASSERT(offsetof(SineCosine, fSin) == 4);
#pragma pack(push, 4)
class CircularArc
{
  public:
    SineCosine Start;     // +0x0, 8 bytes
    SineCosine End;       // +0x8, 8 bytes
    ANGLE_DIRECTION Dir;  // +0x10, 4 bytes
    // CircularArc
    // bool __cdecl CircularArc::*()
    // bool __cdecl CircularArc::*(const SineCosine&)
    // float __cdecl CircularArc::*(float)
    // CircularArc& __cdecl CircularArc::*(const CircularArc&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(CircularArc) == 20);
FNV_STATIC_ASSERT(offsetof(CircularArc, Start) == 0);
FNV_STATIC_ASSERT(offsetof(CircularArc, End) == 8);
FNV_STATIC_ASSERT(offsetof(CircularArc, Dir) == 16);
#pragma pack(push, 4)
class Sphere
{
  public:
    NiPoint3 Center;  // +0x0, 12 bytes
    float fRadius;    // +0xC, 4 bytes
    // Sphere
    // Sphere& __cdecl Sphere::*(const Sphere&)
    // void __cdecl Sphere::*(const NiPoint3&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Sphere) == 16);
FNV_STATIC_ASSERT(offsetof(Sphere, Center) == 0);
FNV_STATIC_ASSERT(offsetof(Sphere, fRadius) == 12);
#pragma pack(push, 4)
class PathSmootherPOVDebugArcRecord
{
  public:
    CircularArc Arc;                                // +0x0, 20 bytes
    Sphere m_kTestSphere;                           // +0x14, 16 bytes
    PathSmootherPOVDebugArcTest__Result m_kResult;  // +0x24, 4 bytes
    // PathSmootherPOVDebugArcRecord
    // PathSmootherPOVDebugArcRecord& __cdecl PathSmootherPOVDebugArcRecord::*(const PathSmootherPOVDebugArcRecord&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathSmootherPOVDebugArcRecord) == 40);
FNV_STATIC_ASSERT(offsetof(PathSmootherPOVDebugArcRecord, Arc) == 0);
FNV_STATIC_ASSERT(offsetof(PathSmootherPOVDebugArcRecord, m_kTestSphere) == 20);
FNV_STATIC_ASSERT(offsetof(PathSmootherPOVDebugArcRecord, m_kResult) == 36);
#pragma pack(push, 4)
class PathSmootherPOVDebugTests
{
  public:
    BSSimpleArray<PathSmootherPOVDebugSphereTest, 1024> POVPointerArray;  // +0x0, 16 bytes
    BSSimpleArray<PathSmootherPOVDebugRay, 1024> Rays;                    // +0x10, 16 bytes
    BSSimpleArray<PathSmootherPOVDebugArcRecord, 1024> m_kThirdArray;     // +0x20, 16 bytes
    // void __cdecl PathSmootherPOVDebugTests::*(PathSmootherPOVDebugTests*)
    // PathSmootherPOVDebugTests
    // void __cdecl PathSmootherPOVDebugTests::*()
    // PathSmootherPOVDebugTests& __cdecl PathSmootherPOVDebugTests::*(const PathSmootherPOVDebugTests&)
    // void* __cdecl PathSmootherPOVDebugTests::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathSmootherPOVDebugTests) == 48);
FNV_STATIC_ASSERT(offsetof(PathSmootherPOVDebugTests, POVPointerArray) == 0);
FNV_STATIC_ASSERT(offsetof(PathSmootherPOVDebugTests, Rays) == 16);
FNV_STATIC_ASSERT(offsetof(PathSmootherPOVDebugTests, m_kThirdArray) == 32);
#pragma pack(push, 4)
class PacketNodeRecord
{
  public:
    unsigned int iFlags;       // +0x0, 4 bytes
    PathingLocation Location;  // +0x4, 40 bytes
    TESObjectREFR* m_pDoorRef;   // +0x2C, 4 bytes
    // PacketNodeRecord
    // void __cdecl PacketNodeRecord::*()
    // PacketNodeRecord* __cdecl PacketNodeRecord::*()
    // void __cdecl PacketNodeRecord::*(NiPointer<NiNode>&)
    // GetLocation
    // void __cdecl PacketNodeRecord::*(PathingLocation&)
    // void __cdecl PacketNodeRecord::*()
    // TESObjectREFR* __cdecl PacketNodeRecord::*()
    // bool __cdecl PacketNodeRecord::*()
    // bool __cdecl PacketNodeRecord::*()
    // bool __cdecl PacketNodeRecord::*()
    // void __cdecl PacketNodeRecord::*(IDebugText*)
    // void __cdecl PacketNodeRecord::*(BGSSaveFormBuffer*)
    // void __cdecl PacketNodeRecord::*(BGSLoadFormBuffer*)
    // PacketNodeRecord& __cdecl PacketNodeRecord::*(const PacketNodeRecord&)
    // void* __cdecl PacketNodeRecord::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PacketNodeRecord) == 48);
FNV_STATIC_ASSERT(offsetof(PacketNodeRecord, iFlags) == 0);
FNV_STATIC_ASSERT(offsetof(PacketNodeRecord, Location) == 4);
FNV_STATIC_ASSERT(offsetof(PacketNodeRecord, m_pDoorRef) == 44);
#pragma pack(push, 4)
class PathingGraphNode
{
  public:
    unsigned int iFlags;       // +0x0, 4 bytes
    PathingLocation Location;  // +0x4, 40 bytes
    NiPoint3 Tangent;          // +0x2C, 12 bytes
    TESObjectREFR* m_pDoorRef;   // +0x38, 4 bytes
    // PathingGraphNode
    // void __cdecl PathingGraphNode::*()
    // PathingGraphNode* __cdecl PathingGraphNode::*()
    // const PathingLocation& __cdecl PathingGraphNode::*()
    // const NiPoint3& __cdecl PathingGraphNode::*()
    // void __cdecl PathingGraphNode::*(NiPointer<NiNode>&)
    // TESObjectCELL* __cdecl PathingGraphNode::*()
    // void __cdecl PathingGraphNode::*(const NiPoint3&)
    // bool __cdecl PathingGraphNode::*()
    // void __cdecl PathingGraphNode::*(TESObjectREFR*)
    // void __cdecl PathingGraphNode::*(bool)
    // bool __cdecl PathingGraphNode::*()
    // bool __cdecl PathingGraphNode::*(Actor*)
    // TESObjectREFR* __cdecl PathingGraphNode::*()
    // void __cdecl PathingGraphNode::*(IDebugText*)
    // void __cdecl PathingGraphNode::*(BGSSaveFormBuffer*)
    // void __cdecl PathingGraphNode::*(BGSLoadFormBuffer*)
    // PathingGraphNode& __cdecl PathingGraphNode::*(const PathingGraphNode&)
    // void* __cdecl PathingGraphNode::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingGraphNode) == 60);
FNV_STATIC_ASSERT(offsetof(PathingGraphNode, iFlags) == 0);
FNV_STATIC_ASSERT(offsetof(PathingGraphNode, Location) == 4);
FNV_STATIC_ASSERT(offsetof(PathingGraphNode, Tangent) == 44);
FNV_STATIC_ASSERT(offsetof(PathingGraphNode, m_pDoorRef) == 56);
#pragma pack(push, 4)
class PathingSolution : public NiRefObject
{
  public:
    LocationDescriptor* GetVirtualNode_006e78b0(unsigned int);
    BaseProcess* GetVirtualNode_006e78b0(unsigned int, NiPoint3&);
    unsigned int PathingSolution_GetVirtualNodeCount();
    float CalculatePathLength();
    // base NiRefObject at +0x0, size 8
    PathingInfo Info;                                               // +0x8, 108 bytes
    BSSimpleArray<NavMeshInfoSearchNode, 1024> m_kFirstArray;       // +0x74, 16 bytes
    BSSimpleArray<NavMeshTrianglePathEntry, 1024> m_kElementArray;  // +0x84, 16 bytes
    PathSmootherPOVDebugTests ArrayContainerData;                   // +0x94, 48 bytes
    BSSimpleArray<PacketNodeRecord, 1024> m_kPathingDoorRefArray;   // +0xC4, 16 bytes
    int PathingRecordCollection;                                    // +0xD4, 4 bytes
    int m_iValueBeforeRecordArray;                                  // +0xD8, 4 bytes
    BSSimpleArray<PathingGraphNode, 1024> m_kRecordArray;           // +0xDC, 16 bytes
    BSSimpleArray<unsigned int, 1024> UnsignedIntArray;             // +0xEC, 16 bytes
    bool m_bHasValidPath;                                           // +0xFC, 1 bytes
    unsigned char layoutPaddingFD[3];
    // PathingSolution
    // void __cdecl PathingSolution::*()
    // void __cdecl PathingSolution::*()
    // bool __cdecl PathingSolution::*()
    // bool __cdecl PathingSolution::*()
    // unsigned int __cdecl PathingSolution::*()
    // GetVirtualNode
    // GetFirstVirtualNode
    // GetLastVirtualNode
    // unsigned int __cdecl PathingSolution::*()
    // GetNode
    // GetFirstNode
    // GetLastNode
    // int __cdecl PathingSolution::*()
    // int __cdecl PathingSolution::*()
    // void __cdecl PathingSolution::*()
    // float __cdecl PathingSolution::*()
    // float __cdecl PathingSolution::*()
    // float __cdecl PathingSolution::*(int)
    // float __cdecl PathingSolution::*(unsigned int)
    // float __cdecl PathingSolution::*(float)
    // void __cdecl PathingSolution::*(float, NiPoint3&)
    // bool __cdecl PathingSolution::*(float, float, bool, float*, NiPoint3*)
    // float __cdecl PathingSolution::*(float, float, unsigned int&)
    // NiPoint3 __cdecl PathingSolution::*(float, float)
    // void __cdecl PathingSolution::*(PathingSolution*)
    // bool __cdecl PathingSolution::*(unsigned int)
    // void __cdecl PathingSolution::*(IDebugText*)
    // void __cdecl PathingSolution::*(BGSSaveFormBuffer*)
    // void __cdecl PathingSolution::*(BGSLoadFormBuffer*)
    // AddVirtualPathingNode
    // AddPathingNode
    // void __cdecl PathingSolution::*(unsigned int)
    // void __cdecl PathingSolution::*()
    // void __cdecl PathingSolution::*()
    // unsigned int __cdecl PathingSolution::*(const PacketNodeRecord*)
    // unsigned int __cdecl PathingSolution::*(const PathingGraphNode*)
    // void __cdecl PathingSolution::*(bool)
    // PathingSolution& __cdecl PathingSolution::*(const PathingSolution&)
    // void __cdecl PathingSolution::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingSolution) == 256);
FNV_STATIC_ASSERT(offsetof(PathingSolution, Info) == 8);
FNV_STATIC_ASSERT(offsetof(PathingSolution, m_kFirstArray) == 116);
FNV_STATIC_ASSERT(offsetof(PathingSolution, m_kElementArray) == 132);
FNV_STATIC_ASSERT(offsetof(PathingSolution, ArrayContainerData) == 148);
FNV_STATIC_ASSERT(offsetof(PathingSolution, m_kPathingDoorRefArray) == 196);
FNV_STATIC_ASSERT(offsetof(PathingSolution, PathingRecordCollection) == 212);
FNV_STATIC_ASSERT(offsetof(PathingSolution, m_iValueBeforeRecordArray) == 216);
FNV_STATIC_ASSERT(offsetof(PathingSolution, m_kRecordArray) == 220);
FNV_STATIC_ASSERT(offsetof(PathingSolution, UnsignedIntArray) == 236);
FNV_STATIC_ASSERT(offsetof(PathingSolution, m_bHasValidPath) == 252);
#endif
