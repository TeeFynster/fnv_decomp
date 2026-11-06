#pragma once

#include "BSSimpleArray.h"
#include "FootIK_DATA.h"

class LookIK_DATA__LookIK_Head_DATA;

class LookIK_DATA
{
public:
    LookIK_DATA();
    ~LookIK_DATA();

    bool bEnabled;
    unsigned char layoutPadding1[3];
    BSSimpleArray<const char*, 1024> m_kLookNames;
    BSSimpleArray<LookIK_DATA__LookIK_Head_DATA, 1024> m_kHeadData;
};
