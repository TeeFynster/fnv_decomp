#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
#define FNV_VEC4_SIMD
#include "../../../../../../../include/Vec4.h"
#include "../../../../../../../include/hkpContactMgr.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkSphere.h"
#include "../../../../../../../include/hkStepInfo.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkThreadLocalData.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkVector4_S.h"
#include "../../../../../../../include/hkpCapsuleShape.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSphereRepShape.h"
#include "../../../../../../../include/hkpTriangleShape.h"

// src/havok/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

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

void __cdecl hkpMultiSphereTriangleAgent_staticGetPenetrations_UpdateState_00d389f0(hkpCollisionDispatcher* dispatcher);
struct ReceiverBase { virtual void Release(unsigned int value); int unk04; };
struct NoteDispatcher {
    virtual void Unknown00(unsigned int, void*);
    virtual void Unknown04(unsigned int, void*);
    virtual void Unknown08(unsigned int, void*);
    virtual void Unknown0C(unsigned int, void*);
    virtual void Unknown10(unsigned int, void*);
    virtual void Dispatch(unsigned int id, void* value);
};
struct FUN_00d39930_class : ReceiverBase {
    NoteDispatcher* dispatcher;
    unsigned short receiverIds[3];
    void __thiscall DispatchToReceivers(void* value);
};
extern const int DAT_010ce7fc;
struct CallbackState {
    const int* m_pIntegerValue;
    float m_fFirstLightParameter;
    int m_iValue;
};
void __cdecl staticGetClosestPoints(void* apFirst, void* apSecond, void* apThird,
                          CallbackState* apState);
