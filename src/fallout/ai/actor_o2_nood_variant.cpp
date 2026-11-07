#include "../../../include/hkArray.h"

// src/fallout/ai/actor_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/fallout/ai/actor.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

#include "Actor.h"
#include "../../../include/hkpUpdateCollisionFilterOnEntityMode.h"
#include "../../../include/hkpEntityActivation.h"
#include "../../../include/hkpCollidableQualityType.h"
#include "../../../include/hkaSkeleton.h"
#include "../../../include/hkReferencedObject.h"
#include "../../../include/hkMonitorStream.h"
#include "../../../include/hkMonitorStream.h"
#include "../../../include/hkMemoryRouter.h"
#include "../../../include/hkMemoryRouter.h"
#include "../../../include/NiTMapItem.h"
#include "../../../include/hkMemoryRouter.h"
#include "../../../include/hkMonitorStream.h"
#include "../../../include/hkStackMemory.h"
#include "../../../include/hkBool.h"
#include "../../../include/hkMemoryAllocator.h"
#include "../../../include/hkStringPtr.h"
#include "../../../include/hkaBone.h"


// Keep the original float-only intrinsic storage for the compiler alias analysis.
// Exe 0x00c7d030 FUN_00c7d030: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; } __m128, LocalM128;
#define FNV_VEC4_NO_SSE
#define FNV_VEC4_SIMD
#include "../../../include/Vec4.h"
#include "../../../include/hkSimdReal.h"

__forceinline void Vec4::operator=(const Vec4& rhs) { m_vComponents=rhs.m_vComponents; }

namespace FloatHardware { extern "C" ::LocalM128 _mm_sub_ps(::LocalM128,::LocalM128); }
extern "C" {
extern ::LocalM128 _mm_shuffle_ps(::LocalM128, ::LocalM128, int);
extern ::LocalM128 _mm_load_ss(float const*);
extern void _mm_store_ss(float*, ::LocalM128);
extern ::LocalM128 _mm_mul_ps(::LocalM128, ::LocalM128);
extern ::LocalM128 _mm_add_ps(::LocalM128, ::LocalM128);
extern ::LocalM128 _mm_add_ss(::LocalM128, ::LocalM128);
extern ::LocalM128 _mm_unpackhi_ps(::LocalM128, ::LocalM128);
extern ::LocalM128 _mm_rsqrt_ps(::LocalM128);
extern void _mm_prefetch(char const*, int);
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern const ::LocalM128 DAT_010c71c0;
extern const ::LocalM128 DAT_010c71d0;
extern const ::LocalM128 DAT_010c71e0;
}

typedef ::LocalM128 hkQuadReal;
typedef float hkReal;

__forceinline hkSimdReal::hkSimdReal(const hkQuadReal& x) : m_vValue(x) {}
__forceinline hkSimdReal::hkSimdReal() {}
__forceinline hkQuadReal hkSimdReal::broadcast() const { return (_mm_shuffle_ps)(m_vValue, m_vValue, 0); }
__forceinline const hkQuadReal& hkSimdReal::getQuad() const { return m_vValue; }
typedef const hkSimdReal& hkSimdRealParameter;


class ActorQuaternionLocal_00ce3a00;
class hkQsTransform;

