#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/Pair.h"

// src/havok/common/base/memory/system/freelist/hkfreelistmemorysystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/system/freelist/hkfreelistmemorysystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cd06c0_t
{
    void __thiscall hkFreeListMemorySystem_setAllocator(int v);
};
// @fnv 0x00cd06c0
// src: XBOX_PDB 0x00cd06c0
void __thiscall FUN_00cd06c0_t::hkFreeListMemorySystem_setAllocator(int v)
{
    *(int*)((char*)this + 4) = v;
    *(int*)((char*)this + 0x18) = v;
}

extern int DAT_010cacd0;

struct FUN_00cd06a0
{
    void* m_p00;
    FUN_00cd06a0(int aiArg);
    void hkThreadMemory_releaseCachedMemory();
    void UpdateFields_00cbf1a0();
};

// @fnv 0x00cd06a0
FUN_00cd06a0::FUN_00cd06a0(int aiArg)
{
    m_p00 = &DAT_010cacd0;
    hkThreadMemory_releaseCachedMemory();
    UpdateFields_00cbf1a0();
}

struct Inner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
};
struct Outer
{
    char pad[0x1c];
    Inner inner;
    void hkFreeListMemorySystem_garbageCollect();
};
// @fnv 0x00cd06e0
// src: HAVOK_LIB 0x00cd06e0
void Outer::hkFreeListMemorySystem_garbageCollect()
{
    inner.v16();
}

void __cdecl hkMemUtil_memSet(void*, int, unsigned int);
struct FUN_00cd0940_record
{
    virtual void slot00() = 0;
    virtual void slot01() = 0;
    virtual void slot02() = 0;
    virtual void slot03() = 0;
    virtual void slot04() = 0;
    virtual void slot05() = 0;
    virtual void slot06() = 0;
    virtual void slot07() = 0;
    virtual void slot08() = 0;
    virtual void slot09() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
};
struct FUN_00cd0940_iface
{
    virtual void slot00() = 0;
    virtual void slot01() = 0;
    virtual void slot02(int, int) = 0;
};
struct FUN_00cd0940_shell
{
    void __thiscall ResetRecordState(int* param, unsigned char mode);
};
// @fnv 0x00cd0940
void __thiscall FUN_00cd0940_shell::ResetRecordState(int* aiParams, unsigned char mode)
{
    FUN_00cd0940_record* record = (FUN_00cd0940_record*)((unsigned char*)this + aiParams[8] * 0x138 + 0xc6c);
    if ((mode & 2) != 0)
    {
        if (*(int*)((unsigned char*)record + 0x130) != 0)
        {
            int start = aiParams[1];
            int length = aiParams[2] - start;
            if (length != 0)
            {
                ((FUN_00cd0940_iface*)((unsigned char*)this + 0x1c))->slot02(start, length);
                aiParams[1] = 0;
                aiParams[0] = 0;
                aiParams[2] = 0;
            }
        }
        record->slot13();
        aiParams[3] = 0;
        aiParams[6] = 0;
    }
    if ((mode & 1) != 0)
    {
        record->slot13();
        *(volatile int*)((unsigned char*)record + 0x128) = 0;
        *(volatile unsigned char*)((unsigned char*)record + 0x12c) = 0;
        hkMemUtil_memSet(aiParams, 0, 0x24);
    }
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct PtrArrayMember
{
    void** m_ppData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~PtrArrayMember() throw()
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_debug);
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
        {
            // Preserve virtual slot 4; the shared header declares FreeArray as nonvirtual.
            typedef void (__thiscall *FreeArrayFn)(hkMemoryAllocator*, void*, unsigned int);
            ((FreeArrayFn*)*(void**)pAllocator)[4](pAllocator, m_ppData, (uCapacity & 0x3fffffff) * 4);
        }
        m_ppData = 0;
        m_uCapacity = 0x80000000;
    }
};

struct FUN_00cd0c80
{
    int unk00;
    PtrArrayMember m_kFirst;
    PtrArrayMember m_kSecond;

    ~FUN_00cd0c80() throw();
};

