#include "../../../../include/HackingMenu.h"
#include "../../../../include/SL.h"
#include "../../../../include/BSStringT.h"
#include "../../../../include/FORenderedTerminal.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/Tile.h"
#include "../../../../include/InterfaceManager.h"

struct HackTile
{
    const char* GetString(int);
    void Set(int, const char*, bool);
    bool ContainsTrait(int);
};
struct HackEntry
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
    HackTile* tile;
};
// src/fallout/interface/menus/hackingmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/hackingmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_006ffe80_shell
{
    int x;
    int y;
    int a;
    int b;
    void FUN_006ffe80(int a, int b);
};

// @fnv 0x006ffe80
void FUN_006ffe80_shell::FUN_006ffe80(int aiFirst, int aiSecond)
{
    this->a = aiFirst;
    this->b = aiSecond;
}


// @fnv 0x00765870
int __thiscall HackingMenu::FUN_00765870()
{
    return 0x41f;
}

namespace fnv_00765880 {


// Stores apTile into the tile slot array at index aiID when aiID is in [0, 8).
} // namespace fnv_00765880

// @fnv 0x00765880
void HackingMenu::SetTile(int aiID, Tile* apTile)
{
    using namespace fnv_00765880;
    if (aiID >= 0 && aiID < 8)
    {
        m_pTiles[aiID] = apTile;
    }
}


namespace fnv_007658b0 {
void __cdecl _Deallocate(void* p);


// Calls the HackingMenu destructor and, when bit 0 of flags is set, deallocates this; returns this.
} // namespace fnv_007658b0

// @fnv 0x007658b0
void* HackingMenu::Destroy(unsigned int flags)
{
    using namespace fnv_007658b0;
    HackingMenu::~HackingMenu();
    if (flags & 1)
        _Deallocate(this);
    return this;
}


// @fnv 0x00766a40
int __cdecl FUN_00766a40()
{
    return 0x41f;
}

namespace fnv_00767ff0 {

} // namespace fnv_00767ff0

// @fnv 0x00767ff0
void HackingMenu::FUN_00767ff0(int aiID, void* apTarget)
{
    using namespace fnv_00767ff0;
    ClearTilePayloadPair();
    ((char*)this)[0x1d8] = 0;
    *(int*)((char*)this + 0x1c0) = 0;
}


struct WeatherEntry;

struct WeatherEntryList
{
    void __thiscall Sort(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
};

int __cdecl FUN_0076b2e0(WeatherEntry*, WeatherEntry*);

struct FUN_007687b0_shell : WeatherEntryList
{
    void SortWeatherEntries();
};

// @fnv 0x007687b0
void FUN_007687b0_shell::SortWeatherEntries()
{
    this->Sort(&FUN_0076b2e0);
}

// Returns the larger of the two unsigned byte arguments.
// @fnv 0x0076af60
char MaxByte(unsigned char a, unsigned char b)
{
    return a > b ? a : b;
}

extern "C" unsigned int __cdecl FUN_005a00a0(unsigned int);

// @fnv 0x0076b2e0
unsigned int __cdecl FUN_0076b2e0()
{
    return FUN_005a00a0(2) * 2 - 1;
}


// @fnv 0x00747d00
int __thiscall InterfaceManager::FUN_00747d00()
{
    return (int)(UpdateInterfaceState() / 2.0 + *(float*)((char*)this + 0x2c));
}

unsigned int __cdecl gm_GetTickCount();



// Calls FUN_0076a540 when gm_GetTickCount() exceeds the tick value stored at this+0x1d0.
// @fnv 0x0076a510
void __thiscall HackingMenu::FUN_0076a510()
{
    if (gm_GetTickCount() > *(unsigned int*)((char*)this + 0x1d0))
    {
        FUN_0076a540();
    }
}

// 0x00726c90 constructs the BSStringT base, then initializes the animation state at 0x006ffe10.
struct HackingTextAnimation : BSStringT<char>
{
    HackingTextAnimation();
    void FUN_006ffe10();
};
// Constructs the object by calling FUN_006ffe10.
// @fnv 0x00726c90
HackingTextAnimation::HackingTextAnimation()
{
    FUN_006ffe10();
}

struct ListX
{
    ~ListX();
};
struct FUN_00765810 : ListX
{
    void __thiscall FreeAll();
    ~FUN_00765810();
};
// @fnv 0x00765810
FUN_00765810::~FUN_00765810()
{
    FreeAll();
}

void __cdecl Deallocate(void* p);
struct FUN_0076b560_shell
{
    void __thiscall FUN_0076b560();
    void* __thiscall FUN_00765b50(unsigned int flags);
};
// Calls FUN_0076b560, then frees this with Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00765b50
void* __thiscall FUN_0076b560_shell::FUN_00765b50(unsigned int flags)
{
    FUN_0076b560();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl UpdateD766AA0Menu();
// If aiButton is 10, stores 4 at offset 0x1c4, calls UpdateD766AA0Menu and returns true; otherwise returns false.
// @fnv 0x00767b80
bool __thiscall HackingMenu::HandleMenuInput(int aiButton, float afValue)
{
    if (aiButton == 10)
    {
        *(int*)((char*)this + 0x1c4) = 4;
        UpdateD766AA0Menu();
        return true;
    }
    return false;
}

struct T7021b0
{
    int __thiscall DestroyOrFree(int);
};
struct C7687d0
{
    void __thiscall FUN_007687d0();
};
// Reads a pointer from this, and if it is non-null calls its DestroyOrFree with 3.
// @fnv 0x007687d0
void __thiscall C7687d0::FUN_007687d0()
{
    T7021b0* q;
    {
        T7021b0* a = *reinterpret_cast<T7021b0**>(this);
        q = a;
    }
    q ? q->DestroyOrFree(3) : 0;
}

extern "C" void __cdecl _Deallocate(void*);

struct FUN_00768920_shell
{
    void* p;
    void* q;
    void __thiscall FUN_00768920(void* n);
};
// @fnv 0x00768920
void __thiscall FUN_00768920_shell::FUN_00768920(void* n)
{
    void* pOldBuffer = p;
    void* pNewBuffer;
    _Deallocate(pOldBuffer);
    q = n;
    pNewBuffer = operator new((unsigned int)n);
    p = pNewBuffer;
}

unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);
unsigned int __cdecl BSStringLength(const char*);
// Returns 0 if either string is null, otherwise counts positions up to the shorter length where the two strings have equal characters.
// @fnv 0x00768a10
unsigned int __thiscall HackingMenu::CountMatchingChars(const char* pcStringA, const char* pcStringB)
{
    if (!pcStringA || !pcStringB)
        return 0;
    unsigned int icnt = 0;
    unsigned int ilen = FUN_0042f5a0(BSStringLength(pcStringA), BSStringLength(pcStringB));
    for (unsigned int i = 0; i < ilen; ++i)
    {
        if (pcStringA[i] == pcStringB[i])
            ++icnt;
    }
    return icnt;
}

struct FUN_007694f0_shell
{
    void __thiscall FUN_00726c90();
    int __thiscall FUN_007694f0();
};

// Calls FUN_00726c90, then zeroes the int fields at offsets 0x30 and 0x2c and returns this.
// @fnv 0x007694f0
int __thiscall FUN_007694f0_shell::FUN_007694f0()
{
    FUN_00726c90();
    *(int*)((char*)this + 0x30) = 0;
    *(int*)((char*)this + 0x2c) = 0;
    return (int)this;
}

struct Struct0076ae30
{
    unsigned char* buf;
    unsigned int cnt;
    int __thiscall FindByteIndices(int, unsigned char*);
};
// Scans buf for bytes equal to v, writes their indices into out, and returns how many were found.
// @fnv 0x0076ae30
int __thiscall Struct0076ae30::FindByteIndices(int aiValue, unsigned char* pIndices)
{
    unsigned char c = 0;
    for (unsigned int i = 0; i < cnt; i++)
    {
        if (buf[i] == aiValue)
        {
            pIndices[c++] = (unsigned char)i;
        }
    }
    return c;
}

struct Struct0076b090
{
    int field0;
    void __thiscall CopyFrom(int);
    Struct0076b090* __thiscall Construct(int);
};
// Resets field0 to 0, calls CopyFrom with a, and returns this.
// @fnv 0x0076b090
Struct0076b090* __thiscall Struct0076b090::Construct(int aiValue)
{
    field0 = 0;
    CopyFrom(aiValue);
    return this;
}

void* __cdecl __memcpy(void*, const void*, unsigned int);
struct STR_0076b200
{
    void* f0;
    unsigned int f4;
    STR_0076b200();   // 0x0096a2d0 (zeroes both words)
    ~STR_0076b200();  // 0x00702220 (frees f0)
    void FUN_00768920(unsigned int);
    STR_0076b200* AssignFrom(STR_0076b200*);
};
// @fnv 0x0076b200
STR_0076b200* STR_0076b200::AssignFrom(STR_0076b200* apSource)
{
    FUN_00768920(apSource->f4);
    __memcpy(f0, apSource->f0, f4);
    return this;
}

unsigned int __cdecl BSStringLength(char const*);
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, char const*);
};
struct G2
{
    void AddHead(int*);
};
struct FUN_0076b240_shell
{
    void __thiscall FUN_0076b240(const char* s);
};
// @fnv 0x0076b240
void __thiscall FUN_0076b240_shell::FUN_0076b240(const char* apString)
{
    unsigned int size = BSStringLength(apString) + 1;
    char* buffer = new char[size];
    TaskQueueInterface::CopyStringToBuffer(buffer, size, apString);
    reinterpret_cast<G2*>(this)->AddHead(reinterpret_cast<int*>(&buffer));
}

namespace fnv_0076b2a0 {
extern "C" void __cdecl Deallocate(void*);
struct FUN_0076b2a0_shell
{
    void* m_p;
    void __thiscall FUN_0063f7b0();
    void __thiscall FreeAll();
};
// Repeatedly deallocates the object at m_p and calls FUN_0063f7b0 until m_p becomes null.
// @fnv 0x0076b2a0
void __thiscall FUN_0076b2a0_shell::FreeAll()
{
    while (m_p)
    {
        void* p = m_p;
        Deallocate(p);
        FUN_0063f7b0();
    }
}
}  // namespace fnv_0076b2a0

// @fnv 0x00768020
void __thiscall HackingMenu::FUN_00768020()
{
    anim.AssignString(0);
    m_pTiles[2]->Set(0x1005, -1);
    m_pTiles[2]->Set(0x1008, -1);
}

int __cdecl FUN_004dc1f0(void);
struct MyHack
{
    unsigned char _pad0[0x4AC];
    float f4AC;
    unsigned char _pad1[0x20];
    float f4D0;
    float __thiscall FUN_007697f0();
};
// Returns f4AC multiplied by 1280.0, divided by the result of FUN_004dc1f0, then multiplied by f4D0.
// @fnv 0x007697f0
float __thiscall MyHack::FUN_007697f0()
{
    return (float)(f4AC * 1280.0 / FUN_004dc1f0() * f4D0);
}


// Writes "0x" followed by the four hex digits of v (most significant first) into dst and null-terminates it.
// @fnv 0x00768970
void __thiscall HackingMenu::FormatHexWord(unsigned short ausValue, char* pDest)
{
    __memcpy(pDest, "0x", 2);
    for (int i = 0; i < 4; i++)
    {
        unsigned char c;
        c = (ausValue & (0xf << (i * 4))) >> (i * 4);
        pDest[5 - i] = c < 10 ? c + 0x30 : c + 0x37;
    }
    pDest[6] = 0;
}

struct TGF
{
    float __thiscall GetFloat(int value) const;
};

struct TileHelper
{
    bool __thiscall ContainsTrait(int value);
};



