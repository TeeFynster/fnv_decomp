#pragma once

#include "hkVector4.h"

class hkpWorldRayCastOutput
{
public:
    hkVector4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    const void* m_pRootCollidable;

    hkpWorldRayCastOutput()
    {
        reset();
    }

    void reset()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeys[0] = static_cast<unsigned int>(-1);
        m_uiShapeKeyIndex = 0;
        m_pRootCollidable = 0;
    }

    bool DidHit() const
    {
        return m_pRootCollidable != 0;
    }
};
