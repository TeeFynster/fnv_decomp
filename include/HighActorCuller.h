#pragma once

#include "MobIterOperator.h"
#include "BSFadeNodeCuller.h"
#include "NiAVObject.h"

class BSMultiBoundNode;
class BSMultiBound;
class BSMultiBoundSphere;

class HighActorCuller : public MobIterOperator
{
public:
    virtual void Operate(MobileObject* mobile);

    BSFadeNodeCuller m_kFadeNodeCuller;
    NiPointer<BSMultiBoundNode> m_pMultiBoundNode;
    NiPointer<BSMultiBound> m_pMultiBound;
    NiPointer<BSMultiBoundSphere> m_spMultiBoundSphere;
};
