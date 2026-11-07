#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/Transform.h"

__forceinline float& hkVector4::operator()(int index)
{
    return m_vComponents.m128_f32[index];
}

__forceinline const float& hkVector4::operator()(int index) const
{
    return m_vComponents.m128_f32[index];
}

// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Object
{
};
void __cdecl Hkpinertiatensorcomputer_CopyAndScalePropertyBlock(float* source, float value, Object* destination);
void __cdecl hkpInertiaTensorComputer_setAndScaleToDensity(float* source, float scale, Object* destination);
struct Receiver
{
    void SetScalarAndRescaleVector(float value);
};
struct State
{
    int first;
    int count;
    int context;
};
void hkpInertiaTensorComputer_computeConvexHullMassProperties(void* state, float zero, void* receiver);
int __cdecl ApplyLimitToReceiver(int owner, int context, int count, float limit, Receiver* receiver, float value);
struct FUN_00cebe80_Struct
{
    float unk00;
    float unk04;
    float unk08;
};
void __cdecl hkpInertiaTensorComputer_shiftInertiaToCom(FUN_00cebe80_Struct* pThis, float fParam2, float* pOut);
void __cdecl AddInertiaTensor(float* param_1, float param_2, float* param_3);
struct FUN_00cec6b0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    float m_64;
    float m_68;
    float m_6C;
    float m_70;
    float m_74;
    float m_78;
    float m_7C;
    float m_80;
    float m_84;
    float m_88;

    void InternalInertiaTensorComputer_computeInertialTensorInternal(float a1, float b, float* p, float* M);
};
struct CECCD0Value
{
    float m_uiFilterValue;

    void set(float v);
    void ScaleValue(float scale);
};
struct S_00ced230_T
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    float unk64;
    float unk68;
    float unk6c;
    float unk70;
    float unk74;
    float unk78;
};
static inline float S_MaxGT(float x, float y)
{
    return (x > y) ? x : y;
}
static inline float S_MaxLT(float x, float y)
{
    return (x < y) ? y : x;
}
void __cdecl hkpInertiaTensorComputer_clipInertia(float d, S_00ced230_T* p);
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
struct S_00cee1c0_Arr
{
    unsigned int* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    unsigned int* m_pTrailingData;
};
S_00cee1c0_Router* hkMemoryRouter_getInstance();
float __cdecl hkInertiaTensorComputer_optimizeInertiasOfConstraintTreeInt(S_00cee1c0_Arr* arr, int unk, float value);
void __cdecl ProcessArrayWithValue(unsigned int* source, int count, int unk, float value);
namespace fnv_anon_00cec3d0 {}
using namespace fnv_anon_00cec3d0;
namespace fnv_anon_00cec3d0 {
struct S00cec3d0_Base
{
    int A;
    int B;
    int C;
    float P1;
    float Pa;
    float Pb;
    float m_fComponent0;
    float m_fComponent1;
    float m_fComponent2;
    float m_fComponent3;
    float m_fComponent4;
    float m_fComponent5;
    float m_fComponent6;

