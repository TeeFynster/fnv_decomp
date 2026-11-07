#pragma once

#include "ValueModifierEffect.h"
#include "NiAVObject.h"

class AbsorbEffect : public ValueModifierEffect
{
public:
    virtual ~AbsorbEffect();
    virtual ActiveEffect* Copy();
    virtual void Update(float delta);
    virtual void FinishLoadGameTES(Actor* actor);
    virtual bool CanApply(MagicCaster* apCaster);
    virtual void CopyData(ActiveEffect* other);
    virtual void Start();
    virtual void Finish();

    NiPointer<NiAVObject> spBolt;
    NiPointer<NiAVObject> spNode50;
    NiPointer<NiAVObject> spNode54;
    NiPointer<NiAVObject> m_spTargetObject;

    AbsorbEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect);
    void __thiscall InitBoltEffect();
    void __thiscall FinishInitLoadGame(Actor* apActor);
    void CopyData_0082a650(ActiveEffect* apDestination);
    void FUN_00802e20();
    void* __thiscall Destroy(unsigned int flags);
    void Update3D_00803b70(float value);
};
