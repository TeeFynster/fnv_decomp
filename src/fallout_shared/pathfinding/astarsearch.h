#ifndef FNV_ASTARSEARCH_H
#define FNV_ASTARSEARCH_H

#include "astarsearch_decls.h"

// @fnv 0x00b00a00
inline BSWin32TaskletManager& GetTaskletManager()
{
    static BSWin32TaskletManager s_TaskletManager(6);
    return s_TaskletManager;
}

// @fnv 0x006a7e00
CREATE_ASTARNODE_RESULT AStarSearch<NavMeshTriangleReference, NavMeshTriangleEdgeReference>::CreateOrUpdateNode(
    unsigned int uiKey, float m_fPathingCostCur, AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>*& pNodeOut)
{
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>** ppBucket =
        &m_kNodeHashTable.m_ppNodes[m_kNodeHashTable.AStarNodeMap_GetBucketIndex(uiKey)];
    if (*ppBucket)
    {
        if ((*ppBucket)->iKey == uiKey)
        {
            if ((*ppBucket)->m_fPathingCostCur > m_fPathingCostCur)
            {
                pNodeOut = *ppBucket;
                AStarBucketQueue.UnlinkNode(pNodeOut);
                pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
                return CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA;
            }
            else
                return CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER;
        }
        else
        {
            AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pPrev = *ppBucket;
            AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pCur;
            pCur = (*ppBucket)->m_pNextHashNode;
            while (pCur)
            {
                if (pCur->iKey == uiKey)
                {
                    if (pCur->m_fPathingCostCur > m_fPathingCostCur)
                    {
                        pNodeOut = pCur;
                        AStarBucketQueue.UnlinkNode(pNodeOut);
                        pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
                        return CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA;
                    }
                    else
                        return CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER;
                }
                pPrev = pCur;
                pCur = pCur->m_pNextHashNode;
            }
        }
    }
    pNodeOut = m_kNodeAllocator.CreateNode();
    pNodeOut->iKey = uiKey;
    pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
    pNodeOut->m_pNextHashNode = *ppBucket;
    *ppBucket = pNodeOut;
    return CREATE_ASTARNODE_RESULT_ASTAR_CREATED_NEW_NODE;
}

// @fnv 0x006b8fe0
CREATE_ASTARNODE_RESULT AStarSearch<AStarNodeData*, AStarNodeLink*>::CreateOrUpdateNode(
    unsigned int uiKey, float m_fPathingCostCur, AStarNode<AStarNodeData*, AStarNodeLink*>*& pNodeOut)
{
    AStarNode<AStarNodeData*, AStarNodeLink*>** ppBucket =
        &m_kNodeHashTable.m_ppNodes[m_kNodeHashTable.AStarNodeMap_GetBucketIndex(uiKey)];
    if (*ppBucket)
    {
        if ((*ppBucket)->iKey == uiKey)
        {
            if ((*ppBucket)->m_fPathingCostCur > m_fPathingCostCur)
            {
                pNodeOut = *ppBucket;
                AStarBucketQueue.UnlinkFromNeighbors(pNodeOut);
                pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
                return CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA;
            }
            else
                return CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER;
        }
        else
        {
            AStarNode<AStarNodeData*, AStarNodeLink*>* pPrev = *ppBucket;
            AStarNode<AStarNodeData*, AStarNodeLink*>* pCur;
            pCur = (*ppBucket)->m_pNextHashNode;
            while (pCur)
            {
                if (pCur->iKey == uiKey)
                {
                    if (pCur->m_fPathingCostCur > m_fPathingCostCur)
                    {
                        pNodeOut = pCur;
                        AStarBucketQueue.UnlinkFromNeighbors(pNodeOut);
                        pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
                        return CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA;
                    }
                    else
                        return CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER;
                }
                pPrev = pCur;
                pCur = pCur->m_pNextHashNode;
            }
        }
    }
    pNodeOut = m_kNodeAllocator.AStarNodeHeap_CombatPlanNode_CombatPlanLink_AllocateNode();
    pNodeOut->iKey = uiKey;
    pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
    pNodeOut->m_pNextHashNode = *ppBucket;
    *ppBucket = pNodeOut;
    return CREATE_ASTARNODE_RESULT_ASTAR_CREATED_NEW_NODE;
}

