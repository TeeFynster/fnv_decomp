#include "../../../include/NiFrustum.h"
#include "../../../include/InterfaceManager.h"
#include "../../../include/BSAudio.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/ImageSpaceManager.h"
#include "../../../include/NiColorA.h"
#include "../../../include/Menu.h"
#include "../../../include/RaceSexMenu.h"
#include "../../../include/FORenderedMenuRaceSex.h"
#include "../../../include/PlayerCharacter.h"

// src/fallout/interface/forenderedmenuracesex.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/forenderedmenuracesex.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_007feb40_This
{
    char _pad[0xC0];
    NiColorA* GetValueAtC0(NiColorA* p);
};
// Copies the 16-byte value at offset 0xC0 of this object into the caller-supplied struct and returns that pointer.
// @fnv 0x007feb40
NiColorA* FUN_007feb40_This::GetValueAtC0(NiColorA* pValue)
{
    *pValue = *(NiColorA*)((char*)this + 0xC0);
    return pValue;
}

struct Animation
{
    void Animation_SkipUpdate(char);
};
extern PlayerCharacter* g_thePlayer;
void _FUN_007037e0();
// @fnv 0x007fe4e0
// src: COMMUNITY 0x007fe4e0
bool Menu::FORenderedMenuRaceSex_OnIdle()
{
    if (!IsUnk28Set())
    {
        _FUN_007037e0();
        return false;
    }
    g_thePlayer->GetAnimation(false)->Animation_SkipUpdate(23);
    g_thePlayer->Unk_78();
    g_thePlayer->UpdateAnimationMovement(g_thePlayer->GetAnimation(false), 0.0f);
    return UpdateScreenEffect();
}

struct SettingFloat
{
    float* Float();
};
extern SettingFloat g_011db520, g_011db464;
extern float g_011ae600, g_0120081c, g_011ae604, g_01200820, g_01200824, g_011ae608, g_01200828;
extern NiColorA g_0120082c;
struct NiRenderer;
NiRenderer* NiXenonRenderer_GetRenderer();
ImageSpaceManager* BSShaderManager_GetImageSpaceManager();
struct Effect
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
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
    float primary;
    bool enabled;
    unsigned char state159, state15a, state15b;
    unsigned int unk15c;
    float secondary;
    float BGSProjectile_GetMuzzleFlashDuration();
    NiColorA GetValueAtC0();
    void FORenderedMenuRaceSex_DoEffect(void*, void*, void*);
};
// @fnv 0x007fe9c0
// src: COMMUNITY 0x007fe9c0
void Effect::FORenderedMenuRaceSex_DoEffect(void* apArg1, void* apArg2, void* unused)
{
    bool active = true;
    active = false;
    if (active)
    {
        g_011ae600 = BGSProjectile_GetMuzzleFlashDuration();
        g_0120081c = *g_011db520.Float();
        g_011ae604 = *g_011db464.Float();
        g_01200820 = primary;
        g_0120082c = GetValueAtC0();
    }
    else
    {
        g_0120081c = 0.0f;
        g_011ae604 = 0.0f;
        g_01200820 = -1.0f;
        g_011ae600 = 1.0f;
        g_0120082c = NiColorA(1.0f, 1.0f, 1.0f, 1.0f);
    }
    if (enabled && active)
    {
        g_01200824 = *g_011db520.Float();
        g_011ae608 = *g_011db464.Float();
        g_01200828 = secondary;
    }
    else
    {
        g_01200824 = 0.0f;
        g_011ae608 = 0.0f;
        g_01200828 = -1.0f;
    }
    BSShaderManager_GetImageSpaceManager()->ImageSpaceManager_RenderEffect(30, NiXenonRenderer_GetRenderer(), apArg1, apArg2, 0, 1);
}

struct S_007fb5a0_Point3
{
    float x, y, z;
    S_007fb5a0_Point3 operator*(float s) const;
    S_007fb5a0_Point3 operator+(const S_007fb5a0_Point3& o) const;
};

struct S_007fb5a0_UpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bUpdateFlags;
    int unk8;
    S_007fb5a0_UpdateData(float t, bool c, bool f);
};

