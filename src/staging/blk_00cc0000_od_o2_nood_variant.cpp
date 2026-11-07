#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// staging/blk_00cc0000_od_o2_nood_variant.cpp: TransformOwner, Obj, Cd2Owner, PoseQuaternion and more (33 functions)

#include <windows.h>
// Retain the unit's minimal intrinsic declaration for the original compiler.
#define _INCLUDED_MM2
// Exe 0x00cda8e0 FUN_00cda8e0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#include "../../include/Transform.h"
#include "../../include/AutoMemContext.h"
#include "../../include/hkAabb.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/NiPoint3.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkArray.h"
#include "../../include/hkReferencedObject.h"
// hkVec4Q_blk_00cc0000_od_o2_nood_variant: local type (was include/hkVec4Q.h, which had no evidence of one real class); no method of it is bound to a named game function
__if_not_exists(__m128)
{
#include <xmmintrin.h>
}

extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);

struct hkMat3Q;

class hkVec4Q_blk_00cc0000_od_o2_nood_variant
{
public:
    LocalM128 m_vComponents;

    __forceinline LocalM128 getSimdAt(int) const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }

    __forceinline void addMul4(LocalM128 r, const hkVec4Q_blk_00cc0000_od_o2_nood_variant& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(r, r, 0), a.m_vComponents));
    }

    __forceinline void setSub4(const hkVec4Q_blk_00cc0000_od_o2_nood_variant& a, const hkVec4Q_blk_00cc0000_od_o2_nood_variant& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }

    __forceinline void setCross(const hkVec4Q_blk_00cc0000_od_o2_nood_variant& v1, const hkVec4Q_blk_00cc0000_od_o2_nood_variant& v2)
    {
        LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                  _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                  _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }

    __forceinline void setMul4(const hkVec4Q_blk_00cc0000_od_o2_nood_variant& a, const hkVec4Q_blk_00cc0000_od_o2_nood_variant& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }

    __forceinline void add4(const hkVec4Q_blk_00cc0000_od_o2_nood_variant& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }

    __forceinline LocalM128 dot3(const hkVec4Q_blk_00cc0000_od_o2_nood_variant& a) const
    {
        LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        LocalM128 result = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), result);
    }

    void _setRotatedDir(const struct hkMat3Q& r, const hkVec4Q_blk_00cc0000_od_o2_nood_variant& b);
    void _setRotatedInverseDir(const struct hkMat3Q& r, const hkVec4Q_blk_00cc0000_od_o2_nood_variant& b);
};
#include "../../include/hkVector4.h"
#include "../../include/hkpConvexShape.h"
#include "../../include/hkpShape.h"

// Keep the original inline implementations with the shared declarations.
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
inline void hkVector4::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}
__forceinline void hkAabb::Init(unsigned a, unsigned b)
{
    *(unsigned*)&m_kMinimumCorner.x = a;
    *(unsigned*)&m_kMinimumCorner.y = b;
}

// src/staging/blk_00cc0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00cc0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_00cc0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/MemoryManager.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/NiPoint3.h"

extern "C" __declspec(thread) int tls_memContext;
__forceinline AutoMemContext::AutoMemContext(int ctx)
{
    m_eMemoryContext = (MEM_CONTEXT)tls_memContext;
    tls_memContext = ctx;
}
__forceinline AutoMemContext::~AutoMemContext()
{
    tls_memContext = m_eMemoryContext;
}

hkMemoryRouter* hkMemoryRouter_getInstance();

struct TransformObj
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_v20;
    hkVector4 m_v30;
    hkVector4 m_v40;
    hkVector4 m_v50;
    hkVector4 m_v60;
    hkVector4 m_v70;
    int unk80;
    float m_f84;
    float m_f88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;

    static void* operator new(unsigned int nbytes)
    {
        TransformObj* p = (TransformObj*)hkMemoryRouter_getInstance()->heap().blockAlloc(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);

    TransformObj();
};

struct TransformOwner
{
    int unk00;
    TransformObj* m_pSource;

    void ReleaseObject(TransformObj* pkObj, int iArg);
    void hkHingeLimitsConstraintCinfo_CloneData(TransformObj* pkObj, int iArg);
};

// @fnv 0x00cc85b0
// src: XBOX_PDB 0x00cc85b0
void TransformOwner::hkHingeLimitsConstraintCinfo_CloneData(TransformObj* pkObj, int iArg)
{
    AutoMemContext kGuard(0x10);
    TransformObj* pkSource = m_pSource;
    if (!pkObj)
        pkObj = new TransformObj();
    pkObj->m_v20 = pkSource->m_v20;
    pkObj->m_v30 = pkSource->m_v30;
    pkObj->m_v40 = pkSource->m_v40;
    pkObj->m_v50 = pkSource->m_v50;
    pkObj->m_v60 = pkSource->m_v60;
    pkObj->m_v70 = pkSource->m_v70;
    pkObj->m_f84 = pkSource->m_f84;
    pkObj->m_f88 = pkSource->m_f88;
    ReleaseObject(pkObj, iArg);
}

namespace fnv_00cdb7c0 {
struct __declspec(align(16)) Mat
{
    float m[12];
    Mat& operator=(const Mat& o)
    {
        *(LocalM128*)&m[0] = *(const LocalM128*)&o.m[0];
        *(LocalM128*)&m[4] = *(const LocalM128*)&o.m[4];
        *(LocalM128*)&m[8] = *(const LocalM128*)&o.m[8];
        return *this;
    }
};

struct ScratchStack
{
    char* top;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* heap;
};

ScratchStack* hkMemoryRouter_getInstance();

struct Info2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int* unk20;
    int unk24;
    int unk28;
    Info2* unk2c;
};

struct Params
{
    Mat m;
    Mat* p;
    int n;
};

struct Sub18
{
    unsigned int count;
};

void hkaKeyFrameHierarchyUtility_applyKeyFrame(float t, Params* p, Sub18* s, int a, int b);

struct Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int unk10;
    int unk14;
    Sub18 unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    Info* unk38;
    void hkaRagdollRigidBodyController_driveToPose(float t, Mat* src, const Mat& xf, int a4);
};

struct ScratchBuf
{
    Mat* data;
    unsigned int count;
    ScratchBuf(unsigned int n)
    {
        ScratchStack* ss = hkMemoryRouter_getInstance();
        data = (Mat*)ss->top;
        ss->top = (char*)data + ((n * sizeof(Mat) + 0x7f) & ~0x7f);
        count = n | 0x80000000;
    }
    void Release()
    {
        hkMemoryRouter_getInstance()->top = (char*)data;
        hkMemoryAllocator* h = hkMemoryRouter_getInstance()->heap;
        if (!(count & 0x80000000))
        {
            count &= 0x3fffffff;
            h->bufFree(data, count * sizeof(Mat));
        }
    }
};
// @fnv 0x00cdb7c0
// src: COMMUNITY 0x00cdb7c0
void Obj::hkaRagdollRigidBodyController_driveToPose(float t, Mat* src, const Mat& xf, int a4)
{
    Params p;
    p.n = unk2c;
    p.m = xf;
    unk24 = (unk10 == unk18.count) ? unk0c : 0;
    if (unk38->unk0c != unk38->unk2c->unk1c)
    {
        ScratchBuf buf(unk18.count);
        for (int i = 0; i < unk38->unk2c->unk1c; i++)
        {
            int idx = unk38->unk20[i];
            if (idx >= 0)
                buf.data[idx] = src[i];
        }
        p.p = buf.data;
        hkaKeyFrameHierarchyUtility_applyKeyFrame(t, &p, &unk18, unk00, a4);
        buf.Release();
    }
    else
    {
        p.p = src;
        hkaKeyFrameHierarchyUtility_applyKeyFrame(t, &p, &unk18, unk00, a4);
    }
}
}  // namespace fnv_00cdb7c0

namespace fnv_00cc6830 {

hkMemoryRouter* hkMemoryRouter_getInstance();
void FUN_00c8b4f0(void* p, int nbytes);

class CloneableMotionReference : public hkReferencedObject
{
public:
    virtual CloneableMotionReference* Clone();
};

class Cc6830Motion
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_v20;
    hkVector4 m_v30;
    hkVector4 m_v40;
    hkVector4 m_v50;
    hkVector4 m_v60;
    hkVector4 m_v70;
    hkVector4 m_v80;
    hkVector4 m_v90;
    char unkA0;
    char unkA1;
    char m_flagA2;
    char unkA3;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    float m_fF8;
    int unkFC;
    int unk100;
    float m_f104;
    float m_f108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    float m_f11C;
    int unk120;
    int unk124;
    int unk128;
    float m_f12C;
    float m_f130;
    int unk134;
    int unk138;
    int unk13C;

    static void* operator new(unsigned int nbytes)
    {
        Cc6830Motion* p = (Cc6830Motion*)hkMemoryRouter_getInstance()->heap().blockAlloc(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00c8b4f0(p, nbytes);
    }

    Cc6830Motion();

    void hkpRagdollConstraintData_setMaxFrictionTorque(float f);
    CloneableMotionReference* hkpRagdollConstraintData_getTwistMotor();
    void hkpRagdollConstraintData_setTwistMotor(CloneableMotionReference* r);
    void hkpRagdollConstraintData_setPlaneMotor(CloneableMotionReference* r);
    void hkpRagdollConstraintData_setConeMotor(CloneableMotionReference* r);
};

struct Cc6830Src
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float m_vScale;
};

void hkHingeConstraintCinfo_ApplyScale(float s, Cc6830Motion* m);

class Cc6830Self
{
  public:
    int unk00;
    Cc6830Motion* m_pMotionState;

    void hkRagdollConstraintCinfo_CloneData(Cc6830Motion* dst, const Cc6830Src* src);
    void ReleaseObject(Cc6830Motion* m, const Cc6830Src* src);
};

// @fnv 0x00cc6830
// src: XBOX_PDB 0x00cc6830
void Cc6830Self::hkRagdollConstraintCinfo_CloneData(Cc6830Motion* dst, const Cc6830Src* src)
{
    Cc6830Motion* m = m_pMotionState;
    if (!dst)
    {
        dst = new Cc6830Motion();
    }
    dst->m_v20 = m->m_v20;
    dst->m_v30 = m->m_v30;
    dst->m_v40 = m->m_v40;
    dst->m_v50 = m->m_v50;
    dst->m_v60 = m->m_v60;
    dst->m_v70 = m->m_v70;
    dst->m_v80 = m->m_v80;
    dst->m_v90 = m->m_v90;
    dst->m_f11C = m->m_f11C;
    dst->m_f12C = m->m_f12C;
    dst->m_f130 = m->m_f130;
    dst->m_f104 = m->m_f104;
    dst->m_f108 = m->m_f108;
    dst->hkpRagdollConstraintData_setMaxFrictionTorque(m->m_fF8);
    float scale = src->m_vScale;
    if (scale != 1.0f)
    {
        hkHingeConstraintCinfo_ApplyScale(scale, dst);
    }
    CloneableMotionReference* r = m->hkpRagdollConstraintData_getTwistMotor();
    if (r)
    {
        CloneableMotionReference* x = r->Clone();
        dst->hkpRagdollConstraintData_setTwistMotor(x);
        dst->hkpRagdollConstraintData_setPlaneMotor(x);
        dst->hkpRagdollConstraintData_setConeMotor(x);
        x->removeReference();
        dst->m_flagA2 = m->m_flagA2;
    }
    ReleaseObject(dst, src);
}
}  // namespace fnv_00cc6830

namespace fnv_00cc91c0 {

struct hkVector4Pair
{
    hkVector4 m_kPointA;
    hkVector4 m_kPointB;
};

void* __cdecl hkMemoryRouter_getInstance();

__forceinline hkMemoryAllocator& containerHeap()
{
    return static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->heap();
}

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* array, int reqCapacity, int sizeElem);

}  // namespace fnv_00cc91c0

