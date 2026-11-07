#include "../../../../../../include/hkArrayBase.h"
#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
#define FNV64_HKMATRIX3_TRIVIAL_DEFAULT

// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Retain this unit's float-only intrinsic type: the CRT's byte-array view
// changes the old compiler's /GS classification of stack temporaries.
#define _INCLUDED_MM2
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_setzero_ps();
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ss(const float*);
    void _mm_store_ps(float*, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_sqrt_ss(LocalM128);
    void _mm_store_ss(float*, LocalM128);
    LocalM128 _mm_div_ss(LocalM128, LocalM128);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_min_ps(LocalM128, LocalM128);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
}
// Preserve aligned SIMD storage and uninitialized vector construction.
#define FNV_VEC4_NO_SSE
#define FNV_VEC4_SIMD
#include "../../../../../../include/Vec4.h"
#include "../../../../../../include/Transform.h"
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/V4.h"
#include "../../../../../../include/hkVector4.h"

// These operations were inline in this unit's original vector definitions.
inline hkAabb::hkAabb() {}
inline V4::V4() {}
inline void V4::setZero4()
{
    q = _mm_setzero_ps();
}
inline float& V4::operator()(int i)
{
    return q.m128_f32[i];
}
inline const float& V4::operator()(int i) const
{
    return q.m128_f32[i];
}

inline void hkVector4::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}
inline float& hkVector4::operator()(int i)
{
    return m_vComponents.m128_f32[i];
}
inline int hkVector4::maxAxisSecond() const
{
    if (x < y)
        return y < z ? 2 : 1;
    return x < z ? 2 : 0;
}
inline int hkVector4::maxAxis() const
{
    if (x < y)
    {
        if (z > y)
            return 2;
        return 1;
    }
    if (z > x)
        return 2;
    return 0;
}


struct Object
{
};
void __cdecl Hkpinertiatensorcomputer_CopyAndScalePropertyBlock(float* source, float value, Object* destination);
// Multiplies the float at source by scale and passes the result to FUN_00cebdf0 along with source and destination.
// @fnv 0x00cebe50
// src: HAVOK_LIB 0x00cebe50
void __cdecl hkpInertiaTensorComputer_setAndScaleToDensity(float* source, float scale, Object* destination)
{
    float result = *source * scale;
    Hkpinertiatensorcomputer_CopyAndScalePropertyBlock(source, result, destination);
}

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
// @fnv 0x00ced020
int __cdecl ApplyLimitToReceiver(int owner, int context, int count, float limit, Receiver* receiver, float value)
{
    State state;
    if (limit <= 0.0f)
        return 1;
    if (count < 1)
        return 1;
    state.count = count;
    state.context = context;
    state.first = owner;
    hkpInertiaTensorComputer_computeConvexHullMassProperties(&state, 0.0f, receiver);
    receiver->SetScalarAndRescaleVector(limit);
    return 0;
}


// Subtracts fParam2 times products of pThis's components from the diagonal of pOut and adds the off-diagonal products to its symmetric entries.
// @fnv 0x00cebe80
// src: HAVOK_LIB 0x00cebe80
void __cdecl hkpInertiaTensorComputer_shiftInertiaToCom(hkVector4* pThis, float fScale, float* pMatrix)
{
    float fValue;

    fValue = pMatrix[0] - fScale * (pThis->z * pThis->z + pThis->y * pThis->y);
    pMatrix[0] = fValue;

    fValue = pMatrix[5] - fScale * (pThis->x * pThis->x + pThis->z * pThis->z);
    pMatrix[5] = fValue;

    fValue = pMatrix[10] - fScale * (pThis->x * pThis->x + pThis->y * pThis->y);
    pMatrix[10] = fValue;

    fValue = pThis->x * fScale * pThis->y + pMatrix[1];
    pMatrix[1] = fValue;
    pMatrix[4] = fValue;

    fValue = fScale * pThis->y * pThis->z + pMatrix[6];
    pMatrix[6] = fValue;
    pMatrix[9] = fValue;

    fValue = fScale * pThis->z * pThis->x + pMatrix[8];
    pMatrix[8] = fValue;
    pMatrix[2] = fValue;
}

// @fnv 0x00cebf30
void __cdecl AddInertiaTensor(float* param_1, float fScale, float* pMatrix)
{
    float fOffDiag;
    *pMatrix = *pMatrix + fScale * (param_1[1] * param_1[1] + param_1[2] * param_1[2]);
    pMatrix[5] = (param_1[0] * param_1[0] + param_1[2] * param_1[2]) * fScale + pMatrix[5];
    pMatrix[10] = (param_1[0] * param_1[0] + param_1[1] * param_1[1]) * fScale + pMatrix[10];
    fOffDiag = pMatrix[1] - param_1[0] * fScale * param_1[1];
    pMatrix[1] = fOffDiag;
    pMatrix[4] = fOffDiag;
    fOffDiag = pMatrix[6] - param_1[1] * fScale * param_1[2];
    pMatrix[6] = fOffDiag;
    pMatrix[9] = fOffDiag;
    fOffDiag = pMatrix[8] - param_1[0] * (param_1[2] * fScale);
    pMatrix[8] = fOffDiag;
    pMatrix[2] = fOffDiag;
}

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

// @fnv 0x00cec6b0
// src: HAVOK_LIB 0x00cec6b0
void FUN_00cec6b0_cls::InternalInertiaTensorComputer_computeInertialTensorInternal(float a1, float afScale, float* p, float* pMatrix)
{
    p[0] = m_68 / m_64;
    p[1] = m_6C / m_64;
    p[2] = m_70 / m_64;

    pMatrix[0] = afScale * (m_7C + m_78);
    pMatrix[5] = afScale * (m_7C + m_74);
    pMatrix[10] = afScale * (m_78 + m_74);

    float t = -afScale * m_80;
    float r;
    r = t;
    pMatrix[1] = r;
    pMatrix[4] = r;
    t = -afScale * m_84;
    r = t;
    pMatrix[6] = r;
    pMatrix[9] = r;
    t = -afScale * m_88;
    r = t;
    pMatrix[8] = r;
    pMatrix[2] = r;

    pMatrix[0] = pMatrix[0] - a1 * (p[1] * p[1] + p[2] * p[2]);
    pMatrix[5] = pMatrix[5] - (p[2] * p[2] + p[0] * p[0]) * a1;
    pMatrix[10] = pMatrix[10] - (p[0] * p[0] + p[1] * p[1]) * a1;

    t = (a1 * p[0]) * p[1] + pMatrix[1];
    r = t;
    pMatrix[1] = r;
    pMatrix[4] = r;
    t = (a1 * p[1]) * p[2] + pMatrix[6];
    r = t;
    pMatrix[6] = r;
    pMatrix[9] = r;
    t = (a1 * p[2]) * p[0] + pMatrix[8];
    r = t;
    pMatrix[8] = r;
    pMatrix[2] = r;
}

struct CECCD0Value
{
    float m_uiFilterValue;

    void set(float v);
    void ScaleValue(float scale);
};

// @fnv 0x00ceccd0
void CECCD0Value::ScaleValue(float scale)
{
    set(m_uiFilterValue * scale);
}

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
// @fnv 0x00ced230
// src: HAVOK_LIB 0x00ced230
void __cdecl hkpInertiaTensorComputer_clipInertia(float afDivisor, S_00ced230_T* pData)
{
    float a = pData->unk50;
    a = S_MaxGT(a, pData->unk64);
    a = S_MaxGT(a, pData->unk78);
    a = a / afDivisor;
    pData->unk50 = S_MaxGT(pData->unk50, a);
    pData->unk64 = S_MaxLT(a, pData->unk64);
    pData->unk78 = S_MaxLT(a, pData->unk78);
}

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

// @fnv 0x00cee1c0
void __cdecl ProcessArrayWithValue(unsigned int* source, int count, int unk, float value)
{
    S_00cee1c0_Arr arr;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_cap = 0x80000000;

    S_00cee1c0_Router* r = hkMemoryRouter_getInstance();
    unsigned int* mem = (unsigned int*)r->cursor;
    r->cursor = (unsigned int)mem + ((count * 4 + 0x7f) & 0xffffff80);
    arr.m_cap = count | 0x80000000;
    arr.m_data = mem;
    arr.m_pTrailingData = mem;

    int i = 0;
    if (count > 0)
    {
        do
        {
            arr.m_data[arr.m_iElementCount++] = source[i];
            i++;
        } while (i < count);
    }

    hkInertiaTensorComputer_optimizeInertiasOfConstraintTreeInt(&arr, unk, value);
    unsigned int* local = arr.m_pTrailingData;
    if (local == arr.m_data)
    {
        arr.m_iElementCount = 0;
    }
    hkMemoryRouter_getInstance()->cursor = (unsigned int)local;
    S_00cee1c0_Heap* h = hkMemoryRouter_getInstance()->heap;
    arr.m_iElementCount = 0;
    if ((arr.m_cap & 0x80000000) == 0)
    {
        h->Free(arr.m_data, (arr.m_cap & 0x3fffffff) * 4);
    }
}

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

