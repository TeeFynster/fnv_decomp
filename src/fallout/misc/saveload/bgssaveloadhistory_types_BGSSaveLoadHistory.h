// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSSAVELOADHISTORY_H
#define FNV_BGSSAVELOADHISTORY_H

#include <stddef.h>
#include "../../../../include/BSSimpleArray.h"
class SaveLoadChangeHistory;
class SaveLoadFile;
#pragma pack(push, 4)
class SaveLoadChangeHistory
{
  public:
    BSSimpleArray<char*, 1024> Notes;  // +0x0, 16 bytes
    void Load(SaveLoadFile* file);
    void Init();
    bool MatchesHistory(SaveLoadChangeHistory* history);
    void AddNote(const char* format, ...);
    void AddNoteWithArguments(const char* format, char* arguments);
    // SaveLoadChangeHistory
    // void __cdecl SaveLoadChangeHistory::*()
    // void __cdecl SaveLoadChangeHistory::*()
    // void __cdecl SaveLoadChangeHistory::*(const char*, ...)
    // void __cdecl SaveLoadChangeHistory::*(const char*, char*)
    // void __cdecl SaveLoadChangeHistory::*(SaveLoadFile*)
    // void __cdecl SaveLoadChangeHistory::*(SaveLoadFile*)
    // void __cdecl SaveLoadChangeHistory::*(unsigned int)
    // void __cdecl SaveLoadChangeHistory::*(SaveLoadChangeHistory*)
    // unsigned int __cdecl SaveLoadChangeHistory::*()
    // const char* __cdecl SaveLoadChangeHistory::*(unsigned int)
    // SaveLoadChangeHistory& __cdecl SaveLoadChangeHistory::*(const SaveLoadChangeHistory&)
    // void* __cdecl SaveLoadChangeHistory::*(unsigned int)
};
#pragma pack(pop)
typedef char SaveLoadChangeHistorySizeCheck[sizeof(SaveLoadChangeHistory) == 16 ? 1 : -1];
typedef char SaveLoadChangeHistoryNotesOffsetCheck[offsetof(SaveLoadChangeHistory, Notes) == 0 ? 1 : -1];
#endif
