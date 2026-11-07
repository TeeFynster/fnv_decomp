#include "../../../../include/ActorCause.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/Actor.h"
#include "../../../../include/BGSExplosion.h"
#include "../../../../include/BSOcclusionPlane.h"
#include "../../../../include/Explosion.h"
#include "../../../../include/HighProcess.h"
#include "../../../../include/NavMeshPtr.h"
#include "../../../../include/TESObjectWEAP.h"
#include "../../../../include/bhkLiquidAction.h"
#include "../../../../include/AutoMemContext.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/GameTimerRecord.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/MobileObject.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/TESDataHandler.h"
#include "../../../../include/ProcessLists.h"
#include "../../../../include/Setting.h"

// src/fallout/ai/combat/explosion_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/fallout/ai/combat/explosion.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/fallout/ai/combat/explosion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/explosion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void __cdecl _Deallocate(void*);
extern NiRTTI g_01268420;
// src: XBOX_PDB 0x00458b50
NavMesh* NavMeshPtr::AnimatingText_GetFullText()
{
    return 0;
}
struct FUN_009afc30_shell
{
    NavMeshPtr m_navMeshPtr;
    NavMesh* hkpFixedBufferCdPointCollector_getHits();
};
struct FUN_009afbb0_shell
{
    virtual ~FUN_009afbb0_shell();
    void* FUN_009afbb0(unsigned int flags);
    void ForwardCall_009afc10();
};
extern "C" void __cdecl Object_UpdateFields_009afbe0(void*);
struct FUN_00621100_shell
{
    void __thiscall SetVtable(void);
};
struct FUN_009afc10_shell
{
    void __thiscall ForwardCall_009afc10();
};
struct FUN_009afc50_shell
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    NavMesh* hkpFixedBufferCdPointCollector_getHits();
};
void __cdecl FUN_009ac940(void*);
struct FUN_009ac910_shell
{
    void __thiscall FUN_009ac940();
    void* __thiscall FUN_009ac910(unsigned int flags);
};
void __cdecl _delete(void*, unsigned int);
struct FUN_00cbc920_shell
{
    void __thiscall FUN_00cbc920();
};
struct StandIn
{
    void* __thiscall FUN_009ae250(unsigned int);
};
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
extern GameTimerRecord g_timeGlobal;
BSAudio* __cdecl _FUN_00c85750();
struct UnkObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, int);
};
void __cdecl Object_UpdateFields_009afbe0(void* a1);
struct H00622570
{
    void __thiscall UpdateState_00622570(bool);
};
struct S009afc70
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    void* __thiscall hkpFixedBufferCdPointCollector_hasHit(void*);
};
class BGSRagdoll;
struct FUN_009b0d30_shell
{
    void __thiscall activate_00c9c1d0();
    void __thiscall hkpRigidBody_applyAngularImpulse(int);
};
struct RetObj
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual bool vf37();
};
struct Standin77900
{
    bool __thiscall HasAnyFlags(int);
};
extern Setting originalRuntimeFloatSetting818;
extern const float runtimeFloatSettingDefault247;
struct FUN_009ae0f0
{
    char _pad[8];
    float m8;
    float mC;
    float m10;
    float m14;
    void __thiscall hkUnaryActionCinfo_hkUnaryActionCinfo();
    FUN_009ae0f0();
};
void* __cdecl operator new(unsigned int);
TESForm* GetFormByID(unsigned int);
ActorCause* FindStateByValue(int);
struct FUN_00825ad0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int uiFormID18;
    unsigned int uiFormID1C;
    unsigned int uiFormID20;
    FUN_00825ad0(void* apOwner);
};
struct Vec3f
{
    float x;
    float y;
    float z;
};
extern const float g_fConst010162c0;
void* __fastcall Callee00439e90(void* p);
void* __fastcall Callee0053d280(void* p);
struct FUN_005762b0_cls
{
    virtual void vf0()
    {}
    virtual void vf1()
    {}
    virtual void vf2()
    {}
    virtual void vf3()
    {}
    virtual void vf4()
    {}
    virtual void vf5()
    {}
    virtual void vf6()
    {}
    virtual void vf7()
    {}
    virtual void vf8()
    {}
    virtual void vf9()
    {}
    virtual void vf10()
    {}
    virtual void vf11()
    {}
    virtual void vf12()
    {}
    virtual void vf13()
    {}
    virtual void vf14()
    {}
    virtual void vf15()
    {}
    virtual void vf16()
    {}
    virtual void vf17()
    {}
    virtual void vf18()
    {}
    virtual void vf19()
    {}
    virtual void vf20()
    {}
    virtual void vf21()
    {}
    virtual void vf22()
    {}
    virtual void vf23()
    {}
    virtual void vf24()
    {}
    virtual void vf25()
    {}
    virtual void vf26()
    {}
    virtual void vf27()
    {}
    virtual void vf28()
    {}
    virtual void vf29()
    {}
    virtual void vf30()
    {}
    virtual void vf31()
    {}
    virtual void vf32()
    {}
    virtual void vf33()
    {}
    virtual void vf34()
    {}
    virtual void vf35()
    {}
    virtual void vf36()
    {}
    virtual void vf37()
    {}
    virtual void vf38()
    {}
    virtual void vf39()
    {}
    virtual void vf40()
    {}
    virtual void vf41()
    {}
    virtual void vf42()
    {}
    virtual void vf43()
    {}
    virtual void vf44()
    {}
    virtual void vf45()
    {}
    virtual void vf46()
    {}
    virtual void vf47()
    {}
    virtual void vf48()
    {}
    virtual void vf49()
    {}
    virtual void vf50()
    {}
    virtual void vf51()
    {}
    virtual void vf52()
    {}
    virtual void vf53()
    {}
    virtual void vf54()
    {}
    virtual void vf55()
    {}
    virtual void vf56()
    {}
    virtual void vf57()
    {}
    virtual void vf58()
    {}
    virtual void vf59()
    {}
    virtual void vf60()
    {}
    virtual void vf61()
    {}
    virtual void vf62()
    {}
    virtual void vf63()
    {}
    virtual void vf64()
    {}
    virtual void vf65()
    {}
    virtual void vf66()
    {}
    virtual void vf67()
    {}
    virtual void vf68()
    {}
    virtual void vf69()
    {}
    virtual void vf70()
    {}
    virtual void vf71()
    {}
    virtual void vf72()
    {}
    virtual void vf73()
    {}
    virtual void vf74()
    {}
    virtual void vf75()
    {}
    virtual void vf76()
    {}
    virtual void vf77()
    {}
    virtual void vf78()
    {}
    virtual void vf79()
    {}
    virtual void vf80()
    {}
    virtual void vf81()
    {}
    virtual void vf82()
    {}
    virtual void vf83()
    {}
    virtual void vf84()
    {}
    virtual void vf85()
    {}
    virtual void vf86()
    {}
    virtual void vf87()
    {}
    virtual void vf88()
    {}
    virtual void vf89()
    {}
    virtual void vf90()
    {}
    virtual void vf91()
    {}
    virtual void vf92()
    {}
    virtual void vf93()
    {}
    virtual void vf94()
    {}
    virtual void vf95()
    {}
    virtual void vf96()
    {}
    virtual void vf97()
    {}
    virtual void vf98()
    {}
    virtual void vf99()
    {}
    virtual void vf100()
    {}
    virtual void vf101()
    {}
    virtual void vf102()
    {}
    virtual void vf103()
    {}
    virtual void vf104()
    {}
    virtual void vf105()
    {}
    virtual void vf106()
    {}
    virtual void vf107()
    {}
    virtual void vf108()
    {}
    virtual void vf109()
    {}
    virtual void vf110()
    {}
    virtual void vf111()
    {}
    virtual void vf112()
    {}
    virtual void vf113()
    {}
    virtual void vf114()
    {}
    virtual void vf115()
    {}
    virtual void vf116()
    {}
    virtual void vf117()
    {}
    virtual void* vf118(unsigned int* p, Vec3f* q, void* r)
    {
        return 0;
    }
    virtual void* vf119(Vec3f* p, Vec3f* q, float f)
    {
        return 0;
    }
    virtual void vf120()
    {}
    virtual void vf121()
    {}
    virtual void vf122()
    {}
    virtual void vf123()
    {}
    virtual void vf124()
    {}
    virtual void* vf125(int a, void* p)
    {
        return 0;
    }
    int TESObjectREFR_GetLookingAtLocation(int a1);
};
struct FUN_009ac550_cls : Standin77900
{
    char _pad[0x8b];
    float m_8C;
    float GetEffectiveValue();
};
extern int g_ae140Count;
struct Ae140Vec
{
    int unk00;
    int unk04;
    int unk08;
    Ae140Vec();
};
extern Ae140Vec g_ae140Default;
struct Ae140Base
{
    virtual ~Ae140Base();
    int unk04;
    int unk08;
    int unk0c;
    Ae140Base();
};
struct FUN_009ae140_cls : Ae140Base
{
    virtual ~FUN_009ae140_cls();
    int m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    Ae140Vec m_24;
    Ae140Vec m_30;
    unsigned char m_3c;

