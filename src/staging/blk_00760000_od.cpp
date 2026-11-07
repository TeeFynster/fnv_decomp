
// src/staging/blk_00760000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/BSSimpleList.h"
#include "../../include/NiFixedString.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/EffectSetting.h"
#include "../../include/Menu.h"

template <>
void BSSimpleArray<NiFixedString, 1024>::Clear(bool freeStorage);

// @fnv 0x007614a0
template <>
BSSimpleArray<NiFixedString, 1024>::~BSSimpleArray()
{
    Clear(true);
}

extern bool* DAT_011d9510;

// @fnv 0x007624d0
// src: XBOX_PDB 0x007624d0
TESSound* DialogMenu_GetDialogSpeaker()
{
    if (DAT_011d9510)
        return reinterpret_cast<EffectSetting*>(DAT_011d9510)->GetCastSound();
    return 0;
}

struct FUN_0076b610_Class
{
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
};

// @fnv 0x0076b610
// src: XBOX_PDB 0x0076b610
bool FUN_0076b610_Class::NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty()
{
    return *(int*)((char*)this + 8) == 0;
}

// @fnv 0x0076b780
bool BSSoundHandle::operator==(unsigned int value) const
{
    return value == GetID();
}

unsigned int __cdecl gm_GetTickCount();

struct FUN_0076bda0_class
{
    FUN_0076bda0_class* __thiscall ProcessAndReturnValue_0076bda0();
    void __thiscall BSTimer_Init(unsigned int);
};

// @fnv 0x0076bda0
// src: GUESS 0x0076bda0 (confidence: low)
FUN_0076bda0_class* __thiscall FUN_0076bda0_class::ProcessAndReturnValue_0076bda0()
{
    BSTimer_Init(gm_GetTickCount());
    return this;
}

struct FUN_00778950_Class
{
    unsigned int GetField188();
};

// @fnv 0x00778950
unsigned int FUN_00778950_Class::GetField188()
{
    return *(unsigned int*)((char*)this + 0x188);
}

struct FUN_0077a450_class
{
    void SetFloats(float a, float b);
};

// Stores the two float arguments at offsets 0x7c and 0x80 of this object.
// @fnv 0x0077a450
void FUN_0077a450_class::SetFloats(float afValue1, float afValue2)
{
    *(float*)((char*)this + 0x7c) = afValue1;
    *(float*)((char*)this + 0x80) = afValue2;
}

// The HUD subtitle array stores pointers to the shared HUD subtitle record type.
class HUDMainMenu__SubtitleData;

template <>
BSSimpleArray<HUDMainMenu__SubtitleData*, 1024>::~BSSimpleArray();

// @fnv 0x0077f970
template <>
BSSimpleArray<HUDMainMenu__SubtitleData*, 1024>::BSSimpleArray()
{
    _InitialSetup(0, 0);
}

// 0x006a8500 frees pBuffer through virtual _Deallocate (slot 2), then clears it.
// The shared array header does not yet declare this storage-release helper.
void __fastcall ReleaseFixedStringArrayBuffer(BSSimpleArray<NiFixedString, 1024>*);

// @fnv 0x007615d0
template <>
void BSSimpleArray<NiFixedString, 1024>::Clear(bool freeStorage)
{
    if (pBuffer)
    {
        ReleaseElements(pBuffer, iSize);
        if (freeStorage)
        {
            ReleaseFixedStringArrayBuffer(this);
            pBuffer = 0;
            SimpleArrayStorage = 0;
        }
        iSize = 0;
    }
}

// Calls the deleting destructor with flag 0 for each fixed string.
// @fnv 0x00761760
template <>
void BSSimpleArray<NiFixedString, 1024>::ReleaseElements(NiFixedString* data, unsigned int n)
{
    for (unsigned int i = 0; i < n; ++i)
        (data + i)->FUN_004b9900(0);
}

