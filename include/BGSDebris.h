#pragma once

#include "TESForm.h"
#include "BGSPreloadable.h"
#include "MagicTarget.h"

class DebrisModelEntry;
struct NiPoint3;

class BGSDebris : public TESForm, public BGSPreloadable
{
public:
    BSSimpleList<DebrisModelEntry*> DataList;

    BGSDebris();
    virtual ~BGSDebris();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* file);
    virtual void QueueResourceLoad(IO_TASK_PRIORITY priority, QueuedFile* file);
    virtual void CopyFrom(const TESForm* source);
    virtual bool Compare(TESForm* form);

    BSSimpleList<DebrisModelEntry*>* GetDataList();
    BSSimpleList<DebrisModelEntry*>* GetData();
    bool Load(TESFile* file);
    void Preload(int priority, void* file);
    DebrisModelEntry* AddDebrisModel(char chance, const char* path, char flags);
    void InsertDebrisIfValid(DebrisModelEntry* entry);
    void WriteDebrisEntries();
    void SpawnDebris(void* cell, NiPoint3* position, unsigned int count, float scale);
};
