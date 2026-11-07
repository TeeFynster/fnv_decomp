// src/havok/animation/ragdoll/instance/hkaragdollinstance_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/animation/ragdoll/instance/hkaragdollinstance.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/animation/ragdoll/instance/hkaragdollinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/instance/hkaragdollinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkaRagdollInstance.h"
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
struct MemoryManager
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void release(void* object, unsigned short value);
};
#include "../../../../../include/hkMemoryRouter.h"
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
template <typename T> struct hkArrayR
{
    hkArrayR() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkArrayR() throw()
    {
        hkMemoryAllocatorR& kAlloc = GetMemoryRouterR().heap();
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
        hkMemoryAllocatorR& kAlloc = GetMemoryRouterR().heap();
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
    hkMemoryRouterR& kRouter = GetMemoryRouterR();
    char* pcCur = (char*)kRouter.m_aiEntries;
    kRouter.m_aiEntries = pcCur + ((n * sizeof(T) + 0x7f) & ~0x7f);
    return (T*)pcCur;
}
template <typename T> __forceinline void hkDeallocateStackR(T* p)
{
    GetMemoryRouterR().m_aiEntries = p;
}
template <typename T> struct hkLocalArrayR : public hkArrayR<T>
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
class hkpRigidBodyR : public hkReferencedObjectR
{
  public:
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual hkpRigidBodyR* clone() const throw();
};
class hkpConstraintInstanceR : public hkReferencedObjectR
{
  public:
    hkpConstraintInstanceR* clone(hkpRigidBodyR* pkEntityA, hkpRigidBodyR* pkEntityB, int eCloneMode) const throw();
};
class hkaSkeletonR : public hkReferencedObjectR
{
  public:
    const char* m_name;
    hkArrayR<short> m_kParentIndices;
};
class hkaRagdollInstanceR : public hkReferencedObjectR
{
  public:
    __forceinline void* operator new(hk_size_tR uiBytes)
    {
        hkReferencedObjectR* b =
            static_cast<hkReferencedObjectR*>(GetMemoryRouterR().heap().AllocateMemoryBlock(uiBytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(uiBytes);
        return b;
    }
    void operator delete(void* p, hk_size_tR uiBytes);
    hkaRagdollInstanceR(const hkArrayR<hkpRigidBodyR*>& kRigidBodies,
                        const hkArrayR<hkpConstraintInstanceR*>& kConstraints, const hkaSkeletonR* pkSkeleton,
                        const hkArrayR<int>& kBoneToRigidBodyMap) throw();
    hkaRagdollInstanceR* hkaRagdollInstance_clone(int eMode) const throw();
    const hkaSkeletonR* getSkeleton() const
    {
        return m_pSkeleton;
    }
    hkArrayR<hkpRigidBodyR*> m_ppRigidBodies;
    hkArrayR<hkpConstraintInstanceR*> m_ppConstraints;
    hkArrayR<int> m_kBoneMap;
    const hkaSkeletonR* m_pSkeleton;
};
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
void __cdecl hkArrayUtil__reserve(ArrayAllocator* heap, void* array, int numElements, int sizeOfElement);
struct RouterRef_ce24
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    ArrayAllocator* m_pStreamAllocator;
    ArrayAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
    static RouterRef_ce24& __cdecl hkMemoryRouter_getInstance() throw();
};
template <class T> struct hkArray_ce24
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void SetSizeAndGrow(int n)
    {
        ArrayAllocator& heap = RouterRef_ce24::hkMemoryRouter_getInstance().heap();
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = 2 * cap;
            hkArrayUtil__reserve(&heap, this, n < cap2 ? cap2 : n, sizeof(T));
        }
        m_iElementCount = n;
    }
};
struct Skeleton_ce24
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    int m_iBoneCount;
};
struct RagdollInstance_ce24
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    hkArray_ce24<ReferenceObject*> m_ppRigidBodies;
    hkArray_ce24<ReferenceObject*> m_ppConstraints;
    hkArray_ce24<int> m_kBoneMap;
    Skeleton_ce24* m_pSkeleton;
    void hkaRagdollInstance_commonInit(const hkArray_ce24<ReferenceObject*>& bodies, const hkArray_ce24<ReferenceObject*>& constraints,
                      Skeleton_ce24* skeleton);
    RagdollInstance_ce24* hkaRagdollInstance_hkaRagdollInstance(const hkArray_ce24<ReferenceObject*>& bodies,
                                       const hkArray_ce24<ReferenceObject*>& constraints, Skeleton_ce24* skeleton);
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
struct UnkCall
{
    void activate_00c9c1d0();
    void hkpRigidBody_setPositionAndRotation(const hkVector4& pos, const hkQuaternion& rot);
};
struct hkpMotion
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void SetTranslationalVelocity(const hkVector4& vel);
    virtual void SetRotationalVelocity(const hkVector4& vel);
    int unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
};
struct hkpRigidBody : public UnkCall
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc;
    hkpMotion m_pMotionState;

    void SetTranslationalVelocity(const hkVector4& vel)
    {
        activate_00c9c1d0();
        m_pMotionState.SetTranslationalVelocity(vel);
    }
    void SetRotationalVelocity(const hkVector4& vel)
    {
        activate_00c9c1d0();
        m_pMotionState.SetRotationalVelocity(vel);
    }
};
struct hkaBone
{
    hkStringPtr m_name;
    hkBool m_bLockTranslation;
};
class hkaSkeleton : public hkReferencedObject
{
  public:
    hkStringPtr m_name;
    hkArray<hkInt16> m_kParentIndices;
    hkArray<hkaBone> m_kBones;
};
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
