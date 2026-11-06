#pragma once

#include "NiBlendInterpolator.h"
#include "NiPoint3.h"

class NiBlendPoint3Interpolator : public NiBlendInterpolator
{
  public:
    NiBlendPoint3Interpolator(bool managerControlled, float weightThreshold, unsigned char arraySize);
    virtual ~NiBlendPoint3Interpolator();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& cloning);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual bool UpdatePoint3(float time, NiObjectNET* target, NiPoint3& value);
    virtual bool IsPoint3ValueSupported() const;
    virtual bool ControlsTransform(NiInterpolator* interpolator);

    bool Update(float time, NiObjectNET* target, NiPoint3& value);
    bool UpdateAccumulatedTransform(float time, NiObjectNET* target, NiPoint3& value);
    bool UpdateSingleInterpolator(float time, NiObjectNET* target, NiPoint3& value);
    NiBlendPoint3Interpolator& operator=(const NiBlendPoint3Interpolator& other);

    NiPoint3 m_kPoint3Value;
    bool m_bValueValid;
};
