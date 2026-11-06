#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESIcon.h"
#include "BGSMessageIcon.h"
#include "ReputationLimitData.h"

enum ReputationType
{
    ReputationType_REPUTATION_NEGATIVE = 0,
    ReputationType_REPUTATION_POSITIVE = 1
};

class TESReputation : public TESForm, public TESFullName, public TESIcon, public BGSMessageIcon
{
public:
    ReputationLimitData data;
    float m_fFirstReputationValue;
    float m_fSecondReputationValue;
    ReputationType m_eReputationType;

    TESReputation();
    virtual ~TESReputation();
    virtual void InitializeComponent();
    virtual bool LoadForm(TESFile* file);

    void ResetFormData();
    bool Load(TESFile* file);
    void ReadTypedData(TESFile* file, void* buffer, unsigned short size);
    float GetUnsignedIntegerPointer(ReputationType type);
    static unsigned int* __cdecl GetUnsignedIntegerPointer(unsigned int* value);
    int GetReputationRank(int type);
    const char* GetReputationName();
    const char* GetSelectedSettingString();
    const char* FUN_00616710();
    const char* FUN_006167d0();
    void ShowMessageBox();
    void ApplyReputationChange(int type, int amount);
    void FUN_00615580(int type, float value);
    void FUN_00615730(int kind, float delta);
    void FUN_00615a00(int kind, float amount);
    void FUN_00615fa0(int kind, int amount);
    float FUN_00616a20();
    float FUN_00616a40();
    unsigned int GetSaveFormID();
};
