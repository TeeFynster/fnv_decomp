#pragma once

// VATSEffectTarget: one target of the VATS screen effect, no vtable. 8 bytes: FOVATSEffectManager's constructor
// 0x007ffec0 builds one at +0x04 and an array of 32 at +0x14 with the eh vector constructor iterator (element size 8,
// count 0x20, ctor 0x00800170, dtor 0x00800190); the constructor 0x00800170 only constructs the NiPointer at +0x04
// (0x00633c90). The pointee types are not established (FOVATSEffectManager::SetTarget 0x00800ac0 calls vtable slot
// 0x1d0 on what it points to).

#include "NiPointer.h"

class NiRefObject;

class VATSEffectTarget
{
public:
    void* pTarget;                    // 0x00
    NiPointer<NiRefObject> spObject;  // 0x04

    VATSEffectTarget();               // 0x00800170
    ~VATSEffectTarget();              // 0x00800190 (folded with ProjectileTarget::~ProjectileTarget)
};
