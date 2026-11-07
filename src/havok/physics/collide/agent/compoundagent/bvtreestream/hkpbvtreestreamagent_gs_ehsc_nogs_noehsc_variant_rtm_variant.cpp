// src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkpAgent3Input.h"
#include "../../../../../../../include/AgentSectorPointerArray.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMotionState.h"
#include "../../../../../../../include/hkQuaternion.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkStepInfo.h"
#include "../../../../../../../include/hkSweptTransform.h"
#include "../../../../../../../include/hkThreadLocalData.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpAgent1nSector.h"
#include "../../../../../../../include/hkpBvTreeShape.h"
#include "../../../../../../../include/hkpBvTreeStreamAgent.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSymmetricAgentFlipBodyCollector.h"
#include "../../../../../../../include/hkpSymmetricAgentFlipCollector.h"

typedef unsigned short hkUint16;
typedef unsigned __w64 hk_size_t;
typedef int hkBool32;
typedef unsigned short hkContactPointId;
#include "../../../../../../../include/hkResult.h"

extern "C" void __cdecl hkpBvTreeAgent_staticGetClosestPoints(void*,void*,void*,void*);
// @fnv 0x00d2dd50
extern "C" void __stdcall FUN_00d2dd50(void* a, void* b, void* c, void* d)
{
    hkpBvTreeAgent_staticGetClosestPoints(a, b, c, d);
}

template<typename T>
__forceinline void hkMemoryAllocator::_bufFree(void* p,int count) { bufFree(p,count*sizeof(T)); }

__forceinline hkMonitorStream& hkMonitorStream::getInstance()
{
    extern hkThreadLocalData<hkMonitorStream*> g_pMonitorStream;
    return *g_pMonitorStream.getData();
}
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline hkBool __cdecl hkMonitorStream::memoryAvailable() { return getEnd()<getCapacityMinus16(); }
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end=ptr; }

template<typename T>
static __forceinline int getLogicalSize(const hkArray<T>& array) { return array.m_iElementCount; }

#include "../../../../../../../include/hkArray.h"
// The in-place hit list's lifetime (hkArray dtor = clearAndDeallocate) and append, as hkArray.inl.
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & int(0x80000000)) == 0)
        alloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
    m_data = 0;
    m_iCapacityState = int(0x80000000);
}
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    clearAndDeallocate();
}
template <typename T> __forceinline void hkArrayBase<T>::pushBackUnchecked(const T& t)
{
    m_data[m_iElementCount++] = t;
}
__forceinline hkTransform::hkTransform() {}
__forceinline hkAabb::hkAabb() {}
__forceinline hkSimdReal::hkSimdReal(float value) { m_vValue=_mm_load_ss(&value); }
__forceinline __m128 hkSimdReal::broadcast() const { return _mm_shuffle_ps(m_vValue,m_vValue,0); }
typedef __m128 hkQuadReal;
typedef const hkVector4&hkVector4Parameter;

typedef const hkSimdReal&hkSimdRealParameter;

__forceinline void* __cdecl hkMatrix3::operator new(size_t nbytes)
{
    return hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
}
__forceinline hkMatrix3::hkMatrix3() {}

__forceinline void* __cdecl hkRotation::operator new(size_t nbytes)
{
    return hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
}

// Unit-local inline bodies for operations declared by the shared hkVector4 header.
inline const __m128& hkVector4::getQuad() const { return m_vComponents; }
inline hkReal& hkVector4::operator()(int index) { return reinterpret_cast<hkReal*>(&m_vComponents)[index]; }
inline const hkReal& hkVector4::operator()(int index) const { return reinterpret_cast<const hkReal*>(&m_vComponents)[index]; }
__forceinline void hkVector4::setZero4() { m_vComponents=_mm_setzero_ps(); }
__forceinline void hkVector4::setMul4(const hkSimdReal& scalar,const hkVector4& v) { m_vComponents=_mm_mul_ps(scalar.broadcast(),v.m_vComponents); }
__forceinline void hkVector4::setMin4(const hkVector4& a,const hkVector4& b) { m_vComponents=_mm_min_ps(a.getQuad(),b.getQuad()); }
__forceinline void hkVector4::setMax4(const hkVector4& a,const hkVector4& b) { m_vComponents=_mm_max_ps(a.getQuad(),b.getQuad()); }