    void Setup(unsigned int aArg);
    FUN_009ae140_cls(unsigned int aArg);
};
struct VectorHolder
{
    unsigned int handle;
    void __thiscall FUN_006815c0();
    void __thiscall FUN_00537e90(unsigned int);
    VectorHolder()
    {
        FUN_006815c0();
    }
};
struct BaseObject
{
    virtual ~BaseObject();
    unsigned int unk04;
    void __thiscall hkpCdPointCollector_hkpCdPointCollector();
    BaseObject()
    {
        hkpCdPointCollector_hkpCdPointCollector();
    }
};
struct FUN_009afaf0 : BaseObject
{
    VectorHolder first;
    VectorHolder second;
    VectorHolder third;
    VectorHolder fourth;
    FUN_009afaf0(unsigned int firstValue, unsigned int secondValue);
    virtual ~FUN_009afaf0();
};
struct FUN_009afca0_holder
{
    void __thiscall InvokeCallback(void* param);
};
extern void(__cdecl* g_01268430)(void* param, void* thisptr);
struct EntryRecord
{
    int category;
    int unk04;
    int result;
};
struct SearchNode
{
    EntryRecord** FUN_006815c0();
    SearchNode* FUN_00726070();
    bool FUN_008256d0();
};
struct MobileObjectBase
{
    virtual ~MobileObjectBase();
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84;
};
TESForm* GetFormByID(unsigned int);
void* LookupThing18(void*);
void* LookupThing1C(void*);
struct CasterData
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    void* pUnk18;
    void* pUnk1C;
    TESObjectREFR* pRef20;
};
struct GlobalObject_00633c90
{
    GlobalObject_00633c90(int v);
    ~GlobalObject_00633c90();
    int m_ptr;
    GlobalObject_00633c90& operator=(void* p);
};
struct GlobalObject_0096a2d0
{
    GlobalObject_0096a2d0();
    ~GlobalObject_0096a2d0();
    int m_item;
    int m_next;
};
struct GlobalObject_0041a250
{
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    int m_00;
    int m_04;
    int m_08;
};
struct GlobalObject_0042f730
{
    GlobalObject_0042f730(void* p);
    ~GlobalObject_0042f730();
    int m_ptr;
    void AssignRetainedObject(void* p);
};
struct GlobalObject_006815c0
{
    GlobalObject_006815c0();
    float x;
    float y;
    float z;
};
extern "C" Vec3f NiPoint3_ZERO;
struct Base1_9abf30
{
    virtual ~Base1_9abf30();
    virtual void bvtbl00();
    int bf04;
    int bf08;
    int bf0c;
    int bf10;
    int bf14;
};
struct Base2_9abf30
{
    virtual void wvtbl00();
};
struct FUN_0092eb50 : Base1_9abf30, Base2_9abf30
{
    FUN_0092eb50();
    virtual ~FUN_0092eb50();
};
// When the reference's 3D is loaded, run a world update on its root node with the current time.
extern float g_fB17A0CurrentTime;
class B17A0UpdateData
{
  public:
    B17A0UpdateData(float fTime, bool m_bUpdateEnabled, bool bIsMultiThreaded);

    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
};
class B17A0Node
{
  public:
    void Update(const B17A0UpdateData& kData);
};
// FUN_009b2790 v01 - worker7 data round
struct Holder0042f780
{
    int m_00;
    Holder0042f780* AssignRetainedObject(ActorCause* p);
};
struct HeadW7
{
    void* FUN_009ac910(unsigned int flags);
};
struct ListW7
{
    int m_00;
    bool _ref_008256d0();
    HeadW7** _ref_006815c0();
    void _ref_0063f7b0();
};
struct Vec3W7
{
    float x;
    float y;
    float z;
};
extern Vec3W7 __NiPoint3_ZERO;
struct MatrixWater
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    MatrixWater();
    void FUN_004a0c90(float);
};
struct SaveX
{
    bool BGSSaveLoadGame_GetSaveGameLoading();
};
extern SaveX* g_BGSSaveLoadGame;
struct SceneX
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual SceneX* AsNode();
    virtual SceneX* AsFade();
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
    virtual void v35();
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
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void Attach(SceneX*, bool);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    void FUN_00450f90(bool);
    void BSFadeNode_TurnFadeNodeOn();
    void NiAVObject_SetTranslate(const NiPoint3&);
    void UpdateProperties();
};
struct IdFlagState
{
    int id, flags, state;
    IdFlagState();
    ~IdFlagState();
    void operator=(const IdFlagState&);
    bool FUN_00ad8ce0();
    bool FUN_00ad8b60(float, float, float);
    bool FUN_00ad8830(bool);
};
struct AudioX
{
    IdFlagState BSAudio_GetSoundHandleByEditorName(const char*, unsigned);
};
AudioX* BSAudio_QInstance();
extern Setting DAT_011d0520, DAT_011d0280, DAT_011d0da4, DAT_011d0ce4, DAT_011d0a78, DAT_011c7ae8;
struct CellX
{
    void RemoveReference(Explosion*);
    void AddReference(Explosion*, bool);
    SceneX* FUN_005497a0();
    float TESObjectCELL_GetWaterHeight();
};
struct ActorProcX
{
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void React(Explosion*, NiPoint3, int*, int, unsigned);
};
struct ActorPtrX
{
    Actor* Modelloader_GetReferencedThis();
};
extern Explosion* DAT_011dea3c;
struct ExtraX
{
    void ExtraDataList_SetRadius(float);
};
struct HandlerX
{
    void PlaceObjectReference(void*, const NiPoint3&, const NiPoint3&, CellX*, void*, int, int, int);
};
extern HandlerX* DAT_011c3f2c;
extern ProcessLists DAT_011e0e80;
struct ListX
{
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddHead(Explosion* const&);
};
extern ListX DAT_011c7b8c;
struct TesX
{
    void FUN_00458e20(SceneX*, float);
};
extern TesX* DAT_011dea10;
SceneX* CreateOctahedron(float, const NiColorA*, int);
void* TESImageSpaceModifier_GetExplosionInFace();
void FUN_005299a0(void*, float, SceneX*);
float ComputeSquaredRatioComplement(float, float);
float GetAnimValueByPrefix(SceneX*, const char*, const char*);
void UpdateDistanceFade(float, const NiPoint3&);
float RandomFloatTwoPi();
void BSTempEffectParticle_Spawn_00689210(CellX*, float, const char*, MatrixWater, NiPoint3, float, int, int);

