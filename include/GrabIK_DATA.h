#pragma once

#include "BSSimpleArray.h"

class GrabIK_DATA__GrabIK_Arm_DATA;

class GrabIK_DATA
{
public:
    GrabIK_DATA();
    ~GrabIK_DATA();

    bool bEnabled;
    unsigned char layoutPadding1[3];
    BSSimpleArray<const char*, 1024> m_kGrabNames;
    BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024> m_kGrabArmData;
};
