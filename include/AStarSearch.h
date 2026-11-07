#ifndef FNV64_ASTARSEARCH_DEFINED
#define FNV64_ASTARSEARCH_DEFINED

template <class NodeDataType, class LinkDataType> class AStarNode;
template <class NodeDataType, class LinkDataType> class AStarConnectionArray;
template <class T, unsigned int Growth> class BSSimpleArray;

enum CREATE_ASTARNODE_RESULT
{
    CREATE_ASTARNODE_RESULT_ASTAR_CREATED_NEW_NODE = 0,
    CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA = 1,
    CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER = 2,
    ASTARNODE_CREATED = CREATE_ASTARNODE_RESULT_ASTAR_CREATED_NEW_NODE,
    ASTARNODE_UPDATED = CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA,
    ASTARNODE_UNCHANGED = CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER
};

template <class NodeDataType, class LinkDataType> class AStarSearch
{
public:
    typedef AStarNode<NodeDataType, LinkDataType> AStarNodeType;

    AStarSearch();
    virtual ~AStarSearch();

    void CollectConnections(AStarNodeType* pNode,
        AStarConnectionArray<NodeDataType, LinkDataType>* pConnectionArray);
    virtual bool CollectConnections(const AStarNodeType* pNode,
        BSSimpleArray<AStarNodeType*, 1024>* pConnectionArray);
    bool HasReachedGoal(AStarNodeType* pNode);
    virtual bool HasReachedGoal(const AStarNodeType* pNode);

    CREATE_ASTARNODE_RESULT CreateOrUpdateNode(unsigned int uiKey,
        float m_fPathingCostCur, AStarNodeType*& pNodeOut);
    AStarNodeType* FindOrCreateSearchNode(unsigned int uiKey,
        const NodeDataType& ObjectResolver, float m_fCost);
    AStarNodeType* ComputePath();
    bool AStarSearch_NavMeshSearchNode_NavMeshSearchLink_GetPathToNode(AStarNodeType* pNode, unsigned int uiParam1,
        unsigned int uiParam2);
    bool Search(unsigned int uiParam1, unsigned int uiParam2, bool bUseBestNode);
    void* __thiscall FUN_006b3850(unsigned int flags);
};

// Keep each matched template specialization with its primary declaration.
// Their storage and virtual slots differ; do not substitute the primary layout.
class CombatPlanNode;
class CombatPlanLink;
class NavMeshSearchLink;
class NavMeshSearchNode;
class PathSmootherPOVNode;
class PathSmootherPOVLink;

template <> class AStarSearch<CombatPlanNode *, CombatPlanLink *>
{
public:
    typedef AStarNode<CombatPlanNode *, CombatPlanLink *> AStarNodeType;

    AStarSearch();
    virtual ~AStarSearch();

    void CollectConnections(AStarNodeType* pNode,
        AStarConnectionArray<CombatPlanNode *, CombatPlanLink *>* pConnectionArray);
    bool CollectConnections(const AStarNodeType* pNode,
        BSSimpleArray<AStarNodeType*, 1024>* pConnectionArray);
    bool HasReachedGoal(AStarNodeType* pNode);
    bool HasReachedGoal(const AStarNodeType* pNode);

    CREATE_ASTARNODE_RESULT CreateOrUpdateNode(unsigned int uiKey,
        float m_fPathingCostCur, AStarNodeType*& pNodeOut);
    AStarNodeType* FindOrCreateSearchNode(unsigned int uiKey,
        CombatPlanNode * const& ObjectResolver, float m_fCost);
    AStarNodeType* ComputePath();
    bool AStarSearch_NavMeshSearchNode_NavMeshSearchLink_GetPathToNode(AStarNodeType* pNode, unsigned int uiParam1,
        unsigned int uiParam2);
    bool Search(unsigned int uiParam1, unsigned int uiParam2, bool bUseBestNode);
    void* __thiscall FUN_006b3850(unsigned int flags);
};

template <class NodeDataType> class AStarSearch<NodeDataType, NavMeshSearchLink>
{
public:
    typedef AStarNode<NodeDataType, NavMeshSearchLink> AStarNodeType;

    AStarSearch();
    virtual ~AStarSearch();
};

template <> class AStarSearch<NavMeshSearchNode, NavMeshSearchLink>
{
public:
    typedef AStarNode<NavMeshSearchNode, NavMeshSearchLink> AStarNodeType;

    AStarSearch();
    virtual ~AStarSearch();

    void CollectConnections(AStarNodeType* pNode,
        AStarConnectionArray<NavMeshSearchNode, NavMeshSearchLink>* pConnectionArray);
    bool CollectConnections(const AStarNodeType* pNode,
        BSSimpleArray<AStarNodeType*, 1024>* pConnectionArray);
    bool HasReachedGoal(AStarNodeType* pNode);
    bool HasReachedGoal(const AStarNodeType* pNode);

    CREATE_ASTARNODE_RESULT CreateOrUpdateNode(unsigned int uiKey,
        float m_fPathingCostCur, AStarNodeType*& pNodeOut);
    AStarNodeType* FindOrCreateSearchNode(unsigned int uiKey,
        const NavMeshSearchNode& ObjectResolver, float m_fCost);
    AStarNodeType* ComputePath();
    bool AStarSearch_NavMeshSearchNode_NavMeshSearchLink_GetPathToNode(AStarNodeType* pNode, unsigned int uiParam1,
        unsigned int uiParam2);
    bool Search(unsigned int uiParam1, unsigned int uiParam2, bool bUseBestNode);
    void* __thiscall FUN_006b3850(unsigned int flags);
};

