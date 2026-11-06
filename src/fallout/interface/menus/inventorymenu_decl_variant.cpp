
// src/fallout/interface/menus/inventorymenu_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00782190: the skeleton of src/fallout/interface/menus/inventorymenu.cpp
// with declarations corrected to what the original code does (inventorymenu_decls.h: InventoryMenu += bool FUN_00782190(int input, int unused);; inventorymenu_decls.h: Tile += float FUN_00a011b0(unsigned int id);). Move the function to its real unit once
// that unit declares it this way.

#include "../../../../include/ExtraDataList.h"
#include "../../../../include/GO.h"
#include "../../../../include/Tile.h"
#include "../../../../include/Menu.h"
#include "../../../../include/InventoryMenu.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/Setting.h"
#include "../../../../include/TESObjectWEAP.h"

// Private constructor declarations; field layouts follow the canonical PC headers.

#include <stddef.h>
#include "../../../../include/ActorValueOwner.h"
#include "../../../../include/FOPipboyManager.h"
#include "../../../../include/HotkeyWheelDisplay.h"
#include "../../../../include/InventoryMenu__sPageState.h"
#include "../../../../include/InventoryStackRecord.h"
#include "../../../../include/ListBox_ItemChange___.h"
#include "../../../../include/OSGlobals.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/TESObjectARMO.h"
#include "../../../../include/InterfaceManager.h"
#define FNV_CTOR_JOIN_(a, b) a##b
#define FNV_CTOR_JOIN(a, b) FNV_CTOR_JOIN_(a, b)
#define FNV_STATIC_ASSERT(c) typedef char FNV_CTOR_JOIN(fnv_layout_check_, __LINE__)[(c) ? 1 : -1]
class ListBoxItem_ItemChange___;






FNV_STATIC_ASSERT(sizeof(InventoryMenu) == 0x124);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_pTiles) == 0x28);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_iCurrentTab) == 0x84);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kPageStates) == 0x88);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kItemList) == 0xB8);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kMenuData) == 0xE8);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kHotkeyObjects) == 0x11C);

enum ENUM_FORM_ID;

class InputManager
{
  public:
    int FUN_00a24660(int, int);
    int FUN_00a23a50(int, int);
};
extern OSGlobals* g_osGlobals;
extern PlayerCharacter* g_thePlayer;


extern Setting DAT_011d3810;
extern Setting DAT_011d1e18;
extern bool DAT_011d9f38;
bool FUN_004b71d0();
InterfaceManager* FUN_004b7210();
int Warning(const char*, ...);
extern Setting DAT_011d3258;
extern Setting DAT_011d2acc;
extern Setting DAT_011d40b4;
extern Setting DAT_011d4d50;
extern Setting DAT_011d29b8;
extern Setting DAT_011d29f4;
extern Setting DAT_011d2c7c;
extern Setting DAT_011d412c;
extern Setting DAT_011d330c;
extern Setting DAT_011d20c4;
extern Setting DAT_011d396c;

static const int kGetClassValue = 1002;
// m_pTiles holds kNumTiles (23) entries, so out-of-range tile ids are ignored.
static const int kNumTiles = 23;

void __cdecl FUN_00704390();
struct FUN_00780be0_shell
{
    unsigned char m_0x00;  // +0x00
    unsigned char m_0x01;  // +0x01
    unsigned char m_0x02;  // +0x02
    unsigned char m_0x03;  // +0x03
    unsigned char m_0x04;  // +0x04
    unsigned char m_0x05;  // +0x05
    unsigned char m_0x06;  // +0x06
    unsigned char m_0x07;  // +0x07
    unsigned char m_0x08;  // +0x08
    unsigned char m_0x09;  // +0x09
    unsigned char m_0x0a;  // +0x0a
    unsigned char m_0x0b;  // +0x0b
    unsigned char m_0x0c;  // +0x0c
    unsigned char m_0x0d;  // +0x0d
    unsigned char m_0x0e;  // +0x0e
    unsigned char m_0x0f;  // +0x0f
    unsigned char m_0x10;  // +0x10
    unsigned char m_0x11;  // +0x11
    unsigned char m_0x12;  // +0x12
    unsigned char m_0x13;  // +0x13
    void __thiscall SetByte13(unsigned char value);
};

