#pragma once

#include "TESForm.h"
#include "TextureParameterBlock.h"
#include "MagicTarget.h"

class BGSTextureSet;
class BSAudio;
class TESGrass;

class TESLandTexture : public TESForm
{
public:
    BGSTextureSet* m_pTextureSet;
    TextureParameterBlock LandTextureParameters;
    unsigned char m_ucTextureTiling;
    BSSimpleList<TESGrass*> m_kGrassList;

    TESLandTexture();
    virtual ~TESLandTexture();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* file);
    virtual void SaveForm();
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void* Delete(unsigned int flags);
    BGSTextureSet* GetTextureSet();
    void ResetFormData();
    bool Load(TESFile* file);
    BSSimpleList<TESGrass*>* GetGrassList();
    void AddLandRef(int iType, void* pvList);
    void v0();
    void v00();
    static BSAudio* GetSoundSystem();
};
