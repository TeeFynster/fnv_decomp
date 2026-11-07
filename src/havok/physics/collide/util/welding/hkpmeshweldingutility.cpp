#include "../../../../../../include/hkArray.h"
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form

// src/havok/physics/collide/util/welding/hkpmeshweldingutility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/util/welding/hkpmeshweldingutility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkVector4.h"

#include "../../../../../../include/Vec4.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkVector4q.h"
#include "../../../../../../include/hkpTriangleShape.h"
#include "../../../../../../include/hkpShape.h"
#include "../../../../../../include/hkpShapeContainer.h"

// Keep the original intrinsic storage view: VC9 treats the byte arrays in the
// CRT's __m128 as GS buffers and changes parameter copies in these functions.
namespace welding_simd {
// Exe 0x00ddd6f0 FUN_00ddd6f0: retain this LocalM128 view; the CRT type does not reproduce this function.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ps1(const float*);
    int _mm_movemask_ps(LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_set_ss(float);
    void _mm_store_ss(float*, LocalM128);
    LocalM128 _mm_load_ps(const float*);
    void _mm_store_ps(float*, LocalM128);
}
}  // namespace welding_simd

struct Record
{
    float x, y, key;
};
struct ComparisonResult
{
    bool value;
    ComparisonResult(bool result) : value(result)
    {}
    operator bool() const
    {
        return value;
    }
};
// src: GUESS 0x00ddcda0 (confidence: low)
__declspec(noinline) ComparisonResult Object_CompareField08_00ddcda0(const Record& left, const Record& right)
{
    return ComparisonResult(left.key > right.key);
}
inline void SwapRecords(Record& first, Record& second)
{
    __declspec(align(16)) Record temp = second;
    second = first;
    first = temp;
}
// Sorts a range of records in place by key using a pivot and recursive quicksort, comparing with FUN_00ddcda0 and swapping with SwapRecords.
// @fnv 0x00ddeb70
// src: HAVOK_LIB 0x00ddeb70
void hkAlgorithm_quickSortRecursive_struct_hkEntry_class_hkAlgorithm_less_struct_hkEntry(Record* records, int left, int right, int comparator)
{
    int i = left;
    int j = right;
    __declspec(align(16)) Record pivotRecord = records[(left + right) >> 1];
    do
    {
        while (Object_CompareField08_00ddcda0(records[i], pivotRecord))
            ++i;
        while (Object_CompareField08_00ddcda0(pivotRecord, records[j]))
            --j;
        if (j >= i)
        {
            if (j != i)
            {
                SwapRecords(records[i], records[j]);
            }
            --j;
            ++i;
        }
    } while (i <= j);
    if (left < j)
        hkAlgorithm_quickSortRecursive_struct_hkEntry_class_hkAlgorithm_less_struct_hkEntry(records, left, j, comparator);
    if (i < right)
        hkAlgorithm_quickSortRecursive_struct_hkEntry_class_hkAlgorithm_less_struct_hkEntry(records, i, right, comparator);
}

// Exe 0x00ddecb0: unit-local DynamicArray view; declarations and layout are preserved.
struct HkpmeshweldingutilityDynamicArrayView
{
    void SpliceElements(int a, int b, int c, int d, int e);
    void SpliceElements_Thunk(int a, int b, int c, int d);
};
// @fnv 0x00ddecb0
// src: GUESS 0x00ddecb0 (confidence: medium)
void HkpmeshweldingutilityDynamicArrayView::SpliceElements_Thunk(int a, int b, int c, int d)
{
    SpliceElements(a, b, 0, c, d);
}

struct S_00ddecf0_Key
{
    float t;
    float a;
    float b;
};

// This entry point is nonthrowing in the game; array cleanup depends on that contract.
__declspec(nothrow) hkMemoryRouter* hkMemoryRouter_getInstance();


template <typename T> __forceinline void hkMemoryAllocator::_bufFree(void* p, int numElem)
{
    bufFree(p, numElem * (int)sizeof(T));
}

struct S_00ddecf0_Array
{
    S_00ddecf0_Key* m_data;
    int m_iElementCount;
    void ForwardCall_00ddecd0(hkMemoryAllocator& heap, int index, const S_00ddecf0_Key& key);
};

struct S_00ddecf0
{
    int unk0;
    S_00ddecf0_Array m_keys;
    void InsertKey(float t, float a, float b);
};

// @fnv 0x00ddecf0
void S_00ddecf0::InsertKey(float t, float a, float b)
{
    int n = m_keys.m_iElementCount;
    for (int i = 0; i < n; i++)
    {
        if (m_keys.m_data[i].t < t)
        {
            n = i + 1;
            break;
        }
    }
    S_00ddecf0_Key key;
    key.t = t;
    key.a = a;
    key.b = b;
    m_keys.ForwardCall_00ddecd0(reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance()->heap()), n, key);
}

extern double DAT_010cd5a8;
extern double DAT_0101ff40;

float Object_ComputeDihedralSinCos(int a1, int* pOut, float* pF);