extern double _gModifierZero;
void __cdecl FUN_00780c00(Tile* pTile);
bool __cdecl _FUN_004b71d0();
int __cdecl FUN_007023c0();

struct ProxyPipboy
{
    void __thiscall SetValue(int, bool);
};
struct ProxyMgr
{
    ProxyPipboy* __thiscall GetPipboyManager();
};
void FUN_00782470(bool a1);
unsigned char FUN_007824b0();
unsigned int __fastcall FUN_0044ddc0(void*);
unsigned char __cdecl IsNotFormType2E(void* a1);
struct FUN_007832e0_class
{
    void FUN_007832e0(float, float);
};

void __cdecl FUN_007800c0();
struct FUN_004bddd0_t
{
    bool __thiscall FUN_004bddd0(bool);
};


extern Setting* DAT_011d5178;
extern Setting g_011d3cdc;
extern Setting g_011d460c;
extern Setting g_011d478c;
struct FUN_007823d0_listbox
{
    virtual void FUN_007823d0_first() = 0;
    virtual int FUN_007823d0_second() = 0;
};


struct Ref006815c0
{
    void* __thiscall _ref_006815c0();
};

struct PlayerCharacterShell
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void v95() = 0;
    virtual void v96() = 0;
    virtual void v97() = 0;
    virtual void v98() = 0;
    virtual void v99() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void v116() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual void v125() = 0;
    virtual void v126() = 0;
    virtual void v127() = 0;
    virtual void v128() = 0;
    virtual void v129() = 0;
    virtual void v130() = 0;
    virtual void v131() = 0;
    virtual void v132() = 0;
    virtual void v133() = 0;
    virtual void v134() = 0;
    virtual void v135() = 0;
    virtual void v136() = 0;
    virtual void v137() = 0;
    virtual void v138() = 0;
    virtual void v139() = 0;
    virtual void v140() = 0;
    virtual void v141() = 0;
    virtual void v142() = 0;
    virtual void v143() = 0;
    virtual void v144() = 0;
    virtual void v145() = 0;
    virtual void v146() = 0;
    virtual void v147() = 0;
    virtual void v148() = 0;
    virtual void v149() = 0;
    virtual void v150() = 0;
    virtual void v151() = 0;
    virtual void v152() = 0;
    virtual void v153() = 0;
    virtual void v154() = 0;
    virtual void v155() = 0;
    virtual void v156() = 0;
    virtual void v157() = 0;
    virtual void v158() = 0;
    virtual void v159() = 0;
    virtual void v160() = 0;
    virtual void v161() = 0;
    virtual void v162() = 0;
    virtual void v163() = 0;
    virtual void v164() = 0;
    virtual void v165() = 0;
    virtual void v166() = 0;
    virtual void v167() = 0;
    virtual void v168() = 0;
    virtual void v169() = 0;
    virtual void v170() = 0;
    virtual void v171() = 0;
    virtual void v172() = 0;
    virtual void v173() = 0;
    virtual void v174() = 0;
    virtual void v175() = 0;
    virtual void v176() = 0;
    virtual void v177() = 0;
    virtual void v178() = 0;
    virtual void v179() = 0;
    virtual void v180() = 0;
    virtual void v181() = 0;
    virtual void v182() = 0;
    virtual void v183() = 0;
    virtual void v184() = 0;
    virtual void v185() = 0;
    virtual void v186() = 0;
    virtual void v187() = 0;
    virtual void v188() = 0;
    virtual void v189() = 0;
    virtual void v190() = 0;
    virtual void v191() = 0;
    virtual void v192() = 0;
    virtual void v193() = 0;
    virtual void v194() = 0;
    virtual void v195() = 0;
    virtual void v196() = 0;
    virtual void v197() = 0;
    virtual void v198() = 0;
    virtual void v199() = 0;
    virtual void v200() = 0;
    virtual void v201() = 0;
    virtual void v202() = 0;
    virtual void v203() = 0;
    virtual void v204() = 0;
    virtual void v205() = 0;
    virtual void v206() = 0;
    virtual void v207() = 0;
    virtual void v208() = 0;
    virtual void v209() = 0;
    virtual void v210() = 0;
    virtual void v211() = 0;
    virtual void v212() = 0;
    virtual void v213() = 0;
    virtual void v214() = 0;
    virtual void v215() = 0;
    virtual void v216() = 0;
    virtual void v217() = 0;
    virtual void v218() = 0;
    virtual void v219() = 0;
    virtual void v220() = 0;
    virtual void v221() = 0;
    virtual void v222() = 0;
    virtual void v223() = 0;
    virtual void v224() = 0;
    virtual void v225() = 0;
    virtual void v226() = 0;
    virtual void v227() = 0;
    virtual void v228() = 0;
    virtual void v229() = 0;
    virtual void v230() = 0;
    virtual void v231() = 0;
    virtual void v232() = 0;
    virtual void v233() = 0;
    virtual void v234() = 0;
    virtual void v235() = 0;
    virtual void v236() = 0;
    virtual void v237() = 0;
    virtual void v238() = 0;
    virtual void v239() = 0;
    virtual void v240() = 0;
    virtual void v241() = 0;
    virtual void v242() = 0;
    virtual void DropInventoryObject(TESBoundObject*, ExtraDataList*, int, NiPoint3*, bool) = 0;
    void __thiscall FUN_009614b0(TESBoundObject*, NiPoint3*, int, int);
};
extern PlayerCharacterShell* _g_thePlayer;
extern int _NiPoint3_ZERO;
extern int _DAT_011f4270;
extern int _DAT_011f4274;
void __cdecl DropInventoryItem(int aiAmountChosen);




