typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2

// src/havok/physics/utilities/actions/mousespring/hkpmousespringaction_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/actions/mousespring/hkpmousespringaction.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/actions/mousespring/hkpmousespringaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/mousespring/hkpmousespringaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpMouseSpringAction.h"
#include "../../../../../../include/hkBool.h"   // the shared class; include/hkMonitorStream.h skips it once havok/hkBase.h is in
#include "../../../../../../include/hkStepInfo.h"
#include "../../../../../../include/hkpCdBody.h"
#include "../../../../../../include/hkpBroadPhaseHandle.h"
#include "../../../../../../include/hkpTypedBroadPhaseHandle.h"
struct FUN_00d2b1f0
{
    void __thiscall EntityRemovedCallback(int);
};
struct FUN_00cbb1c0 : FUN_00d2b1f0
{
    void __thiscall Method(int);
};
struct FUN_00cbb1b0_Class
{
    char pad0[0x48];
    hkReal m_fMaxRelativeForce;
    void __thiscall hkpMouseSpringAction_setMaxRelativeForce(hkReal a);
};
extern "C" int DAT_01268a14;
int __cdecl hkpUnaryAction_getClassType();
// Exe 0x00cbb1e0 FUN_00cbb1e0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).

extern int DAT_010c8e94;
extern int DAT_010c476c;
extern float DAT_0101b2d0;
extern float DAT_0104da48;
extern const char str_011b1f3c[];
struct Ms_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* AllocateBufferWithSize(int* n);
    virtual void ReturnMemory(void* p, int n);
};
struct Ms_Tls
{
    int u0;
    int u1;
    int u2;
    int u3;
    Ms_Heap* heap;
};
Ms_Tls* __cdecl hkMemoryRouter_getInstance();
struct Ms_ArrInit
{
    int* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
    }
};
struct Ms_Arr
{
    int* m_data;
    int m_iElementCount;
    int m_cap;
};
struct Ms_Sphere
{
    int v0;
    int v1;
    int v2;
    int type;
    float radius;
    int u5;
    int u6;
    int u7;
    void __thiscall FUN_00cd8160(float r);
};
struct Ms_Xf
{
    LocalM128 c0;
    LocalM128 c1;
    LocalM128 c2;
    LocalM128 t;
};
struct Ms_Body
{
    int u0;
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    int u11;
    int u12;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    void __thiscall FUN_00cd2d80(Ms_Sphere* s, Ms_Xf* x, int parent);
};
Ms_Xf* __cdecl FUN_00cd4b50();
struct Ms_Input
{
    int i0;
    int i1;
    int i2;
    int i3;
    int i4;
    int i5;
    int i6;
    int i7;
    LocalM128 q0;
    LocalM128 q1;
    LocalM128 q2;
};
struct Ms_Coll
{
    int* vptr;
    float early;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    float dist;
    int hit;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    int u20;
    int u21;
    int u22;
    int key;
    int u24;
    int u25;
    int u26;
    int u27;
    int u28;
    int u29;
    int u30;
    int u31;
};
struct Ms_Shape
{
    int u0;
    int u1;
    int u2;
    int type;
};
struct Ms_Disp
{
    int unk00;
};
struct Ms_World
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
    Ms_Input* input;
    int unk7c;
    Ms_Disp* disp;
};
struct Ms_Ent
{
    int u0;
    int u1;
    Ms_World* world;
    int u3;
    Ms_Shape* shape;
};
typedef void(__cdecl* Ms_Fn)(Ms_Body*, void*, Ms_Input*, Ms_Coll*);
struct Ms_B
{
    void __thiscall FUN_00d2b260(void* e, int z);
};
struct Ms_N
{
    void __thiscall UpdateState_00cb0c10(const char* s);
};
extern "C"
{
    void _mm_store_ps(float*, LocalM128);
    LocalM128 _mm_load_ps(const float*);
}
struct Fv
{
    float x;
    float y;
    float z;
    float w;
};
struct Ms_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Fv pos;
    Fv mouse;
    float damping;
    float elasticity;
    float maxRel;
    float objDamping;
    int shapeKey;
    Ms_ArrInit cb;
    Ms_cls* hkpMouseSpringAction_hkpMouseSpringAction(LocalM128* a0, LocalM128* a1, float a2, float a3, float a4, Ms_Ent* a5, Ms_Arr* a6);
};
class FUN_00d01a60
{
  public:
    FUN_00d01a60();
    int unk00[11];
};
extern const float DAT_01012054;
class FUN_00cd2d80 : public hkpCdBody
{
  public:
    FUN_00cd2d80(const void* shape, const void* motionState, int type);

