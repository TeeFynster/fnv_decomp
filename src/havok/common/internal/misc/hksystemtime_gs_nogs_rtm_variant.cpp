#include <xmmintrin.h>
typedef ::__m128 LocalM128;
// src/havok/common/internal/misc/hksystemtime_gs_nogs_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/misc/hksystemtime.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/havok/common/internal/misc/hksystemtime.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/misc/hksystemtime.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" __int64 __cdecl __time64(__int64*);
int Hksystemtime_Time64_Thunk(void);

#include <math.h>
typedef ::__m128 LocalM128;
extern "C"
{
    LocalM128 _mm_setzero_ps();
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
    float _mm_cvtss_f32(LocalM128);
    void _mm_store_ss(float*, LocalM128);
    void _mm_store_ps(float*, LocalM128);
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_load_ss(const float*);
}

// ---- stand-ins for the analysed image's types
struct __declspec(align(16)) FNV_Vec4
{
    float x, y, z, w;
};
struct E29Src
{
    int idx[4];
    int n;
    static __forceinline void* operator new(size_t, void* place) throw()
    {
        return place;
    }
    static __forceinline void operator delete(void*, void*) throw()
    {}
    __forceinline E29Src(int index) throw()
    {
        idx[0] = index;
        idx[1] = 0;
        idx[2] = 0;
        idx[3] = 0;
        n = 1;
    }
    __forceinline E29Src() throw()
    {
        for (int x = 0; x < 4; x++)
            idx[x] = 0;
        n = 0;
    }
};
struct E29SrcList
{
    E29Src* data;
    int count;
    int cap;
    void* mem;
};

struct E29Item
{
    LocalM128 a;
    LocalM128 b;
    char flag20;
    int val24;
};
struct E29Out1
{
    E29Item item;
    void* ptr30;
    int one34;
    int zero38;
    char unk3c;
    char flag3d;
};
struct E29Out2
{
    E29Item items[4];
    int count;
    char flagC4;
    void* ptrs[4];
    int unkD8;
    int unkDC;
    int zeros[4];
    int unkF0;
};

struct FNV_MemObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Release(void* p, int size);  // vtable slot 4 (+0x10)
};

struct FNV_Ctx
{
    void* cur;  // +0x00 bump pointer
    int pad0;
    int pad1;
    int pad2;
    FNV_MemObj* obj;  // +0x10
};

extern "C" FNV_Ctx* hkMemoryRouter_getInstance() throw();

// ---- shell helpers
struct FUN_00e29920_shell;
extern "C" bool Object_ProcessAndReturnValue_00e29920(FNV_Vec4*, FNV_Vec4*, FNV_Vec4*, FNV_Vec4*, FNV_Vec4*, FNV_Vec4*, float, float) throw();
extern "C" void Runtime_ProcessEntries_00e29a10(E29SrcList*, const LocalM128*, const LocalM128*, char*, E29Out1*, int*, E29Out2*, int*) throw();

static __forceinline LocalM128 dot3(LocalM128 a, LocalM128 b)
{
    LocalM128 q = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q));
}
// src: GUESS 0x00e29920 (confidence: low)
extern "C" __declspec(noinline) bool Object_ProcessAndReturnValue_00e29920(FNV_Vec4* a, FNV_Vec4* b, FNV_Vec4* n, FNV_Vec4* a2, FNV_Vec4* b2,
                                                  FNV_Vec4* n2, float thresh, float limit) throw()
{
    float dot;
    _mm_store_ss(&dot, dot3(*(LocalM128*)n, *(LocalM128*)n2));
    if (dot < thresh)
        return false;
    LocalM128 d1 = _mm_sub_ps(*(LocalM128*)a2, *(LocalM128*)a);
    LocalM128 d2 = _mm_sub_ps(*(LocalM128*)b2, *(LocalM128*)b);
    float distance1;
    _mm_store_ss(&distance1, dot3(d1, d1));
    if (distance1 > limit)
        return false;
    float distance2;
    _mm_store_ss(&distance2, dot3(d2, d2));
    return !(distance2 > limit);
}