extern int DAT_011d9ea4;

extern int DAT_011d9eb8;

class FUN_0077ffd0_list
{
  public:
    void* FUN_00825c00(void*);
};
class FUN_0077ffd0_lbx
{
  public:
    virtual void vfn_00();
    virtual Tile* vfn_04(int);
};
void* __cdecl FUN_00a01860(const char* s);
int __cdecl FUN_00ec62c0();
void __cdecl UpdateCurrentValue();
struct InputInterface
{
    virtual int Reserved0();
    virtual int Reserved1();
    virtual int GetFirstValue(int index);
    virtual int Reserved3();
    virtual int Reserved4();
    virtual int Reserved5();
    virtual int Reserved6();
    virtual int GetSecondValue(int index);
};
extern char* DAT_011dea3c;
bool __cdecl FUN_00780f70();
namespace InventorySelection {
struct Item;
struct Form;
struct TileRef
{
    Tile** FUN_0073ac90();
};
struct TileHolder
{
    unsigned int unk0;
    TileRef tile;
};
struct List
{
    virtual void slot0();
    virtual Tile* Value(int);
    Item* FUN_007a1910();
};
struct Entry
{
    bool FUN_00701740();
};
struct Form
{
    int FUN_00401170();
    void* GetUnk15C();
    int GetField1BC();
};
struct Item
{
    Form* FUN_0044ddc0();
    float FUN_004bcdb0(int);
    const char* GetIconFilename(int);
};
struct Player
{
    bool FUN_00967b70(Item*);
};

struct Camera
{
    void FUN_007f8610(int, float, float, bool);
};
// Exe 0x00780ff0: unit-local InventorymenuInterfaceView view used by this matched implementation.
struct InventorymenuInterfaceView
{
    Camera* FUN_00704370();
};
InventorymenuInterfaceView* FUN_004b7210();
extern Setting DAT_011db2f0, DAT_011db358, DAT_011d3dcc, DAT_011d1f2c, DAT_011d33f0;
extern Setting* DAT_011d5168;
extern int DAT_011d9f34, DAT_011d9ebc;
extern Item* DAT_011d9ea8;
extern Player* DAT_011dea3c;
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
} // namespace InventorySelection