    signed char m_iOwnerOffset;
    signed char m_uiForceCollideOntoPpu;
    unsigned short m_uiShapeSizeOnSpu;
    hkpTypedBroadPhaseHandle m_kBroadPhaseHandle;
    FUN_00d01a60 m_kBoundingVolumeData;
    float m_fAllowedPenetrationDepth;
};
struct Ms_Tls;
Ms_Tls* hkMemoryRouter_getInstance();
struct Ms_HeapX
{
    virtual void v00();
    virtual void v04();
    virtual void v08(void* p, unsigned short n);
    virtual void v0c();
    virtual void v10(int p, int n);
};
struct Cls
{
    void* m_vt;          // 0x00
    int m_04;            // 0x04 (word)
    char m_pad08[0x4c];  // to 0x54
    int m_54;
    int m_58;
    int m_5c;
    Cls* FUN_00cbb8b0(int flags);
    void ReleaseReference_00d2b2b0();
};
extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ps1(const float*);
    LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
}
extern "C"
{
}
extern const LocalM128 DAT_01017d10;
extern const float DAT_01017d00;
struct __declspec(align(16)) hkVector4CBB1
{
    LocalM128 m_vComponents;
    void operator=(const hkVector4CBB1& v)
    {
        m_vComponents = v.m_vComponents;
    }
};
class UnkCall
{
  public:
    int unk00;
    int unk04;
    int m_pOwningWorld;

    void activate_00c9c1d0();
};
class hkpPositionTrackerCBB1
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    UnkCall* m_pOwnerObject;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkVector4CBB1 m_vContactPosition;

    void hkpMouseSpringAction_setMousePosition(const hkVector4CBB1& kPosition);
};
extern "C" LocalM128 _mm_setzero_ps(void);
struct FUN_00cbb4e0
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    void* unk0C;
    unsigned int unk10;
    hkStringPtr m_name;
    void* m_pEntity;
    unsigned int unk1C;
    hkVector4 m_kMousePositionInWorld;
    hkVector4 m_kGrabPointInBodySpace;
    hkReal m_fSpringDamping;
    hkReal m_fSpringElasticity;
    hkReal m_fMaxRelativeForce;
    hkReal m_fTau;
    unsigned int m_uiCollisionShapeKey;
    hkArray<char> m_kAppliedCallbacks;
    FUN_00cbb4e0(int arg);
};
extern float DAT_01016248, DAT_01017870, DAT_0101ffc0;

extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    void _mm_store_ss(float*, LocalM128);
    LocalM128 _mm_setzero_ps();
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_load1_ps(const float*);
    LocalM128 _mm_set1_ps(float);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
}

extern "C" float DAT_0106c288;
extern "C" hkVector4 DAT_010c44d0;

struct FUN_00ca86c0_class
{
    unsigned int __thiscall hkpRigidBody_getStoredDynamicMotion_00ca86c0();
};

__forceinline hkMatrix3::hkMatrix3() {}

struct FUN_00cdf250_class
{
    void __thiscall hkMatrix3_setMul(int*, int);
};

struct Vector4Ext : hkVector4
{
    void __thiscall setTransformedPos_00c7f640(const hkTransform* t, const hkVector4* v);
    void __thiscall hkVector4_setMul3(const hkMatrix3* m, const hkVector4* v);
};

struct Matrix3Ext : FUN_00cdf250_class, hkMatrix3
{
    void __thiscall FUN_00cd4cc0(const hkVector4* v);
    void __thiscall Subtract(const hkMatrix3* a);
    int __thiscall invert_00cd4f10(float eps);
};

