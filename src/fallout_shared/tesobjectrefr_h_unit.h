// fallout_shared/tesobjectrefr_h_unit.h: declares TESObjectREFR
#ifndef FNV_TESOBJECTREFR_WRAPPER_H
#define FNV_TESOBJECTREFR_WRAPPER_H
#include "../../include/TESObjectREFR.h"

// @fnv 0x008d47d0
void TESObjectREFR::Get3D(NiNode* niNode, bool unloadArt)
{
    TESObjectREFR::Set3D(niNode, unloadArt);
}
#endif
