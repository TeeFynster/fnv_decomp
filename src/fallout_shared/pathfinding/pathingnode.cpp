
// src/fallout_shared/pathfinding/pathingnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/TESObjectREFR.h"

struct FUN_006e2330_shell
{
    bool __thiscall PathingNode_IsTeleportDoorNode();
};

struct FUN_006e22f0_shell : public FUN_006e2330_shell
{
    TESObjectREFR* m_pDoorRef;
    bool __thiscall PathingNode_ActivateNode(TESObjectREFR* apActor);
};

// If FUN_006e2330() succeeds, activates the reference stored at offset 0x38 with apActor, returning the result; otherwise returns false.
// @fnv 0x006e22f0
// src: COMMUNITY 0x006e22f0
bool __thiscall FUN_006e22f0_shell::PathingNode_ActivateNode(TESObjectREFR* apActor)
{
    if (PathingNode_IsTeleportDoorNode())
        return ((TESObjectREFR**)((char*)this + 0x38))[0]->Activate(apActor, false, (TESObjectREFR*)0, 1);
    return false;
}

struct FUN_0045bb20_target
{
    void __thiscall Apply(float x, float y, float z);
};

struct FUN_0045bb20_cls
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;

    FUN_0045bb20_target* ApplyScaled(FUN_0045bb20_target* target, float scale);
};

// Calls target->Apply with each stored component multiplied by scale and returns target.
// @fnv 0x0045bb20
FUN_0045bb20_target* FUN_0045bb20_cls::ApplyScaled(FUN_0045bb20_target* target, float scale)
{
    target->Apply(scale * m_uiX, scale * m_uiY, scale * m_uiZ);
    return target;
}
