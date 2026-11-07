#pragma once

class Effect;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;
class CombatController;

class CombatPlan
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    CombatPlan(CombatController* controller);
    ~CombatPlan();

    bool __thiscall CombatController_CombatPlanContainsAction(int aiAction);
    Effect* __thiscall FUN_004fd3e0();
    void __thiscall SetFieldE0(float f);
    void SaveToBuffer(BGSSaveFormBuffer*);
    void ReadFromStream(BGSLoadFormBuffer* buffer);
    bool CombatPlan_IsFinished();
    void* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    bool AdvanceActions(CombatController* controller);
    void Revert(BGSLoadFormBuffer* buffer);
};
