#pragma once

#include "NiObject.h"

class NiObjectNET;
class NiAVObject;
class NiQuatTransform;
class NiColorA;
class NiPoint3;
class NiQuaternion;
class NiBoolInterpolator;

class NiInterpolator : public NiObject
{
  public:
    NiInterpolator();
    virtual ~NiInterpolator();

    virtual void LoadBinary(NiStream& arStream);
    virtual void ProcessClone(CloningProcess& arCloning);

    virtual bool UpdateTransform(float afTime, NiObjectNET* apTarget, NiQuatTransform& arValue);
    virtual bool UpdateColorA(float afTime, NiObjectNET* apTarget, NiColorA& arValue);
    virtual bool UpdatePoint3(float afTime, NiObjectNET* apTarget, NiPoint3& arValue);
    virtual bool UpdateQuaternion(float afTime, NiObjectNET* apTarget, NiQuaternion& arValue);
    virtual bool UpdateFloat(float afTime, NiObjectNET* apTarget, float& arValue);
    virtual bool UpdateBool(float afTime, NiObjectNET* apTarget, bool& arValue);
    virtual bool IsBoolValueSupported() const;
    virtual bool IsFloatValueSupported() const;
    virtual bool IsQuaternionValueSupported() const;
    virtual bool IsPoint3ValueSupported() const;
    virtual bool IsColorAValueSupported() const;
    virtual bool IsTransformValueSupported() const;
    virtual void Collapse();
    virtual void GetInterpolatorTimeRange(float& arBeginKeyTime, float& arEndKeyTime) const;
    virtual void SetActiveTimeRange(float afStartTime, float afEndTime);
    virtual NiInterpolator* CloneForTimeRange(float afStartTime, float afEndTime);
    virtual bool IsPoseValue();
    virtual bool IsTimeVarying();
    virtual bool AlwaysUpdate() const;
    virtual NiBoolInterpolator* IsNiBoolInterpolator() const;

    void IncRefCount();
    void DecRefCount();
    bool Update(float afTime, NiObjectNET* apTarget, NiQuatTransform& arValue);
    bool Update(float afTime, NiObjectNET* apTarget, NiColorA& arValue);
    bool Update(float afTime, NiObjectNET* apTarget, NiPoint3& arValue);
    bool Update(float afTime, NiObjectNET* apTarget, float& arValue);
    bool Update(float afTime, NiObjectNET* apTarget, const void* apUpdateData);
    bool Update(float afTime, NiAVObject* apTarget, const NiQuatTransform& arValue);

    float m_fLastTime;
};
