#pragma once

#include "NiRefObject.h"
#include "NiPoint3.h"
#include <stddef.h>

class TESSound;
class NiControllerSequence;

enum ANIM_GROUP_ENUM;
enum ANIM_GROUP_MOVE_ENUM;
enum ANIM_GROUP_WEAPON_ENUM;
enum ANIM_ENUM;

struct _AnimationGroupActionType
{
    enum Type
    {
        START_STOP,
        LOOP,
        SPECIAL_IDLE,
        EQUIP,
        UNEQUIP,
        ATTACK,
        ATTACK_POWER,
        ATTACK_THROW,
        ATTACK_THROW_ATTACH,
        ATTACK_SPIN,
        COUNT
    };
};
typedef _AnimationGroupActionType::Type ANIM_GROUP_ACTION_TYPE;

class TESAnimGroup : public NiRefObject
{
  public:
    TESAnimGroup(unsigned short sGroup);
    virtual ~TESAnimGroup();

    void __thiscall FUN_005f22d0();
    void* __thiscall FUN_005f22a0(unsigned int flags);
    void __thiscall Animation_ResetVtableAndFinishScriptRunLock();

    struct AnimGroupSound
    {
        float fTime;
        union
        {
            unsigned char ucVolume;
            unsigned char eType;
        };
        union
        {
            float fCurrentSpeed;
            unsigned int uiEnumData;
        };
        TESSound* SoundAssetTmp;
    };

    unsigned char m_ucSectionPriorities[8];
    unsigned short sType;
    unsigned char unk12[2];
    unsigned int frameCount;
    float* times;
    NiPoint3 speed;
    char m_cByteAfterSpeed;
    unsigned char m_ucBlendCount;
    unsigned char m_ucBlendInCount;
    unsigned char m_ucBlendOutCount;
    unsigned char m_ucDecal;
    unsigned char unk2D[3];
    const char* pParentName;
    unsigned int m_uiSoundEntryCount;
    AnimGroupSound* sounds;

    static unsigned short AnimGroup(ANIM_GROUP_MOVE_ENUM, ANIM_GROUP_WEAPON_ENUM, ANIM_GROUP_ENUM, bool);
    static unsigned short AnimGroup(int, ANIM_GROUP_WEAPON_ENUM, int, bool);
    static unsigned short AnimGroup(int, int, int, int);
    static unsigned short AnimGroup(int, int, int, bool);
    static ANIM_GROUP_MOVE_ENUM GetMoveType(unsigned short);
    static ANIM_GROUP_ENUM GetType(unsigned short);
    ANIM_GROUP_ENUM GetType() const;
    unsigned int GetType();
    int GetMoveAnimGroup();
    static bool IsActionTypeValid(ANIM_GROUP_ACTION_TYPE);
    static bool IsActionTypeValid(unsigned short);
    static bool IsAimAnimation(unsigned short);
    static bool IsValidAnimationGroup(ANIM_GROUP_ACTION_TYPE);
    static bool IsValidAnimationGroup(unsigned short);
    static bool IsIronSightsAction(unsigned short);
    static bool IsIronSightsAction(ANIM_GROUP_ENUM);
    bool IsJumpAnimation() const;
    float GetAnimationSpeed() const;
    static char* FindNextLine(char*);
    void SetSoundsFromSequence(NiControllerSequence*);
    void SetSpeed(NiPoint3* speed);
    bool SetActionTime(unsigned int action, float time);
    float GetActionTime(int action);
    unsigned int GetSoundCount();
    void ResizeSoundList(unsigned int count);
    void SetSoundTime(unsigned int index, float time);
    void SetSound(unsigned int index, TESSound* sound);
    void SetSoundEnum(unsigned int index, ANIM_ENUM type, unsigned int data);
    void SetSoundEnum(unsigned int index, int type, unsigned int data);
    void SetSoundVolume(unsigned int index, float volume);
    void SetSoundPitch(unsigned int index, float pitch);
    void SetParentName(const char* name);
    void SetBlendIn(unsigned char frames);
    void SetBlendOut(unsigned char frames);
    void SetBlend(unsigned char frames);
    void SetDecal(unsigned char decal);
    char GetMorphKey();
    void SetMorphKey(unsigned char key);
    unsigned short GetAnimGroupType_0047d3b0();
    unsigned short GetWeapon();
    bool IsPowerAttack_005f26c0();
    void FUN_005f2820(unsigned int count);
    bool FUN_005f3740(unsigned int action, float time);
    float FUN_005f3780(int action);
    static void ParseAnimationGroupFilename(const char* filename, ANIM_GROUP_MOVE_ENUM& move,
                                            ANIM_GROUP_WEAPON_ENUM& weapon, bool& flag);
};

typedef char TESAnimGroup_size_check[(sizeof(TESAnimGroup) == 60) ? 1 : -1];
typedef char TESAnimGroup_priorities_offset_check[(offsetof(TESAnimGroup, m_ucSectionPriorities) == 8) ? 1 : -1];
typedef char TESAnimGroup_type_offset_check[(offsetof(TESAnimGroup, sType) == 16) ? 1 : -1];
typedef char TESAnimGroup_frameCount_offset_check[(offsetof(TESAnimGroup, frameCount) == 20) ? 1 : -1];
typedef char TESAnimGroup_times_offset_check[(offsetof(TESAnimGroup, times) == 24) ? 1 : -1];
typedef char TESAnimGroup_speed_offset_check[(offsetof(TESAnimGroup, speed) == 28) ? 1 : -1];
typedef char TESAnimGroup_byteAfterSpeed_offset_check[(offsetof(TESAnimGroup, m_cByteAfterSpeed) == 40) ? 1 : -1];
typedef char TESAnimGroup_blend_offset_check[(offsetof(TESAnimGroup, m_ucBlendCount) == 41) ? 1 : -1];
typedef char TESAnimGroup_blendIn_offset_check[(offsetof(TESAnimGroup, m_ucBlendInCount) == 42) ? 1 : -1];
typedef char TESAnimGroup_blendOut_offset_check[(offsetof(TESAnimGroup, m_ucBlendOutCount) == 43) ? 1 : -1];
typedef char TESAnimGroup_decal_offset_check[(offsetof(TESAnimGroup, m_ucDecal) == 44) ? 1 : -1];
typedef char TESAnimGroup_parentName_offset_check[(offsetof(TESAnimGroup, pParentName) == 48) ? 1 : -1];
typedef char TESAnimGroup_soundCount_offset_check[(offsetof(TESAnimGroup, m_uiSoundEntryCount) == 52) ? 1 : -1];
typedef char TESAnimGroup_sounds_offset_check[(offsetof(TESAnimGroup, sounds) == 56) ? 1 : -1];
typedef char TESAnimGroup_sound_size_check[(sizeof(TESAnimGroup::AnimGroupSound) == 16) ? 1 : -1];