// Calls FUN_00cec000, then fills Fa, Fb, Fc and the m_fVertex fields from verts, normal n and the base fields using polynomials in 1/n[C].
// @fnv 0x00cec3d0
// src: HAVOK_LIB 0x00cec3d0
void S00cec3d0_Face::InternalInertiaTensorComputer_compFaceIntegrals(const float* verts, const float* apNormal)
{
    InternalInertiaTensorComputer_compProjectionIntegrals(verts);
    float w = -apNormal[0] * verts[0] - verts[1] * apNormal[1] - verts[2] * apNormal[2];
    float k1 = 1.0f / apNormal[C];
    float k2 = k1 * k1;
    float k3 = k2 * k1;
    float k4 = k3 * k1;

    Fa = k1 * Pa;
    Fb = k1 * Pb;
    Fc = -k2 * (apNormal[A] * Pa + apNormal[B] * Pb + w * P1);

    m_fVertex0X = k1 * m_fComponent0;
    m_fVertex0Y = k1 * m_fComponent2;
    m_fVertex0Z =
        k3 * (S00cec3d0_Sqr(apNormal[A]) * m_fComponent0 + 2.0 * apNormal[A] * apNormal[B] * m_fComponent1 +
              S00cec3d0_Sqr(apNormal[B]) * m_fComponent2 + w * (2.0 * (apNormal[A] * Pa + apNormal[B] * Pb) + w * P1));

    m_fVertex1X = k1 * m_fComponent3;
    m_fVertex1Y = k1 * m_fComponent6;
    m_fVertex1Z =
        -k4 *
        (S00cec3d0_Cube(apNormal[A]) * m_fComponent3 + 3.0 * S00cec3d0_Sqr(apNormal[A]) * apNormal[B] * m_fComponent4 +
         3.0 * apNormal[A] * S00cec3d0_Sqr(apNormal[B]) * m_fComponent5 + S00cec3d0_Cube(apNormal[B]) * m_fComponent6 +
         3.0 * w *
             (S00cec3d0_Sqr(apNormal[A]) * m_fComponent0 + 2.0 * apNormal[A] * apNormal[B] * m_fComponent1 +
              S00cec3d0_Sqr(apNormal[B]) * m_fComponent2) +
         w * w * (3.0 * (apNormal[A] * Pa + apNormal[B] * Pb) + w * P1));

    m_fVertex2X = k1 * m_fComponent4;
    m_fVertex2Y = -k2 * (apNormal[A] * m_fComponent5 + apNormal[B] * m_fComponent6 + w * m_fComponent2);
    m_fVertex2Z = k3 * (S00cec3d0_Sqr(apNormal[A]) * m_fComponent3 + 2.0 * apNormal[A] * apNormal[B] * m_fComponent4 +
                        S00cec3d0_Sqr(apNormal[B]) * m_fComponent5 +
                        w * (2.0 * (apNormal[A] * m_fComponent0 + apNormal[B] * m_fComponent1) + w * Pa));
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
// Builds a transform from input's basis, gets the shape's AABB, and writes the transform columns of the largest and second-largest extent axes to outA and outB.
// @fnv 0x00cedae0
// src: GUESS 0x00cedae0 (confidence: medium)
void Object_GetAABBExtentAxes(Shape* shape, const Matrix* input, hkVector4* outA, hkVector4* outB)
{
    Matrix matrix = *input;
    char ok;
    hkVector4 e0, e1, e2;
    HkgeometryutilityGsEhscNogsNoehsc_ComputeValues_00d5ac50(&ok, &matrix, &e0, &e1, &e2);
    __declspec(align(16)) Transform transform;
    transform.r[0] = _mm_setr_ps(e0.x, e1.x, e2.x, 0.0f);
    transform.r[1] = _mm_setr_ps(e0.y, e1.y, e2.y, 0.0f);
    transform.r[2] = _mm_setr_ps(e0.z, e1.z, e2.z, 0.0f);
    transform.r[3] = _mm_setzero_ps();
    hkAabb bounds;
    shape->getAabb(&transform, 0.0f, &bounds);
    hkVector4 extent, absolute;
    extent.m_vComponents = _mm_sub_ps(*reinterpret_cast<const LocalM128*>(&bounds.m_kMaximumCorner.x), *reinterpret_cast<const LocalM128*>(&bounds.m_kMinimumCorner.x));
    absolute.m_vComponents = _mm_and_ps(extent.m_vComponents, DAT_01017d10.m_vComponents);
    int first = absolute.maxAxis();
    extent(first) = 0.0f;
    absolute.m_vComponents = _mm_and_ps(extent.m_vComponents, DAT_01017d10.m_vComponents);
    int second = absolute.maxAxisSecond();
    outA->m_vComponents = transform.r[first];
    outB->m_vComponents = transform.r[second];
}

struct MotionLike
{
    int unk00;
    float field04;
    int unk08;
    int unk0c;
    LocalM128 field10;
    LocalM128 field20;
    LocalM128 field30;
    LocalM128 field40;
    LocalM128 field50;
    LocalM128 field60;
    LocalM128 field70;
    LocalM128 field80;
    float field90;
};
// Copies source field04 to destination field90, and source field10, field20, field30, field40 to destination field80, field50, field60, field70.
// @fnv 0x00cebdb0
// src: GUESS 0x00cebdb0 (confidence: medium)
void Hkpinertiatensorcomputer_CopySelectedSourceFields(const MotionLike* source, MotionLike* destination)
{
    destination->field90 = source->field04;
    destination->field80 = source->field10;
    destination->field50 = source->field20;
    destination->field60 = source->field30;
    destination->field70 = source->field40;
}

struct Sub
{
    void Multiply(const hkVector4* p);
};
struct Owner
{
    int unk00;
    float m04;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    Sub m20;
};
// Multiplies m04 by value, then calls Multiply on m20 with a hkVector4 broadcast from value.
// @fnv 0x00cebfd0
// src: XBOX_PDB 0x00cebfd0
static __declspec(noinline) void hkMatrix3_mul(Owner* self, float afScale)
{
    self->m04 *= afScale;
    hkVector4 tmp;
    tmp.m_vComponents = _mm_load_ss(&afScale);
    self->m20.Multiply(&tmp);
}
Owner* volatile g_owner;
volatile float g_value;
Owner* volatile g_sink;
void caller()
{
    hkMatrix3_mul(g_owner, g_value);
    g_sink = g_owner;
}


struct __declspec(align(16)) S00ceccf0_Mat
{
    hkVector4 c0;
    hkVector4 c1;
    hkVector4 c2;
    void Subtract(const S00ceccf0_Mat& o);
    S00ceccf0_Mat& operator=(const S00ceccf0_Mat& o)
    {
        c0.m_vComponents = o.c0.m_vComponents;
        c1.m_vComponents = o.c1.m_vComponents;
        c2.m_vComponents = o.c2.m_vComponents;
        return *this;
    }
};

struct S00ceccf0_Out
{
    float m_00;
    float m_04;
    int unk08;
    int unk0c;
    hkVector4 m_10;
    S00ceccf0_Mat m_20;
};

extern const double DAT_010cbf40;

// src: XBOX_PDB 0x00ceba60
static __declspec(noinline) void __cdecl hkpInertiaTensorComputer_computeSphereVolumeMassProperties(float a, float b, S00ceccf0_Out* out)
{
    out->m_10.m_vComponents = _mm_setzero_ps();
    out->m_00 = a * b;
    out->m_04 = a + b;
}

void(__cdecl* g_S00ceccf0_fp)(float, float, S00ceccf0_Out*) = &hkpInertiaTensorComputer_computeSphereVolumeMassProperties;

// src: XBOX_PDB 0x00cebfd0
static __declspec(noinline) void hkMatrix3_mul(S00ceccf0_Out* out, float value)
{
    out->m_00 *= value;
    out->m_04 *= value;
}

// Returns 1 for invalid span, start or t; otherwise combines two FUN_00ceba60 results (for start and start-t) into out, scales by span/(a-b), and returns 0.
// @fnv 0x00ceccf0
// src: GUESS 0x00ceccf0 (confidence: low)
int __cdecl hkpInertiaTensorComputer_computeSphereVolumeMassProperties_UpdateState_00ceccf0(float start, float span, float t, S00ceccf0_Out* out)
{
    if (span <= 0.0f)
    {
        return 1;
    }
    if (start <= t)
    {
        return 1;
    }
    if (t <= 0.0f)
    {
        return 1;
    }

    float d = start - t;
    float a = (float)(DAT_010cbf40 * start * start * start);
    float b = (float)(DAT_010cbf40 * d * d * d);

    S00ceccf0_Out x;
    S00ceccf0_Out y;
    LocalM128 zero = _mm_setzero_ps();
    x.m_20.c0.m_vComponents = zero;
    x.m_20.c1.m_vComponents = zero;
    x.m_20.c2.m_vComponents = zero;
    y.m_10.m_vComponents = zero;
    y.m_20.c0.m_vComponents = zero;
    y.m_20.c1.m_vComponents = zero;
    y.m_20.c2.m_vComponents = zero;
    x.m_00 = 0.0f;
    x.m_04 = 0.0f;
    y.m_00 = 0.0f;
    y.m_04 = 0.0f;

    hkpInertiaTensorComputer_computeSphereVolumeMassProperties(start, a, &x);
    hkpInertiaTensorComputer_computeSphereVolumeMassProperties(d, b, &y);

    S00ceccf0_Mat& r = out->m_20;
    out->m_10.m_vComponents = zero;
    r = x.m_20;
    r.Subtract(y.m_20);

    out->m_04 = x.m_04 - y.m_04;
    out->m_00 = x.m_00 - y.m_00;
    hkMatrix3_mul(out, span / (a - b));
    return 0;
}

// Incident-edge walk: detach edges touching `unk`, recurse to the other end,
// then fold the node's inertia diagonal with the children's sum and max.
// Local array is an inplace hkArray (cap 16, dont-free flag 0x80000000).

struct Edge
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int n14;
    int n18;
};

#include "../../../../../../include/hkMatrix3.h"

struct ShapeIface
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void getInertia(hkMatrix3* out);
};

struct Node
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    ShapeIface shape;
    int unkE4;
    char kind;
    bool isStatic() const
    {
        return kind == 5 || kind == 4;
    }
    ShapeIface* getMotion()
    {
        return &shape;
    }
    void hkpRigidBody_setInertiaLocal(hkMatrix3* m);
};

struct LocalArr
{
    Edge** m_data;
    int m_iElementCount;
    int m_cap;
    Edge* storage[16];
};

void __cdecl ResizeAudioStream(void* heap, void* array, int elemSize);

__forceinline void releaseArr(LocalArr* a)
{
    S_00cee1c0_Router* router = hkMemoryRouter_getInstance();
    S_00cee1c0_Heap* heap = router->heap;
    int cap = a->m_cap;
    a->m_iElementCount = 0;
    if ((cap & 0x80000000) == 0)
        heap->Free(a->m_data, (cap & 0x3fffffff) * 4);
}

__forceinline float fMinimumInputValue(float a, float b)
{
    return a > b ? a : b;
}
__forceinline float fTargetUpperBound(float a, float b)
{
    return a < b ? a : b;
}

// Recurses over arr's edges linked to the node, then for a non-static node limits its inertia diagonal entries and returns a clamped value; static nodes return 0.
// @fnv 0x00cedec0
// src: HAVOK_LIB 0x00cedec0
float __cdecl hkInertiaTensorComputer_optimizeInertiasOfConstraintTreeInt(S_00cee1c0_Arr* arr, int aiNode, float value)
{
    LocalArr local;
    local.m_data = &local.storage[0];
    local.m_iElementCount = 0;
    local.m_cap = (int)0x80000010u;

    for (int i = arr->m_iElementCount - 1; i >= 0; --i)
    {
        unsigned int* data = arr->m_data;
        Edge* e = (Edge*)data[i];
        int other;
        if (e->n14 == aiNode)
            other = e->n18;
        else if (e->n18 != aiNode)
            continue;
        else
            other = e->n14;
        if (other == 0)
            continue;

        int n = --arr->m_iElementCount;
        if (n != i)
            data[i] = data[n];

        S_00cee1c0_Router* router = hkMemoryRouter_getInstance();
        if (local.m_iElementCount == (local.m_cap & 0x3fffffff))
            ResizeAudioStream(router->heap, &local, 4);
        local.m_data[local.m_iElementCount++] = e;
    }

    float sum = 0.0f;
    float best = 0.0f;
    for (int i = local.m_iElementCount - 1; i >= 0; --i)
    {
        Edge* e = local.m_data[i];
        int other = (e->n14 == aiNode) ? e->n18 : e->n14;
        float r = hkInertiaTensorComputer_optimizeInertiasOfConstraintTreeInt(arr, other, value);
        sum += r;
        if (best < r)
            best = r;
    }

    Node* body = (Node*)aiNode;
    if (body->isStatic())
    {
        releaseArr(&local);
        return 0.0f;
    }

    hkMatrix3 m;
    ShapeIface* motion = body->getMotion();
    motion->getInertia(&m);

    float fIyy = m.m11;
    float fIzz = m.m22;
    float fIxx = m.m00;
    float maxDiag = fMinimumInputValue(fIxx, fMinimumInputValue(fIyy, fIzz));

    if (sum == 0.0f)
    {
        releaseArr(&local);
        return maxDiag;
    }

    float fClamped = fTargetUpperBound(sum, maxDiag * value);
    fClamped = fMinimumInputValue(fClamped, best);

    if (!(fClamped < fIxx))
        m.m00 = fClamped;
    if (!(fClamped < fIyy))
        m.m11 = fClamped;
    if (!(fClamped < fIzz))
        m.m22 = fClamped;

    body->hkpRigidBody_setInertiaLocal(&m);

    float result = fMinimumInputValue(fTargetUpperBound(maxDiag * value, maxDiag + sum), fClamped);
    releaseArr(&local);
    return result;
}

