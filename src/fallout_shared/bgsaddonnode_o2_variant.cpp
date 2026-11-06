// src/fallout_shared/bgsaddonnode_o2_variant.cpp - /O2 adjustment thunk for BGSAddonNode.

#include "layout_support.h"
#include "../../include/BGSAddonNode.h"
#include "../../include/FileEntryList.h"
#include "../../include/ShortPoint3.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESBoundObject__BOUND_DATA.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESObject.h"
#include "../../include/TESSound.h"
#include "bgsaddonnode_types_BGSAddonNode.h"
#include "bgsaddonnode_decls.h"

// Emit the vtables and the secondary-base deleting-destructor thunk at 0x004f93a0.
// The TESModelTextureSwap base starts at +0x30 in BGSAddonNode.
BGSAddonNode::BGSAddonNode()
{}
