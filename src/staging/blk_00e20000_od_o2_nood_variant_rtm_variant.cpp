// src/staging/blk_00e20000_od_o2_nood_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e20000_od_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include <windows.h>
#include "../../include/hkMonitorStream.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkArray.h"
#include "../../include/hkMemoryRouter.h"

// src/staging/blk_00e20000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00e20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00e20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
// Exe 0x00e29b80 FUN_00e29b80: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; } __m128, LocalM128;
extern "C" {
LocalM128 _mm_mul_ps(LocalM128,LocalM128);
LocalM128 _mm_mul_ss(LocalM128,LocalM128);
LocalM128 _mm_add_ss(LocalM128,LocalM128);
LocalM128 _mm_sub_ps(LocalM128,LocalM128);
LocalM128 _mm_sub_ss(LocalM128,LocalM128);
LocalM128 _mm_shuffle_ps(LocalM128,LocalM128,int);
LocalM128 _mm_rsqrt_ss(LocalM128);
LocalM128 _mm_set_ss(float);
LocalM128 _mm_cmpeq_ss(LocalM128,LocalM128);
LocalM128 _mm_andnot_ps(LocalM128,LocalM128);
void _mm_store_ss(float*,LocalM128);
void _ReadWriteBarrier();
}
struct Vertex { LocalM128 position; LocalM128 supportA; LocalM128 supportB; int flags; int unk34; int unk38; int unk3c; };
struct Face;
struct Edge {
    Vertex* vertex;
    Edge* next;
    Edge* opposite;
    Face* face;
};
struct Face {
    LocalM128 normal;
    Edge edges[3];
    float distance;
    int flags;
    int unk48;
    int unk4c;
    __declspec(noinline) Vertex* ComputePlane();
};
extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;
static __forceinline LocalM128 dot3(LocalM128 a, LocalM128 b) {
    LocalM128 v = _mm_mul_ps(a,b);
    return _mm_add_ss(_mm_shuffle_ps(v,v,0xaa), _mm_add_ss(_mm_shuffle_ps(v,v,0x55),v));
}
Vertex* Face::ComputePlane() {
    Vertex* first = edges[0].vertex;
    LocalM128 a = _mm_sub_ps(first->position,edges[1].vertex->position);
    LocalM128 b = _mm_sub_ps(edges[1].vertex->position,edges[2].vertex->position);
    LocalM128 n = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a,a,0xc9),_mm_shuffle_ps(b,b,0xd2)),_mm_mul_ps(_mm_shuffle_ps(a,a,0xd2),_mm_shuffle_ps(b,b,0xc9)));
    LocalM128 len = dot3(n,n);
    LocalM128 inv = _mm_rsqrt_ss(len);
    LocalM128 scale = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248),inv), _mm_sub_ss(_mm_set_ss(DAT_01017718), _mm_mul_ss(_mm_mul_ss(len,inv),inv)));
    scale = _mm_andnot_ps(_mm_cmpeq_ss(len,_mm_set_ss(DAT_01011d78)), scale);
    normal = n;
    _ReadWriteBarrier();
    normal = _mm_mul_ps(n,_mm_shuffle_ps(scale,scale,0));
    float d;
    _mm_store_ss(&d,dot3(normal,first->position));
    distance = d;
    return first;
}
struct InitEntry { int vertexOffset; int faceOffset; int edgeOffset; };
extern InitEntry DAT_010ed0f0[];
struct Hull {
    int unk00; int unk04; int unk08; int unk0c;
    int faceCount; int unk14; int unk18; int unk1c;
    Vertex vertices[55];
    Face* freeFaces[100];
    Face faces[4];
    void ProcessEntries_00e2d440();
};
struct E29Src { int idx[4]; int n; };
struct E29SrcList { E29Src* data; int count; };
struct E29Item { LocalM128 a; LocalM128 b; char flag20; int val24; };
struct E29Out1 { E29Item item; void* ptr30; int one34; int zero38; char unk3c; char flag3d; };
struct E29Out2 { E29Item items[4]; int count; char flagC4; void* ptrs[4]; int unkD8; int unkDC; int zeros[4]; int unkF0; };
void Runtime_ProcessEntries_00e29a10(E29SrcList* src, const LocalM128* posA, const LocalM128* posB, char* base, E29Out1* out1, int* outCount1, E29Out2* out2, int* outCount2);
inline void* operator new(unsigned int, void* p) { return p; }
void __cdecl ResizeAudioStream(void* mem, void* array, int sizeOfElement);
struct __declspec(align(16)) Key_e3a1 {
    float m_ax, m_ay, m_az, m_aw;
    float m_bx, m_by, m_bz, m_bw;
    Key_e3a1* InitializeFields_00e39e50();
};
struct Track_e3a1 {
    int unk00, unk04;
    int m_numKeys;
    int m_pRayCursor;
    hkArray<Key_e3a1> m_keys;
    void hkpTyremarksWheel_setNumPoints(int numKeys);
};
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
extern "C" void _mm_store_ps(float*, LocalM128);
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
extern int DAT_010dbacc, DAT_010dbad8, DAT_010dbae4, DAT_010dbaf8;
extern int DAT_010ccfac, DAT_010ccfa0, DAT_010ccf8c, DAT_010c3bb8;
extern void* DAT_011b3830[];
void __cdecl Runtime_UpdateState_00d1bb50(void*, void*, void*, void*, void*, void*, void*, void*, void*, int) throw();
void __cdecl hkAabbTreeQueryUtils_ForwardCall_00d1d490(void*, void*, int, void*, void*, void*) throw();
typedef LocalM128 FourFloatVector;
__forceinline FourFloatVector packFractions(float x,float y,float z,float w) { FourFloatVector v; v.m128_f32[0]=x; v.m128_f32[1]=y; v.m128_f32[2]=z; v.m128_f32[3]=w; return v; }
struct RaySource {
    FourFloatVector from, to;
    unsigned char enable; unsigned char unk21; unsigned short unk22;
    unsigned filter;
    unsigned unk28, unk2c;
};
struct RayBatch {
    RaySource rays[4];
    unsigned type;
    unsigned char flag; unsigned char unkc5; unsigned short unkc6;
    void* filters[4];
    unsigned unkd8, unkdc;
    void* hits[4];
};
struct LocalRay {
    FourFloatVector from, to;
    unsigned char enable; unsigned char unk21; unsigned short unk22;
    unsigned filter;
    unsigned unk28, unk2c;
    void* userFilter;
    int one; void* zero;
    unsigned char hit, flag; unsigned short unk3e;
    __forceinline void assign(const RaySource& s) { from=s.from; to=s.to; enable=s.enable; filter=s.filter; }
};
struct RayCollectorBase {
    void* vtable;
    int mode;
    float fraction;
    unsigned char hit; unsigned char unk0d; unsigned short unk0e;
};
struct Collector {
    void* vt0; void* vt1; void* vt2;
    RayCollectorBase ray;
    LocalRay* input; LocalRay* input2;
    void* filter; void* filter2;
    unsigned unk2c;
    FourFloatVector normal;
    FourFloatVector point;
    unsigned unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    unsigned unk70, unk74, unk78, unk7c;
    __forceinline LocalRay* setup(LocalRay* r, const RaySource& source, void* f, int m, unsigned char flag) {
        r->userFilter=f; filter=f; filter2=f;
        r->from=source.from; r->to=source.to;
        r->enable=source.enable; r->filter=source.filter;
        r->flag=flag; r->one=1; r->zero=0;
        input2=r; input=r;
ray.mode=m;         return r;
    }
    __forceinline void init() {
        ray.fraction = 1.0f; vt0 = &DAT_010dbaf8; vt1 = &DAT_010dbae4; vt2 = &DAT_010dbad8; ray.vtable = &DAT_010dbacc;
        unk50 = 0; unk54 = 0; unk60 = 0; ray.hit = 0;
    }
};
struct Bundle {
    FourFloatVector fromX, fromY, fromZ, toX, toY, toZ;
    void* dispatch;
};
struct FractionValues { float x,y,z,w; };
struct FractionArg { FourFloatVector* ptr; };
struct Owner { unsigned unk00, unk04, unk08, unk0c; void* context; };
void __cdecl Runtime_ProcessEntries_00e2b510(Owner* owner, RayBatch* input, int mode, FourFloatVector& fractions);
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
unsigned __int64 __cdecl __rdtsc(void);
class ScrapAllocator
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* Alloc(int& aiSize);
    virtual void Free(void* p, unsigned int size);
};
class JobTarget
{
public:
    void hkSemaphore_acquire();
};
struct __declspec(align(16)) AutoJob
{
    unsigned char m_cType;
    unsigned char m_c01;
    unsigned char m_c02;
    unsigned char m_c03;
    unsigned short m_sSize;
    short m_s06;
    int unk08;
    int unk0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int unk1C;
    int* m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    float m_f38;
    float m_f3C;
    int m_i40;
    int m_i44;
    int unk48;
    int m_i4C;
    int unk50;
    int m_i54;
    int m_i58;
    JobTarget* m_p5C;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6C;
};
__forceinline void InitJob(AutoJob& j)
{
    j.m_cType = 7;
    j.m_c01 = 3;
    j.m_c02 = 2;
    j.m_sSize = 0x70;
    j.m_s06 = -1;
    j.m_i10 = 0;
    j.m_i18 = 0;
    j.m_c02 = 1;
    j.m_i14 = 0;
    j.m_i64 = 0;
    j.m_i68 = 0;
}
struct JobSource
{
    DWORD unk00, unk04, unk08, unk0C;
    JobTarget* m_p10;
    int m_i14;
    int unk18;
    int m_i1C;
    int unk20;
    int m_i24;
    int unk28;
    int m_i2C;
    int unk30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
};
class JobQueue
{
public:
    void AddObjectCopy(AutoJob* pJob, int iFlag);
};
class JobWaiter
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void Start(JobQueue* m_pPrimaryTaskProcessor, int iType);
    virtual void Wait();
};
struct SplitOut
{
    int unk00, unk04, unk08, unk0C;
};
struct SplitResult
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
};
void __cdecl Object_ProcessEntries_00e29b80(int a, int b, int n, void* p1, void* p2, void* p3, SplitResult* pOut);
__forceinline void ProfMark(const char* pName)
{
    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = pName;
        { unsigned int ticks;
__asm {
    rdtsc
    mov dword ptr[ticks], eax
}
pRec->m_time0 = ticks; }
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }
}
__forceinline void ProfMark2(const char* pName, const char* pName2)
{
    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = pName;
        *reinterpret_cast<const char**>(pRec + 1) = pName2;
        { unsigned int ticks;
__asm {
    rdtsc
    mov dword ptr[ticks], eax
}
pRec->m_time0 = ticks; }
        pBuf->m_end.m_storage = reinterpret_cast<char*>(reinterpret_cast<hkMonitorStream::TimerCommand*>(reinterpret_cast<char*>(pRec + 1) + sizeof(const char*)));
    }
}
template <class T> __forceinline T* BufAlloc(ScrapAllocator* pAlloc, int& n)
{
    int bytes = n * sizeof(T);
    T* p = (T*)pAlloc->Alloc(bytes);
    n = bytes / (int)sizeof(T);
    return p;
}
template <class T> __forceinline void ArrInit(T*& rData, unsigned int& rCap, int n)
{
    ScrapAllocator* pAlloc = reinterpret_cast<ScrapAllocator*>(hkMemoryRouter::get().m_heap);
    int cap = n;
    rData = cap ? BufAlloc<T>(pAlloc, cap) : 0;
    rCap = cap ? cap : 0x80000000;
}
template <class T> __forceinline void ArrFree(T* pData, unsigned int uiCap)
{
    ScrapAllocator* pAlloc = reinterpret_cast<ScrapAllocator*>(hkMemoryRouter::get().m_heap);
    if ((uiCap & 0x80000000) == 0)
        pAlloc->Free(pData, (uiCap & 0x3fffffff) * sizeof(T));
}
template <class T> __forceinline void ArrClearFree(hkArray<T>& arr)
{
    ScrapAllocator* pAlloc = reinterpret_cast<ScrapAllocator*>(hkMemoryRouter::get().m_heap);
    unsigned int cap = arr.m_iCapacityState;
    arr.m_iElementCount = 0;
    if ((cap & 0x80000000) == 0)
        pAlloc->Free(arr.m_data, (cap & 0x3fffffff) * sizeof(T));
    arr.m_data = 0;
    arr.m_iCapacityState = 0x80000000;
}
void __cdecl hkTreeBundleRayCastUtil_startWorldRayCastWithAutoBundleJobs(int a, int b, int n, float f1, float f2, JobSource* pSrc, JobQueue* m_pPrimaryTaskProcessor, JobWaiter* pWaiter, int iParam, bool bAuto);
extern "C" LocalM128 _mm_max_ps(LocalM128, LocalM128);
namespace SplineMax {
// Kept POD: FUN_00e314c0 returns this vector by value through the hidden pointer.
struct MaxVec4 { LocalM128 value; };
typedef hkArray<MaxVec4> Points;
}