__forceinline void hkVector4::addMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(r.broadcast(),v1.m_vComponents));
}
__forceinline void hkVector4::setCross(const hkVector4&v0,const hkVector4&v1)
{
hkQuadReal cross0;
cross0=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))));
hkQuadReal cross1;
cross1=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))));
m_vComponents=_mm_sub_ps(cross0,cross1);}

extern "C" const hkQuadReal DAT_010c44d0;
extern "C" const char str_010ce7d4[];
// Preserve the RTM scalar broadcast and original shared sign-mask load.
static __forceinline void setAllComponents(hkVector4& out, hkReal value)
{
    out.m_vComponents=_mm_set_ps1(value);
}
static __forceinline void setNeg4(hkVector4& out, const hkVector4& value)
{
    out.m_vComponents=_mm_xor_ps(value.m_vComponents,DAT_010c44d0);
}
static __forceinline void setRotatedInverseDir(hkVector4& out,const hkRotation&r,const hkVector4&b)
{
hkQuadReal c0=r.getColumn(0).m_vComponents;
hkQuadReal c1=r.getColumn(1).m_vComponents;
hkQuadReal c2=r.getColumn(2).m_vComponents;
{hkQuadReal _tmp,_ctmp;_tmp=_mm_unpacklo_ps(c0,c1);_ctmp=_mm_shuffle_ps(_mm_unpackhi_ps(c0,c1),c2,(((3)<<6)|((2)<<4)|((1)<<2)|((0))));c0=_mm_movelh_ps(_tmp,c2);c1=_mm_shuffle_ps(_mm_movehl_ps(c0,_tmp),c2,(((3)<<6)|((1)<<4)|((1)<<2)|((0))));c2=_ctmp;};
const hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
const hkQuadReal r0=_mm_mul_ps(c0,b0);
const hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
const hkQuadReal r1=_mm_mul_ps(c1,b1);
const hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
const hkQuadReal r2=_mm_mul_ps(c2,b2);
out.m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),r2);}
static __forceinline void setTransformedInversePos(hkVector4& out,const hkTransform&a,const hkVector4&b)
{
hkVector4 t0;t0.setSub4(b,a.getTranslation());
setRotatedInverseDir(out,a.getRotation(),t0);
}
inline const hkVector4&hkRotation::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
__forceinline const hkVector4&hkTransform::getTranslation()const
{
return reinterpret_cast<const hkVector4&>(m_row3);
}
__forceinline const hkRotation&hkTransform::getRotation()const
{
return reinterpret_cast<const hkRotation&>(m_row0);
}
__forceinline hkReal hkSweptTransform::getInvDeltaTime()const
{
return m_vCenterOfMass1(3);
}
__forceinline void hkMonitorStream::TimerCommand::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_time0=ticks;
}
__forceinline const hkTransform&hkMotionState::getTransform()const
{
return m_kMotionTransform;
}
__forceinline const hkSweptTransform&hkMotionState::getSweptTransform()const
{
return m_kSweptTransform;
}
__forceinline hkBool hkAabb::contains(const hkAabb& other) const
{
    __m128 mincomp=_mm_cmple_ps(m_kMinimumCorner.m_vComponents,other.m_kMinimumCorner.m_vComponents);
    __m128 maxcomp=_mm_cmple_ps(other.m_kMaximumCorner.m_vComponents,m_kMaximumCorner.m_vComponents);
    return (_mm_movemask_ps(_mm_and_ps(mincomp,maxcomp)) & 7)==7;
}
__forceinline void hkpShape::getAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const
{
CalculateAabb(localToWorld,tolerance,out);
}
__forceinline const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
__forceinline const hkMotionState*hkpCdBody::GetMotionState()const
{
return static_cast<const hkMotionState*>(m_pMotionState);
}
__forceinline const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}

