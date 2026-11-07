#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
// Preserve this unit's intrinsic register representation: the VC9 CRT union's
// array members change /GS parameter copies and stack allocation.
#ifndef _INCLUDED_MM2
#define _INCLUDED_MM2
// Exe 0x00df7340 FUN_00df7340: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float x;
} __m128, LocalM128;
extern "C" {
extern LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern LocalM128 _mm_sqrt_ss(LocalM128);
extern LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern LocalM128 _mm_load_ss(const float*);
extern void _mm_store_ss(float*, LocalM128);
}
#endif

#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkJobType.h"
#include "../../../../../../../../include/hkStepInfo.h"
#include "../../../../../../../../include/hkThreadLocalData.h"
#include "../../../../../../../../include/hkAabb.h"
#include "../../../../../../../../include/hkAabbTreeQueryUtils.h"
#include "../../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../../include/hkRotation.h"
#include "../../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../../include/hkBool.h"
#include "../../../../../../../../include/hkKdTreeCastCollector.h"
#include "../../../../../../../../include/hkTransform.h"
#include "../../../../../../../../include/hkpBroadPhase.h"
#include "../../../../../../../../include/hkpBroadPhaseCastCollector.h"
#include "../../../../../../../../include/hkpCollidable.h"
#include "../../../../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../../../../include/hkpCollisionFilter.h"
#include "../../../../../../../../include/hkpGroupFilter.h"
#include "../../../../../../../../include/hkpRayCollidableFilter.h"
#include "../../../../../../../../include/hkpRayShapeCollectionFilter.h"
#include "../../../../../../../../include/hkpShape.h"
#include "../../../../../../../../include/hkpShapeCollectionFilter.h"
#include "../../../../../../../../include/Data.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../../include/hkMultiThreadCheck.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../../../include/hkpFixedBufferCdPointCollector.h"
#include <new>
// src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldlinearcastjob_ehsc_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldlinearcastjob_ehsc_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldlinearcastjob_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldlinearcastjob.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldlinearcastjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldlinearcastjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00df71c0_Value {
    int unk00;
    float value;
};
struct FUN_00df71c0_Class {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00df71c0_Value* unk10;
    float GetValue_00df71c0();
};
struct TargetBase { void CastAgainstCollidable(volatile Data *value); };
struct FUN_00df72c0_class {
    int unk00;
    int unk04;
    void ForwardToBase(volatile Data *value);
};
struct Param { unsigned int unk00; unsigned int unk04; unsigned int unk08; Param* next0c; };
struct This { int CastAgainstCollidable(Param*); int hkCpuWorldLinearCastCollector_addLeaf(Param*); };

struct DF7230CdPointCollector {
    int unk00;
    float m_fEarlyOutDistance;
};
struct DF7230LinearCastInput;
typedef void (__cdecl* DF7230LinearCastFunc)(const hkpCollidable& bodyA, const hkpCollidable& bodyB, const DF7230LinearCastInput& input, DF7230CdPointCollector& collector, DF7230CdPointCollector* startCollector);
struct DF7230AgentFuncs {
    void* unk00;
    DF7230LinearCastFunc m_pLinearCastFunc;
    void* unk08;
    void* unk0C;
    void* unk10;
};
struct DF7230Dispatcher {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    unsigned char m_agent2TypeMap[64][32];
    int unk9A0;
    int unk9A4;
    DF7230AgentFuncs m_agent2Funcs[1];

    DF7230LinearCastFunc getLinearCastFunc(int typeA, int typeB) const
    {
        return m_agent2Funcs[m_agent2TypeMap[typeA][typeB]].m_pLinearCastFunc;
    }
};
struct DF7230LinearCastInput {
    const DF7230Dispatcher* m_pCollisionDispatcher;
};

struct DF7230CastCollector {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    const hkpCollisionFilter* m_iFilter;
    DF7230CdPointCollector* m_pPointCollector;
    const hkpCollidable* m_pCollidableA;
    int m_shapeTypeA;
    DF7230LinearCastInput m_pRayCastInput;

