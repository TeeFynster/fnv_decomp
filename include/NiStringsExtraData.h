#pragma once

#include "NiExtraData.h"

class ViewerStringArray;

class NiStringsExtraData : public NiExtraData
{
  public:
    virtual ~NiStringsExtraData();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);

    void __thiscall FreeStrings();
    void __thiscall DestroyFields_00a7b300();
    void* __thiscall FUN_00a94970(unsigned int flags);
    void __thiscall CopyStringsExtraData(NiStringsExtraData* pDest, void* pCloning);
    void LoadStringArray(NiStream* stream);
    NiStringsExtraData* CreateClone_00a94990(void* pCloning);
    void SaveBinary_00a949f0(NiStream& stream);
    void GetViewerStrings_00a94ae0(ViewerStringArray* apViewerStrings);

    union
    {
        unsigned int m_uiItemCount;
        unsigned int m_uiSize;
    };
    union
    {
        void** m_ppData;
        char** m_ppcValue;
    };
};
