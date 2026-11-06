// Private declarations for MediaLocationController::Update.
// Existing class layouts are retained; only out-of-line declarations are added.
#ifndef FNV_MEDIALOCATIONCONTROLLER_UPDATE_DECLS_H
#define FNV_MEDIALOCATIONCONTROLLER_UPDATE_DECLS_H

// Unit-local header for fallout_shared/medialocationcontroller.cpp.
#ifndef FNV_MEDIALOCATIONCONTROLLER_UNIT_H
#define FNV_MEDIALOCATIONCONTROLLER_UNIT_H
#include "layout_support.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "layout_support.h"
class MediaLocationController;
class MediaSet;
#include "../../include/MediaLocationController.h"
#endif
#ifndef FNV_MEDIASET_LOCAL_H
#define FNV_MEDIASET_LOCAL_H
#include "layout_support.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/MediaSet.h"
#endif

#include "../../include/NiPoint3.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/Actor.h"
struct ActorCombatEntry
{
    Actor* pActor;
    bool m_bIsEnemy;
    bool m_bIsCombatTarget;
};
FNV_STATIC_ASSERT(sizeof(ActorCombatEntry) == 8);
class MusicMarkerReference
{
  public:
    TESObjectREFR* m_pMarkerReference;
    void* m_pAudioMarkerData;
};
#include "../../include/PlayerCharacter.h"
extern PlayerCharacter* g_thePlayer;
#include "../../include/TESFaction.h"
#include "../../include/DEFAULT_OBJECT.h"
#include "../../include/BGSDefaultObjectManager.h"
#include "../../include/BSAudio.h"
extern MediaLocationController* DAT_011dd374;
extern MediaLocationController* DAT_011dd378;
#endif
