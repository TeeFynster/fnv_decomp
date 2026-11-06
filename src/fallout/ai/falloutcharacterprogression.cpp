// fallout/ai/falloutcharacterprogression.cpp: Flt, NiNodeBooleanState_falloutcharacterprogression (11 functions)

// ActorValueUtility_falloutcharacterprogression: local type (was include/ActorValueUtility.h, which had no evidence of one real class); its methods are 0x00648b50 GamePlayFormulas::GetRequiredExperiencePoints
class ActorValueUtility_falloutcharacterprogression
{
public:
    static int __cdecl ConvertActorValue(int);
};
// BGSSaveLoadUI_falloutcharacterprogression: local type (was include/BGSSaveLoadUI.h, which had no evidence of one real class); its methods are 0x007d0bb0 XGamerProfile::ForcePresenceUpdate, 0x007d0bd0 XGamerProfile::SetPlayingFlag, 0x007d3170 XGamerProfile::GetRumbleDefault, 0x00a26120 XGamerProfile::RevokeCode
class BGSSaveLoadUI_falloutcharacterprogression
{
public:
    void FUN_007d0bb0();
    void FUN_007d0bd0(bool);
    bool FUN_007d3170();
    bool FUN_00a26090(char*);
    bool FUN_00a26020(char const*);
    void FUN_00a26120(char*);
};
// NiNodeBooleanState_falloutcharacterprogression: local type (was include/NiNodeBooleanState.h, which had no evidence of one real class); its methods are 0x008d0360 ReturnTrue, 0x008d51f0 CharacterProgression::QReadyToLevelUp, 0x008d5270 CharacterProgression::FinishLevelUp
#include "../../../include/NiAVObject.h"

class NiNode;

class NiNodeBooleanState_falloutcharacterprogression
{
public:
    NiPointer<NiNode> pData;

    __declspec(noinline) bool GetBooleanValue();
    void FUN_008d5270();
};
#include "../../../include/Actor.h"
#include "../../../include/ActorValueOwner.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/StatsMenu.h"
#include "../../../include/TESActorBaseData.h"
#include "../../../include/TESDataHandler.h"
#include "../../../include/BSAudio.h"

