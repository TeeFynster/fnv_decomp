// HighlightValue_listbox: local type (was include/HighlightValue.h, which had no evidence of one real class); its methods are 0x00a09130 Tile::Value::AddRefValueAction, 0x00a09410 Tile::Value::SetFloat
#include "../../../include/Tile.h"
#include "../../../include/BSSimpleArray.h"

class HighlightValue_listbox
{
public:
    void Tile_Value_AddRefValueAction(int trait, Tile* tile, int sourceTrait);
    void Tile_Value_AddRefValueAction(int trait, void* source, int sourceTrait);
    void Tile_Value_SetFloat(int value);
};
// HighlightTile_listbox: local type (was include/HighlightTile.h, which had no evidence of one real class); its methods are 0x00700320 Tile::Set, 0x0071aa60 Tile::SetSpeechChallengeFailure, 0x0071aa80 Tile::ShouldPaintRed, 0x00a00f30 Tile::GetValue

class HighlightTile_listbox
{
public:
    HighlightTile_listbox* Tile_GetChildByName(const char* name);
    void SetSpeechChallengeFailure_0071aa60(bool value);
    void Tile_SetChangeFlag(int flags);
    bool GetSpeechChallengeFailure();
    float FUN_00a011b0(int trait);
    void Tile_Set(int trait, float value, bool propagate);
    void SetTraitAndReset(int trait, float value);
    HighlightValue_listbox* Tile_GetValue(int property);
    bool FUN_0071aa80();
    HighlightTile_listbox* GetValue(int trait);
    void Link(int trait, HighlightTile_listbox* tile, int sourceTrait);
    void Update(int trait);
    HighlightTile_listbox* Child(const char* name);
    void SetQuestCompleted(bool value);
    void Refresh(int flags);
    void SetInt(int trait, int value);
};
// HighlightList_listbox: local type (was include/HighlightList.h, which had no evidence of one real class); its methods are 0x007244e0 ListBox<enum ActorValue::Index>::UpdateHighlightBoxPos, 0x00725080 ListBox<enum MiscStatManager::MiscStatID>::UpdateHighlightBoxPos, 0x0075abd0 ListBox<TERMINAL_MENU_ITEM *>::UpdateHighlightBoxPos, 0x007a5e70 ListBox<ItemChange *>::ScrollToHighlight
class Tile;

class HighlightList_listbox
{
public:
    int unk00;
    int unk04;
    int unk08;
    Tile* container;
    Tile* selected;

    void ListBox_enum_ActorValue_Index_UpdateHighlightBoxPos();
    void ListBox_enum_MiscStatManager_MiscStatID_UpdateHighlightBoxPos();
    void ListBox_ItemChange_ScrollToHighlight();
    void UpdateHighlightTraits_007a73e0();
    __declspec(dllexport) void UpdateHighlight();
    void UpdateState_0072c2b0();
};
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
#include "../../../include/Menu.h"
#include "../../../include/VATSMenu.h"
#include "../../../include/Tile.h"
#include "../../../include/InventoryChanges.h"
#include "../../../include/InventoryStackRecord.h"
#include "../../../include/SL.h"
#include "../../../include/TESBoundObject.h"
#include "../../../include/ListBoxBase.h"
#include "../../../include/TESFullName.h"

// The Windows headers pulled in by Tile must not rename the game accessor.
#ifdef GetObject
#undef GetObject
#endif

// src/fallout/interface/listbox.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/listbox.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct G2
{
    void AddHead(int**);
};

extern G2 g_011d8b54;

// @fnv 0x00721130
void AddToHeadList(int* arg)
{
    g_011d8b54.AddHead(&arg);
}

namespace fnv_007211c0 {
struct DummyNode
{
    void Remove(int** pp) const;
};
DummyNode g_011d8b54;

// @fnv 0x007211c0
// src: XBOX_PDB 0x007211c0
void InterfaceManager_UnregisterListBox(int* p)
{
    g_011d8b54.Remove(&p);
}
}  // namespace fnv_007211c0

struct GlobalObject_00869f00
{
    void Clear(bool bClear);
};

extern int DAT_010703b4;

struct FUN_00723f30_shell : GlobalObject_00869f00
{
    void SetVtableAndProcessState_00723f30();
};

// @fnv 0x00723f30
// src: GUESS 0x00723f30 (confidence: low)
void FUN_00723f30_shell::SetVtableAndProcessState_00723f30()
{
    *(int*)this = (int)&DAT_010703b4;
    Clear(true);
}

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

// Sets the vtable pointer and calls FUN_006b3eb0 with 0, 0, then returns this.
// @fnv 0x00723f50
// src: GUESS 0x00723f50 (confidence: medium)
AX* FUN_00723f50_shell::InitializeArrayView()
{
    vtable = &DAT_010703c8;
    reinterpret_cast<AX*>(this)->BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}

namespace fnv_00723f80 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};

extern int DAT_010703c8;

struct FUN_00723f80_shell
{
    void DoNothing_00723f80();
};

// @fnv 0x00723f80
// src: GUESS 0x00723f80 (confidence: high)
void FUN_00723f80_shell::DoNothing_00723f80()
{
    *(void**)this = (void*)&DAT_010703c8;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_00723f80

namespace fnv_00724020 {
struct GlobalObject_00869f00
{
    char* m_str;
    void Clear(bool);
    void ResetVirtualTableAndClear_00724020();
};

// @fnv 0x00724020
// src: GUESS 0x00724020 (confidence: medium)
void GlobalObject_00869f00::ResetVirtualTableAndClear_00724020()
{
    m_str = "`Br";
    Clear(true);
}
}  // namespace fnv_00724020

namespace fnv_00724040 {
struct AX
{
    virtual ~AX();
    void __thiscall BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
    AX* __thiscall InitializeFields_00724040();
};
extern unsigned int DAT_01070404;

// Sets the object's vtable pointer to DAT_01070404, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00724040
// src: GUESS 0x00724040 (confidence: low)
AX* AX::InitializeFields_00724040()
{
    *reinterpret_cast<unsigned int*>(this) = reinterpret_cast<unsigned int>(&DAT_01070404);
    BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}
}  // namespace fnv_00724040

void __cdecl _Deallocate(void*);

struct FUN_00724140_shell
{
    void __thiscall FUN_00722880();
    void* __thiscall Destroy(unsigned int flags);
};

// Calls FUN_00722880, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00724140
void* __thiscall FUN_00724140_shell::Destroy(unsigned int flags)
{
    FUN_00722880();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_007a51c0_shell
{
    void FUN_007a51c0();
};

void _Deallocate(void* p);

struct FUN_007a61f0_shell
{
    void* FUN_007a61f0(unsigned int flags);
};

// Calls FUN_007a51c0 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x007a61f0
void* FUN_007a61f0_shell::FUN_007a61f0(unsigned int flags)
{
    ((FUN_007a51c0_shell*)this)->FUN_007a51c0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_007a62e0_shell
{
    int a;
    int b;
    char c;
    FUN_007a62e0_shell* __thiscall InitializeFields_007a62e0(int param2, int* param3);
};

// Stores param2 in a, the first int pointed to by param3 in b, sets c to 0, and returns this.
// @fnv 0x007a62e0
// src: GUESS 0x007a62e0 (confidence: low)
FUN_007a62e0_shell* __thiscall FUN_007a62e0_shell::InitializeFields_007a62e0(int param2, int* pSource)
{
    a = param2;
    b = *pSource;
    c = 0;
    return this;
}



// Exe 0x007d8d80: unit-local ListBox view; declarations and layout are preserved.
struct ListboxSelectionCallView
{
    bool SetSelection(Tile* apItem, int apSelect);
    bool SetSelection_Thunk(Tile* apSelectItem);
};

// @fnv 0x007d8d80
// src: GUESS 0x007d8d80 (confidence: medium)
bool ListboxSelectionCallView::SetSelection_Thunk(Tile* apSelectItem)
{
    return SetSelection(apSelectItem, 1);
}

struct FUN_007d8e80_shell
{
    void* FUN_007d8e80(unsigned int flags);
};

void __fastcall FUN_007d6f80(void*);
void __cdecl _Deallocate(void*);

// Calls FUN_007d6f80 on this, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x007d8e80
void* FUN_007d8e80_shell::FUN_007d8e80(unsigned int flags)
{
    FUN_007d6f80(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_007d8eb0_shell
{
    void __thiscall FUN_007d7d30();
    void* __thiscall FUN_007d8eb0(unsigned int flags);
};

void __cdecl _Deallocate(void*);

// @fnv 0x007d8eb0
void* FUN_007d8eb0_shell::FUN_007d8eb0(unsigned int flags)
{
    FUN_007d7d30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

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

// Sorts the list at offset 4 using the given comparator, then calls FUN_00724360.
// @fnv 0x00721410
// src: XBOX_PDB 0x00721410
void FUN_00721410_class::ListBox_enum_ActorValue_Index_Sort(void* pComparator)
{
    reinterpret_cast<ListBoxSortList*>(reinterpret_cast<char*>(this) + 4)->Sort((int(__cdecl*)(void*, void*))pComparator);
    ListBox_enum_ActorValue_Index_Synchronize();
}

namespace fnv_00722370 {
struct ListBoxSortList
{
    void __thiscall Sort(int(__cdecl* compare)(void*, void*));
};

struct FUN_00724f00_shell
{
    void __thiscall RefreshTiles();
};

struct FUN_00722370_shell
{
    ListBoxSortList m_kNode;
    void __thiscall ListBox_enum_MiscStatManager_MiscStatID_Sort(int* pParam);
};

// Sorts the ListBoxSortList at offset 4 using the given compare function, then calls RefreshTiles on this object.
// @fnv 0x00722370
// src: XBOX_PDB 0x00722370
void __thiscall FUN_00722370_shell::ListBox_enum_MiscStatManager_MiscStatID_Sort(int* pCompare)
{
    reinterpret_cast<ListBoxSortList*>(reinterpret_cast<char*>(this) + 4)
        ->Sort(reinterpret_cast<int(__cdecl*)(void*, void*)>(pCompare));
    reinterpret_cast<FUN_00724f00_shell*>(this)->RefreshTiles();
}
}  // namespace fnv_00722370

namespace fnv_00722b20 {
struct ListBoxSortList
{
    void __thiscall Sort(int(__cdecl* fp)(void*, void*));
};
struct FUN_007254d0_t
{
    void __thiscall ListBox_StatsMenu_StatusEffect_Synchronize();
};

struct FUN_00722b20_shell
{
    void* m_auiShapeKeys;
    ListBoxSortList m_kNode;
    void __thiscall ListBox_StatsMenu_StatusEffect_Sort(int(__cdecl* fp)(void*, void*));
};

// Sorts the list using the given comparison function, then calls FUN_007254d0 on this object.
// @fnv 0x00722b20
// src: COMMUNITY 0x00722b20
void __thiscall FUN_00722b20_shell::ListBox_StatsMenu_StatusEffect_Sort(int(__cdecl* fp)(void*, void*))
{
    m_kNode.Sort(fp);
    reinterpret_cast<FUN_007254d0_t*>(this)->ListBox_StatsMenu_StatusEffect_Synchronize();
}
}  // namespace fnv_00722b20

extern "C" char str_010703dc[];

struct FUN_00723fa0_shell : AX
{
    int* vtable;
    FUN_00723fa0_shell* __thiscall SetVirtualTableAndProcessState_00723fa0();
};

// Sets the vtable pointer to str_010703dc, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00723fa0
// src: GUESS 0x00723fa0 (confidence: low)
FUN_00723fa0_shell* __thiscall FUN_00723fa0_shell::SetVirtualTableAndProcessState_00723fa0()
{
    vtable = (int*)&str_010703dc;
    BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}

struct FUN_00723ff0_shell : AX
{
    int* vtable;
    FUN_00723ff0_shell* Constructor();
};

// @fnv 0x00723ff0
FUN_00723ff0_shell* FUN_00723ff0_shell::Constructor()
{
    vtable = (int*)"`Br";
    BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}

extern int DAT_01070404;

struct FUN_00724070_shell : GlobalObject_00869f00
{
    void SetVtableAndProcessState_00724070();
};

// @fnv 0x00724070
// src: GUESS 0x00724070 (confidence: low)
void FUN_00724070_shell::SetVtableAndProcessState_00724070()
{
    *(int*)this = (int)&DAT_01070404;
    GlobalObject_00869f00::Clear(true);
}

struct FUN_007241d0_shell : FUN_00723f30_shell
{
    void* __thiscall FUN_007241d0(unsigned int flags);
};

// Calls the base cleanup, then frees this object with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x007241d0
void* FUN_007241d0_shell::FUN_007241d0(unsigned int flags)
{
    this->SetVtableAndProcessState_00723f30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00724290_shell
{
    void __thiscall SetVtableAndProcessState_00724070();
    void* __thiscall FUN_00724290(unsigned int flags);
};

// Calls FUN_00724070, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00724290
void* FUN_00724290_shell::FUN_00724290(unsigned int flags)
{
    SetVtableAndProcessState_00724070();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_007242c0_shell
{
    bool __thiscall ListBox_unsigned_int_GetFlag(unsigned int flags);
};

// Returns whether the bit at position flags is set in the 16-bit value at offset 0x2c of this object.
// @fnv 0x007242c0
// src: XBOX_PDB 0x007242c0
bool __thiscall FUN_007242c0_shell::ListBox_unsigned_int_GetFlag(unsigned int uiFlagIndex)
{
    return (*(unsigned short*)((char*)this + 0x2c) & (1 << uiFlagIndex)) != 0;
}

int GetTileValueID(const char*, int);
extern int DAT_011d8cd8;
extern int DAT_011d8cdc;
struct FUN_0071ae60_shell
{
    Tile* tile;
    unsigned int __thiscall ListBox_ItemChange_NumUnfiltered();
};
// @fnv 0x0071ae60
// src: XBOX_PDB 0x0071ae60
unsigned int __thiscall FUN_0071ae60_shell::ListBox_ItemChange_NumUnfiltered()
{
    static int numFiltered = GetTileValueID("_num_filtered", -1);
    return reinterpret_cast<VATSMenu*>(this)->GetSelectedTargetIndex() - (unsigned int)(*(Tile**)((char*)this + 12))->GetFloat(numFiltered);
}

void __cdecl ProcessEntries_00724930();
struct FUN_00721bc0_shell
{
    int x;
    void __thiscall SortEntriesAndRefresh(int(__cdecl* param)(void*, void*));
    void __thiscall ProcessEntries_00724930();
};
// Sorts the ListBoxSortList at offset 4 using the given comparison function, then calls FUN_00724930 on this object.
// @fnv 0x00721bc0
// src: GUESS 0x00721bc0 (confidence: medium)
void __thiscall FUN_00721bc0_shell::SortEntriesAndRefresh(int(__cdecl* param)(void*, void*))
{
    reinterpret_cast<ListBoxSortList*>((char*)this + 4)->Sort(param);
    this->ProcessEntries_00724930();
}

struct FUN_00723030_Holder
{
    int _p0;
    int _p1;
    int _p2;
    Tile* _t;
    bool IsTileMenu(Menu* p);
};
// Returns true when the tile exists and its menu equals the given menu.
// @fnv 0x00723030
bool FUN_00723030_Holder::IsTileMenu(Menu* apMenu)
{
    return _t && apMenu == _t->GetMenu();
}

struct FUN_00725aa0_shell
{
    void __thiscall ProcessSlots();
};
struct FUN_00723310_shell
{
    ListBoxSortList list;
    void __thiscall SortListAndProcessSlots(int(__cdecl* cmp)(void*, void*));
};
// Sorts the list at offset 4 using the given comparator, then calls ProcessSlots on this object.
// @fnv 0x00723310
// src: GUESS 0x00723310 (confidence: high)
void __thiscall FUN_00723310_shell::SortListAndProcessSlots(int(__cdecl* cmp)(void*, void*))
{
    ((ListBoxSortList*)((char*)this + 4))->Sort(cmp);
    ((FUN_00725aa0_shell*)this)->ProcessSlots();
}

struct FUN_00723ac0_shell
{
    void __thiscall ListBox_unsigned_int_Synchronize();
    void __thiscall ListBox_unsigned_int_Sort(void* param);
};
// Sorts the ListBoxSortList at this+4 using the given comparison function, then calls FUN_00726090.
// @fnv 0x00723ac0
// src: XBOX_PDB 0x00723ac0
void __thiscall FUN_00723ac0_shell::ListBox_unsigned_int_Sort(void* pCompareFunc)
{
    ((ListBoxSortList*)((char*)this + 4))->Sort((int(__cdecl*)(void*, void*))pCompareFunc);
    ListBox_unsigned_int_Synchronize();
}

struct FUN_00723f00_shell : AX
{
    int* vtable;
    FUN_00723f00_shell* __thiscall SetVirtualTableAndProcessState_00723f00();
};
// Sets the vtable pointer, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00723f00
// src: GUESS 0x00723f00 (confidence: low)
FUN_00723f00_shell* __thiscall FUN_00723f00_shell::SetVirtualTableAndProcessState_00723f00()
{
    vtable = &DAT_010703b4;
    BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}

struct FUN_00723fd0_shell : GlobalObject_00869f00
{
    void __thiscall UpdateState_00723fd0();
};

// @fnv 0x00723fd0
// src: GUESS 0x00723fd0 (confidence: low)
void __thiscall FUN_00723fd0_shell::UpdateState_00723fd0()
{
    *(char**)(void*)this = str_010703dc;
    Clear(true);
}

struct FUN_00724090_shell
{
    void __thiscall FUN_00721150();
    void* __thiscall FUN_00724090(unsigned int flags);
};

// Calls FUN_00721150, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00724090
void* FUN_00724090_shell::FUN_00724090(unsigned int flags)
{
    FUN_00721150();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00721920_shell
{
    void __thiscall FUN_00721920();
};
struct FUN_007240e0_shell
{
    void* __thiscall FUN_007240e0(unsigned int flags);
};
// Calls FUN_00721920 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007240e0
void* FUN_007240e0_shell::FUN_007240e0(unsigned int flags)
{
    ((FUN_00721920_shell*)this)->FUN_00721920();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00724110_This
{
    void __thiscall FUN_007220d0();
    void* __thiscall FUN_00724110(unsigned int flags);
};
// Calls FUN_007220d0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00724110
void* __thiscall FUN_00724110_This::FUN_00724110(unsigned int flags)
{
    FUN_007220d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct S_00724170
{
    void __thiscall FUN_00723070();
    void* __thiscall FUN_00724170(unsigned int flags);
};
// Calls FUN_00723070, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00724170
void* __thiscall S_00724170::FUN_00724170(unsigned int flags)
{
    FUN_00723070();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_007241a0_shell
{
    void __thiscall FUN_00723820();
    void* __thiscall FUN_007241a0(unsigned int flags);
};
// Calls FUN_00723820, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007241a0
void* __thiscall FUN_007241a0_shell::FUN_007241a0(unsigned int flags)
{
    FUN_00723820();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Helper_00723fd0
{
    void __thiscall UpdateState_00723fd0();
};

struct FUN_00724230_shell
{
    void* __thiscall FUN_00724230(unsigned int flags);
};

// Calls FUN_00723fd0 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00724230
void* __thiscall FUN_00724230_shell::FUN_00724230(unsigned int flags)
{
    ((Helper_00723fd0*)this)->UpdateState_00723fd0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00724260_shell
{
    void __thiscall ResetVirtualTableAndClear_00724020();
    void* __thiscall FUN_00724260(unsigned int flags);
};
// Calls FUN_00724020, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00724260
void* FUN_00724260_shell::FUN_00724260(unsigned int flags)
{
    ResetVirtualTableAndClear_00724020();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Member_007a8b10
{
    ~Member_007a8b10();
};
struct FUN_007643c0_p07 : Member_007a8b10
{
    Member_007a8b10* __thiscall DestroySelf(unsigned int flags);
};
// Runs the base destructor, then frees this object with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00764e10
Member_007a8b10* __thiscall FUN_007643c0_p07::DestroySelf(unsigned int flags)
{
    this->Member_007a8b10::~Member_007a8b10();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct ListBoxSortList;
struct FUN_007a6480_shell
{
    void __thiscall ProcessEntries_007a6480();
};
struct FUN_007a22a0_shell
{
    void __thiscall SortEntriesAndRefresh_007a22a0(int(__cdecl* cmp)(void*, void*));
};
// Sorts the ListBoxSortList at offset 4 using cmp, then calls FUN_007a6480 on this.
// @fnv 0x007a22a0
// src: GUESS 0x007a22a0 (confidence: medium)
void __thiscall FUN_007a22a0_shell::SortEntriesAndRefresh_007a22a0(int(__cdecl* cmp)(void*, void*))
{
    ((ListBoxSortList*)((char*)this + 4))->Sort(cmp);
    ((FUN_007a6480_shell*)this)->ProcessEntries_007a6480();
}

struct FUN_007a30a0_Holder
{
    int* __thiscall FindNodeValue(int, unsigned char);
    int __thiscall ListBox_ItemChange_GetTileAt(int, unsigned char);
};
// Calls FindNodeValue with the given arguments and returns the pointed-to int, or 0 if the returned pointer is null.
// @fnv 0x007a30a0
// src: COMMUNITY 0x007a30a0
int __thiscall FUN_007a30a0_Holder::ListBox_ItemChange_GetTileAt(int param1, unsigned char param2)
{
    int* p = FindNodeValue(param1, param2);
    return p ? *p : 0;
}

struct FUN_007a80e0_shell
{
    int* __thiscall InitSceneNodes();
};
struct FUN_007a5700_shell
{
    int* __thiscall SortEntriesAndInitializeSceneNodes(int(__cdecl* cmp)(void*, void*));
};
// Sorts the ListBoxSortList at offset 4 using cmp, then returns the result of InitSceneNodes on this object.
// @fnv 0x007a5700
// src: GUESS 0x007a5700 (confidence: medium)
int* __thiscall FUN_007a5700_shell::SortEntriesAndInitializeSceneNodes(int(__cdecl* cmp)(void*, void*))
{
    reinterpret_cast<ListBoxSortList*>(reinterpret_cast<char*>(this) + 4)->Sort(cmp);
    return reinterpret_cast<FUN_007a80e0_shell*>(this)->InitSceneNodes();
}

struct FUN_007a1aa0_shell
{
    void ResetVirtualTableAndClear_007a1aa0();
};
struct FUN_007a6100_shell : FUN_007a1aa0_shell
{
    void* __thiscall FUN_007a6100(unsigned int flags);
};
// @fnv 0x007a6100
void* __thiscall FUN_007a6100_shell::FUN_007a6100(unsigned int flags)
{
    ResetVirtualTableAndClear_007a1aa0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_007a6130_This
{
    void __thiscall FUN_007a1d60();
    void* __thiscall FUN_007a6130(unsigned int flags);
};
// @fnv 0x007a6130
void* __thiscall FUN_007a6130_This::FUN_007a6130(unsigned int flags)
{
    FUN_007a1d60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_007a6190Owner
{
    void __thiscall FUN_007a37b0();
    void* __thiscall FUN_007a6190(unsigned int flags);
};
// Calls FUN_007a37b0, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x007a6190
void* __thiscall FUN_007a6190Owner::FUN_007a6190(unsigned int flags)
{
    FUN_007a37b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

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
// Calls FUN_007a86b0(0) on each of the count items in arr.
// @fnv 0x007a63b0
// src: XBOX_PDB 0x007a63b0
void __thiscall FUN_007a63b0_holder::BSSimpleArray_BSStringT_char_1024_DestructItems(FUN_007a86b0_Item* apItems, unsigned int count)
{
    for (int i = 0; i < count; ++i)
        apItems[i].FUN_007a86b0(0);
}

struct FUN_007a63f0_shell
{
    void __thiscall UpdateState_007a63f0(unsigned int requested, unsigned int savedSize);
    void __thiscall ConstructElements(int, unsigned int);
};
// @fnv 0x007a63f0
// src: GUESS 0x007a63f0 (confidence: low)
void __thiscall FUN_007a63f0_shell::UpdateState_007a63f0(unsigned int uiRequestedSize, unsigned int savedSize)
{
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 12) = 0;
    if (savedSize > uiRequestedSize)
    {
        uiRequestedSize = savedSize;
    }
    if (uiRequestedSize > 0)
    {
        *(int*)((char*)this + 4) =
            ((int(__thiscall*)(void*, unsigned int))(*(int**)(*(int*)this + 4)))((void*)this, uiRequestedSize);
        *(int*)((char*)this + 12) = uiRequestedSize;
    }
    if (savedSize > 0)
    {
        ConstructElements(*(int*)((char*)this + 4), savedSize);
        *(int*)((char*)this + 8) = savedSize;
    }
}

struct FUN_007d9000_shell
{
    void __thiscall ApplySelectionAction(int a, int b);
};
struct FUN_007d7a80_shell
{
    void __thiscall ListBox_StartMenu_Option_Select(int a);
};
// @fnv 0x007d7a80
// src: COMMUNITY 0x007d7a80
void __thiscall FUN_007d7a80_shell::ListBox_StartMenu_Option_Select(int a)
{
    ((FUN_007d9000_shell*)this)->ApplySelectionAction(a, 0);
}

void __cdecl UpdateSaveLoadList();
struct FUN_007d8420_shell
{
    ListBoxSortList list;
    void __thiscall SortList(int(__cdecl* cmp)(void*, void*));
    void __thiscall UpdateSaveLoadList();
};
// Sorts the list at offset 4 using the given comparison function, then calls UpdateSaveLoadList.
// @fnv 0x007d8420
void __thiscall FUN_007d8420_shell::SortList(int(__cdecl* cmp)(void*, void*))
{
    ((ListBoxSortList*)((char*)this + 4))->Sort(cmp);
    UpdateSaveLoadList();
}

struct FUN_007a6fa0_shell
{
    int* __thiscall FindNodeValue(int* a, unsigned char b);
};
struct FUN_007d86c0_shell
{
    int* __thiscall ListBox_BGSSaveLoadFileEntry_GetDataAt(int* apItem, unsigned char apSelect);
};
// @fnv 0x007d86c0
// src: COMMUNITY 0x007d86c0
int* __thiscall FUN_007d86c0_shell::ListBox_BGSSaveLoadFileEntry_GetDataAt(int* apItem, unsigned char apSelect)
{
    FUN_007a6fa0_shell* result = (FUN_007a6fa0_shell*)((FUN_007a6fa0_shell*)this)->FindNodeValue(apItem, apSelect);
    return result ? *(int**)((char*)result + 4) : 0;
}

// The array at 0x011daae0 holds StartMenu::VideoRes records (12 bytes each).
// The nested element type is not declared by StartMenu.h yet; only its pointer
// is needed here, so use the same incomplete element type as its array helpers.
struct StartMenuVideoRes;

// 0x006a8500 releases pBuffer through _Deallocate (virtual slot 2), then clears it.
// The shared array does not yet declare this storage-release helper.
template <class T, unsigned int Growth>
void __fastcall FreeSimpleArrayStorage(BSSimpleArray<T, Growth>* array);

// @fnv 0x007d8e20
template <>
void BSSimpleArray<StartMenuVideoRes, 1024>::Clear(bool freeStorage)
{
    if (pBuffer)
    {
        ReleaseElements(pBuffer, iSize);
        if (freeStorage)
        {
            FreeSimpleArrayStorage(this);
            pBuffer = 0;
            SimpleArrayStorage = 0;
        }
        iSize = 0;
    }
}

namespace fnv_007a3cf0 {
struct ListBoxSortList
{
    void __thiscall Sort(int(__cdecl* compare)(void*, void*));
};

struct FUN_007a3cf0_shell
{
    char pad[4];
    ListBoxSortList m_kNode;
    void __thiscall SortNodesAndRefresh(int(__cdecl* compare)(void*, void*));
};

struct FUN_007a7260_shell
{
    void __thiscall ProcessEntries_007a7260();
};

// @fnv 0x007a3cf0
// src: GUESS 0x007a3cf0 (confidence: medium)
void __thiscall FUN_007a3cf0_shell::SortNodesAndRefresh(int(__cdecl* compare)(void*, void*))
{
    m_kNode.Sort(compare);
    reinterpret_cast<FUN_007a7260_shell*>(this)->ProcessEntries_007a7260();
}
}  // namespace fnv_007a3cf0

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

// @fnv 0x0071ad30
void ListBox_71ad30::UpdateScrollPages()
{
    if (m_pListTile)
    {
        int inumPages;
        float flistHeight;
        flistHeight = ((Tile*)m_pListTile)->GetFloat(0xfb0);
        inumPages = 1;
        if (m_fFirstListValue > 0 && flistHeight > 0)
        {
            if (m_fFirstListValue > flistHeight)
                inumPages = BSMAX_00647b70((int)FUN_004e4430(((FUN_0071ae60_shell*)this)->ListBox_ItemChange_NumUnfiltered() *
                                                           (m_fFirstListValue - flistHeight) / m_fFirstListValue) +
                                             1,
                                         2);
            if (inumPages > 1)
                ((Tile*)m_pListTile)
                    ->Set(Tile_TextToTrait("_scroll_delta"), (m_fFirstListValue - flistHeight) / (inumPages - 1), true);
        }
        if (m_pHighlightedTile)
            ((Tile*)m_pHighlightedTile)->Set(Tile_TextToTrait("_number_of_items"), inumPages);
    }
}

namespace fnv_00723890 {
struct ListBoxItem
{
    Tile* tile;
    InventoryStackRecord* object;
};
struct List_009e03e0
{
    ListBoxItem** FUN_006815c0();
    List_009e03e0* FUN_00726070();
    void FUN_006ecd40(unsigned int);
    ~List_009e03e0();
};
int Tile_TextToTrait(const char*);
extern bool _s_bAllowDetach;
struct FUN_00723890_this
{
    int unk00;
    ListBoxItem* m_item;
    List_009e03e0* m_next;
    Tile* tile;
    int field10;
    int unk14;
    int unk18;
    short field1c;
    float field20;
    void ListBox_unsigned_int_SetTotalListHeight();
    void ListBox_unsigned_int_UpdateHighlightBoxPos();
    void ListBox_unsigned_int_RemoveAll();
};

// @fnv 0x00723890
// src: XBOX_PDB 0x00723890
void FUN_00723890_this::ListBox_unsigned_int_RemoveAll()
{
    while (m_next && *m_next->FUN_006815c0())
    {
        List_009e03e0* next = m_next->FUN_00726070();
        if (!_s_bAllowDetach)
            delete (*m_next->FUN_006815c0())->tile;
        if (((FUN_007242c0_shell*)this)->ListBox_unsigned_int_GetFlag(1))
            delete (*m_next->FUN_006815c0())->object;
        delete *m_next->FUN_006815c0();
        m_next->FUN_006ecd40(0);
        delete m_next;
        m_next = next;
    }
    if (m_item)
    {
        if (!_s_bAllowDetach)
            delete m_item->tile;
        if (((FUN_007242c0_shell*)this)->ListBox_unsigned_int_GetFlag(1))
            delete m_item->object;
        delete m_item;
    }
    m_item = 0;
    field1c = 0;
    field20 = 0.0f;
    if (tile)
        tile->Set(Tile_TextToTrait("_num_filtered"), 0.0f, true);
    ListBox_unsigned_int_SetTotalListHeight();
    field10 = 0;
    ListBox_unsigned_int_UpdateHighlightBoxPos();
}
}  // namespace fnv_00723890

namespace fnv_007d74f0 {
extern int DAT_011dac6c;
extern int DAT_011dac70;
struct FUN_007d74f0_shell
{
    void __thiscall ListBox_StartMenu_Option_SetEnabled(bool abVal);
};
// Sets the "_enabled" trait on the tile via the helper at this+0xc.
// @fnv 0x007d74f0
// src: XBOX_PDB 0x007d74f0
void __thiscall FUN_007d74f0_shell::ListBox_StartMenu_Option_SetEnabled(bool abVal)
{
    static int s_trait = GetTileValueID("_enabled", -1);
    ((Tile*)*(char**)((char*)this + 0xc))->Set(s_trait, abVal);
}
}  // namespace fnv_007d74f0

struct FUN_007d8810_shell
{
    void* m0;
    void* m4;
    void* m8;
    Tile* mC;
    void __thiscall ListBox_BGSSaveLoadFileEntry_SetEnabled(bool abVal);
};
// Sets the _enabled trait on the Tile at mC to abVal using the cached trait ID.
// @fnv 0x007d8810
// src: COMMUNITY 0x007d8810
void __thiscall FUN_007d8810_shell::ListBox_BGSSaveLoadFileEntry_SetEnabled(bool abVal)
{
    static int sTraitID = GetTileValueID("_enabled", -1);
    mC->Set(sTraitID, abVal);
}

extern int DAT_011d95ac;
extern int DAT_011d95b0;
struct FUN_00765340_shell
{
    int pad[3];
    Tile* tile;
    unsigned int __thiscall GetUnfilteredCount();
};
// @fnv 0x00765340
unsigned int __thiscall FUN_00765340_shell::GetUnfilteredCount()
{
    static int numFiltered = GetTileValueID("_num_filtered", -1);
    return reinterpret_cast<VATSMenu*>(this)->GetSelectedTargetIndex() - (unsigned int)tile->GetFloat(numFiltered);
}

extern int DAT_011dac94;
extern int DAT_011dac98;
struct FUN_007d8700_shell
{
    int pad0;
    int pad1;
    int pad2;
    Tile* tile;
    unsigned int GetFilteredItemCount();
};

// Returns the difference between the current count and the tile's float value for the _num_filtered setting.
// @fnv 0x007d8700
unsigned int FUN_007d8700_shell::GetFilteredItemCount()
{
    static int numFiltered = GetTileValueID("_num_filtered", -1);
    return reinterpret_cast<VATSMenu*>(this)->GetSelectedTargetIndex() - (unsigned int)tile->GetFloat(numFiltered);
}

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

// @fnv 0x00721060
FUN_00721060::FUN_00721060()
{
    vptr = &DAT_01070220;

    m_pHighlightedTile = 0;
    m_pSelectedTile = 0;
    m_pListTile = 0;
    pTemplateName = 0;

    usFlags = 0;
    m_usSelectedIndex = 0;

    m_fThirdListValue = 0.0f;
    m_fSecondListValue = 0.0f;
    m_fFirstListValue = 0.0f;

    ((ListBox_SetSelectedTile_shell*)this)->SetSelectedTile(0, true);

    AddToHeadList((int*)this);
}

namespace fnv_00722f60 {
struct FUN_007240c0
{
    char* value;

    FUN_007240c0();
};

struct ListBox_TESQuest_SetSelectedTile_Helper
{
    void SetSelectedTile(Tile* apItem, bool apSelect);
};

extern char str_01070364[];

struct FUN_00722f60 : public FUN_007240c0
{
    SL sl;
    int field0c;
    int field10;
    int field14;
    int field18;
    short field1c;
    float field20;
    float field24;
    float field28;
    short field2c;

    FUN_00722f60();
};

FUN_007240c0::FUN_007240c0()
{}

// Initializes the object's fields to zero, sets value to str_01070364, calls SetSelectedTile(0, true) and AddToHeadList.
// @fnv 0x00722f60
FUN_00722f60::FUN_00722f60()
{
    value = str_01070364;

    field14 = 0;
    field10 = 0;
    field0c = 0;
    field18 = 0;
    field2c = 0;
    field1c = 0;
    field28 = 0.0f;
    field24 = 0.0f;
    field20 = 0.0f;

    reinterpret_cast<ListBox_TESQuest_SetSelectedTile_Helper*>(this)->SetSelectedTile(0, true);
    AddToHeadList(reinterpret_cast<int*>(this));
}
}  // namespace fnv_00722f60

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

// @fnv 0x00725c20
void FUN_00725c20_shell::UpdateHighlightTiles()
{
    static int highlightY = GetTileValueID(str_0106f8c0, -1);
    static int selectedHeight = GetTileValueID(str_0106f8ac, -1);

    TileValue* pHighlightY;
    TileValue* pSelectedHeight;

    if (highlightTile != 0)
    {
        if (selectedTile != 0)
        {
            pHighlightY = reinterpret_cast<TileValue*>(highlightTile->GetValue(highlightY));
            pSelectedHeight = reinterpret_cast<TileValue*>(highlightTile->GetValue(selectedHeight));

            ((HighlightValue_listbox*)pHighlightY)->Tile_Value_AddRefValueAction(0x7d0, selectedTile, 0xfa2);
            ((HighlightValue_listbox*)pHighlightY)->Tile_Value_SetFloat(0);

            ((HighlightValue_listbox*)pSelectedHeight)->Tile_Value_AddRefValueAction(0x7d0, selectedTile, 0xfb0);
            ((HighlightValue_listbox*)pSelectedHeight)->Tile_Value_SetFloat(0);

            if (((Tile*)selectedTile)->GetSpeechChallengeFailure())
            {
                Tile* pHighlightBox = FindNamedTile(highlightTile, str_0106f898);
                if (pHighlightBox != 0)
                {
                    Tile* pChild = ((Tile*)pHighlightBox)->GetNamedChild(str_0106f894);
                    if (pChild != 0)
                    {
                        ((Tile*)pChild)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)pChild)->SetImageFlags(8);

                        pChild = ((Tile*)pHighlightBox)->GetNamedChild(str_0106f88c);
                        ((Tile*)pChild)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)pChild)->SetImageFlags(8);

                        pChild = ((Tile*)pHighlightBox)->GetNamedChild(str_0106f884);
                        ((Tile*)pChild)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)pChild)->SetImageFlags(8);

                        pChild = ((Tile*)pHighlightBox)->GetNamedChild(str_0106f87c);
                        ((Tile*)pChild)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)pChild)->SetImageFlags(8);
                    }

                    ((Tile*)pHighlightBox)->SetSpeechChallengeFailure_0071aa60(true);
                    ((Tile*)pHighlightBox)->SetImageFlags(8);
                }
            }
            else
            {
                Tile* pHighlightBox = FindNamedTile(highlightTile, str_0106f898);
                if (pHighlightBox != 0)
                {
                    Tile* pChild = ((Tile*)pHighlightBox)->GetNamedChild(str_0106f894);
                    if (pChild != 0)
                    {
                        ((Tile*)pChild)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)pChild)->SetImageFlags(8);

                        pChild = ((Tile*)pHighlightBox)->GetNamedChild(str_0106f88c);
                        ((Tile*)pChild)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)pChild)->SetImageFlags(8);

                        pChild = ((Tile*)pHighlightBox)->GetNamedChild(str_0106f884);
                        ((Tile*)pChild)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)pChild)->SetImageFlags(8);

                        pChild = ((Tile*)pHighlightBox)->GetNamedChild(str_0106f87c);
                        ((Tile*)pChild)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)pChild)->SetImageFlags(8);
                    }

                    ((Tile*)pHighlightBox)->SetSpeechChallengeFailure_0071aa60(false);
                    ((Tile*)pHighlightBox)->SetImageFlags(8);
                }
            }
        }
        else
        {
            ((Tile*)highlightTile)->Set(highlightY, -1);
            ((Tile*)highlightTile)->Set(selectedHeight, 0);
        }
    }
}

namespace fnv_007a43a0 {
struct FUN_007240c0
{
    int _padding;
    FUN_007240c0();
};

extern int DAT_010755bc[];

struct FUN_007a43a0_ListBoxHelper
{
    void __thiscall SetSelectedTile(Tile* apItem, bool apSelect);
};

struct FUN_007a43a0 : FUN_007240c0, SL
{
    int field_0c;
    int field_10;
    int field_14;
    int field_18;
    short field_1c;
    float field_20;
    float field_24;
    float field_28;
    short field_2c;

    FUN_007a43a0();
};

// Initialises the object's fields to zero, sets the vtable, clears the selected tile and calls AddToHeadList.
// @fnv 0x007a43a0
FUN_007a43a0::FUN_007a43a0() : FUN_007240c0(), SL()
{
    *(int**)this = DAT_010755bc;
    field_14 = 0;
    field_10 = 0;
    field_0c = 0;
    field_18 = 0;
    field_2c = 0;
    field_1c = 0;
    field_28 = 0.0f;
    field_24 = 0.0f;
    field_20 = 0.0f;

    reinterpret_cast<FUN_007a43a0_ListBoxHelper*>(this)->SetSelectedTile(0, true);
    AddToHeadList((int*)this);
}
}  // namespace fnv_007a43a0

struct FUN_007a6bd0_shell
{
    char _base[0x0c];
    Tile* m_pListTile;
    bool __thiscall HasEnabledTrait();
};

// Returns true if the tile pointer is non-null and its _enabled trait evaluates to true.
// @fnv 0x007a6bd0
// src: GUESS 0x007a6bd0 (confidence: high)
bool FUN_007a6bd0_shell::HasEnabledTrait()
{
    static int enabledTrait = GetTileValueID("_enabled", -1);

    return m_pListTile != 0 && reinterpret_cast<Tile*>(m_pListTile)->ContainsTrait(enabledTrait);
}

struct FUN_007a79b0_shell
{
    char _pad[12];
    Tile* m_pListTile;
    bool __thiscall HasEnabledTrait();
};

// Returns true if the stored Tile pointer is non-null and its _enabled trait evaluates to true.
// @fnv 0x007a79b0
// src: GUESS 0x007a79b0 (confidence: high)
bool FUN_007a79b0_shell::HasEnabledTrait()
{
    static int userTrait = GetTileValueID("_enabled", -1);

    return m_pListTile && static_cast<Tile*>(m_pListTile)->ContainsTrait(userTrait);
}

struct EntryProperty
{
    int FUN_0044ddc0();
};
struct Entry
{
    int id;
    EntryProperty* property;
};
// Exe 0x0071a200: unit-local ListNode view; declarations and layout are preserved.
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
// @fnv 0x0071a200
// src: COMMUNITY 0x0071a200
void FunctionOwner::ListBox_ItemChange_RemoveItemGroup(int entryType)
{
    TemporaryList selected;
    {
        ListboxListNodeView* matched;
        ListboxListNodeView* current;
        current = this ? &entries : 0;
        for (; current && *current->FUN_006815c0(); current = current->FUN_00726070())
        {
            if ((*current->FUN_006815c0())->property)
            {
                if ((*current->FUN_006815c0())->property->FUN_0044ddc0() == entryType)
                {
                    selected.FUN_005ae3d0(current->FUN_006815c0());
                }
            }
        }
        matched = &selected;
        for (; matched && *matched->FUN_006815c0(); matched = matched->FUN_00726070())
        {
            RemoveTile((*matched->FUN_006815c0())->id);
        }
    }
    selected.FUN_00470470();
}

void __cdecl InterfaceManager_UnregisterListBox(void* p);

struct FUN_00721150_cls
{
    virtual ~FUN_00721150_cls();
    SL m_04;

    void __thiscall ListBox_enum_ActorValue_Index_RemoveAll();
};

// @fnv 0x00721150
FUN_00721150_cls::~FUN_00721150_cls()
{
    ListBox_enum_ActorValue_Index_RemoveAll();
    InterfaceManager_UnregisterListBox(this);
}

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

// @fnv 0x00721440
bool FUN_00721440_class::SelectObject(Tile* object)
{
    if (ListBox_enum_ActorValue_Index_IsEnabled() && (!object || (ContainsKey(object) && object->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1)))))
    {
        selected = object;
        ListBox_enum_ActorValue_Index_UpdateHighlightBoxPos();
        return true;
    }
    else
    {
        return false;
    }
}

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

