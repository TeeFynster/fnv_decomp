#include "../../include/BSSimpleList.h"
// fallout_shared/actorvalue_decls.h: shared game classes and actor value declarations

#ifndef FNV_ACTORVALUE_DECLS_H

#include <stdarg.h>
#define FNV_ACTORVALUE_DECLS_H
#include <stddef.h>
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
FNV_STATIC_ASSERT(sizeof(void*) == 4);
FNV_STATIC_ASSERT(sizeof(long) == 4);
class EffectSetting;
class TESFaction;
class TESObjectREFR;
class MediaSet;
class MediaLocationController;
class NiNode;
class TESSound;


#include "../../include/BSStringT.h"
#include "../../include/Actor.h"
#include "../../include/ActorValueOwner.h"
#include "../../include/ActorValueInfo.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/TESDescription.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESIcon.h"
#include "../../include/TESObjectWEAP.h"
#include "../../include/TESTexture.h"

FNV_STATIC_ASSERT(sizeof(BSSimpleList<void*>) == 8);
FNV_STATIC_ASSERT(sizeof(BSStringT<char>) == 8);
#include "../../include/ENUM_FORM_ID.h"

extern "C" void* __cdecl _alloca(size_t auiBytes);
#include "../../include/CHUNK_ID.h"


FNV_STATIC_ASSERT(sizeof(BaseFormComponent) == 0x4);


FNV_STATIC_ASSERT(sizeof(TESForm) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESForm, cFormType) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESForm, iFormFlags) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESForm, iFormID) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESForm, m_kSourceFiles) == 0x10);


FNV_STATIC_ASSERT(sizeof(TESFullName) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFullName, m_kName) == 0x4);

#include "../../include/ActorValue.h"

namespace ActorValue {
ActorValueInfo* GetActorValueInfo(Index index);
void LoadActorValueDefinitions();
}
namespace ActorValue {
void RegisterActorValue(Index, char*, Section, unsigned int, ActorValueDeriveCallback, ActorValueMappingCallback,
                        ActorValueModifiedCallback, int, ...);
}
extern bool DAT_011d6154;

void AV_Aggression_HandleChange(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
void SetProcessFlagIfActive(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
void Actor_EnduranceModifiedCallback(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float AiFormulas_AVDeriveActionPoints(ActorValueOwner*, ActorValue::Index);
float AiFormulas_AVDeriveCarryWeight(ActorValueOwner*, ActorValue::Index);
float AiFormulas_AVDeriveCriticalChance(ActorValueOwner*, ActorValue::Index);
float AiFormulas_AVDeriveHealingRate(ActorValueOwner*, ActorValue::Index);
void AV_HealRate_HandleChange(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float AiFormulas_AVDeriveHealth(ActorValueOwner*, ActorValue::Index);
void UpdateActorValueFlag(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float AiFormulas_AVDeriveFromPrimary(ActorValueOwner*, ActorValue::Index);
float AV_DamageResist_CalculateDefault(ActorValueOwner*, ActorValue::Index);
void Actor_ResetActorDTDR(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float AiFormulas_AVDeriveResistance(ActorValueOwner*, ActorValue::Index);
void AV_RadResist_HandleChange(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float AiFormulas_AVDeriveFatigue(ActorValueOwner*, ActorValue::Index);
float AiFormulas_AVDeriveBodyPartCondition(ActorValueOwner*, ActorValue::Index);
void AV_XP_HandleChange(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float AiFormulas_AVDeriveUnarmedDamage(ActorValueOwner*, ActorValue::Index);
float callback4C(ActorValueOwner*, ActorValue::Index);
void AV_Medicine_HandleChange(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
void AV_Survival_HandleChange(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float Actor_GetInventoryWeight(ActorValueOwner*, ActorValue::Index);
void AV_Paralysis_HandleChange(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
void UpdateStageChange(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
void UpdateStageTransition(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
void OnSleepDeprivationStageChanged(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);
float ActorValueOwner_GetTotalArmorDT(ActorValueOwner*, ActorValue::Index);

FNV_STATIC_ASSERT(offsetof(ActorValueInfo, m_pName) == 0x38);
FNV_STATIC_ASSERT(offsetof(ActorValueInfo, m_pDerivedValueFunction) == 0x4c);

float BSMAX_00404010(float, float);
float BSMIN(float, float);
namespace ActorValue {
bool GetFlag(Index, unsigned int);
float ClampValue(Index, float);
}

namespace ActorValue {

Index GetActorValueForSectionIndex(Section, char);
unsigned int GetCountForSection(Section);
const char* GetActorValueName(Index);
bool TryGetActorValue(ActorValueOwner*, Index, float&);
void NotifyActorValueChanged(ActorValueOwner*, Index, float, float, ActorValueOwner*);
Index* GetDependentActorValueIndices(Index, int&);
bool HasActorValueChangedCallback(Index);
}
template <class T> unsigned int BSStringLength(const T*);
class TESObjectIMOD;

float floorf(float);

namespace ActorValue {
bool IsDerivedAttribute(Index);
bool IsAIAttribute(Index);
bool IsSkill(Index);
Section GetSection(Index);
unsigned char ToArrayIndex(int, Index);
}
bool ActorValue_IsAttribute(ActorValue::Index);
int MinInt(int, int);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
class GlobalObject_0066ef90
{
  public:
    ActorValueInfo* values[77];
    GlobalObject_0066ef90();
};
extern GlobalObject_0066ef90 g_011d61c8;
void* __cdecl operator new(size_t) throw();
void __cdecl operator delete(void*);
bool ActorValue_IsResistance(ActorValue::Index);
#endif
