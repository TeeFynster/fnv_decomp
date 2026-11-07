
// src/gamebryo2.2/corelibs/niparticle/bsstrippsysdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/bsstrippsysdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPSysData.h"
#include "../../../../include/NiStream.h"

struct FUN_00c25dd0_shell
{
    short __thiscall BSStripPSysData_GetMaxPointCount();
};

// @fnv 0x00c25dd0
// src: COMMUNITY 0x00c25dd0
short __thiscall FUN_00c25dd0_shell::BSStripPSysData_GetMaxPointCount()
{
    return *reinterpret_cast<short*>(this + 0x80);
}

extern "C" void* g_01202680;

// @fnv 0x00c25ee0
// src: COMMUNITY 0x00c25ee0
void* __cdecl BSStripPSysData_GetRTTI()
{
    return &g_01202680;
}

struct FUN_00c25e70_shell
{
    void* __thiscall GetElementField(unsigned short a, unsigned short b);
};

// Indexes the pointer at this+0x7c by a*32, then returns that element plus b*0x84+0xc.
// @fnv 0x00c25e70
void* FUN_00c25e70_shell::GetElementField(unsigned short ausIndex, unsigned short ausSubIndex)
{
    void* base = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x7c);
    void* pElement = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(base) + ausIndex * 32);
    return reinterpret_cast<unsigned char*>(pElement) + ausSubIndex * 0x84 + 0xc;
}

extern "C" void __cdecl _delete(void* ptr, unsigned int size);
void* __cdecl FUN_00c25ef0();

struct FUN_00c26380_shell
{
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};

// @fnv 0x00c26380
void* __thiscall FUN_00c26380_shell::DestroyIfFlagged(unsigned int flags)
{
    void* p = FUN_00c25ef0();
    if (flags & 1)
        _delete(this, 0x90);
    return this;
}

struct FUN_00c25db0_shell
{
    unsigned short __thiscall BSStripPSysData_GetPointCount(unsigned short index);
};
// @fnv 0x00c25db0
// src: COMMUNITY 0x00c25db0
unsigned short __thiscall FUN_00c25db0_shell::BSStripPSysData_GetPointCount(unsigned short index)
{
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(*reinterpret_cast<unsigned int**>(
                                                  reinterpret_cast<unsigned char*>(this) + 0x7c)) +
                                              4 + index * 32);
}

struct FUN_00c25de0_shell
{
    float __thiscall GetEntryFloat(unsigned short idx);
};

// @fnv 0x00c25de0
float __thiscall FUN_00c25de0_shell::GetEntryFloat(unsigned short usIndex)
{
    return *(float*)((char*)*(int**)((char*)this + 0x7c) + 0x1c + (int)usIndex * 32);
}

// @fnv 0x00c24c90
__declspec(noinline) NiPSysData::NiPSysData() : m_pkParticleInfo(0), m_pfRotationSpeeds(0), m_usNumActive(0)
{
    m_usNumParticles = 0;
}

// 0x00c25cd0 compares fields at +0x80/+0x84/+0x88/+0x8c after NiPSysData: particle strip data, not an 8-byte BSStringT<char>.
struct ParticleStripData : NiPSysData
{
    void* pkStripPoints;
    unsigned short usMaxPointCount;
    float fStartCapSize;
    float fEndCapSize;
    bool bDoZPrePass;
};
struct FUN_00c25cd0_shell : ParticleStripData
{
    bool __thiscall BSStripPSysData_IsEqual(NiObject* pkObject);
};
// Compares the base fields and then usMaxPointCount, fStartCapSize, fEndCapSize and bDoZPrePass against another ParticleStripData, returning true if all match.
// @fnv 0x00c25cd0
// src: XBOX_PDB 0x00c25cd0
bool __thiscall FUN_00c25cd0_shell::BSStripPSysData_IsEqual(NiObject* pkObject)
{
    ParticleStripData* pkDest = (ParticleStripData*)pkObject;
    if (NiPSysData::IsEqual(pkObject) && pkDest->usMaxPointCount == usMaxPointCount && pkDest->fStartCapSize == fStartCapSize &&
        pkDest->fEndCapSize == fEndCapSize && pkDest->bDoZPrePass == bDoZPrePass)
        return true;
    return false;
}

