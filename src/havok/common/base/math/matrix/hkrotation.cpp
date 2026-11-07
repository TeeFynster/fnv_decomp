
// src/havok/common/base/math/matrix/hkrotation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hkrotation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkVector4q.h"


struct CB2FC0Object;

struct __declspec(align(16)) CB2FC0Snapshot
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;

    CB2FC0Snapshot(const CB2FC0Object* object);
};

struct CB2FC0Object
{
    void hkRotation_set(void* snapshot);
    void hkRotation_renormalize();
};

// Builds a CB2FC0Snapshot from this object and passes it to FUN_00cb2d90.
// @fnv 0x00cb2fc0
// src: HAVOK_LIB 0x00cb2fc0
void CB2FC0Object::hkRotation_renormalize()
{
    CB2FC0Snapshot snapshot(this);
    hkRotation_set(&snapshot);
}

struct __declspec(align(16)) SpawnedSnap
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;

    SpawnedSnap(int value, float scale);
};

class FUN_00cb2e30_cls
{
  public:
    void SpawnSnap(int value, float scale);
};

// Builds a SpawnedSnap from value and scale, then passes it to FUN_00cb2d90 on this object.
// @fnv 0x00cb2e30
void FUN_00cb2e30_cls::SpawnSnap(int value, float scale)
{
    SpawnedSnap snap(value, scale);
    ((CB2FC0Object*)this)->hkRotation_set(&snap);
}

extern int DAT_012683c0;

class FUN_00cb2ff0_base
{
  public:
    virtual void unk00();
    ~FUN_00cb2ff0_base();
    int unk04;
};

class FUN_00cb2ff0 : public FUN_00cb2ff0_base
{
  public:
    virtual ~FUN_00cb2ff0();
    void unk08();
};

// Calls unk08 on this object, then decrements the global counter DAT_012683c0.
// @fnv 0x00cb2ff0
FUN_00cb2ff0::~FUN_00cb2ff0()
{
    this->unk08();
    DAT_012683c0--;
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00cb2e70 {
// Exe 0x00cb2e70 IsOrthonormal: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
    LocalM128 _mm_set_ps1(float);
    void _mm_store_ss(float*, LocalM128);
    int _mm_movemask_ps(LocalM128);
}
extern LocalM128 DAT_01017d10;
}  // namespace fnv_00cb2e70

__forceinline float hkVector4q::lengthSquared3() const
{
    typedef fnv_00cb2e70::LocalM128 Quad;
    const Quad& components = reinterpret_cast<const Quad&>(m_vComponents);
    Quad sq = _mm_mul_ps(components, components);
    Quad t = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    t = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), t);
    float r;
    _mm_store_ss(&r, t);
    return r;
}

__forceinline hkBool hkVector4q::equals3(const hkVector4q& v, float epsilon) const
{
    typedef fnv_00cb2e70::LocalM128 Quad;
    Quad diff = _mm_and_ps(_mm_sub_ps(reinterpret_cast<const Quad&>(m_vComponents),
                                    reinterpret_cast<const Quad&>(v.m_vComponents)), fnv_00cb2e70::DAT_01017d10);
    Quad eps = fnv_00cb2e70::_mm_set_ps1(epsilon);
    int mask = _mm_movemask_ps(_mm_cmple_ps(diff, eps)) & 7;
    return mask == 7;
}
#include "../../../../../../include/hkRotation.h"


namespace fnv_00cb2e70 {
__forceinline __m128 hkCross(__m128 a, __m128 b)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(cross0, cross1);
}
__forceinline float hkLen2(__m128 v)
{
    __m128 sq = _mm_mul_ps(v, v);
    __m128 t = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    t = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), t);
    float r;
    _mm_store_ss(&r, t);
    return r;
}


// Checks that each column's squared length is within epsilon of 1 and the first two columns' cross product matches the third within epsilon.
// @fnv 0x00cb2e70
} // namespace fnv_00cb2e70

