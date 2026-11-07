
// src/havok/physics/internal/collide/gjk/hkpgsk_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/gjk/hkpgsk.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/gjk/hkpgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/hkpgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Entry
{
    char pad[12];
    unsigned short val;
    char pad2[2];
};
struct Dest
{
    unsigned short words[4];
    unsigned char count1;
    unsigned char count2;
};
struct ThisClass
{
    int count1;
    int count2;
    char pad[0x18];
    Entry entries1[3];
    char pad2[0x90];
    Entry entries2[3];

    void hkpGsk_exitAndExportCacheImpl(Dest* out);
};

// local form of hkVector4: 0x00daa7e0 needs its original trivial packet calls (shared extent 1117 vs 1109).


// Define FNV_VECTOR_USE_LOCAL_SSE when __m128 and intrinsics are already declared.
#if !defined(FNV_VECTOR_USE_LOCAL_SSE)
#include <xmmintrin.h>
#endif

class Scalar;
class Comparison;
class Transform;
class hkRotation;

class SimplexVectorCallLocal_00daa7e0
{
public:
    union
    {
        __m128 q;
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
    };

    __forceinline SimplexVectorCallLocal_00daa7e0() {}
    __forceinline SimplexVectorCallLocal_00daa7e0(const SimplexVectorCallLocal_00daa7e0& vector) : q(vector.q) {}
    __forceinline SimplexVectorCallLocal_00daa7e0(const __m128& vector) : q(vector) {}
    SimplexVectorCallLocal_00daa7e0(float x, float y, float z);
    __forceinline SimplexVectorCallLocal_00daa7e0& operator=(const SimplexVectorCallLocal_00daa7e0& vector)
    {
        q = vector.q;
        return *this;
    }
    __forceinline void operator=(const __m128& vector)
    {
        q = vector;
    }
    operator __m128() const;
    SimplexVectorCallLocal_00daa7e0 operator*(float value) const;
    SimplexVectorCallLocal_00daa7e0 operator+(const SimplexVectorCallLocal_00daa7e0& vector) const;
    SimplexVectorCallLocal_00daa7e0 operator-() const;
    float& operator()(int index);
    const float& operator()(int index) const;
    __m128& packet();
    const __m128& packet() const;

    void set(float x, float y, float z, float w = 0.0f);
    void zero();
    void setZero4();
    void subtract(const SimplexVectorCallLocal_00daa7e0& a, const SimplexVectorCallLocal_00daa7e0& b);
    void sub(const SimplexVectorCallLocal_00daa7e0& a, const SimplexVectorCallLocal_00daa7e0& b);
    void setSub(const SimplexVectorCallLocal_00daa7e0& a, const SimplexVectorCallLocal_00daa7e0& b);
    void setSub4(const SimplexVectorCallLocal_00daa7e0& a, const SimplexVectorCallLocal_00daa7e0& b);
    void add(const SimplexVectorCallLocal_00daa7e0& a, const SimplexVectorCallLocal_00daa7e0& b);
    void setAdd(const SimplexVectorCallLocal_00daa7e0& a, const SimplexVectorCallLocal_00daa7e0& b);
    void setAdd4(const SimplexVectorCallLocal_00daa7e0& a, const SimplexVectorCallLocal_00daa7e0& b);
    void add4(const SimplexVectorCallLocal_00daa7e0& vector);
    void mul(const SimplexVectorCallLocal_00daa7e0& a, const SimplexVectorCallLocal_00daa7e0& b);
    void mul4(const SimplexVectorCallLocal_00daa7e0& vector);
    void mul4(const Scalar& scalar);
    void multiply(const Scalar& scalar);
    void scale(const Scalar& scalar);
    void product(const Scalar& scalar, const SimplexVectorCallLocal_00daa7e0& vector);
    void cross(const SimplexVectorCallLocal_00daa7e0& a, const SimplexVectorCallLocal_00daa7e0& b);
    void setCross(const SimplexVectorCallLocal_00daa7e0& a, const SimplexVectorCallLocal_00daa7e0& b);
    void negate(const SimplexVectorCallLocal_00daa7e0& vector);
    void setNeg4(const SimplexVectorCallLocal_00daa7e0& vector);
    void addMul(const SimplexVectorCallLocal_00daa7e0& a, __m128 scale, const SimplexVectorCallLocal_00daa7e0& b);
    void setAddMul4(const SimplexVectorCallLocal_00daa7e0& a, const SimplexVectorCallLocal_00daa7e0& b, const Scalar& scalar);
    void interpolate(const SimplexVectorCallLocal_00daa7e0& a, const SimplexVectorCallLocal_00daa7e0& b, const Scalar& t);
    void setInterpolate4(const SimplexVectorCallLocal_00daa7e0& a, const SimplexVectorCallLocal_00daa7e0& b, const Scalar& t);
    void Interpolate(const SimplexVectorCallLocal_00daa7e0& oldValue, const SimplexVectorCallLocal_00daa7e0& newValue, float factor);
    void SetTransformedPoint(const Transform& transform, const SimplexVectorCallLocal_00daa7e0& point);

