#pragma once

#include "BaseFormComponent.h"

class BGSListForm;
class TESForm;

class BGSBipedModelList : public BaseFormComponent
{
public:
    BGSBipedModelList();
    ~BGSBipedModelList();

    void Init() override;
    void Free() override;
    void CopyFromBase(BaseFormComponent* component) override;
    bool CompareWithBase(BaseFormComponent* component) override;

    void InitItem(TESForm* form);
    void SetBipedModelList(BGSListForm* list);
    BGSListForm* GetList();
    static BGSBipedModelList* GetBipedModelList(TESForm* form);

    BGSListForm* pListForm;
};
