#define FNV_VEC4_SIMD
#include "../../../../../../../include/Vec4.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkMemoryRouter.h"

// src/havok/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void CreateObjectFromFactory();
void Object_CollectPenetratingBodyPair();
void staticGetClosestPoints();
void Object_ProcessEntries_00daf8e0();
void Object_InitializeAgentFunctionTable_00d3ab60(void* apObject);
void __cdecl CreateAllocatedObject();
void __cdecl Object_UpdateFields_00d3ac80();
void __cdecl Object_UpdateFields_00d3b1a0();
void __cdecl Object_UpdateFields_00d3b220();
void __cdecl Hkpcapsuletriangleagent_UpdateState_00d3ab90(void** apTable);
void __cdecl CreateTriAgent2();
void __cdecl Object_UpdateFields_00d38ac0();
void __cdecl hkpMultiSphereTriangleAgent_UpdateState_00d38ed0();
void __cdecl Object_UpdateFields_00d3ac80();
void __cdecl CreateTriAgent();
void __cdecl hkpMultiSphereTriangleAgent_staticGetPenetrations();
void __cdecl Object_ProcessEntries_00d386c0();
void __cdecl Object_ProcessEntries_00daf8e0();
typedef void(__cdecl* S_00d389f0_Func)();
struct S_00d389f0_AgentFuncs
{
    S_00d389f0_Func m_pCreateFunc;
    S_00d389f0_Func m_pQueryPenetrationsFunc;
    S_00d389f0_Func m_getClosestPointsFunc;
    S_00d389f0_Func m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};
