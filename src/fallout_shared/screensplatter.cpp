#include "../../include/Setting.h"
// 0x00408d60 returns the setting value at +4 (or a fallback byte for null this).

// fallout_shared/screensplatter.cpp: ScreenSplatter (16 functions)

// ExtraShell_screensplatter: local type (was include/ExtraShell.h, which had no evidence of one real class); its methods are 0x00411ec0 ExtraDataList::CopyList, 0x004127e0 ExtraDataList::CompareList, 0x00418520 ExtraDataList::GetContainerChanges, 0x00418750 ExtraDataList::HasLeveledItem
#include "../../include/ExtraDataList.h"

class OpacityFadeState;
class RefNode;
class RefrShell;

class ExtraShell_screensplatter : public ExtraDataList
{
public:
    ExtraShell_screensplatter();

    int FUN_00418520();
    bool FUN_00418750();
    short ExtraDataList_GetCount();
    bool ExtraDataList_CompareList(ExtraShell_screensplatter*);
    void ExtraDataList_SetCount(int);
    void ExtraDataList_CopyList(ExtraShell_screensplatter*);
    signed char GetExtraByteValue();
    void ExtraDataList_RemoveHotkey();
    OpacityFadeState* GetOffsetC();
    void FUN_0041aeb0();
    void ExtraDataList_RemoveScript();
    void* ExtraDataList_GetModelSwap();
    RefNode* ExtraDataList_GetDroppedItemList();
    void ExtraDataList_RemoveDroppedItemList();
    void ExtraDataList_SetItemDropper(int a);
    RefrShell* ExtraDataList_GetAshPileRef();
};
#include "../../include/SkyTextureManager.h"
#include "../../include/BSFadeNode.h"
#include "../../include/NiCamera.h"
#include "../../include/GO.h"
#include "../../include/NiFixedString.h"
#include "../../include/AutoMemContext.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiSortAdjustNode.h"
#include "../../include/NiUpdateData.h"
#include "../../include/SettingT_GameSettingCollection_.h"

class FUN_00622c80;

class ScreenSplatter
{
  public:
    static void Init();
    static void Clear();
    static FUN_00622c80* Activate(float time, bool enabled);
};

class FUN_00622c80
{
  public:
    unsigned char data[0x3b0];
    static void* operator new(unsigned int size);
    static void operator delete(void*);
    FUN_00622c80(float value, unsigned int id);
};

unsigned int bhkCollisionFilter_GetNewSystemGroup();
float DecalCaster_GetMaxDecalWidthSmall();
float DecalCaster_GetMaxDecalWidthLarge();

extern unsigned char DAT_011c7834;
extern unsigned int DAT_011c7828;
extern NiPointer<NiAVObject> DAT_011c786c;
extern FUN_00622c80* DAT_011cc200;
extern FUN_00622c80* DAT_011cc1fc;

#include "../../include/MEM_CONTEXT.h"
union SETTING_VALUE;
class INISettingCollection;
template <class T> class SettingT;



class GraphicsRenderer
{
  public:
    unsigned int GetRenderTargetWidth();
    unsigned int GetRenderTargetHeight();
};
class NiRenderer;
NiRenderer* NiXenonRenderer_GetRenderer();

#include "../../include/NiMemObject.h"





// The shared frustum has the layout but does not declare this constructor.
struct ScreenSplatterFrustum : NiFrustum
{
    ScreenSplatterFrustum(bool enabled);
};

struct ScreenSplatterRawData
{
    float value;
    unsigned int first, second;
};
struct ScreenSplatterRawFrustum
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool ortho;
};
struct ScreenSplatterInitLocals
{
    float aspect;
    ScreenSplatterRawFrustum frustum;
    GraphicsRenderer* renderer;
    ScreenSplatterRawData firstData;
    ScreenSplatterRawData secondData;
};








extern Setting DAT_011c784c;
extern NiPointer<NiAVObject> DAT_011c7840;
extern NiPointer<NiTexture> DAT_011c7860;
extern NiPointer<NiTexture> DAT_011c7864;
extern NiPointer<NiTexture> DAT_011c7868;
extern unsigned char DAT_011f941e;
extern NiPoint3 DAT_011a9478;
extern char DAT_01022ab8;
extern float DAT_01022960;
extern float DAT_0102295c;
extern float DAT_01022958;
extern float DAT_01016248;
extern double DAT_01011598;
extern const double runtimeInitializationDouble1;
extern float DAT_01189550;
extern float DAT_01189554;
extern unsigned char DAT_011ce918;
extern unsigned char DAT_011ce284;
extern unsigned char DAT_011cede8;