    __declspec(noinline) void InternalInertiaTensorComputer_compProjectionIntegrals(const float* v);
};
}
struct S00cec3d0_Face : S00cec3d0_Base
{
    float Fa;
    float Fb;
    float Fc;
    float m_fVertex0X;
    float m_fVertex0Y;
    float m_fVertex0Z;
    float m_fVertex1X;
    float m_fVertex1Y;
    float m_fVertex1Z;
    float m_fVertex2X;
    float m_fVertex2Y;
    float m_fVertex2Z;
    void InternalInertiaTensorComputer_compFaceIntegrals(const float* verts, const float* n);
};
static inline float S00cec3d0_Sqr(float x)
{
    return x * x;
}
static inline float S00cec3d0_Cube(float x)
{
    return x * x * x;
}
// src: HAVOK_LIB 0x00cec000
void S00cec3d0_Base::InternalInertiaTensorComputer_compProjectionIntegrals(const float* v)
{
    P1 = v[A] * v[B];
    Pa = v[A];
}
struct Matrix
{
    hkVector4 c0, c1, c2;
};
extern const hkVector4 DAT_01017d10;
void HkgeometryutilityGsEhscNogsNoehsc_ComputeValues_00d5ac50(char*, Matrix*, hkVector4*, hkVector4*, hkVector4*);
struct Shape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void getAabb(const Transform*, float, hkAabb*);
};
void Object_GetAABBExtentAxes(Shape* shape, const Matrix* input, hkVector4* outA, hkVector4* outB);
extern const float DAT_01011d78;
extern const double DAT_010240b0;
struct CE50Matrix
{
    hkVector4 row0, row1, row2;
    void CopyThreeVectors(const CE50Matrix* source);
    void Subtract(const CE50Matrix* source);
};
struct CE50Body
{
    float volume, mass;
    hkVector4 center;
    CE50Matrix inertia;
    CE50Body() : volume(0.0f), mass(0.0f)
    {
        _mm_store_ps(&center.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row0.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row1.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row2.x, _mm_setzero_ps());
    }
};
// src: XBOX_PDB 0x00cebaf0
__declspec(noinline) void __cdecl hkpInertiaTensorComputer_computeBoxVolumeMassProperties(const float* radii, float mass, CE50Body* result)
{
    _mm_store_ps(&result->center.x, _mm_setzero_ps());
    result->mass = mass;
    result->volume = (float)(radii[0] * DAT_010240b0 * radii[1] * radii[2]);
    float scale = mass / 3.0f;
    result->inertia.row0.x = scale * (radii[1] * radii[1] + radii[2] * radii[2]);
    result->inertia.row1.y = scale * (radii[0] * radii[0] + radii[2] * radii[2]);
    result->inertia.row2.z = scale * (radii[0] * radii[0] + radii[1] * radii[1]);
}
// src: XBOX_PDB 0x00cebfd0
static __declspec(noinline) void hkMatrix3_mul(CE50Body* body, float scale)
{
    body->mass *= scale;
    body->inertia.row0.x *= scale;
    body->inertia.row0.y *= scale;
    body->inertia.row0.z *= scale;
    body->inertia.row1.x *= scale;
    body->inertia.row1.y *= scale;
    body->inertia.row1.z *= scale;
    body->inertia.row2.x *= scale;
    body->inertia.row2.y *= scale;
    body->inertia.row2.z *= scale;
}
int __cdecl hkVector4_UpdateState_00cece50(float* src, float mass, float thickness, CE50Body* out, ...);
extern const float DAT_0104da48;
extern const float DAT_01016248;
extern const __m128 DAT_010c44d0;
extern const __m128 DAT_010ec7f0;
// src: GUESS 0x00cec7f0 (confidence: high)
__declspec(noinline) void __cdecl Hkpinertiatensorcomputer_ComputePointsAabbCenterAndExtent(int first, int count, float* b, float* a)
{
    _mm_store_ps(b, _mm_setzero_ps());
    _mm_store_ps(a, _mm_setzero_ps());
    __m128 lo = _mm_set_ps1(DAT_0104da48);
    __m128 hi = _mm_xor_ps(lo, DAT_010c44d0);
    const __m128* vertices = (const __m128*)first;
    for (int i = 0; i < count; ++i)
    {
        lo = _mm_min_ps(vertices[i], lo);
        hi = _mm_max_ps(vertices[i], hi);
    }
    if (count != 0)
    {
        __m128 half = _mm_set_ps1(DAT_01016248);
        _mm_store_ps(b, _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, half), lo), _mm_mul_ps(half, hi)));
        _mm_store_ps(a, _mm_sub_ps(hi, lo));
    }
}
__int64 __cdecl hkpInertiaTensorComputer_computeBoxVolumeMassProperties(float* source, float value, void* dest);
// distinct from Pair: exe 0x00ced8e0 passes this 16-byte-aligned floating output prefix to 0x00cebaf0; shared Pair holds two integers.
__declspec(align(16)) struct InertiaOutputPrefix
{
    float x;
    float y;
};
// Plain float fields (no __m128 members, no arrays): keeps /GS from adding a cookie.
__declspec(align(16)) struct Mat4
{
    float unk00_0;
    float unk00_1;
    float unk00_2;
    float unk00_3;
    float row0_0;
    float row0_1;
    float row0_2;
    float row0_3;
    float row1_0;
    float row1_1;
    float row1_2;
    float row1_3;
    float row2_0;
    float row2_1;
    float row2_2;
    float row2_3;
};
__declspec(align(16)) struct Solver
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
    float unk50;
    float unk54;
    float unk58;
    float unk5C;
    float unk60;
    float unk64;
    float unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88;
    void __thiscall ProcessEntries_00ced390(State* self, float* a);
    void __thiscall InternalInertiaTensorComputer_computeInertialTensorInternal(float value, float ratio, float* vec, float* mat);
};
__declspec(align(16)) struct Work
{
    InertiaOutputPrefix pair;
    Mat4 mat;
    Solver solver;
};
struct OutBlock
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    __m128 vec10;
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
};
// src: XBOX_PDB 0x00cebaf0
__declspec(noinline) __int64 __cdecl hkpInertiaTensorComputer_computeBoxVolumeMassProperties(float* source, float value, void* dest)
{
    if (value <= 0.0f)
        return 1;
    OutBlock* result = (OutBlock*)dest;
    float x = source[0], y = source[1], z = source[2];
    _mm_store_ps(&result->m00, _mm_setzero_ps());
    _mm_store_ps(&result->m10, _mm_setzero_ps());
    _mm_store_ps(&result->m20, _mm_setzero_ps());
    result->m00 = result->m11 = result->m22 = 1.0f;
    result->vec10 = _mm_setzero_ps();
    float factor = value * (1.0 / 3.0);
    result->m00 = factor * (y * y + z * z);
    result->m11 = factor * (x * x + z * z);
    result->m22 = factor * (x * x + y * y);
    result->unk00 = x * y * z * 8.0;
    result->unk04 = value;
    return 0;
}
// src: HAVOK_LIB 0x00cec6b0
__declspec(noinline) void Solver::InternalInertiaTensorComputer_computeInertialTensorInternal(float value, float ratio, float* vec, float* mat)
{
    vec[0] = unk68 / unk64;
    vec[1] = unk6c / unk64;
    vec[2] = unk70 / unk64;
    mat[0] = ratio * (unk78 + unk7c);
    mat[5] = ratio * (unk74 + unk7c);
    mat[10] = ratio * (unk74 + unk78);
    float negative = -ratio;
    mat[1] = mat[4] = negative * unk80;
    mat[6] = mat[9] = negative * unk84;
    mat[8] = mat[2] = negative * unk88;
    mat[0] -= value * (vec[1] * vec[1] + vec[2] * vec[2]);
    mat[5] -= value * (vec[0] * vec[0] + vec[2] * vec[2]);
    mat[10] -= value * (vec[0] * vec[0] + vec[1] * vec[1]);
    mat[1] = mat[4] = mat[1] + value * vec[0] * vec[1];
    mat[6] = mat[9] = mat[6] + value * vec[1] * vec[2];
    mat[8] = mat[2] = mat[8] + value * vec[2] * vec[0];
}
struct MeshTriangle
{
    int a, b, c, material;
};
struct MeshInput
{
    __m128* vertices;
    int count, context;
    MeshTriangle* triangles;
    int triangleCount;
};
// src: GUESS 0x00ced390 (confidence: low)
__declspec(noinline) void Solver::ProcessEntries_00ced390(State* self, float* shift)
{
    MeshInput* mesh = (MeshInput*)self;
    unk64 = unk68 = unk6c = unk70 = unk74 = unk78 = unk7c = unk80 = unk84 = unk88 = 0.0f;
    for (int i = 0; i < mesh->triangleCount; ++i)
    {
        MeshTriangle& face = mesh->triangles[i];
        hkVector4 p, q, r, n;
        __m128 offset = _mm_load_ps(shift);
        __m128 a = _mm_add_ps(mesh->vertices[face.a], offset);
        __m128 b = _mm_add_ps(mesh->vertices[face.b], offset);
        __m128 c = _mm_add_ps(mesh->vertices[face.c], offset);
        _mm_store_ps(&p.x, a);
        _mm_store_ps(&q.x, b);
        _mm_store_ps(&r.x, c);
        b = _mm_sub_ps(b, a);
        c = _mm_sub_ps(c, a);
        __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(c, c, 0xd2)),
                                  _mm_mul_ps(_mm_shuffle_ps(c, c, 0xc9), _mm_shuffle_ps(b, b, 0xd2)));
        _mm_store_ps(&n.x, cross);
        float volume = (p.x * n.x + p.y * n.y + p.z * n.z) / 6.0f;
        unk64 += volume;
        float* pp = &p.x;
        float* qq = &q.x;
        float* rr = &r.x;
        float* first = &unk68;
        float* second = &unk74;
        float* product = &unk80;
        for (int j = 0; j < 3; ++j)
        {
            int k = (j + 1) % 3;
            first[j] += volume * (pp[j] + qq[j] + rr[j]) / 4.0f;
            second[j] +=
                volume *
                (pp[j] * pp[j] + qq[j] * qq[j] + rr[j] * rr[j] + pp[j] * qq[j] + qq[j] * rr[j] + rr[j] * pp[j]) / 10.0f;
            product[j] += volume *
                          (2.0f * (pp[j] * pp[k] + qq[j] * qq[k] + rr[j] * rr[k]) + pp[j] * qq[k] + qq[j] * pp[k] +
                           pp[j] * rr[k] + rr[j] * pp[k] + qq[j] * rr[k] + rr[j] * qq[k]) /
                          20.0f;
        }
    }
}
inline float MaxVal(float a, float b)
{
    return a > b ? a : b;
}
int __cdecl Object_ProcessEntries_00ced8e0(State* self, float value, OutBlock* out);
struct S00cf0690_Mass
{
    float volume;
    float mass;
    hkVector4 center;
    hkVector4 row0, row1, row2;
};
struct S00cf0690_Xf
{
    hkVector4 row0, row1, row2, translation;
};
void __cdecl computeRecursiveShapeVolumeMassProperties(void*, const S00cf0690_Xf*, float, S00cf0690_Mass*);
extern const float DAT_01013ea4;
// src: XBOX_PDB 0x00cebfd0
static __declspec(noinline) void hkMatrix3_mul(S00cf0690_Mass* p, float density)
{
    float newMass = density * p->volume;
    float k = newMass / p->mass;
    p->mass = newMass;
    __m128 f = _mm_set_ps1(k);
    *(__m128*)&p->row0 = _mm_mul_ps(*(__m128*)&p->row0, f);
    *(__m128*)&p->row1 = _mm_mul_ps(*(__m128*)&p->row1, f);
    *(__m128*)&p->row2 = _mm_mul_ps(*(__m128*)&p->row2, f);
}
void __cdecl hkpInertiaTensorComputer_computeShapeVolumeMassProperties(void* shape, float mass, S00cf0690_Mass* result);

