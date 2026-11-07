#include "../../../../include/InterfaceManager.h"
#include "../../../../include/Stack.h"
// fallout/interface/menus/statsmenu.cpp: StatsMenu, BodyPartDisplay, ClickMenu, BGSPerk and more (87 functions)

#include <windows.h>
#include "../../../../include/BSStringT.h"
#include "../../../../include/BSSimpleList.h"
#include "../../../../include/Setting.h"
#include "../../../../include/EffectItem.h"
#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../../../include/NiPointer.h"

// Keep unrelated private support templates distinct from shared dependencies.
#define _ULARGE_INTEGER StatsMenuPrivate_ULARGE_INTEGER
#include "../../../statsmenu_layout_support.h"
#undef _ULARGE_INTEGER

#include "../../../../include/ActiveEffect.h"
#include "../../../../include/Actor.h"
#include "../../../../include/ActorBaseAttributes.h"
#include "../../../../include/ActorValueModifierList.h"
#include "../../../../include/ActorValueOwner.h"
// ActorValueUtility_statsmenu: local type (was include/ActorValueUtility.h, which had no evidence of one real class); its methods are 0x00648b50 GamePlayFormulas::GetRequiredExperiencePoints
class ActorValueUtility_statsmenu
{
public:
    static int __cdecl ConvertActorValue(int);
};
#include "../../../../include/ActorValues.h"
#include "../../../../include/BGSPerk.h"
#include "../../../../include/BSSimpleArray.h"
#include "../../../../include/BaseExtraList.h"
#include "../../../../include/BaseFormComponent.h"
#include "../../../../include/CachedValuesOwner.h"
#include "../../../../include/Character.h"
#include "../../../../include/EffectSetting.h"
#include "../../../../include/ExtraDataList.h"
#include "../../../../include/FileEntryList.h"
#include "../../../../include/ListBoxBase.h"
#include "../../../../include/ListBox_PerkRankData___.h"
#include "../../../../include/ListBox_StatsMenu__StatusEffect___.h"
#include "../../../../include/ListBox_TESReputation___.h"
#include "../../../../include/ListBox_enum_ActorValue__Index_.h"
#include "../../../../include/ListBox_enum_MiscStatManager__MiscStatID_.h"
#include "../../../../include/MagicCaster.h"
// MagicEffectSystem_statsmenu: local type (was include/MagicEffectSystem.h, which had no evidence of one real class); its methods are 0x00403ab0 EffectArchetypes::Activate, 0x00403c80 EffectArchetypes::CheckFlag, 0x00810fd0 EffectSetting::GetEffectArchetype
class ActiveEffect;
class MagicCaster;
class MagicItem;
class TESBoundObject;

class MagicEffectSystem_statsmenu
{
public:
    struct _Type
    {
        enum Type
        {
            VALUE_MODIFIER,
            SCRIPT,
            DISPEL,
            CURE_DISEASE,
            ABSORB,
            SHIELD,
            CALM,
            DEMORALIZE,
            FRENZY,
            COMMAND_CREATURE,
            COMMAND_HUMANOID,
            INVISIBILITY,
            CHAMELEON,
            LIGHT,
            DARKNESS,
            NIGHT_EYE,
            LOCK,
            OPEN,
            BOUND_ITEM,
            SUMMON_CREATURE,
            DETECT_LIFE,
            TELEKINESIS,
            DISINTEGRATE_ARMOR,
            DISINTEGRATE_WEAPON,
            PARALYSIS,
            REANIMATE,
            SOUL_TRAP,
            TURN_UNDEAD,
            SUN_DAMAGE,
            VAMPIRISM,
            CURE_PARALYSIS,
            CURE_ADDICTION,
            CURE_POISON,
            CONCUSSION,
            VALUE_AND_PARTS,
            LIMB_CONDITION,
            TURBO,
            COUNT,
        };
    };

    typedef _Type::Type Type;

    static bool __cdecl IsFlagSet(Type type, unsigned int flags);
    static bool __cdecl IsFlagSet(int type, unsigned int flags);
    static ActiveEffect* Activate(MagicCaster*, MagicItem*, EffectItem*, TESBoundObject*);
};
#include "../../../../include/MagicTarget.h"
#include "../../../../include/MapEntryCount.h"
#include "../../../../include/Menu.h"
#include "../../../../include/MobileObject.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiTListBase_NiTPointerAllocator_unsigned_int__Tile___.h"
#include "../../../../include/NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator.h"
#include "../../../../include/NiTPointerAllocator_unsigned_int_.h"
#include "../../../../include/NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___.h"
#include "../../../../include/NiTPointerList_Tile___.h"
#include "../../../../include/PerkEntryConditionSet.h"
#include "../../../../include/PlacedObjectInfo.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/StatsMenu.h"
#include "../../../../include/StatsMenu__HealingOption.h"
#include "../../../../include/StatsMenu__NamedEffectsList.h"
#include "../../../../include/StatsMenu__StatusEffectList.h"
#include "../../../../include/TESActorBaseData.h"
#include "../../../../include/TESChildCell.h"
#include "../../../../include/TESDataHandler.h"
#include "../../../../include/TESDescription.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/TESFullName.h"
#include "../../../../include/TESIcon.h"
#include "../../../../include/TESModel.h"
#include "../../../../include/TESObjectCELL.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/TESTexture.h"
#include "../../../../include/Tile.h"
#include "../../../../include/TileMenu.h"
#include "../../../../include/TileRect.h"
#include "../../../../include/NiFile.h"
// Avoid the MSVC generated constructor-helper name in TESBoundObject.
#define __local_vftable_ctor_closure InitializeBoundVTable
#include "../../../../include/AlchemyItem.h"
#undef __local_vftable_ctor_closure
#include "../../../../include/BGSDefaultObjectManager.h"
#include "../../../../include/BGSDehydrationStage.h"
#include "../../../../include/BGSHungerStage.h"
#include "../../../../include/BGSRadiationStage.h"
#include "../../../../include/BGSSleepDeprevationStage.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/FOPipboyManager.h"
#include "../../../../include/InventoryStackRecord.h"
#include "../../../../include/MagicItem.h"
#include "../../../../include/Script.h"
#include "../../../../include/SpellItem.h"
#include "../../../../include/StartMenu.h"
#include "../../../../include/TESReputation.h"

#include "../../../statsmenu_types_MiscStatManager__MiscStatID.h"

extern PlayerCharacter* g_thePlayer;

#include "../../../../include/FORenderedMenu.h"
#include "../../../../include/GO.h"

// Unit-local method declaration until BSAudio's sound factory returns BSSoundHandle.
struct StatsMenuAudioMethods : BSAudio
{
    BSSoundHandle GetSoundHandleByEditorID(const char* editorID, unsigned int flags);
};

// Unit-local declaration for an accessor absent from ActiveEffect.h.
int __cdecl GetActiveEffectSpellType();
void __cdecl SetTileImageName();
bool __cdecl GetPlayerHardcoreMode();
int __cdecl CountPlayerItem();

static const int kGetClassValue = 1003;

// @fnv 0x0071f660
int StatsMenu::GetClass()
{
    return kGetClassValue;
}

// @fnv 0x007df1f0
float ActiveEffect::GetDuration() const
{
    return fDuration;
}
// @fnv 0x007df1d0
EffectSetting* ActiveEffect::GetEffectSetting() const
{
    return pEffect->GetEffectSetting();
}
// @fnv 0x007dd8a0
bool BGSPerk::IsPerkHidden() const
{
    return Data.bHidden;
}
// @fnv 0x007ddef0
float StatsMenu::GetChartScale()
{
    return 1000.0f;
}
// @fnv 0x007dfd00
void StatsMenu::SetStatsPage(unsigned char page)
{
    if (ms_pInventoryMenu)
        ms_pInventoryMenu->SetCurrentPage(static_cast<Page>(page));
}
// Returns the current page as a Page enum, read from the menu's float value at 0x1004.
// @fnv 0x007dcc00
StatsMenu::Page StatsMenu::GetCurrentPage()
{
    return static_cast<Page>(static_cast<unsigned int>(pMenu->GetFloat(0x1004)));
}
// Maps HEALTH, ACTION_POINTS and EXPERIENCE_POINTS actor values to trait IDs 0x1009-0x100B, returning INT_MIN otherwise.
// @fnv 0x007dfdf0
int StatsMenu::GetTraitForValue(ActorValue::Index value)
{
    switch (value)
    {
    case ActorValue::ActorValue__Index_HEALTH:
        return 0x1009;
    case ActorValue::ActorValue__Index_ACTION_POINTS:
        return 0x100A;
    case ActorValue::ActorValue__Index_EXPERIENCE_POINTS:
        return 0x100B;
    default:
        return (-2147483647 - 1);
    }
}
// @fnv 0x007df5d0
void StatsMenu::UpdateStatusEffects()
{
    if (ms_pInventoryMenu && ms_pInventoryMenu->m_pTiles[37])
        ms_pInventoryMenu->m_pTiles[37]->Set(0xFC4, TESActorBaseData::GetActorDisplayName(g_thePlayer), true);
}
// @fnv 0x007dda60
void StatsMenu::ClearPerks()
{
    if (ms_pInventoryMenu && ms_pInventoryMenu->m_pTiles[34])
        ((void (__thiscall*)(ListBoxBase*))(*(void***)&ms_pInventoryMenu->m_kPerkRankList)[7])(&ms_pInventoryMenu->m_kPerkRankList);
}
// @fnv 0x007ddad0
void StatsMenu::RefreshMiscStat(MiscStatManager__MiscStatID value)
{
    UpdateMiscStatTile(m_kMiscStatList.GetTileForData(value), value);
}
// @fnv 0x007dcfc0
void StatsMenu::UpdateActorValueTiles()
{
    RefreshActorValueTile(ActorValue::ActorValue__Index_HEALTH);
    RefreshActorValueTile(ActorValue::ActorValue__Index_ACTION_POINTS);
    RefreshActorValueTile(ActorValue::ActorValue__Index_EXPERIENCE_POINTS);
    RefreshActorValueTile(ActorValue::ActorValue__Index_RADIATION_RADS);
    RefreshActorValueTile(ActorValue::ActorValue__Index_RADIATION_RESISTANCE);
    for (int value = 25; value < 32; ++value)
        RefreshActorValueTile(static_cast<ActorValue::Index>(value));
    m_pTiles[6]->Set(0x1004, 0);
    m_kPrimaryActorValueList.Traverse(UpdatePrimaryActorValueTile, 0, 2147483647);
    m_pTiles[7]->Set(0x1004, 0);
    m_kSecondaryActorValueList.Traverse(UpdateSecondaryActorValueTile, 0, 2147483647);
    RefreshActorValueTile(ActorValue::ActorValue__Index_KARMA);
}
// Sets a tile's current actor value and, if it differs from the permanent value, marks it with a (+)/(-) indicator and flags the parent.
// @fnv 0x007dfa30
void StatsMenu::UpdatePrimaryActorValueTile(Tile* tile, ActorValue::Index value)
{
    if (tile)
    {
        struct ComparedActorValues
        {
            int current;
            int permanent;
        } values;
        values.current = g_thePlayer->GetActorValueAsInteger(value);
        values.permanent = g_thePlayer->GetPermanentActorValue(value);
        tile->Set(0x1005, values.current);
        if (values.permanent == values.current)
            tile->Set(0x1004, 0);
        else
        {
            tile->Set(0x1004, 1);
            tile->Set(0x1006, values.current > values.permanent ? "(+)" : "(-)", true);
            tile->GetParent()->Set(0x1004, 1);
        }
    }
}

// @fnv 0x007df1b0
bool EffectSetting::IsScriptEffect()
{
    return MagicEffectSystem_statsmenu::IsFlagSet(GetArchetype(), 0x40);
}

struct OptSI
{
    int pad;
    const char* name;
};
struct VObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    void ListBox_StartMenu_Option_SetEnabled(int);
    Tile* CreateListItem(OptSI*, int, int, int);
};
struct MenuSI
{
    char pad0[0x44];
    Tile* t44;
    char pad1[0x30];
    Tile* t78;
    char pad2[0x68];
    VObj e4;
    void FadeTile(int, int, unsigned int, float);
    void PopulateListBoxTiles(void*, int, int, int, bool);
};
struct ListBoxSI
{
    bool AddItem(void*);
};
// Exe 0x007d49a0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct StatsmenuOffset08View
{
    unsigned int GetFlags();
    OptSI*& GetAt(unsigned int);
};
extern StatsmenuOffset08View g_011dab88;
// Resets the menu, sets tile values from a, b, c and d, then adds each entry of g_011dab88 to lb and creates a named tile for it.
// @fnv 0x007d49a0
void MenuSI::PopulateListBoxTiles(void* apListBox, int aiValueA, int aiValueB, int auiValueC, bool abFlag)
{
    unsigned int i;
    this->e4.v7();
    this->e4.ListBox_StartMenu_Option_SetEnabled(1);
    this->FadeTile(7, 1, 0x80000000, -1.0f);
    ((Tile*)this->t44)->Set(0xfa1, (float)(aiValueA - ((Tile*)this->t44->GetParent())->GetTotalFloat()), true);
    ((Tile*)this->t44)->Set(0xfa2, (float)(aiValueB - ((Tile*)this->t44->GetParent())->GetScreenY()), true);
    ((Tile*)this->t44)->Set(0xfb1, (unsigned int)auiValueC);
    this->t78->Set(0xfa3, (int)abFlag);
    for (i = 0; i < g_011dab88.GetFlags(); i++)
    {
        if (((ListBoxSI*)g_011dab88.GetAt(i))->AddItem(apListBox))
        {
            Tile* ptile = this->e4.CreateListItem(g_011dab88.GetAt(i), 0, 0, 0);
            ptile->Set(0xfc4, g_011dab88.GetAt(i)->name, true);
            ((Tile*)ptile)->SetName(g_011dab88.GetAt(i)->name);
        }
    }
}

// Supplemental entry points absent from the shared headers add no data or virtual slots.
struct StatusPageMenuMethods : public StatsMenu
{
    int StatsMenu_GetStatusPage();
};

// @fnv 0x007dcc40
// src: XBOX_PDB 0x007dcc40
int StatusPageMenuMethods::StatsMenu_GetStatusPage()
{
    return (unsigned int)m_pTiles[5]->GetFloat(0x1004);
}

// @fnv 0x007df210
// src: XBOX_PDB 0x007df210
bool ActiveEffect::HasConditions()
{
    return (iFlags & 0x80) != 0;
}

int __cdecl TruncateFloatToInt(float);
float __cdecl GetSkillValue(void*, int, bool);

// @fnv 0x007dfb00
void __cdecl UpdateActorValueTile(Tile* apTile, ActorValue::Index aeIndex)
{
    if (apTile)
    {
        int ival = g_thePlayer->GetActorValueAsInteger(aeIndex);
        int ibase = g_thePlayer->GetPermanentActorValue(aeIndex);
        float fderivedVal = GetSkillValue((ActorValueOwner*)g_thePlayer, aeIndex, false);
        float fderivedBase = GetSkillValue((ActorValueOwner*)g_thePlayer, aeIndex, true);
        int idelta = (ival - ibase) + TruncateFloatToInt(fderivedVal - fderivedBase);

        apTile->Set(0x1005, ival);
        if (idelta != 0)
        {
            apTile->Set(0x1004, 1);
            apTile->Set(0x1006, idelta > 0 ? "(+)" : "(-)", true);
            apTile->GetParent()->Set(0x1004, 1);
        }
        else
        {
            apTile->Set(0x1004, 0);
        }
    }
}

int __cdecl MiscStatManager_GetVal(int);

// If apTile is non-null, calls Set with 0x1005 and the result of FUN_005a3370(aeID).
// @fnv 0x007dfc60
// src: XBOX_PDB 0x007dfc60
void __cdecl StatsMenu_MiscStatsUpdateFn(Tile* apTile, int aeID)
{
    if (apTile)
    {
        apTile->Set(0x1005, MiscStatManager_GetVal(aeID));
    }
}

bool __fastcall PlayerCharacter_IsHardcore(PlayerCharacter* pPlayer);
bool __cdecl InterfaceManager_Has360Controller(void);
int __cdecl GetStatusResult(void);

// Checks whether the player's current actor value is below its permanent value, choosing the target actor value based on hardcore mode and aHO[2].
// @fnv 0x007e05f0
bool __cdecl IsActorValueBelowPermanent(int* aHO)
{
    bool bIsHardcore = PlayerCharacter_IsHardcore(g_thePlayer);
    if (aHO[2] != 0)
    {
        int etargetAV = GetStatusResult();
        if (bIsHardcore && etargetAV != -1)
        {
            return false;
        }
        else
        {
            if (bIsHardcore || !InterfaceManager_Has360Controller() || etargetAV == -1)
            {
                etargetAV = 0x10;
            }
        }
        return ((ActorValueOwner*)((char*)g_thePlayer + 0xa4))->GetActorValue((ActorValue::Index)etargetAV) <
               ((ActorValueOwner*)((char*)g_thePlayer + 0xa4))->GetPermanentActorValue((ActorValue::Index)etargetAV);
    }
    else
    {
        return false;
    }
}

struct Dummy_0071f9c0
{
    void* FUN_0071f9c0(unsigned int);
};

bool __fastcall _ref_008256d0(void*);
Dummy_0071f9c0** __fastcall _ref_006815c0(void*);
void* __fastcall FUN_0071f9c0(Dummy_0071f9c0*, int, unsigned int);
void __fastcall _ref_0063f7b0(void*);

struct Caller_0071f9c0
{
    void* call_del(unsigned int f)
    {
        return FUN_0071f9c0((Dummy_0071f9c0*)this, 0, f);
    }
};

// @fnv 0x007e07f0
// src: XBOX_PDB 0x007e07f0
void __fastcall StatsMenu_StatusEffectList_Flush(char* this_ptr)
{
    while (!_ref_008256d0(this_ptr + 4))
    {
        Dummy_0071f9c0* p1;
        Dummy_0071f9c0* p2 = (p1 = *_ref_006815c0(this_ptr + 4));
        (p2 != 0) ? ((void*(__thiscall*)(Dummy_0071f9c0*, unsigned int))FUN_0071f9c0)(p2, 1) : 0;
        _ref_0063f7b0(this_ptr + 4);
    }
}

struct SpellListEntry;
struct BSCullingProcess;
struct BSRenderedTexture;
struct BSShaderAccumulator;
struct ShaderRenderProperty;
struct FORenderedMenu;
struct ShadowLightData;
struct NiAVObject;
struct NiAlphaProperty;
struct NiDirectionalLight;
struct NiNode;
struct SceneGraph;
struct ShadowSceneNode;
struct TESFile;
struct TESImageSpaceModifier;
struct TileImage;
struct ViewCaster;
struct blob12
{
    char b[12];
};

