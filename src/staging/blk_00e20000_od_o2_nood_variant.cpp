// staging/blk_00e20000_od_o2_nood_variant.cpp: Face, Hull (8 functions)
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

// Exe 0x00e2b510 FUN_00e2b510: retain this LocalM128 view; the CRT type changes the matched code.
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
// @fnv 0x00e2d440
// src: GUESS 0x00e2d440 (confidence: low)
void Hull::ProcessEntries_00e2d440() {
    faceCount = 4;
    InitEntry* init = DAT_010ed0f0;
    Face* end = faces + 4;
    for (Face* face = faces; face != end; ++face) {
        face->edges[0].next = &face->edges[1];
        face->edges[1].next = &face->edges[2];
        face->flags = 0;
        face->edges[2].next = &face->edges[0];
        for (Edge* edge = face->edges; edge < face->edges + 3; ++edge) {
            edge->face = face;
            edge->vertex = (Vertex*)((char*)vertices + init->vertexOffset);
            edge->opposite = (Edge*)((char*)&faces[0].edges[0] + init->faceOffset + init->edgeOffset);
            ++init;
        }
    }
    Face* begin = faces;
    Face* last = &faces[3];
    last->ComputePlane();
    float d;
    _mm_store_ss(&d,dot3(_mm_sub_ps(vertices[0].position,vertices[1].position),last->normal));
    if (d > 0.0f) {
        faces[2].edges[0].vertex = &vertices[1];
        faces[1].edges[0].vertex = &vertices[1];
        begin->edges[0].vertex = &vertices[1];
        last->edges[0].vertex = &vertices[0];
        faces[1].edges[1].vertex = &vertices[0];
        begin->edges[2].vertex = &vertices[0];
    }
    Face* face = begin;
    int i = 3;
    do { face->ComputePlane(); ++face; } while (--i >= 0);
}

struct E29Src { int idx[4]; int n; };
struct E29SrcList { E29Src* data; int count; };
struct E29Item { LocalM128 a; LocalM128 b; char flag20; int val24; };
struct E29Out1 { E29Item item; void* ptr30; int one34; int zero38; char unk3c; char flag3d; };
struct E29Out2 { E29Item items[4]; int count; char flagC4; void* ptrs[4]; int unkD8; int unkDC; int zeros[4]; int unkF0; };

// @fnv 0x00e29a10
// src: GUESS 0x00e29a10 (confidence: low)
void Runtime_ProcessEntries_00e29a10(E29SrcList* src, const LocalM128* posA, const LocalM128* posB, char* base, E29Out1* out1, int* outCount1, E29Out2* out2, int* outCount2)
{
    int n1 = 0;
    int n2 = 0;
    int count = src->count;
    E29Out2* o2 = out2;
    E29Out1* o1 = out1;
    for (int i = 0; i < count; ++i) {
        E29Src* s = &src->data[i];
        int n = s->n;
        if (n == 1) {
            int k = s->idx[0];
            o1->item.a = posA[k];
            o1->item.b = posB[k];
            o1->item.val24 = 0;
            o1->item.flag20 = 0;
            o1->ptr30 = base + k * 0x60;
            o1->one34 = 1;
            o1->zero38 = 0;
            o1->flag3d = 0;
            o1++;
            n1++;
        } else {
            for (int j = 0; j < n; ++j) {
                int k = s->idx[j];
                o2->items[j].a = posA[k];
                o2->items[j].b = posB[k];
                o2->items[j].val24 = 0;
                o2->items[j].flag20 = 0;
                o2->ptrs[j] = base + k * 0x60;
                o2->zeros[j] = 0;
            }
            o2->count = n;
            o2->flagC4 = 0;
            o2++;
            n2++;
        }
    }
    *outCount1 = n1;
    *outCount2 = n2;
}

