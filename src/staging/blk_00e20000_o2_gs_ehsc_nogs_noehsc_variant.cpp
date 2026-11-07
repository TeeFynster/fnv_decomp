#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

// src/staging/blk_00e20000_o2_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/staging/blk_00e20000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00e20000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkStringPtr.h"
#include "../../include/hkAabb.h"
#include "../../include/hkKdTreeCastCollector.h"
#include "../../include/hkpBroadPhaseCastCollector.h"
#include "../../include/hkCpuWorldRayCastCollector.h"
#include "../../include/hkAabbTreeQueryUtils.h"
#include "../../include/hkVector4.h"
#include "../../include/hkBool.h"
#include "../../include/hkReferencedObject.h"
// hkRefPtrE_blk_00e20000_o2_gs_ehsc_nogs_noehsc_variant: local type (was include/hkRefPtrE.h, which had no evidence of one real class); no method of it is bound to a named game function
#include "../../include/hkReferencedObject.h"

class hkRefPtrE_blk_00e20000_o2_gs_ehsc_nogs_noehsc_variant
{
public:
    hkReferencedObject* m_pRetainedObject;

    ~hkRefPtrE_blk_00e20000_o2_gs_ehsc_nogs_noehsc_variant();
};
#include "../../include/hkTypeIsClass.h"
#include "../../include/hkArray.h"

__forceinline hkAabb::hkAabb()
{}


inline hkpBroadPhaseCastCollector::~hkpBroadPhaseCastCollector()
{}
inline hkKdTreeCastCollector::~hkKdTreeCastCollector()
{}
__forceinline hkVector4::hkVector4(const hkVector4& a) : m_vComponents(a.m_vComponents)
{}
inline void hkVector4::operator=(const __m128& a)
{
    m_vComponents = a;
}
__forceinline void hkVector4::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}
__forceinline float& hkVector4::operator()(int i)
{
    return ((float*)&m_vComponents)[i];
}
inline void hkVector4::SetAllComponents(float f)
{
    m_vComponents = _mm_set_ps1(f);
}
inline void hkVector4::scale(const __m128& f)
{
    m_vComponents = _mm_mul_ps(m_vComponents, f);
}

template <class B, class I>
inline hkAabbTreeQueryUtils<B, I>::Collector::~Collector()
{}

__forceinline hkCpuWorldRayCastCollector::hkCpuWorldRayCastCollector()
{
    m_workFilter = 0;
    m_workCollection = 0;
    m_fixedBufferRayHitFilterCollector = 0;
    m_fHitFraction = 1.0f;
    // The original initializes and reads only the hkBool byte in this shared slot.
    *reinterpret_cast<hkBool*>(&m_bHasHit) = false;
}
inline hkBool hkCpuWorldRayCastCollector::DidHit()
{
    return *reinterpret_cast<hkBool*>(&m_bHasHit);
}
inline float hkCpuWorldRayCastCollector::GetHitFraction()
{
    return m_fHitFraction;
}

