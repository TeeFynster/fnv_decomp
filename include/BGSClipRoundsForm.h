#pragma once

#include "BaseFormComponent.h"

class TESForm;

class BGSClipRoundsForm : public BaseFormComponent
{
public:
    BGSClipRoundsForm();
    ~BGSClipRoundsForm();
    BGSClipRoundsForm& operator=(const BGSClipRoundsForm&);

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void ClearComponent();
    void Save();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    static int GetClipRounds(TESForm* form);
    int GetClipRounds();
    void SetFormClipRounds(int rounds);

    unsigned char m_ucClipRounds;
    unsigned char layoutPadding5[3];
};
