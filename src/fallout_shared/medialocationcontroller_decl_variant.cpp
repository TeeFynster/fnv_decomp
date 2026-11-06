
// src/fallout_shared/medialocationcontroller_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00595310: the skeleton of src/fallout_shared/medialocationcontroller.cpp
// with declarations corrected to what the original code does (medialocationcontroller_update_decls.h: class MediaLocationController : public TESForm, pu -> class MediaLocationController : public TESForm, pu). Move the function to its real unit once
// that unit declares it this way.

#include "../../include/Actor.h"
#include "../../include/BGSDefaultObjectManager.h"
#include "../../include/BSAudio.h"
#include "../../include/MediaLocationController.h"
#include "../../include/MediaSet.h"
#include "../../include/MediaSetEntry.h"
#include "../../include/NiPoint3.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/TESFaction.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESDataHandler.h"
unsigned int __cdecl GetRandomNumberInRange(int aiMin, int aiMax);
int __cdecl Warning(const char* apFormat, ...);
extern TESDataHandler* g_dataHandler;

// @fnv 0x00595310
MediaLocationController::MediaLocationController()
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x70));
    iFlags = 4;
    m_fLowerWeightThreshold = 0.33f;
    m_fUpperWeightThreshold = 0.66f;
    m_fUpdateInterval = 0.0f;
    m_uiShortDelay = 64;
    m_uiLongDelay = 336;
    m_kMediaSetList1.RemoveAll();
    m_kMediaSetList2.RemoveAll();
    m_kMediaSetList3.RemoveAll();
    m_kMediaSetList4.RemoveAll();
    m_kMediaSetList5.RemoveAll();
    m_kMediaSetList6.RemoveAll();
    pFaction = 0;
    m_eRequiredFightReaction = FIGHT_REACTION_FIGHT_REACTION_ENEMY;
    m_pReference = 0;
    m_fUpdateCooldown = 0;
    m_uiFirstCounter = 0;
    m_uiSecondCounter = 0;
    m_uiThirdCounter = 0;
    m_bCountWasNonzero = false;
    m_bActorStateFlag = false;
    m_bConditionWasTrue = false;
    m_bConditionActive = false;
    m_cMediaState = 0;
    m_pMediaSet = 0;
    m_uiPerceivedActorCount = 0;
    m_uiPreviousPerceivedActorCount = 0;
    m_eCurrentFightReaction = FIGHT_REACTION_FIGHT_REACTION_ENEMY;
}