int __cdecl PackBitFields(int a, int b, int c);
extern void* DAT_011be488[];
void __cdecl CallHandlerByIndex(int a, int b, int c);
struct FUN_00e39e60_class
{
    int ComputeIndex(int param);
};
struct FUN_00e3f340_Class
{
    int __thiscall FindEntryByKey(int arg);
    void* __thiscall GetEntryByArg(int arg);
};
struct FUN_00e3f900_class
{
    int __thiscall ReturnSelf(int a);
    int __thiscall ProcessAndReturnValue_00e3f900(int a);
};
int __cdecl hkaSplineCompressedAnimation_packMaskAndQuantizationType(int a, int b);
struct S_00df8990_Obj;
extern void(__cdecl* DAT_0126ec04)(void*, void*, S_00df8990_Obj*);
void __cdecl Runtime_ProcessEntries_00e2b9b0(void*, void*, S_00df8990_Obj*);
void __cdecl Runtime_SetDAT0126ec04();
extern int DAT_010eb3b8[];
extern int DAT_010eb3d0[];
int __cdecl hkaSplineCompressedAnimation_handleEndianQuaternion(int a, int b);
void __cdecl AlignAndAdvance(char flags, int a, int b, int* p);
extern int DAT_010eb770;
struct FUN_00e34800
{
    int vtbl;
    int a;
    int b;
    int c;
    void __thiscall m(int);
    FUN_00e34800(int x);
};
struct CB2FC0Object
{
    void __thiscall hkRotation_set(void*);
};
struct FUN_00e3b4d0_Class
{
    void __thiscall ApplyToBothObjects(void* a, void* b);
};
int __cdecl CompareStringsCaseInsensitive(int, int);
struct FUN_00e3ec30_Class
{
    int __thiscall ProcessEntries_00e3ec30(int arg);
};
struct D481D0RefVariant
{
    void set(void*, const void*);
};
struct FUN_00e3f8d0_class
{
    void Set_Thunk(void* a, const void* b);
};
struct FUN_00e29620_class
{
    void __thiscall ProcessEntries_00e29620(int param);
};
void __cdecl Runtime_ForwardCall_00e298f0(FUN_00e29620_class* object, int param);
struct SplitChunk
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
};
void __cdecl InitSplitChunks(int a1, int a2, int a3, int a4, int a5, SplitChunk* out);
struct E2baaSrc
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    signed char unk20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
};
struct E2baaDst
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float unk14;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1A;
    unsigned char unk1B;
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
};
E2baaDst* __cdecl setCollector(E2baaDst* out, E2baaSrc* src, int flag);
struct FUN_00e2d0d0_cls;
struct E2d0Ref;
struct E2d0Node;
extern float DAT_0104da48;
struct E2d0Owner
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
    E2d0Ref* m_pRef30;
};
struct E2d0Ref
{
    E2d0Owner* m_pSharedOwner;
    unsigned int unk04;
    unsigned int unk08;
    E2d0Node* m_pReferencedNode;
};
struct E2d0Slot
{
    E2d0Ref* m_pReference;
    unsigned int unk04;
    float m_f08;
    int m_state0c;
};
struct E2d0Node
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    E2d0Slot m_slots[3];
    int Probe(int a, FUN_00e2d0d0_cls* self, int* out);
};
struct FUN_00e2d0d0_cls
{
    unsigned int unk00;
    int m_04;
    unsigned int unk08;
    int m_count0c;
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
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    unsigned int unk4F0;
    unsigned int unk4F4;
    unsigned int unk4F8;
    unsigned int unk4FC;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54C;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55C;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56C;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57C;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58C;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59C;
    unsigned int unk5A0;
    unsigned int unk5A4;
    unsigned int unk5A8;
    unsigned int unk5AC;
    unsigned int unk5B0;
    unsigned int unk5B4;
    unsigned int unk5B8;
    unsigned int unk5BC;
    unsigned int unk5C0;
    unsigned int unk5C4;
    unsigned int unk5C8;
    unsigned int unk5CC;
    unsigned int unk5D0;
    unsigned int unk5D4;
    unsigned int unk5D8;
    unsigned int unk5DC;
    unsigned int unk5E0;
    unsigned int unk5E4;
    unsigned int unk5E8;
    unsigned int unk5EC;
    unsigned int unk5F0;
    unsigned int unk5F4;
    unsigned int unk5F8;
    unsigned int unk5FC;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60C;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61C;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62C;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63C;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64C;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65C;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66C;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67C;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68C;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69C;
    unsigned int unk6A0;
    unsigned int unk6A4;
    unsigned int unk6A8;
    unsigned int unk6AC;
    unsigned int unk6B0;
    unsigned int unk6B4;
    unsigned int unk6B8;
    unsigned int unk6BC;
    unsigned int unk6C0;
    unsigned int unk6C4;
    unsigned int unk6C8;
    unsigned int unk6CC;
    unsigned int unk6D0;
    unsigned int unk6D4;
    unsigned int unk6D8;
    unsigned int unk6DC;
    unsigned int unk6E0;
    unsigned int unk6E4;
    unsigned int unk6E8;
    unsigned int unk6EC;
    unsigned int unk6F0;
    unsigned int unk6F4;
    unsigned int unk6F8;
    unsigned int unk6FC;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70C;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71C;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72C;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73C;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74C;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75C;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76C;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77C;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78C;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79C;
    unsigned int unk7A0;
    unsigned int unk7A4;
    unsigned int unk7A8;
    unsigned int unk7AC;
    unsigned int unk7B0;
    unsigned int unk7B4;
    unsigned int unk7B8;
    unsigned int unk7BC;
    unsigned int unk7C0;
    unsigned int unk7C4;
    unsigned int unk7C8;
    unsigned int unk7CC;
    unsigned int unk7D0;
    unsigned int unk7D4;
    unsigned int unk7D8;
    unsigned int unk7DC;
    unsigned int unk7E0;
    unsigned int unk7E4;
    unsigned int unk7E8;
    unsigned int unk7EC;
    unsigned int unk7F0;
    unsigned int unk7F4;
    unsigned int unk7F8;
    unsigned int unk7FC;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80C;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81C;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82C;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83C;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84C;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85C;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86C;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87C;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88C;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89C;
    unsigned int unk8A0;
    unsigned int unk8A4;
    unsigned int unk8A8;
    unsigned int unk8AC;
    unsigned int unk8B0;
    unsigned int unk8B4;
    unsigned int unk8B8;
    unsigned int unk8BC;
    unsigned int unk8C0;
    unsigned int unk8C4;
    unsigned int unk8C8;
    unsigned int unk8CC;
    unsigned int unk8D0;
    unsigned int unk8D4;
    unsigned int unk8D8;
    unsigned int unk8DC;
    unsigned int unk8E0;
    unsigned int unk8E4;
    unsigned int unk8E8;
    unsigned int unk8EC;
    unsigned int unk8F0;
    unsigned int unk8F4;
    unsigned int unk8F8;
    unsigned int unk8FC;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90C;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int unk918;
    unsigned int unk91C;
    unsigned int unk920;
    unsigned int unk924;
    unsigned int unk928;
    unsigned int unk92C;
    unsigned int unk930;
    unsigned int unk934;
    unsigned int unk938;
    unsigned int unk93C;
    unsigned int unk940;
    unsigned int unk944;
    unsigned int unk948;
    unsigned int unk94C;
    unsigned int unk950;
    unsigned int unk954;
    unsigned int unk958;
    unsigned int unk95C;
    unsigned int unk960;
    unsigned int unk964;
    unsigned int unk968;
    unsigned int unk96C;
    unsigned int unk970;
    unsigned int unk974;
    unsigned int unk978;
    unsigned int unk97C;
    unsigned int unk980;
    unsigned int unk984;
    unsigned int unk988;
    unsigned int unk98C;
    unsigned int unk990;
    unsigned int unk994;
    unsigned int unk998;
    unsigned int unk99C;
    unsigned int unk9A0;
    unsigned int unk9A4;
    unsigned int unk9A8;
    unsigned int unk9AC;
    unsigned int unk9B0;
    unsigned int unk9B4;
    unsigned int unk9B8;
    unsigned int unk9BC;
    unsigned int unk9C0;
    unsigned int unk9C4;
    unsigned int unk9C8;
    unsigned int unk9CC;
    unsigned int unk9D0;
    unsigned int unk9D4;
    unsigned int unk9D8;
    unsigned int unk9DC;
    unsigned int unk9E0;
    unsigned int unk9E4;
    unsigned int unk9E8;
    unsigned int unk9EC;
    unsigned int unk9F0;
    unsigned int unk9F4;
    unsigned int unk9F8;
    unsigned int unk9FC;
    unsigned int unkA00;
    unsigned int unkA04;
    unsigned int unkA08;
    unsigned int unkA0C;
    unsigned int unkA10;
    unsigned int unkA14;
    unsigned int unkA18;
    unsigned int unkA1C;
    unsigned int unkA20;
    unsigned int unkA24;
    unsigned int unkA28;
    unsigned int unkA2C;
    unsigned int unkA30;
    unsigned int unkA34;
    unsigned int unkA38;
    unsigned int unkA3C;
    unsigned int unkA40;
    unsigned int unkA44;
    unsigned int unkA48;
    unsigned int unkA4C;
    unsigned int unkA50;
    unsigned int unkA54;
    unsigned int unkA58;
    unsigned int unkA5C;
    unsigned int unkA60;
    unsigned int unkA64;
    unsigned int unkA68;
    unsigned int unkA6C;
    unsigned int unkA70;
    unsigned int unkA74;
    unsigned int unkA78;
    unsigned int unkA7C;
    unsigned int unkA80;
    unsigned int unkA84;
    unsigned int unkA88;
    unsigned int unkA8C;
    unsigned int unkA90;
    unsigned int unkA94;
    unsigned int unkA98;
    unsigned int unkA9C;
    unsigned int unkAA0;
    unsigned int unkAA4;
    unsigned int unkAA8;
    unsigned int unkAAC;
    unsigned int unkAB0;
    unsigned int unkAB4;
    unsigned int unkAB8;
    unsigned int unkABC;
    unsigned int unkAC0;
    unsigned int unkAC4;
    unsigned int unkAC8;
    unsigned int unkACC;
    unsigned int unkAD0;
    unsigned int unkAD4;
    unsigned int unkAD8;
    unsigned int unkADC;
    unsigned int unkAE0;
    unsigned int unkAE4;
    unsigned int unkAE8;
    unsigned int unkAEC;
    unsigned int unkAF0;
    unsigned int unkAF4;
    unsigned int unkAF8;
    unsigned int unkAFC;
    unsigned int unkB00;
    unsigned int unkB04;
    unsigned int unkB08;
    unsigned int unkB0C;
    unsigned int unkB10;
    unsigned int unkB14;
    unsigned int unkB18;
    unsigned int unkB1C;
    unsigned int unkB20;
    unsigned int unkB24;
    unsigned int unkB28;
    unsigned int unkB2C;
    unsigned int unkB30;
    unsigned int unkB34;
    unsigned int unkB38;
    unsigned int unkB3C;
    unsigned int unkB40;
    unsigned int unkB44;
    unsigned int unkB48;
    unsigned int unkB4C;
    unsigned int unkB50;
    unsigned int unkB54;
    unsigned int unkB58;
    unsigned int unkB5C;
    unsigned int unkB60;
    unsigned int unkB64;
    unsigned int unkB68;
    unsigned int unkB6C;
    unsigned int unkB70;
    unsigned int unkB74;
    unsigned int unkB78;
    unsigned int unkB7C;
    unsigned int unkB80;
    unsigned int unkB84;
    unsigned int unkB88;
    unsigned int unkB8C;
    unsigned int unkB90;
    unsigned int unkB94;
    unsigned int unkB98;
    unsigned int unkB9C;
    unsigned int unkBA0;
    unsigned int unkBA4;
    unsigned int unkBA8;
    unsigned int unkBAC;
    unsigned int unkBB0;
    unsigned int unkBB4;
    unsigned int unkBB8;
    unsigned int unkBBC;
    unsigned int unkBC0;
    unsigned int unkBC4;
    unsigned int unkBC8;
    unsigned int unkBCC;
    unsigned int unkBD0;
    unsigned int unkBD4;
    unsigned int unkBD8;
    unsigned int unkBDC;
    unsigned int unkBE0;
    unsigned int unkBE4;
    unsigned int unkBE8;
    unsigned int unkBEC;
    unsigned int unkBF0;
    unsigned int unkBF4;
    unsigned int unkBF8;
    unsigned int unkBFC;
    unsigned int unkC00;
    unsigned int unkC04;
    unsigned int unkC08;
    unsigned int unkC0C;
    unsigned int unkC10;
    unsigned int unkC14;
    unsigned int unkC18;
    unsigned int unkC1C;
    unsigned int unkC20;
    unsigned int unkC24;
    unsigned int unkC28;
    unsigned int unkC2C;
    unsigned int unkC30;
    unsigned int unkC34;
    unsigned int unkC38;
    unsigned int unkC3C;
    unsigned int unkC40;
    unsigned int unkC44;
    unsigned int unkC48;
    unsigned int unkC4C;
    unsigned int unkC50;
    unsigned int unkC54;
    unsigned int unkC58;
    unsigned int unkC5C;
    unsigned int unkC60;
    unsigned int unkC64;
    unsigned int unkC68;
    unsigned int unkC6C;
    unsigned int unkC70;
    unsigned int unkC74;
    unsigned int unkC78;
    unsigned int unkC7C;
    unsigned int unkC80;
    unsigned int unkC84;
    unsigned int unkC88;
    unsigned int unkC8C;
    unsigned int unkC90;
    unsigned int unkC94;
    unsigned int unkC98;
    unsigned int unkC9C;
    unsigned int unkCA0;
    unsigned int unkCA4;
    unsigned int unkCA8;
    unsigned int unkCAC;
    unsigned int unkCB0;
    unsigned int unkCB4;
    unsigned int unkCB8;
    unsigned int unkCBC;
    unsigned int unkCC0;
    unsigned int unkCC4;
    unsigned int unkCC8;
    unsigned int unkCCC;
    unsigned int unkCD0;
    unsigned int unkCD4;
    unsigned int unkCD8;
    unsigned int unkCDC;
    unsigned int unkCE0;
    unsigned int unkCE4;
    unsigned int unkCE8;
    unsigned int unkCEC;
    unsigned int unkCF0;
    unsigned int unkCF4;
    unsigned int unkCF8;
    unsigned int unkCFC;
    unsigned int unkD00;
    unsigned int unkD04;
    unsigned int unkD08;
    unsigned int unkD0C;
    unsigned int unkD10;
    unsigned int unkD14;
    unsigned int unkD18;
    unsigned int unkD1C;
    unsigned int unkD20;
    unsigned int unkD24;
    unsigned int unkD28;
    unsigned int unkD2C;
    unsigned int unkD30;
    unsigned int unkD34;
    unsigned int unkD38;
    unsigned int unkD3C;
    unsigned int unkD40;
    unsigned int unkD44;
    unsigned int unkD48;
    unsigned int unkD4C;
    unsigned int unkD50;
    unsigned int unkD54;
    unsigned int unkD58;
    unsigned int unkD5C;
    unsigned int unkD60;
    unsigned int unkD64;
    unsigned int unkD68;
    unsigned int unkD6C;
    unsigned int unkD70;
    unsigned int unkD74;
    unsigned int unkD78;
    unsigned int unkD7C;
    unsigned int unkD80;
    unsigned int unkD84;
    unsigned int unkD88;
    unsigned int unkD8C;
    unsigned int unkD90;
    unsigned int unkD94;
    unsigned int unkD98;
    unsigned int unkD9C;
    unsigned int unkDA0;
    unsigned int unkDA4;
    unsigned int unkDA8;
    unsigned int unkDAC;
    unsigned int unkDB0;
    unsigned int unkDB4;
    unsigned int unkDB8;
    unsigned int unkDBC;
    unsigned int unkDC0;
    unsigned int unkDC4;
    unsigned int unkDC8;
    unsigned int unkDCC;
    unsigned int unkDD0;
    unsigned int unkDD4;
    unsigned int unkDD8;
    unsigned int unkDDC;
    E2d0Node* m_pNodes[100];
    int TraverseNode(E2d0Node* a1, int a2, int* a3, E2d0Ref** a4);
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
hkMemoryRouter* GetMemoryRouterStub();
struct RefHolderE2
{
    void* m_ptr;
    RefHolderE2(const RefHolderE2& other);
    ~RefHolderE2();
    RefHolderE2& operator=(const RefHolderE2& other);
};
struct KeyedEntryE2
{
    float m_key;
    RefHolderE2 m_uiFilterValue;
};
// The original reserve call is 0x00c908c0, hkArrayUtil::_reserve in the shared units.
template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    if (getCapacity() < n)
    {
        int cap2 = 2 * getCapacity();
        int newCap = n < cap2 ? cap2 : n;
        hkArrayUtil::_reserve(alloc, this, newCap, sizeof(T));
    }
}

