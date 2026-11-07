#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form
// The original intrinsic exposes only float lanes. The VC9 CRT version adds
// byte arrays, causing /GS to change the code of functions with SIMD locals.
#define _INCLUDED_MM2
// Exe 0x00cdd550 FUN_00cdd550: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;

#include "../../../../../include/V4.h"
#include "../../../../../include/Vec4.h"
#include "../../../../../include/hkQsTransform.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkaBone.h"
#include "../../../../../include/hkaSkeleton.h"



// src/havok/animation/animation/rig/hkaskeletonutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/rig/hkaskeletonutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00cdd3f0
// src: HAVOK_LIB 0x00cdd3f0
void hkaSkeletonUtils_unlockTranslations(hkaSkeleton* pEntries)
{
    int n = pEntries->m_kBones.m_iElementCount;
    for (int i = 0; i < n; ++i)
        pEntries->m_kBones.m_data[i].m_bLockTranslation.m_cBooleanValue = 0;
}

extern "C" void __cdecl hkaSkeletonUtils_transformLocalPoseToWorldPose(int, int, int*, int, int);
extern int DAT_01268700;

// Calls FUN_00cddad0 with a, b, the address of DAT_01268700, c and d.
// @fnv 0x00cddcf0
void __cdecl CallWithGlobal(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    hkaSkeletonUtils_transformLocalPoseToWorldPose(aiArg1, aiArg2, &DAT_01268700, aiArg3, aiArg4);
}

extern "C" void __cdecl Object_ToLocal_Thunk(void* a, void* b, void* c, void* d, void* e);
extern int DAT_01268700;

// Calls FUN_00cddd20 with a, b, the address of DAT_01268700, c and d.
// @fnv 0x00cddef0
// src: COMMUNITY 0x00cddef0
void hkaSkeletonUtils_transformModelPoseToLocalPose(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    Object_ToLocal_Thunk(apArg1, apArg2, &DAT_01268700, apArg3, apArg4);
}

extern "C" void __cdecl Atan2(float, float);

// @fnv 0x00ce00f0
// src: GUESS 0x00ce00f0 (confidence: low)
void __cdecl Hkaskeletonutils_ForwardCall_00ce00f0(float afFirst, float afSecond)
{
    Atan2(afFirst, afSecond);
}

int __cdecl CompareStringsCaseInsensitive(const void* pKey, const void* pItem);
static inline int GetBoneCount(const hkaSkeleton* skeleton)
{
    return skeleton->m_kBones.m_iElementCount;
}

static inline void* GetBoneName(const hkaSkeleton* skeleton, int index)
{
    return (void*)((unsigned int)skeleton->m_kBones.m_data[index].m_name.m_pcText & ~1u);
}

// Searches the table's entries for one matching pKey via pfnCompare (default CompareStringsCaseInsensitive) and returns its index, or -1 if none match.
// @fnv 0x00cdd390
short __cdecl FindIndexByKey(hkaSkeleton* pSearchEntries, const void* pKey,
                             int(__cdecl* pfnCompare)(const void*, const void*))
{
    int iCount = GetBoneCount(pSearchEntries);
    if (!pfnCompare)
        pfnCompare = CompareStringsCaseInsensitive;
    for (short i = 0; i < iCount; i++)
    {
        if (pfnCompare(pKey, GetBoneName(pSearchEntries, i)) == 0)
            return i;
    }
    return -1;
}

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
// Clears flags up to root, marks root, then sets each later node's flag from whether its parent is flagged, and finally sets root to finalValue.
// @fnv 0x00cdd410
void __cdecl MarkHierarchyDescendants(hkaSkeleton* hierarchy, int root, unsigned char* flags, unsigned char finalValue)
{
    if (root > 0)
        fnv_zlib_memset(flags, 0, root);
    flags[root] = 1;
    for (int i = root + 1; i < hierarchy->m_kBones.m_iElementCount; ++i)
    {
        short& parent = hierarchy->m_kParentIndices.m_data[i];
        flags[i] = (parent >= 0 && flags[parent] != 0) ? 1 : 0;
    }
    flags[root] = finalValue;
}

