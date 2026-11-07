// fallout/ai/playercharacter.h: declares AnimSelection
#ifndef FNV_PLAYERCHARACTER_UNIT_H
#define FNV_PLAYERCHARACTER_UNIT_H

#include "playercharacter_decls.h"

// @fnv 0x009520f0
void PlayerCharacter::SetActionGroupFlags(unsigned short group, ACTION_FLAGS flags)
{
    if (group & 0x8000)
        group &= 0x7FFF;
    struct AnimSelection
    {
        ANIM_GROUP_ENUM type;
        Animation* animation;
    } selection;
    selection.type = TESAnimGroup::GetType(group);
    if (selection.type == static_cast<ANIM_GROUP_ENUM>(255))  // ANIM_GROUP_NONE
        return;
    selection.animation = GetAnimation(true);
    bool copied = false;
    if (DAT_011977dc[selection.type].availableInThirdPerson)
    {
        Animation* thirdPerson = GetAnimation(false);
        BSAnimGroupSequence* sequence = thirdPerson->Animation_GetCurrentSequence(DAT_011977dc[selection.type].section);
        copied = static_cast<bool>(selection.animation->GetSequenceForKey(sequence, group));
    }
    if (!copied)
    {
        if (selection.animation->IsGroupQueued(group))
            selection.animation->PlayGroup(group, flags, -1, ANIM_GROUP_SECTION_AGS_NONE);
        else if (TESAnimGroup::IsIronSightsAction(group) && selection.animation->IsGroupQueued(group - 3))
            selection.animation->PlayGroup(group - 3, flags, -1, ANIM_GROUP_SECTION_AGS_NONE);
        else
        {
            unsigned short fallback = GetAnimGroup(selection.type, 0, !GetActiveWeapon(), selection.animation);
            if (TESAnimGroup::GetType(fallback) == selection.type ||
                (TESAnimGroup::IsIronSightsAction(selection.type) &&
                 TESAnimGroup::GetType(fallback) == selection.type - 3))
                selection.animation->PlayGroup(fallback, flags, -1, ANIM_GROUP_SECTION_AGS_NONE);
        }
    }
}

// @fnv 0x0095ed80
void PlayerCharacter::ResetActorValueModifiers()
{
    for (int i = 0; i < 77; ++i)
    {
        if (ActorValueModifierData[i] != 0.0 && !HasRecoverableActorValueEffect(static_cast<ActorValue::Index>(i)))
            ActorValueModifierData[i] = 0.0f;
    }
}

// @fnv 0x009396d0
ActorCombatGroup* PlayerCharacter::GetCombatGroup()
{
    return m_pCombatData;
}
#endif
