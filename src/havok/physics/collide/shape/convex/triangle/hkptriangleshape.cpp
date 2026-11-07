
// src/havok/physics/collide/shape/convex/triangle/hkptriangleshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/triangle/hkptriangleshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkThreadLocalData.h"

// Keep this unit's original SIMD representation; the CRT union changes alias analysis.
// Exe 0x00d1ff40 GetCentre: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;
#define _INCLUDED_MM2
extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_load_ss(const float* p);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" void _mm_store_ps(float* p, LocalM128 a);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_rsqrt_ss(LocalM128);
extern "C" LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_set_ss(float);
extern "C" LocalM128 _mm_max_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_min_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ps1(const float*);
extern "C" int _mm_movemask_ps(LocalM128);
extern "C" LocalM128 _mm_rcp_ps(LocalM128 _A);
extern "C" LocalM128 _mm_and_ps(LocalM128 _A,LocalM128 _B);
extern "C" LocalM128 _mm_or_ps(LocalM128 _A,LocalM128 _B);
extern "C" LocalM128 _mm_xor_ps(LocalM128 _A,LocalM128 _B);
extern "C" LocalM128 _mm_cmpeq_ps(LocalM128 _A,LocalM128 _B);
extern "C" LocalM128 _mm_cmplt_ps(LocalM128 _A,LocalM128 _B);
extern "C" LocalM128 _mm_cmple_ps(LocalM128 _A,LocalM128 _B);
extern "C" LocalM128 _mm_setr_ps(float _A,float _B,float _C,float _D);
extern "C" LocalM128 _mm_setzero_ps(void);

#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSphereRepShape.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpTriangleShape.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkAabb.h"

#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkVector4_S.h"

extern char const* const g_01268970_arg1;

void __cdecl hkReferencedObject_calcContentStatistics(char const*, char const* const*);

// @fnv 0x00d1fee0
// src: XBOX_PDB 0x00d1fee0
void __cdecl hkpTriangleShape_calcContentStatistics(char const* arg1, char const* const* arg2)
{
    hkReferencedObject_calcContentStatistics(arg1, &g_01268970_arg1);
}

// The triangle has three collision spheres, plus three for its extrusion.

// @fnv 0x00d1ff10
int hkpTriangleShape::GetNumCollisionSpheres() const
{
    return (m_ucWeldingPadding + 1) * 3;
}

// edge is a triangle edge index (0, 1, or 2).
// @fnv 0x00d1fef0
// src: HAVOK_LIB 0x00d1fef0
static __declspec(noinline) int __cdecl getSingleEdgeBitcode(unsigned short weldingInfo, int edge)
{
    char shift = edge * 5;
    return (weldingInfo >> shift) & 31;
}
int __cdecl ExtractEdge(unsigned short weldingInfo, int edge)
{
    return getSingleEdgeBitcode(weldingInfo, edge);
}

extern float DAT_0106c2e0;

// Stores the sum of the three vertices multiplied by DAT_0106c2e0 into out.
// The shared triangle header omits GetCentre; this adapter adds its declaration without storage.
class TriangleCentre : public hkpTriangleShape {
public:
    void GetCentre(hkVector4* out);
};
// @fnv 0x00d1ff40
void TriangleCentre::GetCentre(hkVector4* out)
{
    LocalM128 sum = _mm_add_ps(*(const LocalM128*)&m_kVertexB, *(const LocalM128*)&m_kVertexA);
    _mm_store_ps(&out->x, sum);
    LocalM128 total = _mm_add_ps(*(const LocalM128*)&m_kVertexC, sum);
    _mm_store_ps(&out->x, total);
    LocalM128 half = _mm_load_ss(&DAT_0106c2e0);
    half = _mm_shuffle_ps(half, half, 0);
    _mm_store_ps(&out->x, _mm_mul_ps(half, total));
}

// @fnv 0x00d1ff20
void hkpTriangleShape::GetFirstVertex(hkVector4& dst) const
{
    LocalM128 v = *(const LocalM128*)&m_kVertexA;
    *(LocalM128*)&dst = v;
}

extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;

// Computes the normalized cross product of two edge vectors and writes the result to out.
// @fnv 0x00d1ff80
// src: GUESS 0x00d1ff80 (confidence: medium)
static __declspec(noinline) void Object_ComputeNormalizedCrossProduct(const LocalM128* apVertexA, const LocalM128* apVertexB, const LocalM128* apVertexC, LocalM128* apNormal)
{
    LocalM128 vb = *apVertexB;
    LocalM128 va = *apVertexA;
    LocalM128 q;
    LocalM128& edge = q;
    LocalM128 p = _mm_sub_ps(vb, va);
    edge = _mm_sub_ps(*apVertexC, vb);
    LocalM128 qz = _mm_shuffle_ps(q, q, 0xd2);
    LocalM128 py = _mm_shuffle_ps(p, p, 0xc9);
    LocalM128 qy = _mm_shuffle_ps(q, q, 0xc9);
    LocalM128 pz = _mm_shuffle_ps(p, p, 0xd2);
    LocalM128 crossProduct = _mm_sub_ps(_mm_mul_ps(py, qz), _mm_mul_ps(pz, qy));
    LocalM128 squaredComponents = _mm_mul_ps(crossProduct, crossProduct);
    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(squaredComponents, squaredComponents, 0x55), squaredComponents);
    LocalM128 length = _mm_add_ss(_mm_shuffle_ps(squaredComponents, squaredComponents, 0xaa), xy);
    LocalM128 r = _mm_rsqrt_ss(length);
    LocalM128 r2 = _mm_mul_ss(_mm_mul_ss(length, r), r);
    LocalM128 zero = _mm_set_ss(DAT_01011d78);
    LocalM128 mask = _mm_cmpeq_ss(length, zero);
    LocalM128 delta = _mm_sub_ss(_mm_set_ss(DAT_01017718), r2);
    LocalM128 newtonFactor = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), r), delta);
    LocalM128 scale = _mm_andnot_ps(mask, newtonFactor);
    *apNormal = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), crossProduct);
}
const LocalM128* volatile inputA;
const LocalM128* volatile inputB;
const LocalM128* volatile inputC;
LocalM128* volatile outputV;
void invokeTriangleNormal() { Object_ComputeNormalizedCrossProduct(inputA, inputB, inputC, outputV); }

