#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESDescription.h"
#include "TESScriptableForm.h"
#include "TESIcon.h"
#include "BGSMessageIcon.h"
#include "ChallengeData.h"
#include "ChallengeProgress.h"

class TESQuest;
class BGSSaveFormBuffer;

enum CHALLENGE_TYPE;

class TESChallenge : public TESForm,
                     public TESFullName,
                     public TESDescription,
                     public TESScriptableForm,
                     public TESIcon,
                     public BGSMessageIcon
{
public:
    using TESDescription::GetDescription;

    TESChallenge();
    virtual ~TESChallenge();
    virtual void InitializeComponent();
    virtual bool LoadForm(TESFile* file);
    virtual void SaveForm(void);
    virtual void SaveGame(BGSSaveFormBuffer* arg);
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void ResetFormData();
    bool Load(TESFile* file);
    void Initialize();
    void CopyFromChallenge(TESForm* form);
    unsigned short __thiscall FUN_005a7770(unsigned int aiFlags);
    void __thiscall FUN_0059adb0(unsigned int aiFlags);
    void __thiscall FUN_00616640(unsigned int aiFlags, unsigned int aiCurrentFlags);
    void FUN_005f5780(BGSSaveFormBuffer* buffer);
    void SetFormOne(TESForm* form);
    void SetFormTwo(TESForm* form);
    TESForm* GetFormOne();
    TESForm* GetFormTwo();
    CHALLENGE_TYPE GetChallengeType();
    int GetStartsLocked();
    int GetRecurring();
    int GetThreshold();
    int GetInterval();
    int GetSpecialOne();
    int GetSpecialTwo();
    int GetSpecialThree();
    int GetUnlocked();
    int GetCompleted();
    int GetRemovedRecurring();
    void ClearProgress();
    void MarkCompleted(bool completed);
    void SetCompletedRecurring(bool completed);
    void IncrementProgress(int amount);
    int GetProgressValue();
    void SetShowZero(bool show);
    void MarkForSave();
    bool FUN_0060fd70();
    TESQuest* FUN_004fd380();
    void FUN_005defe0(bool b);
    void FUN_005f60e0(int amount);

    ChallengeData data;
    union
    {
        ChallengeProgress progress;
        struct
        {
            int unk6C;
            unsigned int nFlags;
        };
    };
    TESForm* m_pPrimaryForm;
    TESForm* m_pSecondaryForm;
};
