
// src/havok/physics/constraintsolver/simplex/hkpsimplexsolver_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/constraintsolver/simplex/hkpsimplexsolver_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHs-c- /Gy (unit lists /MT /O2 /GS- /EHs-c- /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/constraintsolver/simplex/hkpsimplexsolver_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/constraintsolver/simplex/hkpsimplexsolver.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/constraintsolver/simplex/hkpsimplexsolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/simplex/hkpsimplexsolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>

namespace SolverMotionDetail {

typedef float SolverMotionReal;
typedef ::__m128 SolverMotionQuad;

class SolverMotionScalar
{
  public:
    __forceinline SolverMotionScalar(const SolverMotionQuad& x) : m_vValue(x)
    {}
    __forceinline SolverMotionScalar(const SolverMotionReal& x) : m_vValue((::_mm_load_ss)(&x))
    {}
    __forceinline operator SolverMotionReal() const
    {
        SolverMotionReal s;
        (::_mm_store_ss)(&s, m_vValue);
        return s;
    }
    __forceinline SolverMotionQuad broadcast() const
    {
        return (::_mm_shuffle_ps)(m_vValue, m_vValue, 0);
    }

  private:
    SolverMotionQuad m_vValue;
};
typedef const SolverMotionScalar& SolverMotionScalarArg;

class SolverMotionVector
{
  public:
    void operator=(const SolverMotionVector& v);
    void setSub4(const SolverMotionVector& v0, const SolverMotionVector& v1);
    void addMul4(SolverMotionScalarArg r, const SolverMotionVector& v1);
    void setAddMul4(const SolverMotionVector& a, const SolverMotionVector& b, SolverMotionScalarArg r);
    SolverMotionScalar dot3(const SolverMotionVector& a) const;
    SolverMotionScalar dot4xyz1(const SolverMotionVector& a) const;
    SolverMotionQuad m_vComponents;
};
__forceinline void SolverMotionVector::operator=(const SolverMotionVector& v)
{
    m_vComponents = v.m_vComponents;
}
__forceinline void SolverMotionVector::setSub4(const SolverMotionVector& v0, const SolverMotionVector& v1)
{
    m_vComponents = (::_mm_sub_ps)(v0.m_vComponents, v1.m_vComponents);
}
__forceinline void SolverMotionVector::addMul4(SolverMotionScalarArg r, const SolverMotionVector& v1)
{
    m_vComponents = (::_mm_add_ps)(m_vComponents, (::_mm_mul_ps)(r.broadcast(), v1.m_vComponents));
}
__forceinline void SolverMotionVector::setAddMul4(const SolverMotionVector& a, const SolverMotionVector& b,
                                                  SolverMotionScalarArg r)
{
    m_vComponents = (::_mm_add_ps)(a.m_vComponents, (::_mm_mul_ps)(r.broadcast(), b.m_vComponents));
}
__forceinline SolverMotionScalar SolverMotionVector::dot3(const SolverMotionVector& a) const
{
    SolverMotionQuad x2 = (::_mm_mul_ps)(m_vComponents, a.m_vComponents);
    SolverMotionQuad xySum = (::_mm_add_ss)((::_mm_shuffle_ps)(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
    return (::_mm_add_ss)((::_mm_shuffle_ps)(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), xySum);
}
__forceinline SolverMotionScalar SolverMotionVector::dot4xyz1(const SolverMotionVector& a) const
{
    SolverMotionQuad x2 = (::_mm_mul_ps)(m_vComponents, a.m_vComponents);
    SolverMotionQuad xySum = (::_mm_add_ss)((::_mm_shuffle_ps)(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
    SolverMotionQuad zwSum = (::_mm_add_ss)((::_mm_shuffle_ps)(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)),
                                            (::_mm_shuffle_ps)(m_vComponents, m_vComponents, _MM_SHUFFLE(3, 3, 3, 3)));
    return (::_mm_add_ps)(xySum, zwSum);
}

struct SolverMotionSurface
{
    SolverMotionVector m_kTriangleNormal;
    SolverMotionVector m_fVelocity;
    SolverMotionReal m_fStaticFriction;
    SolverMotionReal m_fExtraUpStaticFriction;
    SolverMotionReal m_fExtraDownStaticFriction;
    SolverMotionReal m_fDynamicFriction;
    int m_priority;
};

struct SolverMotionInput
{
    SolverMotionVector m_vContactPosition;
    SolverMotionVector m_fVelocity;
    SolverMotionVector m_vThirdInputVector;
    SolverMotionVector m_vFourthInputVector;
    SolverMotionReal m_fTimeStep;
    SolverMotionReal m_fConstraintParameter;
    SolverMotionSurface* m_ppConstraints;
    int m_iConstraintCount;
};

struct SolverMotionInteraction
{
    enum hkpStatus
    {
        HK_STATUS_OK = 0,
        HK_STATUS_3D_FAILURE = 1,
        HK_STATUS_2D_FAILURE = 2
    };
    unsigned char m_ucByte0;
    unsigned char m_ucByte1;
    SolverMotionReal m_fValue0;
    SolverMotionReal m_fValue1;
    hkpStatus m_iResultCode;
};

struct SolverMotionOutput
{
    SolverMotionVector m_vContactPosition;
    SolverMotionVector m_fVelocity;
    SolverMotionReal m_fTimeStep;
    SolverMotionInteraction* m_pPlaneStatuses;
};

struct SolverMotionState
{
    struct SupportPlane
    {
        int m_uiEdgeIndex;
        const SolverMotionSurface* m_pHavokConstraint;
        SolverMotionInteraction* m_pPlaneStatus;
    };
    SupportPlane m_kActivePlanes[4];
    int m_iActivePlaneCount;
    SolverMotionReal m_fElapsedSimulationTime;
    const SolverMotionInput* m_pRayCastInput;
    SolverMotionOutput* m_pRayCastOutput;
};

extern void SolverMotionReport();

// src: GUESS 0x00d23f50 (confidence: low)
static __declspec(noinline) void hkVector4_ProcessEntries_00d23f50(SolverMotionState& info)
{
    info.m_iActivePlaneCount--;
    SolverMotionReport();
}

// @fnv 0x00d24360
// src: COMMUNITY 0x00d24360
extern "C" void __cdecl hkSimplexSolverSolve(const SolverMotionInput& input, SolverMotionOutput& output)
{
    SolverMotionState info;
    info.m_iActivePlaneCount = 0;
    info.m_fElapsedSimulationTime = 0.0f;
    info.m_pRayCastInput = &input;
    info.m_pRayCastOutput = &output;

    SolverMotionReal timeLeft = input.m_fTimeStep;

    SolverMotionVector& velocity = output.m_fVelocity;
    velocity = input.m_fVelocity;

    SolverMotionVector& position = output.m_vContactPosition;
    position = input.m_vContactPosition;

    for (int i = 0; i < input.m_iConstraintCount; i++)
    {
        SolverMotionInteraction& interaction = output.m_pPlaneStatuses[i];
        interaction.m_ucByte1 = false;
        interaction.m_ucByte0 = false;
        interaction.m_fValue0 = 0.0f;
        interaction.m_fValue1 = 0.0f;
        interaction.m_iResultCode = SolverMotionInteraction::HK_STATUS_OK;
    }

    while (timeLeft >= 0.0f)
    {
        int hitIndex = -1;
        SolverMotionReal minHitTime = timeLeft;

        for (int i = 0; i < input.m_iConstraintCount; i++)
        {
            if (info.m_iActivePlaneCount >= 1 && info.m_kActivePlanes[0].m_uiEdgeIndex == i)
                continue;
            if (info.m_iActivePlaneCount >= 2 && info.m_kActivePlanes[1].m_uiEdgeIndex == i)
                continue;
            if (info.m_iActivePlaneCount >= 3 && info.m_kActivePlanes[2].m_uiEdgeIndex == i)
                continue;
            if (output.m_pPlaneStatuses[i].m_iResultCode != SolverMotionInteraction::HK_STATUS_OK)
                continue;

            const SolverMotionSurface& surface = input.m_ppConstraints[i];

            SolverMotionVector relVel;
            relVel.setSub4(velocity, surface.m_fVelocity);
            SolverMotionReal relVelDot = relVel.dot3(surface.m_kTriangleNormal);
            relVelDot = -relVelDot;
            if (relVelDot <= 0.0f)
                continue;

            SolverMotionVector relPos;
            relPos.setAddMul4(position, surface.m_fVelocity, -info.m_fElapsedSimulationTime);
            SolverMotionReal dist = surface.m_kTriangleNormal.dot4xyz1(relPos);
            if (dist <= 1.192092896e-07f)
                dist = 0.0f;
            dist += info.m_pRayCastOutput->m_pPlaneStatuses[i].m_fValue1;

            if (dist < minHitTime * relVelDot)
            {
                minHitTime = dist / relVelDot;
                hitIndex = i;
            }
        }

        if (minHitTime > 0.0001f)
        {
            info.m_fElapsedSimulationTime += minHitTime;
            timeLeft -= minHitTime;
            position.addMul4(minHitTime, velocity);
            for (int i = 0; i < info.m_iActivePlaneCount; i++)
            {
                info.m_kActivePlanes[i].m_pPlaneStatus->m_fValue0 += minHitTime;
                info.m_kActivePlanes[i].m_pPlaneStatus->m_ucByte0 = true;
            }
            output.m_fTimeStep = info.m_fElapsedSimulationTime;
            if (info.m_fElapsedSimulationTime > info.m_pRayCastInput->m_fConstraintParameter)
            {
                return;
            }
        }

        if (hitIndex < 0)
        {
            output.m_fTimeStep = input.m_fTimeStep;
            break;
        }

        SolverMotionState::SupportPlane& plane = info.m_kActivePlanes[info.m_iActivePlaneCount];
        info.m_iActivePlaneCount++;
        plane.m_pHavokConstraint = &input.m_ppConstraints[hitIndex];
        plane.m_pPlaneStatus = &output.m_pPlaneStatuses[hitIndex];
        plane.m_pPlaneStatus->m_fValue1 = (plane.m_pPlaneStatus->m_fValue1 + 1.192092896e-07f) * 2.0f;
        plane.m_uiEdgeIndex = hitIndex;

        hkVector4_ProcessEntries_00d23f50(info);
    }
}
}
