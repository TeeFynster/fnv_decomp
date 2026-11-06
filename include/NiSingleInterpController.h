#pragma once

#include "NiInterpController.h"

class NiSingleInterpController : public NiInterpController
{
public:
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& process);

    virtual unsigned short GetTargetCount() const;
    virtual const char* GetTargetName(unsigned short index) const;
    virtual unsigned short GetTargetIndex(const char* id) const;
    virtual unsigned short GetTargetIndex(const NiFixedString& id) const;
    virtual NiInterpolator* GetInterpolator(unsigned short index) const;
    virtual void SetInterpolator(NiInterpolator* interpolator, unsigned short index);
    virtual void AdvanceControllerTime();
    virtual void SetActiveTimeRange(float startTime, float endTime);
    virtual bool TargetIsRequired(NiObjectNET* object) const;

    void CopyMemberData(NiSingleInterpController* clone, CloningProcess& process);
    void GetValue(float* value);
    void GetPoseValue(bool& value);

    NiPointer<NiInterpolator> m_spControllerInterpolator;
};
