// src/fallout/interface/menus/inventorymenu_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESBoundObject). The skeleton of src/fallout/interface/menus/inventorymenu.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "../../../../include/ActorValueOwner.h"
#include "../../../../include/BSSimpleList.h"
#include "../../../../include/BaseProcess.h"
#include "../../../../include/ExtraDataList.h"
#include "../../../../include/FOPipboyManager.h"
#include "../../../../include/GO.h"
#include "../../../../include/HotkeyWheelDisplay.h"
#include "../../../../include/InventoryChanges.h"
#include "../../../../include/InventoryMenu.h"
#include "../../../../include/InventoryMenu__sPageState.h"
#include "../../../../include/InventoryStackRecord.h"
#include "../../../../include/ListBoxBase.h"
#include "../../../../include/ListBox_ItemChange___.h"
#include "../../../../include/Menu.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/Setting.h"
#include "../../../../include/TESFullName.h"
#include "../../../../include/TESObjectARMO.h"
#include "../../../../include/TESObjectWEAP.h"
#include "../../../../include/Tile.h"

// Remaining private declarations; shared classes are included above.

#include <stddef.h>
#define FNV_CTOR_JOIN_(a, b) a##b
#define FNV_CTOR_JOIN(a, b) FNV_CTOR_JOIN_(a, b)
#define FNV_STATIC_ASSERT(c) typedef char FNV_CTOR_JOIN(fnv_layout_check_, __LINE__)[(c) ? 1 : -1]

FNV_STATIC_ASSERT(sizeof(InventoryMenu) == 0x124);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_pTiles) == 0x28);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_iCurrentTab) == 0x84);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kPageStates) == 0x88);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kItemList) == 0xB8);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kMenuData) == 0xE8);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kHotkeyObjects) == 0x11C);

// A normal base cast adds null checks under /Od with this compiler. Derive the
// nonnull subobject address from the shared Actor layout to preserve the calls.
static const size_t kActorValueOwnerOffset = offsetof(Actor, m_pRagdollController)
    - sizeof(CachedValuesOwner) - sizeof(ActorValueOwner);
FNV_STATIC_ASSERT(kActorValueOwnerOffset == 0xA4);

extern PlayerCharacter* g_thePlayer;

extern Setting DAT_011d20c4;
extern Setting DAT_011d396c;

void __cdecl FUN_00780c00(Tile* pTile);

unsigned int __fastcall FUN_0044ddc0(void*);

void __cdecl FUN_007800c0();

extern int DAT_011d9ea4;

extern int DAT_011d9eb8;

void* __cdecl FUN_00a01860(const char* s);
void __cdecl UpdateCurrentValue();

// PlayerCharacter.h does not yet declare the these inventory queries on the approved headers.
struct InventoryPlayerQueries : PlayerCharacter
{
    int FUN_00891d70();
    float FUN_008a0c20();
    bool FUN_00967b70(InventoryStackRecord*);
};

namespace InventorySelection {
struct Item;
struct Form
{
    int FUN_00401170();
    void* GetUnk15C();
    int GetField1BC();
};

struct TileRef
{
    Tile** FUN_0073ac90();
};

struct List
{
    virtual void slot0();
    virtual Tile* Value(int);
    Item* FUN_007a1910();
};

struct Item
{
    Form* FUN_0044ddc0();
    float FUN_004bcdb0(int);
    const char* GetIconFilename(int);
};
struct Camera
{
    void FUN_007f8610(int, float, float, bool);
};
// Exe 0x00780ff0: unit-local Interface view; declarations and layout are preserved.
struct InventorymenuInterfaceView
{
    Camera* FUN_00704370();
};
InventorymenuInterfaceView* FUN_004b7210();
extern Setting DAT_011db2f0, DAT_011db358, DAT_011d3dcc, DAT_011d1f2c, DAT_011d33f0;
extern Setting* DAT_011d5168;
extern int DAT_011d9f34, DAT_011d9ebc;
extern Item* DAT_011d9ea8;
extern InventoryPlayerQueries* DAT_011dea3c;
extern float DAT_0102f0f8, DAT_0101b268, DAT_01050280, DAT_01072e3c, DAT_01073af0, DAT_0104f754;
extern double DAT_01073ae8, DAT_01073ae0;
extern const char DAT_01020764[], DAT_0106eb24[], DAT_01073aac[];
void FUN_00707e30(Item*, Tile*);
const char* GetWeaponSkillIconPath(void*);
int FUN_00406d00(char*, unsigned int, const char*, ...);
int FUN_00408b20(const char*, const char*);
void FUN_00406d30(char*, unsigned int, const char*);
unsigned int FUN_0044a670(const char*);
void* FUN_00479430(Form*);
const char* GetMenuIconName(void*);
void FUN_00406d50(char*, unsigned int, const char*);

}

