
// src/fallout_shared/extradataobjects_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESObjectREFR). The skeleton of src/fallout_shared/extradataobjects.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "../../include/BSStringT.h"
#include "../../include/BSSimpleList.h"
#include "../../include/NiTArray.h"
#include "../../include/Actor.h"
#include "../../include/BSExtraData.h"
#include "../../include/BaseProcess.h"
#include "../../include/ExtraAction.h"
#include "../../include/ExtraCount.h"
#include "../../include/ExtraFactionChanges.h"
#include "../../include/ExtraGlobal.h"
#include "../../include/ExtraGuardedRefData.h"
#include "../../include/ExtraLeveledItem.h"
#include "../../include/LitWaterRefList.h"
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
#include "../../include/PlayerCharacter.h"
#include "../../include/TESEnchantableForm.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESTopic.h"
#include "../../include/ExtraDataList.h"
#include "../../include/ExtraLitWaterRefs.h"
void* __cdecl operator new[](unsigned int size);
void __cdecl operator delete[](void* pointer);
extern "C" void* __cdecl memcpy(void* destination, const void* source, unsigned int size);
// @fnv 0x00877a30
template <> TESObjectREFR*& NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >::GetAt(unsigned int index)
{
    return m_pBase[index];
}
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

// This call site passes an owner and a flag; the shared reference header only
// declares the zero-argument form. Inherit the shared layout and supply just
// the missing call declaration needed by the original /Od code.
class LitWaterReference : public TESObjectREFR
{
public:
    ExtraDataList* BSFile_GetDevice(TESForm* owner, bool flag);
};

void __cdecl ResolveFormID(unsigned int* apFormID, TESFile* apFile);
TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int auiFormID);
void __cdecl FNV_Warning(const char* apFormat, ...);

// Shared ExtraLitWaterRefs.h lacks FUN_00434050 (0x00434050, also bound by extradatalist.cpp); retain the real layout locally until it is declared.
class BSExtraDataEx;


// @fnv 0x00434050
// src: XBOX_PDB 0x00434050
void ExtraLitWaterRefs::InitItem_00434050(TESForm* apOwner)
{
    BSSimpleList<TESObjectREFR*>* pNodeB8 = &kRefs;
    BSSimpleList<TESObjectREFR*> kResolved4;
    while (pNodeB8 && !pNodeB8->IsEmpty())
    {
        TESObjectREFR* pItem3 = pNodeB8->GetItem();
        unsigned int auiFormId = (unsigned int)pItem3;
        ResolveFormID(&auiFormId, apOwner->GetFile(-1));
        TESObjectREFR* pRef = dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID(auiFormId));
        if (!pRef || !pRef->GetReferencePersistence())
        {
            if (!pRef)
                FNV_Warning("MASTERFILE: Unable to find lit water reference %08X.", auiFormId);
            else
                FNV_Warning(
                    "MASTERFILE: Reference %08X is not persistent so cannot reflect or refract other references.",
                    auiFormId);
        }
        else
        {
            static_cast<LitWaterReference*>(pRef)->BSFile_GetDevice(apOwner, true)->FUN_0041f840();
            kResolved4.AddHead(pRef);
        }
        pNodeB8 = pNodeB8->GetNext();
    }
    kRefs.RemoveAll();
    BSSimpleList<TESObjectREFR*>* pIter = &kResolved4;
    while (pIter && pIter->GetItem())
    {
        kRefs.AddHead(pIter->GetItem());
        pIter = pIter->GetNext();
    }
    kResolved4.RemoveAll();
}
