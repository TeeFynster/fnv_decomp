#pragma once

#include "SETTING_VALUE.h"
#include "Setting.h"

class GameSettingCollection;
// src: XBOX_PDB (SettingT<INISettingCollection>, INIPrefSettingCollection and GameSettingCollection: 12 bytes).
// PC RTTI 0x01017720 derives SettingT<INISettingCollection> only from Setting.
template <class T> class SettingT : public Setting
{
public:
    SettingT(const char* key, float value);
    SettingT(const char* key, int value);
    SettingT(const char* key, char* value);
    static T* __cdecl GetCollection();
    virtual ~SettingT();
    float GetFloatValue();
protected:
    static T* ms_pCollection; // exe 0x011f96a0 (INI), 0x011f35a0 (preferences)
    static void EnsureCollection(); // exe 0x0044f570 / 0x004de4a0
};

// RTTI .?AV?$SettingT@VGameSettingCollection@@@@: one base, Setting; 0xC like Setting.
template <> class SettingT<GameSettingCollection> : public Setting
{
public:
    SettingT(const char* key, float value);
    SettingT(const char* key, int value);
    SettingT(const char* key, char* value);
    virtual ~SettingT();
    static GameSettingCollection* __cdecl GetCollection();
    float GetFloatValue();
};