struct GlobalObject_0076b930
{
    void __thiscall FUN_0076b930();
    GlobalObject_0076b930* __thiscall FUN_0076b870(unsigned int flags);
};
// Calls FUN_0076b930 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0076b870
GlobalObject_0076b930* __thiscall GlobalObject_0076b930::FUN_0076b870(unsigned int flags)
{
    this->FUN_0076b930();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_0076b8a0_class
{
    BSSimpleList<BSSoundHandle> m_kNode;
    ~FUN_0076b8a0_class();
};
// Destructor that removes all elements from the contained BSSimpleList.
// @fnv 0x0076b8a0
FUN_0076b8a0_class::~FUN_0076b8a0_class()
{
    m_kNode.RemoveAll();
}

namespace fnv_0076b900 {
struct FUN_0076b900 : BSSoundHandle
{
    int fldC;
    FUN_0076b900(FUN_0076b900 const&);
};
// @fnv 0x0076b900
FUN_0076b900::FUN_0076b900(FUN_0076b900 const& o) : BSSoundHandle(o)
{
    fldC = 0;
}
}  // namespace fnv_0076b900

namespace fnv_0076b930 {
struct FUN_0076b930
{
    BSSoundHandle _00;
    int _0C;
    FUN_0076b930();
};
// Initializes the object: constructs the first member with sound ID zero and sets the field at offset 0x0C to 0.
// @fnv 0x0076b930
FUN_0076b930::FUN_0076b930() : _00(0u)
{
    _0C = 0;
}
}  // namespace fnv_0076b930

struct WeatherEntry;
struct G2
{
    void __thiscall AddHead(WeatherEntry*&);
};
extern int g_011d970c;
int __cdecl QuestUpdateManager_SortQuestNamesByPriorityFunction(WeatherEntry*, WeatherEntry*);
// Adds a WeatherEntry to the list at g_011d970c and sorts it using FUN_0076bb00 as the comparison.
// @fnv 0x0076baa0
// src: COMMUNITY 0x0076baa0
void __cdecl QuestUpdateManager_AddQuestNamesHead(WeatherEntry* apEntry)
{
    ((G2*)&g_011d970c)->AddHead(apEntry);
    ((BSSimpleList<WeatherEntry*>*)&g_011d970c)->Sort(&QuestUpdateManager_SortQuestNamesByPriorityFunction);
}

// Compares the int at offset 0x214 of two objects, returning 1 if the first is greater, -1 if less, else 0.
// @fnv 0x0076bb00
// src: COMMUNITY 0x0076bb00
int __cdecl QuestUpdateManager_SortQuestNamesByPriorityFunction(void* pLeft, void* pRight)
{
    if (*((int*)((char*)pLeft + 0x214)) > *((int*)((char*)pRight + 0x214)))
        return 1;
    else if (*((int*)((char*)pLeft + 0x214)) < *((int*)((char*)pRight + 0x214)))
        return -1;
    else
        return 0;
}

extern "C" void* _pme;

// If _pme is set and its field at offset 0x1b8 equals param_1, clears that field to 0 and returns true; otherwise returns false.
// @fnv 0x00778b40
bool __cdecl ClearPmeIfMatches(int aiValue)
{
    if (_pme && *(int*)((char*)_pme + 0x1b8) == aiValue)
    {
        *(int*)((char*)_pme + 0x1b8) = 0;
        return true;
    }
    return false;
}

// @fnv 0x0077f9c0
// src: COMMUNITY 0x0077f9c0
int __cdecl sqr_int(int a)
{
    return a * a;
}

template <>
unsigned int BSSimpleArray<NiFixedString, 1024>::ReserveIndex();
template <>
void BSSimpleArray<NiFixedString, 1024>::InitializeItems(NiFixedString*, unsigned int);

// @fnv 0x007614c0
template <>
unsigned int BSSimpleArray<NiFixedString, 1024>::ReserveIndex(const NiFixedString& value)
{
    unsigned int size = ReserveIndex();
    InitializeItems(pBuffer + size, 1);
    (pBuffer + size)->AssignInternedString(value);
    return size;
}

// @fnv 0x007616d0
template <>
void BSSimpleArray<NiFixedString, 1024>::_InitialSetup(unsigned int requested, unsigned int savedSize)
{
    pBuffer = 0;
    iSize = 0;
    SimpleArrayStorage = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        pBuffer = _Allocate(requested);
        SimpleArrayStorage = requested;
    }
    if (savedSize > 0)
    {
        InitializeItems(pBuffer, savedSize);
        iSize = savedSize;
    }
}