struct S84_25e20
{
    char _0[124];
    float v;
    char _80[4];
};
struct S20_25e20
{
    void* p;
    char _4[28];
};
struct FUN_00c25e20_shell
{
    float __thiscall GetInnerValue(unsigned short, unsigned short);
};
// Indexes base[a].p to an inner object and returns its float field at index b.
// @fnv 0x00c25e20
float __thiscall FUN_00c25e20_shell::GetInnerValue(unsigned short ausOuterIndex, unsigned short ausInnerIndex)
{
    S20_25e20* base = *(S20_25e20**)((char*)this + 0x7c);
    S84_25e20* inner = (S84_25e20*)base[ausOuterIndex].p;
    return inner[ausInnerIndex].v;
}

struct FUN_00c25e40_shell
{
    float __thiscall BSStripPSysData_GetPointRadii(unsigned short a, unsigned short b);
};
struct FUN_00c25e40_Inner
{
    char _0[0x80];
    float v;
};
struct FUN_00c25e40_Outer
{
    FUN_00c25e40_Inner* p;
    char _4[28];
};
// Reads a pointer from this+0x7c, indexes it by a, then indexes that object's p by b and returns the float v.
// @fnv 0x00c25e40
// src: COMMUNITY 0x00c25e40
float __thiscall FUN_00c25e40_shell::BSStripPSysData_GetPointRadii(unsigned short a, unsigned short b)
{
    return (*(FUN_00c25e40_Outer**)((char*)this + 0x7c))[a].p[b].v;
}

struct FUN_00c25e90_entry
{
    void* ptr;
    char pad[28];
};
struct FUN_00c25e90_shell
{
    char _pad[124];
    FUN_00c25e90_entry* arr;
    void* __thiscall BSStripPSysData_GetPointNorms(unsigned short a, unsigned short b);
};
// Returns a pointer into the entry at index a, offset by b * 0x84 + 0x48 from its ptr.
// @fnv 0x00c25e90
// src: COMMUNITY 0x00c25e90
void* __thiscall FUN_00c25e90_shell::BSStripPSysData_GetPointNorms(unsigned short ausIndex, unsigned short b)
{
    return (char*)arr[ausIndex].ptr + b * 0x84 + 0x48;
}

struct FUN_00c25eb0_shell
{
    float __thiscall BSStripPSysData_GetTexCoordDelta(unsigned short a);
};
// Returns 1.0 divided by (the unsigned short at offset 6 of the entry at this+0x7c indexed by a, minus 1.0).
// @fnv 0x00c25eb0
// src: COMMUNITY 0x00c25eb0
float __thiscall FUN_00c25eb0_shell::BSStripPSysData_GetTexCoordDelta(unsigned short ausIndex)
{
    return 1.0f / ((float)*(unsigned short*)(*(char**)((char*)this + 0x7c) + (ausIndex << 5) + 6) - 1.0f);
}

struct DataBufferInfo
{
    char* m_pData;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct FUN_00c25e00_cls
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
    DataBufferInfo* m_pTable;

    char* GetSlotData(unsigned short auIndex, unsigned short auSlot);
};

// @fnv 0x00c25e00
char* FUN_00c25e00_cls::GetSlotData(unsigned short auTableIndex, unsigned short auSlotIndex)
{
    return m_pTable[auTableIndex].m_pData + auSlotIndex * 0x84;
}

// ResetEntry : reset/initialise one 32-byte entry of the table at this+0x7c.

// The lowest float (-FLT_MAX, bit pattern 0xFF7FFFFF) is kept as an explicit
// bit pattern so that it gets its own data symbol instead of the compiler's
// shared "__real@ff7fffff" literal.
union FUN_00c25d40_bits
{
    unsigned int u;
    float f;
};
static const FUN_00c25d40_bits kNegMax = {0xff7fffffu};

struct FUN_00c25d40_entry
{
    void* unk00;           // +0x00 : pointer to the 0x84-byte sub records
    unsigned short unk04;  // +0x04
    unsigned short unk06;  // +0x06
    int unk08;             // +0x08
    int unk0c;             // +0x0c
    int unk10;             // +0x10
    int unk14;             // +0x14
    int unk18;             // +0x18
    float unk1c;           // +0x1c
};

