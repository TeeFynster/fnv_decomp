#pragma once

#include "hkpAction.h"

class hkpEntity;

class hkpUnaryAction : public hkpAction
{
public:
    static const ClassMemberDescriptor Members[];

    hkpUnaryAction(hkpEntity* entity, unsigned int userData);
    hkpUnaryAction(FinishingFlag flag);

    hkpEntity* m_pEntity;
};
