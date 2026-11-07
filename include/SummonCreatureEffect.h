#pragma once

#include "AssociatedItemEffect.h"
#include "NiPoint3.h"

class SelectedRecord;
class SummonOwner;

class SummonCreatureEffect : public AssociatedItemEffect
{
public:
    SummonCreatureEffect(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
    virtual ~SummonCreatureEffect();

    virtual ActiveEffect* Copy();
    virtual void Update(float afElapsedSeconds);
    virtual unsigned short GetSaveSize(Actor* apActor);
    virtual void SaveGame(Actor* apActor);
    virtual void LoadGame(Actor* apActor);
    virtual void InitLoadGame(Actor* apActor);
    virtual void Start();
    virtual void Finish();

    void FUN_00828590();
    void* FUN_00828560(unsigned int flags);
    SummonOwner* GetSummoner();
    void Unsummon();
    SummonCreatureEffect* CloneObject();
    void SpawnSummonedActor(Actor* actor);
    void SpawnSummonedActor(int unused);
    bool SelectRecord(void* context, int flags, SelectedRecord* output);
    bool SelectRecord(Actor* ref, int iUnk, NiPoint3* pPos);
    int __thiscall GetZero(int a, int b, int c);
    bool SummonCreatureEffect_CheckSummonLocation(int flags, SelectedRecord* record);
    void DispelOldestQualifyingEffect();
    void CleanupSummonedCreature();
    void LoadAssociatedItemEffect(Actor* actor);
    void Start_008287e0();
    void Update_00828ba0(int unused);
    unsigned short __thiscall GetSaveSize_00829720(Actor* actor);
    void SaveGame_008297a0(int value);
    void InitLoadGame_00829900(void* arg);

    Actor* unk4C;
    unsigned char unk50;
    unsigned char unk51[3];
    float unk54;
    NiPoint3 unk58;
    NiPoint3 unk64;
    unsigned char unk70;
    unsigned char unk71;
};