// Destructor stub for a structure holding two PtrArrayMember members; the members' destructors run after this body.
// @fnv 0x00cd0c80
FUN_00cd0c80::~FUN_00cd0c80() throw()
{}

struct CallTarget_00cd1d80
{
    int hkArrayBase__spliceInto(int, int, int, int, int);
};
struct SearchObject
{
    int Search(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00cd1e20
int SearchObject::Search(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int callResult0 =
        (unsigned int)((CallTarget_00cd1d80*)this)->hkArrayBase__spliceInto((int)arg0, (int)arg1, (int)0u, (int)arg2, (int)arg3);
    return (int)callResult0;
}

struct SpawnedSub
{
    int Compute();
};

struct FUN_00cd06f0_cls
{
    void AccumulateSpawnedSubTotals(int* out);
};

// Iterates 0x20 entries, adding each active entry's Compute() result and value into out[1] and out[0], then sets out[2] to 0.
// @fnv 0x00cd06f0
void FUN_00cd06f0_cls::AccumulateSpawnedSubTotals(int* out)
{
    char* elem = (char*)this + 0xd9c;
    int remaining = 0x20;
    do
    {
        if (*(elem - 4) != 0)
        {
            SpawnedSub* sub = (SpawnedSub*)(elem - 0x130);
            out[1] += sub->Compute();
            out[0] += *(int*)elem;
        }
        elem += 0x138;
        remaining--;
    } while (remaining != 0);
    out[2] = remaining;
}

struct CD0730Object
{
    virtual int hkFreeListMemorySystem_Func010(const void* info) const;
};

// @fnv 0x00cd0730
// src: COMMUNITY 0x00cd0730
int CD0730Object::hkFreeListMemorySystem_Func010(const void* info) const
{
    return 1;
}

extern const char str_01094d90[];

struct Gap040
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
};
struct Gap038
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
};
struct Gap400
{
    Gap040 g00;
    Gap040 g01;
    Gap040 g02;
    Gap040 g03;
    Gap040 g04;
    Gap040 g05;
    Gap040 g06;
    Gap040 g07;
    Gap040 g08;
    Gap040 g09;
    Gap040 g0a;
    Gap040 g0b;
    Gap040 g0c;
    Gap040 g0d;
    Gap040 g0e;
    Gap040 g0f;
};

struct Flags
{
    unsigned int bits;
};

struct Svc
{
    virtual void s0();
    virtual int s1(int a, int b);
};

struct Sub0b0c
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
};

struct FUN_00d5e960_t
{
    void __thiscall InitStream(int v);
};

struct Owner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(Sub0b0c* s, const char* g, unsigned int flags);
    Svc* svc;
    Gap400 ga;
    Gap400 gb;
    Gap040 gc00;
    Gap040 gc01;
    Gap040 gc02;
    Gap040 gc03;
    Gap040 gc04;
    Gap040 gc05;
    Gap040 gc06;
    Gap040 gc07;
    Gap040 gc08;
    Gap040 gc09;
    Gap040 gc0a;
    Gap038 gd;
    int f0b00;
    int f0b04;
    int unk0b08;
    Sub0b0c sub0b0c;
    FUN_00d5e960_t cnt0b30;
    Sub0b0c* hkFreeListMemorySystem_mainInit(const Pair* p, Flags flags);
};

// Stores p->a and p->b into f0b00/f0b04, optionally calls v3 on sub0b0c and svc->s1 then cnt0b30, and returns &sub0b0c.
// @fnv 0x00cd0740
// src: HAVOK_LIB 0x00cd0740
Sub0b0c* Owner::hkFreeListMemorySystem_mainInit(const Pair* apPair, Flags flags)
{
    f0b00 = apPair->a;
    f0b04 = apPair->b;
    if (flags.bits & 1)
    {
        v3(&sub0b0c, str_01094d90, flags.bits);
    }
    if (flags.bits & 2)
    {
        int b = apPair->b;
        if (b)
        {
            int r = svc->s1(b, b);
            cnt0b30.InitStream(r);
        }
    }
    return &sub0b0c;
}