hkBool hkRotation::IsOrthonormal(float epsilon) const
{
    float colNorm0 = reinterpret_cast<const hkVector4q&>(m_kColumn0).lengthSquared3();
    if ((float)fabs(colNorm0 - 1.0f) > epsilon)
    {
        return false;
    }
    float colNorm1 = reinterpret_cast<const hkVector4q&>(m_kColumn1).lengthSquared3();
    if ((float)fabs(colNorm1 - 1.0f) > epsilon)
    {
        return false;
    }
    float colNorm2 = reinterpret_cast<const hkVector4q&>(m_kColumn2).lengthSquared3();
    if ((float)fabs(colNorm2 - 1.0f) > epsilon)
    {
        return false;
    }
    hkVector4q col0crosscol1;
    fnv_00cb2e70::LocalM128 cross = fnv_00cb2e70::hkCross(reinterpret_cast<const fnv_00cb2e70::LocalM128&>(m_kColumn0.m_vComponents),
                             reinterpret_cast<const fnv_00cb2e70::LocalM128&>(m_kColumn1.m_vComponents));
    col0crosscol1.m_vComponents = reinterpret_cast<const ::__m128&>(cross);
    return col0crosscol1.equals3(reinterpret_cast<const hkVector4q&>(m_kColumn2), epsilon);
}


struct FUN_00cd4d90_cls
{
    __m128 m_row0;
    __m128 m_row1;
    __m128 m_row2;

    const __m128* ScaleRows(const __m128* scale, const __m128* matrix);
};

// Multiplies each row by the first value at scale, adds it to the corresponding row, and returns scale.
// @fnv 0x00cd4d90
const __m128* FUN_00cd4d90_cls::ScaleRows(const __m128* scale, const __m128* matrix)
{
    m_row0 = _mm_add_ps(
        _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps((const float*)scale), _mm_load_ps((const float*)scale), 0), matrix[0]),
        m_row0);
    m_row1 = _mm_add_ps(
        _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps((const float*)scale), _mm_load_ps((const float*)scale), 0), matrix[1]),
        m_row1);
    m_row2 = _mm_add_ps(
        _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps((const float*)scale), _mm_load_ps((const float*)scale), 0), matrix[2]),
        m_row2);
    return scale;
}

extern const __m128 DAT_010c7180;
extern const __m128 DAT_010c8770;
extern const __m128 DAT_010c8780;
class ProductHolder
{
    struct __declspec(align(16)) Words
    {
        float x, y, z, w;
    };
    Words value;

  public:
    ProductHolder(__m128 input)
    {
        _mm_store_ps(&value.x, input);
    }
    operator __m128() const
    {
        return _mm_load_ps(&value.x);
    }
};
struct RotationRows : FUN_00cd4d90_cls
{
    void* hkRotation_set(void* snapshot);
};
static __forceinline void convertRotation(RotationRows& output, __m128 quaternion)
{
    __m128 twice = _mm_add_ps(quaternion, quaternion);
    __m128 crossInputs = _mm_shuffle_ps(quaternion, quaternion, 0x41);
    __m128 pairInputs = _mm_shuffle_ps(twice, twice, 0xa5);
    __m128 squareX = _mm_mul_ss(quaternion, twice);
    __m128 products = _mm_mul_ps(pairInputs, crossInputs);
    ProductHolder savedProducts(products);
    __assume((reinterpret_cast<unsigned>(&output) & 15) == 0);
    __m128 diagonalStart = _mm_sub_ss(DAT_010c7180, squareX);
    __m128 signs = DAT_010c8780;
    __m128 signedProducts = _mm_xor_ps(static_cast<__m128>(savedProducts), DAT_010c8780);
    __m128 mixed = _mm_mul_ps(_mm_shuffle_ps(quaternion, quaternion, 0xfe), _mm_shuffle_ps(twice, twice, 0x1a));
    mixed = _mm_xor_ps(mixed, _mm_load_ps((const float*)&DAT_010c8770));
    mixed = _mm_add_ss(mixed, DAT_010c7180);
    __m128 row0 = _mm_sub_ps(mixed, signedProducts);
    output.m_row0 = row0;
    __m128 row1 = _mm_xor_ps(mixed, *(const __m128*)&signs);
    signedProducts = _mm_move_ss(signedProducts, squareX);
    row1 = _mm_sub_ps(row1, signedProducts);
    row1 = _mm_shuffle_ps(row1, row1, 0xb1);
    __m128 diagonal = _mm_sub_ss(diagonalStart, _mm_mul_ps(pairInputs, crossInputs));
    __m128 row2 = _mm_shuffle_ps(_mm_movehl_ps(row0, row1), diagonal, 0x8d);
    output.m_row1 = row1;
    output.m_row2 = row2;
}
// Converts a quaternion loaded from snapshot into a rotation matrix stored in this RotationRows object.
// @fnv 0x00cb2d90
// src: XBOX_PDB 0x00cb2d90
void* RotationRows::hkRotation_set(void* apQuaternion)
{
    convertRotation(*this, _mm_load_ps((const float*)apQuaternion));
    return apQuaternion;
}