void __cdecl Object_UpdateFields_00d3b220(void* apOne, void* apTwo, void* apThree, int aiValue);

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl ComputeInverseLengths(void* value, void* self);
extern char DAT_010ceefc[];
extern char DAT_010cef38[];
struct FUN_00d39980_cls {
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
extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern const __m128 DAT_010c4c00;

struct Elem_d3b260 {
    hkVector4 m_pos;
    hkVector4 m_dir;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct Buffer_d3b260 {
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
struct Agent_d3b260 {
    void hkpCapsuleTriangleAgent_processCollision(int b, int a, int c, Buffer_d3b260* buf);
    void hkpSymmetricAgentLinearCast_hkpCapsuleTriangleAgent_processCollision(int a, int b, int c, Buffer_d3b260* buf);
};
struct __declspec(align(16)) FourWord {
    unsigned int x, y, z, w;
};
struct __declspec(align(16)) FourFloat {
    union { __m128 simd; FourWord words; };
};
struct __declspec(align(16)) MotionPacket {
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
struct __declspec(align(16)) MotionCallData {
    const void* descriptor;
    float scale;
    FourWord direction;
    unsigned int mode;
};
extern "C" float DAT_0104da48;
extern "C" const __m128 DAT_010c44d0;
extern "C" unsigned char UNK_010ce80c;
extern "C" void __cdecl Object_ProcessEntries_00daf8e0(unsigned int second, unsigned int first,
                            MotionPacket* packet, MotionCallData* primary,
                            MotionCallData* secondary);
void __cdecl Object_UpdateFields_00d3ac80(unsigned int first, unsigned int second, const MotionPacket* apPacket, unsigned int mode, unsigned int optionalMode);
extern char DAT_010ce81c;
struct FUN_00d3b160_tmp { const void* vt; unsigned char flag; unsigned int a4; };
struct CallbackHost_d3b160 {
    void hkpCapsuleTriangleAgent_getPenetrations(void*, void*, void*, void*);
    void hkpSymmetricAgentLinearCast_hkpCapsuleTriangleAgent_getPenetrations(void*, void*, void*, unsigned int);
};
struct Mat4 {
    Vec4::Aligned row0, row1, row2, row3;
};
void __cdecl hkCollideCapsuleUtilCapsVsTri(void* a, float b, void* c, float d, void* e, float f, int g, int h, int i);
static __forceinline void transform(Vec4* out, const char* shape, int count, const Mat4* m)
{
    Vec4::Aligned p0 = m->row0;
    Vec4::Aligned p1 = m->row1;
    Vec4::Aligned p2 = m->row2;
    Vec4::Aligned p3 = m->row3;
    __m128 r0 = *(__m128*)&p0;
    __m128 r1 = *(__m128*)&p1;
    __m128 r2 = *(__m128*)&p2;
    __m128 r3 = *(__m128*)&p3;

    __m128* v = (__m128*)(shape + 0x20);
    for (int i = count - 1; i >= 0; --i) {
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
struct __declspec(align(16)) ScalarVector {
    int x, y, z, w;
    __m128 quad() const { return *(const __m128*)this; }
};
struct Xf {
    ScalarVector r0, r1, r2, t;
};
struct Vt {
    void* f00; void* f04; void* f08; void* f0c;
    void* f10; void* f14; void* f18; void* f1c;
    void* f20; void* f24; void* f28; void* f2c;
    void* f30; void* f34; void* f38; void* f3c;
    int (__thiscall *fn)(void*, void*, void*, void*, void*, void*, void*, void*);
};

struct Obj {
    hkpConvexShape* base;
    int u;
    Xf* xf;
};
struct Par {
    float a;
    int flag;
    float c;
};
struct Info {
    unsigned char count;
    unsigned char type;
    unsigned short feature;
    int index;
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
    for (int i = hi; i >= 0; --i) {
        __m128 v = src[i];
        __m128 x = _mm_shuffle_ps(v, v, 0);
        __m128 y = _mm_shuffle_ps(v, v, 0x55);
        __m128 z = _mm_shuffle_ps(v, v, 0xaa);
        dst[i] = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, c1), _mm_mul_ps(x, c0)), _mm_add_ps(_mm_mul_ps(z, c2), ct));
    }
}
struct CollisionWorkspace { __m128 la[2]; __m128 lb[3]; };
int __cdecl hkpCapsuleTriangleAgent_getClosestPoint(Obj* a, Obj* b, Par* volatile p, void* q, hkContactPoint* out);
#include <windows.h>
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkpIterativeLinearCastAgent.h"
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
extern "C" void __cdecl hkCollideCapsuleUtilCapsVsTri(void* out1, float fx, void* out2, float fy, void* p, float afDepth, int zero, HitRec* hit, int zero2);

struct CollisionInput { int unk00; int unk04; float tolerance; };
struct __declspec(align(16)) RowPair { Vec4f first, second; };
struct CapsuleTriangleAgent {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void hkpCapsuleTriangleAgent_getPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionInput* input, VirtObj* collector);
};

typedef float hkReal;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __w64 hk_size_t;
class hkClass;
typedef int hkBool32;



class hkStatisticsCollector;

extern "C"{

};
typedef __m128 hkQuadReal;
class Vector4Comparison;
typedef const Vector4Comparison&hkVector4ComparisonParameter;

inline void hkVector4::operator=(const hkVector4& v) { m_vComponents = v.m_vComponents; }
inline hkVector4::hkVector4(const hkVector4& v) { m_vComponents = v.m_vComponents; }
__forceinline void hkVector4_S::operator=(const hkVector4_S& v) { m_vComponents = v.m_vComponents; }
inline hkVector4_S::operator __m128() const { return m_vComponents; }
__forceinline const hkReal& hkVector4_S::operator()(int i) const { return reinterpret_cast<const hkReal*>(&m_vComponents)[i]; }
__forceinline void hkVector4_S::_setTransformedPos(const hkTransform& t, const hkVector4_S& b)
{
    hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    hkQuadReal r0 = _mm_mul_ps(t.m_row0, b0);
    hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    hkQuadReal r1 = _mm_mul_ps(t.m_row1, b1);
    hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    hkQuadReal r2 = _mm_mul_ps(t.m_row2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.m_row3));
}
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4_S r0 = reinterpret_cast<const hkVector4_S&>(t.m_row0);
    const hkVector4_S r1 = reinterpret_cast<const hkVector4_S&>(t.m_row1);
    const hkVector4_S r2 = reinterpret_cast<const hkVector4_S&>(t.m_row2);
    const hkVector4_S r3 = reinterpret_cast<const hkVector4_S&>(t.m_row3);
    m_row0 = r0.m_vComponents;
    m_row1 = r1.m_vComponents;
    m_row2 = r2.m_vComponents;
    m_row3 = r3.m_vComponents;
}
inline hkMonitorStream& hkMonitorStream::getInstance()
{
    extern hkThreadLocalData<hkMonitorStream*> g_pMonitorStream;
    return *g_pMonitorStream.getData();
}
inline char* __cdecl hkMonitorStream::getStart() { return m_start.val(); }
inline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
inline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
inline hkBool __cdecl hkMonitorStream::memoryAvailable() { return getEnd() < getCapacityMinus16(); }
inline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end = ptr; }
__forceinline void hkMonitorStream::TimerCommand::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_time0=ticks;
}
typedef hkUint16 hkContactPointId;
inline hkVector4&hkContactPoint::getPosition()
{
return m_vContactPosition;
}
inline hkVector4&hkContactPoint::getSeparatingNormal()
{
return m_vSeparatingNormal;
}
inline hkReal hkContactPoint::getDistance()const
{
return m_vSeparatingNormal.w;
}
class Vector4WithInt24W:public hkVector4_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpRayHitCollector;
class hkpShapeContainer;
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;

