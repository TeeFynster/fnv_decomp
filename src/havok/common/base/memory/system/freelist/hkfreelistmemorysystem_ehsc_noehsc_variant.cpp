#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/Pair.h"
#include "../../../../../../../include/hkMemoryAllocator.h"

// src/havok/common/base/memory/system/freelist/hkfreelistmemorysystem_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/base/memory/system/freelist/hkfreelistmemorysystem.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/memory/system/freelist/hkfreelistmemorysystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/system/freelist/hkfreelistmemorysystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00cd06c0_t
{
    void __thiscall hkFreeListMemorySystem_setAllocator(int v);
};
extern int DAT_010cacd0;
struct FUN_00cd06a0
{
    void* m_p00;
    FUN_00cd06a0(int aiArg);
    void hkThreadMemory_releaseCachedMemory();
    void UpdateFields_00cbf1a0();
};
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
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct PtrArrayMember
{
    void** m_ppData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~PtrArrayMember() throw()
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            pAllocator->bufFree(m_ppData, (uCapacity & 0x3fffffff) * 4);
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
struct CallTarget_00cd1d80
{
    int hkArrayBase__spliceInto(int, int, int, int, int);
};
struct SearchObject
{
    int Search(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
struct SpawnedSub
{
    int Compute();
};
struct FUN_00cd06f0_cls
{
    void AccumulateSpawnedSubTotals(int* out);
};
struct CD0730Object
{
    virtual int hkFreeListMemorySystem_Func010(const void* info) const;
};
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
struct Helper
{
    void FUN_00cd09d0();
};
struct FUN_00cd0c70_cls
{
    int unk00;

    FUN_00cd0c70_cls* EvaluateValue_00cd0c70(int aiUnused);
};
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

#include <windows.h>
extern int DAT_010cad74;
extern int DAT_010cad0c;
extern int DAT_010cacd0;

void __fastcall hkThreadMemory_releaseCachedMemory(void* self);
void __fastcall UpdateFields_00cbf1a0(void* self);
void __fastcall ResetVftableAndDeleteCriticalSection(void* self);
void __fastcall SetVtableAndProcessState_00d5ffd0(void* self);
void __fastcall SetVirtualTable_00cbbfe0(void* self);

struct Base_cd09d0
{
    void* m_vptr;
    int unk04;
    void* m_08;
    int unk0c, unk10, unk14, unk18;
    ~Base_cd09d0()
    {
        m_08 = &DAT_010cad0c;
        SetVirtualTable_00cbbfe0(this);
    }
};
struct Mem1c_cd09d0
{
    int unk0000, unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c;
    int unk0020, unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c;
    int unk0040, unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c;
    int unk0060, unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c;
    int unk0080, unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c;
    int unk00a0, unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc;
    int unk00c0, unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc;
    int unk00e0, unk00e4, unk00e8, unk00ec, unk00f0, unk00f4, unk00f8, unk00fc;
    int unk0100, unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c;
    int unk0120, unk0124, unk0128, unk012c, unk0130, unk0134, unk0138, unk013c;
    int unk0140, unk0144, unk0148, unk014c, unk0150, unk0154, unk0158, unk015c;
    int unk0160, unk0164, unk0168, unk016c, unk0170, unk0174, unk0178, unk017c;
    int unk0180, unk0184, unk0188, unk018c, unk0190, unk0194, unk0198, unk019c;
    int unk01a0, unk01a4, unk01a8, unk01ac, unk01b0, unk01b4, unk01b8, unk01bc;
    int unk01c0, unk01c4, unk01c8, unk01cc, unk01d0, unk01d4, unk01d8, unk01dc;
    int unk01e0, unk01e4, unk01e8, unk01ec, unk01f0, unk01f4, unk01f8, unk01fc;
    int unk0200, unk0204, unk0208, unk020c, unk0210, unk0214, unk0218, unk021c;
    int unk0220, unk0224, unk0228, unk022c, unk0230, unk0234, unk0238, unk023c;
    int unk0240, unk0244, unk0248, unk024c, unk0250, unk0254, unk0258, unk025c;
    int unk0260, unk0264, unk0268, unk026c, unk0270, unk0274, unk0278, unk027c;
    int unk0280, unk0284, unk0288, unk028c, unk0290, unk0294, unk0298, unk029c;
    int unk02a0, unk02a4, unk02a8, unk02ac, unk02b0, unk02b4, unk02b8, unk02bc;
    int unk02c0, unk02c4, unk02c8, unk02cc, unk02d0, unk02d4, unk02d8, unk02dc;
    int unk02e0, unk02e4, unk02e8, unk02ec, unk02f0, unk02f4, unk02f8, unk02fc;
    int unk0300, unk0304, unk0308, unk030c, unk0310, unk0314, unk0318, unk031c;
    int unk0320, unk0324, unk0328, unk032c, unk0330, unk0334, unk0338, unk033c;
    int unk0340, unk0344, unk0348, unk034c, unk0350, unk0354, unk0358, unk035c;
    int unk0360, unk0364, unk0368, unk036c, unk0370, unk0374, unk0378, unk037c;
    int unk0380, unk0384, unk0388, unk038c, unk0390, unk0394, unk0398, unk039c;
    int unk03a0, unk03a4, unk03a8, unk03ac, unk03b0, unk03b4, unk03b8, unk03bc;
    int unk03c0, unk03c4, unk03c8, unk03cc, unk03d0, unk03d4, unk03d8, unk03dc;
    int unk03e0, unk03e4, unk03e8, unk03ec, unk03f0, unk03f4, unk03f8, unk03fc;
    int unk0400, unk0404, unk0408, unk040c, unk0410, unk0414, unk0418, unk041c;
    int unk0420, unk0424, unk0428, unk042c, unk0430, unk0434, unk0438, unk043c;
    int unk0440, unk0444, unk0448, unk044c, unk0450, unk0454, unk0458, unk045c;
    int unk0460, unk0464, unk0468, unk046c, unk0470, unk0474, unk0478, unk047c;
    int unk0480, unk0484, unk0488, unk048c, unk0490, unk0494, unk0498, unk049c;
    int unk04a0, unk04a4, unk04a8, unk04ac, unk04b0, unk04b4, unk04b8, unk04bc;
    int unk04c0, unk04c4, unk04c8, unk04cc, unk04d0, unk04d4, unk04d8, unk04dc;
    int unk04e0, unk04e4, unk04e8, unk04ec, unk04f0, unk04f4, unk04f8, unk04fc;
    int unk0500, unk0504, unk0508, unk050c, unk0510, unk0514, unk0518, unk051c;
    int unk0520, unk0524, unk0528, unk052c, unk0530, unk0534, unk0538, unk053c;
    int unk0540, unk0544, unk0548, unk054c, unk0550, unk0554, unk0558, unk055c;
    int unk0560, unk0564, unk0568, unk056c, unk0570, unk0574, unk0578, unk057c;
    int unk0580, unk0584, unk0588, unk058c, unk0590, unk0594, unk0598, unk059c;
    int unk05a0, unk05a4, unk05a8, unk05ac, unk05b0, unk05b4, unk05b8, unk05bc;
    int unk05c0, unk05c4, unk05c8, unk05cc, unk05d0, unk05d4, unk05d8, unk05dc;
    int unk05e0, unk05e4, unk05e8, unk05ec, unk05f0, unk05f4, unk05f8, unk05fc;
    int unk0600, unk0604, unk0608, unk060c, unk0610, unk0614, unk0618, unk061c;
    int unk0620, unk0624, unk0628, unk062c, unk0630, unk0634, unk0638, unk063c;
    int unk0640, unk0644, unk0648, unk064c, unk0650, unk0654, unk0658, unk065c;
    int unk0660, unk0664, unk0668, unk066c, unk0670, unk0674, unk0678, unk067c;
    int unk0680, unk0684, unk0688, unk068c, unk0690, unk0694, unk0698, unk069c;
    int unk06a0, unk06a4, unk06a8, unk06ac, unk06b0, unk06b4, unk06b8, unk06bc;
    int unk06c0, unk06c4, unk06c8, unk06cc, unk06d0, unk06d4, unk06d8, unk06dc;
    int unk06e0, unk06e4, unk06e8, unk06ec, unk06f0, unk06f4, unk06f8, unk06fc;
    int unk0700, unk0704, unk0708, unk070c, unk0710, unk0714, unk0718, unk071c;
    int unk0720, unk0724, unk0728, unk072c, unk0730, unk0734, unk0738, unk073c;
    int unk0740, unk0744, unk0748, unk074c, unk0750, unk0754, unk0758, unk075c;
    int unk0760, unk0764, unk0768, unk076c, unk0770, unk0774, unk0778, unk077c;
    int unk0780, unk0784, unk0788, unk078c, unk0790, unk0794, unk0798, unk079c;
    int unk07a0, unk07a4, unk07a8, unk07ac, unk07b0, unk07b4, unk07b8, unk07bc;
    int unk07c0, unk07c4, unk07c8, unk07cc, unk07d0, unk07d4, unk07d8, unk07dc;
    int unk07e0, unk07e4, unk07e8, unk07ec, unk07f0, unk07f4, unk07f8, unk07fc;
    int unk0800, unk0804, unk0808, unk080c, unk0810, unk0814, unk0818, unk081c;
    int unk0820, unk0824, unk0828, unk082c, unk0830, unk0834, unk0838, unk083c;
    int unk0840, unk0844, unk0848, unk084c, unk0850, unk0854, unk0858, unk085c;
    int unk0860, unk0864, unk0868, unk086c, unk0870, unk0874, unk0878, unk087c;
    int unk0880, unk0884, unk0888, unk088c, unk0890, unk0894, unk0898, unk089c;
    int unk08a0, unk08a4, unk08a8, unk08ac, unk08b0, unk08b4, unk08b8, unk08bc;
    int unk08c0, unk08c4, unk08c8, unk08cc, unk08d0, unk08d4, unk08d8, unk08dc;
    int unk08e0, unk08e4, unk08e8, unk08ec, unk08f0, unk08f4, unk08f8, unk08fc;
    int unk0900, unk0904, unk0908, unk090c, unk0910, unk0914, unk0918, unk091c;
    int unk0920, unk0924, unk0928, unk092c, unk0930, unk0934, unk0938, unk093c;
    int unk0940, unk0944, unk0948, unk094c, unk0950, unk0954, unk0958, unk095c;
    int unk0960, unk0964, unk0968, unk096c, unk0970, unk0974, unk0978, unk097c;
    int unk0980, unk0984, unk0988, unk098c, unk0990, unk0994, unk0998, unk099c;
    int unk09a0, unk09a4, unk09a8, unk09ac, unk09b0, unk09b4, unk09b8, unk09bc;
    int unk09c0, unk09c4, unk09c8, unk09cc, unk09d0, unk09d4, unk09d8, unk09dc;
    int unk09e0, unk09e4, unk09e8, unk09ec, unk09f0, unk09f4, unk09f8, unk09fc;
    int unk0a00, unk0a04, unk0a08, unk0a0c, unk0a10, unk0a14, unk0a18, unk0a1c;
    int unk0a20, unk0a24, unk0a28, unk0a2c, unk0a30, unk0a34, unk0a38, unk0a3c;
    int unk0a40, unk0a44, unk0a48, unk0a4c, unk0a50, unk0a54, unk0a58, unk0a5c;
    int unk0a60, unk0a64, unk0a68, unk0a6c, unk0a70, unk0a74, unk0a78, unk0a7c;
    int unk0a80, unk0a84, unk0a88, unk0a8c, unk0a90, unk0a94, unk0a98;
    ~Mem1c_cd09d0()
    {
        SetVtableAndProcessState_00d5ffd0(this);
    }
};
struct MemAB8_cd09d0
{
    int unk0000, unk0004, unk0008, unk000c, unk0010, unk0014;
    CRITICAL_SECTION m_kLock;
    int unk0030, unk0034, unk0038, unk003c, unk0040, unk0044, unk0048, unk004c;
    int unk0050, unk0054, unk0058, unk005c, unk0060, unk0064, unk0068, unk006c;
    int unk0070, unk0074;
    ~MemAB8_cd09d0()
    {
        DeleteCriticalSection(&m_kLock);
        UpdateFields_00cbf1a0(this);
    }
};
struct MemB30_cd09d0
{
    int unk0000, unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c;
    int unk0020, unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c;
    int unk0040, unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c;
    int unk0060, unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c;
    int unk0080, unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c;
    int unk00a0, unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc;
    int unk00c0, unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc;
    int unk00e0, unk00e4, unk00e8, unk00ec, unk00f0, unk00f4, unk00f8, unk00fc;
    int unk0100, unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c;
    int unk0120, unk0124, unk0128, unk012c, unk0130, unk0134, unk0138;
    ~MemB30_cd09d0()
    {
        ResetVftableAndDeleteCriticalSection(this);
    }
};
struct Block_cd09d0
{
    void* m_vptr;
    int unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c, unk0020;
    int unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c, unk0040;
    int unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c, unk0060;
    int unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c, unk0080;
    int unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c, unk00a0;
    int unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc, unk00c0;
    int unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc, unk00e0;
    int unk00e4, unk00e8, unk00ec, unk00f0, unk00f4, unk00f8, unk00fc, unk0100;
    int unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c, unk0120;
    int unk0124, unk0128, unk012c, unk0130, unk0134;
    ~Block_cd09d0()
    {
        m_vptr = &DAT_010cacd0;
        hkThreadMemory_releaseCachedMemory(this);
        UpdateFields_00cbf1a0(this);
    }
};
class Pool_cd09d0 : public Base_cd09d0
{
  public:
    Mem1c_cd09d0 m_k1c;
    MemAB8_cd09d0 m_kAB8;
    MemB30_cd09d0 m_kB30;
    Block_cd09d0 m_akBlocks[32];
    CRITICAL_SECTION m_kLock;
    ~Pool_cd09d0();
};

// @fnv 0x00cd09d0
Pool_cd09d0::~Pool_cd09d0()
{
    m_vptr = (void*)&DAT_010cad74;
    *(volatile int*)&DAT_012686cc = 0;
    DeleteCriticalSection(&m_kLock);
}
