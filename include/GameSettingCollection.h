#pragma once

#include "Setting.h"
#include "SettingT_GameSettingCollection_.h"
#include "SETTING_VALUE.h"

#include "SettingCollectionMap.h"

class TESFile;

class GameSettingCollection : public SettingCollectionMap<Setting>
{
public:
    virtual float GetFloat(unsigned int index);
    virtual bool ReadSetting(Setting& setting);
    virtual bool Open(bool create);
    virtual bool Close();
    virtual bool ReadSetting(TESFile* file, const char* key);

    static GameSettingCollection* __cdecl Instance();
    bool GetSetting(const char* key, SettingT_GameSettingCollection_** setting);
    TESFile* GameSettingCollection_File();
    Setting* SettingCollectionMap_Setting_GetPtr(const char* key);
    void SetField108(TESFile* file);
    SETTING_VALUE* __thiscall Bool();
    SETTING_VALUE* __thiscall Int();
    float* Float();

    static SettingT_GameSettingCollection_ iLockLevelMaxVeryEasy;
    static SettingT_GameSettingCollection_ iLockLevelMaxEasy;
    static SettingT_GameSettingCollection_ iLockLevelMaxAverage;
    static SettingT_GameSettingCollection_ iLockLevelMaxHard;
    static SettingT_GameSettingCollection_ iLockLevelMaxVeryHard;
    static SettingT_GameSettingCollection_ fLeveledLockMult;
    static SettingT_GameSettingCollection_ iLockLevelMaxImpossible;
};
