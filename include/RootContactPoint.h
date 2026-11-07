#pragma once

#include "hkContactPoint.h"

class hkpCollidable;

// The 0x70-byte collision point the game's cd-point collectors store (16-byte aligned: the
// fixed-buffer collector copies it with memCpy16 in 7-quad units). 0x006212c0 is its /Od copy:
// hkContactPoint::operator= (0x006281a0) for +0x00, then per body the root collidable, the
// shape key and eight more dwords.
class RootContactPoint
{
public:
    RootContactPoint* InitializeFields_006212c0(void* apSource);

    hkContactPoint m_kContact;               // +0x00
    const hkpCollidable* m_pRootCollidableA; // +0x20
    unsigned int m_uiShapeKeyA;              // +0x24
    unsigned int m_auiUnk28[8];              // +0x28
    const hkpCollidable* m_pRootCollidableB; // +0x48
    unsigned int m_uiShapeKeyB;              // +0x4C
    unsigned int m_auiUnk50[8];              // +0x50
};
