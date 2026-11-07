// bsshader/distantlodshader.cpp: DistantLODShader, BSShader, RSShader, LodCompiler (13 functions)

#include "../../include/BSShader.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiD3DShaderDeclaration.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DVertexShader.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DShaderConstantMap.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
inline void NiD3DVertexShader::IncRefCount() { NiRefObject::IncRefCount(); }
inline void NiD3DVertexShader::DecRefCount() { NiRefObject::DecRefCount(); }
inline void NiD3DPixelShader::IncRefCount() { NiRefObject::IncRefCount(); }
inline void NiD3DPixelShader::DecRefCount() { NiRefObject::DecRefCount(); }
inline void NiD3DShaderConstantMap::IncRefCount() { NiRefObject::IncRefCount(); }
inline void NiD3DShaderConstantMap::DecRefCount() { NiRefObject::DecRefCount(); }

template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
template <class T> inline NiPointer<T>::~NiPointer() {}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>::operator T*() const { return m_pObject; }
template <class T> inline T* NiPointer<T>::operator->() const { return m_pObject; }

extern const float DAT_011ad860;
extern const float DAT_011fa280[];
extern const float DAT_011fa290[];


class DistantLODShader : public BSShader
{
  public:
    NiD3DPass* m_pRenderPass;
    unsigned char m_pAuxiliaryObject[0x24];
    const void* m_pDiffuseDirection;
    unsigned int m_uiInstanceData;
    unsigned short m_usInstanceDataCount;
    unsigned char m_pad3[2];
    unsigned char m_afAmbientColor[0x10];
    unsigned char m_diffuseDirection[0x10];
    unsigned char m_afDiffuseColor[0x10];
    unsigned char m_alphaTestRef[0x10];
    unsigned char m_eyeVector[0x10];
    unsigned char m_eyeRightVector[0x10];
    void UpdateShaderConstants();
    virtual void ClearAllTextureStages();
};

// 0x00bd5670 stores four scalar shader constants at each 0x10 stride; these are color/direction registers.
struct LodShaderConstantRow_00bd5670 { float x, y, z, w; LodShaderConstantRow_00bd5670(); void operator=(const LodShaderConstantRow_00bd5670&); };

inline LodShaderConstantRow_00bd5670::LodShaderConstantRow_00bd5670() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{}
inline void LodShaderConstantRow_00bd5670::operator=(const LodShaderConstantRow_00bd5670& vector)
{
    unsigned int* destination = reinterpret_cast<unsigned int*>(this);
    const unsigned int* source = reinterpret_cast<const unsigned int*>(&vector);
    destination[0] = source[0];
    destination[1] = source[1];
    destination[2] = source[2];
    destination[3] = source[3];
}

// Initializes the base shader, then configures shader constants and the D3D pass.
// @fnv 0x00be0870
bool BSShader::Initialize()
{
    if (!NiD3DShader::Initialize())
        return false;
    Func_75();
    Func_77();
    CreateD3DPass();
    return true;
}

