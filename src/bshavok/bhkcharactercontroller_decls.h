#ifndef BHKCHARACTERCONTROLLER_PACKET_DECLS_H
#define BHKCHARACTERCONTROLLER_PACKET_DECLS_H

#include "../../include/MobileObject.h"
#include "../../include/bhkCharacterController.h"

class CharacterControllerValue
{
  public:
    int value;
    CharacterControllerValue(int initial);
};

struct CollisionFilter
{
    int value;
};

#endif
