#pragma once

#include "CACHEDRIVE_STATUS.h"

class BSCacheDriveSystemUtility
{
public:
    virtual void* vf00(unsigned int flags);
    virtual void vf04();
    virtual void Destroy();

    bool bIsActive;
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    CACHEDRIVE_STATUS m_eDriveStatus;
    char m_acDrivePath[1055];
    unsigned char layoutPadding42B;
};
