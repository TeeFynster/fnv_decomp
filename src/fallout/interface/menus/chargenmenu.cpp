
// src/fallout/interface/menus/chargenmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/chargenmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/ActorValueOwner.h"
#include "../../../../include/TESClass.h"
#include "../../../../include/CharGenMenu.h"
#include "../../../../include/Tile.h"
#include "../../../../include/Menu.h"
#include "../../../../include/Setting.h"

// @fnv 0x00753340
// src: COMMUNITY 0x00753340
int __thiscall CharGenMenu::GetMenuID_00753340()
{
    return 0x418;
}

// Stores tile into the CharGenMenu's tile array at index id when id is in [0, 7).
// @fnv 0x00753350
void CharGenMenu::SetTile(int aiIndex, Tile* tile)
{
    if (aiIndex >= 0 && aiIndex < 7)
    {
        m_pTiles[aiIndex] = tile;
    }
}

// @fnv 0x00753760
// src: COMMUNITY 0x00753760
int __cdecl CharGenMenu_GetMenuID_()
{
    return 0x418;
}

// @fnv 0x00753380: compiler-generated scalar deleting destructor for CharGenMenu.

extern "C" double _gModifierZero;
extern int DAT_011d9220;
extern int DAT_011d92a0;
struct PC7d
{
    TESClass* GetClass();
};
extern PC7d* g_thePlayer;
// @fnv 0x00754530
// src: COMMUNITY 0x00754530
void __cdecl CharGenMenu_TagSkillsFunc(Tile* tile, ActorValue::Index index)
{
    if (tile->GetFloat(0xfac) == _gModifierZero)
        DAT_011d92a0 = 0;
    if (tile->ContainsTrait(DAT_011d9220))
    {
        g_thePlayer->GetClass()->SetClassSkillAtIndex(DAT_011d92a0, index);
        DAT_011d92a0++;
    }
}

// Returns false if any of the seven tile slots is unset, otherwise true.
// @fnv 0x00753770
bool CharGenMenu::HasAllSlotsSet()
{
    for (int i = 0; i < 7; ++i)
        if (m_pTiles[i] == 0)
            return false;
    return true;
}

struct CharGenUISound
{
    static void __cdecl PlayUISound(int);
};

// @fnv 0x007542d0
bool __thiscall CharGenMenu::HandleButton(int aiButton, float afValue)
{
    bool bhandled = false;
    switch (aiButton)
    {
    case 11:
        if (m_pTiles[6]->ContainsTrait(0xFAF))
        {
            CharGenUISound::PlayUISound(1);
            HandleSelection(6, 0);
            bhandled = true;
        }
        break;
    }
    return bhandled;
}

extern CharGenMenu* DAT_011d920c;
// Clears the active menu; the shared list member and Menu base then destroy themselves.
// @fnv 0x007533b0
CharGenMenu::~CharGenMenu()
{
    DAT_011d920c = 0;
}

extern CharGenMenu* DAT_011d920c;
extern int DAT_011d9210;
extern int DAT_011d9214;
extern int DAT_011d9224;

// @fnv 0x00754330
// src: COMMUNITY 0x00754330
void __cdecl callback_Tile_T(Tile* tile)
{
    if (DAT_011d920c)
    {
        if (!DAT_011d920c->m_bValueStringNeedsUpdate)
        {
            DAT_011d920c->m_iPointsUsed +=
                (int)((double)tile->GetFloat(DAT_011d9210) + tile->GetFloat(DAT_011d9214) - 1.0);
        }
        tile->Set(DAT_011d9224, 0.0f, true);
        DAT_011d920c->UpdateValueString(tile);
    }
}

namespace fnv_007543c0 {

extern CharGenMenu* DAT_011d920c;
extern int DAT_011d9224;
// @fnv 0x007543c0
void __cdecl UpdateTagSkillTile(Tile* apTile, ActorValue::Index aeIndex)
{
    if (apTile->ContainsTrait(DAT_011d9220))
    {
        if (!DAT_011d920c->m_bValueStringNeedsUpdate ||
            !g_thePlayer->GetClass()->IsTagSkill(aeIndex))
        {
            apTile->Set(DAT_011d9220, 0);
            apTile->Set(DAT_011d9224, 0.0f, true);
        }
        else if (!DAT_011d920c->m_bValueStringNeedsUpdate)
        {
            DAT_011d920c->m_iPointsUsed++;
        }
    }
    DAT_011d920c->UpdateValueString(apTile);
}
}  // namespace fnv_007543c0

