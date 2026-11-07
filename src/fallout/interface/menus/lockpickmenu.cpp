#include "../../../../include/NiColorA.h"
#include "../../../../include/LockPickMenu.h"
#include "../../../../include/ActorValueOwner.h"
#include "../../../../include/Tile.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiSortAdjustNode.h"
#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/OSGlobals.h"
#include "../../../../include/Setting.h"
#include "../../../../include/StrMem.h"

// BSAudio still declares its legacy handle return type; use the shared handle
// with the same return ABI until that declaration is migrated.
typedef BSSoundHandle (BSAudio::*SoundHandleByEditorID)(const char*, unsigned int);

// src/fallout/interface/menus/lockpickmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/lockpickmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x0078da90
// src: COMMUNITY 0x0078da90
int LockPickMenu::GetClass_0078da90()
{
    return 0x3f6;
}

// Stores tile into the menu's tile array at index id when id is in [0,16).
// @fnv 0x0078daa0
void LockPickMenu::SetTile(int id, Tile* tile)
{
    if (id >= 0 && id < 16)
    {
        m_pTiles[id] = tile;
    }
}

// @fnv 0x0078e080
// src: XBOX_PDB 0x0078e080
int LockPickMenu_GetClassStatic()
{
    return 1014;
}

void __fastcall FUN_0078e0f0(void*);
void __cdecl _Deallocate(void*);
// Calls FUN_0078e0f0 on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0078dad0
void* LockPickMenu::FUN_0078dad0(unsigned int flags)
{
    FUN_0078e0f0(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Proc_S
{
    void* GetNext();
};
void* __cdecl InterfaceManager_GetSingleton();
// If aiID is 13, gets the next entry from FUN_004b7210 and calls Set(0xfa9, 0.0f, true) on it as a Tile.
// @fnv 0x007902b0
// src: XBOX_PDB 0x007902b0
void LockPickMenu::DoEnter_007902b0(int aiID, Tile* apTarget)
{
    if (aiID == 13)
    {
        reinterpret_cast<Tile*>(reinterpret_cast<Proc_S*>(InterfaceManager_GetSingleton())->GetNext())->Set(0xfa9, 0.0f, true);
    }
}

namespace fnv_007902f0 {
struct Proc_S
{
    void* GetNext();
};
void* __cdecl InterfaceManager_GetSingleton();
}  // namespace fnv_007902f0

// If aiID equals 0xD, gets the next object from FUN_004b7210 and calls Set(0xFA9, 255.0f, true) on it as a Tile.
// @fnv 0x007902f0
// src: XBOX_PDB 0x007902f0
void LockPickMenu::DoLeave_007902f0(int aiID, Tile* apTarget)
{
    if (aiID == 0xD)
    {
        ((Tile*)((fnv_007902f0::Proc_S*)fnv_007902f0::InterfaceManager_GetSingleton())->GetNext())->Set(0xFA9, 255.0f, true);
    }
}

struct ObjectRef
{
    NiAVObject* FUN_0043b4a0();
};
struct Manager
{
    ObjectRef* Modelloader_GetReferencedThis(int);
};
extern Manager DAT_011da24c;
// Rotates the lock object by an angle derived from amount and tile->FUN_00a011b0(0xfb1), then applies the rotation and position and updates it.
// @fnv 0x00790df0
void LockPickMenu::UpdateLockRotation(float amount)
{
    NiAVObject* object;
    {
        NiMatrix3 matrix;
        object = DAT_011da24c.Modelloader_GetReferencedThis(1)->FUN_0043b4a0();
        NiUpdateData kUpdateData(0.0f, false, false);
        NiPoint3 offset = position.GetNegatedVector().FUN_00439e90(NiPoint3(0.0f, 0.0f, 0.6f));
        matrix.MakeYRotation((float)((amount / m_64->FUN_00a011b0(0xfb1) * -180.0 + 90.0) * 0.01745329238474369));
        object->NiAVObject_SetTranslate(position.FUN_00439e90(offset).SubtractIntoVector(matrix.operator*(offset)));
        matrix = matrix.operator*(rotation);
        object->SetRotate_0043fa80(matrix);
        object->Update(kUpdateData);
    }
}

namespace fnv_00790f40 {

struct NiNodePointer
{
    NiNode* m_pObject;
    NiNode* GetObject();
};

extern NiNodePointer g_011da24c;

struct Sequence
{
    float GetStartTime(int aiIndex);
    float GetEndTime();
    float GetCurrentTime();
    void SetTime(float afTime);
};
}  // namespace fnv_00790f40

// @fnv 0x00790f40
void LockPickMenu::AdvanceSequence(float afDelta)
{
    using namespace fnv_00790f40;
    float fSequenceTimeRatio = (float)((m_8c + afDelta) / 90.0);
    NiUpdateData kData(0.0f, true, false);
    if (m_a0)
    {
        reinterpret_cast<Sequence*>(m_a0)->SetTime((float)(reinterpret_cast<Sequence*>(m_a0)->GetStartTime(0) +
                                     (reinterpret_cast<Sequence*>(m_a0)->GetEndTime() - reinterpret_cast<Sequence*>(m_a0)->GetCurrentTime()) * fSequenceTimeRatio));
        g_011da24c.GetObject()->GetAt(0)->Update(kData);
    }
}

extern char DAT_011da224;
extern float DAT_01030ff4;

struct SingletonGetter
{
    void* Modelloader_GetReferencedThis();
};

struct ProcBase
{
    void RendererClearBufferHook();
};

struct ObjB
{
    void* FUN_008d80e0();
    void* FUN_006629f0();
};

struct ObjC
{
    void BSCullingProcess_PushCullMode(int);
    void BSCullingProcess_PopCullMode();
    void BSCullingProcess_SetAccumulator(void*);
};

struct ObjD
{
    void* RaceSexMenu_GetProjectorFile();
};

struct Guard : SingletonGetter
{
    int unk00;

    Guard(void* p);
    ~Guard();
    void FUN_0066b0d0(int);
};

void* __stdcall NiXenonRenderer_GetRenderer(int, int);
void* __cdecl Main_GetWorldSceneGraph();
void* __cdecl InterfaceManager_GetSingleton();
int __cdecl FUN_00450b80(int);
void __cdecl UpdateCameraFrustum(void*, float);
void __cdecl BSShaderUtil_AccumulateScene(void*, int, void*);
void __cdecl FUN_00b6c0d0(void*, void*, int);

// @fnv 0x0078e7c0
// src: COMMUNITY 0x0078e7c0
void __cdecl LockPickMenu_DrawScene()
{
    void* v6;
    void* v14;
    void* v18;
    void* v1c3;
    void* v24;

    if (reinterpret_cast<SingletonGetter*>(&DAT_011da24c)->Modelloader_GetReferencedThis() == 0)
    {
        return;
    }
    reinterpret_cast<ProcBase*>(NiXenonRenderer_GetRenderer(0, 4))->RendererClearBufferHook();
    v6 = Main_GetWorldSceneGraph();
    v1c3 = reinterpret_cast<ObjB*>(v6)->FUN_008d80e0();
    reinterpret_cast<ObjC*>(v1c3)->BSCullingProcess_PushCullMode(1);
    v18 = reinterpret_cast<SingletonGetter*>(&DAT_011da224)->Modelloader_GetReferencedThis();
    UpdateCameraFrustum(v18, DAT_01030ff4);
    Guard g(reinterpret_cast<ObjD*>(InterfaceManager_GetSingleton())->RaceSexMenu_GetProjectorFile());
    reinterpret_cast<ObjC*>(v1c3)->BSCullingProcess_SetAccumulator(g.Modelloader_GetReferencedThis());
    if (v18 != 0)
    {
        v24 = v18;
    }
    else
    {
        v24 = reinterpret_cast<ObjB*>(v6)->FUN_006629f0();
    }
    v14 = v24;
    BSShaderUtil_AccumulateScene(v14, FUN_00450b80(1), v1c3);
    FUN_00b6c0d0(v14, g.Modelloader_GetReferencedThis(), 0);
    reinterpret_cast<ObjC*>(v1c3)->BSCullingProcess_SetAccumulator(0);
    g.FUN_0066b0d0(0);
    reinterpret_cast<ObjC*>(v1c3)->BSCullingProcess_PopCullMode();
}

namespace fnv_0078e900 {
// Stand-in types are named after the game function whose constructor they wrap.
struct FUN_00414430
{  // 4-float rectangle (viewport)
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    FUN_00414430(float, float, float, float);
};
struct FUN_00a71b70
{  // frustum: four edges, near, far, orthographic flag
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    bool unk18;
    FUN_00a71b70(int);
};
struct FUN_0043d410
{  // small 12-byte value object
    float unk00;
    int unk04;
    int unk08;
    FUN_0043d410(float, int, int);
};
struct Renderer
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual float vf64();  // vtable slot 0x100: returns the far-plane distance
};
struct FUN_00aa13e0
{  // allocator base: supplies the class operator new
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_00a712f0 : FUN_00aa13e0
{  // camera object, size 0x114
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
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    FUN_00a712f0();
    void FUN_00712e60(FUN_00414430*);
    void NiCamera_SetMaxFarNearRatio(float);
    void FUN_00a6faf0(FUN_00a71b70*);
    void SetLookAt(const NiPoint3&, const NiPoint3&);
    void NiCamera_SetMinNearPlaneDist(float);
    void NiAVObject_Update(FUN_0043d410*);
};
Renderer* Main_GetWorldSceneGraph();
int Renderer_GetScreenHeight();
int Renderer_GetScreenWidth();
float __cdecl tan_0057dd70(float);
extern Setting DAT_01203144;
extern Setting DAT_01203150;
extern bool DAT_011f9426;
extern int DAT_011f9434;
extern float DAT_01016264;
extern double DAT_01023128;
extern double DAT_01070c80;
}  // namespace fnv_0078e900

// Builds a camera: viewport, frustum from a field-of-view setting and the
// screen aspect ratio, far/near ratio, and a default orientation.
// Local names are chosen only to reproduce the original stack layout:
//   b = camera, f = viewport rect, c = frustum, g = aspect ratio,
//   d = frustum scale, e = view angle, a = trailing value object.
// @fnv 0x0078e900
// src: COMMUNITY 0x0078e900
void* LockPickMenu::Create3DCamera()
{
    using namespace fnv_0078e900;
    float g;
    FUN_00a712f0* b = new FUN_00a712f0;
    FUN_00414430 f(0.0f, 1.0f, 1.0f, 0.0f);
    float d;
    b->FUN_00712e60(&f);
    FUN_00a71b70 c(0);
    float e;
    c.unk14 = fnv_0078e900::Main_GetWorldSceneGraph()->vf64();
    c.unk10 = *DAT_01203144.Setting_Float_00403e20();
    b->NiCamera_SetMaxFarNearRatio(c.unk14 / c.unk10);
    g = (double)(DAT_011f9426 ? DAT_011f9434 : Renderer_GetScreenHeight()) / Renderer_GetScreenWidth();
    d = DAT_01016264;
    e = *DAT_01203150.Setting_Float_00403e20() * DAT_01023128 * DAT_01070c80;
    c.unk00 = -tan_0057dd70(e) * d;
    c.unk04 = tan_0057dd70(e) * d;
    c.unk0c = -tan_0057dd70(e) * g * d;
    c.unk08 = tan_0057dd70(e) * g * d;
    c.unk18 = false;
    b->FUN_00a6faf0(&c);
    b->SetLookAt(NiPoint3(0.0f, 0.0f, 1.0f), NiPoint3(0.0f, 0.0f, 1.0f));
    b->NiCamera_SetMinNearPlaneDist(1.0f);
    FUN_0043d410 a(0.0f, 0, 0);
    b->NiAVObject_Update(&a);
    return b;
}

unsigned char __cdecl Interface_Has360Controller();

// @fnv 0x00790290
// src: XBOX_PDB 0x00790290
int __cdecl LockPickMenu_GetTutorialMessageID()
{
    return ((Interface_Has360Controller() != 0 ? -1 : 0) & 8) + 0x14;
}

int __cdecl BSStringT_char_SPrintF(StrMem* pkStr, const char* pFormat, ...);

struct LockAnimNode
{
    int* Setting_Int();
    void ProcessAndReturnValue_0045ce80(int aiValue);
};
extern LockAnimNode* g_apLockNodes0_011a0328[5];
extern LockAnimNode* g_apLockNodes1_011a033c[5];
extern LockAnimNode* g_apLockNodes2_011a0350[5];
extern LockAnimNode* g_apLockNodes3_011a0364[5];

struct PathingActorState
{
    int unk00, unk04, unk08;
    int iBreakCount;
};
struct LockRef
{
    PathingActorState* TESObjectREFR_GetLock();
    void TESObjectREFR_AddLockChange();
};

struct PlayerStandIn
{
    char pad00[0xa4];
    ActorValueOwner kAVOwner;
};
extern PlayerStandIn* g_player_011dea3c;

struct RNG
{
    unsigned int FUN_00aa5230(unsigned int auiMax);
};
RNG* __cdecl FUN_00476c00();
void __cdecl FUN_005e58f0(int aiEntryPoint, PlayerStandIn* apActor, float* apValue);
int __cdecl GamePlayFormulas_GetForceLockChance(int aiSkill, int aiLockLevel);
struct StringSetting
{
    const char* FUN_00403df0();
};
extern StringSetting g_setting_011d3e98;
void __cdecl DispatchMessageToSink(const char* apText, int a2, const char* apIcon, const char* apSound, float afTime,
                                   int a6);
void __cdecl LockPickMenu_Close();
float __cdecl BSMIN(float afA, float afB);
float __cdecl BSMAX_00404010(float afA, float afB);

extern int g_aiLockLevels_011da28c[6];
extern int g_iPickAngle_011da208;
extern int g_iDriverAngle_011da20c;

static const char s_szLockBroken[] = "LOCK BROKEN!  :(";
static const char s_szForceFailIcon[] = "Interface\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds";
static const char s_szForceFailSound[] = "UILockpickingForceFail";
static const char s_szIntFormat[] = "%d";
extern const char g_szLockPickEnd[] = "";

// These call sites supply the getter's legacy flag argument.
typedef float (Tile::*TileFloatGetter)(int);
typedef float (Tile::*TileFloatGetterWithFlag)(int, bool);

// @fnv 0x00790330
void LockPickMenu::HandleLockPickAction(int aiCode, int aiUnused)
{
    int iStep = 5;
    switch (aiCode)
    {
    case 10:
        LockPickMenu_Close();
        break;
    case 9: {
        float fPerk = 0.0f;
        FUN_005e58f0(0x20, g_player_011dea3c, &fPerk);
        if (FUN_00476c00()->FUN_00aa5230(100) <
            (unsigned int)GamePlayFormulas_GetForceLockChance(g_player_011dea3c->kAVOwner.GetActorValueAsInteger(0x24), g_aiLockLevels_011da28c[m_70]))
        {
            m_98 = 1;
            m_90 = 90.0f;
            m_28 = 3;
        }
        else if (!m_6c && fPerk == 0.0)
        {
            m_58->Tile_Set_00a01350(0xfc4, s_szLockBroken, true);
            m_58->FUN_00700320(0xfa3, 1);
            m_28 = 6;
        }
        else
        {
            reinterpret_cast<LockRef*>(m_6c)->TESObjectREFR_GetLock()->iBreakCount++;
            reinterpret_cast<LockRef*>(m_6c)->TESObjectREFR_AddLockChange();
            DispatchMessageToSink(g_setting_011d3e98.FUN_00403df0(), 0, s_szForceFailIcon, s_szForceFailSound, 2.0f, 0);
            LockPickMenu_Close();
        }
        break;
    }
    case 3:
    case 5: {
        int m_eRange = g_aiLockLevels_011da28c[m_70 + 1] - g_aiLockLevels_011da28c[m_70];
        float fT =
            BSMAX_00404010(BSMIN((float)(m_74 - g_aiLockLevels_011da28c[m_70]) / (m_eRange * 2.0f), 1.0f), 0.0f);
        int iDelta = (aiCode != 5 ? 1 : -1) * iStep;
        StrMem kStr;
        g_iPickAngle_011da208 += iDelta;
        m_88 += iDelta / 2;
        BSStringT_char_SPrintF(&kStr, s_szIntFormat, g_iPickAngle_011da208);
        unk3c->Tile_Set_00a01350(0xfc4, kStr.Modelloader_GetReferencedThis(), true);
        g_apLockNodes0_011a0328[m_70]->ProcessAndReturnValue_0045ce80(*g_apLockNodes0_011a0328[m_70]->Setting_Int() +
                                                     (int)(iDelta * (1.0f - fT)));
        g_apLockNodes1_011a033c[m_70]->ProcessAndReturnValue_0045ce80(*g_apLockNodes1_011a033c[m_70]->Setting_Int() +
                                                     (int)(iDelta * fT));
        for (int i = 0; i < 6; i++)
        {
            Tile* pTile = m_64->Tile_GetChildByID(i + 0x11);
            pTile->Tile_Set(0xfb1, (pTile->*reinterpret_cast<TileFloatGetterWithFlag>(static_cast<TileFloatGetter>(&Tile::FUN_00a011b0)))(0xfb1, true) + iDelta);
            pTile->Tile_Set(0xfa1, (pTile->*reinterpret_cast<TileFloatGetterWithFlag>(static_cast<TileFloatGetter>(&Tile::FUN_00a011b0)))(0xfa1, true) - iDelta / 2);
        }
        break;
    }
    case 6:
    case 8: {
        int iRange7 = g_aiLockLevels_011da28c[m_70 + 1] - g_aiLockLevels_011da28c[m_70];
        float fT2_2 =
            BSMAX_00404010(BSMIN((float)(m_74 - g_aiLockLevels_011da28c[m_70]) / (iRange7 * 2.0f), 1.0f), 0.0f);
        int iDeltaX = (aiCode != 8 ? 1 : -1) * iStep;
        StrMem kStrTmp;
        g_iDriverAngle_011da20c += iDeltaX;
        m_88 += iDeltaX;
        BSStringT_char_SPrintF(&kStrTmp, s_szIntFormat, g_iDriverAngle_011da20c);
        unk48->Tile_Set_00a01350(0xfc4, kStrTmp.Modelloader_GetReferencedThis(), true);
        g_apLockNodes2_011a0350[m_70]->ProcessAndReturnValue_0045ce80(*g_apLockNodes2_011a0350[m_70]->Setting_Int() +
                                                     (int)(iDeltaX * (1.0f - fT2_2)));
        g_apLockNodes3_011a0364[m_70]->ProcessAndReturnValue_0045ce80(*g_apLockNodes3_011a0364[m_70]->Setting_Int() +
                                                     (int)(iDeltaX * fT2_2));
        for (int j = 1; j < 6; j++)
        {
            Tile* pTile2 = m_64->Tile_GetChildByID(j + 0x11);
            pTile2->Tile_Set(0xfb1, (pTile2->*reinterpret_cast<TileFloatGetterWithFlag>(static_cast<TileFloatGetter>(&Tile::FUN_00a011b0)))(0xfb1, true) + 2.0 * j * iDeltaX / 5.0);
            pTile2->Tile_Set(0xfa1, (pTile2->*reinterpret_cast<TileFloatGetterWithFlag>(static_cast<TileFloatGetter>(&Tile::FUN_00a011b0)))(0xfa1, true) - j * iDeltaX / 5.0);
        }
        break;
    }
    }
}

extern float DAT_0102978c;
extern double DAT_010718f0;
extern float DAT_01017718;
extern double DAT_01072310;
extern double DAT_01012060;
extern double DAT_01011590;
extern double DAT_010356f8;
extern double DAT_01034208;
extern double DAT_01066808;
extern double DAT_01015a38;
extern char DAT_0107462c;
extern void* DAT_011da1fc;
extern float DAT_011da2c0;

extern OSGlobals* DAT_011dea0c;

struct FooA
{
    int __thiscall GetAxisState(int a0, int a1);
};
struct DummyA
{
    int __thiscall Controls_GetMouseAxis(int a0);
};

bool __cdecl InterfaceManager_Has360Controller();
double __cdecl NiAbs_00408820(float x);
float __cdecl NiPow_006494b0(float a0, float a1);
double __cdecl FUN_00715d40();
double __cdecl InterfaceManager_GetRealScreenWidth();
float __cdecl BSMAX_00404010(float a0, float a1);
float __cdecl BSMIN(float a0, float a1);
void* __stdcall FUN_00476c00(int n);

struct Checker
{
    int __thiscall FUN_00aa5230();
};

struct TileList
{
    void* __thiscall GetHeadPos() const;
    Tile*& __thiscall GetNext(void*& pos);
};
// Computes a sound value from game state, clamps it, plays a sound on threshold crossings, stores it, and updates m_90 from nearby tiles.
// @fnv 0x007908f0
// src: XBOX_PDB 0x007908f0
void __thiscall LockPickMenu::RotateLockpick()
{
    float RunSeventhVirtualOperation = 0.0f;
    long cnt4 = 0;
    float denom;
    denom = DAT_0102978c;
    if (InterfaceManager_Has360Controller())
    {
        cnt4 = ((FooA*)DAT_011dea0c->Main_GetControls())->GetAxisState(0, 7);
        if (NiAbs_00408820((float)cnt4) <= DAT_010718f0)
        {
            cnt4 = 0;
        }
        RunSeventhVirtualOperation = (float)(NiPow_006494b0((float)cnt4 / denom, DAT_01017718) * DAT_01072310);
    }
    else
    {
        RunSeventhVirtualOperation = (float)((double)((DummyA*)DAT_011dea0c->Main_GetControls())->Controls_GetMouseAxis(1) *
                                             (FUN_00715d40() / InterfaceManager_GetRealScreenWidth()));
    }
    float kVal = m_68->FUN_00a011b0((int)DAT_011da1fc) + RunSeventhVirtualOperation;
    int remA8 = (int)m_68->FUN_00a011b0((int)DAT_011da1fc) % 100;
    int val3 = (int)kVal % 100;
    kVal = BSMAX_00404010(kVal, 0.0f);
    kVal = BSMIN(kVal, m_64->FUN_00a011b0(0xfb1));

    if (((RunSeventhVirtualOperation > DAT_01012060 && remA8 > val3) ||
         (RunSeventhVirtualOperation < DAT_01012060 && val3 > remA8)) &&
        ((Checker*)FUN_00476c00(10))->FUN_00aa5230() == 0)
    {
        (BSAudio::GetSingleton()->*reinterpret_cast<SoundHandleByEditorID>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(&DAT_0107462c, 0x101).Play(false);
    }
    else if (RunSeventhVirtualOperation != DAT_01012060 && DAT_011da2c0 == DAT_01012060)
    {
        (BSAudio::GetSingleton()->*reinterpret_cast<SoundHandleByEditorID>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(&DAT_0107462c, 0x101).Play(false);
    }
    m_68->Tile_Set((int)DAT_011da1fc, kVal, true);
    DAT_011da2c0 = RunSeventhVirtualOperation;
    UpdateLockRotation(kVal);
    float x9 = (float)NiAbs_00408820(kVal - m_84);
    if (x9 < (float)m_88)
    {
        unsigned long res4;
        float aV5;
        void* elem9 = reinterpret_cast<TileList*>(&m_64->m_kChildTileList)->GetHeadPos();
        aV5 = m_64->FUN_00a011b0(0xfb1);
        res4 = 0;
        while (elem9 != 0)
        {
            Tile* bestElem6 = reinterpret_cast<TileList*>(&m_64->m_kChildTileList)->GetNext(elem9);
            float a3 = (float)(((Tile*)bestElem6)->FUN_00a011b0(0xfb1) / DAT_01011590);
            if (a3 < aV5 && x9 < a3)
            {
                aV5 = a3;
                res4 = (int)bestElem6;
            }
        }
        if (res4 != 0)
        {
            m_90 = (float)((1.0 - (((Tile*)(void*)res4)->FUN_00a011b0(0xfaa) - DAT_010356f8) / DAT_01034208) *
                           DAT_01066808);
            m_68->Tile_Set(0xfb2, ((Tile*)(void*)res4)->FUN_00a011b0(0xfb2), true);
            m_68->Tile_Set(0xfb3, ((Tile*)(void*)res4)->FUN_00a011b0(0xfb3), true);
            m_68->Tile_Set(0xfb4, ((Tile*)(void*)res4)->FUN_00a011b0(0xfb4), true);
        }
    }
    else
    {
        float resultB_2;
        resultB_2 = (float)(((double)m_88 + x9 - m_64->FUN_00a011b0(0xfb1)) /
                            ((double)m_88 * DAT_01011590 - m_64->FUN_00a011b0(0xfb1)));
        m_90 = (float)(resultB_2 * DAT_01015a38);
        m_68->Tile_Set(0xfb2, m_64->FUN_00a011b0(0xfb2), true);
        m_68->Tile_Set(0xfb3, m_64->FUN_00a011b0(0xfb3), true);
        m_68->Tile_Set(0xfb4, m_64->FUN_00a011b0(0xfb4), true);
    }
}

// InitLockInterface v1 worker20: faithful transcription from capstone ORIG
struct ModelLoader
{
    void* ModelLoader_LoadFile(const char* path, int a, bool b, bool c, bool d, bool e);
};
extern ModelLoader* DAT_011c3b3c;
struct SortNode
{
    SortNode* FUN_00a5ecb0(unsigned int a);
};
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int n);
struct Glob
{
    void FUN_0066b0d0(void* p);
    void* Modelloader_GetReferencedThis();
};
extern void* DAT_011f36ac;
struct MatA
{
    int m_00[9];
    void FUN_006815c0();
    void FUN_00524ac0(float f);
};
struct MatB
{
    int m_00[9];
    void FUN_006815c0();
    void FUN_004a0c90(float f);
};
struct MatrixResult
{
    int values[9];
};
struct Comb
{
    MatrixResult FUN_0043f8d0(void* a);
};
struct CtrlNode
{
    void* NiControllerManager_GetSequenceByName(const NiFixedString& str);
    void FUN_0048fef0(float f);
    void FUN_0047aab0(void* child, int a, int b, float c, float d, int e);
};
struct ChildObj
{
    bool NiControllerSequence_SetCycleType(int a);
};
extern "C" void __cdecl NiTimeController_StartAnimations(void* p);
extern "C" void* __cdecl FUN_00450b80(unsigned int a);
struct TimeObj
{
    float FUN_0084d030();
};
struct SceneNode
{
    void FUN_00b5ca70(void* a, float f);
};
struct VObj
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void f3c();
    virtual void f40();
    virtual void f44();
    virtual void f48();
    virtual void f4c();
    virtual void f50();
    virtual void f54();
    virtual void f58();
    virtual void f5c();
    virtual void f60();
    virtual void f64();
    virtual void f68();
    virtual void f6c();
    virtual void f70();
    virtual void f74();
    virtual void f78();
    virtual void f7c();
    virtual void f80();
    virtual void f84();
    virtual void f88();
    virtual void f8c();
    virtual void f90();
    virtual void f94();
    virtual void f98();
    virtual void f9c();
    virtual void fa0();
    virtual void fa4();
    virtual void fa8();
    virtual void fac();
    virtual void fb0();
    virtual void fb4();
    virtual void fb8();
    virtual void fbc();
    virtual void fc0();
    virtual void fc4();
    virtual void fc8();
    virtual void fcc();
    virtual void fd0();
    virtual void fd4();
    virtual void fd8();
    virtual void m_dc(void* a, int b);
};
struct Mat9
{
    int d[9];
};
extern unsigned char DAT_011a9448;
// Loads the lock interface and bobby pin NIFs, sets up their scene nodes and controllers, and attaches the resulting node to the scene.
// @fnv 0x0078e1c0
void LockPickMenu::InitLockInterface()
{
    void* pin;
    pin = DAT_011c3b3c->ModelLoader_LoadFile("Meshes\\Terminals\\LockInterface01.NIF", 0, true, false, false, false);
    void* idx;
    idx = DAT_011c3b3c->ModelLoader_LoadFile("Meshes\\Terminals\\BobbyPin01.NIF", 0, true, false, false, false);
    *(Mat9*)&rotation = *(Mat9*)&DAT_011a9448;
    {
        position = NiPoint3(0.0f, 0.0f, -1.6f);
    }
    ((NiNode*)idx)->NiAVObject_SetTranslate(position);
    ((NiNode*)idx)->SetRotate_0043fa80(&rotation);
    ((Glob*)&DAT_011da24c)->FUN_0066b0d0(new NiSortAdjustNode(0u));
    ((VObj*)((Glob*)&DAT_011da24c)->Modelloader_GetReferencedThis())->m_dc(pin, 1);
    ((VObj*)((Glob*)&DAT_011da24c)->Modelloader_GetReferencedThis())->m_dc(idx, 1);
    MatA ptr;
    ptr.FUN_006815c0();
    MatB z;
    z.FUN_006815c0();
    ptr.FUN_00524ac0(1.57079637f);
    z.FUN_004a0c90(1.57079637f);
    ((NiNode*)((Glob*)&DAT_011da24c)->Modelloader_GetReferencedThis())->SetRotate_0043fa80(&((Comb*)&ptr)->FUN_0043f8d0(&z));
    ((NiNode*)((Glob*)&DAT_011da24c)->Modelloader_GetReferencedThis())->NiAVObject_SetTranslate_004bc1f0(125.0f, 0.0f, 0.0f);
    NiUpdateData i(0.0f, false, false);
    ((NiNode*)((Glob*)&DAT_011da24c)->Modelloader_GetReferencedThis())->NiAVObject_Update(i);
    void* s;
    s = ((NiNode*)pin)->NiObjectNET_GetController(reinterpret_cast<NiRTTI*>(&DAT_011f36ac));
    CtrlNode* r;
    if (!!s)
    {
        r = (CtrlNode*)s;
        m_9c = (NiControllerSequence*)r->NiControllerManager_GetSequenceByName(NiFixedString("Forward"));
        m_a0 = (NiControllerSequence*)r->NiControllerManager_GetSequenceByName(NiFixedString("Backward"));
        r->FUN_0048fef0(0.0f);
        if (!!m_9c)
        {
            r->FUN_0047aab0(m_9c, 0, 1, 1.0f, 0.0f, 0);
        }
        if (!!m_a0)
        {
            reinterpret_cast<ChildObj*>(m_a0)->NiControllerSequence_SetCycleType(2);
        }
        NiTimeController_StartAnimations(pin);
    }
    void* cnt;
    cnt = ((NiNode*)idx)->NiObjectNET_GetController(reinterpret_cast<NiRTTI*>(&DAT_011f36ac));
    if (!!cnt)
    {
        m_a4 = (NiControllerManager*)cnt;
        m_a8 = (NiControllerSequence*)reinterpret_cast<CtrlNode*>(m_a4)->NiControllerManager_GetSequenceByName(NiFixedString("Forward"));
        m_ac = (NiControllerSequence*)reinterpret_cast<CtrlNode*>(m_a4)->NiControllerManager_GetSequenceByName(NiFixedString("Backward"));
        m_b0 = (NiControllerSequence*)reinterpret_cast<CtrlNode*>(m_a4)->NiControllerManager_GetSequenceByName(NiFixedString("Left"));
        reinterpret_cast<CtrlNode*>(m_a4)->FUN_0048fef0(0.0f);
        if (!!m_a8)
        {
            reinterpret_cast<CtrlNode*>(m_a4)->FUN_0047aab0(m_a8, 0, 1, 1.0f, 0.0f, 0);
        }
        if (!!m_b0)
        {
            reinterpret_cast<ChildObj*>(m_b0)->NiControllerSequence_SetCycleType(2);
        }
        NiTimeController_StartAnimations(idx);
    }
    ((Glob*)&DAT_011da224)->FUN_0066b0d0(Create3DCamera());
    ((VObj*)FUN_00450b80(1))->m_dc(((Glob*)&DAT_011da24c)->Modelloader_GetReferencedThis(), 1);
    float val;
    val = (float)(((TimeObj*)((NiNode*)((Glob*)&DAT_011da24c)->Modelloader_GetReferencedThis())->NiAVObject_GetWorldBound())->FUN_0084d030() * 3.0);
    ((SceneNode*)FUN_00450b80(1))->FUN_00b5ca70(((Glob*)&DAT_011da24c)->Modelloader_GetReferencedThis(), val);
}

int __cdecl BSStringT_char_SPrintF(StrMem*, const char*, ...);
struct PickTemplate
{
    Tile* FUN_00a1ddb0();
};
struct PickWrapper
{
    PickTemplate* FUN_00639b40();
};
struct PickRandom
{
    float FUN_004dff60();
};

extern int DAT_011da28c[6];
// Interpolates pick and driver angles from lock nodes, updates the two angle labels, and builds six sweet-spot tiles with fading colors.
// @fnv 0x00791000
void LockPickMenu::UpdateSweetSpot()
{
    float fraction;
    int angle = DAT_011da28c[m_70 + 1] - DAT_011da28c[m_70];
    fraction = BSMAX_00404010(BSMIN((float)(m_74 - DAT_011da28c[m_70]) / ((float)angle * 2.0f), 1.0f), 0.0f);
    int range = 0;
    int start = 6;
    NiColorA end(0.0f, 1.0f, 0.0f, 1.0f);
    NiColorA color(1.0f, 0.0f, 0.0f, 1.0f);
    NiColorA count = end;
    m_64->ResetImage();
    StrMem text;
    g_iPickAngle_011da208 =
        (int)(*g_apLockNodes0_011a0328[m_70]->Setting_Int() +
              (*g_apLockNodes1_011a033c[m_70]->Setting_Int() - *g_apLockNodes0_011a0328[m_70]->Setting_Int()) *
                  fraction);
    g_iDriverAngle_011da20c =
        (int)(*g_apLockNodes2_011a0350[m_70]->Setting_Int() +
              (*g_apLockNodes3_011a0364[m_70]->Setting_Int() - *g_apLockNodes2_011a0350[m_70]->Setting_Int()) *
                  fraction);
    BSStringT_char_SPrintF(&text, "%d", g_iPickAngle_011da208);
    unk3c->Tile_Set_00a01350(0xfc4, text.Modelloader_GetReferencedThis(), true);
    BSStringT_char_SPrintF(&text, "%d", g_iDriverAngle_011da20c);
    unk48->Tile_Set_00a01350(0xfc4, text.Modelloader_GetReferencedThis(), true);
    m_88 = g_iDriverAngle_011da20c + g_iPickAngle_011da208 / 2;
    m_84 = m_64->FUN_00a011b0(0xfb1) * ((PickRandom*)FUN_00476c00())->FUN_004dff60();
    m_84 = BSMIN(BSMAX_00404010(m_84, (float)m_88), m_64->FUN_00a011b0(0xfb1) - m_88);
    range = (int)(m_84 - g_iPickAngle_011da208 / 2);
    for (int i = 0; i < 6; i++)
    {
        Tile* tile = FUN_00726070(m_64, "LPM_SweetSpotTemplate", 0)->FUN_00639b40()->FUN_00a1ddb0();
        tile->FUN_00700320(0xfaa, i + 17);
        tile->Tile_Set(0xfb1, (m_84 - range) * 2.0f, true);
        tile->FUN_00700320(0xfa1, range);
        tile->FUN_00700320(0xfad, start);
        tile->Tile_Set(0xfb2, (float)(count.r * 255.0), true);
        tile->Tile_Set(0xfb3, (float)(count.g * 255.0), true);
        tile->Tile_Set(0xfb4, (float)(count.b * 255.0), true);
        range -= g_iDriverAngle_011da20c / 5;
        start--;
        count = end + (color - end) * (float)((i + 1) / 5.0);
    }
}

class LKSelection
{
  public:
    virtual ~LKSelection();
};

struct LKMenuFile
{
    Tile* Tile_ReadFile();
};
struct LKInterface
{
    LKMenuFile* CombatController_GetCombatState(const char* pcPath);
};

struct LKRef
{
    int TESObjectREFR_GetLockLevel();
};
struct LKPlayer
{
    int FUN_00575610(int iItem);
};

extern LockPickMenu* DAT_011da204;
extern int DAT_011da1f8;
extern int DAT_011ca268;
extern StringSetting DAT_011d1efc;
extern StringSetting DAT_011d345c;
extern StringSetting DAT_011c3cb4;
extern StringSetting DAT_011d4d2c;
extern StringSetting DAT_011d4360;
extern StringSetting DAT_011d25bc;
extern StringSetting DAT_011d33fc;
extern StringSetting* DAT_01184a98[];

LKSelection* Tile_GetMenuByClass(int m_uiSoundID);
int FUN_00430b40(int iValue);
int BSMAX_00647b70(int iValue, int iMin);
int MinInt(int iValue, int iMax);
int BSsprintf(char* pcBuffer, unsigned int uiSize, const char* pcFormat, ...);
int FUN_00406d50(char* pcBuffer, unsigned int uiSize, const char* pcText);
void Warning_005b5e40(const char* pcMessage);
int Tile_TextToTrait(const char* pcTrait);
float FUN_00a01530();
int BSstrcmp(const char* pcA, const char* pcB);

// Creates the lockpick UI menu from lockpick_menu.xml, sets skill, level, and pick count labels, and returns the menu tile or null on failure.
// @fnv 0x0078db00
Tile* CreateLockpickMenu(LockRef* pkLockRef, int aiLockLevel, bool bDebug)
{
    char acMessageVal[260];
    char acLabel[64];
    LKSelection* pkSelection = Tile_GetMenuByClass(0x3f6);
    LKInterface* pkInterfaceVal = (LKInterface*)InterfaceManager_GetSingleton();
    int iLockLevelNum = pkLockRef ? FUN_00430b40(((LKRef*)pkLockRef)->TESObjectREFR_GetLockLevel()) : aiLockLevel;
    iLockLevelNum = MinInt(BSMAX_00647b70(iLockLevelNum, 0), 4);
    if (pkLockRef && g_player_011dea3c->kAVOwner.GetActorValueAsInteger(0x24) < g_aiLockLevels_011da28c[iLockLevelNum])
    {
        BSsprintf(acMessageVal, 0x104, DAT_011d1efc.FUN_00403df0(), g_aiLockLevels_011da28c[iLockLevelNum]);
        DispatchMessageToSink(acMessageVal, 0, "Interface\\Icons\\Message Icons\\glow_message_padlock.dds", 0, 2.0f, 0);
        (BSAudio::BSAudio_QInstance()->*reinterpret_cast<SoundHandleByEditorID>(&BSAudio::BSAudio_GetSoundHandleByEditorName))("UIPopUpMessageGeneral", 0x121).Play(false);
        return 0;
    }
    if (pkSelection)
        delete pkSelection;
    Tile* pkMenuTileNew = pkInterfaceVal->CombatController_GetCombatState("Data\\Menus\\lockpick_menu.xml")->Tile_ReadFile();
    DAT_011da204 = (LockPickMenu*)pkMenuTileNew->Tile_GetMenu();
    if (DAT_011da204 && DAT_011da204->GetClass() == LockPickMenu_GetClassStatic())
    {
        DAT_011da204->FUN_00a1dc70(reinterpret_cast<TileMenu*>(pkMenuTileNew), false);
        if (!DAT_011da204->LockPickMenu_HasTiles())
        {
            Warning_005b5e40("MENUS: Lockpicking Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (pkMenuTileNew->FUN_00a011b0(0xfa7) == 6006.0 || pkMenuTileNew->FUN_00a011b0(0xfa7) == 102.0)
            pkMenuTileNew->Tile_Set(0xfad, FUN_00a01530(), 1);
        DAT_011da204->m_6c = reinterpret_cast<TESObjectREFR*>(pkLockRef);
        DAT_011da204->m_70 = iLockLevelNum;
        DAT_011da204->FUN_00726070()->FUN_00700320(Tile_TextToTrait("_DebugMode"), bDebug);
        BSsprintf(acLabel, 0x40, "%d", DAT_011da204->m_74);
        DAT_011da204->m_pkSkillTile->Tile_Set_00a01350(DAT_011da1f8, acLabel, 1);
        BSsprintf(acLabel, 0x40, "%s [%d", DAT_011d345c.FUN_00403df0(),
                     GamePlayFormulas_GetForceLockChance(g_player_011dea3c->kAVOwner.GetActorValueAsInteger(0x24),
                                  g_aiLockLevels_011da28c[DAT_011da204->m_70]));
        FUN_00406d50(acLabel, 0x40, "%]");
        DAT_011da204->m_pkSkillLabel->Tile_Set_00a01350(0xfc4, acLabel, 1);
        DAT_011da204->m_pkLevelTile->Tile_Set_00a01350(DAT_011da1f8,
                                                  DAT_01184a98[DAT_011da204->m_70]->FUN_00403df0(), 1);
        DAT_011da204->m_5c->Tile_Set_00a01350(0xfc4, "PICK HEALTH: 100%", 1);
        DAT_011da204->m_30->SetTraitFloat(DAT_011da1f8, 1.0f);
        DAT_011da204->m_30->FUN_00700320(
            DAT_011da1f8, pkLockRef ? ((LKPlayer*)g_player_011dea3c)->FUN_00575610(DAT_011ca268) : 0);
        if (BSstrcmp(DAT_011c3cb4.FUN_00403df0(), "ENGLISH"))
        {
            pkMenuTileNew->GetNamedChild("LPM_SkillTitle")->Tile_Set_00a01350(0xfc4, DAT_011d4d2c.FUN_00403df0(), 1);
            pkMenuTileNew->GetNamedChild("LPM_PickCountTitle")->Tile_Set_00a01350(0xfc4, DAT_011d4360.FUN_00403df0(), 1);
            pkMenuTileNew->GetNamedChild("LPM_LevelTitle")->Tile_Set_00a01350(0xfc4, DAT_011d25bc.FUN_00403df0(), 1);
            DAT_011da204->m_pkLevelLabel->Tile_Set_00a01350(0xfc4, DAT_011d33fc.FUN_00403df0(), 1);
        }
        DAT_011da204->InitLockInterface();
        DAT_011da204->UpdateSweetSpot();
        DAT_011da204->FUN_00a1dc20(0);
        return pkMenuTileNew;
    }
    else
    {
        if (DAT_011da204 && DAT_011da204->FUN_00726070())
            delete DAT_011da204;
    }
    return 0;
}

class xPlayerL
{
  public:
    int m_aiPad[0x29];
    ActorValueOwner m_kAV;
};
extern xPlayerL* xThePlayer;
struct xSetting
{
    float* Float();
};
extern xSetting xS0de0;
extern int xTraitValue;
extern int xTraitX;
int xGetTrait(const char* pName, int i);

// Initializes LockPickMenu by reading trait indices and player AV value, then sets default member values.
// @fnv 0x0078d930
LockPickMenu::LockPickMenu()
{
    xTraitValue = xGetTrait("_Value", -1);
    xTraitX = xGetTrait("_x", -1);
    m_74 = xThePlayer->m_kAV.GetActorValueAsInteger(0x24);
    m_78 = (float)m_74;
    m_8c = 0.0f;
    m_94 = 1.0f + m_78 * *xS0de0.Float();
    m_28 = 0;
    m_98 = false;
    m_9c = 0;
    m_a0 = 0;
    m_a8 = 0;
    m_ac = 0;
    m_b0 = 0;
    m_99 = false;
    m_80 = 0;
}

namespace fnv_0078eb50 {
struct xUpdateData
{
    xUpdateData(float, bool, bool);
    float m_t;
    bool m_kPointA, m_kPointB, m_iThirdValue, m_iFourthElementInteger, m_usTrailingValue;
};
struct xRTTI
{
    int m_iWordAt00;
};
extern xRTTI xg_rtti_11f36ac;
struct xSeq
{
    float GetEndKeyTime_00508100();
    float NiPSysSpawnModifier_GetLifeSpan();
    void SetPhase(float, int);
};
struct xCtrlMgr
{
    void FUN_0047b220(xSeq*, float);
    void FUN_0047aab0(xSeq*, int, int, float, float, int);
    void FUN_0048fef0(float);
};
struct xNodePtr
{
    NiNode* Modelloader_GetReferencedThis();
};
extern xNodePtr xg_spNode_11da24c;
struct xMenuMode
{
    bool InterfaceManager_TutorialManager_HasBeenShown(int);
    bool InterfaceManager_TutorialManager_ShowMessage(int, int, int);
};
struct xIface
{
    char m_auiShapeKeys[0x4d4];
    xMenuMode m_4d4;
    Tile* FUN_0045cd60();
    static bool InterfaceManager_Has360Controller();
    void InterfaceManager_SetLockpickControlsDisable(int);
};
xIface* xF4b7210();
struct xControls
{
    int GetAxisState(int, int);
    void ResetTargetState();
    void Controls_Rumble(float, float, int, int, int, int, int);
};
struct xOS
{
    xControls* Main_GetControls();
};
extern xOS* xg_os_11dea0c;
struct ClockSource
{
    int FUN_00825c00();
};
extern ClockSource xg_timer_11f6394;
struct xStrSetting
{
    const char* FUN_00403df0();
};
struct xFltSetting
{
    float* Setting_Float_00403e20();
};
extern xStrSetting xg_s_11d34ec;
extern xFltSetting xg_f_11cde20;
extern xFltSetting xg_f_11d41c8;
extern xFltSetting xg_f_11d0de0;
struct xForm
{
    int FUN_00401170();
};
struct xLock
{
    int m_iWordAt00, m_iWordAt04, m_8, m_iThirdValue, m_10;
};
struct xFaction : xForm
{
    bool GetEvil();
};


struct xNPC : xForm
{
    char m_auiShapeKeys[0x100];
    ActorValueOwner m_100;
};
struct xPlayer;
struct xRef : xForm
{
    xLock* TESObjectREFR_GetLock();
    void TESObjectREFR_AddLockChange();
    xForm* TESObjectREFR_GetOwner();
    void TESObjectREFR_UnLock();
    xForm* BGSSaveFormBuffer_GetForm();
    bool TESObjectREFR_Activate(xPlayer*, int, int, int);
};
struct xCrimeMgr
{
    void* ProcessLists_GetActorRefInHigh_00970b30(xFaction*, int, int);
    void* ProcessLists_GetActorRefInHigh(xNPC*, int);
};
extern xCrimeMgr xg_crime_11e0e80;

struct xPlayer
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
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void RemoveItem(void*, int, int, int, int, int, int, int, int, int);
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290(int);
    char m_auiShapeKeys[0x208];
    bool m_20c;
    void MiddleHighProcess_SetWantWeaponDrawn(int);
    void FUN_008bfa40(void*, int, int, int, xForm*);
    void PlayerCharacter_RewardKarma(int);
};

extern xPlayer* xg_player_11dea3c;
extern void* xg_pLockpick_11ca268;
extern float xg_fElapsed_11da2ac;
extern int xg_iLastState_11da2a8;
extern bool xg_bMsg_11da2a4;
extern int xg_iTileId_11da1f8;
extern int xg_iTileId2_11da1fc;
extern int xg_iDir_11a0394;
bool xF702450(int);
int xF790290();
int xF78e080();
float xF408820(float);
bool xF5d4a40();
float xF404010(float, float);
float xF40ebd0(float, float);
void xF4d5c60(int);
int xF6705b0(int, int);
void xF75b6e0(int);
int xF47e040(float);
void xF78e0d0();
float xF4bd510(float, float);
int xSprintf(char*, unsigned int, const char*, ...);
bool xQueueMsg(const char*, int, const char*, const char*, float, int);

static const char s_szIcon[] = "Interface\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds";
static const char s_szEnter[] = "UILockpickingEnter";
static const char s_szTurn[] = "UILockpickingCylinderTurn";
static const char s_szSqueakA[] = "UILockpickingCylinderSqueakA";
static const char s_szSqueakB[] = "UILockpickingCylinderSqueakB";
static const char s_szUnlock[] = "UILockpickingUnlock";
static const char s_szOpened[] = "LOCK OPENED!  :D";
static const char s_szStop[] = "UILockpickingCylinderStop";
static const char s_szTension[] = "UILockpickingPickTensionLPM";
static const char s_szHealthFmt[] = "PICK HEALTH: %d%s";
static const char s_szPercent[] = "%";
static const char s_szBreak[] = "UILockpickingPickBreak";
static const char s_szHealthFull[] = "PICK HEALTH: 100%";
extern const char s_litEnd78eb50[] = "";
}  // namespace fnv_0078eb50

// Updates the lockpicking menu state machine, advancing sequences, adjusting tension, and handling lock success or pick breakage.
// @fnv 0x0078eb50
// src: XBOX_PDB 0x0078eb50
void LockPickMenu::DoIdle_0078eb50()
{
    using namespace fnv_0078eb50;
    int qSVM = 0;
    float qrEZrs = 1.0f;
    static BSSoundHandle s_kTension;
    bool qpqRa = xF702450(GetClass());
    if (m_80 == 0)
    {
        qSVM = 0;
        xg_fElapsed_11da2ac = 0.0f;
        xg_iLastState_11da2a8 = 0;
    }
    else
    {
        qSVM = xg_timer_11f6394.FUN_00825c00() - m_80;
        if (xg_iLastState_11da2a8 != m_28)
            xg_fElapsed_11da2ac = 0.0f;
        else
            xg_fElapsed_11da2ac += qSVM / 1000.0;
    }
    m_80 = xg_timer_11f6394.FUN_00825c00();
    xg_iLastState_11da2a8 = m_28;
    if (m_99)
    {
        if (qpqRa && xF4b7210()->m_4d4.InterfaceManager_TutorialManager_HasBeenShown(xF790290()))
            m_99 = false;
        else
            return;
    }
    if (!qpqRa)
        xF4b7210()->FUN_0045cd60()->Tile_Set(0xfa9, 255.0f, true);
    int qsSDDgz = 0;
    int qfTOqo = 0x7fff;
    if (xF4b7210()->InterfaceManager_Has360Controller())
    {
        qsSDDgz = xg_os_11dea0c->Main_GetControls()->GetAxisState(0, 9);
        if (xF408820((float)qsSDDgz) <= 8689.0)
            qsSDDgz = 0;
        qrEZrs = -qsSDDgz / 32767.0;
    }
    switch (m_28)
    {
    case 0:
        if (m_9c && m_a8)
        {
            xUpdateData UPD0(xg_fElapsed_11da2ac, true, false);
            xUpdateData UPD1(xg_fElapsed_11da2ac, true, false);
            xg_spNode_11da24c.Modelloader_GetReferencedThis()->FUN_0043b4a0(0)->NiAVObject_Update(reinterpret_cast<NiUpdateData&>(UPD0));
            if (xg_fElapsed_11da2ac == 0.0 || !m_6c || m_30->FUN_00a011b0(xg_iTileId_11da1f8) > 0.0)
                xg_spNode_11da24c.Modelloader_GetReferencedThis()->FUN_0043b4a0(1)->NiAVObject_Update(reinterpret_cast<NiUpdateData&>(UPD1));
            if (xg_fElapsed_11da2ac == 0.0 && m_6c)
            {
                if (m_30->FUN_00a011b0(xg_iTileId_11da1f8) <= 0.0)
                    xQueueMsg(xg_s_11d34ec.FUN_00403df0(), 0, s_szIcon, 0, 2.0f, 0);
                else
                    (BSAudio::BSAudio_QInstance()->*reinterpret_cast<SoundHandleByEditorID>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(s_szEnter, 0x121).Play(false);
            }
            if (reinterpret_cast<xSeq*>(m_9c)->GetEndKeyTime_00508100() <= xg_fElapsed_11da2ac)
            {
                xCtrlMgr* qArxcFu =
                    (xCtrlMgr*)((NiNode*)xg_spNode_11da24c.Modelloader_GetReferencedThis()->FUN_0043b4a0(0u))->NiObjectNET_GetController(reinterpret_cast<NiRTTI*>(&xg_rtti_11f36ac));
                NiAVObject* qAhbO = ((NiNode*)((NiNode*)xg_spNode_11da24c.Modelloader_GetReferencedThis()->FUN_0043b4a0(0u))->FUN_0043b4a0(0u))->FUN_0043b4a0(2u);
                NiPoint3 qxQHW = qAhbO->GetTranslate_0043c490();
                m_28 = 2;
                qArxcFu->FUN_0047b220(reinterpret_cast<xSeq*>(m_9c), 0.0f);
                qArxcFu->FUN_0047aab0(reinterpret_cast<xSeq*>(m_a0), 0, 1, 1.0f, 0.0f, 0);
                reinterpret_cast<xCtrlMgr*>(m_a4)->FUN_0047b220(reinterpret_cast<xSeq*>(m_a8), 0.0f);
                reinterpret_cast<xCtrlMgr*>(m_a4)->FUN_0047aab0(reinterpret_cast<xSeq*>(m_ac), 0, 1, 1.0f, 0.0f, 0);
            }
        }
        break;
    case 1:
        if (m_a8)
        {
            xUpdateData UPDB(xg_fElapsed_11da2ac, true, false);
            xg_spNode_11da24c.Modelloader_GetReferencedThis()->FUN_0043b4a0(1)->NiAVObject_Update(reinterpret_cast<NiUpdateData&>(UPDB));
            if (reinterpret_cast<xSeq*>(m_a8)->GetEndKeyTime_00508100() <= xg_fElapsed_11da2ac)
            {
                m_28 = 2;
                reinterpret_cast<xCtrlMgr*>(m_a4)->FUN_0047b220(reinterpret_cast<xSeq*>(m_a8), 0.0f);
                reinterpret_cast<xCtrlMgr*>(m_a4)->FUN_0047aab0(reinterpret_cast<xSeq*>(m_ac), 0, 1, 1.0f, 0.0f, 0);
            }
        }
        break;
    case 2:
        if (xF5d4a40() && !xF4b7210()->m_4d4.InterfaceManager_TutorialManager_HasBeenShown(xF790290()))
        {
            m_99 = xF4b7210()->m_4d4.InterfaceManager_TutorialManager_ShowMessage(xF790290(), xF78e080(), 0);
        }
        else if (qpqRa)
        {
            if (!m_6c || m_30->FUN_00a011b0(xg_iTileId_11da1f8) > 0.0)
            {
                if ((xIface::InterfaceManager_Has360Controller() && qrEZrs > 0.0) || (!xIface::InterfaceManager_Has360Controller() && LockPickMenu_IsTurningLock(true)))
                {
                    (BSAudio::BSAudio_QInstance()->*reinterpret_cast<SoundHandleByEditorID>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(s_szTurn, 0x121).Play(false);
                    m_28 = 3;
                }
                RotateLockpick();
            }
            if (m_8c > 0.0)
            {
                float OLD2 = m_8c;
                m_8c -= qSVM * 90 / 1000.0;
                m_8c = xF404010(m_8c, 0.0f);
                AdvanceSequence(0.0f);
                if (m_8c < 30.0 && OLD2 > 30.0)
                    (BSAudio::BSAudio_QInstance()->*reinterpret_cast<SoundHandleByEditorID>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(s_szSqueakA, 0x101).Play(false);
                if (m_8c < 60.0 && OLD2 > 60.0)
                    (BSAudio::BSAudio_QInstance()->*reinterpret_cast<SoundHandleByEditorID>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(s_szSqueakB, 0x101).Play(false);
            }
        }
        break;
    case 3:
        if (!m_98 &&
            (!qpqRa || (xIface::InterfaceManager_Has360Controller() && qrEZrs <= 0.0) || (!xIface::InterfaceManager_Has360Controller() && !LockPickMenu_IsTurningLock(false))))
        {
            xg_os_11dea0c->Main_GetControls()->ResetTargetState();
            m_28 = 2;
        }
        else
        {
            float OLD3 = m_8c;
            if (m_98)
                qrEZrs = 1.0f;
            if (m_8c <= m_90)
            {
                m_8c += qSVM * 90 * qrEZrs / 1000.0;
                m_8c = xF40ebd0(m_8c, m_90);
            }
            AdvanceSequence(0.0f);
            if (xIface::InterfaceManager_Has360Controller())
                xg_os_11dea0c->Main_GetControls()->Controls_Rumble(0.1f, 0.0f, 0xfa, 0x7d, 3, 1, 0);
            if (OLD3 < 30.0 && m_8c > 30.0)
                (BSAudio::BSAudio_QInstance()->*reinterpret_cast<SoundHandleByEditorID>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(s_szSqueakA, 0x101).Play(false);
            if (OLD3 < 60.0 && m_8c > 60.0)
                (BSAudio::BSAudio_QInstance()->*reinterpret_cast<SoundHandleByEditorID>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(s_szSqueakB, 0x101).Play(false);
            if (m_8c >= m_90)
            {
                if (m_8c >= 90.0)
                {
                    if (m_6c)
                    {
                        xF4d5c60(4);
                        if (reinterpret_cast<xRef*>(m_6c)->TESObjectREFR_GetLock()->m_10 == 0)
                        {
                            xg_player_11dea3c->v290(xF6705b0(3, m_70));
                            reinterpret_cast<xRef*>(m_6c)->TESObjectREFR_GetLock()->m_10++;
                            reinterpret_cast<xRef*>(m_6c)->TESObjectREFR_AddLockChange();
                        }
                        if (reinterpret_cast<xRef*>(m_6c)->TESObjectREFR_GetOwner())
                        {
                            xForm* OWNER = reinterpret_cast<xRef*>(m_6c)->TESObjectREFR_GetOwner();
                            void* CRIME = 0;
                            if (OWNER->FUN_00401170() == 8)
                            {
                                xFaction* FACA = (xFaction*)OWNER;
                                CRIME = xg_crime_11e0e80.ProcessLists_GetActorRefInHigh_00970b30(FACA, 1, 1);
                            }
                            else
                            {
                                xNPC* NPCA = (xNPC*)OWNER;
                                CRIME = xg_crime_11e0e80.ProcessLists_GetActorRefInHigh(NPCA, 1);
                            }
                            if (CRIME)
                            {
                                xg_player_11dea3c->MiddleHighProcess_SetWantWeaponDrawn(1);
                                xg_player_11dea3c->FUN_008bfa40(CRIME, 0, 0, 0, OWNER);
                            }
                            else
                            {
                                bool BOUNTY = false;
                                if (OWNER && OWNER->FUN_00401170() == 8)
                                {
                                    xFaction* FACB = (xFaction*)OWNER;
                                    if (!FACB->GetEvil())
                                        BOUNTY = true;
                                }
                                else if (OWNER)
                                {
                                    xNPC* NPCB = (xNPC*)OWNER;
                                    if (NPCB)
                                    {
                                        int DISP = xF47e040(NPCB->m_100.GetCurrentActorValue(static_cast<ActorValue::Index>(0x17)));
                                        if (DISP != 2 && DISP != 4)
                                            BOUNTY = true;
                                    }
                                }
                                if (BOUNTY)
                                    xg_player_11dea3c->PlayerCharacter_RewardKarma((int)*xg_f_11cde20.Setting_Float_00403e20());
                            }
                        }
                        (BSAudio::BSAudio_QInstance()->*reinterpret_cast<SoundHandleByEditorID>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(s_szUnlock, 0x101).Play(false);
                        reinterpret_cast<xRef*>(m_6c)->TESObjectREFR_UnLock();
                        if (reinterpret_cast<xRef*>(m_6c)->FUN_00401170() == 0x1c)
                            xg_player_11dea3c->m_20c = true;
                        if (reinterpret_cast<xRef*>(m_6c)->BGSSaveFormBuffer_GetForm() && reinterpret_cast<xRef*>(m_6c)->BGSSaveFormBuffer_GetForm()->FUN_00401170() == 0x1b)
                            xF75b6e0(1);
                        reinterpret_cast<xRef*>(m_6c)->TESObjectREFR_Activate(xg_player_11dea3c, 0, 0, 1);
                        if (reinterpret_cast<xRef*>(m_6c)->FUN_00401170() == 0x1c)
                            xg_player_11dea3c->m_20c = false;
                        xF78e0d0();
                    }
                    else
                    {
                        m_58->Tile_Set_00a01350(0xfc4, s_szOpened, true);
                        m_58->FUN_00700320(0xfa3, 1);
                        if (!m_6c)
                            m_30->FUN_00700320(xg_iTileId_11da1f8, 0);
                        xg_bMsg_11da2a4 = true;
                        m_28 = 6;
                    }
                }
                else
                {
                    (BSAudio::BSAudio_QInstance()->*reinterpret_cast<SoundHandleByEditorID>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(s_szStop, 0x101).Play(false);
                    s_kTension = (BSAudio::BSAudio_QInstance()->*reinterpret_cast<SoundHandleByEditorID>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(s_szTension, 1);
                    s_kTension.Play(true);
                    m_28 = 4;
                }
                xg_os_11dea0c->Main_GetControls()->ResetTargetState();
            }
        }
        break;
    case 4:
        if (!qpqRa || (xF4b7210()->InterfaceManager_Has360Controller() && qrEZrs <= 0.0) ||
            (!xF4b7210()->InterfaceManager_Has360Controller() && !LockPickMenu_IsTurningLock(false)))
        {
            s_kTension.FadeOutAndRelease(500);
            xg_os_11dea0c->Main_GetControls()->ResetTargetState();
            m_28 = 2;
        }
        else
        {
            xUpdateData qxWmVch(0.0f, true, false);
            float qQMZREG = qSVM / 1000.0;
            char qJDuOZ[0x20];
            if (*xg_f_11d41c8.Setting_Float_00403e20() != 0.0)
                m_94 -= qQMZREG / *xg_f_11d41c8.Setting_Float_00403e20();
            m_94 = xF404010(m_94, 0.0f);
            AdvanceSequence(xg_iDir_11a0394 * 0.25);
            if (xIface::InterfaceManager_Has360Controller())
                xg_os_11dea0c->Main_GetControls()->Controls_Rumble(0.5f, 0.0f, 0xfa, 0, 0, 0, 0);
            if (m_ac)
            {
                reinterpret_cast<xSeq*>(m_ac)->SetPhase(reinterpret_cast<xSeq*>(m_ac)->NiPSysSpawnModifier_GetLifeSpan() + (1.0 - m_94) * (reinterpret_cast<xSeq*>(m_ac)->GetEndKeyTime_00508100() - reinterpret_cast<xSeq*>(m_ac)->NiPSysSpawnModifier_GetLifeSpan()),
                                   0);
                xg_spNode_11da24c.Modelloader_GetReferencedThis()->NiAVObject_Update(reinterpret_cast<NiUpdateData&>(qxWmVch));
            }
            UpdateLockRotation(m_68->FUN_00a011b0(xg_iTileId2_11da1fc) + xg_iDir_11a0394 * 2.5);
            xg_iDir_11a0394 = -xg_iDir_11a0394;
            xSprintf(qJDuOZ, 0x20, s_szHealthFmt, (int)xF4bd510(m_94 * 100.0, 1.0f), s_szPercent);
            m_5c->Tile_Set_00a01350(0xfc4, qJDuOZ, true);
            if (m_94 <= 0.0)
            {
                s_kTension.FadeOutAndRelease(100);
                (BSAudio::BSAudio_QInstance()->*reinterpret_cast<SoundHandleByEditorID>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(s_szBreak, 0x101).Play(false);
                if (m_6c)
                    xg_player_11dea3c->RemoveItem(xg_pLockpick_11ca268, 0, 1, 0, 0, 0, 0, 0, 1, 0);
                m_30->Tile_Set(xg_iTileId_11da1f8, m_30->FUN_00a011b0(xg_iTileId_11da1f8) - 1.0, true);
                reinterpret_cast<xCtrlMgr*>(m_a4)->FUN_0047b220(reinterpret_cast<xSeq*>(m_ac), 0.0f);
                reinterpret_cast<xCtrlMgr*>(m_a4)->FUN_0047aab0(reinterpret_cast<xSeq*>(m_b0), 0, 1, 1.0f, 0.0f, 0);
                xg_os_11dea0c->Main_GetControls()->ResetTargetState();
                m_28 = 5;
            }
        }
        break;
    case 5:
        if (m_b0 && qpqRa)
        {
            xUpdateData UPD5(xg_fElapsed_11da2ac, true, false);
            xg_spNode_11da24c.Modelloader_GetReferencedThis()->FUN_0043b4a0(1)->NiAVObject_Update(reinterpret_cast<NiUpdateData&>(UPD5));
            if (reinterpret_cast<xSeq*>(m_b0)->GetEndKeyTime_00508100() <= xg_fElapsed_11da2ac)
                m_28 = 6;
        }
        break;
    case 6:
        if (xg_fElapsed_11da2ac >= 1.0 && qpqRa)
        {
            m_58->FUN_00700320(0xfa3, 0);
            m_5c->Tile_Set_00a01350(0xfc4, s_szHealthFull, true);
            m_94 = 1.0f + m_78 * *xg_f_11d0de0.Setting_Float_00403e20();
            m_8c = 0.0f;
            AdvanceSequence(0.0f);
            m_68->Tile_Set(xg_iTileId2_11da1fc, m_64->FUN_00a011b0(0xfb1) / 2.0, true);
            xg_spNode_11da24c.Modelloader_GetReferencedThis()->FUN_0043b4a0(1)->NiAVObject_SetTranslate(position);
            xg_spNode_11da24c.Modelloader_GetReferencedThis()->FUN_0043b4a0(1)->SetRotate_0043fa80(reinterpret_cast<const NiMatrix3&>(rotation));
            reinterpret_cast<xCtrlMgr*>(m_a4)->FUN_0048fef0(0.0f);
            reinterpret_cast<xCtrlMgr*>(m_a4)->FUN_0047aab0(reinterpret_cast<xSeq*>(m_a8), 0, 1, 1.0f, 0.0f, 0);
            if (xg_bMsg_11da2a4)
            {
                UpdateSweetSpot();
                xg_bMsg_11da2a4 = false;
            }
            if (m_6c && m_30->FUN_00a011b0(xg_iTileId_11da1f8) == 0.0)
            {
                xQueueMsg(xg_s_11d34ec.FUN_00403df0(), 0, s_szIcon, 0, 2.0f, 0);
                m_58->FUN_00700320(0xfa3, 0);
                xUpdateData UPD6(0.0f, true, false);
                xg_spNode_11da24c.Modelloader_GetReferencedThis()->FUN_0043b4a0(1)->NiAVObject_Update(reinterpret_cast<NiUpdateData&>(UPD6));
                m_28 = 2;
            }
            else
            {
                m_28 = 1;
            }
        }
        break;
    case 7:
        if (FUN_0059bb30() != 2)
        {
            xF4b7210()->FUN_0045cd60()->Tile_Set(0xfa9, 255.0f, true);
            xF4b7210()->InterfaceManager_SetLockpickControlsDisable(1);
            FUN_00726070()->FUN_00700320(0x1772, 1);
            FUN_00a1d910();
        }
        break;
    }
}