// @fnv 0x00780ff0
void Menu::UpdateItemDisplay(int action, Tile* changed)
{
    using namespace InventorySelection;
    if (action == 29)
    {
        DAT_011d9ea8 = ((List*)&static_cast<InventoryMenu*>(this)->m_kItemList)->FUN_007a1910();
        if (DAT_011d9ea8)
        {
            int selectedSlot11 = (int)((List*)&static_cast<InventoryMenu*>(this)->m_kItemList)->Value(0xfac)->FUN_00a011b0();
            if (DAT_011d9f34 != selectedSlot11)
            {
                InventorySelection::FUN_004b7210()->FUN_00704370()->FUN_007f8610(
                    0, DAT_011d9f34 < selectedSlot11 ? *DAT_011db2f0.FUN_00403e20() : -*DAT_011db2f0.FUN_00403e20(),
                    *DAT_011db358.FUN_00403e20(), 1);
                DAT_011d9f34 = selectedSlot11;
            }
            float threshold = DAT_0102f0f8;
            if (DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 24)
                threshold = DAT_0101b268;
            if (DAT_011d9ea8->FUN_004bcdb0(1) >= threshold)
                static_cast<InventoryMenu*>(this)->m_pTiles[8]->FUN_00a01350(0xfc4, DAT_011d3dcc.FUN_00403df0(), 1);
            else
                static_cast<InventoryMenu*>(this)->m_pTiles[8]->FUN_00a01350(0xfc4, DAT_011d1f2c.FUN_00403df0(), 1);
            FUN_00707e30(DAT_011d9ea8, static_cast<InventoryMenu*>(this)->m_pTiles[12]);
            static_cast<InventoryMenu*>(this)->m_pTiles[12]->FUN_00700320(0xfa3, 1);
            FUN_00726070()->FUN_00700320(DAT_011d9ebc, InventorySelection::DAT_011dea3c->FUN_00967b70((InventoryStackRecord*)DAT_011d9ea8));
            static_cast<InventoryMenu*>(this)->m_pTiles[11]->FUN_00a01350(0xfcc, DAT_011d9ea8->GetIconFilename(0), 1);
            InventorySelection::Form* ammo = 0;
            if (DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 40)
            {
                ammo = DAT_011d9ea8->FUN_0044ddc0();
                static_cast<InventoryMenu*>(this)->m_pTiles[20]->FUN_00a01350(0xfcc, GetWeaponSkillIconPath(ammo->GetUnk15C()), 1);
                char countText[128];
                FUN_00406d00(countText, 128, DAT_01020764, ammo->GetField1BC());
                if (static_cast<InventoryMenu*>(this)->m_pTiles[22])
                    static_cast<InventoryMenu*>(this)->m_pTiles[22]->FUN_00a01350(0xfc4, countText, 1);
            }
            if (!FUN_00408b20(static_cast<InventoryMenu*>(this)->m_pTiles[11]->FUN_00a011f0(0xfcc), DAT_011d33f0.FUN_00403df0()))
            {
                static_cast<InventoryMenu*>(this)->m_pTiles[11]->FUN_00a012d0(0xfa1, DAT_01050280, 1);
                static_cast<InventoryMenu*>(this)->m_pTiles[11]->FUN_00a012d0(0xfb1, DAT_01072e3c, 1);
                static_cast<InventoryMenu*>(this)->m_pTiles[11]->FUN_00a012d0(0xfb0, DAT_01072e3c, 1);
            }
            else if (DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 41)
            {
                float heightSlot1 = DAT_01073af0;
                float width = DAT_0104f754;
                static_cast<InventoryMenu*>(this)->m_pTiles[11]->FUN_00a012d0(0xfa1, heightSlot1 + DAT_01073ae8, 1);
                static_cast<InventoryMenu*>(this)->m_pTiles[11]->FUN_00a012d0(0xfb1, width + DAT_01073ae0, 1);
                static_cast<InventoryMenu*>(this)->m_pTiles[11]->FUN_00a012d0(0xfb0, width + DAT_01073ae0, 1);
            }
            else
            {
                static_cast<InventoryMenu*>(this)->m_pTiles[11]->FUN_00a012d0(0xfa1, DAT_01050280, 1);
                static_cast<InventoryMenu*>(this)->m_pTiles[11]->FUN_00a012d0(0xfb1, DAT_01072e3c, 1);
                static_cast<InventoryMenu*>(this)->m_pTiles[11]->FUN_00a012d0(0xfb0, DAT_01072e3c, 1);
            }
            static_cast<InventoryMenu*>(this)->m_pTiles[11]->SetChangeFlag(17);
            char path[260];
            FUN_00406d30(path, 260, DAT_0106eb24);
            unsigned int prefixLengthSlot0 = FUN_0044a670(path);
            FUN_00406d50(path, 260, GetMenuIconName(FUN_00479430(DAT_011d9ea8->FUN_0044ddc0())));
            if (FUN_0044a670(path) > prefixLengthSlot0)
            {
                (*((TileRef*)&static_cast<InventoryMenu*>(this)->m_pTiles[5]->m_kChildTileList)->FUN_0073ac90())->FUN_00a01350(0xfcc, path, 1);
                (*((TileRef*)&static_cast<InventoryMenu*>(this)->m_pTiles[5]->m_kChildTileList)->FUN_0073ac90())->FUN_00700320(0xfa3, 1);
            }
            else
                (*((TileRef*)&static_cast<InventoryMenu*>(this)->m_pTiles[5]->m_kChildTileList)->FUN_0073ac90())->FUN_00700320(0xfa3, 0);
            if (!static_cast<InventoryMenu*>(this)->m_kMenuData.GetVisible())
                static_cast<InventoryMenu*>(this)->m_pTiles[11]->FUN_00700320(0xfa3, 1);
            FUN_00781680();
        }
    }
    else if (action == 30)
    {
        ClearActionPointSource();
        static_cast<InventoryMenu*>(this)->m_pTiles[11]->FUN_00a01350(0xfcc, DAT_01073aac, 1);
        if (!static_cast<InventoryMenu*>(this)->m_kMenuData.GetVisible())
            static_cast<InventoryMenu*>(this)->m_pTiles[11]->FUN_00700320(0xfa3, 1);
        static_cast<InventoryMenu*>(this)->m_pTiles[6]->FUN_00a01350(0xfc4, DAT_011d5168->FUN_00403df0(), 1);
        static_cast<InventoryMenu*>(this)->m_pTiles[6]->FUN_00700320(0xfaf, 1);
    }
}