// Exe 0x00709fd0 allocates the full 0x580-byte shared InterfaceManager.

struct P09AV
{
    static bool __cdecl GetFlag(int, unsigned int);
};

struct IMH
{
    Tile* CombatController_GetCombatState();
};
// BSStringT<char>'s append-by-string overload at 0x007e0d80 is absent from the shared header.
BSStringT<char>& __cdecl AppendStatsEffectString();
struct EquipTypeComponent
{
    int GetEquipType();
};
class StatsMenu__StatusEffect
{
  public:
    class EffectDataList : public BSSimpleList<MagicEffectEntry*>
    {
      public:
        virtual ~EffectDataList();
        void ApplyParamToEntry(ActiveEffect* effect);
    };
    class NamedEffectsList : public BSSimpleList<EffectSetting*>
    {
    public:
        virtual ~NamedEffectsList();
    };
    TESForm* pForm;
    EffectDataList xEffectData;
    NamedEffectsList m_kNamedEffectsList;
    StatsMenu__StatusEffect(SpellItem* spell);
    ~StatsMenu__StatusEffect();
};
class StatusEffectListOps : public StatsMenu__StatusEffectList
{
public:
    void StatsMenu_StatusEffectList_Flush();
    void AddEffectToGroup(ActiveEffect*);
};
struct StatusEffectListBox : public ListBox_StatsMenu__StatusEffect___
{
    Tile* AddItem(StatsMenu__StatusEffect* item, int a, int b, int c);
    int GetNumItems();
    void Synchronize();
};

struct StatsMenuActiveEffects : public StatsMenu
{
    void StatsMenu_UpdateActiveEffects();
};

struct AVH
{
    static const char* __cdecl GetActorValueName(ActorValue::Index);
    static ActorValue::Index __cdecl GetActorValueForSectionIndex(int, unsigned char);
    static unsigned int __cdecl GetCountForSection(int);
};
struct TutorialState
{
    bool ShowMessage(int, int, unsigned int);
};
struct LBH
{
    void Initialize(Tile*, const char*);
    Tile* AddListEntry(int, int, int, int);
    Tile* ListBox_enum_MiscStatManager_MiscStatID_AddItem(int, int, int, int);
};
struct MenuH : StatsMenu
{
    bool HasAllSlots();
    void UpdateXboxButtonState();
};

struct Calendar
{
    unsigned int GetDaysPassed();
};

struct StatusH
{
    void ForwardCall_007db250(Tile*);
    void SetFieldBits(int, int);
};
// The stats-label normalization helper at 0x007b52a0 is absent from BSStringT.h.
void __cdecl NormalizeStatsLabel();

int __cdecl MiscStatManager_GetVal(int);

void* __cdecl InterfaceManager_GetSingleton();
int __cdecl StatsMenu_GetClassStatic();
void __cdecl _FNV_Warning(const char*, ...);
const char* __cdecl GetGameSettingString(int);
void __cdecl CompareActorValueNames();
StatusH* __stdcall StatsMenu_BodyPartController_GetInstance(int);
void __cdecl StatsMenu_UpdatePerks();
void __cdecl UpdateStatsMenuLevelText();
bool __cdecl IsActorValueBelowPermanent(int*);
bool __cdecl IsHealingOptionAvailable(int*);
bool __cdecl IsPlayerSubObjectValueAboveThreshold(int*);
int __cdecl GetTileValueID(const char*, int);
Menu* __cdecl FindMenuById(int);
extern double _DAT_010704f0;
extern double _DAT_010704e8;
extern const char DAT_01019f08[];
extern const char _DAT_0106ed20[];
extern Setting g_011d0c60;
extern const StartMenu g_011d1f08;
extern const StartMenu g_011d1f5c;
extern const StartMenu g_011d246c;
extern const StartMenu g_011d2994;
extern const StartMenu g_011d2e80;
extern const StartMenu g_011d2ebc;
extern const StartMenu g_011d2f88;
extern const StartMenu g_011d30c0;
extern const StartMenu g_011d37c8;
extern const StartMenu g_011d3b08;
extern const StartMenu g_011d3bd4;
extern const StartMenu g_011d3e74;
extern const StartMenu g_011d3fdc;
extern const StartMenu g_011d41bc;
extern const StartMenu g_011d44a4;
extern const StartMenu g_011d472c;
extern const StartMenu g_011d47ec;
extern const StartMenu g_011d48d0;
extern const StartMenu g_011d4bd0;
extern const StartMenu g_011d4ef4;
extern const StartMenu g_011d50b0;

