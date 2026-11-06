#pragma once

#include "SettingCollectionList.h"
#include "Setting.h"

template <class T> class NiTPrimitiveArray;

class INISettingCollection : public SettingCollectionList<Setting>
{
public:
    INISettingCollection();
    virtual ~INISettingCollection();
    virtual void Add(Setting* setting);
    virtual void Remove(Setting* setting);
    virtual unsigned int GetViewerStrings(NiTPrimitiveArray<char*>* strings);
    virtual bool WriteSetting(Setting& setting);
    virtual bool ReadSetting(Setting& setting);
    virtual bool Open(bool write);
    virtual bool Close();
    virtual bool WriteAllSettings();
    virtual bool ReadAllSettings();

    unsigned char unk04[272];

    void FUN_005e0200(const char*);

    struct Display
    {
        static Setting bDoTestHDR;
    };
};