__forceinline const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
__forceinline const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
struct GskAgentInput;
struct WorldOperationEntry;
class hkpConstraintOwner;
class hkpCollisionAgent;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
hkPadSpu<hkpCollisionDispatcher*>m_pCollisionDispatcher;
hkPadSpu<hkBool32>m_collisionQuality;
hkPadSpu<hkReal>m_fScalar;};
class hkpContactMgrFactory;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct ShapeSweepParameters;

struct ContactPointPair
{
ContactPointPair(const hkpCdBody&a,const hkpCdBody&b):m_pBodyA(a),m_pBodyB(b){}
hkContactPoint m_kPoint;
const hkpCdBody&m_pBodyA;
const hkpCdBody&m_pBodyB;};
struct MaterialIndexedTriangle
{
hkUint8 m_uiMaterialIndex;
hkpVertexId m_auiVertexIds[3];
};
class TriangleDistanceUtility
{
public:
static void __cdecl calcBarycentricCoordinates(hkVector4Parameter pos,hkVector4Parameter t0,hkVector4Parameter t1,hkVector4Parameter t2,hkPadSpu<hkReal>result[3]);
struct PointTriangleCache
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(TriangleDistanceUtility::PointTriangleCache));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkReal m_afCacheComponents[3];
hkReal m_fFirstCacheValue;
hkReal m_fSecondCacheValue;
};
static void __cdecl setupPointTriangleDistanceCache(const hkVector4_S*triangle,PointTriangleCache&cache);protected:
TriangleDistanceUtility();};
class hkpCapsuleTriangleAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl InitAgentFunc(hkpCollisionDispatcher::CollisionAgentFunctionTable&f);
static void __cdecl initAgentFuncInverse(hkpCollisionDispatcher::CollisionAgentFunctionTable&f);
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
static void __cdecl registerAgent2(hkpCollisionDispatcher*dispatcher);
virtual inline void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&pointDetails);
static void __cdecl staticGetClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void cleanup(hkpConstraintOwner&constraintOwner);
protected:
friend class hkpCapsuleConvexWelderAgent;
__forceinline hkpCapsuleTriangleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createCapsuleTriangleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createTriangleCapsuleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
private:
static void __cdecl getClosestPointsPublic(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::PointTriangleCache&cache,int searchManifold,hkContactPoint*points);
static __forceinline void __cdecl getClosestPointsInl(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::PointTriangleCache&cache,int searchManifold,hkContactPoint*points,MaterialIndexedTriangle*featureOutput=0);
public:
enum ClosestPointResult
{
ST_CP_MISS,
ST_CP_HIT,
};
private:
static __forceinline ClosestPointResult getClosestPointInternal(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::PointTriangleCache&m_pAccessManager,hkContactPoint&cpoint);
public:
static ClosestPointResult __cdecl ComputeClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::PointTriangleCache&m_pAccessManager,hkContactPoint&cpoint);
protected:
hkContactPointId m_usContactPointId[3];
TriangleDistanceUtility::PointTriangleCache m_kClosestPointCache;
};

