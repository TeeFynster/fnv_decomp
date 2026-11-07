// src/fallout/interface/menus/startmenu_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/interface/menus/startmenu.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "../../../../include/BGSSaveLoadFileEntry.h"
// BGSSaveLoadUI_startmenu_rtm_variant: local type (was include/BGSSaveLoadUI.h, which had no evidence of one real class); its methods are 0x007d0bb0 XGamerProfile::ForcePresenceUpdate, 0x007d0bd0 XGamerProfile::SetPlayingFlag, 0x007d3170 XGamerProfile::GetRumbleDefault, 0x00a26120 XGamerProfile::RevokeCode
class BGSSaveLoadUI_startmenu_rtm_variant
{
public:
    void XGamerProfile_ForcePresenceUpdate();
    void XGamerProfile_SetPlayingFlag(bool);
    bool XGamerProfile_GetRumbleDefault();
    bool XGamerProfile_RedeemCode(char*);
    bool XGamerProfile_IsCodeRedeemed(char const*);
    void XGamerProfile_RevokeCode(char*);
};
#include "../../../../include/ListBoxBase.h"
#include "../../../../include/OptionListBox.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/StartMenu.h"
#include "startmenu_packet.h"

class OSGlobals;
void Get_fGamma();
float BSFadeNode_GetFadeOutMultiplier(int type);
void GetIsControllerDisabled();

#include <string.h>
#include <stdio.h>
struct MainMenuAudioAccess
{
    void BSAudio_KillAllOfType(int, bool);
};
BSAudio* __cdecl BSAudio_QInstance();
struct MainMenuResetAccess
{
    void kMainMenuFromIngameMenuRetnAddr();
};
struct MainMenuWorldAccess
{
    void TES_ShowLoadingMenu(int, int, int);
};
// This player accessor is not yet declared by the shared PlayerCharacter header.
int __cdecl GetMediaLocationController();
typedef int (__thiscall* PlayerMediaAccessor)(PlayerCharacter*);
class TES;
void __cdecl PlayAudioMedia(int, const char*, unsigned int, bool, bool, float, unsigned int);
void __cdecl FUN_008304c0();
void __cdecl Interface_HideMenus();
void __cdecl Interface_CloseAllSupportMenus(int);
void __cdecl FalloutAudio_SetMainMenuMusic(bool);
void __cdecl ResetTaskQueueGlobals();
BGSSaveLoadUI_startmenu_rtm_variant* __cdecl XGamerProfile_Instance();
extern StartMenu* DAT_011daac0;
extern bool DAT_011daacd;
extern OSGlobals* g_osGlobals;
extern TES* g_TES;
extern PlayerCharacter* g_thePlayer;

// @fnv 0x007d0a70
// src: XBOX_PDB 0x007d0a70
void StartMenu_ChooseMainMenu()
{
    char acMusicPath[64];
    delete DAT_011daac0;
    Interface_HideMenus();
    Interface_CloseAllSupportMenus(0);
    ((MainMenuAudioAccess*)BSAudio_QInstance())->BSAudio_KillAllOfType(-1, false);
    ResetTaskQueueGlobals();
    {
        int bIsChild = ((PlayerMediaAccessor)&GetMediaLocationController)(g_thePlayer);
        bIsChild = 0;
    }
    if (XGamerProfile_Instance())
    {
        XGamerProfile_Instance()->XGamerProfile_SetPlayingFlag(false);
        XGamerProfile_Instance()->XGamerProfile_ForcePresenceUpdate();
    }
    DAT_011daacd = true;
    ((MainMenuResetAccess*)g_osGlobals)->kMainMenuFromIngameMenuRetnAddr();
    ((MainMenuWorldAccess*)g_TES)->TES_ShowLoadingMenu(1, 0, 0);
    memset(acMusicPath, 0, 64);
    sprintf_s(acMusicPath, 64, "Data\\Music\\Special\\MainTitle.mp3");
    FalloutAudio_SetMainMenuMusic(true);
    PlayAudioMedia(8, acMusicPath, 5000, true, true, 0.0f, 0);
    FUN_008304c0();
}
