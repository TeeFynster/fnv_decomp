#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form

// src/havok/animation/ragdoll/instance/hkaragdollinstance_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/ragdoll/instance/hkaragdollinstance.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/ragdoll/instance/hkaragdollinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/instance/hkaragdollinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkaRagdollInstance.h"
#include "../../../../../include/hkaSkeleton.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkSimdReal.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkRotation.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkQsTransform.h"
#include "../../../../../include/hkQuaternion.h"
#include "../../../../../include/hkpRigidBody.h"
#include "../../../../../include/hkpMotion.h"

struct ArrayRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    hkMemoryAllocator* m_pStreamAllocator;
};
ArrayRouter* __cdecl hkMemoryRouter_getInstance();

#include <xmmintrin.h>
// FUN_00ce0d30 - build orthonormal basis from 3 indexed points, convert to quaternion via FUN_00cb26e0

extern float DAT_01016248;  // 0.5f
extern float DAT_01011d78;  // 0.0f
extern float DAT_01017718;  // 3.0f

// The shared SIMD-aligned vector changes instruction selection in 0x00ce0d30.
struct VecF
{
    float x, y, z, w;
};

struct Elem
{
    VecF v;
    float pad[8];
};

struct ThisX
{
    unsigned char pad[0x20];
    short m_i0;
    short m_i1;
    short m_i2;
};

static __forceinline __m128 Dot3(__m128 v)
{
    __m128 sq = _mm_mul_ps(v, v);
    __m128 t = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    return _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), t);
}

static __forceinline __m128 Normalize(__m128 v)
{
    __m128 dot = Dot3(v);
    __m128 e = _mm_rsqrt_ss(dot);
    __m128 q = _mm_mul_ss(_mm_mul_ss(dot, e), e);
    __m128 three = _mm_set_ss(DAT_01017718);
    __m128 half = _mm_set_ss(DAT_01016248);
    __m128 mask = _mm_cmpeq_ss(dot, _mm_set_ss(DAT_01011d78));
    __m128 f = _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(half, e), _mm_sub_ss(three, q)));
    return _mm_mul_ps(_mm_shuffle_ps(f, f, 0), v);
}

static __forceinline __m128 Cross(__m128 a, __m128 b)
{
    __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    return _mm_sub_ps(t2, t1);
}

// @fnv 0x00ce0d30
// src: COMMUNITY 0x00ce0d30
void __fastcall hkaPoseMatchingUtility_computeOrientation(ThisX* th, void* edx_unused, const Elem* points, VecF* out)
{
    VecF p0 = points[th->m_i0].v;
    VecF p1 = points[th->m_i1].v;
    VecF p2 = points[th->m_i2].v;

    __m128 e1 = _mm_sub_ps(_mm_load_ps(&p1.x), *(__m128*)&p0.x);
    __m128 n1 = Normalize(e1);
    __m128 e2 = _mm_sub_ps(_mm_load_ps(&p2.x), *(__m128*)&p0.x);
    __m128 n2 = Normalize(e2);
    __m128 c = Normalize(Cross(n2, n1));
    __m128 c2 = Normalize(Cross(c, n1));
    __m128 b = Cross(n1, c2);

    hkQuaternion obj;
    VecF axes[3];
    _mm_store_ps(&axes[0].x, c2);
    _mm_store_ps(&axes[1].x, b);
    _mm_store_ps(&axes[2].x, n1);
    obj.FUN_00cb26e0((int)&axes[0]);
    _mm_store_ps(&out->x, _mm_load_ps(reinterpret_cast<const float*>(&obj)));
}

ArrayRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* a, void* b, int c);

struct __declspec(align(16)) Pose32
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float unk14;
    int unk18;
    int unk1C;
};
struct SubObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* unk10;
};
struct Owner
{
    Pose32* data;
    int count;
    int capacity;
    int unk0C;
    SubObj sub;
    void hkaPoseMatchingUtility_computeOrientation(void* pose, Pose32* poseData);
    int hkaPoseMatchingUtility_addCandidatePose(void* pose, int arg2, float time);
};

