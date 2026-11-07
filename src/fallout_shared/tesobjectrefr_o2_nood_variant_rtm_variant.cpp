// src/fallout_shared/tesobjectrefr_o2_nood_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/tesobjectrefr_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/fallout_shared/tesobjectrefr_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/fallout_shared/tesobjectrefr.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
#include "tesobjectrefr_decls.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiTransform.h"
#include "../../include/NiMatrix3.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiNode.h"
#include "../../include/hkRotation.h"
#include "../../include/hkTransform.h"
#include "../../include/hkQuaternion.h"
#include "../../include/hkVector4.h"
GarbageCollectorUpdateState* MemoryLevelManager_GetSingleton();
void* DecalData_GetDefaultDecalData();
void FalloutRadio_NewCellEntered();
void TESWaterSystem_SetPlayerForceUnderwater(unsigned char value);
float BSAudio_GetMinDialogDist();
float BSAudio_GetMaxDialogDist();
void CheckWithinMultiBoundTask_CancelAttachment(unsigned int index);
extern "C" __declspec(thread) int tls_state;
struct MemContextGuard
{
    int m_iOld;
    MemContextGuard(int aiMemoryContext)
    {
        m_iOld = tls_state;
        tls_state = aiMemoryContext;
    }
    ~MemContextGuard()
    {
        tls_state = m_iOld;
    }
};
class GlobalObjectO2_00a7b610
{
  public:
    const char* m_pcName;
    const GlobalObjectO2_00a7b610* m_pBaseRTTI;
    const char* GetName() const
    {
        return m_pcName;
    }
};
extern GlobalObjectO2_00a7b610 g_01268224;
char* NiViewerStrings_NiGetViewerString_Title(const char* pcText);
void HK2NI_00624b10(NiMatrix3* pkOut, const hkRotation* pkIn);
void FUN_00458620(NiPoint3* pkOut, const hkVector4* pkIn);
struct Arg_00c9f830
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    __m128 unk20;
    __m128 unk30;
};
struct Obj_00c9f830
{
    void FillOutputFromState(Arg_00c9f830* value);
    void bhkAabbPhantom_GetAabb(__m128* value);
    void bhkAabbPhantom_CopyCinfo(Arg_00c9f830* value);
};
extern __m128 DAT_01267e30;
extern __m128 DAT_010c71b0;
void __stdcall FUN_00cb31a0_sub_a(__m128* p);
struct FUN_00cb31a0_cls
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    __m128 m_20;
    __m128 m_30;
    __m128 m_40;

    void Sub_b(__m128* p);
    void Sub_c(FUN_00cb31a0_cls* p);
    void bhkRigidBodyT_PostInit(FUN_00cb31a0_cls* src);
};
struct Sub
{
    unsigned int m_00;
};
struct Arg;
struct Cls
{
    char pad[0x20];
    Sub m_20;
    void FUN_00c8d130(__m128* out);
    Arg* bhkRigidBodyT_GetRotation(Arg* arg);
};
struct Arg
{
    void setMulInverse(__m128* out, Sub* sub);
};
class S00cb3250_Object
{
  public:
    void FUN_00c8d1a0(hkQuaternion* pQuery);
    void bhkRigidBodyT_SetRotation(int iArg);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int m_kOwner;
};
struct RotationResult
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
    __m128 translation;
    void hkRotation_set(const __m128*);
};
struct ShapeFrame
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
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void GetTranslation(__m128*);
    virtual void GetRotation(__m128*);
    RotationResult* bhkRigidBodyT_GetTransform(RotationResult*);
};
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern unsigned long DAT_0126fd98;
struct F9_Alloc
{
    virtual void slot0();
    virtual void* alloc(int bytes);
};
struct F9_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    F9_Alloc* m_pStreamAllocator;
    F9_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
};
F9_Router* __cdecl hkMemoryRouter_getInstance();
struct F9_Ctx
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
    int unk2b4;
};
extern __declspec(thread) F9_Ctx F9_tls;
struct F9_Scope
{
    int saved;
    F9_Scope()
    {
        saved = F9_tls.unk2b4;
        F9_tls.unk2b4 = 0x10;
    }
    ~F9_Scope()
    {
        F9_tls.unk2b4 = saved;
    }
};
struct F9_Mat
{
    __m128 c0;
    __m128 c1;
    __m128 c2;
    __m128 c3;
    void hkRotation_renormalize();
};
struct F9_Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m[16];
};
struct F9_Obj
{
    int unk00;
    short unk04;
    short unk06;
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
    F9_Obj(int a, const F9_Mat* m, int b);
    void FUN_00c905b0();
    static void* operator new(unsigned int n)
    {
        F9_Alloc& h = hkMemoryRouter_getInstance()->heap();
        void* p = h.alloc((int)n);
        ((F9_Obj*)p)->unk04 = (short)n;
        return p;
    }
    static void operator delete(void*)
    {}
};
struct F9_Owner
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void add(F9_Obj* o);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void post(F9_Arg* a);
    void bhkSimpleShapePhantom_Init(F9_Arg* arg);
};
struct PositionSource
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_vContactPosition;
};
extern const char str_010c40a0[];
NiAVObject* __cdecl BSTestObjects_CreateBox_0(const NiPoint3* pkPosition, int iFlags);
struct PositionOwner
{
    int unk00;
    int unk04;
    PositionSource* m_pkSource;
    void bhkBoxShape_BuildDisplayGeometry(NiNode* pkParent, int iUnused);
};
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_setzero_ps();
struct Vec16Helper
{
    void hkVector4_setRotatedDir(char* a, void* b);
};
struct Obj08
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __m128 m_20;
    void hkpCharacterProxy_setPosition(__m128* v);
    void bhkCharacterController_UnMarkWrite();
};
struct Obj570
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
};
struct Obj594
{
    int unk00;
    int unk04;
    char* m_08;
};
class MotionObject
{
  public:
    int unk0000;
    int unk0004;
    Obj08* m_08;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    Obj570 m_570;
    Obj594* m_594;
    void bhkCharacterController_UnMarkWrite();
    void bhkCharacterController_SetPosition(__m128* v);
};
extern "C" __m128 _mm_setzero_ps(void);
struct C9FA20_TlsBlock
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    unsigned int m_2b4;
};
extern __declspec(thread) C9FA20_TlsBlock g_c9fa20Tls;
struct C9FA20_TlsGuard
{
    unsigned int m_saved;
    C9FA20_TlsGuard()
    {
        m_saved = g_c9fa20Tls.m_2b4;
        g_c9fa20Tls.m_2b4 = 0x10;
    }
    ~C9FA20_TlsGuard()
    {
        g_c9fa20Tls.m_2b4 = m_saved;
    }
};
struct C9FA20_Alloc
{
    void* __thiscall Game_DoHeapAlloc(unsigned int size);
};
extern C9FA20_Alloc DAT_011f6238;
struct C9FA20_Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    C9FA20_Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct C9FA20_Data
{
    int unk00;
    int unk04;
    unsigned char m_08;
    C9FA20_Array m_ppData;
    int unk18;
    int unk1C;
    __m128 m_20;
    __m128 m_30;