struct S_007fb5a0_Node
{
    void SetEffectColor(const S_007fb5a0_Point3& pos);
    void NiAVObject_Update(S_007fb5a0_UpdateData& data);
};

struct S_007fb5a0_NodePtr
{
    S_007fb5a0_Node* m_p;
    operator S_007fb5a0_Node*() const;
    S_007fb5a0_Node* operator->() const;
};

struct S_007fb5a0_Setting
{
    float* Setting_Float_00403e20();
};

extern S_007fb5a0_Setting DAT_011db430;
extern S_007fb5a0_Setting DAT_011db4a4;
extern S_007fb5a0_Setting DAT_011db3e8;
extern S_007fb5a0_Point3 DAT_011f4998;

float FUN_004e44d0(float f);

struct S_007fb5a0
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    S_007fb5a0_NodePtr m_pController;  // 1c
    int unk20, unk24, unk28;
    S_007fb5a0_Point3 kBase;        // 2c
    float m_fThirdCreatureStatCur;  // 38
    float fOffsetScale;             // 3c
    int unk40, unk44, unk48;
    char unk4c;
    bool bUseFirst;  // 4d
    char unk4e, unk4f;
    int unk50, unk54, unk58;
    float fFirst;  // 5c
    bool bUseSin;  // 60
    char unk61, unk62, unk63;
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88;
    float fSecond;  // 8c
    int unk90;
    bool bApplyOffset;  // 94

    void UpdateNodePosition(float fTime);
};

// @fnv 0x007fb5a0
void S_007fb5a0::UpdateNodePosition(float fTime)
{
    if (m_pController)
    {
        S_007fb5a0_Point3 kIntersectionOffset = DAT_011f4998;
        if (bApplyOffset)
        {
            float fA = bUseFirst ? fFirst * *DAT_011db430.Setting_Float_00403e20() : 0.0;
            float fB = fSecond * *DAT_011db4a4.Setting_Float_00403e20();
            float fScaleA = bUseSin ? FUN_004e44d0(fTime * *DAT_011db3e8.Setting_Float_00403e20()) + 0.5 : 1.0;
            float fD = (fA + fB) * fScaleA;
            kIntersectionOffset = kBase * fD * fOffsetScale;
        }
        S_007fb5a0_Point3 kPos = kBase * m_fThirdCreatureStatCur + kIntersectionOffset;
        m_pController->SetEffectColor(kPos);
        S_007fb5a0_UpdateData kData(0.0f, false, false);
        m_pController->NiAVObject_Update(kData);
    }
}

struct S_007fe560_Shadow;
struct S_007fe560_Pt3
{
    float x, y, z;
    S_007fe560_Pt3* SetComponents(float ax, float ay, float az);
};
struct S_007fe560_Upd
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_0043d410(float t, bool a, bool b);
};
struct S_007fe560_Light
{
    void SetEffectColor(const S_007fe560_Pt3& c);
    void NiLight_SetAmbientColor(const S_007fe560_Pt3& c);
    void FUN_0050c630(float f);
    void FUN_0050c660(float f);
    void FUN_0050c690(float f);
    void NiLight_SetDimmer(float f);
    void FUN_0050dd50(const S_007fe560_Pt3& p);
    void NiAVObject_Update(const S_007fe560_Upd& u);
};
struct S_007fe560_Base
{
    bool FUN_007fc400(const char* name, S_007fe560_Shadow* ssn);
    S_007fe560_Light* NiAVObject_GetCollisionObject();
    void FORenderedMenu_SetScreenLightColor(S_007fe560_Pt3* c);
    void SetIntensity(float f);
    void FUN_007f99b0(float f);
};
S_007fe560_Shadow* __cdecl FUN_00450b80(int n);
extern float DAT_01017b78;
void __cdecl Warning_005b5e40(const char* msg);

struct FUN_007fe560_cls : S_007fe560_Base
{
    void InitTerminalLight();
};

