#pragma once

#include "ValueModifierEffect.h"

class FrenzyEffect : public ValueModifierEffect
{
public:
    FrenzyEffect(void* a, void* b, void* c);

    virtual ActiveEffect* Copy();
    virtual unsigned short GetSaveSize(Actor* apActor);
    virtual void SaveGame(Actor* apActor);
    virtual void LoadGame(Actor* apActor);
    virtual bool IsEffectValid(MagicTarget* apTarget);
    virtual void Start();
    virtual void Finish();

    unsigned short __thiscall GetSaveSize_0080df90(Actor* apActor);
    void* __thiscall ConstructFrenzyEffect(void* a, void* b, void* c);
    FrenzyEffect* Copy_0080dbf0();
    void __thiscall SaveGame_0080dfd0(Actor* apActor);
    void LoadGame_0080e000(Actor* apActor);
    bool CheckTarget_0080dca0(MagicTarget* apTarget);
    void Start_0080dd30();
    void Finish_0080ddd0();

    unsigned char exhausted;
};
