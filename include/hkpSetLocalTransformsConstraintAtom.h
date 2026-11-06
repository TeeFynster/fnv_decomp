#pragma once

#include "hkTransform.h"

class hkpSetLocalTransformsConstraintAtom
{
public:
    unsigned short m_type;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    hkTransform m_kBodyALocalFrame;
    hkTransform m_kBodyBLocalFrame;
};
