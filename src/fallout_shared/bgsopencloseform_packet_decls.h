#include "../../include/ProcessLists.h"
// Private animation and event declarations for bgsopencloseform_ctxr_variant.cpp.
#ifndef BGSOPENCLOSEFORM_PACKET_DECLS_H
#define BGSOPENCLOSEFORM_PACKET_DECLS_H

#include "../../include/ENUM_FORM_ID.h"
#include "../../include/NavMeshObstacleManager.h"
class NiProperty;
class SkyShaderProperty;
SkyShaderProperty* NiObject_DynamicCast(const NiRTTI*, NiProperty*);
extern NiRTTI DAT_011f36ac;
#include "../../include/OBJECT_ACTION.h"
class AIThreadManager
{
  public:
    static TESObjectREFR* IsConditionMet();
};
bool IsConditionMet();
class TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
    void TaskQueueInterface_QueueSetOpenState(TESObjectREFR*, bool, bool);
};

class GlobalObject_0045cf30
{
};
extern GlobalObject_0045cf30 g_011d7188;
extern const char DAT_01011f30[];
extern const char g_011d22b0_arg1[];
extern float DAT_0101ab70;
void bhkNiCollisionObject_ResetSim(NiNode*, bool);
#endif
