#pragma once

#include "TESBoundObject.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESIcon.h"
#include "TESScriptableForm.h"
#include "TESValueForm.h"
#include "TESWeightForm.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSMessageIcon.h"
#include "BGSPickupPutdownSounds.h"

class TESFile;
class TESSound;

class TESObjectMISC : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESValueForm,
                      public TESWeightForm,
                      public BGSDestructibleObjectForm,
                      public BGSMessageIcon,
                      public BGSPickupPutdownSounds
{
public:
    TESObjectMISC();
    virtual ~TESObjectMISC();

    void ResetFormData();
    virtual void InitItem();
    bool Load(TESFile* file);
    void SetFormType(int type);
    void SetLoopingSound(TESSound* sound);
    void FUN_009db930(unsigned int value);
    void InitializeData();

    TESSound* pLoopingSound;
};
