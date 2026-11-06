// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITRANSFORMDATA_FNV_NIINTERPOLATOR_H
#define FNV_NITRANSFORMDATA_FNV_NIINTERPOLATOR_H

#include "nitransformdata_layout_support.h"
#include "nitransformdata_NiObject.h"
class NiColorA;
class NiQuatTransform;
class NiQuaternion;
class NiBoolInterpolator;
class NiObjectNET;
class NiPoint3;
class NiInterpolator;
class NiInterpolator : public NiObject
{
  public:
    virtual bool UpdateTransform(float time, NiObjectNET* target, NiQuatTransform& value);
    virtual bool UpdateColorA(float time, NiObjectNET* target, NiColorA& value);
    virtual bool UpdatePoint3(float time, NiObjectNET* target, NiPoint3& value);
    virtual bool UpdateQuaternion(float time, NiObjectNET* target, NiQuaternion& value);
    virtual bool UpdateFloat(float time, NiObjectNET* target, float& value);
    virtual bool UpdateBool(float time, NiObjectNET* target, bool& value);
    virtual bool IsBoolValueSupported() const;
    virtual bool IsFloatValueSupported() const;
    virtual bool IsQuaternionValueSupported() const;
    virtual bool IsPoint3ValueSupported() const;
    virtual bool IsColorAValueSupported() const;
    virtual bool IsTransformValueSupported() const;
    virtual void Collapse();
    virtual void GetInterpolatorTimeRange(float& beginTime, float& endTime) const;
    virtual void SetActiveTimeRange(float startTime, float endTime);
    virtual NiInterpolator* CloneForTimeRange(float startTime, float endTime);
    virtual bool IsPoseValue();
    virtual bool IsTimeVarying();
    virtual bool AlwaysUpdate() const;
    virtual NiBoolInterpolator* IsNiBoolInterpolator() const;
    // base NiObject at +0x0, size 8
    float m_fLastTime;  // +0x8, 4 bytes
    // const NiRTTI* __cdecl NiInterpolator::*()
    // void __cdecl NiInterpolator::*(NiStream&)
    // void __cdecl NiInterpolator::*(NiStream&)
    // bool __cdecl NiInterpolator::*(NiStream&)
    // void __cdecl NiInterpolator::*(NiStream&)
    // bool __cdecl NiInterpolator::*(NiObject*)
    // void __cdecl NiInterpolator::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiInterpolator::*()
    // Update
    // void __cdecl NiInterpolator::*()
    // NiInterpolator
    // bool __cdecl NiInterpolator::*(float)
    // NiInterpolator& __cdecl NiInterpolator::*(const NiInterpolator&)
    // void __cdecl NiInterpolator::*()
};
FNV_STATIC_ASSERT(sizeof(NiInterpolator) == 12);
FNV_STATIC_ASSERT(offsetof(NiInterpolator, m_fLastTime) == 8);
#endif
