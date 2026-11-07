#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkColor.h"
#include "../../../../../../../include/hkDebugDisplayHandler.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMoppBvTreeShapeBase.h"
#include "../../../../../../../include/hkMultiThreadCheck.h"
#include "../../../../../../../include/hkProcess.h"
#include "../../../../../../../include/hkProcessContext.h"
#include "../../../../../../../include/hkQuaternion.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkStringPtr.h"
#include "../../../../../../../include/hkThreadLocalData.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpActionListener.h"
#include "../../../../../../../include/hkpBvTreeShape.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCollidable.h"
#include "../../../../../../../include/hkpConstraintListener.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpEntityListener.h"
#include "../../../../../../../include/hkpKeyframedRigidMotion.h"
#include "../../../../../../../include/hkpLinkedCollidable.h"
#include "../../../../../../../include/hkpMaterial.h"
#include "../../../../../../../include/hkpMaxSizeMotion.h"
#include "../../../../../../../include/hkpMoppBvTreeShape.h"
#include "../../../../../../../include/hkpMotion.h"
#include "../../../../../../../include/hkpPhantomListener.h"
#include "../../../../../../../include/hkpPhysicsContextWorldListener.h"
#include "../../../../../../../include/hkpPhysicsSystem.h"
#include "../../../../../../../include/hkpRigidBody.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpShapeCollection.h"
#include "../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../include/hkpSingleShapeContainer.h"
#include "../../../../../../../include/hkpSphereRepShape.h"
#include "../../../../../../../include/hkpTriangleShape.h"
#include "../../../../../../../include/hkpTypedBroadPhaseHandle.h"
#include "../../../../../../../include/hkpWorld.h"
#include "../../../../../../../include/hkpWorldDeletionListener.h"
#include "../../../../../../../include/hkpWorldPostSimulationListener.h"
#include "../../../../../../../include/hkpWorldViewerBase.h"

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl __debugbreak(void);
typedef float hkReal;
typedef signed char hkInt8;
typedef signed short hkInt16;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
#include "../../../../../../../include/hkResult.h"
typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;
class hkClass;

template<class TYPE>
class ReferenceCountedPointer
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
private:
TYPE*m_pRetainedObject;};
#include "../../../../../../../include/hkArray.h"
template<typename T>
class ResizableArray
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
enum
{
CAPACITY_MASK=hkUint16(0x3fff),
FLAG_MASK=hkUint16(0xC000),
DONT_DEALLOCATE_FLAG=hkUint16(0x8000),
LOCKED_FLAG=hkUint16(0x4000),
FORCE_SIGNED=-1
};
protected:
friend class hkStatisticsCollector;
T*m_data;
hkUint16 m_iElementCount;
public:
ResizableArray(FinishingFlag f){}
};

__forceinline hkSimdReal::hkSimdReal() {}
__forceinline const __m128& hkSimdReal::getQuad() const { return *reinterpret_cast<const __m128*>(&x); }
__forceinline __m128 hkSimdReal::broadcast() const { return _mm_shuffle_ps(getQuad(),getQuad(),0); }
__forceinline hkSimdReal::operator float() const { float scalar; _mm_store_ss(&scalar,getQuad()); return scalar; }
// Preserve aligned SIMD temporaries despite the shared scalar member layout.
__forceinline hkSimdReal makeComponent(float scalar) { __m128 value=_mm_load_ss(&scalar); __declspec(align(16)) hkSimdReal component; *reinterpret_cast<__m128*>(&component)=value; return component; }
// hkBool has a one-byte ABI; its shared declaration exposes no storage member.
__forceinline hkMonitorStream& hkMonitorStream::getInstance() { extern hkThreadLocalData<hkMonitorStream*>g_pMonitorStream; return *g_pMonitorStream.getData(); }
__forceinline char* __cdecl hkMonitorStream::getStart() { return m_start.val(); }
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline hkBool __cdecl hkMonitorStream::memoryAvailable() { return getEnd()<getCapacityMinus16(); }
__forceinline void __cdecl hkMonitorStream::setEnd(char*ptr) { m_end=ptr; }
typedef __m128 hkQuadReal;

typedef const hkVector4&hkVector4Parameter;

typedef const hkSimdReal&hkSimdRealParameter;

class hkQsTransform;


// The shared RotationLocal_00d62780 changes instruction scheduling in FUN_00d62780.
// Keep this local definition until the callback matches with the shared type.
// local form of hkRotation: 0x00d62780 needs the original intrinsic scheduling and hkMatrix3 base.
class __declspec(align(16)) RotationLocal_00d62780:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
};


