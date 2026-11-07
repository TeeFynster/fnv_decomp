#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/utilities/actions/spring/hkpspringaction_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/actions/spring/hkpspringaction.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/actions/spring/hkpspringaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/spring/hkpspringaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Keep the original intrinsic union: the SDK byte-array members would add
// /GS instrumentation with the original compiler.
// Exe 0x00d4d530 FUN_00d4d530: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2
extern "C" LocalM128 _mm_rcp_ps(LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpSpringAction.h"
#include "../../../../../../include/hkpEntity.h"
extern int g_unk01269168;
int* __cdecl hkpBinaryAction_getClassType();
void* __cdecl _fnv_zlib_memset(void* pvDst, int iValue, unsigned int uiNumBytes);
struct hkShape00D4F0
{
    unsigned short m_type;
    unsigned short unk02[0x47];
    hkShape00D4F0()
    {
        m_type = 2;
    }
};
struct hkShape90D4F0
{
    unsigned short m_type;
    unsigned short unk02[5];
    hkShape90D4F0()
    {
        m_type = 9;
    }
};
struct hkShape9CD4F0
{
    unsigned short m_type;
    unsigned short unk02[5];
    hkShape9CD4F0()
    {
        m_type = 8;
    }
};
struct hkShapeA8D4F0
{
    unsigned short m_type;
    unsigned short unk02;
    hkShapeA8D4F0()
    {
        m_type = 7;
    }
};
struct hkShapeB0D4F0
{
    unsigned short m_type;
    unsigned short unk02[0x37];
    hkShapeB0D4F0()
    {
        m_type = 4;
    }
};
struct hkShape120D4F0
{
    unsigned short m_type;
    hkShape120D4F0()
    {
        m_type = 12;
    }
};
class FUN_00d4f000
{
  public:
    hkShape00D4F0 m_s00;
    hkShape90D4F0 m_s90;
    hkShape9CD4F0 m_s9C;
    hkShapeA8D4F0 m_sA8;
    hkShapeA8D4F0 m_sAC;
    hkShapeB0D4F0 m_sB0;
    hkShape120D4F0 m_s120;

    FUN_00d4f000() throw();
};
struct FUN_00cf4d80
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
    float m_fMass;
    float m_fSpringConstant;
    float m_fDamping;
    bool m_bModifierActive;
    bool m_bEnableState;
    FUN_00cf4d80(void* a, void* b, unsigned long c);
};
extern int DAT_010d08f4;
extern float DAT_01013974;
extern float DAT_0101e2bc;
struct FUN_00d4d340 : FUN_00cf4d80
{
    FUN_00d4d340(void* a, void* b, unsigned long c);
};
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_sqrt_ss(LocalM128 a);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, LocalM128 a);
class hkpStiffSpringWrapperD4D3 : public hkBaseObject
{
  public:
    void UpdatePivotsAndRestLength(const hkVector4& kPivotAW, const hkVector4& kPivotBW);

    unsigned int unk04, unk08, unk0C, unk10, unk14;
    hkpEntity* m_pEntityA;
    hkpEntity* m_pEntityB;
    unsigned int unk20, unk24, unk28, unk2C;
    hkVector4 m_kPivotInA;
    hkVector4 m_kPivotInB;
    float m_fSpringRestLength;
};

extern "C" void _mm_store_ps(float*, LocalM128);
extern "C" LocalM128 _mm_load_ps1(const float*);
extern const float DAT_01017d00;
struct __declspec(align(16)) SpringVector
{
    LocalM128 q;
    LocalM128 get() const
    {
        return q;
    }
    void set(LocalM128 v)
    {
        q = v;
    }
    void __thiscall setTransformedPos_00c7f640(const void* transform, const hkVector4* local);
};
struct SpringMotion
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void apply(float dt, const hkVector4* force, const SpringVector* point);
};
inline void hkpEntity::ApplyForceAtPoint(float dt, const hkVector4& force, const SpringVector& point)
{
    activate_00c9c1d0();
    reinterpret_cast<SpringMotion*>(&m_pMotionState)->apply(dt, &force, &point);
}
struct SpringStep
{
    float unk00, unk04, deltaTime;
};
struct SpringAction : hkpSpringAction
{
    void __thiscall hkpSpringAction_applyAction(const SpringStep& step);
};
static LocalM128 dot3(LocalM128 a, LocalM128 b)
{
    LocalM128 p = _mm_mul_ps(a, b);
    LocalM128 y = _mm_shuffle_ps(p, p, 0x55);
    LocalM128 z = _mm_shuffle_ps(p, p, 0xaa);
    y = _mm_add_ss(y, p);
    z = _mm_add_ss(z, y);
    return z;
}
static float SpringLength3(LocalM128 v)
{
    float r;
    _mm_store_ss(&r, _mm_sqrt_ss(dot3(v, v)));
    return r;
}
static float SpringDot3(LocalM128 a, LocalM128 b)
{
    float r;
    _mm_store_ss(&r, dot3(a, b));
    return r;
}
extern "C" LocalM128 _mm_set_ss(float);
static LocalM128 SpringSplat(float v)
{
    LocalM128 s = _mm_set_ss(v);
    return _mm_shuffle_ps(s, s, 0);
}
extern "C" LocalM128 _mm_load_ss(const float*);
static LocalM128 SpringSplatRef(const float& v)
{
    LocalM128 s = _mm_load_ss(&v);
    return _mm_shuffle_ps(s, s, 0);
}
extern "C" LocalM128 _mm_set_ps1(float);
static LocalM128 SpringSplatMem(float v)
{
    LocalM128 s = _mm_load_ss(&v);
    return _mm_shuffle_ps(s, s, 0);
}
static LocalM128 broadcast(float v)
{
    return _mm_load_ps1(&v);
}
// @fnv 0x00d4d530
// src: HAVOK_SRC 0x00d4d530
void SpringAction::hkpSpringAction_applyAction(const SpringStep& step)
{
    hkpEntity* a = m_pEntityA;
    hkpEntity* b = m_pEntityB;
    SpringVector pointA, pointB, direction, velocityA, velocityB;
    pointA.setTransformedPos_00c7f640(&a->m_pMotionState.m_kMotionState.m_kMotionTransform, &m_kPositionA);
    pointB.setTransformedPos_00c7f640(&b->m_pMotionState.m_kMotionState.m_kMotionTransform, &m_kPositionB);
    float tolerance = DAT_01017d00;
    LocalM128 displacement = _mm_sub_ps(pointB.get(), pointA.get());
    float length = SpringLength3(displacement);
    if (tolerance > length)
        return;
    direction.set(_mm_mul_ps(broadcast(1.0f / length), displacement));
    if (!m_bSpringEnabled && length < m_fRestLength)
        return;
    if (!m_bElastic && length > m_fRestLength)
        return;
    a->hkpRigidBody_getPointVelocity(&pointA, &velocityA);
    b->hkpRigidBody_getPointVelocity(&pointB, &velocityB);
    float force = (length - m_fRestLength) * m_fSpringStrength +
                  m_fMotorDamping * SpringDot3(_mm_sub_ps(velocityB.get(), velocityA.get()), direction.get());
    _mm_store_ps(&m_kLastForce.x, _mm_mul_ps(SpringSplatRef(-force), direction.get()));
    b->ApplyForceAtPoint(step.deltaTime, m_kLastForce, pointB);
    _mm_store_ps(&m_kLastForce.x, _mm_mul_ps(SpringSplatRef(force), direction.get()));
    a->ApplyForceAtPoint(step.deltaTime, m_kLastForce, pointA);
}