// @fnv 0x00bd5a60
void DistantLODShader::UpdateShaderConstants()
{
    if (m_spVertexConstantMap.m_pObject == 0)
    {
        NiD3DShaderConstantMap* map = new NiD3DShaderConstantMap(static_cast<void*>(m_pkD3DRenderer), 0);
        m_spVertexConstantMap = map;
        m_spVertexConstantMap->SetConstant("WorldViewProjTranspose", 0x20000009, 0, 0, 4, 0, 0, 0, 0, false);
        m_spVertexConstantMap->SetConstant("Diffuse Light direction", 0x10000007, 0, 4, 1, "", 16, 4,
                                              m_diffuseDirection, false);
        m_spVertexConstantMap->SetConstant("Diffuse Light color", 0x10000007, 0, 5, 1, "", 16, 4, m_afDiffuseColor,
                                              false);
        m_spVertexConstantMap->SetConstant("ambient color", 0x10000007, 0, 13, 1, "", 16, 4, m_afAmbientColor,
                                              false);
        m_spVertexConstantMap->SetConstant("eye vector", 0x10000007, 0, 14, 1, "", 16, 4, m_eyeVector, false);
        m_spVertexConstantMap->SetConstant("eye right vector", 0x10000007, 0, 9, 1, "", 16, 4, m_eyeRightVector,
                                              false);
        m_spVertexConstantMap->SetConstant("alpha param param", 0x10000007, 0, 12, 1, "", 16, 4, &DAT_011ad860,
                                              false);
        m_spVertexConstantMap->SetConstant("fogparam", 0x10000007, 0, 11, 1, "", 16, 4, DAT_011fa280, false);
        m_spVertexConstantMap->SetConstant("fogcolor", 0x10000007, 0, 10, 1, "", 16, 4, DAT_011fa290, false);
        m_spVertexConstantMap->SetConstant("instance data", 0x10000009, 0, 0x14, m_usInstanceDataCount, "",
                                              m_usInstanceDataCount << 4, 4, m_pDiffuseDirection, false);
        m_uiInstanceData = reinterpret_cast<unsigned int>(m_spVertexConstantMap->GetEntry(reinterpret_cast<unsigned int>("instance data")));
    }
    if (m_spPixelConstantMap.m_pObject == 0)
    {
        NiD3DShaderConstantMap* map = new NiD3DShaderConstantMap(static_cast<void*>(m_pkD3DRenderer), 2);
        m_spPixelConstantMap = map;
        m_spPixelConstantMap->SetConstant("alpha test ref", 0x10000007, 0, 3, 1, "", 16, 4, m_alphaTestRef, false);
    }
}

struct LodObj
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
    virtual void Release34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void Release40();
};
struct LodShaderBase
{
    char pad0[0x28];
    int field28;
    char pad1[0x7c - 0x2c];
    LodObj* setA[4];
    LodObj* setB[2];
    void FUN_00e814b0();
};
// Releases the objects in setA when field28 is set, releases the objects in setB, then calls FUN_00e814b0 on the shader.
// @fnv 0x00bd4ed0
void __fastcall ReleaseLodObjects(LodShaderBase* shader, int)
{
    int i;
    if (shader->field28)
    {
        for (i = 0; i < 4; ++i)
        {
            LodObj* pObj = shader->setA[i];
            if (pObj)
                pObj->Release40();
        }
    }
    for (i = 0; i < 2; ++i)
    {
        LodObj* pObj = shader->setB[i];
        if (pObj)
            pObj->Release34();
    }
    shader->FUN_00e814b0();
}

extern "C" void* g_012023c8;

// @fnv 0x00bd5460
// src: XBOX_PDB 0x00bd5460
void* __cdecl DistantLODShader_GetRTTI()
{
    return &g_012023c8;
}

struct FUN_00bd5470_shell
{
    void __thiscall DistantLODShader_SetCurrentPass(int a, char b);
};

// @fnv 0x00bd5470
// src: XBOX_PDB 0x00bd5470
void __thiscall FUN_00bd5470_shell::DistantLODShader_SetCurrentPass(int a, char b)
{
    *reinterpret_cast<int*>(this + 0x74) = a;
    *reinterpret_cast<char*>(this + 0x78) = b;
}

