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

    bool __thiscall FUN_00981940(int aiAction);
    Effect* __thiscall FUN_004fd3e0();
    void __thiscall SetFieldE0(float f);
    void SaveToBuffer(BGSSaveFormBuffer*);
    void ReadFromStream(BGSLoadFormBuffer* buffer);
    bool FUN_0097e490();
    void* FUN_0084e3a0();
    bool AdvanceActions(CombatController* controller);
    void Revert(BGSLoadFormBuffer* buffer);
};
