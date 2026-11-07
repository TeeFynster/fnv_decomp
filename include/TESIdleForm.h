#pragma once

#include "TESForm.h"
#include "TESModelAnim.h"
#include "PerkEntryConditionSet.h"

class NiFormArray;
class TESObjectREFR;
class IdleReplayDelayEntry;

class IdleAnimationData
{
public:
    unsigned char m_ucAnimationGroupSection;
    unsigned char m_ucLoopingMin;
    unsigned char m_ucLoopingMax;
    unsigned char unk03;
    unsigned short m_usReplayDelay;
    unsigned char m_ucIdleFlags;
    unsigned char unk07;

    void SwapEndian();
};

class TESIdleForm : public TESForm, public TESModelAnim
{
public:
    PerkEntryConditionSet Conditions;
    IdleAnimationData data;
    NiFormArray* m_pParentPath;
    TESIdleForm* m_pParentIdleForm;
    TESIdleForm* m_pIdleForm;
    unsigned char unk4C[8];

    TESIdleForm();
    virtual ~TESIdleForm();
    virtual void ClearData();
    virtual void InitItem();
    virtual char* GetName() const;

    const char* GetEditorID();
    void ResetFormData();
    void UnregisterIdleForm();
    bool IsFlag40Set();
    bool TESIdleForm_GetAllowNoFile();
    NiFormArray* AssignParentPath();
    unsigned int GetChildCount();
    TESIdleForm* GetChildByIndex(unsigned int index);
    bool Load(TESFile* file);
    // TESForm vtable slot 8 (vftable 0x1049d0c slot 8 = 0x5fe810)
    bool LoadForm(TESFile* file);
    bool HasMissingPathArray();
    void BuildIdleParentPath(NiFormArray* array);
    bool IsIdleFile();
    TESIdleForm* FindIdleFormForObject(
        TESObjectREFR* actionRef, TESObjectREFR* targetRef,
        BSSimpleList<IdleReplayDelayEntry*>* replayDelays);
    bool IsValidForReferences(
        TESObjectREFR* actionRef, TESObjectREFR* targetRef, bool recurseUp);
    int GetFlagsMasked();
    void* FUN_0067f390();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    unsigned char GetRandomValue();
    unsigned short GetField3C();
};
