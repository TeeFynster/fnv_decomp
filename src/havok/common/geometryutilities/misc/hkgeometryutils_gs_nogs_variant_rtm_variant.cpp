#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
// src/havok/common/geometryutilities/misc/hkgeometryutils_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/geometryutilities/misc/hkgeometryutils_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/common/geometryutilities/misc/hkgeometryutils_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/geometryutilities/misc/hkgeometryutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/common/geometryutilities/misc/hkgeometryutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/geometryutilities/misc/hkgeometryutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include <math.h>
#include "../../../../../include/hkThreadMemory.h"
#include "../../../../../include/hkGeometry.h"
#include "../../../../../include/hkRotation.h"
#include "../../../../../include/hkTransform.h"
struct hkMemory
{
    virtual ~hkMemory() throw();
    virtual void* allocate(int size) throw();
    virtual void* unk_slot2() throw();
    virtual void* allocateChunk(int* inoutSize) throw();
    virtual void deallocate(void* p, int size) throw();
};
void* __cdecl hkMemoryRouter_getInstance() throw();
__forceinline hkThreadMemory* getThreadMemory() throw()
{
    return (hkThreadMemory*)hkMemoryRouter_getInstance();
}
void __cdecl FUN_00c90940(void* mem, void* array, int elemSize) throw();
void __cdecl hkArrayUtil__reserve(void* mem, void* array, int reqCapacity, int elemSize) throw();
extern const float DAT_01016248;
extern const float DAT_01017718;
extern const float DAT_01011d78;
extern const __m128 DAT_010c71a0;
extern const __m128 DAT_010c71e0;

__forceinline hkSimdReal::hkSimdReal() {}
__forceinline hkSimdReal::hkSimdReal(float x)
{
    m_vValue = _mm_load_ss(&x);
}
__forceinline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x) {}
__forceinline hkSimdReal::operator float() const
{
    float x;
    _mm_store_ss(&x, m_vValue);
    return x;
}
__forceinline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
__forceinline const __m128& hkSimdReal::getQuad() const { return m_vValue; }