template <typename T> __forceinline void hkArrayUtil::destruct(T* p, int n, hkTypeIsClass)
{
    for (int i = 0; i < n; i++)
        p[i].~T();
}

template <typename T> __forceinline void hkArrayUtil::constructWithArray(T* dst, int n, const T* src, hkTypeIsClass)
{
    for (int i = 0; i < n; i++)
        new (dst + i) T(src[i]);
}

template <typename T> __forceinline hkArrayBase<T>& hkArrayBase<T>::copyFromArray(
    hkMemoryAllocator& kHeap, const hkArrayBase<T>& kSrc, hkTypeIsClass)
{
    const int iWas = m_iElementCount;
    const int iNow = kSrc.m_iElementCount;
    const int iShared = iNow > iWas ? iWas : iNow;
    GrowArrayCapacity(kHeap, iNow);
    hkArrayUtil::destruct(m_data + iNow, iWas - iNow, hkTypeIsClass());
    copy(m_data, kSrc.m_data, iShared);
    hkArrayUtil::constructWithArray(m_data + iShared, iNow - iShared, kSrc.m_data + iShared, hkTypeIsClass());
    m_iElementCount = iNow;
    return *this;
}

template <typename T, typename A> __forceinline hkArray<T, A>& hkArray<T, A>::operator=(const hkArray<T, A>& a)
{
    copyFromArray(GetMemoryRouterStub()->heap(), a, hkTypeIsClass());
    return *this;
}

