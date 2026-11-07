// src/staging/blk_00e20000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e20000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00e20000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#define FNV_VEC4_SIMD
#include "../../include/Vec4.h"
#include "../../include/hkMemoryRouter.h" // hkMemoryRouter: heap allocator at +0x10; instance getter is 0x00c85750.
#include "../../include/hkBool.h"
#include "../../include/hkVector4.h"
#include "../../include/hkRotation.h"
#include "../../include/V4.h"
#include "../../include/hkBaseObject.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkpTyremarksInfo.h"
#include "../../include/hkpTyremarksWheel.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkStringPtr.h"
// hkRefPtrE_blk_00e20000_o2_rtm_variant: local type (was include/hkRefPtrE.h, which had no evidence of one real class); no method of it is bound to a named game function

class hkRefPtrE_blk_00e20000_o2_rtm_variant
{
public:
    hkReferencedObject* m_pRetainedObject;

    ~hkRefPtrE_blk_00e20000_o2_rtm_variant();
};
#include "../../include/hkTypeIsClass.h"
#include "../../include/hkArray.h"
int __cdecl PackBitFields(int a, int aiMiddleBits, int aiHighBits);
extern void* DAT_011be488[];
void __cdecl CallHandlerByIndex(int iHandlerIndex, int b, int c);
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
void __cdecl AlignAndAdvance(char flags, int aiCount, int aiIndex, int* p);
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
void __cdecl InitSplitChunks(int a1, int aiTotal, int a3, int a4, int a5, SplitChunk* out);
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
void __cdecl SwapBytesAndAdvance(int iByteCount, unsigned char** ppBuffer);
void __cdecl FillInterpolatedValues(int count, float** array, float first, float last);
unsigned int __cdecl hkaSplineCompressedAnimation_handleEndianKnots(unsigned char a1, unsigned int* a2);
int __cdecl hkaSplineCompressedAnimation_handleEndianScalarControlPoints(unsigned char a1, unsigned int a2, unsigned int a3, unsigned int* a4);
void __cdecl Object_UpdateFields_00e31740(unsigned char flag, unsigned int uiValue, unsigned int* puiOut);
int __cdecl hkaSplineCompressedAnimation_handleEndianKnots(int a, int* c);
void __cdecl AlignAndAdvance(int a, int result, int b, int* c);
void __cdecl Object_UpdateFields_00e31780(int a, int b, int* c);
int __cdecl FindKeyInterval(int aiLowIndex, int aiHighIndex, unsigned char key, unsigned char* aucTable);
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
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct S_00e3ae70_Item
{
    int unk00;
    int unk04;
    int unk08;
    float m_0c;
    float m_10;
};
struct S_00e3ae70_cls
{
    void CollectSlotValues(unsigned int a1, unsigned int a2, hkArray<S_00e3ae70_Item*>* pOut);
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
inline hkRefPtrE_blk_00e20000_o2_rtm_variant::~hkRefPtrE_blk_00e20000_o2_rtm_variant()
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
struct hkStringPtrE
{
    const char* m_pcText;
    ~hkStringPtrE();
};
struct Pair8
{
    int unk00;
    hkStringPtrE m_name;
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
    hkArray<hkRefPtrE_blk_00e20000_o2_rtm_variant> m_28;
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
// Probe for 0x00e29900: does cl 15.00.30729.01 /GL + /LTCG deliver this
// wrapper's pointer argument in EAX, so the body compiles to
//   50              push eax
//   e8 xx xx xx xx  call ?__time64@@YA_JPA_J@Z
//   83 c4 04        add esp, 4
//   c3              ret
// (original bytes at 0x00e29900: 50 e8 d4 14 0a 00 83 c4 04 c3)?
// Without /GL the cdecl stack parameter forces "mov eax,[esp+4]" first,
// which the original does not have.
__int64 __cdecl __time64(__int64* t);
static __int64 Object___time64_Thunk(__int64* t);
__int64* volatile g_ptr;
__int64 probe_caller(void);
typedef __int64 (*probe_fn)(void);
probe_fn volatile g_keep = probe_caller;
int main(void)
{
    g_ptr = 0;
    probe_fn f = g_keep;
    return (int)f();
}
void __cdecl nullsub_333();
extern "C" unsigned int be_arg_src_e2f9(void);
volatile unsigned int g_be_sink_e2f9;
static unsigned int SwapByteOrder(unsigned int x);
void call_byteswap_e2f9(void);
unsigned char __cdecl ScaleToByte(float fMin, float fScaledValue, float fValue);
extern "C" double __cdecl fabs(double);
inline float S00e311f0_abs(float x)
{
    float result = (float)fabs(x);
    return result;
}
struct S00e311f0_V
{
    float m[4];
};
struct S00e311f0_PA
{
    const S00e311f0_V* value;
    const S00e311f0_V* operator->() const
    {
        return value;
    }
};
struct S00e311f0_PB
{
    const S00e311f0_V* value;
    const S00e311f0_V* operator->() const
    {
        return value;
    }
};
struct S00e311f0_T
{
    float value;
    operator float() const
    {
        return value;
    }
};
unsigned char __cdecl hkaSplineCompressedAnimation_isStatic(S00e311f0_PA a, S00e311f0_PB b, const S00e311f0_V* c, S00e311f0_T eps,
                                   const S00e311f0_V* d);
namespace se34af0 {

// @fnv 0x00e34af0
// src: XBOX_PDB 0x00e34af0
float delta_hkConvertEndianF32(float fValue)
{
    union
    {
        float f;
        unsigned int ui;
        unsigned char auc[4];
    } kSwap;

    kSwap.f = fValue;
    unsigned int uiBits = kSwap.ui;
    kSwap.auc[0] = (unsigned char)(uiBits >> 24);
    kSwap.auc[1] = (unsigned char)(uiBits >> 16);
    kSwap.auc[2] = (unsigned char)(uiBits >> 8);
    kSwap.auc[3] = (unsigned char)uiBits;
    return kSwap.f;
}

}
extern "C" unsigned short stub_val_e34b20(void);
static unsigned short delta_hkConvertEndianU16(unsigned short v);
unsigned short call_e34b20();
#include <xmmintrin.h>
struct WheelComponentParamsX
{
    float m_fSphereRadius;
};
struct FrictionDescX
{
    float m_fFrictionEqualizer, m_fMaxVelocityForPositionalFriction, m_a0, m_a1, m_a2, m_a3, m_a4, m_a5;
    float m_b0, m_b1, m_b2, m_b3, m_b4, m_b5, m_b6, m_b7;
    float m_c0, m_c1, m_c2, m_c3, m_c4, m_c5, m_c6, m_c7;
    float m_d0, m_d1, m_d2, m_d3, m_d4, m_d5, m_d6, m_d7;
    float m_e0, m_e1, m_e2, m_e3, m_e4, m_e5, m_e6, m_e7;
    float m_f0, m_f1, m_f2, m_f3, m_f4, m_f5, m_f6, m_f7;
    float m_g0, m_g1, m_g2, m_g3, m_g4, m_g5, m_g6;
};
struct FUN_00e39da0 : hkReferencedObject
{
    hkVector4 m_kGravity;
    signed char m_iWheelCount;
    hkRotation m_kChassisOrientation;
    float m_fChassisMass;
    float m_fTorqueMax;
    float m_fTorqueMin;
    float m_fTorqueFactor;
    float m_fTorquePitchFactor;
    float m_fTorqueRollFactor;
    float m_fTorqueYawFactor;
    float m_fExtraTorqueFactor;
    float m_fChassisUnitInertiaRoll;
    float m_fChassisUnitInertiaPitch;
    float m_fChassisUnitInertiaYaw;
    hkArray<WheelComponentParamsX> m_kWheelParams;
    hkArray<signed char> m_kNumWheelsPerAxle;
    FrictionDescX m_kFrictionDescription;
    hkVector4 m_vChassisUnitInertiaAndMassInv;
    hkBool m_bWheelsUseChassisForGround;
    FUN_00e39da0();
};
struct FUN_00e39e50_cls
{
    __m128 m_v0;
    __m128 m_v1;
    FUN_00e39e50_cls* __thiscall InitializeFields_00e39e50();
};
extern float DAT_010d0c80;
struct S3b010Links
{
    volatile unsigned short unk00;
    int unk04;
    int unk08;

