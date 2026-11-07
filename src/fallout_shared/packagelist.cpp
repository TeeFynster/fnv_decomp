// fallout_shared/packagelist.cpp: PackageList, TESAIForm (10 functions)

// This unit also needs ItemsInList, which the shared list declaration lacks.
#include "../../include/BSSimpleList.h"

#include "../../include/BSStringT.h"
#include "../../include/Actor.h"
#include "../../include/BaseProcess.h"
#include "../../include/ExtraDataList.h"
#include "../../include/PerkEntryConditionSet.h"
#include "../../include/Script.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESPackage.h"
#include "packagelist_decls.h"
#include "../../include/PackageList.h"
#include "../../include/TESAIForm.h"

// @fnv 0x0067e400
void PackageList::ClearPackageList()
{
    GetListOfPackages()->RemoveAll();
}

// Copies the package list from src into this form's package list.
// @fnv 0x0047f2d0
void TESAIForm::CopyAIPackageList(const TESAIForm* src)
{
    GetPackageList()->Copy(src->GetPackageList());
}

// Scans the package list for a package whose conditions and schedule match the actor, logs the pick, updates extra data and process state, and returns it.
// @fnv 0x0067e780
TESPackage* PackageList::GetPackageForActor(Actor* actor)
{
    struct PackageSelection
    {
        TESPackage* package;
        DurationData* schedule;
        TESPackage* current;
        BSSimpleList<TESPackage*>* list;
    } selection;
    char message[300];
    selection.list = GetListOfPackages();
    selection.current = 0;
    if (actor)
        selection.current = reinterpret_cast<TESPackage*>(actor->GetCurrentPackage());
    if (!selection.list->IsEmpty())
    {
        selection.package = 0;
        selection.schedule = 0;
        while (selection.list && (selection.package = selection.list->GetItem()))
        {
            if ((selection.package->IsPackageValidForActor(actor) && !selection.package->IsFlag10000Set() &&
                 !selection.package->IsMustReachLocation()) ||
                (selection.package->IsMustReachLocation() &&
                 !actor->GetExtraData()->CanReachPackageLocation(selection.package)))
            {
                selection.schedule = selection.package->TESPackage_GetPackageSchedule();
                if (selection.schedule)
                {
                    bool bCalendarMonth;
                    bool bDayOfMonth;
                    bool bDayOfWeek;
                    bDayOfWeek = false;
                    bDayOfMonth = false;
                    bCalendarMonth = false;
                    if (selection.schedule->FUN_0086a460() + selection.schedule->FUN_00726070() > 24)
                    {
                        bDayOfWeek = selection.package->IsScheduledForDay(true);
                        int yesterday = g_calendar.GetGameHour() - 1;
                        if (yesterday < 0)
                            yesterday = 30;
                        if (selection.schedule->Main_GameReset() == yesterday)
                            bDayOfMonth = true;
                        int lastMonth = g_calendar.GetCurrentMonth() - 1;
                        if (lastMonth < 0)
                            lastMonth = 12;
                        if (selection.schedule->PackageLocation_GetLocType() == lastMonth)
                            bCalendarMonth = true;
                    }
                    if ((selection.schedule->PackageLocation_GetLocType() == -1 ||
                         selection.schedule->PackageLocation_GetLocType() == g_calendar.GetCurrentMonth() || bCalendarMonth) &&
                        (selection.schedule->Main_GameReset() == 0 ||
                         selection.schedule->Main_GameReset() == g_calendar.GetGameHour() || bDayOfMonth) &&
                        (selection.schedule->GetSecondByte() == -1 || selection.package->IsScheduledForDay(false) ||
                         bDayOfWeek) &&
                        (selection.schedule->FUN_0086a460() == -1 ||
                         IsHourInRange(selection.schedule->FUN_0086a460(), selection.schedule->FUN_00726070(),
                                       g_calendar.GetGameTime())))
                    {
                        struct PackageTargetState
                        {
                            PackageTargetRecord* packageTarget;
                            TESObjectREFR* reference;
                        } targetState;
                        targetState.reference = 0;
                        targetState.packageTarget = selection.package->GetTarget();
                        if (targetState.packageTarget)
                            targetState.reference = targetState.packageTarget->GetReferenceTarget();
                        if (selection.package->GetConditions()->ContainsTrait(actor, targetState.reference))
                        {
                            if (Interface_GetTargetREFR() == actor)
                            {
                                sprintf(
                                    message, "%s Picked Package %s (%s)", actor->TESObjectREFR::GetFullName(),
                                    PrepareScriptMessage(g_packageTypeNames[selection.package->GetPackType()], false),
                                    PrepareScriptMessage(selection.package->GetName(), false));
                                DebugLog(message);
                            }
                            if (selection.package->GetProcedureType() == -1)
                                selection.package->SetTargetFromReference(actor->GetLinkedRef());
                            if (selection.current && selection.current != selection.package &&
                                selection.current->GetPackType() == 1)
                            {
                                Actor* leader = dynamic_cast<Actor*>(actor->GetProcess()->GetTarget());
                                if (leader)
                                    leader->GetExtraData()->AddFollowerActor(actor);
                            }
                            if (selection.current && selection.current != selection.package)
                            {
                                Script::GetLocalData(selection.current, actor->GetExtraData(), 0x800);
                                actor->GetProcess()->OnPackageStart(actor, selection.current);
                                actor->GetProcess()->SetProcessModeEnabled(false);
                            }
                            if (selection.package && selection.package != selection.current)
                                Script::GetLocalData(selection.package, actor->GetExtraData(), 0x200);
                            return selection.package;
                        }
                    }
                }
            }
            selection.list = selection.list->GetNext();
        }
    }
    return selection.current;
}