// Retained: including the shared SIMD definitions changes the bytes of FUN_00ce3a00.
// local form of hkVector4: 0x00ce3a00 needs the unit FloatHardware intrinsics and force-inline packet form; the shared definitions change its bytes.
class __declspec(align(16)) ActorVectorLocal_00ce3a00 {
public:
    __forceinline ActorVectorLocal_00ce3a00() {}
    __forceinline hkQuadReal& getQuad() { return m_vComponents; }
    __forceinline void operator=(const ActorVectorLocal_00ce3a00& v) { m_vComponents = v.m_vComponents; }
    __forceinline void SetAllComponents(hkSimdRealParameter a) { m_vComponents = (_mm_shuffle_ps)(a.getQuad(), a.getQuad(), 0); }
    __forceinline void add4(const ActorVectorLocal_00ce3a00& v) { m_vComponents = (_mm_add_ps)(m_vComponents, v.m_vComponents); }
    __forceinline void setAdd4(const ActorVectorLocal_00ce3a00& v0, const ActorVectorLocal_00ce3a00& v1) { m_vComponents = (_mm_add_ps)(v0.m_vComponents, v1.m_vComponents); }
    __forceinline void setSub4(const ActorVectorLocal_00ce3a00& v0, const ActorVectorLocal_00ce3a00& v1) { m_vComponents = (FloatHardware::_mm_sub_ps)(v0.m_vComponents, v1.m_vComponents); }
    __forceinline void sub4(const ActorVectorLocal_00ce3a00& v) { m_vComponents = (FloatHardware::_mm_sub_ps)(m_vComponents, v.m_vComponents); }
    __forceinline void mul4(const ActorVectorLocal_00ce3a00& v) { m_vComponents = (_mm_mul_ps)(m_vComponents, v.m_vComponents); }
    __forceinline void setMul4(const ActorVectorLocal_00ce3a00& a, const ActorVectorLocal_00ce3a00& b) { m_vComponents = (_mm_mul_ps)(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(hkSimdRealParameter s) { m_vComponents = (_mm_mul_ps)(s.broadcast(), m_vComponents); }
    __forceinline void addMul4(const ActorVectorLocal_00ce3a00& x, const ActorVectorLocal_00ce3a00& y) { m_vComponents = (_mm_add_ps)(m_vComponents, (_mm_mul_ps)(x.m_vComponents, y.m_vComponents)); }
    __forceinline void setAddMul4(const ActorVectorLocal_00ce3a00& a, const ActorVectorLocal_00ce3a00& x, const ActorVectorLocal_00ce3a00& y) { m_vComponents = (_mm_add_ps)(a.m_vComponents, (_mm_mul_ps)(x.m_vComponents, y.m_vComponents)); }
    __forceinline void addMul4(hkSimdRealParameter r, const ActorVectorLocal_00ce3a00& v1) { m_vComponents = (_mm_add_ps)(m_vComponents, (_mm_mul_ps)(r.broadcast(), v1.m_vComponents)); }
    __forceinline void setCross(const ActorVectorLocal_00ce3a00& v0, const ActorVectorLocal_00ce3a00& v1) {
        hkQuadReal cross0;
        cross0 = (_mm_mul_ps)((_mm_shuffle_ps)(v0.m_vComponents, v0.m_vComponents, 0xc9), (_mm_shuffle_ps)(v1.m_vComponents, v1.m_vComponents, 0xd2));
        hkQuadReal cross1;
        cross1 = (_mm_mul_ps)((_mm_shuffle_ps)(v0.m_vComponents, v0.m_vComponents, 0xd2), (_mm_shuffle_ps)(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = (FloatHardware::_mm_sub_ps)(cross0, cross1);
    }
    __forceinline hkSimdReal dot3(const ActorVectorLocal_00ce3a00& a) const {
        hkQuadReal x2 = (_mm_mul_ps)(m_vComponents, a.m_vComponents);
        hkQuadReal xySum = (_mm_add_ss)((_mm_shuffle_ps)(x2, x2, 0x55), x2);
        return (_mm_add_ss)((_mm_shuffle_ps)(x2, x2, 0xaa), xySum);
    }
    __forceinline hkSimdReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline void setXYZW(const ActorVectorLocal_00ce3a00& xyz, const ActorVectorLocal_00ce3a00& w) {
        m_vComponents = (_mm_shuffle_ps)(xyz.m_vComponents, (_mm_unpackhi_ps)(xyz.m_vComponents, w.m_vComponents), 0xc4);
    }
    __forceinline void setSqrtInverse4(const ActorVectorLocal_00ce3a00& vec) {
        hkQuadReal r = vec.m_vComponents;
        hkQuadReal e = (_mm_rsqrt_ps)(r);
        hkQuadReal he = (_mm_mul_ps)(DAT_010c71d0, e);
        hkQuadReal ree = (_mm_mul_ps)((_mm_mul_ps)(r, e), e);
        m_vComponents = (_mm_mul_ps)(he, (FloatHardware::_mm_sub_ps)(DAT_010c71c0, ree));
    }
    __forceinline hkSimdReal getSimdAt(int i) const {
        switch (i) {
        case 0: return m_vComponents;
        case 1: return (_mm_shuffle_ps)(m_vComponents, m_vComponents, 0x55);
        case 2: return (_mm_shuffle_ps)(m_vComponents, m_vComponents, 0xaa);
        default: return (_mm_shuffle_ps)(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline void broadcast(int i) {
        if (i == 0) m_vComponents = (_mm_shuffle_ps)(m_vComponents, m_vComponents, 0);
        else if (i == 1) m_vComponents = (_mm_shuffle_ps)(m_vComponents, m_vComponents, 0x55);
        else if (i == 2) m_vComponents = (_mm_shuffle_ps)(m_vComponents, m_vComponents, 0xaa);
        else if (i == 3) m_vComponents = (_mm_shuffle_ps)(m_vComponents, m_vComponents, 0xff);
    }
    __forceinline void setBroadcast(const ActorVectorLocal_00ce3a00& v, int i) {
        if (i == 0) m_vComponents = (_mm_shuffle_ps)(v.m_vComponents, v.m_vComponents, 0);
        else if (i == 1) m_vComponents = (_mm_shuffle_ps)(v.m_vComponents, v.m_vComponents, 0x55);
        else if (i == 2) m_vComponents = (_mm_shuffle_ps)(v.m_vComponents, v.m_vComponents, 0xaa);
        else if (i == 3) m_vComponents = (_mm_shuffle_ps)(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline void SetRotatedDirection(const ActorQuaternionLocal_00ce3a00& quat, const ActorVectorLocal_00ce3a00& direction);
    __forceinline void _setTransformedPos(const hkQsTransform& a, const ActorVectorLocal_00ce3a00& b);
    hkQuadReal m_vComponents;
};

// local form of hkQuaternion: 0x00ce3a00 needs the unit FloatHardware intrinsics and force-inline packet form; the shared definitions change its bytes.
class __declspec(align(16)) ActorQuaternionLocal_00ce3a00 {
public:
    __forceinline ActorQuaternionLocal_00ce3a00() {}
    __forceinline const ActorVectorLocal_00ce3a00& getImag() const { return m_vec; }
    __forceinline void operator=(const ActorQuaternionLocal_00ce3a00& q) { m_vec = q.m_vec; }
    void setMul(const ActorQuaternionLocal_00ce3a00& q0, const ActorQuaternionLocal_00ce3a00& q1);
    void ComputeValues_00cd9d10(const ActorVectorLocal_00ce3a00& from, const ActorVectorLocal_00ce3a00& to);
    ActorVectorLocal_00ce3a00 m_vec;
};

// local form of hkVector4/hkQuaternion: 0x00ce3a00 needs the FloatHardware
// packet types in its transform; select them explicitly, keeping shared names intact.
#define FNV64_HKQSTRANSFORM_LOCAL_TYPES
#define FNV64_HKQSTRANSFORM_VECTOR_TYPE ActorVectorLocal_00ce3a00
#define FNV64_HKQSTRANSFORM_QUATERNION_TYPE ActorQuaternionLocal_00ce3a00
#include "../../../include/hkQsTransform.h"
#undef FNV64_HKQSTRANSFORM_QUATERNION_TYPE
#undef FNV64_HKQSTRANSFORM_VECTOR_TYPE
#undef FNV64_HKQSTRANSFORM_LOCAL_TYPES
#include "../../../include/hkaSkeletonMapper.h"


struct __declspec(align(16)) BlendQuat {
    float x, y, z, w;
    BlendQuat& operator=(const BlendQuat& other) { *(LocalM128*)&x=*(const LocalM128*)&other.x; return *this; }
    void __thiscall D3D_ComputeClearColor(const BlendQuat&, const BlendQuat&, float);
};
struct BlendTransform { BlendQuat rotation; BlendQuat translation; BlendQuat scale; };
struct BlendSkeleton {
    int unk000;
    int unk004;
    int unk008;
    BlendTransform* transforms;
    BlendTransform* getTransforms() { return transforms; }
    int unk010;
    int unk014;
    int unk018;
    int count;
    int unk020;
    void* mapping;
    void* getMapping() { return mapping; }
};
struct BlendPose {
    int unk000;
    int unk004;
    int unk008;
    int count;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    BlendSkeleton* skeleton;
    void __thiscall hkaRagdollInstance_getPoseModelSpace(BlendTransform*, void*);
};
struct BlendArray {
    int unk00; unsigned short* data; unsigned int size;
    int find(unsigned short value) const {
        for (unsigned int i=0; i<size; ++i) {
            if (data && data[i]==value) return i;
        }
        return -1;
    }
};
struct BlendRagdoll {
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
    BlendArray bones;
};
struct BlendState { int unk00,unk04,unk08,unk0c; int source,dest; BlendRagdoll* ragdoll; };
struct BlendAccess {
    int* __thiscall hkaPose_getSyncedPoseModelSpace();
    int* __thiscall hkaPose_accessSyncedPoseModelSpace();
    int* __thiscall FUN_00cdb290();
    void __thiscall FUN_00cd9fe0();
    int sourceValue() {return *hkaPose_getSyncedPoseModelSpace();}
    int valueA() {return *hkaPose_accessSyncedPoseModelSpace();}
    int valueB() {return *FUN_00cdb290();}
};
extern __int64 __cdecl BSPrecisionTimer_GetTimer();
extern void __cdecl hkaSkeletonUtils_transformModelPoseToLocalPose(int, BlendTransform*, BlendTransform*, BlendTransform*);
extern void __cdecl CallWithGlobal(int, BlendTransform*, void*, BlendTransform*);
extern void __cdecl mapPose(int, int, int, BlendTransform*, int);
struct BlendBuffer {
    BlendTransform* data; int size;
    static BlendTransform* allocate(int n) {
        hkMemoryRouter* a=&hkMemoryRouter::getInstance();
        BlendTransform* result=(BlendTransform*)a->m_stack.m_next.m_storage;
        int bytes=(n*(int)sizeof(BlendTransform)+127)&~127;
        a->m_stack.m_next.m_storage = (char*)a->m_stack.m_next.m_storage + bytes;
        return result;
    }
    BlendBuffer(int n) { data=allocate(n); }
    ~BlendBuffer() { hkMemoryRouter::getInstance().m_stack.m_next.m_storage=(char*)data; }
};
struct BlendController {
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
    BlendPose* pose;
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
    BlendAccess* access;
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
    float blend;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    BlendState* state;
    BlendState* GetReferenceTimeStep() {return state;}
    __int64 start;

    __int64 duration;

    void __thiscall bhkRagdollController_SetRagdollFeedbackActive(int);
    void __thiscall bhkRagdollController_DoRagdollFeedback();
};
// @fnv 0x00c7c870
// src: COMMUNITY 0x00c7c870
void BlendController::bhkRagdollController_DoRagdollFeedback() {
    BlendController* self=this;
    if (BSPrecisionTimer_GetTimer()-self->start > self->duration) {
        self->bhkRagdollController_SetRagdollFeedbackActive(0);
    } else {
    BlendSkeleton* skeleton=self->pose->skeleton;
    int count=skeleton->count;
    BlendBuffer a(count);
    BlendTransform* aData=a.data;
    {
        BlendBuffer b(count);
        BlendTransform* bData=b.data;
        self->pose->hkaRagdollInstance_getPoseModelSpace(bData,&self->unk010);
        hkaSkeletonUtils_transformModelPoseToLocalPose(count,skeleton->getTransforms(),bData,aData);
    }
    BlendBuffer c(count);
    BlendTransform* cData=c.data;
    BlendBuffer d(count);
    BlendTransform* dData=d.data;
    CallWithGlobal(count,skeleton->getTransforms(),skeleton->getMapping(),dData);
    int mappedCount=(int)skeleton->getMapping();
    mapPose(self->GetReferenceTimeStep()->source,self->access->sourceValue(),mappedCount,dData,2);
    hkaSkeletonUtils_transformModelPoseToLocalPose(count,skeleton->getTransforms(),dData,cData);
    int poseCount=self->pose->count;
    for(int i=0;i<poseCount;++i) {
        int index=self->GetReferenceTimeStep()->ragdoll->bones.find((unsigned short)i);
        if(index!=-1) {
            __declspec(align(16)) char components[sizeof(BlendQuat)];
            BlendQuat& q=*(BlendQuat*)components;
            q.D3D_ComputeClearColor(aData[i].translation,cData[i].translation,self->blend);
            cData[i].translation=q;
        }
    }
    CallWithGlobal(count,skeleton->getTransforms(),cData,dData);
    int v=self->access->valueA();
    int w=self->access->valueB();
    mapPose(self->GetReferenceTimeStep()->dest,(int)dData,w,(BlendTransform*)v,2);
    self->access->FUN_00cd9fe0();
    }
}

union __declspec(align(16)) PackedVector { LocalM128 vector; unsigned char lanes[16]; };
struct InternedHeader { long references; unsigned int length; };


// Interned names and intrusive scene-object references.
char* __cdecl FUN_00a5b690(const char*);
extern char* DAT_0109b220;
__declspec(dllimport) long __stdcall InterlockedIncrement(long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(long*);
void* __cdecl Object_DispatchCommandFour(unsigned int);

__forceinline void RetainString(char* text) {
    if (text != DAT_0109b220) { InternedHeader& header = *((InternedHeader*)text - 1); InterlockedIncrement(&header.references); }
}
__forceinline void ReleaseString(char* text) {
    if (text != DAT_0109b220) InterlockedDecrement(&((InternedHeader*)text - 1)->references);
}
struct MatrixTransform;
void __cdecl NI2HK_00c74dd0(void*, const MatrixTransform*);
struct BoneTransformData;
struct FUN_00a5d3a0 {
    virtual void Reserved();
    virtual void Destroy();
    long references;
    FUN_00a5d3a0();
};
typedef FUN_00a5d3a0 RefBase;
struct CachedScene : RefBase {
    __forceinline BoneTransformData* GetSkeleton() { return skeleton; }
    __forceinline void ApplyTransform(const MatrixTransform&);
    __forceinline void ApplyFinalTransform(const MatrixTransform&);
    __forceinline void ApplyTransformPointer(const MatrixTransform*);
    BoneTransformData* skeleton;
    BoneTransformData* animation;
    void* sourceAnimation;
    void* sourceSkeleton;
    int reserved18;
    int flags;
    CachedScene() {
        skeleton = 0; animation = 0; sourceAnimation = 0; sourceSkeleton = 0; flags = 0;
    }
    virtual void Reserved();
    virtual void Destroy();
    __forceinline static void* operator new(unsigned int n) { return Object_DispatchCommandFour(n); }
    static void operator delete(void*);
};
struct SceneRef {
    CachedScene* p;
    SceneRef(CachedScene* v) : p(v) { if (p) InterlockedIncrement(&p->references); }
    SceneRef(const SceneRef& r) : p(r.p) { if(p) InterlockedIncrement(&p->references); }
    ~SceneRef() { if(p && !InterlockedDecrement(&p->references)) p->Destroy(); }
};
__forceinline void AssignScene(CachedScene*& slot, CachedScene* created) {
    CachedScene* previous = slot;
    if (previous != created) {
        if (previous && !InterlockedDecrement(&previous->references)) previous->Destroy();
        slot = created;
        if (created) InterlockedIncrement(&created->references);
    }
}
struct CacheManager {
    void FUN_00e92760(char*, CachedScene**);
    void InsertOrAssign(char*, SceneRef);
};
extern CacheManager DAT_011b0300;

struct Allocator {
    virtual void Reserved();
    virtual void* Allocate(unsigned int);
    virtual void Reserved8();
    virtual void ReservedC();
    virtual void* Resize(void*, unsigned int);
};
__forceinline hkMemoryRouter* GetRouter() { return (hkMemoryRouter*)(&hkMemoryRouter::getInstance()); }
struct ArrayStorage {
    void* data;
    int size;
    int capacity;
    __forceinline ArrayStorage() : data(0), size(0), capacity(0x80000000) {}
    __forceinline ~ArrayStorage() {
        Allocator& a = reinterpret_cast<Allocator&>(GetRouter()->heap());
        size = 0;
        if ((capacity & 0x80000000) == 0) a.Resize(data, (capacity & 0x3fffffff) * 4);
        data = 0; capacity = 0x80000000;
    }
};
struct ScratchArray : ArrayStorage {
    char* saved;
    __forceinline ScratchArray() {
        hkMemoryRouter* m = GetRouter();
        char* p = static_cast<char*>(reinterpret_cast<hkStackMemory*>(m)->m_next.val());
        reinterpret_cast<hkStackMemory*>(m)->m_next = p + 0x100;
        data = p; capacity = 0x80000040; saved = p;
    }
    __forceinline ~ScratchArray() {
        char* original = saved;
        bool owned = original != data;
        if (!owned) size = 0;
        reinterpret_cast<hkStackMemory*>(GetRouter())->m_next = original;
    }
};
struct MatrixTransform {
    float rotation[3][3];
    float x, y, z;
    float scale;
    void FUN_00a86bf0();
    void hkRotation_set(void*);
    MatrixTransform FUN_0062c250(const MatrixTransform&) const;
};
struct __declspec(align(16)) PoseState {
    BoneTransformData* animation;
    BoneTransformData* skeleton;
    int reserved08;
    float blend, weight;
    void* transforms; int transformCount, transformCapacity;
    void* positions; int positionCount, positionCapacity;
    void* rotations; int rotationCount, rotationCapacity;
    unsigned char localValid, active, reserved3a, reserved3b;
    int reserved3c, reserved40, reserved44, reserved48;
    float scale, inverseScale;
    __forceinline PoseState() throw() { FUN_00c7bfd0(); }
    __forceinline ~PoseState() { FUN_00c7c2b0(); }
    void FUN_00c7bfd0() throw();
    void FUN_00c7c2b0();
};
struct PoseBuffer {
    int reserved00, reserved04, reserved08, reserved0c;
    int VirtualFunction10, reserved14, reserved18, reserved1c;
    int reserved20, VirtualFunction24, VirtualFunction28, reserved2c;
    PackedVector translation, rotation, scale;
    unsigned char valid;
    unsigned char reserved61, reserved62, reserved63;
    int reserved64, reserved68, reserved6c;
    PoseBuffer() { hkaSkeletonMapperData_hkaSkeletonMapperData(); }
    ~PoseBuffer() { UpdateState_00ce5370(); }
    void hkaSkeletonMapperData_hkaSkeletonMapperData();
    void UpdateState_00ce5370();
};
struct FUN_00ce4a20 {
    int reserved0;
    unsigned short allocationSize;
    unsigned short FunctionAtSlot6;
    int VirtualFunction8, reservedC, VirtualFunction10, reserved14, reserved18, reserved1c;
    int reserved20, VirtualFunction24, VirtualFunction28, reserved2c;
    int reserved30, reserved34, reserved38, reserved3c;
    int reserved40, reserved44, reserved48, reserved4c;
    int reserved50, reserved54, reserved58, reserved5c;
    int reserved60, reserved64, reserved68, reserved6c;
    int reserved70, reserved74, reserved78, reserved7c;
    FUN_00ce4a20(PoseBuffer* p);
    __forceinline static void* operator new(unsigned int n) { FUN_00ce4a20* p = (FUN_00ce4a20*)GetRouter()->heap().blockAlloc(n); p->allocationSize = (unsigned short)n; return p; }
    static void operator delete(void*);
};
typedef FUN_00ce4a20 PoseSource;
struct BoneLock { unsigned char value;
    __forceinline BoneLock& operator=(bool b) { value = b; return *this; }
};
struct BoneName { const char* taggedName; BoneLock locked; unsigned char FunctionAtSlot5, FunctionAtSlot6, VirtualFunction7;
    __forceinline const char* Name() const { return (const char*)((unsigned int)taggedName & ~1u); }
};
struct BoneTransformData {
    int reserved0, FunctionAtSlot4, VirtualFunction8, reservedC, VirtualFunction10, reserved14;
    BoneName* bones;
    int boneCount;
    int reserved20;
    void* transform;
    int VirtualFunction28, reserved2c, reserved30;
    MatrixTransform localTransform;
    __forceinline void* GetTransform() { return transform; }
    __forceinline BoneName* GetBones() { return bones; }
    __forceinline BoneName& GetBone(int i) { BoneName* p = &bones[i]; return *p; }
    __forceinline MatrixTransform& GetLocalTransform() { return localTransform; }
};
__forceinline void CachedScene::ApplyTransform(const MatrixTransform& value) { NI2HK_00c74dd0(skeleton->transform, &value); }
__forceinline void CachedScene::ApplyTransformPointer(const MatrixTransform* value) { NI2HK_00c74dd0(skeleton->transform, value); }
__forceinline void CachedScene::ApplyFinalTransform(const MatrixTransform& value) { NI2HK_00c74dd0(GetSkeleton()->GetTransform(), &value); }
struct InputScene {
    int reserved0, FunctionAtSlot4;
    BoneTransformData* skeleton;
    int reservedC;
    void* extra;
    __forceinline BoneTransformData* GetSkeleton() { return skeleton; }
};
struct Argument { int reserved0, FunctionAtSlot4; char* name; };
struct TransformSource {
    int reserved0, FunctionAtSlot4, VirtualFunction8, reservedC;
    int VirtualFunction10, reserved14, reserved18, reserved1c;
    PackedVector basis;
    PackedVector quaternion;
};
struct __declspec(align(16)) Conversion {
    PackedVector rotation;
    PackedVector translation;
    PackedVector scale;
    PackedVector quaternion;
    void hkRotation_set(void*);
};
union TemporaryPoseWork {
    Conversion converted;
    MatrixTransform result;
};
struct ExtraView { TransformSource* FUN_00653290(void*); };
extern int DAT_012683c8;
struct FUN_00cdb400 {
    float* values;
    int reserved04, reserved08, reserved0c, VirtualFunction10, reserved14, reserved18, reserved1c;
    int reserved20, VirtualFunction24, VirtualFunction28, reserved2c, reserved30, reserved34, reserved38, reserved3c;
    int reserved40, reserved44;
    FUN_00cdb400(void* p);
    __forceinline static void* operator new(unsigned int n) { return GetRouter()->heap().blockAlloc(n); }
    static void operator delete(void*);
};
typedef FUN_00cdb400 SkinState;
int __cdecl ApplyToCollisionBodies(BoneTransformData*, ArrayStorage*, ArrayStorage*);
int __cdecl hkaRagdollUtils_reorderForRagdoll(ArrayStorage*, ArrayStorage*);
BoneTransformData* __cdecl hkaRagdollUtils_constructSkeletonForRagdoll(ArrayStorage*, ArrayStorage*);
void __cdecl NI2HK_00c74dd0(void*, const MatrixTransform*);
void __cdecl HK2NI_00624ad0(MatrixTransform*, const void*);
void* __cdecl hkaRagdollUtils_createRagdollInstanceFromSkeleton(BoneTransformData*, ArrayStorage*, ArrayStorage*);
int __cdecl FUN_00ec7750(const char*, const char*);
void __cdecl hkaSkeletonMapperUtils_createMapping(PoseState*, PoseBuffer*, PoseBuffer*);
InputScene* __cdecl bhkUtilFunctions_FindNextCollisionObject(Argument*);
extern float DAT_01267c7c, DAT_01267c88, DAT_01267c94, DAT_01267ca0;
extern float DAT_01267cac, DAT_01267cb8, DAT_01267cc4, DAT_01267cd0;
extern float DAT_01267cdc, DAT_01267ce8, DAT_01267cf4, DAT_01267d00;

struct SceneOwner {
    float rotation[3][3];
    float x, y, z;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    unsigned char unk40;
    unsigned char unk41;
    unsigned char initialized;
    unsigned char unk43;
    void* unk44;
    void* skin;
    SkinState* state;
    int reserved50, reserved54;
    void* skeletonHandle;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11C;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12C;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13C;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14C;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15C;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16C;
    void* unk170;
    void* unk174;
    void* unk178;
    void* unk17C;
    void* unk180;
    void* unk184;
    void* unk188;
    void* unk18C;
    void* unk190;
    void* unk194;
    void* unk198;
    void* unk19C;
    void* unk1A0;
    void* unk1A4;
    void* unk1A8;
    void* unk1AC;
    void* unk1B0;
    void* unk1B4;
    void* unk1B8;
    void* unk1BC;
    void* unk1C0;
    void* unk1C4;
    void* unk1C8;
    void* unk1CC;
    void* unk1D0;
    void* unk1D4;
    void* unk1D8;
    void* unk1DC;
    void* unk1E0;
    void* unk1E4;
    void* unk1E8;
    void* unk1EC;
    void* unk1F0;
    void* unk1F4;
    void* unk1F8;
    void* unk1FC;
    void* unk200;
    void* unk204;
    void* unk208;
    void* unk20C;
    void* unk210;
    unsigned char mode;
    unsigned char unk215;
    unsigned char unk216;
    unsigned char unk217;
    void* unk218;
    void* unk21C;
    void* unk220;
    void* unk224;
    void* unk228;
    void* unk22C;
    void* unk230;
    void* unk234;
    void* unk238;
    void* unk23C;
    void* unk240;
    void* unk244;
    void* unk248;
    void* unk24C;
    void* unk250;
    void* unk254;
    void* unk258;
    void* unk25C;
    void* unk260;
    void* unk264;
    void* unk268;
    void* unk26C;
    void* unk270;
    void* unk274;
    void* unk278;
    void* unk27C;
    void* unk280;
    void* unk284;
    void* unk288;
    void* unk28C;
    void* unk290;
    void* unk294;
    char* name;
    CachedScene* cached;
    int reserved2a8, reserved2ac, reserved2b0, reserved2b4;
    int headBone;
    __forceinline CachedScene* GetCached() { return cached; }
    __forceinline char* GetName() { return name; }
    void bhkRagdollController_Init(Argument*, const char*);
    void bhkRagdollController_CreateSGSkeleton();
    unsigned char bhkRagdollController_InitGrabIK();
    void bhkRagdollController_CheckMappersForWarnings();
};

// @fnv 0x00c7e9a0
// src: COMMUNITY 0x00c7e9a0
void SceneOwner::bhkRagdollController_Init(Argument* sourceInput, const char* requestedName) {
    char* old = name;
    if (old != requestedName) {
        name = FUN_00a5b690(requestedName);
        ReleaseString(old);
    }
    if (!requestedName) {
        char* inherited = sourceInput->name;
        if (name != inherited) {
            RetainString(inherited);
            char* previous = name;
            ReleaseString(previous);
            name = inherited;
        }
    }
    CachedScene** cacheSlot = &cached;
    DAT_011b0300.FUN_00e92760(GetName(), cacheSlot);
    CachedScene* found = *cacheSlot;
    if (!found) {
        AssignScene(*cacheSlot, new CachedScene);
        DAT_011b0300.InsertOrAssign(GetName(), SceneRef(*cacheSlot));
    }
    if (bhkUtilFunctions_FindNextCollisionObject(sourceInput)) {
        InputScene* scene = bhkUtilFunctions_FindNextCollisionObject(sourceInput);
        skeletonHandle = scene->GetSkeleton()->GetBones();
        ScratchArray first;
        ScratchArray second;
        ApplyToCollisionBodies(scene->GetSkeleton(), &first, &second);
        if (hkaRagdollUtils_reorderForRagdoll(&first, &second) != 1) {
            CachedScene* entry = *cacheSlot;
            if (!entry->skeleton) {
                entry->skeleton = hkaRagdollUtils_constructSkeletonForRagdoll(&first, &second);
                (*cacheSlot)->ApplyTransform(scene->GetSkeleton()->GetLocalTransform());
                TransformSource* source;
                if (!scene->extra) source = 0;
                else source = ((ExtraView*)scene->extra)->FUN_00653290(&DAT_012683c8);
                MatrixTransform transform;
                transform.FUN_00a86bf0();
                if (source) {
                    Conversion converted;
                    converted.quaternion.vector = source->quaternion.vector;
                    converted.hkRotation_set(&source->basis);
                    HK2NI_00624ad0(&transform, &converted);
                }
                MatrixTransform copied;
                copied = scene->GetSkeleton()->GetLocalTransform().FUN_0062c250(transform);
                (*cacheSlot)->ApplyTransformPointer(&copied);
            }
            if (cached->skeleton) {
                skin = hkaRagdollUtils_createRagdollInstanceFromSkeleton(GetCached()->skeleton, &first, &second);
                BoneTransformData* skeleton = GetCached()->skeleton;
                for (int bone = 0; bone < skeleton->boneCount; ++bone) {
                    const char* boneName = skeleton->GetBone(bone).Name();
                    if (FUN_00ec7750(boneName, "Head")) headBone = bone;
                }
                if (skin) {
                    state = new SkinState(skin);
                    float* values = state->values;
                    values[0] = DAT_01267c7c; values[1] = DAT_01267c88;
                    values[2] = DAT_01267c94; values[3] = DAT_01267ca0;
                    values[4] = DAT_01267cac; values[5] = DAT_01267cb8;
                    values[6] = DAT_01267cc4; values[7] = DAT_01267cd0;
                    values[8] = DAT_01267cdc; values[9] = DAT_01267ce8;
                    values[10] = DAT_01267cf4; values[11] = DAT_01267d00;
                    initialized = 1;
                    mode = bhkRagdollController_InitGrabIK();
                }
            }
            bhkRagdollController_CreateSGSkeleton();
            if (!(*cacheSlot)->sourceAnimation && !(*cacheSlot)->sourceSkeleton) {
                (*cacheSlot)->animation->bones->locked = false;
                GetCached()->skeleton->bones->locked = false;
                PoseBuffer animationPose;
                PoseBuffer skeletonPose;
                {
                    PoseState pose;
                    pose.animation = (*cacheSlot)->animation;
                    pose.skeleton = (*cacheSlot)->skeleton;
                    pose.active = 0;
                    hkaSkeletonMapperUtils_createMapping(&pose, &animationPose, &skeletonPose);
                }
                bhkRagdollController_CheckMappersForWarnings();
                GetCached()->sourceAnimation = new PoseSource(&animationPose);
                GetCached()->sourceSkeleton = new PoseSource(&skeletonPose);
            }
        }
    }
}

namespace VectorHardware {
// Exe 0x00c7d030 FUN_00c7d030: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned char m128_u8[16];
} __m128, LocalM128;
extern "C" LocalM128 _mm_sub_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_set_ps1(float);
extern "C" LocalM128 _mm_and_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_cmple_ps(LocalM128,LocalM128);
extern "C" int _mm_movemask_ps(LocalM128);
}
typedef VectorHardware::LocalM128 VectorBits;
using VectorHardware::_mm_sub_ps;
using VectorHardware::_mm_set_ps1;
using VectorHardware::_mm_and_ps;
using VectorHardware::_mm_cmple_ps;
using VectorHardware::_mm_movemask_ps;
template<class T> class OwnedCell {
    T stored;
public:
    __forceinline OwnedCell() {}
    __forceinline OwnedCell(T value) : stored(value) {}
    __forceinline void operator=(T value) { stored=value; }
    __forceinline T val() const { return stored; }
    __forceinline T operator->() const { return stored; }
    __forceinline operator T() const { return val(); }
};
struct ReferenceView {
    virtual ~ReferenceView();
    unsigned short allocationFlags;
    unsigned short references;
};
template<class T> class PointerView {
    T* value;
public:
    T* get() const { return value; }
};
extern float DAT_011b02e8;
extern float DAT_011ac39c;
extern const float DAT_01017d00;

extern __int64 BSPrecisionTimer_GetTimer();
struct ScratchAllocator {
    char* current;
    char* allocate(int n) { int numBytes=(n+127)&~127; char* p=current; char* next=p+numBytes; current=next; return p; }
};
extern char bhkRigidBody_IsMotionTypeDynamic(int*);
extern "C" void* __cdecl hkString_memSet(void*,int,unsigned int);
struct Clock {
    __int64 start;
    __int64 duration;
    void FUN_00448e30(float);
    void begin(float f) { start=BSPrecisionTimer_GetTimer(); duration=(__int64)(DAT_011ac39c*f); }
};
struct IndexArray {
    unsigned int unk000;
    unsigned short* data;
    unsigned int count;
    int find(unsigned short v) { for(unsigned int i=0;i<count;++i) if(data && data[i]==v) return i; return -1; }
};
struct Selection {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    IndexArray indices;
    int find(unsigned short v) { return indices.find(v); }
};
struct SelectionHolder {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    Selection* selection;
};
struct BroadHandle { unsigned int id; };
struct TypedHandle : BroadHandle {
    unsigned char type,ownerOffset;
    unsigned short objectGroup;
    unsigned short flags;
    char m_ucObjectQualityType;
    unsigned char unused0b;
};
struct CollisionBodyView {
    void* shape;
    unsigned int shapeKey;
    void* motionState;
    CollisionBodyView* parent;
};
struct ColliderView : CollisionBodyView {
    TypedHandle handle;
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
    const TypedHandle* getBroadPhaseHandle() const { return &handle; }
    TypedHandle* getBroadPhaseHandle() { return &handle; }
};
struct LinkedColliderView : ColliderView {
    void* collisionEntries;
    int collisionCount,collisionCapacity;
};
struct WorldView : ReferenceView {
    void* world;
    unsigned int userData;
    LinkedColliderView collidable;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    const LinkedColliderView* getCollidable() const { return &collidable; }
    LinkedColliderView* getCollidableRw() { return &collidable; }
};
extern const VectorBits DAT_01017d10;
class VectorValue;
class ComparisonValue {
    VectorBits lanes;
    friend class VectorValue;
public:
    enum Required { All=15 };
    __forceinline int all(Required required) const { return (_mm_movemask_ps(lanes)&required)==required; }
};
class VectorValue {
    VectorBits q;
public:
    __forceinline VectorValue() {}
    __forceinline VectorValue(const VectorValue& other) { q=other.q; }
    __forceinline VectorValue(const VectorBits& v) { q=v; }
    operator VectorBits() const { return q; }
    __forceinline void operator=(const VectorBits& v) { q=v; }

    __forceinline void operator=(const VectorValue& other) { q=other.q; }
    __forceinline void difference(const VectorValue& left,const VectorValue& right) { q=_mm_sub_ps(left.q,right.q); }
    __forceinline void absolute(const VectorValue& value) { q=_mm_and_ps(value.q,DAT_01017d10); }
    __forceinline void splat(float value) { q=_mm_set_ps1(value); }
    __forceinline ComparisonValue lessEqual(const VectorValue& value) const { ComparisonValue result; result.lanes=_mm_cmple_ps(q,value.q); return result; }
    __forceinline int equal(const VectorValue& value,float epsilon=0.001f) const {
        VectorValue delta; delta.difference(*this,value); delta.absolute(delta);
        VectorValue tolerance; tolerance.splat(epsilon);
        return delta.lessEqual(tolerance).all(ComparisonValue::All);
    }
};

enum MotionKind { KindInvalid=0,KindDynamic=1,KindSphere=2,KindBox=3,KindKeyframed=4,KindFixed=5,KindThin=6,KindCharacter=7,KindMax=8 };
template<class E,class S> class EnumCell {
    S stored;
public:
    EnumCell() {}
    EnumCell(E value) : stored((S)value) {}
    operator E() const { return (E)stored; }
    void operator=(E value) { stored=(S)value; }
};
struct MotionView : ReferenceView {
    virtual void unused04();
    virtual void unused08();
    virtual void unused0c();
    virtual void unused10();
    virtual void unused14();
    virtual void unused18();
    virtual void unused1c();
    virtual void unused20();
    virtual void unused24();
    virtual void unused28();
    virtual void unused2c();
    virtual void unused30();
    virtual void unused34();
    virtual void unused38();
    virtual void unused3c();
    virtual void SetTranslationalVelocity(const VectorValue&);
    virtual void SetRotationalVelocity(const VectorValue&);
    EnumCell<MotionKind,unsigned char> kind;
    unsigned char flags0,flags1,flags2;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    VectorValue linearVelocity;
    VectorValue angularVelocity;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;

    MotionView();
    MotionKind getType() const { return kind; }
    const VectorValue& getLinearVelocity() const { return linearVelocity; }
    const VectorValue& getAngularVelocity() const { return angularVelocity; }
};
struct KeyframedMotionView : MotionView { KeyframedMotionView(); };
struct MaximumMotionView : KeyframedMotionView {
    MaximumMotionView() : KeyframedMotionView() {}
private:
    MaximumMotionView(const MaximumMotionView&);
    void operator=(const MaximumMotionView&);
};
struct EntityView : WorldView {
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    MaximumMotionView m_pMotionState;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    void activate_00c9c1d0();
    MotionView* getMotion() { return &m_pMotionState; }
};
struct BodyView : EntityView {
    MotionKind getMotionType() const { return m_pMotionState.getType(); }
    hkpCollidableQualityType getQualityType() const { return (hkpCollidableQualityType)getCollidable()->getBroadPhaseHandle()->m_ucObjectQualityType; }
    void setQualityType(hkpCollidableQualityType value) { getCollidableRw()->getBroadPhaseHandle()->m_ucObjectQualityType=(char)value; }
    const VectorValue& getLinearVelocity() const { return m_pMotionState.getLinearVelocity(); }
    const VectorValue& getAngularVelocity() const { return m_pMotionState.getAngularVelocity(); }
    void hkpRigidBody_setMotionType(MotionKind,hkpEntityActivation,hkpUpdateCollisionFilterOnEntityMode);
    void hkpRigidBody_enableDeactivation(bool);
};
template<class T> __forceinline T* AddBytes(T* p,int bytes) { return (T*)((char*)p+bytes); }
__forceinline int ByteDistance(const void* from,const void* to) { return (int)((const char*)to-(const char*)from); }
// hkMemoryRouter::get (0x00c85750) returns the same thread-local object; its first three pointers are the stack allocator.
__forceinline int hkStackMemory::getFreeStackSize() { return ByteDistance(m_next,m_end); }
__forceinline void* hkStackMemory::allocateStack(int bytes,const char* label) {
    if(bytes>getFreeStackSize()) {}
    char* saved=static_cast<char*>(m_next.val());
    m_next=AddBytes(saved,bytes);
    return saved;
}
template<class T> __forceinline T* AllocateView(int n,const char* label=0) {
    hkMemoryRouter& memory=hkMemoryRouter::getInstance();
    return (T*)memory.stack().allocateStack((n*(int)sizeof(T)+127)&~127,label);
}
template<class T> __forceinline void ReleaseView(T* p) {
    hkMemoryRouter::getInstance().stack().deallocateStack(p);
}
struct FixedBuffer {
protected:
    OwnedCell<VectorValue*> data;
    int debugSize;
    __forceinline FixedBuffer() {}
public:
    __forceinline VectorValue* begin() { return data; }
    __forceinline VectorValue& operator[](int i) { return data[i]; }
};
struct BufferView : FixedBuffer {
    __forceinline BufferView(int n) { data=AllocateView<VectorValue>(n); }
    __forceinline ~BufferView() { ReleaseView(data.val()); }
};
template<class T> struct BoneArrayView {
    T* data; int length,capacity;
    const T& operator[](int i) const { return data[i]; }
    int GetLogicalSize() const { return length; }
};
struct SkeletonView {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14;
    BoneArrayView<void*> m_kBones;
};
template<class T> struct SavedReference {
    T* pointer;
    T* operator->() const { return pointer; }
};
struct RagdollView {
    unsigned int unk00,unk04;
    BoneArrayView<BodyView*> bodyArray;
    BoneArrayView<void*> constraints;
    BoneArrayView<int> indices;
    SavedReference<const SkeletonView> skeleton;
    int getNumBones() const { return skeleton->m_kBones.GetLogicalSize(); }
    BodyView* getRigidBodyOfBone(int i) const { int index=indices[i]; return index<0 ? 0 : bodyArray[index]; }
};
struct Controller {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    RagdollView* bodies;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned char unk28c;
    bool enabled;
    bool active;
    unsigned char unk28f;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    PointerView<SelectionHolder> selection;
    Clock timer;
    void bhkRagdollController_UpdateConstraintsWorld(bool);
    void bhkRagdollController_SetRagdollFeedbackActive(bool active);
};
__forceinline void UpdateLinear(BodyView* body,const VectorValue& value) {
    if(!value.equal(body->getLinearVelocity())) {
        body->activate_00c9c1d0();
        body->getMotion()->SetTranslationalVelocity(value);
    }
}
__forceinline void UpdateAngular(BodyView* body,const VectorValue& value) {
    if(!value.equal(body->getAngularVelocity())) {
        body->activate_00c9c1d0();
        body->getMotion()->SetRotationalVelocity(value);
    }
}

// @fnv 0x00c7b6a0
// src: XBOX_PDB 0x00c7b6a0
void Controller::bhkRagdollController_SetRagdollFeedbackActive(bool enable) {
    if (!enabled) return;
    if (!enable && !active) return;
    if (active && enable) { timer.FUN_00448e30(DAT_011b02e8); return; }
    bhkRagdollController_UpdateConstraintsWorld(enable);
    if (enable) timer.begin(DAT_011b02e8); else timer.duration=0;
    int count=bodies->getNumBones();
    BufferView positions(count);
    BufferView rotations(count);
    hkString_memSet(positions.begin(),0,count*16);
    hkString_memSet(rotations.begin(),0,count*16);
    for(int i=0;i<count;++i) {
        BodyView* body=(BodyView*)bodies->getRigidBodyOfBone(i);
        {
            if(body) {
                int kind=body->getMotionType();
                if(bhkRigidBody_IsMotionTypeDynamic(&kind)) { positions[i]=body->getLinearVelocity(); rotations[i]=body->getAngularVelocity(); }
            }
        }
    }
    for(int i=0;i<count;++i) {
        BodyView* body=(BodyView*)bodies->getRigidBodyOfBone(i);
        {
            if(body) {
                if(selection.get()->selection->find((unsigned short)i)!=-1) {
                    if(enable) {
                        if(body->getMotionType()==4 || body->getQualityType()!=4) {
                            body->hkpRigidBody_setMotionType(KindDynamic,HK_ENTITY_ACTIVATION_DO_ACTIVATE,HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK); body->setQualityType((hkpCollidableQualityType)4); body->hkpRigidBody_enableDeactivation(false);
                        }
                    } else {
                        if(body->getMotionType()!=4 || body->getQualityType()!=1) {
                            body->hkpRigidBody_setMotionType(KindKeyframed,HK_ENTITY_ACTIVATION_DO_ACTIVATE,HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK); body->setQualityType((hkpCollidableQualityType)1); body->hkpRigidBody_enableDeactivation(true);
                        }
                    }
                }
                UpdateLinear(body,positions[i]);
                UpdateAngular(body,rotations[i]);
            }
        }
    }
    active=enable;
}

inline void* operator new(unsigned int, void* p) { return p; }
inline void operator delete(void*,void*) {}
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
struct Heap { virtual void Unused(); virtual void* Allocate(unsigned); };
extern void* __cdecl MemoryManager_AlignedAllocate16(unsigned);
extern void __cdecl NI2HK_00c74dd0(void*, void*);
extern float DAT_01050c98, DAT_01050c48, DAT_01011d78, DAT_01012068;
extern void* UNK_010c4dec;
static __forceinline void* AllocateBuffer(unsigned n) { hkMemoryRouter* context=&hkMemoryRouter::getInstance(); Heap* heap=reinterpret_cast<Heap*&>(context->m_heap); return (heap->Allocate)(n); }
static __forceinline int Maximum(int first,int second) { return first >= second ? first : second; }
struct SmallMember { unsigned data; __forceinline SmallMember() { FUN_00cb0a60(); } __forceinline ~SmallMember() { Object_UpdateFields_00cb0c00(); } void FUN_00cb0a60(); void Object_UpdateFields_00cb0c00(); };
struct Entry { SmallMember member; unsigned char enabled; __forceinline Entry():enabled(0) {} };
extern void __cdecl hkArrayUtil__reserve(Heap&, void*, int, unsigned);
// Mesh data arrays use 0x30-byte records of three SIMD packets; these are not the shared 0x40-byte Transform.
struct __declspec(align(16)) MeshPacketRecord48 { LocalM128 x,y,z; };
struct S7de60_IsPod {}; struct S7de60_IsClass {};
template<class T> struct S7de60_PodTrait { typedef S7de60_IsPod type; };
template<> struct S7de60_PodTrait<Entry> { typedef S7de60_IsClass type; };
struct S7de60_ArrayUtil {
    template<class T> static __forceinline void construct(T* t, int n, S7de60_IsPod) {}
    template<class T> static __forceinline void construct(T* t, int n, S7de60_IsClass) { for(int i=0;i<n;++i) new (t+i) T; }
    template<class T> static __forceinline void constructWithCopy(T* t, int n, const T& c, S7de60_IsPod) { for(int i=0;i<n;++i) t[i]=c; }
    template<class T> static __forceinline void destruct(T* t, int n, S7de60_IsPod) {}
    template<class T> static __forceinline void destruct(T* t, int n, S7de60_IsClass) { for(int i=0;i<n;++i) t[i].~T(); }
};
__forceinline Heap& GetRenderHeap(hkMemoryRouter& router) { return *reinterpret_cast<Heap*&>(router.m_heap); }
struct S7de60_HeapAlloc { __forceinline Heap& get(const void*) { return GetRenderHeap(hkMemoryRouter::getInstance()); } };


// Exe 0x00c7de60: Havok arrays retain their original heap growth and element construction inlines.
template <> __forceinline void hkArray<MeshPacketRecord48,hkContainerHeapAllocator>::setSize(int n) {
 ::Heap& alloc=::S7de60_HeapAlloc().get(this);
 const int cap=getCapacity(); if(cap<n) { int cap2=2*cap; int newSize=(n<cap2)?cap2:n; hkArrayUtil__reserve(alloc,this,newSize,sizeof(MeshPacketRecord48)); }
 S7de60_ArrayUtil::destruct(m_data+n,m_iElementCount-n,S7de60_PodTrait<MeshPacketRecord48>::type());
 S7de60_ArrayUtil::construct(m_data+m_iElementCount,n-m_iElementCount,S7de60_PodTrait<MeshPacketRecord48>::type()); m_iElementCount=n;
}
template <> __forceinline void hkArray<int,hkContainerHeapAllocator>::setSize(int n) {
 ::Heap& alloc=::S7de60_HeapAlloc().get(this);
 const int cap=getCapacity(); if(cap<n) { int cap2=2*cap; int newSize=(n<cap2)?cap2:n; hkArrayUtil__reserve(alloc,this,newSize,sizeof(int)); }
 S7de60_ArrayUtil::destruct(m_data+n,m_iElementCount-n,S7de60_PodTrait<int>::type());
 S7de60_ArrayUtil::construct(m_data+m_iElementCount,n-m_iElementCount,S7de60_PodTrait<int>::type()); m_iElementCount=n;
}
template <> __forceinline void hkArray<Entry,hkContainerHeapAllocator>::setSize(int n) {
 ::Heap& alloc=::S7de60_HeapAlloc().get(this);
 const int cap=getCapacity(); if(cap<n) { int cap2=2*cap; int newSize=(n<cap2)?cap2:n; hkArrayUtil__reserve(alloc,this,newSize,sizeof(Entry)); }
 S7de60_ArrayUtil::destruct(m_data+n,m_iElementCount-n,S7de60_PodTrait<Entry>::type());
 S7de60_ArrayUtil::construct(m_data+m_iElementCount,n-m_iElementCount,S7de60_PodTrait<Entry>::type()); m_iElementCount=n;
}
template <> __forceinline void hkArray<short,hkContainerHeapAllocator>::setSize(int n) {
 ::Heap& alloc=::S7de60_HeapAlloc().get(this);
 const int cap=getCapacity(); if(cap<n) { int cap2=2*cap; int newSize=(n<cap2)?cap2:n; hkArrayUtil__reserve(alloc,this,newSize,sizeof(short)); }
 S7de60_ArrayUtil::destruct(m_data+n,m_iElementCount-n,S7de60_PodTrait<short>::type());
 S7de60_ArrayUtil::construct(m_data+m_iElementCount,n-m_iElementCount,S7de60_PodTrait<short>::type()); m_iElementCount=n;
}
template <> __forceinline void hkArray<float,hkContainerHeapAllocator>::reserveExactly(int n) { ::Heap& alloc=::S7de60_HeapAlloc().get(this); if(getCapacity()<n) hkArrayUtil__reserve(alloc,this,n,sizeof(float)); }
template <> __forceinline void hkArray<float,hkContainerHeapAllocator>::setSize(int n,const float& fill) { ::Heap& alloc=::S7de60_HeapAlloc().get(this); const int cap=getCapacity(); if(cap<n) { int cap2=2*cap; int newSize=(n<cap2)?cap2:n; hkArrayUtil__reserve(alloc,this,newSize,sizeof(float)); } S7de60_ArrayUtil::destruct(m_data+n,m_iElementCount-n,S7de60_PodTrait<float>::type()); S7de60_ArrayUtil::constructWithCopy(m_data+m_iElementCount,n-m_iElementCount,fill,S7de60_PodTrait<float>::type()); m_iElementCount=n; }
struct SourceBase {
    unsigned short size,version;
    __forceinline SourceBase():version(1) {}
    virtual ~SourceBase();
};
struct LocalFrameRecord { void* frame; int bone; };
struct SourceBuffer : SourceBase {
    SmallMember member;
    hkArray<short> points; hkArray<Entry> indices; hkArray<MeshPacketRecord48> vertices; hkArray<SmallMember> transforms; hkArray<LocalFrameRecord> extra;
    static __forceinline void* operator new(unsigned n) { SourceBuffer* p=(SourceBuffer*)AllocateBuffer(n); p->size=(unsigned short)n; return p; }
    static void operator delete(void*);
    __forceinline SourceBuffer() {}
};
struct PoseSync91 {
    unsigned char value;
    __forceinline PoseSync91(bool v):value((unsigned char)v) {}
    __forceinline operator bool() const { return value!=0; }
};
struct CloneBuffer {
    SourceBuffer* original;
    hkArray<MeshPacketRecord48> positions,normals; hkArray<int> triangles;
    PoseSync91 enabled,modified; unsigned short flags;
    hkArray<float> remap;
    static __forceinline void* operator new(unsigned n) { return AllocateBuffer(n); }
    static void operator delete(void*);
    __forceinline CloneBuffer(SourceBuffer* p):original(p),enabled(0),modified(0) {
        int count=original->indices.m_iElementCount;
        normals.setSize(count);
        positions.setSize(count);
        triangles.setSize(count);
        const int sizeRoundedUp=(original->transforms.GetLogicalSize()+3)&~3;
        remap.reserveExactly(sizeRoundedUp);
        remap.setSize(original->transforms.m_iElementCount,0.0f);
    }
    void hkaPose_setToReferencePose(); void hkaPose_syncModelSpace();
};
struct Root {
    SourceBuffer* src; __forceinline void SetSource(SourceBuffer* p) { src=p; } int unk04,unk08,unk0c;
    Vec4 a,b;
    static __forceinline void* operator new(unsigned n) { return MemoryManager_AlignedAllocate16(n); }
    __forceinline Root():src(0) {}
};
struct Owner { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18; Root* root; __forceinline void SetRoot(Root* p) { root=p; } };
union Vec128 { LocalM128 value; char bytes[16]; };
struct FramePoint { float x,y,z; };
struct FrameState { FramePoint rotation[3]; FramePoint point; float scale; void FUN_00a86bf0(); };
struct __declspec(align(16)) LookBoneParams91 {
    CloneBuffer* pose;
    short bone,parent;
    float maxAngle;
    Vec4 forwardLocal,forwardParent,previousRotation;
    bool limitRotation,active;
    float deadHeading,deadPitch;
};
template<class T> struct SharedObject91 {
    T* object;
    __forceinline T* operator->() const { T* result=object; return result; }
};
struct RenderNode {
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
    unsigned short unk40; bool active; unsigned char unk43;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    CloneBuffer* buffer;
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
    int unk80;
    int unk84;
    CloneBuffer* input;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    bool success; unsigned char unkb1; unsigned short unkb2;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    LookBoneParams91 boneParams[2];
    bool create; unsigned char unk191; unsigned short unk192;
    int state;
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
    SharedObject91<Owner> owner;
    __forceinline Owner* GetOwner() { Owner* result=owner.operator->(); return result; }
    bool bhkRagdollController_InitBoneParams(CloneBuffer*,const char*,int);
    bool bhkRagdollController_InitLookIK(const char* item);
};
// @fnv 0x00c7de60
// src: COMMUNITY 0x00c7de60
bool RenderNode::bhkRagdollController_InitLookIK(const char* item) {
    bool ok=active;
    if(ok) {
    ok=bhkRagdollController_InitBoneParams(input,item,1);
    if(ok) {
        state=1;
        if(create) {
            if(!owner->root) {
                owner->SetRoot(new Root);
                owner->root->src=new SourceBuffer;
                owner->root->src->indices.setSize(2);
                owner->root->src->points.setSize(2);
                owner->root->src->vertices.setSize(2);
                ((short*)owner->root->src->points.m_data)[0]=-1;
                ((short*)owner->root->src->points.m_data)[1]=0;
                FrameState frame;
                frame.FUN_00a86bf0();
                NI2HK_00c74dd0(owner->root->src->vertices.m_data,&frame);
                frame.point.x=DAT_01050c98; frame.point.y=DAT_01050c48; frame.point.z=0;
                NI2HK_00c74dd0(owner->root->src->vertices.m_data+1,&frame);
                owner->root->a=boneParams[1].forwardParent;
                owner->root->b=boneParams[1].forwardLocal;
            }
            CloneBuffer* clone=new CloneBuffer(owner->root->src);
            buffer=clone;
            clone->hkaPose_setToReferencePose();
            buffer->hkaPose_syncModelSpace();
            Vec128 unit; unit.value=_mm_setr_ps(DAT_01011d78,DAT_01012068,DAT_01011d78,DAT_01011d78);
            boneParams[0].bone=1;
            boneParams[0].forwardLocal.m_vComponents=unit.value;
            boneParams[0].forwardParent.m_vComponents=boneParams[0].forwardLocal.m_vComponents;
            boneParams[0].parent=0;
            boneParams[0].pose=buffer;
            state=0;
        }
    }
    success=ok;
    }
    return ok;
}

struct C74Matrix3 {
    float m_afEntries[3][3];
};

struct C74Transform {
    C74Matrix3 m_kOrientation;
    float m_TranslateX;
    float m_TranslateY;
    float m_TranslateZ;
    float m_fScale;
};

// local form of NiQuaternion: 0x00c74dd0 needs POD default construction; the shared ctor adds bytes.
struct C74NiQuaternion {
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    void FromRotationMatrix(const C74Matrix3& kRot);
};

struct C74Vector4 {
    VectorBits m_vComponents;
    float& operator()(int i) { return m_vComponents.m128_f32[i]; }
};

struct C74Quaternion {
    float m_vec[4];
    void set(float x, float y, float z, float w) { m_vec[0] = x; m_vec[1] = y; m_vec[2] = z; m_vec[3] = w; }
    void normalize();
};

// hkQsTransform was included above with the explicit packet storage types.


extern float DAT_01267c20;

// @fnv 0x00c74dd0
// src: COMMUNITY 0x00c74dd0
hkQsTransform* NI2HK_00c74dd0(hkQsTransform* out, const C74Transform* in)
{
    C74NiQuaternion q;
    q.FromRotationMatrix(in->m_kOrientation);
    reinterpret_cast<C74Quaternion&>(out->m_rotation).set(q.m_fVectorY, q.m_fVectorZ, q.m_fScalarPart, q.m_fVectorX);
    reinterpret_cast<C74Quaternion&>(out->m_rotation).normalize();
    C74Vector4 t;
    t(0) = in->m_TranslateX * DAT_01267c20;
    t(1) = in->m_TranslateY * DAT_01267c20;
    t(2) = in->m_TranslateZ * DAT_01267c20;
    t(3) = 0.0f;
    out->m_vTranslation.m_vComponents = reinterpret_cast<const hkQuadReal&>(t.m_vComponents);
    out->m_vScale.m_vComponents = reinterpret_cast<const hkQuadReal&>(_mm_set_ps1(in->m_fScale));
    return out;
}

namespace EntryHardware {
// Exe 0x00c7d030 FUN_00c7d030: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    PackedVector storage;
    struct { float x,y,z,w; };
} __m128, LocalM128;
extern "C" LocalM128 _mm_setr_ps(float,float,float,float);
}

extern int DAT_011f49e0;
extern double DAT_010c4dd0;
extern double DAT_010c4dc8;
extern float DAT_01011d78;
extern float DAT_01012068;
extern float DAT_01267d90;
struct InputName { char* key; };
struct FNVInput { int unk00; InputName* objects; unsigned count; InputName& at(unsigned i) { return objects[i]; } };

struct StringHeader { long references; unsigned length; void release() { InterlockedDecrement(&references); } };
struct ResourceName {
    char* key;
    ResourceName(InputName const& raw) { if (!raw.key) key=DAT_0109b220; else key=FUN_00a5b690(raw.key); }
    ~ResourceName() { if (key != DAT_0109b220) { StringHeader* header=reinterpret_cast<StringHeader*>(key)-1; header->release(); } }
};
struct __declspec(align(16)) Scratch {
    int owner;
    short first, second, third, unk0a;
    int unk0c;
    EntryHardware::LocalM128 axisA, axisB, axisC, axisD;
    float strength, f54, f58, f5c, f60, f64, f68, threshold, radius;
    bool flag;
    void __thiscall hkaFootPlacementIkSolver_Setup_Setup();
};
struct GameForm {
    GameForm* getLinked();
    GameForm* getChildNamed();
    struct VTable;
    typedef int (__fastcall *TypeQuery)(GameForm*,VTable*);
    struct VTable { void* f0; void* f1; void* f2; TypeQuery canUse; };
    struct NativeQuery { virtual void f0(); virtual void f1(); virtual void f2(); virtual int __fastcall queryType(VTable*)=0; };
    VTable* vtable;
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
    struct Children { GameForm** data; unsigned short capacity,count; GameForm* get() const { return data[0]; } } children;
};
struct Material { int unk00,unk04; int name; };
struct Resource { int unk00,unk04; Material* material; };
struct IndexedRecord { void __thiscall FUN_00c905b0(); };
struct FUN_00cd8820 : IndexedRecord {
    int vtable;
    unsigned short size, references;
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
    FUN_00cd8820(Scratch const&);
    static __forceinline void* operator new(size_t);
    static void operator delete(void*);
};
struct RagdollEntry {
    IndexedRecord* record;
    float value;
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
    short mapped,unkc2;
    int unkc4,unkc8,unkcc;
    static void* operator new(size_t, void* p) { return p; }
    RagdollEntry() : record(0), value(0.0f), mapped(-1) {}
};
struct EntryArray { RagdollEntry* data; int count,capacity; void resize(int); RagdollEntry& operator[](unsigned i) { return data[i]; } };
struct MappingEntry { short source,target; int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c; };
struct Mapping { int unk00,unk04,unk08,unk0c,unk10,unk14; MappingEntry* data; int count; };
struct Table { int unk00,unk04,unk08; int owner; Mapping* mapping; };
struct Geo { float unk00, expansion; };
struct ParticleTable {
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
    short unk40; unsigned char enabled,unk43;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    void* context;
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
    unsigned char unk21c,unk21d,unk21e,complete;
    int unk220;
    int unk224;
    int unk228;
    EntryArray entries;
    int unk238;
    int unk23c;
    int unk240;
    float radius;
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
    Table* table;
    void* getContext() { return context; }
    void __thiscall bhkRagdollController_InitFootIK(FNVInput* incoming);
    bool __thiscall bhkRagdollController_ExtractBipedSetupData(Scratch*, FNVInput*);
    Geo* __thiscall bhkRagdollController_GetCapsuleBoneShapeInfo(GameForm*);
};

extern GameForm* __cdecl BSUtilities_GetObjectByName_00c4b470(void*, ResourceName const&, int);
static __forceinline hkMemoryRouter* GetEntryRuntime() { return reinterpret_cast<hkMemoryRouter*>(&hkMemoryRouter::getInstance()); }
extern "C" void __cdecl hkArrayUtil__reserve(Allocator*, EntryArray*, int, unsigned);
extern "C" Resource* __cdecl bhkUtilFunctions_FindNextCollisionObject(GameForm*);
extern "C" short __cdecl FindIndexByKey(int,int,int);
__forceinline void* FUN_00cd8820::operator new(size_t bytes) {
    void* ptr=GetEntryRuntime()->heap().blockAlloc(bytes);
    static_cast<FUN_00cd8820*>(ptr)->size=(unsigned short)bytes;
    return ptr;
}
__forceinline GameForm* GameForm::getLinked() {
    if (vtable->canUse(this,vtable) && children.count>0) return children.get(); return 0;
}
__forceinline GameForm* GameForm::getChildNamed() { NativeQuery* query=reinterpret_cast<NativeQuery*>(this); if(query->queryType(vtable) && children.count>0) return children.get(); return 0; }
static __forceinline int const& materialName(Resource* resource) {
    return resource ? resource->material->name : DAT_011f49e0;
}
__forceinline void EntryArray::resize(int size) {
    Allocator& allocator=reinterpret_cast<Allocator&>(GetEntryRuntime()->heap());
    int cap=capacity & 0x3fffffff;
    if (cap<size) {
        cap*=2;
        if (size>=cap) cap=size;
        hkArrayUtil__reserve(&allocator,this,cap,sizeof(RagdollEntry));
    }
    int extra=size-count;
    RagdollEntry* dest=data+count;
    for (int k=0;k<extra;++k) new (dest+k) RagdollEntry;
    count=size;
}
// @fnv 0x00c7c3a0
// src: COMMUNITY 0x00c7c3a0
void __thiscall ParticleTable::bhkRagdollController_InitFootIK(FNVInput* incoming) {
    FNVInput* input=incoming;
    unsigned count=incoming->count;
    if (!count || !enabled) return;
    Scratch scratch;
    scratch.hkaFootPlacementIkSolver_Setup_Setup();
    bool ready=bhkRagdollController_ExtractBipedSetupData(&scratch,incoming);
    Table* ownerTable=table;
    int owner=ownerTable->owner;
    if (!ready) return;
    scratch.owner=owner;
    scratch.axisC=EntryHardware::_mm_setr_ps(DAT_01011d78,DAT_01011d78,DAT_01012068,DAT_01011d78);
    scratch.axisD=scratch.axisC;
    scratch.strength=DAT_01267d90;
    entries.resize(count);
    for (unsigned i=0;i<count;++i) {
        GameForm* actor;
        {
            ResourceName name(input->at(i));
            actor=BSUtilities_GetObjectByName_00c4b470(getContext(),name,1);
        }
        GameForm* linked=actor ? actor->getChildNamed():0;
        GameForm* nested=linked ? linked->getLinked():0;
        Resource* pActorResource=actor ? bhkUtilFunctions_FindNextCollisionObject(actor):0;
        Resource* secondResource=linked ? bhkUtilFunctions_FindNextCollisionObject(linked):0;
        Resource* thirdResource=nested ? bhkUtilFunctions_FindNextCollisionObject(nested):0;
        Geo* geo=bhkRagdollController_GetCapsuleBoneShapeInfo(nested);
        float expansion=geo ? geo->expansion:0.0f;
        scratch.threshold=(float)(expansion+DAT_010c4dd0);
        scratch.radius=(float)(expansion+DAT_010c4dc8);
        radius=scratch.radius;
        int first=materialName(pActorResource);
        int second=materialName(secondResource);
        int third=materialName(thirdResource);
        if (second && third && pActorResource!=secondResource && pActorResource!=thirdResource && thirdResource!=secondResource) {
            scratch.first=FindIndexByKey(owner,first,0);
            scratch.second=FindIndexByKey(owner,second,0);
            scratch.third=FindIndexByKey(owner,third,0);
            if (scratch.first!=-1 && scratch.second!=-1 && scratch.third!=-1)
                entries[i].record=new FUN_00cd8820(scratch);
        }
        if (table->mapping) {
            for (int j=0;j<table->mapping->count;++j) {
                MappingEntry* mapped=&table->mapping->data[j];
                if (mapped->source==scratch.third) entries[i].mapped=mapped->target;
            }
        }
    }
    bool success=true;
    for (unsigned j=0;j<count && success;++j) {
        if (!entries[j].record) success=false;
    }
    if (!success) {
        for (unsigned j=0;j<count;++j) {
            IndexedRecord* record=entries[j].record;
            if (record) record->FUN_00c905b0();
        }
        entries.count=0;
    }
    complete=success;
}

extern "C" LocalM128 _mm_mul_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128,LocalM128,int);
extern "C" LocalM128 _mm_add_ss(LocalM128,LocalM128);
extern "C" void _mm_store_ss(float*,LocalM128);
struct VectorStorage {protected:LocalM128 value; __forceinline VectorStorage(){} __forceinline VectorStorage(const LocalM128& v):value(v){} };
struct VecLane:private VectorStorage {
private:
public:
 __forceinline VecLane() {}
 __forceinline VecLane(const VecLane& rhs):VectorStorage(rhs.value) {}
 __forceinline void operator=(const VecLane& rhs) { setRaw(rhs.getRaw()); }
 __forceinline void operator=(const LocalM128& rhs) { value=rhs; }
 __forceinline LocalM128 getRaw() const{return value;}
 __forceinline void setRaw(LocalM128 v){value=v;}
 __forceinline operator LocalM128() const { return getRaw(); }
};
struct QuatLane {VecLane value; __forceinline void operator=(const QuatLane& rhs) {value=rhs.value;} };
struct Transform48 {VecLane translation; QuatLane rotation; VecLane scale;};
template<class T> struct FieldStorage {protected:T value; __forceinline FieldStorage(){} __forceinline FieldStorage(T v):value(v){} };
template<class T> class MemberValue:private FieldStorage<T> {
public:
 __forceinline MemberValue() {}
 __forceinline MemberValue(T p):FieldStorage<T>(p) {}
 __forceinline void operator=(T p) {value=p;}
 __forceinline T val() const {return value;}
 __forceinline operator T() const {return val();}
 __forceinline T operator->() const {return val();}
};
struct TempAllocator {
 virtual void v0();virtual void v4();virtual void v8();
 virtual void* Allocate(int&);
 virtual void Free(void*,int);
 template<class T> __forceinline T* allocateItems(int& n) {int bytes=n*(int)sizeof(T);void* p=Allocate(bytes);n=bytes/(int)sizeof(T);return (T*)p;}
 template<class T> __forceinline void freeItems(T* p,int n) {Free(p,n*sizeof(T));}
};
struct ArenaStack {
 MemberValue<void*> next;
 MemberValue<void*> start;
 MemberValue<void*> end;
 __forceinline int freeBytes() const {return (int)((char*)end.val()-(char*)next.val());}
 __forceinline void* allocate(int bytes,const char* tag) {
  if(bytes>freeBytes()) {}
  void* old=next;
  next=(char*)old+bytes;
  return old;
 }
 __forceinline void release(void* p) {next=p;}
};
struct ScratchState {ArenaStack arena;int unk0c;TempAllocator* allocator;
 __forceinline TempAllocator& heap() {return *allocator;}
 __forceinline ArenaStack& stack() {return arena;}
};
__forceinline ScratchState& getRouter() {return *(ScratchState*)(&hkMemoryRouter::getInstance());}
template<class T> __forceinline T* allocateScratch(int n,const char* tag=0) {
 ScratchState& a=getRouter();
 return (T*)a.stack().allocate((n*(int)sizeof(T)+127)&~127,tag);
}
template<class T> __forceinline void freeScratch(T* p) {getRouter().stack().release((void*)p);}
template<class T> struct RagdollUpdateFixedBuffer {
 MemberValue<T*> data;int debugSize;
 __forceinline RagdollUpdateFixedBuffer() {}
 __forceinline T& operator[](int i) {return data[i];}
 __forceinline T* begin() {return data;}
 __forceinline const T* begin() const {return data;}
};
template<class T> struct LocalBuffer:RagdollUpdateFixedBuffer<T> {
 __forceinline LocalBuffer(int n,const char* tag=0) {data=allocateScratch<T>(n,tag);}
 __forceinline ~LocalBuffer() {freeScratch(data.val());}
};
typedef LocalBuffer<Transform48> ScratchTransforms;
template<class T> struct OwnedBase {
 T* data;int size,capacity;
 __forceinline OwnedBase():data(0),size(0),capacity(0x80000000) {}
 __forceinline void setOwned(T* p,int n,int cap) {data=p;size=n;capacity=cap;}
 __forceinline T* begin() {return data;}
 __forceinline void clearFree(TempAllocator& a) {size=0;if(!(capacity&0x80000000)) a.freeItems(data,capacity&0x3fffffff);data=0;capacity=0x80000000;}
};
struct HeapPolicy {template<class T> __forceinline TempAllocator& get(T*) {return getRouter().heap();}};
template<class T,class P=HeapPolicy> struct OwnedBuffer:OwnedBase<T> {
 __forceinline OwnedBuffer(int n) {TempAllocator& a=P().get(this);T* p=n?a.allocateItems<T>(n):0;int cap=n?n:0x80000000;setOwned(p,n,cap);}
 __forceinline ~OwnedBuffer() {clearFree(P().get(this));}
};
typedef OwnedBuffer<int> IntBuffer;
struct LaneScalar {
 PackedVector storage;
 __forceinline LaneScalar(const LocalM128& v){storage.vector=v;}
 __forceinline operator float() const {float v;_mm_store_ss(&v,storage.vector);return v;}
};
struct VelocityVector {
 LocalM128 value;
 __forceinline LaneScalar dot(const VelocityVector& r) const {
  LocalM128 m=_mm_mul_ps(value,r.value);
  LocalM128 t=_mm_shuffle_ps(m,m,0x55);
  t=_mm_add_ss(t,m);
  m=_mm_shuffle_ps(m,m,0xaa);
  return LaneScalar(_mm_add_ss(m,t));
 }
 __forceinline LaneScalar lengthSquared() const {return dot(*this);}
};
extern float DAT_010c7948[];
struct SmallFloat {
 unsigned char index;
 __forceinline operator float() const {return DAT_010c7948[index];}
};
template<class T> struct ArrayBaseView {
 T* data;int size,capacity;
 __forceinline T* begin() {return data;}
 __forceinline const T* begin() const {return data;}
 __forceinline int GetLogicalSize() const {return size;}
 __forceinline T& operator[](int i) {return data[i];}
 __forceinline const T& operator[](int i) const {return data[i];}
};
template<class T> struct ArrayView:ArrayBaseView<T> {};
struct SkeletonData {
 int unk00,unk04,unk08;ArrayView<short> parents;ArrayView<void*> boneList;ArrayView<Transform48> poseList;
 __forceinline int getCount() const {return boneList.GetLogicalSize();}
 __forceinline const short* getParents() const {return parents.begin();}
 __forceinline const Transform48* getPoses() const {return poseList.begin();}
};
struct BoneState {
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
 SmallFloat scaleIndex; unsigned char unk19d; unsigned short unk19e;
 int unk1a0, unk1a4, unk1a8, unk1ac;
 VelocityVector velocity;
};
struct Skeleton {
 int unk00,unk04;ArrayView<BoneState*> stateList;ArrayView<void*> constraints;ArrayView<int> indexList;SkeletonData* data;
 __forceinline SkeletonData* getData() const {return data;}
 __forceinline int getNumBones() const {return getData()->getCount();}
 __forceinline BoneState* getBody(int i) const {int k=indexList[i];return k>=0?stateList[k]:0;}
 void hkaRagdollInstance_setPoseWorldSpace(Transform48*,void*);
};
struct Processor {
 void hkaRagdollRigidBodyController_reinitialize();
 void hkaRagdollRigidBodyController_driveToPose(float delta, Transform48* transforms, void* settings, int* results);
};
struct PoseLookup { void** hkaPose_getSyncedPoseModelSpace(); };
struct BlendData { int unk00,unk04,unk08,unk0c; void* data; };
extern float DAT_011afe64;
extern float DAT_010c7948[];
void UpdateEntriesByKind(Skeleton*);
void EnableBehaviorsByKind(Skeleton*);
void bhkRagdollController_bhkRagdollPoweredConstraintController_driveToPose(Skeleton*, Transform48*);
void CallWithGlobal(int, void*, void*, Transform48*);
void hkaSkeletonUtils_transformModelPoseToLocalPose(int, void*, Transform48*, Transform48*);
void mapPose(void*,void*,void*,Transform48*,int);
struct RagdollUpdateController {
 int unk00; bool needsInit; unsigned char unk05; unsigned short unk06; int unk08; int mode;
 int settings10, settings14, settings18, settings1c, settings20, settings24, settings28, settings2c, settings30, settings34, settings38, settings3c, settings40;
 bool forceMode; unsigned char unk45; unsigned short unk46;
 Skeleton* skeleton; Processor* processor; bool active; unsigned char unk51; unsigned short unk52;
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
 PoseLookup* lookup;
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
 BlendData* blend;
 void bhkRagdollController_UpdateRagdollRigidBodies(const Transform48* input);
};
// @fnv 0x00c7d030
// src: XBOX_PDB 0x00c7d030
void RagdollUpdateController::bhkRagdollController_UpdateRagdollRigidBodies(const Transform48* input) {
 SkeletonData* data=skeleton->getData();
 int count=data->getCount();
 ScratchTransforms outputStorage(count);
 Transform48* output=outputStorage.begin();
 ScratchTransforms poseStorage(count);
 Transform48* pose=poseStorage.begin();
 int oldMode=mode;
 if(forceMode) mode=1;
 if(needsInit) { UpdateEntriesByKind(skeleton); needsInit=false; }
 if(!input) {
  CallWithGlobal(count,(void*)data->getParents(),(void*)data->getPoses(),pose);
  void* referencePoses=(void*)data->getPoses();
  void* poseTrack=*lookup->hkaPose_getSyncedPoseModelSpace();
  BlendData* currentBlend=blend;
  mapPose(currentBlend->data,poseTrack,referencePoses,pose,2);
  if(mode!=1) { void* bones=(void*)data->getParents(); hkaSkeletonUtils_transformModelPoseToLocalPose(count,bones,pose,output); }
 } else {
  for(int i=0;i<count;++i) outputStorage[i]=input[i];
 }
 switch(mode) {
 case 3: EnableBehaviorsByKind(skeleton); bhkRagdollController_bhkRagdollPoweredConstraintController_driveToPose(skeleton,output); mode=0; break;
 case 2:
  if(active) { processor->hkaRagdollRigidBodyController_reinitialize(); active=false; }
  if(DAT_011afe64>0.0f) {
   IntBuffer results(count);
   processor->hkaRagdollRigidBodyController_driveToPose(DAT_011afe64,output,&settings10,results.begin());
   bool fast=false;
   for(int index=0;index<skeleton->getNumBones();++index) {
    if(fast) break;
    {
     BoneState* state=skeleton->getBody(index);
     if(state) {
      float magnitude=state->velocity.lengthSquared();
      float limit=state->scaleIndex;
      limit=limit*limit;
      fast=magnitude>limit;
     }
    }
   }
   if(fast) { skeleton->hkaRagdollInstance_setPoseWorldSpace(pose,&settings10); active=true; }
  }
  break;
 case 1: { Skeleton* current=skeleton; current->hkaRagdollInstance_setPoseWorldSpace(pose,&settings10); break; }
 }
 if(forceMode) { mode=oldMode; forceMode=false; }
}

extern "C" LocalM128 _mm_setzero_ps();
namespace ControllerFloatHardware { extern "C" LocalM128 _mm_set_ps1(float); }
extern void* DAT_010c4ddc;
extern void* DAT_01071aec;
extern void* DAT_010c4db8;
extern char* DAT_0109b220;
extern const float DAT_010c4df8;
extern const float DAT_01022958;
extern const float DAT_01017868;
extern const LocalM128 DAT_010c71b0;
struct RefTarget {
    virtual void unused();
    virtual void destroy();
    volatile long refs;
};
struct RefSlot {
    RefTarget* object;
    RefSlot():object(0){}
    ~RefSlot();
    void clear() { RefTarget* old=object; if(old) { if(!InterlockedDecrement(&old->refs)) old->destroy(); object=0; } }
};
struct RefSlotArray {
    unsigned int data, size, capacity;
    RefSlotArray():data(0),size(0),capacity(0x80000000){}
    ~RefSlotArray();
};
struct SmallArray {
    void* vtable; unsigned int data,size,capacity;
    SmallArray():vtable(&DAT_01071aec),data(0),size(0),capacity(0){}
    ~SmallArray();
};
struct NameSlot {
    char* name;
    NameSlot():name(DAT_0109b220){}
    ~NameSlot();
};
struct NamePair { NameSlot name; unsigned int value; NamePair():value(0){} };
struct PlainArray {
    unsigned int data,size,capacity,extra;
    PlainArray():data(0),size(0),capacity(0),extra(0){}
    ~PlainArray();
};
struct __declspec(align(16)) StateRecord {
    unsigned int unk00;
    short first,second;
    float weight;
    unsigned int unk0c;
    LocalM128 position,velocity,rotation;
    bool active,valid;
    unsigned short unk42;
    float time,blend;
    unsigned int unk4c;
};
struct NodeArg {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual NiNode* get();
};
struct TempArray {
    void* vtable; unsigned int data,size,capacity;
    TempArray():vtable(&DAT_010c4db8),data(0),size(0),capacity(0){}
    ~TempArray();
};
typedef void (__thiscall *FreeTemp)(TempArray*,unsigned int);
extern FreeTemp DAT_010c4dc0;
TempArray::~TempArray() { vtable=&DAT_010c4db8; if(data) DAT_010c4dc0(this,data); }
extern void __cdecl bhkRagdollController_CopyPoseTo3D(NiNode*,NiNode*,TempArray*,bool*,unsigned int*);
extern void __cdecl RestoreNodeTransforms(NiNode*,TempArray*,bool,unsigned int);
struct ConstructorBase { virtual ~ConstructorBase(); };
struct LastArray { unsigned int data,size,capacity,extra; LastArray():data(0),size(0),capacity(0),extra(0){} };
struct ThirdArg { unsigned int value; };
union NodeOrFlag { NodeArg* node; bool flag; };
struct VecStore { LocalM128 value; VecStore& operator=(LocalM128 other) { value=other; return *this; } };
union SimdVector { LocalM128 value; signed char lanes[16]; };
class FUN_00c7f060 : public ConstructorBase {
public:
    bool unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    float unk08;
    int unk0c;
    VecStore unk10;
    VecStore unk20;
    VecStore unk30;
    bool unk40;
    bool unk41;
    bool unk42;
    bool unk43;
    bool unk44;
    unsigned char unk45;
    unsigned char unk46;
    unsigned char unk47;
    unsigned int unk48;
    unsigned int unk4c;
    bool unk50;
    unsigned char unk51;
    unsigned char unk52;
    unsigned char unk53;
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
    RefSlot ref84;
    unsigned int unk88;
    bool unk8c;
    unsigned char unk8d;
    unsigned char unk8e;
    unsigned char unk8f;
    unsigned int unk90;
    RefSlotArray array94;
    SmallArray arraya0;
    bool unkb0;
    bool unkb1;
    bool unkb2;
    bool unkb3;
    bool unkb4;
    unsigned char unkb5;
    unsigned char unkb6;
    unsigned char unkb7;
    unsigned int unkb8;
    unsigned int unkbc;
    LocalM128 unkc0;
    LocalM128 unkd0;
    LocalM128 unke0;
    StateRecord records[2];
    bool unk190;
    unsigned char unk191;
    unsigned char unk192;
    unsigned char unk193;
    unsigned int unk194;
    bool unk198;
    unsigned char unk199;
    unsigned char unk19a;
    unsigned char unk19b;
    float unk19c;
    float unk1a0;
    bool unk1a4;
    bool unk1a5;
    unsigned char unk1a6;
    unsigned char unk1a7;
    float unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned char unk1bc;
    bool unk1bd;
    unsigned char unk1be;
    unsigned char unk1bf;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned char unk1ec;
    bool unk1ed;
    unsigned char unk1ee;
    unsigned char unk1ef;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    bool unk21c;
    bool unk21d;
    bool unk21e;
    bool unk21f;
    bool unk220;
    bool unk221;
    bool unk222;
    bool unk223;
    bool unk224;
    unsigned char unk225;
    unsigned char unk226;
    unsigned char unk227;
    unsigned int unk228;
    RefSlotArray array22c;
    unsigned short unk238;
    unsigned short unk23a;
    float unk23c;
    bool unk240;
    bool unk241;
    bool unk242;
    bool unk243;
    float unk244;
    unsigned int unk248;
    NamePair name24c;
    bool unk254;
    bool unk255;
    bool unk256;
    unsigned char unk257;
    unsigned int unk258;
    unsigned int unk25c;
    PlainArray array260;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    float unk27c;
    float unk280;
    bool unk284;
    unsigned char unk285;
    unsigned char unk286;
    unsigned char unk287;
    unsigned int unk288;
    bool unk28c;
    bool unk28d;
    bool unk28e;
    bool unk28f;
    float unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    NameSlot name2a0;
    RefSlot ref2a4;
    LastArray array2a8;
    unsigned int unk2b8;
    virtual ~FUN_00c7f060();
    FUN_00c7f060(NodeArg*,NodeOrFlag,void*);
    void bhkRagdollController_Init(NodeArg*,void*);
};
// @fnv 0x00c7f060
FUN_00c7f060::FUN_00c7f060(NodeArg* a,NodeOrFlag b,void* c) {
    unk23c=0.0f;
    unk48=0; unk4c=0; unk50=0; unk54=0; unk58=0; unk5c=0;
    unk240=false; unk241=true; unk242=true;
    SimdVector zero; zero.value=_mm_setzero_ps();
    for(int i=0;i<2;++i) {
        records[i].first=-1; records[i].second=-1;
        records[i].weight=1.04719758f;
        records[i].position=zero.value; records[i].velocity=zero.value;
        records[i].valid=false; records[i].active=true;
        records[i].rotation=DAT_010c71b0;
        records[i].time=0.0f; records[i].blend=0.0f;
    }
    unkd0=zero.value; unke0=zero.value; unkb4=false; unkc0=DAT_010c71b0;
    unk1a0=0.0f; unk19c=0.0f; unk1a8=0.0f;
    unk1a4=false; unk1a5=false;
    unk42=0; unkb0=0; unk21f=0; unk21c=0;
    unk41=0; unkb1=0; unk220=0; unk21d=0; unk255=0;
    unk43=0; unkb2=0; unk221=0; unkb3=0; unk222=0; unk21e=0;
    unk256=0; unk1bd=0; unk1ed=0; unk228=0; unk254=0;
    unk190=0; unk194=0;
    ref84.clear();
    unk248=0; unk258=-1;
    ref2a4.clear();
    unk88=0; unk290=1.0f; unk8c=0; unk28c=0; unk28d=0; unk244=0.0f;
    unk28e=0; unk28f=0; unk294=0; unk243=0; unk223=0; unk90=0;
    unk0c=2; unk10=zero.value; unk20=DAT_010c71b0; unk30=ControllerFloatHardware::_mm_set_ps1(1.0f);
    unk280=10000.0f; unk27c=20.0f; unk23a=0; unk08=0.0f;
    unk40=0; unk284=1; unk288=-1; unk44=0; unk04=0; unk198=0; unk224=1; unk238=0;
    NiNode* first=a?a->get():0;
    NiNode* second=b.node?b.node->get():0;
    b.flag=false;
    unsigned int count;
    if(first && second) count=0; else count=0;
    TempArray temp;
    if(first && second) bhkRagdollController_CopyPoseTo3D(first,second,&temp,&b.flag,&count);
    bhkRagdollController_Init(a,c);
    RestoreNodeTransforms(first,&temp,b.flag,count);
    unk2b8=0;
}

namespace InversePositionHardware {
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
}
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_rcp_ps(LocalM128);
extern const LocalM128 g_rotationOffset;

struct InversePositionVector : Vec4 {
    void hkVector4_setTransformedInversePos_00c7f840(const Vec4* t, const Vec4* p);
};

// @fnv 0x00c7f840
// src: COMMUNITY 0x00c7f840
void InversePositionVector::hkVector4_setTransformedInversePos_00c7f840(const Vec4* t, const Vec4* p)
{
    const LocalM128 d = InversePositionHardware::_mm_sub_ps(p->m_vComponents, t[0].m_vComponents);
    const LocalM128 q = t[1].m_vComponents;
    const LocalM128 w4 = _mm_shuffle_ps(q, q, 0xff);
    const LocalM128 qd = _mm_mul_ps(q, d);
    LocalM128 dot = _mm_add_ss(_mm_shuffle_ps(qd, qd, 0x55), qd);
    dot = _mm_add_ss(_mm_shuffle_ps(qd, qd, 0xaa), dot);
    const LocalM128 c1 = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), _mm_shuffle_ps(d, d, 0xd2));
    const LocalM128 c2 = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2), _mm_shuffle_ps(d, d, 0xc9));
    const LocalM128 cr = InversePositionHardware::_mm_sub_ps(c2, c1);
    LocalM128 r = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w4, w4), g_rotationOffset), d);
    r = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q));
    r = _mm_add_ps(_mm_mul_ps(cr, w4), r);
    const LocalM128 v = _mm_add_ps(r, r);
    m_vComponents = v;
    const LocalM128 s = t[2].m_vComponents;
    const LocalM128 rc = _mm_rcp_ps(s);
    const LocalM128 e = _mm_mul_ps(_mm_mul_ps(rc, s), rc);
    m_vComponents = _mm_mul_ps(InversePositionHardware::_mm_sub_ps(_mm_add_ps(rc, rc), e), v);
}