struct MotionExt
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void unk4();
    virtual void unk5();
    virtual void unk6();
    virtual void unk7();
    virtual void unk8();
    virtual void unk9();
    virtual void __thiscall GetLocalInverseInertia(hkMatrix3* out);
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void __thiscall ApplyImpulseAtPoint(const hkVector4* impulse, const hkVector4* point);

    int unk04;
    int unk08;
    int unk0c;
    float m_kMotionTransformStorage[16];
    __declspec(property(get=Get_m_kMotionTransform)) hkTransform m_kMotionTransform;
    __forceinline hkTransform& Get_m_kMotionTransform() { return *reinterpret_cast<hkTransform*>(m_kMotionTransformStorage); }
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    float m_centerOfMassInWorldStorage[4];
    __declspec(property(get=Get_m_centerOfMassInWorld)) hkVector4 m_centerOfMassInWorld;
    __forceinline hkVector4& Get_m_centerOfMassInWorld() { return *reinterpret_cast<hkVector4*>(m_centerOfMassInWorldStorage); }
    float unk70Storage[4];
    __declspec(property(get=Get_unk70)) hkVector4 unk70;
    __forceinline hkVector4& Get_unk70() { return *reinterpret_cast<hkVector4*>(unk70Storage); }
    float unk80Storage[4];
    __declspec(property(get=Get_unk80)) hkVector4 unk80;
    __forceinline hkVector4& Get_unk80() { return *reinterpret_cast<hkVector4*>(unk80Storage); }
    float unk90Storage[4];
    __declspec(property(get=Get_unk90)) hkVector4 unk90;
    __forceinline hkVector4& Get_unk90() { return *reinterpret_cast<hkVector4*>(unk90Storage); }
    float unka0Storage[4];
    __declspec(property(get=Get_unka0)) hkVector4 unka0;
    __forceinline hkVector4& Get_unka0() { return *reinterpret_cast<hkVector4*>(unka0Storage); }
    float unkb0Storage[4];
    __declspec(property(get=Get_unkb0)) hkVector4 unkb0;
    __forceinline hkVector4& Get_unkb0() { return *reinterpret_cast<hkVector4*>(unkb0Storage); }
    float m_kInertiaAndMassInvStorage[4];
    __declspec(property(get=Get_m_kInertiaAndMassInv)) hkVector4 m_kInertiaAndMassInv;
    __forceinline hkVector4& Get_m_kInertiaAndMassInv() { return *reinterpret_cast<hkVector4*>(m_kInertiaAndMassInvStorage); }
    float m_kTranslationalVelocityStorage[4];
    __declspec(property(get=Get_m_kTranslationalVelocity)) hkVector4 m_kTranslationalVelocity;
    __forceinline hkVector4& Get_m_kTranslationalVelocity() { return *reinterpret_cast<hkVector4*>(m_kTranslationalVelocityStorage); }
    float m_kAngularVelocityStorage[4];
    __declspec(property(get=Get_m_kAngularVelocity)) hkVector4 m_kAngularVelocity;
    __forceinline hkVector4& Get_m_kAngularVelocity() { return *reinterpret_cast<hkVector4*>(m_kAngularVelocityStorage); }

    float __thiscall FUN_00c86430();
};