// hkArray bodies this function inlines (hkArray.inl; hkContainerHeapAllocator = the router's heap).
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return fnv_00cc91c0::containerHeap();
}
template <typename T> __forceinline void hkArrayBase<T>::clear()
{
    m_iElementCount = 0;
}
template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kHeap, int iWanted)
{
    const int iHave = getCapacity();
    if (iHave < iWanted)
    {
        int iTwice = 2 * iHave;
        int iGrowTo = (iWanted < iTwice) ? iTwice : iWanted;
        fnv_00cc91c0::hkArrayUtil__reserve(kHeap, this, iGrowTo, sizeof(T));
    }
}
template <typename T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}

namespace fnv_00cc91c0 {

struct PairSource
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkArray<hkVector4Pair> m_pairs;
};

struct SourceHolder
{
    int unk00;
    int unk04;
    int unk08;
    PairSource* m_pObservedSource;
};

struct VectorOutput
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkArray<hkVector4> m_kShapeVectorData;
};

void __stdcall CopyContainerKeysToInfo(VectorOutput* out);

struct BaseA
{
    int unk00;
    int unk04;
};

struct BaseB
{
    SourceHolder* m_holder;
};

struct FUN_00cc91c0_cls : public BaseA, public BaseB
{
    void bhkBallSocketConstraintChain_CopyCinfo(VectorOutput* out);
};

// @fnv 0x00cc91c0
// src: XBOX_PDB 0x00cc91c0
void FUN_00cc91c0_cls::bhkBallSocketConstraintChain_CopyCinfo(VectorOutput* out)
{
    CopyContainerKeysToInfo(out);
    SourceHolder* holder = this ? m_holder : 0;
    out->m_kShapeVectorData.clear();
    const PairSource* src = holder->m_pObservedSource;
    out->m_kShapeVectorData.setSize(src->m_pairs.GetLogicalSize() * 2);
    int j = 0;
    for (int i = 0; i < src->m_pairs.GetLogicalSize(); i++)
    {
        hkVector4 a = src->m_pairs[i].m_kPointA;
        out->m_kShapeVectorData[j++] = a;
        hkVector4 b = src->m_pairs[i].m_kPointB;
        out->m_kShapeVectorData[j++] = b;
    }
}
}  // namespace fnv_00cc91c0

bool __stdcall bhkShape_CanShare(void* key);

struct Cd2Target
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual bool Accepts(void* key);
};

struct Cd2Entry
{
    int unk00;
    int unk04;
    Cd2Target* m_target;
};

struct Cd2Iterable
{
    virtual void v00();
    virtual void v04();
    virtual int GetFirst();
    virtual int GetNext(int i);
    virtual void v10();
    virtual Cd2Entry* GetEntry(int i, char* buffer);
};

struct Cd2Collection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Cd2Iterable m_items;
};

class Cd2Owner
{
  public:
    int unk00;
    int unk04;
    Cd2Collection* m_pShapeCollection;

    __forceinline Cd2Collection* GetCollection()
    {
        return this ? m_pShapeCollection : 0;
    }
    bool bhkShapeCollection_CanShare(void* key);
};

// @fnv 0x00cd2f10
// src: XBOX_PDB 0x00cd2f10
bool Cd2Owner::bhkShapeCollection_CanShare(void* key)
{
    __declspec(align(16)) char buffer[512];
    bool ok = bhkShape_CanShare(key);
    if (ok)
    {
        for (int i = GetCollection()->m_items.GetFirst(); i != -1 && ok; i = GetCollection()->m_items.GetNext(i))
        {
            Cd2Collection* collection = GetCollection();
            if (collection)
            {
                Cd2Entry* entry = collection->m_items.GetEntry(i, buffer);
                if (entry)
                {
                    Cd2Target* target = entry->m_target;
                    if (target)
                        ok = target->Accepts(key);
                }
            }
        }
    }
    return ok;
}

extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ps(float const*);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_rcp_ps(LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    void _mm_store_ps(float*, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
}
extern "C" const LocalM128 DAT_010c71e0;
extern "C" const LocalM128 DAT_010c44d0;
extern "C" const LocalM128 DAT_010c4c00;
extern "C" const LocalM128 DAT_010c7170;
extern "C" const LocalM128 DAT_010c4c10;

struct __declspec(align(16)) PoseVector
{
    union
    {
        LocalM128 value;
        float lane[4];
    };
    PoseVector()
    {}
    PoseVector(LocalM128 x) : value(x)
    {}
    PoseVector(const PoseVector& x) : value(x.value)
    {}
    PoseVector& operator=(const PoseVector& x)
    {
        value = x.value;
        return *this;
    }
    __forceinline LocalM128 dot(const PoseVector& other) const
    {
        LocalM128 a = _mm_mul_ps(value, other.value);
        LocalM128 b = _mm_add_ss(_mm_shuffle_ps(a, a, 0x55), a);
        return _mm_add_ss(_mm_shuffle_ps(a, a, 0xaa), b);
    }
    __forceinline LocalM128 dotLoaded(const PoseVector& other) const
    {
        LocalM128 a = _mm_mul_ps(_mm_load_ps(reinterpret_cast<const float*>(&value)), other.value);
        LocalM128 b = _mm_add_ss(_mm_shuffle_ps(a, a, 0x55), a);
        return _mm_add_ss(_mm_shuffle_ps(a, a, 0xaa), b);
    }
    __forceinline void cross(const PoseVector& a, const PoseVector& b)
    {
        LocalM128 first = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        LocalM128 second = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(first, second);
    }
    __forceinline void addProduct(const PoseVector& a, const PoseVector& b)
    {
        value = _mm_add_ps(_mm_mul_ps(a.value, b.value), value);
    }
    __forceinline void rotate(const PoseVector& q, const PoseVector& v)
    {
        LocalM128 real = _mm_shuffle_ps(q.value, q.value, 0xff);
        PoseVector square(_mm_add_ps(_mm_mul_ps(real, real), DAT_010c71e0));
        PoseVector accum(_mm_mul_ps(v.value, square.value));
        LocalM128 dot3 = q.dotLoaded(v);
        PoseVector dotSplat(_mm_shuffle_ps(dot3, dot3, 0));
        accum.addProduct(dotSplat, q);
        PoseVector product;
        product.cross(q, v);
        PoseVector realV(real);
        accum.addProduct(realV, product);
        value = _mm_add_ps(accum.value, accum.value);
    }
    __forceinline void rotateBack(const PoseVector& q, const PoseVector& v)
    {
        LocalM128 real = _mm_shuffle_ps(q.value, q.value, 0xff);
        PoseVector square(_mm_add_ps(_mm_mul_ps(real, real), DAT_010c71e0));
        PoseVector accum(_mm_mul_ps(v.value, square.value));
        LocalM128 dot3 = q.dot(v);
        PoseVector dotSplat(_mm_shuffle_ps(dot3, dot3, 0));
        accum.addProduct(dotSplat, q);
        PoseVector product;
        product.cross(v, q);
        PoseVector realV(real);
        accum.addProduct(realV, product);
        value = _mm_add_ps(accum.value, accum.value);
    }
};
struct PoseQuaternion
{
    PoseVector vector;
    void setMul(const PoseQuaternion&, const PoseQuaternion&);
};
extern "C" unsigned int __security_cookie;
extern "C" void __fastcall __security_check_cookie(unsigned int);
struct QuaternionProduct
{
    LocalM128 quad;
};
// src: COMMUNITY 0x00c66320
__declspec(noinline) void PoseQuaternion::setMul(const PoseQuaternion& a, const PoseQuaternion& b)
{
    unsigned int cookie = __security_cookie;
    PoseVector cross;
    cross.cross(a.vector, b.vector);
    LocalM128 aw = _mm_shuffle_ps(a.vector.value, a.vector.value, 0xff);
    LocalM128 bw = _mm_shuffle_ps(b.vector.value, b.vector.value, 0xff);
    LocalM128 xyz = _mm_add_ps(_mm_add_ps(_mm_mul_ps(aw, b.vector.value), cross.value), _mm_mul_ps(bw, a.vector.value));
    LocalM128 product = _mm_mul_ps(a.vector.value, b.vector.value);
    LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    LocalM128 real = _mm_sub_ps(product, _mm_shuffle_ps(sum, sum, 0));
    QuaternionProduct result;
    result.quad = _mm_shuffle_ps(xyz, _mm_unpackhi_ps(xyz, real), 0xc4);
    vector.value = result.quad;
    __security_check_cookie(cookie);
}
struct PoseTransform
{
    PoseVector translation;
    PoseQuaternion rotation;
    PoseVector scale;
    PoseTransform& operator=(const PoseTransform& o)
    {
        translation = o.translation;
        rotation.vector = o.rotation.vector;
        scale = o.scale;
        return *this;
    }
    __forceinline void inverse(const PoseTransform& p)
    {
        translation.rotateBack(p.rotation.vector, p.translation);
        translation.value = _mm_xor_ps(translation.value, DAT_010c44d0);
        rotation.vector.value = _mm_xor_ps(p.rotation.vector.value, DAT_010c4c00);
        LocalM128 input = _mm_shuffle_ps(p.scale.value, _mm_unpackhi_ps(p.scale.value, DAT_010c7170), 0xc4);
        LocalM128 seed = _mm_rcp_ps(input);
        LocalM128 correction = _mm_mul_ps(_mm_mul_ps(input, seed), seed);
        scale.value = _mm_and_ps(_mm_sub_ps(_mm_add_ps(seed, seed), correction), DAT_010c4c10);
    }
    __forceinline void multiply(const PoseTransform& a, const PoseTransform& b)
    {
        PoseVector moved;
        moved.rotate(a.rotation.vector, b.translation);
        translation.value = _mm_add_ps(a.translation.value, moved.value);
        rotation.setMul(a.rotation, b.rotation);
        scale.value = _mm_mul_ps(a.scale.value, b.scale.value);
    }
    __forceinline void relative(const PoseTransform& a, const PoseTransform& b)
    {
        PoseTransform inverseParent;
        inverseParent.inverse(a);
        multiply(inverseParent, b);
    }
};
struct SkeletonData
{
    int unk00, unk04, unk08;
    short* parents;
    int unk10, unk14, unk18;
    int count;
};
struct PoseState
{
    SkeletonData* skeleton;
    PoseTransform* local;
    int unk08, unk0c;
    PoseTransform* world;
    int unk14, unk18;
    int* flags;
    int unk20, unk24;
    bool synchronized;
    const PoseTransform& hkaPose_calculateBoneModelSpace(int);
    __forceinline const PoseTransform& getWorld(int i)
    {
        if (!(flags[i] & 2))
            return world[i];
        return hkaPose_calculateBoneModelSpace(i);
    }
    __forceinline const PoseTransform& getLocal(int i)
    {
        if (flags[i] & 1)
        {
            const PoseTransform& boneWorld = world[i];
            short parent = skeleton->parents[i];
            if (parent != -1)
            {
                const PoseTransform& parentWorld = getWorld(parent);
                local[i].relative(parentWorld, boneWorld);
            }
            else
                local[i] = boneWorld;
            flags[i] &= ~1;
        }
        return local[i];
    }
    __forceinline void prepareChildren(int index)
    {
        const int count = skeleton->count;
        flags[index] |= 4;
        for (int bone = index + 1; bone < count; ++bone)
        {
            short parent = skeleton->parents[bone];
            if (parent != -1 && (flags[parent] & 4))
            {
                getLocal(bone);
                flags[bone] |= 4;
                synchronized = false;
            }
        }
        for (int bone = index + 1; bone < count; ++bone)
        {
            int state = flags[bone];
            if (state & 4)
            {
                state |= 2;
                state &= ~4;
                flags[bone] = state;
            }
        }
    }
    PoseTransform& hkaPose_accessBoneLocalSpace(int index);
};
// @fnv 0x00cda8e0
// src: COMMUNITY 0x00cda8e0
PoseTransform& PoseState::hkaPose_accessBoneLocalSpace(int index)
{
    prepareChildren(index);
    getLocal(index);
    bool& sync = synchronized;
    flags[index] = 2;
    sync = false;
    return local[index];
}

struct FUN_00d4f2a0
{
    int unk00;
    unsigned short m_iElementCount;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    LocalM128 m_20;
    LocalM128 m_30;
    LocalM128 m_40;
    LocalM128 m_50;
    LocalM128 m_60;
    LocalM128 m_70;
    int unk80;
    int unk84;
    float m_88;
    float m_8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    float m_a0;
    int unkA4;
    int unkA8;
    int unkAC;
    float m_b0;
    float m_b4;
    int unkB8;
    int unkBC;

    FUN_00d4f2a0();
    static void operator delete(void* p) throw()
    {}
    static __forceinline void* operator new(unsigned int size) throw()
    {
        hkMemoryRouter* h = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        void* p = h->m_heap->blockAlloc(size);
        ((FUN_00d4f2a0*)p)->m_iElementCount = (unsigned short)size;
        return p;
    }
};

struct FUN_00cc5f30_cls
{
    int unk00;
    FUN_00d4f2a0* m_pSrc;

    void hkRagdollLimitsConstraintCinfo_CloneData(FUN_00d4f2a0* dst, int a2);
    void ReleaseObject(FUN_00d4f2a0* dst, int a2);
};

// @fnv 0x00cc5f30
// src: XBOX_PDB 0x00cc5f30
void FUN_00cc5f30_cls::hkRagdollLimitsConstraintCinfo_CloneData(FUN_00d4f2a0* dst, int a2)
{
    FUN_00d4f2a0* src = m_pSrc;
    if (dst == 0)
    {
        dst = new FUN_00d4f2a0();
    }
    _mm_store_ps((float*)&dst->m_20, src->m_20);
    _mm_store_ps((float*)&dst->m_30, src->m_30);
    dst->m_40 = src->m_40;
    dst->m_50 = src->m_50;
    dst->m_60 = src->m_60;
    dst->m_70 = src->m_70;
    dst->m_a0 = src->m_a0;
    dst->m_b0 = src->m_b0;
    dst->m_b4 = src->m_b4;
    dst->m_88 = src->m_88;
    dst->m_8c = src->m_8c;
    ReleaseObject(dst, a2);
}

struct S_00ccbce0_Source
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
    LocalM128 unk80;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    float unkE4;
};