extern MemoryManager g_memoryManager;

struct Node00cbd500
{
    int unk00;
    int unk04;
    int unk08;
};

// @fnv 0x00cbd500
// src: GUESS 0x00cbd500 (confidence: medium)
void __stdcall Object_ReleaseStorage_00cbd500(Node00cbd500* p)
{
    p->unk08 = 0;
    g_memoryManager.Deallocate(p);
}

#include <math.h>
#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier(void);

struct LiquidVec
{

    float x, y, z;

    bool __thiscall HasEqualComponents(const LiquidVec&);

    float __thiscall FUN_00457910();

    bool operator==(LiquidVec v) const
    {
        return x == v.x && y == v.y && z == v.z;
    }

    LiquidVec& operator+=(const LiquidVec& v)
    {
        x = (x + v.x);
        y = (y + v.y);
        z = (z + v.z);
        return *this;
    }

    LiquidVec& operator-=(const LiquidVec& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    LiquidVec& operator*=(const float& s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    LiquidVec operator*(const float& s) const
    {
        LiquidVec r = {x * s, y * s, z * s};
        return r;
    }

    float LengthSq() const
    {
        return x * x + y * y + z * z;
    }

    float Dot(LiquidVec v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }
};

extern const float DAT_01016248;

struct LiquidVecOf : LiquidVec
{

    LiquidVecOf(__m128 v)
    {
        _mm_store_ss(&x, v);
        _mm_store_ss(&y, _mm_shuffle_ps(v, v, 0x55));
        _mm_store_ss(&z, _mm_shuffle_ps(v, v, 0xaa));
    }
};

struct LiquidFour
{

    __m128 value;

    LiquidFour()
    {}

    LiquidFour(const LiquidFour& v)
    {
        value = v.value;
    }

    LiquidFour& operator=(const LiquidFour& v)
    {
        value = v.value;
        return *this;
    }

    void Set4(float a, float b, float c, float d)
    {
        value = _mm_set_ps(a, b, c, d);
    }

    void Mul(float s)
    {
        value = _mm_mul_ps(_mm_set1_ps(s), value);
    }

    void MulD(double s)
    {
        value = _mm_mul_ps(_mm_set1_ps((float)s), value);
    }
};

struct LiquidContact
{
    LiquidFour position, normal;
    float NormalZ() const
    {
        return normal.value.m128_f32[2];
    }
};

struct LiquidTransform
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
};

struct LiquidTarget
{