    float CastAgainstCollidable(const hkpCollidable* collidableB);
};
// FUN_00df7320 - 0x00df7320, 19 bytes
//
//   mov edx, dword ptr [esp + 4]      ; the first stack argument
//   movsx eax, byte ptr [edx + 5]     ; signed byte at +5 of that object
//   add eax, edx                      ; object + offset
//   push eax
//   call 0xdf7230                     ; same class, this (ECX) forwarded
//   ret 8
//
// CastAgainstCollidable is a __thiscall member of the same class with one 4-byte
// stack argument; it ends with `ret 4`, so it pops the pushed pointer
// itself and our own epilogue only has to drop the two incoming arguments.
//
// The function is a virtual of hkCpuWorldLinearCastCollector (its vftable
// entry sits at 0x010db9e8); `this` is never touched here, it is simply
// passed on to CastAgainstCollidable.
// The object the collector is asked about.  The signed byte at +0x05 is the
// offset of the sub-object that has to be evaluated.
struct FUN_00df7320_Shape {
    int unk00;          // +0x00
    signed char unk04;  // +0x04
    signed char unk05;  // +0x05
};
struct FUN_00df7320_Collector {
    float CastAgainstCollidable(FUN_00df7320_Shape* value);
    float ProcessAndReturnValue_00df7320(FUN_00df7320_Shape* shape, FUN_00df7320_Shape* other);
};
struct Base1 { virtual void FUN_00df7190(); };
struct Base2 { virtual void FUN_00df7190(); };
struct Derived : Base1, Base2 { Derived(); virtual void FUN_00df7190(); };
struct DF71B0Primary {
    virtual void vfunc00();
    virtual void FUN_00df71b0();

    int unk04;
    int unk08;
};
struct DF71B0Secondary {
    virtual void FUN_00df71b0();
};
struct DF71B0Object : DF71B0Primary, DF71B0Secondary {
    DF71B0Object();

// @fnv 0x00df71b0
    virtual void FUN_00df71b0();
};
DF71B0Object::DF71B0Object()
{
}
struct S_00df71d0_Heap {
    virtual void v0();
    virtual void v1();
    virtual void ReleaseBlock(void* p, unsigned int n);
};
struct S_00df71d0_Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00df71d0_Heap* unk10;
    S_00df71d0_Heap& heap() { return *unk10; }
};
S_00df71d0_Router* hkMemoryRouter_getInstance();

struct S_00df71d0_B2 {
    virtual void f2() {}
    ~S_00df71d0_B2() {}
};
struct S_00df71d0_B3 {
    virtual void f3() {}
    ~S_00df71d0_B3() {}
};
struct FUN_00df71d0 : hkpBroadPhaseCastCollector, hkKdTreeCastCollector, S_00df71d0_B2, S_00df71d0_B3 {
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
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
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
    int unk88;
    int unk8c;
    FUN_00df71d0();
// @fnv 0x00df71d0
    virtual ~FUN_00df71d0() {}
    static void operator delete(void* p, unsigned int n) { hkMemoryRouter_getInstance()->heap().ReleaseBlock(p, n); }
};
FUN_00df71d0::FUN_00df71d0() {}

typedef float hkReal;
typedef signed char hkInt8;
typedef signed short hkInt16;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long hkUlong;
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;
class hkStatisticsCollector;
// hkTypeIsPod / hkArray: include/hkArray.h
typedef LocalM128 hkQuadReal;

typedef const hkVector4&hkVector4Parameter;

typedef const hkSimdReal&hkSimdRealParameter;

__forceinline LocalM128 hkSimdReal::broadcast() const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}

static __forceinline hkQuadReal scalarQuad(hkReal value)
{
return _mm_load_ss(&value);
}
static __forceinline const hkSimdReal& scalarValue(const hkQuadReal& value)
{
return reinterpret_cast<const hkSimdReal&>(value);
}

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
};private:
hkQuadReal m_uiMask;};
__forceinline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
}
__forceinline void hkVector4::setAdd4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
__forceinline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
__forceinline void hkVector4::mul4(hkSimdRealParameter s)
{
m_vComponents=_mm_mul_ps(s.broadcast(),m_vComponents);
}
__forceinline void hkVector4::setInterpolate4(const hkVector4&v0,const hkVector4&v1,hkSimdRealParameter _t)
{
extern const hkQuadReal DAT_010ec7f0;
hkQuadReal t=_t.broadcast();
hkQuadReal s=_mm_sub_ps(DAT_010ec7f0,t);
m_vComponents=_mm_add_ps(
_mm_mul_ps(s,v0.m_vComponents),
_mm_mul_ps(t,v1.m_vComponents));}

