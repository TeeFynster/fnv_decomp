// ExtraObj_listbox: local type (was include/ExtraObj.h, which had no evidence of one real class); its methods are 0x00418770 ExtraDataList::GetCount, 0x00418800 ExtraDataList::GetScript, 0x004459e0 ItemChange::`scalar deleting destructor'
class PkgObj;
class FormObj;

class ExtraObj_listbox
{
public:
    PkgObj* ExtraDataList_GetPackageExtra();
    FormObj* ExtraDataList_GetScript();
    short ExtraDataList_GetCount();
    void* FUN_004459e0(unsigned int flags);
};
#include "../../../include/BSSimpleArray.h"
#include "../../../include/Tile.h"
#include "../../../include/MemoryManager.h"
#include "../../../include/InventoryChanges.h"
#include "../../../include/ListBoxBase.h"
#include "../../../include/SL.h"
#include "../../../include/TESBoundObject.h"
#include "../../../include/TESFullName.h"
#include "../../../include/Menu.h"


// src/fallout/interface/listbox_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout/interface/listbox.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/interface/listbox.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/listbox.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct G2
{
    void AddHead(int**);
};
extern G2 g_011d8b54;
void AddToHeadList(int* arg);
struct GlobalObject_00869f00
{
    void Clear(bool bClear);
};
extern int DAT_010703b4;
struct FUN_00723f30_shell : GlobalObject_00869f00
{
    void SetVtableAndProcessState_00723f30();
};
struct AX
{
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
};
extern int DAT_010703c8;
struct FUN_00723f50_shell : AX
{
    int* vtable;
    AX* InitializeArrayView();
};
void __cdecl _Deallocate(void*);
struct FUN_00724140_shell
{
    void __thiscall FUN_00722880();
    void* __thiscall Destroy(unsigned int flags);
};
struct FUN_007a51c0_shell
{
    void FUN_007a51c0();
};
void _Deallocate(void* p);
struct FUN_007a61f0_shell
{
    void* FUN_007a61f0(unsigned int flags);
};
struct FUN_007a62e0_shell
{
    int a;
    int b;
    char c;
    FUN_007a62e0_shell* __thiscall InitializeFields_007a62e0(int param2, int* param3);
};
struct RecursiveLock;
struct NiAVObject;
struct NiNode;
struct TileShaderProperty;
struct MenuValueDescriptor;
struct BGSSaveLoadFileEntry;
// Exe 0x00a09130: unit-local ListBox view; declarations and layout are preserved.
struct ListboxSelectionCallView
{
    bool SetSelection(Tile* apItem, int apSelect);
    bool SetSelection_Thunk(Tile* apSelectItem);
};
struct FUN_007d8e80_shell
{
    void* FUN_007d8e80(unsigned int flags);
};
void __fastcall FUN_007d6f80(void*);
void __cdecl _Deallocate(void*);
struct FUN_007d8eb0_shell
{
    void __thiscall FUN_007d7d30();
    void* __thiscall FUN_007d8eb0(unsigned int flags);
};
void __cdecl _Deallocate(void*);
struct ListBoxSortList
{
    void __thiscall Sort(int(__cdecl* cmp)(void*, void*));
};
struct FUN_00721410_class
{
    ListBoxSortList list;
    void __thiscall ListBox_enum_ActorValue_Index_Synchronize();
    void __thiscall ListBox_enum_ActorValue_Index_Sort(void* param);
};
extern "C" char str_010703dc[];
struct FUN_00723fa0_shell : AX
{
    int* vtable;
    FUN_00723fa0_shell* __thiscall SetVirtualTableAndProcessState_00723fa0();
};
struct FUN_00723ff0_shell : AX
{
    int* vtable;
    FUN_00723ff0_shell* Constructor();
};
extern int DAT_01070404;
struct FUN_00724070_shell : GlobalObject_00869f00
{
    void SetVtableAndProcessState_00724070();
};
struct FUN_007241d0_shell : FUN_00723f30_shell
{
    void* __thiscall FUN_007241d0(unsigned int flags);
};
struct FUN_00724290_shell
{
    void __thiscall SetVtableAndProcessState_00724070();
    void* __thiscall FUN_00724290(unsigned int flags);
};
struct FUN_007242c0_shell
{
    bool __thiscall ListBox_unsigned_int_GetFlag(unsigned int flags);
};
int GetTileValueID(const char*, int);
extern int DAT_011d8cd8;
extern int DAT_011d8cdc;
void __cdecl ProcessEntries_00724930();
struct FUN_00721bc0_shell
{
    int x;
    void __thiscall SortEntriesAndRefresh(int(__cdecl* param)(void*, void*));
    void __thiscall ProcessEntries_00724930();
};
struct FUN_00723030_Holder
{
    int _p0;
    int _p1;
    int _p2;
    Tile* _t;
    bool IsTileMenu(Menu* p);
};
struct FUN_00725aa0_shell
{
    void __thiscall ProcessSlots();
};
struct FUN_00723310_shell
{
    ListBoxSortList list;
    void __thiscall SortListAndProcessSlots(int(__cdecl* cmp)(void*, void*));
};
struct FUN_00723ac0_shell
{
    void __thiscall ListBox_unsigned_int_Synchronize();
    void __thiscall ListBox_unsigned_int_Sort(void* param);
};
struct FUN_00723f00_shell : AX
{
    int* vtable;
    FUN_00723f00_shell* __thiscall SetVirtualTableAndProcessState_00723f00();
};
struct FUN_00723fd0_shell : GlobalObject_00869f00
{
    void __thiscall UpdateState_00723fd0();
};
struct FUN_00724090_shell
{
    void __thiscall FUN_00721150();
    void* __thiscall FUN_00724090(unsigned int flags);
};
struct FUN_00721920_shell
{
    void __thiscall FUN_00721920();
};
struct FUN_007240e0_shell
{
    void* __thiscall FUN_007240e0(unsigned int flags);
};
struct FUN_00724110_This
{
    void __thiscall FUN_007220d0();
    void* __thiscall FUN_00724110(unsigned int flags);
};
struct S_00724170
{
    void __thiscall FUN_00723070();
    void* __thiscall FUN_00724170(unsigned int flags);
};
struct FUN_007241a0_shell
{
    void __thiscall FUN_00723820();
    void* __thiscall FUN_007241a0(unsigned int flags);
};
struct Helper_00723fd0
{
    void __thiscall UpdateState_00723fd0();
};
struct FUN_00724230_shell
{
    void* __thiscall FUN_00724230(unsigned int flags);
};
struct FUN_00724260_shell
{
    void __thiscall ResetVirtualTableAndClear_00724020();
    void* __thiscall FUN_00724260(unsigned int flags);
};
struct Member_007a8b10
{
    ~Member_007a8b10();
};
struct FUN_007643c0_p07 : Member_007a8b10
{
    Member_007a8b10* __thiscall DestroySelf(unsigned int flags);
};
struct ListBoxSortList;
struct FUN_007a6480_shell
{
    void __thiscall ProcessEntries_007a6480();
};
struct FUN_007a22a0_shell
{
    void __thiscall SortEntriesAndRefresh_007a22a0(int(__cdecl* cmp)(void*, void*));
};
struct FUN_007a30a0_Holder
{
    int* __thiscall FindNodeValue(int, unsigned char);
    int __thiscall ListBox_ItemChange_GetTileAt(int, unsigned char);
};
struct FUN_007a80e0_shell
{
    int* __thiscall InitSceneNodes();
};
struct FUN_007a5700_shell
{
    int* __thiscall SortEntriesAndInitializeSceneNodes(int(__cdecl* cmp)(void*, void*));
};
struct FUN_007a1aa0_shell
{
    void ResetVirtualTableAndClear_007a1aa0();
};
struct FUN_007a6100_shell : FUN_007a1aa0_shell
{
    void* __thiscall FUN_007a6100(unsigned int flags);
};
struct FUN_007a6130_This
{
    void __thiscall FUN_007a1d60();
    void* __thiscall FUN_007a6130(unsigned int flags);
};
struct FUN_007a6190Owner
{
    void __thiscall FUN_007a37b0();
    void* __thiscall FUN_007a6190(unsigned int flags);
};
struct FUN_007a86b0_Item
{
    int a;
    int b;
    void __thiscall FUN_007a86b0(int);
};
struct FUN_007a63b0_holder
{
    void __thiscall BSSimpleArray_BSStringT_char_1024_DestructItems(FUN_007a86b0_Item*, unsigned int);
};
struct FUN_007a63f0_shell
{
    void __thiscall UpdateState_007a63f0(unsigned int requested, unsigned int savedSize);
    void __thiscall ConstructElements(int, unsigned int);
};
struct FUN_007d9000_shell
{
    void __thiscall ApplySelectionAction(int a, int b);
};
struct FUN_007d7a80_shell
{
    void __thiscall ListBox_StartMenu_Option_Select(int a);
};
void __cdecl UpdateSaveLoadList();
struct FUN_007d8420_shell
{
    ListBoxSortList list;
    void __thiscall SortList(int(__cdecl* cmp)(void*, void*));
    void __thiscall UpdateSaveLoadList();
};
struct FUN_007a6fa0_shell
{
    int* __thiscall FindNodeValue(int* a, unsigned char b);
};
struct FUN_007d86c0_shell
{
    int* __thiscall ListBox_BGSSaveLoadFileEntry_GetDataAt(int* apItem, unsigned char apSelect);
};
float __cdecl FUN_004e4430(float);
int __cdecl BSMAX_00647b70(int, int);
int Tile_TextToTrait(const char*);
struct ListBox_71ad30 : ListBoxBase
{
    void* pListItem;
    void* pListNext;
    Tile* m_pListTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;
    void UpdateScrollPages();
};
struct FUN_007d8810_shell
{
    void* m0;
    void* m4;
    void* m8;
    Tile* mC;
    void __thiscall ListBox_BGSSaveLoadFileEntry_SetEnabled(bool abVal);
};
extern int DAT_011d95ac;
extern int DAT_011d95b0;
extern int DAT_011dac94;
extern int DAT_011dac98;
struct FUN_007240c0
{
    int* vptr;
    FUN_007240c0();
};
struct ListBox_SetSelectedTile_shell
{
    void __thiscall SetSelectedTile(Tile* apItem, bool apSelect);
};
extern int DAT_01070220;
extern unsigned int _data_011c16bc;
struct FUN_00721060 : FUN_007240c0
{
    SL sl;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    float m_fFirstListValue;
    float m_fSecondListValue;
    float m_fThirdListValue;
    unsigned short usFlags;