// Scans 46 entries for one whose value is non-null, passes a check, and whose floats at 0xfac and 0x1004 equal a and b; returns that value or null.
// @fnv 0x00767bb0
Tile* __thiscall HackingMenu::FUN_00767bb0(int iColumn, int iNewRow)
{
    for (unsigned int i = 0; i < 46; ++i)
    {
        if (reinterpret_cast<TGF*>(entries[i]->tile) != 0 && reinterpret_cast<TileHelper*>(reinterpret_cast<TGF*>(entries[i]->tile))->ContainsTrait(0xfaf) &&
            reinterpret_cast<TGF*>(entries[i]->tile)->GetFloat(0xfac) == static_cast<unsigned int>(iColumn) && reinterpret_cast<TGF*>(entries[i]->tile)->GetFloat(0x1004) == static_cast<unsigned int>(iNewRow))
        {
            return reinterpret_cast<Tile*>(entries[i]->tile);
        }
    }

    return 0;
}

void* __cdecl operator new(unsigned int);

struct FUN_00768810
{
    STR_0076b200* pItems;
    unsigned int uiSize;

    FUN_00768810(unsigned int aiSize);
};

// Stores aiSize, allocates an STR_0076b200 array of that size, and initializes each element via FUN_00768920(uiSize).
// @fnv 0x00768810
FUN_00768810::FUN_00768810(unsigned int aiSize)
{
    unsigned int i;

    uiSize = aiSize;
    pItems = new STR_0076b200[aiSize];

    for (i = 0; i < uiSize; ++i)
        pItems[i].FUN_00768920(uiSize);
}

struct FUN_007021b0_cls
{
    void FUN_00702220();
    void* DestroyOrFree(unsigned int flags);
};

extern "C" void __stdcall FUN_00ec5fce(void* object, int elementSize, int count, void (FUN_007021b0_cls::*callback)());

extern "C" void __cdecl FormHeap_Free(void* apMemory);

// Destroys the object's elements and optionally frees the allocation, returning the object or its base pointer depending on flags.
// @fnv 0x007021b0
void* FUN_007021b0_cls::DestroyOrFree(unsigned int flags)
{
    if (flags & 2)
    {
        FUN_00ec5fce(this, 0x8, reinterpret_cast<int*>(this)[-1], &FUN_007021b0_cls::FUN_00702220);

        if (flags & 1)
        {
            FormHeap_Free(reinterpret_cast<char*>(this) - 4);
        }

        return reinterpret_cast<char*>(this) - 4;
    }

    FUN_00702220();

    if (flags & 1)
    {
        FormHeap_Free(this);
    }

    return this;
}

class TileNU
{
  public:
    void Set(int m_uiSoundID, float fValue, bool bPropagate);
};

class InterfaceManager;

class MenuCloseOperation
{
  public:
    TileNU* GetTile();
    void FUN_00a1d910();
};

FORenderedMenu* __fastcall FUN_00707af0(InterfaceManager* pkManager);
void __cdecl FUN_007ffe40();
unsigned int __cdecl gm_GetTickCount();

extern const float runtimeFloatSettingDefault987;
extern MenuCloseOperation* g_pkD766AA0Menu;
extern InterfaceManager* g_pkD766AA0InterfaceManager;
extern unsigned int g_uiD766AA0CloseTime;

// @fnv 0x00766aa0
void __cdecl UpdateD766AA0Menu()
{
    if (g_pkD766AA0Menu)
    {
        FUN_007ffe40();
        g_pkD766AA0Menu->GetTile()->Set(0xfc1, runtimeFloatSettingDefault987, true);
        if (FUN_00707af0(g_pkD766AA0InterfaceManager))
        {
            if (FUN_00707af0(g_pkD766AA0InterfaceManager)->GetSceneNode() ==
                ((Tile*)g_pkD766AA0Menu->GetTile())->FUN_0056c7f0())
            {
                FORenderedTerminal* pkTerminal =
                    dynamic_cast<FORenderedTerminal*>(FUN_00707af0(g_pkD766AA0InterfaceManager));
                pkTerminal->FUN_007ffaf0();
            }
        }
        ((Tile*)g_pkD766AA0Menu->GetTile())->SetInt(0x1772, 1);
        g_pkD766AA0Menu->FUN_00a1d910();
        g_uiD766AA0CloseTime = gm_GetTickCount() + 8000;
    }
}

extern int DAT_010729c8;
struct ValueRow
{
    float __thiscall FUN_00a011b0(unsigned int key, unsigned int mode);
    void __thiscall FUN_00a012d0(unsigned int key, float value);
    void __thiscall FUN_00715c60(unsigned int key, unsigned int value);
    void __thiscall FUN_00a01350(unsigned int key, unsigned int value, unsigned int mode);
};
struct MenuRowFactory
{
    ValueRow* FUN_00a1ddb0(void*, int*, unsigned int);
};
struct EntryListNode
{
    int __thiscall FUN_00559450();
    ValueRow** __thiscall FUN_0057cbe0(int* iterator);
    void __thiscall FUN_004ed8c0(ValueRow** item);
};
// Adds count to the 0xfac value of each existing row, then creates count new rows with descending 0xfac values and the given values at 0xfc4, appending each.
// @fnv 0x00767ef0
void __thiscall HackingMenu::AddValueRows(unsigned int count, const unsigned int* puiValues)
{
    ValueRow* item;
    {
        int iterator = ((EntryListNode*)((char*)this + 0x168))->FUN_00559450();
        while (iterator != 0)
        {
            item = *(((EntryListNode*)((char*)this + 0x168))->FUN_0057cbe0(&iterator));
            item->FUN_00a012d0(0xfac, item->FUN_00a011b0(0xfac, 1) + float(count));
        }
    }
    for (unsigned int index = 0; index < count; ++index)
    {
        item = reinterpret_cast<MenuRowFactory*>(this)->FUN_00a1ddb0(*(void**)((char*)this + 0x118), &DAT_010729c8, 0);
        item->FUN_00715c60(0xfac, count - index - 1);
        item->FUN_00a01350(0xfc4, puiValues[index], 1);
        ((EntryListNode*)((char*)this + 0x168))->FUN_004ed8c0(&item);
    }
}

struct Entry
{
    unsigned char* data;
    unsigned int count;
    int FUN_0076ae90();
    int FindByteIndices(unsigned int index, unsigned char* result);
};
struct FUN_007687d0
{
    Entry* entries;
    unsigned int count;
    ~FUN_007687d0();
    unsigned int FUN_00726070();
    Entry* FUN_00559450();
    FUN_007687d0 FUN_0076af90(unsigned char* result, int j);
};
unsigned int __cdecl FUN_00403940(unsigned int a, unsigned int b);
unsigned int __cdecl FUN_0042f5a0(unsigned int a, unsigned int b);
struct Context
{
    unsigned int FUN_00769520(FUN_007687d0* input);
};
// Scans input entries for the smallest value, recursing into sub-entries when it exceeds 2, and returns the combined result plus one.
// @fnv 0x00769520
unsigned int Context::FUN_00769520(FUN_007687d0* input)
{
    unsigned char minimum = 255;
    for (unsigned int i = 0; i < input->FUN_00726070(); ++i)
    {
        unsigned char current = input->FUN_00559450()[i].FUN_0076ae90();
        if (current < minimum)
            minimum = current;
    }
    if (minimum == 255)
    {
        return 0;
    }
    else if (minimum <= 2)
    {
        return minimum + 1;
    }
    else
    {
        unsigned int best = input->FUN_00726070();
        for (unsigned int outer = 0; outer < input->FUN_00726070(); ++outer)
        {
            if (input->FUN_00559450()[outer].FUN_0076ae90() == minimum)
            {
                unsigned int worst = 0;
                for (unsigned int inner = 0; inner < input->FUN_00726070(); ++inner)
                {
                    unsigned char results[32];
                    if (input->FUN_00559450()[outer].FindByteIndices(inner, results) == minimum)
                    {
                        FUN_007687d0 a = input->FUN_0076af90(results, minimum);
                        unsigned int j = FUN_00769520(&a);
                        worst = FUN_00403940(worst, j);
                    }
                }
                if (worst != 0)
                    best = FUN_0042f5a0(best, worst);
                if (best <= 2)
                    return best + 1;
            }
        }
        return best + 1;
    }
}

void __cdecl UnkCallA();
bool __cdecl UnkCallB();
extern const double g_dConst;

struct GameCc
{
    float __thiscall UnkGetA();
    float __thiscall UnkGetB(int v);
};

struct GameRoot
{
    unsigned char _pad0[0xcc];
    GameCc* m_cc;
    bool __thiscall UnkTestA();
    float __thiscall UnkGetC();
    int __thiscall UnkGetD();
};

extern GameRoot* g_pGame;


// Calls UnkCallA/UnkCallB, picks m_1cc or a game value as result, then returns -1 if result is outside [a,b] or (result-a)/17.
// @fnv 0x00769700
int HackingMenu::GetScaledValue()
{
    int result = 0;
    UnkCallA();
    if (UnkCallB())
    {
        result = m_iCursorIndex;
    }
    else
    {
        result = (int)(g_pGame->UnkTestA() ? g_pGame->UnkGetC() : (float)g_pGame->UnkGetD());
    }
    int a = (int)g_pGame->m_cc->UnkGetA();
    int b = (int)((double)a + g_pGame->m_cc->UnkGetB(0xfb1) - g_dConst);
    return (a > result || result > b) ? -1 : (result - a) / 17;
}

unsigned int __cdecl gm_GetTickCount();
extern double _gModifierZero;

struct TileV
{
    float __thiscall GetFloat(int id);
    float __thiscall GetWidth();
    void __thiscall SetFloat(int id, float value, bool propagate);
    void __thiscall SetInt(int id, int value);
};



// @fnv 0x0076a3f0
void HackingMenu::FUN_0076a3f0()
{
    if (gm_GetTickCount() > reinterpret_cast<unsigned int&>(unk1d0))
    {
        const unsigned int delay = 50;
        reinterpret_cast<TileV*>(pMenu)->SetFloat(0x1005,
                         reinterpret_cast<TileV*>(pMenu)->GetFloat(0x1005) +
                             static_cast<unsigned int>(unk1b8) * (reinterpret_cast<unsigned int&>(unk1d0) ? (gm_GetTickCount() - reinterpret_cast<unsigned int&>(unk1d0)) / delay + 1 : 1),
                         true);
        reinterpret_cast<unsigned int&>(unk1d0) = gm_GetTickCount() + delay;
        reinterpret_cast<BSSoundHandle&>(sounds[3]).Play(false);
    }
    if (reinterpret_cast<TileV*>(m_pTiles[5])->GetWidth() + reinterpret_cast<TileV*>(m_pTiles[5])->GetFloat(0xfb0) < _gModifierZero)
    {
        reinterpret_cast<TileV*>(pMenu)->SetInt(0x1006, 1);
        m_iStage = 4;
    }
}

extern int DAT_011a0104;
extern char* DAT_011a0100;
int __cdecl FUN_00ec7690(int, int);
int __cdecl FUN_00ec86e1(int);
void __cdecl FUN_00401460(int, const char*, int);


// @fnv 0x0076a670
void HackingMenu::FUN_0076a670(int a1, const char* pcSource)
{
    int idx = 1;
    int r6 = FUN_00ec7690(DAT_011a0104, pcSource[0]);
    if (r6 != 0)
    {
        while (1)
        {
            if (pcSource[idx] == 0 || FUN_00ec86e1(pcSource[idx]) != 0)
            {
                idx = 1;
                break;
            }
            else
            {
                if (pcSource[idx] == DAT_011a0100[r6 - DAT_011a0104])
                {
                    idx++;
                    break;
                }
            }
            idx++;
        }
    }
    FUN_00401460(a1, pcSource, idx);
}

