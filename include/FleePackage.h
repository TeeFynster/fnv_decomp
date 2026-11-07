#pragma once

#include "TESPackage.h"
#include "BSSimpleList.h"
#include "NiPoint3.h"

class A;
class AvoidanceContext;
class BGSSaveFormBuffer;
class PathingAvoidNodeArray;
class PackageTargetD09;

namespace FleeUpdate
{
    class Process;
    class Target;
}

class FleePackage : public TESPackage
{
public:
    FleePackage(Actor* actor, TESForm* form, TESObjectCELL* cell, int arg);
    virtual ~FleePackage();

    virtual void SaveGame(BGSSaveFormBuffer* arg);
    virtual void LoadGame(BGSLoadFormBuffer* arg);
    virtual void Unk_19(void* arg);
    virtual unsigned short GetSaveSize();
    virtual unsigned short SaveGameTESAlt();
    virtual unsigned short LoadGameTESAlt();
    virtual void InitLoadGameTES();

    unsigned char flag80;
    unsigned char flag81;
    unsigned short unk82;
    NiPoint3 position;
    float timer;
    unsigned char flag94;
    unsigned char unk95[3];
    BSSimpleList<TESObjectREFR*> AvoidedRefList;
    TESObjectREFR* pRefA0;
    TESObjectREFR* pRefA4;
    unsigned char flagA8;
    unsigned char flagA9;

    bool MobileObject_IsTalkingActivator(); // 0x00574900
    Actor* GetAVEffect(); // 0x004fd400
    bool GetByteAt94(); // 0x008df020
    bool GetField0xA8(); // 0x008b6240
    bool FUN_008df040(); // 0x008df040
    void FUN_00994ef0(Actor*); // 0x00994ef0
    void BGSTerminal_SetPassword(Actor*); // 0x00500a20
    void AddAvoidedReference(Actor* actor);
    void AddAvoidedRef(TESObjectREFR* reference);
    void AddAvoidedRef(Actor* target);
    void AddAvoidedRef(A* target);
    PackageTargetD09* FUN_0055b980();
    void SetEvaluatePoint(int iArg);

    void RemoveInvalidAvoidedReferences(FleeUpdate::Process* process);
    FleeUpdate::Target* FUN_00671d10();
    float GetField90Float();
    Actor* FindNearestRef(Actor* actor);
    void bhkCharacterControllerCinfo_SetAvoidBox(int state);
    void FleePackage_ModFleeTimer(float elapsed);
    Actor* FUN_005e3fc0();
    void FindTeleportDoor(Actor* actor, Actor* target);
    using TESPackage::FUN_00676280;
    unsigned int FUN_00676280(Actor* actor);
    PathingAvoidNodeArray* BuildAvoidNodeArray();

    using TESPackage::LoadGame;
    void RemoveRef(TESObjectREFR* reference);
    void RemoveInvalidAvoidedReferences(AvoidanceContext* context);
    TESObjectREFR* FindNearestRef(TESObjectREFR* reference);
    bool FindTeleportDoor(TESObjectREFR* reference, TESObjectREFR* context);
    bool ShouldShutDown();
    void SaveExtraData(BGSSaveFormBuffer* buffer);
    void LoadGame_009f24d0(BGSLoadFormBuffer* buffer);
    void SaveFleePackage();
    void LoadGame_009f1e80();
    void InitLoadGame_009f25f0(void* buffer);
};