// @fnv 0x008d51f0
bool NiNodeBooleanState_falloutcharacterprogression::GetBooleanValue()
{
    return *reinterpret_cast<const bool*>(pData.operator->());
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct PlayerProgressionData
{
    void Initialize();
    bool CheckCanLevelUp(int);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void Revert(BGSLoadFormBuffer*);
    bool m_bFirstProgressionFlag;
    char _pad_1[3];
    int m_iProgressionValue;
    bool m_bSecondProgressionFlag;
    char _pad_9[3];
};
typedef char _sizecheck_CharacterProgressionData[sizeof(PlayerProgressionData) == 12 ? 1 : -1];
struct FUN_008d55e0_shell : public PlayerProgressionData
{
    bool FUN_008d55e0(int);
};

class GlobalObject2_0040c150
{
  public:
    int* Int();
};

extern GlobalObject2_0040c150 g_011d0c60;
extern PlayerCharacter* pPlayer;

// Returns true and sets the flag when the player is below the level cap and their actor value 0x18 meets the threshold for aiToLevel.
// @fnv 0x008d55e0
bool FUN_008d55e0_shell::FUN_008d55e0(int aiToLevel)
{
    bool bresult = false;
    if (pPlayer->Actor::GetLevel() >= *g_011d0c60.Int())
    {
        return false;
    }
    int inextThreshold = ActorValueUtility_falloutcharacterprogression::ConvertActorValue(aiToLevel);
    if (reinterpret_cast<ActorValueOwner*>(reinterpret_cast<char*>(pPlayer) + 0xa4)->GetActorValue((ActorValue::Index)0x18) >= inextThreshold)
    {
        m_bFirstProgressionFlag = true;
        bresult = true;
    }
    return bresult;
}

struct FUN_008d54e0_shell
{
    unsigned short FUN_008d54e0(unsigned int);
};

// Returns the sum of the constants 1 and 4 as an unsigned short.
// @fnv 0x008d54e0
unsigned short FUN_008d54e0_shell::FUN_008d54e0(unsigned int)
{
    unsigned short usTotal = 0;
    usTotal = usTotal + 1;
    usTotal = usTotal + 4;
    return usTotal;
}

namespace fnv_008d55b0 {
struct FUN_008d55b0_shell
{
    unsigned char m_b0;
    int m_i4;
    unsigned char m_b8;
    void __thiscall FUN_008d55b0();
};

// @fnv 0x008d55b0
void __thiscall FUN_008d55b0_shell::FUN_008d55b0()
{
    m_b0 = 0;
    m_i4 = ActorValueUtility_falloutcharacterprogression::ConvertActorValue(2);
    m_b8 = 0;
}
}  // namespace fnv_008d55b0

namespace fnv_008d5210 {
struct Flt
{
    operator unsigned int() const;
    void LevelUpPlayer();
};
struct Snd_
{
    void FUN_00ad7fa0(char const*, int);
};
// The shared audio header does not yet declare FUN_00ad7fa0(const char*, int).
extern PlayerCharacter* g_thePlayer;
void __cdecl FUN_00706270();
// If the flag is set, plays the UILevelUp sound, raises the player's actor base level by one and calls FUN_00706270.
// @fnv 0x008d5210
void Flt::LevelUpPlayer()
{
    if (!*(unsigned char*)(unsigned int)(*this))
        return;
    BSAudio::GetSingleton()->FUN_00ad7fa0("UILevelUp", 0x121);
    ((TESActorBaseData*)((char*)g_thePlayer->Actor::GetActorBase() + 0x30))->SetLevel(g_thePlayer->Actor::GetLevel() + 1);
    FUN_00706270();
}
}  // namespace fnv_008d5210

struct Flt
{
    operator unsigned int() const;
    void FUN_008d5510(int);
};
// The shared player header does not yet declare this stream operation.
struct PC7d
{
    void FUN_00484ce0(unsigned int, int);
};
extern PC7d* g_thePlayer;
// @fnv 0x008d5510
void Flt::FUN_008d5510(int aiUnused)
{
    g_thePlayer->FUN_00484ce0((unsigned int)*this, 1);
    g_thePlayer->FUN_00484ce0((unsigned int)*this + 4, 4);
}

namespace fnv_008d5550 {
struct Flt
{
    operator unsigned int() const;
    void FUN_008d5550(int, int);
};
// The shared player header does not yet declare this stream operation.
struct PC7d
{
    void FUN_00484d00(unsigned int, int);
};
extern PC7d* g_thePlayer;
// Calls FUN_00484d00 on g_thePlayer twice, passing the value of *this and *this + 4 with sizes 1 and 4.
// @fnv 0x008d5550
void Flt::FUN_008d5550(int, int)
{
    g_thePlayer->FUN_00484d00((unsigned int)*this, 1);
    g_thePlayer->FUN_00484d00((unsigned int)*this + 4, 4);
}
}  // namespace fnv_008d5550

struct FUN_008d5590_shell
{
    void __thiscall FUN_008d55b0();
    void* __thiscall FUN_008d5590();
};

// @fnv 0x008d5590
void* __thiscall FUN_008d5590_shell::FUN_008d5590()
{
    FUN_008d55b0();
    return this;
}

namespace fnv_008d5270 {
struct FUN_008d55e0_shell
{
    bool FUN_008d55e0(int);
};

extern PlayerCharacter* _g_thePlayer;

extern TESDataHandler* g_dataHandler;

struct DAT_011e0e80_class
{
    void FUN_00975ea0();
};
extern DAT_011e0e80_class DAT_011e0e80;

extern BGSSaveLoadUI_falloutcharacterprogression* __cdecl FUN_00a25920();

struct G7d1
{
    bool GetBoolValue();
};
extern G7d1 g_011e0a30;

}  // namespace fnv_008d5270

// @fnv 0x008d5270
void NiNodeBooleanState_falloutcharacterprogression::FUN_008d5270()
{
    using namespace fnv_008d5270;
    if (!((fnv_008d5270::FUN_008d55e0_shell*)pData.operator->())->FUN_008d55e0(_g_thePlayer->Actor::GetLevel() + 1))
    {
        *(char*)pData.operator->() = 0;
        g_dataHandler->GetRegions();
        DAT_011e0e80.FUN_00975ea0();
        if (FUN_00a25920())
        {
            FUN_00a25920()->FUN_007d0bb0();
        }
        if (g_011e0a30.GetBoolValue())
        {
            _g_thePlayer->WriteProgressData(0);
        }
    }
}

namespace fnv_008d5300 {
// The player is the shared PlayerCharacter; slot 234 (0x3a8) is Actor::ModActorValueInt (0x00880c70).
using ::PlayerCharacter;

void __cdecl _FUN_007df4e0();

extern PlayerCharacter* _g_thePlayer;

struct FUN_008d5300_shell
{
    void SetPlayerLevel(int aLevel);
};

// @fnv 0x008d5300
void FUN_008d5300_shell::SetPlayerLevel(int aLevel)
{
    if (aLevel == _g_thePlayer->Actor::GetLevel())
        return;

    int currentXP;
    char* data;
    int diff;

    {
        NiNodeBooleanState_falloutcharacterprogression* prog = (NiNodeBooleanState_falloutcharacterprogression*)reinterpret_cast<::PlayerCharacter*>(_g_thePlayer)->FUN_00464e10();
        data = (char*)prog->pData.operator->();
    }

    currentXP = reinterpret_cast<ActorValueOwner*>(reinterpret_cast<char*>(_g_thePlayer) + 0xa4)->GetActorValue((ActorValue::Index)0x18);

    {
        int reqXP = ActorValueUtility_falloutcharacterprogression::ConvertActorValue(aLevel - 1);
        diff = reqXP - currentXP;
    }

    data[8] = 1;
    _g_thePlayer->ModActorValueInt((ActorValue::Index)0x18, diff, 0);
    data[8] = 0;
    data[0] = 0;
    *(int*)(data + 4) = ActorValueUtility_falloutcharacterprogression::ConvertActorValue(aLevel + 1);

    ((TESActorBaseData*)((char*)reinterpret_cast<::Actor*>(_g_thePlayer)->GetActorBase() + 0x30))->SetLevel(aLevel);
    reinterpret_cast<NiNodeBooleanState_falloutcharacterprogression*>(this)->FUN_008d5270();
    _FUN_007df4e0();
    StatsMenu::UpdateStatusEffects();
}
}  // namespace fnv_008d5300

namespace fnv_008d53f0 {
extern double _gModifierZero;

void __cdecl QueueLevelUpNotification(int);

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011d0c60;

struct FUN_008d55e0_shell
{
    bool FUN_008d55e0(int);
};

extern PlayerCharacter* _g_thePlayer;

// @fnv 0x008d53f0
void FUN_008d53f0(void* apTarget, int a2, int aiUnused, float afValue)
{
    Actor* pActor = apTarget ? (Actor*)((char*)apTarget - 0xa4) : 0;
    if (pActor && pActor->IsPlayerRef())
    {
        NiNodeBooleanState_falloutcharacterprogression* prog = (NiNodeBooleanState_falloutcharacterprogression*)_g_thePlayer->FUN_00464e10();
        if (*(bool*)((char*)prog->pData.operator->() + 8))
            return;
        if (a2 == 0x18 && afValue > _gModifierZero)
        {
            if ((int)afValue > 0)
                QueueLevelUpNotification((int)afValue);
            if (_g_thePlayer->Actor::GetLevel() < *g_011d0c60.Int())
                ((FUN_008d55e0_shell*)prog->pData.operator->())
                    ->FUN_008d55e0(_g_thePlayer->Actor::GetLevel() + 1);
        }
    }
}
}  // namespace fnv_008d53f0
