#pragma once

class Actor;
class TESBoundObject;
class TESFile;
class TESForm;
class TESWorldSpace;

class BGSPerkEntry
{
public:
    BGSPerkEntry();  // 0x005e9530: vftable 0x01046b48, m_ucRank = m_ucRegionPriority = 0
    unsigned char m_ucRank;
    unsigned char m_ucRegionPriority;
    unsigned short unk06;

    virtual bool CheckConditionFilters(unsigned int count, TESForm** subjects);
    virtual unsigned char GetFunction();
    virtual void* GetFunctionData();
    virtual ~BGSPerkEntry();
    virtual unsigned char GetEntryPoint();
    virtual void ClearData();
    virtual void InitItem(TESForm* form);
    virtual BGSPerkEntry* Duplicate();
    virtual void Copy(BGSPerkEntry* entry);
    virtual bool Compare(BGSPerkEntry* entry);
    virtual void Save();
    virtual bool Load(TESFile* file);
    virtual void ApplyEntryPointEffect(Actor* actor, bool apply);
    virtual void RemoveEntryPointEffect(Actor* actor, bool remove);

    void LoadFromSaveData(const void* data);
    void* Destroy(unsigned int);
    int GetInnerValue();
    void TESObjectREFR_SetCurrentWaterObject(int value);
    TESBoundObject* BGSSaveFormBuffer_GetForm();
    TESWorldSpace* TESObjectREFR_GetWorldSpace();
    bool FUN_00440da0();
};