    FUN_00721060();
};
struct TileValue;
Tile* __cdecl FindNamedTile(Tile* tile, const char* name);
extern "C" char str_0106f87c[];
extern "C" char str_0106f884[];
extern "C" char str_0106f88c[];
extern "C" char str_0106f894[];
extern "C" char str_0106f898[];
extern "C" char str_0106f8ac[];
extern "C" char str_0106f8c0[];
struct FUN_00725c20_shell
{
    char padding_000[0x0c];
    Tile* highlightTile;
    Tile* selectedTile;

    void __thiscall UpdateHighlightTiles();
};
struct FUN_007a6bd0_shell
{
    char _base[0x0c];
    Tile* m_pListTile;
    bool __thiscall HasEnabledTrait();
};
struct FUN_007a79b0_shell
{
    char _pad[12];
    Tile* m_pListTile;
    bool __thiscall HasEnabledTrait();
};
struct EntryProperty
{
    int FUN_0044ddc0();
};
struct Entry
{
    int id;
    EntryProperty* property;
};
// Exe 0x00a09130: unit-local ListNode view; declarations and layout are preserved.
struct ListboxListNodeView
{
    Entry* item;
    ListboxListNodeView* next;
    Entry** FUN_006815c0();
    ListboxListNodeView* FUN_00726070();
};
struct TemporaryList : ListboxListNodeView
{
    TemporaryList();
    ~TemporaryList();
    void FUN_005ae3d0(Entry** item);
    void FUN_00470470();
};
struct FunctionOwner
{
    int unk00;
    ListboxListNodeView entries;
    void RemoveTile(int id);
    void ListBox_ItemChange_RemoveItemGroup(int entryType);
};
void __cdecl InterfaceManager_UnregisterListBox(void* p);
struct SubObject_00721150
{
    ~SubObject_00721150();
};
struct FUN_00721150_cls
{
    virtual ~FUN_00721150_cls();
    SubObject_00721150 m_04;