// @fnv 0x0076a3b0
bool BSSoundHandle::operator!=(unsigned int value)
{
    return value != GetID();
}

struct TESFaction_RankDataView
{
    unsigned char* GetRankDataList();
    bool HasFlag40();
};
// @fnv 0x0077a590
bool TESFaction_RankDataView::HasFlag40()
{
    return (GetRankDataList()[0] & 0x40) != 0;
}

// @fnv 0x0077f9a0
template <>
BSSimpleArray<HUDMainMenu__SubtitleData*, 1024>::~BSSimpleArray()
{
    Clear(true);
}

// These capacity-query helpers are not declared by the shared array header.
bool __fastcall IsFixedStringArrayFull(BSSimpleArray<NiFixedString, 1024>*);
unsigned int __fastcall NextFixedStringArrayCapacity(BSSimpleArray<NiFixedString, 1024>*);

// @fnv 0x00761540
template <>
unsigned int BSSimpleArray<NiFixedString, 1024>::ReserveIndex()
{
    if (IsFixedStringArrayFull(this))
    {
        if (SimpleArrayStorage == 0)
        {
            unsigned int v = 4;
            pBuffer = _Allocate(v);
            SimpleArrayStorage = v;
        }
        else
        {
            unsigned int p = NextFixedStringArrayCapacity(this);
            ReallocateStorage(p, iSize);
            SimpleArrayStorage = p;
        }
    }
    iSize = iSize + 1;
    return iSize - 1;
}

void* __cdecl operator new(unsigned int size, void* where);
void __cdecl operator delete(void* p, void* where);

// Placement-constructs count fixed strings into the array.
// @fnv 0x00761630
template <>
void BSSimpleArray<NiFixedString, 1024>::InitializeItems(NiFixedString* pItems, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++)
    {
        ::new (&pItems[i]) NiFixedString;
    }
}

class B766A50Menu
{
  public:
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
    int unk0A8;
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
    int unk108;
    void* m_apSlots[8];

    bool HasAllSlots(int& riIndex);
};

// Returns false if any of the 8 m_apSlots entries is null, otherwise true; riIndex is left at 8 after the loop.
// @fnv 0x00766a50
bool B766A50Menu::HasAllSlots(int& riSlotIndex)
{
    for (riSlotIndex = 0; riSlotIndex < 8; riSlotIndex++)
    {
        if (!m_apSlots[riSlotIndex])
            return false;
    }
    return true;
}

class B76B560Object
{
  public:
    virtual ~B76B560Object();
};

class B76B560Base
{
  public:
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

    ~B76B560Base();
};

class FUN_0076b560 : public B76B560Base
{
  public:
    B76B560Object* m_pkFirst;
    B76B560Object* m_pkSecond;

    ~FUN_0076b560();
};

// Destructor that deletes m_pkFirst and m_pkSecond.
// @fnv 0x0076b560
FUN_0076b560::~FUN_0076b560()
{
    delete m_pkFirst;
    delete m_pkSecond;
}

struct FUN_0076b900
{
    BSSoundHandle sound;
    FUN_0076b900* next;
    FUN_0076b900(const BSSoundHandle& owner);
};

struct Owner : BSSoundHandle
{
    FUN_0076b900* first;

    void BSSimpleList_BSSoundHandle_AddHead(const BSSoundHandle* value);
};

// If value has a nonzero sound ID, saves the current nonzero handle in a new node, then copies value.
// @fnv 0x0076b6a0
// src: COMMUNITY 0x0076b6a0
void Owner::BSSimpleList_BSSoundHandle_AddHead(const BSSoundHandle* value)
{
    if (*value == 0)
    {
    }
    else
    {
        if (BSSoundHandle::operator!=(0))
        {
            FUN_0076b900* entry = new FUN_0076b900(*this);
            entry->next = first;
            first = entry;
            BSSoundHandle::operator=(*value);
        }
        else
        {
            BSSoundHandle::operator=(*value);
        }
    }
}

