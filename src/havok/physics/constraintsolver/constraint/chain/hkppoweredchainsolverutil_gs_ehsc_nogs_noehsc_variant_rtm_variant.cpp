// src/havok/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkVector4.h"

struct FUN_00df0810_Channel
{
    float value1;
    float value2;
    int unk08;
    int unk0c;
    int unk10;
};
struct FUN_00df0810_Source
{
    unsigned char modes;
    FUN_00df0810_Channel channels[3];
};
struct FUN_00df0810_Dest
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float values[3];
    int unk1c;
};
void __cdecl CopyChannelValue(int index, int channel, FUN_00df0810_Source* sources, FUN_00df0810_Dest* dests);
#include <xmmintrin.h>
static __forceinline void CopyHelper(__m128* d, const void* s)
{
    d[0] = ((__m128*)s)[0];
    d[1] = ((__m128*)s)[1];
    d[2] = ((__m128*)s)[2];
    d[3] = ((__m128*)s)[3];
    d[4] = ((__m128*)s)[4];
    d[5] = ((__m128*)s)[5];
    d[6] = ((__m128*)s)[6];
    d[7] = ((__m128*)s)[7];
    d[8] = ((__m128*)s)[8];
}
struct ObjF
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
    float f0b4;
    float f0b8;
    float f0bc;
    float f0c0;
    float f0c4;
    float f0c8;
    float f0cc;
    float f0d0;
    float f0d4;
    float f0d8;
    float f0dc;
    float f0e0;
    float f0e4;
    float f0e8;
    float f0ec;
    float f0f0;
    float f0f4;
    float f0f8;
    float f0fc;
    float f100;
    float f104;
    float f108;
    float f10c;
    float f110;
    float f114;
    float f118;
    float f11c;
    float f120;
    float f124;
    float f128;
    float f12c;
    float f130;
    float f134;
    float f138;
    float f13c;
    float f140;
    float f144;
    float f148;
    float f14c;
    float f150;
    float f154;
    float f158;
    float f15c;
    float f160;
    float f164;
    float f168;
    float f16c;
    float f170;
    float f174;
    float f178;
    float f17c;
    float f180;
    float f184;
    float f188;
    float f18c;
    float f190;
    float f194;
    float f198;
    float f19c;
    float f1a0;
    float f1a4;
    float f1a8;
    float f1ac;
    float f1b0;
    float f1b4;
    float f1b8;
    float f1bc;
    float f1c0;
    float f1c4;
    float f1c8;
    float f1cc;
    float f1d0;
    float f1d4;
    float f1d8;
    float f1dc;
    float f1e0;
    float f1e4;
    float f1e8;
    float f1ec;
    float f1f0;
    float f1f4;
    float f1f8;
    float f1fc;
    float f200;
    float f204;
    float f208;
    float f20c;
    float f210;
    float f214;
    float f218;
    float f21c;
    float f220;
    float f224;
    float f228;
    float f22c;
    float f230;
    float f234;
    float f238;
    float f23c;
    float f240;
    float f244;
    float f248;
    float f24c;
    float f250;
    float f254;
    float f258;
    float f25c;
    float f260;
    float f264;
    float f268;
    float f26c;
    float f270;
    float f274;
    float f278;
    float f27c;
    float f280;
    float f284;
    float f288;
    float f28c;
    float f290;
    float f294;
    float f298;
    float f29c;
    float f2a0;
    float f2a4;
    float f2a8;
    float f2ac;
    float f2b0;
    float f2b4;
    float f2b8;
    float f2bc;
    float f2c0;
    float f2c4;
    float f2c8;
    float f2cc;
    float f2d0;
    float f2d4;
    float f2d8;
    float f2dc;
    float f2e0;
    float f2e4;
    float f2e8;
    float f2ec;
    float f2f0;
    float f2f4;
    float f2f8;
    float f2fc;
    float f300;
    float f304;
    float f308;
    float f30c;
    float f310;
    float f314;
    float f318;
    float f31c;
    float f320;
    float f324;
    float f328;
    float f32c;
    float f330;
    float f334;
    float f338;
    float f33c;
    float f340;
    float f344;
    float f348;
    float f34c;
    float f350;
    float f354;
    float f358;
    float f35c;
    float f360;
    float f364;
    float f368;
    float f36c;
    float f370;
    float f374;
    float f378;
    float f37c;
    float f380;
    float f384;
    float f388;
    float f38c;
    float f390;
    float f394;
    float f398;
    float f39c;
    float f3a0;
    float f3a4;
    float f3a8;
    float f3ac;
    float f3b0;
    float f3b4;
    float f3b8;
    float f3bc;
};
struct __declspec(align(16)) CBuf
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
};
struct __declspec(align(16)) BufA
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
    float f0b4;
    float f0b8;
    float f0bc;
    float f0c0;
    float f0c4;
    float f0c8;
    float f0cc;
    float f0d0;
    float f0d4;
    float f0d8;
    float f0dc;
    float f0e0;
    float f0e4;
    float f0e8;
    float f0ec;
    float f0f0;
    float f0f4;
    float f0f8;
    float f0fc;
    float f100;
    float f104;
    float f108;
    float f10c;
    float f110;
    float f114;
    float f118;
    float f11c;
    float f120;
    float f124;
    float f128;
    float f12c;
    float f130;
    float f134;
    float f138;
    float f13c;
    float f140;
    float f144;
    float f148;
    float f14c;
    float f150;
    float f154;
    float f158;
    float f15c;
    float f160;
    float f164;
    float f168;
    float f16c;
    float f170;
    float f174;
    float f178;
    float f17c;
};
struct __declspec(align(16)) BufB
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
    float f0b4;
    float f0b8;
    float f0bc;
};
extern void __cdecl ResetJacobianRows(int a, int b, void* c, void* d);
extern void __cdecl Object_ProcessEntries_00df07c0(int a, void* b);
extern void __cdecl _hkMatrix6SetTranspose(void* a, void* b);
extern void __cdecl hkMatrix3_ProcessEntries_00e29470(void* a, void* b, int c);
extern void __cdecl Object_SubtractVectorBundles(void* a, void* b);
extern void __cdecl Runtime_ForwardCall_00e298f0(void* a, void* b);
extern float DAT_0104da4c;
void __cdecl Hkppoweredchainsolverutil_UpdateState_00df0870(int arg0, ObjF* __restrict obj, int arg2, __m128* arg3, int* arg4);
struct MatrixGroup
{
    char data0[0xc0];
    char data1[0xc0];
    char pad[0x240];
};
struct InputStruct
{
    char pad0[4];
    int count;
    char pad1[0x18];
    MatrixGroup* matrices;
    char pad2[8];
    hkAabb* aabbs;
};
extern "C" void __cdecl hkVector4_ComputeValues_00e29510(void* out, const void* matrix, const void* in);
void __cdecl hkAabb_ProcessEntries_00df11a0(InputStruct* a, hkAabb* out);
template <class T> class Slot
{
  public:
    __forceinline T val() const
    {
        return m_uiFilterValue;
    }
    __forceinline operator T() const
    {
        return val();
    }
    __forceinline T operator->() const
    {
        return m_uiFilterValue;
    }

  private:
    T m_uiFilterValue;
};
template <class T> inline T largerOf(T x, T y)
{
    return x > y ? x : y;
}
__forceinline void hkVector4::setZero4() { m_vComponents = _mm_setzero_ps(); }
__forceinline float& hkVector4::operator()(int i) { return ((float*)&m_vComponents)[i]; }

