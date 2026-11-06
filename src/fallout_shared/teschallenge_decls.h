#include "../../include/Interface.h"
#include "../../include/SettingT.h"
#pragma once

#include "teschallenge_support.h"
#include "../../include/SettingT.h"
#include "../../include/BGSListForm.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/ChallengeData.h"
#include "../../include/ChallengeProgress.h"
#include "../../include/MapEntryCount.h"
#include "../../include/Script.h"
#include "../../include/TESChallenge.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESDescription.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/TESScriptableForm.h"

#ifndef FNV_CHALLENGE_TYPE_H
#define FNV_CHALLENGE_TYPE_H
#include "layout_support.h"
#include "../../include/CHALLENGE_TYPE.h"
#endif

int Warning(const char*, ...);

class ChallengeManager
{
  public:
    static BSSimpleList<TESChallenge*> pChallengeList[14];
    static BSSimpleList<TESChallenge*> ms_kInactiveChallengesByType[14];
    static void Clear();
    static void CheckCompletedChallenges();
    static bool UpdateChallengeProgress(CHALLENGE_TYPE type, int count, TESForm* formOne, TESForm* formTwo,
                                        unsigned short specialOne, unsigned short specialTwo,
                                        unsigned short specialThree);
};
class INISettingCollection;
extern SettingT<INISettingCollection> DAT_011cb4d4;
class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;

class TopicMenuController
{
  public:
    static void IncrementMiscStat(int);
};
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);
extern const float DAT_010162c0;

extern "C" void* _alloca(unsigned int);
#pragma intrinsic(_alloca)

extern TESDataHandler* g_dataHandler;
extern "C" void* memset(void*, int, unsigned int);
