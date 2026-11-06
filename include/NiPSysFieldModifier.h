#pragma once

#include "NiPSysModifier.h"

class NiAVObject;

class NiPSysFieldModifier : public NiPSysModifier
{
public:
    NiAVObject* m_spFieldObject;
    float m_fInfluence;
    float m_fFieldAttenuation;
    bool m_bEnableMaxDistance;
    float m_fDistanceLimit;
    float m_fFieldStrength;

    NiPSysFieldModifier();
    virtual ~NiPSysFieldModifier();

    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;

    NiObject* Clone(CloningProcess& process);
    NiPSysFieldModifier* Destroy(unsigned int flags);
    void CopyMemberData(NiPSysFieldModifier* destination, CloningProcess& process);
};
