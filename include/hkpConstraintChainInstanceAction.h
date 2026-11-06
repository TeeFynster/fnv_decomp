#pragma once

#include "hkpAction.h"

class hkpConstraintInstance;
class hkpConstraintChainInstance;

class hkpConstraintChainInstanceAction : public hkpAction
{
public:
    hkpConstraintChainInstanceAction(hkpConstraintInstance* pkInstance) throw();
    virtual ~hkpConstraintChainInstanceAction() throw();

    hkpConstraintChainInstance* m_pConstraintChainInstance;
};
