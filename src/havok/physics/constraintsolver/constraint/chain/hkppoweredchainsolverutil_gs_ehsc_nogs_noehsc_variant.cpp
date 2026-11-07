#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#include "../../../../../../include/hkVector4.h"


// src/havok/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
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
#include "../../../../../../include/hkAabb.h"
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


__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline float& hkVector4::operator()(int i)
{
    return ((float*)&m_vComponents)[i];
}

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

// hkMatrix3 block of the powered-chain 6x6 matrix (Mat6), kept POD with no constructor so the aggregates copy as the original does.
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