// @fnv 0x007da2c0
// src: XBOX_PDB 0x007da2c0
Tile* StatsMenu_Create()
{
    Menu* pold_menu_tile = FindMenuById(StatsMenu_GetClassStatic());
    if (pold_menu_tile)
        delete pold_menu_tile;
    InterfaceManager* pin = (InterfaceManager*)InterfaceManager_GetSingleton();
    float ftop_depth = Tile::GetInterfaceScale();
    Tile* ptile = ((Tile*)((IMH*)pin)->CombatController_GetCombatState())->ReadFile("Data\\Menus\\Main\\stats_menu.xml");
    StatsMenu::ms_pInventoryMenu = (StatsMenu*)((Tile*)ptile)->GetMenu();
    MenuH::ReadMenuDefinition("Data\\Menus\\Main\\stats_menu.xml", StatsMenu::ms_pInventoryMenu);
    ((MenuH*)StatsMenu::ms_pInventoryMenu)->Menu_SetRenderedMenu();
    if (StatsMenu::ms_pInventoryMenu && StatsMenu::ms_pInventoryMenu->GetClass() == StatsMenu_GetClassStatic())
    {
        ((MenuH*)StatsMenu::ms_pInventoryMenu)->SetTileMenu((TileMenu*)ptile, false);
        if (!((MenuH*)StatsMenu::ms_pInventoryMenu)->HasAllSlots())
        {
            _FNV_Warning("MENUS: Stats Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (ptile->GetFloat(0xfa7) == _DAT_010704f0 || ptile->GetFloat(0xfa7) == _DAT_010704e8)
            ((Tile*)ptile)->Set(0xfad, ftop_depth, true);
        ((TutorialState*)((char*)InterfaceManager_GetSingleton() + 0x4d4))->ShowMessage(0x19, StatsMenu_GetClassStatic(), 0x200);
        UpdateStatsMenuLevelText();
        BGSRadiationStage* pstage = BGSRadiationStage::GetStageForLevel(3.402823466e+38F);
        ((Tile*)ptile)->Set(0x1006, pstage ? ((Calendar*)pstage)->GetDaysPassed() : 1000);
        BSStringT<char> strtmp;
        const char* pformat = "%d/%d";
        strtmp.PrintfString(pformat, g_thePlayer->GetActorValue((ActorValue::Index)0x10),
                       g_thePlayer->GetPermanentActorValue((ActorValue::Index)0x10));
        ptile->Set(0x1009, (const char*)strtmp, true);
        strtmp.PrintfString(pformat, g_thePlayer->GetActorValue((ActorValue::Index)0xc),
                       g_thePlayer->GetPermanentActorValue((ActorValue::Index)0xc));
        ptile->Set(0x100a, (const char*)strtmp, true);
        if (((Actor*)g_thePlayer)->GetLevel() >= *g_011d0c60.Int())
        {
            strtmp.PrintfString(DAT_01019f08, g_011d472c.GetMenuTitle());
        }
        else
        {
            strtmp.PrintfString(pformat, g_thePlayer->GetActorValue((ActorValue::Index)0x18),
                           ActorValueUtility_statsmenu::ConvertActorValue(((Actor*)g_thePlayer)->GetLevel() + 1));
        }
        ptile->Set(0x100b, (const char*)strtmp, true);
        ptile->Set(0x100c, ((Actor*)g_thePlayer)->GetLevel());
        strtmp = "stats_list_template";
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kPrimaryActorValueList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[6], (const char*)strtmp);
        for (int i = 0; i < AVH::GetCountForSection(0); i++)
        {
            ActorValue::Index eindex = AVH::GetActorValueForSectionIndex(0, (unsigned char)i);
            if (!P09AV::GetFlag(eindex, 0x2000) && eindex != 0x1f)
            {
                Tile* ptmp =
                    ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kPrimaryActorValueList)->AddListEntry(eindex, 0, 0, 0);
                ptmp->Set(0xfc4, AVH::GetActorValueName(eindex), true);
                ((Tile*)ptmp)->SetName(AVH::GetActorValueName(eindex));
            }
        }
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kSecondaryActorValueList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[7], (const char*)strtmp);
        for (int i = 0; i < AVH::GetCountForSection(2); i++)
        {
            ActorValue::Index eindex = AVH::GetActorValueForSectionIndex(2, (unsigned char)i);
            if (!P09AV::GetFlag(eindex, 0x2000) && eindex != 0x1f)
            {
                Tile* ptmp =
                    ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kSecondaryActorValueList)->AddListEntry(eindex, 0, 0, 0);
                ptmp->Set(0xfc4, AVH::GetActorValueName(eindex), true);
                ((Tile*)ptmp)->SetName(AVH::GetActorValueName(eindex));
            }
        }
        ((void (__thiscall*)(ListBoxBase*, void*))(*(void***)&StatsMenu::ms_pInventoryMenu->m_kSecondaryActorValueList)[8])(&StatsMenu::ms_pInventoryMenu->m_kSecondaryActorValueList, (void*)CompareActorValueNames);
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kPerkRankList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[34], (const char*)strtmp);
        StatsMenu_UpdatePerks();
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kReputationList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[46], (const char*)strtmp);
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kMiscStatList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[8], (const char*)strtmp);
        for (MiscStatManager__MiscStatID eMiscStat = MiscStatManager__MiscStatID_MS_QUESTS_COMPLETED;
             eMiscStat < MiscStatManager__MiscStatID_MS_COUNT;
             TESReputation::GetUnsignedIntegerPointer((unsigned int*)&eMiscStat))
        {
            Tile* ptile = ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kMiscStatList)->ListBox_enum_MiscStatManager_MiscStatID_AddItem(eMiscStat, 0, 0, 0);
            const char* ptext = GetGameSettingString(eMiscStat);
            ptile->Set(0xfc4, ptext, true);
            ptile->Set(0x1005, MiscStatManager_GetVal(eMiscStat));
            ((Tile*)ptile)->SetName(ptext);
        }
        StatsMenu::ms_pInventoryMenu->m_pTiles[47]->Set(0xfcc, "Interface\\shared\\solid_black.dds", true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[47]->Set(0xfa3, 0);
        TESForm* pform = BGSDefaultObjectManager::GetDefaultObjectByIndex(0);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[0].m_pHealingItem = dynamic_cast<AlchemyItem*>(pform);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[0].pTile = StatsMenu::ms_pInventoryMenu->m_pTiles[10];
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[0].pTile->Set(
            0x1004, ((TESFullName*)dynamic_cast<TESFullName*>(pform))->GetFullName(), true);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[0].m_pfnIsAvailable =
            (bool___cdecl__StatsMenu__HealingOption__*)IsActorValueBelowPermanent;
        pform = BGSDefaultObjectManager::GetDefaultObjectByIndex(0x15);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[3].m_pHealingItem = dynamic_cast<AlchemyItem*>(pform);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[3].pTile = StatsMenu::ms_pInventoryMenu->m_pTiles[59];
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[3].pTile->Set(
            0x1004, ((TESFullName*)dynamic_cast<TESFullName*>(pform))->GetFullName(), true);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[3].m_pfnIsAvailable =
            (bool___cdecl__StatsMenu__HealingOption__*)IsHealingOptionAvailable;
        pform = BGSDefaultObjectManager::GetDefaultObjectByIndex(2);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[1].m_pHealingItem = dynamic_cast<AlchemyItem*>(pform);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[1].pTile = StatsMenu::ms_pInventoryMenu->m_pTiles[31];
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[1].pTile->Set(
            0x1004, ((TESFullName*)dynamic_cast<TESFullName*>(pform))->GetFullName(), true);
        pform = BGSDefaultObjectManager::GetDefaultObjectByIndex(3);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[2].m_pHealingItem = dynamic_cast<AlchemyItem*>(pform);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[2].pTile = StatsMenu::ms_pInventoryMenu->m_pTiles[11];
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[2].pTile->Set(
            0x1004, ((TESFullName*)dynamic_cast<TESFullName*>(pform))->GetFullName(), true);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[2].m_pfnIsAvailable =
            (bool___cdecl__StatsMenu__HealingOption__*)IsPlayerSubObjectValueAboveThreshold;
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kStatusEffectList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[33], "stats_effects_template");
        StatsMenu_BodyPartController_GetInstance(0)->ForwardCall_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[12]);
        StatsMenu_BodyPartController_GetInstance(0)->ForwardCall_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[13]);
        StatsMenu_BodyPartController_GetInstance(0)->ForwardCall_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[24]);
        StatsMenu_BodyPartController_GetInstance(1)->ForwardCall_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[18]);
        StatsMenu_BodyPartController_GetInstance(1)->ForwardCall_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[19]);
        StatsMenu_BodyPartController_GetInstance(2)->ForwardCall_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[14]);
        StatsMenu_BodyPartController_GetInstance(2)->ForwardCall_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[15]);
        StatsMenu_BodyPartController_GetInstance(3)->ForwardCall_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[16]);
        StatsMenu_BodyPartController_GetInstance(3)->ForwardCall_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[17]);
        StatsMenu_BodyPartController_GetInstance(4)->ForwardCall_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[22]);
        StatsMenu_BodyPartController_GetInstance(4)->ForwardCall_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[23]);
        StatsMenu_BodyPartController_GetInstance(5)->ForwardCall_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[20]);
        StatsMenu_BodyPartController_GetInstance(5)->ForwardCall_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[21]);
        StatsMenu_BodyPartController_GetInstance(0)->SetFieldBits(1, 2);
        StatsMenu_BodyPartController_GetInstance(0)->SetFieldBits(2, 1);
        StatsMenu_BodyPartController_GetInstance(0)->SetFieldBits(3, 3);
        StatsMenu_BodyPartController_GetInstance(2)->SetFieldBits(0, 0);
        StatsMenu_BodyPartController_GetInstance(2)->SetFieldBits(1, 4);
        StatsMenu_BodyPartController_GetInstance(2)->SetFieldBits(2, 1);
        StatsMenu_BodyPartController_GetInstance(2)->SetFieldBits(3, 3);
        StatsMenu_BodyPartController_GetInstance(1)->SetFieldBits(0, 0);
        StatsMenu_BodyPartController_GetInstance(1)->SetFieldBits(1, 4);
        StatsMenu_BodyPartController_GetInstance(1)->SetFieldBits(3, 2);
        StatsMenu_BodyPartController_GetInstance(3)->SetFieldBits(0, 0);
        StatsMenu_BodyPartController_GetInstance(3)->SetFieldBits(1, 5);
        StatsMenu_BodyPartController_GetInstance(3)->SetFieldBits(2, 2);
        StatsMenu_BodyPartController_GetInstance(4)->SetFieldBits(0, 2);
        StatsMenu_BodyPartController_GetInstance(4)->SetFieldBits(3, 5);
        StatsMenu_BodyPartController_GetInstance(5)->SetFieldBits(0, 2);
        StatsMenu_BodyPartController_GetInstance(5)->SetFieldBits(2, 4);
        StatsMenu::ms_pInventoryMenu->UpdateActorValueTiles();
        ((MenuH*)StatsMenu::ms_pInventoryMenu)->UpdateXboxButtonState();
        strtmp = g_011d30c0.GetMenuTitle();
        ((void (__thiscall*)(BSStringT<char>*))NormalizeStatsLabel)(&strtmp);
        ptile->Set(GetTileValueID("_rads", -1), (const char*)strtmp, true);
        strtmp = g_011d1f08.GetMenuTitle();
        ((void (__thiscall*)(BSStringT<char>*))NormalizeStatsLabel)(&strtmp);
        ptile->Set(GetTileValueID("_h20", -1), (const char*)strtmp, true);
        strtmp = g_011d37c8.GetMenuTitle();
        ((void (__thiscall*)(BSStringT<char>*))NormalizeStatsLabel)(&strtmp);
        ptile->Set(GetTileValueID("_hunger", -1), (const char*)strtmp, true);
        strtmp = g_011d246c.GetMenuTitle();
        ((void (__thiscall*)(BSStringT<char>*))NormalizeStatsLabel)(&strtmp);
        ptile->Set(GetTileValueID("_sleep", -1), (const char*)strtmp, true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[39]->Set(0xfc4, g_011d3fdc.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[40]->Set(GetTileValueID(_DAT_0106ed20, -1), g_011d1f5c.GetMenuTitle(),
                                                        true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[41]->Set(GetTileValueID(_DAT_0106ed20, -1), g_011d50b0.GetMenuTitle(),
                                                        true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[42]->Set(GetTileValueID(_DAT_0106ed20, -1), g_011d44a4.GetMenuTitle(),
                                                        true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[43]->Set(GetTileValueID(_DAT_0106ed20, -1), g_011d3bd4.GetMenuTitle(),
                                                        true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[28]->Set(0xfc4, g_011d48d0.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[29]->Set(0xfc4, g_011d3e74.GetMenuTitle(), true);
        ptile->Set(0x100d, g_011d2e80.GetMenuTitle(), true);
        ptile->Set(0x100e, g_011d41bc.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[44]->Set(0xfc4, g_011d47ec.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[45]->Set(0xfc4, g_011d2ebc.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[0]->Set(0xfc4, g_011d2f88.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[1]->Set(0xfc4, g_011d2994.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[2]->Set(0xfc4, g_011d3b08.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[3]->Set(0xfc4, g_011d4bd0.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[4]->Set(0xfc4, g_011d4ef4.GetMenuTitle(), true);
        ((MenuH*)StatsMenu::ms_pInventoryMenu)->SetMenuVisibility(true);
        return ptile;
    }
    else
    {
        if (StatsMenu::ms_pInventoryMenu && ((MenuH*)StatsMenu::ms_pInventoryMenu)->FUN_00726070())
            delete StatsMenu::ms_pInventoryMenu;
    }
    return 0;
}

namespace fnv_00404820 {
void* __cdecl memcpy(void*, const void*, unsigned int);
}

// Appends text, growing the buffer when the combined length exceeds MaxLength.
// @fnv 0x00404820
template <> BSStringT<char>& BSStringT<char>::operator+=(const char* text)
{
    unsigned int uiTotalLen;
    unsigned int uiSrcLen;
    if (text)
    {
        if ((const char*)*this)
        {
            uiSrcLen = text ? BSStringLength(text) : 0;
            uiTotalLen = Length() + uiSrcLen;
            if (uiTotalLen > MaxLength())
                Set((const char*)*this, uiTotalLen);
            fnv_00404820::memcpy(pString + Length(), text, uiSrcLen + 1);
            SetLength(uiTotalLen);
        }
        else
        {
            Set(text, 0);
        }
    }
    return *this;
}

namespace fnv_007dd090 {

struct StatsMenuImpl : public StatsMenu
{
    void UpdateStatEntry(int aeWhich);
};

struct StatsMenuHelper : StatsMenu
{
    Tile* FUN_00726070();
    void UpdatePipboyNeedle();
    void StatsMenu_UpdateActiveEffects();
    void UpdateOption(int mode);
    int StatsMenu_GetFaceFileNumber();
};
unsigned int __cdecl TESActorBaseData_GetAlignmentForKarma(float);
int __cdecl MinInt(int, int);
int __cdecl GetTileValueID(const char* name, int index);
extern Setting originalRuntimeFloatSetting1017;
extern Setting g_011d0c60;
extern Setting g_011d472c;
extern Setting g_011d31d4;
extern Setting g_011d3204;
extern Setting g_011d41b0;
extern Setting g_011d457c;
extern Setting g_011d4ffc;
extern const char* DAT_011a0a80[];

// Updates the stats menu tile for the given actor value: formats value text, sets image/bar tiles, and handles special cases like level, resistances, and karma.
// @fnv 0x007dd090
void StatsMenuImpl::UpdateStatEntry(int aeWhich)
{
    int eimage = 60;
    int ebar = 60;
    BSStringT<char> strtmp;
    const char* pformat = "%d/%d";

    switch (aeWhich)
    {
    case 16:
        strtmp.PrintfString("Interface\\Stats\\face_%02d.dds", ((StatsMenuHelper*)this)->StatsMenu_GetFaceFileNumber());
        m_pTiles[24]->Set(0xfcc, strtmp.String(), true);
        strtmp.PrintfString(pformat, g_thePlayer->GetActorValue((ActorValue::Index)16),
                       g_thePlayer->GetPermanentActorValue((ActorValue::Index)16));
        ((StatsMenuHelper*)this)->FUN_00726070()->Set(GetTraitForValue((ActorValue::Index)16), strtmp.String(), true);
        ((StatsMenuHelper*)this)->UpdateOption(0);
        break;
    case 12:
        strtmp.PrintfString(pformat, g_thePlayer->GetActorValue((ActorValue::Index)12),
                       g_thePlayer->GetPermanentActorValue((ActorValue::Index)12));
        ((StatsMenuHelper*)this)->FUN_00726070()->Set(GetTraitForValue((ActorValue::Index)12), strtmp.String(), true);
        break;
    case 24:
        if (((Actor*)g_thePlayer)->GetLevel() >= *g_011d0c60.Int())
            strtmp.PrintfString("%s", g_011d472c.String());
        else
            strtmp.PrintfString(pformat, g_thePlayer->GetActorValue((ActorValue::Index)24),
                           ActorValueUtility_statsmenu::ConvertActorValue(((Actor*)g_thePlayer)->GetLevel() + 1));
        ((StatsMenuHelper*)this)->FUN_00726070()->Set(GetTraitForValue((ActorValue::Index)24), strtmp.String(), true);
        break;
    case 54:
        ((StatsMenuHelper*)this)->UpdatePipboyNeedle();
        ((StatsMenuHelper*)this)->UpdateOption(2);
        ((StatsMenuHelper*)this)->StatsMenu_UpdateActiveEffects();
        break;
    case 20: {
        int iresist = MinInt((int)*originalRuntimeFloatSetting1017.Float(),
                             g_thePlayer->GetActorValueAsInteger((ActorValue::Index)20));
        strtmp.PrintfString("%d%%", iresist);
        m_pTiles[38]->Set(0xfc4, strtmp.String(), true);
        ((StatsMenuHelper*)this)->StatsMenu_UpdateActiveEffects();
        break;
    }
    case 25:
        eimage = 12;
        ebar = 13;
    case 26:
        if (eimage == 60)
        {
            eimage = 14;
            ebar = 15;
        }
    case 27:
        if (eimage == 60)
        {
            eimage = 16;
            ebar = 17;
        }
    case 28:
        if (eimage == 60)
        {
            eimage = 18;
            ebar = 19;
        }
    case 29:
        if (eimage == 60)
        {
            eimage = 20;
            ebar = 21;
        }
    case 30:
        if (eimage == 60)
        {
            eimage = 22;
            ebar = 23;
        }
        {
            float fval = g_thePlayer->GetCurrentActorValue((ActorValue::Index)aeWhich) / 100.0;
            strtmp.PrintfString(fval > 0.0 ? "Interface\\Stats\\%s.dds" : "Interface\\Stats\\%s_broken.dds",
                           DAT_011a0a80[aeWhich]);
            m_pTiles[eimage]->Set(0xfcc, strtmp.String(), true);
            ((Tile*)m_pTiles[ebar])->Set(GetTileValueID("_Value", -1), fval, true);
            if (m_bUpdateOption)
                ((StatsMenuHelper*)this)->UpdateOption(0);
            break;
        }
    case 23:
        switch (TESActorBaseData_GetAlignmentForKarma(g_thePlayer->GetCurrentActorValue((ActorValue::Index)23)))
        {
        case 1:
            m_pTiles[36]->Set(0xfcc, "Interface\\Icons\\PipboyImages\\Karma icons\\karma_neutral.dds", true);
            m_pTiles[35]->Set(0xfc4, g_011d3204.String(), true);
            break;
        case 0:
            m_pTiles[36]->Set(0xfcc, "Interface\\Icons\\PipboyImages\\Karma icons\\karma_good.dds", true);
            m_pTiles[35]->Set(0xfc4, g_011d41b0.String(), true);
            break;
        case 2:
            m_pTiles[36]->Set(0xfcc, "Interface\\Icons\\PipboyImages\\Karma icons\\karma_bad.dds", true);
            m_pTiles[35]->Set(0xfc4, g_011d457c.String(), true);
            break;
        case 3:
            m_pTiles[36]->Set(0xfcc, "Interface\\Icons\\PipboyImages\\Karma icons\\karma_saintly.dds", true);
            m_pTiles[35]->Set(0xfc4, g_011d4ffc.String(), true);
            break;
        case 4:
            m_pTiles[36]->Set(0xfcc, "Interface\\Icons\\PipboyImages\\Karma icons\\karma_evil.dds", true);
            m_pTiles[35]->Set(0xfc4, g_011d31d4.String(), true);
            break;
        }
        StatsMenu::UpdateStatusEffects();
        break;
    default:
        StatsMenu::UpdatePrimaryActorValueTile(((ListBox_enum_MiscStatManager__MiscStatID_*)&m_kPrimaryActorValueList)
                                                   ->GetTileForData(*(MiscStatManager__MiscStatID*)&aeWhich),
                                               (ActorValue::Index)aeWhich);
        StatsMenu::UpdateSecondaryActorValueTile(
            ((ListBox_enum_MiscStatManager__MiscStatID_*)&m_kSecondaryActorValueList)
                ->GetTileForData(*(MiscStatManager__MiscStatID*)&aeWhich),
            (ActorValue::Index)aeWhich);
        break;
    }
}
}  // namespace fnv_007dd090

namespace fnv_007df4e0 {

struct MenuActiveS
{
    const char* GetMenuTitle();
};

struct GlobalObject_0040c150
{
    int x;
};
extern GlobalObject_0040c150 g_011d2028;

// @fnv 0x007df4e0
void UpdateStatsMenuLevelText()
{
    if (StatsMenu::ms_pInventoryMenu && g_thePlayer)
    {
        BSStringT<char> strtmp;
        strtmp.PrintfString("%s - %s %hd", ((Actor*)g_thePlayer)->GetFullName(),
                       ((MenuActiveS*)&g_011d2028)->GetMenuTitle(), ((Actor*)g_thePlayer)->GetLevel());
        StatsMenu::ms_pInventoryMenu->m_pTiles[27]->Set(0xfc4, (const char*)strtmp, true);
        ((Menu*)StatsMenu::ms_pInventoryMenu)->FUN_00726070()->Set(0x100c, ((Actor*)g_thePlayer)->GetLevel());
    }
}
}  // namespace fnv_007df4e0

struct ConditionMenuMethods : public StatsMenu
{
    int StatsMenu_GetFaceFileNumber();
};

struct NodeHelper
{
    NodeHelper* FUN_00726070();
    ActiveEffect** FUN_006815c0();
};

extern const double DAT_01020998;

// @fnv 0x007dfe40
// src: XBOX_PDB 0x007dfe40
int ConditionMenuMethods::StatsMenu_GetFaceFileNumber()
{
    NodeHelper* node;
    float fdmg;
    float fmax;
    int iLevel;
    for (node = reinterpret_cast<NodeHelper*>(reinterpret_cast<MagicTarget*>((char*)g_thePlayer + 0x94)->GetActiveEffectList()); node && *node->FUN_006815c0();
         node = node->FUN_00726070())
    {
        if (((int (__thiscall*)(ActiveEffect*))GetActiveEffectSpellType)(*node->FUN_006815c0()) == 10 && ((ActiveEffect*)*node->FUN_006815c0())->ActiveEffect_IsActive())
            return 10;
    }
    fmax = (float)((ActorValueOwner*)((char*)g_thePlayer + 0xa4))->GetPermanentActorValue((ActorValue::Index)0x10);
    fdmg = fmax - ((ActorValueOwner*)((char*)g_thePlayer + 0xa4))->GetCurrentActorValue((ActorValue::Index)0x10);
    iLevel = (int)(fdmg / fmax * 5.0);
    if (iLevel < 0)
        iLevel = 0;
    if (iLevel > 4)
        iLevel = 4;
    return iLevel;
}

// Unit-local declarations for the copy operation and setters absent from EffectItem.h.
struct StatsMenuEffectItemMethods : EffectItem
{
    void SetRange_00404560(unsigned int range);
    void SetMagnitude_004043d0(int magnitude);
    void SetArea_00404470(int area);
    void SetDuration_00404510(int duration);
    void SetOwner(int actorValue);
    void EffectItem_SetConditions(PerkEntryConditionSet* conditions);
    void CopyFrom(EffectItem* apSource);
};

// @fnv 0x00404210
void StatsMenuEffectItemMethods::CopyFrom(EffectItem* apSource)
{
    m_pEffectSetting = apSource->m_pEffectSetting;
    SetRange_00404560(apSource->GetRange());
    SetMagnitude_004043d0(apSource->GetMagnitude());
    SetArea_00404470(apSource->GetArea());
    SetDuration_00404510(apSource->GetDuration());
    SetOwner(apSource->GetAffectedActorValue());
    EffectItem_SetConditions(apSource->GetConditions());
    m_fCost = -1.0f;
}

struct BodyPartDisplay
{
    int m_currentBodyPart;
    void SetBodyPart(int aeBodyPart, bool abFlash);
    void StatsMenu_BodyPartController_SetFlash(int arg);
};

// @fnv 0x007dbfa0
void BodyPartDisplay::SetBodyPart(int aeBodyPart, bool abFlash)
{
    if (abFlash)
    {
        StatsMenu_BodyPartController_SetFlash(0);
    }
    m_currentBodyPart = aeBodyPart;
    if (abFlash)
    {
        StatsMenu_BodyPartController_SetFlash(1);
    }
}

namespace fnv_007dcb40 {
// The shared header does not yet declare this reputation icon accessor.
const char* __cdecl GetReputationIcon();

struct ReputationEntryMenuMethods : public StatsMenu
{
    void SetReputationEntry(TESReputation* pRep);
};

// @fnv 0x007dcb40
void ReputationEntryMenuMethods::SetReputationEntry(TESReputation* pRep)
{
    if (!pRep)
        return;
    m_pTiles[47]->Set(0xfcc, pRep->GetReputationName(), true);
    m_pTiles[47]->Set(0xfa3, 1);
    m_pTiles[48]->Set(0xfa3, 1);
    m_pTiles[51]->Set(0xfa3, 1);
    m_pTiles[51]->Set(0xfc4, ((TESFullName*)((char*)pRep + 0x18))->GetFullName(), true);
    m_pTiles[48]->Set(0xfc4, ((const char* (__thiscall*)(TESReputation*))GetReputationIcon)(pRep), true);
}
}  // namespace fnv_007dcb40

struct PipboyInterface
{
    FOPipboyManager* GetPipboyManager();
};

void* __cdecl InterfaceManager_GetSingleton(void);

// If a stats menu exists, gets the pipboy manager and plays sounds for the menu's current page.
// @fnv 0x007dfc90
void PlayPipboyPageSound(bool abPlaySounds)
{
    if (StatsMenu::ms_pInventoryMenu)
        reinterpret_cast<PipboyInterface*>(InterfaceManager_GetSingleton())
            ->GetPipboyManager()
            ->SetValue(StatsMenu::ms_pInventoryMenu->GetCurrentPage(), abPlaySounds);
}

namespace fnv_007dff40 {
struct PageMenuMethods : public StatsMenu
{
    void SetPage(int);
};

void* __cdecl InterfaceManager_GetSingleton();
// Exe 0x007dff40: unit-local Interface view; declarations and layout are preserved.
class StatsmenuInterfaceView
{
  public:
    FOPipboyManager* GetPipboyManager();
};
// List-box queries: 0x00726710 is also bound in listbox.cpp; 0x007d86c0 serves startmenu.cpp save lists.
struct PerkListQueries
{
    unsigned int GetUnfilteredRaceCount();
    void* ListBox_BGSSaveLoadFileEntry_GetDataAt(int, int);
};
struct StatsPageUpdateMethods : StatsMenu
{
    void UpdateStatsDisplay(int);
    void UpdateScrollBar(void*);
    void RefreshHealingOptions();
};
void __cdecl PlayPipboyPageSound(int);
extern Setting g_011db37c;
extern Setting g_011db458;

// Validates aePage (0-4), updates the Pipboy menu, sets menu value 0x1004 to aePage, and applies page-specific actions.
// @fnv 0x007dff40
void PageMenuMethods::SetPage(int aePage)
{
    if (aePage < 0 || aePage > 4)
        return;
    ((StatsmenuInterfaceView*)InterfaceManager_GetSingleton())->GetPipboyManager()->StartBurst(*g_011db458.Float(), *g_011db37c.Float(), 0.5f);
    pMenu->Set(0x1004, aePage);
    if (((StatsmenuInterfaceView*)InterfaceManager_GetSingleton())->GetPipboyManager()->GetInitialized())
        PlayPipboyPageSound(1);
    if (m_bUpdateOption)
        ((StatsPageUpdateMethods*)this)->RefreshHealingOptions();
    if (aePage == 1)
        ((StatsPageUpdateMethods*)this)->UpdateStatsDisplay(5);
    else if (aePage == 2)
        ((StatsPageUpdateMethods*)this)->UpdateStatsDisplay(0x20);
    else if (aePage == 3 && ((PerkListQueries*)&m_kPerkRankList)->GetUnfilteredRaceCount())
        ((StatsPageUpdateMethods*)this)->UpdateScrollBar(((PerkListQueries*)&m_kPerkRankList)->ListBox_BGSSaveLoadFileEntry_GetDataAt(0, 0));
    else
        m_pTiles[25]->Set(0xfa3, 0);
}
}  // namespace fnv_007dff40

struct LimbTileMenuMethods : public StatsMenu
{
    bool GetTileIndex(int aiTileID, int* apIndex);
};

// Maps a tile ID (0x1c,0x1d,0x1e,0x35,0x37,0x39) to an index written to apIndex and returns true, otherwise returns false.
// @fnv 0x007e0160
bool LimbTileMenuMethods::GetTileIndex(int aiTileID, int* apIndex)
{
    switch (aiTileID)
    {
    case 0x1c:
        *apIndex = 0;
        return true;
    case 0x1d:
        *apIndex = 1;
        return true;
    case 0x1e:
        *apIndex = 2;
        return true;
    case 0x35:
        *apIndex = 3;
        return true;
    case 0x37:
        *apIndex = 4;
        return true;
    case 0x39:
        *apIndex = 5;
        return true;
    }
    return false;
}

namespace fnv_007e0510 {

int __cdecl _stricmp(const char*, const char*);

// Compares the full names of the TESFullName objects referenced at offset 4 of a and b using _stricmp and returns the result.
// @fnv 0x007e0510
int __cdecl CompareEntryNames(void* pEntryA, void* pEntryB)
{
    return _stricmp(((TESFullName*)((char*)*(void**)((char*)pEntryA + 4) + 0x18))->GetFullName(),
                    ((TESFullName*)((char*)*(void**)((char*)pEntryB + 4) + 0x18))->GetFullName());
}
}  // namespace fnv_007e0510

// Compares the effect names of two effects case-insensitively via _stricmp and returns the result.
// @fnv 0x007e0540
int __cdecl CompareEffectNames(EffectSetting* apEffectA, EffectSetting* apEffectB)
{
    return fnv_007e0510::_stricmp(apEffectA->GetEffectName(), apEffectB->GetEffectName());
}

bool __fastcall PlayerCharacter_IsHardcore(PlayerCharacter* pPlayer);
int __cdecl GetStatusResult();
// @fnv 0x007e06f0
bool __cdecl IsHealingOptionAvailable(StatsMenu__HealingOption* apOption)
{
    bool bResult = PlayerCharacter_IsHardcore(g_thePlayer);
    if (apOption->m_pStatusEffect)
    {
        int iIndex = GetStatusResult();
        if (!bResult && iIndex != -1)
            return false;
        for (int i = 0x19; i < 0x1f; i++)
        {
            if (g_thePlayer->GetActorValue((ActorValue::Index)i) <
                g_thePlayer->GetPermanentActorValue((ActorValue::Index)i))
                return true;
        }
    }
    return false;
}

namespace fnv_007e0850 {
void __fastcall _ref_0063f7b0(void*);
void** __fastcall _ref_006815c0(void*);
bool __fastcall _ref_008256d0(void*);
void __cdecl _Deallocate(void*);

// @fnv 0x007e0850
// src: XBOX_PDB 0x007e0850
void __fastcall StatsMenu_StatusDataList_Flush(void* thisPtr)
{
    void* p;
    while (!_ref_008256d0((char*)thisPtr + 4))
    {
        p = *(_ref_006815c0((char*)thisPtr + 4));
        _Deallocate(p);
        _ref_0063f7b0((char*)thisPtr + 4);
    }
}
}  // namespace fnv_007e0850

struct FUN_007e0c50_item
{
    TESForm* pForm;
};
struct FUN_007e0c50_node
{
    FUN_007e0c50_node* FUN_00726070();
    FUN_007e0c50_item*& FUN_006815c0();
};
struct GroupedEffectLookupMethods : StatsMenu__StatusEffectList
{
    FUN_007e0c50_item* StatsMenu_StatusEffectList_Find(unsigned int);
};

// Walks the list nodes and returns the first item whose form's GetFormID matches formID, or null if none matches.
// @fnv 0x007e0c50
// src: XBOX_PDB 0x007e0c50
FUN_007e0c50_item* GroupedEffectLookupMethods::StatsMenu_StatusEffectList_Find(unsigned int formID)
{
    FUN_007e0c50_node* pNode;
    FUN_007e0c50_item* pEffect = 0;
    for (pNode = this ? reinterpret_cast<FUN_007e0c50_node*>(&bSSimpleList_StatsMenu__StatusEffect___Component) : 0; !pEffect && pNode && pNode->FUN_006815c0(); pNode = pNode->FUN_00726070())
    {
        if (pNode->FUN_006815c0()->pForm->GetFormID() == formID)
            pEffect = pNode->FUN_006815c0();
    }
    return pEffect;
}

namespace fnv_007e0d60 {
struct MenuH : StatsMenu
{
    void UpdateXboxButtonState();
    void StatsMenu_DoControllerSwitch(bool);
};

// @fnv 0x007e0d60
// src: XBOX_PDB 0x007e0d60
void MenuH::StatsMenu_DoControllerSwitch(bool abHas360Controller)
{
    MenuH::UpdateXboxButtonState();
}
}  // namespace fnv_007e0d60

// Maps an index 0-5 to a fixed code value (0x19-0x1e) via a switch, returning -1 for any other index.
// @fnv 0x007df9c0
int MapIndexToCode(int aiIndex)
{
    switch (aiIndex)
    {
    case 0:
        return 0x19;
    case 1:
        return 0x1c;
    case 2:
        return 0x1a;
    case 3:
        return 0x1b;
    case 4:
        return 0x1e;
    case 5:
        return 0x1d;
    default:
        return -1;
    }
}

// Returns the current page of the stats menu, or 0 when the menu is not open.
// @fnv 0x007dfcd0
char GetStatsMenuPage()
{
    int page;
    if (StatsMenu::ms_pInventoryMenu)
        page = StatsMenu::ms_pInventoryMenu->GetCurrentPage();
    else
        page = 0;
    return (char)page;
}

struct List_009e03e0
{
    void RemoveAll();
};

struct NamedEffectClearMethods : StatsMenu__NamedEffectsList
{
    void StatsMenu_NamedEffectsList_Flush();
};

// @fnv 0x007e09b0
// src: XBOX_PDB 0x007e09b0
void NamedEffectClearMethods::StatsMenu_NamedEffectsList_Flush()
{
    ((List_009e03e0*)&bSSimpleList_EffectSetting___Component)->RemoveAll();
}

void _Deallocate(void*);

struct FUN_0071f9c0_class
{
    void FUN_0071f9f0();
    void* FUN_0071f9c0(unsigned int flags);
};

// Calls FUN_0071f9f0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0071f9c0
void* FUN_0071f9c0_class::FUN_0071f9c0(unsigned int flags)
{
    FUN_0071f9f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct G2
{
    int d[2];
    void AddHead(int*&);
};
struct S
{
    int pad;
    G2 arr[1];
    void ForwardCall_007db250(int idx, int* val);
};
// Calls AddHead on the element of arr at idx, passing val.
// @fnv 0x007db250
// src: GUESS 0x007db250 (confidence: low)
void S::ForwardCall_007db250(int aiIndex, int* apValue)
{
    arr[aiIndex].AddHead(apValue);
}

namespace fnv_007dbfe0 {
bool __cdecl FUN_007dc040(Tile*, unsigned int);
struct Elem8
{
    int x0;
    int x1;
    void __thiscall BSSimpleList_Tile_Traverse(bool(__cdecl*)(Tile*, unsigned int), unsigned int);
};
struct BodyPartDisplay
{
    int mIndex;
    Elem8 mElems[1];
    void StatsMenu_BodyPartController_SetFlash(unsigned int);
};
// Calls FUN_007e0e30 on the element at mIndex, passing the FUN_007dc040 callback and aiOn.
// @fnv 0x007dbfe0
// src: XBOX_PDB 0x007dbfe0
void BodyPartDisplay::StatsMenu_BodyPartController_SetFlash(unsigned int aiOn)
{
    mElems[mIndex].BSSimpleList_Tile_Traverse(&FUN_007dc040, aiOn);
}
}  // namespace fnv_007dbfe0

struct S_007dc010
{
    unsigned char _pad[52];
    unsigned int arr[1];
    unsigned int GetByte(unsigned int, unsigned int);
};
// Returns byte b of the 32-bit value stored at arr[a] by masking and shifting.
// @fnv 0x007dc010
unsigned int S_007dc010::GetByte(unsigned int auiIndex, unsigned int auiByteIndex)
{
    return (arr[auiIndex] & (0xFF << (auiByteIndex * 8))) >> (auiByteIndex * 8);
}

struct MiscStatMenuMethods : StatsMenu
{
    void TraverseListBox();
};
// @fnv 0x007ddaa0
void MiscStatMenuMethods::TraverseListBox()
{
    int unused1;
    int unused2;
    int FlushUsageData;
    ((ListBox_enum_ActorValue__Index_*)&m_kMiscStatList)->Traverse((void(__cdecl*)(Tile*, ActorValue::Index))StatsMenu::UpdateMiscStatTile, 0, 0x7fffffff);
}

namespace fnv_007e0b20 {
// local form of MagicEffectEntry: 0x007e0b20 needs the out-of-line 0x00403ba0 ctor; shared POD replacement changes bytes.
struct FUN_00403ba0
{
    int m_iMagnitude;
    int m_iArea;
    int m_iPayloadInteger;
    int m_eRange;
    int m_eAssociatedActorValue;
    FUN_00403ba0();
};
struct G2
{
    void AddHead(int*);
};
struct FUN_007e0b20_shell
{
    int pad00;
    G2 kList;  // +0x4
    FUN_00403ba0* FindEntryByFormID(int aiActorValue);
    void AddEffectItem(EffectItem* apEffect);
};

// @fnv 0x007e0b20
void FUN_007e0b20_shell::AddEffectItem(EffectItem* apEffect)
{
    if (apEffect)
    {
        FUN_00403ba0* pEntry = FindEntryByFormID(apEffect->GetAffectedActorValue());
        if (pEntry)
        {
            pEntry->m_iMagnitude += apEffect->GetMagnitude();
        }
        else
        {
            pEntry = new FUN_00403ba0;
            pEntry->m_eAssociatedActorValue = apEffect->GetAffectedActorValue();
            pEntry->m_iMagnitude = apEffect->GetMagnitude();
            if (reinterpret_cast<EffectSetting*>(apEffect->GetEffectSetting())->IsFlagSet_00403e60(4))
                pEntry->m_iMagnitude *= -1;
            if (!reinterpret_cast<EffectSetting*>(apEffect->GetEffectSetting())->IsFlagSet_00403e60(2))
                pEntry->m_iPayloadInteger = apEffect->GetDuration();
            kList.AddHead(reinterpret_cast<int*>(&pEntry));
        }
    }
}
}  // namespace fnv_007e0b20

struct ListX
{
    unsigned char* m_pHead;
    unsigned char* m_pTail;
    unsigned int m_uiCount;
    ~ListX();
};
struct FUN_00406de0 : ListX
{
    virtual ~FUN_00406de0();
    void StatsMenu_StatusDataList_Flush();
};
// @fnv 0x00406de0
FUN_00406de0::~FUN_00406de0()
{
    StatsMenu_StatusDataList_Flush();
}

struct FUN_007db270_t
{
    void SetFieldBits(unsigned int a, unsigned int c, unsigned int b);
};

// @fnv 0x007db270
void FUN_007db270_t::SetFieldBits(unsigned int auiIndex, unsigned int auiByteOffset, unsigned int auiValue)
{
    *(unsigned int*)((char*)this + 0x34 + auiIndex * 4) &= ~(0xff << (auiByteOffset << 3));
    *(unsigned int*)((char*)this + 0x34 + auiIndex * 4) |= auiValue << (auiByteOffset << 3);
}

bool __cdecl IsActorValueBelowPermanent(int*);
bool __cdecl IsHealingOptionAvailable(int*);

// @fnv 0x007e0230
void StatsMenu::RefreshHealingOptions()
{
    m_bUpdateOption = !m_bUpdateOption;
    (*(Tile**)((char*)this + 0x2c))->Set(0xfaf, IsActorValueBelowPermanent((int*)((char*)this + 0x28)));
    (*(Tile**)((char*)this + 0x5c))->Set(0xfaf, IsHealingOptionAvailable((int*)((char*)this + 0x58)));
    ((MenuH*)this)->UpdateXboxButtonState();
}

namespace fnv_007dcc80 {

struct MiscStatMenuMethods : StatsMenu
{
    void TraverseListBox();
};

struct ReputationMenuMethods
{
    void UpdateReputationList();
};

struct HealingMenuMethods
{
    void UpdateOption(int value);
};

struct LimbStatusMenuMethods
{
    void ShowWorstLimbStatus();
};

int __cdecl BSstrcmp(char const*, char const*);
int __cdecl Tile_TextToTrait(char const*);

extern char const* const ENGLISH;
extern const char _DAT_0106ed20[];
extern const char str_0107732c[];
extern const char str_01077340[];
extern const char str_01077358[];
extern const char str_01077368[];
extern const char str_01077378[];
extern const char str_01077388[];
extern const char str_01077398[];

extern const StartMenu g_011c3cb4;
extern const StartMenu g_011d1f08;
extern const StartMenu g_011d1f5c;
extern const StartMenu g_011d246c;
extern const StartMenu g_011d2994;
extern const StartMenu g_011d2e80;
extern const StartMenu g_011d2ebc;
extern const StartMenu g_011d2f88;
extern const StartMenu g_011d37c8;
extern const StartMenu g_011d3b08;
extern const StartMenu g_011d3bd4;
extern const StartMenu g_011d3e74;
extern const StartMenu g_011d3fdc;
extern const StartMenu g_011d41bc;
extern const StartMenu g_011d44a4;
extern const StartMenu g_011d47ec;
extern const StartMenu g_011d48d0;
extern const StartMenu g_011d4bd0;
extern const StartMenu g_011d4ef4;
extern const StartMenu g_011d50b0;

struct StatsMenuInitializationMethods : public StatsMenu
{
    void InitializeStatsMenu();
};

// Calls the base menu setup routines, then if the language is English, assigns localized text to the menu's tiles by index and by name.
// @fnv 0x007dcc80
void StatsMenuInitializationMethods::InitializeStatsMenu()
{
    this->UpdateActorValueTiles();
    reinterpret_cast<MiscStatMenuMethods*>(this)->TraverseListBox();
    reinterpret_cast<ReputationMenuMethods*>(this)->UpdateReputationList();
    reinterpret_cast<HealingMenuMethods*>(this)->UpdateOption(4);
    reinterpret_cast<LimbStatusMenuMethods*>(this)->ShowWorstLimbStatus();

    if (BSstrcmp(g_011c3cb4.GetMenuTitle(), reinterpret_cast<char const*>(&ENGLISH)))
    {
        this->m_pTiles[0]->Set(0xfc4, g_011d2f88.GetMenuTitle(), true);
        this->m_pTiles[1]->Set(0xfc4, g_011d2994.GetMenuTitle(), true);
        this->m_pTiles[2]->Set(0xfc4, g_011d3b08.GetMenuTitle(), true);
        this->m_pTiles[3]->Set(0xfc4, g_011d4bd0.GetMenuTitle(), true);
        this->m_pTiles[4]->Set(0xfc4, g_011d4ef4.GetMenuTitle(), true);
        this->m_pTiles[28]->Set(0xfc4, g_011d48d0.GetMenuTitle(), true);
        this->m_pTiles[29]->Set(0xfc4, g_011d3e74.GetMenuTitle(), true);
        this->m_pTiles[53]->Set(0xfc4, g_011d1f08.GetMenuTitle(), true);
        this->m_pTiles[57]->Set(0xfc4, g_011d246c.GetMenuTitle(), true);
        this->m_pTiles[55]->Set(0xfc4, g_011d37c8.GetMenuTitle(), true);

        reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext())
            ->Set(0x100d, g_011d2e80.GetMenuTitle(), true);

        reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext())
            ->Set(0x100e, g_011d41bc.GetMenuTitle(), true);

        reinterpret_cast<Tile*>(reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext()))
            ->GetNamedChild(str_01077398)
            ->Set(0xfc4, g_011d3fdc.GetMenuTitle(), true);

        reinterpret_cast<Tile*>(reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext()))
            ->GetNamedChild(str_01077388)
            ->Set(Tile_TextToTrait(_DAT_0106ed20), g_011d1f5c.GetMenuTitle(), true);

        reinterpret_cast<Tile*>(reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext()))
            ->GetNamedChild(str_01077378)
            ->Set(Tile_TextToTrait(_DAT_0106ed20), g_011d50b0.GetMenuTitle(), true);

        reinterpret_cast<Tile*>(reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext()))
            ->GetNamedChild(str_01077368)
            ->Set(Tile_TextToTrait(_DAT_0106ed20), g_011d44a4.GetMenuTitle(), true);

        reinterpret_cast<Tile*>(reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext()))
            ->GetNamedChild(str_01077358)
            ->Set(Tile_TextToTrait(_DAT_0106ed20), g_011d3bd4.GetMenuTitle(), true);

        reinterpret_cast<Tile*>(reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext()))
            ->GetNamedChild(str_01077340)
            ->Set(0xfc4, g_011d47ec.GetMenuTitle(), true);

        reinterpret_cast<Tile*>(reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext()))
            ->GetNamedChild(str_0107732c)
            ->Set(0xfc4, g_011d2ebc.GetMenuTitle(), true);
    }
}
}  // namespace fnv_007dcc80

namespace fnv_007e06b0 {

typedef GO StatusH;

bool __cdecl IsStatsMenuActive();
StatusH* __stdcall StatsMenu_BodyPartController_GetInstance();
int __cdecl MapIndexToCode(int);

// @fnv 0x007e06b0
int __cdecl GetStatusResult()
{
    int result;

    if (IsStatsMenuActive())
        result = MapIndexToCode(static_cast<unsigned int>(*StatsMenu_BodyPartController_GetInstance()));
    else
        result = -1;

    return result;
}
}  // namespace fnv_007e06b0

namespace fnv_007e02b0 {
extern int __cdecl GetTileValueID(char const*, int);
extern char const $SG2844[];

extern const StartMenu g_011d4ef4;
extern const StartMenu g_011d4144;

struct GeneralStatsMenuMethods : StatsMenu
{
    void StatsMenu_ToggleGenRepMode();
};

// @fnv 0x007e02b0
// src: XBOX_PDB 0x007e02b0
void GeneralStatsMenuMethods::StatsMenu_ToggleGenRepMode()
{
    static int DAT_011dad88 = GetTileValueID($SG2844, -1);
    static int DAT_011dad84 = GetTileValueID("_user0", -1);
    static bool DAT_011a0ae0 = false;

    DAT_011a0ae0 = !DAT_011a0ae0;

    StatsMenu::ms_pInventoryMenu->m_pTiles[46]->Set(DAT_011dad88, DAT_011a0ae0);
    StatsMenu::ms_pInventoryMenu->m_pTiles[46]->Set(0xFA3, DAT_011a0ae0);
    StatsMenu::ms_pInventoryMenu->m_pTiles[8]->Set(DAT_011dad88, !DAT_011a0ae0);
    StatsMenu::ms_pInventoryMenu->m_pTiles[8]->Set(0xFA3, !DAT_011a0ae0);

    if (DAT_011a0ae0)
    {
        StatsMenu::ms_pInventoryMenu->m_pTiles[49]->Set(0xFC4, g_011d4ef4.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[50]->Set(0x1004, 1);
    }
    else
    {
        StatsMenu::ms_pInventoryMenu->m_pTiles[49]->Set(0xFC4, g_011d4144.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[50]->Set(0x1004, 0);
    }
}
}  // namespace fnv_007e02b0

struct FUN_007d35c0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};
struct SM7d6
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    Tile* t48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    FUN_007d35c0_Obj e4;
    void StartMenu_SetFlag(int, bool);
};
struct GameSettingCollection_stub
{
    const char* String();
};
extern GameSettingCollection_stub g_011d4930;
extern SM7d6* DAT_011daac0;
// If DAT_011daac0 is set, calls its e4.v7, sets tile 0xfc4 text from g_011d4930.String(), and calls FUN_0075f6f0(0x4000, true).
// @fnv 0x007d35c0
// src: COMMUNITY 0x007d35c0
void __cdecl StartMenu_ConfirmSaveGame()
{
    if (DAT_011daac0)
    {
        DAT_011daac0->e4.v7();
        DAT_011daac0->t48->Set(0xfc4, g_011d4930.String(), true);
        DAT_011daac0->StartMenu_SetFlag(0x4000, true);
    }
}

struct StatsMenuSlotMethods : StatsMenu
{
    bool HasAllSlots();
};

// Returns true only if all 60 entries of m_slots are non-null, otherwise false.
// @fnv 0x007db340
bool StatsMenuSlotMethods::HasAllSlots()
{
    for (int i = 0; i < 60; i++)
    {
        if (m_pTiles[i] == 0)
        {
            return false;
        }
    }
    return true;
}

struct FUN_007db630_Entry
{
    int unk00;
    int unk04;
    bool BSSimpleList_TESLevSpell_IsInList(int* value);
};
struct FUN_007db630_Owner
{
    int unk00;
    FUN_007db630_Entry entries[6];
    int FindEntryIndex(int value);
};
void __cdecl FUN_007dc0a0(int* value);
// Scans up to 6 entries, returning the index of the first whose FUN_005f65d0 accepts value, otherwise 6.
// @fnv 0x007db630
int FUN_007db630_Owner::FindEntryIndex(int value)
{
    int index = 0;
    for (; index < 6; FUN_007dc0a0(&index))
    {
        if (entries[index].BSSimpleList_TESLevSpell_IsInList(&value))
            return index;
    }
    return 6;
}

extern const char UNK_01074eb8;
extern const char UNK_0106f8f8;
extern const char UNK_010702d8;
extern const char UNK_01070250;
extern double DAT_01012070;

int __cdecl Tile_TextToTrait(const char* name);
int __cdecl ActorValue_GetActorValueIcon(void* value);
int __cdecl GetActorValueDescription(void* value);
unsigned int __cdecl GetWeaponSkillIconPath(void* value);
float __cdecl BSMAX_00404010(float low, float high);
float __cdecl FUN_004e4430(float value);

struct ChildList007dc7e0
{
    Tile** NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead();
    Tile** FUN_007b5370();
};

struct ActorValueDisplayMenuMethods : StatsMenu
{
    void UpdateStatsDisplay(void* actor);
};
// @fnv 0x007dc7e0
void ActorValueDisplayMenuMethods::UpdateStatsDisplay(void* actor)
{
    Tile* pMain = *(reinterpret_cast<Tile**>(
        reinterpret_cast<ChildList007dc7e0*>((char*)m_pTiles[26] + 4)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead()));
    Tile* second = *(reinterpret_cast<Tile**>(
        reinterpret_cast<ChildList007dc7e0*>((char*)m_pTiles[26] + 4)->FUN_007b5370()));
    float fMinimumInputValue = second->FUN_00a011b0(Tile_TextToTrait(&UNK_01074eb8));
    float diff = 0.0f;
    reinterpret_cast<Tile*>(m_pTiles[25])->FUN_00700320(0xfa3, 1);
    reinterpret_cast<Tile*>(m_pTiles[25])->Tile_Set_00a01350(0xfcc, ActorValue_GetActorValueIcon(actor), true);
    pMain->Tile_Set_00a01350(0xfc4, GetActorValueDescription(actor), true);
    unsigned int amount = GetWeaponSkillIconPath(actor);
    if (amount > 0)
    {
        reinterpret_cast<Tile*>(m_pTiles[52])->FUN_00700320(0xfa3, 1);
        reinterpret_cast<Tile*>(m_pTiles[52])->Tile_Set_00a01350(0xfcc, amount, true);
    }
    else
    {
        reinterpret_cast<Tile*>(m_pTiles[52])->FUN_00700320(0xfa3, 0);
    }
    pMain->Tile_UpdateTile(0);
    diff = pMain->FUN_00a011b0(0xfb0) - pMain->FUN_0045cd60()->FUN_00a011b0(0xfb0);
    diff = BSMAX_00404010(0.0f, diff);
    second->Tile_Set(Tile_TextToTrait(&UNK_0106f8f8), FUN_004e4430(diff / fMinimumInputValue) + DAT_01012070, true);
    second->Tile_Set(Tile_TextToTrait(&UNK_010702d8), 0.0f, false);
    second->SetTraitFloat(Tile_TextToTrait(&UNK_01070250), 1.0f);
}

struct LimbModifierMenuMethods : StatsMenu
{
    Tile* FUN_00726070(unsigned int);
    void StatsMenu_UpdateH20Level();
};

extern void* g_011dea3c;
extern double g_01017b70, g_01011590, g_0101ff40, g_01064f50, g_01012060, g_01012070;
float __cdecl FUN_005c5420();
float __cdecl BSMAX_00404010(float, float);
float __cdecl FUN_004bd510(float, float);
// @fnv 0x007ddc20
// src: XBOX_PDB 0x007ddc20
void LimbModifierMenuMethods::StatsMenu_UpdateH20Level()
{
    float a = FUN_00726070(0x1008)->FUN_00a011b0() * g_01017b70;
    float c = (-a / g_01011590) + FUN_005c5420() * a;
    float d = BSMAX_00404010(0.0f, ((ActorValueOwner*)((char*)g_011dea3c + 0xa4))->GetCurrentActorValue((ActorValue::Index)0x49));
    float e = g_01064f50 - (d + c) / g_01017b70 * g_0101ff40;
    if (d > g_01012060 && d < g_01012070)
        d = 1.0f;
    else
        d = FUN_004bd510(d, 1.0f);
    pMenu->Tile_Set(0x100f, d, true);
}

namespace fnv_007ddd10 {

extern ActorValueOwner* g_011dea3c;
extern double g_01017b70, g_01011590, g_0101ff40, g_01064f50, g_01012060, g_01012070;
extern double __cdecl FUN_005c5420();
extern float __cdecl BSMAX_00404010(float, float);
extern float __cdecl FUN_004bd510(float, float);
struct SecondaryModifierMenuMethods : StatsMenu
{
    Tile* FUN_00726070(int);
    void StatsMenu_UpdateFODLevel();
};
// @fnv 0x007ddd10
// src: XBOX_PDB 0x007ddd10
void SecondaryModifierMenuMethods::StatsMenu_UpdateFODLevel()
{
    float scale;

    float adjustment;
    float currentValue;
    float unusedResult;
    scale = FUN_00726070(0x1008)->FUN_00a011b0() * g_01017b70;
    adjustment = (-scale / g_01011590) + (FUN_005c5420() * scale);
    currentValue =
        BSMAX_00404010(0.0f, (reinterpret_cast<ActorValueOwner*>(reinterpret_cast<char*>(g_011dea3c) + 0xa4))->GetCurrentActorValue((ActorValue::Index)0x4a));
    unusedResult = g_01064f50 - (currentValue + adjustment) / g_01017b70 * g_0101ff40;
    if (currentValue > g_01012060 && currentValue < g_01012070)
        currentValue = 1.0f;
    else
        currentValue = FUN_004bd510(currentValue, 1.0f);
    pMenu->Tile_Set(0x1010, currentValue, true);
}
}  // namespace fnv_007ddd10

extern const double gModifierZero;

float __cdecl FUN_005c5420();
float __cdecl BSMAX_00404010(float fA, float fB);
float __cdecl FUN_004bd510(float fA, float fB);

struct ModifierMenuMethods : StatsMenu
{
    void UpdateModifierTile();
};

// @fnv 0x007dde00
void ModifierMenuMethods::UpdateModifierTile()
{
    float fRange5 = GetTile()->GetFloat(0x1008) * 1000.0;
    float fOffset5 = -fRange5 / 2.0 + FUN_005c5420() * fRange5;
    float fValue = BSMAX_00404010(0.0f, reinterpret_cast<PlayerCharacter*>(g_thePlayer)->GetCurrentActorValue((ActorValue::Index)0x4b));
    float fAngle2 = 1.5707963267948966 - (fValue + fOffset5) / 1000.0 * 3.1415927410125732;
    if (fValue > gModifierZero && fValue < 1.0)
        fValue = 1.0f;
    else
        fValue = FUN_004bd510(fValue, 1.0f);
    pMenu->Set(0x1011, fValue, true);
}

// Show the status for the player's most damaged limb.

enum DF920Limb
{
    DF920_LIMB_HEAD = 0,
    DF920_LIMB_COUNT = 6
};

DF920Limb& __cdecl operator++(DF920Limb& reLimb);
int __cdecl DF920LimbToActorValue(int m_iLimbIndex);

extern PlayerCharacter* g_pkDF920Player;

class DF920Status
{
  public:
    void Show();
};
DF920Status* __stdcall DF920GetLimbStatus(int m_iLimbIndex, int iMode);

struct LimbStatusMenuMethods : StatsMenu
{
    void ShowWorstLimbStatus();
};

// Finds the limb with the lowest actor value and shows its status for the current mode.
// @fnv 0x007df920
void LimbStatusMenuMethods::ShowWorstLimbStatus()
{
    int iWorstLimb = DF920_LIMB_COUNT;
    float fMinValue = 3.402823466e+38f;
    for (DF920Limb m_iActionValue = DF920_LIMB_HEAD; m_iActionValue < DF920_LIMB_COUNT; ++m_iActionValue)
    {
        float fValue = g_pkDF920Player->GetCurrentActorValue((ActorValue::Index)DF920LimbToActorValue(m_iActionValue));
        if (fValue < fMinValue)
        {
            fMinValue = fValue;
            iWorstLimb = m_iActionValue;
        }
    }
    DF920GetLimbStatus(iWorstLimb, m_bHealingMode)->Show();
}

struct GlobA_007dfd20
{
    float* Get(int);
};
struct GlobB_007dfd20
{
    float* Get();
};
extern GlobA_007dfd20 DAT_011db358;
extern GlobB_007dfd20 DAT_011db2f0;

// The shared Pipboy header does not expose these knob update entry points yet.
void __cdecl UpdatePipboyScrollKnobTarget();
void __cdecl SetPipboyGaugeTarget();
struct PipboyControlInterface
{
    FOPipboyManager* FUN_00704370();
};

PipboyControlInterface* __stdcall InterfaceManager_GetSingleton(int, float, float);

struct ScrollKnobMenuMethods : StatsMenu
{
    void StatsMenu_MoveKnob(Tile*, unsigned int*);
};

// @fnv 0x007dfd20
// src: XBOX_PDB 0x007dfd20
void ScrollKnobMenuMethods::StatsMenu_MoveKnob(Tile* apObj, unsigned int* apOut)
{
    unsigned int v = (unsigned int)apObj->FUN_00a011b0(0xfac);
    if (*apOut < v)
    {
        ((void (__thiscall*)(FOPipboyManager*))UpdatePipboyScrollKnobTarget)(
            InterfaceManager_GetSingleton(0, *DAT_011db2f0.Get(), *DAT_011db358.Get(1))->FUN_00704370());
    }
    else if (*apOut > v)
    {
        ((void (__thiscall*)(FOPipboyManager*))UpdatePipboyScrollKnobTarget)(
            InterfaceManager_GetSingleton(0, -*DAT_011db2f0.Get(), *DAT_011db358.Get(1))->FUN_00704370());
    }
    *apOut = v;
}

extern char DAT_01183028[];
extern char DAT_01183158[];
TESFullName* __cdecl FUN_00ec43fb(int a, int b, const char* c, const char* d, int e);
void __cdecl BSstricmp(void* a, void* b);

// Resolves the objects referenced by *pA and *pB via FUN_00ec43fb and passes their FUN_00408da0 results to FUN_00404dc0.
// @fnv 0x007e0480
// src: XBOX_PDB 0x007e0480
void __cdecl StatsMenu_StatusEffectSortFn(int* pA, int* pB)
{
    BSstricmp(FUN_00ec43fb(*pA, 0, DAT_01183028, DAT_01183158, 0)->GetFullName(),
                 FUN_00ec43fb(*pB, 0, DAT_01183028, DAT_01183158, 0)->GetFullName());
}

struct Holder
{
    TESForm* item;
};
struct Entry
{
    unsigned int unk00;
    Holder* holder;
};
int __cdecl BSstricmp(const char*, const char*);
// Compares the text strings of the items referenced by two entries via FUN_00404dc0 and returns its result.
// @fnv 0x007e04e0
int __cdecl CompareEntryText(const Entry* pLeftEntry, const Entry* pRightEntry)
{
    return BSstricmp(reinterpret_cast<TESFullName*>((char*)pLeftEntry->holder->item + sizeof(TESForm))->GetFullName(), reinterpret_cast<TESFullName*>((char*)pRightEntry->holder->item + sizeof(TESForm))->GetFullName());
}

extern const double DAT_01012060;

// Returns true when apArg[2] is nonzero and the player's sub-object at offset 0xa4 returns a value above DAT_01012060 for 0x36.
// @fnv 0x007e07a0
bool __cdecl IsPlayerSubObjectValueAboveThreshold(int* apArg)
{
    int iResult;
    if (apArg[2] != 0 && ((ActorValueOwner*)((char*)g_thePlayer + 0xa4))->GetCurrentActorValue((ActorValue::Index)0x36) > DAT_01012060)
    {
        iResult = 1;
    }
    else
    {
        iResult = 0;
    }
    return *(bool*)&iResult;
}

struct S_007e0a20_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_007e0a20_Entry();
};

struct S_007e0a20_Owner
{
    int unk00;
    BSSimpleList<S_007e0a20_Entry*> m_kNode;
    S_007e0a20_Entry* FindEntryByFormID(int);
    void ApplyParamToEntry(ActiveEffect* apParam);
};

// Looks up an entry by the param's object id; adds the param's float to its unk00, or creates a new entry with that id and value and adds it to the list.
// @fnv 0x007e0a20
void S_007e0a20_Owner::ApplyParamToEntry(ActiveEffect* apParam)
{
    if (apParam)
    {
        S_007e0a20_Entry* pEntry = FindEntryByFormID(apParam->GetHavokWorldObjectCountInSceneGraph_0084e3a0()->GetAffectedActorValue());
        if (pEntry)
        {
            pEntry->unk00 += (int)apParam->GetFloatAtOffset1C();
        }
        else
        {
            pEntry = new S_007e0a20_Entry;
            pEntry->unk10 = apParam->GetHavokWorldObjectCountInSceneGraph_0084e3a0()->GetAffectedActorValue();
            pEntry->unk00 = (int)apParam->GetFloatAtOffset1C();
            m_kNode.AddHead(pEntry);
        }
    }
}

struct ItemListNode;

struct ItemListEntry
{
    unsigned char unk00[0x10];
    int formID;
};

struct ItemListNode
{
    ItemListNode* Next();
    ItemListEntry** Data();
};

class ItemListOwner
{
  public:
    void** m_ppVirtualMethodTable;
    ItemListNode xList;
    ItemListEntry* FindEntryByFormID(int formID);
};

// Walks the linked list and returns the first entry whose formID matches the given formID, or null if none is found.
// @fnv 0x007e0ce0
ItemListEntry* ItemListOwner::FindEntryByFormID(int formID)
{
    ItemListEntry* found = 0;
    ItemListNode* cur = this != 0 ? &xList : 0;
    for (; found == 0 && cur != 0 && *cur->Data() != 0; cur = cur->Next())
    {
        if ((*cur->Data())->formID == formID)
        {
            found = *cur->Data();
        }
    }
    return found;
}

struct FUN_007db2c0
{
    FUN_007db2c0();
    int unk;
    int unkCur;
    int unkValue;
    int unk0C;
    int uNewnk;
    int uTmpnk;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
};

extern FUN_007db2c0* DAT_011dace4;

// Returns the global FUN_007db2c0 instance, allocating it with new if it does not exist yet.
// @fnv 0x007db1c0
// src: XBOX_PDB 0x007db1c0
FUN_007db2c0* StatsMenu_BodyPartController_GetInstance()
{
    if (!DAT_011dace4)
        DAT_011dace4 = new FUN_007db2c0();
    return DAT_011dace4;
}

struct ClickNode
{
    AlchemyItem*& FUN_006815c0();
    ClickNode* FUN_00726070();
};

struct ClickStatus
{
    int FindEntryIndex();
};

struct ClickMenu : StatsMenu
{
    void StatsMenu_DoClick(int id, Tile* tile);
    bool SetIndexFromType(int, int*);
    bool GetTileIndex(int, int*);
    void SetPage(int);
    void StatsMenu_SetStatusPage(int);
    void FUN_007e0230();
    void StatsMenu_ToggleGenRepMode();
    void UpdateStatEntry(int);
    void UpdateOption(int);
    void StatsMenu_UpdateActiveEffects();
};
// @fnv 0x007db380
// src: XBOX_PDB 0x007db380
void ClickMenu::StatsMenu_DoClick(int id, Tile* tile)
{
    if (!tile && id >= 0 && id < 60)
        tile = m_pTiles[id];
    if (InterfaceManager_Has360Controller() && !((Tile*)tile)->IsTraitNonZero(4015))
        return;
    int skill;
    if (SetIndexFromType(id, &skill))
    {
        SetPage(skill);
        return;
    }
    int special;
    if (GetTileIndex(id, &special))
    {
        StatsMenu_SetStatusPage(special);
        return;
    }
    if (id == 9 || (m_bUpdateOption && id == 5))
    {
        FUN_007e0230();
        return;
    }
    if (id == 49)
    {
        StatsMenu_ToggleGenRepMode();
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (tile == m_kHealingOptions[i].pTile && m_kHealingOptions[i].m_pStatusEffect)
        {
            ((Actor*)g_thePlayer)
                ->Actor_QueueEquipObject(m_kHealingOptions[i].m_pStatusEffect->FUN_0044ddc0(),
                               m_kHealingOptions[i].m_pStatusEffect->FUN_00726070(),
                               reinterpret_cast<ExtraDataList*>(m_kHealingOptions[i].m_pStatusEffect->Modelloader_GetReferencedThis()
                                   ? ((ClickNode*)m_kHealingOptions[i].m_pStatusEffect->Modelloader_GetReferencedThis())->FUN_006815c0()
                                   : 0),
                               false, false, true);
            TESBoundObject* object = m_kHealingOptions[i].m_pStatusEffect->FUN_0044ddc0();
            for (ClickNode* node = (ClickNode*)dynamic_cast<BSSimpleList<EffectItem*>*>(object);
                 node && node->FUN_006815c0(); node = node->FUN_00726070())
            {
                UpdateStatEntry(((EffectItem*)node->FUN_006815c0())->GetAffectedActorValue());
            }
            UpdateOption(i);
            m_bStatUpdatePending = false;
            StatsMenu_UpdateActiveEffects();
            i = 4;
        }
    }
    if (m_bUpdateOption && !InterfaceManager_Has360Controller())
    {
        int part = ((ClickStatus*)StatsMenu_BodyPartController_GetInstance((int)tile))->FindEntryIndex();
        if (part != 6)
            PlayerCharacter_IsHardcore(g_thePlayer) ? HandleSelection(59, 0) : HandleSelection(10, 0);
    }
}

// Menu input: on the accept key with the button enabled, trigger the default action and play the OK sound.

struct AcceptKeyMenuMethods : StatsMenu
{
    bool StatsMenu_DoGamepadUpEvent(int, int);
};

// @fnv 0x007dc0e0
// src: XBOX_PDB 0x007dc0e0
bool AcceptKeyMenuMethods::StatsMenu_DoGamepadUpEvent(int iKey, int iUnused)
{
    if (m_bUpdateOption && iKey == 10 && m_pTiles[9]->IsTraitNonZero(0xfaf))
    {
        HandleSelection(9, 0);
        static_cast<StatsMenuAudioMethods*>(BSAudio::GetSingleton())
            ->GetSoundHandleByEditorID("UIMenuOK", 0x121).Play(false);
        return true;
    }
    return false;
}

FORenderedMenu* __cdecl Interface_GetPipboy();
void* __cdecl InterfaceManager_GetSingleton();
bool __cdecl InterfaceManager_IsInPipboyMenu();
unsigned int __cdecl Cmd_GetSessionTime_Execute();
bool __cdecl Interface_IsTopMenuID(int);
bool __fastcall PlayerCharacter_IsHardcore(void*);
extern unsigned int DAT_011dad74;
extern void* DAT_011dea3c;
extern unsigned char DAT_011a0ae1;

extern StatsMenu* DAT_011dace0;

struct Host15 : StatsMenu
{
    void UpdatePipboyNeedle();
    void StatsMenu_UpdateH20Level();
    void StatsMenu_UpdateFODLevel();
    void UpdateModifierTile();
    Tile* FUN_00726070();
    void FUN_007e0230();
    int StatsMenu_GetStatusPage();
    void StatsMenu_SetStatusPage(int);
    void UpdateStatsMenu();
};

// @fnv 0x007dc4f0
void Host15::UpdateStatsMenu()
{
    m_bStatUpdatePending = 0;
    if (Interface_GetPipboy()->IsUnk28Set())
    {
        InterfaceManager_GetSingleton();
        if (InterfaceManager_IsInPipboyMenu())
        {
            if (Cmd_GetSessionTime_Execute() >= DAT_011dad74)
            {
                UpdatePipboyNeedle();
                if (DAT_011dea3c && PlayerCharacter_IsHardcore(DAT_011dea3c))
                {
                    StatsMenu_UpdateH20Level();
                    StatsMenu_UpdateFODLevel();
                    UpdateModifierTile();
                }
                DAT_011dad74 = (unsigned int)((double)Cmd_GetSessionTime_Execute() + FUN_00726070()->FUN_00a011b0(0x1007) * 1000.0);
            }
        }
        if (m_bUpdateOption)
        {
            if (!Interface_IsTopMenuID(0x3eb))
                FUN_007e0230();
        }
    }
    if (GetCurrentPage() == 0)
    {
        if (StatsMenu_GetStatusPage() > (PlayerCharacter_IsHardcore(DAT_011dea3c) ? 5 : 2))
            StatsMenu_SetStatusPage(0);
    }
    if (DAT_011dea3c && !PlayerCharacter_IsHardcore(DAT_011dea3c) && DAT_011a0ae1)
    {
        DAT_011dace0->m_pTiles[53]->Set(0xfaf, 0);
        DAT_011dace0->m_pTiles[53]->Set(0xfa3, 0);
        DAT_011dace0->m_pTiles[57]->Set(0xfaf, 0);
        DAT_011dace0->m_pTiles[57]->Set(0xfa3, 0);
        DAT_011dace0->m_pTiles[55]->Set(0xfaf, 0);
        DAT_011dace0->m_pTiles[55]->Set(0xfa3, 0);
        DAT_011a0ae1 = 0;
    }
    else if (DAT_011dea3c && PlayerCharacter_IsHardcore(DAT_011dea3c) && !DAT_011a0ae1)
    {
        DAT_011dace0->m_pTiles[53]->Set(0xfaf, 1);
        DAT_011dace0->m_pTiles[53]->Set(0xfa3, 1);
        DAT_011dace0->m_pTiles[57]->Set(0xfaf, 1);
        DAT_011dace0->m_pTiles[57]->Set(0xfa3, 1);
        DAT_011dace0->m_pTiles[55]->Set(0xfaf, 1);
        DAT_011dace0->m_pTiles[55]->Set(0xfa3, 1);
    }
    DAT_011a0ae1 = PlayerCharacter_IsHardcore(DAT_011dea3c);
}

namespace fnv_007dc9b0 {
struct ChildListSI
{
    Tile*& NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead();
    Tile*& FUN_007b5370();
};

int __cdecl Tile_TextToTrait(const char*);
float __cdecl BSMAX_00404010(float, float);
float __cdecl FUN_004e4430(float);

struct ScrollMenuMethods : public StatsMenu
{
    void UpdateScrollBar(BGSPerk** apEntry);
};

// @fnv 0x007dc9b0
void ScrollMenuMethods::UpdateScrollBar(BGSPerk** apEntry)
{
    Tile* pHeadTile = (Tile*)((ChildListSI*)((char*)m_pTiles[26] + 4))->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead();
    Tile* pTailTile = (Tile*)((ChildListSI*)((char*)m_pTiles[26] + 4))->FUN_007b5370();
    float fTailScrollDelta = pTailTile->FUN_00a011b0(Tile_TextToTrait("_ScrollDelta"));
    {
        float fPos = 0.0f;
        m_pTiles[25]->Set(0xfa3, 1);
        m_pTiles[25]->Set(0xfcc, reinterpret_cast<TESFullName*>((char*)*apEntry + offsetof(BGSPerk, TESIcon::FullNameComponent) - offsetof(TESIcon, FullNameComponent))->GetFullName(), true);
        pHeadTile->Set(0xfc4, reinterpret_cast<TESDescription*>((char*)*apEntry + offsetof(BGSPerk, TESDescription::m_uiDescriptionFileOffset) - offsetof(TESDescription, m_uiDescriptionFileOffset))->GetDescription(0, static_cast<CHUNK_ID>(0x43534544)), true);
        pHeadTile->Tile_UpdateTile(0);
        fPos = pHeadTile->FUN_00a011b0(0xfb0) - ((Tile*)pHeadTile->GetParent())->FUN_00a011b0(0xfb0);
        fPos = BSMAX_00404010(0.0f, fPos);
        pTailTile->Tile_Set(Tile_TextToTrait("_number_of_items"), (float)(FUN_004e4430(fPos / fTailScrollDelta) + 1.0),
                                true);
    }
    pTailTile->Tile_Set(Tile_TextToTrait("_current_value"), 0.0f, false);
    pTailTile->SetTraitFloat(Tile_TextToTrait("_SetInCode"), 1.0f);
}
}  // namespace fnv_007dc9b0

namespace fnv_007dd710 {
class FUN_007dd710_item
{
  public:
    BGSPerk* pForm;
    unsigned char count;
};

class FUN_007dd710_node
{
  public:
    FUN_007dd710_node* FUN_00726070();
    FUN_007dd710_item*& FUN_006815c0();
};

void __cdecl InsertPerkEntry();

int __cdecl CompareEntryText(const void* left, const void* right);

extern StatsMenu* DAT_011dace0;
extern PlayerCharacter* DAT_011dea3c;

// @fnv 0x007dd710
// src: COMMUNITY 0x007dd710
void __cdecl StatsMenu_UpdatePerks()
{
    if (DAT_011dace0 && DAT_011dace0->m_pTiles[34])
    {
        ((void (__thiscall*)(ListBoxBase*))(*(void***)&DAT_011dace0->m_kPerkRankList)[7])(&DAT_011dace0->m_kPerkRankList);
        for (FUN_007dd710_node* node = reinterpret_cast<FUN_007dd710_node*>(DAT_011dea3c->GetPerks(false)); node != 0 && node->FUN_006815c0() != 0;
             node = node->FUN_00726070())
        {
            if (!node->FUN_006815c0()->pForm->IsPerkHidden())
            {
                BSStringT<char> strEntry;
                if (node->FUN_006815c0()->count > 1)
                {
                    strEntry.PrintfString("%s (%d)", node->FUN_006815c0()->pForm->TESFullName::GetFullName(),
                                 (int)node->FUN_006815c0()->count);
                }
                else
                {
                    strEntry.PrintfString("%s", node->FUN_006815c0()->pForm->TESFullName::GetFullName());
                }
                ((void (__thiscall*)(ListBox_PerkRankData___*, FUN_007dd710_item*, const char*, int(__cdecl*)(const void*, const void*), int))InsertPerkEntry)(&DAT_011dace0->m_kPerkRankList, node->FUN_006815c0(), strEntry.String(), CompareEntryText, 0);
            }
        }
    }
}
}  // namespace fnv_007dd710

namespace fnv_007dd8c0 {
struct ReputationNode
{
    TESReputation*& Get();
    ReputationNode* Next();
};

extern TESDataHandler* DAT_011c3f2c;
extern StatsMenu* DAT_011dace0;
extern const double DAT_01012060;
void __cdecl CompareEntryNames(void* item);

struct ReputationMenuList : ListBox_TESReputation___
{
    void Insert(TESReputation* reputation, const char* label, void(__cdecl* callback)(void*), bool selected);
};

struct ReputationMenuUpdater : StatsMenu
{
    void UpdateReputationList();
};

// @fnv 0x007dd8c0
void ReputationMenuUpdater::UpdateReputationList()
{
    if (DAT_011dace0 && DAT_011dace0->m_pTiles[46])
    {
        m_pTiles[47]->Set(4003, 0);
        m_pTiles[51]->Set(4003, 0);
        m_pTiles[48]->Set(4003, 0);
        ((void (__thiscall*)(ListBoxBase*))(*(void***)&DAT_011dace0->m_kReputationList)[7])(&DAT_011dace0->m_kReputationList);
        for (ReputationNode* node = reinterpret_cast<ReputationNode*>(DAT_011c3f2c->GetTESReputationList()); node && node->Get(); node = node->Next())
        {
            TESReputation* reputation = node->Get();
            if (reputation &&
                (reputation->GetUnsignedIntegerPointer(ReputationType_REPUTATION_POSITIVE) > DAT_01012060 || reputation->GetUnsignedIntegerPointer(ReputationType_REPUTATION_NEGATIVE) > DAT_01012060))
            {
                BSStringT<char> label;
                label.PrintfString(DAT_01019f08, reputation->TESFullName::GetFullName());
                reinterpret_cast<ReputationMenuList*>(&DAT_011dace0->m_kReputationList)
                    ->Insert(reputation, label.String(), CompareEntryNames, false);
            }
        }
    }
}
}  // namespace fnv_007dd8c0

struct PipboyInterfaceStub
{
    FOPipboyManager* GetPipboyManager();
};
float __cdecl FUN_005c5420();
float __cdecl BSMAX_00404010(float a, float b);
float __cdecl FUN_004bd510(float a, float b);
extern float g_fPipboyNeedleSpeed;

struct NeedleMenuMethods : public Menu
{
    Tile* GetMenuTile();
    void UpdatePipboyNeedle();
};

// @fnv 0x007ddb00
void NeedleMenuMethods::UpdatePipboyNeedle()
{
    float fRange5 = GetMenuTile()->GetFloat(0x1008) * 1000.0;
    float fBase2 = -fRange5 / 2.0 + FUN_005c5420() * fRange5;
    float fValue = BSMAX_00404010(0.0f, g_thePlayer->GetCurrentActorValue((ActorValue::Index)0x36));
    float fAngleDifference = 1.5707963267948966 - (fValue + fBase2) / 1000.0 * 3.1415927f;
    if (fValue > 0.0 && fValue < 1.0)
        fValue = 1.0f;
    else
        fValue = FUN_004bd510(fValue, 1.0f);
    ((Tile*)pMenu)->Set(0x1005, fValue, true);
    ((void (__thiscall*)(FOPipboyManager*, int, float, float))SetPipboyGaugeTarget)(
        ((PipboyInterfaceStub*)InterfaceManager_GetSingleton())->GetPipboyManager(),
        1, fAngleDifference, g_fPipboyNeedleSpeed);
}

extern PlayerCharacter* g_healPlayer;
struct HealingMenuMethods : StatsMenu
{
    void Toggle();
    void UpdateOption(int);
};

// @fnv 0x007df230
void HealingMenuMethods::UpdateOption(int aiOptionIndex)
{
    if (!g_healPlayer)
        return;
    for (int indexB = 0; indexB < 4; indexB++)
    {
        if (aiOptionIndex == indexB || aiOptionIndex == 4)
        {
            BSStringT<char> text;
            delete m_kHealingOptions[indexB].m_pStatusEffect;
            m_kHealingOptions[indexB].m_pStatusEffect = g_healPlayer->FindEntryForObject(m_kHealingOptions[indexB].m_pHealingItem, 0);
            m_kHealingOptions[indexB].pTile->Set(0xfaf, ((bool (__cdecl*)(StatsMenu__HealingOption*))m_kHealingOptions[indexB].m_pfnIsAvailable)(&m_kHealingOptions[indexB]));
            if (m_kHealingOptions[indexB].m_pStatusEffect)
            {
                text.PrintfString("(%d) %s", m_kHealingOptions[indexB].m_pStatusEffect->FUN_00726070(),
                           m_kHealingOptions[indexB].pTile->GetString(0x1004));
                if ((indexB == 0 && !((bool (__thiscall*)(PlayerCharacter*))GetPlayerHardcoreMode)(g_healPlayer)) || indexB == 3)
                    m_pTiles[9]->Set(0xfaf, 1);
            }
            else
                text = m_kHealingOptions[indexB].pTile->GetString(0x1004);
            m_kHealingOptions[indexB].pTile->Set(0xfc4, (const char*)text, true);
        }
    }
    if (aiOptionIndex == 0 || aiOptionIndex == 3 || aiOptionIndex == 4)
    {
        int first2 = ((int (__thiscall*)(PlayerCharacter*, AlchemyItem*))CountPlayerItem)(g_healPlayer, m_kHealingOptions[0].m_pHealingItem);
        int last = ((int (__thiscall*)(PlayerCharacter*, AlchemyItem*))CountPlayerItem)(g_healPlayer, m_kHealingOptions[3].m_pHealingItem);
        bool enabled3 = true;
        if (((bool (__thiscall*)(PlayerCharacter*))GetPlayerHardcoreMode)(g_healPlayer) && last == 0)
            enabled3 = false;
        else if (!((bool (__thiscall*)(PlayerCharacter*))GetPlayerHardcoreMode)(g_healPlayer) && last == 0 && first2 == 0)
            enabled3 = false;
        if (!enabled3)
        {
            if (m_bUpdateOption)
                Toggle();
            m_pTiles[9]->Set(0xfaf, 0);
        }
    }
}

namespace fnv_007df620 {
int __cdecl Tile_AddUserTrait(const char* name, int index);
bool __cdecl InterfaceManager_Has360Controller();
BodyPartDisplay* __cdecl StatsMenu_BodyPartController_GetInstance();

struct GSString_00403df0
{
    const char* FUN_00403df0();
};
extern GSString_00403df0 DAT_011d4708;
extern GSString_00403df0 DAT_011d2658;

struct ControllerLabelMenuMethods : StatsMenu
{
    void UpdateXboxButtonState();
};

// @fnv 0x007df620
void ControllerLabelMenuMethods::UpdateXboxButtonState()
{
    static int iConsoleButtonTrait = Tile_AddUserTrait("_xbox_button", -1);
    static int iEnabledTrait = Tile_AddUserTrait("_enabled", -1);
    if (m_pTiles[9] && InterfaceManager_Has360Controller())
    {
        m_pTiles[9]->Set(iConsoleButtonTrait, !m_bUpdateOption + 10);
        m_pTiles[9]->Set(0xfc4, m_bUpdateOption ? DAT_011d4708.FUN_00403df0() : DAT_011d2658.FUN_00403df0(), true);
        m_pTiles[0]->Set(iEnabledTrait, !m_bUpdateOption);
        m_pTiles[1]->Set(iEnabledTrait, !m_bUpdateOption);
        m_pTiles[2]->Set(iEnabledTrait, !m_bUpdateOption);
        m_pTiles[3]->Set(iEnabledTrait, !m_bUpdateOption);
        m_pTiles[4]->Set(iEnabledTrait, !m_bUpdateOption);
        m_pTiles[28]->Set(iEnabledTrait, !m_bUpdateOption);
        m_pTiles[29]->Set(iEnabledTrait, !m_bUpdateOption);
        m_pTiles[53]->Set(iEnabledTrait, !m_bUpdateOption);
        m_pTiles[57]->Set(iEnabledTrait, !m_bUpdateOption);
        m_pTiles[55]->Set(iEnabledTrait, !m_bUpdateOption);
        m_pTiles[30]->Set(iEnabledTrait, !m_bUpdateOption);
    }
    StatsMenu_BodyPartController_GetInstance()->StatsMenu_BodyPartController_SetFlash(m_bUpdateOption);
}
}  // namespace fnv_007df620

namespace fnv_007e0060 {
// FUN_007e0060: /MT /Od /GS /EHsc, 114 bytes, __thiscall with one stack argument.
// Validates an index against a computed limit, then notifies the owner.

extern PlayerCharacter* g_011dea3c;

struct StatusPageMenuMethods : StatsMenu
{
    void FUN_007e0230();
    int StatsMenu_GetStatusPage();
    bool StatsMenu_SetStatusPage(int);
};

// @fnv 0x007e0060
// src: XBOX_PDB 0x007e0060
bool StatusPageMenuMethods::StatsMenu_SetStatusPage(int id)
{
    if (id >= 0 && id <= (PlayerCharacter_IsHardcore(g_011dea3c) ? 5 : 2) && StatsMenu_GetStatusPage() != id)
    {
        if (m_bUpdateOption)
        {
            FUN_007e0230();
        }
        m_pTiles[5]->FUN_00700320(0x1004, id);
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_007e0060

struct EntryEffects
{
    unsigned int unk00, unk04, unk08;
    void StatsMenu_NamedEffectsList_InsertActiveEffect(ActiveEffect*);
    void ApplyParamToEntry(ActiveEffect*);
};
struct EffectGroup
{
    TESForm* group;
    EntryEffects normal;
    EntryEffects special;
    EffectGroup(TESForm*);
};
int StatsMenu_StatusEffectSortFn(EffectGroup*, EffectGroup*);
struct EffectGroupList
{
    void BSSimpleList_ActiveEffect_Insert(EffectGroup*, int (*)(EffectGroup*, EffectGroup*));
};

struct GroupedEffectListMethods : StatsMenu__StatusEffectList
{
    EffectGroup* StatsMenu_StatusEffectList_Find(unsigned int);
    void AddEffectToGroup(ActiveEffect*);
};
// Looks up or creates an EffectGroup for the effect's form, then adds the effect to its special or normal list based on a setting flag.
// @fnv 0x007e08a0
void GroupedEffectListMethods::AddEffectToGroup(ActiveEffect* effect)
{
    TESForm* group = dynamic_cast<TESForm*>(effect->FUN_0044ddc0());
    EffectGroup* pGroup = StatsMenu_StatusEffectList_Find(group->GetFormID());
    if (!pGroup)
    {
        pGroup = new EffectGroup(group);
        ((EffectGroupList*)&bSSimpleList_StatsMenu__StatusEffect___Component)->BSSimpleList_ActiveEffect_Insert(pGroup, StatsMenu_StatusEffectSortFn);
    }
    if (((EffectSetting*)effect->GetEffectSetting())->IsFlagSet_00403e60(0x2000))
        pGroup->special.StatsMenu_NamedEffectsList_InsertActiveEffect(effect);
    else
        pGroup->normal.ApplyParamToEntry(effect);
}

struct FUN_007e09d0_sub
{
    bool BSSimpleList_TESLevSpell_IsInList(EffectSetting** apValue);
    void BSSimpleList_ActiveEffect_Insert(EffectSetting* aValue, int(__cdecl* apCallback)(EffectSetting*, EffectSetting*));
};

class NamedEffectListMethods : public StatsMenu__NamedEffectsList
{
public:
    void StatsMenu_NamedEffectsList_InsertActiveEffect(ActiveEffect*);
};

// @fnv 0x007e09d0
// src: COMMUNITY 0x007e09d0
void NamedEffectListMethods::StatsMenu_NamedEffectsList_InsertActiveEffect(ActiveEffect* arg)
{
    EffectSetting* value = arg->FUN_007df1d0();
    if (!((FUN_007e09d0_sub*)&bSSimpleList_EffectSetting___Component)->BSSimpleList_TESLevSpell_IsInList(&value))
    {
        ((FUN_007e09d0_sub*)&bSSimpleList_EffectSetting___Component)->BSSimpleList_ActiveEffect_Insert(arg->FUN_007df1d0(), CompareEffectNames);
    }
}

struct FUN_007a62e0
{
    Tile* tile;
    ActorValue::Index value;
    bool selected;
    FUN_007a62e0(Tile*, ActorValue::Index*);
};
typedef int(__cdecl* ItemCompare)(FUN_007a62e0*, FUN_007a62e0*);
struct ItemListMethods
{
    void BSSimpleList_ActiveEffect_Insert(FUN_007a62e0*, ItemCompare);
    void AddTail(FUN_007a62e0* const&);
};
struct TraitAction
{
    void RemoveFromReactions();
    void Tile_Value_AddRefValueAction(int, Tile*, int);
    void AppendFloatAction(int, float);
    void Tile_Value_SetFloat(bool);
};
struct ItemTileMethods
{
    void* Tile_GetValue(int);
    TraitAction* FindTraitValue(int);
};
struct MenuTemplateMethods
{
    Tile* FUN_00a1ddb0(Tile*, const char*, int);
};
int __cdecl Tile_AddUserTrait(const char*, int);
struct ItemBox : ListBox_enum_ActorValue__Index_
{
    bool ListBox_unsigned_int_GetFlag(unsigned int);
    void ListBox_StatsMenu_StatusEffect_Synchronize();
    void AccumulateTileHeight(Tile*);
    void UpdateState_00725970();
    int GetRaceCount();
    Tile* StatsMenu_EffectsList_Append(ActorValue::Index, const char*, ItemCompare, const char*);
};
// @fnv 0x007e1430
// src: COMMUNITY 0x007e1430
Tile* ItemBox::StatsMenu_EffectsList_Append(ActorValue::Index value, const char* text, ItemCompare compare, const char* templateName)
{
    if (m_pListTile && (pTemplateName || templateName))
    {
        Tile* tile = ((MenuTemplateMethods*)((Tile*)m_pListTile)->GetMenu())
                         ->FUN_00a1ddb0(m_pListTile, templateName ? templateName : pTemplateName, 0);
        if (!((ItemTileMethods*)tile)->Tile_GetValue(4010))
            tile->Set(4010, -1);
        if (text)
            tile->Set(4036, text, true);
        if (compare)
        {
            ((ItemListMethods*)&bSSimpleList_ListBoxItem_enum_ActorValue__Index____Component)
                ->BSSimpleList_ActiveEffect_Insert(new FUN_007a62e0(tile, &value), compare);
            if (ListBox_unsigned_int_GetFlag(0))
                ListBox_StatsMenu_StatusEffect_Synchronize();
        }
        else
        {
            ((ItemListMethods*)&bSSimpleList_ListBoxItem_enum_ActorValue__Index____Component)
                ->AddTail(new FUN_007a62e0(tile, &value));
            if (ListBox_unsigned_int_GetFlag(0))
            {
                AccumulateTileHeight(tile);
                UpdateState_00725970();
            }
            tile->Set(4012, m_usSelectedIndex++);
        }
        if (GetRaceCount() == 1 &&
            ((Tile*)m_pListTile)->FUN_00a011b0(Tile_AddUserTrait("_number_of_visible_items", -1)) > 0.0)
        {
            TraitAction* action = ((ItemTileMethods*)m_pListTile)->FindTraitValue(4016);
            action->RemoveFromReactions();
            action->Tile_Value_AddRefValueAction(2000, tile, 4016);
            action->AppendFloatAction(
                2003, ((Tile*)m_pListTile)->FUN_00a011b0(Tile_AddUserTrait("_number_of_visible_items", -1)));
            action->Tile_Value_SetFloat(false);
        }
        return tile;
    }
    else
    {
        return 0;
    }
}

namespace fnv_007e16d0 {
struct FUN_007a62e0
{
    Tile* tile;
    ActorValue::Index value;
    bool filtered;
    FUN_007a62e0(Tile*, ActorValue::Index*);
};
struct ListOperations
{
    void BSSimpleList_ActiveEffect_Insert(FUN_007a62e0*, int(__cdecl*)(FUN_007a62e0*, FUN_007a62e0*));
    void FUN_00905820(FUN_007a62e0* const&);
};
struct TemplateMenu
{
    Tile* FUN_00a1ddb0(Tile*, const char*, int);
};
struct TileValueOperations
{
    void RemoveFromReactions();
    void Tile_Value_AddRefValueAction(int, Tile*, int);
    void AppendFloatAction(int, float);
    void Tile_Value_SetFloat(int);
};
struct TileOperations
{
    TemplateMenu* Tile_GetMenu();
    void* Tile_GetValue(int);
    float FUN_00a011b0(int);
    TileValueOperations* FindTraitValue(int);
};
int __cdecl Tile_AddUserTrait(const char*, int);
extern "C" const char kListBoxNumFiltered[];
struct ListBoxInsert : ListBox_enum_ActorValue__Index_
{
    bool ListBox_unsigned_int_GetFlag(unsigned int);
    void ProcessSlots();
    void AccumulateTileHeight(Tile*);
    void UpdateScrollTraits();
    int GetRaceCount();
    Tile* StatsMenu_ReputationList_Append(ActorValue::Index value, const char* text,
                       int(__cdecl* comparator)(FUN_007a62e0*, FUN_007a62e0*), const char* templateName);
};
// @fnv 0x007e16d0
// src: COMMUNITY 0x007e16d0
Tile* ListBoxInsert::StatsMenu_ReputationList_Append(ActorValue::Index value, const char* text,
                                  int(__cdecl* comparator)(FUN_007a62e0*, FUN_007a62e0*), const char* templateName)
{
    if (m_pListTile && (pTemplateName || templateName))
    {
        Tile* tile = ((TileOperations*)m_pListTile)
                         ->Tile_GetMenu()
                         ->FUN_00a1ddb0(m_pListTile, templateName ? templateName : pTemplateName, 0);
        if (!((TileOperations*)tile)->Tile_GetValue(0xFAA))
            tile->Set(0xFAA, -1);
        if (text)
            tile->Set(0xFC4, text, true);
        if (comparator)
        {
            ((ListOperations*)&bSSimpleList_ListBoxItem_enum_ActorValue__Index____Component)
                ->BSSimpleList_ActiveEffect_Insert(new FUN_007a62e0(tile, &value), comparator);
            if (ListBox_unsigned_int_GetFlag(0))
                ProcessSlots();
        }
        else
        {
            ((ListOperations*)&bSSimpleList_ListBoxItem_enum_ActorValue__Index____Component)
                ->FUN_00905820(new FUN_007a62e0(tile, &value));
            if (ListBox_unsigned_int_GetFlag(0))
            {
                AccumulateTileHeight(tile);
                UpdateScrollTraits();
            }
            tile->Set(0xFAC, m_usSelectedIndex++);
        }
        if (GetRaceCount() == 1 &&
            ((TileOperations*)m_pListTile)->FUN_00a011b0(Tile_AddUserTrait(kListBoxNumFiltered, -1)) > 0.0)
        {
            TileValueOperations* height = ((TileOperations*)m_pListTile)->FindTraitValue(0xFB0);
            height->RemoveFromReactions();
            height->Tile_Value_AddRefValueAction(0x7D0, tile, 0xFB0);
            height->AppendFloatAction(
                0x7D3, ((TileOperations*)m_pListTile)->FUN_00a011b0(Tile_AddUserTrait(kListBoxNumFiltered, -1)));
            height->Tile_Value_SetFloat(0);
        }
        return tile;
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_007e16d0

namespace fnv_007dc490 {
bool InterfaceManager_Has360Controller();

class StatusEntry
{
  public:
    int FindEntryIndex();
};
StatusEntry* __stdcall StatsMenu_BodyPartController_GetInstance(int iIndex);

class StatusMenuMethods : public StatsMenu
{
public:
    void FUN_007e0230();
    void StatsMenu_DoLeave(int, int);
};

// @fnv 0x007dc490
// src: XBOX_PDB 0x007dc490
void StatusMenuMethods::StatsMenu_DoLeave(int iUnused, int iIndex)
{
    if (m_bUpdateOption && !InterfaceManager_Has360Controller())
    {
        int iType = StatsMenu_BodyPartController_GetInstance(iIndex)->FindEntryIndex();
        if (iType != 6)
            FUN_007e0230();
    }
    m_pTiles[52]->Set(0xfa3, 0);
}
}  // namespace fnv_007dc490

namespace fnv_007dc1b0 {

struct ListClick
{
    bool ContainsKey(Tile*);
    void* FindItemData(Tile*);
};
struct StatusH
{
    int FindEntryIndex();
    void SetBodyPart(bool);
};
StatusH* __stdcall StatsMenu_BodyPartController_GetInstance(Tile*);
StatusH* __stdcall StatsMenu_BodyPartController_GetInstance(int);
bool __cdecl InterfaceManager_Has360Controller();
extern char DAT_01074f40[];
extern int DAT_011dad60, DAT_011dad64, DAT_011dad68, DAT_011dad6c, DAT_011dad70;
struct ClickMenu : public StatsMenu
{
    void StatsMenu_MoveKnob(Tile*, int*);
    void UpdateStatsDisplay(void*);
    void UpdateScrollBar(void*);
    void SetReputationEntry(void*);
    void FUN_007e0230();
    void OnTileClick(int id, Tile* tile);
};
// Handles a tile click on the stats menu by dispatching to the current page's list, updating the display, and playing a sound for status effects.
// @fnv 0x007dc1b0
void ClickMenu::OnTileClick(int aiTileIndex, Tile* tile)
{
    if (!tile && aiTileIndex >= 0 && aiTileIndex < 60)
        tile = m_pTiles[aiTileIndex];
    switch (GetCurrentPage())
    {
    case SM_STATUS:
        if (((Tile*)tile)->FUN_00a011b0(0xfac) > 0.0)
            StatsMenu_MoveKnob(tile, &DAT_011dad60);
        if (!InterfaceManager_Has360Controller())
        {
            if ((g_thePlayer && ((bool (__thiscall*)(PlayerCharacter*))GetPlayerHardcoreMode)(g_thePlayer)) ? m_kHealingOptions[3].m_pStatusEffect
                                                                             : m_kHealingOptions[0].m_pStatusEffect)
            {
                int status = StatsMenu_BodyPartController_GetInstance(tile)->FindEntryIndex();
                if (status != 6)
                {
                    StatsMenu_BodyPartController_GetInstance(status)->SetBodyPart(true);
                    static_cast<StatsMenuAudioMethods*>(BSAudio::GetSingleton())
                        ->GetSoundHandleByEditorID(DAT_01074f40, 0x121).Play(false);
                    if (!m_bUpdateOption)
                        FUN_007e0230();
                }
            }
        }
        break;
    case SM_SPECIAL:
        if (((ListClick*)&m_kPrimaryActorValueList)->ContainsKey(tile))
        {
            StatsMenu_MoveKnob(tile, &DAT_011dad64);
            UpdateStatsDisplay(((ListClick*)&m_kPrimaryActorValueList)->FindItemData(tile));
        }
        break;
    case SM_SKILLS:
        if (((ListClick*)&m_kSecondaryActorValueList)->ContainsKey(tile))
        {
            StatsMenu_MoveKnob(tile, &DAT_011dad68);
            UpdateStatsDisplay(((ListClick*)&m_kSecondaryActorValueList)->FindItemData(tile));
        }
        break;
    case SM_PERKS:
        if (((ListClick*)&m_kPerkRankList)->ContainsKey(tile))
        {
            StatsMenu_MoveKnob(tile, &DAT_011dad6c);
            UpdateScrollBar(((ListClick*)&m_kPerkRankList)->FindItemData(tile));
        }
        break;
    case SM_GENERAL:
        if (((ListClick*)&m_kMiscStatList)->ContainsKey(tile))
            StatsMenu_MoveKnob(tile, &DAT_011dad70);
        if (((ListClick*)&m_kReputationList)->ContainsKey(tile))
        {
            SetReputationEntry(((ListClick*)&m_kReputationList)->FindItemData(tile));
            StatsMenu_MoveKnob(tile, &DAT_011dad70);
        }
        break;
    }
}
}  // namespace fnv_007dc1b0

namespace s7e00e0 {

struct Owner
{
    bool SetIndexFromType(unsigned int uiType, int* piIndex);
};

// Sets *piIndex to the matching value for uiType 0-4 and returns true, or returns false for any other value.
// @fnv 0x007e00e0
bool Owner::SetIndexFromType(unsigned int uiType, int* piIndex)
{
    switch (uiType)
    {
    case 0:
        *piIndex = 0;
        return true;
    case 1:
        *piIndex = 1;
        return true;
    case 2:
        *piIndex = 2;
        return true;
    case 3:
        *piIndex = 3;
        return true;
    case 4:
        *piIndex = 4;
        return true;
    }
    return false;
}

}

void* __cdecl operator new(unsigned int size);

BGSHungerStage* __cdecl FindHungerStage(float level);
BGSSleepDeprevationStage* __cdecl GetSleepDeprivationStage(float level);
const char* __cdecl ActorValue_GetActorValueAbbreviation(int av);
unsigned int __cdecl FUN_0042f5a0(unsigned int a, unsigned int b);
extern const char DAT_01012630[];
extern const char DAT_01019f08[];

extern Setting g_011d1ef0;

// Rebuilds the stats menu status-effect tiles and list from the player's active effects and survival stage spells.
// @fnv 0x007ddf00
// src: XBOX_PDB 0x007ddf00
void StatsMenuActiveEffects::StatsMenu_UpdateActiveEffects()
{
    BGSDehydrationStage* ph20stage;
    BGSSleepDeprevationStage* psleepstage;
    BGSRadiationStage* pradstage;
    if (m_bStatUpdatePending)
        return;
    m_bStatUpdatePending = true;
    BSStringT<char> strtmp;
    Tile* ptile;
    ActiveEffect* pactiveEffect;
    BGSHungerStage* phungerstage;

    ((StatusEffectListOps*)&m_kStatusEffectEntries)->StatsMenu_StatusEffectList_Flush();
    delete m_pStatusEffectAtIndex0;
    m_pStatusEffectAtIndex0 = 0;
    delete m_pStatusEffectAtIndex1;
    m_pStatusEffectAtIndex1 = 0;
    delete m_pStatusEffectAtIndex3;
    m_pStatusEffectAtIndex3 = 0;
    delete m_pStatusEffectAtIndex2;
    m_pStatusEffectAtIndex2 = 0;

    pradstage = BGSRadiationStage::GetStageForLevel(g_thePlayer->GetCurrentActorValue((ActorValue::Index)54));
    ph20stage = BGSDehydrationStage::FindStage(g_thePlayer->GetCurrentActorValue((ActorValue::Index)73));
    psleepstage = GetSleepDeprivationStage(g_thePlayer->GetCurrentActorValue((ActorValue::Index)75));
    phungerstage = FindHungerStage(g_thePlayer->GetCurrentActorValue((ActorValue::Index)74));

    for (BSSimpleList<ActiveEffect*>* pnode = ((PlayerCharacter*)g_thePlayer)->GetActiveEffectList();
         pnode && (pactiveEffect = pnode->GetItem()); pnode = pnode->GetNext())
    {
        if (((ActiveEffect*)pactiveEffect)->ActiveEffect_IsActive() &&
            !((EffectItem*)((ActiveEffect*)pactiveEffect)->GetHavokWorldObjectCountInSceneGraph_0084e3a0())->IsScriptBasedEffect() &&
            (!pactiveEffect->GetEffectSetting()->IsScriptEffect() ||
             ((EffectSetting*)pactiveEffect->GetEffectSetting())->IsFlagSet(0x2000)))
        {
            SpellItem* pspell = dynamic_cast<SpellItem*>(((ActiveEffect*)pactiveEffect)->FUN_0044ddc0());
            if (pspell && pradstage && pspell == pradstage->GetSpell())
            {
                if (!m_pStatusEffectAtIndex0)
                    m_pStatusEffectAtIndex0 = new StatsMenu__StatusEffect(pspell);
                if (m_pStatusEffectAtIndex0->pForm == pspell)
                    m_pStatusEffectAtIndex0->xEffectData.ApplyParamToEntry(pactiveEffect);
            }
            if (pspell && ph20stage && pspell == ph20stage->GetSpell())
            {
                if (!m_pStatusEffectAtIndex1)
                    m_pStatusEffectAtIndex1 = new StatsMenu__StatusEffect(pspell);
                if (m_pStatusEffectAtIndex1->pForm == pspell)
                    m_pStatusEffectAtIndex1->xEffectData.ApplyParamToEntry(pactiveEffect);
            }
            if (pspell && phungerstage && pspell == phungerstage->GetSpell())
            {
                if (!m_pStatusEffectAtIndex2)
                    m_pStatusEffectAtIndex2 = new StatsMenu__StatusEffect(pspell);
                if (m_pStatusEffectAtIndex2->pForm == pspell)
                    m_pStatusEffectAtIndex2->xEffectData.ApplyParamToEntry(pactiveEffect);
            }
            if (pspell && psleepstage && pspell == psleepstage->GetSpell())
            {
                if (!m_pStatusEffectAtIndex3)
                    m_pStatusEffectAtIndex3 = new StatsMenu__StatusEffect(pspell);
                if (m_pStatusEffectAtIndex3->pForm == pspell)
                    m_pStatusEffectAtIndex3->xEffectData.ApplyParamToEntry(pactiveEffect);
            }
            if (((EffectItem*)((ActiveEffect*)pactiveEffect)->GetHavokWorldObjectCountInSceneGraph_0084e3a0())->IsActorValueUsed() &&
                ActorValue_GetActorValueAbbreviation(
                    ((EffectItem*)((ActiveEffect*)pactiveEffect)->GetHavokWorldObjectCountInSceneGraph_0084e3a0())->GetAffectedActorValue()) &&
                (pactiveEffect->GetDuration() != 0.0 || ((int (__thiscall*)(ActiveEffect*))GetActiveEffectSpellType)(pactiveEffect) == 1 ||
                 ((int (__thiscall*)(ActiveEffect*))GetActiveEffectSpellType)(pactiveEffect) == 6 ||
                 ((int (__thiscall*)(ActiveEffect*))GetActiveEffectSpellType)(pactiveEffect) == 10 ||
                 (((int (__thiscall*)(ActiveEffect*))GetActiveEffectSpellType)(pactiveEffect) == 4 &&
                  ((ActiveEffect*)pactiveEffect)->HasConditions())))
            {
                ((StatusEffectListOps*)&m_kStatusEffectEntries)->AddEffectToGroup(pactiveEffect);
            }
            else if (((EffectSetting*)pactiveEffect->GetEffectSetting())->IsFlagSet(0x2000))
            {
                ((StatusEffectListOps*)&m_kStatusEffectEntries)->AddEffectToGroup(pactiveEffect);
            }
        }
    }

    if (m_pStatusEffectAtIndex0)
    {
        ((Tile*)m_pTiles[32])->ResetImage();
        int i = 0;
        for (BSSimpleList<MagicEffectEntry*>* pnode = &m_pStatusEffectAtIndex0->xEffectData; pnode && pnode->GetItem();
             pnode = pnode->GetNext())
        {
            Tile* ptile = ((Menu*)this)->CreateTileFromTemplate(m_pTiles[32], "stats_rad_effects_template", 0);
            ptile->Set(0xfac, i++);
            strtmp = "stats_rad_effect_";
            strtmp += ActorValue_GetActorValueAbbreviation(pnode->GetItem()->m_eAssociatedActorValue);
            ((void (__thiscall*)(Tile*, BSStringT<char>&))SetTileImageName)(ptile, strtmp);
            strtmp.PrintfString("%+d", pnode->GetItem()->m_iMagnitude);
            ptile->Set(0xfc4, strtmp, true);
            ptile->Set(0x1005, ActorValue_GetActorValueAbbreviation(pnode->GetItem()->m_eAssociatedActorValue), true);
        }
        m_pTiles[32]->Set(0xfa3, 1);
    }
    else
    {
        m_pTiles[32]->Set(0xfa3, 0);
    }

    if (m_pStatusEffectAtIndex1)
    {
        ((Tile*)m_pTiles[54])->ResetImage();
        int i = 0;
        for (BSSimpleList<MagicEffectEntry*>* pnode = &m_pStatusEffectAtIndex1->xEffectData; pnode && pnode->GetItem();
             pnode = pnode->GetNext())
        {
            Tile* ptile = ((Menu*)this)->CreateTileFromTemplate(m_pTiles[54], "stats_rad_effects_template", 0);
            ptile->Set(0xfac, i++);
            strtmp = "stats_h20_effect_";
            strtmp += ActorValue_GetActorValueAbbreviation(pnode->GetItem()->m_eAssociatedActorValue);
            ((void (__thiscall*)(Tile*, BSStringT<char>&))SetTileImageName)(ptile, strtmp);
            strtmp.PrintfString("%+d", pnode->GetItem()->m_iMagnitude);
            ptile->Set(0xfc4, strtmp, true);
            ptile->Set(0x1005, ActorValue_GetActorValueAbbreviation(pnode->GetItem()->m_eAssociatedActorValue), true);
        }
        m_pTiles[54]->Set(0xfa3, 1);
    }
    else
    {
        m_pTiles[54]->Set(0xfa3, 0);
    }

    if (m_pStatusEffectAtIndex2)
    {
        ((Tile*)m_pTiles[56])->ResetImage();
        int i = 0;
        for (BSSimpleList<MagicEffectEntry*>* pnode = &m_pStatusEffectAtIndex2->xEffectData; pnode && pnode->GetItem();
             pnode = pnode->GetNext())
        {
            Tile* ptile = ((Menu*)this)->CreateTileFromTemplate(m_pTiles[56], "stats_rad_effects_template", 0);
            ptile->Set(0xfac, i++);
            strtmp = "stats_hunger_effect_";
            strtmp += ActorValue_GetActorValueAbbreviation(pnode->GetItem()->m_eAssociatedActorValue);
            ((void (__thiscall*)(Tile*, BSStringT<char>&))SetTileImageName)(ptile, strtmp);
            strtmp.PrintfString("%+d", pnode->GetItem()->m_iMagnitude);
            ptile->Set(0xfc4, strtmp, true);
            ptile->Set(0x1005, ActorValue_GetActorValueAbbreviation(pnode->GetItem()->m_eAssociatedActorValue), true);
        }
        m_pTiles[56]->Set(0xfa3, 1);
    }
    else
    {
        m_pTiles[56]->Set(0xfa3, 0);
    }

    if (m_pStatusEffectAtIndex3)
    {
        ((Tile*)m_pTiles[58])->ResetImage();
        int i = 0;
        for (BSSimpleList<MagicEffectEntry*>* pnode = &m_pStatusEffectAtIndex3->xEffectData; pnode && pnode->GetItem();
             pnode = pnode->GetNext())
        {
            Tile* ptile = ((Menu*)this)->CreateTileFromTemplate(m_pTiles[58], "stats_rad_effects_template", 0);
            ptile->Set(0xfac, i++);
            strtmp = "stats_sleep_effect_";
            strtmp += ActorValue_GetActorValueAbbreviation(pnode->GetItem()->m_eAssociatedActorValue);
            ((void (__thiscall*)(Tile*, BSStringT<char>&))SetTileImageName)(ptile, strtmp);
            strtmp.PrintfString("%+d", pnode->GetItem()->m_iMagnitude);
            ptile->Set(0xfc4, strtmp, true);
            ptile->Set(0x1005, ActorValue_GetActorValueAbbreviation(pnode->GetItem()->m_eAssociatedActorValue), true);
        }
        m_pTiles[58]->Set(0xfa3, 1);
    }
    else
    {
        m_pTiles[58]->Set(0xfa3, 0);
    }

    ptile = 0;
    ((void (__thiscall*)(ListBoxBase*))(*(void***)&m_kStatusEffectList)[7])(&m_kStatusEffectList);
    for (BSSimpleList<StatsMenu__StatusEffect*>* peffectlistnode = &m_kStatusEffectEntries ? &m_kStatusEffectEntries.bSSimpleList_StatsMenu__StatusEffect___Component : 0;
         peffectlistnode && peffectlistnode->GetItem(); peffectlistnode = peffectlistnode->GetNext())
    {
        ptile = ((StatusEffectListBox*)&m_kStatusEffectList)->AddItem(peffectlistnode->GetItem(), 0, 0, 0);
        AlchemyItem* ppotion = dynamic_cast<AlchemyItem*>(peffectlistnode->GetItem()->pForm);
        if (ppotion && ((EquipTypeComponent*)((char*)ppotion + 0x9c))->GetEquipType() == 13)
        {
            ptile->Set(0x1004, g_011d1ef0.String(), true);
        }
        else
        {
            TESFullName* pname = dynamic_cast<TESFullName*>(peffectlistnode->GetItem()->pForm);
            if (pname)
            {
                ptile->Set(0x1004, ((TESFullName*)pname)->GetFullName(), true);
            }
            else
            {
                ptile->Set(0x1004, peffectlistnode->GetItem()->pForm->GetName(), true);
            }
        }
        BSStringT<char> streffects;
        for (BSSimpleList<EffectSetting*>* pnamelistnode = &peffectlistnode->GetItem()->m_kNamedEffectsList;
             pnamelistnode && pnamelistnode->GetItem(); pnamelistnode = pnamelistnode->GetNext())
        {
            if (((EffectSetting*)pnamelistnode->GetItem())->GetEffectName())
            {
                strtmp.PrintfString(DAT_01019f08,
                               (const char*)((EffectSetting*)pnamelistnode->GetItem())->GetEffectName());
                ((BSStringT<char>& (__thiscall*)(BSStringT<char>*, const BSStringT<char>&))AppendStatsEffectString)(&streffects, strtmp);
                if (pnamelistnode->GetNext())
                    streffects += DAT_01012630;
            }
        }
        if (streffects.Length() > 0 && peffectlistnode->GetItem()->xEffectData.ItemsInList())
            streffects += DAT_01012630;
        for (BSSimpleList<MagicEffectEntry*>* pdatalistnode = &peffectlistnode->GetItem()->xEffectData;
             pdatalistnode && pdatalistnode->GetItem(); pdatalistnode = pdatalistnode->GetNext())
        {
            if (pdatalistnode->GetItem()->m_iMagnitude)
            {
                strtmp.PrintfString("%s %+d", ActorValue_GetActorValueAbbreviation(pdatalistnode->GetItem()->m_eAssociatedActorValue),
                               pdatalistnode->GetItem()->m_iMagnitude);
                ((BSStringT<char>& (__thiscall*)(BSStringT<char>*, const BSStringT<char>&))AppendStatsEffectString)(&streffects, strtmp);
                if (pdatalistnode->GetNext())
                    streffects += DAT_01012630;
            }
        }
        ptile->Set(0x1005, streffects, true);
    }

    if (ptile)
    {
        ((Tile*)m_pTiles[33])
            ->Set(0xfb0,
                  FUN_0042f5a0(8, ((StatusEffectListBox*)&m_kStatusEffectList)->GetNumItems()) * ptile->GetFloat(0xfb0),
                  true);
        ptile->Set(0x1006, 0);
    }
    else
    {
        m_pTiles[33]->Set(0xfb0, 0);
    }
    ((StatusEffectListBox*)&m_kStatusEffectList)->Synchronize();
}

namespace fnv_007db680 {

struct InputChildren
{
    Tile*& FUN_007b5370();
};
struct InputList
{
    Tile* FUN_00825c00();
};

struct InputStatus
{
    unsigned int Modelloader_GetReferencedThis() const;
    int GetByte(unsigned int, int);
    void SetBodyPart(int, bool);
};
class FUN_007db2c0;
FUN_007db2c0* __cdecl StatsMenu_BodyPartController_GetInstance();
bool __cdecl Interface_IsTopMenuID(int);
struct InputRendered
{
    bool IsUnk28Set();
};
InputRendered* __cdecl Interface_GetPipboy();
bool __cdecl IsActorValueBelowPermanent(StatsMenu__HealingOption*);
bool __cdecl IsHealingOptionAvailable(const StatsMenu__HealingOption*);
BSAudio* __cdecl BSAudio_QInstance();
void __cdecl InterfaceManager_PlayMenuSound(int);
void __cdecl UpdatePipboyMapVisibility(int, bool);
void __cdecl Interface_SetInventoryMenuVisible(int, bool, bool);
StatsMenu::Page* __cdecl DecrementInt(StatsMenu::Page*);
StatsMenu::Page* __cdecl FUN_007dc0a0(StatsMenu::Page*);
struct InputSetting
{
    float* Setting_Float_00403e20();
};
extern InputSetting g_011db358;
extern InputSetting g_011db2f0;
struct InputInterface
{
    FOPipboyManager* FUN_00704370();
};
InputInterface* __cdecl InterfaceManager_GetSingleton();
bool __cdecl Interface_Has360Controller();
struct InputControls
{
    int GetAxisState(int, int);
};
struct InputOS
{
    InputControls* Main_GetControls();
};
extern InputOS* g_osGlobals;
double __cdecl NiAbs_00408820(float);
unsigned int __cdecl gm_GetTickCount();
extern unsigned int DAT_011dad5c;
int __cdecl Tile_TextToTrait(const char*);

struct InputStats : public StatsMenu
{
    int StatsMenu_GetStatusPage();
    bool StatsMenu_SetStatusPage(int);
    bool GetTileIndex(int, int*);
    bool StatsMenu_DoGamepad(int code, float amount);
};

// Processes input codes for the stats menu, updating healing options, status values, page navigation, and scrolling effect lists.
// @fnv 0x007db680
// src: XBOX_PDB 0x007db680
bool InputStats::StatsMenu_DoGamepad(int code, float amount)
{
    if (!Interface_IsTopMenuID(1003) || !Interface_GetPipboy()->IsUnk28Set())
        return false;
    if (Interface_IsTopMenuID(1003))
    {
        if (m_bUpdateOption && (code == 1 || code == 2 || code == 4 || code == 3))
        {
            int direction;
            switch (code)
            {
            case 1:
                direction = 0;
                break;
            case 2:
                direction = 1;
                break;
            case 4:
                direction = 2;
                break;
            case 3:
                direction = 3;
                break;
            default:
                return false;
            }
            int selected3 =
                ((InputStatus*)StatsMenu_BodyPartController_GetInstance())->GetByte(((InputStatus*)StatsMenu_BodyPartController_GetInstance())->Modelloader_GetReferencedThis(), direction);
            if (selected3 < 6)
            {
                ((InputStatus*)StatsMenu_BodyPartController_GetInstance())->SetBodyPart(selected3, true);
                m_kHealingOptions[0].pTile->Set(0xfaf, IsActorValueBelowPermanent(&m_kHealingOptions[0]));
                m_kHealingOptions[3].pTile->Set(0xfaf, IsHealingOptionAvailable(&m_kHealingOptions[3]));
                static_cast<StatsMenuAudioMethods*>(BSAudio_QInstance())
                    ->GetSoundHandleByEditorID("UIPipBoyHighlight", 0x121).Play(false);
            }
            return true;
        }
        else if ((code == 13 || code == 14) && amount >= 1.0)
        {
            InterfaceManager_PlayMenuSound(0x24);
            if (code == 13)
                UpdatePipboyMapVisibility(1, false);
            else
                Interface_SetInventoryMenuVisible(1, false, true);
            return true;
        }
        else if (code == 4)
        {
            Page _previousPage = GetCurrentPage();
            SetCurrentPage(_previousPage == 0 ? SM_LAST_PAGE : *DecrementInt(&_previousPage));
            ((Tile*)m_pTiles[0])->Tile_PlayTileSound(0xfcb);
            return true;
        }
        else if (code == 3)
        {
            Page nextPage = GetCurrentPage();
            SetCurrentPage(nextPage == 4 ? SM_FIRST_PAGE : *FUN_007dc0a0(&nextPage));
            ((Tile*)m_pTiles[0])->Tile_PlayTileSound(0xfcb);
            return true;
        }
        else if (GetCurrentPage() == SM_GENERAL)
        {
            if (code == 11)
            {
                HandleSelection(0x31, 0);
                return true;
            }
        }
        else if (GetCurrentPage() == SM_STATUS)
        {
            if (code == 1 || code == 2)
            {
                int statusStep6 = code == 1 ? -1 : 1;
                int newStatusVal = StatsMenu_GetStatusPage() + statusStep6;
                if (StatsMenu_SetStatusPage(newStatusVal))
                {
                    int limbVal = 6;
                    if (GetTileIndex(0x1c, &limbVal) && limbVal == newStatusVal)
                        ((Tile*)m_pTiles[28])->Tile_PlayTileSound(0xfcb);
                    else if (GetTileIndex(0x1d, &limbVal) && limbVal == newStatusVal)
                        ((Tile*)m_pTiles[29])->Tile_PlayTileSound(0xfcb);
                    else if (GetTileIndex(0x1e, &limbVal) && limbVal == newStatusVal)
                        ((Tile*)m_pTiles[30])->Tile_PlayTileSound(0xfcb);
                    else if (GetTileIndex(0x35, &limbVal) && limbVal == newStatusVal)
                        ((Tile*)m_pTiles[53])->Tile_PlayTileSound(0xfcb);
                    else if (GetTileIndex(0x37, &limbVal) && limbVal == newStatusVal)
                        ((Tile*)m_pTiles[55])->Tile_PlayTileSound(0xfcb);
                    else if (GetTileIndex(0x39, &limbVal) && limbVal == newStatusVal)
                        ((Tile*)m_pTiles[57])->Tile_PlayTileSound(0xfcb);
                    ((void (__thiscall*)(FOPipboyManager*, int, float, float, bool))UpdatePipboyScrollKnobTarget)(
                        InterfaceManager_GetSingleton()->FUN_00704370(), 0, *g_011db2f0.Setting_Float_00403e20() * statusStep6,
                                                                 *g_011db358.Setting_Float_00403e20(), true);
                    return true;
                }
            }
            else if (code == 9)
            {
                switch (StatsMenu_GetStatusPage())
                {
                case 0:
                    HandleSelection(10, 0);
                    return true;
                case 1:
                    HandleSelection(11, 0);
                    return true;
                default:
                    return false;
                }
            }
            else if (code == 11)
            {
                switch (StatsMenu_GetStatusPage())
                {
                case 0:
                    if (!m_bUpdateOption && ((Tile*)m_pTiles[9])->IsTraitNonZero(0xfaf))
                    {
                        HandleSelection(9, 0);
                        static_cast<StatsMenuAudioMethods*>(BSAudio_QInstance())
                            ->GetSoundHandleByEditorID("UIMenuOK", 0x121).Play(false);
                        return true;
                    }
                    return false;
                case 1:
                    HandleSelection(31, 0);
                    return true;
                default:
                    return false;
                }
            }
            else if (code == 12)
            {
                switch (StatsMenu_GetStatusPage())
                {
                case 0:
                    if (((Tile*)m_pTiles[9])->IsTraitNonZero(0xfaf))
                    {
                        HandleSelection(59, 0);
                        static_cast<StatsMenuAudioMethods*>(BSAudio_QInstance())
                            ->GetSoundHandleByEditorID("UIMenuOK", 0x121).Play(false);
                        return true;
                    }
                    return false;
                case 1:
                    HandleSelection(31, 0);
                    return true;
                default:
                    return false;
                }
            }
        }
        if (Interface_Has360Controller() &&
            (((InputList*)&m_kStatusEffectList)->FUN_00825c00()->IsAllChildrenFlag0() ||
             ((Tile*)((InputChildren*)&m_pTiles[26]->m_kChildTileList)->FUN_007b5370())->IsTraitNonZero(0xfa3)))
        {
            int axisB = 0;
            int scrollStepVal4 = 0;
            axisB = g_osGlobals->Main_GetControls()->GetAxisState(0, 10);
            if (NiAbs_00408820((float)axisB) <= 8689.0)
                axisB = 0;
            if (axisB != 0)
                scrollStepVal4 = axisB >= 0 ? -1 : 1;
            if (scrollStepVal4 != 0 && gm_GetTickCount() > DAT_011dad5c)
            {
                Tile* scrollTile =
                    GetCurrentPage() == SM_STATUS
                        ? ((InputList*)&m_kStatusEffectList)->FUN_00825c00()
                        : (Tile*)((InputChildren*)&m_pTiles[26]->m_kChildTileList)->FUN_007b5370();
                int trait3 = Tile_TextToTrait("_current_value");
                int oldValue4 = (int)scrollTile->FUN_00a011b0(trait3);
                scrollTile->Tile_Set(trait3, (float)(oldValue4 + scrollStepVal4), false);
                if (oldValue4 != scrollTile->FUN_00a011b0(trait3))
                    scrollTile->SetTraitFloat(Tile_TextToTrait("_SetInCode"), 1.0f);
                DAT_011dad5c =
                    gm_GetTickCount() + (DAT_011dad5c ? (int)((Tile*)m_pTiles[33])->FUN_00a011b0(0x1004)
                                                      : (int)((Tile*)m_pTiles[33])->FUN_00a011b0(0x1005));
            }
            else if (scrollStepVal4 == 0)
                DAT_011dad5c = 0;
        }
    }
    return false;
}
}  // namespace fnv_007db680
