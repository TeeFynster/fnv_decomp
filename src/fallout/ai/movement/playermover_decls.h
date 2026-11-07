// Declarations used by the player movement implementation.
#ifndef FNV_PLAYERMOVER_DECLS_H
#define FNV_PLAYERMOVER_DECLS_H

class Animation
{
  public:
    unsigned short Animation_GetGroup(int);
    bool GetMovementDelta(NiPoint3*, TESObjectREFR*, bool, bool);
    NiControllerSequence* GetControllerSequence(int);
    void BlendOut(int, bool);
};
extern PlayerCharacter* g_thePlayer;
#include "../../../../include/SETTING_VALUE.h"
#include "../../../../include/SettingT_GameSettingCollection_.h"
extern SettingT_GameSettingCollection_ DAT_011cdf28;
namespace std {
float abs(float);
}
float cos(float);
#endif
