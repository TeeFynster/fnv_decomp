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

    void* FUN_00575ca0();
    CombatWorld* FUN_00575650(CombatWorld*);
    unsigned char FUN_004997b0();
    bool FUN_00894900();
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
    unsigned char FUN_008bffc0();
    CombatActor* FUN_0044ddc0();
    void* FUN_009344a0();
    int FUN_008f25e0(int);
    void CopyScaleAndResetItems(CombatActor*);
    void FUN_008a6ce0(int, int);
    CombatStyleHandler* GetCurrentHandler();
    void ResetHandler();
};
