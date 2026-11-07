#include <xmmintrin.h>
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkQuaternion.h"
#include "../../../../../include/hkQsTransform.h"

extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;

__forceinline hkSimdReal::hkSimdReal() {}
__forceinline hkQuaternion::hkQuaternion() {}
__forceinline hkQuaternion::hkQuaternion(const hkQuaternion& q)
{
    copyRotation(q);
}
__forceinline hkQsTransform::hkQsTransform() {}
__forceinline const hkVector4& hkQuaternion::getImag() const
{
    return reinterpret_cast<const hkVector4&>(*this);
}
__forceinline void hkQuaternion::operator=(const hkQuaternion& q)
{
    reinterpret_cast<__m128&>(*this) = reinterpret_cast<const __m128&>(q);
}
__forceinline void hkQsTransform::operator=(const hkQsTransform& t)
{
    m_vTranslation = t.m_vTranslation;
    m_rotation = t.m_rotation;
    m_vScale = t.m_vScale;
}
__forceinline void hkVector4::addMul4(__m128 s, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
}
__forceinline void hkVector4::setNeg4(const hkVector4& a)
{
    m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
}
__forceinline void hkQuaternion::SetConjugate(const hkQuaternion& q)
{
    reinterpret_cast<__m128&>(*this) = _mm_xor_ps(DAT_010c4c00, reinterpret_cast<const __m128&>(q));
}

// src/havok/animation/animation/rig/hkaskeletonutils_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/rig/hkaskeletonutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/animation/rig/hkaskeletonutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/rig/hkaskeletonutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00cdd3f0_s
{
    int a[6];
    int* field_0x18;
    int field_0x1c;
};
void hkaSkeletonUtils_unlockTranslations(struct FUN_00cdd3f0_s* p);
extern "C" void __cdecl hkaSkeletonUtils_transformLocalPoseToWorldPose(int, int, int*, int, int);
extern int DAT_01268700;
void __cdecl CallWithGlobal(int a, int b, int c, int d);
extern "C" void __cdecl Object_ToLocal_Thunk(void* a, void* b, void* c, void* d, void* e);
extern int DAT_01268700;
void hkaSkeletonUtils_transformModelPoseToLocalPose(void* a, void* b, void* c, void* d);
extern "C" void __cdecl Atan2(float, float);
void __cdecl Hkaskeletonutils_ForwardCall_00ce00f0(float a, float b);
int __cdecl CompareStringsCaseInsensitive(const void* pKey, const void* pItem);
struct S_00cdd390_Entry
{
    unsigned int m_uiTaggedItem;
    int unk04;
};
struct S_00cdd390_Table
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    S_00cdd390_Entry* m_pEntries;
    int m_iArrayLength;
    int GetCount() const
    {
        return m_iArrayLength;
    }
    void* GetAt(int i) const
    {
        return (void*)(m_pEntries[i].m_uiTaggedItem & ~1u);
    }
};
short __cdecl FindIndexByKey(S_00cdd390_Table* pSearchEntries, const void* pKey,
                             int(__cdecl* pfnCompare)(const void*, const void*));
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
template <class T> struct Array
{
    T* data;
    int size;
    int capacity;
    __forceinline T& operator[](int index)
    {
        return data[index];
    }
};
struct Hierarchy
{
    int unk00;
    int unk04;
    int unk08;
    Array<short> parents;
    void* nodes;
    int count;
};
void __cdecl MarkHierarchyDescendants(Hierarchy* hierarchy, int root, unsigned char* flags, unsigned char finalValue);
struct Sequence
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    short* values;
    int count;
};
bool* __cdecl AreSequenceValuesInRange(bool* result, FUN_00cdd3f0_s* limits, Sequence* sequence);
struct Msg
{
    int f0, f4, f8;
    void Init(void* buf, int size);
    void Done();
    Msg& Add(const char* s);
    Msg& Add(const char* s, int v);
    Msg& Add();
    Msg& Fin();
};
struct Logger
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Report(int a, int code, void* msg, const char* file, int line);
};
extern Logger* DAT_01268360;
struct Names
{
    int pad[6];
    unsigned int* names;
    int count;
};
struct Track
{
    int pad[4];
    short* out;
    int cnt;
};
struct Src
{
    int pad[4];
    int n;
    int p14;
    int p18;
    unsigned int* arr;
    int f20;
};
struct Dst
{
    int pad[4];
    short* out;
    int cnt;
};
typedef int(__cdecl* CmpFn)(unsigned int, unsigned int);
int __cdecl MapTracksToBones(Names* names, Src* src, CmpFn cmp, Dst* dst);
struct HolderRec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_10;
};
struct ScanRec
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short* m_0c;
};
struct ScanObj
{
    void ForwardCall_00cde940(int a, int b, void* c);
};
HolderRec* hkMemoryRouter_getInstance();
unsigned char* WalkChainUntilLimit(unsigned char* pOut, ScanRec* rec, short limit, short start, ScanObj* obj);

