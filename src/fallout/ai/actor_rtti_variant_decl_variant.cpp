
// src/fallout/ai/actor_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x008c00e0: the skeleton of src/fallout/ai/actor_rtti_variant.cpp
// that unit declares it this way.

// src/fallout/ai/actor_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESBoundObject). The skeleton of src/fallout/ai/actor.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
#include "../../../include/Actor.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/ExtraDataList.h"
#include "../../../include/TESNPC.h"

class DetectionViewData
{
  public:
    Actor* actor;
    DETECTION_LEVEL level;
};


struct FUN_009eb500
{
    int type, unknown04, unknown08, unknown0C, unknown10;
    int unknown14, unknown18, unknown1C, unknown20, unknown24;
    int unknown28, unknown2C, unknown30, unknown34, unknown38;
    FUN_009eb500(int, TESObjectREFR*, Actor*, int, int, int);
    Actor* FUN_0044ddc0();
    Actor* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    void AddActor(Actor*);
};

struct CrimeLimit
{
    int* Setting_Int();
};
extern CrimeLimit g_011cd9f4;
struct CrimeCalendar
{
    float FUN_00867da0();
    char FUN_00867d60();
    int FUN_00867d20();
    int Calendar_GetYear();
};
extern CrimeCalendar g_011de7b8;
struct CrimeQueue
{
    void AddObjectToList(FUN_009eb500*);
};
extern CrimeQueue g_011e0e80;

extern PlayerCharacter* DAT_011dea3c;
// @fnv 0x008c00e0
// src: XBOX_PDB 0x008c00e0
void Actor::PickpocketAlarm(TESObjectREFR* victimRef, int amount, int crimeValue)
{
    bool status = false;
    if ((Actor*)this != DAT_011dea3c)
        return;
    if (DAT_011dea3c->GetField230() < *g_011cd9f4.Setting_Int() && (Actor*)this == DAT_011dea3c)
        status = true;
    Actor* entry = dynamic_cast<Actor*>(victimRef);
    if (entry->IsDead() || entry->IsDisabled())
    {
        entry->GetProcess()->SetIsWeaponReady(true);
        return;
    }
    if ((Actor*)this != DAT_011dea3c && ActorValueOwner::GetActorValueAsInteger(static_cast<ActorValue::Index>(42)) == 100 && IsSneaking())
        return;
    FUN_009eb500* isLowLevel = 0;
    isLowLevel = new FUN_009eb500(1, victimRef, (Actor*)this, amount, crimeValue, 0);
    Actor* target = (Actor*)victimRef;
    bool crime = false;
    if ((isLowLevel && target == isLowLevel->FUN_0044ddc0()) || isLowLevel->FUN_0044ddc0()->TESObjectREFR_IsAnOwner(target, true))
        crime = true;
    DetectionViewData* base = target->GetProcess()->GetDetectionState(isLowLevel->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), BaseProcess::_DetectionListType::BY_ME);
    DETECTION_LEVEL victim = static_cast<DETECTION_LEVEL>(3);
    if (!base)
        target->GetProcess()->InsertIntoDetectionArray(target, victim);
    else
        base->level = victim;
    TESNPC* form = dynamic_cast<TESNPC*>(target->GetObjectReference());
    entry->GetProcess()->SetIsWeaponReady(true);
    target->GetExtraData()->AddOrCreateExtraItem(isLowLevel, g_011de7b8.FUN_00867da0());
    isLowLevel->AddActor((Actor*)this);
    g_011e0e80.AddObjectToList(isLowLevel);
    target->Actor_IncrementMinorCrimes();
    target->Actor_AddFactionMinorCrime(true, true);
    if (m_bActorListValid)
    {
        bool alert = true;
        if (m_iIntegerAfterActorListValid > 0)
        {
            int day = m_iIntegerAfterActorListValid & 0x1ff;
            if (day != g_011de7b8.FUN_00867d60())
            {
                alert = false;
                m_bActorListValid = false;
            }
        }
        if (alert)
        {
            this->Alert(DAT_011dea3c, 0, 1, 0, 0, 0, 1, 0);
            return;
        }
    }
    else
    {
        m_bActorListValid = true;
        m_iIntegerAfterActorListValid =
            (g_011de7b8.FUN_00867d20() << 9) | g_011de7b8.FUN_00867d60() | (g_011de7b8.Calendar_GetYear() << 13);
    }
    target->Actor_InitiatePickPocketWarning((Actor*)this);
}
