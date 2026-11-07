#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// VC9 RTM /GS- variant of hkpInertiaTensorComputer; matched against the game image.
#include "../../../../../../include/Transform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkQuaternion.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpMassProperties.h"

struct S_00cee1c0_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Free(void* p, unsigned int size);
};
struct S_00cee1c0_Router
{
    unsigned int cursor;
    int unk04;
    int unk08;
    int unk0C;
    S_00cee1c0_Heap* heap;
};
S_00cee1c0_Router* hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* heap, void* array, int elemSize);

#include <math.h>
extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_setzero_ps();
    __m128 _mm_load_ss(const float*);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sqrt_ss(__m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}

typedef __m128 hkQuadReal;
typedef float hkReal;

typedef const hkSimdReal& hkSimdRealParameter;

__forceinline hkSimdReal::hkSimdReal(const hkQuadReal& x) : m_vValue(x)
{}

__forceinline hkSimdReal::hkSimdReal(hkReal x)
{
    m_vValue = _mm_load_ss(&x);
}

__forceinline hkSimdReal::operator hkReal() const
{
    hkReal s;
    _mm_store_ss(&s, m_vValue);
    return s;
}

__forceinline hkQuadReal hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}

__forceinline const hkQuadReal& hkSimdReal::getQuad() const
{
    return m_vValue;
}




__forceinline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
    m_vComponents = _mm_setr_ps(a, b, c, d);
}

__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

__forceinline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
}

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}

__forceinline void hkVector4::mul4(hkSimdRealParameter s)
{
    m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
}

__forceinline void hkVector4::setCross(const hkVector4& v0, const hkVector4& v1)
{
    hkQuadReal cross0;
    cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                        _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    hkQuadReal cross1;
    cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                        _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
}

__forceinline hkSimdReal hkVector4::length3() const
{
    return _mm_sqrt_ss(this->dot3(*this).getQuad());
}

static __forceinline hkSimdReal lengthInverse3(const hkVector4& vector)
{
    const hkQuadReal half = _mm_set_ss(0.5f);
    const hkQuadReal three = _mm_set_ss(3.0f);
    const hkQuadReal zero = _mm_set_ss(0.0f);
    const hkQuadReal len2 = vector.dot3(vector).getQuad();
    const hkQuadReal len2EqualsZero = _mm_cmpeq_ss(len2, zero);
    const hkQuadReal approx = _mm_rsqrt_ss(len2);
    const hkQuadReal refined =
        _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
    return _mm_andnot_ps(len2EqualsZero, refined);
}

__forceinline void hkVector4::normalize3()
{
    hkQuadReal lenInv = lengthInverse3(*this).broadcast();
    m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
}

__forceinline hkReal& hkVector4::operator()(int a)
{
    return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}

__forceinline hkQuaternion::hkQuaternion()
{}

__forceinline hkMatrix3::hkMatrix3()
{}

__forceinline hkVector4& hkMatrix3::getColumn(int x)
{
    return (&m_kColumn0)[x];
}

__forceinline const hkVector4& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}

__forceinline hkReal& hkMatrix3::operator()(int r, int c)
{
    return getColumn(c)(r);
}

__forceinline void hkMatrix3::operator=(const hkMatrix3& a)
{
    m_kColumn0 = a.getColumn(0);
    m_kColumn1 = a.getColumn(1);
    m_kColumn2 = a.getColumn(2);
}

__forceinline void hkMatrix3::setZero()
{
    hkVector4 zero;
    zero.setZero4();
    getColumn(0) = zero;
    getColumn(1) = zero;
    getColumn(2) = zero;
}

__forceinline void hkMatrix3::setIdentity()
{
    setZero();
    hkReal one = 1.0f;
    (*this)(0, 0) = one;
    (*this)(1, 1) = one;
    (*this)(2, 2) = one;
}

__forceinline hkRotation::hkRotation() {}
__forceinline void hkRotation::operator=(const hkRotation& a)
{
    m_kColumn0 = a.m_kColumn0;
    m_kColumn1 = a.m_kColumn1;
    m_kColumn2 = a.m_kColumn2;
}
__forceinline hkTransform::hkTransform() {}
__forceinline void hkTransform::operator=(const hkTransform& a)
{
    m_row0 = a.m_row0;
    m_row1 = a.m_row1;
    m_row2 = a.m_row2;
    m_row3 = a.m_row3;
}
__forceinline void hkTransform::setTranslation(const hkVector4& t)
{
    m_row3 = t.m_vComponents;
}
__forceinline void hkTransform::SetBodyOrientation(const hkQuaternion& q)
{
    reinterpret_cast<hkRotation*>(&m_row0)->hkRotation_set(q);
}
__forceinline void hkTransform::setIdentity()
{
    reinterpret_cast<hkMatrix3*>(&m_row0)->setIdentity();
    m_row3 = _mm_setzero_ps();
}
__forceinline hkpMassProperties::hkpMassProperties() : m_iBufferSize(0.0f), m_fViscosityFriction(0.0f)
{
    m_kCenterOfMass1.setZero4();
    m_kInertiaTensor.setZero();
}

