#include "../../include/InterfaceManager.h"
// bscore/bssimplelist_packet.h: unit-local helper declarations
#ifndef FNV_BSSIMPLELIST_PACKET_H
#define FNV_BSSIMPLELIST_PACKET_H

#include "bssimplelist_decls.h"
class QuantityData
{
  public:
    QuantityData();
    void SetQuantity(unsigned int);
};
class MersenneTwister
{
  public:
    static MersenneTwister* GetRandomGenerator();
    unsigned int IntInRange(int, int);
};

class ActorCause;
class SpellItem;
class ScriptVariableInfo;
class Tile;

template <> void BSSimpleList<ActorCause*>::RemoveAll();
template <> void BSSimpleList<SpellItem*>::AddHead(SpellItem*&);

#endif
