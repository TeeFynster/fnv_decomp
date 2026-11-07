#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN

// src/havok/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpuagentsectorjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpuagentsectorjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../include/hkVector4.h"
#include <string.h>

struct FUN_00d93330 {
    void __thiscall UpdateConstraint(int);
};
// @fnv 0x00d93330
void __thiscall FUN_00d93330::UpdateConstraint(int v)
{
    ++(*(int*)((char*)this + 0x18));
    *(int*)((char*)this + 0x1c) = v;
}

struct FUN_00d93340_StandIn {
    void hkpDeferredConstraintOwner_removeConstraintFromCriticalLockedIsland(int);
};

// @fnv 0x00d93340
// src: HAVOK_LIB 0x00d93340
void __thiscall FUN_00d93340_StandIn::hkpDeferredConstraintOwner_removeConstraintFromCriticalLockedIsland(int a)
{
    *(int*)((char*)this + 0x18) = *(int*)((char*)this + 0x18) - 1;
    *(int*)((char*)this + 0x1c) = a;
}

struct SubTarget {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    short unk10;
    unsigned char unk12;
};

struct Arg1Struct {
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
    SubTarget* unk30;
};

struct SimulationIsland {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int unk20;

    void SetFlags(Arg1Struct* a1, unsigned int a2);
};

// Sets the given flag bits on a1->unk30->unk12 if a1->unk30 exists, otherwise on this->unk20.
// @fnv 0x00d93350
void SimulationIsland::SetFlags(Arg1Struct* a1, unsigned int uiFlags)
{
    if (a1->unk30) {
        a1->unk30->unk12 |= (unsigned char)uiFlags;
    } else {
        this->unk20 |= uiFlags;
    }
}

#include <xmmintrin.h>
#include <windows.h>
extern "C" void _ReadWriteBarrier();
extern "C" const char str_010cc54c[], str_010d3e28[], str_010cd440[], str_010d3e14[];


