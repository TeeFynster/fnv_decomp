
// src/fallout/ai/middlehighprocess_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/middlehighprocess.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "layout_support.h"
#include "../../../include/TESClass.h"
// The process declarations must reuse the shared form base classes.
#define FNV_BASEFORMCOMPONENT_H
#define FNV_TESFORM_H
#include "middlehighprocess_decls.h"
bool IsValidSandboxProcedure(int aiProcedure);

struct AcquireSortItem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int sortKey;
};

struct AcquireSortNode
{
    AcquireSortItem** FUN_006815c0();
    AcquireSortNode* FUN_00726070();
    int FUN_005ae380();
    void FUN_00726c60(AcquireSortItem** slot);
};

struct AcquireSortProcess : MiddleHighProcess
{
    void HighProcess_SortObjectsListByValue();
};

// @fnv 0x0091b640
// src: COMMUNITY 0x0091b640
void AcquireSortProcess::HighProcess_SortObjectsListByValue()
{
    AcquireSortNode* outer2 = (AcquireSortNode*)&ReferenceListNode;
    AcquireSortNode* inner5 = 0;
    if (outer2 != 0)
    {
        unsigned int count4 = outer2->FUN_005ae380();
        bool changed3 = true;
        while (count4 != 0 && changed3)
        {
            changed3 = false;
            inner5 = outer2;
            while (inner5 != 0)
            {
                AcquireSortItem* first2 = *outer2->FUN_006815c0();
                AcquireSortItem* second3 = *inner5->FUN_006815c0();
                if (first2->sortKey > second3->sortKey)
                {
                    outer2->FUN_00726c60(&second3);
                    inner5->FUN_00726c60(&first2);
                    changed3 = true;
                }
                inner5 = inner5->FUN_00726070();
            }
            outer2 = outer2->FUN_00726070();
            count4--;
        }
    }
}