// @fnv 0x00780ff0
void InventoryMenu::UpdateItemDisplay(int action, Tile* changed)
{
    if (action == 29)
    {
        InventorySelection::DAT_011d9ea8 = reinterpret_cast<InventorySelection::List&>(m_kItemList).FUN_007a1910();
        if (InventorySelection::DAT_011d9ea8)
        {
            int selectedSlot11 = (int)reinterpret_cast<InventorySelection::List&>(m_kItemList).Value(0xfac)->FUN_00a011b0();
            if (InventorySelection::DAT_011d9f34 != selectedSlot11)
            {
                InventorySelection::FUN_004b7210()->FUN_00704370()->FUN_007f8610(
                    0, InventorySelection::DAT_011d9f34 < selectedSlot11 ? *InventorySelection::DAT_011db2f0.FUN_00403e20() : -*InventorySelection::DAT_011db2f0.FUN_00403e20(),
                    *InventorySelection::DAT_011db358.FUN_00403e20(), 1);
                InventorySelection::DAT_011d9f34 = selectedSlot11;
            }
            float threshold = InventorySelection::DAT_0102f0f8;
            if (InventorySelection::DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 24)
                threshold = InventorySelection::DAT_0101b268;
            if (InventorySelection::DAT_011d9ea8->FUN_004bcdb0(1) >= threshold)
                m_pTiles[8]->FUN_00a01350(0xfc4, InventorySelection::DAT_011d3dcc.FUN_00403df0(), 1);
            else
                m_pTiles[8]->FUN_00a01350(0xfc4, InventorySelection::DAT_011d1f2c.FUN_00403df0(), 1);
            InventorySelection::FUN_00707e30(InventorySelection::DAT_011d9ea8, m_pTiles[12]);
            m_pTiles[12]->FUN_00700320(0xfa3, true);
            FUN_00726070()->FUN_00700320(InventorySelection::DAT_011d9ebc, InventorySelection::DAT_011dea3c->FUN_00967b70(InventorySelection::DAT_011d9ea8));
            m_pTiles[11]->FUN_00a01350(0xfcc, InventorySelection::DAT_011d9ea8->GetIconFilename(0), 1);
            InventorySelection::Form* ammo = 0;
            if (InventorySelection::DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 40)
            {
                ammo = InventorySelection::DAT_011d9ea8->FUN_0044ddc0();
                m_pTiles[20]->FUN_00a01350(0xfcc, InventorySelection::GetWeaponSkillIconPath(ammo->GetUnk15C()), 1);
                char countText[128];
                InventorySelection::FUN_00406d00(countText, 128, InventorySelection::DAT_01020764, ammo->GetField1BC());
                if (m_pTiles[22])
                    m_pTiles[22]->FUN_00a01350(0xfc4, countText, 1);
            }
            if (!InventorySelection::FUN_00408b20(m_pTiles[11]->FUN_00a011f0(0xfcc), InventorySelection::DAT_011d33f0.FUN_00403df0()))
            {
                m_pTiles[11]->FUN_00a012d0(0xfa1, InventorySelection::DAT_01050280, 1);
                m_pTiles[11]->FUN_00a012d0(0xfb1, InventorySelection::DAT_01072e3c, 1);
                m_pTiles[11]->FUN_00a012d0(0xfb0, InventorySelection::DAT_01072e3c, 1);
            }
            else if (InventorySelection::DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 41)
            {
                float heightSlot1 = InventorySelection::DAT_01073af0;
                float width = InventorySelection::DAT_0104f754;
                m_pTiles[11]->FUN_00a012d0(0xfa1, heightSlot1 + InventorySelection::DAT_01073ae8, 1);
                m_pTiles[11]->FUN_00a012d0(0xfb1, width + InventorySelection::DAT_01073ae0, 1);
                m_pTiles[11]->FUN_00a012d0(0xfb0, width + InventorySelection::DAT_01073ae0, 1);
            }
            else
            {
                m_pTiles[11]->FUN_00a012d0(0xfa1, InventorySelection::DAT_01050280, 1);
                m_pTiles[11]->FUN_00a012d0(0xfb1, InventorySelection::DAT_01072e3c, 1);
                m_pTiles[11]->FUN_00a012d0(0xfb0, InventorySelection::DAT_01072e3c, 1);
            }
            m_pTiles[11]->SetChangeFlag(17);
            char path[260];
            InventorySelection::FUN_00406d30(path, 260, InventorySelection::DAT_0106eb24);
            unsigned int prefixLengthSlot0 = InventorySelection::FUN_0044a670(path);
            InventorySelection::FUN_00406d50(path, 260, InventorySelection::GetMenuIconName(InventorySelection::FUN_00479430(InventorySelection::DAT_011d9ea8->FUN_0044ddc0())));
            if (InventorySelection::FUN_0044a670(path) > prefixLengthSlot0)
            {
                (*reinterpret_cast<InventorySelection::TileHolder*>(m_pTiles[5])->tile.FUN_0073ac90())->FUN_00a01350(0xfcc, path, 1);
                (*reinterpret_cast<InventorySelection::TileHolder*>(m_pTiles[5])->tile.FUN_0073ac90())->FUN_00700320(0xfa3, true);
            }
            else
                (*reinterpret_cast<InventorySelection::TileHolder*>(m_pTiles[5])->tile.FUN_0073ac90())->FUN_00700320(0xfa3, false);
            if (!reinterpret_cast<InventorySelection::Entry&>(m_kMenuData).FUN_00701740())
                m_pTiles[11]->FUN_00700320(0xfa3, true);
            FUN_00781680();
        }
    }
    else if (action == 30)
    {
        ClearActionPointSource();
        m_pTiles[11]->FUN_00a01350(0xfcc, InventorySelection::DAT_01073aac, 1);
        if (!reinterpret_cast<InventorySelection::Entry&>(m_kMenuData).FUN_00701740())
            m_pTiles[11]->FUN_00700320(0xfa3, true);
        m_pTiles[6]->FUN_00a01350(0xfc4, InventorySelection::DAT_011d5168->FUN_00403df0(), 1);
        m_pTiles[6]->FUN_00700320(0xfaf, true);
    }
}

