
// src/havok/physics/dynamics/world/util/broadphase/hkpentityentitybroadphaselistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/broadphase/hkpentityentitybroadphaselistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct D10800Block256
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
};

struct D10800Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    short unk18;
    signed char m_iAutoRemoveLevel;
};

struct D10800TypedHandle
{
    int m_iOwnerObjectOffset;
    unsigned char m_type;
    signed char m_iOwnerOffset;

    D10800Collidable* getOwner() const
    {
        return reinterpret_cast<D10800Collidable*>(const_cast<char*>(reinterpret_cast<const char*>(this)) +
                                                   m_iOwnerOffset);
    }
};

struct D10800HandlePair
{
    D10800TypedHandle* m_kPointA;
    D10800TypedHandle* m_kPointB;
};

struct D10800QualityInfo
{
    int m_data;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

struct D10800Dispatcher
{
    D10800Block256 m_block00;
    D10800Block256 m_block01;
    D10800Block256 m_block02;
    D10800Block256 m_block03;
    D10800Block256 m_block04;
    D10800Block256 m_block05;
    D10800Block256 m_block06;
    D10800Block256 m_block07;
    D10800Block256 m_block08;
    D10800Block256 m_block09;
    D10800Block256 m_block10;
    D10800Block256 m_block11;
    D10800Block256 m_block12;
    D10800Block256 m_block13;
    D10800Block256 m_block14;
    D10800Block256 m_block15;
    D10800Block256 m_block16;
    D10800Block256 m_block17;
    D10800Block256 m_block18;
    D10800Block256 m_block19;
    D10800Block256 m_block20;
    D10800Block256 m_block21;
    D10800Block256 m_block22;
    D10800Block256 m_block23;
    D10800Block256 m_block24;
    D10800Block256 m_block25;
    D10800Block256 m_block26;
    int unk1B00;
    int unk1B04;
    int unk1B08;
    int unk1B0C;
    int unk1B10;
    int unk1B14;
    int unk1B18;
    int unk1B1C;
    int unk1B20;
    int unk1B24;
    int unk1B28;
    int unk1B2C;
    int unk1B30;
    int unk1B34;
    int unk1B38;
    int unk1B3C;
    int unk1B40;
    int unk1B44;
    int unk1B48;
    int unk1B4C;
    int unk1B50;
    int unk1B54;
    int unk1B58;
    int unk1B5C;
    int unk1B60;
    int unk1B64;
    int unk1B68;
    int unk1B6C;
    int unk1B70;
    int unk1B74;
    int unk1B78;
    int unk1B7C;
    int unk1B80;
    int unk1B84;
    int unk1B88;
    int unk1B8C;
    int unk1B90;
    int unk1B94;
    int unk1B98;
    int unk1B9C;
    int unk1BA0;
    int unk1BA4;
    int unk1BA8;
    int unk1BAC;
    unsigned char m_aucByteGrid[10][10];
    int unk1C14;
    int unk1C18;
    int unk1C1C;
    int unk1C20;
    int unk1C24;
    int unk1C28;
    int unk1C2C;
    D10800QualityInfo m_pCollisionQualityInfo[8];
};

struct D10800Input
{
    D10800Dispatcher* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_pCollisionQualityInfo;
};

void __cdecl hkpWorldAgentUtil_addAgent(D10800Collidable* collA, D10800Collidable* collB, D10800Input* input);

struct D10800World
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
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
    D10800Input* m_pCollisionInput;
};

struct D10800Listener
{
    int unk00;
    D10800World* m_pOwningWorld;

    void DispatchCollisionPair(D10800HandlePair& pair);
};

// Resolves both handles to collidables, looks up a quality index from the dispatcher grid, and if nonzero stores its data in input and calls FUN_00cc0f40.
// @fnv 0x00d10800
void D10800Listener::DispatchCollisionPair(D10800HandlePair& pair)
{
    D10800Collidable* collA = pair.m_kPointA->getOwner();
    D10800Collidable* collB = pair.m_kPointB->getOwner();
    D10800Input* input = m_pOwningWorld->m_pCollisionInput;
    D10800Dispatcher* dispatcher = input->m_pCollisionDispatcher;
    signed char quality = dispatcher->m_aucByteGrid[collA->m_iAutoRemoveLevel][collB->m_iAutoRemoveLevel];
    if (quality)
    {
        input->m_pCollisionQualityInfo = dispatcher->m_pCollisionQualityInfo[quality].m_data;
        hkpWorldAgentUtil_addAgent(collA, collB, input);
    }
}

struct D10860Collidable;

struct D10860TypedHandle
{
    int m_iOwnerObjectOffset;
    unsigned char m_type;
    signed char m_iOwnerOffset;

    D10860Collidable* getOwner() const
    {
        return reinterpret_cast<D10860Collidable*>(const_cast<char*>(reinterpret_cast<const char*>(this)) +
                                                   m_iOwnerOffset);
    }
};

struct D10860HandlePair
{
    D10860TypedHandle* m_kPointA;
    D10860TypedHandle* m_kPointB;
};

struct D10860Agent;

D10860Agent* __cdecl FindEntryValue(const D10860Collidable* collA, const D10860Collidable* collB);
void __cdecl hkpWorldAgentUtil_removeAgent(D10860Agent* agent);

struct D10860Listener
{
    void ProcessHandlePair(D10860HandlePair& pair);
};

// @fnv 0x00d10860
void D10860Listener::ProcessHandlePair(D10860HandlePair& pair)
{
    D10860Collidable* collA = pair.m_kPointA->getOwner();
    D10860Collidable* collB = pair.m_kPointB->getOwner();
    D10860Agent* agent = FindEntryValue(collA, collB);
    if (agent)
        hkpWorldAgentUtil_removeAgent(agent);
}