extern "C" unsigned int __cdecl FUN_00457fe0();
extern "C" int __cdecl FUN_00a00940(const char*, int);
extern "C" char str_01072108;
struct Fade
{
    int state;
    int flags;
    float amount;
    void __thiscall FUN_00a0a270(float value, int enabled);
};
struct Resources
{
    float __thiscall FUN_00a011b0(int id);
    Fade* __thiscall FindTraitValue(int id);
};
struct MenuWidgetLookup
{
    struct Widget* FUN_00726070(int);
};
struct Widget
{
    bool __thiscall IsTraitNonZero();
};
// Toggles the fade at offset 0x1d4 between 0 and 1 on a timer, creating it from resource 0xfa3 when absent, unless menu state 4 with widget 0x1006 is active.
// @fnv 0x0076a9d0
void HackingMenu::UpdateFade()
{
    static float delay = (*reinterpret_cast<Resources**>(reinterpret_cast<char*>(this) + 0x11c))
                             ->FUN_00a011b0(FUN_00a00940(&str_01072108, -1));
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x1c4) == 4 && reinterpret_cast<MenuWidgetLookup*>(this)->FUN_00726070(0x1006)->IsTraitNonZero())
    {
        return;
    }
    else
    {
        static unsigned int nextUpdate = 0;
        if (FUN_00457fe0() > nextUpdate && *reinterpret_cast<Fade**>(reinterpret_cast<char*>(this) + 0x1d4) != 0)
        {
            (*reinterpret_cast<Fade**>(reinterpret_cast<char*>(this) + 0x1d4))
                ->FUN_00a0a270(
                    (*reinterpret_cast<Fade**>(reinterpret_cast<char*>(this) + 0x1d4))->amount == 1.0 ? 0.0f : 1.0f, 1);
            nextUpdate = static_cast<unsigned int>(FUN_00457fe0() + delay);
        }
        else if (*reinterpret_cast<Fade**>(reinterpret_cast<char*>(this) + 0x1d4) == 0)
        {
            *reinterpret_cast<Fade**>(reinterpret_cast<char*>(this) + 0x1d4) =
                (*reinterpret_cast<Resources**>(reinterpret_cast<char*>(this) + 0x11c))->FindTraitValue(0xfa3);
        }
    }
}

struct Node
{
    bool __thiscall IsTraitNonZero(int property);
    Node* __thiscall FUN_00a011f0(int property);
    Node* __thiscall FUN_0045cd60();
    void __thiscall FUN_00a011b0(int property);
    void __thiscall FUN_00700320(int property, int value);
};
extern int __cdecl FUN_0044a670(Node* node);
extern int __cdecl FUN_00ec62c0();
// @fnv 0x0076ab40
void HackingMenu::UpdateActiveNodeProperty()
{
    Node* selected;
    int total;
    {
        int multiplier = 0;
        total = 0;
        if (reinterpret_cast<Node*>(m_pTiles[5])->IsTraitNonZero(0xfa3))
        {
            selected = reinterpret_cast<Node*>(m_pTiles[5])->FUN_00a011f0(0xfc4);
            if (selected)
                multiplier = FUN_0044a670(selected);
        }
        for (Node* current = reinterpret_cast<Node*>(m_pTiles[5]); current && current != reinterpret_cast<Node*>(m_pTiles[4])->FUN_0045cd60(); current = current->FUN_0045cd60())
        {
            current->FUN_00a011b0(0xfa1);
            total += FUN_00ec62c0();
        }
        reinterpret_cast<Node*>(m_pTiles[4])->FUN_00700320(0xfa1, multiplier * 17 + total);
    }
}

// BuildHackingGuessTemplate - hacking menu guess template formatting
struct FUN_00a1ddb0_res
{
    void __thiscall FUN_00715c60(unsigned int id, int cnt);
    int __thiscall FUN_00700300();
    void __thiscall FUN_00707e10(int len);
};

struct FUN_00a1ddb0_owner
{
    FUN_00a1ddb0_res* __thiscall FUN_00a1ddb0(char* base, char const* name, void* f0);
};

extern HackingMenu* DAT_011d95b8;

struct FUN_0044ddc0_sub
{
    int __thiscall FUN_0044ddc0();
    void __thiscall FUN_004ed8c0(FUN_00a1ddb0_res** pp);
};




// @fnv 0x0076ad50
void HackingMenu::BuildHackingGuessTemplate()
{
    FUN_00a1ddb0_res* p = reinterpret_cast<FUN_00a1ddb0_owner*>(DAT_011d95b8)->FUN_00a1ddb0(reinterpret_cast<char*>(m_pTiles[1]), "hacking_guess_template", 0);
    p->FUN_00715c60(0xfac, (*reinterpret_cast<FUN_0044ddc0_sub*>(&list174)).FUN_0044ddc0());
    (*reinterpret_cast<FUN_0044ddc0_sub*>(&list174)).FUN_004ed8c0(&p);
    {
        BSStringT<char> nameBuf;
        nameBuf.PrintfString("%s_%d", p->FUN_00700300(), (*reinterpret_cast<FUN_0044ddc0_sub*>(&list174)).FUN_0044ddc0());
        p->FUN_00707e10((int)nameBuf.String());
    }
}

struct FUN_0076ae90_cls
{
    unsigned char* buf;
    unsigned int cnt;
    unsigned int __thiscall FUN_0076ae90();
};

void* __cdecl FUN_00403d30(void*, int, unsigned int);

struct FUN_0076ae90_tbl
{
    unsigned int cap;
    unsigned char table[0x20];
};

// Counts occurrences of each byte below 0x20 in buf and folds the counts into a running result via MaxByte.
// @fnv 0x0076ae90
unsigned int FUN_0076ae90_cls::FUN_0076ae90()
{
    unsigned int i;
    unsigned int j;
    FUN_0076ae90_tbl t_;
    unsigned char result2;

    t_.cap = 0x20;
    result2 = 0;
    FUN_00403d30(t_.table, 0, 0x20);
    for (i = 0; i < cnt; i++)
    {
        if ((unsigned int)buf[i] < 0x20)
        {
            t_.table[buf[i]]++;
        }
    }
    for (j = 0; j < 0x20; j++)
    {
        result2 = MaxByte(result2, t_.table[j]);
    }
    return result2;
}

struct ArrElem
{
    void* f0;
    unsigned int f4;
    ArrElem();
    ~ArrElem();
    ArrElem* AssignFrom(ArrElem* src);
};

struct ElemArray
{
    ArrElem* pItems;
    unsigned int uiSize;

    ElemArray* CopyFrom(ElemArray* src);
};

// @fnv 0x0076b0c0
ElemArray* ElemArray::CopyFrom(ElemArray* src)
{
    uiSize = src->uiSize;
    delete[] pItems;
    pItems = new ArrElem[src->uiSize];
    for (unsigned int i = 0; i < uiSize; i++)
        pItems[i].AssignFrom(&src->pItems[i]);
    return this;
}

struct AudioManager
{
    static AudioManager* Get();
    BSSoundHandle GetSoundByEditorID(const char*, int);
};
void* __cdecl FUN_00403d30(void*, int, unsigned int);
static const char scrollSound[] = "UIHackingCharScroll";
// @fnv 0x007654f0
HackingMenu::HackingMenu()
{
    unk1b4 = 0;
    unk1b8 = 30;
    FUN_00403d30(&unk10c, 0, 32);
    unk19c = 0;
    unk1a4 = 0;
    unk1a0 = 0;
    unk1ac = 0;
    unk1a8 = 0;
    m_iCursorIndex = 0;
    unk1b0 = 0;
    m_iStage = 0;
    unk1bc = -1;
    m_pkCursorTile = 0;
    unk1c0 = 0;
    unk1d9[1] = 0;
    unk1d9[0] = 0;
    m_bBlink = 0;
    unk1d0 = 0;
    unk1d4 = 0;
    AudioManager* audio = AudioManager::Get();
    reinterpret_cast<BSSoundHandle&>(sounds[0]) = audio->GetSoundByEditorID("UIHackingFanHumLP", 49);
    reinterpret_cast<BSSoundHandle&>(sounds[1]) = audio->GetSoundByEditorID("UIHackingPassGood", 33);
    reinterpret_cast<BSSoundHandle&>(sounds[2]) = audio->GetSoundByEditorID("UIHackingPassBad", 33);
    reinterpret_cast<BSSoundHandle&>(sounds[3]) = audio->GetSoundByEditorID(scrollSound, 33);
    reinterpret_cast<BSSoundHandle&>(sounds[4]) = audio->GetSoundByEditorID("UIHackingCharEnter", 33);
    FUN_00403d30(&unk028, 0, 184);
}

struct ScriptObj
{
    virtual int Call0(int);
};
struct EntObj
{
    void* FUN_00765b50(unsigned int);
};
struct SettingValue
{
    int v;
};
struct SettingColl
{
    SettingValue* FUN_0043d4d0();
};
struct SysColorMgr
{
    static SysColorMgr* __stdcall GetSingleton(int, char*);
    void ApplyToChild();
};
unsigned int __cdecl gm_GetTickCount();
void __cdecl FormHeap_Free(void*);
extern SettingColl DAT_011d0b90;
extern unsigned int DAT_011d95c0;
extern char DAT_011d9674;
// @fnv 0x007658e0
HackingMenu::~HackingMenu()
{
    ScriptObj* head7;
    ScriptObj* objTmp;
    ScriptObj* head4;
    ScriptObj* obj2;
    EntObj* ent2;
    EntObj* entCopy2;
    int i8;
    unsigned int jB;
    while (!list168.FUN_0076b610())
    {
        head7 = list168.RemoveHead();
        objTmp = head7;
        objTmp ? objTmp->Call0(1) : 0;
    }
    while (!list174.FUN_0076b610())
    {
        head4 = list174.RemoveHead();
        obj2 = head4;
        obj2 ? obj2->Call0(1) : 0;
    }
    list188.FUN_004ed900();
    DAT_011d95c0 = gm_GetTickCount() + DAT_011d0b90.FUN_0043d4d0()->v;
    pair180.FreeAll();
    void* ptrTmp = reinterpret_cast<void*>(unk1b0);
    FormHeap_Free(ptrTmp);
    DAT_011d95b8 = 0;
    for (i8 = 0; i8 < 5; i8++)
    {
        reinterpret_cast<BSSoundHandle&>(sounds[i8]).Stop();
        reinterpret_cast<BSSoundHandle&>(sounds[i8]).Clear();
    }
    for (jB = 0; jB < 46; jB++)
    {
        ent2 = reinterpret_cast<EntObj**>(entries)[jB];
        entCopy2 = ent2;
        entCopy2 ? entCopy2->FUN_00765b50(1) : 0;
    }
    SysColorMgr::GetSingleton(3, &DAT_011d9674)->ApplyToChild();
}

struct HackList
{
    char* data;
    HackList* next;
    HackList* Next();
    char** Get();
    void Remove(char**);
};
int __cdecl FUN_00408b20(const char*, const char*);
// Picks a random word matching selected, fills its menu tile with dots up to dotCount, shifts positions, frees the word and decrements count.
// @fnv 0x0076a730
void HackingMenu::RemoveRandomWord()
{
    unsigned int index;
    unsigned int iter;
    HackList* word;
    unsigned int position3;
    unsigned int aRow;
    HackTile* tile_2;
    char text[20];
    do
    {
        index = FUN_005a00a0(reinterpret_cast<unsigned int&>(unk1a8));
        iter = index;
        word = &(*reinterpret_cast<HackList*>(&pair180));
        while (iter--)
            word = word->Next();
    } while (!FUN_00408b20(*word->Get(), reinterpret_cast<const char*>(unk19c)));
    aRow = 4;
    for (position3 = reinterpret_cast<unsigned int*>(unk1b0)[index]; position3 > 12; position3 -= 12)
        ++aRow;
    tile_2 = entries[aRow]->tile;
    ++aRow;
    __memcpy(text, tile_2->GetString(0xfc4), 20);
    for (iter = 0; iter < static_cast<unsigned int>(unk1ac) && position3 < 12; ++iter)
    {
        text[position3 + 7] = '.';
        ++position3;
    }
    tile_2->Set(0xfc4, text, true);
    if (entries[aRow] && entries[aRow]->tile && entries[aRow]->tile->ContainsTrait(0xfaf) && iter < static_cast<unsigned int>(unk1ac))
    {
        position3 = 0;
        tile_2 = entries[aRow]->tile;
        __memcpy(text, tile_2->GetString(0xfc4), 20);
        while (iter++ < static_cast<unsigned int>(unk1ac))
        {
            text[position3 + 7] = '.';
            ++position3;
        }
        tile_2->Set(0xfc4, text, true);
    }
    for (; index < reinterpret_cast<unsigned int&>(unk1a8) - 1; ++index)
        reinterpret_cast<unsigned int*>(unk1b0)[index] = reinterpret_cast<unsigned int*>(unk1b0)[index + 1];
    reinterpret_cast<unsigned int*>(unk1b0)[index] = 0x198;
    char* deleted = *word->Get();
    FormHeap_Free(deleted);
    (*reinterpret_cast<HackList*>(&pair180)).Remove(word->Get());
    --reinterpret_cast<unsigned int&>(unk1a8);
}

