#ifndef FNV_BGSADDONNODE_TYPES_H
#define FNV_BGSADDONNODE_TYPES_H

#include "layout_support.h"
#include "../../include/BGSAddonNode.h"
#include "../../include/FileEntryList.h"
#include "../../include/ShortPoint3.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESBoundObject__BOUND_DATA.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESObject.h"

#pragma pack(push, 4)
class AddonNodeData
{
  public:
    void BSEndian_Thunk();
    unsigned short m_usAddonNodeIndex;  // +0x0, 2 bytes
    unsigned char cFlags;               // +0x2, 1 bytes
    unsigned char layoutPadding3[1];
    // void __cdecl AddonNodeData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(AddonNodeData) == 4);
FNV_STATIC_ASSERT(offsetof(AddonNodeData, m_usAddonNodeIndex) == 0);
FNV_STATIC_ASSERT(offsetof(AddonNodeData, cFlags) == 2);
#endif
