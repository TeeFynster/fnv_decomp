#pragma once

#include "NiPoint3InterpController.h"

class NiMaterialColorController : public NiPoint3InterpController
{
public:
    virtual bool IsEqual(NiObject* object) const;

    NiMaterialColorController* Clone(CloningProcess& process);
    const char* GetChannelName();
    NiMaterialColorController* Destroy(int flags);

    unsigned short m_uiObjectFlags;
    unsigned char unk3A[0x7E];
};
