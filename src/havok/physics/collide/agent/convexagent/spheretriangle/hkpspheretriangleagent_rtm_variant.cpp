#ifndef _INCLUDED_MM2
#define _INCLUDED_MM2
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;
#endif

// local form of hkVector4: 0x00d3dd90 needs its original packet form (compiled function extent differs: 670 vs 827).


#if !defined(FNV_FOURFLOATVECTOR_NO_SSE)
#include <xmmintrin.h>
#else
union LocalM128;
#endif

class SimdReal;
class SimdScalar;
class ScalarValue;
class Transform;
class NiPoint3;

#pragma pack(push, 4)

class PacketCallLocal_00d3dd90
{
public:
#if defined(FNV_FOURFLOATVECTOR_NO_SSE)
    union Components
    {
        float m128_f32[4];
        unsigned __int64 m128_u64[2];
        signed char m128_i8[16];
        short m128_i16[8];
        int m128_i32[4];
        __int64 m128_i64[2];
        unsigned char m128_u8[16];
        unsigned short m128_u16[8];
        unsigned int m128_u32[4];
    };
#else
    typedef __declspec(align(4)) LocalM128 Components;
#endif

    union
    {
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        Components m_vComponents;
        Components m;
        float f[4];
        Components values;
        Components q;
        Components value;
        Components quad;
        float elements[4];
        float m_fComponents[4];
    };

    PacketCallLocal_00d3dd90();
    PacketCallLocal_00d3dd90(float x, float y, float z, float w);
    PacketCallLocal_00d3dd90(const LocalM128& vector);

    PacketCallLocal_00d3dd90* hkVector4_hkVector4(float x, float y, float z, float w);
    void SetValue(PacketCallLocal_00d3dd90* vector);
    void __thiscall SetQuaternionComponentsFromVector(const PacketCallLocal_00d3dd90* vector);
    PacketCallLocal_00d3dd90& ComputeValue_00e531a0(int parameter);
    PacketCallLocal_00d3dd90 ProcessAndReturnValue_00e53260(int parameter);
    void normalize_005611c0();

    void operator=(const PacketCallLocal_00d3dd90& vector);
    float& operator()(int index);
    const float& operator()(int index) const;
    float& component(int index);
    float& At(int index);
    const float& At(int index) const;

    LocalM128 length3() const;
    float getW() const;
    ScalarValue Dot(const PacketCallLocal_00d3dd90& vector) const;
    ScalarValue LengthSq() const;
    ScalarValue Length() const;
    ScalarValue InverseLength() const;
    void Normalize();
    bool NormalizeNonzero();
    void Mul(const ScalarValue& scalar);
    void Add(const PacketCallLocal_00d3dd90& vector);
    void Sub(const PacketCallLocal_00d3dd90& vector);
    void Cross(const PacketCallLocal_00d3dd90& a, const PacketCallLocal_00d3dd90& b);

    void setAbs4(const PacketCallLocal_00d3dd90& vector);
    void setMul4(const SimdReal& scalar, const PacketCallLocal_00d3dd90& vector);
    void addMul4(const SimdReal& scalar, const PacketCallLocal_00d3dd90& vector);
    void setAddMul4(const PacketCallLocal_00d3dd90& a, const PacketCallLocal_00d3dd90& b, const SimdReal& scalar);
    SimdReal getSimdAt3() const;
    SimdReal lengthSquared3() const;
    void setXYZ_W(LocalM128 xyz, LocalM128 w);
    void setSqrtInverse4(const PacketCallLocal_00d3dd90& vector);
    void setAddMul(const PacketCallLocal_00d3dd90& a, const PacketCallLocal_00d3dd90& b, const SimdScalar& scalar);
    void addMul(const float& scalar, const PacketCallLocal_00d3dd90& vector);
    void transformed(const Transform& transform, const PacketCallLocal_00d3dd90& vector);
    void addScaled(const PacketCallLocal_00d3dd90& base, const PacketCallLocal_00d3dd90& direction, float amount);
    void* AddVector(void*, NiPoint3*, void*, float);
    void* AddVector(void*, void*);
    void* ScaleSwizzled();
};

#pragma pack(pop)

