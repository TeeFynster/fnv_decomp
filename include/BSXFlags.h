#pragma once

#include "NiIntegerExtraData.h"

class BSXFlags : public NiIntegerExtraData
{
  public:
    BSXFlags();                          // 0x00c42f70 (TESObjectDOOR::Create3DModel allocates 0x10 and runs it)
    void BSXFlags_SetFlags(bool, bool);       // 0x00519230, called on the "BSX" extra data
    unsigned int GetFlags(unsigned int flags) const;
    unsigned int GetFlags(unsigned int flags);
    bool GetAddon() const;
    bool IsBitSet() const;
};