extern "C" unsigned int DAT_012686cc;

struct S_00cd0a60_sub8
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void FUN_00d60500(int a1, int a2);
    __forceinline S_00cd0a60_sub8()
    {
        FUN_00d60500(0, 0);
    }
};

struct S_00cd0a60_sub1c
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
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    void hkFreeListAllocator_00d60270(S_00cd0a60_sub8* a1);
    __forceinline S_00cd0a60_sub1c(S_00cd0a60_sub8* a1)
    {
        hkFreeListAllocator_00d60270(a1);
    }
};

struct S_00cd0a60_VtBase
{
    virtual void v0();
    int unk04;
    __forceinline S_00cd0a60_VtBase()
    {}
};

struct S_00cd0a60_Arr
{
    int m_data;
    int m_iElementCount;
    unsigned int m_cap;
    int m_pTrailingData;
    __forceinline S_00cd0a60_Arr() : m_data(0), m_iElementCount(0), m_cap(0x80000000u), m_pTrailingData(0)
    {}
};

struct S_00cd0a60_Vt : S_00cd0a60_VtBase
{
    S_00cd0a60_Arr arr;
    __forceinline S_00cd0a60_Vt()
    {}
};

struct S_00cd0a60_sub0ad0
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
    void ProcessAndReturnValue_00cf6da0(int a1);
    __forceinline S_00cd0a60_sub0ad0()
    {
        ProcessAndReturnValue_00cf6da0(0);
    }
};

struct S_00cd0a60_sub0b00
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_00cbbfa0();
    __forceinline S_00cd0a60_sub0b00()
    {
        FUN_00cbbfa0();
    }
};

struct S_00cd0a60_sub0b0c
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
    void Clear();
    __forceinline S_00cd0a60_sub0b0c()
    {
        Clear();
    }
};

struct S_00cd0a60_sub0b30
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
    void FUN_00d5e900();
    __forceinline S_00cd0a60_sub0b30()
    {
        FUN_00d5e900();
    }
};

struct S_00cd0a60_elem
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
    char unk12c;
    int unk130;
    int unk134;
    void hkThreadMemory_hkThreadMemory();
};

struct S_00cd0a60_arr
{
    S_00cd0a60_elem e[32];
    __forceinline S_00cd0a60_arr()
    {
        S_00cd0a60_elem* p = e;
        for (int i = 31; i >= 0; --i)
        {
            p->hkThreadMemory_hkThreadMemory();
            p->unk128 = 0;
            p->unk12c = 0;
            p->unk130 = 0;
            ++p;
        }
    }
};

struct FUN_00cd0a60
{
    virtual void v0();
    int unk04;
    S_00cd0a60_sub8 m08;
    S_00cd0a60_sub1c m1c;
    S_00cd0a60_Vt vt;
    S_00cd0a60_sub0ad0 m0ad0;
    S_00cd0a60_sub0b00 m0b00;
    S_00cd0a60_sub0b0c m0b0c;
    S_00cd0a60_sub0b30 m0b30;
    S_00cd0a60_arr arr;
    S_00cd0a60_sub0ad0 m336c;
    FUN_00cd0a60();
};

// Initializes unk04 to 0, links m1c to m08, stores the address of m1c in DAT_012686cc and in m0b00.unk08.
// @fnv 0x00cd0a60
FUN_00cd0a60::FUN_00cd0a60() : unk04(0), m1c(&m08)
{
    unsigned int r = (unsigned int)&m1c;
    DAT_012686cc = r;
    m0b00.unk08 = r;
}

struct Helper
{
    void FUN_00cd09d0();
};

struct FUN_00cd0c70_cls
{
    int unk00;

    FUN_00cd0c70_cls* EvaluateValue_00cd0c70(int aiUnused);
};

// @fnv 0x00cd0c70
// src: GUESS 0x00cd0c70 (confidence: low)
FUN_00cd0c70_cls* FUN_00cd0c70_cls::EvaluateValue_00cd0c70(int aiUnused)
{
    ((Helper*)this)->FUN_00cd09d0();
    return this;
}

