#pragma once

#include "TESBoundAnimObject.h"
#include "TESActorBaseData.h"
#include "TESContainer.h"
#include "BGSTouchSpellForm.h"
#include "TESSpellList.h"
#include "TESAIForm.h"
#include "TESHealthForm.h"
#include "TESAttributes.h"
#include "TESAnimation.h"
#include "TESFullName.h"
#include "TESModel.h"
#include "TESScriptableForm.h"
#include "ActorValueOwner.h"
#include "BGSDestructibleObjectForm.h"

class BGSBodyPartData;
class BGSLoadFormBuffer;
class TESClass;
class TESCombatStyle;
enum SEX;

class __declspec(novtable) TESActorBase : public TESBoundAnimObject,
                     public TESActorBaseData,
                     public TESContainer,
                     public BGSTouchSpellForm,
                     public TESSpellList,
                     public TESAIForm,
                     public TESHealthForm,
                     public TESAttributes,
                     public TESAnimation,
                     public TESFullName,
                     public TESModel,
                     public TESScriptableForm,
                     public ActorValueOwner,
                     public BGSDestructibleObjectForm
{
public:
    TESObjectREFR* BGSExplosion_GetImpactDataSet(); // 0x00516bf0
    TESActorBase();
    virtual ~TESActorBase();

    // Primary slots 0 through 95 are inherited.
    virtual BGSBodyPartData* GetBodyPartData() const; // 96
    virtual void SetBodyPartData(BGSBodyPartData* data); // 97
    virtual TESCombatStyle* GetCombatStyle() const; // 98
    virtual void SetCombatStyle(TESCombatStyle* style); // 99
    virtual void SetActorValueF(ActorValue::Index index, float value); // 100
    virtual void SetActorValueI(ActorValue::Index index, int value); // 101
    virtual void ModActorValueF(ActorValue::Index index, float value); // 102
    virtual void ModActorValueI(ActorValue::Index index, int value); // 103

    virtual void InitItem();
    virtual void Revert(BGSLoadFormBuffer* buffer);
    virtual float GetCurrentActorValue(ActorValue::Index actorValue);

    TESActorBase& operator=(const TESActorBase& other);
    void SetEssentialState(bool value);
    void Copy(TESForm* form);
    bool ShouldUseDefaultAppearance(TESObjectREFR* reference);
    SEX GetSex();
    SEX GetSex() const;
    TESClass* GetClass();
    TESCombatStyle* GetCombatStyle();
    using TESHealthForm::GetHealth;
    int GetHealth() const;
    // Exe/RTTI 0x005f0d00 is the boolean query in primary slot 81.
    virtual bool IsAutoCalculated() const;
    void NotifyFormIDChanged(int flags);
    virtual void LoadGame(BGSLoadFormBuffer* buffer);

    int GetHealth_005f0b00();
    void SetHealth_005f0b30(int value);
    bool DoesSwim();
    bool FightsInWater();
    bool DoesWalk();
    bool DoesFly();
    bool IsImmobile();
    float GetDesirability(TESForm* form);
    void RemoveChange(int flags);
    unsigned short GetSaveSize_005f16f0(unsigned int flags);
    void SaveGame_005f18c0(unsigned int flags);
    void LoadGame_005f1b30(unsigned int flags, unsigned int arg);
    void SaveGame_005f1f30(unsigned int buffer);
    void Reset3DForLoadedActors(bool value);
    void* BGSProjectile_GetExplosion();

    void LimbRTTIAnchor();
    void rttiAnchor();
    void v000();
};