// @fnv 0x004e0540
void ScreenSplatter::Init()
{
    AutoMemContext m_uiMemoryContext(static_cast<MEM_CONTEXT>(7), true, &DAT_01022ab8, 181);
    DAT_011c7834 = *reinterpret_cast<unsigned char*>(DAT_011c784c.FUN_00408d60());
    if (DAT_011c7834)
    {
        ScreenSplatterInitLocals initLocals;
        initLocals.renderer = reinterpret_cast<GraphicsRenderer*>(NiXenonRenderer_GetRenderer());
        initLocals.aspect = static_cast<float>(static_cast<double>(initLocals.renderer->GetRenderTargetWidth()) /
                                               initLocals.renderer->GetRenderTargetHeight());

        DAT_011c7840 = reinterpret_cast<NiAVObject*>(new NiCamera());

        reinterpret_cast<NiAVObject*>(DAT_011c7840.operator->())->NiAVObject_SetTranslate(NiPoint3(0.0f, 0.0f, DAT_01022960));

        reinterpret_cast<NiUpdateData*>(&initLocals.firstData)->NiUpdateData::NiUpdateData(0.0f, 0, 0);
        reinterpret_cast<NiNode*>(DAT_011c7840.operator->())
            ->Update(*reinterpret_cast<const NiUpdateData*>(&initLocals.firstData));

        reinterpret_cast<NiCamera*>(DAT_011c7840.operator->())->AimAt(NiPoint3::ZERO, DAT_011a9478);

        reinterpret_cast<ScreenSplatterFrustum*>(&initLocals.frustum)->ScreenSplatterFrustum::ScreenSplatterFrustum(false);
        initLocals.frustum.ortho = false;
        initLocals.frustum.top = DAT_01016248;
        initLocals.frustum.bottom = DAT_0102295c;
        initLocals.frustum.left = static_cast<float>(initLocals.aspect * DAT_01011598);
        initLocals.frustum.right = static_cast<float>(initLocals.aspect * runtimeInitializationDouble1);
        initLocals.frustum.farPlane = DAT_01022958;
        initLocals.frustum.nearPlane = 1.0f;
        reinterpret_cast<NiCamera*>(DAT_011c7840.operator->())
            ->UpdateViewFrustum(*reinterpret_cast<NiFrustum*>(&initLocals.frustum));

        reinterpret_cast<NiUpdateData*>(&initLocals.secondData)->NiUpdateData::NiUpdateData(0.0f, 0, 0);
        reinterpret_cast<NiNode*>(DAT_011c7840.operator->())
            ->Update(*reinterpret_cast<const NiUpdateData*>(&initLocals.secondData));
        DAT_01189550 = initLocals.frustum.right;
        DAT_01189554 = initLocals.frustum.top;

        DAT_011c786c = reinterpret_cast<NiAVObject*>(new NiSortAdjustNode(0));
        DAT_011c7828 = 0;

        SkyTextureManager::LoadTextureFromPath(
            &DAT_011c7864, reinterpret_cast<SettingT_GameSettingCollection_*>(&DAT_011ce918)->String());
        SkyTextureManager::LoadTextureFromPath(
            &DAT_011c7860, reinterpret_cast<SettingT_GameSettingCollection_*>(&DAT_011ce284)->String());
        if (DAT_011f941e)
        {
            SkyTextureManager::LoadTextureFromPath(
                &DAT_011c7868, reinterpret_cast<SettingT_GameSettingCollection_*>(&DAT_011cede8)->String());
        }
    }
}

// If DAT_011c7834 is set, calls FUN_004def90 on the NiNode from DAT_011c786c and clears DAT_011c7828.
// @fnv 0x004e0870
void ScreenSplatter::Clear()
{
    if (DAT_011c7834)
    {
        reinterpret_cast<NiNode*>(DAT_011c786c.operator->())->NiNode_RemoveAllChildren();
        DAT_011c7828 = 0;
    }
}

// @fnv 0x00622a70
FUN_00622c80* ScreenSplatter::Activate(float time, bool enabled)
{
    if (time > DecalCaster_GetMaxDecalWidthSmall())
    {
        if (!DAT_011cc200 && enabled)
            DAT_011cc200 = new FUN_00622c80(DecalCaster_GetMaxDecalWidthLarge(), bhkCollisionFilter_GetNewSystemGroup());
        return DAT_011cc200;
    }
    else
    {
        if (!DAT_011cc1fc && enabled)
            DAT_011cc1fc = new FUN_00622c80(DecalCaster_GetMaxDecalWidthSmall(), bhkCollisionFilter_GetNewSystemGroup());
        return DAT_011cc1fc;
    }
}


