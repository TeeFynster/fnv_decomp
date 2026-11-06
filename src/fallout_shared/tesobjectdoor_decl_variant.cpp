
// src/fallout_shared/tesobjectdoor_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00517500: the skeleton of src/fallout_shared/tesobjectdoor.cpp
// with declarations corrected to what the original code does (tesobjectdoor_decls.h: TESObjectDOOR += ~TESObjectDOOR();). Move the function to its real unit once
// that unit declares it this way.

#include "../../include/Actor.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSOpenCloseForm.h"
#include "../../include/BSAudio.h"
#include "../../include/BaseProcess.h"
#include "../../include/DoorAccessData.h"
#include "../../include/ExtraLock.h"
#include "../../include/NiPoint3.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/Setting.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/TES.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESObjectDOOR.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESSound.h"

// @fnv 0x00517500
TESObjectDOOR::~TESObjectDOOR()
{
    ClearData();
}
