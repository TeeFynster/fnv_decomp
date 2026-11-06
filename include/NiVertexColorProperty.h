#pragma once

#include "NiProperty.h"

#pragma pack(push, 2)
class NiVertexColorProperty : public NiProperty
{
  public:
    NiVertexColorProperty() throw();

    bool IsVertexColorPropertyEqual(NiObject*);

    unsigned short m_uiObjectFlags;
};
#pragma pack(pop)
