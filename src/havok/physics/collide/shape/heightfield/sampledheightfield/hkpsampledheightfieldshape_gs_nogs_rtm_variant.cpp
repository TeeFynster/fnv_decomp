#define FNV64_HKENUM_INLINE_BODIES

// src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape_gs_nogs_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/FinishingFlag.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkpRayHitCollector.h"
#include "../../../../../../../include/hkThreadLocalData.h"
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
typedef signed char hkInt8;
typedef signed short hkInt16;
typedef signed int hkInt32;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __int64 hkUint64;
typedef __int64 hkInt64;
typedef unsigned __w64 hk_size_t;
class hkClass;
class hkBoolR
{
public:
typedef char CompileTimeTrueType;
inline hkBoolR()
{
}
inline hkBoolR(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};
#include "../../../../../../../include/hkEnum.h"
using ::hkEnum;
class hkBaseObject_
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline hkBaseObject_(){}
};
class hkStatisticsCollector;
class hkReferencedObject_:public hkBaseObject_
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject_*b=static_cast<hkReferencedObject_*>(hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
virtual const hkClass*getClassType()const;
virtual void calcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16 m_usMemSizeAndFlags;
public:
hkReferencedObject_(class FinishingFlag flag){}
};typedef float hkReal;
typedef __m128 hkQuadReal;
class hkVector4_;
typedef const hkVector4_&hkVector4Parameter;

