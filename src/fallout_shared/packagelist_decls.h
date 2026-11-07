#include "../../include/PackageTargetRecord.h"
// fallout_shared/packagelist_decls.h: unit-specific schedule, target and calendar declarations
#ifndef FNV_PACKAGELIST_DECLS_H
#define FNV_PACKAGELIST_DECLS_H

class TESFile;
int Warning(const char*, ...);
class DurationData
{
  public:
    int PackageLocation_GetLocType();
    int GetSecondByte();
    char Main_GameReset();
    char FUN_0086a460();
    int FUN_00726070();
};

class Calendar
{
  public:
    int GetCurrentMonth();
    char GetGameHour();
    float GetGameTime();
    int GetGameDayOfWeek();
};
extern Calendar g_calendar;
extern const char* g_packageTypeNames[];
Actor* Interface_GetTargetREFR();
bool IsHourInRange(int, int, float);
unsigned short GetShortFromTable(int);
const char* PrepareScriptMessage(const char*, bool);
void DebugLog(const char*, ...);
extern "C" int __cdecl sprintf(char*, const char*, ...);
#endif
