
// src/effectsetting_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00407300: the skeleton of src/effectsetting.cpp
// with declarations corrected to what the original code does (effectsetting_decls.h: EffectSetting += void FUN_00407300();; effectsetting_decls.h: TESForm += void FUN_004855a0(); void FUN_00485680();; effectsetting_decls.h: TESFullName += void FUN_00487010();; effectsetting_decls.h: TESDescription += void FUN_00482cb0();; effectsetting_decls.h: TESIcon += void). Move the function to its real unit once
// that unit declares it this way.

#include "../include/BaseFormComponent.h"
#include "../include/EffectSetting.h"
#include "../include/FileEntryList.h"
#include "../include/TESDescription.h"
#include "../include/TESEffectShader.h"
#include "../include/TESFile.h"
#include "../include/TESForm.h"
#include "../include/TESFullName.h"
#include "../include/TESIcon.h"
#include "../include/TESModel.h"
#include "../include/TESObjectLIGH.h"
#include "../include/TESSound.h"
#include "../include/TESTexture.h"

enum
{
    CHUNK_ICON = 0x4E4F4349,
    CHUNK_MODL = 0x4C444F4D,
    CHUNK_MODT = 0x54444F4D,
    CHUNK_DATA = 0x41544144,
    CHUNK_ESCE = 0x45435345
};
bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl AppendChunk(unsigned int, void*, unsigned int);
void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);

// @fnv 0x00407300
// src: COMMUNITY 0x00407300
void EffectSetting::SaveAlt()
{
    BeginFormRecord();
    TESFullName::Save_00487010();
    TESDescription::Save_00482cb0();
    TESIcon::Save(CHUNK_ICON);
    TESModel::WriteToBuffer(CHUNK_MODL, CHUNK_MODT);

    TESSound* pkCastSound = data.m_pCastSound;
    data.m_pCastSound = (TESSound*)(data.m_pCastSound ? static_cast<const TESForm*>(data.m_pCastSound)->GetFormID() : 0);
    TESSound* pkBoltSound = data.m_pBoltSound;
    data.m_pBoltSound = (TESSound*)(data.m_pBoltSound ? static_cast<const TESForm*>(data.m_pBoltSound)->GetFormID() : 0);
    TESSound* m_pContactSound = data.m_pContactSound;
    data.m_pContactSound = (TESSound*)(data.m_pContactSound ? static_cast<const TESForm*>(data.m_pContactSound)->GetFormID() : 0);
    TESSound* m_pAreaEffectSound = data.m_pAreaEffectSound;
    data.m_pAreaEffectSound = (TESSound*)(data.m_pAreaEffectSound ? static_cast<const TESForm*>(data.m_pAreaEffectSound)->GetFormID() : 0);
    TESEffectShader* pkEffectShaderSave = data.m_pEffectShader;
    data.m_pEffectShader = (TESEffectShader*)(data.m_pEffectShader ? static_cast<const TESForm*>(data.m_pEffectShader)->GetFormID() : 0);
    TESEffectShader* pkEnchantEffect = data.m_pEnchantEffectShader;
    data.m_pEnchantEffectShader =
        (TESEffectShader*)(data.m_pEnchantEffectShader ? static_cast<const TESForm*>(data.m_pEnchantEffectShader)->GetFormID() : 0);
    TESObjectLIGH* pkLight = data.apTargetLight;
    data.apTargetLight = (TESObjectLIGH*)(data.apTargetLight ? static_cast<const TESForm*>(data.apTargetLight)->GetFormID() : 0);
    TESForm* savedPAssociatedItemOriginal = data.m_pAssociatedForm;
    data.m_pAssociatedForm = (TESForm*)(data.m_pAssociatedForm ? static_cast<const TESForm*>(data.m_pAssociatedForm)->GetFormID() : 0);

    if (TESForm_QEndianSwapOnSave())
        data.Endian();
    AppendChunk(CHUNK_DATA, &data, sizeof(data));
    if (TESForm_QEndianSwapOnSave())
        data.Endian();

    data.m_pCastSound = pkCastSound;
    data.m_pBoltSound = pkBoltSound;
    data.m_pContactSound = m_pContactSound;
    data.m_pAreaEffectSound = m_pAreaEffectSound;
    data.m_pEffectShader = pkEffectShaderSave;
    data.m_pEnchantEffectShader = pkEnchantEffect;
    data.apTargetLight = pkLight;
    data.m_pAssociatedForm = savedPAssociatedItemOriginal;

    EffectSetting* savedPkEffect;
    for (BSSimpleList<EffectSetting*>* pkIter = &counterEffects; pkIter && (savedPkEffect = pkIter->GetItem()) != 0;
         pkIter = pkIter->GetNext())
        TESForm_AddChunk_00485910(CHUNK_ESCE, static_cast<const TESForm*>(savedPkEffect)->GetFormID());

    FinishFormRecord();
}