namespace FurnitureSearchDetail {
using ::TESObjectREFR;
using ::TESForm;
using ::TESObjectCELL;
using ::Actor;
using ::NiPoint3;
using ::MiddleHighProcess;

struct FurnitureLocation
{
    int PackageLocation_GetLocType();
    ::TESObjectCELL* FUN_0067f3e0();
};
struct FurniturePackage
{
    FurnitureLocation* FUN_0055b980();
    int FUN_0041ca90();
    unsigned int FUN_00676280(::Actor*);
    bool FUN_006728a0(::Actor*, float*);
    ::NiPoint3 TESPackage_GetLocationCoord(::Actor*);
};
struct FurnitureCell
{
    bool FUN_00425fd0();
};
struct FurnitureRef : ::TESObjectREFR
{
    ::TESForm* TESObjectREFR_GetOwner();
};
struct FurnitureList
{
    ::TESObjectREFR*& FUN_006815c0();
    FurnitureList* FUN_00726070();
    void FUN_00470470();
    void FUN_005ae3d0(::TESObjectREFR*&);
    unsigned int FUN_005ae380();
    void FUN_00726c60(::TESObjectREFR* const&);
};
struct FurnitureSetting
{
    float* Setting_Float_00403e20();
};
struct FurnitureSearchManager
{
    void FUN_0046f280(::TESObjectCELL*, const ::NiPoint3&, float, const ::NiPoint3&, float,
                      void(__cdecl*)(::TESObjectREFR*, ::Actor*), ::Actor*);
};
struct FurnitureTime
{
    unsigned int FUN_00825c00();
};
extern bool DAT_011e040c;
extern FurnitureSearchManager* DAT_011c3f2c;
extern FurnitureList DAT_011e0424;
extern FurnitureSetting DAT_011cd24c;
extern FurnitureTime DAT_011f6394;
void __cdecl EvaluateReferenceforSitSleep(::TESObjectREFR*, ::Actor*);
struct SearchFurnitureProcess : ::MiddleHighProcess
{
    void MiddleHighProcess_FindBedChairs(::Actor*, bool, ::TESObjectREFR*);
};
// @fnv 0x00922670
// src: COMMUNITY 0x00922670
void SearchFurnitureProcess::MiddleHighProcess_FindBedChairs(::Actor* actor, bool flag, ::TESObjectREFR* target)
{
    DAT_011e040c = flag;
    ::TESObjectCELL* a = actor->GetParentCell();
    ::NiPoint3 p = *static_cast<const ::TESObjectREFR*>(actor)->GetPos();
    FurniturePackage* f = reinterpret_cast<FurniturePackage*>(static_cast<const ::BaseProcess*>(this)->GetOneTimePackage());  // virtual slot 0x9F (the const declaration)
    if (!f || !actor)
        return;
    FurnitureLocation* s = f->FUN_0055b980();
    float i = 0.0f;
    if (f->FUN_0041ca90() == 3)
    {
        if (s && s->PackageLocation_GetLocType() == 1 && reinterpret_cast<FurnitureCell*>(s->FUN_0067f3e0())->FUN_00425fd0())
            i = 3.402823466e38f;
        else
            i = static_cast<float>(f->FUN_00676280(actor));
    }
    else if (!f->FUN_006728a0(actor, &i))
    {
        if (s && s->PackageLocation_GetLocType() == 1 && reinterpret_cast<FurnitureCell*>(s->FUN_0067f3e0())->FUN_00425fd0())
            i = 3.402823466e38f;
        else
            i = *DAT_011cd24c.Setting_Float_00403e20();
    }
    if (target)
    {
        ::NiPoint3* targetPosition = static_cast<const ::TESObjectREFR*>(target)->GetPos();
        reinterpret_cast<FurnitureSearchManager*>(DAT_011c3f2c)
            ->FUN_0046f280(target->GetParentCell(), *targetPosition, i, *targetPosition, i, EvaluateReferenceforSitSleep, actor);
    }
    else
    {
        reinterpret_cast<FurnitureSearchManager*>(DAT_011c3f2c)
            ->FUN_0046f280(a, p, i, f->TESPackage_GetLocationCoord(actor), i, EvaluateReferenceforSitSleep, actor);
    }
    reinterpret_cast<FurnitureList*>(&m_kSecondaryReferenceList)->FUN_00470470();
    FurnitureList* cf = &DAT_011e0424;
    while (cf && cf->FUN_006815c0())
    {
        reinterpret_cast<FurnitureList*>(&m_kSecondaryReferenceList)->FUN_005ae3d0(cf->FUN_006815c0());
        cf = cf->FUN_00726070();
    }
    DAT_011e0424.FUN_00470470();
    FurnitureList* eb = reinterpret_cast<FurnitureList*>(&m_kSecondaryReferenceList);
    FurnitureList* h = 0;
    if (eb)
    {
        unsigned int item2 = eb->FUN_005ae380();
        bool first = true;
        while (item2 && first)
        {
            first = false;
            h = eb;
            while (h)
            {
                ::TESObjectREFR* barterA = eb->FUN_006815c0();
                ::TESObjectREFR* found = h->FUN_006815c0();
                if (!static_cast<FurnitureRef*>(barterA)->TESObjectREFR_GetOwner() &&
                    static_cast<FurnitureRef*>(found)->TESObjectREFR_GetOwner())
                {
                    eb->FUN_00726c60(found);
                    h->FUN_00726c60(barterA);
                    first = true;
                }
                h = h->FUN_00726070();
            }
            eb = eb->FUN_00726070();
            --item2;
        }
    }
    m_uiFaceGenDataFlags = DAT_011f6394.FUN_00825c00();
}

}

#include "../../../include/BSSimpleList.h"

struct Holder91b580
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    BSSimpleList<TESClass*> m_kNode;
    void HighProcess_SortObjectsListByType();
};

// @fnv 0x0091b580
// src: COMMUNITY 0x0091b580
void Holder91b580::HighProcess_SortObjectsListByType()
{
    BSSimpleList<TESClass*>* pOuter = &m_kNode;
    BSSimpleList<TESClass*>* pInner3 = 0;
    if (pOuter)
    {
        int iCount2 = pOuter->ItemsInList();
        bool bSwapped3 = true;
        TESClass* itemA;
        TESClass* itemB;
        while (iCount2 != 0 && bSwapped3)
        {
            bSwapped3 = false;
            pInner3 = pOuter;
            while (pInner3 != 0)
            {
                itemA = pOuter->GetItem();
                itemB = pInner3->GetItem();
                // Preserve the signed comparison of the word at the full-name component.
                if (reinterpret_cast<const int*>(itemA)[sizeof(TESForm) / sizeof(int)] >
                    reinterpret_cast<const int*>(itemB)[sizeof(TESForm) / sizeof(int)])
                {
                    pOuter->SetItem(itemB);
                    pInner3->SetItem(itemA);
                    bSwapped3 = true;
                }
                pInner3 = pInner3->GetNext();
            }
            pOuter = pOuter->GetNext();
            iCount2--;
        }
    }
}