struct S_00ccbce0_Ref
{
    virtual void FUN_00ccbce0_ref0();
    virtual void FUN_00ccbce0_ref1();

    LONG unk04;
};

struct S_00ccbce0_Output
{
    int unk00;
    S_00ccbce0_Ref* unk04;
    float unk08;
    int unk0c;
    LocalM128 unk10;
};

struct S_00ccbce0_Owner
{
    int unk00;
    int unk04;
    S_00ccbce0_Source* unk08;
    int unk0c;
    int unk10;
    S_00ccbce0_Ref* unk14;

    void __thiscall bhkShape_CopyCinfo(S_00ccbce0_Output* value);
    void __thiscall bhkExtendedMeshShape_CopyCinfo(S_00ccbce0_Output* value);
};

// @fnv 0x00ccbce0
// src: XBOX_PDB 0x00ccbce0
void S_00ccbce0_Owner::bhkExtendedMeshShape_CopyCinfo(S_00ccbce0_Output* value)
{
    this->bhkShape_CopyCinfo(value);

    S_00ccbce0_Source* source = this ? this->unk08 : (S_00ccbce0_Source*)0;

    S_00ccbce0_Ref* oldRef = value->unk04;

    if (oldRef != this->unk14)
    {
        if (oldRef)
        {
            if (InterlockedDecrement(&oldRef->unk04) == 0)
                oldRef->FUN_00ccbce0_ref1();
        }

        S_00ccbce0_Ref* newRef = this->unk14;
        value->unk04 = newRef;

        if (newRef)
            InterlockedIncrement(&newRef->unk04);
    }

    value->unk08 = source->unkE4;
    value->unk10 = source->unk80;
}

extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
union hkVec4
{
    LocalM128 m_vComponents;
    char m_bytes[16];
};
struct BytePair
{
    char a;
    char b;
};
struct EntityCinfo
{
    int unk00, unk04, unk08, unk0C;
    float m_vContactPosition[4];
    float m_rotation[4];
    float unk30, unk34, unk38;
    char unk3C, unk3D;
};
struct EntityObj
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short unk06;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C;
    float unk50, unk54, unk58;
    char unk5C, unk5D;
    static void* operator new(unsigned int nbytes)
    {
        EntityObj* p = (EntityObj*)hkMemoryRouter_getInstance()->heap().blockAlloc(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);
    EntityObj(int a, int b, int c);
    void SetPivots(const hkVector4& position, const hkVector4& rotation);
    void removeReference();
};
struct EntityOwner
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void HandleNode(EntityObj* obj);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual int AddCinfo(EntityCinfo* info);
    int bhkSpringAction_Init(EntityCinfo* info);
};
// @fnv 0x00cc3050
// src: XBOX_PDB 0x00cc3050
int EntityOwner::bhkSpringAction_Init(EntityCinfo* info)
{
    AutoMemContext guard(0x10);
    EntityObj* entity = new EntityObj(info->unk04, info->unk08, 0);
    entity->unk54 = info->unk34;
    entity->unk58 = info->unk38;
    entity->unk50 = info->unk30;
    BytePair flags;
    flags.a = info->unk3C;
    entity->unk5C = flags.a;
    flags.b = *(volatile char*)&info->unk3D;
    entity->unk5D = flags.b;
    hkVec4 rotation;
    rotation.m_vComponents =
        _mm_setr_ps(info->m_rotation[0], info->m_rotation[1], info->m_rotation[2], info->m_rotation[3]);
    hkVec4 position;
    position.m_vComponents =
        _mm_setr_ps(info->m_vContactPosition[0], info->m_vContactPosition[1], info->m_vContactPosition[2], info->m_vContactPosition[3]);
    entity->SetPivots(*(hkVector4*)&position, *(hkVector4*)&rotation);
    HandleNode(entity);
    entity->removeReference();
    return AddCinfo(info);
}

class S_00cd3c20_Obj
{
  public:
    void bhkCharacterController_UpdateState();
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    LocalM128 unk4f0;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    float unk514;
    int unk518;
    int unk51c;
    int unk520;
};

// @fnv 0x00cd3c20
// src: COMMUNITY 0x00cd3c20
void __stdcall bhkCharacterStateClimbing_Update(S_00cd3c20_Obj* obj)
{
    if (obj->unk520 != 0xb)
    {
        obj->bhkCharacterController_UpdateState();
        return;
    }
    obj->unk414 |= 0x400;
    float* ps = &obj->unk514;
    obj->unk4f0 = _mm_setr_ps(0.0f, 0.0f, *ps, 0.0f);
}

struct ShapeVector
{
    hkVec4 m_v;
    ShapeVector(float x, float y, float z, float w)
    {
        m_v.m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct IntegerBlock18
{
    int unk00;
    int m_iType;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
};

struct ShapeObj
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short unk06;
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

    static void* operator new(unsigned int nbytes)
    {
        ShapeObj* p = (ShapeObj*)hkMemoryRouter_getInstance()->heap().blockAlloc(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);

    ShapeObj(int iType, const ShapeVector& kVec, float fA, float fB);
    void FUN_00c905b0();
};

struct ShapeOwner
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void addObject(struct ShapeObj* pkObj);
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void finish(struct IntegerBlock18* pkInfo);
    void bhkMotorAction_Init(IntegerBlock18* pkInfo);
};

// @fnv 0x00cc3710
// src: XBOX_PDB 0x00cc3710
void ShapeOwner::bhkMotorAction_Init(IntegerBlock18* pkInfo)
{
    AutoMemContext kGuard(0x10);
    ShapeObj* pkObj =
        new ShapeObj(pkInfo->m_iType, ShapeVector(pkInfo->m_f10, pkInfo->m_f14, pkInfo->m_f18, pkInfo->m_f1C),
                     pkInfo->m_f20, pkInfo->m_f24);
    addObject(pkObj);
    pkObj->FUN_00c905b0();
    finish(pkInfo);
}

struct S00cc4610_Out
{
    int unk00;
    unsigned short m_iElementCount;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    LocalM128 q20;
    float m_30;
    float m_34;
    int unk38;
    int unk3C;
    S00cc4610_Out(int a, int b, int c);
    void* operator new(unsigned int n)
    {
        hkMemoryAllocator& a = hkMemoryRouter_getInstance()->heap();
        void* p = a.blockAlloc(n);
        ((S00cc4610_Out*)p)->m_iElementCount = (unsigned short)n;
        return p;
    }
};

struct S00cc4610_In
{
    int unk00;
    int m_04;
    int m_08;
    int unk0C;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
};

static inline void s00cc4610_copy(LocalM128& d, const LocalM128& s)
{
    d = s;
}

struct S00cc4610_Self
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35(S00cc4610_Out* o);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47(S00cc4610_In* i);
    void bhkAngularDashpotAction_Init(S00cc4610_In* in);
};

// @fnv 0x00cc4610
// src: XBOX_PDB 0x00cc4610
void S00cc4610_Self::bhkAngularDashpotAction_Init(S00cc4610_In* in)
{
    AutoMemContext scope(0x10);

    S00cc4610_Out* r = new S00cc4610_Out(in->m_04, in->m_08, 0);
    r->m_30 = in->m_20;
    r->m_34 = in->m_24;
    union
    {
        LocalM128 q;
        char b[16];
    } u0;
    u0.q = _mm_setr_ps(in->m_10, in->m_14, in->m_18, in->m_1c);
    const LocalM128* pv = &u0.q;
    r->q20 = *pv;
    v35(r);
    ((hkReferencedObject*)r)->removeReference();
    v47(in);
}

struct Cc7Bool
{
    char value;
};
struct Cc7Local
{
    void* constraint;
    void* scheme;
    int stiffnessReference, dampingReference;
    Cc7Bool linearA[3], linearB[3];
    Cc7Bool angularA, angularB, pivotA, pivotB;
    void InitFromHelper(void* source);
    void ProcessAndReturnValue_00d52000(void* out);
    void UpdateState_00d51c30(void* tmp);
    void* ProcessAndReturnValue_00d520a0(void* out);
    void* ProcessAndReturnValue_00d51d40(void* tmp);
    void AddBridgeAtoms();
    void AppendEntryAndAdvance();
    void ProcessAndReturnValue_00d52ae0(float value);
    void hkpConstraintConstructionKit_restoreStrength();
    void AppendZeroItem();
};

struct __declspec(align(16)) Cc7Vector
{
    unsigned char lanes[16];
};
struct Cc7Tmp
{
    Cc7Vector column0, column1, column2;
    Cc7Vector translation;
    void hkTransform_setMulInverseMul(void* base, void* arg);
};

extern const float g_011c5c70_arg1;

struct Cc7Owner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    void* m04;
    void* m08;
    char* m0c;
    char* m10;
    void* m14;
    void* m18;
    void hkFixedConstraintCinfo_Fix(void* arg);
};

