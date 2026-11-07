// src/havok/animation/animation/ik/lookat/hkalookatiksolver_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/animation/animation/ik/lookat/hkalookatiksolver.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/animation/ik/lookat/hkalookatiksolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/ik/lookat/hkalookatiksolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <xmmintrin.h>
float __cdecl ClampAsin(float value);
float __cdecl Hkaskeletonutils_ForwardCall_00ce00f0(float a, float b);
extern "C" const double DAT_01032980;
// 1.0e-4, the length epsilon
static const float kZero = 0.0f;
void __cdecl Object_ProcessAndReturnValue_00ce01c0(__m128* vec);

#include <math.h>
typedef float hkReal;
typedef __m128 hkQuadReal;
extern const hkQuadReal DAT_010c71e0;
extern const hkQuadReal DAT_01017d10;  // hkVector4::setAbs4 absMask

class S00ce0290_hkBool
{
  public:
    __forceinline S00ce0290_hkBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    __forceinline S00ce0290_hkBool& operator=(bool e)
    {
        m_cBooleanValue = static_cast<char>(e);
        return *this;
    }

  private:
    char m_cBooleanValue;
};

class S00ce0290_hkSimdReal
{
  public:
    __forceinline S00ce0290_hkSimdReal(const hkQuadReal& x) : m_vValue(x)
    {}
    __forceinline operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const hkQuadReal& getQuad() const
    {
        return m_vValue;
    }

  private:
    hkQuadReal m_vValue;
};
typedef const S00ce0290_hkSimdReal& S00ce0290_hkSimdRealParameter;

__forceinline S00ce0290_hkSimdReal operator/(S00ce0290_hkSimdRealParameter r, S00ce0290_hkSimdRealParameter s)
{
    return _mm_div_ss(r.getQuad(), s.getQuad());
}

class S00ce0290_hkVector4Comparison
{
  public:
    enum Mask
    {
        MASK_XYZ = 7
    };
    __forceinline int allAreSet(Mask m) const
    {
        return (_mm_movemask_ps(m_uiMask) & m) == m;
    }
    hkQuadReal m_uiMask;
};

class S00ce0290_hkMatrix3;
class S00ce0290_hkQuaternion;