__forceinline void hkVector4::add4(const hkVector4&v)
{
m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);
}
__forceinline void hkVector4::setAdd4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
__forceinline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
__forceinline void hkVector4::setNeg3(const hkVector4&v)
{
extern const hkQuadReal DAT_010c4c00;
m_vComponents=_mm_xor_ps(v.m_vComponents,DAT_010c4c00);
}
__forceinline void hkVector4::mul4(hkSimdRealParameter s)
{
m_vComponents=_mm_mul_ps(s.broadcast(),m_vComponents);
}
__forceinline void setMulComponent(hkVector4& out,hkSimdRealParameter r,const hkVector4&v1)
{
out.m_vComponents=_mm_mul_ps(r.broadcast(),v1.m_vComponents);
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
__forceinline void hkVector4::setInterpolate4(const hkVector4&v0,const hkVector4&v1,hkSimdRealParameter _t)
{
extern const hkQuadReal DAT_010ec7f0;
hkQuadReal t=_t.broadcast();
hkQuadReal s=_mm_sub_ps(DAT_010ec7f0,t);
m_vComponents=_mm_add_ps(
_mm_mul_ps(s,v0.m_vComponents),
_mm_mul_ps(t,v1.m_vComponents));}
__forceinline void interpolateBroadcast(hkVector4& out,const hkVector4& a,const hkVector4& b,hkQuadReal t) { extern const hkQuadReal DAT_010ec7f0;  hkQuadReal s=_mm_sub_ps(DAT_010ec7f0,t); t=_mm_mul_ps(t,b.m_vComponents); out.m_vComponents=_mm_add_ps(_mm_mul_ps(s,a.m_vComponents),t); }
__forceinline void setTransformedPos(hkVector4& out,const hkTransform&t,const hkVector4&b)
{
const RotationLocal_00d62780&r=reinterpret_cast<const RotationLocal_00d62780&>(t.getRotation());
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
out.m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.getTranslation().m_vComponents));}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
hkQuadReal result=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum); __declspec(align(16)) hkSimdReal component; *reinterpret_cast<__m128*>(&component)=result; return component;}
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
hkQuadReal result=_mm_andnot_ps(len2EqualsZero,refined); __declspec(align(16)) hkSimdReal component; *reinterpret_cast<__m128*>(&component)=result; return component;}
__forceinline void hkVector4::normalize3()
{
hkQuadReal lenInv=lengthInverse3(*this).broadcast();
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
}
inline const hkVector4&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
const hkVector4&hkTransform::getTranslation()const
{
return *reinterpret_cast<const hkVector4*>(&m_row3);
}
const hkRotation&hkTransform::getRotation()const
{
return *reinterpret_cast<const hkRotation*>(&m_row0);
}

class Vector4WithInt24W:public hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};
#include "../../../../../../../include/hkpBufferSize.h"
struct __declspec(align(16)) hkpShapeBuffer { char data[HK_SHAPE_BUFFER_SIZE]; };
class hkAabb;
typedef hkUint32 hkpShapeKey;
hkpShapeType hkpShape::getType()const
{
return *reinterpret_cast<const hkpShapeType*>(&m_type);
}

__forceinline const hkpShape*hkpCollidable::getShape()const
{
return m_pCollisionShape;
}
struct NarrowPhaseAgentEntry;

struct ConstraintInstanceBuffer
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
enum{CAPACITY=128};void reset(){m_uiConstraintCount=0;}
public:
hkUint32 m_uiConstraintCount;
class hkpConstraintInstance*m_ppConstraints[CAPACITY];};const hkTransform&hkMotionState::getTransform()const
{
return m_kMotionTransform;
}
const hkTransform&hkpMotion::getTransform()const
{
return m_kMotionState.getTransform();
}

class hkVisualDebugger;

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

class hkDisplayGeometry;

class hkProcessHandler;


class hkpWeldingViewer:public hkpWorldViewerBase,public hkpWorldPostSimulationListener
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}__forceinline void __cdecl operator delete(void*p){hkReferencedObject*b=static_cast<hkReferencedObject*>(p);;hkMemoryRouter::getInstance().heap().blockFree(p,b->m_usMemSizeAndFlags);}__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){__debugbreak();return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){__debugbreak();}class CommandArgument;
static hkProcess*__cdecl create(const hkArray<hkProcessContext*>&contexts);
static void __cdecl RegisterViewer(void);
static inline const char*__cdecl getName(void){return "WeldingViewer";}
virtual int GetOperationType(void){return m_ucOperationType;}
// The recipe retains the original recovered symbol for the callback entry.
virtual void ProcessEntries_00d62780(hkpWorld*world);
protected:
hkpWeldingViewer(const hkArray<hkProcessContext*>&contexts);
virtual ~hkpWeldingViewer() throw();
virtual void WorldAddedCallback(hkpWorld*world);
virtual void WorldRemovedCallback(hkpWorld*world);
static int m_ucOperationType;
};

class hkpSimulation;
struct EmptyPayload
{};