class Quad8
{
  public:
    __forceinline void setZero8()
    {
        m_vLinearConstraint.setZero4();
        m_vAngularConstraint.setZero4();
    }
    __forceinline void setSub8(const Quad8& a, const Quad8& b)
    {
        m_vLinearConstraint.setSub4(a.m_vLinearConstraint, b.m_vLinearConstraint);
        m_vAngularConstraint.setSub4(a.m_vAngularConstraint, b.m_vAngularConstraint);
    }
    hkVector4 m_vLinearConstraint;
    hkVector4 m_vAngularConstraint;
};
// hkMatrix3 block of the powered-chain 6x6 matrix (Mat6) over this unit's hkVector4 stand-in.
struct ChainMatrix3
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};
struct Mat6
{
    ChainMatrix3 m_00;
    ChainMatrix3 m_01;
    ChainMatrix3 m_10;
    ChainMatrix3 m_11;
};
struct MotorAxis
{
    float m_usFlags;
    float m_minImpulse;
    float m_fVelocity;
    float m_fTau;
    float m_fMotorDamping;
};
struct AngularMotorInfo
{
    unsigned char m_ucReferenceTimeSteps;
    MotorAxis m_axes[3];

    inline int GetReferenceTimeStep(int idx) const
    {
        return (m_ucReferenceTimeSteps >> (2 * idx)) & 3;
    }
    inline void SetReferenceTimeStep(int idx, int value)
    {
        const int bits = (value & 3) << (2 * idx);
        const int mask = 3 << (2 * idx);
        m_ucReferenceTimeSteps &= (unsigned char)(~mask);
        m_ucReferenceTimeSteps |= (unsigned char)(bits);
    }
};
struct MatrixTriple
{
    Mat6 m_lower;
    Mat6 m_lowerInv;
    Mat6 m_kMiddle;
    Mat6 m_upper;
    Mat6 m_upperInv;
};
struct PoweredChain
{
    int m_unk00;
    Slot<int> m_iConstraintCount;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    Slot<MatrixTriple*> m_kMatrices;
    Slot<AngularMotorInfo*> m_ppMotors;
    Slot<Quad8*> m_velocities;
};
// @fnv 0x00df1260
// src: GUESS 0x00df1260 (confidence: low)
extern "C" void __cdecl Object_ProcessEntries_00df1260(PoweredChain* chain, int* chosenConstraint, int* chosenAxis, float* chosenImpulse)
{
    const Quad8* target = chain->m_velocities + 1;
    float worst = 0.0f;
    int bestConstraint = -1;
    int bestAxis = -1;
    Quad8 accum;
    accum.setZero8();
    for (int i = chain->m_iConstraintCount - 1; i >= 0; i--)
    {
        Quad8 product;
        hkVector4_ComputeValues_00e29510(&product, &chain->m_kMatrices[i].m_kMiddle, &accum);
        accum.setSub8(target[i], product);
        for (int axis = 0; axis < 3; axis++)
        {
            if (chain->m_ppMotors[i].GetReferenceTimeStep(axis) == 0)
            {
                const float value = accum.m_vAngularConstraint(axis);
                const float breach =
                    largerOf<float>(value - chain->m_ppMotors[i].m_axes[axis].m_usFlags * double(1.05f),
                                    -value + chain->m_ppMotors[i].m_axes[axis].m_minImpulse * double(1.05f));
                if (breach > worst)
                {
                    worst = breach;
                    bestConstraint = i;
                    bestAxis = axis;
                    *chosenImpulse = value;
                }
            }
        }
    }
    if (bestConstraint >= 0)
    {
        const float limit = chain->m_ppMotors[bestConstraint].m_axes[bestAxis].m_usFlags;
        const int state = (*chosenImpulse > limit) ? 1 : 3;
        chain->m_ppMotors[bestConstraint].SetReferenceTimeStep(bestAxis, state);
        *chosenConstraint = bestConstraint;
        *chosenAxis = bestAxis;
    }
}