    void __thiscall ListBox_enum_ActorValue_Index_RemoveAll();
};
extern "C" char str_01070244[];
int __cdecl Tile_AddUserTrait(const char*, int);
struct FUN_00721440_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Tile* selected;

    bool __thiscall ListBox_enum_ActorValue_Index_IsEnabled();
    bool __thiscall ContainsKey(Tile* object);
    void __thiscall ListBox_enum_ActorValue_Index_UpdateHighlightBoxPos();
    bool __thiscall SelectObject(Tile* object);
};
extern int DAT_010702ec;
struct FUN_00721850_shell
{
    void __thiscall ListBox_ItemChange_SetFlag(int a, int b);
};
struct FUN_00721850_cls : FUN_007240c0
{
    SL sl;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    float m_fFirstListValue;
    float m_fSecondListValue;
    float m_fThirdListValue;
    unsigned short usFlags;

    FUN_00721850_cls();
};
struct CleanupMember_00721920
{
    ~CleanupMember_00721920();
};
struct FUN_00721920
{
    virtual ~FUN_00721920();
    CleanupMember_00721920 cleanup;
    void __thiscall ReleaseStorage_00721990();
};
void __cdecl InterfaceManager_UnregisterListBox(void* object);
void __cdecl InterfaceManager_UnregisterListBox(void* p);
struct SubObj_007220d0
{
    int unk00;
    ~SubObj_007220d0();
};
class FUN_007220d0_cls
{
  public:
    SubObj_007220d0 m_sub04;

    void Cleanup();
    virtual ~FUN_007220d0_cls();
};
extern bool DAT_011d8909;
struct LBExtraObj
{
    ~LBExtraObj();
};
struct LBItem
{
    Tile* tile;
    LBExtraObj* extra;
};
struct LBNode
{
    LBItem** GetItem();
    void FUN_006ecd40(unsigned int flags);
    ~LBNode();
};
LBNode* __fastcall FUN_00726070(LBNode* node);
struct LBListBox
{
    void* vtbl;
    LBItem* pItem;
    LBNode* pNext;
    Tile* m_pListTile;
    int unk10;
    void ListBox_enum_MiscStatManager_MiscStatID_RemoveAll();
    bool ListBox_unsigned_int_GetFlag(unsigned int flags);
    void ListBox_enum_MiscStatManager_MiscStatID_SetTotalListHeight();
    void ListBox_enum_MiscStatManager_MiscStatID_UpdateHighlightBoxPos();
    int unk14;
    int unk18;
    unsigned short usItemCount;
    float m_fFirstListValue;
};
extern "C" char _DAT_01070244[];
int __cdecl Tile_AddUserTrait(const char*, int);
struct ListBox_7223a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Tile* m_pSelected;
    bool ListBox_enum_MiscStatManager_MiscStatID_IsEnabled();
    bool ContainsKey(Tile*);
    void ListBox_enum_MiscStatManager_MiscStatID_UpdateHighlightBoxPos();
    bool ListBox_enum_MiscStatManager_MiscStatID_Highlight(Tile* apTile);
};
// FUN_007227b0: constructor of a object with a base (vptr), a member sub-object
// with its own ctor/dtor (state -1..0 EH frame), a few int/word/float fields and
// a post-init call on this followed by a cdecl call with this.
struct FUN_007227b0_sub
{
    int unk00;
    int unk04;
    FUN_007227b0_sub();
    ~FUN_007227b0_sub();
};
struct FUN_007227b0_target
{
    void __thiscall ListBox_ItemChange_SetFlag(int, int);
};
struct FUN_007227b0_cls : FUN_007240c0
{
    FUN_007227b0_sub sub;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short w1c;
    float f20;
    float f24;
    float f28;
    unsigned short w2c;

    FUN_007227b0_cls();
};
struct Member_00722880
{
    ~Member_00722880();
};
Member_00722880::~Member_00722880()
{}
struct Helper_007228f0
{
    void __thiscall Call();
};
void Helper_007228f0::Call()
{}
void __cdecl InterfaceManager_UnregisterListBox(void*);
struct FUN_00722880
{
    virtual ~FUN_00722880();
    Member_00722880 member4;
};
struct FUN_0046ffb0
{
    ~FUN_0046ffb0();
};
struct FUN_00723070
{
    virtual ~FUN_00723070();
    FUN_0046ffb0 cleanupMember;
    void ProcessEntries_007230e0();
};
void __cdecl InterfaceManager_UnregisterListBox(FUN_00723070* self);
extern char DAT_0107038c;
struct FUN_00723750 : FUN_007240c0, SL
{
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    short m_1c;
    float m_20;
    float m_24;
    float m_28;
    short m_2c;

