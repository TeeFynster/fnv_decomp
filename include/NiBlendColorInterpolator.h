#pragma once

#include "NiBlendInterpolator.h"
#include "NiColorA.h"

class ArraySource;

class NiBlendColorInterpolator : public NiBlendInterpolator
{
public:
    NiBlendColorInterpolator(bool onlyUseHighestWeight, float weightThreshold, unsigned char arraySize);
    virtual ~NiBlendColorInterpolator();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& cloning);
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual bool UpdateColorA(float time, NiObjectNET* target, NiColorA& value);
    virtual bool IsColorAValueSupported() const;
    virtual bool ControlsTransform(NiInterpolator* interpolator);

    bool GetColorAtTime(float time, NiObjectNET* target, NiColorA* value);
    bool UpdateBlend(float time, NiObjectNET* target, NiColorA* value);
    bool UpdateBlend(float time, NiObjectNET* target, NiColorA& value);
    bool InterpolateValue(float time, NiObjectNET* target, NiColorA& value);
    bool GetUpdateTimeForItem(float& time, NiBlendInterpolator__InterpArrayItem& item);
    void AppendTwoEntries(ArraySource* source);

    void SaveBinary_00a56040(NiStream& stream);
    void* FUN_00a56070(unsigned int flags);
    void* CreateClone_00a56090(CloningProcess& cloning);
    void LoadBinary_00a56460(NiStream& stream);
    bool IsEqual_00a564a0(void* other);

    NiColorA m_kColorValue;
    bool m_bValueValid;
};
