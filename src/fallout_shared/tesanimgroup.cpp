// fallout_shared/tesanimgroup.cpp: TESAnimGroup, BSAnimGroupSequence, Holder (35 functions)

#include "../../include/TESAnimGroup.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiMemObject.h"
#include "../../include/BSAnimGroupSequence.h"
#include "../../include/NiControllerSequence.h"

#include "../../include/TESSound.h"
#include "../../include/BSAudio.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/NiTextKeyExtraData.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESFile.h"
#include "../../include/NiPoint3.h"

// TESAnimGroup comes from the shared header. Like the game's other /Od units, this one calls
// the /Od copy of the inline NiRefObject destructor (0x00496910) from ~TESAnimGroup and its
// unwind; the NiMain libraries call the /O2 copy at 0x00A5D3D0. The recipe binds
// ??1NiRefObject@@UAE@XZ to 0x00496910 for this unit.

#include <stddef.h>
#define TESANIMGROUP_JOIN_INNER(a, b) a##b
#define TESANIMGROUP_JOIN(a, b) TESANIMGROUP_JOIN_INNER(a, b)
#define TESANIMGROUP_ASSERT(c) typedef char TESANIMGROUP_JOIN(tesanimgroup_assert_, __LINE__)[(c) ? 1 : -1]
#include "../../include/ANIM_GROUP_ENUM.h"
#include "../../include/ANIM_GROUP_MOVE_ENUM.h"
#include "../../include/ANIM_GROUP_WEAPON_ENUM.h"
#include "../../include/ANIM_GROUP_ACTION.h"
enum ANIM_ENUM
{
};

char* __cdecl strchr(char*, int);                   // C++ <string.h> overload, ?strchr@@YAPADPADH@Z = 0x0043B9D0
TESANIMGROUP_ASSERT(sizeof(void*) == 4);
TESANIMGROUP_ASSERT(sizeof(NiRefObject) == 8);
TESANIMGROUP_ASSERT(sizeof(NiPoint3) == 12);
TESANIMGROUP_ASSERT(sizeof(TESAnimGroup) == 60);
TESANIMGROUP_ASSERT(sizeof(TESAnimGroup::AnimGroupSound) == 16);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup, m_ucSectionPriorities) == 8);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup, sType) == 16);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup, frameCount) == 20);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup, times) == 24);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup, speed) == 28);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup, m_cByteAfterSpeed) == 40);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup, m_ucBlendCount) == 41);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup, m_ucBlendInCount) == 42);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup, m_ucBlendOutCount) == 43);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup, m_ucDecal) == 44);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup, pParentName) == 48);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup, m_uiSoundEntryCount) == 52);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup, sounds) == 56);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup::AnimGroupSound, fTime) == 0);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup::AnimGroupSound, ucVolume) == 4);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup::AnimGroupSound, fCurrentSpeed) == 8);
TESANIMGROUP_ASSERT(offsetof(TESAnimGroup::AnimGroupSound, SoundAssetTmp) == 12);
struct TESAnimGroupActionEntry
{
    ANIM_GROUP_ACTION_TYPE action;
    unsigned char padding[32];
};
extern TESAnimGroupActionEntry DAT_011977e4[];

TESANIMGROUP_ASSERT(sizeof(NiControllerSequence) == 116);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_kName) == 8);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_uiNumControlledBlocks) == 12);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_uiNumIDTags) == 16);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_pInterpArray) == 20);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_pkIDTags) == 24);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_fWeight) == 28);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_spTextKeyData) == 32);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_eAnimationCycleType) == 36);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_fFrequency) == 40);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_fFirstKeyTime) == 44);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_fLastKeyTime) == 48);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_fLastTime) == 52);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_fWeightAdjustedLastTime) == 56);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_fScaledLastTime) == 60);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_pkOwnerManager) == 64);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_eAnimationState) == 68);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_fSequenceOffset) == 72);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_fStartTime) == 76);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_fEndTime) == 80);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_fDestinationFrame) == 84);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_pkTimeSyncSequence) == 88);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_kAccumulationRootName) == 92);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_pkAccumulationRoot) == 96);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_spStringPalette) == 100);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_sAnimNotesExtraDataIndex) == 104);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_pkAnimNotes) == 108);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_usNumAnimNotes) == 112);
TESANIMGROUP_ASSERT(offsetof(NiControllerSequence, m_bHasAnimNotes) == 114);
TESANIMGROUP_ASSERT(sizeof(BSAnimGroupSequence) == 120);
TESANIMGROUP_ASSERT(offsetof(BSAnimGroupSequence, m_spAnimGroup) == 116);
extern const char* DAT_01199bcc[];