struct FUN_00c25d40_shell
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
    FUN_00c25d40_entry* m_entries;   // +0x7c : table of 32-byte entries
    unsigned short m_uiFilterValue;  // +0x80
    void __thiscall ResetEntry(unsigned short index);
};

// @fnv 0x00c25d40
void FUN_00c25d40_shell::ResetEntry(unsigned short index)
{
    m_entries[index].unk04 = 0;
    m_entries[index].unk06 = 0;
    m_entries[index].unk10 = m_uiFilterValue;
    m_entries[index].unk1c = kNegMax.f;
    m_entries[index].unk14 = -1;
    m_entries[index].unk18 = 0;
    m_entries[index].unk0c = m_uiFilterValue;
    m_entries[index].unk08 = m_uiFilterValue;
}

extern "C" void __cdecl NiFree(void* ptr);
struct PointItem
{
    void* ptr;
    char pad[0x1c];
};
struct FUN_00c25ef0 : public NiPSysData
{
    PointItem* pkStripPoints;
    virtual ~FUN_00c25ef0();
};
// Frees each strip point's pointer for all m_usVertices entries, nulls them, then frees the pkStripPoints array.
// @fnv 0x00c25ef0
FUN_00c25ef0::~FUN_00c25ef0()
{

    unsigned short usVertexCount = m_usVertices;
    for (unsigned int i = 0; i < (unsigned int)usVertexCount; ++i)
    {
        NiFree(pkStripPoints[i].ptr);
        pkStripPoints[i].ptr = 0;
    }

    NiFree(pkStripPoints);
}

struct S_00c26000_Item
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float unk1c;
};

struct S_00c26000_Proc;
struct S_00c26000_Strip;

struct S_00c26000_Strip : NiPSysData
{
    S_00c26000_Item* unk7c;
    unsigned short unk80;
    float unk84;
    float unk88;
    unsigned char unk8c;
    void CloneStrip(S_00c26000_Strip* dest, S_00c26000_Proc* proc);
};

void* _NiMalloc_00aa1070(unsigned int size);
void* FUN_00ec44d0(void* dst, const void* src, unsigned int n);

// Copies the base strip and its fields into dest, then allocates and deep-copies the item array from unk7c into dest->unk7c.
// @fnv 0x00c26000
void S_00c26000_Strip::CloneStrip(S_00c26000_Strip* dest, S_00c26000_Proc* proc)
{
    NiPSysData::CopyMemberData(dest, *reinterpret_cast<CloningProcess*>(proc));
    dest->unk80 = unk80;
    dest->unk84 = unk84;
    dest->unk88 = unk88;
    dest->unk8c = unk8c;
    unsigned short n = m_usVertices;
    S_00c26000_Item* items = (S_00c26000_Item*)_NiMalloc_00aa1070(n * 32);
    for (unsigned int i = 0; i < n; i++)
    {
        items[i].unk1c = unk7c[i].unk1c;
        items[i].unk04 = unk7c[i].unk04;
        items[i].unk06 = unk7c[i].unk06;
        items[i].unk0c = unk7c[i].unk0c;
        items[i].unk08 = unk7c[i].unk08;
        items[i].unk10 = unk7c[i].unk10;
        items[i].unk14 = unk7c[i].unk14;
        items[i].unk18 = unk7c[i].unk18;
        items[i].unk00 = _NiMalloc_00aa1070(items[i].unk10 * 0x84);
        FUN_00ec44d0(items[i].unk00, unk7c[i].unk00, unk7c[i].unk04 * 0x84);
    }
    dest->unk7c = items;
}

typedef unsigned int(__cdecl* WriteFn)(void* ctx, void* buf, unsigned int size, unsigned int* pCount,
                                       unsigned int count);

struct StreamCtx
{
    unsigned int unk00;
    unsigned int m_04;
    unsigned int unk08;
    WriteFn m_0C;
};

struct StreamOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    StreamCtx* m_250;
};

class FUN_00c26570_cls : public NiPSysData
{
  public:
    unsigned int unk7C;
    unsigned int m_80;
    unsigned int m_84;
    unsigned int m_88;
    unsigned int m_8C;
    void BSStripPSysData_SaveBinary(StreamOwner* a1);
};

