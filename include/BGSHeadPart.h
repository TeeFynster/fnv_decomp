#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "BSSimpleList.h"

class BGSHeadPart : public TESForm, public TESFullName, public TESModelTextureSwap
{
public:
    BGSHeadPart();

    virtual ~BGSHeadPart();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual void InitItem(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void ResetFormData();
    bool Load(TESFile* file);
    void InitializeHeadPart();
    void AddExtraPart(BGSHeadPart* part);
    BSSimpleList<BGSHeadPart*>* GetExtraParts();
    void* GetExtraPartList();
    unsigned char IsPlayable_005e7a60();
    void ClearData_005e7460();
    bool Load_005e7530(TESFile* file);
    void FUN_005e7790(BGSHeadPart* part);
    void InitItem_005e77b0();
    void Copy_005e78f0(TESForm* form);
    bool Compare_005e79a0(TESForm* form);

    unsigned char cFlags;
    unsigned char padding[3];
    BSSimpleList<BGSHeadPart*> m_kExtraParts;
};
