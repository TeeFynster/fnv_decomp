#pragma once

#include "hkReferencedObject.h"
#include "hkaAnimation.h"

class hkxEnvironmentVariable;

class hkxEnvironment : public hkReferencedObject
{
public:
    hkArray<hkxEnvironmentVariable> m_kVariables;
};
