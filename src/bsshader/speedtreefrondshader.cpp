
// src/bsshader/speedtreefrondshader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/speedtreefrondshader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BSFadeNode.h"
#include "../../include/NiD3DGPUProgramCache.h"
#include "../../include/NiD3DShaderConstantMap.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct NiRefObject_s
{
    virtual ~NiRefObject_s();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
inline void NiD3DShaderConstantMap::IncRefCount()
{
    InterlockedIncrement((long volatile*)&m_uiRefCount);
}

inline void NiD3DShaderConstantMap::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}

template <class T> class NiPointer_s
{
  public:
    T* m_pObject;
    NiPointer_s& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    bool operator==(T* pObject) const
    {
        return m_pObject == pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
};
struct SpeedTreeLeafShaderConstantMapSetup
{
    static void __cdecl ConfigureShaderConstantMap(NiD3DShaderConstantMap*, int);
};

extern const char _DAT_010A1E50[];
extern const char _DAT_010AF568[];
extern const char _DAT_010B92F8[];
extern const char _DAT_010B92E8[];
extern const char _DAT_010AF60C[];
extern const char _DAT_010AF5E4[];
extern const char _DAT_010B92DC[];
extern float _DAT_011FA0C0[4];
extern float _DAT_011FA0D0[4];
extern float _DAT_011FA0E0[4];
extern float DAT_011fa1f0[4];
extern float _DAT_011FA280[4];
extern float _DAT_011FA290[4];
extern float _DAT_011F918C;
extern bool _DAT_011F941E;

struct SpeedTreeFrondShader_s
{
    char pad0[0x18];
    void* m_pOwnerShader;
    char pad1[0x34 - 0x1c];
    NiPointer_s<NiD3DShaderConstantMap> m_spConstantMap;
    char pad2[0x88 - 0x38];
    float m_kPointLightPos[4];
    float m_kDirectionalLightDir[4];
    void CreateConstantMap();
};

// @fnv 0x00bd3000
void SpeedTreeFrondShader_s::CreateConstantMap()
{
    if (!(m_spConstantMap == 0))
        return;

    unsigned int uiPoint4Flags = 0x10000007;
    unsigned int idefinedMatrix4Flags = 0x20000009;
    unsigned int uiPoint1Flags = 0x10000004;

    m_spConstantMap = new NiD3DShaderConstantMap(m_pOwnerShader, 0);
    m_spConstantMap->SetConstant(_DAT_010A1E50, idefinedMatrix4Flags, 0, 0, 4, 0, 0, 0, 0, false);
    m_spConstantMap->SetConstant(_DAT_010AF568, uiPoint4Flags, 0, 5, 1, "", 0x10, 4, _DAT_011FA0C0, false);
    m_spConstantMap->SetConstant(_DAT_010B92F8, uiPoint4Flags, 0, 6, 1, "", 0x10, 4, _DAT_011FA0D0, false);
    m_spConstantMap->SetConstant(_DAT_010B92E8, uiPoint4Flags, 0, 7, 1, "", 0x10, 4, _DAT_011FA0E0, false);
    m_spConstantMap->SetConstant("DirectronalLightDir", uiPoint4Flags, 0, 8, 1, "", 0x10, 4, m_kDirectionalLightDir,
                              false);
    m_spConstantMap->SetConstant("PointLightPos", uiPoint4Flags, 0, 9, 1, "", 0x10, 4, m_kPointLightPos, false);
    m_spConstantMap->SetConstant("LightRadius", uiPoint4Flags, 0, 10, 1, "", 0x10, 4, DAT_011fa1f0, false);
    m_spConstantMap->SetConstant(_DAT_010AF60C, uiPoint4Flags, 0, 14, 1, "", 0x10, 4, _DAT_011FA280, false);
    m_spConstantMap->SetConstant(_DAT_010AF5E4, uiPoint4Flags, 0, 15, 1, "", 0x10, 4, _DAT_011FA290, false);
    if (_DAT_011F941E)
        m_spConstantMap->SetConstant(_DAT_010B92DC, uiPoint1Flags, 0, 16, 1, "", 4, 4, &_DAT_011F918C, false);
    SpeedTreeLeafShaderConstantMapSetup::ConfigureShaderConstantMap(m_spConstantMap, 0x11);
}

extern "C" void __cdecl ShadowLightShader_SetupPassConstants();
// @fnv 0x00bd3270
// src: COMMUNITY 0x00bd3270
void SpeedTreeBranchShader_SetupPassConstants()
{
    ShadowLightShader_SetupPassConstants();
}

struct ShaderProgram
{
    const char* file;
    const char* defines[18];
};
void __cdecl FUN_00be0c00(const char*, char*);
int __cdecl BSsprintf(char*, int, const char*, ...);
extern int DAT_011f91c0;
struct BranchShader
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c;
    unsigned int unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c;
    unsigned int unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88;
    NiPointer_s<NiRefObject_s> vertexShaders1[10];
    NiPointer_s<NiRefObject_s> vertexShaders2[20];
    NiRefObject_s* FUN_00be0fe0(const char*, const char* const*, const char*, const char*);
    void SpeedTreeBranchShader_LoadVertexShaders();
};
// @fnv 0x00bd3280
// src: COMMUNITY 0x00bd3280
void BranchShader::SpeedTreeBranchShader_LoadVertexShaders()
{
    ShaderProgram shaderPrograms1x[10] = {{"lighting\\1x\\v\\base.v.hlsl", {"TREE", "", 0}},
                                          {"lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl", {"TREE", "", "VC", "", 0}},
                                          {"lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl", {"TREE", "", "VC", "", 0}},
                                          {"lighting\\1x\\v\\ambDiffuseDirAndPt.v.hlsl", {"TREE", "", 0}},
                                          {"lighting\\1x\\v\\diffuseDir.v.hlsl", {"TREE", "", 0}},
                                          {"lighting\\1x\\v\\diffusePt.v.hlsl", {"TREE", "", 0}},
                                          {"lighting\\1x\\v\\base.v.hlsl", {"TREE", "", "VC", "", 0}},
                                          {"lighting\\1x\\v\\specularDir.v.hlsl", {"TREE", "", 0}},
                                          {"lighting\\1x\\v\\specularPt.v.hlsl", {"TREE", "", 0}},
                                          {"lighting\\1x\\v\\base.v.hlsl", {"TREE", "", "FOG", "", 0}}};
    ShaderProgram shaderPrograms2x[20] = {
        {"lighting\\2x\\v\\AD.v.hlsl", {"LIGHTS", "2", "TREE", "", 0}},
        {"lighting\\2x\\v\\AD.v.hlsl", {"LIGHTS", "2", "PROJ_SHADOW", "", "TREE", "", 0}},
        {"lighting\\2x\\v\\AD.v.hlsl", {"LIGHTS", "3", "TREE", "", 0}},
        {"lighting\\2x\\v\\AD.v.hlsl", {"LIGHTS", "3", "PROJ_SHADOW", "", "TREE", "", 0}},
        {"lighting\\2x\\v\\ADTS.v.hlsl", {"TREE", "", 0}},
        {"lighting\\2x\\v\\ADTS.v.hlsl", {"PROJ_SHADOW", "", "TREE", "", 0}},
        {"lighting\\2x\\v\\ADTS.v.hlsl", {"LIGHTS", "2", "TREE", "", 0}},
        {"lighting\\2x\\v\\ADTS.v.hlsl", {"LIGHTS", "2", "PROJ_SHADOW", "", "TREE", "", 0}},
        {"lighting\\2x\\v\\ADTS.v.hlsl", {"SPECULAR", "", "TREE", "", 0}},
        {"lighting\\2x\\v\\ADTS.v.hlsl", {"SPECULAR", "", "PROJ_SHADOW", "", "TREE", "", 0}},
        {"lighting\\2x\\v\\ADTS.v.hlsl", {"SPECULAR", "", "LIGHTS", "2", "TREE", "", 0}},
        {"lighting\\2x\\v\\ADTS.v.hlsl", {"SPECULAR", "", "LIGHTS", "2", "PROJ_SHADOW", "", "TREE", "", 0}},
        {"lighting\\2x\\v\\DiffusePt.v.hlsl", {"LIGHTS", "2", "TREE", "", 0}},
        {"lighting\\2x\\v\\DiffusePt.v.hlsl", {"LIGHTS", "3", "TREE", "", 0}},
        {"lighting\\2x\\v\\Specular.v.hlsl", {"TREE", "", 0}},
        {"lighting\\2x\\v\\Specular.v.hlsl", {"PROJ_SHADOW", "", "TREE", "", 0}},
        {"lighting\\2x\\v\\Specular.v.hlsl", {"POINT", "", "TREE", "", 0}},
        {"lighting\\2x\\v\\Specular.v.hlsl", {"NUM_PT_LIGHTS", "2", "POINT", "", "TREE", "", 0}},
        {"lighting\\2x\\v\\Specular.v.hlsl", {"NUM_PT_LIGHTS", "3", "POINT", "", "TREE", "", 0}},
        {"lighting\\2x\\v\\SimpleShadow.v.hlsl", {"SHADOWMAP", "", "TREE", "", 0}}};
    char name[260];
    char shaderPath[260];
    for (int i = 0; i < 10; ++i)
    {
        if (shaderPrograms1x[i].file)
        {
            FUN_00be0c00(shaderPrograms1x[i].file, shaderPath);
            BSsprintf(name, 260, "STB1%03i.vso", i);
            vertexShaders1[i] = FUN_00be0fe0(shaderPath, shaderPrograms1x[i].defines, "vs_1_1", name);
        }
        else
        {
            vertexShaders1[i] = 0;
        }
    }
    if (DAT_011f91c0 >= 2)
    {
        for (int i = 0; i < 20; ++i)
        {
            FUN_00be0c00(shaderPrograms2x[i].file, shaderPath);
            BSsprintf(name, 260, "STB2%03i.vso", i);
            vertexShaders2[i] = FUN_00be0fe0(shaderPath, shaderPrograms2x[i].defines, "vs_2_0", name);
        }
    }
}

