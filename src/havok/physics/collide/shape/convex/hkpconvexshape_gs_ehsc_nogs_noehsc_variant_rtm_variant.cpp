
// src/havok/physics/collide/shape/convex/hkpconvexshape_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/shape/convex/hkpconvexshape_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/shape/convex/hkpconvexshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/convex/hkpconvexshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/shape/convex/hkpconvexshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/hkpconvexshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpShape.h"
#include "../../../../../../include/hkpConvexShape.h"
#include "../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../include/hkpSingleShapeContainer.h"

#include <xmmintrin.h>
#include <emmintrin.h>

extern const hkTransform DAT_01268370;
extern float DAT_01016248;

struct CenterVector
{
    __m128 quad;
    void SetAdd(const CenterVector& a, const CenterVector& b)
    {
        quad = _mm_add_ps(a.quad, b.quad);
    }
    void Scale(const float& scale)
    {
        __m128 scalar = _mm_load_ss(&scale);
        __m128 factor = _mm_shuffle_ps(scalar, scalar, 0);
        quad = _mm_mul_ps(factor, quad);
    }
};
struct __declspec(align(16)) CenterAabb
{
    CenterVector m_kMinimumCorner;
    CenterVector m_kMaximumCorner;
};

class DummyClass
{
  public:
    virtual ~DummyClass();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void getAabb(const hkTransform& localToWorld, float tolerance, CenterAabb& out) const;
    void hkpConvexTransformShapeBase_getCentreImpl(CenterVector* centreOut);
};

// @fnv 0x00c9e250
// src: HAVOK_SRC 0x00c9e250
void DummyClass::hkpConvexTransformShapeBase_getCentreImpl(CenterVector* centreOut)
{
    CenterAabb aabb;
    getAabb(DAT_01268370, 0.0f, aabb);
    centreOut->SetAdd(aabb.m_kMaximumCorner, aabb.m_kMinimumCorner);
    centreOut->Scale(DAT_01016248);
}
