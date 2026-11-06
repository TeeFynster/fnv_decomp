#pragma once

#include "NiInterpolator.h"
#include "NiAVObject.h"
#include "NiBSplineData.h"
#include "NiBSplineBasisData.h"

class NiBSplineInterpolator : public NiInterpolator
{
  public:
    NiBSplineInterpolator();
    virtual ~NiBSplineInterpolator();
    NiBSplineInterpolator& operator=(const NiBSplineInterpolator&);

    virtual void LoadBinary(NiStream& stream);
    virtual void GetInterpolatorTimeRange(float& beginTime, float& endTime) const;
    virtual void SetActiveTimeRange(float startTime, float endTime);
    virtual NiInterpolator* CloneForTimeRange(float startTime, float endTime);

    virtual int vf55();
    virtual unsigned int vf56(unsigned short channel);
    virtual unsigned int vf57(unsigned short channel);
    virtual bool vf58(unsigned short channel);
    virtual unsigned int vf59(unsigned short channel);
    virtual bool vf60();
    virtual unsigned int vf61(unsigned short channel);
    virtual int vf62(int channel);
    virtual void vf63();

    float m_fStartTime;
    float m_fEndTime;
    NiPointer<NiBSplineData> m_spTransformData;
    NiPointer<NiBSplineBasisData> m_spSplineBasisData;
};