#include <xmmintrin.h>
extern "C" __m128 _mm_load_ss(const float*);
template <class T> class Cell
{
    T value;

  public:
    __forceinline operator T() const
    {
        return value;
    }
};
class Scalar
{
    __m128 value;

  public:
    Scalar()
    {}
    __forceinline Scalar(float f)
    {
        value = _mm_load_ss(&f);
    }
    __forceinline Scalar(const __m128& q)
    {
        value = q;
    }
    __forceinline operator float() const
    {
        float r;
        _mm_store_ss(&r, value);
        return r;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
class Vector2
{
    __m128 value;

  public:
    __forceinline operator __m128() const
    {
        return value;
    }
    __forceinline void operator=(const __m128& x)
    {
        value = x;
    }
    __forceinline void setSub4(__m128 a, __m128 b)
    {
        value = _mm_sub_ps((__m128)a, (__m128)b);
    }
    __forceinline void setMul4(__m128 a, __m128 b)
    {
        value = _mm_mul_ps((__m128)a, (__m128)b);
    }
    __forceinline void mul4(const Vector2& a)
    {
        value = _mm_mul_ps(value, a.value);
    }
    __forceinline void mul4(const Scalar& s)
    {
        value = _mm_mul_ps(s.broadcast(), value);
    }
    __forceinline void add4(const Vector2& a)
    {
        value = _mm_add_ps(value, a.value);
    }
    __forceinline void setAdd4(__m128 a, __m128 b)
    {
        value = _mm_add_ps((__m128)a, (__m128)b);
    }
    __forceinline Scalar horizontalAdd3() const
    {
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(value, value, 0x55), value);
        return _mm_add_ss(_mm_shuffle_ps(value, value, 0xaa), xy);
    }
    __forceinline float& operator()(int i)
    {
        return ((float*)&value)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return ((const float*)&value)[i];
    }
};
struct Accumulator2
{
    unsigned char type;
    unsigned int deactivation;
    float gravity;
    Vector2 m_vLinearVelocity, m_vAngularVelocity, m_vInverseInertiaAndMass, m_sumLinear, m_sumAngular;
    __forceinline const Vector2& getSumLinearVel() const
    {
        return m_sumLinear;
    }
    __forceinline const Vector2& getSumAngularVel() const
    {
        return m_sumAngular;
    }
};

struct LinearJac
{
    Vector2 axis, angularA, angularB;
};
struct AngularJac
{
    Vector2 angularA, angularB;
};
struct AxisMotor
{
    float maxImpulse, minImpulse, velocity, tau, damping;
};
struct LinkMotor
{
    unsigned char state;
    AxisMotor axes[3];
};
struct VelocityPair
{
    Vector2 linear, angular;
};
struct AccumOffset
{
    int bytes;
    Accumulator2& get(Accumulator2* base) const
    {
        return *(Accumulator2*)((char*)base + bytes);
    }
};
struct ConstraintSolverState
{
    ObjF* solver;
    Cell<int> count;
    Cell<float> tau, damping;
    Cell<LinearJac*> linear;
    Cell<AngularJac*> angular;
    Cell<AccumOffset*> offsets;
    Cell<Accumulator2*> base;
    int matrices;
    Cell<LinkMotor*> motors;
};

static __forceinline Scalar linearCustom(const LinearJac& j, const Accumulator2& a, const Accumulator2& b,
                                         const ObjF& info, float tau, float damp, float rhs)
{
    Vector2 velocities;
    {
        Vector2 al, aa, bl, ba, dl, pa, pb;
        al.setSub4(a.m_vLinearVelocity, a.getSumLinearVel());
        aa.setSub4(a.m_vAngularVelocity, a.getSumAngularVel());
        bl.setSub4(b.m_vLinearVelocity, b.getSumLinearVel());
        ba.setSub4(b.m_vAngularVelocity, b.getSumAngularVel());
        const __m128& alias_al = al;
        const Vector2& alias_bl = bl;
        dl.setSub4(alias_al, alias_bl);
        const Vector2& sourceA = aa;
        pa.setMul4(sourceA, j.angularA);
        pb.setMul4(ba, j.angularB);
        dl.mul4(j.axis);
        pa.add4(pb);
        velocities.setAdd4(pa, dl);
    }
    Vector2 sums;
    {
        const Vector2 al = a.getSumLinearVel();
        const Vector2 aa = a.getSumAngularVel();
        const Vector2 bl = b.getSumLinearVel();
        const Vector2 ba = b.getSumAngularVel();
        Vector2 dl, pa, pb;
        dl.setSub4(al, bl);
        pa.setMul4(aa, j.angularA);
        pb.setMul4(ba, j.angularB);
        dl.mul4(j.axis);
        pa.add4(pb);
        sums.setAdd4(pa, dl);
    }
    sums.mul4(info.f040 * tau);
    velocities.mul4(damp);
    Vector2 total;
    total.setAdd4(sums, velocities);
    float dot = total.horizontalAdd3();
    float result = rhs * tau - dot;
    return result;
}
static __forceinline Scalar linearDv(const LinearJac& j, const Accumulator2& a, const Accumulator2& b, const ObjF& info,
                                     float tau, float damp)
{
    return linearCustom(j, a, b, info, tau, damp, j.axis(3));
}
static __forceinline Scalar angularDv(const AngularJac& j, const Accumulator2& a, const Accumulator2& b,
                                      const ObjF& info, float tau, float damp)
{
    Vector2 velocities;
    {
        Vector2 aa, ba, pa, pb;
        aa.setSub4(a.m_vAngularVelocity, a.getSumAngularVel());
        ba.setSub4(b.m_vAngularVelocity, b.getSumAngularVel());
        pa.setMul4(aa, j.angularA);
        pb.setMul4(ba, j.angularB);
        velocities.setAdd4(pa, pb);
    }
    Vector2 sums;
    {
        const Vector2 aa = a.getSumAngularVel();
        const Vector2 ba = b.getSumAngularVel();
        Vector2 pa, pb;
        pa.setMul4(aa, j.angularA);
        pb.setMul4(ba, j.angularB);
        sums.setAdd4(pa, pb);
    }
    sums.mul4(info.f040 * tau);
    velocities.mul4(damp);
    Vector2 total;
    total.setAdd4(sums, velocities);
    float dot = total.horizontalAdd3();
    float result = j.angularB(3) * tau - dot;
    return result;
}
// @fnv 0x00df0d30
// src: GUESS 0x00df0d30 (confidence: medium)
extern "C" void hkpPoweredChain_ComputeLinkVelocityDeltas(const ConstraintSolverState& info, VelocityPair* output)
{
    LinearJac* j = info.linear;
    AngularJac* k = info.angular;
    for (int link = 0; link < info.count; j += 3, k += 3, link++)
    {
        VelocityPair& dest = output[link];
        const Accumulator2* __restrict a = &info.offsets[link].get(info.base);
        const Accumulator2* __restrict b = &info.offsets[link + 1].get(info.base);
        const LinkMotor* motors = info.motors + link;
        for (int axis = 0; axis < 3; axis++)
        {
            dest.linear(axis) = linearDv(j[axis], *a, *b, *info.solver, info.tau, info.damping);
            dest.angular(axis) =
                angularDv(k[axis], *a, *b, *info.solver, motors->axes[axis].tau, motors->axes[axis].damping);
        }
        dest.linear(3) = 0.0f;
        dest.angular(3) = 0.0f;
    }
}

class ScalarValue
{
    __m128 value;

