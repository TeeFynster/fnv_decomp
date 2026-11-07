
// src/staging/blk_00500000_od_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00515040: the skeleton of src/staging/blk_00500000_od_rtti_variant.cpp
// with declarations corrected to what the original code does (unit: struct Actor : public ActorVTable { virtual bool ActorCh -> class ActorValueOwner { public: virtual void AVO00(); ). Move the function to its real unit once
// that unit declares it this way.

// src/staging/blk_00500000_od_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESObjectREFR). The skeleton of src/staging/blk_00500000_od.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
// src/staging/blk_00500000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/Actor.h"
#include "../../include/ActorValueOwner.h"
#include "../../include/BGSImpactData.h"
#include "../../include/BGSTerrainManager.h"
#include "../../include/PathingRequest.h"
#include "../../include/TESObjectMISC.h"
#include "../../include/BSFaceGenMorphData.h"
#include "../../include/GO.h"
#include "../../include/NiUpdateData.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint4.h"
#include "../../include/StrMem.h"
#include "../../include/Setting.h"
#include "../../include/TESObject.h"
#include "../../include/TESObjectREFR.h"
struct FUN_00505c20_class
{
    unsigned char GetByteAtOffset9A();
};
struct NiNode;
struct FUN_00507550_Class
{
    void ParticleShaderProperty_SetTexture0x118(void* p);
};
struct FUN_00507570_Class
{
    void ParticleShaderProperty_SetLifetimeVar(float value);
};
struct FUN_005076c0Class
{
    void __thiscall PathingRequestCoveredMove_SetAttackerHealth(float value);
};
struct FUN_005076e0_Class
{
    void SetFieldAtOffsetF4_005076e0(float value);
};
struct FUN_00507720_Class
{
    void __thiscall SetFieldAtOffset100_00507720(float value);
};
struct FUN_00507740_Class
{
    void ParticleShaderProperty_SetBlendOp(int value);
};
struct FUN_00507760_Class
{
    void ParticleShaderProperty_SetZTestFunc(int value);
};
struct FUN_00507780
{
    void SetBoltsRadiusStrength(float value);
};
struct FUN_005077a0_Class
{
    void BoltShaderProperty_SetSegmentVariance(float value);
};
struct Flt
{
    operator unsigned int();
};
struct FUN_00507d80_Class
{
    unsigned int FOPipboyManager_Get3rdPersonPipboyRoot();
};
struct FUN_00508050_Class
{
    float GetFieldAtOffset44();
};
extern "C" void __cdecl _ref_006815c0();
struct FUN_00509890_class
{
    void __thiscall _ref_006815c0();
    void* __thiscall UpdateState_00509890(bool);
};
struct FUN_0050d1d0_class
{
    bool IsFlag8Set() const;
};
struct FUN_0050d1f0_Class
{
    bool __thiscall TESObjectLIGH_GetFlickerSlow() const;
};
struct FUN_0050d210_Class
{
    bool IsFlag80Set() const;
};
struct FUN_0050d230_class
{
    bool TESObjectLIGH_GetPulseSlow() const;
};
struct FUN_00510110_class
{
    void ProcessEntries_005102e0();
    void ForwardCall_00510110();
};
struct FUN_00510360_Class
{
    void* TESObjectList_lnk_GetNext(TESObject* p);
};
struct FUN_00510380_Class
{
    unsigned int __thiscall GetTerrainMinLevel(BGSTerrainManager* a);
};
extern "C" int __cdecl _BSStringLength(const char*);
struct FUN_005103a0_class
{
    void __thiscall FindSubstring(const char* a, const char* b, int c);
    void __thiscall ProcessState_005103a0(const char* a, const char* b);
};
extern "C" int __cdecl _memcmp(const void* s1, const void* s2, unsigned int n);
void __cdecl std_char_traits_char_compare(const void* s1, const void* s2, unsigned int n);
extern "C" void* __cdecl FUN_00eca2e0(void* p, int c, size_t n);
void __cdecl std_char_traits_char_assign_005104d0(void* p, size_t n, char* c);
// Exe 0x00515040: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct BlkOffset08View
{
    unsigned int GetFlags();
    unsigned int HasFlag10000000();
};
struct FUN_00519020_Class
{
    void SetField688(int value);
};
struct FUN_008256d0_list
{
    bool FUN_008256d0();
};
struct FUN_005194d0_shell_base
{
    bool IsRandomDoor();
};
extern "C" void* DAT_0102b3d0;
struct FUN_00519b20_cls
{
    void* m_p;
    void __thiscall ConstructArray(void* arg);
    void* __thiscall InitializeFields_00519b20(void* arg);
};
extern "C" unsigned int __cdecl UpdateFields_00c5faa0(void*);
struct Unk_00a5e930
{
    unsigned int __thiscall UpdateFields_00c5faa0();
};
struct FUN_0051cfe0_Class
{
    unsigned int __thiscall ForwardCall_0051cfe0();
};
struct FUN_0051f4d0_class
{
    unsigned int GetField1CC();
};
struct FUN_0051f4f0_Class
{
    void UpdateState_0051f4f0(int value);
};
struct FUN_0051f530_class
{
    void __thiscall TESObjectWEAP_SetVATSEffect(int value);
};
extern "C" void* __cdecl _NiFreeAlias(void*);
extern void* DAT_0102b3f0;
struct FUN_00519c50_class
{
    void* pVft;
    int _0x4;
    void* _0x8;
    void __thiscall NiTPointerMap_RemoveAll();
    void __thiscall ReleaseStorage_00519c50();
};
extern "C" void __cdecl _Deallocate(void*);
void __cdecl FUN_005010f0();
struct FUN_005010c0_class
{
    void __thiscall FUN_005010f0();
    void* __thiscall FUN_005010c0(unsigned int flags);
};
struct FUN_00507660_class
{
    void ParticleShaderProperty_SetColor2(NiPoint4 p);
};
void __cdecl Deallocate(void*);
struct FUN_00519b50_class
{
    void __thiscall FUN_00519bf0();
    void* __thiscall FUN_00519b50(unsigned int flags);
};
struct FUN_00519c50_class;
void __cdecl _Deallocate(void* p);
struct FUN_00519c80_class
{
    void* __thiscall FUN_00519c80(unsigned int flags);
};
struct FUN_00501cd0_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    unsigned int m_10;
    void* m_14;
    void* __thiscall DoorLock_DoorLock();
};
struct TESForm;
TESForm* __cdecl GetFormByID(unsigned int id);
TESForm* __cdecl TESCombatStyle_GetDefaultCombatStyle();
struct FUN_00507590_Data
{
    float a;
    float b;
    float c;
};
struct FUN_00507590_Class
{
    void __thiscall SetData(FUN_00507590_Data v);
};
struct Vec12_5075c0
{
    int x;
    int y;
    int z;
};
struct S5075c0
{
    void __thiscall ParticleShaderProperty_SetAcceleration(Vec12_5075c0 v);
};
struct FUN_00507630_Cls
{
    unsigned char _pad[0xC4];
    NiPoint4 fld;
    void __thiscall SetPoint(NiPoint4 p);
};
struct FUN_00507690_Class
{
    char _pad[0xe4];
    NiPoint4 m_0xe4;
    void __thiscall ParticleShaderProperty_SetColor3(NiPoint4 v);
};
struct FUN_00508100_shell
{
    float GetEndKeyTime_00508100();
};
struct FUN_00759450_shell
{
    float NiPSysSpawnModifier_GetLifeSpan();
};
struct FUN_005082b0_shell
{
    void UpdateEnvelope(float, float, float, unsigned char, float, float, float, float, float);
};
struct FUN_00508090_shell
{
    float TESCombatStyle_GetWeaponMinRangeMult() const;
    float GetActorRadius();
    float GetEndKeyTime_00508100();
    float NiControllerSequence_GetLastTime();
    float NiPSysSpawnModifier_GetLifeSpan();
    void UpdateEnvelope(float, float, float, unsigned char, float, float, float, float, float);
    void TESEffectShader_AnimateFillEffectAlpha(float a, float b, float c, unsigned char d);
};
struct FUN_0050e640_Holder
{
    char _0[4];
    unsigned char _4;
    bool __thiscall MatchesValue(unsigned char v);
};
float __cdecl NiSqrt_004579e0(float);
float __fastcall NiNPShortPoint3_Length(short* p);
struct AVH
{
    static int __cdecl GetActorValueForSectionIndex(int, unsigned char);
};
struct FUN_00514fd0_class
{
    int __thiscall TESObjectBOOK_GetTeaches();
};
bool __cdecl TESObjectDOOR_CanBeRandomTeleport(int);
struct LH
{
    bool IsInList(int&);
};
struct FUN_00519500_class
{
    bool HasEntry(int a);
};
void* __cdecl NiMalloc(unsigned int size);
void* __cdecl memset(void* dst, int c, unsigned int n);
struct FUN_00519b20
{
    void* __thiscall ConstructArray(unsigned int n);
};
struct TESGrassBase
{
    TESGrassBase();
    ~TESGrassBase();
    void SetFormType(int);
    unsigned char m_00;
    unsigned char m_01;
    unsigned char m_02;
    unsigned char m_03;
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char m_07;
    unsigned char m_08;
    unsigned char m_09;
    unsigned char m_0a;
    unsigned char m_0b;
    unsigned char m_0c;
    unsigned char m_0d;
    unsigned char m_0e;
    unsigned char m_0f;
    unsigned char m_10;
    unsigned char m_11;
    unsigned char m_12;
    unsigned char m_13;
    unsigned char m_14;
    unsigned char m_15;
    unsigned char m_16;
    unsigned char m_17;
    unsigned char m_18;
    unsigned char m_19;
    unsigned char m_1a;
    unsigned char m_1b;
    unsigned char m_1c;
    unsigned char m_1d;
    unsigned char m_1e;
    unsigned char m_1f;
    unsigned char m_20;
    unsigned char m_21;
    unsigned char m_22;
    unsigned char m_23;
    unsigned char m_24;
    unsigned char m_25;
    unsigned char m_26;
    unsigned char m_27;
    unsigned char m_28;
    unsigned char m_29;
    unsigned char m_2a;
    unsigned char m_2b;
    unsigned char m_2c;
    unsigned char m_2d;
    unsigned char m_2e;
    unsigned char m_2f;
};
struct TESGrassModel
{
    TESGrassModel();
    ~TESGrassModel();
    void* vft;
};
struct FUN_00509a10 : TESGrassBase
{
    TESGrassModel m_30;
    FUN_00509a10();
    void ResetFormData();
};
extern int DAT_01028364;
extern int DAT_01028378;
extern int DAT_0102838c;
extern int DAT_010283a0;
extern int DAT_010283b4;
extern int DAT_010283d4;
extern int DAT_010283e8;
extern int DAT_01028408;
extern int DAT_0102842c;
extern int DAT_01028444;
struct SFTX
{
    void SetFormType(int);
};
struct FUN_0050a5a0 : TESObjectMISC
{
    FUN_0050a5a0();
    void SetFormType(int);
    void SetInitializationState(bool);
};
struct TESObjectREFR_Flags
{
    unsigned int GetFlags();
    void SetFlags(unsigned int flags);
    void MarkAsModified(int change);
    void __thiscall SetRefFlag40000000(bool set);
};
struct S_004ed780
{
    S_004ed780* ProcessAndReturnValue_004ed780(float value);
};
struct FUN_0050e620_S
{
    bool IOTask_SetPriority_Thunk(unsigned char value);
};
struct GlobalObject_0045cf30 : FUN_0050e620_S
{
};
extern unsigned char DAT_011c8fa0;
extern double _DAT_01012060;
extern Setting g_011c8fb0;
extern GlobalObject_0045cf30 g_011c8ff0;
extern GlobalObject_0045cf30 g_011c9028;
extern Setting g_011c9054;
extern GlobalObject_0045cf30 g_011c9060;
extern Setting g_011c906c;
extern Setting g_011c907c;
bool __cdecl InitSettingsDefaults();
struct TESBoundObject;
struct LockExtraData
{
    void* pVft;
    TESBoundObject* pKey;
    bool IsLocked();
};
struct P01RefA
{
    virtual ~P01RefA();  // the original class is polymorphic (rtti_variants.py)
    LockExtraData* GetLock();
};
extern Actor* g_thePlayer;
extern TESBoundObject* g_pLockpickItem;
struct FUN_00516cd0_class
{
    bool __thiscall CanUseLockedRef(TESObjectREFR* ref, Actor* actor, bool useLockpick);
};
int DAT_011c6200;
int FixedStrings_GetArrowQuiver();
struct FUN_00505b80_cls
{
    unsigned char DispatchByType(int aType);
    unsigned char FUN_0073cb80();
    unsigned char TESCombatStyle_GetPowerAttackF();
    unsigned char GetByteAtOffset9A();
    unsigned char GetByteAtOffset9B();
    unsigned char FUN_009e8670();
};
class ThisBase_c40
{
  public:
    virtual ~ThisBase_c40();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;