inline const hkArray<hkpRigidBody*>&hkpPhysicsSystem::getRigidBodies()const
{
return m_ppRigidBodies;
}
inline hkpMotion*hkpRigidBody::getRigidMotion()const
{
return const_cast<hkpMaxSizeMotion*>(&m_pMotionState);
}
inline const hkTransform&hkpRigidBody::getTransform()const
{
return getRigidMotion()->getTransform();
}

// The shared welding utility declares the welding types. Keep the table and
// snap-vector implementation at file scope because it does not declare them.
struct WeldingEdgeAngleEntry
{
hkReal m_fValue0;
hkReal m_fValue1;
hkReal m_fValue2;
hkReal m_fValue3;
hkReal m_fValue4;
hkReal m_fValue5;
};
extern __declspec(align(16)) WeldingEdgeAngleEntry weldingEdgeAngleTable[32];
__forceinline void calcSnapVector(const hkVector4&triangleNormal,const hkVector4&edge,int edgeBitcode,int sector,hkVector4&snapVectorOut)
{
hkVector4 orthNormalEdge;orthNormalEdge.setCross(edge,triangleNormal);
hkReal*sinCosTableEntry=&weldingEdgeAngleTable[edgeBitcode].m_fValue0;
hkVector4 hVec0;setMulComponent(hVec0,makeComponent(sinCosTableEntry[sector+0]),triangleNormal);
hkVector4 hVec1;setMulComponent(hVec1,makeComponent(sinCosTableEntry[sector+1]),orthNormalEdge);
snapVectorOut.setAdd4(hVec0,hVec1);
snapVectorOut.normalize3();}
__forceinline void calcSnapVectorOneSided(const hkVector4&triangleNormal,const hkVector4&edge,int edgeBitcode,hkpWeldingUtility::WeldingType weldingType,hkVector4&snapVectorOut)
{
calcSnapVector(triangleNormal,edge,edgeBitcode,(int)weldingType,snapVectorOut);
}

inline const hkpShapeCollection*hkpMoppBvTreeShape::getShapeCollection()const
{
return static_cast<const hkpShapeCollection*>(m_pChildAtom.getChild());
}

__forceinline hkUint16 hkpTriangleShape::getWeldingInfo()const
{
return m_kWeldingInfo;
}
__forceinline hkpWeldingUtility::WeldingType hkpTriangleShape::getWeldingType()const
{
return static_cast<hkpWeldingUtility::WeldingType>(*reinterpret_cast<const hkUint8*>(&m_eWeldingType));
}
__forceinline const hkVector4&hkpTriangleShape::getVertex(int i)const
{
;
return(&m_kVertexA)[i];
}
class hkpMeshWeldingUtility
{
public:
enum WindingConsistency
{
WINDING_IGNORE_CONSISTENCY,
WINDING_TEST_CONSISTENCY,
};
public:
static int __cdecl calcSingleEdgeBitcode(hkUint16 triangleEdgesBitcode,int edgeIndex);
static void __cdecl calcAntiClockwiseTriangleNormal(const hkVector4&vertex0,const hkVector4&vertex1,const hkVector4&vertex2,hkVector4&normal);
public:
static hkResult __cdecl calcWeldingInfoForTriangle(hkpShapeKey shapeKey,const hkpBvTreeShape*bvTreeShape,WindingConsistency testConsistency,hkUint16&info);};