struct SimdVector {
    union { LocalM128 value; float component[4]; };
    void setTransformedPos_00c7f640(const void* transform, const SimdVector& vertex);
    __forceinline void lower(const SimdVector& a, const SimdVector& b) { value = _mm_min_ps(a.value, b.value); }
    __forceinline void upper(const SimdVector& a, const SimdVector& b) { value = _mm_max_ps(a.value, b.value); }
    __forceinline void sum(const SimdVector& a, const SimdVector& b) { value = _mm_add_ps(a.value, b.value); }
    __forceinline void difference(const SimdVector& a, const SimdVector& b) { value = _mm_sub_ps(a.value, b.value); }
    __forceinline void broadcast(float f) { LocalM128 scalar = _mm_load_ss(&f); value = _mm_shuffle_ps(scalar, scalar, 0); }
};
// The shared triangle header omits its AABB override; this adapter contains only the method.
struct TriangleBounds : hkpTriangleShape {
    void hkpTriangleShape_getAabbImpl(const void* transform, float tolerance, hkAabb& out) const;
};
// Computes the axis-aligned bounding box of the triangle (and extrusion) under a transform, expanded by the sphere radius plus tolerance.
// @fnv 0x00d20050
// src: XBOX_PDB 0x00d20050
void TriangleBounds::hkpTriangleShape_getAabbImpl(const void* transform, float tolerance, hkAabb& out) const {
    SimdVector extent;
    extent.broadcast(m_fSphereRadius + tolerance);
    SimdVector a, b, c;
    a.setTransformedPos_00c7f640(transform, reinterpret_cast<const SimdVector&>(m_kVertexA));
    b.setTransformedPos_00c7f640(transform, reinterpret_cast<const SimdVector&>(m_kVertexB));
    c.setTransformedPos_00c7f640(transform, reinterpret_cast<const SimdVector&>(m_kVertexC));
    SimdVector* bounds = reinterpret_cast<SimdVector*>(&out.m_kMinimumCorner.x);
    bounds[0].lower(a,b);
    bounds[1].upper(a,b);
    bounds[0].lower(bounds[0],c);
    bounds[1].upper(bounds[1],c);
    SimdVector shifted;
    shifted.value = _mm_add_ps(bounds[0].value,_mm_load_ps(reinterpret_cast<const float*>(&m_kVertexTransform)));
    bounds[0].lower(bounds[0],shifted);
    shifted.value = _mm_add_ps(bounds[1].value,_mm_load_ps(reinterpret_cast<const float*>(&m_kVertexTransform)));
    bounds[1].upper(bounds[1],shifted);
    bounds[0].difference(bounds[0],extent);
    bounds[1].sum(bounds[1],extent);
}

// @fnv 0x00d20110
const hkSphere* hkpTriangleShape::GetCollisionSpheres(hkSphere* sphereBuffer) const
{
    hkVector4* apVertices = reinterpret_cast<hkVector4*>(sphereBuffer);
    *(LocalM128*)apVertices = *(const LocalM128*)&m_kVertexA;
    apVertices->w = m_fSphereRadius;
    *(LocalM128*)(apVertices + 1) = *(const LocalM128*)&m_kVertexB;
    hkVector4* q = apVertices + 1;
    q->w = m_fSphereRadius;
    ++q;
    *(LocalM128*)q = *(const LocalM128*)&m_kVertexC;
    q->w = m_fSphereRadius;
    ++q;
    if (m_ucWeldingPadding != 0) {
        *(LocalM128*)q = _mm_add_ps(*(const LocalM128*)&m_kVertexTransform, *(const LocalM128*)&m_kVertexA);
        q->w = m_fSphereRadius;
        ++q;
        *(LocalM128*)q = _mm_add_ps(*(const LocalM128*)&m_kVertexTransform, *(const LocalM128*)&m_kVertexB);
        q->w = m_fSphereRadius;
        *(LocalM128*)&q[1] = _mm_add_ps(_mm_load_ps(reinterpret_cast<const float*>(&m_kVertexC.x)), *(const LocalM128*)&m_kVertexTransform);
        q[1].w = m_fSphereRadius;
    }
    return sphereBuffer;
}

__forceinline int rootSelect48(const float* sv)
{
    float L0=sv[0];
    float L1=sv[1];
    float L2=sv[2];
    int idx;
    float m;
    if (L2 > L1) { m = L2; idx = 2; }
    else { m = L1; idx = 1; }
    if (L0 > m) idx = 0;
    return idx;
}

struct SupportVector {
    union { LocalM128 vector; float components[4]; };
    __forceinline void add(const SupportVector& b) { vector = _mm_add_ps(vector, b.vector); }
};