// Combines powerArmor, move, weapon and group into a packed 16-bit animation group value via bit shifts.
// @fnv 0x005f2370
unsigned short TESAnimGroup::AnimGroup(ANIM_GROUP_MOVE_ENUM move, ANIM_GROUP_WEAPON_ENUM weapon, ANIM_GROUP_ENUM group,
                                       bool powerArmor)
{
    return (powerArmor << 15) + (move << 12) + (weapon << 8) + group;
}

// @fnv 0x005f23c0
ANIM_GROUP_MOVE_ENUM TESAnimGroup::GetMoveType(unsigned short group)
{
    return static_cast<ANIM_GROUP_MOVE_ENUM>((group & 0x7000) >> 12);
}

// @fnv 0x005f2440
ANIM_GROUP_ENUM TESAnimGroup::GetType(unsigned short group)
{
    return static_cast<ANIM_GROUP_ENUM>(group & 0xFF);
}

// @fnv 0x005f2420
ANIM_GROUP_ENUM TESAnimGroup::GetType() const
{
    return GetType(sType);
}

// Returns true when the animation group action type is one of the attack variants, false otherwise.
// @fnv 0x005f25a0
bool TESAnimGroup::IsActionTypeValid(ANIM_GROUP_ACTION_TYPE aeActionType)
{
    switch (aeActionType)
    {
    case _AnimationGroupActionType::ATTACK:
    case _AnimationGroupActionType::ATTACK_POWER:
    case _AnimationGroupActionType::ATTACK_THROW:
    case _AnimationGroupActionType::ATTACK_THROW_ATTACH:
    case _AnimationGroupActionType::ATTACK_SPIN:
        return true;
    default:
        return false;
    }
}

// Returns true if group is not ANIM_GROUP_NONE and its type falls between ANIM_GROUP_AIM and ANIM_GROUP_AIM_IS_DOWN.
// @fnv 0x005f2630
bool TESAnimGroup::IsAimAnimation(unsigned short group)
{
    if (group == ANIM_GROUP_ENUM_ANIM_GROUP_NONE)
        return false;
    ANIM_GROUP_ENUM type = GetType(group);
    if (type >= ANIM_GROUP_ENUM_ANIM_GROUP_AIM && type <= ANIM_GROUP_ENUM_ANIM_GROUP_AIM_IS_DOWN)
        return true;
    return false;
}

// @fnv 0x005f26b0
bool TESAnimGroup::IsValidAnimationGroup(ANIM_GROUP_ACTION_TYPE type)
{
    return type == _AnimationGroupActionType::ATTACK_POWER;
}

// Returns true if the animation group type is one of the jump-loop variants, false otherwise.
// @fnv 0x005f4d60
bool TESAnimGroup::IsJumpAnimation() const
{
    switch (GetType(sType))
    {
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP:
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP_FORWARD:
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP_BACKWARD:
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP_LEFT:
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP_RIGHT:
        return true;
    default:
        return false;
    }
}

// @fnv 0x005f4c70
float TESAnimGroup::GetAnimationSpeed() const
{
    return speed.Length();
}

// @fnv 0x005f3870
char* TESAnimGroup::FindNextLine(char* pcText)
{
    pcText = strchr(pcText, '\n');
    while (pcText && *pcText && (*pcText == '\r' || *pcText == '\n'))
        ++pcText;
    if (pcText && *pcText)
        return pcText;
    return 0;
}

// @fnv 0x0048f7f0
TESAnimGroup* BSAnimGroupSequence::GetAnimGroup() const
{
    return m_spAnimGroup;
}

// Returns false for ANIM_GROUP_ENUM_ANIM_GROUP_NONE, otherwise recurses on the action of the group's type entry in DAT_011977e4.
// @fnv 0x005f2670
bool TESAnimGroup::IsValidAnimationGroup(unsigned short group)
{
    if (group == ANIM_GROUP_ENUM_ANIM_GROUP_NONE)
        return false;
    return IsValidAnimationGroup(DAT_011977e4[GetType(group)].action);
}

// @fnv 0x005f2540
bool TESAnimGroup::IsActionTypeValid(unsigned short group)
{
    ANIM_GROUP_ENUM type = GetType(group);
    if (type == ANIM_GROUP_ENUM_ANIM_GROUP_NONE)
        return false;
    switch (type)
    {
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_UP:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_DOWN:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_IS:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_IS_UP:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_IS_DOWN:
        return true;
    }
    return IsActionTypeValid(DAT_011977e4[type].action);
}

// @fnv 0x005f4d00
void TESAnimGroup::SetSoundsFromSequence(NiControllerSequence* sequence)
{
    BSAnimGroupSequence* animSequence = static_cast<BSAnimGroupSequence*>(sequence);
    for (int i = 0; i < 8; ++i)
    {
        if (DAT_01199bcc[i])
            m_ucSectionPriorities[i] = animSequence->GetPriority(DAT_01199bcc[i], 0);
    }
}