    void hkpBridgeConstraintAtom_init(void* arg);
};
struct S3b010Obj
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;
    S3b010Links m_0c;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    volatile float unk24;
    float unk28;
    float unk2c;

    void* hkpStiffSpringChainData_hkpStiffSpringChainData();
};
extern int DAT_010e11ec;
struct M3
{
    V4 c0;
    V4 c1;
    V4 c2;

    void setIdentity()
    {
        c0.setZero();
        c1.setZero();
        c2.setZero();
        c0(0) = 1.0f;
        c1(1) = 1.0f;
        c2(2) = 1.0f;
    }
};
struct FUN_00e3b5c0
{
    int m_vtbl00;
    unsigned short unk04;
    volatile unsigned short m_06;
    volatile int m_08;
    int m_0c;
    volatile unsigned short m_10;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1c;
    M3 m_rot20;
    M3 m_rot50;
    unsigned short m_80;
    unsigned char m_82;
    unsigned char m_83;

    FUN_00e3b5c0();
};
namespace se3b790 {

struct Cell
{
    unsigned char m_aucFlags[48];
};

struct CellInfo
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int m_iIndex;
};

struct CellArray
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    Cell* m_pkCells;
};

struct Grid
{
    int unk000;
    int unk004;
    int unk008;
    CellInfo* m_pkInfo;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    CellArray* m_pkArray;
};

