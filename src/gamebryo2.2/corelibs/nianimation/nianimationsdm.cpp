
// src/gamebryo2.2/corelibs/nianimation/nianimationsdm.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nianimationsdm.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl NiStream_UnregisterLoader(const char* pName);
void __cdecl RemovePostProcess(void(__cdecl* pfnCallback)());
void __cdecl NiOldAnimationConverter_Convert();
void __cdecl ClearNodeList();
void __cdecl ClearGlobalStrings();
void __cdecl ResetRegistry();
extern bool g_bInitialized_011f369d;

static const char s_sz00[] = "NiAlphaController";
static const char s_sz01[] = "NiBlendAccumTransformInterpolator";
static const char s_sz02[] = "NiBlendBoolInterpolator";
static const char s_sz03[] = "NiBlendColorInterpolator";
static const char s_sz04[] = "NiBlendFloatInterpolator";
static const char s_sz05[] = "NiBlendPoint3Interpolator";
static const char s_sz06[] = "NiBlendQuaternionInterpolator";
static const char s_sz07[] = "NiBlendTransformInterpolator";
static const char s_sz08[] = "NiBoneLODController";
static const char s_sz09[] = "NiBoolData";
static const char s_sz10[] = "NiBoolInterpolator";
static const char s_sz11[] = "NiBoolTimelineInterpolator";
static const char s_sz12[] = "NiBSplineBasisData";
static const char s_sz13[] = "NiBSplineData";
static const char s_sz14[] = "NiBSplineColorInterpolator";
static const char s_sz15[] = "NiBSplineCompColorInterpolator";
static const char s_sz16[] = "NiBSplineCompFloatInterpolator";
static const char s_sz17[] = "NiBSplineCompPoint3Interpolator";
static const char s_sz18[] = "NiBSplineCompTransformInterpolator";
static const char s_sz19[] = "NiBSplineFloatInterpolator";
static const char s_sz20[] = "NiBSplinePoint3Interpolator";
static const char s_sz21[] = "NiBSplineTransformInterpolator";
static const char s_sz22[] = "NiColorData";
static const char s_sz23[] = "NiColorExtraDataController";
static const char s_sz24[] = "NiColorInterpolator";
static const char s_sz25[] = "NiControllerManager";
static const char s_sz26[] = "NiControllerSequence";
static const char s_sz27[] = "NiFlipController";
static const char s_sz28[] = "NiFloatData";
static const char s_sz29[] = "NiFloatExtraDataController";
static const char s_sz30[] = "NiFloatInterpolator";
static const char s_sz31[] = "NiFloatsExtraDataController";
static const char s_sz32[] = "NiFloatsExtraDataPoint3Controller";
static const char s_sz33[] = "NiGeomMorpherController";
static const char s_sz34[] = "NiKeyframeController";
static const char s_sz35[] = "NiKeyframeData";
static const char s_sz36[] = "NiKeyframeManager";
static const char s_sz37[] = "NiLightColorController";
static const char s_sz38[] = "NiLightDimmerController";
static const char s_sz39[] = "NiLookAtController";
static const char s_sz40[] = "NiLookAtInterpolator";
static const char s_sz41[] = "NiMaterialColorController";
static const char s_sz42[] = "NiMorphData";
static const char s_sz43[] = "NiMultiTargetTransformController";
static const char s_sz44[] = "NiPathController";
static const char s_sz45[] = "NiPathInterpolator";
static const char s_sz46[] = "NiPoint3Interpolator";
static const char s_sz47[] = "NiPosData";
static const char s_sz48[] = "NiQuaternionInterpolator";
static const char s_sz49[] = "NiRollController";
static const char s_sz50[] = "NiRotData";
static const char s_sz51[] = "NiSequence";
static const char s_sz52[] = "NiSequenceStreamHelper";
static const char s_sz53[] = "NiStringPalette";
static const char s_sz54[] = "NiTextKeyExtraData";
static const char s_sz55[] = "NiTextureTransformController";
static const char s_sz56[] = "NiTransformController";
static const char s_sz57[] = "NiTransformData";
static const char s_sz58[] = "NiTransformInterpolator";
static const char s_sz59[] = "NiUVController";
static const char s_sz60[] = "NiUVData";
static const char s_sz61[] = "NiVisController";
static const char s_sz62[] = "BSAnimNotes";
static const char s_sz63[] = "BSGrabIKNote";
static const char s_sz64[] = "BSLookIKNote";
static const char s_sz65[] = "BSRotAccumTransfInterpolator";
static const char s_sz66[] = "BSTreadTransfInterpolator";
static const char s_sz67[] = "BSBlendTreadTransfInterpolator";
static const char s_sz68[] = "BSMultiTargetTreadTransfController";
static const char s_sz69[] = "BSFrustumFOVController";
static const char s_sz70[] = "NiVisData";
extern const char g_szShutdownEnd[] = "";