// @fnv 0x0047d3b0
// src: XBOX_PDB 0x0047d3b0
unsigned short TESAnimGroup::GetAnimGroupType_0047d3b0()
{
    return sType;
}

// Calls the destructor, frees this when flags has bit 1 set, and returns this.
// @fnv 0x005f22a0
void* TESAnimGroup::FUN_005f22a0(unsigned int flags)
{
    this->FUN_005f22d0();
    if (flags & 1)
        TESAnimGroup::operator delete(this, sizeof(TESAnimGroup));
    return this;
}

// Writes afValue into the times array at aiIndex, returning false if times is null or aiIndex is out of range.
// @fnv 0x005f3740
bool TESAnimGroup::SetActionTime(unsigned int aiIndex, float afValue)
{
    if (!times)
        return false;
    if (aiIndex >= frameCount)
        return false;
    times[aiIndex] = afValue;
    return true;
}

void __cdecl _FNV_Warning(const char*, ...);
int __cdecl _FNV_IsNaN(double);

struct AnimGroupInfo_011977d8
{
    const char* name;
    char pad[0x20];
};
extern AnimGroupInfo_011977d8 DAT_011977d8[];

// Validates groupAction against frameCount, warns on out-of-range or NaN times, and returns times[groupAction] or 0.0f.
// @fnv 0x005f3780
float TESAnimGroup::GetActionTime(int groupAction)
{
    if (groupAction < 0)
    {
        _FNV_Warning("ANIMATION: Invalid anim group action (action %d too small) in %s (%04X).", groupAction,
                     DAT_011977d8[GetType(sType)].name, sType);
        return 0.0f;
    }
    if ((unsigned int)groupAction >= frameCount)
    {
        _FNV_Warning("ANIMATION: Invalid anim group action (action %d too big %d max) in %s (%04x).", groupAction,
                     frameCount, DAT_011977d8[GetType(sType)].name, sType);
        return 0.0f;
    }
    if (times)
    {
        if (_FNV_IsNaN(times[groupAction]))
        {
            _FNV_Warning("ANIMATION: Time %d in group %04X is QNAN", groupAction, sType);
            return 0.0f;
        }
        return times[groupAction];
    }
    return 0.0f;
}

template <typename T> unsigned int __cdecl BSStringLength(const T* str);

const char* __cdecl _strrchr(const char*, int);
int __cdecl __strnicmp(const char*, const char*, unsigned int);

extern const char* DAT_01197794[];
extern const char* DAT_011977a4[];

// @fnv 0x005f38d0
// src: COMMUNITY 0x005f38d0
void __cdecl TESAnimGroup_ParseAnimGroupFilename(const char* apModelName, unsigned int* aeMove, unsigned int* aeWeapon, bool* abPowerArmor)
{
    unsigned int n;
    const char* plastSlash = _strrchr(apModelName, '\\');
    *abPowerArmor = false;
    *aeMove = 0;
    *aeWeapon = 0;
    if (plastSlash)
    {
        plastSlash = plastSlash + 1;
        if (__strnicmp(plastSlash, "PA", BSStringLength("PA")) == 0)
        {
            *abPowerArmor = true;
            plastSlash += BSStringLength("PA");
        }
        for (n = 1; n < 4; ++n)
        {
            if (__strnicmp(plastSlash, DAT_01197794[n], BSStringLength(DAT_01197794[n])) == 0)
            {
                *aeMove = n;
                plastSlash += BSStringLength(DAT_01197794[n]);
                break;
            }
        }
        for (n = 1; n < 12; ++n)
        {
            if (__strnicmp(plastSlash, DAT_011977a4[n], BSStringLength(DAT_011977a4[n])) == 0)
            {
                *aeWeapon = n;
                break;
            }
        }
    }
}

// Stores the NiPoint3 pointed to by apSpeed into the speed field.
// @fnv 0x005f4c40
void TESAnimGroup::SetSpeed(NiPoint3* apSpeed)
{
    speed = *apSpeed;
}

extern char* PTR_s_Start_01199a50[][11];
struct UShortArg
{
    unsigned short v;
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
void* __cdecl memset(void*, int, unsigned int);

// @fnv 0x005f2450
void __fastcall SetAnimGroupType(TESAnimGroup* self, UShortArg type)
{
    self->sType = type.v;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (!*PTR_s_Start_01199a50[i][*(int*)&DAT_011977e4[TESAnimGroup::GetType(type.v)]])
            break;
    }
    self->frameCount = i;
    if (self->times)
        delete self->times;
    if (self->frameCount)
    {
        self->times = new float[self->frameCount];
        memset(self->times, 0, self->frameCount * sizeof(float));
    }
    else
    {
        self->times = 0;
    }
}

