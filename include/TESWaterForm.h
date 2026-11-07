#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESAttackDamageForm.h"
#include "NiAVObject.h"
#include "NiColorA.h"
#include "TESTexture.h"
#include "WaterShaderSettings.h"

class BSRenderedTexture;
class NiTexture;
class NiSourceTexture;
class TESSound;
class SpellItem;
class BGSPlaceableWater;
class BGSSaveFormBuffer;

struct TESWaterForm : public TESForm, public TESFullName, public TESAttackDamageForm
{
public:
    TESWaterForm();
    virtual ~TESWaterForm();
    TESWaterForm& operator=(const TESWaterForm&);

    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile*);
    virtual void SaveForm();
    virtual void SaveGameLegacy(unsigned int changedFlags);
    virtual void LoadGame(BGSLoadFormBuffer* arg);
    virtual void Revert(BGSLoadFormBuffer* buffer);
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void ResetFormData();
    bool Load(TESFile*);
    void SetSpellItem(SpellItem*);
    unsigned int HasTexture();
    const char* GetTexturePath() const;
    void SetTexture(NiSourceTexture* apTexture);
    int __thiscall _FNV_GetFormType();
    WaterShaderSettings* GetShaderSettings();
    WaterShaderSettings* Sky_GetStarsColor();
    bool HasFlag1();
    bool IsDangerous();
    void __thiscall TESWaterForm_SetRemappedWaterForm(int);
    void SetSpellItem_0057f890(SpellItem*);
    unsigned int GetMember();
    const char* GetMaterialName();
    void SetMaterialName(const char*);
    unsigned int GetNoiseTextureNameLength();
    const char* GetNoiseTextureName() const;
    void SetNP(void*);
    void GetNoiseTexture(NiPointer<NiTexture>&);
    float GetOpacity_00580100();
    BGSPlaceableWater* GetPlaceableAutoWater();
    BGSPlaceableWater* GetPlaceableLODWater();
    void SaveWaterForm();
    void Copy_0057fde0(TESForm*);
    bool Compare_0057ff10(TESForm*);
    void SaveGame_005806e0(BGSSaveFormBuffer*);
    void LoadGame_00580730(BGSLoadFormBuffer*);
    void Revert_005807a0(BGSLoadFormBuffer*);

    bool m_bNeedsUpdate;
    unsigned char layoutPadding2D[3];
    NiPointer<BSRenderedTexture> m_pRenderedTexture;
    NiColorA m_kTextureScrollLayer0;
    NiColorA m_kTextureScrollLayer1;
    NiColorA m_kTextureScrollLayer2;
    TESTexture m_kNoiseMapTexture;
    unsigned char m_ucOpacity;
    unsigned char cFlags;
    unsigned char layoutPadding72[2];
    BSStringT<char> m_kMaterialId;
    TESSound* m_pWaterSound;
    TESWaterForm* m_pWaterForm;
    WaterShaderSettings Data;
    TESWaterForm* m_apWaterForms[3];
    int m_iCurrentTextureSelection1;
    int m_iCurrentTextureSelection2;
    unsigned int m_uiNoiseFrequencyX;
    unsigned int m_uiNoiseFrequencyY;
    int m_iNoiseOctaveCount;
    float m_fNoiseAmplitude;
    float m_fNoiseLacunarity;
    float fSideOffset;
    float m_fDistanceScale;
    SpellItem* m_pWaterSpell;
    NiPointer<NiTexture> m_kNoiseTextureData;
    BGSPlaceableWater* m_pPlaceableAutoWater;
    BGSPlaceableWater* m_pPlaceableWater;
    int m_iRadiationMagnitude;
    int m_iHealthMagnitude;
    bool m_bResetNoiseTextures;
    unsigned char layoutPadding191[3];
};
