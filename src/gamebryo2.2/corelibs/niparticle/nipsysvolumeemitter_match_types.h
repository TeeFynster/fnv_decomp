// The shared emitter headers still lack the parameterized constructors and
// serialization/viewer overrides used by this unit.
#ifndef FNV_NIPSYSVOLUMEEMITTER_MATCH_TYPES_H
#define FNV_NIPSYSVOLUMEEMITTER_MATCH_TYPES_H

#include "layout_support.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiColorA.h"

class NiAVObject;
class NiPoint3;
class NiTransform;

class NiPSysEmitter : public NiPSysModifier
{
  public:
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
FNV_STATIC_ASSERT(sizeof(NiPSysEmitter) == 84);

class NiPSysVolumeEmitter : public NiPSysEmitter
{
  public:
    NiPSysVolumeEmitter(const char* pcName, NiAVObject* pkEmitterObj, float fSpeed,
                        float fSpeedVar, float fDeclination, float fDeclinationVar,
                        float fPlanarAngle, float fPlanarAngleVar, NiColorA kInitialColor,
                        float fInitialRadius, float fLifeSpan, float fLifeSpanVar,
                        float fRadiusVar);
    virtual ~NiPSysVolumeEmitter();
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& process);
    virtual void GetPositionAndDirection(NiPoint3& position, NiPoint3& motionVelocity);
    virtual void vf43(NiAVObject* object);
    virtual void vf44(NiTransform& transform, NiPoint3* position, NiPoint3* motionVelocity);
    void* DestroyIfFlagged(unsigned int flags);

    NiAVObject* m_pkEmitterObject;
};
FNV_STATIC_ASSERT(sizeof(NiPSysVolumeEmitter) == 88);
FNV_STATIC_ASSERT(offsetof(NiPSysVolumeEmitter, m_pkEmitterObject) == 84);
#endif
