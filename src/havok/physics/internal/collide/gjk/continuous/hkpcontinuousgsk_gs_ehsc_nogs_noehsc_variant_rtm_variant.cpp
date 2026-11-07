
// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkpAgent3Input.h"
#include <math.h>
#include "../../../../../../../include/hkpGskStatus.h"
#include <string.h>
#include <xmmintrin.h>
#include "../../../../../../../include/FinishingFlag.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/QuantizedFloat8.h"
#include "../../../../../../../include/hkStackMemory.h"
#define FNV64_HKVECTOR4_OWN_COPY
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkQuaternion.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkContactPointMaterial.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkpSphereRepShape.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkSphere.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpContactMgr.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkSweptTransform.h"
#include "../../../../../../../include/hkMotionState.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkStepInfo.h"

inline QuantizedFloat8::QuantizedFloat8() {}
inline hkContactPointMaterial::hkContactPointMaterial() {}
// Read SIMD lanes directly so this unit also works with declaration-only headers.
static __forceinline __m128 scalarBroadcast(const hkSimdReal& value)
{
    return _mm_shuffle_ps(value.m_vValue, value.m_vValue, 0);
}
static __forceinline float scalarReal(const hkSimdReal& value)
{
    float scalar;
    _mm_store_ss(&scalar, value.m_vValue);
    return scalar;
}
// Avoid ambiguous value/reference constructors in the shared SIMD declaration.
static __forceinline hkSimdReal scalarValue(const __m128& value)
{
    return reinterpret_cast<const hkSimdReal&>(value);
}
static __forceinline hkSimdReal scalarValue(float value)
{
    return scalarValue(_mm_load_ss(&value));
}
__forceinline void* hkStackMemory::allocateStack(int numBytes, const char* what)
{
    void* current = m_next;
    m_next = static_cast<char*>(current) + numBytes;
    return current;
}
inline void hkStackMemory::deallocateStack(void* p) { m_next = p; }
inline hkpShapeType hkpShape::getType() const
{
    return *reinterpret_cast<const hkpShapeType*>(&m_type);
}
// Keep the original virtual dispatch for the shared wrapper declarations.
__forceinline hkpContactMgr::ToiAccept hkpContactMgr::addToi(
    const hkpCdBody& a, const hkpCdBody& b, const GskAgentInput& input, WorldOperationEntry& output,
    hkTime toi, hkContactPoint& cp, const ConvexFeaturePairCache* cache,
    hkReal& projectedVelocity, PhysicsMaterial& properties)
{
    typedef ToiAccept (__thiscall *Call)(hkpContactMgr*, const hkpCdBody&, const hkpCdBody&,
        const GskAgentInput&, WorldOperationEntry&, hkTime, hkContactPoint&,
        const ConvexFeaturePairCache*, hkReal&, PhysicsMaterial&);
    return reinterpret_cast<Call>((*reinterpret_cast<void* const* const*>(this))[7])(
        this, a, b, input, output, toi, cp, cache, projectedVelocity, properties);
}
__forceinline void hkpContactMgr::removeToi(hkpConstraintOwner& owner, PhysicsMaterial& properties)
{
    typedef void (__thiscall *Call)(hkpContactMgr*, hkpConstraintOwner&, PhysicsMaterial&);
    reinterpret_cast<Call>((*reinterpret_cast<void* const* const*>(this))[8])(this, owner, properties);
}
struct SweepObj
{
    void* unk00;
    void* unk04;
    hkVector4* m_items;
    int m_uiItemCount;
    int unk10;
    int unk14;
    float m_18;
    float m_1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    float m_44;
    int unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    float m_80;
};
struct SweepOut
{
    float t;
    int unk04, unk08, unk0c;
    hkVector4 v;
};
struct SweepState
{
    hkVector4 r00, r10, r20, r30, r40, r50, r60, r70, r80, r90, ra0, rb0;
    hkVector4 n;   // c0
    hkVector4 o;   // d0
    hkVector4 c;   // e0
    hkVector4 a;   // f0
    hkVector4 b;   // 100
    hkVector4 oa;  // 110
    hkVector4 ob;  // 120
};
void __cdecl hkTransform_setMulInverseMul_UpdateState_00db4b50(SweepObj* obj, float t, SweepState* st);
float __cdecl Object_ProcessEntries_00db4ca0(SweepObj* obj, float* p, hkVector4* v, float a, float b, float c, float d, float e,
                           SweepOut* out);
static inline __m128 Cross(const __m128& a, const __m128& b)
{
    __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(c0, c1);
}
static inline __m128 Dot3(const __m128& a, const __m128& b)
{
    __m128 x2 = _mm_mul_ps(a, b);
    __m128 r = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), r);
}
static inline __m128 Dot4xyz1(const __m128& a, const __m128& b)
{
    __m128 xx = _mm_mul_ps(a, b);
    __m128 x2 = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0xaa), _mm_shuffle_ps(b, b, 0xff));
    __m128 x3 = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0x55), xx);
    return _mm_add_ps(x2, x3);
}
void __cdecl Object_ProcessEntries_00db4e40(SweepObj* obj, float* p, SweepOut* out);
// Adapted from the project's prior contributor draft of 24 October 2026.
// The same-file caller lets VC2008 reproduce the private register convention.
extern const __m128 DAT_010c44d0;
extern const __m128 DAT_010ec7f0;
extern const double DAT_010290f0;
static float HkpcontinuousgskGsEhscNogsNoehsc_ComputeValues_00db49b0(char* a, char* b, __m128* p, __m128* v0, __m128* v1, __m128* v2, float t);
__m128* volatile dbPlanes;
char* volatile dbBodyA;
char* volatile dbBodyB;
__m128* volatile dbPoint;
__m128* volatile dbDirection;
__m128* volatile dbVelocity;
volatile float dbTime;
volatile float dbResult;
void evaluatePlaneDistance();