__forceinline hkVector4::hkVector4(__m128 q) : m_vComponents(q) {}
__forceinline hkVector4::hkVector4(const hkVector4& r) : m_vComponents(r.m_vComponents) {}
__forceinline void hkVector4::operator=(const hkVector4& r)
{
    _mm_store_ps((float*)&m_vComponents, r.m_vComponents);
}
__forceinline void hkVector4::broadcast(int i)
{
    m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0);
}
__forceinline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& c, const hkVector4& scale)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(c.m_vComponents, scale.m_vComponents));
}
__forceinline void hkVector4::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}
__forceinline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, const hkSimdReal& scale)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(scale.broadcast(), b.m_vComponents));
}
__forceinline void hkVector4::SetTransformedPoint(const hkTransform& t, const hkVector4& v)
{
    setTransformedPos_00c7f640(t, v);
}
static __forceinline void capsuleMul4(hkVector4& vector, float s) throw()
{
    __m128 scalar = _mm_load_ss(&s);
    vector.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), vector.m_vComponents);
}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    __m128 m = _mm_mul_ps(_mm_load_ps((const float*)&m_vComponents), a.m_vComponents);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    sum = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), sum);
    return hkSimdReal(sum);
}
static __forceinline float capsuleLength3(const hkVector4& vector) throw()
{
    __m128 sq = _mm_mul_ps(vector.m_vComponents, vector.m_vComponents);
    __m128 xY = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), xY);
    sum = _mm_sqrt_ss(sum);
    float res;
    _mm_store_ss(&res, sum);
    return res;
}
__forceinline void hkVector4::normalize3()
{
    __m128 lenSq = _mm_mul_ps(m_vComponents, m_vComponents);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(lenSq, lenSq, 0x55), lenSq);
    sum = _mm_add_ss(_mm_shuffle_ps(lenSq, lenSq, 0xaa), sum);
    __m128 r = _mm_rsqrt_ss(sum);
    __m128 nr = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), r),
                           _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(sum, r), r)));
    __m128 zero = _mm_set_ss(0.0f);
    __m128 mask = _mm_cmpeq_ss(sum, zero);
    nr = _mm_andnot_ps(mask, nr);
    nr = _mm_shuffle_ps(nr, nr, 0);
    m_vComponents = _mm_mul_ps(m_vComponents, nr);
}
__forceinline void hkVector4::setCross(const hkVector4& a, const hkVector4& b)
{
    __m128 a1 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9);
    __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2);
    __m128 a2 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2);
    __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9);
    m_vComponents = _mm_sub_ps(_mm_mul_ps(a1, b1), _mm_mul_ps(a2, b2));
}
// local form of hkQuaternion: 0x00da16d0 needs the aligned m_vec type and no-throw call surface; canonical form changes size/scheduling (3603 vs 3551 bytes).
struct __declspec(align(16)) GeometryQuaternionLocal_00da16d0
{
    hkVector4 m_vec;
    void hkQuaternion_setAxisAngle(const hkVector4& axis, float angle) throw();
};
__forceinline void hkVector4::SetRotatedDirection(const GeometryQuaternionLocal_00da16d0& q, const hkVector4& v)
{
    hkVector4 offset;
    offset.m_vComponents = DAT_010c71e0;
    hkVector4 real;
    real.m_vComponents = _mm_shuffle_ps(q.m_vec.m_vComponents, q.m_vec.m_vComponents, 0xff);
    hkVector4 factor;
    factor.setAddMul4(offset, real, real);
    hkVector4 result;
    result.setMul4(v, factor);
    hkVector4 dot;
    dot.m_vComponents = q.m_vec.dot3(v).getQuad();
    dot.broadcast(0);
    result.addMul4(dot, q.m_vec);
    hkVector4 cross;
    cross.setCross(q.m_vec, v);
    result.addMul4(real, cross);
    setAdd4(result, result);
}
__forceinline void hkVector4::setRotatedCached(const GeometryQuaternionLocal_00da16d0& q, const hkVector4& v, const __m128& yz,
                                               const __m128& zx) throw()
{
    hkVector4 offset;
    offset.m_vComponents = DAT_010c71e0;
    hkVector4 real;
    real.m_vComponents = _mm_shuffle_ps(q.m_vec.m_vComponents, q.m_vec.m_vComponents, 0xff);
    hkVector4 factor;
    factor.setAddMul4(offset, real, real);
    hkVector4 result;
    result.setMul4(v, factor);
    hkVector4 dot;
    dot.m_vComponents = q.m_vec.dot3(v).getQuad();
    dot.broadcast(0);
    result.addMul4(dot, q.m_vec);
    hkVector4 cross;
    __m128 qY = _mm_shuffle_ps(q.m_vec.m_vComponents, q.m_vec.m_vComponents, 0xc9);
    __m128 qZ = _mm_shuffle_ps(q.m_vec.m_vComponents, q.m_vec.m_vComponents, 0xd2);
    cross.m_vComponents = _mm_sub_ps(_mm_mul_ps(qY, zx), _mm_mul_ps(qZ, yz));
    result.addMul4(real, cross);
    setAdd4(result, result);
}
__forceinline hkRotation::hkRotation() {}
__forceinline void hkRotation::setIdentity()
{
    __m128 zero = _mm_setzero_ps();
    m_kColumn0.m_vComponents = zero;
    ((float*)&m_kColumn0)[0] = 1.0f;
    m_kColumn1.m_vComponents = zero;
    ((float*)&m_kColumn1)[1] = 1.0f;
    m_kColumn2.m_vComponents = zero;
    ((float*)&m_kColumn2)[2] = 1.0f;
}
__forceinline hkTransform::hkTransform() {}