__forceinline const hkVector4&hkTransform::getTranslation()const
{
return reinterpret_cast<const hkVector4&>(m_row3);
}

__forceinline hkMonitorStream& hkMonitorStream::getInstance()
{
extern hkThreadLocalData<hkMonitorStream*>g_pMonitorStream;
return *g_pMonitorStream.getData();
}
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end=ptr; }
__forceinline void hkMonitorStream::TimerCommand::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_time0=ticks;
}
__forceinline hkAabb::hkAabb() {}

class hkpCollisionDispatcher;
class hkpShapeContainer;
typedef hkUint32 hkpShapeKey;
__forceinline hkpShapeType hkpShape::getType()const
{
return *reinterpret_cast<const hkpShapeType*>(&m_type);
}
__forceinline void hkpShape::getAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const
{
CalculateAabb(localToWorld,tolerance,out);
}
const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
#include "../../../../../../../../include/hkpCollisionQualityInfo.h"

class hkpConvexListFilter;
struct RealIntegerData;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
hkPadSpu<hkpCollisionDispatcher*>m_pCollisionDispatcher;
hkPadSpu<hkBool32>m_collisionQuality;
hkPadSpu<hkReal>m_fScalar;
hkPadSpu<const hkpCollisionFilter*>m_iFilter;
hkPadSpu<const hkpConvexListFilter*>m_pConvexListCollisionFilter;
mutable hkPadSpu<hkBool32>m_bCreatePredictiveAgents;
struct AabbBoundsAndScale
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(CollisionAgentContext::AabbBoundsAndScale));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_kAabbMin;
hkVector4 m_kAabbMaximum;
hkVector4 m_kAabbScale;
};
AabbBoundsAndScale m_aiValues;};
__forceinline const hkpShape*hkpCollidable::getShape()const
{
return m_pCollisionShape;
}
struct ContactPointPair
{};
void hkpCdPointCollector::reset()
{
m_fEarlyOutDistance=3.40282e+38f;
}
hkpCdPointCollector::hkpCdPointCollector()
{
reset();
}
hkpCdPointCollector::~hkpCdPointCollector()
{
}
struct hkpAgent1nSector;
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable hkPadSpu<hkpCollisionQualityInfo*>m_pCollisionQualityInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;
void*m_pCollisionFilter;
hkBool m_bEnableDeprecatedWelding;
RealIntegerData*m_pConfiguration;};struct ShapeSweepParameters:public CollisionAgentContext
{
inline ShapeSweepParameters();
inline void setPathAndTolerance(const hkVector4&path,hkReal tolerance);
hkVector4 m_path;
hkReal m_fMaxExtraPenetration;
hkReal m_fStartPointTolerance;
RealIntegerData*m_pConfiguration;};
ShapeSweepParameters::ShapeSweepParameters()
{
m_fMaxExtraPenetration=1.192092896e-07F;
}
void ShapeSweepParameters::setPathAndTolerance(const hkVector4&path,hkReal tolerance)
{
m_path=path;
hkQuadReal square=_mm_mul_ps(path.m_vComponents,path.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(square,square,0x55),square);
hkQuadReal length=_mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(square,square,0xaa),xySum));
hkReal scalarLength;
_mm_store_ss(&scalarLength,length);
m_fStartPointTolerance=scalarLength;
m_fScalar=tolerance;
}
class BusyWaitingSemaphore
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
protected:
protected:void*m_pCompletionSemaphore;};
typedef BusyWaitingSemaphore hkSemaphoreBusyWait;
template<typename T>
class CapacityGrowingArray
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
private:
inline void increaseCapacity();};
typedef hkUint8 hkJobSubType;
struct JobDescriptor
{__declspec(align(16))hkJobSubType m_ucSubType;};
struct JobQueueConstructionInfo
{};
class JobDispatcher {
public:
    struct JobQueueSlot {};
    enum JobPopFuncResult { POP_QUEUE_ENTRY, DO_NOT_POP_QUEUE_ENTRY };
    enum NextJobWaitMode { WAIT_FOR_NEXT_JOB, DO_NOT_WAIT_FOR_NEXT_JOB };
    enum JobStatus { JOB_INVALID=-1, GOT_NEXT_JOB, NO_JOBS_AVAILABLE, ALL_JOBS_FINISHED, JOBS_AVAILABLE_BUT_NOT_FOR_CURRENT_ELF };
    JobStatus GetNextJob(const JobQueueSlot* oldJob, JobQueueSlot& jobOut, NextJobWaitMode waitStatus=WAIT_FOR_NEXT_JOB);
};
struct LinearCastParameters
{
hkVector4 m_vTo;
hkReal m_fMaxExtraPenetration;
hkReal m_fMaxExtraPenetrationAgainstFixed;};typedef hkUlong hkPrimitiveId;
class KdTree
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
protected:
void AllocateNodes(int numNodes);};
struct hkAabbTreeData::SweptBoxQuery
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(SweptBoxQuery));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_vFrom;
hkVector4 m_vTo;
hkVector4 m_vHalfExtents;
};
struct CollisionQueryJobHeader
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};
struct CollisionQueryJobBase:public JobDescriptor
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
enum JobSubType
{
COLLISION_QUERY_MOPP_AABB,
COLLISION_QUERY_PAIR_GET_CLOSEST_POINTS,
COLLISION_QUERY_WORLD_GET_CLOSEST_POINTS,
COLLISION_QUERY_PAIR_LINEAR_CAST,
COLLISION_QUERY_WORLD_LINEAR_CAST,
COLLISION_QUERY_KD_TREE_AABB_QUERY_JOB,
COLLISION_QUERY_AABB_TREE_AABB_QUERY_JOB,
COLLISION_QUERY_JOB_END
};
protected:
__forceinline CollisionQueryJobBase(JobSubType subType,hkUint16 size);
public:
hkSemaphoreBusyWait*m_pCompletionSemaphore;
CollisionQueryJobHeader*m_pCollisionQueryJobHeader;
const GskAgentInput*m_pCollisionInput;};
struct LinearCastRequest
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
LinearCastParameters m_pRayCastInput;
const hkpCollidable*m_kCollidable;
RootContactPoint*m_pResultBuffer;
int m_iResultCount;
int m_iResultCapacity;};
struct RayCastCommandJob:public CollisionQueryJobBase
{
public:
friend struct GskAgentTaskHelper;
enum{MAXIMUM_NUMBER_OF_COMMANDS_PER_TASK=64};
public:
__forceinline RayCastCommandJob(const GskAgentInput*input,CollisionQueryJobHeader*jobHeader,const LinearCastRequest*commandArray,int numCommands,const hkpBroadPhase*broadphase,hkSemaphoreBusyWait*semaphore,int numCommandsPerTask=MAXIMUM_NUMBER_OF_COMMANDS_PER_TASK);
protected:
__forceinline JobDispatcher::JobPopFuncResult popJobTask(RayCastCommandJob&out);
public:
int m_iCommandCapacity;
const LinearCastRequest*m_pCommands;
int m_iCommandCount;
const hkpBroadPhase*m_pBroadPhaseRecord;
const hkAabbTree<hkAabbTreeData::RayQueryAabb,hkUint16>*m_pRayQueryAabbTree;
const hkAabbTree<hkAabbTreeData::QuantizedAabb,hkUint16>*m_pQuantizedAabbTree;
const KdTree*m_pKdTree;};