// @fnv 0x00a2de70
void __cdecl ShutdownAnimationClasses()
{
    if (!g_bInitialized_011f369d)
        return;
    g_bInitialized_011f369d = false;
    NiStream_UnregisterLoader(s_sz00);
    NiStream_UnregisterLoader(s_sz01);
    NiStream_UnregisterLoader(s_sz02);
    NiStream_UnregisterLoader(s_sz03);
    NiStream_UnregisterLoader(s_sz04);
    NiStream_UnregisterLoader(s_sz05);
    NiStream_UnregisterLoader(s_sz06);
    NiStream_UnregisterLoader(s_sz07);
    NiStream_UnregisterLoader(s_sz08);
    NiStream_UnregisterLoader(s_sz09);
    NiStream_UnregisterLoader(s_sz10);
    NiStream_UnregisterLoader(s_sz11);
    NiStream_UnregisterLoader(s_sz12);
    NiStream_UnregisterLoader(s_sz13);
    NiStream_UnregisterLoader(s_sz14);
    NiStream_UnregisterLoader(s_sz15);
    NiStream_UnregisterLoader(s_sz16);
    NiStream_UnregisterLoader(s_sz17);
    NiStream_UnregisterLoader(s_sz18);
    NiStream_UnregisterLoader(s_sz19);
    NiStream_UnregisterLoader(s_sz20);
    NiStream_UnregisterLoader(s_sz21);
    NiStream_UnregisterLoader(s_sz22);
    NiStream_UnregisterLoader(s_sz23);
    NiStream_UnregisterLoader(s_sz24);
    NiStream_UnregisterLoader(s_sz25);
    NiStream_UnregisterLoader(s_sz26);
    NiStream_UnregisterLoader(s_sz27);
    NiStream_UnregisterLoader(s_sz28);
    NiStream_UnregisterLoader(s_sz29);
    NiStream_UnregisterLoader(s_sz30);
    NiStream_UnregisterLoader(s_sz31);
    NiStream_UnregisterLoader(s_sz32);
    NiStream_UnregisterLoader(s_sz33);
    NiStream_UnregisterLoader(s_sz34);
    NiStream_UnregisterLoader(s_sz35);
    NiStream_UnregisterLoader(s_sz36);
    NiStream_UnregisterLoader(s_sz37);
    NiStream_UnregisterLoader(s_sz38);
    NiStream_UnregisterLoader(s_sz39);
    NiStream_UnregisterLoader(s_sz40);
    NiStream_UnregisterLoader(s_sz41);
    NiStream_UnregisterLoader(s_sz42);
    NiStream_UnregisterLoader(s_sz43);
    NiStream_UnregisterLoader(s_sz44);
    NiStream_UnregisterLoader(s_sz45);
    NiStream_UnregisterLoader(s_sz46);
    NiStream_UnregisterLoader(s_sz47);
    NiStream_UnregisterLoader(s_sz48);
    NiStream_UnregisterLoader(s_sz49);
    NiStream_UnregisterLoader(s_sz50);
    NiStream_UnregisterLoader(s_sz51);
    NiStream_UnregisterLoader(s_sz52);
    NiStream_UnregisterLoader(s_sz53);
    NiStream_UnregisterLoader(s_sz54);
    NiStream_UnregisterLoader(s_sz55);
    NiStream_UnregisterLoader(s_sz56);
    NiStream_UnregisterLoader(s_sz57);
    NiStream_UnregisterLoader(s_sz58);
    NiStream_UnregisterLoader(s_sz59);
    NiStream_UnregisterLoader(s_sz60);
    NiStream_UnregisterLoader(s_sz61);
    NiStream_UnregisterLoader(s_sz62);
    NiStream_UnregisterLoader(s_sz63);
    NiStream_UnregisterLoader(s_sz64);
    NiStream_UnregisterLoader(s_sz65);
    NiStream_UnregisterLoader(s_sz66);
    NiStream_UnregisterLoader(s_sz67);
    NiStream_UnregisterLoader(s_sz68);
    NiStream_UnregisterLoader(s_sz69);
    NiStream_UnregisterLoader(s_sz70);
    RemovePostProcess(NiOldAnimationConverter_Convert);
    ClearNodeList();
    ClearGlobalStrings();
    ResetRegistry();
}