namespace fnv_0076ac10 {
unsigned int __cdecl BSStringLength(const char*);

struct HTile
{
    const char* __thiscall GetString(int id);
    float __thiscall GetFloatValue(int id);
    HTile* __thiscall GetParentTile();
    void __thiscall Set(int id, int value);
};



// Computes x/y from the entry's tile string length and float values plus ancestor tiles, then sets them on tile11C.
} // namespace fnv_0076ac10

// @fnv 0x0076ac10
void HackingMenu::PositionTileFromEntry(HackEntry* entry)
{
    using namespace fnv_0076ac10;
    if (!entry || !reinterpret_cast<fnv_0076ac10::HTile*>(entry->tile))
        return;
    const char* text = reinterpret_cast<fnv_0076ac10::HTile*>(entry->tile)->GetString(0xfc4);
    int len4 = (text && *text != ' ') ? fnv_0076ac10::BSStringLength(text) : 0;
    int x8 = reinterpret_cast<fnv_0076ac10::HTile*>(entry->tile)->GetFloatValue(0xfa1) + len4 * 0x11;
    int y = reinterpret_cast<fnv_0076ac10::HTile*>(entry->tile)->GetFloatValue(0xfa2);
    HTile* parent;
    for (parent = reinterpret_cast<fnv_0076ac10::HTile*>(entry->tile)->GetParentTile(); parent && parent != reinterpret_cast<fnv_0076ac10::HTile*>(m_pTiles[4])->GetParentTile();
         parent = parent->GetParentTile())
    {
        x8 += (int)parent->GetFloatValue(0xfa1);
        y += (int)parent->GetFloatValue(0xfa2);
    }
    reinterpret_cast<fnv_0076ac10::HTile*>(m_pTiles[4])->Set(0xfa1, x8);
    reinterpret_cast<fnv_0076ac10::HTile*>(m_pTiles[4])->Set(0xfa2, y);
}


struct FUN_00759eb0
{
    FUN_00759eb0(const char*);
    ~FUN_00759eb0();
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
};
struct SettingRef
{
    unsigned int* __thiscall FUN_0043d4d0();
};
extern SettingRef DAT_011d3dc0;
extern SettingRef DAT_011d4e4c;
extern SettingRef DAT_011d3510;
float __cdecl FUN_004bd510(float, float);
struct TileValue
{
    float __thiscall FUN_00a011b0(int);
};
struct ConstructorTile : FUN_00a1ddb0_res
{
    int __thiscall FindTraitValue(int);
    int __thiscall FUN_00a00f30(int);
    void __thiscall FUN_00700320(unsigned int, int);
    void __thiscall FUN_00a01350(unsigned int, const char*, bool);
};
extern const char DAT_0107293c[];
extern const char DAT_010692d0[];
struct FUN_0076b300 : FUN_00759eb0
{
    ConstructorTile* tile;
    ConstructorTile* label;
    void __thiscall SetCapacity(unsigned int);
    void __thiscall FUN_006ffe80(int, int);
    FUN_0076b300(const char*, char*, const char*, int, unsigned char);
};
// @fnv 0x0076b300
FUN_0076b300::FUN_0076b300(const char* name, char* parent, const char* path, int value, unsigned char kind)
    : FUN_00759eb0(name)
{
    label = 0;
    tile = 0;
    if (!DAT_011d95b8)
        return;
    unsigned int counts[3];
    counts[0] = *DAT_011d3dc0.FUN_0043d4d0();
    counts[1] = *DAT_011d4e4c.FUN_0043d4d0();
    counts[2] = *DAT_011d3510.FUN_0043d4d0();
    {
        unsigned int randomValue = counts[kind] > 1 ? FUN_004bd510(1000.0 / counts[kind], 1.0f) : 1000.0f;
        SetCapacity(randomValue);
        tile = static_cast<ConstructorTile*>(reinterpret_cast<FUN_00a1ddb0_owner*>(DAT_011d95b8)->FUN_00a1ddb0(parent, path, 0));
        if (tile)
        {
            FUN_006ffe80(tile->FUN_00a00f30(0xfc4), tile->FindTraitValue(0xfa3));
            if (kind == 1)
            {
                label = static_cast<ConstructorTile*>(
                    reinterpret_cast<FUN_00a1ddb0_owner*>(DAT_011d95b8)->FUN_00a1ddb0(reinterpret_cast<char*>(DAT_011d95b8->m_pTiles[0]), DAT_0107293c, 0));
                label->FUN_00a01350(0xfc4, DAT_010692d0, true);
            }
            if (value >= 0)
            {
                tile->FUN_00700320(0xfa2, value);
                int width =
                    static_cast<int>(reinterpret_cast<TileValue*>(DAT_011d95b8->FUN_00726070())->FUN_00a011b0(0x1007));
                if (label)
                {
                    label->FUN_00700320(0xfa1, width);
                    label->FUN_00700320(0xfa2, value);
                    tile->FUN_00715c60(0xfa1, width + BSStringLength(DAT_010692d0) * 17);
                }
                else
                {
                    tile->FUN_00700320(0xfa1, width);
                }
            }
        }
    }
}

