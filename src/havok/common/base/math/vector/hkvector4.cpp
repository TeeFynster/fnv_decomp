
// src/havok/common/base/math/vector/hkvector4.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/vector/hkvector4.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/bhkCharacterController.h"

// CheckFloatsFinite (0x00c7f4e0, 21 bytes)
//
// The original is a __thiscall member of a class whose object *is* the float
// array.  It forwards to a file-static helper FUN_00c7f4a0(out, self, count).
//
// MSVC 2008 gives an internal-linkage (file-static) helper its own internal
// "register argument" convention: instead of pushing the arguments on the
// stack they are passed in registers.  With the helper declared as
//     static void* FUN_00c7f4a0(void* out, void* self, int count)
// MSVC 2008 assigns  out->EAX, self->ESI, count->EDX  and the call site
// becomes exactly
//     mov eax,[esp+4] / push esi / mov edx,3 / mov esi,ecx / call / pop esi / ret 4
// The helper returns its first argument, which is what pins that argument
// to EAX; the parameter order (out, self, count) is what makes the call site
// materialise EDX before ESI.

struct Cls_c7f4e0
{
    float unk00[8];
    void CheckFloatsFinite(void* out);
};

// src: HAVOK_LIB 0x00c7f4a0
static __declspec(noinline) void* hkVector4isOk(void* out, void* self, int count)
{
    for (int i = 0; i < count; i++)
    {
        float v = ((float*)self)[i];
        int bits = *(int*)&v;
        if ((bits & 0x7f800000) == 0x7f800000)
        {
            *(char*)out = 0;
            return out;
        }
    }
    *(char*)out = 1;
    return out;
}

// @fnv 0x00c7f4e0
void Cls_c7f4e0::CheckFloatsFinite(void* pResult)
{
    hkVector4isOk(pResult, this, 3);
}

#include <xmmintrin.h>
extern __m128 DAT_01267e30;

struct SubVecHolder;
struct FUN_00c7f700_cls
{
    __m128 m_result;
    void hkVector4_setRotatedDir(void* first, void* second);
};

struct VecSource
{
    __m128* hkpCharacterProxy_getPosition();
};

struct HolderNode
{
    int unk00;
    int unk04;
    char* m_p08;
};

extern void __fastcall bhkCharacterProxy_MarkRead(bhkCharacterController* controller);

// Subtracts res.m_result from the selected vector and stores the difference in out.
// @fnv 0x00c6e300
void bhkCharacterController::SubtractVectors(Vec4* apResult)
{
    HolderNode* holder = *(HolderNode**)((char*)this + 0x594);
    char* base = holder ? holder->m_p08 : 0;

    FUN_00c7f700_cls res;
    res.hkVector4_setRotatedDir(base + 0xb0, (char*)this + 0x570);

    __m128* vec = &DAT_01267e30;
    VecSource* src = reinterpret_cast<VecSource*>(m_pHavokObject);
    if (src != 0)
    {
        bhkCharacterProxy_MarkRead(this);
        vec = src->hkpCharacterProxy_getPosition();
        bhkCharacterProxy_MarkRead(this);
    }

    __m128 a = *vec;
    __m128 b = res.m_result;
    *reinterpret_cast<__m128*>(apResult) = _mm_sub_ps(a, b);
}

struct __declspec(align(16)) CastVector
{
    float x, y, z, w;
    void hkVector4_setTransformedInversePos(void* transform, const CastVector* value);
    void hkVector4_setRotatedDir(void* transform, const CastVector* value);
};

typedef __m128 VecArr;

struct HkBool
{
    char m_cBooleanValue;
    HkBool()
    {}
    HkBool(bool b) : m_cBooleanValue((char)b)
    {}
};

struct HitResult;

struct CastInput
{
    CastVector from;
    CastVector to;
    unsigned int unk20;
    void* unk24;
    CastInput() : unk20(0), unk24(0)
    {}
};

struct CollisionObject
{
    virtual void ReportDiagnostic() = 0;
    virtual void unused1() = 0;
    virtual void unused2() = 0;
    virtual void FlushUsageData() = 0;
    virtual void unused4() = 0;
    virtual void unused5() = 0;
    virtual void unused6() = 0;
    virtual void unused7() = 0;
    virtual HkBool RayCast(const CastInput& input, HitResult& result) const = 0;
    int unknown04;
    int unknown08;
    int type0c;
};