// src: COMMUNITY 0x00c66320
inline __declspec(noinline) void ActorQuaternionLocal_00ce3a00::setMul(const ActorQuaternionLocal_00ce3a00& q0, const ActorQuaternionLocal_00ce3a00& q1) {
    ActorVectorLocal_00ce3a00 vec;
    vec.setCross(q0.getImag(), q1.getImag());
    vec.addMul4(q0.m_vec.getSimdAt(3), q1.getImag());
    vec.addMul4(q1.m_vec.getSimdAt(3), q0.getImag());
    ActorVectorLocal_00ce3a00 dot;
    dot.SetAllComponents(q0.m_vec.dot3(q1.m_vec));
    ActorVectorLocal_00ce3a00 w;
    w.setMul4(q0.m_vec, q1.m_vec);
    w.sub4(dot);
    m_vec.setXYZW(vec, w);
}

__forceinline hkQsTransform::hkQsTransform() {}
__forceinline const ActorVectorLocal_00ce3a00& hkQsTransform::getTranslation() const { return m_vTranslation; }
__forceinline const ActorQuaternionLocal_00ce3a00& hkQsTransform::getRotation() const { return m_rotation; }
__forceinline void hkQsTransform::SetBodyOrientation(const ActorQuaternionLocal_00ce3a00& rotation) { m_rotation = rotation; }
__forceinline void hkQsTransform::operator=(const hkQsTransform& t) {
    m_vTranslation = t.m_vTranslation;
    m_rotation = t.m_rotation;
    m_vScale = t.m_vScale;
}
__forceinline void hkQsTransform::SetProduct(const hkQsTransform& kLeft, const hkQsTransform& kRight) {
    ActorVectorLocal_00ce3a00 kMovedTrans;
    kMovedTrans.SetRotatedDirection(kLeft.m_rotation, kRight.m_vTranslation);
    m_vTranslation.setAdd4(kLeft.m_vTranslation, kMovedTrans);
    m_rotation.setMul(kLeft.m_rotation, kRight.m_rotation);
    m_vScale.setMul4(kLeft.m_vScale, kRight.m_vScale);
}