extern "C" LocalM128 _mm_cmplt_ps(LocalM128 _A, LocalM128 _B);
extern "C" int _mm_movemask_ps(LocalM128 _A);
extern "C" LocalM128 _mm_setzero_ps(void);
#include <math.h>
extern "C" {
LocalM128 _mm_setzero_ps();
LocalM128 _mm_cmplt_ps(LocalM128,LocalM128);
int _mm_movemask_ps(LocalM128);
}

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter::getInstance().heap());
}

typedef LocalM128 S00e29b80_QuadReal;
typedef float hkReal;
typedef int hkBool32;

class S00e29b80_SimdReal
{
public:
    S00e29b80_SimdReal(const S00e29b80_QuadReal& x) : m_vValue(x) {}
    S00e29b80_SimdReal(hkReal x) { m_vValue = _mm_load_ss(&x); }
    S00e29b80_SimdReal() {}
    operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline const S00e29b80_QuadReal& getQuad() const { return m_vValue; }
private:
    S00e29b80_QuadReal m_vValue;
};

class S00e29b80_Comparison
{
public:
    enum S00e29b80_Mask { MASK_NONE = 0, MASK_X = 1, MASK_Y = 2, MASK_Z = 4, MASK_W = 8 };
    __forceinline hkBool32 anyIsSet(S00e29b80_Mask m) const { return _mm_movemask_ps(m_uiMask) & m; }
    S00e29b80_QuadReal m_uiMask;
};