extern Setting g_011d390c;
extern Setting g_011d4138;
extern Setting g_011d4de0;
extern Setting g_011d3888;
extern char const g_011d3d6c_arg1[];

int __cdecl _sprintf_s(char*, unsigned int, char const*, ...);
int __cdecl FNV_strcat_s(char*, unsigned int, char const*);

// @fnv 0x00753d20
void CharGenMenu::UpdatePointsDisplay()
{
    const char* strtitleStrings[2];
    const char* strcounterStrings[2];
    int ipointsLeft;
    char strtemp[128];

    strtitleStrings[0] = g_011d390c.String();
    strtitleStrings[1] = g_011d4138.String();
    strcounterStrings[0] = g_011d4de0.String();
    strcounterStrings[1] = g_011d3888.String();

    ipointsLeft = m_iPointsRemaining - m_iPointsUsed;

    _sprintf_s(strtemp, 0x80, strtitleStrings[m_iSelectedAttributeIndex], m_iPointsUsed, m_iPointsRemaining);
    m_pTiles[0]->Set(0xfc4, strtemp, true);

    if (ipointsLeft == 0)
    {
        m_pTiles[4]->Set(0xfa3, 0);
    }
    else
    {
        _sprintf_s(strtemp, 0x80, strcounterStrings[m_iSelectedAttributeIndex], ipointsLeft);

        if (ipointsLeft != 1)
        {
            FNV_strcat_s(strtemp, 0x80, g_011d3d6c_arg1);
        }

        m_pTiles[4]->Set(0xfc4, strtemp, true);
        m_pTiles[4]->Set(0xfa3, 1);
    }
}

int __cdecl GetTileValueID(char const*, int);

struct FUN_00754950_shell
{
    bool __thiscall ListBox_enum_ActorValue_Index_IsSelected(Tile* apSelectItem);
};

// @fnv 0x00754950
// src: XBOX_PDB 0x00754950
bool FUN_00754950_shell::ListBox_enum_ActorValue_Index_IsSelected(Tile* apSelectItem)
{
    static int selectedTrait = GetTileValueID("_selected", -1);

    return selectedTrait != 0 && apSelectItem != 0 && apSelectItem->ContainsTrait(selectedTrait);
}

struct Proxy_884350
{
    void* Actor_GetClass();
};
struct Proxy_884350b
{
    void* Actor_GetClass(int, int);
};
struct Proxy_5f6e80
{
    void FUN_005f6e80();
};
extern int DAT_011dea3c;
int __cdecl NiStencilProperty_GetType();
void __cdecl CharGenMenu_SetAttributesFunc(Tile*, int);

// @fnv 0x007537b0
// src: XBOX_PDB 0x007537b0
void __cdecl CharGenMenu_Close()
{
    if (DAT_011d920c != 0)
    {
        if (DAT_011d920c->eMode == 0)
        {
            DAT_011d920c->list.Traverse((void(__cdecl*)(Tile*, ActorValue::Index))CharGenMenu_SetAttributesFunc, 0, 0x7fffffff);
        }
        else
        {
            for (int i = 0; ((Proxy_884350*)DAT_011dea3c)->Actor_GetClass(), i < NiStencilProperty_GetType(); i++)
            {
                ((Proxy_5f6e80*)((Proxy_884350b*)DAT_011dea3c)->Actor_GetClass(i, -1))->FUN_005f6e80();
            }
            DAT_011d920c->list.Traverse(CharGenMenu_TagSkillsFunc, 0, 0x7fffffff);
        }
        DAT_011d920c->FUN_00726070()->Set(0x1772, 1);
        DAT_011d920c->LoadMenuData();
    }
}

struct LBList
{
    virtual void Select(Tile*);
    void* FindItemData(Tile*);
};
char const* __cdecl ActorValue_GetActorValueIcon(ActorValue::Index);
char const* __cdecl GetActorValueDescription(ActorValue::Index);
void __cdecl Interface_PlayMenuSound(int);

