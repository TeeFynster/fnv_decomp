#pragma once

#include "BSTempEffect.h"

class ActiveEffect;
class TESObjectREFR;
template <class T> class BSSimpleList;

class MagicHitEffect : public BSTempEffect
{
  public:
    MagicHitEffect();
    MagicHitEffect(TESObjectREFR* apTarget, ActiveEffect* apEffect);
    virtual ~MagicHitEffect();
    virtual int GetType();

    virtual bool Init();
    virtual void ResetTargetPointer();
    virtual void AttachToTarget();
    virtual unsigned short GetSaveSize(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    virtual void SaveGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    virtual void LoadGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    virtual void InitLoadGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    virtual void FinishLoadGameTES(ActiveEffect* apEffect, TESObjectREFR* apTarget, void* apData);

    static BSSimpleList<MagicHitEffect*>* GetEffectsForActiveEffect(ActiveEffect* apEffect);
    char* GetData();
    void SetByteAt24(unsigned int value);
    void FUN_00984f60(unsigned int);

    ActiveEffect* pEffect;
    TESObjectREFR* pTarget;
    float m_fFirstFloatValue;
    bool bWasPlaying;
    unsigned char layoutPadding25[3];
};
