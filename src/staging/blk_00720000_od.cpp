#include "../../include/BSStringT.h"

// src/staging/blk_00720000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/Tile.h"
#include "../../include/VATSMenu.h"

struct FUN_00726d50_class
{
    void SetFlags(int a, int b);
    void AnimatingText_SetFlash(bool a);
};

// @fnv 0x00726d50
// src: XBOX_PDB 0x00726d50
void FUN_00726d50_class::AnimatingText_SetFlash(bool a)
{
    SetFlags(2, a);
}

extern int DAT_01070660;

struct GlobalObject_00869f00
{
    void* p;
    void Clear(bool);
    void InitFromGlobal();
};

void GlobalObject_00869f00::Clear(bool)
{}

// @fnv 0x0072ce90
void GlobalObject_00869f00::InitFromGlobal()
{
    p = &DAT_01070660;
    Clear(true);
}

extern "C" void __cdecl FUN_00ecbc5b(char* apString, int aiSize);

// @fnv 0x00730490
// src: XBOX_PDB 0x00730490
void BSstrupr(char* apString, int aiSize)
{
    FUN_00ecbc5b(apString, aiSize);
}


void __cdecl Deallocate(void*);
struct FUN_00726cf0 : ::BSStringT<char>
{
    void* m_p;
    ~FUN_00726cf0();
};
// Destructor that deallocates the pointer stored at offset 0x24 of this object.
// @fnv 0x00726cf0
FUN_00726cf0::~FUN_00726cf0()
{
    Deallocate(*(void**)((char*)this + 0x24));
}

// @fnv 0x00726d70
void FUN_00726d50_class::SetFlags(int auiFlags, int abSet)
{
    if (*(unsigned char*)&abSet)
        *(unsigned char*)((char*)this + 0x28) |= auiFlags;
    else
        *(unsigned char*)((char*)this + 0x28) &= ~auiFlags;
}

struct AX
{
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
};
struct StandIn
{
    void* vtable;
    StandIn* Initialize();
};
// Sets the vtable to DAT_01070660, calls FUN_006b3eb0 with 0 and 0, and returns this.
// @fnv 0x0072ce30
StandIn* StandIn::Initialize()
{
    vtable = &DAT_01070660;
    reinterpret_cast<AX*>(this)->BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}

struct GlobalObject_0072ce30
{
    ~GlobalObject_0072ce30();
    void* DestroyAndFree(unsigned int flags);
};

// Runs the destructor on this object, frees it with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x0072ce60
void* GlobalObject_0072ce30::DestroyAndFree(unsigned int flags)
{
    this->GlobalObject_0072ce30::~GlobalObject_0072ce30();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct ListX
{
    ~ListX();
};
struct p07
{
    static void InterfaceManager_UnregisterListBox(void*);
};
struct FUN_007308e0 : public ListX
{
    virtual ~FUN_007308e0();
    void ListBox_ItemChange_RemoveAll();
};
// Calls FUN_00730950, then passes this to p07::FUN_007211c0.
// @fnv 0x007308e0
FUN_007308e0::~FUN_007308e0()
{
    ListBox_ItemChange_RemoveAll();
    p07::InterfaceManager_UnregisterListBox(this);
}

struct Calendar
{
    int GetDaysPassed();
};

// Compares the days passed of two Calendar objects, returning 1 if the first is less, -1 if greater, and 0 if equal.
// @fnv 0x0073b6e0
int CompareCalendarDays(Calendar** apCalendarA, Calendar** apCalendarB)
{
    int daysA = (*apCalendarA)->GetDaysPassed();
    int daysB = (*apCalendarB)->GetDaysPassed();
    if (daysA < daysB)
        return 1;
    else if (daysA > daysB)
        return -1;
    else
        return 0;
}

struct TileValue_00a0a270
{
    void Tile_Value_SetFloat_00a0a270(float a, bool b);
};
struct FUN_00726db0_class
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    TileValue_00a0a270* m_t;
    void AnimatingText_SetVisibility(bool a);
};
// If m_t is set, calls FUN_00a0a270 on it with 1.0f when a is true and 0.0f otherwise, passing true.
// @fnv 0x00726db0
// src: COMMUNITY 0x00726db0
void FUN_00726db0_class::AnimatingText_SetVisibility(bool abEnabled)
{
    if (m_t)
        m_t->Tile_Value_SetFloat_00a0a270(abEnabled ? 1.0f : 0.0f, true);
}

int GetTileValueID(char const*, int);


// @fnv 0x00726b40
unsigned int VATSMenu::GetFilteredCount()
{
    static int numFiltered = GetTileValueID("_num_filtered", -1);
    // This routine reads its tile from the template-list link slot (offset 0x0C).
    return GetSelectedTargetIndex() - (unsigned int)reinterpret_cast<Tile*>(m_kTileTemplateList.m_pkNext)->GetFloat(numFiltered);
}