struct FUN_00e2f680_Class
{
    RefHolderE2 m_ref;
    hkArray<KeyedEntryE2> m_entries;

    FUN_00e2f680_Class& CopyFrom(const FUN_00e2f680_Class& other);
};
class FUN_00e30f10
{
  public:
    unsigned short m_kPointA;
    unsigned char m_kPointB;
    FUN_00e30f10();
};
unsigned short NormalizeToUShort(float fMin, float fScaledValue, float fValue);
void __cdecl SwapBytesAndAdvance(int n, unsigned char** pp);
void __cdecl FillInterpolatedValues(int count, float** array, float first, float last);
unsigned int __cdecl hkaSplineCompressedAnimation_handleEndianKnots(unsigned char a1, unsigned int* a2);
int __cdecl hkaSplineCompressedAnimation_handleEndianScalarControlPoints(unsigned char a1, unsigned int a2, unsigned int a3, unsigned int* a4);
void __cdecl Object_UpdateFields_00e31740(unsigned char flag, unsigned int a2, unsigned int* out);
int __cdecl hkaSplineCompressedAnimation_handleEndianKnots(int a, int* c);
void __cdecl AlignAndAdvance(int a, int result, int b, int* c);
void __cdecl Object_UpdateFields_00e31780(int a, int b, int* c);
int __cdecl FindKeyInterval(int a, int b, unsigned char key, unsigned char* t);
unsigned char* StoreBoolFlag(unsigned char* pDest, int value);
struct FUN_00e33910_item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    bool* Test(bool* result);
};
class FUN_00e33910_cls
{
  public:
    FUN_00e33910_item* m_pItems;
    int m_uiItemCount;
    bool* AreAllItemsValid(bool* out);
};
extern "C" void _ReadWriteBarrier(void);
extern int DAT_010eb770;
struct SubObj_b4888
{
    SubObj_b4888();
};
struct Base_b4888
{
    unsigned int unk00;
    unsigned short unk04;
    volatile unsigned short m_06;
    volatile unsigned int m_08;

    Base_b4888()
    {
        m_06 = 1;
        *(int**)this = &DAT_010eb770;
        m_08 = 0;
    }
};
struct FUN_00e347c0 : Base_b4888
{
    SubObj_b4888 m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;

    FUN_00e347c0();
};
struct S_00e34950_Foo
{
    unsigned short unk00;
    unsigned short unk02;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;

    S_00e34950_Foo* Init();
};
extern int DAT_010df9f4;
class FUN_00e39a80
{
  public:
    int m_vptr00;
    unsigned short unk04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    int m_10;
    float m_14;
    FUN_00e39a80();
};
struct FUN_00e3a270 : hkReferencedObject
{
    int unk08;
    int unk0c;
    int m_data;
    int m_iElementCount;
    int m_iCapacityState;