class S00e29b80_Vector4
{
public:
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void setSub4(const S00e29b80_Vector4& v0, const S00e29b80_Vector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline S00e29b80_SimdReal dot3(const S00e29b80_Vector4& a) const
    {
        S00e29b80_QuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        S00e29b80_QuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S00e29b80_Comparison compareLessThanZero4() const
    {
        S00e29b80_Vector4 zero; zero.setZero4();
        S00e29b80_Comparison m; m.m_uiMask = _mm_cmplt_ps(m_vComponents, zero.m_vComponents);
        return m;
    }
    __forceinline S00e29b80_SimdReal fastNormalizeWithLength3()
    {
        S00e29b80_QuadReal len2 = this->dot3(*this).getQuad();
        S00e29b80_QuadReal approx = _mm_rsqrt_ss(len2);
        approx = _mm_shuffle_ps(approx, approx, 0);
        m_vComponents = _mm_mul_ps(m_vComponents, approx);
        return _mm_mul_ss(len2, approx);
    }
    S00e29b80_QuadReal m_vComponents;
};

namespace S00e29b80_hkMath {
    inline hkReal pow(hkReal r, hkReal s) { return ::powf(r, s); }
}

template <typename T>
__forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kHeap, int iWanted)
{
    const int iHave = getCapacity();
    if (iHave < iWanted)
    {
        int iTwice = 2 * iHave;
        int iGrowTo = (iWanted < iTwice) ? iTwice : iWanted;
        hkArrayUtil::_reserve(kHeap, this, iGrowTo, sizeof(T));
    }
}

template <typename T>
__forceinline void hkArrayBase<T>::pushBackUnchecked(const T& t)
{
    T* p = m_data + m_iElementCount;
    for (int i = 0; i < 1; ++i)
    {
        p[i] = t;
    }
    m_iElementCount++;
}


// @fnv 0x00e29b80
// src: GUESS 0x00e29b80 (confidence: low)
void __cdecl Object_ProcessEntries_00e29b80(int a, int b, int numRays, void* p1, void* p2, void* p3, SplitResult* pOut)
{
    for (int i = 0; i < numRays; i++)
    {
        S00e29b80_Vector4& v = ((S00e29b80_Vector4*)p1)[i];
        v.setSub4(((const S00e29b80_Vector4*)b)[i], ((const S00e29b80_Vector4*)a)[i]);
        ((S00e29b80_SimdReal*)p2)[i] = v.fastNormalizeWithLength3();
        ((S00e29b80_SimdReal*)p2)[i] = S00e29b80_hkMath::pow(((S00e29b80_SimdReal*)p2)[i], 2.0f);
    }

    for (int i = 0; i < 8; i++)
    {
        ((int*)pOut)[i] = 0;
        ((hkArray<int>*)p3)[i].reserve(numRays);
    }

    for (int i = 0; i < numRays; i++)
    {
        S00e29b80_Comparison c = ((S00e29b80_Vector4*)p1)[i].compareLessThanZero4();
        int octIdx = 0;
        octIdx += c.anyIsSet(S00e29b80_Comparison::MASK_X) ? 1 : 0;
        octIdx += c.anyIsSet(S00e29b80_Comparison::MASK_Y) ? 2 : 0;
        octIdx += c.anyIsSet(S00e29b80_Comparison::MASK_Z) ? 4 : 0;
        ((int*)pOut)[octIdx]++;
        ((hkArray<int>*)p3)[octIdx].pushBackUnchecked(i);
    }
}

#include <math.h>
extern "C" {
LocalM128 _mm_add_ps(LocalM128, LocalM128);
LocalM128 _mm_xor_ps(LocalM128, LocalM128);
LocalM128 _mm_load_ss(const float*);
LocalM128 _mm_setzero_ps(void);
}

typedef float hkReal;
typedef LocalM128 hkQuadReal;

class S2db70_SimdReal
{
public:
    S2db70_SimdReal(const hkQuadReal& x) : m_vValue(x) {}
    S2db70_SimdReal(hkReal x) { m_vValue = _mm_load_ss(&x); }
    __forceinline hkQuadReal broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const hkQuadReal& getQuad() const { return m_vValue; }
private:
    hkQuadReal m_vValue;
};
typedef const S2db70_SimdReal& S2db70_SimdRealParameter;

extern const LocalM128 DAT_010c44d0;
extern float DAT_0104e148;

class S2db70_Vector4
{
public:
    hkQuadReal m_vComponents;
    inline void operator=(const S2db70_Vector4& v) { m_vComponents = v.m_vComponents; }
    inline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    inline void setAdd4(const S2db70_Vector4& v0, const S2db70_Vector4& v1) { m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents); }
    inline void setSub4(const S2db70_Vector4& v0, const S2db70_Vector4& v1) { m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents); }
    inline void mul4(S2db70_SimdRealParameter s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    inline void setNeg4(const S2db70_Vector4& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0); }
    inline void setCross(const S2db70_Vector4& v0, const S2db70_Vector4& v1)
    {
        hkQuadReal cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        hkQuadReal cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    inline S2db70_SimdReal dot3(const S2db70_Vector4& a) const
    {
        hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    inline S2db70_SimdReal lengthInverse3() const
    {
        const hkQuadReal half = _mm_set_ss(0.5f);
        const hkQuadReal three = _mm_set_ss(3.0f);
        const hkQuadReal zero = _mm_set_ss(0.0f);
        const hkQuadReal len2 = this->dot3(*this).getQuad();
        const hkQuadReal len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const hkQuadReal approx = _mm_rsqrt_ss(len2);
        const hkQuadReal refined = _mm_mul_ss(
            _mm_mul_ss(half, approx),
            _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    inline void normalize3()
    {
        hkQuadReal lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    inline hkReal& operator()(int a) { return reinterpret_cast<hkReal*>(&m_vComponents)[a]; }
    inline const hkReal& operator()(int a) const { return reinterpret_cast<const hkReal*>(&m_vComponents)[a]; }
};

struct S2db70_Transform { S2db70_Vector4 m_kColumn0, m_kColumn1, m_kColumn2, m_vTranslation; };
extern S2db70_Transform DAT_01268370;

struct S2db70_Shape
{
    virtual void unk00();
    virtual void GetSupportPoint(const S2db70_Vector4& dir, S2db70_Vector4& out) const;
};

struct S2db70_Sample
{
    S2db70_Vector4 m_vFirstVector;
    S2db70_Vector4 m_vSecondVector;
    S2db70_Vector4 m_vHitNormal;
    hkReal& getDistance() { return m_vHitNormal(3); }
};

struct S2db70_Out
{
    S2db70_Vector4 m_vPointOnShapeA;
    S2db70_Vector4 m_vPointOnShapeB;
    hkReal m_fClosestPointDistanceSquared;
};

static __forceinline hkReal S2db70_fabs(hkReal r) { return (float)fabs(r); }

static __forceinline void S2db70_calculatePerpendicularVector(const S2db70_Vector4& vectorIn, S2db70_Vector4& biVectorOut)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = S2db70_fabs(vectorIn(0));
    hkReal a1 = S2db70_fabs(vectorIn(1));
    hkReal a2 = S2db70_fabs(vectorIn(2));

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }

    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    biVectorOut.setZero4();
    biVectorOut(ok1) = vectorIn(ok2);
    biVectorOut(ok2) = -vectorIn(ok1);
}

// src: GUESS 0x00e2da40 (confidence: low)
static __declspec(noinline) void hkTransform_UpdateFields_00e2da40(const S2db70_Shape* shapeA, const S2db70_Shape* shapeB, const S2db70_Transform& aTb, const S2db70_Vector4& dir, S2db70_Sample& sample)
{
    S2db70_Vector4 negDir; negDir.setNeg4(dir);
    S2db70_Vector4 dirInB;
    dirInB.m_vComponents = _mm_add_ps(_mm_add_ps(
        _mm_mul_ps(_mm_shuffle_ps(dir.m_vComponents, dir.m_vComponents, 0x55), aTb.m_kColumn1.m_vComponents),
        _mm_mul_ps(_mm_shuffle_ps(dir.m_vComponents, dir.m_vComponents, 0x00), aTb.m_kColumn0.m_vComponents)),
        _mm_mul_ps(_mm_shuffle_ps(dir.m_vComponents, dir.m_vComponents, 0xaa), aTb.m_kColumn2.m_vComponents));
    S2db70_Vector4 pointA;
    shapeA->GetSupportPoint(negDir, pointA);
    S2db70_Vector4 pointB;
    shapeB->GetSupportPoint(dirInB, pointB);
    S2db70_Vector4 pointBinA;
    pointBinA.m_vComponents = _mm_add_ps(_mm_add_ps(
        _mm_mul_ps(_mm_shuffle_ps(pointB.m_vComponents, pointB.m_vComponents, 0x55), aTb.m_kColumn1.m_vComponents),
        _mm_mul_ps(_mm_shuffle_ps(pointB.m_vComponents, pointB.m_vComponents, 0x00), aTb.m_kColumn0.m_vComponents)),
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(pointB.m_vComponents, pointB.m_vComponents, 0xaa), aTb.m_kColumn2.m_vComponents), aTb.m_vTranslation.m_vComponents));
    S2db70_Vector4 diff; diff.setSub4(pointA, pointBinA);
    hkReal dist;
    _mm_store_ss(&dist, diff.dot3(dir).getQuad());
    if (sample.getDistance() - dist < 0.0f)
    {
        sample.m_vHitNormal = dir;
        sample.getDistance() = dist;
        sample.m_vFirstVector = pointA;
        sample.m_vSecondVector = pointB;
    }
}

