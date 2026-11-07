#pragma once

#include "SETTING_VALUE.h"
#include "Setting.h"

#include "SettingT.h"

// Stand-in still used by many units for a SettingT<GameSettingCollection> global (to be moved onto the class above).

class SettingT_GameSettingCollection_
{
public:
    char pad[12];

    SettingT_GameSettingCollection_();
    ~SettingT_GameSettingCollection_();

    SETTING_VALUE* Float();
    SETTING_VALUE* Bool();
    SETTING_VALUE* Int();
    const char* String();

    bool* FUN_00408d60();
    int* Setting_Int();
    const char* FUN_00403df0();
};