typedef union __declspec(intrin_type) __declspec(align(16)) __m128i
{
    int m128i_i32[4];
} __m128i;
extern "C" __m128i _mm_cvtsi32_si128(int);
LocalM128 _mm_castsi128_ps(__m128i);

struct Probe
{
    unsigned char flag;
    unsigned char status1;
    unsigned char status2;
    unsigned char status3;
    int next;
    int previous;
    int index;
};
struct Track
{
    int stage;
    int frame;
    int sequence;
    int timer;
    int interpolation;
    void FUN_00d76ca0();
    void hkgpConvexHull_build_00d77200(void* state, Probe* probe);
    int GetInnerField1A8();
    void ForwardCall_00d762f0();
    float GetMass();
    double hkgpConvexHull_getVolume();
    LocalM128* hkgpConvexHull_getCenterOfMass();
    LocalM128* hkgpConvexHull_getWorldInertia();
    void hkgpConvexHull_expandByPlanarMargin(float scale);
    void ReleaseStorage_00d76940();
};
struct RowMatrix
{
    LocalM128 row0, row1, row2;
    void Multiply(const Vec4* weight);
};
struct Receiver2
{
    float time;
    float enabled;
    float pad08;
    float pad0c;
    LocalM128 translation;
    RowMatrix matrix;
};
struct Status
{
    void hkgpConvexHull_BuildConfig_BuildConfig();
};
extern float DAT_011b153c;
extern double DAT_01020998;
extern double DAT_010cbf50;
extern double DAT_010cbf48;
inline LocalM128 scalarVector(float x)
{
    LocalM128 result = {x};
    return result;
}
extern "C" void _ReadWriteBarrier();
// Steps a Track until it reaches stage 3 past a threshold, stores its translation, matrix and time in receiver, and returns 0, or 1 if the stage is -1.
// @fnv 0x00cebbb0
// src: XBOX_PDB 0x00cebbb0
int __cdecl hkpInertiaTensorComputer_computeConvexHullMassProperties(void* state, float value, Receiver2* receiver)
{
    Track track;
    Probe probe;
    track.FUN_00d76ca0();
    ((Status*)&probe)->hkgpConvexHull_BuildConfig_BuildConfig();
    probe.flag = 1;
    track.hkgpConvexHull_build_00d77200(state, &probe);
    if (track.GetInnerField1A8() != -1)
    {
        float step = (float)(DAT_011b153c / DAT_01020998);
        float current = 0.0f;
        if (track.GetInnerField1A8() == 3)
        {
            track.ForwardCall_00d762f0();
            if (value > 0.0f)
            {
                float pulse = track.GetMass() * value;
                double p = pulse;
                _ReadWriteBarrier();
                current = p + value * DAT_010cbf50 * value * value / 3.0;
            }
        }
        while (track.GetInnerField1A8() != 3 || track.hkgpConvexHull_getVolume() < DAT_010cbf48)
        {
            track.hkgpConvexHull_build_00d77200(state, &probe);
            track.hkgpConvexHull_expandByPlanarMargin(step);
            if (track.GetInnerField1A8() == 3)
                track.ForwardCall_00d762f0();
            step += step;
        }
        receiver->translation = *track.hkgpConvexHull_getCenterOfMass();
        LocalM128* rows = track.hkgpConvexHull_getWorldInertia();
        RowMatrix* m = &receiver->matrix;
        m->row0 = rows[0];
        m->row1 = rows[1];
        m->row2 = rows[2];
        float total = (float)(current + track.hkgpConvexHull_getVolume());
        receiver->time = total;
        receiver->enabled = 1.0f;
        if (total > 0.0f && current > 0.0f)
        {
            float fRatio = (float)(current / total + 1.0);
            Vec4 ratio;
            LocalM128 scalar = _mm_load_ss(&fRatio);
            *(LocalM128*)&ratio = scalar;
            m->Multiply(&ratio);
        }
        track.ReleaseStorage_00d76940();
        return 0;
    }
    track.ReleaseStorage_00d76940();
    return 1;
}

struct S_00ced310_M
{
    hkVector4 c0, c1, c2;
};

static __forceinline float S_Max(float a, float b)
{
    return a > b ? a : b;
}

static __forceinline void S_SetZero(S_00ced310_M* m)
{
    LocalM128 z = _mm_setzero_ps();
    _ReadWriteBarrier();
    _mm_store_ps(&m->c0.x, z);
    _mm_store_ps(&m->c1.x, z);
    _mm_store_ps(&m->c2.x, z);
}

// Stores the maximum of the three diagonal components of m into all three diagonal slots, zeroing the rest.
// @fnv 0x00ced310
void __cdecl SetDiagonal(S_00ced310_M* m)
{
    float d = S_Max(S_Max(m->c0.x, m->c1.y), m->c2.z);
    S_SetZero(m);
    m->c0.x = d;
    m->c1.y = d;
    m->c2.z = d;
}

namespace fnv_00cefb90 {

// Mass properties and inertia helpers for surface geometry.
struct CE50Matrix
{
    hkVector4 row0, row1, row2;
    void FUN_00cd5140(const CE50Matrix* source);
};
struct CE50Body
{
    float volume;
    float mass;
    hkVector4 center;
    CE50Matrix inertia;
};

struct CEFBTri
{
    int a, b, c, material;
};
struct CEFBGeom
{
    hkVector4* verts;
    int vertCount;
    unsigned vertCap;
    CEFBTri* tris;
    int triCount;
    unsigned triCap;
};

struct CEFBAreas
{
    float* data;
    int size;
    unsigned m_iCapacity;
};

void __cdecl hkArrayUtil__reserve(S_00cee1c0_Heap* heap, CEFBAreas* arr, int count, int elemSize);
int __cdecl hkVector4_UpdateState_00cee290(const hkVector4* v0, const hkVector4* v1, const hkVector4* v2, float triMass,
                         float thickness, CE50Body* out);
extern "C" void _ReadWriteBarrier(void);

__declspec(noinline) void __cdecl AddInertiaTensor(float* c, float m, float* I)
{
    I[0] += m * (c[1] * c[1] + c[2] * c[2]);
    I[5] += m * (c[0] * c[0] + c[2] * c[2]);
    I[10] += m * (c[0] * c[0] + c[1] * c[1]);
    float xy = I[1] - m * c[0] * c[1];
    I[1] = I[4] = xy;
    float yz = I[6] - m * c[1] * c[2];
    I[6] = I[9] = yz;
    float zx = I[8] - m * c[2] * c[0];
    I[8] = I[2] = zx;
}
void __cdecl hkpInertiaTensorComputer_computeBoxVolumeMassProperties_ComputeGeometryMassProperties(const CEFBGeom* geometry, float mass, CE50Body* out);
// src: GUESS 0x00cee290 (confidence: low)
__declspec(noinline) int __cdecl hkVector4_UpdateState_00cee290(const hkVector4* a, const hkVector4* b, const hkVector4* c, float mass,
                                              float thickness, CE50Body* out)
{
    if (mass <= 0.0f || thickness < 0.0f)
        return 1;
    LocalM128 ab = _mm_sub_ps(a->m_vComponents, b->m_vComponents);
    LocalM128 cb = _mm_sub_ps(c->m_vComponents, b->m_vComponents);
    LocalM128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(ab, ab, 0xd2), _mm_shuffle_ps(cb, cb, 0xc9)),
                              _mm_mul_ps(_mm_shuffle_ps(ab, ab, 0xc9), _mm_shuffle_ps(cb, cb, 0xd2)));
    LocalM128 sq = _mm_mul_ps(cross, cross);
    LocalM128 len = _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq)));
    float length;
    _mm_store_ss(&length, len);
    hkVector4 center;
    float thirdF = 1.0f / 3.0f;
    LocalM128 thirdV = _mm_load_ss(&thirdF);
    LocalM128 third = _mm_shuffle_ps(thirdV, thirdV, 0);
    center.m_vComponents = _mm_mul_ps(_mm_add_ps(_mm_add_ps(a->m_vComponents, b->m_vComponents), c->m_vComponents), third);
    CE50Matrix inertia;
    if (thickness < 1e-5f)
    {
        float xx = (float)((a->x * a->x + b->x * b->x + c->x * c->x + 9.0 * center.x * center.x) * mass / 12.0);
        float yy = (float)((a->y * a->y + b->y * b->y + c->y * c->y + 9.0 * center.y * center.y) * mass / 12.0);
        float zz = (float)((a->z * a->z + b->z * b->z + c->z * c->z + 9.0 * center.z * center.z) * mass / 12.0);
        inertia.row0.x = yy + zz;
        inertia.row1.y = xx + zz;
        inertia.row2.z = xx + yy;
        inertia.row0.y = inertia.row1.x =
            -(float)((a->x * a->y + b->x * b->y + c->x * c->y + 9.0 * center.x * center.y) * mass / 12.0);
        inertia.row0.z = inertia.row2.x =
            -(float)((a->x * a->z + b->x * b->z + c->x * c->z + 9.0 * center.x * center.z) * mass / 12.0);
        inertia.row1.z = inertia.row2.y =
            -(float)((a->y * a->z + b->y * b->z + c->y * c->z + 9.0 * center.y * center.z) * mass / 12.0);
        hkpInertiaTensorComputer_shiftInertiaToCom(&center, mass, &inertia.row0.x);
    }
    else if (length <= 0.0f)
    {
        inertia.row0.x = mass * (center.y * center.y + center.z * center.z);
        inertia.row1.y = mass * (center.x * center.x + center.z * center.z);
        inertia.row2.z = mass * (center.x * center.x + center.y * center.y);
        inertia.row0.y = inertia.row1.x = -mass * center.x * center.y;
        inertia.row0.z = inertia.row2.x = -mass * center.x * center.z;
        inertia.row1.z = inertia.row2.y = -mass * center.y * center.z;
    }
    else
    {
        float halfThickness = thickness * 0.5f;
        LocalM128 inv = _mm_load_ss(&length);
        inv = _mm_div_ss(_mm_load_ss(&halfThickness), inv);
        LocalM128 delta = _mm_mul_ps(cross, _mm_shuffle_ps(inv, inv, 0));
        hkVector4 points[6];
        points[0].m_vComponents = _mm_add_ps(a->m_vComponents, delta);
        points[1].m_vComponents = _mm_sub_ps(a->m_vComponents, delta);
        points[2].m_vComponents = _mm_add_ps(b->m_vComponents, delta);
        points[3].m_vComponents = _mm_sub_ps(b->m_vComponents, delta);
        points[4].m_vComponents = _mm_add_ps(c->m_vComponents, delta);
        points[5].m_vComponents = _mm_sub_ps(c->m_vComponents, delta);
        CEFBTri faces[8] = {{0, 2, 4, -1}, {1, 5, 3, -1}, {0, 3, 2, -1}, {0, 1, 3, -1},
                            {1, 0, 4, -1}, {1, 4, 5, -1}, {2, 5, 4, -1}, {2, 3, 5, -1}};
        CEFBGeom prism = {points, 6, 0x80000006u, faces, 8, 0x80000008u};
        hkpInertiaTensorComputer_computeBoxVolumeMassProperties_ComputeGeometryMassProperties(&prism, mass, out);
        center = out->center;
        inertia = out->inertia;
    }
    out->mass = mass;
    out->volume = length * 0.5f * thickness;
    out->center = center;
    out->inertia = inertia;
    return 0;
}

