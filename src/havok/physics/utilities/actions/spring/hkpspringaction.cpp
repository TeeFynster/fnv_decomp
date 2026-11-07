
// src/havok/physics/utilities/actions/spring/hkpspringaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/spring/hkpspringaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the original intrinsic lanes: the SDK's byte-array aliases trigger /GS on vector temporaries.
#define _INCLUDED_MM2
// Exe 0x00d4d390 UpdatePivotsAndRestLength: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_sqrt_ss(LocalM128 a);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, LocalM128 a);

#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpEntity.h"

inline hkSimdReal::hkSimdReal(const LocalM128& x) : m_vValue(x)
{}

inline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}

inline hkSimdReal hkVector4::length3() const
{
    const LocalM128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
    const LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum));
}

// GetMonitorStream is 0x00c85750; the shared router stores its Havok heap allocator at +0x10.

extern int g_unk01269168;

// @fnv 0x00cf4ef0
// src: COMMUNITY 0x00cf4ef0
int* __cdecl hkpBinaryAction_getClassType()
{
    return &g_unk01269168;
}

void* __cdecl _fnv_zlib_memset(void* pvDst, int iValue, unsigned int uiNumBytes);

struct hkShape00D4F0
{
    unsigned short m_type;
    unsigned short unk02[0x47];
    hkShape00D4F0()
    {
        m_type = 2;
    }
};

struct hkShape90D4F0
{
    unsigned short m_type;
    unsigned short unk02[5];
    hkShape90D4F0()
    {
        m_type = 9;
    }
};

struct hkShape9CD4F0
{
    unsigned short m_type;
    unsigned short unk02[5];
    hkShape9CD4F0()
    {
        m_type = 8;
    }
};

struct hkShapeA8D4F0
{
    unsigned short m_type;
    unsigned short unk02;
    hkShapeA8D4F0()
    {
        m_type = 7;
    }
};

struct hkShapeB0D4F0
{
    unsigned short m_type;
    unsigned short unk02[0x37];
    hkShapeB0D4F0()
    {
        m_type = 4;
    }
};

struct hkShape120D4F0
{
    unsigned short m_type;
    hkShape120D4F0()
    {
        m_type = 12;
    }
};

class FUN_00d4f000
{
  public:
    hkShape00D4F0 m_s00;
    hkShape90D4F0 m_s90;
    hkShape9CD4F0 m_s9C;
    hkShapeA8D4F0 m_sA8;
    hkShapeA8D4F0 m_sAC;
    hkShapeB0D4F0 m_sB0;
    hkShape120D4F0 m_s120;

    FUN_00d4f000() throw();
};

// Constructs the object by initialising its embedded shape members; the zero-fill branch is never taken because pcBegin equals pcEnd.
// @fnv 0x00d4f000
FUN_00d4f000::FUN_00d4f000() throw()
{
    char* pcBegin = (char*)&m_sB0;
    char* pcEnd = (char*)&m_sB0;
    if (pcBegin < pcEnd)
        _fnv_zlib_memset(pcBegin, 0, pcEnd - pcBegin);
}

struct FUN_00cf4d80
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    float m_fMass;
    float m_fSpringConstant;
    float m_fDamping;
    bool m_bModifierActive;
    bool m_bEnableState;
    FUN_00cf4d80(void* a, void* b, unsigned long c);
};
extern int DAT_010d08f4;
extern float DAT_01013974;
extern float DAT_0101e2bc;
struct FUN_00d4d340 : FUN_00cf4d80
{
    FUN_00d4d340(void* a, void* b, unsigned long c);
};
// Calls the base constructor, sets the vtable, m_fMass to 1.0, spring constant and damping from globals, and sets both bool flags to true.
// @fnv 0x00d4d340
FUN_00d4d340::FUN_00d4d340(void* a, void* b, unsigned long c) : FUN_00cf4d80(a, b, c)
{
    float* __restrict pf = &m_fSpringConstant;
    m_fMass = 1.0f;
    *pf = DAT_01013974;
    *(int* __restrict*)this = &DAT_010d08f4;
    m_fDamping = DAT_0101e2bc;
    *(volatile bool*)&m_bModifierActive = true;
    *(volatile bool*)&m_bEnableState = true;
}

class hkpStiffSpringWrapperD4D3 : public hkBaseObject
{
  public:
    void UpdatePivotsAndRestLength(const hkVector4& kPivotAW, const hkVector4& kPivotBW);

    unsigned int unk04, unk08, unk0C, unk10, unk14;
    hkpEntity* m_pEntityA;
    hkpEntity* m_pEntityB;
    unsigned int unk20, unk24, unk28, unk2C;
    hkVector4 m_kPivotInA;
    hkVector4 m_kPivotInB;
    float m_fSpringRestLength;
};