extern int DAT_010484e8;

void __cdecl operator delete(void*);

// @fnv 0x005f22d0
TESAnimGroup::~TESAnimGroup()
{
    void* p = times;
    ::operator delete(p);
    times = 0;
    ::operator delete(sounds);
    sounds = 0;
    m_uiSoundEntryCount = 0;
}

// @fnv 0x005f23a0
int TESAnimGroup::GetMoveAnimGroup()
{
    return TESAnimGroup::GetMoveType(this->sType);
}

extern "C" unsigned short __cdecl TESAnimGroup_GetWeapon(unsigned short);

// @fnv 0x005f23e0
// src: COMMUNITY 0x005f23e0
unsigned short __thiscall TESAnimGroup::GetWeapon()
{
    return TESAnimGroup_GetWeapon(sType);
}

namespace fnv_005f2400 {
// @fnv 0x005f2400
// src: XBOX_PDB 0x005f2400
int TESAnimGroup_GetWeapon(unsigned short ausValue)
{
    return (ausValue & 0xf00) >> 8;
}
}  // namespace fnv_005f2400

// @fnv 0x005f2610
bool __cdecl IsNine(int aiValue)
{
    if (aiValue == 9)
    {
        return true;
    }
    return false;
}

// @fnv 0x005f2700
bool IsValidCharCode(int aiCharCode)
{
    if (aiCharCode >= 0xb1 && aiCharCode <= 0xc7)
        return true;
    return false;
}

bool __cdecl IsIronSightsAction(ANIM_GROUP_ENUM);

// Returns false for anim group 0xff, otherwise checks whether the group's type is an iron sights action.
// @fnv 0x005f2720
bool IsIronSightsAnimGroup(unsigned short usAnimGroup)
{
    if (usAnimGroup == 0xff)
        return false;
    return IsIronSightsAction(TESAnimGroup::GetType(usAnimGroup));
}

int __cdecl GetType(unsigned short);
bool __cdecl IsNine(int);

// Returns false for type 0xff, otherwise looks up the type's entry and returns the result of IsNine on its stored value.
// @fnv 0x005f25d0
// src: XBOX_PDB 0x005f25d0
bool TESAnimGroup_IsAttackSpinAction(unsigned short ausType)
{
    if (ausType == 0xff)
        return false;
    return IsNine(*(int*)(GetType(ausType) * 0x24 + 0x11977e4));
}

void* __cdecl _Deallocate(void*);
void* __cdecl __memcpy(void*, const void*, unsigned int);
void* __cdecl _Reallocate(void*, unsigned int);

// Resizes the sounds array to count entries, copying existing entries and initialising new ones with default time, type and volume values.
// @fnv 0x005f2820
void TESAnimGroup::ResizeSoundList(unsigned int count)
{
    unsigned int oldSoundCount = m_uiSoundEntryCount;
    m_uiSoundEntryCount = count;
    if (!m_uiSoundEntryCount)
    {
        _Deallocate(sounds);
        sounds = 0;
        return;
    }
    if (oldSoundCount)
    {
        AnimGroupSound* sounds_old = (AnimGroupSound*)::operator new(oldSoundCount * 16);
        __memcpy(sounds_old, sounds, oldSoundCount * 16);
        sounds = (AnimGroupSound*)_Reallocate(sounds, m_uiSoundEntryCount * 16);
        unsigned int n = oldSoundCount;
        if (oldSoundCount > m_uiSoundEntryCount)
            n = m_uiSoundEntryCount;
        __memcpy(sounds, sounds_old, n * 16);
        _Deallocate(sounds_old);
        for (unsigned int i = oldSoundCount; i < m_uiSoundEntryCount; i++)
        {
            sounds[i].SoundAssetTmp = 0;
            sounds[i].fTime = 0.0f;
            sounds[i].eType = 0xfa;
            sounds[i].fCurrentSpeed = 1.0f;
        }
    }
    else
    {
        sounds = (AnimGroupSound*)::operator new(m_uiSoundEntryCount * 16);
        for (unsigned int i = 0; i < m_uiSoundEntryCount; i++)
        {
            sounds[i].SoundAssetTmp = 0;
            sounds[i].fTime = 0.0f;
            sounds[i].eType = 0xfa;
            sounds[i].fCurrentSpeed = 1.0f;
        }
    }
}

int __cdecl GetType(unsigned short);
// Returns true when GetType(a) is 0, 1 or 0xAA, otherwise false.
// @fnv 0x005f4cc0
// src: COMMUNITY 0x005f4cc0
bool __cdecl TESAnimGroup_IsIdleAnim(unsigned short ausType)
{
    switch (GetType(ausType))
    {
    case 0:
    case 1:
    case 0xAA:
        return true;
    default:
        return false;
    }
}

