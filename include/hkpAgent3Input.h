#pragma once

#include "hkPadSpu.h"
#include "hkTransform.h"

class hkpCdBody;
class hkpContactMgr;
class hkpProcessCollisionInput;

// src: COMMUNITY
class hkpAgent3Input
{
public:
    // src: COMMUNITY
    hkpAgent3Input() : m_pAdditionalCollidableBody(0) {}

    // src: COMMUNITY
    hkPadSpu<const hkpCdBody*> m_pBodyA;
    // src: COMMUNITY
    hkPadSpu<const hkpCdBody*> m_pBodyB;
    // src: COMMUNITY
    hkPadSpu<const hkpCdBody*> m_pAdditionalCollidableBody;
    // src: COMMUNITY
    hkPadSpu<const hkpProcessCollisionInput*> m_pRayCastInput;
    // src: COMMUNITY
    hkPadSpu<hkpContactMgr*> m_pContactManager;
    // src: COMMUNITY
    hkTransform m_kTransform;
};