// @fnv 0x00e2db70
// src: GUESS 0x00e2db70 (confidence: medium)
extern "C" void Geometry_RefineClosestPointsByDirectionSampling(const S2db70_Shape* shapeA, const S2db70_Shape* shapeB, const S2db70_Transform& aTb,
                  S2db70_Vector4& pointAinA, S2db70_Vector4& pointBinB, S2db70_Out& out)
{
    S2db70_Sample sample;
    sample.getDistance() = DAT_0104e148;

    const S2db70_Vector4* axis = &DAT_01268370.m_kColumn0;
    for (int i = 0; i < 3; i++)
    {
        S2db70_Vector4 dir = *axis;
        axis++;
        hkTransform_UpdateFields_00e2da40(shapeA, shapeB, aTb, dir, sample);
        dir.setNeg4(dir);
        hkTransform_UpdateFields_00e2da40(shapeA, shapeB, aTb, dir, sample);
    }

    for (hkReal eps = 1.0f; eps > 0.001f; )
    {
        eps *= 0.99f;
        S2db70_Vector4 perp;
        S2db70_calculatePerpendicularVector(sample.m_vHitNormal, perp);
        perp.normalize3();
        S2db70_Vector4 cross; cross.setCross(sample.m_vHitNormal, perp);
        perp.mul4(eps);
        cross.mul4(eps);

        S2db70_Vector4 d0; d0.setAdd4(sample.m_vHitNormal, perp);
        S2db70_Vector4 d1; d1.setSub4(sample.m_vHitNormal, perp);
        S2db70_Vector4 d2; d2.setAdd4(sample.m_vHitNormal, cross);
        S2db70_Vector4 d3; d3.setSub4(sample.m_vHitNormal, cross);
        S2db70_SimdReal invLen = d0.lengthInverse3();
        d0.mul4(invLen);
        d1.mul4(invLen);
        d2.mul4(invLen);
        d3.mul4(invLen);

        hkTransform_UpdateFields_00e2da40(shapeA, shapeB, aTb, d0, sample);
        hkTransform_UpdateFields_00e2da40(shapeA, shapeB, aTb, d1, sample);
        hkTransform_UpdateFields_00e2da40(shapeA, shapeB, aTb, d2, sample);
        hkTransform_UpdateFields_00e2da40(shapeA, shapeB, aTb, d3, sample);
        eps *= 0.5f;
    }

    pointAinA = sample.m_vFirstVector;
    pointBinB = sample.m_vSecondVector;
    out.m_vPointOnShapeA = sample.m_vHitNormal;
    out.m_vPointOnShapeB = sample.m_vFirstVector;
    out.m_fClosestPointDistanceSquared = sample.getDistance();
}

