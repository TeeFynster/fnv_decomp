#include "../../../../../include/hkArray.h"
// src/havok/animation/ragdoll/instance/hkaragdollinstance_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/animation/ragdoll/instance/hkaragdollinstance_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/animation/ragdoll/instance/hkaragdollinstance_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/animation/ragdoll/instance/hkaragdollinstance.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/ragdoll/instance/hkaragdollinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/instance/hkaragdollinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkArray.h"
#include "../../../../../include/MemoryManager.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkaBone.h"
#include "../../../../../include/hkaSkeleton.h"
#include "../../../../../include/hkpMotion.h"
#include "../../../../../include/hkpRigidBody.h"
#include "../../../../../include/hkaRagdollInstance.h"
extern int DAT_01268700;
void __stdcall hkaRagdollInstance_getPoseWorldSpace(int, int, int);
void __stdcall hkaRagdollInstance_getPoseWorldSpace_00ce18d0(int a);
struct FUN_00ce2430_Transform
{
    unsigned char pad[0x30];
};
struct FUN_00ce2430_Data
{
    unsigned char pad[0x1c];
    int count;
};
struct FUN_00ce2430_Class
{
    unsigned char pad[0x2c];
    FUN_00ce2430_Data* data;

    void hkaRagdollInstance_getApproxWorldFromBoneTransformAt(int, float, void*);
    void ApplyValueToTransforms(float, FUN_00ce2430_Transform*);
};
struct FUN_00ce29b0_standin
{
    void FUN_00ce2600();
    void* Destroy(unsigned char deletingFlag);
};
hkMemoryRouter* _D1A0E0GetMemoryRouter();
extern int DAT_010cfd84;
struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* SetVptr(unsigned int unusedArg);
};
struct ReferenceObject : hkReferencedObject
{
    void FUN_00c90510();
    void FUN_00c905b0();
};
struct ArrayAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void* allocateBuffer(int& bytes);
    virtual void freeBuffer(void* buffer, int bytes);
};
struct ArrayRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    ArrayAllocator* m_pStreamAllocator;
};
ArrayRouter* __cdecl hkMemoryRouter_getInstance();
template <class T> struct ObjectArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void assign(const ObjectArray& source)
    {
        ArrayAllocator* heap = hkMemoryRouter_getInstance()->m_pStreamAllocator;
        int capacity = m_iCapacityState & 0x3fffffff;
        if (capacity < source.m_iElementCount)
        {
            if (!(m_iCapacityState & 0x80000000))
                heap->freeBuffer(m_data, capacity * (int)sizeof(T));
            int bytes = source.m_iElementCount * (int)sizeof(T);
            m_data = (T*)heap->allocateBuffer(bytes);
            m_iCapacityState = bytes / (int)sizeof(T);
        }
        m_iElementCount = source.m_iElementCount;
        int count = m_iElementCount;
        T* destination = m_data;
        const T* input = source.m_data;
        for (int i = 0; i < count; ++i)
            destination[i] = input[i];
    }
};
struct RagdollInstance : hkReferencedObject
{
    ObjectArray<ReferenceObject*> m_ppRigidBodies;
    ObjectArray<ReferenceObject*> m_ppConstraints;
    ObjectArray<int> m_kBoneMap;
    ReferenceObject* m_pSkeleton;
    void hkaRagdollInstance_commonInit(const ObjectArray<ReferenceObject*>& bodies, const ObjectArray<ReferenceObject*>& constraints,
                      ReferenceObject* skeleton);
};
struct FUN_00ce26f0_ObjectC
{
    float hkpWorld_getCurrentTime();
};
struct FUN_00ce26f0_ObjectB
{
    void* unk00;
    void* unk04;
    FUN_00ce26f0_ObjectC* unk08;
};
struct FUN_00ce26f0_ObjectA
{
    FUN_00ce26f0_ObjectB* unk00;
};
struct FUN_00ce26f0_Class
{
    int unk00;
    int unk04;
    FUN_00ce26f0_ObjectA* unk08;

