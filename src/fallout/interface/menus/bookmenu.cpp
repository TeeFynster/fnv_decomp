
// src/fallout/interface/menus/bookmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/bookmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSStringT.h"

#include "../../../../include/BSFile.h"
#include "../../../../include/NiFile.h"
#include "../../../../include/TESObject.h"
#include "../../../../include/BookMenu.h"
#include "../../../../include/Menu.h"
#include "../../../../include/Tile.h"
#include "../../../../include/InterfaceManager.h"

extern unsigned int DAT_01070ecc;

// Initializes the Menu base and sets the vtable pointer to DAT_01070ecc, then clears the two pointer fields.
// @fnv 0x0073acb0
BookMenu::BookMenu() : Menu()
{
    m_pHighlightedTile = 0;
    m_pObject = 0;
}

// @fnv 0x0073acf0
// src: COMMUNITY 0x0073acf0
int BookMenu::GetClass_0073acf0()
{
    return 0x402;
}

// Returns true if both tile pointers are non-zero, otherwise false.
// @fnv 0x0073af60
// src: XBOX_PDB 0x0073af60
bool __thiscall BookMenu::IsWellFormedMenu()
{
    if (m_pHighlightedTile && m_pObject)
        return true;
    return false;
}

// Handles the space key (0x20) by calling UpdateMenuTile and returning true; returns false for any other key.
// @fnv 0x0073b6b0
bool BookMenu::HandleKey(int aikey)
{
    if (aikey == 0x20)
    {
        this->UpdateMenuTile();
        return true;
    }
    return false;
}

