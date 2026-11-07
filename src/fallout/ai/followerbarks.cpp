// fallout/ai/followerbarks.cpp: BarkPlaybackEntry (2 functions)

#include "../../../include/Actor.h"
#include "../../../include/BSSimpleList.h"
#include "followerbarks_decls.h"
#include "../../../include/TESTopic.h"
// @fnv 0x008d5bc0
void BarkPlaybackEntry::UpdateBarks()
{
    BSSimpleList<BGSPerkEntry*>* now;
    unsigned int bark = gm_GetTickCount();
    bool remove;
    BarkPlaybackEntry* node;
    now = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(&g_011e0098);
    while (now)
    {
        node = reinterpret_cast<BarkPlaybackEntry*>(now->GetItem());
        remove = false;
        if (node && node->actor && node->startTime <= bark)
        {
            if (node->IsHealthConditionMet() && node->actor->IsPlayerTeammate())
            {
                node->InitTiming(node->actor, node->topic);
                node->PlayBark();
            }
            else
            {
                if (node->endTime <= bark)
                    remove = true;
                else if (!node->actor->IsPlayerTeammate())
                    remove = true;
            }
        }
        if (remove)
        {
            delete node;
            reinterpret_cast<BSSimpleList<const char*>*>(now)->RemoveHead();
        }
        else
            now = now->GetNext();
    }
}

extern TESForm* __cdecl FUN_00483a00(const char*);

// Returns the TESTopic form mapped to kind, or null when no form is returned.
// @fnv 0x008d5910
// src: XBOX_PDB 0x008d5910
TESTopic* __cdecl FollowerBarks_GetBarkTopicByType(unsigned int kind)
{
    switch (kind)
    {
    case 3:
        return 0;
        break;
    case 11:
        return dynamic_cast<TESTopic*>(FUN_00483a00("Wake"));
        break;
    case 0:
        return dynamic_cast<TESTopic*>(FUN_00483a00("KOed"));
        break;
    case 1:
        return dynamic_cast<TESTopic*>(FUN_00483a00("KnockedBack"));
        break;
    case 7:
        return dynamic_cast<TESTopic*>(FUN_00483a00("NoAmmo"));
        break;
    case 8:
        return dynamic_cast<TESTopic*>(FUN_00483a00("WeaponBroke"));
        break;
    case 5:
        return dynamic_cast<TESTopic*>(FUN_00483a00("HealthQuarter"));
        break;
    case 4:
        return dynamic_cast<TESTopic*>(FUN_00483a00("HealthHalf"));
        break;
    case 2:
        return dynamic_cast<TESTopic*>(FUN_00483a00("Crippled"));
        break;
    case 9:
        return dynamic_cast<TESTopic*>(FUN_00483a00("WeaponIneffective"));
        break;
    case 10:
        return dynamic_cast<TESTopic*>(FUN_00483a00("UsedDoctorBag"));
        break;
    case 6:
        return dynamic_cast<TESTopic*>(FUN_00483a00("Crippled"));
        break;
    case 12:
        return dynamic_cast<TESTopic*>(FUN_00483a00("FollowersStealthing"));
        break;
    case 13:
        return dynamic_cast<TESTopic*>(FUN_00483a00("Regenerating"));
    }
    return 0;
}
