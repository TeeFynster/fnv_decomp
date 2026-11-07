#pragma once

#include "ValueModifierEffect.h"

class ChameleonEffect : public ValueModifierEffect
{
public:
    ChameleonEffect(void* caster, void* item, void* effect);

    virtual ~ChameleonEffect();
    virtual ActiveEffect* Copy();
    virtual void FinishLoadGameTES(Actor* actor);
    virtual void Revert(Actor* apActor);
    virtual void Revert(BGSLoadFormBuffer* apBuffer);
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer* apBuffer);
    virtual void Start();
    virtual void Finish();

    void Revert_0080b1b0(Actor* apActor);
    void Revert_0080b310(BGSLoadFormBuffer* apActor);
    void FinishInitLoadGame_0080b0c0(Actor* actor);
    void FinishLoadGame(BGSLoadFormBuffer* target);
    void Finish_0080aef0();
    void UpdateChameleonEffect();
    ChameleonEffect* Clone();
    void CopyTo(ChameleonEffect* pkCopy);
};