    void hkaRagdollInstance_getPoseWorldSpace_00ce18d0(FUN_00ce2430_Transform* a);
    void ApplyValueToTransforms(float a, FUN_00ce2430_Transform* b);
    void hkaRagdollInstance_getApproxCurrentPoseWorldSpace(FUN_00ce2430_Transform* a);
};
typedef unsigned int hk_size_tR;
class hkMemoryAllocatorR
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void v08();
    virtual void v0C();
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};
struct hkMemoryRouterR
{
    void* m_aiEntries;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorR* m_pStreamAllocator;
    hkMemoryAllocatorR& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterR& __cdecl GetMemoryRouterR() throw();
void __cdecl hkArrayUtil_reserveR(hkMemoryAllocatorR& kAlloc, void* pkArray, int iNumElements, int iSizeElem) throw();

template <typename T> __forceinline T* hkAllocateStackR(int n)
{
    hkMemoryRouterR& kRouter = GetMemoryRouterR();
    char* pcCur = (char*)kRouter.m_aiEntries;
    kRouter.m_aiEntries = pcCur + ((n * sizeof(T) + 0x7f) & ~0x7f);
    return (T*)pcCur;
}
template <typename T> __forceinline void hkDeallocateStackR(T* p)
{
    GetMemoryRouterR().m_aiEntries = p;
}
template <typename T> struct hkLocalArrayR : public hkArray<T>
{
    __forceinline hkLocalArrayR(int n) throw()
    {
        T* pLocal = hkAllocateStackR<T>(n);
        this->m_data = pLocal;
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = pLocal;
    }
    __forceinline ~hkLocalArrayR() throw()
    {
        if (m_pStackAllocation == this->m_data)
            this->m_iElementCount = 0;
        hkDeallocateStackR(m_pStackAllocation);
    }
    T* m_pStackAllocation;
};
class hkReferencedObjectR
{
  public:
    virtual ~hkReferencedObjectR() throw();
    void removeReference() const throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpConstraintInstanceR : public hkReferencedObjectR
{
  public:
    hkpConstraintInstanceR* clone(hkpRigidBody* pkEntityA, hkpRigidBody* pkEntityB, int eCloneMode) const throw();
};

#include "../../../../../include/hkaRagdollInstance.h"

#include <xmmintrin.h>
struct FUN_00ce14b0_standin
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
    __m128 unk10;
    unsigned short unk20;
    unsigned short unk22;
    unsigned short unk24;

    void UpdateState_00ce14b0(unsigned short a, unsigned short b, unsigned short c, const void* data);
};
struct FUN_00ce1680_Body
{
    void* unk00;
    void* unk04;
    void* unk08;
};
struct FUN_00c94bd0_Obj
{
    void hkpWorld_addEntityBatch(void* objects, int count, int flag);
};
struct FUN_00c97d30_Obj
{
    void hkpWorld_addConstraint(void* object);
};
struct CallRet
{
    void hkpWorld_updateCollisionFilterOnEntity(void* object, int a, int b);
};
class FUN_00ce1680_Ragdoll : public hkReferencedObject
{
  public:
    hkArray<void*> m_ppRigidBodies;
    hkArray<void*> m_ppConstraints;
    hkArray<hkInt32> m_kBoneMap;
    hkaSkeleton* m_pSkeleton;

    int addToWorld(void* world, unsigned char flag);
};
extern int DAT_010cb830;
struct RagdollInstance_ce24
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    hkArray<ReferenceObject*> m_ppRigidBodies;
    hkArray<ReferenceObject*> m_ppConstraints;
    hkArray<int> m_kBoneMap;
    hkaSkeleton* m_pSkeleton;
    void hkaRagdollInstance_commonInit(const hkArray<ReferenceObject*>& bodies, const hkArray<ReferenceObject*>& constraints,
                      hkaSkeleton* skeleton);
    RagdollInstance_ce24* hkaRagdollInstance_hkaRagdollInstance(const hkArray<ReferenceObject*>& bodies,
                                       const hkArray<ReferenceObject*>& constraints, hkaSkeleton* skeleton);
};
extern "C"
{
    extern __m128 DAT_010c71e0;
    extern __m128 DAT_010c7170;
    extern __m128 DAT_010c44d0;
    extern __m128 DAT_010c4c00;
    extern __m128 DAT_010c4c10;
}
void __cdecl Runtime_ProcessEntries_00ce2d10(unsigned int p0, void* p1, unsigned int p2, int p3, unsigned int p4);
struct Vec4x3
{
    __m128 r0;
    __m128 r1;
    __m128 r2;
};
void __cdecl hkaSkeletonMapper_additivePoseFromCombinedPoseAndReferencePose(unsigned int arg0, unsigned int arg1, unsigned int arg2, int count, unsigned int arg4);
extern float DAT_01267e30;
extern float DAT_01017d00;
extern float DAT_01017d10;
struct PoseW
{
    const hkQsTransform* p;
    PoseW(const hkQsTransform* q) : p(q)
    {}
};
struct RagdollHelper : public hkaRagdollInstance
{
    void ApplyPoseAndClearVelocities(PoseW pose);
};
template <class T> struct InitArray : ObjectArray<T>
{
    InitArray()
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
    }
};
extern "C" int DAT_010cb830;
struct FUN_00ce2510
{
    void* m_vptr;
    short m_iWordAt04;
    short m_6;
    InitArray<void*> m_ppRigidBodies;
    InitArray<void*> m_ppConstraints;
    InitArray<int> m_kBoneMap;
    int m_2c;