InventoryChanges* __cdecl FUN_004bf220(void*);

void __cdecl UpdateItemLabel(Tile* tile, InventoryStackRecord* item);

// ListBox_ItemChange___.h does not yet declare these list operations or slots.
struct InventoryMenuListOperations : ListBoxBase
{
    virtual void RunSeventhVirtualOperation();
    virtual void q7();
    virtual void q8(int);
    Tile* FUN_0071a320(int, const char*, int, int);
    void FUN_0071a320(void*, const char*, void*, int);
    void FUN_0071a200(void*);
    void UpdateItems();
    void FUN_007314c0(void*, int, int);
    void PopulateInventoryList(void*, int, int, void*, int, int);
    void ApplyFilter(void*);
};

// InventoryChanges.h does not yet declare these menu enumeration operations.
struct InventoryMenuChanges : InventoryChanges
{
    void FindEntriesByType(void*, void*);
    int FindFirstItemOfType(int, int*);
};


// InventoryStackRecord.h does not yet declare this item-modification query.
struct InventoryItemQueries : InventoryStackRecord
{
    unsigned char FUN_004bd820();
};
extern int DAT_011d9ea4;
extern int DAT_011d9eb4;
extern int DAT_011d9eb8;
extern int DAT_011d1020;
extern int DAT_011d3a08;
extern int DAT_011d2a18;
extern int DAT_011d4f60;
extern int DAT_011d35d0;
extern int DAT_011d2eb0;
extern int DAT_011d4378;
extern int DAT_011d25b0;
extern int DAT_011d1e60;
extern int DAT_011d300c;
extern int DAT_011d3b20;
extern int DAT_011c3cb4;
void* __cdecl FUN_00705990();

int __cdecl FUN_00406d90(float);
int __cdecl FUN_00406d00(char*, int, const char*, ...);
int __cdecl FUN_00406d30(char*, unsigned int, const char*);
int __cdecl FUN_00406d50(char*, unsigned int, const char*);
int __cdecl FUN_00408b20(const char*, const char*);
void __cdecl UpdateCurrentValue();
int __cdecl FUN_005e58f0(int, void*, void*, int, float*);
unsigned int __fastcall FUN_0044ddc0(void*);
int __cdecl FUN_004839c0(int);
unsigned int __cdecl FUN_0044a670(const char*);