struct HitResult
{
    float normalX, normalY, normalZ, normalW;
    float fraction;
    int faceIndex;
    float unknown18, unknown1c;
    unsigned int shapeKeys[8];
    unsigned int flag40;
    int unknown44;
    int unknown48;
    int unknown4c;
    HitResult()
    {
        reset();
    }
    void reset()
    {
        fraction = 1.0f;
        faceIndex = -1;
        shapeKeys[0] = (unsigned int)-1;
        flag40 = 0;
    }
};

struct Geometry
{
    CollisionObject* collision;
    int unk04;
    void* transform;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int flags;
};

struct State
{
    int* itemAt(int index) const
    {
        return *(int**)(*(char**)((char*)this + 0x160) + index * 8 + 4);
    }
    int count() const
    {
        return *(int*)((char*)this + 0x164);
    }
};

struct Node
{
    int unk00;
    int unk04;
    State* state;
};

extern float __fastcall GetSettingFloat(bhkCharacterController* controller);

extern float DAT_01011d78;
extern float DAT_01267bcc;
extern double DAT_010290b0;
extern double DAT_0102f070;

// Casts rays between transformed points, adjusts both z coordinates by advance, and returns true when a cast fraction is below 1.
// @fnv 0x00c6fa20
// src: COMMUNITY 0x00c6fa20
bool bhkCharacterController::CheckInsideOfObject()
{
    Node* node = *(Node**)((char*)this + 0x594);
    State* state = node ? node->state : 0;
    float advance = *(float*)((char*)this + 0x564) * DAT_010290b0;
    float range = DAT_01267bcc * DAT_0102f070 + GetSettingFloat(this);
    CastVector value;
    *(__m128*)&value = _mm_setr_ps(DAT_01011d78, range, DAT_01011d78, DAT_01011d78);
    State* transformState = node ? node->state : 0;
    value.hkVector4_setRotatedDir((char*)transformState + 0xb0, &value);
    CastVector vStart;
    this->SubtractVectors(reinterpret_cast<Vec4*>(&vStart));
    VecArr vFinish;
    *(__m128*)&vFinish = _mm_add_ps(*(__m128*)&vStart, *(__m128*)&value);

    for (int i = 0; i < state->count(); ++i)
    {
        Geometry* geom = (Geometry*)state->itemAt(i);
        if (!geom)
            continue;
        switch (geom->flags & 0x7f)
        {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
        case 11:
        case 12:
        case 16:
        case 17:
        case 22:
        case 23:
        case 24:
        case 29:
        case 30:
            continue;
        }
        CollisionObject* __restrict shape = geom->collision;
        if (shape->type0c != 8 && shape->type0c != 6 && shape->type0c != 10)
            continue;

        Geometry* __restrict body = geom;
        CastInput input;
        HitResult result;
        input.from.hkVector4_setTransformedInversePos(body->transform, &vStart);
        input.to.hkVector4_setTransformedInversePos(geom->transform, (CastVector*)&vFinish);

        bool hit = false;
        unsigned int j = 0;
        do
        {
            result.fraction = 1.0f;
            input.from.z += advance;
            input.to.z += advance;
            result.faceIndex = -1;
            result.shapeKeys[0] = (unsigned int)-1;
            result.flag40 = 0;
            shape->RayCast(input, result);
            if (result.fraction < 1.0f)
            {
                hit = true;
                break;
            }
        } while (++j < 3);

        input.from.hkVector4_setTransformedInversePos(geom->transform, (CastVector*)&vFinish);
        input.to.hkVector4_setTransformedInversePos(geom->transform, &vStart);

        if (!hit)
        {
            for (unsigned int j = 0; j < 3; ++j)
            {
                result.fraction = 1.0f;
                input.from.z += advance;
                input.to.z += advance;
                result.faceIndex = -1;
                result.shapeKeys[0] = (unsigned int)-1;
                result.flag40 = 0;
                shape->RayCast(input, result);
                if (result.fraction < 1.0f)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

struct __declspec(align(16)) SpawnedMatrix
{
    __m128 m_row0;
    __m128 m_row1;
    __m128 m_row2;
    __m128 m_row3;
};

struct __declspec(align(16)) FUN_00c7f640_cls
{
    __m128 m_vResult;

    void setTransformedPos_00c7f640(const SpawnedMatrix* apMatrix, const __m128* apVector);
};

// Combines the vector's first three components with matrix rows 0-2, adds row3, and stores the result in m_vResult.
// @fnv 0x00c7f640
// src: XBOX_PDB 0x00c7f640
void FUN_00c7f640_cls::setTransformedPos_00c7f640(const SpawnedMatrix* apMatrix, const __m128* apVector)
{
    __m128 vVec = *apVector;
    __m128 vY = _mm_shuffle_ps(vVec, vVec, 0x55);
    __m128 vT1 = _mm_mul_ps(vY, apMatrix->m_row1);
    __m128 vX = _mm_shuffle_ps(vVec, vVec, 0);
    __m128 vT2 = _mm_mul_ps(vX, apMatrix->m_row0);
    vT1 = _mm_add_ps(vT1, vT2);
    __m128 vZ = _mm_shuffle_ps(vVec, vVec, 0xaa);
    __m128 vT3 = _mm_mul_ps(vZ, apMatrix->m_row2);
    vT3 = _mm_add_ps(vT3, apMatrix->m_row3);
    m_vResult = _mm_add_ps(vT1, vT3);
}

struct S_00c7f690_V
{
    __m128 q;
};
struct S_00c7f690_M
{
    S_00c7f690_V c0, c1, c2, c3;
};
struct FUN_00c7f690_cls
{
    void hkVector4_setTransformedInversePos(const S_00c7f690_M* m, const S_00c7f690_V* v);
};

// Subtracts m->c3 from v, multiplies the difference by components assembled from m->c0 through m->c2, and stores the result in this.
// @fnv 0x00c7f690
// src: XBOX_PDB 0x00c7f690
void FUN_00c7f690_cls::hkVector4_setTransformedInversePos(const S_00c7f690_M* apMatrix, const S_00c7f690_V* apVector)
{
    S_00c7f690_V vDelta;
    vDelta.q = _mm_sub_ps(apVector->q, apMatrix->c3.q);
    __m128 a0 = apMatrix->c0.q, a1 = apMatrix->c1.q, a2 = apMatrix->c2.q;
    __m128 vTmp0 = _mm_unpacklo_ps(a0, a1);
    __m128 vTmp1 = _mm_unpackhi_ps(a0, a1);
    a0 = _mm_movelh_ps(vTmp0, a2);
    a1 = _mm_shuffle_ps(_mm_movehl_ps(a0, vTmp0), a2, 0xd4);
    a2 = _mm_shuffle_ps(vTmp1, a2, 0xe4);
    __m128 x = _mm_shuffle_ps(vDelta.q, vDelta.q, 0x00);
    __m128 y = _mm_shuffle_ps(vDelta.q, vDelta.q, 0x55);
    __m128 z = _mm_shuffle_ps(vDelta.q, vDelta.q, 0xaa);
    ((S_00c7f690_V*)this)->q = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, a1), _mm_mul_ps(x, a0)), _mm_mul_ps(a2, z));
}

namespace fnv_00c7f700 {
struct MatrixRows3x4
{
    __m128 row0;
    __m128 row1;
    __m128 row2;
    __m128 row3;
};

struct FUN_00c7f700_cls
{
    __m128 m_result;

    void hkVector4_setRotatedDir(MatrixRows3x4* matrix, __m128* vec);
};

// Multiplies a 3D vector by the first three rows of a 3x4 matrix and stores the result in m_result.
// @fnv 0x00c7f700
// src: XBOX_PDB 0x00c7f700
void FUN_00c7f700_cls::hkVector4_setRotatedDir(MatrixRows3x4* matrix, __m128* apVector)
{
    __m128 v = *apVector;
    __m128 vx = _mm_shuffle_ps(v, v, 0x00);
    __m128 vy = _mm_shuffle_ps(v, v, 0x55);
    __m128 vz = _mm_shuffle_ps(v, v, 0xaa);

    __m128 r = _mm_mul_ps(vy, matrix->row1);
    r = _mm_add_ps(r, _mm_mul_ps(vx, matrix->row0));
    r = _mm_add_ps(r, _mm_mul_ps(vz, matrix->row2));
    m_result = r;
}
}  // namespace fnv_00c7f700

struct FUN_00c7f750_shell
{
    void __thiscall hkVector4_setMul3(float* matrix, float* vector);
};
// Multiplies a 3D vector by a 3x3 matrix using SSE and stores the resulting vector in the object.
// @fnv 0x00c7f750
// src: XBOX_PDB 0x00c7f750
void __thiscall FUN_00c7f750_shell::hkVector4_setMul3(float* matrix, float* vector)
{
    __m128 v = *(__m128*)vector;
    __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1)), *(__m128*)(matrix + 4));
    __m128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0)), *(__m128*)matrix);
    __m128 result = _mm_add_ps(y, x);
    __m128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2)), *(__m128*)(matrix + 8));
    result = _mm_add_ps(result, z);
    *(__m128*)this = result;
}

