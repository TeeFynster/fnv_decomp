#pragma once

#include "BSSimpleArray.h"

#include "FootIK_DATA__FootIKSystem_DATA.h"
#include "GrabIK_DATA.h"

class FootIK_DATA__FootIK_Leg_DATA;

class FootIK_DATA
{
public:
    FootIK_DATA();
    ~FootIK_DATA();

    bool bEnabled;
    unsigned char layoutPadding1[3];
    FootIK_DATA__FootIKSystem_DATA m_kRagdollFeedbackData;
    BSSimpleArray<const char*, 1024> m_kFootNames;
    BSSimpleArray<FootIK_DATA__FootIK_Leg_DATA, 1024> m_kLegData;
};
