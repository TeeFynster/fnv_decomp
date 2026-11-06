#pragma once

#include "BaseFormComponent.h"

class BGSListForm;
class TESForm;

class BGSRepairItemList : public BaseFormComponent
{
public:
    BGSRepairItemList();
    ~BGSRepairItemList();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void InitItem(TESForm* owner);
    void SetRepairList(BGSListForm* list);
    void SetRepairItemList(BGSListForm* list);

    BGSListForm* pListForm;
};
