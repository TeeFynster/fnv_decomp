// Private declarations for the playercharacter.h unit.
#ifndef FNV_PLAYERCHARACTER_UNIT_DECLS_H
#define FNV_PLAYERCHARACTER_UNIT_DECLS_H

#include <stddef.h>
#ifndef FNV_STATIC_ASSERT
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#endif
class TESObjectWEAP;
class ActorCombatGroup;
class Animation;
class BSAnimGroupSequence;
#include "../../../include/ACTION_FLAGS.h"
#include "../../../include/ANIM_GROUP_SECTION.h"
class Animation
{
  public:
    BSAnimGroupSequence* Animation_GetCurrentSequence(ANIM_GROUP_SECTION section);
    BSAnimGroupSequence* GetSequenceForKey(BSAnimGroupSequence* sequence, unsigned short group);
    bool IsGroupQueued(unsigned short group);
    BSAnimGroupSequence* PlayGroup(unsigned short group, ACTION_FLAGS flags, int loops, ANIM_GROUP_SECTION section);
};
#include "../../../include/TESAnimGroup.h"
struct PlayerCharacterAnimGroupInfo
{
    bool availableInThirdPerson;
    unsigned char layoutPadding1[3];
    ANIM_GROUP_SECTION section;
    unsigned char layoutPadding8[28];
};
extern PlayerCharacterAnimGroupInfo DAT_011977dc[];
FNV_STATIC_ASSERT(sizeof(PlayerCharacterAnimGroupInfo) == 0x24);
FNV_STATIC_ASSERT(offsetof(PlayerCharacterAnimGroupInfo, section) == 4);
#include "../../../include/PlayerCharacter.h"
#endif