extern "C" __declspec(align(16)) const unsigned int DAT_010c4c00[4];
extern "C" const float DAT_010d5384;
typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

typedef signed long __w64 hkLong;
#include "../../../../../../../include/hkResult.h"

typedef hkReal hkTime;
__forceinline hkLong __cdecl hkGetByteOffset(const void* base, const void* pntr)
{
    return hkLong(pntr) - hkLong(base);
}
template <typename TYPE> __forceinline TYPE* __cdecl hkAddByteOffset(TYPE* base, hkLong offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}
class hkClass;
typedef int hkBool32;
extern "C"
{
    extern const hkReal g_afRealLookupTable[256];
}

template <typename T> struct TypeSizeConstant
{
    enum
    {
        val = sizeof(T)
    };
};
template <typename TYPE> __forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0)
{
    hkMemoryRouter& mem = hkMemoryRouter::getInstance();
    return static_cast<TYPE*>(
        mem.stack().allocateStack((((n * TypeSizeConstant<TYPE>::val) + ((128) - 1)) & (~((128) - 1))), what));
}
template <typename TYPE> __forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
    hkMemoryRouter::getInstance().stack().deallocateStack(static_cast<void*>(ptr));
}
class hkStatisticsCollector;
#include "../../../../../../../include/hkArray.h"

;
typedef __m128 hkQuadReal;
typedef const hkSimdReal& hkSimdRealParameter;
namespace MathUtilities {
inline hkReal __cdecl fabs(hkReal r)
{
    return ::fabsf(r);
}
inline hkBool __cdecl equal(hkReal x, hkReal y, hkReal tolerance2 = 1e-5f)
{
    return MathUtilities::fabs(x - y) < tolerance2;
}
template <typename T> inline T __cdecl max2(T x, T y)
{
    return x > y ? x : y;
}
template <typename T> inline T __cdecl min2(T x, T y)
{
    return x < y ? x : y;
}
}
__forceinline void* __cdecl hkRotation::operator new(size_t nbytes)
{
    return hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
}
__forceinline const hkVector4& hkRotation::getColumn(int x) const
{
    return x == 0 ? m_kColumn0 : x == 1 ? m_kColumn1 : m_kColumn2;
}
// Preserve the original aggregate copy through the shared header's copy override.
__forceinline hkVector4::hkVector4(const hkVector4& v)
{
    memcpy(this, &v, sizeof(*this));
}
int hkVector4::getInt24W() const
{
    return (reinterpret_cast<const hkUint32*>(this))[3] & ~0x3f000000;
}
inline void hkVector4::setNeg3(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(*(const hkQuadReal*)&DAT_010c4c00, v.m_vComponents);
}
inline void hkVector4::setMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_mul_ps(scalarBroadcast(r), v1.m_vComponents);
}
inline void hkVector4::addMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(scalarBroadcast(r), v1.m_vComponents));
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(scalarBroadcast(r), b.m_vComponents));
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
}
inline void hkVector4::setCross(const hkVector4& v0, const hkVector4& v1)
{
    hkQuadReal cross0;
    cross0 =
        _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, (((3) << 6) | ((0) << 4) | ((2) << 2) | ((1)))),
                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, (((3) << 6) | ((1) << 4) | ((0) << 2) | ((2)))));
    hkQuadReal cross1;
    cross1 =
        _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, (((3) << 6) | ((1) << 4) | ((0) << 2) | ((2)))),
                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, (((3) << 6) | ((0) << 4) | ((2) << 2) | ((1)))));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
inline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter _t)
{
    hkQuadReal t = scalarBroadcast(_t);
    hkQuadReal s = _mm_sub_ps(DAT_010ec7f0, t);
    m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
}
inline void hkVector4::setNeg4(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
}
__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& b)
{
    hkQuadReal c0 = r.getColumn(0).m_vComponents;
    hkQuadReal c1 = r.getColumn(1).m_vComponents;
    hkQuadReal c2 = r.getColumn(2).m_vComponents;
    {
        hkQuadReal _tmp, _ctmp;
        _tmp = _mm_unpacklo_ps(c0, c1);
        _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, (((3) << 6) | ((2) << 4) | ((1) << 2) | ((0))));
        c0 = _mm_movelh_ps(_tmp, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, (((3) << 6) | ((1) << 4) | ((1) << 2) | ((0))));
        c2 = _ctmp;
    };
    const hkQuadReal b0 =
        _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((0) << 6) | ((0) << 4) | ((0) << 2) | ((0))));
    const hkQuadReal r0 = _mm_mul_ps(c0, b0);
    const hkQuadReal b1 =
        _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1))));
    const hkQuadReal r1 = _mm_mul_ps(c1, b1);
    const hkQuadReal b2 =
        _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2))));
    const hkQuadReal r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
