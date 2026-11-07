#pragma once

#include "NiPSysFieldModifier.h"

class NiPSysRadialFieldModifier : public NiPSysFieldModifier
{
public:
    float m_fBoundRadius;

    virtual ~NiPSysRadialFieldModifier();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual void Update(float time, NiPSysData* data);

    void LoadBinary_00c28760(NiStream& stream);
    void SaveBinary_00c27770(NiStream& stream);
};
