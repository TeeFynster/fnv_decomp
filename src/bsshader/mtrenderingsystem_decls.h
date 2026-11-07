#include "../../include/BSRenderedTexture.h"
// bsshader/mtrenderingsystem_decls.h: declares TaskThreadManager, BSRenderedTexture; AILinearTaskThread and NiRenderer come from include/
#ifndef MTRENDERINGSYSTEM_DECLS_H
#define MTRENDERINGSYSTEM_DECLS_H
class TaskThreadManager
{
  public:
    static TaskThreadManager* GetSingleton();
    void StartRenderingTaskThread();
    static void EndRenderingTaskThread();
    void LaunchWorkerThread(int, unsigned int, void(__cdecl*)(), const char*, unsigned int);
};
extern TaskThreadManager DAT_01200088;
extern bool DAT_011f94b4;
extern unsigned int DAT_01200080;
void __cdecl MTRenderingSystem_TaskThreadCallback();
#include "../../include/AILinearTaskThread.h"

#include "../../include/NiRenderer.h"
typedef char check_AILinearTaskThread_task[offsetof(AILinearTaskThread, m_pTaskFunction) == 0x4c ? 1 : -1];
#endif
