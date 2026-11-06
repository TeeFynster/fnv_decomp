#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
#include "../../../../../../../include/hkpAgent3Input.h"
#include "../../../../../../../include/hkpGskBaseAgent.h"
#include "../../../../../../../include/hkpGskfAgent.h"
#include "../../../../../../../include/hkpIterativeLinearCastAgent.h"
#include "../../../../../../../include/hkpPredGskfAgent.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMotionState.h"
#include "../../../../../../../include/hkSingleton.h"
#include "../../../../../../../include/hkSphere.h"
#include "../../../../../../../include/hkStepInfo.h"
#include "../../../../../../../include/hkThreadLocalData.h"
#include "../../../../../../../include/hkSweptTransform.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSphereRepShape.h"
#include "../../../../../../../include/ConvexContactManifold.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkQuaternion.h"
// src/havok/physics/collide/agent/convexagent/gjk/hkppredgskfagent_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/gjk/hkppredgskfagent_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/convexagent/gjk/hkppredgskfagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/convexagent/gjk/hkppredgskfagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/convexagent/gjk/hkppredgskfagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/gjk/hkppredgskfagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl __debugbreak(void);
typedef float hkReal;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;

class hkOstream;
class hkStatisticsCollector;

typedef __m128 hkQuadReal;

// The approved vector interface has storeInto and leaves these bodies to units;
// its replacement provides the inline bodies in the shared headers instead.
__if_exists(hkSimdReal::storeInto)
{
inline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x) {}
inline hkSimdReal::hkSimdReal(float x) { m_vValue = _mm_load_ss(&x); }
inline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}
__forceinline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
__forceinline hkVector4::hkVector4(const hkVector4& v)
{
    reinterpret_cast<unsigned int*>(this)[0] = reinterpret_cast<const unsigned int*>(&v)[0];
    reinterpret_cast<unsigned int*>(this)[1] = reinterpret_cast<const unsigned int*>(&v)[1];
    reinterpret_cast<unsigned int*>(this)[2] = reinterpret_cast<const unsigned int*>(&v)[2];
    reinterpret_cast<unsigned int*>(this)[3] = reinterpret_cast<const unsigned int*>(&v)[3];
}
}

__forceinline hkMatrix3::hkMatrix3() {}
inline hkTransform::hkTransform() {}
inline hkMonitorStream& hkMonitorStream::getInstance()
{
    extern hkThreadLocalData<hkMonitorStream*> g_pMonitorStream;
    return *g_pMonitorStream.getData();
}
__forceinline char* __cdecl hkMonitorStream::getStart() { return m_start.val(); }
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline hkBool __cdecl hkMonitorStream::memoryAvailable()
{
    return getEnd() < getCapacityMinus16();
}
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end = ptr; }

typedef const hkVector4&hkVector4Parameter;

typedef const hkSimdReal&hkSimdRealParameter;class Vector4Comparison;
typedef const Vector4Comparison&hkVector4ComparisonParameter;namespace MathUtilities
{template<typename T>
inline T __cdecl min2(T x,T y)
{
return x<y ? x:y;
}
}

__forceinline const hkVector4& hkRotation::getColumn(int i) const
{
return (&m_kColumn0)[i];
}

