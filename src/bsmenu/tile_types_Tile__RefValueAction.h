// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TILE_REFVALUEACTION_H
#define FNV_TILE_REFVALUEACTION_H

#include <stddef.h>
#include "Tile__Action.h"
class Tile__RefValueAction;
class Tile__Value;
#pragma pack(push, 4)
class Tile__RefValueAction : public Tile__Action
{
  public:
    // base Tile::Action at +0x0, size 12
    Tile__Value* m_pReferencedValue;  // +0xC, 4 bytes
    float GetStoredFloatValue();
    // float __cdecl Tile::RefValueAction::*()
    // Tile::Value* __cdecl Tile::RefValueAction::*()
    // RefValueAction
    // Tile::RefValueAction& __cdecl Tile::RefValueAction::*(const Tile::RefValueAction&)
};
#pragma pack(pop)
typedef char Tile_RefValueAction_size_check[(sizeof(Tile__RefValueAction) == 16) ? 1 : -1];
typedef char Tile_RefValueAction_value_offset_check[(offsetof(Tile__RefValueAction, m_pReferencedValue) == 12) ? 1 : -1];
#endif
