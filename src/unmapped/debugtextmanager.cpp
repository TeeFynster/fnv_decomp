
// src/unmapped/debugtextmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/debug/debugtextmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/NiFixedString.h"
#include "../../include/FontManager.h"

extern "C" void __cdecl DebugTextManager_CreateSingleton();
extern "C" int DAT_011db800;

// @fnv 0x005ba8d0
// src: COMMUNITY 0x005ba8d0
int __cdecl DebugTextManager_GetSingleton()
{
    if (!DAT_011db800)
        DebugTextManager_CreateSingleton();
    return DAT_011db800;
}

struct FUN_00802a00_class
{
    int __thiscall GetZero(int a, int b);
};

// @fnv 0x00802a00
int __thiscall FUN_00802a00_class::GetZero(int a, int b)
{
    int result = 0;
    return result;
}

extern "C" int __cdecl __mbsnicmp(const unsigned char*, const unsigned char*, unsigned int);
struct FUN_00802a20_class
{
    int m_uiPageCount;
    unsigned char m_aucPageBuffer[4352];
    int __thiscall DebugTextManager_FindPageIndex(const char* apPage);
};
// Searches the page table for a case-insensitive name match and returns its index, or -1 if not found.
// @fnv 0x00802a20
// src: COMMUNITY 0x00802a20
int FUN_00802a20_class::DebugTextManager_FindPageIndex(const char* apPage)
{
    int i;
    int iPageIndex;
    iPageIndex = -1;
    i = 0;
    for (; i < *(int*)((char*)this + 0x14) && iPageIndex == -1; i++)
    {
        if (__mbsnicmp((const unsigned char*)apPage, (const unsigned char*)((char*)this + 0x20) + i * 0x44, 0x40) == 0)
            iPageIndex = i;
    }
    return iPageIndex;
}

struct FUN_00802860_class
{
    int __thiscall ResetField();
};

// @fnv 0x00802860
int __thiscall FUN_00802860_class::ResetField()
{
    *(int*)((char*)this + 0x40) = 0;
    return (int)this;
}

// Stand-in for the page registry object passed to FUN_00802220.
struct PageTable
{
    void SetEntryStateByKey(int index, int value);
};

// Stand-in for the class that owns FUN_00802220 (this pointer is unused by it).

// @fnv 0x00802220
// src: COMMUNITY 0x00802220
void FontManager::VATSEffect_SetBodyPartEnabled(PageTable* pPages, int index, unsigned char value)
{
    pPages->SetEntryStateByKey((unsigned short)index, value);
    pPages->SetEntryStateByKey(index * 1000, value);
}

struct FUN_00450f90_cls
{
    void __thiscall FUN_00450f90(bool b);
};

struct FUN_0043f220_cls
{
    int unk00;
    int unk04;
    FUN_00450f90_cls* unk08;
    FUN_0043f220_cls* __thiscall GetEntryAt(int b);
};

struct FUN_00802260_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual FUN_0043f220_cls* v7a();
    void __thiscall FOVATSEffectManager_ShowBipedObjectOnActor(FUN_00802260_cls* a1, int a2, unsigned char a3);
};

// @fnv 0x00802260
// src: COMMUNITY 0x00802260
void __thiscall FUN_00802260_cls::FOVATSEffectManager_ShowBipedObjectOnActor(FUN_00802260_cls* a1, int a2, unsigned char abFlag)
{
    FUN_0043f220_cls* p = a1->v7a();
    if (p != 0)
    {
        FUN_00450f90_cls* q = p->GetEntryAt(a2)->unk08;
        if (q != 0)
        {
            q->FUN_00450f90(abFlag == 0);
        }
    }
}

struct QueryStub
{
    unsigned char BSOcclusionQuery_GetResult(unsigned int* out, int a);
};
struct Obj : QueryStub
{
    ~Obj();
};
struct Owner
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
    char unk118;
    bool flags[15];
    char unk128;
    char unk129;
    short unk12A;
    Obj* objsA[15];
    int unk168;
    Obj* objsB[15];
    void VATSEffect_FreeOcclusionQueries();
};

// @fnv 0x008026b0
// src: COMMUNITY 0x008026b0
void Owner::VATSEffect_FreeOcclusionQueries()
{
    for (unsigned int i = 0; i < 15; i++)
    {
        flags[i] = false;
        unsigned int val = 0;
        if (objsA[i])
        {
            objsA[i]->BSOcclusionQuery_GetResult(&val, 1);
            delete objsA[i];
            objsA[i] = 0;
        }
        if (objsB[i])
        {
            objsB[i]->BSOcclusionQuery_GetResult(&val, 1);
            delete objsB[i];
            objsB[i] = 0;
        }
    }
}

