#include "../../../include/SettingT.h"
#include "../../../include/ImageSpaceTexture.h"
// fallout/misc/main.cpp: Interface, SomeClass, BSFadeNodeCuller, Mover and more (193 functions)
#include "main.h"
#include "../../../include/BSFogProperty.h"
#include "../../../include/BSRenderedTexture.h"
// BSRenderStateManager_main: local type (was include/BSRenderStateManager.h, which had no evidence of one real class); its methods are 0x00b97fa0 BSRenderState::SetAlphaBlendEnable, 0x00b98380 BSRenderState::SetColorWriteEnable
#include "../../../include/BSRENDERSTATE_LOCK.h"
#include "../../../include/SETTING_VALUE.h"
#include "../../../include/InterfaceManager.h"
#include "../../../include/ProcessLists.h"

class BSRenderStateManager_main
{
public:
    static void __cdecl SetDepthBufferEnabled(bool, BSRENDERSTATE_LOCK);
    static void __cdecl SetDepthBufferEnabled(bool, int);
    static void __cdecl SetColorWriteMask(unsigned int, BSRENDERSTATE_LOCK);
    static void __cdecl SetColorWriteMask(unsigned int, unsigned int);
};
// BSShaderRenderUtility_main: local type (was include/BSShaderRenderUtility.h, which had no evidence of one real class); its methods are 0x00469860 TESDataHandler::IsFormIDCreated, 0x00b6ba70 BSShaderUtil::InitSDM, 0x00b6bb30 BSShaderUtil::RecursiveSetPropertyFadeAlpha, 0x00b6c0d0 BSShaderUtil::RenderScene
class AnimIdle;
class BSShaderAccumulator;
class NiCamera;
class NiNode;

class BSShaderRenderUtility_main
{
public:
    bool IsRenderTargetId(unsigned int value);
    static void InitializeMultiBounds();
    static void SetRenderCamera(NiCamera* camera, BSShaderAccumulator* accumulator, bool unused);
    static void SetRenderCamera(AnimIdle* camera, AnimIdle* accumulator, bool unused);
    static void SetRenderCamera(void* camera, unsigned int accumulator, bool unused);
    static void SetAlphaOnNode(NiNode* node, float alpha);
};
#include "../../../include/BSTextureManager.h"
// InterfaceH_main: local type (was include/InterfaceH.h, which had no evidence of one real class); its methods are 0x00702360 Interface::IsInMenuMode, 0x00702450 Interface::IsTopMenuID, 0x00703860 HUDMainMenu::HandleHealthbarForCrosshairActor_, 0x00705e00 Interface::CreateLoadingMenu
class TESForm;
class TESObjectREFR;

class InterfaceH_main
{
public:
    static bool __cdecl GetSelectedTargetIndex(int);
    static void SetQuestTarget(TESForm*, bool);
    static void SetLookAtReference(TESObjectREFR*);
    static double GetFourthInterfaceFloat();
    static double GetThirdInterfaceFloat();
    static bool IsSaveLoadActive();
};
// MobileObjectCellAccess_main: local type (was include/MobileObjectCellAccess.h, which had no evidence of one real class); its methods are 0x004518e0 TESObjectCELL::HasWater
class MobileObjectCellAccess_main
{
public:
    bool FUN_004518e0() const;
};

#include <cstddef>
#include <cstring>
// The shared classes (one world: main.h no longer reads the old include/ chain).
#include "../../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
// include/MagicTarget.h and MagicCaster.h are the shared headers, already read by main.h
#include "../../../include/BSSimpleList.h"
#include "../../../include/NiPoint2.h"
#include "../../../include/NiMatrix3.h"
#include "../../../include/NiFixedString.h"
#include "../../../include/NiObject.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiTexture.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/MiddleLowProcess.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/GameTimerRecord.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/FORenderedMenu.h"
#include "../../../include/FOPipboyManager.h"
#include "../../../include/ShadowSceneNode.h"
#include "../../../include/TESWaterSystem.h"
#include "../../../include/Sky.h"
#include "../../../include/StartMenu.h"
#include "../../../include/BSFadeNodeCuller.h"
#include "../../../include/BGSBodyPart.h"
#include "../../../include/BSFaceGenAnimationData.h"
#include "../../../include/BSFaceGenNiNode.h"
#include "../../../include/BSShaderAccumulator.h"
#include "../../../include/GO.h"
#include "../../../include/HotkeyWheelDisplay.h"
#include "../../../include/ImageSpaceManager.h"
#include "../../../include/NiRenderer.h"
#include "../../../include/NiDX9Renderer.h"
#include "../../../include/NiScreenElementsData.h"
#include "../../../include/TES.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/ShadowSceneLight.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/AutoMemHelper.h"
#include "../../../include/BSCullingProcess.h"
#include "../../../include/DebugText.h"
#include "../../../include/LoveTesterMenu.h"
#include "../../../include/Menu.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/SPECIALBookMenu.h"
#include "../../../include/TESWorldSpace.h"
#include "../../../include/Tile.h"
#include "../../../include/BGSCameraPath.h"
#include "../../../include/BSAudio.h"
#include "../../../include/BSShaderManager.h"
#include "../../../include/BSSystemUtility.h"
#include "../../../include/FalloutRadio.h"
#include "../../../include/NiAdditionalGeometryData.h"
#include "../../../include/NiGeometry.h"
#include "../../../include/NiColorA.h"
#include "../../../include/TESGrass.h"
#include "../../../include/TESNPC.h"
#include "../../../include/Actor.h"
#include "../../../include/Setting.h"
#include "../../../include/Sun.h"


extern int DAT_011c70cc;

// @fnv 0x004dc310
// src: COMMUNITY 0x004dc310
bool __cdecl TESRenderer_GetMultiSampleEnabled()
{
    return DAT_011c70cc >= 2;
}

extern NiPointer<NiNode> g_011dee84;

// Creates a new SceneGraph named "Menu" and stores it in the global NiPointer g_011dee84.
// @fnv 0x004dc5c0
// src: COMMUNITY 0x004dc5c0
void TESMain_CreateMenuRootNode()
{
    g_011dee84 = reinterpret_cast<NiNode*>(new SceneGraph("Menu", true, 0));
}

struct Node
{
    char pad[8];
    int v;
};
struct FUN_004ed8c0_shell
{
    Node* NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_NewItem();
    void NiTListBase_NiTPointerAllocator_unsigned_int_BSFaceGenKeyframe_AddNodeTail(Node*);
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(int* e);
};
// Gets a Node via FUN_0049fa80, stores the int pointed to by e into its v field, then passes the node to FUN_00559a70.
// @fnv 0x004ed8c0
// src: XBOX_PDB 0x004ed8c0
void FUN_004ed8c0_shell::NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(int* piValue)
{
    Node* n = NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_NewItem();
    n->v = *piValue;
    NiTListBase_NiTPointerAllocator_unsigned_int_BSFaceGenKeyframe_AddNodeTail(n);
}

struct BGSAddonNode;
struct Arr86
{
    void SetAt(unsigned int, BGSAddonNode*&);
};
struct Idx86
{
    unsigned int ForwardCall_00877a50(unsigned int&);
};
struct S86
{
    char p[0xad4];
    Idx86 i;
    char q[0xae4 - 0xad5];
    Arr86 a;
    unsigned int NiDX9Renderer_AddResetNotificationFunc(unsigned int key, BGSAddonNode* node);
};
// @fnv 0x0086bae0
// src: COMMUNITY 0x0086bae0
unsigned int S86::NiDX9Renderer_AddResetNotificationFunc(unsigned int key, BGSAddonNode* node)
{
    unsigned int idx = i.ForwardCall_00877a50(key);
    a.SetAt(idx, node);
    return idx;
}

class BGSAddonNode;
namespace fnv_0086bbd0 {
struct Arr86
{
    void SetAt(unsigned int, BGSAddonNode*&);
};
struct Idx86
{
    unsigned int ForwardCall_00877a50(unsigned int&);
};
struct S86b
{
    char p[0xaf4];
    Idx86 i;
    char q[0xb04 - 0xaf5];
    Arr86 a;
    unsigned int NiDX9Renderer_AddLostDeviceNotificationFunc(unsigned int key, BGSAddonNode* node);
};
// @fnv 0x0086bbd0
// src: COMMUNITY 0x0086bbd0
unsigned int S86b::NiDX9Renderer_AddLostDeviceNotificationFunc(unsigned int key, BGSAddonNode* node)
{
    unsigned int idx = i.ForwardCall_00877a50(key);
    a.SetAt(idx, node);
    return idx;
}
}  // namespace fnv_0086bbd0

struct Dummy_0086bce0
{
    void FileFinder_AddPath(int);
};
extern Dummy_0086bce0* _g_fileFinder;

// @fnv 0x0086bce0
// src: COMMUNITY 0x0086bce0
void __cdecl FileFinder_AddPath_0(int aiValue)
{
    if (_g_fileFinder)
        _g_fileFinder->FileFinder_AddPath(aiValue);
}

void __cdecl BSSearchPath_GetBSSearchPath();
void __cdecl NiSearchPath_SetSearchPathCreateCallback(void(__cdecl*)());

// @fnv 0x0086bd70
// src: COMMUNITY 0x0086bd70
void __cdecl BSSearchPath_InitCallback()
{
    NiSearchPath_SetSearchPathCreateCallback(BSSearchPath_GetBSSearchPath);
}

// @fnv 0x0086bda0
// src: GUESS 0x0086bda0 (confidence: low)
void __fastcall Object_AdvanceStateAtOffset5C_0086bda0(int param_1)
{
    if (*(int*)(param_1 + 0x5c) == 1 || *(int*)(param_1 + 0x5c) == 2)
    {
        *(int*)(param_1 + 0x5c) = 3;
    }
}

class BGSLoadGameBuffer;

// Interface's debug print as this unit spells its argument (the shared Interface is include/Menu.h's)
class InterfaceDebug
{
  public:
    static void __cdecl PrintDebugMessage(BGSLoadGameBuffer*);
};


class GlobalObject_0044f440
{
  public:
    float FUN_00450410(void);
};

class GlobalObject_0045cf30
{
};

void __cdecl BSShaderManager_SetShaderErrorCallback(int);
void __cdecl BSShaderManager_CalculateTime();
void __cdecl BSShaderManager_SetTimerFunc(void(__cdecl*)());
void __cdecl BSShaderManager_SetUseHardDriveCache(unsigned char);

extern GlobalObject_0044f440 g_011deb70;
extern GlobalObject_0044f440 g_011dec18;
extern GlobalObject_0045cf30 g_011ded68;
extern GlobalObject_0045cf30 g_011deea8;

extern unsigned char DAT_011f9443;
extern float DAT_011f9480;
extern float DAT_011f9484;

// @fnv 0x0086bf70
// src: XBOX_PDB 0x0086bf70
void __cdecl Main_ShaderInit()
{
    InterfaceDebug::PrintDebugMessage((BGSLoadGameBuffer*)"Initializing Shader System...");
    BSShaderManager_SetShaderErrorCallback(0);
    BSShaderManager_SetTimerFunc(BSShaderManager_CalculateTime);
    BSShaderManager_SetUseHardDriveCache(*reinterpret_cast<ProcessLists*>(&g_011ded68)->GetLifeStateControlFlag());
    DAT_011f9443 = *reinterpret_cast<ProcessLists*>(&g_011deea8)->GetLifeStateControlFlag();
    DAT_011f9484 = g_011dec18.FUN_00450410();
    DAT_011f9480 = g_011deb70.FUN_00450410();
}

// The positional call passes three raw stack values; NiPoint3 preserves that value ABI.
void __fastcall SetReferencePosition(TESObjectREFR*, NiPoint3);

// @fnv 0x0086d490
void TESObjectREFR::SetLocationOnReference(const NiPoint3& arPoint)
{
    ::SetReferencePosition(this, reinterpret_cast<const NiPoint3&>(arPoint));
}

int __cdecl NiXAdapaterDesc_GetDeviceCaps(int, int);
const char* __cdecl Renderer_GetReason();
int __cdecl sprintf(char*, const char*, ...);
namespace main_win32 {
__declspec(dllimport) int __stdcall MessageBoxA(void*, const char*, const char*, unsigned int);
__declspec(dllimport) void __stdcall ExitProcess(unsigned int);
}  // namespace main_win32

// Calls FUN_004da670 with pThis[2] and pThis[3]; on failure formats an error message with FUN_0086d580, shows a MessageBoxA and calls ExitProcess(0).
// @fnv 0x0086d500
// src: COMMUNITY 0x0086d500
void __fastcall TESMain_InitRenderer(int* pThis)
{
    char buf[512];
    if (!NiXAdapaterDesc_GetDeviceCaps(pThis[2], pThis[3]))
    {
        sprintf(buf, "Failed to initialize renderer.\n%s", Renderer_GetReason());
        main_win32::MessageBoxA(0, buf, "Fallout", 0);
        main_win32::ExitProcess(0);
    }
}

class NiGeometryData;



struct FUN_0086e3f0_shell : public NiGeometry
{
    bool NiScreenElements_Insert(unsigned short usNumVertices, unsigned short usNumTriangles, int ausTriList);
};

// Forwards the vertex count, triangle count and triangle list to the geometry data's FUN_00a87ae0 and returns its result.
// @fnv 0x0086e3f0
// src: COMMUNITY 0x0086e3f0
bool FUN_0086e3f0_shell::NiScreenElements_Insert(unsigned short usNumVertices, unsigned short usNumTriangles, int ausTriList)
{
    return ((NiScreenElementsData*)GetModelData())->FUN_00a87ae0(usNumVertices, usNumTriangles, ausTriList);
}

class NiGeometryData;
namespace fnv_0086e420 {
using ::NiGeometry;
using ::NiScreenElementsData;
struct FUN_0086e420_shell : NiGeometry
{
    void NiScreenElements_SetRectangle(int a, float b, float c, float d, float e);
};
// @fnv 0x0086e420
// src: COMMUNITY 0x0086e420
void FUN_0086e420_shell::NiScreenElements_SetRectangle(int a, float b, float c, float d, float e)
{
    ((NiScreenElementsData*)GetModelData())->SetRectangleBounds(a, b, c, d, e);
}
}  // namespace fnv_0086e420

namespace fnv_0086e460 {
using ::NiScreenElementsData;
using ::NiGeometry;
struct FUN_0086e460_shell : public NiGeometry
{
    bool NiScreenElements_SetTextures(int, unsigned short, float, float, float, float);
};
// Forwards the polygon, set and rectangle coordinates to the screen elements data returned by FUN_005495f0 and returns its result.
// @fnv 0x0086e460
// src: COMMUNITY 0x0086e460
bool FUN_0086e460_shell::NiScreenElements_SetTextures(int iPolygon, unsigned short usSet, float fLeft, float fTop, float fRight,
                                      float fBottom)
{
    return ((NiScreenElementsData*)GetModelData())->SetRectangleBounds(iPolygon, usSet, fLeft, fTop, fRight, fBottom);
}
}  // namespace fnv_0086e460

class NiGeometryData;
namespace fnv_0086e4b0 {

using ::NiGeometry;

using ::NiScreenElementsData;

// @fnv 0x0086e4b0
// src: COMMUNITY 0x0086e4b0
void __fastcall NiScreenElements_UpdateBound(NiGeometry* apGeometry)
{
    ((NiScreenElementsData*)apGeometry->GetModelData())->NiScreenElementsData_UpdateBound();
}
}  // namespace fnv_0086e4b0

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};

extern char DAT_011f9308[];

// @fnv 0x0086e4e0
// src: COMMUNITY 0x0086e4e0
void __cdecl BSShaderManager_SetDefaultShaderPath(const char* apPath)
{
    TaskQueueInterface::CopyStringToBuffer(DAT_011f9308, 0x104, apPath);
}

extern NiPointer<NiNode> DAT_011f9508;

// @fnv 0x0086e520
// src: COMMUNITY 0x0086e520
void __cdecl BSShaderManager_SetRenderer(NiNode* apRenderer)
{
    DAT_011f9508 = apRenderer;
}

namespace fnv_0086e540 {
// 0x00408d60 is a folded byte-pointer getter (also ProcessLists::GetLifeStateControlFlag, Setting::FUN_00408d60); the global read here is not the ProcessLists singleton 0x011e0e80
class FlagGetterView
{
  public:
    unsigned char* GetLifeStateControlFlag();
};

extern FlagGetterView g_011c7154;

// @fnv 0x0086e540
// src: COMMUNITY 0x0086e540
unsigned char Display_bDoAmbientPass_Get()
{
    return *g_011c7154.GetLifeStateControlFlag();
}
}  // namespace fnv_0086e540

namespace fnv_0086e560 {
// 0x00408d60 is a folded byte-pointer getter (also ProcessLists::GetLifeStateControlFlag, Setting::FUN_00408d60); the global read here is not the ProcessLists singleton 0x011e0e80
class FlagGetterView
{
  public:
    unsigned char* GetLifeStateControlFlag();
};

extern FlagGetterView g_011c7544;

// @fnv 0x0086e560
// src: COMMUNITY 0x0086e560
unsigned char Display_bDoDiffusePass_Get()
{
    return *g_011c7544.GetLifeStateControlFlag();
}
}  // namespace fnv_0086e560

namespace fnv_0086e580 {
// 0x00408d60 is a folded byte-pointer getter (also ProcessLists::GetLifeStateControlFlag, Setting::FUN_00408d60); the global read here is not the ProcessLists singleton 0x011e0e80
struct FlagGetterView
{
    unsigned char* GetLifeStateControlFlag();
};

extern FlagGetterView g_011c712c;

// @fnv 0x0086e580
// src: COMMUNITY 0x0086e580
unsigned char Display_bDoSpecularPass_Get()
{
    return *g_011c712c.GetLifeStateControlFlag();
}
}  // namespace fnv_0086e580

namespace fnv_0086e5a0 {
// 0x00408d60 is a folded byte-pointer getter (also ProcessLists::GetLifeStateControlFlag, Setting::FUN_00408d60); the global read here is not the ProcessLists singleton 0x011e0e80
class FlagGetterView
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};

extern FlagGetterView g_011c7180;

// @fnv 0x0086e5a0
// src: COMMUNITY 0x0086e5a0
unsigned char Display_bDoTexturePass_Get()
{
    return *g_011c7180.GetLifeStateControlFlag();
}
}  // namespace fnv_0086e5a0

namespace fnv_0086e5c0 {
// 0x00408d60 is a folded byte-pointer getter (also ProcessLists::GetLifeStateControlFlag, Setting::FUN_00408d60); the global read here is not the ProcessLists singleton 0x011e0e80
class FlagGetterView
{
  public:
    unsigned char* GetLifeStateControlFlag();
};
extern FlagGetterView g_011c7368;

// @fnv 0x0086e5c0
// src: COMMUNITY 0x0086e5c0
unsigned char TESRenderer_GetDoActorShadows()
{
    return *g_011c7368.GetLifeStateControlFlag();
}
}  // namespace fnv_0086e5c0

namespace fnv_0086e5e0 {
// 0x00408d60 is a folded byte-pointer getter (also ProcessLists::GetLifeStateControlFlag, Setting::FUN_00408d60); the global read here is not the ProcessLists singleton 0x011e0e80
class FlagGetterView
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};
extern FlagGetterView g_011c7380;

// @fnv 0x0086e5e0
// src: COMMUNITY 0x0086e5e0
unsigned char TESRenderer_GetDoStaticAndArchShadows()
{
    return *g_011c7380.GetLifeStateControlFlag();
}
}  // namespace fnv_0086e5e0

namespace fnv_0086e600 {
// 0x00408d60 is a folded byte-pointer getter (also ProcessLists::GetLifeStateControlFlag, Setting::FUN_00408d60); the global read here is not the ProcessLists singleton 0x011e0e80
struct FlagGetterView
{
    unsigned char* GetLifeStateControlFlag();
};

extern FlagGetterView g_011c7550;

// @fnv 0x0086e600
// src: COMMUNITY 0x0086e600
unsigned char TESRenderer_GetDoStaticMenuBackground()
{
    return *g_011c7550.GetLifeStateControlFlag();
}
}  // namespace fnv_0086e600

extern NiPointer<NiNode> g_011d86bc;

// @fnv 0x0086e630
// src: COMMUNITY 0x0086e630
void BGSTerrainManager_SetTreeNode(NiNode* apTreeNode)
{
    g_011d86bc = apTreeNode;
}

extern int DAT_011f9138;

// @fnv 0x0086ef40
// src: COMMUNITY 0x0086ef40
void BSFadeNode_IncFadeCounter()
{
    DAT_011f9138 = DAT_011f9138 + 1;
}


extern StartMenu* DAT_011daac0;

// @fnv 0x0086efa0
// src: COMMUNITY 0x0086efa0
bool StartMenu_CreditsMenuIsActive()
{
    return DAT_011daac0 && DAT_011daac0->IsFlagSet((StartMenu::Flag)0x10000);
}

namespace fnv_0086f260 {
struct TG
{
};
struct PL
{
    unsigned char* GetLifeStateControlFlag();
};
struct GlobalA
{
};
struct SetA
{
    float* Float();
};
using ::BGSLoadFormBuffer;
using ::GameTimerRecord;
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
using ::TESObjectREFR;
extern TG g_timeGlobal;
extern PL g_011dedbc;
extern SetA g_011c5724;
extern SetA originalRuntimeFloatSetting807;
extern bool DAT_011dea2b;
extern float DAT_011afe60;
extern float DAT_011dea30;
unsigned int __fastcall ReferenceFlags(TESObjectREFR*);
extern TESObjectREFR DAT_011f2250;
void __cdecl FUN_00aa4e40();
bool __cdecl Main_GetSceneIsComplex();
void __cdecl bhkWorld_SetDeltaTime(float, bool, bool);
void __cdecl BSShaderManager_UpdateTimers();
struct Mover
{
    void TESMain_OnIdle_UpdateTimer();
};
// @fnv 0x0086f260
// src: COMMUNITY 0x0086f260
void Mover::TESMain_OnIdle_UpdateTimer()
{
    ((BGSLoadFormBuffer*)&g_timeGlobal)->SetVersion(*g_011dedbc.GetLifeStateControlFlag());
    if (!DAT_011dea2b)
        FUN_00aa4e40();
    ((GameTimerRecord*)&g_timeGlobal)->Update();
    DAT_011afe60 = *originalRuntimeFloatSetting807.Float();
    bhkWorld_SetDeltaTime(((Twin_0084d030*)&g_timeGlobal)->GetStoredFloatValue(), Main_GetSceneIsComplex(), ReferenceFlags(&DAT_011f2250) == 4);
    BSShaderManager_UpdateTimers();
    DAT_011dea30 =
        (float)(DAT_011dea2b ? 0.0 : ((Twin_0084d030*)&g_timeGlobal)->GetStoredFloatValue() * *g_011c5724.Float());
}
}  // namespace fnv_0086f260

extern float(__cdecl* DAT_011f91f0)(int);
extern float DAT_011f940c[4];

// Fills the four-element DAT_011f940c array by calling DAT_011f91f0 for each index, or storing 0.0f when the function pointer is null.
// @fnv 0x0086f330
// src: COMMUNITY 0x0086f330
void BSShaderManager_UpdateTimers()
{
    for (int i = 0; i < 4; i++)
    {
        DAT_011f940c[i] = DAT_011f91f0 ? DAT_011f91f0(i) : 0.0f;
    }
}

namespace fnv_0086f390 {
bool __fastcall PlayerCheck_007d1360(::PlayerCharacter*);
struct FUN_0086f390_shell : public Main
{
    void TESMain_OnIdle_PollControls();
};

using ::PlayerCharacter;
using ::TESObjectREFR;
struct TimeGlobal
{
    float GetSecondsPassed();
};
// Exe 0x0086f390: unit-local Interface view; declarations and layout are preserved.
struct MainInterfaceView
{
    enum enumMenus
    {
        MENU_DUMMY
    };
    static bool IsMenuActive(enumMenus, unsigned int);
};
using ::HotkeyWheelDisplay;
void __fastcall PollHotkeys_00a23010(HotkeyWheelDisplay*);
void __fastcall UpdateHotkeys_00a257c0(HotkeyWheelDisplay*, float);
void __fastcall ClearHotkeys_00a253d0(HotkeyWheelDisplay*);
extern PlayerCharacter* pPlayer;
unsigned int __fastcall ReferenceFlags(TESObjectREFR*);
extern TESObjectREFR DAT_011f2250;
extern TimeGlobal g_timeGlobal;
HotkeyWheelDisplay* __cdecl Controls_GetInstance();
bool __cdecl Interface_IsPipboyOpening();
// @fnv 0x0086f390
// src: COMMUNITY 0x0086f390
void FUN_0086f390_shell::TESMain_OnIdle_PollControls()
{
    PollHotkeys_00a23010(Controls_GetInstance());
    UpdateHotkeys_00a257c0(Controls_GetInstance(), g_timeGlobal.GetSecondsPassed());
    if (!*((unsigned char*)this + 6) && !pPlayer->HasHealth(false))
    {
        if ((ReferenceFlags(&DAT_011f2250) == 4 && !PlayerCheck_007d1360(pPlayer)) || Interface_IsPipboyOpening())
        {
            if (!MainInterfaceView::IsMenuActive((MainInterfaceView::enumMenus)0x3e9, 0) && !PlayerCharacter::UpdatePlayerStatus())
                ClearHotkeys_00a253d0(Controls_GetInstance());
        }
    }
}
}  // namespace fnv_0086f390

struct FUN_0086f640_shell : public Main
{
    void TESMain_OnIdle_UpdateAudio();
};



class FalloutAudioMedia
{
  public:
    static void __cdecl Update();
};

class SoundPlaybackManager
{
  public:
    static void __cdecl ProcessPendingSounds();
};

// @fnv 0x0086f640
// src: COMMUNITY 0x0086f640
void FUN_0086f640_shell::TESMain_OnIdle_UpdateAudio()
{
    ::BSAudio::GetSingleton()->Update(true);
    FalloutRadio::Update(false);
    FalloutAudioMedia::Update();
    SoundPlaybackManager::ProcessPendingSounds();
}

struct FUN_0086f670_shell : public Main
{
    void Main_RunScripts();
};

extern unsigned char DAT_012682f8;
extern unsigned char DAT_011df678;
extern unsigned char DAT_011dea2a;
extern TES* g_TES;

void __cdecl Script_ClearCachedValues();
void __fastcall TES_RunScripts(TES* pTES);

// @fnv 0x0086f670
// src: XBOX_PDB 0x0086f670
void FUN_0086f670_shell::Main_RunScripts()
{
    DAT_012682f8 = 0;
    DAT_011df678 = 0;
    DAT_011dea2a = 0;
    Script_ClearCachedValues();
    TES_RunScripts(g_TES);
}

// @fnv 0x0086f840
// src: XBOX_PDB 0x0086f840
bool __fastcall FOPipboyManager_GetPipBoyManagerReset(char* pThis)
{
    return *(bool*)(pThis + 0x16c);
}

extern bool* DAT_011d9510;

// Returns the byte at offset 0x131 of the object pointed to by DAT_011d9510, or false if that pointer is null.
// @fnv 0x0086f860
// src: XBOX_PDB 0x0086f860
bool DialogMenu_GetPaused()
{
    return DAT_011d9510 ? DAT_011d9510[0x131] : false;
}

struct FUN_0086f890_shell : public Main
{
    void Main_OnIdle_UpdateProcessLists();
};

struct GlobalObject2_0040c150
{
    int* Int(void);
};

extern GlobalObject2_0040c150 g_011c3ea4;
extern bool DAT_011dea2b;
extern bool DAT_011dea2d;
extern bool DAT_011dea2e;
extern PlayerCharacter* pPlayer;
extern int DAT_011e0e80;
extern int DAT_011e0fe0;
extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;

void __fastcall ProcessLists_ChangeProcessLevelTempList(void* pThis);
void __fastcall AITaskManager_UpdateTasks(void* pThis);
void __fastcall CombatManager_UpdateCombatants(void* pThis);
void __fastcall ProcessLists_UpdateProcessLists(void* pThis);
void __fastcall PlayerCharacter_UpdateAutoAimActor(void* pThis);

// @fnv 0x0086f890
// src: XBOX_PDB 0x0086f890
void FUN_0086f890_shell::Main_OnIdle_UpdateProcessLists()
{
    if (*g_011c3ea4.Int() == 1)
    {
        ProcessLists_ChangeProcessLevelTempList(&DAT_011e0e80);
    }

    if ((!DAT_011dea2b || DAT_011dea2d) && !DAT_011dea2e && !((unsigned char*)this)[7])
    {
        if (*g_011c3ea4.Int() == 1)
        {
            AITaskManager_UpdateTasks(&DAT_011e0fe0);
            CombatManager_UpdateCombatants(BGSSaveLoadGlobalDataWorldspacePtr);
        }
        ProcessLists_UpdateProcessLists(&DAT_011e0e80);
    }
    else if (DAT_011dea2b || ((unsigned char*)this)[7])
    {
        PlayerCharacter_UpdateAutoAimActor(pPlayer);
    }
}

void __cdecl Interface_PreIdleStuff();
void __cdecl Interface_Idle();
void __cdecl Interface_PostIdleStuff();

// @fnv 0x0086fd70
// src: COMMUNITY 0x0086fd70
void __fastcall TESMain_OnIdle_DoInterfaceIdle(void* pThis)
{
    Interface_PreIdleStuff();
    Interface_Idle();
    Interface_PostIdleStuff();
}

extern float DAT_011c96fc;

// @fnv 0x0086ff50
// src: COMMUNITY 0x0086ff50
void __cdecl TESImageSpaceModifier_AdvanceCurrentTime(float afDelta)
{
    DAT_011c96fc += afDelta;
}

namespace fnv_008705d0 {
struct GlobalObject2_0040c150
{
    int* Int();
};

extern GlobalObject2_0040c150 g_011c3ea4;

void __fastcall TESMain_OnIdle_UpdateAudio(void* pThis);
void __fastcall Main_OnIdle_UpdateProcessLists(void* pThis);
void __cdecl TESObjectCELL_RunQueuedParticleUpdates();
void __fastcall Main_RunScripts(void* pThis);

// Calls FUN_0086f640, FUN_0086f890, then FUN_00552570 if *g_011c3ea4.Int() > 1, and finally FUN_0086f670 on pThis.
// @fnv 0x008705d0
// src: COMMUNITY 0x008705d0
void __fastcall TESMain_PostSwapProcess(void* pThis)
{
    TESMain_OnIdle_UpdateAudio(pThis);
    Main_OnIdle_UpdateProcessLists(pThis);
    if (*g_011c3ea4.Int() > 1)
    {
        TESObjectCELL_RunQueuedParticleUpdates();
    }
    Main_RunScripts(pThis);
}
}  // namespace fnv_008705d0

namespace fnv_00870610 {
struct FUN_00870610_shell : public Main
{
    void TESMain_OnIdle_PostThreadsProcess();
};

class GlobalObject2_0040c150
{
  public:
    int* Int(void);
};

class TaskQueueInterface
{
  public:
    static TaskQueueInterface* __cdecl GetSingleton(void);
    void ProcessTaskQueue(void);
};

using ::DebugText;

extern GlobalObject2_0040c150 g_011c3ea4;

void* __cdecl InterfaceManager_GetSingleton(void);
void __cdecl Script_RunDelayedScriptActionsOnReferences(void);
void __cdecl Interface_HandleQueuedMenuOpen(void);
void __fastcall InterfaceManager_UpdateQueuedMenuClosings(void*);
void __fastcall TaskQueueInterface_ThreadBeginSecondaryInput(TaskQueueInterface*);
void __fastcall TaskQueueInterface_ThreadEndSecondaryInput(TaskQueueInterface*);
void __fastcall DebugText_HandleQueuedPrints(DebugText*);

// @fnv 0x00870610
// src: COMMUNITY 0x00870610
void FUN_00870610_shell::TESMain_OnIdle_PostThreadsProcess()
{
    Script_RunDelayedScriptActionsOnReferences();
    if (*g_011c3ea4.Int() > 1)
    {
        TaskQueueInterface_ThreadEndSecondaryInput(TaskQueueInterface::GetSingleton());
        TaskQueueInterface::GetSingleton()->ProcessTaskQueue();
        TaskQueueInterface_ThreadBeginSecondaryInput(TaskQueueInterface::GetSingleton());
    }
    Interface_HandleQueuedMenuOpen();
    InterfaceManager_UpdateQueuedMenuClosings(InterfaceManager_GetSingleton());
    DebugText_HandleQueuedPrints(DebugText::Instance(true));
}
}  // namespace fnv_00870610

void __cdecl Interface_CloseAllSupportMenus(int);

// If the byte at offset 0x4cc is set, calls FUN_00706320(0) and clears that byte.
// @fnv 0x00870680
// src: COMMUNITY 0x00870680
void __fastcall InterfaceManager_UpdateQueuedMenuClosings(int param_1)
{
    if (*(unsigned char*)(param_1 + 0x4cc))
    {
        Interface_CloseAllSupportMenus(0);
        *(unsigned char*)(param_1 + 0x4cc) = 0;
    }
}

namespace fnv_008706b0 {
bool __fastcall GetWireframe(::ShadowSceneNode*);
struct FUN_008706b0_shell : public Main
{
    void Main_DrawWorld(BSRenderedTexture*, bool, bool);
};

using ::NiPoint3;
using ::ShadowSceneNode;
void __fastcall SetEyePosition(::ShadowSceneNode*, NiPoint3);
const NiPoint3& __fastcall AnimationPosition_0045bb80(::BSFaceGenAnimationData*);
using ::NiNode;
using ::BSFaceGenAnimationData;
using ::BSFaceGenNiNode;
using ::NiAdditionalGeometryData;
// Exe 0x008706b0: unit-local Interface view; declarations and layout are preserved.
struct MainInterfaceView
{
    enum enumMenus
    {
        MENU_DUMMY
    };
    static bool IsMenuActive(enumMenus, unsigned int);
};
// Main rendering methods at 0x008707c0/0x00870a00/0x00870bd0; include/Main.h is not available yet.
struct MainStub
{
    void TESMain_DrawWorldRenderedMenu(BSRenderedTexture*, bool);
    void Main_DrawWorldWireframe(BSRenderedTexture*, bool);
    void TESMain_DrawWorldStandard(BSRenderedTexture*, bool);
};
BSFaceGenNiNode* __cdecl Main_GetWorldSceneGraph();
// @fnv 0x008706b0
// src: XBOX_PDB 0x008706b0
void FUN_008706b0_shell::Main_DrawWorld(BSRenderedTexture* pTexture, bool bCheckMenu, bool bFlag)
{
    bool f = GetWireframe(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0));
    SetEyePosition(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0),
        AnimationPosition_0045bb80(Main_GetWorldSceneGraph()->::BSFaceGenNiNode::GetAnimationData()));
    if (bCheckMenu && !MainInterfaceView::IsMenuActive((MainInterfaceView::enumMenus)0x3f5, 0))
        ((MainStub*)this)->TESMain_DrawWorldRenderedMenu(pTexture, f);
    else if (f)
        ((MainStub*)this)->Main_DrawWorldWireframe(pTexture, bFlag);
    else
        ((MainStub*)this)->TESMain_DrawWorldStandard(pTexture, bFlag);
}
}  // namespace fnv_008706b0

// @fnv 0x00870770
// src: COMMUNITY 0x00870770
bool __fastcall ShadowSceneNode_IsWireframe(const ::ShadowSceneNode* pThis)
{
    return pThis->bWireframe;
}

struct NiStream;
struct blob12
{
    char b[12];
};



// Stores aPosition into the pos field of the object at offset 0x1f0.
// @fnv 0x00870790
// src: COMMUNITY 0x00870790
void __fastcall ShadowSceneNode_SetEyePosition(::ShadowSceneNode* pThis, NiPoint3 aPosition)
{
    reinterpret_cast<NiPoint3&>(pThis->kEyePosition) = aPosition;
}

// Returns whether the float at offset 0x70 of pThis is greater than zero.
// @fnv 0x00871220
// src: COMMUNITY 0x00871220
bool __fastcall ImageSpaceEffectDepthOfField_DoDepth(char* pObject)
{
    return *(float*)(pObject + 0x70) > 0.0;
}

struct GO871
{
    operator ::NiNode*() const;
};
extern GO871 g_011c7810;
// Returns false if g_011c7810 is null, otherwise returns whether its FUN_00453470 result is greater than zero.
// @fnv 0x00871260
// src: COMMUNITY 0x00871260
bool ScreenCustomSplatter_IsActiveSplatter()
{
    if (!(::NiNode*)g_011c7810)
        return false;
    return ((::NiNode*)g_011c7810)->NiNode_GetChildCount() > 0;
}

namespace fnv_00871a10 {
// 0x00408d60 is a folded byte-pointer getter (also ProcessLists::GetLifeStateControlFlag, Setting::FUN_00408d60); the global read here is not the ProcessLists singleton 0x011e0e80
class FlagGetterView
{
  public:
    unsigned char* GetLifeStateControlFlag();
};

extern FlagGetterView g_011c74d4;

// @fnv 0x00871a10
// src: COMMUNITY 0x00871a10
unsigned char TESRenderer_GetDoShadows()
{
    return *g_011c74d4.GetLifeStateControlFlag();
}
}  // namespace fnv_00871a10

// @fnv 0x00871a30
// src: COMMUNITY 0x00871a30
int __fastcall TESDataHandler_GetFactions(int param_1)
{
    return param_1 + 0x88;
}

namespace fnv_00871c90 {
// 0x00408d60 is a folded byte-pointer getter (also ProcessLists::GetLifeStateControlFlag, Setting::FUN_00408d60); the global read here is not the ProcessLists singleton 0x011e0e80
struct FlagGetterView
{
    unsigned char* GetLifeStateControlFlag();
};
using ::HotkeyWheelDisplay;
void __fastcall PollHotkeys_00a23010(HotkeyWheelDisplay*);
using ::GameTimerRecord;
struct GlobalObject_0045cf30
{
};
struct TimeGlobal
{
};
extern GlobalObject_0045cf30 g_011deed8;
extern TimeGlobal g_timeGlobal;
HotkeyWheelDisplay* Controls_GetInstance();
void __fastcall Controls_ClearKeystrokes(HotkeyWheelDisplay*);
void __fastcall Controls_ClearUserActions(HotkeyWheelDisplay*);
void __fastcall BSTimer_Disable(TimeGlobal*);
struct FUN_00871c90_shell
{
    char pad[3];
    bool f;
    void TESMain_SetActive(bool b);
};
// @fnv 0x00871c90
// src: COMMUNITY 0x00871c90
void FUN_00871c90_shell::TESMain_SetActive(bool abEnabled)
{
    if (*((FlagGetterView*)&g_011deed8)->GetLifeStateControlFlag())
        abEnabled = 1;
    if (Controls_GetInstance())
    {
        Controls_ClearKeystrokes(Controls_GetInstance());
        PollHotkeys_00a23010(Controls_GetInstance());
        Controls_ClearUserActions(Controls_GetInstance());
    }
    if (abEnabled)
        ((GameTimerRecord*)&g_timeGlobal)->Enable();
    else
        BSTimer_Disable(&g_timeGlobal);
    f = abEnabled;
}
}  // namespace fnv_00871c90

struct O872
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual int vf();
};
struct H872
{
    int pad;
    operator O872*() const;
};
struct S872
{
    char p[0x30];
    H872 h[1];
    int BSRenderedTexture_GetWidth(unsigned int i);
};
// Returns the virtual call result of the element at index i, or 0 when that element is null.
// @fnv 0x00872370
// src: COMMUNITY 0x00872370
int S872::BSRenderedTexture_GetWidth(unsigned int uiIndex)
{
    return h[uiIndex] ? ((O872*)h[uiIndex])->vf() : 0;
}

namespace fnv_008723d0 {
struct O872
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual int vf();
};
struct H872
{
    int pad;
    operator O872*() const;
};
struct S872
{
    char p[0x30];
    H872 h[1];
    int BSRenderedTexture_GetHeight(unsigned int i);
};
// Returns the result of the virtual call on the object at index i, or 0 if that slot is null.
// @fnv 0x008723d0
// src: COMMUNITY 0x008723d0
int S872::BSRenderedTexture_GetHeight(unsigned int uiIndex)
{
    return h[uiIndex] ? ((O872*)h[uiIndex])->vf() : 0;
}
}  // namespace fnv_008723d0


// @fnv 0x00874460
void ::BSCullingProcess::SetCompoundFrustum(TaskArg1* apFrustum)
{
    unkC0 = reinterpret_cast<int>(apFrustum);
}

// @fnv 0x00874480
// src: XBOX_PDB 0x00874480
int __fastcall Projectile_GetShooter(char* pThis)
{
    return *(int*)(pThis + 0xfc);
}

// @fnv 0x00874670
// src: COMMUNITY 0x00874670
void* __fastcall TESDataHandler_GetEffectShaders(char* pThis)
{
    return pThis + 0x138;
}

// @fnv 0x00874900
// src: COMMUNITY 0x00874900
float __fastcall PlayerCharacter_Get1stPersonFOV(const char* pThis)
{
    return *(const float*)(pThis + 0x674);
}

namespace fnv_00874ac0 {
struct FUN_00874ac0_shell : public Main
{
    void TESMain_DrawWorld_VATS(bool);
};

struct StrG
{
    operator const char*() const;
};
extern StrG g_011deb38;
struct KFModel
{
    void* GetControllerSequence();
    void FOVATSEffectManager_DrawTargetToTexture(const char*, int, int, int, int, int);
};
struct ShadowLightData : public KFModel
{
};
// Exe 0x00874ac0: unit-local Interface view; declarations and layout are preserved.
struct MainInterfaceView
{
    static ShadowLightData* GetVATSEffect();
};
void __cdecl BSRenderState_RestoreColorWriteEnable(int);
// @fnv 0x00874ac0
// src: COMMUNITY 0x00874ac0
void FUN_00874ac0_shell::TESMain_DrawWorld_VATS(bool b)
{
    void* seq = MainInterfaceView::GetVATSEffect()->GetControllerSequence();
    if (seq)
    {
        BSRenderedTexture::EndAllAndResetRendererState();
        BSRenderStateManager_main::SetColorWriteMask(0, (BSRENDERSTATE_LOCK)1);
        MainInterfaceView::GetVATSEffect()->FOVATSEffectManager_DrawTargetToTexture((const char*)g_011deb38, 0, 0, 1, 7, 0);
        BSRenderState_RestoreColorWriteEnable(1);
        MainInterfaceView::GetVATSEffect()->FOVATSEffectManager_DrawTargetToTexture((const char*)g_011deb38, 0, 0, 0, 1, 1);
    }
}
}  // namespace fnv_00874ac0

struct ImageSpaceEffect;
struct ImageSpaceTexture;
struct NiScreenElements;
struct NiTexture;
struct blob16
{
    char b[16];
};
typedef char _sizecheck_ImageSpaceManager[sizeof(ImageSpaceManager) == 796 ? 1 : -1];
struct FUN_00874b50_shell : public Main
{
    void TESMain_DrawWorld_RestartRenderTexture(BSRenderedTexture*, bool, unsigned int);
};

struct NiRenderTargetGroup;

bool __cdecl BSRenderedTexture_IsOutsideFrame(void);
ImageSpaceManager* __cdecl BSShaderManager_GetImageSpaceManager(void);
void* __cdecl BSShaderManager_GetRenderer(void);
void __cdecl BSRenderedTexture_StartOffscreen(unsigned int, NiRenderTargetGroup*);

// @fnv 0x00874b50
// src: COMMUNITY 0x00874b50
void FUN_00874b50_shell::TESMain_DrawWorld_RestartRenderTexture(BSRenderedTexture* apRenderTexture, bool abMultiSampleEnabled,
                                      unsigned int auiClearMode)
{
    if (BSRenderedTexture_IsOutsideFrame())
    {
        ImageSpaceManager* apImagespaceManager = BSShaderManager_GetImageSpaceManager();
        void* apRenderer = BSShaderManager_GetRenderer();
        BSRenderedTexture_StartOffscreen(auiClearMode, apRenderTexture->GetGroup());
    }
}

class ImageSpaceTexture;
class NiScreenElements;
class NiTexture;
namespace fnv_00874b90 {
struct ImageSpaceEffect;
using ::NiPoint2;
struct blob16
{
    char b[16];
};
using ::ImageSpaceManager;
typedef char _sizecheck_ImageSpaceManager[sizeof(ImageSpaceManager) == 796 ? 1 : -1];
struct FUN_00874b90_shell : public Main
{
    void TESMain_DrawWorld_CopyMenuBG(ImageSpaceManager*, ::NiRenderer*, bool, BSRenderedTexture*);
};

struct StrG
{
    operator const char*() const;
};
extern StrG g_011ded3c;
struct ISMStub
{
    void ImageSpaceManager_RenderEffect(int, ::NiRenderer*, const char*, unsigned int, int, int);
};
void __cdecl BSRenderState_RestoreAlphaBlendEnable(int);
void __cdecl BSRenderState_RestoreColorWriteEnable(int);
// @fnv 0x00874b90
// src: COMMUNITY 0x00874b90
void FUN_00874b90_shell::TESMain_DrawWorld_CopyMenuBG(ImageSpaceManager* pManager, ::NiRenderer* r, bool c, BSRenderedTexture* d)
{
    if ((const char*)g_011ded3c)
    {
        BSRenderStateManager_main::SetColorWriteMask(7, (BSRENDERSTATE_LOCK)1);
        BSRenderStateManager_main::SetDepthBufferEnabled(false, (BSRENDERSTATE_LOCK)1);
        ((ISMStub*)pManager)->ImageSpaceManager_RenderEffect(0x22, r, (const char*)g_011ded3c, c ? 0u : (unsigned int)d, 0, 1);
        BSRenderState_RestoreAlphaBlendEnable(1);
        BSRenderState_RestoreColorWriteEnable(1);
    }
}
}  // namespace fnv_00874b90



// Stores the given NiPoint3 offset into the object's point field.
// @fnv 0x008750e0
// src: COMMUNITY 0x008750e0
void __fastcall ShadowSceneNode_SetLightingOffset(::ShadowSceneNode* self, NiPoint3 a_kOffset)
{
    reinterpret_cast<NiPoint3&>(self->kLightingOffset) = a_kOffset;
}

namespace fnv_00876d20 {
using ::StartMenu;

// 0x00408d60 is a folded byte-pointer getter (also ProcessLists::GetLifeStateControlFlag, Setting::FUN_00408d60); the global read here is not the ProcessLists singleton 0x011e0e80
class FlagGetterView
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};

class GlobalObject2_0040c150
{
  public:
    int* Int(void);
};

extern StartMenu g_011c4030;
extern GlobalObject2_0040c150 g_011deaa0;
extern GlobalObject2_0040c150 g_011deb24;
extern StartMenu g_011deb94;
extern FlagGetterView g_011debdc;
extern GlobalObject2_0040c150 g_011dec40;
extern FlagGetterView g_011dec4c;
extern StartMenu g_011dec68;
extern FlagGetterView g_011dee3c;

void __cdecl ArchiveManager_Init(unsigned char, const char*, const char*, int);
void __cdecl ArchiveManager_SetCheckRuntimeCollisions(unsigned char);
void __cdecl SetRetainStringAndOffsetTables(int, int, int);
void __cdecl ArchiveManager_SetInvalidation(unsigned char, const char*);
void __cdecl ArchiveManager_OpenMasterArchives();

// @fnv 0x00876d20
// src: COMMUNITY 0x00876d20
void __cdecl SetupArchiveSettings_AndLoadBSAs()
{
    ArchiveManager_Init(*g_011dee3c.GetLifeStateControlFlag(), ((const StartMenu&)g_011c4030).GetMenuTitle(), ((const StartMenu&)g_011deb94).GetMenuTitle(), 0x200000);
    ArchiveManager_SetCheckRuntimeCollisions(*g_011debdc.GetLifeStateControlFlag());
    SetRetainStringAndOffsetTables(*g_011deb24.Int(), *g_011deaa0.Int(), *g_011dec40.Int());
    ArchiveManager_SetInvalidation(*g_011dec4c.GetLifeStateControlFlag(), ((const StartMenu&)g_011dec68).GetMenuTitle());
    ArchiveManager_OpenMasterArchives();
}
}  // namespace fnv_00876d20

namespace fnv_00877430 {
struct FUN_00877430_shell : public Main
{
    void TESMain_KillMenuBGTexture();
};

struct StrG
{
    operator const char*() const;
};
extern StrG g_011ded3c;
extern bool DAT_011dea29;
using ::ImageSpaceManager;
ImageSpaceManager* __cdecl BSShaderManager_GetImageSpaceManager();
BSTextureManager* __stdcall BSShaderManager_GetTextureManager(const char*);
// @fnv 0x00877430
// src: COMMUNITY 0x00877430
void FUN_00877430_shell::TESMain_KillMenuBGTexture()
{
    if ((const char*)g_011ded3c)
    {
        BSShaderManager_GetTextureManager((const char*)g_011ded3c)->AddRenderedTexture();
        *(NiPointer<NiNode>*)&g_011ded3c = (NiNode*)0;
        BSShaderManager_GetImageSpaceManager()->SetMenuBGBlendValue(0.0f);
        BSShaderManager_GetImageSpaceManager()->SetMenuBGBlendEnabled(false);
    }
    DAT_011dea29 = false;
}
}  // namespace fnv_00877430

struct Controls;
struct FUN_00877720_shell : public Main
{
    Controls* Main_GetControls();
};

Controls* __cdecl Controls_GetInstance();

// @fnv 0x00877720
// src: XBOX_PDB 0x00877720
Controls* FUN_00877720_shell::Main_GetControls()
{
    return Controls_GetInstance();
}

struct FUN_00936aa0_shell
{
    char pad[0x85];
    bool f;
    void MobileObject_SetSoundCallBackSuccess(bool b);
};
// @fnv 0x00936aa0
// src: COMMUNITY 0x00936aa0
void FUN_00936aa0_shell::MobileObject_SetSoundCallBackSuccess(bool abValue)
{
    f = abValue;
}

struct Dummy_00a239e0
{
    int Controls_GetMouseAxis(int a2);
};

// Returns the int stored at offset 0x1B24, 0x1B28 or 0x1B2C of this object depending on a2 (1, 2 or 3), otherwise 0.
// @fnv 0x00a239e0
// src: COMMUNITY 0x00a239e0
int Dummy_00a239e0::Controls_GetMouseAxis(int aiIndex)
{
    switch (aiIndex)
    {
    case 1:
        return *(int*)((char*)this + 0x1B24);
    case 2:
        return *(int*)((char*)this + 0x1B28);
    case 3:
        return *(int*)((char*)this + 0x1B2C);
    default:
        return 0;
    }
}

namespace fnv_0086fbe0 {
bool __fastcall TESCheck_00451530(::TES*);
using ::TES;
struct TopicH
{
    NiPoint3* GetAddTopicList();
};
using ::BGSCameraPath;
struct RefrHelper
{
    TESWorldSpace* GetParentWorldSpace();
};
struct PC7d;
extern PC7d* g_thePlayer;
extern TES* g_TES;
extern bool DAT_011dea2b;
extern bool DAT_011d8907;
// Main update at 0x0086fbe0 reads its +0x07 flag; include/Main.h is not available yet.
struct MainStandIn
{
    char pad[7];
    bool flag7;
    void Main_OnIdle_UpdateCurrentGridCell();
};
// @fnv 0x0086fbe0
// src: XBOX_PDB 0x0086fbe0
void MainStandIn::Main_OnIdle_UpdateCurrentGridCell()
{
    if (!DAT_011dea2b && !DAT_011d8907 && !flag7)
    {
        g_TES->FindCellAtPosition(((TopicH*)g_thePlayer)->GetAddTopicList(), true);
        if (TESCheck_00451530(g_TES) && !((BGSCameraPath*)g_TES)->GetPrevPath())
        {
            if (((RefrHelper*)g_thePlayer)->GetParentWorldSpace() == (TESWorldSpace*)g_TES->GetHitSound())
            {
            }
        }
    }
}
}  // namespace fnv_0086fbe0

struct Flt
{
    operator unsigned int() const;
};
struct Helper62d0
{
    Helper62d0& operator=(void* const&);
};
struct Obj008731d0
{
    char pad0[8];
    Helper62d0 h;
    char pad1[0x20 - 9];
    void* f;
    void BSRenderedTexture_UsePreRestoreGroup();
};
// If the pointer field f is non-null, assigns it to the helper member h.
// @fnv 0x008731d0
// src: COMMUNITY 0x008731d0
void Obj008731d0::BSRenderedTexture_UsePreRestoreGroup()
{
    if (*(Flt*)&f)
        h = f;
}

namespace fnv_008749b0 {
using ::NiRenderer;
struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
struct Flt
{
    operator unsigned int() const;
};
struct KFModel
{
    void* GetControllerSequence();
};
struct VATSEffect
{
    bool VATSEffect_IsOcclusionEnabled();
    void FOVATSEffectManager_DrawTargetToTexture(unsigned int, int, int, int, int, int);
};
// Exe 0x008749b0: unit-local Interface view; declarations and layout are preserved.
struct MainInterfaceView
{
    static VATSEffect* __cdecl GetVATSEffect();
};
NiRenderer* __cdecl NiXenonRenderer_GetRenderer();
BSTextureManager* __stdcall BSShaderManager_GetTextureManager();
extern NP_0081c630 g_011deb38;

// @fnv 0x008749b0
// src: COMMUNITY 0x008749b0
bool __fastcall TESMain_DrawWorld_VATSOcclusionQuery(void* self)
{
    bool bissuedVATSQuery = false;
    if (((KFModel*)MainInterfaceView::GetVATSEffect())->GetControllerSequence())
    {
        if (!(unsigned int)*(Flt*)&g_011deb38)
        {
            g_011deb38 = BSShaderManager_GetTextureManager()->CreateRenderTargetTexture(reinterpret_cast<::NiRenderer*>(NiXenonRenderer_GetRenderer()), 0x2f, 0, 0, 0);
        }
        if (!(unsigned int)*(Flt*)MainInterfaceView::GetVATSEffect() && (unsigned int)*(Flt*)&g_011deb38 &&
            ((KFModel*)MainInterfaceView::GetVATSEffect())->GetControllerSequence() &&
            MainInterfaceView::GetVATSEffect()->VATSEffect_IsOcclusionEnabled())
        {
            MainInterfaceView::GetVATSEffect()->FOVATSEffectManager_DrawTargetToTexture((unsigned int)*(Flt*)&g_011deb38, 0, 1, 0, 7, 0);
            MainInterfaceView::GetVATSEffect()->FOVATSEffectManager_DrawTargetToTexture((unsigned int)*(Flt*)&g_011deb38, 1, 1, 0, 1, 1);
            bissuedVATSQuery = true;
        }
    }
    return bissuedVATSQuery;
}
}  // namespace fnv_008749b0

struct Arr
{
    unsigned int GetSize(void);
    unsigned int* GetAt(int);
};

struct SomeClass
{
    int m_ucUnknownByte[0xad4 / 4];
    Arr m_aiIndexedValues;
    int FindIndexedValue(unsigned int value);
};

// @fnv 0x0086bb70
// src: GUESS 0x0086bb70 (confidence: high)
int SomeClass::FindIndexedValue(unsigned int value)
{
    for (int i = 0; i < m_aiIndexedValues.GetSize(); i++)
    {
        if (*m_aiIndexedValues.GetAt(i) == value)
            return i;
    }
    return -1;
}

extern unsigned char DAT_011f4448;

// @fnv 0x0086bcc0
// src: COMMUNITY 0x0086bcc0
void NiSourceTexture_SetDestroyAppDataFlag(unsigned char value)
{
    DAT_011f4448 = value;
}

void* DAT_011f6e08;

// @fnv 0x0086bcd0
// src: COMMUNITY 0x0086bcd0
void BSSoundHandle_SetAddMovingSoundCallback(void* obj)
{
    DAT_011f6e08 = obj;
}

extern int DAT_011f6224;

// @fnv 0x0086bd90
// src: COMMUNITY 0x0086bd90
void NiSearchPath_SetSearchPathCreateCallback(int value)
{
    DAT_011f6224 = value;
}

struct GlobalObject_0083b5e0
{
    void RemoveAll();
};

extern GlobalObject_0083b5e0 g_011dd948;

// @fnv 0x0086bdd0
// src: COMMUNITY 0x0086bdd0
void ImpactMixer_DeInitialize()
{
    g_011dd948.RemoveAll();
}

extern double(__cdecl* DAT_011f9134)(void*);

// @fnv 0x0086bde0
// src: COMMUNITY 0x0086bde0
void BSFadeNode_GetLinkedActorAlpha_Set(double(__cdecl* value)(void*))
{
    DAT_011f9134 = value;
}

extern int DAT_011d5c44;

// @fnv 0x0086be80
// src: COMMUNITY 0x0086be80
void BSTreeManager_SetCamera(int value)
{
    DAT_011d5c44 = value;
}

extern NiNode* DAT_011d59ec;

// @fnv 0x0086be90
// src: COMMUNITY 0x0086be90
void BSFaceGenManager_SetWorldCamera(NiNode* value)
{
    DAT_011d59ec = value;
}

extern bool DAT_011a31f4;

// @fnv 0x0086bea0
// src: COMMUNITY 0x0086bea0
void TaskQueueInterface_SetActive(bool value)
{
    DAT_011a31f4 = value;
}

struct GlobalObject_00633c90
{
    GlobalObject_00633c90& operator=(void*);
};

extern GlobalObject_00633c90 g_011d8690;
extern GlobalObject_00633c90 g_011d86a8;
extern NiPointer<NiNode> g_011d86bc;

// Clears the three global objects by assigning null to g_011d86bc, g_011d86a8 and g_011d8690.
// @fnv 0x0086beb0
// src: COMMUNITY 0x0086beb0
void BGSTerrainManager_FreeLODNodes()
{
    g_011d86bc = 0;
    g_011d86a8 = 0;
    g_011d8690 = 0;
}

struct FUN_0086bf40
{
    void __thiscall FUN_0086c880();
    void* __thiscall DeleteThis(unsigned int flags);
};

// Calls FUN_0086c880, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0086bf40
void* __thiscall FUN_0086bf40::DeleteThis(unsigned int flags)
{
    FUN_0086c880();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_011dea18;

// @fnv 0x0086d470
// src: COMMUNITY 0x0086d470
int __cdecl TESMain_GetObjectLODRoot()
{
    return DAT_011dea18;
}

extern int DAT_01202e98;

// @fnv 0x0086d480
// src: COMMUNITY 0x0086d480
int* __cdecl BSUtilities_GetLocalAppDataPath()
{
    return &DAT_01202e98;
}

namespace fnv_0086d580 {
extern int DAT_011c6fc8;

// @fnv 0x0086d580
// src: COMMUNITY 0x0086d580
int* __cdecl Renderer_GetReason()
{
    return &DAT_011c6fc8;
}
}  // namespace fnv_0086d580

// ::NiAVObject is named in full below: the shared ExtraDataList forward-declares ::NiAVObject.
extern unsigned int(__cdecl* DAT_011f91ec)(::NiAVObject*);

// @fnv 0x0086e4d0
// src: COMMUNITY 0x0086e4d0
void BSShaderManager_SetObjectTypeCallback(unsigned int(__cdecl* apObjectTypeFunc)(::NiAVObject*))
{
    DAT_011f91ec = apObjectTypeFunc;
}

extern bool DAT_011f91de;

// @fnv 0x0086e500
// src: COMMUNITY 0x0086e500
void BSShaderManager_SetSeparateAmbientLight(bool abSeparateAmbientLight)
{
    DAT_011f91de = abSeparateAmbientLight;
}

extern unsigned char DAT_011f91dd;

// @fnv 0x0086e510
// src: COMMUNITY 0x0086e510
void BSShaderManager_SetSeparateSpecularColor(unsigned char value)
{
    DAT_011f91dd = value;
}

extern int DAT_011f9644;

// @fnv 0x0086e620
// src: COMMUNITY 0x0086e620
void DistantLODShaderProperty_SetLODTreeParent(int apLODTreeParent)
{
    DAT_011f9644 = apLODTreeParent;
}

extern unsigned char DAT_012677a2;

// @fnv 0x0086ef30
// src: COMMUNITY 0x0086ef30
void bhkWorld_ResetBatchProcessed()
{
    DAT_012677a2 = 0;
}

extern unsigned char DAT_011f4461;

// @fnv 0x0086ef60
// src: COMMUNITY 0x0086ef60
unsigned char BSTexturePalette_IsPartiallyPurged()
{
    return DAT_011f4461;
}

extern "C" float DAT_01267c1c;

// @fnv 0x0086ef90
// src: COMMUNITY 0x0086ef90
void bhkRagdollController_ResetFootCastTimer()
{
    DAT_01267c1c = 0.0f;
}

namespace fnv_0086efe0 {
struct SettingFloat
{
    float* Float();
};
using ::TESWorldSpace;
using ::TES;
// 0x008d6f30 is TESObjectREFR::GetParentCell, inherited by the player.
using ::PlayerCharacter;
extern TES* g_TES;
extern PlayerCharacter* g_thePlayer;
extern SettingFloat g_011dea80;
extern SettingFloat g_011deb10;
extern SettingFloat g_011dec24;
extern SettingFloat g_011dec7c;
extern SettingFloat g_011decc8;
extern SettingFloat g_011ded8c;
extern SettingFloat g_011ded98;
extern SettingFloat g_011deddc;
extern SettingFloat g_011dee54;
bool __cdecl Main_GetSceneIsComplex();
bool __fastcall FUN_00425fd0(TESObjectCELL* cell);
void __cdecl BSFadeNode_SetLODFadeOutObjectMult(float);
void __cdecl BSFadeNode_SetLODFadeOutItemMult(float);
void __cdecl BSFadeNode_SetLODFadeOutActorMult(float);

struct FUN_0086efe0_t
{
    void Main_OnIdle_ScaleLOD();
};

// @fnv 0x0086efe0
// src: XBOX_PDB 0x0086efe0
void FUN_0086efe0_t::Main_OnIdle_ScaleLOD()
{
    if (Main_GetSceneIsComplex())
    {
        BSFadeNode_SetLODFadeOutObjectMult(*g_011dec24.Float());
        BSFadeNode_SetLODFadeOutItemMult(*g_011deb10.Float());
        BSFadeNode_SetLODFadeOutActorMult(*g_011ded8c.Float());
    }
    else if (g_TES->GetParentWorldSpace() && ((TESWorldSpace*)g_TES->GetParentWorldSpace())->GetParentWorld(TESWorldSpace::PU_LOD))
    {
        BSFadeNode_SetLODFadeOutObjectMult(*g_011dec7c.Float());
        BSFadeNode_SetLODFadeOutItemMult(*g_011dee54.Float());
        BSFadeNode_SetLODFadeOutActorMult(*g_011ded98.Float());
    }
    else if (g_thePlayer && g_thePlayer->GetParentCell() && FUN_00425fd0(g_thePlayer->GetParentCell()))
    {
        BSFadeNode_SetLODFadeOutObjectMult(*g_011dea80.Float());
        BSFadeNode_SetLODFadeOutItemMult(*g_011deddc.Float());
        BSFadeNode_SetLODFadeOutActorMult(*g_011decc8.Float());
    }
    else
    {
        BSFadeNode_SetLODFadeOutObjectMult(1.0f);
        BSFadeNode_SetLODFadeOutItemMult(1.0f);
        BSFadeNode_SetLODFadeOutActorMult(1.0f);
    }
}
}  // namespace fnv_0086efe0

extern float DAT_011ad804;

// @fnv 0x0086f160
// src: COMMUNITY 0x0086f160
void BSFadeNode_SetLODFadeOutObjectMult(float value)
{
    DAT_011ad804 = value;
}

extern float DAT_011ad800;

// @fnv 0x0086f170
// src: COMMUNITY 0x0086f170
void BSFadeNode_SetLODFadeOutItemMult(float value)
{
    DAT_011ad800 = value;
}

extern float DAT_011ad7fc;

// @fnv 0x0086f180
// src: COMMUNITY 0x0086f180
void BSFadeNode_SetLODFadeOutActorMult(float value)
{
    DAT_011ad7fc = value;
}

extern float DAT_011c40ec;

// @fnv 0x0086f830
// src: XBOX_PDB 0x0086f830
void BGSDestructibleObjectForm_SetLastUpdateTime(float value)
{
    DAT_011c40ec = value;
}

extern unsigned char DAT_011dcfa6;

// @fnv 0x0086fba0
// src: XBOX_PDB 0x0086fba0
void FalloutAudio_DisableRegionSoundUpdates(unsigned char value)
{
    DAT_011dcfa6 = value;
}

class BGSAcousticSpace;
extern BGSAcousticSpace* DAT_011dcfb8;

// @fnv 0x0086fbb0
// src: XBOX_PDB 0x0086fbb0
void FalloutAudio_SetNextAcousticSpace(BGSAcousticSpace* value)
{
    DAT_011dcfb8 = value;
}

namespace fnv_0086fc60 {
using ::NiUpdateData;
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];
struct FUN_0086fc60_shell : public Main
{
    void Main_OnIdle_UpdateAnimationsAndEffects();
};

extern bool DAT_011dea2b;
extern bool DAT_011dea2c;
extern bool DAT_011dea2d;
extern float DAT_011dea30;
struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011c3ea4;
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
extern Twin_0084d030 g_timeGlobal;
struct ProcessListsH
{
    void ProcessLists_UpdateTempEffectsParallel(float afTimeDelta);
    void FUN_00974420(float afTimeDelta);
};
extern ProcessListsH DAT_011e0e80;
using ::NiUpdateData;
using ::TES;
void __fastcall UpdateTES_00453550(TES*, float);
void __fastcall RefreshTES_004537c0(TES*);
extern TES* g_TES;
struct SceneGraphH
{
    void BSParticleSystemManager_UpdateParallel(NiUpdateData* apUpdateData);
};
SceneGraphH* __cdecl Main_GetMasterParticleSystemManager();
// @fnv 0x0086fc60
// src: XBOX_PDB 0x0086fc60
void FUN_0086fc60_shell::Main_OnIdle_UpdateAnimationsAndEffects()
{
    if ((!DAT_011dea2b || DAT_011dea2c || DAT_011dea2d) && !*((bool*)this + 7))
    {
        if (*g_011c3ea4.Int() > 1)
        {
            DAT_011e0e80.ProcessLists_UpdateTempEffectsParallel(g_timeGlobal.GetStoredFloatValue());
        }
        else
        {
            DAT_011e0e80.FUN_00974420(g_timeGlobal.GetStoredFloatValue());
        }
        if (*g_011c3ea4.Int() == 1 && !DAT_011dea2b)
        {
            UpdateTES_00453550(g_TES, DAT_011dea30);
        }
        else
        {
            RefreshTES_004537c0(g_TES);
        }
        NiUpdateData UpdateData(DAT_011dea30, true, false);
        if (*g_011c3ea4.Int() > 1)
        {
            Main_GetMasterParticleSystemManager()->BSParticleSystemManager_UpdateParallel(&UpdateData);
        }
        else
        {
            Main_GetMasterParticleSystemManager()->BSParticleSystemManager_UpdateParallel(&UpdateData);
        }
    }
}
}  // namespace fnv_0086fc60

extern unsigned char DAT_0118abb0;

// @fnv 0x0086ff40
// src: COMMUNITY 0x0086ff40
unsigned char __cdecl TESImageSpaceModifier_GetEnable()
{
    return DAT_0118abb0;
}

extern char DAT_01189184;

// @fnv 0x008705c0
// src: COMMUNITY 0x008705c0
char __cdecl GridCellArray_GetRecreateCanopyShadowMaskTexture()
{
    return DAT_01189184;
}

extern unsigned char DAT_011f91a4;

// @fnv 0x008709f0
// src: COMMUNITY 0x008709f0
unsigned char BSShaderManager_GetImageSpaceEffects()
{
    return DAT_011f91a4;
}

struct HWND__;
extern "C" __declspec(dllimport) HWND__* __stdcall GetForegroundWindow();
struct Controls
{
    int Controls_IsMouseInBackground();
};
Controls* __cdecl Controls_GetInstance();
int __cdecl Renderer_GetScreenWidth();
int __cdecl Renderer_GetScreenHeight();
void __cdecl Interface_SetCursorPos(float x, float y);
void __cdecl Interface_SetSurgeryCursorPos(int x, int y);

struct FUN_00871d10_t
{
    bool TESMain_HandleMouseMove(int x, int y);
};

// @fnv 0x00871d10
// src: COMMUNITY 0x00871d10
bool FUN_00871d10_t::TESMain_HandleMouseMove(int x, int y)
{
    if (GetForegroundWindow() != *(HWND__**)((char*)this + 8))
        return false;
    if (!InterfaceH_main::IsSaveLoadActive() || !Controls_GetInstance()->Controls_IsMouseInBackground())
        return false;
    if (!InterfaceH_main::GetSelectedTargetIndex(0x41e))
        Interface_SetCursorPos((float)(x / (double)Renderer_GetScreenWidth()), (float)(y / (double)Renderer_GetScreenHeight()));
    else
        Interface_SetSurgeryCursorPos(x, y);
    return true;
}

namespace fnv_008727d0 {
bool __fastcall SceneCheck_005f9ad0(::ShadowSceneNode*);
struct FUN_008727d0_shell : public Main
{
    void TESMain_DrawWorld_UpdateWater();
};

using ::BSFaceGenAnimationData;
using ::ShadowSceneNode;
using ::NiAdditionalGeometryData;
// 0x00408d60 is a folded byte-pointer getter (also ProcessLists::GetLifeStateControlFlag, Setting::FUN_00408d60); the global read here is not the ProcessLists singleton 0x011e0e80
struct FlagGetterView
{
    unsigned char* GetLifeStateControlFlag();
};
using ::TES;
struct FUN_004e2120_s
{
    void f(bool);
};
struct FUN_004e2190_shell
{
    FUN_004e2120_s* Main_QDrawWorldAccum();
};
struct MTRenderingSystem_Helper
{
    void MTRenderingSystem_SetThreadStage(int, int);
    void MTRenderingSystem_WaitOnThreadStage(int, int);
};
struct TaskThreadManager : MTRenderingSystem_Helper
{
    static TaskThreadManager* GetSingleton();
};
bool __cdecl TESObjectCELL_IsNodeCulled(int);
BSFaceGenAnimationData* __cdecl Main_WorldRootCamera();
using ::TESWaterSystem;
extern int DAT_011a9608;
extern FlagGetterView g_011c7adc;
extern FUN_004e2190_shell* g_osGlobals;
extern TES* g_TES;
extern bool DAT_011ff104;
extern bool DAT_011ff8c4;

// @fnv 0x008727d0
// src: COMMUNITY 0x008727d0
void FUN_008727d0_shell::TESMain_DrawWorld_UpdateWater()
{
    if (*g_011c7adc.GetLifeStateControlFlag())
    {
        int isavemaxaniso = DAT_011a9608;
        DAT_011a9608 = 1;
        if (!TESObjectCELL_IsNodeCulled(11) &&
            (!g_TES->IsCellInterior() || ((MobileObjectCellAccess_main*)g_TES->IsCellInterior())->FUN_004518e0()))
        {
            ShadowSceneNode* pscene = NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0);
            bool bwasLightUpdateDisabled = SceneCheck_005f9ad0(pscene);
            pscene->SetCreatureType(1);
            ((TESWaterSystem*)g_TES->GetActorScale())->TESWaterSystem_UpdateWaterSystem(Main_WorldRootCamera(), pscene);
            pscene->SetCreatureType(bwasLightUpdateDisabled);
        }
        else
        {
            DAT_011ff104 = false;
            ((TESWaterSystem*)g_TES->GetActorScale())->m_uiPathPointIndex = 0;
            g_osGlobals->Main_QDrawWorldAccum()->f(false);
            DAT_011ff8c4 = false;
            ((TESWaterSystem*)g_TES->GetActorScale())->TESWaterSystem_SetIsUnderWater(0);
        }
        DAT_011a9608 = isavemaxaniso;
    }
    for (int i = ((TESWaterSystem*)g_TES->GetActorScale())->m_uiPathPointIndex + 1; i < 17; i++)
    {
        TaskThreadManager::GetSingleton()->MTRenderingSystem_SetThreadStage(0, i);
        TaskThreadManager::GetSingleton()->MTRenderingSystem_WaitOnThreadStage(1, i);
    }
}
}  // namespace fnv_008727d0

extern unsigned char DAT_011c7a59;

// @fnv 0x00872930
// src: COMMUNITY 0x00872930
void TESWaterSystem_SetIsUnderWater(unsigned char value)
{
    DAT_011c7a59 = value;
}

extern bool DAT_011f9fc3;
extern bool DAT_011f9fc4;

// @fnv 0x00872dd0
// src: COMMUNITY 0x00872dd0
void __cdecl BSShaderAccumulator_SetRunBoundingSphereTests(bool abFlag1, bool abFlag2)
{
    DAT_011f9fc3 = abFlag1;
    DAT_011f9fc4 = abFlag2;
}

struct GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_01201f7c;



// @fnv 0x00872ef0
void* ::BSFadeNodeCuller::GetRTTI()
{
    return &g_01201f7c;
}

void __fastcall DestroyFadeNode(BSFadeNodeCuller*);


extern "C" void __cdecl _Deallocate(void*);

// Calls FUN_00872f30, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00872f00
void* __thiscall BSFadeNodeCuller::DeleteThis(unsigned int flags)
{
    DestroyFadeNode(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}



// @fnv 0x00874650
// src: COMMUNITY 0x00874650
char __fastcall ShadowSceneNode_HasVisibleUnboundSpace(::ShadowSceneNode* self)
{
    return *reinterpret_cast<char*>(&self->bVisibleUnboundSpace);
}

namespace fnv_00874690 {
class GlobalObject_00633c90
{
  public:
    void* operator->() const;
};

GlobalObject_00633c90 g_011c7840;

// @fnv 0x00874690
// src: COMMUNITY 0x00874690
void ScreenSplatter_GetCamera()
{
    g_011c7840.operator->();
}
}  // namespace fnv_00874690

namespace fnv_008746b0 {
struct GlobalObject_00633c90
{
    operator unsigned int() const;
    int* operator->() const;
};

extern GlobalObject_00633c90 g_011c781c;

// @fnv 0x008746b0
// src: COMMUNITY 0x008746b0
int* ScreenCustomSplatter_GetCamera()
{
    return g_011c781c.operator->();
}
}  // namespace fnv_008746b0

extern int DAT_011ff0f0;

// @fnv 0x008746c0
// src: COMMUNITY 0x008746c0
void BSShaderBloodSplatterProperty_ResetShapeCount()
{
    DAT_011ff0f0 = 0;
}





// @fnv 0x008748d0
// 0x008748d0 uses the real ImageSpaceTexture at owner +0x7c.
struct MainRenderTargetOwner_008748d0 { void ImageSpaceEffectDepthOfField_BorrowMaskTexture(); };
// src: COMMUNITY 0x008748d0
void MainRenderTargetOwner_008748d0::ImageSpaceEffectDepthOfField_BorrowMaskTexture()
{
    ((ImageSpaceTexture*)((char*)this + 0x7c))->CreateRenderTargetTexture((BSTextureManager::RenderTargetType)0x27);
    ((ImageSpaceTexture*)((char*)this + 0x7c))->GetRenderedTexture();
}

BSFaceGenNiNode* __cdecl Main_GetWorldSceneGraph();

struct FUN_00874920_t
{
    void TESMain_DrawWorld_Refraction(::BSShaderAccumulator* apShaderAccum, BSRenderedTexture* apRenderTexture);
};

// Gets the face-gen scene node and passes its animation data with the render texture to the shader accumulator.
// @fnv 0x00874920
// src: COMMUNITY 0x00874920
void FUN_00874920_t::TESMain_DrawWorld_Refraction(::BSShaderAccumulator* apShaderAccum, BSRenderedTexture* apRenderTexture)
{
    BSFaceGenNiNode* pscene;
    AutoMemHelper tempMemContext(0x27, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0x20d5);
    pscene = Main_GetWorldSceneGraph();
    apShaderAccum->BSShaderAccumulator_RenderNormals(pscene->::BSFaceGenNiNode::GetAnimationData(), (::BSRenderedTexture*)apRenderTexture);
}

struct FUN_00a235d0_class
{
    int __thiscall return_1(int a1, int a2);
};

// @fnv 0x00a235d0
// src: COMMUNITY 0x00a235d0
int __thiscall FUN_00a235d0_class::return_1(int a1, int a2)
{
    return 1;
}

struct FUN_00a236b0_Class
{
    int Controls_GetButtonCount(int index);
};

// @fnv 0x00a236b0
// src: COMMUNITY 0x00a236b0
int __thiscall FUN_00a236b0_Class::Controls_GetButtonCount(int index)
{
    return *(int*)(this + 0x1764 + index * 0x2c);
}

struct FUN_0086ba60_Class
{
    bool NiRenderer_Check_FrameState(void* a1, void* a2);
};

// Returns true if the pointer stored at offset 0x200 of this object equals a2.
// @fnv 0x0086ba60
// src: XBOX_PDB 0x0086ba60
bool FUN_0086ba60_Class::NiRenderer_Check_FrameState(void* apUnused, void* a2)
{
    if (*(void**)((char*)this + 0x200) == a2)
        return true;
    return false;
}

namespace fnv_0086bb20 {
struct GlobalObject_00869b10
{
    void RemoveAt(unsigned int);
};

struct SomeClass
{
    int FindIndexedValue(unsigned int);
    bool RemoveEntryFromBothLists(unsigned int index);
};

// Looks up index via FUN_0086bb70; if found, removes that entry from the two lists at offsets 0xad4 and 0xae4 and returns true, else false.
// @fnv 0x0086bb20
// src: GUESS 0x0086bb20 (confidence: medium)
bool SomeClass::RemoveEntryFromBothLists(unsigned int index)
{
    int result = FindIndexedValue(index);
    if (result == -1)
        return false;
    (reinterpret_cast<GlobalObject_00869b10*>(reinterpret_cast<unsigned char*>(this) + 0xad4))->RemoveAt(result);
    (reinterpret_cast<GlobalObject_00869b10*>(reinterpret_cast<unsigned char*>(this) + 0xae4))->RemoveAt(result);
    return true;
}
}  // namespace fnv_0086bb20



// @fnv 0x0086bdf0
// src: COMMUNITY 0x0086bdf0
char LoadingMenuThread_GetByte49()
{
    int result;
    if (BSSystemUtility::ms_pSystemUtility && ((::TESGrass*)BSSystemUtility::ms_pSystemUtility)->::TESGrass::GetMinimumSlopeDegrees())
        result = 1;
    else
        result = 0;
    return (char)result;
}

// Returns the smaller of the two arguments, comparing the float against the double and returning it as a double.
// @fnv 0x008731a0
// src: COMMUNITY 0x008731a0
double dMin(double adValue, float afValue)
{
    double d;
    if (afValue > adValue)
        d = adValue;
    else
        d = afValue;
    return d;
}

namespace fnv_008746a0 {
struct Flt
{
    operator unsigned int(void);
};

extern Flt g_011c7810;

// @fnv 0x008746a0
// src: COMMUNITY 0x008746a0
void ScreenCustomSplatter_GetCurrentRoot()
{
    g_011c7810.operator unsigned int();
}
}  // namespace fnv_008746a0

struct FUN_00874aa0_Class
{
    char VATSEffect_IsOcclusionEnabled();
};

// @fnv 0x00874aa0
// src: COMMUNITY 0x00874aa0
char FUN_00874aa0_Class::VATSEffect_IsOcclusionEnabled()
{
    return *(char*)((char*)this + 0x118);
}

struct FUN_008776e0
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    void SetFlags();
};

// @fnv 0x008776e0
void FUN_008776e0::SetFlags()
{
    b2 = 0;
    b5 = 0;
}



// @fnv 0x00877700
// src: COMMUNITY 0x00877700
bool __fastcall PlayerCharacter_StopHeartbeatSound(::BSSoundHandle* self)
{
    return ((::BSSoundHandle*)((char*)self + 0x77c))->FadeOutAndRelease(0x3e8);
}

struct FUN_0086ef70_Class
{
    char TES_CellTestRunning2();
};

// @fnv 0x0086ef70
// src: XBOX_PDB 0x0086ef70
char FUN_0086ef70_Class::TES_CellTestRunning2()
{
    return *(char*)((char*)this + 0x52);
}

// A trivial aggregate keeps the legacy byte argument on the stack after explicit ECX.
struct RegionSoundFlagArgument
{
    char value;
};

// @fnv 0x0086fbc0
// src: XBOX_PDB 0x0086fbc0
void __fastcall PlayerCharacter_SetAcousticSpaceTransition(::PlayerCharacter* self, RegionSoundFlagArgument flag)
{
    *reinterpret_cast<char*>(&self->regionSoundsEnabled) = flag.value;
}

struct FUN_008727b0_Class
{
    char __thiscall TESSaveLoadGame_GetInitArrayExists() const;
};
// @fnv 0x008727b0
// src: COMMUNITY 0x008727b0
char __thiscall FUN_008727b0_Class::TESSaveLoadGame_GetInitArrayExists() const
{
    return *(int*)((char*)this + 0x20) != 0;
}

extern "C" void __cdecl UpdateFields_00a693e0();

void __fastcall DestroyBaseCuller(BSFadeNodeCuller*);

// @fnv 0x00872f30
void __fastcall DestroyFadeNode(BSFadeNodeCuller* self)
{
    DestroyBaseCuller(self);
}

namespace fnv_00875bd0 {
struct Flt
{
    operator unsigned int();
};

struct FUN_00875bd0_Class
{
    unsigned int __thiscall FOPipboyManager_GetPipboyLightGlow(int idx);
};

// @fnv 0x00875bd0
// src: COMMUNITY 0x00875bd0
unsigned int __thiscall FUN_00875bd0_Class::FOPipboyManager_GetPipboyLightGlow(int aiIndex)
{
    return ((Flt*)((char*)this + 0xf4 + aiIndex * 4))->operator unsigned int();
}
}  // namespace fnv_00875bd0

struct FUN_00456630_helper
{
    bool NiAVObject_GetBit(unsigned int);
    void NiAVObject_GetAlwaysDraw();
};

// @fnv 0x00876810
// src: COMMUNITY 0x00876810
void FUN_00456630_helper::NiAVObject_GetAlwaysDraw()
{
    NiAVObject_GetBit(0x800);
}


// @fnv 0x00876830
// src: COMMUNITY 0x00876830
void __thiscall BSRenderedTexture::TESMain_DrawWorld_StopRenderTarget(int, int)
{
    EndAllAndResetRendererState();
}

struct FUN_00877a50Class
{
    unsigned char _pad_000a[0xa];
    unsigned short m_000a;
    void EvaluateValue_00877e10(unsigned short a, int b);
    void ForwardCall_00877a50(int param_2);
};

// Calls FUN_00877e10 with m_000a and param_2.
// @fnv 0x00877a50
// src: GUESS 0x00877a50 (confidence: low)
void FUN_00877a50Class::ForwardCall_00877a50(int param_2)
{
    EvaluateValue_00877e10(m_000a, param_2);
}

struct FUN_00a23490_Class
{
    int GetMaskedValue_00a23490(int a, unsigned int b);
};

// Returns whether the bit at position b is set in the int stored at this + a*8 + 0x18b8.
// @fnv 0x00a23490
// src: GUESS 0x00a23490 (confidence: low)
int FUN_00a23490_Class::GetMaskedValue_00a23490(int aiIndex, unsigned int auiBit)
{
    return (1 << auiBit) & *(int*)((char*)this + aiIndex * 8 + 0x18b8);
}

struct FUN_00a23690_class
{
    int GetFieldAtOffset1760ByIndex(int index);
};

// @fnv 0x00a23690
// src: GUESS 0x00a23690 (confidence: low)
int FUN_00a23690_class::GetFieldAtOffset1760ByIndex(int index)
{
    return *(int*)((char*)this + 0x1760 + index * 0x2c);
}

struct FUN_00a236d0_class
{
    int __thiscall Controls_GetHatCount(int index);
};

// @fnv 0x00a236d0
// src: COMMUNITY 0x00a236d0
int __thiscall FUN_00a236d0_class::Controls_GetHatCount(int index)
{
    return *(int*)((char*)this + 0x1768 + index * 0x2c);
}

extern "C" void __cdecl _Deallocate(void*);

struct FUN_0086bd40_class
{
    void __thiscall FUN_00afdcf0();
    void* __thiscall FUN_0086bd40(unsigned int flags);
};

// @fnv 0x0086bd40
void* __thiscall FUN_0086bd40_class::FUN_0086bd40(unsigned int flags)
{
    FUN_00afdcf0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_0086bee0_class
{
    void __thiscall FUN_00450770();
    void* __thiscall FUN_0086bee0(unsigned int flags);
};

// @fnv 0x0086bee0
void* __thiscall FUN_0086bee0_class::FUN_0086bee0(unsigned int flags)
{
    FUN_00450770();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl _Deallocate(void*);
void __cdecl ClearThreePerformanceEntries();
struct FUN_0086bf10
{
    void __thiscall ClearThreePerformanceEntries();
    void* __thiscall DeleteThis(unsigned int flags);
};
// Calls FUN_00700650, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0086bf10
void* __thiscall FUN_0086bf10::DeleteThis(unsigned int flags)
{
    ClearThreePerformanceEntries();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

class ActiveEffect;
class Actor;
class AlchemyItem;
struct BGSEncounterZone;
class BGSLoadGameBuffer;
class BGSSaveFormBuffer;
class BGSSaveGameBuffer;
class BSAnimNoteReceiver;
class BSExtraData;
class BSMultiBound;
class BSMultiBoundRoom;
class BSShaderNoLightingProperty;
class BaseFormComponent;
class BaseProcess;
class CellMopp;
class EffectItem;
class ExtraDataList;
class ExtraLock;
class FormRecordHeader;
class FurnitureMark;
class HWND__;
struct InventoryChanges;
class InventoryStackRecord;
class MagicCaster;
class MagicItem;
class MagicProjectile;
class MagicTarget;
class MobileObject;
class NiCamera;
class NiColor;
class NiControllerManager;
class NiControllerSequence;
class NiLight;
class NiPointLight;
class NiTexture;
class PlacedObjectInfo;
class Script;
class ScriptLocals;
class SpellItem;
class TESActorBase;
class TESAmmo;
class TESBoundObject;
class TESContainer;
class TESFile;
class TESForm;
class TESGlobal;
class TESIdleForm;
class TESModel;
class TESObjectARMO;
class TESObjectCLOT;
class TESObjectLIGH;
class TESObjectWEAP;
class TESPackage;
class TESSound;
class TESTopic;
class TESTopicInfo;
class TargetEntry;
class bhkCharacterController;
class bhkNiCollisionObject;
class hkpRigidBody;
namespace fnv_0086f6a0 {
void __fastcall UpdatePipboy_007fa990(::FOPipboyManager*);
struct ActorCause;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct ExplosionForm;
using ::BGSLoadFormBuffer;
using ::BSFaceGenAnimationData;
using ::BSFaceGenNiNode;
using ::BSSoundHandle;
struct BipedAnim;
struct CHUNK;
struct GameFormRecord;
struct DialogueResponse;
struct TeleportableReference;
struct TESFileGroup;
struct BooleanIntegerAccessor;
struct CellDataNode;
struct MagicEffectCollection;
struct MapMarkerData;
struct Point3Offset;
using ::NiAVObject;
struct AnimationInterpolator;
using ::NiFixedString;
using ::NiMatrix3;
using ::NiNode;
using ::NiPoint3;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
using ::ShadowSceneNode;
using ::TESObjectREFR;
using ::TESWorldSpace;
struct TrapEntry;
struct WaterZone;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct FUN_0086f6a0_shell : public Main
{
    void Main_UpdateNonRenderSafeAITasks();
};

template <int N> struct FUN_0086f6a0_vs : FUN_0086f6a0_vs<N - 1>
{
    virtual void vf(int (*)[N + 1]);
};
template <> struct FUN_0086f6a0_vs<0>
{
    virtual void vf0();
};
struct FUN_0086f6a0_mob : FUN_0086f6a0_vs<63>
{
    virtual bool IsSlot64();
};
struct FUN_0086f6a0_act : FUN_0086f6a0_vs<256>
{
    virtual void Slot257(float);
};
using ::FOPipboyManager;
struct GlobalObject_0045cfe0
{
    int* Int();
};
struct GlobalObject2_0040c150;
struct TaskQueueInterface
{
    static TaskQueueInterface* GetInstance();
    static void ThreadProcessSecondaryInput();
    static void ThreadProcessInput(unsigned int);
    void TaskQueueInterface_ProcessQueue();
};
struct FUN_0087a6b0_shell
{
    void TaskQueueInterface_ThreadBeginInput();
};
struct FUN_0087a6d0_shell
{
    void TaskQueueInterface_ThreadEndInput();
};
// Exe 0x0086f6a0: unit-local Interface view; declarations and layout are preserved.
struct MainInterfaceView
{
    static bool IsConsoleActive();
    static FOPipboyManager* GetPipboyManagerInstance();
};
struct DialogH
{
    static bool IsInDialog();
};
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct FUN_0096c970_shell
{
    void ProcessLists_ParallelUpdateAnimationScenegraph();
};
struct FUN_00991600_t
{
    void CombatManager_UpdateMainThread(bool);
};
using ::GameTimerRecord;
void TESObjectCELL_PerformQueuedChildAttaches();
void TESObjectCELL_RunQueuedParticleUpdates();
FUN_0086f6a0_mob* DialogMenu_GetDialogSpeaker();
void BGSDestructibleObjectForm_SetLastUpdateTime(float);
bool __fastcall FOPipboyManager_GetPipBoyManagerReset(char*);
bool DialogMenu_GetPaused();
void __fastcall ProcessLists_ReconcileDetectionDataForActor(ProcessLists*);
extern float DAT_011c3c08;
extern GlobalObject_0045cfe0 g_011c3ea4;
extern GlobalObject2_0040c150 g_011d10d4;
extern bool DAT_011dea2b;
extern bool DAT_011dea2d;
extern ProcessLists DAT_011e0e80;
extern FUN_00991600_t* BGSSaveLoadGlobalDataWorldspacePtr;
extern GameTimerRecord g_timeGlobal;

// @fnv 0x0086f6a0
// src: XBOX_PDB 0x0086f6a0
void FUN_0086f6a0_shell::Main_UpdateNonRenderSafeAITasks()
{
    FOPipboyManager* ppipboy;
    FUN_0086f6a0_mob* pmob;
    FUN_0086f6a0_act* pact;
    if (DialogH::IsInDialog() && !MainInterfaceView::IsConsoleActive() && !DialogMenu_GetPaused())
    {
        pmob = DialogMenu_GetDialogSpeaker();
        if (pmob && pmob->IsSlot64())
        {
            pact = (FUN_0086f6a0_act*)pmob;
            pact->Slot257(0.0f);
        }
    }
    DAT_011e0e80.UpdateMagicTempEffects(0.0f);
    if (*g_011c3ea4.Int() > 1)
        ((FUN_0096c970_shell*)&DAT_011e0e80)->ProcessLists_ParallelUpdateAnimationScenegraph();
    else
        DAT_011e0e80.ProcessLists_UpdateAnimationScenegraph();
    ProcessLists_ReconcileDetectionDataForActor(&DAT_011e0e80);
    DAT_011e0e80.ProcessLists_UpdateNonRenderSafeStuff(((Twin_0084d030*)&g_timeGlobal)->GetStoredFloatValue());
    ppipboy = MainInterfaceView::GetPipboyManagerInstance();
    if (FOPipboyManager_GetPipBoyManagerReset((char*)ppipboy))
        UpdatePipboy_007fa990(ppipboy);
    if (*g_011c3ea4.Int() > 1)
    {
        TESObjectCELL_PerformQueuedChildAttaches();
        ((FUN_0087a6d0_shell*)TaskQueueInterface::GetInstance())->TaskQueueInterface_ThreadEndInput();
        TaskQueueInterface::GetInstance()->TaskQueueInterface_ProcessQueue();
        TESObjectCELL_RunQueuedParticleUpdates();
        BGSDestructibleObjectForm_SetLastUpdateTime(DAT_011c3c08);
        ((FUN_0087a6b0_shell*)TaskQueueInterface::GetInstance())->TaskQueueInterface_ThreadBeginInput();
    }
    TaskQueueInterface::ThreadProcessInput(*((GlobalObject_0045cfe0*)&g_011d10d4)->Int());
    TaskQueueInterface::ThreadProcessSecondaryInput();
    BGSSaveLoadGlobalDataWorldspacePtr->CombatManager_UpdateMainThread(DAT_011dea2b || DAT_011dea2d || *((bool*)this + 7));
}
}  // namespace fnv_0086f6a0

namespace fnv_0086fd90 {
float __fastcall TimerSeconds_0084d030(::GameTimerRecord*);
struct FUN_0086fd90_shell : public Main
{
    void Main_OnIdle_UpdateImageSpace(bool);
};

struct Twin_0084d030
{
    float GetStoredFloatValue();
};
using ::GameTimerRecord;
extern GameTimerRecord g_timeGlobal;
using ::ImageSpaceManager;
void __fastcall ISM_00b8b500(::ImageSpaceManager*);
void __fastcall ISM_00b8aea0(::ImageSpaceManager*);
void __fastcall ISM_00b8ccb0(::ImageSpaceManager*);
void __fastcall ISM_00b8d020(::ImageSpaceManager*);
ImageSpaceManager* __cdecl BSShaderManager_GetImageSpaceManager();
unsigned char __cdecl TESImageSpaceModifier_GetEnable();
void __cdecl TESImageSpaceModifier_AdvanceCurrentTime(float);
struct ISMI_0086fd90
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual bool IsExpired();
    virtual void Update();
    int iPad4;
    bool bActive;
};
struct Flt
{
    operator unsigned int();
};
using ::GO;
struct ISMList_0086fd90
{
    Flt& FUN_006815c0();
    ISMList_0086fd90* GetNext();
    void Remove(const GO&);
};
using ::TES;
extern TES* g_TES;
// @fnv 0x0086fd90
// src: XBOX_PDB 0x0086fd90
void FUN_0086fd90_shell::Main_OnIdle_UpdateImageSpace(bool abAdvanceTime)
{
    ISM_00b8b500(BSShaderManager_GetImageSpaceManager());
    BSShaderManager_GetImageSpaceManager()->BeginParamModifiers();
    if (abAdvanceTime)
        TESImageSpaceModifier_AdvanceCurrentTime(TimerSeconds_0084d030(&g_timeGlobal));
    ISMList_0086fd90* pModifierList = (ISMList_0086fd90*)g_TES->GetActiveImageSpaceModifierList();
    int iActiveCount = 0;
    int iactiveWeatherCount = 0;
    while (pModifierList)
    {
        ISMI_0086fd90* pModifier = (ISMI_0086fd90*)(unsigned int)pModifierList->FUN_006815c0();
        if (pModifier)
        {
            if (pModifier->bActive)
                ++iActiveCount;
            if (pModifier->IsExpired())
            {
                pModifierList->Remove((unsigned int*)pModifier);
                continue;
            }
            else if (TESImageSpaceModifier_GetEnable())
            {
                pModifier->Update();
                if (((Twin_0084d030*)pModifier)->GetStoredFloatValue() > 0.0 && pModifier->bActive)
                    ++iactiveWeatherCount;
            }
        }
        pModifierList = pModifierList->GetNext();
        if (iActiveCount == 4)
        {
            if (!iactiveWeatherCount)
                ISM_00b8aea0(BSShaderManager_GetImageSpaceManager());
            ISM_00b8ccb0(BSShaderManager_GetImageSpaceManager());
            iActiveCount = 0;
        }
    }
    ISM_00b8d020(BSShaderManager_GetImageSpaceManager());
    BSShaderManager_GetImageSpaceManager()->ApplyCurrentParameterData(false);
}
}  // namespace fnv_0086fd90

struct NiStream;
class NiRenderTargetGroup;
namespace fnv_008746d0 {
using ::NiColorA;
typedef char _sizecheck_NiColorA[sizeof(NiColorA) == 16 ? 1 : -1];
struct FUN_008746d0_shell : public Main
{
    void TESMain_DrawWorld_Add1stPersonToDepthBuffer(BSRenderedTexture*);
};

using ::NiNode;
using ::NiColor;
using ::NiAVObject;
// 0x008748d0 runs on an object holding an ImageSpaceTexture at +0x7c (the result of 0x004ebbc0), not on an ImageSpaceTexture
struct TextureOwnerView_008748d0
{
    BSRenderedTexture* ImageSpaceEffectDepthOfField_BorrowMaskTexture();
};
struct S4
{
    TextureOwnerView_008748d0* GetEffect_004ebbc0(int);
};
using ::MiddleLowProcess;
using ::BSFaceGenNiNode;
struct PC_00605d70
{
    NiNode* GetNode(bool);
};
struct FUN_008bbc10_shell
{
    bool Actor_GetIronSights();
};
struct Flt
{
    operator unsigned int();
};
using ::BSShaderManager;
// NiRenderer slots 43-45 are the two background setters and the background getter.
using ::NiRenderer;
S4* __cdecl BSShaderManager_GetImageSpaceManager();
NiRenderer* __cdecl BSShaderManager_GetRenderer();
BSFaceGenNiNode* __cdecl Main_GetWorldSceneGraph();
void __cdecl BSShaderUtil_AccumulateScene(void*, ::NiAVObject*, ::BSCullingProcess*);
void __cdecl BSRenderState_RestoreColorWriteEnable(unsigned int);
float __fastcall PlayerCharacter_Get1stPersonFOV(PC_00605d70*);
float __fastcall PlayerCharacter_GetWorldFOV(PC_00605d70*);
extern NiColor DAT_011f4998;
// @fnv 0x008746d0
// src: COMMUNITY 0x008746d0
void FUN_008746d0_shell::TESMain_DrawWorld_Add1stPersonToDepthBuffer(BSRenderedTexture* apRenderTexture)
{
    S4* pimagespacemanager = BSShaderManager_GetImageSpaceManager();
    NiRenderer* prenderer = BSShaderManager_GetRenderer();
    NiNode* pscenegraph = ((PC_00605d70*)g_thePlayer)->GetNode(true);
    BSFaceGenNiNode* p1stperson3d = Main_GetWorldSceneGraph();
    ::BSCullingProcess* pculler = (::BSCullingProcess*)((MiddleLowProcess*)p1stperson3d)->MiddleLowProcess::GetProcessInteger();
    bool m_kFieldAfterWeaponFlags = ((FUN_008bbc10_shell*)g_thePlayer)->Actor_GetIronSights();
    BSRenderedTexture* p1stpersonBuffer = 0;
    NiColorA savedBackground(0.0f, 0.0f, 0.0f, 0.0f);
    if (m_kFieldAfterWeaponFlags)
    {
        p1stpersonBuffer = pimagespacemanager->GetEffect_004ebbc0(4)->ImageSpaceEffectDepthOfField_BorrowMaskTexture();
        BSRenderedTexture::EndAllAndResetRendererState();
        prenderer->GetBackgroundColor(reinterpret_cast<NiVector4*>(&savedBackground));
        prenderer->SetBackgroundColor(DAT_011f4998);
        BSRenderedTexture_StartOffscreen(1, p1stpersonBuffer->GetGroup());
    }
    else
    {
        BSRenderStateManager_main::SetColorWriteMask(0, 1);
    }
    ::NiAVObject* p1stPersonNode = (::NiAVObject*)pscenegraph;
    bool bwas1stPersonCulled = p1stPersonNode->IsCulledFlag();
    p1stPersonNode->SetAppCulled(false);
    p1stperson3d->SceneGraph_SetCameraFOV(PlayerCharacter_Get1stPersonFOV((PC_00605d70*)g_thePlayer), 0, 0, 0);
    BSShaderManager::SetFOV(PlayerCharacter_Get1stPersonFOV((PC_00605d70*)g_thePlayer));
    pculler->SetAccumulator((::MenuTarget*)(unsigned int)*(Flt*)((char*)this + 0x90));
    BSShaderUtil_AccumulateScene(((BSFaceGenNiNode*)p1stperson3d)->::BSFaceGenNiNode::GetAnimationData(), p1stPersonNode, pculler);
    BSShaderRenderUtility_main::SetRenderCamera(((BSFaceGenNiNode*)p1stperson3d)->::BSFaceGenNiNode::GetAnimationData(),
                                           *(Flt*)((char*)this + 0x90), false);
    pculler->SetAccumulator((::MenuTarget*)0);
    p1stperson3d->SceneGraph_SetCameraFOV(PlayerCharacter_GetWorldFOV((PC_00605d70*)g_thePlayer), 0, 0, 0);
    BSShaderManager::SetFOV(PlayerCharacter_GetWorldFOV((PC_00605d70*)g_thePlayer));
    p1stPersonNode->SetAppCulled(bwas1stPersonCulled);
    if (m_kFieldAfterWeaponFlags)
    {
        prenderer->SetBackgroundColor(reinterpret_cast<NiVector4*>(&savedBackground));
        BSRenderedTexture::EndAllAndResetRendererState();
    }
    else
    {
        BSRenderState_RestoreColorWriteEnable(1);
    }
}
}  // namespace fnv_008746d0

class NiCamera;
namespace fnv_00875e40 {
using ::AutoMemHelper;
// Exe 0x00875e40: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct MainOffset08View
{
    unsigned int GetFlags();
};
extern MainOffset08View DAT_011f2250;
unsigned int __cdecl Main_GetWorldSceneGraph(void);
struct NiObjectCopyInfo
{
    int a, b, c, d;
    NiObjectCopyInfo(unsigned int flags);
    ~NiObjectCopyInfo();
};
struct FUN_00875e40_Clone
{
    virtual ~FUN_00875e40_Clone();
};
struct FUN_00875e40_Src
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual FUN_00875e40_Clone* Clone(NiObjectCopyInfo& info);
};
using ::BSFaceGenNiNode;
struct FUN_00710ab0_Class;
float __fastcall PlayerCharacter_GetWorldFOV(FUN_00710ab0_Class* p);
float __fastcall PlayerCharacter_Get1stPersonFOV(const char* p);
using ::BSShaderManager;
using ::BSShaderAccumulator;
struct FUN_00875e40_shell
{
    void Main_DrawWorld_DoDepth(BSShaderAccumulator* pAccum, BSRenderedTexture* pTexture);
};

// Clones the scene graph's animation data as a camera, sets FOV and depth via pAccum->SetupDepth, then deletes the cloned camera.
// @fnv 0x00875e40
// src: XBOX_PDB 0x00875e40
void FUN_00875e40_shell::Main_DrawWorld_DoDepth(BSShaderAccumulator* pAccum, BSRenderedTexture* pTexture)
{
    BSFaceGenNiNode* pkSceneGraph = (BSFaceGenNiNode*)Main_GetWorldSceneGraph();
    if (DAT_011f2250.GetFlags() != 4)
        pkSceneGraph->SceneGraph_SetCameraFOV(PlayerCharacter_GetWorldFOV((FUN_00710ab0_Class*)g_thePlayer), 0, 0, 0);
    BSShaderManager::SetFOV(PlayerCharacter_GetWorldFOV((FUN_00710ab0_Class*)g_thePlayer));
    {
        NiObjectCopyInfo kInfo(0x101);
        FUN_00875e40_Clone* pkCamera = ((FUN_00875e40_Src*)pkSceneGraph->::BSFaceGenNiNode::GetAnimationData())->Clone(kInfo);
        if (DAT_011f2250.GetFlags() != 4)
            pkSceneGraph->SceneGraph_SetCameraFOV(PlayerCharacter_Get1stPersonFOV((const char*)g_thePlayer), 0, pkCamera, 0);
        AutoMemHelper kMemHelper(0x27, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0x234c);
        pAccum->SetupDepth((::NiCamera*)pkSceneGraph->::BSFaceGenNiNode::GetAnimationData(), (::NiCamera*)pkCamera, (::BSRenderedTexture*)pTexture);
        delete pkCamera;
    }
}
}  // namespace fnv_00875e40

namespace fnv_00875fa0 {
unsigned int __cdecl Main_GetWorldSceneGraph(void);
using ::BSFaceGenNiNode;
struct Param00875fa0
{
    void BSShaderAccumulator_RenderVolumetricFog(void*, void*);
};
struct Outer00875fa0
{
    void TESMain_DrawWorld_DoVolumetricFog(Param00875fa0*, void*);
};
// Calls FUN_0045c670 to get a BSFaceGenNiNode, then passes its animation data and b to FUN_00b651e0 on a.
// @fnv 0x00875fa0
// src: COMMUNITY 0x00875fa0
void Outer00875fa0::TESMain_DrawWorld_DoVolumetricFog(Param00875fa0* pParam, void* b)
{
    BSFaceGenNiNode* tmp = (BSFaceGenNiNode*)Main_GetWorldSceneGraph();
    pParam->BSShaderAccumulator_RenderVolumetricFog(tmp->::BSFaceGenNiNode::GetAnimationData(), b);
}
}  // namespace fnv_00875fa0

class NiDX9TextureData;
class ImageSpaceTexture;
class NiBillboardNode;
class NiCamera;
class NiDirectionalLight;
class NiPick;
class NiScreenElements;
class NiTexture;
class NiTriShape;
class Sun;
namespace fnv_00876850 {
using ::BSShaderAccumulator;
struct ShaderRenderType;
struct GeometryDeviceType;
struct ShaderComRelatedType;
struct ComRenderSupportType;
struct ComGraphicsSupportType;
struct COMBaseInterface;
struct GeometryBufferData;
struct VertexBufferBlock;
struct GeometryRelatedType;
struct NiIBBlock;
struct NiDX9BufferManager;
struct NiDX9VertexDeclaration;
struct Direct3DRenderState;
struct Direct3D9RenderSystem;
struct COMUnknownInterface;
struct RenderableGeometry;
struct ImageSpaceEffectRenderer;
struct Direct3D;
struct ImageSpaceEffect;
using ::NiNode;
using ::NiPoint2;
using ::Sky;
struct Direct3DRendererType;
struct _D3DCAPS9;
struct _D3DDEVICE_CREATION_PARAMETERS;
struct _D3DDISPLAYMODE;
struct _D3DGAMMARAMP;
struct _D3DPRESENT_PARAMETERS_;
struct Direct3DPresentationType;
struct _D3DRASTER_STATUS;
struct Direct3DViewportSupportType;
struct _D3DVIEWPORT9;
struct Direct3DStructure;
struct FourComponentNumericValue;
struct tagRECT;
struct blob4
{
    char b[4];
};
struct blob16
{
    char b[16];
};
using ::ImageSpaceManager;
typedef char _sizecheck_ImageSpaceManager[sizeof(ImageSpaceManager) == 796 ? 1 : -1];
struct FUN_00876850_shell : public Main
{
    void TESMain_DrawWorld_End(BSRenderedTexture*, ImageSpaceManager*, ::NiRenderer*, Sun*);
};

struct Dev9
{
    virtual void __stdcall v0();
    virtual void __stdcall v1();
    virtual void __stdcall v2();
    virtual void __stdcall v3();
    virtual void __stdcall v4();
    virtual void __stdcall v5();
    virtual void __stdcall v6();
    virtual void __stdcall v7();
    virtual void __stdcall v8();
    virtual void __stdcall v9();
    virtual void __stdcall v10();
    virtual void __stdcall v11();
    virtual void __stdcall v12();
    virtual void __stdcall v13();
    virtual void __stdcall v14();
    virtual void __stdcall v15();
    virtual void __stdcall v16();
    virtual void __stdcall v17();
    virtual void __stdcall v18();
    virtual void __stdcall v19();
    virtual void __stdcall v20();
    virtual void __stdcall v21();
    virtual void __stdcall v22();
    virtual void __stdcall v23();
    virtual void __stdcall v24();
    virtual void __stdcall v25();
    virtual void __stdcall v26();
    virtual void __stdcall v27();
    virtual void __stdcall v28();
    virtual void __stdcall v29();
    virtual void __stdcall v30();
    virtual void __stdcall v31();
    virtual void __stdcall v32();
    virtual void __stdcall v33();
    virtual void __stdcall v34();
    virtual void __stdcall v35();
    virtual void __stdcall v36();
    virtual void __stdcall v37();
    virtual void __stdcall v38();
    virtual void __stdcall v39();
    virtual void __stdcall v40();
    virtual void __stdcall v41();
    virtual void __stdcall v42();
    virtual void __stdcall v43();
    virtual void __stdcall v44();
    virtual void __stdcall v45();
    virtual void __stdcall v46();
    virtual void __stdcall v47();
    virtual void __stdcall v48();
    virtual void __stdcall v49();
    virtual void __stdcall v50();
    virtual void __stdcall v51();
    virtual void __stdcall v52();
    virtual void __stdcall v53();
    virtual void __stdcall v54();
    virtual void __stdcall v55();
    virtual void __stdcall v56();
    virtual void __stdcall v57();
    virtual void __stdcall v58();
    virtual void __stdcall v59();
    virtual void __stdcall v60();
    virtual void __stdcall v61();
    virtual void __stdcall v62();
    virtual void __stdcall v63();
    virtual void __stdcall v64();
    virtual void __stdcall v65();
    virtual void __stdcall v66();
    virtual void __stdcall v67();
    virtual void __stdcall v68();
    virtual void __stdcall v69();
    virtual void __stdcall v70();
    virtual void __stdcall v71();
    virtual void __stdcall v72();
    virtual void __stdcall v73();
    virtual void __stdcall v74();
    virtual void __stdcall v75();
    virtual void __stdcall v76();
    virtual void __stdcall v77();
    virtual void __stdcall v78();
    virtual void __stdcall v79();
    virtual void __stdcall v80();
    virtual void __stdcall v81();
    virtual void __stdcall v82();
    virtual void __stdcall v83();
    virtual void __stdcall v84();
    virtual void __stdcall v85();
    virtual void __stdcall v86();
    virtual void __stdcall v87();
    virtual void __stdcall v88();
    virtual void __stdcall v89();
    virtual void __stdcall v90();
    virtual void __stdcall v91();
    virtual void __stdcall v92();
    virtual void __stdcall v93();
    virtual void __stdcall v94();
    virtual void __stdcall v95();
    virtual void __stdcall v96();
    virtual void __stdcall v97();
    virtual void __stdcall v98();
    virtual void __stdcall v99();
    virtual void __stdcall v100(int, int, int, int);
    virtual void __stdcall v101();
    virtual void __stdcall v102();
    virtual void __stdcall v103();
    virtual void __stdcall v104(int);
};
struct Flt
{
    operator unsigned int();
};
struct FUN_00b65660_s
{
    void BSShaderAccumulator_ClearRenderedGeometryCache();
};
struct FUN_00b630c0_s
{
    void BSShaderAccumulator_ClearBloodSplatter();
};
unsigned int __cdecl Main_GetWorldSceneGraph();
void* __cdecl BSShaderManager_GetRenderer();
BSTextureManager* __stdcall BSShaderManager_GetTextureManager();
struct S5;
struct S4
{
    S5* GetEffect_004ebbc0(int);
};
struct FUN_00876a00_Class
{
    void ImageSpaceEffectDepthOfField_ReturnMaskTexture();
};
struct FUN_00642890_Class
{
    void Sun_StopSunOcclusion();
};
using ::BSFaceGenNiNode;
using ::GO;
using ::MiddleLowProcess;
// Exe 0x00876850: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct MainOffset08View
{
    unsigned int GetFlags();
};
int __cdecl NiParallelUpdateTaskManager_Get();
int __cdecl NiParallelUpdateTaskManager_SignalRenderSema();
void __cdecl BSShaderManager_ReturnVelocityBuffers();
void __cdecl BSShaderManager_ReturnSceneDepthTexture();
void __cdecl BSBatchRenderer_EndPass();
void __cdecl ImageSpaceEffectHDR_ClearAdaptedLight();
void __cdecl BSShaderProperty_PreviousTransform_SaveCamera(void*);
struct FUN_004d61b0
{
    char pad[0x30];
    FUN_004d61b0(unsigned int, unsigned int, unsigned int, const char*, unsigned int, unsigned int, int, int);
};
extern unsigned char DAT_011f9440;
extern Flt DAT_011fa008;

// @fnv 0x00876850
// src: COMMUNITY 0x00876850
void FUN_00876850_shell::TESMain_DrawWorld_End(BSRenderedTexture* apRenderTexture, ImageSpaceManager* apImagespaceManager,
                                      ::NiRenderer* apRenderer, Sun* apSun)
{
    Dev9* pd3ddevice;
    int apCuller;
    unsigned int apSceneGraph;
    apSceneGraph = Main_GetWorldSceneGraph();
    apCuller = ((MiddleLowProcess*)apSceneGraph)->MiddleLowProcess::GetProcessInteger();
    if (apSun)
        ((FUN_00642890_Class*)apSun)->Sun_StopSunOcclusion();
    BSShaderProperty_PreviousTransform_SaveCamera(((BSFaceGenNiNode*)apSceneGraph)->::BSFaceGenNiNode::GetAnimationData());
    if (apRenderTexture)
        BSShaderManager_GetTextureManager()->AddRenderedTexture(reinterpret_cast<::BSRenderedTexture*>(apRenderTexture));
    ((FUN_00b65660_s*)(unsigned int)*(Flt*)((char*)this + 0x88))->BSShaderAccumulator_ClearRenderedGeometryCache();
    ((FUN_00b630c0_s*)(unsigned int)*(Flt*)((char*)this + 0x94))->BSShaderAccumulator_ClearBloodSplatter();
    BSShaderManager_ReturnSceneDepthTexture();
    BSShaderManager_ReturnVelocityBuffers();
    ((FUN_00876a00_Class*)((S4*)apImagespaceManager)->GetEffect_004ebbc0(4))->ImageSpaceEffectDepthOfField_ReturnMaskTexture();
    if (DAT_011f9440)
        ImageSpaceEffectHDR_ClearAdaptedLight();
    pd3ddevice = (Dev9*)((::NiRenderer*)BSShaderManager_GetRenderer())->NiXenonRenderer_GetD3DDevice();
    pd3ddevice->v104(0);
    pd3ddevice->v100(0, 0, 0, 0);
    if (NiParallelUpdateTaskManager_Get())
        NiParallelUpdateTaskManager_SignalRenderSema();
    if ((unsigned int)DAT_011fa008)
    {
        new FUN_004d61b0(((TESForm*)this)->GetFormID(), ((MainOffset08View*)this)->GetFlags(), (unsigned int)DAT_011fa008,
                         "Render Passes", 0x80000000, 0x80000000, 800, 600);
        (GO&)DAT_011fa008 = 0;
    }
    BSBatchRenderer_EndPass();
}
}  // namespace fnv_00876850

struct NiStream;
class IOManager;
namespace fnv_00877260 {
struct blob12
{
    char b[12];
};
using ::NiPoint3;
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
using ::NiUpdateData;
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];
using ::AutoMemContext;

class GridCell;
using ::NiNode;
using ::TESObjectREFR;
using ::NiMatrix3;
struct V3;
using ::NiAVObject;
::NiAVObject* __fastcall BSSceneGraph_GetCameraRoot(NiNode*);
unsigned int __cdecl Main_GetWorldSceneGraph();
struct FUN_0056fa00_S
{
    NiMatrix3 TESObjectREFR_GetOrientation();
};
using ::TES;
struct CP_008c48d0
{
    int GetPrevPath();
};
struct GlobalObject_0045cfe0
{
    int* Int();
};
extern GlobalObject_0045cfe0 g_011c63cc;
extern int g_TES;
struct FUN_0054cfd0_S
{
    bool TESObjectCELL_GetCOCPlacementInfo(::NiPoint3* apPos, ::NiPoint3* apRot);
};
struct FUN_00548230_S
{
    void FUN_00548230(TESObjectREFR* apRef, bool abFlag);
};
struct FUN_00456520_Class
{
    void IOManager_LoadAllQueuedPriorities();
};
extern IOManager* DAT_01202d98;
using ::AutoMemHelper;
struct PC_00605d70
{
    NiNode* GetNode(bool);
};
using ::NiAdditionalGeometryData;
struct FUN_00b5cbd0_S
{
    void FUN_00b5cbd0(NiNode* apNode);
};
struct FUN_00565730_S
{
    void TESObjectREFR_InitScript();
};
class PlayerVT
{
  public:
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf050();
    virtual void vf051();
    virtual void vf052();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual void vf064();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void vf077();
    virtual void vf078();
    virtual void vf079();
    virtual void vf080();
    virtual void vf081();
    virtual void vf082();
    virtual void vf083();
    virtual void vf084();
    virtual void vf085();
    virtual void vf086();
    virtual void vf087();
    virtual void vf088();
    virtual void vf089();
    virtual void vf090();
    virtual void vf091();
    virtual void vf092();
    virtual void vf093();
    virtual void vf094();
    virtual void vf095();
    virtual void vf096();
    virtual void vf097();
    virtual void vf098();
    virtual void vf099();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual void vf162();
    virtual void vf163();
    virtual void vf164();
    virtual void vf165();
    virtual void vf166();
    virtual void vf167();
    virtual void vf168();
    virtual void vf169();
    virtual void SetPositionV(::NiPoint3* apPos);
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual void SetZRotV(float afZ);
};
extern PlayerVT* _g_thePlayer;

// @fnv 0x00877260
// src: XBOX_PDB 0x00877260
void __cdecl Main_InitPlayerStart(::NiPoint3 apos)
{
    TESObjectCELL* pcell = (TESObjectCELL*)((CP_008c48d0*)g_TES)->GetPrevPath();
    ::NiPoint3 rot = ::NiPoint3::ZERO;
    if (!pcell)
    {
        pcell = *(TESObjectCELL**)((TES*)g_TES)
                     ->GetGridCell((unsigned int)*g_011c63cc.Int() >> 1, (unsigned int)*g_011c63cc.Int() >> 1);
    }
    if (pcell)
    {
        ((FUN_0054cfd0_S*)pcell)->TESObjectCELL_GetCOCPlacementInfo(&apos, &rot);
    }
    _g_thePlayer->SetZRotV(rot.z);
    _g_thePlayer->SetPositionV(&apos);
    if (pcell)
    {
        ((FUN_00548230_S*)pcell)->FUN_00548230((TESObjectREFR*)_g_thePlayer, false);
        ((FUN_00456520_Class*)DAT_01202d98)->IOManager_LoadAllQueuedPriorities();
        AutoMemHelper tempMemContext(0x34, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp",
                                     0x2612);
        ((::NiAVObject*)((PC_00605d70*)_g_thePlayer)->GetNode(false))->UpdateSceneObject();
        ((FUN_00b5cbd0_S*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))
            ->FUN_00b5cbd0(((PC_00605d70*)_g_thePlayer)->GetNode(false));
    }
    ((FUN_00565730_S*)_g_thePlayer)->TESObjectREFR_InitScript();
    BSSceneGraph_GetCameraRoot((NiNode*)Main_GetWorldSceneGraph())->NiAVObject_SetTranslate(reinterpret_cast<const ::NiPoint3&>(apos));
    BSSceneGraph_GetCameraRoot((NiNode*)Main_GetWorldSceneGraph())->SetLocalRotation((const ::NiMatrix3&)((FUN_0056fa00_S*)_g_thePlayer)->TESObjectREFR_GetOrientation());
    NiUpdateData UpdateData(0.0f, false, false);
    ((NiNode*)BSSceneGraph_GetCameraRoot((NiNode*)Main_GetWorldSceneGraph()))->Update(UpdateData);
}
}  // namespace fnv_00877260

struct GlobalObject_00869b10
{
    void RemoveAt(unsigned int);
};

struct FUN_0086bc10_t
{
    char pad[0xaf4];
    GlobalObject_00869b10 a;
    char pad2[0xb04 - 0xaf4 - 1];
    GlobalObject_00869b10 b;
    int FindFirstMatchingIndex(int);
    bool RemoveMatchingParallelEntries(int);
};

// Looks up arg via FUN_0086bc60; if found, removes that index from a and b and returns true, otherwise returns false.
// @fnv 0x0086bc10
// src: GUESS 0x0086bc10 (confidence: high)
bool FUN_0086bc10_t::RemoveMatchingParallelEntries(int arg)
{
    int idx = FindFirstMatchingIndex(arg);
    if (idx == -1)
        return false;
    a.RemoveAt(idx);
    b.RemoveAt(idx);
    return true;
}

namespace fnv_0086bc60 {
struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int);
};

struct FUN_0086bc60_t
{
    char m_data[0xaf4];
    Arr arr;
    int FindFirstMatchingIndex(int value);
};

// Searches arr for the first element equal to value and returns its index, or -1 if not found.
// @fnv 0x0086bc60
// src: GUESS 0x0086bc60 (confidence: medium)
int FUN_0086bc60_t::FindFirstMatchingIndex(int value)
{
    for (unsigned int i = 0; i < arr.GetSize(); i++)
    {
        if (*arr.GetAt(i) == value)
            return i;
    }
    return -1;
}
}  // namespace fnv_0086bc60

namespace fnv_00872940 {

using ::ImageSpaceManager;


struct NiParallelUpdateTaskManager
{
    void SetupTaskWorkers();
};

// Exe 0x00872940: unit-local Interface view; declarations and layout are preserved.
struct MainInterfaceView
{
  public:
    enum enumMenus
    {
        MENU_ID_0x3f6 = 0x3f6,
        MENU_ID_0x41e = 0x41e,
        MENU_ID_0x424 = 0x424,
        MENU_ID_0x432 = 0x432,
        MENU_ID_0x438 = 0x438,
        MENU_ID_0x439 = 0x439,
        MENU_ID_0x43a = 0x43a,
        MENU_ID_0x43b = 0x43b
    };

    static bool __cdecl IsMenuActive(enumMenus menuID, unsigned int parameter);
};

::NiRenderer* __cdecl NiXenonRenderer_GetRenderer(void);
ImageSpaceManager* __cdecl BSShaderManager_GetImageSpaceManager(void);
bool __cdecl TESRenderer_GetMultiSampleEnabled(void);
unsigned char __cdecl BSShaderManager_GetImageSpaceEffects(void);

void __cdecl Interface_DrawSurgeryMenu3D(void);
void __cdecl Interface_DrawLockpickMenu3D(void);
void __cdecl Interface_DrawSlotMachineMenu3D(void);
void __cdecl Interface_DrawBlackJackMenu3D(void);
void __cdecl Interface_DrawRouletteMenu3D(void);
void __cdecl Interface_DrawCaravanMenu3D(void);
void __cdecl LoveTesterMenu_Draw3DElements(void);
void __cdecl SPECIALBookMenu_Draw3DElements(void);

struct MainTarget
{
    int TESMain_DrawWorld_InitRenderTexture(::NiRenderer* prenderer, BSRenderedTexture* apDestination, int parameter, bool bmultiSampleEnabled);
    void TESMain_DrawWorld_CopyMenuBG(ImageSpaceManager* pimagespacemanager, ::NiRenderer* prenderer, bool bmultiSampleEnabled,
                      BSRenderedTexture* apDestination);
    void TESMain_DrawWorld_ImageSpace(bool bmultiSampleEnabled, int result, ::NiRenderer* prenderer, BSRenderedTexture* apDestination);
    void TESMain_DrawWorld_StopRenderTarget(bool bmultiSampleEnabled, BSRenderedTexture* apDestination);
    void TESMain_DrawWorld_End(int result, ImageSpaceManager* pimagespacemanager, ::NiRenderer* prenderer, int parameter);

    void Main_DrawWorldMenu3D(BSRenderedTexture* apDestination);
};

// @fnv 0x00872940
// src: XBOX_PDB 0x00872940
void MainTarget::Main_DrawWorldMenu3D(BSRenderedTexture* apDestination)
{
    ::NiRenderer* prenderer = NiXenonRenderer_GetRenderer();
    ImageSpaceManager* pimagespacemanager = BSShaderManager_GetImageSpaceManager();
    const bool bmultiSampleEnabled = TESRenderer_GetMultiSampleEnabled();
    int result;

    reinterpret_cast<NiParallelUpdateTaskManager*>(this)->SetupTaskWorkers();

    result = TESMain_DrawWorld_InitRenderTexture(prenderer, apDestination, 0, bmultiSampleEnabled);

    TESMain_DrawWorld_CopyMenuBG(pimagespacemanager, prenderer, bmultiSampleEnabled, apDestination);

    if (MainInterfaceView::IsMenuActive(MainInterfaceView::MENU_ID_0x41e, 0))
        Interface_DrawSurgeryMenu3D();

    if (MainInterfaceView::IsMenuActive(MainInterfaceView::MENU_ID_0x3f6, 0))
        Interface_DrawLockpickMenu3D();

    if (MainInterfaceView::IsMenuActive(MainInterfaceView::MENU_ID_0x438, 0))
        Interface_DrawSlotMachineMenu3D();

    if (MainInterfaceView::IsMenuActive(MainInterfaceView::MENU_ID_0x439, 0))
        Interface_DrawBlackJackMenu3D();

    if (MainInterfaceView::IsMenuActive(MainInterfaceView::MENU_ID_0x43a, 0))
        Interface_DrawRouletteMenu3D();

    if (MainInterfaceView::IsMenuActive(MainInterfaceView::MENU_ID_0x43b, 0))
        Interface_DrawCaravanMenu3D();

    if (MainInterfaceView::IsMenuActive(MainInterfaceView::MENU_ID_0x432, 0))
        LoveTesterMenu_Draw3DElements();

    if (BSShaderManager_GetImageSpaceEffects())
    {
        TESMain_DrawWorld_ImageSpace(bmultiSampleEnabled, result, prenderer, apDestination);
    }
    else if (apDestination)
    {
        TESMain_DrawWorld_StopRenderTarget(bmultiSampleEnabled, apDestination);
    }

    TESMain_DrawWorld_End(result, pimagespacemanager, prenderer, 0);

    if (MainInterfaceView::IsMenuActive(MainInterfaceView::MENU_ID_0x424, 0))
        SPECIALBookMenu_Draw3DElements();
}
}  // namespace fnv_00872940

class FUN_004505a0_target
{
  public:
    int Get();
};

class FUN_004505a0_cls
{
  public:
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
    FUN_004505a0_target* m_28;
    int Sky_GetLight();
};

// Returns the result of calling Get on m_28 if it is non-null, otherwise returns 0.
// @fnv 0x004505a0
// src: XBOX_PDB 0x004505a0
int FUN_004505a0_cls::Sky_GetLight()
{
    return (m_28 != 0) ? m_28->Get() : 0;
}

// FUN_0086ba90 candidate
struct OffScreenFrameHost
{
    virtual bool v00();
    virtual bool v01();
    virtual bool v02();
    virtual bool v03();
    virtual bool v04();
    virtual bool v05();
    virtual bool v06();
    virtual bool v07();
    virtual bool v08();
    virtual bool v09();
    virtual bool v0A();
    virtual bool v0B();
    virtual bool v0C();
    virtual bool v0D();
    virtual bool v0E();
    virtual bool v0F();
    virtual bool v10();
    virtual bool v11();
    virtual bool v12();
    virtual bool v13();
    virtual bool v14();
    virtual bool v15();
    virtual bool v16();
    virtual bool v17();
    virtual bool v18();
    virtual bool v19();
    virtual bool v1A();
    virtual bool v1B();
    virtual bool v1C();
    virtual bool v1D();
    virtual bool v1E();
    virtual bool v1F();
    virtual bool v20();
    virtual bool v21();
    virtual bool v22();
    virtual bool v23();
    virtual bool v24();
    virtual bool v25();
    virtual bool v26();
    virtual bool v27();
    virtual bool v28();
    virtual bool v29();
    virtual bool v2A();
    virtual bool v2B();
    virtual bool v2C();
    virtual bool v2D();
    virtual bool v2E();
    virtual bool v2F();
    virtual bool v30();
    virtual bool v31();
    virtual bool v32();
    virtual bool v33();
    virtual bool v34();
    virtual bool v35();
    virtual bool v36();
    virtual bool v37();
    virtual bool v38();
    virtual bool v39();
    virtual bool v3A();
    virtual bool v3B();
    virtual bool v3C();
    virtual bool v3D();
    virtual bool v3E();
    virtual bool v3F();
    virtual bool v40();
    virtual bool v41();
    virtual bool v42();
    virtual bool v43();
    virtual bool v44();
    virtual bool v45();
    virtual bool v46();
    virtual bool v47();
    virtual bool v48();
    virtual bool v49();
    virtual bool v4A();
    virtual bool v4B();
    virtual bool v4C();
    virtual bool v4D();
    virtual bool v4E();
    virtual bool v4F();
    virtual bool v50();
    virtual bool v51();
    virtual bool v52();
    virtual bool v53();
    virtual bool v54();
    virtual bool v55();
    virtual bool v56();
    virtual bool v57();
    virtual bool v58();
    virtual bool v59();
    virtual bool v5A();
    virtual bool v5B();
    virtual bool v5C();
    virtual bool v5D();
    virtual bool v5E();
    virtual bool v5F();
    virtual bool v60();
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int m_200;
    bool NiRenderer_Check_FrameState(const char* name, int flags);
    bool NiXenonRenderer_EndOffScreenFrame();
};
// Calls FUN_0086ba60 with "EndOffScreenFrame" and flags 2, then v60; on success clears m_200 and returns true.
// @fnv 0x0086ba90
// src: XBOX_PDB 0x0086ba90
bool OffScreenFrameHost::NiXenonRenderer_EndOffScreenFrame()
{
    if (!NiRenderer_Check_FrameState("EndOffScreenFrame", 2))
    {
        return false;
    }
    if (!v60())
    {
        return false;
    }
    m_200 = 0;
    return true;
}

class Sky86B
{
  public:
    virtual ~Sky86B();

    static Sky86B* pInstance;
};

class SkyOwner86B
{
  public:
    void Sky_Destroy();
};

// Deletes the Sky86B singleton instance and clears its static pointer.
// @fnv 0x0086be30
// src: COMMUNITY 0x0086be30
void SkyOwner86B::Sky_Destroy()
{
    delete Sky86B::pInstance;
    Sky86B::pInstance = 0;
}

class C86D4C0Timer
{
  public:
    int unk00;
    float m_fInterval;

    void BSTimer_ClampAt(unsigned int uiFrequency);
};

// Stores the timer interval as 1000 divided by uiFrequency, or 0 when uiFrequency is zero.
// @fnv 0x0086d4c0
// src: COMMUNITY 0x0086d4c0
void C86D4C0Timer::BSTimer_ClampAt(unsigned int uiFrequency)
{
    m_fInterval = uiFrequency ? 1000.0 / uiFrequency : 0.0;
}

class B86F190Process
{
  public:
    bool FUN_00483710();
};

class B86F190Actor
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void* GetNiNode();

    int FUN_00931850();
    B86F190Process* GetProcess();
};

class B86F190ActorList
{
  public:
    unsigned int GetCount(int iUnused);
    B86F190Actor* GetAt(unsigned int uiIndex);
};

class B86F190Manager
{
  public:
    B86F190ActorList* GetActors();
};

extern bool g_bB86F190Enabled;
extern bool g_bB86F190Pending;
extern B86F190Manager g_kB86F190Manager;

class B86F190Owner
{
  public:
    void TESMain_OnIdle_FixActorBones();
};

// @fnv 0x0086f190
// src: COMMUNITY 0x0086f190
void B86F190Owner::TESMain_OnIdle_FixActorBones()
{
    if (g_bB86F190Enabled)
    {
        if (g_bB86F190Pending)
        {
            B86F190ActorList* pkList = g_kB86F190Manager.GetActors();
            B86F190Actor* pkActor = 0;
            for (unsigned int i = 0; i < pkList->GetCount(0); i++)
            {
                pkActor = pkList->GetAt(i);
                if (pkActor && !pkActor->FUN_00931850() && pkActor->GetNiNode())
                {
                    B86F190Process* pkProcess = pkActor->GetProcess();
                    pkProcess->FUN_00483710();
                }
            }
            reinterpret_cast<B86F190Actor*>(g_thePlayer)->GetProcess()->FUN_00483710();
        }
        g_bB86F190Pending = false;
    }
    else
    {
        g_bB86F190Pending = true;
    }
}

extern "C" __declspec(dllimport) void __stdcall DebugBreak();

struct FUN_00872ed0_shell
{
    void NiCullingProcess_AppendVirtual(int param_1);
};

// @fnv 0x00872ed0
// src: XBOX_PDB 0x00872ed0
void FUN_00872ed0_shell::NiCullingProcess_AppendVirtual(int aiUnused)
{
    DebugBreak();
}


struct ScaleSource
{
    NiPoint3 GetScale3() const;
};

NiPoint3* __fastcall NiAVObject_GetWorldTranslate(ScaleSource* pObj);

extern NiPoint3 DAT_011a9490;
extern bool DAT_012003cc;
extern NiPoint3 DAT_012003d4;
extern NiPoint3 DAT_012003e0;

// Compares the object's current scale vectors against stored ones, sets DAT_012003cc when any component ratio exceeds 1.1, and stores the new vectors.
// @fnv 0x008744a0
// src: COMMUNITY 0x008744a0
void __cdecl ImageSpaceEffectFullScreenBlur_CheckCamera(ScaleSource* apScaleSource)
{
    if (apScaleSource == 0)
    {
        DAT_012003d4 = DAT_011a9490;
        DAT_012003cc = false;
        return;
    }
    NiPoint3 kCurA = *NiAVObject_GetWorldTranslate(apScaleSource);
    NiPoint3 kCurB = apScaleSource->GetScale3();
    NiPoint3 kDiffA_2 = kCurA - DAT_012003e0;
    NiPoint3 kDiffB5 = kCurB - DAT_012003d4;
    ::NiPoint3 kRatioA(kDiffA_2.x / DAT_012003e0.x, kDiffA_2.y / DAT_012003e0.y, kDiffA_2.z / DAT_012003e0.z);
    ::NiPoint3 kRatioB4(kDiffB5.x / DAT_012003d4.x, kDiffB5.y / DAT_012003d4.y, kDiffB5.z / DAT_012003d4.z);
    if (kRatioA.x > 1.1 || kRatioA.y > 1.1 || kRatioA.z > 1.1 || kRatioB4.x > 1.1 || kRatioB4.y > 1.1 ||
        kRatioB4.z > 1.1)
    {
        DAT_012003cc = true;
    }
    else
    {
        DAT_012003cc = false;
    }
    DAT_012003e0 = kCurA;
    DAT_012003d4 = kCurB;
}

struct FlagBlock_a234c0
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
    unsigned char flags[0x20];
};

struct FlagPair_a234c0
{
    FlagBlock_a234c0 first;
    FlagBlock_a234c0 second;
};

struct FlagOwner_a234c0
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
    FlagPair_a234c0 pairs[4];

    int Controls_GetJoyStickButton(int index, int bit, int mode);
};

// Compares the 0x80 bit of flags[bit] in the first and second flag blocks of pairs[index] according to mode and returns 1 if the mode's condition holds.
// @fnv 0x00a234c0
// src: COMMUNITY 0x00a234c0
int FlagOwner_a234c0::Controls_GetJoyStickButton(int index, int bit, int mode)
{
    FlagBlock_a234c0* first = &pairs[index].first;
    FlagBlock_a234c0* second6 = &pairs[index].second;
    int result5 = 0;
    switch (mode)
    {
    case 0:
        if (first->flags[bit] & 0x80)
            result5 = 1;
        break;
    case 1:
        if (!(second6->flags[bit] & 0x80) && (first->flags[bit] & 0x80))
            result5 = 1;
        break;
    case 2:
        if (!(first->flags[bit] & 0x80) && (second6->flags[bit] & 0x80))
            result5 = 1;
        break;
    case 3:
        if ((first->flags[bit] & 0x80) != (second6->flags[bit] & 0x80))
            result5 = 1;
        break;
    }
    return result5;
}

struct FUN_00a235f0_Row
{
    unsigned int m_value00;
    unsigned int m_value01;
    unsigned int m_value02;
    unsigned int m_value03;
    unsigned int m_value04;
    unsigned int m_value05;
    unsigned int m_value06;
    unsigned int m_value07;
    unsigned int m_value08;
    unsigned int m_value09;
    unsigned int m_value10;
    unsigned int m_value11;
    unsigned int m_value12;
    unsigned int m_value13;
    unsigned int m_value14;
    unsigned int m_value15;
    unsigned int m_value16;
    unsigned int m_value17;
    unsigned int m_value18;
    unsigned int m_value19;
    unsigned int m_value20;
    unsigned int m_value21;
    unsigned int m_value22;
    unsigned int m_value23;
    unsigned int m_value24;
    unsigned int m_value25;
    unsigned int m_value26;
    unsigned int m_value27;
    unsigned int m_value28;
    unsigned int m_value29;
    unsigned int m_value30;
    unsigned int m_value31;
    unsigned int m_field80;
    unsigned int m_field84;
    unsigned int m_field88;
    unsigned int m_field8c;
    unsigned int m_field90;
    unsigned int m_field94;
    unsigned int m_field98;
    unsigned int m_field9c;
};

struct FUN_00a235f0_Class
{
    unsigned int m_field00;
    unsigned int m_field04;
    unsigned int m_field08;
    unsigned int m_field0c;
    unsigned int m_field10;
    unsigned int m_field14;
    unsigned int m_field18;
    unsigned int m_field1c;
    unsigned int m_field20;
    unsigned int m_field24;
    unsigned int m_field28;
    unsigned int m_field2c;
    unsigned int m_field30;
    FUN_00a235f0_Row m_row;

    int __thiscall Controls_GetJoystickHat(int param_1, int param_2);
};

// Reads a 32-bit value from the row at offset param_1*0xa0+0x34, returns -1 if its low 16 bits are 0xffff, else value/0x1194+0x20.
// @fnv 0x00a235f0
// src: COMMUNITY 0x00a235f0
int __thiscall FUN_00a235f0_Class::Controls_GetJoystickHat(int aiRowIndex, int aiColumnIndex)
{
    unsigned int* row = reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + aiRowIndex * 0xa0 + 0x34);
    int value = static_cast<int>(row[aiColumnIndex + 8]);

    if (static_cast<unsigned short>(value & 0xffff) == 0xffff)
        return -1;

    return value / 0x1194 + 0x20;
}

struct FUN_00a23650_entry
{
    unsigned int m_flags;
    char unk04[0x244 - 4];
};

struct FUN_00a23650_cls
{
    char unk000[0x558];
    FUN_00a23650_entry m_entries[1];
    int GetEntryFlagTypeTwo(int index);
};

// Reads the byte at bits 8-15 of the flags of the entry at index and returns 2 for that case, otherwise -1.
// @fnv 0x00a23650
// src: GUESS 0x00a23650 (confidence: medium)
int FUN_00a23650_cls::GetEntryFlagTypeTwo(int index)
{
    switch ((unsigned char)((m_entries[index].m_flags >> 8) & 0xff))
    {
    case 2:
        return 2;
    }
    return -1;
}

struct FUN_00a236f0_data
{
    unsigned int m_iElementCount;
    unsigned int m_flags;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

class FUN_00a236f0_item
{
  public:
    virtual void __stdcall v00();
    virtual void __stdcall v01();
    virtual void __stdcall v02();
    virtual void __stdcall v03();
    virtual void __stdcall v04();
    virtual void __stdcall v05();
    virtual void __stdcall v06(int code, void* data);
};

class FUN_00a236f0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00a236f0_item* m_items[1];
    void Controls_SetDeviceRange(int index, int a2, int a3);
};

// Builds a data block with the given values and dispatches it to the item at index via v06 with code 4.
// @fnv 0x00a236f0
// src: COMMUNITY 0x00a236f0
void FUN_00a236f0_cls::Controls_SetDeviceRange(int index, int aiValue1, int aiValue2)
{
    FUN_00a236f0_item* pItem = m_items[index];
    FUN_00a236f0_data data;
    data.m_iElementCount = 0x18;
    data.m_flags = 0x10;
    data.unk0C = 0;
    data.unk08 = 0;
    data.unk10 = aiValue1;
    data.unk14 = aiValue2;
    pItem->v06(4, &data);
}

// DWORD: <windows.h>'s (read globally)
struct DIPROPHEADER
{
    DWORD dwSize;
    DWORD dwHeaderSize;
    DWORD dwObj;
    DWORD dwHow;
};
struct DIPROPDWORD
{
    DIPROPHEADER diph;
    DWORD dwData;
};
struct InputDevice
{
    virtual unsigned int __stdcall QueryInterface(void*, void**);
    virtual unsigned int __stdcall AddRef();
    virtual unsigned int __stdcall Release();
    virtual unsigned int __stdcall GetCapabilities(void*);
    virtual unsigned int __stdcall EnumObjects(void*, void*, DWORD);
    virtual unsigned int __stdcall GetProperty(const void*, DIPROPHEADER*);
    virtual unsigned int __stdcall SetProperty(const void*, const DIPROPHEADER*);
};
struct InputManager
{
    int unk00;
    int unk04;
    int unk08;
    InputDevice* devices[1];
    void Controls_SetDeviceDeadzone(int index, float value);
};
// Scales value by 10000 and sets property 5 on the input device at index via SetProperty.
// @fnv 0x00a23750
// src: COMMUNITY 0x00a23750
void InputManager::Controls_SetDeviceDeadzone(int index, float value)
{
    InputDevice* device = devices[index];
    DIPROPDWORD property;
    property.diph.dwSize = sizeof(DIPROPDWORD);
    property.diph.dwHeaderSize = sizeof(DIPROPHEADER);
    property.diph.dwHow = 0;
    property.diph.dwObj = 0;
    property.dwData = (int)(value * 10000.0);
    device->SetProperty((const void*)5, &property.diph);
}

class A237F0Object
{
  public:
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
    void* m_pResource;

    int Lookup(int iKey);
    int HasResourceWithLookupValueOne(int iKey);
};

// @fnv 0x00a237f0
// src: GUESS 0x00a237f0 (confidence: medium)
int A237F0Object::HasResourceWithLookupValueOne(int iKey)
{
    if (m_pResource && Lookup(iKey) == 1)
        return 1;
    return 0;
}

struct FUN_00a23820_tmp
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_00a23820_callee
{
  public:
    virtual void Unk_00(void);
    virtual void Unk_01(void);
    virtual void Unk_02(void);
    virtual void Unk_03(void);
    virtual void Unk_04(void);
    virtual void Unk_05(void);
    virtual void Unk_06(void);
    virtual void Unk_07(void);
    virtual void Unk_08(void);
    virtual void Unk_09(void);
    virtual int __stdcall Unk_0A(int size, FUN_00a23820_tmp* out, int* flag, int zero);
};

class FUN_00a23820_cls
{
  public:
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
    FUN_00a23820_callee* m_pCallee;
    int Controls_GetKeyState(int* out);
};

// Calls m_pCallee->Unk_0A with size 0x14 and, on success with flag set, writes tmp.unk00 to out and returns 2 or 1 depending on bit 0x80 of tmp.unk04.
// @fnv 0x00a23820
// src: COMMUNITY 0x00a23820
int FUN_00a23820_cls::Controls_GetKeyState(int* piOut)
{
    int pad;
    if ((m_pCallee != 0) != false)
    {
        int flag = 1;
        int r;
        FUN_00a23820_tmp tmp;
        if (m_pCallee->Unk_0A(0x14, &tmp, &flag, 0) == 0 && flag != 0)
        {
            r = ((tmp.unk04 & 0x80) != 0 ? -1 : 0) + 2;
            *piOut = tmp.unk00;
            return r;
        }
    }
    return 0;
}

typedef unsigned short WORD245;
typedef unsigned long DWORD245;

class InputManager245
{
  public:
    int GetKeyboardState(unsigned char ucKey, int iState);
    int GetMouseState(unsigned char ucKey, int iState);
    int GetOtherState(unsigned char ucKey, int iState);
    int GetJoystickButtonState(int iJoystick, unsigned char ucButton, int iState);
    int GetJoystickPOV(int iJoystick, int m_uiTrailingValue);
    int Controls_GetButtonState(int iControlSlot, unsigned char ucKey, int iState);

    int unk0000, unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C;
    int unk0020, unk0024, unk0028, unk002C, unk0030, unk0034, unk0038, unk003C;
    int unk0040, unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C;
    int unk0060, unk0064, unk0068, unk006C, unk0070, unk0074, unk0078, unk007C;
    int unk0080, unk0084, unk0088, unk008C, unk0090, unk0094, unk0098, unk009C;
    int unk00A0, unk00A4, unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC;
    int unk00C0, unk00C4, unk00C8, unk00CC, unk00D0, unk00D4, unk00D8, unk00DC;
    int unk00E0, unk00E4, unk00E8, unk00EC, unk00F0, unk00F4, unk00F8, unk00FC;
    int unk0100, unk0104, unk0108, unk010C, unk0110, unk0114, unk0118, unk011C;
    int unk0120, unk0124, unk0128, unk012C, unk0130, unk0134, unk0138, unk013C;
    int unk0140, unk0144, unk0148, unk014C, unk0150, unk0154, unk0158, unk015C;
    int unk0160, unk0164, unk0168, unk016C, unk0170, unk0174, unk0178, unk017C;
    int unk0180, unk0184, unk0188, unk018C, unk0190, unk0194, unk0198, unk019C;
    int unk01A0, unk01A4, unk01A8, unk01AC, unk01B0, unk01B4, unk01B8, unk01BC;
    int unk01C0, unk01C4, unk01C8, unk01CC, unk01D0, unk01D4, unk01D8, unk01DC;
    int unk01E0, unk01E4, unk01E8, unk01EC, unk01F0, unk01F4, unk01F8, unk01FC;
    int unk0200, unk0204, unk0208, unk020C, unk0210, unk0214, unk0218, unk021C;
    int unk0220, unk0224, unk0228, unk022C, unk0230, unk0234, unk0238, unk023C;
    int unk0240, unk0244, unk0248, unk024C, unk0250, unk0254, unk0258, unk025C;
    int unk0260, unk0264, unk0268, unk026C, unk0270, unk0274, unk0278, unk027C;
    int unk0280, unk0284, unk0288, unk028C, unk0290, unk0294, unk0298, unk029C;
    int unk02A0, unk02A4, unk02A8, unk02AC, unk02B0, unk02B4, unk02B8, unk02BC;
    int unk02C0, unk02C4, unk02C8, unk02CC, unk02D0, unk02D4, unk02D8, unk02DC;
    int unk02E0, unk02E4, unk02E8, unk02EC, unk02F0, unk02F4, unk02F8, unk02FC;
    int unk0300, unk0304, unk0308, unk030C, unk0310, unk0314, unk0318, unk031C;
    int unk0320, unk0324, unk0328, unk032C, unk0330, unk0334, unk0338, unk033C;
    int unk0340, unk0344, unk0348, unk034C, unk0350, unk0354, unk0358, unk035C;
    int unk0360, unk0364, unk0368, unk036C, unk0370, unk0374, unk0378, unk037C;
    int unk0380, unk0384, unk0388, unk038C, unk0390, unk0394, unk0398, unk039C;
    int unk03A0, unk03A4, unk03A8, unk03AC, unk03B0, unk03B4, unk03B8, unk03BC;
    int unk03C0, unk03C4, unk03C8, unk03CC, unk03D0, unk03D4, unk03D8, unk03DC;
    int unk03E0, unk03E4, unk03E8, unk03EC, unk03F0, unk03F4, unk03F8, unk03FC;
    int unk0400, unk0404, unk0408, unk040C, unk0410, unk0414, unk0418, unk041C;
    int unk0420, unk0424, unk0428, unk042C, unk0430, unk0434, unk0438, unk043C;
    int unk0440, unk0444, unk0448, unk044C, unk0450, unk0454, unk0458, unk045C;
    int unk0460, unk0464, unk0468, unk046C, unk0470, unk0474, unk0478, unk047C;
    int unk0480, unk0484, unk0488, unk048C, unk0490, unk0494, unk0498, unk049C;
    int unk04A0, unk04A4, unk04A8, unk04AC, unk04B0, unk04B4, unk04B8, unk04BC;
    int unk04C0, unk04C4, unk04C8, unk04CC, unk04D0, unk04D4, unk04D8, unk04DC;
    int unk04E0, unk04E4, unk04E8, unk04EC, unk04F0, unk04F4, unk04F8, unk04FC;
    int unk0500, unk0504, unk0508, unk050C, unk0510, unk0514, unk0518, unk051C;
    int unk0520, unk0524, unk0528, unk052C, unk0530, unk0534, unk0538, unk053C;
    int unk0540, unk0544, unk0548, unk054C, unk0550, unk0554, unk0558, unk055C;
    int unk0560, unk0564, unk0568, unk056C, unk0570, unk0574, unk0578, unk057C;
    int unk0580, unk0584, unk0588, unk058C, unk0590, unk0594, unk0598, unk059C;
    int unk05A0, unk05A4, unk05A8, unk05AC, unk05B0, unk05B4, unk05B8, unk05BC;
    int unk05C0, unk05C4, unk05C8, unk05CC, unk05D0, unk05D4, unk05D8, unk05DC;
    int unk05E0, unk05E4, unk05E8, unk05EC, unk05F0, unk05F4, unk05F8, unk05FC;
    int unk0600, unk0604, unk0608, unk060C, unk0610, unk0614, unk0618, unk061C;
    int unk0620, unk0624, unk0628, unk062C, unk0630, unk0634, unk0638, unk063C;
    int unk0640, unk0644, unk0648, unk064C, unk0650, unk0654, unk0658, unk065C;
    int unk0660, unk0664, unk0668, unk066C, unk0670, unk0674, unk0678, unk067C;
    int unk0680, unk0684, unk0688, unk068C, unk0690, unk0694, unk0698, unk069C;
    int unk06A0, unk06A4, unk06A8, unk06AC, unk06B0, unk06B4, unk06B8, unk06BC;
    int unk06C0, unk06C4, unk06C8, unk06CC, unk06D0, unk06D4, unk06D8, unk06DC;
    int unk06E0, unk06E4, unk06E8, unk06EC, unk06F0, unk06F4, unk06F8, unk06FC;
    int unk0700, unk0704, unk0708, unk070C, unk0710, unk0714, unk0718, unk071C;
    int unk0720, unk0724, unk0728, unk072C, unk0730, unk0734, unk0738, unk073C;
    int unk0740, unk0744, unk0748, unk074C, unk0750, unk0754, unk0758, unk075C;
    int unk0760, unk0764, unk0768, unk076C, unk0770, unk0774, unk0778, unk077C;
    int unk0780, unk0784, unk0788, unk078C, unk0790, unk0794, unk0798, unk079C;
    int unk07A0, unk07A4, unk07A8, unk07AC, unk07B0, unk07B4, unk07B8, unk07BC;
    int unk07C0, unk07C4, unk07C8, unk07CC, unk07D0, unk07D4, unk07D8, unk07DC;
    int unk07E0, unk07E4, unk07E8, unk07EC, unk07F0, unk07F4, unk07F8, unk07FC;
    int unk0800, unk0804, unk0808, unk080C, unk0810, unk0814, unk0818, unk081C;
    int unk0820, unk0824, unk0828, unk082C, unk0830, unk0834, unk0838, unk083C;
    int unk0840, unk0844, unk0848, unk084C, unk0850, unk0854, unk0858, unk085C;
    int unk0860, unk0864, unk0868, unk086C, unk0870, unk0874, unk0878, unk087C;
    int unk0880, unk0884, unk0888, unk088C, unk0890, unk0894, unk0898, unk089C;
    int unk08A0, unk08A4, unk08A8, unk08AC, unk08B0, unk08B4, unk08B8, unk08BC;
    int unk08C0, unk08C4, unk08C8, unk08CC, unk08D0, unk08D4, unk08D8, unk08DC;
    int unk08E0, unk08E4, unk08E8, unk08EC, unk08F0, unk08F4, unk08F8, unk08FC;
    int unk0900, unk0904, unk0908, unk090C, unk0910, unk0914, unk0918, unk091C;
    int unk0920, unk0924, unk0928, unk092C, unk0930, unk0934, unk0938, unk093C;
    int unk0940, unk0944, unk0948, unk094C, unk0950, unk0954, unk0958, unk095C;
    int unk0960, unk0964, unk0968, unk096C, unk0970, unk0974, unk0978, unk097C;
    int unk0980, unk0984, unk0988, unk098C, unk0990, unk0994, unk0998, unk099C;
    int unk09A0, unk09A4, unk09A8, unk09AC, unk09B0, unk09B4, unk09B8, unk09BC;
    int unk09C0, unk09C4, unk09C8, unk09CC, unk09D0, unk09D4, unk09D8, unk09DC;
    int unk09E0, unk09E4, unk09E8, unk09EC, unk09F0, unk09F4, unk09F8, unk09FC;
    int unk0A00, unk0A04, unk0A08, unk0A0C, unk0A10, unk0A14, unk0A18, unk0A1C;
    int unk0A20, unk0A24, unk0A28, unk0A2C, unk0A30, unk0A34, unk0A38, unk0A3C;
    int unk0A40, unk0A44, unk0A48, unk0A4C, unk0A50, unk0A54, unk0A58, unk0A5C;
    int unk0A60, unk0A64, unk0A68, unk0A6C, unk0A70, unk0A74, unk0A78, unk0A7C;
    int unk0A80, unk0A84, unk0A88, unk0A8C, unk0A90, unk0A94, unk0A98, unk0A9C;
    int unk0AA0, unk0AA4, unk0AA8, unk0AAC, unk0AB0, unk0AB4, unk0AB8, unk0ABC;
    int unk0AC0, unk0AC4, unk0AC8, unk0ACC, unk0AD0, unk0AD4, unk0AD8, unk0ADC;
    int unk0AE0, unk0AE4, unk0AE8, unk0AEC, unk0AF0, unk0AF4, unk0AF8, unk0AFC;
    int unk0B00, unk0B04, unk0B08, unk0B0C, unk0B10, unk0B14, unk0B18, unk0B1C;
    int unk0B20, unk0B24, unk0B28, unk0B2C, unk0B30, unk0B34, unk0B38, unk0B3C;
    int unk0B40, unk0B44, unk0B48, unk0B4C, unk0B50, unk0B54, unk0B58, unk0B5C;
    int unk0B60, unk0B64, unk0B68, unk0B6C, unk0B70, unk0B74, unk0B78, unk0B7C;
    int unk0B80, unk0B84, unk0B88, unk0B8C, unk0B90, unk0B94, unk0B98, unk0B9C;
    int unk0BA0, unk0BA4, unk0BA8, unk0BAC, unk0BB0, unk0BB4, unk0BB8, unk0BBC;
    int unk0BC0, unk0BC4, unk0BC8, unk0BCC, unk0BD0, unk0BD4, unk0BD8, unk0BDC;
    int unk0BE0, unk0BE4, unk0BE8, unk0BEC, unk0BF0, unk0BF4, unk0BF8, unk0BFC;
    int unk0C00, unk0C04, unk0C08, unk0C0C, unk0C10, unk0C14, unk0C18, unk0C1C;
    int unk0C20, unk0C24, unk0C28, unk0C2C, unk0C30, unk0C34, unk0C38, unk0C3C;
    int unk0C40, unk0C44, unk0C48, unk0C4C, unk0C50, unk0C54, unk0C58, unk0C5C;
    int unk0C60, unk0C64, unk0C68, unk0C6C, unk0C70, unk0C74, unk0C78, unk0C7C;
    int unk0C80, unk0C84, unk0C88, unk0C8C, unk0C90, unk0C94, unk0C98, unk0C9C;
    int unk0CA0, unk0CA4, unk0CA8, unk0CAC, unk0CB0, unk0CB4, unk0CB8, unk0CBC;
    int unk0CC0, unk0CC4, unk0CC8, unk0CCC, unk0CD0, unk0CD4, unk0CD8, unk0CDC;
    int unk0CE0, unk0CE4, unk0CE8, unk0CEC, unk0CF0, unk0CF4, unk0CF8, unk0CFC;
    int unk0D00, unk0D04, unk0D08, unk0D0C, unk0D10, unk0D14, unk0D18, unk0D1C;
    int unk0D20, unk0D24, unk0D28, unk0D2C, unk0D30, unk0D34, unk0D38, unk0D3C;
    int unk0D40, unk0D44, unk0D48, unk0D4C, unk0D50, unk0D54, unk0D58, unk0D5C;
    int unk0D60, unk0D64, unk0D68, unk0D6C, unk0D70, unk0D74, unk0D78, unk0D7C;
    int unk0D80, unk0D84, unk0D88, unk0D8C, unk0D90, unk0D94, unk0D98, unk0D9C;
    int unk0DA0, unk0DA4, unk0DA8, unk0DAC, unk0DB0, unk0DB4, unk0DB8, unk0DBC;
    int unk0DC0, unk0DC4, unk0DC8, unk0DCC, unk0DD0, unk0DD4, unk0DD8, unk0DDC;
    int unk0DE0, unk0DE4, unk0DE8, unk0DEC, unk0DF0, unk0DF4, unk0DF8, unk0DFC;
    int unk0E00, unk0E04, unk0E08, unk0E0C, unk0E10, unk0E14, unk0E18, unk0E1C;
    int unk0E20, unk0E24, unk0E28, unk0E2C, unk0E30, unk0E34, unk0E38, unk0E3C;
    int unk0E40, unk0E44, unk0E48, unk0E4C, unk0E50, unk0E54, unk0E58, unk0E5C;
    int unk0E60, unk0E64, unk0E68, unk0E6C, unk0E70, unk0E74, unk0E78, unk0E7C;
    int unk0E80, unk0E84, unk0E88, unk0E8C, unk0E90, unk0E94, unk0E98, unk0E9C;
    int unk0EA0, unk0EA4, unk0EA8, unk0EAC, unk0EB0, unk0EB4, unk0EB8, unk0EBC;
    int unk0EC0, unk0EC4, unk0EC8, unk0ECC, unk0ED0, unk0ED4, unk0ED8, unk0EDC;
    int unk0EE0, unk0EE4, unk0EE8, unk0EEC, unk0EF0, unk0EF4, unk0EF8, unk0EFC;
    int unk0F00, unk0F04, unk0F08, unk0F0C, unk0F10, unk0F14, unk0F18, unk0F1C;
    int unk0F20, unk0F24, unk0F28, unk0F2C, unk0F30, unk0F34, unk0F38, unk0F3C;
    int unk0F40, unk0F44, unk0F48, unk0F4C, unk0F50, unk0F54, unk0F58, unk0F5C;
    int unk0F60, unk0F64, unk0F68, unk0F6C, unk0F70, unk0F74, unk0F78, unk0F7C;
    int unk0F80, unk0F84, unk0F88, unk0F8C, unk0F90, unk0F94, unk0F98, unk0F9C;
    int unk0FA0, unk0FA4, unk0FA8, unk0FAC, unk0FB0, unk0FB4, unk0FB8, unk0FBC;
    int unk0FC0, unk0FC4, unk0FC8, unk0FCC, unk0FD0, unk0FD4, unk0FD8, unk0FDC;
    int unk0FE0, unk0FE4, unk0FE8, unk0FEC, unk0FF0, unk0FF4, unk0FF8, unk0FFC;
    int unk1000, unk1004, unk1008, unk100C, unk1010, unk1014, unk1018, unk101C;
    int unk1020, unk1024, unk1028, unk102C, unk1030, unk1034, unk1038, unk103C;
    int unk1040, unk1044, unk1048, unk104C, unk1050, unk1054, unk1058, unk105C;
    int unk1060, unk1064, unk1068, unk106C, unk1070, unk1074, unk1078, unk107C;
    int unk1080, unk1084, unk1088, unk108C, unk1090, unk1094, unk1098, unk109C;
    int unk10A0, unk10A4, unk10A8, unk10AC, unk10B0, unk10B4, unk10B8, unk10BC;
    int unk10C0, unk10C4, unk10C8, unk10CC, unk10D0, unk10D4, unk10D8, unk10DC;
    int unk10E0, unk10E4, unk10E8, unk10EC, unk10F0, unk10F4, unk10F8, unk10FC;
    int unk1100, unk1104, unk1108, unk110C, unk1110, unk1114, unk1118, unk111C;
    int unk1120, unk1124, unk1128, unk112C, unk1130, unk1134, unk1138, unk113C;
    int unk1140, unk1144, unk1148, unk114C, unk1150, unk1154, unk1158, unk115C;
    int unk1160, unk1164, unk1168, unk116C, unk1170, unk1174, unk1178, unk117C;
    int unk1180, unk1184, unk1188, unk118C, unk1190, unk1194, unk1198, unk119C;
    int unk11A0, unk11A4, unk11A8, unk11AC, unk11B0, unk11B4, unk11B8, unk11BC;
    int unk11C0, unk11C4, unk11C8, unk11CC, unk11D0, unk11D4, unk11D8, unk11DC;
    int unk11E0, unk11E4, unk11E8, unk11EC, unk11F0, unk11F4, unk11F8, unk11FC;
    int unk1200, unk1204, unk1208, unk120C, unk1210, unk1214, unk1218, unk121C;
    int unk1220, unk1224, unk1228, unk122C, unk1230, unk1234, unk1238, unk123C;
    int unk1240, unk1244, unk1248, unk124C, unk1250, unk1254, unk1258, unk125C;
    int unk1260, unk1264, unk1268, unk126C, unk1270, unk1274, unk1278, unk127C;
    int unk1280, unk1284, unk1288, unk128C, unk1290, unk1294, unk1298, unk129C;
    int unk12A0, unk12A4, unk12A8, unk12AC, unk12B0, unk12B4, unk12B8, unk12BC;
    int unk12C0, unk12C4, unk12C8, unk12CC, unk12D0, unk12D4, unk12D8, unk12DC;
    int unk12E0, unk12E4, unk12E8, unk12EC, unk12F0, unk12F4, unk12F8, unk12FC;
    int unk1300, unk1304, unk1308, unk130C, unk1310, unk1314, unk1318, unk131C;
    int unk1320, unk1324, unk1328, unk132C, unk1330, unk1334, unk1338, unk133C;
    int unk1340, unk1344, unk1348, unk134C, unk1350, unk1354, unk1358, unk135C;
    int unk1360, unk1364, unk1368, unk136C, unk1370, unk1374, unk1378, unk137C;
    int unk1380, unk1384, unk1388, unk138C, unk1390, unk1394, unk1398, unk139C;
    int unk13A0, unk13A4, unk13A8, unk13AC, unk13B0, unk13B4, unk13B8, unk13BC;
    int unk13C0, unk13C4, unk13C8, unk13CC, unk13D0, unk13D4, unk13D8, unk13DC;
    int unk13E0, unk13E4, unk13E8, unk13EC, unk13F0, unk13F4, unk13F8, unk13FC;
    int unk1400, unk1404, unk1408, unk140C, unk1410, unk1414, unk1418, unk141C;
    int unk1420, unk1424, unk1428, unk142C, unk1430, unk1434, unk1438, unk143C;
    int unk1440, unk1444, unk1448, unk144C, unk1450, unk1454, unk1458, unk145C;
    int unk1460, unk1464, unk1468, unk146C, unk1470, unk1474, unk1478, unk147C;
    int unk1480, unk1484, unk1488, unk148C, unk1490, unk1494, unk1498, unk149C;
    int unk14A0, unk14A4, unk14A8, unk14AC, unk14B0, unk14B4, unk14B8, unk14BC;
    int unk14C0, unk14C4, unk14C8, unk14CC, unk14D0, unk14D4, unk14D8, unk14DC;
    int unk14E0, unk14E4, unk14E8, unk14EC, unk14F0, unk14F4, unk14F8, unk14FC;
    int unk1500, unk1504, unk1508, unk150C, unk1510, unk1514, unk1518, unk151C;
    int unk1520, unk1524, unk1528, unk152C, unk1530, unk1534, unk1538, unk153C;
    int unk1540, unk1544, unk1548, unk154C, unk1550, unk1554, unk1558, unk155C;
    int unk1560, unk1564, unk1568, unk156C, unk1570, unk1574, unk1578, unk157C;
    int unk1580, unk1584, unk1588, unk158C, unk1590, unk1594, unk1598, unk159C;
    int unk15A0, unk15A4, unk15A8, unk15AC, unk15B0, unk15B4, unk15B8, unk15BC;
    int unk15C0, unk15C4, unk15C8, unk15CC, unk15D0, unk15D4, unk15D8, unk15DC;
    int unk15E0, unk15E4, unk15E8, unk15EC, unk15F0, unk15F4, unk15F8, unk15FC;
    int unk1600, unk1604, unk1608, unk160C, unk1610, unk1614, unk1618, unk161C;
    int unk1620, unk1624, unk1628, unk162C, unk1630, unk1634, unk1638, unk163C;
    int unk1640, unk1644, unk1648, unk164C, unk1650, unk1654, unk1658, unk165C;
    int unk1660, unk1664, unk1668, unk166C, unk1670, unk1674, unk1678, unk167C;
    int unk1680, unk1684, unk1688, unk168C, unk1690, unk1694, unk1698, unk169C;
    int unk16A0, unk16A4, unk16A8, unk16AC, unk16B0, unk16B4, unk16B8, unk16BC;
    int unk16C0, unk16C4, unk16C8, unk16CC, unk16D0, unk16D4, unk16D8, unk16DC;
    int unk16E0, unk16E4, unk16E8, unk16EC, unk16F0, unk16F4, unk16F8, unk16FC;
    int unk1700, unk1704, unk1708, unk170C, unk1710, unk1714, unk1718, unk171C;
    int unk1720, unk1724, unk1728, unk172C, unk1730, unk1734, unk1738, unk173C;
    int unk1740, unk1744, unk1748, unk174C, unk1750, unk1754, unk1758, unk175C;
    int unk1760, unk1764, unk1768, unk176C, unk1770, unk1774, unk1778, unk177C;
    int unk1780, unk1784, unk1788, unk178C, unk1790, unk1794, unk1798, unk179C;
    int unk17A0, unk17A4, unk17A8, unk17AC, unk17B0, unk17B4, unk17B8, unk17BC;
    int unk17C0, unk17C4, unk17C8, unk17CC, unk17D0, unk17D4, unk17D8, unk17DC;
    int unk17E0, unk17E4, unk17E8, unk17EC, unk17F0, unk17F4, unk17F8, unk17FC;
    int unk1800, unk1804, unk1808, unk180C, unk1810, unk1814, unk1818, unk181C;
    int unk1820, unk1824, unk1828, unk182C, unk1830, unk1834, unk1838, unk183C;
    int unk1840, unk1844, unk1848, unk184C, unk1850, unk1854, unk1858, unk185C;
    int unk1860, unk1864, unk1868, unk186C, unk1870, unk1874, unk1878, unk187C;
    int unk1880, unk1884, unk1888, unk188C, unk1890, unk1894, unk1898, unk189C;
    int unk18A0, unk18A4, unk18A8, unk18AC, unk18B0, unk18B4, unk18B8, unk18BC;
    int unk18C0, unk18C4, unk18C8, unk18CC, unk18D0, unk18D4, unk18D8, unk18DC;
    int unk18E0, unk18E4, unk18E8, unk18EC, unk18F0;
    int m_iNumJoysticks;
};

// Dispatches a key/button state query to the keyboard, mouse, other, or joystick handlers based on the device id, returning 0 for unknown devices.
// @fnv 0x00a24560
// src: COMMUNITY 0x00a24560
int InputManager245::Controls_GetButtonState(int iControlSlot, unsigned char ucKeyCode, int iState)
{
    switch (iControlSlot)
    {
    case 0xff:
        return 0;
    case 0:
        return GetKeyboardState(ucKeyCode, iState);
    case 1:
        return GetMouseState(ucKeyCode, iState);
    case 3:
        return GetOtherState(ucKeyCode, iState);
    }

    if (iControlSlot - 2 >= m_iNumJoysticks)
        return 0;

    if (ucKeyCode < 0x20)
    {
        return GetJoystickButtonState(iControlSlot - 2, ucKeyCode, iState);
    }
    else
    {
        int iPOV = GetJoystickPOV(iControlSlot - 2, ((WORD245)((((DWORD245)(ucKeyCode)) >> 16) & 0xffff)));
        int iValue = ((WORD245)(((DWORD245)(ucKeyCode)) & 0xffff));
        if (iPOV == iValue)
            return 1;
    }
    return 0;
}

struct FUN_00ec1800_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int hObject;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    bool m_bQueryPending;
    void __thiscall MoviePlayer_WaitForSequenceToEnd();
};

// WaitForSingleObject: <windows.h>'s (read globally)

// @fnv 0x00ec1800
// src: COMMUNITY 0x00ec1800
void __thiscall FUN_00ec1800_cls::MoviePlayer_WaitForSequenceToEnd()
{
    if (hObject != 0)
    {
        m_bQueryPending = true;
        WaitForSingleObject((HANDLE)hObject, 0xffffffffu);
        hObject = 0;
        m_bQueryPending = false;
    }
}

class TileList
{
  public:
    void* GetHeadPos() const;
    ::Tile*& GetNext(void*&);
    ::Tile* Remove(::Tile*&);
};
InterfaceManager* __cdecl InterfaceManager_GetSingleton();
extern "C" bool s_bAllowDetach;
void __cdecl SPECIALBookMenu_Close();
void __cdecl LoveTesterMenu_Close();
bool __cdecl IsStartMenuFlag1Set();

// Enables detach, walks the root tile's children and removes tiles by menu ID, calling handlers for the book and love tester menus, then disables detach.
// @fnv 0x00706320
// src: XBOX_PDB 0x00706320
void __cdecl Interface_CloseAllSupportMenus(int)
{
    s_bAllowDetach = true;
    ::Tile* root = InterfaceManager_GetSingleton()->CombatController_GetCombatState();
    {
        void* position = reinterpret_cast<TileList&>(root->m_kChildTileList).GetHeadPos();
        while (position)
        {
            ::Tile* tile = reinterpret_cast<TileList&>(root->m_kChildTileList).GetNext(position);
            if (tile && tile->GetMenu())
            {
                unsigned int id = tile->GetMenu()->GetClass();
                switch (id)
                {
                case 1002:
                case 1003:
                case 1004:
                case 1007:
                case 1023:
                case 1035:
                case 1061:
                    break;
                case 1060: {
                    SPECIALBookMenu* pBookMenu = tile ? dynamic_cast<SPECIALBookMenu*>(tile->GetMenu()) : 0;
                    if (pBookMenu)
                        SPECIALBookMenu_Close();
                    delete reinterpret_cast<TileList&>(root->m_kChildTileList).Remove(tile);
                    break;
                }
                case 1074: {
                    LoveTesterMenu* pLoveMenu = tile ? dynamic_cast<LoveTesterMenu*>(tile->GetMenu()) : 0;
                    if (pLoveMenu)
                        LoveTesterMenu_Close();
                    delete reinterpret_cast<TileList&>(root->m_kChildTileList).Remove(tile);
                    break;
                }
                case 1013:
                    if (IsStartMenuFlag1Set())
                    {
                        delete reinterpret_cast<TileList&>(root->m_kChildTileList).Remove(tile);
                    }
                    break;
                default:
                    delete reinterpret_cast<TileList&>(root->m_kChildTileList).Remove(tile);
                    break;
                }
            }
        }
    }
    s_bAllowDetach = false;
}

struct Manager86
{
    virtual void First();
    virtual void Second();
    virtual void Stop();
};
struct Device86
{
    virtual int __stdcall QueryInterface(void*, void*);
    virtual int __stdcall AddRef();
    virtual int __stdcall Release();
    virtual int __stdcall TestCooperativeLevel();
};
struct Rect86
{
    int left;
    int top;
    int right;
    int bottom;
};
struct Point86
{
    float x;
    float y;
    float z;
    void SetComponents(float, float, float);
};
struct Receiver86
{
    Receiver86* FUN_00afdc60(const char*, int, int);
    Receiver86* FUN_0086c160(unsigned int, unsigned int);
    Receiver86* FUN_007005d0();

    void FUN_0066b0d0(int);
    void BSTextureManager_ReturnRenderedTexture(int);
    void CancelAllFiles_00448420();
    void AILinearTaskThreadManager_Kill();
    Receiver86* FUN_008d8520();
    void Sky_Destroy();
    void NavMeshObstacleManager_Release();
    void* FUN_0086bee0(unsigned int);
    void* FUN_0086bf10(unsigned int);
    void* FUN_0086bf40(unsigned int);
    void ReleaseAndClearObject();
    void* FUN_00717e50();
    void INISettingCollection_SaveAll(void*);
    void RemoveEntryFromBothLists(void*);
    void RemoveMatchingParallelEntries(void*);
    int MemoryManager_OutputDebugInfo(void*, int);

    void Object_AdvanceStateAtOffset5C_0086bda0();
    Receiver86* TESDataHandler_GetWorldSpaceList();
    int* FUN_006815c0();
    void TES_SetWorldSpace(int);
    void ClearIdleAnims();
    void ExtraDismemberedLimbs_SetEaten(int);
    void ProcessLists_InitPackageLocations();
    void FUN_004614e0();
    void BGSSaveLoadGame_SetGlobalAllowChanges(int);
    void FUN_00483710();
    void FUN_004f15a0(int);
    int FUN_008d6f30();
    void FUN_004650a0(int);
    void MoviePlayer_WaitForSequenceToEnd();
    void IOManager_LoadAllQueuedPriorities();
    int FUN_0044ddc0();
    unsigned char TES_CellTestRunning();
    int Modelloader_GetReferencedThis();
    Device86* NiXenonRenderer_GetD3DDevice();
    void NiXenonRenderer_BeginOffScreenFrame();
    void NiXenonRenderer_EndOffScreenFrame();
    void Main_OnIdle();
    void UnPauseSynchTimer();
    void BSWin32Audio_Pause();
    void FUN_00ad7740(int);
    unsigned int TESMain_GetThread();
    Receiver86* Main_QDrawWorldAccum();
    void BSShaderAccumulator_ClearSunQueries();
    void BGSDecalManager_ClearPendingQueries();
    void VATSEffect_FreeOcclusionQueries();
    bool FUN_005dc960();
    unsigned char Main_GameReset();
    void Main_PerformGameReset(int);

    void BSFileCache_SetFileCacheList(const char*, const char*);
    void NiXenonRenderer_LockRenderer();
    void NiDX9Renderer_AddLostDeviceNotificationFunc(void*, int);
    void NiDX9Renderer_AddResetNotificationFunc(void*, int);
    void NiXenonRenderer_UnlockRenderer();
    void MoviePlayer_StartSequence(const char*, int, int, int, int, float);
    void Main_InitTES(Receiver86*);
    int FUN_006629f0();
    void FUN_006eb8c0();
    void NavMeshObstacleManager_CreateListeners();
    void FUN_008c7290();
    void TESMain_InitRenderer();
    void TESMain_InitSceneGraph();
    void TESMain_SetActive(int);

    Receiver86* BSSystemUtility_GetMsgDialogUtility();
    void FUN_004fb090(void*);
    void FUN_006ecd40(int(__cdecl*)(...));
    void SteamAPI_SetNoCloud(int);
    void j_ReadSettingsFromFile_SettingCollection_VSetting_QEAA_NPEBD_Z(const void*);
};
struct Setting86
{
    unsigned char* FUN_00408d60() throw();
    int* Int() throw();
    const char* FUN_00403df0() throw();
};
extern Setting86 g_011dec88, g_011dee20, g_011ded74;
struct SystemInfo86
{
    unsigned int architecture;
    void* pageSize;
    void* minAddress;
    void* maxAddress;
    unsigned int mask;
    unsigned int processors;
    unsigned int type;
    unsigned int granularity;
    unsigned short level;
    unsigned short revision;
};
struct Context86
{
    int previous;
    void FUN_00404eb0(int, bool, void*, int);
    void FUN_00404f00(int, bool, void*, int);
    void FUN_00404f70();
    void FUN_00404ee0();
};
struct Text86
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void FUN_008783c0(void*);
    void FUN_008784d0();
};
extern Setting86 g_011dee78, g_011ded2c, g_011dece4, g_011dee6c, g_011de72c, g_011d73e4;
extern Receiver86* DAT_0126fac4;
struct WindowClass86
{
    unsigned int style;
    void* procedure;
    int classExtra;
    int windowExtra;
    unsigned int instance;
    unsigned int icon;
    unsigned int cursor;
    unsigned int background;
    unsigned int menu;
    char* className;
};
struct Message86
{
    unsigned int window;
    unsigned int id;
    unsigned int wparam;
    unsigned int lparam;
    unsigned int time;
    int x;
    int y;
};
void* __cdecl operator new(unsigned int);
extern Receiver86* g_dataHandler;
extern Receiver86* g_TESSaveLoadGame;
extern Receiver86* g_BGSSaveLoadGame;
extern Receiver86 g_011deb30;
extern Setting86 g_011deed8;
extern Receiver86 g_011ded3c, g_011dec64, g_011deb38;
extern Receiver86* g_modelLoader;
typedef int(__cdecl* code)(...);

int __cdecl FUN_00408d60(...);
int __cdecl MessageBoxA_0(...);
int __cdecl MessageHandler_Init(...);
int __cdecl MessageHandler_SetAllWarningFileNames(...);
int __cdecl MessageHandler_SetProgramFlowFileName(...);
int __cdecl MessageHandler_SetProgrammerOutputFileName(...);
int __cdecl MessageHandler_SetCrashTraceFileName(...);
int __cdecl FUN_00876ad0(...);
int __cdecl FillUserNameGlobal(...);
Receiver86* __cdecl FUN_00af2640();
int __cdecl FUN_004fb090(...);
int __cdecl SystemUtilityDialogIdleCallback(...);
int __cdecl BSSystemUtility_GetMsgDialogUtility(...);
int __cdecl FUN_006ecd40(...);
int __cdecl NiStaticDataManager_Init(...);
int __cdecl BSMain_InitSDM(...);
int __cdecl FUN_004b7920(...);
int __cdecl Menu_InitSDM(...);
int __cdecl FUN_00bc2940(...);
int __cdecl TES_InitSDM(...);
int __cdecl SetMemContext_00404f30(...);
int __cdecl BSFadeNode_GetLinkedActorAlpha_Set(...);
int __cdecl BSFadeNode_GetLinkedActorAlpha(...);
int __cdecl BSSoundHandle_SetAddMovingSoundCallback(...);
int __cdecl NiSourceTexture_SetDestroyAppDataFlag(...);
int __cdecl BSStream_InitLoaders(...);
int __cdecl FUN_00404eb0(...);
int __cdecl FOCollisionListener_GetSingleton(...);
int __cdecl FUN_00404f70(...);

int __cdecl BSTexturePalette_Init(...);
int __cdecl FUN_006ff610(...);
int __cdecl FUN_00ecc071(...);
Receiver86* __cdecl SteamAPICallbacks_GetSingleton();
int __cdecl SteamAPI_SetNoCloud(...);
Receiver86* __cdecl SettingT_RegSettingCollection_QCollection(...);
int __cdecl j_ReadSettingsFromFile_SettingCollection_VSetting_QEAA_NPEBD_Z(...);
Receiver86* __cdecl FUN_0044f560(...);
int __cdecl BSUtilities_GetPersonalPath(...);
int __cdecl FUN_00406d30(...);
int __cdecl FUN_00406d50(...);
Receiver86* __cdecl FUN_004de490(...);
Receiver86* __cdecl SettingT_RendererSettingCollection_GetCollection(...);
unsigned char __cdecl ProcessCustomINI();
int __cdecl Renderer_Kill(...);
Manager86* __cdecl FUN_00b00a00();
int __cdecl GetInstalledPathRegistryKey(...);
int __cdecl FUN_00404ee0(...);
int __cdecl FUN_00403df0(...);
Receiver86* __cdecl FUN_00aff100();
int __cdecl BSFileCache_SetFileCacheList(...);

int __cdecl FileFinder_AddPath_0(...);
int __cdecl ProgramFlow(...);
int __cdecl Object_AdvanceStateAtOffset5C_0086bda0(...);
int __cdecl SetupArchiveSettings_AndLoadBSAs(...);

int __cdecl TESMain_InitRenderer(...);
Receiver86* __cdecl NiXenonRenderer_GetRenderer();
int __cdecl NiXenonRenderer_LockRenderer(...);
int __cdecl SUB_005d4a40(...);
int __cdecl NiDX9Renderer_AddLostDeviceNotificationFunc(...);
int __cdecl NiDX9Renderer_AddResetNotificationFunc(...);
int __cdecl TESMain_InitSceneGraph(...);
int __cdecl FUN_00702250(...);
int __cdecl BSFaceGenManager_InitializeSystem(...);
int __cdecl TESMain_SetActive(...);
int __cdecl NavMeshRender_InitSingleton(...);
int __cdecl TESMain_ImagespaceInit(...);
int __cdecl NiXenonRenderer_UnlockRenderer(...);
int __cdecl BGSMoviePlayer_Create(...);
int __cdecl MoviePlayer_StartSequence(...);
int __cdecl Main_InitTES(...);
int __cdecl FUN_006629f0(...);
int __cdecl BSFaceGenManager_SetWorldCamera(...);
int __cdecl BSTreeManager_SetCamera(...);
Receiver86* __cdecl AILinearTaskThreadManager_GetSingleton();
int __cdecl FUN_008c7290(...);
int __cdecl Pathing_Init(...);
Receiver86* __cdecl GetPathManager();
int __cdecl FUN_006eb8c0(...);
Receiver86* __cdecl GetNavMeshObstacleManager();
int __cdecl NavMeshObstacleManager_CreateListeners(...);
int __cdecl FUN_004e0540(...);
int __cdecl FUN_004deb30(...);
int __cdecl SetComponents(...);
int __cdecl TESDataHandler_GetWorldSpaceList(...);
int __cdecl FUN_006815c0(...);
int __cdecl TES_SetWorldSpace(...);
int __cdecl ClearIdleAnims(...);
int __cdecl ExtraDismemberedLimbs_SetEaten(...);
int __cdecl ProcessLists_InitPackageLocations(...);
int __cdecl FUN_004614e0(...);
int __cdecl BGSSaveLoadGame_SetGlobalAllowChanges(...);
int __cdecl Main_InitStartCell(...);
int __cdecl Main_InitPlayerStart(...);
int __cdecl FUN_007022c0(...);
int __cdecl FUN_00483710(...);
int __cdecl FUN_004f15a0(...);
int __cdecl ArchiveManager_SetStartupFinished(...);
int __cdecl FUN_008d6f30(...);
int __cdecl FUN_004650a0(...);
int __cdecl Interface_CreateMainMenu(...);
int __cdecl MoviePlayer_WaitForSequenceToEnd(...);
int __cdecl IOManager_LoadAllQueuedPriorities(...);
int __cdecl ourMemset(...);
int __cdecl FUN_0044ddc0(...);
int __cdecl TES_CellTestRunning(...);
int __cdecl Modelloader_GetReferencedThis(...);
int __cdecl NiXenonRenderer_GetD3DDevice(...);
int __cdecl NiXenonRenderer_BeginOffScreenFrame(...);
int __cdecl NiXenonRenderer_EndOffScreenFrame(...);
int __cdecl Main_OnIdle(...);
Receiver86* __cdecl BSAudio_QInstance();
int __cdecl UnPauseSynchTimer(...);
int __cdecl FalloutAudioMedia_MediaMenuUnPause(...);
int __cdecl FUN_00832ad0(...);
int __cdecl FUN_00ad7740(...);
unsigned char __cdecl TESRenderer_GetFullScreen();
int __cdecl FUN_0078d020(...);
int __cdecl TESMain_GetThread(...);
int __cdecl FUN_0078cfc0(...);
int __cdecl BSWin32Audio_Pause(...);
int __cdecl FalloutAudioMedia_MediaMenuPause(...);
int __cdecl Main_QDrawWorldAccum(...);
int __cdecl BSShaderAccumulator_ClearSunQueries(...);
Receiver86* __cdecl FUN_0049fef0();
int __cdecl BGSDecalManager_ClearPendingQueries(...);
Receiver86* __cdecl Interface_GetVATSEffect();
int __cdecl VATSEffect_FreeOcclusionQueries(...);
int __cdecl FUN_005dc960(...);
int __cdecl Main_GameReset(...);
int __cdecl Main_PerformGameReset(...);
int __cdecl Object_ClearGlobalObjectPointer_006ff620(...);
int __cdecl Interface_HideMenus(...);
int __cdecl Interface_CloseAllSupportMenus(...);
Receiver86* __cdecl BSShaderManager_GetTextureManager();
int __cdecl BSTextureManager_ReturnRenderedTexture(...);
int __cdecl FUN_0066b0d0(...);
int __cdecl TaskQueueInterface_SetActive(...);
int __cdecl NiParallelUpdateTaskManager_Get(...);
int __cdecl NiParallelUpdateTaskManager_Shutdown(...);
int __cdecl CancelAllFiles_00448420(...);
int __cdecl AILinearTaskThreadManager_Kill(...);
int __cdecl BGSMoviePlayer_Destroy(...);
int __cdecl InterfaceSceneGraph_Destroy(...);
int __cdecl Interface3DSceneGraph_Destroy(...);
int __cdecl Interface_Free(...);
int __cdecl FUN_008d8520(...);
int __cdecl Sky_Destroy(...);
int __cdecl Object_ProcessEntries_004e0800(...);
int __cdecl Object_ProcessEntries_004def20(...);
int __cdecl PurgeTerminalModel(...);
int __cdecl FalloutRadio_Shutdown(...);
int __cdecl FUN_008304a0(...);
int __cdecl FalloutAudioMedia_Shutdown(...);
int __cdecl DecalManager_Destroy_(...);
int __cdecl DecalCaster_ClearInstance(...);
int __cdecl Runtime_ReleaseStorage_00626f10(...);
int __cdecl NavMeshObstacleManager_Release(...);
int __cdecl FUN_0086bee0(...);
int __cdecl ReleaseAndClearObject(...);
int __cdecl BSFaceGenManager_DestroySystem(...);
int __cdecl CombatManager_FreeAll(...);
int __cdecl BSTreeManager_Destroy_(...);
int __cdecl BGSLoadedReferenceCollection_Destroy(...);
int __cdecl EffectSettingCollection_Destroy(...);
int __cdecl FUN_0086bf10(...);
int __cdecl FUN_0086bf40(...);
int __cdecl FUN_00717e50(...);
int __cdecl INISettingCollection_SaveAll(...);
int __cdecl RemoveEntryFromBothLists(...);
int __cdecl RemoveMatchingParallelEntries(...);
int __cdecl NavMeshRender_Destroy(...);
int __cdecl BSTexturePalette_Kill(...);
int __cdecl Object_UpdateFields_00bc2960(...);
int __cdecl Object_UpdateFields_0086bd00(...);
int __cdecl Runtime_ProcessState_0045b050(...);
int __cdecl Object_UpdateFields_00c5d520(...);
int __cdecl FreeNiNodeBlocks(...);
int __cdecl Runtime_ReleaseStorage_00a1c790(...);
int __cdecl NiStaticDataManager_Shutdown(...);
int __cdecl FUN_008783c0(...);
Receiver86* __cdecl MemoryManager_Instance();
int __cdecl MemoryManager_OutputDebugInfo(...);
int __cdecl FUN_008784d0(...);

extern unsigned int _DAT_011c16bc;
extern char str_01082ab8[];
extern char str_01082a7c[];
extern char str_0104df38[];
extern unsigned char UNK_01082a38;
extern unsigned char UNK_01082a28;
extern unsigned char UNK_01082a10;
extern unsigned char UNK_01082a00;
extern char* _DAT_011a2fe8;
extern unsigned char UNK_00869f30;
extern unsigned char UNK_00b4dfb0;
extern unsigned char UNK_010829c4;
extern unsigned char UNK_010829b4;
extern unsigned char UNK_01082990;
extern char* _DAT_011a2ff0;
extern char* _DAT_011a2ff8;
extern unsigned char UNK_01082978;
extern unsigned char UNK_0105bb14;
extern unsigned char UNK_0086a0a0;
extern unsigned char* _DAT_011dea0c;
extern unsigned int _DAT_011d8804;
extern unsigned char UNK_0108295c;
extern unsigned char DAT_011f4509;
extern unsigned char UNK_00872570;
extern float _DAT_01018bfc;
extern float _DAT_0101e704;
extern unsigned int _DAT_011c3f2c;
extern unsigned char UNK_0108293c;
extern unsigned char UNK_01082924;
extern unsigned char UNK_01082910;
extern unsigned int _DAT_011dea3c;
extern unsigned int _DAT_01202d98;
extern unsigned char UNK_010828fc;
extern unsigned int _DAT_011dea10;
extern unsigned char UNK_010828ec;
extern char str_01082a48[];

// the unit's own int-typed Win32 prototypes (the call ABI is the same as <windows.h>'s, now read globally)
namespace main_win32 {
__declspec(dllimport) unsigned int __stdcall CreateMutexA(int, int, const void*);
__declspec(dllimport) unsigned int __stdcall GetLastError();
__declspec(dllimport) int __stdcall MessageBoxA(int, const void*, const void*, int);
__declspec(dllimport) int __stdcall GetSystemMetrics(int);
__declspec(dllimport) void __stdcall GetSystemInfo(void*);
__declspec(dllimport) int __stdcall FindWindowA(const char*, int);
__declspec(dllimport) int __stdcall GetCommandLineW();
__declspec(dllimport) int __stdcall CommandLineToArgvW(int, int*);
__declspec(dllimport) int __stdcall LocalFree(void*);
__declspec(dllimport) int __stdcall ShellExecuteA(int, int, const void*, int, int, int);
__declspec(dllimport) int __stdcall LoadIconA(int, int);
__declspec(dllimport) int __stdcall GetStockObject(int);
__declspec(dllimport) int __stdcall RegisterClassA(void*);
__declspec(dllimport) int __stdcall AdjustWindowRect(void*, int, int);
__declspec(dllimport) int __stdcall CreateWindowExA(int, const char*, const char*, int, int, int, int, int, int, int,
                                                    int, int);
__declspec(dllimport) int __stdcall PeekMessageA(void*, int, int, int, int);
__declspec(dllimport) int __stdcall TranslateMessage(void*);
__declspec(dllimport) int __stdcall DispatchMessageA(void*);

__declspec(dllimport) void __stdcall Sleep(int);
__declspec(dllimport) int __stdcall GetWindowLongA(int, int);
__declspec(dllimport) int __stdcall AdjustWindowRectEx(void*, int, int, int);
__declspec(dllimport) int __stdcall SetWindowPos(int, int, int, int, int, int, int);
__declspec(dllimport) int __stdcall GetCurrentThreadId();
__declspec(dllimport) int __stdcall SetForegroundWindow(int);
}  // namespace main_win32

// Creates the game window and subsystems, runs the message/render loop until exit, then tears everything down and returns 0.
// @fnv 0x0086a850
// src: COMMUNITY 0x0086a850
int __stdcall WinMain_0086a850(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4)

{
    Rect86 inactiveRect3;
    unsigned int inactiveStyle3;
    Rect86 activeRect5;
    unsigned int activeStyle1;
    int deviceStatus13;
    char launchPath0[260];
    int shellResult10;
    unsigned short* option6;
    int argumentIndex33;
    int argumentCount8;
    unsigned short** arguments5;
    unsigned char enableMemory0;
    Point86 position25;
    SystemInfo86 systemInfo7;
    unsigned int startupState3;
    WindowClass86 windowClass10;
    Message86 message0;
    Context86 memoryContext11;
    Text86 shutdownText46;
    int gameWindow3;
    char path2[260];
    unsigned int window1;
    unsigned int mutex17;
    Rect86 windowRect0;
    unsigned char paused1;
    unsigned int startupFlags3;
    int existingWindow30;

    mutex17 = main_win32::CreateMutexA(0, 0, &str_01082ab8);
    if (main_win32::GetLastError() == 0xb7)
    {
        main_win32::MessageBoxA(0, &str_01082a7c, &str_0104df38, 0);
        return 0;
    }
    if (main_win32::GetSystemMetrics(0x1000))
    {
        main_win32::MessageBoxA(0, &str_01082a48, &str_0104df38, 0);
        return 0;
    }
    {
        {
            enableMemory0 = 0;
            enableMemory0 = 1;
            MessageHandler_Init(enableMemory0, *g_011dec88.FUN_00408d60(), *g_011dee20.FUN_00408d60(),
                         *g_011ded74.FUN_00408d60(), MessageBoxA_0);
            MessageHandler_SetAllWarningFileNames(&UNK_01082a38);
            MessageHandler_SetProgramFlowFileName(&UNK_01082a28);
            MessageHandler_SetProgrammerOutputFileName(&UNK_01082a10);
            MessageHandler_SetCrashTraceFileName(&UNK_01082a00);
            main_win32::GetSystemInfo(&systemInfo7);
            *g_011c3ea4.Int() = systemInfo7.processors;
            FUN_00876ad0(path2);
            if (*g_011c3ea4.Int() == 1)
            {
                *g_011c3ea4.Int() = 2;
            }
            existingWindow30 = main_win32::FindWindowA(_DAT_011a2fe8, 0);
            if (existingWindow30 != 0)
            {
                main_win32::SetForegroundWindow(existingWindow30);
                return 0;
            }
            {
                int result5;
                Receiver86* globalsToDelete3;
                Receiver86* globalsDeleteTarget3;
                Receiver86* interfaceToDelete85;
                Receiver86* interfaceDeleteTarget24;
                Receiver86* tesToDelete37;
                Receiver86* tesDeleteTarget23;
                Receiver86* interfaceAllocation2;
                Receiver86* newInterface17;
                Receiver86* globalsAllocation7;
                Receiver86* newGlobals20;
                Receiver86* fileAllocation4;
                Receiver86* fileSystem2;
                int shellExitResult20;
                FillUserNameGlobal(_DAT_011a2fe8);
                FUN_00af2640()->FUN_004fb090(&UNK_00869f30);
                FUN_00af2640()->BSSystemUtility_GetMsgDialogUtility()->FUN_006ecd40(SystemUtilityDialogIdleCallback);
                NiStaticDataManager_Init(0);
                BSMain_InitSDM();
                FUN_004b7920();
                Menu_InitSDM();
                FUN_00bc2940();
                TES_InitSDM();
                SetMemContext_00404f30(0x3b);
                BSFadeNode_GetLinkedActorAlpha_Set(BSFadeNode_GetLinkedActorAlpha);
                BSSoundHandle_SetAddMovingSoundCallback(&UNK_00b4dfb0);
                NiSourceTexture_SetDestroyAppDataFlag(1);
                BSStream_InitLoaders();
                BSSearchPath_InitCallback();
                memoryContext11.FUN_00404eb0(0x10, 1, &UNK_010829c4, 0x8e0);
                FOCollisionListener_GetSingleton();
                memoryContext11.FUN_00404f70();
                memoryContext11.FUN_00404f00(0xf, 1, &UNK_010829c4, 0x8e6);
                BSTexturePalette_Init();
                memoryContext11.FUN_00404f70();
                FUN_006ff610();
                argumentCount8 = 0;
                arguments5 = (unsigned short**)main_win32::CommandLineToArgvW(main_win32::GetCommandLineW(), &argumentCount8);
                if (arguments5 != 0)
                {
                    for (argumentIndex33 = 0; argumentIndex33 < argumentCount8; argumentIndex33 = argumentIndex33 + 1)
                    {
                        if ((arguments5[argumentIndex33] != 0) && (*arguments5[argumentIndex33] == 0x2d))
                        {
                            option6 = arguments5[argumentIndex33] + 1;
                            if (FUN_00ecc071(option6, &UNK_010829b4) == 0)
                            {
                                SteamAPICallbacks_GetSingleton()->SteamAPI_SetNoCloud(0);
                            }
                        }
                    }
                    main_win32::LocalFree(arguments5);
                }
                SettingT_RegSettingCollection_QCollection()->j_ReadSettingsFromFile_SettingCollection_VSetting_QEAA_NPEBD_Z(&UNK_01082990);
                FUN_0044f560()->j_ReadSettingsFromFile_SettingCollection_VSetting_QEAA_NPEBD_Z(path2);
                FUN_00406d30(path2, 0x104, BSUtilities_GetPersonalPath());
                FUN_00406d50(path2, 0x104, _DAT_011a2ff0);
                FUN_004de490()->j_ReadSettingsFromFile_SettingCollection_VSetting_QEAA_NPEBD_Z(path2);
                FUN_00406d30(path2, 0x104, BSUtilities_GetPersonalPath());
                FUN_00406d50(path2, 0x104, _DAT_011a2ff8);
                SettingT_RendererSettingCollection_GetCollection()->j_ReadSettingsFromFile_SettingCollection_VSetting_QEAA_NPEBD_Z(path2);
                FUN_004de490()->j_ReadSettingsFromFile_SettingCollection_VSetting_QEAA_NPEBD_Z(path2);
                if (*g_011c3ea4.Int() == 1)
                {
                    *g_011c3ea4.Int() = 2;
                }
                if (ProcessCustomINI())
                {
                    Renderer_Kill(1);
                    FUN_00b00a00()->Stop();
                    GetInstalledPathRegistryKey(launchPath0, 0x104);
                    FUN_00406d50(launchPath0, 0x104, &UNK_01082978);
                    shellResult10 = main_win32::ShellExecuteA(0, 0, launchPath0, 0, 0, 1);
                    if (shellResult10 != 0)
                    {
                        shellExitResult20 = 0;
                        memoryContext11.FUN_00404ee0();
                        return shellExitResult20;
                    }
                }
                FUN_00aff100()->BSFileCache_SetFileCacheList(g_011dee78.FUN_00403df0(), g_011ded2c.FUN_00403df0());
                fileAllocation4 = (Receiver86*)operator new(16);
                fileSystem2 = fileAllocation4
                                  ? fileAllocation4->FUN_00afdc60(g_011dece4.FUN_00403df0(), *g_011dee6c.Int(), 0)
                                  : 0;
                FileFinder_AddPath_0(&UNK_0105bb14);
                MessageHandler_Init(enableMemory0, *g_011dec88.FUN_00408d60(), *g_011dee20.FUN_00408d60(),
                             *g_011ded74.FUN_00408d60(), MessageBoxA_0);
                MessageHandler_SetAllWarningFileNames(&UNK_01082a38);
                MessageHandler_SetProgramFlowFileName(&UNK_01082a28);
                MessageHandler_SetProgrammerOutputFileName(&UNK_01082a10);
                MessageHandler_SetCrashTraceFileName(&UNK_01082a00);
                memoryContext11.FUN_00404f00(0x18, 1, &UNK_010829c4, 0x992);
                ProgramFlow();
                FUN_00aff100()->Object_AdvanceStateAtOffset5C_0086bda0();
                memoryContext11.FUN_00404f70();
                memoryContext11.FUN_00404f00(0x13, 1, &UNK_010829c4, 0x99c);
                SetupArchiveSettings_AndLoadBSAs();
                memoryContext11.FUN_00404f70();
                windowClass10.style = 3;
                windowClass10.procedure = &UNK_0086a0a0;
                windowClass10.classExtra = 0;
                windowClass10.windowExtra = 0;
                windowClass10.instance = param_1;
                windowClass10.icon = main_win32::LoadIconA(param_1, 0x65);
                windowClass10.cursor = 0;
                windowClass10.background = main_win32::GetStockObject(4);
                windowClass10.className = _DAT_011a2fe8;
                windowClass10.menu = 0;
                main_win32::RegisterClassA(&windowClass10);
                windowRect0.left = 0;
                windowRect0.top = 0;
                windowRect0.right = 0x140;
                windowRect0.bottom = 0xf0;
                main_win32::AdjustWindowRect(&windowRect0, 0x10000000, 0);
                window1 = main_win32::CreateWindowExA(0, _DAT_011a2fe8, _DAT_011a2fe8, 0x10000000, 0, 0,
                                          windowRect0.right - windowRect0.left, windowRect0.bottom - windowRect0.top, 0,
                                          0, param_1, 0);
                globalsAllocation7 = (Receiver86*)operator new(0xa4);
                newGlobals20 = globalsAllocation7 ? globalsAllocation7->FUN_0086c160(window1, param_1) : 0;
                _DAT_011dea0c = (unsigned char*)newGlobals20;
                memoryContext11.FUN_00404f00(0xd, 1, &UNK_010829c4, 0x9f8);
                interfaceAllocation2 = (Receiver86*)operator new(8);
                newInterface17 = interfaceAllocation2 ? interfaceAllocation2->FUN_007005d0() : 0;
                _DAT_011d8804 = (unsigned int)newInterface17;
                memoryContext11.FUN_00404f70();
                ProgramFlow(&UNK_0108295c);
                ((Receiver86*)_DAT_011dea0c)->TESMain_InitRenderer();
                DAT_011f4509 = 1;
                NiXenonRenderer_GetRenderer()->NiXenonRenderer_LockRenderer();
                NiXenonRenderer_GetRenderer()->NiDX9Renderer_AddLostDeviceNotificationFunc(&SUB_005d4a40, 0);
                NiXenonRenderer_GetRenderer()->NiDX9Renderer_AddResetNotificationFunc(&UNK_00872570, 0);
                Main_ShaderInit();
                ((Receiver86*)_DAT_011dea0c)->TESMain_InitSceneGraph();
                FUN_00702250(1);
                BSFaceGenManager_InitializeSystem();
                ((Receiver86*)_DAT_011dea0c)->TESMain_SetActive(1);
                NavMeshRender_InitSingleton();
                TESMain_ImagespaceInit();
                NiXenonRenderer_GetRenderer()->NiXenonRenderer_UnlockRenderer();
                BGSMoviePlayer_Create();
                DAT_0126fac4->MoviePlayer_StartSequence(g_011de72c.FUN_00403df0(), 0, -1, 1, 1, 0.0f);
                memoryContext11.FUN_00404f70();
                ((Receiver86*)_DAT_011dea0c)->Main_InitTES((Receiver86*)Main_GetWorldSceneGraph());
                BSFaceGenManager_SetWorldCamera(((Receiver86*)Main_GetWorldSceneGraph())->FUN_006629f0());
                BSTreeManager_SetCamera(((Receiver86*)Main_GetWorldSceneGraph())->FUN_006629f0());
                if (*g_011c3ea4.Int() > 1)
                {
                    AILinearTaskThreadManager_GetSingleton()->FUN_008c7290();
                }
                Pathing_Init();
                GetPathManager()->FUN_006eb8c0();
                if (*g_011d73e4.FUN_00408d60())
                {
                    GetNavMeshObstacleManager()->NavMeshObstacleManager_CreateListeners();
                }
                FUN_004e0540();
                FUN_004deb30();
                startupState3 = 0;
                startupFlags3 = 0;
                position25.SetComponents(_DAT_01018bfc, _DAT_01018bfc, _DAT_0101e704);
                ((Receiver86*)_DAT_011dea10)->TES_SetWorldSpace(*g_dataHandler->TESDataHandler_GetWorldSpaceList()->FUN_006815c0());
                ((Receiver86*)_DAT_011dea3c)->ClearIdleAnims();
                g_TESSaveLoadGame->ExtraDismemberedLimbs_SetEaten(1);
                ProgramFlow(&UNK_0108293c);
                ((Receiver86*)&DAT_011e0e80)->ProcessLists_InitPackageLocations();
                g_dataHandler->FUN_004614e0();
                g_BGSSaveLoadGame->BGSSaveLoadGame_SetGlobalAllowChanges(1);
                ProgramFlow(&UNK_01082924);
                Main_InitStartCell(startupFlags3, &position25);
                ProgramFlow(&UNK_01082910);
                Main_InitPlayerStart(position25);
                FUN_007022c0();
                ((Receiver86*)_DAT_011dea3c)->FUN_00483710();
                ((Receiver86*)_DAT_011dea0c)->FUN_004f15a0(1);
                ArchiveManager_SetStartupFinished();
                if (!((Receiver86*)_DAT_011dea3c)->FUN_008d6f30())
                {
                    g_dataHandler->FUN_004650a0(-1);
                    ProgramFlow();
                    Interface_CreateMainMenu();
                    DAT_0126fac4->MoviePlayer_WaitForSequenceToEnd();
                    ProgramFlow();
                }
                else
                {
                    DAT_0126fac4->MoviePlayer_WaitForSequenceToEnd();
                }
                ((Receiver86*)_DAT_01202d98)->IOManager_LoadAllQueuedPriorities();
                ProgramFlow(&UNK_010828fc);
                ourMemset(&message0, 0, 0x1c);
                gameWindow3 = ((Receiver86*)_DAT_011dea0c)->FUN_0044ddc0();
                paused1 = '\0';
                while (true)
                {
                    while (main_win32::PeekMessageA(&message0, 0, 0, 0, 1))
                    {
                        main_win32::TranslateMessage(&message0);
                        main_win32::DispatchMessageA(&message0);
                    }
                    if ((int)GetForegroundWindow() == gameWindow3 || ((Receiver86*)_DAT_011dea10)->TES_CellTestRunning() ||
                        g_011deb30.Modelloader_GetReferencedThis() || *g_011deed8.FUN_00408d60())
                    {
                        deviceStatus13 = NiXenonRenderer_GetRenderer()->NiXenonRenderer_GetD3DDevice()->TestCooperativeLevel();
                        if (deviceStatus13 < 0)
                        {
                            NiXenonRenderer_GetRenderer()->NiXenonRenderer_BeginOffScreenFrame();
                            NiXenonRenderer_GetRenderer()->NiXenonRenderer_EndOffScreenFrame();
                            main_win32::Sleep(0x32);
                        }
                        else
                        {
                            ((Receiver86*)_DAT_011dea0c)->Main_OnIdle();
                        }
                        if (paused1 != '\0')
                        {
                            paused1 = '\0';
                            BSAudio_QInstance()->UnPauseSynchTimer();
                            FalloutAudioMedia_MediaMenuUnPause();
                            FUN_00832ad0(0);
                            BSAudio_QInstance()->FUN_00ad7740(1);
                            if (TESRenderer_GetFullScreen())
                            {
                                activeRect5.left = 0;
                                activeRect5.top = 0;
                                activeRect5.right = Renderer_GetScreenWidth();
                                activeRect5.bottom = Renderer_GetScreenHeight();
                                activeStyle1 = 0;
                                activeStyle1 = main_win32::GetWindowLongA(window1, 0xfffffff0);
                                main_win32::AdjustWindowRectEx(&activeRect5, activeStyle1, 0, 0);
                                main_win32::SetWindowPos(window1, 0, activeRect5.left, activeRect5.bottom,
                                             activeRect5.right - activeRect5.left, activeRect5.top - activeRect5.bottom,
                                             0);
                            }
                        }
                        if (((paused1 == '\0') && (*_DAT_011dea0c != '\0')) && (deviceStatus13 >= 0))
                        {
                            FUN_0078d020();
                            *_DAT_011dea0c = '\0';
                        }
                    }
                    else
                    {
                        if (paused1 == '\0')
                        {
                            paused1 = '\x01';
                            if (!(unsigned char)LoadingMenuThread_GetByte49())
                            {
                                if (main_win32::GetCurrentThreadId() == ((Receiver86*)_DAT_011dea0c)->TESMain_GetThread())
                                {
                                    FUN_0078cfc0();
                                    *_DAT_011dea0c = '\x01';
                                }
                            }
                            BSAudio_QInstance()->BSWin32Audio_Pause();
                            FalloutAudioMedia_MediaMenuPause();
                            FUN_00832ad0(0);
                            BSAudio_QInstance()->FUN_00ad7740(1);
                            ((Receiver86*)_DAT_011dea0c)->Main_QDrawWorldAccum()->BSShaderAccumulator_ClearSunQueries();
                            FUN_0049fef0()->BGSDecalManager_ClearPendingQueries();
                            Interface_GetVATSEffect()->VATSEffect_FreeOcclusionQueries();
                            if (TESRenderer_GetFullScreen())
                            {
                                inactiveRect3.left = 0;
                                inactiveRect3.top = 0;
                                inactiveRect3.right = Renderer_GetScreenWidth();
                                inactiveRect3.bottom = Renderer_GetScreenHeight();
                                inactiveStyle3 = 0;
                                inactiveStyle3 = main_win32::GetWindowLongA(window1, 0xfffffff0);
                                main_win32::AdjustWindowRectEx(&inactiveRect3, inactiveStyle3, 0, 0);
                                main_win32::SetWindowPos(window1, 0, inactiveRect3.left, inactiveRect3.bottom,
                                             inactiveRect3.right - inactiveRect3.left,
                                             inactiveRect3.top - inactiveRect3.bottom, 0);
                            }
                        }
                        main_win32::Sleep(0x32);
                    }
                    if (((Receiver86*)_DAT_011dea0c)->FUN_005dc960())
                        break;
                    if (((Receiver86*)_DAT_011dea0c)->Main_GameReset())
                    {
                        ((Receiver86*)_DAT_011dea0c)->Main_PerformGameReset(1);
                    }
                }
                ((Receiver86*)_DAT_011dea0c)->FUN_004f15a0(0);
                Object_ClearGlobalObjectPointer_006ff620();
                Interface_HideMenus();
                Interface_CloseAllSupportMenus(0);
                if (g_011ded3c.Modelloader_GetReferencedThis())
                {
                    BSShaderManager_GetTextureManager()->BSTextureManager_ReturnRenderedTexture(g_011ded3c.Modelloader_GetReferencedThis());
                    g_011ded3c.FUN_0066b0d0(0);
                }
                if (g_011dec64.Modelloader_GetReferencedThis())
                {
                    BSShaderManager_GetTextureManager()->BSTextureManager_ReturnRenderedTexture(g_011dec64.Modelloader_GetReferencedThis());
                    g_011dec64.FUN_0066b0d0(0);
                }
                if (g_011deb38.Modelloader_GetReferencedThis())
                {
                    BSShaderManager_GetTextureManager()->BSTextureManager_ReturnRenderedTexture(g_011deb38.Modelloader_GetReferencedThis());
                    g_011deb38.FUN_0066b0d0(0);
                }
                TaskQueueInterface_SetActive(0);
                if (NiParallelUpdateTaskManager_Get())
                {
                    NiParallelUpdateTaskManager_Shutdown();
                }
                g_modelLoader->CancelAllFiles_00448420();
                if (*g_011c3ea4.Int() > 1)
                {
                    AILinearTaskThreadManager_GetSingleton()->AILinearTaskThreadManager_Kill();
                }
                BGSMoviePlayer_Destroy();
                InterfaceSceneGraph_Destroy();
                Interface3DSceneGraph_Destroy();
                Interface_Free();
                if (((Receiver86*)_DAT_011dea10)->FUN_008d8520())
                {
                    ((Receiver86*)_DAT_011dea10)->FUN_008d8520()->Sky_Destroy();
                }
                Object_ProcessEntries_004e0800();
                Object_ProcessEntries_004def20();
                PurgeTerminalModel();
                FalloutRadio_Shutdown();
                FUN_008304a0();
                FalloutAudioMedia_Shutdown();
                ((Manager86*)BSAudio_QInstance())->Stop();
                ProgramFlow();
                DecalManager_Destroy_();
                DecalCaster_ClearInstance();
                Runtime_ReleaseStorage_00626f10();
                if (*g_011d73e4.FUN_00408d60())
                {
                    GetNavMeshObstacleManager()->NavMeshObstacleManager_Release();
                }
                tesToDelete37 = (Receiver86*)_DAT_011dea10;
                tesDeleteTarget23 = tesToDelete37;
                tesDeleteTarget23 ? tesDeleteTarget23->FUN_0086bee0(1) : 0;
                BGSTerrainManager_FreeLODNodes();
                GetPathManager()->ReleaseAndClearObject();
                BSFaceGenManager_DestroySystem();
                CombatManager_FreeAll();
                ((Manager86*)FUN_00b00a00())->Stop();
                BSTreeManager_Destroy_();
                BGSLoadedReferenceCollection_Destroy();
                EffectSettingCollection_Destroy();
                ImpactMixer_DeInitialize();
                interfaceToDelete85 = (Receiver86*)_DAT_011d8804;
                interfaceDeleteTarget24 = interfaceToDelete85;
                interfaceDeleteTarget24 ? interfaceDeleteTarget24->FUN_0086bf10(1) : 0;
                globalsToDelete3 = (Receiver86*)_DAT_011dea0c;
                globalsDeleteTarget3 = globalsToDelete3;
                globalsDeleteTarget3 ? globalsDeleteTarget3->FUN_0086bf40(1) : 0;
                _DAT_011dea0c = (unsigned char*)0x0;
                ((Manager86*)FUN_00aff100())->Stop();
                FUN_004de490()->INISettingCollection_SaveAll(FUN_004de490()->FUN_00717e50());
                NiXenonRenderer_GetRenderer()->RemoveEntryFromBothLists(&UNK_00872570);
                NiXenonRenderer_GetRenderer()->RemoveMatchingParallelEntries(&SUB_005d4a40);
                NavMeshRender_Destroy();
                BSTexturePalette_Kill();
                Object_UpdateFields_00bc2960();
                Renderer_Kill(1);
                Object_UpdateFields_0086bd00();
                Runtime_ProcessState_0045b050();
                Object_UpdateFields_00c5d520();
                FreeNiNodeBlocks();
                Runtime_ReleaseStorage_00a1c790();
                NiStaticDataManager_Shutdown();
                shutdownText46.FUN_008783c0(&UNK_010828ec);
                MemoryManager_Instance()->MemoryManager_OutputDebugInfo(&shutdownText46, 0);
                result5 = 0;
                shutdownText46.FUN_008784d0();
                memoryContext11.FUN_00404ee0();
                return result5;
            }
        }
    }
}

extern void* DAT_01082acc;

struct FUN_0086ba10_virtual
{
    virtual bool unk00();
    virtual bool unk01();
    virtual bool unk02();
    virtual bool unk03();
    virtual bool unk04();
    virtual bool unk05();
    virtual bool unk06();
    virtual bool unk07();
    virtual bool unk08();
    virtual bool unk09();
    virtual bool unk0a();
    virtual bool unk0b();
    virtual bool unk0c();
    virtual bool unk0d();
    virtual bool unk0e();
    virtual bool unk0f();
    virtual bool unk10();
    virtual bool unk11();
    virtual bool unk12();
    virtual bool unk13();
    virtual bool unk14();
    virtual bool unk15();
    virtual bool unk16();
    virtual bool unk17();
    virtual bool unk18();
    virtual bool unk19();
    virtual bool unk1a();
    virtual bool unk1b();
    virtual bool unk1c();
    virtual bool unk1d();
    virtual bool unk1e();
    virtual bool unk1f();
    virtual bool unk20();
    virtual bool unk21();
    virtual bool unk22();
    virtual bool unk23();
    virtual bool unk24();
    virtual bool unk25();
    virtual bool unk26();
    virtual bool unk27();
    virtual bool unk28();
    virtual bool unk29();
    virtual bool unk2a();
    virtual bool unk2b();
    virtual bool unk2c();
    virtual bool unk2d();
    virtual bool unk2e();
    virtual bool unk2f();
    virtual bool unk30();
    virtual bool unk31();
    virtual bool unk32();
    virtual bool unk33();
    virtual bool unk34();
    virtual bool unk35();
    virtual bool unk36();
    virtual bool unk37();
    virtual bool unk38();
    virtual bool unk39();
    virtual bool unk3a();
    virtual bool unk3b();
    virtual bool unk3c();
    virtual bool unk3d();
    virtual bool unk3e();
    virtual bool unk3f();
    virtual bool unk40();
    virtual bool unk41();
    virtual bool unk42();
    virtual bool unk43();
    virtual bool unk44();
    virtual bool unk45();
    virtual bool unk46();
    virtual bool unk47();
    virtual bool unk48();
    virtual bool unk49();
    virtual bool unk4a();
    virtual bool unk4b();
    virtual bool unk4c();
    virtual bool unk4d();
    virtual bool unk4e();
    virtual bool unk4f();
    virtual bool unk50();
    virtual bool unk51();
    virtual bool unk52();
    virtual bool unk53();
    virtual bool unk54();
    virtual bool unk55();
    virtual bool unk56();
    virtual bool unk57();
    virtual bool unk58();
    virtual bool unk59();
    virtual bool unk5a();
    virtual bool unk5b();
    virtual bool unk5c();
    virtual bool unk5d();
    virtual bool unk5e();
    virtual bool unk5f();
};

struct FUN_0086ba10_fields
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
};

struct FUN_0086ba10_target
{
    bool NiXenonRenderer_BeginOffScreenFrame();
};

// Calls FUN_0086ba60 with DAT_01082acc and 0, then unk5f; on success sets unk200 to 2 and returns true.
// @fnv 0x0086ba10
// src: XBOX_PDB 0x0086ba10
bool FUN_0086ba10_target::NiXenonRenderer_BeginOffScreenFrame()
{
    if (!reinterpret_cast<FUN_0086ba60_Class*>(this)->NiRenderer_Check_FrameState(&DAT_01082acc, 0))
        return false;

    if (!reinterpret_cast<FUN_0086ba10_virtual*>(this)->unk5f())
        return false;

    reinterpret_cast<FUN_0086ba10_fields*>(this)->unk200 = 2;
    return true;
}

extern FUN_0086bd40_class* DAT_011f81dc;

// If the global object pointer DAT_011f81dc is non-null, calls its FUN_0086bd40 method with 1.
// @fnv 0x0086bd00
// src: GUESS 0x0086bd00 (confidence: low)
void __cdecl Object_UpdateFields_0086bd00(void)
{
    if (DAT_011f81dc)
    {
        FUN_0086bd40_class* pObject = DAT_011f81dc;
        FUN_0086bd40_class* pThis = pObject;

        {
            void* pResult;
            if (pThis)
            {
                pResult = pThis->FUN_0086bd40(1);
            }
            else
            {
                pResult = 0;
            }
        }
    }
}

struct MemScope
{
    int context;
    MemScope(int, bool, const char*, int);
    ~MemScope();
    void Enter(int, bool, const char*, int);
    void Leave();
};
struct UpdateInfo
{
    float time;
    int flags;
    int unk08;
    UpdateInfo(float, bool, bool);
};
struct ScenePart
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual ScenePart* AsNode();
    ScenePart* Child(unsigned int);
    void Link();
    void Reset();
    void Update(UpdateInfo&);
};
struct SkyInit
{
    static SkyInit* GetInstance();
    ScenePart* Attach(ScenePart*);
};
extern SkyInit* DAT_011dea20;
extern int DAT_011dea1c;
void TESMain_InitSky();
int TESMain_GetObjectLODRoot();
ScenePart* Main_LandLODNode();
void LogInit(const char*, ...);
struct WorldInit
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    WorldInit(const char*, int, ScenePart*, SkyInit*, int);
    void Start();
    void LoadTerrain();
    void LoadLandscape();
    void Extra();
    void Finish();
};
extern WorldInit* worldInstance;
void CreateTrees(bool);
struct TaskInit
{
    void Activate();
};
TaskInit& GetTasks();
void BGSLoadedReferenceCollection_Create();
void CombatManager_Create();
struct InitSetting
{
    const char* String();
    int Value();
    int* Int();
    bool* Bool();
};
extern InitSetting g_011debf0;
extern InitSetting g_011deb88;
extern InitSetting g_011decf8;
extern InitSetting g_011dee9c;
extern InitSetting g_011dec34;
extern InitSetting g_011dee0c;
extern InitSetting g_011ded14;
extern InitSetting g_011dee48;
extern InitSetting g_011dea70;
extern InitSetting g_011ded48;
extern InitSetting g_011c7adc;
extern InitSetting g_011dee60;
struct FileInit
{
    void Enable(bool);
    const char* Filename();
};
struct HandlerInit
{
    FileInit* Find(const char*);
    void Load(bool);
    void Scripts();
};
extern HandlerInit* handlerInstance;
extern int DAT_011a2ffc;
int* BSUtilities_GetLocalAppDataPath();
const char* PrepareScriptMessage(const char*, bool);
extern "C" unsigned int __cdecl strlen(const char*);
struct ValueInit
{
    virtual void v0();
    virtual void v4();
    virtual int Get(int);
};
struct PlayerInit
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void Refresh();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void SetID(unsigned int, bool);
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void SetAngles(const ::NiPoint3&);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    ValueInit values;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int unkb54;
    int unkb58;
    int unkb5c;
    int unkb60;
    int unkb64;
    int unkb68;
    int unkb6c;
    int unkb70;
    int unkb74;
    int unkb78;
    int unkb7c;
    int unkb80;
    int unkb84;
    int unkb88;
    int unkb8c;
    int unkb90;
    int unkb94;
    int unkb98;
    int unkb9c;
    int unkba0;
    int unkba4;
    int unkba8;
    int unkbac;
    int unkbb0;
    int unkbb4;
    int unkbb8;
    int unkbbc;
    int unkbc0;
    int unkbc4;
    int unkbc8;
    int unkbcc;
    int unkbd0;
    int unkbd4;
    int unkbd8;
    int unkbdc;
    int unkbe0;
    int unkbe4;
    int unkbe8;
    int unkbec;
    int unkbf0;
    int unkbf4;
    int unkbf8;
    int unkbfc;
    int unkc00;
    int unkc04;
    int unkc08;
    int unkc0c;
    int unkc10;
    int unkc14;
    int unkc18;
    int unkc1c;
    int unkc20;
    int unkc24;
    int unkc28;
    int unkc2c;
    int unkc30;
    int unkc34;
    int unkc38;
    int unkc3c;
    int unkc40;
    int unkc44;
    int unkc48;
    int unkc4c;
    int unkc50;
    int unkc54;
    int unkc58;
    int unkc5c;
    int unkc60;
    int unkc64;
    int unkc68;
    int unkc6c;
    int unkc70;
    int unkc74;
    int unkc78;
    int unkc7c;
    int unkc80;
    int unkc84;
    int unkc88;
    int unkc8c;
    int unkc90;
    int unkc94;
    int unkc98;
    int unkc9c;
    int unkca0;
    int unkca4;
    int unkca8;
    int unkcac;
    int unkcb0;
    int unkcb4;
    int unkcb8;
    int unkcbc;
    int unkcc0;
    int unkcc4;
    int unkcc8;
    int unkccc;
    int unkcd0;
    int unkcd4;
    int unkcd8;
    int unkcdc;
    int unkce0;
    int unkce4;
    int unkce8;
    int unkcec;
    int unkcf0;
    int unkcf4;
    int unkcf8;
    int unkcfc;
    int unkd00;
    int unkd04;
    int unkd08;
    int unkd0c;
    int unkd10;
    int unkd14;
    int unkd18;
    int unkd1c;
    int unkd20;
    int unkd24;
    int unkd28;
    int unkd2c;
    int unkd30;
    int unkd34;
    int unkd38;
    int unkd3c;
    int unkd40;
    int unkd44;
    int unkd48;
    int unkd4c;
    int unkd50;
    int unkd54;
    int unkd58;
    int unkd5c;
    int unkd60;
    int unkd64;
    int unkd68;
    int unkd6c;
    int unkd70;
    int unkd74;
    int unkd78;
    int unkd7c;
    int unkd80;
    int unkd84;
    int unkd88;
    int unkd8c;
    int unkd90;
    int unkd94;
    int unkd98;
    int unkd9c;
    int unkda0;
    int unkda4;
    int unkda8;
    int unkdac;
    int unkdb0;
    int unkdb4;
    int unkdb8;
    int unkdbc;
    int unkdc0;
    int unkdc4;
    int unkdc8;
    int unkdcc;
    int unkdd0;
    int unkdd4;
    int unkdd8;
    int unkddc;
    int unkde0;
    int unkde4;
    int unkde8;
    int unkdec;
    int unkdf0;
    int unkdf4;
    int unkdf8;
    int unkdfc;
    int unke00;
    int unke04;
    int unke08;
    int unke0c;
    int unke10;
    int unke14;
    int unke18;
    int unke1c;
    int unke20;
    int unke24;
    int unke28;
    int unke2c;
    int unke30;
    int unke34;
    int unke38;
    int unke3c;
    int unke40;
    int unke44;
    int unke48;
    int unke4c;
    PlayerInit();
    void SetBase(void*);
    void Position(const ::NiPoint3&);
    void Enable(bool);
};
extern PlayerInit* playerInstance;
void FUN_005f5880();
void FUN_0068b3e0();

::TESForm* LookupForm(unsigned int);
extern ::NiPoint3 zeroPoint;
struct TimeInit
{
    void Set(int);
};
extern TimeInit timeInstance;
struct BootInit
{
    bool LoadPlugins(int*, int);
    void Main_InitTES(ScenePart*);
};
// Initializes the game world, plugins, player, terrain, and scripts in sequence, logging each stage.
// @fnv 0x0086cf20
// src: XBOX_PDB 0x0086cf20
void BootInit::Main_InitTES(ScenePart* scene)
{
    MemScope memory5(10, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0xe4f);
    memory5.Enter(10, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0xe51);
    DAT_011dea20 = SkyInit::GetInstance();
    TESMain_InitSky();
    int mode = TESMain_GetObjectLODRoot();
    ScenePart* root_2 = Main_LandLODNode();
    if (root_2)
    {
        DAT_011dea20->Attach(root_2)->Link();
        ScenePart* child4 = root_2->Child(0);
        root_2 = child4 ? child4->AsNode() : 0;
    }
    LogInit("Initializing TES...");
    worldInstance = new WorldInit("DATA\\", mode, root_2, DAT_011dea20, DAT_011dea1c);
    memory5.Leave();
    worldInstance->Start();
    LogInit("Initializing TreeManager...");
    CreateTrees(false);
    LogInit("Activating Tasklet Threads...");
    GetTasks().Activate();
    BGSLoadedReferenceCollection_Create();
    CombatManager_Create();
    memory5.Enter(25, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0xe85);
    scene->Reset();
    UpdateInfo update9(0.0f, false, false);
    scene->Update(update9);
    memory5.Leave();
    bool found3 = false;
    InitSetting* plugins3[10] = {&g_011debf0, &g_011deb88, &g_011decf8, &g_011dee9c, &g_011dec34,
                                 &g_011dee0c, &g_011ded14, &g_011dee48, &g_011dea70, &g_011ded48};
    for (int index2 = 0; index2 < 10; ++index2)
    {
        if (plugins3[index2]->String() && strlen(plugins3[index2]->String()))
        {
            FileInit* aFile = handlerInstance->Find(PrepareScriptMessage(plugins3[index2]->String(), false));
            if (aFile)
            {
                aFile->Enable(true);
                found3 = true;
            }
        }
    }
    if (LoadPlugins(BSUtilities_GetLocalAppDataPath(), DAT_011a2ffc))
        found3 = true;
    if (!found3)
    {
        FileInit* _fallback = handlerInstance->Find("Fallout.esm");
        if (_fallback)
            _fallback->Enable(true);
    }
    memory5.Enter(52, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0xecb);
    playerInstance = new PlayerInit;
    playerInstance->SetID(20, true);
    memory5.Leave();
    LogInit("Loading Files...");
    handlerInstance->Load(false);
    FUN_005f5880();
    worldInstance->LoadTerrain();
    worldInstance->LoadLandscape();
    if (*g_011c7adc.Bool())
        worldInstance->Extra();
    worldInstance->Finish();
    FUN_0068b3e0();
    LogInit("Initializing Player...");
    memory5.Enter(52, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0xf00);
    {
        TESNPC* base2 = dynamic_cast<TESNPC*>(LookupForm(7));
        playerInstance->SetBase(base2);
        playerInstance->SetAngles(::NiPoint3(2048.0f, 2048.0f, 0.0f));
        playerInstance->Position(zeroPoint);
        playerInstance->Refresh();
        playerInstance->Enable(false);
        int healthB = playerInstance->values.Get(16);
        if (!healthB)
            LogInit("ERROR: Health value is 0 on the Player. Fix '%s' with the editor.",
                    reinterpret_cast<FileInit*>(base2->GetFile(0))->Filename());
    }
    LogInit("Initializing Scripts...");
    handlerInstance->Scripts();
    if (g_011dee60.Value() > 0 && g_011dee60.Value() < 200)
        timeInstance.Set(*g_011dee60.Int());
}

extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int);
namespace FrameUpdate {
struct Service;
struct Values
{
    virtual void v0();
    virtual void v4();
    virtual int Get(int);
};
struct Service
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void Update();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void Advance(float);
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void* Position();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    Values values;
    void SteamAPI_RunCallbacks_();
    bool FUN_00701450(bool);
    void FUN_00851d90();
    void UpdateQueue();
    void TES_ShowLoadingMenu(int, int, int);
    void BSTextureManager_Update(Service*, bool);
    void FUN_007011d0(bool);
    bool TES_CellTestRunning();
    bool TES_CellTestRunning2();
    void TES_TestAllCells(int);
    Service* Modelloader_GetReferencedThis();
    float FUN_0084d030();
    void FUN_00867a40(float);
    int* Setting_Int();
    void TES_RunAnimations();
    void BSSpinLock_Lock(int);
    void ProcessLists_RunActorScripts();
    void FUN_009777a0();
    void ProcessLists_ChangeProcessLevelTempList();
    void FUN_0096e9b0();
    void FUN_008d0600(float, int);
    void BSSpinLock_Unlock();
    void MemoryLevelManager_CheckMemoryLevel(bool);
    void BGSDecalManager_UpdateDecals();
    void FUN_00712e60(void*);
    int FUN_0044ddc0();
    float PlayerCharacter_GetWorldFOV();
    void SceneGraph_SetCameraFOV(float, int, int, bool);
    void* FUN_006629f0();
    void TES_ResetAllMultiBoundNodes(bool, bool);
    void FUN_00b5ac90(void*);
    void TES_UpdateMultiBoundVisibility(void*);
    void AILinearTaskThreadManager_StartThreads();
    void AITaskManager_StartTasksDuringRendering();
    void FUN_006ebc50();
    void NavMeshRender_Update();
    bool* FUN_00408d60();
    void NavMeshObstacleManager_Update();
    void CombatManager_Update(bool);
    void AILinearTaskThreadManager_WaitForThreads();
    void AITaskManager_WaitForTasksDuringRendering();
    bool PlayerCharacter_IsVanityMode();
    signed char InterfaceManager_GetMenuMode();
    void* FUN_008d6f30();
};
Service* __cdecl FUN_00af2640();
bool __cdecl Interface_IsInMenuMode();
bool __cdecl Interface_IsPipboyOpening();
bool __cdecl Interface_InDialog();
bool __cdecl Interface_IsConsoleVisible();
void* __cdecl Interface_GetCurrentRenderedMenu();
void* __cdecl Interface_GetPipboy();
Service* __cdecl InterfaceManager_GetSingleton();
Service* __cdecl SteamAPICallbacks_GetSingleton();
bool __cdecl StartMenu_CreditsMenuIsActive();
bool __cdecl StartMenu_MainMenuIsActive();
bool __cdecl FUN_00705ea0();
Service* __cdecl Main_WorldRootCamera();
Service* __cdecl BSShaderManager_GetTextureManager();
int __cdecl NiParallelUpdateTaskManager_Get();
Service* __cdecl MemoryLevelManager_GetSingleton();
bool __cdecl BSTexturePalette_IsPartiallyPurged();
Service* __cdecl FUN_0049fef0();
Service* __cdecl Main_GetWorldSceneGraph();
Service* __cdecl AILinearTaskThreadManager_GetSingleton();
Service* __cdecl GetPathManager();
Service* __cdecl NavMeshRender_GetSingleton();
Service* __cdecl GetNavMeshObstacleManager();
bool __cdecl NiParallelUpdateTaskManager_IsActive();
int __cdecl Interface_GetTopMenuID();
bool __cdecl SleepWaitMenu_UpdateSleeping();
bool __cdecl TESMain_GetOpenConsole();
void __cdecl FUN_008782b0();
void __cdecl bhkWorld_ResetBatchProcessed();
void __cdecl bhkRagdollController_ResetFootCastTimer();
void __cdecl SleepManager_RunSleep();
void __cdecl BSFadeNode_IncFadeCounter();
void __cdecl FUN_0078cfc0();
void __cdecl ScreenSplatter_Update();
void __cdecl ScreenCustomSplatter_Update();
void __cdecl NiParallelUpdateTaskManager_BeginUpdate();
void __cdecl NiParallelUpdateTaskManager_EndUpdate();
void __cdecl BSTexturePalette_PurgeUnusedTextures();
void __cdecl FUN_00868850();
void __cdecl FUN_00868d10();
void __cdecl Interface_LastMinuteUpdate();
void __cdecl CheckWithinMultiBoundTask_DoAttachments();
void __cdecl ShadowSceneNode_ProcessAllQueuedLights();
void __cdecl RecreateRenderDevice();
void __cdecl Interface_OpenConsole();
void __cdecl Object_DoNothing();
void __cdecl Script_ClearOptimizations();
void __cdecl ScriptLocals_ClearOptimizations();
float __cdecl Pathing_ProfilePathing(void*, void*, int, int);
void __cdecl BSTreeManager_Update(Service*, bool);
void __cdecl FUN_00b54000(float);
Service* __cdecl FUN_00450b80(int);
void __cdecl FUN_008c80e0(bool);
int __cdecl TESActorBaseData_GetAlignmentForKarma(float);
void __cdecl TESMain_SetOpenConsole(int);
void __cdecl MemoryPool_SortFreeBlocks(unsigned int);
extern Service* DAT_011d8804;
extern Service* DAT_011dea3c;
extern Service* DAT_011de134;
extern Service* DAT_01202d98;
extern Service* DAT_011dea10;
extern Service* DAT_011f1958;
extern Service DAT_011deb7c;
extern Service DAT_011f6394;
extern Service DAT_011de7b8;
extern Service DAT_011c3ea4;
extern Service DAT_011f11a0;
extern Service DAT_011e0e80;
extern Service DAT_011f2250;
extern Service DAT_011e0fe0;
extern Service DAT_011d73e4;
extern bool DAT_011dea2b;
extern bool DAT_011dea2c;
extern bool DAT_011dea2d;
extern bool DAT_011dea2e;
extern bool DAT_011deefc;
extern bool DAT_011c6fbb;
extern unsigned char DAT_011deef5;
extern float DAT_011a3010, DAT_011deef8;
extern int DAT_011a2fe0, DAT_011df674;
extern char DAT_011ad840;
struct MainLoop
{
    int unk00;
    char unk04, unk05, unk06;
    bool paused;
    void Main_OnIdle_UpdatePlayer();
    void TESMain_OnIdle_FixActorBones();
    void FUN_00483710();
    void TESMain_OnIdle_UpdateTimer();
    void TESMain_OnIdle_PollControls();
    void Main_OnIdle_ScaleLOD();
    void FUN_0086f450();
    void Main_OnIdle_UpdateCurrentGridCell();
    void TESMain_OnIdle_DoInterfaceIdle();
    void Main_OnIdle_UpdateAnimationsAndEffects();
    void Main_RenderMenuBackground();
    void Main_Swap();
    void TESMain_PostSwapProcess();
    void Main_UpdateNonRenderSafeAITasks();
    void TESMain_OnIdle_PostThreadsProcess();
    void TESObjectREFR_GetIsChildSize(float);
    void Main_OnIdle_UpdateImageSpace(bool);
    void Main_OnIdle();
};
// @fnv 0x0086e650
// src: XBOX_PDB 0x0086e650
void MainLoop::Main_OnIdle()
{
    TESObjectREFR_GetIsChildSize(DAT_011a3010);
    short key4;
    key4 = GetAsyncKeyState(9);
    if ((key4 >> 15) & 1)
    {
        key4 = GetAsyncKeyState(18);
        if ((key4 >> 15) & 1)
            return;
    }
    FUN_00af2640()->Update();
    DAT_011dea2b = Interface_IsInMenuMode() || Interface_IsPipboyOpening();
    DAT_011dea2c = Interface_InDialog();
    DAT_011dea2d = DAT_011d8804->FUN_00701450(true);
    DAT_011dea2e = Interface_IsConsoleVisible();
    bool differentMenu = Interface_GetCurrentRenderedMenu() && Interface_GetCurrentRenderedMenu() != Interface_GetPipboy();
    if (InterfaceManager_GetSingleton()->InterfaceManager_GetMenuMode() == 3 && !differentMenu)
        FUN_008782b0();
    Main_OnIdle_UpdatePlayer();
    SteamAPICallbacks_GetSingleton()->SteamAPI_RunCallbacks_();
    Main_OnIdle_UpdateImageSpace(!DAT_011dea2b && !paused);
    DAT_011dea2b = Interface_IsInMenuMode() || Interface_IsPipboyOpening();
    DAT_011dea2c = Interface_InDialog();
    DAT_011dea2d = DAT_011d8804->FUN_00701450(true);
    DAT_011dea2e = Interface_IsConsoleVisible();
    if (DAT_011deefc)
        Pathing_ProfilePathing(DAT_011dea3c->FUN_008d6f30(), DAT_011dea3c->Position(), 2, 100);
    DAT_011de134->FUN_00851d90();
    bhkWorld_ResetBatchProcessed();
    bhkRagdollController_ResetFootCastTimer();
    TESMain_OnIdle_FixActorBones();
    FUN_00483710();
    SleepManager_RunSleep();
    ++DAT_011a2fe0;
    DAT_011df674 = 0;
    if (!DAT_011dea2b)
        BSFadeNode_IncFadeCounter();
    TESMain_OnIdle_UpdateTimer();
    TESMain_OnIdle_PollControls();
    DAT_01202d98->UpdateQueue();
    if (!StartMenu_CreditsMenuIsActive())
    {
        if (StartMenu_MainMenuIsActive())
            FUN_0078cfc0();
        else if (FUN_00705ea0())
            DAT_011dea10->TES_ShowLoadingMenu(0, 0, 0);
    }
    Main_OnIdle_ScaleLOD();
    BSShaderManager_GetTextureManager()->BSTextureManager_Update(Main_WorldRootCamera(), DAT_011dea2b);
    FUN_0086f450();
    DAT_011d8804->FUN_007011d0(true);
    if (!DAT_011dea2b && !paused)
    {
        ScreenSplatter_Update();
        ScreenCustomSplatter_Update();
    }
    if (NiParallelUpdateTaskManager_Get())
        NiParallelUpdateTaskManager_BeginUpdate();
    if (!DAT_011dea2b && !paused)
    {
        if (DAT_011dea10->TES_CellTestRunning() && !DAT_011dea10->TES_CellTestRunning2())
            DAT_011dea10->TES_TestAllCells(0);
        DAT_011deb7c.Modelloader_GetReferencedThis()->Advance(DAT_011f6394.FUN_0084d030());
        DAT_011de7b8.FUN_00867a40(DAT_011f6394.FUN_0084d030());
        if (*DAT_011c3ea4.Setting_Int() == 1)
            DAT_011dea10->TES_RunAnimations();
    }
    DAT_011f11a0.BSSpinLock_Lock(0);
    DAT_011e0e80.ProcessLists_RunActorScripts();
    if (*DAT_011c3ea4.Setting_Int() != 1)
    {
        if ((!DAT_011dea2b || DAT_011dea2d) && !DAT_011dea2e && !paused)
        {
            DAT_011e0e80.FUN_009777a0();
            DAT_011e0e80.ProcessLists_ChangeProcessLevelTempList();
            DAT_011e0e80.FUN_0096e9b0();
        }
    }
    else
    {
        if ((!DAT_011dea2b || DAT_011dea2d) && !DAT_011dea2e && !paused)
        {
            DAT_011e0e80.FUN_009777a0();
            DAT_011e0e80.FUN_008d0600(0.0f, 0);
            DAT_011e0e80.ProcessLists_ChangeProcessLevelTempList();
            DAT_011e0e80.FUN_0096e9b0();
        }
    }
    DAT_011f11a0.BSSpinLock_Unlock();
    MemoryLevelManager_GetSingleton()->MemoryLevelManager_CheckMemoryLevel(true);
    if (BSTexturePalette_IsPartiallyPurged())
        BSTexturePalette_PurgeUnusedTextures();
    FUN_00868850();
    FUN_00868d10();
    BSTreeManager_Update(Main_WorldRootCamera(), DAT_011dea2b || paused);
    Main_OnIdle_UpdateCurrentGridCell();
    if (*DAT_011c3ea4.Setting_Int() == 1)
        TESMain_OnIdle_DoInterfaceIdle();
    FUN_00483710();
    FUN_0049fef0()->BGSDecalManager_UpdateDecals();
    Main_WorldRootCamera()->FUN_00712e60(&DAT_011ad840);
    if (DAT_011f2250.FUN_0044ddc0() != 4)
        Main_GetWorldSceneGraph()->SceneGraph_SetCameraFOV(DAT_011dea3c->PlayerCharacter_GetWorldFOV(), 0, 0, true);
    FUN_00b54000(DAT_011dea3c->PlayerCharacter_GetWorldFOV());
    void* sceneB = DAT_011deb7c.Modelloader_GetReferencedThis()->FUN_006629f0();
    void* replacement5 = 0;
    DAT_011dea10->TES_ResetAllMultiBoundNodes(true, true);
    FUN_00450b80(0)->FUN_00b5ac90(replacement5 ? replacement5 : sceneB);
    DAT_011dea10->TES_UpdateMultiBoundVisibility(replacement5 ? replacement5 : sceneB);
    bool update = (!DAT_011dea2b || DAT_011dea2d) && !DAT_011dea2e && !paused;
    if (update)
    {
        if (*DAT_011c3ea4.Setting_Int() > 1)
        {
            FUN_008c80e0(true);
            AILinearTaskThreadManager_GetSingleton()->AILinearTaskThreadManager_StartThreads();
        }
        else
            DAT_011e0fe0.AITaskManager_StartTasksDuringRendering();
    }
    Main_OnIdle_UpdateAnimationsAndEffects();
    if (*DAT_011c3ea4.Setting_Int() > 1 && !update)
    {
        TESMain_OnIdle_DoInterfaceIdle();
        if (Interface_IsInMenuMode())
            Interface_LastMinuteUpdate();
    }
    if (!paused)
        GetPathManager()->FUN_006ebc50();
    NavMeshRender_GetSingleton()->NavMeshRender_Update();
    if (*DAT_011c3ea4.Setting_Int() == 1)
    {
        if (*DAT_011d73e4.FUN_00408d60())
            GetNavMeshObstacleManager()->NavMeshObstacleManager_Update();
        DAT_011f1958->CombatManager_Update(DAT_011dea2b || DAT_011dea2d || paused);
    }
    if (NiParallelUpdateTaskManager_IsActive())
        NiParallelUpdateTaskManager_EndUpdate();
    if (Interface_GetTopMenuID() == 0x3f4 && SleepWaitMenu_UpdateSleeping())
        Main_RenderMenuBackground();
    CheckWithinMultiBoundTask_DoAttachments();
    ShadowSceneNode_ProcessAllQueuedLights();
    int mode4 = TESActorBaseData_GetAlignmentForKarma((float)DAT_011dea3c->values.Get(23));
    if (mode4 > 2)
    {
        if (mode4 == 3)
            mode4 = 0;
        else
            mode4 = 2;
    }
    Main_Swap();
    TESMain_PostSwapProcess();
    if (DAT_011c6fbb)
    {
        RecreateRenderDevice();
        DAT_011c6fbb = false;
    }
    if ((!DAT_011dea2b || DAT_011dea2d) && !DAT_011dea2e && !paused)
    {
        if (*DAT_011c3ea4.Setting_Int() > 1)
            AILinearTaskThreadManager_GetSingleton()->AILinearTaskThreadManager_WaitForThreads();
        else
            DAT_011e0fe0.AITaskManager_WaitForTasksDuringRendering();
    }
    Main_UpdateNonRenderSafeAITasks();
    TESMain_OnIdle_PostThreadsProcess();
    if (TESMain_GetOpenConsole())
    {
        TESMain_SetOpenConsole(0);
        Interface_OpenConsole();
    }
    Object_DoNothing();
    Script_ClearOptimizations();
    ScriptLocals_ClearOptimizations();
    DAT_011deef8 += DAT_011f6394.FUN_0084d030();
    if (Interface_IsInMenuMode() || (DAT_011dea3c && DAT_011dea3c->PlayerCharacter_IsVanityMode()) || DAT_011deef8 >= 45.0)
    {
        DAT_011deef8 = 0.0f;
        MemoryPool_SortFreeBlocks(DAT_011deef5++);
        if (DAT_011deef5 == 256)
            DAT_011deef5 = 0;
    }
}
}

namespace fnv_008707c0 {
typedef ImageSpaceManager ISMgr;
struct RootNode;
struct AnimData;
struct StrObj
{
    operator const char*() const;
};

struct MTHelper
{
    void MTRenderingSystem_SetThreadStage(int a, int b);
    void MTRenderingSystem_WaitOnThreadStage(int a, int b);
};
MTHelper* __cdecl FUN_004ea970();

struct RMenu
{
    RootNode* SkyObject_GetNiNode();
};
RMenu* __cdecl Interface_GetCurrentRenderedMenu();
::NiRenderer* __cdecl NiXenonRenderer_GetRenderer();
bool __cdecl TESRenderer_GetMultiSampleEnabled();
bool __cdecl Interface_IsInPipboyMenu();
unsigned char __cdecl BSShaderManager_GetImageSpaceEffects();
void __cdecl FUN_008c80e0(int);

struct FNode
{
    void BSCullingProcess_SetAccumulator(const char* s);
    void FUN_0041fd00(AnimData* a);
};
struct FGen
{
    FNode* FUN_008d80e0();
};
AnimData* __cdecl Main_WorldRootCamera();
struct SSN
{
    void ShadowSceneNode_PreOnVisible(FNode* n);
};
SSN* __cdecl FUN_00450b80(int);

struct RenderMgr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    StrObj name;

    void FUN_00872ad0();
    void Main_DrawWorld_UpdateOffscreenBuffers();
    int TESMain_DrawWorld_InitRenderTexture(::NiRenderer* r, int p1, bool p2, bool b);
    void TESMain_DrawWorld_CopyMenuBG(ISMgr* m, ::NiRenderer* r, bool b, int p1);
    void Main_DrawWorld_MTSetup1stPerson();
    void TESMain_DrawWorld_MTRender1stPerson(::NiRenderer* r, RootNode* root, int z, int res);
    void TESMain_DrawWorld_RenderedMenuScene();
    void TESMain_DrawWorld_ImageSpace(bool b, int res, ::NiRenderer* r, int p1);
    void Main_DrawWorld_RenderedMenu(RootNode* root, ::NiRenderer* r);
    void TESMain_DrawWorld_StopRenderTarget(bool b, int p1);
    void TESMain_DrawWorld_End(int res, ISMgr* m, ::NiRenderer* r, int z);

    void TESMain_DrawWorldRenderedMenu(int p1, bool p2);
};

// Runs the render update: resets helpers, computes a result via FUN_00872f50, sets up a node when FUN_00705a00 is true, and dispatches the remaining render steps.
// @fnv 0x008707c0
// src: COMMUNITY 0x008707c0
void RenderMgr::TESMain_DrawWorldRenderedMenu(int p1, bool p2)
{
    ISMgr* ism2 = BSShaderManager_GetImageSpaceManager();
    ::NiRenderer* renderer = NiXenonRenderer_GetRenderer();
    bool flag_ = TESRenderer_GetMultiSampleEnabled();
    RootNode* root2 = Interface_GetCurrentRenderedMenu() ? Interface_GetCurrentRenderedMenu()->SkyObject_GetNiNode() : 0;
    FUN_00872ad0();
    for (int i4 = 1; i4 < 0x11; i4++)
    {
        FUN_004ea970()->MTRenderingSystem_SetThreadStage(0, i4);
        FUN_004ea970()->MTRenderingSystem_WaitOnThreadStage(1, i4);
    }
    Main_DrawWorld_UpdateOffscreenBuffers();
    int res4 = TESMain_DrawWorld_InitRenderTexture(renderer, p1, p2, flag_);
    TESMain_DrawWorld_CopyMenuBG(ism2, renderer, flag_, p1);
    if (*g_011c3ea4.Int() > 1)
        FUN_008c80e0(0);
    FUN_004ea970()->MTRenderingSystem_SetThreadStage(0, 0x15);
    FUN_004ea970()->MTRenderingSystem_WaitOnThreadStage(1, 0x15);
    if (Interface_IsInPipboyMenu())
    {
        AnimData* anim3 = Main_WorldRootCamera();
        FGen* fg7 = (FGen*)Main_GetWorldSceneGraph();
        FNode* pNode = fg7->FUN_008d80e0();
        pNode->BSCullingProcess_SetAccumulator(name);
        pNode->FUN_0041fd00(anim3);
        FUN_00450b80(0)->ShadowSceneNode_PreOnVisible(pNode);
        Main_DrawWorld_MTSetup1stPerson();
        TESMain_DrawWorld_MTRender1stPerson(renderer, root2, 0, res4);
    }
    else
    {
        FUN_004ea970()->MTRenderingSystem_SetThreadStage(0, 0x16);
        FUN_004ea970()->MTRenderingSystem_WaitOnThreadStage(1, 0x16);
    }
    TESMain_DrawWorld_RenderedMenuScene();
    if (BSShaderManager_GetImageSpaceEffects() && !p2)
    {
        TESMain_DrawWorld_ImageSpace(flag_, res4, renderer, p1);
        if (root2)
            Main_DrawWorld_RenderedMenu(root2, renderer);
    }
    else if (p1)
    {
        TESMain_DrawWorld_StopRenderTarget(flag_, p1);
    }
    TESMain_DrawWorld_End(res4, ism2, renderer, 0);
}
}  // namespace fnv_008707c0

struct ISManagerStub870;
struct RTexStub870;
struct TexStub870;

struct AVObjStub870
{
    bool GetAppCulled_00456610();
};
struct PlayerStub870
{
    AVObjStub870* GetNode(bool firstPerson);
};

struct MenuStub870
{
    void* GetMenuRoot();
};
struct RenderSysStub870
{
    void EnableA(int a, int b);
    void EnableB(int a, int b);
};

::NiRenderer* GetRenderer870();
ISManagerStub870* GetISManager870();
bool IsFlag870();
void SetupState870(int a, int b);
MenuStub870* GetMenu870();
bool MenuCheck870();
RenderSysStub870* GetRenderSys870();
void SetState870(int a);

struct SceneRendererStub870
{
    void Prepare1();
    TexStub870* GetTexture();
    void Prepare2();
    bool CheckX();
    void Prepare3();
    RTexStub870* RenderMain(::NiRenderer* renderer, TexStub870* target, int unk, bool flag);
    void ShaderPassEntry(TexStub870* tex, bool draw, bool unk, bool x);
    void Finish1();
    void TESMain_DrawWorld_RestartRenderTexture(RTexStub870* rt, bool flag, unsigned int unk);
    void Composite(::NiRenderer* renderer, int unk, TexStub870* tex, RTexStub870* rt);
    void CopyTarget(bool flag, TexStub870* target);
    void RenderAlt(bool flag, RTexStub870* rt, ::NiRenderer* renderer, TexStub870* target);
    void RenderImageSpace(RTexStub870* rt, ISManagerStub870* ism, ::NiRenderer* renderer, int unk);

    void Main_DrawWorldWireframe(TexStub870* target, bool skip);
};

// @fnv 0x00870a00
// src: XBOX_PDB 0x00870a00
void SceneRendererStub870::Main_DrawWorldWireframe(TexStub870* target, bool skip)
{
    ::NiRenderer* renderer2 = GetRenderer870();
    ISManagerStub870* ism = GetISManager870();
    TexStub870* tex2 = 0;
    bool nodeFlag4 = ((PlayerStub870*)g_thePlayer)->GetNode(true)->GetAppCulled_00456610();
    bool flagVal = IsFlag870();
    SetupState870(1, 1);
    Prepare1();
    tex2 = GetTexture();
    Prepare2();
    bool checkXA = CheckX();
    Prepare3();
    RTexStub870* rt4 = RenderMain(renderer2, target, 0, flagVal);
    bool draw2 = !nodeFlag4 && !skip && !GetMenu870()->GetMenuRoot() && !MenuCheck870();
    ShaderPassEntry(tex2, draw2, true, checkXA);
    if (draw2)
    {
        Finish1();
        TESMain_DrawWorld_RestartRenderTexture(rt4, flagVal, 0);
        Composite(renderer2, 0, tex2, rt4);
    }
    else
    {
        GetRenderSys870()->EnableA(0, 0x16);
        GetRenderSys870()->EnableB(1, 0x16);
    }
    if (target)
        CopyTarget(flagVal, target);
    SetState870(1);
    if (BSShaderManager_GetImageSpaceEffects())
    {
        RenderAlt(flagVal, rt4, renderer2, target);
    }
    else if (target)
    {
        CopyTarget(flagVal, target);
    }
    RenderImageSpace(rt4, ism, renderer2, 0);
}

struct ShadowActor;
struct ShadowNode;
struct ShadowView;
struct ShadowMap;
struct ShadowVector
{
    float x, y, z;
};
struct ShadowBound
{
    float x, y, z, radius;
    float FUN_0084d030();
};
struct ShadowUpdate
{
    float time;
    int flags, frame;
    ShadowUpdate(float, bool, bool);
};
struct ShadowExtra
{
    const ShadowVector& FUN_00500940();
};
struct ShadowTransform
{
    void* FUN_0045bbe0();
};
struct ShadowNode
{
    int NiAVObject_GetParent();
    ShadowExtra* FUN_00a5bdd0(int);
    ShadowBound* NiAVObject_GetWorldBound();
    bool GetAppCulled_00456610();
    void FUN_00450f90(bool);
    const ShadowVector& NiAVObject_GetWorldTranslate();
    void NiAVObject_Update(ShadowUpdate*);
};
struct ShadowView
{
    void FUN_0041fd00(ShadowTransform*);
    void NiCullingProcess_SetFrustum(void*);
};
struct ShadowScene
{
    ShadowView* FUN_008d80e0();
    ShadowTransform* FUN_006629f0();
};
struct ShadowMap
{
    ShadowNode* ShadowSceneLight_GetLight();
    ShadowNode* ShadowSceneLight_GetShadowScene();
    bool ShadowSceneLight_IsFadedOut();
    void ShadowSceneLight_SetFadeTarget(float, bool);
    void UpdateOutputLight(int, ShadowVector);
    void ShadowSceneLight_TestFrustumCull(ShadowView*);
    unsigned short ShadowSceneLight_GetFrustumCull();
    float GetFirstLightParameter();
    void UpdateShadow(ShadowView*, int);
    void FUN_00b9fba0();
    void FUN_00ba0110(ShadowNode*);
    void ShadowSceneLight_RemoveUnusedGeom();
};
struct ShadowSystem
{
    void ShadowSceneNode_ReleaseAllShadowMaps();
    void ShadowSceneNode_DisableAllShadowLights();
    void FUN_00b5c3c0();
    void* FUN_00b5cbd0(ShadowNode*);
    void FUN_00b5cde0(void*);
    ShadowMap* FUN_00b5afc0();
    ShadowMap* FUN_00b5b010();
    void* ShadowSceneNode_QPortalGraph();
    void FUN_00b5d300(ShadowMap*);
    void FUN_00b5b880(ShadowView*);
};
struct ShadowRenderer
{
    void ResizeActivePool();
};
struct ShadowTarget
{
    void MTRenderingSystem_SetThreadStage();
    void MTRenderingSystem_WaitOnThreadStage();
};
struct ShadowEnvironment
{
    int FUN_005f36f0();
};
struct ShadowIntSetting
{
    int* Setting_Int();
};
struct ShadowBoolSetting
{
    bool* FUN_00408d60();
};
struct ShadowLock
{
    void BSSpinLock_Lock(int);
    void BSSpinLock_Unlock();
};
struct ShadowActors
{
    ShadowActor** TESDataHandler_GetFactions();
    int MissileProjectile_GetImpactResult();
};
extern ShadowEnvironment* DAT_011dea10;
extern ShadowActor* DAT_011dea3c;
extern ShadowIntSetting DAT_011c72d8, DAT_011c72e4;
extern ShadowBoolSetting DAT_011c71dc, DAT_011c7664;
extern ShadowLock DAT_011f1180;
extern const ShadowVector DAT_011f426c;
extern bool DAT_011def08;
const double DAT_01021928 = 3.0;
const double DAT_01082cb0 = 0.05;
bool BSShaderManager_GetShadows();
bool Main_GetSceneIsComplex();
void BSShaderManager_EnableShadows(bool);
bool TESRenderer_GetDoShadows();
void BSShaderManager_ResetNextAvailableShadowMapAccumulator();
ShadowSystem* FUN_00450b80(int);
void* __stdcall NiXenonRenderer_GetRenderer(int);
ShadowRenderer* __stdcall BSShaderManager_GetTextureManager(void*);
int BSBound_Tag();
float BSMAX_00404010(float, float);
ShadowNode* TESTerrainLODManager_GetGrassNode();
void BSFadeNode_SetFadeEnabled(bool);
ShadowTarget* __stdcall FUN_004ea970(int, int);
struct ShadowActor
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5C();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6C();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7C();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8C();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual void Slot9C();
    virtual void SlotA0();
    virtual void SlotA4();
    virtual void SlotA8();
    virtual void SlotAC();
    virtual void SlotB0();
    virtual void SlotB4();
    virtual void SlotB8();
    virtual void SlotBC();
    virtual void SlotC0();
    virtual void SlotC4();
    virtual void SlotC8();
    virtual void SlotCC();
    virtual void SlotD0();
    virtual void SlotD4();
    virtual void SlotD8();
    virtual void SlotDC();
    virtual void SlotE0();
    virtual void SlotE4();
    virtual void SlotE8();
    virtual void SlotEC();
    virtual void SlotF0();
    virtual void SlotF4();
    virtual void SlotF8();
    virtual void SlotFC();
    virtual void Slot100();
    virtual void Slot104();
    virtual void Slot108();
    virtual void Slot10C();
    virtual void Slot110();
    virtual void Slot114();
    virtual void Slot118();
    virtual void Slot11C();
    virtual void Slot120();
    virtual void Slot124();
    virtual void Slot128();
    virtual void Slot12C();
    virtual void Slot130();
    virtual void Slot134();
    virtual void Slot138();
    virtual void Slot13C();
    virtual void Slot140();
    virtual void Slot144();
    virtual void Slot148();
    virtual void Slot14C();
    virtual void Slot150();
    virtual void Slot154();
    virtual void Slot158();
    virtual void Slot15C();
    virtual void Slot160();
    virtual void Slot164();
    virtual void Slot168();
    virtual void Slot16C();
    virtual void Slot170();
    virtual void Slot174();
    virtual void Slot178();
    virtual void Slot17C();
    virtual void Slot180();
    virtual void Slot184();
    virtual void Slot188();
    virtual void Slot18C();
    virtual void Slot190();
    virtual void Slot194();
    virtual void Slot198();
    virtual void Slot19C();
    virtual void Slot1A0();
    virtual void Slot1A4();
    virtual void Slot1A8();
    virtual void Slot1AC();
    virtual void Slot1B0();
    virtual void Slot1B4();
    virtual void Slot1B8();
    virtual void Slot1BC();
    virtual void Slot1C0();
    virtual void Slot1C4();
    virtual void Slot1C8();
    virtual void Slot1CC();
    virtual ShadowNode* Get3D();
    virtual void Slot1D4();
    virtual void Slot1D8();
    virtual void Slot1DC();
    virtual void Slot1E0();
    virtual void Slot1E4();
    virtual void Slot1E8();
    virtual void Slot1EC();
    virtual void Slot1F0();
    virtual void Slot1F4();
    virtual void Slot1F8();
    virtual void Slot1FC();
    virtual void Slot200();
    virtual void Slot204();
    virtual void Slot208();
    virtual void Slot20C();
    virtual void Slot210();
    virtual int GetState();
    bool PlayerCharacter_Is3rdPerson();
    bool PlayerCharacter_IsVanityMode();
    bool IsRefractive();
    ShadowNode* PlayerCharacter_Get3D_00950bb0(int);
    bool Actor_HasShadow();
};
struct ShadowHost
{
    void Main_DrawWorld_UpdateOffscreenBuffers();
    void TESMain_UpdateOffscreenInterface();
};
// Toggles shadow rendering based on two flags, builds the shadow map from actors, renders visible shadow maps up to a limit, and resets unused shadow targets.
// @fnv 0x00871290
// src: XBOX_PDB 0x00871290
void ShadowHost::Main_DrawWorld_UpdateOffscreenBuffers()
{
    if (BSShaderManager_GetShadows() && Main_GetSceneIsComplex())
    {
        DAT_011def08 = BSShaderManager_GetShadows();
        BSShaderManager_EnableShadows(false);
        ShadowSystem* system = FUN_00450b80(0);
        system->ShadowSceneNode_ReleaseAllShadowMaps();
        BSShaderManager_GetTextureManager(NiXenonRenderer_GetRenderer(0))->ResizeActivePool();
    }
    else if (DAT_011def08 && !Main_GetSceneIsComplex())
    {
        DAT_011def08 = false;
        BSShaderManager_EnableShadows(true);
        int limit = DAT_011dea10->FUN_005f36f0() ? *DAT_011c72d8.Setting_Int() : *DAT_011c72e4.Setting_Int();
        BSShaderManager_GetTextureManager(NiXenonRenderer_GetRenderer(limit))->ResizeActivePool();
    }
    if (BSShaderManager_GetShadows() && TESRenderer_GetDoShadows())
    {
        BSShaderManager_ResetNextAvailableShadowMapAccumulator();
        ShadowSystem* system = FUN_00450b80(0);
        system->ShadowSceneNode_DisableAllShadowLights();
        int limit = DAT_011dea10->FUN_005f36f0() ? *DAT_011c72d8.Setting_Int() : *DAT_011c72e4.Setting_Int();
        BSShaderManager_GetTextureManager(NiXenonRenderer_GetRenderer(limit))->ResizeActivePool();
        if (!limit)
            system->FUN_00b5c3c0();
        else
        {
            void* playerShadow32 = 0;
            int count33 = 0;
            if ((DAT_011dea3c->PlayerCharacter_Is3rdPerson() || DAT_011dea3c->PlayerCharacter_IsVanityMode()) && !DAT_011dea3c->IsRefractive())
            {
                playerShadow32 = system->FUN_00b5cbd0(DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(0));
                ++count33;
            }
            DAT_011f1180.BSSpinLock_Lock(0);
            ShadowActor** actors8 = ((ShadowActors*)&DAT_011e0e80)->TESDataHandler_GetFactions();
            int actorCount72 = ((ShadowActors*)&DAT_011e0e80)->MissileProjectile_GetImpactResult();
            for (int i = 0; i < actorCount72 && count33 < limit; ++i)
            {
                ShadowActor* actor = actors8[i];
                if (actor->Get3D() && actor->Get3D()->NiAVObject_GetParent() && actor->Actor_HasShadow() &&
                    actor->GetState() != 4 && !actor->IsRefractive())
                {
                    ShadowExtra* extra6 = actor->Get3D()->FUN_00a5bdd0(BSBound_Tag());
                    ShadowVector dimensions4 = extra6 ? extra6->FUN_00500940() : DAT_011f426c;
                    float maximum37 = BSMAX_00404010(BSMAX_00404010(dimensions4.x, dimensions4.y), dimensions4.z);
                    if (maximum37 * DAT_01021928 > actor->Get3D()->NiAVObject_GetWorldBound()->FUN_0084d030())
                    {
                        system->FUN_00b5cbd0(actor->Get3D());
                        ++count33;
                    }
                }
            }
            DAT_011f1180.BSSpinLock_Unlock();
            system->FUN_00b5cde0(playerShadow32);
            ShadowNode* playerNode50 = DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(1);
            if (playerNode50)
            {
                ShadowScene* scene9 = (ShadowScene*)Main_GetWorldSceneGraph();
                ShadowView* view8 = scene9->FUN_008d80e0();
                view8->FUN_0041fd00(scene9->FUN_006629f0());
                view8->NiCullingProcess_SetFrustum(scene9->FUN_006629f0()->FUN_0045bbe0());
                bool playerHidden14 = playerNode50->GetAppCulled_00456610();
                playerNode50->FUN_00450f90(true);
                ShadowNode* specialNode3 = TESTerrainLODManager_GetGrassNode();
                BSFadeNode_SetFadeEnabled(false);
                bool specialHidden29 = false;
                if (specialNode3)
                {
                    specialHidden29 = specialNode3->GetAppCulled_00456610();
                    if (!*DAT_011c71dc.FUN_00408d60())
                        specialNode3->FUN_00450f90(true);
                }
                ShadowMap* shadow4 = system->FUN_00b5afc0();
                int rendered62 = 0;
                while (shadow4)
                {
                    if (shadow4->ShadowSceneLight_GetLight() && shadow4->ShadowSceneLight_GetShadowScene())
                    {
                        if (!shadow4->ShadowSceneLight_IsFadedOut() && shadow4->ShadowSceneLight_GetLight()->GetAppCulled_00456610())
                        {
                            if (shadow4->ShadowSceneLight_GetShadowScene()->GetAppCulled_00456610())
                                shadow4->ShadowSceneLight_SetFadeTarget(0.0f, true);
                            else
                            {
                                if (rendered62 < limit)
                                    shadow4->ShadowSceneLight_GetLight()->FUN_00450f90(false);
                                shadow4->ShadowSceneLight_SetFadeTarget(0.0f, false);
                            }
                        }
                        if (rendered62 < limit && !shadow4->ShadowSceneLight_GetLight()->GetAppCulled_00456610() &&
                            !shadow4->ShadowSceneLight_GetShadowScene()->GetAppCulled_00456610())
                        {
                            ShadowBound bounds = *shadow4->ShadowSceneLight_GetShadowScene()->NiAVObject_GetWorldBound();
                            shadow4->UpdateOutputLight(0, shadow4->ShadowSceneLight_GetShadowScene()->NiAVObject_GetWorldTranslate());
                            shadow4->ShadowSceneLight_TestFrustumCull(view8);
                            if (shadow4->ShadowSceneLight_GetFrustumCull() != 255 && shadow4->GetFirstLightParameter() >= DAT_01082cb0)
                            {
                                ++rendered62;
                                ShadowUpdate update53(0.0f, false, false);
                                shadow4->ShadowSceneLight_GetLight()->NiAVObject_Update(&update53);
                                shadow4->UpdateShadow(view8, rendered62 - 1);
                                shadow4->FUN_00b9fba0();
                                void* renderer12 = FUN_00450b80(0)->ShadowSceneNode_QPortalGraph();
                                FUN_00450b80(0)->FUN_00b5d300(shadow4);
                                if (*DAT_011c7664.FUN_00408d60())
                                    shadow4->FUN_00ba0110(shadow4->ShadowSceneLight_GetShadowScene());
                                shadow4->ShadowSceneLight_RemoveUnusedGeom();
                            }
                            else
                                shadow4->ShadowSceneLight_GetLight()->FUN_00450f90(true);
                        }
                        else
                            shadow4->ShadowSceneLight_GetLight()->FUN_00450f90(true);
                    }
                    shadow4 = system->FUN_00b5b010();
                }
                while (rendered62 + 17 < 21)
                {
                    FUN_004ea970(0, rendered62 + 17)->MTRenderingSystem_SetThreadStage();
                    ++rendered62;
                }
                if (specialNode3)
                    specialNode3->FUN_00450f90(specialHidden29);
                BSFadeNode_SetFadeEnabled(true);
                system->FUN_00b5b880(view8);
                playerNode50->FUN_00450f90(playerHidden14);
            }
        }
    }
    else
    {
        for (int i = 17; i < 21; ++i)
        {
            FUN_004ea970(0, i)->MTRenderingSystem_SetThreadStage();
            FUN_004ea970(1, i)->MTRenderingSystem_WaitOnThreadStage();
        }
    }
    TESMain_UpdateOffscreenInterface();
}

namespace fnv_00871a50 {
extern bool __cdecl Interface_IsInMenuMode();
extern bool __cdecl Interface_IsInRenderedMenu();
extern bool __cdecl Interface_IsInPipboyMenu();
extern void __cdecl Interface_LastMinuteUpdate();
extern bool __cdecl Interface_IsActiveMenuTheRenderedMenu();
extern bool __cdecl Interface_IsMenuIDVisible(unsigned int, int);
struct RenderFlag
{
    bool* FUN_00408d60();
};
extern RenderFlag DAT_011db2cc, DAT_011d8ba0;
struct RenderNode
{
    void SetScreenTexture(int);
    bool GetAppCulled_00456610();
    void FUN_00450f90(bool);
};
struct UiMenu
{
    RenderNode* GetModel_0056c7f0();
};
extern UiMenu* __cdecl Tile_GetMenuByClass(unsigned int);
extern RenderNode* __cdecl Interface_GetPipboy();
struct UiRenderer
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void Draw(RenderNode*, bool, int);
};
extern UiRenderer* __cdecl Interface_GetCurrentRenderedMenu();
struct RenderHolder
{
    RenderNode* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(RenderNode*);
};
extern RenderHolder DAT_011dec64;
struct RenderTextureSource
{
    RenderNode* BSTextureManager_BorrowRenderedTexture();
};
extern RenderTextureSource* __stdcall BSShaderManager_GetTextureManager(void*, int, int, int, int);
extern void* __cdecl NiXenonRenderer_GetRenderer();
extern const char DAT_010829c4[];
struct HudRenderPass
{
    void TESMain_UpdateOffscreenInterface();
};
// When the HUD conditions hold, ensures the render holder has a node, draws it via the UI renderer, and temporarily hides menu 1001's node while drawing.
// @fnv 0x00871a50
// src: COMMUNITY 0x00871a50
void HudRenderPass::TESMain_UpdateOffscreenInterface()
{
    if (Interface_IsInMenuMode() && (*DAT_011db2cc.FUN_00408d60() || *DAT_011d8ba0.FUN_00408d60()) && Interface_IsInRenderedMenu())
    {
        AutoMemHelper kContext(13, true, DAT_010829c4, 0x1ade);
        bool wasActive = Interface_IsInPipboyMenu();
        if (Interface_IsInMenuMode())
            Interface_LastMinuteUpdate();
        if (!DAT_011dec64.Modelloader_GetReferencedThis())
            DAT_011dec64.FUN_0066b0d0(BSShaderManager_GetTextureManager(NiXenonRenderer_GetRenderer(), 45, 0, 0, 0)->BSTextureManager_BorrowRenderedTexture());
        if (!wasActive)
            Interface_GetPipboy()->SetScreenTexture(0);
        bool show = Interface_IsActiveMenuTheRenderedMenu() || Tile_GetMenuByClass(1001) || Tile_GetMenuByClass(1016) || Tile_GetMenuByClass(1059);
        if (Interface_IsInRenderedMenu() && show)
        {
            bool hide = wasActive && Interface_IsMenuIDVisible(1001, 0);
            bool previous5 = 0;
            RenderNode* node_2 = 0;
            if (hide)
            {
                node_2 = Tile_GetMenuByClass(1001)->GetModel_0056c7f0();
                previous5 = node_2->GetAppCulled_00456610();
                node_2->FUN_00450f90(true);
            }

            Interface_GetCurrentRenderedMenu()->Draw(DAT_011dec64.Modelloader_GetReferencedThis(), true, 0);
            if (hide)
                node_2->FUN_00450f90(previous5);
        }
    }
    else if (Interface_IsInMenuMode())
        Interface_LastMinuteUpdate();
}
}  // namespace fnv_00871a50

namespace fnv_00871dc0 {
struct RenderSurface
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual unsigned int Width(unsigned int);
    virtual unsigned int Height(unsigned int);
};
using ::NiRenderer;
NiRenderer* NiXenonRenderer_GetRenderer();
struct MTRenderer
{
    void MTRenderingSystem_StartThreads();
    void MTRenderingSystem_WaitForThreads();
    void MTRenderingSystem_SetThreadStage(int, int);
    void MTRenderingSystem_WaitOnThreadStage(int, int);
};
MTRenderer* FUN_004ea970();
void AutoTileLock_AutoTileLock();
void Object___imp__LeaveCriticalSection_Thunk();
struct MenuTarget
{
    unsigned int BSRenderedTexture_GetWidth(unsigned int);
    unsigned int BSRenderedTexture_GetHeight(unsigned int);
};
struct MenuTargetPointer
{
    MenuTarget* value;
    MenuTarget* Get() const;
    void operator=(MenuTarget*);
};
extern MenuTargetPointer g_011ded3c;
struct TextureMgr
{
    void BSTextureManager_ReturnRenderedTexture(MenuTarget*);
    MenuTarget* BSTextureManager_BorrowRenderedTexture(NiRenderer*, int, int, int, int);
};
TextureMgr* __stdcall BSShaderManager_GetTextureManager();
extern bool DAT_011ad884;
extern bool DAT_011f9426;
extern bool DAT_011dea29;
struct Rect
{
    float left, right, top, bottom;
    Rect(float, float, float, float);
};
struct Camera
{
    void FUN_00712e60(const Rect&);
};
Camera* Main_WorldRootCamera();
extern Rect DAT_011ad840;
float BSMIN(float, float);
struct Modifier;
InterfaceManager* InterfaceManager_GetSingleton();
Modifier* TESImageSpaceModifier_GetGetHit();
void FUN_00529c90(Modifier*);
void FUN_005299a0(Modifier*, float, void*);
bool Interface_IsInPipboyMenu();
bool Interface_IsMenuIDVisible(int, unsigned int);
bool IsStartMenuFlag1Set();
struct RenderMenu
{
    void* FUN_008b6200();
    void* GetMenuRoot();
};
RenderMenu* Interface_GetCurrentRenderedMenu();
using ::BSCullingProcess;
struct SceneObject
{
    void BSShaderAccumulator_SetShadowSceneNode(void*);
};
void* FUN_00450b80(int);
void BSShaderUtil_AccumulateScene(void*, void*, BSCullingProcess*);
void FUN_00b6c0d0(void*, MenuTarget*, int);
struct FUN_00871dc0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    MenuTargetPointer unk98;
    bool unk9c;
    void Main_OnIdle_UpdateImageSpace(int);
    void Main_DrawWorld(MenuTarget*, int, bool);
    void Main_RenderMenuBackground();
};
// @fnv 0x00871dc0
// src: XBOX_PDB 0x00871dc0
void FUN_00871dc0_class::Main_RenderMenuBackground()
{
    AutoMemHelper modifier(13, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 7193);
    if (!g_thePlayer->GetParentCell() || !g_thePlayer->GetNiNode())
        return;
    bool menu = DAT_011ad884;
    DAT_011ad884 = true;
    unk9c = true;
    NiXenonRenderer_GetRenderer()->NiXenonRenderer_LockRenderer();
    AutoTileLock_AutoTileLock();
    FUN_004ea970()->MTRenderingSystem_StartThreads();
    if (g_011ded3c.Get())
        BSShaderManager_GetTextureManager()->BSTextureManager_ReturnRenderedTexture(g_011ded3c.Get());
    g_011ded3c = BSShaderManager_GetTextureManager()->BSTextureManager_BorrowRenderedTexture(NiXenonRenderer_GetRenderer(), 6, 0, 0, 0);
    if (reinterpret_cast<RenderSurface*>(static_cast< ::NiDX9Renderer*>(NiXenonRenderer_GetRenderer())->GetDefaultRT())->Width(0) != g_011ded3c.Get()->BSRenderedTexture_GetWidth(0) ||
        reinterpret_cast<RenderSurface*>(static_cast< ::NiDX9Renderer*>(NiXenonRenderer_GetRenderer())->GetDefaultRT())->Height(0) != g_011ded3c.Get()->BSRenderedTexture_GetHeight(0))
    {
        float x =
            BSMIN((float)reinterpret_cast<RenderSurface*>(static_cast< ::NiDX9Renderer*>(NiXenonRenderer_GetRenderer())->GetDefaultRT())->Width(0) / (float)g_011ded3c.Get()->BSRenderedTexture_GetWidth(0), 1.0f);
        float y =
            BSMIN((float)reinterpret_cast<RenderSurface*>(static_cast< ::NiDX9Renderer*>(NiXenonRenderer_GetRenderer())->GetDefaultRT())->Height(0) / (float)g_011ded3c.Get()->BSRenderedTexture_GetHeight(0), 1.0f);
        Main_WorldRootCamera()->FUN_00712e60(Rect(0, x, y, 0));
    }
    else if (DAT_011f9426)
        Main_WorldRootCamera()->FUN_00712e60(DAT_011ad840);
    Modifier* mem = (Modifier*)InterfaceManager_GetSingleton()->InterfaceManager_GetCurrentImagespaceMod();
    FUN_00529c90(TESImageSpaceModifier_GetGetHit());
    if (mem)
    {
        FUN_005299a0(mem, 1.0f, 0);
        Main_OnIdle_UpdateImageSpace(0);
    }
    bool old = Interface_IsInPipboyMenu();
    if (Interface_IsMenuIDVisible(0x3f5, 0))
        old = false;
    Main_DrawWorld(g_011ded3c.Get(), 0, old);
    if (Interface_IsMenuIDVisible(0x40c, 0) && IsStartMenuFlag1Set())
    {
        BSCullingProcess cull((void*)0);
        void* camera = Interface_GetCurrentRenderedMenu()->FUN_008b6200();
        cull.SetCamera(camera);
        cull.SetAccumulator((::MenuTarget*)unk98.Get());
        ((SceneObject*)unk98.Get())->BSShaderAccumulator_SetShadowSceneNode(FUN_00450b80(1));
        BSShaderUtil_AccumulateScene(camera, Interface_GetCurrentRenderedMenu()->GetMenuRoot(), &cull);
        FUN_00b6c0d0(camera, unk98.Get(), 0);
        cull.SetAccumulator((::MenuTarget*)0);
    }
    if (mem)
    {
        FUN_00529c90(mem);
        Main_OnIdle_UpdateImageSpace(0);
    }
    FUN_004ea970()->MTRenderingSystem_SetThreadStage(0, 0x17);
    FUN_004ea970()->MTRenderingSystem_WaitOnThreadStage(1, 0x17);
    FUN_004ea970()->MTRenderingSystem_WaitForThreads();
    DAT_011dea29 = true;
    Main_WorldRootCamera()->FUN_00712e60(Rect(0, 1, 1, 0));
    Object___imp__LeaveCriticalSection_Thunk();
    NiXenonRenderer_GetRenderer()->NiXenonRenderer_UnlockRenderer();
    unk9c = false;
    DAT_011ad884 = menu;
}
}  // namespace fnv_00871dc0

struct FUN_00872780_Class
{
    int unk00;
    int unk04;
    int unk08;
    FUN_008727b0_Class* callback;
    char BGSMoviePlayer_IsPlaying();
};
// Returns the result of calling callback->FUN_008727b0() if callback is set, otherwise returns 0.
// @fnv 0x00872780
// src: COMMUNITY 0x00872780
char FUN_00872780_Class::BGSMoviePlayer_IsPlaying()
{
    return callback ? callback->TESSaveLoadGame_GetInitArrayExists() : static_cast<char>(0);
}

extern double DAT_01082d20;
extern const char str_010829c4[];

struct NiRenderTargetGroup;
struct TexObj
{
    unsigned int BSRenderedTexture_GetWidth(unsigned int i);
    unsigned int BSRenderedTexture_GetHeight(unsigned int i);
    void BSRenderedTexture_UsePreRestoreGroup();
};
extern BSRenderedTexture* DAT_011f9438;

struct P1
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual NiRenderTargetGroup* GetRenderGroup();
    unsigned int FUN_004dee10();
    unsigned int FUN_004dee70();
};

struct Mgr
{
    BSRenderedTexture* BSTextureManager_BorrowRenderedTexture();
};
Mgr* __stdcall BSShaderManager_GetTextureManager(P1* a, int b, int c, int d, int e);

unsigned char BSShaderManager_GetImageSpaceEffects();
double dMin(double b, float a);
void __cdecl BSRenderedTexture_StartOffscreen(unsigned int id, NiRenderTargetGroup* ausAnimationGroup);
void __cdecl BSRenderedTexture_Start(unsigned int id, NiRenderTargetGroup* ausAnimationGroup);

::BSFaceGenAnimationData* __cdecl Main_WorldRootCamera();

struct Host
{
    BSRenderedTexture* TESMain_DrawWorld_InitRenderTexture(P1* a1, BSRenderedTexture* a2, unsigned char a3, unsigned char a4);
};

// @fnv 0x00872f50
// src: COMMUNITY 0x00872f50
BSRenderedTexture* Host::TESMain_DrawWorld_InitRenderTexture(P1* apSource, BSRenderedTexture* apFallbackTexture, unsigned char abSkipCreate,
                                      unsigned char abUseSourceGroup)
{
    BSRenderedTexture* tex = 0;
    if (BSShaderManager_GetImageSpaceEffects() && !abSkipCreate)
    {
        AutoMemHelper helper(0x27, true, str_010829c4, 0x1e6d);
        tex = BSShaderManager_GetTextureManager(apSource, 4, 0, 0, 0)->BSTextureManager_BorrowRenderedTexture();
        ((TexObj*)tex)->BSRenderedTexture_UsePreRestoreGroup();
        DAT_011f9438 = tex;
        if (apSource->FUN_004dee10() != ((TexObj*)tex)->BSRenderedTexture_GetWidth(0) ||
            apSource->FUN_004dee70() != ((TexObj*)tex)->BSRenderedTexture_GetHeight(0))
        {
            float fa;
            fa = (float)dMin(
                (double)apSource->FUN_004dee10() * DAT_01082d20 / (double)((TexObj*)tex)->BSRenderedTexture_GetWidth(0), 1.0f);
            float fb;
            fb = (float)dMin(
                (double)apSource->FUN_004dee70() * DAT_01082d20 / (double)((TexObj*)tex)->BSRenderedTexture_GetHeight(0), 1.0f);
            Main_WorldRootCamera()->FUN_00712e60(&(NiColorA&)NiColorA(0.0f, fa, fb, 0.0f));
        }
        BSRenderedTexture_StartOffscreen(7, tex->GetGroup());
    }
    else
    {
        AutoMemHelper helper(0x26, true, str_010829c4, 0x1e84);
        if (apFallbackTexture)
        {
            if (abUseSourceGroup)
            {
                BSRenderedTexture_StartOffscreen(7, apSource->GetRenderGroup());
            }
            else
            {
                BSRenderedTexture_StartOffscreen(7, apFallbackTexture->GetGroup());
            }
        }
        else
        {
            BSRenderedTexture_Start(7, 0);
        }
    }
    return tex;
}

namespace fnv_00874c10 {
using ::BSFaceGenNiNode;
BSFaceGenNiNode* __cdecl Main_GetWorldSceneGraph();

using ::BSFaceGenAnimationData;
BSFaceGenAnimationData* __cdecl Main_WorldRootCamera();

struct TransformState
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    float tx, ty, tz;
    float scale;
};

struct AnimDataHelper
{
    float FUN_006447f0();
    void* FUN_0045bbe0();
    void* TESDataHandler_GetImpactDataSetList();
    TransformState* NiAVObject_GetWorldRotate();
};

using ::NiUpdateData;

struct NiPoint3WithNeg : public NiPoint3
{
    NiPoint3 GetNegatedVector() const;
};

using ::NiNode;

struct PlayerObjectHelper
{
    NiPoint3* NiAVObject_GetWorldTranslate();
};

struct PlayerHelper
{
    NiNode* PlayerCharacter_Get3D_00950bb0(bool);
    PlayerObjectHelper* PlayerCharacter_GetWeaponSightingNode();
    bool Actor_IsReloading();
    bool PlayerCharacter_IsPipboyActive();
};

struct AudioGlobalHelper
{
    bool TESRegionData_GetPriority();
};
extern AudioGlobalHelper* DAT_011dea0c;

struct CameraHelper
{
    NiPoint3* NiAVObject_GetWorldTranslate();
};
extern CameraHelper* DAT_011e07d0;

struct VATSHelper
{
    bool VATS_IsInVats();
};
extern VATSHelper DAT_011f2250;

using ::BGSBodyPart;
BGSBodyPart* __fastcall MenuPart_006838b0(::FORenderedMenu*);

using ::FORenderedMenu;
FORenderedMenu* __cdecl Interface_GetPipboy();
FORenderedMenu* __cdecl Interface_GetCurrentRenderedMenu();

struct MTRenderingSystem_Helper
{
    void MTRenderingSystem_SetThreadStage(int, int);
    void MTRenderingSystem_AddAccumTask(void*, int, void*, int, int, void*, int, int, int);
};
MTRenderingSystem_Helper* __cdecl FUN_004ea970();

struct ObjectA0
{
    void NiCamera_SetMaxFarNearRatio(float);
    void FUN_00a6faf0(void*);
    void FUN_00712e60(void*);
    void NiAVObject_SetWorldTranslate(const NiPoint3&);
    void NiAVObject_SetWorldRotate(TransformState*);
    NiPoint3* NiAVObject_GetWorldTranslate();
};

struct Object8C
{
};

template <class T> struct TargetPointer
{
    T* m_pObject;
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
};

using ::NiRenderer;
NiRenderer* __cdecl NiXenonRenderer_GetRenderer();


void* __cdecl FUN_00450b80(int);

extern const char str_010829c4[];
extern unsigned char DAT_011f9426;
extern int DAT_011ad840;
extern unsigned char DAT_011de9d1;

struct MainShell
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
    TargetPointer<Object8C> spObj8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    TargetPointer<ObjectA0> spObjA0;

    void Main_DrawWorld_MTSetup1stPerson();
};

// Updates the player's face gen node and render objects, toggling DAT_011de9d1 and submitting spObjA0/spObj8C to the rendering system.
// @fnv 0x00874c10
// src: XBOX_PDB 0x00874c10
void MainShell::Main_DrawWorld_MTSetup1stPerson()
{
    AutoMemHelper memHelper5(0x34, 1, str_010829c4, 0x21b1);
    BSFaceGenNiNode* pFaceGenNode2 = Main_GetWorldSceneGraph();
    BSFaceGenAnimationData* pAnimData = Main_WorldRootCamera();
    NiNode* _pPlayerNode = ((PlayerHelper*)g_thePlayer)->PlayerCharacter_Get3D_00950bb0(1);
    _pPlayerNode->FUN_00450f90(0);

    if (DAT_011f9426)
    {
        if (static_cast< ::NiDX9Renderer*>(NiXenonRenderer_GetRenderer())->GetCurrentRT() == 0 || static_cast< ::NiDX9Renderer*>(NiXenonRenderer_GetRenderer())->GetCurrentRT() == static_cast< ::NiDX9Renderer*>(NiXenonRenderer_GetRenderer())->GetDefaultRT())
        {
            Main_WorldRootCamera()->FUN_00712e60(&DAT_011ad840);
        }
    }

    pFaceGenNode2->SceneGraph_SetCameraFOV(PlayerCharacter_Get1stPersonFOV((const char*)g_thePlayer), 0, 0, 0);

    if (((!((PlayerHelper*)g_thePlayer)->PlayerCharacter_Get3D_00950bb0(0)->GetAppCulled_00456610() &&
          !((PlayerHelper*)g_thePlayer)->PlayerCharacter_Get3D_00950bb0(1)->GetAppCulled_00456610() == 0) ||
         (!((PlayerHelper*)g_thePlayer)->PlayerCharacter_Get3D_00950bb0(0)->GetAppCulled_00456610() == 0 &&
          !((PlayerHelper*)g_thePlayer)->PlayerCharacter_Get3D_00950bb0(1)->GetAppCulled_00456610())) &&
        !DAT_011dea0c->TESRegionData_GetPriority())
    {
        NiPoint3 pt_5c3 = reinterpret_cast<const NiPoint3WithNeg&>(_pPlayerNode->NiAVObject_GetWorldTranslate()).GetNegatedVector();
        NiUpdateData updateData7(0.0f, 0, 0);
        DAT_011de9d1 = 1;

        spObjA0->NiCamera_SetMaxFarNearRatio(((AnimDataHelper*)pAnimData)->FUN_006447f0());
        spObjA0->FUN_00a6faf0(((AnimDataHelper*)pAnimData)->FUN_0045bbe0());
        spObjA0->FUN_00712e60(((AnimDataHelper*)pAnimData)->TESDataHandler_GetImpactDataSetList());

        TransformState kTransform = *((AnimDataHelper*)pAnimData)->NiAVObject_GetWorldRotate();
        spObjA0->NiAVObject_SetWorldTranslate(*DAT_011e07d0->NiAVObject_GetWorldTranslate() + pt_5c3);
        spObjA0->NiAVObject_SetWorldRotate(&kTransform);

        if (((PlayerHelper*)g_thePlayer)->PlayerCharacter_GetWeaponSightingNode() && !((PlayerHelper*)g_thePlayer)->Actor_IsReloading() &&
            !DAT_011f2250.VATS_IsInVats())
        {
            spObjA0->NiAVObject_SetWorldTranslate(*((PlayerHelper*)g_thePlayer)->PlayerCharacter_GetWeaponSightingNode()->NiAVObject_GetWorldTranslate() + pt_5c3);
        }

        NiPoint3 pt_6c_ = reinterpret_cast<const NiPoint3&>(_pPlayerNode->GetTranslate_0043c490());
        _pPlayerNode->NiAVObject_SetTranslate(reinterpret_cast<const ::NiPoint3*>(&NiPoint3::ZERO));
        _pPlayerNode->Update(&updateData7);
        _pPlayerNode->NiAVObject_SetTranslate(reinterpret_cast<const ::NiPoint3*>(&pt_6c_));

        BGSBodyPart* pBodyPart3 =
            ((PlayerHelper*)g_thePlayer)->PlayerCharacter_IsPipboyActive() ? (pBodyPart3 = MenuPart_006838b0(Interface_GetPipboy())) : 0;
        _pPlayerNode->NiAVObject_SetAlwaysDraw(1);

        if (pBodyPart3)
        {
            pBodyPart3->NiAVObject_SetWorldTranslate(*pBodyPart3->NiAVObject_GetWorldTranslate() - reinterpret_cast<const ::NiPoint3&>(pt_5c3));
        }

        ShadowSceneNode_SetEyePosition((::ShadowSceneNode*)FUN_00450b80(0), *spObjA0->NiAVObject_GetWorldTranslate());
        ShadowSceneNode_SetLightingOffset((::ShadowSceneNode*)FUN_00450b80(0), pt_5c3);
    }
    else
    {
        DAT_011de9d1 = 0;
    }

    if (Interface_GetCurrentRenderedMenu() && Interface_GetCurrentRenderedMenu() != Interface_GetPipboy())
    {
    }
    else
    {
        FUN_004ea970()->MTRenderingSystem_AddAccumTask(spObjA0, 0, _pPlayerNode, 0, 0, spObj8C, 0, 0x16, 0);
    }
    FUN_004ea970()->MTRenderingSystem_SetThreadStage(0, 0x16);
}
}  // namespace fnv_00874c10

namespace SetRenderCamera {
struct Scene;
struct Context;
struct Pointer;
struct List;
using ::NiPoint3;
struct Rect
{
    float left, right, top, bottom;
    Rect(float, float, float, float);
};
struct Update
{
    float time;
    unsigned int flags, other;
    Update(float, int, int);
};
struct Guard
{
    unsigned int state;
    Guard(int, int, const char*, int);
    ~Guard();
};
struct VecRef
{
    NiPoint3* GetTranslate_0043c490();
};
struct Scene
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual Scene* Node();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual bool Active();
    virtual void slotc4();
    virtual void* Secondary();
    virtual void* Primary();
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned short unk38;
    unsigned char visible, unk3b;
    void FUN_00450f90(bool);
    void RendererClearBufferHook(int, int);
    void FUN_00712e60(const Rect&);
    void FUN_00a6faf0(void*);
    void SetScreenTexture(int);
    Scene* SkyObject_GetNiNode();
    Scene* FOPipboyManager_GetPipboyLightGlow(int);
    Scene* FUN_00a59d30(void*);
    void NiAlphaProperty_SetAlphaBlending(int);
    NiPoint3* NiAVObject_GetWorldTranslate();
    void* FUN_0045bbe0();
    void NiAVObject_SetWorldTranslate(const NiPoint3&);
    void MobileObject_SetSoundCallBackSuccess(bool);
    void Object_DoNothing();
    void* FUN_00b6b260();
    void BSShaderAccumulator_RenderNormals(Scene*, Scene*);
    void NiAVObject_Update(const Update&);
    void NiAVObject_SetAlwaysDraw(int);
    VecRef* NiAVObject_GetParent();
    void ShadowSceneNode_SetEyePosition(NiPoint3);
    void ShadowSceneNode_SetLightingOffset(NiPoint3);
    Scene* NiObjectNET_GetControllers();
    bool GetAppCulled_00456610();
    void FUN_006426a0(int, Scene*, Scene*);
    Context* FUN_008d80e0();
    Scene* FUN_006629f0();
    void SceneGraph_SetCameraFOV(float, int, int, int);
    void MTRenderingSystem_WaitOnThreadStage(int, int);
};
struct Output : Scene
{
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    Output(int, int, int);
    static __forceinline void* operator new(unsigned int);
    static __forceinline void operator delete(void*)
    {}
};
void* Object_DispatchCommandFour(unsigned int);
__forceinline void* Output::operator new(unsigned int n)
{
    return Object_DispatchCommandFour(n);
}
struct Pointer
{
    Scene* value;
    Pointer(Scene*);
    Pointer(const Pointer&);
    ~Pointer();
    Scene* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(Scene*);
};
struct Context
{
    void BSCullingProcess_PushCullMode(int);
    void BSCullingProcess_SetAccumulator(Scene*);
    void BSCullingProcess_PopCullMode();
};
struct List
{
    bool BSSimpleList_NiRefObjectPtr_IsEmpty();
    Pointer* FUN_006815c0();
    List* FUN_00726070();
};
struct ListRef
{
    List* GetTranslate_0043c490();
};
struct Mode
{
    bool VATS_IsInVats();
    int FUN_0044ddc0();
};
struct Player
{
    Scene* PlayerCharacter_Get3D_00950bb0(int);
    float PlayerCharacter_Get1stPersonFOV();
    float PlayerCharacter_GetWorldFOV();
    bool IsRefractive();
    Scene* PlayerCharacter_GetWeaponSightingNode();
    bool Actor_IsReloading();
};
extern Player* DAT_011dea3c;
extern bool DAT_011f9426, DAT_011de9d1;
extern Rect DAT_011ad840;
extern const char DAT_010829c4[];
extern Scene* DAT_011f9438;
extern ListRef DAT_011e0e80;
extern Mode DAT_011f2250;
extern Scene* DAT_011e07d0;
extern NiPoint3 DAT_011f426c;
extern Pointer DAT_011deb7c;
Scene* Main_GetWorldSceneGraph();
Scene* FUN_004ea970();
Scene* NiXenonRenderer_GetRenderer();
void FUN_00b54000(float);
Scene* Interface_GetCurrentRenderedMenu();
Scene* Interface_GetPipboy();
bool Interface_IsInRenderedMenu();
bool Interface_IsInPipboyMenu();
void* MagicSystem_CheckEffectFlares();
void BSShaderUtil_AccumulateScene(Scene*, Scene*, Context*);
void FUN_00b6c0d0(Scene*, Scene*, int);
void FUN_00b98380(int, int);
void BSRenderState_RestoreColorWriteEnable(int);
bool BSShaderManager_IsRefractionEnabled();
void FUN_00b6b790();
void BSRenderedTexture_StartOffscreen(int, void*);
Scene* Main_WorldRootCamera();
Scene* FUN_00450b80(int);
struct Main
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    Pointer texture, surface;
    unsigned int unk90, unk94, unk98, unk9c;
    Pointer camera;
    void TESMain_DrawWorld_RestartRenderTexture(Scene*, int, int);
    void TESMain_DrawWorld_MTRender1stPerson(Scene*, Scene*, Scene*, Scene*);
};
// @fnv 0x00875110
// src: COMMUNITY 0x00875110
void Main::TESMain_DrawWorld_MTRender1stPerson(Scene* root, Scene* firstPerson, Scene* extra, Scene* pass)
{
    Scene* renderSlot52 = Main_GetWorldSceneGraph();
    Context* contextSlot26 = renderSlot52->FUN_008d80e0();
    Scene* playerSceneSlot0 = DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(1);
    playerSceneSlot0->FUN_00450f90(0);
    Scene* viewSlot23 = renderSlot52->FUN_006629f0();
    Scene* aliasSlot0 = playerSceneSlot0;
    FUN_004ea970()->MTRenderingSystem_WaitOnThreadStage(1, 22);
    surface.Modelloader_GetReferencedThis()->visible = 0;
    Guard guardSlot1(0x34, 1, DAT_010829c4, 0x221f);
    root->RendererClearBufferHook(0, 4);
    if (DAT_011f9426 && (!NiXenonRenderer_GetRenderer()->Primary() || NiXenonRenderer_GetRenderer()->Primary() == NiXenonRenderer_GetRenderer()->Secondary()))
        camera.Modelloader_GetReferencedThis()->FUN_00712e60(DAT_011ad840);
    else
        camera.Modelloader_GetReferencedThis()->FUN_00712e60(Rect(0, 1, 1, 0));
    renderSlot52->SceneGraph_SetCameraFOV(DAT_011dea3c->PlayerCharacter_Get1stPersonFOV(), 0, 0, 0);
    FUN_00b54000(DAT_011dea3c->PlayerCharacter_Get1stPersonFOV());
    camera.Modelloader_GetReferencedThis()->FUN_00a6faf0(viewSlot23->FUN_0045bbe0());
    if (firstPerson)
    {
        Interface_GetCurrentRenderedMenu()->SetScreenTexture(0);
        firstPerson->FUN_00450f90(0);
        if (Interface_IsInRenderedMenu())
        {
            if (Interface_IsInPipboyMenu() && DAT_011dea3c->IsRefractive())
                Interface_GetCurrentRenderedMenu()->SkyObject_GetNiNode()->FUN_00450f90(1);
            Pointer tempTextureSlot13(new Output(99, 1, 759));
            contextSlot26->BSCullingProcess_PushCullMode(1);
            Scene* property = Interface_GetCurrentRenderedMenu()->SkyObject_GetNiNode()->FUN_00a59d30(MagicSystem_CheckEffectFlares());
            if (property)
                property->NiAlphaProperty_SetAlphaBlending(0);
            Interface_GetCurrentRenderedMenu()->SetScreenTexture(0);
            contextSlot26->BSCullingProcess_SetAccumulator(tempTextureSlot13.Modelloader_GetReferencedThis());
            if (Interface_IsInPipboyMenu() && DAT_011dea3c->IsRefractive())
            {
                BSShaderUtil_AccumulateScene(camera.Modelloader_GetReferencedThis(), Interface_GetPipboy()->FOPipboyManager_GetPipboyLightGlow(0), contextSlot26);
                BSShaderUtil_AccumulateScene(camera.Modelloader_GetReferencedThis(), Interface_GetPipboy()->FOPipboyManager_GetPipboyLightGlow(1), contextSlot26);
                BSShaderUtil_AccumulateScene(camera.Modelloader_GetReferencedThis(), Interface_GetPipboy()->FOPipboyManager_GetPipboyLightGlow(2), contextSlot26);
            }
            BSShaderUtil_AccumulateScene(camera.Modelloader_GetReferencedThis(), Interface_GetCurrentRenderedMenu()->SkyObject_GetNiNode(), contextSlot26);
            FUN_00b6c0d0(camera.Modelloader_GetReferencedThis(), tempTextureSlot13.Modelloader_GetReferencedThis(), 0);
            contextSlot26->BSCullingProcess_SetAccumulator(0);
            tempTextureSlot13.FUN_0066b0d0(0);
            contextSlot26->BSCullingProcess_PopCullMode();
            if (Interface_IsInPipboyMenu() && DAT_011dea3c->IsRefractive())
                Interface_GetCurrentRenderedMenu()->SkyObject_GetNiNode()->FUN_00450f90(0);
        }
    }
    if (Interface_GetCurrentRenderedMenu() && Interface_GetCurrentRenderedMenu() != Interface_GetPipboy())
    {
    }
    else if (!Interface_IsInPipboyMenu() || !DAT_011dea3c->IsRefractive())
    {
        FUN_00b98380(15, 1);
        FUN_004ea970()->MTRenderingSystem_WaitOnThreadStage(1, 22);
        FUN_00b6c0d0(camera.Modelloader_GetReferencedThis(), surface.Modelloader_GetReferencedThis(), 0);
        BSRenderState_RestoreColorWriteEnable(1);
        List* list = DAT_011e0e80.GetTranslate_0043c490();
        if (list && !list->BSSimpleList_NiRefObjectPtr_IsEmpty())
        {
            NiPoint3 offset(0, 0, 0);
            if (DAT_011dea3c->PlayerCharacter_GetWeaponSightingNode() && !DAT_011dea3c->Actor_IsReloading() && !DAT_011f2250.VATS_IsInVats())
                offset = DAT_011dea3c->PlayerCharacter_GetWeaponSightingNode()->NiAVObject_GetWorldTranslate()->SubtractIntoVector(*DAT_011e07d0->NiAVObject_GetWorldTranslate());
            Scene* render2Slot14 = Main_GetWorldSceneGraph();
            Scene* view2Slot10 = render2Slot14->FUN_006629f0();
            Context* context2Slot0 = render2Slot14->FUN_008d80e0();
            Pointer texture2Slot11(texture);
            NiPoint3 savedPosSlot10 = *view2Slot10->NiAVObject_GetWorldTranslate();
            view2Slot10->NiAVObject_SetWorldTranslate(savedPosSlot10.FUN_00439e90(offset));
            context2Slot0->BSCullingProcess_SetAccumulator(texture2Slot11.Modelloader_GetReferencedThis());
            texture2Slot11.Modelloader_GetReferencedThis()->MobileObject_SetSoundCallBackSuccess(1);
            bool renderedSlot0 = false;
            while (list)
            {
                Scene* object = list->FUN_006815c0()->Modelloader_GetReferencedThis();
                list = list->FUN_00726070();
                if (object && object->Active())
                {
                    renderedSlot0 = true;
                    object->Node()->FUN_00450f90(0);
                    BSShaderUtil_AccumulateScene(view2Slot10, object->Node(), context2Slot0);
                    object->Node()->FUN_00450f90(1);
                }
            }
            if (renderedSlot0)
                FUN_00b6c0d0(view2Slot10, texture2Slot11.Modelloader_GetReferencedThis(), 0);
            context2Slot0->BSCullingProcess_SetAccumulator(0);
            texture2Slot11.Modelloader_GetReferencedThis()->MobileObject_SetSoundCallBackSuccess(0);
            texture2Slot11.FUN_0066b0d0(0);
            view2Slot10->NiAVObject_SetWorldTranslate(savedPosSlot10);
        }
    }
    if (BSShaderManager_IsRefractionEnabled())
    {
        Guard guard2Slot0(0x27, 1, DAT_010829c4, 0x22b5);
        if (Interface_IsInPipboyMenu() && BSShaderManager_IsRefractionEnabled() && DAT_011dea3c->IsRefractive())
        {
            FUN_00b6b790();
            DAT_011f9438->Object_DoNothing();
            BSRenderedTexture_StartOffscreen(6, pass->FUN_00b6b260());
            if (DAT_011f9426)
                Main_WorldRootCamera()->FUN_00712e60(DAT_011ad840);
        }
        Scene* render3Slot0 = Main_GetWorldSceneGraph();
        surface.Modelloader_GetReferencedThis()->BSShaderAccumulator_RenderNormals(camera.Modelloader_GetReferencedThis(), pass);
        TESMain_DrawWorld_RestartRenderTexture(pass, 0, 0);
    }
    if (DAT_011de9d1)
    {
        Update update(0.0f, 0, 0);
        aliasSlot0->NiAVObject_Update(update);
        aliasSlot0->NiAVObject_SetAlwaysDraw(0);
        FUN_00450b80(0)->ShadowSceneNode_SetEyePosition(*viewSlot23->NiAVObject_GetParent()->GetTranslate_0043c490());
        FUN_00450b80(0)->ShadowSceneNode_SetLightingOffset(DAT_011f426c);
    }
    if (DAT_011f2250.FUN_0044ddc0() != 4)
        Main_GetWorldSceneGraph()->SceneGraph_SetCameraFOV(DAT_011dea3c->PlayerCharacter_GetWorldFOV(), 0, 0, 0);
    FUN_00b54000(DAT_011dea3c->PlayerCharacter_GetWorldFOV());
    if (extra && !extra->NiObjectNET_GetControllers()->GetAppCulled_00456610())
    {
        bool previousSlot0 = extra->NiObjectNET_GetControllers()->GetAppCulled_00456610();
        extra->NiObjectNET_GetControllers()->FUN_00450f90(0);
        Scene* render4Slot20 = Main_GetWorldSceneGraph();
        Scene* view4Slot48 = render4Slot20->FUN_006629f0();
        Context* context4 = render4Slot20->FUN_008d80e0();
        Pointer texture4(texture);
        context4->BSCullingProcess_SetAccumulator(texture4.Modelloader_GetReferencedThis());
        texture4.Modelloader_GetReferencedThis()->MobileObject_SetSoundCallBackSuccess(1);
        BSShaderUtil_AccumulateScene(view4Slot48, extra->NiObjectNET_GetControllers(), context4);
        FUN_00b6c0d0(view4Slot48, texture4.Modelloader_GetReferencedThis(), 0);
        context4->BSCullingProcess_SetAccumulator(0);
        texture4.Modelloader_GetReferencedThis()->MobileObject_SetSoundCallBackSuccess(0);
        texture4.FUN_0066b0d0(0);
        extra->NiObjectNET_GetControllers()->FUN_00450f90(previousSlot0);
    }
    if (extra)
        extra->FUN_006426a0(2, texture.Modelloader_GetReferencedThis(), DAT_011deb7c.Modelloader_GetReferencedThis()->FUN_006629f0());
    renderSlot52->SceneGraph_SetCameraFOV(DAT_011dea3c->PlayerCharacter_Get1stPersonFOV(), 0, 0, 0);
    FUN_00b54000(DAT_011dea3c->PlayerCharacter_Get1stPersonFOV());
}
}

namespace fnv_00875fd0 {
struct SaveGameRenderState
{
    bool BGSSaveLoadGame_GetSaveGameLoading();
    bool FUN_005621d0();
};
extern SaveGameRenderState* g_BGSSaveLoadGame;
bool __cdecl Interface_IsInPipboyMenu();
bool __cdecl Interface_IsInMenuMode();
bool __cdecl FUN_00705e80();
void __cdecl Interface_Accumulate();
void __cdecl FUN_00b6b790();
bool __cdecl Interface_IsInRenderedMenu();
struct RenderEffectManager
{
    void PrepareEffect(void*, BSShaderAccumulator*, int, unsigned char);
    void VATSEffect_ShutdownEffect();
};
RenderEffectManager* __cdecl Interface_GetVATSEffect();
struct AccumulatorPointer
{
    BSShaderAccumulator* Modelloader_GetReferencedThis() const;
    void FUN_0066b0d0(BSShaderAccumulator*);
};
extern AccumulatorPointer DAT_011deb38;
extern bool DAT_011dea29;
extern bool DAT_012005a2;
extern float DAT_011add08;
extern void* DAT_011f917c;
struct RenderedMenu
{
    virtual void UnkVirtual0();
    virtual void UnkVirtual1();
    virtual void UnkVirtual2();
    virtual void UnkVirtual3();
    virtual void UnkVirtual4();
    virtual void UnkVirtual5();
    virtual void UnkVirtual6();
    virtual void UnkVirtual7();
    virtual void UnkVirtual8();
    virtual void UnkVirtual9();
    virtual void UnkVirtual10();
    virtual float GetRenderScale();
};
RenderedMenu* __cdecl Interface_GetCurrentRenderedMenu();
void __cdecl BSShaderManager_RenderImageSpaceEffects(void*, void*, void*);
struct TextureReturnManager
{
    void BSTextureManager_ReturnRenderedTexture(BSShaderAccumulator*);
};
TextureReturnManager* __stdcall BSShaderManager_GetTextureManager();
struct ViewportCamera
{
    void FUN_00712e60(const NiColorA&);
};
ViewportCamera* __cdecl Main_WorldRootCamera();
struct FrameRenderer
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    bool bSkipScene;
    void TESMain_DrawWorld_ImageSpace(void*, void*, void*, void*);
};

// @fnv 0x00875fd0
// src: COMMUNITY 0x00875fd0
void FrameRenderer::TESMain_DrawWorld_ImageSpace(void* unused, void* renderer, void* scene, void* target)
{
    AutoMemHelper m_uiMemoryContext(39, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 9058);
    if (!BSRenderedTexture_IsOutsideFrame())
        FUN_00b6b790();
    if (!Interface_IsInPipboyMenu() && !Interface_IsInMenuMode() && !FUN_00705e80() && !g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading() &&
        !g_BGSSaveLoadGame->FUN_005621d0() && !bSkipScene)
        Interface_Accumulate();
    if (DAT_011deb38.Modelloader_GetReferencedThis())
        Interface_GetVATSEffect()->PrepareEffect(renderer, DAT_011deb38.Modelloader_GetReferencedThis(), 0, 0);
    bool menuActive = Interface_IsInRenderedMenu() && !bSkipScene && DAT_011dea29;
    if (menuActive)
    {
        DAT_012005a2 = true;
        float renderScale = Interface_GetCurrentRenderedMenu()->GetRenderScale();
        DAT_011add08 = renderScale;
    }
    DAT_011f917c = Main_GetWorldSceneGraph()->::BSFaceGenNiNode::GetAnimationData();
    BSShaderManager_RenderImageSpaceEffects(scene, renderer, target);
    if (DAT_011deb38.Modelloader_GetReferencedThis())
    {
        Interface_GetVATSEffect()->VATSEffect_ShutdownEffect();
        BSShaderManager_GetTextureManager()->BSTextureManager_ReturnRenderedTexture(DAT_011deb38.Modelloader_GetReferencedThis());
        DAT_011deb38.FUN_0066b0d0(0);
    }
    if (menuActive)
    {
        DAT_012005a2 = false;
        DAT_011add08 = 1.0f;
    }
    Main_WorldRootCamera()->FUN_00712e60(NiColorA(0.0f, 1.0f, 1.0f, 0.0f));
}
}  // namespace fnv_00875fd0

namespace fnv_008761e0 {
struct V876
{
    float x, y, z;
    void FUN_0043d410(float, int, int);
};
struct T876
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    V876 pos;
    float scale;
    void NiTransform_NiTransform();
    void FUN_00a86bf0();
};
struct R876
{
    float l, r, t, b;
};
struct Camera876
{
    bool NiAVObject_GetAlwaysDraw();
    T876* NiAVObject_GetRotate_006a9540();
    void NiAVObject_SetTranslate(V876*);
    void NiAVObject_Update(V876*);
    void NiAVObject_SetAlwaysDraw(bool);
    Camera876* NiAVObject_GetParent();
    Camera876* FUN_006629f0();
    Camera876* FUN_008b6200();
    Camera876* FUN_005585e0();
    R876* TESDataHandler_GetImpactDataSetList();
    void FUN_00712e60(R876*);
    Camera876* NiAVObject_GetWorldTranslate();
    V876* GetNegatedVector(V876*);
    void SetImpactDataSet_004fb0b0(bool);
    void FUN_0041fd00(Camera876*);
    void BSCullingProcess_SetAccumulator(void*);
    void BSShaderAccumulator_SetShadowSceneNode(void*);
    void BSShaderAccumulator_ClearGroupPasses(int);
    void NiAlphaProperty_SetAlphaBlending(bool);
    void NiAlphaProperty_SetSrcBlendMode(int);
    void NiAlphaProperty_SetDestBlendMode(int);
    Camera876* FUN_00a59d30(void*);
    void UpdateProperties();
    Camera876* SkyObject_GetNiNode();
    void SetScreenTexture(void*);
    Camera876* Modelloader_GetReferencedThis();
    void* BSRenderedTexture_GetTexture(int);
};
struct Player876
{
    Camera876* FUN_008d80e0();
    Camera876* FUN_006629f0();
};
struct Global876
{
    bool PlayerCharacter_IsPipboyActive();
    bool IsRefractive();
};
struct Input876
{
    int Controls_GetMouseButton(int, int);
    void RendererClearBufferHook(int, int);
};
struct Mode876
{
    bool CheckOrangeButtonsClicked(bool, bool, float*, float*, int*);
    Camera876* FOPipboyManager_GetPipboyLightGlow(int);
};
extern Global876* DAT_011dea3c;
extern Camera876* DAT_011e07d0;
extern Camera876 g_011dec64;
extern V876 DAT_011f426c;
extern bool DAT_011f9426;
extern R876 DAT_011ad840;
Camera876* Interface_GetCurrentRenderedMenu();
Mode876* Interface_GetPipboy();
bool Interface_IsInPipboyMenu();
void Interface_SetQueuedPipboyTab(bool, float, float, int);
void FUN_00b98380(int, int);
void BSRenderState_SetZWriteEnable(int, int);
void BSRenderState_SetZEnable(int, int);
void BSShaderUtil_AccumulateScene(Camera876*, Camera876*, Camera876*);
void FUN_00b6c0d0(Camera876*, Camera876*, int);
void BSRenderState_RestoreColorWriteEnable(int);
void* MagicSystem_CheckEffectFlares();
void BSRenderState_RestoreZWriteEnable(int);
void BSRenderState_RestoreZEnable(int);
::ShadowSceneNode* FUN_00450b80(int);
::NiRenderer* NiXenonRenderer_GetRenderer();
struct Shell876
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    Camera876 a8c;
    int unk90;
    int unk94;
    Camera876 a98;
    int unk9c;
    Camera876 aa0;
    Input876* Main_GetControls();
    void Main_DrawWorld_RenderedMenu(int, Input876*);
};
// Sets up the player camera and scene nodes, applies camera transforms and render passes, then restores the previous camera state.
// @fnv 0x008761e0
// src: XBOX_PDB 0x008761e0
void Shell876::Main_DrawWorld_RenderedMenu(int unused, Input876* input)
{
    Player876* p;
    R876 h;
    Camera876* a;
    Camera876* i;
    Camera876* s;
    Camera876* f;
    bool eb;
    V876 cf;
    Camera876* q;
    T876 b;
    T876 ba;
    bool k;
    int l;
    float c;
    float e;
    V876 j;
    p = (Player876*)Main_GetWorldSceneGraph();
    s = p->FUN_008d80e0();
    i = Interface_GetCurrentRenderedMenu()->FUN_008b6200();
    input->RendererClearBufferHook(0, 4);
    f = Interface_GetCurrentRenderedMenu()->FUN_005585e0();
    s->SetImpactDataSet_004fb0b0(true);
    cf.FUN_0043d410(0.0f, 0, 0);
    b.NiTransform_NiTransform();
    eb = f->NiAVObject_GetAlwaysDraw();
    a = i ? i : p->FUN_006629f0();

    if (DAT_011dea3c->PlayerCharacter_IsPipboyActive())
    {
        ba = *f->NiAVObject_GetRotate_006a9540();
        f->NiAVObject_SetTranslate(&DAT_011f426c);
        f->NiAVObject_Update(&cf);
        f->NiAVObject_SetTranslate(&ba.pos);
        b.FUN_00a86bf0();
        if (a && a->NiAVObject_GetParent())
        {
            b = *a->NiAVObject_GetParent()->NiAVObject_GetRotate_006a9540();
            a->NiAVObject_GetParent()->NiAVObject_SetTranslate((V876*)DAT_011e07d0->NiAVObject_GetWorldTranslate());
            a->NiAVObject_GetParent()->NiAVObject_Update(&cf);
        }

        ::ShadowSceneNode_SetLightingOffset(FUN_00450b80(0), *(NiPoint3*)f->NiAVObject_GetWorldTranslate()->GetNegatedVector(&j));
    }
    if (Interface_IsInPipboyMenu())
    {
        l = 0;
        k = Interface_GetPipboy()->CheckOrangeButtonsClicked(Main_GetControls()->Controls_GetMouseButton(0, 1) > 0, Main_GetControls()->Controls_GetMouseButton(0, 2) > 0,
                                         &e, &c, &l);
        Interface_SetQueuedPipboyTab(k, e, c, l);
    }
    i = i ? i : p->FUN_006629f0();
    if (!i)
        i = aa0.Modelloader_GetReferencedThis();
    h = *i->TESDataHandler_GetImpactDataSetList();
    if (DAT_011f9426 && static_cast< ::NiDX9Renderer*>(NiXenonRenderer_GetRenderer())->GetCurrentRT() == static_cast< ::NiDX9Renderer*>(NiXenonRenderer_GetRenderer())->GetDefaultRT())
        i->FUN_00712e60(&DAT_011ad840);
    FUN_00b98380(0, 1);
    s->FUN_0041fd00(i);
    s->BSCullingProcess_SetAccumulator(a8c.Modelloader_GetReferencedThis());
    a8c.Modelloader_GetReferencedThis()->BSShaderAccumulator_SetShadowSceneNode(FUN_00450b80(0));
    BSShaderUtil_AccumulateScene(i, f, s);
    FUN_00b6c0d0(i, a8c.Modelloader_GetReferencedThis(), 0);
    a8c.Modelloader_GetReferencedThis()->BSShaderAccumulator_ClearGroupPasses(6);
    s->BSCullingProcess_SetAccumulator(0);
    BSRenderState_RestoreColorWriteEnable(1);
    q = Interface_GetCurrentRenderedMenu()->SkyObject_GetNiNode()->FUN_00a59d30(MagicSystem_CheckEffectFlares());
    if (q)
    {
        q->NiAlphaProperty_SetAlphaBlending(true);
        q->NiAlphaProperty_SetSrcBlendMode(6);
        q->NiAlphaProperty_SetDestBlendMode(0);
        Interface_GetCurrentRenderedMenu()->SkyObject_GetNiNode()->UpdateProperties();
    }
    Interface_GetCurrentRenderedMenu()->SetScreenTexture(g_011dec64.Modelloader_GetReferencedThis()->BSRenderedTexture_GetTexture(0));
    s->FUN_0041fd00(i);
    s->BSCullingProcess_SetAccumulator(a98.Modelloader_GetReferencedThis());
    BSRenderState_SetZWriteEnable(0, 1);
    if (DAT_011dea3c->IsRefractive() && Interface_IsInPipboyMenu())
    {
        BSShaderUtil_AccumulateScene(i, Interface_GetPipboy()->FOPipboyManager_GetPipboyLightGlow(0), s);
        BSShaderUtil_AccumulateScene(i, Interface_GetPipboy()->FOPipboyManager_GetPipboyLightGlow(1), s);
        BSShaderUtil_AccumulateScene(i, Interface_GetPipboy()->FOPipboyManager_GetPipboyLightGlow(2), s);
        BSRenderState_SetZEnable(0, 1);
    }
    BSShaderUtil_AccumulateScene(i, Interface_GetCurrentRenderedMenu()->SkyObject_GetNiNode(), s);
    FUN_00b6c0d0(i, a98.Modelloader_GetReferencedThis(), 0);
    BSRenderState_RestoreZWriteEnable(1);
    if (DAT_011dea3c->IsRefractive() && Interface_IsInPipboyMenu())
        BSRenderState_RestoreZEnable(1);
    s->BSCullingProcess_SetAccumulator(0);
    Interface_GetCurrentRenderedMenu()->SetScreenTexture(0);
    if (q)
        q->NiAlphaProperty_SetAlphaBlending(false);
    i->FUN_00712e60(&h);
    if (DAT_011dea3c->PlayerCharacter_IsPipboyActive())
    {
        f->NiAVObject_Update(&cf);
        f->NiAVObject_SetAlwaysDraw(eb);
        if (a && a->NiAVObject_GetParent())
        {
            a->NiAVObject_GetParent()->NiAVObject_SetTranslate(&b.pos);
            a->NiAVObject_GetParent()->NiAVObject_Update(&cf);
        }
        ::ShadowSceneNode_SetLightingOffset(FUN_00450b80(0), *(NiPoint3*)&DAT_011f426c);
    }
    s->SetImpactDataSet_004fb0b0(false);
}
}  // namespace fnv_008761e0

struct SLPoint3
{
    float x;
    float y;
    float z;
};

struct SLWorldSpace;

struct SLCell
{
    bool IsInterior();
    SLWorldSpace* GetParentWorldSpace();
    int GetPosX();
    int GetPosY();
};

struct SLWorldSpace
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual const char* GetEditorID();

    SLCell* GetCellAtCoords(int aiX, int aiY);
};

struct SLWorldSpaceList
{
    SLWorldSpace* pItem;
    SLWorldSpaceList* pNext;

    bool IsEmpty();
    SLWorldSpace** GetItem();
    SLWorldSpaceList* GetNext();
};

struct SLDataHandler
{
    SLWorldSpaceList* GetWorldSpaces();
    SLCell* GetCellByName(const char* apName);
    SLWorldSpace* GetWorldSpaceForCell(const char* apName, int* apX, int* apY);
    SLCell* GetContainingCell(int aiX, int aiY, SLWorldSpace* apWorld, bool abCreate);
    void FUN_004650a0(int aiValue);
};

struct SLSky
{
    void AttachAllLand3D();
};

struct SLTES
{
    void AssignWorldSpace(SLWorldSpace* apWorld);
    void SetPosition(SLPoint3* apPos);
    void SetInteriorCell(SLCell* apCell, SLPoint3* apPos);
    void LoadArea(SLPoint3* apPos, bool abFlag);
    SLSky* GetSky();
};

struct SLSetting
{
    const char* GetString();
};

unsigned int __cdecl BSStringLength(const char* apString);
const char* __cdecl PrepareScriptMessage(const char* apString, bool abFlag);
void __cdecl FNV_Warning(const char* apFormat, ...);
long __cdecl SLStrToLong(const char* apString);
int __cdecl SLStrICmp(const char* apString1, const char* apString2);

extern SLDataHandler* g_pSLDataHandler;
extern SLTES* g_pSLTES;
extern SLSetting g_kStartingCell;
extern SLSetting g_kStartingCellX;
extern SLSetting g_kStartingCellY;
extern SLSetting g_kStartingWorld;
extern double g_dCellHalfSize;

// Resolves the starting cell from a name or the starting-cell INI settings, positions the player there, and warns if the cell cannot be found.
// @fnv 0x00876dd0
// src: XBOX_PDB 0x00876dd0
void __cdecl Main_InitStartCell(const char* apCellName, SLPoint3* apPos)
{
    SLCell* pCell4 = 0;
    bool bWarn = true;
    bool bLoad7 = true;

    if ((apCellName && BSStringLength(apCellName)) || strlen(g_kStartingCell.GetString()))
    {
        if (apCellName && BSStringLength(apCellName))
            pCell4 = g_pSLDataHandler->GetCellByName(apCellName);
        else
            pCell4 = g_pSLDataHandler->GetCellByName(PrepareScriptMessage(g_kStartingCell.GetString(), false));
        if (!pCell4)
        {
            int iX = 0;
            int iY4 = 0;
            SLWorldSpace* pWorld8 = g_pSLDataHandler->GetWorldSpaceForCell(
                PrepareScriptMessage(g_kStartingCell.GetString(), false), &iX, &iY4);
            if (pWorld8)
            {
                g_pSLTES->AssignWorldSpace(pWorld8);
                apPos->x = (iX << 12) + g_dCellHalfSize;
                apPos->y = (iY4 << 12) + g_dCellHalfSize;
                apPos->z = 0.0f;
                g_pSLTES->SetPosition(apPos);
                pCell4 = g_pSLDataHandler->GetContainingCell(iX, iY4, pWorld8, false);
                bLoad7 = false;
            }
        }
    }
    else if (strlen(g_kStartingCellX.GetString()) && strlen(g_kStartingCellY.GetString()))
    {
        int m_iGridPositionX = SLStrToLong(PrepareScriptMessage(g_kStartingCellX.GetString(), false));
        int iCellY8 = SLStrToLong(PrepareScriptMessage(g_kStartingCellY.GetString(), false));
        SLWorldSpace* pWorldA = *g_pSLDataHandler->GetWorldSpaces()->GetItem();
        SLWorldSpaceList* pIter_ = g_pSLDataHandler->GetWorldSpaces();
        while (pIter_ && !pIter_->IsEmpty())
        {
            SLWorldSpace* m_pContainingWorldspace = *pIter_->GetItem();
            if (!SLStrICmp(m_pContainingWorldspace->GetEditorID(), g_kStartingWorld.GetString()))
            {
                pWorldA = m_pContainingWorldspace;
                break;
            }
            pIter_ = pIter_->GetNext();
        }
        if (pWorldA)
        {
            pCell4 = pWorldA->GetCellAtCoords(m_iGridPositionX, iCellY8);
            if (!pCell4)
                pCell4 = g_pSLDataHandler->GetContainingCell(m_iGridPositionX, iCellY8, pWorldA, true);
        }
    }
    else
    {
        bWarn = false;
        bLoad7 = false;
    }

    if (bLoad7)
    {
        if (pCell4)
        {
            if (pCell4->IsInterior())
            {
                g_pSLTES->SetInteriorCell(pCell4, apPos);
            }
            else
            {
                g_pSLTES->AssignWorldSpace(pCell4->GetParentWorldSpace());
                apPos->x = (pCell4->GetPosX() << 12) + g_dCellHalfSize;
                apPos->y = (pCell4->GetPosY() << 12) + g_dCellHalfSize;
                apPos->z = 0.0f;
                g_pSLTES->SetPosition(apPos);
            }
            bLoad7 = false;
        }
        else if (bWarn)
        {
            if (g_kStartingCell.GetString() && *g_kStartingCell.GetString())
            {
                FNV_Warning("CELLS: Could not find starting cell '%s'.", g_kStartingCell.GetString());
            }
            else if (g_kStartingCellX.GetString() && g_kStartingCellY.GetString() && *g_kStartingCellX.GetString() &&
                     *g_kStartingCellY.GetString())
            {
                if (g_kStartingWorld.GetString() && *g_kStartingWorld.GetString())
                    FNV_Warning("CELLS: Could not find starting cell (%s, %s) in worldspace '%s'.",
                                g_kStartingCellX.GetString(), g_kStartingCellY.GetString(),
                                g_kStartingWorld.GetString());
                else
                    FNV_Warning("CELLS: Could not find starting cell (%s, %s) in default Tamriel worldspace",
                                g_kStartingCellX.GetString(), g_kStartingCellY.GetString());
            }
            else
            {
                FNV_Warning("CELLS: Could not find starting cell for INI data.");
            }
        }
        g_pSLDataHandler->FUN_004650a0(-1);
        if (bLoad7)
        {
            g_pSLTES->LoadArea(apPos, true);
            g_pSLTES->GetSky()->AttachAllLand3D();
        }
    }
}

namespace fnv_008774a0 {
struct FUN_009611e0_ctrl
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058(void* apNode);
};

struct FUN_008774a0_node
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual FUN_008774a0_node* v003();
    FUN_009611e0_ctrl* NiAVObject_GetParent();
};

struct FUN_0054ca90_cell
{
    void TESObjectCELL_RemoveReference(void* apRef);
};

struct FUN_008774a0_player
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115(int a1, int a2);
    void PlayerCharacter_StopHeartbeatSound();
    FUN_0054ca90_cell* FUN_008d6f30();
    FUN_008774a0_node* PlayerCharacter_Get3D_00950bb0(bool abFirstPerson);
};

struct FUN_007d6bd0_save
{
    bool BGSSaveLoadGame_SetGlobalAllowChanges(bool abFlag);
    void FUN_0084a840();
};

struct FUN_004539a0_tes
{
    void TES_ClearAllCells(int a1, int a2);
    void FUN_007037c0(int aiValue);
    void FUN_0061cc40(int aiValue);
    void TES_CleanupTemporaryParticleCache();
};

struct FUN_00ad8780_audio
{
    void FUN_00ad8780(int aiValue);
};
struct FUN_006c09f0_mgr
{
    void NavMeshObstacleManager_ClearAllObstacles();
};
struct FUN_00970d50_lists
{
    void ProcessLists_InitPackageLocations();
};
struct FUN_004614e0_dh
{
    void FUN_004614e0();
};
struct FUN_00b631d0_obj
{
    void BSShaderAccumulator_ClearAllQueries();
};

FUN_00ad8780_audio* BSAudio_QInstance();
void __cdecl FUN_008324e0(int aiValue);
FUN_006c09f0_mgr* GetNavMeshObstacleManager();
void GarbageCollector_ClearAll(int aiValue);
void NiObjectGarbage_ClearAll(int aiValue);
FUN_00b631d0_obj* BSShaderManager_GetAccumulator();
void __cdecl ProgramFlow();
void Interface_CloseAllSupportMenus(int aiValue);
void __cdecl Interface_CreateMainMenu();

extern FUN_008774a0_player* DAT_011dea3c;
extern FUN_007d6bd0_save* DAT_011ddf38;
extern FUN_004539a0_tes* DAT_011dea10;
extern FUN_004614e0_dh* DAT_011c3f2c;

struct FUN_008774a0_shell
{
    bool TESRegionData_GetOverride();
    void FUN_004f15a0(int aiValue);
    void FUN_008776e0();
    void Main_PerformGameReset(bool abFlag);
};

extern FUN_008774a0_shell* DAT_011dea0c;

// @fnv 0x008774a0
// src: XBOX_PDB 0x008774a0
void FUN_008774a0_shell::Main_PerformGameReset(bool abFlag)
{
    bool bState = TESRegionData_GetOverride();
    FUN_004f15a0(0);
    DAT_011dea3c->PlayerCharacter_StopHeartbeatSound();
    bool bSaveFlag = DAT_011ddf38->BGSSaveLoadGame_SetGlobalAllowChanges(false);
    BSAudio_QInstance()->FUN_00ad8780(-1);
    FUN_008324e0(0);
    if (DAT_011dea3c->FUN_008d6f30())
        DAT_011dea3c->FUN_008d6f30()->TESObjectCELL_RemoveReference(DAT_011dea3c);

    FUN_008774a0_node* pNode = DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(true);
    FUN_008774a0_node* pRoot = pNode ? pNode->v003() : 0;
    if (pRoot && pRoot->NiAVObject_GetParent())
        pRoot->NiAVObject_GetParent()->v058(pNode);
    pNode = DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(false);
    pRoot = pNode ? pNode->v003() : 0;
    if (pRoot && pRoot->NiAVObject_GetParent())
        pRoot->NiAVObject_GetParent()->v058(pNode);

    DAT_011dea10->TES_ClearAllCells(0, 0);
    DAT_011dea10->FUN_007037c0(0x7fffffff);
    DAT_011dea10->FUN_0061cc40(0x7fffffff);
    GetNavMeshObstacleManager()->NavMeshObstacleManager_ClearAllObstacles();
    GarbageCollector_ClearAll(0);
    NiObjectGarbage_ClearAll(0);
    DAT_011dea3c->v115(0, 0);
    DAT_011ddf38->FUN_0084a840();
    ((FUN_00970d50_lists*)&DAT_011e0e80)->ProcessLists_InitPackageLocations();
    DAT_011c3f2c->FUN_004614e0();
    BSShaderManager_GetAccumulator()->BSShaderAccumulator_ClearAllQueries();
    ProgramFlow();
    Interface_CloseAllSupportMenus(0);
    DAT_011dea10->TES_CleanupTemporaryParticleCache();
    if (abFlag)
        Interface_CreateMainMenu();
    DAT_011ddf38->BGSSaveLoadGame_SetGlobalAllowChanges(bSaveFlag);
    DAT_011dea0c->FUN_008776e0();
    DAT_011dea0c->FUN_004f15a0(bState);
}
}  // namespace fnv_008774a0

namespace fnv_00873200 {
// Scene traversal, visibility batching, and the main and auxiliary render passes.
// Local-name suffixes preserve the VC++ 2008 stack-slot allocation.

struct ViewNode;
struct ViewGeometry;
struct ViewList;
struct ViewHandle
{
    ViewNode* value;
    ViewNode* Modelloader_GetReferencedThis();
};
struct ViewList
{
    void* Modelloader_GetReferencedThis();
    ViewHandle* NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(void** position);
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
};
struct ViewNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual ViewNode* AsNode();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void SetCamera(ViewNode* camera);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    bool m_38;
    unsigned char unk39;
    bool m_3a;
    ViewNode* FUN_008d80e0();
    ViewNode* FUN_006629f0();
    ViewNode* PlayerCharacter_Get3D_00950bb0(bool);
    bool GetAppCulled_00456610();
    void FUN_00450f90(bool);
    ViewNode* GetEffect_004ebbc0(int);
    bool ImageSpaceEffectDepthOfField_DoDepth();
    void FUN_0041fd00(ViewNode*);
    void* FUN_0045bbe0();
    void NiCullingProcess_SetFrustum(void*);
    void BSCullingProcess_SetAccumulator(ViewNode*);
    ViewNode* NiNode_GetAtChecked(unsigned int);
    unsigned int FUN_0043b480();
    ViewNode* FUN_0043b4a0(unsigned int);
    ViewNode* FUN_005f36f0();
    bool ShadowSceneNode_HasVisibleUnboundSpace();
    ViewNode* ShadowSceneNode_QPortalGraph();
    ViewList* FUN_00436aa0();
    ViewList* TESCombatStyle_GetAdvancedData();
    ViewGeometry* BSPortal_GetSharedGeometry();
    bool BSCullingProcess_AddShared(ViewGeometry*);
    int Projectile_GetShooter();
    int Projectile_GetDesiredTarget();
    ViewNode* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    void FUN_00b5ba80(ViewNode*, ViewNode*);
    ViewList* FUN_007d6bb0();
    ViewNode* FUN_00457070();
    ViewNode* GetPortalGraph_009d9f20();
    unsigned int BSPortalGraph_GetAlwaysRenderArrayCount();
    ViewNode* BSPortalGraph_GetAlwaysRenderAt(int);
    void ShadowSceneNode_PreOnVisible(ViewNode*);
    ViewNode* TESDataHandler_GetEffectShaders();
    void BSCompoundFrustum_PrethreadOpList();
    void NiTexturingProperty_Map_SetTexture(ViewNode*);
    void nullsub_3(ViewNode*);
    void SetImpactDataSet_004fb0b0(bool);
    void Sun_StartSunOcclusion();
    void FUN_006426a0(bool, ViewNode*, ViewNode*);
    int* Setting_Int();
};
struct ViewGeometry : ViewNode
{
};
struct VisibleList
{
    int unk00;
    int unk04;
    int unk08;
    VisibleList();
    ~VisibleList();
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(ViewNode* const&);
    void FUN_004ed900();
};
struct MemoryContext
{
    int unk00;
    MemoryContext(int, bool, const char*, int);
    ~MemoryContext();
    void FUN_00404f70();
};
struct RenderSystem
{
    void MTRenderingSystem_AddAccumTask(ViewNode*, ViewNode*, int, VisibleList*, int, ViewNode*, int, int, bool);
    void MTRenderingSystem_SetThreadStage(int, int);
    void MTRenderingSystem_WaitOnThreadStage(int, int);
};
struct InterfaceSystem
{
    void FOVATSEffectManager_DrawTargetToTexture(int, int, int, int, int, int);
};
ViewNode* Main_GetWorldSceneGraph();
ViewNode* BSShaderManager_GetImageSpaceManager();
ViewNode* FUN_00450b80(int);
ViewNode* NiXenonRenderer_GetRenderer();
RenderSystem* FUN_004ea970();
InterfaceSystem* Interface_GetVATSEffect();
ViewNode* ScreenSplatter_GetCamera();
ViewNode* ScreenCustomSplatter_GetCamera();
ViewNode* ScreenCustomSplatter_GetCurrentRoot();
ViewNode* ScreenSplatter_GetRoot();
void* BSShaderManager_GetRenderer();
void BSShaderBloodSplatterProperty_ResetShapeCount();
void BSShaderManager_SetAccumulator(ViewNode*);
void BSShaderUtil_AccumulateSceneList(ViewNode*, VisibleList*, ::BSCullingProcess*);
void BSShaderUtil_AccumulateScene(ViewNode*, ViewNode*, ViewNode*);
void BSShaderUtil_RenderScenePreResolveDepth(ViewNode*, ViewNode*, bool);
void BSShaderUtil_RenderScenePostResolveDepth(ViewNode*, ViewNode*, bool);
void FUN_00b6c0d0(ViewNode*, ViewNode*, bool);
void FUN_00b98380(int, int);
void BSRenderState_RestoreColorWriteEnable(int);
void BSShaderBloodSplatter_ComputeScreenSpaceLightLoc(ViewNode*);
void FUN_008c80e0(int);
void ImageSpaceEffectFullScreenBlur_CheckCamera(ViewNode*);
void BSShaderAccumulator_SetRunBoundingSphereTests(bool, bool);
extern ViewNode* DAT_011dea3c;
extern ViewNode* DAT_011dea10;
extern ViewHandle DAT_011deb7c;
extern ViewNode DAT_011c3ea4;
extern ViewNode* DAT_011f9684;
extern bool DAT_011f94b4;
extern bool DAT_011f94a9;
extern const char DAT_010829c4[];
extern __declspec(thread) int DAT_012722bc;
// Main render pass at 0x00873200 uses accumulators at +0x88/+0x8c/+0x94; include/Main.h is not available yet.
struct MainView
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    ViewHandle m_88;
    ViewHandle m_8c;
    int unk90;
    ViewHandle m_94;
    void TESMain_DrawWorld_DrawScene(ViewNode* listener, int unused, bool hide, bool drawInterface);
};
// Builds visible lists from the scene graph, renders the main view and secondary passes, and restores the saved visibility state.
// @fnv 0x00873200
// src: COMMUNITY 0x00873200
void MainView::TESMain_DrawWorld_DrawScene(ViewNode* listener, int unused, bool hide, bool drawInterface)
{
    ViewNode* root3 = Main_GetWorldSceneGraph();
    ViewNode* process = root3->FUN_008d80e0();
    ViewNode* otherProcess;
    ViewNode* cameraX;
    void* renderer2;
    DAT_011f9684 = root3->FUN_006629f0();
    if (listener)
        listener->Sun_StartSunOcclusion();
    bool savedVisibility = DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(true)->GetAppCulled_00456610();
    DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(true)->FUN_00450f90(true);
    m_88.Modelloader_GetReferencedThis()->m_38 = !hide;
    ViewNode* imageEffect5 = BSShaderManager_GetImageSpaceManager()->GetEffect_004ebbc0(4);
    m_88.Modelloader_GetReferencedThis()->m_3a = !hide && imageEffect5->ImageSpaceEffectDepthOfField_DoDepth();
    m_8c.Modelloader_GetReferencedThis()->m_3a = !hide && imageEffect5->ImageSpaceEffectDepthOfField_DoDepth();
    MemoryContext memory7(15, true, DAT_010829c4, 0x1eb7);
    cameraX = 0;
    cameraX = root3->FUN_006629f0();
    process->FUN_0041fd00(cameraX);
    process->NiCullingProcess_SetFrustum(cameraX->FUN_0045bbe0());
    process->BSCullingProcess_SetAccumulator(m_88.Modelloader_GetReferencedThis());
    // Partition visible objects between the two culling passes.
    if (DAT_011f94b4)
    {
        VisibleList leftList2;
        VisibleList rightList4;
        VisibleList commonList3;
        ViewNode* graph = FUN_00450b80(0);
        ViewNode* node2 = 0;
        ViewNode* branch = 0;
        node2 = graph->NiNode_GetAtChecked(0);
        if (node2 && !node2->GetAppCulled_00456610())
            commonList3.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(node2);
        node2 = graph->NiNode_GetAtChecked(1);
        if (node2 && !node2->GetAppCulled_00456610())
            commonList3.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(node2);
        node2 = graph->NiNode_GetAtChecked(2);
        if (node2 && !node2->GetAppCulled_00456610())
            branch = node2->AsNode();
        if (branch)
        {
            node2 = branch->NiNode_GetAtChecked(0);
            if (node2 && !node2->GetAppCulled_00456610())
                leftList2.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(node2);
            node2 = branch->NiNode_GetAtChecked(1);
            if (node2 && !node2->GetAppCulled_00456610())
                leftList2.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(node2);
            node2 = branch->NiNode_GetAtChecked(2);
            if (node2 && !node2->GetAppCulled_00456610())
                leftList2.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(node2);
        }
        node2 = graph->NiNode_GetAtChecked(3);
        branch = node2->AsNode();
        // Exterior and interior scenes organize their child nodes differently.
        if (!DAT_011dea10->FUN_005f36f0())
        {
            if (branch && !branch->GetAppCulled_00456610())
            {
                for (int i = 0; i < branch->FUN_0043b480(); ++i)
                {
                    node2 = branch->FUN_0043b4a0(i);
                    if (node2)
                    {
                        ViewNode* section = node2->AsNode();
                        if (section && !section->GetAppCulled_00456610())
                        {
                            for (int j = 0; j < section->FUN_0043b480(); ++j)
                            {
                                ViewNode* item = section->FUN_0043b4a0(j);
                                if (item)
                                {
                                    ViewNode* nested = item->AsNode();
                                    if (nested)
                                    {
                                        if (!nested->GetAppCulled_00456610())
                                        {
                                            int k = 0;
                                            if (j == 6)
                                                k = 1;
                                            for (; k < nested->FUN_0043b480(); ++k)
                                            {
                                                ViewNode* leaf = nested->FUN_0043b4a0(k);
                                                if (leaf && !leaf->GetAppCulled_00456610())
                                                {
                                                    if (i % 2)
                                                        leftList2.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(leaf);
                                                    else
                                                        rightList4.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(leaf);
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (i % 2)
                                            leftList2.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(item);
                                        else
                                            rightList4.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(item);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            if (FUN_00450b80(0)->ShadowSceneNode_HasVisibleUnboundSpace())
            {
                node2 = branch->NiNode_GetAtChecked(0);
                if (node2 && !node2->GetAppCulled_00456610())
                    rightList4.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(node2);
                node2 = branch->NiNode_GetAtChecked(1);
                if (node2 && !node2->GetAppCulled_00456610())
                    leftList2.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(node2);
                node2 = branch->NiNode_GetAtChecked(2);
                if (node2)
                {
                    branch = node2->AsNode();
                    if (branch && !branch->GetAppCulled_00456610())
                    {
                        for (int outerIndex = 0; outerIndex < branch->FUN_0043b480(); ++outerIndex)
                        {
                            node2 = branch->FUN_0043b4a0(outerIndex);
                            if (node2 && outerIndex != 4 && outerIndex != 0)
                            {
                                ViewNode* section2 = node2->AsNode();
                                if (section2 && !section2->GetAppCulled_00456610())
                                {
                                    int childIndex = 0;
                                    if (outerIndex == 6)
                                        childIndex = 1;
                                    for (; childIndex < section2->FUN_0043b480(); ++childIndex)
                                    {
                                        ViewNode* leaf2 = section2->FUN_0043b4a0(childIndex);
                                        if (leaf2 && !leaf2->GetAppCulled_00456610())
                                        {
                                            if (childIndex % 2)
                                                leftList2.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(leaf2);
                                            else
                                                rightList4.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(leaf2);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                node2 = branch->NiNode_GetAtChecked(2);
                if (node2)
                {
                    branch = node2->AsNode();
                    if (branch && !branch->GetAppCulled_00456610())
                    {
                        node2 = branch->NiNode_GetAtChecked(7);
                        if (node2)
                        {
                            branch = node2->AsNode();
                            if (branch)
                            {
                                for (int index3 = 0; index3 < branch->FUN_0043b480(); ++index3)
                                {
                                    ViewNode* leaf3 = branch->FUN_0043b4a0(index3);
                                    if (leaf3 && !leaf3->GetAppCulled_00456610())
                                    {
                                        if (index3 % 2)
                                            leftList2.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(leaf3);
                                        else
                                            rightList4.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(leaf3);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            ViewNode* area = FUN_00450b80(0)->ShadowSceneNode_QPortalGraph();
            ViewList* roomsTmp = area ? area->FUN_00436aa0() : 0;
            void* roomPosition4 = roomsTmp ? roomsTmp->Modelloader_GetReferencedThis() : 0;
            int visibleCount = 0;
            while (roomPosition4)
            {
                ViewNode* room = area->FUN_00436aa0()->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(&roomPosition4)->Modelloader_GetReferencedThis();
                if (room && !room->TESCombatStyle_GetAdvancedData()->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
                {
                    void* itemPosition = room->TESCombatStyle_GetAdvancedData()->Modelloader_GetReferencedThis();
                    while (itemPosition)
                    {
                        ViewNode* object = room->TESCombatStyle_GetAdvancedData()->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(&itemPosition)->value;
                        if (object && process->BSCullingProcess_AddShared(object->BSPortal_GetSharedGeometry()))
                        {
                            ViewGeometry* geometry = object->BSPortal_GetSharedGeometry();
                            if (geometry)
                            {
                                if (object->Projectile_GetShooter() && object->Projectile_GetDesiredTarget())
                                {
                                    FUN_00450b80(0)->FUN_00b5ba80(process->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), object);
                                }
                                if (visibleCount % 2)
                                    leftList2.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(geometry);
                                else
                                    rightList4.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(geometry);
                                ++visibleCount;
                            }
                        }
                    }
                }
            }
            if (FUN_00450b80(0)->ShadowSceneNode_HasVisibleUnboundSpace())
            {
                void* objectPosition = area->FUN_007d6bb0()->Modelloader_GetReferencedThis();
                while (objectPosition)
                {
                    ViewNode* object2 = area->FUN_007d6bb0()->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(&objectPosition)->value;
                    if (object2 && process->BSCullingProcess_AddShared(object2->BSPortal_GetSharedGeometry()))
                    {
                        ViewGeometry* geometry2 = object2->BSPortal_GetSharedGeometry();
                        if (geometry2)
                        {
                            if (visibleCount % 2)
                                leftList2.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(geometry2);
                            else
                                rightList4.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(geometry2);
                            ++visibleCount;
                        }
                    }
                }
            }
            ViewNode* extra6 = DAT_011dea10->FUN_00457070()->GetPortalGraph_009d9f20();
            if (extra6)
            {
                for (int extraIndex = 0; extraIndex < extra6->BSPortalGraph_GetAlwaysRenderArrayCount(); ++extraIndex)
                {
                    ViewNode* extraNode = extra6->BSPortalGraph_GetAlwaysRenderAt(extraIndex);
                    if (extraNode)
                        commonList3.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(extraNode);
                }
            }
        }
        node2 = graph->NiNode_GetAtChecked(4);
        if (node2 && !node2->GetAppCulled_00456610())
            commonList3.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(node2);
        node2 = graph->NiNode_GetAtChecked(5);
        if (node2 && !node2->GetAppCulled_00456610())
            commonList3.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(node2);
        node2 = graph->NiNode_GetAtChecked(6);
        if (node2 && !node2->GetAppCulled_00456610())
            leftList2.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(node2);
        for (int tailIndex = 7; tailIndex < graph->FUN_0043b480(); ++tailIndex)
        {
            node2 = graph->FUN_0043b4a0(tailIndex);
            if (node2 && !node2->GetAppCulled_00456610())
            {
                if (tailIndex % 2)
                    leftList2.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(node2);
                else
                    rightList4.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(node2);
            }
        }
        process->FUN_0041fd00(cameraX);
        FUN_00450b80(0)->ShadowSceneNode_PreOnVisible(process);
        if (FUN_00450b80(0)->TESDataHandler_GetEffectShaders())
            FUN_00450b80(0)->TESDataHandler_GetEffectShaders()->BSCompoundFrustum_PrethreadOpList();
        m_88.Modelloader_GetReferencedThis()->SetCamera(cameraX);
        BSShaderManager_SetAccumulator(m_88.Modelloader_GetReferencedThis());
        NiXenonRenderer_GetRenderer()->NiTexturingProperty_Map_SetTexture(m_88.Modelloader_GetReferencedThis());
        FUN_004ea970()->MTRenderingSystem_AddAccumTask(cameraX, FUN_00450b80(0)->TESDataHandler_GetEffectShaders(), 0, &leftList2, 0, m_88.Modelloader_GetReferencedThis(), 0,
                                     21, true);
        FUN_004ea970()->MTRenderingSystem_SetThreadStage(0, 21);
        DAT_012722bc = 0;
        ::BSCullingProcess localProcess((void*)0);
        localProcess.SetCamera(cameraX);
        localProcess.SetAccumulator((::MenuTarget*)m_88.Modelloader_GetReferencedThis());
        localProcess.SetCompoundFrustum((::TaskArg1*)FUN_00450b80(0)->TESDataHandler_GetEffectShaders());
        BSShaderUtil_AccumulateSceneList(cameraX, &rightList4, &localProcess);
        localProcess.SetCompoundFrustum(0);
        BSShaderUtil_AccumulateSceneList(cameraX, &commonList3, &localProcess);
        FUN_004ea970()->MTRenderingSystem_WaitOnThreadStage(1, 21);
        leftList2.FUN_004ed900();
        rightList4.FUN_004ed900();
    }
    else
    {
        BSShaderUtil_AccumulateScene(cameraX, root3, process);
    }
    // Finish the main scene and draw the requested interface layer.
    BSShaderUtil_RenderScenePreResolveDepth(root3->FUN_006629f0(), m_88.Modelloader_GetReferencedThis(), true);
    if (drawInterface)
    {
        FUN_00b98380(0, 1);
        Interface_GetVATSEffect()->FOVATSEffectManager_DrawTargetToTexture(0, 2, 1, 0, 0, 0);
        BSRenderState_RestoreColorWriteEnable(1);
    }
    BSShaderUtil_RenderScenePostResolveDepth(root3->FUN_006629f0(), m_88.Modelloader_GetReferencedThis(), true);
    if (DAT_011f94b4)
        FUN_00450b80(0)->nullsub_3(process);
    process->BSCullingProcess_SetAccumulator(0);
    memory7.FUN_00404f70();
    m_88.Modelloader_GetReferencedThis()->m_38 = false;
    m_88.Modelloader_GetReferencedThis()->m_3a = false;
    BSShaderBloodSplatterProperty_ResetShapeCount();
    // Render the auxiliary scene views through the secondary culling process.
    renderer2 = BSShaderManager_GetRenderer();
    otherProcess = Main_GetWorldSceneGraph()->FUN_008d80e0();
    otherProcess->SetImpactDataSet_004fb0b0(true);
    BSShaderBloodSplatter_ComputeScreenSpaceLightLoc(DAT_011deb7c.Modelloader_GetReferencedThis()->FUN_006629f0());
    otherProcess->FUN_0041fd00(ScreenSplatter_GetCamera());
    otherProcess->BSCullingProcess_SetAccumulator(m_94.Modelloader_GetReferencedThis());
    BSShaderUtil_AccumulateScene(ScreenSplatter_GetCamera(), ScreenSplatter_GetRoot(), otherProcess);
    FUN_00b6c0d0(ScreenSplatter_GetCamera(), m_94.Modelloader_GetReferencedThis(), false);
    process->BSCullingProcess_SetAccumulator(0);
    otherProcess->SetImpactDataSet_004fb0b0(false);
    BSShaderBloodSplatterProperty_ResetShapeCount();
    renderer2 = BSShaderManager_GetRenderer();
    otherProcess = Main_GetWorldSceneGraph()->FUN_008d80e0();
    otherProcess->SetImpactDataSet_004fb0b0(true);
    BSShaderBloodSplatter_ComputeScreenSpaceLightLoc(DAT_011deb7c.Modelloader_GetReferencedThis()->FUN_006629f0());
    otherProcess->FUN_0041fd00(ScreenCustomSplatter_GetCamera());
    otherProcess->BSCullingProcess_SetAccumulator(m_94.Modelloader_GetReferencedThis());
    BSShaderUtil_AccumulateScene(ScreenCustomSplatter_GetCamera(), ScreenCustomSplatter_GetCurrentRoot(), otherProcess);
    FUN_00b6c0d0(ScreenCustomSplatter_GetCamera(), m_94.Modelloader_GetReferencedThis(), false);
    process->BSCullingProcess_SetAccumulator(0);
    otherProcess->SetImpactDataSet_004fb0b0(false);
    if (*DAT_011c3ea4.Setting_Int() > 1)
        FUN_008c80e0(0);
    if (DAT_011f94a9)
        ImageSpaceEffectFullScreenBlur_CheckCamera(root3->FUN_006629f0());
    if (listener)
        listener->FUN_006426a0(true, m_88.Modelloader_GetReferencedThis(), DAT_011deb7c.Modelloader_GetReferencedThis()->FUN_006629f0());
    BSShaderAccumulator_SetRunBoundingSphereTests(false, false);
    DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(true)->FUN_00450f90(savedVisibility);
}
}  // namespace fnv_00873200

class NiObject;
class TESLevItem;
class INISettingCollection;
namespace fnv_00877730 {
struct GlobalObject_0045cf30;
using ::ImageSpaceManager;
using ::AutoMemHelper;

using ::NiUpdateData;

using ::NiNode;

struct GO00
{
    NiNode* Modelloader_GetReferencedThis();
};
struct GO34
{
    NiNode* Modelloader_GetReferencedThis();
};
struct GOa4
{
    NiNode* Modelloader_GetReferencedThis();
};
extern GO00 DAT_011deb00;
extern GO34 DAT_011deb34;
extern GOa4 g_011deda4;
extern GO34 DAT_011deb34;

using ::SettingT;
extern GlobalObject_0045cf30 g_011deadc;

struct ProcObj
{
    void Sky_Initialize(void* a, void* b);
    void* FUN_0045cd60();
    void* Sky_GetLight();
};
extern ProcObj* DAT_011dea20;

struct ModelOps
{
    void* NiObjectNET_GetControllers();
};

struct FUN_0049ec80_Property : NiRefObject
{
    void* unknown08;
    void* unknown0c;
    void* unknown10;
    unsigned int unknown14;
    unsigned short flags18;
    unsigned char alphaThreshold1a;
    unsigned char unknown1b;
    unsigned int unknown1c;
    unsigned int unknown20;
    FUN_0049ec80_Property();
    void NiAlphaProperty_SetAlphaBlending(bool b);
    void FUN_0049ede0(unsigned int value);
    void FUN_0050f9a0(unsigned int value);
};
typedef FUN_0049ec80_Property NiAlphaProperty;
struct HostV
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37(void* p, int i);
};

struct LightShell
{
    void FUN_00b5aac0(void* p);
};

struct ISM2
{
    void ImageSpaceManager_SetUseSunbeams(bool b);
};

void ProgramFlow(const char* s);
LightShell* FUN_00450b80(unsigned int i);
ImageSpaceManager* BSShaderManager_GetImageSpaceManager();
void FUN_00b57e30(void* p, int a, int b);

// @fnv 0x00877730
// src: COMMUNITY 0x00877730
void TESMain_InitSky()
{
    AutoMemHelper helper8(0x21, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0x26bd);
    ProgramFlow("Initializing Sky...");
    DAT_011dea20->Sky_Initialize(DAT_011deb34.Modelloader_GetReferencedThis(), DAT_011deb00.Modelloader_GetReferencedThis());
    ((HostV*)g_011deda4.Modelloader_GetReferencedThis())->v37(((ModelOps*)(void*)DAT_011dea20->FUN_0045cd60())->NiObjectNET_GetControllers(), 1);
    ((LightShell*)FUN_00450b80(0))->FUN_00b5aac0((void*)DAT_011dea20->Sky_GetLight());
    DAT_011deb34.Modelloader_GetReferencedThis()->UpdateProperties();
    ((ISM2*)BSShaderManager_GetImageSpaceManager())->ImageSpaceManager_SetUseSunbeams(((SettingT<INISettingCollection>*)&g_011deadc)->Bool()[0]);
    if (((SettingT<INISettingCollection>*)&g_011deadc)->Bool()[0])
    {
        NiAlphaProperty* obj = new NiAlphaProperty;
        ((NiAlphaProperty*)obj)->NiAlphaProperty_SetAlphaBlending(true);
        obj->FUN_0049ede0(2);
        obj->FUN_0050f9a0(0xff);
        DAT_011deb34.Modelloader_GetReferencedThis()->AttachProperty((::NiObject*)obj);
    }
    NiUpdateData upd1(0.0f, false, false);
    DAT_011deb34.Modelloader_GetReferencedThis()->Update(upd1);
    g_011deda4.Modelloader_GetReferencedThis()->UpdateProperties();
    NiUpdateData updTmp(0.0f, false, false);
    g_011deda4.Modelloader_GetReferencedThis()->Update(updTmp);
    FUN_00b57e30(DAT_011deb34.Modelloader_GetReferencedThis(), 0, 0);
    FUN_00b57e30(((ModelOps*)(void*)DAT_011dea20->FUN_0045cd60())->NiObjectNET_GetControllers(), 0, 0);
}
}  // namespace fnv_00877730

struct IDIDevice8
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetCapabilities(void* caps);
    virtual long __stdcall EnumObjects(void* cb, void* ref, unsigned long flags);
    virtual long __stdcall GetProperty(const void* guid, void* prop);
    virtual long __stdcall SetProperty(const void* guid, const void* prop);
    virtual long __stdcall Acquire();
    virtual long __stdcall Unacquire();
    virtual long __stdcall GetDeviceState(unsigned long cb, void* data);
    virtual long __stdcall GetDeviceData(unsigned long cbObjectData, void* rgdod, unsigned long* pdwInOut,
                                         unsigned long flags);
};
struct DIDeviceOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    IDIDevice8* m_pDirectInputDevice;
    void Controls_ClearKeystrokes();
};
// @fnv 0x00a237b0
// src: COMMUNITY 0x00a237b0
void DIDeviceOwner::Controls_ClearKeystrokes()
{
    if (m_pDirectInputDevice)
    {
        unsigned long dwItems = 0xffffffff;
        m_pDirectInputDevice->GetDeviceData(0x14, 0, &dwItems, 0);
    }
}

extern short DAT_011f35b0;
extern short DAT_011f35b2;
extern short DAT_011f35b4;
extern short DAT_011f35b6;
extern bool DAT_011f35c8;

struct FUN_00a23390_t
{
    int GetAxisState(int device, int axis);
};

// Returns the state of the specified controller axis, reading from per-device state or global fallback values for axes 7-10.
// @fnv 0x00a23390
int FUN_00a23390_t::GetAxisState(int device, int axis)
{
    int* pAxisState = (int*)((char*)this + device * 0xa0 + 0x34);
    switch (axis)
    {
    case 1:
        return pAxisState[0];
    case 2:
        return pAxisState[1];
    case 3:
        return pAxisState[2];
    case 4:
        return pAxisState[3];
    case 5:
        return pAxisState[4];
    case 6:
        return pAxisState[5];
    case 7:
        if (DAT_011f35c8)
            return DAT_011f35b0;
        break;
    case 8:
        if (DAT_011f35c8)
            return DAT_011f35b2;
        break;
    case 9:
        if (DAT_011f35c8)
            return DAT_011f35b4;
        break;
    case 10:
        if (DAT_011f35c8)
            return DAT_011f35b6;
        break;
    }
    return 0;
}

namespace sa238a0 {

extern unsigned char DAT_011a7440[256];
extern unsigned char DAT_011a7540[256];
extern unsigned char DAT_011a7640[256];
extern unsigned char DAT_011a7740[256];
extern unsigned char DAT_011a7840[256];
extern unsigned char DAT_011a7940[256];
extern unsigned char DAT_011a7a40[256];
extern unsigned char DAT_011a7b40[256];
extern unsigned char DAT_011a7c40[256];
extern unsigned char DAT_011a7d40[256];

int FUN_00a22cb0();

struct CharTable
{
    int Controls_TranslateKeystroke(int iChar, int iMode);
};

// Bounds-checks iChar, then returns a byte from a 256-entry table selected by iMode and FUN_00a22cb0().
// @fnv 0x00a238a0
// src: COMMUNITY 0x00a238a0
int CharTable::Controls_TranslateKeystroke(int iChar, int iMode)
{
    if (iChar < 0 || iChar > 0xff)
        return -1;
    if (iMode == 0xff)
        return DAT_011a7540[iChar];
    switch (FUN_00a22cb0())
    {
    case 3:
        return iMode ? DAT_011a7b40[iChar] : DAT_011a7a40[iChar];
    case 4:
        return iMode ? DAT_011a7d40[iChar] : DAT_011a7c40[iChar];
    case 2:
        return iMode ? DAT_011a7940[iChar] : DAT_011a7840[iChar];
    case 1:
        return iMode ? DAT_011a7740[iChar] : DAT_011a7640[iChar];
    default:
        return iMode ? DAT_011a7540[iChar] : DAT_011a7440[iChar];
    }
}

}

class NiCamera;
namespace fnv_00872b00 {
void* __fastcall SkyData_0045cd60(::Sky*);
int __fastcall SkyMode_00476c90(::Sky*);
using ::NiUpdateData;
struct ISMgr
{
    void FUN_00712e60(const NiColorA& p);
};
struct ISHolder
{
    void SceneGraph_SetCameraFOV(float f, int a, int b, bool c);
};
extern NiColorA DAT_011ad840;
struct StateObj
{
    unsigned int CallGetFlags();
};
extern StateObj DAT_011f2250;
using ::PlayerCharacter;
float __fastcall PlayerCharacter_GetWorldFOV(PlayerCharacter* p);
extern PlayerCharacter* g_thePlayer;
using ::BSShaderManager;
using ::NiAVObject;
struct CamNode
{
    ::NiAVObject* BSSceneGraph_GetCameraRoot();
    NiCamera* GetAnimationData();
};
struct CamNodePtr
{
    operator CamNode*() const;
};
struct NodePtr
{
    operator ::NiAVObject*() const;
};
extern CamNodePtr g_011deb7c;
extern NodePtr g_011deb34;
extern NodePtr g_011deda4;
struct BoolSetting
{
    bool* Bool();
};
extern BoolSetting g_011ded80;
extern BoolSetting g_011decd8;
extern BoolSetting g_011deb60;
struct CamWatcher
{
    int unk00;
    CamWatcher();
    ~CamWatcher();
    void HighActorCuller_Run(NiCamera* cam);
};
extern unsigned char DAT_011f9fc0;
extern unsigned char DAT_011f9fc1;
extern unsigned char DAT_011f94a5;
void __cdecl BSShaderAccumulator_SetRunBoundingSphereTests(bool a, bool b);
void __cdecl BSShaderAccumulator_SetDisplayBoundingSpheres(bool a);
using ::Sky;
using ::TES;
extern TES* g_TES;

// Main camera update at 0x00872b00 reads its +0x9c flag; include/Main.h is not available yet.
struct MainX
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
    bool bFlag9C;
    void* UpdateCamera();
};

// Applies image-space parameters, sets FOV, updates two scene objects from camera data, and returns a sky-provided pointer when conditions match.
// @fnv 0x00872b00
void* MainX::UpdateCamera()
{
    ((ISMgr*)Main_GetWorldSceneGraph()->::BSFaceGenNiNode::GetAnimationData())->FUN_00712e60(DAT_011ad840);
    if (DAT_011f2250.CallGetFlags() != 4)
    {
        ((ISHolder*)Main_GetWorldSceneGraph())->SceneGraph_SetCameraFOV(PlayerCharacter_GetWorldFOV(g_thePlayer), 0, 0, true);
    }
    BSShaderManager::SetFOV(PlayerCharacter_GetWorldFOV(g_thePlayer));
    if (bFlag9C)
    {
        ((ISMgr*)Main_GetWorldSceneGraph()->::BSFaceGenNiNode::GetAnimationData())->FUN_00712e60(NiColorA(0.0f, 1.0f, 1.0f, 0.0f));
    }
    NiCamera* pCamera = ((CamNode*)g_011deb7c)->GetAnimationData();
    NiCamera* pOverride6 = 0;
    if (*g_011ded80.Bool())
    {
        static CamWatcher kWatcher;
        kWatcher.HighActorCuller_Run(pOverride6 ? pOverride6 : pCamera);
    }
    ((::NiAVObject*)g_011deb34)->NiAVObject_SetTranslate(((CamNode*)g_011deb7c)->BSSceneGraph_GetCameraRoot()->GetTranslate_0043c490());
    NiUpdateData kData5(0.0f, false, false);
    ((::NiAVObject*)g_011deb34)->Update(kData5);
    ((::NiAVObject*)g_011deda4)->NiAVObject_SetTranslate(((CamNode*)g_011deb7c)->BSSceneGraph_GetCameraRoot()->GetTranslate_0043c490());
    NiUpdateData kData2(0.0f, false, false);
    ((::NiAVObject*)g_011deda4)->Update(kData2);
    if (DAT_011f9fc0)
    {
        DAT_011f9fc0 = 0;
        DAT_011f9fc1 = 1;
    }
    BSShaderAccumulator_SetRunBoundingSphereTests(*g_011decd8.Bool(), true);
    BSShaderAccumulator_SetDisplayBoundingSpheres(*g_011deb60.Bool());
    DAT_011f94a5 = 0;
    void* pResult = 0;
    if (g_TES->GetSky() && SkyData_0045cd60(g_TES->GetSky()) &&
        (SkyMode_00476c90(g_TES->GetSky()) == 3 || SkyMode_00476c90(g_TES->GetSky()) == 2))
    {
        pResult = SkyData_0045cd60(g_TES->GetSky());
    }
    return pResult;
}
}  // namespace fnv_00872b00

namespace fnv_0086ff70 {
struct Main86 : Main
{
    void Main_Swap();
    void Main_RenderMenuBackground();
    void TESMain_KillMenuBGTexture();
    void Main_DrawWorld(int, int, int);
    void TESMain_UpdateOffscreenInterface();
    void Main_DrawWorldMenu3D(int);
    void TESMain_DrawWorld_CopyMenuBG(int);
};
struct Extra86
{
    void ProcessLists_SkipHighListFadeIn();
};
struct PlayerState86
{
    virtual bool vfn_000();
    virtual bool vfn_004();
    virtual bool vfn_008();
    virtual bool vfn_00c();
    virtual bool vfn_010();
    virtual bool vfn_014();
    virtual bool vfn_018();
    virtual bool vfn_01c();
    virtual bool vfn_020();
    virtual bool vfn_024();
    virtual bool vfn_028();
    virtual bool vfn_02c();
    virtual bool vfn_030();
    virtual bool vfn_034();
    virtual bool vfn_038();
    virtual bool vfn_03c();
    virtual bool vfn_040();
    virtual bool vfn_044();
    virtual bool vfn_048();
    virtual bool vfn_04c();
    virtual bool vfn_050();
    virtual bool vfn_054();
    virtual bool vfn_058();
    virtual bool vfn_05c();
    virtual bool vfn_060();
    virtual bool vfn_064();
    virtual bool vfn_068();
    virtual bool vfn_06c();
    virtual bool vfn_070();
    virtual bool vfn_074();
    virtual bool vfn_078();
    virtual bool vfn_07c();
    virtual bool vfn_080();
    virtual bool vfn_084();
    virtual bool vfn_088();
    virtual bool vfn_08c();
    virtual bool vfn_090();
    virtual bool vfn_094();
    virtual bool vfn_098();
    virtual bool vfn_09c();
    virtual bool vfn_0a0();
    virtual bool vfn_0a4();
    virtual bool vfn_0a8();
    virtual bool vfn_0ac();
    virtual bool vfn_0b0();
    virtual bool vfn_0b4();
    virtual bool vfn_0b8();
    virtual bool vfn_0bc();
    virtual bool vfn_0c0();
    virtual bool vfn_0c4();
    virtual bool vfn_0c8();
    virtual bool vfn_0cc();
    virtual bool vfn_0d0();
    virtual bool vfn_0d4();
    virtual bool vfn_0d8();
    virtual bool vfn_0dc();
    virtual bool vfn_0e0();
    virtual bool vfn_0e4();
    virtual bool vfn_0e8();
    virtual bool vfn_0ec();
    virtual bool vfn_0f0();
    virtual bool vfn_0f4();
    virtual bool vfn_0f8();
    virtual bool vfn_0fc();
    virtual bool vfn_100();
    virtual bool vfn_104();
    virtual bool vfn_108();
    virtual bool vfn_10c();
    virtual bool vfn_110();
    virtual bool vfn_114();
    virtual bool vfn_118();
    virtual bool vfn_11c();
    virtual bool vfn_120();
    virtual bool vfn_124();
    virtual bool vfn_128();
    virtual bool vfn_12c();
    virtual bool vfn_130();
    virtual bool vfn_134();
    virtual bool vfn_138();
    virtual bool vfn_13c();
    virtual bool vfn_140();
    virtual bool vfn_144();
    virtual bool vfn_148();
    virtual bool vfn_14c();
    virtual bool vfn_150();
    virtual bool vfn_154();
    virtual bool vfn_158();
    virtual bool vfn_15c();
    virtual bool vfn_160();
    virtual bool vfn_164();
    virtual bool vfn_168();
    virtual bool vfn_16c();
    virtual bool vfn_170();
    virtual bool vfn_174();
    virtual bool vfn_178();
    virtual bool vfn_17c();
    virtual bool vfn_180();
    virtual bool vfn_184();
    virtual bool vfn_188();
    virtual bool vfn_18c();
    virtual bool vfn_190();
    virtual bool vfn_194();
    virtual bool vfn_198();
    virtual bool vfn_19c();
    virtual bool vfn_1a0();
    virtual bool vfn_1a4();
    virtual bool vfn_1a8();
    virtual bool vfn_1ac();
    virtual bool vfn_1b0();
    virtual bool vfn_1b4();
    virtual bool vfn_1b8();
    virtual bool vfn_1bc();
    virtual bool vfn_1c0();
    virtual bool vfn_1c4();
    virtual bool vfn_1c8();
    virtual bool vfn_1cc();
    virtual int vfn_1d0();
    PlayerState86* PlayerCharacter_Get3D_00950bb0(int);
};
struct PlayerContext86
{
    bool GetAppCulled_00456610();
    void FUN_00450f90(int);
};
struct Core86
{
    void NiXenonRenderer_LockRenderer();
    void FUN_005585e0();
    int FUN_004e9530();
    void NiXenonRenderer_UnlockRenderer();
};
struct Input86
{
    bool FUN_00701450(int);
    void FUN_007010e0(int, int);
    bool IsFaderActive(int);
};
struct Topic86
{
    void RecreateCanopyShadowMaskTexture();
};
struct Engine86
{
    void TES_ShowLoadingMenu(int, int, int);
    int FUN_005f36f0();
    Engine86* FUN_004fd3e0();
    const char* TESWorldSpace_GetCanopyShadowTextureName();
    Topic86* FUN_0044ddc0();
    void RecreateCanopyShadowMaskTexture();
};
struct Global86
{
    int Modelloader_GetReferencedThis();
    void FUN_0066b0d0(int);
};
struct Resource86
{
    void BSSceneGraph_SetCameraScene();
};
struct Options86
{
    int* Setting_Int();
    void ProcessAndReturnValue_0045ce80(int);
};
struct Frame86
{
    float FUN_007013e0();
    void BSTimer_ClampAt(int);
};
struct Node86
{
    void FUN_004534f0(int);
    bool FUN_0047c850();
    void FUN_00483710();
};
struct Sound86
{
    void MTRenderingSystem_StartThreads();
    void MTRenderingSystem_SetThreadStage();
    void MTRenderingSystem_WaitOnThreadStage();
    void MTRenderingSystem_WaitForThreads();
};
struct GlobalText86
{
    int FUN_00403df0();
};
struct ControlItem86
{
    bool Controls_GetUserAction();
    bool Controls_GetKeyboardButton();
};
struct Settings86
{
    int* Setting_Int();
};
struct Sink86
{
    void FUN_00701450(int);
};
struct ContextResult86
{
    bool FUN_004e9530();
};
struct MenuHandler86
{
    void BSTimer_ClampAt(int);
};
struct Receiver86;
extern Receiver86* __cdecl NiXenonRenderer_GetRenderer();
extern Sound86* __cdecl FUN_004ea970();
extern Sound86* __stdcall FUN_004ea970(int, int);
extern char __cdecl Interface_IsMenuIDVisible(int, int);
extern bool __cdecl StartMenu_MainMenuIsActive();
extern bool __cdecl Interface_IsInRenderedMenu();
extern bool __cdecl Interface_IsInRenderedMenu(int);
extern bool __cdecl Interface_IsInMenuMode();
extern bool __cdecl Cmd_Default_Execute();
extern void __cdecl BSShaderManager_RenderDebugTexture();
extern void __cdecl Interface_DrawHUDMenu3D();
extern void __cdecl Object_DoNothing();
extern int __cdecl ProgramFlow(...);
extern void __cdecl ApplyGammaRamp();
extern void __cdecl FUN_0070edf0_unused();
extern void __cdecl SaveScreenshot(int);
extern void __cdecl NiObjectGarbage_Update();
extern void __cdecl FUN_00b6b730();
extern void __cdecl BSSceneGraph_SetCameraScene();
extern void __cdecl FUN_008c80e0(int);
extern void __cdecl BSsprintf(char*, unsigned int, const char*, int, int);
extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char*, void*);
extern int __stdcall BSShaderManager_GetImageSpaceManager(Core86*, int, int);
extern void __cdecl RenderOrFallback(int, int);
struct SwapMessage86
{
    void BSTextureManager_ReturnRenderedTexture();
};
extern SwapMessage86* __stdcall BSShaderManager_GetTextureManager(int);
extern void __cdecl BSTextureManager_ReturnRenderedTexture();
extern bool __cdecl TESRenderer_GetMultiSampleEnabled();
extern int DAT_011e0e80;
extern void __cdecl NiXAdapaterDesc_GetDeviceCaps();
extern char __cdecl FUN_00707000_unused();
extern unsigned char DAT_011d890a, DAT_011c6fb8, DAT_011dea29;
extern bool DAT_011dea40;
extern int DAT_011def04, DAT_011dea44;
extern float DAT_011def00;
extern double DAT_01012070;
extern PlayerState86* DAT_011dea3c;
extern Engine86* DAT_011dea10;
extern Input86* DAT_011d8804;
extern Node86* DAT_011de45c;
extern Global86 DAT_011ded3c, DAT_011dec64, DAT_011deb7c;
extern Options86 DAT_011deecc, DAT_011dee00, DAT_011c3ea4;
extern Frame86 DAT_011f6394;
extern GlobalText86 DAT_011deb04;
extern ControlItem86 DAT_011fdf30_dummy;
extern const char DAT_01082ca4[];
extern unsigned char DAT_011dea29;
extern int DAT_011c6fb8_dummy;
extern int DAT_011dea40_dummy;
extern int DAT_011def04;
extern char __cdecl GridCellArray_GetRecreateCanopyShadowMaskTexture();
extern void __cdecl FUN_004ea970_set();
extern void __cdecl FUN_0045cd60();
extern void __cdecl InterfaceManager_UpdateQueuedMenuClosings();
extern void __cdecl Interface_PostIdleStuff();
extern void __cdecl Interface_Idle();
extern void __cdecl Interface_PreIdleStuff();
extern void __cdecl Object_DoNothing();
extern void __cdecl NiObjectGarbage_Update();
extern void __cdecl FUN_00878660();
extern int __cdecl ProgramFlow(...);
extern void __cdecl NiXenonRenderer_UnlockRenderer();
extern float __cdecl FUN_00450820();
extern void __cdecl Interface_PostIdleStuff();
extern void __cdecl RenderOrFallback(int, int);
struct Control86
{
    int Controls_GetUserAction();
    int Controls_GetKeyboardButton();
};
extern Control86* __stdcall Controls_GetInstance(int, int);
extern Control86* __cdecl FUN_007fdf30_control(int, int);
struct Receiver86;
extern Receiver86* __cdecl NiXenonRenderer_GetRenderer();
extern int __cdecl FUN_004e3270_variant(int, int);
extern void __cdecl FUN_00450f90_variant(int);
extern int __cdecl FUN_004dc310_variant(int);
extern void __cdecl FUN_004ea970_variant();
extern void __cdecl BSTextureManager_ReturnRenderedTexture();
extern void __cdecl BSSceneGraph_SetCameraScene();
extern void __cdecl FUN_004e9530_dummy();
extern int __cdecl FUN_0043c4b0_unused();
extern int __cdecl FUN_0044ddc0_unused();
extern void __cdecl FUN_007028b0_unused();
extern int __cdecl FUN_00559450_unused();
// Runs player, input, audio, and state update calls, then performs frame cleanup and resource updates.
// @fnv 0x0086ff70
// src: XBOX_PDB 0x0086ff70
void Main86::Main_Swap()
{
    Core86* core = reinterpret_cast<Core86*>(NiXenonRenderer_GetRenderer());
    core->NiXenonRenderer_LockRenderer();
    if (DAT_011d890a)
    {
        DAT_011d890a = 0;
        bool first = reinterpret_cast<PlayerContext86*>(DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(1))->GetAppCulled_00456610();
        bool second = reinterpret_cast<PlayerContext86*>(DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(0))->GetAppCulled_00456610();
        reinterpret_cast<PlayerContext86*>(DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(1))->FUN_00450f90(1);
        reinterpret_cast<PlayerContext86*>(DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(0))->FUN_00450f90(1);
        Main_RenderMenuBackground();
        reinterpret_cast<PlayerContext86*>(DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(1))->FUN_00450f90(first);
        reinterpret_cast<PlayerContext86*>(DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(0))->FUN_00450f90(second);
    }
    reinterpret_cast<Core86*>(NiXenonRenderer_GetRenderer())->FUN_005585e0();
    Object_DoNothing();
    ProgramFlow();
    FUN_004ea970()->MTRenderingSystem_StartThreads();
    if (DAT_011c6fb8)
        ApplyGammaRamp();
    if (DAT_011d8804->FUN_00701450(1) || DAT_011d8804->FUN_00701450(2))
    {
        if (!DAT_011def04)
        {
            DAT_011dea10->TES_ShowLoadingMenu(0, 0, 0);
            ProgramFlow();
            reinterpret_cast<Extra86*>(&DAT_011e0e80)->ProcessLists_SkipHighListFadeIn();
        }
        DAT_011def00 += DAT_011f6394.FUN_007013e0();
        ++DAT_011def04;
        if (DAT_011def00 >= DAT_01012070 && DAT_011def04 >= 10)
        {
            DAT_011d8804->FUN_007010e0(1, 0);
            DAT_011d8804->FUN_007010e0(2, 0);
            DAT_011de45c->FUN_004534f0(0);
            if (DAT_011de45c->FUN_0047c850())
            {
                DAT_011de45c->FUN_004534f0(0);
                DAT_011de45c->FUN_00483710();
            }
            TESMain_KillMenuBGTexture();
        }
    }
    else
    {
        DAT_011def00 = 0.0f;
        DAT_011def04 = 0;
    }
    int eventState = 0;
    if (!DAT_011dea29 && !StartMenu_MainMenuIsActive() && DAT_011dea3c->vfn_1d0() && !DAT_011d8804->IsFaderActive(1))
    {
        if (!DAT_011dea10->FUN_005f36f0())
        {
            if (DAT_011dea10->FUN_004fd3e0()->TESWorldSpace_GetCanopyShadowTextureName()[0] && DAT_011dea10->FUN_0044ddc0())
            {
                DAT_011dea10->FUN_0044ddc0();
                if ((unsigned char)GridCellArray_GetRecreateCanopyShadowMaskTexture())
                    DAT_011dea10->FUN_0044ddc0()->RecreateCanopyShadowMaskTexture();
            }
        }
        Main_DrawWorld(0, 0, 0);
    }
    else if ((Interface_IsInRenderedMenu() || !Interface_IsInMenuMode()) && !(unsigned char)Interface_IsMenuIDVisible(0x3f5, 0))
    {
        if (DAT_011dea3c->vfn_1d0())
            Main_DrawWorld(0, Interface_IsInRenderedMenu(), 0);
    }
    else
    {
        for (int i = 1; i < 23; ++i)
        {
            FUN_004ea970(0, i)->MTRenderingSystem_SetThreadStage();
            FUN_004ea970(1, i)->MTRenderingSystem_WaitOnThreadStage();
        }
        TESMain_UpdateOffscreenInterface();
        if ((unsigned char)Interface_IsMenuIDVisible(0x41e, 0) || (unsigned char)Interface_IsMenuIDVisible(0x3f6, 0) ||
            (unsigned char)Interface_IsMenuIDVisible(0x424, 0) || (unsigned char)Interface_IsMenuIDVisible(0x432, 0) ||
            (unsigned char)Interface_IsMenuIDVisible(0x438, 0) || (unsigned char)Interface_IsMenuIDVisible(0x439, 0) ||
            (unsigned char)Interface_IsMenuIDVisible(0x43a, 0) || (unsigned char)Interface_IsMenuIDVisible(0x43b, 0))
            Main_DrawWorldMenu3D(0);
        else if (DAT_011ded3c.Modelloader_GetReferencedThis())
            TESMain_DrawWorld_CopyMenuBG(BSShaderManager_GetImageSpaceManager(core, TESRenderer_GetMultiSampleEnabled(), 0));
    }
    if (Cmd_Default_Execute() == 1)
        BSShaderManager_RenderDebugTexture();
    Interface_DrawHUDMenu3D();
    RenderOrFallback(eventState, DAT_011dec64.Modelloader_GetReferencedThis());
    FUN_004ea970()->MTRenderingSystem_WaitForThreads();
    if (DAT_011dec64.Modelloader_GetReferencedThis())
    {
        BSShaderManager_GetTextureManager(DAT_011dec64.Modelloader_GetReferencedThis())->BSTextureManager_ReturnRenderedTexture();
        DAT_011dec64.FUN_0066b0d0(0);
    }
    if (Controls_GetInstance(0x1e, 1)->Controls_GetUserAction())
    {
        if (Controls_GetInstance(0x9d, 0)->Controls_GetKeyboardButton() || DAT_011dea40)
        {
            DAT_011dea40 = !DAT_011dea40;
            if (DAT_011dea40)
            {
                DAT_011dea44 = 0;
                DAT_011deecc.ProcessAndReturnValue_0045ce80(*DAT_011deecc.Setting_Int() + 1);
                char outputDirectory[0x104];
                BSsprintf(outputDirectory, 0x104, DAT_01082ca4, DAT_011deb04.FUN_00403df0(),
                             *DAT_011deecc.Setting_Int());
                CreateDirectoryA(outputDirectory, 0);
                DAT_011f6394.BSTimer_ClampAt(*DAT_011dee00.Setting_Int());
            }
            else
                DAT_011f6394.BSTimer_ClampAt(0);
        }
        else
            SaveScreenshot(0);
    }
    NiObjectGarbage_Update();
    if (core->FUN_004e9530())
        FUN_00b6b730();
    if (eventState)
    {
        BSShaderManager_GetTextureManager(eventState)->BSTextureManager_ReturnRenderedTexture();
        eventState = 0;
    }
    reinterpret_cast<Resource86*>(DAT_011deb7c.Modelloader_GetReferencedThis())->BSSceneGraph_SetCameraScene();
    core->NiXenonRenderer_UnlockRenderer();
    if (*DAT_011c3ea4.Setting_Int() > 1)
        FUN_008c80e0(0);
}
}  // namespace fnv_0086ff70

namespace fnv_00870bd0 {
struct FUN_00414430;
using ::NiPoint2;
struct ImageView;
struct ProjectionView;
ImageView* BSShaderManager_GetImageSpaceManager();
ProjectionView* Main_GetWorldSceneGraph();
bool TESRenderer_GetMultiSampleEnabled();
unsigned char BSShaderManager_GetImageSpaceEffects();
bool ScreenCustomSplatter_IsActiveSplatter();
struct RenderNode
{
    bool GetAppCulled_00456610();
    void FUN_00450f90(bool);
};
// 0x0045cd60 returns Sky::m_pSun (+0x28); 0x0043b230 obtains its +0x0c scene object.
// Sun.h has no declaration for that accessor; keep its call without a duplicate Sun class.
NiAVObject* __fastcall SunSceneObject_0043b230(::Sun*);
struct PlayerView
{
    RenderNode* PlayerCharacter_Get3D_00950bb0(bool);
};
// 0x00705910 is Interface::GetVATSEffect; this receiver is the interface effect, not Menu.
struct VATSEffect
{
    int FUN_005585e0();
};
struct WorldView
{
    int FUN_005f36f0();
};
// 0x0045bb80 is NiAVObject::FUN_0045bb80 (world translation), not a NiPoint3 method.
using ::NiAVObject;
struct CameraView
{
    virtual void v0();
    virtual NiAVObject* v1();
};
struct CameraHolder
{
    CameraView* FUN_0045cd60();
};
struct ProjectionResult
{
    bool ProjectPointToScreen();
};
struct ProjectionView
{
    ProjectionResult* FUN_006629f0(const NiPoint3&, float&, float&, float&, float);
};
struct RenderView
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43(void*);
    unsigned FUN_004dee10();
    unsigned FUN_004dee70();
    void RendererClearBufferHook(FUN_00414430*, bool);
};
struct EffectView
{
    bool ImageSpaceEffectDepthOfField_DoDepth();
};
struct ImageView
{
    EffectView* GetEffect_004ebbc0(int);
    bool FUN_00b8b390(int);
    void ImageSpaceManager_SetSunPosition(const NiPoint2&);
};
struct ShaderView
{
    unsigned SumItemSubValues();
};
struct ShaderHolder
{
    ShaderView* Modelloader_GetReferencedThis();
};
using ::Setting;

struct ToggleView
{
    void MTRenderingSystem_WaitOnThreadStage();
    void MTRenderingSystem_SetThreadStage();
};
struct FUN_00414430
{
    float a, b, c, d;
    FUN_00414430(float, float, float, float);
};
extern PlayerView* DAT_011dea3c;
extern WorldView* DAT_011dea10;
extern CameraHolder* DAT_011dea20;
extern Setting DAT_011dea8c;
extern Setting DAT_011deadc;
extern int DAT_011a9bd0;
RenderView* NiXenonRenderer_GetRenderer();
VATSEffect* Interface_GetVATSEffect();
bool DialogMenu_IsDialogActive();
bool IsEyefinity();
bool Interface_IsGunScopeVisible();
bool BSShaderManager_IsRefractionEnabled();
bool ScreenSplatter_IsActiveSplatter();
bool Interface_IsInPipboyMenu();
float FUN_00706e70();
void BSShaderManager_EnableFullScreenScissor(unsigned, unsigned, unsigned, unsigned);
ToggleView* __stdcall FUN_004ea970(int, int);

void BSShaderManager_DisableFullScreenScissor();
struct RenderCoordinator
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c,
        unk80, unk84;
    ShaderHolder shaders;
    void FUN_00872ad0();
    ::Sun* UpdateCamera();
    void TESMain_DrawWorld_UpdateWater();
    bool TESMain_DrawWorld_VATSOcclusionQuery();
    void Main_DrawWorld_UpdateOffscreenBuffers();
    BSRenderedTexture* TESMain_DrawWorld_InitRenderTexture(RenderView*, int, int, bool);
    void TESMain_DrawWorld_VATS(bool);
    void TESMain_DrawWorld_RestartRenderTexture(BSRenderedTexture*, bool, unsigned);
    void TESMain_DrawWorld_DrawScene(::Sun*, bool, int, bool);
    void TESMain_DrawWorld_Add1stPersonToDepthBuffer(BSRenderedTexture*);
    void TESMain_DrawWorld_Refraction(ShaderView*, BSRenderedTexture*);
    void Main_DrawWorld_MTSetup1stPerson();
    void TESMain_DrawWorld_MTRender1stPerson(RenderView*, int, ::Sun*, BSRenderedTexture*);
    void Main_DrawWorld_DoDepth(ShaderView*, BSRenderedTexture*);
    void TESMain_DrawWorld_DoVolumetricFog(ShaderView*, BSRenderedTexture*);
    void TESMain_DrawWorld_ImageSpace(bool, BSRenderedTexture*, RenderView*, int);
    void TESMain_DrawWorld_ScreenSplatter(RenderView*);
    void TESMain_DrawWorld_StopRenderTarget(bool, int);
    void TESMain_DrawWorld_End(BSRenderedTexture*, ImageView*, RenderView*, ::Sun*);
    void TESMain_DrawWorldStandard(int, bool);
};
// Renders the scene into a BSRenderedTexture, applying effects, post-processing, and camera projection based on the given argument and skip flag.
// @fnv 0x00870bd0
// src: COMMUNITY 0x00870bd0
void RenderCoordinator::TESMain_DrawWorldStandard(int arg, bool skip)
{
    RenderView* l = NiXenonRenderer_GetRenderer();
    ImageView* h = (ImageView*)BSShaderManager_GetImageSpaceManager();
    ::Sun* s = 0;
    bool p = DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(true)->GetAppCulled_00456610();
    bool q = TESRenderer_GetMultiSampleEnabled();
    FUN_00872ad0();
    s = UpdateCamera();
    TESMain_DrawWorld_UpdateWater();
    bool i = TESMain_DrawWorld_VATSOcclusionQuery();
    Main_DrawWorld_UpdateOffscreenBuffers();
    BSRenderedTexture* j = TESMain_DrawWorld_InitRenderTexture(l, arg, 0, q);
    TESMain_DrawWorld_VATS(i);
    TESMain_DrawWorld_RestartRenderTexture(j, q, 5);
    bool cf = !p && !skip && !Interface_GetVATSEffect()->FUN_005585e0() && !DialogMenu_IsDialogActive();
    bool a = false;
    if (cf && s)
    {
        a = SunSceneObject_0043b230(s)->IsCulledFlag();
        SunSceneObject_0043b230(s)->SetAppCulled(true);
    }
    bool eb = true;
    if (IsEyefinity())
        eb = false;
    bool e = Interface_IsGunScopeVisible();
    if (e)
    {
        unsigned j = l->FUN_004dee10();
        unsigned c = l->FUN_004dee70();
        float l = *DAT_011dea8c.Setting_Float_00403e20() * FUN_00706e70() * 0.5;
        float e = j * l;
        float k = j - e;
        if (eb)
            BSShaderManager_EnableFullScreenScissor((unsigned)e, 0, (unsigned)k, c);
    }
    TESMain_DrawWorld_DrawScene(s, cf, 0, i);
    if (cf && s)
        SunSceneObject_0043b230(s)->SetAppCulled(a);
    EffectView* k = h->GetEffect_004ebbc0(4);
    bool c = k->ImageSpaceEffectDepthOfField_DoDepth();
    bool j7 = (h->FUN_00b8b390(9) && !DAT_011dea10->FUN_005f36f0() && *DAT_011deadc.FUN_00408d60()) ? true : false;
    const bool ba = false;
    const bool f = false;
    bool b = false;
    if ((c || ba || f) && cf)
    {
        b = true;
        TESMain_DrawWorld_Add1stPersonToDepthBuffer(j);
        TESMain_DrawWorld_RestartRenderTexture(j, q, 0);
    }
    if (BSShaderManager_IsRefractionEnabled() && shaders.Modelloader_GetReferencedThis()->SumItemSubValues() > 0)
        TESMain_DrawWorld_Refraction(shaders.Modelloader_GetReferencedThis(), j);
    if (cf)
    {
        Main_DrawWorld_MTSetup1stPerson();
        TESMain_DrawWorld_RestartRenderTexture(j, q, 0);
        if (!b)
            FUN_004ea970(1, 22)->MTRenderingSystem_WaitOnThreadStage();
        TESMain_DrawWorld_MTRender1stPerson(l, 0, s, j);
    }
    else
    {
        FUN_004ea970(0, 22)->MTRenderingSystem_SetThreadStage();
        FUN_004ea970(1, 22)->MTRenderingSystem_WaitOnThreadStage();
    }
    if (c || ba)
        Main_DrawWorld_DoDepth(shaders.Modelloader_GetReferencedThis(), j);
    if (f)
        TESMain_DrawWorld_DoVolumetricFog(shaders.Modelloader_GetReferencedThis(), j);
    if (j7 && !DAT_011dea10->FUN_005f36f0() && DAT_011dea20 && DAT_011dea20->FUN_0045cd60())
    {
        NiPoint3 v = DAT_011dea20->FUN_0045cd60()->v1()->NiAVObject_GetWorldTranslate();
        float w, u, n;
        w = u = n = 0.0f;
        ProjectionView* a = (ProjectionView*)Main_GetWorldSceneGraph();
        bool f = a->FUN_006629f0(v, w, u, n, 0.00001f)->ProjectPointToScreen();
        ((ImageView*)BSShaderManager_GetImageSpaceManager())->ImageSpaceManager_SetSunPosition(NiPoint2(w, u));
    }
    if (BSShaderManager_GetImageSpaceEffects())
    {
        TESMain_DrawWorld_ImageSpace(q, j, l, arg);
        if ((ScreenCustomSplatter_IsActiveSplatter() || ScreenSplatter_IsActiveSplatter()) && !Interface_IsInPipboyMenu())
            TESMain_DrawWorld_ScreenSplatter(l);
    }
    else if (arg)
        TESMain_DrawWorld_StopRenderTarget(q, arg);
    if (e)
    {
        if (eb)
            BSShaderManager_DisableFullScreenScissor();
        if (IsEyefinity())
        {
            NiXenonRenderer_GetRenderer()->v43(&DAT_011a9bd0);
            FUN_00414430 param(0, 0, 0, 0);
            param.a = 0;
            param.b = 0.33f;
            param.c = 1;
            param.d = 0;
            NiXenonRenderer_GetRenderer()->RendererClearBufferHook(&param, true);
            param.a = 0.66f;
            param.b = 1;
            param.c = 1;
            param.d = 0;
            NiXenonRenderer_GetRenderer()->RendererClearBufferHook(&param, true);
        }
    }
    TESMain_DrawWorld_End(j, h, l, s);
}
}  // namespace fnv_00870bd0

class HWND__;
namespace fnv_00872570 {
class BGSMoviePlayer_ML
{
  public:
    bool MoviePlayer_GetPlayingSequence();
    void FUN_00ec29b0();
    void MoviePlayer_WaitForSequenceToEnd();
    bool BGSMoviePlayer_IsPlaying();
    void MoviePlayer_Stop();
};
struct RenderManager_ML
{
    void BSShaderAccumulator_ClearAllQueries();
};
RenderManager_ML* __cdecl BSShaderManager_GetAccumulator();
struct CellState_ML
{
    int unk00;
    int active;
};
struct CellUpdate_ML
{
    void GetCanopyShadowMask(void**, CellState_ML**);
};
struct GridCell_ML
{
    CellUpdate_ML* cell;
};
struct CellGrid_ML
{
    int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct WorldAudio_ML
{
    void ReleaseWaterResources(int, int);
    void TESWaterSystem_EnableWaterSystem();
};
class TES_ML
{
  public:
    CellGrid_ML* FUN_0044ddc0();
    GridCell_ML* GetGridCell_00457050(int, int);
    WorldAudio_ML* DetailedActorPathHandler_GetCurrentNodeIndex();
};
class OSGlobals_ML
{
  public:
    int unk00;
    int unk04;
    HWND__* window;
    void TESMain_KillMenuBGTexture();
};
void __cdecl BSSleep(unsigned long);
unsigned char __cdecl TESRenderer_GetFullScreen();
unsigned char __cdecl TESWaterSystem_GetWaterEnabled();
void __cdecl ImageSpaceEffectHDR_ClearAdaptedLight();
extern unsigned char DAT_011f941e;
struct WindowRect_ML
{
    long left, top, right, bottom;
};
extern "C" __declspec(dllimport) long __stdcall GetWindowLongA(HWND__*, int);
extern "C" __declspec(dllimport) int __stdcall AdjustWindowRectEx(WindowRect_ML*, unsigned long, int, unsigned long);
extern "C" __declspec(dllimport) int __stdcall SetWindowPos(HWND__*, HWND__*, int, int, int, int, unsigned int);

namespace MainLoopGlobals {
extern "C" BGSMoviePlayer_ML* DAT_0126fac4;
extern "C" TES_ML* DAT_011dea10;
extern "C" OSGlobals_ML* g_osGlobals;
extern "C" bool __cdecl LoadingMenuThread_GetByte49();
extern "C" long __cdecl Renderer_GetScreenWidth();
extern "C" long __cdecl Renderer_GetScreenHeight();
}

// When active, waits for a condition and updates render, cell, and window state; otherwise, it performs audio-related calls.
// @fnv 0x00872570
// src: COMMUNITY 0x00872570
bool __cdecl TESMain_ResetDeviceCallback(bool active)
{
    if (active)
    {
        while (!(unsigned char)MainLoopGlobals::LoadingMenuThread_GetByte49())
            BSSleep(5);
        if (MainLoopGlobals::DAT_0126fac4->MoviePlayer_GetPlayingSequence())
        {
            MainLoopGlobals::DAT_0126fac4->FUN_00ec29b0();
            MainLoopGlobals::DAT_0126fac4->MoviePlayer_WaitForSequenceToEnd();
        }
        if (MainLoopGlobals::DAT_0126fac4->BGSMoviePlayer_IsPlaying())
            MainLoopGlobals::DAT_0126fac4->MoviePlayer_Stop();
        RenderManager_ML* renderer = BSShaderManager_GetAccumulator();
        if (renderer)
            renderer->BSShaderAccumulator_ClearAllQueries();
        {
            int count = MainLoopGlobals::DAT_011dea10->FUN_0044ddc0()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            for (int x = 0; x < count; ++x)
            {
                for (int y = 0; y < count; ++y)
                {
                    CellUpdate_ML* cell = MainLoopGlobals::DAT_011dea10->GetGridCell_00457050(x, y)->cell;
                    if (cell)
                    {
                        void* object;
                        CellState_ML* state;
                        cell->GetCanopyShadowMask(&object, &state);
                        if (object && state && state->active)
                            state->active = 0;
                    }
                }
            }
            MainLoopGlobals::g_osGlobals->TESMain_KillMenuBGTexture();
            if (TESRenderer_GetFullScreen())
            {
                long style;
                {
                    WindowRect_ML rectWindow;
                    rectWindow.left = 0;
                    rectWindow.top = 0;
                    rectWindow.right = MainLoopGlobals::Renderer_GetScreenWidth();
                    rectWindow.bottom = MainLoopGlobals::Renderer_GetScreenHeight();
                    style = 0;
                    style = fnv_00872570::GetWindowLongA(MainLoopGlobals::g_osGlobals->window, -16);
                    AdjustWindowRectEx(&rectWindow, style, 0, 0);
                    fnv_00872570::SetWindowPos(MainLoopGlobals::g_osGlobals->window, 0, rectWindow.left, rectWindow.bottom,
                                 rectWindow.right - rectWindow.left, rectWindow.top - rectWindow.bottom, 0);
                }
            }
        }
    }
    else
    {
        if (DAT_011f941e)
            ImageSpaceEffectHDR_ClearAdaptedLight();
        if (MainLoopGlobals::DAT_011dea10->DetailedActorPathHandler_GetCurrentNodeIndex() && TESWaterSystem_GetWaterEnabled())
        {
            MainLoopGlobals::DAT_011dea10->DetailedActorPathHandler_GetCurrentNodeIndex()->ReleaseWaterResources(1, 0);
            MainLoopGlobals::DAT_011dea10->DetailedActorPathHandler_GetCurrentNodeIndex()->TESWaterSystem_EnableWaterSystem();
        }
    }
    return true;
}
}  // namespace fnv_00872570

#include <string.h>
namespace fnv_00a24830 {
struct DIGuid
{
    unsigned long Data1;
    unsigned short Data2, Data3;
    unsigned char Data4[8];
};
struct DIDEVICEOBJECTINSTANCEA;
struct DIDEVICEINSTANCEA
{
    unsigned long dwSize;
    DIGuid guidInstance, guidProduct;
    unsigned long dwDevType;
    char tszInstanceName[260], tszProductName[260];
    DIGuid guidFFDriver;
    unsigned short wUsagePage, wUsage;
};
struct DIDEVCAPS
{
    unsigned long dwSize, dwFlags, dwDevType, dwAxes, dwButtons, dwPOVs, dwFFSamplePeriod, dwFFMinTimeResolution,
        dwFirmwareRevision, dwHardwareRevision, dwFFDriverVersion;
};
struct IDirectInputDevice8A
{
    virtual long __stdcall Q();
    virtual long __stdcall A();
    virtual long __stdcall R();
    virtual long __stdcall GetCapabilities(DIDEVCAPS*);
    virtual long __stdcall EnumObjects(int(__stdcall*)(const DIDEVICEOBJECTINSTANCEA*, void*), void*, unsigned long);
    virtual long __stdcall GetProperty();
    virtual long __stdcall SetProperty();
    virtual long __stdcall Acquire();
    virtual long __stdcall Unacquire();
    virtual long __stdcall GetDeviceState();
    virtual long __stdcall GetDeviceData();
    virtual long __stdcall SetDataFormat(const void*);
    virtual long __stdcall SetEventNotification();
    virtual long __stdcall SetCooperativeLevel(void*, unsigned long);
};
struct IDirectInput8A
{
    virtual long __stdcall Q();
    virtual long __stdcall A();
    virtual long __stdcall R();
    virtual long __stdcall CreateDevice(const DIGuid&, IDirectInputDevice8A**, void*);
};
extern "C" __declspec(dllimport) void* __stdcall GetForegroundWindow();
extern const unsigned char DAT_01100ebc[];

void* _fnv_zlib_memset(void*, int, unsigned int);
int __stdcall MatchObjectGuids(const DIDEVICEOBJECTINSTANCEA*, void*);
struct JoystickCounts
{
    unsigned int axes, buttons;
};
struct InputOwner
{
    unsigned int unk00, unk04;
    IDirectInput8A* input;
    IDirectInputDevice8A* devices[8];
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    DIDEVICEINSTANCEA instances[8];
    DIDEVCAPS caps[8];
    JoystickCounts counters[8];
    unsigned int count;
    void Controls_SetDeviceRange(unsigned int, int, int);
    void Controls_SetDeviceDeadzone(unsigned int, float);
};
// Accepts instances whose low device type byte is 20 or 21, creates a device, queries capabilities and object counts, and stores it.
// @fnv 0x00a24830
// src: COMMUNITY 0x00a24830
int __stdcall DIEnumDevicesCallback(const DIDEVICEINSTANCEA* instance, void* context)
{
    InputOwner* manager = (InputOwner*)context;
    if ((unsigned char)(instance->dwDevType & 255) != 20 && (unsigned char)(instance->dwDevType & 255) != 21)
        return 1;
    DIDEVICEINSTANCEA* deviceOut = &manager->instances[manager->count];
    memcpy(deviceOut, instance, 0x244);
    IDirectInputDevice8A* saved;
    manager->input->CreateDevice(instance->guidInstance, &saved, 0);
    IDirectInputDevice8A* device = saved;
    device->SetCooperativeLevel(GetForegroundWindow(), 6);
    device->SetDataFormat(DAT_01100ebc);
    DIDEVCAPS* caps = &manager->caps[manager->count];
    _fnv_zlib_memset(caps, 0, 0x2c);
    manager->caps[manager->count].dwSize = 0x2c;
    device->GetCapabilities(&manager->caps[manager->count]);
    manager->counters[manager->count].axes = 0;
    manager->counters[manager->count].buttons = 0;
    device->EnumObjects(MatchObjectGuids, &manager->counters[manager->count], 0);
    manager->devices[manager->count] = device;
    manager->Controls_SetDeviceRange(manager->count, -100, 100);
    manager->Controls_SetDeviceDeadzone(manager->count, 0.1f);
    manager->count++;
    if (manager->count == 8)
        return 0;
    return 1;
}
}  // namespace fnv_00a24830

class BGSAcousticSpace;
namespace fnv_0086f940 {
// Required virtual interface: the pack leaves the update slot untyped.
class PlayerUpdate : public TESObjectREFR
{
  public:
    virtual void StartHighProcess(void);
    virtual void Unk_91(void);
    virtual void Unk_92(void);
    virtual void Unk_93(void);
    virtual void Unk_94(void);
    virtual void Unk_95(void);
    virtual void Unk_96(void);
    virtual void Unk_97(void);
    virtual void Unk_98(void);
    virtual void Unk_99(void);
    virtual void Unk_9A(float arg0);
    virtual void Unk_9B(void);
    virtual void Unk_9C(void);
    virtual void Unk_9D(void);
    virtual void Unk_9E(void);
    virtual void Unk_9F(void* arg0);
    virtual void Unk_A0(void);
    virtual void Unk_A1(void);
    virtual void Unk_A2(void);
    virtual void Unk_A3(void* arg0, bool arg1);
    virtual void Unk_A4(void);
    virtual void Unk_A5(void);
    virtual void Unk_A6(void);
    virtual void Unk_A7(void);
    virtual void Unk_A8(void);
    virtual void Unk_A9(void);
    virtual void Unk_AA(NiPoint3& arg0);
    virtual void Unk_AB(NiPoint3& result);
    virtual void Unk_AC(void);
    virtual void Unk_AD(void);
    virtual void Unk_AE(void);
    virtual float GetCurrentTargetDistance(bool ignoreImmobile);
    virtual void Unk_B0(void);
    virtual void SetFurnitureHeading(float heading);
    virtual TESObjectREFR* GetCurrentTarget();
    virtual void Unk_B3(void);
    virtual void Unk_B4(void);
    virtual void Unk_B5(void);
    virtual void Unk_B6(void);
    virtual void SetActorEssentialState(int value);
    virtual void Unk_B8(void);
    virtual void Unk_B9(void);
    virtual bool Unk_BA();
    virtual void Unk_BB(void);
    virtual void Unk_BC(void);
    virtual void Unk_BD(void);
    virtual void Unk_BE(float delta);
};
struct PlayerCalls
{
    bool PlayerCharacter_HandlePositionPlayerRequest();
    void PlayerCharacter_ForceGrenadeHold();
    void PlayerCharacter_UpdateFlyCamera(float delta, unsigned char mode);
    NiPoint3* GetAddTopicList();
    void PlayerCharacter_SetAcousticSpaceTransition(char value);
};
struct CellCalls
{
    bool IsInterior();
    bool FUN_00550200(const NiPoint3& position);
    TESWorldSpace* FUN_0054ddd0();
    bool TESObjectCELL_GetLoaded();
    bool TESObjectCELL_GetAttached();
    void AddReference(TESObjectREFR*, bool);
    BGSAcousticSpace* GetAcousticSpace();
};
struct DataHandlerCalls
{
    TESObjectCELL* FUN_00461bc0(float x, float y, TESWorldSpace*, bool);
};
struct Receiver86;
extern Receiver86* g_dataHandler;
class WorldUpdateCalls
{
  public:
    void FUN_00452580(const NiPoint3&, bool);
    bool TES_CellTestRunning();
    void TES_ShowLoadingMenu(int, int, int);
};
extern unsigned int _DAT_011dea10;
struct TimeGlobal
{
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
struct UpdateScale
{
    float FUN_009c8cc0();
};
extern UpdateScale DAT_011f2250;
extern unsigned char DAT_011e07a8;
bool Interface_IsPipboyOpening();
extern bool DAT_011dea2b;
void FalloutAudio_DisableRegionSoundUpdates(bool);
struct RenderManager
{
    void BSShaderAccumulator_ClearAllBoundVolumes();
};
RenderManager* BSShaderManager_GetAccumulator();
struct PlayerUpdateState
{
    unsigned int updateFlags;
    unsigned short updateState;
    bool specialUpdate;
    unsigned char updateMode;
    void Main_OnIdle_UpdatePlayer();
};

// Updates player state and may transfer the player to a destination cell when the current cell is exterior and a position check fails.
// @fnv 0x0086f940
// src: XBOX_PDB 0x0086f940
void PlayerUpdateState::Main_OnIdle_UpdatePlayer()
{
    bool bChanged;
    if (!reinterpret_cast<PlayerCalls*>(g_thePlayer)->PlayerCharacter_HandlePositionPlayerRequest())
    {
        if (DAT_011dea2b && !Interface_IsPipboyOpening())
        {
            reinterpret_cast<PlayerCalls*>(g_thePlayer)->PlayerCharacter_ForceGrenadeHold();
        }
        else if (specialUpdate)
        {
            if (g_thePlayer->GetNiNode())
            {
                reinterpret_cast<PlayerCalls*>(g_thePlayer)->PlayerCharacter_UpdateFlyCamera(g_timeGlobal.FUN_0084d030(), updateMode);
            }
        }
        else
        {
            if (g_thePlayer->GetNiNode())
            {
                ++DAT_011e07a8;
                reinterpret_cast<PlayerUpdate*>(g_thePlayer)
                    ->Unk_BE(g_timeGlobal.FUN_0084d030() * DAT_011f2250.FUN_009c8cc0());
                --DAT_011e07a8;
            }
            bChanged = false;
            TESObjectCELL* cell = g_thePlayer->GetParentCell();
            NiPoint3 position = *reinterpret_cast<PlayerCalls*>(g_thePlayer)->GetAddTopicList();
            if (cell && !reinterpret_cast<CellCalls*>(cell)->IsInterior() &&
                !reinterpret_cast<CellCalls*>(cell)->FUN_00550200(position))
            {
                TESObjectCELL* destination =
                    reinterpret_cast<DataHandlerCalls*>(g_dataHandler)
                        ->FUN_00461bc0(position.x, position.y, reinterpret_cast<CellCalls*>(cell)->FUN_0054ddd0(),
                                       true);
                if (destination)
                {
                    if (!reinterpret_cast<CellCalls*>(destination)->TESObjectCELL_GetLoaded() &&
                        !reinterpret_cast<CellCalls*>(destination)->TESObjectCELL_GetAttached())
                    {
                        reinterpret_cast<WorldUpdateCalls*>(_DAT_011dea10)->FUN_00452580(position, true);
                        if (reinterpret_cast<WorldUpdateCalls*>(_DAT_011dea10)->TES_CellTestRunning())
                        {
                            reinterpret_cast<WorldUpdateCalls*>(_DAT_011dea10)->TES_ShowLoadingMenu(0, 0, 0);
                        }
                    }
                    FalloutAudio_DisableRegionSoundUpdates(1);
                    reinterpret_cast<PlayerCalls*>(g_thePlayer)->PlayerCharacter_SetAcousticSpaceTransition(1);
                    reinterpret_cast<CellCalls*>(destination)->AddReference(g_thePlayer, false);
                    FalloutAudio_SetNextAcousticSpace(reinterpret_cast<CellCalls*>(destination)->GetAcousticSpace());
                    reinterpret_cast<PlayerCalls*>(g_thePlayer)->PlayerCharacter_SetAcousticSpaceTransition(0);
                    FalloutAudio_DisableRegionSoundUpdates(0);
                    RenderManager* manager = BSShaderManager_GetAccumulator();
                    if (manager)
                    {
                        manager->BSShaderAccumulator_ClearAllBoundVolumes();
                    }
                }
                bChanged = true;
            }
        }
    }
}
}  // namespace fnv_0086f940

namespace fnv_0086d590 {
using ::NiAVObject;
using ::AutoMemHelper;
void BSShaderManager_SetRenderer(NiNode*);
void BSShaderManager_SetSeparateAmbientLight(bool);
void BSShaderManager_SetSeparateSpecularColor(bool);
void BSShaderManager_SetObjectTypeCallback(unsigned int(__cdecl*)(::NiAVObject*));
void DistantLODShaderProperty_SetLODTreeParent(int);
void BGSTerrainManager_SetTreeNode(NiNode*);

using ::NiFixedString;
struct ResourceObject;
struct Resource
{
    ResourceObject* object;
    ResourceObject* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(void* item);
};
struct ResourceObject
{
    ResourceObject* FUN_006629f0();
    void FUN_00712e60(void*);
    void ShadowSceneNode_SetSceneGraphIndex(int);
    void BSShaderAccumulator_SetShadowSceneNode(void*);
    ResourceObject* BSSceneGraph_GetCameraRoot();
    void UpdateProperties();
    void NiAVObject_Update(void*);
    void AssignFixedString(const NiFixedString&);
    void BSMultiBoundNode_SetCullingMode(int);
    void FUN_005467c0(int);
    void NiAVObject_SetAlwaysDraw(int);
    void SetDepthParams(float);
    void NiAlphaProperty_SetAlphaBlending(int);
    void NiAVObject_AttachProperty(void*);
    void NiAVObject_SetTranslate_004bc1f0(float, float, float);
    void NiMaterialProperty_SetEmittance(void*);
    void SetBaseTexture(int);
    void FUN_0060aeb0(int);
    void FUN_004f3200(int);
    int BSRenderedTexture_GetTexture(int);
    void NiScreenElements_Insert(int, int, int);
    void NiScreenElements_SetRectangle(int, float, float, float, float);
    void NiScreenElements_UpdateBound();
    void NiScreenElements_SetTextures(int, int, float, float, float, float);
};
struct ModuleRoot
{
    virtual void virtual_00();
    virtual void virtual_04();
    virtual void virtual_08();
    virtual void virtual_0c();
    virtual void virtual_10();
    virtual void virtual_14();
    virtual void virtual_18();
    virtual void virtual_1c();
    virtual void virtual_20();
    virtual void virtual_24();
    virtual void virtual_28();
    virtual void virtual_2c();
    virtual void virtual_30();
    virtual void virtual_34();
    virtual void virtual_38();
    virtual void virtual_3c();
    virtual void virtual_40();
    virtual void virtual_44();
    virtual void virtual_48();
    virtual void virtual_4c();
    virtual void virtual_50();
    virtual void virtual_54();
    virtual void virtual_58();
    virtual void virtual_5c();
    virtual void virtual_60();
    virtual void virtual_64();
    virtual void virtual_68();
    virtual void virtual_6c();
    virtual void virtual_70();
    virtual void virtual_74();
    virtual void virtual_78();
    virtual void virtual_7c();
    virtual void virtual_80();
    virtual void virtual_84();
    virtual void virtual_88();
    virtual void virtual_8c();
    virtual void virtual_90();
    virtual void virtual_94();
    virtual void virtual_98();
    virtual void virtual_9c();
    virtual void virtual_a0();
    virtual void virtual_a4();
    virtual void virtual_a8();
    virtual void virtual_ac();
    virtual void virtual_b0();
    virtual void virtual_b4();
    virtual void virtual_b8();
    virtual void virtual_bc();
    virtual void virtual_c0();
    virtual void virtual_c4();
    virtual void virtual_c8();
    virtual void virtual_cc();
    virtual void virtual_d0();
    virtual void virtual_d4();
    virtual void virtual_d8();
    virtual void virtual_dc(void*, int);
    virtual void virtual_e0();
    virtual void virtual_e4();
    virtual void virtual_e8();
    virtual void virtual_ec();
    virtual void virtual_f0();
    virtual void virtual_f4();
    virtual void virtual_f8(int, void*);
};

struct SceneObject : ModuleRoot
{
    SceneObject* SceneGraph_SceneGraph(const char*, int, int);
    void NiScreenElements_SetRectangle(float, float, float, float, int);
};
struct DataObject : ModuleRoot
{
    DataObject* FUN_00b5e0f0();
    void NiTexturingProperty_Map_SetTexture(void*);
};
struct InputObject : ModuleRoot
{
    InputObject* FUN_00bb8180();
    InputObject* FUN_00c46970();
    InputObject* FUN_00a5ecb0(int);
    InputObject* FUN_00bc2980();
    InputObject* FUN_00c503d0();
    InputObject* FUN_00a87810(void*);
    InputObject* FUN_00a881e0(int, int, int, int, int, int, int, int, int);
    InputObject* Lighting30shaderproperty_StoreAndAddReference_00a75650();
    InputObject* FUN_00a6aa40();
    void BSMultiBoundNode_SetCullingMode(int);
    void NiAVObject_SetAlwaysDraw(int);
    void FUN_005467c0(int);
    void AssignFixedString(const NiFixedString&);
    void NiMaterialProperty_SetEmittance(void*);
    void SetBaseTexture(int);
    void FUN_0060aeb0(int);
    void FUN_004f3200(int);
    void SetDepthParams(float);
    void NiAlphaProperty_SetAlphaBlending(int);
    void NiScreenElements_Insert(int, int, int);
    void NiScreenElements_SetRectangle(int, float, float, float, float);
    void NiScreenElements_UpdateBound();
    void NiScreenElements_SetTextures(int, int, float, float, float, float);
};
struct RenderSystem
{
    void TESMain_InitSceneGraph();
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
    int unknown_10;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    int unknown_24;
    int unknown_28;
    int unknown_2c;
    int unknown_30;
    int unknown_34;
    int unknown_38;
    int unknown_3c;
    int unknown_40;
    int unknown_44;
    int unknown_48;
    int unknown_4c;
    int unknown_50;
    int unknown_54;
    int unknown_58;
    int unknown_5c;
    int unknown_60;
    int unknown_64;
    int unknown_68;
    int unknown_6c;
    int unknown_70;
    int unknown_74;
    int unknown_78;
    int unknown_7c;
    int unknown_80;
    int unknown_84;
    Resource resource88;
    Resource resource8c;
    Resource resource90;
    Resource resource94;
    Resource resource98;
};

extern Resource DAT_011deb7c;
extern Resource DAT_011deb00;
extern Resource DAT_011deb34;
extern Resource DAT_011deda4;
extern Resource DAT_011ded58;
extern Resource DAT_011dec94;
extern Resource DAT_011ded3c;
extern Resource DAT_011f95d8;
extern int DAT_011ad82c;
extern float DAT_011fd870;
extern float DAT_011ad808;
extern unsigned char DAT_011dea28;
extern InputObject* DAT_011dea14;
extern int DAT_011dea18;
extern int DAT_011dea1c;
extern const char str_010829c4[];
extern const char str_01082c9c[];
extern const char str_01082c8c[];
extern const char str_01082c88[];
extern const char str_01082c80[];
extern const char str_01082c78[];
extern const char str_01082c68[];
extern const char str_01082c5c[];
extern const char str_01082c50[];
extern const char str_01082c40[];
extern const char str_01082c28[];
extern float DAT_0101e704;
extern int DAT_011a9b7c;
extern int DAT_011ad840;
extern NiNode* Renderer_GetNIRenderer();
extern unsigned char TESRenderer_GetDoCanopyShadowPass();

extern void BSShaderManager_SetDefaultShaderPath(const char*);
extern void InitRenderSystem();
extern void BSShaderManager_SetShadowSceneNode(int, void*);
extern int FUN_00450b80(int);

extern bool Display_bDoAmbientPass_Get();
extern bool Display_bDoDiffusePass_Get();
extern bool Display_bDoTexturePass_Get();
extern bool Display_bDoSpecularPass_Get();
extern int FUN_004dc060(int);
extern void BSShaderManager_SetEnabledPasses(int);
extern bool TESRenderer_GetDoActorShadows();
extern bool TESRenderer_GetDoStaticAndArchShadows();
extern unsigned int TESObjectREFR_GetLightingObjectType(::NiAVObject*);
extern void FUN_00b55540(int, void*);
extern void TESMain_CreateMenuRootNode();
extern void FUN_004dc650();

extern void NiAVObject_SetTranslate_004bc1f0();
extern void* BSShaderManager_GetAccumulator();
extern unsigned char TESRenderer_GetDoStaticMenuBackground();
extern void UpdateTerrainLODMaxRange();
extern int BSRenderedTexture_GetTexture(int);
extern DataObject* NiXenonRenderer_GetRenderer();
extern void* __cdecl Object_DispatchCommandFour(unsigned int);
struct FUN_00b5e0f0 : NiMemObject
{
    FUN_00b5e0f0();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
    unsigned int unknown_b4;
    unsigned int unknown_b8;
    unsigned int unknown_bc;
    unsigned int unknown_c0;
    unsigned int unknown_c4;
    unsigned int unknown_c8;
    unsigned int unknown_cc;
    unsigned int unknown_d0;
    unsigned int unknown_d4;
    unsigned int unknown_d8;
    unsigned int unknown_dc;
    unsigned int unknown_e0;
    unsigned int unknown_e4;
    unsigned int unknown_e8;
    unsigned int unknown_ec;
    unsigned int unknown_f0;
    unsigned int unknown_f4;
    unsigned int unknown_f8;
    unsigned int unknown_fc;
    unsigned int unknown_100;
    unsigned int unknown_104;
    unsigned int unknown_108;
    unsigned int unknown_10c;
    unsigned int unknown_110;
    unsigned int unknown_114;
    unsigned int unknown_118;
    unsigned int unknown_11c;
    unsigned int unknown_120;
    unsigned int unknown_124;
    unsigned int unknown_128;
    unsigned int unknown_12c;
    unsigned int unknown_130;
    unsigned int unknown_134;
    unsigned int unknown_138;
    unsigned int unknown_13c;
    unsigned int unknown_140;
    unsigned int unknown_144;
    unsigned int unknown_148;
    unsigned int unknown_14c;
    unsigned int unknown_150;
    unsigned int unknown_154;
    unsigned int unknown_158;
    unsigned int unknown_15c;
    unsigned int unknown_160;
    unsigned int unknown_164;
    unsigned int unknown_168;
    unsigned int unknown_16c;
    unsigned int unknown_170;
    unsigned int unknown_174;
    unsigned int unknown_178;
    unsigned int unknown_17c;
    unsigned int unknown_180;
    unsigned int unknown_184;
    unsigned int unknown_188;
    unsigned int unknown_18c;
    unsigned int unknown_190;
    unsigned int unknown_194;
    unsigned int unknown_198;
    unsigned int unknown_19c;
    unsigned int unknown_1a0;
    unsigned int unknown_1a4;
    unsigned int unknown_1a8;
    unsigned int unknown_1ac;
    unsigned int unknown_1b0;
    unsigned int unknown_1b4;
    unsigned int unknown_1b8;
    unsigned int unknown_1bc;
    unsigned int unknown_1c0;
    unsigned int unknown_1c4;
    unsigned int unknown_1c8;
    unsigned int unknown_1cc;
    unsigned int unknown_1d0;
    unsigned int unknown_1d4;
    unsigned int unknown_1d8;
    unsigned int unknown_1dc;
    unsigned int unknown_1e0;
    unsigned int unknown_1e4;
    unsigned int unknown_1e8;
    unsigned int unknown_1ec;
    unsigned int unknown_1f0;
    unsigned int unknown_1f4;
    unsigned int unknown_1f8;
    unsigned int unknown_1fc;
};
struct FUN_00c46970 : NiMemObject
{
    FUN_00c46970();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
};
struct FUN_00a5ecb0 : NiMemObject
{
    FUN_00a5ecb0(unsigned int);
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
};
struct FUN_00bc2980 : NiMemObject
{
    FUN_00bc2980();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
    unsigned int unknown_b4;
};
struct FUN_00c503d0 : NiMemObject
{
    FUN_00c503d0();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
    unsigned int unknown_b4;
};
struct FUN_00a87810 : NiMemObject
{
    FUN_00a87810(void*);
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
    unsigned int unknown_b4;
    unsigned int unknown_b8;
    unsigned int unknown_bc;
    unsigned int unknown_c0;
};
struct FUN_00a881e0 : NiMemObject
{
    FUN_00a881e0(int, int, int, int, int, int, int, int, int);
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
};
struct FUN_00a75650 : NiMemObject
{
    FUN_00a75650();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
};
struct FUN_00a6aa40 : NiMemObject
{
    FUN_00a6aa40();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
};
using ::NiUpdateData;
using ::Setting;
extern Setting DAT_011dedc8;
extern const char str_0101fe78[];
// Creates a SceneGraph, associates resources and input objects, configures render state, and initializes additional scene objects.
// @fnv 0x0086d590
// src: COMMUNITY 0x0086d590
void RenderSystem::TESMain_InitSceneGraph()
{
    // Memory context, scene root, and graph construction.
    AutoMemHelper h(25, 1, str_010829c4, 0xf4c);
    DAT_011deb7c.FUN_0066b0d0(new SceneGraph(str_01082c9c, false, 0));

    DataObject* p = (DataObject*)new FUN_00b5e0f0;
    (BSShaderManager_SetRenderer)(Renderer_GetNIRenderer());
    BSShaderManager_SetDefaultShaderPath(str_01082c8c);
    InitRenderSystem();
    DAT_011deb7c.Modelloader_GetReferencedThis()->FUN_006629f0()->FUN_00712e60(&DAT_011ad840);
    ((ResourceObject*)p)->ShadowSceneNode_SetSceneGraphIndex(0);
    BSShaderManager_SetShadowSceneNode(0, p);
    this->resource88.Modelloader_GetReferencedThis()->BSShaderAccumulator_SetShadowSceneNode(p);
    this->resource8c.Modelloader_GetReferencedThis()->BSShaderAccumulator_SetShadowSceneNode(p);
    this->resource90.Modelloader_GetReferencedThis()->BSShaderAccumulator_SetShadowSceneNode(p);
    this->resource94.Modelloader_GetReferencedThis()->BSShaderAccumulator_SetShadowSceneNode(p);
    this->resource98.Modelloader_GetReferencedThis()->BSShaderAccumulator_SetShadowSceneNode((void*)FUN_00450b80(1));
    BSShaderManager_SetSeparateAmbientLight(0);
    BSShaderManager_SetSeparateSpecularColor(0);
    unsigned int f = (Display_bDoAmbientPass_Get() == 1 ? 1u : 0u);
    f |= (Display_bDoDiffusePass_Get() == 1 ? 2u : 0u);
    f |= (Display_bDoTexturePass_Get() == 1 ? 4u : 0u);
    f |= (Display_bDoSpecularPass_Get() == 1 ? 8u : 0u);
    f |= 0x10;
    f |= (TESRenderer_GetDoCanopyShadowPass() && FUN_004dc060(0) >= 2) ? 0x20 : 0;
    BSShaderManager_SetEnabledPasses(f);
    unsigned int eb = TESRenderer_GetDoActorShadows() ? 8 : 0;
    eb |= TESRenderer_GetDoStaticAndArchShadows() ? 2 : 0;
    DAT_011ad82c = eb;
    (BSShaderManager_SetObjectTypeCallback)(TESObjectREFR_GetLightingObjectType);  // parenthesized: no argument-dependent lookup of the global overload
    DAT_011fd870 = 0.0f;
    DAT_011f95d8.FUN_0066b0d0(DAT_011deb7c.Modelloader_GetReferencedThis()->FUN_006629f0());
    ((ModuleRoot*)DAT_011deb7c.Modelloader_GetReferencedThis())->virtual_dc(p, 1);

    DAT_011deb00.FUN_0066b0d0((InputObject*)new BSFogProperty());
    DAT_011deb00.Modelloader_GetReferencedThis()->NiAlphaProperty_SetAlphaBlending(1);
    DAT_011deb00.Modelloader_GetReferencedThis()->SetDepthParams(1.0f);
    FUN_00b55540(0, DAT_011deb00.Modelloader_GetReferencedThis());

    DAT_011deb34.FUN_0066b0d0((InputObject*)new FUN_00c46970());
    DAT_011deb34.Modelloader_GetReferencedThis()->BSMultiBoundNode_SetCullingMode(1);
    DAT_011deb34.Modelloader_GetReferencedThis()->FUN_005467c0(1);
    DAT_011deb34.Modelloader_GetReferencedThis()->AssignFixedString(NiFixedString(str_01082c88));
    p->virtual_f8(0, DAT_011deb34.Modelloader_GetReferencedThis());

    DAT_011deda4.FUN_0066b0d0((InputObject*)new FUN_00a5ecb0(0));
    DAT_011deda4.Modelloader_GetReferencedThis()->NiAVObject_SetAlwaysDraw(1);
    DAT_011deda4.Modelloader_GetReferencedThis()->FUN_005467c0(1);
    DAT_011deda4.Modelloader_GetReferencedThis()->AssignFixedString(NiFixedString(str_0101fe78));
    p->virtual_f8(1, DAT_011deda4.Modelloader_GetReferencedThis());
    TESMain_CreateMenuRootNode();
    FUN_004dc650();

    DAT_011dea14 = (InputObject*)new FUN_00bc2980();
    DAT_011dea14->AssignFixedString(NiFixedString(str_01082c80));
    p->virtual_f8(2, DAT_011dea14);

    // s is the active scene parent; a is its tree child.
    InputObject* s = (InputObject*)new FUN_00a5ecb0(0);
    s->NiAVObject_SetAlwaysDraw(1);
    s->FUN_005467c0(1);
    s->AssignFixedString(NiFixedString(str_01082c78));
    DAT_011dea14->virtual_dc(s, 1);

    DAT_011ad808 = *DAT_011dedc8.Setting_Float_00403e20();
    s = (InputObject*)new FUN_00a5ecb0(0);
    s->NiAVObject_SetAlwaysDraw(1);
    s->FUN_005467c0(1);
    s->AssignFixedString(NiFixedString(str_01082c68));
    DAT_011dea14->virtual_dc(s, 1);

    DAT_011dea1c = (int)(InputObject*)new FUN_00a5ecb0(0);
    ((InputObject*)DAT_011dea1c)->NiAVObject_SetAlwaysDraw(1);
    ((InputObject*)DAT_011dea1c)->FUN_005467c0(1);
    ((InputObject*)DAT_011dea1c)->AssignFixedString(NiFixedString(str_01082c5c));
    DAT_011dea14->virtual_dc((InputObject*)DAT_011dea1c, 1);

    InputObject* a = (InputObject*)new FUN_00a5ecb0(0);
    a->NiAVObject_SetAlwaysDraw(1);
    a->FUN_005467c0(1);
    a->AssignFixedString(NiFixedString(str_01082c50));
    s->virtual_dc(a, 1);
    DistantLODShaderProperty_SetLODTreeParent((int)a);
    (BGSTerrainManager_SetTreeNode)((NiNode*)a);

    DAT_011dea18 = (int)(InputObject*)new FUN_00a5ecb0(0);
    ((InputObject*)DAT_011dea18)->NiAVObject_SetAlwaysDraw(1);
    ((InputObject*)DAT_011dea18)->FUN_005467c0(1);
    ((InputObject*)DAT_011dea18)->AssignFixedString(NiFixedString(str_01082c40));
    p->virtual_f8(3, ((InputObject*)DAT_011dea18));

    DAT_011ded58.FUN_0066b0d0((InputObject*)new FUN_00c503d0());
    DAT_011ded58.Modelloader_GetReferencedThis()->AssignFixedString(NiFixedString(str_01082c28));
    p->virtual_f8(5, DAT_011ded58.Modelloader_GetReferencedThis());

    DAT_011deb7c.Modelloader_GetReferencedThis()->BSSceneGraph_GetCameraRoot()->NiAVObject_SetTranslate_004bc1f0(0.0f, 0.0f, DAT_0101e704);
    DAT_011deb7c.Modelloader_GetReferencedThis()->UpdateProperties();
    NiUpdateData i(0.0f, false, false);
    DAT_011deb7c.Modelloader_GetReferencedThis()->NiAVObject_Update(&i);
    NiXenonRenderer_GetRenderer()->NiTexturingProperty_Map_SetTexture(BSShaderManager_GetAccumulator());
    DAT_011dea28 = TESRenderer_GetDoStaticMenuBackground();

    if (!DAT_011dec94.Modelloader_GetReferencedThis())
    {
        DAT_011dec94.FUN_0066b0d0((InputObject*)new FUN_00a87810(new FUN_00a881e0(0, 0, 1, 1, 1, 4, 1, 2, 1)));
        DAT_011dec94.Modelloader_GetReferencedThis()->NiScreenElements_Insert(4, 0, 0);
        DAT_011dec94.Modelloader_GetReferencedThis()->NiScreenElements_SetRectangle(0, 0.0f, 0.0f, 1.0f, 1.0f);
        DAT_011dec94.Modelloader_GetReferencedThis()->NiScreenElements_UpdateBound();
        DAT_011dec94.Modelloader_GetReferencedThis()->NiScreenElements_SetTextures(0, 0, 0.0f, 0.0f, 1.0f, 1.0f);
        InputObject* p = (InputObject*)new FUN_00a75650();
        p->NiMaterialProperty_SetEmittance((void*)&DAT_011a9b7c);
        DAT_011dec94.Modelloader_GetReferencedThis()->NiAVObject_AttachProperty(p);
        InputObject* h = (InputObject*)new FUN_00a6aa40();
        h->SetBaseTexture(DAT_011ded3c.Modelloader_GetReferencedThis()->BSRenderedTexture_GetTexture(0));
        h->FUN_0060aeb0(0);
        h->FUN_004f3200(0);
        DAT_011dec94.Modelloader_GetReferencedThis()->NiAVObject_AttachProperty(h);
        DAT_011dec94.Modelloader_GetReferencedThis()->UpdateProperties();
        NiUpdateData i(0.0f, false, false);
        DAT_011dec94.Modelloader_GetReferencedThis()->NiAVObject_Update(&i);
    }
    UpdateTerrainLODMaxRange();
}
}  // namespace fnv_0086d590

struct S00875bf0_Cam875;
S00875bf0_Cam875* __fastcall MenuCamera_008b6200(::FORenderedMenu*);
struct S00875bf0_Cam875
{
    void FUN_00712e60(const NiColorA&);
};
// The shared culler has no declaration for the out-of-line cull-mode restore.
void __fastcall RestoreCullMode(::BSCullingProcess*);
struct S00875bf0_Face875
{
    ::BSCullingProcess* FUN_008d80e0();
};
using ::FORenderedMenu;
FORenderedMenu* Interface_GetCurrentRenderedMenu();
FORenderedMenu* Interface_GetPipboy();
struct S00875bf0_Ptr875
{
    void* Modelloader_GetReferencedThis();
};
extern unsigned char DAT_011f9426;
extern NiColorA DAT_011ad840;
void BSShaderUtil_AccumulateScene(S00875bf0_Cam875*, void*, ::BSCullingProcess*);
void BSRenderState_SetZWriteEnable(unsigned int, unsigned int);
void FUN_00b98380(int, int);
void FUN_00b6c0d0(S00875bf0_Cam875*, void*, int);
void BSRenderState_RestoreColorWriteEnable(unsigned int);
void BSRenderState_RestoreZWriteEnable(int);
using ::ShadowSceneNode;
struct S00875bf0_Shell875
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    S00875bf0_Ptr875 scene;
    void TESMain_DrawWorld_RenderedMenuScene();
};
// Sets up the face scene and camera, invokes rendering calls with the target scene, and restores the scene state.
// @fnv 0x00875bf0
// src: COMMUNITY 0x00875bf0
void S00875bf0_Shell875::TESMain_DrawWorld_RenderedMenuScene()
{
    if (!g_011deb38.Modelloader_GetReferencedThis() && Interface_GetCurrentRenderedMenu() && Interface_GetCurrentRenderedMenu() != Interface_GetPipboy())
    {
        ::BSFaceGenNiNode* face = (::BSFaceGenNiNode*)Main_GetWorldSceneGraph();
        ::BSCullingProcess* scene = ((S00875bf0_Face875*)face)->FUN_008d80e0();
        scene->SetCullMode(1);
        S00875bf0_Cam875* camera = MenuCamera_008b6200(Interface_GetCurrentRenderedMenu()) ? MenuCamera_008b6200(Interface_GetCurrentRenderedMenu())
                                                                  : (S00875bf0_Cam875*)face->::BSFaceGenNiNode::GetAnimationData();
        scene->SetCamera(camera);
        scene->SetAccumulator((::MenuTarget*)this->scene.Modelloader_GetReferencedThis());
        ((::BSShaderAccumulator*)this->scene.Modelloader_GetReferencedThis())->BSShaderAccumulator_SetShadowSceneNode(FUN_00450b80(0));
        if (DAT_011f9426 &&
            (!reinterpret_cast< ::NiDX9Renderer*>(NiXenonRenderer_GetRenderer())->GetCurrentRT() ||
             reinterpret_cast< ::NiDX9Renderer*>(NiXenonRenderer_GetRenderer())->GetCurrentRT() == reinterpret_cast< ::NiDX9Renderer*>(NiXenonRenderer_GetRenderer())->GetDefaultRT()))
            camera->FUN_00712e60(DAT_011ad840);
        else
            camera->FUN_00712e60(NiColorA(0.0f, 1.0f, 1.0f, 0.0f));
        BSShaderUtil_AccumulateScene(camera, Interface_GetCurrentRenderedMenu()->v2(), scene);
        ::BSShaderManager::SetRenderMode(15);
        BSRenderState_SetZWriteEnable(0, 1);
        FUN_00b98380(8, 1);
        FUN_00b6c0d0(camera, this->scene.Modelloader_GetReferencedThis(), 0);
        ::BSShaderManager::SetRenderMode(0);
        BSRenderState_RestoreColorWriteEnable(1);
        BSRenderState_RestoreZWriteEnable(1);
        BSShaderUtil_AccumulateScene(camera, Interface_GetCurrentRenderedMenu()->v2(), scene);
        FUN_00b6c0d0(camera, this->scene.Modelloader_GetReferencedThis(), 0);
        scene->SetAccumulator((::MenuTarget*)0);
        RestoreCullMode(scene);
    }
}