    FUN_00723750();
    void ListBox_ItemChange_SetFlag(int a, int b);
};
void __cdecl InterfaceManager_UnregisterListBox(void* p);
class Member_00723820
{
  public:
    ~Member_00723820();
};
class FUN_00723820_cls
{
  public:
    virtual ~FUN_00723820_cls();
    void Reset();
    Member_00723820 m_04;
};
extern "C" const char kListBoxEnabled[];
int __cdecl Tile_AddUserTrait(const char* pcTrait, int iIndex);
class B23AF0ListBox
{
  public:
    bool IsEnabled();
    bool Contains(Tile* pkTile);
    void Refresh();
    bool ListBox_unsigned_int_Highlight(Tile* pkTile);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Tile* m_pkSelected;
};
struct ListItem
{
    int key;
};
struct ListLink
{
    ListItem* item;
    ListLink* next;
    ListItem** FUN_006815c0();
    ListLink* FUN_00726070();
};
struct ListOwner
{
    int unknown00;
    ListLink head;
    bool ContainsKey(int key);
};
struct FUN_00724360_Item
{
    int** FUN_006815c0();
    void* FUN_00726070();
};
struct FUN_00724360_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    unsigned short unk1e;
    float m_20;
    void ListBox_enum_ActorValue_Index_Synchronize();
    void AccumulateTileHeight(int v);
    void ListBox_enum_ActorValue_Index_SetTotalListHeight();
    void ListBox_enum_ActorValue_Index_UpdateHighlightBoxPos();
};
extern "C" char str_01070244[];
int __cdecl Tile_AddUserTrait(const char* name, int value);
struct Owner_00724430
{
    int unk00;
    int unk04;
    int unk08;
    Tile* item;
    bool __thiscall ListBox_enum_ActorValue_Index_IsEnabled();
};
struct Item00724930
{
    Tile* unk00;
    int unk04;
    unsigned char flag08;
};
struct Node00724930
{
    Item00724930** __thiscall FUN_006815c0();
    Node00724930* __thiscall FUN_00726070();
};
struct FUN_00724930_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    unsigned short unk1e;
    float m_20;

    void __thiscall AccumulateTileHeight(Tile* p);
    void __thiscall UpdateState_00724dd0();
    void __thiscall UpdateTraitDisplay();
    void ProcessEntries_00724930();
};
float __cdecl FUN_004e4430(float);
int __cdecl BSMAX_00647b70(int, int);
int Tile_TextToTrait(const char*);
// 0x00726710 counts list entries at +0x04 using a tile at +0x0c; these are list-box scroll fields, not the VATSMenu layout.
struct ScrollPageList
{
    int unk00;
    int unk04;
    int unk08;
    Tile* pScrollTile;
    int unk10;
    Tile* pCountTile;
    int unk18;
    int unk1C;
    float fTotal;
    unsigned int GetUnfilteredRaceCount();
    void UpdateState_00724dd0();
};
struct OwnerProxy
{
    int unk00, unk04, unk08;
    Tile* tile0c;
    int unk10;
    Tile* tile14;
    int unk18, unk1c;
    float range;
    unsigned int ListBox_enum_MiscStatManager_MiscStatID_NumUnfiltered();
    void ListBox_enum_MiscStatManager_MiscStatID_SetTotalListHeight();
};
struct FUN_007255a0_cls
{
    int unk00;
    int unk04;
    int unk08;
    Tile* m_0c;
    unsigned char HasEnabledTrait();
};
int __cdecl Tile_AddUserTrait(const char* name, int len);
extern "C" char str_0106f90c[];
extern "C" char str_0106f8f8[];
struct S725970
{
    int unk00;
    int unk04;
    int unk08;
    Tile* tileA;
    int unk10;
    Tile* tileB;
    int unk18;
    int unk1C;
    float fVal;
    unsigned int GetUnfilteredRaceCount();
    void UpdateState_00725970();
};
extern "C" const char kListBoxEnabled[];
int __cdecl Tile_AddUserTrait(const char* pcTrait, int iIndex);
class B726160Menu
{
  public:
    int unk00;
    int unk04;
    int unk08;
    Tile* m_pkTile;
    bool ListBox_unsigned_int_IsEnabled();
};
struct Parent
{
    void* vptr;
    Parent();
};
struct Section
{
    unsigned int count;
    unsigned int capacity;
    Section();
    ~Section();
};
struct FUN_00730810 : Parent
{
    Section section;
    void* container;
    void* selected;
    void* scrollbar;
    const char* templateName;
    unsigned short nextIndex;
    float totalHeight;
    float lastSelection;
    float lastScrollbar;
    unsigned short flags;
    FUN_00730810();
    void __thiscall ListBox_ItemChange_SetFlag(int, int);
};
extern void* DAT_01070890;
void __cdecl AddToHeadList(FUN_00730810*);
struct FUN_00730e20_inner
{
    bool IsTraitNonZero(void* apKey);
};
struct FUN_00730e20_cls
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00730e20_inner* m_0c;
    bool ListBox_ItemChange_IsEnabled();
};
int __cdecl Tile_AddUserTrait(const char* s, int n);
extern "C" char _DAT_01070244[];
int __cdecl Tile_AddUserTrait(const char*, int);
struct Cls_764e40
{
    int unk00;
    int unk04;
    int unk08;
    Tile* m_pTile0c;
    bool ListBox_int_IsEnabled();
};
struct Item
{
    int* data;
    int key;
};
struct Node
{
    Item** __thiscall FUN_006815c0();
    Node* __thiscall FUN_00726070();
};
struct Owner
{
    int unk00;
    Node head;
    int* __thiscall FindItemData(int* key);
};
extern "C" char str_01070244[];
struct FUN_007a23e0_cls
{
    int unk00[4];
    Tile* m_10;
    bool HasEnabledTrait();
    bool __thiscall ContainsKey(Tile* arg);
    void UpdateHighlightTraits_007a6600();
    bool ListBox_TESQuest_Destroy(Tile* arg);
};
int __cdecl Tile_AddUserTrait(const char* name, int len);
class B7A27F0Base
{
  public:
    B7A27F0Base();
    virtual void VFunc00();
};
class B7A27F0List
{
  public:
    B7A27F0List();
    ~B7A27F0List();

    void* m_pvItem;
    B7A27F0List* m_pkNext;
};
void __cdecl AddToHeadList(void* pvListBox);
class FUN_007a27f0_cls : public B7A27F0Base, public B7A27F0List
{
  public:
    FUN_007a27f0_cls();
    virtual void VFunc00();

    void SetSelectedTile(Tile* pkTile, bool bFlag);

    void* m_pkParentTile;
    void* m_pkScrollBar;
    void* m_pkSelected;
    void* m_pkTemplate;
    short m_sItemCount;
    short unk1E;
    float m_fScrollPos;
    float m_fScrollMax;
    float m_fItemHeight;
    short m_sFlags;
};
extern int DAT_01075594;
struct FUN_007a36e0_m4
{
    int m_00;
    FUN_007a36e0_m4();
    ~FUN_007a36e0_m4();
};
struct FUN_007a36e0_cls : FUN_007240c0
{
    FUN_007a36e0_m4 m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    unsigned short m_1c;
    float m_20;
    float m_24;
    float m_28;
    unsigned short m_2c;

