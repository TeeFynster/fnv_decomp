#pragma once

// LipSyncBackgroundManager: background lip-sync loading, no vtable of its own. ProcessLists holds it by value at
// +0x10360; its constructor 0x00905e30 only constructs the LockFreeMap<MobileObject*, NiPointer<LipTask> > at +0x00
// (0x00906160 with 10, 0x25, 0xc), so 0x40 bytes, 32-byte aligned.

#include "LockFreeMap.h"
#include "NiPointer.h"

class LipTask;
class MobileObject;

class LipSyncBackgroundManager
{
  public:
    LockFreeMap<MobileObject*, NiPointer<LipTask> > kLipMap;  // 0x00

    LipSyncBackgroundManager();                              // 0x00905e30
};