    static __forceinline void* operator new(unsigned int size)
    {
        unsigned char* p = static_cast<unsigned char*>(DAT_011f6238.Game_DoHeapAlloc(size + 0x10));
        unsigned char offset = (unsigned char)(0x10 - ((unsigned int)p & 0xf));
        p += offset;
        p[-1] = offset;
        return p;
    }
    static void operator delete(void*)
    {}
    C9FA20_Data()
    {
        unk00 = 0;
        unk04 = 0;
        m_08 = 2;
        m_20 = _mm_setzero_ps();
        m_30 = _mm_setzero_ps();
    }
};
struct C9FA20_Owner
{
    int unk00;
    int unk04;
    int m_08;
    C9FA20_Data* m_pData;
    void bhkAabbPhantom_CopyCinfo(C9FA20_Data* data);
    C9FA20_Data* bhkAabbPhantom_CreateCinfo(bool* created);
};

extern "C"
{
    __m128 _mm_load_ss(const float*);
    __m128 _mm_mul_ps(__m128, __m128);
}

extern "C" void _ReadWriteBarrier(void);

struct ScaleParams
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    float unk10;
};

struct FUN_00cb30d0_cls
{
    virtual void VSlot00();
    virtual void VSlot01();
    virtual void VSlot02();
    virtual void VSlot03();
    virtual void VSlot04();
    virtual void VSlot05();
    virtual void VSlot06();
    virtual void VSlot07();
    virtual void VSlot08();
    virtual void VSlot09();
    virtual void VSlot10();
    virtual void VSlot11();
    virtual void VSlot12();
    virtual void VSlot13();
    virtual void VSlot14();
    virtual void VSlot15();
    virtual void VSlot16();
    virtual void VSlot17();
    virtual void VSlot18();
    virtual void VSlot19();
    virtual void VSlot20();
    virtual void VSlot21();
    virtual void VSlot22();
    virtual void VSlot23();
    virtual void VSlot24();
    virtual void VSlot25();
    virtual void VSlot26();
    virtual void VSlot27();
    virtual void VSlot28();
    virtual void VSlot29();
    virtual void VSlot30();
    virtual void VSlot31();
    virtual void VSlot32();
    virtual void VSlot33();
    virtual void VSlot34();
    virtual void VSlot35();
    virtual void VSlot36();
    virtual void VSlot37();
    virtual void VSlot38();
    virtual void VSlot39();
    virtual void VSlot40();
    virtual void VSlot41();
    virtual void VSlot42();
    virtual void VSlot43();
    virtual void VSlot44();
    virtual void* VSlot45(unsigned char* flag);

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    __m128 m_20;
    __m128 m_30;