extern "C" float DAT_01011584[];
char* __cdecl FUN_00ecdd16(double value, int digits, char* buffer);
extern float DAT_011adbcc;
void __cdecl FUN_00be0c00(const char* name, char* outBuf);
extern "C" void* __cdecl _fnv_zlib_memset(void* dst, int val, unsigned int size);
int _sprintf_s(char* buf, unsigned int size, const char* fmt, ...);
struct Entry
{
    const char* f00;
    const char* f04;
    const void* f08;
    int f0c;
    int t10;
    int t14;
    int t18;
    int t1c;
    int t20;
    int t24;
    int t28;
    int t2c;
    int t30;
    int t34;
    int t38;
    int t3c;
    int t40;
    int t44;
    int t48;
};
struct Frond
{
    char pad0[0x18];
    void* m_pOwnerShader;
    char pad1[0x34 - 0x1c];
    NiPointer_s<NiD3DShaderConstantMap> m_spConstantMap;
    char pad2[0x88 - 0x38];
    float m_kPointLightPos[4];
    float m_kDirectionalLightDir[4];
    char pad3[0x104 - 0xa8];
    NiPointer_s<NiD3DShaderConstantMap> m_slots[10];
    NiD3DShaderConstantMap* FUN_00be1750(char* buf, void* entryPart, const char* profile, char* psoName);
    void CreateShaderConstantMaps();
};
// Builds ten shader entry descriptors, then for each one formats its name and creates a shader constant map stored in m_slots.
// @fnv 0x00bd3c60
void Frond::CreateShaderConstantMaps()
{
    char specMultBuf[0x160];
    Entry shaderEntries[10];
    FUN_00ecdd16((double)DAT_011adbcc, 12, specMultBuf);
    shaderEntries[0].f00 = "lighting\\1x\\p\\base.p.hlsl";
    shaderEntries[0].f04 = 0;
    _fnv_zlib_memset(&shaderEntries[0].f08, 0, 0x44);
    shaderEntries[1].f00 = "lighting\\1x\\p\\ambDiffDirTexture.p.hlsl";
    shaderEntries[1].f04 = "VC";
    shaderEntries[1].f08 = DAT_01011584;
    shaderEntries[1].f0c = 0;
    _fnv_zlib_memset(&shaderEntries[1].t10, 0, 0x3c);
    shaderEntries[2].f00 = "lighting\\1x\\p\\ambDiffDirTexture.p.hlsl";
    shaderEntries[2].f04 = "VC";
    shaderEntries[2].f08 = DAT_01011584;
    shaderEntries[2].f0c = 0;
    _fnv_zlib_memset(&shaderEntries[2].t10, 0, 0x3c);
    shaderEntries[3].f00 = "lighting\\1x\\p\\ambDiffDirAndPt.p.hlsl";
    shaderEntries[3].f04 = 0;
    _fnv_zlib_memset(&shaderEntries[3].f08, 0, 0x44);
    shaderEntries[4].f00 = "lighting\\1x\\p\\diffuseDir.p.hlsl";
    shaderEntries[4].f04 = 0;
    _fnv_zlib_memset(&shaderEntries[4].f08, 0, 0x44);
    shaderEntries[5].f00 = "lighting\\1x\\p\\diffusePt.p.hlsl";
    shaderEntries[5].f04 = 0;
    _fnv_zlib_memset(&shaderEntries[5].f08, 0, 0x44);
    shaderEntries[6].f00 = "lighting\\1x\\p\\base.p.hlsl";
    shaderEntries[6].f04 = "TEX";
    shaderEntries[6].f08 = DAT_01011584;
    shaderEntries[6].f0c = (int)"VC";
    shaderEntries[6].t10 = (int)DAT_01011584;
    shaderEntries[6].t14 = 0;
    _fnv_zlib_memset(&shaderEntries[6].t18, 0, 0x34);
    shaderEntries[7].f00 = "lighting\\1x\\p\\specularDir.p.hlsl";
    shaderEntries[7].f04 = "SPECMULT";
    shaderEntries[7].f08 = specMultBuf;
    shaderEntries[7].f0c = 0;
    _fnv_zlib_memset(&shaderEntries[7].t10, 0, 0x3c);
    shaderEntries[8].f00 = "lighting\\1x\\p\\specularPt.p.hlsl";
    shaderEntries[8].f04 = "SPECMULT";
    shaderEntries[8].f08 = specMultBuf;
    shaderEntries[8].f0c = 0;
    _fnv_zlib_memset(&shaderEntries[8].t10, 0, 0x3c);
    shaderEntries[9].f00 = "lighting\\1x\\p\\base.p.hlsl";
    shaderEntries[9].f04 = "FOG";
    shaderEntries[9].f08 = DAT_01011584;
    shaderEntries[9].f0c = 0;
    _fnv_zlib_memset(&shaderEntries[9].t10, 0, 0x3c);
    const char* profile = NiD3DGPUProgramCache::GetPixelShaderProfile(true);
    char shaderPathBuf[0x104];
    char psoNameBuf[0x104];
    int i = 0;
    Entry* pEntry = shaderEntries;
    NiPointer_s<NiD3DShaderConstantMap>* slot = m_slots;
    for (;;)
    {
        if (pEntry->f00)
        {
            FUN_00be0c00(pEntry->f00, shaderPathBuf);
            _sprintf_s(psoNameBuf, 0x104, "STB1%03i.pso", i);
            NiD3DShaderConstantMap* pConstantMap = FUN_00be1750(shaderPathBuf, &pEntry->f04, profile, psoNameBuf);
            *slot = pConstantMap;
        }
        else
        {
            *slot = (NiD3DShaderConstantMap*)0;
        }
        i++;
        pEntry++;
        slot++;
        if (i >= 10)
            break;
    }
}