// @fnv 0x006a7c90
AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* AStarSearch<NavMeshTriangleReference, NavMeshTriangleEdgeReference>::FindOrCreateSearchNode(
    unsigned int uiKey, const NavMeshTriangleReference& ObjectResolver, float m_fCost)
{
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pNode;
    switch (((NavMeshSearch*)this)->CreateOrUpdateNode(uiKey, 0.0f, pNode))
    {
    case CREATE_ASTARNODE_RESULT_ASTAR_CREATED_NEW_NODE:
        pNode->m_fCost = m_fCost;
        pNode->ObjectResolver = ObjectResolver;
        AStarBucketQueue.InsertSortedNode(pNode);
        m_pLastCreatedNode = pNode;
        return pNode;
    case CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA:
        return pNode;
    case CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER:
        return 0;
    default:
        return 0;
    }
}

// @fnv 0x006a8010
AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* AStarSearch<NavMeshTriangleReference, NavMeshTriangleEdgeReference>::ComputePath()
{
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pCurNode;
    AStarConnectionArray<NavMeshTriangleReference, NavMeshTriangleEdgeReference> ConnectionArray;
    unsigned int uiCounter;
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* i;
    unsigned int pSavedLastNode;
    i = m_pCurrentNode;
    m_pCurrentNode = AStarBucketQueue.Pop();
    if (m_pCurrentNode == NULL)
        return NULL;
    m_pFirstNode = m_pCurrentNode;
    uiCounter = 0;
    while (m_pCurrentNode)
    {
        if (HasReachedGoal(m_pCurrentNode))
        {
            m_pFirstNode = m_pCurrentNode;
            return m_pCurrentNode;
        }
        ConnectionArray.Clear(0);
        CollectConnections(m_pCurrentNode, &ConnectionArray);
        for (pSavedLastNode = 0; pSavedLastNode < ConnectionArray.GetSize(); pSavedLastNode++)
        {
            pCurNode = ConnectionArray[pSavedLastNode];
            AStarBucketQueue.UnlinkNode(pCurNode);
            if (m_pCurrentNode->m_pParentNode == pCurNode)
                return NULL;
            pCurNode->m_pParentNode = m_pCurrentNode;
            AStarBucketQueue.InsertSortedNode(pCurNode);
            if (pCurNode->GetFitness() < m_pFirstNode->GetFitness())
                m_pFirstNode = pCurNode;
        }
        if (m_bUseBestNode)
        {
            if (++uiCounter == 50)
            {
                uiCounter = 0;
                BSSleep(0);
            }
        }
        i = m_pCurrentNode;
        m_pCurrentNode = AStarBucketQueue.Pop();
    }
    m_pCurrentNode = i;
    return NULL;
}

// @fnv 0x006a7d60
bool AStarSearch<NavMeshTriangleReference, NavMeshTriangleEdgeReference>::Search(unsigned int uiParam1, unsigned int uiParam2, bool bUseBestNode)
{
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pNode;
    bool bSuccess;
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pOutNode;
    m_bUseBestNode = GetTaskletManager().IsTaskletThread(gm_GetCurrentThreadId());
    pNode = ComputePath();
    if (pNode)
    {
        bSuccess = true;
        pOutNode = pNode;
    }
    else if (bUseBestNode)
    {
        bSuccess = false;
        pOutNode = m_pFirstNode;
    }
    else
    {
        bSuccess = false;
        pOutNode = NULL;
    }
    if (pOutNode)
        AStarSearch_NavMeshSearchNode_NavMeshSearchLink_GetPathToNode(pOutNode, uiParam1, uiParam2);
    return bSuccess;
}

#endif