// @fnv 0x007fe560
void FUN_007fe560_cls::InitTerminalLight()
{
    if (!FUN_007fc400("Omni01", FUN_00450b80(1)))
    {
        Warning_005b5e40("MENUS: Failed to create terminal light.  Terminal will only receive ambient light.");
        return;
    }
    S_007fe560_Light* light = NiAVObject_GetCollisionObject();
    if (light)
    {
        S_007fe560_Pt3 kPos;
        S_007fe560_Pt3 kDiffuseColor;
        S_007fe560_Pt3 kAmbient;
        S_007fe560_Pt3 kFullColor;
        S_007fe560_Upd kNewData;
        light->SetEffectColor(*kAmbient.SetComponents(0.0f, 0.0f, 0.0f));
        light->NiLight_SetAmbientColor(*kDiffuseColor.SetComponents(0.0f, 0.0f, 0.0f));
        light->FUN_0050c630(0.0f);
        light->FUN_0050c660(0.0f);
        light->FUN_0050c690(0.0f);
        light->NiLight_SetDimmer(1.0f);
        light->FUN_0050dd50(*kPos.SetComponents(DAT_01017b78, 0.0f, 0.0f));
        kFullColor.SetComponents(1.0f, 1.0f, 1.0f);
        FORenderedMenu_SetScreenLightColor(&kFullColor);
        SetIntensity(1.0f);
        FUN_007f99b0(1.0f);
        kNewData.FUN_0043d410(0.0f, false, false);
        light->NiAVObject_Update(kNewData);
    }
}

struct PickVec
{
    float x;
    float y;
    float z;
    PickVec();
};

struct PickRecord
{
    void* ProcessArray_GetItem(unsigned int a1);
};

struct GlobalObject_00e98f20
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
    GlobalObject_00e98f20(int a1, int a2);
    ~GlobalObject_00e98f20();
    void SetByteAtOffset17(int a1);
    void FUN_006ecd40(unsigned int a1);
    void SetByteAtOffset30(int a1);
    void SetTarget_00705fc0(NiNode* apRoot);
    bool FUN_00e98e20(PickVec* apOrigin, PickVec* apDir, int a3);
    PickRecord* FUN_00500940();
};



InterfaceManager* InterfaceManager_GetSingleton();

struct PickCamera
{
    void MapScreenToRay(int aiX, int aiY, PickVec* apOrigin, PickVec* apDir, int a5);
};




struct MenuTile
{
    RaceSexMenu* GetMenu();
};

// @fnv 0x007fe6c0
bool FORenderedMenuRaceSex::HandleRaceSexMenuInput(bool abDown, int a2, int a3)
{
    InterfaceManager* pInterface = InterfaceManager_GetSingleton();
    if (abDown)
    {
        bool bReady = true;
        for (int i = 0; bReady && i < 4; i++)
        {
            if (!(NiNode*)unkD8[i] || !(NiNode*)unkE8[i])
                bReady = false;
        }
        if (bReady)
        {
            PickVec origin;
            PickVec dir;
            GlobalObject_00e98f20 pick(0, 8);
            pick.SetByteAtOffset17(1);
            pick.FUN_006ecd40(0);
            pick.SetByteAtOffset30(0);
            int iFound = -1;
            for (int j = 0; iFound < 0 && j < 4; j++)
            {
                pick.SetTarget_00705fc0(unkD8[j]);
                GetPickCamera()->MapScreenToRay((int)pInterface->TESCombatStyle_GetWeaponMinRangeMult(), (int)pInterface->QueuedModel_GetOverriddenVisualDistance(),
                                               &origin, &dir, 0);
                if (pick.FUN_00e98e20(&origin, &dir, 0))
                {
                    if (pick.FUN_00500940()->ProcessArray_GetItem(0))
                        iFound = j;
                }
            }
            if (iFound >= 0)
            {
                (BSAudio::GetSingleton()->*reinterpret_cast<BSSoundHandle (BSAudio::*)(const char*, unsigned int)>(
                    static_cast<BSSoundHandle (BSAudio::*)(const char*, unsigned int)>(
                        &BSAudio::GetSoundHandleByEditorID)))("UIMenuMode", 0x121).Play(false);
                GetMenuTile()->GetMenu()->OnRaceSelected_Thunk(iFound);
                return true;
            }
        }
    }
    // The approved base header still names this virtual slot v6.
    __if_exists(FORenderedMenu::Pick_007fb790)
    {
        return FORenderedMenu::Pick_007fb790(abDown, a2, a3);
    }
    __if_not_exists(FORenderedMenu::Pick_007fb790)
    {
        return FORenderedMenu::v6(abDown, a2, a3);
    }
}