struct BoolFlag
{
    char value;
};
// Computes the rigid body properties (mass, center of mass, and inertia tensor) for a CEFBGeom by summing contributions from each triangle.
// @fnv 0x00cefb90
// src: GUESS 0x00cefb90 (confidence: medium)
int __cdecl hkVector4_ComputeTriangleSurfaceMassProperties(const CEFBGeom* geom, float surfaceThickness, BoolFlag distributeUniformly, float mass,
                         CE50Body* result)
{
    if (mass <= 0.0f)
        return 1;
    if (surfaceThickness <= 0.0f)
        return 1;

    _ReadWriteBarrier();

    LocalM128 zero = _mm_setzero_ps();
    CE50Matrix* inertia = &result->inertia;
    inertia->row0.m_vComponents = zero;
    inertia->row1.m_vComponents = zero;
    inertia->row2.m_vComponents = zero;
    hkVector4* center = &result->center;
    center->m_vComponents = zero;

    int count = geom->triCount;
    CEFBAreas triAreas;
    triAreas.data = 0;
    triAreas.size = 0;
    triAreas.m_iCapacity = 0x80000000u;

    S_00cee1c0_Router* router = hkMemoryRouter_getInstance();
    S_00cee1c0_Heap* heap = router->heap;
    int cap = (int)(triAreas.m_iCapacity & 0x3fffffffu);
    if (cap < count)
    {
        int iNewCapacity = cap + cap;
        if (count >= iNewCapacity)
            iNewCapacity = count;
        hkArrayUtil__reserve(heap, &triAreas, iNewCapacity, 4);
    }

    float total = 0.0f;
    int i = 0;
    triAreas.size = count;
    for (; i < geom->triCount; ++i)
    {
        const CEFBTri* tri = &geom->tris[i];
        LocalM128 vb = geom->verts[tri->b].m_vComponents;
        LocalM128 e2 = _mm_sub_ps(geom->verts[tri->c].m_vComponents, vb);
        LocalM128 e0 = _mm_sub_ps(geom->verts[tri->a].m_vComponents, vb);
        LocalM128 yzxE0 = _mm_shuffle_ps(e0, e0, 0xC9);
        LocalM128 zxyE2 = _mm_shuffle_ps(e2, e2, 0xD2);
        LocalM128 yzxE2 = _mm_shuffle_ps(e2, e2, 0xC9);
        LocalM128 prodA = _mm_mul_ps(yzxE0, zxyE2);
        LocalM128 zxyE0 = _mm_shuffle_ps(e0, e0, 0xD2);
        LocalM128 prodB = _mm_mul_ps(zxyE0, yzxE2);
        LocalM128 vCross = _mm_sub_ps(prodB, prodA);
        LocalM128 sq = _mm_mul_ps(vCross, vCross);
        LocalM128 yy = _mm_shuffle_ps(sq, sq, 0x55);
        LocalM128 sum = _mm_add_ss(yy, sq);
        LocalM128 zz = _mm_shuffle_ps(sq, sq, 0xAA);
        sum = _mm_add_ss(zz, sum);
        sum = _mm_sqrt_ss(sum);
        float len;
        _mm_store_ss(&len, sum);
        if (distributeUniformly.value)
        {
            if (len < 1e-5f)
                triAreas.data[i] = 5e-6f;
            else
                triAreas.data[i] = (float)(len * 0.5);
        }
        else
        {
            triAreas.data[i] = 1.0f;
        }
        total += triAreas.data[i];
    }

    for (int j = 0; j < geom->triCount; ++j)
    {
        const CEFBTri* __restrict tri = &geom->tris[j];
        hkVector4 v0;
        hkVector4 v1;
        hkVector4 v2;
        v0.m_vComponents = geom->verts[tri->a].m_vComponents;
        v1.m_vComponents = geom->verts[tri->b].m_vComponents;
        v2.m_vComponents = geom->verts[tri->c].m_vComponents;
        float triMass = triAreas.data[j] * mass / total;

        CE50Body triBody;
        triBody.volume = 0.0f;
        triBody.mass = 0.0f;
        triBody.center.m_vComponents = zero;
        triBody.inertia.row0.m_vComponents = zero;
        triBody.inertia.row1.m_vComponents = zero;
        triBody.inertia.row2.m_vComponents = zero;
        hkVector4_UpdateState_00cee290(&v0, &v1, &v2, triMass, surfaceThickness, &triBody);

        CE50Matrix shiftedInertia;
        shiftedInertia.row0.m_vComponents = triBody.inertia.row0.m_vComponents;
        shiftedInertia.row1.m_vComponents = triBody.inertia.row1.m_vComponents;
        shiftedInertia.row2.m_vComponents = triBody.inertia.row2.m_vComponents;

        LocalM128 com = triBody.center.m_vComponents;
        LocalM128 vTriMass = _mm_load_ss(&triMass);
        LocalM128 scale = _mm_shuffle_ps(vTriMass, vTriMass, 0);
        center->m_vComponents = _mm_add_ps(center->m_vComponents, _mm_mul_ps(scale, com));

        hkVector4 comCopy;
        comCopy.m_vComponents = com;
        AddInertiaTensor(&comCopy.x, triMass, &shiftedInertia.row0.x);
        inertia->FUN_00cd5140(&shiftedInertia);
    }

    result->mass = mass;
    float invMass = 1.0f / mass;
    LocalM128 vInvMass = _mm_load_ss(&invMass);
    LocalM128 inv = _mm_shuffle_ps(vInvMass, vInvMass, 0);
    center->m_vComponents = _mm_mul_ps(inv, center->m_vComponents);
    hkpInertiaTensorComputer_shiftInertiaToCom(center, mass, &inertia->row0.x);

    S_00cee1c0_Router* freeRouter = hkMemoryRouter_getInstance();
    S_00cee1c0_Heap* freeHeap = freeRouter->heap;
    int flags = (int)triAreas.m_iCapacity;
    triAreas.size = 0;
    if ((flags & 0x80000000) == 0)
    {
        unsigned bytes = ((unsigned)flags & 0x3fffffffu);
        bytes += bytes;
        bytes += bytes;
        freeHeap->Free(triAreas.data, bytes);
    }
    return 0;
}
}  // namespace fnv_00cefb90


struct S_00ced090_Elem
{
    float unk00;
    float unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
};
struct S_00ced090_Out
{
    float unk00;
    float unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};
struct S_00ced090_State
{
    S_00ced090_Elem* first;
    int count;
};
struct S_00ced090_Mat
{
    hkVector4 r0, r1, r2;
    void FUN_00cd5880(void* xf);
};
struct S_00ced090_Inertia
{
    hkVector4 r0, r1, r2;
    void FUN_00cd5140(S_00ced090_Mat* m);
};
void __cdecl AddInertiaTensor(hkVector4* d, float m, S_00ced090_Mat* mat);

// Sums mass and mass-weighted center and accumulates an inertia tensor over the elements into out; returns 1 if the total mass is not positive.
// @fnv 0x00ced090
// src: XBOX_PDB 0x00ced090
int __cdecl hkpInertiaTensorComputer_combineMassProperties(S_00ced090_State* apState, S_00ced090_Out* out)
{
    float mass = 0.0f;
    float sum0 = 0.0f;
    LocalM128 vAccum = _mm_setzero_ps();
    for (int i = 0; i < apState->count; i++)
    {
        hkVector4 v;
        v.setTransformedPos_00c7f640(*reinterpret_cast<const Transform*>(&apState->first[i].unk50), *reinterpret_cast<const hkVector4*>(&apState->first[i].unk10));
        LocalM128 t = _mm_load_ss(&apState->first[i].unk04);
        mass = mass + apState->first[i].unk04;
        sum0 += apState->first[i].unk00;
        vAccum = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(t, t, 0), v.m_vComponents), vAccum);
    }
    if (mass <= 0.0f)
        return 1;
    float inv = 1.0f / mass;
    S_00ced090_Inertia* pInertia = (S_00ced090_Inertia*)&out->unk20;
    out->unk04 = mass;
    vAccum = _mm_mul_ps(_mm_set_ps1(inv), vAccum);
    *(LocalM128*)&out->unk10 = vAccum;
    out->unk00 = sum0;
    S_00ced090_Inertia* I = pInertia;
    *(LocalM128*)&I->r0 = _mm_setzero_ps();
    *(LocalM128*)&I->r1 = _mm_setzero_ps();
    *(LocalM128*)&I->r2 = _mm_setzero_ps();
    for (int i = 0; i < apState->count; i++)
    {
        S_00ced090_Mat m;
        *(LocalM128*)&m.r0 = *(LocalM128*)&apState->first[i].unk20;
        *(LocalM128*)&m.r1 = *(LocalM128*)&apState->first[i].unk30;
        *(LocalM128*)&m.r2 = *(LocalM128*)&apState->first[i].unk40;
        m.FUN_00cd5880(&apState->first[i].unk50);
        hkVector4 v;
        v.setTransformedPos_00c7f640(*reinterpret_cast<const Transform*>(&apState->first[i].unk50), *reinterpret_cast<const hkVector4*>(&apState->first[i].unk10));
        v.m_vComponents = _mm_sub_ps(v.m_vComponents, vAccum);
        AddInertiaTensor(&v, apState->first[i].unk04, &m);
        I->FUN_00cd5140(&m);
    }
    return 0;
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
extern __declspec(thread) int DAT_012722b4;

struct S00cf0f40_Guard
{
    int m_saved;
    S00cf0f40_Guard()
    {
        m_saved = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }
    ~S00cf0f40_Guard()
    {
        DAT_012722b4 = m_saved;
    }
};

struct S00cf0f40_Stream
{
    int unk00;
    unsigned int m_pos;
    unsigned int(__cdecl* m_read)(S00cf0f40_Stream* self, void* dst, unsigned int size, unsigned int* comp,
                                  unsigned int n);
    unsigned int BinaryRead(void* p, unsigned int size, unsigned int* comp, unsigned int n)
    {
        unsigned int r = m_read(this, p, size, comp, n);
        m_pos += r;
        return r;
    }
};

inline unsigned int S00cf0f40_Load(S00cf0f40_Stream& s, unsigned int* p, unsigned int n)
{
    unsigned int uiSize = sizeof(unsigned int);
    return s.BinaryRead(p, n * sizeof(unsigned int), &uiSize, 1);
}

struct S00cf0f40_Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
    unsigned char unk1E6;
    unsigned char unk1E7;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    S00cf0f40_Stream* m_stream;
};