// Initializes the object's vtable pointer, clears its Tile pointers, template name, flags, and float fields, then calls FUN_007a1950 and AddToHeadList.
// @fnv 0x00721850
FUN_00721850_cls::FUN_00721850_cls()
{
    vptr = &DAT_010702ec;
    m_pHighlightedTile = 0;
    m_pSelectedTile = 0;
    m_pListTile = 0;
    pTemplateName = 0;
    usFlags = 0;
    m_usSelectedIndex = 0;
    m_fThirdListValue = 0.0f;
    m_fSecondListValue = 0.0f;
    m_fFirstListValue = 0.0f;
    ((FUN_00721850_shell*)this)->ListBox_ItemChange_SetFlag(0, 1);
    AddToHeadList((int*)this);
}

struct FUN_00721920
{
    virtual ~FUN_00721920();
    SL cleanup;
    void __thiscall ReleaseStorage_00721990();
};

void __cdecl InterfaceManager_UnregisterListBox(void* object);

// Calls FUN_00721990, then passes this to FUN_007211c0.
// @fnv 0x00721920
FUN_00721920::~FUN_00721920()
{
    ReleaseStorage_00721990();
    InterfaceManager_UnregisterListBox(this);
}

namespace fnv_00721bf0 {
extern "C" char str_01070244[];
const char* __cdecl Tile_AddUserTrait(const char*, int);
struct TargetMenu
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Tile* selected;
    bool __thiscall IsScrollBarTraitEnabled();
    bool __thiscall ContainsKey(Tile*);
    void __thiscall UpdateTraitDisplay();
    bool __thiscall UpdateState_00721bf0(Tile*);
};
// @fnv 0x00721bf0
// src: GUESS 0x00721bf0 (confidence: low)
bool TargetMenu::UpdateState_00721bf0(Tile* item)
{
    if (IsScrollBarTraitEnabled() &&
        (item == 0 || (ContainsKey(item) && item->IsTraitNonZero(reinterpret_cast<int>(Tile_AddUserTrait(str_01070244, -1))))))
    {
        selected = item;
        UpdateTraitDisplay();
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_00721bf0

void __cdecl InterfaceManager_UnregisterListBox(void* p);

class FUN_007220d0_cls
{
  public:
    SL m_sub04;

    void Cleanup();
    virtual ~FUN_007220d0_cls();
};

// @fnv 0x007220d0
FUN_007220d0_cls::~FUN_007220d0_cls()
{
    Cleanup();
    InterfaceManager_UnregisterListBox(this);
}

extern bool DAT_011d8909;

struct LBItem
{
    Tile* tile;
    InventoryStackRecord* extra;
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

// @fnv 0x00722140
// src: XBOX_PDB 0x00722140
void LBListBox::ListBox_enum_MiscStatManager_MiscStatID_RemoveAll()
{
    while (pNext && *pNext->GetItem())
    {
        LBNode* next = FUN_00726070(pNext);
        if (!DAT_011d8909)
        {
            delete (*pNext->GetItem())->tile;
        }
        if (ListBox_unsigned_int_GetFlag(1))
        {
            delete (*pNext->GetItem())->extra;
        }
        delete *pNext->GetItem();
        pNext->FUN_006ecd40(0);
        delete pNext;
        pNext = next;
    }
    if (pItem)
    {
        if (!DAT_011d8909)
        {
            delete pItem->tile;
        }
        if (ListBox_unsigned_int_GetFlag(1))
        {
            delete pItem->extra;
        }
        delete pItem;
    }
    pItem = 0;
    usItemCount = 0;
    m_fFirstListValue = 0.0f;
    if (m_pListTile)
    {
        m_pListTile->Set(Tile_TextToTrait("_num_filtered"), 0.0f, true);
    }
    ListBox_enum_MiscStatManager_MiscStatID_SetTotalListHeight();
    unk10 = 0;
    ListBox_enum_MiscStatManager_MiscStatID_UpdateHighlightBoxPos();
}

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

// @fnv 0x007223a0
// src: XBOX_PDB 0x007223a0
bool ListBox_7223a0::ListBox_enum_MiscStatManager_MiscStatID_Highlight(Tile* apTile)
{
    if (ListBox_enum_MiscStatManager_MiscStatID_IsEnabled() && (!apTile || (ContainsKey(apTile) && apTile->IsTraitNonZero(Tile_AddUserTrait(_DAT_01070244, -1)))))
    {
        m_pSelected = apTile;
        ListBox_enum_MiscStatManager_MiscStatID_UpdateHighlightBoxPos();
        return true;
    }
    else
    {
        return false;
    }
}

// FUN_007227b0: constructor of a object with a base (vptr), a member sub-object
// with its own ctor/dtor (state -1..0 EH frame), a few int/word/float fields and
// a post-init call on this followed by a cdecl call with this.

struct FUN_007227b0_target
{
    void __thiscall ListBox_ItemChange_SetFlag(int, int);
};

struct FUN_007227b0_cls : FUN_007240c0
{
    SL sub;
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

// @fnv 0x007227b0
FUN_007227b0_cls::FUN_007227b0_cls()
{
    vptr = (int*)"P+r";
    unk14 = 0;
    unk10 = 0;
    unk0c = 0;
    unk18 = 0;
    w2c = 0;
    w1c = 0;
    f28 = 0.0f;
    f24 = 0.0f;
    f20 = 0.0f;
    ((FUN_007227b0_target*)this)->ListBox_ItemChange_SetFlag(0, 1);
    AddToHeadList((int*)this);
}

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
    SL member4;
};

// Calls Call on the object, then passes this to FUN_007211c0.
// @fnv 0x00722880
FUN_00722880::~FUN_00722880()
{
    ((Helper_007228f0*)this)->Call();
    InterfaceManager_UnregisterListBox(this);
}

namespace fnv_00722b50 {
struct Holder
{
    int unk00, unk04, unk08, unk0c;
    Tile* selected;
    bool __thiscall HasEnabledTrait();
    bool __thiscall ContainsKey(Tile*);
    void __thiscall UpdateSpeechChallengeTrait();
    bool __thiscall SelectEntry(Tile*);
};
extern int DAT_01070244;
extern "C" void* __cdecl Tile_AddUserTrait(const void*, int);
// @fnv 0x00722b50
bool Holder::SelectEntry(Tile* pEntry)
{
    if (HasEnabledTrait() && (!pEntry || (ContainsKey(pEntry) && pEntry->IsTraitNonZero(reinterpret_cast<int>(Tile_AddUserTrait(&DAT_01070244, -1))))))
    {
        selected = pEntry;
        UpdateSpeechChallengeTrait();
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_00722b50

struct FUN_00723070
{
    virtual ~FUN_00723070();
    SL cleanupMember;
    void ProcessEntries_007230e0();
};
void __cdecl InterfaceManager_UnregisterListBox(FUN_00723070* self);

// Calls FUN_007230e0 then FUN_007211c0 on this object during destruction.
// @fnv 0x00723070
FUN_00723070::~FUN_00723070()
{
    ProcessEntries_007230e0();
    InterfaceManager_UnregisterListBox(this);
}

namespace fnv_00723340 {
void* __cdecl Tile_AddUserTrait(const char* name, int len);

struct FUN_00723340_cls
{
    char unk00[0x10];
    Tile* m_pArg;

    bool IsEnabled();
    bool ContainsKey(Tile* arg);
    void UpdateHighlightTiles();
    bool ProcessAndReturnValue_00723340(Tile* arg);
};

// @fnv 0x00723340
// src: GUESS 0x00723340 (confidence: low)
bool FUN_00723340_cls::ProcessAndReturnValue_00723340(Tile* arg)
{
    if (IsEnabled() && (arg == 0 || (ContainsKey(arg) && arg->IsTraitNonZero(reinterpret_cast<int>(Tile_AddUserTrait("_enabled", -1))))))
    {
        m_pArg = arg;
        UpdateHighlightTiles();
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_00723340

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

// Initialises the object's vtable pointer and zeroes its integer, short and float members, then calls FUN_007a1950(0, 1) and AddToHeadList.
// @fnv 0x00723750
FUN_00723750::FUN_00723750()
{
    *(void**)this = &DAT_0107038c;
    this->m_14 = 0;
    this->m_10 = 0;
    this->m_0c = 0;
    this->m_18 = 0;
    this->m_2c = 0;
    this->m_1c = 0;
    this->m_28 = 0.0f;
    this->m_24 = 0.0f;
    this->m_20 = 0.0f;
    this->ListBox_ItemChange_SetFlag(0, 1);
    AddToHeadList((int*)this);
}

void __cdecl InterfaceManager_UnregisterListBox(void* p);

class FUN_00723820_cls
{
  public:
    virtual ~FUN_00723820_cls();
    void Reset();
    SL m_04;
};

// @fnv 0x00723820
FUN_00723820_cls::~FUN_00723820_cls()
{
    Reset();
    InterfaceManager_UnregisterListBox(this);
}

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

// If the list box is enabled and the tile is null or contained and passes the enabled check, stores it as m_pkSelected, refreshes, and returns true.
// @fnv 0x00723af0
// src: XBOX_PDB 0x00723af0
bool B23AF0ListBox::ListBox_unsigned_int_Highlight(Tile* pkTile)
{
    if (IsEnabled() && (!pkTile || (Contains(pkTile) && pkTile->IsTraitNonZero(Tile_AddUserTrait(kListBoxEnabled, -1)))))
    {
        m_pkSelected = pkTile;
        Refresh();
        return true;
    }
    else
    {
        return false;
    }
}

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
// Walks the linked list from head and returns true if any item's key equals key, otherwise false.
// @fnv 0x007242f0
bool ListOwner::ContainsKey(int key)
{
    ListLink* current = this ? &head : 0;
    for (; current && *current->FUN_006815c0(); current = current->FUN_00726070())
    {
        if ((*current->FUN_006815c0())->key == key)
        {
            return true;
        }
    }
    return false;
}

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

// @fnv 0x00724360
// src: XBOX_PDB 0x00724360
void FUN_00724360_cls::ListBox_enum_ActorValue_Index_Synchronize()
{
    FUN_00724360_Item* cur;

    m_1c = 0;
    m_20 = 0.0f;
    for (cur = (FUN_00724360_Item*)((this != 0) ? (char*)this + 4 : 0); cur != 0 && *cur->FUN_006815c0() != 0;
         cur = (FUN_00724360_Item*)cur->FUN_00726070())
    {
        if (((unsigned char*)*cur->FUN_006815c0())[8] == 0)
        {
            ((Tile*)**cur->FUN_006815c0())->FUN_00700320(0xfac, (int)m_1c++);
            AccumulateTileHeight(**cur->FUN_006815c0());
        }
    }
    ListBox_enum_ActorValue_Index_SetTotalListHeight();
    ListBox_enum_ActorValue_Index_UpdateHighlightBoxPos();
}

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
// @fnv 0x00724430
// src: XBOX_PDB 0x00724430
bool Owner_00724430::ListBox_enum_ActorValue_Index_IsEnabled()
{
    static int selectedValue = Tile_AddUserTrait(str_01070244, -1);
    return item != 0 && item->IsTraitNonZero(selectedValue);
}

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

// @fnv 0x00724930
// src: GUESS 0x00724930 (confidence: low)
void FUN_00724930_cls::ProcessEntries_00724930()
{
    m_1c = 0;
    m_20 = 0.0f;
    Node00724930* cur;
    for (cur = this != 0 ? (Node00724930*)((char*)this + 4) : 0; cur != 0 && *cur->FUN_006815c0() != 0;
         cur = cur->FUN_00726070())
    {
        if ((*cur->FUN_006815c0())->flag08 == 0)
        {
            (*cur->FUN_006815c0())->unk00->FUN_00700320(0xfac, m_1c++);
            AccumulateTileHeight((*cur->FUN_006815c0())->unk00);
        }
    }
    UpdateState_00724dd0();
    UpdateTraitDisplay();
}

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

// @fnv 0x00724dd0
// src: GUESS 0x00724dd0 (confidence: low)
void ScrollPageList::UpdateState_00724dd0()
{
    if (pScrollTile)
    {
        float fScrollValue = pScrollTile->GetFloat(0xfb0);
        int iItemCount = 1;
        if (fTotal > 0.0 && fScrollValue > 0.0)
        {
            if (fTotal > fScrollValue)
            {
                iItemCount = BSMAX_00647b70((int)FUN_004e4430(GetUnfilteredRaceCount() * (fTotal - fScrollValue) / fTotal) + 1, 2);
            }
            if (iItemCount > 1)
            {
                ((Tile*)pScrollTile)
                    ->Set(Tile_TextToTrait("_scroll_delta"), (fTotal - fScrollValue) / (iItemCount - 1), true);
            }
        }
        if (pCountTile)
        {
            pCountTile->Set(Tile_TextToTrait("_number_of_items"), iItemCount);
        }
    }
}

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
// Reads a value from tile0c, computes a scroll delta from range and that value, applies it to tile0c, and passes the count to tile14.
// @fnv 0x007253a0
// src: XBOX_PDB 0x007253a0
void OwnerProxy::ListBox_enum_MiscStatManager_MiscStatID_SetTotalListHeight()
{
    if (tile0c)
    {
        float p = tile0c->FUN_00a011b0(4016);
        int h = 1;
        if (range > 0.0 && p > 0.0)
        {
            if (range > p)
            {
                h = BSMAX_00647b70((int)FUN_004e4430(ListBox_enum_MiscStatManager_MiscStatID_NumUnfiltered() * (range - p) / range) + 1, 2);
            }
            if (h > 1)
                tile0c->Tile_Set(Tile_TextToTrait("_scroll_delta"), (range - p) / (h - 1), true);
        }
        if (tile14)
            tile14->FUN_00700320(Tile_TextToTrait("_number_of_items"), h);
    }
}

struct FUN_007255a0_cls
{
    int unk00;
    int unk04;
    int unk08;
    Tile* m_0c;
    unsigned char HasEnabledTrait();
};

int __cdecl Tile_AddUserTrait(const char* name, int len);

// Returns 1 if m_0c is non-null and its IsTraitNonZero returns true for the cached "_enabled" setting, otherwise 0.
// @fnv 0x007255a0
// src: GUESS 0x007255a0 (confidence: medium)
unsigned char FUN_007255a0_cls::HasEnabledTrait()
{
    static int enabledRef = Tile_AddUserTrait("_enabled", -1);
    return (m_0c != 0 && m_0c->IsTraitNonZero(enabledRef)) ? 1 : 0;
}

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
// @fnv 0x00725970
// src: GUESS 0x00725970 (confidence: low)
void S725970::UpdateState_00725970()
{
    int n;
    float f6;
    if (tileA)
    {
        f6 = tileA->GetFloat(0xfb0);
        n = 1;
        if (fVal > 0.0 && f6 > 0.0)
        {
            if (fVal > f6)
                n = BSMAX_00647b70((int)FUN_004e4430((float)(unsigned int)GetUnfilteredRaceCount() * (fVal - f6) / fVal) + 1, 2);
            if (n > 1)
                tileA->Set(Tile_TextToTrait(str_0106f90c), (fVal - f6) / (n - 1), true);
        }
        if (tileB)
            tileB->Set(Tile_TextToTrait(str_0106f8f8), n);
    }
}

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

// Returns true if m_pkTile exists and its GetBool returns true for the cached s_iEnabled setting.
// @fnv 0x00726160
// src: XBOX_PDB 0x00726160
bool B726160Menu::ListBox_unsigned_int_IsEnabled()
{
    static int s_iEnabled = Tile_AddUserTrait(kListBoxEnabled, -1);
    return m_pkTile && m_pkTile->IsTraitNonZero(s_iEnabled);
}

struct Parent
{
    void* vptr;
    Parent();
};
struct FUN_00730810 : Parent
{
    SL section;
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
// Initialises the object's vtable, clears its pointers, flags, indices and floats, then calls FUN_007a1950(0,1) and AddToHeadList.
// @fnv 0x00730810
FUN_00730810::FUN_00730810()
{
    vptr = &DAT_01070890;
    scrollbar = 0;
    selected = 0;
    container = 0;
    templateName = 0;
    flags = 0;
    nextIndex = 0;
    lastScrollbar = 0.0f;
    lastSelection = 0.0f;
    totalHeight = 0.0f;
    ListBox_ItemChange_SetFlag(0, 1);
    AddToHeadList(this);
}

struct FUN_00730e20_cls
{
    int m_00;
    int m_04;
    int m_08;
    Tile* m_0c;
    bool ListBox_ItemChange_IsEnabled();
};

int __cdecl Tile_AddUserTrait(const char* s, int n);

// @fnv 0x00730e20
// src: XBOX_PDB 0x00730e20
bool FUN_00730e20_cls::ListBox_ItemChange_IsEnabled()
{
    static void* sKey = (void*)Tile_AddUserTrait("_enabled", -1);
    return (m_0c != 0 && m_0c->IsTraitNonZero(reinterpret_cast<int>(sKey))) ? 1 : 0;
}

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

// Returns true if m_pTile0c is set and its IsTraitNonZero check passes for the cached s_trait value.
// @fnv 0x00764e40
// src: XBOX_PDB 0x00764e40
bool Cls_764e40::ListBox_int_IsEnabled()
{
    static int s_trait = Tile_AddUserTrait(_DAT_01070244, -1);
    return m_pTile0c && m_pTile0c->IsTraitNonZero(s_trait);
}

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
// Walks the head node list, comparing each item's key to *key, and returns the matching item's data pointer or 0.
// @fnv 0x007a22d0
int* Owner::FindItemData(int* piKey)
{
    Node* iter = this ? &head : 0;
    for (; iter && *iter->FUN_006815c0(); iter = iter->FUN_00726070())
    {
        if ((*iter->FUN_006815c0())->key == *piKey)
        {
            return (*iter->FUN_006815c0())->data;
        }
    }
    return 0;
}

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

// @fnv 0x007a23e0
// src: COMMUNITY 0x007a23e0
bool FUN_007a23e0_cls::ListBox_TESQuest_Destroy(Tile* arg)
{
    if (HasEnabledTrait() && (arg == 0 || (ContainsKey(arg) && arg->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1)))))
    {
        m_10 = arg;
        UpdateHighlightTraits_007a6600();
        return true;
    }
    else
    {
        return false;
    }
}

class B7A27F0Tile;

class B7A27F0Base
{
  public:
    B7A27F0Base();
    virtual void VFunc00();
};

void __cdecl AddToHeadList(void* pvListBox);

class FUN_007a27f0_cls : public B7A27F0Base, public SL
{
  public:
    FUN_007a27f0_cls();
    virtual void VFunc00();

    void SetSelectedTile(B7A27F0Tile* pkTile, bool bFlag);

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

// Initializes the tile list's pointers, flags, counts and scroll values to zero, then clears the selection and calls AddToHeadList on this.
// @fnv 0x007a27f0
FUN_007a27f0_cls::FUN_007a27f0_cls()
{
    m_pkSelected = 0;
    m_pkScrollBar = 0;
    m_pkParentTile = 0;
    m_pkTemplate = 0;
    m_sFlags = 0;
    m_sItemCount = 0;
    m_fItemHeight = 0.0f;
    m_fScrollMax = 0.0f;
    m_fScrollPos = 0.0f;
    SetSelectedTile(0, true);
    AddToHeadList(this);
}

extern int DAT_01075594;

struct FUN_007a36e0_cls : FUN_007240c0
{
    SL m_04;
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

// @fnv 0x007a36e0
FUN_007a36e0_cls::FUN_007a36e0_cls() : FUN_007240c0(), m_04()
{
    vptr = (int*)&DAT_01075594;
    m_14 = 0;
    m_10 = 0;
    m_0c = 0;
    m_18 = 0;
    m_2c = 0;
    m_1c = 0;
    m_28 = 0.0f;
    m_24 = 0.0f;
    m_20 = 0.0f;
    ListBox_ItemChange_SetFlag(0, 1);
    AddToHeadList((int*)this);
}

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

// Default-constructs count FUN_007a6310_Elem8 objects in place at arr.
// @fnv 0x007a6310
void FUN_007a6310_cls::ConstructElements(int apElements, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        new (&((FUN_007a6310_Elem8*)apElements)[i]) FUN_007a6310_Elem8();
    }
}

namespace fnv_007a6480 {
struct Obj
{
    Tile* inner;
    int unk04;
    unsigned char flag08;
};

struct Holder
{
    Obj* obj;
};

struct Node
{
    Node* FUN_00726070();
    Holder* FUN_006815c0();
};

struct FUN_007a6480_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short unk1c;
    float unk20;

    void AccumulateTileHeight(Tile* p);
    void UpdateScrollTraits_007a6920();
    void UpdateHighlightTraits_007a6600();
    void ProcessEntries_007a6480();
};

// @fnv 0x007a6480
// src: GUESS 0x007a6480 (confidence: low)
void FUN_007a6480_cls::ProcessEntries_007a6480()
{
    unk1c = 0;
    unk20 = 0.0f;
    for (Node* cur = this ? (Node*)&unk04 : 0; cur != 0 && cur->FUN_006815c0()->obj != 0; cur = cur->FUN_00726070())
    {
        if (cur->FUN_006815c0()->obj->flag08 == 0)
        {
            cur->FUN_006815c0()->obj->inner->FUN_00700320(0xfac, unk1c++);
            AccumulateTileHeight(cur->FUN_006815c0()->obj->inner);
        }
    }
    UpdateScrollTraits_007a6920();
    UpdateHighlightTraits_007a6600();
}
}  // namespace fnv_007a6480

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

// Returns true when target is non-null and its IsTraitNonZero check passes for the cached value from FUN_00a00940(str_01070244, -1).
// @fnv 0x007a6550
// src: GUESS 0x007a6550 (confidence: medium)
bool FUN_007a6550_shell::HasEnabledTrait()
{
    static int value = Tile_AddUserTrait(str_01070244, -1);
    return target != 0 && target->IsTraitNonZero(value);
}

namespace fnv_007a6fa0 {
// Exe 0x007a6fa0: unit-local ListNode view; declarations and layout are preserved.
struct ListboxListNodeView
{
    bool __thiscall FUN_008256d0();
    ListboxListNodeView* __thiscall FUN_00726070();
    Tile*** __thiscall FUN_006815c0();
};
struct ListOwner
{
    int ownerData;
    ListboxListNodeView firstNode;
    int* __thiscall FindNodeValue(unsigned int requested, unsigned char byIndex);
};
// Walks the node list by index or by matching trait 0xfac against requested, returning the node's value pointer or null.
// @fnv 0x007a6fa0
int* ListOwner::FindNodeValue(unsigned int requested, unsigned char byIndex)
{
    if (firstNode.FUN_008256d0())
        return 0;
    ListboxListNodeView* node = this ? &firstNode : 0;
    if (byIndex)
    {
        unsigned int index = 0;
        while (node != 0 && index++ != requested)
            node = node->FUN_00726070();
    }
    else
    {
        while (node != 0 && (**node->FUN_006815c0())->FUN_00a011b0(0xfac) != requested)
            node = node->FUN_00726070();
    }
    return node ? (int*)*node->FUN_006815c0() : 0;
}
}  // namespace fnv_007a6fa0

int Tile_AddUserTrait(const char* name, int len);

struct FUN_007a7330_cls
{
    int unk00;
    int unk04;
    int unk08;
    Tile* m_0c;

    unsigned char IsEnabled();
};

// Returns 1 if m_0c is non-null and its IsTraitNonZero returns true for the cached "_enabled" handle, otherwise 0.
// @fnv 0x007a7330
// src: GUESS 0x007a7330 (confidence: high)
unsigned char FUN_007a7330_cls::IsEnabled()
{
    static int s_handle = Tile_AddUserTrait("_enabled", -1);
    return (m_0c != 0 && m_0c->IsTraitNonZero(s_handle)) ? 1 : 0;
}

struct FUN_007a81b0_cls
{
    int m_00;
    int m_04;
    int m_08;
    Tile* m_0c;
    bool IsEnabled();
};

int __cdecl Tile_AddUserTrait(const char* s, int n);

// @fnv 0x007a81b0
// src: GUESS 0x007a81b0 (confidence: high)
bool FUN_007a81b0_cls::IsEnabled()
{
    static void* sKey = (void*)Tile_AddUserTrait("_enabled", -1);
    return (m_0c != 0 && m_0c->IsTraitNonZero(reinterpret_cast<int>(sKey))) ? 1 : 0;
}

extern int DAT_01077094;
struct FUN_007240c0_Base
{
    const void* vtbl00;
    FUN_007240c0_Base();
};
void __cdecl AddToHeadList(void* p);
struct FUN_007d7c60 : FUN_007240c0_Base
{
    SL list04;
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
// Constructor: sets the vtable, zero-initialises the fields, calls FUN_007a1950 with null and true, then AddToHeadList on this.
// @fnv 0x007d7c60
FUN_007d7c60::FUN_007d7c60()
{
    vtbl00 = &DAT_01077094;
    unk14 = 0;
    unk10 = 0;
    unk0C = 0;
    unk18 = 0;
    unk2C = 0;
    unk1C = 0;
    unk28 = 0.0f;
    unk24 = 0.0f;
    unk20 = 0.0f;
    ListBox_ItemChange_SetFlag(0, true);
    AddToHeadList(this);
}

void __cdecl InterfaceManager_UnregisterListBox(void*);

struct FUN_007d7d30
{
    SL m;
    void ListBox_BGSSaveLoadFileEntry_RemoveAll();
    virtual ~FUN_007d7d30();
};

// Calls FUN_007d81f0 on this, then passes this to FUN_007211c0.
// @fnv 0x007d7d30
FUN_007d7d30::~FUN_007d7d30()
{
    this->ListBox_BGSSaveLoadFileEntry_RemoveAll();
    InterfaceManager_UnregisterListBox(this);
}

void** __fastcall FUN_006815c0(void* node);
void* __fastcall FUN_00726070(void* node);

struct FUN_007d8da0_cls
{
    void ListBox_BGSSaveLoadFileEntry_DeselectAll(bool bFlag);
};

// Iterates the list starting at this+4 and calls FUN_007d8d80 on each tile, skipping entries whose byte at offset 8 is set when bFlag is true.
// @fnv 0x007d8da0
// src: COMMUNITY 0x007d8da0
void FUN_007d8da0_cls::ListBox_BGSSaveLoadFileEntry_DeselectAll(bool abSkipFlagged)
{
    for (void* cur = (this != 0) ? (void*)((char*)this + 4) : 0; cur != 0 && *FUN_006815c0(cur) != 0;
         cur = FUN_00726070(cur))
    {
        if (!abSkipFlagged || ((unsigned char*)*FUN_006815c0(cur))[8] == 0)
        {
            ((ListboxSelectionCallView*)this)->SetSelection_Thunk((Tile*)*(void**)*FUN_006815c0(cur));
        }
    }
}

int __cdecl Tile_AddUserTrait(const char*, int);
struct SelectionTile
{
    bool IsTraitNonZero(int);
    void Set(int, int);
};
struct SelectionList
{
    bool ListBox_StartMenu_Option_IsEnabled();
    bool ContainsKey(SelectionTile*);
    bool ApplySelectionAction(SelectionTile* item, int action);
};
// If the list is ready and contains the item, reads its _selected state and sets it to 1, 0 or toggled depending on action 0/1/2, returning true on success.
// @fnv 0x007d9000
bool SelectionList::ApplySelectionAction(SelectionTile* item, int action)
{
    if (ListBox_StartMenu_Option_IsEnabled() && item && ContainsKey(item))
    {
        static int selected = Tile_AddUserTrait("_selected", -1);
        bool value = item->IsTraitNonZero(selected);
        switch (action)
        {
        case 0:
            if (!value)
            {
                item->Set(selected, 1);
                return true;
            }
            break;
        case 1:
            if (value)
            {
                item->Set(selected, 0);
                return true;
            }
            break;
        case 2:
            item->Set(selected, !value);
            return true;
        }
    }
    return false;
}

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
// @fnv 0x007d9460
// src: XBOX_PDB 0x007d9460
void HeightList::ListBox_StartMenu_Option_SetTotalListHeight()
{
    if (container)
    {
        float count = container->FUN_00a011b0(0xfb0);
        int height = 1;
        if (totalHeight > 0.0 && count > 0.0)
        {
            if (totalHeight > count)
                height = BSMAX_00647b70((int)FUN_004e4430(FUN_007d9ee0() * (totalHeight - count) / totalHeight) + 1, 2);
            if (height > 1)
                ((Tile*)container)->Set(Tile_TextToTrait(str_0106f90c), (totalHeight - count) / (height - 1), true);
        }
        if (scrollbar)
            scrollbar->Set(Tile_TextToTrait(str_0106f8f8), height);
    }
}

namespace fnv_007d9660 {
int Tile_AddUserTrait(const char*, int);
struct SelectionTile
{
    bool IsTraitNonZero(int);
    void FUN_00700320(int, int);
};
struct SelectionList
{
    bool ListBox_BGSSaveLoadFileEntry_IsEnabled();
    bool ContainsKey(SelectionTile*);
    bool SetItemSelectionTrait(SelectionTile*, int);
};
// Checks the list and item, reads the item's _selected trait, and sets, clears, or toggles it based on operation, returning whether it changed.
// @fnv 0x007d9660
// src: GUESS 0x007d9660 (confidence: medium)
bool SelectionList::SetItemSelectionTrait(SelectionTile* item, int operation)
{
    if (ListBox_BGSSaveLoadFileEntry_IsEnabled() && item && ContainsKey(item))
    {
        static int selectedTrait = Tile_AddUserTrait("_selected", -1);
        bool selected = item->IsTraitNonZero(selectedTrait);
        switch (operation)
        {
        case 0:
            if (!selected)
            {
                item->FUN_00700320(selectedTrait, true);
                return true;
            }
            break;
        case 1:
            if (selected)
            {
                item->FUN_00700320(selectedTrait, false);
                return true;
            }
            break;
        case 2:
            item->FUN_00700320(selectedTrait, !selected);
            return true;
        }
    }
    return false;
}
}  // namespace fnv_007d9660

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

// @fnv 0x007d9d50
// src: XBOX_PDB 0x007d9d50
void ListBoxScroll::ListBox_BGSSaveLoadFileEntry_SetTotalListHeight()
{
    if (m_pListTile)
    {
        float m_fGlyphExtent = m_pListTile->GetFloat(0xfb0);
        int iNumItems2 = 1;
        if (m_fFirstListValue > 0.0 && m_fGlyphExtent > 0.0)
        {
            if (m_fFirstListValue > m_fGlyphExtent)
            {
                iNumItems2 = BSMAX_00647b70(
                    int(FUN_004e4430(GetFilteredItemCount() * (m_fFirstListValue - m_fGlyphExtent) / m_fFirstListValue)) + 1,
                    2);
            }
            if (iNumItems2 > 1)
            {
                m_pListTile->Set(Tile_TextToTrait("_scroll_delta"), (m_fFirstListValue - m_fGlyphExtent) / (iNumItems2 - 1), true);
            }
        }
        if (m_pHighlightedTile)
        {
            m_pHighlightedTile->Set(Tile_TextToTrait("_number_of_items"), iNumItems2);
        }
    }
}

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
// @fnv 0x00851540
// src: COMMUNITY 0x00851540
void RecordList::BGSSaveLoadManager_FreeSavesList()
{
    OwnedRecordList* current = head;
    while (current != 0)
    {
        delete *current->FUN_006815c0();
        current = current->FUN_00726070();
    }
    if (head != 0)
    {
        head->FUN_00470470();
        delete head;
        head = 0;
    }
    count = 0;
}

// These game helpers have C++ linkage; the CRT also declares C functions
// with these names through the shared headers.
namespace ListBoxStrings
{
int __cdecl strcpy_s(char*, unsigned int, const char*);
int __cdecl strcat_s(char*, unsigned int, const char*);
}
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
// @fnv 0x00719ef0
void InventoryListBox::PopulateInventoryList(InventoryOwner* owner, bool(__cdecl* filter)(InventoryEntry*), int sort,
                                             void(__cdecl* callback)(Tile*, InventoryEntry*), bool split, bool include)
{
    if (!owner || !container || !templateName)
        return;
    ClearItems();
    ListBox_ItemChange_SetFlag(1, true);
    bool a = ListBox_unsigned_int_GetFlag(0);
    ListBox_ItemChange_SetFlag(0, false);
    InventoryList* h;
    InventoryChanges* p;
    owner->TESObjectREFR_StartInventoryIter(include, &h, &p);
    if (h && p)
    {
        InventoryEntry* entry = p->GetNextInventoryEntry(h);
        while (entry)
        {
            if (!filter || !filter(entry))
            {
                TESFullName* s;
                unsigned int i;
                Tile* a;
                int p = 0;
                int h = entry->FUN_00726070();
                do
                {
                    s = dynamic_cast<TESFullName*>(entry->GetObject());
                    i = BSStringLength(s->GetFullName());
                    char name[128];
                    ListBoxStrings::strcpy_s(name, i + 1, s->GetFullName());
                    if (entry->FUN_004bd820())
                        ListBoxStrings::strcat_s(name, i + 2, "+");
                    if (split)
                    {
                        if (p > 0)
                        {
                            InventoryEntry* single = new InventoryEntry;
                            single->ItemChange_Copy2(entry);
                            entry = single;
                            entry->FUN_006ecd40(1);
                        }
                        else if (h > 1)
                        {
                            entry->FUN_006ecd40(1);
                        }
                        ++p;
                    }
                    a = ListBox_ItemChange_AddItem(entry, name, sort, 0);
                    if (callback)
                        callback(a, entry);
                } while (split && p < h);
            }
            entry = p->GetNextInventoryEntry(h);
        }
        delete h;
    }
    if (sort)
        UpdateItems();
    ListBox_ItemChange_SetFlag(0, a);
}

struct RemovalItem
{
    Tile* tile;
    InventoryStackRecord* extra;
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

// @fnv 0x0071aaa0
bool RemovalList::RemoveNode(RemovalNode* node, RemovalNode* previous)
{
    if (node)
    {
        if ((*node->GetItem())->tile == selected)
        {
            selected = node->FUN_00726070() ? (*node->FUN_00726070()->GetItem())->tile
                                            : ((previous && previous != node) ? (*previous->GetItem())->tile : 0);
            if (selected)
                InterfaceManager_GetSingleton()->InterfaceManager_SetCurrentFocusTarget(selected, 0xfc3, 1);
        }
        if (container && (*node->GetItem())->counted)
            container->Tile_Set(Tile_TextToTrait(str_0106f8d0),
                                    container->FUN_00a011b0(Tile_TextToTrait(str_0106f8d0)) - 1.0, true);
        delete (*node->GetItem())->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete (*node->GetItem())->extra;
        delete *node->GetItem();
        if (node == static_cast<RemovalNode*>(this))
        {
            if (next)
            {
                previous = next;
                next = previous->FUN_00726070();
                item = *previous->GetItem();
                previous->FUN_006ecd40(0);
                delete previous;
            }
            else
            {
                item = 0;
            }
        }
        else
        {
            previous->FUN_006ecd40(node->FUN_00726070());
            node->FUN_006ecd40(0);
            delete node;
        }
        if (ListBox_unsigned_int_GetFlag(0))
            UpdateItems();
        return true;
    }
    return false;
}

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

// Clears DAT_011dace0, deletes the four owned pointers p74/p80/p7c/p78, then calls FUN_0071f8c0.
// @fnv 0x0071f700
FUN_0071f700::~FUN_0071f700()
{
    DAT_011dace0 = 0;
    delete p74;
    delete p80;
    delete p7c;
    delete p78;
    Object_UpdateFields_0071f8c0();
}

struct TileObjV
{
    virtual void* Del(unsigned int flags);
};
struct ItemS
{
    TileObjV* curNode;
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

// @fnv 0x007211e0
// src: XBOX_PDB 0x007211e0
void OwnerS::ListBox_enum_ActorValue_Index_RemoveAll()
{
    while (pHead != 0 && *pHead->FUN_006815c0() != 0)
    {
        NodeS* nextNode;
        NodeS* tile;
        ItemS* tileObj;
        ExtraObj_listbox* zArg;
        ExtraObj_listbox* pTile;
        TileObjV* itemPtr;
        TileObjV* curNode;
        NodeS* deadNode = pHead->FUN_00726070();
        if (!DAT_011d8909)
        {
            itemPtr = (*pHead->FUN_006815c0())->curNode;
            curNode = itemPtr;
            curNode ? curNode->Del(1) : 0;
        }
        if (ListBox_unsigned_int_GetFlag(1))
        {
            zArg = (*pHead->FUN_006815c0())->extra;
            pTile = zArg;
            pTile ? pTile->FUN_004459e0(1) : 0;
        }
        tileObj = *pHead->FUN_006815c0();
        operator delete(tileObj);
        pHead->FUN_006ecd40(0);
        nextNode = pHead;
        tile = nextNode;
        tile ? tile->FUN_004702f0(1) : 0;
        pHead = deadNode;
    }
    if (pSingle != 0)
    {
        ItemS* secondTile;
        ExtraObj_listbox* nxt;
        ExtraObj_listbox* extraB;
        TileObjV* tileTmpPtr;
        TileObjV* singleItem;
        if (!DAT_011d8909)
        {
            tileTmpPtr = pSingle->curNode;
            singleItem = tileTmpPtr;
            singleItem ? singleItem->Del(1) : 0;
        }
        if (ListBox_unsigned_int_GetFlag(1))
        {
            nxt = pSingle->extra;
            extraB = nxt;
            extraB ? extraB->FUN_004459e0(1) : 0;
        }
        secondTile = pSingle;
        operator delete(secondTile);
    }
    pSingle = 0;
    m_usPassCountLocal = 0;
    m_fGlyphExtent = 0.0f;
    if (pTile != 0)
    {
        pTile->Tile_Set(Tile_TextToTrait("_num_filtered"), 0.0f, true);
    }
    ListBox_enum_ActorValue_Index_SetTotalListHeight();
    m10 = 0;
    ListBox_enum_ActorValue_Index_UpdateHighlightBoxPos();
}

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
// @fnv 0x007214b0
// src: XBOX_PDB 0x007214b0
Tile* NavigationList::ListBox_enum_ActorValue_Index_GetHighlightTarget(unsigned int action)
{
    Tile* result = 0;
    int delta = 0;
    switch (action)
    {
    case 2:
        delta = 1;
        break;
    case 1:
        delta = -1;
        break;
    case 15:
        delta = container
                    ? (int)FUN_004bd510(
                          -container->FUN_00a011b0(0xfb0) / container->FUN_00a011b0(Tile_TextToTrait(str_0106f90c)), 1.0f)
                    : 0;
        break;
    case 16:
        delta = container
                    ? (int)FUN_004bd510(
                          container->FUN_00a011b0(0xfb0) / container->FUN_00a011b0(Tile_TextToTrait(str_0106f90c)), 1.0f)
                    : 0;
        break;
    }
    if (ListBox_enum_ActorValue_Index_IsEnabled() && delta && count)
    {
        int last = count - 1;
        int current;
        int index;
        NavigationNode* node;
        if (selected)
        {
            index = (int)selected->FUN_00a011b0(0xfac);
            if ((current = index + delta) < 0)
                current = 0;
            else if (current > last)
                current = last;
        }
        else
        {
            if (delta > 0)
                current = 0;
            else
                current = last;
        }
        while (true)
        {
            for (node = this; !result && node && *node->FUN_006815c0(); node = node->FUN_00726070())
            {
                if ((*node->FUN_006815c0())->tile->FUN_00a011b0(0xfac) == current)
                    result = (*node->FUN_006815c0())->tile;
            }
            if (result && !result->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1)))
            {
                result = 0;
                if (delta > 0 && ++current > last)
                {
                    current = last - 1;
                    while ((!result || !result->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1))) && current >= 0)
                    {
                        result = GetAt(current--, false);
                    }
                    break;
                }
                else if (delta < 0 && --current < 0)
                {
                    current = 1;
                    while ((!result || !result->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1))) && current <= last)
                    {
                        result = GetAt(current++, false);
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    return result != selected ? result : 0;
}

int __cdecl LBGetTraitID(const char* apName);

struct LBClearList : LBListBox
{
    void UpdateState_00724dd0();
    void UpdateTraitDisplay();
    void ReleaseStorage_00721990();
};

// @fnv 0x00721990
// src: GUESS 0x00721990 (confidence: low)
void LBClearList::ReleaseStorage_00721990()
{
    while (pNext && *pNext->GetItem())
    {
        LBNode* pListNode = FUN_00726070(pNext);
        if (!DAT_011d8909)
            delete (*pNext->GetItem())->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete (*pNext->GetItem())->extra;
        delete *pNext->GetItem();
        pNext->FUN_006ecd40(0);
        delete pNext;
        pNext = pListNode;
    }

    if (pItem)
    {
        if (!DAT_011d8909)
            delete pItem->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete pItem->extra;
        delete pItem;
    }
    pItem = 0;
    usItemCount = 0;
    m_fFirstListValue = 0.0f;
    if (m_pListTile)
        m_pListTile->Set(LBGetTraitID("_num_filtered"), 0.0f, true);
    UpdateState_00724dd0();
    unk10 = 0;
    UpdateTraitDisplay();
}

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

// Computes a target index from the action delta, scans sibling nodes for a matching enabled tile, and returns it unless it equals m_pSelected.
// @fnv 0x00721c60
// src: COMMUNITY 0x00721c60
Tile* Class_721c60::ListBox_PerkRankData_HandleKeyboardInput(int action)
{
    Tile* pTargetTile2 = 0;
    int iDelta = 0;

    switch (action)
    {
    case 2:
        iDelta = 1;
        break;
    case 1:
        iDelta = -1;
        break;
    case 15:
        iDelta = m_pScrollBar ? (int)FUN_004bd510(-m_pScrollBar->FUN_00a011b0(0xfb0) /
                                                      m_pScrollBar->FUN_00a011b0(Tile_TextToTrait(str_0106f90c)),
                                                  1.0f)
                              : 0;
        break;
    case 16:
        iDelta = m_pScrollBar ? (int)FUN_004bd510(m_pScrollBar->FUN_00a011b0(0xfb0) /
                                                      m_pScrollBar->FUN_00a011b0(Tile_TextToTrait(str_0106f90c)),
                                                  1.0f)
                              : 0;
        break;
    }

    if (IsScrollBarTraitEnabled() && iDelta != 0 && m_usItemCount != 0)
    {
        int iIndex;
        int iMaxIndex2 = m_usItemCount - 1;
        int iCurIndex5;
        Node_721c60* pIter;

        if (m_pSelected)
        {
            iCurIndex5 = (int)m_pSelected->FUN_00a011b0(0xfac);
            if ((iIndex = iCurIndex5 + iDelta) < 0)
            {
                iIndex = 0;
            }
            else if (iIndex > iMaxIndex2)
            {
                iIndex = iMaxIndex2;
            }
        }
        else if (iDelta > 0)
        {
            iIndex = 0;
        }
        else
        {
            iIndex = iMaxIndex2;
        }

        while (true)
        {
            for (pIter = this; !pTargetTile2 && pIter && *pIter->FUN_006815c0(); pIter = pIter->FUN_00726070())
            {
                if ((*pIter->FUN_006815c0())->tile->FUN_00a011b0(0xfac) == iIndex)
                {
                    pTargetTile2 = (*pIter->FUN_006815c0())->tile;
                }
            }

            if (pTargetTile2 && !pTargetTile2->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1)))
            {
                pTargetTile2 = 0;
                if (iDelta > 0 && ++iIndex > iMaxIndex2)
                {
                    iIndex = iMaxIndex2 - 1;
                    while ((!pTargetTile2 || !pTargetTile2->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1))) &&
                           iIndex >= 0)
                    {
                        pTargetTile2 = VFunc14(iIndex--, false);
                    }
                    break;
                }
                else if (iDelta < 0 && --iIndex < 0)
                {
                    iIndex = 1;
                    while ((!pTargetTile2 || !pTargetTile2->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1))) &&
                           iIndex <= iMaxIndex2)
                    {
                        pTargetTile2 = VFunc14(iIndex++, false);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    return pTargetTile2 != m_pSelected ? pTargetTile2 : 0;
}

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

// @fnv 0x00722000
FUN_00722000::FUN_00722000()
{
    vptr = &DAT_01070314;
    m_pHighlightedTile = 0;
    m_pSelectedTile = 0;
    m_pListTile = 0;
    pTemplateName = 0;
    usFlags = 0;
    m_usSelectedIndex = 0;
    m_fThirdListValue = 0.0f;
    m_fSecondListValue = 0.0f;
    m_fFirstListValue = 0.0f;
    ListBox_ItemChange_SetFlag(0, 1);
    AddToHeadList(this);
}

struct ListBox_007228f0 : LBListBox
{
    void UpdateState_00725970();
    void UpdateSpeechChallengeTrait();
    void ListBox_StatsMenu_StatusEffect_FreeAllTiles();
};

// @fnv 0x007228f0
// src: COMMUNITY 0x007228f0
void ListBox_007228f0::ListBox_StatsMenu_StatusEffect_FreeAllTiles()
{
    while (this->pNext != 0 && *this->pNext->GetItem() != 0)
    {
        LBNode* pNext = FUN_00726070(this->pNext);
        if (!DAT_011d8909)
        {
            delete (*this->pNext->GetItem())->tile;
        }
        if (this->ListBox_unsigned_int_GetFlag(1))
        {
            delete (*this->pNext->GetItem())->extra;
        }
        delete *this->pNext->GetItem();
        this->pNext->FUN_006ecd40(0);
        delete this->pNext;
        this->pNext = pNext;
    }
    if (this->pItem != 0)
    {
        if (!DAT_011d8909)
        {
            delete this->pItem->tile;
        }
        if (this->ListBox_unsigned_int_GetFlag(1))
        {
            delete this->pItem->extra;
        }
        delete this->pItem;
    }
    this->pItem = 0;
    this->usItemCount = 0;
    this->m_fFirstListValue = 0.0f;
    if (this->m_pListTile != 0)
    {
        this->m_pListTile->Set(Tile_TextToTrait("_num_filtered"), 0.0f, true);
    }
    this->UpdateState_00725970();
    this->unk10 = 0;
    this->UpdateSpeechChallengeTrait();
}

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

// @fnv 0x007230e0
// src: GUESS 0x007230e0 (confidence: low)
void ListBoxClear::ProcessEntries_007230e0()
{
    while (pNext && *pNext->GetItem())
    {
        LBNode* next = FUN_00726070(pNext);
        if (!DAT_011d8909)
            delete (*pNext->GetItem())->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete (*pNext->GetItem())->extra;
        delete *pNext->GetItem();
        pNext->FUN_006ecd40(0);
        delete pNext;
        pNext = next;
    }
    if (pItem)
    {
        if (!DAT_011d8909)
            delete pItem->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete pItem->extra;
        delete pItem;
    }
    pItem = 0;
    usItemCount = 0;
    m_fFirstListValue = 0.0f;
    if (m_pListTile)
        m_pListTile->Set(Tile_TextToTrait("_num_filtered"), 0.0f, true);
    UpdateScrollTraits();
    m_pSelectedTile = 0;
    UpdateHighlightTiles();
}

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

// Maps a navigation key to a scroll delta, finds the matching enabled tile by index, and returns it unless it is already selected.
// @fnv 0x007233b0
Tile* LBKListBox::GetTileByKey(int aiKey)
{
    Tile* pTile = 0;
    int iDelta_ = 0;

    switch (aiKey)
    {
    case 2:
        iDelta_ = 1;
        break;
    case 1:
        iDelta_ = -1;
        break;
    case 15:
        iDelta_ = pParentTile
                      ? (int)FUN_004bd510(
                            -pParentTile->GetFloat(0xfb0) / pParentTile->GetFloat(Tile_TextToTrait("_scroll_delta")), 1.0f)
                      : 0;
        break;
    case 16:
        iDelta_ = pParentTile
                      ? (int)FUN_004bd510(
                            pParentTile->GetFloat(0xfb0) / pParentTile->GetFloat(Tile_TextToTrait("_scroll_delta")), 1.0f)
                      : 0;
        break;
    }

    if (IsEnabled() && iDelta_ && usItemCount)
    {
        int iLast7 = usItemCount - 1;
        int kINew;
        if (pSelected)
        {
            int iCurrent = (int)pSelected->GetFloat(0xfac);
            if ((kINew = iCurrent + iDelta_) < 0)
                kINew = 0;
            else if (kINew > iLast7)
                kINew = iLast7;
        }
        else
        {
            if (iDelta_ > 0)
                kINew = 0;
            else
                kINew = iLast7;
        }

        while (1)
        {
            for (LBKNode* pIter = this; !pTile && pIter && *pIter->GetItem(); pIter = pIter->GetNext())
            {
                if ((*pIter->GetItem())->pTile->GetFloat(0xfac) == kINew)
                    pTile = (*pIter->GetItem())->pTile;
            }
            if (pTile && !pTile->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1)))
            {
                pTile = 0;
                if (iDelta_ > 0 && ++kINew > iLast7)
                {
                    kINew = iLast7 - 1;
                    while ((!pTile || !pTile->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1))) && kINew >= 0)
                        pTile = GetTileByIndex(kINew--, 0);
                    break;
                }
                else if (iDelta_ < 0 && --kINew < 0)
                {
                    kINew = 1;
                    while ((!pTile || !pTile->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1))) && kINew <= iLast7)
                        pTile = GetTileByIndex(kINew++, 0);
                    break;
                }
            }
            else
                break;
        }
    }
    return pTile != pSelected ? pTile : 0;
}

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

// @fnv 0x00723b60
// src: XBOX_PDB 0x00723b60
Tile* ListBoxHelper::ListBox_unsigned_int_GetHighlightTarget(int code)
{
    Tile* delta3 = 0;
    int found = 0;
    int aIdx2;
    int count3;
    int base2;
    ListboxListNodeView* node;

    switch (code)
    {
    case 2:
        found = 1;
        break;
    case 1:
        found = -1;
        break;
    case 15:
        found = m_0c != 0 ? (int)FUN_004bd510((float)((double)-m_0c->FUN_00a011b0(0xfb0) /
                                                      m_0c->FUN_00a011b0(Tile_TextToTrait(str_0106f90c))),
                                              1.0f)
                          : 0;
        break;
    case 16:
        found =
            m_0c != 0
                ? (int)FUN_004bd510(
                      (float)((double)m_0c->FUN_00a011b0(0xfb0) / m_0c->FUN_00a011b0(Tile_TextToTrait(str_0106f90c))), 1.0f)
                : 0;
        break;
    }

    if (ListBox_unsigned_int_IsEnabled() && found != 0 && m_1c != 0)
    {
        count3 = m_1c - 1;
        if (m_10 != 0)
        {
            base2 = (int)m_10->FUN_00a011b0(0xfac);
            aIdx2 = base2 + found;
            if (aIdx2 < 0)
            {
                aIdx2 = 0;
            }
            else if (aIdx2 > count3)
            {
                aIdx2 = count3;
            }
        }
        else
        {
            if (found > 0)
                aIdx2 = 0;
            else
                aIdx2 = count3;
        }

        while (1)
        {
            node = this != 0 ? &head : 0;
            for (; delta3 == 0 && node != 0 && *node->FUN_006815c0() != 0; node = node->FUN_00726070())
            {
                if ((*(Tile**)(*node->FUN_006815c0()))->FUN_00a011b0(0xfac) == (float)aIdx2)
                {
                    delta3 = *(Tile**)(*node->FUN_006815c0());
                }
            }

            if (delta3 != 0 && !((Tile*)delta3)->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1)))
            {
                delta3 = 0;
                if (found > 0 && ++aIdx2 > count3)
                {
                    aIdx2 = count3 - 1;
                    while (
                        (delta3 == 0 || !((Tile*)delta3)->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1))) &&
                        aIdx2 >= 0)
                    {
                        delta3 = GetItemAt(aIdx2--, 0);
                    }
                    break;
                }
                else if (found < 0 && --aIdx2 < 0)
                {
                    aIdx2 = 1;
                    while (
                        (delta3 == 0 || !((Tile*)delta3)->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1))) &&
                        aIdx2 <= count3)
                    {
                        delta3 = GetItemAt(aIdx2++, 0);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    return (delta3 != m_10) ? delta3 : 0;
}

int __cdecl Tile_AddUserTrait(const char*, int);
extern "C" char str_0106f87c[], str_0106f884[], str_0106f88c[], str_0106f894[], str_0106f898[], str_0106f8ac[],
    str_0106f8c0[];
Tile* __cdecl FindNamedTile(Tile*, const char*);
// @fnv 0x007244e0
// src: XBOX_PDB 0x007244e0
void HighlightList_listbox::ListBox_enum_ActorValue_Index_UpdateHighlightBoxPos()
{
    static int index = Tile_AddUserTrait(str_0106f8c0, -1);
    static int value = Tile_AddUserTrait(str_0106f8ac, -1);
    if (container)
    {
        if (selected)
        {
            HighlightValue_listbox* indexValue4 = reinterpret_cast<HighlightValue_listbox*>(container->GetValue(index));
            HighlightValue_listbox* selectedValue6 = reinterpret_cast<HighlightValue_listbox*>(container->GetValue(value));
            indexValue4->Tile_Value_AddRefValueAction(2000, selected, 4002);
            indexValue4->Tile_Value_SetFloat(0);
            selectedValue6->Tile_Value_AddRefValueAction(2000, selected, 4016);
            selectedValue6->Tile_Value_SetFloat(0);
            if (selected->GetSpeechChallengeFailure())
            {
                Tile* failureBox7 = FindNamedTile(container, str_0106f898);
                if (failureBox7)
                {
                    Tile* failureChild3 = failureBox7->GetNamedChild(str_0106f894);
                    if (failureChild3)
                    {
                        failureChild3->SetSpeechChallengeFailure_0071aa60(true);
                        failureChild3->SetImageFlags(8);
                        failureChild3 = failureBox7->GetNamedChild(str_0106f88c);
                        failureChild3->SetSpeechChallengeFailure_0071aa60(true);
                        failureChild3->SetImageFlags(8);
                        failureChild3 = failureBox7->GetNamedChild(str_0106f884);
                        failureChild3->SetSpeechChallengeFailure_0071aa60(true);
                        failureChild3->SetImageFlags(8);
                        failureChild3 = failureBox7->GetNamedChild(str_0106f87c);
                        failureChild3->SetSpeechChallengeFailure_0071aa60(true);
                        failureChild3->SetImageFlags(8);
                    }
                    failureBox7->SetSpeechChallengeFailure_0071aa60(true);
                    failureBox7->SetImageFlags(8);
                }
            }
            else
            {
                Tile* normalBox = FindNamedTile(container, str_0106f898);
                if (normalBox)
                {
                    Tile* normalChild4 = normalBox->GetNamedChild(str_0106f894);
                    if (normalChild4)
                    {
                        normalChild4->SetSpeechChallengeFailure_0071aa60(false);
                        normalChild4->SetImageFlags(8);
                        normalChild4 = normalBox->GetNamedChild(str_0106f88c);
                        normalChild4->SetSpeechChallengeFailure_0071aa60(false);
                        normalChild4->SetImageFlags(8);
                        normalChild4 = normalBox->GetNamedChild(str_0106f884);
                        normalChild4->SetSpeechChallengeFailure_0071aa60(false);
                        normalChild4->SetImageFlags(8);
                        normalChild4 = normalBox->GetNamedChild(str_0106f87c);
                        normalChild4->SetSpeechChallengeFailure_0071aa60(false);
                        normalChild4->SetImageFlags(8);
                    }
                    normalBox->SetSpeechChallengeFailure_0071aa60(false);
                    normalBox->SetImageFlags(8);
                }
            }
        }
        else
        {
            container->Set(index, -1);
            container->Set(value, 0);
        }
    }
}

namespace fnv_00724800 {
float __cdecl FUN_004e4430(float);
int __cdecl BSMAX_00647b70(int, int);
int Tile_TextToTrait(const char*);

struct ListBoxScroll
{
    void* vtable;
    void* pListItem;
    void* pListNext;
    Tile* m_pListTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;
    unsigned int GetItemCount();
    void ListBox_enum_ActorValue_Index_SetTotalListHeight();
};

// @fnv 0x00724800
// src: XBOX_PDB 0x00724800
void ListBoxScroll::ListBox_enum_ActorValue_Index_SetTotalListHeight()
{
    if (m_pListTile)
    {
        int iNumItems2;
        float m_fGlyphExtent = m_pListTile->GetFloat(0xfb0);
        iNumItems2 = 1;
        if (m_fFirstListValue > 0.0 && m_fGlyphExtent > 0.0)
        {
            if (m_fFirstListValue > m_fGlyphExtent)
            {
                iNumItems2 = BSMAX_00647b70(
                    (int)FUN_004e4430((float)GetItemCount() * (m_fFirstListValue - m_fGlyphExtent) / m_fFirstListValue) + 1,
                    2);
            }
            if (iNumItems2 > 1)
            {
                m_pListTile->Set(Tile_TextToTrait("_scroll_delta"), (m_fFirstListValue - m_fGlyphExtent) / (iNumItems2 - 1), true);
            }
        }
        if (m_pHighlightedTile)
        {
            m_pHighlightedTile->Set(Tile_TextToTrait("_number_of_items"), iNumItems2);
        }
    }
}
}  // namespace fnv_00724800

// Sets the selected and index trait tile values, then shows or hides the speech-challenge failure child tiles based on GetSpeechChallengeFailure.
// @fnv 0x00724ab0
void FUN_00724930_cls::UpdateTraitDisplay()
{
    static int selectedTrait = GetTileValueID(str_0106f8c0, -1);
    static int indexTrait = GetTileValueID(str_0106f8ac, -1);
    if (unk0c)
    {
        if (unk10)
        {
            TileValue* selectedValue = reinterpret_cast<TileValue*>(reinterpret_cast<Tile*>(unk0c)->GetValue(selectedTrait));
            TileValue* sVertexIndex = reinterpret_cast<TileValue*>(reinterpret_cast<Tile*>(unk0c)->GetValue(indexTrait));
            ((HighlightValue_listbox*)selectedValue)->Tile_Value_AddRefValueAction(2000, (Tile*)unk10, 4002);
            ((HighlightValue_listbox*)selectedValue)->Tile_Value_SetFloat(0);
            ((HighlightValue_listbox*)sVertexIndex)->Tile_Value_AddRefValueAction(2000, (Tile*)unk10, 4016);
            ((HighlightValue_listbox*)sVertexIndex)->Tile_Value_SetFloat(0);
            if (((Tile*)unk10)->GetSpeechChallengeFailure())
            {
                Tile* parent = FindNamedTile((Tile*)unk0c, str_0106f898);
                if (parent)
                {
                    Tile* child = ((Tile*)parent)->GetNamedChild(str_0106f894);
                    if (child)
                    {
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->SetImageFlags(8);
                        child = ((Tile*)parent)->GetNamedChild(str_0106f88c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->SetImageFlags(8);
                        child = ((Tile*)parent)->GetNamedChild(str_0106f884);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->SetImageFlags(8);
                        child = ((Tile*)parent)->GetNamedChild(str_0106f87c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->SetImageFlags(8);
                    }
                    ((Tile*)parent)->SetSpeechChallengeFailure_0071aa60(true);
                    ((Tile*)parent)->SetImageFlags(8);
                }
            }
            else
            {
                Tile* parent = FindNamedTile((Tile*)unk0c, str_0106f898);
                if (parent)
                {
                    Tile* child = ((Tile*)parent)->GetNamedChild(str_0106f894);
                    if (child)
                    {
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->SetImageFlags(8);
                        child = ((Tile*)parent)->GetNamedChild(str_0106f88c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->SetImageFlags(8);
                        child = ((Tile*)parent)->GetNamedChild(str_0106f884);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->SetImageFlags(8);
                        child = ((Tile*)parent)->GetNamedChild(str_0106f87c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->SetImageFlags(8);
                    }
                    ((Tile*)parent)->SetSpeechChallengeFailure_0071aa60(false);
                    ((Tile*)parent)->SetImageFlags(8);
                }
            }
        }
        else
        {
            ((Tile*)unk0c)->Set(selectedTrait, -1);
            ((Tile*)unk0c)->Set(indexTrait, 0);
        }
    }
}

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

// Resets the count and scroll, assigns sequential indices to visible item tiles, adds them, then sorts tiles and updates the scroll.
// @fnv 0x00724f00
void ListBox724::RefreshTiles()
{
    m_usElementCount = 0;
    m_fScroll = 0.0f;
    for (ItemList724* pkNode = this; pkNode && *pkNode->GetItem(); pkNode = pkNode->GetNext())
    {
        if (!(*pkNode->GetItem())->m_bHidden)
        {
            (*pkNode->GetItem())->m_pkTile->SetInt(0xfac, m_usElementCount++);
            AddTile((*pkNode->GetItem())->m_pkTile);
        }
    }
    SortTiles();
    UpdateScroll();
}

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

// Returns true if m_pkTile exists and its _enabled trait value is set, using a cached trait ID.
// @fnv 0x00724fd0
// src: XBOX_PDB 0x00724fd0
bool C4FD0ListBox::ListBox_enum_MiscStatManager_MiscStatID_IsEnabled()
{
    static int s_iEnabledTrait = C4FD0TraitNameToID("_enabled", -1);
    return m_pkTile && m_pkTile->IsTraitNonZero(s_iEnabledTrait);
}

Tile* __cdecl Tile_GetTileByName(Tile*, const char*);
// Updates the highlight and height values on the container's selected tile and toggles the child box elements based on the selected tile's state.
// @fnv 0x00725080
// src: XBOX_PDB 0x00725080
void HighlightList_listbox::ListBox_enum_MiscStatManager_MiscStatID_UpdateHighlightBoxPos()
{
    static int highlight = Tile_AddUserTrait(str_0106f8c0, -1);
    static int height = Tile_AddUserTrait(str_0106f8ac, -1);
    if (container)
    {
        if (selected)
        {
            HighlightValue_listbox* pHighlightValue = reinterpret_cast<HighlightValue_listbox*>(container->Tile_GetValue(highlight));
            HighlightValue_listbox* value = reinterpret_cast<HighlightValue_listbox*>(container->Tile_GetValue(height));
            pHighlightValue->Tile_Value_AddRefValueAction(2000, (Tile*)selected, 4002);
            pHighlightValue->Tile_Value_SetFloat(0);
            value->Tile_Value_AddRefValueAction(2000, (Tile*)selected, 4016);
            value->Tile_Value_SetFloat(0);
            if (selected->GetSpeechChallengeFailure())
            {
                Tile* box = Tile_GetTileByName(container, str_0106f898);
                if (box)
                {
                    Tile* child = box->GetNamedChild(str_0106f894);
                    if (child)
                    {
                        child->SetSpeechChallengeFailure_0071aa60(true);
                        child->Tile_SetChangeFlag(8);
                        child = box->GetNamedChild(str_0106f88c);
                        child->SetSpeechChallengeFailure_0071aa60(true);
                        child->Tile_SetChangeFlag(8);
                        child = box->GetNamedChild(str_0106f884);
                        child->SetSpeechChallengeFailure_0071aa60(true);
                        child->Tile_SetChangeFlag(8);
                        child = box->GetNamedChild(str_0106f87c);
                        child->SetSpeechChallengeFailure_0071aa60(true);
                        child->Tile_SetChangeFlag(8);
                    }
                    box->SetSpeechChallengeFailure_0071aa60(true);
                    box->Tile_SetChangeFlag(8);
                }
            }
            else
            {
                Tile* box = Tile_GetTileByName(container, str_0106f898);
                if (box)
                {
                    Tile* child = box->GetNamedChild(str_0106f894);
                    if (child)
                    {
                        child->SetSpeechChallengeFailure_0071aa60(false);
                        child->Tile_SetChangeFlag(8);
                        child = box->GetNamedChild(str_0106f88c);
                        child->SetSpeechChallengeFailure_0071aa60(false);
                        child->Tile_SetChangeFlag(8);
                        child = box->GetNamedChild(str_0106f884);
                        child->SetSpeechChallengeFailure_0071aa60(false);
                        child->Tile_SetChangeFlag(8);
                        child = box->GetNamedChild(str_0106f87c);
                        child->SetSpeechChallengeFailure_0071aa60(false);
                        child->Tile_SetChangeFlag(8);
                    }
                    box->SetSpeechChallengeFailure_0071aa60(false);
                    box->Tile_SetChangeFlag(8);
                }
            }
        }
        else
        {
            container->FUN_00700320(highlight, -1);
            container->FUN_00700320(height, 0);
        }
    }
}

struct FUN_007254d0_t
{
    int unk00;
    int unk04;
    int unk08;
    Tile* container;
    Tile* selected;
    void UpdateSpeechChallengeTrait();
};
// @fnv 0x00725650
void FUN_007254d0_t::UpdateSpeechChallengeTrait()
{
    static int selectedTrait = Tile_AddUserTrait(str_0106f8c0, -1);
    static int failedTrait = Tile_AddUserTrait(str_0106f8ac, -1);
    if (container)
    {
        if (selected)
        {
            void* selectedValue = ((Tile*)container)->Tile_GetValue(selectedTrait);
            void* pFailedTraitValue = ((Tile*)container)->Tile_GetValue(failedTrait);
            ((HighlightValue_listbox*)selectedValue)->Tile_Value_AddRefValueAction(0x7d0, selected, 0xfa2);
            ((HighlightValue_listbox*)selectedValue)->Tile_Value_SetFloat(0);
            ((HighlightValue_listbox*)pFailedTraitValue)->Tile_Value_AddRefValueAction(0x7d0, selected, 0xfb0);
            ((HighlightValue_listbox*)pFailedTraitValue)->Tile_Value_SetFloat(0);
            if (((Tile*)selected)->GetSpeechChallengeFailure())
            {
                Tile* parent = FindNamedTile(container, str_0106f898);
                if (parent)
                {
                    Tile* child = ((Tile*)parent)->GetNamedChild(str_0106f894);
                    if (child)
                    {
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)parent)->GetNamedChild(str_0106f88c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)parent)->GetNamedChild(str_0106f884);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)parent)->GetNamedChild(str_0106f87c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                    }
                    ((Tile*)parent)->SetSpeechChallengeFailure_0071aa60(true);
                    ((Tile*)parent)->Tile_SetChangeFlag(8);
                }
            }
            else
            {
                Tile* parent = FindNamedTile(container, str_0106f898);
                if (parent)
                {
                    Tile* child = ((Tile*)parent)->GetNamedChild(str_0106f894);
                    if (child)
                    {
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)parent)->GetNamedChild(str_0106f88c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)parent)->GetNamedChild(str_0106f884);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)parent)->GetNamedChild(str_0106f87c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                    }
                    ((Tile*)parent)->SetSpeechChallengeFailure_0071aa60(false);
                    ((Tile*)parent)->Tile_SetChangeFlag(8);
                }
            }
        }
        else
        {
            ((Tile*)container)->Set(selectedTrait, -1);
            ((Tile*)container)->Set(failedTrait, 0);
        }
    }
}

