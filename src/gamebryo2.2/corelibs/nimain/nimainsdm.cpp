
// src/gamebryo2.2/corelibs/nimain/nimainsdm.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nimainsdm.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiStream.h"

struct MM
{
    void __thiscall _DeallocateAlias(void*);
};
extern MM g_memoryManager;
extern void* DAT_011c5f54;
// @fnv 0x00a8a200
template <class T> struct PoolAllocatorBase
{
    struct LinkedListEntry
    {
        LinkedListEntry* next;
    };
    static LinkedListEntry* ms_pFreeList;
};
void FUN_00a8a200()
{
    void* p = DAT_011c5f54;
    if (p)
    {
        do
        {
            void* n = *(void**)p;
            g_memoryManager._DeallocateAlias(p);
            p = n;
        } while (p);
    }
    DAT_011c5f54 = 0;
    PoolAllocatorBase<unsigned int>::ms_pFreeList = 0;
}

namespace fnv_00a8a240 {
struct MM
{
    void _DeallocateAlias(void*);
};
extern MM g_memoryManager;
extern void* DAT_011f6034;
extern void* DAT_011f6038;
// Walks the linked list starting at DAT_011f6034, deallocating each node, then clears DAT_011f6038 and DAT_011f6034.
// @fnv 0x00a8a240
void FreeMemoryList()
{
    void* pCurrent = DAT_011f6034;
    if (pCurrent)
    {
        do
        {
            void* next = *(void**)pCurrent;
            g_memoryManager._DeallocateAlias(pCurrent);
            pCurrent = next;
        } while (pCurrent);
    }
    *(void* volatile*)&DAT_011f6038 = 0;
    *(void* volatile*)&DAT_011f6034 = 0;
}
}  // namespace fnv_00a8a240


struct FUN_00a8f730
{
    static void Release();
};

struct FUN_00a928b0_shell
{
    static void ClearFixedStrings();
};

void __cdecl FUN_00a5b660();
void __cdecl FUN_00a5cf60();
void __cdecl ReleasePendingTable();
void __cdecl FUN_00a62ae0();
void __cdecl FUN_00a632b0();
void __cdecl ReleaseGlobalStrings();
void __cdecl FUN_00a6f4d0();
void __cdecl ReleaseGlobalHolder();
void __cdecl FUN_00a76b30();
void __cdecl FreeGlobalAlias();
void __cdecl FUN_00a81590();
void __cdecl FreeMemoryList();
void __cdecl FUN_00a8f620();
void __cdecl FUN_00a8fcc0();
void __cdecl ResetStreamLinkIDSet();
void __cdecl DestroyGlobalPool();
void __cdecl FUN_00a9a120();
void __cdecl FUN_00a9bb60();
void __cdecl DestroyPairArrays();

extern char DAT_011f5b80;