struct FUN_0073ac90_shell
{
    void* m_pHead;
    void* NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead();
};
// @fnv 0x0073ac90
// src: XBOX_PDB 0x0073ac90
void* FUN_0073ac90_shell::NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead()
{
    return (char*)(void*)*(void**)this + 8;
}

struct Inner_b9969
{
    Tile* m_00;
    int m_04;
    unsigned char m_08;
};

struct Node_b9969
{
    Node_b9969* Next();
    Inner_b9969** Slot();
};

struct FUN_00725aa0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    float m_20;

    void Log(Tile* v);
    void Finish1();
    void Finish2();
    void ProcessSlots();
};

// Resets m_1c and m_20, iterates the node list calling Set(0xfac, m_1c++) and Log on each slot with m_08 == 0, then calls Finish1 and Finish2.
// @fnv 0x00725aa0
void FUN_00725aa0_cls::ProcessSlots()
{
    m_1c = 0;
    m_20 = 0.0f;
    for (Node_b9969* cur = this ? (Node_b9969*)&unk04 : 0; cur != 0 && *cur->Slot() != 0; cur = cur->Next())
    {
        if ((*cur->Slot())->m_08 == 0)
        {
            (*cur->Slot())->m_00->Set(0xfac, m_1c++);
            Log((*cur->Slot())->m_00);
        }
    }
    Finish1();
    Finish2();
}

extern double DAT_01012060;
extern float __cdecl FUN_004e4430(float value);
extern int __cdecl BSMAX_00647b70(int lower, int upper);
extern int __cdecl Tile_TextToTrait(const char* name);
struct FUN_00725f40_shell
{
    int unk00;
    int unk04;
    int unk08;
    Tile* unk0c;
    int unk10;
    Tile* unk14;
    int unk18;
    int unk1c;
    float unk20;
    int GetUnfilteredItemCount();
    void UpdateScrollTraits();
};
// Reads a float from unk0c, computes a scroll delta from unk20 versus that value, and writes it plus an item count to unk0c and unk14.
// @fnv 0x00725f40
// src: GUESS 0x00725f40 (confidence: medium)
void FUN_00725f40_shell::UpdateScrollTraits()
{
    if (unk0c != 0)
    {
        float iStack_c = unk0c->GetFloat(0xfb0);
        {

            int iItemCount = 1;

            if (unk20 > DAT_01012060 && iStack_c > DAT_01012060)
            {
                if (unk20 > iStack_c)
                {
                    iItemCount = BSMAX_00647b70(
                        (int)FUN_004e4430((float)(unsigned int)GetUnfilteredItemCount() * (unk20 - iStack_c) / unk20) + 1, 2);
                }
                if (iItemCount > 1)
                {
                    unk0c->Set(Tile_TextToTrait("_scroll_delta"), (unk20 - iStack_c) / (iItemCount - 1), true);
                }
            }
            if (unk14 != 0)
            {
                unk14->Set(Tile_TextToTrait("_number_of_items"), iItemCount);
            }
        }
    }
}

struct FNVNodeLink
{
    FNVNodeLink* GetNext();
    void*** GetRef();
};

struct FUN_00726090_cls
{
    int unk00;
    void* m_04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    unsigned short unk1E;
    float m_20;

    void Remove(void* p);
    void Flush();
    void Reset();
    void ListBox_unsigned_int_Synchronize();
};

// Clears m_1c and m_20, notifies and removes each linked object whose byte at offset 8 is zero, then calls Flush and Reset.
// @fnv 0x00726090
// src: XBOX_PDB 0x00726090
void FUN_00726090_cls::ListBox_unsigned_int_Synchronize()
{
    m_1c = 0;
    m_20 = 0.0f;
    for (FNVNodeLink* cur = this ? (FNVNodeLink*)((char*)this + 4) : 0; cur != 0 && *cur->GetRef() != 0;
         cur = cur->GetNext())
    {
        if (((unsigned char*)*cur->GetRef())[8] == 0)
        {
            ((Tile*)**cur->GetRef())->Set(0xfac, m_1c++);
            Remove(**cur->GetRef());
        }
    }
    Flush();
    Reset();
}

// @fnv 0x007273e0
// src: COMMUNITY 0x007273e0
int __cdecl RecipeMenu_GetID()
{
    return (int)1077u;
}

struct Fnv72c700Holder
{
    Tile* m_00;
    int m_04;
    unsigned char m_08;
};

struct Fnv72c700Node
{
    Fnv72c700Node* FUN_00726070();
    Fnv72c700Holder** FUN_006815c0();
};

struct FUN_0072c700_cls
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

    void AccumulateTileHeight(Tile* o);
    void UpdateScrollTraits_0072cba0();
    void UpdateHighlightTraits();
    void UpdateEntryMetrics_0072c700();
};

