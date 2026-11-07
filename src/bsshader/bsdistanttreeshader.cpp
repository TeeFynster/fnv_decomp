// bsshader/bsdistanttreeshader.cpp: ZTree, This, BSDistantTreeShaderPasses, GeomShader (14 functions)

#include <new>

#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/BSShader.h"
#include "../../include/NiD3DDefaultShader.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiD3DShaderDeclaration.h"
#include "../../include/NiD3DShaderInterface.h"
#include "../../include/NiShader.h"
#include "../../include/NiShaderConstantMap.h"
#include "../../include/NiShaderDeclaration.h"
#include "../../include/NiColorA.h"
#include "../../include/NiD3DVertexShader.h"
#include "../../include/NiD3DPixelShader.h"

// Use the shared reference object throughout this translation unit.
#define FNV_NIREFOBJECT_H
#include "bsdistanttreeshader_decls.h"

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

inline void NiD3DPass::IncRefCount() { ++m_uiRefCount; }
inline void NiD3DPass::DecRefCount()
{
    if (--m_uiRefCount == 0)
        FUN_00e80190();
}
inline NiColorA::NiColorA(float red, float green, float blue, float alpha)
    : r(red), g(green), b(blue), a(alpha) {}

extern int g_012007bc;

// @fnv 0x00bb6490
// src: XBOX_PDB 0x00bb6490
int* __cdecl BSDistantTreeShader_GetRTTI()
{
    return &g_012007bc;
}

extern int DAT_0126f74c;
struct Unknown_00bb62b0
{
    char _0[0x6c];
    int m_6c;
    int m_70;
    char _1[0xc];
    NiGPUProgram* m_80;
    NiPointer_NiGPUProgram_& BSDistantTreeShader_InitPass(int);
};
// Stores m_6c or m_70 into DAT_0126f74c based on a, then replaces the GPU program pointer at offset 0x28 with m_80.
// @fnv 0x00bb62b0
// src: XBOX_PDB 0x00bb62b0
NiPointer_NiGPUProgram_& Unknown_00bb62b0::BSDistantTreeShader_InitPass(int a)
{
    switch (a)
    {
    case 0x236:
        DAT_0126f74c = m_6c;
        return ((NiPointerDispatch*)((char*)this + 0x28))->Replace(m_80);
    case 0x237:
        DAT_0126f74c = m_70;
        return ((NiPointerDispatch*)((char*)this + 0x28))->Replace(m_80);
    }
}

void __cdecl BSRenderState_SetWireframeEnable(int, int);
struct S_00bb6b60_a
{
    char _0[0x24];
    unsigned int m_24;
};
struct S_00bb6b60_b
{
    char _0[0xC];
    S_00bb6b60_a* m_C;
};
// @fnv 0x00bb6b60
// src: XBOX_PDB 0x00bb6b60
void __stdcall BSDistantTreeShader_PostGeometry(S_00bb6b60_b* p)
{
    S_00bb6b60_a* pFlagHolder = p->m_C;
    if (pFlagHolder && ((pFlagHolder->m_24 & 0x10000) > 0))
        BSRenderState_SetWireframeEnable(0, 0);
}

void __cdecl _delete(void*, unsigned int);
struct Struct00bb6e00
{
    void FUN_00bb6300();
    void* FUN_00bb6e00(unsigned int);
};
// Calls FUN_00bb6300, then deletes this with size 0xfc when flags has bit 0 set, and returns this.
// @fnv 0x00bb6e00
void* Struct00bb6e00::FUN_00bb6e00(unsigned int flags)
{
    FUN_00bb6300();
    if (flags & 1)
        _delete(this, 0xfc);
    return this;
}

struct FUN_00bb6060_shell : public BSDistantTreeShader
{
    void BSDistantTreeShader_LoadShaders();
};