// @fnv 0x00753870
void CharGenMenu::HandleTileClick(int id, Tile* tile)
{
    switch (id)
    {
    case 8:
    case 9:
        if (tile->GetFloat(0xfac) != unk50)
        {
            m_pTiles[2]->Set(0xfcc, ActorValue_GetActorValueIcon((ActorValue::Index)(int)((LBList*)&list)->FindItemData(tile)), true);
            m_pTiles[3]->Set(0xfc4, GetActorValueDescription((ActorValue::Index)(int)((LBList*)&list)->FindItemData(tile)), true);
            m_pTiles[2]->Set(0xfa3, 1);
            m_pTiles[3]->Set(0xfa3, 1);
            Interface_PlayMenuSound(4);
            unk50 = tile->GetFloat(0xfac);
        }
        break;
    case 10:
    case 11:
        ((LBList*)&list)->Select(tile->FUN_0045cd60());
        HandleMouseover(8, tile->FUN_0045cd60());
        break;
    }
}

namespace fnv_007539a0 {
struct List
{
    Tile* items;
    void FUN_0075a0d0(Tile*, const char*);
    Tile* AddListEntry(int, const char*, int, int);
};
struct Animation
{
    void InterfaceManager_TutorialManager_ShowMessage(int, int, int);
};
struct MenuState
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    Animation animation;
};
MenuState* __cdecl InterfaceManager_GetSingleton();
unsigned int __cdecl FUN_0066ecf0(int);
int __cdecl FUN_0066ec10(int, unsigned char);
const char* __cdecl FUN_0066e950(int);
struct Player
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    ActorValueOwner values;
};
extern Player* DAT_011dea3c;
extern int DAT_011d9210, DAT_011d9224;
extern const float DAT_01071c84;
extern const char DAT_01071c88[];

}  // namespace fnv_007539a0

// Builds attribute tiles and counts the points already assigned.

// @fnv 0x007539a0
void CharGenMenu::InitMenu()
{
    m_iPointsUsed = 0;
    if (!editing)
        m_iPointsRemaining -= 7;
    ((fnv_007539a0::List*)&list)->FUN_0075a0d0(m_pTiles[1], fnv_007539a0::DAT_01071c88);
    m_pTiles[1]->Tile_Set(4002, fnv_007539a0::DAT_01071c84, true);
    fnv_007539a0::InterfaceManager_GetSingleton()->animation.InterfaceManager_TutorialManager_ShowMessage(12, GetClass(), 500);
    for (unsigned int i = 0; i < fnv_007539a0::FUN_0066ecf0(0); ++i)
    {
        int e = fnv_007539a0::FUN_0066ec10(0, (unsigned char)i);
        Tile* j = ((fnv_007539a0::List*)&list)->AddListEntry(e, fnv_007539a0::FUN_0066e950(e), 0, 0);
        int c = fnv_007539a0::DAT_011dea3c->values.GetPermanentActorValue((ActorValue::Index)e);
        j->FUN_00700320(4010, 8);
        j->FUN_00700320(fnv_007539a0::DAT_011d9210, c);
        j->Tile_Set(fnv_007539a0::DAT_011d9224, 0.0f, true);
        UpdateValueString(j);
        if (!editing)
            m_iPointsUsed += c - 1;
    }
}

extern int DAT_011dea3c;


