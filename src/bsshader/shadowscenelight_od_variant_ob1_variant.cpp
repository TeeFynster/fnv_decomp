
// src/bsshader/shadowscenelight_od_variant_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/bsshader/shadowscenelight_od_variant.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/bsshader/shadowscenelight_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/shadowscenelight.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "../../include/NiPoint3.h"
#include "../../include/NiFrustumPlanes.h"
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" const NiPoint3 NiPoint3_ZERO;
extern const float runtimeFloatSettingDefault100;

class FUN_00c49fe0
{
  public:
    FUN_00c49fe0();
    ~FUN_00c49fe0();
    void FUN_00c4a070(int a, int b);
    void* m_p0;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
};
class FUN_00c4a1b0
{
  public:
    FUN_00c4a1b0();
    ~FUN_00c4a1b0();
    void FUN_00c4a1e0(int a, int b);
    void* m_p0;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
};
class FUN_00c47660
{
  public:
    FUN_00c47660();
    bool m_b0;
    FUN_00c49fe0 m_kList4;
    FUN_00c4a1b0 m_kList14;
    int m_24;
    int m_28;
    int m_2c;
    NiFrustumPlanes m_kFrustumPlanes;
    NiPoint3 m_kPoint;
    bool m_bA0;
};
// @fnv 0x00c47660
FUN_00c47660::FUN_00c47660()
{
    NiPoint3 kA;
    NiPoint3 kB;
    NiPoint3 kC;
    m_24 = 0;
    m_28 = 0;
    m_kPoint = NiPoint3::ZERO;
    m_kList4.FUN_00c4a070(4, 1);
    m_kList14.FUN_00c4a1e0(10, 1);
    m_b0 = false;
    m_2c = 0;
    m_bA0 = false;
}