inline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((0) << 6) | ((0) << 4) | ((0) << 2) | ((0))));
    hkQuadReal r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1))));
    hkQuadReal r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2))));
    hkQuadReal r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.getTranslation().m_vComponents));
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
    return scalarValue(_mm_add_ss(_mm_shuffle_ps(x2, x2, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))), xySum));
}
inline hkSimdReal hkVector4::length3() const
{
    return scalarValue(_mm_sqrt_ss(this->dot3(*this).m_vValue));
}
inline hkReal& hkVector4::operator()(int a)
{
    return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal& hkVector4::operator()(int a) const
{
    return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline hkSimdReal hkVector4::getSimdAt(int i) const
{
    switch (i)
    {
    case 0:
        return scalarValue(m_vComponents);
    case 1:
        return scalarValue(_mm_shuffle_ps(m_vComponents, m_vComponents, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))));
    case 2:
        return scalarValue(_mm_shuffle_ps(m_vComponents, m_vComponents, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))));
    case 3:
    default:
        return scalarValue(_mm_shuffle_ps(m_vComponents, m_vComponents, (((3) << 6) | ((3) << 4) | ((3) << 2) | ((3)))));
    }
}
inline void hkVector4::setBroadcast(const hkVector4& v, int i)
{
    if (i == 0)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((0) << 6) | ((0) << 4) | ((0) << 2) | ((0))));
    }
    else if (i == 3)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((3) << 6) | ((3) << 4) | ((3) << 2) | ((3))));
    }
}
inline void hkVector4::setRotatedInverseDir(const hkRotation& t, const hkVector4& v)
{
    _setRotatedInverseDir(t, v);
}
__forceinline hkTransform::hkTransform() {}
__forceinline const hkVector4& hkTransform::getTranslation() const
{
    return reinterpret_cast<const hkVector4&>(m_row3);
}
__forceinline hkRotation& hkTransform::getRotation()
{
    return reinterpret_cast<hkRotation&>(m_row0);
}
__forceinline const hkRotation& hkTransform::getRotation() const
{
    return reinterpret_cast<const hkRotation&>(m_row0);
}
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4 r0 = t.getRotation().getColumn(0);
    const hkVector4 r1 = t.getRotation().getColumn(1);
    const hkVector4 r2 = t.getRotation().getColumn(2);
    const hkVector4 r3 = t.getTranslation();
    getRotation().m_kColumn0 = r0;
    getRotation().m_kColumn1 = r1;
    getRotation().m_kColumn2 = r2;
    reinterpret_cast<hkVector4&>(m_row3) = r3;
}

__forceinline hkTime hkSweptTransform::getBaseTime() const
{
    return hkTime(m_vCenterOfMass0(3));
}
__forceinline hkReal hkSweptTransform::getInvDeltaTime() const
{
    return m_vCenterOfMass1(3);
}
__forceinline hkReal hkSweptTransform::getInterpolationValue(hkTime t) const
{
    ;
    hkReal dt = (t - getBaseTime()) * getInvDeltaTime();
    ;
    ;
    return dt;
}
class MemoryUtils
{
  public:
    enum ReplaceType
    {
        REPLACE_ONE,
        REPLACE_ALL
    };
    static __forceinline void __cdecl memClear16(void* dst, int numQuads);

  private:
    static void copyAndReplace(char* dest, const char* orig, int origLen, const MemoryUtils& from,
                               const MemoryUtils& to, const hkArray<int>& indices);
};
void __cdecl MemoryUtils::memClear16(void* dst, int numQuads)
{
    ;
    hkUint32* dst32 = reinterpret_cast<hkUint32*>(dst);
    {
        for (int i = 0; i < numQuads; i++)
        {
            dst32[0] = 0;
            dst32[1] = 0;
            dst32[2] = 0;
            dst32[3] = 0;
            dst32 += 4;
        }
    }
}
inline const hkSweptTransform& hkMotionState::getSweptTransform() const
{
    return m_kSweptTransform;
}
typedef hkUint16 hkContactPointId;
inline hkContactPoint& hkContactPoint::operator=(const hkContactPoint& other)
{
    m_vContactPosition = other.m_vContactPosition;
    m_vSeparatingNormal = other.m_vSeparatingNormal;
    return *this;
}
inline const hkVector4& hkContactPoint::getNormal() const
{
    return m_vSeparatingNormal;
}
inline hkVector4& hkContactPoint::getPosition()
{
    return m_vContactPosition;
}
inline hkVector4& hkContactPoint::getSeparatingNormal()
{
    return m_vSeparatingNormal;
}
inline void hkContactPoint::setSeparatingNormal(const hkVector4& separatingNormal)
{
    m_vSeparatingNormal = separatingNormal;
}
inline void hkContactPoint::setDistance(hkReal d)
{
    m_vSeparatingNormal(3) = d;
}
class Vector4WithInt24W : public hkVector4
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    int GetValueForType() const
    {
        return getInt24W();
    }
};
class hkpCollisionDispatcher;
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpRayHitCollector;
class hkpShapeContainer;
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
const hkMotionState* hkpCdBody::GetMotionState() const
{
    return static_cast<const hkMotionState*>(m_pMotionState);
}
const hkpShape* hkpCdBody::getShape() const
{
    return m_pCollisionShape;
}
struct GskAgentInput;
struct WorldOperationEntry;

struct AgentSubtypeMarker : public hkpAgent3Input
{
    hkPadSpu<hkReal> m_fSubtypeValue;
    hkVector4 m_vSubtypePosition;
};
#include "../../../../../../../include/hkpCollisionQualityInfo.h"
class hkpCollisionFilter;
class hkpConvexListFilter;
struct CollisionAgentContext
{
  public:
    hkReal getTolerance() const
    {
        return m_fScalar;
    }

  public:
    hkPadSpu<hkpCollisionDispatcher*> m_pCollisionDispatcher;
    hkPadSpu<hkReal> m_fScalar;
    hkPadSpu<const hkpCollisionFilter*> m_iFilter;
    hkPadSpu<const hkpConvexListFilter*> m_pConvexListCollisionFilter;
    mutable hkPadSpu<hkBool32> m_bCreatePredictiveAgents;
    struct AabbBoundsAndScale
    {
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                hkMemoryRouter::getInstance().heap().blockFree(
                    p, sizeof(CollisionAgentContext::AabbBoundsAndScale));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        hkVector4 m_kAabbMin;
        hkVector4 m_kAabbMaximum;
        hkVector4 m_kAabbScale;
    };
    AabbBoundsAndScale m_aiValues;
};
struct CollisionContactResults;
class ConvexFeaturePairCache;
class ContactImpulseInfo
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    inline ContactImpulseInfo();
    inline void init();

  public:
    hkReal m_fAccumulatedImpulse;
    hkReal m_fImpulseLimit;
};
inline void ContactImpulseInfo::init()
{
    m_fAccumulatedImpulse = 0.0f;
    m_fImpulseLimit = 0.0f;
}
inline ContactImpulseInfo::ContactImpulseInfo()
{
    init();
}
class PhysicsMaterial : public ContactImpulseInfo, public hkContactPointMaterial
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    hkReal m_uiUserData;
    typedef hkUint32 UserData;
};
__declspec(align(16)) class ContactDataPhysicsMaterial : public PhysicsMaterial
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    void set(const ContactDataPhysicsMaterial& other)
    {
        *this = other;
    }
    UserData m_aiContactData[7];
};
struct ContactPointWithId
{
    hkContactPoint m_kPoint;
    hkPadSpu<hkUint32> m_usContactPointId;
};
struct hkpAgent1nSector;
struct GskAgentInput : public CollisionAgentContext
{
  public:
    GskAgentInput() : m_pAgent1nSector(0)
    {}

