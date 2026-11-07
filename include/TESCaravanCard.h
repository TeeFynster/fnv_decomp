#pragma once

#include "TESBoundObject.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESIcon.h"
#include "BGSMessageIcon.h"
#include "TESValueForm.h"
#include "TESScriptableForm.h"
#include "BGSPickupPutdownSounds.h"
#include "TESTexture.h"
#include "UnsignedValuePair.h"

class TESCaravanCard : public TESBoundObject,
                       public TESFullName,
                       public TESModelTextureSwap,
                       public TESIcon,
                       public BGSMessageIcon,
                       public TESValueForm,
                       public TESScriptableForm,
                       public BGSPickupPutdownSounds
{
public:
    TESCaravanCard();
    virtual ~TESCaravanCard();
    virtual void InitializeComponent();
    virtual bool LoadForm(TESFile* file);
    virtual void InitItem();

    bool Load(TESFile* file);
    void ResetFormData();
    TESTexture* GetBackTexture();
    char* CaravanAIPackage_Print_WhatIsHeThinking();

    bool bIsActive;
    unsigned char layoutPadding99[3];
    TESTexture m_kFrontTexture;
    TESTexture m_kBackTexture;
    UnsignedValuePair data;
};
