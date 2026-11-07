// fallout/misc/calendar.cpp: Calendar, CalendarProxy, CalendarDateFormatter, Thing (17 functions)

#include "../../../include/BSSimpleArray.h"
#include "calendar_types_CALENDAR_MONTH.h"
#include "calendar_types_DAYS_OF_THE_WEEK.h"
#include "calendar_types_Calendar.h"
#include "calendar_decls.h"
#include "../../../include/StartMenu.h"

// @fnv 0x0086a460
char Calendar::GetGameHour()
{
    return ((const char*)this)[3];
}

// @fnv 0x00867950
float Calendar::GetGameTimeScale()
{
    return reinterpret_cast<TESGlobalValueReader*>(pHourGlobal)->GetValue();
}

// @fnv 0x00867ef0
DAYS_OF_THE_WEEK Calendar::GetGameDayOfWeek()
{
    return (DAYS_OF_THE_WEEK)(GetGameDaysPassed() % 7);
}

// @fnv 0x00867d60
int Calendar::GetDayOfMonth()
{
    return (int)(m_pDayGlobal ? reinterpret_cast<TESGlobalValueReader*>(m_pDayGlobal)->GetValue() : 17.0f);
}

// @fnv 0x00450d80
void Calendar::ResetCachedValues()
{
    *((unsigned int*)((char*)this + 0x24)) = 0x7fffffff;
    *((unsigned int*)((char*)this + 0x28)) = 0x7fffffff;
    *((unsigned int*)((char*)this + 0x2c)) = 0x7fffffff;
    *((unsigned int*)((char*)this + 0x30)) = 0x7fffffff;
    *((unsigned int*)((char*)this + 0x48)) = 0x7fffffff;
    *((unsigned int*)((char*)this + 0x4c)) = 0x7fffffff;
}

// Returns the game days passed as an unsigned int from the global value reader, or 1 if the reader is null.
// @fnv 0x00867de0
unsigned int Calendar::GetGameDaysPassed()
{
    return (unsigned int)(m_pGameDaysPassedGlobal
                              ? reinterpret_cast<TESGlobalValueReader*>(m_pGameDaysPassedGlobal)->GetValue()
                              : 1.0f);
}

// Returns the value read from the global value reader if present, otherwise 12.0f.
// @fnv 0x00867da0
float Calendar::GetGameTime()
{
    return m_pHourGlobal ? reinterpret_cast<TESGlobalValueReader*>(m_pHourGlobal)->GetValue() : 12.0f;
}

// Returns the month from the calendar's global value reader, or August when no reader is set.
// @fnv 0x00867d20
CALENDAR_MONTH Calendar::GetCurrentMonth()
{
    return m_pMonthGlobal ? (CALENDAR_MONTH)(char)reinterpret_cast<TESGlobalValueReader*>(m_pMonthGlobal)->GetValue()
                          : CALENDAR_MONTH_MONTH_AUGUST;
}

// @fnv 0x00867e30
unsigned int Calendar::GetGameHoursPassed()
{
    float fDays =
        m_pGameDaysPassedGlobal ? reinterpret_cast<TESGlobalValueReader*>(m_pGameDaysPassedGlobal)->GetValue() : 1.0f;
    return (unsigned int)floor(fDays * 24.0);
}

// Advances the calendar clock by afDeltaTime, rolling hours into days, months and years and updating the related global values.
// @fnv 0x00867a40
void Calendar::Update(float afDeltaTime)
{
    float fHour;
    float fHoursPassed = reinterpret_cast<TESGlobalValueReader*>(pHourGlobal)->GetValue() * afDeltaTime / DAT_01012640;
    fHour = reinterpret_cast<TESGlobalValueReader*>(m_pHourGlobal)->GetValue() + fHoursPassed;

    if (!(DAT_011de7e8 & 1))
    {
        DAT_011de7e8 |= 1;
        DAT_011de7e4 = fHour;
    }

    if (bUnknown1C || DAT_011de7e4 + 1.0 < fHour)
    {
        int iDays = (int)reinterpret_cast<TESGlobalValueReader*>(m_pGameDaysPassedGlobal)->GetValue();
        m_pGameDaysPassedGlobal->SetValue((float)(iDays + fHour / 24.0));
        bUnknown1C = false;
    }

    if (fHour > 24.0)
    {
        float fDay = reinterpret_cast<TESGlobalValueReader*>(m_pDayGlobal)->GetValue();
        float fMonth = reinterpret_cast<TESGlobalValueReader*>(m_pMonthGlobal)->GetValue();
        float fYear = reinterpret_cast<TESGlobalValueReader*>(m_pYearGlobal)->GetValue();
        unsigned short usDaysInMonth = GetShortFromTable((char)fMonth);

        while (fHour > 24.0)
        {
            fHour -= 24.0;
            fDay += 1.0;
        }

        if (usDaysInMonth < fDay)
        {
            fDay -= usDaysInMonth;
            fMonth += 1.0;
            if (fMonth >= 12.0)
            {
                fMonth -= 12.0;
                fYear += 1.0;
                m_pYearGlobal->SetValue(fYear);
            }
            m_pMonthGlobal->SetValue(fMonth);
        }
        m_pDayGlobal->SetValue(fDay);
        m_uiDaysPassed++;
    }

    m_pGameDaysPassedGlobal->SetValue(
        (float)(reinterpret_cast<TESGlobalValueReader*>(m_pGameDaysPassedGlobal)->GetValue() + fHoursPassed / 24.0));
    DAT_011de7e4 = fHour;
    m_pHourGlobal->SetValue(fHour);
}