void __cdecl _delete(void*, unsigned int);
struct S_00bd58f0
{
    void __thiscall FUN_00bd5330();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// Calls FUN_00bd5330, then if bit 0 of flags is set deletes this with size 0x100, and returns this.
// @fnv 0x00bd58f0
void* __thiscall S_00bd58f0::DestroyIfFlagged(unsigned int flags)
{
    FUN_00bd5330();
    if (flags & 1)
        _delete(this, 0x100);
    return this;
}

struct ShaderVTable
{
    virtual void f00()
    {}
    virtual void f01()
    {}
    virtual void f02()
    {}
    virtual void f03()
    {}
    virtual void f04()
    {}
    virtual void f05()
    {}
    virtual void f06()
    {}
    virtual void f07()
    {}
    virtual void f08()
    {}
    virtual void f09()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18()
    {}
    virtual void f19()
    {}
    virtual void f20()
    {}
    virtual void f21()
    {}
    virtual void f22()
    {}
    virtual void f23()
    {}
    virtual void f24()
    {}
    virtual void f25()
    {}
    virtual void f26()
    {}
    virtual void f27()
    {}
    virtual void f28()
    {}
    virtual void f29()
    {}
    virtual void f30()
    {}
    virtual void f31()
    {}
    virtual void f32()
    {}
    virtual void f33()
    {}
    virtual void f34()
    {}
    virtual void f35(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int)
    {}
    virtual void f36()
    {}
    virtual void f37(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                     unsigned int)
    {}
    virtual void f38()
    {}
    virtual void f39()
    {}
    virtual void f40()
    {}
    virtual void f41()
    {}
    virtual void f42()
    {}
    virtual void f43()
    {}
    virtual void f44()
    {}
    virtual void f45()
    {}
    virtual void f46()
    {}
    virtual void f47()
    {}
    virtual void f48(void*)
    {}
    virtual void f49()
    {}
    virtual void f50()
    {}
    virtual void f51()
    {}
    virtual void f52()
    {}
    virtual void f53()
    {}
    virtual void f54()
    {}
    virtual void f55()
    {}
    virtual void f56()
    {}
    virtual void f57()
    {}
    virtual void f58()
    {}
    virtual void f59()
    {}
    virtual void f60()
    {}
    virtual void f61()
    {}
    virtual void f62()
    {}
    virtual void f63()
    {}
    virtual void f64()
    {}
    virtual void f65()
    {}
    virtual void f66()
    {}
    virtual void f67()
    {}
    virtual void f68()
    {}
    virtual void f69()
    {}
    virtual void f70()
    {}
    virtual void f71()
    {}
    virtual void f72()
    {}
    virtual void f73()
    {}
    virtual void f74()
    {}
    virtual void f75()
    {}
    virtual void f76()
    {}
    virtual void f77()
    {}
    virtual void f78()
    {}
    virtual void f79()
    {}
    virtual void f80()
    {}
};

struct NiD3DVertexDeclaration : ShaderVTable
{
    static NiD3DVertexDeclaration* __cdecl Create(NiRenderer*, unsigned int, unsigned int);
};

struct A51BF0Base : ShaderVTable
{
    char pad[0x100 - sizeof(void*)];
    static void* __cdecl operator new(unsigned int);
};

struct FUN_00bd5670 : A51BF0Base
{
    FUN_00bd5670(NiD3DVertexDeclaration*);
};

extern void* DAT_011f9508;
extern unsigned int _data_011c16bc;

// @fnv 0x00bd5920
// src: COMMUNITY 0x00bd5920
FUN_00bd5670* DistantLODShader_CreateShader()
{
    NiD3DVertexDeclaration* declaration = NiD3DVertexDeclaration::Create((NiRenderer*)DAT_011f9508, 4, 1);

    FUN_00bd5670* result = 0;

    declaration->f35((unsigned int)result, (unsigned int)result, (unsigned int)result, 2, (unsigned int)result);
    declaration->f35(1, 5, 4, 3, (unsigned int)result);
    declaration->f35(2, 7, 5, 1, (unsigned int)result);
    declaration->f37((unsigned int)result, 3, 6, 0x80000000, (unsigned int)result, 5, 1, (unsigned int)result);
    declaration->f45();

    result = new FUN_00bd5670(declaration);

    result->f19();
    result->f79();
    result->f71();
    result->f80();
    result->f48(declaration);

    return result;
}

struct FUN_00bd5a40_shell
{
    void __thiscall SetupRenderPass();
    bool __thiscall DistantLODShader_Func_80();
};

// @fnv 0x00bd5a40
// src: COMMUNITY 0x00bd5a40
bool FUN_00bd5a40_shell::DistantLODShader_Func_80()
{
    NiD3DPass::CreateD3DPass(*(NiD3DPass**)((char*)this + 0x6c));
    SetupRenderPass();
    return true;
}

// @fnv 0x00bd5320
void DistantLODShader::ClearAllTextureStages()
{
    ClearTextureStages(m_pRenderPass);
}

struct FUN_00b79930
{
    unsigned int member;
    ~FUN_00b79930();
};
struct FUN_00b66f20
{
    NiRefObject* m_pObject;
    ~FUN_00b66f20();
};
struct MM_011f6238
{
    void MemoryManager_Deallocate(void* ptr);
};
extern MM_011f6238 DAT_011f6238;
struct FUN_00bd5330 : BSShader
{
    FUN_00b79930 table6c[1];
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    FUN_00b66f20 maps7c[4];
    FUN_00b66f20 maps8c[2];
    void* instance94;
    unsigned int count98;
    virtual ~FUN_00bd5330();
};
// @fnv 0x00bd5330
FUN_00bd5330::~FUN_00bd5330()
{
    for (unsigned int i = 0; i < 4; ++i)
    {
        NiRefObject* obj = maps7c[i].m_pObject;
        if (obj)
        {
            obj->DecRefCount();
            maps7c[i].m_pObject = 0;
        }
    }
    for (unsigned int i = 0; i < 2; ++i)
    {
        NiRefObject* obj = maps8c[i].m_pObject;
        if (obj)
        {
            obj->DecRefCount();
            maps8c[i].m_pObject = 0;
        }
    }
    void* allocated = instance94;
    count98 = 0;
    DAT_011f6238.MemoryManager_Deallocate(allocated);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* apValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* apValue);

struct RSTexture
{
    int unk000;
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
    unsigned int m_uiRefCount;

