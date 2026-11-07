#pragma once

#include "NiBoolInterpolator.h"

class NiBoolData;
class StrArr;

class NiBoolTimelineInterpolator : public NiBoolInterpolator
{
  public:
    NiBoolTimelineInterpolator() throw();
    NiBoolTimelineInterpolator(NiBoolData* pkBoolData);
    virtual ~NiBoolTimelineInterpolator() throw();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual bool UpdateBool(float afTime, NiObjectNET* apTarget, bool& arValue);
    virtual unsigned short GetKeyChannelCount() const;
    virtual unsigned int GetColorKeyCount(unsigned short usChannel) const;
    virtual void vf57();
    virtual void vf58();
    virtual NiAnimationKey* GetChannelKeys(unsigned short usChannel) const;
    virtual unsigned char GetColorKeySize(unsigned short usChannel) const;
    virtual void vf61(unsigned short usChannel);


    void* ReleaseRef(unsigned int flags);
    void AppendString(StrArr* pkStrings);
    void CloneTo(NiBoolTimelineInterpolator* dest, CloningProcess& cloning);
    NiBoolTimelineInterpolator* CreateClone_00a52f80(CloningProcess& cloning);
    bool EvaluateBoolAtTime(float time, void* target, bool& out);
    bool Update(float time, NiObjectNET* target, bool& out);
    bool IsEqual_00a52d10();

    unsigned int m_uiLastIndex;
    bool m_bBoolValue;
};