extern char const* const g_011f4408_arg0;
extern char const* const g_011f4428_arg0;
extern char const* const g_011f4430_arg0;
extern char const* const g_011f444c_arg0;
extern char const* const g_011f49a4_arg0;
extern char const* const g_011f4a04_arg0;
extern char const* const g_011f4a0c_arg0;
extern char const* const g_011f4a18_arg0;
extern char const* const g_011f4a20_arg0;
extern char const* const g_011f4a30_arg0;
extern char const* const g_011f4a38_arg0;
extern char const* const g_011f4a40_arg0;
extern char const* const g_011f4a48_arg0;
extern char const* const g_011f4a5c_arg0;
extern char const* const g_011f4a68_arg0;
extern char const* const g_011f4a70_arg0;
extern char const* const g_011f4a80_arg0;
extern char const* const g_011f4a88_arg0;
extern char const* const g_011f4a90_arg0;
extern char const* const g_011f4a98_arg0;
extern char const* const g_011f4aa0_arg0;
extern char const* const g_011f4aac_arg0;
extern char const* const g_011f4ab8_arg0;
extern char const* const g_011f5ae0_arg0;
extern char const* const g_011f5af4_arg0;
extern char const* const g_011f5b1c_arg0;
extern char const* const g_011f5b24_arg0;
extern char const* const g_011f5b2c_arg0;
extern char const* const g_011f5b48_arg0;
extern char const* const g_011f5b50_arg0;
extern char const* const g_011f5b60_arg0;
extern char const* const g_011f5b68_arg0;
extern char const* const g_011f5b78_arg0;
extern char const* const g_011f5b88_arg0;
extern char const* const g_011f5c08_arg0;
extern char const* const g_011f5d20_arg0;
extern char const* const g_011f5e54_arg0;
extern char const* const g_011f5e5c_arg0;
extern char const* const g_011f5e64_arg0;
extern char const* const g_011f5e6c_arg0;
extern char const* const g_011f5e84_arg0;
extern char const* const g_011f5e8c_arg0;
extern char const* const g_011f5e94_arg0;
extern char const* const g_011f5eac_arg0;
extern char const* const g_011f5eb4_arg0;
extern char const* const g_011f5ebc_arg0;
extern char const* const g_011f5ec4_arg0;
extern char const* const g_011f5ecc_arg0;
extern char const* const g_011f5ed8_arg0;
extern char const* const g_011f5ee0_arg0;
extern char const* const g_011f5ee8_arg0;
extern char const* const g_011f5ef0_arg0;
extern char const* const g_011f5ef8_arg0;
extern char const* const g_011f5f0c_arg0;
extern char const* const g_011f5f14_arg0;
extern char const* const g_011f5f1c_arg0;
extern char const* const g_011f5f24_arg0;
extern char const* const g_011f5f2c_arg0;
extern char const* const g_011f5f34_arg0;
extern char const* const g_011f5f40_arg0;
extern char const* const g_011f5f48_arg0;
extern char const* const g_011f5f54_arg0;
extern char const* const g_011f5f5c_arg0;
extern char const* const g_011f5f64_arg0;
extern char const* const g_011f5f6c_arg0;
extern char const* const g_011f5f74_arg0;

extern char const* const DAT_0109f0a0;

// @fnv 0x00a8a280
void __cdecl FUN_00a8a280()
{
    if (DAT_011f5b80)
    {
        DAT_011f5b80 = 0;

        NiStream::UnregisterObjectLoader((char const*)&g_011f4aac_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4a30_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5f74_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4408_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5f6c_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5d20_arg0);
        NiStream::UnregisterObjectLoader("NiAutoNormalParticles");
        NiStream::UnregisterObjectLoader("NiAutoNormalParticlesData");
        NiStream::UnregisterObjectLoader((char const*)&g_011f4aa0_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4ab8_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5f5c_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5f54_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4a18_arg0);
        NiStream::UnregisterObjectLoader("NiClusterAccumulator");
        NiStream::UnregisterObjectLoader("NiCollisionSwitch");
        NiStream::UnregisterObjectLoader((char const*)&g_011f5b68_arg0);

        NiStream::UnregisterObjectLoader((char const*)&g_011f4a04_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4a68_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5f48_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4a80_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5f40_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5b60_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5f34_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5f2c_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5f24_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5f1c_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4a48_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5b88_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4a5c_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4428_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5c08_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5f14_arg0);

        NiStream::UnregisterObjectLoader((char const*)&g_011f5f0c_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5f64_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5ef0_arg0);
        NiStream::UnregisterObjectLoader((char const*)&DAT_0109f0a0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4a90_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4a98_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5ef8_arg0);
        NiStream::UnregisterObjectLoader("NiRotatingParticles");
        NiStream::UnregisterObjectLoader("NiRotatingParticlesData");
        NiStream::UnregisterObjectLoader((char const*)&g_011f5ee8_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5ee0_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5ae0_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5b24_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5b2c_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5b1c_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5ed8_arg0);

        NiStream::UnregisterObjectLoader((char const*)&g_011f5b48_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5b50_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f444c_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5ecc_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5ec4_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4a0c_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4a38_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5ebc_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5eb4_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5eac_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5e94_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f49a4_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4a40_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4a88_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5af4_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4a20_arg0);

        NiStream::UnregisterObjectLoader((char const*)&g_011f4a70_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5e8c_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5e84_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f4430_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5b78_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5e5c_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5e54_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5e64_arg0);
        NiStream::UnregisterObjectLoader((char const*)&g_011f5e6c_arg0);

        DestroyPairArrays();
        FUN_00a928b0_shell::ClearFixedStrings();
        FUN_00a5cf60();
        FUN_00a9a120();
        ReleaseGlobalHolder();
        FUN_00a9bb60();
        FUN_00a81590();
        FUN_00a6f4d0();
        ReleaseGlobalStrings();
        FUN_00a8f620();
        FUN_00a76b30();
        FUN_00a632b0();
        FUN_00a62ae0();
        DestroyGlobalPool();
        ReleasePendingTable();
        FreeGlobalAlias();
        FUN_00a8f730::Release();
        FUN_00a8fcc0();
        ResetStreamLinkIDSet();
        FUN_00a8a200();
        FreeMemoryList();
        FUN_00a5b660();
    }
}

