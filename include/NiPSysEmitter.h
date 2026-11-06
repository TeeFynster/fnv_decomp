#pragma once

#include "NiPSysModifier.h"
#include "NiColorA.h"

class NiPoint3;

class NiPSysEmitter : public NiPSysModifier
{
public:
    NiPSysEmitter();
    NiPSysEmitter(const char* pcName, unsigned int uiOrder, float fSpeed, float fSpeedVar,
                  float fDeclination, float fDeclinationVar, float fPlanarAngle,
                  float fPlanarAngleVar, NiColorA kInitialColor, float fInitialRadius,
                  float fLifeSpan, float fLifeSpanVar, float fRadiusVar);
    virtual ~NiPSysEmitter();

    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);

    virtual void vf41(float time, unsigned short numParticles, const float* ages);
    virtual void GetPositionAndDirection(NiPoint3& position, NiPoint3& motionVelocity);

    float m_fEmissionSpeed;
    float m_fSpeedVariation;
    float m_fEmissionDeclination;
    float m_fDeclinationVariation;
    float m_fEmissionPlanarAngle;
    float m_fPlanarAngleVariation;
    NiColorA m_kParticleColor;
    float m_fEmissionRadius;
    float m_fRadiusVariation;
    float m_fYValue;
    float m_fLifeSpanVariation;
    float m_fScale;
};
