#pragma once

#include "NiExtraData.h"

#pragma pack(push, 1)
class NiBooleanExtraData : public NiExtraData
{
  public:
    virtual ~NiBooleanExtraData();

    bool IsEqualTo(NiObject* pObject);

    bool m_bValue;
};
#pragma pack(pop)
