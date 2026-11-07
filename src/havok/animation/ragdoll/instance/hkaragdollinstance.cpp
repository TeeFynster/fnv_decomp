
// src/havok/animation/ragdoll/instance/hkaragdollinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/instance/hkaragdollinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkArray.h"
#include "../../../../../include/MemoryManager.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkaBone.h"
#include "../../../../../include/hkaSkeleton.h"
#include "../../../../../include/hkpMotion.h"
#include "../../../../../include/hkpRigidBody.h"
#include "../../../../../include/hkaRagdollInstance.h"
#include "../../../../../include/hkQsTransform.h"

extern int DAT_01268700;
void __stdcall hkaRagdollInstance_getPoseWorldSpace(int, int, int);
// @fnv 0x00ce18d0
// src: COMMUNITY 0x00ce18d0
void __stdcall hkaRagdollInstance_getPoseWorldSpace_00ce18d0(int a)
{
    hkaRagdollInstance_getPoseWorldSpace(a, (int)&DAT_01268700, 0);
}

struct FUN_00ce2430_Transform
{
    unsigned char pad[0x30];
};


struct FUN_00ce2430_Class
{
    unsigned char pad[0x2c];
    hkaSkeleton* data;

    void hkaRagdollInstance_getApproxWorldFromBoneTransformAt(int, float, void*);
    void ApplyValueToTransforms(float, FUN_00ce2430_Transform*);
};

// Iterates over data->m_kBones.m_iElementCount entries, calling FUN_00ce2150 with each index, value and successive transform.
// @fnv 0x00ce2430
void FUN_00ce2430_Class::ApplyValueToTransforms(float value, FUN_00ce2430_Transform* transforms)
{
    int count = this->data->m_kBones.m_iElementCount;

    for (int i = 0; i < count; ++i)
    {
        this->hkaRagdollInstance_getApproxWorldFromBoneTransformAt(i, value, transforms);
        ++transforms;
    }
}




struct FUN_00ce29b0_standin
{
    void FUN_00ce2600();
    void* Destroy(unsigned char deletingFlag);
};

hkMemoryRouter* _D1A0E0GetMemoryRouter();

// @fnv 0x00ce29b0
void* FUN_00ce29b0_standin::Destroy(unsigned char deletingFlag)
{
    FUN_00ce2600();

    if (deletingFlag & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        ((hkMemoryAllocator*)router->m_heap)->blockFree(this, *(unsigned short*)((unsigned char*)this + 4));
    }

    return this;
}

extern int DAT_010cfd84;

struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* SetVptr(unsigned int unusedArg);
};

