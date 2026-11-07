#pragma once

#include "NiBSplineColorInterpolator.h"

class NiBSplineCompColorInterpolator : public NiBSplineColorInterpolator
{
public:
    NiBSplineCompColorInterpolator();
    NiBSplineCompColorInterpolator(const NiBSplineCompColorInterpolator& other);
    virtual ~NiBSplineCompColorInterpolator();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& cloning);
    virtual void LoadBinary(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual bool UpdateColorA(float time, NiObjectNET* target, NiColorA& value);
    virtual bool vf60();

    void SaveToStream(NiStream& stream);
    void LoadFromStream(NiStream& stream);
    void* Destroy(unsigned int flags);
    void GetViewerStrings_00a519b0(NiTPrimitiveArray<char*>* strings);
    NiBSplineCompColorInterpolator* CreateClone_00a51890(CloningProcess& cloning);
    char EvaluateColor(float time, void* unused, NiColorA* output);

    union
    {
        float m_afOffsetAndHalfRange[2];
        float m_afScalars[2];
        float m_data[2];
        int m_iFourthElementInteger[2];
        struct
        {
            float bias;
            float multiplier;
        };
        struct
        {
            volatile float m_fStartValue;
            volatile float m_fEndValue;
        };
    };
};