#include <math.h>
struct Triangle159
{
    int a, b, c, material;
};
struct Mesh159
{
    hkVector4* vertices;
    int unk04, unk08;
    Triangle159* triangles;
    int count;
};
struct Integrals159
{
    int axisA, axisB, axisC;
    float P1, Pa, Pb, m_fComponent0, m_fComponent1, m_fComponent2, m_fComponent3, m_fComponent4, m_fComponent5,
        m_fComponent6;
    float face[12];
    float volume;
    float first[3];
    float second[3];
    float products[3];
    void InternalInertiaTensorComputer_compProjectionIntegrals(const hkVector4* triangle);
    void InternalInertiaTensorComputer_compFaceIntegrals(const hkVector4* triangle, const hkVector4* normal);
    void ProcessEntries_00ced390(Mesh159* mesh, const hkVector4* offset);
};
// src: HAVOK_LIB 0x00cec000
__declspec(noinline) void Integrals159::InternalInertiaTensorComputer_compProjectionIntegrals(const hkVector4* triangle)
{
    P1 = Pa = Pb = m_fComponent0 = m_fComponent1 = m_fComponent2 = m_fComponent3 = m_fComponent4 = m_fComponent5 =
        m_fComponent6 = 0.0f;
    for (int i = 0; i < 3; ++i)
    {
        const hkVector4& p = triangle[i];
        const hkVector4& q = triangle[(i + 1) % 3];
        float a0 = p(axisA), b0 = p(axisB), a1 = q(axisA), b1 = q(axisB);
        float da = a1 - a0, db = b1 - b0;
        float a02 = a0 * a0, a03 = a02 * a0, a04 = a03 * a0;
        float b02 = b0 * b0, b03 = b02 * b0, b04 = b03 * b0;
        float a12 = a1 * a1, a13 = a12 * a1;
        float b12 = b1 * b1, b13 = b12 * b1;
        float c1 = a1 + a0;
        float ca = a1 * c1 + a02, caa = a1 * ca + a03, caaa = a1 * caa + a04;
        float cb = b1 * (b1 + b0) + b02, cbb = b1 * cb + b03, cbbb = b1 * cbb + b04;
        float cab = 3 * a12 + 2 * a1 * a0 + a02;
        float kab = a12 + 2 * a1 * a0 + 3 * a02;
        float caab = a0 * cab + 4 * a13, kaab = a1 * kab + 4 * a03;
        float cabb = 4 * b13 + 3 * b12 * b0 + 2 * b1 * b02 + b03;
        float kabb = b13 + 2 * b12 * b0 + 3 * b1 * b02 + 4 * b03;
        P1 += db * c1;
        Pa += db * ca;
        m_fComponent0 += db * caa;
        m_fComponent3 += db * caaa;
        Pb += da * cb;
        m_fComponent2 += da * cbb;
        m_fComponent6 += da * cbbb;
        m_fComponent1 += db * (b1 * cab + b0 * kab);
        m_fComponent4 += db * (b1 * caab + b0 * kaab);
        m_fComponent5 += da * (a1 * cabb + a0 * kabb);
    }
    P1 /= 2.0f;
    Pa /= 6.0f;
    m_fComponent0 /= 12.0f;
    m_fComponent3 /= 20.0f;
    Pb /= -6.0f;
    m_fComponent2 /= -12.0f;
    m_fComponent6 /= -20.0f;
    m_fComponent1 /= 24.0f;
    m_fComponent4 /= 60.0f;
    m_fComponent5 /= -60.0f;
}
// src: HAVOK_LIB 0x00cec3d0
__declspec(noinline) void Integrals159::InternalInertiaTensorComputer_compFaceIntegrals(const hkVector4* triangle, const hkVector4* normal)
{
    InternalInertiaTensorComputer_compProjectionIntegrals(triangle);
    float w = -normal->x * triangle[0].x - normal->y * triangle[0].y - normal->z * triangle[0].z;
    float na = (*normal)(axisA), nb = (*normal)(axisB);
    float k1 = 1.0f / (*normal)(axisC), k2 = k1 * k1, k3 = k2 * k1, k4 = k3 * k1;
    face[0] = k1 * Pa;
    face[1] = k1 * Pb;
    face[2] = -k2 * (na * Pa + nb * Pb + w * P1);
    face[3] = k1 * m_fComponent0;
    face[4] = k1 * m_fComponent2;
    face[5] = k3 * (na * na * m_fComponent0 + 2 * na * nb * m_fComponent1 + nb * nb * m_fComponent2 +
                    w * (2 * (na * Pa + nb * Pb) + w * P1));
    face[6] = k1 * m_fComponent3;
    face[7] = k1 * m_fComponent6;
    face[8] = -k4 * (na * na * na * m_fComponent3 + 3 * na * na * nb * m_fComponent4 +
                     3 * na * nb * nb * m_fComponent5 + nb * nb * nb * m_fComponent6 +
                     3 * w * (na * na * m_fComponent0 + 2 * na * nb * m_fComponent1 + nb * nb * m_fComponent2) +
                     w * w * (3 * (na * Pa + nb * Pb) + w * P1));
    face[9] = k1 * m_fComponent4;
    face[10] = -k2 * (na * m_fComponent5 + nb * m_fComponent6 + w * m_fComponent2);
    face[11] = k3 * (na * na * m_fComponent3 + 2 * na * nb * m_fComponent4 + nb * nb * m_fComponent5 +
                     w * (2 * (na * m_fComponent0 + nb * m_fComponent1) + w * Pa));
}
// @fnv 0x00ced390
// src: GUESS 0x00ced390 (confidence: low)
void Integrals159::ProcessEntries_00ced390(Mesh159* mesh, const hkVector4* offset)
{
    int triangleCount = mesh->count;
    volume = first[0] = first[1] = first[2] = second[0] = second[1] = second[2] = products[0] = products[1] =
        products[2] = 0.0f;
    if (triangleCount > 0)
    {
        int byteOff = 0;
        int remaining = triangleCount;
        do
        {
            Triangle159 tri = *(Triangle159*)((char*)mesh->triangles + byteOff);
            hkVector4 points[3];
            points[1].m_vComponents = _mm_add_ps(mesh->vertices[tri.b].m_vComponents, offset->m_vComponents);
            points[2].m_vComponents = _mm_add_ps(mesh->vertices[tri.c].m_vComponents, offset->m_vComponents);
            points[0].m_vComponents = _mm_add_ps(mesh->vertices[tri.a].m_vComponents, offset->m_vComponents);
            __m128 e0 = _mm_sub_ps(points[1].m_vComponents, points[0].m_vComponents);
            __m128 e1 = _mm_sub_ps(points[2].m_vComponents, points[0].m_vComponents);
            __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(e1, e1, 0xd2), _mm_shuffle_ps(e0, e0, 0xc9)),
                                      _mm_mul_ps(_mm_shuffle_ps(e1, e1, 0xc9), _mm_shuffle_ps(e0, e0, 0xd2)));
            __m128 square = _mm_mul_ps(cross, cross);
            __m128 sy = _mm_shuffle_ps(square, square, 0x55);
            __m128 sz = _mm_shuffle_ps(square, square, 0xaa);
            __m128 lengthVector = _mm_sqrt_ss(_mm_add_ss(sz, _mm_add_ss(sy, square)));
            float length;
            _mm_store_ss(&length, lengthVector);
            if (length > 0.0f)
            {
                float inverse = 1.0f / length;
                hkVector4 normal;
                normal.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&inverse), _mm_load_ss(&inverse), 0), cross);
                float nx = fabsf(normal.x), ny = fabsf(normal.y), nz = fabsf(normal.z);
                if (nx > ny && nx > nz)
                    axisC = 0;
                else
                    axisC = (ny > nz) ? 1 : 2;
                axisA = (axisC + 1) % 3;
                axisB = (axisA + 1) % 3;
                InternalInertiaTensorComputer_compFaceIntegrals(points, &normal);
                int a = axisA;
                float projected = (a == 0) ? face[0] : ((axisB == 0) ? face[1] : face[2]);
                volume += static_cast<volatile float&>(normal.x) * projected;
                first[a] += normal(a) * face[3];
                first[axisB] += normal(axisB) * face[4];
                first[axisC] += normal(axisC) * face[5];
                second[axisA] += normal(axisA) * face[6];
                second[axisB] += normal(axisB) * face[7];
                second[axisC] += normal(axisC) * face[8];
                products[axisA] += normal(axisA) * face[9];
                products[axisB] += normal(axisB) * face[10];
                products[axisC] += normal(axisC) * face[11];
            }
            byteOff += 16;
        } while (--remaining);
    }
    for (int i = 0; i < 3; ++i)
        first[i] = (float)(first[i] * 0.5);
    for (int i = 0; i < 3; ++i)
        second[i] = (float)(second[i] / 3.0);
    for (int i = 0; i < 3; ++i)
        products[i] = (float)(products[i] * 0.5);
}
