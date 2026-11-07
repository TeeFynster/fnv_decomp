
// src/havok/physics/collide/dispatch/hkpagentregisterutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/dispatch/hkpagentregisterutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FlagCBFD
{
    bool m_bValue;
    FlagCBFD(bool bValue) : m_bValue(bValue)
    {}
    FlagCBFD(const FlagCBFD& kOther) : m_bValue(kOther.m_bValue)
    {}
};

class WorldCBFD
{
  public:
    void FUN_00cfb1e0(FlagCBFD kFlag);
};

void __cdecl hkpCollisionDispatcher_ProcessState_00d46410(WorldCBFD* pkWorld);
void __cdecl ConfigureVtblHandlers(WorldCBFD* pkWorld);
void __cdecl RegisterTwoTables(WorldCBFD* pkWorld);
void __cdecl RegisterAll(WorldCBFD* pkWorld);
void __cdecl hkpShapeCollectionAgent_registerAgent(WorldCBFD* pkWorld);
void __cdecl hkpAgentRegisterUtil__registerListAgents(WorldCBFD* pkWorld);
void __cdecl RegisterCallbacks(WorldCBFD* pkWorld);
void __cdecl Object_UpdateFields_00d42960(WorldCBFD* pkWorld);
void __cdecl hkpAgentRegisterUtil__registerTerminalAgents(WorldCBFD* pkWorld);

// Calls a sequence of registration and configuration functions on pkWorld, toggling a flag between two of them.
// @fnv 0x00cbfd20
void __cdecl InitializeWorld(WorldCBFD* pkWorld)
{
    hkpCollisionDispatcher_ProcessState_00d46410(pkWorld);
    ConfigureVtblHandlers(pkWorld);
    RegisterTwoTables(pkWorld);
    RegisterAll(pkWorld);
    pkWorld->FUN_00cfb1e0(FlagCBFD(false));
    hkpShapeCollectionAgent_registerAgent(pkWorld);
    pkWorld->FUN_00cfb1e0(FlagCBFD(true));
    hkpAgentRegisterUtil__registerListAgents(pkWorld);
    RegisterCallbacks(pkWorld);
    Object_UpdateFields_00d42960(pkWorld);
    hkpAgentRegisterUtil__registerTerminalAgents(pkWorld);
}