    void Destroy();
    void DecRefCount()
    {
        --m_uiRefCount;
        if (m_uiRefCount == 0)
            Destroy();
    }
};

struct RSTexturePtr
{
    RSTexture* m_pObject;

    RSTexturePtr() : m_pObject(0)
    {}
    ~RSTexturePtr()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
};

class D3DRenderStateGroup
{
public:
    void SetRenderState(int aiState, int aiValue, int aiSave);
};

D3DRenderStateGroup* __cdecl RSCreateRenderState();
void __cdecl RSGetTexture(RSTexturePtr* apTexture);
void __cdecl RSSetupTexture(RSTexture* apTexture, int aiUnk1, int aiUnk2, int aiUnk3, int aiUnk4);
extern int g_iRSShaderLevel;

inline void NiD3DPass::SetVertexShader(NiD3DVertexShader* shader)
{
    m_spVertexShader = shader;
}
inline void NiD3DPass::SetPixelShader(NiD3DPixelShader* shader)
{
    m_spPixelShader = shader;
}
inline D3DRenderStateGroup* NiD3DPass::GetRenderStateGroup()
{
    if (!m_pkRenderStateGroup)
        m_pkRenderStateGroup = RSCreateRenderState();
    return m_pkRenderStateGroup;
}

struct RSShader
{
    int unk000;
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
    NiD3DPass* m_pRenderPass;
    int unk070;
    int unk074;
    int unk078;
    NiD3DVertexShader* m_pkVertexShader;
    int unk080;
    int unk084;
    int unk088;
    NiD3DPixelShader* m_pkPixelShader;

