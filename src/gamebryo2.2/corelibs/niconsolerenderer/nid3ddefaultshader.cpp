// gamebryo2.2/corelibs/niconsolerenderer/nid3ddefaultshader.cpp: NiD3DDefaultShader (10 functions)

#include "../../../../include/NiD3DDefaultShader.h"
#include "../../../../include/NiD3DShader.h"
#include "nid3ddefaultshader_decls.h"

// These entry points are absent from the shared class declarations. The unused
// EDX parameter keeps their stack arguments compatible with the original methods.
// Calls through __thiscall pointers leave that unused register unspecified.
struct GeomX;
struct GeometryTextureSetBufferView;
struct StateX;
struct S_00e7c720_State;
extern void __fastcall GetDefaultShaderLocalData(NiD3DDefaultShader* shader);
extern unsigned int __fastcall FinishD3DShaderPass(
    NiD3DShader*, void*, void*, void*, void*, void*, void*, void*, void*);
extern unsigned int __fastcall BeginD3DShaderPass(
    NiD3DShader*, void*, void*, void*, void*, S_00e7c720_State*, void*, void*, void*);
extern void __fastcall SetDefaultShaderValue(NiD3DDefaultShader*, void*, unsigned int);
unsigned int __fastcall CreateDefaultShaderPass(
    NiD3DDefaultShader*, void*, GeomX*, void*, GeometryTextureSetBufferView*, StateX*, void*, void*, void*);

// Initializes the default shader without an exception-unwind path, as in the game.
// @fnv 0x00e7c6b0
__declspec(nothrow) NiD3DDefaultShader::NiD3DDefaultShader()
{
    m_bUsesNiRenderState = false;
    m_bUsesNiLightState = false;
    m_spShaderDecl.m_pObject = 0;
    m_pkRenderStateGroup = 0;
    m_spPixelConstantMap.m_pObject = 0;
    m_spVertexConstantMap.m_pObject = 0;
    m_uiCurrentPass = 0;
    *(void**)this = (void*)DAT_010eecac;
    m_peFogPassArray = 0;
    m_uiFogPassArraySize = 0;
    m_pkLastState = 0;
    _ReadWriteBarrier();
    const char* shaderName = "Default Shader From Gamebryo 2.1";
    char* pOldNameHandle = m_kName.m_kHandle;
    if (pOldNameHandle != shaderName)
    {
        m_kName.m_kHandle = NiGlobalStringTable::AddString(shaderName);
        if (pOldNameHandle != EmptyFS.m_kHandle)
            InterlockedDecrement((long*)(pOldNameHandle - 8));
    }
    m_bIsBestImplementation = true;
}

// @fnv 0x00e7c560
bool __fastcall InitializeDefaultShaderIfNeeded(NiD3DDefaultShader* shader)
{
    if (!shader->m_bInitialized)
    {
        if (!shader->NiD3DShader::Initialize())
            return false;
        GetDefaultShaderLocalData(shader);
    }
    return true;
}

// Resets passes through virtual slot 59, then creates the default shader pass.
// @fnv 0x00e7cc10
unsigned int __fastcall PrepareDefaultShaderPass(
    NiD3DDefaultShader* shader, void*, void* pkGeometry, void* pkSkin, void* pkRendererData, void* pkState,
    void* pkEffects, void* kWorld, void* kWorldBound)
{
    ((void(__thiscall*)(NiD3DDefaultShader*))(*(void***)shader)[59])(shader);
    return reinterpret_cast<unsigned int(__thiscall*)(NiD3DDefaultShader*, void*, void*, void*, void*, void*, void*, void*)>(
        CreateDefaultShaderPass)(shader, pkGeometry, pkSkin, pkRendererData, pkState, pkEffects, kWorld, kWorldBound);
}

struct RendererFake
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void Set(int, unsigned int, int, int);
};
// Restores the saved lighting render state, then finishes the shader pass.
// @fnv 0x00e7c580
unsigned int __fastcall RestoreDefaultShaderState(
    NiD3DDefaultShader* shader, void*, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7)
{
    reinterpret_cast<RendererFake*>(shader->m_pkD3DRenderState)->Set(0x89, shader->m_uiOldLightingValue, 0, 0);
    return reinterpret_cast<unsigned int(__thiscall*)(NiD3DShader*, void*, void*, void*, void*, void*, void*, void*)>(
        FinishD3DShaderPass)(shader, a1, a2, a3, a4, a5, a6, a7);
}

extern void NiFree(void*);
extern void _delete(void*, unsigned int);

