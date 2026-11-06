#pragma once

#include "BSExtraData.h"
#include "NiAVObject.h"

class BSMultiBoundNode;

class ExtraMultiBound : public BSExtraData
{
public:
    NiPointer<BSMultiBoundNode> m_kMultiBoundNode;
};