// Adapted from prior contributor's code (credited in packet.json)
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl FUN_00afdf20(const char*, unsigned int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_005b5e40(int, const char*, const char*);
extern "C" unsigned int __cdecl FUN_005a00a0(unsigned int);
unsigned int __cdecl BSStringCapacityMaximum(unsigned int, unsigned int);
void __cdecl FUN_0040fbe0(const char*, int);
unsigned int __cdecl BSStringLength(const char*);
extern char str_01072a34[];
extern char str_01072a00[];
extern char str_010729e8[];
unsigned int __cdecl gm_GetTickCount();
void __cdecl UpdateD766AA0Menu();

struct FUN_00680890 : FUN_00765810
{
    void* m_item;
    void* m_next;
    FUN_00680890();
};
struct WordsView : FUN_00765810
{
    void __thiscall FUN_00680890();
    void __thiscall FUN_0076b240(const char*);
    void __thiscall SortWeatherEntries();
    WordsView* __thiscall FUN_00726070();
    char** __thiscall FUN_006815c0();
};
struct FileObj
{
    virtual ~FileObj();
    virtual void __thiscall unknown04();
    virtual void __thiscall unknown08();
    virtual void __thiscall unknown0c();
    virtual void __thiscall unknown10();
    virtual void __thiscall unknown14();
    virtual void __thiscall unknown18();
    virtual void __thiscall unknown1c();
    virtual unsigned char __thiscall FUN_20(int, int);
    virtual void __thiscall unknown24();
    virtual void __thiscall unknown28();
    virtual void __thiscall unknown2c();
    virtual void __thiscall unknown30();
    virtual int __thiscall FUN_34(char*, int, int);
};
struct EntryRow
{
    unsigned char* __thiscall FUN_00559450();
};
struct MatrixWrapper : FUN_007687d0
{
    MatrixWrapper(unsigned int);
};

// @fnv 0x00768070
void __thiscall HackingMenu::SelectWordSet(unsigned int requestedCount)
{
    unsigned int attacker;
    int ahead;
    char* aimed;
    int ammo;
    unsigned int bracket;
    WordsView* currentNode;
    int row;
    char* chosen;
    BSStringT<char> dataFileName;
    FileObj* openedFile = 0;
    struct FUN_00680890 available;
    unsigned int startTicks = gm_GetTickCount();
    attacker = 0;
    ammo = 8;
    int threat = 10;
    unsigned int qty = (requestedCount - 2) / *(unsigned int*)((char*)this + 0x1ac) + 1;
    ahead = 0;
    if (*(unsigned int*)((char*)this + 0x1ac) == 0)
        return;
    dataFileName = str_01072a34;
    openedFile = (FileObj*)FUN_00afdf20(dataFileName.String(), 0, 0x4000, 0x100);
    if (!openedFile || !openedFile->FUN_20(0, 0))
    {
        FUN_005b5e40(0x12, str_01072a00, dataFileName.String());
        UpdateD766AA0Menu();
        return;
    }
    char line[32];
    while (true)
    {
        memset(line, 0, 32);
        if (openedFile->FUN_34(line, 32, 32) == 0)
        {
            break;
        }
        else
        {
            if (!line[0])
                continue;
        }
        if (BSStringLength(line) == *(unsigned int*)((char*)this + 0x1ac))
            ((FUN_0076b240_shell*)&available)->FUN_0076b240(line);
    }
    delete openedFile;
    ((FUN_007687b0_shell*)&available)->SortWeatherEntries();
    ((FUN_007687b0_shell*)&available)->SortWeatherEntries();
    ((FUN_007687b0_shell*)&available)->SortWeatherEntries();
    while (1)
    {
        unsigned int limit = gm_GetTickCount() + 100;
        while (gm_GetTickCount() < limit && ++attacker)
        {
            ((WordsView*)((char*)this + 0x180))->FreeAll();
            *(unsigned int*)((char*)this + 0x1a8) = 0;
            ((FUN_007687b0_shell*)&available)->SortWeatherEntries();
            for (currentNode = (WordsView*)&available; *(unsigned int*)((char*)this + 0x1a8) < requestedCount &&
                                                       currentNode && (chosen = *currentNode->FUN_006815c0());
                 currentNode = currentNode->FUN_00726070())
            {
                bool accepted = true;
                unsigned char similarities[8];
                memset(similarities, 0, sizeof(similarities));
                for (WordsView* selected = ((WordsView*)((char*)this + 0x180));
                     accepted && selected && (aimed = *selected->FUN_006815c0()); selected = selected->FUN_00726070())
                {
                    unsigned int similarity = CountMatchingChars(chosen, aimed);
                    if (similarity == *(unsigned int*)((char*)this + 0x1ac))
                    {
                        accepted = false;
                    }
                    else if (*(unsigned int*)((char*)this + 0x1a8) < requestedCount - 1)
                    {
                        accepted = (similarity > 0 || FUN_005a00a0(10) < (unsigned int)ahead);
                    }
                    else
                    {
                        accepted = (similarity >= 8 || ++similarities[similarity] <= qty);
                    }
                }
                if (accepted)
                {
                    ((FUN_0076b240_shell*)((WordsView*)((char*)this + 0x180)))->FUN_0076b240(chosen);
                    ++*(unsigned int*)((char*)this + 0x1a8);
                }
            }
            if (*(unsigned int*)((char*)this + 0x1a8) == requestedCount)
                break;
        }
        if (*(unsigned int*)((char*)this + 0x1a8) == requestedCount)
        {
            break;
        }
        else
        {
            if (++ahead == 10)
            {
                ahead = 0;
                if (++qty > (requestedCount >> 1))
                    break;
            }
        }
    }
    ((FUN_007687b0_shell*)((WordsView*)((char*)this + 0x180)))->SortWeatherEntries();
    ((FUN_007687b0_shell*)((WordsView*)((char*)this + 0x180)))->SortWeatherEntries();
    ((FUN_007687b0_shell*)((WordsView*)((char*)this + 0x180)))->SortWeatherEntries();
    ((FUN_007687b0_shell*)((WordsView*)((char*)this + 0x180)))->SortWeatherEntries();
    bracket = FUN_005a00a0(*(unsigned int*)((char*)this + 0x1a8));
    currentNode = ((WordsView*)((char*)this + 0x180));
    for (int index = 0; (unsigned int)index < bracket; ++index)
        currentNode = currentNode->FUN_00726070();
    *(char**)((char*)this + 0x19c) = *currentNode->FUN_006815c0();
    FUN_0040fbe0(str_010729e8, (int)*(char**)((char*)this + 0x19c));
    MatrixWrapper bonus(*(unsigned int*)((char*)this + 0x1a8));
    row = 0;
    for (currentNode = ((WordsView*)((char*)this + 0x180)); currentNode && *currentNode->FUN_006815c0();
         currentNode = currentNode->FUN_00726070())
    {
        int columnIndex = 0;
        for (WordsView* col = ((WordsView*)((char*)this + 0x180)); col && *col->FUN_006815c0();
             col = col->FUN_00726070())
        {
            ((EntryRow*)&bonus.FUN_00559450()[row])->FUN_00559450()[columnIndex] =
                (currentNode == col) ? 0xFF
                                     : this->CountMatchingChars(*currentNode->FUN_006815c0(), *col->FUN_006815c0());
            ++columnIndex;
        }
        ++row;
    }
    *(void**)((char*)this + 0x1a0) = (void*)reinterpret_cast<Context*>(this)->FUN_00769520(&bonus);
    *(void**)((char*)this + 0x1a0) = (void*)BSStringCapacityMaximum(4, *(unsigned int*)((char*)this + 0x1a0));
    *(void**)((char*)this + 0x1a4) = *(void**)((char*)this + 0x1a0);
}

struct Setting83
{
    const char* FUN_00403df0();
    const char* FUN_004c69f0();
};
extern Setting83 DAT_011d2e20, DAT_011d33cc, DAT_011d430c;
struct Tile83
{
    float FUN_00a011b0(int, int);
    void FUN_00a012d0(int, float);
    int FUN_00a00f30(int);
    void FUN_00715c60(int, int);
    float GetTotalFloat();
    void FUN_00700320(int, int);
};
struct Entry83
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    Tile83* tile;
    int unk30;
    Entry83(const char*, Tile83*, const char*, int, int);
    Entry83();
    ~Entry83();
    void* FUN_00765b50(int);
    void FUN_006ffe80(int, int);
};
struct Node83
{
    char* item;
    Node83* next;
    char** FUN_006815c0();
    Node83* FUN_00726070();
    void FUN_0063f7b0();
    void FUN_006ecd40(int);
};
void* FUN_00403d30(void*, int, unsigned int);
unsigned int FUN_0044a670(const char*);
void* FUN_00401460(void*, const void*, unsigned int);
void __cdecl FUN_005b5e40(const char*, ...);
void* FUN_004b7210();
bool FUN_004b71d0();
void operator delete(void*);
void* operator new[](unsigned int);
void operator delete[](void*);
// Clears the entry list, rebuilds the intro entries, generates a random password buffer from the word list, and creates one entry per 12-character chunk.
// @fnv 0x00768aa0
void HackingMenu::BuildHackingPasswordFile()
{
    for (unsigned int i = 0; i < 46 && reinterpret_cast<Entry83**>(entries)[i]; i++)
        delete reinterpret_cast<Entry83**>(entries)[i];
    FUN_00403d30(reinterpret_cast<Entry83**>(entries), 0, 184);
    BSStringT<char> text24x17;
    text24x17.PrintfString("%d %s", unk1a0, DAT_011d2e20.FUN_00403df0());
    reinterpret_cast<Entry83**>(entries)[0] = new Entry83(DAT_011d33cc.FUN_004c69f0(), reinterpret_cast<Tile83*>(m_pTiles[1]), "hacking_intro_template", unk1b4, 0);
    reinterpret_cast<Entry83**>(entries)[1] = new Entry83(DAT_011d430c.FUN_004c69f0(), reinterpret_cast<Tile83*>(m_pTiles[1]), "hacking_intro_template", unk1b4 + unk1b8, 0);
    reinterpret_cast<Entry83**>(entries)[2] = new Entry83(text24x17.String(), reinterpret_cast<Tile83*>(m_pTiles[1]), "hacking_intro_template", unk1b4 + unk1b8 * 3, 0);
    reinterpret_cast<Tile83*>(m_pTiles[1])->FUN_00a012d0(4101, reinterpret_cast<Entry83**>(entries)[2]->tile->FUN_00a011b0(4001, 1) + text24x17.Length() * 17);
    reinterpret_cast<Tile83*>(m_pTiles[1])->FUN_00a012d0(4102, reinterpret_cast<Entry83**>(entries)[2]->tile->FUN_00a011b0(4002, 1));
    reinterpret_cast<Entry83**>(entries)[3] = new Entry83;
    reinterpret_cast<Entry83**>(entries)[3]->FUN_006ffe80(0, reinterpret_cast<Tile83*>(m_pTiles[1])->FUN_00a00f30(4100));
    int entryIndex7x39 = 4;
    for (unsigned int i = 0; i < (unsigned int)unk1a4; i++)
        BuildHackingGuessTemplate();
    unsigned int alphabetSize17x2 = FUN_0044a670("!@#$%^*()_+=-`[]{}|;':,./<>?\\\"");
    int spacing35x61 = 2;
    int bufferSize12x1 = 409;
    char bufferx3[409];
    if (!unk1a8)
        return;
    delete[] reinterpret_cast<int*&>(unk1b0);
    reinterpret_cast<int*&>(unk1b0) = new int[unk1a8];
    unsigned int attempts8x10 = 0;
    while (true)
    {
        for (unsigned int fill18 = 0; fill18 < 408; fill18++)
            bufferx3[fill18] = "!@#$%^*()_+=-`[]{}|;':,./<>?\\\""[FUN_005a00a0(alphabetSize17x2)];
        bufferx3[408] = 0;
        Node83* node15 = &(*reinterpret_cast<Node83*>(&pair180));
        int wordIndex4 = 0;
        unsigned int failures12 = 0;
        while (node15 && *node15->FUN_006815c0() && failures12 < 100)
        {
            int position4 = FUN_005a00a0(409 - unk1ac - 2);
            bool free16 = true;
            for (int j = -2; free16 && j < unk1ac + 2; j++)
                free16 = !(position4 + j >= 0 && bufferx3[position4 + j] >= 'A' && bufferx3[position4 + j] <= 'Z');
            if (free16)
            {
                FUN_00401460(bufferx3 + position4, *node15->FUN_006815c0(), unk1ac);
                reinterpret_cast<int*&>(unk1b0)[wordIndex4] = position4;
                wordIndex4++;
                node15 = node15->FUN_00726070();
                failures12 = 0;
            }
            else
                failures12++;
        }
        if (failures12)
        {
            attempts8x10++;
            if (attempts8x10 <= 4)
                continue;
            else
            {
                FUN_005b5e40(
                    "MENUS: Unable to construct complete password file for hacking minigame.  Continuing with fewer words.");
                while (*node15->FUN_006815c0())
                {
                    if (reinterpret_cast<char*&>(unk19c) == *node15->FUN_006815c0())
                        reinterpret_cast<char*&>(unk19c) = *node15->FUN_006815c0();
                    delete[] *node15->FUN_006815c0();
                    node15->FUN_0063f7b0();
                    unk1a8--;
                    reinterpret_cast<int*&>(unk1b0)[wordIndex4] = 408;
                    wordIndex4++;
                }
                for (Node83* walk = &(*reinterpret_cast<Node83*>(&pair180)); walk; walk = walk->FUN_00726070())
                    if (walk->FUN_00726070() == node15)
                        walk->FUN_006ecd40(0);
            }
        }
        else
            break;
    }
    int row104x2 = 0;
    int column9x68 = 0;
    char* current28x7 = bufferx3;
    char* end47x7 = bufferx3 + 408;
    while (current28x7 < end47x7)
    {
        char backup = 0;
        if (end47x7 - current28x7 > 12)
        {
            backup = current28x7[12];
            current28x7[12] = 0;
        }
        char address[8];
        FormatHexWord((unsigned short)current28x7, address);
        text24x17.PrintfString("%s %s", address, current28x7);
        reinterpret_cast<Entry83**>(entries)[entryIndex7x39] =
            new Entry83(text24x17.String(), reinterpret_cast<Tile83*>(m_pTiles[2]), "hacking_password_file_template", -1, 2);
        reinterpret_cast<Entry83**>(entries)[entryIndex7x39]->tile->FUN_00715c60(4012, row104x2);
        reinterpret_cast<Entry83**>(entries)[entryIndex7x39]->tile->FUN_00715c60(4100, column9x68);
        FUN_004b7210();
        if (FUN_004b71d0() && !row104x2 && !column9x68)
        {
            reinterpret_cast<Tile83*&>(m_pkCursorTile) = reinterpret_cast<Entry83**>(entries)[entryIndex7x39]->tile;
            m_iCursorIndex = (int)(reinterpret_cast<Tile83*&>(m_pkCursorTile)->GetTotalFloat() + 119.0);
        }
        row104x2++;
        if (row104x2 == 17)
        {
            row104x2 = 0;
            column9x68++;
        }
        entryIndex7x39++;
        if (end47x7 - current28x7 > 12)
            current28x7[12] = backup;
        current28x7 += 12;
    }
    reinterpret_cast<Tile83*>(m_pTiles[0])->FUN_00700320(4003, 0);
    m_iStage = 1;
}

namespace s767610 {



InterfaceManager* FUN_004b7210();
bool FUN_00702450(int iMenuID);
int FUN_00ec86e1(int iChar);

struct HackingState
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
    Tile* m_pkSelected;
};

extern HackingState* DAT_011d95bc;


// Handles key input for the hacking menu, moving the cursor tile or triggering a click based on the current stage and key code.
} // namespace s767610

