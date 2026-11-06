#pragma once

#include "TESForm.h"
#include "TESModel.h"
#include "BGSPreloadable.h"

class BGSBodyPart;
class BGSRagdoll;
class TESFile;
class QueuedFile;
enum IO_TASK_PRIORITY;

class BGSBodyPartData : public TESForm, public TESModel, public BGSPreloadable
{
public:
    BGSBodyPart* m_apBodyParts[15];
    BGSRagdoll* m_pRagdoll;

    BGSBodyPartData();
    virtual ~BGSBodyPartData();

    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* modInfo);
    virtual void InitItem(void);
    virtual void QueueResourceLoad(IO_TASK_PRIORITY priority, QueuedFile* file);

    void FUN_005e4bc0();
    void ResetFormData();
    void ClearBodyParts();
    bool Load(TESFile* file);
    void AddBodyPart(BGSBodyPart* part);
    BGSBodyPart* GetPart(unsigned int limbIndex);
    BGSBodyPart* GetValueByIndex(int limb);

    static void InitializeBodyPartData();
    static BGSBodyPartData* ms_pBodyPartData;
    static BGSBodyPartData* ms_pBodyPartDataInstance;
};
