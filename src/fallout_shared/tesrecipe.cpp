// fallout_shared/tesrecipe.cpp: TESRecipe, TESRecipeCategory (4 functions)

#define FNV_TESFILE_H  // the shared TESFile below replaces layout_support.h's stub
#include "../../include/NiFile.h"
#include "tesrecipe.h"
#include <malloc.h>
#include "../../include/TESFile.h"

static const char s_kRecipeCategoryWarning[] =
    "MASTERFILE: Recipe Category (%08X) not found in InitItem for Recipe (%08X) '%s'.";
static const char s_kRecipeSubCategoryWarning[] =
    "MASTERFILE: Recipe (sub)Category (%08X) not found in InitItem for Recipe (%08X) '%s'.";

// @fnv 0x005a80a0
void TESRecipe::ClearData()
{
    GetConditions()->InitializeConditionItems();
    GetIngredientList()->RemoveAll();
    GetOutputList()->RemoveAll();
    GetGarbageList()->RemoveAll();
    SetSkill(-1);
    SetSkillLevel(0);
    SetCategory(static_cast<TESRecipeCategory*>(0));
    SetSubCategory(0);
}

// Initializes recipe category, subcategory, and ingredient/output lists by resolving form IDs, then marks the form as initialized.
// @fnv 0x005a7e00
void TESRecipe::InitItem()
{
    TESForm* item;
    TESForm* form;
    QuantityData* component;
    TESRecipeCategory* category;
    BSSimpleList<QuantityData*>* compList;
    unsigned int level;
    unsigned int id;
    if (static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))->IsFormInitialized())
        return;
    kConditions.InitItem(this);
    level = GetData()->m_iRequiredLevel;
    category = 0;
    id = GetData()->CategoryID;
    if (id)
    {
        TESForm::RemapFormIDForFile(id, GetFile(-1));
        category = dynamic_cast<TESRecipeCategory*>(TESFormInitFlag::GetFormByID(id));
        if (!category)
            Warning(s_kRecipeCategoryWarning, id, GetFormID(), GetName());
        else
            SetCategory(category);
    }
    category = 0;
    id = GetData()->SubCategoryID;
    if (id)
    {
        TESForm::RemapFormIDForFile(id, GetFile(-1));
        category = dynamic_cast<TESRecipeCategory*>(TESFormInitFlag::GetFormByID(id));
        if (!category)
            Warning(s_kRecipeSubCategoryWarning, id, GetFormID(), GetName());
        else
            SetSubCategory(category);
    }
    compList = GetIngredientList();
    component = 0;
    while (compList && compList->GetItem())
    {
        component = compList->GetItem();
        compList = compList->GetNext();
        form = TESFormInitFlag::GetFormByID(reinterpret_cast<unsigned int>(component->GetItem()));
        component->SetItem(form);
    }
    compList = GetOutputList();
    component = 0;
    while (compList && compList->GetItem())
    {
        component = compList->GetItem();
        compList = compList->GetNext();
        item = TESFormInitFlag::GetFormByID(reinterpret_cast<unsigned int>(component->GetItem()));
        component->SetItem(item);
    }
    SetInitializationState(true);
}

// Parses recipe chunks (ID, OBND, FNAM, DATA, CND, CRIN, CRO, CRQ) from a TESFile, building ingredient and output lists from QuantityData entries.
// @fnv 0x005a8110
bool TESRecipe::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    QuantityData* component;
    unsigned int formID;
    bool bOutput;
    int chunk;
    ClearData();
    if (formType != 0x6A)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    component = 0;
    formID = 0;
    bOutput = false;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* buffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(buffer, 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4C4C5546:  // FULL
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x41544144:  // DATA
            ReadTypedData(file, &kData, sizeof(kData));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<RecipeCraftingInfo*>(&kData)->Endian();
            break;
        case 0x41445443:  // CTDA
            GetConditions()->Load(file);
            break;
        case 0x4C494352:  // RCIL
        {
            bOutput = false;
            component = new QuantityData;
            unsigned int ingredientID = 0;
            file->GetChunkData(&ingredientID);
            TESForm::RemapFormIDForFile(ingredientID, GetFile(-1));
            formID = ingredientID;
            break;
        }
        case 0x444F4352:  // RCOD
        {
            bOutput = true;
            component = new QuantityData;
            unsigned int outputID = 0;
            file->GetChunkData(&outputID);
            TESForm::RemapFormIDForFile(outputID, GetFile(-1));
            formID = outputID;
            break;
        }
        case 0x59514352:  // RCQY
        {
            unsigned int quantity = 0;
            file->GetChunkData(&quantity);
            component->SetQuantity(quantity);
            break;
        }
        }
        if (component > 0 && component->GetQuantity() > 0 && formID > 0)
        {
            component->SetItem(reinterpret_cast<TESForm*>(formID));
            if (bOutput)
                GetOutputList()->AddTail(component);
            else
                GetIngredientList()->AddTail(component);
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Loads a TESRecipeCategory record from a file, validating form type 0x6B and parsing EDIT, OBND, FNAM, and DATA chunks.
// @fnv 0x005a7910
bool TESRecipeCategory::Load(TESFile* file)
{
    int chunk;
    unsigned char formType = file->GetTESForm();
    if (formType != 0x6B)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* pEditorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(pEditorID, 0x200);
            SetEditorID_AtRuntime(pEditorID);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4C4C5546:  // FULL
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x41544144:  // DATA
            ReadTypedData(file, &data, sizeof(data));
            if (file->IsEndianConversionRequired())
                data.Endian();
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}
