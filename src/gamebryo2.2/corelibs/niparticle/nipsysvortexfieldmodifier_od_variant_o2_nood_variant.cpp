#include "../../../../include/NiTransform.h"

// src/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier_od_variant_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier_od_variant.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void* g_01202688;
void* __cdecl NiPSysVortexFieldModifier_GetRTTI();

// FUN_00c26de0: NiPSysFieldModifier-style Update with attenuation - per-particle
// force from FUN_00c26820, scaled by magnitude * dt / dist^attenuation.
extern "C" double __cdecl pow(double, double);

struct TPoint3
{
    float x, y, z;

    TPoint3()
    {}
    TPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}

    TPoint3 operator-(const TPoint3& kPt) const
    {
        return TPoint3(x - kPt.x, y - kPt.y, z - kPt.z);
    }
    bool HasEqualComponents(const TPoint3& kPt) const;
    float FUN_00457990() const;
    void Unitize_004a0c10();
    TPoint3& ScaleComponents(float fScalar);
    TPoint3& ComputeValue_0063c8a0(const TPoint3& kPt);
};

extern const TPoint3 DAT_011f426c;

struct TAVObject
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    NiTransform m_kWorldSpaceTransform;
};

struct TParticleInfo
{
    TPoint3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    int unk18;
};

struct TPSysData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    TPoint3* m_pkVertex;
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
    unsigned short m_usVertices;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    TParticleInfo* m_pkParticleInfo;

    unsigned short GetShaderParticleCount() const
    {
        return m_usVertices;
    }
    TPoint3* GetVertices() const
    {
        return m_pkVertex;
    }
    TParticleInfo* GetParticleInfo() const
    {
        return m_pkParticleInfo;
    }
};

inline float NiPow(float fBase, float fExp)
{
    return (float)pow(fBase, fExp);
}

struct TFieldModifier
{
    void* m_pVtbl;
    int m_iRefCount;
    int m_kName;
    unsigned int m_uiUpdateOrder;
    TAVObject* m_pkTarget;
    bool m_bModifierActive;
    TAVObject* m_pkFieldObject;
    float m_fInfluence;
    float m_fFieldAttenuation;
    bool m_bEnableMaxDistance;
    float m_fDistanceLimit;
    float m_fFieldStrength;
    TPoint3 m_kLightVector;

    void NiPSysVortexFieldModifier_Update(float fTime, TPSysData* pkData);
    void ApplyVortexVelocityWithinDistance(float fTime, TPSysData* pkData);
    void ApplyParticleForces(float fTime, TPSysData* pkData);
    __declspec(noalias) TPoint3 Object_ProcessAndReturnValue_00c26820(const TPoint3& kFieldPos, const TPoint3& kFieldDir, const TPoint3& kPos);
};

// @fnv 0x00c26de0
// src: XBOX_PDB 0x00c26de0
void TFieldModifier::NiPSysVortexFieldModifier_Update(float fTime, TPSysData* pkData)
{
    if (m_fInfluence == 0.0f)
        return;
    if (pkData->GetShaderParticleCount() == 0)
        return;
    if (m_kLightVector.HasEqualComponents(DAT_011f426c))
        return;
    if (!m_pkFieldObject)
        return;

    if (m_fFieldAttenuation == 0.0f)
    {
        if (m_bEnableMaxDistance)
            ApplyVortexVelocityWithinDistance(fTime, pkData);
        else
            ApplyParticleForces(fTime, pkData);
        return;
    }

    // The original temporaries are uninitialized; use aligned storage to avoid
    // introducing constructor calls before the transform copies and inverse.
    float fieldStorage[sizeof(NiTransform) / sizeof(float)];
    NiTransform& kFieldXform = *reinterpret_cast<NiTransform*>(fieldStorage);
    kFieldXform = m_pkFieldObject->m_kWorldSpaceTransform;
    float inverseStorage[sizeof(NiTransform) / sizeof(float)];
    NiTransform& kInvPSys = *reinterpret_cast<NiTransform*>(inverseStorage);
    {
        float targetStorage[sizeof(NiTransform) / sizeof(float)];
        NiTransform& kPSysXform = *reinterpret_cast<NiTransform*>(targetStorage);
        kPSysXform = m_pkTarget->m_kWorldSpaceTransform;
        kPSysXform.FUN_004b4880(kInvPSys);
    }

    {
        NiTransform kFieldToPSys = kInvPSys.FUN_0062c250(kFieldXform);
        TPoint3 kFieldPos = reinterpret_cast<const TPoint3&>(kFieldToPSys.m_Translate);
        NiPoint3 kRotatedDir = static_cast<const NiMatrix3&>(kFieldToPSys.m_Rotate).operator*(
            reinterpret_cast<const NiPoint3&>(m_kLightVector));
        TPoint3& kFieldDir = reinterpret_cast<TPoint3&>(kRotatedDir);
        kFieldDir.Unitize_004a0c10();

        for (unsigned short i = 0; i < pkData->GetShaderParticleCount(); i++)
        {
            TParticleInfo* pkInfo = &pkData->GetParticleInfo()[i];
            float fDeltaT = fTime - pkInfo->m_fZValue;
            if (fDeltaT != 0.0f)
            {
                TPoint3 kPos = pkData->GetVertices()[i];
                TPoint3 kDiff = kPos - reinterpret_cast<const TPoint3&>(kFieldToPSys.m_Translate);
                float fDist = kDiff.FUN_00457990();
                if (fDist != 0.0f)
                {
                    if (!m_bEnableMaxDistance || fDist <= m_fDistanceLimit)
                    {
                        TPoint3 kForce = Object_ProcessAndReturnValue_00c26820(kFieldPos, kFieldDir, kPos);
                        if (m_fFieldAttenuation == 0.0f)
                            kForce.ScaleComponents(fDeltaT * m_fInfluence);
                        else
                            kForce.ScaleComponents(fDeltaT * m_fInfluence / NiPow(fDist, m_fFieldAttenuation));
                        pkInfo->m_kValue.ComputeValue_0063c8a0(kForce);
                    }
                }
            }
        }
    }
}