    void ListBox_ItemChange_SetFlag(int a, int b);

    FUN_007a36e0_cls();
};
struct FUN_007a6310_Elem8
{
    int a;
    int b;
    FUN_007a6310_Elem8();
};
void* __cdecl operator new(unsigned int size, void* where);
void __cdecl operator delete(void* p, void* where);
struct FUN_007a6310_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void __thiscall ConstructElements(int arr, unsigned int count);
};
extern "C" char str_01070244[];
int __cdecl Tile_AddUserTrait(const char*, int);
struct FUN_007a6550_shell
{
    int unk00;
    int unk04;
    int unk08;
    Tile* target;

    bool __thiscall HasEnabledTrait();
};
int Tile_AddUserTrait(const char* name, int len);
struct FUN_007a7330_cls
{
    int unk00;
    int unk04;
    int unk08;
    Tile* m_0c;

    unsigned char IsEnabled();
};
struct FUN_007a81b0_cls
{
    int m_00;
    int m_04;
    int m_08;
    Tile* m_0c;
    bool IsEnabled();
};
int __cdecl Tile_AddUserTrait(const char* s, int n);
extern int DAT_01077094;
struct FUN_007240c0_Base
{
    const void* vtbl00;
    FUN_007240c0_Base();
};
struct FUN_0096a2d0_List
{
    int unk00;
    int unk04;
    FUN_0096a2d0_List();
    ~FUN_0096a2d0_List()
    {}
};
void __cdecl AddToHeadList(void* p);
struct FUN_007d7c60 : FUN_007240c0_Base
{
    FUN_0096a2d0_List list04;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    short unk1C;
    float unk20;
    float unk24;
    float unk28;
    short unk2C;
    FUN_007d7c60();
    void ListBox_ItemChange_SetFlag(void* tile, bool flag);
};
struct Member_0046ffb0
{
    ~Member_0046ffb0();
};
Member_0046ffb0::~Member_0046ffb0()
{}
void __cdecl InterfaceManager_UnregisterListBox(void*);
struct FUN_007d7d30
{
    Member_0046ffb0 m;
    void ListBox_BGSSaveLoadFileEntry_RemoveAll();
    virtual ~FUN_007d7d30();
};
void** __fastcall FUN_006815c0(void* node);
void* __fastcall FUN_00726070(void* node);
struct FUN_007d8da0_cls
{
    void ListBox_BGSSaveLoadFileEntry_DeselectAll(bool bFlag);
};
int __cdecl Tile_AddUserTrait(const char*, int);
struct SelectionList
{
    bool ListBox_StartMenu_Option_IsEnabled();
    bool ContainsKey(Tile*);
    bool ApplySelectionAction(Tile* item, int action);
};
extern "C" char str_0106f90c[];
extern "C" char str_0106f8f8[];
struct HeightList
{
    int unk00;
    int unk04;
    int unk08;
    Tile* container;
    int unk10;
    Tile* scrollbar;
    int unk18;
    int unk1c;
    float totalHeight;
    unsigned int __thiscall FUN_007d9ee0();
    void __thiscall ListBox_StartMenu_Option_SetTotalListHeight();
};
float __cdecl FUN_004e4430(float);
int __cdecl BSMAX_00647b70(int, int);
int Tile_TextToTrait(const char*);
struct ListBoxScrollBase
{
    virtual ~ListBoxScrollBase();
};
struct ListBoxScroll : ListBoxScrollBase
{
    void* pListItem;
    void* pListNext;
    Tile* m_pListTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;

    unsigned int GetFilteredItemCount();
    void ListBox_BGSSaveLoadFileEntry_SetTotalListHeight();
};
struct OwnedRecord
{
    ~OwnedRecord();
};
struct OwnedRecordList
{
    OwnedRecord** FUN_006815c0();
    OwnedRecordList* FUN_00726070();
    void FUN_00470470();
    ~OwnedRecordList();
};
struct RecordList
{
    OwnedRecordList* head;
    unsigned int count;
    void BGSSaveLoadManager_FreeSavesList();
};
int __cdecl strcpy_s(char*, unsigned int, const char*);
int __cdecl strcat_s(char*, unsigned int, const char*);
unsigned int __cdecl BSStringLength(const char*);
struct InventoryEntry
{
    TESBoundObject* object;
    int count;
    void* extra;
    InventoryEntry();
    int FUN_00726070();
    TESBoundObject* GetObject();
    bool FUN_004bd820();
    void ItemChange_Copy2(InventoryEntry*);
    void FUN_006ecd40(int);
};
struct InventoryList
{
    ~InventoryList();
};
struct InventoryOwner
{
    void TESObjectREFR_StartInventoryIter(bool, InventoryList**, InventoryChanges**);
};
struct InventoryListBox
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void ClearItems();
    void* item;
    void* next;
    Tile* container;
    Tile* selected;
    Tile* scrollbar;
    const char* templateName;
    void ListBox_ItemChange_SetFlag(int, bool);
    bool ListBox_unsigned_int_GetFlag(unsigned int);
    Tile* ListBox_ItemChange_AddItem(InventoryEntry*, const char*, int, int);
    void UpdateItems();
    void PopulateInventoryList(InventoryOwner*, bool(__cdecl*)(InventoryEntry*), int,
                               void(__cdecl*)(Tile*, InventoryEntry*), bool, bool);
};
struct RemovalItem
{
    Tile* tile;
    LBExtraObj* extra;
    bool counted;
};
struct RemovalNode
{
    RemovalItem* item;
    RemovalNode* next;
    RemovalItem** GetItem();
    RemovalNode* FUN_00726070();
    void FUN_006ecd40(RemovalNode* next);
    ~RemovalNode();
};
struct RemovalHeader
{
    int vtable;
};
struct RemovalList : RemovalHeader, RemovalNode
{
    Tile* container;
    Tile* selected;
    bool ListBox_unsigned_int_GetFlag(unsigned int);
    void UpdateItems();
    bool RemoveNode(RemovalNode* node, RemovalNode* previous);
};
struct RemovalInterface
{
    void InterfaceManager_SetCurrentFocusTarget(Tile*, int, int);
};
RemovalInterface* InterfaceManager_GetSingleton();
extern "C" char str_0106f8d0[];
struct MenuBase_71f700
{
    virtual ~MenuBase_71f700();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};