struct S_00d389f0_Dispatcher
{
    void AppendRecordAndRegisterAgents(S_00d389f0_AgentFuncs& f, int typeA, int typeB);
};
void __cdecl hkpMultiSphereTriangleAgent_staticGetPenetrations_UpdateState_00d389f0(S_00d389f0_Dispatcher* dispatcher);
struct ReceiverBase
{
    virtual void Release(unsigned int value);
    int unk04;
};
struct NoteDispatcher
{
    virtual void Unknown00(unsigned int, void*);
    virtual void Unknown04(unsigned int, void*);
    virtual void Unknown08(unsigned int, void*);
    virtual void Unknown0C(unsigned int, void*);
    virtual void Unknown10(unsigned int, void*);
    virtual void Dispatch(unsigned int id, void* value);
};
struct FUN_00d39930_class : ReceiverBase
{
    NoteDispatcher* dispatcher;
    unsigned short receiverIds[3];
    void __thiscall DispatchToReceivers(void* value);
};
extern const int DAT_010ce7fc;
struct CallbackState
{
    const int* m_pIntegerValue;
    float m_fFirstLightParameter;
    int m_iValue;
};
void __cdecl staticGetClosestPoints(void* apFirst, void* apSecond, void* apThird, CallbackState* apState);
void __cdecl Object_UpdateFields_00d3b220(void* apOne, void* apTwo, void* apThree, int aiValue);
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl ComputeInverseLengths(void* value, void* self);
extern char DAT_010ceefc[];
extern char DAT_010cef38[];
struct FUN_00d39980_cls
{
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    unsigned short m_w0C;
    unsigned short m_w0E;
    unsigned short m_w10;
    unsigned short m_w12;
    void* m_sub;
};
FUN_00d39980_cls* __cdecl CreateAllocatedObject(int a1, int a2, int a3, int a4);
extern const __m128 DAT_010c4c00;
struct Elem_d3b260
{
    hkVector4 m_pos;
    hkVector4 m_dir;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct Buffer_d3b260
{
    Elem_d3b260* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Elem_d3b260 m_pElements[256];
    hkVector4 m_vHitNormal;
    float m_fHitFraction;
    int unk3034;
    int unk3038;
    int unk303c;
    unsigned short m_idx[4];
    unsigned char m_kPointA;
    unsigned char m_kPointB;
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};
struct Agent_d3b260
{
    void hkpCapsuleTriangleAgent_processCollision(int b, int a, int c, Buffer_d3b260* buf);
    void hkpSymmetricAgentLinearCast_hkpCapsuleTriangleAgent_processCollision(int a, int b, int c, Buffer_d3b260* buf);
};
struct __declspec(align(16)) FourWord
{
    unsigned int x, y, z, w;
};
struct __declspec(align(16)) FourFloat
{
    union
    {
        __m128 simd;
        FourWord words;
    };
};
struct __declspec(align(16)) MotionPacket
{
    unsigned int word00;
    unsigned int word04;
    unsigned int word08;
    unsigned int word0c;
    unsigned int word10;
    unsigned int word14;
    unsigned int word18;
    unsigned int word1c;
    unsigned int word20;
    unsigned int word24;
    unsigned int word28;
    unsigned int word2c;
    unsigned int word30;
    unsigned int word34;
    unsigned int word38;
    unsigned int word3c;
    unsigned int word40;
    unsigned int word44;
    unsigned int word48;
    unsigned int word4c;
    FourFloat direction;
    unsigned int trailing60, trailing64, trailing68, trailing6c;
};
struct __declspec(align(16)) MotionCallData
{
    const void* descriptor;
    float scale;
    FourWord direction;
    unsigned int mode;
};
extern "C" float DAT_0104da48;
extern "C" const __m128 DAT_010c44d0;
extern "C" unsigned char UNK_010ce80c;
extern "C" void __cdecl Object_ProcessEntries_00daf8e0(unsigned int second, unsigned int first, MotionPacket* packet,
                                     MotionCallData* primary, MotionCallData* secondary);
void __cdecl Object_UpdateFields_00d3ac80(unsigned int first, unsigned int second, const MotionPacket* apPacket, unsigned int mode,
                          unsigned int optionalMode);
extern char DAT_010ce81c;
struct FUN_00d3b160_tmp
{
    const void* vt;
    unsigned char flag;
    unsigned int a4;
};
struct CallbackHost_d3b160
{
    void hkpCapsuleTriangleAgent_getPenetrations(void*, void*, void*, void*);
    void hkpSymmetricAgentLinearCast_hkpCapsuleTriangleAgent_getPenetrations(void*, void*, void*, unsigned int);
};
struct Mat4
{
    Vec4 row0, row1, row2, row3;
};
void __cdecl hkCollideCapsuleUtilCapsVsTri(void* a, float b, void* c, float d, void* e, float f, int g, int h, int i);
static __forceinline void transform(Vec4* out, const char* shape, int count, const Mat4* m)
{
    Vec4 p0 = m->row0;
    Vec4 p1 = m->row1;
    Vec4 p2 = m->row2;
    Vec4 p3 = m->row3;
    __m128 r0 = *(__m128*)&p0;
    __m128 r1 = *(__m128*)&p1;
    __m128 r2 = *(__m128*)&p2;
    __m128 r3 = *(__m128*)&p3;

    __m128* v = (__m128*)(shape + 0x20);
    for (int i = count - 1; i >= 0; --i)
    {
        __m128 vi = v[i];
        __m128 x = _mm_shuffle_ps(vi, vi, 0x00);
        __m128 y = _mm_shuffle_ps(vi, vi, 0x55);
        __m128 z = _mm_shuffle_ps(vi, vi, 0xaa);
        __m128 a = _mm_add_ps(_mm_mul_ps(y, r1), _mm_mul_ps(x, r0));
        __m128 b = _mm_add_ps(_mm_mul_ps(z, r2), r3);
        *(__m128*)&out[i] = _mm_add_ps(a, b);
    }
}
void __cdecl TransformAndDispatch(char* a1, char* a2, char* pExtra, void* a4, int a5, int a6);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" void _mm_store_ss(float* p, __m128 a);
extern "C" __m128 _mm_load_ps(const float* p);
extern "C" void _mm_store_ps(float* p, __m128 a);
extern "C" __m128 _mm_rsqrt_ps(__m128 a);
extern __m128 DAT_010c71c0;
extern __m128 DAT_010c71d0;
static __forceinline float SqLenLane(__m128 x)
{
    __m128 sq = _mm_mul_ps(x, x);
    __m128 yx = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    __m128 zyx = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), yx);
    float r;
    _mm_store_ss(&r, zyx);
    return r;
}
void __cdecl ComputeInverseLengths(__m128* pts, float* out);
struct __declspec(align(16)) ScalarVector
{
    int x, y, z, w;
    __m128 quad() const
    {
        return *(const __m128*)this;
    }
};
struct Xf
{
    ScalarVector r0, r1, r2, t;
};
struct Vt
{
    void* f00;
    void* f04;
    void* f08;
    void* f0c;
    void* f10;
    void* f14;
    void* f18;
    void* f1c;
    void* f20;
    void* f24;
    void* f28;
    void* f2c;
    void* f30;
    void* f34;
    void* f38;
    void* f3c;
    int(__thiscall* fn)(void*, void*, void*, void*, void*, void*, void*, void*);
};
struct ShapeInterface
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
    virtual int refine(void*, void*, void*, void*, void*, void*, void*);
};
struct Shape : ShapeInterface
{
    int unk04;
    int unk08;
    int unk0c;
    float radius;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 vertices[3];
};
struct Obj
{
    Shape* base;
    int u;
    Xf* xf;
};
struct Par
{
    float a;
    int flag;
    float c;
};
struct Info
{
    unsigned char count;
    unsigned char type;
    unsigned short feature;
    int index;
};
struct Contact
{
    __m128 normal;
    __m128 position;
    Contact& operator=(const Contact& c)
    {
        normal = c.normal;
        position = c.position;
        return *this;
    }
    void __thiscall SetPositionXYZ(void* arg);
};
static __forceinline void xform(const Xf& m, const __m128* src, __m128* dst, int hi)
{
    ScalarVector column0 = m.r0;
    __m128 c0 = column0.quad();
    ScalarVector column1 = m.r1;
    __m128 c1 = column1.quad();
    ScalarVector column2 = m.r2;
    __m128 c2 = column2.quad();
    ScalarVector translation = m.t;
    __m128 ct = translation.quad();
    for (int i = hi; i >= 0; --i)
    {
        __m128 v = src[i];
        __m128 x = _mm_shuffle_ps(v, v, 0);
        __m128 y = _mm_shuffle_ps(v, v, 0x55);
        __m128 z = _mm_shuffle_ps(v, v, 0xaa);
        dst[i] = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, c1), _mm_mul_ps(x, c0)), _mm_add_ps(_mm_mul_ps(z, c2), ct));
    }
}
struct CollisionWorkspace
{
    __m128 la[2];
    __m128 lb[3];
};
int __cdecl hkpCapsuleTriangleAgent_getClosestPoint(Obj* a, Obj* b, Par* volatile p, void* q, Contact* out);
#include <windows.h>
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpShape.h"
extern DWORD DAT_0126835c;
extern "C" void _ReadWriteBarrier(void);
unsigned __int64 __cdecl __rdtsc(void);
typedef ScalarVector Vec4f;
struct ContactMatrix
{
    Vec4f row[4];
};
struct VirtObj
{
    virtual void v00();
    virtual void Run(const void* a, const void* b);
};
struct ManifoldPoint
{
    __m128 pos;
    int unk10;
    int unk14;
    int unk18;
    float dist;
};
struct HitRec
{
    ManifoldPoint pt0;
    ManifoldPoint pt1;
    ManifoldPoint pt2;
};
struct Context
{
    HitRec hit;
    __m128 capsule[2];
    __m128 triangle[3];
};
extern "C" void __cdecl hkCollideCapsuleUtilCapsVsTri(void* out1, float fx, void* out2, float fy, void* p, float afDepth, int zero,
                                     HitRec* hit, int zero2);
