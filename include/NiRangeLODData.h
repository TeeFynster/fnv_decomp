#pragma once

#include "NiLODData.h"
#include "NiPoint3.h"
#include "NiPoint3.h"

class CloningProcess;

class NiRangeLODData : public NiLODData
{
  public:
    struct Range
    {
        float m_fNearPlane;
        float m_fFarPlane;
        unsigned int unusedA;
        unsigned int unusedB;
    };

    NiPoint3 m_kCenter;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int m_uiRangeCount;
    Range* m_pRanges;

    NiPoint3& GetWorldCenter()
    {
        return *reinterpret_cast<NiPoint3*>(&unk14);
    }
    const NiPoint3& GetWorldCenter() const
    {
        return *reinterpret_cast<const NiPoint3*>(&unk14);
    }
    void SetWorldCenter(const NiPoint3& center)
    {
        GetWorldCenter() = center;
    }
    __declspec(property(get=GetWorldCenter, put=SetWorldCenter)) NiPoint3 m_kWorldCenter;

    NiRangeLODData() throw();
    virtual ~NiRangeLODData();
    virtual NiObject* MakeClone(CloningProcess& arCloning);


    NiRangeLODData* __thiscall InitializeRangeLODData();
    void __thiscall SetRangeCount(unsigned int count);
    void SetGridPosition(const NiPoint3& c);
    void SetRange(unsigned int i, float fNear, float fFar);
    void CopyTo(NiRangeLODData* pkDest, CloningProcess* kCloning);
    void CopyMemberData(NiRangeLODData* pkDest, CloningProcess& kCloning);
    NiObject* CreateClone_00a97ce0(CloningProcess& kCloning);
};