    ThisBase_c40();
};
class ThisMember18_c40
{
  public:
    ThisMember18_c40();
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    int m_40;
    int m_44;
    int m_48;
    int m_4C;
    int m_50;
    int m_54;
    int m_58;
    int m_5C;
    int m_60;
    int m_64;
    int m_68;
    int m_6C;
    int m_70;
    int m_74;
    int m_78;
    int m_7C;
    int m_80;
    int m_84;
    int m_88;
    int m_8C;
    int m_90;
    int m_94;
    int m_98;
    int m_9C;
    int m_A0;
    int m_A4;
    int m_A8;
    int m_AC;
    int m_B0;
    int m_B4;
    int m_B8;
    int m_BC;
    int m_C0;
    int m_C4;
    int m_C8;
    int m_CC;
    int m_D0;
    int m_D4;
    int m_D8;
    int m_DC;
    int m_E0;
    int m_E4;
    int m_E8;
    int m_EC;
    int m_F0;
    int m_F4;
    int m_F8;
    int m_FC;
    int m_100;
    int m_104;
    int m_108;
    int m_10C;
    int m_110;
    int m_114;
    int m_118;
    int m_11C;
    int m_120;
    int m_124;
    int m_128;
    int m_12C;
    int m_130;
    int m_134;
};
class ThisMemberD_c40
{
  public:
    int m_00;
    int m_04;
    int m_08;