struct CollisionInput
{
    int unk00;
    int unk04;
    float tolerance;
};
struct __declspec(align(16)) RowPair
{
    Vec4f first, second;
};
struct CapsuleTriangleAgent
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void hkpCapsuleTriangleAgent_getPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionInput* input, VirtObj* collector);
};
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
struct ContactNormalSetter : Contact
{
    ContactNormalSetter* SetPositionXYZ(const __m128* source);
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct MonitorRecord
{
    const char* name;
    unsigned int time;
    unsigned int unk08;
};
struct __declspec(align(16)) PlainVector
{
    int x, y, z, w;
    __m128 quad() const
    {
        return *(const __m128*)this;
    }
};
struct PlainMatrix
{
    PlainVector r0, r1, r2, t;
};
struct ContactRecord
{
    __m128 position;
    __m128 normal;
    ContactRecord& operator=(const ContactRecord& o)
    {
        position = o.position;
        normal = o.normal;
        return *this;
    }
    void SetPositionXYZ(const PlainVector*);
};
struct CacheRecord
{
    unsigned char flag;
    unsigned char unk01;
    unsigned short feature;
    unsigned int unk04;
};
union __declspec(align(16)) TransformCacheScratch
{
    PlainVector column;
    CacheRecord cache[3];
};
struct CollisionShape;
struct CapsuleShapeInterface
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
    virtual int process(unsigned short*, unsigned char*, ContactRecord*, const PlainMatrix*, const CollisionShape*,
                        const PlainMatrix*, PlainVector*);
};
struct CollisionShape : CapsuleShapeInterface
{
    unsigned int unk04, unk08, unk0c;
    float radius;
    unsigned int unk14, unk18, unk1c;
    hkVector4 points[3];
};
struct BodyRecord
{
    const CollisionShape* shape;
    unsigned int unk04;
    const PlainMatrix* matrix;
};
struct PointEvent
{
    ContactRecord contact;
    const BodyRecord* a;
    const BodyRecord* b;
    unsigned int unk28, unk2c;
};
struct Collector
{
    virtual void slot00();
    virtual void accept(const PointEvent*);
};
struct ContactResults
{
    ContactRecord points[3];
};
void __cdecl hkCollideCapsuleUtilCapsVsTri(hkVector4*, float, hkVector4*, float, void*, float, int, ContactResults*, CacheRecord*);
struct CollisionAgent
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, cache14;
    void hkpCapsuleTriangleAgent_getClosestPoints(const BodyRecord& a, const BodyRecord& b, const CollisionInput& input, Collector* output);
};