class C8027D0Map
{
  public:
    C8027D0Map(int iHashSize);
    ~C8027D0Map();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class C8027D0Slot
{
  public:
    C8027D0Slot();

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
};

class FUN_008027d0
{
  public:
    FUN_008027d0();

    int m_iSlotCount;
    C8027D0Map m_kFormatEntries;
    int m_iArrayLength;
    int m_iFirst;
    int m_iLast;
    C8027D0Slot m_akSlots[64];
};

// @fnv 0x008027d0
FUN_008027d0::FUN_008027d0() : m_iSlotCount(1), m_kFormatEntries(37), m_iArrayLength(0), m_iFirst(0), m_iLast(0)
{}

struct FUN_008029c0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    bool __thiscall DebugTextManager_SetScreenDebugPage(const char* apPage, int value);
};

// @fnv 0x008029c0
// src: COMMUNITY 0x008029c0
bool FUN_008029c0_class::DebugTextManager_SetScreenDebugPage(const char* apPage, int value)
{
    int result = reinterpret_cast<FUN_00802a20_class*>(this)->DebugTextManager_FindPageIndex(apPage);

    if (result != -1)
    {
        unk18 = result;
        unk1c = value;
    }

    return result != -1;
}

extern int DAT_011f49d8;

struct NiObj;
struct ListObj;
struct GeomObj;

struct NiObj
{
    virtual void tv00();
    virtual void tv01();
    virtual void tv02();
    virtual ListObj* tv03();
    virtual void tv04();
    virtual void tv05();
    virtual GeomObj* tv06();
    void __thiscall FUN_00450f90(bool b);
};

struct GeomObj
{
    NiObj* __thiscall NiGeometry_GetSkinInstance();
};

struct ListObj
{
    virtual void tv00();
    virtual void tv01();
    virtual void tv02();
    virtual void tv03();
    virtual void tv04();
    virtual void tv05();
    virtual void tv06();
    virtual void tv07();
    virtual void tv08();
    virtual void tv09();
    virtual void tv10();
    virtual void tv11();
    virtual void tv12();
    virtual void tv13();
    virtual void tv14();
    virtual void tv15();
    virtual void tv16();
    virtual void tv17();
    virtual void tv18();
    virtual void tv19();
    virtual void tv20();
    virtual void tv21();
    virtual void tv22();
    virtual void tv23();
    virtual void tv24();
    virtual void tv25();
    virtual void tv26();
    virtual void tv27();
    virtual void tv28();
    virtual void tv29();
    virtual void tv30();
    virtual void tv31();
    virtual void tv32();
    virtual void tv33();
    virtual void tv34();
    virtual void tv35();
    virtual void tv36();
    virtual void tv37();
    virtual void tv38();
    virtual NiObj* tv39(const NiFixedString& fs);
    unsigned int __thiscall FUN_0043b480();
    NiObj* __thiscall FUN_0043b4a0(unsigned int idx);
};

struct SkyObj;
struct BGSProj
{
    virtual void tv00();
    virtual void tv01();
    virtual void tv02();
    virtual void tv03();
    virtual void tv04();
    virtual void tv05();
    virtual void tv06();
    virtual void tv07();
    virtual void tv08();
    virtual void tv09();
    virtual void tv10();
    virtual void tv11();
    virtual void tv12();
    virtual void tv13();
    virtual void tv14();
    virtual void tv15();
    virtual void tv16();
    virtual void tv17();
    virtual void tv18();
    virtual void tv19();
    virtual void tv20();
    virtual void tv21();
    virtual void tv22();
    virtual void tv23();
    virtual void tv24();
    virtual void tv25();
    virtual void tv26();
    virtual void tv27();
    virtual void tv28();
    virtual void tv29();
    virtual void tv30();
    virtual void tv31();
    virtual void tv32();
    virtual void tv33();
    virtual void tv34();
    virtual void tv35();
    virtual void tv36();
    virtual void tv37();
    virtual void tv38();
    virtual void tv39();
    virtual void tv40();
    virtual void tv41();
    virtual void tv42();
    virtual void tv43();
    virtual void tv44();
    virtual void tv45();
    virtual void tv46();
    virtual void tv47();
    virtual void tv48();
    virtual void tv49();
    virtual void tv50();
    virtual void tv51();
    virtual void tv52();
    virtual void tv53();
    virtual void tv54();
    virtual void tv55();
    virtual void tv56();
    virtual void tv57();
    virtual void tv58();
    virtual void tv59();
    virtual void tv60();
    virtual void tv61();
    virtual void tv62();
    virtual void tv63();
    virtual void tv64();
    virtual void tv65();
    virtual void tv66();
    virtual void tv67();
    virtual void tv68();
    virtual void tv69();
    virtual void tv70();
    virtual void tv71();
    virtual void tv72();
    virtual void tv73();
    virtual void tv74();
    virtual void tv75();
    virtual void tv76();
    virtual void tv77();
    virtual void tv78();
    virtual void tv79();
    virtual void tv80();
    virtual void tv81();
    virtual void tv82();
    virtual void tv83();
    virtual void tv84();
    virtual void tv85();
    virtual void tv86();
    virtual void tv87();
    virtual void tv88();
    virtual void tv89();
    virtual void tv90();
    virtual void tv91();
    virtual void tv92();
    virtual void tv93();
    virtual void tv94();
    virtual void tv95();
    virtual SkyObj* tv96();
};