struct TimedTextEntry
{
    void SetTime(float);
    float GetTime();
    void SetText(void*);
    void* GetText();
    TimedTextEntry* Copy();
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void RegisterStreamables(NiStream*);
    float m_fTime;
    NiFixedString m_kText;
};

namespace fnv_005f3a20 {
typedef char _sizecheck_NiTextKey[sizeof(TimedTextEntry) == 8 ? 1 : -1];
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

int _stricmp(const char* str1, const char* str2);
int __strnicmp(const char* str1, const char* str2, int count);
const char* _strrchr(const char* str, int ch);
void _FNV_Warning(const char* format, ...);
template <class T> unsigned int BSStringLength(const T* str);
char* strchr(char* str, int ch);
double atof(const char* str);
long atol(const char* str);
int strcpy_s(char* dest, unsigned int size, const char* src);
int sprintf_s(char* buffer, unsigned int size, const char* format, ...);
int TruncateFloatToInt(float f);
void MessageHandler_IncDisableWarningCount(bool b);

// These folded no-argument thiscall accessors take the sequence in ECX, as do
// single-argument fastcall functions; the shared header has no declarations.
const NiFixedString& __fastcall GetSequenceAccumulationRootName(const NiControllerSequence* sequence);
unsigned int __fastcall GetSequenceNumIDs(const NiControllerSequence* sequence);
unsigned int __fastcall GetSequenceCycleType(const NiControllerSequence* sequence);

void ParseAnimationGroupFilename(const char* pFilename, ANIM_GROUP_MOVE_ENUM& eMove, ANIM_GROUP_WEAPON_ENUM& eWeapon,
                                 bool& bPowerArmor);

struct AnimGroupInfo
{
    const char* pName;
    int iUnk04;
    int iLoopType;
    int iSequenceType;
    int m_iPadding[5];
};

extern AnimGroupInfo DAT_011977d8[];
extern const char* DAT_01199a50[][11];
extern const char* DAT_01199b50[];
extern const char* DAT_011a8244;
extern TESDataHandler* g_dataHandler;

// Parses a controller sequence's text keys to build a TESAnimGroup, setting parent, morph, blend, decal and sound data and warning on bad notes.
// @fnv 0x005f3a20
// src: COMMUNITY 0x005f3a20
TESAnimGroup* TESAnimGroup_LoadAnimGroup(NiControllerSequence* apSequence, const char* apModelName)
{
    ANIM_GROUP_ENUM m;
    char message[260];
    bool bshowWarning = false;
    TESAnimGroup* panimGroup = 0;
    ANIM_GROUP_ENUM lastGroup = (ANIM_GROUP_ENUM)0xff;
    unsigned int iactionIndex = 0;
    bool bpowerArmor = false;
    ANIM_GROUP_MOVE_ENUM eanimMove = ANIM_GROUP_MOVE_ENUM_AGM_NONE;
    ANIM_GROUP_WEAPON_ENUM eanimWeapon = ANIM_GROUP_WEAPON_ENUM_AGW_NONE;
    const char* plastSlash = _strrchr(apModelName, '\\');
    MessageHandler_IncDisableWarningCount(true);
    const char* paccumName = GetSequenceAccumulationRootName(apSequence);
    int iaccumIndex = -1;
    int inonAccumIndex = -1;
    char cnonAccumName[64];
    sprintf_s(cnonAccumName, 64, "%s NonAccum", paccumName);
    unsigned int n;
    for (n = 0; n < GetSequenceNumIDs(apSequence); n++)
    {
        char ptestName[260];
        apSequence->GetEntryText(n, ptestName);
        if (ptestName[0])
        {
            if (!_stricmp(paccumName, ptestName))
                iaccumIndex = n;
            else if (!_stricmp(cnonAccumName, ptestName))
                inonAccumIndex = n;
        }
        else
        {
            _FNV_Warning("No object name at index %i for sequence '%s'.", n, (const char*)static_cast<const NiControllerSequence*>(apSequence)->GetName());
        }
        if (iaccumIndex != -1 && inonAccumIndex != -1)
        {
            apSequence->SetEntryByte(inonAccumIndex, apSequence->GetEntryByte0d(iaccumIndex));
            break;
        }
    }

    ParseAnimationGroupFilename(apModelName, eanimMove, eanimWeapon, bpowerArmor);

    if (apSequence && apSequence->GetName_00700300())
    {
        unsigned int numKeys;
        char plocalKeyText[260];
        TimedTextEntry* key = apSequence->GetName_00700300()->GetKeys(numKeys);
        for (n = 0; n < numKeys; n++)
        {
            NiFixedString keyText(*(NiFixedString*)key[n].GetText());
            float time = key[n].GetTime();
            if (!keyText.Exists())
            {
                _FNV_Warning("ANIMATION: AnimGroup empty note key at time %.2f in sequence '%s' in model '%s'.", time,
                             (const char*)static_cast<const NiControllerSequence*>(apSequence)->GetName(), apModelName);
                bshowWarning = true;
            }
            else if (!__strnicmp(keyText, "prn:", 4))
            {
                if (((const char*)keyText)[4] != ' ')
                    panimGroup->SetParentName(keyText + 4);
                else
                    panimGroup->SetParentName(keyText + 5);
            }
            else
            {
                strcpy_s(plocalKeyText, 260, (const char*)keyText);
                char* ptoken = plocalKeyText;
                char* pfirstLineOfKeyText = plocalKeyText;
                while (ptoken && BSStringLength(ptoken))
                {
                    if (*ptoken == '\r')
                        ptoken = TESAnimGroup::FindNextLine(ptoken);
                    if (!__strnicmp(ptoken, DAT_011a8244, BSStringLength(DAT_011a8244)))
                    {
                        if (!panimGroup->GetMorphKey())
                            panimGroup->SetMorphKey(ptoken[2]);
                    }
                    else if (!__strnicmp(ptoken, "BlendIn:", 8))
                    {
                        if (ptoken[8] != ' ')
                            panimGroup->SetBlendIn(atol(ptoken + 8));
                        else
                            panimGroup->SetBlendIn(atol(ptoken + 9));
                    }
                    else if (!__strnicmp(ptoken, "BlendOut:", 9))
                    {
                        if (ptoken[9] != ' ')
                            panimGroup->SetBlendOut(atol(ptoken + 9));
                        else
                            panimGroup->SetBlendOut(atol(ptoken + 10));
                    }
                    else if (!__strnicmp(ptoken, "Blend:", 6))
                    {
                        if (ptoken[6] != ' ')
                            panimGroup->SetBlend(atol(ptoken + 6));
                        else
                            panimGroup->SetBlend(atol(ptoken + 7));
                    }
                    else if (!__strnicmp(ptoken, "Decal:", 6))
                    {
                        if (ptoken[6] != ' ')
                            panimGroup->SetDecal(atol(ptoken + 6));
                        else
                            panimGroup->SetDecal(atol(ptoken + 7));
                    }
                    else if (!__strnicmp(ptoken, "Sound:", BSStringLength("Sound:")) ||
                             !__strnicmp(ptoken, "Enum:", BSStringLength("Enum:")))
                    {
                        bool benum = false;
                        if (!__strnicmp(ptoken, "Enum:", BSStringLength("Enum:")))
                            benum = true;
                        if (panimGroup)
                        {
                            char* cr2 = strchr(ptoken, '\r');
                            if (cr2)
                                *cr2 = 0;
                            const char* soundID = ptoken;
                            if (benum)
                                soundID += BSStringLength("Enum: ");
                            else
                                soundID += BSStringLength("Sound: ");
                            strcpy_s(message, 260, soundID);
                            char* vol = 0;
                            char* pitch = 0;
                            char* cr = strchr(message, ',');
                            if (cr)
                            {
                                vol = cr + 1;
                            }
                            else
                            {
                                cr = strchr(message, ' ');
                                if (cr)
                                    vol = cr + 1;
                            }
                            if (cr)
                                *cr = 0;
                            if (vol)
                            {
                                while (*vol == ' ' && *vol != '\r')
                                    vol++;
                                cr = strchr(vol, ',');
                                if (cr)
                                {
                                    pitch = cr + 1;
                                }
                                else
                                {
                                    cr = strchr(vol, ' ');
                                    if (cr)
                                        pitch = cr + 1;
                                }
                                if (cr)
                                    *cr = 0;
                            }
                            bool bbadNote = false;
                            if (benum)
                            {
                                ANIM_ENUM etype = (ANIM_ENUM)0;
                                while (etype < 31 && _stricmp(DAT_01199b50[etype], message))
                                    etype = (ANIM_ENUM)(etype + 1);
                                if (etype < 31)
                                {
                                    unsigned int iElementIndex = ((ptoken - pfirstLineOfKeyText) << 8) | n;
                                    unsigned int m_uiSoundEntryCount = panimGroup->GetSoundCount();
                                    panimGroup->ResizeSoundList(m_uiSoundEntryCount + 1);
                                    panimGroup->SetSoundTime(m_uiSoundEntryCount, time);
                                    panimGroup->SetSoundEnum(m_uiSoundEntryCount, etype, iElementIndex);
                                }
                                else
                                {
                                    bbadNote = true;
                                }
                            }
                            else
                            {
                                TESSound* openSound = g_dataHandler->GetSoundByEditorID(message);
                                if (openSound)
                                {
                                    BSAudio::GetSingleton()->ForwardToManager(openSound->GetSoundID(), false);
                                    unsigned int m_uiSoundEntryCount = panimGroup->GetSoundCount();
                                    panimGroup->ResizeSoundList(m_uiSoundEntryCount + 1);
                                    panimGroup->SetSoundTime(m_uiSoundEntryCount, time);
                                    panimGroup->SetSound(m_uiSoundEntryCount, openSound);
                                    if (vol && *vol)
                                        panimGroup->SetSoundVolume(m_uiSoundEntryCount, atof(vol));
                                    if (pitch)
                                        panimGroup->SetSoundPitch(m_uiSoundEntryCount, atof(pitch));
                                }
                                else
                                {
                                    bbadNote = true;
                                }
                            }
                            if (bbadNote)
                            {
                                _FNV_Warning("ANIMATION: Bad note string \"%s\" frame %d in \"%s\".", ptoken,
                                             TruncateFloatToInt(time * 30.0), apModelName);
                                bshowWarning = true;
                            }
                            if (cr2)
                                *cr2 = '\r';
                        }
                    }
                    else
                    {
                        for (m = (ANIM_GROUP_ENUM)0; m < 245; m = (ANIM_GROUP_ENUM)(m + 1))
                        {
                            if (lastGroup != 0xff)
                                m = lastGroup;
                            if (!fnv_005f3a20::_stricmp(static_cast<const NiControllerSequence*>(apSequence)->GetName(), DAT_011977d8[m].pName))
                            {
                                lastGroup = m;
                                ANIM_GROUP_ACTION action = (ANIM_GROUP_ACTION)DAT_011977d8[m].m_iPadding[iactionIndex];
                                if (action == -1)
                                    break;
                                if (m == 2 && iactionIndex == 1 &&
                                    !__strnicmp(ptoken, DAT_01199a50[3][DAT_011977d8[m].iSequenceType],
                                                BSStringLength(DAT_01199a50[3][DAT_011977d8[m].iSequenceType])))
                                    iactionIndex = action = (ANIM_GROUP_ACTION)3;
                                if (DAT_011977d8[m].iSequenceType == 5 && iactionIndex == 2 &&
                                    !__strnicmp(ptoken, DAT_01199a50[3][DAT_011977d8[m].iSequenceType],
                                                BSStringLength(DAT_01199a50[3][DAT_011977d8[m].iSequenceType])))
                                    iactionIndex = action = (ANIM_GROUP_ACTION)3;
                                if (!__strnicmp(ptoken, DAT_01199a50[action][DAT_011977d8[m].iSequenceType],
                                                BSStringLength(DAT_01199a50[action][DAT_011977d8[m].iSequenceType])))
                                {
                                    if (!panimGroup)
                                    {
                                        if (m == 2)
                                            panimGroup = new TESAnimGroup((unsigned short)m);
                                        else
                                            panimGroup = new TESAnimGroup(
                                                TESAnimGroup::AnimGroup(eanimMove, eanimWeapon, m, bpowerArmor));
                                    }
                                    if (time > -1.0)
                                        panimGroup->SetActionTime(action, time);
                                    if (DAT_011977d8[m].iSequenceType == 1 && GetSequenceCycleType(apSequence))
                                    {
                                        if (DAT_011977d8[m].iLoopType != 1)
                                        {
                                            _FNV_Warning("ANIMATION: '%s' should be a looping animation.", apModelName);
                                            bshowWarning = true;
                                        }
                                    }
                                    else if (DAT_011977d8[m].iSequenceType != 1 && !GetSequenceCycleType(apSequence))
                                    {
                                        _FNV_Warning("ANIMATION: '%s' should NOT be a looping animation.", apModelName);
                                        bshowWarning = true;
                                    }
                                    iactionIndex++;
                                    break;
                                }
                                if (iactionIndex == 5 || DAT_011977d8[m].m_iPadding[iactionIndex] == -1)
                                {
                                    char* cr = strchr(ptoken, '\r');
                                    if (cr)
                                        *cr = 0;
                                    _FNV_Warning("ANIMATION: Bad note string \"%s\" frame %d in \"%s\".", ptoken,
                                                 TruncateFloatToInt(time * 30.0), apModelName);
                                    if (cr)
                                        *cr = '\r';
                                    bshowWarning = true;
                                }
                                break;
                            }
                            else if (m == lastGroup)
                            {
                                break;
                            }
                        }
                        if (m == 245)
                        {
                            _FNV_Warning("ANIMATION: AnimGroup unable to find sequence '%s' in model '%s'.",
                                         (const char*)static_cast<const NiControllerSequence*>(apSequence)->GetName(), apModelName);
                            bshowWarning = true;
                            ptoken = 0;
                            n = numKeys;
                        }
                    }
                    if (ptoken)
                        ptoken = TESAnimGroup::FindNextLine(ptoken);
                }
            }
        }

        if (panimGroup)
        {
            panimGroup->SetSoundsFromSequence(apSequence);
            ANIM_GROUP_ACTION estartAction = (ANIM_GROUP_ACTION)0;
            ANIM_GROUP_ACTION eendAction = (ANIM_GROUP_ACTION)1;
            switch (DAT_011977d8[panimGroup->GetType()].iSequenceType)
            {
            case 7:
                eendAction = (ANIM_GROUP_ACTION)4;
                break;
            case 8:
                eendAction = (ANIM_GROUP_ACTION)3;
                break;
            case 9:
                eendAction = (ANIM_GROUP_ACTION)3;
                break;
            case 5:
                if (panimGroup->GetActionTime(2) < panimGroup->GetActionTime(1))
                    panimGroup->SetActionTime(2, panimGroup->GetActionTime(1));
                eendAction = (ANIM_GROUP_ACTION)4;
                break;
            case 6:
                eendAction = (ANIM_GROUP_ACTION)2;
                break;
            case 10:
                eendAction = (ANIM_GROUP_ACTION)2;
                break;
            case 2:
                if (panimGroup->GetActionTime(1) < panimGroup->GetActionTime(0))
                    panimGroup->SetActionTime(1, panimGroup->GetActionTime(0));
                if (panimGroup->GetActionTime(2) <= panimGroup->GetActionTime(1))
                    panimGroup->SetActionTime(2, panimGroup->GetActionTime(3));
                eendAction = (ANIM_GROUP_ACTION)3;
                break;
            case 3:
            case 4:
                eendAction = (ANIM_GROUP_ACTION)2;
                break;
            }
            if (panimGroup->GetActionTime(eendAction) <= panimGroup->GetActionTime(estartAction))
            {
                _FNV_Warning("ANIMATION: (%s) End frame is less than or equal to Start frame in \"%s\".",
                             DAT_011977d8[panimGroup->GetType()].pName, apModelName);
                bshowWarning = true;
            }
            if (panimGroup->m_ucBlendCount && (panimGroup->m_ucBlendInCount || panimGroup->m_ucBlendOutCount))
            {
                _FNV_Warning("ANIMATION: (%s) too many blend values in \"%s\". Blend %d, BlendIn %d, BlendOut %d",
                             DAT_011977d8[panimGroup->GetType()].pName, apModelName, panimGroup->m_ucBlendCount,
                             panimGroup->m_ucBlendInCount, panimGroup->m_ucBlendOutCount);
                bshowWarning = true;
            }
        }
    }

    MessageHandler_IncDisableWarningCount(false);
    if (bshowWarning)
        _FNV_Warning("ANIMATION: Animation group note problem. See %s file.", TESFile::IsTempIDLoadable());
    return panimGroup;
}
}  // namespace fnv_005f3a20