// @fnv 0x00ce25f0
// src: GUESS 0x00ce25f0 (confidence: low)
FnvVtObj* FnvVtObj::SetVptr(unsigned int unusedArg)
{
    m_vptr = (int)&DAT_010cfd84;
    return this;
}

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
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
template <class T> struct ObjectArrayLocalForm
{ // local form of hkArray: 0x00ce22c0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void assign(const ObjectArrayLocalForm& source)
    {
        ArrayAllocator* heap = (ArrayAllocator*)hkMemoryRouter_getInstance()->m_heap;
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
    ObjectArrayLocalForm<ReferenceObject*> m_ppRigidBodies;
    ObjectArrayLocalForm<ReferenceObject*> m_ppConstraints;
    ObjectArrayLocalForm<int> m_kBoneMap;
    ReferenceObject* m_pSkeleton;
    void hkaRagdollInstance_commonInit(const ObjectArrayLocalForm<ReferenceObject*>& bodies, const ObjectArrayLocalForm<ReferenceObject*>& constraints,
                      ReferenceObject* skeleton);
};
// @fnv 0x00ce22c0
// src: HAVOK_LIB 0x00ce22c0
void RagdollInstance::hkaRagdollInstance_commonInit(const ObjectArrayLocalForm<ReferenceObject*>& bodies,
                                   const ObjectArrayLocalForm<ReferenceObject*>& constraints, ReferenceObject* skeleton)
{
    if (skeleton)
        skeleton->FUN_00c90510();
    if (m_pSkeleton)
        m_pSkeleton->FUN_00c905b0();
    m_pSkeleton = skeleton;
    m_ppRigidBodies.assign(bodies);
    m_ppConstraints.assign(constraints);
    for (int i = 0; i < m_ppRigidBodies.m_iElementCount; ++i)
        if (m_ppRigidBodies[i])
            m_ppRigidBodies[i]->FUN_00c90510();
    for (int i = 0; i < m_ppConstraints.m_iElementCount; ++i)
        if (m_ppConstraints[i])
            m_ppConstraints[i]->FUN_00c90510();
}

namespace fnv_00ce2600 {
extern int DAT_010cb830;
extern int DAT_0102e388;
struct FnvRefObject
{
    void FUN_00c905b0() throw();
};

hkMemoryRouter* hkMemoryRouter_getInstance();
struct FnvArray
{
    void** data;
    int size;
    unsigned int capacityAndFlags;
    ~FnvArray() throw()
    {
        hkMemoryRouter* router = hkMemoryRouter_getInstance();
        hkMemoryAllocator* mgr = (hkMemoryAllocator*)router->m_heap;
        unsigned int cap = capacityAndFlags;
        size = 0;
        if (!(cap & 0x80000000u))
            mgr->bufFree(data, (cap & 0x3fffffffu) * 4);
        data = 0;
        capacityAndFlags = 0x80000000u;
    }
};
struct FnvParent
{
    void* vtbl;
    unsigned short flags;
    short references;
    ~FnvParent() throw()
    {
        vtbl = &DAT_0102e388;
    }
};
struct FUN_00ce2600 : FnvParent
{
    FnvArray bodies, constraints, mapping;
    FnvRefObject* skeleton;
    ~FUN_00ce2600() throw();
};
// @fnv 0x00ce2600
FUN_00ce2600::~FUN_00ce2600() throw()
{
    vtbl = &DAT_010cb830;
    for (int i = 0; i < bodies.size; ++i)
        ((FnvRefObject*)bodies.data[i])->FUN_00c905b0();
    for (int j = 0; j < constraints.size; ++j)
        ((FnvRefObject*)constraints.data[j])->FUN_00c905b0();
    if (skeleton)
        skeleton->FUN_00c905b0();
    skeleton = 0;
}
}  // namespace fnv_00ce2600

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

// Calls FUN_00c91020 and passes its result to ApplyValueToTransforms when the nested pointer exists; otherwise calls FUN_00ce18d0.
// @fnv 0x00ce26f0
// src: HAVOK_LIB 0x00ce26f0
void FUN_00ce26f0_Class::hkaRagdollInstance_getApproxCurrentPoseWorldSpace(FUN_00ce2430_Transform* apTransform)
{
    FUN_00ce26f0_ObjectB* object = this->unk08->unk00;
    FUN_00ce26f0_ObjectC* target = object != 0 ? object->unk08 : 0;

    if (target == 0)
    {
        this->hkaRagdollInstance_getPoseWorldSpace_00ce18d0(apTransform);
        return;
    }

    this->ApplyValueToTransforms(target->hkpWorld_getCurrentTime(), apTransform);
}

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
hkMemoryRouter& __cdecl GetMemoryRouterR() throw();
inline hkMemoryAllocatorR& GetRagdollHeap(hkMemoryRouter& router)
{
    return *(hkMemoryAllocatorR*)router.m_heap;
}

void __cdecl hkArrayUtil_reserveR(hkMemoryAllocatorR& kAlloc, void* pkArray, int iNumElements, int iSizeElem) throw();
template <typename T> struct hkArrayRLocalForm
{ // local form of hkArray: 0x00ce2730 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    hkArrayRLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkArrayRLocalForm() throw()
    {
        hkMemoryAllocatorR& kAlloc = GetRagdollHeap(GetMemoryRouterR());
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocatorR& kAlloc = GetRagdollHeap(GetMemoryRouterR());
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            hkArrayUtil_reserveR(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <typename T> __forceinline T* hkAllocateStackR(int n)
{
    hkMemoryRouter& kRouter = GetMemoryRouterR();
    char* pcCur = (char*)kRouter.m_stack.m_next.m_storage;
    kRouter.m_stack.m_next.m_storage = (void*)((int)(pcCur + ((n * sizeof(T) + 0x7f) & ~0x7f)));
    return (T*)pcCur;
}
template <typename T> __forceinline void hkDeallocateStackR(T* p)
{
    GetMemoryRouterR().m_stack.m_next.m_storage = (void*)((int)p);
}
template <typename T> struct hkLocalArrayR : public hkArrayRLocalForm<T>
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
// clone() is not declared in the shared header yet; retain its virtual slot.
__forceinline hkpRigidBody* CloneRigidBody(const hkpRigidBody* body)
{
    typedef hkpRigidBody* (__thiscall *CloneFunction)(const hkpRigidBody*);
    return (*reinterpret_cast<CloneFunction* const*>(body))[6](body);
}
class hkpConstraintInstanceR : public hkReferencedObjectR
{
  public:
    hkpConstraintInstanceR* clone(hkpRigidBody* pkEntityA, hkpRigidBody* pkEntityB, int eCloneMode) const throw();
};
// local form of hkaRagdollInstance: 0x00ce2730 needs the inline allocation/array-constructor form; canonical clone does not reproduce exe bytes.
class hkaRagdollInstanceR : public hkReferencedObjectR
{
  public:
    __forceinline void* operator new(hk_size_tR uiBytes)
    {
        hkReferencedObjectR* b =
            static_cast<hkReferencedObjectR*>(GetRagdollHeap(GetMemoryRouterR()).AllocateMemoryBlock(uiBytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(uiBytes);
        return b;
    }
    void operator delete(void* p, hk_size_tR uiBytes);
    hkaRagdollInstanceR(const hkArrayRLocalForm<hkpRigidBody*>& kRigidBodies,
                        const hkArrayRLocalForm<hkpConstraintInstanceR*>& kConstraints, const hkaSkeleton* pkSkeleton,
                        const hkArrayRLocalForm<int>& kBoneToRigidBodyMap) throw();
    hkaRagdollInstanceR* hkaRagdollInstance_clone(int eMode) const throw();
    const hkaSkeleton* getSkeleton() const
    {
        return m_pSkeleton;
    }
    hkArrayRLocalForm<hkpRigidBody*> m_ppRigidBodies;
    hkArrayRLocalForm<hkpConstraintInstanceR*> m_ppConstraints;
    hkArrayRLocalForm<int> m_kBoneMap;
    const hkaSkeleton* m_pSkeleton;
};

// Clones the ragdoll's rigid bodies and constraints, builds a new hkaRagdollInstanceR from them, and returns it.
// @fnv 0x00ce2730
// src: HAVOK_LIB 0x00ce2730
hkaRagdollInstanceR* hkaRagdollInstanceR::hkaRagdollInstance_clone(int aeCloneMode) const throw()
{
    const int iNumRigidBodies = m_ppRigidBodies.GetLogicalSize();
    const int iNumConstraints = m_ppConstraints.GetLogicalSize();
    hkLocalArrayR<hkpRigidBody*> kNewRigidBodies(iNumRigidBodies);
    kNewRigidBodies.SetSizeAndGrow(iNumRigidBodies);
    hkLocalArrayR<hkpConstraintInstanceR*> kNewConstraints(iNumConstraints);
    kNewConstraints.SetSizeAndGrow(iNumConstraints);
    for (int rb = 0; rb < iNumRigidBodies; rb++)
    {
        const hkpRigidBody* body = m_ppRigidBodies[rb];
        hkpRigidBody*& newBody = kNewRigidBodies[rb];
        newBody = CloneRigidBody(body);
    }
    for (int c = 0; c < iNumConstraints; c++)
    {
        hkpRigidBody* pkChildRb = kNewRigidBodies[c + 1];
        hkpRigidBody* pkParentRb = kNewRigidBodies[m_pSkeleton->m_kParentIndices.m_data[c + 1]];
        kNewConstraints[c] = m_ppConstraints[c]->clone(pkChildRb, pkParentRb, aeCloneMode);
    }
    hkaRagdollInstanceR* pkNewInstance =
        new hkaRagdollInstanceR(kNewRigidBodies, kNewConstraints, getSkeleton(), m_kBoneMap);
    for (int rb = 0; rb < iNumRigidBodies; rb++)
        static_cast<const hkReferencedObject*>(kNewRigidBodies[rb])->removeReference();
    for (int c = 0; c < iNumConstraints; c++)
        kNewConstraints[c]->removeReference();
    return pkNewInstance;
}

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

// @fnv 0x00ce14b0
// src: GUESS 0x00ce14b0 (confidence: low)
void FUN_00ce14b0_standin::UpdateState_00ce14b0(unsigned short auwFirst, unsigned short auwSecond, unsigned short auwThird,
                                        const void* data)
{
    unsigned short second = auwSecond;
    unsigned short third = auwThird;

    unk20 = auwFirst;
    unk22 = second;
    unk00 = 0;
    unk04 = 0;
    unk08 = 0x80000000;
    unk24 = third;

    __m128 value = *reinterpret_cast<const __m128*>(data);
    unk10 = value;
}

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


#include "../../../../../include/hkaRagdollInstance.h"


// Passes rigid bodies and constraints to world methods; when flag is nonzero, calls another world method for each body.
// @fnv 0x00ce1680
// src: HAVOK_LIB 0x00ce1680
int hkaRagdollInstance::addToWorld(void* world, unsigned char flag)
{
    hkpRigidBody* firstBody = (hkpRigidBody*)m_ppRigidBodies.m_data[0];

    if (firstBody && firstBody->m_pOwningWorld)
        return 1;

    ((FUN_00c94bd0_Obj*)world)->hkpWorld_addEntityBatch(m_ppRigidBodies.m_data, m_ppRigidBodies.m_iElementCount, 1);

    for (int iConstraintIndex = 0; iConstraintIndex < m_ppConstraints.m_iElementCount; ++iConstraintIndex)
    {
        ((FUN_00c97d30_Obj*)world)->hkpWorld_addConstraint(m_ppConstraints.m_data[iConstraintIndex]);
    }

    if (flag)
    {
        int bodyCount = m_ppRigidBodies.m_iElementCount;
        int bodyIndex = 0;

        if (bodyCount > 0)
        {
            do
            {
                ((CallRet*)world)->hkpWorld_updateCollisionFilterOnEntity(m_ppRigidBodies.m_data[bodyIndex], 1, 0);
            } while (++bodyIndex < bodyCount);
        }
    }

    return 0;
}

extern int DAT_010cb830;
// The shared hkArray declarations leave allocator-dependent bodies to each unit.
// This unit's reserve call is 0x00c908c0 (hkArrayUtil::_reserve).
inline hkMemoryAllocator& GetArrayHeap(hkMemoryRouter& router)
{
    return *(hkMemoryAllocator*)router.m_heap;
}

template <class T> inline void SetRagdollArraySize(hkArray<T>& array, int n)
{
    hkMemoryAllocator& heap = GetArrayHeap(GetMemoryRouterR());
    int cap = array.m_iCapacityState & 0x3fffffff;
    if (cap < n)
    {
        int cap2 = 2 * cap;
        hkArrayUtil::_reserve(heap, &array, n < cap2 ? cap2 : n, sizeof(T));
    }
    array.m_iElementCount = n;
}

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

// Initializes the ragdoll's shared arrays, references, and identity bone map.
// @fnv 0x00ce2470
// src: HAVOK_LIB 0x00ce2470
RagdollInstance_ce24* RagdollInstance_ce24::hkaRagdollInstance_hkaRagdollInstance(const hkArray<ReferenceObject*>& bodies,
                                                         const hkArray<ReferenceObject*>& constraints,
                                                         hkaSkeleton* skeleton)
{
    m_vtbl = &DAT_010cb830;
    m_sReferenceCount = 1;
    m_ppRigidBodies.setOwnedData(0, 0, 0x80000000);
    m_ppConstraints.setOwnedData(0, 0, 0x80000000);
    m_kBoneMap.setOwnedData(0, 0, 0x80000000);
    m_pSkeleton = 0;
    hkaRagdollInstance_commonInit(bodies, constraints, skeleton);
    SetRagdollArraySize(m_kBoneMap, skeleton->m_kBones.m_iElementCount);
    for (int i = 0; i < skeleton->m_kBones.m_iElementCount; i++)
        m_kBoneMap[i] = i;
    return this;
}

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

// Reserves stack space for count Vec4x3 values, transforms each source entry with SIMD, calls FUN_00ce2d10, then restores the stack cursor.
// @fnv 0x00ce2f40
// src: XBOX_PDB 0x00ce2f40
void __cdecl hkaSkeletonMapper_additivePoseFromCombinedPoseAndReferencePose(unsigned int arg0, unsigned int arg1, unsigned int arg2, int count, unsigned int arg4)
{
    void** cursor = (void**)hkMemoryRouter_getInstance();
    unsigned char* pMatBase = (unsigned char*)*cursor;
    unsigned int size = (unsigned int)((count * 3) << 4) + 0x7f;
    size &= 0xffffff80u;
    *cursor = pMatBase + size;

    if (count > 0)
    {
        const Vec4x3* s = (const Vec4x3*)arg1;
        Vec4x3* d = (Vec4x3*)pMatBase;
        for (int i = 0; i < count; i++)
        {
            __m128 b = s[i].r1;
            __m128 a = s[i].r0;

            __m128 ab = _mm_mul_ps(a, b);
            __m128 vCross = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
            __m128 cb = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
            vCross = _mm_sub_ps(vCross, cb);
            __m128 vW = _mm_shuffle_ps(b, b, 0xff);
            vCross = _mm_mul_ps(vCross, vW);
            __m128 t1 = _mm_add_ss(_mm_shuffle_ps(ab, ab, 0x55), ab);
            __m128 vDot = _mm_add_ss(_mm_shuffle_ps(ab, ab, 0xaa), t1);
            __m128 t5 = _mm_mul_ps(vW, vW);
            t5 = _mm_add_ps(t5, DAT_010c71e0);
            t5 = _mm_mul_ps(t5, a);
            __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(vDot, vDot, 0), b);
            t5 = _mm_add_ps(t5, t2);
            vCross = _mm_add_ps(vCross, t5);
            __m128 res = _mm_add_ps(vCross, vCross);
            d[i].r0 = res;
            res = _mm_xor_ps(res, DAT_010c44d0);
            d[i].r0 = res;

            __m128 k = _mm_xor_ps(s[i].r1, DAT_010c4c00);
            d[i].r1 = k;

            __m128 c = s[i].r2;
            __m128 x = _mm_unpackhi_ps(c, DAT_010c7170);
            x = _mm_shuffle_ps(c, x, 0xc4);
            __m128 vRcp = _mm_rcp_ps(x);
            __m128 tt = _mm_mul_ps(vRcp, x);
            tt = _mm_mul_ps(tt, vRcp);
            __m128 vRecip = _mm_add_ps(vRcp, vRcp);
            vRecip = _mm_sub_ps(vRecip, tt);
            vRecip = _mm_and_ps(vRecip, DAT_010c4c10);
            d[i].r2 = vRecip;
        }
    }

    Runtime_ProcessEntries_00ce2d10(arg0, (void*)pMatBase, arg2, count, arg4);
    void** cursor2 = (void**)hkMemoryRouter_getInstance();
    *cursor2 = pMatBase;
}

extern float DAT_01267e30;
extern float DAT_01017d00;
extern float DAT_01017d10;

inline void hkpRigidBody::SetTranslationalVelocity(const hkVector4& vel)
{
    activate_00c9c1d0();
    m_pMotionState.SetTranslationalVelocity(vel);
}

inline void hkpRigidBody::SetRotationalVelocity(const hkVector4& vel)
{
    activate_00c9c1d0();
    m_pMotionState.SetRotationalVelocity(vel);
}

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

// Sets mapped rigid-body transforms from pose and sets each velocity to zero when not all four components are within epsilon of zero.
// @fnv 0x00ce1560
// src: GUESS 0x00ce1560 (confidence: medium)
void RagdollHelper::ApplyPoseAndClearVelocities(PoseW pose)
{
    int numBones = m_pSkeleton->m_kBones.m_iElementCount;
    const hkVector4& zero = *(const hkVector4*)&DAT_01267e30;
    int i = 0;
    if (numBones <= 0)
        return;
    const hkQsTransform* cursor = pose.p;
    do
    {
        int rbIndex = m_kBoneMap.m_data[i];
        if (rbIndex >= 0)
        {
            hkpRigidBody* rb = (hkpRigidBody*)m_ppRigidBodies.m_data[rbIndex];
            if (rb)
            {
                rb->SetPositionAndRotation(reinterpret_cast<const NiPoint3&>(cursor->m_vTranslation),
                                           reinterpret_cast<const NiQuaternion&>(cursor->m_rotation));

                __m128 kZeroVec = *(const __m128*)&zero;
                __m128 kLinVel = *(const __m128*)&rb->m_pMotionState.m_kTranslationalVelocity;
                __m128 eps = _mm_set1_ps(DAT_01017d00);
                __m128 kDiffLin = _mm_sub_ps(kZeroVec, kLinVel);
                __m128 kAbsLin = _mm_and_ps(kDiffLin, *(const __m128*)&DAT_01017d10);
                __m128 kCmpLin = _mm_cmple_ps(kAbsLin, eps);
                if ((_mm_movemask_ps(kCmpLin) & 0xf) != 0xf)
                {
                    rb->SetTranslationalVelocity(zero);
                    kZeroVec = *(const __m128*)&zero;
                }

                __m128 kAngVel = *(const __m128*)&rb->m_pMotionState.m_kAngularVelocity;
                __m128 kDiffAng = _mm_sub_ps(kZeroVec, kAngVel);
                __m128 kAbsAng = _mm_and_ps(kDiffAng, *(const __m128*)&DAT_01017d10);
                __m128 kCmpAng = _mm_cmple_ps(kAbsAng, eps);
                if ((_mm_movemask_ps(kCmpAng) & 0xf) != 0xf)
                {
                    rb->SetRotationalVelocity(zero);
                }
            }
        }
        cursor = *static_cast<const hkQsTransform* volatile*>(&cursor);
        ++i;
        ++cursor;
    } while (i < numBones);
}

template <class T> struct InitArray : ObjectArrayLocalForm<T>
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
    FUN_00ce2510(int a, int b, int c, ObjectArrayLocalForm<int>* d);
};

// Sets the vtable and reference count, calls FUN_00ce22c0, and assigns m_kBoneMap from the provided array.
// @fnv 0x00ce2510
FUN_00ce2510::FUN_00ce2510(int a, int b, int c, ObjectArrayLocalForm<int>* apBoneMap) : m_vptr(&DAT_010cb830), m_6(1)
{
    m_2c = 0;

    hkaRagdollInstance_commonInit(a, b, c);
    m_kBoneMap.assign(*apBoneMap);
}
