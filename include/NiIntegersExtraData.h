#pragma once

#include "NiExtraData.h"
#include "NiIntegerStreamArray.h"

class NiIntegersExtraData : public NiExtraData
{
  public:
    NiIntegersExtraData() throw()
    {
        m_piValue = 0;
        m_uiSize = 0;
    }
    virtual ~NiIntegersExtraData();

    virtual void LoadBinary(NiStream& stream);
    virtual void GetViewerStrings(NiViewerStringsArray* pkStrings);

    void AssignPointerArray(int a, int b);
    void SetVtableAndProcessState_00a99950();
    NiIntegersExtraData* NiIntegersExtraData_00a99980(int a, int b);
    NiIntegersExtraData* FUN_00a99a50(int flag);
    bool IsEqual_00a998e0(NiIntegersExtraData* pObject);
    void CopyMembers_00a99870(NiIntegersExtraData* pDest, void* pCloning);
    NiExtraData* CreateClone_00a999b0(void* pvProcess);
    void BaseGetViewerStrings(NiViewerStringsArray* pkStrings);

    union
    {
        NiIntegerStreamArray entries;
        struct
        {
            unsigned int m_uiSize;
            int* m_piValue;
        };
    };
};