    unsigned unk0;

    unsigned unk4;

    unsigned unk8;

    unsigned unkc;

    unsigned unk10;

    unsigned unk14;

    unsigned unk18;

    unsigned unk1c;

    unsigned unk20;

    unsigned unk24;

    unsigned unk28;

    unsigned unk2c;

    unsigned unk30;

    unsigned unk34;

    unsigned unk38;

    unsigned unk3c;

    unsigned unk40;

    unsigned unk44;

    unsigned unk48;

    unsigned unk4c;

    unsigned unk50;

    unsigned unk54;

    unsigned unk58;

    unsigned unk5c;

    unsigned unk60;

    unsigned unk64;

    LiquidTransform rotation;
};

struct LiquidBody;

struct LiquidLink
{
    unsigned unk00, unk04, unk08;
    LiquidBody* body;
};

struct LiquidOwner
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14;
    LiquidLink* link;
    unsigned unk1c;
    LiquidFour force;
};

struct LiquidCast
{
    LiquidOwner* __thiscall FUN_00653290(const void*);
};

struct __declspec(align(8)) LiquidResult
{
    LiquidCast* object;
    unsigned high;
};

extern const unsigned DAT_01267b70, DAT_012043f8;

LiquidResult* __cdecl bhkWorldObject_GetProperty(LiquidResult*, void*, const void*);

