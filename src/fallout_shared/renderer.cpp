// fallout_shared/renderer.cpp: Renderer, Setting (13 functions)
#include "../../include/NiColorA.h"

#include "renderer_decls.h"
#include "../../include/GO.h"
#include "../../include/Setting.h"
#include "../../include/SettingT_GameSettingCollection_.h"

// Stores color into DAT_011c74b8 and, if FUN_004bc3f0() succeeds, passes a copy with alpha 0.0f to its SetBackgroundColor (slot 43) and returns true.
// @fnv 0x004dce50
bool Renderer::SetBackgroundColor(NiColor& color)
{
    DAT_011c74b8 = color;
    if (Renderer_GetNIRenderer())
    {
        NiColorA background(0.0f, 0.0f, 0.0f, 0.0f);
        background.r = DAT_011c74b8.r;
        background.g = DAT_011c74b8.g;
        background.b = DAT_011c74b8.b;
        background.a = 0.0f;
        Renderer_GetNIRenderer()->SetBackgroundColor(reinterpret_cast<NiVector4*>(&background)); // slot 43 (+0xac)
        return true;
    }
    return false;
}

// Returns true when DAT_011c70e9 is unset or FUN_005d4a40 returns true.
// @fnv 0x00452540
bool Renderer::CanRender()
{
    return !DAT_011c70e9 || Cmd_Default_Execute();
}

double __cdecl FUN_00ec9ac0(double, double);

// Returns the result of FUN_00ec9ac0(_X, _Y) cast to float.
// @fnv 0x004dd150
// src: XBOX_PDB 0x004dd150
float __cdecl powf_004dd150(float _X, float _Y)
{
    return (float)FUN_00ec9ac0(_X, _Y);
}

// Renderer setting operations not yet declared by the shared Setting header.
struct RendererSetting : public Setting
{
    void SetValue(float);
    RendererSetting* ProcessAndReturnValue_004ed780(float f);
    void Setting_SetValueB(int);
};
// @fnv 0x004ed780
// src: GUESS 0x004ed780 (confidence: low)
RendererSetting* RendererSetting::ProcessAndReturnValue_004ed780(float f)
{
    SetValue(f);
    return this;
}

struct FUN_004da650_shell
{
    void* GetFieldAt204();
};

// @fnv 0x004da650
void* FUN_004da650_shell::GetFieldAt204()
{
    return reinterpret_cast<char*>(this) + 0x204;
}

extern "C" void* __cdecl NiDX9SystemDesc_Get(void);
extern "C" void* DAT_011c70dc;

// @fnv 0x004dce30
// src: COMMUNITY 0x004dce30
void* __cdecl TESRenderer_GetSystemDesc()
{
    if (DAT_011c70dc == 0)
        DAT_011c70dc = NiDX9SystemDesc_Get();
    return DAT_011c70dc;
}

namespace fnv_004dd130 {
extern "C" float __cdecl powf_004dd150(float, float);

// @fnv 0x004dd130
// src: XBOX_PDB 0x004dd130
float pow_004dd130(float a, float b)
{
    return powf_004dd150(a, b);
}
}  // namespace fnv_004dd130

namespace fnv_004dcdb0 {
struct Flt
{
    operator unsigned int();
    unsigned int GetElementOrZero(unsigned int);
};
void* __cdecl TESRenderer_GetSystemDesc();
extern Flt* DAT_011c70dc;
// Returns the value at index a1 from DAT_011c70dc when FUN_004dce30() succeeds and a1 is in range, otherwise 0.
// @fnv 0x004dcdb0
unsigned int __cdecl GetFltValueAt(unsigned int auiIndex)
{
    unsigned int uiValue;
    if (TESRenderer_GetSystemDesc() && auiIndex < (unsigned int)*DAT_011c70dc)
        uiValue = DAT_011c70dc->GetElementOrZero(auiIndex);
    else
        uiValue = 0;
    return uiValue;
}
}  // namespace fnv_004dcdb0

struct ShaderReference
{
    unsigned int _ref_00726070();
};

GO g_011c73b4;

void __cdecl BSShaderManager_Free(bool);
void __cdecl MessageHandler_ForceNextWarningToDisplay();
void __cdecl _FNV_Warning(const char*, ...);

// Calls FUN_00b54630, and on final kill releases the renderer via FUN_00461300, warning if smart pointers remain, then clears g_011c73b4.
// @fnv 0x004da4d0
// src: XBOX_PDB 0x004da4d0
void __cdecl Renderer_Kill(bool abFinalKill)
{
    BSShaderManager_Free(abFinalKill);

    if (abFinalKill)
    {
        if (g_011c73b4.operator unsigned int() && reinterpret_cast<ShaderReference*>(g_011c73b4.operator unsigned int())->_ref_00726070() != 1)
        {
            MessageHandler_ForceNextWarningToDisplay();

            if (reinterpret_cast<ShaderReference*>(g_011c73b4.operator unsigned int())->_ref_00726070() == 2)
            {
                _FNV_Warning(
                    "SHADERS: There is 1 object with a smart pointer to the renderer we are trying to release.");
            }
            else
            {
                _FNV_Warning(
                    "SHADERS: There are %d objects with smart pointers to the renderer we are trying to release.",
                    reinterpret_cast<ShaderReference*>(g_011c73b4.operator unsigned int())->_ref_00726070() - 1);
            }
        }
    }

    g_011c73b4.operator=(0);
}