struct S00cf0f40_Arr;
inline S_00cee1c0_Heap& S00cf0f40_heap(S_00cee1c0_Router* r)
{
    return *r->heap;
}
void __cdecl hkArrayUtil__reserve(S_00cee1c0_Heap* heap, void* arr, int cap, int elemSize);

struct S00cf0f40_Arr
{
    hkVector4* m_data;
    int m_iElementCount;
    int m_capFlags;

    int getCapacity() const
    {
        return m_capFlags & 0x3fffffff;
    }
    void ClearAndRelease()
    {
        S_00cee1c0_Heap& heap = S00cf0f40_heap(hkMemoryRouter_getInstance());
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0)
            heap.Free(m_data, getCapacity() * sizeof(hkVector4));
        m_data = 0;
        m_capFlags = 0x80000000;
    }
    void reserve(int n)
    {
        S_00cee1c0_Heap& heap = S00cf0f40_heap(hkMemoryRouter_getInstance());
        int cap = getCapacity();
        if (cap < n)
        {
            int nc = cap * 2;
            hkArrayUtil__reserve(&heap, this, n < nc ? nc : n, sizeof(hkVector4));
        }
    }
    void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
};

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
inline void S00cf0f40_Swap4(void* p)
{
    unsigned int t;
    memcpy(&t, p, 4);
    t = _byteswap_ulong(t);
    memcpy(p, &t, 4);
}

// @fnv 0x00cf0f40
// src: XBOX_PDB 0x00cf0f40
unsigned int __cdecl bhkStream_LoadBinary(S00cf0f40_Owner* owner, S00cf0f40_Arr* arr)
{
    S00cf0f40_Guard guard;
    unsigned int n = 0;
    S00cf0f40_Load(*owner->m_stream, &n, 1);
    arr->ClearAndRelease();
    arr->SetSizeAndGrow(n);
    unsigned int bytes = n * sizeof(hkVector4);
    for (unsigned int i = 0; i < n; ++i)
    {
        owner->m_stream->BinaryRead(&arr->m_data[i], sizeof(hkVector4), 0, 0);
        if (owner->m_1e5 != 1)
        {
            hkVector4* v = &arr->m_data[i];
            S00cf0f40_Swap4(&v->x);
            S00cf0f40_Swap4(&v->y);
            S00cf0f40_Swap4(&v->z);
            S00cf0f40_Swap4(&v->w);
        }
    }
    return bytes;
}

extern "C" void _ReadWriteBarrier();

extern const double DAT_010290c0;
extern const double DAT_010cbf40;

struct Target
{
    float m_f00;
    float m_f04;
    unsigned int unk08;
    unsigned int unk0C;
    LocalM128 m_v10;
    union
    {
        LocalM128 m_v20;
        struct
        {
            float m_f20;
            float unk24;
            float unk28;
            float unk2C;
        };
    };
    union
    {
        LocalM128 m_v30;
        struct
        {
            float unk30;
            float m_f34;
            float unk38;
            float unk3C;
        };
    };
    union
    {
        LocalM128 m_v40;
        struct
        {
            float unk40;
            float unk44;
            float m_f48;
            float unk4C;
        };
    };
};

// Returns 1 if a or b is not positive; otherwise sets three diagonal entries to a*b*a*DAT_010290c0, m_f00 to a^3*DAT_010cbf40 and m_f04 to b, and returns 0.
// @fnv 0x00ceba60
// src: XBOX_PDB 0x00ceba60
int __cdecl hkpInertiaTensorComputer_computeSphereVolumeMassProperties(float a, float b, Target* t)
{
    if (b <= 0.0f)
        return 1;
    if (a <= 0.0f)
        return 1;
    Target* o = t;
    o->m_v20 = _mm_setzero_ps();
    o->m_v30 = _mm_setzero_ps();
    o->m_v40 = _mm_setzero_ps();
    float x = (float)(a * b * a * DAT_010290c0);
    *(volatile float*)&o->m_f20 = 1.0f;
    *(volatile float*)&o->m_f34 = 1.0f;
    *(volatile float*)&o->m_f48 = 1.0f;
    _ReadWriteBarrier();
    o->m_v10 = _mm_setzero_ps();
    *(volatile float*)&o->m_f20 = x;
    o->m_f34 = x;
    o->m_f48 = x;
    float y = (float)(a * ((a * DAT_010cbf40) * a));
    o->m_f00 = y;
    o->m_f04 = b;
    return 0;
}

extern double DAT_01012638;

struct VertexComponentData
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

    void InternalInertiaTensorComputer_compProjectionIntegrals(const float* verts);
};

// Accumulates polynomial integrals over three segments of verts and stores the scaled results in P1, Pa, Pb and m_fComponent0 through m_fComponent6.
// @fnv 0x00cec000
// src: HAVOK_LIB 0x00cec000
void VertexComponentData::InternalInertiaTensorComputer_compProjectionIntegrals(const float* verts)
{
    float a0, a1, da;
    float b0, b1, db;
    float a0_2, a0_3, a0_4, b0_2, b0_3, b0_4;
    float a1_2, a1_3, b1_2, b1_3;
    float C1, Ca, Caa, Caaa, Cb, Cbb, Cbbb;
    float Cab, Kab, Caab, Kaab, Cabb, Kabb;
    int i;

    P1 = Pa = Pb = m_fComponent0 = m_fComponent1 = m_fComponent2 = m_fComponent3 = m_fComponent4 = m_fComponent5 =
        m_fComponent6 = 0.0f;

    for (i = 0; i < 3; i++)
    {
        a0 = verts[i * 4 + A];
        b0 = verts[i * 4 + B];
        a1 = verts[((i + 1) % 3) * 4 + A];
        b1 = verts[((i + 1) % 3) * 4 + B];
        da = a1 - a0;
        db = b1 - b0;
        a0_2 = a0 * a0;
        a0_3 = a0_2 * a0;
        a0_4 = a0_3 * a0;
        b0_2 = b0 * b0;
        b0_3 = b0_2 * b0;
        b0_4 = b0_3 * b0;
        a1_2 = a1 * a1;
        a1_3 = a1_2 * a1;
        b1_2 = b1 * b1;
        b1_3 = b1_2 * b1;

        C1 = a1 + a0;
        Ca = a1 * C1 + a0_2;
        Caa = a1 * Ca + a0_3;
        Caaa = a1 * Caa + a0_4;
        Cb = b1 * (b1 + b0) + b0_2;
        Cbb = b1 * Cb + b0_3;
        Cbbb = b1 * Cbb + b0_4;
        Cab = 3 * a1_2 + 2 * a1 * a0 + a0_2;
        Kab = a1_2 + 2 * a1 * a0 + 3 * a0_2;
        Caab = a0 * Cab + 4 * a1_3;
        Kaab = a1 * Kab + 4 * a0_3;
        Cabb = 4 * b1_3 + 3 * b1_2 * b0 + 2 * b1 * b0_2 + b0_3;
        Kabb = b1_3 + 2 * b1_2 * b0 + 3 * b1 * b0_2 + 4 * b0_3;

        P1 += db * C1;
        Pa += db * Ca;
        m_fComponent0 += db * Caa;
        m_fComponent3 += db * Caaa;
        Pb += da * Cb;
        m_fComponent2 += da * Cbb;
        m_fComponent6 += da * Cbbb;
        m_fComponent1 += db * (b1 * Cab + b0 * Kab);
        m_fComponent4 += db * (b1 * Caab + b0 * Kaab);
        m_fComponent5 += da * (a1 * Cabb + a0 * Kabb);
    }

    P1 /= 2.0f;
    Pa /= 6.0f;
    m_fComponent0 /= 12.0f;
    m_fComponent3 /= 20.0f;
    Pb /= -6.0f;
    m_fComponent2 /= -12.0f;
    m_fComponent6 /= -20.0f;
    m_fComponent1 /= 24.0f;
    m_fComponent4 /= DAT_01012638;
    m_fComponent5 /= -60.0f;
}

extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;
struct Inertia
{
    hkVector4 row0, row1, row2;
    void Multiply(const LocalM128*);
};
struct MassBody
{
    float volume, mass;
    hkVector4 center;
    Inertia inertia;
    MassBody() : volume(0.0f), mass(0.0f)
    {
        _mm_store_ps(&center.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row0.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row1.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row2.x, _mm_setzero_ps());
    }
};
typedef S_00cee1c0_Heap Heap;
typedef S_00cee1c0_Router Router;
struct Handle
{
    hkVector4* data;
    int count, capacity;
    __forceinline void release(Heap* heap)
    {
        count = 0;
        if ((capacity & 0x80000000) == 0)
            heap->Free(data, (capacity & 0x3fffffff) * 16);
    }
};
struct View
{
    hkVector4* data;
    int count, stride;
};
struct __declspec(align(16)) Query
{
    unsigned int shapeBuffer[128];
};
struct ShapeVector
{
    float x, y, z, w;
};
__forceinline void InitializeTranslatedTransform(Transform* matrix, const ShapeVector& offset)
{
    _mm_store_ps(&matrix->m_f00, _mm_setzero_ps());
    matrix->m_f00 = 1.0f;
    _mm_store_ps(&matrix->m_f10, _mm_setzero_ps());
    matrix->m_f14 = 1.0f;
    _mm_store_ps(&matrix->m_f20, _mm_setzero_ps());
    matrix->m_f28 = 1.0f;
    _mm_store_ps(&matrix->m_f30, (const LocalM128&)offset);
}
struct HkShape
{
    virtual void v00();
    virtual void v04();
    virtual int First();
    virtual int Next(int);
    virtual HkShape* Container();
    virtual HkShape* Find(int, Query*);
    int m04, m08, tag;
    union
    {
        float radius;
        int count;
    };
    HkShape* child14;
    HkShape* child18;
    int m1c;
    ShapeVector v20, v30, v40;
    __forceinline int GetType() const
    {
        return tag;
    }
    float FUN_00d571a0();
    void FUN_00d59200(Handle*);
};
struct TreeShape : HkShape
{
    virtual HkShape* Container();
};
struct ScaledShape
{
    int m00, m04, m08, m0c, m10, m14, m18, m1c;
    hkVector4 m20, m30;
    void FUN_00cd8160(float);
};
void __cdecl ResizeAudioStream(void*, void*, int);
void __cdecl hkpInertiaTensorComputer_computeBoxVolumeMassProperties(hkVector4*, float, MassBody*);
void __cdecl hkpInertiaTensorComputer_computeCapsuleVolumeMassProperties(hkVector4*, hkVector4*, float, float, MassBody*);
void __cdecl hkpInertiaTensorComputer_computeCylinderVolumeMassProperties(hkVector4*, hkVector4*, float, float, MassBody*);
float __cdecl NiMax(float, float);
void __cdecl hkVector4_UpdateState_00cee290(hkVector4*, hkVector4*, hkVector4*, float, float, MassBody*);
void __cdecl hkpInertiaTensorComputer_combineMassProperties(void*, MassBody*);
struct RawBody
{
    float volume, mass;
    hkVector4 center;
    Inertia inertia;
};
struct Element
{
    RawBody body;
    Transform transform;
    __forceinline void Initialize()
    {
        body.volume = 0.0f;
        _mm_store_ps(&body.center.x, _mm_setzero_ps());
        body.mass = 0.0f;
        _mm_store_ps(&body.inertia.row0.x, _mm_setzero_ps());
        _mm_store_ps(&body.inertia.row1.x, _mm_setzero_ps());
        _mm_store_ps(&body.inertia.row2.x, _mm_setzero_ps());
        _mm_store_ps(&transform.m_f00, _mm_setzero_ps());
        _mm_store_ps(&transform.m_f10, _mm_setzero_ps());
        _mm_store_ps(&transform.m_f20, _mm_setzero_ps());
        transform.m_f00 = 1.0f;
        transform.m_f14 = 1.0f;
        transform.m_f28 = 1.0f;
        _mm_store_ps(&transform.m_f30, _mm_setzero_ps());
    }
    void FUN_00cf0820(const MassBody*);
};
union PrimitiveTemporary
{
    Handle vertices;
    LocalM128 vector;
};
// VC9 unions cannot contain the shared Transform or hkVector4 copy constructors.
// Keep aligned storage and access it through the shared types.
union ShapeTemporary
{
    LocalM128 local[sizeof(Transform) / sizeof(LocalM128)];
    LocalM128 scaled[sizeof(ScaledShape) / sizeof(LocalM128)];
};
struct Working
{
    ShapeTemporary temp;
    Transform combined;
    MassBody body;
};
struct Array
{
    Element* data;
    int count, capacity;
    Element local[2];
    __forceinline void release(Heap* heap)
    {
        count = 0;
        if ((capacity & 0x80000000) == 0)
            heap->Free(data, (capacity & 0x3fffffff) * 0x90);
    }
};