// @fnv 0x00cc7fe0
// src: XBOX_PDB 0x00cc7fe0
void Cc7Owner::hkFixedConstraintCinfo_Fix(void* arg)
{
    v10();
    Cc7Local kit;
    kit.InitFromHelper(m04);
    char* base = m10;
    Cc7Tmp first, second;
    first.hkTransform_setMulInverseMul(m0c + 0xf0, arg);
    second.hkTransform_setMulInverseMul(base + 0xf0, arg);
    kit.ProcessAndReturnValue_00d52000(&first.translation);
    kit.UpdateState_00d51c30(&first);
    m14 = kit.ProcessAndReturnValue_00d520a0(&second.translation);
    m18 = kit.ProcessAndReturnValue_00d51d40(&second);
    kit.AddBridgeAtoms();
    kit.AppendEntryAndAdvance();
    kit.ProcessAndReturnValue_00d52ae0(g_011c5c70_arg1);
    kit.hkpConstraintConstructionKit_restoreStrength();
    kit.AppendZeroItem();
}

extern "C" void _ReadWriteBarrier();

struct TypeHeader
{
    unsigned int unk00, unk04, unk08, typeCode;
};
struct TypeAttributes
{
    unsigned int attributes;
};
struct ObjectType : TypeHeader, TypeAttributes
{
};
union __declspec(align(16)) Lane128Q
{
    float f32[4];
    unsigned __int64 u64[2];
    __int8 i8[16];
};
struct ScratchGeometry
{
    Lane128Q dimensions;
    float tolerance, radius, margin;
    unsigned char useA, useB, specialShape, useD, useE;
    void FUN_00d54de0();
};
struct LunaAction
{
    unsigned int id;
    ObjectType* source;
    void* result;
    float defaultValue;
    ScratchGeometry scratch;
};
struct LunaArgument
{
    int unk00, unk04;
    ObjectType* value;
    int unk0c;
};
struct LunaTarget
{
    unsigned int bhkMoppBvTreeShape_Init(LunaArgument* argument);
};
extern void* __cdecl hkpMoppUtility_buildCode(const void*, ScratchGeometry*, unsigned int);
// @fnv 0x00cca360
// src: XBOX_PDB 0x00cca360
unsigned int LunaTarget::bhkMoppBvTreeShape_Init(LunaArgument* argument)
{
    AutoMemContext scope(0x10);
    LunaAction action;
    action.id = 0;
    action.result = 0;
    action.defaultValue = 1.0f;
    _ReadWriteBarrier();
    action.source = argument->value;
    action.scratch.FUN_00d54de0();
    if (argument->value->typeCode == 14)
        action.scratch.specialShape = 1;
    const void* attrs = argument->value;
    if (attrs)
        attrs = &static_cast<const ObjectType*>(attrs)->attributes;
    else
        attrs = 0;
    void* result = hkpMoppUtility_buildCode(attrs, &action.scratch, 0);
    typedef void(__thiscall * ActionHandler)(LunaTarget*, LunaAction*);
    ActionHandler handler = reinterpret_cast<ActionHandler>((*reinterpret_cast<void***>(this))[44]);
    action.result = result;
    handler(this, &action);
    return scope.m_eMemoryContext;
}

union Quaternion525
{
    LocalM128 value;
    char bytes[16];  // the real xmmintrin __m128 also overlays __int8 m128_i8[16]
    Quaternion525()
    {}
    Quaternion525& operator=(const Quaternion525& other)
    {
        value = other.value;
        return *this;
    }
};
struct RotationSource525
{
    unsigned int unk00, unk04, unk08, unk0c;
    Quaternion525 rotation;
};
struct StringArray525 : NiTObjectArray<char*>
{
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char* const&);
    void append(char* const& value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_0096ad30(index + m_usGrowBy);
        FUN_0096ae90(index, value);
    }
};
class PositionText525
{
  public:
    float x, y, z;
    char* GetViewerString_00a59af0(const char*);
};
extern void* DAT_01268670;
extern const char DAT_0101c29c[];
extern const char DAT_010ca6a4[];
char* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);
void __cdecl FUN_00458620(PositionText525*, const Quaternion525*);
struct RotationOwner525
{
    unsigned int unk00, unk04;
    RotationSource525* source;
    void bhkHeightFieldShape_GetViewerStrings(StringArray525*);
    void bhkPlaneShape_GetViewerStrings(StringArray525*);
};
// @fnv 0x00ccb810
// src: XBOX_PDB 0x00ccb810
void RotationOwner525::bhkPlaneShape_GetViewerStrings(StringArray525* stream)
{
    AutoMemContext guard(16);
    bhkHeightFieldShape_GetViewerStrings(stream);
    char* value = NiViewerStrings_NiGetViewerString_Title(DAT_01268670);
    stream->append(value);
    // The SDK quaternion default constructor does not initialize its value.
    // The native owner/source-null branch similarly omits that assignment.
    Quaternion525 rotation;
    if (this && source)
        rotation = source->rotation;
    PositionText525 position;
    FUN_00458620(&position, &rotation);
    value = position.GetViewerString_00a59af0(DAT_0101c29c);
    stream->append(value);
    value = NiGetViewerString_00a7d550(DAT_010ca6a4, rotation.value.m128_f32[3]);
    stream->append(value);
}

struct TlsState
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
};

extern __declspec(thread) TlsState g_tlsState;

extern MemoryManager _g_memoryManager;

struct Holder;

struct CinfoVector
{
    hkVec4 value;
    __forceinline CinfoVector(LocalM128 vector)
    {
        value.m_vComponents = vector;
    }
};
extern "C" LocalM128 _mm_set_ps1(float);

struct CachedObj
{
    int unk00;
    int unk04;
    float unk08;
    int unk0c;
    LocalM128 unk10;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

struct Holder
{
    int unk00;
    int unk04;
    void* unk08;
    CachedObj* unk0c;
    int unk10;
    int unk14;
    void bhkExtendedMeshShape_CopyCinfo(void* p);
    CachedObj* bhkExtendedMeshShape_CreateCinfo(bool* created);
};

inline void* AllocAligned(unsigned int size)
{
    unsigned char* p = (unsigned char*)_g_memoryManager.Allocate(size);
    unsigned char pad = (unsigned char)(0x10 - ((unsigned int)p & 0xf));
    p += pad;
    p[-1] = pad;
    return p;
}

// @fnv 0x00ccbfa0
// src: XBOX_PDB 0x00ccbfa0
CachedObj* Holder::bhkExtendedMeshShape_CreateCinfo(bool* created)
{
    AutoMemContext ctx(0x10);
    bool bCreated = (unk0c == 0);
    *created = bCreated;
    if (bCreated)
    {
        CachedObj* o = (CachedObj*)AllocAligned(sizeof(CachedObj));
        float& fZero = o->unk08;
        o->unk00 = 0;
        o->unk04 = 0;
        fZero = 0.0f;
        o->unk10 = CinfoVector(_mm_set_ps1(1.0f)).value.m_vComponents;
        unk0c = o;
        if (unk08 != 0)
            bhkExtendedMeshShape_CopyCinfo(o);
    }
    return unk0c;
}

struct Mat
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
};
struct NodeTransform
{
    Mat rotation;
    NiPoint3 translation;
    float scale;
};
struct TLSData
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int context;
};
extern __declspec(thread) TLSData g_tlsBlock;
struct Context
{
    unsigned int previous;
    Context()
    {
        previous = g_tlsBlock.context;
        g_tlsBlock.context = 0x10;
    }
    ~Context()
    {
        g_tlsBlock.context = previous;
    }
};
struct ConvexShapeNode
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void attach(ConvexShapeNode*, int);
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
    Mat rotation;
    NiPoint3 position;
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
    ConvexShapeNode(unsigned short);
    static void* operator new(unsigned int);
    void SetParentObject(const struct Name&);
};
extern char* emptyString;
struct Name
{
    char* value;
    static char* InternString(const char*);
    Name(const char* s) : value(InternString(s))
    {}
    ~Name()
    {
        if (value != emptyString)
            InterlockedDecrement(reinterpret_cast<volatile long*>(value) - 2);
    }
};
struct Target
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void finish(ConvexShapeNode*, void*);
};
struct Owner
{
    int unk00, unk04;
    Target* target;
};
struct Body
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Owner* owner;
    int unk1c;
    __declspec(align(16)) Transform transform;
};
extern Transform identity;
extern const char nodeName[];
void HK2NI_00624b10(Mat*, Transform*);
void FUN_00458620(NiPoint3*, LocalM128*);
struct Subject
{
    int unk00, unk04;
    Body* body;
    void bhkConvexTransformShape_BuildDisplayGeometry(ConvexShapeNode*, void*);
};
// @fnv 0x00ccf150
// src: XBOX_PDB 0x00ccf150
void Subject::bhkConvexTransformShape_BuildDisplayGeometry(ConvexShapeNode* parent, void* arg)
{
    Context context;
    const Transform* src = this && body ? &body->transform : &identity;
    // Preserve the original transform buffer's /GS stack protection.
    __declspec(align(16)) char transformBuffer[sizeof(Transform)];
    Transform& transform = *reinterpret_cast<Transform*>(transformBuffer);
    transform.r[0] = src->r[0];
    transform.r[1] = src->r[1];
    transform.r[2] = src->r[2];
    transform.r[3] = src->r[3];
    NodeTransform converted;
    HK2NI_00624b10(&converted.rotation, &transform);
    FUN_00458620(&converted.translation, &transform.r[3]);
    ConvexShapeNode* __restrict node = new ConvexShapeNode(0);
    node->SetParentObject(Name("bhkConvexTransformShape"));
    parent->attach(node, 1);
    node->position = converted.translation;
    node->rotation = converted.rotation;
    if (this)
    {
        Body* b = body;
        if (b)
        {
            Owner* o = b->owner;
            if (o)
            {
                Target* t = o->target;
                if (t)
                    t->finish(node, arg);
            }
        }
    }
}

extern "C"
{
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_min_ps(LocalM128, LocalM128);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
}

extern float DAT_0104da48;
extern float DAT_0104e148;

struct BoundsVector : hkVector4
{
    __forceinline const LocalM128& Get() const
    {
        return m_vComponents;
    }
    __forceinline void SetAll(float value)
    {
        m_vComponents = _mm_set_ps1(value);
    }
    __forceinline void Min(const BoundsVector& a, const BoundsVector& b)
    {
        m_vComponents = _mm_min_ps(a.Get(), b.Get());
    }
    __forceinline void Max(const BoundsVector& a, const BoundsVector& b)
    {
        m_vComponents = _mm_max_ps(a.Get(), b.Get());
    }
};

struct BoundsEntry
{
    BoundsVector translation;
    BoundsVector rotation;
    BoundsVector scale;
};

struct BoundsBox
{
    BoundsVector m_kMinimumCorner;
    BoundsVector m_kMaximumCorner;
    __forceinline void Include(const BoundsVector& point)
    {
        m_kMinimumCorner.Min(m_kMinimumCorner, point);
        m_kMaximumCorner.Max(m_kMaximumCorner, point);
    }
};

class BoundsOwner
{
  public:
    SkeletonData* m_pSub;
    int unk04;
    int unk08;
    int unk0c;
    BoundsEntry* m_pEntries;
    void hkaPose_syncModelSpace();
    void ProcessEntries_00cda610(BoundsBox* out);
};

// @fnv 0x00cda610
// src: GUESS 0x00cda610 (confidence: low)
void BoundsOwner::ProcessEntries_00cda610(BoundsBox* out)
{
    out->m_kMinimumCorner.SetAll(DAT_0104da48);
    out->m_kMaximumCorner.SetAll(DAT_0104e148);
    int count = m_pSub->count;
    hkaPose_syncModelSpace();
    for (int i = 0; i < count; i++)
    {
        BoundsEntry* entry = &m_pEntries[i];
        out->Include(entry->translation);
    }
}