__declspec(noalias) LiquidVec& __cdecl FUN_00458620(LiquidVec*, const LiquidFour*);

LiquidVec& __cdecl HK2NINS(LiquidVec*, const LiquidFour*);

extern const LiquidVec DAT_011f426c, DAT_011a9484;

extern const LiquidFour DAT_01267e30;

extern float DAT_011b2178, DAT_011b217c, DAT_011b2180, DAT_011b2184, DAT_011b2188, DAT_011b218c;

extern float DAT_01268428;

extern const double DAT_01012070, DAT_01011598;

extern unsigned char DAT_0126842c;

struct LiquidRigid;

struct LiquidContactArray
{

    unsigned unk00;
    unsigned short count, unk06;

    unsigned unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;

    LiquidContact contacts[1];
};

struct LiquidConstraintData
{

    virtual void v0();

    virtual void v1();

    virtual void v2();

    virtual void v3();

    virtual void v4();

    virtual void v5();

    virtual void v6();

    virtual void v7();

    virtual int GetType();

    unsigned unk04, unk08;
    unsigned char* indices;

    unsigned unk10, unk14, unk18, unk1c, unk20, unk24;
    LiquidContactArray* contactData;

    unsigned short __thiscall hkpSimpleContactConstraintData_getContactPointIdAt(int);
};

