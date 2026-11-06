#pragma once

#include "hkVector4.h"

class hkpShapeRayCastOutput
{
public:
    hkVector4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    union
    {
        int m_auiShapeKeys[2];
        struct
        {
            int unk18;
            int unk1C;
        };
    };
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    int unk44;
    int unk48;
    int unk4c;

    hkpShapeRayCastOutput()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeys[0] = 0xffffffff;
        m_uiShapeKeyIndex = 0;
    }

    void reset()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeys[0] = 0xffffffff;
        m_uiShapeKeyIndex = 0;
    }
};
