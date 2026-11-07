// fallout/misc/saveload/bgssaveloadhistory.cpp: SaveLoadChangeHistory (12 functions)

#include "../../../../include/NiTPointerMap.h"

#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/BGSSaveGameBuffer.h"
#include "../../../../include/BGSSaveLoadChangesMap.h"
#include "../../../../include/CombatTargetMap.h"
#include "../../../../include/SettingT.h"

#include "bgssaveloadhistory_types_BGSSaveLoadHistory.h"
#include "bgssaveloadhistory_types_TaskQueueInterface.h"
#include "bgssaveloadhistory_decls.h"
#include <stdarg.h>
#include <new>

// Calls FUN_009a4250 on the map stored at this object's first pointer with history and returns whether it succeeded.
// @fnv 0x0084aad0
bool SaveLoadChangeHistory::MatchesHistory(SaveLoadChangeHistory* history)
{
    if (reinterpret_cast<BGSSaveLoadChangesMap*>(*reinterpret_cast<void**>(this))
            ->FUN_009a4250(reinterpret_cast<unsigned int>(history)))
        return true;
    return false;
}

// @fnv 0x0084dff0
void SaveLoadChangeHistory::AddNote(const char* format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    AddNoteWithArguments(format, arguments);
    va_end(arguments);
}

// Clears the field at offset 0xd68 and removes all entries from the BSSimpleList at offset 0x5fc.
// @fnv 0x00848e10
void SaveLoadChangeHistory::Init()
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0xd68) = 0;
    reinterpret_cast<BSSimpleList<ActorCause*>*>(reinterpret_cast<char*>(this) + 0x5fc)->RemoveAll();
}

// Calls FUN_0084c2a0 twice, with (0, 12) and (1000, 1001), passing flags through to each call.
// @fnv 0x0084c270
void BGSSaveLoadHistory_Destroy(unsigned char flags)
{
    BGSSaveLoadGlobalData_RevertGlobalDataRange(0, 12, flags);
    BGSSaveLoadGlobalData_RevertGlobalDataRange(1000, 1001, flags);
}

// @fnv 0x0084e020
void SaveLoadChangeHistory::AddNoteWithArguments(const char* format, char* arguments)
{
    BGSSaveLoadHistoryNoteLocals locals;
    int length;
    if (!*reinterpret_cast<unsigned char*>(reinterpret_cast<Setting*>(0x11de0a4)->Bool()))
        return;
    length = BSvsprintf(locals.buffer, format, arguments);
    if (length > 0)
    {
        locals.allocation = static_cast<char*>(::operator new(length + 1));
        locals.note = locals.allocation;
        TaskQueueInterface::CopyStringToBuffer(locals.note, length + 1, locals.buffer);
        reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&Notes)->Add(reinterpret_cast<NavMeshInfo*&>(locals.note));
    }
}

// Reads a count and that many strings from a BGSLoadGameBuffer and appends each to the Notes array.
// @fnv 0x0084e190
void SaveLoadChangeHistory::Load(SaveLoadFile* file)
{
    BGSLoadGameBuffer buffer;
    buffer.ReadAndVerifySize(file);
    {
        BGSLoadGameBuffer* pBuffer = &buffer;
        {
            unsigned int count = 0;
            pBuffer->ReadTypedData(static_cast<void*>(&count), 4);
            for (unsigned int i = 0; i < count; i++)
            {
                char* note = pBuffer->LoadString(0);
                reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&Notes)->Add(
                    reinterpret_cast<NavMeshInfo*&>(note));
            }
        }
    }
}

struct HArr
{
    HArr();
    ~HArr();
    void GrowCapacity(unsigned int);
};
struct FUN_0084ded0 : public HArr
{
    FUN_0084ded0();
};
// @fnv 0x0084ded0
FUN_0084ded0::FUN_0084ded0()
{
    GrowCapacity(0x40);
}

struct FUN_0084e2c0_shell : public SaveLoadChangeHistory
{
    void AddAllNotes(SaveLoadChangeHistory*);
};

struct HH84
{
    unsigned int GetReferenceFlags();
    const char* GetArrayElement(unsigned int);
};
// Iterates over the history's entry count, retrieves each string by index and passes it to AddNote.
// @fnv 0x0084e2c0
void FUN_0084e2c0_shell::AddAllNotes(SaveLoadChangeHistory* apHistory)
{
    unsigned int icount = reinterpret_cast<HH84*>(apHistory)->GetReferenceFlags();
    for (unsigned int i = 0; i < icount; i++)
    {
        const char* pNote = reinterpret_cast<HH84*>(apHistory)->GetArrayElement(i);
        AddNote(pNote);
    }
}

extern int _data_011c16bc;
struct FUN_00822630
{
    ~FUN_00822630();
};
struct FUN_0084df30 : FUN_00822630
{
    void DeleteAllElements();
    ~FUN_0084df30();
};
// @fnv 0x0084df30
FUN_0084df30::~FUN_0084df30()
{
    DeleteAllElements();
}

// Exe 0x0084df90: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct BgssaveloadhistoryOffset08View
{
    unsigned int GetFlags();
};
struct _Mem_20a4
{
    void SetSize(unsigned int, bool);
};
struct FUN_0084df90_shell : BgssaveloadhistoryOffset08View
{
    unsigned int& GetAt(int);
    void DeleteAllElements();
};
// Deletes each element returned by GetAt up to GetFlags, then resets the container size to 0.
// @fnv 0x0084df90
void FUN_0084df90_shell::DeleteAllElements()
{
    for (unsigned int i = 0; i < GetFlags(); i++)
        delete reinterpret_cast<void*>(GetAt(i));
    reinterpret_cast<_Mem_20a4*>(this)->SetSize(0, false);
}

struct FUN_0084e250_shell
{
    int GetReferenceFlags();
    unsigned int& GetAt(int);
    void UpdateEntryValue(unsigned int, unsigned int);
    void DeleteItemsFrom(unsigned int count);
};

void __cdecl operator delete(void*);

// @fnv 0x0084e250
void FUN_0084e250_shell::DeleteItemsFrom(unsigned int uiStartIndex)
{
    int size = GetReferenceFlags();
    if (uiStartIndex >= (unsigned int)size)
        return;
    for (unsigned int i = uiStartIndex; i < (unsigned int)size; ++i)
    {
        void* item = (void*)GetAt(i);
        operator delete(item);
    }
    UpdateEntryValue(uiStartIndex, (unsigned int)size - uiStartIndex);
}

// 0x00865e70 is SaveGameString; this view iterates history note strings, not NavMeshInfo objects.
class HistoryNotesView
{
  public:
    unsigned int GetSize();
    char*& GetAt(int iIndex);
    void SaveTo(SaveLoadFile* pkTarget);
};

// Saves the note count and each string into a BGSSaveGameBuffer, then writes the buffer to pkTarget.
// @fnv 0x0084e0d0
void HistoryNotesView::SaveTo(SaveLoadFile* pkTarget)
{
    BGSSaveGameBuffer kBuffer;
    BGSSaveGameBuffer* pkBuffer6 = &kBuffer;

    unsigned int ItemUpdateArray = GetSize();
    pkBuffer6->SaveData(static_cast<void*>(&ItemUpdateArray), 4, 0);
    for (unsigned int uiIndex = 0; uiIndex < ItemUpdateArray; uiIndex++)
    {
        char* note = GetAt(uiIndex);
        pkBuffer6->SaveGameString(static_cast<const char*>(note), 0);
    }

    kBuffer.Save(pkTarget);
}
