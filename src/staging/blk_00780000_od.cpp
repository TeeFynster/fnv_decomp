
// src/staging/blk_00780000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/Actor.h"
#include "../../include/Menu.h"
#include "../../include/Tile.h"
#include "../../include/TileShaderProperty.h"
// ActorValueUtility_blk_00780000_od: local type (was include/ActorValueUtility.h, which had no evidence of one real class); its methods are 0x00648b50 GamePlayFormulas::GetRequiredExperiencePoints
class ActorValueUtility_blk_00780000_od
{
public:
    static int __cdecl ConvertActorValue(int);
};
#include "../../include/InventoryMenu.h"
#include "../../include/LoveTesterMenu.h"
#include "../../include/NiAdditionalGeometryData.h"
#include "../../include/ShadowSceneNode.h"
#include "../../include/BSSystemUtility.h"
#include "../../include/GO.h"

struct FUN_007832e0_class
{
    void UpdateCurrentValueTile(int a);
    void ListBox_ItemChange_SetListState(float a, float b);
};

// Stores two floats at offsets 9 and 10 of this object, then calls UpdateCurrentValueTile with 1.
// @fnv 0x007832e0
// src: XBOX_PDB 0x007832e0
void FUN_007832e0_class::ListBox_ItemChange_SetListState(float afFirst, float afSecond)
{
    ((float*)this)[9] = afFirst;
    ((float*)this)[10] = afSecond;
    UpdateCurrentValueTile(1);
}

struct FUN_00788330
{
    void* __thiscall Alloc(int a);
};

// Allocates a block of a * 20 bytes via operator new and returns the pointer.
// @fnv 0x00788330
void* __thiscall FUN_00788330::Alloc(int a)
{
    void* result = operator new(a * 20);
    return result;
}


// If the BSSystemUtility singleton exists, sets its byte at offset 0x4a to 1 and calls Update().
// @fnv 0x0078d050
void UpdateSystemUtility()
{
    if (BSSystemUtility::ms_pSystemUtility)
    {
        ((char*)BSSystemUtility::ms_pSystemUtility)[0x4a] = 1;
        BSSystemUtility::ms_pSystemUtility->Update();
    }
}

struct FUN_00792780_Class
{
    void SetByteAtOffset30(unsigned char param);
};

// @fnv 0x00792780
void FUN_00792780_Class::SetByteAtOffset30(unsigned char aucValue)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x30) = aucValue;
}