struct FUN_00725b70_cls
{
    int m_00;
    int m_04;
    int m_08;
    Tile* m_0c;
    bool IsEnabled();
};

int __cdecl Tile_AddUserTrait(const char* s, int n);

// Returns true when m_0c is non-null and its IsTraitNonZero lookup of the static "_enabled" key succeeds.
// @fnv 0x00725b70
// src: GUESS 0x00725b70 (confidence: high)
bool FUN_00725b70_cls::IsEnabled()
{
    static void* sKey = (void*)Tile_AddUserTrait("_enabled", -1);
    return (m_0c != 0 && m_0c->IsTraitNonZero(reinterpret_cast<int>(sKey))) ? 1 : 0;
}

namespace fnv_00726210 {
struct ListBox726210
{
    int unk00;
    int unk04;
    int unk08;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    void ListBox_unsigned_int_UpdateHighlightBoxPos();
};

// @fnv 0x00726210
// src: XBOX_PDB 0x00726210
void ListBox726210::ListBox_unsigned_int_UpdateHighlightBoxPos()
{
    static int traitHighlightY = GetTileValueID(str_0106f8c0, -1);
    static int traitSelectedHeight = GetTileValueID(str_0106f8ac, -1);
    if (m_pListTile != 0)
    {
        if (m_pSelectedTile != 0)
        {
            TileValue* valHighlightY = reinterpret_cast<TileValue*>(m_pListTile->GetValue(traitHighlightY));
            TileValue* valSelectedHeight = reinterpret_cast<TileValue*>(m_pListTile->GetValue(traitSelectedHeight));
            ((HighlightValue_listbox*)valHighlightY)->Tile_Value_AddRefValueAction(2000, m_pSelectedTile, 4002);
            ((HighlightValue_listbox*)valHighlightY)->Tile_Value_SetFloat(0);
            ((HighlightValue_listbox*)valSelectedHeight)->Tile_Value_AddRefValueAction(2000, m_pSelectedTile, 4016);
            ((HighlightValue_listbox*)valSelectedHeight)->Tile_Value_SetFloat(0);
            if (((Tile*)m_pSelectedTile)->GetSpeechChallengeFailure())
            {
                Tile* box = FindNamedTile(m_pListTile, str_0106f898);
                if (box != 0)
                {
                    Tile* child = ((Tile*)box)->GetNamedChild(str_0106f894);
                    if (child != 0)
                    {
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)box)->GetNamedChild(str_0106f88c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)box)->GetNamedChild(str_0106f884);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)box)->GetNamedChild(str_0106f87c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                    }
                    ((Tile*)box)->SetSpeechChallengeFailure_0071aa60(true);
                    ((Tile*)box)->Tile_SetChangeFlag(8);
                }
            }
            else
            {
                Tile* box = FindNamedTile(m_pListTile, str_0106f898);
                if (box != 0)
                {
                    Tile* child = ((Tile*)box)->GetNamedChild(str_0106f894);
                    if (child != 0)
                    {
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)box)->GetNamedChild(str_0106f88c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)box)->GetNamedChild(str_0106f884);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)box)->GetNamedChild(str_0106f87c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                    }
                    ((Tile*)box)->SetSpeechChallengeFailure_0071aa60(false);
                    ((Tile*)box)->Tile_SetChangeFlag(8);
                }
            }
        }
        else
        {
            ((Tile*)m_pListTile)->Set(traitHighlightY, -1);
            ((Tile*)m_pListTile)->Set(traitSelectedHeight, 0);
        }
    }
}
}  // namespace fnv_00726210

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

