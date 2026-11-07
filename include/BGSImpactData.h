#pragma once

#include "TESForm.h"
#include "TESModel.h"
#include "BGSImpactData__IMPACT_DATA_DATA.h"

class BGSTextureSet;
class TESSound;



#include "DecalData.h"

class BGSImpactData : public TESForm, public TESModel
{
public:
    BGSImpactData__IMPACT_DATA_DATA Data;
    BGSTextureSet* m_pDecalTextureSet;
    TESSound* m_pPrimaryImpactSound;
    TESSound* m_pSecondaryImpactSound;
    DecalData ImpactDecalInfo;

    BGSImpactData();
    virtual ~BGSImpactData();
    virtual void InitializeComponent();
    virtual bool LoadForm(TESFile* file);
    virtual void SaveForm(void);
    virtual void InitItem(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void ResetFormData();
    void ReadTypedData(TESFile* file, void* buffer, unsigned short size);
    void SetDecalTextureSet(BGSTextureSet* textureSet);
    void SetSound1(TESSound* sound);
    void SetSound2(TESSound* sound);
    void CopyDecalDataFromTextureSet();
    bool Load(TESFile* file);
    BGSTextureSet* GetDecalTextureSet() const;

    void Copy_0058dd10(int arg);
    bool IsDifferentFrom(TESForm* apCompare);
    bool IsFlagSet();
    void Save_0058e450();
    void CopyDecalData();
    int GetGlobalValue();
};
