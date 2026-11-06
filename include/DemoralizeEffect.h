#pragma once

#include "ActiveEffect.h"

class DemoralizeEffect : public ActiveEffect
{
public:
    DemoralizeEffect(MagicCaster*, MagicItem*, EffectItem*);

    ActiveEffect* Copy() override;
    unsigned short GetSaveSize(Actor*) override;
    void SaveGame(Actor*) override;
    bool IsEffectValid(MagicTarget*) override;
    void Start() override;
    void Finish() override;

    MagicCaster* FUN_0045cd60();
    static void* operator new(unsigned int);
    static void operator delete(void*);

    unsigned char m_bDemoralized;
};
