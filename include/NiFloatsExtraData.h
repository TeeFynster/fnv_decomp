#pragma once

#include "NiExtraData.h"

template <class T> struct NiFloatsMallocInterface;
#include "NiTArray.h"
typedef NiTArray<char*, NiTMallocInterface<char*> > NiFloatsViewerStringsArray;

class NiFloatsExtraData : public NiExtraData
{
  public:
    virtual ~NiFloatsExtraData();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);

    float GetValueAt(int index);
    float GetValueAt(unsigned int uiIndex);
    bool SetValue(unsigned int uiIndex, float fValue);
    void SetValue(int index, float value);

    void CopyFloatsExtraData(NiFloatsExtraData* pDest, CloningProcess* pCloning);
    using NiExtraData::CopyMembers_00a7b330;
    void CopyMembers_00a7b330(NiFloatsExtraData* pDest, CloningProcess* pCloning);
    NiFloatsExtraData* CreateNiFloatsExtraData(CloningProcess* pCloning);
    void* DestroyNiFloatsExtraData(unsigned int flags);
    bool IsEqual_00a890b0(const NiFloatsExtraData* pOther);
    void SaveBinary_00a89210(NiStream& stream);
    void GetViewerStrings_00a89280(NiFloatsViewerStringsArray* pkStrings);

    unsigned int m_uiSize;
    float* m_pfValue;
};
