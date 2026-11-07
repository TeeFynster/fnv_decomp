
// src/havok/physics/collide/shape/convex/cylinder/hkpcylindershape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/cylinder/hkpcylindershape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkpCylinderShape.h"

// @fnv 0x00d571b0
// src: GUESS 0x00d571b0 (confidence: high)
int __cdecl hkpCylinderShape_ReturnConstant_0x12()
{
    return 0x12;
}

// FUN_00d571a0: __thiscall getter returning the float at this+0x14,
// which is hkpCylinderShape::m_fCylinderRadius in the pack's layout
// (vptr 0x0, m_usMemSizeAndFlags 0x4, m_sReferenceCount 0x6, m_ulUserData 0x8,
//  m_type 0xC, m_fSphereRadius 0x10, m_fCylinderRadius 0x14).

// @fnv 0x00d571a0
hkReal hkpCylinderShape::getCylinderRadius() const {
    return m_fCylinderRadius;
}

extern char DAT_01268940[];
void __cdecl hkReferencedObject_calcContentStatistics(void* item, const char* type);
// @fnv 0x00d571c0
// src: XBOX_PDB 0x00d571c0
void __cdecl hkpCylinderShape_calcContentStatistics(void* item, const char*)
{
    hkReferencedObject_calcContentStatistics(item, DAT_01268940);
}

struct C00d573e0 {
    char  pad00[0x10];
    volatile float f10;
    float f14;
    char  pad18[0x2c - 0x18];
    float f2c;
    char  pad30[0x3c - 0x30];
    float f3c;
    void SetValue(float v);
};

// @fnv 0x00d573e0
void C00d573e0::SetValue(float afValue) {
    f14 = afValue;
    f2c = f10 + afValue;
    f3c = afValue + f10;
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

extern char DAT_010305a8;
extern char DAT_010d0f1c;
extern float DAT_011b5be8;

// src: HAVOK_LIB 0x00d571d0
static __declspec(noinline) float minValueRoundedUpTo1()
{
    return 0.0f;
}

struct S00d57b20_Obj {
    void* unk00;
    int unk04;
    int unk08;
    int unk0C;

    S00d57b20_Obj* __thiscall hkpCylinderShape_hkpCylinderShape_00d57b20(int condition);
};

// @fnv 0x00d57b20
// src: HAVOK_LIB 0x00d57b20
S00d57b20_Obj* __thiscall S00d57b20_Obj::hkpCylinderShape_hkpCylinderShape_00d57b20(int condition)
{
    unk00 = &DAT_010305a8;

    if (condition)
        unk0C = 0;

    unk0C = 0x12;
    unk00 = &DAT_010d0f1c;

    if (condition && DAT_011b5be8 < 0.0f)
        DAT_011b5be8 = 1.0f - minValueRoundedUpTo1();

    unk0C = 2;
    return this;
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00d57220 {
// Exe 0x00d57220 InitPerpendiculars: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_set_ss(float);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_rsqrt_ss(LocalM128);
extern "C" LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);

struct Vec_d57220v {
    LocalM128 q;
    float& operator()(int i) { return q.m128_f32[i]; }
    const float& operator()(int i) const { return q.m128_f32[i]; }
    void setZero4() { q = _mm_setzero_ps(); }
    __forceinline void normalize3()
    {
        LocalM128 v = q;
        LocalM128 x2 = _mm_mul_ps(v, v);
        LocalM128 len2 = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        len2 = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), len2);
        LocalM128 e = _mm_rsqrt_ss(len2);
        LocalM128 mask = _mm_cmpeq_ss(len2, _mm_set_ss(0.0f));
        LocalM128 t = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e));
        LocalM128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), t);
        r = _mm_andnot_ps(mask, r);
        q = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v);
    }
    void setCross(const Vec_d57220v& a, const Vec_d57220v& b)
    {
        LocalM128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        LocalM128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(c0, c1);
    }
};

static inline float Abs_d57220v(float r) { return (float)fabs(r); }

static __forceinline void Perp_d57220v(const Vec_d57220v& vectorIn, Vec_d57220v& biVectorOut)
{
    int minIdx = 0;
    int ok1 = 1;
    int ok2 = 2;
    float a0 = Abs_d57220v(vectorIn(0));
    float a1 = Abs_d57220v(vectorIn(1));
    float a2 = Abs_d57220v(vectorIn(2));
    if (a1 < a0) {
        ok1 = 0;
        minIdx = 1;
        a0 = a1;
    }
    if (a2 < a0) {
        ok2 = minIdx;
        minIdx = 2;
    }
    biVectorOut.setZero4();
    biVectorOut(ok1) = vectorIn(ok2);
    biVectorOut(ok2) = -vectorIn(ok1);
}

struct Cyl_d57220 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec_d57220v m_kVertexA;
    Vec_d57220v m_kVertexB;
    Vec_d57220v m_kPerpendicular1;
    Vec_d57220v m_kPerpendicular2;
    void InitPerpendiculars();
};

// Computes the direction between m_kVertexA and m_kVertexB, then derives two perpendicular vectors stored in m_kPerpendicular1 and m_kPerpendicular2.
// @fnv 0x00d57220
void Cyl_d57220::InitPerpendiculars()
{
    Vec_d57220v dir;
    dir.q = _mm_sub_ps(m_kVertexB.q, m_kVertexA.q);
    dir.normalize3();
    Perp_d57220v(dir, m_kPerpendicular1);
    m_kPerpendicular1.normalize3();
    m_kPerpendicular2.setCross(dir, m_kPerpendicular1);
}
}  // namespace fnv_00d57220

extern float DAT_01016248;

struct S00d57830 {
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;
    float m_fSphereRadius;
    float m_fCylinderRadius;
    float m_fCylinderRadiusSquared;
    unsigned int m_auiShapeKeys;
    __m128 m_kVertexA;
    __m128 m_kVertexB;

    void hkpCylinderShape_getCentreImpl(__m128* out);
};

// Stores (m_kVertexA + m_kVertexB) scaled by DAT_01016248 into *out.
// @fnv 0x00d57830
// src: XBOX_PDB 0x00d57830
void S00d57830::hkpCylinderShape_getCentreImpl(__m128* out)
{
    __m128 a = this->m_kVertexA;
    __m128 b = this->m_kVertexB;
    __m128 sum = _mm_add_ps(b, a);

    *out = sum;

    __m128 c = _mm_load_ss(&DAT_01016248);
    __m128 s = _mm_shuffle_ps(c, c, 0);

    *out = _mm_mul_ps(s, sum);
}

struct FnvCpu_FUN_00d57870_CpuData0 {
    __m128 field00;
};
struct FnvCpu_FUN_00d57870_CpuObject {
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
    __m128 field30;
    void CopyField30(FnvCpu_FUN_00d57870_CpuData0* input0);
};
// @fnv 0x00d57870
void FnvCpu_FUN_00d57870_CpuObject::CopyField30(FnvCpu_FUN_00d57870_CpuData0* apCpuData)
{
    apCpuData->field00 = this->field30;
}

namespace fnv_00d571d0 {
namespace c571 { const float DAT_01056528 = 1.1f; }
using namespace c571;
// @fnv 0x00d571d0
// src: HAVOK_LIB 0x00d571d0
float __cdecl minValueRoundedUpTo1()
{
    for (float fValue = 0.0f; fValue < DAT_01056528; fValue += 0.009999999776482582)
    {
        if (fnv_FloatToInt(fValue) != 0)
            return fValue;
    }
    return 1.0f;
}
}  // namespace fnv_00d571d0
