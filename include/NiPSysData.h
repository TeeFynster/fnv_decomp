#pragma once

#include "NiParticlesData.h"

class NiStream;
class Point3ParameterData;
class ParticleInfo;

class NiPSysData : public NiParticlesData
{
public:
    NiPSysData();
    virtual ~NiPSysData();

    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    virtual void SaveBinary(NiStream&);
    virtual bool IsEqual(NiObject*) const;
    virtual void GetViewerStrings(NiViewerStringsArray*);
    virtual void vf41(unsigned short);
    virtual unsigned short GetParticleVertexCount();
    virtual void vf43();

    bool IsKindOfType(const NiRTTI*) const;
    NiPoint3* GetPositions();
    NiPoint3* GetVertices() const;
    unsigned short GetShaderParticleCount() const;
    Point3ParameterData* GetParticleInfo();
    ParticleInfo* GetParticleInfo() const;
    float* GetRotationSpeeds();
    void SetParticleCount(unsigned int uiIndex);
    void CopyMemberData(NiPSysData* pkDest, CloningProcess& kCloning);
    void ResolveAddedParticles();
    NiPSysData& operator=(const NiPSysData&);

    Point3ParameterData* m_pkParticleInfo;
    float* m_pfRotationSpeeds;
    unsigned short m_usNumActive;
    unsigned short m_usNumParticles;
};