namespace fnv_00e2ab00 {
// Exe 0x00e2b510 FUN_00e2b510: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; } __m128, LocalM128;
extern "C" { LocalM128 _mm_load_ps(const LocalM128*); void _mm_store_ps(LocalM128*,LocalM128); LocalM128 _mm_shuffle_ps(LocalM128,LocalM128,int); void _ReadWriteBarrier(); }

// @fnv 0x00e2ab00
// src: GUESS 0x00e2ab00 (confidence: low)
LocalM128* Object_ProcessAndReturnValue_00e2ab00(LocalM128* src, LocalM128* out1, LocalM128* out2) {
    out1[0] = src[0];
    out2[0] = src[1];
    out1[1] = src[3];
    out2[1] = src[4];
    out1[2] = src[6];
    out2[2] = src[7];

    LocalM128 d0 = src[9];
    _ReadWriteBarrier();
    LocalM128 a2 = out1[2];
    LocalM128 a0 = out1[0];
    LocalM128 d1 = src[10];
    LocalM128 a1 = out1[1];
    LocalM128 t2 = _mm_shuffle_ps(a2, d0, 0x44);
    LocalM128 t1 = _mm_shuffle_ps(a0, a1, 0xEE);
    LocalM128 t3 = _mm_shuffle_ps(a2, d0, 0xEE);
    LocalM128 t0 = _mm_shuffle_ps(a0, a1, 0x44);
    out1[0] = _mm_shuffle_ps(t0, t2, 0x88);
    out1[2] = _mm_shuffle_ps(t1, t3, 0x88);
    out1[1] = _mm_shuffle_ps(t0, t2, 0xDD);

    LocalM128 b0 = out2[0];
    LocalM128 b1 = out2[1];
    LocalM128 b2 = out2[2];
    LocalM128 u0 = _mm_shuffle_ps(b0, b1, 0x44);
    LocalM128 u1 = _mm_shuffle_ps(b0, b1, 0xEE);
    LocalM128 u2 = _mm_shuffle_ps(b2, d1, 0x44);
    LocalM128 u3 = _mm_shuffle_ps(b2, d1, 0xEE);
    out2[0] = _mm_shuffle_ps(u0, u2, 0x88);
    out2[1] = _mm_shuffle_ps(u0, u2, 0xDD);
    out2[2] = _mm_shuffle_ps(u1, u3, 0x88);
    return out1;
}
}  // namespace fnv_00e2ab00

inline void* operator new(unsigned int, void* p) { return p; }

struct __declspec(align(16)) Key_e3a1 {
    float m_ax, m_ay, m_az, m_aw;
    float m_bx, m_by, m_bz, m_bw;
    Key_e3a1* InitializeFields_00e39e50();
};

// This instantiation fetches the router before the capacity check and its heap only when growing.
template <>
__forceinline void hkArray<Key_e3a1>::pushBack(const Key_e3a1& t)
{
    hkMemoryRouter& router = hkMemoryRouter::getInstance();
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        hkArrayUtil::_reserveMore(*reinterpret_cast<hkMemoryAllocator*>(router.m_heap), this, sizeof(Key_e3a1));
    new (&m_data[m_iElementCount]) Key_e3a1(t);
    m_iElementCount++;
}

struct Track_e3a1 {
    int unk00, unk04;
    int m_numKeys;
    int m_pRayCursor;
    hkArray<Key_e3a1> m_keys;
    void hkpTyremarksWheel_setNumPoints(int numKeys);
};

// @fnv 0x00e3a1e0
// src: HAVOK_LIB 0x00e3a1e0
void Track_e3a1::hkpTyremarksWheel_setNumPoints(int numKeys)
{
    m_pRayCursor = numKeys;
    m_numKeys = 0;
    for (int i = 0; i < m_pRayCursor; i++) {
        Key_e3a1 key;
        key.InitializeFields_00e39e50();
        m_keys.pushBack(key);
    }
}

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
// @fnv 0x00e2b510
// src: GUESS 0x00e2b510 (confidence: low)
void __cdecl Runtime_ProcessEntries_00e2b510(Owner* owner, RayBatch* input, int mode, FourFloatVector& fractions) {
    if (!owner) return;
    Bundle bundle;
    Runtime_UpdateState_00d1bb50(&bundle, &input->rays[0].from, &input->rays[0].to,
        &input->rays[1].from, &input->rays[1].to, &input->rays[2].from,
        &input->rays[2].to, &input->rays[3].from, &input->rays[3].to, 15);
    LocalRay rays[4];
    rays[0].hit=0; rays[1].hit=0; rays[2].hit=0; rays[3].hit=0;
    Collector collectors[4];
    collectors[0].init(); collectors[1].init(); collectors[2].init(); collectors[3].init();
    float values[4];
    RayCollectorBase* pointers[4];
    for (int i = 0; i < 4; i++) {
        rays[i].userFilter = input->filters[i];
        collectors[i].filter = rays[i].userFilter;
        collectors[i].filter2 = rays[i].userFilter;
        rays[i].assign(input->rays[i]);
        rays[i].flag = input->flag;
        rays[i].one = 1;
        rays[i].zero = 0;
        collectors[i].ray.mode = mode;
        collectors[i].input2 = &rays[i];
        collectors[i].input = &rays[i];
        values[i] = fractions.m128_f32[i];
        pointers[i] = &collectors[i].ray;
    }
    bundle.dispatch = DAT_011b3830[input->type];
    hkAabbTreeQueryUtils_ForwardCall_00d1d490(owner, owner->context, 0, &bundle, pointers, values);
    for (int i = 0; i < 4; i++) input->hits[i] = rays[i].zero;
    fractions = _mm_setr_ps(values[0], values[1], values[2], values[3]);
    volatile Collector* p = collectors + 4;
    int n = 3;
    do {
        --p;
        p->ray.vtable = &DAT_010ccfac; p->vt2 = &DAT_010ccfa0;
        p->vt1 = &DAT_010ccf8c; p->vt0 = &DAT_010c3bb8;
    } while (--n >= 0);
}

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
        *(const char**)(pRec + 1) = pName2;
        { unsigned int ticks;
__asm {
    rdtsc
    mov dword ptr[ticks], eax
}
pRec->m_time0 = ticks; }
        pBuf->m_end.m_storage = reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)((const char**)(pRec + 1) + 1));
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
    hkMemoryRouter* pHolder = &hkMemoryRouter::getInstance();
    ScrapAllocator* pAlloc = reinterpret_cast<ScrapAllocator*>(pHolder->m_heap);
    int cap = n;
    rData = cap ? BufAlloc<T>(pAlloc, cap) : 0;
    rCap = cap ? cap : 0x80000000;
}

