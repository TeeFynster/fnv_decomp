// Sandbox animation APIs not yet provided by the shared headers.
#ifndef SANDBOXPACKAGE_IDLE_H
#define SANDBOXPACKAGE_IDLE_H

#include "../../../include/Actor.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
#include "sandboxpackage.h"
#include "../../../include/BaseProcess.h"  // not src/fallout/ai/BaseProcess.h (a body file that reaches layout_support.h)
#include "../../../include/TimeoutTimer.h"

class Animation
{
  public:
    bool IsSequenceActive();
    BSAnimGroupSequence* GetPlayingSequence();
};

extern SettingT_GameSettingCollection_ g_011cde98;
extern TESBoundObject* DAT_011ca244;
extern TESBoundObject* DAT_011ca248;
extern const float runtimeFloatSettingDefault94;
extern float DAT_010249d8;
float AiFormulas_ComputeRandomSandboxSubProcessDuration(void*, SANDBOX_PROCEDURE);
#endif