struct MassPropertiesTransform
{
    __forceinline MassPropertiesTransform()
    {
        m_kMotionTransform.setIdentity();
    }
    hkpMassProperties m_kProperties;
    hkTransform m_kMotionTransform;
};

inline S_00cee1c0_Heap& GetRouterHeap(S_00cee1c0_Router* r)
{
    return *r->heap;
}

#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkArray.h"
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryAllocator&>(GetRouterHeap(hkMemoryRouter_getInstance()));
}
template <typename T> __forceinline void hkArrayBase<T>::clear()
{
    m_iElementCount = 0;
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, getCapacity() * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
template <typename T> __forceinline T& hkArrayBase<T>::_expandOne(hkMemoryAllocator& alloc)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(&alloc, this, sizeof(T));
    T* t = m_data + m_iElementCount;
    for (int i = 0; i < 1; ++i)
        ::new (t + i) T;
    return m_data[m_iElementCount++];
}
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    clearAndDeallocate();
}

extern const hkVector4 DAT_01268390;
float __cdecl ClampedAcos(float);
int __cdecl hkpInertiaTensorComputer_combineMassProperties(const hkArray<MassPropertiesTransform>& elements, hkpMassProperties& result);
namespace MathUtilities {
__forceinline hkReal fabs(hkReal r)
{
    return ::fabsf(r);
}
}

// @fnv 0x00cef6d0
// src: XBOX_PDB 0x00cef6d0
__declspec(noinline) int __cdecl hkpInertiaTensorComputer_computeCylinderVolumeMassProperties(const hkVector4& startAxis, const hkVector4& endAxis, hkReal radius,
                                              hkReal mass, hkpMassProperties& result)
{
    if (!(mass <= 0.0f))
    {
        if (radius <= 0.0f)
            return 1;
        hkVector4 axis;
        axis.setSub4(endAxis, startAxis);
        const hkReal height = axis.length3();
        hkTransform cylinderBaseTransform;
        if (height > 0.0f)
        {
            axis.normalize3();
            hkVector4 canonicalZ(DAT_01268390);
            if (MathUtilities::fabs(axis.dot3(canonicalZ)) < 0.99999f)
            {
                hkVector4 rotAxis;
                rotAxis.setCross(canonicalZ, axis);
                rotAxis.normalize3();
                hkQuaternion q;
                q.hkQuaternion_setAxisAngle(rotAxis, ClampedAcos(axis.dot3(canonicalZ)));
                cylinderBaseTransform.SetBodyOrientation(q);
            }
            else
            {
                cylinderBaseTransform.setIdentity();
            }
            hkVector4 centre;
            centre.setAdd4(startAxis, endAxis);
            centre.mul4(hkSimdReal(0.5f));
            cylinderBaseTransform.setTranslation(centre);
            const hkReal volume = (hkReal)(3.1415927410125732421875 * radius * radius * height);
            const hkReal massCopy = mass;
            hkInplaceArray<MassPropertiesTransform, 1> elements(0);
            MassPropertiesTransform& el = elements.expandOne();
            el.m_kMotionTransform = cylinderBaseTransform;
            el.m_kProperties.m_kCenterOfMass1.set(0.0f, 0.0f, 0.0f, 0.0f);
            el.m_kProperties.m_kInertiaTensor.setIdentity();
            el.m_kProperties.m_kInertiaTensor(0, 0) =
                (hkReal)(radius * radius * 0.25 + height / 2.0 * height / 2.0 / 3.0);
            el.m_kProperties.m_kInertiaTensor(1, 1) = el.m_kProperties.m_kInertiaTensor(0, 0);
            el.m_kProperties.m_kInertiaTensor(2, 2) = (hkReal)(radius * radius * 0.5);
            el.m_kProperties.m_kInertiaTensor.Multiply(massCopy);
            el.m_kProperties.m_kCenterOfMass1.setZero4();
            el.m_kProperties.m_iBufferSize = volume;
            el.m_kProperties.m_fViscosityFriction = massCopy;
            hkpInertiaTensorComputer_combineMassProperties(elements, result);
            return 0;
        }
    }
    return 1;
}