struct AgentSubtypeMarker:public hkpAgent3Input
{
hkPadSpu<hkReal>m_fSubtypeValue;
hkVector4 m_vSubtypePosition;};
class hkpCollisionFilter;
class hkpConvexListFilter;
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
struct AabbBoundsAndScale
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(CollisionAgentContext::AabbBoundsAndScale));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_kAabbMin;
hkVector4 m_kAabbMaximum;
hkVector4 m_kAabbScale;
};
AabbBoundsAndScale m_aiValues;};
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable hkPadSpu<hkpCollisionQualityInfo*>m_pCollisionQualityInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;};
class hkpBvTreeAgent:public hkpCollisionAgent
{
public:
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector);
static void __cdecl m_pVirtualFunction2(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector);
virtual void linearCast(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&collector,hkpCdPointCollector*startCollector);
static void __cdecl m_pVirtualFunction3(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&collector,hkpCdPointCollector*startCollector);
virtual void FUN_00d2df90(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void cleanup(hkpConstraintOwner&info);
static void __cdecl setUseAabbCaching(hkBool useIt);
static hkBool __cdecl getUseAabbCaching();
public:
static hkBool ms_bUseAabbCaching;
virtual void ProcessContactPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpConstraintOwner&constraintOwner);
virtual void RemovePoint(const CollisionAgentContext&input);
virtual void WarpTime(hkTime oldTime,hkTime newTime,const CollisionAgentContext&input);
__forceinline static hkResult __cdecl BuildCollisionHitList(
const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkTransform&bTa,
const hkVector4&linearTimInfo,const GskAgentInput&input,
hkAabb*cachedAabb,hkArray<hkpShapeKey>&hitListOut);
public:
hkpBvTreeAgent(hkpContactMgr*mgr);
protected:
void calcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
static hkpCollisionAgent*__cdecl CreateBvTreeAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&env,hkpContactMgr*mgr);
void ProcessCollisionPartners(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpConstraintOwner&constraintOwner);
__forceinline void prepareCollisionPartnersProcess(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,hkpConstraintOwner&constraintOwner);
static void __cdecl CalculateAabbForLinearCast(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkAabb&aabbOut);
static void __cdecl CalculateAabbForCollision(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkAabb&aabbOut);
~hkpBvTreeAgent(){}
struct BvTreeAgentTrack
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(hkpBvTreeAgent::BvTreeAgentTrack));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkpShapeKey m_key;
hkInt32 m_iValueAtOffset4;
hkpCollisionAgent*m_pCollisionAgent;
hkpShapeKey&GetIteratorKey(){return m_key;}
void setKey(hkpShapeKey&key){m_key=key;}
};
hkArray<BvTreeAgentTrack>m_kEntries;
hkAabb m_kBoundingBox;
static hkBool ms_bUseAabbCache;
static hkpCollisionAgent*__cdecl createShapeBvAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createBvTreeShapeAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createBvBvAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
};
extern "C"
{
void __cdecl BuildShapeCollectionBWorldOperations(AgentSectorPointerArray&agentTrack,const AgentSubtypeMarker&input,const hkpShapeContainer*shapeContainterB,const hkpShapeKey*hitList,WorldOperationEntry&output);}
namespace MotionUtilities
{
__forceinline void __cdecl calcTimInfo(const hkMotionState&ms0,const hkMotionState&ms1,hkReal deltaTime,hkVector4&timOut);}
void __cdecl MotionUtilities::calcTimInfo(const hkMotionState&ms0,const hkMotionState&ms1,hkReal deltaTime,hkVector4&timOut)
{
const hkSweptTransform&st0=ms0.getSweptTransform();
const hkSweptTransform&st1=ms1.getSweptTransform();
hkVector4 diff0;diff0.setSub4(st0.m_vCenterOfMass0,st0.m_vCenterOfMass1);
hkVector4 diff1;diff1.setSub4(st1.m_vCenterOfMass1,st1.m_vCenterOfMass0);
hkReal f0=deltaTime*st0.getInvDeltaTime();
hkReal f1=deltaTime*st1.getInvDeltaTime();
timOut.setMul4(hkSimdReal(f0),diff0);
timOut.addMul4(f1,diff1);
timOut(3)=f0*ms0.m_kDeltaAngle(3)*ms0.m_fObjectRadius+f1*ms1.m_kDeltaAngle(3)*ms1.m_fObjectRadius;}
namespace AlgorithmUtilities
{template<typename T>
class less
{
public:
__forceinline hkBool32 operator()(const T&a,const T&b)
{
return(a<b);
}
};
template<typename T>
__forceinline void __cdecl quickSort(T*pArr,int iSize)
{
quickSort(pArr,iSize,less<T>());
}
template<typename T,typename L>
void __cdecl QuickSortSubrange(T*pArr,int d,int h,L cmpLess);}
namespace AlgorithmUtilities
{template<typename T,typename L>
void __cdecl quickSort(T*pArr,int iSize,L cmpLess)
{
if(iSize>1)
{
int low=0;
int high=iSize-1;
QuickSortSubrange(pArr,low,high,cmpLess);
}
}
}
void SetMemoryState(hkMemoryAllocator::MemoryState state);__forceinline bool hkHasMemoryAvailable(int id,int size)
{
// The shared vf09 slot lacks the bool(int) availability-query signature.
// Keep the call type here so this unit needs no shared-header change.
hkMemoryAllocator& allocator=hkMemoryRouter::getInstance().heap();
typedef bool (__thiscall *CanAllocateBytes)(hkMemoryAllocator*,int);
bool hasAvailable=reinterpret_cast<CanAllocateBytes>((*reinterpret_cast<void***>(&allocator))[9])(&allocator,size);
return hasAvailable;
}
hkResult __cdecl hkpBvTreeAgent::BuildCollisionHitList(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkTransform&bTa,
const hkVector4&linearTimInfo,const GskAgentInput&input,
hkAabb*cachedAabb,hkArray<hkpShapeKey>&hitListOut)
{
hkAabb aabb;
{
const hkMotionState*msA=bodyA.GetMotionState();
const hkMotionState*msB=bodyB.GetMotionState();
hkVector4 timInfo;setRotatedInverseDir(timInfo,bodyB.getTransform().getRotation(),linearTimInfo);
hkVector4 aabbExtents;
if(input.m_pCollisionQualityInfo->m_iQualityInfoValue10.val())
{
const hkReal secOrdErrA=(msA->m_kDeltaAngle(3)+msB->m_kDeltaAngle(3))*msA->m_fObjectRadius;
const hkReal secOrdErrB=msB->m_kDeltaAngle(3)*msB->m_kDeltaAngle(3)*msB->m_fObjectRadius;
const hkReal checkEpsilon=input.m_fScalar*0.5+(secOrdErrA+secOrdErrB);
bodyA.getShape()->getAabb(bTa,checkEpsilon,aabb);
hkVector4 massCenterAinB;
{
hkVector4 radius4;
setAllComponents(radius4,input.m_fScalar*0.5+msA->m_fObjectRadius+secOrdErrB);
setTransformedInversePos(massCenterAinB,bodyB.getTransform(),msA->getSweptTransform().m_vCenterOfMass1);
hkVector4 maxR;maxR.setAdd4(massCenterAinB,radius4);
hkVector4 minR;minR.setSub4(massCenterAinB,radius4);
aabb.m_kMinimumCorner.setMax4(aabb.m_kMinimumCorner,minR);
aabb.m_kMaximumCorner.setMin4(aabb.m_kMaximumCorner,maxR);
}
aabbExtents.setSub4(aabb.m_kMaximumCorner,aabb.m_kMinimumCorner);
{
if(msB->m_kDeltaAngle(3)>0.0)
{
hkVector4 relPos;relPos.setSub4(massCenterAinB,msB->getSweptTransform().m_vCenterOfMassLocal);
hkVector4 offsetOut;offsetOut.setCross(relPos,msB->m_kDeltaAngle);
hkReal f=input.m_pStepInfo.m_fTimeStep*msB->getSweptTransform().getInvDeltaTime();
timInfo.addMul4(f,offsetOut);
}
hkVector4 zero;zero.setZero4();
hkVector4 minPath;minPath.setMin4(zero,timInfo);
hkVector4 maxPath;maxPath.setMax4(zero,timInfo);
aabb.m_kMinimumCorner.add4(minPath);
aabb.m_kMaximumCorner.add4(maxPath);
}
}
else
{
const hkReal checkEpsilon=input.m_fScalar*0.5;
bodyA.getShape()->getAabb(bTa,checkEpsilon,aabb);
aabbExtents.setSub4(aabb.m_kMaximumCorner,aabb.m_kMinimumCorner);
}
if(cachedAabb)
{
if(cachedAabb->contains(aabb))
{
return HK_FAILURE;
}
hkVector4 zero;zero.setZero4();
hkVector4 minPath;minPath.setMin4(zero,timInfo);
hkVector4 maxPath;maxPath.setMax4(zero,timInfo);
hkVector4 expand4;setAllComponents(expand4,input.m_fScalar*0.5);
aabb.m_kMinimumCorner.sub4(expand4);
aabb.m_kMaximumCorner.add4(expand4);
const hkReal maxExpand=0.4f;
const hkReal framesLookAhead=-2.0f;
hkVector4 minExtentPath;minExtentPath.setMul4(hkSimdReal(framesLookAhead),maxPath);
hkVector4 maxExtentPath;maxExtentPath.setMul4(hkSimdReal(framesLookAhead),minPath);
hkVector4 maxExpand4;maxExpand4.setMul4(hkSimdReal(maxExpand),aabbExtents);
maxExtentPath.setMin4(maxExtentPath,maxExpand4);
hkVector4 minExpand4;setNeg4(minExpand4,maxExpand4);
minExtentPath.setMax4(minExtentPath,minExpand4);
aabb.m_kMinimumCorner.add4(minExtentPath);
aabb.m_kMaximumCorner.add4(maxExtentPath);
cachedAabb->m_kMinimumCorner=aabb.m_kMinimumCorner;
cachedAabb->m_kMaximumCorner=aabb.m_kMaximumCorner;
}
}
const hkpBvTreeShape*bvB=static_cast<const hkpBvTreeShape*>(bodyB.getShape());
bvB->GetAabbHits(aabb,hitListOut);
return HK_SUCCESS;}
// @fnv 0x00d2df90
void hkpBvTreeStreamAgent::vf06(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&output)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerBeginListCommand*h=reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.getEnd());h->m_commandAndMonitor="L" "t" "BvTree3";h->m_nameOfFirstSplit="S" "t" "QueryTree";h->setTime();mStream.setEnd((char*)(h+1));}};
AgentSubtypeMarker in3;
{
in3.m_pBodyA=&bodyA;
in3.m_pBodyB=&bodyB;
in3.m_pContactManager=m_pContactManager;
in3.m_pRayCastInput=reinterpret_cast<const hkpProcessCollisionInput*>(&input);
const hkMotionState*msA=bodyA.GetMotionState();
const hkMotionState*msB=bodyB.GetMotionState();
MotionUtilities::calcTimInfo(*msA,*msB,input.m_pStepInfo.m_fTimeStep,in3.m_vSubtypePosition);
in3.m_kTransform.SetMulInverse(msA->getTransform(),msB->getTransform());
}
hkInplaceArray<hkpShapeKey,128>hitList;
hitList.pushBackUnchecked(0xffffffff);
hkResult prepareSuccessful;
{
hkTransform bTa;bTa.SetConjugate(in3.m_kTransform);
prepareSuccessful=hkpBvTreeAgent::BuildCollisionHitList(bodyA,bodyB,bTa,in3.m_vSubtypePosition,input,&m_kBoundingBox,hitList);
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor=str_010ce7d4;h->setTime();mStream.setEnd((char*)(h+1));}};
if(prepareSuccessful==HK_SUCCESS)
{
int newMemNeeded=(hitList.GetLogicalSize()/ 4+1-getLogicalSize(m_kAgentNnTrack.m_kSectors))*hkpAgent1nSector::SECTOR_SIZE;
if(!hkHasMemoryAvailable(3,newMemNeeded))
{
SetMemoryState(hkMemoryAllocator::MEMORY_STATE_OUT_OF_MEMORY);
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="l" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
AlgorithmUtilities::quickSort(hitList.begin(),hitList.GetLogicalSize());
;
const hkpBvTreeShape*bvB=static_cast<const hkpBvTreeShape*>(bodyB.getShape());
const hkpShapeContainer*shapeContainer=bvB->GetShapeContainer();
BuildShapeCollectionBWorldOperations(m_kAgentNnTrack,in3,shapeContainer,hitList.begin(),output);
}
else
{
const hkpBvTreeShape*bvB=static_cast<const hkpBvTreeShape*>(bodyB.getShape());
const hkpShapeContainer*shapeContainer=bvB->GetShapeContainer();
BuildShapeCollectionBWorldOperations(m_kAgentNnTrack,in3,shapeContainer,0,output);
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="l" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}