    FUN_00e3a270();
    virtual void FUN_vfn0();
};
struct S_00e3ae70_Alloc
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};
struct S_00e3ae70_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00e3ae70_Alloc* m_pAllocator;
};
S_00e3ae70_Holder* __cdecl hkMemoryRouter_getInstance() throw();
struct S_00e3ae70_Item
{
    int unk00;
    int unk04;
    int unk08;
    float m_0c;
    float m_10;
};
struct S_00e3ae70_Array
{
    S_00e3ae70_Item** pBuffer;
    int iSize;
    unsigned int SimpleArrayStorage;
};
struct S_00e3ae70_cls
{
    void CollectSlotValues(unsigned int a1, unsigned int a2, S_00e3ae70_Array* pOut);
    void SetItemValues(unsigned int a1, unsigned int a2, float a3, float a4);
};
extern void* DAT_010eb98c;
union ReleaseFlags
{
    int releaseHandle;
    int releaseOwner;
};
struct LinkOwner
{
    void* unk00;
    void* unk04;
    void* unk08;
    void __thiscall hkpBridgeConstraintAtom_init(void*);
};
struct FUN_00e3b060_Class
{
    void* vtable;
    int unk04;
    int unk08;
    LinkOwner links;
    FUN_00e3b060_Class* __thiscall ReleaseLinks(ReleaseFlags flags);
};
struct S_00e3c5b0_Obj
{
    int unk04;
    int unk08;
    int unk0c;
    virtual void vf0();
};
struct S_00e3c5b0_Act
{
    int unk14;
    virtual void vf1();
};
struct S_00e3c5b0_Base : S_00e3c5b0_Obj, S_00e3c5b0_Act
{
    S_00e3c5b0_Base(int type, int flag) throw();
};
struct S_00e3c5b0_Arr
{
    int* data;
    int size;
    int cap;
    S_00e3c5b0_Arr()
    {
        data = 0;
        size = 0;
        cap = (int)0x80000000;
    }
};
struct FUN_00e3c5b0 : S_00e3c5b0_Base
{
    S_00e3c5b0_Arr a;
    S_00e3c5b0_Arr b;
    S_00e3c5b0_Arr c;
    float unk3c;
    unsigned char unk40;
    FUN_00e3c5b0(float f);
};
struct FUN_00e3dfb0_arg
{
    int value;
    unsigned short m_type;
    unsigned short unk06;
};
class FUN_00e3dfb0_cls
{
  public:
    int unk00;
    int unk04;
    int m_08;
    int unk0c;
    int unk10;
    int m_14;
    int unk18;
    int unk1c;
    int m_20;
    int unk24;
    int unk28;
    int m_2c;
    int unk30;
    int unk34;
    int m_38;

    int hkxVertexBuffer_getVertexDataPtr(FUN_00e3dfb0_arg* rec);
};
struct FUN_00e3ec00_Class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    FUN_00e3ec00_Class** unk28;
    int unk2c;

    int __thiscall GetTotal();
};
struct S_00e3ed00_Foo;
struct S_00e3ed00_Result
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
struct S_00e3ed00_List
{
    S_00e3ed00_Foo** elements;
    int count;
    int capacity;
};
struct S_00e3ed00_Foo
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
    S_00e3ed00_Foo** children;
    int childCount;

    S_00e3ed00_Result* __thiscall hkMemoryRouter_getInstance();
    int __thiscall AppendToTraversalList(S_00e3ed00_Foo* param1, S_00e3ed00_List* param2);
};
void __cdecl ResizeAudioStream(int param1, S_00e3ed00_List* param2, int param3);
hkMemoryRouter& GetMemoryRouter();
inline hkRefPtrE_blk_00e20000_o2_gs_ehsc_nogs_noehsc_variant::~hkRefPtrE_blk_00e20000_o2_gs_ehsc_nogs_noehsc_variant()
{
    if (m_pRetainedObject)
        m_pRetainedObject->removeReference();
    m_pRetainedObject = 0;
}
struct ReferenceCountedPointer
{
    hkReferencedObject* m_pRetainedObject;
    void release()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};
struct Pair8
{
    int unk00;
    hkStringPtr m_name;
    ~Pair8()
    {}
};
struct Elem40
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
};
template <class T> __forceinline void destructAll2(T* t, int n, hkTypeIsClass)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}
__forceinline void destructAll(Elem40* t, int n)
{}
template <class T> __forceinline void destructAll(T* t, int n)
{
    destructAll2(t, n, hkTypeIsClass());
}
struct BaseE3EAA0
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    virtual void vf0();
    void Shutdown();
};
struct FUN_00e3ed80 : BaseE3EAA0
{
    hkStringPtr m_14;
    ReferenceCountedPointer m_18;
    hkArray<Elem40> m_1c;
    hkArray<hkRefPtrE_blk_00e20000_o2_gs_ehsc_nogs_noehsc_variant> m_28;
    hkArray<Pair8> m_34;
    hkStringPtr m_40;
    virtual ~FUN_00e3ed80();
};
struct E3F0F0Less
{
};
void __cdecl HeapSort(int* piFirst, int* piLast, E3F0F0Less kPred);
struct E3F0F0Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int* m_piFirst;
    int* m_piLast;

    void ProcessState_00e3f0f0();
};
struct FUN_00e3f210_cls
{
    char m_buf[2];
    unsigned char HasDelimiter();
};
int __cdecl CompareStringsCaseInsensitive(unsigned int a, int b);
struct FUN_00e3f230_Entry
{
    unsigned int m_flagged;
    unsigned int unk04;
};
struct FUN_00e3f230_cls
{
    int unk00;
    int unk04;
    FUN_00e3f230_Entry* m_pEntries;
    int m_uiItemCount;
    int FindEntryByKey(int arg);
};
int __cdecl CompareStringsCaseInsensitive(const char* pcA, const char* pcB);
struct BE3E7E0Entry
{
    unsigned int m_uiTaggedName;
    int unk04;
    int unk08;
    int unk0C;

    const char* GetName() const
    {
        return (const char*)(m_uiTaggedName & ~1u);
    }
};
class BE3E7E0Table
{
  public:
    int unk00;
    int unk04;
    BE3E7E0Entry* m_pkEntryArray;
    int m_iArrayLength;