struct CD07B0_Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void FreeBytes(void* apMemory, unsigned int auiBytes);
};
struct CD07B0_Obj1c
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void Release();
};
struct CD07B0_Buffer
{
    int unk00;
    char* m_pBegin;
    char* m_pRecordEnd;
    unsigned int Size() const
    {
        return m_pRecordEnd - m_pBegin;
    }
    void InitStream(int a1, int a2);
};
struct FUN_00cd07b0_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Detach(Sub0b0c* apSub, Flags akFlags);
    CD07B0_Allocator* m_pAllocator;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    CD07B0_Obj1c m_kObj1c;
    Gap400 ga;
    Gap400 gb;
    Gap040 gc00;
    Gap040 gc01;
    Gap040 gc02;
    Gap040 gc03;
    Gap040 gc04;
    Gap040 gc05;
    Gap040 gc06;
    Gap040 gc07;
    Gap040 gc08;
    Gap040 gc09;
    Gap040 gc0a;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    Sub0b0c m_kSub;
    CD07B0_Buffer m_kBuffer;
    int Cleanup(Flags akFlags);
};

// Frees the buffer bytes and detaches the sub-object when the corresponding flag bits are set, then nulls the allocator pointer.
// @fnv 0x00cd07b0
int FUN_00cd07b0_cls::Cleanup(Flags akFlags)
{
    if (akFlags.bits & 2)
    {
        if (m_kBuffer.Size())
        {
            m_pAllocator->FreeBytes(m_kBuffer.m_pBegin, m_kBuffer.Size());
            m_kBuffer.InitStream(0, 0);
        }
    }
    if (akFlags.bits & 1)
    {
        Detach(&m_kSub, akFlags);
        m_kObj1c.Release();
    }
    m_pAllocator = 0;
    return 0;
}

#include <windows.h>
struct FUN_00d2c3a0_t
{
    void __thiscall hkThreadMemory_setMemory(unsigned int a, unsigned int b);
};

struct Slot_1c_t
{
    virtual void v0();
    virtual int v1(int n);
};

struct FUN_00cd0830_cls
{
    void AcquireSlot(unsigned int* out, unsigned int a2, unsigned int flags);
};

// When flags bit 0 is set, scans up to 32 entries, marks a zero byte, and writes slot-related values; bit 1 writes additional values.
// @fnv 0x00cd0830
void FUN_00cd0830_cls::AcquireSlot(unsigned int* out, unsigned int a2, unsigned int flags)
{
    char* self = (char*)this;
    int iSlotIndex;
    unsigned int uiZero;

    if (flags & 1)
    {
        EnterCriticalSection((LPCRITICAL_SECTION)(self + 0x336c));
        iSlotIndex = 0;
        char* e = self + 0xd98;
        do
        {
            if (*e == 0)
                goto found;
            ++iSlotIndex;
            e += 0x138;
        } while (iSlotIndex < 0x20);
        goto notfound;
    found:
        *(unsigned char*)(self + 0xd98 + iSlotIndex * 0x138) = 1;
    notfound:
        LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0x336c));

        char* slot = self + iSlotIndex * 0x138 + 0xc6c;
        *(unsigned int*)(slot + 0x128) = a2;
        unsigned int uiValue = *(unsigned int*)(self + 0xb08);
        ((FUN_00d2c3a0_t*)slot)->hkThreadMemory_setMemory(uiValue, 8);

        uiZero = 0;
        out[3] = uiZero;
        out[4] = (unsigned int)slot;
        out[7] = *(unsigned int*)(self + 0xb08);
        out[5] = *(unsigned int*)(self + 4);
        out[6] = uiZero;
        out[8] = iSlotIndex;
        out[1] = uiZero;
        out[0] = uiZero;
        out[2] = uiZero;
    }
    else
    {
        uiZero = 0;
    }

    if (flags & 2)
    {
        iSlotIndex = out[8];
        unsigned int ebp = *(unsigned int*)(self + 0xb00);
        char* slot = self + iSlotIndex * 0x138 + 0xc6c;
        if (ebp != uiZero)
        {
            int r = ((Slot_1c_t*)(self + 0x1c))->v1(ebp);
            out[1] = r;
            out[0] = r;
            out[2] = r + ebp;
            *(unsigned int*)(slot + 0x130) = ebp;
            *(unsigned int*)(slot + 0x134) = (unsigned int)out;
        }
        out[3] = (unsigned int)slot;
        out[6] = (unsigned int)(self + 0xb30);
    }
}

