#pragma once

#include "NiGeometryData.h"
#include "NiQuaternion.h"

class NiParticlesData : public NiGeometryData
{
  public:
    NiParticlesData();
    virtual ~NiParticlesData();

    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    virtual void SaveBinary(NiStream&);
    virtual bool IsEqual(NiObject*) const;
    virtual void GetViewerStrings(NiViewerStringsArray*);
    virtual void vf41(unsigned short);

    void SetRotations(NiQuaternion*);
    float* GetRadii();
    float* GetSizes();
    unsigned char* GetTextureIndices();
    NiColorA* GetSubTextureOffsets();
    unsigned char GetSubTextureOffsetCount();
    NiQuaternion* GetRotations();
    float* GetRotationAngles();
    NiPoint3* GetRotationAxes();
    NiParticlesData& operator=(const NiParticlesData&);

    bool m_bHasRadii;
    unsigned char layoutPadding41[3];
    unsigned short* m_pusParticleIndices;
    float* m_pfSortValues;
    float* m_pfRadii;
    unsigned short m_usActive;
    unsigned char layoutPadding52[2];
    float* m_pfSizes;
    NiQuaternion* m_pkRotations;
    float* m_pfRotationAngles;
    NiPoint3* m_pkRotationAxes;
    unsigned char* m_pucTextureIndices;
    NiColorA* m_pkSubTextureOffsets;
    unsigned char m_ucSubTextureOffsetCount;
    unsigned char layoutPadding6D[3];
};