    BE3E7E0Entry* FindEntryByName(const char* pcName);
};
void __cdecl SetEntity();
void __cdecl Object_SetEntity_Thunk();
struct FUN_00e39e80_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    float unk1C;
    float GetUnk1C_00e39e80();
};
struct FUN_00e3df50_Class
{
    FUN_00e3df50_Class* __thiscall ReturnSelf(int param);
};
int __cdecl hkxVertexBuffer_getVertexDataPtr(int param_1, int* param_2);
int __cdecl Object_HkxVertexBuffer_getVertexDataPtr_Thunk(int param_1, int* param_2);
struct FNVTreeNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int taggedName;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    FNVTreeNode** children;
    int childCount;

    FNVTreeNode* __thiscall FindChildByName(const char* name);
};
class Base
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int GetUnk0C();
};
struct FUN_00e31080
{
    float f0;
    float f4;
    float f8;
    float fc;
    unsigned short w10;
    unsigned short w12;
    unsigned short w14;
    unsigned short w16;
    unsigned char b18;
    unsigned char b19;
    unsigned char b1a;
    unsigned char b1b;
    FUN_00e31080();
};
bool* IsValidMode(bool* out, unsigned int mode);
struct E3F290Entry
{
    int unk00;
    int unk04;
};
struct E3F290Class
{
    int unk00;
    int unk04;
    E3F290Entry* unk08;
    int __thiscall GetEntryValue(int index);
};
struct FUN_00e3f370_handle
{
    int unk00;
    void Release();
};
struct FUN_00e3f370_pair
{
    FUN_00e3f370_handle first;
    FUN_00e3f370_handle second;
};
struct FUN_00e3f370_cls
{
    int unk00;
    int unk04;
    FUN_00e3f370_pair* m_pItems;
    int m_iArrayLength;
    void ReleaseItems();
};

struct Mat34
{
    float m[3][4];
};

// @fnv 0x00e310c0
// src: GUESS 0x00e310c0 (confidence: low)
void hkVector4_ProcessEntries_00e310c0(const Mat34* src, int stride, int n, int row, int col, hkVector4** outA, hkVector4** outB,
                  hkVector4** outC)
{
    for (int i = 0; i < n; i++)
    {
        const Mat34& t = src[(row + i) * stride + col];
        (*outA)[i].set(t.m[0][0], t.m[0][1], t.m[0][2]);
        (*outB)[i].set(t.m[1][0], t.m[1][1], t.m[1][2], t.m[1][3]);
        (*outC)[i].set(t.m[2][0], t.m[2][1], t.m[2][2]);
    }
}

struct Ray
{
    hkVector4 from, to;
    hkBool filtering;
    unsigned int filterInfo;
    Ray() : filtering(false), filterInfo(0)
    {}
};
// Havok 7.1 hkpWorldRayCastCommand (hkpRayCastQueryJobs.h): m_rayInput, m_results, m_resultsCapacity,
// m_numResultsOut, m_useCollector, m_stopAfterFirstHit; same constructor. Not the console-command Command.
struct hkpWorldRayCastCommand
{
    Ray input;
    void* results;
    int capacity;
    int count;
    hkBool useCollector, stop;
    hkpWorldRayCastCommand()
    {
        useCollector = false;
        stop = false;
    }
};
struct BundleCommand
{
    Ray input[4];
    int active;
    hkBool stop;
    void* results[4];
    __declspec(align(16)) int counts[4];
    hkBool useCollector;
};
struct Task
{
    hkVector4 o0, o1, o2, i0, i1, i2;
    int mask;
};
struct Input
{
    int unk00, unk04, unk08, unk0c;
    void* data10;
};
extern int DAT_011b3830[];
Task __cdecl Runtime_UpdateState_00d1bb50(const hkVector4&, const hkVector4&, const hkVector4&, const hkVector4&, const hkVector4&,
                          const hkVector4&, const hkVector4&, const hkVector4&, int);
void __cdecl AabbTree_ForwardCall_00d1d530(const Input*, void*, int, const Task&,
                          hkAabbTreeQueryUtils<hkAabbTreeData::RayQueryAabb>::Collector**, float*);
// @fnv 0x00e2b070
// src: GUESS 0x00e2b070 (confidence: low)
void hkVector4_ProcessEntries_00e2b070(const Input* input, BundleCommand* src, void* filter, hkVector4& fractions, void*, void*, void*,
                  void*, int*)
{
    if (!input)
        return;
    Task task = Runtime_UpdateState_00d1bb50(src->input[0].from, src->input[0].to, src->input[1].from, src->input[1].to,
                             src->input[2].from, src->input[2].to, src->input[3].from, src->input[3].to, 15);
    hkpWorldRayCastCommand commands[4];
    hkCpuWorldRayCastCollector collectors[4];
    float limits[4];
    hkAabbTreeQueryUtils<hkAabbTreeData::RayQueryAabb>::Collector* ptrs[4];
    for (int i = 0; i < 4; ++i)
    {
        commands[i].results = src->results[i];
        collectors[i].m_result = reinterpret_cast<int>(commands[i].results);
        collectors[i].m_iFieldAfterResult = reinterpret_cast<int>(commands[i].results);
        commands[i].input = src->input[i];
        commands[i].stop = src->stop;
        commands[i].capacity = 1;
        commands[i].count = 0;
        collectors[i].m_iFilter = reinterpret_cast<int>(filter);
        collectors[i].m_iFieldBeforeResult = reinterpret_cast<int>(&commands[i].input);
        collectors[i].m_iFieldAfterHasHit = reinterpret_cast<int>(&commands[i]);
        limits[i] = fractions(i);
        ptrs[i] = &collectors[i];
    }
    task.mask = DAT_011b3830[src->active];
    AabbTree_ForwardCall_00d1d530(input, input->data10, 0, task, ptrs, limits);
    for (int i = 0; i < 4; ++i)
        src->counts[i] = commands[i].count;
    fractions.set(limits[0], limits[1], limits[2], limits[3]);
}