// Array contains Transform instances, so its union arm also needs raw storage.
union ResultStorage
{
    Query query;
    LocalM128 array[sizeof(Array) / sizeof(LocalM128)];
};

// Recursively computes the mass, volume, center of mass, and inertia of an HkShape into output, handling primitives, composites, and containers.
// @fnv 0x00ceff00
// src: XBOX_PDB 0x00ceff00
void __cdecl computeRecursiveShapeVolumeMassProperties(HkShape* apShape, const Transform& transform, float limit, MassBody& output)
{
    Working workspace;
    ResultStorage storage;
    PrimitiveTemporary primitive;
    hkVector4& vectorA = reinterpret_cast<hkVector4&>(primitive.vector);
    hkVector4 vectorB;
    MassBody& body = workspace.body;
    Transform& combined = workspace.combined;
    Transform& local = reinterpret_cast<Transform&>(workspace.temp.local);
    LocalM128 zero = _mm_setzero_ps();
    int shapeType = apShape->GetType();
    switch (shapeType)
    {
    case 1:
        hkpInertiaTensorComputer_computeSphereVolumeMassProperties(apShape->radius, 1.0f, (S00ceccf0_Out*)&body);
        break;
    case 4: {
        float r = apShape->radius;
        hkVector4& radii = vectorA;
        LocalM128 radius = _mm_set_ps1(r);
        LocalM128 halfExtents = (const LocalM128&)apShape->v20;
        radius = _mm_add_ps(radius, halfExtents);
        _mm_store_ps(&radii.x, radius);
        hkpInertiaTensorComputer_computeBoxVolumeMassProperties(&radii, 1.0f, &body);
        break;
    }
    case 6: {
        Handle& h = primitive.vertices;
        h.data = 0;
        h.count = 0;
        h.capacity = 0x80000000;
        apShape->FUN_00d59200(&h);
        View view;
        view.data = h.data;
        view.count = h.count;
        view.stride = 16;
        hkpInertiaTensorComputer_computeConvexHullMassProperties(&view, apShape->radius, &body);
        Router* vertexRouter = (Router*)hkMemoryRouter_getInstance();
        h.release(vertexRouter->heap);
        break;
    }
    case 3: {
        hkVector4& a = *reinterpret_cast<hkVector4*>(workspace.temp.local);
        hkVector4& b = vectorB;
        hkVector4& c = vectorA;
        _mm_store_ps(&a.x, _mm_load_ps(&apShape->v20.x));
        _mm_store_ps(&b.x, _mm_load_ps(&apShape->v30.x));
        _mm_store_ps(&c.x, _mm_load_ps(&apShape->v40.x));
        hkVector4_UpdateState_00cee290(&a, &b, &c, 1.0f, NiMax(apShape->radius, limit), &body);
        break;
    }
    case 27:
        computeRecursiveShapeVolumeMassProperties(apShape->child18, transform, limit, output);
        return;
    case 11: {
        InitializeTranslatedTransform(&local, apShape->v20);
        combined.hkTransform_setMul(&transform, &local);
        computeRecursiveShapeVolumeMassProperties(apShape->child18, combined, limit, output);
        return;
    }
    case 12: {
        combined.hkTransform_setMul(&transform, (const Transform*)&apShape->v20);
        computeRecursiveShapeVolumeMassProperties(apShape->child18, combined, limit, output);
        return;
    }
    case 15: {
        combined.hkTransform_setMul(&transform, (const Transform*)&apShape->v30);
        computeRecursiveShapeVolumeMassProperties(apShape->child14, combined, limit, output);
        return;
    }
    case 21: {
        int i = 0;
        if (apShape->count > 0)
        {
            hkVector4* walk = (hkVector4*)&apShape->v20;
            do
            {
                _mm_store_ps(&combined.m_f00, _mm_load_ps(&transform.m_f00));
                _mm_store_ps(&combined.m_f10, _mm_load_ps(&transform.m_f10));
                _mm_store_ps(&combined.m_f20, _mm_load_ps(&transform.m_f20));
                _mm_store_ps(&combined.m_f30, _mm_load_ps(&transform.m_f30));
                reinterpret_cast<hkVector4&>(combined.r[3]).setTransformedPos_00c7f640(combined, *walk);
                ScaledShape& scaled = reinterpret_cast<ScaledShape&>(workspace.temp.scaled);
                scaled.FUN_00cd8160(walk->w);
                computeRecursiveShapeVolumeMassProperties((HkShape*)&scaled, combined, limit, output);
                ++i;
                ++walk;
            } while (i < apShape->count);
        }
        return;
    }
    case 7:
    case 8:
    case 9:
    case 10:
    case 14:
    case 22:
    case 23: {
        HkShape* container;
        if (apShape->GetType() == 8 || apShape->GetType() == 10)
        {
            TreeShape* tree = (TreeShape*)apShape;
            container = tree->Container();
        }
        else
        {
            container = apShape->Container();
        }
        int id = container->First();
        if (id == -1)
            return;
        Query& q = storage.query;
        for (;;)
        {
            HkShape* found = container->Find(id, &q);
            if (found)
                computeRecursiveShapeVolumeMassProperties(found, transform, limit, output);
            id = container->Next(id);
            if (id == -1)
                break;
        }
        return;
    }
    case 5:
        hkpInertiaTensorComputer_computeCapsuleVolumeMassProperties((hkVector4*)&apShape->v20, (hkVector4*)&apShape->v30, apShape->radius, 1.0f, &body);
        break;
    case 2: {
        LocalM128 v5 = _mm_load_ps(&apShape->v30.x), v3 = _mm_load_ps(&apShape->v20.x);
        float t = apShape->radius;
        LocalM128 v1 = _mm_sub_ps(v5, v3);
        LocalM128 v0 = _mm_mul_ps(v1, v1);
        LocalM128 v2 = _mm_shuffle_ps(v0, v0, 0x55);
        v2 = _mm_add_ss(v2, v0);
        v0 = _mm_shuffle_ps(v0, v0, 0xaa);
        v0 = _mm_add_ss(v0, v2);
        LocalM128 r = _mm_rsqrt_ss(v0);
        LocalM128 mask = _mm_cmpeq_ss(v0, _mm_set_ss(DAT_01011d78));
        LocalM128 rr = _mm_mul_ss(_mm_mul_ss(v0, r), r);
        LocalM128 fac = _mm_mul_ss(_mm_set_ss(DAT_01016248), r);
        fac = _mm_mul_ss(fac, _mm_sub_ss(_mm_set_ss(DAT_01017718), rr));
        fac = _mm_andnot_ps(mask, fac);
        LocalM128 n = _mm_mul_ps(_mm_shuffle_ps(fac, fac, 0), v1);
        hkVector4& start = vectorB;
        hkVector4& end = *reinterpret_cast<hkVector4*>(workspace.temp.local);
        LocalM128 ts = _mm_load_ss(&t);
        LocalM128 ts2 = _mm_load_ss(&t);
        _mm_store_ps(&start.x, _mm_sub_ps(v3, _mm_mul_ps(_mm_shuffle_ps(ts, ts2, 0), n)));
        _mm_store_ps(&end.x, _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(ts2, ts, 0), n), v5));
        float radius = apShape->FUN_00d571a0() + t;
        hkpInertiaTensorComputer_computeCylinderVolumeMassProperties(&start, &end, radius, 1.0f, &body);
        break;
    }
    case 28:
        goto function_end;
    default:
        return;
    }
    if (body.volume != 0.0f)
    {
        hkMatrix3_mul((Owner*)&body, body.volume);
        Array& arr = reinterpret_cast<Array&>(storage.array);
        arr.data = arr.local;
        arr.count = 0;
        arr.capacity = 0x80000002;
        Router* router = (Router*)hkMemoryRouter_getInstance();
        if (arr.count == (arr.capacity & 0x3fffffff))
            ResizeAudioStream(router->heap, &arr, 0x90);
        Element* slot = arr.data + arr.count;
        if (slot)
            slot->Initialize();
        Element* e0 = arr.data + arr.count++;
        e0->FUN_00cf0820(&output);
        _mm_store_ps(&e0->transform.m_f00, zero);
        _mm_store_ps(&e0->transform.m_f10, zero);
        _mm_store_ps(&e0->transform.m_f20, zero);
        e0->transform.m_f00 = 1.0f;
        e0->transform.m_f14 = 1.0f;
        e0->transform.m_f28 = 1.0f;
        _mm_store_ps(&e0->transform.m_f30, zero);
        router = (Router*)hkMemoryRouter_getInstance();
        if (arr.count == (arr.capacity & 0x3fffffff))
            ResizeAudioStream(router->heap, &arr, 0x90);
        slot = arr.data + arr.count;
        if (slot)
            slot->Initialize();
        Element* e1 = arr.data + arr.count++;
        e1->FUN_00cf0820(&body);
        e1->transform.r[0] = transform.r[0];
        e1->transform.r[1] = transform.r[1];
        e1->transform.r[2] = transform.r[2];
        e1->transform.r[3] = transform.r[3];
        hkpInertiaTensorComputer_combineMassProperties(&arr, &output);
        Router* cleanupRouter = (Router*)hkMemoryRouter_getInstance();
        arr.release(cleanupRouter->heap);
    }
function_end:
    return;
}

struct S_00cecc90_Sub
{
    void Multiply(hkVector4* v);
};

// Stores value at offset 4, computes value divided by the previous value, and passes the quotient to Multiply.
// @fnv 0x00cecc90
// src: GUESS 0x00cecc90 (confidence: medium)
__declspec(noinline) void Receiver::SetScalarAndRescaleVector(float value)
{
    float* p = (float*)((char*)this + 4);
    float quotient = value / *p;
    *p = value;
    hkVector4 v;
    v.m_vComponents = _mm_load_ss(&quotient);
    ((S_00cecc90_Sub*)((char*)this + 0x20))->Multiply(&v);
}