__forceinline hkpFixedBufferCdPointCollector::hkpFixedBufferCdPointCollector(RootContactPoint*buffer,int capacity):hkpCdPointCollector()
{
m_pPointBuffer=buffer;
m_pPointBufferEnd=buffer;
m_pRayCursor=capacity;
m_iPointCount=0;
}
__forceinline hkpFixedBufferCdPointCollector::~hkpFixedBufferCdPointCollector()
{
}
class BroadPhaseCastCollector;

hkpBroadPhase*__cdecl hk3AxisSweep32CreateBroadPhase(const hkVector4&worldMin,const hkVector4&worldMax,int numMarkers);

template<typename BOUNDING_VOLUME,typename hkIdxType>
inline hkAabbTreeQueryUtils<BOUNDING_VOLUME,hkIdxType>::Collector::~Collector() {}

class KdTreeAabbCast
{
public:
enum{DEFAULT_STACK_SIZE=128};
struct BoxSweepInput
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(KdTreeAabbCast::BoxSweepInput));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_vFrom;
hkVector4 m_vTo;
hkVector4 m_vHalfExtents;
BoxSweepInput(){}
};
static hkBool __cdecl CastSweptAabb(const KdTree*root,KdTreeAabbCast::BoxSweepInput&castInput,class hkKdTreeCastCollector*collector,hkReal aabbCheckTolerance);};
__forceinline hkpBroadPhase::AabbSweepInput::AabbSweepInput() : m_pBroadPhaseAabbCache(0) {}
__forceinline hkpBroadPhaseCastCollector::~hkpBroadPhaseCastCollector() {}
__forceinline hkKdTreeCastCollector::~hkKdTreeCastCollector() {}
class hkCpuWorldLinearCastCollector:public hkpBroadPhaseCastCollector,
public hkKdTreeCastCollector,
public hkAabbTreeQueryUtils<hkAabbTreeData::RayQueryAabb,hkUint16>::Collector,
public hkAabbTreeQueryUtils<hkAabbTreeData::QuantizedAabb,hkUint16>::Collector
{
protected:
hkReal ReleaseCollector(const hkpBroadPhaseHandle*broadphaseHandle,int castIndex);
virtual hkBool ReportHit(hkPrimitiveId primId);
virtual hkBool DidHit();
virtual hkReal GetHitFraction();
virtual hkReal GetHitDistance(const hkAabbTree<hkAabbTreeData::RayQueryAabb,hkUint16>::Node*leaf);
virtual hkReal GetHitDistance(const hkAabbTree<hkAabbTreeData::QuantizedAabb,hkUint16>::Node*leaf);
public:
const hkpGroupFilter*m_iFilter;
hkpFixedBufferCdPointCollector*m_pPointCollector;
const hkpCollidable*m_kCollidable;
hkpShapeType m_iType;
ShapeSweepParameters m_pRayCastInput;};
// @fnv 0x00df7340
// src: XBOX_PDB 0x00df7340
int __cdecl hkCpuWorldLinearCastJob(JobDispatcher&jobQueue,JobDispatcher::JobQueueSlot&nextJobOut)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.getEnd()<mStream.getCapacityMinus16()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "CollQueryWorldLinearCast";h->setTime();mStream.setEnd((char*)(h+1));}};
const RayCastCommandJob&worldLinearCastJob=reinterpret_cast<RayCastCommandJob&>(nextJobOut);
hkpFixedBufferCdPointCollector castCollector(0,1);
hkCpuWorldLinearCastCollector broadPhaseCollector;
broadPhaseCollector.m_pRayCastInput.m_collisionQuality=false;
{
broadPhaseCollector.m_iFilter=static_cast<const hkpGroupFilter*>(worldLinearCastJob.m_pCollisionInput->m_iFilter.val());
broadPhaseCollector.m_pPointCollector=&castCollector;
static_cast<CollisionAgentContext&>(broadPhaseCollector.m_pRayCastInput)=*worldLinearCastJob.m_pCollisionInput;
broadPhaseCollector.m_pRayCastInput.m_pConfiguration=worldLinearCastJob.m_pCollisionInput->m_pConfiguration;
}
for(int i=0;i<worldLinearCastJob.m_iCommandCount;i++)
{
LinearCastRequest*command=const_cast<LinearCastRequest*>(&worldLinearCastJob.m_pCommands[i]);
::new(&castCollector)hkpFixedBufferCdPointCollector(command->m_pResultBuffer,command->m_iResultCount);
hkVector4 castPath;castPath.setSub4(command->m_pRayCastInput.m_vTo,static_cast<const hkTransform*>(command->m_kCollidable->m_pMotionState)->getTranslation());
broadPhaseCollector.m_kCollidable=command->m_kCollidable;
broadPhaseCollector.m_iType=command->m_kCollidable->getShape()->getType();
broadPhaseCollector.m_pRayCastInput.m_fMaxExtraPenetration=command->m_pRayCastInput.m_fMaxExtraPenetration;
broadPhaseCollector.m_pRayCastInput.setPathAndTolerance(castPath,command->m_pRayCastInput.m_fMaxExtraPenetrationAgainstFixed);
if(!worldLinearCastJob.m_pBroadPhaseRecord)
{
hkAabb CastSweptAabb;
command->m_kCollidable->getShape()->getAabb(*static_cast<const hkTransform*>(command->m_kCollidable->m_pMotionState),command->m_pRayCastInput.m_fMaxExtraPenetrationAgainstFixed,CastSweptAabb);
hkVector4 from;from.setAdd4(CastSweptAabb.m_kMaximumCorner,CastSweptAabb.m_kMinimumCorner);
from.mul4(scalarValue(scalarQuad(0.5f)));
hkVector4 to;to.setAdd4(from,castPath);
hkVector4 halfExtents;halfExtents.setSub4(CastSweptAabb.m_kMaximumCorner,CastSweptAabb.m_kMinimumCorner);
halfExtents.mul4(scalarValue(scalarQuad(0.5f)));
if(worldLinearCastJob.m_pRayQueryAabbTree || worldLinearCastJob.m_pQuantizedAabbTree)
{
hkAabbTreeData::SweptBoxQuery aabbTreeInput;
aabbTreeInput.m_vFrom=from;
aabbTreeInput.m_vTo=to;
aabbTreeInput.m_vHalfExtents=halfExtents;
hkAabbTreeQueryUtils<hkAabbTreeData::RayQueryAabb,hkUint16>::CastSweptAabb(worldLinearCastJob.m_pRayQueryAabbTree,CastSweptAabb,aabbTreeInput,&broadPhaseCollector);
hkAabbTreeQueryUtils<hkAabbTreeData::QuantizedAabb,hkUint16>::CastSweptAabb(worldLinearCastJob.m_pQuantizedAabbTree,CastSweptAabb,aabbTreeInput,&broadPhaseCollector);
}
if(worldLinearCastJob.m_pKdTree)
{
KdTreeAabbCast::BoxSweepInput kdTreeInput;
kdTreeInput.m_vFrom=from;
kdTreeInput.m_vTo=to;
kdTreeInput.m_vHalfExtents=halfExtents;
KdTreeAabbCast::CastSweptAabb(worldLinearCastJob.m_pKdTree,kdTreeInput,&broadPhaseCollector,0.0f);
}
}
else
{
hkpBroadPhase::AabbSweepInput castInput;
{
hkAabb aabb;
command->m_kCollidable->getShape()->getAabb(*static_cast<const hkTransform*>(command->m_kCollidable->m_pMotionState),command->m_pRayCastInput.m_fMaxExtraPenetrationAgainstFixed,aabb);
castInput.m_vFrom.setInterpolate4(aabb.m_kMinimumCorner,aabb.m_kMaximumCorner,scalarValue(scalarQuad(0.5f)));
castInput.m_vTo.setAdd4(castInput.m_vFrom,castPath);
castInput.m_vHalfExtents.setSub4(aabb.m_kMaximumCorner,aabb.m_kMinimumCorner);
castInput.m_vHalfExtents.mul4(scalarValue(scalarQuad(0.5f)));
castInput.m_pBroadPhaseAabbCache=0;
}
worldLinearCastJob.m_pBroadPhaseRecord->CastSweptAabb(castInput,broadPhaseCollector);
}
command->m_iResultCapacity=castCollector.m_iPointCount;
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.getEnd()<mStream.getCapacityMinus16()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return jobQueue.GetNextJob(&nextJobOut,nextJobOut);
}