struct AvgSrc
{
    const float* values;
    int count;
};

extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ps(const float*);

// @fnv 0x00e31410
// src: GUESS 0x00e31410 (confidence: low)
LocalM128* Runtime_ProcessEntries_00e31410(LocalM128* out, AvgSrc* s)
{
    int m = s->count;
    LocalM128 sum = _mm_setzero_ps();
    *out = sum;
    int n = m;
    if (m > 0)
    {
        const float* p = s->values;
        do
        {
            sum = _mm_add_ps(_mm_load_ps(p), sum);
            p += 4;
            --m;
        } while (m != 0);
        *out = sum;
    }
    _ReadWriteBarrier();
    float inv = 1.0f / (float)n;
    LocalM128 t = _mm_load_ss(&inv);
    *out = _mm_mul_ps(_mm_shuffle_ps(t, t, 0), *out);
    return out;
}

extern "C" {
LocalM128 _mm_div_ss(LocalM128, LocalM128);
LocalM128 _mm_add_ps(LocalM128, LocalM128);
}
extern float DAT_01012068;
extern float DAT_01011d78;
static __forceinline LocalM128 inverseSpan(LocalM128 a, LocalM128 b) { return _mm_div_ss(_mm_load_ss(&DAT_01012068),_mm_add_ss(a,b)); }
// @fnv 0x00e33670
// src: GUESS 0x00e33670 (confidence: low)
void Runtime_ComputeValues_00e33670(float t, int unused, const float* knots, const LocalM128* ctrl, LocalM128* out)
{
    float f;
    f = t - knots[1];
    LocalM128 left1 = _mm_load_ss(&f);
    f = knots[2] - t;
    LocalM128 right1 = _mm_load_ss(&f);
    LocalM128 inv = inverseSpan(right1,left1);
    LocalM128 n01 = _mm_mul_ss(right1, inv);
    f = t - knots[0];
    LocalM128 left2 = _mm_load_ss(&f);
    f = knots[3] - t;
    LocalM128 right2 = _mm_load_ss(&f);
    LocalM128 zero = _mm_load_ss(&DAT_01011d78);
    LocalM128 a = _mm_div_ss(_mm_add_ss(zero,n01), _mm_add_ss(right1,left2));
    LocalM128 b0 = _mm_add_ss(zero,_mm_mul_ss(right1,a));
    LocalM128 b1left = _mm_mul_ss(left2,a);
    LocalM128 b = _mm_div_ss(_mm_mul_ss(left1,inv), _mm_add_ss(right2,left1));
    LocalM128 b1 = _mm_add_ss(b1left,_mm_mul_ss(right2,b));
    LocalM128 b2 = _mm_mul_ss(left1,b);
    *out = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(b1,b1,0),ctrl[1]),_mm_mul_ps(_mm_shuffle_ps(b0,b0,0),ctrl[0])),_mm_mul_ps(_mm_shuffle_ps(b2,b2,0),ctrl[2]));
}