struct Sky2
{
    const char* __thiscall SkyObject_GetNiNode();
};
struct SkyObj
{
    Sky2* __thiscall GetValueByIndex(int a);
};

struct NodeObj
{
    virtual void tv00();
    virtual void tv01();
    virtual void tv02();
    virtual void tv03();
    virtual void tv04();
    virtual void tv05();
    virtual void tv06();
    virtual void tv07();
    virtual void tv08();
    virtual void tv09();
    virtual void tv10();
    virtual void tv11();
    virtual void tv12();
    virtual void tv13();
    virtual void tv14();
    virtual void tv15();
    virtual void tv16();
    virtual void tv17();
    virtual void tv18();
    virtual void tv19();
    virtual void tv20();
    virtual void tv21();
    virtual void tv22();
    virtual void tv23();
    virtual void tv24();
    virtual void tv25();
    virtual void tv26();
    virtual void tv27();
    virtual void tv28();
    virtual void tv29();
    virtual void tv30();
    virtual void tv31();
    virtual void tv32();
    virtual void tv33();
    virtual void tv34();
    virtual void tv35();
    virtual void tv36();
    virtual void tv37();
    virtual void tv38();
    virtual void tv39();
    virtual void tv40();
    virtual void tv41();
    virtual void tv42();
    virtual void tv43();
    virtual void tv44();
    virtual void tv45();
    virtual void tv46();
    virtual void tv47();
    virtual void tv48();
    virtual void tv49();
    virtual void tv50();
    virtual void tv51();
    virtual void tv52();
    virtual void tv53();
    virtual void tv54();
    virtual void tv55();
    virtual void tv56();
    virtual void tv57();
    virtual void tv58();
    virtual void tv59();
    virtual void tv60();
    virtual void tv61();
    virtual void tv62();
    virtual void tv63();
    virtual unsigned char tv64();
    virtual void tv65();
    virtual void tv66();
    virtual void tv67();
    virtual void tv68();
    virtual void tv69();
    virtual void tv70();
    virtual void tv71();
    virtual void tv72();
    virtual void tv73();
    virtual void tv74();
    virtual void tv75();
    virtual void tv76();
    virtual void tv77();
    virtual void tv78();
    virtual void tv79();
    virtual void tv80();
    virtual void tv81();
    virtual void tv82();
    virtual void tv83();
    virtual void tv84();
    virtual void tv85();
    virtual void tv86();
    virtual void tv87();
    virtual void tv88();
    virtual void tv89();
    virtual void tv90();
    virtual void tv91();
    virtual void tv92();
    virtual void tv93();
    virtual void tv94();
    virtual void tv95();
    virtual void tv96();
    virtual void tv97();
    virtual void tv98();
    virtual void tv99();
    virtual void tv100();
    virtual void tv101();
    virtual void tv102();
    virtual void tv103();
    virtual void tv104();
    virtual void tv105();
    virtual void tv106();
    virtual void tv107();
    virtual void tv108();
    virtual void tv109();
    virtual void tv110();
    virtual void tv111();
    virtual void tv112();
    virtual void tv113();
    virtual void tv114();
    virtual void tv115();
    virtual ListObj* tv116();
    BGSProj* __thiscall FUN_004181e0();
};

struct MgrObj
{
    void __thiscall SetEntryStateByKey(int index, int value);
};

bool __cdecl Animation_FindSkinnedNode(NiObj* o);
NiObj* __cdecl NiObject_DynamicCast(void* rtti, NiObj* o);