int __cdecl FUN_00ecadb8();

extern "C" const double DAT_01016978;

struct TimerSource
{
    float* Get();
};

extern "C" TimerSource DAT_011db5b4;

struct FUN_007feb80_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54(float afValue);

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
    float m_f150;
    float m_f154;
    unsigned char m_b158;
    unsigned char unk159;
    unsigned char unk15A;
    unsigned char unk15B;
    unsigned char unk15C;
    unsigned char unk15D;
    unsigned char unk15E;
    unsigned char unk15F;
    unsigned char unk160;
    unsigned char unk161;
    unsigned char unk162;
    unsigned char unk163;
    unsigned char unk164;
    unsigned char unk165;
    unsigned char unk166;
    unsigned char unk167;
    float m_f168;

    void ActivateAndResetTimer();
    void Update(float afValue);
};

// Updates m_f150/m_f154 when afValue exceeds the timer threshold, then calls v54 if m_b158 is set, otherwise calls FUN_007fecc0 when afValue exceeds m_f168.
// @fnv 0x007feb80
void FUN_007feb80_cls::Update(float afValue)
{
    if ((double)(afValue - m_f150) > *DAT_011db5b4.Get())
    {
        m_f150 = afValue;
        m_f154 = (float)((FUN_00ecadb8() % 1000) * DAT_01016978);
    }
    if (m_b158 != 0)
    {
        v54(afValue);
    }
    else if (afValue > m_f168)
    {
        ActivateAndResetTimer();
    }
}

struct FloatSource
{
    float* Get();
};

struct IntSource
{
    int* Get();
};

extern FloatSource g_floatSource;
extern IntSource g_intSource;
extern const double g_epsilon;
int __cdecl FUN_00ecadb8();

struct Timer
{
    char pad[0x158];
    bool unk158;
    float unk15c;
    float unk160;
    float unk164;
    float unk168;
    void FORenderedMenuRaceSex_UpdateFakeDistort(float now);
};

// @fnv 0x007fec30
// src: COMMUNITY 0x007fec30
void Timer::FORenderedMenuRaceSex_UpdateFakeDistort(float now)
{
    float delta = now - unk15c;
    unk160 = delta / unk164;
    if (*g_floatSource.Get() + g_epsilon < unk160)
    {
        unk158 = false;
        unk168 = (float)(FUN_00ecadb8() % *g_intSource.Get()) + now;
    }
}

struct xPoint3
{
    xPoint3(float, float, float);
    float x, y, z;
};
struct xMat3
{
    xMat3();
    void FUN_0043f850(float);
    void FUN_004a0c90(float);
    xMat3 FUN_0043f8d0(const xMat3&) const;
    void SetElement(unsigned int, float, float, float);
    float m[9];
};
extern xMat3 xg_m_11a9448;
struct xFixedStr
{
    xFixedStr(const char*);
    ~xFixedStr();
    const char* m_p;
};
struct xUpdateData
{
    xUpdateData(float, bool, bool);
    float m_t;
    bool m_kPointA, m_kPointB, m_iThirdValue, m_iFourthElementInteger, m_usTrailingValue;
};

struct xBound
{
    float FUN_0084d030();
};
struct xNiMem
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
};

struct xAV
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual struct xAV* GetNode();
    virtual void v4();
    virtual void v5();
    virtual struct xAV* GetGeom();
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
    virtual struct xAV* GetObjectByName(const xFixedStr&);
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
    virtual void AttachChildInAvailableSlot(struct xAV*, bool);
    void NiAVObject_SetScale(float);
    void NiAVObject_Update(const xUpdateData&);
    void SetRotate_0043fa80(const xMat3&);
    void NiAVObject_SetTranslate_004bc1f0(float, float, float);
    void NiAVObject_SetTranslate(const xPoint3&);
    xAV* FUN_0043b4a0(unsigned int);
    xBound* NiAVObject_GetWorldBound();
    void NiAVObject_RemoveProperty(int);
    void NiAVObject_AttachProperty(void*);
};

