#pragma once

#include "MagicHitEffect.h"
#include "NiAVObject.h"
#include "BGSLoadGameSubBuffer.h"

class MagicModelHitEffect : public MagicHitEffect
{
  public:
    MagicModelHitEffect(TESObjectREFR* apTarget, ActiveEffect* apEffect);
    MagicModelHitEffect(TESObjectREFR* apTarget, const char* apFilename, float afLifetime);
    virtual ~MagicModelHitEffect();
    virtual const NiRTTI* GetRTTI() const;

    virtual bool Update(float afTime);
    virtual int GetType();
    virtual bool IsSaveable();
    virtual unsigned short GetSaveSize();
    virtual void SaveGame();
    virtual void SaveGame(BGSSaveGameBuffer* apBuffer);
    virtual bool LoadGame();
    virtual void LoadGame(BGSLoadGameBuffer* apBuffer);
    virtual void InitLoadGame(BGSLoadGameBuffer* apBuffer);
    virtual void ApplyLoadBuffer(BGSLoadGameBuffer* apBuffer);
    virtual bool Init();
    virtual void AttachToTarget();
    virtual unsigned short GetSaveSize(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    virtual void SaveGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    virtual void LoadGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    virtual void InitLoadGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    virtual void FinishLoadGameTES(ActiveEffect* apEffect, TESObjectREFR* apTarget, void* apData);

    bool m_bFirstPerson;
    bool b3rdPerson;
    unsigned char layoutPadding2A[2];
    const char* pFilename;
    NiPointer<NiAVObject> spRetainedObject;
    NiPointer<NiAVObject> m_spTargetObject;
    BGSLoadGameSubBuffer m_kLoadGameSubBuffer;
};