extern NiFixedString* DAT_011c7830;

// The former BSFadeNode stand-in is a four-byte fixed string, not a scene node.
// Allocates the fixed string "SPD" and stores it in DAT_011c7830.
// @fnv 0x004e0050
void CreateSpdFadeNode()
{
    DAT_011c7830 = ::new NiFixedString("SPD");
}

// @fnv 0x004e0320
// src: XBOX_PDB 0x004e0320
NiFixedString* BSSplatterExtraData_Tag()
{
    return DAT_011c7830;
}

struct GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_011c7844;

struct FUN_004e0530_shell
{
    GlobalObject_00a7b610* GetGlobalObject();
};

// @fnv 0x004e0530
GlobalObject_00a7b610* __thiscall FUN_004e0530_shell::GetGlobalObject()
{
    return &g_011c7844;
}

// @fnv 0x00622ba0
// src: XBOX_PDB 0x00622ba0
float DecalCaster_GetMaxDecalWidthSmall()
{
    return 32.0f;
}

extern "C" const float runtimeFloatSettingDefault38;

// @fnv 0x00622bb0
// src: XBOX_PDB 0x00622bb0
float DecalCaster_GetMaxDecalWidthLarge()
{
    return runtimeFloatSettingDefault38;
}

// Calls FUN_004b9900(1) on DAT_011c7830 if non-null, then sets DAT_011c7830 to null.
// @fnv 0x004e00d0
// src: GUESS 0x004e00d0 (confidence: low)
void NiFixedString_UpdateState_004e00d0()
{
    NiFixedString* b;
    {
        NiFixedString* a = DAT_011c7830;
        b = a;
    }
    (b ? b->FUN_004b9900(1) : 0);
    DAT_011c7830 = 0;
}

// @fnv 0x004e0800
// src: GUESS 0x004e0800 (confidence: low)
void Object_ProcessEntries_004e0800()
{
    if (DAT_011c7834)
    {
        ((NiNode*)((GO*)&DAT_011c786c)->operator unsigned int())->NiNode_RemoveAllChildren();
        ((GO*)&DAT_011c786c)->operator=(0);
        ((GO*)&DAT_011c7840)->operator=(0);
    }
    DAT_011c7834 = 0;
    for (int i = 0; i < 3; ++i)
        ((GO*)((char*)&DAT_011c7860 + i * 4))->operator=(0);
}

void __cdecl CallWithParam(int);
struct Dummy00622c50
{
    void FUN_00622d00();
    void* FUN_00622c50(unsigned int flags);
};
// Calls FUN_00622d00, then if bit 0 of flags is set calls CallWithParam with this, and returns this.
// @fnv 0x00622c50
void* Dummy00622c50::FUN_00622c50(unsigned int flags)
{
    FUN_00622d00();
    if (flags & 1)
        CallWithParam((int)this);
    return this;
}

