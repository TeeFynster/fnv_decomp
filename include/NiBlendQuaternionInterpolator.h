#pragma once

#include "NiBlendInterpolator.h"
#include "NiQuaternion.h"

class NiQuadWords;
class StrArr;

class NiBlendQuaternionInterpolator : public NiBlendInterpolator
{
public:
    virtual NiObject* MakeClone(CloningProcess& cloning);
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual bool UpdateQuaternion(float time, NiObjectNET* target, NiQuaternion& value);
    virtual bool ControlsTransform(NiInterpolator* interpolator);

    void* CloneInterpolator(void* cloning);
    bool Interpolate(float time, void* target, NiQuaternion* value);
    void AppendInterpolatorStrings(StrArr* strings);
    unsigned char CheckWithOffset(void* object);
    bool UpdateSingle(float time, void* target, NiQuadWords* value);
    bool BlendValues(float time, void* target, NiQuaternion& value);

    NiQuaternion m_kQuaternionValue;
};
