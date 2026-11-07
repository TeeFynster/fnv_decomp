#include "../../../include/InterfaceManager.h"
// fallout_shared/magic/magicformulas_packet.h: declares FlaggedData, InterfaceManager
#ifndef MAGICFORMULAS_PACKET_H
#define MAGICFORMULAS_PACKET_H

class FlaggedData
{
    unsigned char padding[0x40];
    unsigned char flags;

  public:
    int ContainsAnyFlag(unsigned int mask);
    static int GetPlayerValue();
};
class QuestStage
{
  public:
    unsigned char GetIndex();
};

InterfaceManager* InterfaceManager_GetSingleton();
#endif