struct __declspec(align(16)) AlignedVector { float x, y, z, w; };
struct Input {
    void *dispatcher, *collisionFilter, *qualityLibrary, *shapeCollectionFilter;
    int field10, field14, field18, field1c;
    AlignedVector stepInfo, tolerance, configuration;
};
struct Context : Input {
    hkVector4 time;
    void *quality;
    void *allocation;
    int field68;
    char field6c, field6d;
    short field6e;
    void *field70;
    int field74, field78, field7c;
    void FUN_00cfa7d0(const Input *);
};
// 16-byte hkpPhysicsCommand slot of the per-thread hkpPhysicsCommandQueue (type byte, object, value, extra);
// AddCommand/RemoveCommand below are its typed forms. Not the console-command Command.
struct PhysicsCommand { union { int type; char code; }; int object, value, extra; };
struct CommandBuffer {
    int offset, size, capacity, field0c;
    PhysicsCommand commands[16];
    void hkpFixedSizePhysicsCommandQueue_256_hkpFixedSizePhysicsCommandQueue_256();
    PhysicsCommand *end() { return (PhysicsCommand *)((char *)this + offset + size); }
};
extern int DAT_010d3df8, DAT_0102e388;
struct AddCommand { char type; int object, critical; };
struct RemoveCommand { char type; int object; };
struct __declspec(align(16)) Owner {
    const void *dispatch;
    unsigned short flags, references;
    int maximum, added, removed, changed, pending, object, critical;
    int field24, field28, field2c;
    CommandBuffer commands;
    __forceinline void flush() {
        if (!pending) critical = 0;
        else {
            if (pending > 0) {
                AddCommand c; c.type = 0; c.object = object; c.critical = critical;
                *(AddCommand *)commands.end() = c;
                critical = 0;
            } else {
                RemoveCommand c; c.type = 1; c.object = object;
                *(RemoveCommand *)commands.end() = c;
            }
            commands.size += 16;
        }
        pending = 0;
    }
};
struct Contact { AlignedVector position, normal, properties; };
struct Toi {
    AlignedVector position, normal;
    float time; int field24, field28, field2c;
    AlignedVector separatingVelocity;
    float velocity, rotation; int field48, field4c;
    AlignedVector properties, material;
};
struct Output {
    Contact *end;
    Owner *owner;
    int field08, field0c;
    Contact contacts[256];
    Toi toi;
    int count, field84, field88, field8c;
};
struct CollisionManager {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void process(void *, void *, Context *, Output *);
};
struct Entry {
    unsigned char type, field01, field02, field03;
    int field04;
    CollisionManager *manager;
    signed char quality;
    char field0d; short field0e;
    void *bodyA, *bodyB;
    int field18, field1c, field20, field24, field28, field2c, field30, field34, field38, field3c, field40, field44, field48, field4c, field50, field54, field58, field5c, field60, field64, field68, field6c, field70, field74, field78, field7c;
};
struct Sector { Entry entries[4]; };
struct Statistics { int maximum, added, removed, changed; CommandBuffer commands; };
struct Batch { int field00, field04, field08; Statistics *results[1]; };
struct Island {
    int field00, field04, maximum, added, removed, changed;
    int field18, field1c, field20, field24, field28, field2c, field30, field34, field38, field3c;
    int field40, field44, field48, field4c, field50, field54;
    int lastSize;
    Entry **sectors;
    int sectorCount;
};
struct Job {
    unsigned char type, field01; short field02;
    int field04, field08, field0c, field10;
    Island *island;
    int field18, field1c;
    Batch *batch;
    short index, field26;
    unsigned short count, stride;
    Entry **entries;
    hkVector4 time;
    union { int sector; unsigned char useContinuousQuality; };
};
struct World {
    void EnterLock(Island *);
    void hkpWorld_unlockIslandForConstraintUpdate(Island *);
};
struct Quality { int field00, field04, field08, field0c; int createPredictive; int field14, field18, field1c, field20, field24, field28, field2c, field30, field34, field38, field3c; };
struct Dispatcher {
    int field0000, field0004, field0008, field000c, field0010, field0014, field0018, field001c, field0020, field0024, field0028, field002c, field0030, field0034, field0038, field003c, field0040, field0044, field0048, field004c, field0050, field0054, field0058, field005c, field0060, field0064, field0068, field006c, field0070, field0074, field0078, field007c, field0080, field0084, field0088, field008c, field0090, field0094, field0098, field009c, field00a0, field00a4, field00a8, field00ac, field00b0, field00b4, field00b8, field00bc, field00c0, field00c4, field00c8, field00cc, field00d0, field00d4, field00d8, field00dc, field00e0, field00e4, field00e8, field00ec, field00f0, field00f4, field00f8, field00fc, field0100, field0104, field0108, field010c, field0110, field0114, field0118, field011c, field0120, field0124, field0128, field012c, field0130, field0134, field0138, field013c, field0140, field0144, field0148, field014c, field0150, field0154, field0158, field015c, field0160, field0164, field0168, field016c, field0170, field0174, field0178, field017c, field0180, field0184, field0188, field018c, field0190, field0194, field0198, field019c, field01a0, field01a4, field01a8, field01ac, field01b0, field01b4, field01b8, field01bc, field01c0, field01c4, field01c8, field01cc, field01d0, field01d4, field01d8, field01dc, field01e0, field01e4, field01e8, field01ec, field01f0, field01f4, field01f8, field01fc, field0200, field0204, field0208, field020c, field0210, field0214, field0218, field021c, field0220, field0224, field0228, field022c, field0230, field0234, field0238, field023c, field0240, field0244, field0248, field024c, field0250, field0254, field0258, field025c, field0260, field0264, field0268, field026c, field0270, field0274, field0278, field027c, field0280, field0284, field0288, field028c, field0290, field0294, field0298, field029c, field02a0, field02a4, field02a8, field02ac, field02b0, field02b4, field02b8, field02bc, field02c0, field02c4, field02c8, field02cc, field02d0, field02d4, field02d8, field02dc, field02e0, field02e4, field02e8, field02ec, field02f0, field02f4, field02f8, field02fc, field0300, field0304, field0308, field030c, field0310, field0314, field0318, field031c, field0320, field0324, field0328, field032c, field0330, field0334, field0338, field033c, field0340, field0344, field0348, field034c, field0350, field0354, field0358, field035c, field0360, field0364, field0368, field036c, field0370, field0374, field0378, field037c, field0380, field0384, field0388, field038c, field0390, field0394, field0398, field039c, field03a0, field03a4, field03a8, field03ac, field03b0, field03b4, field03b8, field03bc, field03c0, field03c4, field03c8, field03cc, field03d0, field03d4, field03d8, field03dc, field03e0, field03e4, field03e8, field03ec, field03f0, field03f4, field03f8, field03fc, field0400, field0404, field0408, field040c, field0410, field0414, field0418, field041c, field0420, field0424, field0428, field042c, field0430, field0434, field0438, field043c, field0440, field0444, field0448, field044c, field0450, field0454, field0458, field045c, field0460, field0464, field0468, field046c, field0470, field0474, field0478, field047c, field0480, field0484, field0488, field048c, field0490, field0494, field0498, field049c, field04a0, field04a4, field04a8, field04ac, field04b0, field04b4, field04b8, field04bc, field04c0, field04c4, field04c8, field04cc, field04d0, field04d4, field04d8, field04dc, field04e0, field04e4, field04e8, field04ec, field04f0, field04f4, field04f8, field04fc, field0500, field0504, field0508, field050c, field0510, field0514, field0518, field051c, field0520, field0524, field0528, field052c, field0530, field0534, field0538, field053c, field0540, field0544, field0548, field054c, field0550, field0554, field0558, field055c, field0560, field0564, field0568, field056c, field0570, field0574, field0578, field057c, field0580, field0584, field0588, field058c, field0590, field0594, field0598, field059c, field05a0, field05a4, field05a8, field05ac, field05b0, field05b4, field05b8, field05bc, field05c0, field05c4, field05c8, field05cc, field05d0, field05d4, field05d8, field05dc, field05e0, field05e4, field05e8, field05ec, field05f0, field05f4, field05f8, field05fc, field0600, field0604, field0608, field060c, field0610, field0614, field0618, field061c, field0620, field0624, field0628, field062c, field0630, field0634, field0638, field063c, field0640, field0644, field0648, field064c, field0650, field0654, field0658, field065c, field0660, field0664, field0668, field066c, field0670, field0674, field0678, field067c, field0680, field0684, field0688, field068c, field0690, field0694, field0698, field069c, field06a0, field06a4, field06a8, field06ac, field06b0, field06b4, field06b8, field06bc, field06c0, field06c4, field06c8, field06cc, field06d0, field06d4, field06d8, field06dc, field06e0, field06e4, field06e8, field06ec, field06f0, field06f4, field06f8, field06fc, field0700, field0704, field0708, field070c, field0710, field0714, field0718, field071c, field0720, field0724, field0728, field072c, field0730, field0734, field0738, field073c, field0740, field0744, field0748, field074c, field0750, field0754, field0758, field075c, field0760, field0764, field0768, field076c, field0770, field0774, field0778, field077c, field0780, field0784, field0788, field078c, field0790, field0794, field0798, field079c, field07a0, field07a4, field07a8, field07ac, field07b0, field07b4, field07b8, field07bc, field07c0, field07c4, field07c8, field07cc, field07d0, field07d4, field07d8, field07dc, field07e0, field07e4, field07e8, field07ec, field07f0, field07f4, field07f8, field07fc, field0800, field0804, field0808, field080c, field0810, field0814, field0818, field081c, field0820, field0824, field0828, field082c, field0830, field0834, field0838, field083c, field0840, field0844, field0848, field084c, field0850, field0854, field0858, field085c, field0860, field0864, field0868, field086c, field0870, field0874, field0878, field087c, field0880, field0884, field0888, field088c, field0890, field0894, field0898, field089c, field08a0, field08a4, field08a8, field08ac, field08b0, field08b4, field08b8, field08bc, field08c0, field08c4, field08c8, field08cc, field08d0, field08d4, field08d8, field08dc, field08e0, field08e4, field08e8, field08ec, field08f0, field08f4, field08f8, field08fc, field0900, field0904, field0908, field090c, field0910, field0914, field0918, field091c, field0920, field0924, field0928, field092c, field0930, field0934, field0938, field093c, field0940, field0944, field0948, field094c, field0950, field0954, field0958, field095c, field0960, field0964, field0968, field096c, field0970, field0974, field0978, field097c, field0980, field0984, field0988, field098c, field0990, field0994, field0998, field099c, field09a0, field09a4, field09a8, field09ac, field09b0, field09b4, field09b8, field09bc, field09c0, field09c4, field09c8, field09cc, field09d0, field09d4, field09d8, field09dc, field09e0, field09e4, field09e8, field09ec, field09f0, field09f4, field09f8, field09fc, field0a00, field0a04, field0a08, field0a0c, field0a10, field0a14, field0a18, field0a1c, field0a20, field0a24, field0a28, field0a2c, field0a30, field0a34, field0a38, field0a3c, field0a40, field0a44, field0a48, field0a4c, field0a50, field0a54, field0a58, field0a5c, field0a60, field0a64, field0a68, field0a6c, field0a70, field0a74, field0a78, field0a7c, field0a80, field0a84, field0a88, field0a8c, field0a90, field0a94, field0a98, field0a9c, field0aa0, field0aa4, field0aa8, field0aac, field0ab0, field0ab4, field0ab8, field0abc, field0ac0, field0ac4, field0ac8, field0acc, field0ad0, field0ad4, field0ad8, field0adc, field0ae0, field0ae4, field0ae8, field0aec, field0af0, field0af4, field0af8, field0afc, field0b00, field0b04, field0b08, field0b0c, field0b10, field0b14, field0b18, field0b1c, field0b20, field0b24, field0b28, field0b2c, field0b30, field0b34, field0b38, field0b3c, field0b40, field0b44, field0b48, field0b4c, field0b50, field0b54, field0b58, field0b5c, field0b60, field0b64, field0b68, field0b6c, field0b70, field0b74, field0b78, field0b7c, field0b80, field0b84, field0b88, field0b8c, field0b90, field0b94, field0b98, field0b9c, field0ba0, field0ba4, field0ba8, field0bac, field0bb0, field0bb4, field0bb8, field0bbc, field0bc0, field0bc4, field0bc8, field0bcc, field0bd0, field0bd4, field0bd8, field0bdc, field0be0, field0be4, field0be8, field0bec, field0bf0, field0bf4, field0bf8, field0bfc, field0c00, field0c04, field0c08, field0c0c, field0c10, field0c14, field0c18, field0c1c, field0c20, field0c24, field0c28, field0c2c, field0c30, field0c34, field0c38, field0c3c, field0c40, field0c44, field0c48, field0c4c, field0c50, field0c54, field0c58, field0c5c, field0c60, field0c64, field0c68, field0c6c, field0c70, field0c74, field0c78, field0c7c, field0c80, field0c84, field0c88, field0c8c, field0c90, field0c94, field0c98, field0c9c, field0ca0, field0ca4, field0ca8, field0cac, field0cb0, field0cb4, field0cb8, field0cbc, field0cc0, field0cc4, field0cc8, field0ccc, field0cd0, field0cd4, field0cd8, field0cdc, field0ce0, field0ce4, field0ce8, field0cec, field0cf0, field0cf4, field0cf8, field0cfc, field0d00, field0d04, field0d08, field0d0c, field0d10, field0d14, field0d18, field0d1c, field0d20, field0d24, field0d28, field0d2c, field0d30, field0d34, field0d38, field0d3c, field0d40, field0d44, field0d48, field0d4c, field0d50, field0d54, field0d58, field0d5c, field0d60, field0d64, field0d68, field0d6c, field0d70, field0d74, field0d78, field0d7c, field0d80, field0d84, field0d88, field0d8c, field0d90, field0d94, field0d98, field0d9c, field0da0, field0da4, field0da8, field0dac, field0db0, field0db4, field0db8, field0dbc, field0dc0, field0dc4, field0dc8, field0dcc, field0dd0, field0dd4, field0dd8, field0ddc, field0de0, field0de4, field0de8, field0dec, field0df0, field0df4, field0df8, field0dfc, field0e00, field0e04, field0e08, field0e0c, field0e10, field0e14, field0e18, field0e1c, field0e20, field0e24, field0e28, field0e2c, field0e30, field0e34, field0e38, field0e3c, field0e40, field0e44, field0e48, field0e4c, field0e50, field0e54, field0e58, field0e5c, field0e60, field0e64, field0e68, field0e6c, field0e70, field0e74, field0e78, field0e7c, field0e80, field0e84, field0e88, field0e8c, field0e90, field0e94, field0e98, field0e9c, field0ea0, field0ea4, field0ea8, field0eac, field0eb0, field0eb4, field0eb8, field0ebc, field0ec0, field0ec4, field0ec8, field0ecc, field0ed0, field0ed4, field0ed8, field0edc, field0ee0, field0ee4, field0ee8, field0eec, field0ef0, field0ef4, field0ef8, field0efc, field0f00, field0f04, field0f08, field0f0c, field0f10, field0f14, field0f18, field0f1c, field0f20, field0f24, field0f28, field0f2c, field0f30, field0f34, field0f38, field0f3c, field0f40, field0f44, field0f48, field0f4c, field0f50, field0f54, field0f58, field0f5c, field0f60, field0f64, field0f68, field0f6c, field0f70, field0f74, field0f78, field0f7c, field0f80, field0f84, field0f88, field0f8c, field0f90, field0f94, field0f98, field0f9c, field0fa0, field0fa4, field0fa8, field0fac, field0fb0, field0fb4, field0fb8, field0fbc, field0fc0, field0fc4, field0fc8, field0fcc, field0fd0, field0fd4, field0fd8, field0fdc, field0fe0, field0fe4, field0fe8, field0fec, field0ff0, field0ff4, field0ff8, field0ffc, field1000, field1004, field1008, field100c, field1010, field1014, field1018, field101c, field1020, field1024, field1028, field102c, field1030, field1034, field1038, field103c, field1040, field1044, field1048, field104c, field1050, field1054, field1058, field105c, field1060, field1064, field1068, field106c, field1070, field1074, field1078, field107c, field1080, field1084, field1088, field108c, field1090, field1094, field1098, field109c, field10a0, field10a4, field10a8, field10ac, field10b0, field10b4, field10b8, field10bc, field10c0, field10c4, field10c8, field10cc, field10d0, field10d4, field10d8, field10dc, field10e0, field10e4, field10e8, field10ec, field10f0, field10f4, field10f8, field10fc, field1100, field1104, field1108, field110c, field1110, field1114, field1118, field111c, field1120, field1124, field1128, field112c, field1130, field1134, field1138, field113c, field1140, field1144, field1148, field114c, field1150, field1154, field1158, field115c, field1160, field1164, field1168, field116c, field1170, field1174, field1178, field117c, field1180, field1184, field1188, field118c, field1190, field1194, field1198, field119c, field11a0, field11a4, field11a8, field11ac, field11b0, field11b4, field11b8, field11bc, field11c0, field11c4, field11c8, field11cc, field11d0, field11d4, field11d8, field11dc, field11e0, field11e4, field11e8, field11ec, field11f0, field11f4, field11f8, field11fc, field1200, field1204, field1208, field120c, field1210, field1214, field1218, field121c, field1220, field1224, field1228, field122c, field1230, field1234, field1238, field123c, field1240, field1244, field1248, field124c, field1250, field1254, field1258, field125c, field1260, field1264, field1268, field126c, field1270, field1274, field1278, field127c, field1280, field1284, field1288, field128c, field1290, field1294, field1298, field129c, field12a0, field12a4, field12a8, field12ac, field12b0, field12b4, field12b8, field12bc, field12c0, field12c4, field12c8, field12cc, field12d0, field12d4, field12d8, field12dc, field12e0, field12e4, field12e8, field12ec, field12f0, field12f4, field12f8, field12fc, field1300, field1304, field1308, field130c, field1310, field1314, field1318, field131c, field1320, field1324, field1328, field132c, field1330, field1334, field1338, field133c, field1340, field1344, field1348, field134c, field1350, field1354, field1358, field135c, field1360, field1364, field1368, field136c, field1370, field1374, field1378, field137c, field1380, field1384, field1388, field138c, field1390, field1394, field1398, field139c, field13a0, field13a4, field13a8, field13ac, field13b0, field13b4, field13b8, field13bc, field13c0, field13c4, field13c8, field13cc, field13d0, field13d4, field13d8, field13dc, field13e0, field13e4, field13e8, field13ec, field13f0, field13f4, field13f8, field13fc, field1400, field1404, field1408, field140c, field1410, field1414, field1418, field141c, field1420, field1424, field1428, field142c, field1430, field1434, field1438, field143c, field1440, field1444, field1448, field144c, field1450, field1454, field1458, field145c, field1460, field1464, field1468, field146c, field1470, field1474, field1478, field147c, field1480, field1484, field1488, field148c, field1490, field1494, field1498, field149c, field14a0, field14a4, field14a8, field14ac, field14b0, field14b4, field14b8, field14bc, field14c0, field14c4, field14c8, field14cc, field14d0, field14d4, field14d8, field14dc, field14e0, field14e4, field14e8, field14ec, field14f0, field14f4, field14f8, field14fc, field1500, field1504, field1508, field150c, field1510, field1514, field1518, field151c, field1520, field1524, field1528, field152c, field1530, field1534, field1538, field153c, field1540, field1544, field1548, field154c, field1550, field1554, field1558, field155c, field1560, field1564, field1568, field156c, field1570, field1574, field1578, field157c, field1580, field1584, field1588, field158c, field1590, field1594, field1598, field159c, field15a0, field15a4, field15a8, field15ac, field15b0, field15b4, field15b8, field15bc, field15c0, field15c4, field15c8, field15cc, field15d0, field15d4, field15d8, field15dc, field15e0, field15e4, field15e8, field15ec, field15f0, field15f4, field15f8, field15fc, field1600, field1604, field1608, field160c, field1610, field1614, field1618, field161c, field1620, field1624, field1628, field162c, field1630, field1634, field1638, field163c, field1640, field1644, field1648, field164c, field1650, field1654, field1658, field165c, field1660, field1664, field1668, field166c, field1670, field1674, field1678, field167c, field1680, field1684, field1688, field168c, field1690, field1694, field1698, field169c, field16a0, field16a4, field16a8, field16ac, field16b0, field16b4, field16b8, field16bc, field16c0, field16c4, field16c8, field16cc, field16d0, field16d4, field16d8, field16dc, field16e0, field16e4, field16e8, field16ec, field16f0, field16f4, field16f8, field16fc, field1700, field1704, field1708, field170c, field1710, field1714, field1718, field171c, field1720, field1724, field1728, field172c, field1730, field1734, field1738, field173c, field1740, field1744, field1748, field174c, field1750, field1754, field1758, field175c, field1760, field1764, field1768, field176c, field1770, field1774, field1778, field177c, field1780, field1784, field1788, field178c, field1790, field1794, field1798, field179c, field17a0, field17a4, field17a8, field17ac, field17b0, field17b4, field17b8, field17bc, field17c0, field17c4, field17c8, field17cc, field17d0, field17d4, field17d8, field17dc, field17e0, field17e4, field17e8, field17ec, field17f0, field17f4, field17f8, field17fc, field1800, field1804, field1808, field180c, field1810, field1814, field1818, field181c, field1820, field1824, field1828, field182c, field1830, field1834, field1838, field183c, field1840, field1844, field1848, field184c, field1850, field1854, field1858, field185c, field1860, field1864, field1868, field186c, field1870, field1874, field1878, field187c, field1880, field1884, field1888, field188c, field1890, field1894, field1898, field189c, field18a0, field18a4, field18a8, field18ac, field18b0, field18b4, field18b8, field18bc, field18c0, field18c4, field18c8, field18cc, field18d0, field18d4, field18d8, field18dc, field18e0, field18e4, field18e8, field18ec, field18f0, field18f4, field18f8, field18fc, field1900, field1904, field1908, field190c, field1910, field1914, field1918, field191c, field1920, field1924, field1928, field192c, field1930, field1934, field1938, field193c, field1940, field1944, field1948, field194c, field1950, field1954, field1958, field195c, field1960, field1964, field1968, field196c, field1970, field1974, field1978, field197c, field1980, field1984, field1988, field198c, field1990, field1994, field1998, field199c, field19a0, field19a4, field19a8, field19ac, field19b0, field19b4, field19b8, field19bc, field19c0, field19c4, field19c8, field19cc, field19d0, field19d4, field19d8, field19dc, field19e0, field19e4, field19e8, field19ec, field19f0, field19f4, field19f8, field19fc, field1a00, field1a04, field1a08, field1a0c, field1a10, field1a14, field1a18, field1a1c, field1a20, field1a24, field1a28, field1a2c, field1a30, field1a34, field1a38, field1a3c, field1a40, field1a44, field1a48, field1a4c, field1a50, field1a54, field1a58, field1a5c, field1a60, field1a64, field1a68, field1a6c, field1a70, field1a74, field1a78, field1a7c, field1a80, field1a84, field1a88, field1a8c, field1a90, field1a94, field1a98, field1a9c, field1aa0, field1aa4, field1aa8, field1aac, field1ab0, field1ab4, field1ab8, field1abc, field1ac0, field1ac4, field1ac8, field1acc, field1ad0, field1ad4, field1ad8, field1adc, field1ae0, field1ae4, field1ae8, field1aec, field1af0, field1af4, field1af8, field1afc, field1b00, field1b04, field1b08, field1b0c, field1b10, field1b14, field1b18, field1b1c, field1b20, field1b24, field1b28, field1b2c, field1b30, field1b34, field1b38, field1b3c, field1b40, field1b44, field1b48, field1b4c, field1b50, field1b54, field1b58, field1b5c, field1b60, field1b64, field1b68, field1b6c, field1b70, field1b74, field1b78, field1b7c, field1b80, field1b84, field1b88, field1b8c, field1b90, field1b94, field1b98, field1b9c, field1ba0, field1ba4, field1ba8, field1bac, field1bb0, field1bb4, field1bb8, field1bbc, field1bc0, field1bc4, field1bc8, field1bcc, field1bd0, field1bd4, field1bd8, field1bdc, field1be0, field1be4, field1be8, field1bec, field1bf0, field1bf4, field1bf8, field1bfc, field1c00, field1c04, field1c08, field1c0c, field1c10, field1c14, field1c18, field1c1c;
    Quality qualities[8];
};
struct Physics {
    int field00, field04, field08, field0c, field10, field14, field18, field1c;
    int field20, field24, field28, field2c, field30, field34, field38, field3c;
    int field40, field44, field48, field4c, field50, field54, field58, field5c;
    int field60, field64, field68, field6c, field70, field74, field78, field7c;
    int field80, field84, field88, field8c, field90, field94, field98, field9c;
    int fielda0, fielda4, fielda8, fieldac, fieldb0, fieldb4, fieldb8, fieldbc;
    int fieldc0, fieldc4, fieldc8, fieldcc, fieldd0, fieldd4, fieldd8, fielddc;
    int fielde0, fielde4, fielde8, fieldec, fieldf0, fieldf4, fieldf8, fieldfc;
    int toiQueue;
    void AddToiEvent(Output *, Entry *, int *);
};
struct Globals {
    World *world;
    int field04, field08, field0c, field10, field14, field18, field1c;
    int field20, field24, field28, field2c, field30, field34, field38, field3c;
    int field40, field44, field48, field4c, field50, field54, field58, field5c;
    int field60, field64, field68, field6c, field70, field74, field78, field7c;
    int field80, field84, field88, field8c;
    Context input;
    Physics *physics;
};
struct Queue { int ProcessCallback(Job *, Job *, int); };
struct MonitorRecord { const char *name; unsigned int time, field08; __forceinline void sample() { unsigned int stamp;
        __asm {
            rdtsc
            mov dword ptr[stamp], eax
        }
        time = stamp;
    } };
