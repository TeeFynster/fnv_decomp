// gamebryo2.2/corelibs/nimain/niparallelupdatetaskmanager_inl_decls.h: declares NiParallelUpdateTaskManager
#ifndef FNV_NIPARALLELUPDATETASKMANAGER_INL_DECLS_H
#define FNV_NIPARALLELUPDATETASKMANAGER_INL_DECLS_H

int NiParallelUpdateTaskManager_Get();
bool NiParallelUpdateTaskManager_IsActive();
void NiParallelUpdateTaskManager_EndUpdate();
void NiParallelUpdateTaskManager_WaitRenderSema(int);
class NiParallelUpdateTaskManager
{
  public:
    void SetupTaskWorkers();
};
#endif