struct Elem_71f700
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~Elem_71f700();
};
struct List68_71f700
{
    int unk00;
    int unk04;
    int unk08;
    ~List68_71f700();
};
struct Owned_71f700
{
    int unk00;
    ~Owned_71f700();
};
struct Effects_71f700
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
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    ~Effects_71f700();
};
struct ListBoxA_71f700
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
    ~ListBoxA_71f700();
};
struct ListBoxB_71f700
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
    ~ListBoxB_71f700();
};
struct ListBoxC_71f700
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
    ~ListBoxC_71f700();
};
struct ListBoxD_71f700
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
    ~ListBoxD_71f700();
};
struct ListBoxE_71f700
{
    ~ListBoxE_71f700();
};
extern int DAT_011dace0;
void Object_UpdateFields_0071f8c0();
struct FUN_0071f700 : MenuBase_71f700
{
    Elem_71f700 elems[4];
    List68_71f700 list68;
    Owned_71f700* p74;
    Owned_71f700* p78;
    Owned_71f700* p7c;
    Owned_71f700* p80;
    Effects_71f700 effects;
    ListBoxA_71f700 list180;
    ListBoxA_71f700 list1b0;
    ListBoxB_71f700 list1e0;
    ListBoxC_71f700 list210;
    ListBoxD_71f700 list240;
    ListBoxE_71f700 list270;
    virtual ~FUN_0071f700();
};
struct ItemS
{
    Tile* curNode;
    ExtraObj_listbox* extra;
};
struct NodeS
{
    ItemS** FUN_006815c0();
    NodeS* FUN_00726070();
    void FUN_006ecd40(unsigned int flags);
    void* FUN_004702f0(unsigned int flags);
};
struct OwnerS
{
    void* vptr00;
    ItemS* pSingle;
    NodeS* pHead;
    Tile* pTile;
    int m10;
    int m14;
    int m18;
    unsigned short m_usPassCountLocal;
    unsigned short us1e;
    float m_fGlyphExtent;
    bool ListBox_unsigned_int_GetFlag(unsigned int flags);
    void ListBox_enum_ActorValue_Index_SetTotalListHeight();
    void ListBox_enum_ActorValue_Index_UpdateHighlightBoxPos();
    void ListBox_enum_ActorValue_Index_RemoveAll();
};
struct NavigationItem
{
    Tile* tile;
};
struct NavigationNode
{
    NavigationItem* item;
    NavigationNode* next;
    NavigationItem** FUN_006815c0();
    NavigationNode* FUN_00726070();
};
struct NavigationBase
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual Tile* GetAt(int current, bool select);
};
struct NavigationList : NavigationBase, NavigationNode
{
    Tile* container;
    Tile* selected;
    Tile* scrollbar;
    const char* templateName;
    unsigned short count;
    bool ListBox_enum_ActorValue_Index_IsEnabled();
    Tile* ListBox_enum_ActorValue_Index_GetHighlightTarget(unsigned int action);
};
float __cdecl FUN_004bd510(float value, float step);
int __cdecl LBGetTraitID(const char* apName);
struct LBClearList : LBListBox
{
    void UpdateState_00724dd0();
    void UpdateTraitDisplay();
    void ReleaseStorage_00721990();
};
float __cdecl FUN_004bd510(float a, float b);
struct Item_721c60
{
    Tile* tile;
};
struct Node_721c60
{
    Item_721c60* item;
    Node_721c60* next;
    Item_721c60** FUN_006815c0();
    Node_721c60* FUN_00726070();
};
struct Base_721c60
{
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual Tile* VFunc14(int index, bool flag);
};
struct Class_721c60 : Base_721c60, Node_721c60
{
    Tile* m_pScrollBar;
    Tile* m_pSelected;
    int unk14;
    int unk18;
    unsigned short m_usItemCount;

    bool IsScrollBarTraitEnabled();
    Tile* ListBox_PerkRankData_HandleKeyboardInput(int action);
};
extern int DAT_01070314;
struct FUN_00722000 : FUN_007240c0
{
    SL sl;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    float m_fFirstListValue;
    float m_fSecondListValue;
    float m_fThirdListValue;
    unsigned short usFlags;

    void ListBox_ItemChange_SetFlag(int, int);

    FUN_00722000();
};
struct ListBox_007228f0 : LBListBox
{
    void UpdateState_00725970();
    void UpdateSpeechChallengeTrait();
    void ListBox_StatsMenu_StatusEffect_FreeAllTiles();
};
struct ListBoxClear
{
    void* vtable;
    LBItem* pItem;
    LBNode* pNext;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    void* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;

    bool ListBox_unsigned_int_GetFlag(unsigned int flags);
    void UpdateScrollTraits();
    void UpdateHighlightTiles();
    void ProcessEntries_007230e0();
};
float __cdecl FUN_004bd510(float afValue, float afMin);
struct LBKItem
{
    Tile* pTile;
};
struct LBKNode
{
    LBKItem* pItem;
    LBKNode* pNext;
    LBKItem** GetItem();
    LBKNode* GetNext();
};
struct LBKBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual Tile* GetTileByIndex(int aiIndex, int aiUnk);
};
struct LBKListBox : LBKBase, LBKNode
{
    Tile* pParentTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;

    bool IsEnabled();
    Tile* GetTileByKey(int aiKey);
};
float __cdecl FUN_004bd510(float value, float one);
struct ListBoxHelper
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual Tile* GetItemAt(int index, int flag);
    ListboxListNodeView head;
    Tile* m_0c;
    Tile* m_10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    bool ListBox_unsigned_int_IsEnabled();
    Tile* ListBox_unsigned_int_GetHighlightTarget(int code);
};
int __cdecl Tile_AddUserTrait(const char*, int);
extern "C" char str_0106f87c[], str_0106f884[], str_0106f88c[], str_0106f894[], str_0106f898[], str_0106f8ac[],
    str_0106f8c0[];