typedef void(__cdecl* FnA_d3a280)(void*, void*, void*, CallbackState*);
typedef void(__cdecl* FnB_daf8e0)(unsigned int, unsigned int, MotionPacket*, MotionCallData*, MotionCallData*);
// src: GUESS 0x00d3ab60 (confidence: medium)
__declspec(noinline) void Object_InitializeAgentFunctionTable_00d3ab60(void* p)
{
    S_00d389f0_AgentFuncs* s = (S_00d389f0_AgentFuncs*)p;
    s->m_pCreateFunc = (S_00d389f0_Func)CreateObjectFromFactory;
    s->m_pQueryPenetrationsFunc = (S_00d389f0_Func)Object_CollectPenetratingBodyPair;
    s->m_getClosestPointsFunc = (S_00d389f0_Func)(FnA_d3a280)staticGetClosestPoints;
    s->m_pLinearCastFunc = (S_00d389f0_Func)(FnB_daf8e0)Object_ProcessEntries_00daf8e0;
    s->m_bIsFlipped = 0;
    s->m_bIsPredictive = 0;
}

// @fnv 0x00d3abc0
// src: GUESS 0x00d3abc0 (confidence: low)
void __cdecl Object_UpdateFields_00d3abc0(S_00d389f0_Dispatcher* obj)
{
    S_00d389f0_AgentFuncs s;
    s.m_bIsFlipped = 0;
    s.m_bIsPredictive = 0;
    Hkpcapsuletriangleagent_UpdateState_00d3ab90((void**)&s);
    obj->AppendRecordAndRegisterAgents(s, 3, 5);
    s.m_bIsFlipped = 0;
    s.m_bIsPredictive = 0;
    Object_InitializeAgentFunctionTable_00d3ab60(static_cast<void*>(&s));
    obj->AppendRecordAndRegisterAgents(s, 5, 3);
}

struct FNVHookStruct
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    unsigned char unk10;
    unsigned char unk11;
};
struct FNVHookOwner
{
    void AddSpawnEntry(void* s, int a, int b);
};
// @fnv 0x00d3ac20
// src: GUESS 0x00d3ac20 (confidence: low)
void Object_UpdateFields_00d3ac20(FNVHookOwner* p)
{
    FNVHookStruct h;
    h.unk10 = 0;
    h.unk11 = 0;
    Hkpcapsuletriangleagent_UpdateState_00d3ab90((void**)&h);
    p->AddSpawnEntry(&h, 3, 5);
    h.unk10 = 0;
    h.unk11 = 0;
    Object_InitializeAgentFunctionTable_00d3ab60(&h);
    p->AddSpawnEntry(&h, 5, 3);
}