inline void SetPair(Cell* pkCell, int iByte, int iPair, unsigned char ucValue)
{
    int iShift = iPair * 2;
    pkCell->m_aucFlags[iByte] =
        (pkCell->m_aucFlags[iByte] & ~(unsigned char)(3 << iShift)) | (unsigned char)(ucValue << iShift);
}

// @fnv 0x00e3b790
// src: GUESS 0x00e3b790 (confidence: high)
void Runtime_ClearCellBitPair(Grid* pkGrid, int iByte, int iPair)
{
    Cell* pkCell = &pkGrid->m_pkArray->m_pkCells[pkGrid->m_pkInfo->m_iIndex];
    SetPair(pkCell, iByte, iPair, 0);
}

}
namespace se3d200 {

struct Mesh
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    unsigned short* m_pusIndices;

    void ProcessState_00e3cd50(int iV0, int iV1, int iV2, float fValue, int iArg0, int iArg1, int iArg2);
    void ForwardCall_00e3d200(int iTri, float fValue, int iArg0, int iArg1, int iArg2);
};

// @fnv 0x00e3d200
// src: GUESS 0x00e3d200 (confidence: low)
void Mesh::ForwardCall_00e3d200(int iTri, float fValue, int iArg0, int iArg1, int iArg2)
{
    ProcessState_00e3cd50(m_pusIndices[iTri] * 3, m_pusIndices[iTri + 1] * 3, m_pusIndices[iTri + 2] * 3, fValue, iArg0, iArg1,
                 iArg2);
}

}
namespace ns_e3e8 {
int __cdecl CompareStringsCaseInsensitive(const char* a, const char* b) throw();
}
struct Resource_e3e8
{
    const char* FUN_00d46d40() throw();
    void FUN_00c905b0() throw();
};
template <class T> struct hkRefPtr_e3e8
{
    T* m_pRetainedObject;
    ~hkRefPtr_e3e8() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
    }
    T* hkRefVariant_getClass() throw();
    T* val() const
    {
        return m_pRetainedObject;
    }
};
hkRefPtr_e3e8<Resource_e3e8> __stdcall FindWorldByKey(const char* name) throw();
Resource_e3e8* __stdcall Object_FindNamedWorldWithExpectedType(const char* name, Resource_e3e8* expected);
struct S_00e3f280_Entry
{
    int unk00;
    int unk04;
};
struct S_00e3f280_Class
{
    int unk00;
    int unk04;
    S_00e3f280_Entry* unk08;

    int __thiscall GetMaskedValue0xfffffffe(int index);
    int __thiscall GetEntryValue(int index);
};
int S_00e3f280_Class::GetEntryValue(int index)
{
    return unk08[index].unk04 & 0xfffffffe;
}
struct FUN_00e22d50
{
    virtual ~FUN_00e22d50();
    void operator delete(void* p)
    {
        GetMemoryRouter().heap().blockFree(p, 0x30);
    }
};

