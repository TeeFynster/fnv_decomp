#pragma once

#include "AStarSearch.h"
#include <stddef.h>

class CombatPlanNode;
class CombatPlanLink;
class CPNode;
class CPOutArray;
class CPOutItem;
class Owner;

class CombatPlanner : public AStarSearch<CombatPlanNode *, CombatPlanLink *>
{
public:
    class WorldState
    {
    public:
        int unk00[23];

        WorldState()
        {
            CombatWorldStateArray_CombatWorldStateArray();
        }
        void* CombatWorldStateArray_CombatWorldStateArray();
        void CombatWorldStateArray_ClearValues();
    };

    class StreamAllocator
    {
    public:
        unsigned int unk00;
        unsigned int unk04;
        unsigned int unk08;
        unsigned int unk0C;

        StreamAllocator();
        ~StreamAllocator();
        void* ScrapHeap_Allocate(unsigned int size, unsigned int alignment);
    };

    class PlanStorage
    {
    public:
        int unk00;
        unsigned int unk04;
        void* array1[22];
        void* array2[22];
        float unkB8[22];

        PlanStorage()
        {
            CombatPlannerData_CombatPlannerData();
        }

        ~PlanStorage()
        {
            ReleaseStorage_00995910();
        }
        PlanStorage* CombatPlannerData_CombatPlannerData();
        void ReleaseStorage_00995910();
        void SetQuantity(unsigned int quantity);
    };

    CombatPlanner();
    virtual ~CombatPlanner();
    virtual bool ExpandNode(CPNode* pkNode, CPOutArray* pkOut);
    virtual bool IsGoalNode_00995800(const AStarNode<CombatPlanNode *, CombatPlanLink *>* p);

    Owner* BuildPlan(void*, int);
    Owner* CreatePlan_0(void*, int);
    Owner* CreatePlan_0(void*, bool);
    void* FUN_0097e460(unsigned int flags);
    void FUN_0097e3e0();
    void CleanUp_00995830();
    int CombatPlanner_GetNodeKey(CombatPlanNode** ppkState);
    template <class State>
    int CombatPlanner_GetNodeKey(State** ppkState);
    int FUN_006b8fe0(int iState, float m_fPathingCostCur, CPOutItem** ppkItem);
    bool vf02(const AStarNode<CombatPlanNode *, CombatPlanLink *>* p);

    int pad[0x815];
    int field_2058;
    WorldState field_205c;
    StreamAllocator field_20b8;
    PlanStorage field_20c8;
};

typedef char CombatPlannerSizeCheck[sizeof(CombatPlanner) == 8664 ? 1 : -1];
typedef char CombatPlannerOwnerOffsetCheck[offsetof(CombatPlanner, field_2058) == 0x2058 ? 1 : -1];
typedef char CombatPlannerWorldStateOffsetCheck[offsetof(CombatPlanner, field_205c) == 0x205c ? 1 : -1];
typedef char CombatPlannerAllocatorOffsetCheck[offsetof(CombatPlanner, field_20b8) == 0x20b8 ? 1 : -1];
typedef char CombatPlannerStorageOffsetCheck[offsetof(CombatPlanner, field_20c8) == 0x20c8 ? 1 : -1];