// @fnv 0x00767610
bool HackingMenu::HandleKey(int iKey, int iUnused)
{
    using namespace s767610;
    if (!s767610::FUN_004b7210()->FUN_004b71d0())
        return false;
    if (s767610::FUN_00702450(0x41f))
    {
        s767610::DAT_011d95bc->m_pkSelected = m_pkCursorTile;
        if (m_iStage < 2 && iKey == 9)
        {
            HandleSelection(-1, 0);
            return true;
        }
        else if (m_iStage == 2)
        {
            switch (iKey)
            {
            case 4: {
                int iSavedIndex = m_iCursorIndex;
                bool bWord = (m_pkCursorTile && m_pkCursorTile->FUN_00a011f0(0xfc4))
                                 ? (s767610::FUN_00ec86e1(m_pkCursorTile->FUN_00a011f0(0xfc4)[GetScaledValue()]) ? 1 : 0)
                                 : 0;
                m_iCursorIndex -= 0x11;
                while (bWord && GetScaledValue() >= 7 &&
                       s767610::FUN_00ec86e1(m_pkCursorTile->FUN_00a011f0(0xfc4)[GetScaledValue()]))
                    m_iCursorIndex -= 0x11;
                if (GetScaledValue() < 7)
                {
                    if (m_pkCursorTile->FUN_00a011b0(0x1004) > 0.0)
                    {
                        int iColIndex = (int)m_pkCursorTile->FUN_00a011b0(0xfac);
                        int iNewRow = (int)m_pkCursorTile->FUN_00a011b0(0x1004) - 1;
                        Tile* pkFound = FUN_00767bb0(iColIndex, iNewRow);
                        if (pkFound)
                        {
                            m_bBlink = false;
                            m_pkCursorTile = pkFound;
                            m_iCursorIndex =
                                (int)(m_pkCursorTile->GetTotalFloat() + m_pkCursorTile->FUN_00a011b0(0xfb1) - 17.0);
                        }
                        else
                        {
                            m_iCursorIndex = iSavedIndex;
                        }
                    }
                    else
                    {
                        m_iCursorIndex = iSavedIndex;
                    }
                }
                else
                {
                    m_bBlink = false;
                }
                return true;
            }
            case 3: {
                int iSavedIndex = m_iCursorIndex;
                bool bWord = (m_pkCursorTile && m_pkCursorTile->FUN_00a011f0(0xfc4))
                                 ? (s767610::FUN_00ec86e1(m_pkCursorTile->FUN_00a011f0(0xfc4)[GetScaledValue()]) ? 1 : 0)
                                 : 0;
                m_iCursorIndex += 0x11;
                while (bWord && GetScaledValue() != -1 &&
                       s767610::FUN_00ec86e1(m_pkCursorTile->FUN_00a011f0(0xfc4)[GetScaledValue()]))
                    m_iCursorIndex += 0x11;
                if (GetScaledValue() == -1)
                {
                    if (m_pkCursorTile->FUN_00a011b0(0x1004) < 1.0)
                    {
                        int iColIndex = (int)m_pkCursorTile->FUN_00a011b0(0xfac);
                        int iNewRow = (int)m_pkCursorTile->FUN_00a011b0(0x1004) + 1;
                        Tile* pkFound = FUN_00767bb0(iColIndex, iNewRow);
                        if (pkFound)
                        {
                            m_bBlink = false;
                            m_pkCursorTile = pkFound;
                            m_iCursorIndex = (int)(m_pkCursorTile->GetTotalFloat() + 119.0);
                        }
                        else
                        {
                            m_iCursorIndex = iSavedIndex;
                        }
                    }
                    else
                    {
                        m_iCursorIndex = iSavedIndex;
                    }
                }
                else
                {
                    m_bBlink = false;
                }
                return true;
            }
            case 1: {
                int iColumn = (int)m_pkCursorTile->FUN_00a011b0(0xfac);
                if (iColumn > 0)
                {
                    m_bBlink = false;
                    m_pkCursorTile = FUN_00767bb0(iColumn - 1, (unsigned int)m_pkCursorTile->FUN_00a011b0(0x1004));
                    return true;
                }
                break;
            }
            case 2: {
                int iColumn = (int)m_pkCursorTile->FUN_00a011b0(0xfac);
                if (iColumn < 0x10)
                {
                    m_bBlink = false;
                    m_pkCursorTile = FUN_00767bb0(iColumn + 1, (unsigned int)m_pkCursorTile->FUN_00a011b0(0x1004));
                    return true;
                }
                break;
            }
            }
        }
    }
    return false;
}



bool __cdecl FUN_00702450(int);
struct Sub4D4
{
    bool __thiscall FUN_00718840(int);
};
struct Mgr4B7210
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
    int unk48;
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
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    Sub4D4 m4D4;
};
struct Global11d95bc
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
    int unk48;
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
    Tile* mCC;
};
extern Global11d95bc* DAT_011d95bc;
struct Entry28
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
    void* tile2C;
    bool __thiscall FUN_00759d80();
    void __thiscall FUN_006ffea0();
};


// Updates tile state based on unk1C4, handling fade, entry positioning, and active node property updates.
// @fnv 0x00767c90
void HackingMenu::UpdateDialog()
{
    unsigned int bbb;
    int j;
    if (m_eFadeState != 1 || !FUN_00702450(FUN_00766a40()) ||
        (unk1d9[1] && !((Mgr4B7210*)FUN_004b7210())->m4D4.FUN_00718840(0x13)))
    {
        return;
    }
    if ((FUN_004b7210(), FUN_004b71d0()))
    {
        DAT_011d95bc->mCC = m_pkCursorTile;
    }
    anim.FUN_006ffea0();
    UpdateFade();
    switch (m_iStage)
    {
    case 0:
        FUN_00769830();
        break;
    case 1:
        for (bbb = 0; bbb < 46; ++bbb)
        {
            if (reinterpret_cast<Entry28**>(entries)[bbb] && !reinterpret_cast<Entry28**>(entries)[bbb]->FUN_00759d80())
            {
                reinterpret_cast<BSSoundHandle&>(sounds[3]).Play(false);
                reinterpret_cast<Entry28**>(entries)[bbb]->FUN_006ffea0();
                PositionTileFromEntry(reinterpret_cast<Entry28**>(entries)[bbb]);
                break;
            }
        }
        if (bbb == 46)
        {
            Tile* i;
            j = 0;
            for (i = m_pTiles[5]; i && i != m_pTiles[4]->FUN_0045cd60(); i = i->FUN_0045cd60())
            {
                j += (int)i->FUN_00a011b0(0xfa2);
            }
            m_pTiles[4]->FUN_00700320(0xfa2, j);
            m_iStage = 2;
        }
        break;
    case 2:
        UpdateActiveNodeProperty();
        if (unk1a0 == 1)
        {
            reinterpret_cast<Entry28**>(entries)[1]->FUN_006ffea0();
        }
        if (DAT_011d95bc->mCC && DAT_011d95bc->mCC->FUN_0045cd60() == m_pTiles[2])
        {
            UpdateHighlight();
        }
        break;
    case 3:
        UpdateActiveNodeProperty();
        FUN_0076a3f0();
        break;
    case 4:
        UpdateActiveNodeProperty();
        if (unk1a0 && m_eFadeState != 2)
        {
            FUN_0076a510();
        }
        break;
    }
}

namespace H769769 {

struct H769TileV
{
    void FUN_00700320(int id, int value);
    bool IsTraitNonZero(int id);
    const char* FUN_00a011f0(int id);
};
struct H769Line
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
    H769TileV* pText;
    H769TileV* kArgumentPosition;
    bool FUN_00759d80();
    void FUN_006ffea0();
};
struct H769Audio
{
    BSSoundHandle ResolveAudioHandle(const char* name, int flags);
};
H769Audio* FUN_00ad9060();
}
using namespace H769769;
extern unsigned int DAT_011d969c;
extern int DAT_011d9694;

// @fnv 0x00769830
void HackingMenu::FUN_00769830()
{
    int i;

    for (i = 0; i < 14; i++)
    {
        if (FUN_00457fe0() > DAT_011d95c0)
        {
            reinterpret_cast<H769Line**>(entries)[0]->pText->FUN_00700320(0xfa3, 0);
        }
        else
        {
            reinterpret_cast<H769Line**>(entries)[0]->pText->FUN_00700320(0xfa3, 1);
        }
        if (reinterpret_cast<H769Line**>(entries)[i] && !reinterpret_cast<H769Line**>(entries)[i]->FUN_00759d80())
        {
            if (reinterpret_cast<H769Line**>(entries)[i]->kArgumentPosition)
            {
                if (!reinterpret_cast<H769Line**>(entries)[i]->kArgumentPosition->IsTraitNonZero(0xfa3))
                {
                    reinterpret_cast<H769Line**>(entries)[i]->kArgumentPosition->FUN_00700320(0xfa3, 1);
                    DAT_011d969c = FUN_00457fe0() + 1000;
                }
                if (FUN_00457fe0() > DAT_011d969c)
                {
                    unsigned int uiStart4 = FUN_0044a670(reinterpret_cast<H769Line**>(entries)[i]->pText->FUN_00a011f0(0xfc4));
                    reinterpret_cast<H769Line**>(entries)[i]->FUN_006ffea0();
                    unsigned int uiEnd = FUN_0044a670(reinterpret_cast<H769Line**>(entries)[i]->pText->FUN_00a011f0(0xfc4));
                    for (unsigned int j6 = 0; j6 < uiEnd - uiStart4; j6++)
                    {
                        static int s_iTypeTime =
                            (int)(*DAT_011d4e4c.FUN_0043d4d0() > 1
                                      ? FUN_004bd510((float)(1000.0 / *DAT_011d4e4c.FUN_0043d4d0()), 1.0f)
                                      : 1000.0f);
                        unsigned int uiDelay = j6 * s_iTypeTime / (uiEnd - uiStart4);
                        FUN_00ad9060()->ResolveAudioHandle("UIHackingCharSingle", 0x121).PlayAfter(uiDelay, 0);
                    }
                    if (reinterpret_cast<H769Line**>(entries)[i]->FUN_00759d80())
                    {
                        reinterpret_cast<BSSoundHandle&>(sounds[4]).Play(0);
                        DAT_011d969c = FUN_00457fe0() + 500;
                    }
                }
            }
            else if (FUN_00457fe0() > DAT_011d969c)
            {
                reinterpret_cast<H769Line**>(entries)[i]->FUN_006ffea0();
                reinterpret_cast<BSSoundHandle&>(sounds[3]).Play(0);
            }
            PositionTileFromEntry(reinterpret_cast<HackEntry*>(entries[i]));
            break;
        }
    }
    if (i == 14 && FUN_00457fe0() > DAT_011d969c)
    {
        BuildHackingPasswordFile();
    }
}

// FUN_0076a540 - HackingMenu: open a hacking terminal menu tile.
extern char DAT_01072b00;
void __cdecl FNV_Warning(const char* format);

struct MenuPX
{
    void FUN_00867a20();
};
struct TilePX
{
    MenuPX* FUN_00a03c90();
    NiNode* FUN_0056c7f0();
};
struct TileStatics
{
    static void UpdateAll(bool propagate);
};

TilePX* __cdecl CreateComputerMenu(const char* path);
FORenderedMenu* __cdecl FUN_00707ad0();

// Creates a computer menu tile, updates tile statics, and attaches it to a rendered terminal, creating a new FORenderedTerminal if none exists.
// @fnv 0x0076a540
void HackingMenu::FUN_0076a540()
{
    (*(Tile**)((char*)this + 4))->Set(0x1772, 1);
    ((MenuCloseOperation*)this)->FUN_00a1d910();
    if (*(int*)((char*)this + 0x194))
    {
        TilePX* pTile = CreateComputerMenu(*(const char**)((char*)this + 0x198));
        pTile->FUN_00a03c90()->FUN_00867a20();
        TileStatics::UpdateAll(false);
        FORenderedTerminal* r = dynamic_cast<FORenderedTerminal*>(FUN_00707ad0());
        if (!r)
        {
            FNV_Warning(&DAT_01072b00);
            r = new FORenderedTerminal;
        }
        r->FUN_00984f60(pTile);
        r->FUN_00705fc0(pTile->FUN_0056c7f0());
    }
}

namespace grid76a {
struct G7Row
{
    unsigned char* pData;
    int iCount;
    unsigned char* FUN_00559450();
};
struct G7Grid
{
    G7Row* m_pRows;
    int iCount;
    G7Grid(unsigned char size);
    G7Grid(const G7Grid& other);
    ~G7Grid();
    G7Row* FUN_00559450();
    G7Grid FUN_0076af90(const unsigned char* order, unsigned char size);
};
}
using namespace grid76a;

// Creates a new G7Grid by reordering rows and columns of this grid according to the given permutation order.
// @fnv 0x0076af90
G7Grid G7Grid::FUN_0076af90(const unsigned char* order, unsigned char size)
{
    G7Grid kResult(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            kResult.FUN_00559450()[i].FUN_00559450()[j] = m_pRows[order[i]].FUN_00559450()[order[j]];
        }
    }
    return kResult;
}

