
// src/fallout_shared/tesproduceform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesproduceform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BaseFormComponent.h"
#include "../../include/IngredientItem.h"
#include "../../include/TESProduceForm.h"
#include "../../include/TESRaceForm.h"

void* __cdecl memset(void* p, int c, unsigned int n);

// Sets the int at offset 4 to 0 and zeroes the 4 bytes at offset 8 of this object.
// @fnv 0x0048b590
void TESProduceForm::Init()
{
    *(reinterpret_cast<int*>(this) + 1) = 0;
    memset(reinterpret_cast<char*>(this) + 8, 0, 4);
}

extern "C" void* __cdecl __memcpy(void* dst, const void* src, unsigned int count);

// Copies 4 bytes from src into this object at offset 8 when src is non-null.
// @fnv 0x0048b670
void TESProduceForm::CopyFromSource(void* pSource)
{
    if (pSource)
        __memcpy((char*)this + 8, pSource, 4);
}

void __cdecl TESForm_AddChunkArray(unsigned int, void*, unsigned int);
void __cdecl _FUN_00485910(unsigned int, unsigned int);
// @fnv 0x0048b5c0
void TESProduceForm::Save()
{
    unsigned int tmp;
    if (pIngredient != 0)
    {
        tmp = pIngredient->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        _FUN_00485910(0x47494650, tmp);
    }
    TESForm_AddChunkArray(0x43504650, cProdChance, 4);
}

// Casts apCopyFC to TESProduceForm, initializes this from its ingredient value, then copies the data at offset 8.
// @fnv 0x0048b610
void TESProduceForm::CopyFromBase(BaseFormComponent* apCopyFC)
{
    TESProduceForm* pCopy = dynamic_cast<TESProduceForm*>(apCopyFC);
    if (!pCopy)
        return;
    ((TESRaceForm*)this)->Initialize(pCopy->GetIngredient());
    CopyFromSource((void*)((char*)pCopy + 8));
}

extern "C" int __cdecl memcmp(const void* a, const void* b, unsigned int n);
// Compares production chance bytes and the ingredient value against another component, returning true when they differ or the other is not a TESProduceForm.
// @fnv 0x0048b6a0
bool TESProduceForm::CompareWithBase(BaseFormComponent* apOther)
{
    TESProduceForm* pOther = dynamic_cast<TESProduceForm*>(apOther);
    if (!pOther)
        return true;
    if (GetIngredient() != pOther->GetIngredient())
        return true;
    if (memcmp(cProdChance, pOther->cProdChance, 4))
        return true;
    return false;
}

void ResolveFormID(unsigned int* apFormID, TESFile* apFile);
TESForm* TESForm_GetFormByNumericID(unsigned int aFormID);
void FNV_Warning(const char* apMsg, ...);

extern const char DAT_0101d2b4[];
extern const char DAT_0101d2f8[];
extern const char DAT_0101d340[];

// Resolves pIngredient's form ID through the file, re-looks it up as an IngredientItem, and warns if the lookup fails.
// @fnv 0x0048b720
void TESProduceForm::ResolveIngredient(TESForm* apArg)
{
    if (pIngredient != 0)
    {
        unsigned int formID = (unsigned int)pIngredient;
        ResolveFormID(&formID, apArg->GetFile(-1));
        pIngredient = dynamic_cast<IngredientItem*>(TESForm_GetFormByNumericID(formID));
        if (pIngredient == 0)
        {
            if (apArg != 0)
            {
                if (apArg->GetFormEditorIDLength())
                {
                    FNV_Warning(DAT_0101d340, formID, apArg->GetName());
                }
                else
                {
                    FNV_Warning(DAT_0101d2f8, formID, apArg->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
                }
            }
            else
            {
                FNV_Warning(DAT_0101d2b4, formID);
            }
        }
    }
}
