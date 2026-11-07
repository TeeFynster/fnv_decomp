#pragma once

#include "ActiveEffect.h"

class SunDamageEffect : public ActiveEffect
{
public:
    static void* operator new(unsigned int size);
    static void operator delete(void* p);

    SunDamageEffect(MagicCaster*, MagicItem*, EffectItem*);

    ActiveEffect* Copy() override;
    unsigned short GetSaveSize(Actor* apActor) override;
    void SaveGame(Actor* apActor) override;

    void LoadGame(Actor* apActor) override;
    void UpdateEffect(float arg);
    bool IsCausingDamage();
    double GetDamageAmount();
    void UpdateHitEffect(bool abApply);
    int FUN_0055b980();

    float fValue;
    bool bFlag4C;
    bool bFlag4D;
};
