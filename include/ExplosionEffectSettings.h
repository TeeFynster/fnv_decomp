#pragma once

#include "BaseProcess.h"

class TESObjectLIGH;
class TESSound;
class BGSImpactDataSet;

class ExplosionEffectSettings
{
public:
    float fForce;
    float afDamageAmount;
    float fRadius;
    TESObjectLIGH* apTargetLight;
    TESSound* m_pPrimaryImpactSound;
    unsigned int iFlags;
    float ExplosionRuntimeData;
    BGSImpactDataSet* m_pImpactDataSet;
    TESSound* m_pSecondaryImpactSound;
    float ImpactSoundSettings;
    float m_fImpactSecondValue;
    float m_fImpactThirdValue;
    SOUND_LEVEL m_eSoundLevel;

    // 0x004faa00: calls InitExplosionData (BGSExplosion::ResetFormData calls it on its Data member)
    void Object_ProcessAndReturnValue_004faa00();
    void InitExplosionData();
};