// @fnv 0x00e7c5d0
void* __fastcall DestroyDefaultShader(NiD3DDefaultShader* shader, void*, unsigned int auiFlags)
{
    void* p = shader->m_peFogPassArray;
    *(void**)shader = (void*)DAT_010eecac;
    NiFree(p);
    shader->NiD3DShader::FUN_00e806c0();
    if (auiFlags & 1)
    {
        _delete(shader, sizeof(NiD3DDefaultShader));
    }
    return shader;
}

struct S_00e7c720_Renderer
{
    virtual void f00();
    virtual void f01();
    virtual void f02(void* a);
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual unsigned int f27(unsigned int v);
};
struct S_00e7c720_Mgr
{
    void ApplyRenderModes(void* a, void* b, int c);
};
struct S_00e7c720_Owner
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
    S_00e7c720_Mgr* unk8c8;
};
struct S_00e7c720_State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* unk14;
};
// Applies render modes, begins the shader pass, and saves its lighting render state.
// @fnv 0x00e7c720
unsigned int __fastcall BeginDefaultShaderPass(
    NiD3DDefaultShader* shader, void*, void* apArg1, void* apArg2, void* apArg3, S_00e7c720_State* apState,
    void* apArg5, void* apArg6, void* apArg7)
{
    reinterpret_cast<S_00e7c720_Renderer*>(shader->m_pkD3DRenderState)->f02(apState);
    reinterpret_cast<S_00e7c720_Owner*>(shader->m_pkD3DRenderer)->unk8c8->ApplyRenderModes(apArg5, apState->unk14, 0);
    unsigned int r = reinterpret_cast<unsigned int(__thiscall*)(NiD3DShader*, void*, void*, void*, S_00e7c720_State*, void*, void*, void*)>(
        BeginD3DShaderPass)(shader, apArg1, apArg2, apArg3, apState, apArg5, apArg6, apArg7);
    shader->m_uiOldLightingValue = reinterpret_cast<S_00e7c720_Renderer*>(shader->m_pkD3DRenderState)->f27(0x89);
    return r;
}

struct ShaderOwner
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    void* m_30;
    unsigned int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    int m_64;
    void Tail();
};

struct Sub30Cls
{
    void Create(unsigned int size, int a, int b);
};

extern void* DAT_0126f74c;
extern unsigned int DAT_011bf558;
extern unsigned int DAT_011bf55c;
extern void GetOwner(ShaderOwner** out);
extern void* MakeSub30();

// @fnv 0x00e7c790
void __fastcall ConfigureDefaultShader(
    NiD3DDefaultShader* shader, void*, int aiUnused1, int aiUnused2, unsigned char a3, unsigned char a4)
{
    ShaderOwner* p = 0;
    int delta = -1;
    DAT_0126f74c = 0;
    GetOwner(&p);
    void*& pSub30 = p->m_30;
    DAT_0126f74c = p;
    if (pSub30 == 0)
    {
        pSub30 = MakeSub30();
    }
    ((Sub30Cls*)pSub30)->Create(0xa8, 7, 1);
    // Preserve the incoming flag bytes without bool normalization.
    reinterpret_cast<unsigned char&>(shader->m_bBaseTextureAlphaNeeded) = a3;
    reinterpret_cast<unsigned char&>(shader->m_bVertexColorAlphaNeeded) = a4;
    shader->m_uiRemainingStages = DAT_011bf558;
    shader->m_uiRemainingTextures = DAT_011bf55c;
    if (a3)
    {
        shader->m_uiRemainingStages += delta;
        shader->m_uiRemainingTextures += delta;
    }
    if (p)
    {
        ShaderOwner* q = p;
        q->m_64 += delta;
        if (q->m_64 == 0)
        {
            q->Tail();
        }
    }
}