struct IntSetting
{
    int* Setting_Int();
};
struct FloatSetting
{
    float* Setting_Float_00403e20();
};
extern IntSetting DAT_011cf2b8;
extern FloatSetting DAT_011cfd4c;
unsigned int FUN_0042f5a0(unsigned int, unsigned int);
struct Params
{
    float a, b, c;
    unsigned int d;
};
struct FUN_004e04e0 : NiMemObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    FUN_004e04e0(const Params&);
    unsigned int FUN_007d6bb0();
};
struct ObjectProxy
{
    void SetExtraDataName(FUN_004e04e0*);
    void AssignFixedString(const NiFixedString&);
};
ObjectProxy* CreateScatterShapes(unsigned int);
void BSShaderBloodSplatterProperty_SetFadeSourceRecurse(ObjectProxy*, unsigned int);
struct RootProxy
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3c();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4c();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5c();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6c();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7c();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void unk8c();
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void unk9c();
    virtual void unka0();
    virtual void unka4();
    virtual void unka8();
    virtual void unkac();
    virtual void unkb0();
    virtual void unkb4();
    virtual void unkb8();
    virtual void unkbc();
    virtual void unkc0();
    virtual void unkc4();
    virtual void unkc8();
    virtual void unkcc();
    virtual void unkd0();
    virtual void unkd4();
    virtual void unkd8();
    virtual void Attach(ObjectProxy*, bool);
    void NiAVObject_Update(const NiUpdateData&);
};
// If screen splatter is enabled, allocates a splatter proxy for the requested amount, attaches it to the root, and updates it.
// @fnv 0x004e0330
// src: XBOX_PDB 0x004e0330
void ScreenSplatter_Activate(unsigned int requested, float time)
{
    if (DAT_011c7834)
    {
        unsigned int p = FUN_0042f5a0(requested, *DAT_011cf2b8.Setting_Int() - DAT_011c7828);
        if (p > 0)
        {
            ObjectProxy* a = CreateScatterShapes(p);
            DAT_011c7828 += p;
            Params s;
            s.c = 1.0f;
            s.a = 0.0f;
            if (time > 0.0)
                s.b = time;
            else
                s.b = *DAT_011cfd4c.Setting_Float_00403e20();
            s.d = p;
            FUN_004e04e0* h = new FUN_004e04e0(s);
            a->SetExtraDataName(h);
            a->AssignFixedString(NiFixedString("ScreenSplatterRoot"));
            ((RootProxy*)DAT_011c786c.operator->())->Attach(a, true);
            BSShaderBloodSplatterProperty_SetFadeSourceRecurse(a, h->FUN_007d6bb0());
            NiUpdateData i(0.0f, false, false);
            ((RootProxy*)DAT_011c786c.operator->())->NiAVObject_Update(i);
        }
    }
}

struct OpacityFadeState
{
    float age;
    float life;
    float alpha;
    unsigned int count;
};
struct ObjShell
{
    ExtraShell_screensplatter* FUN_00a5bdd0(NiFixedString*);
    void NiAVObject_Update(const NiUpdateData&);
};
struct RootCalls
{
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(unsigned int);
};
struct SplatterRoot : RootProxy
{
    virtual void SlotA();
    virtual void SlotB();
    virtual void SlotC();
    virtual void SlotD();
    virtual NiAVObject* DetachAt(unsigned int);
};
struct TimeGlobal
{
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
struct SettingF
{
    float* Setting_Float_00403e20();
};
extern SettingF DAT_011ceeb4;
extern SettingF DAT_011cf6a8;
extern SettingF DAT_011cfc2c;
extern unsigned int DAT_011c7828;
float __cdecl LinearInterpolate(float, float, float, float, float);
float __cdecl BSMIN(float, float);
void __cdecl BSShaderBloodSplatter_SetFlareOffsetScale(float);
void __cdecl BSShaderBloodSplatter_SetFlareMult(float);
void __cdecl BSShaderBloodSplatter_SetGlobalAlpha(float);
float __cdecl BSShaderBloodSplatter_GetGlobalAlpha();

// Advances each splatter child's age by elapsed time, detaches expired ones and decrements DAT_011c7828, fades alpha, updates nodes, and ramps splash5 toward 1.
// @fnv 0x004e0110
// src: COMMUNITY 0x004e0110
void ScreenSplatter_Update()
{
    if (DAT_011c7834)
    {
        float elapsed_2;
        unsigned int count;
        float splash5;
        count = ((RootCalls*)DAT_011c786c.operator->())->FUN_0043b480();
        elapsed_2 = g_timeGlobal.FUN_0084d030();
        for (unsigned int i5 = 0; i5 < count; i5++)
        {
            NiAVObject* child4 = ((RootCalls*)DAT_011c786c.operator->())->FUN_0043b4a0(i5);
            if (child4)
            {
                ExtraShell_screensplatter* extra4 = ((ObjShell*)child4)->FUN_00a5bdd0(BSSplatterExtraData_Tag());
                OpacityFadeState* data = extra4->GetOffsetC();
                data->age += elapsed_2;
                if (data->age >= data->life)
                {
                    DAT_011c7828 -= data->count;
                    ((SplatterRoot*)DAT_011c786c.operator->())->DetachAt(i5);
                }
                else
                {
                    if (data->age / data->life >= *DAT_011cfc2c.Setting_Float_00403e20())
                        data->alpha = 1.0f - LinearInterpolate(0.0f, 1.0f, *DAT_011cfc2c.Setting_Float_00403e20() * data->life,
                                                               data->life, data->age);
                    NiUpdateData updateDataA(data->age, true, false);
                    ((ObjShell*)child4)->NiAVObject_Update(updateDataA);
                }
            }
        }
        BSShaderBloodSplatter_SetFlareOffsetScale(*DAT_011ceeb4.Setting_Float_00403e20());
        BSShaderBloodSplatter_SetFlareMult(*DAT_011cf6a8.Setting_Float_00403e20());
        splash5 = BSShaderBloodSplatter_GetGlobalAlpha();
        if (splash5 < 1.0)
        {
            splash5 += elapsed_2 / 0.4;
            splash5 = BSMIN(1.0f, splash5);
            BSShaderBloodSplatter_SetGlobalAlpha(splash5);
        }
    }
}

// Constructor-like thiscall with one stack arg: calls a base routine with the
// result of a global getter, stores the class vtable pointer, copies a
// 16-byte value from the argument into the member at +0x0c and returns this.

extern char DAT_01022a24[];

struct FUN_004e04e0_quad
{
    unsigned int a, b, c, d;
};

struct FUN_004e04e0_base
{
    void FUN_00a7b440(void* node);
};

struct FUN_004e04e0_cls : FUN_004e04e0_base
{
    void* m_pVTable;
    unsigned int m_04;
    unsigned int m_08;
    FUN_004e04e0_quad m_0c;