__forceinline void ActorVectorLocal_00ce3a00::SetRotatedDirection(const ActorQuaternionLocal_00ce3a00& quat, const ActorVectorLocal_00ce3a00& direction) {
    ActorVectorLocal_00ce3a00 minusHalf; minusHalf.getQuad() = DAT_010c71e0;
    ActorVectorLocal_00ce3a00 qreal;
    qreal.setBroadcast(quat.m_vec, 3);
    ActorVectorLocal_00ce3a00 q2minus1;
    q2minus1.setAddMul4(minusHalf, qreal, qreal);

    ActorVectorLocal_00ce3a00 ret;
    ret.setMul4(direction, q2minus1);

    ActorVectorLocal_00ce3a00 imagDotDir;
    imagDotDir.getQuad() = quat.getImag().dot3(direction).getQuad();
    imagDotDir.broadcast(0);
    ret.addMul4(imagDotDir, quat.getImag());

    ActorVectorLocal_00ce3a00 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

__forceinline void ActorVectorLocal_00ce3a00::_setTransformedPos(const hkQsTransform& a, const ActorVectorLocal_00ce3a00& b) {
    ActorVectorLocal_00ce3a00 temp(b);
    temp.mul4(a.m_vScale);
    SetRotatedDirection(a.m_rotation, temp);
    add4(a.m_vTranslation);
}

namespace MathUtilities {
    __forceinline void prefetch128(const void* p) { (_mm_prefetch)((const char*)p, 0); }
}
template <class T> __forceinline const T* hkAddByteOffsetConst(const T* base, long offset) {
    return reinterpret_cast<const T*>(reinterpret_cast<const char*>(base) + offset);
}

template <class T> __forceinline void hkMemoryAllocator::_bufFree(void* p, int numElem) { bufFree(p, numElem * sizeof(T)); }


template <class T> __forceinline T* hkAddByteOffset(T* base, long offset) {
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}

__forceinline void hkStackMemory::deallocateStack(void* p) { m_next = p; }


template <class T> __forceinline T* hkAllocateStack(int n, const char* what = 0) {
    hkMemoryRouter& mem = hkMemoryRouter::getInstance();
    return static_cast<T*>(mem.stack().allocateStack(((n * (int)sizeof(T)) + 127) & ~127, what));
}
template <class T> __forceinline void hkDeallocateStack(T* ptr) {
    hkMemoryRouter::getInstance().stack().deallocateStack(static_cast<void*>(ptr));
}

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*) { return hkMemoryRouter::getInstance().heap(); }

