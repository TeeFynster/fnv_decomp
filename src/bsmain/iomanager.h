
#include "iomanager_decls.h"
// @fnv 0x0043d690
void IOManager::SubmitTask()
{
    DAT_01202d98->IOManager_AddPostProcessTask(this);
}
// @fnv 0x0043db70
void IOTask::GenerateKey()
{
    SetKey(3, InitScriptRunLockTask(), GetPriority(), IOTask_GetNextCounter());
}