// @fnv 0x00e3a360
hkpTyremarksInfo::~hkpTyremarksInfo() throw()
{
    for (int i = 0; i < m_kTyremarksWheels.m_iElementCount; i++)
        m_kTyremarksWheels.m_data[i]->removeReference();

    hkMemoryAllocator& kAlloc = hkMemoryRouter_getInstance()->heap();
    m_kTyremarksWheels.m_iElementCount = 0;
    if ((m_kTyremarksWheels.m_iCapacityState & 0x80000000) == 0)
        kAlloc.bufFree(m_kTyremarksWheels.m_data,
                            (m_kTyremarksWheels.m_iCapacityState & 0x3fffffff) * sizeof(hkpTyremarksWheel*));
    m_kTyremarksWheels.m_data = 0;
    m_kTyremarksWheels.m_iCapacityState = 0x80000000;
}
struct Owner_e3f4e0 : hkReferencedObject
{
    hkArray<int> m_entries;
    Owner_e3f4e0();
    virtual ~Owner_e3f4e0();
};
struct S_00df8990_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    signed char unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    unsigned char unk3c;
};
struct CastOutput
{
    int* vtable;
    float fraction;
    int shape08;
    int shape0c;
    int shape10;
    int shape14;
    int shape18;
};
struct __declspec(align(16)) CastCollector
{
    int* vtable00;
    int* vtable04;
    int* vtable08;
    int* vtable0c;
    int value10;
    float fraction14;
    unsigned char hit18;
    S_00df8990_Obj* owner1c;
    S_00df8990_Obj* owner20;
    int shape24;
    int shape28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int extra50;
    int adjusted54;
    int unk58;
    int unk5c;
    CastOutput* output60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
};
extern int DAT_010dbaf8, DAT_010dbae4, DAT_010dbad8, DAT_010dbacc, DAT_010dbb04;
void __cdecl hkKdTreeUtils_castRayIterative(void*, void*, S_00df8990_Obj*, void*, void*);
void __cdecl hkTreeRayCastJobUtil_castRayKdTree(void* caster, S_00df8990_Obj* source, int value, CastOutput* output);
void __cdecl nullsub_334();
void Runtime_DoNothing_00e2cfd0();
#include <xmmintrin.h>
float __cdecl Object_GetGlobalValue_00e52f40();
float __cdecl Runtime_GetField010ec960();
float __cdecl Object_GetGlobalValue_00e52f60();
float __cdecl Runtime_GetField010ec964();
float __cdecl Object_GetDAT_010ec968_00e52f80();
float __cdecl Runtime_GetDAT0104da4c();
float __cdecl hkaSplineCompressedAnimation_TrackCompressionParams_approximateQuantizationAccuracy(int type);
float __cdecl Object_ComputeValue_00e32ea0(int type);
extern "C" void _ReadWriteBarrier(void);
struct Chain
{
    int unk00;
    int value;
    int unk08;
    Chain* next;
};
struct __declspec(align(16)) Node
{
    Vec4 vector;
    float value;
    int id;
    int unk18;
    int unk1c;
    int chainValues[12];
    Chain* tail;
    int unk54;
    int unk58;
    int unk5c;
};
template <class T> struct Cell
{
    T data;
    __forceinline Cell()
    {}
    __forceinline Cell(T item) : data(item)
    {}
    __forceinline void operator=(T item)
    {
        data = item;
    }
    __forceinline T get() const
    {
        return data;
    }
    __forceinline operator T() const
    {
        return get();
    }
    __forceinline T operator->() const
    {
        return get();
    }
};
struct Manager
{
    int unk00;
    int unk04;
    Cell<Node*> base;
    Cell<Node*> current;
    Cell<int> capacity;
    Cell<int> used;
    Cell<Chain*> tail;
};
void __cdecl Runtime_ProcessEntries_00e2b9b0(Chain* chain, Node* source, Manager* manager);
extern "C" void _ReadWriteBarrier();
struct PlaneIndex
{
    unsigned short value;
};
struct PackedPlane
{
    unsigned int x, y, z;
    union
    {
        unsigned int w;
        struct
        {
            unsigned short low;
            PlaneIndex left;
        };
    };
    unsigned short flags;
    PlaneIndex extra;
    PackedPlane()
    {
        flags = 0;
    }
};
struct WorkItem
{
    PackedPlane plane;
    PackedPlane* node;
    int side;
    int count;
};
struct PlaneList
{
    PackedPlane* data;
    PackedPlane* GetEntryOffset(PlaneIndex index) throw();
};
struct SplitInput
{
    int unk00, unk04, unk08, unk0c;
    PackedPlane* root;
    int unk14, unk18;
    PlaneList nodes;
};
hkMemoryRouter* hkStackMemory_getInstance() throw();
void Object_ProcessEntries_00e2c100(SplitInput*, PackedPlane*, PackedPlane*, int, int, int, int, int, float*, int*, int, int, int, int,
                  int*, int*, int*, int*, PackedPlane*, PackedPlane*) throw();