__forceinline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
__forceinline void hkVector4::setMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=_mm_mul_ps(r.broadcast(),v1.m_vComponents);
}
__forceinline void hkVector4::addMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(r.broadcast(),v1.m_vComponents));
}
__forceinline void hkVector4::_setTransformedPos(const hkTransform&t,const hkVector4&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.getTranslation().m_vComponents));}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
__forceinline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
__forceinline const hkReal&hkVector4::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
__forceinline hkVector4&hkMatrix3::getColumn(int x)
{
return(&m_kColumn0)[x];
}
__forceinline const hkVector4&hkMatrix3::getColumn(int x)const
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
// Preserve the RTM scalar copy sequence when staging transform columns.
static __forceinline void CopyVectorComponents(hkVector4& destination, const hkVector4& source)
{
    reinterpret_cast<unsigned int*>(&destination)[0] = reinterpret_cast<const unsigned int*>(&source)[0];
    reinterpret_cast<unsigned int*>(&destination)[1] = reinterpret_cast<const unsigned int*>(&source)[1];
    reinterpret_cast<unsigned int*>(&destination)[2] = reinterpret_cast<const unsigned int*>(&source)[2];
    reinterpret_cast<unsigned int*>(&destination)[3] = reinterpret_cast<const unsigned int*>(&source)[3];
}
__forceinline hkTransform::hkTransform(const hkTransform&t)
{
hkVector4 r0;
CopyVectorComponents(r0,t.getRotation().getColumn(0));
hkVector4 r1;
CopyVectorComponents(r1,t.getRotation().getColumn(1));
hkVector4 r2;
CopyVectorComponents(r2,t.getRotation().getColumn(2));
hkVector4 r3;
CopyVectorComponents(r3,t.getTranslation());
reinterpret_cast<hkVector4&>(m_row0)=r0;
reinterpret_cast<hkVector4&>(m_row1)=r1;
reinterpret_cast<hkVector4&>(m_row2)=r2;
reinterpret_cast<hkVector4&>(m_row3)=r3;}
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
class ScopedTimer
{
public:
__forceinline ~ScopedTimer(){{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};}
};
const hkSweptTransform&hkMotionState::getSweptTransform()const
{
return m_kSweptTransform;
}
typedef hkUint16 hkContactPointId;class Vector4WithInt24W:public hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};

struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;

const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
const hkMotionState*hkpCdBody::GetMotionState()const
{
return static_cast<const hkMotionState*>(m_pMotionState);
}
const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
hkpCdBody::hkpCdBody(const hkpCdBody*parent,const hkTransform*t)
{
m_parent=parent;
m_pMotionState=t;
}
hkpShapeKey hkpCdBody::getShapeKey()const
{
return m_uiCollisionShapeKey;
}
void hkpCdBody::SetCollisionShapeAndKey(const hkpShape*shape,hkpShapeKey key)
{
m_pCollisionShape=shape;
m_uiCollisionShapeKey=key;
}
struct GskAgentInput;
class hkpContactMgr;
struct WorldOperationEntry;
class hkpConstraintOwner;
class hkpCollisionAgent;
struct FourByteState
{};

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
class hkpContactMgrFactory;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct ShapeSweepParameters;
struct ContactPointWithId
{};
struct hkpAgent1nSector;
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable hkPadSpu<hkpCollisionQualityInfo*>m_pCollisionQualityInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;};
enum{HK_MAX_CONTACT_POINT=256};
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
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}public:
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
struct GskAgentData;
class ConvexShapePairCache;

class ConvexFeaturePairCache
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
hkUint16 m_kVertices[4];
hkUint8 m_ucDimensionA;
hkUint8 m_ucDimensionB;
hkUint8 m_ucFeatureTypeA:4;
hkUint8 m_ucFeatureTypeB:4;
public:
void init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const hkTransform&btoa);};

void hkpConvexShape::GetVerticesForIds(const hkpVertexId*ids,int numIds,Vector4WithInt24W*vertixArrayOut)const
{
this->GetVerticesFromIds(ids,numIds,vertixArrayOut);
}
class SegmentSegmentClosestPoint
{
public:
enum
{
CLSLS_POINTA_START=1,
CLSLS_POINTA_END=2,
CLSLS_POINTB_START=4,
CLSLS_POINTB_END=8
};
struct VectorPairResult
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(SegmentSegmentClosestPoint::VectorPairResult));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_kFirstVector;
hkVector4 m_kClosestPointOnSecond;
hkPadSpu<hkReal>m_fValue;
};};
const ConvexContactManifold::VertexId*ConvexContactManifold::getVertexIds()const
{
return reinterpret_cast<const VertexId*>(reinterpret_cast<const char*>(&m_akContactPoints)+m_usNumContactPoints*sizeof(AlignedPairData));
}

