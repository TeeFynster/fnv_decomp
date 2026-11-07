
// src/havok/physics/collide/agent/convexagent/gjk/hkppredgskfagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/gjk/hkppredgskfagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct __declspec(align(16)) FUN_00d41f00_Local
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
};

void __cdecl hkPredGskAgent3_initAgentFunc(FUN_00d41f00_Local* p);

class SpawnedObject
{
  public:
    void AddEntry(FUN_00d41f00_Local* p, int a, int b);
};

// @fnv 0x00d41f00
// src: HAVOK_LIB 0x00d41f00
void __cdecl hkPredGskAgent3_registerAgent3(SpawnedObject* self, int aiArg1, int aiArg2)
{
    FUN_00d41f00_Local local;
    local.unk30 = 0;
    local.unk31 = 0;
    local.unk32 = 0;
    local.unk18 = 0;
    local.unk1C = 0;
    local.unk20 = 0;
    local.unk24 = 0;
    local.unk28 = 0;
    hkPredGskAgent3_initAgentFunc(&local);
    self->AddEntry(&local, aiArg1, aiArg2);
}