struct xCam : xAV
{
    xCam();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    void FUN_00712e60(const NiColorA&);
    void NiCamera_SetMinNearPlaneDist(float);
    void NiCamera_SetMaxFarNearRatio(float);
    void FUN_00a6faf0(const ::NiFrustum&);
    int m_auiShapeKeys[(0x114 - 4) / 4];
};
struct xLight : xAV
{
    xLight();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    void SetEffectColor(const xPoint3&);
    void FUN_0050dd50(const xPoint3&);
    void NiLight_SetDimmer(float);
    int m_auiShapeKeys[(0xfc - 4) / 4];
};
struct xAlpha : xNiMem
{
    xAlpha();
    int m_auiShapeKeys[7];
};
struct xGO
{
    xAV* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(void*);
    xAV* m_p;
};
struct xColorMgr
{
    bool FUN_00719060(int, NiColorA&);
};
xColorMgr* xF718b60();
struct ClockSource
{
    unsigned int FUN_00825c00();
};
extern ClockSource xg_timer_11f6394;
struct xIntSetting
{
    int* Setting_Int();
};
extern xIntSetting xg_i_11db4f8;
struct xFltSetting
{
    float* Setting_Float_00403e20();
};
extern xFltSetting xg_f_11db4d0, xg_f_11db544, xg_f_11db570, xg_f_11db5cc, xg_f_11db594, xg_f_1203144, xg_f_1203150,
    xg_f_11db5ec;
struct xLoader
{
    xAV* ModelLoader_LoadFile(const char*, int, bool, bool, bool, bool);
};
extern xLoader* xg_loader_11c3b3c;
struct xT2
{
    const char* RaceSexMenu_GetProjectorFile();
};
struct xT1
{
    xT2* Tile_GetMenu();
};

struct xFarObj
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
    virtual float GetFar();
};

xFarObj* xF45c670();
struct xShadow
{
    void* FUN_00b5ca70(xAV*, float);
    void FUN_00b5c940(xLight*, int);
};
xShadow* xF450b80(int);
int xRand();
void xF4b7660(xAV*);
bool xF707b50();
int xF4dc200();
int xF4dc1f0();
float xF57dd70(float);
void xF709d50(xCam*, float);
int xF40df90();
extern bool xg_b_11f9426;
extern int xg_i_11f9434;

static const char s_szScreen[] = "Screen";
static const char s_szSexBtn[] = "SexBtn:0";
static const char s_szRaceBtn[] = "RaceBtn:0";
static const char s_szFaceBtn[] = "FaceBtn:0";
static const char s_szBodyBtn[] = "BodyBtn:0";
static const char s_szSexGlow[] = "SexGlow:0";
static const char s_szRaceGlow[] = "RaceGlow:0";
static const char s_szFaceGlow[] = "FaceGlow:0";
static const char s_szBodyGlow[] = "BodyGlow:0";
extern const char s_litEnd7fc970[] = "";

struct xRenderedMenu
{
    int m_pad00[0xd8 / 4];
    xGO m_d8, m_dc, m_e0, m_e4, m_e8, m_ec, m_f0, m_f4, m_f8, m_fc;
    int m_100;
    xGO m_104;
    int m_pad108[(0x150 - 0x108) / 4];
    float m_150, m_154;
    bool m_158;
    int m_15c, m_160;
    float m_164, m_168;
    void FORenderedMenu_SetTintColor(const NiColorA&);
    xT1* NiAVObject_GetParent();
    void NiTexturingProperty_Map_SetTexture(xAV*);
    void SetScreenTexture(int);
    void bhkCharacterControllerCinfo_SetAvoidBox(bool);
    void LowProcess_SetEssentialDownTimer(float);
    int FUN_009b6600();
    void SetGo(xCam*);
    void SetScreen(xAV*);
    xAV* SkyObject_GetNiNode();
    void InitTerminalLight();
    void FUN_007fc150();
    void Init();
};