Tile* __cdecl FindNamedTile(Tile*, const char*);
struct Item724
{
    Tile* m_pkTile;
    int unk04;
    bool m_bHidden;
};
class ItemList724
{
  public:
    Item724** GetItem();
    ItemList724* GetNext();

    Item724* m_pkItem;
    ItemList724* m_pkNext;
};
class MenuBase724
{
  public:
    virtual void vfn00();
};
class ListBox724 : public MenuBase724, public ItemList724
{
  public:
    void AddTile(Tile* pkTile);
    void SortTiles();
    void UpdateScroll();
    void RefreshTiles();

    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_usElementCount;
    unsigned short unk1E;
    float m_fScroll;
};
// Whether the list box tile is enabled (trait id resolved once and cached).
int __cdecl C4FD0TraitNameToID(const char* pcName, int iDefault);
class C4FD0ListBox
{
  public:
    int unk00;
    int unk04;
    int unk08;
    Tile* m_pkTile;

    bool ListBox_enum_MiscStatManager_MiscStatID_IsEnabled();
};
struct FUN_007254d0_t
{
    int unk00;
    int unk04;
    int unk08;
    Tile* container;
    Tile* selected;
    void UpdateSpeechChallengeTrait();
};
struct FUN_00725b70_cls
{
    int m_00;
    int m_04;
    int m_08;
    Tile* m_0c;
    bool IsEnabled();
};
int __cdecl Tile_AddUserTrait(const char* s, int n);
struct VLPoint3
{
    float x;
    float y;
    float z;
};
struct VLListNode;
struct VLTileList
{
    VLListNode* GetHeadPos();
    Tile*& GetNext(VLListNode*& arpPos);
};
struct VLFontManager
{
    static VLFontManager* __cdecl Instance();
    VLPoint3 GetStringDimensions(const char* apText, int aiFont, float afWrapWidth, int aiFlags);
};
int __cdecl VLTraitNameToID(const char* apName, int aiDefault);
int __cdecl VLTraitNameToIDSimple(const char* apName);
struct VLList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float fTotalHeight;

    void AccumulateTileHeight(Tile* apTile);
};
struct Value050
{
    void RemoveFromReactions();
    void Tile_Value_AddRefValueAction(int, Tile*, int);
    void AppendFloatAction(int, float);
    void Tile_Value_SetFloat(int);
};
struct FUN_007a62e0
{
    Tile* tile;
    int data;
    bool flag;
    FUN_007a62e0(Tile*, int*);
};
struct List050
{
    FUN_007a62e0* item;
    List050* next;
    void BSSimpleList_ActiveEffect_Insert(FUN_007a62e0*, int);
    void FUN_00905820(FUN_007a62e0* const&);
};
struct Owner050
{
    int unk00;
    List050 entries;
    Tile* container;
    int unk10;
    int unk14;
    const char* templateName;
    unsigned short count;
    bool ListBox_unsigned_int_GetFlag(unsigned int);
    void ListBox_enum_ActorValue_Index_Synchronize();
    void AccumulateTileHeight(Tile*);
    void ListBox_enum_ActorValue_Index_SetTotalListHeight();
    unsigned int GetRaceCount();
    Tile* AddListEntry(int, const char*, int, const char*);
};
extern "C" char kListBoxNumFiltered[];
struct ItemValue
{
    void RemoveFromReactions();
    void Tile_Value_AddRefValueAction(int, Tile*, int);
    void AppendFloatAction(int, float);
    void Tile_Value_SetFloat(int);
};
struct ItemMenu
{
    Tile* Create(Tile*, const char*, int);
};
struct BoxItem
{
    Tile* tile;
    int data;
    char flag;
    BoxItem(Tile*, int*);
};
struct ItemList
{
    BoxItem* item;
    ItemList* next;
    void InsertSorted(BoxItem*, int(__cdecl*)(BoxItem*, BoxItem*));
    void AppendItem(BoxItem* const&);
};
extern "C" char str_0106f860[];
int Tile_AddUserTrait(const char*, int);
struct IntListBox
{
    int unk00;
    ItemList items;
    Tile* container;
    int unk10;
    int unk14;
    const char* templateName;
    unsigned short nextIndex;
    bool ListBox_unsigned_int_GetFlag(unsigned int);
    void Synchronize();
    void AccumulateTileHeight(Tile*);
    void Update();
    int __thiscall Count();
    Tile* ListBox_int_AddItem(int, const char*, int(__cdecl*)(BoxItem*, BoxItem*), const char*);
};
extern bool DAT_011d8909;
extern "C" char str_0106f8d0[];
int Tile_TextToTrait(const char*);
struct ClearExtra
{
    ~ClearExtra();
};
struct ClearTileExtraPair
{
    Tile* tile;
    ClearExtra* extra;
};
struct ClearNode
{
    ClearTileExtraPair** FUN_006815c0();
    ClearNode* FUN_00726070();
    void FUN_006ecd40(unsigned int);
    ~ClearNode();
};
struct ClearOwner
{
    int unk00;
    ClearTileExtraPair* item;
    ClearNode* next;
    Tile* container;
    int selection;
    int unk14;
    int unk18;
    unsigned short count;
    float height;
    bool ListBox_unsigned_int_GetFlag(unsigned int);
    void ResetScroll();
    void Refresh();
    void ListBox_int_RemoveAll();
};
struct C764930Item
{
    Tile* m_pkTile;
    int unk04;
    bool m_bHidden;
};
class C764930ListNode
{
  public:
    C764930Item*& GetItem();
    C764930ListNode* GetNext();

    C764930Item* m_pkItem;
    C764930ListNode* m_pkNext;
};
class C764930MenuBase
{
  public:
    virtual ~C764930MenuBase();
};
class C764930ListMenu : public C764930MenuBase, public C764930ListNode
{
  public:
    void AddTile(Tile* pkTile);
    void UpdateScrollBar();
    void UpdateSelection();

    void RebuildVisibleTiles();

    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_usNumVisible;
    unsigned short unk1E;
    float m_fScroll;
};
struct Cls_764ef0
{
    int unk00;
    int unk04;
    int unk08;
    Tile* highlightTile;
    Tile* selectedTile;

