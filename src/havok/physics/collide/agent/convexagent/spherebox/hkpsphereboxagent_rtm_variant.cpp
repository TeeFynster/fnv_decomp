#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
// src/havok/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Use compiler intrinsic declarations without the SDK inline wrappers.
#define _INCLUDED_MM2
// Exe 0x00d3c5b0 FUN_00d3c5b0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;

#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkThreadLocalData.h"
#include <windows.h>
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkpBoxShape.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpIterativeLinearCastAgent.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSphereRepShape.h"
#include "../../../../../../../include/hkpSphereShape.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkpSymmetricAgentFlipCollector.h"

extern void __cdecl hkpSphereBoxAgent_staticGetPenetrations(int a, int b, int c, int d);
void __stdcall ForwardToD3C440(int a, int b, int c, int d);
struct Conversion {
    void (*convert)();
    void (*create)();
    void (*copy)();
    void (*destroy)();
    bool enabled;
    bool supported;
};
struct Registry { void AppendRecordAndRegisterAgents(Conversion*, int, int); };
void hkpSphereBoxAgent_createBoxSphereAgent();
void Object_UpdateFields_00d3cfc0();
void FlipAndDispatchCollector();
void Object_UpdateFields_00d3ac80();
void CreateD3C380Obj();
void hkpSphereBoxAgent_staticGetPenetrations();
void hkpSphereBoxAgent_staticGetClosestPoints();
void Object_ProcessEntries_00daf8e0();
void __cdecl hkpSphereBoxAgent_registerAgent(Registry* registry);
extern float DAT_0104da48;
extern void __cdecl hkpSphereBoxAgent_staticGetClosestPoints(void*, void*, int, void*);
void __cdecl FlipAndDispatchCollector(void* arg1, void* arg2, int arg3, int arg4);
struct S_00d3c3c0_Holder {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void v14(unsigned int idx, int arg);
};
struct S_00d3c3c0_Obj {
    virtual void v00(int flag);
    int unk04;
    S_00d3c3c0_Holder* unk08;
    unsigned short unk0c;
    void hkpSphereBoxAgent_cleanup(int arg);
};

struct ObjAllocator {
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};
struct SmallRecord {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    unsigned short m_w0C;
};
extern char DAT_010cf018[];
hkMemoryRouter* hkMemoryRouter_getInstance();
void __cdecl hkpSphereBoxAgent_createBoxSphereAgent(int aiUnused1, int aiUnused2, int aiUnused3, int d);
class D3CF80CollectorBase {
public:
    D3CF80CollectorBase() : m_bHit(false) {}
    virtual void AddCdPoint(const void* pkEvent) = 0;

    bool m_bHit;
};
class D3CF80Collector : public D3CF80CollectorBase {
public:
    D3CF80Collector(int iFilter) : m_iFilter(iFilter) {}
    virtual void AddCdPoint(const void* pkEvent);

    int m_iFilter;
};
class D3CF80Agent {
public:
    void ForwardToD3C440(void* pkA, void* pkB, void* pkInput, D3CF80Collector* pkCollector);
    void CollectFilteredEvents(void* pkA, void* pkB, void* pkInput, int iFilter);
};
extern void __cdecl hkpSphereBoxAgent_staticGetPenetrations(int a, int b, int c, int d);
extern char DAT_010ce81c[];
struct FlipCollectorLocal {
    void* unk00;
    unsigned char unk04;
    int unk08;
};
void __cdecl Object_UpdateFields_00d3cfc0(int aiArg1, int aiArg2, int aiArg3, int a4);
struct CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct CpuObject {
    void hkpSphereBoxAgent_getClosestPoints(void*, void*, unsigned int, CpuCallData*);
    void hkpSymmetricAgentLinearCast_hkpSphereBoxAgent_getClosestPoints(void*, void*, unsigned int, unsigned int);
};
extern "C" {
LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
LocalM128 _mm_mul_ps(LocalM128, LocalM128);
LocalM128 _mm_add_ps(LocalM128, LocalM128);
LocalM128 _mm_xor_ps(LocalM128, LocalM128);
}
extern LocalM128 DAT_010c4c00;
struct SimplexVertex
{
    LocalM128 m_kPointA;
    LocalM128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};
struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};
struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    LocalM128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};
struct AgentBase
{
    void hkpSphereBoxAgent_processCollision(int a, int b, int c, Simplex* s);
};
struct Agent : AgentBase
{
    void hkpSymmetricAgentLinearCast_hkpSphereBoxAgent_processCollision(int a, int b, int c, Simplex* s);
};

extern "C" {
unsigned __int64 __rdtsc(void);
void _ReadWriteBarrier(void);
LocalM128 _mm_add_ss(LocalM128, LocalM128);
LocalM128 _mm_sub_ss(LocalM128, LocalM128);
LocalM128 _mm_mul_ss(LocalM128, LocalM128);
LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
LocalM128 _mm_and_ps(LocalM128, LocalM128);
LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
LocalM128 _mm_min_ps(LocalM128, LocalM128);
LocalM128 _mm_sub_ps(LocalM128, LocalM128);
LocalM128 _mm_rsqrt_ss(LocalM128);
LocalM128 _mm_set_ss(float);
LocalM128 _mm_load_ss(float const*);
void _mm_store_ss(float*, LocalM128);
LocalM128 _mm_setzero_ps(void);
int _mm_movemask_ps(LocalM128);
LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
}

extern DWORD DAT_0126835c;
extern const char str_010cf050[];
extern const char str_010c41f8[];
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

typedef unsigned __w64 hk_size_t;
typedef int hkBool32;

extern "C"{
__declspec(dllimport)void*_stdcall TlsGetValue(unsigned long dwTlsIndex);}