extern const float DAT_010d1648;
extern const double DAT_010d1640;
// The annotated entry receives the post-simulation listener subobject at
// +0x28. Recover the shared hkProcess subobject at +0x08; unk10 is the
// display-handler pointer used by this callback.
// @fnv 0x00d62780
// src: GUESS 0x00d62780 (confidence: low)
void hkpWeldingViewer::ProcessEntries_00d62780(hkpWorld*world)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "hkpActiveContactPointViewer::postSimulationCallback";h->setTime();mStream.setEnd((char*)(h+1));}};ScopedTimer timeblock18;
world->lock();
hkpPhysicsSystem*system=world->getWorldAsOneSystem();
const hkArray<hkpRigidBody*>&rigidBodies=system->getRigidBodies();
for(int i=0;i<rigidBodies.m_iElementCount;i++)
{
const hkpRigidBody*body=rigidBodies.m_data[i];
const int collidableId=(int)(hkUlong)(&body->m_kCollidable);
const hkTransform&bodyTransform=body->getTransform();
const hkpShape*rootShape=body->m_kCollidable.getShape();
if(rootShape->getType()==HK_SHAPE_MOPP)
{
const hkpMoppBvTreeShape*mopp=static_cast<const hkpMoppBvTreeShape*>(rootShape);
const hkpShapeCollection*coll=mopp->getShapeCollection();
for(hkpShapeKey key=coll->GetFirstKey();key !=0xffffffff;key=coll->GetNextShapeKey(key))
{
hkpShapeBuffer buffer;
const hkpShape*childShape=coll->GetShapeForKey(key,buffer);
if(childShape->getType()==HK_SHAPE_TRIANGLE)
{
const hkpTriangleShape*triangle=static_cast<const hkpTriangleShape*>(childShape);
if(triangle->getWeldingType()!=hkpWeldingUtility::WELDING_TYPE_TWO_SIDED&&triangle->getWeldingType()!=hkpWeldingUtility::WELDING_TYPE_NONE)
{
hkUint16 weldingInfo=triangle->getWeldingInfo();
hkVector4 vertices[3];
setTransformedPos(vertices[0],bodyTransform,triangle->getVertex(0));
setTransformedPos(vertices[1],bodyTransform,triangle->getVertex(1));
setTransformedPos(vertices[2],bodyTransform,triangle->getVertex(2));
reinterpret_cast<hkDebugDisplayHandler*>(reinterpret_cast<const hkProcess*>(reinterpret_cast<const char*>(this)-0x20)->unk10)->DisplayLine(vertices[0],vertices[1],hkColor::RED,collidableId,m_ucOperationType);
reinterpret_cast<hkDebugDisplayHandler*>(reinterpret_cast<const hkProcess*>(reinterpret_cast<const char*>(this)-0x20)->unk10)->DisplayLine(vertices[1],vertices[2],hkColor::RED,collidableId,m_ucOperationType);
reinterpret_cast<hkDebugDisplayHandler*>(reinterpret_cast<const hkProcess*>(reinterpret_cast<const char*>(this)-0x20)->unk10)->DisplayLine(vertices[2],vertices[0],hkColor::RED,collidableId,m_ucOperationType);
hkVector4 triangleCenter;
triangleCenter.setAdd4(vertices[0],vertices[1]);
triangleCenter.add4(vertices[2]);
triangleCenter.mul4(makeComponent(1.0f / 3.0f));
hkVector4 triangleNormal;
hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(vertices[0],vertices[1],vertices[2],triangleNormal);
for(int k=0;k<3;k++)
{
int edgeIndex0=k;
int edgeIndex1=(k+1)% 3;
hkVector4 edge;
edge.setSub4(vertices[edgeIndex1],vertices[edgeIndex0]);
edge.normalize3();
int edgeCode=hkpMeshWeldingUtility::calcSingleEdgeBitcode(weldingInfo,k);
hkVector4 edgeCenter;
interpolateBroadcast(edgeCenter,vertices[edgeIndex0],vertices[edgeIndex1],_mm_set_ps1(DAT_010d1648));
hkVector4 snapVector0;
calcSnapVectorOneSided(triangleNormal,edge,edgeCode,triangle->getWeldingType(),snapVector0);
if(triangle->getWeldingType()==hkpWeldingUtility::WELDING_TYPE_CLOCKWISE)
{
triangleNormal.setNeg3(triangleNormal);
}
if(snapVector0.dot3(triangleNormal)<DAT_010d1640)
{
continue;
}
hkVector4 p0,p1;
p0.setAdd4(edgeCenter,snapVector0);
p1.setAdd4(edgeCenter,triangleNormal);
reinterpret_cast<hkDebugDisplayHandler*>(reinterpret_cast<const hkProcess*>(reinterpret_cast<const char*>(this)-0x20)->unk10)->DisplayLine(edgeCenter,p0,hkColor::ORANGE,collidableId,m_ucOperationType);
reinterpret_cast<hkDebugDisplayHandler*>(reinterpret_cast<const hkProcess*>(reinterpret_cast<const char*>(this)-0x20)->unk10)->DisplayLine(edgeCenter,p1,hkColor::ORANGE,collidableId,m_ucOperationType);
reinterpret_cast<hkDebugDisplayHandler*>(reinterpret_cast<const hkProcess*>(reinterpret_cast<const char*>(this)-0x20)->unk10)->DisplayLine(edgeCenter,triangleCenter,hkColor::GREEN,collidableId,m_ucOperationType);
hkVector4 start;start=snapVector0;
const int kSteps=10;
for(int s=0;s<kSteps;s++)
{
hkVector4 interp;
interp.setInterpolate4(snapVector0,triangleNormal,makeComponent((s+1)/ 10.0));
interp.normalize3();
hkVector4 ep0,ep1;
ep0.setAdd4(edgeCenter,start);
ep1.setAdd4(edgeCenter,interp);
reinterpret_cast<hkDebugDisplayHandler*>(reinterpret_cast<const hkProcess*>(reinterpret_cast<const char*>(this)-0x20)->unk10)->DisplayLine(ep0,ep1,hkColor::ORANGE,collidableId,m_ucOperationType);
start=interp;
}
}
}
}
}
}
}
static_cast<const hkpPhysicsSystem*>(system)->removeReference();
world->unlock();
}