extern __declspec(thread) int DAT_tls_field;

namespace Memory306 {
extern "C" hkMemoryRouter* hkMemoryRouter_getInstance();
}
struct S00cc2530_Source306
{
    int a, b, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float m[16];
};
struct S00cc2530_FUN_00d4ce10
{
    virtual ~S00cc2530_FUN_00d4ce10();
    unsigned short memorySize;
    short references;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;

    S00cc2530_FUN_00d4ce10(int, const LocalM128*, int);
    void removeReference();
    static void* operator new(unsigned int n)
    {
        void* p = Memory306::hkMemoryRouter_getInstance()->heap().blockAlloc(n);
        static_cast<S00cc2530_FUN_00d4ce10*>(p)->memorySize = (unsigned short)n;
        return p;
    }
    static void operator delete(void* p)
    {
        Memory306::hkMemoryRouter_getInstance()->heap().blockFree(p, 0x170);
    }
};
__forceinline LocalM128* BuildTransform306(S00cc2530_Source306* src, LocalM128* t)
{
    t[0] = _mm_setr_ps(src->m[0], src->m[1], src->m[2], src->m[3]);
    t[1] = _mm_setr_ps(src->m[4], src->m[5], src->m[6], src->m[7]);
    t[2] = _mm_setr_ps(src->m[8], src->m[9], src->m[10], src->m[11]);
    t[3] = _mm_setr_ps(src->m[12], src->m[13], src->m[14], src->m[15]);
    return t;
}

struct S00cc2530_Owner306
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void Set(S00cc2530_FUN_00d4ce10*);
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void OnSource(S00cc2530_Source306*);
    void bhkCachingShapePhantom_Init(S00cc2530_Source306*);
};
// @fnv 0x00cc2530
// src: XBOX_PDB 0x00cc2530
void S00cc2530_Owner306::bhkCachingShapePhantom_Init(S00cc2530_Source306* src)
{
    AutoMemContext heap(0x10);
    union
    {
        LocalM128 m[4];
        char gs[64];
    } transformBuf;
    LocalM128* transform = transformBuf.m;
    S00cc2530_FUN_00d4ce10* object = new S00cc2530_FUN_00d4ce10(src->b, BuildTransform306(src, transform), src->a);
    Set(object);
    object->removeReference();
    OnSource(src);
}

struct SourceGeometry
{
    unsigned int type;
    unsigned int owner;
    unsigned int count;
    unsigned int options;
    LocalM128 dimensions;
    unsigned int material;
    volatile unsigned int flags;
    void FUN_00c905b0();
};

struct InitializePathingRequestFromPosition
{
    unsigned int id;
    ObjectType* type;
    SourceGeometry* cachedGeometry;
    float scale;
};

struct RefCountedObject
{
    void FUN_00c905b0();
};

namespace fnvc_adapt {
extern SourceGeometry* __cdecl hkpMoppUtility_buildCode(const void* attributes, ScratchGeometry* scratch, unsigned int options);
}
extern int DAT_0102e368;

struct Shape : RefCountedObject
{
    const void** volatile methods;
    unsigned short size;
    volatile unsigned short state;
    unsigned int unk08, unk0c;
    LocalM128 dimensions;
    unsigned int material;
    volatile unsigned int flags;
    unsigned int combinedFlags;
    unsigned char kind;
    static void* operator new(unsigned int bytes)
    {
        hkMemoryRouter* router = hkMemoryRouter_getInstance();
        Shape* result = static_cast<Shape*>(router->heap().blockAlloc(bytes));
        result->size = (unsigned short)bytes;
        return result;
    }
    Shape(const LocalM128& scaled, unsigned int materialValue, unsigned int shapeFlags)
    {
        methods = reinterpret_cast<const void**>(&DAT_0102e368);
        state = 1;
        dimensions = scaled;
        flags = shapeFlags;
        material = materialValue;
        combinedFlags = shapeFlags | 0x80000000u;
        kind = 2;
    }
};

struct FUN_00cc9d00 : RefCountedObject
{
    unsigned int unk00;
    unsigned short size;
    volatile unsigned short state;
    unsigned int unk08, unk0c;
    LocalM128 dimensions;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    FUN_00cc9d00(ObjectType* type, Shape* shape, SourceGeometry* geometry);
    static void* operator new(unsigned int bytes)
    {
        hkMemoryRouter* router = hkMemoryRouter_getInstance();
        FUN_00cc9d00* result = static_cast<FUN_00cc9d00*>(router->heap().blockAlloc(bytes));
        result->size = (unsigned short)bytes;
        return result;
    }
    static void operator delete(void* memory);
};

struct OutputHandler
{
    void bhkMoppBvTreeShape_Init_00cca6f0(InitializePathingRequestFromPosition* request);
};

typedef void(__thiscall* OutputMethod)(OutputHandler*, void*);
typedef void(__thiscall* RequestMethod)(OutputHandler*, InitializePathingRequestFromPosition*);

// @fnv 0x00cca6f0
// src: XBOX_PDB 0x00cca6f0
void OutputHandler::bhkMoppBvTreeShape_Init_00cca6f0(InitializePathingRequestFromPosition* request)
{
    AutoMemContext scope(0x10);

    SourceGeometry* temporary = 0;
    if (!request->cachedGeometry)
    {
        ScratchGeometry scratch;
        scratch.FUN_00d54de0();
        if (request->type->typeCode == 14)
            scratch.specialShape = 1;
        const void* attrs = request->type ? &request->type->attributes : 0;
        temporary = fnvc_adapt::hkpMoppUtility_buildCode(attrs, &scratch, 0);
    }
    SourceGeometry* geometry = request->cachedGeometry ? request->cachedGeometry : temporary;

    const float& scale = request->scale;
    float inverseScale = 1.0f / request->scale;
    LocalM128 scaled = _mm_mul_ps(_mm_setr_ps(scale, scale, scale, inverseScale), geometry->dimensions);

    Shape* shape = new Shape(scaled, geometry->material, geometry->flags);

    FUN_00cc9d00* result = new FUN_00cc9d00(request->type, shape, geometry);

    shape->FUN_00c905b0();
    if (temporary)
        temporary->FUN_00c905b0();

    reinterpret_cast<OutputMethod>((*reinterpret_cast<void***>(this))[0x8c / 4])(this, result);
    result->FUN_00c905b0();
    reinterpret_cast<RequestMethod>((*reinterpret_cast<void***>(this))[0xbc / 4])(this, request);
}

struct ThreadTlsBlock
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern volatile unsigned int DAT_0126fd98;

struct TlsFlagGuard
{
    ThreadTlsBlock* m_blk;
    unsigned int m_saved;
    TlsFlagGuard()
    {
        unsigned int index = DAT_0126fd98;
        m_blk = reinterpret_cast<ThreadTlsBlock**>(__readfsdword(0x2c))[index];
        m_saved = m_blk->m_2b4;
        m_blk->m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        m_blk->m_2b4 = m_saved;
    }
};

extern unsigned int DAT_01268694;

extern float DAT_010c72bc;

struct NameArr
{
    virtual ~NameArr();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int n);
    void FUN_0096ae90(unsigned int i, const unsigned int& v);
};

struct __declspec(align(16)) Blk
{
    int i0;
    float f4;
    float f8;
    float fc;
    float v0, v1, v2, v3;
    float w0, w1, w2, w3;
    float z0;
    float z1, z2;
};

struct TagObj
{
    float x, y, z;
    unsigned int GetViewerString_00a59af0(const char* s);
};

unsigned int __cdecl NiViewerStrings_NiGetViewerString_Title(unsigned int v);
namespace fnvc_adapt {
unsigned int __cdecl NiGetViewerString_00a7d550(const char* s, float f);
}
void __cdecl HK2NINS(TagObj* t, const LocalM128* v);

extern const char g_011d3e74_arg1[];
extern const char str_010ca918[];
extern const char str_010ca914[];

class NamedShape
{
  public:
    unsigned int unk00;
    void WriteLimitedHingeData(Blk* b);
    void bhkConvexShape_GetViewerStrings(NameArr* arr);
    void bhkCylinderShape_GetViewerStrings(NameArr* arr);
};

static void AddName(NameArr* arr, const unsigned int& v)
{
    unsigned int n = arr->m_usSize;
    if (n >= arr->m_usMaxSize)
    {
        arr->FUN_0096ad30(n + arr->m_usGrowBy);
    }
    arr->FUN_0096ae90(n, v);
}

// @fnv 0x00ccd960
// src: XBOX_PDB 0x00ccd960
void NamedShape::bhkCylinderShape_GetViewerStrings(NameArr* arr)
{
    TlsFlagGuard guard;
    bhkConvexShape_GetViewerStrings(arr);
    unsigned int item = NiViewerStrings_NiGetViewerString_Title(DAT_01268694);
    AddName(arr, item);

    TagObj t1;
    Blk b;
    b.i0 = 0;
    b.f4 = DAT_010c72bc;
    b.v0 = 0.0f;
    b.v1 = 0.0f;
    b.v2 = 0.0f;
    b.v3 = 0.0f;
    b.z0 = 0.0f;
    b.w0 = 1.0f;
    b.w1 = 0.0f;
    b.w2 = 0.0f;
    b.w3 = 0.0f;
    WriteLimitedHingeData(&b);
    item = fnvc_adapt::NiGetViewerString_00a7d550(g_011d3e74_arg1, b.z0);
    AddName(arr, item);

    hkVec4 v1;
    *reinterpret_cast<LocalM128*>(&v1) = _mm_setr_ps(b.v0, b.v1, b.v2, b.v3);
    HK2NINS(&t1, reinterpret_cast<const LocalM128*>(&v1));
    item = t1.GetViewerString_00a59af0(str_010ca918);
    AddName(arr, item);

    *reinterpret_cast<LocalM128*>(&v1) = _mm_setr_ps(b.w0, b.w1, b.w2, b.w3);
    HK2NINS(&t1, reinterpret_cast<const LocalM128*>(&v1));
    item = t1.GetViewerString_00a59af0(str_010ca914);
    AddName(arr, item);
}

extern "C" void _mm_store_ss(float*, LocalM128);

struct AlignedPairData
{
    hkVec4Q_blk_00cc0000_od_o2_nood_variant m_vContactPosition;
    hkVec4Q_blk_00cc0000_od_o2_nood_variant m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int m_type;
    int unk28;
    int unk2C;
    hkVec4Q_blk_00cc0000_od_o2_nood_variant unk30;
    hkVec4Q_blk_00cc0000_od_o2_nood_variant unk40;
    hkVec4Q_blk_00cc0000_od_o2_nood_variant unk50;
    hkVec4Q_blk_00cc0000_od_o2_nood_variant unk60;
};

template <int ELEMENTSIZE> __forceinline void memCpyOneAligned(void* dst, const void* src)
{
    int i = 0;
    do
    {
        static_cast<unsigned __int64*>(dst)[i] = static_cast<const unsigned __int64*>(src)[i];
    } while (++i < int(ELEMENTSIZE / 8));
}

struct ContactArray
{
    AlignedPairData* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline AlignedPairData& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpyOneAligned<sizeof(AlignedPairData)>(m_data + index, m_data + m_iElementCount);
    }
};

struct ContactManifold
{
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    int unk08;
    int unk0C;
    ContactArray m_kPoints;
    int unk1C;
    AlignedPairData m_kStorage[8];
    ContactManifold* m_other;

    void ProcessEntries_00cd3080();
};