// @fnv 0x00dddc40
int GetIndexForValue(int aiArg)
{
    int n;
    float tmp;
    tmp = Object_ComputeDihedralSinCos(aiArg, &n, &tmp);
    float r = tmp;

    for (n = 0; n < 31; n++)
    {
        tmp = (float)((double)n * DAT_010cd5a8 - DAT_0101ff40);
        if (r <= tmp)
            goto done;
    }
    return n;
done:
    if (r > 0.0f)
    {
        if (tmp != r)
            n--;
    }
    return n;
}

struct FlagTag
{
    bool m_bValue;
    FlagTag(bool value) : m_bValue(value)
    {}
    FlagTag(const FlagTag& other) : m_bValue(other.m_bValue)
    {}
};

struct Mgr
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void Write(unsigned int hash, FlagTag value);
    virtual void Read(bool* out, unsigned int hash);
};

extern Mgr* DAT_01268360;

__declspec(align(16)) struct QueryBuffer
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
};

int hkpMeshWeldingUtility_calcBitcodeForTriangleEdge(hkpShape* self, const hkpShape* a, void* b, int idx, int zero, int* out);

// Reads a flag, clears it, runs up to three sub-queries via FUN_00dde4c0, sets result false if any returns 1, then restores the flag.
// @fnv 0x00dde930
bool* CheckSubQueries(bool* result, void* key, hkpShape* self)
{
    QueryBuffer queryBuf;
    const hkpShape* sub = self->GetShapeContainer()->GetShapeForKey(
        reinterpret_cast<hkpShapeKey>(key), *reinterpret_cast<hkpShapeBuffer*>(&queryBuf));
    bool flag;
    DAT_01268360->Read(&flag, 0xfe98751e);
    if (flag)
    {
        Mgr* mgr = DAT_01268360;
        mgr->Write(0xfe98751e, FlagTag(false));
    }
    *result = true;
    int n = 0;
    for (int i = 0; i < 3; i++)
    {
        if (hkpMeshWeldingUtility_calcBitcodeForTriangleEdge(self, sub, key, i, 0, &n) == 1)
        {
            *result = false;
            break;
        }
    }
    if (flag)
    {
        Mgr* mgr = DAT_01268360;
        mgr->Write(0xfe98751e, FlagTag(true));
    }
    return result;
}

void* hkArrayUtil__reserve(void* alloc, void* arr, int numElems, int elemSize);
void hkMemUtil_memMove(void* dst, const void* src, int numBytes);

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct S_00ddeab0_Elem
{
    int a, b, c;
    S_00ddeab0_Elem()
    {}
};

static __forceinline void S_00ddeab0_GrowArrayCapacity(hkArrayBase<S_00ddeab0_Elem>& self, void* alloc, int numElems);

static __forceinline void S_00ddeab0_GrowArrayCapacity(hkArrayBase<S_00ddeab0_Elem>& self, void* alloc, int numElems)
{
        int cap = self.m_iCapacityState & 0x3fffffff;
        if (cap < numElems)
        {
            int cap2 = cap + cap;
            int newcap = (numElems < cap2) ? cap2 : numElems;
            hkArrayUtil__reserve(alloc, (&self), newcap, 12);
        }
    }

// Replaces numdel elements at index with numtoinsert copies from p, shifting the tail and growing the buffer if needed.
// @fnv 0x00ddeab0


struct S_00ddecd0
{
    void SpliceElements_Thunk(int a, int b, int c, int flag);
    void ForwardCall_00ddecd0(int a, int b, int c);
};
// @fnv 0x00ddecd0
// src: GUESS 0x00ddecd0 (confidence: low)
void S_00ddecd0::ForwardCall_00ddecd0(int aiArg1, int aiArg2, int aiArg3)
{
    SpliceElements_Thunk(aiArg1, aiArg2, aiArg3, 1);
}

struct LocalBuffer
{
    __declspec(align(16)) int data[125];
};

char* IsDegenerateTriangle(char* out, const hkVector4* v0, const hkVector4* v1, const hkVector4* v2,
                           float eps);
int hkpMeshWeldingUtility_calcBitcodeForTriangleEdge(hkpShape* p2, const hkpTriangleShape* trans, void* p1, int i, void* p3, int* outLocal);

// @fnv 0x00dde880
int __cdecl CheckTransformAndProcess(void* p1, hkpShape* pOuter, void* p3, short* outWord)
{
    LocalBuffer buffer;
    char checkResult;

    const hkpShapeContainer* inner = pOuter->GetShapeContainer();
    const hkpTriangleShape* trans = static_cast<const hkpTriangleShape*>(
        inner->GetShapeForKey(reinterpret_cast<hkpShapeKey>(p1), *reinterpret_cast<hkpShapeBuffer*>(&buffer)));

    if (*IsDegenerateTriangle(&checkResult, reinterpret_cast<const hkVector4*>(&trans->m_kVertexA), reinterpret_cast<const hkVector4*>(&trans->m_kVertexB), reinterpret_cast<const hkVector4*>(&trans->m_kVertexC), 1.0e-7f) != 0)
    {
        *outWord = 0;
        return 1;
    }

    int iResult = 0;
    int local2 = 0;
    for (int i = 0; i < 3; ++i)
    {
        int iRet = hkpMeshWeldingUtility_calcBitcodeForTriangleEdge(pOuter, trans, p1, i, p3, &iResult);
        if (iRet == 1)
        {
            local2 = iRet;
        }
    }
    *outWord = (short)iResult;
    return local2;
}

