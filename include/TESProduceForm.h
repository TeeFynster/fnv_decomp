#pragma once

#include "BaseFormComponent.h"

class IngredientItem;
class TESForm;

class TESProduceForm : public BaseFormComponent
{
public:
    ~TESProduceForm();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void CopyFromSource(void* source);
    void Save();
    unsigned int GetIngredient();
    void ResolveIngredient(TESForm* owner);

    IngredientItem* pIngredient;
    unsigned char cProdChance[4];
};
