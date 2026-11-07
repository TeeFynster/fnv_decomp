#pragma once

#include "IOTask.h"
#include "NiAVObject.h"

enum MEM_CONTEXT;
class QueuedChildren;
class QueuedParents;

class QueuedFile : public IOTask
{
public:
    QueuedFile(IO_TASK_PRIORITY priority);
    QueuedFile(int priority);

    virtual ~QueuedFile();
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

    QueuedFile& operator=(const QueuedFile& other);
    void SetParent(QueuedFile* apParent);
    void AddAdditionalParent(QueuedFile* apParent);
    unsigned int GetChildCount();
    unsigned int GetChildCountFinished();
    bool GetAllChildrenFinished();
    void AddChild(QueuedFile* apChild);
    void IncRefCount();
    void DecRefCount();
    bool QueuedFile_GetAllChildrenFinished();

    MEM_CONTEXT aeMemoryContext;        // 0x18
    NiPointer<QueuedFile> m_pParent;     // 0x1C
    QueuedChildren* pChildren;          // 0x20
    QueuedParents* pAdditionalParents;  // 0x24
};