namespace fnv_00e7c830 {
struct PassRenderState
{
    void Set(unsigned int state, unsigned int value, bool save);
};
struct ShaderPassTexture;
struct ShaderPass
{
    int unk00, unk04;
    void* texture;
    int unk0C;
    PassRenderState* state;
    int unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58;
    unsigned short unk5C;
    bool enabled;
    unsigned char unk5F;
    unsigned int references;
    void SetClamp(unsigned int value);
    void SetFilter(unsigned int value);
    void Destroy();
    void Release()
    {
        if (--references == 0)
            Destroy();
    }
    void BindTexture(void* image, unsigned int value)
    {
        PassRenderState* current = state;
        texture = image;
        current->Set(11, value, false);
    }
    __forceinline void Disable()
    {
        PassRenderState* current = state;
        enabled = false;
        current->Set(24, 0, false);
    }
};

struct MaterialPassConfiguration
{
    unsigned int GetValue(ShaderPass* pass);
};
struct ShaderMaterial
{
    int unk00;
    unsigned short flags;
    unsigned short unk06;
    void* texture;
    MaterialPassConfiguration* configuration;
};
struct ShaderPassManager
{
    int unk00, unk04, unk08, unk0C, unk10;
    void* group;
    bool Prepare(unsigned int count, int material);
    void Register(void* group, ShaderPass* pass);
};
extern ShaderPassManager* DAT_0126f74c;
void __cdecl AssignStageFromPool(ShaderPass** pass);

// Prepares a pass slot, configures render states and texture binding from the material, registers the pass, and returns it.
// @fnv 0x00e7c830
ShaderPass* __fastcall CreateDefaultShaderTexturePass(
    NiD3DDefaultShader* shader, void*, ShaderMaterial* material, unsigned int value)
{
    if (!DAT_0126f74c || !DAT_0126f74c->Prepare(1, material != 0))
        return 0;
    ShaderPass* pass = 0;
    AssignStageFromPool(&pass);
    ShaderPass* result = pass;
    PassRenderState*& state = result->state;
    state->Set(28, 1, false);
    if (material && material->texture)
    {
        result->BindTexture(material->texture, value);
        state->Set(1, 2, false);
        state->Set(2, 2, false);
        state->Set(3, 1, false);
        state->Set(4, 3, false);
        state->Set(5, 2, false);
        if (shader->m_bVertexColorAlphaNeeded)
        {
            state->Set(6, 0, false);
            shader->m_bVertexColorAlphaNeeded = false;
        }
        else
        {
            state->Set(6, 1, false);
        }
        result->SetClamp(reinterpret_cast<unsigned char*>(&material->flags)[1] & 15);
        result->SetFilter((material->flags >> 12) & 3);
        MaterialPassConfiguration* configuration = material->configuration;
        if (!configuration)
        {
            result->Disable();
        }
        else
        {
            reinterpret_cast<void(__thiscall*)(NiD3DDefaultShader*, unsigned int)>(
                SetDefaultShaderValue)(shader, configuration->GetValue(result));
        }
        --shader->m_uiRemainingTextures;
    }
    else
    {
        state->Set(1, 2, false);
        state->Set(2, 0, false);
        state->Set(3, 1, false);
        if (shader->m_bVertexColorAlphaNeeded)
        {
            state->Set(4, 2, false);
            shader->m_bVertexColorAlphaNeeded = false;
        }
        else
        {
            state->Set(4, 3, false);
        }
        state->Set(5, 0, false);
        state->Set(6, 1, false);
        if (shader->m_uiRemainingTextures)
            --shader->m_uiRemainingTextures;
    }
    --shader->m_uiRemainingStages;
    DAT_0126f74c->Register(DAT_0126f74c->group, result);
    if (pass)
        pass->Release();
    return result;
}
}  // namespace fnv_00e7c830

namespace fnv_00e7ca20 {
extern unsigned int DAT_0126f74c;

struct FUN_00e7ca20_setter
{
    void SetStageValue(int a, int b, int c);
};

struct FUN_00e7ca20_holder
{
    unsigned int unk00, unk04, unk08, unk0c;
    FUN_00e7ca20_setter* m_10;
};

// Configures the alpha texture stage and clears the remaining stage and texture counts.
// @fnv 0x00e7ca20
void __fastcall ConfigureDefaultShaderTexture(NiD3DDefaultShader* shader, void*, void* p)
{
    if (DAT_0126f74c != 0)
    {
        if (shader->m_bBaseTextureAlphaNeeded != 0 && p != 0)
        {
            unsigned short v = *(unsigned short*)((char*)p + 4);
            v = (unsigned short)(v & 0xff);
            unsigned short c = v;
            if ((unsigned int)c > shader->m_uiMaxTextureIndex)
            {
                c = (unsigned short)shader->m_uiMaxTextureIndex;
            }
            FUN_00e7ca20_holder* pHolder = reinterpret_cast<FUN_00e7ca20_holder*(__thiscall*)(NiD3DDefaultShader*, void*, unsigned int)>(
                fnv_00e7c830::CreateDefaultShaderTexturePass)(shader, p, (unsigned int)c);
            if (pHolder != 0)
            {
                pHolder->m_10->SetStageValue(1, 3, 0);
                if (shader->m_bBaseTextureAlphaNeeded != 0)
                {
                    pHolder->m_10->SetStageValue(4, 4, 0);
                    pHolder->m_10->SetStageValue(6, 0, 0);
                }
                else
                {
                    pHolder->m_10->SetStageValue(4, 2, 0);
                }
            }
        }
        shader->m_uiRemainingStages = 0;
        shader->m_uiRemainingTextures = 0;
    }
}
}  // namespace fnv_00e7ca20

