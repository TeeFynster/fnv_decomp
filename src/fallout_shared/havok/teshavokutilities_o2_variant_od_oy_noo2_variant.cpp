
// src/fallout_shared/havok/teshavokutilities_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout_shared/havok/teshavokutilities_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/havok/teshavokutilities_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/havok/teshavokutilities.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout_shared/havok/teshavokutilities.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/teshavokutilities.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
// PodPoint3: unit-local copy of the former shared stand-in Point3. Same layout as NiPoint3 but constructor-free (an aggregate under VC9): with NiPoint3, 0x0062bfb0 does not match (POD construction/return; NiPoint3's user constructors change the code).
#include <stddef.h>
class PodPoint3
{
public:
    float x;
    float y;
    float z;

    // Legacy compilers require an aggregate for brace initialization.
#if !defined(_MSC_VER) || _MSC_VER >= 1800
    PodPoint3()
    {}
    PodPoint3(float fX, float fY, float fZ)
        : x(fX), y(fY), z(fZ)
    {}
#endif

    PodPoint3 operator+(const PodPoint3& other) const;
    PodPoint3 operator-(const PodPoint3& other) const;
    PodPoint3 operator-() const;
    PodPoint3 operator*(float scalar) const;
    float operator*(const PodPoint3& other) const;
    PodPoint3& operator+=(const PodPoint3& other);
    friend PodPoint3 operator*(float scalar, const PodPoint3& point);

    float DotPart(float value, const PodPoint3& point) const;
    float DotProduct(const PodPoint3& point) const;
    double DotProduct(const PodPoint3& point);
    float Length() const;

    PodPoint3& ScaleComponents(float scalar);
    PodPoint3 FUN_00439e90(const PodPoint3& shift) const;
    PodPoint3* FUN_00439e90(PodPoint3* output, const PodPoint3* other) const;
    PodPoint3 SubtractIntoVector(const PodPoint3& other) const;
    void SubtractIntoVector();
    PodPoint3 FUN_004b3800(const PodPoint3& axis) const;
    void Unitize_004a0c10();
    float FUN_00457910();
    float FUN_00457990() const;
    double FUN_004a7290();
    PodPoint3* FUN_006815c0();
    PodPoint3* SetComponents(float x, float y, float z);
    void FUN_0043d410(float x, int y, int z);
    char* GetViewerString_00a59af0(const char* text);

    static void* operator new[](size_t size);
    static void operator delete[](void* memory);
    static const PodPoint3 ZERO;
};
#include "../../../include/NiTransform.h"
struct Aabb
{
    __m128 minimum, maximum;
    Aabb* FUN_00437c10();
};
struct HavokTransform
{
    __m128 rotation0, rotation1, rotation2, translation;
    HavokTransform* FUN_0056ded0();
};
struct Node
{
    const NiTransform* NiAVObject_GetWorldRotate() const;
};
struct WorldObject
{
    void GetAabb(Aabb* bounds);
    void bhkRigidBody_GetTransform(HavokTransform* transform);
};
struct CollisionObject
{
    WorldObject* bhkNiCollisionObject_GetWorldObject();
    Node* FUN_0044ddc0();
};
struct RTTI;
extern RTTI g_012683c8;
extern PodPoint3 DAT_011f426c;
CollisionObject* FindFirstCollisionObject(Node*);
void FUN_00458620(PodPoint3* out, const __m128* havokPoint);
PodPoint3* FUN_004a3760(PodPoint3* out, float scale, const PodPoint3* point);
float FUN_00476b70(float minimum, float maximum);
bool NiObject_IsKindOf(const RTTI*, WorldObject*);
NiTransform* HK2NI_00624ad0(NiTransform* out, const HavokTransform* havok);
// @fnv 0x0062bfb0
// src: COMMUNITY 0x0062bfb0
PodPoint3* TESHavokUtilities_GetLocalPointWithinCollision(PodPoint3* out, Node* node)
{
    PodPoint3 chosen = DAT_011f426c;
    CollisionObject* collision = FindFirstCollisionObject(node);
    if (collision)
    {
        WorldObject* body = collision->bhkNiCollisionObject_GetWorldObject();
        if (body)
        {
            Aabb bounds;
            bounds.FUN_00437c10();
            body->GetAabb(&bounds);
            PodPoint3 minimum;
            minimum.FUN_006815c0();
            FUN_00458620(&minimum, &bounds.minimum);
            PodPoint3 maximum;
            maximum.FUN_006815c0();
            FUN_00458620(&maximum, &bounds.maximum);
            PodPoint3 lower, upper, minTermA, maxTermA, minTermB, maxTermB;
            FUN_004a3760(&maxTermA, .55f, &maximum)->FUN_00439e90(&upper, FUN_004a3760(&minTermA, .45f, &minimum));
            FUN_004a3760(&maxTermB, .45f, &maximum)->FUN_00439e90(&lower, FUN_004a3760(&minTermB, .55f, &minimum));
            PodPoint3 random;
            chosen = *random.SetComponents(FUN_00476b70(lower.x, upper.x), FUN_00476b70(lower.y, upper.y),
                                          FUN_00476b70(lower.z, upper.z));
            if (NiObject_IsKindOf(&g_012683c8, body) || collision->FUN_0044ddc0() != node)
            {
                HavokTransform bodyHavok;
                bodyHavok.FUN_0056ded0();
                body->bhkRigidBody_GetTransform(&bodyHavok);
                NiTransform bodyWorld;
                HK2NI_00624ad0(&bodyWorld, &bodyHavok);
                bodyWorld.m_fScale = 1.0f;
                NiTransform inverse;
                node->NiAVObject_GetWorldRotate()->FUN_004b4880(inverse);
                PodPoint3 transformed;
                chosen = *(PodPoint3*)(inverse * bodyWorld).ComputeValue_00524c40((NiPoint3*)&transformed, (const NiPoint3&)chosen);
            }
        }
    }
    *out = chosen;
    return out;
}
