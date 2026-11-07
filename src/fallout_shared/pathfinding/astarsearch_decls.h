// FNV decompilation source: fallout_shared/pathfinding/astarsearch.h
//
// A* pathfinding search template used by the NavMesh and CombatPlan planners.
// PC layout corrections are derived from the PC disassembly: the node map
// lives at +0x14 (buckets only, no vtable slot), the search queue at +0x1FF4,
// m_pFirstNode at +0x2048, m_pCurrentNode at +0x204C, m_pLastCreatedNode at
// +0x2050 and m_bUseBestNode at +0x2054. AStarNode stores its link data
// by value, so the key/bucket offsets depend on the instantiation.
#ifndef FNV_ASTARSEARCH_DECLS_H
#define FNV_ASTARSEARCH_DECLS_H


#include "layout_support.h"
#include "../../../include/BSWin32TaskletManager.h"
#include "../../../include/NavMeshSearch.h"
#include "../../../include/NavMeshTriangleEdgeReference.h"
#include "../../../include/NavMeshTriangleReference.h"

FNV_STATIC_ASSERT(sizeof(NavMeshTriangleReference) == 20);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleReference, m_pLocationNavMesh) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleReference, m_usTriangleIdentifier) == 4);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleReference, m_fCenterX) == 8);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleReference, m_fCenterY) == 12);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleReference, m_fCenterZ) == 16);

FNV_STATIC_ASSERT(sizeof(NavMeshTriangleEdgeReference) == 12);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleEdgeReference, m_pLocationNavMesh) == 0);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleEdgeReference, m_usTriangleIdentifier) == 4);
FNV_STATIC_ASSERT(offsetof(NavMeshTriangleEdgeReference, m_iEdgeIndex) == 8);

class AStarNodeData;
class AStarNodeLink;

template <class BoundingVolumeNode, class TLink> class AStarNode
{
  public:
    float m_fPathingCostCur;                        // +0x0
    float m_fCost;                      // +0x4
    BoundingVolumeNode ObjectResolver;  // +0x8
    TLink m_kOpenListLink;              // +0x8 + sizeof(BoundingVolumeNode)
    AStarNode* m_pParentNode;
    AStarNode* m_ppPreviousNodeLink;
    AStarNode* pListNode;
    unsigned int iKey;
    AStarNode* m_pNextHashNode;

    double GetFitness();
};

template <class BoundingVolumeNode, class TLink> class AStarNodeAllocator
{
  public:
    unsigned char m_ScrapHeap[16];
    AStarNode<BoundingVolumeNode, TLink>* CreateNode();
    AStarNode<BoundingVolumeNode, TLink>* AStarNodeHeap_CombatPlanNode_CombatPlanLink_AllocateNode();
};

template <class BoundingVolumeNode, class TLink> class AStarNodeHashTable
{
  public:
    AStarNode<BoundingVolumeNode, TLink>* m_ppNodes[2039];  // +0x0
    unsigned int iCount;                                    // +0x1FDC
    unsigned int AStarNodeMap_GetBucketIndex(unsigned int uiKey);
};

template <class BoundingVolumeNode, class TLink> class AStarOpenList
{
  public:
    float m_fValue;                                       // +0x0
    AStarNode<BoundingVolumeNode, TLink>* m_ppNodes[20];  // +0x4
    void InsertSortedNode(AStarNode<BoundingVolumeNode, TLink>* pNode);
    void UnlinkNode(AStarNode<BoundingVolumeNode, TLink>* pNode);
    void UnlinkFromNeighbors(AStarNode<BoundingVolumeNode, TLink>* pNode);
    AStarNode<BoundingVolumeNode, TLink>* Pop();
};

// PC-only dynamic connection array (20 bytes on PC: no inline buffer).
// The original container type is unrecovered; size and methods are fixed by
// the ComputePath disassembly (ctor writes +0x10, Clear touches +0x4/+0x8/+0xC).
template <class BoundingVolumeNode, class TLink> class AStarConnectionArray
{
  public:
    AStarConnectionArray();
    ~AStarConnectionArray();
    void Clear(bool bFreeData);
    unsigned int GetSize();
    AStarNode<BoundingVolumeNode, TLink>*& operator[](unsigned int uiIndex);

  private:
    // Named words (not an array) so /GS sees no local buffer here.
    unsigned int m_uiData0;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    unsigned int m_uiData3;
    unsigned int m_uiData4;
};

// Select the exe concrete layouts after their private storage types are complete.
#define FNV64_ASTARSEARCH_STORED_SPECIALIZATIONS
#include "../../../include/AStarSearch.h"
#undef FNV64_ASTARSEARCH_STORED_SPECIALIZATIONS
// The shared primary template also serves the distinct NavMeshSearchNode instantiation.





typedef AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference> NavMeshAStarNode;
typedef AStarNode<AStarNodeData*, AStarNodeLink*> CombatPlanAStarNode;
typedef AStarSearch<NavMeshTriangleReference, NavMeshTriangleEdgeReference> NavMeshAStarSearch;
FNV_STATIC_ASSERT(sizeof(NavMeshAStarNode) == 0x3C);
FNV_STATIC_ASSERT(offsetof(NavMeshAStarNode, iKey) == 0x34);
FNV_STATIC_ASSERT(offsetof(NavMeshAStarNode, m_pNextHashNode) == 0x38);
FNV_STATIC_ASSERT(sizeof(CombatPlanAStarNode) == 0x24);
FNV_STATIC_ASSERT(offsetof(CombatPlanAStarNode, iKey) == 0x1C);
FNV_STATIC_ASSERT(offsetof(CombatPlanAStarNode, m_pNextHashNode) == 0x20);
FNV_STATIC_ASSERT(sizeof(NavMeshAStarSearch) == 0x2058);
FNV_STATIC_ASSERT(offsetof(NavMeshAStarSearch, m_kNodeHashTable) == 0x14);
FNV_STATIC_ASSERT(offsetof(NavMeshAStarSearch, AStarBucketQueue) == 0x1FF4);
FNV_STATIC_ASSERT(offsetof(NavMeshAStarSearch, m_pFirstNode) == 0x2048);
FNV_STATIC_ASSERT(offsetof(NavMeshAStarSearch, m_pLastCreatedNode) == 0x2050);
FNV_STATIC_ASSERT(offsetof(NavMeshAStarSearch, m_bUseBestNode) == 0x2054);

unsigned int gm_GetCurrentThreadId();

void BSSleep(unsigned long);
#endif
