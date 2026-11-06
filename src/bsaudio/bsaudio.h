#include "bsaudio_player_decls.h"

// MobileObject::Unk_96 (slot 0x258) lacks its Boolean argument in the shared declaration.
typedef void (__thiscall* PlayerAIControlVirtual)(PlayerCharacter*, bool);

// @fnv 0x0093a5f0
void PlayerCharacter::SetUnderAIControl(bool enabled)
{
    underAIControl = enabled;
    if (GetUnderAIControl())
        reinterpret_cast<PlayerAIControlVirtual>((*reinterpret_cast<void***>(this))[0x258 / sizeof(void*)])(this, false);
    else
        reinterpret_cast<PlayerAIControlVirtual>((*reinterpret_cast<void***>(this))[0x258 / sizeof(void*)])(this, true);
}
// @fnv 0x00950290
void PlayerCharacter::UpdateCameraMode()
{
    bool changed = thirdPerson != previousThirdPerson;
    if (!changed)
        return;
    if (DAT_011e07dc > DAT_0101db88)
        return;
    previousThirdPerson = thirdPerson;
    if (!DAT_011e07b8 && firstPersonNode.operator->() && !previousThirdPerson)
        Show1stPerson(!previousThirdPerson);
}