// @fnv 0x00cd3080
// src: GUESS 0x00cd3080 (confidence: low)
void ContactManifold::ProcessEntries_00cd3080()
{
    AutoMemContext context(0x10);
    int sharedIndex;

    for (int i = m_kPoints.GetLogicalSize() - 1; i > 0; i--)
    {
        sharedIndex = i - 1;
        if (sharedIndex != 0)
            do
            {
                sharedIndex--;
                AlignedPairData& b = m_kPoints[i];
                AlignedPairData& a = m_kPoints[sharedIndex];
                if (a.m_type == 1 && b.m_type != 1)
                {
                    // Preserve the original byte-addressable storage and compiler stack allocation.
                    union { hkVec4Q_blk_00cc0000_od_o2_nood_variant vector; char bytes[sizeof(hkVec4Q_blk_00cc0000_od_o2_nood_variant)]; } diff;
                    diff.vector.setSub4(a.m_vContactPosition, b.m_vContactPosition);
                    float dist;
                    _mm_store_ss(&dist, diff.vector.dot3(a.m_vHitNormal));
                    if (dist > 0.0f)
                    {
                        m_kPoints.removeAt(i);
                        break;
                    }
                }
            } while (sharedIndex != 0);
    }

    if (m_other && m_other->m_kPoints.GetLogicalSize())
    {
        sharedIndex = m_other->m_kPoints.GetLogicalSize();
        while (sharedIndex--)
        {
            int j = m_kPoints.GetLogicalSize();
            while (j--)
            {
                AlignedPairData& b = m_kPoints[j];
                AlignedPairData& a = m_other->m_kPoints[sharedIndex];
                if (a.m_type == 1 && b.m_type != 1)
                {
                    // Preserve the original byte-addressable storage and compiler stack allocation.
                    union { hkVec4Q_blk_00cc0000_od_o2_nood_variant vector; char bytes[sizeof(hkVec4Q_blk_00cc0000_od_o2_nood_variant)]; } diff;
                    diff.vector.setSub4(a.m_vContactPosition, b.m_vContactPosition);
                    float dist;
                    _mm_store_ss(&dist, diff.vector.dot3(a.m_vHitNormal));
                    if (dist > 0.0f)
                    {
                        m_kPoints.removeAt(j);
                    }
                }
            }
        }
    }
}

extern "C" LocalM128 _mm_setzero_ps();

extern float DAT_011b153c;

union hkVecQ3E
{
    LocalM128 m_vComponents;
    char m_bytes[16];
    __forceinline hkVecQ3E()
    {}
    __forceinline hkVecQ3E(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct ShapeInfo_SI
{
    int unk00;
    float m_fBoundRadius;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3C;
};

__forceinline void* hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* p = (hkReferencedObject*)hkMemoryRouter_getInstance()->heap().blockAlloc(nbytes);
    p->m_usMemSizeAndFlags = (unsigned short)nbytes;
    return p;
}
template <typename ENUM, typename STORAGE>
__forceinline hkEnum<ENUM, STORAGE>::hkEnum(ENUM value) : m_kStorage(value) {}
template <typename ENUM, typename STORAGE>
__forceinline hkEnum<ENUM, STORAGE>::hkEnum() {}
__forceinline hkpShape::hkpShape(hkpShapeType type)
{
    m_ulUserData = 0;
    *(int*)&m_type = type;
}
__forceinline hkpConvexShape::hkpConvexShape(int type, float radius) : hkpShape((hkpShapeType)type)
{
    m_fSphereRadius = radius;
}

struct ShapeObj_SI : hkpConvexShape
{
    unsigned short unk14;
    unsigned char unk16;
    unsigned char unk17;
    hkVecQ3E m_v20;
    hkVecQ3E m_v30;
    hkVecQ3E m_v40;
    hkVecQ3E m_v50;

    __forceinline ShapeObj_SI(const hkVecQ3E& a, const hkVecQ3E& b, const hkVecQ3E& c, float fRadius = DAT_011b153c)
        : hkpConvexShape(3, fRadius)
    {
        m_v20.m_vComponents = a.m_vComponents;
        m_v30.m_vComponents = b.m_vComponents;
        m_v40.m_vComponents = c.m_vComponents;
        m_v50.m_vComponents = _mm_setzero_ps();
        unk14 = 0;
        unk17 = 0;
        unk16 = 6;
    }
    virtual ~ShapeObj_SI() throw();
    virtual void CalculateAabb(const hkTransform&, hkReal, hkAabb&) const;
    virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery&, ShapeRayCastOutput&) const;
    virtual void CastRayWithCollector(const ShapeRayCastQuery&, const hkpCdBody&, hkpRayHitCollector&) const;
    virtual void GetFirstVertex(hkVector4&) const;
    virtual void GetSupportVertex(const hkVector4&, Vector4WithInt24W&) const;
    virtual void GetVerticesFromIds(const hkpVertexId*, int, Vector4WithInt24W*) const;
};

struct ShapeOwner_SI
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void addObject(hkReferencedObject* pkObj);
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void finish(ShapeInfo_SI* pkInfo);
    void bhkTriangleShape_Init(ShapeInfo_SI* pkInfo);
};

// @fnv 0x00ccaee0
// src: XBOX_PDB 0x00ccaee0
void ShapeOwner_SI::bhkTriangleShape_Init(ShapeInfo_SI* pkInfo)
{
    const float& fRadius = pkInfo->m_fBoundRadius;
    AutoMemContext kGuard(0x10);
    ShapeObj_SI* pkObj = new ShapeObj_SI(hkVecQ3E(pkInfo->m_f10, pkInfo->m_f14, pkInfo->m_f18, pkInfo->m_f1C),
                                         hkVecQ3E(pkInfo->m_f20, pkInfo->m_f24, pkInfo->m_f28, pkInfo->m_f2C),
                                         hkVecQ3E(pkInfo->m_f30, pkInfo->m_f34, pkInfo->m_f38, pkInfo->m_f3C));
    pkObj->m_fSphereRadius = fRadius;
    addObject(pkObj);
    pkObj->removeReference();
    finish(pkInfo);
}

struct ParamSrc
{
    int unk00, unk04, unk08, unk0c;
    float m_10, m_14, m_18, m_1c;
    float m_20, m_24, m_28, m_2c;
    float m_30;
};
class CylinderInitOwner
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47(ParamSrc*);
    void __thiscall CreateAndDispatchObject(const LocalM128& lo, const LocalM128& hi, float f);
    void __thiscall bhkCylinderShape_Init(ParamSrc*);
};
// @fnv 0x00ccd8c0
// src: XBOX_PDB 0x00ccd8c0
void CylinderInitOwner::bhkCylinderShape_Init(ParamSrc* p)
{
    hkVec4 hi;
    hi.m_vComponents = _mm_setr_ps(p->m_20, p->m_24, p->m_28, p->m_2c);
    hkVec4 lo;
    lo.m_vComponents = _mm_setr_ps(p->m_10, p->m_14, p->m_18, p->m_1c);
    CreateAndDispatchObject(lo.m_vComponents, hi.m_vComponents, p->m_30);
    v47(p);
}

void* __cdecl FUN_00ec44d0(void*, const void*, unsigned);

void* __cdecl Object_DispatchCommandFour(unsigned);

void __cdecl FreeStorage(void*);

using ::MemoryManager;
using ::_g_memoryManager;

struct ExtendedMeshFloat
{
    float value;
    static void* operator new[](unsigned size)
    {
        return _g_memoryManager.Allocate(size);
    }
};
struct ExtendedMeshIndex
{
    unsigned short value;
    static void* operator new[](unsigned size)
    {
        return _g_memoryManager.Allocate(size);
    }
};

struct Triangle
{
    unsigned short a, b, c, unk06;
};

struct Region
{
    unsigned value;
    unsigned count;
    unsigned other;
};

struct Geometry
{

    unsigned unk00, unk04;

    unsigned short triangleCount, unk0A, unk0C, unk0E, regionCount, unk12;

    Triangle* triangles;

    NiPoint3* vertices;

    unsigned unk1C, unk20;

    Region* regions;

    __forceinline bool GetTriangle(unsigned short index, Triangle*& out)
    {

        out = &triangles[index];

        return index >= triangleCount;
    }
};

struct ExtendedMeshInput
{

    unsigned unk00;

    Geometry* geometry;

    float scale;

    unsigned unk0C;

    LocalM128 transform;
};

struct MeshPart
{
    static void* operator new[](unsigned size)
    {
        return _g_memoryManager.Allocate(size);
    }

    unsigned vertexCount;

    NiPoint3* vertices;

    unsigned triangleCount;

    unsigned short* indices;

    hkAabb* bounds;

    MeshPart();

    ~MeshPart();
};

struct FUN_00a5d3a0
{

    FUN_00a5d3a0();

    virtual ~FUN_00a5d3a0();

    unsigned references;
};

struct Mesh : FUN_00a5d3a0
{

    unsigned count;

    MeshPart* parts;

    static void* operator new(unsigned n)
    {
        return Object_DispatchCommandFour(n);
    }

    Mesh() : count(0), parts(0)
    {}

    virtual ~Mesh();
};

extern void* indexVtable[];

struct IndexArray
{

    void** vtable;

    ~IndexArray()
    {
        FreeStorage(data);
    }

    unsigned short* data;

    unsigned short capacity, size, used, grow;

    IndexArray()
    {
        capacity = 0;
        grow = 1;
        size = 0;
        used = 0;
        data = 0;
        vtable = indexVtable;
    }

    void Resize(unsigned);

    __forceinline void Append(unsigned short value)
    {
        SetAt(size, value);
    }

    __forceinline void SetAt(unsigned index, unsigned short value)
    {

        if (index >= capacity)
            Resize(index + grow);

        if (index >= size)
        {

            size = index + 1;

            if (value)
                ++used;
        }
        else if (value)
        {

            if (!data[index])
                ++used;
        }
        else
        {

            if (data[index])
                --used;
        }

        data[index] = value;
    }

    void Clear()
    {

        unsigned short* values = data;

        unsigned short count = size;

        for (unsigned short index = 0; index < count; ++index)
            values[index] = 0;

        size = 0;
        used = 0;
    }
};

struct __declspec(align(16)) ExtendedMeshStoredVector
{
    hkVec4 lanes;
    __forceinline ExtendedMeshStoredVector& operator=(LocalM128 v)
    {
        _mm_store_ps(reinterpret_cast<float*>(&lanes.m_bytes[0]), v);
        return *this;
    }
    __forceinline operator const LocalM128&() const
    {
        return *reinterpret_cast<const LocalM128*>(&lanes.m_bytes[0]);
    }
};
struct Result
{

    Mesh* mesh;

    unsigned unk04;

    float scale;

    unsigned unk0C;

    ExtendedMeshStoredVector transform;

    Result(Mesh*);

    ~Result();
};

struct ExtendedMeshBuilder
{

    virtual void Slot00();

    virtual void Slot04();

    virtual void Slot08();

    virtual void Slot0C();

    virtual void Slot10();

    virtual void Slot14();

    virtual void Slot18();

    virtual void Slot1C();

    virtual void Slot20();

    virtual void Slot24();

    virtual void Slot28();

    virtual void Slot2C();

    virtual void Slot30();

    virtual void Slot34();

    virtual void Slot38();

    virtual void Slot3C();

    virtual void Slot40();

    virtual void Slot44();

    virtual void Slot48();

    virtual void Slot4C();

    virtual void Slot50();

    virtual void Slot54();

    virtual void Slot58();

    virtual void Slot5C();

    virtual void Slot60();

    virtual void Slot64();

    virtual void Slot68();

    virtual void Slot6C();

    virtual void Slot70();

    virtual void Slot74();

    virtual void Slot78();

    virtual void Slot7C();

    virtual void Slot80();

    virtual void Slot84();

    virtual void Slot88();

    virtual void Slot8C();

    virtual void Slot90();

    virtual void Slot94();