extern const float DAT_01017d00;
extern const welding_simd::LocalM128 DAT_01017d10;

inline bool WeldingVectorsEqual3(const hkVector4& a, const hkVector4& b)
{
    welding_simd::LocalM128 t = welding_simd::_mm_sub_ps(
        reinterpret_cast<const welding_simd::LocalM128&>(a), reinterpret_cast<const welding_simd::LocalM128&>(b));
    t = welding_simd::_mm_and_ps(t, DAT_01017d10);
    const welding_simd::LocalM128 eps = welding_simd::_mm_load_ps1(&DAT_01017d00);
    return (welding_simd::_mm_movemask_ps(welding_simd::_mm_cmple_ps(t, eps)) & 7) == 7;
}

struct hkUtilDDCE
{
    static hkBool ForwardCall_00ddced0(const hkpTriangleShape& kA, const hkpTriangleShape& kB);
};

// Returns true when the three vertices of kA and kB are all equal within epsilon.
// @fnv 0x00ddced0
// src: GUESS 0x00ddced0 (confidence: low)
hkBool hkUtilDDCE::ForwardCall_00ddced0(const hkpTriangleShape& kA, const hkpTriangleShape& kB)
{
    return WeldingVectorsEqual3(kA.m_kVertexA, kB.m_kVertexA) && WeldingVectorsEqual3(kA.m_kVertexB, kB.m_kVertexB) &&
           WeldingVectorsEqual3(kA.m_kVertexC, kB.m_kVertexC);
}

namespace fnv_00ddd940 { extern welding_simd::LocalM128 DAT_010c4c00; }

inline welding_simd::LocalM128& WeldingQuad(hkVector4& v)
{
    return reinterpret_cast<welding_simd::LocalM128&>(v.m_vComponents);
}
inline const welding_simd::LocalM128& WeldingQuad(const hkVector4& v)
{
    return reinterpret_cast<const welding_simd::LocalM128&>(v.m_vComponents);
}

__forceinline void hkVector4::operator=(const hkVector4& v)
{
    WeldingQuad(*this) = WeldingQuad(v);
}
__forceinline hkReal& hkVector4::operator()(int i)
{
    return reinterpret_cast<hkReal*>(&WeldingQuad(*this))[i];
}

__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    WeldingQuad(*this) = welding_simd::_mm_sub_ps(WeldingQuad(a), WeldingQuad(b));
}
__forceinline void hkVector4::setNeg3(const hkVector4& v)
{
    WeldingQuad(*this) = welding_simd::_mm_xor_ps(WeldingQuad(v), fnv_00ddd940::DAT_010c4c00);
}
__forceinline void hkVector4::setCross(const hkVector4& v0, const hkVector4& v1)
{
    welding_simd::LocalM128 cross0 = welding_simd::_mm_mul_ps(welding_simd::_mm_shuffle_ps(WeldingQuad(v0), WeldingQuad(v0), 0xc9),
                               welding_simd::_mm_shuffle_ps(WeldingQuad(v1), WeldingQuad(v1), 0xd2));
    welding_simd::LocalM128 cross1 = welding_simd::_mm_mul_ps(welding_simd::_mm_shuffle_ps(WeldingQuad(v0), WeldingQuad(v0), 0xd2),
                               welding_simd::_mm_shuffle_ps(WeldingQuad(v1), WeldingQuad(v1), 0xc9));
    WeldingQuad(*this) = welding_simd::_mm_sub_ps(cross0, cross1);
}
__forceinline hkReal hkVector4::dot3scalar(const hkVector4& v) const
{
    welding_simd::LocalM128 p = welding_simd::_mm_mul_ps(WeldingQuad(*this), WeldingQuad(v));
    welding_simd::LocalM128 s = welding_simd::_mm_add_ss(welding_simd::_mm_shuffle_ps(p, p, 0x55), p);
    s = welding_simd::_mm_add_ss(welding_simd::_mm_shuffle_ps(p, p, 0xaa), s);
    hkReal r;
    welding_simd::_mm_store_ss(&r, s);
    return r;
}
__forceinline void hkVector4::normalize3()
{
    welding_simd::LocalM128 p = welding_simd::_mm_mul_ps(WeldingQuad(*this), WeldingQuad(*this));
    welding_simd::LocalM128 len2 = welding_simd::_mm_add_ss(welding_simd::_mm_shuffle_ps(p, p, 0x55), p);
    len2 = welding_simd::_mm_add_ss(welding_simd::_mm_shuffle_ps(p, p, 0xaa), len2);
    welding_simd::LocalM128 e = welding_simd::_mm_rsqrt_ss(len2);
    welding_simd::LocalM128 r = welding_simd::_mm_mul_ss(welding_simd::_mm_mul_ss(welding_simd::_mm_set_ss(0.5f), e),
                          welding_simd::_mm_sub_ss(welding_simd::_mm_set_ss(3.0f), welding_simd::_mm_mul_ss(welding_simd::_mm_mul_ss(len2, e), e)));
    r = welding_simd::_mm_andnot_ps(welding_simd::_mm_cmpeq_ss(len2, welding_simd::_mm_set_ss(0.0f)), r);
    WeldingQuad(*this) = welding_simd::_mm_mul_ps(welding_simd::_mm_shuffle_ps(r, r, 0), WeldingQuad(*this));
}