// ---------------------------------------------------------------------------
// FUN_00cdd480 - batch interpolation of 0x30 byte records.
//
//   arg1  number of records to process (compared unsigned)
//   arg2  first  record array   (0x30 byte stride)
//   arg3  second record array   (0x30 byte stride)
//   arg4  array of blend factors (float, one per record)
//   arg5  output record array   (0x30 byte stride)
//
// For every record the blend factor is put into a 16 byte, 16 byte aligned
// vector whose first component carries the factor; that vector is handed to
// FUN_00cde740, which broadcasts its first component and interpolates the
// three 4 x float blocks of the two 0x30 byte records into the output.
//
// The original code of this module was built with /GS- and with SSE code
// generation for scalar floats, so the factor is held in an hkVector4:
// a __m128 local whose address is taken makes MSVC
// 2008 add a /GS stack cookie that the original does not have.
// ---------------------------------------------------------------------------

void __cdecl hkQsTransform_UpdateFields_00cde740(const hkQsTransform* a, const hkQsTransform* b, const hkVector4* t, hkQsTransform* out);

// @fnv 0x00cdd480
// src: GUESS 0x00cdd480 (confidence: low)
void hkQsTransform_ProcessEntries_00cdd480(unsigned count, hkQsTransform* a, hkQsTransform* b, float* c, hkQsTransform* d)
{
    for (unsigned i = 0; i < count; i++)
    {
        hkVector4 t;
        _mm_store_ps((float*)&t, _mm_load_ss(&c[i]));
        hkQsTransform_UpdateFields_00cde740(a + i, b + i, &t, d + i);
    }
}