class S00ce0290_hkVector4
{
  public:
    __forceinline void operator=(const S00ce0290_hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline hkQuadReal& getQuad()
    {
        return m_vComponents;
    }
    __forceinline const hkQuadReal& getQuad() const
    {
        return m_vComponents;
    }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    __forceinline void setAll3(hkReal a)
    {
        m_vComponents = _mm_set_ps1(a);
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void setAdd4(const S00ce0290_hkVector4& v0, const S00ce0290_hkVector4& v1)
    {
        m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void setSub4(const S00ce0290_hkVector4& v0, const S00ce0290_hkVector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void setMul4(const S00ce0290_hkVector4& a, const S00ce0290_hkVector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const S00ce0290_hkVector4& x, const S00ce0290_hkVector4& y)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setAddMul4(const S00ce0290_hkVector4& a, const S00ce0290_hkVector4& x,
                                  const S00ce0290_hkVector4& y)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setCross(const S00ce0290_hkVector4& v0, const S00ce0290_hkVector4& v1)
    {
        hkQuadReal cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        hkQuadReal cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline S00ce0290_hkVector4Comparison compareLessThanEqual4(const S00ce0290_hkVector4& a) const
    {
        S00ce0290_hkVector4Comparison m;
        m.m_uiMask = _mm_cmple_ps(m_vComponents, a.m_vComponents);
        return m;
    }
    __forceinline void setAbs4(const S00ce0290_hkVector4& v)
    {
        m_vComponents = _mm_and_ps(v.m_vComponents, DAT_01017d10);
    }
    __forceinline void setMin4(const S00ce0290_hkVector4& a, const S00ce0290_hkVector4& b)
    {
        m_vComponents = _mm_min_ps(a.getQuad(), b.getQuad());
    }
    __forceinline void setMax4(const S00ce0290_hkVector4& a, const S00ce0290_hkVector4& b)
    {
        m_vComponents = _mm_max_ps(a.getQuad(), b.getQuad());
    }
    __forceinline S00ce0290_hkSimdReal dot3(const S00ce0290_hkVector4& a) const
    {
        hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), xySum);
    }
    __forceinline S00ce0290_hkSimdReal length3() const
    {
        return _mm_sqrt_ss(this->dot3(*this).getQuad());
    }
    __forceinline S00ce0290_hkSimdReal lengthInverse3() const
    {
        const hkQuadReal half = _mm_set_ss(0.5f);
        const hkQuadReal three = _mm_set_ss(3.0f);
        const hkQuadReal zero = _mm_set_ss(0.0f);
        const hkQuadReal len2 = this->dot3(*this).getQuad();
        const hkQuadReal len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const hkQuadReal approx = _mm_rsqrt_ss(len2);
        const hkQuadReal refined =
            _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline void normalize3()
    {
        hkQuadReal lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    __forceinline void broadcast(int i)
    {
        if (i == 0)
        {
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(0, 0, 0, 0));
        }
        else if (i == 1)
        {
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
        }
        else if (i == 2)
        {
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
        }
        else if (i == 3)
        {
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
        }
    }
    __forceinline void setBroadcast(const S00ce0290_hkVector4& v, int i)
    {
        if (i == 0)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(0, 0, 0, 0));
        }
        else if (i == 1)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
        }
        else if (i == 2)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
        }
        else if (i == 3)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
        }
    }
    __forceinline int equals3(const S00ce0290_hkVector4& v, hkReal epsilon) const
    {
        S00ce0290_hkVector4 t;
        t.setSub4(*this, v);
        t.setAbs4(t);
        S00ce0290_hkVector4 epsilon_v;
        epsilon_v.setAll3(epsilon);
        return t.compareLessThanEqual4(epsilon_v).allAreSet(S00ce0290_hkVector4Comparison::MASK_XYZ);
    }
    __forceinline hkReal& operator()(int a)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[a];
    }
    __forceinline void SetRotatedDirection(const S00ce0290_hkQuaternion& quat, const S00ce0290_hkVector4& direction);
    void hkVector4_setMul3(const S00ce0290_hkMatrix3& a, const S00ce0290_hkVector4& b);

    hkQuadReal m_vComponents;
};

class S00ce0290_hkQuaternion
{
  public:
    __forceinline S00ce0290_hkQuaternion()
    {}
    __forceinline void operator=(const S00ce0290_hkQuaternion& q)
    {
        m_vec = q.m_vec;
    }
    __forceinline const S00ce0290_hkVector4& getImag() const
    {
        return m_vec;
    }
    void hkQuaternion_setAxisAngle(const S00ce0290_hkVector4& axis, hkReal angle);
    void setMul(const S00ce0290_hkQuaternion& q0, const S00ce0290_hkQuaternion& q1);
    void SetQuaternionProduct(const S00ce0290_hkQuaternion& q);  // mul
    S00ce0290_hkVector4 m_vec;
};