struct FUN_00754460_obj
{
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual void p123();
    virtual void p124();
    virtual void p125();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual void p133();
    virtual void p134();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual void p139();
    virtual void p140();
    virtual void p141();
    virtual void p142();
    virtual void p143();
    virtual void p144();
    virtual void p145();
    virtual void p146();
    virtual void p147();
    virtual void p148();
    virtual void p149();
    virtual void p150();
    virtual void p151();
    virtual void p152();
    virtual void p153();
    virtual void p154();
    virtual void p155();
    virtual void p156();
    virtual void p157();
    virtual void p158();
    virtual void p159();
    virtual void p160();
    virtual void p161();
    virtual void p162();
    virtual void p163();
    virtual void p164();
    virtual void p165();
    virtual void p166();
    virtual void p167();
    virtual void p168();
    virtual void p169();
    virtual void p170();
    virtual void p171();
    virtual void p172();
    virtual void p173();
    virtual void p174();
    virtual void p175();
    virtual void p176();
    virtual void p177();
    virtual void p178();
    virtual void p179();
    virtual void p180();
    virtual void p181();
    virtual void p182();
    virtual void p183();
    virtual void p184();
    virtual void p185();
    virtual void p186();
    virtual void p187();
    virtual void p188();
    virtual void p189();
    virtual void p190();
    virtual void p191();
    virtual void p192();
    virtual void p193();
    virtual void p194();
    virtual void p195();
    virtual void p196();
    virtual void p197();
    virtual void p198();
    virtual void p199();
    virtual void p200();
    virtual void p201();
    virtual void p202();
    virtual void p203();
    virtual void p204();
    virtual void p205();
    virtual void p206();
    virtual void p207();
    virtual void p208();
    virtual void p209();
    virtual void p210();
    virtual void p211();
    virtual void p212();
    virtual void p213();
    virtual void p214();
    virtual void p215();
    virtual void p216();
    virtual void p217();
    virtual void p218();
    virtual void p219();
    virtual void p220();
    virtual void p221();
    virtual void p222();
    virtual void p223();
    virtual void p224();
    virtual void p225();
    virtual void p226();
    virtual void p227();
    virtual void p228();
    virtual void v229(int, float);
    char pad_04[0xa0];
    ActorValueOwner m_a4;
    void PlayerCharacter_SetActorBaseValueF(int, float);
};

// @fnv 0x00754460
// src: COMMUNITY 0x00754460
void __cdecl CharGenMenu_SetAttributesFunc(Tile* pSelf, int a2)
{
    if (DAT_011d920c != 0 && DAT_011d920c->m_bValueStringNeedsUpdate != 0 &&
        DAT_011d920c->eMode == 0)
    {
        int v = ((FUN_00754460_obj*)DAT_011dea3c)->m_a4.GetBaseActorValue((ActorValue::Index)a2);
        ((FUN_00754460_obj*)DAT_011dea3c)->v229(a2, (float)((double)v + pSelf->FUN_00a011b0(DAT_011d9224)));
    }
    else
    {
        ((FUN_00754460_obj*)DAT_011dea3c)
            ->PlayerCharacter_SetActorBaseValueF(a2, (float)((double)pSelf->FUN_00a011b0(DAT_011d9210) + pSelf->FUN_00a011b0(DAT_011d9224)));
    }
}

extern const char str_01071c5c[], str_01071c08[], str_01071bfc[];
struct Manager753
{
    Tile* Root();
};
Manager753* __cdecl InterfaceManager_GetSingleton();
CharGenMenu* __cdecl Lookup753(int);
float __cdecl Scale753();
void __cdecl FNV_Warning(const char*);
int __cdecl Tile_TextToTrait(const char*);
extern Setting g_011d33d8, g_011d35c4;
struct List753
{
    Tile* Selected();
    int Value(Tile*);
};