    void hkaRagdollInstance_commonInit(int a, int b, int c);
    FUN_00ce2510(int a, int b, int c, ObjectArray<int>* d);
};

namespace PoseVelocityDetails {

static const float DAT_01017d00 = 0.001f;

struct __declspec(align(16)) PoseVelocity_QuadFloats
{
    float x, y, z, w;
};
struct __declspec(align(16)) PoseVelocity_QuadBits
{
    unsigned x, y, z, w;
};
static const PoseVelocity_QuadFloats PoseVelocity_halfBias = {-0.5f, -0.5f, -0.5f, -0.5f};
static const PoseVelocity_QuadBits DAT_01017d10 = {0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff};

struct PoseVelocity_ScalarLane
{
    PoseVelocity_ScalarLane()
    {}
    PoseVelocity_ScalarLane(float x)
    {
        value = _mm_load_ss(&x);
    }
    __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }

    PoseVelocity_ScalarLane(const __m128& q) : value(q)
    {}
    operator float() const
    {
        float result;
        _mm_store_ss(&result, value);
        return result;
    }
    const __m128& getQuad() const
    {
        return value;
    }
    __m128 value;
};

class PoseVelocity_QuadValue
{
    __m128 lanes;

  public:
    __forceinline operator __m128() const
    {
        return lanes;
    }
    __forceinline void operator=(const __m128& value)
    {
        lanes = value;
    }
};
struct PoseVelocity_MyVector4
{
    PoseVelocity_QuadValue quad;

