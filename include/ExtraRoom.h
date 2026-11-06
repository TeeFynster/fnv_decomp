#pragma once

#include "BSExtraData.h"
#include "NiAVObject.h"

class BSRoomNode;

class ExtraRoom : public BSExtraData
{
public:
    NiPointer<BSRoomNode> m_pRoomNode;
};
