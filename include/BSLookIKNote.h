#pragma once

#include "BSAnimNote.h"

class BSLookIKNote : public BSAnimNote
{
  public:
    BSLookIKNote();
    virtual ~BSLookIKNote();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual bool __thiscall vf35(const TimedTextEntry* apTextKey);

    void* __thiscall Destroy(unsigned int flags);

    float m_fDistanceScale;
    int eState;
};
