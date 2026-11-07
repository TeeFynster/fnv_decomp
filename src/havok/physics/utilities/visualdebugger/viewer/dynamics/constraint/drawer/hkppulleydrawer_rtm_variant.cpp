#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppulleydrawer_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppulleydrawer.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppulleydrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppulleydrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Preserve the original SIMD representation; VC9's CRT byte lanes introduce /GS cookies.
#define _INCLUDED_MM2
// Exe 0x00de6550 FUN_00de6550: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_load_ps1(const float*);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);

#include "../../../../../../../../../include/hkDebugDisplayHandler.h"
#include "../../../../../../../../../include/hkRotation.h"
#include "../../../../../../../../../include/hkTransform.h"
#include "../../../../../../../../../include/hkpConstraintInstance.h"
#include "../../../../../../../../../include/hkpEntity.h"
#include "../../../../../../../../../include/hkpPulleyConstraintData.h"

extern double DAT_01011598;

inline hkVector4::hkVector4(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}

inline hkTransform::hkTransform()
{
}

inline hkRotation& hkTransform::getRotation()
{
    return *reinterpret_cast<hkRotation*>(&m_row0);
}

inline void hkVector4::set(hkReal x, hkReal y, hkReal z, hkReal w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}

inline void hkVector4::setMul4(hkReal r, const hkVector4& v)
{
    m_vComponents = _mm_mul_ps(_mm_load_ps1(&r), v.m_vComponents);
}

inline void hkVector4::setMul4_b(hkReal r, const hkVector4& v)
{
    LocalM128 s = _mm_load_ss(&r);
    s = _mm_shuffle_ps(s, s, 0);
    m_vComponents = _mm_mul_ps(s, v.m_vComponents);
}

inline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}

inline void hkVector4::add4(const hkVector4& a)
{
    m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
}

struct VecAddress
{
    const hkVector4* p;
    VecAddress(const hkVector4* a) : p(a)
    {}
};

inline void displayLine(hkDebugDisplayHandler* handler, const hkVector4& start, VecAddress end,
                        unsigned int color, int id, int tag)
{
    handler->DisplayLine(start, *end.p, color, id, tag);
}

struct DebugDisplayHandlerHolder
{
    void hkpPrimitiveDrawer_setDisplayHandler(hkDebugDisplayHandler* displayHandler);
};

template <class T> inline T hkMax2(T a, T b)
{
    return a > b ? a : b;
}

struct ConstraintVisualizer
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    hkVector4 m_vVectorAtOffset40;
    hkVector4 m_vVectorAtOffset50;
    hkVector4 unk60;
    hkVector4 unk70;
    hkVector4 unk80;
    hkVector4 unk90;
    hkVector4 unka0;
    hkVector4 unkb0;
    DebugDisplayHandlerHolder m_kDisplayGeometry;

    void hkpConstraintDrawer_updateCommonParameters(hkpConstraintInstance* constraint, hkTransform& refLocalToWorld, hkTransform& attLocalToWorld);
    void hkpConstraintDrawer_drawPivots(int id, int tag);
    void hkpConstraintDrawer_drawBodyFrames(int id, int tag);
    void ProcessEntries_00de6550(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler, int id, int tag);
};

// @fnv 0x00de6550
// src: GUESS 0x00de6550 (confidence: low)
void ConstraintVisualizer::ProcessEntries_00de6550(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler, int id,
                                   int tag)
{
    hkpPulleyConstraintData* pulley = static_cast<hkpPulleyConstraintData*>(constraint->m_data);
    m_kDisplayGeometry.hkpPrimitiveDrawer_setDisplayHandler(displayHandler);
    {
        hkTransform refLocalToWorld;
        hkTransform attLocalToWorld;
        hkpConstraintDrawer_updateCommonParameters(constraint, refLocalToWorld, attLocalToWorld);
        m_vVectorAtOffset50.setTransformedPos_00c7f640(refLocalToWorld, pulley->m_kTranslationB);
        m_vVectorAtOffset40.setTransformedPos_00c7f640(attLocalToWorld, pulley->m_kTranslationA);
    }
    hkpConstraintDrawer_drawPivots(id, tag);
    hkpConstraintDrawer_drawBodyFrames(id, tag);

    displayLine(displayHandler, pulley->m_kFixedPivotA, VecAddress(&pulley->m_kFixedPivotB), 0xffc0c0c0, id, tag);
    displayLine(displayHandler, m_vVectorAtOffset40, VecAddress(&pulley->m_kFixedPivotA), 0xffffffff, id, tag);

    int numRopes = int(hkMax2(pulley->m_fRopeLength, 1.0f));
    hkVector4 offset(0.0f, 0.0f, 0.0f, 0.0f);
    offset.set(0.07f, 0.0f, 0.0f, 0.0f);
    offset.hkVector4_setRotatedDir(constraint->m_kActorEntries[1]->m_pMotionState.m_kMotionState.m_kMotionTransform.getRotation(), offset);
    hkVector4 start(0.0f, 0.0f, 0.0f, 0.0f);
    start.setMul4_b(hkReal((numRopes - 1) * DAT_01011598), offset);
    for (int i = 0; i < numRopes; i++)
    {
        hkVector4 delta(0.0f, 0.0f, 0.0f, 0.0f);
        delta.setMul4(hkReal(i), offset);
        delta.add4(start);
        hkVector4 ropeStart(0.0f, 0.0f, 0.0f, 0.0f);
        ropeStart.setAdd4(m_vVectorAtOffset50, delta);
        hkVector4 ropeEnd(0.0f, 0.0f, 0.0f, 0.0f);
        ropeEnd.setAdd4(delta, pulley->m_kFixedPivotB);
        displayLine(displayHandler, ropeStart, VecAddress(&ropeEnd), 0xffffffff, id, tag);
    }
}