namespace MotionUtilities
{
void __cdecl ComputeTransformAtTime(const hkSweptTransform&sweptTrans,hkTime time,hkTransform&transformOut);
__forceinline void __cdecl calcTimInfo(const hkMotionState&ms0,const hkMotionState&ms1,hkReal deltaTime,hkVector4&timOut);}
void __cdecl MotionUtilities::calcTimInfo(const hkMotionState&ms0,const hkMotionState&ms1,hkReal deltaTime,hkVector4&timOut)
{
const hkSweptTransform&st0=ms0.getSweptTransform();
const hkSweptTransform&st1=ms1.getSweptTransform();
hkQuadReal diff0 = _mm_sub_ps(st0.m_vCenterOfMass0.m_vComponents, st0.m_vCenterOfMass1.m_vComponents);
hkQuadReal diff1 = _mm_sub_ps(st1.m_vCenterOfMass1.m_vComponents, st1.m_vCenterOfMass0.m_vComponents);
hkReal f0=deltaTime*st0.getInvDeltaTime();
hkReal f1=deltaTime*st1.getInvDeltaTime();
timOut.m_vComponents = _mm_mul_ps(hkSimdReal(f0).broadcast(), diff0);
timOut.m_vComponents = _mm_add_ps(timOut.m_vComponents, _mm_mul_ps(hkSimdReal(f1).broadcast(), diff1));
timOut(3)=f0*ms0.m_kDeltaAngle(3)*ms0.m_fObjectRadius+f1*ms1.m_kDeltaAngle(3)*ms1.m_fObjectRadius;}
namespace hkVector4Util_S
{
__forceinline void __cdecl TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut);}
inline void __cdecl hkVector4Util_S::TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut)
{
hkTransform unaliased=t;
int i=numVectors-1;
do
{
vectorsOut[i]._setTransformedPos(unaliased,vectorsIn[i]);
}while(--i>=0);}
class hkTraceStream:public hkReferencedObject,public hkSingleton<hkTraceStream>
{
public:
static const struct ClassMemberDescriptor Members[];
void dontPrintf(const char*title,const char*fmt,...);
public:
hkTraceStream(){m_stream=0;m_iFirstInteger=0;}
public:
hkOstream*m_stream;
int m_iFirstInteger;};
class ConvexShapePairCache
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
ConvexShapePairCache():m_uiCacheFlags(0){}
__forceinline void init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const ConvexFeaturePairCache&cache);
__forceinline void checkForChangesAndUpdateCache(ConvexFeaturePairCache&cache)const;
void WriteContactFeatureCache(ConvexFeaturePairCache&cache)const;
protected:
__forceinline void setFeatureChange(int f){m_iFeatureChange=f;}
public:
hkPadSpu<int>m_ucDimensionA;
hkPadSpu<int>m_ucDimensionB;
hkPadSpu<int>m_ucFeatureTypeA;
hkPadSpu<int>m_ucFeatureTypeB;
hkPadSpu<hkUint32>m_uiCacheFlags;
hkPadSpu<int>m_iFeatureChange;
Vector4WithInt24W m_akPackedVerticesA[4];
hkVector4 unk60;
hkVector4 unk70;
hkVector4 unk80;
hkVector4 unk90;
hkVector4 m_akCachedVectors[4];
Vector4WithInt24W m_akPackedVerticesB[4];
hkVector4 m_pSupport;
SegmentSegmentClosestPoint::VectorPairResult m_kVectorPairResult;
hkVector4 m_pCachedPoint;
hkPadSpu<int>m_iCacheState;};
__forceinline void ConvexShapePairCache::init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const ConvexFeaturePairCache&cache)
{
m_ucDimensionA=cache.m_ucDimensionA;
m_ucDimensionB=cache.m_ucDimensionB;
m_ucFeatureTypeA=cache.m_ucFeatureTypeA;
m_ucFeatureTypeB=cache.m_ucFeatureTypeB;
setFeatureChange(0);
shapeA->GetVerticesForIds(&cache.m_kVertices[0],m_ucDimensionA,&m_akPackedVerticesA[0]);
shapeB->GetVerticesForIds(&cache.m_kVertices[m_ucDimensionA],m_ucDimensionB,&m_akPackedVerticesB[0]);}
__forceinline void ConvexShapePairCache::checkForChangesAndUpdateCache(ConvexFeaturePairCache&cache)const
{
if(!m_iFeatureChange)
{
return;
}
WriteContactFeatureCache(cache);
}
struct MeshVertexBasisData
{
Vector4WithInt24W m_kVertices[ConvexContactManifold::MAX_VERTICES];
hkVector4 m_kFirstBasisVector;
hkPadSpu<hkReal>m_kBoxBasisVector;
hkPadSpu<hkReal>m_kThirdBasisVector;
hkPadSpu<hkReal>m_fMinimumCollisionSeparation;
hkPadSpu<hkReal>m_fMaximumSeparation;};
extern "C"
{
void __cdecl RemoveManifoldContacts(ConvexContactManifold&manifold,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner);
int __cdecl BuildManifoldOperation(ConvexContactManifold&manifold,const MeshVertexBasisData&work,int firstPointIndex,WorldOperationEntry&out,hkpContactMgr*contactMgr);
void __cdecl BuildContactPointOperation(const AgentSubtypeMarker&in3,const hkReal allowedPenetration,const hkReal minSeparation,const hkReal toiSeparation,ConvexFeaturePairCache&gskCache,hkVector4&separatingNormal,WorldOperationEntry&output);
__forceinline void __cdecl hkGskManifold_init(const ConvexContactManifold&manifold,const hkVector4&masterNormal,const hkpCdBody&cA,const hkpCdBody&m_ucPackageByte,hkReal keepContactMaxDist,MeshVertexBasisData&work)
{
work.m_fMinimumCollisionSeparation=keepContactMaxDist;
const hkpConvexShape*shapeA=static_cast<const hkpConvexShape*>(cA.getShape());
const hkpConvexShape*shapeB=static_cast<const hkpConvexShape*>(m_ucPackageByte.getShape());
work.m_kBoxBasisVector=shapeA->getRadius();
work.m_kThirdBasisVector=shapeB->getRadius();
hkReal maxDist=work.m_fMinimumCollisionSeparation+work.m_kBoxBasisVector+work.m_kThirdBasisVector;
work.m_fMaximumSeparation=maxDist*maxDist;
work.m_kFirstBasisVector=masterNormal;
if(!manifold.m_usNumContactPoints)
{
return;
}
const ConvexContactManifold::VertexId*vertexIds=manifold.getVertexIds();
shapeA->GetVerticesForIds(vertexIds,manifold.m_ucNumVerticesA,&work.m_kVertices[0]);
hkVector4Util_S::TransformPointArray(cA.getTransform(),&work.m_kVertices[0],manifold.m_ucNumVerticesA,&work.m_kVertices[0]);
int b=manifold.m_ucNumVerticesA;
Vector4WithInt24W*verts=&work.m_kVertices[b];
shapeB->GetVerticesForIds(vertexIds+b,manifold.m_ucNumVerticesB,verts);
hkVector4Util_S::TransformPointArray(m_ucPackageByte.getTransform(),verts,manifold.m_ucNumVerticesB,verts);
}
}
// @fnv 0x00d42020
void hkpPredGskfAgent::ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&output)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "Gsk";h->setTime();mStream.setEnd((char*)(h+1));}};ScopedTimer timeblock155;
char names[2][128];
{
if(m_fFloatValue !=input.m_pStepInfo.m_uiStartTime)
{
if(!input.m_pCollisionQualityInfo->m_iQualityInfoValue10.val())
{
m_fFloatValue=input.m_pStepInfo.m_fEndTime;
goto PROCESS_AT_T1;
}
hkTransform tA;
hkTransform tB;
hkpCdBody bA(&bodyA,&tA);bA.SetCollisionShapeAndKey(bodyA.getShape(),bodyA.getShapeKey());
hkpCdBody bB(&bodyB,&tB);bB.SetCollisionShapeAndKey(bodyB.getShape(),bodyB.getShapeKey());
MotionUtilities::ComputeTransformAtTime(bodyA.GetMotionState()->getSweptTransform(),input.m_pStepInfo.m_uiStartTime,tA);
MotionUtilities::ComputeTransformAtTime(bodyB.GetMotionState()->getSweptTransform(),input.m_pStepInfo.m_uiStartTime,tB);
const hkpConvexShape*shapeA=static_cast<const hkpConvexShape*>(bodyA.getShape());
const hkpConvexShape*shapeB=static_cast<const hkpConvexShape*>(bodyB.getShape());
ConvexShapePairCache gsk;
gsk.init(shapeA,shapeB,*reinterpret_cast<ConvexFeaturePairCache*>(m_pAccess));
ComputeClosestPoint(bA,bB,input.m_pCollisionQualityInfo->m_fMinimumCollisionSeparation,gsk,m_vSeparatingNormal);
gsk.checkForChangesAndUpdateCache(*reinterpret_cast<ConvexFeaturePairCache*>(m_pAccess));
}
m_fFloatValue=input.m_pStepInfo.m_fEndTime;
const hkMotionState*msA=bodyA.GetMotionState();
const hkMotionState*msB=bodyB.GetMotionState();
hkVector4 timInfo;
MotionUtilities::calcTimInfo(*msA,*msB,input.m_pStepInfo.m_fTimeStep,timInfo);
hkReal realProjectedLinearDelta=timInfo.dot3(m_vSeparatingNormal);
hkReal distAtT1=m_vSeparatingNormal(3)-realProjectedLinearDelta-timInfo(3);
if(distAtT1>input.m_pCollisionQualityInfo->m_fMinimumCollisionSeparation&&m_fSeparationDistance*0.5<distAtT1)
{
if(0)hkTraceStream::GetMonitorStream().dontPrintf("Tim","# Tim %-6s %-6s dist:%2.4f \n",names[0],names[1],distAtT1);
m_vSeparatingNormal(3)=distAtT1;
if(m_kContactManifold.m_usNumContactPoints)
{
RemoveManifoldContacts(m_kContactManifold,m_pContactManager,*output.m_pConstraintOwner.val());
}
goto END_OF_FUNCTION;
}
if(input.m_pCollisionQualityInfo->m_iQualityInfoValue10.val())
{
AgentSubtypeMarker in3;
in3.m_pBodyA=&bodyA;
in3.m_pBodyB=&bodyB;
in3.m_pRayCastInput=reinterpret_cast<const hkpProcessCollisionInput*>(&input);
in3.m_pContactManager=m_pContactManager;
in3.m_fSubtypeValue=distAtT1;
in3.m_vSubtypePosition=timInfo;
hkpCollisionQualityInfo*qi=input.m_pCollisionQualityInfo;
const hkReal distance=m_vSeparatingNormal(3);
const hkReal minSeparation=MathUtilities::min2(qi->m_fCreateContactThreshold*m_fSeparationDistance,distance+qi->m_fManifoldTimeDistance*m_fSeparationDistance);
if(distAtT1>=minSeparation)
{
goto QUICK_VERIFY_MANIFOLD;
}
const hkReal toiSeparation=MathUtilities::min2(qi->m_fMinimumTimeOfImpactDelta*m_fSeparationDistance,distance+qi->m_fMaximumTimeOfImpactDelta*m_fSeparationDistance);
BuildContactPointOperation(in3,m_fSeparationDistance,minSeparation,toiSeparation,*reinterpret_cast<ConvexFeaturePairCache*>(m_pAccess),m_vSeparatingNormal,output);
goto PROCESS_AT_T1;
}
QUICK_VERIFY_MANIFOLD:
if(distAtT1>input.m_pCollisionQualityInfo->m_fTimeOfImpactSeparation)
{
if(0)hkTraceStream::GetMonitorStream().dontPrintf("Pts","# Pts %-6s %-6s dist:%2.4f \n",names[0],names[1],distAtT1);
m_vSeparatingNormal(3)=distAtT1;
MeshVertexBasisData work;
hkGskManifold_init(m_kContactManifold,m_vSeparatingNormal,bodyA,bodyB,input.getTolerance(),work);
BuildManifoldOperation(m_kContactManifold,work,0,output,m_pContactManager);
goto END_OF_FUNCTION;
}
}
PROCESS_AT_T1:
ProcessGskCollision(bodyA,bodyB,input,output);
END_OF_FUNCTION:;
}
