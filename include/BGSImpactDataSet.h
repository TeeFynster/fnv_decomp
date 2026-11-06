#pragma once

#include "TESForm.h"
#include "BGSPreloadable.h"

class BGSImpactData;
class ImpactSwap;
class QueuedFile;
class TESFile;

struct BGSImpactDataSet : public TESForm, public BGSPreloadable
{
public:
    BGSImpactDataSet();
    virtual ~BGSImpactDataSet();

    void ResetFormData();
    bool Load(TESFile* file);
    virtual void InitItem();
    static void CacheImpactDataSet();
    static void RefreshImpactData(ImpactSwap* swap);
    virtual void QueueResourceLoad(IO_TASK_PRIORITY priority, QueuedFile* file);
    BGSImpactData* GetImpactDataForMaterial(int material);
    void Save();
    void Copy(TESForm* form);
    virtual bool Compare(TESForm* form);

    static BGSImpactDataSet* ms_pImpactDataSet;

    BGSImpactData* m_apImpactData[12];
};
