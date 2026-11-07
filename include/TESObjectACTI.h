#pragma once

#include <stddef.h>

#include "TESBoundAnimObject.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESScriptableForm.h"
#include "TESMagicTargetForm.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSOpenCloseForm.h"

class TESSound;
class TESWaterForm;
class BGSTalkingActivator;
struct StringX;

class TESObjectACTI : public TESBoundAnimObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESScriptableForm,
                      public TESMagicTargetForm,
                      public BGSDestructibleObjectForm,
                      public BGSOpenCloseForm
{
public:
    TESObjectACTI();
    virtual ~TESObjectACTI();

    // Primary virtual overrides; the remaining slots are inherited.
    virtual void InitializeComponent();
    virtual bool LoadForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual void SaveGameLegacy(unsigned int changedFlags);
    virtual void LoadGameLegacy(unsigned int changedFlags, unsigned int currentFlags);
    virtual void InitItem(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    virtual bool Unk_49(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
    virtual TESWaterForm* GetAssociatedWaterForm() const;

    TESObjectACTI& operator=(const TESObjectACTI& other);

    void ResetFormData();
    // Alternate name for LoadForm; it must not add a virtual slot.
    bool Load(TESFile* file);
    void SetLoopingSound(TESSound* sound);
    void SetActivationPrompt(BSStringT<char> prompt);
    void SetActivateSound(TESSound* sound);
    StringX GetActivateText();

    TESSound* TESChallenge_GetFormOne();
    void* FUN_005105f0(unsigned int flags);
    void TESObjectACTI_InitItem();
    void TESObjectACTI_SetActivationPrompt(BSStringT<char> prompt);
    bool TESObjectACTI_Compare(TESForm* form);

    TESSound* m_pSoundEffect;                 // 0x74
    TESSound* m_pLoopSound;                   // 0x78
    TESSound* pRadioTemplate;                 // 0x7C
    TESWaterForm* m_pWaterForm;               // 0x80
    BGSTalkingActivator* m_pTalkingActivator; // 0x84
    BSStringT<char> m_kActivationPrompt;      // 0x88
};

typedef char TESObjectACTI_size_check[(sizeof(TESObjectACTI) == 0x90) ? 1 : -1];
typedef char TESObjectACTI_sound_effect_offset_check[(offsetof(TESObjectACTI, m_pSoundEffect) == 0x74) ? 1 : -1];
typedef char TESObjectACTI_loop_sound_offset_check[(offsetof(TESObjectACTI, m_pLoopSound) == 0x78) ? 1 : -1];
typedef char TESObjectACTI_radio_template_offset_check[(offsetof(TESObjectACTI, pRadioTemplate) == 0x7C) ? 1 : -1];
typedef char TESObjectACTI_water_form_offset_check[(offsetof(TESObjectACTI, m_pWaterForm) == 0x80) ? 1 : -1];
typedef char TESObjectACTI_talking_activator_offset_check[(offsetof(TESObjectACTI, m_pTalkingActivator) == 0x84) ? 1 : -1];
typedef char TESObjectACTI_activation_prompt_offset_check[(offsetof(TESObjectACTI, m_kActivationPrompt) == 0x88) ? 1 : -1];