#include "../../../../../../../include/Transform.h"
#include "../../../../../../../include/hkMonitorStream.h"

#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkThreadMemory.h"
// src/havok/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spheretriangle/hkpspheretriangleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct D3DD50CollectorBase {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    bool m_bFound;

    D3DD50CollectorBase() : m_bFound(false) {}
};
struct D3DD50Collector : D3DD50CollectorBase {
    int m_iData;

    D3DD50Collector(int iData) : m_iData(iData) {}

    virtual void unk00();
    virtual void unk04();
};
void __cdecl D3DD50Query(int a, int b, int c, D3DD50CollectorBase* collector);
void __cdecl QueryD3DCollector(int aiArg1, int aiArg2, int aiArg3, int aiData);
extern char DAT_010ce7fc[];
struct Functor_d3e110 {
    void* m_vtbl;
    float m_fHitFraction;
    int m_uiFilterValue;
};
void __cdecl hkpCdBody_ProcessAndReturnValue_00d3d8c0(int a, int b, int c, Functor_d3e110* f);
void __cdecl Hkpspheretriangleagent_UpdateState_00d3e110(int a, int b, int aiArg3, int d);
struct SpawnedInner
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14(unsigned short flags, void* param);
};
class FUN_00d3d200_cls
{
public:
    virtual void unk00(int flags);
    int m_unk04;                 // +0x04
    SpawnedInner* m_pInner;      // +0x08
    unsigned short m_wFlags;     // +0x0C

    void hkpSphereTriangleAgent_cleanup(void* param);
};
struct hkMemory {
    virtual void unk0();
    virtual void* allocateChunk(int size);
};
extern "C" hkThreadMemory* __cdecl hkMemoryRouter_getInstance();
extern "C" void __cdecl hkpCollideTriangleUtil_setupClosestPointTriangleCache(void* src, void* dst);
extern "C" const void* DAT_010cf060;
extern "C" const void* DAT_010cf09c;
struct TargetAgent {
    const void* vtable;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pContactManager;
    unsigned short m_padC;
    short m_padE;
    char m_pAccessManager[0x10];

    TargetAgent(const void* bodyA, void* mgr)
        : m_usMemSizeAndFlags(0x20),
          m_sReferenceCount(1),
          m_pContactManager(mgr),
          m_padC(0xffff)
    {
        vtable = &DAT_010cf060;
        void* triangle = *(void**)bodyA;
        hkpCollideTriangleUtil_setupClosestPointTriangleCache((char*)triangle + 0x20, m_pAccessManager);
        vtable = &DAT_010cf09c;
    }
};
void* __cdecl CreateTargetAgent(void* bodyA, void* bodyB, void* input, void* mgr);
extern char DAT_010ce81c[];
struct D3DD10Data
{
    void* vt;
    unsigned char flag;
    unsigned int value;
};
struct D3DD10Object
{
    void __thiscall hkpSphereTriangleAgent_getPenetrations(unsigned int a1, unsigned int a2,
                                 unsigned int a3, D3DD10Data* data);

