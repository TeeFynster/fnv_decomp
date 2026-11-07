// bsshader/geometrydecalshader.cpp: GeometryDecalShader, DecalCls, Fx_Self (10 functions)

#include "../../include/BSShader.h"
#include "../../include/NiD3DGPUProgramCache.h"
#include "../../include/NiD3DVertexShader.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DShaderConstantMap.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

inline NiRefObject::~NiRefObject()
{}
inline void NiRefObject::DeleteThis()
{}
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

inline void NiD3DShaderConstantMap::IncRefCount()
{
    NiRefObject::IncRefCount();
}
inline void NiD3DShaderConstantMap::DecRefCount()
{
    NiRefObject::DecRefCount();
}

inline void NiGPUProgram::IncRefCount() throw()
{
    NiRefObject::IncRefCount();
}
inline void NiGPUProgram::DecRefCount() throw()
{
    NiRefObject::DecRefCount();
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (pkNew != 0)
            pkNew->IncRefCount();
    }
    return *this;
}

inline void NiD3DPass::IncRefCount()
{
    ++m_uiRefCount;
}
inline void NiD3DPass::DecRefCount()
{
    --m_uiRefCount;
    if (!m_uiRefCount)
        DestroyPass();
}
inline void NiD3DVertexShader::IncRefCount()
{
    NiRefObject::IncRefCount();
}
inline void NiD3DVertexShader::DecRefCount()
{
    NiRefObject::DecRefCount();
}
inline void NiD3DPixelShader::IncRefCount()
{
    NiRefObject::IncRefCount();
}
inline void NiD3DPixelShader::DecRefCount()
{
    NiRefObject::DecRefCount();
}

#include "../../include/_D3DXMACRO.h"

template <> NiPointer<NiD3DPass>::NiPointer();
template <> NiPointer<NiD3DPass>::~NiPointer();
template <> NiPointer<NiD3DVertexShader>::NiPointer();
template <> NiPointer<NiD3DVertexShader>::~NiPointer();
template <> NiPointer<NiD3DPixelShader>::NiPointer();
template <> NiPointer<NiD3DPixelShader>::~NiPointer();