struct This8022
{
    int m_000;
    NodeObj* m_004;
    int m_008;
    int m_00c;
    int m_010;
    int m_014;
    int m_018;
    int m_01c;
    int m_020;
    int m_024;
    int m_028;
    int m_02c;
    int m_030;
    int m_034;
    int m_038;
    int m_03c;
    int m_040;
    int m_044;
    int m_048;
    int m_04c;
    int m_050;
    int m_054;
    int m_058;
    int m_05c;
    int m_060;
    int m_064;
    int m_068;
    int m_06c;
    int m_070;
    int m_074;
    int m_078;
    int m_07c;
    int m_080;
    int m_084;
    int m_088;
    int m_08c;
    int m_090;
    int m_094;
    int m_098;
    int m_09c;
    int m_0a0;
    int m_0a4;
    int m_0a8;
    int m_0ac;
    int m_0b0;
    int m_0b4;
    int m_0b8;
    int m_0bc;
    int m_0c0;
    int m_0c4;
    int m_0c8;
    int m_0cc;
    int m_0d0;
    int m_0d4;
    int m_0d8;
    int m_0dc;
    int m_0e0;
    int m_0e4;
    int m_0e8;
    int m_0ec;
    int m_0f0;
    int m_0f4;
    int m_0f8;
    int m_0fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    int m_198;
    int m_19c;
    int m_1a0;
    int m_1a4;
    int m_1a8;
    int m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    int m_1d0;
    int m_1d4;
    int m_1d8;
    int m_1dc;
    int m_1e0;
    int m_1e4;
    int m_1e8;
    int m_1ec;
    int m_1f0;
    int m_1f4;
    int m_1f8;
    int m_1fc;
    int m_200;
    int m_204;
    int m_208;
    int m_20c;
    int m_210;
    int m_214;
    int m_218;
    int m_21c;
    int m_220;
    int m_224;
    int m_228;
    int m_22c;
    int m_230;
    int m_234;
    int m_238;
    int m_23c;
    void __thiscall FOVATSEffectManager_ShowBipedObjectOnActor(NodeObj* a1, int a2, unsigned char a3);
    void __thiscall FOVATSEffectManager_RestoreBodyParts();
};

// @fnv 0x008022c0
// src: COMMUNITY 0x008022c0
void __thiscall This8022::FOVATSEffectManager_RestoreBodyParts()
{
    if (!m_004->tv64())
        return;
    if (m_23c == 0xe || m_23c == 0xf)
        return;
    NodeObj* res = m_004;
    FOVATSEffectManager_ShowBipedObjectOnActor(res, 3, 1);
    FOVATSEffectManager_ShowBipedObjectOnActor(res, 4, 1);
    FOVATSEffectManager_ShowBipedObjectOnActor(res, 0xa, 1);
    FOVATSEffectManager_ShowBipedObjectOnActor(res, 0xb, 1);
    FOVATSEffectManager_ShowBipedObjectOnActor(res, 0xc, 1);
    FOVATSEffectManager_ShowBipedObjectOnActor(res, 0xd, 1);
    FOVATSEffectManager_ShowBipedObjectOnActor(res, 9, 1);
    FOVATSEffectManager_ShowBipedObjectOnActor(res, 0xe, 1);
    FOVATSEffectManager_ShowBipedObjectOnActor(res, 0xf, 1);
    FOVATSEffectManager_ShowBipedObjectOnActor(res, 0x10, 1);
    FOVATSEffectManager_ShowBipedObjectOnActor(res, 1, 1);
    FOVATSEffectManager_ShowBipedObjectOnActor(res, 0, 1);
    int list1;
    list1 = m_23c;
    ListObj* kIter = m_004->tv116();
    {
        unsigned long r2;
        for (r2 = 0; r2 < kIter->FUN_0043b480(); r2++)
        {
            NiObj* p60 = kIter->FUN_0043b4a0(r2);
            if (p60 != 0)
            {
                if (Animation_FindSkinnedNode(p60))
                {
                    ListObj* r1;
                    r1 = p60->tv03();
                    GeomObj* x30 = p60->tv06();
                    unsigned int i;
                    i = 0;
                    while (x30 != 0 || (r1 != 0 && i < r1->FUN_0043b480()))
                    {
                        if (r1 != 0)
                        {
                            x30 = r1->FUN_0043b4a0(i) ? ((NiObj*)r1->FUN_0043b4a0(i))->tv06() : 0;
                            i++;
                        }
                        NiObj* mgr = x30 ? x30->NiGeometry_GetSkinInstance() : 0;
                        MgrObj* f23;
                        f23 = (MgrObj*)NiObject_DynamicCast(&DAT_011f49d8, mgr);
                        if (f23 != 0)
                        {
                            int ptr;
                            for (ptr = 0; 15 > ptr; ptr++)
                            {
                                f23->SetEntryStateByKey((unsigned short)ptr, 1);
                                f23->SetEntryStateByKey(ptr * 1000, 1);
                                f23->SetEntryStateByKey(ptr + 100, 0);
                                f23->SetEntryStateByKey(ptr + 200, 0);
                            }
                        }
                        x30 = 0;
                    }
                }
                else
                {
                    p60->FUN_00450f90(false);
                }
            }
        }
    }
    if (0 != res && m_23c == 0)
    {
        int j;
        for (j = 0; j < 15; j++)
        {
            SkyObj* tmp64 = res->FUN_004181e0()->tv96();
            Sky2* p = tmp64->GetValueByIndex(m_23c);
            if (p != 0)
            {
                NiObj* val = res->tv116()->tv39(NiFixedString(p->SkyObject_GetNiNode()));
                if (0 != val)
                {
                    val->FUN_00450f90(false);
                }
            }
        }
    }
}

