#pragma once

class CombatActorVtable;
class CombatWorld;
class PackageView;
class ProcessView;
class ExtraView;
class ActorBaseView;
class FactionView;
class CombatStyleHandler;

class CombatActor
{
public:
    CombatActorVtable* vtable;

    void* TESObjectREFR_GetSpace();
    CombatWorld* TESObjectREFR_GetWorldLocation(CombatWorld*);
    unsigned char FUN_004997b0();
    bool Actor_IsAttacking();
    bool HasTarget(CombatActor*);
    bool HasPackage();
    PackageView* Package();
    void Stop(int);
    ProcessView* Process();
    void Reset();
    ExtraView* Extra();
    ActorBaseView* Base();
    unsigned Gather(FactionView**, unsigned, void*, void*);
    unsigned char FUN_00566950();
    unsigned char IsHostileTo(void* target, int mode, int* result, unsigned char check);
    unsigned char Actor_IsAngryWithPlayer();
    CombatActor* FUN_0044ddc0();
    void* FUN_009344a0();
    int FUN_008f25e0(int);
    void CopyScaleAndResetItems(CombatActor*);
    void Actor_EvaluatePackage(int, int);
    CombatStyleHandler* GetCurrentHandler();
    void ResetHandler();
};
