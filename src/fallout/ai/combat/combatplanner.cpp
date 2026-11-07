
// src/fallout/ai/combat/combatplanner.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatplanner.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/CombatPlanner.h"

template <class NodeDataType, class LinkDataType> struct AStarNode
{
    int m_i;
    int m_iUnknownValue;
    NodeDataType m_p;
};
// Returns true when the int at offset 0xdc of the node's m_p is zero, otherwise false.
// @fnv 0x00995800
// src: XBOX_PDB 0x00995800
bool CombatPlanner::IsGoalNode_00995800(const AStarNode<CombatPlanNode*, CombatPlanLink*>* apNode)
{
    if (*(const int*)((const char*)apNode->m_p + 0xdc) == 0)
        return true;
    return false;
}

void* operator new(unsigned int uiSize, void* pvWhere);
void operator delete(void* pvMem, void* pvWhere);

extern unsigned int DAT_010a2720;
extern const float DAT_0108dbf0;  // FLT_MAX

class CPTarget;

class CPCond
{
  public:
    int Modelloader_GetReferencedThis();
    CPTarget* FUN_00726070();
};

struct CPCondList
{
    CPCond* m_pkItem;
    CPCondList* m_pkNext;
    CPCond** FUN_006815c0();
    CPCondList* FUN_0062d990();
};

struct CPEntry
{
    CPCond* m_pkCond;
    void* m_pAssociatedData;
};

class CPNodeData
{
  public:
    int unk00[23];
    CPEntry m_aEntries[16];       // +0x5c
    unsigned int m_uiNumEntries;  // +0xdc
    CPTarget* GetCombatGoal(CPTarget* pkTarget);
};

class CPNode
{
  public:
    float m_fCost;
    int unk04;
    CPNodeData* m_pUserData;
    CPNode* TESMain_GetThread();
};

class CPGoals
{
  public:
    void FUN_006ecd40(class FUN_00995760_Aim* pkAim);
};

class CPOwner
{
  public:
    CPGoals* FUN_005e3fc0();
};

class CPAction
{
  public:
    virtual bool IsValid(CPOwner* pkOwner, CombatPlanner::WorldState* pkState, CPTarget* pkTarget);
    virtual void v01();
    virtual void v02();
    virtual float GetCost(CPOwner* pkOwner, CPTarget* pkTarget);

    bool HasFlags(bool bValue);
    bool CombatAction_HasTargetState(CPCond* pkCond);
    CPCondList* FUN_007d6bb0();
    CPCondList* FUN_00409140();
    CPCondList* GetOffsetC();
};

struct CPActionList
{
    CPAction* m_pkItem;
    CPActionList* m_pkNext;
    CPAction** FUN_006815c0();
    CPActionList* FUN_00726070();
};

CPActionList* CombatAction_GetActionsForTargetState(int iCond);
bool IsValidCode(CPTarget* pkTarget);

class FUN_00995760_Aim
{
  public:
    int m_iValue;
    FUN_00995760_Aim();
};

class FUN_004b0680_Pair
{
  public:
    int m_iKey;
    int m_iNext;
    FUN_004b0680_Pair(int iItem, int iNext);
};

class FUN_00994e60_State
{
  public:
    int unk00[57];
    FUN_00994e60_State(CombatPlanner::WorldState* pkState);
    int CombatWorldStateArray_GetStateValue(CPTarget* pkFrom, CPTarget* pkTo);
    void CombatWorldStateArray_ApplyWorldState(int iCond, int iCondValue);
    bool CombatWorldStateArray_IsTrue(int iCond, int iCondValue);
    void AppendPair(FUN_004b0680_Pair* pkPair, void* pvValue);
};

class FUN_00995780_Plan
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int m_iAim;
    FUN_00995780_Plan(CPAction* pkAction, CPTarget* pkTarget, void* pvValue);
};

struct CPOutItem
{
    int unk00;
    float m_fCost;
    FUN_00994e60_State* m_pkState;
    FUN_00995780_Plan* m_pkPlan;
};

class CPOutArray
{
  public:
    void BSSimpleArray_TESObjectREFR_1024_SetReservedSize(unsigned int uiSize);
    void FUN_007cb2e0(CPOutItem*& rpkItem);
    void FUN_008454f0(bool bFree);
};