void __cdecl FUN_007824e0();
void __cdecl FUN_00782620();
static const char kStr_IM_Headline_Title[] = "IM_Headline_Title";
// @fnv 0x00782a90
void FUN_00782a90()
{
    BSSimpleList<void*>* pInventoryChangeNode;
    int el;
    InventoryMenuChanges* ea;
    int df;
    int cn;
    int ck;
    int ca;
    float bn;
    float bl;
    char ba[64];
    int ak;
    if (DAT_011d9ea4 && ((FOPipboyManager*)FUN_00705990())->IsUnk28Set())
    {
        ea = (InventoryMenuChanges*)FUN_004bf220(g_thePlayer);
        ca = FUN_00406d90(reinterpret_cast<ActorValueOwner*>(reinterpret_cast<char*>(g_thePlayer) + kActorValueOwnerOffset)->GetCurrentActorValue((ActorValue::Index)0x12));
        ak = (int)(*((Setting*)&DAT_011d1020)->FUN_00403e20());
        if (ca > ak)
            ca = ak;
        FUN_00406d00(ba, 0x40, "%d", ca);
        ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_pTiles[2]->FUN_00a01350(DAT_011d9eb4, ba, true);
        bl = (float)FUN_00406d90(reinterpret_cast<ActorValueOwner*>(reinterpret_cast<char*>(g_thePlayer) + kActorValueOwnerOffset)->GetCurrentActorValue((ActorValue::Index)0x4c));
        cn = (int)g_thePlayer->GetCurrentAIProcess()->GetActiveWeapon();
        ck = 0;
        if (cn)
            ck = (int)FUN_0044ddc0((void*)cn);
        else
            ck = FUN_004839c0(0x1f4);
        bn = 0.0f;
        FUN_005e58f0(0x38, g_thePlayer, g_thePlayer, ck, &bn);
        FUN_00406d00(ba, 0x40, "%1.1f", (double)(bl + bn));
        ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_pTiles[21]->FUN_00a01350(DAT_011d9eb4, ba, true);
        if (((InventoryPlayerQueries*)g_thePlayer)->FUN_00891d70() > *((Setting*)&DAT_011d3a08)->FUN_0043d4d0())
            FUN_00406d00(ba, 0x40, "%d+", *((Setting*)&DAT_011d3a08)->FUN_0043d4d0());
        else
            FUN_00406d00(ba, 0x40, "%d", ((InventoryPlayerQueries*)g_thePlayer)->FUN_00891d70());
        ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_pTiles[0]->FUN_00a01350(DAT_011d9eb4, ba, true);
        FUN_00406d00(ba, 0x40, "%d/%d", reinterpret_cast<ActorValueOwner*>(reinterpret_cast<char*>(g_thePlayer) + kActorValueOwnerOffset)->GetActorValue((ActorValue::Index)0x2e),
                     (int)(((InventoryPlayerQueries*)g_thePlayer)->FUN_008a0c20()));
        ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_pTiles[3]->FUN_00a01350(DAT_011d9eb4, ba, true);
        FUN_00406d00(ba, 0x40, "%d/%d", reinterpret_cast<ActorValueOwner*>(reinterpret_cast<char*>(g_thePlayer) + kActorValueOwnerOffset)->GetActorValue((ActorValue::Index)0x10),
                     reinterpret_cast<ActorValueOwner*>(reinterpret_cast<char*>(g_thePlayer) + kActorValueOwnerOffset)->GetPermanentActorValue((ActorValue::Index)0x10));
        ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_pTiles[1]->FUN_00a01350(DAT_011d9eb4, ba, true);
        if (FUN_00408b20(((Setting*)&DAT_011c3cb4)->FUN_00403df0(), "ENGLISH"))
        {
            el = (int)FUN_00a01860("_Title");
            ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)
                ->m_pTiles[7]->FUN_00a01350(0xfc4, ((Setting*)&DAT_011d2a18)->FUN_00403df0(), true);
            ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)
                ->m_pTiles[8]->FUN_00a01350(0xfc4, ((Setting*)&DAT_011d4f60)->FUN_00403df0(), true);
            ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)
                ->m_pTiles[9]->FUN_00a01350(0xfc4, ((Setting*)&DAT_011d35d0)->FUN_00403df0(), true);
            ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)
                ->m_pTiles[19]->FUN_00a01350(0xfc4, ((Setting*)&DAT_011d2eb0)->FUN_00403df0(), true);
            ((Menu*)(void*)(unsigned int)DAT_011d9ea4)
                ->FUN_00726070()
                ->GetNamedChild(kStr_IM_Headline_Title)
                ->FUN_00a01350(0xfc4, ((Setting*)&DAT_011d4378)->FUN_00403df0(), true);
            ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_pTiles[2]->FUN_00a01350(el, DAT_011d20c4.FUN_00403df0(), true);
            ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_pTiles[21]->FUN_00a01350(el, DAT_011d396c.FUN_00403df0(), true);
            ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)
                ->m_pTiles[0]->FUN_00a01350(el, ((Setting*)&DAT_011d25b0)->FUN_00403df0(), true);
            ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)
                ->m_pTiles[3]->FUN_00a01350(el, ((Setting*)&DAT_011d1e60)->FUN_00403df0(), true);
            ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)
                ->m_pTiles[1]->FUN_00a01350(el, ((Setting*)&DAT_011d300c)->FUN_00403df0(), true);
        }
        ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_pTiles[5]->FUN_00700320(0xfa3, 0);
        ((Menu*)(void*)(unsigned int)DAT_011d9ea4)->FUN_00726070()->FUN_00700320(DAT_011d9eb8, 0);
        ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->HandleMouseoverTileAlt(0x1d, 0);
        if (((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_kHotkeyObjects.IsEmpty() == 0 && ea)
        {
            UpdateCurrentValue();
            ((InventoryMenuListOperations*)&((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_kItemList)->Highlight(0);
            for (pInventoryChangeNode = (BSSimpleList<void*>*)&((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_kHotkeyObjects;
                 pInventoryChangeNode && pInventoryChangeNode->GetItem();
                 pInventoryChangeNode = pInventoryChangeNode->GetNext())
            {
                {
                    char bo[128];
                    void* bb;
                    int as;
                    BSSimpleList<void*>* am;
                    BSSimpleList<InventoryStackRecord*> ah;
                    ea->FindEntriesByType(pInventoryChangeNode->GetItem(), &ah);
                    ((InventoryMenuListOperations*)&((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_kItemList)->FUN_0071a200(pInventoryChangeNode->GetItem());
                    for (am = (BSSimpleList<void*>*)&ah; am && am->GetItem(); am = am->GetNext())
                    {
                        bb = dynamic_cast<TESFullName*>(
                            (TESBoundObject*)(void*)((InventoryStackRecord*)am->GetItem())->FUN_0044ddc0());
                        as = (int)FUN_0044a670(((TESFullName*)bb)->GetFullName());
                        FUN_00406d30(bo, 0x80, ((TESFullName*)bb)->GetFullName());
                        if (((InventoryItemQueries*)am->GetItem())->FUN_004bd820())
                            FUN_00406d50(bo, 0x80, "+");
                        ((InventoryMenuListOperations*)&((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_kItemList)->FUN_0071a320(am->GetItem(), bo, (void*)&FUN_007824e0, 0);
                    }
                }
            }
            ((InventoryMenuListOperations*)&((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_kItemList)->FUN_007314c0((void*)&UpdateItemLabel, 0, 0x7fffffff);
            ((InventoryMenuListOperations*)&((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_kItemList)->UpdateItems();
            ((InventoryMenuListOperations*)&((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_kItemList)->FUN_007314c0((void*)&FUN_00780c00, -1, 0x7fffffff);
            ((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_kHotkeyObjects.RemoveAll();
        }
        else
        {
            ((InventoryMenuListOperations*)&((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_kItemList)->PopulateInventoryList(g_thePlayer, 0, 0, (void*)&UpdateItemLabel, 0, 0);
            if (ea)
            {
                if (ea->FindFirstItemOfType(0x2e, &df))
                {
                    Tile* tt;
                    tt = ((InventoryMenuListOperations*)&((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_kItemList)->FUN_0071a320(0, ((Setting*)&DAT_011d3b20)->FUN_00403df0(), 0, 0);
                    tt->FUN_00700320(0xfaa, 0x1e);
                }
            }
            ((InventoryMenuListOperations*)&((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_kItemList)->ApplyFilter((void*)&FUN_00782620);
            ((InventoryMenuListOperations*)&((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_kItemList)->FUN_007314c0((void*)&FUN_00780c00, -1, 0x7fffffff);
            ((InventoryMenuListOperations*)&((InventoryMenu*)(void*)(unsigned int)DAT_011d9ea4)->m_kItemList)->q8((int)&FUN_007824e0);
        }
        ((Menu*)DAT_011d9ea4)->ClearActionPointSource();
        FUN_007800c0();
    }
}
