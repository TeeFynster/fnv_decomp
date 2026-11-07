#pragma once

#include "NiLODData.h"
#include "NiBound.h"

class NiLODNode;
class ScreenData;
class ScreenObject;

class NiScreenLODData : public NiLODData
{
  public:
    ScreenData* data;
    void* unused;
    ScreenObject* root;
    ScreenObject** objects;
    NiBound m_kWorldBound;
    union
    {
        unsigned int m_uiProportionCount;
        unsigned int m_uiItemCount;
        unsigned int m_uiCount;
        unsigned int m_28;
    };
    union
    {
        float* m_pfProportions;
        float* m_iSlotIds;
        int* m_piIndices;
        void* m_2c;
        float* prop;
    };

    NiBound& GetBound()
    {
        return *reinterpret_cast<NiBound*>(&data);
    }
    const NiBound& GetBound() const
    {
        return *reinterpret_cast<const NiBound*>(&data);
    }
    void SetBound(const NiBound& bound)
    {
        GetBound().m_kCenter = bound.m_kCenter;
        GetBound().m_fRadius = bound.m_fRadius;
    }
    __declspec(property(get=GetBound, put=SetBound)) NiBound m_kBound;
    __declspec(property(get=GetBound, put=SetBound)) NiBound m_08;

    NiBound& GetWorldBound()
    {
        return m_kWorldBound;
    }
    const NiBound& GetWorldBound() const
    {
        return m_kWorldBound;
    }
    void SetWorldBound(const NiBound& bound)
    {
        m_kWorldBound.m_kCenter = bound.m_kCenter;
        m_kWorldBound.m_fRadius = bound.m_fRadius;
    }
    __declspec(property(get=GetWorldBound, put=SetWorldBound)) NiBound m_18;

    void UpdateScreenBound(NiBound& bound);
    void UpdateScreenBound(NiLODNode*);
    int ClampToLODCount(int index);
    void SetProportionCount(unsigned int count);
    NiScreenLODData* InitializeScreenLODData();
    void* NiScreenLODData_GetRTTI();
};
