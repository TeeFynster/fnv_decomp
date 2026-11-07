#define FNV64_HKAABBUINT32_OUTLINE_ASSIGN
#include "../../../../../../include/hkAabbUint32.h"
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkMotionState.h"
#include "../../../../../../include/hkSweptTransform.h"
#include "../../../../../../include/hkpCollidable.h"
#include "../../../../../../include/hkStackMemory.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkQuaternion.h"
#include "../../../../../../include/AgentSectorPointerArray.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/FinishingFlag.h"
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkpBroadPhaseHandle.h"
#include "../../../../../../include/hkpCdBody.h"
#include "../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../include/hkpShape.h"
#include "../../../../../../include/hkpShapeCollection.h"
#include "../../../../../../include/hkpListShape.h"
#include "../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../include/hkpTypedBroadPhaseHandle.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkStepInfo.h"
#include "../../../../../../include/hkThreadLocalData.h"
#include <xmmintrin.h>
#include <string.h>
// src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHs-c- /Gy (unit lists /MT /O2 /GS- /EHs-c- /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv_asm_helpers.h"
typedef float hkReal;
typedef signed char hkInt8;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32_S;
typedef unsigned long __w64 hkUlong;
typedef signed long __w64 hkLong;
typedef hkReal hkTime;__forceinline hkLong __cdecl hkGetByteOffset(const void*base,const void*pntr)
{
return hkLong(pntr)-hkLong(base);
}
template<typename TYPE>
__forceinline TYPE*__cdecl hkAddByteOffset(TYPE*base,hkLong offset)
{
return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base)+offset);
}

class hkClass;
typedef int hkBool32;
template<typename T>struct TypeSizeConstant{enum{val=sizeof(T)};};
__forceinline int hkStackMemory::getFreeStackSize()
{
return int(hkGetByteOffset(m_next,m_end));
}
__forceinline void*hkStackMemory::allocateStack(int numBytes,const char*what)
{
;
if(numBytes>getFreeStackSize())
{
;
}
void*current=m_next;
m_next=hkAddByteOffset(current,numBytes);
return current;
}
void hkStackMemory::deallocateStack(void*p)
{
;
m_next=p;
}
void hkStackMemory::shrinkAllocatedStack(void*p,int newSize)
{
m_next=hkAddByteOffset(p,newSize);
}

template<typename TYPE>
__forceinline TYPE*__cdecl hkAllocateStack(int n,const char*what=0)
{
hkMemoryRouter&mem=hkMemoryRouter::getInstance();
return static_cast<TYPE*>(mem.stack().allocateStack((((n*TypeSizeConstant<TYPE>::val)+((128)-1))&(~((128)-1))),what));
}
template<typename TYPE>
__forceinline void __cdecl hkShrinkAllocatedStack(TYPE*ptr,int n)
{
hkMemoryRouter&mem=hkMemoryRouter::getInstance();
mem.stack().shrinkAllocatedStack(ptr,(((n*TypeSizeConstant<TYPE>::val)+((128)-1))&(~((128)-1))));
}
template<typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE*ptr)
{
hkMemoryRouter::getInstance().stack().deallocateStack(static_cast<void*>(ptr));
}

class hkStatisticsCollector;
#include "../../../../../../include/hkArray.h"

typedef union ::__m128 hkQuadReal;
namespace D35770Sse {
using ::_mm_add_ss;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_mul_ps;
using ::_mm_sqrt_ss;
using ::_mm_min_ps;
using ::_mm_max_ps;
using ::_mm_shuffle_ps;
extern "C" {
hkQuadReal _mm_xor_ps(hkQuadReal,hkQuadReal);
hkQuadReal _mm_load_ss(const float*);
}
}

inline hkSimdReal::hkSimdReal(const hkQuadReal&x):m_vValue(x){}
inline hkSimdReal::hkSimdReal(hkReal x){m_vValue=D35770Sse::_mm_load_ss(&x);}
__forceinline hkQuadReal hkSimdReal::broadcast()const{return D35770Sse::_mm_shuffle_ps(m_vValue,m_vValue,0);}
__forceinline const hkQuadReal&hkSimdReal::getQuad()const{return m_vValue;}
typedef const hkSimdReal&hkSimdRealParameter;
namespace MathUtilities
{inline int __cdecl hkToIntFast(hkReal r){
int i;
i = fnv_FloatToInt(r);return i;
}
}
namespace MathUtilities
{template<typename T>
inline T __cdecl max2(T x,T y)
{
return x>y ? x:y;
}
}

