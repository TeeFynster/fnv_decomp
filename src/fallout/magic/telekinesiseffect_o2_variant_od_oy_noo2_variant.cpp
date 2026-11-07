
// src/fallout/magic/telekinesiseffect_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/magic/telekinesiseffect_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/magic/telekinesiseffect_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/telekinesiseffect.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/magic/telekinesiseffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/telekinesiseffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../include/TelekinesisEffect.h"

void __cdecl _Deallocate(void*);
struct FUN_0082aab0_shell
{
    void SetField644(float value);
};
struct FUN_0082af40_shell
{
    float fTelekinesisStrength;  // +0x644
    float GetTelekinesisStrength();
};
struct FUN_008df040_shell
{
    unsigned char __thiscall FUN_008df040();
};
extern FUN_008df040_shell* g_TESSaveLoadGame;
void* __cdecl Interface_GetTelekinesisREFR();
struct Flt
{
    operator unsigned int();
};
struct FUN_0082aa90_shell
{
    unsigned int GetFloatAsUInt();
};
void* __cdecl bhkEntity_Getbhk(void const*);
struct FUN_0082aeb0_shell
{
    void* __thiscall bhkUnaryAction_GethkRigidBody();
    void* __thiscall bhkUnaryAction_GetRigidBody();
};

#include <xmmintrin.h>
class NiPoint3T
{
  public:
    float x, y, z;
    NiPoint3T();
    NiPoint3T operator*(float fScalar) const;
};
extern const NiPoint3T g_kZeroPointT;

class NiMatrix3T
{
  public:
    float m_afEntries[3][3];
    NiMatrix3T();
    void SetRotationFromEulerXYZ(float fXAngle, float fYAngle, float fZAngle);
    void GetCol(unsigned int uiCol, NiPoint3T& kCol) const;
};

class hkVector4T
{
  public:
    __m128 m_vComponents;
    hkVector4T();
    void mul4(const class hkSimdRealT& kScale);
};

class hkSimdRealT
{
  public:
    __m128 m_vValue;
    hkSimdRealT(float fValue);
};

void __cdecl NI2HK(hkVector4T* pkOut, const NiPoint3T* pkIn);

class TelekinesisTargetController
{
  public:
    void Update();
};

class TelekinesisTarget
{
  public:
    float GetMass();
    TelekinesisTargetController* SetLinearVelocity(const hkVector4T& kMotionVelocity);
    void SetVelocity(const NiPoint3T& kMotionVelocity);
};

class PlayerCameraT
{
  public:
    FUN_0082aeb0_shell* GetGrab();
    void ReleaseGrab();
    const NiPoint3T& GetRotation();
};
extern PlayerCameraT* g_pkPlayerCameraT;

class GameSettingTableT
{
  public:
    float& GetValue();
};
extern GameSettingTableT g_kTelekinesisDistanceT;

// @fnv 0x0082afa0
// src: XBOX_PDB 0x0082afa0
void TelekinesisEffect::RemoveSpring()
{
    if (g_pkPlayerCameraT->GetGrab())
    {
        void* pvGrabbed = g_pkPlayerCameraT->GetGrab()->bhkUnaryAction_GethkRigidBody();
        g_pkPlayerCameraT->ReleaseGrab();
        if (pvGrabbed)
        {
            TelekinesisTarget* pkTarget = (TelekinesisTarget*)bhkEntity_Getbhk(pvGrabbed);
            if (m_bHolding)
            {
                NiPoint3T kForward;
                NiMatrix3T kRotationBasis;
                NiPoint3T kAngles = g_pkPlayerCameraT->GetRotation();
                kRotationBasis.SetRotationFromEulerXYZ(kAngles.z, kAngles.x, kAngles.y);
                kRotationBasis.GetCol(1, kForward);
                NiPoint3T kIntersectionOffset = kForward * (g_kTelekinesisDistanceT.GetValue() + m_fHitDistance);
                hkVector4T kMotionVelocity;
                NI2HK(&kMotionVelocity, &kIntersectionOffset);
                hkSimdRealT kMass(pkTarget->GetMass());
                kMotionVelocity.mul4(kMass);
                pkTarget->SetLinearVelocity(kMotionVelocity)->Update();
            }
            else
            {
                pkTarget->SetVelocity(g_kZeroPointT);
            }
        }
    }
}
