// fallout_shared/bgsloadedreferencecollection.cpp: LoadedReferenceMap, BGSLoadedReferenceCollection, TESContainer (4 functions)

#include "../../include/LoadedReferenceMap.h"
#include "../../include/TESObjectREFR.h"
#include "bgsloadedreferencecollection.h"
#include "../../include/TESContainer.h"

// Inserts pRef into the map by its form ID if absent, increments iCount and records the current timestamp.
// @fnv 0x00526bd0
bool LoadedReferenceMap::AddReference(TESObjectREFR* pRef)
{
    TESObjectREFR* existing = 0;
    if (GetAt(pRef->GetFormID(), existing))
        return false;

    SetAt(pRef->GetFormID(), pRef);
    iCount++;
    m_uiLastUpdateTime = g_timeGlobal.GetTimeStamp();
    return true;
}


struct TESObjectSTAT;

extern TESObjectSTAT* DAT_011ca264;

TESObjectREFR* __fastcall _FNV_GetObjectReference(TESObjectREFR* object);
unsigned int __fastcall _FNV_GetFormType(TESForm* object);

#include "../../include/BGSLoadedReferenceCollection.h"
// Gets the form type of apRef's base object and adds apRef to the collection's per-type lists based on that type and extra data.
// @fnv 0x005270b0
// src: XBOX_PDB 0x005270b0
void BGSLoadedReferenceCollection::RemoveReference_005270b0(TESObjectREFR* apRef)
{
    unsigned int eformType;

    eformType = _FNV_GetFormType(_FNV_GetObjectReference(apRef));

    if (TESContainer::IsValidContainerType((unsigned char)eformType))
    {
        LoadedReferenceMap* prefMap;

        member18.RemoveSound(reinterpret_cast<TESSound*>(apRef));
        prefMap = reinterpret_cast<LoadedReferenceMap*>(GetFieldByType(eformType));
        if (prefMap)
            reinterpret_cast<BGSLoadedReferenceCollection::ReferenceBucket*>(prefMap)->RemoveSound(reinterpret_cast<TESSound*>(apRef));
    }

    if (eformType == 0x1B)
        member60.RemoveSound(reinterpret_cast<TESSound*>(apRef));

    if (eformType == 0x2A || eformType == 0x2B)
        member78.RemoveSound(reinterpret_cast<TESSound*>(apRef));

    if (_FNV_GetObjectReference(apRef) == reinterpret_cast<void*>(DAT_011ca264))
        member90.RemoveSound(reinterpret_cast<TESSound*>(apRef));

    if (eformType == 0x51)
        member90.RemoveSound(reinterpret_cast<TESSound*>(apRef));

    if (eformType == 0x1C && apRef->GetExtraRadioData())
        memberA8.RemoveSound(reinterpret_cast<TESSound*>(apRef));
}

// @fnv 0x00526b70
LoadedReferenceMap::~LoadedReferenceMap()
{
    RemoveAll();
}