    ThisMemberD_c40();
    ~ThisMemberD_c40();
};
class FUN_00505c40 : public ThisBase_c40
{
  public:
    ThisMember18_c40 m_18;
    ThisMemberD_c40 m_14c;
    ThisMemberD_c40 m_158;
    ThisMemberD_c40 m_164;

    FUN_00505c40();
    virtual ~FUN_00505c40();
    virtual void unk00();
    void CallA_c40(int a1);
    void CallB_c40();
};
class FUN_00507da0_cls
{
  public:
    int unk00;
    float NiAVObject_GetWorldScale();
    float Explosion_GetRadius(float value);
    float BGSProjectile_GetMuzzleFlashDuration(float value);
    float GetField90Float(float value);
    float FUN_0051b8e0(float value);
    void UpdateEnvelope(float a, float b, float c, unsigned char flag, float value);
    void TESEffectShader_BirthParticles(float a, float b, float c, unsigned char flag);
};
extern "C" double gModifierZero;
extern float runtimeInitializationFloat2255;
float sin_004e44b0(float fValue);
class B5081D0Actor
{
  public:
    float GetFloatAt64();
    float GetFloatAtOffset68() const;

    float TESEffectShader_CalculateEdgeAlphaPulse(float fTime);
};
extern "C" double gModifierZero;
extern float runtimeInitializationFloat2255;
float C508240Curve(float fValue);
class C508240Ref
{
  public:
    float GetScale();
    float GetHeight();

