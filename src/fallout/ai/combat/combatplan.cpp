#include "../../../../include/CombatPlan.h"

// src/fallout/ai/combat/combatplan.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatplan.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00994860_obj
{
    bool __thiscall ContainsValue(int);
};


// Returns the result of ContainsValue(aiAction) on the object at offset 0xa0, or false if that pointer is null.
// @fnv 0x00981940
// src: XBOX_PDB 0x00981940
bool __thiscall CombatPlan::CombatController_CombatPlanContainsAction(int aiAction)
{
    if (*reinterpret_cast<FUN_00994860_obj**>(reinterpret_cast<char*>(this) + 0xa0))
        return (*reinterpret_cast<FUN_00994860_obj**>(reinterpret_cast<char*>(this) + 0xa0))->ContainsValue(aiAction);
    return false;
}

struct Entry
{
    int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct StreamReader
{
    void ReadBytes(void* dst, unsigned int size);
};

int __cdecl ConvertFlagToValue(bool flag);
int __cdecl FinishValue(bool flag);

class FUN_009949a0_cls
{
  public:
    Entry** m_entries;
    unsigned int m_uiItemCount;
    unsigned int unk08;
    int unk0C;

    void AllocEntries(unsigned int count);
    void ReadFromStream(StreamReader* reader);
};

// Reads a count, allocates entries and fills each from the stream, then reads a trailing value and flag into unk08 and unk0C.
// @fnv 0x009949a0
void FUN_009949a0_cls::ReadFromStream(StreamReader* reader)
{
    reader->ReadBytes(&m_uiItemCount, 4);
    AllocEntries(m_uiItemCount);

    for (unsigned int uiIndex = 0; uiIndex < m_uiItemCount; ++uiIndex)
    {
        Entry* entry = m_entries[uiIndex];
        bool flag = false;
        reader->ReadBytes(&flag, 1);
        reader->ReadBytes(&entry->unk0C, 4);
        entry->unk00 = ConvertFlagToValue(flag);
        entry->unk04 = 0;
        entry->unk08 = 0;
    }

    reader->ReadBytes(&unk08, 4);
    bool last = false;
    reader->ReadBytes(&last, 1);
    unk0C = FinishValue(last);
}