extern "C"{
extern LocalM128 _mm_add_ss(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_add_ps(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_sub_ss(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_sub_ps(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_mul_ss(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_mul_ps(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_rsqrt_ss(LocalM128 _A);
extern LocalM128 _mm_min_ps(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_and_ps(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_andnot_ps(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_xor_ps(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_cmpeq_ss(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_cmplt_ps(LocalM128 _A,LocalM128 _B);
extern LocalM128 _mm_shuffle_ps(LocalM128 _A,LocalM128 _B,unsigned int _Imm8);
extern LocalM128 _mm_unpackhi_ps(LocalM128 _A,LocalM128 _B);
extern int _mm_movemask_ps(LocalM128 _A);
extern LocalM128 _mm_set_ss(float _A);
extern LocalM128 _mm_setzero_ps(void);
extern LocalM128 _mm_load_ss(float const*_A);
extern void _mm_store_ss(float*_V,LocalM128 _A);};

__forceinline hkSimdReal::hkSimdReal(const LocalM128& x) : m_vValue(x) {}
__forceinline hkSimdReal::hkSimdReal(float x) { m_vValue = _mm_load_ss(&x); }
__forceinline hkSimdReal::operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
__forceinline float hkSimdReal::storeInto(float& scalar) const { _mm_store_ss(&scalar, m_vValue); return scalar; }
__forceinline LocalM128 hkSimdReal::broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
__forceinline const LocalM128& hkSimdReal::getQuad() const { return m_vValue; }
__forceinline void hkMonitorStream::TimerCommand::setTime()
{
    _ReadWriteBarrier();
    unsigned int ticks = (unsigned int)__rdtsc();
    m_time0 = *(volatile unsigned int*)&ticks;
}
__forceinline hkMonitorStream& hkMonitorStream::getInstance()
{
    extern hkThreadLocalData<hkMonitorStream*> g_pMonitorStream;
    return *g_pMonitorStream.getData();
}
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline hkBool __cdecl hkMonitorStream::memoryAvailable() { return m_end.val() < m_capacityMinus16.val(); }
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end = ptr; }

typedef LocalM128 hkQuadReal;

typedef const hkVector4&hkVector4Parameter;

typedef const hkSimdReal&hkSimdRealParameter;
class Vector4Comparison
{
public:
enum Mask
{
MASK_NONE=0,
MASK_X=1,
MASK_Y=2,
MASK_XY=3,
MASK_Z=4,
MASK_XZ=5,
MASK_YZ=6,
MASK_XYZ=7,
MASK_W=8,
MASK_XW=9,
MASK_YW=10,
MASK_XYW=11,
MASK_ZW=12,
MASK_XZW=13,
MASK_YZW=14,
MASK_XYZW=15
};__forceinline hkBool32 anyIsSet(Mask m)const{return _mm_movemask_ps(m_uiMask)&m;}
private:
hkQuadReal m_uiMask;
friend class hkVector4;};
__forceinline hkVector4::hkVector4(const hkVector4& vector) : m_vComponents(vector.m_vComponents) {}
__forceinline void hkVector4::negateSelf() { extern const unsigned int DAT_010c44d0[4]; m_vComponents = _mm_xor_ps(m_vComponents, *(const LocalM128*)DAT_010c44d0); }

__forceinline hkQuadReal&hkVector4::getQuad()
{
return m_vComponents;
}
__forceinline const hkQuadReal&hkVector4::getQuad()const
{
return m_vComponents;
}
__forceinline void hkVector4::setZero4()
{
m_vComponents=_mm_setzero_ps();
}
__forceinline void hkVector4::setAddMul4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter r)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(r.broadcast(),b.m_vComponents));
}
__forceinline Vector4Comparison hkVector4::compareLessThanZero4()const
{
hkVector4 zero;zero.setZero4();
Vector4Comparison m;m.m_uiMask=_mm_cmplt_ps(m_vComponents,zero);
return m;
}
__forceinline void hkVector4::setNeg4(const hkVector4&v)
{
static __declspec(align(16))const hkUint32 negateMask[4]={0x80000000,0x80000000,0x80000000,0x80000000};
m_vComponents=_mm_xor_ps(v.m_vComponents,*(const hkQuadReal*)&negateMask);
}
__forceinline void hkVector4::setAbs4(const hkVector4&v)
{
static __declspec(align(16))const hkUint32 absMask[4]={0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff};
m_vComponents=_mm_and_ps(v.m_vComponents,*(const hkQuadReal*)&absMask);
}
__forceinline void hkVector4::setMin4(const hkVector4&a,const hkVector4&b)
{
m_vComponents=_mm_min_ps(a.getQuad(),b.getQuad());
}
__forceinline void hkVector4::_setMul3(const hkMatrix3&a,const hkVector4&b)
{
const hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
const hkQuadReal r0=_mm_mul_ps(a.getColumn(0).m_vComponents,b0);
const hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
const hkQuadReal r1=_mm_mul_ps(a.getColumn(1).m_vComponents,b1);
const hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
const hkQuadReal r2=_mm_mul_ps(a.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),r2);}
__forceinline void hkVector4::_setRotatedDir(const hkRotation&r,const hkVector4&v)
{
_setMul3(reinterpret_cast<const hkMatrix3&>(r),v);
}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
__forceinline hkSimdReal lengthInverse3(const hkVector4& vector)
{
const hkQuadReal half=_mm_set_ss(0.5f);
const hkQuadReal three=_mm_set_ss(3.0f);
const hkQuadReal zero=_mm_set_ss(0.0f);
const hkQuadReal len2=vector.dot3(vector).getQuad();
const hkQuadReal len2EqualsZero=_mm_cmpeq_ss(len2,zero);
const hkQuadReal approx=_mm_rsqrt_ss(len2);
const hkQuadReal refined=_mm_mul_ss(
_mm_mul_ss(half,approx),
_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(len2,approx),approx)));
return _mm_andnot_ps(len2EqualsZero,refined);}
__forceinline hkSimdReal hkVector4::normalizeWithLength3()
{
hkQuadReal len2=this->dot3(*this).getQuad();
hkQuadReal lenInv=lengthInverse3(*this).broadcast();
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
return _mm_mul_ss(len2,lenInv);
}
__forceinline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
__forceinline const hkReal&hkVector4::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
__forceinline void hkVector4::setXYZ(const hkVector4&xyz)
{
m_vComponents=_mm_shuffle_ps(xyz.m_vComponents,_mm_unpackhi_ps(xyz.m_vComponents,m_vComponents),(((3)<<6)|((0)<<4)|((1)<<2)|((0))));
}
inline const hkVector4&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
const hkVector4&hkTransform::getColumn(int x)const
{
return reinterpret_cast<const hkVector4*>(&m_row0)[x];
}
const hkVector4&hkTransform::getTranslation()const
{
return reinterpret_cast<const hkVector4&>(m_row3);
}
const hkRotation&hkTransform::getRotation()const
{
return reinterpret_cast<const hkRotation&>(m_row0);
}

// The original's timer helper that also hands back the tick count, a unit-local view.
struct TimerCommand_spherebox : hkMonitorStream::TimerCommand
{
    void setTime(hkUint32& ticks);
};
void TimerCommand_spherebox::setTime(hkUint32& ticks)
{
_ReadWriteBarrier();
ticks = (hkUint32)__rdtsc();
m_time0 = *(volatile hkUint32*)&ticks;
}
typedef hkUint16 hkContactPointId;
inline const hkVector4&hkContactPoint::getNormal()const
{
return m_vSeparatingNormal;
}
inline hkVector4&hkContactPoint::getPosition()
{
return m_vContactPosition;
}
inline hkVector4&hkContactPoint::getSeparatingNormal()
{
return m_vSeparatingNormal;
}
inline void hkContactPoint::setDistance(hkReal d)
{
m_vSeparatingNormal(3)=d;
}
inline void hkContactPoint::setNormal(const hkVector4&normal)
{
m_vSeparatingNormal.setXYZ(normal);
}
class Vector4WithInt24W:public hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};

class hkpCollisionDispatcher;
typedef hkUint32 hkpShapeKey;

const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
struct GskAgentInput;
class hkpContactMgr;
class hkpConstraintOwner;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
hkPadSpu<hkpCollisionDispatcher*>m_pCollisionDispatcher;
hkPadSpu<hkBool32>m_collisionQuality;
hkPadSpu<hkReal>m_fScalar;};
struct ContactPointPair
{
ContactPointPair(const hkpCdBody&a,const hkpCdBody&b):m_pBodyA(a),m_pBodyB(b){}
hkContactPoint m_kPoint;
const hkpCdBody&m_pBodyA;
const hkpCdBody&m_pBodyB;};
struct WorldOperationEntry;
class hkpCdBodyPairCollector;

class hkpSphereBoxAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector);

virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void cleanup(hkpConstraintOwner&constraintOwner);
protected:
static hkpCollisionAgent*__cdecl createSphereBoxAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createBoxSphereAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
protected:
hkpSphereBoxAgent(hkpContactMgr*mgr);
public:
static __forceinline hkBool ComputeClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkContactPoint&contactOut,hkReal& scalarScratch);
protected:
hkContactPointId m_usContactPointId;
};