    Scalar getSimdAt(int index) const;
    Scalar dot(const SimplexVectorCallLocal_00daa7e0& vector) const;
    Scalar dot3(const SimplexVectorCallLocal_00daa7e0& vector) const;
    float DotProduct(const SimplexVectorCallLocal_00daa7e0& vector);
    Scalar sum() const;
    Scalar norm() const;
    Scalar lengthSquared3() const;
    Scalar length3() const;
    float length() const;
    Scalar inverseLength() const;
    void normalize();
    void normalize3();
    Comparison compareLessThanZero4() const;
    int getMajorAxis() const;
    int maxAxisSecond() const;
    int maxAxis() const;
    float GetAngle();

    void SetComponents(float x, float y, float z);
    SimplexVectorCallLocal_00daa7e0 SubtractIntoVector(const SimplexVectorCallLocal_00daa7e0& vector);
    SimplexVectorCallLocal_00daa7e0 FUN_00439e90(const SimplexVectorCallLocal_00daa7e0& vector);
    void ScaleComponents(float value);
    void Unitize_004a0c10();
    void normalize_005611c0();
    void setMul(const SimplexVectorCallLocal_00daa7e0* a, const SimplexVectorCallLocal_00daa7e0* b);
    void setMulInverse(const SimplexVectorCallLocal_00daa7e0* a, const SimplexVectorCallLocal_00daa7e0* b);
    void hkQuaternion_getAxis(SimplexVectorCallLocal_00daa7e0* vector);
    void setTransformedPos_00c7f640(const Transform& transform, const SimplexVectorCallLocal_00daa7e0& point);
    void hkQuaternion_setAxisAngle(const SimplexVectorCallLocal_00daa7e0* vector, float value);
    void FUN_00cb26e0(const hkRotation* rotation);

    template <int I> void splat(const SimplexVectorCallLocal_00daa7e0& vector);

    static const SimplexVectorCallLocal_00daa7e0& getZero();
};

#include "../../../../../../include/Transform.h"
struct PlainVector
{
    float x, y, z, w;
};

struct SolverOutput
{
    SimplexVectorCallLocal_00daa7e0 normal;
    SimplexVectorCallLocal_00daa7e0 point;
    float distance;
};

extern const float runtimeFloatSettingDefault726;

int __cdecl TestPenetration(void*, void*, const Transform*, float, SimplexVectorCallLocal_00daa7e0*, SimplexVectorCallLocal_00daa7e0*, SimplexVectorCallLocal_00daa7e0*, int, SolverOutput*);

void __cdecl hkLineSegmentUtil_closestLineSegLineSeg(SimplexVectorCallLocal_00daa7e0*, SimplexVectorCallLocal_00daa7e0*, SimplexVectorCallLocal_00daa7e0*, SimplexVectorCallLocal_00daa7e0*, SimplexVectorCallLocal_00daa7e0*);

struct Simplex
{

    int countA, countB, unk08, unk0c, unk10, status, unk18, unk1c;

    SimplexVectorCallLocal_00daa7e0 a[4];

    SimplexVectorCallLocal_00daa7e0 unk60, unk70, unk80, unk90;

    SimplexVectorCallLocal_00daa7e0 verticesB[8];

    SimplexVectorCallLocal_00daa7e0 result, axis;

    void hkpGsk_reduceDimensionExtended();

    void hkpGsk_processEdgeTriangle(void*, void*, const Transform*);
};

static __forceinline SimplexVectorCallLocal_00daa7e0 copyVector(const PlainVector& p)
{
    SimplexVectorCallLocal_00daa7e0 v;
    reinterpret_cast<PlainVector&>(v.q) = p;
    return v;
}