namespace fnv_00765b80 {
struct Tile84;
struct Ref84;
struct Base84
{
    bool IsFlagBitSet();
    int FUN_00501270(Ref84*);
    float FUN_005017a0(Ref84*);
};
struct Ref84
{
    Base84* FUN_007af430();
};
struct Color84
{
    float r, g, b, a;
    Color84(float, float, float, float);
};
struct Palette84
{
    void FUN_00719060(int, Color84*);
    void ApplyToChild(int, const Color84&);
};
Palette84* FUN_00718b60();
extern Color84 DAT_011d9674;
struct Setting84
{
    unsigned int* FUN_0043d4d0();
    const char* FUN_00403df0();
    const char* FUN_004c69f0();
};
struct Values84
{
    float FUN_0066ef50(int);
};
struct Player84
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
    Values84 values;
    int GetTerminalAccessResult(Ref84*);
};
extern Player84* DAT_011dea3c;
struct Keys84
{
    bool FUN_00718630(int, int, int);
};
struct Interface84
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
    Keys84 keys;
    Tile84* FUN_00586150(const char*);
};
extern Interface84* DAT_011d95bc;
struct Tile84
{
    Tile84* FUN_00a01b00();
    HackingMenu* FUN_00a03c90();
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, int);
    void FUN_00a01350(int, const char*, int);
    void FUN_00700320(int, int);
    int FindTraitValue(int);
    int FUN_00a00f30(int);
};
struct Entry84
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    Tile84* tile;
    int unk30;
    Entry84(const char*, Tile84*, const char*, int, int);
};
struct Text84
{
    int unk00, unk04, unk08, unk0c;
    void FUN_006ffe80(int, int);
    void SetCapacity(unsigned int);
};
extern HackingMenu* DAT_011d95b8;
HackingMenu* FUN_00a09030(int);
Interface84* FUN_004b7210();
float FUN_00a01530();
extern unsigned int DAT_0119f27c, DAT_0119f280;
void __cdecl FUN_005b5e40(const char*, ...);
unsigned int FUN_0042f5a0(unsigned int, unsigned int);
void FUN_005e58f0(int, Player84*, float*);
float FUN_00404010(float, float);
float FUN_0040ebd0(float, float);
float FUN_004bd510(float, float);
void* operator new(unsigned int);
void operator delete(void*);
extern Setting84 DAT_011d42d0;
extern Setting84 DAT_011d2934;
extern Setting84 DAT_011d31bc;
extern Setting84 DAT_011d30e4;
extern Setting84 DAT_011d3318;
extern Setting84 DAT_011d3c4c;
extern Setting84 DAT_011d4e4c;
extern Setting84 DAT_011d3f58;
extern Setting84 DAT_011d3a38;
extern Setting84 DAT_011d3c64;
extern Setting84 DAT_011d4c00;
extern Setting84 DAT_011d4d5c;
extern Setting84 DAT_011d3030;
extern Setting84 DAT_011d4b94;
extern Setting84 DAT_011d1f44;
extern Setting84 DAT_011d1d9c;
extern Setting84 DAT_011d306c;
extern Setting84 DAT_011d484c;
extern Setting84 DAT_011d4f18;
extern Setting84 DAT_011d4690;
extern Setting84 DAT_011d2130;
// Creates and configures the hacking menu from hacking_menu.xml, populating entries based on terminal difficulty and skill.
// @fnv 0x00765b80
Tile84* FUN_00765b80(Ref84* reference)
{
    HackingMenu* old40 = FUN_00a09030(FUN_00766a40());
    if (old40)
        delete old40;
    DAT_011d95bc = FUN_004b7210();
    float screen13 = FUN_00a01530();
    FUN_00718b60()->FUN_00719060(3, &DAT_011d9674);
    Base84* terminal14 = reference->FUN_007af430();
    if (terminal14->IsFlagBitSet())
        FUN_00718b60()->ApplyToChild(3, Color84(1.0f, 1.0f, 1.0f, 0.0f));
    DAT_0119f27c = *DAT_011d42d0.FUN_0043d4d0();
    DAT_0119f280 = *DAT_011d2934.FUN_0043d4d0();
    Tile84* tile4 = DAT_011d95bc->FUN_00586150("Data\\Menus\\hacking_menu.xml")->FUN_00a01b00();
    HackingMenu* menu24 = tile4->FUN_00a03c90();
    if (menu24 && menu24->GetClass() == FUN_00766a40())
    {
        menu24->FUN_00a1dc70(reinterpret_cast<TileMenu*>(tile4), 0);
        DAT_011d95b8 = menu24;
        int missing1;
        if (!DAT_011d95b8->HasAllSlots(&missing1))
        {
            FUN_005b5e40("MENUS: Hacking Menu Creation Failed... Missing index = #%d", missing1);
            return 0;
        }
        if (tile4->FUN_00a011b0(4007) == 6006.0 || tile4->FUN_00a011b0(4007) == 102.0)
            tile4->FUN_00a012d0(4013, screen13, 1);
        reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[6])->FUN_00a01350(4036, DAT_011d31bc.FUN_00403df0(), 1);
        reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[7])->FUN_00a01350(4036, DAT_011d30e4.FUN_00403df0(), 1);
        Base84* base14 = reference ? reference->FUN_007af430() : 0;
        if (base14 && DAT_011dea3c->GetTerminalAccessResult(reference) == 2)
        {
            tile4->FUN_00700320(4102, 1);
            DAT_011d95b8->m_iStage = 4;
            reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[4])->FUN_00700320(4003, 0);
        }
        else
        {
            reinterpret_cast<Base84*&>(DAT_011d95b8->unk194) = base14;
            reinterpret_cast<Ref84*&>(DAT_011d95b8->unk198) = reference;
            DAT_011d95b8->unk1ac =
                reinterpret_cast<Base84*&>(DAT_011d95b8->unk194) ? reinterpret_cast<Base84*&>(DAT_011d95b8->unk194)->FUN_00501270(reinterpret_cast<Ref84*&>(DAT_011d95b8->unk198)) : 12;
            DAT_011d95b8->unk1ac = FUN_0042f5a0(12, DAT_011d95b8->unk1ac);
            DAT_011d95b8->unk1d9[1] = DAT_011d95bc->keys.FUN_00718630(19, FUN_00766a40(), 512);
            float skill5 = DAT_011dea3c->values.FUN_0066ef50(40);
            FUN_005e58f0(30, DAT_011dea3c, &skill5);
            unsigned int maximum12 = FUN_0042f5a0(20, *DAT_011d3318.FUN_0043d4d0());
            unsigned int minimum17 = FUN_0042f5a0(maximum12, *DAT_011d3c4c.FUN_0043d4d0());
            float difficulty4 =
                FUN_0040ebd0(100.0f, FUN_00404010(0.0f, reinterpret_cast<Base84*&>(DAT_011d95b8->unk194)->FUN_005017a0(reference)));
            float delta2 = FUN_00404010(0.0f, skill5 - difficulty4);
            float denominator55 = 100.0 - difficulty4;
            float fraction41 = denominator55 != 0.0 ? 1.0f - delta2 / denominator55 : 0.5;
            unsigned int count7 = minimum17 + (unsigned int)FUN_004bd510((maximum12 - minimum17) * fraction41, 1.0f);
            if (count7 > 20)
                count7 = 20;
            DAT_011d95b8->SelectWordSet(count7);
            tile4->FUN_00a01350(4100, ">", 1);
            (*reinterpret_cast<Text84*>(&DAT_011d95b8->anim)).FUN_006ffe80(reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[5])->FUN_00a00f30(4036),
                                            reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[5])->FindTraitValue(4003));
            if (*DAT_011d4e4c.FUN_0043d4d0() > 0)
                (*reinterpret_cast<Text84*>(&DAT_011d95b8->anim)).SetCapacity((unsigned int)FUN_004bd510(1000.0 / *DAT_011d4e4c.FUN_0043d4d0(), 1.0f));
            const char* name9 = "hacking_intro_template";
            reinterpret_cast<Entry84**>(DAT_011d95b8->entries)[0] =
                new Entry84(DAT_011d3f58.FUN_004c69f0(), reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[0]), name9, DAT_011d95b8->unk1b4, 0);
            reinterpret_cast<Entry84**>(DAT_011d95b8->entries)[1] = new Entry84(DAT_011d3a38.FUN_004c69f0(), reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[0]), name9,
                                                   DAT_011d95b8->unk1b4 + DAT_011d95b8->unk1b8 * 2, 0);
            reinterpret_cast<Entry84**>(DAT_011d95b8->entries)[2] = new Entry84(DAT_011d3c64.FUN_004c69f0(), reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[0]), name9,
                                                   DAT_011d95b8->unk1b4 + DAT_011d95b8->unk1b8 * 4, 1);
            reinterpret_cast<Entry84**>(DAT_011d95b8->entries)[3] = new Entry84(DAT_011d4c00.FUN_004c69f0(), reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[0]), name9,
                                                   DAT_011d95b8->unk1b4 + DAT_011d95b8->unk1b8 * 6, 0);
            reinterpret_cast<Entry84**>(DAT_011d95b8->entries)[4] = new Entry84(DAT_011d4d5c.FUN_004c69f0(), reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[0]), name9,
                                                   DAT_011d95b8->unk1b4 + DAT_011d95b8->unk1b8 * 8, 1);
            reinterpret_cast<Entry84**>(DAT_011d95b8->entries)[5] = new Entry84(DAT_011d3030.FUN_004c69f0(), reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[0]), name9,
                                                   DAT_011d95b8->unk1b4 + DAT_011d95b8->unk1b8 * 9, 1);
            reinterpret_cast<Entry84**>(DAT_011d95b8->entries)[6] = new Entry84(DAT_011d4b94.FUN_004c69f0(), reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[0]), name9,
                                                   DAT_011d95b8->unk1b4 + DAT_011d95b8->unk1b8 * 11, 0);
            reinterpret_cast<Entry84**>(DAT_011d95b8->entries)[7] = new Entry84(DAT_011d1f44.FUN_004c69f0(), reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[0]), name9,
                                                   DAT_011d95b8->unk1b4 + DAT_011d95b8->unk1b8 * 12, 0);
            reinterpret_cast<Entry84**>(DAT_011d95b8->entries)[8] = new Entry84(DAT_011d1d9c.FUN_004c69f0(), reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[0]), name9,
                                                   DAT_011d95b8->unk1b4 + DAT_011d95b8->unk1b8 * 13, 0);
            reinterpret_cast<Entry84**>(DAT_011d95b8->entries)[9] = new Entry84(DAT_011d306c.FUN_004c69f0(), reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[0]), name9,
                                                   DAT_011d95b8->unk1b4 + DAT_011d95b8->unk1b8 * 14, 0);
            reinterpret_cast<Entry84**>(DAT_011d95b8->entries)[10] = new Entry84(DAT_011d484c.FUN_004c69f0(), reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[0]), name9,
                                                    DAT_011d95b8->unk1b4 + DAT_011d95b8->unk1b8 * 15, 0);
            reinterpret_cast<Entry84**>(DAT_011d95b8->entries)[11] = new Entry84(DAT_011d4f18.FUN_004c69f0(), reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[0]), name9,
                                                    DAT_011d95b8->unk1b4 + DAT_011d95b8->unk1b8 * 16, 0);
            reinterpret_cast<Entry84**>(DAT_011d95b8->entries)[12] = new Entry84(DAT_011d4690.FUN_004c69f0(), reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[0]), name9,
                                                    DAT_011d95b8->unk1b4 + DAT_011d95b8->unk1b8 * 17, 0);
            reinterpret_cast<Entry84**>(DAT_011d95b8->entries)[13] = new Entry84(DAT_011d2130.FUN_004c69f0(), reinterpret_cast<Tile84*>(DAT_011d95b8->m_pTiles[0]), name9,
                                                    DAT_011d95b8->unk1b4 + DAT_011d95b8->unk1b8 * 19, 1);
        }
        reinterpret_cast<BSSoundHandle&>(DAT_011d95b8->sounds[0]).Play(0);
        menu24->FUN_00a1dc20(0);
        return tile4;
    }
    else if (menu24 && menu24->FUN_00726070())
        delete menu24;
    return 0;
}
}  // namespace fnv_00765b80