namespace hkVector4Util_S
{
__forceinline void __cdecl mulSigns4(hkVector4&inout,const hkVector4&signsSource);}
inline void __cdecl hkVector4Util_S::mulSigns4(hkVector4&inout,const hkVector4&signs)
{
static __declspec(align(16))const hkUint32 signmask[4]=
{0x80000000,0x80000000,0x80000000,0x80000000};
inout.getQuad()=_mm_xor_ps(inout.getQuad(),
_mm_and_ps(signs.getQuad(),*(const hkQuadReal*)&signmask));}

__forceinline void S3c5_timer(const char* name)
{
    hkMonitorStream& mStream = hkMonitorStream::getInstance();
    if (mStream.memoryAvailable())
    {
        hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
        h->m_commandAndMonitor = name;
        h->setTime();
        mStream.setEnd((char*)(h + 1));
    }
}

#include "../../../../../../../include/hkpCdBody.h"


struct S3c5_CollisionInput {
    void* m_pCollisionDispatcher;
    int m_collisionQuality;
    float m_fScalar;
    __forceinline float getTolerance() const { return m_fScalar; }
};

struct S3c5_ProcessCdPoint {
    hkContactPoint m_kPoint;
    unsigned int m_usContactPointId;
};

struct S3c5_ConstraintOwner;

