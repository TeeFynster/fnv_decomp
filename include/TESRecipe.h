#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "Data.h"
#include "PerkEntryConditionSet.h"
#include "MagicTarget.h"
#include "NiPoint3.h"

class TESRecipeCategory;
class QuantityData;
class RecipeCraftingInfo;
class RecipeData;
class RecipeItem;
class RecipeItemProcessor;

class TESRecipe : public TESForm, public TESFullName
{
public:
    

    // local form of ::Data: 0x005a7c50 needs a trivial recipe record; the shared ctor/dtor makes 197 bytes versus exe 182.
    struct Data
    { // TESRecipe::Data is the nested trivial recipe record; unlike ::Data it must not emit ctor/dtor calls (0x005a7c50: exe 182 vs 197 bytes).
        ActorValue::Index eReqSkill;
        int iReqSkillLevel;
        unsigned int uiCategoryID;
        unsigned int uiSubCategoryID;
    };

    Data kData;
    PerkEntryConditionSet kConditions;
    BSSimpleList<QuantityData*> kIngredients;
    BSSimpleList<QuantityData*> kOutputs;
    BSSimpleList<QuantityData*> kGarbageCollection;
    TESRecipeCategory* pCategory;
    TESRecipeCategory* pSubCategory;

    TESRecipe();
    virtual ~TESRecipe();

    virtual void ClearData();
    virtual bool LoadForm(TESFile* file);
    virtual void InitItem();

    void FUN_004f15a0(unsigned int type);
    bool Load(TESFile* file);
    RecipeCraftingInfo* GetData();
    NiPoint3* TESObjectREFR_GetDeltaForAngle(NiPoint3* point, float value);
    RecipeItemProcessor* NiAVObject_GetRotate_006a9540();
    TESForm* FUN_006286d0();
    RecipeData* FUN_00430830();
    BSSimpleList<RecipeItem*>* ComputeValue_005a8080();
    BSSimpleList<RecipeItem*>* BSFile_GetDevice();
    void SaveAlt_005a8490();
    PerkEntryConditionSet* GetConditions();
    BSSimpleList<QuantityData*>* GetIngredientList();
    BSSimpleList<QuantityData*>* GetOutputList();
    BSSimpleList<QuantityData*>* GetGarbageList();
    TESForm* GetField54();
    void SetSkill(int skill);
    void SetSkillLevel(int level);
    void SetRequiredSkill(ActorValue::Index skill);
    void SetCategory(TESRecipeCategory* category);
    void SetCategory(unsigned int category);
    void SetSubCategory(TESRecipeCategory* subCategory);
    void ReadTypedData(TESFile* file, void* data, unsigned short size);
};