extern const float DAT_0104da48;
extern const float DAT_01016248;
extern const LocalM128 DAT_010c44d0;
extern const LocalM128 DAT_010ec7f0;

// Computes the center and extent of the axis-aligned bounding box enclosing apPoints[0..aiCount-1] using SIMD min/max and a 0.5 blend.
// @fnv 0x00cec7f0
// src: GUESS 0x00cec7f0 (confidence: high)
void __cdecl Hkpinertiatensorcomputer_ComputePointsAabbCenterAndExtent(const LocalM128* apPoints, int volatile aiCount, LocalM128* apCenter, LocalM128* apExtent)
{
    int iCount = aiCount;
    LocalM128 kMinPoint = _mm_set_ps1(DAT_0104da48);

    *apCenter = _mm_setzero_ps();
    *apExtent = _mm_setzero_ps();

    LocalM128 kMaxPoint = _mm_xor_ps(DAT_010c44d0, kMinPoint);

    for (int i = 0; i < iCount; i++)
    {
        LocalM128 kPoint = apPoints[i];
        kMinPoint = _mm_min_ps(kPoint, kMinPoint);
        kMaxPoint = _mm_max_ps(kPoint, kMaxPoint);
    }

    if (iCount != 0)
    {
        LocalM128 kT = _mm_set_ps1(DAT_01016248);
        LocalM128 kOneMinusT = _mm_sub_ps(DAT_010ec7f0, kT);
        *apCenter = _mm_add_ps(_mm_mul_ps(kOneMinusT, kMinPoint), _mm_mul_ps(kT, kMaxPoint));
        *apExtent = _mm_sub_ps(kMaxPoint, kMinPoint);
    }
}

extern "C" const double DAT_01099ee0;
extern "C" const double DAT_010240b0;

struct BoxInertia : hkMatrix3
{
    float& operator()(int r, int c)
    {
        return (&m_kColumn0.m_f[0])[c * 4 + r];
    }
    void setZero()
    {
        V4 z;
        z.setZero4();
        _mm_store_ps(&m_kColumn0.m_f[0], z.q);
        _mm_store_ps(&m_kColumn1.m_f[0], z.q);
        _mm_store_ps(&m_kColumn2.m_f[0], z.q);
    }
    void setIdentity()
    {
        setZero();
        (*this)(0, 0) = 1.0f;
        (*this)(1, 1) = 1.0f;
        (*this)(2, 2) = 1.0f;
    }
};
struct MassProperties
{
    float m_iBufferSize;
    float m_fViscosityFriction;
    float unk08;
    float unk0C;
    V4 m_kCenterOfMass1;
    BoxInertia m_kInertiaTensor;
};

// Fills result with the inertia tensor, zero center of mass, volume and mass for a box of given halfExtents and mass, returning 1 if mass is not positive.
// @fnv 0x00cebaf0
// src: XBOX_PDB 0x00cebaf0
int __cdecl hkpInertiaTensorComputer_computeBoxVolumeMassProperties(const V4& halfExtents, float mass, MassProperties& result)
{
    if (mass <= 0.0f)
        return 1;

    float x = halfExtents(0);
    float y = halfExtents(1);
    float z = halfExtents(2);
    float k = mass * (1.0f / 3.0f);

    result.m_kInertiaTensor.setIdentity();
    result.m_kCenterOfMass1.setZero4();

    result.m_kInertiaTensor(0, 0) = (y * y + z * z) * k;
    result.m_kInertiaTensor(1, 1) = (x * x + z * z) * k;
    result.m_kInertiaTensor(2, 2) = (x * x + y * y) * k;

    result.m_iBufferSize = (float)(x * y * z * DAT_010240b0);
    result.m_fViscosityFriction = mass;
    return 0;
}

__declspec(align(16)) struct Vec4Q
{
    float x;
    float y;
    float z;
    float w;
};

struct SourceBlock
{
    int unk00;
    float f04;
    int unk08;
    int unk0c;
    LocalM128 a10;
    LocalM128 b20;
    LocalM128 c30;
    LocalM128 d40;
};

struct DestBlock
{
    LocalM128 m00;
    LocalM128 m10;
    LocalM128 m20;
    LocalM128 m30;
    float f40;
    void Multiply(Vec4Q* v);
};

// Copies four LocalM128 blocks from source into destination at offset 0x50, stores value in f40, and calls Multiply with value divided by src->f04.
// @fnv 0x00cebdf0
// src: GUESS 0x00cebdf0 (confidence: medium)
void __cdecl Hkpinertiatensorcomputer_CopyAndScalePropertyBlock(float* source, float value, Object* destination)
{
    SourceBlock* src = (SourceBlock*)source;
    DestBlock* dst = (DestBlock*)((char*)destination + 0x50);
    float q = value / src->f04;
    float* qp = &q;
    dst->f40 = value;
    dst->m30 = src->a10;
    dst->m00 = src->b20;
    dst->m10 = src->c30;
    dst->m20 = src->d40;
    Vec4Q tmp;
    _mm_store_ps((float*)&tmp, _mm_load_ss(qp));
    dst->Multiply(&tmp);
}


extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl fabs(double);

static __forceinline float Square(float x)
{
    return x * x;
}
static __forceinline float Sqrt(float x)
{
    return (float)sqrt(x);
}
static __forceinline float Abs(float x)
{
    return (float)fabs(x);
}

struct EigenMatrix
{
    LocalM128 row0, row1, row2;
    void hkMatrix3_setMul(const EigenMatrix& a, const EigenMatrix& b);
};

struct EigenVector
{
    union { LocalM128 q; LocalM128 m_vComponents; };
    __forceinline float& operator()(int i)
    {
        return ((float*)&q)[i];
    }
    __forceinline void normalize3()
    {
        LocalM128 m = _mm_mul_ps(q, q);
        LocalM128 lenSq = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m));
        LocalM128 r = _mm_rsqrt_ss(lenSq);
        LocalM128 zero = _mm_set_ss(0.0f);
        LocalM128 c3 = _mm_set_ss(3.0f);
        LocalM128 c05 = _mm_set_ss(0.5f);
        LocalM128 invLen = _mm_mul_ss(_mm_mul_ss(c05, r), _mm_sub_ss(c3, _mm_mul_ss(_mm_mul_ss(lenSq, r), r)));
        invLen = _mm_andnot_ps(_mm_cmpeq_ss(lenSq, zero), invLen);
        q = _mm_mul_ps(_mm_shuffle_ps(invLen, invLen, 0), q);
    }
    __forceinline void setCross(const EigenVector& a, const EigenVector& b)
    {
        LocalM128 aq = a.m_vComponents;
        LocalM128 bq = b.m_vComponents;
        q = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(aq, aq, 0xd2), _mm_shuffle_ps(bq, bq, 0xc9)),
                       _mm_mul_ps(_mm_shuffle_ps(aq, aq, 0xc9), _mm_shuffle_ps(bq, bq, 0xd2)));
    }
    __forceinline void setCrossS(const EigenVector& a, const EigenVector& b)
    {
        LocalM128 aq = a.m_vComponents;
        LocalM128 bq = b.m_vComponents;
        q = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(aq, aq, 0xc9), _mm_shuffle_ps(bq, bq, 0xd2)),
                       _mm_mul_ps(_mm_shuffle_ps(aq, aq, 0xd2), _mm_shuffle_ps(bq, bq, 0xc9)));
    }
};

struct Basis
{
    EigenVector c0, c1, c2;
    __forceinline EigenVector& getColumn(int i)
    {
        return (&c0)[i];
    }
    __forceinline void setIdentityZ(LocalM128 z)
    {
        getColumn(0).q = z;
        getColumn(1).q = z;
        getColumn(2).q = z;
        getColumn(0)(0) = 1.0f;
        getColumn(1)(1) = 1.0f;
        getColumn(2)(2) = 1.0f;
    }
    __forceinline void setIdentityZ2(LocalM128 z)
    {
        c0.m_vComponents = z;
        c1.m_vComponents = z;
        c2.m_vComponents = z;
        c0(0) = 1.0f;
        c1(1) = 1.0f;
        c2(2) = 1.0f;
    }
    __forceinline float& at(int r, int c)
    {
        return ((float*)this)[r * 4 + c];
    }
    __forceinline void setIdentityZ3(LocalM128 z)
    {
        c0.m_vComponents = z;
        c1.m_vComponents = z;
        c2.m_vComponents = z;
        at(0, 0) = 1.0f;
        at(1, 1) = 1.0f;
        at(2, 2) = 1.0f;
    }
    __forceinline void Orthonormalize()
    {
        getColumn(0).normalize3();
        getColumn(1).setCrossS(getColumn(2), getColumn(0));
        getColumn(1).normalize3();
        getColumn(2).setCross(getColumn(1), getColumn(0));
        getColumn(2).normalize3();
    }
    __forceinline void renormalize2()
    {
        c0.normalize3();
        c1.setCross(c2, c0);
        c1.normalize3();
        c2.setCross(c0, c1);
        c2.normalize3();
    }
};

// Applies Jacobi rotations to zero off-diagonal elements of src, accumulating the rotation into dst, then orthonormalizes dst.
// @fnv 0x00cec880
// src: GUESS 0x00cec880 (confidence: medium)
void __cdecl Object_ApplyJacobiRotations(EigenMatrix* src, EigenMatrix* dst)
{
    LocalM128 zero = _mm_setzero_ps();
    ((Basis*)dst)->setIdentityZ2(zero);

    int iter = 5;
    do
    {
        float* a = (float*)src;
        int q = 1;
        int p = 0;
        float maxSq = a[1] * a[1];
        float v = Square(a[2]);
        if (v > maxSq)
        {
            maxSq = v;
            q = 2;
            p = 0;
        }
        v = Square(a[6]);
        if (v > maxSq)
        {
            maxSq = v;
            q = 2;
            p = 1;
        }
        if (maxSq < 1.4210854715202004e-14f)
            break;

        v = (a[q * 5] - a[p * 5]) / (a[p + q * 4] * 2.0f);
        float fSign = v > 0.0f ? 1.0f : -1.0f;
        float t = fSign / (Sqrt((float)(v * v + 1.0)) + Abs(v));
        float c = 1.0f / Sqrt((float)(t * t + 1.0));
        float s = c * t;

        EigenMatrix R;
        R.row0 = zero;
        R.row1 = zero;
        R.row2 = zero;
        float* r = (float*)&R;
        r[0] = 1.0f;
        r[5] = 1.0f;
        r[10] = 1.0f;
        r[p * 5] = c;
        r[q * 5] = c;
        float ns = -s;
        r[p + q * 4] = ns;
        r[q + p * 4] = s;

        EigenMatrix temp;
        temp.hkMatrix3_setMul(R, *src);
        r[p + q * 4] = s;
        r[q + p * 4] = ns;
        src->hkMatrix3_setMul(temp, R);
        temp.hkMatrix3_setMul(*dst, R);
        dst->row0 = temp.row0;
        dst->row1 = temp.row1;
        dst->row2 = temp.row2;
    } while (--iter > 0);

    Basis* B = (Basis*)dst;
    B->Orthonormalize();
}

