#pragma once

#include "BSExtraData.h"
#include "NiAVObject.h"

class NiCell3DNode;

class ExtraCell3D : public BSExtraData
{
public:
    virtual ~ExtraCell3D();

    NiPointer<NiCell3DNode> m_pController;
};