struct Form
{
    int FUN_00401170();
};
struct Extra
{
    bool FUN_00418ba0();
};
struct ExtraNode
{
    Extra** FUN_006815c0();
};
struct Entry
{
    ~Entry();
    Form* FUN_0044ddc0();
    float FUN_004bcdb0(bool);
    int FUN_00726070();
    ExtraNode* FUN_00559450();
    bool FUN_004bddd0(bool);
    void* FUN_004459e0(int);
};
struct EntryListNode
{
    Entry* item;
    EntryListNode* next;
    EntryListNode();
    ~EntryListNode();
    Entry** FUN_006815c0();
    EntryListNode* FUN_00726070();
    void FUN_0063f7b0();
};
struct Changes
{
    void FilterInventoryChanges(Form*, EntryListNode*);
};
Changes* __cdecl FUN_004bf220(void*);
extern void* player;
float __cdecl FUN_00476b20(float);
struct InventoryCheck
{
    bool FUN_00781860(Entry* entry);
};
struct ItemLabelSource : InventoryStackRecord
{
    int FUN_00726070();
    unsigned char FUN_004bd820();
    const char* GetTargetFullName();
    bool FUN_004bddd0(bool);
};

struct ItemLabelPlayer
{
    bool FUN_00967b70(InventoryStackRecord*);
    TESObjectWEAP* FUN_008a1710();
};
struct ItemLabelChildren
{
    Tile** FUN_007b5370();
    void* FUN_00559450();
    Tile** AddEight(void*);
};
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
void __cdecl UpdateItemLabel(Tile* tile, ItemLabelSource* item);
// 0x00780d60  unit_65921382d98c.cpp  /MT /Od /Oy- /GS /EHsc /Gy
// thiscall, no stack args (ret): menu refresh/close path.
extern "C" void* DAT_011d9ea8;
extern "C" int DAT_011d9ebc;
void* __fastcall FUN_00559450(void* obj);
void __cdecl FUN_00782a90();
void __cdecl FUN_007832a0(void* tile, int index);
struct Sh006815c0
{
    void** FUN_006815c0();
};
struct Sh00726070
{
    void* FUN_00726070();
};
struct Sh007314c0
{
    char pad[0x64];
    void FUN_007314c0(void (*fn)(void*, int), int a, int b);
};
struct Sh005ae3d0
{
    void FUN_005ae3d0(void** pp);
};
struct Sh004bddd0
{
    bool FUN_004bddd0(bool arg);
};
struct Sh0088c650
{
    void EquipItem(void* a, int b, void* c, bool d, bool e, bool f);
};
struct Sh0088c790
{
    void UnequipItem(void* a, int b, void* c, bool d, bool e, bool f);
};
unsigned __cdecl FUN_0058db10(int arg);
unsigned __cdecl FUN_004839c0(int arg);

