#pragma once

#include "NiExtraData.h"
#include "BSFaceGenKeyframeMultiple.h"
#include "NiTPointerList.h"
#include "NiPoint3.h"
#include "RecursiveSpinLock.h"

class NiQuaternion;
enum BS_FACEGEN_MORPH_TYPE;
enum BS_FACEGEN_EXPRESSION;
enum BS_FACEGEN_PHONEME;
enum BS_FACEGEN_CUSTOM_MORPH;
struct BS_FACEGEN_MODIFIER;

class BSFaceGenAnimationData : public NiExtraData
{
  public:
    BSFaceGenAnimationData();
    virtual ~BSFaceGenAnimationData();
    virtual const NiRTTI* GetRTTI() const;

    virtual float GetExpressionWeight(BS_FACEGEN_EXPRESSION expression);
    virtual void SetExpressionValue(int, float);
    virtual bool CalculateRotationQuaternion(NiQuaternion& rotation);
    virtual void SetModifierValue(int, float);
    virtual float GetPhonemeWeight(BS_FACEGEN_PHONEME phoneme);
    virtual void SetPhonemeValue(int, float);
    virtual float GetCustomMorphWeight(BS_FACEGEN_CUSTOM_MORPH morph);
    virtual void SetCustomMorphValue(BS_FACEGEN_CUSTOM_MORPH, float);
    virtual void vfn_b4(float, bool, bool, bool, bool, bool);
    virtual void SetTransitionDuration(float duration);
    virtual void FadeOutMorphs(float, bool, bool, bool, bool);
    virtual void SetHeadTrackVector(float, float, float, int);
    virtual void Reset(bool);
    virtual bool UpdateMorphs();
    virtual bool NeedsUpdate();
    virtual void SetUpdated(bool value);
    virtual bool IsDead();
    virtual void SetStateFlags(bool, bool);
    virtual void SetExpressionValue_00649be0(int, float);
    virtual void SetModifierKeyframeValue(BS_FACEGEN_MODIFIER, float);
    virtual void SetPhonemeValue_00649c40(int, float);
    virtual void SetCustomMorphKeyframeValue(int, float);
    virtual void InsertPhonemeKeyframe(float* phonemes, float duration);
    virtual void AddModifierKeyframe(float* modifiers, float duration);
    virtual void AddKeyframe(BS_FACEGEN_MORPH_TYPE type, float duration, bool clear);
    virtual void vfn_f8(BS_FACEGEN_MORPH_TYPE, float, bool);
    virtual void SetMorphFlags(bool, bool, bool, bool);
    virtual void vfn_100(bool, bool, bool, bool);
    virtual void vfn_104(bool, bool, bool, bool);
    virtual unsigned char Check(int);
    virtual void vfn_10c();
    virtual void SetKeyframeQuantities(float*, float);
    virtual void SetExpressionWeight(int, float);
    virtual void SetExpressionKeyframes(float*);
    virtual void SetMoodExpression(int, bool);
    virtual void ClearTransitionTarget();
    virtual void vf73();
    virtual bool UpdateAnimation(float);
    virtual void vf75();

    void ResetFaceGenAnimationData(float, bool, bool, bool, bool, bool);
    void ResetFaceGenData(float, bool, bool, bool, bool, bool);
    bool UpdateFaceGenAnimation(float);
    void ClearLists(bool, bool, bool, bool);
    void BSFaceGenAnimationData_SetShouldHeadTrack(bool);
    bool BSFaceGenAnimationData_UpdateEyeTracking(float, unsigned int);
    float BSFaceGenAnimationData_GetModifierValue(int);
    bool GetChanged();
    void SetModified(bool);
    bool GetDead();
    void Update(float, bool, bool, bool, bool, bool);
    bool IsActive();
    void vfn_120();
    void IncRefCount();
    void DecRefCount();
    void FUN_00712e60(void*);

    struct AnimationState
    {
        NiPoint3 pt;
        float f130;
        float f134;
        float f138;
        float f13c;
        float f140;
        float f144;
        int i148;
        bool b14c;
        bool b14d;
        bool b14e;
        bool b14f;
        float f150;
        float f154;
        float f158;
        float f15c;
        float f160;
        float f164;
        float f168;
        float f16c;
        float f170;
        int i174;
        float f178;
        float f17c;
        int unk180;
        int unk184;
        bool b188;
        bool b189;
        bool b18a;
        bool b18b;
        bool b18c;
        bool b18d;
        bool b18e;
        bool b18f;
        bool b190;
        bool b191;
        bool b192;
        bool b193;
        float f194;
        int unk198;
        int unk19c;

        AnimationState();
    };

    BSFaceGenKeyframeMultiple* target;
    union
    {
        struct
        {
            char data[0x179];
            bool changed;
            bool p18a;
            bool dirty;
            bool p18c;
            bool p18d;
            bool dead;
        };
        struct
        {
            BSFaceGenKeyframeMultiple kf10;
            BSFaceGenKeyframeMultiple kf24;
            BSFaceGenKeyframeMultiple kf38;
            BSFaceGenKeyframeMultiple kf4c;
            BSFaceGenKeyframeMultiple kf60;
            BSFaceGenKeyframeMultiple kf74;
            NiTPointerList<BSFaceGenKeyframe*> obj88;
            BSFaceGenKeyframeMultiple kf94;
            BSFaceGenKeyframeMultiple kfa8;
            NiTPointerList<BSFaceGenKeyframe*> objbc;
            BSFaceGenKeyframeMultiple kfc8;
            BSFaceGenKeyframeMultiple kfdc;
            NiTPointerList<BSFaceGenKeyframe*> objf0;
            BSFaceGenKeyframeMultiple kffc;
            BSFaceGenKeyframeMultiple kf110;
            AnimationState unk124;
        };
    };
    RecursiveSpinLock unk1a0;
};