// Picks the triangle vertex with the largest projection of pf, adds m_kVertexTransform if its dot with pf is positive, and stores the index in out[3].
// @fnv 0x00d20270
void hkpTriangleShape::GetSupportVertex(const hkVector4& direction, Vector4WithInt24W& supportingVertexOut) const
{
    const float* pf = reinterpret_cast<const float*>(&direction);
    float* out = reinterpret_cast<float*>(&supportingVertexOut);
    LocalM128 v0 = *reinterpret_cast<const LocalM128*>(&m_kVertexA);
    LocalM128 v1 = *reinterpret_cast<const LocalM128*>(&m_kVertexB);
    LocalM128 v4 = *reinterpret_cast<const LocalM128*>(&m_kVertexC);
    LocalM128 tp = _mm_unpacklo_ps(v0, v1);
    LocalM128 ct = _mm_unpackhi_ps(v0, v1);
    v0 = _mm_movelh_ps(tp, v4);
    v1 = _mm_shuffle_ps(_mm_movehl_ps(v0, tp), v4, 0xd4);
    v4 = _mm_shuffle_ps(ct, v4, 0xe4);
    LocalM128 d = _mm_load_ps(pf);
    LocalM128 v2 = d;
    v2 = _mm_shuffle_ps(v2, d, 0x55);
    v2 = _mm_mul_ps(v2, v1);
    LocalM128 v3 = d;
    v3 = _mm_shuffle_ps(v3, d, 0);
    v2 = _mm_add_ps(v2, _mm_mul_ps(v3, v0));
    v2 = _mm_add_ps(v2, _mm_mul_ps(_mm_shuffle_ps(d, d, 0xaa), v4));
    LocalM128 s = v2;
    float sv[4];
    _mm_store_ps(sv, s);
    int idx = rootSelect48(sv);
    _mm_store_ps(out, reinterpret_cast<const LocalM128*>(&m_kVertexA)[idx]);
    LocalM128 vD = *reinterpret_cast<const LocalM128*>(&m_kVertexTransform);
    LocalM128 vP = _mm_mul_ps(_mm_load_ps(pf), vD);
    LocalM128 e = _mm_add_ss(_mm_shuffle_ps(vP, vP, 0xaa), _mm_add_ss(_mm_shuffle_ps(vP, vP, 0x55), vP));
    float fE;
    _mm_store_ss(&fE, e);
    if (fE > 0.0f) {
        idx += 3;
        reinterpret_cast<SupportVector*>(out)->add(*reinterpret_cast<const SupportVector*>(&m_kVertexTransform));
    }
    ((int*)out)[3] = idx | 0x3f000000;
}

#include <math.h>
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"

extern int DAT_011b3b4c[];
extern int DAT_011b3b50[];
extern float DAT_011b3b38[];
// hkpWeldingUtility sin/cos table: cosAccept0, sinAccept0, cosSnap0, cosSnap1, cosAccept1, sinAccept1
struct FloatArray6 { float value[6]; };
extern FloatArray6 DAT_01269210[];

