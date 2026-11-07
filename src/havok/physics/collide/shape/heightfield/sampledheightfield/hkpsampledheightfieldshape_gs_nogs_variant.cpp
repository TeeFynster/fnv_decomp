#include <xmmintrin.h>
typedef ::__m128 LocalM128;

// src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
typedef ::__m128 LocalM128;
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkRotation.h"
using ::_mm_load_ps1;
extern float DAT_01012068;
extern double DAT_01012070;
struct Cls_00d24670 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30();
    virtual float getH(int x, int y);
    virtual void getFlip(bool& flip);
    void UpdateState_00d24670(int x, int y, float fx, float fy, LocalM128* nrm, float* height, int* flag);
};
struct hkInfoD260 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fScalar;
};
class hkCollectorD260 {
public:
    hkCollectorD260(hkInfoD260* info) : m_fScalar(info->m_fScalar), m_bHasHit(false), m_info(info) {}
    virtual void AddHit(void* hit);

    float m_fScalar;
    bool m_bHasHit;
    hkInfoD260* m_info;
};
struct FUN_00d24b50_Obj {
    void __thiscall hkpSampledHeightFieldShape_castRayInternal(void* object, int flags, hkBool flag2, float f, hkCollectorD260* collector);
};
class hkShapeD260 : public FUN_00d24b50_Obj {
public:
    hkBool __thiscall hkpSampledHeightFieldShape_castRayImpl(void* object, hkInfoD260* info);
};
struct S00d261b0_Elem {
    LocalM128 v00;
    float f10;
    int i14;
    int unk18;
    int unk1c;
    int m_slots[8];
    int m_idx40;
};
struct S00d261b0_cls {
    int unk00;
    float f04;
    unsigned char b08;
    S00d261b0_Elem* p0c;
    void UpdateMinValue(int a0, int a1);
};

using ::_mm_shuffle_ps;
using ::_mm_mul_ps;
using ::_mm_add_ps;

struct Input_d26310 {
    LocalM128 m_kLightVector;
    LocalM128 m_kExtra;
};
struct Context_d26310 {
    int unk00;
    int unk04;
    hkRotation* m_pRotation;
};
struct Child_d26310 {
    virtual void query(Context_d26310* pkContext, const Input_d26310* pkInput);
};
struct FUN_00d26310_cls {
    int unk00;
    int unk04;
    Child_d26310* m_pChildObject;
    void ComputeValues_00d26310(Context_d26310* pkContext, const Input_d26310* pkInput);
};
// @fnv 0x00d26310
// src: GUESS 0x00d26310 (confidence: low)
void FUN_00d26310_cls::ComputeValues_00d26310(Context_d26310* pkContext, const Input_d26310* pkInput)
{
    Input_d26310 kLocal(*pkInput);
    const LocalM128& kWorldPosition = pkInput->m_kLightVector;
    const hkRotation& r = *pkContext->m_pRotation;
    LocalM128 kRes = _mm_mul_ps(_mm_shuffle_ps(kWorldPosition, kWorldPosition, 0x55), r.m_kColumn1.m_vComponents);
    kRes = _mm_add_ps(kRes, _mm_mul_ps(_mm_shuffle_ps(kWorldPosition, kWorldPosition, 0), r.m_kColumn0.m_vComponents));
    kRes = _mm_add_ps(kRes, _mm_mul_ps(_mm_shuffle_ps(kWorldPosition, kWorldPosition, 0xaa), r.m_kColumn2.m_vComponents));
    kLocal.m_kLightVector = kRes;
    m_pChildObject->query(pkContext, &kLocal);
}