class PassReference
{
  public:
    NiRefObject* m_pObject;
    PassReference() : m_pObject(0)
    {}
    ~PassReference()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    PassReference& operator=(NiRefObject* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

extern const char DAT_010bb750[];
extern "C" const char DAT_010A1E50[];
extern const char kSkinWorldViewProjTranspose[];
extern const char kBoneMatrix3[];
extern const char DAT_010bb744[];
extern const char g_011c72c0_arg1[];
extern const float DAT_012021d0[];
extern const float DAT_012021c0[];

class GeometryDecalShader : public BSShader
{
  public:
    NiPointer<NiD3DPass> m_spPasses[2];
    NiPointer<NiD3DVertexShader> m_spVertexShaders[2];
    NiPointer<NiD3DPixelShader> m_spPixelShaders[2];
    PassReference m_pkPass0;
    PassReference m_pkPass1;
    PassReference m_pkPass2;

    GeometryDecalShader();
    void UpdateShaderConstants();
    virtual void SetupPasses();
};

// @fnv 0x00bcbf00
GeometryDecalShader::GeometryDecalShader()
{
    iShaderType = 12;
    m_bUsesNiRenderState = true;
    m_pkPass0 = 0;
    m_pkPass1 = 0;
    m_pkPass2 = 0;
    for (int i = 0; i < 2; ++i)
        m_spPasses[i] = 0;
}

// GetEntry(const char*) occupies slot 0x70 in the game. The shared header's
// additional overload currently places that declaration at 0x74 under MSVC.
// Keep the original virtual dispatch until its overload order is corrected.
inline NiRefObject* LookupConstantMapEntry(NiD3DShaderConstantMap* map, const char* name)
{
    typedef NiRefObject* (__thiscall *Lookup)(NiD3DShaderConstantMap*, const char*);
    return reinterpret_cast<Lookup>((*reinterpret_cast<void***>(map))[28])(map, name);
}

// Lazily creates two NiD3DShaderConstantMap objects, adds shader constants to them, and stores the resulting entries in m_pkPass0/1/2.
// @fnv 0x00bcc2b0
void GeometryDecalShader::UpdateShaderConstants()
{
    if (!m_spPixelConstantMap.m_pObject)
    {
        m_spPixelConstantMap = new NiD3DShaderConstantMap(m_pkD3DRenderer, 2u);
        ((NiD3DShaderConstantMap*)m_spPixelConstantMap.m_pObject)
            ->SetConstant(DAT_010bb750, 0x10000007, 0, 15, 1, g_011c72c0_arg1, 16, 4, DAT_012021d0, false);
    }
    if (!m_spVertexConstantMap.m_pObject)
    {
        m_spVertexConstantMap = new NiD3DShaderConstantMap(m_pkD3DRenderer, 0u);
        ((NiD3DShaderConstantMap*)m_spVertexConstantMap.m_pObject)
            ->SetConstant(DAT_010A1E50, 0x20000009, 0, 0, 4, 0, 0, 0, 0, false);
        m_pkPass0 = LookupConstantMapEntry((NiD3DShaderConstantMap*)m_spVertexConstantMap.m_pObject, DAT_010A1E50);
        ((NiD3DShaderConstantMap*)m_spVertexConstantMap.m_pObject)
            ->AddConstant8(kSkinWorldViewProjTranspose, 0x20000009, 1, g_011c72c0_arg1, 0, 0, 0, false);
        m_pkPass1 =
            LookupConstantMapEntry((NiD3DShaderConstantMap*)m_spVertexConstantMap.m_pObject, kSkinWorldViewProjTranspose);
        ((NiD3DShaderConstantMap*)m_spVertexConstantMap.m_pObject)
            ->SetConstant(kBoneMatrix3, 0x20000009, 0x120000, 44, 54, 0, 0, 0, 0, false);
        m_pkPass2 = LookupConstantMapEntry((NiD3DShaderConstantMap*)m_spVertexConstantMap.m_pObject, kBoneMatrix3);
        ((NiD3DShaderConstantMap*)m_spVertexConstantMap.m_pObject)
            ->SetConstant(DAT_010bb744, 0x10000007, 0, 31, 1, g_011c72c0_arg1, 16, 4, DAT_012021c0, false);
    }
}

extern NiGPUProgram* DAT_012021e0;
extern NiGPUProgram* DAT_012021e4;

struct FUN_00bcbc90_shell
{
    NiGPUProgram* GeometryDecalShader_GetShaderDecl(void* obj, void* extra);
};

// @fnv 0x00bcbc90
// src: XBOX_PDB 0x00bcbc90
NiGPUProgram* __thiscall FUN_00bcbc90_shell::GeometryDecalShader_GetShaderDecl(void* obj, void* extra)
{
    return *(NiGPUProgram**)((char*)obj + 0xbc) ? DAT_012021e4 : DAT_012021e0;
}

extern NiGPUProgram* DAT_012021e0;
extern NiGPUProgram* DAT_012021e4;

struct FUN_00bcbc70_shell : public GeometryDecalShader
{
    void __thiscall CreateDecalShaders();
    void __thiscall GeometryDecalShader_ReloadShaders();
};

// @fnv 0x00bcbc70
// src: XBOX_PDB 0x00bcbc70
void __thiscall FUN_00bcbc70_shell::GeometryDecalShader_ReloadShaders()
{
    CreateDecalShaders();
    void(__thiscall * fn)(FUN_00bcbc70_shell*) = *(void(__thiscall**)(FUN_00bcbc70_shell*))(*(char**)this + 0x13c);
    fn(this);
}

void __cdecl _delete(void*, unsigned int);
struct FUN_00bcb210_shell
{
    void FUN_00bcb210();
};
struct FUN_00bcc070_shell
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00bcb210 on this, frees this with _delete when bit 0 of a is set, and returns this.
// @fnv 0x00bcc070
void* FUN_00bcc070_shell::DestroyIfFlagged(unsigned int a)
{
    ((FUN_00bcb210_shell*)this)->FUN_00bcb210();
    if (a & 1)
        _delete(this, 0x90);
    return this;
}

struct FUN_00bcb4d0_shell : public GeometryDecalShader
{
    void CreateDecalShaders();
};

struct ShaderSourceInfo
{
    const char* path;
    const char* macros[18];
};
void* _fnv_zlib_memset(void*, int, int);
int _sprintf_s(char*, unsigned int, const char*, ...);
extern const char DAT_01063f48[];

inline void AssignRef(PassReference& dst, const PassReference& src)
{
    if (dst.m_pObject != src.m_pObject)
    {
        if (dst.m_pObject)
            dst.m_pObject->DecRefCount();
        dst.m_pObject = src.m_pObject;
        if (dst.m_pObject)
            dst.m_pObject->IncRefCount();
    }
}

// @fnv 0x00bcb4d0
void FUN_00bcb4d0_shell::CreateDecalShaders()
{
    char pTempFileName[260];
    const char* pPixelShaderProfile;
    char pCacheFileName[260];
    PassReference* pShaderPasses = (PassReference*)((char*)this + 0x74);

    ShaderSourceInfo VSbaseParam;
    VSbaseParam.path = "lighting\\2x\\v\\decal.v.hlsl";
    VSbaseParam.macros[0] = "DECAL";
    VSbaseParam.macros[1] = g_011c72c0_arg1;
    VSbaseParam.macros[2] = "GEOMDECAL";
    VSbaseParam.macros[3] = g_011c72c0_arg1;
    VSbaseParam.macros[4] = "MAXDECALS";
    VSbaseParam.macros[5] = DAT_01063f48;
    VSbaseParam.macros[6] = 0;
    _fnv_zlib_memset(&VSbaseParam.macros[7], 0, 0x2c);
    BSShader::GetShaderPath(VSbaseParam.path, pCacheFileName);
    _sprintf_s(pTempFileName, 0x104, "GDECAL.vso");
    pShaderPasses[0] =
        CompileVertexShader(pCacheFileName, (const _D3DXMACRO*)VSbaseParam.macros, "vs_1_1", pTempFileName);

    ShaderSourceInfo vsSkinnedParams = {
        "lighting\\2x\\v\\decal.v.hlsl",
        {"DECAL", g_011c72c0_arg1, "GEOMDECAL", g_011c72c0_arg1, "MAXDECALS", DAT_01063f48, "SKIN", g_011c72c0_arg1}};
    BSShader::GetShaderPath(vsSkinnedParams.path, pCacheFileName);
    _sprintf_s(pTempFileName, 0x104, "GDECALS.vso");
    pShaderPasses[1] =
        CompileVertexShader(pCacheFileName, (const _D3DXMACRO*)vsSkinnedParams.macros, "vs_1_1", pTempFileName);

    pPixelShaderProfile = NiD3DGPUProgramCache::GetPixelShaderProfile(true);
    ShaderSourceInfo PSbaseParam;
    PSbaseParam.path = "lighting\\2x\\p\\decal.p.hlsl";
    PSbaseParam.macros[0] = "DECAL";
    PSbaseParam.macros[1] = g_011c72c0_arg1;
    PSbaseParam.macros[2] = "GEOMDECAL";
    PSbaseParam.macros[3] = g_011c72c0_arg1;
    PSbaseParam.macros[4] = "MAXDECALS";
    PSbaseParam.macros[5] = DAT_01063f48;
    PSbaseParam.macros[6] = 0;
    _fnv_zlib_memset(&PSbaseParam.macros[7], 0, 0x2c);
    BSShader::GetShaderPath(PSbaseParam.path, pCacheFileName);
    _sprintf_s(pTempFileName, 0x104, "GDECAL.pso");
    pShaderPasses[2] =
        CompilePixelShader(pCacheFileName, (const _D3DXMACRO*)PSbaseParam.macros, pPixelShaderProfile, pTempFileName);
    AssignRef(pShaderPasses[3], pShaderPasses[2]);
}

struct StageReturn
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int m_iRefCount;
    void ReturnToPool();
    void DecRefCount()
    {
        --m_iRefCount;
        if (m_iRefCount == 0)
            ReturnToPool();
    }
};

void __cdecl AssignStageFromPool(StageReturn*& pStage);

struct StagePtr
{
    StageReturn* p;
    StagePtr() : p(0)
    {}
    ~StagePtr()
    {
        if (p)
            p->DecRefCount();
    }
};

class D3DRenderStateGroup
{
  public:
    void SetNodeValue(int a, int b, int c);
};

D3DRenderStateGroup* __cdecl FUN_00e7f5d0();

// The shared pass currently omits the indexed stage setter. Keep only that
// declaration here, inheriting the shared layout and all other methods.
class IndexedD3DPass : public NiD3DPass
{
  public:
    void SetStage(unsigned int index, StageReturn* stage);
};

void __cdecl ConfigureBeamStage(StageReturn* pStage, int a, int b, int c, int d);

struct PtrPass
{
    NiD3DPass* m_pObject;
    PtrPass() : m_pObject(0)
    {}
    PtrPass(const PtrPass& other) : m_pObject(other.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~PtrPass()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    NiD3DPass* operator->() const
    {
        return m_pObject;
    }
    PtrPass& operator=(const PtrPass& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

extern const float DAT_01200458;

struct DecalCls : public BSShader
{
    PtrPass m_spPasses[2];
    NiPointer<NiD3DVertexShader> m_spVertexShaders[2];
    NiPointer<NiD3DPixelShader> m_spPixelShaders[2];
    PassReference m_pkPass0;
    PassReference m_pkPass1;
    PassReference m_pkPass2;

    void GeometryDecalShader_PresetPasses();
};

// Configures both passes: builds missing stages, assigns shaders, and sets map constants via SetNodeValue.
// @fnv 0x00bcb7f0
// src: COMMUNITY 0x00bcb7f0
void DecalCls::GeometryDecalShader_PresetPasses()
{
    PtrPass spRenderPass;
    StagePtr stagePtr;
    StageReturn*& pStage = stagePtr.p;
    spRenderPass = m_spPasses[0];
    unsigned int gateVal = spRenderPass->m_uiStageCount;
    if (gateVal < 2)
    {
        AssignStageFromPool(pStage);
        ConfigureBeamStage(pStage, 0, 1, 2, 1);
        static_cast<IndexedD3DPass*>(spRenderPass.m_pObject)->SetStage(spRenderPass->m_uiCurrentStage, pStage);
        AssignStageFromPool(pStage);
        ConfigureBeamStage(pStage, 1, 3, 2, 1);
        static_cast<IndexedD3DPass*>(spRenderPass.m_pObject)->SetStage(spRenderPass->m_uiCurrentStage, pStage);
    }
    spRenderPass->m_spVertexShader = m_spVertexShaders[0].m_pObject;
    spRenderPass->m_spPixelShader = m_spPixelShaders[0].m_pObject;
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0xa8, 15, 1);
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0x1b, 1, 1);
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0x13, 9, 1);
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0x14, 6, 1);
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0xf, 1, 1);
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0x19, 5, 1);
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0x18, 0, 1);
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0xe, 0, 1);
    {
        float fConst = DAT_01200458;
        int iConstBits = *(int*)&fConst;
        if (!spRenderPass->m_pkRenderStateGroup)
            spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
        spRenderPass->m_pkRenderStateGroup->SetNodeValue(0xc3, iConstBits, 1);
    }

    spRenderPass = m_spPasses[1];
    if (spRenderPass->m_uiStageCount < 2)
    {
        AssignStageFromPool(pStage);
        ConfigureBeamStage(pStage, 0, 1, 2, 1);
        static_cast<IndexedD3DPass*>(spRenderPass.m_pObject)->SetStage(spRenderPass->m_uiCurrentStage, pStage);
        AssignStageFromPool(pStage);
        ConfigureBeamStage(pStage, 1, 3, 2, 1);
        static_cast<IndexedD3DPass*>(spRenderPass.m_pObject)->SetStage(spRenderPass->m_uiCurrentStage, pStage);
    }
    spRenderPass->m_spVertexShader = m_spVertexShaders[1].m_pObject;
    spRenderPass->m_spPixelShader = m_spPixelShaders[1].m_pObject;
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0xa8, 15, 1);
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0x1b, 1, 1);
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0x13, 9, 1);
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0x14, 6, 1);
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0xf, 1, 1);
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0x19, 5, 1);
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0x18, 0, 1);
    {
        float fConst = DAT_01200458;
        int iConstBits = *(int*)&fConst;
        if (!spRenderPass->m_pkRenderStateGroup)
            spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
        spRenderPass->m_pkRenderStateGroup->SetNodeValue(0xc3, iConstBits, 1);
    }
    if (!spRenderPass->m_pkRenderStateGroup)
        spRenderPass->m_pkRenderStateGroup = FUN_00e7f5d0();
    spRenderPass->m_pkRenderStateGroup->SetNodeValue(0xe, 0, 1);
}