static __m128 cross3(__m128 a, __m128 b)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                      _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}
static __m128 dot3(__m128 a, __m128 b)
{
    __m128 v = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v));
}
// src: GUESS 0x00ce0ff0 (confidence: low)
static __declspec(noinline) void hkQuaternion_ComputeValues_00ce0ff0(SubObj* object, Pose32* pose)
{
    __m128 axis = _mm_load_ps(reinterpret_cast<float*>(object));
    __declspec(align(16)) float absAxis[4];
    _mm_store_ps(absAxis, _mm_andnot_ps(_mm_set1_ps(-0.0f), axis));
    int major;
    if (absAxis[0] > absAxis[1])
        major = absAxis[0] > absAxis[2] ? 0 : 2;
    else
        major = absAxis[1] > absAxis[2] ? 1 : 2;
    __declspec(align(16)) float basis[4] = {0, 0, 0, 0};
    basis[(major + 1) % 3] = 1.0f;
    __m128 vector = _mm_load_ps(basis);
    __m128 q = _mm_load_ps(reinterpret_cast<float*>(pose));
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 d = dot3(q, vector);
    __m128 rotated = _mm_add_ps(_mm_mul_ps(cross3(q, vector), w),
                                _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), _mm_set1_ps(-0.5f)), vector),
                                           _mm_mul_ps(_mm_shuffle_ps(d, d, 0), q)));
    rotated = _mm_add_ps(rotated, rotated);
    __m128 third = cross3(rotated, axis);
    __m128 length = dot3(third, third);
    __m128 inverse = _mm_rsqrt_ss(length);
    inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), inverse),
                         _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(length, inverse), inverse)));
    inverse = _mm_andnot_ps(_mm_cmpeq_ss(length, _mm_setzero_ps()), inverse);
    third = _mm_mul_ps(third, _mm_shuffle_ps(inverse, inverse, 0));
    __m128 matrix[3] = {cross3(axis, third), axis, third};
    __declspec(align(16)) hkQuaternion orient;
    orient.FUN_00cb26e0(matrix);
    __declspec(align(16)) hkQuaternion conjugate;
    reinterpret_cast<__m128&>(conjugate) = _mm_xor_ps(reinterpret_cast<__m128&>(orient), _mm_set_ps(0.0f, -0.0f, -0.0f, -0.0f));
    __declspec(align(16)) hkQuaternion result;
    result.setMul(conjugate, *reinterpret_cast<hkQuaternion*>(pose));
    _mm_store_ps(reinterpret_cast<float*>(pose), reinterpret_cast<__m128&>(result));
}

// @fnv 0x00ce1420
// src: COMMUNITY 0x00ce1420
int Owner::hkaPoseMatchingUtility_addCandidatePose(void* pose, int arg2, float time)
{
    Pose32 poseData;
    poseData.unk14 = time;
    poseData.unk10 = arg2;
    hkaPoseMatchingUtility_computeOrientation(pose, &poseData);
    hkQuaternion_ComputeValues_00ce0ff0(&sub, &poseData);
    ArrayRouter* router = hkMemoryRouter_getInstance();
    if (count == (capacity & 0x3FFFFFFF))
        ResizeAudioStream(router->m_pStreamAllocator, this, 0x20);
    Pose32* destination = data + count;
    if (destination != 0)
        *destination = poseData;
    count += 1;
    return count - 1;
}

extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;
extern __m128 DAT_010c71b0;

