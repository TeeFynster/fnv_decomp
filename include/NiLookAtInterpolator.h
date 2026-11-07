#pragma once

#include "NiInterpolator.h"
#include "NiFixedString.h"
#include "NiQuatTransform.h"

class NiAVObjectPalette;

class NiLookAtInterpolator : public NiInterpolator
{
  public:
    NiLookAtInterpolator(unsigned int pkLookAt, unsigned int eAxis, bool bFlip);
    virtual ~NiLookAtInterpolator();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual void ProcessClone(CloningProcess& arCloning);
    virtual bool UpdateTransform(float afTime, NiObjectNET* apTarget, NiQuatTransform& arValue);
    virtual bool IsTransformValueSupported() const;
    virtual void Collapse();
    virtual void GetInterpolatorTimeRange(float& arBeginKeyTime, float& arEndKeyTime) const;
    virtual void SetActiveTimeRange(float afStartTime, float afEndTime);
    virtual NiInterpolator* CloneForTimeRange(float afStartTime, float afEndTime);
    virtual bool IsPoseValue();
    virtual bool IsTimeVarying();

    void __thiscall CopyMembers_00a4c4b0(NiLookAtInterpolator* pkDest, CloningProcess& kCloning);
    void* __thiscall FUN_00a4c5c0(unsigned int flags);
    void SetLookAtName(const NiFixedString& kName);
    bool ResolveTargetObject(NiAVObjectPalette* pkPalette);
    void __thiscall GetItemsRange(float* pStart, float* pEnd);

    unsigned short m_usFlags;
    unsigned short unk0E;
    NiAVObject* m_pkLookAt;
    NiFixedString m_kTargetNodeName;
    NiQuatTransform m_kTransform;
    NiInterpolator* m_pItems[3];
};