struct StageX
{
    void SetStageValue(unsigned int a, unsigned int b, unsigned int c);
};
struct PassX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    StageX* m_pkStage;
};
struct MapX
{
    int m0;
    unsigned short m_usFlags;
    short m6;
    void* m_pkTexture;
};
struct TexPropX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short m_usFlags;
    short m1a;
    enum Mode
    {
        M0,
        M1,
        M2,
        M3,
        M4,
        M5,
        M6,
        M7
    };
    Mode GetMode() const
    {
        return (Mode)((m_usFlags & 0xe) >> 1);
    }
    int m1c;
    MapX** m_ppkMaps;
};
struct StateX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    TexPropX* m_pkTexProp;
};
// Renderer buffer view: byte 7 counts texture sets and 0x00e8eeb0 validates streams; Data.h instead stores skill requirements.
struct GeometryTextureSetBufferView
{
    int unk00;
    char unk04;
    char unk05;
    char unk06;
    unsigned char m_ucCount;
    bool FUN_00e8eeb0();
};
struct SkinX
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
    GeometryTextureSetBufferView* m_pUserData;
};
struct GeomX
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
    SkinX* m_pkSkin;
};
// @fnv 0x00e7cac0
unsigned int __fastcall CreateDefaultShaderPass(
    NiD3DDefaultShader* shader, void*, GeomX* pkGeometry, void* pkSkin, GeometryTextureSetBufferView* pkData, StateX* pkState,
    void* pkEffects, void* kWorld, void* kWorldBound)
{
    if (!pkGeometry)
    {
        if (!pkData || !pkData->FUN_00e8eeb0() || !pkState)
            return 0xffffffff;
    }
    else if (!pkData)
        return 0xffffffff;
    TexPropX* pkTex = pkState->m_pkTexProp;
    MapX* pkMap = 0;
    if (!pkData)
        pkData = pkGeometry->m_pkSkin->m_pUserData;
    unsigned short usBoneCount = pkData->m_ucCount;
    shader->m_uiMaxTextureIndex = 0;
    unsigned int uiNumMaps;
    if (usBoneCount)
    {
        pkMap = pkTex->m_ppkMaps[0];
        shader->m_uiMaxTextureIndex = usBoneCount - 1;
        if (pkMap && pkMap->m_pkTexture)
            uiNumMaps = 1;
        else
            uiNumMaps = 0;
    }
    else
        uiNumMaps = 0;
    TexPropX::Mode mode = pkTex->GetMode();
    bool bAlpha;
    try
    {
        bAlpha = mode != TexPropX::M0;
    }
    catch (...)
    {
        throw;
    }
    if (bAlpha || uiNumMaps > 0)
    {
        reinterpret_cast<void(__thiscall*)(NiD3DDefaultShader*, int, int, unsigned char, unsigned char)>(
            ConfigureDefaultShader)(shader, 1, 3, 0, 0);
        PassX* pkPass;
        if (uiNumMaps > 0)
        {
            unsigned short usIdx = pkMap->m_usFlags & 0xff;
            if (usIdx > shader->m_uiMaxTextureIndex)
                usIdx = (unsigned short)shader->m_uiMaxTextureIndex;
            pkPass = reinterpret_cast<PassX*(__thiscall*)(NiD3DDefaultShader*, MapX*, unsigned int)>(
                fnv_00e7c830::CreateDefaultShaderTexturePass)(shader, pkMap, usIdx);
            if (bAlpha)
            {
                pkPass->m_pkStage->SetStageValue(1, 4, 0);
                pkPass->m_pkStage->SetStageValue(3, 0, 0);
                pkPass->m_pkStage->SetStageValue(4, 4, 0);
                pkPass->m_pkStage->SetStageValue(6, 0, 0);
            }
            else
            {
                pkPass->m_pkStage->SetStageValue(1, 2, 0);
                pkPass->m_pkStage->SetStageValue(4, 2, 0);
            }
        }
        else
        {
            pkPass = reinterpret_cast<PassX*(__thiscall*)(NiD3DDefaultShader*, MapX*, unsigned int)>(
                fnv_00e7c830::CreateDefaultShaderTexturePass)(shader, 0, 0);
            pkPass->m_pkStage->SetStageValue(1, 2, 0);
            pkPass->m_pkStage->SetStageValue(4, 2, 0);
        }
        reinterpret_cast<void(__thiscall*)(NiD3DDefaultShader*, MapX*)>(
            fnv_00e7ca20::ConfigureDefaultShaderTexture)(shader, pkMap);
    }
    return 0;
}