__forceinline hkpConvexShape::WeldResult hkpConvexShape::weldContactPoint(hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
    hkVector4& contactPointWs, const hkTransform* thisObjTransform,
    const hkpConvexShape* collidingShape, const hkTransform* collidingTransform, hkVector4& separatingNormalInOut) const
{
    return (WeldResult)this->WeldContactPoint(featurePoints, numFeaturePoints,
        contactPointWs, thisObjTransform, collidingShape, collidingTransform, separatingNormalInOut);
}
inline const hkVector4* hkpCapsuleShape::GetIndexedVertices() const { return &m_kVertexA; }
__forceinline const hkVector4_S* hkpTriangleShape::GetIndexedVertices() const { return reinterpret_cast<const hkVector4_S*>(&m_kVertexA); }
inline hkContactPoint& hkContactPoint::operator=(const hkContactPoint& point)
{
    m_vContactPosition = point.m_vContactPosition;
    m_vSeparatingNormal = point.m_vSeparatingNormal;
    return *this;
}
extern "C"
{
void CollideCapsuleWithTriangle(const hkVector4_S*capsAPoints,hkReal capsARadius,const hkVector4_S*triVertices,hkReal triBRadius,
const TriangleDistanceUtility::PointTriangleCache&cache,hkReal collisionTolerance,int searchManifold,hkContactPoint*points,MaterialIndexedTriangle*featuresOut=0);}
namespace hkVector4Util_S
{
__forceinline void __cdecl TransformPointArray(const hkTransform&t,const hkVector4_S*vectorsIn,int numVectors,hkVector4_S*vectorsOut);}
inline void __cdecl hkVector4Util_S::TransformPointArray(const hkTransform&t,const hkVector4_S*vectorsIn,int numVectors,hkVector4_S*vectorsOut)
{
hkTransform unaliased=t;
int i=numVectors-1;
do
{
vectorsOut[i]._setTransformedPos(unaliased,vectorsIn[i]);
}while(--i>=0);}
__forceinline void __cdecl hkpCapsuleTriangleAgent::getClosestPointsInl(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::PointTriangleCache&cache,int searchManifold,hkContactPoint*points,MaterialIndexedTriangle*featureOutput)
{
const hkpCapsuleShape*capsuleA=static_cast<const hkpCapsuleShape*>(bodyA.getShape());
const hkpTriangleShape*triB=static_cast<const hkpTriangleShape*>(bodyB.getShape());
hkVector4_S endPoints[2];hkVector4Util_S::TransformPointArray(bodyA.getTransform(),reinterpret_cast<const hkVector4_S*>(capsuleA->GetIndexedVertices()),2,endPoints);
hkVector4_S triVertices[3];hkVector4Util_S::TransformPointArray(bodyB.getTransform(),triB->GetIndexedVertices(),3,triVertices);
CollideCapsuleWithTriangle(endPoints,capsuleA->getRadius(),triVertices,triB->hkpConvexShape::getRadius(),cache,input.getTolerance(),searchManifold,points,featureOutput);}
__forceinline hkpCapsuleTriangleAgent::ClosestPointResult hkpCapsuleTriangleAgent::getClosestPointInternal(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::PointTriangleCache&cache,hkContactPoint&cpoint)
{
const hkpCapsuleShape*capsuleA=static_cast<const hkpCapsuleShape*>(bodyA.getShape());
const hkpTriangleShape*triB=static_cast<const hkpTriangleShape*>(bodyB.getShape());
hkContactPoint points[3];
MaterialIndexedTriangle featureOutput[3];
getClosestPointsInl(bodyA,bodyB,input,cache,0,points,featureOutput);
const hkReal dist0=points[0].getDistance();
const hkReal dist1=points[1].getDistance();
int Id=-1;
if(dist0<dist1)
{
if(input.getTolerance()>dist0)
{
Id=0;
}
}
else
{
if(input.getTolerance()>dist1)
{
Id=1;
}
}
if(Id !=-1)
{
hkUint8 numFeaturePoints=featureOutput[Id].m_uiMaterialIndex;
if(input.m_collisionQuality.val()&&numFeaturePoints>0)
{
hkVector4_S weldedNormal=reinterpret_cast<const hkVector4_S&>(points[Id].getSeparatingNormal());
hkpConvexShape::WeldResult result=triB->weldContactPoint(&featureOutput[Id].m_auiVertexIds[0],numFeaturePoints,points[Id].getPosition(),&bodyB.getTransform(),capsuleA,&bodyA.getTransform(),reinterpret_cast<hkVector4&>(weldedNormal));
if(result==hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT)
{
return ST_CP_MISS;
}
else if(result==hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED)
{
points[Id].setNormal(reinterpret_cast<const hkVector4&>(weldedNormal));
}
}
cpoint=points[Id];
return ST_CP_HIT;
}
return ST_CP_MISS;}
// @fnv 0x00d3a280
// src: XBOX_PDB 0x00d3a280
void __cdecl hkpCapsuleTriangleAgent::staticGetClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "CapsTriangle";h->setTime();mStream.setEnd((char*)(h+1));}};
TriangleDistanceUtility::PointTriangleCache cache;
{
const hkpTriangleShape*triB=static_cast<const hkpTriangleShape*>(bodyB.getShape());
TriangleDistanceUtility::setupPointTriangleDistanceCache(triB->GetIndexedVertices(),cache);
}
ContactPointPair event(bodyA,bodyB);
if(getClosestPointInternal(bodyA,bodyB,input,cache,event.m_kPoint))
{
collector.AddCdPoint(event);
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}