struct S3c5_ProcessCollisionOutput {
    S3c5_ProcessCdPoint* m_pAlignedPairData;
    S3c5_ConstraintOwner* m_pConstraintOwner;
    __forceinline S3c5_ProcessCdPoint* reserveContactPoints(int numPoints) { return m_pAlignedPairData; }
    __forceinline void commitContactPoints(int numPoints) { m_pAlignedPairData = m_pAlignedPairData + numPoints; }
    __forceinline void abortContactPoints(int numPoints) {}
};

class S3c5_ContactMgr {
public:
    __forceinline unsigned short addContactPoint(const hkpCdBody& a, const hkpCdBody& b, const S3c5_CollisionInput& input, S3c5_ProcessCollisionOutput& output, const void* contactCache, hkContactPoint& cp)
    {
        return CreateContactPoint(a, b, input, output, contactCache, cp);
    }
    __forceinline void removeContactPoint(unsigned short cpId, S3c5_ConstraintOwner& constraintOwner)
    {
        removeContactPointImpl(cpId, constraintOwner);
    }
    virtual ~S3c5_ContactMgr();
    virtual void v04();
    virtual void v08();
    virtual unsigned short CreateContactPoint(const hkpCdBody& a, const hkpCdBody& b, const S3c5_CollisionInput& input, S3c5_ProcessCollisionOutput& output, const void* contactCache, hkContactPoint& cp);
    virtual void v10();
    virtual void removeContactPointImpl(unsigned short cpId, S3c5_ConstraintOwner& constraintOwner);
};

class S3c5_SphereBoxAgent {
public:
    virtual ~S3c5_SphereBoxAgent();
    int m_usMemSizeAndFlags;
    S3c5_ContactMgr* m_pContactManager;
    unsigned short m_usContactPointId;

    void processContact(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const S3c5_CollisionInput& input, S3c5_ProcessCollisionOutput& result);
    static __forceinline bool ComputeClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const S3c5_CollisionInput& input, hkContactPoint& contactOut);
};

__forceinline bool S3c5_SphereBoxAgent::ComputeClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const S3c5_CollisionInput& input, hkContactPoint& contactOut)
{
    const hkVector4& posA = bodyA.getTransform().getTranslation();
    hkVector4 posLocal;
    posLocal.SetTransformedPosition(bodyB.getTransform(), posA);

    const hkpBoxShape* boxB = static_cast<const hkpBoxShape*>(bodyB.getShape());
    const hkpConvexShape* sphereA = static_cast<const hkpConvexShape*>(bodyA.getShape());

    hkVector4 absPos; absPos.setAbs4(posLocal);
    hkVector4 clippedAbsPos; clippedAbsPos.setMin4(absPos, boxB->getHalfExtents());
    hkVector4 delta; delta.setSub4(clippedAbsPos, absPos);

    float distance;
    if (delta.compareLessThanZero4().anyIsSet(Vector4Comparison::MASK_XYZ))
    {
        distance = delta.normalizeWithLength3();
        distance -= sphereA->getRadius() + boxB->getRadius();
        if (distance > input.getTolerance())
        {
            return false;
        }
        hkVector4Util_S::mulSigns4(delta, posLocal);
        delta.setNeg4(delta);
        contactOut.getSeparatingNormal()._setRotatedDir(bodyB.getTransform().getRotation(), delta);
    }
    else
    {
        float dx = absPos(0) - boxB->getHalfExtents()(0);
        float dy = absPos(1) - boxB->getHalfExtents()(1);
        float dz = absPos(2) - boxB->getHalfExtents()(2);
        int axis;
        if (dx > dy)
        {
            if (dx > dz)
            {
                axis = 0;
                contactOut.setNormal(bodyB.getTransform().getColumn(0));
                distance = dx;
            }
            else
            {
                axis = 2;
                contactOut.setNormal(bodyB.getTransform().getColumn(2));
                distance = dz;
            }
        }
        else
        {
            if (dy > dz)
            {
                axis = 1;
                contactOut.setNormal(bodyB.getTransform().getColumn(1));
                distance = dy;
            }
            else
            {
                axis = 2;
                contactOut.setNormal(bodyB.getTransform().getColumn(2));
                distance = dz;
            }
        }
        if (posLocal(axis) < 0.0f)
        {
            contactOut.getSeparatingNormal().negateSelf();
        }
        distance = distance - boxB->getRadius() - sphereA->getRadius();
    }
    contactOut.getPosition().setAddMul4(posA, contactOut.getNormal(), hkSimdReal(-distance - sphereA->getRadius()));
    contactOut.setDistance(distance);
    contactOut.getPosition()(3) = 1.0f;
    return true;
}