  public:
    ScalarValue()
    {}
    ScalarValue(const __m128& x) : value(x)
    {}
    ScalarValue(float x)
    {
        value = _mm_load_ss(&x);
    }
    operator float() const
    {
        float x;
        _mm_store_ss(&x, value);
        return x;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};

class VectorValue
{
    __m128 value;

  public:
    __forceinline void operator=(const VectorValue& x)
    {
        value = x.value;
    }
    __forceinline void sub(const VectorValue& a, const VectorValue& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void mul(const VectorValue& a, const VectorValue& b)
    {
        value = _mm_mul_ps(a.value, b.value);
    }
    __forceinline void add(const VectorValue& a, const VectorValue& b)
    {
        value = _mm_add_ps(a.value, b.value);
    }
    __forceinline void scale(const ScalarValue& s)
    {
        value = _mm_mul_ps(s.broadcast(), value);
    }
    __forceinline ScalarValue sum3() const
    {
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(value, value, 0x55), value);
        return _mm_add_ss(_mm_shuffle_ps(value, value, 0xaa), xy);
    }
    __forceinline float& operator()(int i)
    {
        return ((float*)&value)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return ((const float*)&value)[i];
    }
};

struct AngularPair
{
    VectorValue first, second;
    inline float rhs() const
    {
        return second(3);
    }
};
struct BodyAccum
{
    int type;
    int deactivation;
    float gravity;
    VectorValue linear, angular, inverseMass, scratch, sumAngular;
    inline const VectorValue& sum() const
    {
        return sumAngular;
    }
};
struct BodyOffset
{
    int offset;
    inline BodyAccum& resolve(BodyAccum* base) const
    {
        return *(BodyAccum*)((char*)base + offset);
    }
};
struct SolverBasis
{
    VectorValue unk00, unk10, unk20, unk30, inverseFactor;
};
struct ChainState
{
    const SolverBasis* solver;
    Slot<int> count;
    int unk08, unk0c, unk10;
    Slot<AngularPair*> jac;
    Slot<BodyOffset*> offsets;
    Slot<BodyAccum*> accum;
    void* matrices;
    Slot<AngularMotorInfo*> motors;
};

static __forceinline ScalarValue customVelocity(const AngularPair& jac, const BodyAccum& a, const BodyAccum& b,
                                                const SolverBasis& info, float tau, float damping, float rhs)
{
    VectorValue current;
    {
        VectorValue da, db, pa, pb;
        da.sub(a.angular, a.sum());
        db.sub(b.angular, b.sum());
        pa.mul(da, jac.first);
        pb.mul(db, jac.second);
        current.add(pa, pb);
    }
    VectorValue sums;
    {
        VectorValue sa = a.sum();
        VectorValue sb = b.sum();
        VectorValue pa, pb;
        pa.mul(sa, jac.first);
        pb.mul(sb, jac.second);
        sums.add(pa, pb);
    }
    sums.scale(info.inverseFactor(0) * tau);
    current.scale(damping);
    VectorValue combined;
    combined.add(sums, current);
    float reduction = combined.sum3();
    float dv = rhs * tau - reduction;
    return dv;
}
static __forceinline ScalarValue angularVelocity(const AngularPair& jac, const BodyAccum& a, const BodyAccum& b,
                                                 const SolverBasis& info, float tau, float damping)
{
    return customVelocity(jac, a, b, info, tau, damping, jac.rhs());
}
// @fnv 0x00df1060
// src: GUESS 0x00df1060 (confidence: low)
void __cdecl Object_UpdateFields_00df1060(int index, int axis, const ChainState& state, Quad8* out)
{
    int i = index;
    Quad8& dst = out[i];
    BodyAccum& a = state.offsets[i].resolve(state.accum);
    BodyAccum& b = state.offsets[i + 1].resolve(state.accum);
    AngularMotorInfo& row = state.motors[i];
    int c = axis;
    dst.m_vAngularConstraint(c) =
        angularVelocity(state.jac[3 * i + c], a, b, *state.solver, row.m_axes[c].m_fTau, row.m_axes[c].m_fMotorDamping);
}

#include <math.h>
typedef __m128 hkQuad;
class hkSimd
{
  public:
    __forceinline hkSimd(const hkQuad& x) : m_vValue(x)
    {}
    __forceinline hkSimd(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline hkSimd()
    {}
    __forceinline operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline hkQuad broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const hkQuad& getQuad() const
    {
        return m_vValue;
    }

  private:
    hkQuad m_vValue;
};
typedef const hkSimd& hkSimdParam;
class hkVec4
{
  public:
    __forceinline hkVec4()
    {}
    __forceinline void operator=(const hkVec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void add4(const hkVec4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setAdd4(const hkVec4& v0, const hkVec4& v1)
    {
        m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void setSub4(const hkVec4& v0, const hkVec4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void setMul4(const hkVec4& a, const hkVec4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(hkSimdParam s)
    {
        m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
    }
    __forceinline hkSimd horizontalAdd3() const
    {
        hkQuad xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55), m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa), xySum);
    }
    __forceinline float& operator()(int a)
    {
        return reinterpret_cast<float*>(&m_vComponents)[a];
    }
    __forceinline const float& operator()(int a) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[a];
    }
    hkQuad m_vComponents;
};
class hkVec8
{
  public:
    hkVec4 m_vLinearConstraint;
    hkVec4 m_vAngularConstraint;
    __forceinline void setZero8()
    {
        m_vLinearConstraint.setZero4();
        m_vAngularConstraint.setZero4();
    }
    __forceinline void add8(const hkVec8& a)
    {
        m_vLinearConstraint.add4(a.m_vLinearConstraint);
        m_vAngularConstraint.add4(a.m_vAngularConstraint);
    }
    __forceinline void setSub8(const hkVec8& a, const hkVec8& b)
    {
        m_vLinearConstraint.setSub4(a.m_vLinearConstraint, b.m_vLinearConstraint);
        m_vAngularConstraint.setSub4(a.m_vAngularConstraint, b.m_vAngularConstraint);
    }
};
// local form of hkMatrix3: 0x00df1430 needs inline matrix construction/setIdentity/accessors; shared form gives 1364 bytes vs exe 1446.
class hkMat3
{
  public:
    __forceinline hkMat3()
    {}
    __forceinline hkVec4& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    __forceinline float& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }
    __forceinline void setZero()
    {
        hkVec4 zero;
        zero.setZero4();
        getColumn(0) = zero;
        getColumn(1) = zero;
        getColumn(2) = zero;
    }
    __forceinline void setIdentity()
    {
        setZero();
        float one = 1.0f;
        (*this)(0, 0) = one;
        (*this)(1, 1) = one;
        (*this)(2, 2) = one;
    }
    hkVec4 m_kColumn0;
    hkVec4 m_kColumn1;
    hkVec4 m_kColumn2;
};
class hkMat6
{
  public:
    __forceinline hkMat6()
    {}
    __forceinline void setIdentity()
    {
        m_iUnknownValue2[0][0].setIdentity();
        m_iUnknownValue2[0][1].setZero();
        m_iUnknownValue2[1][0].setZero();
        m_iUnknownValue2[1][1].setIdentity();
    }
    hkMat3 m_iUnknownValue2[2][2];
};
template <class T> class hkPad
{
  public:
    __forceinline T val() const
    {
        return m_kStorage;
    }
    __forceinline operator T() const
    {
        return val();
    }

  private:
    T m_kStorage;
};
struct hkMotor1d
{
    float m_usFlags, m_minImpulse, m_fVelocity, m_fTau, m_fMotorDamping;
};
struct hkMotorInfo3d
{
    unsigned char m_ucReferenceTimeSteps;
    __forceinline int GetReferenceTimeStep(int idx) const
    {
        return (m_ucReferenceTimeSteps >> (2 * idx)) & 3;
    }
    __forceinline void SetReferenceTimeStep(int idx, int value)
    {
        const int shiftedValue = (value & 3) << (2 * idx);
        const int shiftedMask = 3 << (2 * idx);
        m_ucReferenceTimeSteps &= (unsigned char)(~shiftedMask);
        m_ucReferenceTimeSteps |= (unsigned char)(shiftedValue);
    }
    hkMotor1d m_kAngularMotors[3];
};
struct hkTriple
{
    hkMat6 m_lower, m_lowerInv, m_diag, m_upper, m_upperInv;
};
struct hkAccum
{
    int unk00, unk04, unk08, unk0c;
    hkVec4 m_vLinearVelocity, m_vAngularVelocity, m_vInverseInertiaAndMass, m_vCenterOfMass, m_scratch1;
    __forceinline const hkVec4& getScratch1() const
    {
        return m_scratch1;
    }
    __forceinline const hkVec4& getSumAngularVel() const
    {
        return getScratch1();
    }
};
template <class T> __forceinline T* hkAddOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}
struct hkAccumOffset
{
    unsigned int m_offset;
    __forceinline hkAccum& getAccumulator(hkAccum* base)
    {
        return *hkAddOffset(base, m_offset);
    }
};
class hkAngJac
{
  public:
    hkVec4 m_kAngularVelocity[2];
    __forceinline float getAngularRhs() const
    {
        return m_kAngularVelocity[1](3);
    }
};
struct hkSolverGlobal
{
    hkVec4 unk00, unk10, unk20, unk30, m_kTimeStep;
};
struct hkChainInfo
{
    const hkSolverGlobal* m_pSolverInfo;
    hkPad<int> m_iConstraintCount;
    int unk08, unk0c, unk10;
    hkPad<hkAngJac*> m_jacobians;
    hkPad<hkAccumOffset*> m_offsets;
    hkPad<hkAccum*> m_pVelocityAccumulatorA;
    hkPad<hkTriple*> m_kMatrices;
    hkPad<hkMotorInfo3d*> m_kAngularMotors;
    hkPad<hkVec8*> m_vectorG;
};
inline float hkFabs(float r)
{
    return fabsf(r);
}
__forceinline void reserveRegs(unsigned int)
{}
__forceinline void releaseRegs(unsigned int)
{}
__forceinline void loadAccums(const hkAccum&, const hkAccum&)
{
    reserveRegs(0xffff0000);
}
__forceinline void popAccums()
{
    releaseRegs(0xffff0000);
}
__forceinline hkSimd getAngularDv0CustomRhs(const hkAngJac& jac, const hkAccum& mA, const hkAccum& mB,
                                            const hkSolverGlobal& info, float tau, float damping, float rhs)
{
    hkVec4 d0;
    d0.setSub4(mA.m_vAngularVelocity, mA.getSumAngularVel());
    hkVec4 d1;
    d1.setSub4(mB.m_vAngularVelocity, mB.getSumAngularVel());
    hkVec4 x0;
    x0.setMul4(d0, jac.m_kAngularVelocity[0]);
    hkVec4 x1;
    x1.setMul4(d1, jac.m_kAngularVelocity[1]);
    hkVec4 dv;
    dv.setAdd4(x0, x1);
    hkVec4 s0 = mA.getSumAngularVel();
    hkVec4 s1 = mB.getSumAngularVel();
    hkVec4 y0;
    y0.setMul4(s0, jac.m_kAngularVelocity[0]);
    hkVec4 y1;
    y1.setMul4(s1, jac.m_kAngularVelocity[1]);
    hkVec4 sv;
    sv.setAdd4(y0, y1);
    sv.mul4(info.m_kTimeStep(0) * tau);
    dv.mul4(damping);
    hkVec4 sum;
    sum.setAdd4(sv, dv);
    float h = sum.horizontalAdd3();
    return rhs * tau - h;
}
__forceinline hkSimd getAngularDv0(const hkAngJac& jac, const hkAccum& mA, const hkAccum& mB,
                                   const hkSolverGlobal& info, float tau, float damping)
{
    return getAngularDv0CustomRhs(jac, mA, mB, info, tau, damping, jac.getAngularRhs());
}
// @fnv 0x00df1430
// src: GUESS 0x00df1430 (confidence: low)
void __cdecl hkChainInfo_ProcessEntries_00df1430(const hkChainInfo& info, int& modifiedConstraintIndex, int& modifiedCoordinateIndex,
                          hkVec8* impulse, void* motorsState)
{
    const hkVec8* g = ((hkVec8*)info.m_vectorG) + 1;
    float maxBreaching = 0.0f;
    int constraintIndex = -1;
    int coordinate = -1;
    hkVec8 impRight;
    impRight.setZero8();
    hkVec8 impCenter;
    impCenter.setZero8();
    hkVec8 impLeft;
    impLeft.setZero8();
    {
        hkVec8 tmp;
        hkVector4_ComputeValues_00e29510(&tmp, &((hkTriple*)info.m_kMatrices)[info.m_iConstraintCount - 1].m_diag, &impLeft);
        impLeft.setSub8(g[info.m_iConstraintCount - 1], tmp);
    }
    for (int i = info.m_iConstraintCount - 1; i >= 0; i--)
    {
        const int tIdx = i - 1;
        impRight = impCenter;
        impCenter = impLeft;
        const hkTriple* baseTriple = (hkTriple*)info.m_kMatrices + (short)tIdx;
        if (tIdx >= 0)
        {
            hkVec8 tmp;
            hkVector4_ComputeValues_00e29510(&tmp, &baseTriple->m_diag, &impLeft);
            impLeft.setSub8(g[tIdx], tmp);
        }
        else
        {
            impLeft.setZero8();
        }
        hkMat6 offDiagTransp;
        if (tIdx >= 0)
        {
            _hkMatrix6SetTranspose(&offDiagTransp, (void*)&baseTriple->m_upperInv);
        }
        else
        {
            offDiagTransp.setIdentity();
        }
        hkVec8 resultVelocityVec;
        hkVector4_ComputeValues_00e29510(&resultVelocityVec, &offDiagTransp, &impLeft);
        {
            hkVec8 tmp;
            hkVector4_ComputeValues_00e29510(&tmp, &baseTriple[1].m_upper, &impCenter);
            resultVelocityVec.add8(tmp);
            hkVector4_ComputeValues_00e29510(&tmp, &baseTriple[1].m_upperInv, &impRight);
            resultVelocityVec.add8(tmp);
        }
        for (int c = 0; c < 3; c++)
        {
            const int state = ((hkMotorInfo3d*)info.m_kAngularMotors)[i].GetReferenceTimeStep(c);
            if (state == 3 || state == 1)
            {
                const int gi = i;
                hkAccum& mA = ((hkAccumOffset*)info.m_offsets)[gi].getAccumulator(info.m_pVelocityAccumulatorA);
                hkAccum& mB = ((hkAccumOffset*)info.m_offsets)[gi + 1].getAccumulator(info.m_pVelocityAccumulatorA);
                loadAccums(mA, mB);
                const hkMotorInfo3d* ami = (hkMotorInfo3d*)info.m_kAngularMotors + gi;
                const float targetVelocity =
                    getAngularDv0(((hkAngJac*)info.m_jacobians)[gi * 3 + c], mA, mB, *info.m_pSolverInfo,
                                  ami->m_kAngularMotors[c].m_fTau, ami->m_kAngularMotors[c].m_fMotorDamping);
                popAccums();
                const float resultVelocity = resultVelocityVec.m_vAngularConstraint(c);
                if ((state == 3 && resultVelocity <= targetVelocity) ||
                    (state == 1 && resultVelocity >= targetVelocity))
                {
                    const float velocityBreach = hkFabs(resultVelocity - targetVelocity);
                    if (velocityBreach > maxBreaching)
                    {
                        maxBreaching = velocityBreach;
                        constraintIndex = gi;
                        coordinate = c;
                    }
                }
            }
        }
    }
    if (constraintIndex >= 0)
    {
        ((hkMotorInfo3d*)info.m_kAngularMotors)[constraintIndex].SetReferenceTimeStep(coordinate, 0);
        modifiedConstraintIndex = constraintIndex;
        modifiedCoordinateIndex = coordinate;
    }
}