template <class T> __forceinline void ArrFree(T* pData, unsigned int uiCap)
{
    hkMemoryRouter* pHolder = &hkMemoryRouter::getInstance();
    ScrapAllocator* pAlloc = reinterpret_cast<ScrapAllocator*>(pHolder->m_heap);
    if ((uiCap & 0x80000000) == 0)
        pAlloc->Free(pData, (uiCap & 0x3fffffff) * sizeof(T));
}

template <class T> __forceinline void ArrClearFree(hkArrayBase<T>& arr)
{
    hkMemoryRouter* pHolder = &hkMemoryRouter::getInstance();
    ScrapAllocator* pAlloc = reinterpret_cast<ScrapAllocator*>(pHolder->m_heap);
    unsigned int cap = arr.m_iCapacityState;
    arr.m_iElementCount = 0;
    if ((cap & 0x80000000) == 0)
        pAlloc->Free(arr.m_data, (cap & 0x3fffffff) * sizeof(T));
    arr.m_data = 0;
    arr.m_iCapacityState = 0x80000000;
}

// @fnv 0x00e2a390
// src: XBOX_PDB 0x00e2a390
void __cdecl hkTreeBundleRayCastUtil_startWorldRayCastWithAutoBundleJobs(int a, int b, int n, float f1, float f2, JobSource* pSrc,
                          JobQueue* m_pPrimaryTaskProcessor, JobWaiter* pWaiter, int iParam, bool bAuto)
{
    if (bAuto)
    {
        ProfMark2("LtAutoJob", "StAddJobs");
        int off1 = pSrc->m_i24;
        int off2 = pSrc->m_i2C;
        for (int i = 0; i < 8; i++)
        {
            AutoJob job;
            job.m_cType = 7;
            job.m_c01 = 3;
            job.m_sSize = 0x70;
            job.m_s06 = -1;
            job.m_i10 = 0;
            job.m_i18 = 0;
            job.m_c02 = 1;
            job.m_i14 = 0;
            job.m_i20 = (int*)0;
            job.m_i24 = i;
            job.m_i28 = 0;
            job.m_i2C = a;
            job.m_i30 = b;
            job.m_i34 = n;
            job.m_f38 = f1;
            job.m_f3C = f2;
            job.m_i40 = iParam;
            job.m_i44 = off1;
            job.m_i4C = off2;
            job.m_i54 = pSrc->m_i1C;
            job.m_i58 = pSrc->m_i14;
            job.m_p5C = pSrc->m_p10;
            job.m_i60 = pSrc->m_i34;
            job.m_i64 = pSrc->m_i38;
            job.m_i68 = pSrc->m_i3C;
            job.m_i6C = pSrc->m_i40;
            m_pPrimaryTaskProcessor->AddObjectCopy(&job, 1);
            off1 += n << 6;
            off2 += n << 8;
        }
        pWaiter->Start(m_pPrimaryTaskProcessor, 0xb);
        ProfMark("StWaitThreads");
        pWaiter->Wait();
        ProfMark("lt");
        pSrc->m_p10->hkSemaphore_acquire();
        return;
    }

    ProfMark("TtCPUSplit");
    SplitOut* pData1;
    unsigned int uiCap1;
    SplitOut* pData2;
    unsigned int uiCap2;
    hkArrayBase<int>* pData3;
    int iSize3;
    unsigned int uiCap3;
    int* pData4;
    unsigned int uiCap4;
    int* pData5;
    unsigned int uiCap5;
    {
    ArrInit(pData1, uiCap1, n);
    ArrInit(pData2, uiCap2, n);
    {
        hkMemoryRouter* pHolder = &hkMemoryRouter::getInstance();
        int cap = 8;
        pData3 = cap ? BufAlloc<hkArrayBase<int> >(reinterpret_cast<ScrapAllocator*>(pHolder->m_heap), cap) : 0;
        iSize3 = cap;
        uiCap3 = cap ? cap : 0x80000000;
    }
    for (int k = 0; k < iSize3; k++)
    {
        hkArrayBase<int>* pElem = &pData3[k];
        if (pElem != 0)
        {
            pElem->m_data = 0;
            pElem->m_iElementCount = 0;
            pElem->m_iCapacityState = 0x80000000;
        }
    }
    SplitResult out;
    Object_ProcessEntries_00e29b80(a, b, n, pData1, pData2, pData3, &out);
    ArrInit(pData4, uiCap4, 8);
    ArrInit(pData5, uiCap5, 8);

    int off1 = pSrc->m_i24;
    int off2 = pSrc->m_i2C;
    for (int j = 0; j < 8; j++)
    {
        if (pData3[j].m_iElementCount == 0)
            continue;
        {
            AutoJob job;
            InitJob(job);
            job.m_i20 = pData3[j].m_data;
            job.m_i28 = pData3[j].m_iElementCount;
            job.m_i2C = a;
            job.m_i30 = b;
            job.m_i34 = n;
            job.m_f38 = f1;
            job.m_f3C = f2;
            job.m_i40 = iParam;
            job.m_i44 = off1;
            job.m_i4C = off2;
            job.m_i54 = pSrc->m_i1C;
            job.m_i58 = pSrc->m_i14;
            job.m_p5C = pSrc->m_p10;
            job.m_i60 = pSrc->m_i34;
            job.m_i64 = pSrc->m_i38;
            job.m_i68 = pSrc->m_i3C;
            job.m_i6C = pSrc->m_i40;
            m_pPrimaryTaskProcessor->AddObjectCopy(&job, 1);
            off1 += n << 6;
            off2 += n << 8;
        }
    }
    }
    ProfMark("Et");
    ProfMark("TtAutoBundleJobs");
    pWaiter->Start(m_pPrimaryTaskProcessor, 0xb);
    pWaiter->Wait();
    pSrc->m_p10->hkSemaphore_acquire();
    ProfMark("Et");

    ArrFree(pData5, uiCap5);
    ArrFree(pData4, uiCap4);
    {
        ScrapAllocator* pAlloc = reinterpret_cast<ScrapAllocator*>(hkMemoryRouter::getInstance().m_heap);
        for (int k = 0; k < iSize3; k++)
            ArrClearFree(pData3[k]);
        if ((uiCap3 & 0x80000000) == 0)
            pAlloc->Free(pData3, (uiCap3 & 0x3fffffff) * sizeof(hkArrayBase<int>));
    }
    ArrFree(pData2, uiCap2);
    ArrFree(pData1, uiCap1);
}