extern CharGenMenu* menu753;
extern int DAT_011d9218, DAT_011d921c;
int __cdecl CharGenMenu_GetMenuID_();
const char* __cdecl Name753(int);
const char* __cdecl Desc753(int);
// Validates kind and points, rebuilds the menu from a tile file, attaches it, sets kind/points/flags and labels, then shows it and returns the tile.
// @fnv 0x00753420
// src: COMMUNITY 0x00753420
Tile* __cdecl CharGenMenu_Create(int kind, int points, bool onlyAdd, bool flag)
{
    CharGenMenu* oldMenu = Lookup753(0x418);
    Manager753* manager = InterfaceManager_GetSingleton();
    if (points <= 0 || kind < 0 || kind > 1)
        return 0;
    if (oldMenu)
        delete oldMenu;
    Tile* aTile = manager->Root()->ReadFile(str_01071c5c);
    menu753 = static_cast<CharGenMenu*>(aTile->GetMenu());
    if (menu753 && menu753->GetClass() == CharGenMenu_GetMenuID_())
    {
        menu753->FUN_00a1dc70((TileMenu*)aTile, false);
        if (!menu753->HasAllSlotsSet())
        {
            FNV_Warning(str_01071c08);
            return 0;
        }
        if (aTile->GetFloat(0xfa7) == 6006.0 || aTile->GetFloat(0xfa7) == 102.0)
            aTile->Set(0xfad, Scale753(), true);
        menu753->m_iPointsRemaining = points;
        menu753->eMode = kind;
        menu753->flag = flag;
        menu753->onlyAdd = onlyAdd;
        menu753->FUN_00726070()->SetInt(Tile_TextToTrait(str_01071bfc), onlyAdd);
        menu753->m_pTiles[5]->Set(0xfc4, g_011d33d8.String(), true);
        menu753->m_pTiles[6]->Set(0xfc4, g_011d35c4.String(), true);
        if (kind == 0)
            menu753->InitMenu();
        else
            menu753->BuildSkillList();
        menu753->FUN_00726070()->SetInt(DAT_011d9218, menu753->m_iPointsUsed);
        menu753->FUN_00726070()->SetInt(DAT_011d921c, menu753->m_iPointsRemaining);
        menu753->UpdatePointsDisplay();
        int iSelectedValue = ((List753*)&menu753->list)->Value(((List753*)&menu753->list)->Selected());
        menu753->m_pTiles[2]->Set(0xfcc, Name753(iSelectedValue), true);
        menu753->m_pTiles[3]->Set(0xfc4, Desc753(iSelectedValue), true);
        menu753->m_pTiles[2]->SetInt(0xfa3, 1);
        menu753->m_pTiles[3]->SetInt(0xfa3, 1);
        if (menu753)
        {
            menu753->FUN_00a1dc20(false);
            return aTile;
        }
    }
    else if (menu753 && menu753->FUN_00726070())
        delete menu753;
    return 0;
}

namespace fnv_00753b10 {
struct SkillList
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void Sort(void(__cdecl*)());
    void Initialize(Tile*, const char*);
    Tile* AddListEntry(ActorValue::Index, const char*, int, int);
};
struct SkillPlayer : PC7d
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    ActorValueOwner values;
};
struct SkillInterfacePart
{
    void InterfaceManager_TutorialManager_ShowMessage(int, int, int);
};
struct SkillInterface
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    SkillInterfacePart skills;
};
SkillInterface* __cdecl InterfaceManager_GetSingleton();
unsigned int __cdecl FUN_0066ecf0(int);
ActorValue::Index __cdecl FUN_0066ec10(int, unsigned char);
bool __cdecl ActorValue_IsFlagSet(ActorValue::Index, unsigned int);
const char* __cdecl FUN_0066e950(ActorValue::Index);
void __cdecl CompareActorValueNames();
extern Setting DAT_011ccf5c;
extern const char DAT_01071ca0[];
extern const float g_011c72f0_arg1;

}  // namespace fnv_00753b10

// Builds skill tiles with their values and tag state, then sorts the list.

// @fnv 0x00753b10
void CharGenMenu::BuildSkillList()
{
    ((fnv_00753b10::SkillList*)&list)->Initialize(m_pTiles[1], fnv_00753b10::DAT_01071ca0);
    m_pTiles[1]->Set(4002, fnv_00753b10::g_011c72f0_arg1, true);
    fnv_00753b10::InterfaceManager_GetSingleton()->skills.InterfaceManager_TutorialManager_ShowMessage(14, GetClass(), 500);
    for (unsigned int i = 0; i < fnv_00753b10::FUN_0066ecf0(2); ++i)
    {
        ActorValue::Index skill = fnv_00753b10::FUN_0066ec10(2, (unsigned char)i);
        if (!fnv_00753b10::ActorValue_IsFlagSet(skill, 8192))
        {
            Tile* tile = ((fnv_00753b10::SkillList*)&list)->AddListEntry(skill, fnv_00753b10::FUN_0066e950(skill), 0, 0);
            float value = (float)((fnv_00753b10::SkillPlayer*)g_thePlayer)->values.GetPermanentActorValue(skill);
            tile->SetName(fnv_00753b10::FUN_0066e950(skill));
            tile->Set(4010, 9);
            tile->Set(DAT_011d9210, value, true);
            if (g_thePlayer->GetClass()->IsTagSkill(skill))
            {
                tile->Set(DAT_011d9210, value - *fnv_00753b10::DAT_011ccf5c.Float(), true);
                if (showTagged)
                {
                    tile->Set(DAT_011d9220, 1);
                    tile->Set(DAT_011d9224, *fnv_00753b10::DAT_011ccf5c.Float(), true);
                    if (!editing)
                        ++m_iPointsUsed;
                }
            }
            UpdateValueString(tile);
        }
    }
    ((fnv_00753b10::SkillList*)&list)->Sort(fnv_00753b10::CompareActorValueNames);
}

