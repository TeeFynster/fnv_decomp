#pragma once

class TESFile;
class TESForm;

class BGSEntryPointFunctionData
{
public:
    virtual ~BGSEntryPointFunctionData();
    virtual unsigned char GetType();
    virtual BGSEntryPointFunctionData* Duplicate();
    virtual bool Compare(BGSEntryPointFunctionData* other);
    virtual void Save();
    virtual void Load(TESFile* file);
    virtual void InitItem(TESForm* form);
};