struct GlobalObject_00788300
{
    ~GlobalObject_00788300();
    void* __thiscall Destroy(unsigned int flags);
};
// Runs the destructor and, when flags has bit 0 set, frees the object with operator delete; returns this.
// @fnv 0x00788360
void* __thiscall GlobalObject_00788300::Destroy(unsigned int flags)
{
    GlobalObject_00788300::~GlobalObject_00788300();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_0078d8d0_Class
{
    void __thiscall LoadingMenu_UpdateState_0078d8b0();
    void* __thiscall FUN_0078d8d0(unsigned int flags);
};

void __cdecl Deallocate(void*);

// Calls FUN_0078d8b0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0078d8d0
void* __thiscall FUN_0078d8d0_Class::FUN_0078d8d0(unsigned int flags)
{
    LoadingMenu_UpdateState_0078d8b0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0078e090_class
{
    char __thiscall LockPickMenu_HasTiles();
};

// Checks the 16 int slots at offset 0x2c and returns 1 only if every one is non-zero, otherwise 0.
// @fnv 0x0078e090
// src: COMMUNITY 0x0078e090
char __thiscall FUN_0078e090_class::LockPickMenu_HasTiles()
{
    for (int i = 0; i < 16; ++i)
    {
        if (!(*(int*)((char*)this + 0x2c + i * 4)))
            return 0;
    }
    return 1;
}

extern "C" void __cdecl CreateLoveTesterMenu(int a);

// @fnv 0x007915e0
// src: GUESS 0x007915e0 (confidence: medium)
void __cdecl Object_CreateLoveTesterMenu_Thunk()
{
    CreateLoveTesterMenu(0x23);
}

struct NiAVObject;
struct PropHelper
{
    void* GetProperty(unsigned int id);
};
int __cdecl NiShadeProperty_GetType(void);
struct FUN_0078cf10_Class
{
    void __thiscall SetAlphaRecursive(NiAVObject* object, float alpha);
};
// Recursively applies alpha to the object's children and, if the object has a shader property, sets its alpha.
// @fnv 0x0078cf10
void __thiscall FUN_0078cf10_Class::SetAlphaRecursive(NiAVObject* object, float alpha)
{
    if (!object)
        return;
    NiNode* node = ((NiNode * (__thiscall*)(void*))(*(void***)object)[3])(object);
    for (unsigned int i = 0; node && i < node->GetNumChildren(); ++i)
        SetAlphaRecursive(node->GetAt(i), alpha);
    if (((int(__thiscall*)(void*))(*(void***)object)[6])(object))
    {
        TileShaderProperty* pShaderProp = (TileShaderProperty*)((PropHelper*)object)->GetProperty(NiShadeProperty_GetType());
        if (pShaderProp)
            pShaderProp->SetAlpha(alpha);
    }
}

struct S5460
{
    virtual void v0();
    virtual unsigned int v1(unsigned int a);
    bool BSSimpleArray_NavMeshInfo_1024_ShouldGrow();
    unsigned int BSSimpleArray_NavMeshInfo_1024_GetNewSizeForGrow();
    unsigned int BSSimpleArray_CombatMember_1024_AddUninitialized();
};
struct FUN_0098f040_shell
{
    void UpdateThreat(unsigned int a, unsigned int b);
};
// If FUN_00438b90 succeeds, initializes or advances the id at offset 0xc, then increments the counter at offset 8 and returns its previous value.
// @fnv 0x007881d0
// src: XBOX_PDB 0x007881d0
unsigned int S5460::BSSimpleArray_CombatMember_1024_AddUninitialized()
{
    if (BSSimpleArray_NavMeshInfo_1024_ShouldGrow())
    {
        if (!*(unsigned int*)((char*)this + 0xc))
        {
            unsigned int id = 4;
            *(unsigned int*)((char*)this + 4) = v1(id);
            *(unsigned int*)((char*)this + 0xc) = id;
        }
        else
        {
            unsigned int id = BSSimpleArray_NavMeshInfo_1024_GetNewSizeForGrow();
            ((FUN_0098f040_shell*)this)->UpdateThreat(id, *(unsigned int*)((char*)this + 8));
            *(unsigned int*)((char*)this + 0xc) = id;
        }
    }
    *(unsigned int*)((char*)this + 8) += 1;
    return *(unsigned int*)((char*)this + 8) - 1;
}

struct FUN_007883b0
{
    virtual ~FUN_007883b0();
    virtual void* Write(unsigned int size);
    void ConstructElems(void* data, unsigned int size);
    void RecordRequestedSize(unsigned int requested, unsigned int savedSize);
    void* iSize;
    unsigned int iPosition;
    unsigned int iDataLength;
};

// @fnv 0x007883b0
void FUN_007883b0::RecordRequestedSize(unsigned int requested, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        iSize = Write(requested);
        iDataLength = requested;
    }
    if (savedSize > 0)
    {
        ConstructElems(iSize, savedSize);
        iPosition = savedSize;
    }
}

struct GlobalObject_0045cfe0
{
    int* Int();
};
struct Player
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float v3(int);
};
extern Actor* g_thePlayer;
extern GlobalObject_0045cfe0 g_011d0c60;
void FNV_Warning(int a, const char* format, int b, int c, double d);

// Returns the player's progress fraction between the current and next level XP thresholds, warning if current XP is below the low threshold.
// @fnv 0x0078d5a0
float GetLevelProgress()
{
    if (g_thePlayer->GetLevel() >= *g_011d0c60.Int())
        return 0.0f;

    int lowXP;
    int highXP;
    int level = g_thePlayer->GetLevel();
    lowXP = ActorValueUtility_blk_00780000_od::ConvertActorValue(level);
    highXP = ActorValueUtility_blk_00780000_od::ConvertActorValue(level + 1);
    float currentXP = ((Player*)(char*)g_thePlayer + 0xa4 / 4)->v3(0x18);
    if (currentXP < lowXP)
        FNV_Warning(0x12, "Loading Menu:  Invalid Level Progress Values\n  LowXP=%d, HighXP=%d, CurrXP=%.2f", lowXP,
                    highXP, currentXP);
    return (currentXP - lowXP) / (highXP - lowXP);
}

