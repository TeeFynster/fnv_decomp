
// src/gamebryo2.2/corelibs/nimain/nitrishapedynamicdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nitrishapedynamicdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiTriShapeData.h"

struct NiTriShapeDynamicData
{
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    void GetStripData_00a81730(unsigned short& usStrips, const unsigned short*& pusStripLengths,
                      const unsigned short*& pusTriList, unsigned int& uiStripLengthSum);
};

// @fnv 0x00a81730
// src: XBOX_PDB 0x00a81730
void __thiscall NiTriShapeDynamicData::GetStripData_00a81730(unsigned short& usStrips, const unsigned short*& pusStripLengths,
                                                    const unsigned short*& pusTriList, unsigned int& uiStripLengthSum)
{
    usStrips = *(unsigned short*)((char*)this + 0x5a);
    pusStripLengths = (const unsigned short*)0;
    pusTriList = *(const unsigned short**)((char*)this + 0x48);
    uiStripLengthSum = *(unsigned short*)((char*)this + 0x5a) * 3;
}

extern void* g_011f5af4;

// @fnv 0x00a81800
// src: COMMUNITY 0x00a81800
void* __cdecl NiTriShapeDynamicData_GetRTTI()
{
    return &g_011f5af4;
}

namespace fnv_00a81820 {
struct NiTriShapeDynamicData
{
    void __thiscall SetActiveTriangleCount(unsigned short usActiveTriangles);
};

// @fnv 0x00a81820
// src: XBOX_PDB 0x00a81820
void __thiscall NiTriShapeDynamicData::SetActiveTriangleCount(unsigned short usActiveTriangles)
{
    *(unsigned short*)((char*)this + 0x5a) = usActiveTriangles;
}
}  // namespace fnv_00a81820

struct NiTriShapeDynamicDataShell : NiTriShapeData
{
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    bool NiTriShapeDynamicData_IsEqual(const NiTriShapeDynamicDataShell*);
};
// Compares this shape data with another via FUN_00a7b7e0 and checks that the active vertex and triangle counts match.
// @fnv 0x00a817c0
// src: XBOX_PDB 0x00a817c0
bool NiTriShapeDynamicDataShell::NiTriShapeDynamicData_IsEqual(const NiTriShapeDynamicDataShell* other)
{
    if (IsEqual_00a7b7e0(other) && *(unsigned short*)((char*)this + 0x58) == *(unsigned short*)((char*)other + 0x58) &&
        *(unsigned short*)((char*)this + 0x5a) == *(unsigned short*)((char*)other + 0x5a))
        return true;
    return false;
}

struct NiTriShapeDynamicData_shell : NiTriShapeDynamicData
{
    void NiTriShapeDynamicData_SetActiveVertexCount(unsigned short usActiveVertices);
};

// @fnv 0x00a81810
// src: XBOX_PDB 0x00a81810
void NiTriShapeDynamicData_shell::NiTriShapeDynamicData_SetActiveVertexCount(unsigned short usActiveVertices)
{
    ((unsigned short*)this)[0x2c] = usActiveVertices;
}

void __fastcall FUN_00a7b8c0(void*);
void __cdecl _delete(void*, unsigned int);
struct S00a81830
{
    void* Destroy(unsigned int);
};
// Calls FUN_00a7b8c0 on this and, when bit 0 of a is set, frees this with _delete, then returns this.
// @fnv 0x00a81830
void* S00a81830::Destroy(unsigned int auiFlags)
{
    FUN_00a7b8c0(this);
    if (auiFlags & 1)
        _delete(this, 0x5c);
    return this;
}

struct S_00a818b0_Bin
{
    unsigned int unk00;
    unsigned int m_uiPos;
    unsigned int unk08;
    unsigned int(__cdecl* m_pfnRead)(S_00a818b0_Bin*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* p, unsigned int bytes, unsigned int* sz, unsigned int n)
    {
        return m_pfnRead(this, p, bytes, sz, n);
    }
};
static __forceinline void S_BinRead(S_00a818b0_Bin* bin, void* v, unsigned int bytes)
{
    unsigned int sz = 2;
    bin->m_uiPos += bin->Read(v, bytes, &sz, 1);
}
struct FUN_00a818b0_cls
{
    void FUN_00a7bbe0(void* pOther);
    void NiTriShapeDynamicData_SaveBinary(void* pOther);
};
// Calls FUN_00a7bbe0, then reads two 2-byte values from the stream at pOther+0x250 into this+0x58 and this+0x5a.
// @fnv 0x00a818b0
// src: XBOX_PDB 0x00a818b0
void FUN_00a818b0_cls::NiTriShapeDynamicData_SaveBinary(void* pOther)
{
    char* pObj = (char*)pOther;
    FUN_00a7bbe0(pOther);
    S_BinRead(*(S_00a818b0_Bin**)(pObj + 0x250), (char*)this + 0x58, 2);
    S_BinRead(*(S_00a818b0_Bin**)(pObj + 0x250), (char*)this + 0x5a, 2);
}

