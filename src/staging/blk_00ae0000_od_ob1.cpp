
// src/staging/blk_00ae0000_od_ob1.cpp - STAGING flag-variant unit created 2026-10-17: functions whose bytes need /Od /Ob1 WITHOUT /GF (00afb190 pushes a
// non-pooled "Data\\" copy, so it is not from archive.cpp, which is /GF). Not a real source path.

#include "../../include/layout_support.h"

extern bool DAT_011acdf9;
int __cdecl _strcpy_s(char*, unsigned int, const char*);
int __cdecl _strcat_s(char*, unsigned int, const char*);
int __cdecl FUN_00ecbf05(const char* path, int mode);
struct FUN_00afb190_entry
{
    unsigned int uiHashLow;
    unsigned int uiHashHigh;
    unsigned int uiSizeFlags;
    unsigned int uiElapsedMilliseconds;

    bool IsChecked() const
    {
        return (uiSizeFlags & 0x80000000) ? true : false;
    }
    void SetChecked(bool b)
    {
        b ? (uiSizeFlags |= 0x80000000) : (uiSizeFlags &= ~0x80000000);
    }
    void SetOffset(unsigned int o)
    {
        uiElapsedMilliseconds = (o & 0x7fffffff) | (uiElapsedMilliseconds & 0x80000000);
    }
};
struct FUN_00afb190_shell
{
    bool Archive_CheckInvalidateFile(FUN_00afb190_entry* entry, const char* name);
};
// @fnv 0x00afb190
// src: COMMUNITY 0x00afb190
bool FUN_00afb190_shell::Archive_CheckInvalidateFile(FUN_00afb190_entry* entry, const char* name)
{
    char path[0x104];
    if (DAT_011acdf9 && !entry->IsChecked())
    {
        if (name)
        {
            _strcpy_s(path, 0x104, "Data\\");
            _strcat_s(path, 0x104, name);
            if (FUN_00ecbf05(path, 0) != -1)
            {
                entry->SetOffset(0);
                return true;
            }
        }
        entry->SetChecked(true);
    }
    return false;
}

// @fnv 0x00af2d30
// src: GUESS 0x00af2d30 (confidence: high)
void Runtime_DoNothing()
{}
