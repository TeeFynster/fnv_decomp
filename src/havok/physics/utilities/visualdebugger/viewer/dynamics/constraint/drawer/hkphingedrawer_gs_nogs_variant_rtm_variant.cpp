
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingedrawer_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingedrawer_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingedrawer_gs_nogs_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingedrawer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingedrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingedrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "../../../../../../../../../include/hkSimdReal.h"

inline hkSimdReal::hkSimdReal(float x)
{
    m_vValue = _mm_load_ss(&x);
}

__forceinline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}

typedef const hkSimdReal& hkSimdRealParameter;

struct hkTransformD;
struct hkRotationD;

struct hkVector4D
{
    __m128 m_vComponents;

    void setTransformedPosD(const hkTransformD& t, const hkVector4D& p);
    void setRotatedDirD(const hkRotationD& r, const hkVector4D& d);
    __forceinline void setAddMul4(const hkVector4D& a, const hkVector4D& b, hkSimdRealParameter r)
    {
        m_vComponents = _mm_add_ps(_mm_mul_ps(r.broadcast(), b.m_vComponents), a.m_vComponents);
    }
};

// local form of hkRotation: 0x00de7f20 needs implicit rotation construction; shared form gives 376 bytes vs exe 355.
struct hkRotationD
{
    hkVector4D m_kColumn0;
    hkVector4D m_kColumn1;
    hkVector4D m_kColumn2;
};

struct hkTransformD
{
    hkRotationD m_rotation;
    hkVector4D m_vTranslation;
};

struct hkpSetLocalTransformsConstraintAtomD
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkTransformD m_kBodyALocalFrame;
    hkTransformD m_kBodyBLocalFrame;
};

struct hkpHingeConstraintDataD
{
    hkpSetLocalTransformsConstraintAtomD m_kBridgeAtoms;
};

struct hkpConstraintInstanceD
{
    int unk00;
    int unk04;
    int unk08;
    hkpHingeConstraintDataD* m_data;
};

struct hkDebugDisplayHandlerD
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void DisplayLine(const hkVector4D& start, const hkVector4D& end, unsigned int color, int id, int tag);
};

struct DisplayHolderD
{
    void setHandlerD(hkDebugDisplayHandlerD* h);
};

unsigned int __cdecl hkColorRgbD(float r, float g, float b, float a);

struct Drawer
{
    float m_fRestLength;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    int unk14;
    int unk18;
    float m_vScale;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    hkVector4D m_posA;
    hkVector4D m_posB;
    hkRotationD m_rotA;
    hkRotationD m_rotB;
    DisplayHolderD m_pDisplayHandler;

    void getConstraintTransformsD(const hkpConstraintInstanceD* constraint, hkTransformD& transformB,
                                  hkTransformD& transformA);
    void drawFramesD(int id, int tag);
    void drawPivotsD(int id, int tag);

    void UpdateFields_00de7f20(const hkpConstraintInstanceD* constraint, hkDebugDisplayHandlerD* displayHandler, int id,
                      int tag);
};

// @fnv 0x00de7f20
// src: GUESS 0x00de7f20 (confidence: low)
void Drawer::UpdateFields_00de7f20(const hkpConstraintInstanceD* constraint, hkDebugDisplayHandlerD* displayHandler, int id,
                          int tag)
{
    hkpHingeConstraintDataD* data = constraint->m_data;
    m_pDisplayHandler.setHandlerD(displayHandler);

    hkTransformD transformA;
    hkTransformD transformB;
    getConstraintTransformsD(constraint, transformB, transformA);

    m_posB.setTransformedPosD(transformB, data->m_kBridgeAtoms.m_kBodyBLocalFrame.m_vTranslation);
    m_posA.setTransformedPosD(transformA, data->m_kBridgeAtoms.m_kBodyALocalFrame.m_vTranslation);

    drawFramesD(id, tag);
    drawPivotsD(id, tag);

    displayHandler->DisplayLine(m_posA, m_posB, 0xffff0000, id, tag);

    hkVector4D axis;
    axis.setRotatedDirD(m_rotB, data->m_kBridgeAtoms.m_kBodyBLocalFrame.m_rotation.m_kColumn0);

    float len = m_vScale * m_fRestLength;

    hkVector4D p1;
    p1.setAddMul4(m_posB, axis, (float)(0.75 * len));

    hkVector4D p0;
    p0.setAddMul4(m_posB, axis, (float)(-0.75 * len));

    displayHandler->DisplayLine(p0, p1, hkColorRgbD(0.0f, 0.5f, 1.0f, 1.0f), id, tag);
}