// Inline implementations belong here; the shared headers provide the class declarations.
__forceinline void hkQuaternion::operator=(const hkQuaternion& q)
{
    reinterpret_cast<hkVector4&>(*this) = reinterpret_cast<const hkVector4&>(q);
}
__forceinline void hkQsTransform::operator=(const hkQsTransform& t)
{
    m_vTranslation = t.m_vTranslation;
    m_rotation = t.m_rotation;
    m_vScale = t.m_vScale;
}
__forceinline hkQuaternion::hkQuaternion() {}
__forceinline hkQsTransform::hkQsTransform() {}
__forceinline void hkQsTransform::setIdentity()
{
    m_vTranslation.m_vComponents = _mm_setzero_ps();
    reinterpret_cast<hkVector4&>(m_rotation).m_vComponents = DAT_010c71b0;
    m_vScale.m_vComponents = _mm_set1_ps(1.0f);
}
__forceinline hkSimdReal::hkSimdReal(const __m128& value) { m_vValue = value; }
__forceinline hkRotation::hkRotation() {}
__forceinline hkTransform::hkTransform() {}
__forceinline const hkVector4& hkTransform::getTranslation() const
{
    return reinterpret_cast<const hkVector4*>(this)[3];
}

    __forceinline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void hkVector4::addMul4(__m128 s, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void hkVector4::setNeg4(const hkVector4& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    __forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline hkSimdReal hkVector4::dot3(const hkVector4& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return hkSimdReal(_mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum));
    }

// The removed copies use the shared transform layout, skeleton offsets, and quaternion targets.
__forceinline hkVector4& QuaternionVector(hkQuaternion& q) { return reinterpret_cast<hkVector4&>(q); }
__forceinline const hkVector4& QuaternionVector(const hkQuaternion& q) { return reinterpret_cast<const hkVector4&>(q); }
__forceinline void hkQuaternion::SetConjugate(const hkQuaternion& q)
{
    QuaternionVector(*this).m_vComponents = _mm_xor_ps(DAT_010c4c00, QuaternionVector(q).m_vComponents);
}

inline __declspec(noinline) void hkQuaternion::SetProduct(const hkQuaternion& q0, const hkQuaternion& q1)
{
    __m128 a = QuaternionVector(q0).m_vComponents;
    __m128 b = QuaternionVector(q1).m_vComponents;
    __m128 cross = _mm_sub_ps(
        _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
        _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
    __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
    __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
    __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
    __m128 prod = _mm_mul_ps(b, a);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                            _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
    __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
    QuaternionVector(*this).m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
}
__declspec(noinline) void hkQsTransform::SetFromTransform(const hkTransform& kTransform)
{
    m_rotation.set(reinterpret_cast<const hkRotation&>(kTransform));
    m_vTranslation = kTransform.getTranslation();
    m_vScale.m_vComponents = DAT_010c7170;
}
// src: COMMUNITY 0x00ce5070
__declspec(noinline) void hkQsTransform::setFromTransformNoScale(const hkTransform& kTransform)
{
    m_rotation.set(reinterpret_cast<const hkRotation&>(kTransform));
    m_vTranslation = kTransform.getTranslation();
    m_vScale.m_vComponents = DAT_010c7170;
}

__forceinline void SetRotatedDirection(hkVector4& result, const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(QuaternionVector(quat).m_vComponents, QuaternionVector(quat).m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = QuaternionVector(quat).dot3(direction).m_vValue;
    ret.addMul4(imagDotDir, QuaternionVector(quat));
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(QuaternionVector(quat), direction);
    ret.addMul4(imagCrossDir, qreal);
    result.setAdd4(ret, ret);
}

__forceinline void ComposeReferenceTransform(hkQsTransform& result, const hkQsTransform& t1, const hkQsTransform& t2)
{
    hkVector4 temp;
    SetRotatedDirection(temp, t1.m_rotation, t2.m_vTranslation);
    result.m_vTranslation.setAdd4(temp, t1.m_vTranslation);
    result.m_rotation.SetProduct(t1.m_rotation, t2.m_rotation);
    result.m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
}

// Accumulated scale of a bone and all its parents in the reference pose.
__declspec(noinline) void __cdecl MultiplyBoneScales(const hkaSkeleton* pkSkeleton, const hkQsTransform* pkPose,
                                                     int iBone, hkVector4& kScaleOut)
{
    hkVector4 kScale;
    kScale.m_vComponents = DAT_010c7170;
    while (iBone != -1)
    {
        kScale.m_vComponents = _mm_mul_ps(pkPose[iBone].m_vScale.m_vComponents, kScale.m_vComponents);
        iBone = pkSkeleton->m_kParentIndices.m_data[iBone];
    }
    kScaleOut = kScale;
}

class FUN_00ce2000Owner
{
  public:
    int unk00;
    int unk04;
    hkpRigidBody** m_ppBodies;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int* m_piBoneToBody;
    int unk24;
    int unk28;
    hkaSkeleton* m_pkSkeleton;

    void ProcessAndReturnValue_00ce2000(int iBone, hkQsTransform& kOut);
};

// @fnv 0x00ce2000
// src: GUESS 0x00ce2000 (confidence: low)
void FUN_00ce2000Owner::ProcessAndReturnValue_00ce2000(int iBone, hkQsTransform& kOut)
{
    int iBody = m_piBoneToBody[iBone];
    if (iBody >= 0)
    {
        hkpRigidBody* pkBody = m_ppBodies[iBody];
        if (pkBody)
        {
            kOut.SetFromTransform(pkBody->m_pMotionState.m_kMotionState.m_kMotionTransform);
            MultiplyBoneScales(m_pkSkeleton, m_pkSkeleton->m_kReferencePose.m_data, iBone, kOut.m_vScale);
            return;
        }
    }

    hkQsTransform kParent;
    int iParent = m_pkSkeleton->m_kParentIndices.m_data[iBone];
    if (iParent >= 0)
        ProcessAndReturnValue_00ce2000(iParent, kParent);
    else
        kParent.setIdentity();
    ComposeReferenceTransform(kOut, kParent, m_pkSkeleton->m_kReferencePose.m_data[iBone]);
}

extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;
extern __m128 DAT_010c71b0;

// The approved hkMotionState has no EvaluateTransformAtTime declaration.
struct MotionStateC21
{
    void EvaluateTransformAtTime(float fTime, hkTransform& kTransformOut) const;
};

class FUN_00ce2150Owner
{
  public:
    int unk00;
    int unk04;
    hkpRigidBody** m_ppBodies;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int* m_piBoneToBody;
    int unk24;
    int unk28;
    hkaSkeleton* m_pkSkeleton;

    void hkaRagdollInstance_getApproxWorldFromBoneTransformAt(int iBone, float fTime, hkQsTransform& kOut);
};

// @fnv 0x00ce2150
// src: XBOX_PDB 0x00ce2150
void FUN_00ce2150Owner::hkaRagdollInstance_getApproxWorldFromBoneTransformAt(int iBone, float fTime, hkQsTransform& kOut)
{
    int iBody = m_piBoneToBody[iBone];
    if (iBody >= 0)
    {
        hkpRigidBody* pkBody = m_ppBodies[iBody];
        if (pkBody)
        {
            hkTransform kTransform;
            reinterpret_cast<const MotionStateC21*>(&pkBody->m_pMotionState)->EvaluateTransformAtTime(fTime, kTransform);
            kOut.SetFromTransform(kTransform);
            MultiplyBoneScales(m_pkSkeleton, m_pkSkeleton->m_kReferencePose.m_data, iBone, kOut.m_vScale);
            return;
        }
    }

    {
        hkQsTransform kParent;
        int iParent = m_pkSkeleton->m_kParentIndices.m_data[iBone];
        if (iParent >= 0)
            hkaRagdollInstance_getApproxWorldFromBoneTransformAt(iParent, fTime, kParent);
        else
            kParent.setIdentity();
        ComposeReferenceTransform(kOut, kParent, m_pkSkeleton->m_kReferencePose.m_data[iBone]);
    }
}

extern int DAT_01012068;

struct Ce0d30Obj
{
    void hkaPoseMatchingUtility_computeOrientation(void* arr, void* out);
};

struct Ce12a0Self
{
    int unk00, unk04, unk08, unk0c;
    void* unk10;
    int unk14, unk18, unk1c;
    short idx0, idx1, idx2;
};

class Ce12a0Host
{
  public:
    void UpdateFields_00ce12a0(void* a1, void* a2, hkQsTransform* a3, hkQsTransform* a4);
};

__forceinline void hkVector4::SetRotatedDirection(const hkVector4& q, const hkVector4& b)
{
    __m128 half = _mm_load_ps((const float*)&DAT_010c71e0);
    __m128 scalar = _mm_shuffle_ps(q.m_vComponents, q.m_vComponents, 0xff);
    __m128 factor = _mm_add_ps(half, _mm_mul_ps(scalar, scalar));
    __m128 base = _mm_mul_ps(b.m_vComponents, factor);
    hkSimdReal product = q.dot3(b);
    __m128 splat = _mm_shuffle_ps(product.m_vValue, product.m_vValue, 0);
    base = _mm_add_ps(base, _mm_mul_ps(splat, q.m_vComponents));
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(q.m_vComponents, q.m_vComponents, 0xc9), _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(q.m_vComponents, q.m_vComponents, 0xd2), _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
    __m128 crossed = _mm_sub_ps(first, second);
    base = _mm_add_ps(base, _mm_mul_ps(scalar, crossed));
    m_vComponents = _mm_add_ps(base, base);
}

// @fnv 0x00ce12a0
// src: GUESS 0x00ce12a0 (confidence: low)
void Ce12a0Host::UpdateFields_00ce12a0(void* a1, void* a2, hkQsTransform* a3, hkQsTransform* a4)
{
    Ce12a0Self* self = (Ce12a0Self*)this;
    hkQuaternion q0, q1;

    ((Ce0d30Obj*)self)->hkaPoseMatchingUtility_computeOrientation(a1, &q0);
    ((Ce0d30Obj*)self)->hkaPoseMatchingUtility_computeOrientation(a2, &q1);

    a4->setIdentity();
    int index = self->idx0;
    reinterpret_cast<__m128&>(a4->m_vTranslation) = ((hkQsTransform*)a2)[index].m_vTranslation.m_vComponents;
    a4->m_rotation.setMulInverse(&q1, &q0);

    hkVector4 rotated;
    rotated.SetRotatedDirection(*(hkVector4*)&reinterpret_cast<__m128&>(a4->m_rotation), *(hkVector4*)&((hkQsTransform*)a1)[index].m_vTranslation.m_vComponents);
    reinterpret_cast<__m128&>(a4->m_vTranslation) = _mm_sub_ps(reinterpret_cast<__m128&>(a4->m_vTranslation), rotated.value);

    a3->setIdentity();
    reinterpret_cast<__m128&>(a3->m_vTranslation) = reinterpret_cast<__m128&>(a4->m_vTranslation);
    reinterpret_cast<__m128&>(a3->m_rotation) = reinterpret_cast<__m128&>(a4->m_rotation);
    reinterpret_cast<__m128&>(a3->m_vScale) = reinterpret_cast<__m128&>(a4->m_vScale);

    {
        __declspec(align(16)) float angle;
        hkQuaternion axis;
        a3->m_rotation.hkQuaternion_decomposeRestAxis(&self->unk10, &axis, &angle);
        a3->m_rotation.hkQuaternion_setAxisAngle(&self->unk10, angle);
    }
}

extern const float DAT_0104da4c = 1.1920928955078125e-7f;

struct ByteResult
{
    char value;
    ByteResult(bool b) : value(b)
    {}
};

struct VectorTest
{
    __m128 m_data;

    ByteResult ProcessAndReturnValue_00ce1500() const;
};

// @fnv 0x00ce1500
// src: GUESS 0x00ce1500 (confidence: low)
ByteResult VectorTest::ProcessAndReturnValue_00ce1500() const
{
    __m128 v = m_data;
    float scale = DAT_0104da4c;
    __m128 a = _mm_mul_ps(v, v);
    __m128 b = _mm_shuffle_ps(a, a, 0x55);
    __m128 c = _mm_shuffle_ps(a, a, 0xaa);
    b = _mm_add_ss(b, a);
    c = _mm_add_ss(c, b);
    c = _mm_sqrt_ss(c);
    __m128 r = c;
    float f;
    _mm_store_ss(&f, r);
    return ByteResult(f > scale);
}

extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;

__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(QuaternionVector(quat).m_vComponents, QuaternionVector(quat).m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = QuaternionVector(quat).dot3(direction).m_vValue;
    ret.addMul4(imagDotDir, QuaternionVector(quat));
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(direction, QuaternionVector(quat));
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkQsTransform::SetConjugate(const hkQsTransform& t)
{
    m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
    m_vTranslation.m_vComponents = _mm_xor_ps(m_vTranslation.m_vComponents, DAT_010c44d0);
    m_rotation.SetConjugate(t.m_rotation);
    hkVector4 s;
    s.m_vComponents = _mm_shuffle_ps(
        t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
    m_vScale.setReciprocal4(s);
    m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
}

__forceinline void hkQsTransform::setMulContext(const hkQsTransform& t1, const hkQsTransform& t2)
{
    hkVector4 temp;
    temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
    m_vTranslation.setAdd4(temp, t1.m_vTranslation);
    m_rotation.SetProduct(t1.m_rotation, t2.m_rotation);
    m_vScale.m_vComponents = _mm_mul_ps(
        _mm_load_ps(&m_vScale.x), _mm_load_ps(&t1.m_vScale.x));
}

class RagdollMapperC18
{
  public:
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
    hkaSkeleton* m_pkSkeleton;
    void getWorldPose(hkQsTransform* pkPoseOut);
    void hkaRagdollInstance_getPoseModelSpace(hkQsTransform* pkPoseOut, const hkQsTransform& kWorldFromModel);
};
// @fnv 0x00ce18f0
// src: COMMUNITY 0x00ce18f0
void RagdollMapperC18::hkaRagdollInstance_getPoseModelSpace(hkQsTransform* pkPoseOut, const hkQsTransform& kWorldFromModel)
{
    getWorldPose(pkPoseOut);
    int iNumBones = m_pkSkeleton->m_kBones.m_iElementCount;
    hkQsTransform kModelFromWorld;
    kModelFromWorld.SetConjugate(kWorldFromModel);
    for (int i = 0; i < iNumBones; i++)
        pkPoseOut[i].setMulContext(kModelFromWorld, pkPoseOut[i]);
}

extern "C" void _ReadWriteBarrier();
// Near miss: two load-register encodings remain under accepted GS- flags and RTM.

extern const __m128 DAT_01017d10;
extern __m128 DAT_010c71e0;
extern __m128 DAT_010c4c00;

// @fnv 0x00ce0ff0
// src: GUESS 0x00ce0ff0 (confidence: low)
static __declspec(noinline) void hkQuaternion_ComputeValues_00ce0ff0(const hkVector4& dir, hkQuaternion& q)
{
    hkVector4 perp;
    perp.m_vComponents = _mm_setzero_ps();
    hkVector4 a;
    a.m_vComponents = _mm_and_ps(dir.m_vComponents, DAT_01017d10);
    const float* f = (const float*)&a;
    int major;
    if (f[0] < f[1])
        major = (f[1] < f[2]) ? 2 : 1;
    else
        major = (f[0] < f[2]) ? 2 : 0;
    ((float*)&perp)[(major + 1) % 3] = 1.0f;

    __m128 qv = QuaternionVector(q).m_vComponents;
    __m128 w = _mm_shuffle_ps(qv, qv, 0xff);
    __m128 d = dot3(qv, perp.m_vComponents);
    __m128 r0 = _mm_mul_ps(cross3(qv, perp.m_vComponents), w);
    __m128 t = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), perp.m_vComponents);
    t = _mm_add_ps(t, _mm_mul_ps(_mm_shuffle_ps(d, d, 0), qv));
    __m128 r = _mm_add_ps(r0, t);
    r = _mm_add_ps(r, r);

    __m128 dirQuad = dir.m_vComponents;
    __m128 c = cross3(r, dirQuad);

    const __m128 half = _mm_set_ss(0.5f);
    const __m128 three = _mm_set_ss(3.0f);
    const __m128 zero = _mm_set_ss(0.0f);

    const __m128 len2 = dot3(c, c);
    const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);

    const __m128 approx = _mm_rsqrt_ss(len2);
    const __m128 refined =
        _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
    __m128 s = _mm_andnot_ps(len2EqualsZero, refined);
    c = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), c);

    hkRotation m;
    m.m_kColumn0.m_vComponents = cross3(dirQuad, c);
    m.m_kColumn1.m_vComponents = dirQuad;
    m.m_kColumn2.m_vComponents = c;
    __declspec(align(16)) hkQuaternion rq;
    rq.FUN_00cb26e0(m);
    __declspec(align(16)) hkQuaternion inv;
    __m128 mask = DAT_010c4c00;
    _ReadWriteBarrier();
    __m128 value = QuaternionVector(rq).m_vComponents;
    _ReadWriteBarrier();
    QuaternionVector(inv).m_vComponents = _mm_xor_ps(value, mask);
    __declspec(align(16)) hkQuaternion res;
    res.setMul(inv, q);
    QuaternionVector(q).m_vComponents = QuaternionVector(res).m_vComponents;
}
// This ordinary array caller lets VC9 derive the internal register convention.
void AlignDirections(const hkVector4& dir, hkQuaternion* quaternions, int count)
{
    for (int i = 0; i < count; ++i)
        hkQuaternion_ComputeValues_00ce0ff0(dir, quaternions[i]);
}

