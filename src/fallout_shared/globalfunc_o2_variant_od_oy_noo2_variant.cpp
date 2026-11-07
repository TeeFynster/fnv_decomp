
// src/fallout_shared/globalfunc_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF (unit src/fallout_shared/globalfunc_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/globalfunc_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/globalfunc.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "../../include/NiD3DPass.h"
#include "../../include/bhkRefObject.h"

#include <xmmintrin.h>
class S004b4db0_SimdReal
{
  public:
    operator float() const;  // FUN_004586d0
    __m128 m_vValue;
};

class S004b4db0_Vector4
{
  public:
    S004b4db0_SimdReal getComponent(int i) const;  // FUN_00458700
    __m128 m_vComponents;
};

class S004b4db0_Quaternion
{
  public:
    S004b4db0_Quaternion& SetQuaternionComponentsFromVector(const S004b4db0_Vector4& v);
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;
};

// @fnv 0x004b4db0
// src: GUESS 0x004b4db0 (confidence: high)
S004b4db0_Quaternion& S004b4db0_Quaternion::SetQuaternionComponentsFromVector(const S004b4db0_Vector4& v)
{
    m_fVectorY = v.getComponent(0);
    m_fVectorZ = v.getComponent(1);
    m_fScalarPart = v.getComponent(2);
    m_fVectorX = v.getComponent(3);
    return *this;
}
