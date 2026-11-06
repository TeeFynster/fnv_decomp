// Unit-local header for fallout_shared/tesrecipe.cpp.
// Unit-local recipe data and loading helpers.
#ifndef FNV_TESRECIPE_UNIT_H
#define FNV_TESRECIPE_UNIT_H

#include "layout_support.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "TESFile.h"
class
    TESConditionItem;  // 1 Nov: the folder-local layout_support.h subset (it wins the shared guard) does not declare it
#include "../../include/ByteFlags.h"
#include "../../include/TESRecipe.h"
#include "../../include/TESRecipeCategory.h"

// with BGSDefaultObjectManager::IsFormInitialized (0x004013e0) through
// identical-COMDAT folding. The canonical TESForm.h does not declare it yet,
// so it is declared on this shim, following the accepted TESFileFormInt
// precedent in tessound.cpp.
struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
    static TESForm* GetFormByID(unsigned int auiFormID);
};

// TESFullName::LoadFullNameChunk is not declared in the bundled TESFullName.h;
// declared here on a shim following the TESFormInitFlag precedent.
// 1 Nov: TESFullNameLoader is declared by the folder-local layout_support.h (a second definition here was C2011)

int Warning(const char* apFormat, ...);


#pragma pack(push, 4)
class RecipeCraftingInfo
{
  public:
    int m_iRequiredLevel;  // +0x0, 4 bytes
    int m_iSkill;          // +0x4, 4 bytes
    int CategoryID;        // +0x8, 4 bytes
    int SubCategoryID;     // +0xC, 4 bytes
    void Endian();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RecipeCraftingInfo) == 16);
FNV_STATIC_ASSERT(offsetof(RecipeCraftingInfo, m_iRequiredLevel) == 0);
FNV_STATIC_ASSERT(offsetof(RecipeCraftingInfo, m_iSkill) == 4);
FNV_STATIC_ASSERT(offsetof(RecipeCraftingInfo, CategoryID) == 8);
FNV_STATIC_ASSERT(offsetof(RecipeCraftingInfo, SubCategoryID) == 12);


#pragma pack(push, 4)
class QuantityData
{
  public:
    unsigned int Quantity;  // +0x0, 4 bytes
    TESForm* m_pItemForm;   // +0x4, 4 bytes
    QuantityData();
    unsigned int GetQuantity();
    void SetQuantity(unsigned int auiQuantity);
    TESForm* GetItem();
    void SetItem(TESForm* apItem);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(QuantityData) == 8);
FNV_STATIC_ASSERT(offsetof(QuantityData, Quantity) == 0);
FNV_STATIC_ASSERT(offsetof(QuantityData, m_pItemForm) == 4);

#endif