// @fnv 0x009950c0
bool CombatPlanner::ExpandNode(CPNode* pkNode, CPOutArray* pkOut)
{
    float m_fPathingCostCur = pkNode->m_fCost;
    bool bFirst = (pkNode->TESMain_GetThread() == 0) ? true : false;
    if (bFirst)
        pkOut->BSSimpleArray_TESObjectREFR_1024_SetReservedSize(0x10);

    for (unsigned int i = 0; i < pkNode->m_pUserData->m_uiNumEntries; i++)
    {
        CPCond* pkCond = pkNode->m_pUserData->m_aEntries[i].m_pkCond;
        CPActionList* pkNodeIter = CombatAction_GetActionsForTargetState(pkCond->Modelloader_GetReferencedThis());
        bool bFound = false;
        while (pkNodeIter && *pkNodeIter->FUN_006815c0())
        {
            CPAction* pkAction = *pkNodeIter->FUN_006815c0();
            if (!pkAction->HasFlags(true) || bFirst)
            {
                bool bValid = pkAction->CombatAction_HasTargetState(pkCond);
                CPTarget* pkTarget = pkCond->FUN_00726070();
                if (IsValidCode(pkTarget))
                    pkTarget = pkNode->m_pUserData->GetCombatGoal(pkTarget);
                FUN_00995760_Aim kAim;
                ((CPOwner*)field_2058)->FUN_005e3fc0()->FUN_006ecd40(&kAim);
                if (bValid)
                {
                    if (pkAction->IsValid(((CPOwner*)field_2058), &field_205c, pkTarget))
                    {
                        float fActionCost = pkAction->GetCost(((CPOwner*)field_2058), pkTarget);
                        if (fActionCost < DAT_0108dbf0)
                        {
                            FUN_00994e60_State* pkState =
                                new (field_20b8.ScrapHeap_Allocate(sizeof(FUN_00994e60_State), DAT_010a2720))
                                    FUN_00994e60_State(&field_205c);

                            CPCondList* pkEffect = pkAction->FUN_007d6bb0();
                            while (pkEffect && *pkEffect->FUN_006815c0())
                            {
                                CPCond* pkEffectCond = *pkEffect->FUN_006815c0();
                                int iCondValue = pkState->CombatWorldStateArray_GetStateValue(pkEffectCond->FUN_00726070(), pkTarget);
                                pkState->CombatWorldStateArray_ApplyWorldState(pkEffectCond->Modelloader_GetReferencedThis(), iCondValue);
                                pkEffect = pkEffect->FUN_0062d990();
                            }

                            CPCondList* pkSide = pkAction->FUN_00409140();
                            while (pkSide && *pkSide->FUN_006815c0())
                            {
                                CPCond* pkSideCond = *pkSide->FUN_006815c0();
                                int iCondValue = pkState->CombatWorldStateArray_GetStateValue(pkSideCond->FUN_00726070(), pkTarget);
                                pkState->CombatWorldStateArray_ApplyWorldState(pkSideCond->Modelloader_GetReferencedThis(), iCondValue);
                                pkSide = pkSide->FUN_0062d990();
                            }

                            for (unsigned int j = 0; j < pkNode->m_pUserData->m_uiNumEntries; j++)
                            {
                                CPCond* pkGoalCond = pkNode->m_pUserData->m_aEntries[j].m_pkCond;
                                int iCondValue = pkState->CombatWorldStateArray_GetStateValue(pkGoalCond->FUN_00726070(), pkTarget);
                                if (!pkState->CombatWorldStateArray_IsTrue(pkGoalCond->Modelloader_GetReferencedThis(), iCondValue))
                                    pkState->AppendPair(
                                        new (field_20b8.ScrapHeap_Allocate(sizeof(FUN_004b0680_Pair), DAT_010a2720))
                                            FUN_004b0680_Pair(pkGoalCond->Modelloader_GetReferencedThis(), iCondValue),
                                        pkNode->m_pUserData->m_aEntries[j].m_pAssociatedData);
                            }

                            CPCondList* pkRequire = pkAction->GetOffsetC();
                            while (pkRequire && *pkRequire->FUN_006815c0())
                            {
                                CPCond* pkPreCond = *pkRequire->FUN_006815c0();
                                int iCondValue = pkState->CombatWorldStateArray_GetStateValue(pkPreCond->FUN_00726070(), pkTarget);
                                if (!pkState->CombatWorldStateArray_IsTrue(pkPreCond->Modelloader_GetReferencedThis(), iCondValue))
                                    pkState->AppendPair(
                                        new (field_20b8.ScrapHeap_Allocate(sizeof(FUN_004b0680_Pair), DAT_010a2720))
                                            FUN_004b0680_Pair(pkPreCond->Modelloader_GetReferencedThis(), iCondValue),
                                        pkState);
                                pkRequire = pkRequire->FUN_0062d990();
                            }

                            fActionCost += m_fPathingCostCur;
                            bFound = true;
                            int iState = CombatPlanner_GetNodeKey(&pkState);
                            CPOutItem* pkResult;
                            switch (FUN_006b8fe0(iState, fActionCost, &pkResult))
                            {
                            case 0:
                                pkResult->m_pkState = pkState;
                                pkResult->m_fCost = 0.0f;
                            case 1: {
                                FUN_00995780_Plan* pkPlan =
                                    new (field_20b8.ScrapHeap_Allocate(sizeof(FUN_00995780_Plan), DAT_010a2720))
                                        FUN_00995780_Plan(pkAction, pkTarget,
                                                          pkNode->m_pUserData->m_aEntries[i].m_pAssociatedData);
                                pkPlan->m_iAim = kAim.m_iValue;
                                pkResult->m_pkPlan = pkPlan;
                                pkOut->FUN_007cb2e0(pkResult);
                            }
                            break;
                            }
                        }
                    }
                }
            }
            pkNodeIter = pkNodeIter->FUN_00726070();
        }
        if (!bFound)
        {
            pkOut->FUN_008454f0(false);
            return false;
        }
    }
    return true;
}