    void SetupRenderPass();
};

// Configures the shader's render pass by setting up a texture, binding vertex and pixel shaders, and applying several render state settings.
// @fnv 0x00bd5490
void RSShader::SetupRenderPass()
{
    RSTexturePtr spTexture;
    RSGetTexture(&spTexture);
    RSSetupTexture(spTexture.m_pObject, 0, 3, 2, 1);
    m_pRenderPass->NiD3DPass_SetStage(m_pRenderPass->m_uiCurrentStage, reinterpret_cast<BeamStage*>(spTexture.m_pObject));
    m_pRenderPass->SetVertexShader(m_pkVertexShader);
    m_pRenderPass->SetPixelShader(m_pkPixelShader);
    D3DRenderStateGroup* pkRS;
    if (g_iRSShaderLevel >= 2)
    {
        pkRS = m_pRenderPass->GetRenderStateGroup();
        pkRS->SetRenderState(0x18, 0xa, 1);
    }
    pkRS = m_pRenderPass->GetRenderStateGroup();
    pkRS->SetRenderState(0xa8, 7, 1);
    pkRS = m_pRenderPass->GetRenderStateGroup();
    pkRS->SetRenderState(0x1b, 0, 1);
    pkRS = m_pRenderPass->GetRenderStateGroup();
    pkRS->SetRenderState(7, 1, 1);
    pkRS = m_pRenderPass->GetRenderStateGroup();
    pkRS->SetRenderState(0x17, 4, 1);
    pkRS = m_pRenderPass->GetRenderStateGroup();
    pkRS->SetRenderState(0xe, 1, 1);
}

#include <string.h>
struct ShaderRecord
{
    const char* name;
    const char* shader;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned char body[0x34];
};
struct LodCompiler
{
    unsigned int dummy00;
    unsigned int dummy04;
    unsigned int dummy08;
    unsigned int dummy0c;
    unsigned int dummy10;
    unsigned int dummy14;
    unsigned int dummy18;
    unsigned int dummy1c;
    unsigned int dummy20;
    unsigned int dummy24;
    unsigned int dummy28;
    unsigned int dummy2c;
    unsigned int dummy30;
    unsigned int dummy34;
    unsigned int dummy38;
    unsigned int dummy3c;
    unsigned int dummy40;
    unsigned int dummy44;
    unsigned int dummy48;
    unsigned int dummy4c;
    unsigned int dummy50;
    unsigned int dummy54;
    unsigned int dummy58;
    unsigned int dummy5c;
    unsigned int dummy60;
    unsigned int dummy64;
    unsigned int dummy68;
    unsigned int dummy6c;
    unsigned int dummy70;
    unsigned int dummy74;
    unsigned int dummy78;
    NiPointer<NiRefObject> vertex[4];
    NiPointer<NiRefObject> pixel[2];
    void CompileDistanceLodShaders();
    NiRefObject* FUN_00be0fe0(void*, void*, const char*, const char*);
    NiRefObject* FUN_00be1750(void*, void*, unsigned int, const char*);
};
extern unsigned int DAT_011f91c0;
extern "C" unsigned int __cdecl DistantLODShader_GetRTTI(unsigned int);
extern "C" int __cdecl FUN_00be0c00(const char*, void*);
extern "C" int __cdecl BSsprintf(char*, unsigned int, const char*, ...);
extern const char str_010bc23c[], str_010b8ba0[], str_010b8bc4[], str_010b8b7c[], str_010b8b74[];
// Builds shader records and calls shader routines for the selected branch, using vs_1_1 or vs_2_0.
// @fnv 0x00bd4f30
void LodCompiler::CompileDistanceLodShaders()
{
    ShaderRecord pix[2], vert[4];
    vert[0].name = str_010bc23c;
    vert[0].shader = 0;
    memset(&vert[0].field08, 0, 0x44);
    vert[1].name = str_010bc23c;
    vert[1].shader = str_010b8ba0;
    vert[1].field08 = 0;
    vert[1].field0c = 0;
    memset(&vert[1].field10, 0, 0x3c);
    vert[2].name = str_010bc23c;
    vert[2].shader = str_010b8bc4;
    vert[2].field08 = 0;
    vert[2].field0c = 0;
    memset(&vert[2].field10, 0, 0x3c);
    vert[3].name = str_010bc23c;
    vert[3].shader = str_010b8bc4;
    vert[3].field08 = 0;
    vert[3].field0c = (unsigned int)str_010b8ba0;
    vert[3].field10 = 0;
    vert[3].field14 = 0;
    memset(&vert[3].body[0], 0, 0x34);
    pix[0].name = str_010b8b7c;
    pix[0].shader = 0;
    pix[0].field08 = 0;
    memset(&pix[0].field0c, 0, 0x40);
    pix[1].name = str_010b8b7c;
    pix[1].shader = str_010b8b74;
    pix[1].field08 = 0;
    pix[1].field0c = 0;
    pix[1].field10 = 0;
    memset(&pix[1].field14, 0, 0x38);
    unsigned int uiShaderProfile = DistantLODShader_GetRTTI(1);
    char scratch[260], name[260];
    if (DAT_011f91c0 == 1)
    {
        for (int i = 0; i < 2; ++i)
        {
            FUN_00be0c00(vert[i].name, scratch);
            BSsprintf(name, 260, "DISTLOD1%03i.vso", i);
            vertex[i] = FUN_00be0fe0(scratch, &vert[i].shader, "vs_1_1", name);
        }
        FUN_00be0c00(pix[0].name, scratch);
        BSsprintf(name, 260, "DISTLOD1%03i.pso", 0);
        pixel[0] = FUN_00be1750(scratch, &pix[0].shader, uiShaderProfile, name);
    }
    else
    {
        for (int i = 2; i < 4; ++i)
        {
            FUN_00be0c00(vert[i].name, scratch);
            BSsprintf(name, 260, "DISTLOD2%03i.vso", i);
            vertex[i] = FUN_00be0fe0(scratch, &vert[i].shader, "vs_2_0", name);
        }
        FUN_00be0c00(pix[1].name, scratch);
        BSsprintf(name, 260, "DISTLOD2%03i.pso", 1);
        pixel[1] = FUN_00be1750(scratch, &pix[1].shader, uiShaderProfile, name);
    }
}

namespace fnv_00bd5670 {
struct PassPointer
{
    NiD3DPass* m_pObject;
    PassPointer();
    ~PassPointer();
};

struct ShaderPointer
{
    NiRefObject* m_pObject;
    ShaderPointer();
    ~ShaderPointer();
};

extern LodShaderConstantRow_00bd5670 DAT_011a9bd0;
extern int DAT_011f91c0;

struct MemoryManager_Helper
{
    void* Allocate(unsigned int size);
};

struct InstanceData_00bd5670
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    static void* operator new[](unsigned int size)
    {
        return ((MemoryManager_Helper*)&DAT_011f6238)->Allocate(size);
    }
};

struct FUN_00bd5670_c : BSShader
{
    PassPointer table6c[1];
    float m_field70;
    int m_field74;
    char m_field78;
    char unk79;
    char unk7a;
    char unk7b;
    ShaderPointer maps7c[4];
    ShaderPointer maps8c[2];
    void* m_uiInstanceData;
    unsigned int m_count98;
    unsigned short m_usInstanceDataCount;
    char unk9e;
    char unk9f;
    LodShaderConstantRow_00bd5670 m_afAmbientColor;
    LodShaderConstantRow_00bd5670 m_diffuseDirection;
    LodShaderConstantRow_00bd5670 m_afDiffuseColor;
    LodShaderConstantRow_00bd5670 m_alphaTestRef;
    LodShaderConstantRow_00bd5670 m_eyeVector;
    LodShaderConstantRow_00bd5670 m_eyeRightVector;

