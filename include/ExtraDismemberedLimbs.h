#pragma once

#include "BSExtraData.h"
#include "ShadowSceneLight.h"

class DismembermentPart;

class ExtraDismemberedLimbs : public BSExtraData
{
public:
    ExtraDismemberedLimbs();
    virtual ~ExtraDismemberedLimbs();

    unsigned int GetCount();
    DismembermentPart* GetInfoAt(unsigned int index);
    bool IsBitSet(int limb);
    void SetBit(int limb, bool removed);
    void* __thiscall Destroy();
    void* __thiscall ReleaseIfFlagged(unsigned int flags);
    void* __thiscall FUN_004302d0();
    void* __thiscall FUN_004302a0(unsigned int flags);

    unsigned char unk0C[0x14];
    BSSimpleArray<DismembermentPart*, 1024> parts;
};