#include <math.h>
extern float DAT_0104da48;

__forceinline hkSimdReal::operator float() const
{
    float scalar;
    _mm_store_ss(&scalar, m_vValue);
    return scalar;
}
__forceinline hkSimdReal hkVector4::dot4(const hkVector4& other) const
{
    __m128 product = _mm_mul_ps(m_vComponents, other.m_vComponents);
    __m128 pair = _mm_add_ps(_mm_shuffle_ps(product, product, 0x4e), product);
    __m128 swapped = _mm_shuffle_ps(pair, pair, 0xb1);
    return _mm_add_ps(pair, swapped);
}
__forceinline void hkVector4::cofactor(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9), _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2)),
                               _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2), _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9)));
}
__forceinline void hkVector4::normalize3()
{
    __m128 square = _mm_mul_ps(m_vComponents, m_vComponents);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(square, square, 0x55), square);
    __m128 length = _mm_add_ss(_mm_shuffle_ps(square, square, 0xaa), xy);
    __m128 estimate = _mm_rsqrt_ss(length);
    __m128 zero = _mm_cmpeq_ss(length, _mm_setzero_ps());
    __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(length, estimate), estimate));
    __m128 scale = _mm_andnot_ps(zero, _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction));
    m_vComponents = _mm_mul_ps(m_vComponents, _mm_shuffle_ps(scale, scale, 0));
}

