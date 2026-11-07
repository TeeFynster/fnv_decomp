
// src/fallout/ai/combat/grenadeprojectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/combat/grenadeprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/grenadeprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/grenadeprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "../../../../include/ActorValueOwner.h"
#include "../../../../include/BSSimpleList.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/bhkCollisionObject.h"
#include "../../../../include/Projectile.h"

#include <xmmintrin.h>
extern const float g_fBaseAlpha9B4;

// 0x004b4d50 sets a Havok four-vector and 0x009b4670 multiplies its SSE lanes; this is velocity, not NiColorA.
class ProjectileVelocityVector
{
  public:
    ProjectileVelocityVector();
    void Set(float fX, float fY, float fZ, float fW);
    void Multiply(void* pvOther);
    __m128 m_vComponents;
};

class GameModeState9B4
{
  public:
    int GetMode();
};
extern GameModeState9B4 g_kGameMode9B4;

extern PlayerCharacter* g_pkPlayer9B4;

// 0x00517630 queries a bhkRigidBody motion type; 0x00560d80/0x00561690 read/write its velocity, not NiAVObject material.
class RigidBodyMotionAccess
{
  public:
    int GetMotionType();
    void* GetLinearVelocity();
    void SetLinearVelocity(ProjectileVelocityVector* pkVelocity);
};

bhkCollisionObject* __cdecl FUN_0043b610(void* pvRoot);
bool __cdecl bhkRigidBody_IsMotionTypeDynamic(int* piFlags);
bool __cdecl CanProjectileHit(TESObjectREFR* pkTarget, int iArg, void* pvActor, void* pvProcess);
void __cdecl TESHavokUtilities_AddVelocity(void* pvRoot, const void* pvPos, int iFlag);
extern const float g_kZeroPoint9B4[3];

// 0x009b4460 calls Projectile::OnCollision (0x009bf5a0), tests impacts at +0x88 and sets the impact flag at +0x90.
class GrenadeImpactState
{
  public:
    virtual void va000();
    virtual void va004();
    virtual void va008();
    virtual void va00c();
    virtual void va010();
    virtual void va014();
    virtual void va018();
    virtual void va01c();
    virtual void va020();
    virtual void va024();
    virtual void va028();
    virtual void va02c();
    virtual void va030();
    virtual void va034();
    virtual void va038();
    virtual void va03c();
    virtual void va040();
    virtual void va044();
    virtual void va048();
    virtual void va04c();
    virtual void va050();
    virtual void va054();
    virtual void va058();
    virtual void va05c();
    virtual void va060();
    virtual void va064();
    virtual void va068();
    virtual void va06c();
    virtual void va070();
    virtual void va074();
    virtual void va078();
    virtual void va07c();
    virtual void va080();
    virtual void va084();
    virtual void va088();
    virtual void va08c();
    virtual void va090();
    virtual void va094();
    virtual void va098();
    virtual void va09c();
    virtual void va0a0();
    virtual void va0a4();
    virtual void va0a8();
    virtual void va0ac();
    virtual void va0b0();
    virtual void va0b4();
    virtual void va0b8();
    virtual void va0bc();
    virtual void va0c0();
    virtual void va0c4();
    virtual void va0c8();
    virtual void va0cc();
    virtual void va0d0();
    virtual void va0d4();
    virtual void va0d8();
    virtual void va0dc();
    virtual void va0e0();
    virtual void va0e4();
    virtual void va0e8();
    virtual void va0ec();
    virtual void va0f0();
    virtual void va0f4();
    virtual void va0f8();
    virtual void va0fc();
    virtual void va100();
    virtual void va104();
    virtual void va108();
    virtual void va10c();
    virtual void va110();
    virtual void va114();
    virtual void va118();
    virtual void va11c();
    virtual void va120();
    virtual void va124();
    virtual void va128();
    virtual void va12c();
    virtual void va130();
    virtual void va134();
    virtual void va138();
    virtual void va13c();
    virtual void va140();
    virtual void va144();
    virtual void va148();
    virtual void va14c();
    virtual void va150();
    virtual void va154();
    virtual void va158();
    virtual void va15c();
    virtual void va160();
    virtual void va164();
    virtual void va168();
    virtual void va16c();
    virtual void va170();
    virtual void va174();
    virtual void va178();
    virtual void va17c();
    virtual void va180();
    virtual void va184();
    virtual void va188();
    virtual void va18c();
    virtual void va190();
    virtual void va194();
    virtual void va198();
    virtual void va19c();
    virtual void va1a0();
    virtual void va1a4();
    virtual void va1a8();
    virtual void va1ac();
    virtual void va1b0();
    virtual void va1b4();
    virtual void va1b8();
    virtual void va1bc();
    virtual void va1c0();
    virtual void va1c4();
    virtual void va1c8();
    virtual void va1cc();
    virtual void* Get3D();
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    BSSimpleList<Projectile::ImpactData*> m_kImpacts;
    bool m_bHasImpactData;

    void* GetProjectileBase();
    bool ProcessCollision(TESObjectREFR* pkTarget, int a2, int a3, int a4, int a5, int a6);
    float FUN_00885bd0();
    void Object_ProcessAndReturnValue_009b4740();
    bool GrenadeProjectile_AddImpact(TESObjectREFR* pkTarget, int a2, int a3, int a4, int a5, int a6);
};

// @fnv 0x009b4460
// src: XBOX_PDB 0x009b4460
bool GrenadeImpactState::GrenadeProjectile_AddImpact(TESObjectREFR* pkTarget, int a2, int a3, int a4, int a5, int a6)
{
    if (g_kGameMode9B4.GetMode() == 4)
    {
        bhkCollisionObject* pkNode = FUN_0043b610(Get3D());
        if (pkNode)
        {
            RigidBodyMotionAccess* pkObject = reinterpret_cast<RigidBodyMotionAccess*>(pkNode->bhkNiCollisionObject_GetWorldObject());
            if (pkObject)
            {
                int iFlags = pkObject->GetMotionType();
                if (bhkRigidBody_IsMotionTypeDynamic(&iFlags))
                {
                    ProjectileVelocityVector kVelocity;
                    float fAlpha = g_fBaseAlpha9B4;
                    fAlpha = (100 - g_pkPlayer9B4->GetActorValue(static_cast<ActorValue::Index>(0x23))) / 100.0 * fAlpha;
                    fAlpha = fAlpha + (double)0.1f;
                    kVelocity.Set(fAlpha, fAlpha, fAlpha, 0.0f);
                    kVelocity.Multiply(pkObject->GetLinearVelocity());
                    pkObject->SetLinearVelocity(&kVelocity);
                }
            }
        }
    }
    if (m_kImpacts.IsEmpty() && CanProjectileHit(pkTarget, a4, this, GetProjectileBase()) &&
        ProcessCollision(pkTarget, a2, a3, a4, a5, a6))
    {
        if (pkTarget && pkTarget->IsActor())
        {
            TESHavokUtilities_AddVelocity(Get3D(), g_kZeroPoint9B4, 1);
        }
        else if (FUN_00885bd0() == 0.0)
        {
            Object_ProcessAndReturnValue_009b4740();
            m_bHasImpactData = true;
        }
        return true;
    }
    return false;
}

// hkVector4::mul4(const hkVector4&): component-wise multiply in place.
struct hkVector4Mul
{
    __m128 m_vComponents;
    void MultiplyComponentsInPlace(const hkVector4Mul& a);
};
// @fnv 0x009b4670
// src: GUESS 0x009b4670 (confidence: high)
void hkVector4Mul::MultiplyComponentsInPlace(const hkVector4Mul& a)
{
    m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents);
}
