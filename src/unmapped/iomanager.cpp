
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/IOTask.h"
#include "../../include/QueuedFile.h"
#include "../../include/QueuedFileLoad.h"
#include "../../include/QueuedMagicItem.h"

// @fnv 0x0043daa0
void QueuedFileLoad::Finish()
{
    QueuedFile::Finish();
}

// @fnv 0x0043db30
QueuedMagicItem::QueuedMagicItem(MagicItem* aMagicItem, EffectSetting* aEffect, IO_TASK_PRIORITY aPriority) : QueuedFile(aPriority)
{
    pMagicItem = aMagicItem;
    m_pEffectSetting = aEffect;
}

struct QHeadPtr
{
    IOTask* pHead;
    QHeadPtr(IOTask* pHead);
    ~QHeadPtr();
};
struct C_00449210
{
    void LockFreePriorityQueue_NiPointer_IOTask_Push(int, QHeadPtr*);
};
struct FUN_0043d6b0_shell
{
    void __thiscall IOManager_AddPostProcessTask(IOTask* aHead);
};
// Wraps aHead in a QHeadPtr and passes its priority and the wrapper to the object at this+0x64 via FUN_00449210.
// @fnv 0x0043d6b0
// src: XBOX_PDB 0x0043d6b0
void FUN_0043d6b0_shell::IOManager_AddPostProcessTask(IOTask* aHead)
{
    QHeadPtr head(aHead);
    (*(C_00449210**)((char*)this + 0x64))->LockFreePriorityQueue_NiPointer_IOTask_Push(aHead->GetPriority(), &head);
}
