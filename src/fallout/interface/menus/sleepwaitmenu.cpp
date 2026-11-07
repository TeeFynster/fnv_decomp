#include "../../../../include/BSStringT.h"

// src/fallout/interface/menus/sleepwaitmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/sleepwaitmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BGSSaveLoadGame.h"
#include "../../../../include/Setting.h"
#include "../../../../include/Menu.h"
#include "../../../../include/OSGlobals.h"
#include "../../../../include/SleepWaitMenu.h"
#include "../../../../include/Tile.h"
#include "../../../../include/ProcessLists.h"

// @fnv 0x007bfbc0
// src: COMMUNITY 0x007bfbc0
int SleepWaitMenu::GetClass_007bfbc0()
{
    return 0x3f4;
}

extern "C" void* __cdecl _Deallocate(void*);

// Returns this, and if bit 0 of flags is set, deallocates this before returning it.
// @fnv 0x007bfbd0
void* SleepWaitMenu::FUN_007bfbd0(unsigned int flags)
{
    this->SleepWaitMenu::~SleepWaitMenu();
    if (flags & 1)
        _Deallocate(this);
    return this;
}


struct Time
{
    float FUN_00867da0();
    ::BSStringT<char> FormatDate();
    const char* GetDayName();
};
extern Time DAT_011de7b8;
extern Setting DAT_011d24fc, DAT_011d27f0;
int __cdecl sprintf_s(char*, unsigned, const char*, ...);
// Builds a 12-hour clock string from the current game time and passes it to the tile via FUN_00a01350.
// @fnv 0x007c0000
void Menu::UpdateClockText()
{
    char szClockText[260];
    int hour;
    {
        float time = DAT_011de7b8.FUN_00867da0();
        hour = (int)time;
        {
            int minute = (int)((time - hour) * 60.0);
            if (time >= 0.0 && time < 1.0)
                hour = 12;
            else if (time >= 13.0)
                hour -= 12;
            sprintf_s(szClockText, 260, "%s, %s, %d:%02d %s", DAT_011de7b8.GetDayName(),
                      DAT_011de7b8.FormatDate().String(), hour, minute,
                      time < 12.0 ? DAT_011d24fc.FUN_00403df0() : DAT_011d27f0.FUN_00403df0());
        }
    }
    static_cast<SleepWaitMenu*>(this)->m_pTiles[SleepWaitMenu::TI_TIME_TEXT]->Tile_Set_00a01350(0xfc4, szClockText, true);
}