    void bhkRigidBodyT_CopyMembers(void* a1, ScaleParams* a2);
    void CopyBodyToClone(void* a1, ScaleParams* a2);
};

// @fnv 0x00cb30d0
// src: XBOX_PDB 0x00cb30d0
void FUN_00cb30d0_cls::bhkRigidBodyT_CopyMembers(void* a1, ScaleParams* a2)
{
    unsigned char flag;
    char* obj = static_cast<char*>(VSlot45(&flag));
    __m128& slot40 = *reinterpret_cast<__m128*>(obj + 0x40);
    __m128& slot30 = *reinterpret_cast<__m128*>(obj + 0x30);
    slot40 = m_20;
    slot30 = m_30;
    _ReadWriteBarrier();

    float scale = a2->unk10;
    if (scale != 1.0f)
    {
        __m128 scalar = _mm_load_ss(&scale);
        __m128 broadcast = _mm_shuffle_ps(scalar, scalar, 0);
        slot30 = _mm_mul_ps(broadcast, slot30);
    }

    CopyBodyToClone(a1, a2);
}

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);

extern const __m128 DAT_010c71e0;

// Havok's inline default constructor leaves the quaternion uninitialized.
inline hkQuaternion::hkQuaternion()
{}

inline const hkVector4& hkQuaternion::getImag() const
{
    return *reinterpret_cast<const hkVector4*>(this);
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

__forceinline void hkVector4::setBroadcast3(const hkVector4& v)
{
    m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
}

__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    qreal.setBroadcast3(quat.getImag());
    hkVector4 q2minus1;
    q2minus1.m_vComponents = _mm_add_ps(_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(q2minus1, direction);
    hkVector4 imagDotDir;
    const __m128 x2 = _mm_mul_ps(quat.getImag().m_vComponents, direction.m_vComponents);
    const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    imagDotDir.m_vComponents = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    imagDotDir.m_vComponents = _mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(imagDotDir, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

class RigidMotionDAD
{
  public:
    void SetPosRot(const hkVector4& position, const hkQuaternion& rotation);
    void bhkRigidBodyT_SetPosRot(const hkVector4& position, const hkQuaternion& rotation);

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkQuaternion m_localRotation;
    hkVector4 m_localTranslation;
};

// Preserve the original stack protection for address-taken SIMD temporaries.
#pragma strict_gs_check(push, on)
// @fnv 0x00cb3570
// src: XBOX_PDB 0x00cb3570
void RigidMotionDAD::bhkRigidBodyT_SetPosRot(const hkVector4& position, const hkQuaternion& rotation)
{
    hkVector4 newPosition;
    newPosition.SetRotatedDirection(rotation, m_localTranslation);
    hkVector4 worldPosition;
    worldPosition.setAdd4(newPosition, position);
    __declspec(align(16)) hkQuaternion newRotation;
    newRotation.setMul(rotation, m_localRotation);
    newRotation.normalize_005611c0();
    SetPosRot(worldPosition, newRotation);
}
#pragma strict_gs_check(pop)