extern char DAT_011f5b80;
extern NiPoint3 DAT_011f426c;
extern NiPoint3 DAT_011f4288;
extern float DAT_011f4294;
void __cdecl FUN_00a5b630();
void __cdecl InitTrigTables();
void __cdecl FUN_00a9c2a0();
void __cdecl FUN_00a927e0();
void __cdecl FUN_00a5cef0();
void __cdecl FUN_00a9a090();
void __cdecl FUN_00a759e0();
void __cdecl FUN_00a29680();
void __cdecl FUN_00a81520();
void __cdecl FUN_00a9ba80();
void __cdecl FUN_00a6f450();
void __cdecl FUN_00a6b410();
void __cdecl CreateCullingProperty();
void __cdecl CreateImageConverter();
void __cdecl FUN_00a660a0();
void __cdecl FUN_00a7f740();
void __cdecl FUN_00a73e20();
void __cdecl CreateNiAlphaAccumulator();
void __cdecl CreateNiAlphaProperty();
void __cdecl FUN_00a9b330();
void __cdecl CreateProperty();
void __cdecl FUN_00a9b150();
void __cdecl FUN_00a96600();
void __cdecl FUN_00a7e770();
void __cdecl FUN_00a7f8e0();
void __cdecl FUN_00a9af90();
void __cdecl CreateNiParticleObject();
void __cdecl FUN_00a71430();
void __cdecl FUN_00a5f030();
void __cdecl FUN_00a89490();
void __cdecl FUN_00a6f000();
void __cdecl CreateNiDirectionalLight();
void __cdecl FUN_00a9a640();
void __cdecl FUN_00a7b380();
void __cdecl FUN_00a9a480();
void __cdecl FUN_00a89190();
void __cdecl CreateNiFogProperty();
void __cdecl FUN_00a99cd0();
void __cdecl FUN_00a99a10();
void __cdecl FUN_00a99710();
void __cdecl CreateSceneFactoryObject();
void __cdecl CreateNiPairHolder();
void __cdecl FUN_00a756d0();
void __cdecl FUN_00a8b220();
void __cdecl FUN_00a98e70();
void __cdecl FUN_00a98d30();
void __cdecl FUN_00a982d0();
void __cdecl CreateSpawnedPixelData();
void __cdecl FUN_00a7d6e0();
void __cdecl CreateRangeLODData();
void __cdecl CreateObj_a96();
void __cdecl AllocateAndConstruct();
void __cdecl FUN_00a877a0();
void __cdecl CreateBA87920Object();
void __cdecl FUN_00a958b0();
void __cdecl FUN_00a814e0();
void __cdecl FUN_00a84d30();
void __cdecl FUN_00a866f0();
void __cdecl FUN_00a6c8a0();
void __cdecl FUN_00a81fb0();
void __cdecl FUN_00a952a0();
void __cdecl CreateA5FC10Stub();
void __cdecl CreateNiSourceCubeMap();
void __cdecl FUN_00a95160();
void __cdecl FUN_00a94e20();
void __cdecl FUN_00a6f410();
void __cdecl FUN_00a74230();
void __cdecl FUN_00a94930();
void __cdecl CreateSwitchNode();
void __cdecl FUN_00a93870();
void __cdecl FUN_00a929b0();
void __cdecl CreateTexturingProperty();
void __cdecl CreateNiTriShapeX();
void __cdecl FUN_00a87140();
void __cdecl FUN_00a7b790();
void __cdecl FUN_00a81760();
void __cdecl CreateNiTriStrips();
void __cdecl FUN_00a75ec0();
void __cdecl FUN_00a923f0();
void __cdecl FUN_00a91fe0();
void __cdecl FUN_00a5f280();
void __cdecl CreateNiExtraData();
void __cdecl FUN_00a91ee0();
void __cdecl FUN_00a8ff80();
void __cdecl FUN_00a90b20();
void __cdecl FUN_00a8ffc0();
void __cdecl FUN_00a91290();
void __cdecl FUN_00a62110();
void __cdecl FUN_00a7e930();
void __cdecl FUN_00a8fd80();
void __cdecl CreateSdmDerived();
void __cdecl FUN_00a74da0();
extern const char DAT_0109df08;
extern const char DAT_0109d378;
extern const char DAT_0109f220;
extern const char DAT_0109b4e0;
extern const char DAT_0109f210;
extern const char DAT_0109f1fc;
extern const char DAT_0109f1e4;
extern const char DAT_0109f1c8;
extern const char DAT_0109dec4;
extern const char DAT_0109df58;
extern const char DAT_0109f1b4;
extern const char DAT_0109f1a8;
extern const char DAT_0109cd04;
extern const char DAT_0109f190;
extern const char DAT_0109b0f8;
extern const char DAT_0109ed6c;
extern const char DAT_0109ca34;
extern const char DAT_0109d890;
extern const char DAT_0109f17c;
extern const char DAT_0109dab0;
extern const char DAT_0109f168;
extern const char DAT_0109ecb0;
extern const char DAT_0109f158;
extern const char DAT_0109f144;
extern const char DAT_0109f130;
extern const char DAT_0109f124;
extern const char DAT_0109d64c;
extern const char DAT_0109f118;
extern const char DAT_0109d79c;
extern const char DAT_0109b6b8;
extern const char DAT_0109f10c;
extern const char DAT_0109f0f8;
extern const char DAT_0109f0e0;
extern const char DAT_0109f0d4;
extern const char DAT_0109f0c4;
extern const char DAT_0109dc94;
extern const char DAT_0109de0c;
extern const char DAT_0109f090;
extern const char DAT_0109f07c;
extern const char DAT_0109f064;
extern const char DAT_0109f054;
extern const char DAT_0109ea78;
extern const char DAT_0109ebd4;
extern const char DAT_0109f044;
extern const char DAT_0109e314;
extern const char DAT_0109e6a0;
extern const char DAT_0109e6ec;
extern const char DAT_0109c808;
extern const char DAT_0109e560;
extern const char DAT_0109f030;
extern const char DAT_0109baa4;
extern const char DAT_0109bb6c;
extern const char DAT_0109f01c;
extern const char DAT_0109f010;
extern const char DAT_0109cb84;
extern const char DAT_0109d43c;
extern const char DAT_0109effc;
extern const char DAT_0109efec;
extern const char DAT_0109efd4;
extern const char DAT_0109efc4;
extern const char DAT_0109c7a0;
extern const char DAT_0109d548;
extern const char DAT_0109e96c;
extern const char DAT_0109db9c;
extern const char DAT_0109e408;
extern const char DAT_0109ce38;
extern const char DAT_0109d990;
extern const char DAT_0109efac;
extern const char DAT_0109ef98;
extern const char DAT_0109b7dc;
extern const char DAT_0109ef30;
extern const char DAT_0109ef84;
extern const char DAT_0109ef70;
extern const char DAT_0109ef58;
extern const char DAT_0109ef48;
void __cdecl FUN_00a64900(const void*, void(__cdecl*)());
// Runs one-time initialization guarded by DAT_011f5b80: calls setup routines, resets DAT_011f4294/DAT_011f4288, and registers many handlers via FUN_00a64900.
// @fnv 0x00a89cc0
void __cdecl InitializeGameSystems()
{
    if (DAT_011f5b80 == 0)
    {
        DAT_011f5b80 = 1;
        FUN_00a5b630();
        InitTrigTables();
        FUN_00a9c2a0();
        FUN_00a927e0();
        FUN_00a5cef0();
        FUN_00a9a090();
        FUN_00a759e0();
        FUN_00a29680();
        FUN_00a81520();
        FUN_00a9ba80();
        FUN_00a6f450();
        FUN_00a6b410();
        CreateCullingProperty();
        DAT_011f4294 = 0.0f;
        DAT_011f4288 = DAT_011f426c;
        CreateImageConverter();
        FUN_00a660a0();
        FUN_00a64900(&DAT_0109df08, FUN_00a7f740);
        FUN_00a64900(&DAT_0109d378, FUN_00a73e20);
        FUN_00a64900(&DAT_0109f220, CreateNiAlphaAccumulator);
        FUN_00a64900(&DAT_0109b4e0, CreateNiAlphaProperty);
        FUN_00a64900(&DAT_0109f210, FUN_00a9b330);
        FUN_00a64900(&DAT_0109f1fc, CreateProperty);
        FUN_00a64900(&DAT_0109f1e4, FUN_00a9b150);
        FUN_00a64900(&DAT_0109f1c8, FUN_00a96600);
        FUN_00a64900(&DAT_0109dec4, FUN_00a7e770);
        FUN_00a64900(&DAT_0109df58, FUN_00a7f8e0);
        FUN_00a64900(&DAT_0109f1b4, FUN_00a9af90);
        FUN_00a64900(&DAT_0109f1a8, CreateNiParticleObject);
        FUN_00a64900(&DAT_0109cd04, FUN_00a71430);
        FUN_00a64900(&DAT_0109f190, CreateNiAlphaAccumulator);
        FUN_00a64900(&DAT_0109b0f8, FUN_00a5f030);
        FUN_00a64900(&DAT_0109ed6c, FUN_00a89490);
        FUN_00a64900(&DAT_0109ca34, FUN_00a6f000);
        FUN_00a64900(&DAT_0109d890, CreateNiDirectionalLight);
        FUN_00a64900(&DAT_0109f17c, FUN_00a9a640);
        FUN_00a64900(&DAT_0109dab0, FUN_00a7b380);
        FUN_00a64900(&DAT_0109f168, FUN_00a9a480);
        FUN_00a64900(&DAT_0109ecb0, FUN_00a89190);
        FUN_00a64900(&DAT_0109f158, CreateNiFogProperty);
        FUN_00a64900(&DAT_0109f144, FUN_00a99cd0);
        FUN_00a64900(&DAT_0109f130, FUN_00a99a10);
        FUN_00a64900(&DAT_0109f124, FUN_00a99710);
        FUN_00a64900(&DAT_0109d64c, CreateSceneFactoryObject);
        FUN_00a64900(&DAT_0109f118, CreateNiPairHolder);
        FUN_00a64900(&DAT_0109d79c, FUN_00a756d0);
        FUN_00a64900(&DAT_0109b6b8, FUN_00a5f030);
        FUN_00a64900(&DAT_0109f10c, FUN_00a8b220);
        FUN_00a64900(&DAT_0109f0f8, FUN_00a98e70);
        FUN_00a64900(&DAT_0109f0e0, FUN_00a98d30);
        FUN_00a64900(&DAT_0109f0d4, FUN_00a9b150);
        FUN_00a64900(&DAT_0109f0c4, FUN_00a96600);
        FUN_00a64900(&DAT_0109f0a0, FUN_00a982d0);
        FUN_00a64900(&DAT_0109dc94, CreateSpawnedPixelData);
        FUN_00a64900(&DAT_0109de0c, FUN_00a7d6e0);
        FUN_00a64900(&DAT_0109f090, CreateRangeLODData);
        FUN_00a64900(&DAT_0109f07c, FUN_00a9b150);
        FUN_00a64900(&DAT_0109f064, CreateObj_a96);
        FUN_00a64900(&DAT_0109f054, AllocateAndConstruct);
        FUN_00a64900(&DAT_0109ea78, FUN_00a877a0);
        FUN_00a64900(&DAT_0109ebd4, CreateBA87920Object);
        FUN_00a64900(&DAT_0109f044, FUN_00a958b0);
        FUN_00a64900(&DAT_0109e314, FUN_00a814e0);
        FUN_00a64900(&DAT_0109e6a0, FUN_00a84d30);
        FUN_00a64900(&DAT_0109e6ec, FUN_00a866f0);
        FUN_00a64900(&DAT_0109c808, FUN_00a6c8a0);
        FUN_00a64900(&DAT_0109e560, FUN_00a81fb0);
        FUN_00a64900(&DAT_0109f030, FUN_00a952a0);
        FUN_00a64900(&DAT_0109baa4, CreateA5FC10Stub);
        FUN_00a64900(&DAT_0109bb6c, CreateNiSourceCubeMap);
        FUN_00a64900(&DAT_0109f01c, FUN_00a95160);
        FUN_00a64900(&DAT_0109f010, FUN_00a94e20);
        FUN_00a64900(&DAT_0109cb84, FUN_00a6f410);
        FUN_00a64900(&DAT_0109d43c, FUN_00a74230);
        FUN_00a64900(&DAT_0109effc, FUN_00a94930);
        FUN_00a64900(&DAT_0109efec, CreateSwitchNode);
        FUN_00a64900(&DAT_0109efd4, FUN_00a93870);
        FUN_00a64900(&DAT_0109efc4, FUN_00a929b0);
        FUN_00a64900(&DAT_0109c7a0, CreateTexturingProperty);
        FUN_00a64900(&DAT_0109d548, CreateNiTriShapeX);
        FUN_00a64900(&DAT_0109e96c, FUN_00a87140);
        FUN_00a64900(&DAT_0109db9c, FUN_00a7b790);
        FUN_00a64900(&DAT_0109e408, FUN_00a81760);
        FUN_00a64900(&DAT_0109ce38, CreateNiTriStrips);
        FUN_00a64900(&DAT_0109d990, FUN_00a75ec0);
        FUN_00a64900(&DAT_0109efac, FUN_00a923f0);
        FUN_00a64900(&DAT_0109ef98, FUN_00a91fe0);
        FUN_00a64900(&DAT_0109b7dc, FUN_00a5f280);
        FUN_00a64900(&DAT_0109ef30, CreateNiExtraData);
        FUN_00a64900(&DAT_0109ef84, FUN_00a91ee0);
        FUN_00a64900(&DAT_0109ef70, FUN_00a8ff80);
        FUN_00a64900(&DAT_0109ef58, FUN_00a90b20);
        FUN_00a64900(&DAT_0109ef48, FUN_00a8ffc0);
        FUN_00a91290();
        FUN_00a62110();
        FUN_00a7e930();
        FUN_00a29680();
        FUN_00a8fd80();
        CreateSdmDerived();
        FUN_00a74da0();
    }
}