namespace fnv_004da570 {
struct FUN_004da650_shell
{
    void* GetFieldAt204();
};

struct TgtOps : public FUN_004da650_shell
{
    void* GetPosition();
};

extern Setting g_011c72c0;
extern char DAT_01021184[];

void* __cdecl TESRenderer_GetSystemDesc();
TgtOps* __cdecl GetFltValueAt(int);
char* __cdecl ___insecure_strcpy(char*, char const*);
char* __cdecl FUN_00ec6380(char*, char const*);
int __cdecl __stricmp(char const*, char const*);

// @fnv 0x004da570
// src: COMMUNITY 0x004da570
bool __cdecl ProcessCustomINI()
{
    char buffer[260];

    if (TESRenderer_GetSystemDesc())
    {
        TgtOps* target = GetFltValueAt(0);
        if (target)
        {
            char const* pcMenuState = static_cast<char const*>(target->GetFieldAt204());
            {
                void* position = target->GetPosition();
            }

            if (__stricmp(g_011c72c0.String(), pcMenuState) != 0)
                return true;
        }
    }

    ___insecure_strcpy(buffer, DAT_01021184);
    FUN_00ec6380(buffer, g_011c72c0.String());
    FUN_00ec6380(buffer, DAT_01021184);
    g_011c72c0.AssignStringValue(buffer);
    return false;
}
}  // namespace fnv_004da570

struct GRRamp
{
    unsigned short red[256];
    unsigned short green[256];
    unsigned short blue[256];
};

struct GRDevice
{
    virtual long __stdcall v00();
    virtual long __stdcall v04();
    virtual long __stdcall v08();
    virtual long __stdcall v0C();
    virtual long __stdcall v10();
    virtual long __stdcall v14();
    virtual long __stdcall v18();
    virtual long __stdcall v1C();
    virtual long __stdcall v20();
    virtual long __stdcall v24();
    virtual long __stdcall v28();
    virtual long __stdcall v2C();
    virtual long __stdcall v30();
    virtual long __stdcall v34();
    virtual long __stdcall v38();
    virtual long __stdcall v3C();
    virtual long __stdcall v40();
    virtual long __stdcall v44();
    virtual long __stdcall v48();
    virtual long __stdcall v4C();
    virtual long __stdcall v50();
    virtual long __stdcall SetGammaRamp(unsigned int auiSwapChain, unsigned long aulFlags, const GRRamp* apRamp);
};

struct GRRenderer
{
    GRDevice* GetD3DDevice();
};

struct GRRendererPtr
{
    operator GRRenderer*() const;
};

float __cdecl GRApplyGamma(float afValue, float afGamma);

extern bool g_bGRGammaDirty;
extern float g_fGRGamma;
extern RendererSetting g_kGRGammaSetting;
extern GRRendererPtr g_spGRRenderer;

// Clears the gamma-dirty flag, stores g_fGRGamma, builds a 256-entry gamma ramp via GRApplyGamma and applies it to swap chain 0 with SetGammaRamp.
// @fnv 0x004dcef0
void __cdecl ApplyGammaRamp()
{
    GRRamp kRamp4;
    unsigned short i;

    g_bGRGammaDirty = false;
    g_kGRGammaSetting.ProcessAndReturnValue_004ed780(g_fGRGamma);
    for (i = 0; i < 256; i++)
    {
        kRamp4.red[i] = (unsigned short)(GRApplyGamma((float)(i / 255.0), g_fGRGamma) * 65535.0 + 0.5);
        kRamp4.green[i] = (unsigned short)(GRApplyGamma((float)(i / 255.0), g_fGRGamma) * 65535.0 + 0.5);
        kRamp4.blue[i] = (unsigned short)(GRApplyGamma((float)(i / 255.0), g_fGRGamma) * 65535.0 + 0.5);
    }
    ((GRRenderer*)g_spGRRenderer)->GetD3DDevice()->SetGammaRamp(0, 1, &kRamp4);
}

#include <string.h>
struct P03MM
{
    void* Allocate(unsigned int);
    void _DeallocateAlias(void*);
};
extern P03MM _g_memoryManager;