    float TESEffectShader_CalculateFillAlphaPulse(float fDistance);
};
namespace std {
float abs(float);
}
float BSMAX_00404010(float, float);
float BSMIN(float, float);
unsigned int FUN_00ba52d0();
struct Envelope
{
    float UpdateEnvelope(float current, float rate, float elapsed, unsigned char releasing, float attack, float decay,
                         float hold, float maximum, float minimum);
};
extern char DAT_01026bd0;
extern char DAT_01026a4c;
extern char DAT_01026a34;
extern char DAT_01026a10;
extern char DAT_010269fc;
extern char DAT_010269e8;
extern char DAT_010269d8;
class ActorStateBase
{
  public:
    ActorStateBase();
    void* m_00;
    int m_04;
    int m_08;
};
class ActorStateSub
{
  public:
    ActorStateSub();
    ~ActorStateSub();
    void FUN_004f15a0(int a);
    void FUN_00484ab0(int a);
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
};
class FUN_00508450_cls : public ActorStateBase
{
  public:
    FUN_00508450_cls();
    ActorStateSub m_0c;
    void* m_3c;
    int m_40;
    int m_44;
    void* m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    void* m_68;
    int m_6c;
    int m_70;
    void* m_74;
    int m_78;
    void* m_7c;
};
struct FUN_0050a850_Primary
{
    virtual ~FUN_0050a850_Primary();
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
};
struct FUN_0050a850_Secondary30
{
    virtual ~FUN_0050a850_Secondary30();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct FUN_0050a850_Secondary4c
{
    virtual ~FUN_0050a850_Secondary4c();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct FUN_0050a850 : FUN_0050a850_Primary, FUN_0050a850_Secondary30, FUN_0050a850_Secondary4c
{
    virtual ~FUN_0050a850();
};
class B0B8F0Form
{
  public:
    B0B8F0Form();
    virtual ~B0B8F0Form();

    void SetFormType(int eType);
    void SetFlag(int iValue);

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
};
class B0B8F0Component
{
  public:
    B0B8F0Component();
    virtual ~B0B8F0Component();
};
class FUN_0050b8f0 : public B0B8F0Form, public B0B8F0Component
{
  public:
    FUN_0050b8f0();
    virtual ~FUN_0050b8f0();
};
class Obj50DDB0
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
    unsigned int m_uiValue1;

    void TESObjectLIGH_SetDynamic(bool bSet);
};
extern int DAT_011c620c;
int __cdecl FixedStrings_GetAttachLight();
struct S_0050de20_Obj
{
    int unk00;
    int unk04;
    void IncRefCount();
    void DecRefCount();
};
struct S_0050de20_A
{
    NiPointer<S_0050de20_Obj> unk00;
    int unk04;
};
struct S_0050de20_Class
{
    bool __thiscall TESObjectLIGH_Update_(NiPointer<S_0050de20_Obj> p, int* q, int b);
    bool __thiscall TESObjectLIGH_Update(S_0050de20_A* a, int b);
};
extern int DAT_011f81dc;
int FileFinder_GetSingleton();
struct S_5102e0_Node
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual ~S_5102e0_Node();
    int unk04f;
    int unk08f;
    int unk0cf;
    int unk10f;
    int unk14f;
    int unk18f;
    S_5102e0_Node* FUN_00441110();
};
struct S_5102e0_List
{
    int unk00;
    int unk04;
    S_5102e0_Node* head;
    void ProcessEntries_005102e0();
};
extern unsigned int g_010173f0;
extern "C" unsigned int __cdecl FindNextMatch(void* p, unsigned int n, char* c);
extern "C" unsigned int __cdecl CompareRun(unsigned int found, char* a1, unsigned int count);
struct FUN_005103d0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_14;
    unsigned int GetBase();
    unsigned int FindSubstring(char* a1, unsigned int start, unsigned int count);
};
struct NiTPointerMapBase
{
    virtual ~NiTPointerMapBase();
};
struct FUN_00519bf0 : NiTPointerMapBase
{
    virtual ~FUN_00519bf0();
};
// FUN_0051cf00 (132 bytes) - the constructor of NiBillboardNode.
//
//   0051cf00  55                    push ebp
//   0051cf01  8bec                  mov ebp, esp
//   0051cf03  6aff                  push -1
//   0051cf05  68e84bef00            push __ehhandler
//   0051cf0a  64a100000000          mov eax, dword ptr fs:[0]
//   0051cf10  50                    push eax
//   0051cf11  51                    push ecx            <- this home [ebp-0x10]
//   0051cf12  a1bc161c01            mov eax, __security_cookie
//   0051cf17  33c5                  xor eax, ebp
//   0051cf19  50                    push eax            <- cookie [ebp-0x14]
//   0051cf1a  8d45f4                lea eax, [ebp-0xc]
//   0051cf1d  64a300000000          mov dword ptr fs:[0], eax
//   0051cf23  894df0                mov dword ptr [ebp-0x10], ecx
//   0051cf26  6a00                  push 0
//   0051cf28  8b4df0                mov ecx, dword ptr [ebp-0x10]
//   0051cf2b  e8801d5400            call 0xa5ecb0        <- base ctor
//   0051cf30  c745fc00000000        mov dword ptr [ebp-4], 0      <- EH state 0
//   0051cf37  8b45f0                mov eax, dword ptr [ebp-0x10]
//   0051cf3a  c70044bf0201          mov dword ptr [eax], 0x102bf44  <- own vftable
//   0051cf40  33c9                  xor ecx, ecx
//   0051cf42  8b55f0                mov edx, dword ptr [ebp-0x10]
//   0051cf45  66898aac000000        mov word ptr [edx+0xac], cx
//   0051cf4c  8b45f0                mov eax, dword ptr [ebp-0x10]
//   0051cf4f  d9ee                  fldz
//   0051cf51  d998b0000000          fstp dword ptr [eax+0xb0]
//   0051cf57  6a01                  push 1
//   0051cf59  8b4df0                mov ecx, dword ptr [ebp-0x10]
//   0051cf5c  e89f000000            call 0x51d000
//   0051cf61  6a01                  push 1
//   0051cf63  8b4df0                mov ecx, dword ptr [ebp-0x10]
//   0051cf66  e8f5000000            call 0x51d060
//   0051cf6b  c745fcffffffff        mov dword ptr [ebp-4], 0xffffffff
//   0051cf72  8b45f0                mov eax, dword ptr [ebp-0x10]
//   0051cf75  8b4df4                mov ecx, dword ptr [ebp-0xc]
//   0051cf78  64890d00000000        mov dword ptr fs:[0], ecx
//   0051cf7f  59                    pop ecx
//   0051cf80  8be5                  mov esp, ebp
//   0051cf82  5d                    pop ebp
//   0051cf83  c3                    ret
//
// The module is an unoptimised (/Od) build, and this is a constructor of a
// POLYMORPHIC class whose vftable lives at 0x102bf44
// (tools/pe.py rtti 0x102bf44 -> .?AVNiBillboardNode@@).  Three facts drive
// the shape:
//
//  * the class has a base class with a NON-TRIVIAL destructor, so the
//    constructor gets an exception-handling frame: the "push -1 / push
//    __ehhandler / mov eax,fs:[0]" prologue, the state word at [ebp-4] (0
//    right after the base ctor call, -1 at scope exit) and, because MSVC
//    2008 arms the /GS cookie for every function that carries an EH frame,
//    the "mov eax,__security_cookie / xor eax,ebp / push eax" trio;
//  * a constructor returns `this` in EAX, so the vptr store goes THROUGH
//    EAX ("mov eax,[ebp-0x10] / mov dword ptr [eax],<vftable>"); under /Od
//    the `this` home is reloaded from the frame for every use;
//  * /Od re-reads `this` from the frame for every use and materialises a
//    call argument into a scratch register, so the base ctor call and the
//    two member calls are all "push arg / mov ecx,[ebp-0x10] / call".
//
// The base class is a stand-in: only its SIZE matters (the derived members
// have to land on +0xac and +0xb0) and its constructor/destructor are
// declared but never defined, so the call target and the cleanup funclet
// are bound by the checker from the original's own bytes.
struct NiBillboardBase
{
    virtual void vfunc_base();
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
    int unkA0;
    int unkA4;
    int unkA8;
    NiBillboardBase(int flags);
    ~NiBillboardBase();
};
struct FUN_0051cf00_NiBillboardNode : public NiBillboardBase
{
    unsigned short m_0ac;
    float m_0b0;
    virtual void vfunc_node();
    void SetMode_0051d000(int flags);
    void NiBillboardNode_SetUpdateControllers(int flags);
    FUN_0051cf00_NiBillboardNode();
    ~FUN_0051cf00_NiBillboardNode();
};
class FormPart508
{
  public:
    virtual void InitItem();
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
};
class ModelPart508
{
  public:
    virtual void GetModelFilePath();
    int unk04;
    int unk08;
};
class ScriptPart508
{
  public:
    virtual void GetScript();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
class DestructPart508
{
  public:
    virtual void GetDestructible();
    int unk04;
    int unk08;
};
class SoundPart508
{
  public:
    virtual void GetSoundByEditorID();
    int unk04;
};
class WaterPart508
{
  public:
    virtual void GetWater();
    int unk04;
};
class ActivatorBase508 : public FormPart508,
                         public ModelPart508,
                         public ScriptPart508,
                         public DestructPart508,
                         public SoundPart508,
                         public WaterPart508
{
  public:
    virtual ~ActivatorBase508();

    void ClearData();
};
class ListPart508
{
  public:
    virtual void GetList();

