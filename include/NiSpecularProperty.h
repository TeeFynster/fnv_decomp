#pragma once

#include "NiProperty.h"

class NiSpecularProperty : public NiProperty
{
  public:
    NiSpecularProperty() throw();

    virtual NiObject* MakeClone(CloningProcess& cloning);

    unsigned short m_uiObjectFlags;
};
