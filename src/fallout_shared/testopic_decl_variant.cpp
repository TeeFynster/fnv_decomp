
// src/fallout_shared/testopic_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0061af30: the skeleton of src/fallout_shared/testopic.cpp
// with declarations corrected to what the original code does (TESTopicInfo.h: TESTopicInfo += TESQuest* FUN_006733e0();). Move the function to its real unit once
// that unit declares it this way.

#include "../../include/BSSimpleList.h"
#include "TESTopic.h"
#include "TESTopicInfo.h"
#include "TESQuest.h"
#include "QuestDialogueInfo.h"
#include "TESTopicInfoData.h"
#include "DialogueItem.h"
#include "../../include/MobileObject.h"
#include "../../include/PlayerCharacter.h"
#include "game_constants.h"
extern PlayerCharacter* g_thePlayer;
extern unsigned int DialogueRandom();

// @fnv 0x0061af30
// src: XBOX_PDB 0x0061af30
TESTopicInfo* TESTopic_GetMatchingFollowUpInfo(TESTopicInfo* input, bool& deferredResult, TESObjectREFR* speaker, TESObjectREFR* listener,
                           bool filter, BSSimpleList<DialogueItem*>* history)
{
    TESTopicInfo* b = input;
    deferredResult = false;
    if (!b || b->IsDeleted())
        return 0;
    TESTopicInfo* excluded = 0;
    BSSimpleList<TESTopicInfo*> choices;
    unsigned int f = 0;
    bool h = false;
    BSSimpleList<TESTopicInfo*>* a = 0;
    if (b->GetConversationData())
        a = b->GetConversationData()->GetFollowUpInfoList();
    TESTopicInfo* fallback = 0;
    while (a && a->GetItem() && !h)
    {
        TESTopicInfo* info = a->GetItem();
        TESQuest* quest = info->GetParentQuest();
        a = a->GetNext();
        if (quest && quest->GetEnabled() && quest->GetConditions()->ContainsTrait(speaker, listener))
        {
            bool deferred = false;
            bool allowed = true;
            if (info && info->IsSayOnceADay() && speaker->IsMobileObject())
            {
                MobileObject* mobile = (MobileObject*)speaker;
                if (mobile->HasSaidTopicInfo(info))
                    allowed = false;
            }
            if (info && allowed && info->IsInfoValidForDialogue(deferred, 0, speaker, listener))
            {
                deferredResult = false;
                bool keep = true;
                if (keep)
                {
                    if (info->IsRandomEnd())
                        h = true;
                    BSSimpleList<DialogueItem*>* seen = history;
                    while (seen && !seen->IsEmpty())
                    {
                        DialogueItem* dialogue = seen->GetItem();
                        if (dialogue->GetInfo() == info)
                        {
                            excluded = info;
                            keep = false;
                            break;
                        }
                        seen = seen->GetNext();
                    }
                }
                if (keep)
                {
                    if (info->IsRandomEnd())
                        h = true;
                    if (choices.IsEmpty() && !info->IsRandom())
                    {
                        return info;
                    }
                    else if (!info->IsRandom())
                    {
                        h = true;
                        break;
                    }
                    else
                    {
                        choices.AddHead(info);
                        f++;
                    }
                }
                if (!filter && deferred)
                {
                    fallback = info;
                    deferredResult = true;
                }
                if (h)
                    break;
            }
        }
    }
    if (choices.IsEmpty())
    {
        if (filter)
            return 0;
        else
            return fallback;
    }
    else
    {
        int pick = f ? DialogueRandom() % f + 1 : 0;
        int a = 0;
        BSSimpleList<TESTopicInfo*>* c = &choices;
        TESTopicInfo* selected = 0;
        TESTopicInfo* b = 0;
        while (a < pick && c)
        {
            b = c->GetItem();
            if (b)
            {
                selected = b;
                a++;
            }
            c = c->GetNext();
        }
        choices.RemoveAll();
        return selected;
    }
}
