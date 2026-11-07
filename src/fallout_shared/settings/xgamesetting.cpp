// fallout_shared/settings/xgamesetting.cpp: GameSettingCollection, StrArr (9 functions)

#include "xgamesetting_decls.h"
#include "../../../include/GameSettingCollection.h"
#include "../../../include/NiTPrimitiveArray.h"
#include "../../../include/StrArr.h"

// Reads a DATA chunk from the current TESFile and stores its payload into the setting according to the setting's type.
// @fnv 0x004f8860
bool GameSettingCollection::ReadSetting(Setting& setting)
{
    bool result = false;
    if (GameSettingCollection_File())
    {
        TESFile* file = GameSettingCollection_File();
        file->NextChunk();
        if (file->GetChunkID() == 0x41544144)
        {
            switch (setting.Setting_DataType())
            {
            case 3:
                result = file->GetChunkData(&setting.uValue.u);
                break;
            case 5:
                result = file->GetChunkData(&setting.uValue.u);
                break;
            case 6:
                char* buffer = static_cast<char*>(_alloca(file->GetChunkSize()));
                result = file->GetChunkData(buffer, 0);
                setting.SetStringAndPromoteKeyOwnership(buffer);
                break;
            }
        }
    }
    return result;
}

// Reads a setting from the file by key, returning whether a matching setting was found and read, then closes the file.
// @fnv 0x004f89c0
bool GameSettingCollection::ReadSetting(TESFile* file, const char* key)
{
    bool result = false;
    SetField108(file);
    {
        Setting* setting = SettingCollectionMap_Setting_GetPtr(PrepareScriptMessage(key, false));
        if (setting)
            result = ReadSetting(*setting);
    }
    Close();
    return result;
}

// @fnv 0x004f89a0
bool GameSettingCollection::Close()
{
    pFile = 0;
    return true;
}

// @fnv 0x0096a610
void StrArr::AddFirstEmpty(char*& element)
{
    SetAtGrow(m_usSize, element);
}

// @fnv 0x004f8980
bool GameSettingCollection::Open(bool)
{
    return pFile != 0;
}

void __cdecl _Deallocate(void*);
// Retained: the shared setting-collection headers do not declare the destruction
// helpers at 0x00404b40/0x00404b70 needed to compile this matching body.
struct S00404b40
{
    void FUN_00404b70();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00404b70, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00404b40
void* S00404b40::DestroyIfFlagged(unsigned int flags)
{
    FUN_00404b70();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

char* _FUN_00a7d330(char const*);
char* __cdecl NiGetViewerString_00a7d510(char const*, unsigned int);
// Retained: SettingCollectionMap and GameSettingCollection do not yet declare
// the viewer-string helpers at 0x00404fd0 and 0x004f8800, respectively.
struct Base00404fd0
{
    unsigned int GetViewerStrings_00404fd0(NiTPrimitiveArray<unsigned int>*);
};
struct Holder004f8800 : Base00404fd0
{
    unsigned int AddGameSettingsStrings(NiTPrimitiveArray<unsigned int>*);
};
// Adds "GameSettings" and "Total GameSettings" strings to apStrings and returns the count from FUN_00404fd0.
// @fnv 0x004f8800
unsigned int Holder004f8800::AddGameSettingsStrings(NiTPrimitiveArray<unsigned int>* apStrings)
{
    unsigned int I;
    apStrings->AddFirstEmpty((unsigned int)_FUN_00a7d330("GameSettings"));
    I = GetViewerStrings_00404fd0(apStrings);
    apStrings->AddFirstEmpty((unsigned int)NiGetViewerString_00a7d510("Total GameSettings", I));
    return I;
}

struct Pad12
{
    int a;
    int b;
    int c;
};
// Appends element to the array, growing it by m_usGrowBy if full, and returns the index it was stored at.
// @fnv 0x00c4c8d0
unsigned int StrArr::Add(char*& element)
{
    Pad12 pad;
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            FUN_00c4c920(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
}

char* __cdecl FUN_00ec7750(const char* key, const char* name);

// @fnv 0x00c4bd20
// src: COMMUNITY 0x00c4bd20
int __cdecl BSUtilities_GetSequenceFileName(Setting* setting)
{
    int res = 0;
    char* dst;
    const char* n = setting->pKey;
    const char* p = n;
    if (p)
    {
        dst = FUN_00ec7750(p, "_:");
        if (dst)
        {
            dst += 2;
        }
    }
    else
    {
        res = 0;
    }
    return res;
}