class Handle754
{
  public:
    Handle754();
    Handle754(int iValue);
    ~Handle754();
    Handle754& operator=(const Handle754& kOther);

    int m_iValue;
    int unk04;
    int unk08;
};

class FUN_00754b40 : public Menu
{
  public:
    FUN_00754b40();
    virtual ~FUN_00754b40();

    // Menu ctor is 0x00a1c4a0; this derived layout starts its own fields at 0x70.
    unsigned char layoutExtension[0x48];
    int m_iIndex;
    bool m_bFlag;
    int unk78;
    Handle754 m_kHandle;
};

// Initializes the menu: clears m_bFlag, sets m_iIndex to -1, and assigns a zero-valued Handle754 to m_kHandle.
// @fnv 0x00754b40
FUN_00754b40::FUN_00754b40()
{
    m_bFlag = false;
    m_iIndex = -1;
    Handle754 kEmpty(0);
    m_kHandle = kEmpty;
}

struct Proxy_724430
{
    bool ListBox_enum_ActorValue_Index_IsEnabled();
};

struct Proxy_7242f0
{
    bool ContainsKey(void* value);
};

struct Proxy_754a00
{
    bool SetTraitSelected(void* parameter, int action);
};

extern void* volatile DAT_011d92ac;
extern volatile int DAT_011d92b0;
extern char const DAT_01071b64[];

struct ScopeGuard
{
    ~ScopeGuard()
    {}
};

// Checks the object and parameter, then sets the "_selected" trait on the parameter to 1, 0, or toggled based on action (0/1/2); returns true on success.
// @fnv 0x00754a00
bool Proxy_754a00::SetTraitSelected(void* pTarget, int action)
{
    if (((Proxy_724430*)this)->ListBox_enum_ActorValue_Index_IsEnabled())
    {
        if (pTarget != 0)
        {
            if (((Proxy_7242f0*)this)->ContainsKey(pTarget))
            {
                static int selectedTrait = GetTileValueID("_selected", -1);

                bool selected = static_cast<Tile*>(pTarget)->IsTraitNonZero(selectedTrait);

                switch (action)
                {
                case 0:
                    if (!selected)
                    {
                        static_cast<Tile*>(pTarget)->FUN_00700320(selectedTrait, 1);
                        return true;
                    }
                    break;
                case 1:
                    if (selected)
                    {
                        static_cast<Tile*>(pTarget)->FUN_00700320(selectedTrait, 0);
                        return true;
                    }
                    break;
                case 2:
                    static_cast<Tile*>(pTarget)->FUN_00700320(selectedTrait, selected ? 0 : 1);
                    return true;
                }
            }
        }
    }

    return false;
}

int __cdecl xMin(int, int);
int __cdecl MaxI(int, int);
int __cdecl GetTrait(char const*, int);
// Sums three tile reads, clamps the result by the menu mode, and sets the tile's _ValueString trait.
// @fnv 0x007545a0
void CharGenMenu::UpdateValueString(Tile* apTile)
{
    int iValue;
    char strtemp[16];
    iValue = (int)(apTile->Read(DAT_011d9210) + apTile->Read(DAT_011d9214) +
                   apTile->Read(DAT_011d9224));
    if (0 == eMode)
        iValue = xMin(MaxI(iValue, 1), 10);
    else if (1 == eMode)
        iValue = xMin(MaxI(iValue, 0), 100);
    _sprintf_s(strtemp, 16, "%d", iValue);
    apTile->Set(GetTrait("_ValueString", -1), strtemp, true);
}