int _sprintf_s(char*, unsigned int, const char*, ...);
void __cdecl FUN_00be0c00(const char*, char*);
void* fnv_zlib_memset(void*, int, int);
struct ShMacro
{
    const char* Name;
    const char* Definition;
};
struct ShaderSourceInfo
{
    const char* pFile;
    ShMacro macros[9];
};
struct ShRefObj
{
    virtual void S0();
    virtual void DeleteThis();
    long m_lRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRefCount) == 0)
            DeleteThis();
    }
};
struct ShPtr
{
    ShRefObj* m_pObject;
    ShPtr& operator=(ShRefObj* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

// @fnv 0x00bb6060
// src: COMMUNITY 0x00bb6060
void FUN_00bb6060_shell::BSDistantTreeShader_LoadShaders()
{
    char tempName[260];
    ShaderSourceInfo vertexShaderParams;
    char cacheName[260];
    ShaderSourceInfo pixelShaderParams;
    ShaderSourceInfo pixelShaderParamsSilhouette;

    vertexShaderParams.pFile = "distanttree\\DistantTree.v.hlsl";
    vertexShaderParams.macros[0].Name = "DTTEST";
    vertexShaderParams.macros[0].Definition = "";
    vertexShaderParams.macros[1].Name = 0;
    fnv_zlib_memset(&vertexShaderParams.macros[1].Definition, 0, 0x3c);
    pixelShaderParams.pFile = "distanttree\\DistantTree.p.hlsl";
    pixelShaderParams.macros[0].Name = "DTTEST";
    pixelShaderParams.macros[0].Definition = "";
    pixelShaderParams.macros[1].Name = 0;
    fnv_zlib_memset(&pixelShaderParams.macros[1].Definition, 0, 0x3c);
    pixelShaderParamsSilhouette.pFile = "distanttree\\DistantTree.p.hlsl";
    pixelShaderParamsSilhouette.macros[0].Name = "DTTEST";
    pixelShaderParamsSilhouette.macros[0].Definition = "";
    pixelShaderParamsSilhouette.macros[1].Name = "SILHOUETTE";
    pixelShaderParamsSilhouette.macros[1].Definition = "";
    pixelShaderParamsSilhouette.macros[2].Name = 0;
    fnv_zlib_memset(&pixelShaderParamsSilhouette.macros[2].Definition, 0, 0x34);

    char* pThis = (char*)this;
    FUN_00be0c00(vertexShaderParams.pFile, cacheName);
    _sprintf_s(tempName, 260, "DISTTREE.vso");
    *(ShPtr*)(pThis + 0x74) =
        (ShRefObj*)CompileVertexShader(cacheName, (const _D3DXMACRO*)vertexShaderParams.macros, "vs_1_1", tempName);
    FUN_00be0c00(pixelShaderParams.pFile, cacheName);
    _sprintf_s(tempName, 260, "DISTTREE.pso");
    *(ShPtr*)(pThis + 0x78) =
        (ShRefObj*)CompilePixelShader(cacheName, (const _D3DXMACRO*)pixelShaderParams.macros, "ps_2_a", tempName);
    FUN_00be0c00(pixelShaderParamsSilhouette.pFile, cacheName);
    _sprintf_s(tempName, 260, "DISTTREESil.pso");
    *(ShPtr*)(pThis + 0x7c) = (ShRefObj*)CompilePixelShader(
        cacheName, (const _D3DXMACRO*)pixelShaderParamsSilhouette.macros, "ps_2_a", tempName);
}

extern MemoryManager g_memoryManager;
inline void FreeTreeMemory(void* ptr)
{
    g_memoryManager.Deallocate(ptr);
}
struct FUN_00bb6300 : BSShader
{
    NiPointer<NiD3DPass> passes[2];
    NiPointer<ShRefObj> vertex[1];
    NiPointer<ShRefObj> pixels[2];
    NiPointer<ShRefObj> decl;
    NiColorA fog[2];
    unsigned int count;
    void* instances;
    virtual ~FUN_00bb6300();
};
// Releases the shader's pass, vertex, pixel and declaration references, frees the instances buffer, and clears the declaration pointer.
// @fnv 0x00bb6300
FUN_00bb6300::~FUN_00bb6300()
{
    for (unsigned int i = 0; i < 2; ++i)
        passes[i] = 0;
    for (unsigned int i = 0; i < 1; ++i)
        vertex[i] = 0;
    for (unsigned int i = 0; i < 2; ++i)
        pixels[i] = 0;
    FreeTreeMemory(instances);
    decl = 0;
}

extern "C" void* __cdecl memmove(void* dst, const void* src, unsigned int size);

extern unsigned int DAT_012007b8;
extern "C" int fnv_particle_shader_renderer_level;

struct BB6B90Particle
{
    float m_fVectorY;
    float m_fVectorX;
    float m_fScalarPart;
    float m_fVectorZ;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct BB6B90ParticleData
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
    unsigned int m_uiActive;
    BB6B90Particle* m_pkParticles;
};

struct BB6B90ParticleSource
{
    int unk00;
    int unk04;
    int unk08;
    BB6B90ParticleData* m_pUserData;
};

struct BB6B90ParticleShader
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
    int unk9C;
    int unkA0;
    int unkA4;
    BB6B90Particle* m_pkParticles;

    static unsigned int GetMaxParticles()
    {
        if (!DAT_012007b8)
            DAT_012007b8 = fnv_particle_shader_renderer_level >= 2 ? 114 : 40;
        return DAT_012007b8;
    }

    void CopyParticlesFromSource(BB6B90ParticleSource* source);
};

// @fnv 0x00bb6b90
void BB6B90ParticleShader::CopyParticlesFromSource(BB6B90ParticleSource* source)
{
    BB6B90ParticleData* data = source->m_pUserData;
    unsigned long active = data->m_uiActive;
    memmove(m_pkParticles, data->m_pkParticles, active * sizeof(BB6B90Particle));
    unsigned long i = active;
    unsigned int max = GetMaxParticles();
    if (i < max)
    {
        while (max > i)
        {
            m_pkParticles[i].m_fVectorY = 0.0f;
            m_pkParticles[i].m_fVectorX = 0.0f;
            m_pkParticles[i].m_fScalarPart = -100000.0f;
            m_pkParticles[i].m_fVectorZ = 0.0f;
            ++i;
        }
    }
}

extern MemoryManager g_memoryManager;


struct DistantTreeInstance
{
    float x;
    float y;
    float z;
    float w;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    static unsigned int GetMaxCount()
    {
        if (!DAT_012007b8)
            DAT_012007b8 = fnv_particle_shader_renderer_level >= 2 ? 114 : 40;
        return DAT_012007b8;
    }
    static void* operator new[](unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
};



struct DistantTreeFogColors
{
    // Construct the shared colors in a loop, as the original array initialization does.
    __declspec(align(4)) unsigned char storage[2 * sizeof(NiColorA)];
    __forceinline DistantTreeFogColors()
    {
        NiColorA* p = reinterpret_cast<NiColorA*>(storage);
        int count = 1;
        do
        {
            __assume(p != 0);
            new (p) NiColorA();
            ++p;
        } while (--count >= 0);
    }
};


struct FUN_00bb6c30 : public BSShader
{
    NiPointer<NiD3DPass> spRenderPass[2];
    NiPointer<NiD3DVertexShader> m_spTreeVertexShader[1];
    NiPointer<NiD3DPixelShader> m_spPixelShaderVariants[2];
    NiPointer<NiD3DVertexDeclaration> m_spVertexDeclaration;
    DistantTreeFogColors m_kFogColors;
    unsigned int m_uiInstanceCount;
    DistantTreeInstance* m_pInstances;
    NiColorA m_kColor1;
    NiColorA m_kColor2;
    NiColorA m_kColor3;
    NiColorA m_kColor4;
    NiColorA m_kColor5;