    PoseVelocity_MyVector4()
    {}
    void operator=(const __m128& q)
    {
        quad = q;
    }
    __forceinline PoseVelocity_ScalarLane dot4(const PoseVelocity_MyVector4& other) const
    {
        __m128 product = _mm_mul_ps(quad, other.quad);
        __m128 pairs = _mm_add_ps(_mm_shuffle_ps(product, product, 78), product);
        __m128 opposite = _mm_shuffle_ps(pairs, pairs, 177);
        return _mm_add_ps(pairs, opposite);
    }
    __forceinline PoseVelocity_ScalarLane length3() const
    {
        return _mm_sqrt_ss(dot3(*this).getQuad());
    }
    __forceinline void normalize(int dimensions)
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 square = dimensions == 3 ? dot3(*this).getQuad() : dot4(*this).getQuad();
        const __m128 isZero = _mm_cmpeq_ss(square, zero);
        const __m128 estimate = _mm_rsqrt_ss(square);
        const __m128 refined = _mm_mul_ss(_mm_mul_ss(half, estimate),
                                          _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(square, estimate), estimate)));
        PoseVelocity_ScalarLane reciprocal(_mm_andnot_ps(isZero, refined));
        quad = _mm_mul_ps(reciprocal.splat(), quad);
    }
    __forceinline void combine(const PoseVelocity_MyVector4& xyz, const PoseVelocity_MyVector4& real)
    {
        quad = _mm_shuffle_ps(xyz.quad, _mm_unpackhi_ps(xyz.quad, real.quad), 196);
    }
    __forceinline void setAdd4(const PoseVelocity_MyVector4& a, const PoseVelocity_MyVector4& b)
    {
        quad = _mm_add_ps(a.quad, b.quad);
    }
    __forceinline void setSub4(const PoseVelocity_MyVector4& a, const PoseVelocity_MyVector4& b)
    {
        quad = _mm_sub_ps(a.quad, b.quad);
    }
    __forceinline void setMul4(const PoseVelocity_MyVector4& a, const PoseVelocity_MyVector4& b)
    {
        quad = _mm_mul_ps(a.quad, b.quad);
    }
    __forceinline void mul4(const PoseVelocity_ScalarLane& s)
    {
        quad = _mm_mul_ps(s.splat(), quad);
    }
    __forceinline void setZero4()
    {
        quad = _mm_setzero_ps();
    }
    __forceinline void broadcastFrom(const PoseVelocity_MyVector4& source, int lane)
    {
        if (lane == 3)
            quad = _mm_shuffle_ps(source.quad, source.quad, 255);
        else
            quad = _mm_shuffle_ps(source.quad, source.quad, 0);
    }
    __forceinline void broadcastLow()
    {
        quad = _mm_shuffle_ps(quad, quad, 0);
    }
    __forceinline void addProduct(const PoseVelocity_MyVector4& a, const PoseVelocity_MyVector4& b)
    {
        quad = _mm_add_ps(quad, _mm_mul_ps(a.quad, b.quad));
    }
    __forceinline void addProduct(const PoseVelocity_ScalarLane& a, const PoseVelocity_MyVector4& b)
    {
        quad = _mm_add_ps(quad, _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0), b.quad));
    }
    __forceinline void sumProduct(const PoseVelocity_MyVector4& a, const PoseVelocity_MyVector4& b,
                                  const PoseVelocity_MyVector4& c)
    {
        quad = _mm_add_ps(a.quad, _mm_mul_ps(b.quad, c.quad));
    }
    __forceinline PoseVelocity_ScalarLane dot3(const PoseVelocity_MyVector4& other) const
    {
        __m128 products = _mm_mul_ps(quad, other.quad);
        __m128 firstPair = _mm_add_ss(_mm_shuffle_ps(products, products, 85), products);
        return _mm_add_ss(_mm_shuffle_ps(products, products, 170), firstPair);
    }
    __forceinline void crossOf(const PoseVelocity_MyVector4& a, const PoseVelocity_MyVector4& b)
    {
        __m128 firstProduct = _mm_mul_ps(_mm_shuffle_ps(a.quad, a.quad, 201), _mm_shuffle_ps(b.quad, b.quad, 210));
        __m128 secondProduct = _mm_mul_ps(_mm_shuffle_ps(a.quad, a.quad, 210), _mm_shuffle_ps(b.quad, b.quad, 201));
        quad = _mm_sub_ps(firstProduct, secondProduct);
    }
    __forceinline void SetRotatedDirection(const PoseVelocity_MyVector4& q, const PoseVelocity_MyVector4& v)
    {
        PoseVelocity_MyVector4 bias;
        bias.quad = *reinterpret_cast<const __m128*>(&PoseVelocity_halfBias);
        PoseVelocity_MyVector4 realPart;
        realPart.broadcastFrom(q, 3);
        PoseVelocity_MyVector4 realFactor;
        realFactor.sumProduct(bias, realPart, realPart);
        PoseVelocity_MyVector4 accum;
        accum.setMul4(v, realFactor);
        PoseVelocity_MyVector4 projection;
        projection.quad = q.dot3(v).value;
        projection.broadcastLow();
        accum.addProduct(projection, q);
        PoseVelocity_MyVector4 cross;
        cross.crossOf(q, v);
        accum.addProduct(realPart, cross);
        setAdd4(accum, accum);
    }
    __forceinline bool equals4(const PoseVelocity_MyVector4& other, float epsilon) const
    {
        PoseVelocity_MyVector4 difference;
        difference.setSub4(*this, other);
        difference.quad = _mm_and_ps(difference.quad, *reinterpret_cast<const __m128*>(&DAT_01017d10));
        PoseVelocity_MyVector4 eps;
        eps.quad = _mm_set_ps1(epsilon);
        __m128 comparison = _mm_cmple_ps(difference.quad, eps.quad);
        return (_mm_movemask_ps(comparison) & 15) == 15;
    }
};