    virtual void Slot98();

    virtual void Slot9C();

    virtual void SlotA0();

    virtual void SlotA4();

    virtual void SlotA8();

    virtual void SlotAC();

    virtual void Apply(Result*);

    void bhkExtendedMeshShape_Init_00ccc980(ExtendedMeshInput*);
};

// @fnv 0x00ccc980
// src: XBOX_PDB 0x00ccc980
void ExtendedMeshBuilder::bhkExtendedMeshShape_Init_00ccc980(ExtendedMeshInput* input)
{

    AutoMemContext context(16);

    Geometry* geometry = input->geometry;

    unsigned short baseVertex = 0;

    unsigned short triangleIndex = 0;

    Mesh* mesh = new Mesh;

    MeshPart* parts = new MeshPart[geometry->regionCount];

    mesh->parts = parts;

    mesh->count = geometry->regionCount;

    IndexArray indices;

    for (int regionIndex = 0; regionIndex < geometry->regionCount; ++regionIndex)
    {

        unsigned triangleCount = 0;

        Region* region = &geometry->regions[regionIndex];

        bool done = false;

        while (!done)
        {

            Triangle* triangle;

            done = geometry->GetTriangle((unsigned short)triangleIndex, triangle);

            if (done)
                break;

            if (triangle->a >= (unsigned short)baseVertex + region->count)
                break;

            unsigned short a = triangle->a, b = triangle->b, c = triangle->c;

            indices.Append((unsigned short)(a - baseVertex));

            indices.Append((unsigned short)(b - baseVertex));

            indices.Append((unsigned short)(c - baseVertex));

            ++triangleIndex;

            ++triangleCount;
        }

        unsigned short vertexCount = 0;

        if (0 < triangleCount)
        {

            vertexCount = (unsigned short)region->count;

            NiPoint3* vertices;

            vertices = (NiPoint3*)new ExtendedMeshFloat[3 * (vertexCount + 1)];

            for (unsigned short vertex = (unsigned short)baseVertex;

                 vertex < (unsigned short)baseVertex + vertexCount; ++vertex)
            {

                vertices[vertex - (unsigned short)baseVertex].x = geometry->vertices[vertex].x;

                vertices[vertex - (unsigned short)baseVertex].y = geometry->vertices[vertex].y;

                vertices[vertex - (unsigned short)baseVertex].z = geometry->vertices[vertex].z;
            }

            unsigned short* copiedIndices = (unsigned short*)new ExtendedMeshIndex[indices.size];

            unsigned byteCount = 2 * indices.size;

            FUN_00ec44d0(copiedIndices, indices.data, byteCount);

            void* allocation = _g_memoryManager.Allocate(24);

            unsigned char adj = (unsigned char)(16 - ((unsigned)allocation & 15));

            unsigned adjustment = (unsigned char)adj;

            ((unsigned char*)allocation)[adjustment - 1] = adj;

            unsigned char* aligned = (unsigned char*)allocation + adjustment;

            hkAabb* bounds = (hkAabb*)aligned;

            bounds->Init(geometry->regions[regionIndex].value, geometry->regions[regionIndex].other);

            MeshPart& part = parts[regionIndex];

            part.bounds = bounds;

            part.vertexCount = vertexCount;

            part.vertices = vertices;

            part.indices = copiedIndices;

            part.triangleCount = triangleCount;
        }
        else
        {

            --mesh->count;
        }

        indices.Clear();

        baseVertex += vertexCount;
    }

    Result result(mesh);

    result.scale = input->scale;

    result.transform = input->transform;

    Apply(&result);
}

void* __cdecl NiMalloc(unsigned);

__declspec(noinline) void IndexArray::Resize(unsigned requested)
{

    if (requested == capacity)
        return;

    if (requested < size)
    {

        for (unsigned short i = (unsigned short)requested; i < size; ++i)
        {

            if (data[i])
            {
                data[i] = 0;
                --used;
            }
        }

        size = (unsigned short)requested;
    }

    unsigned short* old = data;

    capacity = (unsigned short)requested;

    if (requested > 0)
    {

        data = (unsigned short*)NiMalloc((unsigned short)requested * 2);

        for (unsigned short i = 0; i < size; ++i)
            data[i] = old[i];

        for (unsigned short i = size; i < capacity; ++i)
            data[i] = 0;
    }
    else
        data = 0;

    FreeStorage(old);
}

struct FUN_00ccea00Block
{
    LocalM128 m_v0;
    LocalM128 m_v1;
    LocalM128 m_v2;
    LocalM128 m_v3;
};

struct FUN_00ccea00Inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    FUN_00ccea00Block m_20;
};

struct FUN_00ccea00Out
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00ccea00Block m_10;
};

extern FUN_00ccea00Block DAT_01268370;

struct FUN_00ccea00Holder
{
    int unk00;
    int unk04;
    FUN_00ccea00Inner* m_08;

    void bhkConvexShape_CopyCinfo(FUN_00ccea00Out* out);
    void bhkConvexTransformShape_CopyCinfo(FUN_00ccea00Out* out);
};

// @fnv 0x00ccea00
// src: XBOX_PDB 0x00ccea00
void FUN_00ccea00Holder::bhkConvexTransformShape_CopyCinfo(FUN_00ccea00Out* out)
{
    this->bhkConvexShape_CopyCinfo(out);

    out->unk08 = (this != 0 && m_08 != 0) ? m_08->unk18 : 0;

    FUN_00ccea00Block* src;
    if (this == 0)
    {
        src = &DAT_01268370;
    }
    else
    {
        FUN_00ccea00Inner* inner = m_08;
        src = (FUN_00ccea00Block*)((char*)inner + 0x20);
        if (inner == 0)
            src = &DAT_01268370;
    }

    out->m_10.m_v0 = src->m_v0;
    out->m_10.m_v1 = src->m_v1;
    out->m_10.m_v2 = src->m_v2;
    out->m_10.m_v3 = src->m_v3;
}

namespace ScalarC97 {
extern "C" ::LocalM128 _mm_load_ss(const float*);
}

class ShapeC97 : public ::hkReferencedObject
{
  public:
    ShapeC97();

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ::hkVector4 m_v20;
    ::hkVector4 m_v30;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
};

struct ShapeCinfoC97
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_vScale;
};

// src: COMMUNITY 0x00cc96b0
__declspec(noinline) void __cdecl hkBallAndSocketConstraintCinfo_ApplyScale(float scale, ShapeC97* shape)
{
    if (shape && scale != 1.0f)
    {
        ::LocalM128 s = (ScalarC97::_mm_load_ss)(&scale);
        shape->m_v20.m_vComponents = (::_mm_mul_ps)((::_mm_shuffle_ps)(s, s, 0), shape->m_v20.m_vComponents);
        shape->m_v30.m_vComponents = (::_mm_mul_ps)((::_mm_shuffle_ps)(s, s, 0), shape->m_v30.m_vComponents);
    }
}

class ShapeClonerC97
{
  public:
    ShapeC97* ReleaseObject(ShapeC97* shape, ShapeCinfoC97* cinfo);
    ShapeC97* hkBallAndSocketConstraintCinfo_CloneData(ShapeC97* dst, ShapeCinfoC97* cinfo);

    int unk00;
    ShapeC97* m_pCollisionShape;
};

// @fnv 0x00cc9790
// src: XBOX_PDB 0x00cc9790
ShapeC97* ShapeClonerC97::hkBallAndSocketConstraintCinfo_CloneData(ShapeC97* dst, ShapeCinfoC97* cinfo)
{
    ::AutoMemContext kContext(0x10);
    ShapeC97* src = m_pCollisionShape;
    if (!dst)
    {
        dst = new ShapeC97;
    }
    dst->m_v20 = src->m_v20;
    dst->m_v30 = src->m_v30;
    float scale = cinfo->m_vScale;
    if (scale != 1.0f)
    {
        hkBallAndSocketConstraintCinfo_ApplyScale(scale, dst);
    }
    return ReleaseObject(dst, cinfo);
}

struct Ccb5d0Vector
{
    ::hkVec4 m_uiFilterValue;
    Ccb5d0Vector(float x, float y, float z, float w)
    {
        m_uiFilterValue.m_vComponents = (::_mm_setr_ps)(x, y, z, w);
    }
};

class FUN_00d55240_cls : public ::hkReferencedObject
{
  public:
    FUN_00d55240_cls(const Ccb5d0Vector& a, const Ccb5d0Vector& b, const Ccb5d0Vector& c);

    static void operator delete(void* p, unsigned int nbytes)
    {
        ::fnv_00cc6830::FUN_00c8b4f0(p, nbytes);
    }

    int unk08;
    int unk0C;
    ::hkVector4 m_v10;
    ::hkVector4 m_v20;
    ::hkVector4 m_v30;
};

struct Ccb5d0Source
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_f10, m_f14, m_f18, m_f1C;
    float m_f20, m_f24, m_f28, m_f2C;
    float m_f30, m_f34, m_f38, m_f3C;
};

class Ccb5d0Self
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void addShape(FUN_00d55240_cls* shape);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void finish(const Ccb5d0Source* source);

    void bhkPlaneShape_Init(const Ccb5d0Source* source);
};

// @fnv 0x00ccb5d0
// src: XBOX_PDB 0x00ccb5d0
void Ccb5d0Self::bhkPlaneShape_Init(const Ccb5d0Source* source)
{
    ::AutoMemContext guard(16);
    FUN_00d55240_cls* shape =
        new FUN_00d55240_cls(Ccb5d0Vector(source->m_f10, source->m_f14, source->m_f18, source->m_f1C),
                             Ccb5d0Vector(source->m_f30, source->m_f34, source->m_f38, source->m_f3C),
                             Ccb5d0Vector(source->m_f20, source->m_f24, source->m_f28, source->m_f2C));
    addShape(shape);
    shape->removeReference();
    finish(source);
}

struct MeshInitRefObject
{
    virtual void v00();
    virtual void destroy();
    long m_iObjectReferenceCount;
};

struct MeshInitEntry
{
    unsigned int m_channel;
    unsigned int m_uiEdgeIndex;
    unsigned int m_uiFilterValue;
    unsigned int m_resource;
    unsigned int m_ulUserData;
};

struct MeshInitEntryList : MeshInitRefObject
{
    unsigned int m_iElementCount;
    MeshInitEntry* m_entries;
};

struct MeshInitInput
{
    int unk00;
    MeshInitEntryList* m_kNode;
    float m_uiFilterValue;
    int unk0C;
    ::hkVec4 m_vector;
};

struct MeshInitElement
{
    unsigned char m_flags;
    unsigned char m_enabled;
    unsigned short m_eVertexFormat;
    unsigned int m_data;
    unsigned short m_uiItemCount;
    unsigned short m_iElementIndex;
    unsigned int m_ulUserData;
    unsigned int unk10;
    unsigned int m_uiFilterValue;
    unsigned int m_uiEdgeIndex;
    unsigned int m_iValueAfterFlags;
    unsigned int m_channel;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    ::hkVec4 m_vector;
    unsigned int m_resource;
    unsigned int m_kind;
    unsigned char m_type;
    unsigned char m_uiContentCount;
    unsigned short unk4A;
    unsigned int unk4C;
    unsigned int unk50;

    MeshInitElement()
    {
        m_uiItemCount = 0;
        m_eVertexFormat = 0;
        m_enabled = 1;
        m_ulUserData = 0;
        m_flags = 0;
        m_data = 0;
        unk10 = 0;
        m_vector.m_vComponents = (::_mm_setzero_ps)();
        unk50 = 0;
        m_uiContentCount = 0;
        m_iValueAfterFlags = 12;
        m_iElementIndex = 1;
    }
};

