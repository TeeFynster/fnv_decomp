
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
    void FUN_00449210(int, QHeadPtr*);
};
struct FUN_0043d6b0_shell
{
    void __thiscall FUN_0043d6b0(IOTask* aHead);
};
// Wraps aHead in a QHeadPtr and passes its priority and the wrapper to the object at this+0x64 via FUN_00449210.
// @fnv 0x0043d6b0
void FUN_0043d6b0_shell::FUN_0043d6b0(IOTask* aHead)
{
    QHeadPtr head(aHead);
    (*(C_00449210**)((char*)this + 0x64))->FUN_00449210(aHead->GetPriority(), &head);
}