struct LiquidConstraint
{
    unsigned unk00, unk04, unk08;
    LiquidConstraintData* data;
    unsigned unk10;
    LiquidRigid* first;
    LiquidRigid* second;
};

struct LiquidRigid
{

    unsigned unk00, unk04;
    struct LiquidWorld* world;

    unsigned unkc;

    unsigned unk10;

    unsigned unk14;

    unsigned unk18;

    unsigned unk1c;

    unsigned unk20;

    unsigned unk24;

    unsigned unk28;

    unsigned unk2c;

    unsigned unk30;

    unsigned unk34;

    unsigned unk38;

    unsigned unk3c;

    unsigned unk40;

    unsigned unk44;

    unsigned unk48;

    unsigned unk4c;

    unsigned unk50;

    unsigned unk54;

    unsigned unk58;

    unsigned unk5c;

    unsigned unk60;

    unsigned unk64;

    unsigned unk68;

    unsigned unk6c;

    unsigned unk70;

    unsigned unk74;

    unsigned unk78;

    unsigned unk7c;

    unsigned unk80;

    unsigned unk84;

    unsigned unk88;

    unsigned unk8c;

    unsigned unk90;

    unsigned unk94;

    unsigned unk98;

    unsigned unk9c;

    unsigned unka0;

    unsigned unka4;

    unsigned unka8;

    unsigned unkac;

    unsigned unkb0;

    unsigned unkb4;

    unsigned unkb8;

    unsigned unkbc;

    unsigned unkc0;

    unsigned unkc4;

    unsigned unkc8;

    unsigned unkcc;

    unsigned unkd0;

    unsigned unkd4;

    unsigned unkd8;

    unsigned unkdc;

    unsigned unke0;

    unsigned unke4;

    unsigned unke8;

    unsigned unkec;

    unsigned unkf0;

    unsigned unkf4;

    unsigned unkf8;

    unsigned unkfc;

    unsigned unk100;

    unsigned unk104;

    unsigned unk108;

    unsigned unk10c;

    unsigned unk110;

    unsigned unk114;

    unsigned unk118;

    unsigned unk11c;

    unsigned unk120;

    unsigned unk124;

    unsigned unk128;

    unsigned unk12c;

    unsigned unk130;

    unsigned unk134;

    unsigned unk138;

    unsigned unk13c;

    unsigned unk140;

    unsigned unk144;

    unsigned unk148;

    unsigned unk14c;

    unsigned unk150;

    unsigned unk154;

    unsigned unk158;

    unsigned unk15c;

    unsigned unk160;

    unsigned unk164;

    unsigned unk168;

    unsigned unk16c;

    unsigned unk170;

    unsigned unk174;

    unsigned unk178;

    unsigned unk17c;

    unsigned unk180;

    unsigned unk184;

    unsigned unk188;

    unsigned unk18c;

    unsigned unk190;

    unsigned unk194;

    unsigned unk198;

    unsigned unk19c;

    unsigned unk1a0;

    unsigned unk1a4;

    unsigned unk1a8;

    unsigned unk1ac;

    LiquidFour velocity;

    void __thiscall OnTrigger(const LiquidFour&);

    void __thiscall activate_00c9c1d0();

    int __thiscall getNumConstraints();

    LiquidConstraint* __thiscall GetEntry(int);
};

struct LiquidWorld
{
    void __thiscall OnTrigger(const LiquidFour&);
    void __thiscall activate_00c9c1d0();
};

struct LiquidBody
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

    virtual void v35();

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

    virtual void v47();

    virtual void v48();

    virtual void v49();

    virtual void v50();

    virtual void v51();

    virtual void v52();

    virtual const LiquidFour& GetPosition(LiquidFour& out);

    unsigned unk04;
    LiquidRigid* object;

    void __thiscall Object_DoNothing();

    __forceinline void CopyPosition(LiquidVec& out)
    {
        LiquidFour v;
        FUN_00458620(&out, &GetPosition(v));
    }
};