extern void* g_011f5af4;
void* __cdecl NiViewerStrings_NiGetViewerString_Title(void* p);
void* __cdecl NiGetViewerString_00a7d490(const char* name, unsigned int value);

struct NiArr
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short m_0c;
    unsigned short m_0e;
    void FUN_0096ad30(unsigned int n);
    void FUN_0096ae90(unsigned int idx, void** out);
    void Add(void* x)
    {
        unsigned int i = m_0a;
        if (i >= m_08)
            FUN_0096ad30(i + m_0e);
        FUN_0096ae90(i, &x);
    }
    void AddR(void*& x)
    {
        unsigned int i = m_0a;
        if (i >= m_08)
            FUN_0096ad30(i + m_0e);
        FUN_0096ae90(i, &x);
    }
};

struct FUN_00a81910_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4c;
    unsigned int m_50;
    unsigned int m_54;
    unsigned short m_58;
    unsigned short m_5a;
    void AppendTriListInfo(NiArr* a);
    void AddActiveCounts(NiArr* a);
};

// Calls AppendTriListInfo, then appends the result of FUN_00a7d330(g_011f5af4) and two named values m_usActiveVertices and m_usActiveTriangles to the array.
// @fnv 0x00a81910
void FUN_00a81910_cls::AddActiveCounts(NiArr* a)
{
    AppendTriListInfo(a);
    a->Add(NiViewerStrings_NiGetViewerString_Title(g_011f5af4));
    a->Add(NiGetViewerString_00a7d490("m_usActiveVertices", m_58));
    a->Add(NiGetViewerString_00a7d490("m_usActiveTriangles", m_5a));
}

struct FUN_00a81710_cls
{
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
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned short m_58;
    unsigned short NiTriShapeDynamicData_GetActiveVertexCount();
};
// @fnv 0x00a81710
// src: XBOX_PDB 0x00a81710
unsigned short FUN_00a81710_cls::NiTriShapeDynamicData_GetActiveVertexCount()
{
    return m_58;
}

struct A81720Owner
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
    unsigned short unk58;
    unsigned short unk5a;
    unsigned short NiTriShapeDynamicData_GetActiveTriangleCount();
};

// @fnv 0x00a81720
// src: XBOX_PDB 0x00a81720
unsigned short A81720Owner::NiTriShapeDynamicData_GetActiveTriangleCount()
{
    return unk5a;
}

struct Reader
{
    unsigned int unk00;
    unsigned int m_uiBytesRead;
    int(__cdecl* m_pfnRead)(Reader*, void*, unsigned int, unsigned int*, unsigned int);
    int Read(void* p, unsigned int bytes, unsigned int* sz, unsigned int n)
    {
        return m_pfnRead(this, p, bytes, sz, n);
    }
};
struct Stream
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    Reader* m_pReader;
};
struct Dynamic
{
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
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    bool FUN_00a7b940(Stream*);
    void NiTriShapeDynamicData_LoadBinary(Stream*);
};
static __forceinline void ReadBytes(Reader* bin, void* v, unsigned int bytes)
{
    unsigned int size = 2;
    bin->m_uiBytesRead += bin->Read(v, bytes, &size, 1);
}
// @fnv 0x00a81850
// src: XBOX_PDB 0x00a81850
void Dynamic::NiTriShapeDynamicData_LoadBinary(Stream* pStream)
{
    Stream* s = pStream;
    FUN_00a7b940(s);
    ReadBytes(s->m_pReader, &m_usActiveVertices, 2);
    ReadBytes(s->m_pReader, &m_usActiveTriangles, 2);
}