struct QueryScalar
{
    __m128 q;
    QueryScalar()
    {}
    QueryScalar(const __m128& value) : q(value)
    {}
    QueryScalar(const QueryScalar& value) : q(value.q)
    {}
    operator float() const
    {
        float v;
        _mm_store_ss(&v, q);
        return v;
    }
};
// Character support query with triangle and general shape paths.
struct Mat16;
struct QueryVector
{
    __m128 q;
    QueryVector()
    {}
    QueryScalar get(int i) const
    {
        switch (i)
        {
        case 0:
            return q;
        case 1:
            return _mm_shuffle_ps(q, q, 85);
        case 2:
            return _mm_shuffle_ps(q, q, 170);
        default:
            return _mm_shuffle_ps(q, q, 255);
        }
    }
    float& operator()(int i)
    {
        return ((float*)&q)[i];
    }
    QueryVector(const QueryVector& x)
    {
        q = x.q;
    }
    QueryVector& operator=(const QueryVector& x)
    {
        const __m128& ref = x.q;
        q = ref;
        return *this;
    }
    void setTransformedPos_00c7f640(void* a, const QueryVector* v);
    void hkVector4_setTransformedInversePos(const Mat16* t, const QueryVector* v);
};
struct Mat16
{
    QueryVector col[4];
};
struct BoundingVolumeNode
{
    void* f00;
    int u04;
    BoundingVolumeNode* child;
    int type;
    union
    {
        int f10;
        float radius;
    };
    int u014;
    int u018;
    int u01c;
    union
    {
        __m128 points[3];
        struct
        {
            int u020, u024, u028, u02c, u030;
            BoundingVolumeNode* f34;
        };
    };
    int bhkShape_GetSubshapeMaterial(int key);
};
struct VarObj
{
    BoundingVolumeNode* first;
    int u04;
    int u08;
    int u0c;
    char b10;
    char u11;
    char u12;
    char u13;
    int u14;
    char type;
    char u19;
    char u1a;
    char u1b;
    int u1c;
    int u020;
    int u024;
    int u028;
    int u02c;
    int u030;
    int u034;
    int u038;
    int u03c;
    int u040;
    int u044;
    int u048;
    int u04c;
    int u050;
    int u054;
    int u058;
    int u05c;
    int u060;
    int u064;
    int u068;
    int u06c;
    int u070;
    int u074;
    int u078;
    int u07c;
    int u080;
    int u084;
    int u088;
    int u08c;
    int u090;
    int u094;
    int u098;
    int u09c;
    int u0a0;
    int u0a4;
    int u0a8;
    int u0ac;
    int u0b0;
    int u0b4;
    int u0b8;
    int u0bc;
    int u0c0;
    int u0c4;
    int u0c8;
    int u0cc;
    int u0d0;
    int u0d4;
    int u0d8;
    int u0dc;
    int u0e0;
    int u0e4;
    int u0e8;
    int u0ec;
    Mat16 mat;
};
struct ArgObj
{
    float v[4];
    int u10;
    int u14;
    int u18;
    int u1c;
    VarObj* f20;
    int u024;
    int u028;
    int u02c;
    int u030;
    int u034;
    int u038;
    int u03c;
    int u040;
    int u044;
    VarObj* f48;
    int f4c;
};
struct Sub410
{
    int s000;
    int flags;
    int s008;
    int s00c;
    int s010;
    int s014;
    int s018;
    int s01c;
    int s020;
    int s024;
    int s028;
    int s02c;
    int s030;
    int s034;
    int s038;
    int s03c;
    int s040;
    int s044;
    int s048;
    int s04c;
    int s050;
    int s054;
    int s058;
    int s05c;
    void AccumulateValue(void* a, float f);
};
struct ShapeStorage
{
    __declspec(align(16)) char bytes[512];
};
struct Iface
{
    void** vtbl;
};
struct ResObj
{
    int u00;
    int u04;
    int u08;
    int u0c;
    Iface iface;
};
typedef BoundingVolumeNode*(__thiscall* ResFn)(Iface* self, int id, ShapeStorage* out);
struct RayIn
{
    QueryVector vectors[2];
    int filter;
    void* collectionFilter;
};
struct RayOut
{
    __m128 normal;
    float fraction;
    int extra;
    int u18;
    int u1c;
    unsigned int keys[8];
    int keyIndex;
};
struct Contact
{
    __m128 normal;
    int u10, u14, u18;
    float distance;
};
struct Contacts
{
    Contact hit[3];
};
union CollisionOutput
{
    RayOut ray;
    Contacts contacts;
};
struct Plane
{
    float x, y, z, w, area;
};
struct BoolResult
{
    char value;
    BoolResult(char v) : value(v)
    {}
};
struct RayShape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual BoolResult cast(const RayIn&, RayOut&) const;
};
__declspec(noinline) void* __cdecl GetValidatedPointer(void* obj)
{
    BoundingVolumeNode* n = (BoundingVolumeNode*)obj;
    BoundingVolumeNode* result = 0;
    if (n)
    {
        int type = n->type;
        if (type == 10)
        {
            n = n->f34;
            type = n->type;
        }
        if (type == 0x17 || type == 0x1e || type == 0x1f)
            result = n;
    }
    return result;
}
void __cdecl ComputeInverseLengths(const QueryVector* triangle, Plane* plane);
void __cdecl hkCollideCapsuleUtilCapsVsTri(const QueryVector* ray, float tolerance, const QueryVector* triangle, float radius,
                          const Plane* plane, float zero, int flags, Contacts* contacts, void* extra);