static __forceinline float scalar(LocalM128 v) { float out; _mm_store_ss(&out, v); return out; }
static __forceinline LocalM128 splat(LocalM128 v) { return _mm_shuffle_ps(v, v, 0); }
static __forceinline LocalM128 horizontal3(LocalM128 p) {
    LocalM128 y = _mm_shuffle_ps(p, p, 0x55);
    LocalM128 xy = _mm_add_ss(y, p);
    LocalM128 z = _mm_shuffle_ps(p, p, 0xaa);
    return _mm_add_ss(z, xy);
}
static __forceinline LocalM128 dot3(LocalM128 a, LocalM128 b) { return horizontal3(_mm_mul_ps(a, b)); }
static __forceinline LocalM128 cross3(LocalM128 a, LocalM128 b) {
    return _mm_sub_ps(
        _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
        _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}
static __forceinline LocalM128 normalized3(LocalM128 v) {
    LocalM128 length = dot3(v, v);
    LocalM128 estimate = _mm_rsqrt_ss(length);
    LocalM128 zero = _mm_set_ss(DAT_01011d78);
    LocalM128 three = _mm_set_ss(DAT_01017718);
    LocalM128 half = _mm_set_ss(DAT_01016248);
    LocalM128 zeroMask = _mm_cmpeq_ss(length, zero);
    LocalM128 product = _mm_mul_ss(_mm_mul_ss(length, estimate), estimate);
    LocalM128 correction = _mm_mul_ss(_mm_mul_ss(half, estimate), _mm_sub_ss(three, product));
    return _mm_mul_ps(splat(_mm_andnot_ps(zeroMask, correction)), v);
}

static __forceinline bool shouldSnapOneSided(unsigned int type, const LocalM128& face, const LocalM128& normal, const float* limits) {
    float alignment = scalar(dot3(face, normal));
    if (type == 0) return alignment < limits[type];
    return alignment > limits[type];
}
static __forceinline int getSector(unsigned int code, const LocalM128& face, const LocalM128& normal) {
    float alignment = scalar(dot3(face, normal));
    int cone;
    if (alignment >= DAT_01269210[code].value[0]) cone = 1;
    else if (alignment >= DAT_01269210[code].value[2]) cone = 0;
    else if (alignment >= DAT_01269210[code].value[3]) cone = 2;
    else if (alignment >= DAT_01269210[code].value[4]) cone = 4;
    else cone = 3;
    return cone;
}
struct VectorOperations {
    LocalM128 value;
    void hkVector4_setRotatedDir(const hkRotation*, const LocalM128*);
    void hkVector4_setTransformedInversePos(const hkTransform*, const hkVector4*);
    void setTransformedPos_00c7f640(const hkTransform*, const VectorOperations&);
};
// Welding calls the original support callback at vtable +0x44, absent from the common convex declaration.
struct SupportShape {
    virtual void slot00(); virtual void slot04(); virtual void slot08();
    virtual void slot0c(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1c(); virtual void slot20();
    virtual void slot24(); virtual void slot28(); virtual void slot2c();
    virtual void slot30(); virtual void slot34(); virtual void slot38();
    virtual void slot3c(); virtual void slot40();
    virtual void getSupport(VectorOperations*);
};
extern float __cdecl NiMin(float, float);

// The shared reference-based welding signature changes code at 0x00d203f0; retain this pointer-based adapter.
class TriangleWelding : public hkpTriangleShape {
public:
    int WeldContactPoint(unsigned short* indices, unsigned char* count,
        const hkVector4* position, const hkTransform* transform,
        SupportShape* source, const hkTransform* sourceTransform, hkVector4* output);
};

// Welds a triangle edge against a support shape, adjusting the face normal and separation based on welding type and sector cone.
// @fnv 0x00d203f0
int TriangleWelding::WeldContactPoint(unsigned short* indices, unsigned char* count,
    const hkVector4* position, const hkTransform* transform,
    SupportShape* source, const hkTransform* sourceTransform, hkVector4* output) {
    unsigned int weldingType = *(const unsigned char*)&m_eWeldingType;
    if (weldingType == 6) return 2;
    int edge = DAT_011b3b4c[indices[0]];
    unsigned char sectors = *count;
    if (sectors > 1) {
        int other = DAT_011b3b4c[indices[1]];
        if (sectors == 3) {
            if (indices[0] + indices[1] + indices[2] == 3) return 2;
            if (other == edge) other = DAT_011b3b4c[indices[2]];
            *count = 2;
            indices[0] = (unsigned short)edge;
            indices[1] = (unsigned short)other;
        }
        if (DAT_011b3b50[edge] != other) edge = other;
    }

    VectorOperations corrected;
    // Copy the caller's four scalar components, preserving the original unaligned load form.
    ((int*)&corrected)[0] = ((const int*)output)[0];
    ((int*)&corrected)[1] = ((const int*)output)[1];
    ((int*)&corrected)[2] = ((const int*)output)[2];
    ((int*)&corrected)[3] = ((const int*)output)[3];
    LocalM128 v0 = *(const LocalM128*)&transform->m_rotation.m_kColumn0;
    LocalM128 v1 = *(const LocalM128*)&transform->m_rotation.m_kColumn1;
    LocalM128 v4 = *(const LocalM128*)&transform->m_rotation.m_kColumn2;
    LocalM128 tp = _mm_unpacklo_ps(v0, v1);
    LocalM128 ct = _mm_unpackhi_ps(v0, v1);
    v0 = _mm_movelh_ps(tp, v4);
    v1 = _mm_shuffle_ps(_mm_movehl_ps(v0, tp), v4, 0xd4);
    v4 = _mm_shuffle_ps(ct, v4, 0xe4);
    LocalM128 d = corrected.value;
    LocalM128 v2 = d;
    v2 = _mm_shuffle_ps(v2, d, 0x55);
    v2 = _mm_mul_ps(v2, v1);
    LocalM128 v3 = d;
    v3 = _mm_shuffle_ps(v3, d, 0);
    v2 = _mm_add_ps(v2, _mm_mul_ps(v3, v0));
    v2 = _mm_add_ps(v2, _mm_mul_ps(_mm_shuffle_ps(d, d, 0xaa), v4));
    LocalM128 localNormal = v2;
    SimdVector normalStore;
    normalStore.value = v2;

    VectorOperations faceTemporary;
    Object_ComputeNormalizedCrossProduct((const LocalM128*)&m_kVertexA, (const LocalM128*)&m_kVertexB, (const LocalM128*)&m_kVertexC, &faceTemporary.value);
    LocalM128 face = faceTemporary.value;
    LocalM128 faceProduct = _mm_mul_ps(face, localNormal);
    float separation = (float)fabs(scalar(horizontal3(faceProduct))) * ((const hkVector4*)&corrected)->w;
    LocalM128 edgeDirection = normalized3(_mm_sub_ps(((const LocalM128*)&m_kVertexA)[DAT_011b3b50[edge]], ((const LocalM128*)&m_kVertexA)[edge]));
    unsigned int code = (m_kWeldingInfo >> ((signed char)edge * (signed char)5)) & 31;

    if (weldingType != 5) {
        if (!shouldSnapOneSided(weldingType, face, localNormal, DAT_01269210[code].value)) return 2;
        const float* limits = DAT_01269210[code].value;
        LocalM128 angleCos = _mm_load_ss(limits + weldingType);
        LocalM128 angleSin = _mm_load_ss(limits + weldingType + 1);
        corrected.value = normalized3(_mm_add_ps(
            _mm_mul_ps(cross3(edgeDirection, face), splat(angleSin)),
            _mm_mul_ps(splat(angleCos), face)));
        corrected.hkVector4_setRotatedDir(&transform->m_rotation, &corrected.value);
        if (m_ucWeldingPadding) {
            faceTemporary.value = _mm_mul_ps(_mm_load_ps1(DAT_011b3b38 + weldingType), faceTemporary.value);
            VectorOperations localPosition;
            localPosition.hkVector4_setTransformedInversePos(transform, position);
            separation = NiMin(scalar(dot3(_mm_sub_ps(localPosition.value, *(const LocalM128*)&m_kVertexA), faceTemporary.value)), separation);
        } else {
            VectorOperations support;
            source->getSupport(&support);
            support.setTransformedPos_00c7f640(sourceTransform, support);
            LocalM128 projection = dot3(_mm_sub_ps(*(const LocalM128*)position, support.value), corrected.value);
            if ((_mm_movemask_ps(projection) & 1) == 0) return 0;
        }
    } else {
        int cone = getSector(code, face, localNormal);
        switch (cone) {
        case 0:
        case 4: break;
        case 2: return 0;
        default: return 2;
        }
        if (*count == 1) return 0;
        const FloatArray6& entry = DAT_01269210[code];
        LocalM128 angleCos = _mm_load_ss(&entry.value[cone]);
        LocalM128 angleSin = _mm_load_ss(&entry.value[cone + 1]);
        LocalM128 correction = normalized3(_mm_add_ps(
            _mm_mul_ps(cross3(edgeDirection, face), splat(angleSin)),
            _mm_mul_ps(splat(angleCos), face)));
        LocalM128 blend = _mm_add_ps(
            _mm_mul_ps(splat(dot3(edgeDirection, localNormal)), edgeDirection),
            _mm_mul_ps(splat(dot3(correction, localNormal)), correction));
        normalStore.value = normalized3(blend);
        corrected.hkVector4_setRotatedDir(&transform->m_rotation, &normalStore.value);
    }
    *(LocalM128*)output = corrected.value;
    output->w = separation;
    return 1;
}

typedef unsigned char hkUint8_S;
typedef unsigned short hkUint16_S;
typedef unsigned int hkUint32_S;
typedef unsigned __w64 hk_size_t;
typedef int hkBool32;

typedef float hkReal_S;

typedef LocalM128 hkQuadReal;
typedef const hkVector4_S&hkVector4Parameter;

__forceinline hkSimdReal::hkSimdReal() {}

// Initialize SIMD storage without selecting between the shared constructor overloads.
static __forceinline hkSimdReal componentValue(const hkQuadReal& value)
{
    hkSimdReal result;
    result.m_vValue = value;
    return result;
}

__forceinline hkSimdReal::hkSimdReal(const hkQuadReal& x)
    : m_vValue(x) {}
__forceinline hkQuadReal hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
__forceinline const hkQuadReal& hkSimdReal::getQuad() const
{
    return m_vValue;
}
typedef const hkSimdReal&hkSimdRealParameter;class Vector4Comparison;
typedef const Vector4Comparison&hkVector4ComparisonParameter;
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
};
static const Mask ms_kLaneMasks[4];
__forceinline void setAnd(hkVector4ComparisonParameter a,hkVector4ComparisonParameter b){m_uiMask=_mm_and_ps(a.m_uiMask,b.m_uiMask);}
__forceinline void setOr(hkVector4ComparisonParameter a,hkVector4ComparisonParameter b){m_uiMask=_mm_or_ps(a.m_uiMask,b.m_uiMask);}
__forceinline void setNot(hkVector4ComparisonParameter a)
{
static __declspec(align(16))const hkUint32_S allBits[4]={0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF};
m_uiMask=_mm_andnot_ps(a.m_uiMask,*(const hkQuadReal*)&allBits);
}
__forceinline hkBool32 anyIsSet(Mask m)const{return _mm_movemask_ps(m_uiMask)&m;}
private:
hkQuadReal m_uiMask;
friend class hkVector4_S;};
namespace MathUtilities
{inline hkQuadReal quadReciprocal(hkQuadReal r)
{
hkQuadReal e=_mm_rcp_ps(r);
return _mm_sub_ps(_mm_add_ps(e,e),_mm_mul_ps(_mm_mul_ps(e,r),e));
}
}
extern const hkQuadReal g_kQuadRealConstant;