// Scalar operations used by the heightfield's local vector implementation.
class HeightFieldScalar
{
public:
    HeightFieldScalar(const hkQuadReal& x) : m_vValue(x) {}
    HeightFieldScalar(hkReal x) { m_vValue = _mm_load_ss(&x); }
    __forceinline hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const hkQuadReal& getQuad() const { return m_vValue; }
private:
    hkQuadReal m_vValue;
};
typedef const HeightFieldScalar&hkSimdRealParameter;class Vector4Comparison;
typedef const Vector4Comparison&hkVector4ComparisonParameter;
namespace MathUtilities
{inline int __cdecl hkToIntFast(hkReal r){
return fnv_FloatToInt(r);
}
}
extern "C"{
double __cdecl fabs([SA_Pre(Null=SA_No)][SA_Pre(Deref=1,Valid=SA_Yes,Access=SA_Read)]double _X);inline float fabsf([SA_Pre(Null=SA_No)][SA_Pre(Deref=1,Valid=SA_Yes,Access=SA_Read)]float _X)
{return((float)fabs((double)_X));}
}
namespace MathUtilities
{inline hkReal __cdecl fabs(hkReal r){return::fabsf(r);}
template<typename T>
inline T __cdecl max2(T x,T y)
{
return x>y ? x:y;
}
}
class hkTransform_;
class hkVector4_
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline void setAll3(hkReal x);
__forceinline void add4(const hkVector4_&a);
__forceinline void setAdd4(const hkVector4_&a,const hkVector4_&b);
__forceinline void mul4(const hkVector4_&a);
__forceinline void setMul4(hkVector4Parameter a,hkVector4Parameter b);
__forceinline void setInterpolate4(const hkVector4_&a,const hkVector4_&b,hkSimdRealParameter t);
__forceinline HeightFieldScalar dot3(const hkVector4_&a)const;
__forceinline HeightFieldScalar lengthInverse3()const;
__forceinline void normalize3();
__forceinline hkReal&operator()(int i);
__forceinline hkQuadReal&getQuad();
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};
inline hkQuadReal&hkVector4_::getQuad()
{
return m_vComponents;
}
inline void hkVector4_::setAll3(hkReal a)
{
m_vComponents=_mm_set_ps1(a);
}
inline void hkVector4_::add4(const hkVector4_&v)
{
m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4_::setAdd4(const hkVector4_&v0,const hkVector4_&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4_::mul4(const hkVector4_&v)
{
m_vComponents=_mm_mul_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4_::setMul4(const hkVector4_&a,const hkVector4_&b)
{
m_vComponents=_mm_mul_ps(a.m_vComponents,b.m_vComponents);
}
inline void hkVector4_::setInterpolate4(const hkVector4_&v0,const hkVector4_&v1,hkSimdRealParameter _t)
{
static __declspec(align(16))const float cw[4]={1.0f,1.0f,1.0f,1.0f};
hkQuadReal t=_t.broadcast();
hkQuadReal s=_mm_sub_ps(*(const hkQuadReal*)&cw,t);
m_vComponents=_mm_add_ps(
_mm_mul_ps(s,v0.m_vComponents),
_mm_mul_ps(t,v1.m_vComponents));}
inline HeightFieldScalar hkVector4_::dot3(const hkVector4_&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline HeightFieldScalar hkVector4_::lengthInverse3()const
{
const hkQuadReal half=_mm_set_ss(0.5f);
const hkQuadReal three=_mm_set_ss(3.0f);
const hkQuadReal zero=_mm_set_ss(0.0f);
const hkQuadReal len2=this->dot3(*this).getQuad();
const hkQuadReal len2EqualsZero=_mm_cmpeq_ss(len2,zero);
const hkQuadReal approx=_mm_rsqrt_ss(len2);
const hkQuadReal refined=_mm_mul_ss(
_mm_mul_ss(half,approx),
_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(len2,approx),approx)));
return _mm_andnot_ps(len2EqualsZero,refined);}
inline void hkVector4_::normalize3()
{
hkQuadReal lenInv=lengthInverse3().broadcast();
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
}
inline hkReal&hkVector4_::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}

// Keep monitor operations inline at their original call sites.
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
__forceinline void hkMonitorStream::TimerCommand::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_time0=ticks;
}
class Vector4WithInt24W:public hkVector4_
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};
enum hkpShapeType
{
HK_SHAPE_INVALID=0,
HK_SHAPE_SPHERE,
HK_FIRST_SHAPE_TYPE=HK_SHAPE_SPHERE,
HK_SHAPE_CYLINDER,
HK_SHAPE_TRIANGLE,
HK_SHAPE_BOX,
HK_SHAPE_CAPSULE,
HK_SHAPE_CONVEX_VERTICES,
HK_SHAPE_COLLECTION,
HK_SHAPE_BV_TREE,
HK_SHAPE_LIST,
HK_SHAPE_MOPP,
HK_SHAPE_CONVEX_TRANSLATE,
HK_SHAPE_CONVEX_TRANSFORM,
HK_SHAPE_SAMPLED_HEIGHT_FIELD,
HK_SHAPE_EXTENDED_MESH,
HK_SHAPE_TRANSFORM,
HK_SHAPE_COMPRESSED_MESH,
HK_SHAPE_MAX_ID_SPU=HK_SHAPE_COMPRESSED_MESH+1,
HK_SHAPE_CONVEX,
HK_SHAPE_PACKED_CONVEX_VERTICES,
HK_SHAPE_MOPP_EMBEDDED,
HK_SHAPE_CONVEX_PIECE,
HK_SHAPE_MULTI_SPHERE,
HK_SHAPE_CONVEX_LIST,
HK_SHAPE_TRIANGLE_COLLECTION,
HK_SHAPE_MULTI_RAY,
HK_SHAPE_HEIGHT_FIELD,
HK_SHAPE_SPHERE_REP,
HK_SHAPE_BV,
HK_SHAPE_PLANE,
HK_SHAPE_PHANTOM_CALLBACK,
HK_SHAPE_USER0,
HK_SHAPE_USER1,
HK_SHAPE_USER2,
HK_SHAPE_MAX_ID,
HK_SHAPE_ALL=-1
};
#include "../../../../../../../include/hkpBufferSize.h"
typedef __declspec(align(16))char hkpShapeBuffer[HK_SHAPE_BUFFER_SIZE];
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpShapeContainer;
class hkSphere;
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape_:public hkReferencedObject_
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape_(hkpShapeType type);
virtual hkReal getMaximumProjection(const hkVector4_&direction)const;
virtual const hkpShapeContainer*GetShapeContainer()const{return 0;}
virtual bool isConvex()const{return false;}
struct PhysicsShape
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(hkpShape_::PhysicsShape));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
bool m_bIsConvex;
bool m_bIsConvexPiece;
bool m_bIsComposite;
};
virtual int CalcSizeForSpu(const PhysicsShape&input,int spuBufferSizeLeft)const;
protected:
virtual void CalculateAabb(const hkTransform_&localToWorld,hkReal tolerance,hkAabb&out)const=0;
virtual hkBoolR IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const=0;
virtual void CastRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const=0;
virtual Vector4Comparison CastRayBundle(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask)const;
public:
static void __cdecl resetShapeFunctions();
typedef void(__cdecl*GetSupportingVertexFunc)(const void*thisObj,hkVector4Parameter direction,Vector4WithInt24W&supportVertex);
typedef void(__cdecl*ConvertVertexIdsToVerticesFunc)(const void*thisObj,const hkpVertexId*ids,int numIds,class Vector4WithInt24W*verticesOut);
typedef int(__cdecl*WeldContactPointFunc)(const void*thisObj,hkpVertexId*featurePoints,hkUint8&numFeaturePoints,hkVector4_&contactPointWs,const hkTransform_*thisObjTransform,const hkpConvexShape*collidingShape,const hkTransform_*collidingTransform,hkVector4_&separatingNormalInOut);
typedef void(__cdecl*GetCentreFunc)(const void*thisObj,hkVector4_&centreOut);
typedef int(__cdecl*GetNumCollisionSpheresFunc)(const void*thisObj);
typedef const hkSphere*(__cdecl*GetCollisionSpheresFunc)(const void*thisObj,hkSphere*sphereBuffer);
typedef void(__cdecl*GetAabbFunc)(const void*thisObj,const hkTransform_&localToWorld,hkReal tolerance,hkAabb&out);
typedef hkBoolR(__cdecl*CastRayFunc)(const void*thisObj,const ShapeRayCastQuery&input,ShapeRayCastOutput&output);
typedef void(__cdecl*CastRayWithCollectorFunc)(const void*thisObj,const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector);
typedef Vector4Comparison(__cdecl*CastRayBundleFunc)(const void*thisObj,const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask);
typedef const hkpShape_*(__cdecl*GetChildShapeFunc)(const void*thisObj,hkpShapeKey key,hkpShapeBuffer&buffer);
typedef hkUint32(__cdecl*GetCollisionFilterInfoFunc)(const void*thisObj,hkpShapeKey key);
struct ShapeCallbackDispatchTable
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(hkpShape_::ShapeCallbackDispatchTable));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkPadSpu<GetSupportingVertexFunc>m_kGetSupportingVertexFunction;
hkPadSpu<ConvertVertexIdsToVerticesFunc>m_kConvertVertexIdsToVerticesFunction;
hkPadSpu<WeldContactPointFunc>m_kWeldContactPointFunction;
hkPadSpu<GetCentreFunc>m_kGetCentreFunction;
hkPadSpu<GetNumCollisionSpheresFunc>m_kGetNumCollisionSpheresFunction;
hkPadSpu<GetCollisionSpheresFunc>m_kGetCollisionSpheresFunction;
hkPadSpu<GetAabbFunc>m_kGetAabbFunction;
hkPadSpu<CastRayFunc>m_kCastRayFunction;
hkPadSpu<CastRayWithCollectorFunc>m_kCastRayWithCollectorFunction;
hkPadSpu<CastRayBundleFunc>m_kCastRayBundleFunction;
hkPadSpu<GetChildShapeFunc>m_kGetChildShapeFunction;
hkPadSpu<GetCollisionFilterInfoFunc>m_kGetCollisionFilterInfoFunction;
void reset();
};
public:
public:
hkUlong m_ulUserData;
public:
hkEnum<::hkpShapeType,hkUint32>m_type;
public:
hkpShape_(class FinishingFlag flag):hkReferencedObject_(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_INVALID;
}
}
};struct RayCastHitResult
{
inline RayCastHitResult();
inline void reset();
hkVector4_ m_vHitNormal;
hkReal m_fHitFraction;
int m_iExtraInfo;};
void RayCastHitResult::reset()
{
m_fHitFraction=1.0f;
m_iExtraInfo=-1;
}
RayCastHitResult::RayCastHitResult()
{
reset();
}
struct ShapeRayCastOutput:public RayCastHitResult
{
public:
enum{MAX_HIERARCHY_DEPTH=8};
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline ShapeRayCastOutput();
private:
__forceinline void _reset();
public:
hkpShapeKey m_uiShapeKeys[MAX_HIERARCHY_DEPTH];
private:
int m_uiShapeKeyIndex;};
void ShapeRayCastOutput::_reset()
{
m_uiShapeKeyIndex=0;
m_uiShapeKeys[0]=0xffffffff;
}
ShapeRayCastOutput::ShapeRayCastOutput()
{
_reset();
}
union hkIntUnion64
{
hkQuadReal quad;
hkInt64 i64;
hkUint64 u64;
hkInt32 i32[2];
hkUint32 u32[2];
hkInt16 i16[4];
hkUint16 u16[4];
hkInt8 i8[8];
hkUint8 u8[8];
};
namespace hkVector4Util_S
{
__forceinline void __cdecl convertToUint16(const hkVector4_&in,const hkVector4_&offset,const hkVector4_&scale,hkIntUnion64&out);}
inline void __cdecl hkVector4Util_S::convertToUint16(const hkVector4_&in,const hkVector4_&offset,const hkVector4_&scale,hkIntUnion64&out)
{
static hkQuadReal magicQuad={hkReal(0x30000),hkReal(0x30000),hkReal(0x30000),hkReal(0x30000)};
hkVector4_ x,magic;
x.setAdd4(in,offset);
x.mul4(scale);
magic.getQuad()=magicQuad;
x.add4(magic);
union
{
hkQuadReal q;
hkUint32 i[4];
}u;
u.q=x.getQuad();
out.i16[0]=static_cast<hkInt16>(u.i[0]>>6);
out.i16[2]=static_cast<hkInt16>(u.i[2]>>6);}
struct ShapeRayCastQuery
{
hkVector4_ m_vFrom;
hkVector4_ m_vTo;};
class hkpHeightFieldShape_:public hkpShape_
{
public:
static const struct ClassMemberDescriptor Members[];
struct CollisionSphereData
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(hkpHeightFieldShape_::CollisionSphereData));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
class hkSphere*m_kSpheres;
int m_iSphereCount;
hkReal m_fScalar;
};
typedef hkVector4_ SphereCollisionOutput;
struct SphereRayCastQuery:public ShapeRayCastQuery
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(hkpHeightFieldShape_::SphereRayCastQuery));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkReal m_fSphereRadius;
hkReal m_fMaxExtraPenetration;
};
public:
hkpHeightFieldShape_(hkpShapeType type):hkpShape_(type){}
public:
hkpHeightFieldShape_(FinishingFlag flag):hkpShape_(flag){m_type=HK_SHAPE_HEIGHT_FIELD;}
};
class ShapeScaleVector
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}public:
hkVector4_ m_vScale;};
class SampledHeightRayCastView:public hkpHeightFieldShape_
{
public:
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
enum HeightFieldType
{
HEIGHTFIELD_STORAGE=0,
HEIGHTFIELD_COMPRESSED,
HEIGHTFIELD_USER,
HEIGHTFIELD_MAX_ID
};
SampledHeightRayCastView(const ShapeScaleVector&ci,HeightFieldType type=HEIGHTFIELD_USER);
virtual ~SampledHeightRayCastView();
void GetHeightFieldCinfo(ShapeScaleVector&cinfo)const;
virtual void CalculateAabb(const hkTransform_&localToWorld,hkReal tolerance,hkAabb&out)const;
virtual void CollideSpheres(const CollisionSphereData&input,SphereCollisionOutput*outputArray)const=0;
virtual void CastSphere(const SphereRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const;
__forceinline hkReal getHeightAt(int x,int z)const;
__forceinline hkBoolR getTriangleFlip()const;
virtual hkReal GetHeightAtGridPoint(int x,int z)const=0;
virtual hkBoolR IsTriangleWindingFlipped()const=0;
static void __cdecl registerSimulationFunctions(ShapeCallbackDispatchTable&sf);
static void __cdecl registerCollideQueryFunctions(ShapeCallbackDispatchTable&sf);
static void __cdecl registerRayCastFunctions(ShapeCallbackDispatchTable&sf);
static void __cdecl registerHeightFieldFunctions();
virtual hkBoolR IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const;
virtual void CastRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const;
public:
void hkpSampledHeightFieldShape_castRayInternal(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkBoolR reportPenetratingStartPosition,hkReal maxExtraPenetration,hkpRayHitCollector&collector)const;
__forceinline void _getHeightAndNormalAt(int xPos,int zPos,hkReal subX,hkReal subZ,hkVector4_&normalOut,hkReal&heightOut,int&triangleIndexOut)const;
public:
void GetHeightAndNormalAt(int xPos,int zPos,hkReal subX,hkReal subZ,hkVector4_&normalOut,hkReal&heightOut,int&triangleIndexOut)const;
public:
int m_iXResolution;
int m_iZResolution;
hkReal m_fHeightScale;
hkBoolR m_bUseProjectionBasedHeight;
hkEnum<HeightFieldType,hkUint8>m_ucHeightFieldType;
hkVector4_ m_kHeightScaleVector;
hkVector4_ m_kInverseScale;
hkVector4_ m_kOffset;
hkVector4_ SetCenterPosition;
public:
SampledHeightRayCastView():hkpHeightFieldShape_(HK_SHAPE_SAMPLED_HEIGHT_FIELD){}
SampledHeightRayCastView(FinishingFlag flag):hkpHeightFieldShape_(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_SAMPLED_HEIGHT_FIELD;
}
}
};
__forceinline hkReal SampledHeightRayCastView::getHeightAt(int x,int z)const
{
return GetHeightAtGridPoint(x,z);
}
__forceinline hkBoolR SampledHeightRayCastView::getTriangleFlip()const
{
return IsTriangleWindingFlipped();
}
__forceinline void SampledHeightRayCastView::_getHeightAndNormalAt(int x,int z,hkReal subX,hkReal subZ,hkVector4_&normalOut,hkReal&heightOut,int&triangleIndexOut)const
{
normalOut.setAll3(1.0f);
if(getTriangleFlip())
{
hkReal h00=getHeightAt(x,z);
hkReal h11=getHeightAt(x+1,z+1);
if(subX>subZ)
{
hkReal h10=getHeightAt(x+1,z);
hkReal dx=h10-h00;
hkReal dz=h11-h10;
heightOut=subZ*dz+h00+subX*dx;
normalOut(0)=-dx;
normalOut(2)=-dz;
triangleIndexOut=1;
}
else
{
hkReal h01=getHeightAt(x,z+1);
hkReal dx=h11-h01;
hkReal dz=h01-h00;
heightOut=subZ*dz+h00+subX*dx;
normalOut(0)=-dx;
normalOut(2)=-dz;
triangleIndexOut=0;
}
}
else
{
hkReal h10=getHeightAt(x+1,z);
hkReal h01=getHeightAt(x,z+1);
if(subX+subZ>1.0f)
{
hkReal h11=getHeightAt(x+1,z+1);
hkReal dx=h11-h01;
hkReal dz=h11-h10;
heightOut=subZ*dz+h10+(subX-1.0f)*dx;
normalOut(0)=-dx;
normalOut(2)=-dz;
triangleIndexOut=1;
}
else
{
hkReal h00=getHeightAt(x,z);
hkReal dx=h10-h00;
hkReal dz=h01-h00;
heightOut=subZ*dz+h00+subX*dx;
normalOut(0)=-dx;
normalOut(2)=-dz;
triangleIndexOut=0;
}
}
}
// @fnv 0x00d24b50
// src: XBOX_PDB 0x00d24b50
void SampledHeightRayCastView::hkpSampledHeightFieldShape_castRayInternal(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkBoolR reportPenetratingStartPosition,hkReal maxExtraPenetration,hkpRayHitCollector&collector)const
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "rcHeightFild";h->setTime();mStream.setEnd((char*)(h+1));}};
hkIntUnion64 intFrom;
hkVector4Util_S::convertToUint16(input.m_vFrom,m_kOffset,m_kInverseScale,intFrom);
int ep[3];
ep[0]=intFrom.i16[0];
ep[2]=intFrom.i16[2];
hkVector4_ from;from.setMul4(input.m_vFrom,m_kInverseScale);
hkVector4_ to;to.setMul4(input.m_vTo,m_kInverseScale);
hkBoolR triangleFlip=getTriangleFlip();
from(3)=from(1);
to(3)=to(1);
if(!triangleFlip)
{
from(1)=from(0)+from(2);
to(1)=to(0)+to(2);
}
else
{
from(1)=from(0)-from(2);
to(1)=to(0)-to(2);
}
hkVector4_ absRayDir;
hkVector4_ gridLineDistance;
hkVector4_ signedGridLineDistance;
int signRayDir[3];
float distToNextCell[3];
for(int i=0;i<3;i++)
{
float delta=to(i)-from(i);
float fabsDelta=MathUtilities::fabs(delta);
absRayDir(i)=fabsDelta;
if(fabsDelta<3.0517578125e-5f)
{
gridLineDistance(i)=0.0f;
signRayDir[i]=-1;
distToNextCell[i]=3.40282e+38f;
continue;
}
float invDelta=1.0f / delta;
signedGridLineDistance(i)=invDelta;
if(delta<0.0f)
{
signRayDir[i]=-1;
gridLineDistance(i)=-invDelta;
}
else
{
signRayDir[i]=1;
ep[i]=ep[i]+1;
gridLineDistance(i)=invDelta;
}
distToNextCell[i]=(ep[i]-from(i))*invDelta;
}
if(gridLineDistance(0)+gridLineDistance(2)==0 || gridLineDistance(0)+gridLineDistance(1)==0 || gridLineDistance(1)+gridLineDistance(2)==0)
{
int ix=ep[0];
int iz=ep[2];
if((unsigned)ix>=(unsigned)(m_iXResolution-1)||(unsigned)iz>=(unsigned)(m_iZResolution-1))
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
ShapeRayCastOutput output;
hkReal fieldHeight;
int triangleIndexOut;
_getHeightAndNormalAt(ix,iz,from(0)-ix,from(2)-iz,output.m_vHitNormal,fieldHeight,triangleIndexOut);
const hkReal h0=from(3)-fieldHeight;
const hkReal h1=to(3)-fieldHeight;
if(h1>h0)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
hkReal hitFraction;
if(reportPenetratingStartPosition&&h0<0.0f)
{
if(h1>h0-maxExtraPenetration)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
hitFraction=0.0f;
}
else
{
if(h0<0.0f || h1>=0.0f)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
hitFraction=h0 /(h0-h1);
}
if(hitFraction<collector.m_fEarlyOutHitFraction)
{
output.m_vHitNormal.mul4(m_kInverseScale);
output.m_vHitNormal.normalize3();
output.m_fHitFraction=hitFraction;
output.m_iExtraInfo=(iz<<16)+triangleIndexOut+ix*2;
collector.CollectRayHit(cdBody,output);
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
hkVector4_ clippedFrom=from;
int origEp0=ep[0];
int origEp2=ep[2];
while(true)
{
float ratio;
if(signRayDir[0]>0)
{
if(ep[0]>0){break;}
if(to(0)<0.0f)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
ratio=-from(0)*gridLineDistance(0);
ep[0]=1;
}
else
{
if(ep[0]<=m_iXResolution-2){break;}
const hkReal maxVal=hkReal(m_iXResolution-1);
if(to(0)>maxVal)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
ratio=(from(0)-maxVal)*gridLineDistance(0);
ep[0]=m_iXResolution-2;
}
distToNextCell[0]=ratio+gridLineDistance(0);
clippedFrom.setInterpolate4(from,to,ratio);
ep[2]=origEp2+MathUtilities::hkToIntFast(ratio*absRayDir(2))*signRayDir[2]-2;
while(clippedFrom(2)>=hkReal(ep[2]))
{
ep[2]=ep[2]+1;
}
ep[2]=ep[2]+(signRayDir[2]>>1);
if(gridLineDistance(2)!=0.0f)
{
distToNextCell[2]=(ep[2]-from(2))*signedGridLineDistance(2);
}
break;
}
while(true)
{
float ratio;
if(signRayDir[2]>0)
{
if(ep[2]>0){break;}
if(to(2)<0.0f)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
ratio=-from(2)*gridLineDistance(2);
ep[2]=1;
}
else
{
if(ep[2]<=m_iZResolution-2){break;}
const hkReal maxVal=hkReal(m_iZResolution-1);
if(to(2)>maxVal)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
ratio=(from(2)-maxVal)*gridLineDistance(2);
ep[2]=m_iZResolution-2;
}
distToNextCell[2]=ratio+gridLineDistance(2);
clippedFrom.setInterpolate4(from,to,ratio);
ep[0]=origEp0+MathUtilities::hkToIntFast(ratio*absRayDir(0))*signRayDir[0]-2;
while(clippedFrom(0)>=hkReal(ep[0]))
{
ep[0]=ep[0]+1;
}
ep[0]=ep[0]+(signRayDir[0]>>1);
if(gridLineDistance(0)!=0.0f)
{
distToNextCell[0]=(ep[0]-from(0))*signedGridLineDistance(0);
}
break;
}
if((unsigned)ep[0]>=(unsigned)m_iXResolution)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
int x=ep[0]-signRayDir[0];
if((unsigned)x>=(unsigned)m_iXResolution)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
hkBoolR diagDir=((signRayDir[0]^ signRayDir[2])>=0)^ triangleFlip;
if(gridLineDistance(1)==0.0f)
{
diagDir=false;
}
int inMoreDistantTriangle=2;
ep[1]=!triangleFlip ? ep[0]+ep[2]:ep[0]-ep[2];
{
float subPos=clippedFrom(1)-ep[1];
if(diagDir)
{
if(MathUtilities::fabs(subPos)>1.0f)
{
ep[1]=ep[1]-signRayDir[1];
}
else
{
inMoreDistantTriangle ^=2;
}
}
else
{
subPos=signRayDir[1]*subPos;
if(subPos>0.0f)
{
inMoreDistantTriangle ^=2;
ep[1]=ep[1]+signRayDir[1];
}
}
}
if(gridLineDistance(1)!=0.0f)
{
distToNextCell[1]=(ep[1]-from(1))*gridLineDistance(1)*signRayDir[1];
}
else
{
distToNextCell[1]=3.40282e+38f;
}
float distToPrevCell[3];
for(int i=0;i<3;i++)
{
if(gridLineDistance(i)==0.0f)
{
distToPrevCell[i]=-3.40282e+38f;
continue;
}
float cd=distToNextCell[i]-gridLineDistance(i);
distToPrevCell[i]=cd;
}
int backWalkingDir;
if(diagDir)
{
backWalkingDir=(inMoreDistantTriangle==0)? 1:(distToPrevCell[0]>distToPrevCell[2]? 0:2);
}
else if(absRayDir(0)<absRayDir(2))
{
backWalkingDir=inMoreDistantTriangle ? 2:(distToPrevCell[0]>distToPrevCell[1]? 0:1);
}
else
{
backWalkingDir=inMoreDistantTriangle ? 0:(distToPrevCell[1]>distToPrevCell[2]? 1:2);
}
ep[backWalkingDir]-=signRayDir[backWalkingDir];
distToNextCell[backWalkingDir]-=gridLineDistance(backWalkingDir);
hkReal lastFieldHeight=3.40282e+38f;
hkReal lastRayHeight=0.0f;
hkReal distToLastCrossedCell=-1.0f;
int sInd=backWalkingDir;
goto examineCrossedGridBorder;
while(true)
{
if(diagDir)
{
sInd=(inMoreDistantTriangle==0)? 1:(distToNextCell[0]<distToNextCell[2]? 0:2);
}
else if(absRayDir(0)<absRayDir(2))
{
sInd=inMoreDistantTriangle ? 2:(distToNextCell[0]<distToNextCell[1]? 0:1);
}
else
{
sInd=inMoreDistantTriangle ? 0:(distToNextCell[1]<distToNextCell[2]? 1:2);
}
examineCrossedGridBorder:
if((unsigned)ep[0]>=(unsigned)m_iXResolution ||(unsigned)ep[2]>=(unsigned)m_iZResolution)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
if(distToLastCrossedCell>collector.m_fEarlyOutHitFraction)
{
break;
}
const hkReal fraction=distToNextCell[sInd];
hkReal hitFraction;
hkReal rayHeight;
int triangleIndex;
hkReal fieldHeight;
{
hkVector4_ curPos;
curPos.setInterpolate4(from,to,fraction);
int x0=ep[0];
int x1=ep[0]-signRayDir[0];
int z0=ep[2];
if(sInd==0)
{
int z1=ep[2]-signRayDir[2];
hkReal h0=getHeightAt(x0,z1);
hkReal h1=getHeightAt(x0,z0);
hkReal frac=MathUtilities::fabs(curPos(2)-ep[2]);
fieldHeight=(h0-h1)*frac+h1;
}
else if(sInd==2)
{
hkReal h0=getHeightAt(x1,z0);
hkReal h1=getHeightAt(x0,z0);
hkReal frac=MathUtilities::fabs(curPos(0)-ep[0]);
fieldHeight=(h0-h1)*frac+h1;
}
else
{
int z1=z0;
hkReal frac=MathUtilities::fabs(curPos(0)-ep[0]);
if(diagDir)
{
z1=z1-signRayDir[2];
}
else
{
z0=z0-signRayDir[2];
}
hkReal h0=getHeightAt(x1,z0);
hkReal h1=getHeightAt(x0,z1);
fieldHeight=(h0-h1)*frac+h1;
}
rayHeight=curPos(3);
}
if(reportPenetratingStartPosition)
{
if(rayHeight>=fieldHeight)
{
goto setAndWalk;
}
{
const hkReal height=rayHeight-fieldHeight;
const hkReal lastHeight=lastRayHeight-lastFieldHeight;
const hkReal cellFraction=fraction-distToLastCrossedCell;
if(height>=lastHeight-cellFraction*maxExtraPenetration)
{
goto setAndWalk;
}
if(lastHeight<=0.0f)
{
hitFraction=MathUtilities::max2(0.0f,distToLastCrossedCell);
goto reportHit;
}
}
}
else
{
if(rayHeight>=fieldHeight || lastRayHeight<lastFieldHeight)
{
setAndWalk:
lastFieldHeight=fieldHeight;
lastRayHeight=rayHeight;
distToLastCrossedCell=fraction;
goto walk;
}
}
{
const hkReal height=rayHeight-fieldHeight;
if(distToLastCrossedCell>=0.0f)
{
const hkReal lastHeight=lastRayHeight-lastFieldHeight;
const hkReal subFraction=lastHeight /(lastHeight-height);
hitFraction=(fraction-distToLastCrossedCell)*subFraction+distToLastCrossedCell;
}
else
{
const hkReal f=fraction /(fraction-distToLastCrossedCell);
const hkReal startFieldHeight=lastFieldHeight*f+(1.0f-f)*fieldHeight;
hkReal lastHeight=from(3)-startFieldHeight;
if(lastHeight<0.0f)
{
if(!reportPenetratingStartPosition)
{
goto setAndWalk;
}
lastHeight=0.0f;
}
const hkReal subFraction=lastHeight /(lastHeight-height);
hitFraction=fraction*subFraction;
}
}
reportHit:
lastFieldHeight=fieldHeight;
lastRayHeight=rayHeight;
distToLastCrossedCell=fraction;
if(hitFraction>collector.m_fEarlyOutHitFraction)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
{
ShapeRayCastOutput output;
output.m_vHitNormal(3)=0.0f;
output.m_vHitNormal(1)=1.0f;
{
int x0=ep[0];
int x1=ep[0]-signRayDir[0];
int z0=ep[2];
int z1=ep[2]-signRayDir[2];
if(diagDir)
{
hkReal h0=getHeightAt(x0,z1);
hkReal h1=getHeightAt(x1,z0);
if(sInd==1)
{
hkReal h2=getHeightAt(x1,z1);
output.m_vHitNormal(0)=h2-h0;
output.m_vHitNormal(2)=h2-h1;
triangleIndex=(z1>z0)^ triangleFlip;
}
else
{
hkReal h2=getHeightAt(x0,z0);
output.m_vHitNormal(0)=h1-h2;
output.m_vHitNormal(2)=h0-h2;
triangleIndex=(z0>z1)^ triangleFlip;
}
}
else
{
hkReal h0=getHeightAt(x1,z1);
hkReal h1=getHeightAt(x0,z0);
if(sInd==0 ||(sInd==1&&absRayDir(0)<absRayDir(2)))
{
hkReal h2=getHeightAt(x0,z1);
output.m_vHitNormal(0)=h0-h2;
output.m_vHitNormal(2)=h2-h1;
triangleIndex=(z1>z0)^ triangleFlip;
}
else
{
hkReal h2=getHeightAt(x1,z0);
output.m_vHitNormal(0)=h2-h1;
output.m_vHitNormal(2)=h0-h2;
triangleIndex=(z0>z1)^ triangleFlip;
}
}
}
output.m_vHitNormal(0)*=signRayDir[0];
output.m_vHitNormal(2)*=signRayDir[2];
output.m_vHitNormal.mul4(m_kInverseScale);
output.m_vHitNormal.normalize3();
output.m_fHitFraction=hitFraction;
{
int ix=ep[0]-(signRayDir[0]>>1)-1;
int iz=ep[2]-(signRayDir[2]>>1)-1;
output.m_iExtraInfo=(iz<<16)+triangleIndex+ix*2;
}
collector.CollectRayHit(cdBody,output);
if(reportPenetratingStartPosition)
{
reportPenetratingStartPosition=false;
}
}
walk:
inMoreDistantTriangle ^=2;
ep[sInd]+=signRayDir[sInd];
distToNextCell[sInd]+=gridLineDistance(sInd);
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}