namespace fnv_00ddd940 {

typedef float hkReal;

void hkpMeshWeldingUtility_calcAntiClockwiseTriangleNormal(const hkVector4& a, const hkVector4& b, const hkVector4& c, hkVector4& normalOut);

// Builds five planes for a triangle: its normal, the negated normal, and three edge planes (edge crossed with normal, normalized), each offset by -radius.
// @fnv 0x00ddd940
void GenerateTrianglePlanes(hkVector4* planes, const hkpTriangleShape* triangle, hkReal radius)
{
    hkVector4 normal;
    hkpMeshWeldingUtility_calcAntiClockwiseTriangleNormal(triangle->m_kVertexA, triangle->m_kVertexB, triangle->m_kVertexC, normal);

    hkReal d = -radius;

    hkVector4 e0;
    e0.setSub4(triangle->m_kVertexB, triangle->m_kVertexA);
    hkVector4 e1;
    e1.setSub4(triangle->m_kVertexC, triangle->m_kVertexB);
    hkVector4 e2;
    e2.setSub4(triangle->m_kVertexA, triangle->m_kVertexC);

    planes[0] = normal;
    planes[0](3) = d - planes[0].dot3scalar(triangle->m_kVertexA);

    planes[1].setNeg3(normal);
    planes[1](3) = d - planes[1].dot3scalar(triangle->m_kVertexA);

    planes[2].setCross(e0, normal);
    planes[2].normalize3();
    planes[2](3) = d - planes[2].dot3scalar(triangle->m_kVertexA);

    planes[3].setCross(e1, normal);
    planes[3].normalize3();
    planes[3](3) = d - planes[3].dot3scalar(triangle->m_kVertexB);

    planes[4].setCross(e2, normal);
    planes[4].normalize3();
    planes[4](3) = d - planes[4].dot3scalar(triangle->m_kVertexC);
}
}  // namespace fnv_00ddd940

struct FUN_00ddea00_src
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
};

__declspec(align(16)) struct FUN_00ddea00_tmp
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
};

__declspec(align(16)) struct FUN_00ddea00_cls
{
    welding_simd::LocalM128 m_v00;
    welding_simd::LocalM128 m_v10;
    welding_simd::LocalM128 m_v20;
    welding_simd::LocalM128 m_v30;
    unsigned int m_i40;

    FUN_00ddea00_cls* CopyFromSource(const FUN_00ddea00_src* src);
};

// Copies all fields from the source struct into the welding_simd::__m128 members and m_i40 of this object, then returns this.
// @fnv 0x00ddea00
FUN_00ddea00_cls* FUN_00ddea00_cls::CopyFromSource(const FUN_00ddea00_src* src)
{
    FUN_00ddea00_tmp tmp;
    tmp.unk00 = src->unk00;
    tmp.unk04 = src->unk04;
    tmp.unk08 = src->unk08;
    tmp.unk0C = src->unk0C;
    tmp.unk10 = src->unk10;
    tmp.unk14 = src->unk14;
    tmp.unk18 = src->unk18;
    tmp.unk1C = src->unk1C;
    tmp.unk20 = src->unk20;
    tmp.unk24 = src->unk24;
    tmp.unk28 = src->unk28;
    tmp.unk2C = src->unk2C;
    tmp.unk30 = src->unk30;
    tmp.unk34 = src->unk34;
    tmp.unk38 = src->unk38;
    unsigned int uiLastWord = src->unk3C;
    m_v00 = *(welding_simd::LocalM128*)&tmp.unk00;
    m_v10 = *(welding_simd::LocalM128*)&tmp.unk10;
    m_v20 = *(welding_simd::LocalM128*)&tmp.unk20;
    tmp.unk3C = uiLastWord;
    m_v30 = *(welding_simd::LocalM128*)&tmp.unk30;
    m_i40 = src->unk40;
    return this;
}

