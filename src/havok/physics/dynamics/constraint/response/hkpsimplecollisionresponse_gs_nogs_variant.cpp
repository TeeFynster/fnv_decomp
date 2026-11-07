// src/havok/physics/dynamics/constraint/response/hkpsimplecollisionresponse_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/dynamics/constraint/response/hkpsimplecollisionresponse.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/constraint/response/hkpsimplecollisionresponse.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/response/hkpsimplecollisionresponse.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include <math.h>
extern const float DAT_01011d78;
extern const float DAT_01017718;
extern float DAT_01016248;

class D9Scalar
{
    __m128 value;

  public:
    __forceinline D9Scalar()
    {}
    __forceinline D9Scalar(const __m128& x) : value(x)
    {}
    __forceinline __m128 quad() const
    {
        return value;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};

struct D9Matrix;
struct D9Rotation;
struct __declspec(align(16)) D9Vector
{
    __m128 unk00;
    __forceinline D9Vector()
    {}
    __forceinline D9Vector(float x, float y, float z, float w = 0.0f)
    {
        unk00 = _mm_setr_ps(x, y, z, w);
    }
    __forceinline D9Vector(const __m128& value)
    {
        unk00 = value;
    }
    __forceinline D9Vector(const D9Vector& value)
    {
        unk00 = value.unk00;
    }
    __forceinline void operator=(const D9Vector& value)
    {
        unk00 = value.unk00;
    }
    __forceinline void operator=(const __m128& value)
    {
        unk00 = value;
    }
    operator __m128() const
    {
        return unk00;
    }
    __forceinline float& component(int i)
    {
        return unk00.m128_f32[i];
    }
    __forceinline const float& component(int i) const
    {
        return unk00.m128_f32[i];
    }
    __forceinline void subtract(const D9Vector& a, const D9Vector& b)
    {
        unk00 = _mm_sub_ps(a.unk00, b.unk00);
    }
    __forceinline void broadcast(const D9Vector& a, int i)
    {
        if (i == 0)
            unk00 = _mm_shuffle_ps(a.unk00, a.unk00, 0);
        else if (i == 1)
            unk00 = _mm_shuffle_ps(a.unk00, a.unk00, 0x55);
        else
            unk00 = _mm_shuffle_ps(a.unk00, a.unk00, 0xaa);
    }
    __forceinline void multiply(const D9Vector& a, const D9Vector& b)
    {
        unk00 = _mm_mul_ps(a.unk00, b.unk00);
    }
    __forceinline void zero()
    {
        unk00 = _mm_setzero_ps();
    }
    __forceinline D9Scalar dot(const D9Vector& a) const
    {
        __m128 products = _mm_mul_ps(unk00, a.unk00);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(products, products, 0x55), products);
        return _mm_add_ss(_mm_shuffle_ps(products, products, 0xaa), xy);
    }
    __forceinline D9Scalar inverseLength() const
    {
        const __m128 half = _mm_set_ss(DAT_01016248);
        const __m128 three = _mm_set_ss(DAT_01017718);
        const __m128 zero = _mm_set_ss(DAT_01011d78);
        const __m128 square = dot(*this).quad();
        const __m128 empty = _mm_cmpeq_ss(square, zero);
        const __m128 approximation = _mm_rsqrt_ss(square);
        const __m128 improved =
            _mm_mul_ss(_mm_mul_ss(half, approximation),
                       _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(square, approximation), approximation)));
        return _mm_andnot_ps(empty, improved);
    }
    __forceinline void normalize3()
    {
        __m128 inverse = inverseLength().splat();
        unk00 = _mm_mul_ps(inverse, unk00);
    }
    __forceinline void cross(const D9Vector& a, const D9Vector& b)
    {
        __m128 positive = _mm_mul_ps(_mm_shuffle_ps(a.unk00, a.unk00, 0xc9), _mm_shuffle_ps(b.unk00, b.unk00, 0xd2));
        __m128 negative = _mm_mul_ps(_mm_shuffle_ps(a.unk00, a.unk00, 0xd2), _mm_shuffle_ps(b.unk00, b.unk00, 0xc9));
        unk00 = _mm_sub_ps(positive, negative);
    }
    inline void inverseRotate(const D9Rotation& matrix, const D9Vector& vector);
    inline void rotate(const D9Rotation& matrix, const D9Vector& vector);
};
struct D9Matrix
{
    D9Vector unk00, unk10, unk20;
    __forceinline D9Matrix()
    {}
    __forceinline D9Matrix(const D9Matrix& other)
    {
        unk00 = other.unk00;
        unk10 = other.unk10;
        unk20 = other.unk20;
    }
    __forceinline D9Vector& column(int i)
    {
        return (&unk00)[i];
    }
    __forceinline const D9Vector& column(int i) const
    {
        return (&unk00)[i];
    }
    void FUN_00cd4b60();
    void hkMatrix3_setMul(const D9Matrix&, const D9Matrix&);
};
struct __declspec(align(16)) D9Rotation : D9Matrix
{
};
inline void D9Vector::inverseRotate(const D9Rotation& matrix, const D9Vector& vector)
{
    __m128 x = matrix.column(0).unk00, y = matrix.column(1).unk00, z = matrix.column(2).unk00;
    {
        __m128 low, last;
        low = _mm_unpacklo_ps(x, y);
        last = _mm_shuffle_ps(_mm_unpackhi_ps(x, y), z, 0xe4);
        x = _mm_movelh_ps(low, z);
        y = _mm_shuffle_ps(_mm_movehl_ps(x, low), z, 0xd4);
        z = last;
    }
    const __m128 vx = _mm_shuffle_ps(vector.unk00, vector.unk00, 0);
    const __m128 px = _mm_mul_ps(x, vx);
    const __m128 vy = _mm_shuffle_ps(vector.unk00, vector.unk00, 0x55);
    const __m128 py = _mm_mul_ps(y, vy);
    const __m128 vz = _mm_shuffle_ps(vector.unk00, vector.unk00, 0xaa);
    const __m128 pz = _mm_mul_ps(z, vz);
    unk00 = _mm_add_ps(_mm_add_ps(px, py), pz);
}
inline void D9Vector::rotate(const D9Rotation& matrix, const D9Vector& vector)
{
    __m128 vx = _mm_shuffle_ps(vector.unk00, vector.unk00, 0);
    __m128 px = _mm_mul_ps(matrix.column(0).unk00, vx);
    __m128 vy = _mm_shuffle_ps(vector.unk00, vector.unk00, 0x55);
    __m128 py = _mm_mul_ps(matrix.column(1).unk00, vy);
    __m128 vz = _mm_shuffle_ps(vector.unk00, vector.unk00, 0xaa);
    __m128 pz = _mm_mul_ps(matrix.column(2).unk00, vz);
    unk00 = _mm_add_ps(_mm_add_ps(px, py), pz);
}
struct D9Shape
{
    D9Vector unk00, unk10, unk20, unk30, unk40;
    D9Rotation unk50;
    D9Vector& center()
    {
        return unk40;
    }
    D9Rotation& rotation()
    {
        return unk50;
    }
};
struct D9Contact
{
    D9Vector unk00, unk10;
    const D9Vector& position() const
    {
        return unk00;
    }
    const D9Vector& normal() const
    {
        return unk10;
    }
};
struct D9Row
{
    D9Vector unk00;
    D9Matrix unk10;
    D9Vector unk40;
    const void* unk50;
};
struct D9Pair
{
    D9Vector unk00, unk10;
};
struct D9Solver
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void f3c();
    virtual void f40(const D9Contact&, D9Row&, D9Pair&, D9Row&, D9Pair&);
    virtual void f44(const D9Contact&, float, D9Row&, D9Pair&, D9Row&, D9Pair&);
};
struct D9Body
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned char unke8;
    unsigned char unke9;
    unsigned char unkea;
    unsigned char unkeb;
    unsigned char unkec;
    unsigned char unked;
    unsigned char unkee;
    unsigned char unkef;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    __m128 unk1b0, unk1c0;
};
struct D9Equation
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
};
inline float D9Abs(float value)
{
    return (float)fabs(value);
}
__forceinline void D9Perpendicular(const D9Vector& normal, D9Vector& out)
{
    int minimum = 0, first = 1, second = 2;
    float x = D9Abs(normal.component(0));
    float y = D9Abs(normal.component(1));
    float z = D9Abs(normal.component(2));
    if (y < x)
    {
        first = 0;
        minimum = 1;
        x = y;
    }
    if (z < x)
    {
        second = minimum;
        minimum = 2;
    }
    out.zero();
    out.component(first) = normal.component(second);
    out.component(second) = -normal.component(first);
}
struct Basis
{
    D9Vector unk00, unk10, unk20;
    __forceinline void setNormalBasis(const D9Vector& normal)
    {
        unk00 = normal;
        D9Perpendicular(normal, unk10);
        unk10.normalize3();
        unk20.cross(normal, unk10);
    }
};
extern void __cdecl hkpCollision_BuildResponseMatrices(const D9Row&, const D9Row&, const Basis&, D9Equation&);
extern float __cdecl Object_ProcessAndReturnValue_00df5f80(const D9Equation&, void*, D9Pair&, D9Pair&);
// @fnv 0x00d9ee50
// src: GUESS 0x00d9ee50 (confidence: low)
void __cdecl hkMatrix3_setMul_ProcessEntries_00d9ee50(D9Solver* solver, const D9Contact& contact, void* parameters, D9Body* ownerA, D9Body* ownerB,
                          D9Shape* accumulatorA, D9Shape* accumulatorB, float& result)
{
    D9Row inputs[2];
    D9Pair velocities[2];
    {
        D9Shape* accumulator = accumulatorA;
        D9Body* owner = ownerA;
        for (int index = 0; index < 2; ++index)
        {
            D9Row& input = inputs[index];
            D9Pair& velocity = velocities[index];
            input.unk40 = accumulator->unk30;
            const D9Vector& center = accumulator->center();
            input.unk00.subtract(contact.position(), center);
            const D9Vector& inverseMasses = accumulator->unk30;
            velocity.unk00 = accumulator->unk10;
            {
                D9Rotation rotation(accumulator->rotation());
                velocity.unk10.inverseRotate(rotation, accumulator->unk20);
                rotation.FUN_00cd4b60();
                D9Matrix scaled;
                D9Vector sx, sy, sz;
                sx.broadcast(inverseMasses, 0);
                sy.broadcast(inverseMasses, 1);
                sz.broadcast(inverseMasses, 2);
                scaled.column(0).multiply(sx, rotation.column(0));
                scaled.column(1).multiply(sy, rotation.column(1));
                scaled.column(2).multiply(sz, rotation.column(2));
                input.unk10.hkMatrix3_setMul(scaled, accumulator->rotation());
            }
            input.unk50 = &owner->unkf0;
            accumulator = accumulatorB;
            owner = ownerB;
        }
    }
    D9Equation equation;
    Basis basis;
    basis.setNormalBasis(contact.normal());
    solver->f40(contact, inputs[0], velocities[0], inputs[1], velocities[1]);
    hkpCollision_BuildResponseMatrices(inputs[0], inputs[1], basis, equation);
    result = Object_ProcessAndReturnValue_00df5f80(equation, parameters, velocities[0], velocities[1]);
    solver->f44(contact, result, inputs[0], velocities[0], inputs[1], velocities[1]);
    accumulatorA->unk10 = velocities[0].unk00;
    if (ownerA->unke8 != 5)
    {
        ownerA->unk1b0 = velocities[0].unk00;
        ownerA->unk1c0 = velocities[0].unk10;
    }
    accumulatorB->unk10 = velocities[1].unk00;
    if (ownerB->unke8 != 5)
    {
        ownerB->unk1b0 = velocities[1].unk00;
        ownerB->unk1c0 = velocities[1].unk10;
    }
    {
        D9Shape* accumulator = accumulatorA;
        for (int index = 0; index < 2; accumulator = accumulatorB, ++index)
            accumulator->unk20.rotate(accumulator->rotation(), velocities[index].unk10);
    }
}