// Initializes the rendered menu by loading the screen model, configuring its transform and camera, and setting up the terminal light.
// @fnv 0x007fc970
void xRenderedMenu::Init()
{
    float qahtre;
    m_158 = false;
    m_168 = (double)xg_timer_11f6394.FUN_00825c00() + xRand() % *xg_i_11db4f8.Setting_Int();
    m_164 = *xg_f_11db4d0.Setting_Float_00403e20();
    NiColorA qHXYKT(0.0f, 0.0f, 0.0f, 0.0f);
    if (xF718b60()->FUN_00719060(3, qHXYKT))
        FORenderedMenu_SetTintColor(qHXYKT);
    xAV* qdqWL = 0;
    if (!m_f8.Modelloader_GetReferencedThis())
    {
        qdqWL = xg_loader_11c3b3c->ModelLoader_LoadFile(NiAVObject_GetParent()->Tile_GetMenu()->RaceSexMenu_GetProjectorFile(), 0, true, false, false,
                                                false);
        m_f8.FUN_0066b0d0(qdqWL);
        xF4b7660(qdqWL);
    }
    else
    {
        qdqWL = m_f8.Modelloader_GetReferencedThis();
    }
    qdqWL->NiAVObject_SetScale(*xg_f_11db544.Setting_Float_00403e20());
    NiTexturingProperty_Map_SetTexture(qdqWL);
    xAV* qSuoDt = qdqWL->GetObjectByName(xFixedStr(s_szScreen));
    SetScreenTexture(0);
    bhkCharacterControllerCinfo_SetAvoidBox(false);
    m_fc.FUN_0066b0d0(0);
    m_104.FUN_0066b0d0(0);
    m_d8.FUN_0066b0d0(qdqWL->GetObjectByName(xFixedStr(s_szSexBtn)));
    m_dc.FUN_0066b0d0(qdqWL->GetObjectByName(xFixedStr(s_szRaceBtn)));
    m_e0.FUN_0066b0d0(qdqWL->GetObjectByName(xFixedStr(s_szFaceBtn)));
    m_e4.FUN_0066b0d0(qdqWL->GetObjectByName(xFixedStr(s_szBodyBtn)));
    m_e8.FUN_0066b0d0(qdqWL->GetObjectByName(xFixedStr(s_szSexGlow)));
    m_ec.FUN_0066b0d0(qdqWL->GetObjectByName(xFixedStr(s_szRaceGlow)));
    m_f0.FUN_0066b0d0(qdqWL->GetObjectByName(xFixedStr(s_szFaceGlow)));
    m_f4.FUN_0066b0d0(qdqWL->GetObjectByName(xFixedStr(s_szBodyGlow)));
    m_150 = 0.0f;
    m_154 = 0.0f;
    LowProcess_SetEssentialDownTimer(0.0f);
    xMat3 qpqRa;
    xMat3 qjXCGmG;
    qpqRa.FUN_0043f850(1.57f);
    qjXCGmG.FUN_004a0c90(1.57f);
    qdqWL->SetRotate_0043fa80(qjXCGmG.FUN_0043f8d0(qpqRa));
    float qhxpxJd = 0.0f;
    if (FUN_009b6600() == 1 || FUN_009b6600() == 0)
        qhxpxJd = 80.0f;
    else
        qhxpxJd = *xg_f_11db570.Setting_Float_00403e20();
    if (!xF707b50() && !xg_b_11f9426)
        qhxpxJd *= 0.75;
    if (FUN_009b6600() == 1 || FUN_009b6600() == 0)
        qdqWL->NiAVObject_SetTranslate_004bc1f0(qhxpxJd, 0.0f, *xg_f_11db5cc.Setting_Float_00403e20());
    else
        qdqWL->NiAVObject_SetTranslate_004bc1f0(qhxpxJd, *xg_f_11db594.Setting_Float_00403e20(), *xg_f_11db5cc.Setting_Float_00403e20());
    xUpdateData qsSDDgz(0.0f, false, false);
    qdqWL->NiAVObject_Update(qsSDDgz);
    xCam* qSVM = new xCam();
    NiColorA qrEZrs(0.0f, 1.0f, 1.0f, 0.0f);
    qSVM->FUN_00712e60(qrEZrs);
    xMat3 qbGYp;
    qbGYp.SetElement(0, 0.0f, 0.0f, 1.0f);
    qbGYp.SetElement(1, 1.0f, 0.0f, 0.0f);
    qbGYp.SetElement(2, 0.0f, 1.0f, 0.0f);
    qSVM->SetRotate_0043fa80(xg_m_11a9448);
    qSVM->NiCamera_SetMinNearPlaneDist(1.0f);
    ::NiFrustum qnuVZg;
    qnuVZg.Init(false);
    qnuVZg.m_fFarPlane = xF45c670()->GetFar();
    qnuVZg.m_fNearPlane = *xg_f_1203144.Setting_Float_00403e20();
    qSVM->NiCamera_SetMaxFarNearRatio(qnuVZg.m_fFarPlane / qnuVZg.m_fNearPlane);
    float qvyWyw = (float)(xg_b_11f9426 ? xg_i_11f9434 : xF4dc200()) / xF4dc1f0();
    float qkbsJ = 0.75f;
    qahtre = *xg_f_1203150.Setting_Float_00403e20() * 0.01745329238474369 * *xg_f_11db5ec.Setting_Float_00403e20();
    qnuVZg.m_fLeftBound = -xF57dd70(qahtre) * qkbsJ;
    qnuVZg.m_fRightBound = xF57dd70(qahtre) * qkbsJ;
    qnuVZg.m_fBottomBound = -xF57dd70(qahtre) * qvyWyw * qkbsJ;
    qnuVZg.m_fTopBound = xF57dd70(qahtre) * qvyWyw * qkbsJ;
    qnuVZg.m_bOrthographic = false;
    qSVM->FUN_00a6faf0(qnuVZg);
    xF709d50(qSVM, *xg_f_11db5ec.Setting_Float_00403e20());
    xUpdateData qfTOqo(0.0f, false, false);
    qSVM->NiAVObject_Update(qfTOqo);
    SetGo(qSVM);
    if (qSuoDt->GetGeom())
        SetScreen(qSuoDt->GetGeom());
    else if (qSuoDt->GetNode())
        SetScreen(qSuoDt->GetNode()->FUN_0043b4a0(0)->GetGeom());
    NiTexturingProperty_Map_SetTexture(qdqWL);
    SkyObject_GetNiNode()->NiAVObject_RemoveProperty(xF40df90());
    SkyObject_GetNiNode()->NiAVObject_AttachProperty(new xAlpha());
    float qzzQr = qdqWL->NiAVObject_GetWorldBound()->FUN_0084d030() * 3.0;
    void* qpTd = xF450b80(1)->FUN_00b5ca70(qdqWL, qzzQr);
    if (!qpTd)
    {
        xLight* PLIGHT = new xLight();
        qdqWL->AttachChildInAvailableSlot(PLIGHT, true);
        PLIGHT->NiAVObject_SetTranslate(xPoint3(0.0f, -50.0f, 0.0f));
        PLIGHT->SetEffectColor(xPoint3(0.75f, 0.75f, 0.75f));
        PLIGHT->FUN_0050dd50(xPoint3(1000.0f, 0.0f, 0.0f));
        PLIGHT->NiLight_SetDimmer(1.0f);
        xUpdateData UPD3(0.0f, false, false);
        PLIGHT->NiAVObject_Update(UPD3);
        xF450b80(1)->FUN_00b5c940(PLIGHT, 0);
        InitTerminalLight();
    }
    FUN_007fc150();
}

