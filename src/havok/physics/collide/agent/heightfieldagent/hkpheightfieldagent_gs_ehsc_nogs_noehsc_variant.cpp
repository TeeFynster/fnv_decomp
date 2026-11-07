
// src/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkArray.h"

extern char DAT_010ceaa8[];
BSAudio* hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);
struct SizeSource {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10();
    virtual int GetCount();
};
struct SourceRef {
    SizeSource* m_p;
};
struct FUN_00d32060_Class {
    void* m_vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_flag;
    hkArray<unsigned short> m_aiIndexedValues;

    FUN_00d32060_Class* Init(const SourceRef& src, int b, int c, int flag);
};
extern void __cdecl hkpHeightFieldAgent_staticGetClosestPoints(void*, void*, void*, void*);
void __stdcall hkpHeightFieldAgent_getClosestPoints(void* a, void* b, void* c, void* d);
typedef void (*S_00d321e0_Func)();
void hkpHeightFieldAgent_createHeightFieldAAgent();
void hkpHeightFieldAgent_staticGetPenetrations_UpdateState_00d32370();
void hkpHeightFieldAgent_staticGetClosestPoints_ProcessState_00d323b0();
void Hkpheightfieldagent_UpdateState_00d323f0();
void AllocateTargetObj();
void hkpHeightFieldAgent_staticGetPenetrations();
void hkpHeightFieldAgent_staticGetClosestPoints();
void hkpHeightFieldAgent_ProcessSphereQueries();
struct S_00d321e0_AgentFuncs {
    S_00d321e0_Func m_pCreateFunc;
    S_00d321e0_Func m_pQueryPenetrationsFunc;
    S_00d321e0_Func m_pGetPenetrationsFunc;
    S_00d321e0_Func m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};
struct S_00d321e0_Dispatcher {
    void AppendRecordAndRegisterAgents(S_00d321e0_AgentFuncs& f, int typeA, int typeB);
};
void hkpHeightFieldAgent_registerAgent(S_00d321e0_Dispatcher* dispatcher);
extern float g_D323B0MaxDistance;
struct D323B0CollectorBase {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    float m_fEarlyOutDistance;

    D323B0CollectorBase() : m_fEarlyOutDistance(g_D323B0MaxDistance) {}
};
struct D323B0Collector : D323B0CollectorBase {
    int m_iData;

    D323B0Collector(int iData) : m_iData(iData) {}