namespace HavokArrayUtilities {
    template <class T> __forceinline void destruct(T*, int, hkTypeIsPod) {}
}

template <class T> __forceinline void hkArrayBase<T>::clear() { HavokArrayUtilities::destruct(m_data, m_iElementCount, hkTypeIsPod()); m_iElementCount = 0; }
template <class T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc) {
    clear();
    if ((m_iCapacityState & 0x80000000) == 0) alloc._bufFree<T>(m_data, getCapacity());
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
template <class T> class StackAllocatedArray : public hkArrayBase<T> {
public:
    __forceinline void init(int capacity) {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
        this->m_data = hkAllocateStack<T>(capacity);
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline hkBool wasReallocated() const { return m_pStackAllocation != this->m_data; }
    __forceinline void destroy() {
        if (!wasReallocated()) hkArrayBase<T>::clear();
        hkDeallocateStack<T>(m_pStackAllocation);
        hkArrayBase<T>::_clearAndDeallocate(hkContainerHeapAllocator().get(this));
    }
    T* m_pStackAllocation;
};


hkBool __cdecl WalkChainUntilLimit(const hkaSkeleton& skeleton, short start, short end, hkArray<short>& chain);
extern "C" void __cdecl hkaSkeleton_RestoreLockedBoneTranslations(const hkaSkeleton& skeleton, hkQsTransform* pose);
extern "C" void __cdecl hkQsTransform_ProcessEntries_00cde2d0(const hkaSkeleton& skeleton, const hkQsTransform* ref, hkQsTransform* pose);

// Preserve the original access types when viewing the shared mapper storage.
template <class T> class ReferenceCountedPointer {
public:
    __forceinline T* val() const { return m_pRetainedObject; }
    __forceinline T* operator->() const { return val(); }
    __forceinline operator T*() const { return val(); }
    T* m_pRetainedObject;
};

class __declspec(align(16)) hkaSkeletonMapperDataSimpleMapping {
public:
    short m_sBoneA;
    short m_sBoneB;
    hkQsTransform m_kAFromBTransform;
};

class __declspec(align(16)) hkaSkeletonMapperDataChainMapping {
public:
    short m_sStartBoneA;
    short m_sEndBoneA;
    short m_sStartBoneB;
    short m_sEndBoneB;
    hkQsTransform m_kStartAFromBTransform;
    hkQsTransform m_kEndAFromBTransform;
};

#include "../../../include/hkThreadLocalData.h"
// Havok's monitor-stream TLS slot (hkMonitorStream::m_instance).
extern "C" hkThreadLocalData<void*> DAT_0126835c;

__forceinline hkMonitorStream& hkMonitorStream::getInstance() { return *(hkMonitorStream*)DAT_0126835c.getData(); }
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline hkBool __cdecl hkMonitorStream::memoryAvailable() { return getEnd() < getCapacityMinus16(); }
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end = ptr; }
__forceinline void hkMonitorStream::TimerCommand::setTime() {
    unsigned int ticks;
    __asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
    m_time0 = ticks;
}

// src: GUESS 0x00ce2a50 (confidence: low)
static __declspec(noinline) void hkVector4_ComputeValues_00ce2a50(ActorVectorLocal_00ce3a00& a, ActorVectorLocal_00ce3a00& b) {
    ActorVectorLocal_00ce3a00 aLen; aLen.SetAllComponents(a.lengthSquared3());
    ActorVectorLocal_00ce3a00 bLen; bLen.SetAllComponents(b.lengthSquared3());
    ActorVectorLocal_00ce3a00 lens; lens.setXYZW(aLen, bLen);
    ActorVectorLocal_00ce3a00 inv; inv.setSqrtInverse4(lens);
    a.mul4(inv.getSimdAt(0));
    b.mul4(inv.getSimdAt(3));
}


// @fnv 0x00ce3a00
// src: XBOX_PDB 0x00ce3a00
void __cdecl hkaSkeletonMapper::mapPose(const hkQsTransform* poseAModelSpace, const hkQsTransform* originalPoseBLocalSpace, hkQsTransform* poseBModelSpace, int source) const {
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable()) {
            hkMonitorStream::TimerBeginListCommand* h = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "LtMapPoseModelSpace";
            h->m_nameOfFirstSplit = "Stinit";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable()) {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "StsimpleMappings";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
    {
        const int numSimpleMappings = (reinterpret_cast<const hkArray<hkaSkeletonMapperDataSimpleMapping>&>(m_kMappingData.m_kSimpleMappings)).GetLogicalSize();
        for (int i = 0; i < numSimpleMappings; i++) {
            const int prefetchDistance = 128;
            MathUtilities::prefetch128(hkAddByteOffsetConst(&(reinterpret_cast<const hkArray<hkaSkeletonMapperDataSimpleMapping>&>(m_kMappingData.m_kSimpleMappings))[i], prefetchDistance));
            const hkaSkeletonMapperDataSimpleMapping& simpleMapping = (reinterpret_cast<const hkArray<hkaSkeletonMapperDataSimpleMapping>&>(m_kMappingData.m_kSimpleMappings))[i];
            poseBModelSpace[simpleMapping.m_sBoneB].SetProduct(poseAModelSpace[simpleMapping.m_sBoneA], simpleMapping.m_kAFromBTransform);
            MathUtilities::prefetch128(hkAddByteOffsetConst(&poseAModelSpace[simpleMapping.m_sBoneA], prefetchDistance));
            MathUtilities::prefetch128(hkAddByteOffsetConst(&poseBModelSpace[simpleMapping.m_sBoneB], prefetchDistance));
        }
    }
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable()) {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "StchainMappings";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
    {
        const int numChainMappings = (reinterpret_cast<const hkArray<hkaSkeletonMapperDataChainMapping>&>(m_kMappingData.m_kChainMappings)).GetLogicalSize();
        for (int i = 0; i < numChainMappings; i++) {
            const hkaSkeletonMapperDataChainMapping& chainMapping = (reinterpret_cast<const hkArray<hkaSkeletonMapperDataChainMapping>&>(m_kMappingData.m_kChainMappings))[i];
            const short startBoneA = chainMapping.m_sStartBoneA;
            const short endBoneA = chainMapping.m_sEndBoneA;
            const short startBoneB = chainMapping.m_sStartBoneB;
            const short endBoneB = chainMapping.m_sEndBoneB;

            poseBModelSpace[startBoneB].SetProduct(poseAModelSpace[startBoneA], chainMapping.m_kStartAFromBTransform);

            StackAllocatedArray<short> chainBones;
            chainBones.init(endBoneB - startBoneB + 1);
            WalkChainUntilLimit(*(reinterpret_cast<const ReferenceCountedPointer<const hkaSkeleton>&>(m_kMappingData.m_pSkeletonB)), startBoneB, endBoneB, static_cast<hkArray<short>&>(static_cast<hkArrayBase<short>&>(chainBones)));

            ActorVectorLocal_00ce3a00 currentEndModelSpacePos;
            currentEndModelSpacePos = originalPoseBLocalSpace[endBoneB].getTranslation();
            for (int b = chainBones.GetLogicalSize() - 2; b >= 1; b--) {
                const short bone = chainBones[b];
                currentEndModelSpacePos._setTransformedPos(originalPoseBLocalSpace[bone], currentEndModelSpacePos);
            }
            currentEndModelSpacePos._setTransformedPos(poseBModelSpace[startBoneB], currentEndModelSpacePos);

            {
                const ActorVectorLocal_00ce3a00& startModelSpacePos = poseBModelSpace[startBoneB].getTranslation();
                hkQsTransform desiredEndModelSpace;
                desiredEndModelSpace.SetProduct(poseAModelSpace[endBoneA], chainMapping.m_kEndAFromBTransform);
                const ActorVectorLocal_00ce3a00& desiredEndModelSpacePos = desiredEndModelSpace.getTranslation();

                ActorVectorLocal_00ce3a00 currentDirection; currentDirection.setSub4(currentEndModelSpacePos, startModelSpacePos);
                ActorVectorLocal_00ce3a00 desiredDirection; desiredDirection.setSub4(desiredEndModelSpacePos, startModelSpacePos);
                hkVector4_ComputeValues_00ce2a50(currentDirection, desiredDirection);

                ActorQuaternionLocal_00ce3a00 rotationQuaternion;
                rotationQuaternion.ComputeValues_00cd9d10(currentDirection, desiredDirection);

                ActorQuaternionLocal_00ce3a00 currentRot = poseBModelSpace[startBoneB].getRotation();
                ActorQuaternionLocal_00ce3a00 temp;
                temp.setMul(rotationQuaternion, currentRot);
                poseBModelSpace[startBoneB].SetBodyOrientation(temp);
            }

            for (int b = 1; b < chainBones.GetLogicalSize() - 1; b++) {
                const short childIdx = chainBones[b];
                const short parentIdx = chainBones[b - 1];
                const hkQsTransform& parentFromChild = originalPoseBLocalSpace[childIdx];
                const hkQsTransform& modelFromParent = poseBModelSpace[parentIdx];
                poseBModelSpace[childIdx].SetProduct(modelFromParent, parentFromChild);
            }
            chainBones.destroy();
        }
    }
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable()) {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "StunmappedBones";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
    {
        const int numUnmapped = (reinterpret_cast<const hkArray<short>&>(m_kMappingData.m_kUnmappedBones)).GetLogicalSize();
        if (m_kMappingData.m_bKeepUnmappedLocal) {
            for (int i = 0; i < numUnmapped; i++) {
                const short boneIdx = (reinterpret_cast<const hkArray<short>&>(m_kMappingData.m_kUnmappedBones))[i];
                const short parentIdx = (reinterpret_cast<const ReferenceCountedPointer<const hkaSkeleton>&>(m_kMappingData.m_pSkeletonB))->m_kParentIndices.m_data[boneIdx];
                if (parentIdx != -1) {
                    const hkQsTransform& parentFromChild = originalPoseBLocalSpace[boneIdx];
                    const hkQsTransform& modelFromParent = poseBModelSpace[parentIdx];
                    poseBModelSpace[boneIdx].SetProduct(modelFromParent, parentFromChild);
                } else {
                    poseBModelSpace[boneIdx] = originalPoseBLocalSpace[boneIdx];
                }
            }
        }
    }
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable()) {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "StenforceConstraints";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
    switch (source) {
    case 1:
        hkaSkeleton_RestoreLockedBoneTranslations(*(reinterpret_cast<const ReferenceCountedPointer<const hkaSkeleton>&>(m_kMappingData.m_pSkeletonB)), poseBModelSpace);
        break;
    case 2:
        hkQsTransform_ProcessEntries_00cde2d0(*(reinterpret_cast<const ReferenceCountedPointer<const hkaSkeleton>&>(m_kMappingData.m_pSkeletonB)), originalPoseBLocalSpace, poseBModelSpace);
        break;
    }
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable()) {
            hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "lt";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

// ---- Gamebryo / game helpers ----
void* __cdecl NiMalloc(unsigned int size);
void __cdecl NiFree(void* p);
void* __cdecl _fnv_zlib_memset(void* dst, int val, unsigned int n);

struct MM {
    void Deallocate(void* p);
};
extern MM _g_memoryManager;

__forceinline hkStringPtr::hkStringPtr() throw() { Init(); }
__forceinline hkStringPtr::~hkStringPtr() throw() { release(); }
__forceinline hkaBone::hkaBone() { m_bLockTranslation = false; }
__forceinline void* hkaBone::operator new(unsigned int, void* p) { return p; }
__forceinline void hkaBone::operator delete(void*, void*) {}

inline hkMemoryAllocator* ReferenceHeapAllocator() {
    hkMemoryRouter* r = reinterpret_cast<hkMemoryRouter*>((&hkMemoryRouter::getInstance()));
    return r->m_heap;
}
__forceinline void* __cdecl hkReferencedObject::operator new(std::size_t n) {
    hkReferencedObject* b = static_cast<hkReferencedObject*>(ReferenceHeapAllocator()->blockAlloc(n));
    b->m_usMemSizeAndFlags = static_cast<unsigned short>(n);
    return b;
}
__forceinline void hkReferencedObject::operator delete(void* p, unsigned int n) {
    reinterpret_cast<hkMemoryRouter*>((&hkMemoryRouter::getInstance()))->m_heap->blockFree(p, n);
}

namespace SkeletonBuild {

// ---- Havok memory ----


int __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* array, int capacity, int elemSize);
const char* __cdecl hkString_strDup_00cb1410(int name);

inline hkMemoryAllocator* HeapAllocator()
{
    hkMemoryRouter* r = reinterpret_cast<hkMemoryRouter*>((&hkMemoryRouter::getInstance()));
    return r->m_heap;
}

template<class T> struct HkArrayLocalForm { // local form of hkArray: 0x00c7e3b0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    HkArrayLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~HkArrayLocalForm()
    {
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if (m_iCapacityState >= 0)
            HeapAllocator()->blockFree(m_data, getCapacity() * sizeof(T));
    }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocator* alloc = HeapAllocator();
        if (getCapacity() < n) {
            int cap2 = getCapacity() * 2;
            hkArrayUtil__reserve(alloc, this, n < cap2 ? cap2 : n, sizeof(T));
        }
    }
    __forceinline void reserveExactly(int n)
    {
        hkMemoryAllocator* alloc = HeapAllocator();
        if (getCapacity() < n)
            hkArrayUtil__reserve(alloc, this, n, sizeof(T));
    }
    __forceinline void setSizePod(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
    __forceinline void setSizeFill(int n, int fill)
    {
        reserve(n);
        int count = n - m_iElementCount;
        int* p = reinterpret_cast<int*>(m_data + m_iElementCount);
        for (int i = 0; i < count; ++i)
            p[i] = fill;
        m_iElementCount = n;
    }
    static __forceinline void destruct(T* t, int n)
    {
        for (int i = 0; i < n; ++i)
            t[i].~T();
    }
    static __forceinline void construct(T* t, int n)
    {
        for (int i = 0; i < n; ++i)
            new (t + i) T;
    }
    __forceinline void setSizeObj(int n)
    {
        reserve(n);
        destruct(m_data + n, m_iElementCount - n);
        construct(m_data + m_iElementCount, n - m_iElementCount);
        m_iElementCount = n;
    }
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
};

// The shared hkaSkeleton's arrays seen through this unit's HkArrayLocalForm.
template<class T, class U> __forceinline HkArrayLocalForm<T>& View(U& a) { return reinterpret_cast<HkArrayLocalForm<T>&>(a); }
template<class T, class U> __forceinline const HkArrayLocalForm<T>& View(const U& a) { return reinterpret_cast<const HkArrayLocalForm<T>&>(a); }
template<class T, class U> __forceinline void ConstructView(U& a) { View<T>(a).HkArrayLocalForm<T>::HkArrayLocalForm(); }

} // namespace SkeletonBuild

// HK_DECLARE_CLASS_ALLOCATOR: the same heap block as hkReferencedObject's.
__forceinline void* __cdecl hkaSkeleton::operator new(unsigned int n)
{
    return hkReferencedObject::operator new(n);
}

// The members' hkArray() constructors run (shared hkArray).
__forceinline hkaSkeleton::hkaSkeleton()
{
}

namespace SkeletonBuild {

struct SkeletonPoseData {
    const hkaSkeleton* m_pSkeleton;
    HkArrayLocalForm<hkQsTransform> m_pLocalPose;
    HkArrayLocalForm<hkQsTransform> m_pModelPose;
    HkArrayLocalForm<unsigned int> m_pBoneFlags;
    hkBool m_bPoseFlag;
    hkBool m_bPoseInitialized;
    HkArrayLocalForm<float> m_kPoseData;

    void* operator new(unsigned int n) { return HeapAllocator()->blockAlloc(n); }
    void operator delete(void* p, unsigned int n) { HeapAllocator()->blockFree(p, n); }

    __forceinline SkeletonPoseData(const hkaSkeleton* skeleton) : m_pSkeleton(skeleton), m_bPoseFlag(false), m_bPoseInitialized(false)
    {
        const int numBones = View<hkaBone>(m_pSkeleton->m_kBones).GetLogicalSize();
        m_pModelPose.setSizePod(numBones);
        m_pLocalPose.setSizePod(numBones);
        m_pBoneFlags.setSizePod(numBones);
        m_kPoseData.reserveExactly((View<hkStringPtr>(m_pSkeleton->m_kFloatSlots).GetLogicalSize() + 3) & ~3);
        m_kPoseData.setSizeFill(View<hkStringPtr>(m_pSkeleton->m_kFloatSlots).GetLogicalSize(), 0);
    }
    void hkaPose_setToReferencePose();
};

// ---- gathered bone records ----
struct BoneRecord {
    int name;
    int unk04;
    int unk08;
    int unk0c;
    hkQsTransform transform;
    short parent;
};

struct BoneRecordArray {
    BoneRecord** m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiMaxSize;
    BoneRecordArray() : m_pBase(0), m_uiSize(0), m_uiMaxSize(0) {}
    virtual ~BoneRecordArray()
    {
        if (m_pBase)
            Free(m_pBase);
    }
    virtual void* Alloc(unsigned int n);
    __declspec(dllimport) virtual void Free(void* p);
    void RemoveAll()
    {
        if (m_pBase) {
            Free(m_pBase);
            m_pBase = 0;
            m_uiMaxSize = 0;
            m_uiSize = 0;
        }
    }
};

// RTTI NiTMapBase<DFALL<NiTMapItem<NiAVObject *,short> >,NiAVObject *,short> (vftable 0x010c4cf8); the
// map below is NiTMap<NiAVObject *,short> (vftable 0x010c4d18).
struct NiTMapBase_NiAVObject_short {
    unsigned int m_uiHashSize;
    NiTMapItem<NiAVObject*, short>** m_ppkHashTable;
    unsigned int m_uiCount;
    NiTMapBase_NiAVObject_short(unsigned int uiHashSize = 37)
    {
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        unsigned int uiSize = sizeof(NiTMapItem<NiAVObject*, short>*) * m_uiHashSize;
        m_ppkHashTable = static_cast<NiTMapItem<NiAVObject*, short>**>(NiMalloc(uiSize));
        unsigned int bytes = m_uiHashSize * sizeof(NiTMapItem<NiAVObject*, short>*);
        _fnv_zlib_memset(m_ppkHashTable, 0, bytes);
    }
    virtual ~NiTMapBase_NiAVObject_short()
    {
        RemoveAll();
        NiFree(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(int key) const;
    void RemoveAll();
};

struct BoneRecordMap : NiTMapBase_NiAVObject_short {
    BoneRecordMap() {}
    virtual ~BoneRecordMap() { RemoveAll(); }
};

template<class T> struct PlainPtr {
    T* ptr;
    T* operator->() const { return ptr; }
    operator T*() const { return ptr; }
    T* operator=(T* p) { ptr = p; return p; }
};
struct SkeletonHolder {
    int unk00;
    int unk04;
    int unk08;
    hkaSkeleton* m_pSkeleton;
};

struct BuildNode {
    int key;
    int unk04;
    void* payload;
};
BuildNode* __cdecl bhkUtilFunctions_FindNextCollisionObject(void* root);

struct AnimationOwner {
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
    void* root;
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
    SkeletonPoseData* pose;
    int unk08c;
    int unk090;
    HkArrayLocalForm<hkQsTransform> transforms;
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
    PlainPtr<SkeletonHolder> skeletonHolder;

    void bhkRagdollController_CreateSGSkeletonRec(void* node, BoneRecordArray* records, BoneRecordMap* map);
    void bhkRagdollController_CreateSGSkeleton();
};

// @fnv 0x00c7e3b0
// src: COMMUNITY 0x00c7e3b0
void AnimationOwner::bhkRagdollController_CreateSGSkeleton()
{
    if (!root)
        return;

    void* node = bhkUtilFunctions_FindNextCollisionObject(root)->payload;
    BoneRecordArray records;
    BoneRecordMap map;
    bhkRagdollController_CreateSGSkeletonRec(node, &records, &map);

    SkeletonHolder* holder = skeletonHolder;
    if (!holder->m_pSkeleton) {
        skeletonHolder->m_pSkeleton = new hkaSkeleton;
        int numBones = records.m_uiSize;
        View<hkaBone>(skeletonHolder->m_pSkeleton->m_kBones).setSizeObj(numBones);
        View<short>(skeletonHolder->m_pSkeleton->m_kParentIndices).setSizePod(numBones);
        View<hkQsTransform>(skeletonHolder->m_pSkeleton->m_kReferencePose).setSizePod(numBones);
        for (unsigned int i = 0; i < records.m_uiSize; ++i) {
            hkaBone& bone = View<hkaBone>(skeletonHolder->m_pSkeleton->m_kBones)[i];
            bone.m_name.Assign(hkString_strDup_00cb1410(records.m_pBase[i]->name));
            View<hkaBone>(skeletonHolder->m_pSkeleton->m_kBones)[i].m_bLockTranslation = true;
            View<hkQsTransform>(skeletonHolder->m_pSkeleton->m_kReferencePose)[i] = records.m_pBase[i]->transform;
            View<short>(skeletonHolder->m_pSkeleton->m_kParentIndices)[i] = records.m_pBase[i]->parent;
        }
    }

    for (unsigned int i = 0; i < records.m_uiSize; ++i) {
        BoneRecord* r = records.m_pBase[i];
        if (r)
            _g_memoryManager.Deallocate(reinterpret_cast<char*>(r) - reinterpret_cast<unsigned char*>(r)[-1]);
    }
    records.RemoveAll();

    pose = new SkeletonPoseData(skeletonHolder->m_pSkeleton);
    pose->hkaPose_setToReferencePose();
    transforms.setSizePod(View<hkaBone>(skeletonHolder->m_pSkeleton->m_kBones).GetLogicalSize());
}

} // namespace SkeletonBuild