struct RigidBodyExt : FUN_00ca86c0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float unk10Storage[4];
    __declspec(property(get=Get_unk10)) hkVector4 unk10;
    __forceinline hkVector4& Get_unk10() { return *reinterpret_cast<hkVector4*>(unk10Storage); }
    float unk20Storage[4];
    __declspec(property(get=Get_unk20)) hkVector4 unk20;
    __forceinline hkVector4& Get_unk20() { return *reinterpret_cast<hkVector4*>(unk20Storage); }
    float unk30Storage[4];
    __declspec(property(get=Get_unk30)) hkVector4 unk30;
    __forceinline hkVector4& Get_unk30() { return *reinterpret_cast<hkVector4*>(unk30Storage); }
    float unk40Storage[4];
    __declspec(property(get=Get_unk40)) hkVector4 unk40;
    __forceinline hkVector4& Get_unk40() { return *reinterpret_cast<hkVector4*>(unk40Storage); }
    float unk50Storage[4];
    __declspec(property(get=Get_unk50)) hkVector4 unk50;
    __forceinline hkVector4& Get_unk50() { return *reinterpret_cast<hkVector4*>(unk50Storage); }
    float unk60Storage[4];
    __declspec(property(get=Get_unk60)) hkVector4 unk60;
    __forceinline hkVector4& Get_unk60() { return *reinterpret_cast<hkVector4*>(unk60Storage); }
    float unk70Storage[4];
    __declspec(property(get=Get_unk70)) hkVector4 unk70;
    __forceinline hkVector4& Get_unk70() { return *reinterpret_cast<hkVector4*>(unk70Storage); }
    float unk80Storage[4];
    __declspec(property(get=Get_unk80)) hkVector4 unk80;
    __forceinline hkVector4& Get_unk80() { return *reinterpret_cast<hkVector4*>(unk80Storage); }
    float unk90Storage[4];
    __declspec(property(get=Get_unk90)) hkVector4 unk90;
    __forceinline hkVector4& Get_unk90() { return *reinterpret_cast<hkVector4*>(unk90Storage); }
    float unka0Storage[4];
    __declspec(property(get=Get_unka0)) hkVector4 unka0;
    __forceinline hkVector4& Get_unka0() { return *reinterpret_cast<hkVector4*>(unka0Storage); }
    float unkb0Storage[4];
    __declspec(property(get=Get_unkb0)) hkVector4 unkb0;
    __forceinline hkVector4& Get_unkb0() { return *reinterpret_cast<hkVector4*>(unkb0Storage); }
    float unkc0Storage[4];
    __declspec(property(get=Get_unkc0)) hkVector4 unkc0;
    __forceinline hkVector4& Get_unkc0() { return *reinterpret_cast<hkVector4*>(unkc0Storage); }
    float unkd0Storage[4];
    __declspec(property(get=Get_unkd0)) hkVector4 unkd0;
    __forceinline hkVector4& Get_unkd0() { return *reinterpret_cast<hkVector4*>(unkd0Storage); }
    MotionExt m_pMotionState;

    void __thiscall OnTrigger(const hkVector4* linVel);
    void __thiscall hkpRigidBody_setAngularVelocity(const hkVector4* velDiff);
    void __thiscall hkpRigidBody_getPointVelocity(const hkVector4* point, hkVector4* outVel);
    void __thiscall activate_00c9c1d0();
};

extern "C" double __cdecl sqrt(double);

typedef void(__cdecl* MouseSpringCallback)(hkpMouseSpringAction*, const hkStepInfo&, const hkVector4&);

struct MouseSpringActionExt : hkpMouseSpringAction
{
    void __thiscall hkpMouseSpringAction_applyAction(const hkStepInfo& stepInfo);
};

