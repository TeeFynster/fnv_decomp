#include "../../../../include/BSStringT.h"
#include "../../../../include/InterfaceManager.h"
#include "../../../../include/BookMenu.h"
#include "../../../../include/TESObjectBOOK.h"
#include "../../../../include/Menu.h"
#include "../../../../include/NiFile.h"
#include "../../../../include/BSFile.h"
#include "../../../../include/Tile.h"
#include "../../../../include/TileMenu.h"
// src/fallout/interface/menus/bookmenu_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (BookMenu, Menu, Tile). The skeleton of src/fallout/interface/menus/bookmenu.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.


// src/fallout/interface/menus/bookmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/bookmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern unsigned int DAT_01070ecc;
struct FUN_0073acb0 : Menu
{
    void* m_pHighlightedTile;
    void* m_pObject;
    FUN_0073acb0();
};
struct FUN_0073af60_shell
{
    int m_0x00;
    int m_0x04;
    int m_0x08;
    int m_0x0c;
    int m_0x10;
    int m_0x14;
    int m_0x18;
    int m_0x1c;
    int m_0x20;
    int m_0x24;
    int m_0x28;
    int m_0x2c;
    bool __thiscall IsWellFormedMenu();
};
void __cdecl _Deallocate(void*);
struct FUN_0073ad00_shell
{
    void __thiscall SetVtableAndProcessState_0073ad30();
    void* __thiscall FUN_0073ad00(unsigned int);
};
struct BSCullingProcess;
struct BSRenderedTexture;
struct BSShaderAccumulator;
struct ShaderRenderProperty;
struct FOPipboyManager;
struct FORenderedMenu;
struct ShadowLightData;
struct InventoryStackRecord;
struct ListBoxBase;
struct Menu;
struct MobileObject;
struct NiAVObject;
struct NiAlphaProperty;
struct NiDirectionalLight;
struct NiNode;
struct SceneGraph;
struct ShadowSceneNode;
struct TESImageSpaceModifier;
struct TESObjectREFR;
struct TileImage;
struct ViewCaster;
struct blob12
{
    char b[12];
};

// Exe 0x00709fd0 allocates the full 0x580-byte shared InterfaceManager.
struct FUN_0073b020_shell : public InterfaceManager
{
    int InterfaceManager_GetCursorY();
};
float __cdecl InterfaceManager_GetScreenHeight();
struct FUN_0073b460_shell
{
    bool __thiscall TESObjectBOOK_GetCantTake();
};
struct Inner73b430
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void foo(int, int)
    {}
};
struct Holder73b430
{
    char _pad[0x94];
    Inner73b430 inner;
    void __thiscall CallInnerFoo();
};
extern unsigned int DAT_01077abc;
struct FUN_007e7a80 : Menu
{
    char _pad[0x50];
    int m_78;
    int m_7c;
    FUN_007e7a80();
};
FUN_0073b020_shell* __cdecl _FUN_004b7210();
int __cdecl __ftol2_sse(double);
struct FUN_0073b050_shell : Menu
{
    Tile* m_pHighlightedTile;
    Tile* m_pObject;
    unsigned int m_0x30;
    unsigned int m_0x34;
    float m_fValue;

    void __thiscall DoStillDown(int, Tile*);
};
struct FUN_00a1c520_shell
{
    void __thiscall FUN_00a1c520();
};
struct Res_0073b0f0
{
    short ExtraDataList_GetCount();
};
struct Obj30_0073b0f0
{
    Res_0073b0f0* BSFile_GetDevice(int);
};
struct VT_0073b0f0
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void vSlot(Obj30_0073b0f0*, int);
};
extern VT_0073b0f0* DAT_011dea3c;
struct FUN_0073b0f0_cls
{
    char _pad[0x30];
    Obj30_0073b0f0* m_0x30;
    void __thiscall UpdateMenuTile();
    void __thiscall HandleMessage(int, int);
};
struct BookInput
{
    bool TESObjectBOOK_GetScroll();
    const char* CallInnerFoo();
    bool TESObjectBOOK_GetCantTake();
};