__forceinline void S3c5_endTimer(const char* name, unsigned int& ticks)
{
    hkMonitorStream& stream = hkMonitorStream::getInstance();
    if (stream.memoryAvailable()) {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)stream.getEnd();
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_time0 = *(volatile unsigned int*)&ticks;
        stream.setEnd((char*)(h + 1));
    }
}
__forceinline void S3c5_SphereBoxAgent::processContact(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const S3c5_CollisionInput& input, S3c5_ProcessCollisionOutput& result)
{
    union Saved { S3c5_SphereBoxAgent* self; unsigned int ticks; } saved;
    saved.self = this;
    S3c5_timer(str_010cf050);

    S3c5_ProcessCdPoint* point = result.reserveContactPoints(1);

    if (ComputeClosestPoints(bodyA, bodyB, input, point->m_kPoint))
    {
        S3c5_SphereBoxAgent* agent = *(S3c5_SphereBoxAgent* volatile*)&saved.self;
        if (agent->m_usContactPointId == 0xffff)
        {
            agent->m_usContactPointId = agent->m_pContactManager->addContactPoint(bodyA, bodyB, input, result, 0, point->m_kPoint);
        }

        if (agent->m_usContactPointId != 0xffff)
        {
            point->m_usContactPointId = agent->m_usContactPointId;
            result.commitContactPoints(1);
        }
        else
        {
            result.abortContactPoints(1);
        }
    }
    else
    {
        result.abortContactPoints(1);
        S3c5_SphereBoxAgent* agent = *(S3c5_SphereBoxAgent* volatile*)&saved.self;
        if (agent->m_usContactPointId != 0xffff)
        {
            agent->m_pContactManager->removeContactPoint(agent->m_usContactPointId, *result.m_pConstraintOwner);
            agent->m_usContactPointId = 0xffff;
        }
    }

    S3c5_endTimer(str_010c41f8, saved.ticks);
}

// @fnv 0x00d3c5b0
// src: HAVOK_SRC 0x00d3c5b0
void AgentBase::hkpSphereBoxAgent_processCollision(int a, int b, int c, Simplex* s)
{
    ((S3c5_SphereBoxAgent*)this)->processContact(*(const hkpCdBody*)a, *(const hkpCdBody*)b, *(const S3c5_CollisionInput*)c, *(S3c5_ProcessCollisionOutput*)s);
}

extern "C" {
LocalM128 _mm_and_ps(LocalM128, LocalM128);
LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
LocalM128 _mm_sub_ps(LocalM128, LocalM128);
LocalM128 _mm_min_ps(LocalM128, LocalM128);
LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
LocalM128 _mm_setzero_ps(void);
LocalM128 _mm_set_ss(float);
LocalM128 _mm_load_ss(const float*);
LocalM128 _mm_add_ss(LocalM128, LocalM128);
LocalM128 _mm_sub_ss(LocalM128, LocalM128);
LocalM128 _mm_mul_ss(LocalM128, LocalM128);
LocalM128 _mm_rsqrt_ss(LocalM128);
LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
int _mm_movemask_ps(LocalM128);
void _mm_store_ss(float*, LocalM128);
unsigned __int64 __rdtsc(void);
void _ReadWriteBarrier(void);
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
}

extern unsigned long DAT_0126835c;
extern const char str_010cf050[];
extern const char str_010c41f8[];
extern const unsigned int DAT_01017d10[4];
extern const unsigned int DAT_010c44d0[4];

static __forceinline void ReadTimerTicks(hkMonitorStream::TimerCommand& command)
{
    unsigned int ticks;
    __asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
    command.m_time0 = ticks;
}

