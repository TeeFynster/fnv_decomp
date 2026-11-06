#pragma once

#include "TESBoundObject.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESIcon.h"
#include "BGSMessageIcon.h"
#include "TESValueForm.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSPickupPutdownSounds.h"

class TESFile;

class TESCasinoChips : public TESBoundObject,
                       public TESFullName,
                       public TESModelTextureSwap,
                       public TESIcon,
                       public BGSMessageIcon,
                       public TESValueForm,
                       public BGSDestructibleObjectForm,
                       public BGSPickupPutdownSounds
{
public:
    BSStringT<char> m_kPrimaryString;

    TESCasinoChips();

    virtual void ClearData();
    virtual void InitItem();

    bool Load(TESFile* apFile);
    // TESForm vtable slot 8 (vftable 0x10263dc slot 8 = 0x503ef0)
    bool LoadForm(TESFile* file);
};
