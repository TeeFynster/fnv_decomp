#pragma once

#include "NiPSysModifier.h"

class ParticleSystemX;

class NiPSysSpawnModifier : public NiPSysModifier
{
public:
    virtual void LoadBinary(NiStream& kStream);
    virtual void SpawnChildParticles(float fTime, float fCollisionTime, unsigned int uiIndex,
                                    NiPSysData* pkData);
    virtual void UpdateSpawning(float afTime, float fTime, unsigned short usOldIndex,
                               ParticleSystemX* pkSystem);

    unsigned short m_usSpawnGenerationCount;
    unsigned char layoutPadding1A[2];
    float m_fSpawnPercentage;
    unsigned short m_usMinimumParticlesToSpawn;
    unsigned short m_usMaximumParticlesToSpawn;
    float m_fSpawnedSpeedChaos;
    float m_fSpawnDirectionChaos;
    float m_fYValue;
    float m_fLifeSpanVariation;
};