struct Sequence
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    short* values;
    int count;
};
// Checks every value in sequence->values against limits->m_kBones.m_iElementCount, writing true to result if all are in [0, limit) and false otherwise.
// @fnv 0x00cdd5b0
bool* __cdecl AreSequenceValuesInRange(bool* pbInRange, hkaSkeleton* limits, Sequence* sequence)
{
    int i = 0;
    for (; i < sequence->count; ++i)
    {
        short value = sequence->values[i];
        if (value < 0 || value >= limits->m_kBones.m_iElementCount)
        {
            *pbInRange = false;
            return pbInRange;
        }
    }
    *pbInRange = true;
    return pbInRange;
}

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

// Validates that the binding and track names are initialized, then maps each track to a bone index by comparing names and writes the indices to dst->out.
// @fnv 0x00cdd880
int __cdecl MapTracksToBones(hkaSkeleton* names, Src* src, CmpFn cmp, Dst* dst)
{
    if (dst->cnt == 0 || dst->cnt != src->n)
    {
        int buf[0x80];
        Msg m;
        m.Init(buf, 0x200);
        m.Add("Binding is not initiialized");
        DAT_01268360->Report(1, 0x654e3435, buf, ".\\Rig\\hkaSkeletonUtils.cpp", 0x1b7);
        m.Done();
        return 1;
    }
    if (src->f20 != src->n)
    {
        int buf[0x80];
        Msg m;
        m.Init(buf, 0x200);
        m.Add("No track names present in animation");
        DAT_01268360->Report(1, 0x654e3437, buf, ".\\Rig\\hkaSkeletonUtils.cpp", 0x1be);
        m.Done();
        return 1;
    }
    int cnt = names->m_kBones.m_iElementCount;
    int i;
    for (i = 0; i < cnt; i++)
    {
        if (((unsigned int)names->m_kBones.m_data[i].m_name.m_pcText & ~1u) == 0)
        {
            int buf[0x80];
            Msg m;
            m.Init(buf, 0x200);
            m.Add("No bone name for bone ", i).Fin();
            DAT_01268360->Report(1, 0x654e3437, buf, ".\\Rig\\hkaSkeletonUtils.cpp", 0x1c8);
            m.Done();
            return 1;
        }
    }
    for (int t = 0; t < src->n; t++)
    {
        bool found = false;
        unsigned int uiTrackKey = src->arr[t * 4] & ~1u;
        short j = 0;
        for (; j < names->m_kBones.m_iElementCount; j++)
        {
            unsigned int uiBoneName = (unsigned int)names->m_kBones.m_data[j].m_name.m_pcText & ~1u;
            if (cmp(uiBoneName, uiTrackKey) == 0)
            {
                found = true;
                dst->out[t] = j;
            }
        }
        if (!found)
        {
            int buf[0x80];
            Msg m;
            m.Init(buf, 0x200);
            m.Add("No match for track ", (int)uiTrackKey).Add();
            DAT_01268360->Report(1, 0x654e3438, buf, ".\\Rig\\hkaSkeletonUtils.cpp", 0x1de);
            m.Done();
            return 1;
        }
    }
    return 0;
}

struct HolderRec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_10;
};

struct ScanObj
{
    void ForwardCall_00cde940(int a, int b, void* c);
};

HolderRec* hkMemoryRouter_getInstance();

// @fnv 0x00cde3d0
unsigned char* WalkChainUntilLimit(unsigned char* pabResult, hkaSkeleton* rec, short asLimit, short asStart, ScanObj* obj)
{
    short s = asStart;
    int idx = (unsigned short)s;
    int iCurrent = idx;
    short sLimit = asLimit;
    if (s > 0)
    {
        do
        {
            if ((short)idx == sLimit)
                break;
            HolderRec* h = hkMemoryRouter_getInstance();
            obj->ForwardCall_00cde940(h->m_10, 0, &iCurrent);
            idx = ((const unsigned short*)rec->m_kParentIndices.m_data)[(short)idx];
            iCurrent = idx;
        } while ((short)idx > 0);
    }
    {
        int out;
        HolderRec* h = hkMemoryRouter_getInstance();
        obj->ForwardCall_00cde940(h->m_10, 0, &out);
    }
    *pabResult = ((short)idx >= 0);
    return pabResult;
}

