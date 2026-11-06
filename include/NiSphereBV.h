#pragma once

#include "NiBoundingVolume.h"
#include "NiSphere.h"

class NiSphereBV : public NiBoundingVolume
{
public:
    NiSphere m_kBoundingSphere;

    virtual void LoadBinary(NiStream& kStream) override;
    virtual void __thiscall SaveBinary(NiStream& kStream) override;

    void CopySphereFrom(const NiBoundingVolume&);
};
