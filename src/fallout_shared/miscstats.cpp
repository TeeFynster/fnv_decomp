// fallout_shared/miscstats.cpp: MiscStatManager (5 functions)

#include "../../include/Menu.h"
#include "../../include/StatsMenu.h"
#include "../../include/Tile.h"
#include "miscstats_decls.h"
#include "../../include/BGSSaveGameBuffer.h"

// @fnv 0x004d5e10
void AddMiscStat(MiscStatManager::MiscStat eStat, int delta)
{
    if (delta == 0)
        return;
    if (eStat < MS_COUNT && DAT_011c6d50[eStat])
    {
        DAT_011c6d50[eStat]->value += delta;
        ChallengeManager::UpdateChallengeProgress(CHALLENGE_TYPE_CHALLENGE_TYPE_MISC_STAT, delta, 0, 0, (unsigned short)eStat, 0, 0);
        StatsMenu* menu = (StatsMenu*)((Tile*)Tile::FindMenuById(StatsMenu_GetClassStatic()))->GetMenu();
        if (menu)
            menu->RefreshMiscStat(eStat);
    }
    else
    {
        Warning("MENUS: Unable to modify miscellaneous stat (id=%d) by %d.", eStat, delta);
    }
}

// Copies each of the 0x2B ints from a1 into the second int field of the object pointed to by DAT_011c6d50[i].
// @fnv 0x004d5f20
void CopyIntArrayToObjects(int* aiValues)
{
    for (int i = 0; i < 0x2B; ++i)
        ((int*)DAT_011c6d50[i])[1] = aiValues[i];
}

// Copies the second int of each of 43 entries from DAT_011c6d50 into the array pointed to by a1.
// @fnv 0x004d5f60
void CopyEntrySecondFields(int* paiOut)
{
    for (int i = 0; i < 43; ++i)
        paiOut[i] = ((int*)DAT_011c6d50[i])[1];
}

extern MiscStatEntry* DAT_011c6d50[];

// Writes the misc stat count (43) and each stat's value from DAT_011c6d50 to the save buffer, using 0 for null entries.
// @fnv 0x004d5fa0
void SaveMiscStats(BGSSaveGameBuffer* pSave)
{
    int nCount = 43;
    pSave->SaveData((void*)&nCount, 4, 0);
    unsigned int i = 0;
    for (; i < (unsigned int)nCount; ++i)
    {
        int nVal;
        if (DAT_011c6d50[i])
            nVal = *(int*)((char*)DAT_011c6d50[i] + 4);
        else
            nVal = 0;
        int iSaveValue = nVal;
        pSave->SaveData((void*)&iSaveValue, 4, 0);
    }
}

extern const char* DAT_01189280[];

void FNV_Warning(const char* format, ...);
void FUN_007dc0a0(int* a1);
int BSstricmp(const char* a1, const char* a2);

// Searches the 0x2b-entry misc stat name table for a1 and returns its index, or warns and returns 0x2b if not found.
// @fnv 0x004d5eb0
int FindMiscStatIndex(const char* pcStatName)
{
    int i;

    for (i = 0; i < 0x2b; FUN_007dc0a0(&i))
    {
        if (DAT_01189280[i] != 0 && BSstricmp(DAT_01189280[i], pcStatName) == 0)
        {
            return i;
        }
    }
    FNV_Warning("MENUS: Miscellaneous stat %s could not be found.  Returning MS_COUNT.", pcStatName);
    return 0x2b;
}