namespace fnv_00cde450 {
struct S_00cde450_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n);
};

struct S_00cde450_Router
{
    char* m_fMinimumV;
    int unk04;
    int unk08;
    int unk0c;
    S_00cde450_Heap* m_pStreamAllocator;
    S_00cde450_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00cde450_Router* __cdecl hkMemoryRouter_getInstance();

struct S_00cde450_ByteArr;
struct S_00cde450_UShortArr;
void __cdecl FUN_00ec61c0(void* dst, int value, int size);
void __cdecl hkArrayUtil__reserve(S_00cde450_Heap& h, S_00cde450_ByteArr* a, int n, int elemSize);
void __cdecl ResizeAudioStream(S_00cde450_Heap& h, S_00cde450_UShortArr* a, int elemSize);

struct S_00cde450_UShortArr
{
    unsigned short* m_data;
    int m_iElementCount;
    int m_cap;

    void AddBack(unsigned short v)
    {
        S_00cde450_Heap& h = hkMemoryRouter_getInstance()->heap();
        if (m_iElementCount == (m_cap & 0x3fffffff))
            ResizeAudioStream(h, this, 2);
        unsigned short* p = m_data + m_iElementCount;
        for (int k = 0; k < 1; k++)
            p[k] = v;
        m_iElementCount++;
    }
};

struct S_00cde450_ByteArr
{
    char* m_data;
    int m_iElementCount;
    int m_cap;
    char* m_pTrailingData;
};

static __forceinline void S_00cde450_SetSize(S_00cde450_ByteArr& a, int n)
{
    int diff = n - a.m_iElementCount;
    char* p = a.m_data + a.m_iElementCount;
    if (diff <= 0)
    {
        a.m_iElementCount = n;
        return;
    }
    FUN_00ec61c0(p, 0, diff);
    a.m_iElementCount = n;
}

// @fnv 0x00cde450
void __cdecl CollectReachableNodes(hkaSkeleton* g, short asStartIndex, S_00cde450_UShortArr* pOutList,
                                   bool abIncludeStart)
{
    int iNodeCount = g->m_kBones.m_iElementCount;
    S_00cde450_ByteArr bits;
    bits.m_data = 0;
    bits.m_iElementCount = 0;
    bits.m_cap = 0x80000000;
    {
        S_00cde450_Router* r = hkMemoryRouter_getInstance();
        char* top = r->m_fMinimumV;
        r->m_fMinimumV = top + ((iNodeCount + 0x7f) & ~0x7f);
        bits.m_cap = iNodeCount | 0x80000000;
        bits.m_data = top;
        bits.m_pTrailingData = top;
    }
    int n = g->m_kBones.m_iElementCount;
    {
        S_00cde450_Heap& h = hkMemoryRouter_getInstance()->heap();
        int c = bits.m_cap & 0x3fffffff;
        if (c < n)
            hkArrayUtil__reserve(h, &bits, (n < c * 2) ? c * 2 : n, 1);
    }
    S_00cde450_SetSize(bits, n);

    if (abIncludeStart)
        pOutList->AddBack(asStartIndex);
    bits.m_data[asStartIndex] = 1;
    short i = (unsigned short)(asStartIndex + 1);
    for (; i < g->m_kBones.m_iElementCount; i++)
    {
        short p = g->m_kParentIndices.m_data[i];
        if (p != -1 && bits.m_data[p])
        {
            bits.m_data[i] = 1;
            pOutList->AddBack(i);
        }
    }

    char* pAllocBase = bits.m_pTrailingData;
    if (pAllocBase == bits.m_data)
        bits.m_iElementCount = 0;
    hkMemoryRouter_getInstance()->m_fMinimumV = pAllocBase;
    S_00cde450_Heap& h2 = hkMemoryRouter_getInstance()->heap();
    bits.m_iElementCount = 0;
    if ((bits.m_cap & 0x80000000) == 0)
        h2.ReturnMemory(bits.m_data, bits.m_cap & 0x3fffffff);
}
}  // namespace fnv_00cde450

