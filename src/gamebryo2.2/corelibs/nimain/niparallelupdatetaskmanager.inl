
#include "niparallelupdatetaskmanager_inl_decls.h"

// @fnv 0x00872ad0
void NiParallelUpdateTaskManager::SetupTaskWorkers()
{
    if (NiParallelUpdateTaskManager_Get()) {
        if (NiParallelUpdateTaskManager_IsActive()) {
            NiParallelUpdateTaskManager_EndUpdate();
        }
        NiParallelUpdateTaskManager_WaitRenderSema(3);
    }
}
