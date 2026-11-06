#pragma once

#include "GAMEDATA_STATUS.h"

class BSGameDataSystemUtility
{
public:
    virtual void* vf00(unsigned int flags);
    virtual void vf04();
    virtual void Destroy();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();

    bool bIsActive;
    bool m_bGameDataFlag;
    unsigned short layoutPadding6;
    GAMEDATA_STATUS m_eGameDataStatus;
    char m_acFirstLargeBuffer[1055];
    char m_acSecondaryPath[1055];
    unsigned short layoutPadding84A;
    int m_iBufferValue;
};