namespace fnv_007fe1f0 {

struct RtTexture;
struct RtTarget
{
    RtTexture* BSTextureManager_BorrowRenderedTexture(int iFlags, int a2, int a3, int a4);
    void BSTextureManager_ReturnRenderedTexture();
};
struct RtRenderer
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
    virtual void SetBackgroundColor(const NiColorA& kColor);
    virtual void v044();
    virtual void SetBorderColor(const NiColorA& kColor);
};
RtRenderer* __cdecl NiXenonRenderer_GetRenderer();
RtTarget* __stdcall BSShaderManager_GetTextureManager(void* pkObject);

template <class T> struct RtPtr
{
    T* m_pObject;
    RtPtr(T* pObject);
    ~RtPtr();
    T* Modelloader_GetReferencedThis() const;
    RtPtr& FUN_0066b0d0(T* pObject);
};

struct RtTextureData
{
    void* FUN_00b6b260();
};
struct RtTexture : RtTextureData
{
};

struct RtAccum
{
    int unk00[0xc4 / 4];
    RtAccum(int iUnk);
    ~RtAccum();
    void BSCullingProcess_SetAccumulator(RtTexture* pkTexture);
    void BSCullingProcess_PushCullMode(int i);
    void BSCullingProcess_PopCullMode();
};

