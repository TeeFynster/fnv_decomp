#pragma once

#include "NiSingleInterpController.h"
#include "NiFixedString.h"
#include "NiExtraData.h"

class NiExtraDataController : public NiSingleInterpController
{
public:
    virtual bool IsEqual(NiObject* object) const;

    void PostLinkObject_00a57400(NiStream& kStream);

    NiFixedString m_kDataName;
    NiPointer<NiExtraData> m_pExtraData;
};