static __declspec(noinline) void AlignPoseToAxis(const hkVector4& axis, hkQuaternion& value)
{
    hkVector4 side;
    side.m_vComponents = _mm_setzero_ps();
    hkVector4 magnitudes;
    magnitudes.m_vComponents = _mm_andnot_ps(_mm_set1_ps(-0.0f), axis.m_vComponents);
    int major = magnitudes.m_f[0] < magnitudes.m_f[1]
                    ? (magnitudes.m_f[1] < magnitudes.m_f[2] ? 2 : 1)
                    : (magnitudes.m_f[0] < magnitudes.m_f[2] ? 2 : 0);
    side.m_f[(major + 1) % 3] = 1.0f;
    __m128 rotation = QuaternionVector(value).m_vComponents;
    __m128 real = _mm_shuffle_ps(rotation, rotation, 0xff);
    __m128 factor = _mm_add_ps(_mm_set1_ps(-0.5f), _mm_mul_ps(real, real));
    __m128 product = _mm_mul_ps(rotation, side.m_vComponents);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
    __m128 result = _mm_add_ps(_mm_mul_ps(side.m_vComponents, factor), _mm_mul_ps(_mm_shuffle_ps(sum, sum, 0), rotation));
    hkVector4 perpendicular;
    perpendicular.cofactor(QuaternionVector(value), side);
    result = _mm_add_ps(result, _mm_mul_ps(real, perpendicular.m_vComponents));
    side.m_vComponents = _mm_add_ps(result, result);
    hkVector4 up;
    up.cofactor(side, axis);
    up.normalize3();
    side.cofactor(axis, up);
    hkRotation basis;
    basis.m_kColumn0 = side;
    basis.m_kColumn1 = axis;
    basis.m_kColumn2 = up;
    __declspec(align(16)) hkQuaternion frame;
    frame.FUN_00cb26e0(basis);
    __declspec(align(16)) hkQuaternion inverse;
    QuaternionVector(inverse).m_vComponents = _mm_xor_ps(QuaternionVector(frame).m_vComponents, _mm_set_ps(0.0f, -0.0f, -0.0f, -0.0f));
    __declspec(align(16)) hkQuaternion composed;
    composed.setMul(inverse, value);
    value = composed;
}