    void __thiscall hkpSymmetricAgentLinearCast_hkpSphereTriangleAgent_getPenetrations(unsigned int p0, unsigned int p1,
                                 unsigned int p2, unsigned int p3);
};
extern "C" {
LocalM128 _mm_add_ps(LocalM128, LocalM128);
LocalM128 _mm_mul_ps(LocalM128, LocalM128);
LocalM128 _mm_xor_ps(LocalM128, LocalM128);
LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
}
template <typename T>
__forceinline void hkSwap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}
struct NibblePair
{
    unsigned char lo : 4;
    unsigned char hi : 4;
};
struct SpawnedParticle
{
    PacketCallLocal_00d3dd90 m_vContactPosition;
    PacketCallLocal_00d3dd90 m_fVelocity;
    PacketCallLocal_00d3dd90 m_extra;
};
struct ParticleSystemState
{
    SpawnedParticle* m_kRayEnd;
    int unk0004;
    int unk0008;
    int unk000C;
    SpawnedParticle m_particles[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    PacketCallLocal_00d3dd90 m_3020;
    float m_3030;
    int unk3034;
    int unk3038;
    int unk303C;
    struct Info
    {
        unsigned short m_3040;
        unsigned short m_3042;
        unsigned short m_3044;
        unsigned short unk3046;
        unsigned char m_3048;
        unsigned char m_3049;
        NibblePair m_304a;
        unsigned char unk304b;
    } m_info;
};
extern PacketCallLocal_00d3dd90 DAT_010c4c00;
class ParticleSystemOps
{
public:
    void hkpSphereTriangleAgent_processCollision(int a, int b, int c, ParticleSystemState* state);
    void hkpSymmetricAgentLinearCast_hkpSphereTriangleAgent_processCollision(int a1, int a2, int a3, ParticleSystemState* s);
};
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern "C" {
unsigned __int64 __rdtsc();
void _ReadWriteBarrier();
LocalM128 _mm_sub_ps(LocalM128, LocalM128);
LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
void _mm_store_ps(float*, LocalM128);
}
extern "C" DWORD DAT_0126835c;
struct __declspec(align(16)) Res {
    PacketCallLocal_00d3dd90 pt;
    float d;
};
struct Arg3S {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float f10;
};
struct BodyB {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct BodyHolderB {
    BodyB* obj;
    int unk04;
    Transform* xf;
};
struct Sink {
    virtual void unk00();
    virtual void unk04(BodyHolderB& a, BodyHolderB& b);
};
extern void __cdecl hkpCollideTriangleUtil_closestPointTriangle(PacketCallLocal_00d3dd90* v, void* tri, float* f, Res* out, void* flag);
// non-POD 1-dword wrapper params: block the entry-enregister pass so the
// params are read lazily from their incoming arg slots (see e2fbc0)
struct BHWrap {
    BodyHolderB* p;
    BHWrap(BodyHolderB* q) : p(q) {}
};
struct SinkWrap {
    Sink* p;
    SinkWrap(Sink* q) : p(q) {}
};
class SphereTriAgent {
public:
    int unk00, unk04, unk08, unk0C;
    float unk10;
    void hkpSphereTriangleAgent_getPenetrations(BodyHolderB* a, BodyHolderB* b, int c_, Sink* sink);
};
// rotate the translation difference by the inverse of B's rotation (HK_TRANSPOSE3), compute the
// closest point, and report a contact when the distance is below the summed radii.
extern DWORD DAT_0126835c;
extern char DAT_010cf0d4[];
// "TtSphereTri"
extern char DAT_010c41f8[];
// "Et"
struct S_00d3d3e0_Entry {
    const char* name;
    unsigned time;
    int unk08;
};
struct S_00d3d3e0_Shape {
    int unk00, unk04, unk08, unk0c;
    float f10;
};
struct S_00d3d3e0_Obj {
    int unk00, unk04, unk08, unk0c;
    float f10;
    int unk14, unk18, unk1c;
    int unk20;
};
struct S_00d3d3e0_P1 {
    S_00d3d3e0_Shape* shape;
    int unk04;
    Transform* mat;
};
struct S_00d3d3e0_P2 {
    S_00d3d3e0_Obj* obj;
    int unk04;
    Transform* mat;
};
struct S_00d3d3e0_P3 {
    virtual void v0();
    virtual void v1(S_00d3d3e0_P1* a, S_00d3d3e0_P2* b);
};
struct __declspec(align(16)) S_00d3d3e0_Out {
    int unk00, unk04, unk08, unk0c;
    float f10;
};
void __cdecl hkpCollideTriangleUtil_setupClosestPointTriangleCache(void* a, PacketCallLocal_00d3dd90* out);
void __cdecl hkpCollideTriangleUtil_closestPointTriangle(PacketCallLocal_00d3dd90* a, void* b, PacketCallLocal_00d3dd90* c, S_00d3d3e0_Out* d, bool* e);
struct S_00d3d3e0_P1P { S_00d3d3e0_P1* p; S_00d3d3e0_P1* val() const { return p; } };
struct S_00d3d3e0_P2P { S_00d3d3e0_P2* p; S_00d3d3e0_P2* val() const { return p; } };
struct S_00d3d3e0_P3P { S_00d3d3e0_P3* p; S_00d3d3e0_P3* val() const { return p; } };
void hkpSphereTriangleAgent_staticGetPenetrations(S_00d3d3e0_P1P a1, S_00d3d3e0_P2P a2, int unused, S_00d3d3e0_P3P a3);

extern "C" LocalM128 _mm_load_ss(float const*_A);
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern "C" {
unsigned __int64 __rdtsc();
void _ReadWriteBarrier();
LocalM128 _mm_load_ss(const float*);
}
struct __declspec(align(16)) S00d3d6b0_Res { PacketCallLocal_00d3dd90 pt; float d; };
struct S00d3d6b0_ProfRec { const char* name; unsigned int tsc; unsigned int unk08; };
struct S00d3d6b0_BodyB {
    int unk00,unk04,unk08,unk0C;
    float radius;
    int unk14,unk18,unk1C;
    PacketCallLocal_00d3dd90 vertices[3];
};
struct S00d3d6b0_BodyHolderB { S00d3d6b0_BodyB* obj; int unk04; Transform* xf; };
struct __declspec(align(16)) S00d3d6b0_HitInfo { PacketCallLocal_00d3dd90 pt,nrm; S00d3d6b0_BodyHolderB* a; S00d3d6b0_BodyHolderB* b; };
struct S00d3d6b0_Sink { virtual void unk00(); virtual void unk04(S00d3d6b0_HitInfo*); };
struct S00d3d6b0_Input { int unk00,unk04; float tolerance; };
extern void __cdecl hkpCollideTriangleUtil_closestPointTriangle(PacketCallLocal_00d3dd90* v, void* tri, float* f, S00d3d6b0_Res* out, void* flag);
class S00d3d6b0_SphereTriAgent {
public:
    int unk00,unk04,unk08,unk0C;
    float unk10;
    void hkpSphereTriangleAgent_getClosestPoints(S00d3d6b0_BodyHolderB* a, S00d3d6b0_BodyHolderB* b, S00d3d6b0_Input* input, S00d3d6b0_Sink* sink);
};
extern "C" void* __cdecl memcpy(void* dst, const void* src, unsigned int size);
#pragma intrinsic(memcpy)

static __forceinline void copyVector(PacketCallLocal_00d3dd90& out, const PacketCallLocal_00d3dd90& in) {
    memcpy(&out, &in, sizeof(out));
}

// @fnv 0x00d3d6b0
// src: HAVOK_SRC 0x00d3d6b0
void S00d3d6b0_SphereTriAgent::hkpSphereTriangleAgent_getClosestPoints(S00d3d6b0_BodyHolderB* a, S00d3d6b0_BodyHolderB* b, S00d3d6b0_Input* input, S00d3d6b0_Sink* sink) {
    volatile unsigned int lo;
    {
        hkMonitorStream* buf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        S00d3d6b0_ProfRec* r = (S00d3d6b0_ProfRec*)buf->m_end.m_storage;
        if (r < (S00d3d6b0_ProfRec*)buf->m_capacityMinus16.m_storage) {
            r->name = "TtSphereTri";
            _ReadWriteBarrier();
            lo = (unsigned int)__rdtsc();
            r->tsc = lo;
            buf->m_end.m_storage = (char*)(r + 1);
        }
    }
    S00d3d6b0_HitInfo hit;
    hit.a=a;
    hit.b=b;
    S00d3d6b0_BodyB* shapeA = a->obj;
    S00d3d6b0_BodyB* shapeB = b->obj;
    Transform* axf = a->xf;
    PacketCallLocal_00d3dd90* center = (PacketCallLocal_00d3dd90*)&axf->r[3];
    __declspec(align(16)) PacketCallLocal_00d3dd90 tri[3];
    __declspec(align(16)) PacketCallLocal_00d3dd90 r0,r1,r2;
    S00d3d6b0_Res out;
    {
        copyVector(r0, *(PacketCallLocal_00d3dd90*)&b->xf->r[0]);
        copyVector(r1, *(PacketCallLocal_00d3dd90*)&b->xf->r[1]);
        copyVector(r2, *(PacketCallLocal_00d3dd90*)&b->xf->r[2]);
        copyVector(out.pt, *(PacketCallLocal_00d3dd90*)&b->xf->r[3]);
        for (int i=2; i>=0; --i) {
            LocalM128 v = *(LocalM128*)&shapeB->vertices[i];
            LocalM128 y = _mm_shuffle_ps(v,v,0x55);
            LocalM128 x = _mm_shuffle_ps(v,v,0);
            LocalM128 z = _mm_shuffle_ps(v,v,0xaa);
            LocalM128 px = _mm_mul_ps(x,*(LocalM128*)&r0);
            LocalM128 py = _mm_mul_ps(y,*(LocalM128*)&r1);
            LocalM128 pz = _mm_mul_ps(z,*(LocalM128*)&r2);
            *(LocalM128*)&tri[i] = _mm_add_ps(_mm_add_ps(py,px),_mm_add_ps(pz,*(LocalM128*)&out.pt));
        }
    }
    hkpCollideTriangleUtil_closestPointTriangle(center,tri,&unk10,&out,0);
    float sum = shapeA->radius+shapeB->radius;
    float distance = out.d;
    float threshold = input->tolerance+sum;
    if (distance < threshold) {
        float delta = shapeB->radius-distance;
        LocalM128 centerValue = *(LocalM128*)center;
        LocalM128 scalar = _mm_load_ss(&delta);
        LocalM128 splat = _mm_shuffle_ps(scalar,scalar,0);
        LocalM128 normal = *(LocalM128*)&out.pt;
        LocalM128 pos = _mm_add_ps(_mm_mul_ps(splat,normal),centerValue);
        *(LocalM128*)&hit.pt = pos;
        *(LocalM128*)&hit.nrm = normal;
        hit.nrm.w = distance-sum;
        sink->unk04(&hit);
    }
    {
        hkMonitorStream* buf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        S00d3d6b0_ProfRec* r = (S00d3d6b0_ProfRec*)buf->m_end.m_storage;
        if (r < (S00d3d6b0_ProfRec*)buf->m_capacityMinus16.m_storage) {
            r->name = "Et";
            _ReadWriteBarrier();
            lo = (unsigned int)__rdtsc();
            r->tsc = lo;
            buf->m_end.m_storage = (char*)(r + 1);
        }
    }
}

extern "C" {
unsigned __int64 __rdtsc(void);
void _ReadWriteBarrier(void);
LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
LocalM128 _mm_load_ss(const float*);
}

__forceinline PacketCallLocal_00d3dd90::PacketCallLocal_00d3dd90() {}

__forceinline void PacketCallLocal_00d3dd90::operator=(const PacketCallLocal_00d3dd90& rhs) { m = rhs.m; }

__forceinline void PacketCallLocal_00d3dd90::addScaled(const PacketCallLocal_00d3dd90& base, const PacketCallLocal_00d3dd90& direction, float amount) {
    LocalM128 scalar = _mm_load_ss(&amount);
    scalar = _mm_shuffle_ps(scalar, scalar, 0);
    m = _mm_add_ps(base.m, _mm_mul_ps(scalar, direction.m));
}

__forceinline float& PacketCallLocal_00d3dd90::component(int n) { return f[n]; }

__forceinline Transform::Transform(const Transform& rhs) {
    const PacketCallLocal_00d3dd90 c0 = *(const PacketCallLocal_00d3dd90*)&rhs.r[0], c1 = *(const PacketCallLocal_00d3dd90*)&rhs.r[1], c2 = *(const PacketCallLocal_00d3dd90*)&rhs.r[2], c3 = *(const PacketCallLocal_00d3dd90*)&rhs.r[3];
    *(PacketCallLocal_00d3dd90*)&r[0] = c0; *(PacketCallLocal_00d3dd90*)&r[1] = c1; *(PacketCallLocal_00d3dd90*)&r[2] = c2; *(PacketCallLocal_00d3dd90*)&r[3] = c3;
}

__forceinline void PacketCallLocal_00d3dd90::transformed(const Transform& t, const PacketCallLocal_00d3dd90& v) {
    LocalM128 splatX = _mm_shuffle_ps(v.m, v.m, 0);
    LocalM128 prodX = _mm_mul_ps(t.r[0], splatX);
    LocalM128 splatY = _mm_shuffle_ps(v.m, v.m, 0x55);
    LocalM128 prodY = _mm_mul_ps(t.r[1], splatY);
    LocalM128 splatZ = _mm_shuffle_ps(v.m, v.m, 0xaa);
    LocalM128 prodZ = _mm_mul_ps(t.r[2], splatZ);
    m = _mm_add_ps(_mm_add_ps(prodX, prodY), _mm_add_ps(prodZ, t.r[3]));
}

struct __declspec(align(16)) AlignedPairData {
    PacketCallLocal_00d3dd90 m_vContactPosition;
    PacketCallLocal_00d3dd90 m_vSeparatingNormal;
    unsigned int m_iOwnerObjectOffset;
    int pad24;
    int pad28;
    int pad2C;
};

struct Shape;
struct CdBody {
    Shape* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    Transform* m_kMotionState;
    Shape* shape() const { return m_pCollisionShape; }
    const Transform& transform() const { return *m_kMotionState; }
};

struct Shape {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual int weldContactPoint(void* a1, void* a2, void* a3, const void* a4, const void* a5, const void* a6, void* a7);

