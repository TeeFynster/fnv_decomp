#include "../../include/hkArray.h"
// src/staging/blk_00d20000_od_o2_nood_variant_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d20000_od_o2_nood_variant_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/staging/blk_00d20000_od_o2_nood_variant_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/staging/blk_00d20000_od_o2_nood_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d20000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00d20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00d20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkAabb.h"
#include "../../include/hkMatrix3.h"
#include "../../include/hkRotation.h"
#include "../../include/hkSphere.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/FinishingFlag.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkStackMemory.h"
#include "../../include/hkSimdReal.h"
#include "../../include/hkBool.h"
#include "../../include/hkContactPoint.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkTransform.h"
#include "../../include/hkThreadLocalData.h"
#include "../../include/hkpCdBody.h"
#include "../../include/hkpCdPointCollector.h"
#include "../../include/hkpCollisionDispatcher.h"
#include "../../include/hkpConvexShape.h"
#include "../../include/hkpShape.h"
#include "../../include/hkpSphereRepShape.h"
#include "../../include/hkpSphereShape.h"
#include "../../include/hkpTriangleShape.h"
#include "../../include/hkBaseObject.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkpCollisionAgent.h"
#include "../../include/hkpIterativeLinearCastAgent.h"
struct ContactBody
{
    char unk00[0xa];
    unsigned char m_qualityA;
    unsigned char unk0b;
    unsigned char m_qualityC;
    char unk0d[0xb0 - 0xd];
    float m_uiCommandId;
    char unkb4[0xd0 - 0xb4];
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
    char unkf0[0xfc - 0xf0];
    float m_limitA;
    char unk100[0x10c - 0x100];
    float m_limitC;
};
bool Object_ProcessEntries_00d28560(void* unused, char** items, int count, int offset);
inline void* operator new(unsigned int, void* p) throw() { return p; }
inline void operator delete(void*, void*) throw() {}