struct FUN_00867c60_shell : public Calendar
{
    unsigned int Calendar_GetYear();
};

// Returns the value read by the TESGlobalValueReader stored at the start of the object, or 77.0f when that pointer is null.
// @fnv 0x00867c60
// src: XBOX_PDB 0x00867c60
unsigned int FUN_00867c60_shell::Calendar_GetYear()
{
    return (int)(*(TESGlobalValueReader**)this ? (*(TESGlobalValueReader**)this)->GetValue() : 77.0f);
}

struct FUN_008aced0_cv
{
    char pad[0x44];
    unsigned int flags;
};
struct FUN_008aced0_cls
{
    char pad[0x2c];
    FUN_008aced0_cv* cached;
    bool HasCachedFlag(unsigned int aeWhich);
};
// Returns true when cached is non-null and its flags contain the bit(s) in aeWhich, otherwise false.
// @fnv 0x008aced0
bool FUN_008aced0_cls::HasCachedFlag(unsigned int aeWhich)
{
    return cached ? (cached->flags & aeWhich) != 0 : false;
}

// @fnv 0x00867a20
// src: XBOX_PDB 0x00867a20
void __fastcall Menu_SetRenderedMenu(void* aThis)
{
    *(char*)((char*)aThis + 0x1C) = 1;
}

extern StartMenu* DAT_011895b8[7];
struct CalendarProxy : public Calendar
{
    const char* GetDayName();
};
// Gets the current day of the week, returns its name from DAT_011895b8, or "Bad Day" if the day is invalid.
// @fnv 0x00867f10
const char* CalendarProxy::GetDayName()
{
    DAYS_OF_THE_WEEK eday;
    eday = GetGameDayOfWeek();
    if (eday != DAYS_OF_THE_WEEK_DAY_NONE && eday < DAYS_OF_THE_WEEK_DAY_COUNT)
        return static_cast<const StartMenu*>(DAT_011895b8[eday])->GetMenuTitle();
    return "Bad Day";
}

extern double DAT_01012638;
struct FUN_00526ac0_shell
{
    float BSMultiBoundCapsule_QMultiBoundRadius();
};
struct FUN_00867ea0_shell
{
    char _pad[16];
    FUN_00526ac0_shell* m_ptr;
    float Calendar_GetMinutesPassed();
};
// @fnv 0x00867ea0
// src: COMMUNITY 0x00867ea0
float FUN_00867ea0_shell::Calendar_GetMinutesPassed()
{
    float days = m_ptr ? m_ptr->BSMultiBoundCapsule_QMultiBoundRadius() : 1.0f;
    return days * 24.0 * DAT_01012638;
}

// Calendar: format the current game date as "MM.DD.YY".

class DateString
{
  public:
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    DateString();
    DateString(const DateString& kOther);
    ~DateString();
    int PrintfString(const char* pFormat, ...);
};

struct CalendarDateFormatter : public Calendar
{
    unsigned int GetYearNumber();
    char GetDayNumber();
    int GetMonthIndex();
    DateString FormatDate();
};

// Builds a DateString formatted as "%02d.%02d.%02d" from the month index plus one, day number, and year modulo 100, and returns it.
// @fnv 0x00867970
DateString CalendarDateFormatter::FormatDate()
{
    DateString kDate;
    kDate.PrintfString("%02d.%02d.%02d", GetMonthIndex() + 1, GetDayNumber(), GetYearNumber() % 100);
    return kDate;
}

struct Thing
{
    int FUN_00867d20();
    int Calendar_GetSeason();
};

// Maps values 0 through 11 to results 0 through 3 using a switch.
// @fnv 0x00867ca0
// src: COMMUNITY 0x00867ca0
int Thing::Calendar_GetSeason()
{
    int result = 0;
    switch (FUN_00867d20())
    {
    case 0:
    case 1:
    case 11:
        result = 3;
        break;
    case 2:
    case 3:
    case 4:
        result = 0;
        break;
    case 5:
    case 6:
    case 7:
        result = 1;
        break;
    case 8:
    case 9:
    case 10:
        result = 2;
        break;
    }
    return result;
}