    int unk04;
    int unk08;
};
class FUN_00508510_Activator : public ListPart508, public ActivatorBase508
{
  public:
    virtual ~FUN_00508510_Activator();
};
struct Item;
struct List
{
    unsigned int __thiscall FUN_0043b480();
    Item* __thiscall FUN_0043b4a0(unsigned int index);
};
struct Item
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    void* __thiscall FUN_00a59d30(int kind);
};
struct T
{
    void __thiscall NiMaterialProperty_SetEmittance(void* p);
};
extern void* DAT_011f4998;
void __cdecl ProcessListItems(List* list);
void __cdecl ProcessListItems(List* list);
extern double DAT_01011590;
extern double DAT_01029100;
extern double DAT_010290f8;
extern double DAT_010290f0;
extern double DAT_010290e8;
extern double DAT_010290e0;
extern double DAT_0101ff48;
extern double DAT_010290d8;
extern double DAT_01011588;
extern double DAT_010290d0;
extern double DAT_010290c8;
extern double DAT_01012060;
extern double DAT_01021928;
extern double DAT_01020998;
extern double DAT_01012070;
extern float DAT_01012054;
extern double DAT_010290c0;
extern double DAT_010290b8;
extern double DAT_010290b0;
extern double DAT_01016408;
extern float DAT_0101e2bc;
extern float DAT_010181bc;
unsigned int __cdecl FUN_00487f50();
float __cdecl sin_004e44b0(float v);
float __cdecl BSMIN(float a, float b);
float __cdecl BSMAX_00404010(float a, float b);
float __cdecl FUN_00408840(float v);
struct Obj
{
    float Projectile_GetSpreadLooking();
    float Sky_GetCurrentWeatherPct();
    float TESObjectWEAP_GetSpeed();
    void FUN_0050c630(float v);
    void FUN_0050c660(float v);
    void FUN_0050c690(float v);
    void NiAVObject_SetTranslate_004bc1f0(float a, float b, float c);
    void NiAVObject_Update(NiUpdateData& u);
    float TESCombatStyle_GetDodgeDuringAttackMult();
    void NiLight_SetDimmer(float v);
};
struct Ptr
{
    void* m_p;
    ~Ptr();
    Obj* Modelloader_GetReferencedThis();
};
struct TimeGlobal
{
    float FUN_0084d030();
};
extern TimeGlobal DAT_011f6394;
extern Setting DAT_011c8fcc;
struct TQ
{
    void TaskQueueInterface_QueueObjectUpdate();
};
TQ* __stdcall FUN_004537b0(void* p);
bool __cdecl AILinearTaskThreadManager_ShouldQueue3DTask();
struct Host
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
    unsigned int m_a8;
    int unkAC;
    int unkB0;
    float m_b4;
    bool TESObjectLIGH_Update_(Ptr p1, float* p2, NiPoint3* p3);
};
struct Region
{
    bool IsInterior();
};
struct Reference
{
    Region* World();
    Region* Cell();
};
struct Node
{
    bool Empty();
    void** Item();
    Node* Next();
    unsigned int Size();
};
struct SelectionMap
{
    int vtable;
    int size;
    int table;
    int count;
    SelectionMap(unsigned int);
    ~SelectionMap();
    bool Lookup(unsigned int, bool*);
    void Set(unsigned int, bool);
};
struct Selector
{
    Node* List();
    void* FindRandomSelection(Reference*, int);
};
struct PlayerSelection
{
    unsigned char Previous(Selector*);
    void Record(Selector*, unsigned char);
};
extern PlayerSelection* selectionPlayer;
unsigned int DialogueRandom();
void* FindSelection(void*, Region*, void**);