// @fnv 0x00daa7e0
// src: XBOX_PDB 0x00daa7e0
void Simplex::hkpGsk_processEdgeTriangle(void* arg1, void* arg2, const Transform* transform)
{

    int count = 4;

    if (countB >= 3)
    {

        if (countB > 3)
            a[3] = a[0];

        else if (countA > 1)
        {
            a[3] = a[1];
            verticesB[4 + 3] = verticesB[4 + 0];
            verticesB[3] = verticesB[0];
        }

        else
            count = 3;

        a[1] = a[0];
        a[2] = a[0];
    }
    else if (countA >= 3)
    {

        if (countA > 3)
        {
            verticesB[4 + 3] = verticesB[4 + 0];
            verticesB[3] = verticesB[0];
        }

        else if (countB > 1)
        {
            a[3] = a[0];
            verticesB[4 + 3] = verticesB[4 + 1];
            verticesB[3] = verticesB[1];
        }

        else
            count = 3;

        verticesB[4 + 1] = verticesB[4 + 0];
        verticesB[1] = verticesB[0];
        verticesB[4 + 2] = verticesB[4 + 0];
        verticesB[2] = verticesB[0];
    }
    else
    {

        SimplexVectorCallLocal_00daa7e0 v = copyVector(reinterpret_cast<const PlainVector&>(a[0].q));
        a[countA] = v;
        a[countA + 1] = v;

        v = copyVector(reinterpret_cast<const PlainVector&>(verticesB[4 + 0].q));
        verticesB[4 + countB] = v;
        verticesB[4 + countB + 1] = v;

        v = copyVector(reinterpret_cast<const PlainVector&>(verticesB[0].q));
        verticesB[countB] = v;
        verticesB[countB + 1] = v;

        count = 1;
    }

    SimplexVectorCallLocal_00daa7e0 differences[4];
    SolverOutput output;

    for (int i = 0; i < count; ++i)
        differences[i].q = _mm_sub_ps(a[i].q, verticesB[i].q);

    if (TestPenetration(arg1, arg2, transform, runtimeFloatSettingDefault726, a, verticesB + 4, differences, count,
                        &output) == 1)
    {

        countA = 1;
        countB = 1;
        status = 1;
        result = output.normal;
        return;
    }

    unsigned tag2 = *(unsigned*)&a[2].q.m128_f32[3] & 0xc0ffffff;

    unsigned tag1 = *(unsigned*)&a[1].q.m128_f32[3] & 0xc0ffffff;

    countA = 3;
    countB = 3;

    if (tag1 == tag2 || ((*(unsigned*)&a[0].q.m128_f32[3] & 0xc0ffffff) == tag2))
        countA = 2;

    if ((*(unsigned*)&a[0].q.m128_f32[3] & 0xc0ffffff) == tag1)
    {
        --countA;
        a[0] = a[countA];
    }

    tag2 = *(unsigned*)&verticesB[4 + 2].q.m128_f32[3] & 0xc0ffffff;

    tag1 = *(unsigned*)&verticesB[4 + 1].q.m128_f32[3] & 0xc0ffffff;

    if (tag1 == tag2)
        --countB;
    else if ((*(unsigned*)&verticesB[4 + 0].q.m128_f32[3] & 0xc0ffffff) == tag2)
        --countB;

    if (countB >= 2 && ((*(unsigned*)&verticesB[4 + 0].q.m128_f32[3] & 0xc0ffffff) == tag1))
    {
        --countB;
        verticesB[4 + 0] = verticesB[4 + countB];
    }

    SimplexVectorCallLocal_00daa7e0 tx = copyVector(reinterpret_cast<const PlainVector&>(transform->r[0])),
           ty = copyVector(reinterpret_cast<const PlainVector&>(transform->r[1])),
           tz = copyVector(reinterpret_cast<const PlainVector&>(transform->r[2])),
           tw = copyVector(reinterpret_cast<const PlainVector&>(transform->r[3]));

    int j = countB - 1;
    SimplexVectorCallLocal_00daa7e0* cursor = &verticesB[4 + j];
    do
    {

        __m128 p = cursor->q;

        __m128 xy =
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p, p, 0x55), ty.q), _mm_mul_ps(_mm_shuffle_ps(p, p, 0), tx.q));

        __m128 zw = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p, p, 0xaa), tz.q), tw.q);

        cursor[-4].q = _mm_add_ps(xy, zw);
        --j;
        --cursor;

    } while (j >= 0);

    if (countA + countB > 4)
        hkpGsk_reduceDimensionExtended();

    if (countA == 2 && countB == 2)
    {

        SimplexVectorCallLocal_00daa7e0 da, db;

        da.q = _mm_sub_ps(a[1].q, a[0].q);

        db.q = _mm_sub_ps(verticesB[1].q, verticesB[0].q);

        hkLineSegmentUtil_closestLineSegLineSeg(a, &da, verticesB, &db, &axis);
        status = 1;
    }

    else
        status = 1;
    result = output.normal;
}