    FUN_00bb6c30(NiD3DVertexDeclaration* pDecl);
    virtual ~FUN_00bb6c30();
    virtual BSShader* CreateShader();
};

// Initializes the shader: stores the declaration, sets a value to 25, and allocates the instance array sized by GetMaxCount().
// @fnv 0x00bb6c30
FUN_00bb6c30::FUN_00bb6c30(NiD3DVertexDeclaration* pDecl)
{
    iShaderType = 25;
    m_spVertexDeclaration = pDecl;
    m_pInstances = new DistantTreeInstance[DistantTreeInstance::GetMaxCount()];
}

namespace fnv_00bb6e30 {
struct TreeVertexDecl
{
    virtual void Slot0();
    virtual void Slot1();
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
    virtual void SetElement(int, int, int, int, int);
    virtual void Slot36();
    virtual void SetConstant(int, int, int, unsigned int, int, int, int, int);
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Finalize();
};

TreeVertexDecl* NiDX9ShaderDeclaration_Create(void*, int, bool);
void* Object_DispatchCommandFour(unsigned int);
struct FUN_00bb6c30
{
    virtual void Slot0();
    virtual void Slot1();
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
    virtual void Initialize();
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
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void SetDecl(TreeVertexDecl*);
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Complete();
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
    static void* operator new(unsigned int bytes)
    {
        return Object_DispatchCommandFour(bytes);
    }
    FUN_00bb6c30(TreeVertexDecl*);
    void BSDistantTreeShader_LoadShaders();
    void BSDistantTreeShader_LoadStagesAndPasses();
};
// @fnv 0x00bb6e30
FUN_00bb6c30* CreateTreeShader()
{
    TreeVertexDecl* declaration = NiDX9ShaderDeclaration_Create(DAT_011f9508, 4, true);
    declaration->SetElement(0, 0, 0, 2, 0);
    declaration->SetElement(1, 1, 5, 1, 0);
    declaration->SetElement(2, 2, 3, 2, 0);
    declaration->SetConstant(0, 3, 3, 0x80000000u, 0, 5, 1, 0);
    declaration->Finalize();
    FUN_00bb6c30* shader = new FUN_00bb6c30(declaration);
    shader->Initialize();
    shader->BSDistantTreeShader_LoadShaders();
    shader->BSDistantTreeShader_LoadStagesAndPasses();
    shader->Complete();
    shader->SetDecl(declaration);
    return shader;
}
}  // namespace fnv_00bb6e30

struct ZVec
{
    float x, y, z;
    void Unitize_004a0c10();
};
struct ZFog
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ZVec unk20;
    float unk2C, unk30;
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
    float unk60;
};
struct ZLight
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    ZVec unkC8, unkD4;
    int unkE0, unkE4, unkE8, unkEC;
    ZVec unkF0;
};
struct ZNode
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    ZLight* unkF8;
};
struct ZScene
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    ZNode* unkE0;
};
struct ZRenderer
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    ZScene* unk194;
};
struct ZSky
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    NiColorA unk154;
};
ZFog* __cdecl BSShaderManager_GetFogProperty(int);
ZRenderer* __cdecl BSShaderManager_GetAccumulator();
ZSky* __cdecl BSShaderManager_GetCurrentAccumulator();
extern unsigned char DAT_011f91c4;
extern unsigned int DAT_011f91b8;
extern NiColorA DAT_011a9bd0;
struct ZTree
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
    NiColorA unk84, unk94;
    int unkA4, unkA8;
    NiColorA unkAC, unkBC, unkCC;
    void UpdateLighting(int);
};
// Sets the tree's fog and ambient/directional light colors from the current fog, sky, or scene light, depending on DAT_011f91b8.
// @fnv 0x00bb6700
void ZTree::UpdateLighting(int arg)
{
    ZFog* fog = BSShaderManager_GetFogProperty(DAT_011f91c4);
    if (fog)
    {
        float fFogStart = fog->unk2C;
        float fFogEnd = fog->unk30;
        ZVec fogColor = fog->unk20;
        float power = fog->unk60;
        if (fFogEnd == 0.0f && fFogStart == 0.0f)
        {
            unk84 = NiColorA(500000.0f, 0.0f, power, 0.0f);
            unk94 = DAT_011a9bd0;
        }
        else
        {
            unk84 = NiColorA(fFogEnd, fFogEnd - fFogStart, power, 0.0f);
            unk94 = NiColorA(fogColor.x, fogColor.y, fogColor.z, 1.0f);
        }
    }
    if (DAT_011f91b8 == 15)
    {
        unkAC = BSShaderManager_GetCurrentAccumulator()->unk154;
        unkCC = DAT_011a9bd0;
        unkBC = DAT_011a9bd0;
        return;
    }
    ZLight* light = BSShaderManager_GetAccumulator()->unk194->unkE0->unkF8;
    if (light)
    {
        ZVec lightDir = light->unkF0;
        lightDir.Unitize_004a0c10();
        ZVec ambient = light->unkC8;
        unkAC = NiColorA(ambient.x, ambient.y, ambient.z, 1.0f);
        ambient = light->unkD4;
        unkCC = NiColorA(ambient.x, ambient.y, ambient.z, 1.0f);
        unkBC = NiColorA(-lightDir.x, -lightDir.y, -lightDir.z, 1.0f);
    }
}