struct PoseVelocity_MyQuaternion
{
    PoseVelocity_MyVector4 m_vec;
    inline void __thiscall setMul(const PoseVelocity_MyQuaternion& a, const PoseVelocity_MyQuaternion& b);
    inline void __thiscall normalize_005611c0();
    inline void __thiscall setMulInverse(const PoseVelocity_MyQuaternion& a, const PoseVelocity_MyQuaternion& b);
    inline void __thiscall hkQuaternion_getAxis(PoseVelocity_MyVector4& axis);
    inline float __thiscall GetAngle();

    __forceinline bool hasValidAxis() const
    {
        return float(m_vec.length3()) > 1.192092896e-7f;
    }
};

// src: COMMUNITY 0x005611c0
inline void PoseVelocity_MyQuaternion::normalize_005611c0()
{
    m_vec.normalize(4);
}
// src: COMMUNITY 0x00c66320
inline void PoseVelocity_MyQuaternion::setMul(const PoseVelocity_MyQuaternion& first,
                                                    const PoseVelocity_MyQuaternion& second)
{
    PoseVelocity_MyVector4 imaginary;
    imaginary.crossOf(first.m_vec, second.m_vec);
    PoseVelocity_ScalarLane firstReal(_mm_shuffle_ps(first.m_vec.quad, first.m_vec.quad, 255));
    imaginary.addProduct(firstReal, second.m_vec);
    PoseVelocity_ScalarLane secondReal(_mm_shuffle_ps(second.m_vec.quad, second.m_vec.quad, 255));
    imaginary.addProduct(secondReal, first.m_vec);
    PoseVelocity_MyVector4 dot;
    dot.quad = first.m_vec.dot3(second.m_vec).splat();
    PoseVelocity_MyVector4 real;
    real.setMul4(first.m_vec, second.m_vec);
    real.quad = _mm_sub_ps(real.quad, dot.quad);
    m_vec.combine(imaginary, real);
}
// src: COMMUNITY 0x00c74ac0
inline void PoseVelocity_MyQuaternion::setMulInverse(const PoseVelocity_MyQuaternion& first,
                                                    const PoseVelocity_MyQuaternion& second)
{
    PoseVelocity_MyVector4 imaginary;
    imaginary.crossOf(second.m_vec, first.m_vec);
    PoseVelocity_ScalarLane firstReal(_mm_shuffle_ps(first.m_vec.quad, first.m_vec.quad, 255));
    imaginary.quad = _mm_sub_ps(imaginary.quad, _mm_mul_ps(firstReal.splat(), second.m_vec.quad));
    PoseVelocity_ScalarLane secondReal(_mm_shuffle_ps(second.m_vec.quad, second.m_vec.quad, 255));
    imaginary.addProduct(secondReal, first.m_vec);
    PoseVelocity_MyVector4 real;
    real.quad = first.m_vec.dot4(second.m_vec).splat();
    m_vec.combine(imaginary, real);
}
// src: COMMUNITY 0x00c74c90
inline void PoseVelocity_MyQuaternion::hkQuaternion_getAxis(PoseVelocity_MyVector4& output)
{
    PoseVelocity_MyVector4 axis;
    axis = m_vec;
    axis.normalize(3);
    if (_mm_movemask_ps(_mm_cmplt_ps(m_vec.quad, _mm_setzero_ps())) & 8)
    {
        static const PoseVelocity_QuadBits sign = {0x80000000, 0x80000000, 0x80000000, 0x80000000};
        axis.quad = _mm_xor_ps(axis.quad, *reinterpret_cast<const __m128*>(&sign));
    }
    output = axis;
}
extern "C" double __cdecl acos(double);
extern "C" double __cdecl fabs(double);
inline float PoseVelocity_safeAcos(float input)
{
    if ((float)fabs(input) >= 1.0f)
        return input > 0.0f ? 0.0f : 3.14159265358979f;
    return (float)acos(input);
}
inline float PoseVelocity_MyQuaternion::GetAngle()
{
    float value = (float)fabs(reinterpret_cast<const float*>(&m_vec)[3]);
    value = PoseVelocity_safeAcos(value);
    value *= 2.0f;
    return value;
}

// local form of hkQsTransform: 0x00ce1ca0 needs inline SetProduct and quaternion normalization; shared out-of-line product does not reproduce exe bytes.
struct PoseVelocity_MyQsTransform
{
    PoseVelocity_MyVector4 m_vTranslation;
    PoseVelocity_MyQuaternion m_rotation;
    PoseVelocity_MyVector4 m_vScale;

