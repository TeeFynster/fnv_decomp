#pragma once

#include "TESBoundObject.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESIcon.h"
#include "BGSMessageIcon.h"
#include "TESValueForm.h"
#include "BGSPickupPutdownSounds.h"

class TESCaravanMoney : public TESBoundObject,
                        public TESFullName,
                        public TESModelTextureSwap,
                        public TESIcon,
                        public BGSMessageIcon,
                        public TESValueForm,
                        public BGSPickupPutdownSounds
{
public:
    TESCaravanMoney();
    virtual ~TESCaravanMoney();

    virtual void Init();
    virtual void InitItem();
    virtual void ClearData();
    virtual void SaveForm();
    virtual bool Compare(TESForm* other);

    // Alternate names for inherited virtual slots.
    void VSlot00();
    bool Load(TESFile* file);
    void ResetFormData();
    TESModelTextureSwap* GetModelTextureSwap(int index);
    void* Release(unsigned int flags);

    TESModelTextureSwap m_kModelTextureSwaps[2];
};