namespace fnv_00766b80 {
struct HackTile
{
    void* data;
    void Refresh();
    HackTile* Parent();
    const char* Text();
    float Float(int);
    void SetText(const char*);
    void Enable(bool);
};
struct HackSetting
{
    const char* String();
    const char* GetString();
};
struct HackList
{
    int a, b, c;
    unsigned int Count();
    struct HackItem* RemoveTail();
};
struct HackNumberList
{
    int a, b, c;
    void Add(const unsigned int&);
};
struct HackItem
{
    virtual ~HackItem();
};
struct HackForm
{
    unsigned int Type();
};
struct HackRef
{
    HackForm* Owner();
};
struct HackTarget
{
    int Difficulty(HackRef*);
};
struct HackPlayer
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual void slot2bc();
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual void slot2e4();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void slot2f4();
    virtual void slot2f8();
    virtual void slot2fc();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30c();
    virtual void slot310();
    virtual void slot314();
    virtual void slot318();
    virtual void slot31c();
    virtual void slot320();
    virtual void slot324();
    virtual void slot328();
    virtual void slot32c();
    virtual void slot330();
    virtual void slot334();
    virtual void slot338();
    virtual void slot33c();
    virtual void slot340();
    virtual void slot344();
    virtual void slot348();
    virtual void slot34c();
    virtual void slot350();
    virtual void slot354();
    virtual void slot358();
    virtual void slot35c();
    virtual void slot360();
    virtual void slot364();
    virtual void slot368();
    virtual void slot36c();
    virtual void slot370();
    virtual void slot374();
    virtual void slot378();
    virtual void slot37c();
    virtual void slot380();
    virtual void slot384();
    virtual void slot388();
    virtual void slot38c();
    virtual void slot390();
    virtual void slot394();
    virtual void slot398();
    virtual void slot39c();
    virtual void slot3a0();
    virtual void slot3a4();
    virtual void slot3a8();
    virtual void slot3ac();
    virtual void slot3b0();
    virtual void slot3b4();
    virtual void slot3b8();
    virtual void slot3bc();
    virtual void slot3c0();
    virtual void slot3c4();
    virtual void slot3c8();
    virtual void slot3cc();
    virtual void slot3d0();
    virtual void slot3d4();
    virtual void slot3d8();
    virtual void slot3dc();
    virtual void slot3e0();
    virtual void slot3e4();
    virtual void slot3e8();
    virtual void slot3ec();
    virtual void slot3f0();
    virtual void slot3f4();
    virtual void slot3f8();
    virtual void slot3fc();
    virtual void slot400();
    virtual void slot404();
    virtual void slot408();
    virtual void slot40c();
    virtual void slot410();
    virtual void slot414();
    virtual void slot418();
    virtual void slot41c();
    virtual void slot420();
    virtual void slot424();
    virtual void slot428();
    virtual void slot42c();
    virtual void slot430();
    virtual void slot434();
    virtual void slot438();
    virtual void slot43c();
    virtual void slot440();
    virtual void slot444();
    virtual void slot448();
    virtual void slot44c();
    virtual void slot450();
    virtual void slot454();
    virtual void slot458();
    virtual void slot45c();
    virtual void slot460();
    virtual void slot464();
    virtual void slot468();
    virtual void slot46c();
    virtual void slot470();
    virtual void slot474();
    virtual void slot478();
    virtual void slot47c();
    virtual void slot480();
    virtual void slot484();
    virtual void Reward(int);
    void Crime(HackRef*, HackForm*, int);
};
extern HackPlayer* g_thePlayer;
extern HackSetting g_011d26dc, g_011d1e78, g_011d430c, g_011d47e0, g_011d4f6c, g_011d2604, g_011d3444, g_011d4858,
    g_011d4ae0, g_011d2b2c, g_011d1f74, g_011d3144, g_011d339c, g_011d2e20;
extern unsigned int DAT_011d95c0;
void* FUN_004b7210();
bool FUN_004b71d0();
unsigned int gm_GetTickCount();
int FUN_00ec86e1(int);
unsigned int BSStringLength(const char*);
extern "C" unsigned int __cdecl FUN_005a00a0(unsigned int);
void SuccessRef(HackRef*, bool);
void FailRef(HackRef*, bool);
int FUN_006705b0(int, int);
void Finish(int);
// Handles a tile click by comparing the entered word to the password, updating the display, and triggering success or failure outcomes based on the match result.
} // namespace fnv_00766b80

// @fnv 0x00766b80
void HackingMenu::HandleSelection(int aiButtonIndex, Tile* tile)
{
    using namespace fnv_00766b80;
    fnv_00766b80::FUN_004b7210();
    if (fnv_00766b80::FUN_004b71d0())
        tile = m_pkCursorTile;
    if (!tile && aiButtonIndex >= 0 && aiButtonIndex < 8)
        tile = m_pTiles[aiButtonIndex];
    if (m_iStage == 0)
    {
        if (fnv_00766b80::gm_GetTickCount() > fnv_00766b80::DAT_011d95c0)
            BuildHackingPasswordFile();
        return;
    }
    else if (m_iStage == 1)
    {
        for (unsigned int iter = 0; iter < 46; iter++)
            if (reinterpret_cast<fnv_00766b80::HackTile**>(entries)[iter])
                reinterpret_cast<fnv_00766b80::HackTile**>(entries)[iter]->Refresh();
    }
    else if (m_iStage == 2 && tile && reinterpret_cast<fnv_00766b80::HackTile*>(tile)->Parent() == reinterpret_cast<fnv_00766b80::HackTile**>(m_pTiles)[2])
    {
        (*reinterpret_cast<fnv_00766b80::HackTile*>(&anim)).Refresh();
        const char* word = (*reinterpret_cast<fnv_00766b80::HackTile*>(&anim)).Text();
        if (word && *word)
        {
            reinterpret_cast<BSSoundHandle&>(sounds[4]).Play(false);
            unsigned int matched = CountMatchingChars(word, reinterpret_cast<const char*>(unk19c));
            if (!fnv_00766b80::FUN_00ec86e1(*word) && fnv_00766b80::BSStringLength(word) > 1)
            {
                BSStringT<char> c[3];
                unsigned int j;
                c[0].PrintfString("%s%s", ">", word);
                if (unk1a8 == 1)
                {
                    c[1].PrintfString("%s%s", ">", g_011d26dc.String());
                    j = 2;
                }
                else if (unk1d9[0] || fnv_00766b80::FUN_005a00a0(4))
                {
                    RemoveRandomWord();
                    (*reinterpret_cast<HackNumberList*>(&list188)).Add(12 * (unsigned int)(reinterpret_cast<fnv_00766b80::HackTile*>(tile)->Float(0x1004) * 17.0 + reinterpret_cast<fnv_00766b80::HackTile*>(tile)->Float(0xfac)) + GetScaledValue() - 7);
                    c[1].PrintfString("%s%s", ">", g_011d1e78.String());
                    j = 2;
                }
                else
                {
                    if (reinterpret_cast<unsigned int&>(unk1a0) == 1)
                    {
                        reinterpret_cast<fnv_00766b80::HackTile**>(entries)[1]->SetText(g_011d430c.GetString());
                        reinterpret_cast<fnv_00766b80::HackTile**>(entries)[1]->Enable(false);
                        reinterpret_cast<fnv_00766b80::HackTile**>(entries)[1]->Refresh();
                    }
                    c[1].PrintfString("%s%s", ">", g_011d47e0.String());
                    c[2].PrintfString("%s%s", ">", g_011d4f6c.String());
                    reinterpret_cast<unsigned int&>(unk1a0) = static_cast<unsigned int>(unk1a4);
                    unk1d9[0] = true;
                    (*reinterpret_cast<HackNumberList*>(&list188)).Add(12 * (unsigned int)(reinterpret_cast<fnv_00766b80::HackTile*>(tile)->Float(0x1004) * 17.0 + reinterpret_cast<fnv_00766b80::HackTile*>(tile)->Float(0xfac)) + GetScaledValue() - 7);
                    while ((*reinterpret_cast<fnv_00766b80::HackList*>(&list174)).Count() < static_cast<unsigned int>(unk1a4))
                        BuildHackingGuessTemplate();
                    j = 3;
                }
                const char* e[3] = {c[0], c[1], c[2]};
                AddValueRows(j, reinterpret_cast<const unsigned int*>(e));
            }
            else if (matched == static_cast<unsigned int>(unk1ac))
            {
                BSStringT<char> c[5];
                c[0].PrintfString("%s%s", ">", word);
                c[1].PrintfString("%s%s", ">", g_011d2604.String());
                c[2].PrintfString("%s%s", ">", g_011d3444.String());
                c[3].PrintfString("%s%s", ">", g_011d4858.String());
                c[4].PrintfString("%s%s", ">", g_011d4ae0.String());
                const char* e[5] = {c[0], c[1], c[2], c[3], c[4]};
                AddValueRows(5, reinterpret_cast<const unsigned int*>(e));
                reinterpret_cast<BSSoundHandle&>(sounds[1]).PlayAfter(250, 0);
                reinterpret_cast<unsigned int&>(unk1d0) = fnv_00766b80::gm_GetTickCount() + 3000;
                m_iStage = 4;
                if (reinterpret_cast<HackTarget*>(unk194))
                {
                    SuccessRef(reinterpret_cast<HackRef*>(unk198), true);
                    g_thePlayer->Reward(FUN_006705b0(2, reinterpret_cast<HackTarget*>(unk194)->Difficulty(reinterpret_cast<HackRef*>(unk198))));
                    HackForm* owner = reinterpret_cast<HackRef*>(unk198)->Owner();
                    if (owner)
                    {
                        int zero = 0;
                        if (owner->Type() == 8)
                        {
                            HackForm* faction = owner;
                        }
                        else
                        {
                            HackForm* npc = owner;
                        }
                        g_thePlayer->Crime(reinterpret_cast<HackRef*>(unk198), owner, -1);
                    }
                }
                Finish(5);
            }
            else
            {
                BSStringT<char> lines3[4];
                lines3[0].PrintfString("%s%s", ">", word);
                lines3[1].PrintfString("%s%s", ">", g_011d26dc.String());
                --reinterpret_cast<unsigned int&>(unk1a0);
                if (reinterpret_cast<unsigned int&>(unk1a0))
                {
                    lines3[2].PrintfString("%s%d/%d %s.", ">", matched, static_cast<unsigned int>(unk1ac), g_011d2b2c.String());
                    const char* values3[3] = {lines3[0], lines3[1], lines3[2]};
                    AddValueRows(3, reinterpret_cast<const unsigned int*>(values3));
                    if (reinterpret_cast<unsigned int&>(unk1a0) == 1)
                    {
                        reinterpret_cast<fnv_00766b80::HackTile**>(entries)[1]->SetText(g_011d1f74.GetString());
                        reinterpret_cast<fnv_00766b80::HackTile**>(entries)[1]->Refresh();
                        reinterpret_cast<fnv_00766b80::HackTile**>(entries)[1]->Enable(true);
                    }
                }
                else
                {
                    lines3[2].PrintfString("%s%s", ">", g_011d3144.String());
                    lines3[3].PrintfString("%s", g_011d339c.String());
                    const char* values4[4] = {lines3[0], lines3[1], lines3[2], lines3[3]};
                    AddValueRows(4, reinterpret_cast<const unsigned int*>(values4));
                    m_iStage = 3;
                    if (reinterpret_cast<HackTarget*>(unk194))
                        FailRef(reinterpret_cast<HackRef*>(unk198), true);
                }
                reinterpret_cast<BSSoundHandle&>(sounds[2]).PlayAfter(250, 0);
                delete (*reinterpret_cast<fnv_00766b80::HackList*>(&list174)).RemoveTail();
            }
            BSStringT<char> status;
            status.PrintfString("%d %s", reinterpret_cast<unsigned int&>(unk1a0), g_011d2e20.String());
            reinterpret_cast<fnv_00766b80::HackTile**>(entries)[2]->SetText(status);
            reinterpret_cast<fnv_00766b80::HackTile**>(entries)[2]->Refresh();
            FUN_00768020();
            m_bBlink = true;
        }
    }
}

