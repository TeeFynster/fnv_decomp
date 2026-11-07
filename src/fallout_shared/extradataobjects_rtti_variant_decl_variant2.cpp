
// src/fallout_shared/extradataobjects_rtti_variant_decl_variant2.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00433db0: the skeleton of src/fallout_shared/extradataobjects_rtti_variant.cpp
// with declarations corrected to what the original code does (extradataobjects_private_packet_rtti_variant.h: class TESObjectREFR { public: virtual ~TESObje -> class TESObjectREFR : public TESForm { public:; extradataobjects_private_packet_rtti_variant.h: TESForm += TESFile* FUN_00484e60(int index);; extradataobjects_additions.h: ExtraDecalRefs += void FUN_004). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/extradataobjects_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESObjectREFR). The skeleton of src/fallout_shared/extradataobjects.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
#include "../../include/BSStringT.h"
#include "../../include/Actor.h"
#include "../../include/BGSQuestObjective.h"
#include "../../include/BSExtraData.h"
#include "../../include/BaseProcess.h"
#include "../../include/ExtraAction.h"
#include "../../include/ExtraCount.h"
#include "../../include/ExtraDecalRefs.h"
#include "../../include/ExtraFactionChanges.h"
#include "../../include/ExtraGlobal.h"
#include "../../include/ExtraGuardedRefData.h"
#include "../../include/ExtraHealth.h"
#include "../../include/ExtraLeveledItem.h"
#include "../../include/ExtraLock.h"
#include "../../include/ExtraMultiBoundData.h"
#include "../../include/ExtraPatrolRefInUseData.h"
#include "../../include/ExtraPersistentCell.h"
#include "../../include/ExtraRagDollData.h"
#include "../../include/ExtraReservedMarkers.h"
#include "../../include/ExtraScript.h"
#include "../../include/ExtraSecuritronFace.h"
#include "../../include/ExtraStartingWorldOrCell.h"
#include "../../include/ExtraUsedMarkers.h"
#include "../../include/ExtraWorn.h"
#include "../../include/GameSettingCollection.h"
#include "../../include/NiPoint3.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/TESEnchantableForm.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESTopic.h"
#include "../../include/NiTArray.h"
#include "extradataobjects_private_packet_rtti_variant_decl_extradataobjects_rtti_variant2.h"
// @fnv 0x00877a30
template <> TESObjectREFR*& NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >::GetAt(unsigned int index)
{
    return m_pBase[index];
}
#include "extradataobjects_additions_decl_extradataobjects_rtti_variant2.h"
int LockExtraData::EnumToNumericValue(LOCK_LEVEL level)
{
    int value = 0;
    switch (level)
    {
    case LOCK_LEVEL_LL_VERYEASY:
        value = GameSettingCollection::iLockLevelMaxVeryEasy.Int()->i;
        break;
    case LOCK_LEVEL_LL_EASY:
        value = GameSettingCollection::iLockLevelMaxEasy.Int()->i;
        break;
    case LOCK_LEVEL_LL_AVERAGE:
        value = GameSettingCollection::iLockLevelMaxAverage.Int()->i;
        break;
    case LOCK_LEVEL_LL_HARD:
        value = GameSettingCollection::iLockLevelMaxHard.Int()->i;
        break;
    case LOCK_LEVEL_LL_VERYHARD:
        value = GameSettingCollection::iLockLevelMaxVeryHard.Int()->i;
        break;
    case LOCK_LEVEL_LL_IMPOSSIBLE:
        value = GameSettingCollection::iLockLevelMaxImpossible.Int()->i;
        break;
    }
    return value;
}
// Copies source into pString, reallocating when needed, and returns whether the resulting string is non-empty.
// @fnv 0x00438470
template <> bool BSStringT<char>::Set(const BSStringT<char>& source)
{
    unsigned int length = source.Length();
    if (length <= MaxLength())
    {
        if (length)
            memcpy(pString, source.String(), length + 1);
        else
        {
            if (pString)
                delete[] pString;
            pString = 0;
            length = 0;
            SetMaxLength(length);
        }
    }
    else
    {
        char* old = pString;
        pString = new char[length + 1];
        memcpy(pString, source.String(), length + 1);
        if (old)
            delete[] old;
        SetMaxLength(length);
    }
    SetLength(length);
    return length != 0;
}

void ResolveFormID(unsigned int*, TESFile*);
TESForm* TESForm_GetFormByNumericID(unsigned int);
void Warning_005b5e40(const char*, ...);
void __cdecl operator delete(void*);

// Walks m_kDecalReferences, resolving each decal's m_pHitReference form ID against the given TESForm and removing entries that cannot be resolved.
// @fnv 0x00433db0
// src: XBOX_PDB 0x00433db0
void ExtraDecalRefs::InitItem_00433db0(TESForm* form)
{
    BSSimpleList<ReferenceIntersectionData*>* position = &m_kDecalReferences;
    BSSimpleList<ReferenceIntersectionData*>* previous = 0;
    while (position && !position->IsEmpty())
    {
        bool removed = false;
        ReferenceIntersectionData* decal = position->GetItem();
        unsigned int formID = reinterpret_cast<unsigned int>(decal->m_pHitReference);
        ResolveFormID(&formID, form->FUN_00484e60(-1));
        TESObjectREFR* resolvedB = dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID(formID));
        if (!resolvedB)
        {
            Warning_005b5e40("MASTERFILE: Unable to find decal reference %08X.", formID);
            if (previous)
            {
                previous->Remove(decal);
                position = previous->GetNext();
            }
            else
            {
                position->RemoveHead();
            }
            delete decal;
            decal = 0;
            removed = true;
        }
        else
        {
            decal->m_pHitReference = resolvedB;
        }
        if (!removed)
        {
            previous = position;
            position = position->GetNext();
        }
    }
}