static __forceinline void S00d3c910_timerBegin(const char* name)
{
    hkMonitorStream& mStream = hkMonitorStream::getInstance();
    if (mStream.memoryAvailable())
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.getEnd();
        h->m_commandAndMonitor = name;
        ReadTimerTicks(*h);
        mStream.setEnd((char*)(h + 1));
    }
}

namespace S00d3c910_Util
{
    extern const unsigned int DAT_010c44d0[4];

    __forceinline void mulSigns4(hkVector4& inout, const hkVector4& signs)
    {
        inout.getQuad() = _mm_xor_ps(inout.getQuad(),
            _mm_and_ps(signs.getQuad(), *(const LocalM128*)&DAT_010c44d0));
    }
}

#include "../../../../../../../include/hkpCdBody.h"


struct S00d3c910_CollisionInput
{
    void* m_pCollisionDispatcher;
    int m_collisionQuality;
    float m_fScalar;
    float getTolerance() const { return m_fScalar; }
};

struct S00d3c910_CdPoint
{
    hkContactPoint m_kPoint;
    const hkpCdBody& m_pBodyA;
    const hkpCdBody& m_pBodyB;
    S00d3c910_CdPoint(const hkpCdBody& a, const hkpCdBody& b) : m_pBodyA(a), m_pBodyB(b) {}
};

struct S00d3c910_CdPointCollector
{
    virtual ~S00d3c910_CdPointCollector();
    virtual void AddCdPoint(const S00d3c910_CdPoint& event);
};

struct S00d3c910_SphereBoxAgent
{
    static bool ComputeClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
        const S00d3c910_CollisionInput& input, hkContactPoint& contact);
    void hkpSphereBoxAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
        const S00d3c910_CollisionInput& input, S00d3c910_CdPointCollector& collector);
};

__forceinline bool S00d3c910_SphereBoxAgent::ComputeClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
    const S00d3c910_CollisionInput& input, hkContactPoint& contact)
{
    const hkVector4& posA = bodyA.getTransform().getTranslation();
    hkVector4 posLocal;
    posLocal.SetTransformedPosition(bodyB.getTransform(), posA);

    const hkpBoxShape* boxB = static_cast<const hkpBoxShape*>(bodyB.getShape());
    const hkpConvexShape* sphereA = static_cast<const hkpConvexShape*>(bodyA.getShape());

    hkVector4 absPos; absPos.setAbs4(posLocal);
    hkVector4 clipped; clipped.setMin4(absPos, boxB->getHalfExtents());
    hkVector4 delta; delta.setSub4(clipped, absPos);

    float distance;
    if (delta.compareLessThanZero4().anyIsSet(Vector4Comparison::MASK_XYZ))
    {
        distance = delta.normalizeWithLength3();
        distance = distance - (sphereA->getRadius() + boxB->getRadius());
        if (distance > input.getTolerance())
        {
            return false;
        }
        S00d3c910_Util::mulSigns4(delta, posLocal);
        delta.setNeg4(delta);
        contact.getSeparatingNormal()._setRotatedDir(bodyB.getTransform().getRotation(), delta);
    }
    else
    {
        float dx = absPos(0) - boxB->getHalfExtents()(0);
        float dy = absPos(1) - boxB->getHalfExtents()(1);
        float dz = absPos(2) - boxB->getHalfExtents()(2);
        int axis;
        if (dx > dy)
        {
            if (dx > dz)
            {
                axis = 0;
                contact.setNormal(bodyB.getTransform().getColumn(0));
                distance = dx;
            }
            else
            {
                axis = 2;
                contact.setNormal(bodyB.getTransform().getColumn(2));
                distance = dz;
            }
        }
        else
        {
            if (dy > dz)
            {
                axis = 1;
                contact.setNormal(bodyB.getTransform().getColumn(1));
                distance = dy;
            }
            else
            {
                axis = 2;
                contact.setNormal(bodyB.getTransform().getColumn(2));
                distance = dz;
            }
        }
        if (posLocal(axis) < 0.0f)
        {
            contact.getSeparatingNormal().setNeg4(contact.getSeparatingNormal());
        }
        distance = distance - boxB->getRadius() - sphereA->getRadius();
    }
    contact.getPosition().setAddMul4(posA, contact.getNormal(), hkSimdReal(-distance - sphereA->getRadius()));
    contact.setDistance(distance);
    contact.getPosition()(3) = 1.0f;
    return true;
}

