// src/fallout/interface/menus/startmenu_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/interface/menus/startmenu.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "../../../../include/BGSSaveLoadFileEntry.h"
// BGSSaveLoadUI_startmenu_rtm_variant: local type (was include/BGSSaveLoadUI.h, which had no evidence of one real class); its methods are 0x007d0bb0 XGamerProfile::ForcePresenceUpdate, 0x007d0bd0 XGamerProfile::SetPlayingFlag, 0x007d3170 XGamerProfile::GetRumbleDefault, 0x00a26120 XGamerProfile::RevokeCode
class BGSSaveLoadUI_startmenu_rtm_variant
{
public:
    void FUN_007d0bb0();
    void FUN_007d0bd0(bool);
    bool FUN_007d3170();
    bool FUN_00a26090(char*);
    bool FUN_00a26020(char const*);
    void FUN_00a26120(char*);
};
#include "../../../../include/ListBoxBase.h"
#include "../../../../include/OptionListBox.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/StartMenu.h"
#include "startmenu_packet.h"

class OSGlobals;
void FUN_007d1b30();
float FUN_007d1d00(int type);
void FUN_007d30d0();

#include <string.h>
#include <stdio.h>
struct MainMenuAudioAccess
{
    void FUN_00ad84e0(int, bool);
};
BSAudio* __cdecl FUN_00453a70();
struct MainMenuResetAccess
{
    void FUN_007d0b90();
};
struct MainMenuWorldAccess
{
    void FUN_00457d70(int, int, int);
};
// This player accessor is not yet declared by the shared PlayerCharacter header.
int __cdecl GetMediaLocationController();
typedef int (__thiscall* PlayerMediaAccessor)(PlayerCharacter*);
class TES;
void __cdecl PlayAudioMedia(int, const char*, unsigned int, bool, bool, float, unsigned int);
void __cdecl FUN_008304c0();
void __cdecl FUN_00703610();
void __cdecl FUN_00706320(int);
void __cdecl FUN_00761460(bool);
void __cdecl ResetTaskQueueGlobals();
BGSSaveLoadUI_startmenu_rtm_variant* __cdecl FUN_00a25920();
extern StartMenu* DAT_011daac0;
extern bool DAT_011daacd;
extern OSGlobals* g_osGlobals;
extern TES* g_TES;
extern PlayerCharacter* g_thePlayer;

// @fnv 0x007d0a70
void FUN_007d0a70()
{
    char acMusicPath[64];
    delete DAT_011daac0;
    FUN_00703610();
    FUN_00706320(0);
    ((MainMenuAudioAccess*)FUN_00453a70())->FUN_00ad84e0(-1, false);
    ResetTaskQueueGlobals();
    {
        int bIsChild = ((PlayerMediaAccessor)&GetMediaLocationController)(g_thePlayer);
        bIsChild = 0;
    }
    if (FUN_00a25920())
    {
        FUN_00a25920()->FUN_007d0bd0(false);
        FUN_00a25920()->FUN_007d0bb0();
    }
    DAT_011daacd = true;
    ((MainMenuResetAccess*)g_osGlobals)->FUN_007d0b90();
    ((MainMenuWorldAccess*)g_TES)->FUN_00457d70(1, 0, 0);
    memset(acMusicPath, 0, 64);
    sprintf_s(acMusicPath, 64, "Data\\Music\\Special\\MainTitle.mp3");
    FUN_00761460(true);
    PlayAudioMedia(8, acMusicPath, 5000, true, true, 0.0f, 0);
    FUN_008304c0();
}