struct CandidatePose
{
    __declspec(align(16)) hkQuaternion reference;
    const void* binding;
    float time;
};
struct PoseMatcher
{
    hkArray<CandidatePose> candidates;
    hkVector4 axis;
    short rootBone, otherBone, thirdBone;
    void hkaPoseMatchingUtility_computeOrientation(const hkQsTransform* pose, hkQuaternion& out) const;
    int hkaPoseMatchingUtility_findBestCandidatePoseIndex(const hkQsTransform* pose, float& error) const;
};

inline float magnitude(float value)
{
    return fabsf(value);
}

// @fnv 0x00ce11f0
// src: COMMUNITY 0x00ce11f0
int PoseMatcher::hkaPoseMatchingUtility_findBestCandidatePoseIndex(const hkQsTransform* pose, float& error) const
{
    __declspec(align(16)) hkQuaternion orientation;
    hkaPoseMatchingUtility_computeOrientation(pose, orientation);
    AlignPoseToAxis(axis, orientation);
    int selected = -1;
    error = DAT_0104da48;
    for (int index = 0; index < candidates.m_iElementCount; ++index)
    {
        float distance = 1.0f - magnitude(QuaternionVector(orientation).dot4(QuaternionVector(candidates.m_data[index].reference)));
        if (distance < error)
        {
            selected = index;
            error = distance;
        }
    }
    return selected;
}

extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;
extern __m128 DAT_010c71b0;

class Ragdoll4
{
  public:
    int unk00;
    int unk04;
    hkpRigidBody** m_ppBodies;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int* m_piBoneToBody;
    int unk24;
    int unk28;
    hkaSkeleton* m_pkSkeleton;

    void hkaRagdollInstance_getPoseWorldSpace(hkQsTransform* pkPoseOut, const hkQsTransform& kRoot, const hkQsTransform* pkLocalPose);
};

// @fnv 0x00ce1760
// src: COMMUNITY 0x00ce1760
void Ragdoll4::hkaRagdollInstance_getPoseWorldSpace(hkQsTransform* pkPoseOut, const hkQsTransform& kRoot,
                            const hkQsTransform* pkLocalPose)
{
    if (!pkLocalPose)
        pkLocalPose = m_pkSkeleton->m_kReferencePose.m_data;

    for (int i = 0; i < m_pkSkeleton->m_kBones.m_iElementCount; i++)
    {
        int iBody = m_piBoneToBody[i];
        if (iBody >= 0)
        {
            hkpRigidBody* pkBody = m_ppBodies[iBody];
            if (pkBody)
            {
                pkPoseOut[i].setFromTransformNoScale(pkBody->m_pMotionState.m_kMotionState.m_kMotionTransform);
                MultiplyBoneScales(m_pkSkeleton, m_pkSkeleton->m_kReferencePose.m_data, i, pkPoseOut[i].m_vScale);
                continue;
            }
        }

        int iParent = m_pkSkeleton->m_kParentIndices.m_data[i];
        hkQsTransform kParent;
        (iParent >= 0) ? (kParent = pkPoseOut[iParent]) : (kParent = kRoot);
        ComposeReferenceTransform(pkPoseOut[i], kParent, pkLocalPose[i]);
    }
}