__forceinline hkVector4_S::operator hkQuadReal() const
{
    return m_vComponents;
}
__forceinline hkQuadReal&hkVector4_S::getQuad()
{
return m_vComponents;
}
__forceinline const hkQuadReal&hkVector4_S::getQuad()const
{
return m_vComponents;
}
__forceinline void hkVector4_S::operator=(const hkVector4_S&v)
{
m_vComponents=v.m_vComponents;
}
__forceinline void hkVector4_S::set(hkReal_S a,hkReal_S b,hkReal_S c,hkReal_S d)
{
m_vComponents=_mm_setr_ps(a,b,c,d);
}
__forceinline void hkVector4_S::SetAllComponents(hkSimdRealParameter a)
{
m_vComponents=_mm_shuffle_ps(a.getQuad(),a.getQuad(),(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
__forceinline void hkVector4_S::setZero4()
{
m_vComponents=_mm_setzero_ps();
}
__forceinline void hkVector4_S::sub4(const hkVector4_S&v)
{
m_vComponents=_mm_sub_ps(m_vComponents,v.m_vComponents);
}
__forceinline void hkVector4_S::setSub4(const hkVector4_S&v0,const hkVector4_S&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
__forceinline void hkVector4_S::mul4(const hkVector4_S&v)
{
m_vComponents=_mm_mul_ps(m_vComponents,v.m_vComponents);
}
__forceinline void hkVector4_S::setMul4(const hkVector4_S&a,const hkVector4_S&b)
{
m_vComponents=_mm_mul_ps(a.m_vComponents,b.m_vComponents);
}
__forceinline void hkVector4_S::mul4(hkSimdRealParameter s)
{
m_vComponents=_mm_mul_ps(s.broadcast(),m_vComponents);
}
__forceinline void hkVector4_S::addMul4(hkSimdRealParameter r,const hkVector4_S&v1)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(r.broadcast(),v1.m_vComponents));
}
__forceinline void hkVector4_S::addMul4(const hkVector4_S&x,const hkVector4_S&y)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(x.m_vComponents,y.m_vComponents));
}
__forceinline void hkVector4_S::setCross(const hkVector4_S&v0,const hkVector4_S&v1)
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
__forceinline Vector4Comparison hkVector4_S::compareLessThan4(hkVector4Parameter a)const
{
Vector4Comparison m;m.m_uiMask=_mm_cmplt_ps(m_vComponents,a.m_vComponents);
return m;
}
__forceinline Vector4Comparison hkVector4_S::compareEqual4(hkVector4Parameter a)const
{
Vector4Comparison m;m.m_uiMask=_mm_cmpeq_ps(m_vComponents,a.m_vComponents);
return m;
}
__forceinline Vector4Comparison hkVector4_S::compareLessThanEqual4(const hkVector4_S&a)const
{
Vector4Comparison m;m.m_uiMask=_mm_cmple_ps(m_vComponents,a.m_vComponents);
return m;
}
__forceinline hkSimdReal hkVector4_S::dot3(const hkVector4_S&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return componentValue(_mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum));}
__forceinline hkSimdReal hkVector4_S::lengthSquared3()const
{
return this->dot3(*this);
}
__forceinline hkSimdReal hkVector4_S::lengthInverse3()const
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
return componentValue(_mm_andnot_ps(len2EqualsZero,refined));}
__forceinline void hkVector4_S::normalize3()
{
hkQuadReal lenInv=lengthInverse3().broadcast();
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
}
__forceinline hkReal_S&hkVector4_S::operator()(int a)
{
return reinterpret_cast<hkReal_S*>(&m_vComponents)[a];
}
__forceinline void hkVector4_S::setReciprocal4(const hkVector4_S&vec)
{
m_vComponents=MathUtilities::quadReciprocal(vec.m_vComponents);
}
__forceinline hkSimdReal hkVector4_S::getSimdAt(int i)const
{
switch(i)
{
case 0:
return componentValue(m_vComponents);
case 1:
return componentValue(_mm_shuffle_ps(m_vComponents,m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))));
case 2:
return componentValue(_mm_shuffle_ps(m_vComponents,m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))));
case 3:
default:
return componentValue(_mm_shuffle_ps(m_vComponents,m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3)))));
}
}
__forceinline void hkVector4_S::setBroadcast(const hkVector4_S&v,int i)
{
if(i==0)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
else if(i==1)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
}
else if(i==2)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
}
else if(i==3)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3))));
}
}
__forceinline Vector4Comparison hkVector4_S::compareGreaterThanEqual4(hkVector4Parameter a)const
{
return a.compareLessThanEqual4(*this);
}

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
__forceinline void hkMonitorStream::TimerCommand::setTime()
{
hkUint32_S ticks;
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
class Vector4WithInt24W:public hkVector4_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};
#include "../../../../../../../include/hkpBufferSize.h"
typedef __declspec(align(16))char hkpShapeBuffer[HK_SHAPE_BUFFER_SIZE];
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
class hkSphere;
typedef hkUint16_S hkpVertexId;
typedef hkUint32_S hkpShapeKey;