    virtual void unk00();
    virtual void unk04();
};
void __cdecl hkpHeightFieldAgent_staticGetClosestPoints(int a, int b, int c, D323B0CollectorBase* collector);
void __cdecl hkpHeightFieldAgent_staticGetClosestPoints_ProcessState_00d323b0(int a, int b, int c, int d);
struct Handler {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void invoke(unsigned short item, int value);
};
struct Owner {
    virtual void clear(unsigned int mode);
    int unk04;
    Handler* callback;
    unsigned short* indices;
    int count;
    void NotifyAndClear(int value);
};
extern "C" void __cdecl hkpHeightFieldAgent_ProcessSphereQueries(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
// @fnv 0x00d32030
// src: HAVOK_SRC 0x00d32030
extern "C" void __stdcall hkpHeightFieldAgent_linearCast(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4)
{
    hkpHeightFieldAgent_ProcessSphereQueries(arg0, arg1, arg2, arg3, arg4);
}
extern "C" void __cdecl hkpHeightFieldAgent_staticGetPenetrations(void* arg0, void* arg1, void* arg2, void* arg3);
// @fnv 0x00d32150
// src: HAVOK_SRC 0x00d32150
extern "C" void __stdcall hkpHeightFieldAgent_getPenetrations(void* arg0, void* arg1, void* arg2, void* arg3)
{
    hkpHeightFieldAgent_staticGetPenetrations(arg0, arg1, arg2, arg3);
}
extern char DAT_010ce81c;
void __cdecl hkpHeightFieldAgent_staticGetPenetrations(int a1, int a2, int a3, void* a4);
struct FUN_00d32370_cls {
    void* vt;
    unsigned char flag;
    int d;
};
void __cdecl hkpHeightFieldAgent_staticGetPenetrations_UpdateState_00d32370(int a1, int a2, int a3, int a4);
#include <xmmintrin.h>

extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern char DAT_010cea14[];

union CastVector {
    __m128 v;
    struct { float x,y,z,w; };
    template<int mask> __forceinline void broadcast(const CastVector& s) { v=_mm_shuffle_ps(s.v,s.v,mask); }
    __forceinline void mul(const CastVector& a,const CastVector& b) { v=_mm_mul_ps(a.v,b.v); }
    __forceinline void add(const CastVector& a,const CastVector& b) { v=_mm_add_ps(a.v,b.v); }
};
struct CastTransform {
    CastVector r0,r1,r2,translation;
    void __thiscall hkTransform_setMulInverseMul(const CastTransform*,const CastTransform*);
};
static __forceinline void transformVector(CastVector& out,const CastTransform& t,const CastVector& in) {
    CastVector x,y,z,tx,ty,tz,xy,zt;
    x.broadcast<0>(in);
    y.broadcast<0x55>(in);
    z.broadcast<0xaa>(in);
    tx.mul(x,t.r0);
    ty.mul(y,t.r1);
    tz.mul(z,t.r2);
    xy.add(tx,ty);
    zt.add(tz,t.translation);
    out.add(xy,zt);
}
struct CastBody;
struct CastInput {
    void* dispatcher; void* filter; void* quality;
    float tolerance; float weldTolerance; float allowedPenetration;
    int broadPhaseMode; int collisionMode;
    void* config; void* constraintOwner; void* world; void* query;
    int queryFlags; int filterInfo; int material; int shapeKey;
    float time; float deltaTime; int flags; int mode;
    CastVector path;
    float maxExtraPenetration;
};
struct SphereCastInput {
    CastVector from,to;
    int filterInfo,filterInfoB;
    int shapeKey,shapeKeyB;
    float radius,maxExtraPenetration;
    int flags,mode;
};
struct CastCollector {
    char* vtable;
    float earlyOut;
    int flags,mode;
    CastVector worldPosition;
    float radius;
    int filterInfo,shapeKey,material;
    CastVector path;
    CastBody* body;
    void* output;
    int flags2,mode2;
};
struct CastShape {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28();
    virtual int count();
    virtual CastVector* getSpheres(void*);
};
struct CastBody;
struct SphereCastInput;
struct CastCollector;
struct CastHeightField {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void CastSphere(const SphereCastInput&,const CastBody&,CastCollector&) const;
};
struct CastBody {
    CastShape* shape;
    int shapeKey;
    CastTransform* transform;
};
struct TimerEvent { const char* name; unsigned time, timeHi; const char* first; };
struct CastWork {
    CastTransform relativeTransform;
};
struct TimerStream { void* begin; TimerEvent* current; void* capacity; TimerEvent* end; };
static __forceinline void event(TimerStream* stream,const char* name) {
    TimerEvent* e=stream->current;
    if(e<stream->end) {
        e->name=name;
        unsigned int stamp;
        __asm {
            rdtsc
            mov dword ptr[stamp], eax
        }
        e->time=stamp;
        stream->current=(TimerEvent*)((unsigned char*)e+12);
    }
}
// @fnv 0x00d31d30
// src: GUESS 0x00d31d30 (confidence: medium)
extern "C" void __cdecl hkpHeightFieldAgent_ProcessSphereQueries(void* arg0,void* arg1,void* arg2,void* arg3,void* arg4) {
    TimerStream* stream=(TimerStream*)TlsGetValue(DAT_0126835c);
    TimerEvent* e=stream->current;
    if(e<stream->end) {
        e->name="LtHeightField";
        e->first="StClosestPoints";
        unsigned int stamp;
        __asm {
            rdtsc
            mov dword ptr[stamp], eax
        }
        e->time=stamp;
        stream->current=e+1;
    }
    CastBody* bodyA=(CastBody*)arg0;
    CastBody* bodyB=(CastBody*)arg1;
    CastInput* input=(CastInput*)arg2;
    if(arg4) hkpHeightFieldAgent_staticGetClosestPoints(arg0,arg1,arg2,arg4);
    event((TimerStream*)TlsGetValue(DAT_0126835c),"StGetSpheres");
    CastShape* shape=bodyA->shape;
    CastHeightField* __restrict heightField=(CastHeightField*)bodyB->shape;
    CastTransform relativeTransform;
    relativeTransform.hkTransform_setMulInverseMul(bodyB->transform,bodyA->transform);
    int count=shape->count();
    BSAudio* scratch=hkMemoryRouter_getInstance();
    // This Havok scratch pointer uses the first word as its stack cursor.
    int savedStack=*reinterpret_cast<int*>(scratch);
    *reinterpret_cast<int*>(scratch)=savedStack+((count*16+127)&~127);
    __m128 c0=bodyB->transform->r0.v;
    __m128 c1=bodyB->transform->r1.v;
    __m128 c2=bodyB->transform->r2.v;
    __m128 path; (void)path;
    {
        __m128 lo=_mm_unpacklo_ps(c0,c1);
        __m128 ct=_mm_shuffle_ps(_mm_unpackhi_ps(c0,c1),c2,0xe4);
        c0=_mm_movelh_ps(lo,c2);
        c1=_mm_shuffle_ps(_mm_movehl_ps(c0,lo),c2,0xd4);
        c2=ct;
    }
    path=input->path.v;
    __m128 b0=_mm_shuffle_ps(path,path,0);
    __m128 p0=_mm_mul_ps(c0,b0);
    __m128 b1=_mm_shuffle_ps(path,path,0x55);
    __m128 p1=_mm_mul_ps(c1,b1);
    __m128 b2=_mm_shuffle_ps(path,path,0xaa);
    __m128 p2=_mm_mul_ps(c2,b2);
    __m128 localPath=_mm_add_ps(_mm_add_ps(p0,p1),p2);
    CastVector* spheres=shape->getSpheres((void*)savedStack);
    event((TimerStream*)TlsGetValue(DAT_0126835c),"StCastSpheres");
    {
    SphereCastInput sphereInput;
    CastCollector collector;
    sphereInput.filterInfo=0;
    sphereInput.filterInfoB=0;
    sphereInput.maxExtraPenetration=input->maxExtraPenetration;
    collector.vtable=DAT_010cea14;
    collector.earlyOut=1.0f;
    collector.path=input->path;
    collector.body=bodyA;
    collector.output=arg3;
    if(count>0) { int remaining=count; do {
        CastVector sphere;
        sphere.v=spheres->v;
        sphereInput.radius=spheres->w;
        double radius=spheres->w;
        CastVector transformed;
        transformVector(transformed,relativeTransform,sphere);
        sphereInput.from.v=transformed.v;
        sphereInput.to.v=_mm_add_ps(sphereInput.from.v,localPath);
        CastVector worldPosition;
        transformVector(worldPosition,*bodyA->transform,sphere);
        collector.worldPosition.v=worldPosition.v;
        collector.radius=radius;
        heightField->CastSphere(sphereInput,*bodyB,collector);
        ++spheres;
    } while(--remaining); }
    *reinterpret_cast<int*>(hkMemoryRouter_getInstance())=savedStack;
    event((TimerStream*)TlsGetValue(DAT_0126835c),"lt");
    }
}

#include <xmmintrin.h>
namespace fnv_00d324e0 {
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned int DAT_0126835c;
extern char DAT_010ceae0[];
extern char DAT_010c41f8[];
struct TimerEvent { const char* tag; unsigned int time; unsigned int unused; };
struct TimerStream { int unk00; TimerEvent* next; int unk08; TimerEvent* end; };
static __forceinline void timer(const char* tag) {
    TimerStream* s = (TimerStream*)TlsGetValue(DAT_0126835c);
    TimerEvent* p = s->next;
    if (p < s->end) {
        p->tag = tag;
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        p->time = t;
        s->next = p + 1;
    }
}
struct Matrix {
    __m128 c0,c1,c2,c3;
    void hkTransform_setMulInverseMul(const Matrix& b, const Matrix& a);
};
struct SphereQuery {
    __m128* spheres; int count; float tolerance;
    SphereQuery(__m128* s,int n,float t):spheres(s),count(n),tolerance(t) {}
};
struct ShapeD {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28();
    virtual void query(const SphereQuery& q, __m128* out);
    virtual const __m128* spheres(__m128* buffer);
};
struct BodyD { ShapeD* shape; int unk04; const Matrix* transform; };
struct InputD { int unk00,unk04; float tolerance; };
struct ContactD { __m128 position; __m128 normal; unsigned int id; int unk24,unk28,unk2c; };
struct OutputD { ContactD* next; int constraint; };
struct ManagerD {
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual unsigned short add(const BodyD&, const BodyD&, const InputD&, OutputD&, int, ContactD*);
    virtual void v10(); virtual void remove(unsigned short id, int constraint);
};
static __forceinline __m128* reserve(int n) {
    __m128** top = reinterpret_cast<__m128**>(hkMemoryRouter_getInstance());
    __m128* p = *top;
    int bytes = (n * 16 + 127) & -128;
    *top = (__m128*)((char*)p + bytes);
    return p;
}
static __forceinline __m128 point(const Matrix& m, __m128 v) {
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v,v,0x55),m.c1), _mm_mul_ps(_mm_shuffle_ps(v,v,0),m.c0)),
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v,v,0xaa),m.c2),m.c3));
}
static __forceinline __m128 direction(const Matrix& m, __m128 v) {
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v,v,0x55),m.c1), _mm_mul_ps(_mm_shuffle_ps(v,v,0),m.c0)),
                     _mm_mul_ps(_mm_shuffle_ps(v,v,0xaa),m.c2));
}
struct AgentD {
    void* vtable; int unk04; ManagerD* manager; unsigned short* ids; int count; int capacity;
    void hkpHeightFieldAgent_processCollision(const BodyD& a, const BodyD& b, const InputD& input, OutputD& output);
};
// @fnv 0x00d324e0
// src: HAVOK_SRC 0x00d324e0
void AgentD::hkpHeightFieldAgent_processCollision(const BodyD& a, const BodyD& b, const InputD& input, OutputD& output) {
    timer(DAT_010ceae0);
    ShapeD* shapeA = a.shape;
    ShapeD* shapeB = b.shape;
    Matrix relative;
    relative.hkTransform_setMulInverseMul(*b.transform,*a.transform);
    int n = count;
    __m128* transformed = reserve(n);
    unsigned short* id = ids;
    const __m128* src = shapeA->spheres(transformed);
    int last = n - 1;
    int j = last;
    const __m128 c0 = relative.c0;
    const __m128 c1 = relative.c1;
    const __m128 c2 = relative.c2;
    const __m128 c3 = relative.c3;
    const __m128* s = src + last;
    int delta = (char*)transformed - (char*)src;
    do {
        __m128 sphere = *s;
        __m128 v = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(sphere,sphere,0x55),c1), _mm_mul_ps(_mm_shuffle_ps(sphere,sphere,0),c0)),
                             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(sphere,sphere,0xaa),c2),c3));
        *(__m128*)((char*)s + delta) = _mm_shuffle_ps(v,_mm_unpackhi_ps(v,sphere),0xc4);
        --j;
        --s;
    } while (j >= 0);
    __m128* planes = reserve(n);
    shapeB->query(SphereQuery(transformed,n,input.tolerance),planes);
    float tolerance = input.tolerance;
    __m128* p = planes;
    __m128* sphere = transformed;
    for (int i = last; i >= 0; ++p,++sphere,++id,--i) {
        if (((float*)p)[3] > tolerance) {
            if (*id != 0xffff) {
                manager->remove(*id,output.constraint);
                *id = 0xffff;
            }
        } else {
            ContactD* c = output.next;
            float negW = -((float*)sphere)[3];
            __m128 pos = _mm_add_ps(_mm_mul_ps(_mm_set1_ps(negW),*p),*sphere);
            c->position = point(*b.transform,pos);
            c->normal = direction(*b.transform,*p);
            ((float*)&c->normal)[3] = ((float*)p)[3];
            if (*id == 0xffff) {
                *id = manager->add(a,b,input,output,0,c);
                if (*id != 0xffff) ++output.next;
            } else ++output.next;
            c->id = *id;
        }
    }
    *reinterpret_cast<__m128**>(hkMemoryRouter_getInstance()) = planes;
    *reinterpret_cast<__m128**>(hkMemoryRouter_getInstance()) = transformed;
    timer(DAT_010c41f8);
}
}  // namespace fnv_00d324e0