extern bool DAT_011f369d;
void FUN_00a64900(const char*, void (*)());
void FUN_00a64920(void (*)());
void NiOldAnimationConverter_Convert();
void FUN_00a421c0();
extern const char DAT_01096060[];  // NiAlphaController
void CreateFloatInterpController();
extern const char DAT_0109603c[];  // NiBlendAccumTransformInterpolator
void NiBlendAccumTransformInterpolator_CreateObject();
extern const char DAT_01096024[];  // NiBlendBoolInterpolator
void NiBlendBoolInterpolator_CreateObject();
extern const char DAT_01096008[];  // NiBlendColorInterpolator
void CreateBlendColorInterpolator();
extern const char DAT_01095fec[];  // NiBlendFloatInterpolator
void CreateNiBlendFloatInterpolator();
extern const char DAT_01095fd0[];  // NiBlendPoint3Interpolator
void NiBlendPoint3Interpolator_CreateObject();
extern const char DAT_01095fb0[];  // NiBlendQuaternionInterpolator
void NiBlendQuaternionInterpolator_CreateObject();
extern const char DAT_01095f90[];  // NiBlendTransformInterpolator
void NiBlendTransformInterpolator_CreateObject();
extern const char DAT_01095f7c[];  // NiBoneLODController
void CreateBoneLODController();
extern const char DAT_01095f70[];  // NiBoolData
void NiBoolData_CreateObject();
extern const char DAT_01095f5c[];  // NiBoolInterpolator
void CreateNiKeyBasedInterpolator();
extern const char DAT_01095f40[];  // NiBoolTimelineInterpolator
void CreateBoolInterpolator();
extern const char DAT_01095f2c[];  // NiBSplineBasisData
void CreateNiSplineImpl();
extern const char DAT_01095f1c[];  // NiBSplineData
void NiBSplineData_CreateObject();
extern const char DAT_01095f00[];  // NiBSplineColorInterpolator
void NiBSplineColorInterpolator_CreateObject();
extern const char DAT_01095ee0[];  // NiBSplineCompColorInterpolator
void CreateSplineCompColorInterpolator();
extern const char DAT_01095ec0[];  // NiBSplineCompFloatInterpolator
void NiBSplineCompFloatInterpolator_CreateObject();
extern const char DAT_01095ea0[];  // NiBSplineCompPoint3Interpolator
void CreateComp4();
extern const char DAT_01095e7c[];  // NiBSplineCompTransformInterpolator
void CreateEvaluator();
extern const char DAT_01095e60[];  // NiBSplineFloatInterpolator
void NiBSplineFloatInterpolator_CreateObject();
extern const char DAT_01095e44[];  // NiBSplinePoint3Interpolator
void NiBSplinePoint3Interpolator_CreateObject();
extern const char DAT_01095e24[];  // NiBSplineTransformInterpolator
void NiBSplineTransformInterpolator_CreateObject();
extern const char DAT_01095e18[];  // NiColorData
void CreateNiColorData();
extern const char DAT_01095dfc[];  // NiColorExtraDataController
void NiColorExtraDataController_CreateObject();
extern const char DAT_01095de8[];  // NiColorInterpolator
void NiColorInterpolator_CreateObject();
extern const char DAT_01095dd4[];  // NiControllerManager
void NiControllerManager_CreateObject();
extern const char DAT_01095dbc[];  // NiControllerSequence
void NiControllerSequence_CreateObject();
extern const char DAT_01095da8[];  // NiFlipController
void CreateNiFlipController();
extern const char DAT_01095d9c[];  // NiFloatData
void CreateNiFloatData();
extern const char DAT_01095d80[];  // NiFloatExtraDataController
void NiFloatExtraDataController_CreateObject();
extern const char DAT_01095d6c[];  // NiFloatInterpolator
void CreateNiFloatInterpolator();
extern const char DAT_01095d50[];  // NiFloatsExtraDataController
void NiFloatsExtraDataController_CreateObject();
extern const char DAT_01095d2c[];  // NiFloatsExtraDataPoint3Controller
void NiFloatsExtraDataPoint3Controller_CreateObject();
extern const char DAT_01095d14[];  // NiGeomMorpherController
void NiGeomMorpherController_CreateObject();
extern const char DAT_01095cfc[];  // NiKeyframeController
void NiTransformController_CreateObject();
extern const char DAT_01095cec[];  // NiKeyframeData
void FUN_00a4e040();
extern const char DAT_01095cd8[];  // NiKeyframeManager
void NiKeyframeManager_CreateObject();
extern const char DAT_01095cc0[];  // NiLightColorController
void NiLightColorController_CreateObject();
extern const char DAT_01095ca8[];  // NiLightDimmerController
void NiLightDimmerController_CreateObject();
extern const char DAT_01095c94[];  // NiLookAtController
void CreateMorphData();
extern const char DAT_01095c7c[];  // NiLookAtInterpolator
void NiLookAtInterpolator_CreateObject();
extern const char DAT_01095c60[];  // NiMaterialColorController
void NiMaterialColorController_CreateObject();
extern const char DAT_01095c54[];  // NiMorphData
void CreateA51BF0();
extern const char DAT_01095c30[];  // NiMultiTargetTransformController
void CreateCtl();
extern const char DAT_01095c1c[];  // NiPathController
void NiPathController_CreateObject();
extern const char DAT_01095c08[];  // NiPathInterpolator
void CreateA51BF0Base();
extern const char DAT_01095bf0[];  // NiPoint3Interpolator
void NiPoint3Interpolator_CreateObject();
extern const char DAT_01095be4[];  // NiPosData
void NiPosData_CreateObject();
extern const char DAT_01095bc8[];  // NiQuaternionInterpolator
void CreateNiQuaternionInterpolator();
extern const char DAT_01095bb4[];  // NiRollController
void NiRollController_CreateObject();
extern const char DAT_01095ba8[];  // NiRotData
void NiRotData_CreateObject();
extern const char DAT_01095b9c[];  // NiSequence
void NiSequence_CreateObject();
extern const char DAT_01095b84[];  // NiSequenceStreamHelper
void NiSequenceStreamHelper_CreateObject();
extern const char DAT_01095b74[];  // NiStringPalette
void NiStringPalette_CreateObject();
extern const char DAT_01095b60[];  // NiTextKeyExtraData
void NiTextKeyExtraData_CreateObject();
extern const char DAT_01095b40[];  // NiTextureTransformController
void NiTextureTransformController_CreateObject();
extern const char DAT_01095b28[];  // NiTransformController
void NiTransformController_CreateObject();
extern const char DAT_01095b18[];  // NiTransformData
void FUN_00a4e040();
extern const char DAT_01095b00[];  // NiTransformInterpolator
void NiTransformInterpolator_CreateObject();
extern const char DAT_01095af0[];  // NiUVController
void NiUVController_CreateObject();
extern const char DAT_01095ae4[];  // NiUVData
void CreateControllerAllocation();
extern const char DAT_01095ad4[];  // NiVisController
void NiVisController_CreateObject();
extern const char DAT_01095ac8[];  // BSAnimNotes
void BSAnimNotes_CreateObject();
extern const char DAT_01095ab8[];  // BSGrabIKNote
void BSGrabIKNote_CreateObject();
extern const char DAT_01095aa8[];  // BSLookIKNote
void CreateLookIKNote();
extern const char DAT_01095a88[];  // BSRotAccumTransfInterpolator
void CreateRotAccumTransfInterpolator();
extern const char DAT_01095a6c[];  // BSTreadTransfInterpolator
void CreateDerivedA43370();
extern const char DAT_01095a4c[];  // BSBlendTreadTransfInterpolator
void BSBlendTreadTransfInterpolator_CreateObject();
extern const char DAT_01095a28[];  // BSMultiTargetTreadTransfController
void BSMultiTargetTreadTransfController_CreateObject();
extern const char DAT_01095a10[];  // BSFrustumFOVController
void BSFrustumFOVController_CreateObject();
extern const char DAT_01095a04[];  // NiVisData
void NiBoolData_CreateObject();
// @fnv 0x00a2d8a0
// src: COMMUNITY 0x00a2d8a0
void NiAnimationSDM_Init()
{
    if (!DAT_011f369d)
    {
        DAT_011f369d = true;
        FUN_00a64900(DAT_01096060, CreateFloatInterpController);
        FUN_00a64900(DAT_0109603c, NiBlendAccumTransformInterpolator_CreateObject);
        FUN_00a64900(DAT_01096024, NiBlendBoolInterpolator_CreateObject);
        FUN_00a64900(DAT_01096008, CreateBlendColorInterpolator);
        FUN_00a64900(DAT_01095fec, CreateNiBlendFloatInterpolator);
        FUN_00a64900(DAT_01095fd0, NiBlendPoint3Interpolator_CreateObject);
        FUN_00a64900(DAT_01095fb0, NiBlendQuaternionInterpolator_CreateObject);
        FUN_00a64900(DAT_01095f90, NiBlendTransformInterpolator_CreateObject);
        FUN_00a64900(DAT_01095f7c, CreateBoneLODController);
        FUN_00a64900(DAT_01095f70, NiBoolData_CreateObject);
        FUN_00a64900(DAT_01095f5c, CreateNiKeyBasedInterpolator);
        FUN_00a64900(DAT_01095f40, CreateBoolInterpolator);
        FUN_00a64900(DAT_01095f2c, CreateNiSplineImpl);
        FUN_00a64900(DAT_01095f1c, NiBSplineData_CreateObject);
        FUN_00a64900(DAT_01095f00, NiBSplineColorInterpolator_CreateObject);
        FUN_00a64900(DAT_01095ee0, CreateSplineCompColorInterpolator);
        FUN_00a64900(DAT_01095ec0, NiBSplineCompFloatInterpolator_CreateObject);
        FUN_00a64900(DAT_01095ea0, CreateComp4);
        FUN_00a64900(DAT_01095e7c, CreateEvaluator);
        FUN_00a64900(DAT_01095e60, NiBSplineFloatInterpolator_CreateObject);
        FUN_00a64900(DAT_01095e44, NiBSplinePoint3Interpolator_CreateObject);
        FUN_00a64900(DAT_01095e24, NiBSplineTransformInterpolator_CreateObject);
        FUN_00a64900(DAT_01095e18, CreateNiColorData);
        FUN_00a64900(DAT_01095dfc, NiColorExtraDataController_CreateObject);
        FUN_00a64900(DAT_01095de8, NiColorInterpolator_CreateObject);
        FUN_00a64900(DAT_01095dd4, NiControllerManager_CreateObject);
        FUN_00a64900(DAT_01095dbc, NiControllerSequence_CreateObject);
        FUN_00a64900(DAT_01095da8, CreateNiFlipController);
        FUN_00a64900(DAT_01095d9c, CreateNiFloatData);
        FUN_00a64900(DAT_01095d80, NiFloatExtraDataController_CreateObject);
        FUN_00a64900(DAT_01095d6c, CreateNiFloatInterpolator);
        FUN_00a64900(DAT_01095d50, NiFloatsExtraDataController_CreateObject);
        FUN_00a64900(DAT_01095d2c, NiFloatsExtraDataPoint3Controller_CreateObject);
        FUN_00a64900(DAT_01095d14, NiGeomMorpherController_CreateObject);
        FUN_00a64900(DAT_01095cfc, NiTransformController_CreateObject);
        FUN_00a64900(DAT_01095cec, FUN_00a4e040);
        FUN_00a64900(DAT_01095cd8, NiKeyframeManager_CreateObject);
        FUN_00a64900(DAT_01095cc0, NiLightColorController_CreateObject);
        FUN_00a64900(DAT_01095ca8, NiLightDimmerController_CreateObject);
        FUN_00a64900(DAT_01095c94, CreateMorphData);
        FUN_00a64900(DAT_01095c7c, NiLookAtInterpolator_CreateObject);
        FUN_00a64900(DAT_01095c60, NiMaterialColorController_CreateObject);
        FUN_00a64900(DAT_01095c54, CreateA51BF0);
        FUN_00a64900(DAT_01095c30, CreateCtl);
        FUN_00a64900(DAT_01095c1c, NiPathController_CreateObject);
        FUN_00a64900(DAT_01095c08, CreateA51BF0Base);
        FUN_00a64900(DAT_01095bf0, NiPoint3Interpolator_CreateObject);
        FUN_00a64900(DAT_01095be4, NiPosData_CreateObject);
        FUN_00a64900(DAT_01095bc8, CreateNiQuaternionInterpolator);
        FUN_00a64900(DAT_01095bb4, NiRollController_CreateObject);
        FUN_00a64900(DAT_01095ba8, NiRotData_CreateObject);
        FUN_00a64900(DAT_01095b9c, NiSequence_CreateObject);
        FUN_00a64900(DAT_01095b84, NiSequenceStreamHelper_CreateObject);
        FUN_00a64900(DAT_01095b74, NiStringPalette_CreateObject);
        FUN_00a64900(DAT_01095b60, NiTextKeyExtraData_CreateObject);
        FUN_00a64900(DAT_01095b40, NiTextureTransformController_CreateObject);
        FUN_00a64900(DAT_01095b28, NiTransformController_CreateObject);
        FUN_00a64900(DAT_01095b18, FUN_00a4e040);
        FUN_00a64900(DAT_01095b00, NiTransformInterpolator_CreateObject);
        FUN_00a64900(DAT_01095af0, NiUVController_CreateObject);
        FUN_00a64900(DAT_01095ae4, CreateControllerAllocation);
        FUN_00a64900(DAT_01095ad4, NiVisController_CreateObject);
        FUN_00a64900(DAT_01095ac8, BSAnimNotes_CreateObject);
        FUN_00a64900(DAT_01095ab8, BSGrabIKNote_CreateObject);
        FUN_00a64900(DAT_01095aa8, CreateLookIKNote);
        FUN_00a64900(DAT_01095a88, CreateRotAccumTransfInterpolator);
        FUN_00a64900(DAT_01095a6c, CreateDerivedA43370);
        FUN_00a64900(DAT_01095a4c, BSBlendTreadTransfInterpolator_CreateObject);
        FUN_00a64900(DAT_01095a28, BSMultiTargetTreadTransfController_CreateObject);
        FUN_00a64900(DAT_01095a10, BSFrustumFOVController_CreateObject);
        FUN_00a64900(DAT_01095a04, NiBoolData_CreateObject);
        FUN_00a64920(NiOldAnimationConverter_Convert);
        FUN_00a421c0();
    }
}