struct RayCastHitResult
{
inline void reset();
hkVector4_S m_vHitNormal;
hkReal_S m_fHitFraction;};struct ShapeRayCastOutput:public RayCastHitResult
{
public:
enum{MAX_HIERARCHY_DEPTH=8};
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline void setKey(hkpShapeKey key);
private:
__forceinline void _reset();
public:
hkpShapeKey m_uiShapeKeys[MAX_HIERARCHY_DEPTH];
private:
int m_uiShapeKeyIndex;};inline void ShapeRayCastOutput::setKey(hkpShapeKey key)
{
m_uiShapeKeys[m_uiShapeKeyIndex]=key;
}
struct ShapeRayCastOutputArray
{
ShapeRayCastOutput m_akRayOutputs[4];
void reset(){m_akRayOutputs[0].reset();m_akRayOutputs[1].reset();m_akRayOutputs[2].reset();m_akRayOutputs[3].reset();}
};

__forceinline const hkVector4& hkpTriangleShape::getVertex(int i) const
{
    return (&m_kVertexA)[i];
}
struct ShapeRayBundleCastInput
{
hkVector4_S m_vFrom[3];
hkVector4_S m_vTo[3];};
namespace hkVector4Util_S
{
__forceinline void __cdecl mulSigns4(hkVector4_S&inout,const hkVector4_S&signsSource);}
inline void __cdecl hkVector4Util_S::mulSigns4(hkVector4_S&inout,const hkVector4_S&signs)
{
static __declspec(align(16))const hkUint32_S signmask[4]=
{0x80000000,0x80000000,0x80000000,0x80000000};
inout.getQuad()=_mm_xor_ps(inout.getQuad(),
_mm_and_ps(signs.getQuad(),*(const hkQuadReal*)&signmask));}
static void diffCrossDiffDotNormal(const hkVector4_S&p_i,const hkVector4_S&p_j,const hkVector4_S*hitPoints,const hkVector4_S&normal,hkVector4_S&dotsOut)
{
hkVector4_S A[3];
hkVector4_S B[3];
A[0].setBroadcast(p_i,0);
A[0].sub4(hitPoints[0]);
A[2].sub4(hitPoints[2]);
B[0].setBroadcast(p_j,0);
B[2].sub4(hitPoints[2]);
hkVector4_S temp;
hkVector4_S dots;
hkVector4_S cp;
dots.setZero4();
dots.addMul4(normal.getSimdAt(0),cp);
cp.setMul4(A[2],B[0]);temp.setMul4(A[0],B[2]);cp.sub4(temp);
dots.addMul4(normal.getSimdAt(2),cp);
dotsOut=dots;}
// The shared triangle header omits its bundle override; attach only that method, with no layout copy.
class TriangleRayBundle : public hkpTriangleShape {
public:
    Vector4Comparison CastRayBundle(const ShapeRayBundleCastInput&, ShapeRayCastOutputArray&, hkVector4ComparisonParameter) const;
};
// @fnv 0x00d20e70
Vector4Comparison TriangleRayBundle::CastRayBundle(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&results,hkVector4ComparisonParameter mask) const
{
const hkpTriangleShape* thisObj = this;

{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "rayBundleTriangle";h->setTime();mStream.setEnd((char*)(h+1));}};ScopedTimer timeblock54;
;
Vector4Comparison kComparisonMask=mask;
const hkVector4_S&vert0=reinterpret_cast<const hkVector4_S&>(thisObj->getVertex(0));
const hkVector4_S&vert1=reinterpret_cast<const hkVector4_S&>(thisObj->getVertex(1));
const hkVector4_S&vert2=reinterpret_cast<const hkVector4_S&>(thisObj->getVertex(2));
hkVector4_S v10;v10.setSub4(vert1,vert0);
hkVector4_S v20;v20.setSub4(vert2,vert0);
hkVector4_S triangleNormal;triangleNormal.setCross(v10,v20);
hkVector4_S dist;dist.SetAllComponents(vert0.dot3(triangleNormal));
hkVector4_S dist_a;dist_a.setZero4();
hkVector4_S dist_b;dist_b.setZero4();
dist_a.addMul4(triangleNormal.getSimdAt(0),input.m_vFrom[0]);
dist_b.addMul4(triangleNormal.getSimdAt(0),input.m_vTo[0]);
dist_a.addMul4(triangleNormal.getSimdAt(1),input.m_vFrom[1]);
dist_b.addMul4(triangleNormal.getSimdAt(1),input.m_vTo[1]);
dist_a.addMul4(triangleNormal.getSimdAt(2),input.m_vFrom[2]);
dist_b.addMul4(triangleNormal.getSimdAt(2),input.m_vTo[2]);
dist_a.sub4(dist);
dist_b.sub4(dist);
Vector4Comparison distMask;
{
hkVector4_S distProd;distProd.setMul4(dist_a,dist_b);
hkVector4_S zero;zero.setZero4();
Vector4Comparison distProdGteZero=distProd.compareGreaterThanEqual4(zero);
Vector4Comparison distAEqZero=dist_a.compareEqual4(zero);
Vector4Comparison distBEqZero=dist_b.compareEqual4(zero);
Vector4Comparison distBNeqZero;distBNeqZero.setNot(distBEqZero);
distAEqZero.setOr(distAEqZero,distBNeqZero);
distProdGteZero.setAnd(distProdGteZero,distAEqZero);
distMask.setNot(distProdGteZero);
}
kComparisonMask.setAnd(kComparisonMask,distMask);
hkVector4_S proj_length;proj_length.setSub4(dist_a,dist_b);
hkVector4_S distance;distance.setReciprocal4(proj_length);
distance.mul4(dist_a);
hkVector4_S oneMinusDistance;oneMinusDistance.getQuad()=g_kQuadRealConstant;
oneMinusDistance.sub4(distance);
const hkQuadReal edgeToleranceMul={-1e-4f,-1e-4f,-1e-4f,-1e-4f};
hkVector4_S edge_tolerance;edge_tolerance.getQuad()=edgeToleranceMul;
edge_tolerance.mul4(triangleNormal.lengthSquared3());
{
hkVector4_S earlyOutFractions;earlyOutFractions.set(results.m_akRayOutputs[0].m_fHitFraction,results.m_akRayOutputs[1].m_fHitFraction,results.m_akRayOutputs[2].m_fHitFraction,results.m_akRayOutputs[3].m_fHitFraction);
Vector4Comparison closeEnough=distance.compareLessThan4(earlyOutFractions);
kComparisonMask.setAnd(kComparisonMask,closeEnough);
}
hkVector4_S point[3];
point[0].setMul4(oneMinusDistance,input.m_vFrom[0]);
point[0].addMul4(distance,input.m_vTo[0]);
point[1].setMul4(oneMinusDistance,input.m_vFrom[1]);
point[1].addMul4(distance,input.m_vTo[1]);
point[2].setMul4(oneMinusDistance,input.m_vFrom[2]);
point[2].addMul4(distance,input.m_vTo[2]);
hkVector4_S dots01;
diffCrossDiffDotNormal(vert0,vert1,point,triangleNormal,dots01);
Vector4Comparison ok01=dots01.compareGreaterThanEqual4(edge_tolerance);
kComparisonMask.setAnd(kComparisonMask,ok01);
hkVector4_S dots12;
diffCrossDiffDotNormal(vert1,vert2,point,triangleNormal,dots12);
Vector4Comparison ok12=dots12.compareGreaterThanEqual4(edge_tolerance);
kComparisonMask.setAnd(kComparisonMask,ok12);
hkVector4_S dots20;
diffCrossDiffDotNormal(vert2,vert0,point,triangleNormal,dots20);
Vector4Comparison ok20=dots20.compareGreaterThanEqual4(edge_tolerance);
kComparisonMask.setAnd(kComparisonMask,ok20);
for(int i=0;i<4;i++)
{
if(kComparisonMask.anyIsSet(Vector4Comparison::ms_kLaneMasks[i]))
{
triangleNormal.normalize3();
results.m_akRayOutputs[i].m_fHitFraction=distance(i);
hkVector4_S dist_a4;dist_a4.setBroadcast(dist_a,i);
hkVector4_S tempNormal;tempNormal=triangleNormal;
hkVector4Util_S::mulSigns4(tempNormal,dist_a4);
results.m_akRayOutputs[i].m_vHitNormal=tempNormal;
results.m_akRayOutputs[i].setKey(0xffffffff);
}
}
return kComparisonMask;
}

