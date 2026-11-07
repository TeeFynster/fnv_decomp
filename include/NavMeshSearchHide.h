#pragma once

#include "NavMeshSearch.h"
#include "NiPoint3.h"

class ActorX;
class Range6aa4;
class MeshX;
class InfoF;
class ParamX;
class NavMeshStandIn;
class NavSearchNode;
class NavSearchNodeInfo;
class NavSearchNodeList;
class NavData6aa4;

struct TriRef20
{
    MeshX* m_pMesh;
    unsigned short m_usTri;
    unsigned short unk06;
    NiPoint3 m_kPt;
};

class NavMeshSearchHide : public NavMeshSearch
{
public:
    virtual ~NavMeshSearchHide();
    virtual bool CollectConnections(const SearchNode*, BSSimpleArray<SearchNode*, 1024>*);
    virtual bool HasReachedGoal(const SearchNode*);

    void UpdateFields_006a9d60();
    void* DestroyIfFlagged(unsigned int flags);

    void InitEntry(SearchNode* pkEntry, NavMesh* pkMesh, unsigned short usNode);
    void InitEntry(NavSearchNode* pNode, NavMeshStandIn* pMesh, unsigned short usTri);
    bool ExpandNeighbors(NavSearchNodeInfo* pkInfo, NavSearchNodeList* pkList);
    int SetupActorTarget(ActorX* pkActor, TriRef20* pkInfo, ParamX* pkObj, int iArg);
    bool IsGoalNode(NavData6aa4* pkData);

    int GetKeyForNode_006a94f0(NavMeshStandIn* pMesh, unsigned short usTri,
                     float m_fPathingCostCur, NavSearchNode** ppNode);
    int GetKeyForNode_006a94f0(MeshX* pMesh, unsigned short usTri);
    int FUN_006a7e00(int iResult);
    void FUN_006a7c90(int iPacked, InfoF* pkInfo, float fVal);
    void FUN_006a7d60(ParamX* pkObj, int iArg, int iOne);

    union
    {
        ActorX* m_pActor;
        Range6aa4* m_pkActor;
    };
    TriRef20 m_kInfo;
    NiPoint3 m_kStartPoint;
    float m_fFirstLightParameter;
    NiPoint3 m_kTargetPos;
};
