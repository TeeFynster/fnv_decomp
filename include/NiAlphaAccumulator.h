#pragma once

#include "NiBackToFrontAccumulator.h"

class NiAlphaAccumulator : public NiBackToFrontAccumulator
{
  public:
    NiAlphaAccumulator();
    virtual ~NiAlphaAccumulator();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void RegisterObjectArray(NiVisibleArray* pkVisibleArray);
    virtual bool RegisterObject(NiGeometry* pkGeom);
    virtual void Sort();

    static NiObject* CreateObject();

    void SetObserveNoSortHint(bool bObserveNoSortHint);
    bool GetObserveNoSortHint();
    void SetSortByClosestPoint(bool bSortByClosestPoint);
    bool GetSortByClosestPoint();
    void SetInterfaceSort(bool bInterfaceSort);
    NiAlphaAccumulator& operator=(const NiAlphaAccumulator&);

    bool m_bObserveNoSortHint;
    bool m_bSortByClosestPoint;
    bool m_bInterfaceSort;
    unsigned char _pad33[1];
};