// FUN_00da16d0 reads its arrays through this plain layout view of hkArray (m_data, size, capacityAndFlags),
// reinterpreted straight from hkGeometry's hkArray members: any derived-to-hkArrayBase conversion in the body makes VC9
// order two hoisted unitX shuffles of the bottom-hemisphere loop the other way round (4 bytes at +2033).
template <typename T> struct CapsuleArrayView
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <typename T> static __forceinline void releaseArray(CapsuleArrayView<T>& array, hkMemory& memory) throw()
{
    array.m_iElementCount = 0;
    if ((array.m_iCapacityState & 0x80000000) == 0)
        memory.deallocate(array.m_data, (array.m_iCapacityState & 0x3fffffff) * sizeof(T));
}
template <typename T> static __forceinline void reserveArray(CapsuleArrayView<T>& array, int n) throw()
{
    hkThreadMemory* memory = getThreadMemory();
    if ((array.m_iCapacityState & 0x3fffffff) < n)
        hkArrayUtil__reserve(memory->m_pMemoryAllocator, &array, n, sizeof(T));
}
template <typename T> static __forceinline void fillOne(T* dst, int n, const T& val)
{
    for (int i = 0; i < n; ++i)
        dst[i] = val;
}
template <typename T> static __forceinline void addBack(CapsuleArrayView<T>& array, const T& val) throw()
{
    hkThreadMemory* memory = getThreadMemory();
    if (array.m_iElementCount == (array.m_iCapacityState & 0x3fffffff))
        FUN_00c90940(memory->m_pMemoryAllocator, &array, sizeof(T));
    fillOne(array.m_data + array.m_iElementCount, 1, val);
    ++array.m_iElementCount;
}
template <typename T> static __forceinline void copyItems(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; ++i)
        dst[i].m_vComponents = src[i].m_vComponents;
}
template <typename T> static __forceinline void assignArray(CapsuleArrayView<T>& array, const CapsuleArrayView<T>& other) throw()
{
    hkMemory* memory = getThreadMemory()->m_pMemoryAllocator;
    if ((array.m_iCapacityState & 0x3fffffff) < other.m_iElementCount)
    {
        if ((array.m_iCapacityState & 0x80000000) == 0)
            memory->deallocate(array.m_data, (array.m_iCapacityState & 0x3fffffff) * sizeof(T));
        int reqBytes = other.m_iElementCount * sizeof(T);
        array.m_data = (T*)memory->allocateChunk(&reqBytes);
        array.m_iCapacityState = reqBytes / (int)sizeof(T);
    }
    array.m_iElementCount = other.m_iElementCount;
    T* dst = array.m_data;
    const T* src = other.m_data;
    copyItems(dst, src, array.m_iElementCount);
}


__forceinline hkGeometry::hkGeometry()
{
}