struct Bundle
{
    hkVector4 m_data[3];
};
struct RayQuerySet
{
    __forceinline RayQuerySet()
    {}
    Bundle m_vFrom;
    Bundle m_vInverseDirection;
    int m_uiMask;
};
// @fnv 0x00e2baf0
// src: GUESS 0x00e2baf0 (confidence: low)
RayQuerySet __cdecl hkVector4_UpdateState_00e2baf0(const hkVector4& from0, const hkVector4& invDir0, const hkVector4& from1, const hkVector4& invDir1,
                                 const hkVector4& from2, const hkVector4& invDir2, const hkVector4& from3, const hkVector4& invDir3,
                                 int mask)
{
    Bundle bundleFrom;
    hkVector4 tmpFrom;
    Bundle bundleInvDir;
    hkVector4 tmpInvDir;
    bundleFrom.m_data[0] = from0;
    bundleFrom.m_data[1] = from1;
    bundleFrom.m_data[2] = from2;
    tmpFrom = from3;
    bundleInvDir.m_data[0] = invDir0;
    bundleInvDir.m_data[1] = invDir1;
    bundleInvDir.m_data[2] = invDir2;
    tmpInvDir = invDir3;
    {
        __m128 tmp3, tmp2, tmp1, tmp0;

        tmp0 = _mm_shuffle_ps((bundleFrom.m_data[0]), (bundleFrom.m_data[1]), 0x44);
        tmp2 = _mm_shuffle_ps((bundleFrom.m_data[0]), (bundleFrom.m_data[1]), 0xEE);
        tmp1 = _mm_shuffle_ps((bundleFrom.m_data[2]), (tmpFrom), 0x44);
        tmp3 = _mm_shuffle_ps((bundleFrom.m_data[2]), (tmpFrom), 0xEE);

        (bundleFrom.m_data[0]) = _mm_shuffle_ps(tmp0, tmp1, 0x88);
        (bundleFrom.m_data[1]) = _mm_shuffle_ps(tmp0, tmp1, 0xDD);
        (bundleFrom.m_data[2]) = _mm_shuffle_ps(tmp2, tmp3, 0x88);
        (tmpFrom) = _mm_shuffle_ps(tmp2, tmp3, 0xDD);
    }
    {
        __m128 tmp3, tmp2, tmp1, tmp0;

        tmp0 = _mm_shuffle_ps((bundleInvDir.m_data[0]), (bundleInvDir.m_data[1]), 0x44);
        tmp2 = _mm_shuffle_ps((bundleInvDir.m_data[0]), (bundleInvDir.m_data[1]), 0xEE);
        tmp1 = _mm_shuffle_ps((bundleInvDir.m_data[2]), (tmpInvDir), 0x44);
        tmp3 = _mm_shuffle_ps((bundleInvDir.m_data[2]), (tmpInvDir), 0xEE);

        (bundleInvDir.m_data[0]) = _mm_shuffle_ps(tmp0, tmp1, 0x88);
        (bundleInvDir.m_data[1]) = _mm_shuffle_ps(tmp0, tmp1, 0xDD);
        (bundleInvDir.m_data[2]) = _mm_shuffle_ps(tmp2, tmp3, 0x88);
        (tmpInvDir) = _mm_shuffle_ps(tmp2, tmp3, 0xDD);
    }
    RayQuerySet bundle;
    bundle.m_vFrom = bundleFrom;
    bundle.m_vInverseDirection = bundleInvDir;
    bundle.m_uiMask = mask;
    return bundle;
}