struct ListStub
{
    int item;
    ListStub* next;
    ListStub();
    ~ListStub();
};
struct B6815c0
{
    int c0;
    int c4;
    int c8;
    int cc;
    int d0;
    int d4;
    int d8;
    int dc;
    int e0;
    int e4;
    int e8;
    int ec;
    int f0;
    B6815c0();
    ~B6815c0();
};
struct C76bda0
{
    int e0;
    int e4;
    int e8;
    int ec;
    int f0;
    int f4;
    int f8;
    int fc;
    C76bda0();
};
struct TimeGlobalStub
{
    int GetTime();
};
struct GO709f00Stub
{
    bool Check();
};
extern TimeGlobalStub g_timeGlobal;
extern GO709f00Stub g_011d8a38;
extern int DAT_011d96ac;

struct FUN_0076bb40 : Menu
{
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
    int unkfc;
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
    float unk188;
    ListStub list18c;
    int unk194;
    BSSimpleArray<HUDMainMenu__SubtitleData*, 1024> ax198;
    int unk1a8;
    BSSoundHandle go1ac;
    int unk1b8;
    int unk1bc;
    unsigned int flags1c0;
    int unk1c4;
    B6815c0 b1c8;
    bool unk1fc;
    int unk200;
    bool unk204;
    bool unk205;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    C76bda0 c224;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    bool unk254;
    ListStub list258;
    bool unk260;
    bool unk261;
    ListStub list264;
    ListStub list26c;
    float unk274;
    FUN_0076bb40();
    virtual ~FUN_0076bb40();
};

void* __cdecl memset(void*, int, unsigned int);

// @fnv 0x0076bb40
FUN_0076bb40::FUN_0076bb40()
{
    memset(&unk28, 0, 0x158);
    unk184 = 0;
    unk188 = 0.0f;
    unk1b8 = 0;
    unk21c = 0;
    unk244 = 0;
    unk248 = g_timeGlobal.GetTime();
    unk24c = -1;
    unk250 = -1;
    flags1c0 = (g_011d8a38.Check() ? 0x40 : 0) | 0x3f | 0x80 | 0x100 | 0x200 | 0x400 | 0x800 | 0x1000 | 0x2000 |
               0x4000 | 0x8000 | 0x10000;
    unk1c4 = 4;
    unk254 = false;
    DAT_011d96ac = g_timeGlobal.GetTime();
    unk1fc = false;
    unk200 = 0;
    unk274 = 0.0f;
    unk204 = false;
    unk194 = 0;
    unk1a8 = 0;
    unk205 = false;
    unk260 = false;
    unk261 = false;
    unk20c = 0;
}

namespace fnv_007617a0 {
struct FUN_007642f0
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
    FUN_007642f0();
    ~FUN_007642f0();
};
struct B006815c0
{
    int unk00;
    int unk04;
    B006815c0();
};
extern bool DAT_011d9514;
extern float DAT_011a008c;
void* __cdecl GetInstance();
struct FUN_007617a0 : Menu
{
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    FUN_007642f0 member40;
    void* unk70;
    BSSoundHandle member74;
    int unk80;
    bool unk84;
    char unk85;
    short unk86;
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
    bool unk104;
    char unk105;
    short unk106;
    float unk108;
    int unk10c;
    B006815c0 member110;
    B006815c0 member118;
    B006815c0 member120;
    int unk128;
    int unk12c;
    bool unk130;
    bool unk131;
    short unk132;
    int unk134;
    bool unk138;
    bool unk139;
    bool unk13a;
    FUN_007617a0();
    virtual ~FUN_007617a0();
};
// @fnv 0x007617a0
FUN_007617a0::FUN_007617a0()
{
    unk80 = 0;
    DAT_011d9514 = true;
    unk130 = false;
    unk131 = false;
    unk138 = false;
    unk108 = 0.0f;
    unk28 = 0;
    unk2c = 0;
    unk70 = GetInstance();
    unk84 = false;
    unk104 = false;
    unk12c = 0;
    DAT_011a008c = 100.0f;
    unk139 = false;
    unk13a = false;
    unk10c = 0;
}
}  // namespace fnv_007617a0