extern "C" LocalM128 _mm_load_ss(const float* p);
__forceinline V4::V4() {}
extern "C" void __cdecl hkQsTransform_UpdateFields_00cde740(void* a, void* b, V4* v, void* c);
// For each of count entries, calls FUN_00cde740 on 0x30-byte slots at idx[i]*0x30 offsets in b1, b2, b3, passing w as a float vector.
// @fnv 0x00cdd550
// src: GUESS 0x00cdd550 (confidence: low)
void __cdecl Hkaskeletonutils_ProcessIndexedTransformSlots(unsigned int count, const short* idx, char* b1, char* b2, float w, char* b3)
{
    V4 v;
    v.q = _mm_load_ss(&w);
    for (unsigned int i = 0; i < count; i++)
    {
        int off = idx[i] * 0x30;
        hkQsTransform_UpdateFields_00cde740(b1 + off, b2 + off, &v, b3 + off);
    }
}

extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);

extern const LocalM128 DAT_010c71e0;


__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    const LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& b) const
{
    const LocalM128 x2 = _mm_mul_ps(m_vComponents, b.m_vComponents);
    hkSimdReal result;
    result.m_vValue = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    return result;
}

__forceinline hkSimdReal::hkSimdReal() {}

__forceinline void hkVector4::setMul4(LocalM128 r, const hkVector4& v)
{
    m_vComponents = _mm_mul_ps(r, v.m_vComponents);
}

__forceinline void hkVector4::addMul4(LocalM128 r, const hkVector4& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r, v.m_vComponents));
}

__forceinline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction)
{
    const hkVector4& imag = reinterpret_cast<const hkVector4&>(quat);
    const LocalM128 qreal = _mm_shuffle_ps(imag.m_vComponents, imag.m_vComponents, 0xff);
    const LocalM128 q2minus1 = _mm_add_ps(_mm_mul_ps(qreal, qreal), DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(q2minus1, direction);
    const LocalM128 imagDotDir = imag.dot3(direction).m_vValue;
    ret.addMul4(_mm_shuffle_ps(imagDotDir, imagDotDir, 0), imag);
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(imag, direction);
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

__forceinline void hkVector4::SetTransformedPoint(const hkQsTransform& t, const hkVector4& v)
{
    SetRotatedDirection(t.m_rotation, v);
    add4(t.m_vTranslation);
}


__forceinline void hkVector4::add4(const hkVector4& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
}

typedef short hkInt16;

// The shared skeleton ends just before the reference-pose array.
// Keep access to its data pointer here until that member is shared.
static __forceinline hkQsTransform* GetReferencePose(const hkaSkeleton* skeleton)
{
    return skeleton->m_kReferencePose.m_data;
}

// For each bone with m_bLockTranslation, sets poseModel translation from the reference pose, rotated and offset by the parent's transform when a parent exists.
// @fnv 0x00cde1d0
// src: GUESS 0x00cde1d0 (confidence: high)
void __cdecl hkaSkeleton_RestoreLockedBoneTranslations(const hkaSkeleton* skeleton, hkQsTransform* poseModel)
{
    const int numBones = skeleton->m_kBones.m_iElementCount;
    for (int i = 0; i < numBones; i++)
    {
        const short parent = skeleton->m_kParentIndices.m_data[i];
        if (skeleton->m_kBones.m_data[i].m_bLockTranslation.m_cBooleanValue)
        {
            const hkVector4& refTranslation = GetReferencePose(skeleton)[i].m_vTranslation;
            hkQsTransform& out = poseModel[i];
            if (parent != -1)
            {
                const hkQsTransform& p = poseModel[parent];
                out.m_vTranslation.SetRotatedDirection(p.m_rotation, refTranslation);
                poseModel[i].m_vTranslation.add4(p.m_vTranslation);
            }
            else
            {
                poseModel[i].m_vTranslation.m_vComponents = refTranslation.m_vComponents;
            }
        }
    }
}

extern "C" LocalM128 _mm_xor_ps(LocalM128, LocalM128);
extern "C" const LocalM128 DAT_010c44d0;
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern char DAT_010cb7dc[];
extern char DAT_010c41f8[];

struct TimerEntry
{
    const char* tag;
    unsigned int stamp;
    unsigned int unk08;
};
struct Monitor
{
    int unk00;
    TimerEntry* current;
    int unk08;
    TimerEntry* end;
};
static __forceinline void timer(const char* tag)
{
    Monitor* monitor = static_cast<Monitor*>(TlsGetValue(DAT_0126835c));
    TimerEntry* entry = monitor->current;
    if (entry < monitor->end)
    {
        entry->tag = tag;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        entry->stamp = stamp;
        monitor->current = entry + 1;
    }
}

struct HkObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void Begin();
};
struct HkEntity
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int owner;
};
struct HkWorld
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
    virtual HkEntity* GetEntity();
};
union __declspec(align(16)) VectorValue
{
    LocalM128 quad;
};
struct Allocator
{
    virtual void v00();
    virtual void* Allocate(unsigned int);
};
struct AllocationService
{
    int unk00, unk04, unk08, unk0c;
    Allocator* volatile allocator;
};
struct Property
{
    unsigned short type, unk02;
    int unk04, unk08, unk0c;
    unsigned short size, unk12;
    int unk14, unk18, unk1c;
    LocalM128 vector;
    static void* operator new(unsigned int bytes)
    {
        AllocationService* service = reinterpret_cast<AllocationService*>(hkMemoryRouter_getInstance());
        return service->allocator->Allocate(bytes);
    }
    Property()
    {
        type = 0x1a;
        size = 0x30;
    }
};
extern "C" Property* __cdecl FindModifierConstraintAtom(HkEntity*, int);
extern "C" void __cdecl hkpWorldConstraintUtil_addModifier(HkEntity*, HkObj*, Property*);