#include <xmmintrin.h>
__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(QuaternionVector(quat).m_vComponents, QuaternionVector(quat).m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = QuaternionVector(quat).dot3(direction).m_vValue;
    ret.addMul4(imagDotDir, QuaternionVector(quat));
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(QuaternionVector(quat), direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}
__forceinline void hkQsTransform::SetProduct(const hkQsTransform& t1, const hkQsTransform& t2)
{
    hkVector4 extraTrans;
    extraTrans.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
    m_vTranslation.setAdd4(extraTrans, t1.m_vTranslation);
    m_rotation.setMul(t1.m_rotation, t2.m_rotation);
    m_vScale.m_vComponents = _mm_mul_ps(_mm_load_ps(&t1.m_vScale.x), t2.m_vScale.m_vComponents);
}

namespace fnv_00ce1ad0 {
#include <xmmintrin.h>

extern __declspec(align(16)) float DAT_01267e30;
extern __declspec(align(16)) const float DAT_010c71e0;
extern __declspec(align(16)) const float DAT_01017d10;

// The approved hkpRigidBody has no FUN_00ca8860 declaration.
struct UnkCall
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    hkpMotion m_pMotionState;

    void activate_00c9c1d0();
    void hkpRigidBody_setPositionAndRotation(const hkVector4* pos, const hkQuaternion* rot);

    void SetTranslationalVelocity(const float* v)
    {
        activate_00c9c1d0();
        m_pMotionState.SetTranslationalVelocity(*reinterpret_cast<const hkVector4*>(v));
    }
    void SetRotationalVelocity(const float* v)
    {
        activate_00c9c1d0();
        m_pMotionState.SetRotationalVelocity(*reinterpret_cast<const hkVector4*>(v));
    }
};

struct RagInstance
{
    int unk00;
    int unk04;
    UnkCall** m_ppRigidBodies;
    int m_iRigidBodyCount;
    int m_rigidBodiesCap;
    void** m_ppConstraints;
    int m_iConstraintCount;
    int m_constraintsCap;
    int* m_kBoneMap;
    int m_numMap;
    int m_mapCap;
    hkaSkeleton* m_pSkeleton;

    UnkCall* getRigidBodyOfBone(int b) const
    {
        int rbIdx = m_kBoneMap[b];
        if (rbIdx < 0)
            return 0;
        return m_ppRigidBodies[rbIdx];
    }

    void hkaRagdollInstance_setPoseWorldSpace(const hkQsTransform* pose, const hkQsTransform& worldFromModel);
};

static __forceinline bool equals4(const __m128& a, const float* v)
{
    __m128 t =
        _mm_and_ps(_mm_sub_ps(reinterpret_cast<const __m128&>(*v), a), reinterpret_cast<const __m128&>(DAT_01017d10));
    __m128 eps = _mm_set1_ps(1e-3f);
    return (_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 0xf) == 0xf;
}

// @fnv 0x00ce1ad0
// src: COMMUNITY 0x00ce1ad0
void RagInstance::hkaRagdollInstance_setPoseWorldSpace(const hkQsTransform* pose, const hkQsTransform& worldFromModel)
{
    int numBones = m_pSkeleton->m_kBones.m_iElementCount;
    for (int b = 0; b < numBones; b++, pose++)
    {
        UnkCall* rb = getRigidBodyOfBone(b);
        if (rb)
        {
            hkQsTransform rbWorld;
            rbWorld.SetProduct(worldFromModel, *pose);
            rbWorld.m_rotation.normalize_005611c0();
            rb->hkpRigidBody_setPositionAndRotation(&rbWorld.m_vTranslation, &rbWorld.m_rotation);

            const float* zero = &DAT_01267e30;
            if (!equals4(rb->m_pMotionState.m_kTranslationalVelocity.m_vComponents, zero))
                rb->SetTranslationalVelocity(zero);
            if (!equals4(rb->m_pMotionState.m_kAngularVelocity.m_vComponents, zero))
                rb->SetRotationalVelocity(zero);
        }
    }
}
}  // namespace fnv_00ce1ad0
