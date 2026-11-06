#pragma once

#include "NiObject.h"
#include "CA0E60Array.h"

class bhkRagdollTemplateData : public NiObject
{
public:
    virtual ~bhkRagdollTemplateData();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* apObject) const;

    static NiObject* __cdecl CreateObject();

    void* m_kName;
    CA0E60Array m_kArray1;
    CA0E60Array m_kArray2;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
