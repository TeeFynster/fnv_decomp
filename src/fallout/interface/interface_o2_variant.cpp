
// src/fallout/interface/interface_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/interface/interface.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../include/BSSystemUtility.h"
#include "../../../include/QueuedTreeModel.h"
#include "interface_rebase_packet.h"
class TESWorldSpace;
class Menu;
class TESForm;
class NiControllerSequence;
// Exe 0x00b60040: unit-local InterfaceInterfaceView view used by this matched implementation.
class InterfaceInterfaceView
{
  public:
    static const char* GetInterfaceName();
    static float GetFirstInterfaceFloat();
    static float UpdateInterfaceState();
    static float GetThirdInterfaceFloat();
    static float GetFourthInterfaceFloat();
    static bool IsInterfaceOpen();
    static float GetInterfaceFloat();
    static Tile* GetPrimaryInterfaceTile();
    static Tile* GetSecondaryInterfaceTile();
    static NiNode* GetInterfaceNode();
    static bool IsAnyMenuOpen();

    static bool IsWorldSpaceEnabled(TESWorldSpace* apSpace);
    static bool IsInterfaceActive();

    enum enumMenus
    {
        eNoMenu = 0,
        eMainFour = 1,
        eOtherRoot = 2,
        eConsoleMenu = 3,
        eFirstMenu = 1001,
        eMessageMenu = 1001,
        eInventoryMenu = 1002,
        eStatsMenu = 1003,
        eHUDMainMenu = 1004,
        eLoadingMenu = 1007,
        eContainerMenu = 1008,
        eDialogMenu = 1009,
        eSleepWaitMenu = 1012,
        eStartMenu = 1013,
        eLockPickMenu = 1014,
        eQuantityMenu = 1016,
        eAudioMenu = 1017,
        eVideoMenu = 1018,
        eGameplayMenu = 1020,
        eMapMenu = 1023,
        eBookMenu = 1026,
        eLevelUpMenu = 1027,
        eBirthSignMenu = 1029,
        eRepairMenu = 1035,
        eRaceSexMenu = 1036,
        eCreditsMenu = 1047,
        eCharGenMenu = 1048,
        eTextEditMenu = 1051,
        eBarterMenu = 1053,
        eSurgeryMenu = 1054,
        eHackingMenu = 1055,
        eVATSMenu = 1056,
        eComputersMenu = 1057,
        eRepairServicesMenu = 1058,
        eTutorialMenu = 1059,
        eSPECIALBookMenu = 1060,
        eItemModMenu = 1061,
        eLoveTesterMenu = 1074,
        eCompanionWheelMenu = 1075,
        eTraitSelectMenu = 1076,
        eRecipeMenu = 1077,
        eSlotMachineMenu = 1080,
        eBlackJackMenu = 1081,
        eRouletteMenu = 1082,
        eCaravanMenu = 1083,
        eTraitMenu = 1084,
        eLastMenu = 1084
    };
    static void Init(bool);
    static void RefreshInterfaceState();
    static void SetQuestTarget(TESForm*, bool);
    static bool IsPipBoyOpen();
    static bool GetStatsMenuVisible();
    static bool IsGamePaused();
    static bool ContainerIsRecipe();
    static bool ContainerIsBarter();
    static void SetLookAtReference(TESObjectREFR*);
    static bool PlayNifSounds(NiControllerSequence*);
    static Menu* GetMenuById(int);
    static void SetHUDVisible(bool);
    static void SetTileFormattedText(Tile*, int, const char*, ...);
};
const char kMeshesFolder[] = "Meshes";
unsigned int FUN_00702440();
bool FUN_00705100();
unsigned int FUN_00706f20();
bool FUN_00707b50();

extern char* DAT_011f91c8;
extern unsigned char DAT_011f91d8;
void __fastcall FUN_00b5fd60(char*);
// @fnv 0x00b60040
void FUN_00b60040()
{
    char** p = &DAT_011f91c8;
    do
    {
        if (*p)
            FUN_00b5fd60(*p);
        p += 1;
    } while ((int)p < (int)&DAT_011f91d8);
}

void __cdecl BuildAssetPath(int, char*, int);
struct Inner060
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24(char*, int);
};
struct Outer060
{
    char _pad0[40];
    int _m28;
    char _pad1[4];
    Inner060 _m30;
    void FUN_00b60060();
};
// @fnv 0x00b60060
void Outer060::FUN_00b60060()
{
    char buf[0x104];
    BuildAssetPath(_m28, buf, 0x104);
    _m30.f24(buf, 0);
}

extern "C" char DAT_010ade08[];

// @fnv 0x00b600c0
bool QueuedTreeModel::FUN_00b600c0(char* pBuf, unsigned int uiSize)
{
    return FUN_00c3d0e0(pBuf, uiSize, DAT_010ade08);
}