    void __thiscall UpdateHighlightTile();
};
struct ScrollList
{
    int unk00;
    int unk04;
    int unk08;
    Tile* container;
    int unk10;
    Tile* scrollbar;
    int unk18;
    int unk1c;
    float total;
    unsigned int GetUnfilteredCount();
    void ListBox_int_SetTotalListHeight();
};
class FUN_007a3ac0_ListBox
{
  public:
    void* vtbl;
    LBItem* pItem;
    LBNode* pNext;
    Tile* m_pListTile;
    int unk10;
    int unk14;
    int unk18;
    unsigned short usItemCount;
    float m_fFirstListValue;

    bool ListBox_unsigned_int_GetFlag(unsigned int flags);
    void UpdateScrollTraits_007a7700();
    void UpdateHighlightTraits_007a73e0();
    void ProcessEntries_007a3ac0();
};
struct NavItem
{
    Tile* tile;
};
struct NavNode
{
    NavItem* item;
    NavNode* next;
    NavItem** GetItem();
    NavNode* Next();
};
float RoundStep(float, float step = 1.0f);
int Trait(const char*);
int UserTrait(const char*, int);
struct Navigation
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Tile* At(int, bool);
    NavNode items;
    Tile* container;
    Tile* selected;
    int unk14;
    int unk18;
    unsigned short count;
    bool Active();
    Tile* ProcessEntries_007a4000(int key);
};
struct ListBox_7a6600
{
    int unk00;
    int unk04;
    int unk08;
    Tile* highlightTile;
    Tile* selectedTile;

    void __thiscall UpdateHighlightTraits_007a6600();
};
// Whether the list box tile is enabled (trait id resolved once and cached).
int __cdecl D7580TraitNameToID(const char* pcName, int iDefault);
class D7580ListBox
{
  public:
    int unk00;
    int unk04;
    int unk08;
    Tile* m_pkTile;

    bool ListBox_StartMenu_Option_IsEnabled();
};
extern "C" char str_0106f8d0[];
struct P240Item
{
    Tile* tile;
    void* data;
    bool hidden;
};
struct P240List
{
    P240Item* item;
    P240List* next;
    P240Item** FUN_006815c0();
    P240List* FUN_00726070();
};
struct P240Base
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Tile* v5(int, bool);
};
struct P240Owner : P240Base, P240List
{
    Tile* container;
    Tile* selected;
    Tile* scrollbar;
    const char* templateName;
    unsigned short count;
    float height;
    void AccumulateTileHeight(Tile*);
    void ListBox_BGSSaveLoadFileEntry_SetTotalListHeight();
    Tile* SelectLast();
    void ListBox_BGSSaveLoadFileEntry_UpdateHighlightBoxPos();
    void ApplyFilter(bool(__cdecl* predicate)(void*));
};
// Selects a tile in the list box when the box is active and the tile is null or an enabled member of the list.
int __cdecl C7D8950TraitNameToID(const char* pcName, int iDefault);
class C7D8950ListBox
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Tile* m_pkSelected;

    bool IsActive();
    bool Contains(Tile* pkTile);
    void UpdateSelection();
    bool SetSelectedTileIfEnabled(Tile* pkTile);
};
struct TileValue
{
    void Tile_Value_AddRefValueAction(int index, Tile* tile, int value);
    void Tile_Value_SetFloat(int value);
};
struct ListBoxExt
{
    int unk00;
    int unk04;
    int unk08;
    Tile* tile0c;
    Tile* tile10;

    void UpdateHighlightBox();
};
struct ListBoxX
{
    int unk00;
    int unk04;
    int unk08;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    void ListBox_BGSSaveLoadFileEntry_UpdateHighlightBoxPos();
};
struct ContNode;
bool __fastcall FUN_008256d0(ContNode*);
struct N6815c0
{
    RemovalItem** FUN_006815c0();
};
struct RList71a5 : RemovalList
{
    bool RemoveTile(Tile* tile);
};
struct Item118
{
    Tile* tile;
};
struct Node118
{
    Item118* item;
    Node118* next;
    Item118*& FUN_006815c0();
    Node118* FUN_00726070();
};
float FUN_004bd510(float, float);
int Tile_TextToTrait(const char*);
struct Box118
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual Tile* GetTile(int, int);
    Node118 head;
    Tile* scroll;
    Tile* selected;
    int unk14, unk18;
    unsigned short count, flags;
    bool ListBox_enum_MiscStatManager_MiscStatID_IsEnabled();
    Tile* ListBox_enum_MiscStatManager_MiscStatID_GetHighlightTarget(unsigned int action);
};


extern MemoryManager DAT_011f6238;
class AGListItem
{
  public:
    virtual ~AGListItem();
    int m_iIndex;
    AGListItem* m_pNext;
    AGListItem() : m_iIndex(2000), m_pNext(0)
    {}
    static void* operator new(unsigned int uiSize)
    {
        return DAT_011f6238.Game_DoHeapAlloc(uiSize);
    }
    static void operator delete(void* p);
};
class AGValueItem : public AGListItem
{
  public:
    virtual ~AGValueItem();
    TileValue* m_pIntegerData;
    AGValueItem()
    {}
};
void __cdecl Tile_AddReaction(TileValue* pValue, void* pOwner);
class AGOwner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AGValueItem* m_pHead;
    void Tile_Value_AddRefValueAction(int iIndex, Tile* pTile, int iValue);
};

// @fnv 0x00a09130
// src: COMMUNITY 0x00a09130
void AGOwner::Tile_Value_AddRefValueAction(int iIndex, Tile* pTile, int iValue)
{
    AGValueItem* pLast = m_pHead;
    AGValueItem* pItem = new AGValueItem;
    pItem->m_iIndex = iIndex;
    pItem->m_pIntegerData = (TileValue*)pTile->GetOrCreateTraitValue(iValue);
    if (pLast)
    {
        while (pLast->m_pNext)
            pLast = (AGValueItem*)pLast->m_pNext;
        pLast->m_pNext = pItem;
    }
    else
    {
        m_pHead = pItem;
    }
    Tile_AddReaction(pItem->m_pIntegerData, this);
}