// @fnv 0x00c26570
// src: XBOX_PDB 0x00c26570
void FUN_00c26570_cls::BSStripPSysData_SaveBinary(StreamOwner* apOwner)
{
    NiPSysData::SaveBinary(*reinterpret_cast<NiStream*>(apOwner));
    StreamCtx* s = apOwner->m_250;
    {
        unsigned int n = 2;
        s->m_04 += s->m_0C(s, &m_80, 2, &n, 1);
    }
    s = apOwner->m_250;
    {
        unsigned int n = 4;
        s->m_04 += s->m_0C(s, &m_84, 4, &n, 1);
    }
    s = apOwner->m_250;
    {
        unsigned int n = 4;
        s->m_04 += s->m_0C(s, &m_88, 4, &n, 1);
    }
    s = apOwner->m_250;
    {
        unsigned int n = 1;
        s->m_04 += s->m_0C(s, &m_8C, 1, &n, 1);
    }
}

struct FUN_00c25f40_rec
{
    unsigned short m00;
    unsigned short m02;
    unsigned short m04;
    unsigned short m06;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
};

struct FUN_00c25f40_cls
{
    char _0[0x50];
    unsigned short m50;
    char _52[0x2a];
    FUN_00c25f40_rec* m7c;
    void FUN_00c24cc0(unsigned short a);
    void* PopRecord(unsigned int a);
};

// Decrements the record's count and advances its index, or removes the slot and swaps the last record into it.
// @fnv 0x00c25f40
void* FUN_00c25f40_cls::PopRecord(unsigned int auiIndex)
{
    unsigned short idx = (unsigned short)auiIndex;
    unsigned int off = (unsigned int)idx * 32;
    if (m7c[idx].m04 > 1)
    {
        FUN_00c25f40_rec* pSlot = &m7c[idx];
        int iModulus = pSlot->m10;
        int r = (pSlot->m14 + 1) % iModulus;
        if (r < 0)
        {
            r += iModulus;
        }
        pSlot->m14 = r;
        m7c[idx].m04 = (unsigned short)(m7c[idx].m04 - 1);
        int* p = &m7c[idx].m0c;
        (*p)--;
        return p;
    }
    unsigned short last = m50;
    last--;
    FUN_00c24cc0(idx);
    if (idx != last)
    {
        FUN_00c25f40_rec* cur = (FUN_00c25f40_rec*)((char*)m7c + off);
        FUN_00c25f40_rec tmpSlot = *cur;
        *cur = m7c[last];
        m7c[last] = tmpSlot;
    }
}

struct ArrHdr
{
    unsigned int unk00, unk04;
    unsigned short unk08, unk0A, unk0C, unk0E;
    void Grow(unsigned int n);
    void SetAt(unsigned int index, void** item);
    void Add(void* value)
    {
        unsigned int index = unk0A;
        unsigned int capacity = unk08;
        if (index >= capacity)
            Grow(unk0E + index);
        SetAt(index, &value);
    }
};
extern "C" void* g_01202680;
extern "C" void* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);
extern "C" void* __cdecl NiGetViewerString_00a7d490(const char*, unsigned int);
extern "C" void* __cdecl NiGetViewerString_00a7d550(const char*, float);
extern "C" void* __cdecl NiGetViewerString(const char*, unsigned int);
extern "C" char str_010be5ec[], str_010be5dc[], str_010be5d0[], str_010be5c4[];
struct FUN_00c26630_cls : NiPSysData
{
    unsigned int unk7c;
    unsigned short m80, unk82;
    float m84, m88;
    unsigned char m8c;
    void BSStripPSysData_GetViewerStrings(void* p);
};
// Calls FUN_00c255b0 on the array, then appends entries built from g_01202680, m80, m84, m88 and m8c via the FUN_00a7d3xx/d4xx/d5xx helpers.
// @fnv 0x00c26630
// src: XBOX_PDB 0x00c26630
void FUN_00c26630_cls::BSStripPSysData_GetViewerStrings(void* pArray)
{
    ArrHdr* a = (ArrHdr*)pArray;
    NiPSysData::GetViewerStrings(reinterpret_cast<NiViewerStringsArray*>(a));
    pArray = NiViewerStrings_NiGetViewerString_Title(g_01202680);
    a->Add(pArray);
    pArray = NiGetViewerString_00a7d490(str_010be5ec, m80);
    a->Add(pArray);
    pArray = NiGetViewerString_00a7d550(str_010be5dc, m84);
    a->Add(pArray);
    pArray = NiGetViewerString_00a7d550(str_010be5d0, m88);
    a->Add(pArray);
    pArray = NiGetViewerString(str_010be5c4, m8c);
    a->Add(pArray);
}