// Sets a field on the pass object owned by the global renderer from the shader's data,
// then tail-calls a __thiscall member on that pass object (callee pops 4 bytes, so the
// caller must be __stdcall for the jmp tail call).
struct PassOwner
{
    int unk00;
    NiD3DPass* unk04;
};
struct GlobalRendererState
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    PassOwner* unk24;
};
struct ShaderParams
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78;
    int unk7c;
};
struct ShaderInput
{
    int unk00;
    int unk04;
    int unk08;
    ShaderParams* unk0c;
};
extern GlobalRendererState* DAT_0126f74c;

// Copies the shader parameter into the pass's name storage, then applies render state changes.
// @fnv 0x00bcbcb0
void __stdcall ApplyShaderInputToPass(ShaderInput* apInput)
{
    NiD3DPass* pPass = DAT_0126f74c->unk24->unk04;
    *reinterpret_cast<int*>(&pPass->m_szName[4]) = apInput->unk0c->unk7c;
    pPass->ApplyRenderStateChanges(false);
}

struct NiRenderer;
extern NiRenderer* DAT_011f9508;
NiGPUProgram* __cdecl NiDX9ShaderDeclaration_Create(NiRenderer*, unsigned int, unsigned int);
struct ProgramView : NiGPUProgram
{
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void SetEntry(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Finish();
};
inline void SetProgram(NiGPUProgram*& destination, NiGPUProgram* object)
{
    if (destination != object)
    {
        if (destination)
            destination->DecRefCount();
        destination = object;
        if (object)
            object->IncRefCount();
    }
}
// Builds two GPU programs with entry points, creates a GeometryDecalShader, initializes its passes, and binds the first program.
// @fnv 0x00bcc0a0
GeometryDecalShader* __cdecl CreateGeometryDecalShader()
{
    SetProgram(DAT_012021e0, NiDX9ShaderDeclaration_Create(DAT_011f9508, 2, 1));
    SetProgram(DAT_012021e4, NiDX9ShaderDeclaration_Create(DAT_011f9508, 4, 1));
    static_cast<ProgramView*>(DAT_012021e0)->SetEntry(0, 0, 0, 2, 0);
    static_cast<ProgramView*>(DAT_012021e0)->SetEntry(1, 3, 3, 2, 0);
    static_cast<ProgramView*>(DAT_012021e0)->Finish();
    static_cast<ProgramView*>(DAT_012021e4)->SetEntry(0, 0, 0, 2, 0);
    static_cast<ProgramView*>(DAT_012021e4)->SetEntry(1, 1, 1, 3, 0);
    static_cast<ProgramView*>(DAT_012021e4)->SetEntry(2, 2, 2, 4, 0);
    static_cast<ProgramView*>(DAT_012021e4)->SetEntry(3, 3, 3, 2, 0);
    static_cast<ProgramView*>(DAT_012021e4)->Finish();
    GeometryDecalShader* shader = new GeometryDecalShader;
    shader->Initialize();
    static_cast<FUN_00bcb4d0_shell*>(shader)->CreateDecalShaders();
    for (unsigned int i = 0; i < 2; ++i)
        NiD3DPass::CreateD3DPass(shader->m_spPasses[i]);
    shader->SetupPasses();
    shader->InitShaderConstants();
    shader->UseShaderDeclaration(reinterpret_cast<NiD3DShaderDeclaration*>(DAT_012021e0));
    return shader;
}

struct Fx_Sub34
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
};
struct Fx_Mgr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int* unk20;
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
    Fx_Sub34* unkb8;
    int unkbc;
};
struct Fx_Param;
struct Fx_Hook
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Call(int a, Fx_Mgr* b, int c, int d, int e, Fx_Param* f, int g, int* h, int* i, int j, int k);
};
struct Fx_Sub
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
    float unk28;
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
    float unkbc;
    unsigned char unkc0;
};
struct Fx_Param
{
    int unk00;
    int unk04;
    int unk08;
    Fx_Sub* unk0c;
};
struct Fx_State
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
};
struct Fx_Obj18
{
    void Fx_Run(int* p, int z);
};
struct Fx_Self
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Fx_Obj18* unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Fx_Hook* unk30;
    Fx_Hook* unk34;
    void UpdateColorAndPower(Fx_Param* a0);
};
struct Fx_Color
{
    float r, g, b, a;
};
extern Fx_Mgr** DAT_011f91e0;
extern int DAT_011f4288[];
extern float DAT_01016248;
__forceinline float fx_pow10(float x)
{
    float r = 1.0f;
    unsigned int n = 10;
    for (;;)
    {
        if (n & 1)
            r *= x;
        n >>= 1;
        if (!n)
            return r;
        x *= x;
    }
}
inline void fx_dispatch44(Fx_Hook* h, Fx_Mgr* m, int l, int e, Fx_Param* a0, int* v, int* p)
{
    if (h && reinterpret_cast<Fx_State*>(DAT_0126f74c)->unk44)
        h->Call(reinterpret_cast<Fx_State*>(DAT_0126f74c)->unk44, m, l, 0, e, a0, 0, v, p, 0, 1);
}
inline void fx_dispatch5c(Fx_Hook* h, Fx_Mgr* m, int l, int e, Fx_Param* a0, int* v, int* p)
{
    if (h && reinterpret_cast<Fx_State*>(DAT_0126f74c)->unk5c)
        h->Call(reinterpret_cast<Fx_State*>(DAT_0126f74c)->unk5c, m, l, 0, e, a0, 0, v, p, 0, 1);
}
// Runs the sub-object, sets a global color from s->unkc0, stores 1-pow10(unkbc) and unk28, then dispatches hooks unk30 and unk34.
// @fnv 0x00bcbce0
void Fx_Self::UpdateColorAndPower(Fx_Param* apParam)
{
    Fx_Mgr* m = *DAT_011f91e0;
    int* v = &m->unk68;
    int* p = m->unk20;
    if (!p)
        p = DAT_011f4288;
    int e = m->unkb8->unk34;
    int l = m->unkbc;
    Fx_Sub* pSub = apParam->unk0c;
    unk18->Fx_Run(v, 0);
    Fx_Color* pGlobalColor = reinterpret_cast<Fx_Color*>(const_cast<float*>(DAT_012021d0));
    Fx_Color c;
    switch (pSub->unkc0)
    {
    case 0:
        c.r = 0.0f;
        c.g = DAT_01016248;
        c.b = 0.0f;
        c.a = DAT_01016248;
        *pGlobalColor = c;
        break;
    case 1:
        c.r = DAT_01016248;
        c.g = DAT_01016248;
        c.b = 0.0f;
        c.a = DAT_01016248;
        *pGlobalColor = c;
        break;
    case 2:
        c.r = 0.0f;
        c.g = DAT_01016248;
        c.b = DAT_01016248;
        c.a = DAT_01016248;
        *pGlobalColor = c;
        break;
    case 3:
        c.r = DAT_01016248;
        c.g = DAT_01016248;
        c.b = DAT_01016248;
        c.a = DAT_01016248;
        *pGlobalColor = c;
        break;
    }
    float* h = const_cast<float*>(DAT_012021c0);
    volatile float pw = fx_pow10(pSub->unkbc);
    h[0] = 1.0f - pw;
    h[1] = pSub->unk28;
    fx_dispatch44(unk30, m, l, e, apParam, v, p);
    fx_dispatch5c(unk34, m, l, e, apParam, v, p);
}
