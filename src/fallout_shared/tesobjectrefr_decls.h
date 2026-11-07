#include "../../include/SettingT.h"
#include "../../include/SETTING_VALUE.h"
// fallout_shared/tesobjectrefr_decls.h: declares TESObjectREFR, DurationData
#include "../../include/TESObjectREFR.h"
#ifndef FNV_TESOBJECTREFR_DECLS_H
#define FNV_TESOBJECTREFR_DECLS_H

// Private declarations for fallout_shared/tesobjectrefr.cpp (unit army-glm-5257).
// Signatures follow the canonical bindings from IDENTITIES.md / lookup sym;
// layouts here are minimal and private to this translation unit.



class GameSettingCollection;

extern SettingT<GameSettingCollection> DAT_011f6da8;
extern SettingT<GameSettingCollection> DAT_011f6db4;

class GlobalObject_00559cc0
{
  public:
    bool RemoveAt(unsigned int);
};
extern GlobalObject_00559cc0 g_011ca304;

class GlobalObject_00593240
{
  public:
    char storage[4];
};
extern GlobalObject_00593240 g_011ca8b4;

class GlobalObject_00878030
{
  public:
    char storage[4];
};
extern GlobalObject_00878030 g_011deffc;

class GarbageCollectorUpdateState;

class BGSEncounterZone;
extern BGSEncounterZone* DAT_011c9520;
extern unsigned char DAT_011c7a58;
extern unsigned char DAT_011dd435;


class DurationData
{
  public:
    char month;  // +0x0
    int PackageLocation_GetLocType();
};

#endif