extern Setting g_011d4ccc;
extern Setting g_011d49c0;
extern Setting g_011c9284;
extern float DAT_010162c0;
bool Interface_IsInMenuMode();
bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);
void ApplyPerkModifiers(int, Actor*, ...);
void FUN_004d5c60(int);
int BSStringT_char_SPrintF(StrMem*, const char*, ...);
namespace ActorValue {
bool IsSkill(Index);
const char* GetActorValueName(Index);
}
struct SkillBookEffect552
{
    ActorValue::Index TESObjectBOOK_GetTeaches();
    bool TESObjectBOOK_Read(TESObjectREFR* reference);
};
// @fnv 0x00515040
// src: COMMUNITY 0x00515040
bool SkillBookEffect552::TESObjectBOOK_Read(TESObjectREFR* reference)
{
    bool applied = false;
    Actor* actor2 = dynamic_cast<Actor*>(reference);
    if (!actor2->IsPlayerRef())
        return applied;
    if (actor2->Actor_IsInCombat() && !Interface_IsInMenuMode())
    {
        QueueUIMessage(g_011d4ccc.FUN_00403df0(), 0, 0, 0, DAT_010162c0, false);
        return applied;
    }
    ActorValue::Index skill2 = TESObjectBOOK_GetTeaches();
    if (ActorValue::IsSkill(skill2))
    {
        if (g_thePlayer->GetPermanentActorValue(skill2) < 200)
        {
            float amount5 = *g_011c9284.Setting_Float_00403e20();
            StrMem message;
            ApplyPerkModifiers(11, g_thePlayer, &amount5);
            g_thePlayer->ForceActorValue(skill2, amount5, 0);
            FUN_004d5c60(15);
            BSStringT_char_SPrintF(&message, g_011d49c0.FUN_00403df0(), ActorValue::GetActorValueName(skill2),
                         static_cast<int>(amount5));
            QueueUIMessage(message.Modelloader_GetReferencedThis(), 1, 0, 0, DAT_010162c0, false);
            applied = true;
        }
    }
    return applied;
}