// @fnv 0x00cdd4f0
// src: GUESS 0x00cdd4f0 (confidence: low)
void __cdecl hkVector4_ProcessEntries_00cdd4f0(unsigned int n, char* a, char* b, float f, char* c)
{
    hkVector4 s;
    *(__m128*)&s = _mm_load_ss(&f);
    for (unsigned int i = 0; i < n; i++)
        hkQsTransform_UpdateFields_00cde740(reinterpret_cast<hkQsTransform*>(a + i * 48),
                     reinterpret_cast<hkQsTransform*>(b + i * 48), &s,
                     reinterpret_cast<hkQsTransform*>(c + i * 48));
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

__forceinline void hkVector4::setBroadcast3(const hkVector4& v)
{
    m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& v) const
{
    const __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
    const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    hkSimdReal result;
    result.m_vValue = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    return result;
}

__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    qreal.setBroadcast3(quat.getImag());
    hkVector4 q2minus1;
    q2minus1.m_vComponents = _mm_add_ps(_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(q2minus1, direction);
    hkVector4 imagDotDir;
    imagDotDir.m_vComponents = quat.getImag().dot3(direction).m_vValue;
    imagDotDir.m_vComponents = _mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(imagDotDir, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

__forceinline void hkQsTransform::SetProduct(const hkQsTransform& t1, const hkQsTransform& t2)
{
    hkVector4 temp;
    temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
    m_vTranslation.setAdd4(temp, t1.m_vTranslation);
    m_rotation.setMul(t1.m_rotation, t2.m_rotation);
    m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
}

// @fnv 0x00cddad0
// src: COMMUNITY 0x00cddad0
extern "C" void __cdecl hkaSkeletonUtils_transformLocalPoseToWorldPose(int numTransforms, int parentIndicesIn, int* worldFromModelIn, int poseLocalIn,
                                     int poseModelIn)
{
    for (int i = 0; i < numTransforms; i++)
    {
        const int parentId = ((const short*)parentIndicesIn)[i];
        const hkQsTransform& worldFromParent = (-1 != parentId) ? ((hkQsTransform*)poseModelIn)[parentId]
                                                                   : (*(const hkQsTransform*)worldFromModelIn);
        ((hkQsTransform*)poseModelIn)[i].SetProduct(worldFromParent, ((const hkQsTransform*)poseLocalIn)[i]);
    }
}

// @fnv 0x00cddbf0
// src: GUESS 0x00cddbf0 (confidence: high)
void __cdecl hkQsTransform_AccumulateBoneParentTransforms(int boneIndex, const short* parentIndices, const hkQsTransform* poseLocal,
                          hkQsTransform& poseModelOut)
{
    poseModelOut = poseLocal[boneIndex];
    for (int parentId = parentIndices[boneIndex]; parentId >= 0; parentId = parentIndices[parentId])
    {
        poseModelOut.SetProduct(poseLocal[parentId], poseModelOut);
    }
}

// @fnv 0x00cddf20
// src: GUESS 0x00cddf20 (confidence: low)
void __cdecl hkQsTransform_ProcessEntries_00cddf20(int numTransforms, const hkQsTransform& transform, const hkQsTransform* transformsIn,
                          hkQsTransform* transformsOut)
{
    for (int i = 0; i < numTransforms; i++)
    {
        transformsOut[i].SetProduct(transform, transformsIn[i]);
    }
}

__declspec(noinline) inline void hkQuaternion::SetProduct(const hkQuaternion& q0, const hkQuaternion& q1)
{
    __m128 a = reinterpret_cast<const __m128&>(q0);
    __m128 b = reinterpret_cast<const __m128&>(q1);
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
    reinterpret_cast<__m128&>(*this) = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
}

__forceinline void hkVector4::SetRotatedDirection(const hkVector4& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vComponents, quat.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.dot3(direction).m_vValue;
    ret.addMul4(imagDotDir, quat);
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.getImag().m_vComponents, quat.getImag().m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.getImag().dot3(direction).m_vValue;
    ret.addMul4(imagDotDir, quat.getImag());
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(direction, quat.getImag());
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkQsTransform::SetConjugate(const hkQsTransform& t)
{
    m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
    m_vTranslation.setNeg4(m_vTranslation);
    m_rotation.SetConjugate(t.m_rotation);
    hkVector4 s;
    s.m_vComponents = _mm_shuffle_ps(
        t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
    // Refine the local reciprocal before storing it, as in this unit's inline form.
    __m128 r = _mm_rcp_ps(s.m_vComponents);
    __m128 rr = _mm_mul_ps(_mm_mul_ps(r, s.m_vComponents), r);
    m_vScale.m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
}

__forceinline void hkQsTransform::setMulContext(const hkQsTransform& t1, const hkQsTransform& t2)
{
    hkVector4 temp;
    temp.SetRotatedDirection(t1.m_rotation.getImag(), t2.m_vTranslation);
    m_vTranslation.setAdd4(temp, t1.m_vTranslation);
    m_rotation.SetProduct(t1.m_rotation, t2.m_rotation);
    m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
}

__forceinline void hkQsTransform::SetMulInverse(const hkQsTransform& a, const hkQsTransform& b)
{
    hkQsTransform h;
    h.SetConjugate(a);
    setMulContext(h, b);
}

// @fnv 0x00cde010
// src: GUESS 0x00cde010 (confidence: medium)
void __cdecl hkQsTransform_SetTransformArrayMulInverse(int iCount, const hkQsTransform& kA, const hkQsTransform* pkB, hkQsTransform* pkOut)
{
    for (int i = 0; i < iCount; i++)
        pkOut[i].SetMulInverse(kA, pkB[i]);
}

extern __m128 DAT_010ec7f0;
extern __m128 DAT_010c71b0;
extern const float DAT_01012054 = -1.0f;
extern const float DAT_0104da4c = 1.192092896e-07f;

static __m128 ld(const hkVector4& v)
{
    return _mm_load_ps(&v.x);
}

static void st(hkVector4& v, __m128 m)
{
    _mm_store_ps(&v.x, m);
}

static __m128 ld(const hkQuaternion& q)
{
    return _mm_load_ps(reinterpret_cast<const float*>(&q));
}

static void st(hkQuaternion& q, __m128 m)
{
    _mm_store_ps(reinterpret_cast<float*>(&q), m);
}

static __m128 hsum4(__m128 p)
{
    __m128 h = _mm_add_ps(p, _mm_shuffle_ps(p, p, 0x4e));
    return _mm_add_ps(h, _mm_shuffle_ps(h, h, 0xb1));
}

static __forceinline __m128 blend(__m128 a, __m128 b, const hkVector4* tp)
{
    __m128 t = _mm_shuffle_ps(ld(*tp), ld(*tp), 0);
    __m128 omt = _mm_sub_ps(DAT_010ec7f0, t);
    return _mm_add_ps(_mm_mul_ps(omt, a), _mm_mul_ps(b, t));
}
// @fnv 0x00cde740
// src: GUESS 0x00cde740 (confidence: low)
void __cdecl hkQsTransform_UpdateFields_00cde740(const hkQsTransform* a, const hkQsTransform* b, const hkVector4* tp, hkQsTransform* out)
{
    st(out->m_vTranslation, blend(ld(a->m_vTranslation), ld(b->m_vTranslation), tp));
    float dot;
    _mm_store_ss(&dot,
                 hsum4(_mm_mul_ps(reinterpret_cast<const __m128&>(a->m_rotation), reinterpret_cast<const __m128&>(b->m_rotation))));
    hkQuaternion qb = b->m_rotation;
    __m128 vQuaternionSign;
    if (dot < 0.0f)
    {
        __m128 neg = _mm_load_ss(&DAT_01012054);
        neg = _mm_shuffle_ps(neg, neg, 0);
        vQuaternionSign = _mm_mul_ps(neg, ld(qb));
    }
    else
    {
        vQuaternionSign = ld(qb);
    }
    st(out->m_rotation, blend(ld(a->m_rotation), vQuaternionSign, tp));
    st(out->m_vScale, blend(ld(a->m_vScale), ld(b->m_vScale), tp));
    _mm_store_ss(&dot, hsum4(_mm_mul_ps(ld(out->m_rotation), ld(out->m_rotation))));
    if (dot < DAT_0104da4c)
    {
        st(out->m_rotation, DAT_010c71b0);
    }
    else
    {
        out->m_rotation.normalize_005611c0();
    }
}

struct SkinFlagEntry
{
    int unk00;
    unsigned char m_bEnableState;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
};

struct SkinXformSet
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short* m_pIndices;
    int unk10;
    int unk14;
    SkinFlagEntry* m_pFlags;
    int m_uiItemCount;
};

static __forceinline __m128 rotate(__m128 a, __m128 b)
{
    __m128 w = _mm_shuffle_ps(b, b, 0xff);
    __m128 weight = _mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0);
    __m128 r = _mm_mul_ps(a, weight);
    __m128 product = _mm_mul_ps(a, b);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 xyz = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
    __m128 dot = _mm_shuffle_ps(xyz, xyz, 0);
    r = _mm_add_ps(r, _mm_mul_ps(dot, b));
    __m128 left = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 right = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    __m128 cross = _mm_sub_ps(right, left);
    r = _mm_add_ps(_mm_mul_ps(cross, w), r);
    return _mm_add_ps(r, r);
}

// @fnv 0x00cde2d0
// src: GUESS 0x00cde2d0 (confidence: low)
void __cdecl hkQsTransform_ProcessEntries_00cde2d0(SkinXformSet* set, const hkQsTransform* input, hkQsTransform* output)
{
    int count = set->m_uiItemCount;
    for (int index = 0; index < count; ++index)
    {
        short parent = (short)set->m_pIndices[index];
        hkQsTransform& destination = output[index];
        if (set->m_pFlags[index].m_bEnableState)
        {
            if (parent != -1)
            {
                hkQsTransform* parentEntry = output + parent;
                __m128 r = rotate(input[index].m_vTranslation.m_vComponents, reinterpret_cast<const __m128&>(parentEntry->m_rotation));
                destination.m_vTranslation.m_vComponents = _mm_add_ps(r, parentEntry->m_vTranslation.m_vComponents);
            }
            else
            {
                destination.m_vTranslation.m_vComponents = input[index].m_vTranslation.m_vComponents;
            }
        }
    }
}