// Rotates a's three vectors by index into out, then appends each b[i] not equal to out[0] or out[1] (else stores i in result[j]) and returns the count.
// @fnv 0x00ddd6f0
// src: GUESS 0x00ddd6f0 (confidence: medium)
int __cdecl Hkpmeshweldingutility_MergeTriangleVectors(const welding_simd::LocalM128* apVectors, const welding_simd::LocalM128* b, int aiStartIndex, welding_simd::LocalM128* out, int* result)
{
    out[0] = apVectors[aiStartIndex % 3];
    out[1] = apVectors[(aiStartIndex + 1) % 3];
    out[2] = apVectors[(aiStartIndex + 2) % 3];
    int count = 3;
    int i = 0;
    welding_simd::LocalM128* append = out + 3;
    for (; i < 3; ++i)
    {
        welding_simd::LocalM128 current = b[i];
        for (int j = 0; j < 2; ++j)
        {
            welding_simd::LocalM128 d = welding_simd::_mm_sub_ps(out[j], current);
            welding_simd::LocalM128 p = welding_simd::_mm_mul_ps(d, d);
            welding_simd::LocalM128 y = welding_simd::_mm_shuffle_ps(p, p, 0x55);
            welding_simd::LocalM128 z = welding_simd::_mm_shuffle_ps(p, p, 0xaa);
            y = welding_simd::_mm_add_ss(y, p);
            z = welding_simd::_mm_add_ss(z, y);
            float distance;
            welding_simd::_mm_store_ss(&distance, z);
            if (distance == 0.0f)
            {
                result[j] = i;
                goto next;
            }
        }
        ++count;
        welding_simd::LocalM128* destination = append;
        ++append;
        *destination = current;
    next:;
    }
    return count;
}

extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;

struct ScalarNormal
{
    welding_simd::LocalM128 q;
    ScalarNormal(welding_simd::LocalM128 value) : q(value)
    {}
    welding_simd::LocalM128 broadcast() const
    {
        return welding_simd::_mm_shuffle_ps(q, q, 0);
    }
};
struct NormalVector
{
    welding_simd::LocalM128 q;
    __forceinline void difference(const NormalVector& a, const NormalVector& b)
    {
        q = welding_simd::_mm_sub_ps(a.q, b.q);
    }
    __forceinline void cross(const NormalVector& a, const NormalVector& b)
    {
        welding_simd::LocalM128 pos = welding_simd::_mm_mul_ps(welding_simd::_mm_shuffle_ps(a.q, a.q, 201), welding_simd::_mm_shuffle_ps(b.q, b.q, 210));
        welding_simd::LocalM128 neg = welding_simd::_mm_mul_ps(welding_simd::_mm_shuffle_ps(a.q, a.q, 210), welding_simd::_mm_shuffle_ps(b.q, b.q, 201));
        q = welding_simd::_mm_sub_ps(pos, neg);
    }
    __forceinline ScalarNormal dot(const NormalVector& v) const
    {
        welding_simd::LocalM128 square = welding_simd::_mm_mul_ps(q, v.q);
        welding_simd::LocalM128 sum = welding_simd::_mm_add_ss(welding_simd::_mm_shuffle_ps(square, square, 85), square);
        return ScalarNormal(welding_simd::_mm_add_ss(welding_simd::_mm_shuffle_ps(square, square, 170), sum));
    }
    __forceinline ScalarNormal inverseLength() const
    {
        welding_simd::LocalM128 half = welding_simd::_mm_set_ss(DAT_01016248);
        welding_simd::LocalM128 three = welding_simd::_mm_set_ss(DAT_01017718);
        welding_simd::LocalM128 zero = welding_simd::_mm_set_ss(DAT_01011d78);
        welding_simd::LocalM128 len = dot(*this).q;
        welding_simd::LocalM128 mask = welding_simd::_mm_cmpeq_ss(len, zero);
        welding_simd::LocalM128 approx = welding_simd::_mm_rsqrt_ss(len);
        welding_simd::LocalM128 correction = welding_simd::_mm_sub_ss(three, welding_simd::_mm_mul_ss(welding_simd::_mm_mul_ss(len, approx), approx));
        return ScalarNormal(welding_simd::_mm_andnot_ps(mask, welding_simd::_mm_mul_ss(welding_simd::_mm_mul_ss(half, approx), correction)));
    }
    __forceinline void normalize()
    {
        q = welding_simd::_mm_mul_ps(inverseLength().broadcast(), q);
    }
};
// Computes the normalized cross product of two triangle edge vectors (b-a) and (c-b) and stores the result in out.
// @fnv 0x00ddd620
// src: COMMUNITY 0x00ddd620
void hkpMeshWeldingUtility_calcAntiClockwiseTriangleNormal(const NormalVector* apVertexA, const NormalVector* apVertexB, const NormalVector* apVertexC,
                  NormalVector* apNormal)
{
    NormalVector edges[2];
    edges[0].difference(*apVertexB, *apVertexA);
    edges[1].difference(*apVertexC, *apVertexB);
    NormalVector n;
    n.cross(edges[0], edges[1]);
    n.normalize();
    *apNormal = n;
}

extern const double DAT_010290b8;
void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize) throw();