struct WeatherEntry
{
    int unk00;
    int kind;
    char title[260];
    char subtitle[260];
    int unk210;
    int priority;
    int titleFont;
    int subtitleFont;
    char icon[260];
};
void* __cdecl operator new(unsigned int);
int __cdecl strcpy_s(char*, unsigned int, const char*);
void __cdecl Warning_005b5e40(int, const char*, ...);
void __cdecl QuestUpdateManager_AddQuestNamesTail(char*);
// Allocates a WeatherEntry, copies the title, subtitle and icon strings, validates the fonts, and queues the entry by priority.
// @fnv 0x0076b960
// src: EXE 0x0076b960
void __cdecl QuestUpdateManager_SetCustomQuestText(const char* title, const char* subtitle, int priority, int extra, int titleFont,
                          int subtitleFont, const char* icon)
{
    WeatherEntry* entry = new WeatherEntry;
    entry->kind = 3;
    strcpy_s(entry->title, 260, title);
    strcpy_s(entry->subtitle, 260, subtitle);
    entry->unk210 = extra;
    entry->priority = priority;
    if (titleFont == 0)
    {
        Warning_005b5e40(
            7,
            "QuestUpdateManager::SetCustomQuestText() - FONT_1 is an invalid value for aiCustomTextTitleFont.  Setting to FONT_NONE.");
        titleFont = -1;
    }
    entry->titleFont = titleFont;
    if (subtitleFont == 0)
    {
        Warning_005b5e40(
            7,
            "QuestUpdateManager::SetCustomQuestText() - FONT_1 is an invalid value for aiCustomTextSubtitleFont.  Setting to FONT_NONE.");
        subtitleFont = -1;
    }
    entry->subtitleFont = subtitleFont;
    strcpy_s(entry->icon, 260, icon);
    switch (priority)
    {
    case 1:
    case 2:
        QuestUpdateManager_AddQuestNamesTail((char*)entry);
        break;
    case 0:
        QuestUpdateManager_AddQuestNamesHead(entry);
        break;
    default:
        Warning_005b5e40(
            7,
            "QuestUpdateManager::SetCustomQuestText() - Invalid aiCustomQueuePriority (%i)!  Setting to HCQQP_NORMAL.",
            priority);
        QuestUpdateManager_AddQuestNamesTail((char*)entry);
        break;
    }
}

struct Arr77a400
{
    int m_unk00;
    void* m_pData;
    unsigned int m_Size;
    unsigned int GetSize();
    int* GetAt(int index);
};

struct C77a400
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
    int unk0A8;
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
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int m_unk6f4;
    int m_unk6f8;
    int m_unk6fc;
    int m_unk700;
    int m_unk704;
    Arr77a400 m_Arr708;

    unsigned int GetFirstOrFallback();
};

// Returns the first element of m_Arr708 if the array is non-empty, otherwise returns m_unk6f4.
// @fnv 0x0077a400
unsigned int C77a400::GetFirstOrFallback()
{
    return this->m_Arr708.GetSize() > 0 ? (unsigned int)*this->m_Arr708.GetAt(0) : (unsigned int)this->m_unk6f4;
}

class HKTile
{
  public:
    const char* Tile_GetString(int m_iValueId);
    float FUN_00a011b0(int m_iValueId);
    void Tile_Set_00a01350(int m_iValueId, const char* pcValue, int iFlag);
    void FUN_00700320(int m_iValueId, int iValue);
    void Tile_Set(int m_iValueId, float fValue, int iFlag);
};

struct HKScreen
{
    int unk00[51];
    HKTile* m_pkTextTile;  // +0xcc
};
extern HKScreen* DAT_011d95bc;

struct HKWordNode
{
    char** FUN_006815c0();
    HKWordNode* FUN_00726070();
};

struct HKWordSet
{
    bool ForwardCall_0076a3d0(const char* pcWord);
    void AssignString(const char* pcWord);
    unsigned int TESMain_GetThread(int iFlag);
};

