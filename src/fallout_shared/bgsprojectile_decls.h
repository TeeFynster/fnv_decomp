#include "../../include/InterfaceManager.h"
// Declarations local to the BGSProjectile unit.
#ifndef FNV_BGSPROJECTILE_DECLS_H
#define FNV_BGSPROJECTILE_DECLS_H

void* operator new(unsigned int size);

class BGSProjectileFloatNode
{
  public:
    float value;
    BGSProjectileFloatNode* next;
    BGSProjectileFloatNode(const BGSProjectileFloatNode& other);
    void AddHead(const float& value);
};


class Tile;

#endif