// Scans packages over the coming days/hours, adds those whose schedule matches and are not current or already missed, then sorts the missed list by schedule.
// @fnv 0x0067ec40
void PackageList::CollectEligiblePackages(Actor* actor, BSSimpleList<TESPackage*>* pMissedList, float elapsed,
                                          float startHour)
{
    struct CalendarScan
    {
        float hour;
        int day;
        int currentMonth;
        int month;
        int year;
    } scan;
    struct MissedPackageContext
    {
        int today;
        TESPackage* current;
        BSSimpleList<TESPackage*>* cursor;
    } sortCtx;
    sortCtx.current = 0;
    scan.day = actor->GetProcess()->GetPackedStateBits0To8();
    scan.month = actor->GetProcess()->GetPackedStateBits9To12();
    scan.year = actor->GetProcess()->GetPackedStateBits13To26();
    scan.hour = startHour;
    sortCtx.today = g_calendar.GetGameHour();
    scan.currentMonth = g_calendar.GetCurrentMonth();
    while (scan.day)
    {
        BSSimpleList<TESPackage*>* pList = GetListOfPackages();
        if (actor)
            sortCtx.current = reinterpret_cast<TESPackage*>(actor->GetCurrentPackage());
        if (!pList->IsEmpty())
        {
            TESPackage* pPackage = 0;
            DurationData* pSchedule = 0;
            while (pList && (pPackage = pList->GetItem()))
            {
                if (pPackage->GetMustComplete() && pPackage->HasActorCompletedPackage(actor))
                {
                    pSchedule = pPackage->TESPackage_GetPackageSchedule();
                    if (pSchedule && (pSchedule->PackageLocation_GetLocType() == -1 || pSchedule->PackageLocation_GetLocType() <= scan.month) &&
                        (pSchedule->Main_GameReset() == 0 || pSchedule->Main_GameReset() <= scan.day) &&
                        (pSchedule->GetSecondByte() == -1 ||
                         pSchedule->GetSecondByte() <= g_calendar.GetGameDayOfWeek()) &&
                        (pSchedule->FUN_0086a460() == -1 || pSchedule->FUN_0086a460() < scan.hour) &&
                        pPackage != sortCtx.current && !pMissedList->IsInList(pPackage))
                    {
                        if (pPackage->GetProcedureType() == -1)
                            pPackage->SetTargetFromReference(actor->GetLinkedRef());
                        pMissedList->AddTail(pPackage);
                    }
                }
                pList = pList->GetNext();
            }
            scan.hour += 1.0;
            if (scan.hour > 23.0)
            {
                ++scan.day;
                scan.hour = 0;
                unsigned short usDaysInMonth = GetShortFromTable((signed char)scan.month);
                if (scan.day > usDaysInMonth)
                {
                    scan.day -= usDaysInMonth;
                    ++scan.month;
                    if (scan.month >= 12)
                    {
                        scan.month -= 12;
                        ++scan.year;
                    }
                }
            }
            if (scan.day == sortCtx.today && scan.month == scan.currentMonth &&
                (int)scan.hour >= (int)g_calendar.GetGameTime())
                scan.day = 0;
        }
        else
            scan.day = 0;
    }
    sortCtx.cursor = pMissedList;
    BSSimpleList<TESPackage*>* pNext = 0;
    if (sortCtx.cursor)
    {
        unsigned int iCount = sortCtx.cursor->ItemsInList();
        bool bSwapped = true;
        while (iCount && bSwapped)
        {
            bSwapped = false;
            pNext = sortCtx.cursor;
            while (pNext)
            {
                TESPackage* pPackage1 = sortCtx.cursor->GetItem();
                TESPackage* pPackage2 = pNext->GetItem();
                if (pPackage1->CompareTo(pPackage2->TESPackage_GetPackageSchedule()) == 1)
                {
                    sortCtx.cursor->SetItem(pPackage2);
                    pNext->SetItem(pPackage1);
                    bSwapped = true;
                }
                pNext = pNext->GetNext();
            }
            sortCtx.cursor = sortCtx.cursor->GetNext();
            --iCount;
        }
    }
}