// The temporary vertex buffer: a plain array the function initialises and frees itself.
struct CapsuleVertices
{
    CapsuleArrayView<hkVector4> array;
    CapsuleVertices() throw()
    {
        array.m_data = 0;
        array.m_iElementCount = 0;
        array.m_iCapacityState = 0x80000000;
    }
    ~CapsuleVertices() throw() { releaseArray(array, *getThreadMemory()->m_pMemoryAllocator); }
};
__forceinline void* hkGeometry::operator new(size_t size) throw()
{
    return getThreadMemory()->m_pMemoryAllocator->allocate(size);
}
static __forceinline void appendCapsuleEnd(hkGeometry* geom, int numSides, int startVertex, hkGeometry::Triangle& tri)
{
    if (numSides > 0)
    {
        CapsuleArrayView<hkGeometry::Triangle>& triangles = reinterpret_cast<CapsuleArrayView<hkGeometry::Triangle>&>(geom->m_uiTriangleCount);
        int i = 1;
        int remaining = numSides;
        do
        {
            tri.m_kPointB = startVertex + i - 1;
            tri.m_kPointA = startVertex + i % numSides;
            tri.m_iThirdValue = startVertex + numSides;
            addBack(triangles, tri);
            ++i;
        } while (--remaining);
    }
}
// @fnv 0x00da16d0
// src: XBOX_PDB 0x00da16d0
void __cdecl hkGeometryUtils_createCapsuleGeometry(const hkVector4& top, const hkVector4& bottom, float radius, int numHeightSegments,
                          int numSides, const hkTransform& transform, hkGeometry*& outGeom) throw()
{
    const int halfSides = numSides >> 1;
    CapsuleVertices vertexBuffer;
    CapsuleArrayView<hkVector4>& localVertices = vertexBuffer.array;
    hkVector4 axis;
    axis.setSub4(bottom, top);
    float len = capsuleLength3(axis);
    hkTransform localTransform;
    if (len > 0.0f)
    {
        axis.normalize3();
        hkVector4 zAxis;
        zAxis.m_vComponents = DAT_010c71a0;
        float dotZ = zAxis.dot3(axis);
        if (fabsf(dotZ) < 0.99999f)
        {
            hkVector4 yAxis;
            yAxis.setCross(axis, zAxis);
            yAxis.normalize3();
            reinterpret_cast<hkRotation&>(localTransform).m_kColumn0.setCross(yAxis, axis);
            reinterpret_cast<hkRotation&>(localTransform).m_kColumn1.m_vComponents = yAxis.m_vComponents;
            reinterpret_cast<hkRotation&>(localTransform).m_kColumn2.m_vComponents = axis.m_vComponents;
        }
        else
        {
            reinterpret_cast<hkRotation&>(localTransform).setIdentity();
        }
    }
    else
    {
        reinterpret_cast<hkRotation&>(localTransform).setIdentity();
    }
    hkVector4 center;
    center.setAdd4(bottom, top);
    capsuleMul4(center, 0.5f);
    localTransform.position = center;
    double halfLen;
    int numVerts = (numHeightSegments + halfSides * 2 - 1) * numSides + 2;
    hkVector4 topCenter;
    {
        float scalar = (float)(-len * 0.5);
        topCenter.set(0, 0, scalar, 0);
    }
    halfLen = len * 0.5;
    hkVector4 bottomCenter;
    {
        float scalar = (float)halfLen;
        bottomCenter.set(0, 0, scalar, 0);
    }
    hkVector4 axisDelta;
    axisDelta.setSub4(bottomCenter, topCenter);
    hkVector4 unitZ;
    unitZ.set(0.0f, 0.0f, 1.0f, 0.0f);
    hkVector4 unitX;
    unitX.set(1.0f, 0.0f, 0.0f, 0.0f);
    hkVector4 negUnitY;
    negUnitY.set(0.0f, -1.0f, 0.0f, 0.0f);
    reserveArray(localVertices, numVerts);
    hkVector4 pt;
    double apexHeight = halfLen + radius;
    // Top apex
    {
        float apex = (float)apexHeight;
        pt.set(0.0f, 0.0f, apex, 0.0f);
        pt.SetTransformedPoint(localTransform, pt);
        addBack(localVertices, pt);
    }
    int i, j;
    // Top hemisphere rings
    for (i = halfSides - 1; i >= 0; --i)
    {
        float angle = (float)((float)i / (float)halfSides * 3.1415927410125732421875 * 0.5);
        GeometryQuaternionLocal_00da16d0 qY;
        qY.hkQuaternion_setAxisAngle(negUnitY, angle);
        hkVector4 v3;
        v3.SetRotatedDirection(qY, unitX);

        j = 0;
        if (numSides > 0)
        {
            __m128 yz;
            (void)yz;
            __m128 zx = _mm_shuffle_ps(v3.m_vComponents, v3.m_vComponents, 0xd2);
            yz = _mm_shuffle_ps(v3.m_vComponents, v3.m_vComponents, 0xc9);
            for (; j < numSides; ++j)
            {
                float sideAngle = (float)((float)j / (float)numSides * 3.1415927410125732421875 * 2.0);
                GeometryQuaternionLocal_00da16d0 sideRotation;
                sideRotation.hkQuaternion_setAxisAngle(unitZ, sideAngle);
                hkVector4 radial;
                radial.setRotatedCached(sideRotation, v3, yz, zx);

                float radiusScale = radius;
                pt.setAddMul4(bottomCenter, radial, hkSimdReal(radiusScale));
                pt.SetTransformedPoint(localTransform, pt);
                addBack(localVertices, pt);
            }
        }
    }
    // Cylinder body
    const hkVector4& cylinderAxis = unitX;
    for (j = numHeightSegments - 1; j > 0; --j)
    {
        for (i = 0; i < numSides; ++i)
        {
            float sideAngle = (float)((float)i / (float)numSides * 3.1415927410125732421875 * 2.0);
            GeometryQuaternionLocal_00da16d0 sideRotation;
            sideRotation.hkQuaternion_setAxisAngle(unitZ, sideAngle);
            hkVector4 radial;
            radial.SetRotatedDirection(sideRotation, cylinderAxis);

            float vRing = (float)j / (float)numHeightSegments;
            hkVector4 segCenter;
            segCenter.setAddMul4(topCenter, axisDelta, hkSimdReal(vRing));
            float radiusScale = radius;
            pt.setAddMul4(segCenter, radial, hkSimdReal(radiusScale));
            pt.SetTransformedPoint(localTransform, pt);
            addBack(localVertices, pt);
        }
    }
    // Bottom hemisphere
    for (i = 0; i < halfSides; ++i)
    {
        float angle = (float)(-(float)i / (float)halfSides * 3.1415927410125732421875 * 0.5);
        GeometryQuaternionLocal_00da16d0 qY;
        qY.hkQuaternion_setAxisAngle(negUnitY, angle);
        hkVector4 v3;
        v3.SetRotatedDirection(qY, unitX);
        for (j = 0; j < numSides; ++j)
        {
            float sideAngle = (float)((float)j / (float)numSides * 3.1415927410125732421875 * 2.0);
            GeometryQuaternionLocal_00da16d0 sideRotation;
            sideRotation.hkQuaternion_setAxisAngle(unitZ, sideAngle);
            hkVector4 radial;
            radial.SetRotatedDirection(sideRotation, v3);

            float radiusScale = radius;
            pt.setAddMul4(topCenter, radial, hkSimdReal(radiusScale));
            pt.SetTransformedPoint(localTransform, pt);
            addBack(localVertices, pt);
        }
    }
    // Bottom apex
    {
        float apex = (float)(-apexHeight);
        pt.set(0.0f, 0.0f, apex, 0.0f);
        pt.SetTransformedPoint(localTransform, pt);
        addBack(localVertices, pt);
    }
    hkGeometry* geom = new hkGeometry();
    assignArray(reinterpret_cast<CapsuleArrayView<hkVector4>&>(geom->m_kVertices), localVertices);
    for (int i = 0; i < reinterpret_cast<CapsuleArrayView<hkVector4>&>(geom->m_kVertices).m_iElementCount; ++i)
    {
        reinterpret_cast<CapsuleArrayView<hkVector4>&>(geom->m_kVertices).m_data[i].SetTransformedPoint(transform, reinterpret_cast<CapsuleArrayView<hkVector4>&>(geom->m_kVertices).m_data[i]);
    }
    hkGeometry::Triangle tri;
    tri.m_iMaterialIndex = -1;
    int startVertex = 1;
    if (numSides > 0)
    {
        CapsuleArrayView<hkGeometry::Triangle>& triangles = reinterpret_cast<CapsuleArrayView<hkGeometry::Triangle>&>(geom->m_uiTriangleCount);
        int i = 1;
        int remaining = numSides;
        do
        {
            tri.m_kPointA = 0;
            tri.m_kPointB = i;
            tri.m_iThirdValue = i % numSides + 1;
            addBack(triangles, tri);
            ++i;
        } while (--remaining);
    }
    for (j = 0; j < numHeightSegments + halfSides * 2 - 2; ++j)
    {
        {
            if (numSides > 0)
            {
                CapsuleArrayView<hkGeometry::Triangle>& triangles = reinterpret_cast<CapsuleArrayView<hkGeometry::Triangle>&>(geom->m_uiTriangleCount);
                int i = 1;
                int remaining = numSides;
                do
                {
                    tri.m_kPointA = startVertex + i - 1;
                    tri.m_kPointB = startVertex + i - 1 + numSides;
                    tri.m_iThirdValue = startVertex + i % numSides + numSides;
                    addBack(triangles, tri);
                    tri.m_kPointB = startVertex + i - 1;
                    tri.m_kPointA = startVertex + i % numSides;
                    tri.m_iThirdValue = startVertex + numSides + i % numSides;
                    addBack(triangles, tri);
                    ++i;
                } while (--remaining);
            }
            startVertex += numSides;
        }
    }
    appendCapsuleEnd(geom, numSides, startVertex, tri);
    outGeom = geom;
}