// @fnv 0x00cbb1e0
// src: HAVOK_SRC 0x00cbb1e0
void __thiscall MouseSpringActionExt::hkpMouseSpringAction_applyAction(const hkStepInfo& stepInfo)
{
    Vector4Ext impulse;
    Vector4Ext worldPos;
    Vector4Ext r;
    Vector4Ext angVel;
    struct MassAndVelocity
    {
        Matrix3Ext K;
        Vector4Ext lin;
        Vector4Ext ang;
    } work;
    Vector4Ext deltaPos;
    Matrix3Ext crossR;
    struct InertiaProducts
    {
        Matrix3Ext tempMat1;
        Matrix3Ext inertiaInvWorld;
        Matrix3Ext tempMat2;
    } matrices;
    float maxImpulse;
    float lenSq;

    RigidBodyExt* rb = (RigidBodyExt*)m_pEntity;

    worldPos.setTransformedPos_00c7f640(&rb->m_pMotionState.m_kMotionTransform, &m_kMousePositionInWorld);

    *(LocalM128*)&deltaPos = _mm_sub_ps(*(LocalM128*)&worldPos, *(LocalM128*)&m_kGrabPointInBodySpace);

    MotionExt* motion = rb->hkpRigidBody_getStoredDynamicMotion_00ca86c0() ? (MotionExt*)rb->hkpRigidBody_getStoredDynamicMotion_00ca86c0() : &rb->m_pMotionState;

    LocalM128 invMassVec =
        _mm_shuffle_ps(*(LocalM128*)&motion->m_kInertiaAndMassInv, *(LocalM128*)&motion->m_kInertiaAndMassInv, 0xff);
    _mm_store_ss(&maxImpulse, invMassVec);

    *(LocalM128*)&r = _mm_sub_ps(*(LocalM128*)&worldPos, *(LocalM128*)&rb->m_pMotionState.m_centerOfMassInWorld);

    crossR.FUN_00cd4cc0(&r);

    motion->GetLocalInverseInertia(&matrices.inertiaInvWorld);

    *(LocalM128*)&work.K.m_kColumn0 = _mm_setzero_ps();
    work.K.m_kColumn0.x = maxImpulse;
    *(LocalM128*)&work.K.m_kColumn1 = _mm_setzero_ps();
    work.K.m_kColumn1.y = maxImpulse;
    *(LocalM128*)&work.K.m_kColumn2 = _mm_setzero_ps();
    work.K.m_kColumn2.z = maxImpulse;

    matrices.tempMat1.hkMatrix3_setMul((int*)&crossR, (int)&matrices.inertiaInvWorld);
    matrices.tempMat2.hkMatrix3_setMul((int*)&matrices.tempMat1, (int)&crossR);

    work.K.Subtract(&matrices.tempMat2);

    if (work.K.invert_00cd4f10(DAT_0106c288) == 0)
    {
        *(LocalM128*)&work.lin = *(LocalM128*)&rb->m_pMotionState.m_kTranslationalVelocity;
        LocalM128 dampLoad1 = _mm_load_ss(&m_fTau);
        LocalM128 dampSplat1 = _mm_shuffle_ps(dampLoad1, dampLoad1, 0);
        *(LocalM128*)&work.lin = _mm_mul_ps(*(LocalM128*)&work.lin, dampSplat1);
        rb->OnTrigger(&work.lin);

        *(LocalM128*)&work.ang = *(LocalM128*)&rb->m_pMotionState.m_kAngularVelocity;
        LocalM128 dampLoad2 = _mm_load_ss(&m_fTau);
        LocalM128 dampSplat2 = _mm_shuffle_ps(dampLoad2, dampLoad2, 0);
        *(LocalM128*)&work.ang = _mm_mul_ps(*(LocalM128*)&work.ang, dampSplat2);
        rb->hkpRigidBody_setAngularVelocity(&work.ang);

        rb->hkpRigidBody_getPointVelocity(&worldPos, &r);

        float springFactor = m_fSpringElasticity * stepInfo.m_fInverseDeltaTime;
        LocalM128 term1 =
            _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&springFactor), _mm_load_ss(&springFactor), 0), *(LocalM128*)&deltaPos);
        *(LocalM128*)&angVel = term1;
        LocalM128 sdLoad = _mm_load_ss(&m_fSpringDamping);
        LocalM128 sdSplat = _mm_shuffle_ps(sdLoad, sdLoad, 0);
        LocalM128 term2 = _mm_mul_ps(sdSplat, *(LocalM128*)&r);
        *(LocalM128*)&angVel = _mm_add_ps(term2, term1);

        impulse.hkVector4_setMul3(&work.K, &angVel);

        *(LocalM128*)&impulse = _mm_xor_ps(*(LocalM128*)&impulse, *(LocalM128*)&DAT_010c44d0);

        LocalM128 sq = _mm_mul_ps(*(LocalM128*)&impulse, *(LocalM128*)&impulse);
        LocalM128 y = _mm_shuffle_ps(sq, sq, 0x55);
        LocalM128 xy = _mm_add_ss(y, sq);
        LocalM128 z = _mm_shuffle_ps(sq, sq, 0xaa);
        LocalM128 xyz = _mm_add_ss(z, xy);
        _mm_store_ss(&lenSq, xyz);

        maxImpulse = motion->FUN_00c86430();
        maxImpulse = stepInfo.m_fTimeStep * maxImpulse * m_fMaxRelativeForce;

        if (lenSq > maxImpulse * maxImpulse)
        {
            float sqrtLen = (float)sqrt(lenSq);
            float invLen = 1.0f / sqrtLen;
            float scale = invLen * maxImpulse;
            *(LocalM128*)&impulse =
                _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&scale), _mm_load_ss(&scale), 0), *(LocalM128*)&impulse);
        }

        rb->activate_00c9c1d0();
        rb->m_pMotionState.ApplyImpulseAtPoint(&impulse, &worldPos);

        for (int i = 0; i < m_kAppliedCallbacks.m_iElementCount; ++i)
        {
            ((MouseSpringCallback*)m_kAppliedCallbacks.m_data)[i](this, stepInfo, impulse);
        }
    }
}