static inline FinishingFlag NotFinishing()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    return flag;
}
class S00d2c8a0_Base
{
public:
    S00d2c8a0_Base(FinishingFlag flag);  // FUN_00d2c7e0
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
class S00d2c8a0_Derived : public S00d2c8a0_Base
{
public:
    S00d2c8a0_Derived(FinishingFlag flag) : S00d2c8a0_Base(flag) {}
    virtual void vf04();
    __m128 m_kScaleFactors;
};
const void* __cdecl Object_GetConstructedVirtualTable();
struct SortPair {
    unsigned int key;
    unsigned int val;
};
// @fnv 0x00d36520
// src: GUESS 0x00d36520 (confidence: low)
extern "C" void Object_ProcessEntries_00d36520(SortPair* arr, int lo, int hi, unsigned int extra)
{
    int i;
    int j;
    __declspec(align(16)) SortPair pivot;
    __declspec(align(16)) SortPair tmp;

    for (;;) {
        i = lo;
        j = hi;
        pivot = arr[(lo + hi) >> 1];
        do {
            while (arr[i].key < pivot.key || (arr[i].key == pivot.key && arr[i].val < pivot.val)) {
                ++i;
            }
            while (pivot.key < arr[j].key || (pivot.key == arr[j].key && pivot.val < arr[j].val)) {
                --j;
            }
            if (j < i) {
                break;
            }
            if (j != i) {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
            --j;
            ++i;
        } while (i <= j);
        if (lo < j) {
            Object_ProcessEntries_00d36520(arr, lo, j, extra);
        }
        if (i >= hi) {
            break;
        }
        lo = i;
    }
}

void InitOutputDefaults();
void Runtime_ReleaseHandles_Thunk();
void ReleaseHandles();
void RemoveKeyFromTable();
void InsertIntoSlotArray();
void nullsub_15();
void hkCollideCapsuleUtilCapsVsTri_ProcessEntries_00d39150();
void hkCapsuleTriangleAgent3_process();

typedef float hkReal;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned __w64 hk_size_t;class hkClass;
typedef int hkBool32;

class hkStatisticsCollector;
typedef __m128 hkQuadReal;
struct hkVec4X;
typedef const hkVec4X&hkVector4Parameter;

typedef const hkSimdReal&hkSimdRealParameter;class Vector4Comparison;
typedef const Vector4Comparison&hkVector4ComparisonParameter;
struct hkVec4X
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVec4X&v);
__forceinline void setAddMul4(const hkVec4X&a,const hkVec4X&b,hkSimdRealParameter r);
__forceinline void _setTransformedPos(const hkTransform&a,const hkVec4X&b);
__forceinline hkReal&operator()(int i);
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};inline void hkVec4X::operator=(const hkVec4X&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVec4X::setAddMul4(const hkVec4X&a,const hkVec4X&b,hkSimdRealParameter r)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(r.broadcast(),b.m_vComponents));
}
inline void hkVec4X::_setTransformedPos(const hkTransform&t,const hkVec4X&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.m_row3));}
inline hkReal&hkVec4X::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline hkVector4&hkMatrix3::getColumn(int x)
{
return(&m_kColumn0)[x];
}
inline const hkVector4&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
__forceinline const hkVector4& hkRotation::getColumn(int x) const
{
return (&m_kColumn0)[x];
}
__forceinline const hkVector4& hkTransform::getTranslation() const
{
return *reinterpret_cast<const hkVector4*>(&m_row3);
}
__forceinline const hkRotation& hkTransform::getRotation() const
{
return *reinterpret_cast<const hkRotation*>(&m_row0);
}
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    // Keep the vector copy semantics used by the original scalar loads.
    const hkVec4X r0 = reinterpret_cast<const hkVec4X&>(t.m_row0);
    const hkVec4X r1 = reinterpret_cast<const hkVec4X&>(t.m_row1);
    const hkVec4X r2 = reinterpret_cast<const hkVec4X&>(t.m_row2);
    const hkVec4X r3 = reinterpret_cast<const hkVec4X&>(t.m_row3);
    reinterpret_cast<hkVec4X&>(m_row0) = r0;
    reinterpret_cast<hkVec4X&>(m_row1) = r1;
    reinterpret_cast<hkVec4X&>(m_row2) = r2;
    reinterpret_cast<hkVec4X&>(m_row3) = r3;
}
// The shared hkBool declaration is opaque; retain its one-byte game representation.
__forceinline hkMonitorStream& hkMonitorStream::getInstance()
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
__forceinline hkSimdReal::hkSimdReal() {}
__forceinline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
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
__forceinline ~ScopedTimer(){{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){::hkMonitorStream::TimerCommand*h=reinterpret_cast<::hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};}
};typedef hkUint16 hkContactPointId;
inline hkVector4&hkContactPoint::getPosition()
{
return m_vContactPosition;
}
inline hkVector4&hkContactPoint::getSeparatingNormal()
{
return m_vSeparatingNormal;
}
inline void hkContactPoint::setSeparatingNormal(const hkVector4&normal,hkReal dist)
{
reinterpret_cast<hkVec4X&>(m_vSeparatingNormal)=reinterpret_cast<const hkVec4X&>(normal);
reinterpret_cast<hkVec4X&>(m_vSeparatingNormal)(3)=dist;
}
class Vector4WithInt24W:public hkVec4X
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
class hkpContactMgr;
struct WorldOperationEntry;
class hkpConstraintOwner;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
hkPadSpu<hkpCollisionDispatcher*>m_pCollisionDispatcher;
hkPadSpu<hkBool32>m_collisionQuality;
hkPadSpu<hkReal>m_fScalar;};
class hkpContactMgrFactory;
class hkpCdBodyPairCollector;
struct ShapeSweepParameters;

struct ContactPointPair
{
ContactPointPair(const hkpCdBody&a,const hkpCdBody&b):m_pBodyA(a),m_pBodyB(b){}
hkContactPoint m_kPoint;
const hkpCdBody&m_pBodyA;
const hkpCdBody&m_pBodyB;};