// Sets the tile's _y to fTotalHeight, measures the child text tile's height if unset, stores it in trait 0xfb0 and adds it to fTotalHeight.
// @fnv 0x007269d0
void VLList::AccumulateTileHeight(Tile* apTile)
{
    float fHeight4 = 0.0f;
    apTile->SetFloat(VLTraitNameToID("_y", -1), fTotalHeight, true);
    fHeight4 = apTile->GetFloat(0xfb0);
    if (fHeight4 == 0.0)
    {
        Tile* pText = 0;
        VLListNode* pPosVal = reinterpret_cast<VLTileList*>(&apTile->m_kChildTileList)->GetHeadPos();
        while (pPosVal && !pText)
        {
            Tile* pChild2 = reinterpret_cast<VLTileList*>(&apTile->m_kChildTileList)->GetNext(pPosVal);
            if (pChild2->GetType() == 0x387)
                pText = pChild2;
        }
        if (pText)
        {
            float fWrapWidth = pText->GetFloat(0xfba);
            fHeight4 = VLFontManager::Instance()
                           ->GetStringDimensions(pText->GetString(0xfc4), (int)pText->GetFloat(0xfb9),
                                                 (fWrapWidth > 0.0) ? fWrapWidth : 3.402823466e+38F, 0)
                           .y;
            fHeight4 += apTile->GetFloat(VLTraitNameToIDSimple("_VerticalSpacing"));
        }
    }
    apTile->SetFloat(0xfb0, fHeight4, false);
    fTotalHeight += fHeight4;
}

