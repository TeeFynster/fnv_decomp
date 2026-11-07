#pragma once

#include "ActiveEffect.h"
#include "NiPointLight.h"

class LightEffect : public ActiveEffect
{
public:
    LightEffect(void* caster, void* item, void* effect);

    virtual ~LightEffect();
    virtual ActiveEffect* Copy();
    virtual void Update(float afElapsedSeconds);
    virtual void FinishLoadGameTES(Actor* apActor);
    virtual void Revert(Actor* apActor);
    virtual void Revert(BGSLoadFormBuffer* apBuffer);
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer* apBuffer);
    virtual void CopyData(ActiveEffect* apOther);
    virtual void Start();
    virtual void Finish();

    float GetFloatAtOffset1C();
    void AttachLightEffect();
    void FUN_0080f030(Actor* apActor);
    void DetachLight();

    NiPointer<NiPointLight> m_spLight;
};
