#pragma once

#include "TESForm.h"

class SpellItem;
class TESFile;

class StageRecordData
{
public:
    unsigned int m_uiStageIndex;
    SpellItem* m_pSpell;
};

class DehydrationStageData : public StageRecordData
{
public:
    DehydrationStageData();
    void SwapEndian();
    void TwoValues_Endian();
};

class BGSDehydrationStage : public TESForm
{
public:
    DehydrationStageData data;

    BGSDehydrationStage();
    virtual ~BGSDehydrationStage();

    virtual void InitItem();
    bool Load(TESFile* file);
    virtual void ClearData();
    SpellItem* GetSpell();
    unsigned int GetSpellFormID();
    void SetSpell(SpellItem* spell);
    void* GetDataBuffer(unsigned int size);
    void ReadData(TESFile* file, void* buffer);
    void InitDehydrationStage();
    unsigned int FUN_00441110();
    void FUN_0050f9a0(SpellItem* spell);
    void* FUN_00500940(unsigned int size);
    void TESForm_LoadData(TESFile* file, void* data);

    static BGSDehydrationStage* GetStage(unsigned int index);
    static BGSDehydrationStage* FindStage(float level);
    static void ClearStageData(BGSDehydrationStage* stage);
    static BGSDehydrationStage** AllocateStageArray(unsigned int count);
};
