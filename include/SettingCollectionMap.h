#pragma once

#include "Setting.h"

class TESFile;

// RTTI: SettingCollectionMap<Setting> : SettingCollection<Setting>, vftable 0x0101215c (10 slots; slot 1 0x00404de0 is
// the add-setting body); GameSettingCollection (0x120 bytes) derives from it. The SettingCollection part is the vtable,
// the 260-byte file name and the file (0x10c bytes); the setting map follows at 0x10c.
template <class T>
class SettingCollectionMap
{
public:
    virtual void vfn_0();
    virtual void v1(void*);
    virtual void vfn_8();
    virtual float GetFloat(unsigned int index);
    virtual void vfn_10();
    virtual bool ReadSetting(T& setting);
    virtual bool Open(bool create);
    virtual bool Close();
    virtual void vfn_20();
    virtual void vfn_24();

    char szFileName[260];
    TESFile* pFile;

    void __thiscall AddSetting(T* setting);
    unsigned int GetViewerStrings_00404fd0(NiTPrimitiveArray<char*>*);
};