char __cdecl bhkCharacterController_IsShapeConsideredPenetrating(BoundingVolumeNode* obj, int one, char v, int id);
typedef char(__cdecl* PredFn)(int v);
extern PredFn DAT_01267bc8;
extern "C" void _ReadWriteBarrier();
extern float DAT_01011d78;
static __forceinline float scalar(__m128 x)
{
    float value;
    _mm_store_ss(&value, x);
    return value;
}
static __forceinline __m128 squared3(__m128 v)
{
    __m128 products = _mm_mul_ps(v, v);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(products, products, 85), products);
    return _mm_add_ss(_mm_shuffle_ps(products, products, 170), xy);
}
static __forceinline __m128 normalized3(__m128 v)
{
    __m128 half = _mm_set_ss(0.5f);
    __m128 three = _mm_set_ss(3.0f);
    __m128 zero = _mm_set_ss(0.0f);
    __m128 square = squared3(v);
    __m128 isZero = _mm_cmpeq_ss(square, zero);
    __m128 estimate = _mm_rsqrt_ss(square);
    __m128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(square, estimate), estimate));
    __m128 inverse = _mm_andnot_ps(isZero, _mm_mul_ss(_mm_mul_ss(half, estimate), correction));
    return _mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), v);
}
static __forceinline void transformed(QueryVector& r, const Mat16& m, __m128 v)
{
    __m128 px = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), m.col[0].q);
    __m128 py = _mm_mul_ps(_mm_shuffle_ps(v, v, 85), m.col[1].q);
    __m128 pz = _mm_mul_ps(_mm_shuffle_ps(v, v, 170), m.col[2].q);
    r.q = _mm_add_ps(_mm_add_ps(py, px), _mm_add_ps(pz, m.col[3].q));
}
static __forceinline __m128 make4(float x, float y, float z, float w)
{
    return _mm_setr_ps(x, y, z, w);
}
static __forceinline QueryVector subtractVectors(const QueryVector& a, const QueryVector& b)
{
    QueryVector result;
    result.q = _mm_sub_ps(a.q, b.q);
    return result;
}
struct CastWorkspace
{
    QueryVector direction, origin, endpoint;
    RayIn input;
    QueryVector pos;
    Mat16 scratch;
    CollisionOutput output;
    ShapeStorage storage;
};
// Checks filters and geometry, may run a ray cast or contact query, and returns the resulting flag.
// @fnv 0x00c6eb00
// The shared controller has no declaration for this routine yet. The unused
// EDX argument preserves its original thiscall stack argument layout.
// src: COMMUNITY 0x00c6eb00
char __fastcall bhkCharacterController_IsStep(bhkCharacterController* controller, void*, ArgObj* arg)
{
    ArgObj* a = arg;
    VarObj* o20 = a->f20;
    void* decoded20;
    if (o20->type == 2)
        decoded20 = (char*)o20 + (signed char)o20->b10;
    else
        decoded20 = 0;
    VarObj* o48 = a->f48;
    VarObj* decoded48;
    if (o48->type == 1)
        decoded48 = (VarObj*)((char*)o48 + (signed char)o48->b10);
    else
        decoded48 = 0;
    bool flag = false;
    int iIndex = 0;
    if (decoded48)
    {
        BoundingVolumeNode* found = 0;
        BoundingVolumeNode* n = o48->first;
        if (n)
        {
            int type = n->type;
            if (type == 10)
            {
                n = n->f34;
                type = n->type;
            }
            if (type == 0x17 || type == 0x1e || type == 0x1f)
                found = n;
        }
        int key = a->f4c;
        bool allowed = true;
        if (found && found->child)
        {
            BoundingVolumeNode* child = found->child;
            int v = key != -1 ? child->bhkShape_GetSubshapeMaterial(key) : child->f10 & 31;
            char c = 0;
            if (DAT_01267bc8)
                c = DAT_01267bc8(v);
            allowed = c == 0;
        }
        flag = allowed == 0;
        if (flag)
            goto end;
    }
    if (!decoded20 || !decoded48)
        goto end;
    {
        BoundingVolumeNode* shape = a->f48->first;
        float scale = (*reinterpret_cast<float*>((char*)controller + 0x5f0));
        BoundingVolumeNode* node5 = 0;
        BoundingVolumeNode* pNode20 = a->f20->first;
        if (pNode20->type == 5)
        {
            node5 = pNode20;
            scale = pNode20->radius;
        }
        QueryVector direction;
        QueryVector origin;
        QueryVector endpoint;
        RayIn input;
        QueryVector pos;
        Mat16 scratch;
        CollisionOutput output;
        ShapeStorage storage;
        pos.q = _mm_load_ps(a->v);
        float sourceZ = (float)pos.get(2);
        controller->SubtractVectors(reinterpret_cast<Vec4*>(&origin));
        if ((*reinterpret_cast<Sub410*>((char*)controller + 0x410)).flags & 1)
        {
            unsigned i = 0;
            void* tm = &((VarObj*)decoded20)->u0b0;
            for (; i < 2; ++i)
            {
                if (node5)
                    direction.q = node5->points[i];
                else
                {
                    direction.q = make4(0.0f, (float)((*reinterpret_cast<float*>((char*)controller + 0x5f4)) * 0.5), scale, 0.0f);
                    if (i == 1)
                        direction.q.m128_f32[1] = (float)(direction.q.m128_f32[1] * -1.0);
                }
                (reinterpret_cast<QueryVector*>((char*)controller + 0x5b0))[i].setTransformedPos_00c7f640(tm, &direction);
                (reinterpret_cast<QueryVector*>((char*)controller + 0x5b0))[i].q.m128_f32[2] += (*reinterpret_cast<float*>((char*)controller + 0x470));
                input.vectors[i] = subtractVectors(pos, (reinterpret_cast<QueryVector*>((char*)controller + 0x5b0))[i]);
            }
            float d0 = scalar(squared3(input.vectors[0].q));
            float d1 = scalar(squared3(input.vectors[1].q));
            iIndex = 0;
            if (!(d0 < d1))
                iIndex = 1;
            origin(0) = (float)(reinterpret_cast<QueryVector*>((char*)controller + 0x5b0))[iIndex].get(0);
            origin(1) = (float)(reinterpret_cast<QueryVector*>((char*)controller + 0x5b0))[iIndex].get(1);
        }
        __m128 vLeft = origin.q;
        _ReadWriteBarrier();
        direction.q = _mm_sub_ps(vLeft, pos.q);
        direction.q.m128_f32[2] = 0.0f;
        origin(2) += (*reinterpret_cast<float*>((char*)controller + 0x470));
        __m128 vNormalized = normalized3(direction.q);
        pos.q.m128_f32[2] = (float)origin.get(2);
        float fDeltaZ = sourceZ - (float)origin.get(2);
        direction.q = vNormalized;
        char side = 1;
        if (!(fDeltaZ > 0.0f))
            side = 0;
        float limit = (float)((*reinterpret_cast<float*>((char*)controller + 0x470)) / 3.0);
        if (fDeltaZ > limit)
        {
            if (!((*reinterpret_cast<Sub410*>((char*)controller + 0x410)).flags & 1))
                goto end;
            fDeltaZ = sourceZ - (reinterpret_cast<QueryVector*>((char*)controller + 0x5b0))[iIndex].q.m128_f32[2] + (*reinterpret_cast<float*>((char*)controller + 0x470));
            if (fDeltaZ > 0.0f)
            {
                if (fDeltaZ > limit)
                    goto end;
                side = 1;
            }
        }
        int childKey = a->f4c;
        if (childKey != -1)
        {
            ResObj* pResObj = (ResObj*)GetValidatedPointer(shape);
            if (pResObj)
            {
                BoundingVolumeNode* triangle = ((ResFn)pResObj->iface.vtbl[5])(&pResObj->iface, childKey, &storage);
                __m128 c0 = decoded48->mat.col[0].q;
                __m128 c1 = decoded48->mat.col[1].q;
                __m128 c2 = decoded48->mat.col[2].q;
                __m128 c3 = decoded48->mat.col[3].q;
                for (int k = 2; k >= 0; --k)
                {
                    __m128 v = triangle->points[k];
                    __m128 x = _mm_mul_ps(c0, _mm_shuffle_ps(v, v, 0));
                    __m128 y = _mm_mul_ps(c1, _mm_shuffle_ps(v, v, 85));
                    __m128 z = _mm_mul_ps(c2, _mm_shuffle_ps(v, v, 170));
                    scratch.col[k].q = _mm_add_ps(_mm_add_ps(y, x), _mm_add_ps(z, c3));
                }
                Plane plane;
                ComputeInverseLengths(scratch.col, &plane);
                input.vectors[1].q = pos.q;
                input.vectors[0].q = pos.q;
                input.vectors[1].q.m128_f32[0] -= scalar(direction.q) * (*reinterpret_cast<float*>((char*)controller + 0x474));
                input.vectors[1].q.m128_f32[1] -= scalar(_mm_shuffle_ps(direction.q, direction.q, 85)) * (*reinterpret_cast<float*>((char*)controller + 0x474));
                hkCollideCapsuleUtilCapsVsTri(input.vectors, 0.05f, scratch.col, triangle->radius, &plane, 0.0f, 0, &output.contacts, 0);
                flag = output.contacts.hit[0].distance >= 0.0f && output.contacts.hit[1].distance >= 0.0f;
                goto end;
            }
        }
        {
            unsigned int uiLastKey = ~0U;
            input.filter = 0;
            input.collectionFilter = 0;
            output.ray.fraction = 1.0f;
            output.ray.extra = -1;
            output.ray.keyIndex = 0;
            output.ray.keys[0] = -1;
            endpoint.q = origin.q;
            scale = (*reinterpret_cast<float*>((char*)controller + 0x474)) + scale;
            endpoint.q.m128_f32[0] -= scalar(direction.q) * scale;
            endpoint.q.m128_f32[1] -= scalar(_mm_shuffle_ps(direction.q, direction.q, 85)) * scale;
            scratch.col[0].q = decoded48->mat.col[0].q;
            scratch.col[1].q = decoded48->mat.col[1].q;
            scratch.col[2].q = decoded48->mat.col[2].q;
            scratch.col[3].q = decoded48->mat.col[3].q;
            input.vectors[0].hkVector4_setTransformedInversePos(&scratch, &origin);
            input.vectors[1].hkVector4_setTransformedInversePos(&scratch, &endpoint);
            ((RayShape*)shape)->cast(input, output.ray);
            if (output.ray.fraction < 1.0f)
            {
                for (int j = 0; j < 8; ++j)
                {
                    unsigned int key = output.ray.keys[j];
                    if (key == -1)
                        break;
                    uiLastKey = key;
                }
                flag = bhkCharacterController_IsShapeConsideredPenetrating(shape, 1, side, uiLastKey) == 0;
            }
            else
            {
                flag = true;
            }
        }
    }
end:
    if (((*reinterpret_cast<Sub410*>((char*)controller + 0x410)).flags & 1) && flag)
        (*reinterpret_cast<Sub410*>((char*)controller + 0x410)).AccumulateValue((void*)iIndex, scalar(_mm_shuffle_ps(_mm_load_ps(a->v), _mm_load_ps(a->v), 170)));
    return flag;
}
