// src/havok/physics/collide/agent/compoundagent/list/hkplistagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/list/hkplistagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkpListAgent.h"

extern "C" void __cdecl hkpAgent1nSector_ProcessEntries_00da3510(void*, void*);

struct hkAgent1nMachine
{
    void __thiscall InvalidateTim(void*);
};

// @fnv 0x00d36850
void __thiscall hkpListAgent::vf09(void* arg)
{
    hkpAgent1nSector_ProcessEntries_00da3510(&m0[4], arg);
}

extern "C" void __cdecl Hkpshapecollectionagent_ForwardCall_00d36990(int, int, int, int);

// @fnv 0x00d36b00
// src: HAVOK_SRC 0x00d36b00
void __stdcall hkpListAgent_getPenetrations(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    Hkpshapecollectionagent_ForwardCall_00d36990(aiArg1, aiArg2, aiArg3, aiArg4);
}

extern "C" void __cdecl _hkAgent1nMachine_WarpTime(void*, float, float, int);
// The shared class does not yet declare these method signatures. The unused
// EDX parameter preserves their original ECX receiver and stack arguments.
// Forwards the three arguments to FUN_00da35f0 with the object's field at offset 0x10 as its first argument.
// @fnv 0x00d36870
void __fastcall hkpListAgent_warpTime(hkpListAgent* agent, void*, float afValue1, float afValue2, int aiValue)
{
    _hkAgent1nMachine_WarpTime(&agent->m0[4], afValue1, afValue2, aiValue);
}

void __cdecl Object_QueryClosestPoints_Thunk(void* a, void* b, void* c, void* d);

// @fnv 0x00d36940
// src: HAVOK_SRC 0x00d36940
void __stdcall hkpListAgent_getClosestPoints(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    Object_QueryClosestPoints_Thunk(apArg1, apArg2, apArg3, apArg4);
}

void __cdecl hkpConvexListAgent_ForwardCall_00d36930(int a1, int a2, int a3, int a4, int a5);

// Forwards all five arguments to FUN_00d36930.
// @fnv 0x00d36960
// src: HAVOK_SRC 0x00d36960
void __stdcall hkpListAgent_linearCast(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5)
{
    hkpConvexListAgent_ForwardCall_00d36930(aiArg1, aiArg2, aiArg3, aiArg4, aiArg5);
}

extern "C" void __cdecl hkAgent1nMachine_Destroy(void* a, int b, int c, int d);

// Releases the agent track, then invokes the deleting destructor.
// @fnv 0x00d36820
void __fastcall hkpListAgent_cleanup(hkpListAgent* agent, void*, int aiValue)
{
    hkAgent1nMachine_Destroy(&agent->m0[4], *(int*)agent->m0, (int)agent->m_pContactManager, aiValue);
    typedef void (__thiscall *DeletingDestructor)(hkpListAgent*, int);
    (*(DeletingDestructor**)agent)[0](agent, 1);
}

struct S_00d368a0_Arg
{
    int unk00;
    int unk04;
    int m_field08;
};

void __cdecl hkpAgentMachineUtil_calc1nStatistics(void* sub, int field08, S_00d368a0_Arg* arg);

// @fnv 0x00d368a0
void __fastcall hkpListAgent_updateShapeCollectionFilter(hkpListAgent* agent, void*, S_00d368a0_Arg* a, int unused)
{
    hkpAgentMachineUtil_calc1nStatistics(&agent->m0[4], a->m_field08, a);
}

extern "C" void __cdecl hkAgent1nMachine_UpdateShapeCollectionFilter(void*, void*);

struct VirtTarget
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c();
    virtual int v10();
};

struct CallArgs
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

// Builds the collision arguments and processes the agent track.
// @fnv 0x00d368c0
void __fastcall hkpListAgent_processCollision(hkpListAgent* agent, void*, void* a1, void* a2, void* a3, void* a4)
{
    CallArgs s;
    s.unk00 = (int)a1;
    s.unk10 = (int)a3;
    int iStored = (int)agent->m_pContactManager;
    s.unk04 = (int)a2;
    s.unk14 = iStored;
    s.unk18 = (int)a4;
    s.unk0C = (*(VirtTarget**)a2)->v10();
    hkAgent1nMachine_UpdateShapeCollectionFilter(&agent->m0[4], &s);
}