struct Value050
{
    void RemoveFromReactions();
    void Tile_Value_AddRefValueAction(int, Tile*, int);
    void AppendFloatAction(int, float);
    void Tile_Value_SetFloat(int);
};
// Tile's linear lookup at 0x00a00e90 is absent from the shared header; this extension adds only that declaration.
struct LinearTraitLookup : Tile
{
    Value050* FindTraitValue(int);
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
// @fnv 0x00754690
Tile* Owner050::AddListEntry(int data, const char* text, int compare, const char* name)
{
    if (container && (templateName || name))
    {
        Tile* tile = container->GetMenu()->CreateTileFromTemplate(container, name ? name : templateName, 0);
        if (!tile->Tile_GetValue(0xfaa))
            tile->FUN_00700320(0xfaa, -1);
        if (text)
            tile->Tile_Set_00a01350(0xfc4, text, true);
        if (compare)
        {
            entries.BSSimpleList_ActiveEffect_Insert(new FUN_007a62e0(tile, &data), compare);
            if (ListBox_unsigned_int_GetFlag(0))
                ListBox_enum_ActorValue_Index_Synchronize();
        }
        else
        {
            entries.FUN_00905820(new FUN_007a62e0(tile, &data));
            if (ListBox_unsigned_int_GetFlag(0))
            {
                AccumulateTileHeight(tile);
                ListBox_enum_ActorValue_Index_SetTotalListHeight();
            }
            tile->FUN_00700320(0xfac, count++);
        }
        if (GetRaceCount() == 1 && container->FUN_00a011b0(Tile_AddUserTrait(kListBoxNumFiltered, -1)) > 0.0)
        {
            Value050* value = reinterpret_cast<LinearTraitLookup*>(container)->FindTraitValue(0xfb0);
            value->RemoveFromReactions();
            value->Tile_Value_AddRefValueAction(0x7d0, tile, 0xfb0);
            value->AppendFloatAction(0x7d3, container->FUN_00a011b0(Tile_AddUserTrait(kListBoxNumFiltered, -1)));
            value->Tile_Value_SetFloat(0);
        }
        return tile;
    }
    else
        return 0;
}

struct ItemTile;
struct ItemValue
{
    void RemoveFromReactions();
    void Tile_Value_AddRefValueAction(int, ItemTile*, int);
    void AppendFloatAction(int, float);
    void Tile_Value_SetFloat(int);
};
struct ItemMenu
{
    ItemTile* Create(ItemTile*, const char*, int);
};
struct ItemTile
{
    ItemMenu* GetMenu();
    void* GetValue(int);
    void Set(int, int);
    void Set(int, const char*, bool);
    float FUN_00a011b0(int);
    ItemValue* FindTraitValue(int);
};
struct BoxItem
{
    ItemTile* tile;
    int data;
    char flag;
    BoxItem(ItemTile*, int*);
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
    ItemTile* container;
    int unk10;
    int unk14;
    const char* templateName;
    unsigned short nextIndex;
    bool ListBox_unsigned_int_GetFlag(unsigned int);
    void Synchronize();
    void AccumulateTileHeight(ItemTile*);
    void Update();
    int __thiscall Count();
    ItemTile* ListBox_int_AddItem(int, const char*, int(__cdecl*)(BoxItem*, BoxItem*), const char*);
};
// @fnv 0x00764430
// src: XBOX_PDB 0x00764430
ItemTile* IntListBox::ListBox_int_AddItem(int data, const char* text, int(__cdecl* compare)(BoxItem*, BoxItem*),
                                   const char* name)
{
    if (container && (templateName || name))
    {
        ItemTile* tile_2 = container->GetMenu()->Create(container, name ? name : templateName, 0);
        ItemValue* value;
        if (!tile_2->GetValue(0xfaa))
            tile_2->Set(0xfaa, -1);
        if (text)
            tile_2->Set(0xfc4, text, true);
        if (compare)
        {
            items.InsertSorted(new BoxItem(tile_2, &data), compare);
            if (ListBox_unsigned_int_GetFlag(0))
                Synchronize();
        }
        else
        {
            items.AppendItem(new BoxItem(tile_2, &data));
            if (ListBox_unsigned_int_GetFlag(0))
            {
                AccumulateTileHeight(tile_2);
                Update();
            }
            tile_2->Set(0xfac, nextIndex++);
        }
        if (Count() == 1 && container->FUN_00a011b0(Tile_AddUserTrait(str_0106f860, -1)) > 0.0)
        {
            value = container->FindTraitValue(0xfb0);
            value->RemoveFromReactions();
            value->Tile_Value_AddRefValueAction(0x7d0, tile_2, 0xfb0);
            value->AppendFloatAction(0x7d3, container->FUN_00a011b0(Tile_AddUserTrait(str_0106f860, -1)));
            value->Tile_Value_SetFloat(0);
        }
        return tile_2;
    }
    else
        return 0;
}

extern bool DAT_011d8909;
extern "C" char str_0106f8d0[];
int Tile_TextToTrait(const char*);
struct ClearTileExtraPair
{
    Tile* tile;
    InventoryStackRecord* extra;
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
// @fnv 0x007646d0
// src: XBOX_PDB 0x007646d0
void ClearOwner::ListBox_int_RemoveAll()
{
    while (next && *next->FUN_006815c0())
    {
        ClearNode* following = next->FUN_00726070();
        if (!DAT_011d8909)
            delete (*next->FUN_006815c0())->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete (*next->FUN_006815c0())->extra;
        delete *next->FUN_006815c0();
        next->FUN_006ecd40(0);
        delete next;
        next = following;
    }
    if (item)
    {
        if (!DAT_011d8909)
            delete item->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete item->extra;
        delete item;
    }
    item = 0;
    count = 0;
    height = 0.0f;
    if (container)
        container->Set(Tile_TextToTrait(str_0106f8d0), 0.0f, true);
    ResetScroll();
    selection = 0;
    Refresh();
}

class C764930Tile
{
  public:
    void SetInt(int m_uiSoundID, int iValue);
};

struct C764930Item
{
    C764930Tile* m_pkTile;
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
    void AddTile(C764930Tile* pkTile);
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

// Resets the visible count and scroll, adds each non-hidden item's tile with its index, then updates the scroll bar and selection.
// @fnv 0x00764930
void C764930ListMenu::RebuildVisibleTiles()
{
    m_usNumVisible = 0;
    m_fScroll = 0.0f;
    for (C764930ListNode* pkNode = this; pkNode && pkNode->GetItem(); pkNode = pkNode->GetNext())
    {
        if (!pkNode->GetItem()->m_bHidden)
        {
            pkNode->GetItem()->m_pkTile->SetInt(0xfac, m_usNumVisible++);
            AddTile(pkNode->GetItem()->m_pkTile);
        }
    }
    UpdateScrollBar();
    UpdateSelection();
}

struct Cls_764ef0
{
    int unk00;
    int unk04;
    int unk08;
    Tile* highlightTile;
    Tile* selectedTile;

    void __thiscall UpdateHighlightTile();
};

// @fnv 0x00764ef0
void Cls_764ef0::UpdateHighlightTile()
{
    static int trait1 = Tile_AddUserTrait(str_0106f8c0, -1);
    static int trait2 = Tile_AddUserTrait(str_0106f8ac, -1);

    if (highlightTile)
    {
        if (selectedTile)
        {
            TileValue* val1 = reinterpret_cast<TileValue*>(highlightTile->GetValue(trait1));
            TileValue* val2 = reinterpret_cast<TileValue*>(highlightTile->GetValue(trait2));
            ((HighlightValue_listbox*)val1)->Tile_Value_AddRefValueAction(0x7d0, selectedTile, 0xfa2);
            ((HighlightValue_listbox*)val1)->Tile_Value_SetFloat(0);
            ((HighlightValue_listbox*)val2)->Tile_Value_AddRefValueAction(0x7d0, selectedTile, 0xfb0);
            ((HighlightValue_listbox*)val2)->Tile_Value_SetFloat(0);
            if (((Tile*)selectedTile)->GetSpeechChallengeFailure())
            {
                Tile* box1 = FindNamedTile(highlightTile, str_0106f898);
                if (box1)
                {
                    Tile* child1 = ((Tile*)box1)->GetNamedChild(str_0106f894);
                    if (child1)
                    {
                        ((Tile*)child1)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child1)->SetImageFlags(8);
                        child1 = ((Tile*)box1)->GetNamedChild(str_0106f88c);
                        ((Tile*)child1)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child1)->SetImageFlags(8);
                        child1 = ((Tile*)box1)->GetNamedChild(str_0106f884);
                        ((Tile*)child1)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child1)->SetImageFlags(8);
                        child1 = ((Tile*)box1)->GetNamedChild(str_0106f87c);
                        ((Tile*)child1)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child1)->SetImageFlags(8);
                    }
                    ((Tile*)box1)->SetSpeechChallengeFailure_0071aa60(true);
                    ((Tile*)box1)->SetImageFlags(8);
                }
            }
            else
            {
                Tile* box2 = FindNamedTile(highlightTile, str_0106f898);
                if (box2)
                {
                    Tile* child2 = ((Tile*)box2)->GetNamedChild(str_0106f894);
                    if (child2)
                    {
                        ((Tile*)child2)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child2)->SetImageFlags(8);
                        child2 = ((Tile*)box2)->GetNamedChild(str_0106f88c);
                        ((Tile*)child2)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child2)->SetImageFlags(8);
                        child2 = ((Tile*)box2)->GetNamedChild(str_0106f884);
                        ((Tile*)child2)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child2)->SetImageFlags(8);
                        child2 = ((Tile*)box2)->GetNamedChild(str_0106f87c);
                        ((Tile*)child2)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child2)->SetImageFlags(8);
                    }
                    ((Tile*)box2)->SetSpeechChallengeFailure_0071aa60(false);
                    ((Tile*)box2)->SetImageFlags(8);
                }
            }
        }
        else
        {
            ((Tile*)highlightTile)->Set(trait1, -1);
            ((Tile*)highlightTile)->Set(trait2, 0);
        }
    }
}

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
// Computes a scrollbar height from total and container count, stores the scroll delta on the container and the item count on the scrollbar.
// @fnv 0x00765210
// src: XBOX_PDB 0x00765210
void ScrollList::ListBox_int_SetTotalListHeight()
{
    if (container)
    {
        float count = container->FUN_00a011b0(0xfb0);
        int height = 1;
        if (total > 0.0 && count > 0.0)
        {
            if (total > count)
            {
                height = BSMAX_00647b70((int)FUN_004e4430(GetUnfilteredCount() * (total - count) / total) + 1, 2);
            }
            if (height > 1)
            {
                container->Set(Tile_TextToTrait("_scroll_delta"), (total - count) / (height - 1), true);
            }
        }
        if (scrollbar)
        {
            scrollbar->FUN_00700320(Tile_TextToTrait("_number_of_items"), height);
        }
    }
}