struct KeyLess
{
};
void __cdecl hkAlgorithm_quickSortRecursive_struct_hkEntry_class_hkAlgorithm_less_struct_hkEntry(S_00ddecf0_Key* keys, int left, int right, KeyLess cmp) throw();
template <typename T, typename L> inline void quickSort(T* pArr, int size, L cmpLess)
{
    if (size > 1)
        hkAlgorithm_quickSortRecursive_struct_hkEntry_class_hkAlgorithm_less_struct_hkEntry(pArr, 0, size - 1, cmpLess);
}
extern "C" double __cdecl fabs(double);
__declspec(noinline) ComparisonResult __cdecl AreZDiffering(const S_00ddecf0_Key& a, const S_00ddecf0_Key& b) throw()
{
    float delta = a.b - b.b;
    float distance = (float)fabs(delta);
    bool same = distance < DAT_01017d00;
    return ComparisonResult(!same);
}

// hkArray bodies (allocator = the memory router's heap).
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance()->heap());
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if (!(m_iCapacityState & 0x80000000))
        alloc._bufFree<T>(m_data, getCapacity());
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
template <typename T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& value)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(&alloc, this, sizeof(T));
    T* dest = m_data + m_iElementCount;
    new (dest) T(value);
    ++m_iElementCount;
}
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    clearAndDeallocate();
}

static inline float clamp(float x, float lo, float hi)
{
    if (x < lo)
        return lo;
    if (x > hi)
        return hi;
    return x;
}

struct Track : public S_00ddecf0
{
    float hkHistogram_evaluate();
};

// If m_keys is empty returns unk0; else sorts it, groups near-equal-b keys, and returns the smallest b of a group with summed a-t >= DAT_010290b8, or 0.
// @fnv 0x00dded60
// src: HAVOK_LIB 0x00dded60
float Track::hkHistogram_evaluate()
{
    if (m_keys.m_iElementCount == 0)
        return *(float*)&unk0;
    quickSort(m_keys.m_data, m_keys.m_iElementCount, KeyLess());

    hkArray<S_00ddecf0_Key> spans;
    {
        int start = 0;
        for (int i = 1; i <= m_keys.m_iElementCount; i++)
        {
            if (i < m_keys.m_iElementCount && !AreZDiffering(m_keys.m_data[start], m_keys.m_data[i]))
                continue;
            int n = i - start;
            float sum = 0.0f;
            for (int k = 0; k < n; k++)
            {
                const S_00ddecf0_Key& key = m_keys.m_data[start + k];
                sum += key.a - key.t;
            }
            S_00ddecf0_Key key;
            key.b = m_keys.m_data[start].b;
            key.t = 0.0f;
            key.a = clamp(sum, 0.0f, 1.0f);
            spans.pushBack(key);
            start = i;
        }
    }
    float minLen = 3.14159274f;
    bool found = false;
    for (int j = 0; j < spans.GetLogicalSize(); ++j)
    {
        S_00ddecf0_Key* p = &spans[j];
        if (!(p->a - p->t < DAT_010290b8))
        {
            float len = p->b;
            if (!(minLen < len))
                minLen = len;
            found = true;
        }
    }
    return found ? minLen : 0.0f;
}

// FUN_00ddcf60 - "point A is close to one of the three points of the shape
// AND point B is close to one of them as well" test.
//
// The shape object holds three 4-float points at +0x20 / +0x30 / +0x40.
// A point counts as a hit when the x/y/z components of the difference are not
// (movmskps + "and 7" + "cmp 7").
//
// The result byte is written through the first argument; the argument pointer
// is handed back to the caller.

// Stores true when points a and b are each within tolerance of a triangle vertex, and returns out.
// @fnv 0x00ddcf60
// src: GUESS 0x00ddcf60 (confidence: medium)
volatile unsigned char* __cdecl Object_TestTriangleVertexProximity(volatile unsigned char* out, const Vec4* apPointA, const Vec4* apPointB,
                                             const hkpTriangleShape* apShape)
{
    welding_simd::LocalM128 pt = reinterpret_cast<const welding_simd::LocalM128&>(apShape->m_kVertexA);
    welding_simd::LocalM128 q = reinterpret_cast<const welding_simd::LocalM128&>(*apPointA);
    welding_simd::LocalM128 eps = welding_simd::_mm_load_ps1(&DAT_01017d00);
    welding_simd::LocalM128 mask = DAT_01017d10;

    bool v =
        (((welding_simd::_mm_movemask_ps(welding_simd::_mm_cmple_ps(welding_simd::_mm_and_ps(welding_simd::_mm_sub_ps(pt, q), mask), eps)) & 7) == 7) ||
         ((welding_simd::_mm_movemask_ps(welding_simd::_mm_cmple_ps(welding_simd::_mm_and_ps(welding_simd::_mm_sub_ps(reinterpret_cast<const welding_simd::LocalM128&>(apShape->m_kVertexB), q), mask), eps)) & 7) == 7) ||
         ((welding_simd::_mm_movemask_ps(welding_simd::_mm_cmple_ps(welding_simd::_mm_and_ps(welding_simd::_mm_sub_ps(reinterpret_cast<const welding_simd::LocalM128&>(apShape->m_kVertexC), q), mask), eps)) & 7) == 7)) &&
        (((welding_simd::_mm_movemask_ps(welding_simd::_mm_cmple_ps(welding_simd::_mm_and_ps(welding_simd::_mm_sub_ps(pt, reinterpret_cast<const welding_simd::LocalM128&>(*apPointB)), mask), eps)) & 7) == 7) ||
         ((welding_simd::_mm_movemask_ps(welding_simd::_mm_cmple_ps(welding_simd::_mm_and_ps(welding_simd::_mm_sub_ps(reinterpret_cast<const welding_simd::LocalM128&>(apShape->m_kVertexB), reinterpret_cast<const welding_simd::LocalM128&>(*apPointB)), mask), eps)) & 7) == 7) ||
         ((welding_simd::_mm_movemask_ps(welding_simd::_mm_cmple_ps(welding_simd::_mm_and_ps(welding_simd::_mm_sub_ps(reinterpret_cast<const welding_simd::LocalM128&>(apShape->m_kVertexC), reinterpret_cast<const welding_simd::LocalM128&>(*apPointB)), mask), eps)) & 7) == 7));

    *out = v;
    return out;
}

