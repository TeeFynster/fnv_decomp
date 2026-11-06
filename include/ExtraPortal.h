#pragma once

#include "BSExtraData.h"
#include "NiAVObject.h"

class BSPortalNode;

class ExtraPortal : public BSExtraData
{
public:
    NiPointer<BSPortalNode> m_pPortalNode;
};