// Returns true when the animation group's sType maps to one of the codes 0x5c through 0x65, otherwise false.
// @fnv 0x005f26c0
// src: COMMUNITY 0x005f26c0
bool TESAnimGroup::IsPowerAttack_005f26c0()
{
    switch (GetType(sType))
    {
    case 0x5c:
    case 0x5d:
    case 0x5e:
    case 0x5f:
    case 0x60:
    case 0x61:
    case 0x62:
    case 0x63:
    case 0x64:
    case 0x65:
        return true;
    default:
        return false;
    }
}

// FUN_005f2750: switch over a byte-coded action id; true for the listed action ids.
// @fnv 0x005f2750
// src: XBOX_PDB 0x005f2750
bool __cdecl TESAnimGroup_IsIronSightsAction(int a)
{
    switch (a)
    {
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2f:
    case 0x30:
    case 0x31:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0x6f:
    case 0x70:
    case 0x71:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x7b:
    case 0x7c:
    case 0x7d:
    case 0x81:
    case 0x82:
    case 0x83:
    case 0x87:
    case 0x88:
    case 0x89:
    case 0x8d:
    case 0x8e:
    case 0x8f:
    case 0x93:
    case 0x94:
    case 0x95:
        return true;
    default:
        return false;
    }
}

struct Holder
{
    char pad[0x1c];
    NiPoint3 m_vec;
    NiPoint3* GetVec(NiPoint3* out);
};

// Copies m_vec into the out parameter and returns out.
// @fnv 0x005f4c90
NiPoint3* Holder::GetVec(NiPoint3* out)
{
    // Use the trivial point assignment to preserve the original three word copies.
    *reinterpret_cast<NiPoint3*>(out) = *reinterpret_cast<const NiPoint3*>(&m_vec);
    return out;
}