void hkArrayUtil__reserve(S_00cee1c0_Heap* a, void* arr, int n, int sz);
struct OutObj
{
    float unk00;
    float m_04;
    float unk08;
    float unk0c;
    LocalM128 com;
    LocalM128 r0;
    LocalM128 r1;
    LocalM128 r2;
};
struct __declspec(align(16)) Vec
{
    float x, y, z, w;
};

static __forceinline void computePoints(Vec* data, int count, float mass, OutObj* out)
{
    out->m_04 = mass;
    out->r0 = _mm_setzero_ps();
    out->r1 = _mm_setzero_ps();
    out->r2 = _mm_setzero_ps();
    out->com = _mm_setzero_ps();
    float fc = (float)count;
    float inv = mass / fc;
    for (int i = 0; i < count; i++)
        out->com = _mm_add_ps(_mm_load_ps(&data[i].x), out->com);
    fc = 1.0f / fc;
    LocalM128 scalar = _mm_load_ss(&fc);
    LocalM128 broadcast = _mm_shuffle_ps(scalar, scalar, 0);
    out->com = _mm_mul_ps(broadcast, out->com);
    for (int i = 0; i < count; i++)
    {
        const Vec* q = &data[i];
        float dx = q->x - out->com.m128_f32[0], dy = q->y - out->com.m128_f32[1], dz = q->z - out->com.m128_f32[2];
        out->r0.m128_f32[0] += (dy * dy + dz * dz) * inv;
        out->r1.m128_f32[1] += (dx * dx + dz * dz) * inv;
        out->r2.m128_f32[2] += (dx * dx + dy * dy) * inv;
        out->r1.m128_f32[0] -= dx * dy * inv;
        out->r0.m128_f32[1] -= dx * dy * inv;
        out->r2.m128_f32[0] -= dx * dz * inv;
        out->r0.m128_f32[2] -= dx * dz * inv;
        out->r1.m128_f32[2] -= dy * dz * inv;
        out->r2.m128_f32[1] -= dy * dz * inv;
    }
}
// Copies vertex positions into a temporary array, computes the center of mass and inertia tensor via computePoints, then frees the array.
// @fnv 0x00cedcb0
// src: GUESS 0x00cedcb0 (confidence: medium)
int __cdecl hkArrayBase_ComputePointMassProperties(char* apVertices, int stride, int count, float mass, OutObj* out)
{
    if (count <= 0)
        return 1;
    hkArrayBase<Vec> a;
    a.m_data = 0;
    a.m_iElementCount = 0;
    a.m_iCapacityState = 0x80000000u;
    S_00cee1c0_Router* router = hkMemoryRouter_getInstance();
    S_00cee1c0_Heap* heap = router->heap;
    if ((int)(a.m_iCapacityState & 0x3fffffff) < count)
    {
        int n = (a.m_iCapacityState & 0x3fffffff) * 2;
        if (count >= n)
            n = count;
        hkArrayUtil__reserve(heap, &a, n, 16);
    }
    a.m_iElementCount = count;
    char* p = apVertices;
    float zero = 0.0f;
    for (int i = 0; i < count; i++)
    {
        a.m_data[i].x = ((float*)p)[0];
        a.m_data[i].y = ((float*)p)[1];
        a.m_data[i].z = ((float*)p)[2];
        a.m_data[i].w = zero;
        p += stride;
    }
    computePoints(a.m_data, count, mass, out);
    router = hkMemoryRouter_getInstance();
    heap = router->heap;
    a.m_iElementCount = 0;
    unsigned capacity = a.m_iCapacityState;
    if ((capacity & 0x80000000u) == 0)
        heap->Free(a.m_data, (capacity & 0x3fffffff) * 16);
    return 0;
}

struct Geometry
{
    Vec4* vertices;
    int vertexCount;
    int vertexCapacity;
    int* triangles;
    int triangleCount;
};
struct MassPropertiesSV
{
    float volume;
    float mass;
    hkVector4 center;
    Matrix inertia;
    MassPropertiesSV& operator=(const MassPropertiesSV& source)
    {
        volume = source.volume;
        mass = source.mass;
        center.m_vComponents = source.center.m_vComponents;
        inertia = source.inertia;
        return *this;
    }
};
// src: GUESS 0x00cec7f0 (confidence: high)
__declspec(noinline) void __cdecl Hkpinertiatensorcomputer_ComputePointsAabbCenterAndExtent(Vec4* v, int n, Vec4* center, Vec4* dims)
{
    LocalM128 lo = _mm_load_ps(&v->x);
    LocalM128 hi = lo;
    LocalM128 s0 = lo;
    Vec4* p = v + 1;
    Vec4* e = v + n;
    while (p < e)
    {
        LocalM128 q = _mm_load_ps(&p->x);
        lo = _mm_min_ps(lo, q);
        hi = _mm_max_ps(hi, q);
        s0 = _mm_add_ps(s0, q);
        _mm_store_ps(&dims[(int)(p - v) & 1].x, hi);
        _mm_store_ps(&center[(int)(e - p) & 1].x, s0);
        ++p;
    }
    LocalM128 a = _mm_add_ps(lo, hi);
    LocalM128 b = _mm_xor_ps(lo, s0);
    _mm_store_ps(&center->x, _mm_mul_ps(a, b));
    _mm_store_ps(&dims->x, _mm_add_ps(b, hi));
}
// src: XBOX_PDB 0x00cebaf0
__declspec(noinline) int __cdecl hkpInertiaTensorComputer_computeBoxVolumeMassProperties(Vec4* d, float m, MassPropertiesSV* p)
{
    if (m <= 0.0f)
        return 1;
    float x = d->x, y = d->y, z = d->z;
    _mm_store_ps(&p->inertia.c0.x, _mm_setzero_ps());
    _mm_store_ps(&p->inertia.c1.x, _mm_setzero_ps());
    _mm_store_ps(&p->inertia.c2.x, _mm_setzero_ps());
    _mm_store_ps(&p->center.x, _mm_setzero_ps());
    float k = m * 0.33333334f;
    p->inertia.c0.x = k * (y * y + z * z);
    p->inertia.c1.y = k * (x * x + z * z);
    p->inertia.c2.z = k * (x * x + y * y);
    p->volume = x * y * z * 8.0f;
    p->mass = m;
    return 0;
}
struct Integrator
{
    Vec4 basisX, basisY, basisZ, translation, boundsMin, boundsMax;
    float m_60, m_64, m_68, m_6C, m_70, m_74, m_78, m_7C, m_80, m_84, m_88;
    void ProcessEntries_00ced390(Geometry*, Vec4*);
    void InternalInertiaTensorComputer_computeInertialTensorInternal(float, float, float*, float*);
};
// src: GUESS 0x00ced390 (confidence: low)
__declspec(noinline) void Integrator::ProcessEntries_00ced390(Geometry* g, Vec4* off)
{
    LocalM128 o = _mm_load_ps(&off->x);
    LocalM128 acc = _mm_load_ps(&basisY.x);
    for (int i = 0; i < g->triangleCount; ++i)
    {
        int* t = g->triangles + i * 3;
        LocalM128 a = _mm_add_ps(_mm_load_ps(&g->vertices[t[0]].x), o);
        LocalM128 b = _mm_add_ps(_mm_load_ps(&g->vertices[t[1]].x), o);
        LocalM128 c = _mm_load_ps(&g->vertices[t[2]].x);
        acc = _mm_add_ps(acc, _mm_mul_ps(a, b));
        _mm_store_ps(&basisX.x, _mm_add_ps(_mm_load_ps(&basisX.x), _mm_mul_ps(a, c)));
        m_64 += g->vertices[t[2]].x * m_60 + m_68;
    }
    _mm_store_ps(&basisY.x, acc);
}
// src: HAVOK_LIB 0x00cec6b0
__declspec(noinline) void Integrator::InternalInertiaTensorComputer_computeInertialTensorInternal(float a, float b, float* p, float* M)
{
    float s = b / m_64;
    p[0] = m_68 * s;
    p[1] = m_6C * s;
    p[2] = m_70 * s;
    for (int i = 0; i < 3; ++i)
    {
        M[i * 5] = (&m_74)[i] * a - p[i] * b;
        M[i + 4] = M[i] + (&m_80)[i];
    }
}
static inline float maximum(float a, float b)
{
    return a < b ? b : a;
}
// Computes volume, mass, center of mass, and inertia tensor for a Geometry, falling back to an axis-aligned box when the integrated volume is non-positive.
// @fnv 0x00ced6b0
// src: GUESS 0x00ced6b0 (confidence: medium)
void __cdecl hkpInertiaTensorComputer_computeBoxVolumeMassProperties_ComputeGeometryMassProperties(Geometry* geometry, float mass, MassPropertiesSV* result)
{
    float zero = 0.0f;
    if (mass <= zero)
        mass = 1.0f;
    Vec4 center;
    MassPropertiesSV boxProperties;
    {
        Vec4 dimensions;
        Hkpinertiatensorcomputer_ComputePointsAabbCenterAndExtent(geometry->vertices, geometry->vertexCount, &center, &dimensions);
        boxProperties.volume = zero;
        boxProperties.mass = zero;
        _mm_store_ps(&boxProperties.center.x, _mm_setzero_ps());
        _mm_store_ps(&boxProperties.inertia.c0.x, _mm_setzero_ps());
        _mm_store_ps(&boxProperties.inertia.c1.x, _mm_setzero_ps());
        _mm_store_ps(&boxProperties.inertia.c2.x, _mm_setzero_ps());
        hkpInertiaTensorComputer_computeBoxVolumeMassProperties(&dimensions, mass, &boxProperties);
    }
    LocalM128 centerValue = *(LocalM128*)&center;
    *(LocalM128*)&boxProperties.center = centerValue;
    Integrator integrator;
    {
        Vec4 shift;
        *(LocalM128*)&shift = _mm_xor_ps(DAT_010c44d0, centerValue);
        integrator.ProcessEntries_00ced390(geometry, &shift);
    }
    if (integrator.m_64 <= 0.0f)
    {
        *result = boxProperties;
        return;
    }
    result->volume = integrator.m_64;
    result->mass = mass;
    float density = mass / integrator.m_64;
    integrator.InternalInertiaTensorComputer_computeInertialTensorInternal(mass, density, (float*)&result->center, (float*)&result->inertia.c0);
    *(LocalM128*)&result->center = _mm_add_ps(*(LocalM128*)&result->center, *(LocalM128*)&boxProperties.center);
    float* inertia = (float*)&result->inertia.c0;
    float* boxInertia = (float*)&boxProperties.inertia.c0;
    for (int i = 0; i < 3; ++i)
    {
        if (inertia[i * 5] < (double)0.1f * boxInertia[i * 5])
        {
            inertia[i * 5] = (float)((double)0.1f * boxInertia[i * 5]);
            ((float*)&result->center)[i] = ((float*)&center)[i];
            for (int j = 0; j < 3; ++j)
            {
                if (j != i)
                {
                    float v = inertia[i * 4 + j];
                    inertia[i * 4 + j] = inertia[j * 4 + i] = S_MaxGT(0.0f, v);
                }
            }
        }
    }
}