extern "C"
{
    float __cdecl Atan2(float y, float x);
}

inline welding_simd::LocalM128& WeldingQuad(hkVector4q& v)
{
    return reinterpret_cast<welding_simd::LocalM128&>(v.m_vComponents);
}
inline const welding_simd::LocalM128& WeldingQuad(const hkVector4q& v)
{
    return reinterpret_cast<const welding_simd::LocalM128&>(v.m_vComponents);
}


__forceinline void hkVector4q::normalize3()
{
    welding_simd::LocalM128 p = welding_simd::_mm_mul_ps(WeldingQuad(*this), WeldingQuad(*this));
    welding_simd::LocalM128 len2 = welding_simd::_mm_add_ss(welding_simd::_mm_shuffle_ps(p, p, 0x55), p);
    len2 = welding_simd::_mm_add_ss(welding_simd::_mm_shuffle_ps(p, p, 0xaa), len2);
    welding_simd::LocalM128 e = welding_simd::_mm_rsqrt_ss(len2);
    welding_simd::LocalM128 r = welding_simd::_mm_mul_ss(welding_simd::_mm_mul_ss(welding_simd::_mm_set_ss(0.5f), e),
                          welding_simd::_mm_sub_ss(welding_simd::_mm_set_ss(3.0f), welding_simd::_mm_mul_ss(welding_simd::_mm_mul_ss(len2, e), e)));
    r = welding_simd::_mm_andnot_ps(welding_simd::_mm_cmpeq_ss(len2, welding_simd::_mm_set_ss(0.0f)), r);
    WeldingQuad(*this) = welding_simd::_mm_mul_ps(welding_simd::_mm_shuffle_ps(r, r, 0), WeldingQuad(*this));
}

__forceinline void hkVector4q::setCross(const hkVector4q& a, const hkVector4q& b)
{
    welding_simd::LocalM128 cross0 = welding_simd::_mm_mul_ps(welding_simd::_mm_shuffle_ps(WeldingQuad(a), WeldingQuad(a), 0xc9),
                               welding_simd::_mm_shuffle_ps(WeldingQuad(b), WeldingQuad(b), 0xd2));
    welding_simd::LocalM128 cross1 = welding_simd::_mm_mul_ps(welding_simd::_mm_shuffle_ps(WeldingQuad(a), WeldingQuad(a), 0xd2),
                               welding_simd::_mm_shuffle_ps(WeldingQuad(b), WeldingQuad(b), 0xc9));
    WeldingQuad(*this) = welding_simd::_mm_sub_ps(cross0, cross1);
}

__forceinline float hkVector4q::dot3(const hkVector4q& v) const
{
    welding_simd::LocalM128 p = welding_simd::_mm_mul_ps(WeldingQuad(*this), WeldingQuad(v));
    welding_simd::LocalM128 s = welding_simd::_mm_add_ss(welding_simd::_mm_shuffle_ps(p, p, 0x55), p);
    s = welding_simd::_mm_add_ss(welding_simd::_mm_shuffle_ps(p, p, 0xaa), s);
    float r;
    welding_simd::_mm_store_ss(&r, s);
    return r;
}

static __forceinline float hkAtan2(float y, float x)
{
    return Atan2(y, x);
}
void __cdecl FUN_00ddd620_triNormal(const hkVector4q& a, const hkVector4q& b, const hkVector4q& c,
                                    hkVector4q& normalOut);