namespace fnv_007a2070 {
extern "C" bool s_bAllowDetach;

struct ClearTilePayloadPair
{
    Tile* tile;
    InventoryStackRecord* payload;
};
struct ClearNode
{
    ClearTilePayloadPair** FUN_006815c0();
    ClearNode* FUN_00726070();
    void FUN_006ecd40(int value);
    ~ClearNode();
};
struct ClearList
{
    int unk00;
    ClearTilePayloadPair* head;
    ClearNode* tail;
    Tile* container;
    void* selected;
    void* scrollBar;
    const char* templateName;
    unsigned short count;
    float scrollPosition;
    bool ListBox_unsigned_int_GetFlag(unsigned int flags);
    void UpdateScrollTraits_007a6920();
    void UpdateHighlightTraits_007a6600();
    void ReleaseStorage_007a2070();
};

// @fnv 0x007a2070
// src: GUESS 0x007a2070 (confidence: low)
void ClearList::ReleaseStorage_007a2070()
{
    while (tail && *tail->FUN_006815c0())
    {
        ClearNode* next = tail->FUN_00726070();
        if (!s_bAllowDetach)
            delete (*tail->FUN_006815c0())->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete (*tail->FUN_006815c0())->payload;
        delete *tail->FUN_006815c0();
        tail->FUN_006ecd40(0);
        delete tail;
        tail = next;
    }
    if (head)
    {
        if (!s_bAllowDetach)
            delete head->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete head->payload;
        delete head;
    }
    head = 0;
    count = 0;
    scrollPosition = 0.0f;
    if (container)
        container->Set(Tile_TextToTrait("_num_filtered"), 0.0f, true);
    UpdateScrollTraits_007a6920();
    selected = 0;
    UpdateHighlightTraits_007a6600();
}
}  // namespace fnv_007a2070

namespace fnv_007a2450 {
struct NavigationRow
{
    Tile* tile;
};
struct NavigationLink
{
    NavigationRow* row;
    NavigationLink* next;
    NavigationRow** FUN_006815c0();
    NavigationLink* FUN_00726070();
};
struct NavigationVirtual
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual Tile* GetTile(unsigned int index, bool scroll);
};
int Tile_TextToTrait(const char* name);
int Tile_AddUserTrait(const char* name, int fallback);
float FUN_004bd510(float value, float step);
struct NavigationList : NavigationVirtual, NavigationLink
{
    Tile* container;
    Tile* selected;
    unsigned int unk14, unk18;
    unsigned short count, unk1e;
    bool HasEnabledTrait();
    Tile* GetNavigationTileForEvent(unsigned int event);
};

// Maps a navigation event to a scroll delta, finds the tile at the resulting index that is enabled, and returns it unless it equals selected.
// @fnv 0x007a2450
Tile* NavigationList::GetNavigationTileForEvent(unsigned int event)
{
    Tile* foundVal = 0;
    int delta8 = 0;
    switch (event)
    {
    case 2:
        delta8 = 1;
        break;
    case 1:
        delta8 = -1;
        break;
    case 15:
        delta8 = container ? (int)FUN_004bd510(-container->FUN_00a011b0(0xfb0) /
                                                   container->FUN_00a011b0(Tile_TextToTrait("_scroll_delta")),
                                               1.0f)
                           : 0;
        break;
    case 16:
        delta8 = container ? (int)FUN_004bd510(container->FUN_00a011b0(0xfb0) /
                                                   container->FUN_00a011b0(Tile_TextToTrait("_scroll_delta")),
                                               1.0f)
                           : 0;
        break;
    }
    if (HasEnabledTrait() && delta8 && count)
    {
        int maximumTmp = count - 1;
        int index;
        if (selected)
        {
            int current5 = (int)selected->FUN_00a011b0(0xfac);
            index = current5 + delta8;
            if (index < 0)
                index = 0;
            else if (index > maximumTmp)
                index = maximumTmp;
        }
        else if (delta8 > 0)
        {
            index = 0;
        }
        else
        {
            index = maximumTmp;
        }
        while (true)
        {
            for (NavigationLink* link = static_cast<NavigationLink*>(this); !foundVal && link && *link->FUN_006815c0();
                 link = link->FUN_00726070())
            {
                if ((*link->FUN_006815c0())->tile->FUN_00a011b0(0xfac) == index)
                    foundVal = (*link->FUN_006815c0())->tile;
            }
            if (foundVal && !foundVal->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1)))
            {
                foundVal = 0;
                if (delta8 > 0 && ++index > maximumTmp)
                {
                    index = maximumTmp - 1;
                    while ((!foundVal || !foundVal->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1))) && index >= 0)
                    {
                        foundVal = GetTile(index--, false);
                    }
                    break;
                }
                else if (delta8 < 0 && --index < 0)
                {
                    index = 1;
                    while ((!foundVal || !foundVal->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1))) &&
                           index <= maximumTmp)
                    {
                        foundVal = GetTile(index++, false);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return foundVal != selected ? foundVal : 0;
}
}  // namespace fnv_007a2450

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

// @fnv 0x007a3ac0
// src: GUESS 0x007a3ac0 (confidence: low)
void FUN_007a3ac0_ListBox::ProcessEntries_007a3ac0()
{
    while (pNext && *pNext->GetItem())
    {
        LBNode* pListNode = FUN_00726070(pNext);
        if (!DAT_011d8909)
            delete (*pNext->GetItem())->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete (*pNext->GetItem())->extra;
        delete *pNext->GetItem();
        pNext->FUN_006ecd40(0);
        delete pNext;
        pNext = pListNode;
    }

    if (pItem)
    {
        if (!DAT_011d8909)
            delete pItem->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete pItem->extra;
        delete pItem;
    }
    pItem = 0;

    usItemCount = 0;
    m_fFirstListValue = 0.0f;
    if (m_pListTile)
        m_pListTile->Set(Tile_TextToTrait("_num_filtered"), 0.0f, true);
    UpdateScrollTraits_007a7700();
    unk10 = 0;
    UpdateHighlightTraits_007a73e0();
}

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
// @fnv 0x007a4000
// src: GUESS 0x007a4000 (confidence: low)
Tile* Navigation::ProcessEntries_007a4000(int key)
{
    Tile* result = 0;
    int delta = 0;
    switch (key)
    {
    case 2:
        delta = 1;
        break;
    case 1:
        delta = -1;
        break;
    case 15:
        delta =
            container ? (int)RoundStep(-container->GetFloat(0xfb0) / container->GetFloat(Trait("_scroll_delta"))) : 0;
        break;
    case 16:
        delta =
            container ? (int)RoundStep(container->GetFloat(0xfb0) / container->GetFloat(Trait("_scroll_delta"))) : 0;
        break;
    }
    if (Active() && delta && count)
    {
        int maximum = count - 1;
        int index;
        if (selected)
        {
            int current = (int)selected->GetFloat(0xfac);
            index = current + delta;
            if (index < 0)
                index = 0;
            else if (index > maximum)
                index = maximum;
        }
        else if (delta > 0)
            index = 0;
        else
            index = maximum;
        while (true)
        {
            NavNode* node;
            for (node = this ? &items : 0; !result && node && *node->GetItem(); node = node->Next())
            {
                if ((*node->GetItem())->tile->GetFloat(0xfac) == index)
                    result = (*node->GetItem())->tile;
            }
            if (result && !result->IsTraitNonZero(UserTrait("_enabled", -1)))
            {
                result = 0;
                if (delta > 0 && ++index > maximum)
                {
                    index = maximum - 1;
                    while ((!result || !result->IsTraitNonZero(UserTrait("_enabled", -1))) && index >= 0)
                    {
                        result = At(index--, false);
                    }
                    break;
                }
                else if (delta < 0 && --index < 0)
                {
                    index = 1;
                    while ((!result || !result->IsTraitNonZero(UserTrait("_enabled", -1))) && index <= maximum)
                    {
                        result = At(index++, false);
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    return result != selected ? result : 0;
}

namespace fnv_007a54d0 {
struct ClearTileExtraPair
{
    Tile* tile;
    InventoryStackRecord* extra;
};
struct ClearNode
{
    ClearTileExtraPair** FUN_006815c0();
    ClearNode* FUN_00726070();
    void FUN_006ecd40(unsigned int flags);
    ~ClearNode();
};
struct ClearListBox
{
    void* vtable;
    ClearTileExtraPair* item;
    ClearNode* next;
    Tile* container;
    void* selected;
    void* scrollbar;
    const char* templateName;
    unsigned short itemCount;
    float totalHeight;
    bool ListBox_unsigned_int_GetFlag(unsigned int flags);
    void ListBox_TESChallenge_SetTotalListHeight();
    void UpdateHighlight();
    void ReleaseStorage_007a54d0();
};
// @fnv 0x007a54d0
// src: GUESS 0x007a54d0 (confidence: low)
void ClearListBox::ReleaseStorage_007a54d0()
{
    while (next && *next->FUN_006815c0())
    {
        ClearNode* following = next->FUN_00726070();
        if (!DAT_011d8909)
            delete (*next->FUN_006815c0())->tile;
        if (ListBox_unsigned_int_GetFlag(1))
        {
            delete (*next->FUN_006815c0())->extra;
        }
        delete *next->FUN_006815c0();
        next->FUN_006ecd40(0);
        delete next;
        next = following;
    }
    if (item)
    {
        if (!DAT_011d8909)
            delete item->tile;
        if (ListBox_unsigned_int_GetFlag(1))
        {
            delete item->extra;
        }
        delete item;
    }
    item = 0;
    itemCount = 0;
    totalHeight = 0.0f;
    if (container)
        container->Tile_Set(Tile_TextToTrait("_num_filtered"), 0.0f, true);
    ListBox_TESChallenge_SetTotalListHeight();
    selected = 0;
    UpdateHighlight();
}
}  // namespace fnv_007a54d0

namespace fnv_007a5ad0 {
struct NavItem
{
    Tile* tile;
};
struct NavNode
{
    NavItem* item;
    NavNode* next;
    NavItem** GetItem();
    NavNode* GetNext();
};
int Tile_AddUserTrait(const char*, int);
int Tile_TextToTrait(const char*);
double RoundStep(float, float);
struct NavList : NavNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Tile* GetAt(unsigned int, bool);
    Tile* container;
    Tile* selected;
    int scrollbar;
    int templateName;
    unsigned short count;
    bool CanNavigate();
    Tile* GetNavigationTarget(int action);
};
// @fnv 0x007a5ad0
Tile* NavList::GetNavigationTarget(int action)
{
    Tile* result = 0;
    int delta = 0;
    switch (action)
    {
    case 2:
        delta = 1;
        break;
    case 1:
        delta = -1;
        break;
    case 15:
        delta =
            container
                ? (int)RoundStep(
                      (float)(-container->GetFloat(0xfb0) / container->GetFloat(Tile_TextToTrait("_scroll_delta"))), 1.0f)
                : 0;
        break;
    case 16:
        delta =
            container
                ? (int)RoundStep(
                      (float)(container->GetFloat(0xfb0) / container->GetFloat(Tile_TextToTrait("_scroll_delta"))), 1.0f)
                : 0;
        break;
    }
    if (CanNavigate() && delta && count)
    {
        int maxIndex = count - 1;
        int index;
        if (selected)
        {
            int oldIndex = (int)selected->GetFloat(0xfac);
            index = oldIndex + delta;
            if (index < 0)
                index = 0;
            else if (index > maxIndex)
                index = maxIndex;
        }
        else if (delta > 0)
            index = 0;
        else
            index = maxIndex;
        while (true)
        {
            for (NavNode* node = static_cast<NavNode*>(this); !result && node && *node->GetItem();
                 node = node->GetNext())
            {
                if ((*node->GetItem())->tile->GetFloat(0xfac) == index)
                    result = (*node->GetItem())->tile;
            }
            if (result && !result->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1)))
            {
                result = 0;
                if (delta > 0 && ++index > maxIndex)
                {
                    index = maxIndex - 1;
                    while ((!result || !result->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1))) && index >= 0)
                    {
                        result = GetAt(index--, false);
                    }
                    break;
                }
                else if (delta < 0 && --index < 0)
                {
                    index = 1;
                    while ((!result || !result->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1))) && index <= maxIndex)
                    {
                        result = GetAt(index++, false);
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    return result != selected ? result : 0;
}
}  // namespace fnv_007a5ad0

void FNV_Warning(const char*);
// @fnv 0x007a5e70
// src: COMMUNITY 0x007a5e70
void HighlightList_listbox::ListBox_ItemChange_ScrollToHighlight()
{
    if (selected && (*reinterpret_cast<HighlightTile_listbox**>(reinterpret_cast<char*>(this) + sizeof(HighlightList_listbox))) && container && reinterpret_cast<HighlightTile_listbox*>(container)->FUN_00a011b0(0xfb0) > 0.0)
    {
        bool above = reinterpret_cast<HighlightTile_listbox*>(selected)->FUN_00a011b0(0xfa2) < 0.0;
        bool changed = reinterpret_cast<HighlightTile_listbox*>(selected)->FUN_00a011b0(0xfa2) + reinterpret_cast<HighlightTile_listbox*>(selected)->FUN_00a011b0(0xfb0) > reinterpret_cast<HighlightTile_listbox*>(container)->FUN_00a011b0(0xfb0);
        bool below = above || changed;
        while (reinterpret_cast<HighlightTile_listbox*>(selected)->FUN_00a011b0(0xfac) >= 0.0 && (above || changed))
        {
            int previous = above ? -1 : 1;
            float direction = (*reinterpret_cast<HighlightTile_listbox**>(reinterpret_cast<char*>(this) + sizeof(HighlightList_listbox)))->FUN_00a011b0(Tile_TextToTrait("_current_value"));
            (*reinterpret_cast<HighlightTile_listbox**>(reinterpret_cast<char*>(this) + sizeof(HighlightList_listbox)))->Tile_Set(Tile_TextToTrait("_current_value"), direction + previous, false);
            if (direction == (*reinterpret_cast<HighlightTile_listbox**>(reinterpret_cast<char*>(this) + sizeof(HighlightList_listbox)))->FUN_00a011b0(Tile_TextToTrait("_current_value")))
            {
                FNV_Warning(
                    "MENUS: The scrollbar update in ScrollToHighlight() has hit an infinite loop trying to scroll to an impossible value.");
                break;
            }
            above = reinterpret_cast<HighlightTile_listbox*>(selected)->FUN_00a011b0(0xfa2) < 0.0;
            changed = reinterpret_cast<HighlightTile_listbox*>(selected)->FUN_00a011b0(0xfa2) + reinterpret_cast<HighlightTile_listbox*>(selected)->FUN_00a011b0(0xfb0) > reinterpret_cast<HighlightTile_listbox*>(container)->FUN_00a011b0(0xfb0);
        }
        if (below)
            (*reinterpret_cast<HighlightTile_listbox**>(reinterpret_cast<char*>(this) + sizeof(HighlightList_listbox)))->SetTraitAndReset(Tile_TextToTrait("_SetInCode"), 1.0f);
    }
}

struct ListBox_7a6600
{
    int unk00;
    int unk04;
    int unk08;
    Tile* highlightTile;
    Tile* selectedTile;

    void __thiscall UpdateHighlightTraits_007a6600();
};

// Applies trait values to the highlight tile and shows or hides the speech-challenge box and its children based on the selected tile's speech challenge failure.
// @fnv 0x007a6600
// src: GUESS 0x007a6600 (confidence: medium)
void ListBox_7a6600::UpdateHighlightTraits_007a6600()
{
    static int trait1 = Tile_AddUserTrait(str_0106f8c0, -1);
    static int trait2 = Tile_AddUserTrait(str_0106f8ac, -1);

    if (highlightTile)
    {
        if (selectedTile)
        {
            TileValue* val1 = reinterpret_cast<TileValue*>(highlightTile->GetValue(trait1));
            TileValue* val2 = reinterpret_cast<TileValue*>(highlightTile->GetValue(trait2));
            ((HighlightValue_listbox*)val1)->Tile_Value_AddRefValueAction(0x7d0, selectedTile, 0xfa2);
            ((HighlightValue_listbox*)val1)->Tile_Value_SetFloat(0);
            ((HighlightValue_listbox*)val2)->Tile_Value_AddRefValueAction(0x7d0, selectedTile, 0xfb0);
            ((HighlightValue_listbox*)val2)->Tile_Value_SetFloat(0);

            if (((Tile*)selectedTile)->GetSpeechChallengeFailure())
            {
                Tile* box1 = FindNamedTile(highlightTile, str_0106f898);
                if (box1)
                {
                    Tile* child1 = ((Tile*)box1)->GetNamedChild(str_0106f894);
                    if (child1)
                    {
                        ((Tile*)child1)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child1)->SetImageFlags(8);
                        child1 = ((Tile*)box1)->GetNamedChild(str_0106f88c);
                        ((Tile*)child1)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child1)->SetImageFlags(8);
                        child1 = ((Tile*)box1)->GetNamedChild(str_0106f884);
                        ((Tile*)child1)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child1)->SetImageFlags(8);
                        child1 = ((Tile*)box1)->GetNamedChild(str_0106f87c);
                        ((Tile*)child1)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child1)->SetImageFlags(8);
                    }
                    ((Tile*)box1)->SetSpeechChallengeFailure_0071aa60(true);
                    ((Tile*)box1)->SetImageFlags(8);
                }
            }
            else
            {
                Tile* box2 = FindNamedTile(highlightTile, str_0106f898);
                if (box2)
                {
                    Tile* child2 = ((Tile*)box2)->GetNamedChild(str_0106f894);
                    if (child2)
                    {
                        ((Tile*)child2)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child2)->SetImageFlags(8);
                        child2 = ((Tile*)box2)->GetNamedChild(str_0106f88c);
                        ((Tile*)child2)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child2)->SetImageFlags(8);
                        child2 = ((Tile*)box2)->GetNamedChild(str_0106f884);
                        ((Tile*)child2)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child2)->SetImageFlags(8);
                        child2 = ((Tile*)box2)->GetNamedChild(str_0106f87c);
                        ((Tile*)child2)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child2)->SetImageFlags(8);
                    }
                    ((Tile*)box2)->SetSpeechChallengeFailure_0071aa60(false);
                    ((Tile*)box2)->SetImageFlags(8);
                }
            }
        }
        else
        {
            ((Tile*)highlightTile)->Set(trait1, -1);
            ((Tile*)highlightTile)->Set(trait2, 0);
        }
    }
}

namespace fnv_007a6920 {
struct ScrollList
{
    unsigned int unk00, unk04, unk08;
    Tile* container;
    unsigned int unk10;
    Tile* scrollbar;
    unsigned int unk18, unk1c;
    float totalHeight;
    unsigned int GetUnfilteredRaceCount_007a86e0();
    void UpdateScrollTraits_007a6920();
};
// Computes a scroll step from totalHeight and the container's count, applies it via _scroll_delta, and sets _number_of_items on the scrollbar.
// @fnv 0x007a6920
// src: GUESS 0x007a6920 (confidence: medium)
void ScrollList::UpdateScrollTraits_007a6920()
{
    if (container)
    {
        float count = container->FUN_00a011b0(0xfb0);
        int height = 1;
        if (totalHeight > 0.0 && count > 0.0)
        {
            if (totalHeight > count)
                height = BSMAX_00647b70((int)FUN_004e4430(GetUnfilteredRaceCount_007a86e0() * (totalHeight - count) / totalHeight) + 1, 2);
            if (height > 1)
                container->Tile_Set(Tile_TextToTrait("_scroll_delta"), (totalHeight - count) / (height - 1), true);
        }
        if (scrollbar)
            scrollbar->FUN_00700320(Tile_TextToTrait("_number_of_items"), height);
    }
}
}  // namespace fnv_007a6920

// Binds the highlight and selected-height traits to the selected tile and toggles the lb_highlight_box borders based on the speech challenge failure state.
// @fnv 0x007a73e0
// src: GUESS 0x007a73e0 (confidence: medium)
void HighlightList_listbox::UpdateHighlightTraits_007a73e0()
{
    static int highlightY = Tile_AddUserTrait("_highlight_y", -1);
    static int selectedHeight = Tile_AddUserTrait("_selected_height", -1);
    if (container)
    {
        if (selected)
        {
            HighlightValue_listbox* height = reinterpret_cast<HighlightValue_listbox*>(container->Tile_GetValue(highlightY));
            HighlightValue_listbox* y = reinterpret_cast<HighlightValue_listbox*>(container->Tile_GetValue(selectedHeight));
            height->Tile_Value_AddRefValueAction(2000, selected, 4002);
            height->Tile_Value_SetFloat(0);
            y->Tile_Value_AddRefValueAction(2000, selected, 4016);
            y->Tile_Value_SetFloat(0);
            if (selected->GetSpeechChallengeFailure())
            {
                Tile* box = (Tile*)FindNamedTile((Tile*)container, "lb_highlight_box");
                if (box)
                {
                    Tile* child = box->GetNamedChild("top");
                    if (child)
                    {
                        child->SetSpeechChallengeFailure_0071aa60(true);
                        child->Tile_SetChangeFlag(8);
                        child = box->GetNamedChild("bottom");
                        child->SetSpeechChallengeFailure_0071aa60(true);
                        child->Tile_SetChangeFlag(8);
                        child = box->GetNamedChild("left");
                        child->SetSpeechChallengeFailure_0071aa60(true);
                        child->Tile_SetChangeFlag(8);
                        child = box->GetNamedChild("right");
                        child->SetSpeechChallengeFailure_0071aa60(true);
                        child->Tile_SetChangeFlag(8);
                    }
                    box->SetSpeechChallengeFailure_0071aa60(true);
                    box->Tile_SetChangeFlag(8);
                }
            }
            else
            {
                Tile* box = (Tile*)FindNamedTile((Tile*)container, "lb_highlight_box");
                if (box)
                {
                    Tile* child = box->GetNamedChild("top");
                    if (child)
                    {
                        child->SetSpeechChallengeFailure_0071aa60(false);
                        child->Tile_SetChangeFlag(8);
                        child = box->GetNamedChild("bottom");
                        child->SetSpeechChallengeFailure_0071aa60(false);
                        child->Tile_SetChangeFlag(8);
                        child = box->GetNamedChild("left");
                        child->SetSpeechChallengeFailure_0071aa60(false);
                        child->Tile_SetChangeFlag(8);
                        child = box->GetNamedChild("right");
                        child->SetSpeechChallengeFailure_0071aa60(false);
                        child->Tile_SetChangeFlag(8);
                    }
                    box->SetSpeechChallengeFailure_0071aa60(false);
                    box->Tile_SetChangeFlag(8);
                }
            }
        }
        else
        {
            container->Set(highlightY, -1);
            container->Set(selectedHeight, 0);
        }
    }
}

namespace fnv_007d7290 {
extern bool DAT_011d8909;
struct ClearTileExtraPair
{
    Tile* tile;
    InventoryStackRecord* extra;
};
struct ClearNode
{
    ClearTileExtraPair** FUN_006815c0();
    ClearNode* FUN_00726070();
    void FUN_006ecd40(unsigned int);
    ~ClearNode();
};
int Tile_TextToTrait(const char*);
struct ClearList
{
    int unk00;
    ClearTileExtraPair* item;
    ClearNode* next;
    Tile* container;
    int selected;
    int unk14;
    int unk18;
    unsigned short count;
    float height;
    bool ListBox_unsigned_int_GetFlag(unsigned int);
    void ListBox_StartMenu_Option_SetTotalListHeight();
    void UpdateHighlightBox();
    void ListBox_StartMenu_Option_RemoveAll();
};
// Deletes every node and item in the list, resets count, height and selection, and updates the container's _num_filtered value.
// @fnv 0x007d7290
// src: XBOX_PDB 0x007d7290
void ClearList::ListBox_StartMenu_Option_RemoveAll()
{
    while (next && *next->FUN_006815c0())
    {
        ClearNode* following = next->FUN_00726070();
        if (!DAT_011d8909)
            delete (*next->FUN_006815c0())->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete (*next->FUN_006815c0())->extra;
        delete *next->FUN_006815c0();
        next->FUN_006ecd40(0);
        delete next;
        next = following;
    }
    if (item)
    {
        if (!DAT_011d8909)
            delete item->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete item->extra;
        delete item;
    }
    item = 0;
    count = 0;
    height = 0.0f;
    if (container)
        container->Set(Tile_TextToTrait("_num_filtered"), 0.0f, true);
    ListBox_StartMenu_Option_SetTotalListHeight();
    selected = 0;
    UpdateHighlightBox();
}
}  // namespace fnv_007d7290

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

// Returns true when m_pkTile exists and its _enabled trait bool value is set.
// @fnv 0x007d7580
// src: XBOX_PDB 0x007d7580
bool D7580ListBox::ListBox_StartMenu_Option_IsEnabled()
{
    static int s_iEnabledTrait = D7580TraitNameToID("_enabled", -1);
    return m_pkTile && m_pkTile->IsTraitNonZero(s_iEnabledTrait);
}