__forceinline void S00ce0290_hkVector4::SetRotatedDirection(const S00ce0290_hkQuaternion& quat,
                                                            const S00ce0290_hkVector4& direction)
{
    S00ce0290_hkVector4 minusHalf;
    minusHalf.getQuad() = DAT_010c71e0;
    S00ce0290_hkVector4 qreal;
    qreal.setBroadcast(quat.m_vec, 3);
    S00ce0290_hkVector4 q2minus1;
    q2minus1.setAddMul4(minusHalf, qreal, qreal);

    S00ce0290_hkVector4 ret;
    ret.setMul4(direction, q2minus1);

    S00ce0290_hkVector4 imagDotDir;
    imagDotDir.getQuad() = quat.getImag().dot3(direction).getQuad();
    imagDotDir.broadcast(0);
    ret.addMul4(imagDotDir, quat.getImag());

    S00ce0290_hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

// local form of hkMatrix3: 0x00ce0290 needs inline matrix construction/setCols and QsTransform getters; shared out-of-line calls do not reproduce exe bytes.
class S00ce0290_hkMatrix3
{
  public:
    __forceinline S00ce0290_hkMatrix3()
    {}
    __forceinline void setCols(const S00ce0290_hkVector4& c0, const S00ce0290_hkVector4& c1,
                               const S00ce0290_hkVector4& c2)
    {
        m_kColumn0 = c0;
        m_kColumn1 = c1;
        m_kColumn2 = c2;
    }
    void FUN_00cd4ba0(const S00ce0290_hkMatrix3& s);
    S00ce0290_hkVector4 m_kColumn0;
    S00ce0290_hkVector4 m_kColumn1;
    S00ce0290_hkVector4 m_kColumn2;
};

// local form of hkQsTransform: 0x00ce0290 needs inline matrix construction/setCols and QsTransform getters; shared out-of-line calls do not reproduce exe bytes.
class S00ce0290_hkQsTransform
{
  public:
    __forceinline const S00ce0290_hkVector4& getTranslation() const
    {
        return m_vTranslation;
    }
    __forceinline const S00ce0290_hkQuaternion& getRotation() const
    {
        return m_rotation;
    }
    S00ce0290_hkVector4 m_vTranslation;
    S00ce0290_hkQuaternion m_rotation;
    S00ce0290_hkVector4 m_vScale;
};

__forceinline hkReal S00ce0290_sqrt(hkReal r)
{
    return sqrtf(r);
}
__forceinline hkReal S00ce0290_fabs(hkReal r)
{
    return fabsf(r);
}
__forceinline hkReal S00ce0290_sin(hkReal r)
{
    return sinf(r);
}
__forceinline hkReal S00ce0290_cos(hkReal r)
{
    return cosf(r);
}
__forceinline hkReal S00ce0290_max2(hkReal x, hkReal y)
{
    return x > y ? x : y;
}

inline hkReal __cdecl ClampedAcos(hkReal r)
{
    if (S00ce0290_fabs(r) >= 1.0f)
    {
        r = (r > 0) ? 0 : 3.14159265358979f;
        return r;
    }
    return acosf(r);
}

class S00ce0290_LookAt
{
  public:
    struct Setup
    {
        S00ce0290_hkVector4 m_kFirstVector;
        S00ce0290_hkVector4 m_kMiddleVector;
        S00ce0290_hkVector4 m_kThirdVector;
        hkReal m_fTrailingReal;
    };
    struct BoneTransformRange
    {
        hkReal m_fFirstRangeValue;
        hkReal m_fSecondRangeValue;
        hkReal m_fThirdRangeValue;
        hkReal m_fFourthRangeValue;
        S00ce0290_hkVector4 m_kRangeVector;
    };
    static S00ce0290_hkBool __cdecl hkaLookAtIkSolver_solve(const Setup& setup, const S00ce0290_hkVector4& targetMS, hkReal gain,
                                                 S00ce0290_hkQsTransform& boneModelSpaceInOut,
                                                 const BoneTransformRange* range);
    static void __cdecl HkalookatiksolverGsEhscNogsNoehsc_UpdateState_00ce0110(S00ce0290_hkVector4& sphericalInCartesianOut);
    static void __cdecl Object_ProcessAndReturnValue_00ce01c0(S00ce0290_hkVector4& cartesianInSphericalOut);
};

// @fnv 0x00ce0290
// src: COMMUNITY 0x00ce0290
S00ce0290_hkBool __cdecl S00ce0290_LookAt::hkaLookAtIkSolver_solve(const Setup& setup, const S00ce0290_hkVector4& targetMS,
                                                        hkReal gain, S00ce0290_hkQsTransform& boneModelSpaceInOut,
                                                        const BoneTransformRange* range)
{
    hkReal limitAngle = setup.m_fTrailingReal;
    if (range)
    {
        limitAngle = S00ce0290_fabs(range->m_fThirdRangeValue);
        limitAngle = S00ce0290_max2(limitAngle, S00ce0290_fabs(range->m_fFourthRangeValue));
        limitAngle = S00ce0290_max2(limitAngle, S00ce0290_fabs(range->m_fFirstRangeValue));
        limitAngle = S00ce0290_max2(limitAngle, S00ce0290_fabs(range->m_fSecondRangeValue));
    }

    const S00ce0290_hkVector4& bonePosMS = boneModelSpaceInOut.getTranslation();
    S00ce0290_hkVector4 vecToTargetMS;
    vecToTargetMS.setSub4(targetMS, bonePosMS);
    const hkReal targetDist = vecToTargetMS.length3();
    vecToTargetMS.normalize3();

    S00ce0290_hkBool insideLimits(true);

    const hkReal cosTargetAngle = vecToTargetMS.dot3(setup.m_kThirdVector);
    const hkReal cosLimitAngle = S00ce0290_cos(limitAngle);
    if (cosTargetAngle < cosLimitAngle)
    {
        S00ce0290_hkVector4 cross;
        cross.setCross(setup.m_kThirdVector, vecToTargetMS);
        cross.normalize3();
        S00ce0290_hkQuaternion q;
        q.hkQuaternion_setAxisAngle(cross, limitAngle);
        vecToTargetMS.SetRotatedDirection(q, setup.m_kThirdVector);
        insideLimits = false;
    }

    if (range)
    {
        S00ce0290_hkVector4 vecToTargetMSOld = vecToTargetMS;

        S00ce0290_hkVector4 sideAxisMS;
        sideAxisMS.setCross(range->m_kRangeVector, setup.m_kThirdVector);

        S00ce0290_hkMatrix3 worldFromFSU;
        S00ce0290_hkMatrix3 fsuFromWorld;
        worldFromFSU.setCols(setup.m_kThirdVector, sideAxisMS, range->m_kRangeVector);
        fsuFromWorld.FUN_00cd4ba0(worldFromFSU);

        S00ce0290_hkVector4 vec;
        vec.hkVector4_setMul3(fsuFromWorld, vecToTargetMS);
        Object_ProcessAndReturnValue_00ce01c0(vec);

        S00ce0290_hkVector4 maxVec;
        maxVec.set(3.40282e+38f, range->m_fThirdRangeValue, range->m_fFirstRangeValue, 0.0f);
        S00ce0290_hkVector4 minVec;
        minVec.set(-3.40282e+38f, range->m_fFourthRangeValue, range->m_fSecondRangeValue, 0.0f);

        S00ce0290_hkVector4 limitedVec = vec;
        limitedVec.setMin4(limitedVec, maxVec);
        limitedVec.setMax4(limitedVec, minVec);
        HkalookatiksolverGsEhscNogsNoehsc_UpdateState_00ce0110(limitedVec);

        vecToTargetMS.hkVector4_setMul3(worldFromFSU, limitedVec);

        if (!vecToTargetMS.equals3(vecToTargetMSOld, 0.001f))
        {
            insideLimits = false;
        }
    }

    {
        S00ce0290_hkVector4 fwdMS;
        fwdMS.SetRotatedDirection(boneModelSpaceInOut.getRotation(), setup.m_kFirstVector);

        S00ce0290_hkVector4 cross;
        cross.setCross(fwdMS, vecToTargetMS);
        cross.normalize3();

        const hkReal cosAngle = vecToTargetMS.dot3(fwdMS);
        const hkReal angle = ClampedAcos(cosAngle) * gain;

        S00ce0290_hkQuaternion q;
        q.hkQuaternion_setAxisAngle(cross, angle);

        const hkReal eyeDistLS = setup.m_kMiddleVector.length3();
        if (eyeDistLS > 0.0)
        {
            S00ce0290_hkVector4 tmpAxis;
            tmpAxis.setCross(setup.m_kFirstVector, setup.m_kMiddleVector);
            tmpAxis.normalize3();

            S00ce0290_hkVector4 projAxis;
            projAxis.setCross(tmpAxis, setup.m_kFirstVector);
            projAxis.normalize3();

            const hkReal eyeHeighLS = projAxis.dot3(setup.m_kMiddleVector) / projAxis.length3();

            const hkReal a1 = eyeHeighLS;
            const hkReal c1 = targetDist;
            const hkReal c12 = c1 * c1;
            const hkReal a12 = a1 * a1;
            const hkReal b1 = S00ce0290_sqrt(S00ce0290_fabs(c12 - a12));
            const hkReal b12 = b1 * b1;
            const hkReal a2 = S00ce0290_sqrt(S00ce0290_fabs(-2.0 * c12 * b12 + 2.0 * b12 * a12 + c12 * c12 +
                                                            2.0 * c12 * a12 + b12 * b12 + a12 * a12)) *
                              0.5 / b1;

            hkReal correctionAngle = 0.0f;
            if (a2 != 0.0)
            {
                correctionAngle = ClampedAcos(a1 / a2);
            }

            S00ce0290_hkVector4 eyePositionMS;
            eyePositionMS.SetRotatedDirection(boneModelSpaceInOut.getRotation(), setup.m_kMiddleVector);

            S00ce0290_hkVector4 crossCorrection;
            crossCorrection.setCross(fwdMS, eyePositionMS);
            crossCorrection.normalize3();

            S00ce0290_hkQuaternion qCorrection;
            qCorrection.hkQuaternion_setAxisAngle(crossCorrection, -correctionAngle);
            q.SetQuaternionProduct(qCorrection);
        }

        {
            S00ce0290_hkQuaternion newRotation;
            newRotation.setMul(q, boneModelSpaceInOut.getRotation());
            boneModelSpaceInOut.m_rotation = newRotation;
        }
    }

    return insideLimits;
}

// src: GUESS 0x00ce0110 (confidence: low)
void __cdecl S00ce0290_LookAt::HkalookatiksolverGsEhscNogsNoehsc_UpdateState_00ce0110(S00ce0290_hkVector4& sphericalInCartesianOut)
{
    const hkReal r = sphericalInCartesianOut(0);
    const hkReal theta = sphericalInCartesianOut(1);
    const hkReal phi = sphericalInCartesianOut(2);
    const hkReal rcos = S00ce0290_cos(phi) * r;
    sphericalInCartesianOut.set(S00ce0290_cos(theta) * rcos, S00ce0290_sin(theta) * rcos, S00ce0290_sin(phi) * r, 0.0f);
}

// src: GUESS 0x00ce01c0 (confidence: low)
void __cdecl S00ce0290_LookAt::Object_ProcessAndReturnValue_00ce01c0(S00ce0290_hkVector4& cartesianInSphericalOut)
{
    const hkReal eps = 0.0001f;
    const hkReal rho = cartesianInSphericalOut.length3();
    if (rho < eps)
    {
        cartesianInSphericalOut.setZero4();
    }
    else
    {
        const hkReal x = cartesianInSphericalOut(0);
        const hkReal y = cartesianInSphericalOut(1);
        const hkReal z = cartesianInSphericalOut(2);
        const hkReal phi = ::ClampAsin(z / rho);
        const hkReal theta = ::Hkaskeletonutils_ForwardCall_00ce00f0(y, x);
        cartesianInSphericalOut.set(rho, theta, phi, 0.0f);
    }
}