#include "../../../../../../../include/hkResult.h"
typedef hkReal hkTime;
struct FourByteState;

hkContactPointId hkpContactMgr::addContactPoint(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&output,const ConvexFeaturePairCache*contactCache,hkContactPoint&cp)
{
return CreateContactPoint(a,b,input,output,contactCache,cp);
}
void hkpContactMgr::removeContactPoint(hkContactPointId cpId,hkpConstraintOwner&constraintOwner)
{
removeContactPointImpl(cpId,constraintOwner);
}
struct ContactPointWithId
{
hkContactPoint m_kPoint;
hkPadSpu<hkUint32>m_usContactPointId;};


struct hkpAgent1nSector;
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;};enum{HK_MAX_CONTACT_POINT=256};
struct CollisionContactResults
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
hkPadSpu<ContactPointWithId*>m_pAlignedPairData;
hkPadSpu<hkpConstraintOwner*>m_pConstraintOwner;};
struct WorldOperationEntry:public CollisionContactResults
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}inline ContactPointWithId*reserveContactPoints(int numberOfPoints=1)
{
return m_pAlignedPairData;
}
inline void commitContactPoints(int numberOfPoints=1)
{
m_pAlignedPairData=m_pAlignedPairData+numberOfPoints;
;
}
public:
struct ContactPointAgentEntry
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(WorldOperationEntry::ContactPointAgentEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
ContactPointWithId*m_vContactPoint;
FourByteState*m_pAgentEntry;
void*m_pUserData;
};
struct ContactPointBuffer
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(WorldOperationEntry::ContactPointBuffer));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
void reset()
{
m_pFirstFreeContactPoint=&m_akContactRecords[0];
m_ppFirstFreeContactPointer=&m_apContactPointPointers[0];
}
ContactPointAgentEntry*m_pFirstFreeContactPoint;
ContactPointWithId**m_ppFirstFreeContactPointer;
ContactPointWithId*m_apContactPointPointers[HK_MAX_CONTACT_POINT];
ContactPointAgentEntry m_akContactRecords[HK_MAX_CONTACT_POINT];
};
public:
hkPadSpu<ContactPointBuffer*>m_akContactRecords;};
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
static __forceinline void updateXYZ(hkVector4& dst,const hkVector4& xyz) {
    reinterpret_cast<hkQuadReal&>(dst)=_mm_shuffle_ps(xyz,_mm_unpackhi_ps(xyz,dst),0xc4);
}
inline void hkContactPoint::setNormal(const hkVector4& normal) { updateXYZ(m_vSeparatingNormal,normal); }
static __forceinline void capsuleTriClosest(const hkpCdBody& a,const hkpCdBody& b,const CollisionAgentContext& input,TriangleDistanceUtility::PointTriangleCache& cache,int manifold,hkContactPoint* points,MaterialIndexedTriangle* features)
{
    const hkpCapsuleShape* capsule=static_cast<const hkpCapsuleShape*>(a.getShape());
    const hkpTriangleShape* triangle=static_cast<const hkpTriangleShape*>(b.getShape());
    hkVector4_S ends[2];
    hkVector4Util_S::TransformPointArray(a.getTransform(),reinterpret_cast<const hkVector4_S*>(capsule->GetIndexedVertices()),2,ends);
    hkVector4_S vertices[3];
    hkVector4Util_S::TransformPointArray(b.getTransform(),triangle->GetIndexedVertices(),3,vertices);
    CollideCapsuleWithTriangle(ends,capsule->getRadius(),vertices,triangle->hkpConvexShape::getRadius(),cache,input.getTolerance(),manifold,points,features);
}
struct CapsuleTriProcess : hkpCapsuleTriangleAgent {
    void hkpCapsuleTriangleAgent_processCollision(const hkpCdBody&,const hkpCdBody&,const GskAgentInput&,WorldOperationEntry&);
};
// @fnv 0x00d3ad70
// src: HAVOK_SRC 0x00d3ad70
void CapsuleTriProcess::hkpCapsuleTriangleAgent_processCollision(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result)
{
;
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "CapsuleTri";h->setTime();mStream.setEnd((char*)(h+1));}};
const hkpCapsuleShape*capsuleA=static_cast<const hkpCapsuleShape*>(bodyA.getShape());
const hkpTriangleShape*triB=static_cast<const hkpTriangleShape*>(bodyB.getShape());
hkContactPoint points[3];
MaterialIndexedTriangle featureOutput[3];
capsuleTriClosest(bodyA,bodyB,input,m_kClosestPointCache,1,points,featureOutput);
for(int p=0;p<3;p++)
{
if(points[p].getDistance()<input.getTolerance())
{
hkUint8 numFeaturePoints=featureOutput[p].m_uiMaterialIndex;
if(numFeaturePoints>0)
{
hkVector4_S weldedNormal=reinterpret_cast<const hkVector4_S&>(points[p].getSeparatingNormal());
hkpConvexShape::WeldResult weldResult=triB->weldContactPoint(&featureOutput[p].m_auiVertexIds[0],numFeaturePoints,points[p].getPosition(),&bodyB.getTransform(),capsuleA,&bodyA.getTransform(),reinterpret_cast<hkVector4&>(weldedNormal));
if(weldResult==hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT)
{
if(m_usContactPointId[p]!=(0xffff))
{
m_pContactManager->removeContactPoint(m_usContactPointId[p],*result.m_pConstraintOwner.val());
m_usContactPointId[p]=(0xffff);
}
continue;
}
else if(weldResult==hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED)
{
points[p].setNormal(reinterpret_cast<const hkVector4&>(weldedNormal));
}
}
if(m_usContactPointId[p]==(0xffff))
{
m_usContactPointId[p]=m_pContactManager->addContactPoint(bodyA,bodyB,input,result,0,points[p]);
}
if(m_usContactPointId[p]!=(0xffff))
{
ContactPointWithId*point=result.reserveContactPoints(1);
result.commitContactPoints(1);
point->m_kPoint.getPosition()=points[p].getPosition();
point->m_kPoint.getSeparatingNormal()=points[p].getSeparatingNormal();
point->m_usContactPointId=m_usContactPointId[p];
}
}
else
{
if(m_usContactPointId[p]!=(0xffff))
{
m_pContactManager->removeContactPoint(m_usContactPointId[p],*result.m_pConstraintOwner.val());
m_usContactPointId[p]=(0xffff);
}
}
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}