void FUN_00ec61c0(void*, int, unsigned int);
struct RegisteredPage
{
    char name[68];
};
struct PageReporter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int count;
    int unk18;
    int unk1c;
    RegisteredPage pages[64];
    void DebugTextManager_OutputDebugPageNames(void(__cdecl*)(const char*));
};
void FUN_00406d50(char*, unsigned int, const char*);
// Builds a comma-separated string of up to five page names per batch and passes each batch to the report callback.
// @fnv 0x00802880
// src: COMMUNITY 0x00802880
void PageReporter::DebugTextManager_OutputDebugPageNames(void(__cdecl* report)(const char*))
{
    char buffer[512];
    buffer[0] = 0;
    FUN_00ec61c0(buffer + 1, 0, 511);
    for (int page = 0; page < count; page += 5)
    {
        buffer[0] = 0;
        for (int item = 0; item < 5 && item + page < count; item++)
        {
            FUN_00406d50(buffer, 512, pages[page + item].name);
            if (page + item + 1 < count)
                FUN_00406d50(buffer, 512, ", ");
        }
        report(buffer);
    }
}

class Manager802
{
  public:
    Manager802();
    virtual ~Manager802();

    static void DebugTextManager_CreateSingleton();

    int unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C, unk0020;
    int unk0024, unk0028, unk002C, unk0030, unk0034, unk0038, unk003C, unk0040;
    int unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C, unk0060;
    int unk0064, unk0068, unk006C, unk0070, unk0074, unk0078, unk007C, unk0080;
    int unk0084, unk0088, unk008C, unk0090, unk0094, unk0098, unk009C, unk00A0;
    int unk00A4, unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC, unk00C0;
    int unk00C4, unk00C8, unk00CC, unk00D0, unk00D4, unk00D8, unk00DC, unk00E0;
    int unk00E4, unk00E8, unk00EC, unk00F0, unk00F4, unk00F8, unk00FC, unk0100;
    int unk0104, unk0108, unk010C, unk0110, unk0114, unk0118, unk011C, unk0120;
    int unk0124, unk0128, unk012C, unk0130, unk0134, unk0138, unk013C, unk0140;
    int unk0144, unk0148, unk014C, unk0150, unk0154, unk0158, unk015C, unk0160;
    int unk0164, unk0168, unk016C, unk0170, unk0174, unk0178, unk017C, unk0180;
    int unk0184, unk0188, unk018C, unk0190, unk0194, unk0198, unk019C, unk01A0;
    int unk01A4, unk01A8, unk01AC, unk01B0, unk01B4, unk01B8, unk01BC, unk01C0;
    int unk01C4, unk01C8, unk01CC, unk01D0, unk01D4, unk01D8, unk01DC, unk01E0;
    int unk01E4, unk01E8, unk01EC, unk01F0, unk01F4, unk01F8, unk01FC, unk0200;
    int unk0204, unk0208, unk020C, unk0210, unk0214, unk0218, unk021C, unk0220;
    int unk0224, unk0228, unk022C, unk0230, unk0234, unk0238, unk023C, unk0240;
    int unk0244, unk0248, unk024C, unk0250, unk0254, unk0258, unk025C, unk0260;
    int unk0264, unk0268, unk026C, unk0270, unk0274, unk0278, unk027C, unk0280;
    int unk0284, unk0288, unk028C, unk0290, unk0294, unk0298, unk029C, unk02A0;
    int unk02A4, unk02A8, unk02AC, unk02B0, unk02B4, unk02B8, unk02BC, unk02C0;
    int unk02C4, unk02C8, unk02CC, unk02D0, unk02D4, unk02D8, unk02DC, unk02E0;
    int unk02E4, unk02E8, unk02EC, unk02F0, unk02F4, unk02F8, unk02FC, unk0300;
    int unk0304, unk0308, unk030C, unk0310, unk0314, unk0318, unk031C, unk0320;
    int unk0324, unk0328, unk032C, unk0330, unk0334, unk0338, unk033C, unk0340;
    int unk0344, unk0348, unk034C, unk0350, unk0354, unk0358, unk035C, unk0360;
    int unk0364, unk0368, unk036C, unk0370, unk0374, unk0378, unk037C, unk0380;
    int unk0384, unk0388, unk038C, unk0390, unk0394, unk0398, unk039C, unk03A0;
    int unk03A4, unk03A8, unk03AC, unk03B0, unk03B4, unk03B8, unk03BC, unk03C0;
    int unk03C4, unk03C8, unk03CC, unk03D0, unk03D4, unk03D8, unk03DC, unk03E0;
    int unk03E4, unk03E8, unk03EC, unk03F0, unk03F4, unk03F8, unk03FC, unk0400;
    int unk0404, unk0408, unk040C, unk0410, unk0414, unk0418, unk041C, unk0420;
    int unk0424, unk0428, unk042C, unk0430, unk0434, unk0438, unk043C, unk0440;
    int unk0444, unk0448, unk044C, unk0450, unk0454, unk0458, unk045C, unk0460;
    int unk0464, unk0468, unk046C, unk0470, unk0474, unk0478, unk047C, unk0480;
    int unk0484, unk0488, unk048C, unk0490, unk0494, unk0498, unk049C, unk04A0;
    int unk04A4, unk04A8, unk04AC, unk04B0, unk04B4, unk04B8, unk04BC, unk04C0;
    int unk04C4, unk04C8, unk04CC, unk04D0, unk04D4, unk04D8, unk04DC, unk04E0;
    int unk04E4, unk04E8, unk04EC, unk04F0, unk04F4, unk04F8, unk04FC, unk0500;
    int unk0504, unk0508, unk050C, unk0510, unk0514, unk0518, unk051C, unk0520;
    int unk0524, unk0528, unk052C, unk0530, unk0534, unk0538, unk053C, unk0540;
    int unk0544, unk0548, unk054C, unk0550, unk0554, unk0558, unk055C, unk0560;
    int unk0564, unk0568, unk056C, unk0570, unk0574, unk0578, unk057C, unk0580;
    int unk0584, unk0588, unk058C, unk0590, unk0594, unk0598, unk059C, unk05A0;
    int unk05A4, unk05A8, unk05AC, unk05B0, unk05B4, unk05B8, unk05BC, unk05C0;
    int unk05C4, unk05C8, unk05CC, unk05D0, unk05D4, unk05D8, unk05DC, unk05E0;
    int unk05E4, unk05E8, unk05EC, unk05F0, unk05F4, unk05F8, unk05FC, unk0600;
    int unk0604, unk0608, unk060C, unk0610, unk0614, unk0618, unk061C, unk0620;
    int unk0624, unk0628, unk062C, unk0630, unk0634, unk0638, unk063C, unk0640;
    int unk0644, unk0648, unk064C, unk0650, unk0654, unk0658, unk065C, unk0660;
    int unk0664, unk0668, unk066C, unk0670, unk0674, unk0678, unk067C, unk0680;
    int unk0684, unk0688, unk068C, unk0690, unk0694, unk0698, unk069C, unk06A0;
    int unk06A4, unk06A8, unk06AC, unk06B0, unk06B4, unk06B8, unk06BC, unk06C0;
    int unk06C4, unk06C8, unk06CC, unk06D0, unk06D4, unk06D8, unk06DC, unk06E0;
    int unk06E4, unk06E8, unk06EC, unk06F0, unk06F4, unk06F8, unk06FC, unk0700;
    int unk0704, unk0708, unk070C, unk0710, unk0714, unk0718, unk071C, unk0720;
    int unk0724, unk0728, unk072C, unk0730, unk0734, unk0738, unk073C, unk0740;
    int unk0744, unk0748, unk074C, unk0750, unk0754, unk0758, unk075C, unk0760;
    int unk0764, unk0768, unk076C, unk0770, unk0774, unk0778, unk077C, unk0780;
    int unk0784, unk0788, unk078C, unk0790, unk0794, unk0798, unk079C, unk07A0;
    int unk07A4, unk07A8, unk07AC, unk07B0, unk07B4, unk07B8, unk07BC, unk07C0;
    int unk07C4, unk07C8, unk07CC, unk07D0, unk07D4, unk07D8, unk07DC, unk07E0;
    int unk07E4, unk07E8, unk07EC, unk07F0, unk07F4, unk07F8, unk07FC, unk0800;
    int unk0804, unk0808, unk080C, unk0810, unk0814, unk0818, unk081C, unk0820;
    int unk0824, unk0828, unk082C, unk0830, unk0834, unk0838, unk083C, unk0840;
    int unk0844, unk0848, unk084C, unk0850, unk0854, unk0858, unk085C, unk0860;
    int unk0864, unk0868, unk086C, unk0870, unk0874, unk0878, unk087C, unk0880;
    int unk0884, unk0888, unk088C, unk0890, unk0894, unk0898, unk089C, unk08A0;
    int unk08A4, unk08A8, unk08AC, unk08B0, unk08B4, unk08B8, unk08BC, unk08C0;
    int unk08C4, unk08C8, unk08CC, unk08D0, unk08D4, unk08D8, unk08DC, unk08E0;
    int unk08E4, unk08E8, unk08EC, unk08F0, unk08F4, unk08F8, unk08FC, unk0900;
    int unk0904, unk0908, unk090C, unk0910, unk0914, unk0918, unk091C, unk0920;
    int unk0924, unk0928, unk092C, unk0930, unk0934, unk0938, unk093C, unk0940;
    int unk0944, unk0948, unk094C, unk0950, unk0954, unk0958, unk095C, unk0960;
    int unk0964, unk0968, unk096C, unk0970, unk0974, unk0978, unk097C, unk0980;
    int unk0984, unk0988, unk098C, unk0990, unk0994, unk0998, unk099C, unk09A0;
    int unk09A4, unk09A8, unk09AC, unk09B0, unk09B4, unk09B8, unk09BC, unk09C0;
    int unk09C4, unk09C8, unk09CC, unk09D0, unk09D4, unk09D8, unk09DC, unk09E0;
    int unk09E4, unk09E8, unk09EC, unk09F0, unk09F4, unk09F8, unk09FC, unk0A00;
    int unk0A04, unk0A08, unk0A0C, unk0A10, unk0A14, unk0A18, unk0A1C, unk0A20;
    int unk0A24, unk0A28, unk0A2C, unk0A30, unk0A34, unk0A38, unk0A3C, unk0A40;
    int unk0A44, unk0A48, unk0A4C, unk0A50, unk0A54, unk0A58, unk0A5C, unk0A60;
    int unk0A64, unk0A68, unk0A6C, unk0A70, unk0A74, unk0A78, unk0A7C, unk0A80;
    int unk0A84, unk0A88, unk0A8C, unk0A90, unk0A94, unk0A98, unk0A9C, unk0AA0;
    int unk0AA4, unk0AA8, unk0AAC, unk0AB0, unk0AB4, unk0AB8, unk0ABC, unk0AC0;
    int unk0AC4, unk0AC8, unk0ACC, unk0AD0, unk0AD4, unk0AD8, unk0ADC, unk0AE0;
    int unk0AE4, unk0AE8, unk0AEC, unk0AF0, unk0AF4, unk0AF8, unk0AFC, unk0B00;
    int unk0B04, unk0B08, unk0B0C, unk0B10, unk0B14, unk0B18, unk0B1C, unk0B20;
    int unk0B24, unk0B28, unk0B2C, unk0B30, unk0B34, unk0B38, unk0B3C, unk0B40;
    int unk0B44, unk0B48, unk0B4C, unk0B50, unk0B54, unk0B58, unk0B5C, unk0B60;
    int unk0B64, unk0B68, unk0B6C, unk0B70, unk0B74, unk0B78, unk0B7C, unk0B80;
    int unk0B84, unk0B88, unk0B8C, unk0B90, unk0B94, unk0B98, unk0B9C, unk0BA0;
    int unk0BA4, unk0BA8, unk0BAC, unk0BB0, unk0BB4, unk0BB8, unk0BBC, unk0BC0;
    int unk0BC4, unk0BC8, unk0BCC, unk0BD0, unk0BD4, unk0BD8, unk0BDC, unk0BE0;
    int unk0BE4, unk0BE8, unk0BEC, unk0BF0, unk0BF4, unk0BF8, unk0BFC, unk0C00;
    int unk0C04, unk0C08, unk0C0C, unk0C10, unk0C14, unk0C18, unk0C1C, unk0C20;
    int unk0C24, unk0C28, unk0C2C, unk0C30, unk0C34, unk0C38, unk0C3C, unk0C40;
    int unk0C44, unk0C48, unk0C4C, unk0C50, unk0C54, unk0C58, unk0C5C, unk0C60;
    int unk0C64, unk0C68, unk0C6C, unk0C70, unk0C74, unk0C78, unk0C7C, unk0C80;
    int unk0C84, unk0C88, unk0C8C, unk0C90, unk0C94, unk0C98, unk0C9C, unk0CA0;
    int unk0CA4, unk0CA8, unk0CAC, unk0CB0, unk0CB4, unk0CB8, unk0CBC, unk0CC0;
    int unk0CC4, unk0CC8, unk0CCC, unk0CD0, unk0CD4, unk0CD8, unk0CDC, unk0CE0;
    int unk0CE4, unk0CE8, unk0CEC, unk0CF0, unk0CF4, unk0CF8, unk0CFC, unk0D00;
    int unk0D04, unk0D08, unk0D0C, unk0D10, unk0D14, unk0D18, unk0D1C, unk0D20;
    int unk0D24, unk0D28, unk0D2C, unk0D30, unk0D34, unk0D38, unk0D3C, unk0D40;
    int unk0D44, unk0D48, unk0D4C, unk0D50, unk0D54, unk0D58, unk0D5C, unk0D60;
    int unk0D64, unk0D68, unk0D6C, unk0D70, unk0D74, unk0D78, unk0D7C, unk0D80;
    int unk0D84, unk0D88, unk0D8C, unk0D90, unk0D94, unk0D98, unk0D9C, unk0DA0;
    int unk0DA4, unk0DA8, unk0DAC, unk0DB0, unk0DB4, unk0DB8, unk0DBC, unk0DC0;
    int unk0DC4, unk0DC8, unk0DCC, unk0DD0, unk0DD4, unk0DD8, unk0DDC, unk0DE0;
    int unk0DE4, unk0DE8, unk0DEC, unk0DF0, unk0DF4, unk0DF8, unk0DFC, unk0E00;
    int unk0E04, unk0E08, unk0E0C, unk0E10, unk0E14, unk0E18, unk0E1C, unk0E20;
    int unk0E24, unk0E28, unk0E2C, unk0E30, unk0E34, unk0E38, unk0E3C, unk0E40;
    int unk0E44, unk0E48, unk0E4C, unk0E50, unk0E54, unk0E58, unk0E5C, unk0E60;
    int unk0E64, unk0E68, unk0E6C, unk0E70, unk0E74, unk0E78, unk0E7C, unk0E80;
    int unk0E84, unk0E88, unk0E8C, unk0E90, unk0E94, unk0E98, unk0E9C, unk0EA0;
    int unk0EA4, unk0EA8, unk0EAC, unk0EB0, unk0EB4, unk0EB8, unk0EBC, unk0EC0;
    int unk0EC4, unk0EC8, unk0ECC, unk0ED0, unk0ED4, unk0ED8, unk0EDC, unk0EE0;
    int unk0EE4, unk0EE8, unk0EEC, unk0EF0, unk0EF4, unk0EF8, unk0EFC, unk0F00;
    int unk0F04, unk0F08, unk0F0C, unk0F10, unk0F14, unk0F18, unk0F1C, unk0F20;
    int unk0F24, unk0F28, unk0F2C, unk0F30, unk0F34, unk0F38, unk0F3C, unk0F40;
    int unk0F44, unk0F48, unk0F4C, unk0F50, unk0F54, unk0F58, unk0F5C, unk0F60;
    int unk0F64, unk0F68, unk0F6C, unk0F70, unk0F74, unk0F78, unk0F7C, unk0F80;
    int unk0F84, unk0F88, unk0F8C, unk0F90, unk0F94, unk0F98, unk0F9C, unk0FA0;
    int unk0FA4, unk0FA8, unk0FAC, unk0FB0, unk0FB4, unk0FB8, unk0FBC, unk0FC0;
    int unk0FC4, unk0FC8, unk0FCC, unk0FD0, unk0FD4, unk0FD8, unk0FDC, unk0FE0;
    int unk0FE4, unk0FE8, unk0FEC, unk0FF0, unk0FF4, unk0FF8, unk0FFC, unk1000;
    int unk1004, unk1008, unk100C, unk1010, unk1014, unk1018, unk101C, unk1020;
    int unk1024, unk1028, unk102C, unk1030, unk1034, unk1038, unk103C, unk1040;
    int unk1044, unk1048, unk104C, unk1050, unk1054, unk1058, unk105C, unk1060;
    int unk1064, unk1068, unk106C, unk1070, unk1074, unk1078, unk107C, unk1080;
    int unk1084, unk1088, unk108C, unk1090, unk1094, unk1098, unk109C, unk10A0;
    int unk10A4, unk10A8, unk10AC, unk10B0, unk10B4, unk10B8, unk10BC, unk10C0;
    int unk10C4, unk10C8, unk10CC, unk10D0, unk10D4, unk10D8, unk10DC, unk10E0;
    int unk10E4, unk10E8, unk10EC, unk10F0, unk10F4, unk10F8, unk10FC, unk1100;
    int unk1104, unk1108, unk110C, unk1110, unk1114, unk1118, unk111C;

    static Manager802* ms_pkInstance;
};

// Creates the singleton Manager802 instance if ms_pkInstance is null.
// @fnv 0x00802a90
// src: COMMUNITY 0x00802a90
void Manager802::DebugTextManager_CreateSingleton()
{
    if (!ms_pkInstance)
        ms_pkInstance = new Manager802;
}
