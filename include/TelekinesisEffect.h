#pragma once

#include "ValueModifierEffect.h"
#include "GO.h"

class TESObjectREFR;

class __declspec(novtable) TelekinesisEffect : public ValueModifierEffect
{
public:
    virtual ~TelekinesisEffect();
    virtual ActiveEffect* Copy();
    virtual void Update(float delta);
    virtual unsigned short GetSaveSize(Actor* apActor);
    virtual void SaveGame(Actor* apActor);
    virtual void LoadGame(Actor* apActor);
    virtual void FinishLoadGameTES(Actor* apActor);
    virtual bool CanApply(MagicCaster* apCaster);
    virtual void CopyData(ActiveEffect* other);
    virtual void Start();
    virtual void Finish();

    GO m_4c;
    union
    {
        float m_50;
        float magnitude;
        float strength;
    };
    union
    {
        float m_54;
        float velocity;
        float m_fHitDistance;
    };
    union
    {
        TESObjectREFR* target;
        int m_58;
        unsigned int unk58;
    };
    union
    {
        unsigned char m_5c;
        bool released;
        bool m_bHolding;
    };
    union
    {
        unsigned char m_5d;
        bool skipCost;
    };

    TelekinesisEffect(int a, int b, int c);
    TelekinesisEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect);

    void FUN_0082a540();
    unsigned short __thiscall GetSaveSize_0082b190(Actor* apActor);
    void LoadFromSave(Actor* apActor);
    void SaveLoad(Actor* apActor);
    ActiveEffect* CreateCopy();
    void UpdateGrabEffect(float delta);
    void __thiscall StartTelekinesisEffect();
    void __thiscall Start_0082a670();
    void __thiscall Finish_0082af60();
    void FinishInitLoadGame_0082b300(Actor* apActor);
    void __thiscall RemoveSpring();
};