class LaneScalar {
    LocalM128 value;
public:
    LaneScalar(const LocalM128& source) : value(source) {}
    __forceinline LocalM128 splat() const {
        return _mm_shuffle_ps(value,value,0);
    }
};

class LaneVector {
    LocalM128 value;
public:
    __forceinline operator LocalM128() const { return value; }
    __forceinline void operator=(const LaneVector& source) { value=source.value; }
    __forceinline void operator=(const LocalM128& source) { value=source; }
    __forceinline void broadcast(const LaneVector& source,int lane) {
        if(lane==0) value=_mm_shuffle_ps(source.value,source.value,0);
        else if(lane==1) value=_mm_shuffle_ps(source.value,source.value,0x55);
        else if(lane==2) value=_mm_shuffle_ps(source.value,source.value,0xaa);
        else value=_mm_shuffle_ps(source.value,source.value,0xff);
    }
    __forceinline LaneScalar scalar(int lane) const {
        switch(lane) {
        case 0: return value;
        case 1: return _mm_shuffle_ps(value,value,0x55);
        case 2: return _mm_shuffle_ps(value,value,0xaa);
        default: return _mm_shuffle_ps(value,value,0xff);
        }
    }
    __forceinline void clear() { value=_mm_setzero_ps(); }
    __forceinline void subtract(const LaneVector& other) { value=_mm_sub_ps(value,other.value); }
    __forceinline void product(const LaneVector& a,const LaneVector& b) { value=_mm_mul_ps(a.value,b.value); }
    __forceinline void accumulate(const LaneScalar& scale,const LaneVector& other) {
        value=_mm_add_ps(value,_mm_mul_ps(scale.splat(),other.value));
    }
};

