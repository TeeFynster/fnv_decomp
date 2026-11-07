#pragma once

#include "BSTempEffect.h"
#include "GO.h"
#include "NiTransform.h"
#ifndef FNV_BSSOUNDHANDLE_H
#include "BSSoundHandle.h"
#endif

class ParticleObj;
class ParticleSource;
class TraversalItem;
class ArrQ;
class Matrix;
class NiPoint3;
class Block9;
class Block3;
class Parent;
class Obj;

class BSTempEffectParticle : public BSTempEffect
{
  public:
    BSTempEffectParticle(TESObjectCELL* cell, float radius, const char* filename, void* node);
    virtual ~BSTempEffectParticle();
    virtual const NiRTTI* GetRTTI() const;
    virtual void Detach();
    virtual bool Update(float afTime);
#ifndef PROCESSLISTS_PRIVATE_BSTEMPEFFECT_H
    virtual bool IsSaveable();
    virtual unsigned short GetSaveSize();
    using BSTempEffect::SaveGame;
    using BSTempEffect::LoadGame;
    virtual void SaveGame();
    virtual bool LoadGame();
#else
    void SaveGame();
    bool LoadGame();
#endif

    ParticleObj* GetParticleObject();
    ParticleSource* GetSource();
    void SetParentCell(TESObjectCELL* apCell);
    bool CheckShouldSave();
    void PlaySequence(const char* name);
    void Detach_006896c0();
    bool UpdateTransform(float time);
    bool LoadFromSave();

    void StopSounds();
    void InitLoopSounds();
    void PlayImpactDataSounds(void* pValue);
    void BSTempEffectParticle_ResetGravity(void* searchArg);
    void AttachModel(NiNode* parent, NiMatrix3 rotation, NiPoint3 position, float scale, unsigned int flags);
    void AttachModel(Parent* parent, NiMatrix3 rotation, NiPoint3 position, float scale, unsigned int flags);
    void AttachModel(void* parent, Matrix rotation, NiPoint3 position, float scale, int flags);
    void AttachModel(void* parent, Block9 rotation, Block3 position, float scale, unsigned int flags);
    float ComputeTraversalValue(TraversalItem* entry);
    void CollectUniqueChildValues(NiNode* node, ArrQ* values, int* count);
    float Calc(Obj* object);
    void Setup(Obj* object);

    GO m_flt;
    const char* pFilename;
    GO m_20;
    NiTransform m_kMotionTransform;
    void* m_58;
    BSSoundHandle m_5c;
    BSSoundHandle m_68;
};
