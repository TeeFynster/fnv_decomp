#pragma once

#include "NiKeyBasedInterpolator.h"
#include "NiColorInterpolator.h"
#include "NiQuaternion.h"

class NiRotData;
class TimedRotationKey;

class NiQuaternionInterpolator : public NiKeyBasedInterpolator
{
  public:
    NiQuaternionInterpolator();
    virtual ~NiQuaternionInterpolator();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual bool UpdateQuaternion(float afTime, NiObjectNET* apTarget, NiQuaternion& arValue);
    virtual bool IsQuaternionValueSupported() const;
    virtual void Collapse();
    virtual void GetInterpolatorTimeRange(float& arBeginKeyTime, float& arEndKeyTime) const;
    virtual void SetActiveTimeRange(float afStartTime, float afEndTime);
    virtual NiInterpolator* CloneForTimeRange(float afStartTime, float afEndTime);
    virtual unsigned short GetKeyChannelCount() const;
    virtual unsigned int GetColorKeyCount(unsigned short usChannel) const;
    virtual void vf57();
    virtual void vf58();
    virtual NiAnimationKey* GetChannelKeys(unsigned short usChannel) const;
    virtual unsigned char GetColorKeySize(unsigned short usChannel) const;
    virtual void vf61(unsigned short usChannel);

    NiAnimationKey::KeyContent __stdcall GetKeyContent();
    NiAnimationKey::KeyContent __stdcall ComputeValue_00a487e0();
    void GuaranteeTimeRange_00a48960(float m_fStartTime, float m_fMaximumDistance);
    bool TimeHasChanged(float fTime);
    TimedRotationKey* GetKeys(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize) const;
    bool GetQuaternionAtTime(float fTime, NiObjectNET* pkInterpTarget, NiQuaternion& kValue);
    void CollapseQuatInterp();

    NiQuaternion m_kQuaternionValue;
    NiPointer<NiRotData> m_spQuaternionData;
    unsigned int m_uiLastKeyIndex;
};
