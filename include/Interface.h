#pragma once

// src: XBOX_PDB (Interface, class, sizeof 1); static call targets checked against the PC exe.
class TESModel;
class BGSLoadGameBuffer;
class Interface
{
public:
    enum FADE_STATE
    {
        FADE_SHOWN = 1,
        FADING_OUT = 2,
        FADE_HIDDEN = 4,
        FADING_IN = 8,
        FADE_ALL = 15,
        FADE_IN_SHOWN = 9,
        FADE_OUT_SHOWN = 3,
        FADE_NOT_HIDDEN = 11,
    };

    enum enumMenus
    {
        MessageMenu = 0x3e9, DialogueMenu = 0x3f1, MenuLoading = 0x3f5,
        Menu_3f6 = 0x3f6, Menu_41e = 0x41e, VATSMenu = 0x420,
        Menu_424 = 0x424, Menu_432 = 0x432, Menu_438 = 0x438,
        Menu_439 = 0x439, Menu_43a = 0x43a, Menu_43b = 0x43b
    };
    static bool IsInDialog(); // exe 0x007050d0
    static bool GetSelectedTargetIndex(enumMenus); // exe 0x00702450
    static bool IsMenuActive(enumMenus, unsigned int); // exe 0x00702680
    static bool IsPipboyMenuActive(); // exe 0x00705a00
    static bool IsConsoleActive(); // exe 0x00703d50
    static bool IsPipBoyOpen(); // exe 0x00704ad0, menu 1002 visibility
    static bool IsPipboyMenuOpen(); // exe 0x007079b0
    bool FaderManager_IsFaderActive(bool); // exe 0x007014a0
    static void PrintDebugMessage(BGSLoadGameBuffer*); // exe 0x0040fbe0

    static void SetHUDVisible(bool); // exe 0x00709c40
    static void ClearGunScope(); // exe 0x00709ca0
    static void InitGunScope(TESModel*);
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool); // exe 0x007052f0
    static void PlayUISound(int); // exe 0x00706f30
    static bool __cdecl IsSaveLoadActive();  // 0x00702360 (bound by actor, camerashake, inventorymenu)
    static bool IsGamePaused();  // 0x00705e80 (bound by teswater)
};