// @fnv 0x00d201a0
// src: GUESS 0x00d201a0 (confidence: low)
static __declspec(noinline) void Object_UpdateFields_00d201a0(const LaneVector& first,const LaneVector& second,const LaneVector* rows,const LaneVector& weight,LaneVector& output)
{
    LaneVector left[3];
    LaneVector right[3];
    left[0].broadcast(first,0); left[0].subtract(rows[0]);
    left[1].broadcast(first,1); left[1].subtract(rows[1]);
    left[2].broadcast(first,2); left[2].subtract(rows[2]);
    right[0].broadcast(second,0); right[0].subtract(rows[0]);
    right[1].broadcast(second,1); right[1].subtract(rows[1]);
    right[2].broadcast(second,2); right[2].subtract(rows[2]);
    LaneVector scratch;
    LaneVector sum;
    LaneVector component;
    sum.clear();
    component.product(left[1],right[2]); scratch.product(left[2],right[1]); component.subtract(scratch);
    sum.accumulate(weight.scalar(0),component);
    component.product(left[2],right[0]); scratch.product(left[0],right[2]); component.subtract(scratch);
    sum.accumulate(weight.scalar(1),component);
    component.product(left[0],right[1]); scratch.product(left[1],right[0]); component.subtract(scratch);
    sum.accumulate(weight.scalar(2),component);
    output=sum;
}

extern const LaneVector* obtainVector();
extern LaneVector* obtainOutput();
void keepEdgeTest() { Object_UpdateFields_00d201a0(*obtainVector(),*obtainVector(),obtainVector(),*obtainVector(),*obtainOutput()); }

struct ShapeRayCastQuery {
    hkVector4_S m_vFrom;
    hkVector4_S m_vTo;
};

static __forceinline float rayScalar(const hkSimdReal& value) {
    float result;
    _mm_store_ss(&result, value.getQuad());
    return result;
}
static __forceinline void rayInterpolate(hkVector4_S& out, const hkVector4_S& a, const hkVector4_S& b, float fraction) {
    static __declspec(align(16)) const float ones[4] = {1,1,1,1};
    LocalM128 scalar = _mm_load_ss(&fraction);
    LocalM128 t = _mm_shuffle_ps(scalar,scalar,0);
    LocalM128 s = _mm_sub_ps(*(const LocalM128*)ones,t);
    out.getQuad() = _mm_add_ps(_mm_mul_ps(s,a.getQuad()),_mm_mul_ps(t,b.getQuad()));
}
static __forceinline void rayNegate(hkVector4_S& out, const hkVector4_S& a) {
    static __declspec(align(16)) const unsigned int signs[4] = {0x80000000,0x80000000,0x80000000,0x80000000};
    out.getQuad() = _mm_xor_ps(a.getQuad(),*(const LocalM128*)signs);
}
// Tests a ray against this triangle, writing hit fraction and normal to results and returning whether the ray hits inside the triangle.
// The shared triangle header omits its ray override; attach only that method, with no layout copy.
class TriangleRayCast : public hkpTriangleShape {
public:
    hkBool IntersectRayWithShape(const ShapeRayCastQuery&, ShapeRayCastOutput&) const;
};
// @fnv 0x00d20a70
hkBool TriangleRayCast::IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&results) const
{
const hkpTriangleShape* thisObj = this;
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "rcTriangle";h->setTime();mStream.setEnd((char*)(h+1));}};
const hkVector4_S&vert0=reinterpret_cast<const hkVector4_S&>(thisObj->getVertex(0));
const hkVector4_S&vert1=reinterpret_cast<const hkVector4_S&>(thisObj->getVertex(1));
const hkVector4_S&vert2=reinterpret_cast<const hkVector4_S&>(thisObj->getVertex(2));
hkVector4_S v10;v10.setSub4(vert1,vert0);
hkVector4_S v20;v20.setSub4(vert2,vert0);
hkVector4_S triangleNormal;triangleNormal.setCross(v10,v20);
const hkReal_S dist=rayScalar(vert0.dot3(triangleNormal));
hkReal_S dist_a=rayScalar(triangleNormal.dot3(input.m_vFrom));
dist_a-=dist;
hkReal_S dist_b=rayScalar(triangleNormal.dot3(input.m_vTo));
dist_b-=dist;
if(dist_a*dist_b>=0.0f)
{
if(dist_a !=0.0f || dist_b==0.0f)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return false;
}
}
const hkReal_S proj_length=dist_a-dist_b;
const hkReal_S distance=dist_a / proj_length;
if(distance<results.m_fHitFraction)
{
hkReal_S edge_tolerance=rayScalar(triangleNormal.lengthSquared3());
edge_tolerance*=-0.0001f;
hkVector4_S point;rayInterpolate(point,input.m_vFrom,input.m_vTo,distance);
{
hkVector4_S v0p;v0p.setSub4(vert0,point);
hkVector4_S v1p;v1p.setSub4(vert1,point);
hkVector4_S cp0;cp0.setCross(v0p,v1p);
if(rayScalar(cp0.dot3(triangleNormal))>=edge_tolerance)
{
hkVector4_S v2p;v2p.setSub4(vert2,point);
hkVector4_S cp1;cp1.setCross(v1p,v2p);
if(rayScalar(cp1.dot3(triangleNormal))>=edge_tolerance)
{
hkVector4_S cp2;cp2.setCross(v2p,v0p);
if(rayScalar(cp2.dot3(triangleNormal))>=edge_tolerance)
{
results.m_fHitFraction=distance;
if(dist_a>0.0f)
{
results.m_vHitNormal=triangleNormal;
}
else
{
rayNegate(results.m_vHitNormal,triangleNormal);
}
results.m_vHitNormal.normalize3();
results.setKey(0xffffffff);
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return true;
}
}
}
}
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return false;
}