struct LiquidActionCandidate;

struct LiquidNode
{
    LiquidActionCandidate* data;
    LiquidNode* next;
};

struct LiquidMap
{
    __declspec(noalias) bool __thiscall FUN_00a53c30(LiquidTarget*, LiquidNode*&);
};

extern LiquidMap DAT_011b2190;

struct LiquidActionCandidate
{

    unsigned unk00, unk04;
    LiquidOwner* owner;
    unsigned unk0c;

    LiquidTarget* target;
    float radius, strength, impulse, unk20;

    LiquidVec position, normal;
    unsigned char pending;

    void __thiscall bhkLiquidAction_SetTargetObject(LiquidLink*);

    __forceinline LiquidLink* GetLink()
    {
        return this && owner ? owner->link : (LiquidLink*)owner;
    }

    __forceinline LiquidLink* GetLink0()
    {
        LiquidLink* l = this && owner ? owner->link : 0;
        _ReadWriteBarrier();
        return l;
    }

    __forceinline LiquidBody* GetBody()
    {
        LiquidLink* l = GetLink0();
        return l ? l->body : 0;
    }

    void bhkLiquidAction_Update(float);
};

__forceinline float LiquidPick(bool c, float a, float b)
{
    return c ? a : b;
}

__forceinline float LiquidMin(float v, float m)
{
    return v > DAT_01012070 ? m : v;
}

__forceinline float LiquidMax(float v, float m)
{
    return v < DAT_01011598 ? m : v;
}

// src: GUESS 0x004390c0 (confidence: high)
__declspec(noinline) bool LiquidVec::HasEqualComponents(const LiquidVec& p)
{
    bool a = x == p.x;
    bool b = y == p.y;
    bool c = z == p.z;
    return a & b & c;
}

// @fnv 0x00cbccb0
// src: XBOX_PDB 0x00cbccb0
void LiquidActionCandidate::bhkLiquidAction_Update(float delta)