// Copies apString to the string value; if pKey exists, copies it into a new buffer, changes its first byte to 'S', and frees old pKey only when it starts with 'S'.
// @fnv 0x00c33170
// src: GUESS 0x00c33170 (confidence: medium)
Setting& Setting::SetStringAndPromoteKeyOwnership(const char* apString)
{
    if (this)
    {
        unsigned int ikeyLen;
        {
            unsigned int ilen;
            {
                char* pstr;
                {
                    char* cp;
                    {
                        void* pmem;
                        {
                            char* pold;
                            {
                                const char* pkey;
                                {
                                    const char* psrc;
                                    ikeyLen = pKey ? (pkey = pKey, strlen(pkey) + 1) : 0;
                                    if (apString)
                                    {
                                        ilen = strlen(apString) + 1;
                                        pmem = _g_memoryManager.Allocate(ilen + ikeyLen);
                                        pstr = (char*)pmem;
                                        if (pstr)
                                        {
                                            cp = pstr + ikeyLen;
                                            strcpy(cp, apString);
                                            *reinterpret_cast<const char**>(&uValue) = cp;
                                            if (ikeyLen)
                                            {
                                                psrc = pKey;
                                                strcpy_s(pstr, ikeyLen, psrc);
                                                *pstr = 'S';
                                                if (*pKey == 'S')
                                                {
                                                    pold = const_cast<char*>(pKey);
                                                    _g_memoryManager._DeallocateAlias(pold);
                                                }
                                                pKey = pstr;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        *reinterpret_cast<const char**>(&uValue) = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return *this;
}

namespace fnv_004da670 {
struct S4eb0
{
    int context;
    S4eb0(int, bool, const char*, int);
    ~S4eb0();
};
struct RendObj;
struct Rect4
{
    int a;
    int b;
    int c;
    int d;
};
char* __cdecl BSUtilities_GetPersonalPath();
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
void* __cdecl FUN_00ec9a47(const char*, const char*);
extern "C" int __cdecl _fclose(void*);
bool __cdecl is_bEyeFinity();
float __cdecl Get_1280();
float __cdecl Get_720();
void __cdecl InitEyefinityDisplayInfo();
bool __cdecl TESRenderer_ValidateSettings(int);
int __cdecl Renderer_GetScreenWidth();
int __cdecl Renderer_GetScreenHeight();
int __cdecl TESRenderer_GetHWND();
int __cdecl TESRenderer_GetAdapterIndex();
int __cdecl TESRenderer_GetFlags();
int __cdecl TESRenderer_GetDeviceType();
int __cdecl TESRenderer_GetSwapEffect();
int __cdecl TESRenderer_GetBackBufferCount();
int __cdecl TESRenderer_GetRefreshRate();
int __cdecl TESRenderer_GetFrameBufferFormat();
int __cdecl TESRenderer_GetDepthStencilFormat();
int __cdecl TESRenderer_GetFrameBufferMode();
int __cdecl TESRenderer_GetPresentInterval();
bool __cdecl DispatchFormValue(int, int);
int __cdecl FUN_00b4f4a0();
int __cdecl FUN_00ec9774(void*, const char*, ...);
int __cdecl FUN_00e76210(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
__declspec(dllimport) int __stdcall IMP_fdf2b8(int, int, int, int, int, int, int, int, int, int, int, int);
__declspec(dllimport) int __stdcall IMP_fdf2ec(int, int);
__declspec(dllimport) int __stdcall IMP_fdf2e8(int, int, int);
__declspec(dllimport) int __stdcall IMP_fdf310(void*, int);
__declspec(dllimport) int __stdcall IMP_fdf2a4(int, int, int, int, int, int, int);
__declspec(dllimport) int __stdcall IMP_fdf2b0(int);
extern int DAT_011c6fc0;
extern int DAT_011c6fc4;
extern int DAT_011c6fb0;
extern int DAT_011c6fbc;
extern int DAT_0118947c;
extern int DAT_01189480;
extern int DAT_01189478;
extern int DAT_011a2fe8;
extern int DAT_011c70cc;
extern SettingT_GameSettingCollection_ DAT_011c7628;
extern SettingT_GameSettingCollection_ DAT_011c7418;
extern Setting DAT_011c73dc;
extern Setting DAT_011c718c;
extern Setting DAT_011c73f4;
extern Setting DAT_011c7654;
extern Setting DAT_011c75d4;
extern Setting DAT_011c771c;
extern Setting DAT_011c77b4;
extern SettingT_GameSettingCollection_ DAT_011c76c0;
extern RendererSetting DAT_011c7790;
extern unsigned char DAT_011f9421;
extern char DAT_01021568;
extern char DAT_01021518;
extern GO DAT_011c73b4;
extern char DAT_0102156c;

struct DevObj
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual int __stdcall vfn_28(int, int, int, int, int, int);
};
struct RendObj
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0(unsigned int);
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual int __stdcall vfn_13c(float);
    RendObj* NiXenonRenderer_GetD3DDevice();
    static DevObj* NiDX9Renderer_GetDirect3D();
};
struct ShaderInitializer
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
    int unk48c33V3;
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
    ShaderInitializer();
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct Sub130
{
    int unk000;
    int unk004;
    int unk008;
    unsigned int f0c;
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
    int f3c;
    unsigned int f40;
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
    int fc4;
    int unk0c8;
    int fcc;
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
    int f110;
    int unk114;
    short f118;
};
struct DbcObj
{
    void* GetFieldAt204();
    void* FUN_00717e50();
    Sub130* NiXAdapaterDesc_GetDeviceCaps_004dc120(int);
};
void* __cdecl Object_DispatchCommandFour(unsigned int);
void __cdecl AssignImageConverter(void*);
void __cdecl NiSourceTexture_SetUsePreloading(bool);
int __cdecl NiTexture_SetMipmapByDefault(int);
DbcObj* __cdecl GetFltValueAt(int);
int __cdecl BSShaderManager_kBackgroundColor_Get();
int __cdecl TESRenderer_GetNPatchSegments();
void __cdecl CopyStringToGlobal(const char*);
void __stdcall D3DPERF_SetOptions_009f9968(int);
extern char DAT_010214e4;
extern char DAT_010214c8;
extern char DAT_0102149c;
extern unsigned char DAT_011c6fba;
extern bool DAT_011c6fb9;
extern unsigned char DAT_011c70ea;
extern unsigned char DAT_011f941f;
extern bool DAT_011f9420;
extern unsigned char DAT_011f9183;
extern unsigned char DAT_011f9426;
extern unsigned char DAT_011c70ec;
extern int DAT_011ad810;
extern int DAT_011ad814;
extern int DAT_011ad818;
extern int DAT_0126efc4;
extern int DAT_0126efc8;
extern SettingT_GameSettingCollection_ DAT_011c7284;
extern SettingT_GameSettingCollection_ DAT_011c7784;
extern SettingT_GameSettingCollection_ DAT_011c7680;
extern SettingT_GameSettingCollection_ DAT_011c779c;
extern SettingT_GameSettingCollection_ DAT_011c7254;
extern SettingT_GameSettingCollection_ DAT_011c7538;
extern SettingT_GameSettingCollection_ DAT_011c747c;
extern SettingT_GameSettingCollection_ DAT_011c75b0;
extern SettingT_GameSettingCollection_ DAT_011c7768;
extern SettingT_GameSettingCollection_ DAT_011c73a4;
extern SettingT_GameSettingCollection_ DAT_011c74e0;
extern SettingT_GameSettingCollection_ DAT_011c7520;
extern SettingT_GameSettingCollection_ DAT_011c72d8;
extern SettingT_GameSettingCollection_ DAT_011c72e4;
extern SettingT_GameSettingCollection_ DAT_011c7504;
extern RendererSetting DAT_011c71dc;
extern unsigned char DAT_011f941e;
extern unsigned char DAT_011f94a8;
extern unsigned char DAT_011f94a9;
extern unsigned char DAT_011f9422;
extern unsigned char DAT_011f91a3;
extern unsigned char DAT_011f9440;
extern unsigned char DAT_011f9181;
extern unsigned char DAT_011c70eb;

extern int DAT_011f9430;
extern int DAT_011f9434;
extern int DAT_0118946c;
extern int DAT_01189468;
extern NiColorA DAT_011ad840;
extern NiColorA DAT_011f961c;
int __cdecl DetectGpuVendor(int, int, int, void*, void*, int);
int __cdecl FUN_004dc060(int);
int __cdecl BSRenderState_GetGPUVendor();
void __cdecl BSShaderManager_SetMaxShadowMaps(int);
int __cdecl BSMAX_00647b70(int, int);
void __cdecl BSShaderManager_EnableUseRefractionShader(int);
bool __cdecl TESRenderer_GetMultiSampleEnabled();
int __cdecl FUN_009fea2a();
int __cdecl Runtime_ForwardCall_009fead0(int, int*);
int __cdecl FUN_009fead6(int, int*);
int __cdecl FUN_009feae8(int*, unsigned int*);
int __cdecl Object_ForwardCall_009feae2(int*, unsigned int*);
int __cdecl FUN_009febd8(void*, int*);
void* __cdecl NiXenonRenderer_GetRenderer();
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
struct DriverVersion
{
    int version;
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
};
struct DevInfo
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
};
struct Unk48c
{
    int f0;
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
};
struct Ver654
{
    int f0;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};
typedef int(__cdecl* Fn0)();
__declspec(dllimport) void* __stdcall IMP_fdf0b0(const char*);
__declspec(dllimport) void* __stdcall IMP_fdf0ac(void*, const char*);
__declspec(dllimport) void* __stdcall IMP_fdf0a8(void*);
extern char DAT_0102148c;
extern char DAT_01021478;
extern char DAT_011f9194[15];
extern unsigned char DAT_011ad832;
extern char DAT_01021570;
extern char DAT_01021450;
extern char DAT_01021434;
extern char DAT_01021418;
extern char DAT_010213fc;
extern char DAT_010213e0;
extern char DAT_010213c4;
extern char DAT_010213a8;
extern char DAT_0102138c;
extern unsigned char DAT_011f94a4;
extern unsigned char DAT_011f94a6;
extern char DAT_01021388;
extern char DAT_01021384;
extern char DAT_01021368;
extern char DAT_0102134c;
extern char DAT_01021330;
extern char DAT_01021314;
extern char DAT_010212f8;
extern char DAT_010212dc;
extern char DAT_010212c0;
extern char DAT_010212a4;
extern char DAT_01021284;
extern char DAT_01021268;
extern char DAT_0102124c;
extern char DAT_01021230;
extern char DAT_01021214;
extern char DAT_010211f8;
extern char DAT_010211dc;
extern char DAT_010211c0;
extern char DAT_010211a4;
extern char DAT_01021188;
extern Setting DAT_011c7b20;
extern Setting DAT_011c7b6c;
extern Setting DAT_011c7ac4;
extern Setting DAT_011c7b48;
extern SettingT_GameSettingCollection_ DAT_011c3ea4;
bool __cdecl BSShaderManager_GetUseRefractionShader();
int __cdecl ShaderBuffer_GetCurrentBufferType();
void __cdecl FUN_00ec9907(void*);
extern int DAT_011ad830;
extern SettingT_GameSettingCollection_ DAT_011c752c;
extern int DAT_011f91b0;
extern int DAT_011f9490;
extern float DAT_011f9190;
extern float DAT_011f918c;
extern float DAT_011f9188;
extern float DAT_011f9444;
extern float DAT_011f9448;
extern float DAT_011f944c;
extern float DAT_011f9450;
extern float DAT_011f9454;
extern float DAT_011f9458;
extern float DAT_011f945c;
extern float DAT_011f9460;
extern float DAT_011f9464;
extern float DAT_011f9468;
extern float DAT_011f946c;
extern float DAT_011f9470;
extern float DAT_011f9474;
extern float DAT_011f9478;
extern float DAT_011f9428;
extern float DAT_011ad834;
extern float DAT_011ad838;

extern unsigned char DAT_011f9488;
extern unsigned char DAT_011f9489;
extern unsigned char DAT_011f94b4;
extern unsigned char DAT_011f9425;
extern unsigned char DAT_011f948a;
extern SettingT_GameSettingCollection_ DAT_011c7610;
extern SettingT_GameSettingCollection_ DAT_011c710c;
extern SettingT_GameSettingCollection_ DAT_011c7774;
extern SettingT_GameSettingCollection_ DAT_011c7308;
extern SettingT_GameSettingCollection_ DAT_011c76cc;
extern Setting DAT_011c7488;
extern Setting DAT_011c7170;
extern Setting DAT_011c7574;
extern Setting DAT_011c7510;
extern Setting DAT_011c7740;
extern Setting DAT_011c76b4;
extern Setting DAT_011c7568;
extern Setting DAT_011c7400;
extern Setting DAT_011c7598;
extern Setting DAT_011c7634;
extern Setting DAT_011c7374;
extern Setting DAT_011c73e8;
extern Setting DAT_011c7160;
extern Setting DAT_011c72f0;
extern Setting DAT_011c72cc;
extern Setting DAT_011c7428;
extern Setting DAT_011c72fc;
extern Setting DAT_011c7344;
extern Setting DAT_011c735c;
extern Setting DAT_011c7464;
extern Setting DAT_011c75e0;
extern Setting DAT_011c73d0;
extern Setting DAT_011c77cc;
extern Setting DAT_011c75f8;
void __cdecl SetBSStringCapacity(int);

extern Setting DAT_011c71ac;
void __cdecl Renderer_SetGamma(float);
int __cdecl FUN_00b4f3e0();
int __cdecl FUN_00b4f380(int);

// Initializes the renderer device, queries GPU capabilities, writes RendererInfo.txt, and caches float/bool settings into globals.
// @fnv 0x004da670
// src: EXE 0x004da670
int __cdecl NiXAdapaterDesc_GetDeviceCaps(int aiWidth, int aiHeight)
{
    S4eb0 tracker10(4, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Renderer.cpp", 377);
    DAT_011c6fc0 = aiWidth;
    DAT_011c6fc4 = aiHeight;
    char buf21[260];
    _sprintf_s(buf21, 260, "%sRendererInfo.txt", BSUtilities_GetPersonalPath());
    void* file32 = FUN_00ec9a47(buf21, (const char*)&DAT_0102156c);
    if (file32 != 0)
    {
        _fclose(file32);
    }
    DAT_011c6fb0 = *DAT_011c7628.Setting_Int();
    DAT_0118947c = DAT_011c73dc.GetUInt();
    DAT_01189480 = DAT_011c718c.GetUInt();
    if (DAT_011c771c.GetBoolValue())
    {
        InitEyefinityDisplayInfo();
    }
    if (is_bEyeFinity())
    {
        DAT_0118947c = (unsigned int)Get_1280();
        DAT_01189480 = (unsigned int)Get_720();
        DAT_011c73f4.ProcessAndReturnValue_0045ce80((*DAT_011c73f4.Int() < 2) ? *DAT_011c73f4.Int() : 2);
    }
    if (TESRenderer_ValidateSettings(1))
    {
        if (DAT_011c77b4.GetBoolValue())
        {
            DAT_01189478 |= 4;
            DAT_011c6fbc = DAT_011c6fc0;
        }
        else
        {
            DAT_011c6fbc = IMP_fdf2b8(0, DAT_011a2fe8, 0, 0x50000000, 0, 0, Renderer_GetScreenWidth(), Renderer_GetScreenHeight(),
                                      DAT_011c6fc0, 0, DAT_011c6fc4, 0);
            Rect4 rect13;
            rect13.a = 0;
            rect13.b = 0;
            rect13.c = Renderer_GetScreenWidth();
            rect13.d = Renderer_GetScreenHeight();
            IMP_fdf310(&rect13, IMP_fdf2e8(DAT_011c6fc0, -16, IMP_fdf2ec(DAT_011c6fbc, -8)));
            int w3 = rect13.c - rect13.a;
            int h11 = rect13.d - rect13.b;
            IMP_fdf2a4(DAT_011c6fc0, 0, DAT_011c75d4.GetUInt(), DAT_011c7654.GetUInt(), w3, h11, 0x40);
        }
        DAT_011c70cc = 0;
        if (*DAT_011c7418.FUN_00408d60())
        {
            if (DAT_011c70cc == 0)
            {
                DAT_011c70cc = 1;
            }
        }
        bool flag2 = false;
        if (DAT_011c77b4.GetBoolValue())
        {
            if (IMP_fdf2b0(0x50) > 1)
            {
                int t113 = IMP_fdf2b0(1);
                int t212 = IMP_fdf2b0(0);
                if (t113 != Renderer_GetScreenHeight())
                {
                    flag2 = true;
                }
                else if (t212 != Renderer_GetScreenWidth())
                {
                    flag2 = true;
                }
            }
        }
        DAT_011c73b4.operator=(reinterpret_cast<void*>(FUN_00e76210(Renderer_GetScreenWidth(), Renderer_GetScreenHeight(), TESRenderer_GetFlags(), TESRenderer_GetHWND(),
                                               TESRenderer_GetHWND(), TESRenderer_GetAdapterIndex(), TESRenderer_GetDeviceType(), TESRenderer_GetFrameBufferFormat(),
                                               TESRenderer_GetDepthStencilFormat(), TESRenderer_GetPresentInterval(), TESRenderer_GetSwapEffect(), TESRenderer_GetFrameBufferMode(),
                                               TESRenderer_GetBackBufferCount(), TESRenderer_GetRefreshRate(), flag2)));
    }
    else
    {
        return 0;
    }
    if (*DAT_011c73f4.Int() > 0)
    {
        if (DispatchFormValue(*DAT_011c73f4.Int(), 0x71) || !*DAT_011c76c0.FUN_00408d60())
        {
            switch (DAT_011c73f4.GetUInt())
            {
            default:
                DAT_011c70cc = 0;
                break;
            case 2:
            case 3:
                DAT_011c70cc = 2;
                break;
            case 4:
                DAT_011c70cc = 4;
                break;
            case 8:
                DAT_011c70cc = 8;
                break;
            }
        }
        else
        {
            int ft = FUN_00b4f4a0();
            (void)ft;
            _sprintf_s(buf21, 260, "%sRendererInfo.txt", BSUtilities_GetPersonalPath());
            file32 = FUN_00ec9a47(buf21, (const char*)&DAT_01021568);
            if (file32 != 0)
            {
                FUN_00ec9774(file32, (const char*)&DAT_01021518, *DAT_011c73f4.Int());
            }
            DAT_011c7790.Setting_SetValueB(0);
            DAT_011f9421 = 0;
        }
    }
    if (reinterpret_cast<RendObj*>(DAT_011c73b4.operator unsigned int()) != 0)
    {
        reinterpret_cast<RendObj*>(DAT_011c73b4.operator unsigned int())->vfn_b0(BSShaderManager_kBackgroundColor_Get());
        if (DAT_011c6fba != 0)
        {
            RendObj* sub = reinterpret_cast<RendObj*>(DAT_011c73b4.operator unsigned int())->NiXenonRenderer_GetD3DDevice();
            if (sub != 0)
            {
                sub->vfn_13c((float)TESRenderer_GetNPatchSegments());
            }
        }
    }
    else
    {
        CopyStringToGlobal((const char*)&DAT_010214e4);
        return 0;
    }
    AssignImageConverter(new ShaderInitializer);
    NiSourceTexture_SetUsePreloading(true);
    NiTexture_SetMipmapByDefault(0);
    DbcObj* dbc15 = GetFltValueAt(TESRenderer_GetAdapterIndex());
    void* spells117 = dbc15->GetFieldAt204();
    void* spells218 = dbc15->FUN_00717e50();
    (void)spells117;
    (void)spells218;
    if (dbc15 == 0)
    {
        CopyStringToGlobal((const char*)&DAT_010214c8);
        return 0;
    }
    D3DPERF_SetOptions_009f9968(1);
    Sub130* sub13013 = dbc15->NiXAdapaterDesc_GetDeviceCaps_004dc120(1);
    if (sub13013 == 0)
    {
        CopyStringToGlobal((const char*)&DAT_0102149c);
        return 0;
    }
    if (DAT_011c77b4.GetBoolValue())
    {
        DAT_011c6fb9 = ((sub13013->f0c & 0x20000) != 0);
    }
    else
    {
        DAT_011c6fb9 = 0;
    }
    unsigned short wval40 = sub13013->f118;
    if (wval40 > 0x60)
    {
        if (sub13013->f110 < 0x20)
        {
            wval40 = 0x60;
        }
    }
    int hr62 = reinterpret_cast<RendObj*>(DAT_011c73b4.operator unsigned int())->NiDX9Renderer_GetDirect3D()->vfn_28(0, 1, 0x16, 0x80000, 3, 0x71);
    DAT_011c70ea = (int)(hr62 >= 0);
    hr62 = reinterpret_cast<RendObj*>(DAT_011c73b4.operator unsigned int())->NiDX9Renderer_GetDirect3D()->vfn_28(0, 1, 0x16, 0x20000, 3, 0x71);
    DAT_011f941f = (int)(hr62 >= 0);
    DAT_011ad810 = *DAT_011c7284.Setting_Int();
    DAT_011ad814 = *DAT_011c7784.Setting_Int();
    DAT_011ad818 = *DAT_011c7680.Setting_Int();
    DAT_011f9420 = ((sub13013->f40 & 0x400) != 0);
    bool b12;
    b12 = ((sub13013->f3c & 2) != 0 && (sub13013->f3c & 0x100) == 0) ? 0 : 1;
    DAT_011f9183 = (b12 && !*DAT_011c7538.FUN_00408d60()) ? 1 : 0;
    DAT_0126efc4 = *DAT_011c779c.Setting_Int();
    DAT_0126efc8 = *DAT_011c7254.Setting_Int();
    DAT_011f9426 = DAT_011c70ec;
    if (DAT_011c70ec != 0)
    {
        float rf = (float)(((double)(unsigned int)DAT_01189480 - *DAT_011c718c.Int()) /
                           (double)(unsigned int)DAT_01189480 / 2.0);
        DAT_011ad840 = NiColorA(0.0f, 1.0f, 1.0f - rf, rf);
        DAT_011f9430 = *DAT_011c73dc.Int();
        DAT_011f9434 = *DAT_011c718c.Int();
    }
    DAT_011f941e = (*DAT_011c76c0.FUN_00408d60() && DAT_011c70ea != 0) ? 1 : 0;
    DAT_011f94a8 = *DAT_011c747c.FUN_00408d60();
    DAT_011f94a9 = *DAT_011c75b0.FUN_00408d60();
    DAT_011f9422 = (!DAT_011f941e && *DAT_011c7768.FUN_00408d60()) ? 1 : 0;
    DAT_011f91a3 = *DAT_011c73a4.FUN_00408d60();
    DetectGpuVendor(DAT_01189468, DAT_0118946c, *DAT_011c74e0.FUN_00408d60(), spells117, spells218, wval40);
    if (FUN_004dc060(0) < 5)
    {
        DAT_011c71dc.Setting_SetValueB(0);
    }
    *(short*)&DAT_011ad830 = *reinterpret_cast<short*>(DAT_011c7520.Setting_Int());
    if (BSRenderState_GetGPUVendor() == 1)
    {
        hr62 = reinterpret_cast<RendObj*>(DAT_011c73b4.operator unsigned int())->NiDX9Renderer_GetDirect3D()->vfn_28(0, 1, 0x16, 0, 1, 0x434f5441);
    }
    else if (BSRenderState_GetGPUVendor() == 2)
    {
        hr62 = 0;
    }
    else if (BSRenderState_GetGPUVendor() == 3)
    {
        hr62 = (int)0x88760866;
    }
    else
    {
        hr62 = (int)0x88760866;
    }
    DAT_011f9421 = (hr62 >= 0 && *DAT_011c7790.Bool() && *DAT_011c73f4.Int() > 1) ? 1 : 0;
    BSShaderManager_SetMaxShadowMaps(BSMAX_00647b70(*DAT_011c72e4.Setting_Int(), *DAT_011c72d8.Setting_Int()));
    bool flag27 = true;
    if (BSRenderState_GetGPUVendor() == 2)
    {
        void* hmod = IMP_fdf0b0((const char*)&DAT_0102148c);
        if (hmod != 0)
        {
            void* proc = IMP_fdf0ac(hmod, (const char*)&DAT_01021478);
            if (proc != 0)
            {
                int res = ((Fn0)proc)();
                if (res > 1)
                {
                    DAT_011f9440 = 1;
                    DAT_011f9181 = 0;
                }
            }
            IMP_fdf0a8(hmod);
        }
    }
    else if (BSRenderState_GetGPUVendor() == 1)
    {
        DriverVersion driverVersionV52;
        int queryStatusV22;
        int arr1V6[128];
        Unk48c unk48c33V3;
        int cnt57V6;
        DevInfo dinfo2V19;
        unsigned int countA23V9;
        unsigned int countB2V25;
        int idx33V7;
        {
            queryStatusV22 = FUN_009fea2a();
            driverVersionV52.version = 0;
            fnv_zlib_memset(&driverVersionV52.unk04, 0, 0x88);
            driverVersionV52.version = 0x1008c;
            queryStatusV22 = Runtime_ForwardCall_009fead0(0, &driverVersionV52.version);
            if (queryStatusV22 != 0)
                goto gpuQueryDone;
            cnt57V6 = 0;
            queryStatusV22 = 0;
            for (idx33V7 = 0; queryStatusV22 == 0 && idx33V7 < 0x80; idx33V7++)
            {
                queryStatusV22 = FUN_009fead6(idx33V7, &arr1V6[idx33V7]);
                if (queryStatusV22 == 0)
                    cnt57V6++;
            }
            queryStatusV22 = FUN_009feae8(&dinfo2V19.unk000, &countA23V9);
            if (queryStatusV22 != 0)
                goto gpuQueryDone;
            queryStatusV22 = Object_ForwardCall_009feae2(&unk48c33V3.f0, &countB2V25);
            if (queryStatusV22 != 0)
                goto gpuQueryDone;
            Ver654 ver654;
            ver654.f0 = 0x1001c;
            queryStatusV22 = FUN_009febd8(((RendObj*)NiXenonRenderer_GetRenderer())->NiDX9Renderer_GetDirect3D(), &ver654.f0);
            if (queryStatusV22 != 0)
            {
                if (countA23V9 < countB2V25)
                {
                    DAT_011f9440 = 1;
                    DAT_011f9181 = 0;
                }
            }
            else
            {
                if (countB2V25 > 0)
                {
                    DAT_011f9440 = 1;
                    DAT_011f9181 = 0;
                }
            }
        gpuQueryDone:;
        }
    }
    else if (BSRenderState_GetGPUVendor() == 3)
    {
        if (TESRenderer_GetMultiSampleEnabled())
        {
        }
    }
    else
    {
        if (TESRenderer_GetMultiSampleEnabled())
        {
        }
    }
    if (flag27 && *DAT_011c7504.FUN_00408d60())
    {
        BSShaderManager_EnableUseRefractionShader(1);
    }
    else
    {
        BSShaderManager_EnableUseRefractionShader(0);
    }
    if ((double)Renderer_GetScreenHeight() / (double)Renderer_GetScreenWidth() == 0.75)
    {
        DAT_011c70eb = 0;
    }
    else
    {
        DAT_011c70eb = 1;
    }
    int fmt33;
    {
        int li10;
        DevObj* dev413;
        int rr1;
        DevObj* dev53;
        int r510;
        for (li10 = 0; li10 < 15; li10++)
        {
            switch (li10)
            {
            case 0:
                fmt33 = 0x17;
                break;
            case 1:
                fmt33 = 0x18;
                break;
            case 2:
                fmt33 = 0x19;
                break;
            case 3:
                fmt33 = 0x1a;
                break;
            case 4:
                fmt33 = 0x51;
                break;
            case 5:
                fmt33 = 0x14;
                break;
            case 6:
                fmt33 = 0x15;
                break;
            case 7:
                fmt33 = 0x16;
                break;
            case 8:
                fmt33 = 0x72;
                break;
            case 10:
                fmt33 = 0x24;
                break;
            case 9:
                fmt33 = 0x71;
                break;
            case 11:
                fmt33 = 0x74;
                break;
            case 12:
                fmt33 = 0x32;
                break;
            case 13:
                fmt33 = 0x22;
                break;
            case 14:
                fmt33 = 0x70;
                break;
            default:
                fmt33 = 0;
                break;
            }
            dev413 = reinterpret_cast<RendObj*>(DAT_011c73b4.operator unsigned int())->NiDX9Renderer_GetDirect3D();
            rr1 = dev413->vfn_28(0, 1, 0x16, 0, 3, fmt33);
            if (rr1 >= 0)
            {
                DAT_011f9194[li10] = 1;
            }
            else
            {
                DAT_011f9194[li10] = 0;
            }
        }
        dev53 = reinterpret_cast<RendObj*>(DAT_011c73b4.operator unsigned int())->NiDX9Renderer_GetDirect3D();
        r510 = dev53->vfn_28(0, 1, 0x16, 0x80000, 3, 0x24);
        DAT_011ad832 = (int)(r510 >= 0);
    }
    Renderer_SetGamma(*DAT_011c71ac.Float());
    int t1404 = FUN_00b4f4a0();
    _sprintf_s(buf21, 260, "%sRendererInfo.txt", BSUtilities_GetPersonalPath());
    file32 = FUN_00ec9a47(buf21, (const char*)&DAT_01021568);
    if (file32 != 0)
    {
        FUN_00ec9774(file32, (const char*)&DAT_01021450, spells117, spells218);
        FUN_00ec9774(file32, (const char*)&DAT_01021434, t1404);
        FUN_00ec9774(file32, (const char*)&DAT_01021418, sub13013->fcc & 0xffff);
        FUN_00ec9774(file32, (const char*)&DAT_010213fc, sub13013->fc4 & 0xffff);
        FUN_00ec9774(file32, (const char*)&DAT_010213e0, FUN_00b4f3e0());
        FUN_00ec9774(file32, (const char*)&DAT_010213c4, FUN_00b4f380(0));
        FUN_00ec9774(file32, (const char*)&DAT_010213a8, FUN_00b4f380(1));
        FUN_00ec9774(file32, (const char*)&DAT_0102138c, (int)wval40);
        FUN_00ec9774(file32, (const char*)&DAT_01021368,
                     DAT_011f94a4 ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_0102134c,
                     DAT_011f94a6 ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_01021330, b12 ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_01021314,
                     DAT_011c70ea ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_010212f8,
                     DAT_011f941f ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_010212dc,
                     DAT_011f941e ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_010212c0,
                     DAT_011f9422 ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_010212a4,
                     BSShaderManager_GetUseRefractionShader() ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_01021284,
                     DAT_011f91a3 ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_01021268,
                     DAT_011f9440 ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_0102124c,
                     DAT_011c7b20.GetBoolValue() ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_01021230,
                     DAT_011c7b6c.GetBoolValue() ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_01021214,
                     DAT_011c7ac4.GetBoolValue() ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_010211f8,
                     DAT_011c7b48.GetBoolValue() ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_010211dc, DAT_011c70cc);
        FUN_00ec9774(file32, (const char*)&DAT_010211c0,
                     DAT_011f9421 ? (const char*)&DAT_01021388 : (const char*)&DAT_01021384);
        FUN_00ec9774(file32, (const char*)&DAT_010211a4, ShaderBuffer_GetCurrentBufferType());
        FUN_00ec9774(file32, (const char*)&DAT_01021188, *DAT_011c3ea4.Setting_Int());
        FUN_00ec9907(file32);
    }
    DAT_011f9190 = *DAT_011c76c0.FUN_00408d60() ? *DAT_011c7488.Float() : *DAT_011c7170.Float();
    DAT_011f918c = *DAT_011c7574.Float();
    DAT_011f9188 = *DAT_011c7510.Float();
    DAT_011f9444 = *DAT_011c7740.Float();
    DAT_011f9448 = *DAT_011c7740.Float() + *DAT_011c76b4.Float();
    DAT_011f944c = *DAT_011c7568.Float();
    DAT_011f9450 = *DAT_011c7568.Float() + *DAT_011c7400.Float();
    DAT_011f9454 = *DAT_011c7598.Float();
    DAT_011f9458 = *DAT_011c7598.Float() + *DAT_011c7634.Float();
    DAT_011f945c = *DAT_011c7374.Float();
    DAT_011f9460 = *DAT_011c73e8.Float();
    DAT_011f9464 = *DAT_011c7160.Float();
    DAT_011f9468 = *DAT_011c72f0.Float();
    DAT_011f946c = *DAT_011c72cc.Float();
    DAT_011f9470 = *DAT_011c7428.Float();
    DAT_011f9474 = *DAT_011c72fc.Float();
    DAT_011f9478 = *DAT_011c7344.Float();
    DAT_011f9488 = *DAT_011c7610.FUN_00408d60();
    DAT_011ad834 = *DAT_011c735c.Float();
    DAT_011f9489 = 0;
    DAT_011f94b4 = *DAT_011c710c.FUN_00408d60();
    DAT_011f9425 = *DAT_011c7774.FUN_00408d60();
    DAT_011f9428 = *DAT_011c7464.Float();
    DAT_011ad838 = *DAT_011c75e0.Float();
    DAT_011f91b0 = (*DAT_011c752c.Setting_Int() >= 0 && *DAT_011c752c.Setting_Int() <= 3) ? *DAT_011c752c.Setting_Int() : 3;
    DAT_011f9490 = DAT_011c70cc;
    DAT_011f961c =
        NiColorA(*DAT_011c75f8.Float(), *DAT_011c77cc.Float(), *DAT_011c73d0.Float(), 1.0f);
    SetBSStringCapacity(*DAT_011c76cc.Setting_Int());
    DAT_011f948a = *DAT_011c7308.FUN_00408d60();
    return (int)reinterpret_cast<RendObj*>(DAT_011c73b4.operator unsigned int());
}
}  // namespace fnv_004da670