extern unsigned int DAT_012007b8;
extern char DAT_01011584;


static void AssignRef(NiD3DShaderConstantMap*& slot, NiD3DShaderConstantMap* nobj)
{
    NiD3DShaderConstantMap* old = slot;
    if (old != nobj)
    {
        if (old && InterlockedDecrement((long*)((char*)old + 4)) == 0)
            old->DeleteThis();
        slot = nobj;
        if (nobj)
            InterlockedIncrement((long*)((char*)nobj + 4));
    }
}

struct This
{
    char pad00[0x18];
    unsigned int m_18;
    char pad1c[0x30 - 0x1c];
    NiD3DShaderConstantMap* m_30;
    NiD3DShaderConstantMap* m_34;
    char pad38[0x84 - 0x38];
    char m_84[0xa8 - 0x84];
    void* m_a8;
    char m_ac[0xbc - 0xac];
    char m_bc[0xcc - 0xbc];
    char m_cc[0xdc - 0xcc];

    void InitShaderParams();
};

// Creates the two NiD3DShaderConstantMap instances if missing and, for the second, registers the WorldViewProjTranspose, fog, instances and light shader parameters.
// @fnv 0x00bb6f40
void This::InitShaderParams()
{
    if (this->m_30 == 0)
    {
        NiD3DShaderConstantMap* nobj = new NiD3DShaderConstantMap(this->m_18, 2u);
        AssignRef(this->m_30, nobj);
    }
    if (this->m_34 == 0)
    {
        NiD3DShaderConstantMap* nobj = new NiD3DShaderConstantMap(this->m_18, 0u);
        AssignRef(this->m_34, nobj);
        this->m_34->SetConstant("WorldViewProjTranspose", 0x20000009, 0, 0, 4, 0, 0, 0, 0, 0);
        this->m_34->SetConstant("fog", 0x10000009, 0, 4, 2, &DAT_01011584, 0x20, 4, &this->m_84, 0);
        this->m_34->SetConstant("instances", 0x10000009, 0, 9, DAT_012007b8 + DAT_012007b8, &DAT_01011584,
                             DAT_012007b8 << 5, 4, this->m_a8, 0);
        this->m_34->SetConstant("Diffuse Light direction", 0x10000007, 0, 6, 1, &DAT_01011584, 0x10, 4, &this->m_bc, 0);
        this->m_34->SetConstant("Diffuse Light color", 0x10000007, 0, 7, 1, &DAT_01011584, 0x10, 4, &this->m_cc, 0);
        this->m_34->SetConstant("ambient color", 0x10000007, 0, 8, 1, &DAT_01011584, 0x10, 4, &this->m_ac, 0);
    }
}


