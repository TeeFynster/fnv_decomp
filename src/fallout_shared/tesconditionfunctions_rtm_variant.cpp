
// src/fallout_shared/tesconditionfunctions_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/tesconditionfunctions.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /Od /Oy- /GS /EHsc /Gy /GF (unit lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton.

#include "../../include/Actor.h"
extern PlayerCharacter* g_thePlayer;
struct PlayerCharacterMovingStateView
{
    unsigned char padding[0x20c];
    unsigned char movingIntoNewSpace;
};
bool __cdecl GetEssentialConditionFunction(TESObjectREFR* reference, void* arg1, void* arg2, double& result);
bool __cdecl IsPlayerEnteringSpaceConditionFunction(TESObjectREFR* reference, void* arg1, void* arg2, double& result);
bool GetLastHitLocationConditionFunction(TESObjectREFR* reference, void* arg1, void* arg2, double& result);

namespace s59e490 {

extern __declspec(thread) bool tls_bEchoConsole;

void Interface_PrintLine(const char* pcFormat, ...);

struct Quest
{
    bool FUN_0060d600(unsigned char ucStage);
};

static const char s_szGetStageDoneFormat[] = "GetStageDone >> %0.2f";

// @fnv 0x0059e490
// src: XBOX_PDB 0x0059e490
bool Script_GetStageDoneConditionFunction(void* pvThisObj, Quest* pkQuestArg, unsigned int uiStage, double* pdResult)
{
    Quest* pkQuest;
    unsigned int uiStageIndex;

    *pdResult = 0.0;
    pkQuest = pkQuestArg ? pkQuestArg : 0;
    uiStageIndex = uiStage;
    if (pkQuest && pkQuest->FUN_0060d600((unsigned char)uiStageIndex))
        *pdResult = 1.0;
    if (tls_bEchoConsole)
        Interface_PrintLine(s_szGetStageDoneFormat, *pdResult);
    return true;
}

}