    __forceinline void SetProduct(const PoseVelocity_MyQsTransform& a, const PoseVelocity_MyQsTransform& b)
    {
        PoseVelocity_MyVector4 translated;
        translated.SetRotatedDirection(a.m_rotation.m_vec, b.m_vTranslation);
        m_vTranslation.setAdd4(a.m_vTranslation, translated);
        m_rotation.setMul(a.m_rotation, b.m_rotation);
        m_vScale.setMul4(a.m_vScale, b.m_vScale);
    }
};

struct PoseVelocity_RagdollPoseUpdater : public hkaRagdollInstance
{
    void ProcessEntries_00ce1ca0(const PoseVelocity_MyQsTransform* poseA, const PoseVelocity_MyQsTransform& worldFromModelA,
                      const PoseVelocity_MyQsTransform* poseB, const PoseVelocity_MyQsTransform& worldFromModelB,
                      float deltaTime);
};

// @fnv 0x00ce1ca0
// src: GUESS 0x00ce1ca0 (confidence: low)
void PoseVelocity_RagdollPoseUpdater::ProcessEntries_00ce1ca0(const PoseVelocity_MyQsTransform* poseA,
                                                   const PoseVelocity_MyQsTransform& worldFromModelA,
                                                   const PoseVelocity_MyQsTransform* poseB,
                                                   const PoseVelocity_MyQsTransform& worldFromModelB, float deltaTime)
{
    float inverseDeltaTime;
    long boneCount = m_pSkeleton->m_kBones.m_iElementCount;
    inverseDeltaTime = 1.0f / deltaTime;
    for (int i = 0; i < boneCount; ++i)
    {
        int bodyIndex = m_kBoneMap.m_data[i];
        if (bodyIndex >= 0)
        {
            hkpRigidBody* body;
            body = (hkpRigidBody*)m_ppRigidBodies.m_data[bodyIndex];
            if ((bool)body)
            {
                PoseVelocity_MyQsTransform worldPoseA;
                worldPoseA.SetProduct(worldFromModelA, poseA[i]);
                worldPoseA.m_rotation.normalize_005611c0();

                PoseVelocity_MyQsTransform worldPoseB;
                worldPoseB.SetProduct(worldFromModelB, poseB[i]);
                worldPoseB.m_rotation.normalize_005611c0();

                body->SetPositionAndRotation(reinterpret_cast<const NiPoint3&>(worldPoseB.m_vTranslation),
                                             reinterpret_cast<const NiQuaternion&>(worldPoseB.m_rotation));

                PoseVelocity_MyVector4 linearVelocity;
                linearVelocity.setSub4(worldPoseB.m_vTranslation, worldPoseA.m_vTranslation);
                linearVelocity.mul4(inverseDeltaTime);
                if (!linearVelocity.equals4(
                        reinterpret_cast<const PoseVelocity_MyVector4&>(body->m_pMotionState.m_kTranslationalVelocity),
                        DAT_01017d00))
                {
                    body->activate_00c9c1d0();
                    body->m_pMotionState.SetTranslationalVelocity(reinterpret_cast<const hkVector4&>(linearVelocity));
                }

                PoseVelocity_MyQuaternion relativeRotation;
                relativeRotation.setMulInverse(worldPoseB.m_rotation, worldPoseA.m_rotation);
                relativeRotation.normalize_005611c0();

                PoseVelocity_MyVector4 angularVelocity;
                if (!relativeRotation.hasValidAxis())
                {
                    angularVelocity.setZero4();
                }
                else
                {
                    float angle = relativeRotation.GetAngle();
                    relativeRotation.hkQuaternion_getAxis(angularVelocity);
                    angularVelocity.mul4(angle * inverseDeltaTime);
                }

                if (!angularVelocity.equals4(
                        reinterpret_cast<const PoseVelocity_MyVector4&>(body->m_pMotionState.m_kAngularVelocity),
                        DAT_01017d00))
                {
                    body->activate_00c9c1d0();
                    body->m_pMotionState.SetRotationalVelocity(reinterpret_cast<const hkVector4&>(angularVelocity));
                }
            }
        }
    }
}

}