struct FUN_00cbf1a0_t
{
    void UpdateFields_00cbf1a0();
};

struct FUN_00cd0c50_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    CRITICAL_SECTION m_cs;

    FUN_00cd0c50_cls* Destroy(int a1);
};

// @fnv 0x00cd0c50
FUN_00cd0c50_cls* FUN_00cd0c50_cls::Destroy(int a1)
{
    DeleteCriticalSection((LPCRITICAL_SECTION)((char*)this + 0x18));
    reinterpret_cast<FUN_00cbf1a0_t*>(this)->UpdateFields_00cbf1a0();
    return this;
}

namespace fnv_00cd0b30 {
extern "C" char str_010cade0;
extern "C" char str_010cadb4;

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, unsigned int auiNewSize);

struct Target_cc01
{
    void ProcessAndReturnValue_00cc01c0(char* pText);
};

struct VSlotObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual int vSlot50();
};

struct CtorLocal
{
    int unk10;
    void** m_ppA;
    unsigned int m_nCallbackId;
    unsigned int m_cA;
    int* m_pB;
    unsigned int m_nB;
    unsigned int m_cB;
    unsigned int unk2c;
    int unk30;
    void FUN_00cd0c80();
};

struct FUN_00cd0b30_cls
{
    void hkMemorySystem__printStatistics(int a1, CtorLocal* pLocal);
    void hkFreeListMemorySystem_printStatistics(int a1);
};

// Calls FUN_00cc01c0 twice, collects slot pointers and values, passes the local to FUN_00cbc220, then calls its FUN_00cd0c80 method.
// @fnv 0x00cd0b30
// src: HAVOK_LIB 0x00cd0b30
void FUN_00cd0b30_cls::hkFreeListMemorySystem_printStatistics(int apTarget)
{
    char* self = (char*)this;
    ((Target_cc01*)apTarget)->ProcessAndReturnValue_00cc01c0(&str_010cade0);
    ((Target_cc01*)apTarget)->ProcessAndReturnValue_00cc01c0(&str_010cadb4);

    CtorLocal localData;
    localData.m_cA = 0x80000000u;
    localData.m_cB = 0x80000000u;
    VSlotObj* obj = (VSlotObj*)(self + 0x1c);
    localData.unk10 = 0;
    localData.m_ppA = 0;
    localData.m_nCallbackId = 0;
    localData.m_pB = 0;
    localData.m_nB = 0;
    localData.unk2c = 0;
    localData.unk30 = 0;
    localData.unk30 = obj->vSlot50();
    localData.unk10 = *(int*)(self + 0xb08);

    char* p = self + 0xda0;
    for (unsigned int i = 0x20; i != 0; --i)
    {
        if (*(p - 8) != 0)
        {
            hkMemoryRouter* holder = hkMemoryRouter_getInstance();
            if (localData.m_nCallbackId == (localData.m_cA & 0x3fffffffu))
            {
                ResizeAudioStream(holder->m_debug, &localData.m_ppA, 4);
            }
            localData.m_ppA[localData.m_nCallbackId] = (void*)(p - 0x134);
            localData.m_nCallbackId++;

            holder = hkMemoryRouter_getInstance();
            if (localData.m_nB == (localData.m_cB & 0x3fffffffu))
            {
                ResizeAudioStream(holder->m_debug, &localData.m_pB, 4);
            }
            localData.m_pB[localData.m_nB] = *(int*)p;
            localData.m_nB++;
        }
        p += 0x138;
    }

    this->hkMemorySystem__printStatistics(apTarget, &localData);
    localData.FUN_00cd0c80();
}
}  // namespace fnv_00cd0b30
