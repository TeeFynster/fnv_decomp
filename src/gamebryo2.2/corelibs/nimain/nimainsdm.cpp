
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
// src: COMMUNITY 0x00a8a200
void NiTAbstractPoolAllocator__SDMShutdown()
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

void __cdecl ClearStaticStringTable();
void __cdecl NiAlphaProperty__SDMShutdown();
void __cdecl ReleasePendingTable();
void __cdecl NiRenderer__SDMShutdown();
void __cdecl NiStream__SDMShutdown();
void __cdecl ReleaseGlobalStrings();
void __cdecl NiStencilProperty__SDMShutdown();
void __cdecl ReleaseGlobalHolder();
void __cdecl NiImageConverter__SDMShutdown();
void __cdecl FreeGlobalAlias();
void __cdecl NiShadeProperty__SDMShutdown();
void __cdecl FreeMemoryList();
void __cdecl NiCullingProperty__SDMShutdown();
void __cdecl NiSingleShaderMaterialLibrary__SDMShutdown();
void __cdecl ResetStreamLinkIDSet();
void __cdecl DestroyGlobalPool();
void __cdecl NiFogProperty__SDMShutdown();
void __cdecl NiMetricsLayer__SDMShutdown();
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
// src: COMMUNITY 0x00a8a280
void __cdecl NiMainSDM_Shutdown()
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
        NiAlphaProperty__SDMShutdown();
        NiFogProperty__SDMShutdown();
        ReleaseGlobalHolder();
        NiMetricsLayer__SDMShutdown();
        NiShadeProperty__SDMShutdown();
        NiStencilProperty__SDMShutdown();
        ReleaseGlobalStrings();
        NiCullingProperty__SDMShutdown();
        NiImageConverter__SDMShutdown();
        NiStream__SDMShutdown();
        NiRenderer__SDMShutdown();
        DestroyGlobalPool();
        ReleasePendingTable();
        FreeGlobalAlias();
        FUN_00a8f730::Release();
        NiSingleShaderMaterialLibrary__SDMShutdown();
        ResetStreamLinkIDSet();
        NiTAbstractPoolAllocator__SDMShutdown();
        FreeMemoryList();
        ClearStaticStringTable();
    }
}