// Exe 0x007832a0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct BlkOffset08View
{
    unsigned int GetFlags();
};

struct FUN_004bddd0_t : public BlkOffset08View
{
    bool ItemChange_GetWorn(bool a);
};

struct FUN_007832a0_class
{
    void __cdecl InventoryMenu_AddToChangedItemsListIfWorn(FUN_004bddd0_t* a);
};

// @fnv 0x007832a0
// src: COMMUNITY 0x007832a0
void __cdecl FUN_007832a0_class::InventoryMenu_AddToChangedItemsListIfWorn(FUN_004bddd0_t* a)
{
    if (a != 0 && a->ItemChange_GetWorn(false))
    {
        TESBoundObject* flags = reinterpret_cast<TESBoundObject*>(a->GetFlags());
        InventoryMenu::ms_pInventoryMenu->m_kHotkeyObjects.AddHead(flags);
    }
}






extern GO DAT_011da24c;
extern GO g_011da224;
extern int DAT_011da204;

struct FUN_0078e0f0 : Menu
{
    ~FUN_0078e0f0();
};

// @fnv 0x0078e0f0
FUN_0078e0f0::~FUN_0078e0f0()
{
    NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1)
        ->RemoveObject((NiAVObject*)DAT_011da24c.operator unsigned int());

    ((NiNode*)DAT_011da24c.operator unsigned int())->DetachAllChildren();

    DAT_011da24c.operator=(0);
    g_011da224.operator=(0);
    DAT_011da204 = 0;

    NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1)->RemoveAllLights();
}

void* operator new(unsigned int size, void* place);
void operator delete(void* object, void* place);

struct Elem_788
{
    int m_unk00, m_unk04, m_unk08, m_unk0c, m_unk10;
    Elem_788();
};

struct Owner_788
{
    void ConstructElems(Elem_788* pData, unsigned int ItemUpdateArray);
};

// @fnv 0x00788260
void Owner_788::ConstructElems(Elem_788* pData, unsigned int auiCount)
{
    for (unsigned int i = 0; i < auiCount; i++)
    {
        new (&pData[i]) Elem_788;
    }
}

struct IMStub
{
    Tile* GetMenuRoot();
};

struct NodePtr
{
    NodePtr& operator=(void* p);
};

IMStub* GetInterfaceManager();
int GetLoveTesterMenuID();
void FNV_Warning(const char* fmt, ...);
void CloseLoveTester();
void SetLoveTesterEnabled(bool b);

extern LoveTesterMenu* DAT_011da2c8;
extern NodePtr g_011da2f4;

// @fnv 0x007915f0
void __cdecl CreateLoveTesterMenu(int aiValue)
{
    Tile* pTile = GetInterfaceManager()->GetMenuRoot()->ReadFile("Data\\Menus\\CharGen\\love_tester_menu.xml");
    Menu* menu = pTile->GetMenu();
    if (menu && menu->GetClass() == GetLoveTesterMenuID())
    {
        menu->SetTileMenu(reinterpret_cast<TileMenu*>(pTile), false);
        DAT_011da2c8 = (LoveTesterMenu*)menu;
        int missing;
        if (!DAT_011da2c8->InitializeCollection(&missing))
        {
            FNV_Warning("MENUS:  Special book menu creation failed... Missing index = #%d", missing);
            delete pTile;
            CloseLoveTester();
            return;
        }
        DAT_011da2c8->unk58 = aiValue;
        DAT_011da2c8->Setup();
        g_011da2f4 = DAT_011da2c8->GetNode();
        SetLoveTesterEnabled(true);
        menu->SetMenuVisibility(false);
    }
    else if (menu && menu->GetTile())
    {
        delete menu;
    }
}

// @fnv 0x00791740
// src: XBOX_PDB 0x00791740
int LoveTesterMenu_GetClassStatic()
{
    return 0x432;
}


// Sets *index to 0, scans the eight menu tiles and returns false on the first missing tile.
// @fnv 0x00791750
bool LoveTesterMenu::InitializeCollection(int* index)
{
    *index = 0;
    for (; *index < 8; (*index)++)
    {
        if ((&unk28)[*index] == 0)
        {
            return false;
        }
    }
    return true;
}