    FUN_00bd5670_c(NiRefObject* decl);
    virtual ~FUN_00bd5670_c();
};

// Initializes the shader by releasing map references, setting the declaration, and allocating instance data based on DAT_011f91c0.
// @fnv 0x00bd5670
FUN_00bd5670_c::FUN_00bd5670_c(NiRefObject* apDeclaration)
{
    iShaderType = 7;
    for (int i = 0; i < 4; ++i)
    {
        if (maps7c[i].m_pObject)
        {
            maps7c[i].m_pObject->DecRefCount();
            maps7c[i].m_pObject = 0;
        }
    }
    for (int i = 0; i < 2; ++i)
    {
        if (maps8c[i].m_pObject)
        {
            maps8c[i].m_pObject->DecRefCount();
            maps8c[i].m_pObject = 0;
        }
    }
    m_spShaderDecl = reinterpret_cast<NiD3DShaderDeclaration*>(apDeclaration);
    m_field70 = 0.0f;
    m_afAmbientColor = DAT_011a9bd0;
    if (DAT_011f91c0 >= 2)
        m_usInstanceDataCount = 0xe4;
    else
        m_usInstanceDataCount = 0x50;
    m_uiInstanceData = new InstanceData_00bd5670[m_usInstanceDataCount];
    m_count98 = 0;
}
}  // namespace fnv_00bd5670
