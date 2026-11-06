#pragma once

#include "CombatProcedure.h"
#include "CombatTargetTimestamp.h"
#ifndef COMBATPROCEDUREATTACKMELEE_TIMER_H
#include "TimeoutTimer.h"
#endif

class Actor;
class CombatVec3;
class MeleeDebugOutput;
class NiPoint3;

class CombatProcedureAttackMelee : public CombatProcedure
{
public:
    struct CombatMeleeData
    {
        CombatMeleeData();
        int unk00;
    };

    CombatProcedureAttackMelee();
    virtual ~CombatProcedureAttackMelee();
    virtual void Unk04();
    virtual void Unk08(CombatController*);
    virtual void Unk0c();
    virtual void d05();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void vf16();

    int ChooseMeleeAttack(bool abMidAttack, float afDistance, float afReach,
                          bool abTargetAttacking, bool abTargetPostAttack,
                          bool abTargetRecoiling, bool* abDoPowerAttack,
                          bool* abSwitchAttack);
    int FUN_009ccb20(bool abMidAttack, float afDistance, float afReach,
                     bool abTargetAttacking, bool abTargetPostAttack,
                     bool abTargetRecoiling, bool* abDoPowerAttack,
                     bool* abSwitchAttack);

    void RunCombatProcedure();
    void UpdateCombatState();
    void FUN_009cc510();
    void FUN_009cce70(int attack, int arg2);
    void FUN_009cced0();
    void FUN_009ccfb0();
    void FUN_009cd150();
    void FUN_009cd3d0();
    void FUN_009cd410();
    void FUN_009cd430();
    void FUN_009cd5e0();
    void UpdateDodge();
    void EvaluateReaction();
    void UpdateState();
    void FUN_009cde10();
    void FUN_009cdf00();
    void UpdateCombatMovement();
    void UpdateMeleeCombat();
    void FUN_009ce190();
    float FUN_009ce560();
    void FUN_009ce5b0(CombatVec3* position);
    int FUN_009ce870(float distance, float reach, bool targetAttacking,
                     bool targetMidAttack, int arg5);
    bool IsWithinThreshold(float value, float limit, int unused);
    char IsWithinThreshold(float value, float limit, float unused);
    unsigned char FUN_009cf030(float distance, float reach, int unused);
    void TryAttackTarget(float arg1, float arg2);
    bool IsActionAvailable(unsigned action);
    bool IsActionAvailable(int action);
    void SetMode(int mode);
    void FUN_009cf6d0(int arg);
    void PrintDebugInfo(MeleeDebugOutput* output, int x, int y);
    char FUN_009cfbd0(unsigned short mask);
    bool FUN_009cfbd0(int mask);
    void FUN_009cfc00();
    void FUN_009cfc60();
    float GetModifierValue();
    bool IsTargetOutOfRange();
    float FUN_009cfe90();
    void StopIfSpeakerOutOfRange();

    Actor* FUN_00996de0();
    Actor* FUN_00996e00();
    void FUN_00996e20(int);
    void FUN_00996ea0();
    void SetLookAtPoint(NiPoint3*, int);
    void FUN_009caac0(const char*);
    int FUN_00825c00();
    int FUN_0044edb0();
    int GetSection();
    int GetAudioBackendData();

    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    TimeoutTimer pt20;
    TimeoutTimer pt28;
    TimeoutTimer pt30;
    TimeoutTimer pt38;
    TimeoutTimer pt40;
    TimeoutTimer pt48;
    bool unk50;
    unsigned char unk51[3];
    int unk54;
    float unk58;
    float unk5C;
    CombatTargetTimestamp val60;
    CombatMeleeData data64;
    unsigned char unk68[0x20];
};