struct MemberList
{
    int a, b, c;
    MemberList();
    ~MemberList();
};
struct StringMember
{
    int a, b;
    StringMember();
    ~StringMember();
};
struct ViewParam
{
    float a, b, c, d;
    ViewParam(float, float, float, float);
};
struct ItemValue
{
    void* Get();
};
struct ListMember
{
    ItemValue* item;
    ListMember* next;
    ListMember();
    ~ListMember();
    ItemValue** GetItem();
};
struct SmallMember
{
    int a, b, c;
    SmallMember();
    ~SmallMember();
};
struct SmallMember_d00483710 : SmallMember
{
    SmallMember_d00483710()
    {}
    ~SmallMember_d00483710();
};
struct SmartMember
{
    void* ptr;
    SmartMember();
    ~SmartMember();
    SmartMember& operator=(void*);
};
struct Renderer
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void GetView(ViewParam*);
};
Renderer* GetRenderer();
bool extern DAT_011a0294;
void* memset(void*, int, unsigned int);
struct FUN_00788440 : Menu
{
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
    MemberList list0, list1, list2, list3, list4;
    int indices[43];
    StringMember text;
    ViewParam view;
    ListMember items;
    ListMember* current;
    ItemValue* selected;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0;
    SmallMember_d00483710 small0, small1;
    SmartMember nodes[4];
    int unk21c;
    unsigned short unk220, unk222;
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
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    FUN_00788440();
    virtual ~FUN_00788440();
    void SetFlag(int, bool);
    void Apply(void*);
};
// Initializes the view, clears the node and index arrays, queries the renderer view, sets flags, and applies the first item's data.
// @fnv 0x00788440
FUN_00788440::FUN_00788440() : view(0.0f, 0.0f, 0.0f, 0.0f)
{
    memset(&unk028, 0, 0x98);
    unk1e4 = 0;
    unk1e0 = 0;
    unk222 = 0;
    unk220 = 0;
    unk5b8 = 0;
    unk21c = 0;
    for (int nodeIndex = 0; nodeIndex < 4; ++nodeIndex)
        nodes[nodeIndex] = 0;
    unk5bc = 0;
    unk1e8 = 0;
    for (int entryIndex = 0; entryIndex < 43; ++entryIndex)
        indices[entryIndex] = 43;
    GetRenderer()->GetView(&view);
    unk1f0 = 0;
    unk1ec = 0;
    current = &items;
    unk5b4 = 0;
    SetFlag(0, !DAT_011a0294);
    SetFlag(4, true);
    selected = *current->GetItem();
    if (selected)
    {
        void* data = selected->Get();
        if (data)
            Apply(&static_cast<Menu*>(data)->m_iSecondaryValue);
    }
}

// Whether the control is active on any of the four input devices (mouse/keyboard/gamepad order).

class C1540InputManager
{
  public:
    int GetControlState(int iControlSlot, int iControl);
};

class C1540OSGlobals
{
  public:
    C1540InputManager* GetInputManager();
};
extern C1540OSGlobals* g_pkC1540OSGlobals;

class C1540Menu
{
  public:
    bool LockPickMenu_IsTurningLock(int iControl);
};

// Returns true if the input manager reports control state for device 2, 3, 0 or 1 for the given control.
// @fnv 0x00791540
// src: XBOX_PDB 0x00791540
bool C1540Menu::LockPickMenu_IsTurningLock(int iControl)
{
    return g_pkC1540OSGlobals->GetInputManager()->GetControlState(2, iControl) ||
           g_pkC1540OSGlobals->GetInputManager()->GetControlState(3, iControl) ||
           g_pkC1540OSGlobals->GetInputManager()->GetControlState(0, iControl) ||
           g_pkC1540OSGlobals->GetInputManager()->GetControlState(1, iControl);
}

extern int(__stdcall* DAT_00fdf1b0)(void*);

class CriticalSectionEntry
{
  public:
    void NiCriticalSection_TryEnterCriticalSection();
};

// @fnv 0x0078d1d0
// src: COMMUNITY 0x0078d1d0
void CriticalSectionEntry::NiCriticalSection_TryEnterCriticalSection()
{
    DAT_00fdf1b0(this);
}