struct WorkStack
{
    WorkItem* data;
    int size;
    static __forceinline void initialize(WorkItem* ptr, int length)
    {
        for (int j = 0; j < length; ++j)
            new (ptr + j) WorkItem;
    }
    __forceinline WorkItem* expand(int amount)
    {
        int old = size;
        size = old + amount;
        initialize(data + old, size - old);
        return data + old;
    }
};
struct WorkArray : hkArrayBase<WorkItem>   // hkLocalArray<WorkItem> (fields set by hand)
{
    WorkItem* localMemory;
    static __forceinline void initialize(WorkItem* ptr, int length)
    {
        for (int j = 0; j < length; ++j)
            new (ptr + j) WorkItem;
    }
    __forceinline WorkItem* expand(int amount)
    {
        int old = m_iElementCount;
        m_iElementCount = old + amount;
        initialize(m_data + old, m_iElementCount - old);
        return m_data + old;
    }
};
void hkAabbTreeRayCastUtil_struct_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_castRayFiltering(SplitInput* input, int a2, int a3, int a4, int a5, int a6, int count);
#include <xmmintrin.h>
namespace FanSpace {
// Exe 0x00e2d1b0 FanBuilder::FUN_00e2d1b0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m[4];
} __m128, LocalM128;
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_rsqrt_ss(LocalM128);
extern "C" LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_set_ss(float);
extern "C" void _mm_store_ss(float*, LocalM128);
struct SimdScalar
{
    union
    {
        LocalM128 q;
        float values[4];
    };
    SimdScalar(LocalM128 x) : q(x)
    {}
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, q);
        return f;
    }
    __forceinline LocalM128 splat() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
struct FanVec
{
    union
    {
        LocalM128 q;
        float values[4];
    };
    __forceinline void subtract(const FanVec& a, const FanVec& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void cross(const FanVec& a, const FanVec& b)
    {
        LocalM128 p = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        LocalM128 r = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(p, r);
    }
    __forceinline SimdScalar dot(const FanVec& b) const
    {
        LocalM128 prod = _mm_mul_ps(q, b.q);
        LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
        return _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), xy);
    }
    __forceinline SimdScalar inverseLength() const
    {
        LocalM128 half = _mm_set_ss(0.5f);
        LocalM128 three = _mm_set_ss(3.0f);
        LocalM128 zero = _mm_set_ss(0.0f);
        LocalM128 len = dot(*this).q;
        LocalM128 mask = _mm_cmpeq_ss(len, zero);
        LocalM128 estimate = _mm_rsqrt_ss(len);
        LocalM128 val =
            _mm_mul_ss(_mm_mul_ss(half, estimate), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, estimate), estimate)));
        return _mm_andnot_ps(mask, val);
    }
    __forceinline void normalize()
    {
        q = _mm_mul_ps(inverseLength().splat(), q);
    }
};
template <class T> struct FanPad
{
    T value;
    FanPad()
    {}
    FanPad(T v) : value(v)
    {}
    __forceinline operator T() const
    {
        return val();
    }
    __forceinline T operator->() const
    {
        return value;
    }
    __forceinline void operator=(T v)
    {
        value = v;
    }
    __forceinline T val() const
    {
        return value;
    }
};
struct FanEdge;
struct FanVertex
{
    FanVec position;
    FanVec pointA;
    FanVec pointB;
    FanPad<FanEdge*> referee;
};
struct FanTriangle;
struct FanEdge
{
    FanVertex* vertex;
    FanEdge* next;
    FanEdge* twin;
    FanTriangle* triangle;
};
struct FanTriangle
{
    FanVec normal;
    FanEdge edges[3];
    float distance;
    int state;
    __forceinline int plane(const FanVec& a, const FanVec& b, const FanVec& c)
    {
        FanVec x;
        x.subtract(a, b);
        FanVec y;
        y.subtract(b, c);
        FanVec n;
        n.cross(x, y);
        if (float(n.dot(n)) == 0.0)
            return 1;
        n.normalize();
        distance = a.dot(n);
        normal.q = n.q;
        return 0;
    }
};
struct FanBuilder
{
    FanPad<float> tolerance;
    FanPad<float> previous;
    FanPad<int> numVertices;
    FanPad<int> numFree;
    FanPad<int> numTriangles;
    FanVertex vertices[55];
    FanTriangle* freeTriangles[100];
    FanTriangle triangles[100];
    __forceinline FanTriangle* allocateOne()
    {
        FanTriangle* t = &triangles[numTriangles];
        numTriangles = numTriangles + 1;
        return t;
    }
    __forceinline void allocate(int n, FanTriangle** result)
    {
        int i = 0;
        for (int f = numFree - 1; n != 0 && f >= 0; --f)
        {
            result[i++] = freeTriangles[f];
            numFree = numFree - 1;
            --n;
        }
        for (int j = 0; j < n; ++j)
        {
            FanTriangle* q = &triangles[numTriangles];
            numTriangles = numTriangles + 1;
            result[i++] = q;
        }
    }
    __forceinline int initialize(FanTriangle** t, int count, FanEdge* chain, FanVertex*& apex)
    {
        FanEdge* current = chain;
        for (int i = 0; i < count; ++i)
        {
            if (current == 0)
                return 2;
            FanTriangle* tri = t[i];
            FanTriangle* nextTri;
            if (i + 1 < count)
                nextTri = t[i + 1];
            else
                nextTri = t[0];
            tri->edges[0].triangle = tri;
            tri->edges[1].triangle = tri;
            tri->edges[2].triangle = tri;
            tri->edges[0].next = &tri->edges[1];
            tri->edges[1].next = &tri->edges[2];
            tri->edges[2].next = &tri->edges[0];
            FanVertex* a = current->next->vertex;
            FanVertex* b = current->vertex;
            tri->edges[0].vertex = a;
            tri->edges[1].vertex = b;
            tri->edges[2].vertex = apex;
            current->twin = &tri->edges[0];
            tri->edges[0].twin = current;
            nextTri->edges[1].twin = &tri->edges[2];
            tri->edges[2].twin = &nextTri->edges[1];
            if (tri->plane(a->position, b->position, apex->position))
                return 2;
            FanVertex* last = current->next->vertex;
            FanEdge* following = last->referee;
            last->referee = 0;
            current = following;
        }
        for (int j = 0; j < numTriangles; ++j)
            triangles[j].state = 0;
        for (int k = 0; k < numVertices; ++k)
            vertices[k].referee = 0;
        return chain == current ? 0 : 2;
    }
    int AllocateTriangleFan(int count, FanEdge* chain, FanVertex* apex);
};
// @fnv 0x00e2d1b0
// src: GUESS 0x00e2d1b0 (confidence: medium)
int FanBuilder::AllocateTriangleFan(int count, FanEdge* chain, FanVertex* apex)
{
    FanTriangle* fresh[100];
    allocate(count, fresh);
    return initialize(fresh, count, chain, apex);
}
}
#include <xmmintrin.h>
#include <math.h>
extern int DAT_010e00dc;
struct TyremarkWheelView : FUN_00e3a270
{
    TyremarkWheelView* FUN_00e3a270();
    void hkpTyremarksWheel_setNumPoints(int pointCount);
};
inline TyremarkWheelView* allocateTyremarkWheel();
struct TyremarkVehicleView
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    signed char m_iWheelCount;
};