static __forceinline LocalM128 normalizeVector(FNV_Vec4& result, LocalM128 value)
{
    LocalM128 q = _mm_mul_ps(value, value);
    LocalM128 y = _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q);
    LocalM128 len = _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), y);
    LocalM128 inv = _mm_rsqrt_ss(len);
    LocalM128 scale = _mm_shuffle_ps(inv, inv, 0);
    LocalM128 distance = _mm_mul_ss(len, scale);
    _mm_store_ps(&result.x, _mm_mul_ps(scale, value));
    return distance;
}

// @fnv 0x00e2a010
// src: XBOX_PDB 0x00e2a010
void hkTreeBundleRayCastUtil_autoBundleScanAll(int corner, FNV_Vec4* A, FNV_Vec4* B, int n, float angle, float scale, char* a7, E29Out1* a8, int* a9,
                  E29Out2* a10, int* a11)
{
    float thresh = (float)fabs((float)cos((double)angle));
    E29SrcList list;
    list.count = 0;
    FNV_Ctx* ctx = hkMemoryRouter_getInstance();
    E29Src* recs = (E29Src*)ctx->cur;
    ctx->cur = (char*)recs + ((n * 5 * 4 + 0x7f) & ~0x7f);
    int cap = n | 0x80000000;
    list.data = recs;
    list.cap = cap;
    list.mem = recs;
    FNV_Vec4* pa = A;
    int i = 0;
    if (n > 0)
    {
        LocalM128 zero = _mm_setzero_ps();
        E29Src* cursor = recs;
        int off = (char*)B - (char*)A;
        do
        {
            FNV_Vec4 va = *pa;
            FNV_Vec4 vb = *(FNV_Vec4*)((char*)pa + off);
            LocalM128 delta = _mm_sub_ps(*(LocalM128*)&vb, *(LocalM128*)&va);
            int bits = _mm_movemask_ps(_mm_cmplt_ps(delta, zero));
            if ((bits & 4) + (bits & 2) + (bits & 1) != corner)
                goto next;
            FNV_Vec4 nrm1;
            float dist;
            _mm_store_ss(&dist, normalizeVector(nrm1, delta));
            float power = pow(dist, 2.0f);
            LocalM128 ang = _mm_load_ss(&power);

            {
                for (int k = 0; k < list.count; k++)
                {
                    E29Src* rec = &recs[k];
                    if (rec->n >= 4)
                        continue;
                    for (int j = 0; j < 1; j++)
                    {
                        int idx = rec->idx[j];
                        FNV_Vec4 va2 = A[idx];
                        FNV_Vec4 vb2 = B[idx];
                        LocalM128 d2 = _mm_sub_ps(*(LocalM128*)&vb2, *(LocalM128*)&va2);
                        FNV_Vec4 nrm2;
                        normalizeVector(nrm2, d2);
                        float sc;
                        _mm_store_ss(&sc, _mm_mul_ss(ang, _mm_load_ss(&scale)));
                        if (Object_ProcessAndReturnValue_00e29920(&va, &vb, &nrm1, &va2, &vb2, &nrm2, thresh, sc))
                        {
                            rec->idx[rec->n] = i;
                            rec->n++;
                            goto next;
                        }
                    }
                }
            }
            {
                E29Src tmp;
                tmp.idx[tmp.n++] = i;
                new (cursor) E29Src(tmp);
                list.count++;
                cursor++;
            }
        next:
            i++;
            pa++;
        } while (i < n);
    }
    Runtime_ProcessEntries_00e29a10(&list, (const LocalM128*)A, (const LocalM128*)B, a7, a8, a9, a10, a11);
    hkMemoryRouter_getInstance()->cur = recs;
    FNV_Ctx* holder = hkMemoryRouter_getInstance();
    FNV_MemObj* allocator = holder->obj;
    if ((list.cap & 0x80000000) == 0)
        allocator->Release(recs, (list.cap & 0x3fffffff) * 5 * 4);
}