namespace hkVector4Util_S
{
__forceinline void __cdecl TransformPointArray(const hkTransform&t,const hkVec4X*vectorsIn,int numVectors,hkVec4X*vectorsOut);}
inline void __cdecl hkVector4Util_S::TransformPointArray(const hkTransform&t,const hkVec4X*vectorsIn,int numVectors,hkVec4X*vectorsOut)
{
hkTransform unaliased=t;
int i=numVectors-1;
do
{
vectorsOut[i]._setTransformedPos(unaliased,vectorsIn[i]);
}while(--i>=0);}
struct MaterialIndexedTriangle
{
hkUint8 m_uiMaterialIndex;
hkpVertexId m_auiVertexIds[3];
};
class TriangleDistanceUtility
{
public:
static void __cdecl calcBarycentricCoordinates(hkVector4Parameter pos,hkVector4Parameter t0,hkVector4Parameter t1,hkVector4Parameter t2,hkPadSpu<hkReal>result[3]);
struct FourRealValueRecord
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(TriangleDistanceUtility::FourRealValueRecord));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkReal m_fFirstValue;
hkReal m_fSecondValue;
hkReal m_fThirdValue;
hkReal m_fFourthValue;
};
struct CollisionDistanceInfo
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(TriangleDistanceUtility::CollisionDistanceInfo));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVec4X m_kNearestPoint;
hkPadSpu<hkReal>distance;
void calcClosestPoint(hkVector4Parameter point,hkVec4X&closestPoint)
{
const float scalar = distance.val();
const __m128 quad = _mm_load_ss(&scalar);
hkSimdReal value;
value.m_vValue = quad;
closestPoint.setAddMul4(point,m_kNearestPoint,value);
}
};
static void __cdecl setupClosestPointTriangleCache(const hkVec4X*triangle,FourRealValueRecord&cache);
enum ClosestPointTriangleStatus
{
HIT_TRIANGLE_FACE=0,
HIT_TRIANGLE_EDGE
};
static ClosestPointTriangleStatus __cdecl GetClosestPointOnTriangle(hkVector4Parameter position,const hkVec4X*tri,const FourRealValueRecord&cache,CollisionDistanceInfo&result,MaterialIndexedTriangle*featureOutput=0);protected:
TriangleDistanceUtility();};
class hkpSphereTriangleAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl InitAgentFunc(hkpCollisionDispatcher::CollisionAgentFunctionTable&f);
static void __cdecl initAgentFuncInverse(hkpCollisionDispatcher::CollisionAgentFunctionTable&f);
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
static void __cdecl registerAgent2(hkpCollisionDispatcher*dispatcher);
virtual inline void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&pointDetails);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction2(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector);
virtual void cleanup(hkpConstraintOwner&info);
protected:
__forceinline hkpSphereTriangleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl CreateSphereTriangleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createTriangleSphereAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
public:
enum ClosestPointResult
{
ST_CP_MISS,
ST_CP_FACE,
ST_CP_EDGE
};
static ClosestPointResult __cdecl ComputeClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::FourRealValueRecord&m_pAccessManager,hkContactPoint&cpoint);
static __forceinline ClosestPointResult getClosestPointInl(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::FourRealValueRecord&m_pAccessManager,hkContactPoint&cpoint,MaterialIndexedTriangle*featureOutput=0);
hkContactPointId m_usContactPointId;
TriangleDistanceUtility::FourRealValueRecord m_kTriangleAccessData;
};

__forceinline const hkVector4_S* hkpTriangleShape::GetIndexedVertices() const
{
return reinterpret_cast<const hkVector4_S*>(&m_kVertexA);
}