void __cdecl _Deallocate(void*);
// Calls FUN_0073ad30, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x0073ad00
void* __thiscall BookMenu::FUN_0073ad00(unsigned int flags)
{
    SetVtableAndProcessState_0073ad30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct BSCullingProcess;
struct BSRenderedTexture;
struct BSShaderAccumulator;
struct ShaderRenderProperty;
struct FOPipboyManager;
struct FORenderedMenu;
struct ShadowLightData;
struct InventoryStackRecord;
struct ListBoxBase;
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
struct FUN_0073b020_shell : public InterfaceManager
{
    int InterfaceManager_GetCursorY();
};

float __cdecl InterfaceManager_GetScreenHeight();
// @fnv 0x0073b020
// src: COMMUNITY 0x0073b020
int FUN_0073b020_shell::InterfaceManager_GetCursorY()
{
    return (int)(InterfaceManager_GetScreenHeight() - (InterfaceManager_GetScreenHeight() / 2.0 + *(float*)((char*)this + 0x34)));
}

struct FUN_0073b460_shell
{
    bool __thiscall TESObjectBOOK_GetCantTake();
};
// @fnv 0x0073b460
// src: XBOX_PDB 0x0073b460
bool __thiscall FUN_0073b460_shell::TESObjectBOOK_GetCantTake()
{
    return (unsigned char)((char*)this)[0xc0] & 2;
}


// Stores apTile into one of two Tile pointers selected by aiID (0xb or 0xc).
// @fnv 0x0073af90
void BookMenu::SetTileByID(int aiID, Tile* apTile)
{
    switch (aiID)
    {
    case 0xb:
        m_pHighlightedTile = apTile;
        break;
    case 0xc:
        m_pObject = apTile;
        break;
    }
}

namespace fnv_0073afd0 {
InterfaceManager* __cdecl InterfaceManager_GetSingleton();
}  // namespace fnv_0073afd0

// For tile ID 12, stores the difference between the current tile's value and the interface manager's value.
// @fnv 0x0073afd0
// src: XBOX_PDB 0x0073afd0
void BookMenu::DoDownClick(int aiID, Tile* apTarget)
{
    InterfaceManager* pim;
    if (aiID == 12)
    {
        pim = fnv_0073afd0::InterfaceManager_GetSingleton();
        reinterpret_cast<float&>(unk38) = (double)m_pObject->GetScreenY() - pim->InterfaceManager_GetCursorY();
    }
}

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
// @fnv 0x0073b430
void __thiscall Holder73b430::CallInnerFoo()
{
    inner.foo(0, 0x43534544);
}

Tile* __cdecl FindMenuById(int);
void __cdecl InterfaceManager_PlayMenuSound(int);

// Gets tile 0x402, sets it to 0x1772/1, invokes its menu, then calls FUN_00717280 with 0x19 or 0x1b depending on FUN_00409700.
// @fnv 0x0073b480
void BookMenu::UpdateMenuTile()
{
    Tile* ptile = FindMenuById(0x402);
    if (ptile && ptile->GetMenu())
    {
        ptile->Set(0x1772, 1);
        ptile->GetMenu()->LoadMenuData();
        if (reinterpret_cast<TESObject*>(unk34)->TESObjectBOOK_GetScroll())
            InterfaceManager_PlayMenuSound(0x19);
        else
            InterfaceManager_PlayMenuSound(0x1b);
    }
}

struct FUN_007e7a80 : Menu
{
    char _pad[0x50];
    int m_78;
    int m_7c;
    FUN_007e7a80();
};
// Initialises the menu object: sets the vtable pointer, then sets m_78 and m_7c to -1.
// @fnv 0x007e7a80
FUN_007e7a80::FUN_007e7a80()
{
    m_78 = -1;
    m_7c = -1;
}

FUN_0073b020_shell* __cdecl _FUN_004b7210();
int __cdecl __ftol2_sse(double);

// @fnv 0x0073b050
// src: XBOX_PDB 0x0073b050
void BookMenu::DoStillDown(int aiID, Tile* apTarget)
{
    float imarker;
    FUN_0073b020_shell* pim;

    if (aiID == 0xc)
    {
        pim = _FUN_004b7210();
        imarker = (static_cast<double>(pim->InterfaceManager_GetCursorY()) + reinterpret_cast<float&>(unk38) - m_pHighlightedTile->GetScreenY()) /
                  m_pObject->GetFloat(0x100c);

        m_pHighlightedTile->Set(0x1009, static_cast<int>(0xc4653601));
        m_pHighlightedTile->Set(0x1009, static_cast<int>(imarker));
        m_pHighlightedTile->Set(0x1009, 0);
    }
}

// @fnv 0x0073ad30
// src: GUESS 0x0073ad30 (confidence: low)
void BookMenu::SetVtableAndProcessState_0073ad30()
{
    *reinterpret_cast<unsigned int*>(this) = (unsigned int)&DAT_01070ecc;
    FUN_00a1c520();
}

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
// Handles message 0x1f by calling UpdateMenuTile; for 0x20, passes a value from unk30 to DAT_011dea3c's vSlot, then calls UpdateMenuTile.
// @fnv 0x0073b0f0
void __thiscall BookMenu::HandleMessage(int msg, int unused)
{
    if (msg == 0x1f)
    {
        UpdateMenuTile();
        return;
    }
    if (msg == 0x20)
    {

        DAT_011dea3c->vSlot(reinterpret_cast<Obj30_0073b0f0*>(unk30), reinterpret_cast<Obj30_0073b0f0*>(unk30)->BSFile_GetDevice(0)->ExtraDataList_GetCount());
        UpdateMenuTile();
    }
}

struct BookInput
{
    bool TESObjectBOOK_GetScroll();
    const char* CallInnerFoo();
    bool TESObjectBOOK_GetCantTake();
};
// Updates the book menu tile: sets tile 0x1004 from input state, sets tile 0x1006 text, stores value in unk30, and sets tile 0x1007 and 0x100a.
// @fnv 0x0073b2f0
void BookMenu::UpdateBookMenu(BookInput* input, int value)
{
    if (input->TESObjectBOOK_GetScroll())
        static_cast<Tile*>(FUN_00726070())->FUN_00700320(0x1004, 0);
    else
        static_cast<Tile*>(FUN_00726070())->FUN_00700320(0x1004, 1);
    static_cast<Tile*>(FUN_00726070())->Tile_Set_00a01350(0x1006, input->CallInnerFoo(), true);
    unk30 = value;
    if (!value || input->TESObjectBOOK_GetCantTake())
        static_cast<Tile*>(FUN_00726070())->FUN_00700320(0x1007, 0);
    else
        static_cast<Tile*>(FUN_00726070())->FUN_00700320(0x1007, 1);
    BSStringT<char> text(input->CallInnerFoo());
    static_cast<Tile*>(FUN_00726070())->FUN_00700320(0x100a, -99999);
    static_cast<Tile*>(FUN_00726070())->FUN_00700320(0x100a, 0);
}

void __cdecl InterfaceManager_PlayMenuSound(int);

// @fnv 0x0073b150
void BookMenu::HandleScrollInput(int a1, int a2)
{
    InterfaceManager* interfaceManager6 = InterfaceManager::Instance();
    if (!static_cast<Tile*>(this->FUN_00726070())->IsTraitNonZero(0x1004))
    {
        int iVar1 = (int)this->m_pHighlightedTile->FUN_00a011b0(0x100b);
        int iVar6 = interfaceManager6->GetMouseWheel() / 120;
        this->m_pObject->Set(0x100d, -iVar6);
        this->m_pObject->Set(0x100d, 0);
        if (iVar1 != this->m_pHighlightedTile->FUN_00a011b0(0x100b))
        {
            this->HandleMouseoverTileAlt(a1, reinterpret_cast<Tile*>(a2));
            InterfaceManager::Instance()->SetMenuFocusEnabled(false);
        }
    }
    else
    {
        int iVar3 = (int)static_cast<Tile*>(this->FUN_00726070())->FUN_00a011b0(0x100d);
        if (interfaceManager6->GetMouseWheel() > 0)
        {
            static_cast<Tile*>(this->FUN_00726070())->Set(0x100a, -2);
        }
        else
        {
            static_cast<Tile*>(this->FUN_00726070())->Set(0x100a, 2);
        }
        static_cast<Tile*>(this->FUN_00726070())->Set(0x100a, 0);
        if (static_cast<Tile*>(this->FUN_00726070())->FUN_00a011b0(0x100d) != iVar3)
        {
            int iVar5 = (int)static_cast<Tile*>(this->FUN_00726070())->FUN_00a011b0(0x100c);
            if (iVar5 != 0)
            {
                InterfaceManager::Instance();
                InterfaceManager_PlayMenuSound(iVar5);
            }
        }
    }
}

extern const char DAT_01070fa8[];
extern const char DAT_01070f84[];

extern void __cdecl Interface_PrintLine(const char*, ...);
// Opens the book file, logs an error and returns if it fails, otherwise reads its text and passes it to the book tile with two 0x100a settings.
// @fnv 0x0073b500
void BookMenu::LoadBookFile()
{
    BSStringT<char> path2(DAT_01070fa8);
    BSFile file(path2.String(), NiFile::READ_ONLY, 0x4000, false);
    BSStringT<char> text6;
    unsigned int length = 0;
    file.FUN_00aff300(false, false);
    if (!file.TESAnimGroup_GetDecal())
    {
        Interface_PrintLine(DAT_01070f84, path2.String());
        return;
    }
    file.FUN_00aff7c0(&text6, -1);
    length = text6.Length();
    static_cast<Tile*>(FUN_00726070())->Tile_Set_00a01350(0x1006, text6.String(), true);
    static_cast<Tile*>(FUN_00726070())->FUN_00700320(0x100a, -99999);
    static_cast<Tile*>(FUN_00726070())->FUN_00700320(0x100a, 0);
}