namespace fnv_007d7da0 {
void* __cdecl operator new(unsigned int);
struct ItemTile;
struct ItemValue
{
    void Clear();
    void Link(int, ItemTile*, int);
    void SetFloat(int, float);
    void Update(int);
};
struct ItemMenu
{
    ItemTile* Create(ItemTile*, const char*, int);
};
struct ItemTile
{
    ItemMenu* GetMenu();
    ItemValue* GetValue(int);
    void SetInt(int, int);
    void SetString(int, const char*, bool);
    float GetFloat(int);
    ItemValue* GetOrCreate(int);
};
struct BoxEntry
{
    ItemTile* tile;
    int* data;
    char flag;
    BoxEntry(ItemTile*, int*);
};
struct BoxEntries
{
    BoxEntry* item;
    BoxEntries* next;
    void Insert(BoxEntry*, int(__cdecl*)(BoxEntry*, BoxEntry*));
    void AddTail(BoxEntry* const&);
};
extern "C" const char kListBoxNumFiltered[];
int __cdecl Tile_AddUserTrait(const char*, int);
struct ItemBox
{
    int unk00;
    BoxEntries entries;
    ItemTile* container;
    ItemTile* selected;
    ItemTile* scrollbar;
    const char* templateName;
    unsigned short nextIndex;
    bool Test(unsigned int);
    void SortRefresh();
    void Select(ItemTile*);
    void Refresh();
    int GetMode();
    ItemTile* SavesListBox_Insert(int, const char*, int(__cdecl*)(BoxEntry*, BoxEntry*), const char*);
};
// Creates a tile in the container's menu, sets its values, inserts it into entries (sorted or appended), and updates the filtered-count value when in mode 1.
// @fnv 0x007d7da0
// src: COMMUNITY 0x007d7da0
ItemTile* ItemBox::SavesListBox_Insert(int data, const char* text, int(__cdecl* compare)(BoxEntry*, BoxEntry*),
                                const char* name)
{
    if (container && (templateName || name))
    {
        ItemTile* tile = container->GetMenu()->Create(container, name ? name : templateName, 0);
        if (!tile->GetValue(0xfaa))
            tile->SetInt(0xfaa, -1);
        if (text)
            tile->SetString(0xfc4, text, true);
        if (compare)
        {
            entries.Insert(new BoxEntry(tile, &data), compare);
            if (Test(0))
                SortRefresh();
        }
        else
        {
            entries.AddTail(new BoxEntry(tile, &data));
            if (Test(0))
            {
                Select(tile);
                Refresh();
            }
            tile->SetInt(0xfac, nextIndex++);
        }
        if (GetMode() == 1 && container->GetFloat(Tile_AddUserTrait(kListBoxNumFiltered, -1)) > 0.0)
        {
            ItemValue* value = container->GetOrCreate(0xfb0);
            value->Clear();
            value->Link(0x7d0, tile, 0xfb0);
            value->SetFloat(0x7d3, container->GetFloat(Tile_AddUserTrait(kListBoxNumFiltered, -1)));
            value->Update(0);
        }
        return tile;
    }
    else
        return 0;
}
}  // namespace fnv_007d7da0

namespace fnv_007d81f0 {
extern "C" char str_0106f8d0[];
struct ClearNode
{
    LBItem** FUN_006815c0();
    ClearNode* FUN_00726070();
    void FUN_006ecd40(unsigned int value);
    ~ClearNode();
};
struct ClearList
{
    void* vtable;
    LBItem* item;
    ClearNode* next;
    Tile* container;
    void* selected;
    void* scrollbar;
    const char* templateName;
    unsigned short itemCount;
    float totalHeight;
    bool ListBox_unsigned_int_GetFlag(unsigned int flags);
    void ListBox_BGSSaveLoadFileEntry_SetTotalListHeight();
    void ListBox_BGSSaveLoadFileEntry_UpdateHighlightBoxPos();
    void ListBox_BGSSaveLoadFileEntry_RemoveAll();
};
// @fnv 0x007d81f0
// src: XBOX_PDB 0x007d81f0
void ClearList::ListBox_BGSSaveLoadFileEntry_RemoveAll()
{
    while (next && *next->FUN_006815c0())
    {
        ClearNode* following = next->FUN_00726070();
        if (!DAT_011d8909)
            delete (*next->FUN_006815c0())->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete (*next->FUN_006815c0())->extra;
        delete *next->FUN_006815c0();
        next->FUN_006ecd40(0);
        delete next;
        next = following;
    }
    if (item)
    {
        if (!DAT_011d8909)
            delete item->tile;
        if (ListBox_unsigned_int_GetFlag(1))
            delete item->extra;
        delete item;
    }
    item = 0;
    itemCount = 0;
    totalHeight = 0.0f;
    if (container)
        container->Set(Tile_TextToTrait(str_0106f8d0), 0.0f, true);
    ListBox_BGSSaveLoadFileEntry_SetTotalListHeight();
    selected = 0;
    ListBox_BGSSaveLoadFileEntry_UpdateHighlightBoxPos();
}
}  // namespace fnv_007d81f0

extern "C" char str_0106f8d0[];
struct P240Tile
{
    float FUN_00a011b0(int);
    void FUN_00700320(int, int);
    void FUN_00715c60(int, int);
};
struct P240Item
{
    P240Tile* tile;
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
    virtual P240Tile* v5(int, bool);
};
struct P240Owner : P240Base, P240List
{
    P240Tile* container;
    P240Tile* selected;
    P240Tile* scrollbar;
    const char* templateName;
    unsigned short count;
    float height;
    void AccumulateTileHeight(P240Tile*);
    void ListBox_BGSSaveLoadFileEntry_SetTotalListHeight();
    P240Tile* SelectLast();
    void ListBox_BGSSaveLoadFileEntry_UpdateHighlightBoxPos();
    void ApplyFilter(bool(__cdecl* predicate)(void*));
};
// Applies predicate to each list item, hides matches, renumbers visible tiles, updates the container count and reselects a tile.
// @fnv 0x007d8450
void P240Owner::ApplyFilter(bool(__cdecl* predicate)(void*))
{
    int iHiddenCount = 0;
    int iSelectedIndex = -1;
    static int trait = Tile_AddUserTrait(str_0106f8d0, -1);
    count = 0;
    height = 0.0f;
    for (P240List* node = this; node && *node->FUN_006815c0(); node = node->FUN_00726070())
    {
        (*node->FUN_006815c0())->hidden = predicate && predicate((*node->FUN_006815c0())->data);
        if ((*node->FUN_006815c0())->hidden)
        {
            if ((*node->FUN_006815c0())->tile == selected)
            {
                iSelectedIndex = (int)(*node->FUN_006815c0())->tile->FUN_00a011b0(0xfac);
                selected = 0;
            }
            (*node->FUN_006815c0())->tile->FUN_00700320(0xfac, -1);
            ++iHiddenCount;
        }
        else
        {
            if (iSelectedIndex >= 0 && count == iSelectedIndex)
                selected = (*node->FUN_006815c0())->tile;
            (*node->FUN_006815c0())->tile->FUN_00700320(0xfac, count++);
            AccumulateTileHeight((*node->FUN_006815c0())->tile);
        }
    }
    container->FUN_00715c60(trait, iHiddenCount);
    ListBox_BGSSaveLoadFileEntry_SetTotalListHeight();
    if (!selected && iSelectedIndex >= 0)
        selected = v5(iSelectedIndex, false);
    if (!selected && iSelectedIndex >= 0)
        selected = SelectLast();
    ListBox_BGSSaveLoadFileEntry_UpdateHighlightBoxPos();
}

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

// If active and the tile is null or contained and enabled, sets m_pkSelected to the tile, updates the selection and returns true; otherwise returns false.
// @fnv 0x007d8950
// src: GUESS 0x007d8950 (confidence: high)
bool C7D8950ListBox::SetSelectedTileIfEnabled(Tile* pkTile)
{
    if (IsActive() && (!pkTile || (Contains(pkTile) && pkTile->IsTraitNonZero(C7D8950TraitNameToID("_enabled", -1)))))
    {
        m_pkSelected = pkTile;
        UpdateSelection();
        return true;
    }
    else
    {
        return false;
    }
}

namespace fnv_007d89c0 {
float __cdecl FUN_004bd510(float value, float step);
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
    virtual Tile* GetTile(int last, bool select);
};
struct NavigationList : NavigationBase, NavigationNode
{
    Tile* container;
    Tile* selected;
    Tile* scrollbar;
    const char* templateName;
    unsigned short count;
    bool ListBox_BGSSaveLoadFileEntry_IsEnabled();
    Tile* ListBox_BGSSaveLoadFileEntry_HandleKeyboardInput(int direction);
};
// @fnv 0x007d89c0
// src: COMMUNITY 0x007d89c0
Tile* NavigationList::ListBox_BGSSaveLoadFileEntry_HandleKeyboardInput(int direction)
{
    Tile* tile = 0;
    int step = 0;
    switch (direction)
    {
    case 2:
        step = 1;
        break;
    case 1:
        step = -1;
        break;
    case 15:
        step = container
                   ? (int)FUN_004bd510(
                         -container->FUN_00a011b0(0xfb0) / container->FUN_00a011b0(Tile_TextToTrait(str_0106f90c)), 1.0f)
                   : 0;
        break;
    case 16:
        step = container
                   ? (int)FUN_004bd510(
                         container->FUN_00a011b0(0xfb0) / container->FUN_00a011b0(Tile_TextToTrait(str_0106f90c)), 1.0f)
                   : 0;
        break;
    }
    if (ListBox_BGSSaveLoadFileEntry_IsEnabled() && step && count)
    {
        int index = count - 1;
        int last;
        if (selected)
        {
            int current = (int)selected->FUN_00a011b0(0xfac);
            if ((last = current + step) < 0)
                last = 0;
            else if (last > index)
                last = index;
        }
        else
        {
            if (step > 0)
                last = 0;
            else
                last = index;
        }
        while (true)
        {
            for (NavigationNode* node = this; !tile && node && *node->FUN_006815c0(); node = node->FUN_00726070())
            {
                if ((*node->FUN_006815c0())->tile->FUN_00a011b0(0xfac) == last)
                    tile = (*node->FUN_006815c0())->tile;
            }
            if (tile && !tile->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1)))
            {
                tile = 0;
                if (step > 0 && ++last > index)
                {
                    last = index - 1;
                    while ((!tile || !tile->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1))) && last >= 0)
                        tile = GetTile(last--, false);
                    break;
                }
                else if (step < 0 && --last < 0)
                {
                    last = 1;
                    while ((!tile || !tile->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1))) && last <= index)
                        tile = GetTile(last++, false);
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return tile != selected ? tile : 0;
}
}  // namespace fnv_007d89c0

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

// @fnv 0x007d9140
void ListBoxExt::UpdateHighlightBox()
{
    static int s_highlightY = Tile_AddUserTrait("_highlight_y", -1);
    static int s_selectedHeight = Tile_AddUserTrait("_selected_height", -1);

    if (tile0c)
    {
        if (tile10)
        {
            TileValue* valSelectedHeight;
            TileValue* valHighlightY;
            valHighlightY = reinterpret_cast<TileValue*>(tile0c->GetValue(s_highlightY));
            valSelectedHeight = reinterpret_cast<TileValue*>(tile0c->GetValue(s_selectedHeight));
            valHighlightY->Tile_Value_AddRefValueAction(0x7d0, tile10, 0xfa2);
            valHighlightY->Tile_Value_SetFloat(0);
            valSelectedHeight->Tile_Value_AddRefValueAction(0x7d0, tile10, 0xfb0);
            valSelectedHeight->Tile_Value_SetFloat(0);
            if (tile10->GetSpeechChallengeFailure())
            {
                Tile* highlightBox = (Tile*)FindNamedTile(tile0c, "lb_highlight_box");
                if (highlightBox)
                {
                    Tile* child = highlightBox->GetNamedChild("top");
                    if (child)
                    {
                        child->SetSpeechChallengeFailure_0071aa60(true);
                        child->SetImageFlags(8);
                        child = highlightBox->GetNamedChild("bottom");
                        child->SetSpeechChallengeFailure_0071aa60(true);
                        child->SetImageFlags(8);
                        child = highlightBox->GetNamedChild("left");
                        child->SetSpeechChallengeFailure_0071aa60(true);
                        child->SetImageFlags(8);
                        child = highlightBox->GetNamedChild("right");
                        child->SetSpeechChallengeFailure_0071aa60(true);
                        child->SetImageFlags(8);
                    }
                    highlightBox->SetSpeechChallengeFailure_0071aa60(true);
                    highlightBox->SetImageFlags(8);
                }
            }
            else
            {
                Tile* highlightBox = (Tile*)FindNamedTile(tile0c, "lb_highlight_box");
                if (highlightBox)
                {
                    Tile* child = highlightBox->GetNamedChild("top");
                    if (child)
                    {
                        child->SetSpeechChallengeFailure_0071aa60(false);
                        child->SetImageFlags(8);
                        child = highlightBox->GetNamedChild("bottom");
                        child->SetSpeechChallengeFailure_0071aa60(false);
                        child->SetImageFlags(8);
                        child = highlightBox->GetNamedChild("left");
                        child->SetSpeechChallengeFailure_0071aa60(false);
                        child->SetImageFlags(8);
                        child = highlightBox->GetNamedChild("right");
                        child->SetSpeechChallengeFailure_0071aa60(false);
                        child->SetImageFlags(8);
                    }
                    highlightBox->SetSpeechChallengeFailure_0071aa60(false);
                    highlightBox->SetImageFlags(8);
                }
            }
        }
        else
        {
            tile0c->Set(s_highlightY, -1);
            tile0c->Set(s_selectedHeight, 0);
        }
    }
}

struct ListBoxX
{
    int unk00;
    int unk04;
    int unk08;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    void ListBox_BGSSaveLoadFileEntry_UpdateHighlightBoxPos();
};

// @fnv 0x007d97a0
// src: XBOX_PDB 0x007d97a0
void ListBoxX::ListBox_BGSSaveLoadFileEntry_UpdateHighlightBoxPos()
{
    static int traitHighlightY = GetTileValueID(str_0106f8c0, -1);
    static int traitSelectedHeight = GetTileValueID(str_0106f8ac, -1);
    if (m_pListTile != 0)
    {
        if (m_pSelectedTile != 0)
        {
            TileValue* valHighlightY = reinterpret_cast<TileValue*>(m_pListTile->GetValue(traitHighlightY));
            TileValue* valSelectedHeight = reinterpret_cast<TileValue*>(m_pListTile->GetValue(traitSelectedHeight));
            ((HighlightValue_listbox*)valHighlightY)->Tile_Value_AddRefValueAction(2000, m_pSelectedTile, 4002);
            ((HighlightValue_listbox*)valHighlightY)->Tile_Value_SetFloat(0);
            ((HighlightValue_listbox*)valSelectedHeight)->Tile_Value_AddRefValueAction(2000, m_pSelectedTile, 4016);
            ((HighlightValue_listbox*)valSelectedHeight)->Tile_Value_SetFloat(0);
            if (((Tile*)m_pSelectedTile)->GetSpeechChallengeFailure())
            {
                Tile* box = FindNamedTile(m_pListTile, str_0106f898);
                if (box != 0)
                {
                    Tile* child = ((Tile*)box)->GetNamedChild(str_0106f894);
                    if (child != 0)
                    {
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)box)->GetNamedChild(str_0106f88c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)box)->GetNamedChild(str_0106f884);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)box)->GetNamedChild(str_0106f87c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(true);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                    }
                    ((Tile*)box)->SetSpeechChallengeFailure_0071aa60(true);
                    ((Tile*)box)->Tile_SetChangeFlag(8);
                }
            }
            else
            {
                Tile* box = FindNamedTile(m_pListTile, str_0106f898);
                if (box != 0)
                {
                    Tile* child = ((Tile*)box)->GetNamedChild(str_0106f894);
                    if (child != 0)
                    {
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)box)->GetNamedChild(str_0106f88c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)box)->GetNamedChild(str_0106f884);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                        child = ((Tile*)box)->GetNamedChild(str_0106f87c);
                        ((Tile*)child)->SetSpeechChallengeFailure_0071aa60(false);
                        ((Tile*)child)->Tile_SetChangeFlag(8);
                    }
                    ((Tile*)box)->SetSpeechChallengeFailure_0071aa60(false);
                    ((Tile*)box)->Tile_SetChangeFlag(8);
                }
            }
        }
        else
        {
            ((Tile*)m_pListTile)->Set(traitHighlightY, -1);
            ((Tile*)m_pListTile)->Set(traitSelectedHeight, 0);
        }
    }
}

namespace fnv_007d9ac0 {
struct TileObj
{
    virtual int FirstVirtual(int);
};
struct ListBoxItem_t
{
    TileObj* f0;
    InventoryStackRecord* f4;
    unsigned char f8;
};
struct FUN_004ee7d0_node
{
    ListBoxItem_t** FUN_006815c0();
    FUN_004ee7d0_node* FUN_00726070();
    void FUN_006ecd40(unsigned int);
    int FUN_004702f0(int);
    ListBoxItem_t* item;
    FUN_004ee7d0_node* next;
};
struct IMObjX
{
    void InterfaceManager_SetCurrentFocusTarget(int, int, int);
};
void* InterfaceManager_GetSingleton();
int __cdecl Tile_TextToTrait(const char*);
void __cdecl FormHeapFreeAndLog_00401030(void*);

struct LBThis
{
    void* vtbl;
    FUN_004ee7d0_node head;
    Tile* container;
    TileObj* selected;
    bool ListBox_unsigned_int_GetFlag(unsigned int);
    void UpdateSaveLoadList();
    bool RemoveItemNode(FUN_004ee7d0_node* p1, FUN_004ee7d0_node* p2);
};

// @fnv 0x007d9ac0
bool LBThis::RemoveItemNode(FUN_004ee7d0_node* pNodeToRemove, FUN_004ee7d0_node* p2)
{
    if (pNodeToRemove)
    {
        TileObj* selObj;
        TileObj* selTmp;
        InventoryStackRecord* elemA;
        InventoryStackRecord* had;
        ListBoxItem_t* itemB;
        if ((*pNodeToRemove->FUN_006815c0())->f0 == selected)
        {
            selected = pNodeToRemove->FUN_00726070() ? (*pNodeToRemove->FUN_00726070()->FUN_006815c0())->f0
                                                     : ((p2 && p2 != pNodeToRemove) ? (*p2->FUN_006815c0())->f0 : 0);
            if (selected)
            {
                ((IMObjX*)InterfaceManager_GetSingleton())->InterfaceManager_SetCurrentFocusTarget((int)selected, 0xfc3, 1);
            }
        }
        if (container && (*pNodeToRemove->FUN_006815c0())->f8)
        {
            container->Tile_Set(Tile_TextToTrait("_num_filtered"),
                                    container->FUN_00a011b0(Tile_TextToTrait("_num_filtered")) - 1.0, true);
        }
        selTmp = (*pNodeToRemove->FUN_006815c0())->f0;
        selObj = selTmp;
        (void)(selObj ? selObj->FirstVirtual(1) : 0);
        if (ListBox_unsigned_int_GetFlag(1))
        {
            had = (*pNodeToRemove->FUN_006815c0())->f4;
            elemA = had;
            (void)(elemA ? elemA->FUN_004459e0(1) : 0);
        }
        itemB = *pNodeToRemove->FUN_006815c0();
        FormHeapFreeAndLog_00401030(itemB);
        if (pNodeToRemove == (this ? &head : 0))
        {
            if (head.next)
            {
                p2 = head.next;
                head.next = p2->FUN_00726070();
                head.item = *p2->FUN_006815c0();
                p2->FUN_006ecd40(0);
                FUN_004ee7d0_node* node2 = p2;
                FUN_004ee7d0_node* nodeA = node2;
                (void)(nodeA ? nodeA->FUN_004702f0(1) : 0);
            }
            else
            {
                head.item = 0;
            }
        }
        else
        {
            p2->FUN_006ecd40((unsigned int)pNodeToRemove->FUN_00726070());
            pNodeToRemove->FUN_006ecd40(0);
            FUN_004ee7d0_node* nodeBTmp = pNodeToRemove;
            FUN_004ee7d0_node* nodeB = nodeBTmp;
            (void)(nodeB ? nodeB->FUN_004702f0(1) : 0);
        }
        if (ListBox_unsigned_int_GetFlag(0))
        {
            UpdateSaveLoadList();
        }
        return true;
    }
    return false;
}
}  // namespace fnv_007d9ac0