    FUN_004e04e0_cls* InitializeFields_004e04e0(const FUN_004e04e0_quad* value);
};

// Sets the vtable, copies the given quad into m_0c, and returns this after calling FUN_00a7b440 on FUN_004e0320().
// @fnv 0x004e04e0
// src: GUESS 0x004e04e0 (confidence: low)
FUN_004e04e0_cls* FUN_004e04e0_cls::InitializeFields_004e04e0(const FUN_004e04e0_quad* pQuad)
{
    FUN_00a7b440(BSSplatterExtraData_Tag());
    m_pVTable = (void*)DAT_01022a24;
    m_0c = *pQuad;
    return this;
}

// If DAT_011cc200 and DAT_011cc1fc are set, calls FUN_00622c50(1) on each, then clears both globals.
// @fnv 0x00622bc0
// src: COMMUNITY 0x00622bc0
void DecalCaster_ClearInstance()
{
    if (DAT_011cc200)
    {
        FUN_00622c80* a = DAT_011cc200;
        FUN_00622c80* b5 = a;
        b5 ? ((Dummy00622c50*)b5)->FUN_00622c50(1) : 0;
    }
    DAT_011cc200 = 0;
    if (DAT_011cc1fc)
    {
        FUN_00622c80* c = DAT_011cc1fc;
        FUN_00622c80* d = c;
        d ? ((Dummy00622c50*)d)->FUN_00622c50(1) : 0;
    }
    DAT_011cc1fc = 0;
}

class FUN_00620ff0
{
  public:
    FUN_00620ff0();
    ~FUN_00620ff0();
};

class FUN_00633c90
{
  public:
    FUN_00633c90(int iCount);
    ~FUN_00633c90();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

namespace ScreenSplatterImpl {
class FUN_00622c80 : public FUN_00620ff0
{
  public:
    static void operator delete(void*);

  private:
  public:
    FUN_00622c80(float value, unsigned int id);

    void DecalCaster_Init(float value, unsigned int id);

    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208, unk20C;
    int unk210, unk214, unk218, unk21C, unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248, unk24C, unk250, unk254, unk258, unk25C, unk260, unk264, unk268, unk26C;
    int unk270, unk274, unk278, unk27C, unk280, unk284, unk288, unk28C, unk290, unk294, unk298, unk29C;
    int unk2A0, unk2A4, unk2A8, unk2AC, unk2B0, unk2B4, unk2B8, unk2BC, unk2C0, unk2C4, unk2C8, unk2CC;
    int unk2D0, unk2D4, unk2D8, unk2DC, unk2E0, unk2E4, unk2E8, unk2EC, unk2F0, unk2F4, unk2F8, unk2FC;
    int unk300, unk304, unk308, unk30C, unk310, unk314, unk318, unk31C, unk320, unk324, unk328, unk32C;
    int unk330, unk334, unk338, unk33C, unk340, unk344, unk348, unk34C, unk350, unk354, unk358, unk35C;
    int unk360, unk364, unk368, unk36C, unk370, unk374, unk378, unk37C, unk380, unk384, unk388, unk38C;
    int unk390, unk394, unk398, unk39C;
    FUN_00633c90 m_kSplatters;
};

// Initializes m_kSplatters, then calls FUN_00622d60 with value and id.
// @fnv 0x00622c80
FUN_00622c80::FUN_00622c80(float value, unsigned int id) : m_kSplatters(0)
{
    DecalCaster_Init(value, id);
}
}