// Stores a Vec4 into a Property's vector field on an HkEntity, XORing it with DAT_010c44d0 when the entity's owner matches the given owner.
// @fnv 0x00cdfcd0
void SetModifierConstraint(HkWorld* apWorld, int owner, HkObj* apObj, Vec4* apVec)
{
    HkEntity* e = apWorld->GetEntity();
    if (e)
    {
        apObj->Begin();
        timer(DAT_010cb7dc);
        VectorValue t;
        *reinterpret_cast<Vec4*>(&t.quad) = *apVec;
        if (e->owner == owner)
        {
            t.quad = _mm_xor_ps(t.quad, DAT_010c44d0);
        }
        Property* p = FindModifierConstraintAtom(e, 0x1a);
        if (p)
        {
            p->vector = t.quad;
        }
        else
        {
            p = new Property;
            p->vector = t.quad;
            hkpWorldConstraintUtil_addModifier(e, apObj, p);
        }
        timer(DAT_010c41f8);
    }
}

extern LocalM128 DAT_010c7170;

struct S_00cdd600_Out
{
    LocalM128* p;
    LocalM128* val() const
    {
        return p;
    }
};
// Multiplies the scale vectors of a chain of bones starting at idx into r, then stores the result in out.
// @fnv 0x00cdd600
void __cdecl MultiplyBoneScales(hkaSkeleton* obj, hkQsTransform* bones, int aiStartIndex, S_00cdd600_Out out)
{
    LocalM128 r = DAT_010c7170;
    for (; aiStartIndex != -1; aiStartIndex = obj->m_kParentIndices.m_data[aiStartIndex])
        r = _mm_mul_ps(bones[aiStartIndex].m_vScale.m_vComponents, r);
    *out.val() = r;
}

extern "C"
{
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    void _mm_store_ss(float*, LocalM128);
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_rsqrt_ps(LocalM128);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    void _ReadWriteBarrier(void);
}

extern const LocalM128 DAT_010c71c0;
extern const LocalM128 DAT_010c71d0;

