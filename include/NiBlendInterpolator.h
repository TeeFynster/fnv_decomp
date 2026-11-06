#pragma once

#include "NiInterpolator.h"
#include "StrArr.h"

class NiBlendInterpolator__InterpArrayItem;

class NiBlendInterpolator : public NiInterpolator
{
  public:
    class InterpArrayItem;

    NiBlendInterpolator(bool onlyUseHighestWeight, float weightThreshold, unsigned char arraySize);
    virtual ~NiBlendInterpolator();

    virtual void LoadBinary(NiStream& stream);
    virtual void ProcessClone(CloningProcess& process);

    virtual unsigned char AddInterpolatorItem(NiInterpolator* interpolator, float weight, char priority,
                                              float easeSpinner);
    virtual void RemoveInterpolatorAt(unsigned char index);
    virtual bool ControlsTransform(NiInterpolator* interpolator);
    virtual bool GrowInterpolatorArray();

    virtual void SaveBinary(NiStream& stream);
    void CopyMembers(void* object, void* process);
    void AppendInterpolatorStrings(StrArr* strings);
    bool Probe(void* object);
    bool GetUpdateTimeForItem(float& time, unsigned char index);

    virtual bool IsEqual(NiObject* object) const;
    void NormalizeWeights();
    void UpdatePriorityData();
    bool GetBlendUpdateTime(float& time, NiBlendInterpolator__InterpArrayItem& item);
    void GetTimeRange(float* minTime, float* maxTime);

    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
    char m_cHighPriority;
    char m_cNextHighPriority;
    unsigned char unk12[2];
    NiBlendInterpolator__InterpArrayItem* m_pInterpArray;
    NiInterpolator* m_pSingleInterpolator;
    float m_fWeightThreshold;
    float m_fSingleInterpolatorTime;
    float m_fHighSumOfWeights;
    float m_fNextHighSumOfWeights;
    float m_fTrailingValue;

    static const float INVALID_TIME;
};