struct HKOffsetMap
{
    int FUN_0049c680(unsigned int* puiOffset, int iFlag);
};

struct HKSoundNode
{
    BSSoundHandle* FUN_006815c0();
    HKSoundNode* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct HKSoundList : HKSoundNode
{
    void ClearQueue();
    void BSSimpleList_BSSoundHandle_AddHead(const BSSoundHandle& kSound);
};
extern HKSoundList DAT_011d9604;

class HKAudio
{
  public:
    static HKAudio* BSAudioManager_QInstance_00ad9060();
    BSSoundHandle ResolveAudioHandle(const char* pcName, int iFlags);
};

int FUN_00ec86e1(int iChar);
void* ourMemset(void* pvDst, int iValue, unsigned int uiSize);
void* FUN_00401460(void* pvDst, const void* pvSrc, unsigned int uiSize);
unsigned int BSstrlen(const char* pcString);

class HKMenu
{
  public:
    int unk000[56];
    HKWordSet m_kGuessed;  // +0xe0
    int unk0e4[12];
    HKTile* m_pkHighlight;  // +0x114
    int unk118[26];
    HKWordNode m_kWords;  // +0x180
    int unk184;
    HKOffsetMap m_kSymbols;  // +0x188
    int unk18c[7];
    unsigned int m_uiWordCount;      // +0x1a8
    unsigned int m_uiWordLength;     // +0x1ac
    unsigned int* m_puiWordOffsets;  // +0x1b0
    int unk1b4;
    int unk1b8;
    int m_iLastPos;        // +0x1bc
    HKTile* m_pkLastTile;  // +0x1c0
    int unk1c4[5];
    bool m_bShowing;  // +0x1d8