extern "C" Setting DAT_011d2af0;
struct GpEmb75
{
    virtual int v0();
    virtual int v1();
    virtual int v2(int arg);
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7(int arg);
};
struct Gp75
{
    char pad00[0xa4];
    GpEmb75 emb;
};


bool FUN_00702450(int);
FOPipboyManager* FUN_00705990();
bool FUN_00709d40();
bool FUN_00702140();
void FUN_00717280(int);
void ShowStatsMenu(int, int);
void UpdatePipboyMapVisibility(int, int);

// @fnv 0x00782190
bool InventoryMenu::FUN_00782190(int input, int unused)
{
    if (!FUN_00702450(1002) || !FUN_00705990()->IsUnk28Set())
        return false;
    bool consumed = false;
    if (FUN_00709d40() && m_kMenuData.GetVisible())
    {
        switch (input)
        {
        case 1:
        case 2:
        case 3:
        case 4:
            if (FUN_00702140())
                consumed = true;
            break;
        }
    }
    if (!consumed && FUN_00702450(1002))
    {
        switch (input)
        {
        case 13:
            FUN_00717280(36);
            ShowStatsMenu(1, 0);
            consumed = true;
            break;
        case 14:
            FUN_00717280(36);
            UpdatePipboyMapVisibility(1, 0);
            consumed = true;
            break;
        case 15:
            HandleSelection(19, 0);
            consumed = true;
            break;
        case 16:
            if (m_pTiles[9]->FUN_00a011b0(0xfafu) != 0.0)
            {
                m_kMenuData.SetVisible(true);
                m_pTiles[11]->Set(0xfa3, 0);
            }
            consumed = true;
            break;
        case 3:
        case 4: {
            int tab = m_iCurrentTab;
            bool visible = m_kMenuData.GetVisible();
            HandleMouseoverTileAlt(29, 0);
            tab += input == 4 ? -1 : 1;
            tab = tab > 4 ? 0 : tab;
            tab = tab < 0 ? 4 : tab;
            HandleSelection(tab + 24, 0);
            if (visible)
                m_kMenuData.SetVisible(true);
            consumed = true;
        }
        break;
        }
    }
    return consumed;
}