struct Simd
{
    LocalM128 m;
    __forceinline float getReal() const
    {
        float f;
        _mm_store_ss(&f, m);
        return f;
    }
};
// A 16-byte hkVector4/hkQuaternion lane of hkQsTransform (Item = translation, rotation, scale) with the unit's own inline lengthSquared4/mul4 forms; FUN_00cdd660 normalizes the rotations.
struct QsVector4
{
    LocalM128 m;
    __forceinline Simd lengthSquared() const
    {
        LocalM128 d = _mm_mul_ps(m, m);
        LocalM128 s = _mm_add_ps(d, _mm_shuffle_ps(d, d, 0x4e));
        Simd r;
        r.m = _mm_add_ps(s, _mm_shuffle_ps(s, s, 0xb1));
        return r;
    }
    __forceinline void mul(const Simd& factor)
    {
        m = _mm_mul_ps(_mm_shuffle_ps(factor.m, factor.m, 0), m);
    }
    __forceinline void SetProduct(const Simd& factor, const QsVector4& v)
    {
        m = _mm_mul_ps(factor.m, v.m);
    }
};
struct Item
{
    QsVector4 translation;
    QsVector4 rot;
    QsVector4 scale;
};

// Normalizes the rot vectors of up to count Item entries in batches of four using SIMD, then handles any remaining items individually.
// @fnv 0x00cdd660
// src: GUESS 0x00cdd660 (confidence: medium)
void Object_NormalizeRotationVectors(Item* items, int count)
{
    int blocks = count / 4;
    if ((unsigned int)blocks > 0)
    {
        float a[4];
        float d3[4];
        do
        {
            Simd sq0 = items[0].rot.lengthSquared();
            _mm_store_ss(&a[0], sq0.m);
            d3[0] = a[0];
            Simd sq1 = items[1].rot.lengthSquared();
            _mm_store_ss(&a[1], sq1.m);
            d3[1] = a[1];
            Simd sq2 = items[2].rot.lengthSquared();
            _mm_store_ss(&a[2], sq2.m);
            d3[2] = a[2];
            Simd sq3 = items[3].rot.lengthSquared();
            _mm_store_ss(&a[3], sq3.m);
            d3[3] = a[3];

            LocalM128 len = _mm_load_ps(d3);
            LocalM128 x = _mm_rsqrt_ps(len);
            LocalM128 r2 = _mm_mul_ps(x, len);
            r2 = _mm_mul_ps(r2, x);
            LocalM128 sub;
            sub = _mm_sub_ps(DAT_010c71c0, r2);
            LocalM128 j = _mm_mul_ps(DAT_010c71d0, x);
            LocalM128 factor = _mm_mul_ps(sub, j);

            Simd sc0;
            sc0.m = factor;
            items[0].rot.mul(sc0);
            Simd sc1;
            sc1.m = _mm_shuffle_ps(factor, factor, 0x55);
            items[1].rot.mul(sc1);
            Simd sc2;
            sc2.m = _mm_shuffle_ps(factor, factor, 0xaa);
            LocalM128 res2 = _mm_mul_ps(_mm_shuffle_ps(sc2.m, sc2.m, 0), items[2].rot.m);
            Simd sc3;
            sc3.m = _mm_shuffle_ps(factor, factor, 0xff);
            items[2].rot.m = res2;
            _ReadWriteBarrier();
            items[3].rot.mul(sc3);
            _ReadWriteBarrier();

            items += 4;
        } while (--blocks);
    }

    int iRemainder = count % 4;
    if (iRemainder)
    {
        LocalM128 pObj = _mm_set_ss(0.0f);
        LocalM128 three = _mm_set_ss(3.0f);
        LocalM128 half = _mm_set_ss(0.5f);
        LocalM128* p = &items->rot.m;
        int remaining = iRemainder;
        do
        {
            LocalM128 v;
            v = *p;
            LocalM128 d = _mm_mul_ps(v, v);
            LocalM128 s = _mm_add_ps(d, _mm_shuffle_ps(d, d, 0x4e));
            s = _mm_add_ps(s, _mm_shuffle_ps(s, s, 0xb1));

            LocalM128 r = _mm_rsqrt_ss(s);
            LocalM128 r2 = _mm_mul_ss(s, r);
            r2 = _mm_mul_ss(r2, r);
            LocalM128 j;
            j = _mm_mul_ss(half, r);
            LocalM128 sub = _mm_sub_ss(three, r2);
            LocalM128 factor = _mm_mul_ss(j, sub);

            LocalM128 zero = _mm_cmpeq_ss(s, pObj);
            factor = _mm_andnot_ps(zero, factor);
            LocalM128 d2 = _mm_shuffle_ps(factor, factor, 0x00);
            *p = _mm_mul_ps(d2, v);
            p = &(++items)->rot.m;
        } while (--remaining);
    }
}