struct Monitor { int field00; MonitorRecord *end; int field08; MonitorRecord *limit; };
extern unsigned long DAT_0126835c;
extern int DAT_01269200;
__forceinline void profile(const char *name, unsigned long tlsIndex) {
    Monitor *m = (Monitor *)TlsGetValue(tlsIndex);
    MonitorRecord *p = m->end;
    if (p < m->limit) {
        p->name = name;
        p->sample();
        m->end = p + 1;
    }
}
void hkAgentNnMachine_ProcessAgent(Entry *, Context *, Output *, CollisionManager *);
void hkPhysicsCommandMachineProcess(World *, void *, int);
struct Allocator { virtual void v0(); virtual void v1(); virtual void release(void *, int); };
struct Memory { int field00, field04, field08, field0c; Allocator *allocator; };
Memory *hkMemoryRouter_getInstance();
__forceinline Quality *qualityAt(Context &c, int index) { return ((Dispatcher *)c.dispatcher)->qualities + index; }
__forceinline void storeResults(Statistics *s, Owner &owner) {
    s->maximum = owner.maximum; s->added = owner.added; s->removed = owner.removed; s->changed = owner.changed;
    int size = owner.commands.size;
    if (size) {
        PhysicsCommand *src = (PhysicsCommand *)((char *)&owner.commands + owner.commands.offset);
        CommandBuffer *b = &s->commands; PhysicsCommand *dst = (PhysicsCommand *)((char *)b + b->offset);
        int n = size >> 4; if (n > 0) do { *dst++ = *src++; } while (--n);
        s->commands.size = size;
    }
}
// @fnv 0x00d93380
// src: COMMUNITY 0x00d93380
int hkCpuAgentSectorJob(Globals *globals, Queue *queue, Job *job) {
    union WorkSlot { Island *savedIsland; int i; }; WorkSlot work;
    // The job initializes this context in place without constructing its time vector.
    __declspec(align(16)) void *contextStorage[sizeof(Context) / sizeof(void *)];
    Context &context = *(Context *)contextStorage;
    (Input &)context = (Input &)globals->input;
    context.allocation = 0;
    context.FUN_00cfa7d0(&globals->input);
    memcpy(&context.time, &job->time, sizeof(context.time));
    Owner owner;
    owner.references = 1;
    owner.dispatch = &DAT_010d3df8;
    owner.commands.hkpFixedSizePhysicsCommandQueue_256_hkpFixedSizePhysicsCommandQueue_256();
    Output output;
    output.toi.time = 3.402820018375656e38f;
    output.toi.rotation = output.toi.velocity = 0.0f;
    owner.maximum = 0; owner.added = 0; owner.removed = 0; owner.changed = 0;
    owner.pending = 0; owner.critical = 0;
    output.owner = &owner;
    if (job->type == 13) {
        {
        Island *island = job->island; work.savedIsland = island;
        profile(str_010cc54c, DAT_0126835c);
        int num = job->count;
        int index = job->sector;
        int remaining = num - 1;
        Entry *current = island->sectors[index];
        char *end = (char *)current + (index + 1 == island->sectorCount ? island->lastSize : 512);
        Entry *next = current + 1;
        Entry *prefetched = next + 1;
        if ((char *)next >= end) prefetched = next = 0;
        else if ((char *)prefetched >= end) prefetched = 0;
        do {
            void *bodyA = current->bodyA;
            Physics *physics = globals->physics;
            void *bodyB = current->bodyB;
            context.quality = qualityAt(context, current->quality);
            context.field14 = ((Quality *)context.quality)->createPredictive;
            output.toi.time = 3.402820018375656e38f;
            output.end = output.contacts; output.count = 0;
            hkAgentNnMachine_ProcessAgent(current, &context, &output, current->manager);
            if (output.end != output.contacts) current->manager->process(bodyA, bodyB, &context, &output);
            if (output.toi.time != 3.402820018375656e38) physics->AddToiEvent(&output, current, &physics->toiQueue);
            owner.flush();
            current = next; next = prefetched;
            if (DAT_01269200 == 1) break;
            if (prefetched) {
                ++prefetched;
                if ((char *)prefetched >= end) {
                    ++index; --remaining;
                    if (remaining >= 0) {
                        Island *sectorIsland = work.savedIsland;
                        Entry *const &slot = sectorIsland->sectors[index]; prefetched = slot;
                        if (remaining > 0) {
                            char *p = (char *)sectorIsland->sectors[index + 1];
                            _mm_prefetch(p, 0); _mm_prefetch(p + 64, 0); _mm_prefetch(p + 128, 0); _mm_prefetch(p + 192, 0);
                        }
                        end = (index + 1 == sectorIsland->sectorCount ? sectorIsland->lastSize : 512) + (char *)slot;
                    } else prefetched = 0;
                }
            }
        } while (current);
        if (!job->batch) {
            if ((owner.maximum | owner.added | owner.removed | owner.changed) || owner.commands.size) {
                island = work.savedIsland;
                globals->world->EnterLock(island);
                island->maximum = island->maximum > owner.maximum ? island->maximum : owner.maximum;
                island->added += owner.added; island->removed += owner.removed; island->changed += owner.changed;
                if (owner.commands.size) hkPhysicsCommandMachineProcess(globals->world, (char *)&owner.commands + owner.commands.offset, owner.commands.size);
                globals->world->hkpWorld_unlockIslandForConstraintUpdate(island);
            }
        } else storeResults(job->batch->results[job->index], owner);
        }
        profile(str_010d3e28, DAT_0126835c);
    } else {
        profile(str_010cd440, DAT_0126835c);
        int start = job->stride * (unsigned short)job->index;
        for (work.i = 0; work.i < job->count; ++work.i) {
            Entry *entry = job->entries[start + work.i];
            if (job->useContinuousQuality) {
                context.quality = qualityAt(context, 7);
                context.field14 = qualityAt(context, entry->quality)->createPredictive;
            } else {
                context.quality = qualityAt(context, entry->quality);
                context.field14 = ((Quality *)context.quality)->createPredictive;
            }
            output.toi.time = 3.402820018375656e38f;
            output.end = output.contacts; output.count = 0;
            hkAgentNnMachine_ProcessAgent(entry, &context, &output, entry->manager);
            if (output.end != output.contacts) entry->manager->process(entry->bodyA, entry->bodyB, &context, &output);
            if (output.toi.time != 3.402820018375656e38) globals->physics->AddToiEvent(&output, entry, &globals->physics->toiQueue);
            owner.flush();
            if (DAT_01269200 == 1) break;
        }
        storeResults(job->batch->results[job->index], owner);
        profile(str_010d3e14, DAT_0126835c);
    }
    int result = queue->ProcessCallback(job, job, 0);
    owner.dispatch = &DAT_0102e388;
    if (context.allocation) { Memory *m = hkMemoryRouter_getInstance(); Allocator *a = m->allocator; a->release(context.allocation, 512); }
    return result;
}