// Transforms world-space pivots into local entity space, then stores their 3D distance as the spring rest length.
// @fnv 0x00d4d390
void hkpStiffSpringWrapperD4D3::UpdatePivotsAndRestLength(const hkVector4& kPivotAW, const hkVector4& kPivotBW)
{
    hkpEntity* pkA = m_pEntityA;
    hkpEntity* pkB = m_pEntityB;
    m_kPivotInA.hkVector4_setTransformedInversePos(pkA->m_pMotionState.m_kMotionState.m_kMotionTransform, kPivotAW);
    m_kPivotInB.hkVector4_setTransformedInversePos(pkB->m_pMotionState.m_kMotionState.m_kMotionTransform, kPivotBW);
    hkVector4 kDiff;
    kDiff.setSub4(kPivotAW, kPivotBW);
    m_fSpringRestLength = kDiff.length3();
}

namespace fnv_00d4d410 {

class hkpStiffSpringWrapperD4D41 : public hkBaseObject
{
  public:
    void SetPivots(const hkVector4& kPivotA, const hkVector4& kPivotB);

    unsigned int unk04, unk08, unk0C, unk10, unk14;
    hkpEntity* m_pEntityA;
    hkpEntity* m_pEntityB;
    unsigned int unk20, unk24, unk28, unk2C;
    hkVector4 m_kPivotInA;
    hkVector4 m_kPivotInB;
    float m_fSpringRestLength;
};

// Stores the given pivot vectors and computes the spring rest length from the world-space distance between the two pivots.
// @fnv 0x00d4d410
void hkpStiffSpringWrapperD4D41::SetPivots(const hkVector4& kPivotA, const hkVector4& kPivotB)
{
    hkpEntity* pkA = m_pEntityA;
    hkpEntity* pkB = m_pEntityB;
    m_kPivotInA = kPivotA;
    m_kPivotInB = kPivotB;
    hkVector4 kPivotAW;
    kPivotAW.setTransformedPos_00c7f640(pkA->m_pMotionState.m_kMotionState.m_kMotionTransform, kPivotA);
    hkVector4 kPivotBW;
    kPivotBW.setTransformedPos_00c7f640(pkB->m_pMotionState.m_kMotionState.m_kMotionTransform, kPivotB);
    hkVector4 kDiff;
    kDiff.setSub4(kPivotAW, kPivotBW);
    m_fSpringRestLength = kDiff.length3();
}
}  // namespace fnv_00d4d410

namespace fnv_00d4d4a0 {

struct hkpEntityPairD4A0
{
    void* m_pEntityA;
    void* m_pEntityB;
};

struct hkpCloneArgD4A0
{
    hkpEntityPairD4A0* m_kActorEntries;
    int m_type;
};

struct S00d4d4a0_Obj
{
    static void* operator new(unsigned int size)
    {
        S00d4d4a0_Obj* memory = reinterpret_cast<S00d4d4a0_Obj*>(hkMemoryRouter::getInstance().heap().blockAlloc(size));
        memory->m_usMemSizeAndFlags = static_cast<unsigned short>(size);
        return memory;
    }

    S00d4d4a0_Obj* FUN_00d4d340(void* entityA, void* entityB, void* data);

    S00d4d4a0_Obj* hkpSpringAction_clone(const hkpCloneArgD4A0& argA, const hkpCloneArgD4A0& argB) const;

    unsigned int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* unk08;
    void* unk0C;
    void* m_ulUserData;
    void* unk14;
    void* m_pEntityA;
    void* m_pEntityB;
    hkVector4 m_kLastForce;
    hkVector4 m_kPivotInA;
    hkVector4 m_kPivotInB;
    float m_fRestLength;
    float m_fSpringStrength;
    float m_fMotorDamping;
    unsigned char m_bSpringEnabled;
    unsigned char m_bElastic;
    unsigned short unk5E;
};

// Returns null unless argA.m_type is 2 and argB.m_type is 0; else builds a copy on argA's entity pair and copies pivots, rest length, spring, damping and flags.
// @fnv 0x00d4d4a0
// src: HAVOK_SRC 0x00d4d4a0
S00d4d4a0_Obj* S00d4d4a0_Obj::hkpSpringAction_clone(const hkpCloneArgD4A0& argA, const hkpCloneArgD4A0& argB) const
{
    if (argA.m_type != 2)
        return 0;

    if (argB.m_type != 0)
        return 0;

    S00d4d4a0_Obj* clone = new S00d4d4a0_Obj;

    clone = clone->FUN_00d4d340(argA.m_kActorEntries->m_pEntityA, argA.m_kActorEntries->m_pEntityB, m_ulUserData);

    clone->m_kPivotInA = m_kPivotInA;
    clone->m_kPivotInB = m_kPivotInB;
    clone->m_fRestLength = m_fRestLength;
    clone->m_fSpringStrength = m_fSpringStrength;
    clone->m_fMotorDamping = m_fMotorDamping;
    clone->m_bSpringEnabled = m_bSpringEnabled;
    clone->m_bElastic = m_bElastic;

    return clone;
}
}  // namespace fnv_00d4d4a0