// Texture stage: pooled object, plain (non-atomic) refcount at +0x60.
struct TreeTextureStage : public BeamStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        ++m_uiRefCount;
    }
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
            ReturnToPool();
    }
};


struct BSDistantTreeShaderPasses : public BSDistantTreeShader
{
    bool BSDistantTreeShader_LoadStagesAndPasses();
    NiD3DPass* GetPassData(int i)
    {
        return (NiD3DPass*)spRenderPass[i];
    }
};

// Creates two D3D passes, configures a beam texture stage for each, and assigns the tree vertex and pixel shader variants to the pass data.
// @fnv 0x00bb64a0
// src: COMMUNITY 0x00bb64a0
bool BSDistantTreeShaderPasses::BSDistantTreeShader_LoadStagesAndPasses()
{
    NiD3DPass::CreateD3DPass(spRenderPass[0]);
    NiPointer<TreeTextureStage> spStage;
    BeamStage::CreateNewStage((NiPointer<BeamStage>&)spStage);
    ConfigureBeamStage(spStage, 0, 3, 2, true);
    spStage->NiD3DTextureStage_SetFilterMode(1);
    spRenderPass[0]->NiD3DPass_SetStage(GetPassData(0)->m_uiCurrentStage, spStage);
    GetPassData(0)->m_spVertexShader = (NiD3DVertexShader*)m_spTreeVertexShader;
    GetPassData(0)->m_spPixelShader = (NiD3DPixelShader*)m_spPixelShaderVariants[0];

    NiD3DPass::CreateD3DPass(spRenderPass[1]);
    spStage = 0;
    BeamStage::CreateNewStage((NiPointer<BeamStage>&)spStage);
    ConfigureBeamStage(spStage, 0, 3, 2, true);
    spStage->NiD3DTextureStage_SetFilterMode(1);
    spRenderPass[1]->NiD3DPass_SetStage(GetPassData(1)->m_uiCurrentStage, spStage);
    GetPassData(1)->m_spVertexShader = (NiD3DVertexShader*)m_spTreeVertexShader;
    GetPassData(1)->m_spPixelShader = (NiD3DPixelShader*)m_spPixelShaderVariants[1];

    return true;
}