namespace fnv_00e2c100 {
extern float DAT_01011d78;
struct QuantizedNode
{
    unsigned short maxX, maxY, maxZ, minX, minY, minZ, child0, child1, flags, metadata;
};
struct NodeArray
{
    QuantizedNode* data;
    QuantizedNode* __thiscall GetEntryOffset(unsigned short);
};
struct Tree
{
    hkVector4 treeHeader;
    int nodeCount, capacity, root;
    NodeArray nodes;
    int field20, field24, field28, field2c;
    hkVector4 bounds;
    hkVector4 offset;
    hkVector4 scale0;
    hkVector4 scale1;
    hkVector4 scale;
};
struct Ray
{
    hkVector4 origin, invDirection;
};
struct Shape
{
    __m128 transform0, transform1;
    signed char shapeType;
    unsigned char unk21, unk22, unk23;
    int shapeKey;
    int unk28, unk2c;
    void* object;
    void* filter;
    int key;
    bool hasFilter;
};
struct Collector
{
    virtual void unused();
    virtual float hit(QuantizedNode*);
    int collectorState;
};
struct QueryHeader
{
    virtual void queryUnused();
    int flags, user;
};
struct Query : QueryHeader, Collector
{
    float fraction;
    bool hitFlag;
    unsigned char unk19;
    unsigned short unk1a;
    void* body;
    void* shape;
    void* object;
    void* object2;
    hkVector4 normal;
    hkVector4 position;
    int key;
    void* filter;
    int mode;
    int state;
    void* callback;
    int callbackFlags, callbackKey, callbackState;
    hkVector4 maxFraction;
};
struct Filter
{
    virtual void InvokeCallback();
    virtual void FUN_00df8960();
    float fraction;
    void* body;
    void* object;
    void* filter;
    int flags;
    int key;
    Filter(void* a, void* b) : fraction(1.0f), body(a), object(a), filter(b), flags(0), key(0)
    {}
};
struct FilterData
{
    int unk00, unk04, unk08, unk0c;
    int data;
};
// src: HAVOK_LIB 0x00e2baa0
__declspec(noinline) Query* __cdecl setCollector(Query* q, Shape* s, void* f)
{
    q->fraction = 1.0f;
    q->hitFlag = false;
    q->object = s->object;
    q->shape = s;
    q->object2 = s->object;
    q->body = s;
    q->key = s->shapeKey;
    FilterData* active = s->shapeType ? (FilterData*)f : 0;
    q->filter = active ? &active->data : 0;
    return q;
}
extern void __cdecl hkVector4_UpdateState_00e2baf0(void*, __m128*, __m128*, __m128*, __m128*, __m128*, __m128*, __m128*, __m128*, int);
extern void __cdecl Object_CollectRayTreeHits(Tree*, QuantizedNode*, void*, void*, Collector**, float*);
extern int DAT_011b3830[];
extern float DAT_01267e30;
__forceinline void restore(QuantizedNode* n, const hkVector4& scale, const hkVector4& offset, hkAabb& out)
{

    reinterpret_cast<hkVector4&>(out.m_kMaximumCorner.x).set(float(n->maxX << 15), float(n->maxY << 15), float(n->maxZ << 15), DAT_01011d78);
    reinterpret_cast<hkVector4&>(out.m_kMinimumCorner.x).set(float(n->minX << 15), float(n->minY << 15), float(n->minZ << 15), DAT_01011d78);
    __m128 factor = scale.v;
    reinterpret_cast<hkVector4&>(out.m_kMinimumCorner.x).v = _mm_mul_ps(reinterpret_cast<hkVector4&>(out.m_kMinimumCorner.x).v, factor);
    reinterpret_cast<hkVector4&>(out.m_kMaximumCorner.x).v = _mm_mul_ps(factor, reinterpret_cast<hkVector4&>(out.m_kMaximumCorner.x).v);
    reinterpret_cast<hkVector4&>(out.m_kMinimumCorner.x).v = _mm_sub_ps(reinterpret_cast<hkVector4&>(out.m_kMinimumCorner.x).v, offset.v);
    reinterpret_cast<hkVector4&>(out.m_kMaximumCorner.x).v = _mm_sub_ps(reinterpret_cast<hkVector4&>(out.m_kMaximumCorner.x).v, offset.v);
}
__forceinline __m128 reduceNear(const __m128& mn)
{
    __m128 y = _mm_shuffle_ps(mn, mn, 0x55), z = _mm_shuffle_ps(mn, mn, 0xaa);
    return _mm_max_ps(_mm_max_ps(mn, *(__m128*)&DAT_01267e30), _mm_max_ps(y, z));
}
__forceinline __m128 reduceFar(const __m128& mx, const hkVector4& limit)
{
    __m128 y = _mm_shuffle_ps(mx, mx, 0x55), z = _mm_shuffle_ps(mx, mx, 0xaa);
    return _mm_min_ps(_mm_min_ps(mx, limit.v), _mm_min_ps(y, z));
}
__forceinline bool intersects(const hkAabb& bounds, Ray* r, const hkVector4& limit)
{
    const __m128& lo = reinterpret_cast<const hkVector4&>(bounds.m_kMinimumCorner.x).v;
    const __m128& hi = reinterpret_cast<const hkVector4&>(bounds.m_kMaximumCorner.x).v;
    hkVector4 a, b;
    a.v = lo;
    b.v = hi;
    a.v = _mm_sub_ps(a.v, r->origin.v);
    b.v = _mm_sub_ps(b.v, r->origin.v);
    a.scale(r->invDirection.v);
    b.scale(r->invDirection.v);
    hkVector4 mn, mx;
    mn.v = _mm_min_ps(a.v, b.v);
    mx.v = _mm_max_ps(a.v, b.v);
    hkVector4 nearValue, farValue;
    nearValue.v = reduceNear(mn.v);
    farValue.v = reduceFar(mx.v, limit);
    return (_mm_movemask_ps(_mm_cmplt_ps(nearValue.v, farValue.v)) & 1) != 0;
}
// @fnv 0x00e2c100
// src: GUESS 0x00e2c100 (confidence: low)
void __cdecl Object_ProcessEntries_00e2c100(Tree* tree, QuantizedNode* node, void* arg3, Ray* rays, Query* queries, Filter* filters,
                          Shape* shapes, void* arg8, float* fractions, int* indices, int count, int depth,
                          int capacity0, int capacity1, int* out0, int* num0, int* out1, int* num1,
                          QuantizedNode* child0, QuantizedNode* child1)
{
    *num1 = 0;
    *num0 = 0;
    const hkVector4& scale = tree->scale;
    const hkVector4& offset = tree->offset;
    if (node->flags & 0x8000)
    {
        hkAabb bounds;
        restore(node, scale, offset, bounds);
        if (0 >= count)
            return;
        hkVector4 limit;
        limit.v = _mm_set_ps1(1.0f);
        for (int i = 0; i < count; ++i)
        {
            int index = indices[i];
            if (intersects(bounds, rays + index, limit))
            {
                setCollector(queries, shapes + index, arg8);
                queries->hit(node);
            }
        }
        return;
    }
    if (capacity0 >= count && capacity1 >= count && depth >= 2 && count > 4)
    {
        NodeArray* manager = &tree->nodes;
        QuantizedNode* a = manager->GetEntryOffset(node->child0);
        QuantizedNode* b = manager->GetEntryOffset(node->child1);
        *child0 = *a;
        *child1 = *b;
        hkAabb bounds0, bounds1;
        restore(child0, scale, offset, bounds0);
        restore(child1, scale, offset, bounds1);
        hkVector4 limit;
        limit.v = _mm_set_ps1(1.0f);
        for (int i = 0; i < count; ++i)
        {
            int index = indices[i];
            if (intersects(bounds0, rays + index, limit))
            {
                *out0++ = index;
                ++*num0;
            }
            if (intersects(bounds1, rays + index, limit))
            {
                *out1++ = index;
                ++*num1;
            }
        }
        return;
    }
    int index4[4] = {0, 0, 0, 0};
    int groups = (count + 3) >> 2;
    if (groups <= 0)
        return;
    for (int bundle = 0; bundle < groups; ++bundle)
    {
        float oldFraction[4];
        int left = count - 4 * bundle;
        int n = left < 4 ? left : 4;
        Query* query = queries;
        for (int i = 0; i < n; ++i, ++query)
        {
            index4[i] = indices[4 * bundle + i];
            Shape* shape = shapes + index4[i];

            setCollector(query, shape, arg8);

            query->maxFraction.SetAllComponents(fractions[index4[i]]);
            oldFraction[i] = fractions[index4[i]];
            if (shape->hasFilter)
            {
                query->callback = new (filters + i) Filter(shape->object, shape->filter);
                DAT_0126ec04 = Runtime_ProcessEntries_00e2b9b0;
            }
            else
                query->callback = 0;
        }
        struct Batch
        {
            __m128 originX, originY, originZ, inverseX, inverseY, inverseZ;
            int mask;
        } batch;
        hkVector4_UpdateState_00e2baf0(&batch, &rays[index4[0]].origin.v, &rays[index4[0]].invDirection.v, &rays[index4[1]].origin.v,
                     &rays[index4[1]].invDirection.v, &rays[index4[2]].origin.v, &rays[index4[2]].invDirection.v,
                     &rays[index4[3]].origin.v, &rays[index4[3]].invDirection.v, DAT_011b3830[n]);
        Collector* collectors[4] = {queries, queries + 1, queries + 2, 3 + queries};
        Object_CollectRayTreeHits(tree, node, arg3, &batch, collectors, oldFraction);
        for (int i = 0; i < n; ++i)
            fractions[index4[i]] = queries[i].maxFraction.v.m128_f32[0];
    }
}
}  // namespace fnv_00e2c100