extern char DAT_011f5b80;
extern NiPoint3 DAT_011f426c;
extern NiPoint3 DAT_011f4288;
extern float DAT_011f4294;
void __cdecl NiGlobalStringTable__SDMInit();
void __cdecl InitTrigTables();
void __cdecl FUN_00a9c2a0();
void __cdecl FUN_00a927e0();
void __cdecl NiAlphaProperty__SDMInit();
void __cdecl NiFogProperty__SDMInit();
void __cdecl NiMaterialProperty__SDMInit();
void __cdecl Object_DoNothing();
void __cdecl NiShadeProperty__SDMInit();
void __cdecl NiShaderConstantMapEntry__SDMInit();
void __cdecl NiStencilProperty__SDMInit();
void __cdecl FUN_00a6b410();
void __cdecl CreateCullingProperty();
void __cdecl CreateImageConverter();
void __cdecl NiStream__SDMInit();
void __cdecl BSPackedAdditionalGeometryData_CreateObject();
void __cdecl NiAdditionalGeometryData_CreateObject();
void __cdecl CreateNiAlphaAccumulator();
void __cdecl CreateNiAlphaProperty();
void __cdecl NiAmbientLight_CreateObject();
void __cdecl CreateProperty();
void __cdecl NiParticles_CreateObject();
void __cdecl NiParticlesData_CreateObject();
void __cdecl NiBillboardNode_CreateObject();
void __cdecl NiBinaryExtraData_CreateObject();
void __cdecl NiBooleanExtraData_CreateObject();
void __cdecl CreateNiParticleObject();
void __cdecl NiCamera_CreateObject();
void __cdecl NiNode_CreateObject();
void __cdecl NiColorExtraData_CreateObject();
void __cdecl NiDefaultAVObjectPalette_CreateObject();
void __cdecl CreateNiDirectionalLight();
void __cdecl NiDitherProperty_CreateObject();
void __cdecl NiExtraData_CreateObject();
void __cdecl NiFloatExtraData_CreateObject();
void __cdecl NiFloatsExtraData_CreateObject();
void __cdecl CreateNiFogProperty();
void __cdecl NiIntegerExtraData_CreateObject();
void __cdecl NiIntegersExtraData_CreateObject();
void __cdecl NiLODNode_CreateObject();
void __cdecl CreateSceneFactoryObject();
void __cdecl CreateNiPairHolder();
void __cdecl NiMaterialProperty_CreateObject();
void __cdecl NiPalette_CreateObject();
void __cdecl NiParticleMeshes_CreateObject();
void __cdecl NiParticleMeshesData_CreateObject();
void __cdecl NiPersistentSrcTextureRendererData_CreateObject();
void __cdecl CreateSpawnedPixelData();
void __cdecl NiPointLight_CreateObject();
void __cdecl CreateRangeLODData();
void __cdecl CreateObj_a96();
void __cdecl AllocateAndConstruct();
void __cdecl NiScreenElements_CreateObject();
void __cdecl CreateBA87920Object();
void __cdecl NiScreenTexture_CreateObject();
void __cdecl FUN_00a814e0();
void __cdecl NiSkinData_CreateObject();
void __cdecl NiSkinInstance_CreateObject();
void __cdecl BSDismemberSkinInstance_CreateObject();
void __cdecl NiSkinPartition_CreateObject();
void __cdecl NiSortAdjustNode_CreateObject();
void __cdecl CreateA5FC10Stub();
void __cdecl CreateNiSourceCubeMap();
void __cdecl NiSpecularProperty_CreateObject();
void __cdecl NiSpotLight_CreateObject();
void __cdecl NiStencilProperty_CreateObject();
void __cdecl NiStringExtraData_CreateObject();
void __cdecl NiStringsExtraData_CreateObject();
void __cdecl CreateSwitchNode();
void __cdecl NiSwitchStringExtraData_CreateObject();
void __cdecl NiTextureEffect_CreateObject();
void __cdecl CreateTexturingProperty();
void __cdecl CreateNiTriShapeX();
void __cdecl BSSegmentedTriShape_CreateObject();
void __cdecl NiTriShapeData_CreateObject();
void __cdecl NiTriShapeDynamicData_CreateObject();
void __cdecl CreateNiTriStrips();
void __cdecl NiTriStripsData_CreateObject();
void __cdecl NiTriStripsDynamicData_CreateObject();
void __cdecl NiVectorExtraData_CreateObject();
void __cdecl NiVertexColorProperty_CreateObject();
void __cdecl CreateNiExtraData();
void __cdecl NiScreenSpaceCamera_CreateObject();
void __cdecl NiScreenGeometry_CreateObject();
void __cdecl NiScreenGeometryData_CreateObject();
void __cdecl NiScreenPolygon_CreateObject();
void __cdecl NiScreenGeometryData__SDMInit();
void __cdecl FUN_00a62110();
void __cdecl NiPoint3__SDMInit();
void __cdecl NiSingleShaderMaterialLibrary__SDMInit();
void __cdecl CreateSdmDerived();
void __cdecl NiProcessorSpecificCode_OptimizeMainEngineForProcessor();
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
        NiGlobalStringTable__SDMInit();
        InitTrigTables();
        FUN_00a9c2a0();
        FUN_00a927e0();
        NiAlphaProperty__SDMInit();
        NiFogProperty__SDMInit();
        NiMaterialProperty__SDMInit();
        Object_DoNothing();
        NiShadeProperty__SDMInit();
        NiShaderConstantMapEntry__SDMInit();
        NiStencilProperty__SDMInit();
        FUN_00a6b410();
        CreateCullingProperty();
        DAT_011f4294 = 0.0f;
        DAT_011f4288 = DAT_011f426c;
        CreateImageConverter();
        NiStream__SDMInit();
        FUN_00a64900(&DAT_0109df08, BSPackedAdditionalGeometryData_CreateObject);
        FUN_00a64900(&DAT_0109d378, NiAdditionalGeometryData_CreateObject);
        FUN_00a64900(&DAT_0109f220, CreateNiAlphaAccumulator);
        FUN_00a64900(&DAT_0109b4e0, CreateNiAlphaProperty);
        FUN_00a64900(&DAT_0109f210, NiAmbientLight_CreateObject);
        FUN_00a64900(&DAT_0109f1fc, CreateProperty);
        FUN_00a64900(&DAT_0109f1e4, NiParticles_CreateObject);
        FUN_00a64900(&DAT_0109f1c8, NiParticlesData_CreateObject);
        FUN_00a64900(&DAT_0109dec4, NiBillboardNode_CreateObject);
        FUN_00a64900(&DAT_0109df58, NiBinaryExtraData_CreateObject);
        FUN_00a64900(&DAT_0109f1b4, NiBooleanExtraData_CreateObject);
        FUN_00a64900(&DAT_0109f1a8, CreateNiParticleObject);
        FUN_00a64900(&DAT_0109cd04, NiCamera_CreateObject);
        FUN_00a64900(&DAT_0109f190, CreateNiAlphaAccumulator);
        FUN_00a64900(&DAT_0109b0f8, NiNode_CreateObject);
        FUN_00a64900(&DAT_0109ed6c, NiColorExtraData_CreateObject);
        FUN_00a64900(&DAT_0109ca34, NiDefaultAVObjectPalette_CreateObject);
        FUN_00a64900(&DAT_0109d890, CreateNiDirectionalLight);
        FUN_00a64900(&DAT_0109f17c, NiDitherProperty_CreateObject);
        FUN_00a64900(&DAT_0109dab0, NiExtraData_CreateObject);
        FUN_00a64900(&DAT_0109f168, NiFloatExtraData_CreateObject);
        FUN_00a64900(&DAT_0109ecb0, NiFloatsExtraData_CreateObject);
        FUN_00a64900(&DAT_0109f158, CreateNiFogProperty);
        FUN_00a64900(&DAT_0109f144, NiIntegerExtraData_CreateObject);
        FUN_00a64900(&DAT_0109f130, NiIntegersExtraData_CreateObject);
        FUN_00a64900(&DAT_0109f124, NiLODNode_CreateObject);
        FUN_00a64900(&DAT_0109d64c, CreateSceneFactoryObject);
        FUN_00a64900(&DAT_0109f118, CreateNiPairHolder);
        FUN_00a64900(&DAT_0109d79c, NiMaterialProperty_CreateObject);
        FUN_00a64900(&DAT_0109b6b8, NiNode_CreateObject);
        FUN_00a64900(&DAT_0109f10c, NiPalette_CreateObject);
        FUN_00a64900(&DAT_0109f0f8, NiParticleMeshes_CreateObject);
        FUN_00a64900(&DAT_0109f0e0, NiParticleMeshesData_CreateObject);
        FUN_00a64900(&DAT_0109f0d4, NiParticles_CreateObject);
        FUN_00a64900(&DAT_0109f0c4, NiParticlesData_CreateObject);
        FUN_00a64900(&DAT_0109f0a0, NiPersistentSrcTextureRendererData_CreateObject);
        FUN_00a64900(&DAT_0109dc94, CreateSpawnedPixelData);
        FUN_00a64900(&DAT_0109de0c, NiPointLight_CreateObject);
        FUN_00a64900(&DAT_0109f090, CreateRangeLODData);
        FUN_00a64900(&DAT_0109f07c, NiParticles_CreateObject);
        FUN_00a64900(&DAT_0109f064, CreateObj_a96);
        FUN_00a64900(&DAT_0109f054, AllocateAndConstruct);
        FUN_00a64900(&DAT_0109ea78, NiScreenElements_CreateObject);
        FUN_00a64900(&DAT_0109ebd4, CreateBA87920Object);
        FUN_00a64900(&DAT_0109f044, NiScreenTexture_CreateObject);
        FUN_00a64900(&DAT_0109e314, FUN_00a814e0);
        FUN_00a64900(&DAT_0109e6a0, NiSkinData_CreateObject);
        FUN_00a64900(&DAT_0109e6ec, NiSkinInstance_CreateObject);
        FUN_00a64900(&DAT_0109c808, BSDismemberSkinInstance_CreateObject);
        FUN_00a64900(&DAT_0109e560, NiSkinPartition_CreateObject);
        FUN_00a64900(&DAT_0109f030, NiSortAdjustNode_CreateObject);
        FUN_00a64900(&DAT_0109baa4, CreateA5FC10Stub);
        FUN_00a64900(&DAT_0109bb6c, CreateNiSourceCubeMap);
        FUN_00a64900(&DAT_0109f01c, NiSpecularProperty_CreateObject);
        FUN_00a64900(&DAT_0109f010, NiSpotLight_CreateObject);
        FUN_00a64900(&DAT_0109cb84, NiStencilProperty_CreateObject);
        FUN_00a64900(&DAT_0109d43c, NiStringExtraData_CreateObject);
        FUN_00a64900(&DAT_0109effc, NiStringsExtraData_CreateObject);
        FUN_00a64900(&DAT_0109efec, CreateSwitchNode);
        FUN_00a64900(&DAT_0109efd4, NiSwitchStringExtraData_CreateObject);
        FUN_00a64900(&DAT_0109efc4, NiTextureEffect_CreateObject);
        FUN_00a64900(&DAT_0109c7a0, CreateTexturingProperty);
        FUN_00a64900(&DAT_0109d548, CreateNiTriShapeX);
        FUN_00a64900(&DAT_0109e96c, BSSegmentedTriShape_CreateObject);
        FUN_00a64900(&DAT_0109db9c, NiTriShapeData_CreateObject);
        FUN_00a64900(&DAT_0109e408, NiTriShapeDynamicData_CreateObject);
        FUN_00a64900(&DAT_0109ce38, CreateNiTriStrips);
        FUN_00a64900(&DAT_0109d990, NiTriStripsData_CreateObject);
        FUN_00a64900(&DAT_0109efac, NiTriStripsDynamicData_CreateObject);
        FUN_00a64900(&DAT_0109ef98, NiVectorExtraData_CreateObject);
        FUN_00a64900(&DAT_0109b7dc, NiVertexColorProperty_CreateObject);
        FUN_00a64900(&DAT_0109ef30, CreateNiExtraData);
        FUN_00a64900(&DAT_0109ef84, NiScreenSpaceCamera_CreateObject);
        FUN_00a64900(&DAT_0109ef70, NiScreenGeometry_CreateObject);
        FUN_00a64900(&DAT_0109ef58, NiScreenGeometryData_CreateObject);
        FUN_00a64900(&DAT_0109ef48, NiScreenPolygon_CreateObject);
        NiScreenGeometryData__SDMInit();
        FUN_00a62110();
        NiPoint3__SDMInit();
        Object_DoNothing();
        NiSingleShaderMaterialLibrary__SDMInit();
        CreateSdmDerived();
        NiProcessorSpecificCode_OptimizeMainEngineForProcessor();
    }
}
