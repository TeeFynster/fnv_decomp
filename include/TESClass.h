#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESDescription.h"
#include "TESTexture.h"
#include "TESAttributes.h"
#include "TESClassData.h"

class TESClass : public TESForm, public TESFullName, public TESDescription, public TESTexture, public TESAttributes
{
public:
    TESClass();
    virtual ~TESClass();

    bool IsGuard();
    bool IsTagSkill(ActorValue::Index aeSkill);
    bool IsTagSkill(ActorValue::Index aeSkill) const;
    unsigned int FUN_006286d0();
    void SetClassSkillAtIndex(int index, ActorValue::Index skill);
    void ResetFormData();
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    bool Load(TESFile* file);
    bool ValidateSkillActorValue();
    void* DestroyIfFlagged(unsigned int flags);
    int GetTrainingSkill();
    void SetTrainingSkill(ActorValue::Index skill);
    virtual void SaveForm(void);
    virtual void SaveGame(BGSSaveFormBuffer* buffer);
    void CopyFromTESClass(TESForm* other);
    void TESForm_CopyAllComponents(TESForm* other);
    bool CompareClass(TESForm* other);
    bool TESForm_CompareAllComponents(TESForm* other);
    TESClassData* GetClassData() const;

    TESClassData data;
};