struct SkPerkList
{
    bool FUN_005a5f40(void*);
};
struct SkMgr
{
    SkPerkList* Actor_GetClass();
};
extern SkMgr* g_skMgr_11dea3c;
extern Setting g_skSetting_11ccf5c;
struct SkItemList
{
    void* FindItemData(Tile*);
    void ListBox_enum_ActorValue_Index_ToggleSelection(Tile*);
    bool ListBox_enum_ActorValue_Index_IsSelected(Tile*);
};

// Processes skill menu commands by ID, toggling or adjusting skill points and updating the display accordingly.
// @fnv 0x00753ea0
void CharGenMenu::HandleSkillMenuCommand(int aiID, Tile* apTile)
{
    switch (aiID)
    {
    case 9: {
        void* pItemData = ((SkItemList*)&list)->FindItemData(apTile);
        bool selected = ((SkItemList*)&list)->ListBox_enum_ActorValue_Index_IsSelected(apTile);
        if ((!selected && m_iPointsUsed < m_iPointsRemaining) ||
            (selected && (!bLimit || !g_skMgr_11dea3c->Actor_GetClass()->FUN_005a5f40(pItemData))))
        {
            ((SkItemList*)&list)->ListBox_enum_ActorValue_Index_ToggleSelection(apTile);
            apTile->Tile_Set(DAT_011d9224, ((SkItemList*)&list)->ListBox_enum_ActorValue_Index_IsSelected(apTile) ? *g_skSetting_11ccf5c.Setting_Float_00403e20() : 0.0f,
                                  true);
            Interface_PlayMenuSound(3);
            m_iPointsUsed += selected ? -1 : 1;
            FUN_00726070()->Set(DAT_011d9218, m_iPointsUsed);
            UpdateValueString(apTile);
            UpdatePointsDisplay();
        }
        break;
    }
    case 10:
    case 11: {
        void* pEntry = ((SkItemList*)&list)->FindItemData(apTile->FUN_0045cd60());
        int delta = aiID != 10 ? 1 : -1;
        m_iPointsUsed += delta;
        FUN_00726070()->Set(DAT_011d9218, m_iPointsUsed);
        apTile->FUN_0045cd60()->Tile_Set(DAT_011d9224, apTile->FUN_0045cd60()->FUN_00a011b0(DAT_011d9224) + delta,
                                               true);
        UpdateValueString(apTile->FUN_0045cd60());
        UpdatePointsDisplay();
        break;
    }
    case 6:
        CharGenMenu_Close();
        break;
    case 5: {
        int iOldPointsUsed = m_iPointsUsed;
        m_iPointsUsed = 0;
        if (eMode == 0)
            list.Traverse((void(__cdecl*)(Tile*, ActorValue::Index))callback_Tile_T, 0, 0x7fffffff);
        if (eMode == 1)
            list.Traverse(fnv_007543c0::UpdateTagSkillTile, 0, 0x7fffffff);
        FUN_00726070()->Set(DAT_011d9218, m_iPointsUsed);
        UpdatePointsDisplay();
        if (m_iPointsUsed != iOldPointsUsed)
            Interface_PlayMenuSound(1);
        break;
    }
    }
}

struct SubList
{
    virtual void v0();
    virtual Tile* Selected();
};

// @fnv 0x00754150
// src: GUESS 0x00754150 (confidence: low)
bool CharGenMenu::UpdateState_00754150(int a1, float amount)
{
    bool result = false;

    switch (a1)
    {
    case 3:
    case 4:
        if (this->eMode == 0 && ((SubList*)&this->list)->Selected())
        {
            int var_8 = (a1 != 4) + 10;
            Tile* var_c = ((SubList*)&this->list)->Selected()->Tile_GetChildByID(var_8);
            if (var_c && var_c->IsTraitNonZero(0xfa3))
            {
                var_c->Tile_PlayTileSound(0xfcb);
                this->HandleSelection(var_8, var_c);
            }
            result = true;
        }
        break;

    case 9:
        if (this->eMode == 1 && ((SubList*)&this->list)->Selected())
        {
            this->HandleSelection(9, ((SubList*)&this->list)->Selected());
            result = true;
        }
        else if (this->eMode == 0)
        {
            result = this->HandleMenuInput(3, 1.0f);
        }
        break;

    case 10:
        if (this->eMode == 0)
        {
            result = this->HandleMenuInput(4, 1.0f);
        }
        break;
    }

    return result;
}