struct RtSource
{
    RtTexture* RaceSexMenu_GetProjectorFile();
};
RtSource* __cdecl InterfaceManager_GetSingleton();
void __cdecl BSRenderedTexture_StartOffscreen(int i, void* pkData);
void* __cdecl FUN_00450b80(int i);
void __cdecl BSShaderUtil_AccumulateScene(void* pkNode, void* pkCamera, RtAccum* pkAccum);
void __cdecl FUN_00b6c0d0(void* pkNode, RtTexture* pkTexture, int i);
void __cdecl FUN_00b6b790();

struct RtNode;
struct RenderToTextureImpl
{
    char pad000[0x104];
    RtPtr<RtNode> m_spScene;

    const NiColorA& GetBackTexture();
    void Render_007fba00(int a1, int a2, RtTexture* pkTexture);
    void FORenderedMenuRaceSex_Draw(int a1, int a2, int a3);
};

// Sets a render target and background color, processes m_spScene through render calls, then passes the target to FUN_007fba00.
// @fnv 0x007fe1f0
// src: COMMUNITY 0x007fe1f0
void RenderToTextureImpl::FORenderedMenuRaceSex_Draw(int aiUnk, int aiUnk2, int aiUnk3)
{
    bool bOverrideTmp = false;
    bOverrideTmp = true;
    RtRenderer* pkRendererY = NiXenonRenderer_GetRenderer();
    RtPtr<RtTexture> spTarget5(BSShaderManager_GetTextureManager(NiXenonRenderer_GetRenderer())->BSTextureManager_BorrowRenderedTexture(0x30, 0, 0, 0));
    NiColorA kKBorder(0.0f, 0.0f, 0.0f, 0.0f);
    NiColorA kBackgroundVal2(0.0f, 0.0f, 0.0f, 0.0f);
    kBackgroundVal2 = GetBackTexture();
    kBackgroundVal2.a = 1.0f;
    if (bOverrideTmp)
        kBackgroundVal2 = NiColorA(0.125f, 0.161f, 0.141f, 1.0f);
    pkRendererY->SetBorderColor(kKBorder);
    pkRendererY->SetBackgroundColor(kBackgroundVal2);
    BSRenderedTexture_StartOffscreen(7, spTarget5.Modelloader_GetReferencedThis()->FUN_00b6b260());
    RtAccum kAccumRes(0);
    RtPtr<RtTexture> spSource9(InterfaceManager_GetSingleton()->RaceSexMenu_GetProjectorFile());
    kAccumRes.BSCullingProcess_SetAccumulator(spSource9.Modelloader_GetReferencedThis());
    kAccumRes.BSCullingProcess_PushCullMode(1);
    BSShaderUtil_AccumulateScene(m_spScene.Modelloader_GetReferencedThis(), FUN_00450b80(3), &kAccumRes);
    FUN_00b6c0d0(m_spScene.Modelloader_GetReferencedThis(), spSource9.Modelloader_GetReferencedThis(), 0);
    kAccumRes.BSCullingProcess_PopCullMode();
    kAccumRes.BSCullingProcess_SetAccumulator(0);
    spSource9.FUN_0066b0d0(0);
    FUN_00b6b790();
    Render_007fba00(aiUnk, 0, spTarget5.Modelloader_GetReferencedThis());
    BSShaderManager_GetTextureManager(spTarget5.Modelloader_GetReferencedThis())->BSTextureManager_ReturnRenderedTexture();
    spTarget5.FUN_0066b0d0(0);
}
}  // namespace fnv_007fe1f0