extern "C" LocalM128 _mm_max_ps(LocalM128, LocalM128);
namespace SplineMax {
// Keep the vector POD: FUN_00e314c0 returns it by value through the hidden pointer.
struct MaxVec4 { LocalM128 value; };
}
// @fnv 0x00e314c0
// src: GUESS 0x00e314c0 (confidence: low)
SplineMax::MaxVec4 __cdecl hkArrayBase_ProcessEntries_00e314c0(const hkArrayBase<SplineMax::MaxVec4>& input)
{
    SplineMax::MaxVec4 result = input.m_data[0];
    const int count = input.m_iElementCount;
    for (int i = 1; i < count; ++i)
        result.value = _mm_max_ps(result.value, input.m_data[i].value);
    return result;
}

namespace S31470_Intrinsics {
extern "C" ::LocalM128 (_mm_min_ps)(::LocalM128, ::LocalM128);
}

struct MinVec4 {
    LocalM128 m_vComponents;
    void setMin4(const MinVec4& a, const MinVec4& b) { m_vComponents = (S31470_Intrinsics::_mm_min_ps)(a.m_vComponents, b.m_vComponents); }
};
// @fnv 0x00e31470
// src: GUESS 0x00e31470 (confidence: low)
MinVec4 __cdecl hkArrayBase_ProcessEntries_00e31470(const hkArrayBase<MinVec4>& arr)
{
    MinVec4 r = arr.m_data[0];
    for (int i = 1; i < arr.m_iElementCount; i++)
        r.setMin4(r, arr.m_data[i]);
    return r;
}
