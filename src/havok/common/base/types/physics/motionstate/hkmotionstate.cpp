
// src/havok/common/base/types/physics/motionstate/hkmotionstate.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/physics/motionstate/hkmotionstate.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMotionState.h"

struct FUN_00c9ea90_Base
{
    virtual void b0();
    FUN_00c9ea90_Base(int a, int b);
};

struct FUN_00c9ea90 : FUN_00c9ea90_Base
{
    virtual void v0();
    FUN_00c9ea90(int a1);
};

struct __declspec(align(16)) FUN_00827200_class
{
    int unk00;
    int unk04;
    void __thiscall FUN_00cb26e0(int);
};

struct FUN_00cf2410_class
{
    int __thiscall hkMotionState_initMotionState(int, void*);
};

class FUN_00c9ea40_cls : public FUN_00c9ea90
{
  public:
    virtual ~FUN_00c9ea40_cls();
    virtual void v1();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkMotionState* m_motionPtr;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    unsigned char m_sweptStorage[sizeof(hkMotionState)];
    __declspec(property(get=GetSweptStorage)) hkMotionState m_swept;
    __forceinline hkMotionState& GetSweptStorage() { return *reinterpret_cast<hkMotionState*>(m_sweptStorage); }

    FUN_00c9ea40_cls(int a, int b);
};

// Calls the base constructor, initializes a temporary from b, passes it with b + 0x30 to FUN_00cf2410, and points m_motionPtr at m_swept.
// @fnv 0x00c9ea40
FUN_00c9ea40_cls::FUN_00c9ea40_cls(int a, int b) : FUN_00c9ea90(a)
{
    FUN_00827200_class tmp;
    tmp.FUN_00cb26e0(b);
    ((FUN_00cf2410_class*)&m_swept)->hkMotionState_initMotionState(b + 0x30, &tmp);
    m_motionPtr = &m_swept;
}