struct FUN_00a817b0_shell : NiPSysData
{
    bool __thiscall BSStripPSysData_RegisterStreamables(NiStream& a);
};
// @fnv 0x00a817b0
// src: XBOX_PDB 0x00a817b0
bool __thiscall FUN_00a817b0_shell::BSStripPSysData_RegisterStreamables(NiStream& a)
{
    return NiPSysData::RegisterStreamables(a);
}

#include <float.h>
struct S_00c26410_Stream;
struct S_00c26410_Bin
{
    unsigned int unk00;
    unsigned int m_uiPos;
    unsigned int(__cdecl* m_pfnRead)(S_00c26410_Bin*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* p, unsigned int bytes, unsigned int* sz, unsigned int n)
    {
        return m_pfnRead(this, p, bytes, sz, n);
    }
};

struct S_00c26410_Stream
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    S_00c26410_Bin* m_pkBin;
};

static __forceinline void S_BinRead(S_00c26410_Bin* bin, void* v, unsigned int bytes)
{
    unsigned int sz = bytes;
    bin->m_uiPos += bin->Read(v, bytes, &sz, 1);
}

struct S_00c26410_Elem
{
    void* m_00;
    unsigned short m_04;
    unsigned short m_06;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    float m_1C;
};

// game global: -FLT_MAX
static float DAT_01015f5c = -FLT_MAX;
void* __cdecl _NiMalloc_00aa1070(unsigned int n);

struct S_00c26410_Mid : NiPSysData
{
    S_00c26410_Elem* m_7C;
    S_00c26410_Elem& At(unsigned short k)
    {
        return m_7C[k];
    }
};

struct FUN_00c26410_cls : S_00c26410_Mid
{
    unsigned short m_80;
    unsigned short unk82;
    float m_84;
    float m_88;
    unsigned char m_8C;
    void BSStripPSysData_LoadBinary(S_00c26410_Stream* pkStream);
};

// Reads m_80, m_84, m_88, m_8C from pkStream, allocates m_7C with m_08 elements, and initializes each element's fields from m_80 and DAT_01015f5c.
// @fnv 0x00c26410
// src: XBOX_PDB 0x00c26410
void FUN_00c26410_cls::BSStripPSysData_LoadBinary(S_00c26410_Stream* pkStream)
{
    NiPSysData::LoadBinary(*reinterpret_cast<NiStream*>(pkStream));
    S_BinRead(pkStream->m_pkBin, &m_80, 2);
    S_BinRead(pkStream->m_pkBin, &m_84, 4);
    S_BinRead(pkStream->m_pkBin, &m_88, 4);
    S_BinRead(pkStream->m_pkBin, &m_8C, 1);
    unsigned short n = m_usVertices;
    m_7C = (S_00c26410_Elem*)_NiMalloc_00aa1070(n * sizeof(S_00c26410_Elem));
    for (unsigned int i = 0; i < n; i++)
    {
        m_7C[i].m_00 = _NiMalloc_00aa1070(m_80 * 0x84);
        At(i).m_04 = 0;
        At(i).m_06 = 0;
        At(i).m_10 = m_80;
        At(i).m_1C = DAT_01015f5c;
        At(i).m_14 = -1;
        At(i).m_18 = 0;
        At(i).m_0C = m_80;
        At(i).m_08 = m_80;
    }
}

extern const void* DAT_010be514[];
void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct StripCloneC263 : S_00c26000_Strip
{
    StripCloneC263() throw()
    {
        *reinterpret_cast<const void***>(this) = DAT_010be514;
        unk7c = 0;
    }

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }

    StripCloneC263* BSStripPSysData_CreateClone(S_00c26000_Proc& cloning);
};

// Allocates a new StripCloneC263 and copies the source strip into it via CloneStrip, returning the new object.
// @fnv 0x00c263b0
// src: XBOX_PDB 0x00c263b0
StripCloneC263* StripCloneC263::BSStripPSysData_CreateClone(S_00c26000_Proc& cloning)
{
    StripCloneC263* result = new StripCloneC263;
    CloneStrip(result, &cloning);
    return result;
}