__forceinline void*__cdecl hkRotation::operator new(size_t nbytes){;void*obj=(*hkMemoryRouter::getInstance().m_heap).blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline const hkVector4&hkRotation::getColumn(int x)const
{
return reinterpret_cast<const hkMatrix3&>(*this).getColumn(x);
}


// Preserve the original empty construction and bitwise vector copies in this unit.
__forceinline hkVector4::hkVector4(const hkVector4& vector) { memcpy(this,&vector,sizeof(*this)); }
__forceinline void hkVector4::operator=(const hkVector4& vector) { memcpy(this,&vector,sizeof(*this)); }
__forceinline hkAabb::hkAabb() {}

inline hkQuadReal&hkVector4::getQuad()
{
return m_vComponents;
}
inline const hkQuadReal&hkVector4::getQuad()const
{
return m_vComponents;
}
inline void hkVector4::SetAllComponents(hkSimdRealParameter a)
{
m_vComponents=D35770Sse::_mm_shuffle_ps(a.getQuad(),a.getQuad(),(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
inline void hkVector4::add4(const hkVector4&v)
{
m_vComponents=D35770Sse::_mm_add_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4::setAdd4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=D35770Sse::_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=D35770Sse::_mm_sub_ps(v0.getQuad(),v1.getQuad());
}
inline void hkVector4::mul4(const hkVector4&v)
{
m_vComponents=D35770Sse::_mm_mul_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4::setNeg3(const hkVector4&v)
{
static __declspec(align(16))const hkUint32_S negateMask[4]={0x80000000,0x80000000,0x80000000,0x00000000};
m_vComponents=D35770Sse::_mm_xor_ps(v.m_vComponents,*(const hkQuadReal*)&negateMask);
}
inline void hkVector4::mul4(hkSimdRealParameter s)
{
m_vComponents=D35770Sse::_mm_mul_ps(s.broadcast(),m_vComponents);
}
inline void hkVector4::addMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=D35770Sse::_mm_add_ps(m_vComponents,
D35770Sse::_mm_mul_ps(r.broadcast(),v1.m_vComponents));
}
inline void hkVector4::setInterpolate4(const hkVector4&v0,const hkVector4&v1,hkSimdRealParameter _t)
{
static __declspec(align(16))const float cw[4]={1.0f,1.0f,1.0f,1.0f};
hkQuadReal t=_t.broadcast();
hkQuadReal s=D35770Sse::_mm_sub_ps(*(const hkQuadReal*)&cw,t);
m_vComponents=D35770Sse::_mm_add_ps(
D35770Sse::_mm_mul_ps(s,v0.m_vComponents),
D35770Sse::_mm_mul_ps(t,v1.m_vComponents));}
inline void hkVector4::setMin4(const hkVector4&a,const hkVector4&b)
{
m_vComponents=D35770Sse::_mm_min_ps(a.getQuad(),b.getQuad());
}
inline void hkVector4::setMax4(const hkVector4&a,const hkVector4&b)
{
m_vComponents=D35770Sse::_mm_max_ps(a.getQuad(),b.getQuad());
}
inline void hkVector4::_setTransformedPos(const hkTransform&t,const hkVector4&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=D35770Sse::_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=D35770Sse::_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=D35770Sse::_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=D35770Sse::_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=D35770Sse::_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=D35770Sse::_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
m_vComponents=D35770Sse::_mm_add_ps(D35770Sse::_mm_add_ps(r0,r1),D35770Sse::_mm_add_ps(r2,t.getTranslation().m_vComponents));}
inline hkSimdReal hkVector4::dot3(const hkVector4&a)const
{
hkQuadReal x2=D35770Sse::_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=D35770Sse::_mm_add_ss(D35770Sse::_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return D35770Sse::_mm_add_ss(D35770Sse::_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline hkSimdReal hkVector4::length3()const
{
return D35770Sse::_mm_sqrt_ss(this->dot3(*this).getQuad());
}
inline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline hkSimdReal hkVector4::getSimdAt(int i)const
{
switch(i)
{
case 0:
return m_vComponents;
case 1:
return D35770Sse::_mm_shuffle_ps(m_vComponents,m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
case 2:
return D35770Sse::_mm_shuffle_ps(m_vComponents,m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
case 3:
default:
return D35770Sse::_mm_shuffle_ps(m_vComponents,m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3))));
}
}
inline const hkVector4&__cdecl hkVector4::getZero()
{
extern hkVector4 g_vZero;
return g_vZero;
}
inline const hkVector4&hkMatrix3::getColumn(int x)const
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
__forceinline hkRotation&hkTransform::getRotation(){return reinterpret_cast<hkRotation&>(m_row0);}
__forceinline hkTransform::hkTransform(){}
__forceinline hkTransform::hkTransform(const hkTransform&t)
{
const hkVector4 r0=t.getRotation().getColumn(0);
const hkVector4 r1=t.getRotation().getColumn(1);
reinterpret_cast<hkMatrix3&>(getRotation()).getColumn(0)=r0;
reinterpret_cast<hkMatrix3&>(getRotation()).getColumn(1)=r1;
}
class MemoryUtils
{
public:
enum ReplaceType
{
REPLACE_ONE,
REPLACE_ALL
};
template<int size>
static __forceinline void __cdecl memCpy16(void*dst,const void*src);
private:
static void copyAndReplace(char*dest,const char*orig,int origLen,const MemoryUtils&from,const MemoryUtils&to,const hkArray<int>&indices);};
__forceinline hkMonitorStream& hkMonitorStream::getInstance() {
extern hkThreadLocalData<hkMonitorStream*>g_pMonitorStream;
return *g_pMonitorStream.getData();
}
__forceinline char* __cdecl hkMonitorStream::getStart(){return m_start.val();}
__forceinline char* __cdecl hkMonitorStream::getEnd(){return m_end.val();}
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16(){return m_capacityMinus16.val();}
__forceinline hkBool __cdecl hkMonitorStream::memoryAvailable(){return getEnd()<getCapacityMinus16();}
__forceinline void __cdecl hkMonitorStream::setEnd(char*ptr){m_end=ptr;}

__forceinline void hkMonitorStream::TimerCommand::setTime()
{
hkUint32_S ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_time0=ticks;
}
inline const hkSweptTransform&hkMotionState::getSweptTransform()const
{
return m_kSweptTransform;
}

typedef hkUint16 hkContactPointId;

#include "../../../../../../include/hkpBufferSize.h"
struct __declspec(align(16)) hkpShapeBuffer { char m_data[HK_SHAPE_BUFFER_SIZE]; };

typedef hkUint32_S hkpShapeKey_S;
class ShapeKeyCombination
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=(*hkMemoryRouter::getInstance().m_heap).blockAlloc(static_cast<int>(nbytes));;return obj;}
hkpShapeKey_S m_uiShapeKeyA;
hkpShapeKey_S m_uiShapeKeyB;};
__declspec(align(16))class AlignedHkpShape:public hkpShape{
AlignedHkpShape();
};
hkpShapeType hkpShape::getType()const
{
return *reinterpret_cast<const hkpShapeType*>(&static_cast<const AlignedHkpShape*>(this)->m_type);
}
void hkpShape::getAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const
{
CalculateAabb(localToWorld,tolerance,out);
}

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
const hkpCollidable*hkpCdBody::getRootCollidable()const
{
const hkpCdBody*body=this;
while(body->m_parent)
{
body=body->m_parent;
}
return reinterpret_cast<const hkpCollidable*>(body);
}
const hkpCdBody*hkpCdBody::getParent()const
{
return m_parent;
}
struct GskAgentInput;
class hkpContactMgr;
struct WorldOperationEntry;

class hkpConstraintOwner;
struct CollisionAgentContext;
class hkpCollisionAgent;
struct FourByteState
{};
class hkpAgentData;
struct CollectionAgentInputLocalForm
{ // local form of hkpAgent3Input: 0x00d35770 needs aggregate copying; shared hkTransform emits an out-of-line hkpAgent3Input copy constructor absent from the exe call sequence.
hkPadSpu<const hkpCdBody*>m_pBodyA;
hkPadSpu<const hkpCdBody*>m_pBodyB;
hkPadSpu<const hkpCdBody*>m_pAdditionalCollidableBody;
hkPadSpu<const GskAgentInput*>m_pRayCastInput;
hkPadSpu<hkpContactMgr*>m_pContactManager;
hkTransform m_kTransform;};
struct AgentSubtypeMarker:public CollectionAgentInputLocalForm
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
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=(*hkMemoryRouter::getInstance().m_heap).blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;(*hkMemoryRouter::getInstance().m_heap).blockFree(p,sizeof(CollisionAgentContext::AabbBoundsAndScale));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_kAabbMin;
hkVector4 m_kAabbMaximum;
hkVector4 m_kAabbScale;
};
AabbBoundsAndScale m_aiValues;};
class hkpContactMgrFactory;
__forceinline hkBool32 hkpCollisionDispatcher::hasAlternateType(hkpShapeType type,hkpShapeType alternateType)
{
;
;
return(m_auiAlternateTypeFlags[type]&(1<<alternateType));
}

struct hkpAgent1nSector;
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable hkPadSpu<hkpCollisionQualityInfo*>m_pCollisionQualityInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;};
namespace hkpCollectionCollectionAgent3
{
hkpAgentData*__cdecl process_00d35770(const AgentSubtypeMarker&input,FourByteState*entry,hkpAgentData*agentData,hkVector4*separatingNormal,WorldOperationEntry&result);
void __cdecl RegisterAgentFunctions(hkpCollisionDispatcher*dispatcher);
void __cdecl InitAgentFunc(hkpCollisionDispatcher::Agent3FunctionTable&f);
void __cdecl CleanupAgent(FourByteState*entry,hkpAgentData*agentData,const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner);
void __cdecl AddStat(FourByteState*entry,hkpAgentData*agentData,const CollisionAgentContext&input,hkStatisticsCollector*collector);
void __cdecl RemovePoint(FourByteState*entry,hkpAgentData*agentData,const CollisionAgentContext&input);
void __cdecl WarpTime(FourByteState*entry,hkpAgentData*agentData,hkTime oldTime,hkTime newTime,const CollisionAgentContext&input);
extern bool g_bCollisionAgentFlag;
}

namespace hkBvTreeAgent3
{
hkpAgentData*__cdecl process_00d35770(const AgentSubtypeMarker&input,FourByteState*entry,hkpAgentData*agentData,hkVector4*separatingNormal,WorldOperationEntry&result);
void __cdecl RegisterAgentFunctions(hkpCollisionDispatcher*dispatcher);
void __cdecl InitAgentFunc(hkpCollisionDispatcher::Agent3FunctionTable&f);
void __cdecl CleanupAgent(FourByteState*entry,hkpAgentData*agentData,const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner);
void __cdecl AddStat(FourByteState*entry,hkpAgentData*agentData,const CollisionAgentContext&input,hkStatisticsCollector*collector);
void __cdecl RemovePoint(FourByteState*entry,hkpAgentData*agentData,const CollisionAgentContext&input);
void __cdecl WarpTime(FourByteState*entry,hkpAgentData*agentData,hkTime oldTime,hkTime newTime,const CollisionAgentContext&input);
int __cdecl BuildCollisionHitList(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkTransform&bTa,
const hkVector4&linearTimInfo,const GskAgentInput&input,
hkAabb*cachedAabb,hkpShapeKey_S*hitListOut,int hitListCapacity);
const hkpShapeContainer*__cdecl GetContainerFromBody(const hkpCdBody*body,hkpShapeBuffer&buffer);
const hkpShapeCollection*__cdecl GetCollectionFromBody(const hkpCdBody*body,hkpShapeBuffer&buffer);
}

extern "C"
{
void __cdecl BuildShapeCollectionBWorldOperations(AgentSectorPointerArray&agentTrack,const AgentSubtypeMarker&input,const hkpShapeContainer*shapeContainterB,const hkpShapeKey_S*hitList,WorldOperationEntry&output);
void __cdecl BuildShapePairWorldOperations(AgentSectorPointerArray&agentTrack,const AgentSubtypeMarker&input,const hkpShapeContainer*shapeContainerA,const hkpShapeContainer*shapeCollectionB,const ShapeKeyCombination*hitList,WorldOperationEntry&output);}

enum{HK_MAX_NUM_HITS_PER_AABB_QUERY=4096};struct ShapeKeyPair
{
hkUint32_S m_uiFirstShapeKey;
hkUint32_S m_uiSecondShapeKey;
};
class AabbCollisionPairGenerator
{
public:
struct KeyedAabb:public hkAabbUint32
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=(*hkMemoryRouter::getInstance().m_heap).blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;(*hkMemoryRouter::getInstance().m_heap).blockFree(p,sizeof(AabbCollisionPairGenerator::KeyedAabb));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32_S&GetIteratorKey()
{
hkUint32_S*minP=m_kMinimumCorner;
return minP[3];
}
const hkUint32_S&GetIteratorKey()const
{
const hkUint32_S*minP=m_kMinimumCorner;
return minP[3];
}
__forceinline bool operator<(const AabbCollisionPairGenerator::KeyedAabb&aabb1)const{return this->m_kMinimumCorner[0]<aabb1.m_kMinimumCorner[0];}
void operator=(const KeyedAabb&other){MemoryUtils::memCpy16<sizeof(KeyedAabb)>(this,&other);}
void setEndMarker()
{
m_kMinimumCorner[0]=hkUint32_S(-1);
}
void set(const hkAabb&aabb,int key);
static __forceinline hkUint32_S yzDisjoint(const AabbCollisionPairGenerator::KeyedAabb&aabb,const AabbCollisionPairGenerator::KeyedAabb&other)
{
hkUint32_S yab=aabb.m_kMaximumCorner[1]-other.m_kMinimumCorner[1];
hkUint32_S yba=other.m_kMaximumCorner[1]-aabb.m_kMinimumCorner[1];
hkUint32_S zab=aabb.m_kMaximumCorner[2]-other.m_kMinimumCorner[2];
hkUint32_S zba=other.m_kMaximumCorner[2]-aabb.m_kMinimumCorner[2];
hkUint32_S combined=(yab | yba)|(zab | zba);
return combined&0x80000000;
}
};
static int __cdecl collide(const KeyedAabb*pa,int numA,const KeyedAabb*pb,int numB,ShapeKeyPair*__restrict pairsOut,int maxNumPairs,hkPadSpu<int>&numPairsSkipped);};
class AabbUtil
{
public:
static void __cdecl ComputeAabb(const float*vertexArray,int numVertices,int striding,hkAabb&aabbOut);
public:
struct OffsetAabbSweepInput
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=(*hkMemoryRouter::getInstance().m_heap).blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;(*hkMemoryRouter::getInstance().m_heap).blockFree(p,sizeof(AabbUtil::OffsetAabbSweepInput));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkPadSpu<const hkMotionState*>m_kMotionState;
hkTransform m_kTransforms[4];
hkPadSpu<int>m_numQsTransforms;
hkTransform m_kFirstAdditionalTransform;
hkTransform m_kSecondAdditionalTransform;
};
static void __cdecl GetMotionStateTransforms(const hkMotionState*motionstate,OffsetAabbSweepInput&input);
static void __cdecl sweepOffsetAabb(const OffsetAabbSweepInput&input,const hkAabb&aabbIn,hkAabb&aabbOut);};__forceinline void __cdecl AabbUtil::sweepOffsetAabb(const AabbUtil::OffsetAabbSweepInput&input,const hkAabb&aabbIn,hkAabb&aabbOut)
{
hkSimdReal half(0.5f);
hkVector4 aabbHalfSize=aabbIn.m_kMaximumCorner;aabbHalfSize.setSub4(aabbHalfSize,aabbIn.m_kMinimumCorner);aabbHalfSize.mul4(half);
hkVector4 aabbCenter;aabbCenter.setInterpolate4(aabbIn.m_kMaximumCorner,aabbIn.m_kMinimumCorner,half);
hkVector4 arm;arm._setTransformedPos(input.m_kSecondAdditionalTransform,aabbCenter);
hkVector4 min=aabbCenter;
hkVector4 max=aabbCenter;
{
hkVector4 p;p._setTransformedPos(input.m_kFirstAdditionalTransform,arm);
min.setMin4(min,p);
max.setMax4(max,p);
}
const hkVector4 centerOfMassLocal=input.m_kMotionState->getSweptTransform().m_vCenterOfMassLocal;
for(int i=0;i<input.m_numQsTransforms;i++)
{
hkVector4 extendedArm;
extendedArm.setSub4(arm,centerOfMassLocal);
extendedArm.mul4(input.m_kTransforms[i].getTranslation().getSimdAt(3));
extendedArm.add4(centerOfMassLocal);
hkVector4 p;p._setTransformedPos(input.m_kTransforms[i],extendedArm);
min.setMin4(min,p);
max.setMax4(max,p);
}
{
hkSimdReal r=aabbHalfSize.length3();
hkVector4 radius;radius.SetAllComponents(r);
aabbHalfSize.addMul4(input.m_kMotionState->m_kDeltaAngle.getSimdAt(3),radius);
aabbHalfSize.setMin4(radius,aabbHalfSize);
}
aabbOut.m_kMinimumCorner.setSub4(min,aabbHalfSize);
aabbOut.m_kMaximumCorner.setAdd4(max,aabbHalfSize);
aabbOut.m_kMinimumCorner.setMin4(aabbIn.m_kMinimumCorner,aabbOut.m_kMinimumCorner);
aabbOut.m_kMaximumCorner.setMax4(aabbIn.m_kMaximumCorner,aabbOut.m_kMaximumCorner);}
inline int hkpListShape::GetNumChildShapes()const
{
return m_kChildInfoList.m_iElementCount-m_usNumDisabledChildren;
}
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
namespace hkVector4Util_S
{
__forceinline void __cdecl convertToUint32WithClip(const hkVector4&in,const hkVector4&offset,const hkVector4&scale,const hkVector4&min,const hkVector4&max,hkUint32_S*out);
__forceinline void __cdecl convertAabbToUint32(const hkAabb&aabb,const hkVector4&offsetLow,const hkVector4&offsetHigh,const hkVector4&scale,hkAabbUint32&aabbOut);
__forceinline void __cdecl uncompressExpandedAabbUint32(const hkAabbUint32&unexpandedAabbInt,hkAabbUint32&expandedAabbOut);
extern hkQuadReal g_vAabbExpansion;}
inline void __cdecl hkVector4Util_S::convertToUint32WithClip(const hkVector4&in,const hkVector4&offset,const hkVector4&scale,const hkVector4&min,const hkVector4&max,hkUint32_S*out)
{
hkVector4 x;
x.setAdd4(in,offset);
x.mul4(scale);
x.setMin4(x,max);
x.setMax4(x,min);
out[0]=static_cast<hkUint32_S>(MathUtilities::hkToIntFast(x(0)));
out[1]=static_cast<hkUint32_S>(MathUtilities::hkToIntFast(x(1)));
out[2]=static_cast<hkUint32_S>(MathUtilities::hkToIntFast(x(2)));
out[3]=static_cast<hkUint32_S>(MathUtilities::hkToIntFast(x(3)));}
inline void __cdecl hkVector4Util_S::convertAabbToUint32(const hkAabb&aabb,const hkVector4&offsetLow,const hkVector4&offsetHigh,const hkVector4&scale,hkAabbUint32&aabbOut)
{
hkVector4 maxVal;maxVal.getQuad()=hkVector4Util_S::g_vAabbExpansion;
hkVector4Util_S::convertToUint32WithClip(aabb.m_kMinimumCorner,offsetLow,scale,hkVector4::getZero(),maxVal,aabbOut.m_kMinimumCorner);
hkVector4Util_S::convertToUint32WithClip(aabb.m_kMaximumCorner,offsetHigh,scale,hkVector4::getZero(),maxVal,aabbOut.m_kMaximumCorner);}
inline void __cdecl hkVector4Util_S::uncompressExpandedAabbUint32(const hkAabbUint32&unexpandedAabbInt,hkAabbUint32&expandedAabbOut)
{
int shift=unexpandedAabbInt.m_ucExpansionShift;
hkUint32_S mix=unexpandedAabbInt.m_kMinimumCorner[0]-(unexpandedAabbInt.m_ucExpansionMin[0]<<shift);
hkUint32_S miy=unexpandedAabbInt.m_kMinimumCorner[1]-(unexpandedAabbInt.m_ucExpansionMin[1]<<shift);
expandedAabbOut.m_kMinimumCorner[0]=mix;
expandedAabbOut.m_kMinimumCorner[1]=miy;
hkUint32_S maxx=unexpandedAabbInt.m_kMaximumCorner[0]+(unexpandedAabbInt.m_ucExpansionMax[0]<<shift);
expandedAabbOut.m_kMaximumCorner[0]=maxx;}
__forceinline void hkCollectionBvTreeAgent3_calcAabbs(const AgentSubtypeMarker&input,const hkpShapeContainer*container,const hkpCdBody*cdBody,const hkpShapeKey_S*hitList,int numHits,AabbCollisionPairGenerator::KeyedAabb*__restrict aabbsOut)
{
AabbUtil::OffsetAabbSweepInput sweepInput;
const int useContinuousPhysics=input.m_pRayCastInput->m_pCollisionQualityInfo->m_iQualityInfoValue10.val();
if(useContinuousPhysics)AabbUtil::GetMotionStateTransforms(cdBody->getRootCollidable()->GetMotionState(),sweepInput);
for(int idx=0;idx<numHits;idx++)
{
hkpShapeKey_S key=hitList[idx];
hkpShapeBuffer shapeBuffer;
const hkpShape*child=container->GetShapeForKey(key,shapeBuffer);
hkAabb aabb;
child->getAabb(cdBody->getTransform(),input.m_pRayCastInput->m_fScalar,aabb);
if(useContinuousPhysics)AabbUtil::sweepOffsetAabb(sweepInput,aabb,aabb);
hkVector4Util_S::convertAabbToUint32(aabb,input.m_pRayCastInput->m_aiValues.m_kAabbMin,input.m_pRayCastInput->m_aiValues.m_kAabbMaximum,input.m_pRayCastInput->m_aiValues.m_kAabbScale,aabbsOut[idx]);
aabbsOut[idx].GetIteratorKey()=key;
}
}
static int GetChildAabbs(const hkpCdBody*cdBody,const hkpCdBody*overrideCdBody,const hkpShapeContainer*collection,const GskAgentInput&input,AabbCollisionPairGenerator::KeyedAabb*aabbs,int aabbsCapacity,int aabbBufferSize_usedOnSpu)
{
const int useContinuousPhysics=input.m_pCollisionQualityInfo->m_iQualityInfoValue10;
int numChildAabbs=0;
const hkpCollidableBoundingVolumeData*bvData=0;
if(!cdBody->getParent()&&(bvData=&reinterpret_cast<const hkpCollidable*>(cdBody)->m_kBoundingVolumeData)->m_pChildShapeAabbs&&(bvData->m_kMinimumCorner[0]<=bvData->m_kMaximumCorner[0]))
{
if(!bvData->m_uiNumChildShapeAabbs)
{
return 0;
}
hkAabbUint32*childShapeAabbs=static_cast<hkAabbUint32*>(bvData->m_pChildShapeAabbs);
hkpShapeKey_S*childShapeKeys=static_cast<hkpShapeKey_S*>(bvData->m_pChildShapeKeys);
for(int i=0;i<bvData->m_uiNumChildShapeAabbs;i++)
{
AabbCollisionPairGenerator::KeyedAabb*aabbInt=&aabbs[i];
if(useContinuousPhysics){hkVector4Util_S::uncompressExpandedAabbUint32(*childShapeAabbs,*aabbInt);}
else{static_cast<hkAabbUint32&>(*aabbInt)=*childShapeAabbs;}
aabbInt->GetIteratorKey()=*childShapeKeys;
childShapeAabbs++;
childShapeKeys++;
numChildAabbs++;
}
if(!useContinuousPhysics)
{
goto DONT_SORT;
}
}
else if(bvData&&(bvData->m_kMinimumCorner[0]<=bvData->m_kMaximumCorner[0])&&overrideCdBody)
{
;
AabbCollisionPairGenerator::KeyedAabb*aabbInt=aabbs;
;
const hkAabbUint32*bvDataAabb=reinterpret_cast<const hkAabbUint32*>(bvData);
if(useContinuousPhysics)
{
hkVector4Util_S::uncompressExpandedAabbUint32(*bvDataAabb,*aabbInt);
}
else
{
static_cast<hkAabbUint32&>(*aabbInt)=*bvDataAabb;
}
aabbInt->GetIteratorKey()=0;
numChildAabbs++;
goto DONT_SORT;
}
else
{
AabbUtil::OffsetAabbSweepInput sweepInput;
if(useContinuousPhysics)
{
AabbUtil::GetMotionStateTransforms(cdBody->getRootCollidable()->GetMotionState(),sweepInput);
}
hkpShapeBuffer buffer;
for(hkpShapeKey_S key=collection->GetFirstKey();key !=0xffffffff;key=collection->GetNextShapeKey(key))
{
const hkpShape*child=collection->GetShapeForKey(key,buffer);
hkAabb aabb;
child->getAabb(cdBody->getTransform(),input.m_fScalar,aabb);
if(useContinuousPhysics)
{
AabbUtil::sweepOffsetAabb(sweepInput,aabb,aabb);
}
AabbCollisionPairGenerator::KeyedAabb*aabbInt=&aabbs[numChildAabbs++];
hkVector4Util_S::convertAabbToUint32(aabb,input.m_aiValues.m_kAabbMin,input.m_aiValues.m_kAabbMaximum,input.m_aiValues.m_kAabbScale,*aabbInt);
aabbInt->GetIteratorKey()=key;
}
}
DONT_SORT:
;}
// @fnv 0x00d35770
// src: XBOX_PDB 0x00d35770
hkpAgentData*__cdecl hkpCollectionCollectionAgent3::process_00d35770(const AgentSubtypeMarker&input,FourByteState*entry,hkpAgentData*agentData,hkVector4*separatingNormal,WorldOperationEntry&output)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerBeginListCommand*h=reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(mStream.getEnd());h->m_commandAndMonitor="L" "t" "CollColl3";h->m_nameOfFirstSplit="S" "t" "Init";h->setTime();mStream.setEnd((char*)(h+1));}};
AgentSectorPointerArray*agent1nTrack=reinterpret_cast<AgentSectorPointerArray*>(agentData);
const bool shapeAisCollection=!input.m_pRayCastInput->m_pCollisionDispatcher->hasAlternateType(input.m_pBodyA->getShape()->getType(),HK_SHAPE_BV_TREE);
const bool shapeBisCollection=!input.m_pRayCastInput->m_pCollisionDispatcher->hasAlternateType(input.m_pBodyB->getShape()->getType(),HK_SHAPE_BV_TREE);
bool treatAasCollection;
if(shapeAisCollection | shapeBisCollection)
{
treatAasCollection=shapeAisCollection;
if((shapeAisCollection&&input.m_pBodyA->getShape()->getType()!=HK_SHAPE_LIST)||(shapeBisCollection&&input.m_pBodyB->getShape()->getType()!=HK_SHAPE_LIST))
{
;
}
}
else
{
const bool bodyAHasCachedChildShapeAabbs=!input.m_pBodyA->m_parent&&reinterpret_cast<const hkpCollidable*>(input.m_pBodyA.val())->m_kBoundingVolumeData.m_pChildShapeAabbs;
const bool bodyBHasCachedChildShapeAabbs=!input.m_pBodyB->m_parent&&reinterpret_cast<const hkpCollidable*>(input.m_pBodyB.val())->m_kBoundingVolumeData.m_pChildShapeAabbs;
if(bodyAHasCachedChildShapeAabbs==bodyBHasCachedChildShapeAabbs)
{
hkpShapeBuffer tmpBufferA;const hkpShapeCollection*childCollectionA=hkBvTreeAgent3::GetCollectionFromBody(input.m_pBodyA,tmpBufferA);
hkpShapeBuffer tmpBufferB;const hkpShapeCollection*childCollectionB=hkBvTreeAgent3::GetCollectionFromBody(input.m_pBodyB,tmpBufferB);
const bool shapeAhasList=childCollectionA ? childCollectionA->getType()==HK_SHAPE_LIST:false;
const bool shapeBhasList=childCollectionB ? childCollectionB->getType()==HK_SHAPE_LIST:false;
if(shapeAhasList&&shapeBhasList)
{
treatAasCollection=static_cast<const hkpListShape*>(childCollectionA)->hkpListShape::GetNumChildShapes()<=static_cast<const hkpListShape*>(childCollectionB)->hkpListShape::GetNumChildShapes();
}
else if(shapeAhasList | shapeBhasList)
{
treatAasCollection=shapeAhasList;
}
else
{
treatAasCollection=input.m_pBodyA->GetMotionState()->m_fObjectRadius<=input.m_pBodyB->GetMotionState()->m_fObjectRadius;
;
}
}
else
{
treatAasCollection=bodyAHasCachedChildShapeAabbs;
}
}
hkpShapeBuffer bufferA;const hkpShapeContainer*shapeContainerA=hkBvTreeAgent3::GetContainerFromBody(input.m_pBodyA,bufferA);
hkpShapeBuffer bufferB;const hkpShapeContainer*shapeContainerB=hkBvTreeAgent3::GetContainerFromBody(input.m_pBodyB,bufferB);
ShapeKeyCombination*shapeKeyPairs=hkAllocateStack<ShapeKeyCombination>(HK_MAX_NUM_HITS_PER_AABB_QUERY,"ShapeKeyPairs");
int numShapeKeyPairs;
{
int numHitsFirst=0;
int numHitsSecond=0;
AabbCollisionPairGenerator::KeyedAabb*aabbsFirst;
AabbCollisionPairGenerator::KeyedAabb*aabbsSecond;
const hkpCdBody*firstCdBody;
{
const hkpCdBody*secondBody;
const hkpShapeContainer*secondContainer;
if(!(shapeAisCollection&shapeBisCollection))
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="S" "t" "queryTree";h->setTime();mStream.setEnd((char*)(h+1));}};
const hkpShapeContainer*firstContainer;
hkpShapeKey_S hitList[HK_MAX_NUM_HITS_PER_AABB_QUERY];
if(treatAasCollection)
{
;
hkTransform bTa;bTa.SetConjugate(input.m_kTransform);
numHitsFirst=hkBvTreeAgent3::BuildCollisionHitList(*input.m_pBodyA,*input.m_pBodyB,bTa,input.m_vSubtypePosition,*input.m_pRayCastInput,0,hitList,HK_MAX_NUM_HITS_PER_AABB_QUERY);
firstCdBody=input.m_pBodyB;
firstContainer=shapeContainerB;
secondBody=input.m_pBodyA;
secondContainer=shapeContainerA;
}
else
{
;
hkVector4 negLinearTimInfo;negLinearTimInfo.setNeg3(input.m_vSubtypePosition);
numHitsFirst=hkBvTreeAgent3::BuildCollisionHitList(*input.m_pBodyB,*input.m_pBodyA,input.m_kTransform,negLinearTimInfo,*input.m_pRayCastInput,0,hitList,HK_MAX_NUM_HITS_PER_AABB_QUERY);
firstCdBody=input.m_pBodyA;
firstContainer=shapeContainerA;
secondBody=input.m_pBodyB;
secondContainer=shapeContainerB;
}
aabbsFirst=hkAllocateStack<AabbCollisionPairGenerator::KeyedAabb>(numHitsFirst+4,"aabbsFirst");
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="S" "t" "ConvertHitlist";h->setTime();mStream.setEnd((char*)(h+1));}};
hkCollectionBvTreeAgent3_calcAabbs(input,firstContainer,firstCdBody,hitList,numHitsFirst,aabbsFirst);
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="S" "t" "SortHitList";h->setTime();mStream.setEnd((char*)(h+1));}};
AlgorithmUtilities::quickSort(aabbsFirst,numHitsFirst);
}
else
{
numHitsFirst=shapeContainerA->GetNumChildShapes();
{
const hkpCollidable*coll=reinterpret_cast<const hkpCollidable*>(input.m_pBodyA.val());
if(!coll->getParent()&&coll->m_kBoundingVolumeData.m_pChildShapeAabbs&&(coll->m_kBoundingVolumeData.m_kMinimumCorner[0]<=coll->m_kBoundingVolumeData.m_kMaximumCorner[0]))
{
numHitsFirst=MathUtilities::max2(numHitsFirst,int(coll->m_kBoundingVolumeData.m_uiNumChildShapeAabbs));
}
}
int numHitsForAllocate=numHitsFirst;
const int numAabbsAllocated=numHitsForAllocate+4;
aabbsFirst=hkAllocateStack<AabbCollisionPairGenerator::KeyedAabb>(numAabbsAllocated,"aabbsFirst");
numHitsFirst=GetChildAabbs(input.m_pBodyA,input.m_pAdditionalCollidableBody,shapeContainerA,*input.m_pRayCastInput.val(),aabbsFirst,numHitsFirst,numAabbsAllocated*sizeof(AabbCollisionPairGenerator::KeyedAabb));
firstCdBody=input.m_pBodyA;
secondBody=input.m_pBodyB;
secondContainer=shapeContainerB;
}
if(numHitsFirst)
{
numHitsSecond=secondContainer->GetNumChildShapes();
{
const hkpCollidable*coll=reinterpret_cast<const hkpCollidable*>(secondBody);
if(!coll->getParent()&&coll->m_kBoundingVolumeData.m_pChildShapeAabbs&&(coll->m_kBoundingVolumeData.m_kMinimumCorner[0]<=coll->m_kBoundingVolumeData.m_kMaximumCorner[0]))
{
numHitsSecond=MathUtilities::max2(numHitsSecond,int(coll->m_kBoundingVolumeData.m_uiNumChildShapeAabbs));
}
}
int numHitsForAllocate=numHitsSecond;
const int numAabbsAllocated=numHitsForAllocate+4;
aabbsSecond=hkAllocateStack<AabbCollisionPairGenerator::KeyedAabb>(numAabbsAllocated,"aabbsSecond");
;
numHitsSecond=GetChildAabbs(secondBody,0,secondContainer,*input.m_pRayCastInput.val(),aabbsSecond,numHitsSecond,numAabbsAllocated*sizeof(AabbCollisionPairGenerator::KeyedAabb));
}
else
{
numHitsSecond=0;
aabbsSecond=hkAllocateStack<AabbCollisionPairGenerator::KeyedAabb>(4,"aabbsSecond");
}
for(int i=numHitsFirst;i<numHitsFirst+4;i++){aabbsFirst[i].m_kMinimumCorner[0]=hkUint32_S(-1);}
for(int i=numHitsSecond;i<numHitsSecond+4;i++){aabbsSecond[i].m_kMinimumCorner[0]=hkUint32_S(-1);}
}
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="S" "t" "1-Axis";h->setTime();mStream.setEnd((char*)(h+1));}};
hkPadSpu<int>numPairsSkipped(0);
if(firstCdBody==input.m_pBodyA)
{
numShapeKeyPairs=AabbCollisionPairGenerator::collide(aabbsFirst,numHitsFirst,aabbsSecond,numHitsSecond,reinterpret_cast<ShapeKeyPair*>(shapeKeyPairs),HK_MAX_NUM_HITS_PER_AABB_QUERY-1,numPairsSkipped);
}
else
{
numShapeKeyPairs=AabbCollisionPairGenerator::collide(aabbsSecond,numHitsSecond,aabbsFirst,numHitsFirst,reinterpret_cast<ShapeKeyPair*>(shapeKeyPairs),HK_MAX_NUM_HITS_PER_AABB_QUERY-1,numPairsSkipped);
}
hkDeallocateStack(aabbsSecond);
hkDeallocateStack(aabbsFirst);
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="S" "t" "SortHits";h->setTime();mStream.setEnd((char*)(h+1));}};
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::AddValueCommand*h=reinterpret_cast<hkMonitorStream::AddValueCommand*>(mStream.getEnd());h->m_commandAndMonitor="M" "i" "NumHits";h->m_value=float(numShapeKeyPairs);mStream.setEnd((char*)(h+1));}};
AlgorithmUtilities::quickSort(shapeKeyPairs,numShapeKeyPairs);
;
ShapeKeyCombination*pair=shapeKeyPairs+numShapeKeyPairs;
pair->m_uiShapeKeyA=0xffffffff;
pair->m_uiShapeKeyB=0xffffffff;
}
int total=numShapeKeyPairs+1;
if(total<HK_MAX_NUM_HITS_PER_AABB_QUERY)
{
hkShrinkAllocatedStack(shapeKeyPairs,total);
}
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="S" "t" "Narrow";h->setTime();mStream.setEnd((char*)(h+1));}};
if(!input.m_pAdditionalCollidableBody)
{
BuildShapePairWorldOperations(*agent1nTrack,input,shapeContainerA,shapeContainerB,shapeKeyPairs,output);
}
else
{
hkpShapeKey_S*shapeKeys=hkAllocateStack<hkpShapeKey_S>(numShapeKeyPairs+1,"ShapeKeyPairs");
ShapeKeyCombination*fullShapeKeyPairs=shapeKeyPairs;
for(int i=0;i<=numShapeKeyPairs;i++)
{
shapeKeys[i]=fullShapeKeyPairs[i].m_uiShapeKeyB;
}
AgentSubtypeMarker modInput=input;
modInput.m_pBodyA=input.m_pAdditionalCollidableBody;
modInput.m_pAdditionalCollidableBody=0;
BuildShapeCollectionBWorldOperations(*agent1nTrack,modInput,shapeContainerB,shapeKeys,output);
hkDeallocateStack(shapeKeys);
}
hkDeallocateStack(shapeKeyPairs);
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="l" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return hkAddByteOffset(agentData,(((sizeof(AgentSectorPointerArray))+((16)-1))&(~((16)-1))));
}