template <>
class AStarSearch<PathSmootherPOVNode, PathSmootherPOVLink>
{
public:
    typedef AStarNode<PathSmootherPOVNode, PathSmootherPOVLink> AStarNodeType;

    virtual ~AStarSearch();

    unsigned char searchState[0x2054];

    void CollectConnections(AStarNodeType*,
        AStarConnectionArray<PathSmootherPOVNode, PathSmootherPOVLink>*);
    bool CollectConnections(const AStarNodeType*, BSSimpleArray<AStarNodeType*, 1024>*);
    bool HasReachedGoal(AStarNodeType*);
    bool HasReachedGoal(const AStarNodeType*);
    CREATE_ASTARNODE_RESULT CreateOrUpdateNode(unsigned int, float, AStarNodeType*&);
    AStarNodeType* FindOrCreateSearchNode(unsigned int, const PathSmootherPOVNode&, float);
    AStarNodeType* ComputePath();
    bool AStarSearch_NavMeshSearchNode_NavMeshSearchLink_GetPathToNode(AStarNodeType*, unsigned int, unsigned int);
    bool Search(unsigned int, unsigned int, bool);
    void* __thiscall FUN_006b3850(unsigned int);
};

#endif // FNV64_ASTARSEARCH_DEFINED

// Exe 0x006a7e00/0x006b8fe0: concrete 0x2058-byte searches; select after the storage policies are complete.
#if defined(FNV64_ASTARSEARCH_STORED_SPECIALIZATIONS) && !defined(FNV64_ASTARSEARCH_STORED_SPECIALIZATIONS_DEFINED)
#define FNV64_ASTARSEARCH_STORED_SPECIALIZATIONS_DEFINED
template <> class AStarSearch<NavMeshTriangleReference, NavMeshTriangleEdgeReference>
{
  public:
    virtual ~AStarSearch();
    AStarNodeAllocator<NavMeshTriangleReference, NavMeshTriangleEdgeReference> m_kNodeAllocator;  // +0x4
    AStarNodeHashTable<NavMeshTriangleReference, NavMeshTriangleEdgeReference> m_kNodeHashTable;  // +0x14
    AStarOpenList<NavMeshTriangleReference, NavMeshTriangleEdgeReference> AStarBucketQueue;       // +0x1FF4
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* m_pFirstNode;              // +0x2048
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* m_pCurrentNode;            // +0x204C
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* m_pLastCreatedNode;        // +0x2050
    bool m_bUseBestNode;                                             // +0x2054
    unsigned char m_Padding2055[3];

    virtual void CollectConnections(AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pNode,
                                    AStarConnectionArray<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pConnectionArray);
    virtual bool HasReachedGoal(AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pNode);

    CREATE_ASTARNODE_RESULT CreateOrUpdateNode(unsigned int uiKey, float m_fPathingCostCur,
                                               AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>*& pNodeOut);
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* FindOrCreateSearchNode(unsigned int uiKey,
                                                                 const NavMeshTriangleReference& ObjectResolver,
                                                                 float m_fCost);
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* ComputePath();
    bool AStarSearch_NavMeshSearchNode_NavMeshSearchLink_GetPathToNode(AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pNode, unsigned int uiParam1, unsigned int uiParam2);
    bool Search(unsigned int uiParam1, unsigned int uiParam2, bool bUseBestNode);
};

template <> class AStarSearch<AStarNodeData*, AStarNodeLink*>
{
  public:
    virtual ~AStarSearch();
    AStarNodeAllocator<AStarNodeData*, AStarNodeLink*> m_kNodeAllocator;  // +0x4
    AStarNodeHashTable<AStarNodeData*, AStarNodeLink*> m_kNodeHashTable;  // +0x14
    AStarOpenList<AStarNodeData*, AStarNodeLink*> AStarBucketQueue;       // +0x1FF4
    AStarNode<AStarNodeData*, AStarNodeLink*>* m_pFirstNode;              // +0x2048
    AStarNode<AStarNodeData*, AStarNodeLink*>* m_pCurrentNode;            // +0x204C
    AStarNode<AStarNodeData*, AStarNodeLink*>* m_pLastCreatedNode;        // +0x2050
    bool m_bUseBestNode;                                             // +0x2054
    unsigned char m_Padding2055[3];

    virtual void CollectConnections(AStarNode<AStarNodeData*, AStarNodeLink*>* pNode,
                                    AStarConnectionArray<AStarNodeData*, AStarNodeLink*>* pConnectionArray);
    virtual bool HasReachedGoal(AStarNode<AStarNodeData*, AStarNodeLink*>* pNode);

    CREATE_ASTARNODE_RESULT CreateOrUpdateNode(unsigned int uiKey, float m_fPathingCostCur,
                                               AStarNode<AStarNodeData*, AStarNodeLink*>*& pNodeOut);
    AStarNode<AStarNodeData*, AStarNodeLink*>* FindOrCreateSearchNode(unsigned int uiKey,
                                                                 AStarNodeData* const& ObjectResolver,
                                                                 float m_fCost);
    AStarNode<AStarNodeData*, AStarNodeLink*>* ComputePath();
    bool AStarSearch_NavMeshSearchNode_NavMeshSearchLink_GetPathToNode(AStarNode<AStarNodeData*, AStarNodeLink*>* pNode, unsigned int uiParam1, unsigned int uiParam2);
    bool Search(unsigned int uiParam1, unsigned int uiParam2, bool bUseBestNode);
};
#endif