extern "C" LocalM128 _mm_rcp_ps(LocalM128);
extern "C" LocalM128 _mm_and_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);

extern "C"
{
    extern const unsigned int DAT_010c4c00[4];
    extern const unsigned int DAT_010c4c10[4];
}

class SReal
{
  public:
    SReal()
    {}
    SReal(const LocalM128& x) : m_vValue(x)
    {}
    __forceinline LocalM128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const LocalM128& getQuad() const
    {
        return m_vValue;
    }

  private:
    LocalM128 m_vValue;
};

__forceinline LocalM128 approxReciprocal(LocalM128 r)
{
    LocalM128 e = _mm_rcp_ps(r);
    return _mm_sub_ps(_mm_add_ps(e, e), _mm_mul_ps(_mm_mul_ps(e, r), e));
}

struct QRot;

class QVec
{
  public:
    QVec()
    {}
    QVec(const LocalM128& q)
    {
        m_vComponents = q;
    }
    QVec(const QVec& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const QVec& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const LocalM128& q)
    {
        getQuad() = q;
    }
    operator LocalM128() const
    {
        return m_vComponents;
    }
    LocalM128& getQuad()
    {
        return m_vComponents;
    }
    const LocalM128& getQuad() const
    {
        return m_vComponents;
    }

    __forceinline void setAdd4(const QVec& a, const QVec& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const QVec& a, const QVec& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAddMul4(const QVec& a, const QVec& x, const QVec& y)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void addMul4(const QVec& x, const QVec& y)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void addMul4(const SReal& r, const QVec& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents));
    }
    __forceinline void sub4(const QVec& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void SetAllComponents(const SReal& r)
    {
        m_vComponents = _mm_shuffle_ps(r.getQuad(), r.getQuad(), 0x00);
    }
    __forceinline SReal lane(int i) const
    {
        switch (i)
        {
        case 0:
            return m_vComponents;
        case 1:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        case 2:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        case 3:
        default:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline void setNeg4(const QVec& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setNeg3(const QVec& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, *(const LocalM128*)&DAT_010c4c00);
    }
    __forceinline void setXYZ0(const QVec& xyz)
    {
        m_vComponents = _mm_and_ps(xyz, *(const LocalM128*)&DAT_010c4c10);
    }
    __forceinline void setXYZW(const QVec& xyz, const QVec& w)
    {
        m_vComponents = _mm_shuffle_ps(xyz.m_vComponents, _mm_unpackhi_ps(xyz.m_vComponents, w.m_vComponents), 0xc4);
    }
    __forceinline void setReciprocal4(const QVec& v)
    {
        m_vComponents = approxReciprocal(v.m_vComponents);
    }
    __forceinline void setReciprocal3(const QVec& v)
    {
        QVec ones;
        ones.getQuad() = DAT_010c7170;
        QVec padded;
        padded.setXYZW(v, ones);
        setReciprocal4(padded);
    }
    __forceinline void setCross(const QVec& a, const QVec& b)
    {
        LocalM128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        LocalM128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    __forceinline SReal dot3(const QVec& a) const
    {
        LocalM128 p = _mm_mul_ps(m_vComponents, a.m_vComponents);
        LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
    }
    __forceinline void splat(int i)
    {
        if (i == 0)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x00);
        else if (i == 1)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        else if (i == 2)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        else if (i == 3)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
    __forceinline void setSplat(const QVec& v, int i)
    {
        if (i == 0)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        else if (i == 1)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        else if (i == 2)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        else if (i == 3)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    void rotate(const QRot& q, const QVec& d);
    void rotateInverse(const QRot& q, const QVec& d);

  private:
    LocalM128 m_vComponents;
};

struct QRot
{
    QVec m_vec;
    __forceinline const QVec& imag() const
    {
        return m_vec;
    }
    __forceinline void SetConjugate(const QRot& q)
    {
        m_vec.setNeg3(q.imag());
    }
    inline void SetProduct(const QRot& a, const QRot& b);
};

inline void QRot::SetProduct(const QRot& a, const QRot& b)
{
    QVec v;
    v.setCross(a.imag(), b.imag());
    v.addMul4(a.m_vec.lane(3), b.imag());
    v.addMul4(b.m_vec.lane(3), a.imag());
    QVec d;
    d.SetAllComponents(a.m_vec.dot3(b.m_vec));
    QVec w;
    w.setMul4(a.m_vec, b.m_vec);
    w.sub4(d);
    m_vec.setXYZW(v, w);
}

__forceinline void QVec::rotate(const QRot& q, const QVec& d)
{
    QVec half;
    half.getQuad() = DAT_010c71e0;
    QVec w;
    w.setSplat(q.m_vec, 3);
    QVec w2;
    w2.setAddMul4(half, w, w);
    QVec out;
    out.setMul4(d, w2);
    QVec dp;
    dp.getQuad() = q.imag().dot3(d).getQuad();
    dp.splat(0);
    out.addMul4(dp, q.imag());
    QVec cr;
    cr.setCross(q.imag(), d);
    out.addMul4(w, cr);
    setAdd4(out, out);
}

__forceinline void QVec::rotateInverse(const QRot& q, const QVec& d)
{
    QVec half;
    half.getQuad() = DAT_010c71e0;
    QVec w;
    w.setSplat(q.m_vec, 3);
    QVec w2;
    w2.setAddMul4(half, w, w);
    QVec out;
    out.setMul4(d, w2);
    QVec dp;
    dp.getQuad() = q.imag().dot3(d).getQuad();
    dp.splat(0);
    out.addMul4(dp, q.imag());
    QVec cr;
    cr.setCross(d, q.imag());
    out.addMul4(w, cr);
    setAdd4(out, out);
}

// local form of hkQsTransform: 0x00cddd20 needs inline SetMulInverse; shared call gives 86 bytes vs exe 462.
struct QsXform
{
    QVec m_vTranslation;
    QRot m_rotation;
    QVec m_vScale;

    QsXform()
    {}

    __forceinline void SetConjugate(const QsXform& t)
    {
        m_vTranslation.rotateInverse(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        QVec inv;
        inv.setReciprocal3(t.m_vScale);
        m_vScale.setXYZ0(inv);
    }

    __forceinline void SetProduct(const QsXform& ab, const QsXform& bc)
    {
        QVec moved;
        moved.rotate(ab.m_rotation, bc.m_vTranslation);
        m_vTranslation.setAdd4(ab.m_vTranslation, moved);
        m_rotation.SetProduct(ab.m_rotation, bc.m_rotation);
        m_vScale.setMul4(ab.m_vScale, bc.m_vScale);
    }

    __forceinline void SetMulInverse(const QsXform& a, const QsXform& b)
    {
        QsXform inv;
        inv.SetConjugate(a);
        SetProduct(inv, b);
    }
};

__forceinline void toLocal(int count, const short* parents, const QsXform& root, const QsXform* world,
                           QsXform* localOut)
{
    for (int i = 0; i < count; i++)
    {
        const int p = parents[i];
        const QsXform& parentWorld = (p != -1) ? world[p] : root;
        localOut[i].SetMulInverse(parentWorld, world[i]);
    }
}

// Converts world-space QsXform transforms to local-space by calling toLocal with the given count, parents, root, world, and localOut arguments.
// @fnv 0x00cddd20
// src: GUESS 0x00cddd20 (confidence: medium)
extern "C" void __cdecl Object_ToLocal_Thunk(void* aiCount, void* apParents, void* apRoot, void* apWorld, void* apLocalOut)
{
    toLocal((int)aiCount, (const short*)apParents, *(const QsXform*)apRoot, (const QsXform*)apWorld,
            (QsXform*)apLocalOut);
}
