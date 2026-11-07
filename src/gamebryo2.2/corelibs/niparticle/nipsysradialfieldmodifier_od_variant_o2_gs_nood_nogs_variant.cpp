
// src/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier_od_variant_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier_od_variant.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../include/NiTransform.h"
#include <string.h>

extern "C" void* g_012026b0;
void* __cdecl NiPSysRadialFieldModifier_GetRTTI();

inline NiPoint3::NiPoint3(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}

inline NiPoint3 NiPoint3::operator-(const NiPoint3& pt) const
{
    return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
}

inline NiPoint3 NiPoint3::operator*(float fScalar) const
{
    return NiPoint3(fScalar * x, fScalar * y, fScalar * z);
}

inline float NiPoint3::SqrLength() const
{
    return x * x + y * y + z * z;
}

inline void AddComponent(float& dst, float value)
{
    dst += value;
}

inline NiPoint3& AccumulatePoint(NiPoint3& dst, const NiPoint3& pt)
{
    dst.x += pt.x;
    AddComponent(dst.y, pt.y);
    dst.z += pt.z;
    return dst;
}

inline NiPoint3 ScalePoint(float s, float x, const NiPoint3& d)
{
    return NiPoint3(s * x, d.y * s, s * d.z);
}

struct SceneObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64;
    NiTransform world;
    NiTransform GetWorldTransform() const
    {
        return world;
    }
};

struct Particle
{
    NiPoint3 velocity;
    float unk0c, unk10, birthTime, unk18;
};

struct ParticleSystem
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    NiPoint3* positions;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    unsigned short count, unk52;
    int unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    Particle* particles;
};

float __cdecl BSMAX_00404010(float, float);
extern "C" double __cdecl pow(double, double);
inline float NiPow(float fBase, float fExponent)
{
    return (float)pow(fBase, fExponent);
}

class RadialField
{
  public:
    int unk00, unk04, unk08, unk0c;
    SceneObject* target;
    int unk14;
    SceneObject* source;
    float strength;
    float exponent;
    bool useRadius;
    float unk28;
    float radiusSquared;
    float attenuation;
    void Update(float time, ParticleSystem* system);
    void NiPSysRadialFieldModifier_Update(float time, ParticleSystem* system);
};

// @fnv 0x00c287a0
// src: XBOX_PDB 0x00c287a0
void RadialField::NiPSysRadialFieldModifier_Update(float time, ParticleSystem* system)
{
    if (strength == 0.0f || system->count == 0 || source == 0)
        return;
    if (!useRadius && (exponent == 0.0f || attenuation == 0.0f))
    {
        Update(time, system);
        return;
    }
    // These transforms are filled by bulk copies or the inverse operation.
    // Keep their storage uninitialized, as in the original, without invoking constructors.
    float sourceTransformStorage[sizeof(NiTransform) / sizeof(float)];
    NiTransform& sourceTransform = *reinterpret_cast<NiTransform*>(sourceTransformStorage);
    memcpy(&sourceTransform, &source->world, sizeof(sourceTransform));
    float inverseStorage[sizeof(NiTransform) / sizeof(float)];
    NiTransform& inverse = *reinterpret_cast<NiTransform*>(inverseStorage);
    {
        float targetTransformStorage[sizeof(NiTransform) / sizeof(float)];
        NiTransform& targetTransform = *reinterpret_cast<NiTransform*>(targetTransformStorage);
        memcpy(&targetTransform, &target->world, sizeof(targetTransform));
        targetTransform.FUN_004b4880(inverse);
    }
    {
        NiTransform fieldToSystem = inverse * sourceTransform;
        float halfExponent = exponent * 0.5;
        for (unsigned short i = 0; i < system->count; ++i)
        {
            Particle& particle = system->particles[i];
            float deltaTime = time - particle.birthTime;
            if (deltaTime == 0.0f)
                continue;
            NiPoint3 position = system->positions[i];
            NiPoint3 difference = position - fieldToSystem.m_Translate;
            float distanceSquared = static_cast<const NiPoint3&>(difference).SqrLength();
            if (useRadius && !(radiusSquared >= distanceSquared))
                continue;
            NiPoint3 change;
            if (exponent != 0.0f && distanceSquared != 0.0f)
            {
                change = ScalePoint((deltaTime * strength) /
                                        BSMAX_00404010(1.0f, NiPow(distanceSquared, halfExponent) * attenuation),
                                    difference.x, difference);
            }
            else
            {
                float scale = deltaTime * strength;
                change = difference * scale;
            }
            AccumulatePoint(particle.velocity, change);
        }
    }
}
