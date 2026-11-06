#pragma once

#include "TESForm.h"

class BGSProjectile;

class AmmoProjectileData
{
public:
    unsigned char m_ucFlags;
    unsigned char layoutPadding1[3];
    BGSProjectile* m_pProjectile;
    float m_fProjectileSpeed;
    TESForm* m_pShellCasing;
    float m_fDamageMultiplier;
};
