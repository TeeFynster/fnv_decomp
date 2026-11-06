#pragma once

#include "QueuedFile.h"

class MagicItem;
class EffectSetting;

class QueuedMagicItem : public QueuedFile
{
public:
    QueuedMagicItem(MagicItem*, EffectSetting*, IO_TASK_PRIORITY);

    virtual ~QueuedMagicItem();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE state, void* parent);
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual void ProcessLoadedAnimIdle();
    virtual void GenerateKey();
    virtual void ChangePriority(IO_TASK_PRIORITY priority);
    virtual void DispatchToManager();
    virtual void HandleChildCompletion(QueuedFile* apChild);
    virtual void OnChildCompletion();

    MagicItem* pMagicItem;
    EffectSetting* m_pEffectSetting;
};