{

    LiquidVec force;
    force = DAT_011f426c;

    LiquidLink* link = GetLink0();

    if (link)
    {

        LiquidBody* body = link->body;

        if (body)
        {

            if (!target)
            {

                LiquidResult lookup;

                LiquidRigid* obj = body->object;

                LiquidCast* found = bhkWorldObject_GetProperty(&lookup, obj, &DAT_01267b70)->object;

                if (found)
                {

                    LiquidOwner* other = found->FUN_00653290(&DAT_012043f8);

                    if (other && other->unk08)
                    {

                        LiquidOwner* nested = (LiquidOwner*)other->unk08;

                        if (nested->link)
                            bhkLiquidAction_SetTargetObject(nested->link);
                    }
                }
            }

            LiquidVec bodyPosition;

            body->CopyPosition(bodyPosition);

            LiquidRigid* object = body->object;

            unsigned char gravity = DAT_0126842c;

            bool hasNormal = false;

            LiquidFour velocity = object ? object->velocity : DAT_01267e30;

            LiquidContact contact;

            if (object && object->getNumConstraints() && position.HasEqualComponents(DAT_011f426c))
            {

                for (int i = 0; position.HasEqualComponents(DAT_011f426c) && i < object->getNumConstraints(); ++i)
                {

                    LiquidConstraint* c = object->GetEntry(i);

                    LiquidConstraintData* d = c->data;

                    if (d->GetType() == 11)
                    {

                        unsigned flags;

                        if (c->first == object && c->second)
                            flags = c->second->unk2c;

                        else if (c->second == object && c->first)
                            flags = c->first->unk2c;

                        else
                            continue;

                        if ((flags & 127) == 1 || (flags & 127) == 13)
                        {

                            LiquidContactArray* contacts = d->contactData;

                            if (contacts->count > 0)
                            {

                                contact = contacts->contacts[d->indices[d->hkpSimpleContactConstraintData_getContactPointIdAt(0)]];

                                if (contact.NormalZ() < 0.5f)
                                {

                                    FUN_00458620(&position, &contact.position);

                                    HK2NINS(&normal, &contact.normal);

                                    velocity.value = _mm_setr_ps(0.0f, 0.0f, 0.0f, 0.0f);
                                }
                            }
                        }
                    }
                }
            }

            float damping;

            if (!(position == DAT_011f426c))
            {

                LiquidVec difference = position;

                difference -= bodyPosition;

                gravity = true;
                hasNormal = true;

                float squared = difference.LengthSq();

                float distance = (float)sqrt(squared);

                if (distance > 0.0f)
                {

                    LiquidVec projected = normal;

                    projected *= normal.Dot(difference);

                    force.x = projected.x + force.x;
                    force.y = projected.y + force.y;
                    force.z = projected.z + force.z;
                }

                damping = DAT_011b2184;
            }
            else
                damping = DAT_011b2180;

            float exponent = (float)(damping * -1.0 * delta);

            float decay = exp(exponent);

            velocity.Mul(decay);

            if (gravity)
            {

                float vertical = -delta * DAT_011b218c * DAT_011b217c;

                velocity.value = _mm_add_ps(velocity.value, _mm_setr_ps(0.0f, 0.0f, vertical, 0.0f));
            }

            LiquidRigid* world = body->object;

            if (world)
            {

                body->Object_DoNothing();

                world->OnTrigger(velocity);

                body->Object_DoNothing();
            }

            {

                LiquidNode* node = 0;

                DAT_011b2190.FUN_00a53c30(target, node);

                for (; node; node = node->next)
                {

                    if (!node->next && !node->data)
                        break;

                    LiquidBody* otherBody = node->data->GetBody();

                    __m128 otherPosition = otherBody->GetPosition(contact.position).value;

                    float px, py, pz;

                    _mm_store_ss(&px, otherPosition);

                    _mm_store_ss(&py, _mm_shuffle_ps(otherPosition, otherPosition, 0x55));

                    _mm_store_ss(&pz, _mm_shuffle_ps(otherPosition, otherPosition, 0xaa));

                    LiquidVec raw = {px, py, pz};

                    LiquidVec otherPos = raw * DAT_011b2188;

                    LiquidVec difference = bodyPosition;

                    difference -= otherPos;

                    float distance = difference.FUN_00457910();

                    if (distance > 0 && radius + radius > distance)
                    {

                        float ratio = (radius - distance) / (radius * DAT_011b2178);

                        float hi = ratio > DAT_01012070 ? 1.0f : ratio;

                        float lo = hi < DAT_01011598 ? -0.5f : hi;

                        float scale = strength * lo;

                        LiquidVec push = {difference.x * scale, difference.y * scale, difference.z * scale};

                        if (hasNormal)
                        {

                            float dot = normal.Dot(push);

                            LiquidVec projected;
                            projected = normal * dot;

                            push -= projected;
                        }

                        force.x += push.x;
                        force.y += push.y;
                        force.z += push.z;
                    }
                }
            }

            if (target)
            {

                float neg = -impulse;
                LiquidVec push = DAT_011a9484 * neg;

                LiquidVec rotated = {

                    target->rotation.xx * push.x + target->rotation.xy * push.y + target->rotation.xz * push.z,

                    target->rotation.yx * push.x + target->rotation.yy * push.y + target->rotation.yz * push.z,

                    target->rotation.zx * push.x + target->rotation.zy * push.y + target->rotation.zz * push.z};

                impulse *= 0.89999997615814209;

                force += rotated;
            }

            LiquidFour result;

            result.value.m128_f32[0] = (float)(force.x) * DAT_01268428;

            result.value.m128_f32[1] = force.y * DAT_01268428;

            result.value.m128_f32[2] = force.z * DAT_01268428;

            result.value.m128_f32[3] = 0;

            owner->force = result;

            if (!(force == DAT_011f426c))
            {

                LiquidRigid* world = body->object;

                if (world)
                {

                    body->Object_DoNothing();

                    world->activate_00c9c1d0();

                    body->Object_DoNothing();
                }
            }
        }
    }

    pending = 0;
}