hkpSphereTriangleAgent::ClosestPointResult __cdecl hkpSphereTriangleAgent::getClosestPointInl(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::FourRealValueRecord&cache,hkContactPoint&cpoint,MaterialIndexedTriangle*featureOutput)
{
const hkpSphereShape*sphereA=static_cast<const hkpSphereShape*>(bodyA.getShape());
const hkpTriangleShape*triB=static_cast<const hkpTriangleShape*>(bodyB.getShape());
const hkVec4X&posA=reinterpret_cast<const hkVec4X&>(bodyA.getTransform().getTranslation());
hkVec4X triVertices[3];
hkVector4Util_S::TransformPointArray(bodyB.getTransform(),reinterpret_cast<const hkVec4X*>(triB->GetIndexedVertices()),3,triVertices);
TriangleDistanceUtility::CollisionDistanceInfo cptr;
TriangleDistanceUtility::ClosestPointTriangleStatus res=TriangleDistanceUtility::GetClosestPointOnTriangle(posA,triVertices,cache,cptr,featureOutput);
const hkReal radiusSum=sphereA->getRadius()+triB->m_fSphereRadius;
if(cptr.distance<radiusSum+input.getTolerance())
{
const float scalar = triB->m_fSphereRadius-cptr.distance;
hkSimdReal value;
value.m_vValue = _mm_load_ss(&scalar);
reinterpret_cast<hkVec4X&>(cpoint.getPosition()).setAddMul4(posA,cptr.m_kNearestPoint,value);
cpoint.setSeparatingNormal(reinterpret_cast<const hkVector4&>(cptr.m_kNearestPoint),cptr.distance-radiusSum);
if(res==TriangleDistanceUtility::HIT_TRIANGLE_FACE)
{
return ST_CP_FACE;
}
else
{
return ST_CP_EDGE;
}
}
return ST_CP_MISS;}
// @fnv 0x00d3d8c0
// src: GUESS 0x00d3d8c0 (confidence: low)
void __cdecl hkpCdBody_ProcessAndReturnValue_00d3d8c0(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){::hkMonitorStream::TimerCommand*h=reinterpret_cast<::hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "SphereTri";h->setTime();mStream.setEnd((char*)(h+1));}};ScopedTimer timeblock47;
const hkpTriangleShape*triB=static_cast<const hkpTriangleShape*>(bodyB.getShape());
TriangleDistanceUtility::FourRealValueRecord cache;
TriangleDistanceUtility::setupClosestPointTriangleCache(reinterpret_cast<const hkVec4X*>(triB->GetIndexedVertices()),cache);
ContactPointPair event(bodyA,bodyB);
MaterialIndexedTriangle featureOutput;
if(hkpSphereTriangleAgent::getClosestPointInl(bodyA,bodyB,input,cache,event.m_kPoint,&featureOutput))
{
hkUchar m_uiMaterialIndex=featureOutput.m_uiMaterialIndex;
if(input.m_collisionQuality.val()&&m_uiMaterialIndex>0)
{
const hkpSphereShape*sphereA=static_cast<const hkpSphereShape*>(bodyA.getShape());
hkVec4X weldedNormal=reinterpret_cast<const hkVec4X&>(event.m_kPoint.getSeparatingNormal());
hkVec4X pointPos=reinterpret_cast<const hkVec4X&>(event.m_kPoint.getPosition());
hkpConvexShape::WeldResult weldResult=static_cast<hkpConvexShape::WeldResult>(triB->WeldContactPoint(&featureOutput.m_auiVertexIds[0],m_uiMaterialIndex,reinterpret_cast<hkVector4&>(pointPos),&bodyB.getTransform(),sphereA,&bodyA.getTransform(),reinterpret_cast<hkVector4&>(weldedNormal)));
if(weldResult==hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT)
{
return;
}
else if(weldResult==hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED)
{
event.m_kPoint.setNormal(reinterpret_cast<const hkVector4&>(weldedNormal));
}
}
collector.AddCdPoint(event);
}
}


namespace fnv_00d37d30 {


inline hkMemoryAllocator& HeapD37D30(hkMemoryRouter& holder)
{
    return *reinterpret_cast<hkMemoryAllocator*>(holder.m_heap);
}
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();



template <class T>
static __forceinline void D37D30Array_destroy(hkArrayBase<T>& self) throw();

template <class T>
static __forceinline void D37D30Array_destroy(hkArrayBase<T>& self) throw()
{
        hkMemoryAllocator& alloc = HeapD37D30(hkMemoryRouter_getInstance());
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & hkArrayBase<T>::DONT_DEALLOCATE_FLAG) == 0)
            alloc.bufFree(self.m_data, (self.m_iCapacityState & hkArrayBase<T>::CAPACITY_MASK) * sizeof(T));
        self.m_data = 0;
        self.m_iCapacityState = hkArrayBase<T>::DONT_DEALLOCATE_FLAG;
    }

struct D37D30ArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { D37D30Array_destroy(self); }
};

class FUN_00d37d30 : public hkReferencedObject {
public:
    int unk08;
    hkArray<unsigned short, D37D30ArrayPolicy> m_ppIndices;

    FUN_00d37d30();

    static void operator delete(void* p) {
        HeapD37D30(hkMemoryRouter_getInstance()).blockFree(p, static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags);
    }
};

// @fnv 0x00d37d30
FUN_00d37d30::FUN_00d37d30() {
}
}  // namespace fnv_00d37d30


template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    __if_exists(A::destroy) { A::destroy(*this); }
    __if_not_exists(A::destroy) { clearAndDeallocate(); }
}