  public:
    hkStepInfo m_pStepInfo;
    mutable hkPadSpu<hkpCollisionQualityInfo*> m_pCollisionQualityInfo;
    mutable hkpAgent1nSector* m_pAgent1nSector;
};
class ConvexFeaturePairCache
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    hkUint16 m_kVertices[4];

  public:
    void init(const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& btoa);
};
__declspec(align(16)) class HeapContactFeatureCache : public ConvexFeaturePairCache
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    void set(const HeapContactFeatureCache& other)
    {
        *this = other;
    }
};
enum
{
    HK_MAX_CONTACT_POINT = 256
};
struct FourByteState;
struct CollisionContactResults
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    inline hkBool hasToi() const;

  public:
    hkPadSpu<ContactPointWithId*> m_pAlignedPairData;
    hkPadSpu<hkpConstraintOwner*> m_pConstraintOwner;
    ContactPointWithId m_akContactPoints[HK_MAX_CONTACT_POINT];
    struct CollisionCacheState
    {
      public:
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                hkMemoryRouter::getInstance().heap().blockFree(
                    p, sizeof(CollisionContactResults::CollisionCacheState));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        inline CollisionCacheState();
        inline void flip();

      public:
        hkContactPoint m_vContactPoint;
        hkPadSpu<hkReal> m_uiCommandId;
        hkPadSpu<hkReal> m_fSeparation;
        HeapContactFeatureCache m_kGskCache;
        ContactDataPhysicsMaterial m_kProperties;
    };
    struct CollisionCacheState m_fTimeOfImpact;
};
inline hkBool CollisionContactResults::hasToi() const
{
    return m_fTimeOfImpact.m_uiCommandId != 3.40282e+38f;
}
struct WorldOperationEntry : public CollisionContactResults
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    struct ContactPointAgentEntry
    {
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                hkMemoryRouter::getInstance().heap().blockFree(
                    p, sizeof(WorldOperationEntry::ContactPointAgentEntry));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        ContactPointWithId* m_vContactPoint;
        FourByteState* m_pAgentEntry;
        void* m_pUserData;
    };
    struct ContactPointBuffer
    {
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                hkMemoryRouter::getInstance().heap().blockFree(
                    p, sizeof(WorldOperationEntry::ContactPointBuffer));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        void reset()
        {
            m_pFirstFreeContactPoint = &m_akContactRecords[0];
            m_ppFirstFreeContactPointer = &m_apContactPointPointers[0];
        }
        ContactPointAgentEntry* m_pFirstFreeContactPoint;
        ContactPointWithId** m_ppFirstFreeContactPointer;
        ContactPointWithId* m_apContactPointPointers[HK_MAX_CONTACT_POINT];
        ContactPointAgentEntry m_akContactRecords[HK_MAX_CONTACT_POINT];
    };

  public:
    hkPadSpu<ContactPointBuffer*> m_akContactRecords;
};
namespace MotionUtilities {
void __cdecl calcTransformFromSweptTransform(const hkSweptTransform& sweptTrans, hkTime t, hkReal tAddOn, hkTransform& transformOut);
__forceinline void __cdecl calcAngularTimInfo(const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime,
                                              hkVector4* deltaAngleOut0, hkVector4* deltaAngleOut1);
}
void __cdecl MotionUtilities::calcAngularTimInfo(const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime,
                                                 hkVector4* __restrict deltaAngleOut0,
                                                 hkVector4* __restrict deltaAngleOut1)
{
    const hkSweptTransform& st0 = ms0.getSweptTransform();
    const hkSweptTransform& st1 = ms1.getSweptTransform();
    hkReal f0 = deltaTime * st0.getInvDeltaTime();
    hkReal f1 = deltaTime * st1.getInvDeltaTime();
    hkVector4 ang0;
    ang0.setMul4(scalarValue(f0), ms0.m_kDeltaAngle);
    hkVector4 ang1;
    ang1.setMul4(scalarValue(f1), ms1.m_kDeltaAngle);
    deltaAngleOut0[0] = ang0;
    deltaAngleOut1[0] = ang1;
}
namespace hkVector4Util {
__forceinline void __cdecl TransformPointArray(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                               hkVector4* vectorsOut);
}
inline void __cdecl hkVector4Util::TransformPointArray(const hkTransform& t, const hkVector4* vectorsIn,
                                                        int numVectors, hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
// These shared wrappers dispatch through the original Havok virtual slots.
__forceinline int hkpSphereRepShape::getNumCollisionSpheres() const
{
    typedef int (__thiscall *Call)(const hkpSphereRepShape*);
    return reinterpret_cast<Call>((*reinterpret_cast<void* const* const*>(this))[11])(this);
}
__forceinline const hkSphere* hkpSphereRepShape::getCollisionSpheres(hkSphere* sphereBuffer) const
{
    typedef const hkSphere* (__thiscall *Call)(const hkpSphereRepShape*, hkSphere*);
    return reinterpret_cast<Call>((*reinterpret_cast<void* const* const*>(this))[12])(this, sphereBuffer);
}
__forceinline int hkpConvexShape::getNumCollisionSpheres() const
{
    return GetNumCollisionSpheres();
}
__forceinline const hkSphere* hkpConvexShape::getCollisionSpheres(hkSphere* sphereBuffer) const
{
    return GetCollisionSpheres(sphereBuffer);
}
__forceinline hkpConvexShape::WeldResult hkpConvexShape::weldContactPoint(
    hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4& contactPointWs,
    const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape,
    const hkTransform* collidingTransform, hkVector4& separatingNormalInOut) const
{
    return (WeldResult)this->WeldContactPoint(featurePoints, numFeaturePoints,
        contactPointWs, thisObjTransform, collidingShape, collidingTransform,
        separatingNormalInOut);
}

struct ContactPointWeldingParameters
{
    hkPadSpu<hkReal> m_fMinimumTimeOfImpactDelta;
    hkPadSpu<hkReal> m_fCreateContactThreshold;
    hkPadSpu<hkReal> m_fThirdContactParameter;
    hkPadSpu<hkReal> m_fMaximumAngularVelocity;
    hkPadSpu<hkReal> m_fMaximumConstraintViolation;
};
struct ConvexCollisionQueryData
{
    hkPadSpu<const hkMotionState*> m_pFirstQueryData;
    hkPadSpu<const hkMotionState*> m_pSecondQueryData;
    hkPadSpu<hkVector4*> m_akPackedVerticesA;
    hkPadSpu<int> m_iStridedVertexCount;
    hkPadSpu<int> m_iSecondPackedVertexCount;
    hkPadSpu<hkReal> m_kFourthBasisVector;
    hkPadSpu<hkReal> m_fSecondBasisScalar;
    hkPadSpu<hkReal> m_fThirdBasisScalar;
    hkVector4 m_vFirstStoredVector;
    hkVector4 m_vSecondStoredVector;
    hkPadSpu<const hkStepInfo*> m_pStepInfo;
    hkPadSpu<hkReal> m_fStepTimeParameter;
    hkVector4 m_vSubtypePosition;
    hkVector4 m_avSubtypeVectors[2];
    hkPadSpu<hkReal> m_fFinalQueryParameter;
};
struct ScalarVectorData
{
    ScalarVectorData()
    {
        m_fScale = 1.0f;
    }
    hkPadSpu<hkReal> m_fScale;
    hkVector4 m_vVector;
};
struct CollisionSolverInput
{
    hkTransform m_pTransformB;
    hkTransform m_pTransformA;
    hkTransform m_kTransform;
    hkVector4 m_kTriangleNormal;
    hkVector4 m_vContactNormal;
    hkVector4 m_vLinearVelocity;
    hkVector4 m_vAngularVelocity[2];
    hkVector4 m_vMassCenterA;
    hkVector4 m_vMassCenterB;
};
class ConvexShapePairCache
{
  public:
    hkpGskStatus GetClosestPoint(const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& aTb,
                                   hkVector4& separatingNormalOut);
    __forceinline void getClosestPointAinA(const hkVector4& separatingNormal, hkVector4& pointInA)
    {
        if (m_ucDimensionA == 1)
        {
            pointInA = m_akPackedVerticesA[0];
        }
        else if (m_ucDimensionB == 1)
        {
            pointInA = m_akCachedVectors[0];
            pointInA.addMul4(separatingNormal.getSimdAt(3), separatingNormal);
        }
        else
        {
            pointInA = m_kVectorPairResult[0];
        }
    }
    void WriteContactFeatureCache(ConvexFeaturePairCache& cache) const;
    hkPadSpu<int> m_ucDimensionA;
    hkPadSpu<int> m_ucDimensionB;
    hkPadSpu<int> m_ucFeatureTypeA;
    int m_unkA;
    int m_unkB;
    Vector4WithInt24W m_akPackedVerticesA[4];
    hkVector4 m_unkC0;
    hkVector4 m_unkC1;
    hkVector4 m_unkC2;
    hkVector4 m_unkC3;
    hkVector4 m_akCachedVectors[4];
    Vector4WithInt24W m_akPackedVerticesB[4];
    hkVector4 m_pSupport;
    hkVector4 m_kVectorPairResult[3];
};
extern "C" void FindSupportPoint(const Vector4WithInt24W* vA, const hkVector4* vBinA, int dimA, int dimB,
                                           const hkVector4* masterNormalA, hkVector4* pointBinAOut,
                                           hkVector4* supportOut);
extern "C" void hk4dGskCollidePointsWithPlane(const ConvexCollisionQueryData& input,
                                              const ContactPointWeldingParameters& tol, ScalarVectorData& out);
__forceinline void hk4dGskCollPInputInitialize(const AgentSubtypeMarker& in3,
                                               ConvexCollisionQueryData& collPInput)
{
    const hkpConvexShape* shapeA = (const hkpConvexShape*)in3.m_pBodyA->getShape();
    const hkpConvexShape* shapeB = (const hkpConvexShape*)in3.m_pBodyB->getShape();
    const hkMotionState* msA = in3.m_pBodyA->GetMotionState();
    const hkMotionState* msB = in3.m_pBodyB->GetMotionState();
    collPInput.m_pFirstQueryData = msA;
    collPInput.m_pSecondQueryData = msB;
    collPInput.m_kFourthBasisVector = shapeA->getRadius() + shapeB->getRadius();
    collPInput.m_vSubtypePosition = in3.m_vSubtypePosition;
    collPInput.m_pStepInfo = &reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val())->m_pStepInfo;
    int numSpheres = shapeA->getNumCollisionSpheres();
    collPInput.m_iSecondPackedVertexCount = numSpheres;
    collPInput.m_iStridedVertexCount = numSpheres;
    collPInput.m_akPackedVerticesA = hkAllocateStack<hkVector4>(numSpheres);
    shapeA->getCollisionSpheres((hkSphere*)collPInput.m_akPackedVerticesA.val());
    hkReal mA = msA->m_fObjectRadius * collPInput.m_avSubtypeVectors[0](3) * collPInput.m_avSubtypeVectors[0](3);
    hkReal mB = msB->m_fObjectRadius * collPInput.m_avSubtypeVectors[1](3) * collPInput.m_avSubtypeVectors[1](3);
    collPInput.m_fSecondBasisScalar = mA + mB;
    collPInput.m_fThirdBasisScalar = 1.0f / (collPInput.m_fSecondBasisScalar + 1.192092896e-07F);
}
__forceinline hkReal hk4dGskCalcPointVelocity(const hkMotionState* msA, const hkMotionState* msB,
                                              const hkVector4& separatingPoint, const hkVector4& separatingNormal,
                                              const hkVector4& linearTimInfo, const hkVector4* deltaAngles, hkReal t)
{
    hkVector4 relVel;
    relVel.setNeg4(linearTimInfo);
    {
        hkReal relT = msA->getSweptTransform().getInterpolationValue(t);
        hkVector4 massCenter;
        massCenter.setInterpolate4(msA->getSweptTransform().m_vCenterOfMass0, msA->getSweptTransform().m_vCenterOfMass1,
                                   scalarValue(relT));
        hkVector4 relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4 arm;
        arm.setCross(deltaAngles[0], relPos);
        relVel.add4(arm);
    }
    {
        hkReal relT = msB->getSweptTransform().getInterpolationValue(t);
        hkVector4 massCenter;
        massCenter.setInterpolate4(msB->getSweptTransform().m_vCenterOfMass0, msB->getSweptTransform().m_vCenterOfMass1,
                                   scalarValue(relT));
        hkVector4 relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4 arm;
        arm.setCross(deltaAngles[1], relPos);
        relVel.sub4(arm);
    }
    hkReal separatingVelocity = scalarReal(relVel.dot3(separatingNormal));
    return separatingVelocity;
}
static __declspec(noinline) hkReal
    CalcSeparatingVelocity(const hkMotionState* msA, const hkMotionState* msB,
                                                    const hkVector4& separatingPoint,
                                                    const hkVector4& separatingNormal, const hkVector4& linearTimInfo,
                                                    const hkVector4* deltaAngles, hkReal t)
{
    const float angularVelocityFactor = 1.2f;
    hkVector4 relVel;
    relVel.setNeg4(linearTimInfo);
    hkReal separatingVelocity = scalarReal(relVel.dot3(separatingNormal));
    {
        hkReal relT = msA->getSweptTransform().getInterpolationValue(t);
        hkVector4 massCenter;
        massCenter.setInterpolate4(msA->getSweptTransform().m_vCenterOfMass0, msA->getSweptTransform().m_vCenterOfMass1,
                                   scalarValue(relT));
        hkVector4 relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4 arm;
        arm.setCross(deltaAngles[0], relPos);
        hkReal angVelPart = scalarReal(arm.dot3(separatingNormal));
        if (angVelPart <= 0.0f)
        {
            separatingVelocity += angVelPart * angularVelocityFactor;
        }
        else
        {
            separatingVelocity += angVelPart / angularVelocityFactor;
        }
    }
    {
        hkReal relT = msB->getSweptTransform().getInterpolationValue(t);
        hkVector4 massCenter;
        massCenter.setInterpolate4(msB->getSweptTransform().m_vCenterOfMass0, msB->getSweptTransform().m_vCenterOfMass1,
                                   scalarValue(relT));
        hkVector4 relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4 arm;
        arm.setCross(deltaAngles[1], relPos);
        hkReal angVelPart = scalarReal(arm.dot3(separatingNormal));
        if (angVelPart >= 0.0f)
        {
            separatingVelocity -= angVelPart * angularVelocityFactor;
        }
        else
        {
            separatingVelocity -= angVelPart / angularVelocityFactor;
        }
    }
    return separatingVelocity;
}
__forceinline void hk4dGskCalcWorstCaseProjectedVelocity(const hkMotionState* msA, const hkMotionState* msB,
                                                         const hkVector4& separatingNormal,
                                                         const hkVector4& linearTimInfo, const hkVector4* deltaAngles,
                                                         hkReal& realProjectedLinearDelta,
                                                         hkReal& projectedAngularDelta)
{
    hkVector4 crossAngleA;
    crossAngleA.setCross(deltaAngles[0], separatingNormal);
    hkVector4 crossAngleB;
    crossAngleB.setCross(deltaAngles[1], separatingNormal);
    hkReal lenA = scalarReal(crossAngleA.length3()) * msA->m_fObjectRadius;
    hkReal lenB = scalarReal(crossAngleB.length3()) * msB->m_fObjectRadius;
    projectedAngularDelta = lenA + lenB;
    realProjectedLinearDelta = scalarReal(linearTimInfo.dot3(separatingNormal));
}
static __forceinline void hkGskRecalcContact(ConvexShapePairCache* gsk, const hkVector4* masterNormalA,
                                             hkVector4* pointBinAOut, hkVector4* supportOut)
{
    FindSupportPoint(gsk->m_akPackedVerticesA, gsk->m_akCachedVectors, gsk->m_ucDimensionA,
                               gsk->m_ucDimensionB, masterNormalA, pointBinAOut, supportOut);
}
// @fnv 0x00db54b0
// src: GUESS 0x00db54b0 (confidence: low)
static __declspec(noinline) void hkVector4_ProcessEntries_00db54b0(const AgentSubtypeMarker& in3, ContactPointWeldingParameters& tol,
                                              ConvexShapePairCache& gsk, int featureChange,
                                              const hkVector4& oldMasterNormal, const hkVector4* deltaAngles,
                                              hkReal startRt, hkReal endRt, hkReal distance0, hkReal distance1,
                                              WorldOperationEntry& out)
{
    CollisionSolverInput mat;
    hkReal Rt = startRt;
    hkReal distance = distance0;
    hkTransform wTa;
    hkTransform wTb;
    hkTransform aTb;
    const hkpConvexShape* shapeA = (const hkpConvexShape*)in3.m_pBodyA->getShape();
    const hkpConvexShape* shapeB = (const hkpConvexShape*)in3.m_pBodyB->getShape();
    hkReal radiusSum = shapeA->getRadius();
    radiusSum += shapeB->getRadius();
    hkReal velocityBasedOnDistance = (distance1 - distance0) / (endRt - startRt);
    hkVector4 normalA;
    hkVector4 pointA;
    for (int iteration = 0; iteration < 10; iteration++)
    {
        hkReal delta = distance1 - distance0;
        if (delta > -tol.m_fMaximumConstraintViolation)
        {
            endRt = startRt;
            delta = 0.5f;
        }
        hkBool earlyOut;
        if (MathUtilities::equal(distance1, tol.m_fMinimumTimeOfImpactDelta, tol.m_fMaximumConstraintViolation))
        {
            earlyOut = true;
            featureChange = 0;
            Rt = endRt;
        }
        else
        {
            earlyOut = false;
            hkReal rel = (tol.m_fMinimumTimeOfImpactDelta - distance0) / delta;
            rel = MathUtilities::max2(rel, 0.1f);
            rel = MathUtilities::min2(rel, 0.9f);
            Rt = (1.0f - rel) * startRt + endRt * rel;
        }
        const hkStepInfo* stepInfo = &reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val())->m_pStepInfo;
        hkReal timeAddon = stepInfo->m_fTimeStep * Rt;
        MotionUtilities::calcTransformFromSweptTransform(in3.m_pBodyA->GetMotionState()->getSweptTransform(), stepInfo->m_uiStartTime,
                                 timeAddon, wTa);
        MotionUtilities::calcTransformFromSweptTransform(in3.m_pBodyB->GetMotionState()->getSweptTransform(), stepInfo->m_uiStartTime,
                                 timeAddon, wTb);
        aTb.SetMulInverse(wTa, wTb);
        if (featureChange)
        {
            const hkpConvexShape* shapeA = (const hkpConvexShape*)in3.m_pBodyA->getShape();
            const hkpConvexShape* shapeB = (const hkpConvexShape*)in3.m_pBodyB->getShape();
            gsk.GetClosestPoint(shapeA, shapeB, aTb, normalA);
            gsk.getClosestPointAinA(normalA, pointA);
        }
        else
        {
            hkVector4Util::TransformPointArray(aTb, gsk.m_akPackedVerticesB, gsk.m_ucDimensionB,
                                                gsk.m_akCachedVectors);
            hkVector4 oldMasterNormalInA;
            oldMasterNormalInA.setRotatedInverseDir(wTa.getRotation(), oldMasterNormal);
            hkGskRecalcContact(&gsk, &oldMasterNormalInA, &pointA, &normalA);
        }
        distance = normalA(3) - radiusSum;
        if (MathUtilities::equal(distance, tol.m_fMinimumTimeOfImpactDelta, tol.m_fMaximumConstraintViolation) ||
            earlyOut)
        {
            break;
        }
        if (startRt == endRt)
        {
            break;
        }
        if (tol.m_fMinimumTimeOfImpactDelta > distance)
        {
            endRt = Rt;
            distance1 = distance;
        }
        else
        {
            startRt = Rt;
            distance0 = distance;
        }
    }
    const hkStepInfo* stepInfo = &reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val())->m_pStepInfo;
    hkReal deltaTime = MathUtilities::max2(stepInfo->m_fTimeStep.val() * Rt, tol.m_fMaximumAngularVelocity.val());
    hkReal toi = stepInfo->m_uiStartTime + deltaTime;
    ;
    ;
    if (toi < out.m_fTimeOfImpact.m_uiCommandId && stepInfo->m_fEndTime - tol.m_fMaximumAngularVelocity > toi)
    {
        HeapContactFeatureCache cache;
        hkReal separatingVelocity;
        const hkpConvexShape* shapeA = (const hkpConvexShape*)in3.m_pBodyA->getShape();
        hkpContactMgr::ToiAccept cbResult;
        __declspec(align(16)) char contactPointStorage[sizeof(hkContactPoint)];
        hkContactPoint& cp = *reinterpret_cast<hkContactPoint*>(contactPointStorage);
        {
            const hkMotionState* msA;
            hkVector4 pointWs;
            hkpConvexShape::WeldResult weldResult;
            const hkMotionState* msB;
            pointWs.SetTransformedPoint(wTa, pointA);
            cp.getSeparatingNormal().SetRotatedDirection(wTa.getRotation(), normalA);
            cp.getPosition().setAddMul4(pointWs, cp.getSeparatingNormal(), scalarValue(-shapeA->getRadius() - distance));
            cp.setDistance(distance);
            weldResult = hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED;
            hkVector4 weldedNormal = cp.getSeparatingNormal();
            if (in3.m_pBodyB->getShape()->getType() == HK_SHAPE_TRIANGLE)
            {
                {
                    hkpVertexId featurePoints[3];
                    hkUint8 numFeaturePoints;
                    const hkpConvexShape* shapeB;
                    numFeaturePoints = gsk.m_ucDimensionB;
                    featurePoints[0] = gsk.m_akPackedVerticesB[0].GetValueForType();
                    featurePoints[1] =
                        numFeaturePoints < 2 ? 0xffff : hkpVertexId(gsk.m_akPackedVerticesB[1].GetValueForType());
                    featurePoints[2] =
                        numFeaturePoints < 3 ? 0xffff : hkpVertexId(gsk.m_akPackedVerticesB[2].GetValueForType());
                    shapeB = (const hkpConvexShape*)in3.m_pBodyB->getShape();
                    weldResult = shapeB->weldContactPoint(featurePoints, numFeaturePoints, cp.getPosition(), &wTb,
                                                          shapeA, &wTa, weldedNormal);
                }
                cp.setSeparatingNormal(weldedNormal);
            EXAMINE_WELD_RESULTS:
                if (weldResult == hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT &&
                    reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val())->m_pCollisionQualityInfo->m_bEnableToiWeldRejection)
                {
                    return;
                }
            }
            else if (in3.m_pBodyA->getShape()->getType() == HK_SHAPE_TRIANGLE)
            {
                hkpVertexId featurePoints[3];
                hkUint8 numFeaturePoints;
                hkVector4 dist;
                hkVector4 pointOnA;
                const hkpConvexShape* shapeB;
                numFeaturePoints = gsk.m_ucDimensionA;
                featurePoints[0] = gsk.m_akPackedVerticesA[0].GetValueForType();
                featurePoints[1] =
                    numFeaturePoints < 2 ? 0xffff : hkpVertexId(gsk.m_akPackedVerticesA[1].GetValueForType());
                featurePoints[2] =
                    numFeaturePoints < 3 ? 0xffff : hkpVertexId(gsk.m_akPackedVerticesA[2].GetValueForType());
                dist.setBroadcast(weldedNormal, 3);
                pointOnA.setAddMul4(cp.getPosition(), weldedNormal, dist);
                weldedNormal.setNeg3(weldedNormal);
                shapeB = (const hkpConvexShape*)in3.m_pBodyB->getShape();
                weldResult = shapeA->weldContactPoint(featurePoints, numFeaturePoints, pointOnA, &wTa, shapeB, &wTb,
                                                      weldedNormal);
                weldedNormal.setNeg3(weldedNormal);
                cp.setSeparatingNormal(weldedNormal);
                goto EXAMINE_WELD_RESULTS;
            }
            msA = in3.m_pBodyA->GetMotionState();
            msB = in3.m_pBodyB->GetMotionState();
            separatingVelocity = hk4dGskCalcPointVelocity(msA, msB, cp.getPosition(), cp.getNormal(),
                                                          in3.m_vSubtypePosition, deltaAngles, toi);
            if (weldResult == hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED &&
                separatingVelocity > -1.1920929e-7f)
            {
                ConvexCollisionQueryData collPInput;
                collPInput.m_fFinalQueryParameter = Rt;
                MotionUtilities::calcAngularTimInfo(*msA, *msB, reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val())->m_pStepInfo.m_fTimeStep,
                                                    &collPInput.m_avSubtypeVectors[0], &collPInput.m_avSubtypeVectors[1]);
                {
                    hkReal realProjectedLinearDelta;
                    hkReal projectedAngularDelta;
                    hk4dGskCalcWorstCaseProjectedVelocity(msA, msB, cp.getNormal(), in3.m_vSubtypePosition,
                                                          collPInput.m_avSubtypeVectors, realProjectedLinearDelta,
                                                          projectedAngularDelta);
                    collPInput.m_fStepTimeParameter = realProjectedLinearDelta + projectedAngularDelta;
                }
                hk4dGskCollPInputInitialize(in3, collPInput);
                collPInput.m_vFirstStoredVector.setRotatedInverseDir(wTb.getRotation(), cp.getNormal());
                collPInput.m_vSecondStoredVector = gsk.m_akPackedVerticesB[0];
                if (collPInput.m_akPackedVerticesA.val())
                {
                    ScalarVectorData collidePointsOut;
                    hk4dGskCollidePointsWithPlane(collPInput, tol, collidePointsOut);
                    hkDeallocateStack<hkVector4>(collPInput.m_akPackedVerticesA.val());
                    if (collidePointsOut.m_fScale < 1.0f)
                    {
                        hkVector4 newPos;
                        newPos.SetTransformedPoint(wTa, collidePointsOut.m_vVector);
                        cp.getPosition() = newPos;
                    }
                }
            }
            if (velocityBasedOnDistance < separatingVelocity)
            {
                if (separatingVelocity * 1.2f < velocityBasedOnDistance)
                {
                    separatingVelocity = velocityBasedOnDistance;
                }
                else
                {
                    separatingVelocity = CalcSeparatingVelocity(
                        in3.m_pBodyA->GetMotionState(), in3.m_pBodyB->GetMotionState(), cp.getPosition(),
                        cp.getNormal(), in3.m_vSubtypePosition, deltaAngles, toi);
                    separatingVelocity = MathUtilities::min2(0.0f, separatingVelocity);
                }
            }
            separatingVelocity *= stepInfo->m_fInverseDeltaTime;
        }
        ContactDataPhysicsMaterial properties;
        MemoryUtils::memClear16(&properties, 3);
        properties.m_uiUserData = DAT_010d5384;
        gsk.WriteContactFeatureCache(cache);
        cbResult = in3.m_pContactManager->addToi(*in3.m_pBodyA, *in3.m_pBodyB, *reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val()), out, toi, cp,
                                                 static_cast<const ConvexFeaturePairCache*>(&cache), separatingVelocity, static_cast<PhysicsMaterial&>(properties));
        if (cbResult == hkpContactMgr::TOI_ACCEPT)
        {
            if (out.hasToi())
            {
                in3.m_pContactManager->removeToi(*out.m_pConstraintOwner, static_cast<PhysicsMaterial&>(out.m_fTimeOfImpact.m_kProperties));
            }
            out.m_fTimeOfImpact.m_fSeparation = separatingVelocity;
            out.m_fTimeOfImpact.m_vContactPoint = cp;
            out.m_fTimeOfImpact.m_uiCommandId = toi;
            out.m_fTimeOfImpact.m_kProperties.set(properties);
            out.m_fTimeOfImpact.m_kGskCache.set(cache);
        }
    }
}
void hk_user(const AgentSubtypeMarker& in3, ContactPointWeldingParameters& tol, ConvexShapePairCache& gsk, int featureChange,
             const hkVector4& oldMasterNormal, const hkVector4* deltaAngles, hkReal startRt, hkReal endRt,
             hkReal distance0, hkReal distance1, WorldOperationEntry& out)
{
    hkVector4_ProcessEntries_00db54b0(in3, tol, gsk, featureChange, oldMasterNormal, deltaAngles, startRt, endRt, distance0, distance1, out);
}