namespace fnv_007c01b0 {
// Exe 0x007c01b0: unit-local Interface view; declarations and layout are preserved.
struct SleepwaitmenuInterfaceView
{
    void FUN_007010e0(int, int);
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern ProcessLists DAT_011e0e80;
extern SleepwaitmenuInterfaceView* DAT_011d8804;
extern SleepWaitMenu* DAT_011da920;

// @fnv 0x007c01b0
// src: XBOX_PDB 0x007c01b0
void SleepWaitMenu_Close()
{
    if (DAT_011da920)
    {
        if (!g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
            DAT_011e0e80.UpdateActor3D();
        if (DAT_011da920->m_bState2)
            DAT_011d8804->FUN_007010e0(0, 0);
        DAT_011da920->FUN_00726070()->Set(0x1772, 1);
        DAT_011da920->FUN_00a1d910();
    }
}
}  // namespace fnv_007c01b0

extern void* DAT_011da918;
void* __cdecl Tile_TextToTrait(const char* asName);

// Initializes m_fCameraTransitionTime, m_bState1, m_fWaitTime and m_bState3 to zero and stores the result of FUN_00a01860("_current_value") in DAT_011da918.
// @fnv 0x007bfb30
SleepWaitMenu::SleepWaitMenu()
{
    m_fCameraTransitionTime = 0.0f;
    m_bState1 = 0;
    m_fWaitTime = 0.0f;
    m_bState3 = 0;
    DAT_011da918 = Tile_TextToTrait("_current_value");
}

namespace fnv_007c0220 {
struct DecCfg
{
    float* Setting_Float_00403e20(int);
};
struct DecGate
{
    const unsigned char* FUN_00408d60();
};
struct DecMenuA
{
    void ResetAndUpdate();
};
struct DecSnd
{
    void FUN_00700960(int, float);
};
struct DecMgr
{
    void FUN_005c1a00(int);
    void FUN_005c1a00(int, int);
    bool PlayerCharacter_GetInChargen();
};
struct DecBox
{
    void ProcessLists_StopAllActorsInDialog();
    void ProcessLists_KillAllProjectiles();
};

extern DecCfg DAT_011c3e7c;
extern DecGate DAT_011d89f0, DAT_011d8974;
extern DecMenuA* DAT_011de134;
extern DecSnd* DAT_011d8804;
extern int DAT_011da918;
extern DecMgr* DAT_011dea3c;
extern DecBox DAT_011e0e80;

int __cdecl FUN_00ec62c0();
void __cdecl InterfaceManager_PlayMenuSound(int);
void __cdecl FUN_004d5c60(int);
void __cdecl SleepWaitMenu_Close();

}  // namespace fnv_007c0220

// @fnv 0x007c0220
// src: XBOX_PDB 0x007c0220
void SleepWaitMenu::DoClick_007c0220(int slot, int value)
{
    using namespace fnv_007c0220;
    using fnv_007c0220::DAT_011da918;
    if (value == 0 && slot >= 0 && slot < 6)
    {
        value = reinterpret_cast<int>(m_pTiles[slot]);
    }
    switch (slot)
    {
    case 4:
        InterfaceManager_PlayMenuSound(1);
        if ((m_bState2 && *DAT_011d89f0.FUN_00408d60()) || (!m_bState2 && *DAT_011d8974.FUN_00408d60()))
        {
            DAT_011de134->ResetAndUpdate();
        }
        if (m_bState2 != 0)
        {
            DAT_011d8804->FUN_00700960(0, *DAT_011c3e7c.Setting_Float_00403e20(0));
        }
        m_bState1 = 1;
        m_pTiles[4]->FUN_00700320(0xfaf, 0);
        m_pTiles[1]->FUN_00700320(0xfaf, 0);
        // Preserve the original extra argument and ignored floating-point return.
        (m_pTiles[1]->*reinterpret_cast<void (Tile::*)(int, unsigned char)>(static_cast<float (Tile::*)(int)>(&Tile::FUN_00a011b0)))(DAT_011da918, static_cast<unsigned char>(m_bState2));
        DAT_011dea3c->FUN_005c1a00(FUN_00ec62c0() + 1);
        if (m_bState2 != 0)
        {
            FUN_004d5c60(0x17);
        }
        if (!DAT_011dea3c->PlayerCharacter_GetInChargen())
        {
            DAT_011e0e80.ProcessLists_StopAllActorsInDialog();
        }
        DAT_011e0e80.ProcessLists_KillAllProjectiles();
        break;
    case 5:
        InterfaceManager_PlayMenuSound(2);
        DAT_011dea3c->FUN_005c1a00(0, 0);
        SleepWaitMenu_Close();
        break;
    }
}

namespace fnv_007c04d0 {
extern float DAT_0104a494;
extern float DAT_010162c0;
extern int DAT_011da918;
extern char str_01070250[];
int __cdecl Tile_TextToTrait(const char* s);

}  // namespace fnv_007c04d0

// @fnv 0x007c04d0
// src: XBOX_PDB 0x007c04d0
bool SleepWaitMenu::DoGamepad_007c04d0(int a1, int aiUnused)
{
    using namespace fnv_007c04d0;
    using fnv_007c04d0::DAT_011da918;
    using fnv_007c04d0::Tile_TextToTrait;
    bool done = false;
    if (m_pTiles[TI_WAIT_BUTTON]->IsTraitNonZero(0xfaf))
    {
        if (a1 == 0xf || a1 == 0x10)
        {
            // Preserve the unused second argument passed by the original getter call.
            m_pTiles[TI_SCROLLBAR]->Tile_Set(DAT_011da918,
                (m_pTiles[TI_SCROLLBAR]->*reinterpret_cast<float (Tile::*)(int, int)>(static_cast<float (Tile::*)(int)>(&Tile::FUN_00a011b0)))(DAT_011da918, 0) + (a1 == 0xf ? DAT_0104a494 : DAT_010162c0));
            m_pTiles[TI_SCROLLBAR]->SetTraitFloat(Tile_TextToTrait(str_01070250), 1.0f);
            done = true;
        }
    }
    return done;
}

namespace fnv_007c03a0 {
extern int DAT_011da918;
extern Setting DAT_011d3ae0, DAT_011d448c;
int __cdecl FloatToInt(float f);
void __cdecl Interface_PlayMenuSound(int a);

}  // namespace fnv_007c03a0

// When the gauge value for DAT_011da918 changes, updates the cached value, optionally triggers FUN_00706f30(4), and writes a formatted string to the tile.
// @fnv 0x007c03a0
void SleepWaitMenu::UpdateGaugeDisplay()
{
    using namespace fnv_007c03a0;
    using fnv_007c03a0::DAT_011da918;
    char szText[260];
    if (m_pTiles[TI_SCROLLBAR]->FUN_00a011b0(DAT_011da918) != m_fWaitTime)
    {
        if (m_pTiles[TI_WAIT_BUTTON]->IsTraitNonZero(0xfaf))
        {
            Interface_PlayMenuSound(4);
        }
        m_fWaitTime = m_pTiles[TI_SCROLLBAR]->FUN_00a011b0(DAT_011da918);
        sprintf_s(szText, 0x104, "%d %s", FloatToInt((float)(m_fWaitTime + 1.0)),
                  (m_fWaitTime > 0.0) ? DAT_011d3ae0.FUN_00403df0() : DAT_011d448c.FUN_00403df0());
        m_pTiles[TI_HOURS_TEXT]->Tile_Set_00a01350(0xfc4, szText, true);
    }
}

// OSGlobals returns this input interface; no shared InputManager definition exists yet.
class InputManager
{
public:
    int Controls_GetUserAction();
};

struct PlayerStub
{
    bool FUN_0094df60();
    bool PlayerCharacter_IsHardcore();
    void PlayerCharacter_UpdateHardcoreMode();
    void PlayerCharacter_PlayerSleep();
    int PlayerCharacter_GetSleepHours();
};

struct TimeGlobalStub
{
    float FUN_0084d030();
};

struct TESStub
{
    void TES_RunScripts();
};

extern OSGlobals* DAT_011dea0c;
extern PlayerStub* DAT_011dea3c;
extern TESStub* DAT_011dea10;
extern TimeGlobalStub DAT_011f6394;

bool __cdecl Interface_IsConsoleVisible();

// Handles input state flags and, while m_bState1 is set, advances m_fCameraTransitionTime by the frame time and updates the tile's _current_value and _SetInCode when it reaches 1.0.
// @fnv 0x007c0580
// src: COMMUNITY 0x007c0580
bool SleepWaitMenu::UpdateSleep()
{
    if (DAT_011dea0c->Main_GetControls(15, 2)->Controls_GetUserAction())
    {
        m_bState3 = 1;
    }
    if ((m_bState3 && DAT_011dea0c->Main_GetControls(15, 1)->Controls_GetUserAction()) || (m_bState1 && !DAT_011dea3c->FUN_0094df60()))
    {
        if (!Interface_IsConsoleVisible())
        {
            HandleSelection(5, 0);
            return false;
        }
    }
    if (!m_bState1)
    {
        return false;
    }
    m_fCameraTransitionTime += DAT_011f6394.FUN_0084d030();
    if (m_fCameraTransitionTime >= 1.0)
    {
        m_fCameraTransitionTime = 0.0f;
    }
    else
    {
        return false;
    }
    DAT_011dea10->TES_RunScripts();
    if (DAT_011dea3c->PlayerCharacter_IsHardcore())
    {
        DAT_011dea3c->PlayerCharacter_UpdateHardcoreMode();
    }
    DAT_011dea3c->PlayerCharacter_PlayerSleep();
    m_pTiles[TI_SCROLLBAR]->FUN_00700320((int)Tile_TextToTrait("_current_value"), DAT_011dea3c->PlayerCharacter_GetSleepHours() - 1);
    m_pTiles[TI_SCROLLBAR]->SetTraitFloat((int)Tile_TextToTrait("_SetInCode"), 1.0f);
    UpdateClockText();
    return true;
}

float __cdecl FUN_00a01530();

extern SleepWaitMenu* g_pkSleepWaitMenu_011da920;

struct SwInterface
{
    Tile* CombatController_GetCombatState();
};
SwInterface* __cdecl InterfaceManager_GetSingleton();
int __cdecl ret_1012();
Menu* __cdecl Tile_GetMenuByClass(int m_uiSoundID);
void __cdecl Warning_005b5e40(const char* pcFormat, ...);
int __cdecl FUN_00406d30(char* pcDest, unsigned int uiSize, const char* pcSrc);
int __cdecl BSsprintf(char* pcDest, unsigned int uiSize, const char* pcFormat, ...);
extern "C" int __cdecl toupper(int c);

struct SwSoundHandle
{
    int unk00, unk04, unk08;
    ~SwSoundHandle();
    bool FUN_00ad8830();
};
struct SwAudio
{
    static SwAudio* GetSingleton();
    SwSoundHandle BSAudio_GetSoundHandleByEditorName(const char* pcName, unsigned int uiFlags, int i);
};

extern Setting g_s_011d3948;
extern Setting g_s_011d23ac;
extern Setting g_s_011d2910;
extern Setting g_s_011d448c;
extern Setting g_s_011d29f4;
extern Setting g_s_011d3174;

static const char s_szMenuPath[] = "Data\\Menus\\sleep_wait_menu.xml";
static const char s_szError[] = "MENUS: Sleep Wait Menu Creation Failed... Are your menu and art resources up to date?";
static const char s_szSound[] = "UIPopUpMessageGeneral";
static const char s_szTitleFormat[] = "%s %s?";
static const char s_szHourFormat[] = "1 %s";
static const char s_szBackground[] = "SWM_Background";
extern const char g_szSleepWaitEnd[] = "";

// Creates the sleep/wait menu from s_szMenuPath, sets its title, verb, hour, clock, and background, and returns the root tile or 0 on failure.
// @fnv 0x007bfc30
Tile* __cdecl CreateSleepWaitMenu(bool bSleep)
{
    SwInterface* pkInterfaceY = InterfaceManager_GetSingleton();
    Menu* pkOld_ = Tile_GetMenuByClass(ret_1012());
    if (pkOld_)
        delete pkOld_;
    Tile* pkTileTmp2 = pkInterfaceY->CombatController_GetCombatState()->Tile_ReadFile(s_szMenuPath);
    g_pkSleepWaitMenu_011da920 = static_cast<SleepWaitMenu*>(pkTileTmp2->Tile_GetMenu());
    if (g_pkSleepWaitMenu_011da920 && g_pkSleepWaitMenu_011da920->GetClass() == ret_1012())
    {
        g_pkSleepWaitMenu_011da920->FUN_00a1dc70(reinterpret_cast<TileMenu*>(pkTileTmp2), false);
        if (!g_pkSleepWaitMenu_011da920->QuantityMenu_IsWellFormedMenu())
        {
            Warning_005b5e40(s_szError);
            return 0;
        }
        SwAudio::GetSingleton()->BSAudio_GetSoundHandleByEditorName(s_szSound, 0x121, 0).FUN_00ad8830();
        if (pkTileTmp2->FUN_00a011b0(0xfa7) == 6006.0 || pkTileTmp2->FUN_00a011b0(0xfa7) == 102.0)
            pkTileTmp2->Tile_Set(0xfad, FUN_00a01530(), true);
        g_pkSleepWaitMenu_011da920->m_bSleep = bSleep;
        char acVerb[0x104];
        if (bSleep)
            FUN_00406d30(acVerb, 0x104, g_s_011d3948.FUN_00403df0());
        else
            FUN_00406d30(acVerb, 0x104, g_s_011d23ac.FUN_00403df0());
        char acText[0x104];
        BSsprintf(acText, 0x104, s_szTitleFormat, g_s_011d2910.FUN_00403df0(), acVerb);
        g_pkSleepWaitMenu_011da920->m_pTiles[SleepWaitMenu::TI_HOW_MANY_TEXT]->Tile_Set_00a01350(0xfc4, acText, true);
        acVerb[0] = toupper(acVerb[0]);
        g_pkSleepWaitMenu_011da920->m_pTiles[SleepWaitMenu::TI_WAIT_BUTTON]->Tile_Set_00a01350(0xfc4, acVerb, true);
        BSsprintf(acText, 0x104, s_szHourFormat, g_s_011d448c.FUN_00403df0());
        g_pkSleepWaitMenu_011da920->m_pTiles[SleepWaitMenu::TI_HOURS_TEXT]->Tile_Set_00a01350(0xfc4, acText, true);
        g_pkSleepWaitMenu_011da920->UpdateClockText();
        g_pkSleepWaitMenu_011da920->m_pTiles[SleepWaitMenu::TI_CANCEL_BUTTON]->Tile_Set_00a01350(0xfc4, g_s_011d29f4.FUN_00403df0(), true);
        g_pkSleepWaitMenu_011da920->FUN_00726070()
            ->GetNamedChild(s_szBackground)
            ->Tile_Set(0xfa9, *g_s_011d3174.Setting_Float_00403e20() * 255.0, true);
        g_pkSleepWaitMenu_011da920->FUN_00a1dc20(0);
        return pkTileTmp2;
    }
    else
    {
        if (g_pkSleepWaitMenu_011da920 && g_pkSleepWaitMenu_011da920->FUN_00726070())
            delete g_pkSleepWaitMenu_011da920;
    }
    return 0;
}

extern int DAT_011da920;
// Clears the active menu before the base menu is destroyed.
// @fnv 0x007bfc00
SleepWaitMenu::~SleepWaitMenu()
{
    DAT_011da920 = 0;
}