// @fnv 0x0072c700
// src: GUESS 0x0072c700 (confidence: low)
void FUN_0072c700_cls::UpdateEntryMetrics_0072c700()
{
    m_1c = 0;
    m_20 = 0.0f;
    for (Fnv72c700Node* cur = this != 0 ? (Fnv72c700Node*)((char*)this + 4) : 0; cur != 0 && *cur->FUN_006815c0() != 0;
         cur = cur->FUN_00726070())
    {
        if ((*cur->FUN_006815c0())->m_08 == 0)
        {
            (*cur->FUN_006815c0())->m_00->FUN_00700320(0xfac, m_1c++);
            AccumulateTileHeight((*cur->FUN_006815c0())->m_00);
        }
    }
    UpdateScrollTraits_0072cba0();
    UpdateHighlightTraits();
}

extern double DAT_01012060;
extern float __cdecl FUN_004e4430(float value);
extern int __cdecl BSMAX_00647b70(int lower, int upper);
extern int __cdecl Tile_TextToTrait(const char* name);
struct FUN_0072cba0_cls
{
    int unk00;
    int unk04;
    int unk08;
    Tile* unk0c;
    int unk10;
    Tile* unk14;
    int unk18;
    unsigned short m_1c;
    unsigned short unk1e;
    float m_20;

    unsigned int GetVisibleCount();
    void UpdateScrollTraits_0072cba0();
};

// Computes a scroll item count from the tile's float at 0xfb0 versus m_20 and stores _scroll_delta and _number_of_items on the tiles.
// @fnv 0x0072cba0
// src: GUESS 0x0072cba0 (confidence: medium)
void FUN_0072cba0_cls::UpdateScrollTraits_0072cba0()
{
    if (unk0c)
    {
        float fCurrentAmountNext = unk0c->GetFloat(0xfb0);
        int iCount = 1;
        if (m_20 > DAT_01012060 && fCurrentAmountNext > DAT_01012060)
        {
            if (m_20 > fCurrentAmountNext)
            {
                iCount = BSMAX_00647b70((int)FUN_004e4430((float)(GetVisibleCount() * (m_20 - fCurrentAmountNext) / m_20)) + 1, 2);
            }
            if (iCount > 1)
            {
                unk0c->Set(Tile_TextToTrait("_scroll_delta"), (float)((m_20 - fCurrentAmountNext) / (iCount - 1)), true);
            }
        }
        if (unk14)
        {
            unk14->Set(Tile_TextToTrait("_number_of_items"), iCount);
        }
    }
}

struct InvExtraList;

struct InvExtraListList
{
    InvExtraList** GetFirst();
    void AddHead(InvExtraList*& arItem);
};

struct InvBoundObject;

struct InvEntry
{
    InvExtraListList* pExtendData;
    int iCountDelta;
    InvBoundObject* pType;

    InvEntry(InvBoundObject* apType, int aiCount);
    InvExtraListList* GetExtendData();
    int GetCount();
    void SetCount(int aiCount);
    InvBoundObject* GetType();
};

struct InvEntryList
{
    InvEntry* pItem;
    InvEntryList* pNext;

    void AddTail(InvEntry*& arItem);
};

extern InvEntry* g_pInvPendingEntry;

struct InvOwner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int iMarkerA8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int* pCurrent;
    InvEntryList kListA;
    InvEntryList kListB;

    InvEntry* FindEntry(InvEntryList* apList, InvEntry* apEntry);
    void AddOrUpdateEntryCount(int aiCount);
};

// Finds the pending inventory entry in the active list, adds aiCount to its count, or creates a new entry with the pending type and extra data and appends it.
// @fnv 0x0072faa0
void InvOwner::AddOrUpdateEntryCount(int aiCount)
{
    InvEntryList* pList3 = (pCurrent == &iMarkerA8) ? &kListB : &kListA;
    InvEntry* pEntry3 = FindEntry(pList3, g_pInvPendingEntry);
    InvExtraList* pExtra3 = (pEntry3 && pEntry3->GetExtendData()) ? *pEntry3->GetExtendData()->GetFirst() : 0;

    if (pEntry3)
    {
        pEntry3->SetCount(pEntry3->GetCount() + aiCount);
    }
    else
    {
        InvExtraList* pPendingExtra = (g_pInvPendingEntry && g_pInvPendingEntry->GetExtendData())
                                          ? *g_pInvPendingEntry->GetExtendData()->GetFirst()
                                          : 0;
        pEntry3 = new InvEntry(g_pInvPendingEntry->GetType(), aiCount);
        if (pPendingExtra)
            pEntry3->GetExtendData()->AddHead(pPendingExtra);
        pList3->AddTail(pEntry3);
    }
}