struct BookTarget : Menu
{
    void* unk28;
    void* unk2c;
    int unk30;
    Tile* FUN_00726070();
    void UpdateBookMenu(BookInput*, int);
};
void __cdecl InterfaceManager_PlayMenuSound(int);
struct BookMenu_Shell
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Tile* m_pHighlightedTile;
    Tile* m_pObject;

    Tile* FUN_00726070();
    void HandleScrollInput(int a1, int a2);
};
extern const char DAT_01070fa8[];
extern const char DAT_01070f84[];
extern void __cdecl Interface_PrintLine(const char*, ...);
struct LoadBook
{
    Tile* FUN_00726070();
    void LoadBookFile();
};

struct IMH
{
    Tile* CombatController_GetCombatState();
};
struct BookMenuData : Menu
{
    void* m_pHighlightedTile;
    void* m_pObject;
    void* unk30;
    TESObjectBOOK* m_pObjectToUpdateMenuTile;
    void UpdateBookMenu(TESObjectBOOK*, TESObjectREFR*);
};
struct MenuH
{
    virtual ~MenuH();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual int GetID();
    void SetTileMenu(TileMenu*, bool);
    void SetMenuVisibility(bool);
};
Menu* __cdecl FindMenuById(int);
InterfaceManager* __cdecl InterfaceManager_GetSingleton();
void __cdecl FNV_Warning(const char*, ...);
void __cdecl InterfaceManager_PlayMenuSound(int);
void* __fastcall FUN_00726070(Menu*);

// @fnv 0x0073ad50
// src: XBOX_PDB 0x0073ad50
Tile* __cdecl BookMenu_Create(TESObjectBOOK* apBook, TESObjectREFR* apRef)
{
    BookMenu* g_pHudMainMenuInstance;
    InterfaceManager* pin;
    Menu* pmenu;
    TESObjectBOOK* pbook;
    float ftop_depth;
    Tile* ptile;
    Tile* pold_menu_tile;
    pold_menu_tile = (Tile*)FindMenuById(0x402);
    if (pold_menu_tile)
        delete pold_menu_tile;
    pbook = apBook;
    if (!pbook)
        return 0;
    pin = InterfaceManager_GetSingleton();
    ftop_depth = Tile::GetInterfaceScale();
    ptile = 0;
    ptile = ((IMH*)pin)->CombatController_GetCombatState()->Tile_ReadFile("Data\\Menus\\book_menu.xml");
    pmenu = ptile->Tile_GetMenu();
    g_pHudMainMenuInstance = (BookMenu*)pmenu;
    ((BookMenuData*)g_pHudMainMenuInstance)->m_pObjectToUpdateMenuTile = apBook;
    if (pmenu && ((MenuH*)pmenu)->GetID() == 0x402)
    {
        ((MenuH*)pmenu)->SetTileMenu(dynamic_cast<TileMenu*>((Tile*)ptile), false);
        BookMenu* g_pHudMainMenuInstance = dynamic_cast<BookMenu*>(pmenu);
        if (!((FUN_0073af60_shell*)g_pHudMainMenuInstance)->IsWellFormedMenu())
        {
            FNV_Warning("MENUS: Book Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (ptile->GetFloat(0xfa7) == 6006.0 || ptile->GetFloat(0xfa7) == 102.0)
            ptile->Tile_Set(0xfad, ftop_depth, true);
        ((BookMenuData*)g_pHudMainMenuInstance)->UpdateBookMenu(apBook, apRef);
        if (((BookMenuData*)g_pHudMainMenuInstance)->m_pObjectToUpdateMenuTile->TESObjectBOOK_GetScroll())
            InterfaceManager_PlayMenuSound(0x18);
        else
            InterfaceManager_PlayMenuSound(0x1a);
        ((MenuH*)pmenu)->SetMenuVisibility(false);
        return ptile;
    }
    else if (pmenu && FUN_00726070(pmenu))
    {
        delete (MenuH*)pmenu;
    }
    return 0;
}