namespace fnv_007e1190 {
struct EntryTile;
struct TileAction
{
    void RemoveFromReactions();
    void Tile_Value_AddRefValueAction(int trait, EntryTile* tile, int value);
    void AppendFloatAction(int trait, float value);
    void Tile_Value_SetFloat(int value);
};
struct CreatedTile
{
    EntryTile* FUN_00a1ddb0();
};
struct EntryTile
{
    CreatedTile* Tile_GetMenu(EntryTile* parent, const char* name, int flags);
    void* Tile_GetValue(int trait);
    void FUN_00700320(int trait, int value);
    void Tile_Set_00a01350(int trait, const char* value, bool propagate);
    float FUN_00a011b0(int trait);
    TileAction* FindTraitValue(int trait);
};
struct FUN_007a62e0
{
    EntryTile* tile;
    int data;
    unsigned char selected;
    FUN_007a62e0(EntryTile*, int*);
};
struct EntryListNode
{
    FUN_007a62e0* item;
    EntryListNode* next;
    void BSSimpleList_ActiveEffect_Insert(FUN_007a62e0* entry, int comparator);
    void FUN_00905820(FUN_007a62e0* const& entry);
};
extern "C" char str_0106f860[];
struct LBH
{
    void* vtable;
    EntryListNode entries;
    EntryTile* container;
    EntryTile* selected;
    EntryTile* scrollbar;
    const char* templateName;
    unsigned short itemCount;
    bool ListBox_unsigned_int_GetFlag(unsigned int);
    void RefreshTiles();
    void AccumulateTileHeight(EntryTile*);
    void ListBox_enum_MiscStatManager_MiscStatID_SetTotalListHeight();
    int GetRaceCount();
    EntryTile* ListBox_enum_MiscStatManager_MiscStatID_AddItem(int data, const char* text, int comparator, const char* name);
};
// @fnv 0x007e1190
// src: COMMUNITY 0x007e1190
EntryTile* LBH::ListBox_enum_MiscStatManager_MiscStatID_AddItem(int data, const char* text, int comparator, const char* name)
{
    if (container && (templateName || name))
    {
        EntryTile* tile = container->Tile_GetMenu(container, name ? name : templateName, 0)->FUN_00a1ddb0();
        if (!tile->Tile_GetValue(0xfaa))
            tile->FUN_00700320(0xfaa, -1);
        if (text)
            tile->Tile_Set_00a01350(0xfc4, text, true);
        if (comparator)
        {
            entries.BSSimpleList_ActiveEffect_Insert(new FUN_007a62e0(tile, &data), comparator);
            if (ListBox_unsigned_int_GetFlag(0))
                RefreshTiles();
        }
        else
        {
            entries.FUN_00905820(new FUN_007a62e0(tile, &data));
            if (ListBox_unsigned_int_GetFlag(0))
            {
                AccumulateTileHeight(tile);
                ListBox_enum_MiscStatManager_MiscStatID_SetTotalListHeight();
            }
            tile->FUN_00700320(0xfac, itemCount++);
        }
        if (GetRaceCount() == 1 && container->FUN_00a011b0(Tile_AddUserTrait(str_0106f860, -1)) > 0.0)
        {
            TileAction* value = container->FindTraitValue(0xfb0);
            value->RemoveFromReactions();
            value->Tile_Value_AddRefValueAction(0x7d0, tile, 0xfb0);
            value->AppendFloatAction(0x7d3, container->FUN_00a011b0(Tile_AddUserTrait(str_0106f860, -1)));
            value->Tile_Value_SetFloat(0);
        }
        return tile;
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_007e1190

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

// @fnv 0x0071a5c0
bool RList71a5::RemoveTile(Tile* tile)
{
    if (!tile || FUN_008256d0((ContNode*)&item))
        return false;
    RemovalNode* posCur = this;
    RemovalNode* prev = this;
    while (posCur && (*((N6815c0*)posCur)->FUN_006815c0())->tile != tile)
    {
        prev = posCur;
        posCur = posCur->FUN_00726070();
    }
    return RemoveNode(posCur, prev);
}

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
// @fnv 0x00722410
// src: XBOX_PDB 0x00722410
Tile* Box118::ListBox_enum_MiscStatManager_MiscStatID_GetHighlightTarget(unsigned int action)
{
    Tile* pFound = 0;
    int delta8 = 0;
    switch (action)
    {
    case 2:
        delta8 = 1;
        break;
    case 1:
        delta8 = -1;
        break;
    case 15:
        delta8 = scroll ? (int)FUN_004bd510(
                              -scroll->FUN_00a011b0(0xfb0) / scroll->FUN_00a011b0(Tile_TextToTrait("_scroll_delta")), 1.0f)
                        : 0;
        break;
    case 16:
        delta8 = scroll ? (int)FUN_004bd510(
                              scroll->FUN_00a011b0(0xfb0) / scroll->FUN_00a011b0(Tile_TextToTrait("_scroll_delta")), 1.0f)
                        : 0;
        break;
    }
    if (ListBox_enum_MiscStatManager_MiscStatID_IsEnabled() && delta8 && count)
    {
        int maximum = count - 1;
        int iCurrent;
        if (selected)
        {
            int iPrevious = (int)selected->FUN_00a011b0(0xfac);
            iCurrent = iPrevious + delta8;
            if (iCurrent < 0)
                iCurrent = 0;
            else if (iCurrent > maximum)
                iCurrent = maximum;
        }
        else
        {
            if (delta8 > 0)
                iCurrent = 0;
            else
                iCurrent = maximum;
        }
        while (true)
        {
            for (Node118* node = this ? &head : 0; !pFound && node && node->FUN_006815c0(); node = node->FUN_00726070())
            {
                if (node->FUN_006815c0()->tile->FUN_00a011b0(0xfac) == iCurrent)
                    pFound = node->FUN_006815c0()->tile;
            }
            if (pFound && !pFound->IsTraitNonZero(Tile_AddUserTrait(kListBoxEnabled, -1)))
            {
                pFound = 0;
                if (delta8 > 0 && ++iCurrent > maximum)
                {
                    iCurrent = maximum - 1;
                    while ((!pFound || !pFound->IsTraitNonZero(Tile_AddUserTrait(kListBoxEnabled, -1))) && iCurrent >= 0)
                        pFound = GetTile(iCurrent--, 0);
                    break;
                }
                else if (delta8 < 0 && --iCurrent < 0)
                {
                    iCurrent = 1;
                    while ((!pFound || !pFound->IsTraitNonZero(Tile_AddUserTrait(kListBoxEnabled, -1))) &&
                           iCurrent <= maximum)
                        pFound = GetTile(iCurrent++, 0);
                    break;
                }
            }
            else
                break;
        }
    }
    return pFound != selected ? pFound : 0;
}

struct ListItem_71a
{
    Tile* pTile;
    int unk04;
    bool m_bFiltered;
};
template <class T> struct SimpleList_71a
{
    T m_item;
    SimpleList_71a<T>* m_pkNext;
    T& FUN_006815c0();
    SimpleList_71a<T>* FUN_00726070();
};
struct ListBox_71a : ListBoxBase, SimpleList_71a<ListItem_71a*>
{
    Tile* m_pListTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;
    void UpdateItems();
    void AccumulateTileHeight(Tile* apTile);
    void UpdateScrollPages();
    void ListBox_ItemChange_UpdateHighlightBoxPos();
};
// Resets the item count and a float, assigns trait 0xfac with an incrementing index to each unflagged list item's tile, then calls UpdateScrollPages and FUN_0071a740.
// @fnv 0x0071a670
void ListBox_71a::UpdateItems()
{
    usItemCount = 0;
    m_fFirstListValue = 0.0f;
    for (SimpleList_71a<ListItem_71a*>* pNode = this; pNode && pNode->FUN_006815c0(); pNode = pNode->FUN_00726070())
    {
        if (!pNode->FUN_006815c0()->m_bFiltered)
        {
            pNode->FUN_006815c0()->pTile->FUN_00700320(0xfac, usItemCount++);
            AccumulateTileHeight(pNode->FUN_006815c0()->pTile);
        }
    }
    UpdateScrollPages();
    ListBox_ItemChange_UpdateHighlightBoxPos();
}

int Tile_AddUserTrait(const char* pcName, int iDefault);
Tile* Tile_GetTileByName(Tile* pkParent, const char* pcName);
struct ListBoxZ
{
    char pad[0xc];
    Tile* m_pkTile;
    Tile* m_pkItem;
    void ListBox_ItemChange_UpdateHighlightBoxPos();
};
// Sets highlight and selected-height properties from m_pkItem, then sets the highlight box and its sides visible according to the item's boolean result.
// @fnv 0x0071a740
// src: XBOX_PDB 0x0071a740
void ListBoxZ::ListBox_ItemChange_UpdateHighlightBoxPos()
{
    static int s_iHighlightY = Tile_AddUserTrait("_highlight_y", -1);
    static int s_iSelectedHeight = Tile_AddUserTrait("_selected_height", -1);
    if (m_pkTile)
    {
        if (m_pkItem)
        {
            TileValue* pkHighlight_zkij = reinterpret_cast<TileValue*>(m_pkTile->Tile_GetValue(s_iHighlightY));
            TileValue* pkHeight_dxa = reinterpret_cast<TileValue*>(m_pkTile->Tile_GetValue(s_iSelectedHeight));
            pkHighlight_zkij->Tile_Value_AddRefValueAction(0x7d0, m_pkItem, 0xfa2);
            pkHighlight_zkij->Tile_Value_SetFloat(0);
            pkHeight_dxa->Tile_Value_AddRefValueAction(0x7d0, m_pkItem, 0xfb0);
            pkHeight_dxa->Tile_Value_SetFloat(0);
            if (m_pkItem->GetSpeechChallengeFailure())
            {
                Tile* pkBox = Tile_GetTileByName(m_pkTile, "lb_highlight_box");
                if (pkBox)
                {
                    Tile* pkSide = pkBox->GetNamedChild("top");
                    if (pkSide)
                    {
                        pkSide->SetSpeechChallengeFailure_0071aa60(true);
                        pkSide->Tile_SetChangeFlag(8);
                        pkSide = pkBox->GetNamedChild("bottom");
                        pkSide->SetSpeechChallengeFailure_0071aa60(true);
                        pkSide->Tile_SetChangeFlag(8);
                        pkSide = pkBox->GetNamedChild("left");
                        pkSide->SetSpeechChallengeFailure_0071aa60(true);
                        pkSide->Tile_SetChangeFlag(8);
                        pkSide = pkBox->GetNamedChild("right");
                        pkSide->SetSpeechChallengeFailure_0071aa60(true);
                        pkSide->Tile_SetChangeFlag(8);
                    }
                    pkBox->SetSpeechChallengeFailure_0071aa60(true);
                    pkBox->Tile_SetChangeFlag(8);
                }
            }
            else
            {
                Tile* pkBox = Tile_GetTileByName(m_pkTile, "lb_highlight_box");
                if (pkBox)
                {
                    Tile* pkSide = pkBox->GetNamedChild("top");
                    if (pkSide)
                    {
                        pkSide->SetSpeechChallengeFailure_0071aa60(false);
                        pkSide->Tile_SetChangeFlag(8);
                        pkSide = pkBox->GetNamedChild("bottom");
                        pkSide->SetSpeechChallengeFailure_0071aa60(false);
                        pkSide->Tile_SetChangeFlag(8);
                        pkSide = pkBox->GetNamedChild("left");
                        pkSide->SetSpeechChallengeFailure_0071aa60(false);
                        pkSide->Tile_SetChangeFlag(8);
                        pkSide = pkBox->GetNamedChild("right");
                        pkSide->SetSpeechChallengeFailure_0071aa60(false);
                        pkSide->Tile_SetChangeFlag(8);
                    }
                    pkBox->SetSpeechChallengeFailure_0071aa60(false);
                    pkBox->Tile_SetChangeFlag(8);
                }
            }
        }
        else
        {
            m_pkTile->FUN_00700320(s_iHighlightY, -1);
            m_pkTile->FUN_00700320(s_iSelectedHeight, 0);
        }
    }
}

extern "C" char str_01070244[];
int __cdecl Tile_AddUserTrait(const char* name, int fallback);

// Returns whether m_pScrollBar exists and has the trait identified by str_01070244 set to a non-zero value.
// @fnv 0x00724a00
bool Class_721c60::IsScrollBarTraitEnabled()
{
    static int enabledTrait = Tile_AddUserTrait(str_01070244, -1);
    return m_pScrollBar && m_pScrollBar->IsTraitNonZero(enabledTrait);
}

struct FUN_007d7670_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Tile* m_pkSelected;

    bool ListBox_StartMenu_Option_IsEnabled();
    bool ContainsKey(Tile* pkTile);
    void UpdateHighlightBox();
    bool ListBox_StartMenu_Option_Highlight(Tile* pkTile);
};
// When the class is active, assigns pkTile if null or contained with a nonzero trait, then updates the highlight box.
// @fnv 0x007d7670
// src: XBOX_PDB 0x007d7670
bool FUN_007d7670_cls::ListBox_StartMenu_Option_Highlight(Tile* pkTile)
{
    if (ListBox_StartMenu_Option_IsEnabled() && (!pkTile || (ContainsKey(pkTile) && pkTile->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1)))))
    {
        m_pkSelected = pkTile;
        UpdateHighlightBox();
        return true;
    }
    else
    {
        return false;
    }
}

namespace list71a {
struct L71Tile;
struct L71Value
{
    void RemoveFromReactions();
    void Tile_Value_AddRefValueAction(int op, L71Tile* tile, int id);
    void AppendFloatAction(int op, float value);
    void Tile_Value_SetFloat(int a);
};
struct L71Created;
struct L71Tile
{
    int Tile_GetValue(int id);
    void FUN_00700320(int id, int value);
    void Tile_Set_00a01350(int id, const char* text, int a);
    float FUN_00a011b0(int id);
    L71Value* FindTraitValue(int id);
    L71Created* Tile_GetMenu(L71Tile* parent, L71Tile* tmpl, int a);
};
struct L71Created
{
    L71Tile* FUN_00a1ddb0();
};
struct L71Item
{
    int unk00;
    int unk04;
    int unk08;
    L71Item(L71Tile* tile, int& data);
};
struct L71List
{
    int unk00;
    int unk04;
    void BSSimpleList_ActiveEffect_Insert(L71Item* item, int (*compare)(L71Item*, L71Item*));
    void FUN_00905820(L71Item* const& item);
};
struct L71Menu
{
    int unk00;
    L71List kItems;
    L71Tile* pRoot;
    int unk10;
    int unk14;
    L71Tile* pTemplate;
    unsigned short m_usPassCountLocal;
    bool ListBox_unsigned_int_GetFlag(int a);
    void UpdateItems();
    void AccumulateTileHeight(L71Tile* tile);
    void UpdateScrollPages();
    int GetRaceCount();
    L71Tile* ListBox_ItemChange_AddItem(int data, const char* text, int (*compare)(L71Item*, L71Item*), L71Tile* tmpl);
};
}
using namespace list71a;

// Creates a tile under pRoot, optionally sets trait 0xfc4, inserts it into kItems, and updates menu layout and trait 0xfb0.
// @fnv 0x0071a320
// src: XBOX_PDB 0x0071a320
L71Tile* L71Menu::ListBox_ItemChange_AddItem(int data, const char* apLabel, int (*compare)(L71Item*, L71Item*), L71Tile* apTemplate)
{
    L71Tile* pTile;
    L71Value* pTraitValue;

    if (pRoot && (pTemplate || apTemplate))
    {
        pTile = pRoot->Tile_GetMenu(pRoot, apTemplate ? apTemplate : pTemplate, 0)->FUN_00a1ddb0();
        if (!pTile->Tile_GetValue(0xfaa))
        {
            pTile->FUN_00700320(0xfaa, -1);
        }
        if (apLabel)
        {
            pTile->Tile_Set_00a01350(0xfc4, apLabel, 1);
        }
        if (compare)
        {
            kItems.BSSimpleList_ActiveEffect_Insert(new L71Item(pTile, data), compare);
            if (ListBox_unsigned_int_GetFlag(0))
            {
                UpdateItems();
            }
        }
        else
        {
            kItems.FUN_00905820(new L71Item(pTile, data));
            if (ListBox_unsigned_int_GetFlag(0))
            {
                AccumulateTileHeight(pTile);
                UpdateScrollPages();
            }
            pTile->FUN_00700320(0xfac, m_usPassCountLocal++);
        }
        if (GetRaceCount() == 1 && pRoot->FUN_00a011b0(Tile_AddUserTrait("_number_of_visible_items", -1)) > 0.0)
        {
            pTraitValue = pRoot->FindTraitValue(0xfb0);
            pTraitValue->RemoveFromReactions();
            pTraitValue->Tile_Value_AddRefValueAction(0x7d0, pTile, 0xfb0);
            pTraitValue->AppendFloatAction(0x7d3, pRoot->FUN_00a011b0(Tile_AddUserTrait("_number_of_visible_items", -1)));
            pTraitValue->Tile_Value_SetFloat(0);
        }
        return pTile;
    }
    else
    {
        return 0;
    }
}

namespace scroll722 {
struct S722Entry
{
    Tile* pTile;
};
struct S722Node
{
    S722Entry* pItem;
    S722Node* pNext;
    S722Entry** FUN_006815c0();
    S722Node* FUN_00726070();
};
struct MenuBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual Tile* GetItemTile(int index, int a);
};
struct S722Menu : public MenuBase, public S722Node
{
    Tile* m_pHighlightedTile;
    Tile* pSelected;
    int unk14;
    int unk18;
    unsigned short m_usPassCountLocal;
    bool HasEnabledTrait();
    Tile* ListBox_StatsMenu_StatusEffect_HandleKeyboardInput(int code);
};
}
using namespace scroll722;

// Finds a tile at the index offset derived from code and returns it unless it matches pSelected.
// @fnv 0x00722bc0
// src: COMMUNITY 0x00722bc0
Tile* S722Menu::ListBox_StatsMenu_StatusEffect_HandleKeyboardInput(int code)
{
    Tile* pFound5 = 0;
    int iDelta = 0;

    switch (code)
    {
    case 2:
        iDelta = 1;
        break;
    case 1:
        iDelta = -1;
        break;
    case 15:
        iDelta = m_pHighlightedTile
                     ? (int)FUN_004bd510(-m_pHighlightedTile->FUN_00a011b0(0xfb0) /
                                             m_pHighlightedTile->FUN_00a011b0(Tile_TextToTrait("_scroll_delta")),
                                         1.0f)
                     : 0;
        break;
    case 16:
        iDelta = m_pHighlightedTile
                     ? (int)FUN_004bd510(m_pHighlightedTile->FUN_00a011b0(0xfb0) /
                                             m_pHighlightedTile->FUN_00a011b0(Tile_TextToTrait("_scroll_delta")),
                                         1.0f)
                     : 0;
        break;
    }
    if (HasEnabledTrait() && iDelta && m_usPassCountLocal)
    {
        int iLastB = m_usPassCountLocal - 1;
        int iIndex;
        if (pSelected)
        {
            int iCurrent5 = (int)pSelected->FUN_00a011b0(0xfac);
            if ((iIndex = iCurrent5 + iDelta) < 0)
            {
                iIndex = 0;
            }
            else if (iIndex > iLastB)
            {
                iIndex = iLastB;
            }
        }
        else if (iDelta > 0)
        {
            iIndex = 0;
        }
        else
        {
            iIndex = iLastB;
        }
        while (1)
        {
            for (S722Node* pNode4 = this; !pFound5 && pNode4 && *pNode4->FUN_006815c0();
                 pNode4 = pNode4->FUN_00726070())
            {
                if ((*pNode4->FUN_006815c0())->pTile->FUN_00a011b0(0xfac) == iIndex)
                {
                    pFound5 = (*pNode4->FUN_006815c0())->pTile;
                }
            }
            if (pFound5 && !pFound5->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1)))
            {
                pFound5 = 0;
                if (iDelta > 0 && ++iIndex > iLastB)
                {
                    iIndex = iLastB - 1;
                    while ((!pFound5 || !pFound5->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1))) && iIndex >= 0)
                    {
                        pFound5 = GetItemTile(iIndex--, 0);
                    }
                    break;
                }
                else if (iDelta < 0 && --iIndex < 0)
                {
                    iIndex = 1;
                    while ((!pFound5 || !pFound5->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1))) && iIndex <= iLastB)
                    {
                        pFound5 = GetItemTile(iIndex++, 0);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return pFound5 != pSelected ? pFound5 : 0;
}

struct LBItem_7314c0
{
    Tile* tile;
    void* object;
};
struct LBNode_7314c0
{
    LBItem_7314c0* item;
    LBNode_7314c0* next;
    LBItem_7314c0** FUN_006815c0();
    LBNode_7314c0* FUN_00726070();
};
struct LBBase_7314c0
{
    virtual void VFunc00();
};
struct LBList_7314c0 : LBBase_7314c0, LBNode_7314c0
{
    void ListBox_ItemChange_Traverse(void(__cdecl* callback)(Tile*, void*), int minIndex, int maxIndex);
};
// Iterates the linked list, calling callback on each tile whose index is within [minIndex, maxIndex).
// @fnv 0x007314c0
// src: XBOX_PDB 0x007314c0
void LBList_7314c0::ListBox_ItemChange_Traverse(void(__cdecl* callback)(Tile*, void*), int minIndex, int maxIndex)
{
    for (LBNode_7314c0* node = this;
         node && *node->FUN_006815c0() && (int)(*node->FUN_006815c0())->tile->FUN_00a011b0(0xFAC) < maxIndex;
         node = node->FUN_00726070())
    {
        if ((int)(*node->FUN_006815c0())->tile->FUN_00a011b0(0xFAC) >= minIndex)
            callback((*node->FUN_006815c0())->tile, (*node->FUN_006815c0())->object);
    }
}

namespace scroll764 {
struct S764Entry
{
    Tile* pTile;
};
struct S764Node
{
    S764Entry* pItem;
    S764Node* pNext;
    S764Entry** FUN_006815c0();
    S764Node* FUN_00726070();
};
struct MenuBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual Tile* GetItemTile(int index, int a);
};
struct S764Menu : public MenuBase, public S764Node
{
    Tile* m_pHighlightedTile;
    Tile* pSelected;
    int unk14;
    int unk18;
    unsigned short m_usPassCountLocal;
    bool ListBox_int_IsEnabled();
    Tile* ListBox_int_GetHighlightTarget(int code);
};
}
using namespace scroll764;

// Finds an enabled tile at an index offset derived from code and returns it, or 0 if it matches pSelected.
// @fnv 0x00764a70
// src: XBOX_PDB 0x00764a70
Tile* S764Menu::ListBox_int_GetHighlightTarget(int aiScrollCode)
{
    Tile* pFound5 = 0;
    int iDelta = 0;

    switch (aiScrollCode)
    {
    case 2:
        iDelta = 1;
        break;
    case 1:
        iDelta = -1;
        break;
    case 15:
        iDelta = m_pHighlightedTile
                     ? (int)FUN_004bd510(-m_pHighlightedTile->FUN_00a011b0(0xfb0) /
                                             m_pHighlightedTile->FUN_00a011b0(Tile_TextToTrait("_scroll_delta")),
                                         1.0f)
                     : 0;
        break;
    case 16:
        iDelta = m_pHighlightedTile
                     ? (int)FUN_004bd510(m_pHighlightedTile->FUN_00a011b0(0xfb0) /
                                             m_pHighlightedTile->FUN_00a011b0(Tile_TextToTrait("_scroll_delta")),
                                         1.0f)
                     : 0;
        break;
    }
    if (ListBox_int_IsEnabled() && iDelta && m_usPassCountLocal)
    {
        int iLastB = m_usPassCountLocal - 1;
        int iIndex;
        if (pSelected)
        {
            int iCurrent5 = (int)pSelected->FUN_00a011b0(0xfac);
            if ((iIndex = iCurrent5 + iDelta) < 0)
            {
                iIndex = 0;
            }
            else if (iIndex > iLastB)
            {
                iIndex = iLastB;
            }
        }
        else if (iDelta > 0)
        {
            iIndex = 0;
        }
        else
        {
            iIndex = iLastB;
        }
        while (1)
        {
            for (S764Node* pNode4 = this; !pFound5 && pNode4 && *pNode4->FUN_006815c0();
                 pNode4 = pNode4->FUN_00726070())
            {
                if ((*pNode4->FUN_006815c0())->pTile->FUN_00a011b0(0xfac) == iIndex)
                {
                    pFound5 = (*pNode4->FUN_006815c0())->pTile;
                }
            }
            if (pFound5 && !pFound5->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1)))
            {
                pFound5 = 0;
                if (iDelta > 0 && ++iIndex > iLastB)
                {
                    iIndex = iLastB - 1;
                    while ((!pFound5 || !pFound5->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1))) && iIndex >= 0)
                    {
                        pFound5 = GetItemTile(iIndex--, 0);
                    }
                    break;
                }
                else if (iDelta < 0 && --iIndex < 0)
                {
                    iIndex = 1;
                    while ((!pFound5 || !pFound5->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1))) && iIndex <= iLastB)
                    {
                        pFound5 = GetItemTile(iIndex++, 0);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return pFound5 != pSelected ? pFound5 : 0;
}

extern "C" char str_01070244[];
int __cdecl Tile_AddUserTrait(const char* name, int len);
struct MenuChk_a3f90
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Tile* unk10;
    bool IsEnabled();
    bool ContainsKey(Tile* tile);
    void UpdateHighlightTraits_007a73e0();
    bool ListBox_TESObjectREFR_Destroy(Tile* tile);
};
// If FUN_007a7330 is true and tile is null or contained with a nonzero trait, assigns unk10, calls FUN_007a73e0, and returns true.
// @fnv 0x007a3f90
// src: COMMUNITY 0x007a3f90
bool MenuChk_a3f90::ListBox_TESObjectREFR_Destroy(Tile* tile)
{
    if (IsEnabled() && (!tile || (ContainsKey(tile) && tile->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1)))))
    {
        unk10 = tile;
        UpdateHighlightTraits_007a73e0();
        return true;
    }
    else
    {
        return false;
    }
}

namespace menu7a5 {
struct FUN_007240c0
{
    FUN_007240c0();
    virtual void v00();
    void ListBox_ItemChange_SetFlag(int a, int b);
};
void AddToHeadList(FUN_007240c0* menu);
struct FUN_007a50f0 : public FUN_007240c0, public SL
{
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_usPassCountLocal;
    short unk1e;
    float fX;
    float fY;
    float fZ;
    unsigned short usIndex;
    FUN_007a50f0();
    virtual void v00();
};

}
using namespace menu7a5;

// @fnv 0x007a50f0
FUN_007a50f0::FUN_007a50f0()
{
    unk14 = 0;
    unk10 = 0;
    unk0c = 0;
    unk18 = 0;
    usIndex = 0;
    m_usPassCountLocal = 0;
    fZ = 0.0f;
    fY = 0.0f;
    fX = 0.0f;
    ListBox_ItemChange_SetFlag(0, 1);
    AddToHeadList(this);
}

struct Owner_007a5a60
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Tile* m_pkTarget;
    bool IsEnabled();
    bool ContainsKey(Tile* pkTarget);
    void UpdateHighlight();
    bool SetEnabledHighlightTarget(Tile* pkTarget);
};

// When FUN_007a81b0 is true and pkTarget is null or contained with a nonzero _enabled trait, assigns m_pkTarget and calls UpdateHighlight.
// @fnv 0x007a5a60
// src: GUESS 0x007a5a60 (confidence: medium)
bool Owner_007a5a60::SetEnabledHighlightTarget(Tile* pkTarget)
{
    if (IsEnabled() &&
        (!pkTarget || (ContainsKey(pkTarget) && pkTarget->IsTraitNonZero(Tile_AddUserTrait("_enabled", -1)))))
    {
        m_pkTarget = pkTarget;
        UpdateHighlight();
        return true;
    }
    else
    {
        return false;
    }
}

struct Item_7d76e0
{
    Tile* tile;
};
struct Node_7d76e0
{
    Item_7d76e0* item;
    Node_7d76e0* next;
    Item_7d76e0** FUN_006815c0();
    Node_7d76e0* FUN_00726070();
};
struct Base_7d76e0
{
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual Tile* VFunc14(int index, bool flag);
};
struct Class_7d76e0 : Base_7d76e0, Node_7d76e0
{
    Tile* container;
    Tile* selected;
    Tile* scrollbar;
    const char* templateName;
    unsigned short count;

    bool ListBox_StartMenu_Option_IsEnabled();
    Tile* ListBox_StartMenu_Option_GetHighlightTarget(int action);
};

// Finds a tile at the index offset derived from action and returns it unless it matches selected.
// @fnv 0x007d76e0
// src: XBOX_PDB 0x007d76e0
Tile* Class_7d76e0::ListBox_StartMenu_Option_GetHighlightTarget(int action)
{
    Tile* result = 0;
    int delta = 0;
    switch (action)
    {
    case 2:
        delta = 1;
        break;
    case 1:
        delta = -1;
        break;
    case 15:
        delta = container
                    ? (int)FUN_004bd510(
                          -container->FUN_00a011b0(0xfb0) / container->FUN_00a011b0(Tile_TextToTrait(str_0106f90c)), 1.0f)
                    : 0;
        break;
    case 16:
        delta = container
                    ? (int)FUN_004bd510(
                          container->FUN_00a011b0(0xfb0) / container->FUN_00a011b0(Tile_TextToTrait(str_0106f90c)), 1.0f)
                    : 0;
        break;
    }
    if (ListBox_StartMenu_Option_IsEnabled() && delta != 0 && count != 0)
    {
        int newIdx;
        int maxIdx = count - 1;
        int curIdx;
        if (selected != 0)
        {
            curIdx = (int)selected->FUN_00a011b0(0xfac);
            if ((newIdx = curIdx + delta) < 0)
            {
                newIdx = 0;
            }
            else if (newIdx > maxIdx)
            {
                newIdx = maxIdx;
            }
        }
        else
        {
            if (delta > 0)
            {
                newIdx = 0;
            }
            else
            {
                newIdx = maxIdx;
            }
        }
        while (true)
        {
            Node_7d76e0* node;
            for (node = this; !result && node && *node->FUN_006815c0(); node = node->FUN_00726070())
            {
                if ((*node->FUN_006815c0())->tile->FUN_00a011b0(0xfac) == newIdx)
                {
                    result = (*node->FUN_006815c0())->tile;
                }
            }
            if (result && !result->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1)))
            {
                result = 0;
                if (delta > 0 && ++newIdx > maxIdx)
                {
                    newIdx = maxIdx - 1;
                    while ((!result || !result->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1))) && newIdx >= 0)
                    {
                        result = VFunc14(newIdx--, false);
                    }
                    break;
                }
                else if (delta < 0 && (newIdx -= 1) < 0)
                {
                    newIdx = 1;
                    while ((!result || !result->IsTraitNonZero(Tile_AddUserTrait(str_01070244, -1))) && newIdx <= maxIdx)
                    {
                        result = VFunc14(newIdx++, false);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return result != selected ? result : 0;
}

extern int FUN_01070418[];

struct FUN_007240c0_shell
{
    int* vtable;
    void* __thiscall DoNothing_007240c0();
};

// @fnv 0x007240c0
// src: GUESS 0x007240c0 (confidence: high)
void* __thiscall FUN_007240c0_shell::DoNothing_007240c0()
{
    vtable = FUN_01070418;
    return this;
}

struct FUN_00723f80
{
    virtual ~FUN_00723f80();
};

FUN_00723f80::~FUN_00723f80()
{}

struct FUN_00724200 : FUN_00723f80
{
    virtual ~FUN_00724200();
};

// @fnv 0x00724200
FUN_00724200::~FUN_00724200()
{}