struct FUN_00bb66b0
{
    void BSDistantTreeShader_LoadShaders();
    void BSDistantTreeShader_LoadStagesAndPasses();
    void Call();
};

// @fnv 0x00bb66b0
void FUN_00bb66b0::Call()
{
    BSDistantTreeShader_LoadShaders();
    BSDistantTreeShader_LoadStagesAndPasses();
}

struct GeomB8
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
};
struct GeomObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char* unk20;
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    GeomB8* unkB8;
    int unkBC;
};
struct GeomRenderer
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V0A();
    virtual void V0B();
    virtual void V0C();
    virtual void V0D();
    virtual void V0E();
    virtual void V0F();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V1A();
    virtual void V1B();
    virtual void V1C();
    virtual void V1D();
    virtual void Render(int a, GeomObj* geom, int b, int c, int d, int e, int f, int* g, char* name, int h, int i);
};
struct GeomPass
{
    void NiDX9Renderer_SetModelTransform(int* p, int b);
};
struct GeomSettings
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
};
extern GeomObj** DAT_011f91e0;
extern char DAT_011f4288[];
struct GeomShader
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V0A();
    virtual void V0B();
    virtual void V0C();
    virtual void V0D();
    virtual void V0E();
    virtual void V0F();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V1A();
    virtual void V1B();
    virtual void V1C();
    virtual void V1D();
    virtual void V1E();
    virtual void V1F();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V2A();
    virtual void V2B();
    virtual void V2C();
    virtual void V2D();
    virtual void V2E();
    virtual void V2F();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V3A();
    virtual void V3B();
    virtual void V3C();
    virtual void V3D();
    virtual void V3E();
    virtual void V3F();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V4A();
    virtual void V4B();
    virtual void V4C();
    virtual void V4D();
    virtual void V4E();
    virtual void SetupGeometry(int arg);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    GeomPass* unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    GeomRenderer* unk30;
    GeomRenderer* unk34;
    void RenderGeometry(int arg);
};
// Sets up geometry, then calls Render on the two GeomRenderer slots if their settings flags are non-zero.
// @fnv 0x00bb6a80
void GeomShader::RenderGeometry(int arg)
{
    GeomObj* geom = *DAT_011f91e0;
    int* bound = &geom->unk68;
    char* name = geom->unk20;
    if (!name)
        name = DAT_011f4288;
    int b8 = geom->unkB8->unk34;
    int bc = geom->unkBC;
    SetupGeometry(arg);
    unk18->NiDX9Renderer_SetModelTransform(bound, 0);
    GeomRenderer* r = unk30;
    if (r)
    {
        int iSetting = ((GeomSettings*)DAT_0126f74c)->unk44;
        if (iSetting)
            r->Render(iSetting, geom, bc, 0, b8, arg, 0, bound, name, 0, 1);
    }
    r = unk34;
    if (r)
    {
        int iSetting = ((GeomSettings*)DAT_0126f74c)->unk5C;
        if (iSetting)
            r->Render(iSetting, geom, bc, 0, b8, arg, 0, bound, name, 0, 1);
    }
}
