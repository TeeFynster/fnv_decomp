#pragma once

#include "NiProperty.h"
#include "StrArr.h"

class NiStencilProperty : public NiProperty
{
  public:
    NiStencilProperty();
    virtual ~NiStencilProperty();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);

    void* DestroyAndFree(unsigned int flags);
    void Destroy();
    void DestroyBase();
    bool IsEqual_00a6f070(NiObject* object);
    void LoadBinary_00a6f500(NiStream& stream);
    void SaveBinary_00a6f740(NiStream* stream);
    void GetViewerStrings_00a6f7d0(StrArr* strings);

    union
    {
        unsigned int m_18;
        unsigned short mode;
    };
    union
    {
        unsigned int m_1c;
        unsigned int flags;
        unsigned int reference;
    };
    union
    {
        unsigned int m_20;
        unsigned int mask;
    };

    static const NiRTTI ms_kRTTI;
};