// Resolves each package form ID in the package list to a TESPackage, warning and removing entries that cannot be found.
// @fnv 0x0067e560
void PackageList::InitItem(TESForm* form)
{
    struct PackageResolutionCursor
    {
        BSSimpleList<TESPackage*>* list;
        BSSimpleList<TESPackage*>* previous;
        TESFile* file;
    } cursor;
    cursor.list = GetListOfPackages();
    cursor.previous = 0;
    cursor.file = form ? form->GetFile(-1) : 0;
    while (cursor.list && !cursor.list->IsEmpty())
    {
        struct PackageResolution
        {
            unsigned int formID;
            TESPackage* package;
        } packageEntry;
        packageEntry.formID = reinterpret_cast<unsigned int>(cursor.list->GetItem());
        if (form)
            TESForm::RemapFormIDForFile(packageEntry.formID, cursor.file);
        packageEntry.package = dynamic_cast<TESPackage*>(TESForm::GetFormByID(packageEntry.formID));
        if (!packageEntry.package)
        {
            BSStringT<char> debugName;
            if (form)
                form->GetDebugName(&debugName);
            else
                debugName.Set("UNKNOWN form", 0);
            Warning("MASTERFILE: Could not find Package (%08X) for %s.", packageEntry.formID, debugName.String());
            if (cursor.previous)
            {
                TESPackage* pMissingPackage = reinterpret_cast<TESPackage*>(packageEntry.formID);
                cursor.previous->Remove(pMissingPackage);
                cursor.list = cursor.previous->GetNext();
            }
            else
                cursor.list->RemoveHead();
        }
        else
        {
            cursor.list->SetItem(packageEntry.package);
            cursor.previous = cursor.list;
            cursor.list = cursor.list->GetNext();
        }
    }
}

// Checks whether the integer hour falls within the range from start to start+duration, handling wrap-around past 23.
// @fnv 0x0067e700
bool IsHourInRange(int start, int duration, float hour)
{
    struct TimeRange
    {
        int current;
        int wrapped;
        int end;
    } timeRange;
    timeRange.current = static_cast<int>(hour);
    timeRange.end = start + duration;
    timeRange.wrapped = 0;
    if (timeRange.current == start)
        return true;
    if (timeRange.end > 23)
    {
        timeRange.wrapped = timeRange.end - 24;
        if ((timeRange.current > start || timeRange.current < timeRange.wrapped) && timeRange.current < timeRange.end)
            return true;
    }
    else if (timeRange.current > start && timeRange.current < timeRange.end)
        return true;
    return false;
}

// @fnv 0x0067e440
void PackageList::Copy(const PackageList* src)
{
    struct CopyCursor
    {
        TESPackage* package;
        BSSimpleList<TESPackage*>* list;
    } cursor;
    ClearPackageList();
    cursor.list = src->GetListOfPackages();
    if (!cursor.list->IsEmpty())
    {
        while (cursor.list)
        {
            cursor.package = cursor.list->GetItem();
            AddPackage(cursor.package);
            cursor.list = cursor.list->GetNext();
        }
    }
}

// Appends the given TESPackage to the list returned by GetListOfPackages().
// @fnv 0x0067e420
void PackageList::AddPackage(TESPackage* package)
{
    GetListOfPackages()->AddTail(package);
}

// @fnv 0x0067efd0
// src: XBOX_PDB 0x0067efd0
bool TESPackage::GetMustComplete()
{
    return (packageFlags & 4) ? true : false;
}

// Compares two lists element by element, returning true if they differ or one is exhausted first.
// @fnv 0x0067e4a0
bool PackageList::DiffersFrom(PackageList* other)
{
    unsigned int q;
    unsigned int r;
    BSSimpleList<TESPackage*>* p;
    BSSimpleList<TESPackage*>* s;

    s = GetListOfPackages();
    p = other->GetListOfPackages();
    if (!s->IsEmpty())
    {
        while (s != 0 && s->GetItem() != 0 && p != 0 && p->GetItem() != 0)
        {
            r = reinterpret_cast<unsigned int>(s->GetItem());
            q = reinterpret_cast<unsigned int>(p->GetItem());
            if (r != q)
            {
                return true;
            }
            s = s->GetNext();
            p = p->GetNext();
        }
        if (s != 0 || p != 0)
        {
            return true;
        }
    }
    else
    {
        if (!p->IsEmpty())
        {
            return true;
        }
    }
    return false;
}