    float m_fSphereRadius;
    int pad14;
    int pad18;
    int pad1C;
    __declspec(align(16)) PacketCallLocal_00d3dd90 m_kVertices[3];
};

struct CollisionConstraintOwner {};

struct ProcessCollisionOutput {
    AlignedPairData* m_pAlignedPairData;
    CollisionConstraintOwner* m_pConstraintOwner;
};

struct ProcessCollisionInput {
    int unk00;
    int unk04;
    float m_fCollisionTolerance;
};

struct ContactMgr {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual unsigned short addContactPoint(const CdBody* bodyA, const CdBody* bodyB, const ProcessCollisionInput* input, ProcessCollisionOutput* result, int zero, AlignedPairData* cp);
    virtual void unk10();
    virtual void removeContactPoint(unsigned short id, CollisionConstraintOwner& owner);
};

struct MonitorRecord {
    const char* name;
    unsigned int timestamp;
    unsigned int auxiliary;
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;

extern "C" int __cdecl hkpCollideTriangleUtil_closestPointTriangle(
    const void* spherePos,
    const void* vertices,
    void* cache,
    void* output,
    void* weldFlag
);

union FeatureInfo {
    struct { unsigned char count; unsigned short indices[3]; };
    unsigned __int64 encoded;
};

struct __declspec(align(16)) ClosestPointOutput {
    PacketCallLocal_00d3dd90 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
};

static __forceinline int queryContact(const CdBody* bodyA, const CdBody* bodyB, const ProcessCollisionInput* input, void* cache, AlignedPairData* cp, FeatureInfo* feature) {
    Shape* shapeA = bodyA->shape();
    Shape* shapeB = bodyB->shape();
    const PacketCallLocal_00d3dd90* spherePos = (const PacketCallLocal_00d3dd90*)&bodyA->transform().r[3];

    __declspec(align(16)) PacketCallLocal_00d3dd90 vTransformed[3];
        const Transform* motionB = (&bodyB->transform());
        __declspec(align(16)) Transform copy(*motionB);
        for (int i=2; i>=0; --i) {
            vTransformed[i].transformed(copy, shapeB->m_kVertices[i]);
        }

    __declspec(align(16)) ClosestPointOutput cpOutput;
    int featureKind = hkpCollideTriangleUtil_closestPointTriangle(spherePos, vTransformed, cache, &cpOutput, feature);

    float sumRadius = shapeA->m_fSphereRadius + shapeB->m_fSphereRadius;
    float maxDist = sumRadius + input->m_fCollisionTolerance;

    if (cpOutput.m_fClosestPointDistanceSquared < maxDist) {
        cp->m_vContactPosition.addScaled(*spherePos, cpOutput.m_vHitNormal, shapeB->m_fSphereRadius - cpOutput.m_fClosestPointDistanceSquared);
        cp->m_vSeparatingNormal = cpOutput.m_vHitNormal;
        cp->m_vSeparatingNormal.component(3) = cpOutput.m_fClosestPointDistanceSquared - sumRadius;

        if (featureKind) return 2; return 1;
    }
    return 0;
}

struct TargetAgent_Cand : TargetAgent {
    void hkpSphereTriangleAgent_processCollision(const CdBody* bodyA, const CdBody* bodyB, const ProcessCollisionInput* input, ProcessCollisionOutput* result);
};

// @fnv 0x00d3dd90
// src: HAVOK_SRC 0x00d3dd90
void TargetAgent_Cand::hkpSphereTriangleAgent_processCollision(const CdBody* bodyA, const CdBody* bodyB, const ProcessCollisionInput* input, ProcessCollisionOutput* result) {
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    MonitorRecord* cur = (MonitorRecord*)stream->m_end.m_storage;
    if (cur < (MonitorRecord*)stream->m_capacityMinus16.m_storage) {
        cur->name = DAT_010cf0d4;
        unsigned int ticks;
        _ReadWriteBarrier();
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        cur->timestamp = ticks;
        stream->m_end.m_storage = (char*)(cur + 1);
    }

    AlignedPairData* cp = result->m_pAlignedPairData;
    FeatureInfo weldFlag;
    if (queryContact(bodyA, bodyB, input, this->m_pAccessManager, cp, &weldFlag)) {
        unsigned char m_uiMaterialIndex = weldFlag.count;
        if (m_uiMaterialIndex > 0) {
            Shape* weldShape = bodyB->shape();
            __declspec(align(16)) PacketCallLocal_00d3dd90 normalOut = cp->m_vSeparatingNormal;
            __declspec(align(16)) PacketCallLocal_00d3dd90 posOut = cp->m_vContactPosition;
            int weldRes = weldShape->weldContactPoint(weldFlag.indices, &m_uiMaterialIndex, &posOut, (&bodyB->transform()), bodyA->shape(), (&bodyA->transform()), &normalOut);
            if (weldRes == 0) {
                if (this->m_padC != 0xffff) {
                    ((ContactMgr*)this->m_pContactManager)->removeContactPoint(this->m_padC, *result->m_pConstraintOwner);
                    this->m_padC = 0xffff;
                }
                return;
            }
            if (weldRes == 1) {
                LocalM128 oldNormal = cp->m_vSeparatingNormal.m;
                LocalM128 newNormal = normalOut.m;
                LocalM128 unpck = _mm_unpackhi_ps(newNormal, oldNormal);
                cp->m_vSeparatingNormal.m = _mm_shuffle_ps(newNormal, unpck, 0xc4);
            }
        }

        if (this->m_padC == 0xffff) {
            this->m_padC = ((ContactMgr*)this->m_pContactManager)->addContactPoint(bodyA, bodyB, input, result, 0, cp);
        }
        if (this->m_padC != 0xffff) {
            cp->m_iOwnerObjectOffset = this->m_padC;
            ++result->m_pAlignedPairData;
        }
    } else {
        if (this->m_padC != 0xffff) {
            ((ContactMgr*)this->m_pContactManager)->removeContactPoint(this->m_padC, *result->m_pConstraintOwner);
            this->m_padC = 0xffff;
        }
    }

    hkMonitorStream* streamEnd = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    MonitorRecord* curEnd = (MonitorRecord*)streamEnd->m_end.m_storage;
    if (curEnd < (MonitorRecord*)streamEnd->m_capacityMinus16.m_storage) {
        curEnd->name = DAT_010c41f8;
        unsigned int ticks;
        _ReadWriteBarrier();
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        curEnd->timestamp = ticks;
        streamEnd->m_end.m_storage = (char*)(curEnd + 1);
    }
}

extern "C" LocalM128 _mm_load_ss(const float*);
static __forceinline LocalM128 PlainBroadcast(const float& f) {
 LocalM128 t=_mm_load_ss(&f); return _mm_shuffle_ps(t,t,0);
}





static __forceinline void S_00d3d520_Xform(PacketCallLocal_00d3dd90& out, const PacketCallLocal_00d3dd90& c0, const PacketCallLocal_00d3dd90& c1, const PacketCallLocal_00d3dd90& c2, const PacketCallLocal_00d3dd90& c3, const PacketCallLocal_00d3dd90& b)
{
    const LocalM128 xb = _mm_shuffle_ps(b.m, b.m, 0x00);
    const LocalM128 yb = _mm_shuffle_ps(b.m, b.m, 0x55);
    const LocalM128 zb = _mm_shuffle_ps(b.m, b.m, 0xaa);
    const LocalM128 t0 = _mm_mul_ps(xb, *(const LocalM128*)&c0);
    const LocalM128 t1 = _mm_mul_ps(yb, *(const LocalM128*)&c1);
    const LocalM128 t2 = _mm_mul_ps(zb, *(const LocalM128*)&c2);
    out.m = _mm_add_ps(_mm_add_ps(t1, t0), _mm_add_ps(t2, *(const LocalM128*)&c3));
}

static __forceinline void S_00d3d520_TransformPoints(const Transform& t, const PacketCallLocal_00d3dd90* in, PacketCallLocal_00d3dd90* out)
{
    PacketCallLocal_00d3dd90 c0; copyVector(c0, *(const PacketCallLocal_00d3dd90*)&t.r[0]);
    PacketCallLocal_00d3dd90 c1; copyVector(c1, *(const PacketCallLocal_00d3dd90*)&t.r[1]);
    PacketCallLocal_00d3dd90 c2; copyVector(c2, *(const PacketCallLocal_00d3dd90*)&t.r[2]);
    PacketCallLocal_00d3dd90 c3; copyVector(c3, *(const PacketCallLocal_00d3dd90*)&t.r[3]);
    int i = 2;
    do {
        S_00d3d520_Xform(out[i], c0, c1, c2, c3, in[i]);
    } while (--i >= 0);
}

struct S_00d3d520_Shape {
    int unk00, unk04, unk08, unk0c;
    float radius;
    int unk14, unk18, unk1c;
    PacketCallLocal_00d3dd90 verts[3];
};

struct S_00d3d520_Body {
    S_00d3d520_Shape* shape;
    int unk04;
    Transform* motion;
};

struct S_00d3d520_A {
    S_00d3d520_Shape* shape;
    int unk04;
    PacketCallLocal_00d3dd90* pos;
};

struct S_00d3d520_Info {
    int unk00;
    int unk04;
    float distance;
};

struct __declspec(align(16)) S_00d3d520_Res {
    PacketCallLocal_00d3dd90 normal;
    float dist;
};

struct __declspec(align(16)) S_00d3d520_Out { PacketCallLocal_00d3dd90 point; PacketCallLocal_00d3dd90 normal; };

int __cdecl hkpCollideTriangleUtil_closestPointTriangle(const PacketCallLocal_00d3dd90* pos, const PacketCallLocal_00d3dd90* tri, int a4, S_00d3d520_Res* out, char* flag);

// @fnv 0x00d3d520
// src: XBOX_PDB 0x00d3d520
int __cdecl hkpSphereTriangleAgent_getClosestPoint(S_00d3d520_A* a, S_00d3d520_Body* b, S_00d3d520_Info* info, int a4, S_00d3d520_Out* outp)
{
    __declspec(align(16)) PacketCallLocal_00d3dd90 v[3]; S_00d3d520_Shape* sphere = a->shape;
    { S_00d3d520_Shape* tri = b->shape;
    const PacketCallLocal_00d3dd90* count = a->pos + 3;
    
    S_00d3d520_TransformPoints(*b->motion, tri->verts, v);
    S_00d3d520_Res pen;
    int r = hkpCollideTriangleUtil_closestPointTriangle(count, v, a4, &pen, 0);
    float k = sphere->radius + tri->radius;
    
    float thr = info->distance + k;
    if (pen.dist < thr) {
S_00d3d520_Out* o=outp;
float res=tri->radius-pen.dist;
double separation=pen.dist-k;
volatile float* distance=&o->normal.w;
o->point.m=_mm_add_ps(count->m,_mm_mul_ps(PlainBroadcast(res),pen.normal.m));
o->normal.m=pen.normal.m;
*distance=(float)separation;
        int f = 1 + (r != 0); return f;
    } }
    return 0;
}
