#pragma once

#include "TESForm.h"
#include "ImageSpaceModifierEffectData.h"
#include "NiFloatInterpolator.h"
#include "NiColorInterpolator.h"

class TESSound;
class TimedFloatKey;
class AlphaColor;

class TESImageSpaceModifier : public TESForm
{
public:
    typedef ::ImageSpaceModifierEffectData ImageSpaceModifierEffectData;

    TESImageSpaceModifier();
    TESImageSpaceModifier& operator=(const TESImageSpaceModifier&);
    virtual ~TESImageSpaceModifier();
    virtual void ClearData();
    virtual void InitItem();
    virtual bool Compare(TESForm* form);

    void __vslot_10();
    bool Load(TESFile* file);
    void Save();
    void Copy(TESForm* form);
    void ResetFormData();
    bool GetAnimatable();
    float GetDuration();
    void SetAnimatable(bool animatable);
    void SetDuration(float duration);
    static void SetEnable(bool enable);
    static bool GetEnable();
    void Apply(float startTime, float strength, NiAVObject* target);
    void EvaluateInterpolators(float startTime, float strength);
    bool IsExpired(float startTime);
    static void BlendModifiers(float blendWeight, TESImageSpaceModifier* lastModifier,
                               TESImageSpaceModifier* modifier, float modifierBlendWeight,
                               float time, NiAVObject* coordinate, NiAVObject* target);
    bool RemoveFloatKey(NiFloatInterpolator* interpolator);
    bool RemoveColorKey(NiColorInterpolator* interpolator);
    void MakeFloatKeyDefault(NiFloatInterpolator* interpolator, float value);
    void MakeColorKeyDefault(NiColorInterpolator* interpolator);
    void ResetInterpolators();
    bool HasValidKeys();
    bool AreKeysValid(NiAnimationKey* keys, unsigned int count, unsigned char type);
    TESSound* GetIntroSound();
    TESSound* GetOutroSound();
    static void SetCurrentTime(float time);
    static float GetTickCount();
    static void AdvanceCurrentTime(float time);
    void InitializeModifierData();
    static void AllowGetHit(bool allow);
    static TESImageSpaceModifier* GetGetHit();
    static TESImageSpaceModifier* GetConcussionModifier();
    static TESImageSpaceModifier* GetExplosionInFace();
    static TESImageSpaceModifier* QDefault();

    TESSound* pOutroSound;
    TESSound* pIntroSound;
    ImageSpaceModifierEffectData Data;
    NiFloatInterpolator m_akFloatInterpolators[21][2];
    NiFloatInterpolator m_kFloatInterpolatorOne;
    NiFloatInterpolator m_kFloatInterpolatorTwo;
    NiColorInterpolator m_kColorInterpolatorOne;
    NiColorInterpolator m_kColorInterpolatorTwo;
    NiFloatInterpolator m_kFloatInterpolatorNine;
    NiFloatInterpolator m_kFloatInterpolatorTen;
    NiFloatInterpolator m_kFloatInterpolatorEleven;
    NiFloatInterpolator m_kFloatInterpolatorThree;
    NiFloatInterpolator m_kFloatInterpolatorFour;
    NiFloatInterpolator m_kFloatInterpolatorFive;
    NiFloatInterpolator m_kFloatInterpolatorSix;
    NiFloatInterpolator m_kFloatInterpolatorSeven;
    NiFloatInterpolator m_kFloatInterpolatorEight;
    TimedFloatKey* pEffectEntryTable[21][2];
    TimedFloatKey* pSecondEffectEntries;
    TimedFloatKey* pThirdEffectEntries;
    AlphaColor* pFirstEffectRecordArray;
    AlphaColor* pSecondEffectRecordArray;
    TimedFloatKey* pTenthEffectEntries;
    TimedFloatKey* pEleventhEffectEntries;
    TimedFloatKey* pTwelfthEffectEntries;
    TimedFloatKey* pFourthEffectEntries;
    TimedFloatKey* pFifthEffectEntries;
    TimedFloatKey* pSeventhEffectEntries;
    TimedFloatKey* pEighthEffectEntries;
    TimedFloatKey* pNinthEffectEntries;
    TimedFloatKey* pSixthEffectEntries;
};
