// fallout_shared/miscstats_decls.h: misc stat data and challenge declarations
#ifndef MISCSTATS_DECLS_H
#define MISCSTATS_DECLS_H

enum
{
    MS_COUNT = 43
};
struct MiscStatEntry
{
    const char* name;
    int value;
};
extern "C" MiscStatEntry* DAT_011c6d50[43];
int StatsMenu_GetClassStatic();
int Warning(const char*, ...);
class TESForm;
#include "../../include/CHALLENGE_TYPE.h"
class ChallengeManager
{
  public:
    static bool UpdateChallengeProgress(CHALLENGE_TYPE, int, TESForm*, TESForm*, unsigned short, unsigned short,
                                        unsigned short);
};
#endif