// @fnv 0x00d3c910
// src: HAVOK_SRC 0x00d3c910
void S00d3c910_SphereBoxAgent::hkpSphereBoxAgent_getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
    const S00d3c910_CollisionInput& input, S00d3c910_CdPointCollector& collector)
{
    S00d3c910_timerBegin(str_010cf050);

    S00d3c910_CdPoint event(bodyA, bodyB);
    if (ComputeClosestPoints(bodyA, bodyB, input, event.m_kPoint))
    {
        collector.AddCdPoint(event);
    }

    S00d3c910_timerBegin(str_010c41f8);
}

__forceinline hkBool hkpSphereBoxAgent::ComputeClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkContactPoint&contactOut,hkReal& scalarScratch)
{
const hkVector4&posA=bodyA.getTransform().getTranslation();
hkVector4 posLocalB;posLocalB.SetTransformedPosition(bodyB.getTransform(),posA);
const hkpBoxShape*boxB=static_cast<const hkpBoxShape*>(bodyB.getShape());
const hkpSphereShape*sphereA=static_cast<const hkpSphereShape*>(bodyA.getShape());
hkVector4 absPosB;absPosB.setAbs4(posLocalB);
hkVector4 clippedAbsPos;clippedAbsPos.setMin4(absPosB,boxB->getHalfExtents());
hkVector4 delta;delta.setSub4(clippedAbsPos,absPosB);
hkReal distance;
if(delta.compareLessThanZero4().anyIsSet(Vector4Comparison::MASK_XYZ))
{
distance=delta.normalizeWithLength3().storeInto(scalarScratch);
distance=distance-(sphereA->getRadius()+boxB->getRadius());
if(distance>input.getTolerance())
{
return false;
}
hkVector4Util_S::mulSigns4(delta,posLocalB);
delta.setNeg4(delta);
contactOut.getSeparatingNormal()._setRotatedDir(bodyB.getTransform().getRotation(),delta);
}
else
{
hkReal d0=absPosB(0)-boxB->getHalfExtents()(0);
hkReal d1=absPosB(1)-boxB->getHalfExtents()(1);
hkReal d2=absPosB(2)-boxB->getHalfExtents()(2);
int i;
if(d0>d1)
{
if(d0>d2)
{
i=0;
contactOut.setNormal(bodyB.getTransform().getColumn(0));
distance=d0;
}
else
{
i=2;
contactOut.setNormal(bodyB.getTransform().getColumn(2));
distance=d2;
}
}
else
{
if(d1>d2)
{
i=1;
contactOut.setNormal(bodyB.getTransform().getColumn(1));
distance=d1;
}
else
{
i=2;
contactOut.setNormal(bodyB.getTransform().getColumn(2));
distance=d2;
}
}
if(posLocalB(i)<0)
{
contactOut.getSeparatingNormal().setNeg4(contactOut.getSeparatingNormal());
}
distance=distance-boxB->getRadius()-sphereA->getRadius();
}
contactOut.getPosition().setAddMul4(posA,contactOut.getNormal(),hkSimdReal(-distance-sphereA->getRadius()));
contactOut.setDistance(distance);
contactOut.getPosition()(3)=1.0f;
return true;}
// @fnv 0x00d3cc00
// src: XBOX_PDB 0x00d3cc00
void __cdecl hkpSphereBoxAgent_staticGetClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector)
{
hkUint32 ticks;
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "SphereBox";static_cast<TimerCommand_spherebox*>(h)->setTime(ticks);mStream.setEnd((char*)(h+1));}};
ContactPointPair event(bodyA,bodyB);
if(hkpSphereBoxAgent::ComputeClosestPoints(bodyA,bodyB,input,event.m_kPoint,reinterpret_cast<hkReal&>(ticks)))
{
collector.AddCdPoint(event);
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";static_cast<TimerCommand_spherebox*>(h)->setTime(ticks);mStream.setEnd((char*)(h+1));}};
}