struct FUN_00d569c0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void addElement(MeshInitElement* pkElement);

    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        FUN_00d569c0* p = (FUN_00d569c0*)(::hkMemoryRouter_getInstance)()->heap().blockAlloc(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);

    FUN_00d569c0(float fRadius, int iCount);
    void hkpExtendedMeshShape_setScaling(const ::hkVec4* pkVector);
    void FUN_00c905b0();

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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int m_flags;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    float m_uiFilterValue;
    int unkE8;
    int unkEC;
};

struct MeshInitOwner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void attach(FUN_00d569c0* pkShape);
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void update(MeshInitInput* pkInput);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    MeshInitEntryList* m_kNode;

    void bhkExtendedMeshShape_Init(MeshInitInput* pkInput);
};

// @fnv 0x00ccc080
// src: XBOX_PDB 0x00ccc080
void MeshInitOwner::bhkExtendedMeshShape_Init(MeshInitInput* pkInput)
{
    ::AutoMemContext kGuard(0x10);
    FUN_00d569c0* pkShape = new FUN_00d569c0(DAT_011b153c, 12);
    pkShape->m_flags = 15;
    pkShape->m_uiFilterValue = pkInput->m_uiFilterValue;
    pkShape->hkpExtendedMeshShape_setScaling(&pkInput->m_vector);
    MeshInitEntryList* pkList = pkInput->m_kNode;
    for (unsigned int i = 0; i < pkList->m_iElementCount; i++)
    {
        const MeshInitEntry& kEntry = pkList->m_entries[i];
        MeshInitElement kElement;
        kElement.m_uiEdgeIndex = kEntry.m_uiEdgeIndex;
        kElement.m_channel = kEntry.m_channel;
        kElement.m_uiFilterValue = kEntry.m_uiFilterValue;
        kElement.m_type = 2;
        kElement.m_kind = 6;
        kElement.m_resource = kEntry.m_resource;
        kElement.m_iElementIndex = 1;
        kElement.m_ulUserData = kEntry.m_ulUserData;
        kElement.m_eVertexFormat = 8;
        kElement.m_uiItemCount = 1;
        kElement.m_enabled = 1;
        pkShape->addElement(&kElement);
    }
    MeshInitEntryList* pkOld = m_kNode;
    if (pkOld != pkInput->m_kNode)
    {
        if (pkOld && InterlockedDecrement(&pkOld->m_iObjectReferenceCount) == 0)
            pkOld->destroy();
        m_kNode = pkInput->m_kNode;
        if (m_kNode)
            InterlockedIncrement(&m_kNode->m_iObjectReferenceCount);
    }
    attach(pkShape);
    pkShape->FUN_00c905b0();
    update(pkInput);
}

extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);

class FNVSoftContactSource
{
  public:
    virtual void vtbl00(void);
    virtual void vtbl04(void);
    virtual void vtbl08(void);
    virtual void vtbl0C(void);
    virtual void vtbl10(void);
    virtual void vtbl14(void);
    virtual void vtbl18(void);
    virtual void vtbl1C(void);
    virtual void vtbl20(void);
    virtual void vtbl24(void);
    virtual void vtbl28(void);
    virtual void vtbl2C(void);
    virtual void vtbl30(void);
    virtual void vtbl34(void);
    virtual void vtbl38(void);
    virtual void vtbl3C(void);
    virtual void* vtbl40(void);
};

class FNVSoftContactTarget
{
  public:
    virtual void vtbl00(void);
    virtual void vtbl04(void);
    virtual void vtbl08(void);
    virtual void vtbl0C(void);
    virtual void vtbl10(void);
    virtual void vtbl14(void);
    virtual void vtbl18(void);
};

struct FNVOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_i14;
};

struct FNVEffectRec
{
    unsigned short m_sType;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned short m_sSize;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    LocalM128 m_v20;
    LocalM128 m_v30;
};

void* __cdecl FindModifierConstraintAtom(void* p, int type);
void __cdecl hkpWorldConstraintUtil_addModifier(void* p, FNVSoftContactTarget* target, FNVEffectRec* rec);

// @fnv 0x00cdf850
// src: COMMUNITY 0x00cdf850
void __cdecl hkpResponseModifier_setInvMassScalingForContact_0(FNVSoftContactSource* a1, int a2, int a3, FNVSoftContactTarget* a4, LocalM128* a5, LocalM128* a6)
{
    volatile DWORD tick;
    void* p = a1->vtbl40();
    if (p == 0)
    {
        return;
    }
    a4->vtbl18();

    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "TtSetMassChang";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }

    FNVEffectRec* rec = (FNVEffectRec*)FindModifierConstraintAtom(p, 0x18);
    if (rec == 0)
    {
        hkMemoryRouter* holder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        hkMemoryAllocator* alloc = holder->m_heap;
        FNVEffectRec* fresh = (FNVEffectRec*)alloc->blockAlloc(0x40);
        if (fresh != 0)
        {
            fresh->m_sType = 0x18;
            fresh->m_sSize = 0x40;
            rec = fresh;
        }
        else
        {
            rec = 0;
        }
        hkpWorldConstraintUtil_addModifier(p, a4, rec);
    }

    if (a2 == ((FNVOwner*)p)->m_i14)
    {
        rec->m_v20 = *a5;
        rec->m_v30 = *a6;
    }
    else
    {
        rec->m_v20 = *a6;
        rec->m_v30 = *a5;
    }

    pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "Et";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }
}

extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);

void* __cdecl FindModifierConstraintAtom(void* p, int type);
void __cdecl hkpWorldConstraintUtil_addModifier(void* p, FNVSoftContactTarget* target, FNVEffectRec* rec);

// @fnv 0x00cdfac0
// src: COMMUNITY 0x00cdfac0
void __cdecl hkpResponseModifier_setCenterOfMassDisplacementForContact(FNVSoftContactSource* a1, int a2, int a3, FNVSoftContactTarget* a4, LocalM128* a5, LocalM128* a6)
{
    volatile DWORD tick;
    void* p = a1->vtbl40();
    if (p == 0)
    {
        return;
    }
    a4->vtbl18();

    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "TtSetMassChang";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }

    FNVEffectRec* rec = (FNVEffectRec*)FindModifierConstraintAtom(p, 0x1c);
    if (rec == 0)
    {
        hkMemoryRouter* holder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        hkMemoryAllocator* alloc = holder->m_heap;
        FNVEffectRec* fresh = (FNVEffectRec*)alloc->blockAlloc(0x40);
        if (fresh != 0)
        {
            fresh->m_sType = 0x1c;
            fresh->m_sSize = 0x40;
            rec = fresh;
        }
        else
        {
            rec = 0;
        }
        hkpWorldConstraintUtil_addModifier(p, a4, rec);
    }

    if (a2 == ((FNVOwner*)p)->m_i14)
    {
        rec->m_v20 = *a5;
        rec->m_v30 = *a6;
    }
    else
    {
        rec->m_v20 = *a6;
        rec->m_v30 = *a5;
    }

    pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "Et";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }
}

extern float DAT_01011d78;

struct HavokObjectCC3
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkVector4 m_v20;
    hkVector4 m_v30;
    float m_f40;
    float m_f44;
};

struct VectorListCC3
{
    void SetQuaternionComponentsFromVector(const hkVector4& v);
};

struct PropertiesCC3
{
    int unk00, unk04, unk08, unk0C;
    VectorListCC3 m_kVectors;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    float m_f30;
    float m_f34;
};

class WorldObjectCC3
{
  public:
    HavokObjectCC3* GetObject() const
    {
        return m_pPointer;
    }
    float GetF40() const
    {
        if (this && m_pPointer)
            return m_pPointer->m_f40;
        return 0.0f;
    }
    float GetF44() const
    {
        if (this && m_pPointer)
            return m_pPointer->m_f44;
        return 0.0f;
    }
    void WriteScriptTargetInfo(PropertiesCC3* pkOut);
    void bhkDashpotAction_CopyCinfo(PropertiesCC3* pkOut);

    void* m_ppVirtualMethodTable;
    int m_unk04;
    HavokObjectCC3* m_pPointer;
};

// @fnv 0x00cc3a50
// src: XBOX_PDB 0x00cc3a50
void WorldObjectCC3::bhkDashpotAction_CopyCinfo(PropertiesCC3* pkOut)
{
    WriteScriptTargetInfo(pkOut);
    // The original vector wrapper contains a byte buffer, so retain its /GS protection.
    __declspec(align(16)) char vectorStorage[2 * sizeof(hkVector4)];
    hkVector4& v0 = *(hkVector4*)&vectorStorage[0];
    v0.set(DAT_01011d78, DAT_01011d78, DAT_01011d78, DAT_01011d78);
    hkVector4& v1 = *(hkVector4*)&vectorStorage[sizeof(hkVector4)];
    v1.set(DAT_01011d78, DAT_01011d78, DAT_01011d78, DAT_01011d78);
    if (this)
    {
        HavokObjectCC3* pkObject = m_pPointer;
        if (pkObject)
        {
            v0 = pkObject->m_v20;
            v1 = pkObject->m_v30;
        }
    }
    pkOut->m_kVectors.SetQuaternionComponentsFromVector(v0);
    pkOut->m_kVectors.SetQuaternionComponentsFromVector(v1);
    pkOut->m_f30 = GetF40();
    pkOut->m_f34 = GetF44();
}

extern float DAT_010c72bc;
extern const char DAT_010c4048[];

struct __declspec(align(16)) ShapeCinfo
{
    int m_iType;
    float m_fConvexRadius;
    int unk08;
    int unk0C;
    float m_fA0;
    float m_fA1;
    float m_fA2;
    float m_fA3;
    float m_fB0;
    float m_fB1;
    float m_fB2;
    float m_fB3;
    float m_fBoundRadius;
    int unk34;
    int unk38;
    int unk3C;

    ShapeCinfo()
    {
        m_iType = 0;
        m_fConvexRadius = DAT_010c72bc;
        m_fA0 = 0.0f;
        m_fA1 = 0.0f;
        m_fA2 = 0.0f;
        m_fA3 = 0.0f;
        m_fBoundRadius = 0.0f;
        m_fB0 = 1.0f;
        m_fB1 = 0.0f;
        m_fB2 = 0.0f;
        m_fB3 = 0.0f;
    }
};

struct FUN_00d58510
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pkResult;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;

    static void* operator new(unsigned int nbytes)
    {
        FUN_00d58510* p = (FUN_00d58510*)::hkMemoryRouter_getInstance()->heap().blockAlloc(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);

    FUN_00d58510(const ::ShapeVector& kA, const ::ShapeVector& kB, float fRadius, int iA, int iB);
};

struct CylinderDisplayOwner
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55(void* pkA, void* pkResult, void* pkB, const char* pcName);

    void WriteLimitedHingeData(ShapeCinfo* pkInfo);
    void bhkCylinderShape_BuildDisplayGeometry(void* pkA, void* pkB);
};

// @fnv 0x00ccd6f0
// src: XBOX_PDB 0x00ccd6f0
void CylinderDisplayOwner::bhkCylinderShape_BuildDisplayGeometry(void* pkA, void* pkB)
{
    ::AutoMemContext guard(16);
    ShapeCinfo info;
    WriteLimitedHingeData(&info);
    FUN_00d58510* pkObj =
        new FUN_00d58510(::ShapeVector(info.m_fA0, info.m_fA1, info.m_fA2, info.m_fA3),
                         ::ShapeVector(info.m_fB0, info.m_fB1, info.m_fB2, info.m_fB3), info.m_fBoundRadius, 9, 1);
    pkObj->vf04();
    void* pkResult = pkObj->m_pkResult;
    if (pkResult)
    {
        vf55(pkA, pkResult, pkB, DAT_010c4048);
    }
}