// Computes the dihedral angle between two adjacent triangles via their normals and edge cross product, storing sin and cos outputs.
// @fnv 0x00ddd7e0
// src: GUESS 0x00ddd7e0 (confidence: medium)
float Object_ComputeDihedralSinCos(const hkVector4q* apVertices, float* sinOut, float* cosOut)
{
    hkVector4q nA;
    hkVector4q nB;
    FUN_00ddd620_triNormal(apVertices[0], apVertices[1], apVertices[2], nA);
    FUN_00ddd620_triNormal(apVertices[1], apVertices[0], apVertices[3], nB);

    hkVector4q edge;
    WeldingQuad(edge) = welding_simd::_mm_sub_ps(WeldingQuad(apVertices[1]), WeldingQuad(apVertices[0]));
    edge.normalize3();

    hkVector4q c;
    c.setCross(edge, nA);

    *sinOut = c.dot3(nB);
    *cosOut = nB.dot3(nA);
    return hkAtan2(*sinOut, *cosOut);
}

struct __declspec(align(16)) Row
{
    float x, y, z, w;
};
struct __declspec(align(16)) Matrix44
{
    Row row0, row1, row2, row3;
};

struct __declspec(align(16)) Item
{
    Matrix44 transform;
    int payload;
};

struct S00dde760_ScratchVector
{
    Item* elements;
    unsigned int size;
    unsigned int encodedCapacity;
    char* originalCursor;
};

extern "C" Matrix44 DAT_01268370;
extern "C" void __cdecl hkpMeshWeldingUtility_computeWeldingInfoMultiShape(const Matrix44*, int, int, S00dde760_ScratchVector*, int);

// Copies DAT_01268370 into a local Item, allocates a scratch vector from the pool, and passes it to FUN_00dddcd0.
// @fnv 0x00dde760
// src: XBOX_PDB 0x00dde760
void __cdecl hkpMeshWeldingUtility_computeWeldingInfo(int a, int aiPayload, int c, int d)
{
    Item item;
    welding_simd::_mm_store_ps(&item.transform.row0.x, welding_simd::_mm_load_ps(&DAT_01268370.row0.x));
    welding_simd::_mm_store_ps(&item.transform.row1.x, welding_simd::_mm_load_ps(&DAT_01268370.row1.x));
    welding_simd::_mm_store_ps(&item.transform.row2.x, welding_simd::_mm_load_ps(&DAT_01268370.row2.x));
    welding_simd::_mm_store_ps(&item.transform.row3.x, welding_simd::_mm_load_ps(&DAT_01268370.row3.x));
    item.payload = aiPayload;
    S00dde760_ScratchVector vector;
    vector.elements = 0;
    vector.size = 0;
    vector.encodedCapacity = 0x80000000;
    hkMemoryRouter* poolState = hkMemoryRouter_getInstance();
    char* cursor = reinterpret_cast<char*&>(poolState->m_stack.m_next.m_storage);
    reinterpret_cast<char*&>(poolState->m_stack.m_next.m_storage) = cursor + 0x80;
    vector.elements = reinterpret_cast<Item*>(cursor);
    vector.encodedCapacity = 0x80000001;
    vector.originalCursor = cursor;
    poolState = hkMemoryRouter_getInstance();
    if (vector.size == (vector.encodedCapacity & 0x3fffffff))
    {
        ResizeAudioStream(reinterpret_cast<hkMemoryAllocator*>(poolState->m_heap), &vector, 0x50);
    }
    Item* destination = vector.elements + vector.size;
    if (destination != 0)
        reinterpret_cast<FUN_00ddea00_cls*>(destination)
            ->CopyFromSource(reinterpret_cast<const FUN_00ddea00_src*>(&item));
    ++vector.size;
    hkpMeshWeldingUtility_computeWeldingInfoMultiShape(&DAT_01268370, a, c, &vector, d);
    char* finalCursor = vector.originalCursor;
    if (finalCursor == reinterpret_cast<char*>(vector.elements))
        vector.size = 0;
    reinterpret_cast<char*&>(hkMemoryRouter_getInstance()->m_stack.m_next.m_storage) = finalCursor;
    poolState = hkMemoryRouter_getInstance();
    hkMemoryAllocator* currentAllocator = reinterpret_cast<hkMemoryAllocator*>(poolState->m_heap);
    vector.size = 0;
    if ((vector.encodedCapacity & 0x80000000u) == 0)
        currentAllocator->bufFree(vector.elements, (vector.encodedCapacity & 0x3fffffff) * 0x50);
}


template <>
void hkArrayBase<S_00ddeab0_Elem>::_spliceInto(hkMemoryAllocator& kSharedAlloc, int index, int numdel, const S_00ddeab0_Elem* apElems, int aiNumInsert)
{
    void* alloc = &kSharedAlloc;
    int newsize = m_iElementCount - numdel + aiNumInsert;
    unsigned int numtomove = m_iElementCount - index - numdel;
    S_00ddeab0_GrowArrayCapacity(*this, alloc, newsize);
    hkMemUtil_memMove(&m_data[index + aiNumInsert], &m_data[index + numdel], numtomove * 12);
    S_00ddeab0_Elem* dst = m_data + index;
    for (int i = 0; i < aiNumInsert; ++i)
    {
        new (&dst[i]) S_00ddeab0_Elem(apElems[i]);
    }
    m_iElementCount = newsize;
}