    int GetScaledValue();
    void ClearEntry();
    void GetGarbageString(char* pcOut, const char* pcText);
    HKTile* FindTile(int iColumn, unsigned int uiLine);
    void UpdateHighlight();
};

// Recomputes the cursor position and the word at it from the text tile, updates the guessed-word state and sounds, and sets m_pkHighlight's text and coordinates.
// @fnv 0x00769b50
void HKMenu::UpdateHighlight()
{
    int iPos = GetScaledValue() - 7;
    if ((iPos == m_iLastPos && DAT_011d95bc->m_pkTextTile == m_pkLastTile) || (iPos < 0 && m_iLastPos < 0))
        return;
    m_iLastPos = iPos;
    m_pkLastTile = DAT_011d95bc->m_pkTextTile;
    if (iPos < 0)
    {
        ClearEntry();
        m_bShowing = false;
        return;
    }
    if (m_bShowing)
    {
        ClearEntry();
        if (!FUN_00ec86e1(DAT_011d95bc->m_pkTextTile->Tile_GetString(0xfc4)[iPos + 7]))
        {
            m_bShowing = false;
            m_pkLastTile = 0;
        }
        return;
    }
    unsigned int uiElapsedMilliseconds = (unsigned int)((DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0x1004) * 17.0 +
                                                         DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfac)) *
                                                            12.0 +
                                                        iPos);
    HKWordNode* pkNodeTmp = &m_kWords;
    for (unsigned int j = 0; j < m_uiWordCount; j++)
    {
        if (uiElapsedMilliseconds >= m_puiWordOffsets[j] &&
            uiElapsedMilliseconds < m_puiWordOffsets[j] + m_uiWordLength)
            break;
        else
            pkNodeTmp = pkNodeTmp->FUN_00726070();
    }
    char acWordNext[32];
    ourMemset(acWordNext, 0, 0x20);
    if (pkNodeTmp)
        FUN_00401460(acWordNext, *pkNodeTmp->FUN_006815c0(), m_uiWordLength);
    else if (!m_kSymbols.FUN_0049c680(&uiElapsedMilliseconds, 0))
        GetGarbageString(acWordNext, DAT_011d95bc->m_pkTextTile->Tile_GetString(0xfc4) + GetScaledValue());
    else
        acWordNext[0] = DAT_011d95bc->m_pkTextTile->Tile_GetString(0xfc4)[GetScaledValue()];
    if (m_kGuessed.ForwardCall_0076a3d0(acWordNext))
    {
        m_kGuessed.AssignString(acWordNext);
        for (HKSoundNode* pkSound = &DAT_011d9604; pkSound && pkSound->FUN_006815c0()->operator!=(-1);
             pkSound = pkSound->GetHavokWorldObjectCountInSceneGraph_0084e3a0())
            pkSound->FUN_006815c0()->Release();
        DAT_011d9604.ClearQueue();
        unsigned int ItemUpdateArray = BSstrlen(acWordNext);
        while (ItemUpdateArray--)
        {
            BSSoundHandle kSound = HKAudio::BSAudioManager_QInstance_00ad9060()->ResolveAudioHandle("UIHackingCharSingle", 0x121);
            DAT_011d9604.BSSimpleList_BSSoundHandle_AddHead(kSound);
            if (ItemUpdateArray)
                // This original call to 0x00ad8870 passes only the delay; preserve its one-argument ABI.
                (kSound.*reinterpret_cast<void (BSSoundHandle::*)(int)>(&BSSoundHandle::PlayAfter))(
                    (int)(m_kGuessed.TESMain_GetThread(0) * ItemUpdateArray * 1.5));
            else
                kSound.Play(false);
        }
    }
    bool bFound = false;
    iPos = GetScaledValue();
    if (pkNodeTmp)
    {
        const char* pcText = DAT_011d95bc->m_pkTextTile->Tile_GetString(0xfc4);
        while (FUN_00ec86e1(pcText[iPos - 1]))
            iPos--;
        for (unsigned int k = 1; !bFound && k < m_uiWordLength; k++)
        {
            int iXNew = (int)DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfa1);
            int iY = (int)DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfa2);
            int iX2Cur = iXNew + 0x77;
            int iY2 = iY;
            if (!pcText[iPos + k])
            {
                bFound = true;
                iXNew += iPos * 0x11;
                if (DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfac) + 1.0 < 17.0)
                    iY2 += (int)DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfb0);
                else
                {
                    HKTile* pkLine =
                        FindTile(0, (unsigned int)DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0x1004) + 1);
                    iX2Cur = (int)(pkLine->FUN_00a011b0(0xfa1) + 119.0);
                    iY2 = (int)pkLine->FUN_00a011b0(0xfa2);
                }
            }
            else if (!FUN_00ec86e1(pcText[iPos + k]))
            {
                bFound = true;
                k = m_uiWordLength - k;
                if (DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfac) != 0.0)
                {
                    iXNew += (0x13 - k) * 0x11;
                    iY -= (int)DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfb0);
                }
                else
                {
                    HKTile* pkPrevLine =
                        FindTile(0x10, (unsigned int)DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0x1004) - 1);
                    iXNew = (int)(pkPrevLine->FUN_00a011b0(0xfa1) + (0x13 - k) * 0x11);
                    iY = (int)pkPrevLine->FUN_00a011b0(0xfa2);
                }
            }
            if (bFound)
            {
                char cSaved = acWordNext[k];
                acWordNext[k] = 0;
                m_pkHighlight->Tile_Set_00a01350(0x1004, acWordNext, 1);
                m_pkHighlight->FUN_00700320(0x1005, iXNew);
                m_pkHighlight->FUN_00700320(0x1006, iY);
                acWordNext[k] = cSaved;
                m_pkHighlight->Tile_Set_00a01350(0x1007, &acWordNext[k], 1);
                m_pkHighlight->FUN_00700320(0x1008, iX2Cur);
                m_pkHighlight->FUN_00700320(0x1009, iY2);
            }
        }
    }
    if (!bFound)
    {
        m_pkHighlight->Tile_Set_00a01350(0x1004, acWordNext, 1);
        m_pkHighlight->Tile_Set(0x1005, DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfa1) + iPos * 0x11, 1);
        m_pkHighlight->Tile_Set(0x1006, DAT_011d95bc->m_pkTextTile->FUN_00a011b0(0xfa2), 1);
        m_pkHighlight->FUN_00700320(0x1008, -1);
    }
}