namespace RaySimilarityMath {
typedef FanSpace::LocalM128 LocalM128;
extern "C" LocalM128 _mm_load_ss(const float*);
using FanSpace::_mm_sub_ps;
using FanSpace::_mm_mul_ps;
using FanSpace::_mm_add_ss;
using FanSpace::_mm_shuffle_ps;
using FanSpace::_mm_store_ss;

struct RayScalar
{
    LocalM128 q;
    RayScalar()
    {}
    RayScalar(float f) : q(_mm_load_ss(&f))
    {}
    RayScalar(const LocalM128& v) : q(v)
    {}
    operator float() const
    {
        float f;
        _mm_store_ss(&f, q);
        return f;
    }
};
struct RayVector : FanSpace::FanVec
{
    void setSub(const RayVector& a, const RayVector& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    RayScalar dot3(const RayVector& b) const
    {
        LocalM128 p = _mm_mul_ps(q, b.q);
        LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        p = _mm_shuffle_ps(p, p, 0xaa);
        p = _mm_add_ss(p, xy);
        return RayScalar(p);
    }
    RayScalar lengthSquared3() const
    {
        return dot3(*this);
    }
};
// @fnv 0x00e29920
// src: GUESS 0x00e29920 (confidence: low)
extern "C" bool __cdecl Object_ProcessAndReturnValue_00e29920(const RayVector& a, const RayVector& b, const RayVector& c, const RayVector& d,
                                     const RayVector& e, const RayVector& f, float g, float h)
{
    if (float(c.dot3(f)) < g)
        return false;
    RayScalar limit(h);
    RayVector da, db;
    da.setSub(d, a);
    db.setSub(e, b);
    RayScalar distance0;
    distance0 = da.lengthSquared3();
    if (distance0 > limit)
        return false;
    RayScalar distance1;
    distance1 = db.lengthSquared3();
    if (distance1 > limit)
        return false;
    return true;
}

}
