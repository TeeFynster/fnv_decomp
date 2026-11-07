// bsshader/lighting30shader.cpp: SM3ShaderLoader, Shadow, Lighting, MapOwner and more (36 functions)

#include "../../include/BSFogProperty.h"
#include "../../include/BSShader.h"
#include "../../include/BSShaderManager.h"
#include "../../include/NiD3DDefaultShader.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiD3DShaderDeclaration.h"
#include "../../include/NiD3DShaderInterface.h"
#include "../../include/NiShader.h"
#include "../../include/NiShaderDeclaration.h"
#include "../../include/NiD3DGPUProgramCache.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiColorA.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint4.h"
#include "../../include/NiPoint3.h"

inline NiColorA::NiColorA(float fR, float fG, float fB, float fA) : r(fR), g(fG), b(fB), a(fA)
{}

inline NiColorA NiColorA::operator*(float fScalar) const
{
    NiColorA out = *this;
    out.r *= fScalar;
    out.g *= fScalar;
    out.b *= fScalar;
    out.a *= fScalar;
    return out;
}


inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& point) const
{
    return NiPoint3(x - point.x, y - point.y, z - point.z);
}

// Unit-private C++03 declaration closure. No authored helper bodies.
// PC layout and ordered virtual declarations: see NOTES and community_virtual_declarations.json.

#include <stddef.h>
#include <string.h>
class NiTexture;
typedef unsigned int UInt32;
typedef unsigned short UInt16;
#define LIGHTING30_JOIN2(a, b) a##b
#define LIGHTING30_JOIN(a, b) LIGHTING30_JOIN2(a, b)
#define LIGHTING30_ASSERT(x) typedef char LIGHTING30_JOIN(lighting30_assert_, __LINE__)[(x) ? 1 : -1]
LIGHTING30_ASSERT(sizeof(void*) == 4);
class NiRTTI;
class NiNode;
class BSFadeNode;
class BSMultiBoundNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class BSSegmentedTriShape;
class BSResizableTriShape;
class NiParticles;
class NiLines;
class bhkNiCollisionObject;
class bhkBlendCollisionObject;
class bhkRigidBody;
class bhkLimitedHingeConstraint;
class NiSkinInstance;
class NiGeometryBufferData;
class NiPropertyState;
class NiDynamicEffectState;
class NiTransform;
class NiBound;
class NiShaderConstantMap;
class NiGPUProgram;
class NiDX9ShaderDeclaration;

class D3DRenderStateGroup;
class NiD3DVertexShader;
class NiD3DPixelShader;
class NiShaderConstantMapEntry;
class Lighting30ShaderProperty;
class GraphicsRenderer;
class ShaderPassRenderer;
class NiDX9RenderState;
class NiDX9VertexBufferManager;
class NiVBChip;
class NiGeometryData;
class CloningProcess;
class NiStream;
class NiObjectGroup;
class NiControllerManager;
struct IDirect3DDevice9;
struct IDirect3DVertexDeclaration9;
typedef IDirect3DDevice9* LPDIRECT3DDEVICE9;
typedef IDirect3DVertexDeclaration9* LPDIRECT3DVERTEXDECLARATION9;
template <class T> class NiTPrimitiveArray;

class BSShaderProperty;
#include "../../include/NiMemObject.h"
LIGHTING30_ASSERT(sizeof(NiRefObject) == 8);
LIGHTING30_ASSERT(sizeof(NiObject) == 8);
LIGHTING30_ASSERT(sizeof(NiShader) == 0x14);
LIGHTING30_ASSERT(sizeof(NiD3DShaderInterface) == 0x24);
LIGHTING30_ASSERT(sizeof(NiD3DShader) == 0x3c);
LIGHTING30_ASSERT(sizeof(NiD3DDefaultShader) == 0x5c);
LIGHTING30_ASSERT(sizeof(BSShader) == 0x6c);
LIGHTING30_ASSERT(sizeof(NiD3DShaderDeclaration) == 0x2c);
struct _D3DVERTEXELEMENT9;
class NiD3DVertexDeclaration : public NiD3DShaderDeclaration
{
  public:
    _D3DVERTEXELEMENT9* m_pkVertexElements;
    LPDIRECT3DVERTEXDECLARATION9 m_pkD3DVertexDeclaration;
    static NiD3DVertexDeclaration* Create(GraphicsRenderer*, UInt32, UInt32);
};
LIGHTING30_ASSERT(sizeof(NiD3DVertexDeclaration) == 0x34);
class Lighting30Shader : public BSShader
{
  public:
    virtual void UpdateDiffuseNormalStages(UInt32, Lighting30ShaderProperty*);
    virtual void UpdatePassTextureStages(UInt32, Lighting30ShaderProperty*);
    virtual void SetRenderStatesForPass(UInt32, Lighting30ShaderProperty*);
    virtual void InitializeShaderData();
    virtual void InitializeVertexShader();
    virtual void InitializePixelShader();
    virtual bool ConfigureShaderPass();
    NiPointer<NiD3DShaderConstantMap> m_spFillColorConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spFogConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spFirstPassConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spSecondPassConstantMap;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration1;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration2;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration3;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration4;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration5;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration6;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration7;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration8;
    NiGeometryBufferData* m_pGeometryBufferData;
    UInt32 m_uiShaderOptions;
    Lighting30Shader(NiD3DVertexDeclaration*, NiD3DVertexDeclaration*, NiD3DVertexDeclaration*,
                     NiD3DVertexDeclaration*);
    static BSShader* CreateShader();
    static void InvalidateShaderConstants();
};
LIGHTING30_ASSERT(sizeof(Lighting30Shader) == 0xa4);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_spFillColorConstantMap) == 0x6c);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_spSecondPassConstantMap) == 0x78);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration1) == 0x7c);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration2) == 0x80);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration3) == 0x84);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration4) == 0x88);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration5) == 0x8c);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration6) == 0x90);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration7) == 0x94);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration8) == 0x98);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pGeometryBufferData) == 0x9c);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_uiShaderOptions) == 0xa0);
extern GraphicsRenderer* g_pkRenderer;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

// Natural new-expression exception cleanup; no fabricated lifetime helpers.
// PC virtual slots and cross-platform names are documented in NOTES.md.
// Builds eight shader declarations with vertex entries, creates a Lighting30Shader, assigns the non-color declarations to its slots, and initializes it.
// @fnv 0x00bbd0d0
BSShader* Lighting30Shader::CreateShader()
{
    NiD3DVertexDeclaration* declaration = NiD3DVertexDeclaration::Create(g_pkRenderer, 6, 1);
    NiD3DVertexDeclaration* declarationNC = NiD3DVertexDeclaration::Create(g_pkRenderer, 6, 1);
    NiD3DVertexDeclaration* skinnedDeclaration = NiD3DVertexDeclaration::Create(g_pkRenderer, 8, 1);
    NiD3DVertexDeclaration* skinnedDeclarationNC = NiD3DVertexDeclaration::Create(g_pkRenderer, 8, 1);
    NiD3DVertexDeclaration* vertexColorDeclaration = NiD3DVertexDeclaration::Create(g_pkRenderer, 6, 1);
    NiD3DVertexDeclaration* vertexColorDeclarationNC = NiD3DVertexDeclaration::Create(g_pkRenderer, 6, 1);
    NiD3DVertexDeclaration* skinnedVertexColorDeclaration = NiD3DVertexDeclaration::Create(g_pkRenderer, 8, 1);
    NiD3DVertexDeclaration* skinnedVertexColorDeclarationNC = NiD3DVertexDeclaration::Create(g_pkRenderer, 8, 1);
    declaration->SetEntry(0, 0, (NiShaderDeclaration::ShaderParameter)0, (NiShaderDeclaration::ShaderParameterType)2,
                          0);
    declaration->SetEntry(1, 3, (NiShaderDeclaration::ShaderParameter)3, (NiShaderDeclaration::ShaderParameterType)2,
                          0);
    declaration->SetEntry(2, 7, (NiShaderDeclaration::ShaderParameter)5, (NiShaderDeclaration::ShaderParameterType)1,
                          0);
    declaration->SetEntry(3, 14, (NiShaderDeclaration::ShaderParameter)13, (NiShaderDeclaration::ShaderParameterType)2,
                          0);
    declaration->SetEntry(4, 15, (NiShaderDeclaration::ShaderParameter)14, (NiShaderDeclaration::ShaderParameterType)2,
                          0);
    declarationNC->SetEntry(0, 0, (NiShaderDeclaration::ShaderParameter)0, (NiShaderDeclaration::ShaderParameterType)2,
                            0);
    declarationNC->SetEntry(1, 3, (NiShaderDeclaration::ShaderParameter)3, (NiShaderDeclaration::ShaderParameterType)2,
                            0);
    declarationNC->SetEntry(2, 7, (NiShaderDeclaration::ShaderParameter)5, (NiShaderDeclaration::ShaderParameterType)1,
                            0);
    declarationNC->SetEntry(3, 14, (NiShaderDeclaration::ShaderParameter)13,
                            (NiShaderDeclaration::ShaderParameterType)2, 0);
    declarationNC->SetEntry(4, 15, (NiShaderDeclaration::ShaderParameter)14,
                            (NiShaderDeclaration::ShaderParameterType)2, 0);
    declaration->GetD3DDeclaration();
    declarationNC->GetD3DDeclaration();
    vertexColorDeclaration->SetEntry(0, 0, (NiShaderDeclaration::ShaderParameter)0,
                                     (NiShaderDeclaration::ShaderParameterType)2, 0);
    vertexColorDeclaration->SetEntry(1, 3, (NiShaderDeclaration::ShaderParameter)3,
                                     (NiShaderDeclaration::ShaderParameterType)2, 0);
    vertexColorDeclaration->SetEntry(2, 5, (NiShaderDeclaration::ShaderParameter)4,
                                     (NiShaderDeclaration::ShaderParameterType)3, 0);
    vertexColorDeclaration->SetEntry(3, 7, (NiShaderDeclaration::ShaderParameter)5,
                                     (NiShaderDeclaration::ShaderParameterType)1, 0);
    vertexColorDeclaration->SetEntry(4, 14, (NiShaderDeclaration::ShaderParameter)13,
                                     (NiShaderDeclaration::ShaderParameterType)2, 0);
    vertexColorDeclaration->SetEntry(5, 15, (NiShaderDeclaration::ShaderParameter)14,
                                     (NiShaderDeclaration::ShaderParameterType)2, 0);
    vertexColorDeclarationNC->SetEntry(0, 0, (NiShaderDeclaration::ShaderParameter)0,
                                       (NiShaderDeclaration::ShaderParameterType)2, 0);
    vertexColorDeclarationNC->SetEntry(1, 3, (NiShaderDeclaration::ShaderParameter)3,
                                       (NiShaderDeclaration::ShaderParameterType)2, 0);
    vertexColorDeclarationNC->SetEntry(2, 5, (NiShaderDeclaration::ShaderParameter)4,
                                       (NiShaderDeclaration::ShaderParameterType)3, 0);
    vertexColorDeclarationNC->SetEntry(3, 7, (NiShaderDeclaration::ShaderParameter)5,
                                       (NiShaderDeclaration::ShaderParameterType)1, 0);
    vertexColorDeclarationNC->SetEntry(4, 14, (NiShaderDeclaration::ShaderParameter)13,
                                       (NiShaderDeclaration::ShaderParameterType)2, 0);
    vertexColorDeclarationNC->SetEntry(5, 15, (NiShaderDeclaration::ShaderParameter)14,
                                       (NiShaderDeclaration::ShaderParameterType)2, 0);
    vertexColorDeclaration->GetD3DDeclaration();
    vertexColorDeclarationNC->GetD3DDeclaration();
    skinnedDeclaration->SetEntry(0, 0, (NiShaderDeclaration::ShaderParameter)0,
                                 (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedDeclaration->SetEntry(1, 1, (NiShaderDeclaration::ShaderParameter)1,
                                 (NiShaderDeclaration::ShaderParameterType)3, 0);
    skinnedDeclaration->SetEntry(2, 2, (NiShaderDeclaration::ShaderParameter)2,
                                 (NiShaderDeclaration::ShaderParameterType)4, 0);
    skinnedDeclaration->SetEntry(3, 3, (NiShaderDeclaration::ShaderParameter)3,
                                 (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedDeclaration->SetEntry(4, 7, (NiShaderDeclaration::ShaderParameter)5,
                                 (NiShaderDeclaration::ShaderParameterType)1, 0);
    skinnedDeclaration->SetEntry(5, 14, (NiShaderDeclaration::ShaderParameter)13,
                                 (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedDeclaration->SetEntry(6, 15, (NiShaderDeclaration::ShaderParameter)14,
                                 (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedDeclarationNC->SetEntry(0, 0, (NiShaderDeclaration::ShaderParameter)0,
                                   (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedDeclarationNC->SetEntry(1, 1, (NiShaderDeclaration::ShaderParameter)1,
                                   (NiShaderDeclaration::ShaderParameterType)3, 0);
    skinnedDeclarationNC->SetEntry(2, 2, (NiShaderDeclaration::ShaderParameter)2,
                                   (NiShaderDeclaration::ShaderParameterType)4, 0);
    skinnedDeclarationNC->SetEntry(3, 3, (NiShaderDeclaration::ShaderParameter)3,
                                   (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedDeclarationNC->SetEntry(4, 7, (NiShaderDeclaration::ShaderParameter)5,
                                   (NiShaderDeclaration::ShaderParameterType)1, 0);
    skinnedDeclarationNC->SetEntry(5, 14, (NiShaderDeclaration::ShaderParameter)13,
                                   (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedDeclarationNC->SetEntry(6, 15, (NiShaderDeclaration::ShaderParameter)14,
                                   (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedDeclaration->GetD3DDeclaration();
    skinnedDeclarationNC->GetD3DDeclaration();
    skinnedVertexColorDeclaration->SetEntry(0, 0, (NiShaderDeclaration::ShaderParameter)0,
                                            (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedVertexColorDeclaration->SetEntry(1, 1, (NiShaderDeclaration::ShaderParameter)1,
                                            (NiShaderDeclaration::ShaderParameterType)3, 0);
    skinnedVertexColorDeclaration->SetEntry(2, 2, (NiShaderDeclaration::ShaderParameter)2,
                                            (NiShaderDeclaration::ShaderParameterType)4, 0);
    skinnedVertexColorDeclaration->SetEntry(3, 3, (NiShaderDeclaration::ShaderParameter)3,
                                            (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedVertexColorDeclaration->SetEntry(4, 5, (NiShaderDeclaration::ShaderParameter)4,
                                            (NiShaderDeclaration::ShaderParameterType)3, 0);
    skinnedVertexColorDeclaration->SetEntry(5, 7, (NiShaderDeclaration::ShaderParameter)5,
                                            (NiShaderDeclaration::ShaderParameterType)1, 0);
    skinnedVertexColorDeclaration->SetEntry(6, 14, (NiShaderDeclaration::ShaderParameter)13,
                                            (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedVertexColorDeclaration->SetEntry(7, 15, (NiShaderDeclaration::ShaderParameter)14,
                                            (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedVertexColorDeclarationNC->SetEntry(0, 0, (NiShaderDeclaration::ShaderParameter)0,
                                              (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedVertexColorDeclarationNC->SetEntry(1, 1, (NiShaderDeclaration::ShaderParameter)1,
                                              (NiShaderDeclaration::ShaderParameterType)3, 0);
    skinnedVertexColorDeclarationNC->SetEntry(2, 2, (NiShaderDeclaration::ShaderParameter)2,
                                              (NiShaderDeclaration::ShaderParameterType)4, 0);
    skinnedVertexColorDeclarationNC->SetEntry(3, 3, (NiShaderDeclaration::ShaderParameter)3,
                                              (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedVertexColorDeclarationNC->SetEntry(4, 5, (NiShaderDeclaration::ShaderParameter)4,
                                              (NiShaderDeclaration::ShaderParameterType)3, 0);
    skinnedVertexColorDeclarationNC->SetEntry(5, 7, (NiShaderDeclaration::ShaderParameter)5,
                                              (NiShaderDeclaration::ShaderParameterType)1, 0);
    skinnedVertexColorDeclarationNC->SetEntry(6, 14, (NiShaderDeclaration::ShaderParameter)13,
                                              (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedVertexColorDeclarationNC->SetEntry(7, 15, (NiShaderDeclaration::ShaderParameter)14,
                                              (NiShaderDeclaration::ShaderParameterType)2, 0);
    skinnedVertexColorDeclaration->GetD3DDeclaration();
    skinnedVertexColorDeclarationNC->GetD3DDeclaration();
    Lighting30Shader* shader =
        new Lighting30Shader(declaration, skinnedDeclaration, vertexColorDeclaration, skinnedVertexColorDeclaration);
    shader->Initialize();
    {
        NiD3DVertexDeclaration* previous = shader->m_pVertexDeclaration2.m_pObject;
        if (previous != declarationNC)
        {
            if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
                previous->DeleteThis();
            shader->m_pVertexDeclaration2.m_pObject = declarationNC;
            if (declarationNC)
                InterlockedIncrement(reinterpret_cast<volatile long*>(&declarationNC->m_uiRefCount));
        }
    }
    {
        NiD3DVertexDeclaration* previous = shader->m_pVertexDeclaration4.m_pObject;
        if (previous != vertexColorDeclarationNC)
        {
            if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
                previous->DeleteThis();
            shader->m_pVertexDeclaration4.m_pObject = vertexColorDeclarationNC;
            if (vertexColorDeclarationNC)
                InterlockedIncrement(reinterpret_cast<volatile long*>(&vertexColorDeclarationNC->m_uiRefCount));
        }
    }
    {
        NiD3DVertexDeclaration* previous = shader->m_pVertexDeclaration6.m_pObject;
        if (previous != skinnedDeclarationNC)
        {
            if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
                previous->DeleteThis();
            shader->m_pVertexDeclaration6.m_pObject = skinnedDeclarationNC;
            if (skinnedDeclarationNC)
                InterlockedIncrement(reinterpret_cast<volatile long*>(&skinnedDeclarationNC->m_uiRefCount));
        }
    }
    {
        NiD3DVertexDeclaration* previous = shader->m_pVertexDeclaration8.m_pObject;
        if (previous != skinnedVertexColorDeclarationNC)
        {
            if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
                previous->DeleteThis();
            shader->m_pVertexDeclaration8.m_pObject = skinnedVertexColorDeclarationNC;
            if (skinnedVertexColorDeclarationNC)
                InterlockedIncrement(reinterpret_cast<volatile long*>(&skinnedVertexColorDeclarationNC->m_uiRefCount));
        }
    }
    shader->InitializeShaderData();
    shader->InitShaderConstants();
    shader->ConfigureShaderPass();
    shader->UseShaderDeclaration(declaration);
    return shader;
}

#include "lighting30shader_packet.h"
// Copies DAT_011a9bd0 into DAT_01201b30, sets DAT_012010c4->dirty and the two flags DAT_01200bf4 and DAT_01200bf5 to true.
// @fnv 0x00bbb840
void Lighting30Shader::InvalidateShaderConstants()
{
    DAT_01201b30 = DAT_011a9bd0;
    DAT_012010c4->dirty = true;
    DAT_01200bf4 = true;
    DAT_01200bf5 = true;
}

// Copies the packet into DAT_01201b30 and sets the byte at offset 8 of DAT_012010c4 from param_2 or DAT_01200bf4, then stores param_2 in DAT_01200bf4.
// @fnv 0x00bbb790
void __cdecl ApplyLighting30Packet(const Lighting30Packet4* apPacket, bool param_2)
{
    DAT_01201b30 = *apPacket;
    *((bool*)DAT_012010c4 + 8) = (param_2 || DAT_01200bf4) ? true : false;
    DAT_01200bf4 = param_2;
}


extern char* DAT_012010b0;
extern char* DAT_011f91c8;
extern NiPoint3 DAT_011f474c;
extern float DAT_01201360;
extern float DAT_01201364;
extern float DAT_01201368;

// If DAT_012010b0[8] is set, computes pos minus DAT_011f474c minus the offset at DAT_011f91c8+0x1e4 and stores the result into DAT_01201360/64/68.
// @fnv 0x00bbbcf0
void __stdcall UpdatePositionOffset(const NiPoint3& pos)
{
    if (DAT_012010b0[8])
    {
        NiPoint3 offset = *(NiPoint3*)(DAT_011f91c8 + 0x1e4);
        NiPoint3 diff = pos - DAT_011f474c - offset;
        DAT_01201360 = diff.x;
        DAT_01201364 = diff.y;
        DAT_01201368 = diff.z;
    }
}

extern char* DAT_012010cc;
extern int DAT_01201b50;
extern int DAT_01201b54;
extern int DAT_01201b58;
extern int DAT_01201b5c;

// If DAT_012010cc[8] is nonzero, copies four ints at offsets 0x84..0x90 of param_1 into DAT_01201b50..DAT_01201b5c.
// @fnv 0x00bbbda0
// src: COMMUNITY 0x00bbbda0
void __stdcall Lighting30Shader_SetupGeometryConstants_HairTint(const char* param_1)
{
    if (DAT_012010cc[8] != 0)
    {
        DAT_01201b50 = *(const int*)(param_1 + 0x84);
        DAT_01201b54 = *(const int*)(param_1 + 0x88);
        DAT_01201b58 = *(const int*)(param_1 + 0x8c);
        DAT_01201b5c = *(const int*)(param_1 + 0x90);
    }
}

extern const float g_011c3bb8_arg1;
extern char* DAT_012010d8;
extern float DAT_01201b90;
extern float DAT_01201b94;

// @fnv 0x00bbbdf0
// src: COMMUNITY 0x00bbbdf0
void __fastcall Lighting30Shader_SetupGeometryConstants_RefractionPower(void* this_ptr, int, char* param_1)
{
    if (DAT_012010d8[8] != 0)
    {
        DAT_01201b90 = *(float*)(param_1 + 0xe0);
        if ((*(unsigned int*)(param_1 + 0x24) & 0x10) > 0)
        {
            DAT_01201b94 = g_011c3bb8_arg1;
        }
        else
        {
            DAT_01201b94 = 1.0f;
        }
    }
}

extern char* DAT_012010e0;
extern float DAT_01201be8;
extern float DAT_01201bec;

struct DummyVTable
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual int vf4(int, int);
};

// If DAT_012010e0[8] is set, queries param_1->vf4(5, 0) to set DAT_01201bec to 1.0 or 0.0 and copies the float at param_1+0x30 into DAT_01201be8.
// @fnv 0x00bbbe30
// src: COMMUNITY 0x00bbbe30
void __fastcall Lighting30Shader_SetupGeometryConstants_Envmap(void* this_ptr, int edx_unused, DummyVTable* param_1)
{
    if (DAT_012010e0[8] != 0)
    {
        if (param_1->vf4(5, 0) != 0)
            DAT_01201bec = 1.0f;
        else
            DAT_01201bec = 0.0f;
        DAT_01201be8 = *(float*)((char*)param_1 + 0x30);
    }
}

extern unsigned int DAT_011f91e4;
void __stdcall NiD3DShader_SetupGeometryAlphaBlending(int arg);

// Calls FUN_00be1ff0 with arg unless DAT_011f91e4 falls within any of four excluded ranges.
// @fnv 0x00bbc5c0
void __stdcall DispatchIfNotExcluded(int arg)
{
    if ((DAT_011f91e4 < 0x1cc || DAT_011f91e4 > 0x1dc) && (DAT_011f91e4 < 0x1bd || DAT_011f91e4 > 0x1c3) &&
        (DAT_011f91e4 < 0x1e0 || DAT_011f91e4 > 0x1e1) && (DAT_011f91e4 < 0x2d8 || DAT_011f91e4 > 0x2ef))
    {
        NiD3DShader_SetupGeometryAlphaBlending(arg);
    }
}

// @fnv 0x00bbd820
// src: XBOX_PDB 0x00bbd820
int __fastcall Lighting30Shader_GetShaderDecl(char* pThis, int, char* arg1, char* apFlags)
{
    bool bHasFlag = false;
    if (*reinterpret_cast<int*>(*reinterpret_cast<char**>(arg1 + 0xB8) + 0x28) != 0)
        bHasFlag = true;
    bHasFlag |= (*reinterpret_cast<unsigned int*>(apFlags + 0x24) & 0x20) > 0;
    if ((*reinterpret_cast<unsigned int*>(apFlags + 0x20) & 2) > 0)
    {
        if (bHasFlag)
            return *reinterpret_cast<int*>(pThis + 0x94);
        return *reinterpret_cast<int*>(pThis + 0x8C);
    }
    if (bHasFlag)
        return *reinterpret_cast<int*>(pThis + 0x84);
    return *reinterpret_cast<int*>(pThis + 0x7C);
}

void __cdecl BSRenderState_SetZWriteEnable(unsigned int, unsigned int);
void __cdecl BSRenderState_SetZFunc(unsigned int, unsigned int);
void __cdecl UpdateRendererStateCount(unsigned int, unsigned int);
extern unsigned int DAT_011f91e4;
extern int DAT_011ff9dc;

// Checks DAT_011f91e4 and state entries, calling FUN_00b97e80, UpdateRendererStateCount or decrementing DAT_011ff9dc and calling FUN_00b97e30 based on flags.
// @fnv 0x00bbeef0
// src: XBOX_PDB 0x00bbeef0
void __fastcall Lighting30Shader_PostGeometry(void* this_ptr, int, unsigned char** state)
{
    unsigned int val = DAT_011f91e4;
    if (val == 0x1e0 || val == 0x1e1)
        BSRenderState_SetZFunc(3, 0);

    unsigned char* rendererSpecific = state[4];
    if (rendererSpecific && (rendererSpecific[0x18] & 1))
        UpdateRendererStateCount(0, 0);

    if (val - 0x1d3 <= 3)
    {
        unsigned char* alpha = state[0];
        if (alpha[0x18] & 1)
        {
            --DAT_011ff9dc;
            BSRenderState_SetZWriteEnable(1, 0);
        }
    }
}

extern "C" void* g_01201f20;

// @fnv 0x00bbc9b0
// src: XBOX_PDB 0x00bbc9b0
void* __cdecl Lighting30Shader_GetRTTI()
{
    return &g_01201f20;
}

extern "C" void __cdecl _delete(void*, unsigned int);
void __cdecl FUN_00bbc9c0();

struct FUN_00bbef60_shell
{
    void* __thiscall DestroyIfFlagged(int flag);
};

// @fnv 0x00bbef60
void* __thiscall FUN_00bbef60_shell::DestroyIfFlagged(int aiFlags)
{
    FUN_00bbc9c0();
    if (aiFlags & 1)
    {
        _delete(this, 0xa4);
    }
    return this;
}

extern int DAT_01200ec0;
extern int DAT_01201080;
struct S
{
    void ApplyToGlobalRange();
};
// @fnv 0x00bbb7f0
void S::ApplyToGlobalRange()
{
    int* p = &DAT_01200ec0;
    do
    {
        int v = *p;
        (*(void(__thiscall**)(S*, int))(*(int*)this + 0x128))(this, v);
        ++p;
    } while ((int)p < (int)&DAT_01201080);
}

// Iterates entries from start to the count at p+0x18 and zeroes the int at offset 8 of each non-null entry from the array at p+0x24.
// @fnv 0x00bbc610
// src: COMMUNITY 0x00bbc610
void __stdcall Lighting30Shader_ClearUnusedStages(void* apContainer, unsigned int start)
{
    for (unsigned int i = start; i < *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(apContainer) + 0x18); ++i)
    {
        void* pEntry = (*reinterpret_cast<void***>(reinterpret_cast<char*>(apContainer) + 0x24))[i];
        if (pEntry)
            *reinterpret_cast<int*>(reinterpret_cast<char*>(pEntry) + 8) = 0;
    }
}

struct P4_bbb890
{
    float x, y, z, w;
    P4_bbb890()
    {}
    P4_bbb890(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};
struct M_bbb890
{
    float m[16];
};
struct Flag_bbb890
{
    char pad[8];
    bool bOn;
};
struct Obj_bbb890
{
    char pad[0x30];
    float f30;
};
extern Flag_bbb890* DAT_012010a4;
extern Flag_bbb890* DAT_012010c8;
extern char* DAT_011f91c8;
extern P4_bbb890 DAT_011fa2a0;
extern P4_bbb890 DAT_01201370;
extern P4_bbb890 DAT_01201b40;
NiPoint3* __stdcall D3DXVec3TransformCoord_00ee6df8(NiPoint3*, const NiPoint3*, const M_bbb890*);

// @fnv 0x00bbb890
void __stdcall UpdateTransformedPosition(M_bbb890 kMat, Obj_bbb890* pObject)
{
    if (DAT_012010a4->bOn || DAT_012010c8->bOn)
    {
        P4_bbb890 kWorldPosition = DAT_011fa2a0;
        NiPoint3 kPos;
        kPos = NiPoint3(kWorldPosition.x, kWorldPosition.y, kWorldPosition.z);
        NiPoint3 kCam = *(NiPoint3*)(DAT_011f91c8 + 0x1e4);
        kPos += kCam;
        NiPoint3 kIn(kPos.x, kPos.y, kPos.z);
        D3DXVec3TransformCoord_00ee6df8(&kPos, &kIn, &kMat);
        DAT_01201370 = P4_bbb890(kPos.x, kPos.y, kPos.z, 1.0f);
        DAT_01201b40 = P4_bbb890(kPos.x, kPos.y, kPos.z, pObject->f30);
    }
}

namespace fnv_00bbce70 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RefObj_bbce70
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
};
extern RefObj_bbce70* DAT_01200dd8[57];
extern RefObj_bbce70* DAT_01200c48[50];
extern RefObj_bbce70* DAT_01200d10[50];
extern NiD3DPass* DAT_01200ec0[112];
namespace L30_bbce70 {
extern RefObj_bbce70* DAT_012010c4[10];
}
extern RefObj_bbce70* DAT_01201080[17];
extern Lighting30Packet4 DAT_012010f0[164];

static inline void Release_bbce70(RefObj_bbce70*& p)
{
    RefObj_bbce70* pObj = p;
    if (pObj)
    {
        if (InterlockedDecrement(&pObj->m_uiRefCount) == 0)
            pObj->DeleteThis();
        p = 0;
    }
}

struct Lighting30Shader_s : BSShader
{
    bool Lighting30Shader_Initialize();
};

// Calls Initialize, releases all cached objects in the global arrays, clears the packet arrays, and returns true.
// @fnv 0x00bbce70
// src: XBOX_PDB 0x00bbce70
bool Lighting30Shader_s::Lighting30Shader_Initialize()
{
    BSShader::Initialize();
    int i;
    for (i = 0; i < 57; i++)
        Release_bbce70(DAT_01200dd8[i]);
    for (i = 0; i < 50; i++)
    {
        Release_bbce70(DAT_01200c48[i]);
        Release_bbce70(DAT_01200d10[i]);
    }
    for (i = 0; i < 112; i++)
    {
        NiD3DPass* pPass = DAT_01200ec0[i];
        if (pPass)
        {
            if (--pPass->m_uiRefCount == 0)
                pPass->DestroyPass();
            DAT_01200ec0[i] = 0;
        }
    }
    for (i = 0; i < 17; i++)
        Release_bbce70(DAT_01201080[i]);
    for (i = 0; i < 10; i++)
        Release_bbce70(L30_bbce70::DAT_012010c4[i]);
    for (i = 0; i < 164; i++)
        DAT_012010f0[i] = DAT_011a9bd0;
    for (i = 0; i < 63; i++)
        (&DAT_01201b30)[i] = DAT_011a9bd0;
    return true;
}
}  // namespace fnv_00bbce70



struct BeamStage
{
    unsigned char m_pad00[0x8];
    NiTexture* m_pBeamTexture;

    void ApplyPairToState(unsigned int);
};

extern NiTexture* DAT_011f9510;
extern NiTexture* DAT_011f9518;
extern int DAT_011f952c;

void __cdecl AddToTwoCounters(int, int, int);
int __cdecl GetTableValue(int);

struct FUN_00bbdcd0_Arg1
{
    unsigned char m_pad00[0x20];
    unsigned int m_uiObjectFlags;
    unsigned char m_pad24[0x8c];
    NiTexture** m_ppTexture;
    unsigned char m_padB4[0x28];
    struct FUN_00bbdcd0_TextureObject* m_pTextureObject;
};

struct FUN_00bbdcd0_TextureObject
{
    unsigned char m_pad00[0x8];
    NiTexture* m_pBeamTexture;
    unsigned char m_pad0c[0x50];
    int m_nValue5c;
    int m_nValue60;
};


struct FUN_00bbdcd0_shell
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

    void ApplyTextureStages(FUN_00bbdcd0_Arg1*, NiD3DPass*);
};

// Assigns textures to the first two render stages from arg1 and clears the rest, then calls AddToTwoCounters with values derived from textureObject.
// @fnv 0x00bbdcd0
void FUN_00bbdcd0_shell::ApplyTextureStages(FUN_00bbdcd0_Arg1* pTextureSource, NiD3DPass* pStageList)
{
    FUN_00bbdcd0_TextureObject* textureObject = pTextureSource->m_pTextureObject;
    if (!textureObject)
        return;

    BeamStage* stage0 = pStageList->m_kStages.m_pBase[0].m_pObject;
    NiTexture* texture = *pTextureSource->m_ppTexture;
    if (!texture)
        texture = ((pTextureSource->m_uiObjectFlags & 0x80) > 0) ? DAT_011f9518 : DAT_011f9510;

    stage0->m_pBeamTexture = texture;
    stage0->ApplyPairToState(3);

    BeamStage* stage1 = pStageList->m_kStages.m_pBase[1].m_pObject;
    if (textureObject->m_pBeamTexture)
        stage1->m_pBeamTexture = textureObject->m_pBeamTexture;
    else
        stage1->m_pBeamTexture = reinterpret_cast<NiTexture*>(DAT_011f952c);
    stage1->ApplyPairToState(3);

    for (unsigned int i = 2; i < pStageList->m_uiStageCount; ++i)
    {
        BeamStage* stage = pStageList->m_kStages.m_pBase[i].m_pObject;
        if (stage)
            stage->m_pBeamTexture = 0;
    }

    AddToTwoCounters(GetTableValue(textureObject->m_nValue5c), GetTableValue(textureObject->m_nValue60), 0);

    v66();
}

struct GroupStandIn
{
    void ApplyGroupEntries();
};


extern int DAT_0126f74c;

class FUN_00bbb820_cls
{
  public:
    NiD3DPass* SetupPass(int param_1, int param_2);
    void Lighting30Shader_SetRenderStatesForPass(int param_1, int param_2);
};

// @fnv 0x00bbb820
// src: COMMUNITY 0x00bbb820
void FUN_00bbb820_cls::Lighting30Shader_SetRenderStatesForPass(int param_1, int param_2)
{
    NiD3DPass* pResult = this->SetupPass(param_1, param_2);
    DAT_0126f74c = (int)pResult;
    reinterpret_cast<GroupStandIn*>(pResult->m_pkRenderStateGroup)->ApplyGroupEntries();
}

struct FogColorA
{
    float r, g, b, a;
    FogColorA()
    {}
    FogColorA(float fR, float fG, float fB, float fA) : r(fR), g(fG), b(fB), a(fA)
    {}
};

struct FogQuad
{
    float x, y, z, w;
};

struct FogFloatPair
{
    float x, y;
};

BSFogProperty* __cdecl BSShaderManager_GetFogProperty(int iIndex);

struct ShadowSceneData
{
    int unk00;
    int unk04;
    int unk08;
    FogQuad m_kQuad0;
    FogQuad m_kQuad1;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    float m_f4c;
    float m_f50;
    float m_f54;
};

struct ShadowSceneOwner
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
    ShadowSceneData* m_pData;
};

extern unsigned char DAT_011f91c4;
extern FogQuad DAT_01200bf8;
extern FogQuad DAT_01200c08;
extern float DAT_01200be8;
extern float DAT_01200bec;
extern FogFloatPair DAT_01200c18;
extern FogColorA DAT_01200c28;
extern FogColorA DAT_01200c38;

// @fnv 0x00bbde20
// src: COMMUNITY 0x00bbde20
void __stdcall Lighting30Shader_UpdateTexEffectConstants(int bFog, ShadowSceneOwner* pOwner, int iUnused)
{
    if (!pOwner)
        return;

    ShadowSceneData* pData = pOwner->m_pData;
    if (pData)
    {
        DAT_01200bf8 = pData->m_kQuad0;
        DAT_01200c08 = pData->m_kQuad1;
        DAT_01200be8 = pData->m_f4c;
        DAT_01200bec = pData->m_f50;
        DAT_01200c18.x = pData->m_f54;
        DAT_01200c18.y = 1.0f;
    }

    DAT_01200c28 = FogColorA(0.0f, 0.0f, 0.0f, 0.0f);
    DAT_01200c38 = FogColorA(0.0f, 0.0f, 0.0f, 0.0f);

    if (!bFog)
        return;

    BSFogProperty* pFog = BSShaderManager_GetFogProperty(DAT_011f91c4);
    if (!pFog)
        return;

    float fStart = pFog->nearDepth;
    float fFogEnd = pFog->farDepth;
    float m_fAlpha = pFog->density;
    if (fFogEnd != 0.0f || fStart != 0.0f)
    {
        NiColor kFogColor = pFog->color;
        DAT_01200c38 = FogColorA(fFogEnd, fFogEnd - fStart, m_fAlpha, 0.0f);
        DAT_01200c28 = FogColorA(kFogColor.r, kFogColor.g, kFogColor.b, 0.0f);
    }
}

#include <stdlib.h>

Lighting30Shader* __cdecl BSShaderManager_GetShader(int);
struct ConstantMapPointer
{
    NiD3DShaderConstantMap* value;
    void FUN_00c663d0(const NiPointer<NiD3DShaderConstantMap>*);
};
class D3DRenderStateGroup
{
  public:
    void SetNodeValue(unsigned int, unsigned int, bool);
};
D3DRenderStateGroup* __cdecl FUN_00e7f5d0();
extern unsigned int DAT_01200868[];
extern unsigned int DAT_01200a28[];
extern bool DAT_01200854[];
extern bool DAT_01200848, DAT_01200849, DAT_0120084a, DAT_0120084b;
extern bool DAT_0120084c, DAT_0120084d, DAT_0120084e, DAT_0120084f;
extern bool DAT_01200850, DAT_01200851;
extern Lighting30PacketState* DAT_012010d0;
extern Lighting30PacketState* DAT_012010d4;
extern Lighting30PacketState* DAT_012010dc;
extern Lighting30PacketState* DAT_012010e4;
extern Lighting30PacketState* DAT_012010e8;
extern unsigned short DAT_011f941c;
inline void AssignMap(NiPointer<NiD3DShaderConstantMap>& dst, const NiPointer<NiD3DShaderConstantMap>& src)
{
    NiRefObject* old = reinterpret_cast<NiRefObject*>(dst.m_pObject);
    if (dst.m_pObject != src.m_pObject)
    {
        if (old && !InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount)))
            old->DeleteThis();
        dst.m_pObject = src.m_pObject;
        if (dst.m_pObject)
            InterlockedIncrement(
                reinterpret_cast<volatile long*>(&reinterpret_cast<NiRefObject*>(dst.m_pObject)->m_uiRefCount));
    }
}
// @fnv 0x00bbd880
void __cdecl UpdateLightingPassState(unsigned int pass)
{
    Lighting30Shader* shader = BSShaderManager_GetShader(29);
    if (shader && (pass == 480 || pass == 481))
    {
        reinterpret_cast<ConstantMapPointer*>(&shader->m_spPixelConstantMap)
            ->FUN_00c663d0(&shader->m_spFillColorConstantMap);
        reinterpret_cast<ConstantMapPointer*>(&shader->m_spVertexConstantMap)
            ->FUN_00c663d0(&shader->m_spFogConstantMap);
        return;
    }
    AssignMap(shader->m_spPixelConstantMap, shader->m_spFirstPassConstantMap);
    AssignMap(shader->m_spVertexConstantMap, shader->m_spSecondPassConstantMap);
    unsigned int index;
    switch (pass)
    {
    case 10:
        index = 1;
        break;
    case 11:
        index = 2;
        break;
    case 12:
        index = 3;
        break;
    case 13:
        index = 4;
        break;
    case 14:
        index = 5;
        break;
    case 15:
        index = 6;
        break;
    case 730:
        index = 104;
        break;
    case 731:
        index = 105;
        break;
    case 736:
        index = 106;
        break;
    case 737:
        index = 107;
        break;
    case 742:
        index = 108;
        break;
    case 743:
        index = 109;
        break;
    case 748:
        index = 110;
        break;
    case 749:
        index = 111;
        break;
    default:
        index = pass - 376;
        break;
    }
    int i = 0;
    unsigned int mask = 1;
    for (; i < 17; ++i)
    {
        Lighting30PacketState* state = reinterpret_cast<Lighting30PacketState**>(&DAT_01201080)[i];
        if (state)
            state->dirty = (DAT_01200a28[index] & _rotl(mask, 1)) != 0;
        mask = _rotl(mask, 1);
        DAT_01200854[i] = (DAT_01200a28[index] & mask) != 0;
    }
    if (DAT_012010c4)
        DAT_012010c4->dirty = (DAT_01200868[index] >> 1) & 1;
    DAT_01200848 = (DAT_01200868[index] >> 1) & 1;
    if (DAT_012010c8)
        DAT_012010c8->bOn = (DAT_01200868[index] >> 2) & 1;
    DAT_01200849 = (DAT_01200868[index] >> 2) & 1;
    if (DAT_012010cc)
        reinterpret_cast<Lighting30PacketState*>(DAT_012010cc)->dirty = (DAT_01200868[index] >> 3) & 1;
    DAT_0120084a = (DAT_01200868[index] >> 3) & 1;
    if (DAT_012010d0)
        DAT_012010d0->dirty = (DAT_01200868[index] >> 4) & 1;
    DAT_0120084b = (DAT_01200868[index] >> 4) & 1;
    if (DAT_012010d4)
        DAT_012010d4->dirty = (DAT_01200868[index] >> 5) & 1;
    DAT_0120084c = (DAT_01200868[index] >> 5) & 1;
    if (DAT_012010d8)
        reinterpret_cast<Lighting30PacketState*>(DAT_012010d8)->dirty = (DAT_01200868[index] >> 6) & 1;
    DAT_0120084d = (DAT_01200868[index] >> 6) & 1;
    if (DAT_012010dc)
        DAT_012010dc->dirty = (DAT_01200868[index] >> 7) & 1;
    DAT_0120084e = (DAT_01200868[index] >> 7) & 1;
    if (DAT_012010e0)
        reinterpret_cast<Lighting30PacketState*>(DAT_012010e0)->dirty = (DAT_01200868[index] >> 8) & 1;
    DAT_0120084f = (DAT_01200868[index] >> 8) & 1;
    if (DAT_012010e4)
        DAT_012010e4->dirty = (DAT_01200868[index] >> 9) & 1;
    DAT_01200850 = (DAT_01200868[index] >> 9) & 1;
    if (DAT_012010e8)
        DAT_012010e8->dirty = (DAT_01200868[index] >> 10) & 1;
    DAT_01200851 = (DAT_01200868[index] >> 10) & 1;
    if ((pass >= 10 && pass <= 15) || ((DAT_011f941c & 1) > 0u))
    {
        NiD3DPass* p = reinterpret_cast<NiD3DPass**>(&DAT_01200ec0)[index];
        if (!p->m_pkRenderStateGroup)
            p->m_pkRenderStateGroup = FUN_00e7f5d0();
        p->m_pkRenderStateGroup->SetNodeValue(168, 0, true);
    }
    else if (pass >= 467 && pass <= 470)
    {
        NiD3DPass* p = reinterpret_cast<NiD3DPass**>(&DAT_01200ec0)[index];
        if (!p->m_pkRenderStateGroup)
            p->m_pkRenderStateGroup = FUN_00e7f5d0();
        p->m_pkRenderStateGroup->SetNodeValue(168, 3, true);
    }
    else if (pass >= 460 && pass <= 479)
    {
        NiD3DPass* p = reinterpret_cast<NiD3DPass**>(&DAT_01200ec0)[index];
        if (!p->m_pkRenderStateGroup)
            p->m_pkRenderStateGroup = FUN_00e7f5d0();
        p->m_pkRenderStateGroup->SetNodeValue(168, 15, true);
    }
    else if (pass >= 377 && pass <= 481)
    {
        NiD3DPass* p = reinterpret_cast<NiD3DPass**>(&DAT_01200ec0)[index];
        if (!p->m_pkRenderStateGroup)
            p->m_pkRenderStateGroup = FUN_00e7f5d0();
        p->m_pkRenderStateGroup->SetNodeValue(168, 7, true);
    }
    else
    {
        NiD3DPass* p = reinterpret_cast<NiD3DPass**>(&DAT_01200ec0)[index];
        if (!p->m_pkRenderStateGroup)
            p->m_pkRenderStateGroup = FUN_00e7f5d0();
        p->m_pkRenderStateGroup->SetNodeValue(168, 0, true);
    }
}

void __cdecl BSRenderState_SetAlphaTestFuncRef(unsigned int, unsigned int, unsigned int);

struct FUN_00bbdda0_cls : public FUN_00bbdcd0_shell
{
    void SetupTextureStages(FUN_00bbdcd0_Arg1* a1, NiD3DPass* a2);
};

// @fnv 0x00bbdda0
void FUN_00bbdda0_cls::SetupTextureStages(FUN_00bbdcd0_Arg1* apTextureSource, NiD3DPass* apStageList)
{
    unsigned char* pTextureObject = (unsigned char*)apTextureSource->m_pTextureObject;
    if (pTextureObject == 0)
    {
        return;
    }

    unsigned int uiFirstTexture = *(unsigned int*)(pTextureObject + 0x6c);
    BeamStage* stage0 = apStageList->m_kStages.m_pBase[0].m_pObject;
    if (uiFirstTexture != 0)
    {
        stage0->m_pBeamTexture = (NiTexture*)uiFirstTexture;
    }
    else
    {
        stage0->m_pBeamTexture = (NiTexture*)DAT_011f952c;
    }
    stage0->ApplyPairToState(3);

    for (unsigned int i = 1; i < apStageList->m_uiStageCount; ++i)
    {
        BeamStage* stage = apStageList->m_kStages.m_pBase[i].m_pObject;
        if (stage != 0)
        {
            stage->m_pBeamTexture = 0;
        }
    }

    this->v66();
    BSRenderState_SetAlphaTestFuncRef(4, *(unsigned int*)(pTextureObject + 0x70), 0);
}

struct Color3
{
    float r, g, b;
    Color3()
    {}
    Color3(float x, float y, float z) : r(x), g(y), b(z)
    {}
    Color3& operator*=(float s)
    {
        r *= s;
        g *= s;
        b *= s;
        return *this;
    }
};

struct LightSource
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    Color3 color;
    Color3* overrideColor;
    int unk38, unk3c;
    float intensity;
};
struct LightState
{
    int value;
};
struct RenderContext
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c,
        unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0;
    LightState* state;
};
struct Exposure
{
    int unk00, unk04, unk08;
    float scale;
};
struct ExposureOwner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    Exposure* data;
};
struct SceneLink
{
    int unk00;
    ExposureOwner* owner;
};
struct SceneRoot
{
    int unk00, unk04;
    SceneLink* link;
};
extern SceneRoot* DAT_011f91ac;
extern bool DAT_011f941e;
extern Color3 DAT_011f4998;
extern NiColorA DAT_01201b70;
// Computes a light's color (override or base), scales it by exposure and intensity, then clamps and accumulates it into the global color or stores it separately.
// @fnv 0x00bbecd0
void __stdcall ApplyLightSource(LightSource* light, RenderContext* context)
{
    Color3 color = light->overrideColor ? *light->overrideColor : light->color;
    bool separate = context->state->value != 0;
    if (color.r != DAT_011f4998.r || color.g != DAT_011f4998.g || color.b != DAT_011f4998.b || separate)
    {
        if (DAT_011f941e)
        {
            float scale = DAT_011f91ac->link->owner->data->scale * light->intensity;
            color *= scale;
        }
        if (!separate)
        {
            NiColorA result = *reinterpret_cast<NiColorA*>(&DAT_01201b30);
            result.r += color.r;
            result.g += color.g;
            result.b += color.b;
            if (!DAT_011f941e)
            {
                if (!(result.r < 1.0f))
                    result.r = 1.0f;
                if (!(result.g < 1.0f))
                    result.g = 1.0f;
                if (!(result.b < 1.0f))
                    result.b = 1.0f;
            }
            *reinterpret_cast<NiColorA*>(&DAT_01201b30) = result;
            DAT_012010c4->dirty = true;
            DAT_01200bf4 = true;
        }
        else
        {
            if (!DAT_011f941e)
            {
                if (!(color.r < 1.0f))
                    color.r = 1.0f;
                if (!(color.g < 1.0f))
                    color.g = 1.0f;
                if (!(color.b < 1.0f))
                    color.b = 1.0f;
            }
            DAT_01201b70 = NiColorA(color.r, color.g, color.b, 0.0f);
        }
    }
}

namespace ConstantMaps {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
void* __cdecl Object_DispatchCommandFour(unsigned int);
__forceinline void ReleaseConstantMapObject(NiRefObject* object)
{
    if (InterlockedDecrement((volatile long*)&object->m_uiRefCount) == 0)
        object->DeleteThis();
}
__forceinline void AddRefConstantMapObject(NiRefObject* object)
{
    InterlockedIncrement((volatile long*)&object->m_uiRefCount);
}
struct Pointer
{
    NiRefObject* object;
    void FUN_00a5f860(NiRefObject*);
    __forceinline void operator=(NiRefObject* value)
    {
        if (object != value)
        {
            if (object)
                ReleaseConstantMapObject(object);
            object = value;
            if (object)
                AddRefConstantMapObject(object);
        }
    }
    __forceinline void operator=(const Pointer& value)
    {
        if (object != value.object)
        {
            if (object)
                ReleaseConstantMapObject(object);
            object = value.object;
            if (object)
                AddRefConstantMapObject(object);
        }
    }
};
extern bool DAT_01201f28;
extern char DAT_01011584[];
extern char DAT_01013cf4[];
extern char DAT_01031334[];
extern char DAT_010a16ec[];
extern char DAT_010a18a4[];
extern char DAT_010a1cac[];
extern char DAT_010a1d20[];
extern char DAT_010a1db8[];
extern char DAT_010a1e50[];
extern char DAT_010a1ee0[];
extern char DAT_010af45c[];
extern char DAT_010af468[];
extern char DAT_010af474[];
extern char DAT_010af48c[];
extern char DAT_010af498[];
extern char DAT_010af580[];
extern char DAT_010af590[];
extern char DAT_010af5a0[];
extern char DAT_010af5b0[];
extern char DAT_010af5d8[];
extern char DAT_010aff58[];
extern char DAT_010ba250[];
extern char DAT_010ba258[];
extern char DAT_010ba26c[];
extern char DAT_010ba278[];
extern char DAT_010ba288[];
extern char DAT_010ba294[];
extern char DAT_010ba2a4[];
extern char DAT_010ba2b4[];
extern char DAT_010ba2bc[];
extern char DAT_010ba2c8[];
extern char DAT_010ba2d4[];
extern char DAT_010ba2e4[];
extern char DAT_010ba2f4[];
extern char DAT_010ba30c[];
extern char DAT_010ba320[];
extern char DAT_010ba32c[];
extern char DAT_011fa580[];
extern char DAT_011fed08[];
extern char DAT_011fed48[];
extern char DAT_01200be8[];
extern char DAT_01200bec[];
extern char DAT_01200bf0[];
extern char DAT_01200bf8[];
extern char DAT_01200c08[];
extern char DAT_01200c18[];
extern char DAT_01200c28[];
extern char DAT_01200c38[];
extern char DAT_01201170[];
extern char DAT_012012b0[];
extern char DAT_012012f0[];
extern char DAT_01201350[];
extern char DAT_01201360[];
extern char DAT_01201370[];
extern char DAT_01201380[];
extern char DAT_012013b0[];
extern char DAT_012013d0[];
extern char DAT_01201b30[];
extern char DAT_01201b40[];
extern char DAT_01201b50[];
extern char DAT_01201b60[];
extern char DAT_01201b70[];
extern char DAT_01201b90[];
extern char DAT_01201ba0[];
extern char DAT_01201bc0[];
extern char DAT_01201be0[];
extern char DAT_01201c70[];
extern Pointer DAT_01201080;
extern Pointer DAT_01201084;
extern Pointer DAT_01201088;
extern Pointer DAT_0120108c;
extern Pointer DAT_01201090;
extern Pointer DAT_01201094;
extern Pointer DAT_01201098;
extern Pointer DAT_0120109c;
extern Pointer DAT_012010a0;
extern Pointer DAT_012010a4;
extern Pointer DAT_012010a8;
extern Pointer DAT_012010ac;
extern Pointer DAT_012010b0;
extern Pointer DAT_012010b4;
extern Pointer DAT_012010b8;
extern Pointer DAT_012010bc;
extern Pointer DAT_012010c0;
extern Pointer DAT_012010c4;
extern Pointer DAT_012010c8;
extern Pointer DAT_012010cc;
extern Pointer DAT_012010d0;
extern Pointer DAT_012010d4;
extern Pointer DAT_012010d8;
extern Pointer DAT_012010dc;
extern Pointer DAT_012010e0;
extern Pointer DAT_012010e4;
extern Pointer DAT_012010e8;
struct Lighting
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    void* device;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    Pointer constants30;
    Pointer constants34;
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
    Pointer constants6c;
    Pointer constants70;
    Pointer constants74;
    Pointer constants78;
    void Lighting30Shader_CreateConstantMaps();
};
// @fnv 0x00bbf5a0
// src: XBOX_PDB 0x00bbf5a0
void Lighting::Lighting30Shader_CreateConstantMaps()
{
    if (!constants34.object && !DAT_01201f28)
    {
        DAT_01201f28 = true;
        constants34.FUN_00a5f860(new NiD3DShaderConstantMap((GraphicsRenderer*)device, 0u));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->AddConstant8((const char*)((unsigned int)DAT_010a1e50), 0x20000009, 0x0,(const char*)((unsigned int)DAT_01011584), 0x0, 0x0,(const void*)(0x0),(bool)(0x0));
        DAT_01201080.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010a1e50));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->AddConstant8((const char*)((unsigned int)DAT_010a1d20), 0x20000009, 0x14,(const char*)((unsigned int)DAT_01011584), 0x0, 0x0,(const void*)(0x0),(bool)(0x0));
        DAT_01201084.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010a1d20));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->AddConstant8((const char*)((unsigned int)DAT_010a1ee0), 0x20000009, 0x4,(const char*)((unsigned int)DAT_01011584), 0x0, 0x0,(const void*)(0x0),(bool)(0x0));
        DAT_01201088.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010a1ee0));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->AddConstant8((const char*)((unsigned int)DAT_010a1db8), 0x20000009, 0x18,(const char*)((unsigned int)DAT_01011584), 0x0, 0x0,(const void*)(0x0),(bool)(0x0));
        DAT_0120108c.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010a1db8));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->SetConstant((const char*)((unsigned int)DAT_010a1cac), 0x20000009, 0x120000, 0x34, 0x36,(const char*)(0x0), 0x0, 0x0,(const void*)(0x0),(bool)(0x0));
        DAT_01201090.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010a1cac));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->SetConstant((const char*)((unsigned int)DAT_010af580), 0x10000009, 0x0, 0x6c, 0x36,(const char*)((unsigned int)DAT_01011584), 0x360, 0x4,(const void*)((unsigned int)DAT_011fa580),(bool)(0x0));
        DAT_01201094.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010af580));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba32c), 0x10000009, 0x0, 0x8, 0x4,(const char*)((unsigned int)DAT_01011584), 0x40, 0x4,(const void*)((unsigned int)DAT_01201170),(bool)(0x0));
        DAT_01201098.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010ba32c));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->SetConstant((const char*)((unsigned int)DAT_010a18a4), 0x10000007, 0x0, 0x28, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01201370),(bool)(0x0));
        DAT_012010a4.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010a18a4));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba320), 0x10000007, 0x0, 0x2e, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_012013d0),(bool)(0x0));
        DAT_012010c0.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010ba320));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->SetConstant((const char*)((unsigned int)DAT_01013cf4), 0x1000000c, 0x0, 0x2c, 0x2,(const char*)((unsigned int)DAT_01011584), 0x20, 0x4,(const void*)((unsigned int)DAT_012013b0),(bool)(0x0));
        DAT_012010bc.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_01013cf4));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->SetConstant((const char*)((unsigned int)DAT_010af5b0), 0x10000007, 0x0, 0x29, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01201380),(bool)(0x0));
        DAT_012010a8.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010af5b0));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->SetConstant((const char*)((unsigned int)DAT_01031334), 0x10000007, 0x0, 0x26, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01201350),(bool)(0x0));
        DAT_012010ac.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_01031334));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba30c), 0x10000007, 0x0, 0x27, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01201360),(bool)(0x0));
        DAT_012010b0.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010ba30c));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba2f4), 0x10000009, 0x0, 0x20, 0x6,(const char*)((unsigned int)DAT_01011584), 0x60, 0x4,(const void*)((unsigned int)DAT_012012f0),(bool)(0x0));
        DAT_012010b4.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010ba2f4));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->SetConstant((const char*)((unsigned int)DAT_010af5a0), 0x10000009, 0x0, 0xc, 0x4,(const char*)((unsigned int)DAT_01011584), 0x40, 0x4,(const void*)((unsigned int)DAT_011fed08),(bool)(0x0));
        DAT_0120109c.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010af5a0));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->SetConstant((const char*)((unsigned int)DAT_010af590), 0x10000009, 0x0, 0x10, 0x4,(const char*)((unsigned int)DAT_01011584), 0x40, 0x4,(const void*)((unsigned int)DAT_011fed48),(bool)(0x0));
        DAT_012010a0.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010af590));
        ((NiD3DShaderConstantMap*)constants34.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba2e4), 0x10000009, 0x0, 0x1c, 0x4,(const char*)((unsigned int)DAT_01011584), 0x40, 0x4,(const void*)((unsigned int)DAT_012012b0),(bool)(0x0));
        DAT_012010b8.FUN_00a5f860((NiRefObject*)((NiD3DShaderConstantMap*)constants34.object)->GetEntry((unsigned int)DAT_010ba2e4));
        constants34.FUN_00a5f860(new NiD3DShaderConstantMap((GraphicsRenderer*)device, 0u));
    }
    if (!constants30.object)
    {
        constants30 = new NiD3DShaderConstantMap((GraphicsRenderer*)device, 2u);
        ((NiD3DShaderConstantMap*)constants30.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba2d4), 0x10000007, 0x0, 0x0, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01201b30),(bool)(0x0));
        DAT_012010c4 = (NiRefObject*)((NiD3DShaderConstantMap*)constants30.object)->GetEntry((unsigned int)DAT_010ba2d4);
        ((NiD3DShaderConstantMap*)constants30.object)
            ->SetConstant((const char*)((unsigned int)DAT_010aff58), 0x10000007, 0x0, 0x1, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01201b40),(bool)(0x0));
        DAT_012010c8 = (NiRefObject*)((NiD3DShaderConstantMap*)constants30.object)->GetEntry((unsigned int)DAT_010aff58);
        ((NiD3DShaderConstantMap*)constants30.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba2c8), 0x10000007, 0x0, 0x2, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01201b50),(bool)(0x0));
        DAT_012010cc = (NiRefObject*)((NiD3DShaderConstantMap*)constants30.object)->GetEntry((unsigned int)DAT_010ba2c8);
        ((NiD3DShaderConstantMap*)constants30.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba2bc), 0x10000007, 0x0, 0x3, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01201b60),(bool)(0x0));
        DAT_012010d0 = (NiRefObject*)((NiD3DShaderConstantMap*)constants30.object)->GetEntry((unsigned int)DAT_010ba2bc);
        ((NiD3DShaderConstantMap*)constants30.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba2b4), 0x10000007, 0x0, 0x4, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01201b70),(bool)(0x0));
        DAT_012010d4 = (NiRefObject*)((NiD3DShaderConstantMap*)constants30.object)->GetEntry((unsigned int)DAT_010ba2b4);
        ((NiD3DShaderConstantMap*)constants30.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba2a4), 0x10000007, 0x0, 0x6, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01201b90),(bool)(0x0));
        DAT_012010d8 = (NiRefObject*)((NiD3DShaderConstantMap*)constants30.object)->GetEntry((unsigned int)DAT_010ba2a4);
        ((NiD3DShaderConstantMap*)constants30.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba294), 0x10000007, 0x0, 0x7, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01201ba0),(bool)(0x0));
        DAT_012010dc = (NiRefObject*)((NiD3DShaderConstantMap*)constants30.object)->GetEntry((unsigned int)DAT_010ba294);
        ((NiD3DShaderConstantMap*)constants30.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba288), 0x1000000c, 0x0, 0x9, 0x2,(const char*)((unsigned int)DAT_01011584), 0x20, 0x4,(const void*)((unsigned int)DAT_01201bc0),(bool)(0x0));
        DAT_012010e4 = (NiRefObject*)((NiD3DShaderConstantMap*)constants30.object)->GetEntry((unsigned int)DAT_010ba288);
        ((NiD3DShaderConstantMap*)constants30.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba278), 0x10000007, 0x0, 0xb, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01201be0),(bool)(0x0));
        DAT_012010e0 = (NiRefObject*)((NiD3DShaderConstantMap*)constants30.object)->GetEntry((unsigned int)DAT_010ba278);
        ((NiD3DShaderConstantMap*)constants30.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba26c), 0x10000009, 0x0, 0x14, 0x29,(const char*)((unsigned int)DAT_01011584), 0x290, 0x4,(const void*)((unsigned int)DAT_01201c70),(bool)(0x0));
        DAT_012010e8 = (NiRefObject*)((NiD3DShaderConstantMap*)constants30.object)->GetEntry((unsigned int)DAT_010ba26c);
        constants30 = new NiD3DShaderConstantMap((GraphicsRenderer*)device, 2u);
    }
    constants78 = constants34;
    constants74 = constants30;
    if (!constants70.object)
    {
        constants70 = new NiD3DShaderConstantMap((GraphicsRenderer*)device, 0u);
        ((NiD3DShaderConstantMap*)constants70.object)
            ->AddConstant8((const char*)((unsigned int)DAT_010a1e50), 0x20000009, 0x0,(const char*)((unsigned int)DAT_01011584), 0x0, 0x0,(const void*)(0x0),(bool)(0x0));
        ((NiD3DShaderConstantMap*)constants70.object)
            ->AddConstant8((const char*)((unsigned int)DAT_010a1d20), 0x20000009, 0x4,(const char*)((unsigned int)DAT_01011584), 0x0, 0x0,(const void*)(0x0),(bool)(0x0));
        ((NiD3DShaderConstantMap*)constants70.object)
            ->SetConstant((const char*)((unsigned int)DAT_010a1cac), 0x20000009, 0x120000, 0xe, 0x36,(const char*)(0x0), 0x0, 0x0,(const void*)(0x0),(bool)(0x0));
        ((NiD3DShaderConstantMap*)constants70.object)
            ->SetConstant((const char*)((unsigned int)DAT_010af5d8), 0x10000007, 0x0, 0x8, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01201370),(bool)(0x0));
        ((NiD3DShaderConstantMap*)constants70.object)
            ->SetConstant((const char*)((unsigned int)DAT_010af498), 0x10000004, 0x0, 0x9, 0x1,(const char*)((unsigned int)DAT_01011584), 0x4, 0x4,(const void*)((unsigned int)DAT_01200be8),(bool)(0x0));
        ((NiD3DShaderConstantMap*)constants70.object)
            ->SetConstant((const char*)((unsigned int)DAT_010af48c), 0x10000004, 0x0, 0xa, 0x1,(const char*)((unsigned int)DAT_01011584), 0x4, 0x4,(const void*)((unsigned int)DAT_01200bec),(bool)(0x0));
        ((NiD3DShaderConstantMap*)constants70.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba258), 0x10000004, 0x0, 0xb, 0x1,(const char*)((unsigned int)DAT_01011584), 0x4, 0x4,(const void*)((unsigned int)DAT_01200bf0),(bool)(0x0));
        ((NiD3DShaderConstantMap*)constants70.object)
            ->SetConstant((const char*)((unsigned int)DAT_010af474), 0x10000007, 0x0, 0xc, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01200c38),(bool)(0x0));
        ((NiD3DShaderConstantMap*)constants70.object)
            ->SetConstant((const char*)((unsigned int)DAT_010a16ec), 0x10000007, 0x0, 0xd, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01200c28),(bool)(0x0));
    }
    if (!constants6c.object)
    {
        constants6c = new NiD3DShaderConstantMap((GraphicsRenderer*)device, 2u);
        ((NiD3DShaderConstantMap*)constants6c.object)
            ->SetConstant((const char*)((unsigned int)DAT_010af468), 0x10000007, 0x0, 0x0, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01200bf8),(bool)(0x0));
        ((NiD3DShaderConstantMap*)constants6c.object)
            ->SetConstant((const char*)((unsigned int)DAT_010af45c), 0x10000007, 0x0, 0x1, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01200c08),(bool)(0x0));
        ((NiD3DShaderConstantMap*)constants6c.object)
            ->SetConstant((const char*)((unsigned int)DAT_010ba250), 0x10000007, 0x0, 0x2, 0x1,(const char*)((unsigned int)DAT_01011584), 0x10, 0x4,(const void*)((unsigned int)DAT_01200c18),(bool)(0x0));
    }
}
}

namespace fnv_00bbba00 {

struct FogColorA
{
    float r, g, b, a;
    __forceinline FogColorA()
    {}
    __forceinline FogColorA(float r, float g, float b, float a) : r(r), g(g), b(b), a(a)
    {}
};

extern NiPoint3 DAT_011f474c;

struct ShaderTransform
{
    float r00, r01, r02, r10, r11, r12, r20, r21, r22;
    NiPoint3 translation;
    float scale;
};
struct ShaderMatrix
{
    __forceinline ShaderMatrix()
    {}
    __forceinline ShaderMatrix(const ShaderTransform& transform, const NiPoint3& camera)
    {
        m00 = transform.r00;
        m01 = transform.r01;
        m02 = transform.r02;
        m03 = transform.translation.x + camera.x;
        m10 = transform.r10;
        m11 = transform.r11;
        m12 = transform.r12;
        m13 = transform.translation.y + camera.y;
        m20 = transform.r20;
        m21 = transform.r21;
        m22 = transform.r22;
        m23 = transform.translation.z + camera.z;
        m30 = 0.0f;
        m31 = 0.0f;
        m32 = 0.0f;
        m33 = transform.scale;
    }
    __forceinline ShaderMatrix(const NiPoint3& translation, const NiPoint3& camera)
    {
        m00 = 1.0f;
        m01 = 0.0f;
        m02 = 0.0f;
        m03 = translation.x + camera.x;
        m10 = 0.0f;
        m11 = 1.0f;
        m12 = 0.0f;
        m13 = translation.y + camera.y;
        m20 = 0.0f;
        m21 = 0.0f;
        m22 = 1.0f;
        m23 = translation.z + camera.z;
        m30 = 0.0f;
        m31 = 0.0f;
        m32 = 0.0f;
        m33 = 1.0f;
    }
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
};
struct ShaderScene
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
    NiPoint3 cameraTranslation;
};
extern Lighting30PacketState* DAT_012010b4;
extern FogColorA DAT_012012f0, DAT_01201300, DAT_01201310, DAT_01201320;
extern FogColorA DAT_01201330, DAT_01201340;
extern FogColorA DAT_011fd874, DAT_011fd884;
extern NiPoint3 DAT_011f474c;
extern void* DAT_011f91c8;

// @fnv 0x00bbba00
void __stdcall UpdateShaderMatrices(int identity, const ShaderTransform* transform)
{
    if (!DAT_012010b4->dirty)
        return;
    NiPoint3 camera = reinterpret_cast<ShaderScene*>(DAT_011f91c8)->cameraTranslation;
    ShaderMatrix shaderMatrix;
    if (!identity)
    {
        shaderMatrix = ShaderMatrix(*transform, camera);
    }
    else
    {
        NiPoint3 translation = DAT_011f474c;
        shaderMatrix = ShaderMatrix(translation, camera);
    }
    DAT_012012f0 = FogColorA(shaderMatrix.m00, shaderMatrix.m01, shaderMatrix.m02, shaderMatrix.m03);
    DAT_01201300 = FogColorA(shaderMatrix.m10, shaderMatrix.m11, shaderMatrix.m12, shaderMatrix.m13);
    DAT_01201310 = FogColorA(shaderMatrix.m20, shaderMatrix.m21, shaderMatrix.m22, shaderMatrix.m23);
    DAT_01201320 = FogColorA(shaderMatrix.m30, shaderMatrix.m31, shaderMatrix.m32, shaderMatrix.m33);
    DAT_01201330 = DAT_011fd874;
    DAT_01201340 = DAT_011fd884;
}
}  // namespace fnv_00bbba00

namespace fnv_00bbd000 {
struct Stage
{
    int unk00;
    int unk04;
    unsigned char active;
};
extern Stage* DAT_01201090;
extern char DAT_010a1cac;
struct Frame
{
    int m00;
    void* m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    unsigned short m20;
};
struct Parameters
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
};
struct Pipeline
{
    void NiDX9Renderer_CalculateBoneMatrices(Parameters* params, int extra, int a, int b, int c);
};
extern Pipeline* DAT_011f9508;
// Exe 0x00bbd000: unit-local Map view; declarations and layout are preserved.
struct Lighting30shaderMapView
{
    virtual void skipped0();
    virtual void skipped1();
    virtual void skipped2();
    virtual void skipped3();
    virtual void skipped4();
    virtual void skipped5();
    virtual void skipped6();
    virtual void skipped7();
    virtual void skipped8();
    virtual void skipped9();
    virtual void skipped10();
    virtual void skipped11();
    virtual void skipped12();
    virtual void skipped13();
    virtual void skipped14();
    virtual void skipped15();
    virtual void skipped16();
    virtual void skipped17();
    virtual void skipped18();
    virtual void skipped19();
    virtual void skipped20();
    virtual void skipped21();
    virtual void skipped22();
    virtual void skipped23();
    virtual void skipped24();
    virtual void skipped25();
    virtual void skipped26();
    virtual void skipped27();
    virtual void* GetResource(const void* key);
};
struct Device
{
    virtual void skipped0();
    virtual void skipped1();
    virtual void skipped2();
    virtual void skipped3();
    virtual void skipped4();
    virtual void skipped5();
    virtual void skipped6();
    virtual void skipped7();
    virtual void skipped8();
    virtual void skipped9();
    virtual void skipped10();
    virtual void skipped11();
    virtual void skipped12();
    virtual void skipped13();
    virtual void skipped14();
    virtual void skipped15();
    virtual void skipped16();
    virtual void skipped17();
    virtual void skipped18();
    virtual void skipped19();
    virtual void skipped20();
    virtual void skipped21();
    virtual void skipped22();
    virtual void skipped23();
    virtual void skipped24();
    virtual void skipped25();
    virtual void skipped26();
    virtual void skipped27();
    virtual void skipped28();
    virtual void skipped29();
    virtual void Draw(void* r, int a, unsigned short b, int c, void* d);
};
struct DeviceOwner
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    Device* m5c;
};
extern DeviceOwner* DAT_0126f74c;
typedef void(__thiscall* RenderDrawFn)(Device*, void*, int, unsigned short, int, void*);
struct FUN_00bbd000_cls
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    Lighting30shaderMapView* m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    Lighting30shaderMapView* m70;
    int RenderFrame(int a1, Parameters* params, Frame* frame, int a4, int a5, int a6, int extra, int a8);
};
// If a frame is given and m38 is zero and a stage is active or m34 equals m70, submits params to the pipeline and draws the frame via the device.
// @fnv 0x00bbd000
int FUN_00bbd000_cls::RenderFrame(int aiUnused, Parameters* params, Frame* frame, int aiUnused4, int aiUnused5,
                                  int aiUnused6, int extra, int aiUnused8)
{
    if (frame && m38 == 0 && ((DAT_01201090 && DAT_01201090->active) || m34 == m70))
    {
        DAT_011f9508->NiDX9Renderer_CalculateBoneMatrices(params, extra, 0, 3, 1);
        Lighting30shaderMapView* resource = m70;
        int texture = params->m28;
        int address = params->m20;
        if (m34 == resource)
        {
            Device* device = DAT_0126f74c->m5c;
            RenderDrawFn* slot = (RenderDrawFn*)((char*)*(void**)device + 0x78);
            (*slot)(device, resource->GetResource(&DAT_010a1cac), texture, frame->m20, address, frame->m04);
        }
        else
        {
            Device* device = DAT_0126f74c->m5c;
            device->Draw(DAT_01201090, texture, frame->m20, address, frame->m04);
        }
    }
    return 0;
}
}  // namespace fnv_00bbd000


struct ShaderDescriptor
{
    const char* pFileName;
    D3DXMACRO kMacros[9];
};

__declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

class BSPixelShader
{
  public:
    virtual ~BSPixelShader();
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

class BSPixelShaderPtr
{
  public:
    BSPixelShader* m_pObject;

    BSPixelShaderPtr& operator=(BSPixelShader* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (pObject != 0)
                pObject->IncRefCount();
        }
        return *this;
    }
};


void __cdecl FUN_00be0c00(const char* pFileName, char* pPath);
int __cdecl BSsprintf(char* pBuffer, int iSize, const char* pFormat, ...);
int __cdecl sprintf(char* pBuffer, const char* pFormat, ...);
int __cdecl FUN_004dc060(bool bArg);

extern int DAT_011f91b0;
extern bool DAT_011f94a4;
extern BSPixelShaderPtr DAT_01200c48[50];
extern BSPixelShaderPtr DAT_01200d10[24];

class SM3ShaderLoader
{
  public:
    BSPixelShader* CreatePixelShader(const char* pPath, D3DXMACRO* apMacros, const char* pProfile, const char* pName);
    void Lighting30Shader_LoadPixelShaders();
};

// Creates SM3 pixel shaders into DAT_01200c48 and DAT_01200d10 from kDescs, adjusting macro definitions by iVersion and DAT_011f94a4.
// @fnv 0x00bba5d0
// src: COMMUNITY 0x00bba5d0
void SM3ShaderLoader::Lighting30Shader_LoadPixelShaders()
{
    ShaderDescriptor kDescs[50] = {
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "9", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "SPECULAR", NULL, NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "HAIR", "1", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "7", "HAIR", "1", "SPECULAR", NULL, NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "PARALLAX", "", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "PARALLAXOCC", "30", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "PARALLAX", "", "SPECULAR", NULL, NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "PARALLAXOCC", "30", "SPECULAR", NULL, NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "FACEGENBLEND", "", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "FACEGENBLEND", "", "SPECULAR", NULL, NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "GLOW", "", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "GLOW", "", "SPECULAR", NULL, NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "PROJSHADOW", "", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "SPECULAR", NULL, "PROJSHADOW", "", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "HAIR", "1", "PROJSHADOW", "", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "7", "HAIR", "1", "SPECULAR", NULL, "PROJSHADOW", "", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "PARALLAX", "", "PROJSHADOW", "", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "PARALLAXOCC", "30", "PROJSHADOW", "", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "PARALLAX", "", "SPECULAR", NULL, "PROJSHADOW", "",
         NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "PARALLAXOCC", "30", "SPECULAR", NULL, "PROJSHADOW", "",
         NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "FACEGENBLEND", "", "PROJSHADOW", "", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "FACEGENBLEND", "", "SPECULAR", NULL, "PROJSHADOW", "",
         NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "GLOW", "", "PROJSHADOW", "", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "8", "GLOW", "", "SPECULAR", NULL, "PROJSHADOW", "", NULL},
        {"lighting\\2x\\p\\EnvMap.p.hlsl", "SM3", "", NULL},
        {"lighting\\2x\\p\\EnvMap.p.hlsl", "SM3", "", "WINDOW", NULL, NULL},
        {"lighting\\2x\\p\\EnvMap.p.hlsl", "SM3", "", "EYE", NULL, NULL},
        {"lighting\\2x\\p\\WaterFog.p.hlsl", "SM3", "", NULL},
        {"lighting\\2x\\p\\WaterFog.p.hlsl", "SM3", "", "ALPHATESTING", "", NULL},
        {"lighting\\3x\\SM3SimpleShadow.p.hlsl", "SOFTSHADOW", "4", "DEPTHBIAS", "-2", "SHADOWMODE", "3", NULL},
        {"lighting\\3x\\SM3DepthMap.p.hlsl", "SHADOWMODE", "3", NULL},
        {"lighting\\3x\\SM3DepthMap.p.hlsl", "SHADOWMODE", "3", NULL},
        {"lighting\\2x\\p\\renderNormals.p.hlsl", "SM3", NULL, NULL},
        {"lighting\\2x\\p\\renderNormals.p.hlsl", "SM3", NULL, NULL},
        {"lighting\\2x\\p\\renderNormals.p.hlsl", "SM3", NULL, "FIRE", "", NULL},
        {"lighting\\2x\\p\\renderNormals.p.hlsl", "SM3", NULL, "CLEAR", "", NULL},
        {"lighting\\2x\\p\\renderNormals.p.hlsl", "SM3", NULL, "CLEAR", "", NULL},
        {"lighting\\3x\\SM3Lighting.p.hlsl", "MAXLIGHTS", "1", "SILHOUETTE", "", NULL},
        {"lighting\\2x\\p\\renderDepth.p.hlsl", "SM3", NULL, NULL},
        {"lighting\\2x\\p\\renderVelocity.p.hlsl", "SM3", NULL, NULL},
        {"lighting\\2x\\p\\localMap.p.hlsl", "SM3", NULL, NULL},
        {"lighting\\2x\\p\\localMap.p.hlsl", "SM3", NULL, "CLEAR", NULL, NULL},
        {"lighting\\1x\\p\\texEffect.p.hlsl", "HQ", "", NULL},
        {"lighting\\1x\\p\\texEffect.p.hlsl", "HQ", "", NULL},
        {"lighting\\3x\\SM3ZOnly.p.hlsl", NULL},
        {"lighting\\3x\\SM3ZOnly.p.hlsl", NULL},
        {"lighting\\3x\\SM3ZOnly.p.hlsl", NULL},
        {"lighting\\3x\\SM3ZOnly.p.hlsl", NULL},
        {"lighting\\3x\\SM3ZOnly.p.hlsl", "CONSTALPHA", "", NULL},
        {"lighting\\3x\\SM3ZOnly.p.hlsl", "CONSTALPHA", "", NULL},
    };
    char szShaderPath[260];
    char szShaderName[260];

    const char* pProfile = NiD3DGPUProgramCache::GetPixelShaderProfile(false);
    char szTwo[3] = "2";
    char szFour[3] = "4";
    char szTwenty[3] = "20";
    char szShadowMode[2];
    sprintf(szShadowMode, "%i", DAT_011f91b0);
    kDescs[29].kMacros[2].Definition = szShadowMode;
    kDescs[30].kMacros[0].Definition = szShadowMode;
    kDescs[31].kMacros[0].Definition = szShadowMode;

    for (int i = 0; i < 50; i++)
    {
        D3DXMACRO* apMacros = kDescs[i].kMacros;
        FUN_00be0c00(kDescs[i].pFileName, szShaderPath);
        BSsprintf(szShaderName, 260, "SM3%03i.pso", i);
        int iVersion = FUN_004dc060(false);
        if (iVersion == 7)
        {
            if (i < 24)
                apMacros[0].Definition = szFour;
            if (i == 2 || i == 3 || i == 14 || i == 15)
                apMacros[1].Definition = szTwo;
            DAT_01200c48[i] = CreatePixelShader(szShaderPath, apMacros, pProfile, szShaderName);
        }
        else if (iVersion == 5 || iVersion == 6)
        {
            if (i < 24)
                apMacros[0].Definition = szFour;
            if (i == 5 || i == 7 || i == 17 || i == 19)
            {
                if (DAT_011f94a4)
                    DAT_01200c48[i] = CreatePixelShader(szShaderPath, apMacros, "ps_3_0", szShaderName);
                else
                {
                    apMacros[1].Definition = szTwenty;
                    DAT_01200c48[i] = CreatePixelShader(szShaderPath, apMacros, pProfile, szShaderName);
                }
            }
            else
                DAT_01200c48[i] = CreatePixelShader(szShaderPath, apMacros, pProfile, szShaderName);
        }
        else
        {
            if (i == 5 || i == 7 || i == 17 || i == 19)
            {
                if (DAT_011f94a4)
                    DAT_01200c48[i] = CreatePixelShader(szShaderPath, apMacros, "ps_3_0", szShaderName);
                else
                {
                    apMacros[1].Definition = szTwenty;
                    DAT_01200c48[i] = CreatePixelShader(szShaderPath, apMacros, pProfile, szShaderName);
                }
            }
            else
                DAT_01200c48[i] = CreatePixelShader(szShaderPath, apMacros, pProfile, szShaderName);
        }

        if (i < 24)
        {
            BSsprintf(szShaderName, 260, "SM3LL%03i.pso", i);
            apMacros[0].Definition = szTwo;
            if (i == 5 || i == 7 || i == 17 || i == 19)
            {
                if (DAT_011f94a4)
                    DAT_01200d10[i] = CreatePixelShader(szShaderPath, apMacros, "ps_3_0", szShaderName);
                else
                {
                    apMacros[1].Definition = szTwenty;
                    DAT_01200d10[i] = CreatePixelShader(szShaderPath, apMacros, pProfile, szShaderName);
                }
            }
            else
                DAT_01200d10[i] = CreatePixelShader(szShaderPath, apMacros, pProfile, szShaderName);
        }
    }
}

namespace fnv_00bbbe80 {
struct Flag_bbb890
{
    int unk00;
    int unk04;
    bool bOn;
};
extern NiPoint3 DAT_011fa2a0;
extern void* DAT_011f91c8;
struct PlaneVector
{
    NiPoint3 normal;
    float w;
    float Dot(const NiPoint3& p) const
    {
        return normal.Dot(p);
    }
    float Distance(const NiPoint3& p) const
    {
        return Dot(p) - w;
    }
};
struct ResultVector
{
    float x, y, z, w;
    ResultVector(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
    ResultVector(const NiPoint3& n, float d) : x(n.x), y(n.y), z(n.z), w(d)
    {}
};
struct FogCamera
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
    NiPoint3 position;
};
extern Flag_bbb890* DAT_012010e4;
extern PlaneVector DAT_011f9604;
extern float DAT_011f9614, DAT_011f9618;
extern ResultVector DAT_01201bc0, DAT_01201bd0;
// When DAT_012010e4->bOn, computes a fog plane from DAT_011f9604 and camera position, and sets DAT_01201bd0 from DAT_011f9614/DAT_011f9618.
// @fnv 0x00bbbe80
void UpdateFogPlanes()
{
    if (DAT_012010e4->bOn)
    {
        NiPoint3 position(DAT_011fa2a0.x, DAT_011fa2a0.y, DAT_011fa2a0.z);
        NiPoint3 camera = reinterpret_cast<FogCamera*>(DAT_011f91c8)->position;
        position.x = position.x + camera.x;
        position.y = position.y + camera.y;
        position.z = position.z + camera.z;
        PlaneVector plane = DAT_011f9604;
        NiPoint3 normal = DAT_011f9604.normal;
        DAT_01201bc0 = ResultVector(normal, plane.Distance(position));
        float end = DAT_011f9618;
        float start = DAT_011f9614;
        if (end == 0.0f && start == 0.0f)
            DAT_01201bd0 = ResultVector(0.0f, 0.0f, -1.0f, 0.0f);
        else
            DAT_01201bd0 = ResultVector(end, end - start, 1.0f, 1.0f);
    }
}
}  // namespace fnv_00bbbe80

namespace fnv_00bbc050 {

struct RenderData
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
    Lighting30Packet4 light154;
};
struct LightingSource
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int flags20;
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
    float intensity6c;
    unsigned short BSShaderLightingProperty_GetNumberofActiveLights();
};
struct EffectOp
{
    unsigned int unk00;
    unsigned short opCode04;
    unsigned short unk06;
    unsigned char unk08;
    unsigned char count09;
    unsigned char unk0a;
    unsigned char unk0b;
    int* indices0c;
};
struct OtherData
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
    float value38;
};
struct RenderState
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    int value20;
};
struct SizeScale
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
    float scale30;
};
struct Matrix;
struct PositionAlphaEntry
{
    NiPoint3 position;
    float alpha;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
};
extern int DAT_011f91b8;
extern unsigned char DAT_011f941e;
extern unsigned char DAT_011f91a7;
extern unsigned char DAT_011f9427;
extern float DAT_011f9184;
extern NiColorA DAT_011fa0d0;
extern float DAT_01201c70, DAT_01201c74, DAT_01201c78, DAT_01201c7c;
extern NiColorA DAT_01201c80;
extern PositionAlphaEntry DAT_01201c90[];
extern int DAT_011ae60c;
struct ActorOrigin
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
    NiPoint3 position1e4;
};
extern ActorOrigin* DAT_011f91c8;
extern RenderState* DAT_012010e8;
extern const float DAT_01016248;
RenderData* __cdecl BSShaderManager_GetCurrentAccumulator();
void __cdecl SetLightColor(int i, int v, float amount);
void __cdecl ApplyWaterLighting(int i, int v, float amount);
void __stdcall D3DXVec3TransformNormal_00ee6df2(NiPoint3* dst, const NiPoint3* src, const Matrix* matrix);
void __stdcall D3DXVec3Normalize_00ee6dec(NiPoint3* dst, const NiPoint3* src);
void __stdcall D3DXVec3TransformCoord_00ee6df8(NiPoint3* dst, const NiPoint3* src, const Matrix* matrix);
// Sets light colors and updates position/alpha entries in DAT_01201c90 using matrix transforms, actor origin, and scale adjustments.
// @fnv 0x00bbc050
// src: COMMUNITY 0x00bbc050
void __stdcall Lighting30Shader_SetupGeometryConstants_Lights(LightingSource* source, EffectOp* op, unsigned int type, OtherData* detail, Matrix* matrix,
                            int adjustScale, SizeScale* size)
{
    NiPoint3 vPoint, v;
    float amount = source->intensity6c;
    if (DAT_011f91b8 == 15)
    {
        RenderData* data = BSShaderManager_GetCurrentAccumulator();
        DAT_01201b30.x = data->light154.x;
        DAT_01201b30.y = data->light154.y;
        DAT_01201b30.z = data->light154.z;
        DAT_01201b30.w = data->light154.w;
        return;
    }
    unsigned short opcode = op->opCode04;
    int count = op->count09;
    unsigned short usLo = 0x1c4, usHi = 0x1c7;
    if ((opcode >= (unsigned short)0x1c8 && opcode <= (unsigned short)0x1cb) || (opcode >= usLo && opcode <= usHi))
    {
        SetLightColor(0, op->indices0c[0], amount);
    }
    else
    {
        if (count > 0)
            ApplyWaterLighting(0, op->indices0c[0], amount);
        for (int i = 1; i < count; ++i)
            SetLightColor(i, op->indices0c[i], amount);
    }
    if (DAT_011f941e && (source->flags20 & 0x400) > 0)
    {
        DAT_011fa0d0 = DAT_011fa0d0 * DAT_011f9184;
    }
    if (DAT_011f91a7)
        *reinterpret_cast<Lighting30Packet4*>(&DAT_011fa0d0) = DAT_011a9bd0;
    if (type < 0x1bd)
    {
        unsigned short cnt;
        if (op->count09 > 0)
        {
            int vv = op->count09;
            if (DAT_011ae60c < vv)
                vv = DAT_011ae60c;
            cnt = (unsigned short)(vv - 1);
        }
        else
        {
            cnt = 0;
        }
        DAT_01201c70 = 1.0f;
        DAT_01201c74 = (float)(int)cnt;
        DAT_01201c78 = detail->value38;
        DAT_01201c7c = DAT_011f9427 ? 0.0f : 1.0f;
        DAT_012010e8->value20 = (int)(cnt + cnt + 3);
    }
    else if (type == 0x1c3)
    {
        if (source->BSShaderLightingProperty_GetNumberofActiveLights() == 0)
        {
            if (DAT_011f91b8 == 10)
            {
                DAT_01201c80 = NiColorA(DAT_01016248, DAT_01016248, DAT_01016248, 1.0f);
            }
            else
            {
                *reinterpret_cast<Lighting30Packet4*>(&DAT_01201c80) = DAT_01201b30;
            }
        }
        DAT_012010e8->value20 = 2;
    }
    else
    {
        if (type - 0x1c4 <= 3)
        {
            DAT_012010e8->value20 = 3;
            DAT_01201c70 = 0.0f;
            DAT_01201c74 = 1.0f;
        }
        else
        {
            DAT_012010e8->value20 = 3;
            DAT_01201c70 = 0.0f;
            DAT_01201c74 = 0.0f;
        }
    }
    {
        NiPoint3 vTransformed;
        int offset = 0;
        int primaryCount = (int)DAT_01201c70;
        int secondaryCount = (int)DAT_01201c74;
        if ((type < 0x1c4 || type > 0x1c7) && primaryCount > 0)
        {
            PositionAlphaEntry* pEntry = DAT_01201c90 + 1;

            while (offset < primaryCount)
            {
                NiColorA vNeg(-pEntry[-1].position.x, -pEntry[-1].position.y, -pEntry[-1].position.z,
                                 pEntry[-1].alpha);
                vPoint.x = vNeg.r;
                vPoint.y = vNeg.g;
                vPoint.z = vNeg.b;
                D3DXVec3TransformNormal_00ee6df2(&vTransformed, &vPoint, matrix);
                D3DXVec3Normalize_00ee6dec(&vPoint, &vTransformed);
                NiPoint3 vTemp(vPoint.x, vPoint.y, vPoint.z);
                v = vTemp;
                v.Unitize_004a0c10();
                pEntry[-1].position.x = v.x;
                ++pEntry;
                pEntry[-2].position.y = v.y;
                pEntry[-2].position.z = v.z;
                ++offset;
            }
        }
        for (int i = 0; i < secondaryCount; ++i)
        {
            PositionAlphaEntry& refEntry = DAT_01201c90[offset + i];
            NiColorA vEntryCopy = *reinterpret_cast<NiColorA*>(&refEntry);
            v.x = vEntryCopy.r;
            v.y = vEntryCopy.g;
            v.z = vEntryCopy.b;
            NiPoint3 vOrigin = DAT_011f91c8->position1e4;
            v += vOrigin;
            D3DXVec3TransformCoord_00ee6df8(&vTransformed, &v, matrix);
            vPoint.x = vTransformed.x;
            vPoint.y = vTransformed.y;
            vPoint.z = vTransformed.z;
            float opacity = vEntryCopy.a;
            if (adjustScale == 0)
            {
                if (type == 0x1c4 || type == 0x1c5)
                {
                    vPoint *= size->scale30;
                }
                else
                    opacity /= size->scale30;
            }
            NiColorA vCopyPosition(vPoint.x, vPoint.y, vPoint.z, opacity);
            *reinterpret_cast<NiColorA*>(&refEntry) = vCopyPosition;
        }
    }
}
}  // namespace fnv_00bbc050

namespace fnv_00bbe120 {


BSFogProperty* __cdecl BSShaderManager_GetFogProperty(int);

struct PacketF
{
    float x;
    float y;
    float z;
    float w;
};
struct P4_bbb890
{
    float x;
    float y;
    float z;
    float w;
};

extern unsigned int DAT_01200a28[];
extern unsigned int DAT_01200868[];
extern Lighting30PacketState* DAT_01201080[];
extern unsigned char DAT_01200854[];
extern unsigned char DAT_01200848[];
extern Lighting30PacketState* DAT_012010bc;
extern Lighting30PacketState* DAT_012010c0;
extern Lighting30PacketState* DAT_012010c8;
extern Lighting30PacketState* DAT_012010cc;
extern Lighting30PacketState* DAT_012010d0;
extern Lighting30PacketState* DAT_012010d4;
extern Lighting30PacketState* DAT_012010d8;
extern Lighting30PacketState* DAT_012010dc;
extern Lighting30PacketState* DAT_012010e0;
extern Lighting30PacketState* DAT_012010e4;
extern Lighting30PacketState* DAT_012010e8;
extern unsigned char DAT_011f91c4;
extern PacketF DAT_012013b0;
extern PacketF DAT_012013c0;
extern PacketF DAT_012013d0;
extern P4_bbb890 DAT_011fa2a0;
extern NiPoint3 DAT_011f474c;

class MapOwner : public NiD3DShader
{
  public:
    void UpdateShaderDirtyFlags(int);
};

// Maps a shader index to a table entry, sets dirty flags on Lighting30PacketState objects, and updates fog and position packet data when their states are dirty.
// @fnv 0x00bbe120
void MapOwner::UpdateShaderDirtyFlags(int aiShaderIndex)
{
    PacketF t;
    if (aiShaderIndex == 480 || aiShaderIndex == 481)
        return;
    int iTableIndex;
    switch ((unsigned int)aiShaderIndex)
    {
    case 467:
        iTableIndex = 89;
        break;
    case 10:
        iTableIndex = 1;
        break;
    case 11:
        iTableIndex = 2;
        break;
    case 12:
        iTableIndex = 3;
        break;
    case 13:
        iTableIndex = 4;
        break;
    case 14:
        iTableIndex = 5;
        break;
    case 15:
        iTableIndex = 6;
        break;
    case 468:
        iTableIndex = 90;
        break;
    case 469:
        iTableIndex = 91;
        break;
    case 470:
        iTableIndex = 92;
        break;
    case 471:
        iTableIndex = 93;
        break;
    case 472:
        iTableIndex = 94;
        break;
    case 473:
        iTableIndex = 95;
        break;
    case 474:
        iTableIndex = 96;
        break;
    case 730:
        iTableIndex = 104;
        break;
    case 731:
        iTableIndex = 105;
        break;
    case 736:
        iTableIndex = 104;
        break;
    case 737:
        iTableIndex = 105;
        break;
    case 742:
        iTableIndex = 104;
        break;
    case 743:
        iTableIndex = 105;
        break;
    case 748:
        iTableIndex = 104;
        break;
    case 749:
        iTableIndex = 105;
        break;
    default:
        iTableIndex = aiShaderIndex - 376;
        break;
    }

    int i = 0;
    unsigned int mask = i + 1;
    for (; i < 17; i++)
    {
        Lighting30PacketState* s = DAT_01201080[i];
        if (s)
            s->dirty = (DAT_01200a28[iTableIndex] & ((mask << 1) | (mask >> 31))) != 0;
        mask = (mask << 1) | (mask >> 31);
        DAT_01200854[i] = (DAT_01200a28[iTableIndex] & mask) != 0;
    }

    if (DAT_012010c4)
        DAT_012010c4->dirty = (DAT_01200868[iTableIndex] >> 1) & 1;
    DAT_01200848[0] = (unsigned char)((DAT_01200868[iTableIndex] >> 1) & 1);
    if (DAT_012010c8)
        DAT_012010c8->dirty = (DAT_01200868[iTableIndex] >> 2) & 1;
    DAT_01200848[1] = (unsigned char)((DAT_01200868[iTableIndex] >> 2) & 1);
    if (DAT_012010cc)
        DAT_012010cc->dirty = (DAT_01200868[iTableIndex] >> 3) & 1;
    DAT_01200848[2] = (unsigned char)((DAT_01200868[iTableIndex] >> 3) & 1);
    if (DAT_012010d0)
        DAT_012010d0->dirty = (DAT_01200868[iTableIndex] >> 4) & 1;
    DAT_01200848[3] = (unsigned char)((DAT_01200868[iTableIndex] >> 4) & 1);
    if (DAT_012010d4)
        DAT_012010d4->dirty = (DAT_01200868[iTableIndex] >> 5) & 1;
    DAT_01200848[4] = (unsigned char)((DAT_01200868[iTableIndex] >> 5) & 1);
    if (DAT_012010d8)
        DAT_012010d8->dirty = (DAT_01200868[iTableIndex] >> 6) & 1;
    DAT_01200848[5] = (unsigned char)((DAT_01200868[iTableIndex] >> 6) & 1);
    if (DAT_012010dc)
        DAT_012010dc->dirty = (DAT_01200868[iTableIndex] >> 7) & 1;
    DAT_01200848[6] = (unsigned char)((DAT_01200868[iTableIndex] >> 7) & 1);
    if (DAT_012010e0)
        DAT_012010e0->dirty = (DAT_01200868[iTableIndex] >> 8) & 1;
    DAT_01200848[7] = (unsigned char)((DAT_01200868[iTableIndex] >> 8) & 1);
    if (DAT_012010e4)
        DAT_012010e4->dirty = (DAT_01200868[iTableIndex] >> 9) & 1;
    DAT_01200848[8] = (unsigned char)((DAT_01200868[iTableIndex] >> 9) & 1);
    if (DAT_012010e8)
        DAT_012010e8->dirty = (DAT_01200868[iTableIndex] >> 10) & 1;
    DAT_01200848[9] = (unsigned char)((DAT_01200868[iTableIndex] >> 10) & 1);

    m_spVertexConstantMap.m_pObject->vf09();
    m_spPixelConstantMap.m_pObject->vf09();

    if (DAT_012010bc->dirty)
    {
        BSFogProperty* pFogProperty = BSShaderManager_GetFogProperty(DAT_011f91c4);
        if (pFogProperty)
        {
            float v2c = pFogProperty->nearDepth;
            NiColor pt = pFogProperty->color;
            float v30 = pFogProperty->farDepth;
            float v60 = pFogProperty->density;
            if (v30 == 0.0f && v2c == 0.0f)
            {
                t.x = 500000.0f;
                t.y = 0.0f;
                t.z = v60;
                t.w = 0.0f;
                DAT_012013b0 = t;
                DAT_012013c0 = *(PacketF*)&DAT_011a9bd0;
            }
            else
            {
                PacketF packetFogData;
                packetFogData.x = v30;
                packetFogData.y = v30 - v2c;
                packetFogData.z = v60;
                packetFogData.w = 0.0f;
                DAT_012013b0 = packetFogData;
                PacketF u;
                u.x = pt.r;
                u.y = pt.g;
                u.z = pt.b;
                u.w = 1.0f;
                DAT_012013c0 = u;
            }
        }
    }

    if (DAT_012010c0->dirty)
    {
        P4_bbb890 a = DAT_011fa2a0;
        t.x = a.x - DAT_011f474c.x;
        t.y = a.y - DAT_011f474c.y;
        t.z = a.z - DAT_011f474c.z;
        PacketF packetFogData;
        packetFogData.x = t.x;
        packetFogData.y = t.y;
        packetFogData.z = t.z;
        packetFogData.w = 1.0f;
        DAT_012013d0 = packetFogData;
    }
}
}  // namespace fnv_00bbe120

namespace fnv_00c0bd40 {
struct DummyVTable
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void vfdc();
    virtual void vfe0();
    virtual void vfe4();
    virtual void vfe8();
    virtual void vfec();
    virtual void vff0();
    virtual void* GetTexture(int, int);
};
extern int DAT_01200ec0, DAT_01201b50, DAT_01201b54, DAT_01201b58, DAT_01201b5c;
extern float DAT_01201b90, DAT_01201b94, DAT_01201360, DAT_01201364, DAT_01201368;
extern NiPoint3 DAT_011f474c;
extern void* DAT_011f9510;
struct PassTexture
{
    int unk00;
    int unk04;
    void* texture;
    void SetTexture(void* t)
    {
        texture = t;
    }
};
struct PassStages
{
    PassTexture* stage0;
    PassTexture* stage1;
    PassTexture* stage2;
    PassTexture* stage3;
    PassTexture* stage4;
    PassTexture* stage5;
    PassTexture* stage6;
};
struct ColorSource
{
    int unk00;
    void* data;
};
struct RenderContext : DummyVTable
{
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
    int color84;
    int color88;
    int color8c;
    int color90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    ColorSource* sourceAC;
    ColorSource* sourceB0;
    void** sourceB4;
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
    float scaleE8;
    float scaleEC;
};
struct RenderPassShader
{
    NiD3DPass* SetupPass(int kind, RenderContext* context);
    void SetupTexture(RenderContext*, NiD3DPass*);
    void SetupInput(NiD3DPass*, RenderContext*, int);
    void SetupMulti(NiD3DPass*);
    void SetupKind(NiD3DPass*, RenderContext*, int);
    void SetupGeometry(NiD3DPass*, RenderContext*);
    void SetupExtra(NiD3DPass*, RenderContext*, int);
    void SetupStages(NiD3DPass*, int);
    void SetupSecondary(RenderContext*, NiD3DPass*);
};
extern int DAT_011f9530;
extern float DAT_01201384, DAT_01201388, DAT_0120138c;
struct BoundGeometry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NiPoint3* position;
};
extern BoundGeometry** DAT_011f91e0;
extern NiPoint3 DAT_011f4288;
struct ImageEffect
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
    float parameter58;
    float GetParameter();
};
struct ImageRoot
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
    ImageEffect* effect;
};
struct ImageManager
{
    int unk00;
    int unk04;
    ImageRoot* root;
};
extern ImageManager* DAT_011f91ac;
void __cdecl ShadowLightShader_UpdateFarNear();
extern NiD3DPass* DAT_01200ec4;
extern NiD3DPass* DAT_01200ec8;
extern NiD3DPass* DAT_01200ecc;
extern NiD3DPass* DAT_01200ed0;
extern NiD3DPass* DAT_01200ed4;
extern NiD3DPass* DAT_01200ed8;
extern NiD3DPass* DAT_01200edc;
extern NiD3DPass* DAT_01200ee0;
extern NiD3DPass* DAT_01200ee4;
extern NiD3DPass* DAT_01200ee8;
extern NiD3DPass* DAT_01200eec;
extern NiD3DPass* DAT_01200ef0;
extern NiD3DPass* DAT_01200ef4;
extern NiD3DPass* DAT_01200ef8;
extern NiD3DPass* DAT_01200efc;
extern NiD3DPass* DAT_01200f00;
extern NiD3DPass* DAT_01200f04;
extern NiD3DPass* DAT_01200f08;
extern NiD3DPass* DAT_01200f0c;
extern NiD3DPass* DAT_01200f10;
extern NiD3DPass* DAT_01200f14;
extern NiD3DPass* DAT_01200f18;
extern NiD3DPass* DAT_01200f1c;
extern NiD3DPass* DAT_01200f20;
extern NiD3DPass* DAT_01200f24;
extern NiD3DPass* DAT_01200f28;
extern NiD3DPass* DAT_01200f2c;
extern NiD3DPass* DAT_01200f30;
extern NiD3DPass* DAT_01200f34;
extern NiD3DPass* DAT_01200f38;
extern NiD3DPass* DAT_01200f3c;
extern NiD3DPass* DAT_01200f40;
extern NiD3DPass* DAT_01200f44;
extern NiD3DPass* DAT_01200f48;
extern NiD3DPass* DAT_01200f4c;
extern NiD3DPass* DAT_01200f54;
extern NiD3DPass* DAT_01200f58;
extern NiD3DPass* DAT_01200f5c;
extern NiD3DPass* DAT_01200f60;
extern NiD3DPass* DAT_01200f64;
extern NiD3DPass* DAT_01200f68;
extern NiD3DPass* DAT_01200f6c;
extern NiD3DPass* DAT_01200f70;
extern NiD3DPass* DAT_01200f74;
extern NiD3DPass* DAT_01200f78;
extern NiD3DPass* DAT_01200f7c;
extern NiD3DPass* DAT_01200f80;
extern NiD3DPass* DAT_01200f84;
extern NiD3DPass* DAT_01200f88;
extern NiD3DPass* DAT_01200f8c;
extern NiD3DPass* DAT_01200f90;
extern NiD3DPass* DAT_01200f94;
extern NiD3DPass* DAT_01200f98;
extern NiD3DPass* DAT_01200f9c;
extern NiD3DPass* DAT_01200fa0;
extern NiD3DPass* DAT_01200fa4;
extern NiD3DPass* DAT_01200fa8;
extern NiD3DPass* DAT_01200fac;
extern NiD3DPass* DAT_01200fb0;
extern NiD3DPass* DAT_01200fb4;
extern NiD3DPass* DAT_01200fb8;
extern NiD3DPass* DAT_01200fbc;
extern NiD3DPass* DAT_01200fc0;
extern NiD3DPass* DAT_01200fc4;
extern NiD3DPass* DAT_01200fc8;
extern NiD3DPass* DAT_01200fcc;
extern NiD3DPass* DAT_01200fd0;
extern NiD3DPass* DAT_01200fd4;
extern NiD3DPass* DAT_01200fd8;
extern NiD3DPass* DAT_01200fdc;
extern NiD3DPass* DAT_01200fe0;
extern NiD3DPass* DAT_01200fe4;
extern NiD3DPass* DAT_01200fe8;
extern NiD3DPass* DAT_01200fec;
extern NiD3DPass* DAT_01200ff0;
extern NiD3DPass* DAT_01200ff4;
extern NiD3DPass* DAT_01200ff8;
extern NiD3DPass* DAT_01200ffc;
extern NiD3DPass* DAT_01201000;
extern NiD3DPass* DAT_01201008;
extern NiD3DPass* DAT_01201010;
extern NiD3DPass* DAT_01201014;
extern NiD3DPass* DAT_01201018;
extern NiD3DPass* DAT_0120101c;
extern NiD3DPass* DAT_01201020;
extern NiD3DPass* DAT_01201024;
extern NiD3DPass* DAT_01201028;
extern NiD3DPass* DAT_0120102c;
extern NiD3DPass* DAT_01201030;
extern NiD3DPass* DAT_01201034;
extern NiD3DPass* DAT_01201038;
extern NiD3DPass* DAT_0120103c;
extern NiD3DPass* DAT_01201040;
extern NiD3DPass* DAT_01201044;
extern NiD3DPass* DAT_01201048;
extern NiD3DPass* DAT_0120104c;
extern NiD3DPass* DAT_01201050;
extern NiD3DPass* DAT_01201054;
extern NiD3DPass* DAT_01201058;
extern NiD3DPass* DAT_0120105c;
extern NiD3DPass* DAT_01201060;
extern NiD3DPass* DAT_01201064;
extern NiD3DPass* DAT_01201068;
extern NiD3DPass* DAT_0120106c;
extern NiD3DPass* DAT_01201070;
extern NiD3DPass* DAT_01201074;
extern NiD3DPass* DAT_01201078;
extern NiD3DPass* DAT_0120107c;

inline const NiPoint3& GetGeomPosition()
{
    NiPoint3* p = (*DAT_011f91e0)->position;
    if (p)
        return *p;
    return DAT_011f4288;
}

// Selects a NiD3DPass by kind, configures its texture stages and inputs from the render context, and returns the pass.
// @fnv 0x00c0bd40
NiD3DPass* RenderPassShader::SetupPass(int kind, RenderContext* context)
{
    NiD3DPass* pass = 0;
    switch (kind)
    {
    case 10:
        pass = DAT_01200ec4;
        break;
    case 11:
        pass = DAT_01200ec8;
        break;
    case 12:
        pass = DAT_01200ecc;
        break;
    case 13:
        pass = DAT_01200ed0;
        break;
    case 14:
        pass = DAT_01200ed4;
        SetupTexture(context, pass);
        break;
    case 15:
        pass = DAT_01200ed8;
        SetupTexture(context, pass);
        break;
    case 376:
        pass = (NiD3DPass*)DAT_01200ec0;
        break;
    case 383:
        pass = DAT_01200edc;
        break;
    case 384:
        pass = DAT_01200ee0;
        break;
    case 385:
        pass = DAT_01200ee4;
        DAT_01201b50 = context->color84;
        DAT_01201b54 = context->color88;
        DAT_01201b58 = context->color8c;
        DAT_01201b5c = context->color90;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[4].m_pObject)->texture = (void*)DAT_011f9530;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[5].m_pObject)->texture = *context->sourceB4;
        break;
    case 386:
        pass = DAT_01200ee8;
        SetupInput(pass, context, 4);
        break;
    case 387:
        pass = DAT_01200eec;
        DAT_01201b90 = context->scaleE8;
        DAT_01201b94 = context->scaleEC;
        SetupInput(pass, context, 4);
        break;
    case 388:
        pass = DAT_01200ef0;
        {
            const bool withVertexColor = false;
            reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[4].m_pObject)->texture = context->sourceAC->data;
            reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[5].m_pObject)->texture = context->sourceB0->data;
            if (withVertexColor)
            {
                PassTexture* stage = reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject);
                stage->texture = context->GetTexture(2, 0);
            }
        }
        break;
    case 389:
        pass = DAT_01200ef4;
        {
            const bool withVertexColor = true;
            reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[4].m_pObject)->texture = context->sourceAC->data;
            reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[5].m_pObject)->texture = context->sourceB0->data;
            if (withVertexColor)
            {
                PassTexture* stage = reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject);
                stage->texture = context->GetTexture(2, 0);
            }
        }
        break;
    case 390:
        pass = DAT_01200ef8;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        break;
    case 391:
        pass = DAT_01200efc;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        break;
    case 392:
        pass = DAT_01200f00;
        break;
    case 393:
        pass = DAT_01200f04;
        break;
    case 394:
        pass = DAT_01200f08;
        SetupInput(pass, context, 4);
        break;
    case 395:
        pass = DAT_01200f0c;
        DAT_01201b90 = context->scaleE8;
        DAT_01201b94 = context->scaleEC;
        SetupInput(pass, context, 4);
        break;
    case 396:
        pass = DAT_01200f10;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        break;
    case 397:
        pass = DAT_01200f14;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        break;
    case 398:
        pass = DAT_01200f18;
        break;
    case 399:
        pass = DAT_01200f1c;
        break;
    case 400:
        pass = DAT_01200f20;
        DAT_01201b50 = context->color84;
        DAT_01201b54 = context->color88;
        DAT_01201b58 = context->color8c;
        DAT_01201b5c = context->color90;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[4].m_pObject)->texture = (void*)DAT_011f9530;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[5].m_pObject)->texture = *context->sourceB4;
        break;
    case 401:
        pass = DAT_01200f24;
        SetupInput(pass, context, 4);
        break;
    case 402:
        pass = DAT_01200f28;
        DAT_01201b90 = context->scaleE8;
        DAT_01201b94 = context->scaleEC;
        SetupInput(pass, context, 4);
        break;
    case 403:
        pass = DAT_01200f2c;
        {
            const bool withVertexColor = false;
            reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[4].m_pObject)->texture = context->sourceAC->data;
            reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[5].m_pObject)->texture = context->sourceB0->data;
            if (withVertexColor)
            {
                PassTexture* stage = reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject);
                stage->texture = context->GetTexture(2, 0);
            }
        }
        break;
    case 404:
        pass = DAT_01200f30;
        {
            const bool withVertexColor = true;
            reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[4].m_pObject)->texture = context->sourceAC->data;
            reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[5].m_pObject)->texture = context->sourceB0->data;
            if (withVertexColor)
            {
                PassTexture* stage = reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject);
                stage->texture = context->GetTexture(2, 0);
            }
        }
        break;
    case 405:
        pass = DAT_01200f34;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        break;
    case 406:
        pass = DAT_01200f38;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        break;
    case 407:
        pass = DAT_01200f3c;
        break;
    case 408:
        pass = DAT_01200f40;
        break;
    case 409:
        pass = DAT_01200f44;
        SetupInput(pass, context, 4);
        break;
    case 410:
        pass = DAT_01200f48;
        DAT_01201b90 = context->scaleE8;
        DAT_01201b94 = context->scaleEC;
        SetupInput(pass, context, 4);
        break;
    case 411:
        pass = DAT_01200f4c;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        break;
    case 412:
        pass = DAT_01200f14;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        break;
    case 413:
        pass = DAT_01200f54;
        SetupMulti(pass);
        break;
    case 414:
        pass = DAT_01200f58;
        SetupMulti(pass);
        break;
    case 415:
        pass = DAT_01200f5c;
        DAT_01201b50 = context->color84;
        DAT_01201b54 = context->color88;
        DAT_01201b58 = context->color8c;
        DAT_01201b5c = context->color90;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[4].m_pObject)->texture = (void*)DAT_011f9530;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[5].m_pObject)->texture = *context->sourceB4;
        SetupMulti(pass);
        break;
    case 416:
        pass = DAT_01200f60;
        SetupMulti(pass);
        SetupInput(pass, context, 4);
        break;
    case 417:
        pass = DAT_01200f64;
        DAT_01201b90 = context->scaleE8;
        DAT_01201b94 = context->scaleEC;
        SetupMulti(pass);
        SetupInput(pass, context, 4);
        break;
    case 418:
        pass = DAT_01200f68;
        SetupMulti(pass);
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[4].m_pObject)->texture = context->sourceAC->data;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[5].m_pObject)->texture = context->sourceB0->data;
        break;
    case 419:
        pass = DAT_01200f6c;
        SetupMulti(pass);
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[4].m_pObject)->texture = context->sourceAC->data;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[5].m_pObject)->texture = context->sourceB0->data;
        {
            PassTexture* stage = reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject);
            stage->texture = context->GetTexture(2, 0);
        }
        break;
    case 420:
        pass = DAT_01200f70;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        SetupMulti(pass);
        break;
    case 421:
        pass = DAT_01200f74;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        SetupMulti(pass);
        break;
    case 422:
        pass = DAT_01200f78;
        SetupMulti(pass);
        break;
    case 423:
        pass = DAT_01200f7c;
        SetupMulti(pass);
        break;
    case 424:
        pass = DAT_01200f80;
        SetupMulti(pass);
        SetupInput(pass, context, 4);
        break;
    case 425:
        pass = DAT_01200f84;
        DAT_01201b90 = context->scaleE8;
        DAT_01201b94 = context->scaleEC;
        SetupMulti(pass);
        SetupInput(pass, context, 4);
        break;
    case 426:
        pass = DAT_01200f88;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        SetupMulti(pass);
        break;
    case 427:
        pass = DAT_01200f8c;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        SetupMulti(pass);
        break;
    case 428:
        pass = DAT_01200f90;
        SetupMulti(pass);
        break;
    case 429:
        pass = DAT_01200f94;
        SetupMulti(pass);
        break;
    case 430:
        pass = DAT_01200f98;
        DAT_01201b50 = context->color84;
        DAT_01201b54 = context->color88;
        DAT_01201b58 = context->color8c;
        DAT_01201b5c = context->color90;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[4].m_pObject)->texture = (void*)DAT_011f9530;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[5].m_pObject)->texture = *context->sourceB4;
        SetupMulti(pass);
        break;
    case 431:
        pass = DAT_01200f9c;
        SetupMulti(pass);
        SetupInput(pass, context, 4);
        break;
    case 432:
        pass = DAT_01200fa0;
        DAT_01201b90 = context->scaleE8;
        DAT_01201b94 = context->scaleEC;
        SetupMulti(pass);
        SetupInput(pass, context, 4);
        break;
    case 433:
        pass = DAT_01200fa4;
        SetupMulti(pass);
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[4].m_pObject)->texture = context->sourceAC->data;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[5].m_pObject)->texture = context->sourceB0->data;
        break;
    case 434:
        pass = DAT_01200fa8;
        SetupMulti(pass);
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[4].m_pObject)->texture = context->sourceAC->data;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[5].m_pObject)->texture = context->sourceB0->data;
        {
            PassTexture* stage = reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject);
            stage->texture = context->GetTexture(2, 0);
        }
        break;
    case 435:
        pass = DAT_01200fac;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        SetupMulti(pass);
        break;
    case 436:
        pass = DAT_01200fb0;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        SetupMulti(pass);
        break;
    case 437:
        pass = DAT_01200fb4;
        SetupMulti(pass);
        break;
    case 438:
        pass = DAT_01200fb8;
        SetupMulti(pass);
        break;
    case 439:
        pass = DAT_01200fbc;
        SetupMulti(pass);
        SetupInput(pass, context, 4);
        break;
    case 440:
        pass = DAT_01200fc0;
        DAT_01201b90 = context->scaleE8;
        DAT_01201b94 = context->scaleEC;
        SetupMulti(pass);
        SetupInput(pass, context, 4);
        break;
    case 441:
        pass = DAT_01200fc4;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        SetupMulti(pass);
        break;
    case 442:
        pass = DAT_01200fc8;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[6].m_pObject)->texture = *context->sourceB4;
        SetupMulti(pass);
        break;
    case 445:
        pass = DAT_01200fd4;
        SetupKind(pass, context, kind);
        SetupGeometry(pass, context);
        SetupExtra(pass, context, 0);
        break;
    case 446:
        pass = DAT_01200fd8;
        SetupKind(pass, context, kind);
        SetupGeometry(pass, context);
        SetupExtra(pass, context, 0);
        break;
    case 447:
        pass = DAT_01200fdc;
        SetupKind(pass, context, kind);
        SetupGeometry(pass, context);
        SetupExtra(pass, context, 0);
        break;
    case 448:
        pass = DAT_01200fe0;
        SetupKind(pass, context, kind);
        SetupGeometry(pass, context);
        SetupExtra(pass, context, 0);
        break;
    case 449:
        pass = DAT_01200fe4;
        SetupKind(pass, context, kind);
        SetupGeometry(pass, context);
        SetupExtra(pass, context, 0);
        break;
    case 450:
        pass = DAT_01200fe8;
        SetupKind(pass, context, kind);
        SetupGeometry(pass, context);
        SetupExtra(pass, context, 0);
        break;
    case 451:
        pass = DAT_01200fec;
        SetupKind(pass, context, kind);
        SetupGeometry(pass, context);
        SetupExtra(pass, context, 0);
        {
            BoundGeometry* geom = *DAT_011f91e0;
            NiPoint3* position = geom->position ? geom->position : &DAT_011f4288;
            NiPoint3 relative = *position - DAT_011f474c;
            DAT_01201360 = relative.x;
            DAT_01201364 = relative.y;
            DAT_01201368 = relative.z;
        }
        break;
    case 730:
        pass = DAT_01201060;
        break;
    case 731:
        pass = DAT_01201064;
        break;
    case 736:
        pass = DAT_01201068;
        break;
    case 737:
        pass = DAT_0120106c;
        break;
    case 742:
        pass = DAT_01201070;
        break;
    case 743:
        pass = DAT_01201074;
        break;
    case 748:
        pass = DAT_01201078;
        break;
    case 749:
        pass = DAT_0120107c;
        break;
    case 452:
        pass = DAT_01200ff0;
        break;
    case 453:
        pass = DAT_01200ff4;
        break;
    case 454:
        pass = DAT_01200ff8;
        break;
    case 455:
        pass = DAT_01200ffc;
        break;
    case 480:
        pass = DAT_01201058;
        SetupSecondary(context, pass);
        break;
    case 481:
        pass = DAT_0120105c;
        SetupSecondary(context, pass);
        break;
    case 467:
        pass = DAT_01201024;
        break;
    case 468:
        pass = DAT_01201028;
        break;
    case 469:
        pass = DAT_0120102c;
        break;
    case 470:
        pass = DAT_01201030;
        break;
    case 456:
        pass = DAT_01201000;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[0].m_pObject)->texture = *(void**)context->sourceAC;
        SetupStages(pass, 1);
        break;
    case 458:
        pass = DAT_01201008;
        reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[0].m_pObject)->texture = *(void**)context->sourceAC;
        SetupStages(pass, 1);
        break;
    case 460:
        pass = DAT_01201010;
        {
            void* texture = *(void**)context->sourceB0;
            if (!texture)
                texture = DAT_011f9510;
            reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[0].m_pObject)->texture = texture;
        }
        SetupStages(pass, 1);
        break;
    case 462:
        pass = DAT_01201014;
        {
            void* texture = *(void**)context->sourceB0;
            if (!texture)
                texture = DAT_011f9510;
            reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[0].m_pObject)->texture = texture;
        }
        SetupStages(pass, 1);
        break;
    case 464:
        pass = DAT_01201018;
        {
            void* texture = *(void**)context->sourceB0;
            if (!texture)
                texture = DAT_011f9510;
            reinterpret_cast<PassTexture*>(pass->m_kStages.m_pBase[0].m_pObject)->texture = texture;
        }
        SetupStages(pass, 1);
        break;
    case 465:
        pass = DAT_0120101c;
        SetupStages(pass, 0);
        break;
    case 466:
        pass = DAT_01201020;
        SetupStages(pass, 0);
        break;
    case 443:
        pass = DAT_01200fcc;
        SetupStages(pass, 1);
        break;
    case 444:
        pass = DAT_01200fd0;
        SetupStages(pass, 1);
        break;
    case 471:
        pass = DAT_01201034;
        SetupStages(pass, 0);
        break;
    case 472:
        pass = DAT_01201038;
        SetupStages(pass, 0);
        break;
    case 473:
        pass = DAT_0120103c;
        SetupStages(pass, 0);
        ShadowLightShader_UpdateFarNear();
        break;
    case 474:
        pass = DAT_01201040;
        SetupStages(pass, 0);
        ShadowLightShader_UpdateFarNear();
        break;
    case 475:
        pass = DAT_01201044;
        SetupStages(pass, 0);
        DAT_01201384 = DAT_011f91ac->root->effect->GetParameter();
        DAT_01201388 = DAT_011f91ac->root->effect->parameter58;
        DAT_0120138c = 0.0f;
        ShadowLightShader_UpdateFarNear();
        break;
    case 476:
        pass = DAT_01201048;
        SetupStages(pass, 0);
        DAT_01201384 = DAT_011f91ac->root->effect->GetParameter();
        DAT_01201388 = DAT_011f91ac->root->effect->parameter58;
        DAT_0120138c = 0.0f;
        break;
    case 477:
        pass = DAT_0120104c;
        SetupStages(pass, 0);
        break;
    case 478:
        pass = DAT_01201050;
        SetupStages(pass, 0);
        break;
    case 479:
        pass = DAT_01201054;
        SetupStages(pass, 0);
        break;
    }
    return pass;
}
}  // namespace fnv_00c0bd40

#include <string.h>
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* p)
{
    T* pOld = m_pObject;
    if (pOld != p)
    {
        if (pOld)
        {
            if (InterlockedDecrement((volatile long*)&((NiRefObject*)(void*)pOld)->m_uiRefCount) == 0)
                ((NiRefObject*)(void*)pOld)->DeleteThis();
        }
        m_pObject = p;
        if (p)
            InterlockedIncrement((volatile long*)&((NiRefObject*)(void*)p)->m_uiRefCount);
    }
    return *this;
}

namespace fnv_00bbc640 {
template <class T> class SPtr_bbc640
{
  public:
    T* m_pObject;
    SPtr_bbc640() : m_pObject(0)
    {}
    ~SPtr_bbc640();
    SPtr_bbc640& operator=(T* p)
    {
        T* pOld = m_pObject;
        if (pOld != p)
        {
            if (pOld)
            {
                if (InterlockedDecrement((volatile long*)&((NiRefObject*)(void*)pOld)->m_uiRefCount) == 0)
                    ((NiRefObject*)(void*)pOld)->DeleteThis();
            }
            m_pObject = p;
            if (p)
                InterlockedIncrement((volatile long*)&((NiRefObject*)(void*)p)->m_uiRefCount);
        }
        return *this;
    }
};

extern int DAT_011f91c0;
extern int DAT_011ae60c;
extern int DAT_01200854;
extern int DAT_01200858;
extern int DAT_0120085c;
extern int DAT_01200860;
extern char DAT_01200864;
extern int DAT_01200848;
extern int DAT_0120084c;
extern short DAT_01200850;

class FUN_00bbc640 : public BSShader
{
  public:
    FUN_00bbc640(NiD3DVertexDeclaration* a, NiD3DVertexDeclaration* b, NiD3DVertexDeclaration* c,
                 NiD3DVertexDeclaration* d);
    SPtr_bbc640<NiD3DShaderConstantMap> m_spTexEffectP;
    SPtr_bbc640<NiD3DShaderConstantMap> m_spTexEffectV;
    SPtr_bbc640<NiD3DShaderConstantMap> m_spDefaultPixel;
    SPtr_bbc640<NiD3DShaderConstantMap> m_spDefaultVertex;
    SPtr_bbc640<NiD3DVertexDeclaration> m_spDecl;
    SPtr_bbc640<NiD3DVertexDeclaration> m_spDeclNC;
    SPtr_bbc640<NiD3DVertexDeclaration> m_spDeclVC;
    SPtr_bbc640<NiD3DVertexDeclaration> m_spDeclVCNC;
    SPtr_bbc640<NiD3DVertexDeclaration> m_spSkinned;
    SPtr_bbc640<NiD3DVertexDeclaration> m_spSkinnedNC;
    SPtr_bbc640<NiD3DVertexDeclaration> m_spSkinnedVC;
    SPtr_bbc640<NiD3DVertexDeclaration> m_spSkinnedVCNC;
    NiGeometryBufferData* m_pLast;
    int m_iZWrite;
};

// @fnv 0x00bbc640
FUN_00bbc640::FUN_00bbc640(NiD3DVertexDeclaration* apDecl, NiD3DVertexDeclaration* apSkinned,
                           NiD3DVertexDeclaration* apDeclVC, NiD3DVertexDeclaration* apSkinnedVC)
{
    iShaderType = 0x11;
    m_spShaderDecl = (NiD3DShaderDeclaration*)apDecl;
    m_spDecl = apDecl;
    m_spDeclNC = apDecl;
    m_spSkinned = apSkinned;
    m_spSkinnedNC = apSkinned;
    m_spDeclVC = apDeclVC;
    m_spDeclVCNC = apDeclVC;
    m_spSkinnedVC = apSkinnedVC;
    m_spSkinnedVCNC = apSkinnedVC;
    m_spTexEffectP = 0;
    m_spTexEffectV = 0;
    m_spDefaultPixel = 0;
    m_spDefaultVertex = 0;
    memset(&DAT_01200854, 0, 17);
    memset(&DAT_01200848, 0, 10);
    if (DAT_011f91c0 < 7)
        DAT_011ae60c = 5;
    m_pLast = 0;
    m_iZWrite = 1;
}
}  // namespace fnv_00bbc640

#include <windows.h>
namespace fnv_00bbe020 {
extern unsigned int DAT_0126f74c;
unsigned int __stdcall Lighting30Shader_SelectPass(int a1);
class Lighting30Sub_cls
{
  public:
    void FUN_00c663d0(void* p);
};

class FUN_00bbe020_cls
{
  public:
    void SetLighting(int a1);

    char unk00[0x30];
    NiRefObject* m_30;
    NiRefObject* m_34;
    char unk38[0x34];
    NiRefObject* m_6c;
    NiRefObject* m_70;
    void* m_74;
    void* m_78;
};

// Stores a1 via FUN_00c0abd0, marks globals dirty, and either swaps m_30/m_34 with m_6c/m_70 or calls FUN_00c663d0 on them when a1 is not 0x1e0/0x1e1.
// @fnv 0x00bbe020
void FUN_00bbe020_cls::SetLighting(int a1)
{
    DAT_0126f74c = Lighting30Shader_SelectPass(a1);
    DAT_01201b30 = DAT_011a9bd0;
    DAT_012010c4->dirty = true;
    DAT_01200bf4 = true;
    DAT_01200bf5 = true;

    if (a1 == 0x1e0 || a1 == 0x1e1)
    {
        NiRefObject* old = m_30;
        if (old != m_6c)
        {
            if (old != 0)
            {
                if (InterlockedDecrement((LONG*)&old->m_uiRefCount) != 0)
                {
                }
                else
                {
                    old->DeleteThis();
                }
            }
            m_30 = m_6c;
            if (m_6c != 0)
            {
                InterlockedIncrement((LONG*)&m_6c->m_uiRefCount);
            }
        }
        old = m_34;
        if (old != m_70)
        {
            if (old != 0)
            {
                if (InterlockedDecrement((LONG*)&old->m_uiRefCount) != 0)
                {
                }
                else
                {
                    old->DeleteThis();
                }
            }
            m_34 = m_70;
            if (m_70 != 0)
            {
                InterlockedIncrement((LONG*)&m_70->m_uiRefCount);
            }
        }
    }
    else
    {
        reinterpret_cast<Lighting30Sub_cls*>(&m_30)->FUN_00c663d0(&m_74);
        reinterpret_cast<Lighting30Sub_cls*>(&m_34)->FUN_00c663d0(&m_78);
    }
}
}  // namespace fnv_00bbe020

namespace fnv_00bb96f0 {
#include "../../include/_D3DXMACRO.h"
struct ShaderDescriptor
{
    const char* pFileName;
    D3DXMACRO kMacros[9];
};
struct BSVertexShader
{
    virtual ~BSVertexShader();
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
class BSVertexShaderPtr
{
  public:
    BSVertexShader* m_pObject;
    BSVertexShaderPtr& operator=(BSVertexShader* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
};
void __cdecl FUN_00be0c00(const char*, char*);
int __cdecl BSsprintf(char*, int, const char*, ...);
extern bool DAT_011f94a4;
extern const char DAT_010b9f78[];
extern BSVertexShaderPtr DAT_01200dd8[57];
class SM3ShaderLoader
{
  public:
    BSVertexShader* FUN_00be0fe0(const char*, D3DXMACRO*, const char*, const char*);
    void Lighting30Shader_LoadVertexShaders();
};
// Loads 57 vertex shader entries using the selected profile, with four entries that may instead use vs_3_0.
// @fnv 0x00bb96f0
// src: COMMUNITY 0x00bb96f0
void SM3ShaderLoader::Lighting30Shader_LoadVertexShaders()
{
    ShaderDescriptor shaderEntries[57] = {
        {"lighting\\3x\\SM3Lighting.v.hlsl", 0},
        {"lighting\\3x\\SM3Lighting.v.hlsl", 0},
        {"lighting\\3x\\SM3Lighting.v.hlsl", "SKIN", "", 0},
        {"lighting\\3x\\SM3Lighting.v.hlsl", "VC", "", 0},
        {"lighting\\3x\\SM3Lighting.v.hlsl", "VC", "", 0},
        {"lighting\\3x\\SM3Lighting.v.hlsl", "SKIN", "", "VC", "", 0},
        {"lighting\\3x\\SM3Lighting.v.hlsl", "PROJSHADOW", "", 0},
        {"lighting\\3x\\SM3Lighting.v.hlsl", "PROJSHADOW", "", 0},
        {"lighting\\3x\\SM3Lighting.v.hlsl", "SKIN", "", "PROJSHADOW", "", 0},
        {"lighting\\3x\\SM3Lighting.v.hlsl", "VC", "", "PROJSHADOW", "", 0},
        {"lighting\\3x\\SM3Lighting.v.hlsl", "VC", "", "PROJSHADOW", "", 0},
        {"lighting\\3x\\SM3Lighting.v.hlsl", "SKIN", "", "VC", "", "PROJSHADOW", "", 0},
        {"lighting\\2x\\v\\EnvMap.v.hlsl", "SM3", "", "ENVMAP", 0, 0},
        {"lighting\\2x\\v\\EnvMap.v.hlsl", "SM3", "", "ENVMAP", 0, "VC", "", 0},
        {"lighting\\2x\\v\\EnvMap.v.hlsl", "SM3", "", "ENVMAP", 0, "SKIN", "", 0},
        {"lighting\\2x\\v\\EnvMap.v.hlsl", "SM3", "", "ENVMAP", 0, "SKIN", "", "VC", "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {"lighting\\2x\\v\\EnvMap.v.hlsl", "SM3", "", "ENVMAP", 0, "EYE", 0, 0},
        {"lighting\\2x\\v\\WaterFog.v.hlsl", "SM3", "", 0},
        {"lighting\\2x\\v\\WaterFog.v.hlsl", "SM3", "", "SKIN", "", 0},
        {"lighting\\2x\\v\\WaterFog.v.hlsl", "SM3", "", "TEXCOORD", "", 0},
        {"lighting\\2x\\v\\WaterFog.v.hlsl", "SM3", "", "SKIN", "", "TEXCOORD", "", 0},
        {"lighting\\2x\\v\\WaterFog.v.hlsl", "SM3", "", "VC", "", 0},
        {"lighting\\2x\\v\\WaterFog.v.hlsl", "SM3", "", "SKIN", "", "VC", "", 0},
        {"lighting\\2x\\v\\WaterFog.v.hlsl", "SM3", "", "TEXCOORD", "", "VC", "", 0},
        {"lighting\\2x\\v\\WaterFog.v.hlsl", "SM3", "", "SKIN", "", "TEXCOORD", "", "VC", "", 0, 0, 0, 0, 0, 0, 0, 0, 0,
         0},
        {"lighting\\3x\\SM3SimpleShadow.v.hlsl", 0},
        {"lighting\\3x\\SM3SimpleShadow.v.hlsl", "VC", 0, 0},
        {"lighting\\3x\\SM3SimpleShadow.v.hlsl", "SKIN", "", 0},
        {"lighting\\3x\\SM3SimpleShadow.v.hlsl", "SKIN", "", "VC", 0, 0},
        {"lighting\\3x\\SM3DepthMap.v.hlsl", 0},
        {"lighting\\3x\\SM3DepthMap.v.hlsl", "VC", "", 0},
        {"lighting\\3x\\SM3DepthMap.v.hlsl", "SKIN", "", 0},
        {"lighting\\3x\\SM3DepthMap.v.hlsl", "VC", "", "SKIN", "", 0},
        {"lighting\\2x\\v\\renderNormals.v.hlsl", "SM3", 0, 0},
        {"lighting\\2x\\v\\renderNormals.v.hlsl", "SM3", 0, "SKIN", "", 0},
        {"lighting\\2x\\v\\renderNormals.v.hlsl", "SM3", 0, "FIRE", "", 0},
        {"lighting\\2x\\v\\renderNormals.v.hlsl", "SM3", 0, "CLEAR", "", 0},
        {"lighting\\2x\\v\\renderNormals.v.hlsl", "SM3", 0, "CLEAR", "", "SKIN", "", 0},
        {"lighting\\2x\\v\\renderDepth.v.hlsl", "SM3", 0, 0},
        {"lighting\\2x\\v\\renderDepth.v.hlsl", "SM3", 0, "VC", 0, 0},
        {"lighting\\2x\\v\\renderDepth.v.hlsl", "SM3", 0, "SKIN", "", 0},
        {"lighting\\2x\\v\\renderDepth.v.hlsl", "SM3", 0, "SKIN", "", "VC", 0, 0},
        {"lighting\\2x\\v\\renderVelocity.v.hlsl", "SM3", 0, 0},
        {"lighting\\2x\\v\\renderVelocity.v.hlsl", "SM3", 0, "SKIN", "", 0},
        {"lighting\\2x\\v\\localMap.v.hlsl", "SM3", 0, 0},
        {"lighting\\2x\\v\\localMap.v.hlsl", "SM3", 0, "SKIN", "", 0},
        {"lighting\\2x\\v\\localMap.v.hlsl", "SM3", 0, "CLEAR", "", 0},
        {"lighting\\1x\\v\\texEffect.v.hlsl", 0},
        {"lighting\\1x\\v\\texEffect.v.hlsl", "SKIN", "", 0},
        {"lighting\\3x\\SM3ZOnly.v.hlsl", 0},
        {"lighting\\3x\\SM3ZOnly.v.hlsl", "SKIN", "", 0},
        {"lighting\\3x\\SM3ZOnly.v.hlsl", "VC", "", 0},
        {"lighting\\3x\\SM3ZOnly.v.hlsl", "VC", "", "SKIN", "", 0},
        {"lighting\\3x\\SM3ZOnly.v.hlsl", 0},
        {"lighting\\3x\\SM3ZOnly.v.hlsl", "SKIN", "", 0},
        {"lighting\\3x\\SM3ZOnly.v.hlsl", 0},
        {"lighting\\3x\\SM3ZOnly.v.hlsl", "SKIN", "", 0},
    };
    char shaderPath[260];
    char name[260];
    const char* shaderProfile = NiD3DGPUProgramCache::GetVertexShaderProfile();
    for (int i = 0; i < 57; ++i)
    {
        D3DXMACRO* macros = shaderEntries[i].kMacros;
        FUN_00be0c00(shaderEntries[i].pFileName, shaderPath);
        BSsprintf(name, 260, DAT_010b9f78, i);
        if (i == 1 || i == 4 || i == 7 || i == 10)
        {
            if (DAT_011f94a4)
                DAT_01200dd8[i] = FUN_00be0fe0(shaderPath, macros, "vs_3_0", name);
            else
                DAT_01200dd8[i] = FUN_00be0fe0(shaderPath, macros, shaderProfile, name);
        }
        else
            DAT_01200dd8[i] = FUN_00be0fe0(shaderPath, macros, shaderProfile, name);
    }
}
}  // namespace fnv_00bb96f0

namespace fnv_00bbef90 {
struct Plane
{
    float a, b, c, d;
};
union Scratch
{
    float vector[3];
    Plane plane;
    Scratch()
    {}
};
struct RawMat
{
    float m[4][4];
};
struct Mat : RawMat
{
    Mat()
    {}
    Mat(const RawMat& o)
    {
        memcpy(this, &o, sizeof(Mat));
    }
};
struct __declspec(align(16)) MatA : Mat
{
};

struct Renderer
{
    int field_000;
    int field_004;
    int field_008;
    int field_00c;
    int field_010;
    int field_014;
    int field_018;
    int field_01c;
    int field_020;
    int field_024;
    int field_028;
    int field_02c;
    int field_030;
    int field_034;
    int field_038;
    int field_03c;
    int field_040;
    int field_044;
    int field_048;
    int field_04c;
    int field_050;
    int field_054;
    int field_058;
    int field_05c;
    int field_060;
    int field_064;
    int field_068;
    int field_06c;
    int field_070;
    int field_074;
    int field_078;
    int field_07c;
    int field_080;
    int field_084;
    int field_088;
    int field_08c;
    int field_090;
    int field_094;
    int field_098;
    int field_09c;
    int field_0a0;
    int field_0a4;
    int field_0a8;
    int field_0ac;
    int field_0b0;
    int field_0b4;
    int field_0b8;
    int field_0bc;
    int field_0c0;
    int field_0c4;
    int field_0c8;
    int field_0cc;
    int field_0d0;
    int field_0d4;
    int field_0d8;
    int field_0dc;
    int field_0e0;
    int field_0e4;
    int field_0e8;
    int field_0ec;
    int field_0f0;
    int field_0f4;
    int field_0f8;
    int field_0fc;
    int field_100;
    int field_104;
    int field_108;
    int field_10c;
    int field_110;
    int field_114;
    int field_118;
    int field_11c;
    int field_120;
    int field_124;
    int field_128;
    int field_12c;
    int field_130;
    int field_134;
    int field_138;
    int field_13c;
    int field_140;
    int field_144;
    int field_148;
    int field_14c;
    int field_150;
    int field_154;
    int field_158;
    int field_15c;
    int field_160;
    int field_164;
    int field_168;
    int field_16c;
    int field_170;
    int field_174;
    int field_178;
    int field_17c;
    int field_180;
    int field_184;
    int field_188;
    int field_18c;
    int field_190;
    int field_194;
    int field_198;
    int field_19c;
    int field_1a0;
    int field_1a4;
    int field_1a8;
    int field_1ac;
    int field_1b0;
    int field_1b4;
    int field_1b8;
    int field_1bc;
    int field_1c0;
    int field_1c4;
    int field_1c8;
    int field_1cc;
    int field_1d0;
    int field_1d4;
    int field_1d8;
    int field_1dc;
    int field_1e0;
    int field_1e4;
    int field_1e8;
    int field_1ec;
    int field_1f0;
    int field_1f4;
    int field_1f8;
    int field_1fc;
    int field_200;
    int field_204;
    int field_208;
    int field_20c;
    int field_210;
    int field_214;
    int field_218;
    int field_21c;
    int field_220;
    int field_224;
    int field_228;
    int field_22c;
    int field_230;
    int field_234;
    int field_238;
    int field_23c;
    int field_240;
    int field_244;
    int field_248;
    int field_24c;
    int field_250;
    int field_254;
    int field_258;
    int field_25c;
    int field_260;
    int field_264;
    int field_268;
    int field_26c;
    int field_270;
    int field_274;
    int field_278;
    int field_27c;
    int field_280;
    int field_284;
    int field_288;
    int field_28c;
    int field_290;
    int field_294;
    int field_298;
    int field_29c;
    int field_2a0;
    int field_2a4;
    int field_2a8;
    int field_2ac;
    int field_2b0;
    int field_2b4;
    int field_2b8;
    int field_2bc;
    int field_2c0;
    int field_2c4;
    int field_2c8;
    int field_2cc;
    int field_2d0;
    int field_2d4;
    int field_2d8;
    int field_2dc;
    int field_2e0;
    int field_2e4;
    int field_2e8;
    int field_2ec;
    int field_2f0;
    int field_2f4;
    int field_2f8;
    int field_2fc;
    int field_300;
    int field_304;
    int field_308;
    int field_30c;
    int field_310;
    int field_314;
    int field_318;
    int field_31c;
    int field_320;
    int field_324;
    int field_328;
    int field_32c;
    int field_330;
    int field_334;
    int field_338;
    int field_33c;
    int field_340;
    int field_344;
    int field_348;
    int field_34c;
    int field_350;
    int field_354;
    int field_358;
    int field_35c;
    int field_360;
    int field_364;
    int field_368;
    int field_36c;
    int field_370;
    int field_374;
    int field_378;
    int field_37c;
    int field_380;
    int field_384;
    int field_388;
    int field_38c;
    int field_390;
    int field_394;
    int field_398;
    int field_39c;
    int field_3a0;
    int field_3a4;
    int field_3a8;
    int field_3ac;
    int field_3b0;
    int field_3b4;
    int field_3b8;
    int field_3bc;
    int field_3c0;
    int field_3c4;
    int field_3c8;
    int field_3cc;
    int field_3d0;
    int field_3d4;
    int field_3d8;
    int field_3dc;
    int field_3e0;
    int field_3e4;
    int field_3e8;
    int field_3ec;
    int field_3f0;
    int field_3f4;
    int field_3f8;
    int field_3fc;
    int field_400;
    int field_404;
    int field_408;
    int field_40c;
    int field_410;
    int field_414;
    int field_418;
    int field_41c;
    int field_420;
    int field_424;
    int field_428;
    int field_42c;
    int field_430;
    int field_434;
    int field_438;
    int field_43c;
    int field_440;
    int field_444;
    int field_448;
    int field_44c;
    int field_450;
    int field_454;
    int field_458;
    int field_45c;
    int field_460;
    int field_464;
    int field_468;
    int field_46c;
    int field_470;
    int field_474;
    int field_478;
    int field_47c;
    int field_480;
    int field_484;
    int field_488;
    int field_48c;
    int field_490;
    int field_494;
    int field_498;
    int field_49c;
    int field_4a0;
    int field_4a4;
    int field_4a8;
    int field_4ac;
    int field_4b0;
    int field_4b4;
    int field_4b8;
    int field_4bc;
    int field_4c0;
    int field_4c4;
    int field_4c8;
    int field_4cc;
    int field_4d0;
    int field_4d4;
    int field_4d8;
    int field_4dc;
    int field_4e0;
    int field_4e4;
    int field_4e8;
    int field_4ec;
    int field_4f0;
    int field_4f4;
    int field_4f8;
    int field_4fc;
    int field_500;
    int field_504;
    int field_508;
    int field_50c;
    int field_510;
    int field_514;
    int field_518;
    int field_51c;
    int field_520;
    int field_524;
    int field_528;
    int field_52c;
    int field_530;
    int field_534;
    int field_538;
    int field_53c;
    int field_540;
    int field_544;
    int field_548;
    int field_54c;
    int field_550;
    int field_554;
    int field_558;
    int field_55c;
    int field_560;
    int field_564;
    int field_568;
    int field_56c;
    int field_570;
    int field_574;
    int field_578;
    int field_57c;
    int field_580;
    int field_584;
    int field_588;
    int field_58c;
    int field_590;
    int field_594;
    int field_598;
    int field_59c;
    int field_5a0;
    int field_5a4;
    int field_5a8;
    int field_5ac;
    int field_5b0;
    int field_5b4;
    int field_5b8;
    int field_5bc;
    int field_5c0;
    int field_5c4;
    int field_5c8;
    int field_5cc;
    int field_5d0;
    int field_5d4;
    int field_5d8;
    int field_5dc;
    int field_5e0;
    int field_5e4;
    int field_5e8;
    int field_5ec;
    int field_5f0;
    int field_5f4;
    int field_5f8;
    int field_5fc;
    int field_600;
    int field_604;
    int field_608;
    int field_60c;
    int field_610;
    int field_614;
    int field_618;
    int field_61c;
    int field_620;
    int field_624;
    int field_628;
    int field_62c;
    int field_630;
    int field_634;
    int field_638;
    int field_63c;
    int field_640;
    int field_644;
    int field_648;
    int field_64c;
    int field_650;
    int field_654;
    int field_658;
    int field_65c;
    int field_660;
    int field_664;
    int field_668;
    int field_66c;
    int field_670;
    int field_674;
    int field_678;
    int field_67c;
    int field_680;
    int field_684;
    int field_688;
    int field_68c;
    int field_690;
    int field_694;
    int field_698;
    int field_69c;
    int field_6a0;
    int field_6a4;
    int field_6a8;
    int field_6ac;
    int field_6b0;
    int field_6b4;
    int field_6b8;
    int field_6bc;
    int field_6c0;
    int field_6c4;
    int field_6c8;
    int field_6cc;
    int field_6d0;
    int field_6d4;
    int field_6d8;
    int field_6dc;
    int field_6e0;
    int field_6e4;
    int field_6e8;
    int field_6ec;
    int field_6f0;
    int field_6f4;
    int field_6f8;
    int field_6fc;
    int field_700;
    int field_704;
    int field_708;
    int field_70c;
    int field_710;
    int field_714;
    int field_718;
    int field_71c;
    int field_720;
    int field_724;
    int field_728;
    int field_72c;
    int field_730;
    int field_734;
    int field_738;
    int field_73c;
    int field_740;
    int field_744;
    int field_748;
    int field_74c;
    int field_750;
    int field_754;
    int field_758;
    int field_75c;
    int field_760;
    int field_764;
    int field_768;
    int field_76c;
    int field_770;
    int field_774;
    int field_778;
    int field_77c;
    int field_780;
    int field_784;
    int field_788;
    int field_78c;
    int field_790;
    int field_794;
    int field_798;
    int field_79c;
    int field_7a0;
    int field_7a4;
    int field_7a8;
    int field_7ac;
    int field_7b0;
    int field_7b4;
    int field_7b8;
    int field_7bc;
    int field_7c0;
    int field_7c4;
    int field_7c8;
    int field_7cc;
    int field_7d0;
    int field_7d4;
    int field_7d8;
    int field_7dc;
    int field_7e0;
    int field_7e4;
    int field_7e8;
    int field_7ec;
    int field_7f0;
    int field_7f4;
    int field_7f8;
    int field_7fc;
    int field_800;
    int field_804;
    int field_808;
    int field_80c;
    int field_810;
    int field_814;
    int field_818;
    int field_81c;
    int field_820;
    int field_824;
    int field_828;
    int field_82c;
    int field_830;
    int field_834;
    int field_838;
    int field_83c;
    int field_840;
    int field_844;
    int field_848;
    int field_84c;
    int field_850;
    int field_854;
    int field_858;
    int field_85c;
    int field_860;
    int field_864;
    int field_868;
    int field_86c;
    int field_870;
    int field_874;
    int field_878;
    int field_87c;
    int field_880;
    int field_884;
    int field_888;
    int field_88c;
    int field_890;
    int field_894;
    int field_898;
    int field_89c;
    int field_8a0;
    int field_8a4;
    int field_8a8;
    int field_8ac;
    int field_8b0;
    int field_8b4;
    int field_8b8;
    int field_8bc;
    int field_8c0;
    int field_8c4;
    int field_8c8;
    int field_8cc;
    int field_8d0;
    int field_8d4;
    int field_8d8;
    int field_8dc;
    int field_8e0;
    int field_8e4;
    int field_8e8;
    int field_8ec;
    int field_8f0;
    int field_8f4;
    int field_8f8;
    int field_8fc;
    int field_900;
    int field_904;
    int field_908;
    int field_90c;
    int field_910;
    int field_914;
    int field_918;
    int field_91c;
    int field_920;
    int field_924;
    int field_928;
    int field_92c;
    int field_930;
    int field_934;
    int field_938;
    int field_93c;
    int field_940;
    int field_944;
    int field_948;
    int field_94c;
    int field_950;
    int field_954;
    int field_958;
    int field_95c;
    int field_960;
    int field_964;
    int field_968;
    int field_96c;
    int field_970;
    int field_974;
    int field_978;
    int field_97c;
    RawMat view;
    RawMat projection;
    void NiDX9Renderer_SetModelTransform(void* p, int z);
};
struct ClipFull
{
    int pad_000;
    int pad_004;
    int pad_008;
    int pad_00c;
    int pad_010;
    int pad_014;
    int pad_018;
    int pad_01c;
    int pad_020;
    int pad_024;
    int pad_028;
    int pad_02c;
    int pad_030;
    int pad_034;
    int pad_038;
    int pad_03c;
    int pad_040;
    int pad_044;
    int pad_048;
    int pad_04c;
    int pad_050;
    int pad_054;
    int pad_058;
    int pad_05c;
    int pad_060;
    int pad_064;
    int pad_068;
    int pad_06c;
    int pad_070;
    int pad_074;
    int pad_078;
    int pad_07c;
    int pad_080;
    int pad_084;
    int pad_088;
    int pad_08c;
    int pad_090;
    int pad_094;
    int pad_098;
    int pad_09c;
    int pad_0a0;
    int pad_0a4;
    int pad_0a8;
    int pad_0ac;
    int pad_0b0;
    int pad_0b4;
    int pad_0b8;
    int pad_0bc;
    int pad_0c0;
    int pad_0c4;
    int pad_0c8;
    int pad_0cc;
    int pad_0d0;
    int pad_0d4;
    int pad_0d8;
    int pad_0dc;
    int pad_0e0;
    int pad_0e4;
    int pad_0e8;
    int pad_0ec;
    int pad_0f0;
    int pad_0f4;
    int pad_0f8;
    int pad_0fc;
    int pad_100;
    int pad_104;
    int pad_108;
    int pad_10c;
    int pad_110;
    int pad_114;
    int pad_118;
    int pad_11c;
    int pad_120;
    int pad_124;
    int pad_128;
    int pad_12c;
    int pad_130;
    int pad_134;
    int pad_138;
    int pad_13c;
    int pad_140;
    Plane planes[6];
    int pad2_000;
    Plane planes2[6];
    char flag208;
    void CopySourceData(Plane* p);
};
struct Cam
{
    void ShadowSceneNode_GetLightingOffset(NiPoint3* out);
};
struct Sink
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
    virtual void f24(void* t);
};
struct Geo
{
    int pad_000;
    int pad_004;
    int pad_008;
    int pad_00c;
    int pad_010;
    int pad_014;
    unsigned char flags;
};
struct Arg
{
    Geo* g0;
    int u4;
    int p8;
    struct P0c* pc;
    Geo* g10;
};
struct P0c
{
    int pad_000;
    int pad_004;
    int pad_008;
    int pad_00c;
    int pad_010;
    int pad_014;
    int pad_018;
    int pad_01c;
    int pad_020;
    int pad_024;
    int pad_028;
    int pad_02c;
    int pad_030;
    int pad_034;
    int pad_038;
    int pad_03c;
    int pad_040;
    int pad_044;
    int pad_048;
    int pad_04c;
    int pad_050;
    int pad_054;
    int pad_058;
    int pad_05c;
    int pad_060;
    int pad_064;
    int pad_068;
    int pad_06c;
    int pad_070;
    int pad_074;
    int pad_078;
    int pad_07c;
    int pad_080;
    int pad_084;
    int pad_088;
    int pad_08c;
    int pad_090;
    int pad_094;
    int pad_098;
    int pad_09c;
    int pad_0a0;
    int pad_0a4;
    int pad_0a8;
    int pad_0ac;
    int pad_0b0;
    int pad_0b4;
    int pad_0b8;
    int pad_0bc;
    int pad_0c0;
    int pad_0c4;
    int pad_0c8;
    int pad_0cc;
    int pad_0d0;
    int pad_0d4;
    int pad_0d8;
    int pad_0dc;
    int pad_0e0;
    int ie4;
    float fe8;
    float fec;
};
struct Obj
{
    int pad_000;
    int pad_004;
    int pad_008;
    int pad_00c;
    int pad_010;
    int pad_014;
    int pad_018;
    int pad_01c;
    const char* name;
    int pad2_000;
    int pad2_004;
    int pad2_008;
    int pad2_00c;
    int pad2_010;
    int pad2_014;
    int pad2_018;
    int pad2_01c;
    int pad2_020;
    int pad2_024;
    int pad2_028;
    int pad2_02c;
    int pad2_030;
    int pad2_034;
    int pad2_038;
    int pad2_03c;
    int pad2_040;
    int sub68_000;
    int sub68_004;
    int sub68_008;
    int sub68_00c;
    int sub68_010;
    int sub68_014;
    int sub68_018;
    int sub68_01c;
    int sub68_020;
    int sub68_024;
    int sub68_028;
    int sub68_02c;
    int sub68_030;
    int sub68_034;
    int sub68_038;
    int sub68_03c;
    int sub68_040;
    int sub68_044;
    int sub68_048;
    int sub68_04c;
    struct
    {
        int pad_000;
        int pad_004;
        int pad_008;
        int pad_00c;
        int pad_010;
        int pad_014;
        int pad_018;
        int pad_01c;
        int pad_020;
        int pad_024;
        int pad_028;
        int pad_02c;
        int pad_030;
        int v;
    }* b8;
    int bc;
};
struct GHold
{
    int pad_000;
    int pad_004;
    unsigned char b;
};
struct Flags164
{
    int pad_000;
    int pad_004;
    int pad_008;
    int pad_00c;
    int pad_010;
    int pad_014;
    int field_018;
    int pad_01c;
    int pad_020;
    int pad_024;
    int pad_028;
    int pad_02c;
    int pad_030;
    int pad_034;
    int pad_038;
    int pad_03c;
    int pad_040;
    int pad_044;
    int pad_048;
    int pad_04c;
    int pad_050;
    int pad_054;
    int pad_058;
    int pad_05c;
    int pad_060;
    int pad_064;
    int pad_068;
    int pad_06c;
    int pad_070;
    int pad_074;
    int pad_078;
    int pad_07c;
    int pad_080;
    int pad_084;
    int pad_088;
    int pad_08c;
    int pad_090;
    int pad_094;
    int pad_098;
    int pad_09c;
    int pad_0a0;
    int pad_0a4;
    int pad_0a8;
    int pad_0ac;
    int pad_0b0;
    int pad_0b4;
    int pad_0b8;
    int pad_0bc;
    int pad_0c0;
    int pad_0c4;
    int pad_0c8;
    int pad_0cc;
    int pad_0d0;
    int pad_0d4;
    int pad_0d8;
    int pad_0dc;
    int pad_0e0;
    int pad_0e4;
    int pad_0e8;
    int pad_0ec;
    int pad_0f0;
    int pad_0f4;
    int pad_0f8;
    int pad_0fc;
    int pad_100;
    int pad_104;
    int pad_108;
    int pad_10c;
    int pad_110;
    int pad_114;
    int pad_118;
    int pad_11c;
    int pad_120;
    int pad_124;
    int pad_128;
    int pad_12c;
    int pad_130;
    int pad_134;
    int pad_138;
    int pad_13c;
    int pad_140;
    int pad_144;
    int pad_148;
    int pad_14c;
    int pad_150;
    int pad_154;
    int pad_158;
    int pad_15c;
    int pad_160;
    char a;
    char b;
};
struct Lst;
struct Glob
{
    int pad_000;
    int pad_004;
    int pad_008;
    int pad_00c;
    int pad_010;
    int pad_014;
    int pad_018;
    int pad_01c;
    int pad_020;
    int pad_024;
    int pad_028;
    int pad_02c;
    int pad_030;
    Lst* l34;
    int u38;
    int u3c;
    int u40;
    int h44;
    Lst* l48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int h5c;
};
struct Lst
{
    virtual void w00();
    virtual void w01();
    virtual void w02();
    virtual void w03();
    virtual void w04();
    virtual void w05();
    virtual void w06();
    virtual void w07();
    virtual void w08();
    virtual void w09();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void vfn(int h, Obj* o, int b, int z, int a, Arg* arg, int z2, void* sub, const char* n2, int z3, int one);
};
struct Root
{
    Obj* obj;
    int u4;
    int u8;
    ClipFull** clip;
};

extern Root* DAT_011f91e0;
extern int DAT_011f91e4;
extern char DAT_011f4288[];
extern GHold* DAT_012010ac;
extern GHold* DAT_012010dc;
extern float DAT_011f940c;
extern float DAT_01201350;
extern float DAT_01201ba0;
extern float DAT_01201ba4;
extern Glob* DAT_0126f74c;
extern Cam* DAT_011f91c8;
struct PlaneTarget;
struct PlaneTargetHolder
{
    int field_000;
    int field_004;
    int field_008;
    int field_00c;
    int field_010;
    int field_014;
    int field_018;
    int field_01c;
    int field_020;
    int field_024;
    int field_028;
    int field_02c;
    int field_030;
    int field_034;
    int field_038;
    int field_03c;
    int field_040;
    int field_044;
    int field_048;
    int field_04c;
    int field_050;
    int field_054;
    int field_058;
    int field_05c;
    int field_060;
    int field_064;
    int field_068;
    int field_06c;
    int field_070;
    int field_074;
    int field_078;
    int field_07c;
    int field_080;
    int field_084;
    int field_088;
    int field_08c;
    int field_090;
    int field_094;
    int field_098;
    int field_09c;
    int field_0a0;
    int field_0a4;
    int field_0a8;
    int field_0ac;
    int field_0b0;
    int field_0b4;
    int field_0b8;
    int field_0bc;
    int field_0c0;
    int field_0c4;
    int field_0c8;
    int field_0cc;
    int field_0d0;
    int field_0d4;
    int field_0d8;
    int field_0dc;
    int field_0e0;
    int field_0e4;
    int field_0e8;
    int field_0ec;
    int field_0f0;
    int field_0f4;
    int field_0f8;
    int field_0fc;
    int field_100;
    int field_104;
    int field_108;
    int field_10c;
    int field_110;
    int field_114;
    int field_118;
    int field_11c;
    int field_120;
    int field_124;
    int field_128;
    int field_12c;
    int field_130;
    int field_134;
    int field_138;
    int field_13c;
    int field_140;
    int field_144;
    int field_148;
    int field_14c;
    int field_150;
    int field_154;
    int field_158;
    int field_15c;
    int field_160;
    int field_164;
    int field_168;
    int field_16c;
    int field_170;
    int field_174;
    int field_178;
    int field_17c;
    int field_180;
    int field_184;
    int field_188;
    int field_18c;
    int field_190;
    int field_194;
    int field_198;
    int field_19c;
    int field_1a0;
    int field_1a4;
    int field_1a8;
    int field_1ac;
    int field_1b0;
    int field_1b4;
    int field_1b8;
    int field_1bc;
    int field_1c0;
    int field_1c4;
    int field_1c8;
    int field_1cc;
    int field_1d0;
    int field_1d4;
    int field_1d8;
    int field_1dc;
    int field_1e0;
    int field_1e4;
    int field_1e8;
    int field_1ec;
    int field_1f0;
    int field_1f4;
    int field_1f8;
    int field_1fc;
    int field_200;
    int field_204;
    int field_208;
    int field_20c;
    int field_210;
    int field_214;
    int field_218;
    int field_21c;
    int field_220;
    int field_224;
    int field_228;
    int field_22c;
    int field_230;
    int field_234;
    int field_238;
    int field_23c;
    int field_240;
    int field_244;
    int field_248;
    int field_24c;
    int field_250;
    int field_254;
    int field_258;
    int field_25c;
    int field_260;
    int field_264;
    int field_268;
    int field_26c;
    int field_270;
    int field_274;
    int field_278;
    int field_27c;
    int field_280;
    int field_284;
    PlaneTarget* target;
};
extern PlaneTargetHolder* DAT_011f4748;
extern float DAT_011f474c, DAT_011f4750, DAT_011f4754;

void BSRenderState_SetZWriteEnable(int, int);
void BSUtilities_GetInverseWorldMatrix(void* sub, int b, Mat* m);
Flags164* BSShaderManager_GetAccumulator();
Mat* __stdcall D3DXMatrixMultiply_00ee6de0(Mat* o, Mat* a, Mat* b);
Mat* __stdcall D3DXMatrixInverse_00ee6dda(Mat* o, float* det, Mat* a);
Mat* __stdcall D3DXMatrixTranspose_00ee6dd4(Mat* o, Mat* a);
Plane* __stdcall D3DXPlaneNormalize_00ee6dce(Plane* o, Plane* a);
Plane* __stdcall D3DXPlaneTransform_00ee6dc8(Plane* o, Plane* a, Mat* m);
void __stdcall Lighting30Shader_SetupGeometryConstants_Envmap(P0c* p);

struct PlaneTarget
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s0a();
    virtual void s0b();
    virtual void s0c();
    virtual void s0d();
    virtual void s0e();
    virtual void s0f();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s1a();
    virtual void s1b();
    virtual void s1c();
    virtual void s1d();
    virtual void s1e();
    virtual void s1f();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s2a();
    virtual void s2b();
    virtual void s2c();
    virtual void s2d();
    virtual void s2e();
    virtual void s2f();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void __stdcall SetWaterColorParameter(int i, Plane* p);
};

struct Shadow
{
    int pad_000;
    int pad_004;
    int pad_008;
    int pad_00c;
    int pad_010;
    int pad_014;
    Renderer* r18;
    Sink* s1c;
    int pad2_000;
    int pad2_004;
    int pad2_008;
    int pad2_00c;
    int e30;
    int e34;
    void SetupTextureStages(P0c* p, Glob* g);
    void ApplyTextureStages(P0c* p, Glob* g);
    void Lighting30Shader_UpdateTexEffectConstants(Obj* o, P0c* p, Glob* g);
    void Lighting30Shader_SetupGeometryConstants_Lights(P0c* p, Root* r, int mode, int p8, Mat* m, int b, void* sub);
    void Lighting30Shader_SetupGeometryConstants_ObjToCubemap(Root* r, int mode, int b, void* sub);
    void UpdateShaderMatrices(int b, void* sub);
    void UpdatePositionOffset(const char* n);
    void UpdateTransformedPosition(Mat m, void* sub);
    void Lighting30Shader_SetupGeometryConstants_HairTint(P0c* p);
    void Lighting30Shader_SetupGeometryConstants_MaterialAlpha(const char* n, P0c* p, Arg* a, int mode);
    void ApplyLightSource(int p8, P0c* p);
    void Lighting30Shader_SetupGeometryConstants_RefractionPower(P0c* p);
    void UpdateFogPlanes();
    Renderer* GetRenderer() const
    {
        return r18;
    }
    void Lighting30Shader_SetupGeometryConstants(Arg* arg);
    Shadow* UpdateFrustum(ClipFull* clip, Plane* src, Shadow* volatile& owner);
};

static __forceinline Renderer* SetProjectionTranslation(Shadow& object, double value, float& out)
{
    Renderer* r = object.GetRenderer();
    out = (float)value;
    return r;
}

__forceinline Shadow* Shadow::UpdateFrustum(ClipFull* clip, Plane* src, Shadow* volatile& owner)
{
    Scratch one, two;
    Shadow& current = *owner;
    Mat view = current.GetRenderer()->view;
    NiPoint3 cam;
    DAT_011f91c8->ShadowSceneNode_GetLightingOffset(&cam);
    Renderer* projectionRenderer;
    float px, py, pz;
    {
        NiPoint3& pos = *(NiPoint3*)one.vector;
        NiPoint3& col = *(NiPoint3*)two.vector;
        col.x = view.m[0][0];
        col.y = view.m[1][0];
        col.z = view.m[2][0];
        px = cam.x + DAT_011f474c;
        pos.x = px;
        py = cam.y + DAT_011f4750;
        pos.y = py;
        pz = cam.z + DAT_011f4754;
        pos.z = pz;
        view.m[3][0] = -pos.DotProduct(col);
    }
    {
        NiPoint3& pos = *(NiPoint3*)two.vector;
        NiPoint3& col = *(NiPoint3*)one.vector;
        col.x = view.m[0][1];
        col.y = view.m[1][1];
        col.z = view.m[2][1];
        pos.x = px;
        pos.y = py;
        pos.z = pz;
        view.m[3][1] = -pos.DotProduct(col);
    }
    {
        NiPoint3& pos = *(NiPoint3*)two.vector;
        NiPoint3& col = *(NiPoint3*)one.vector;
        col.x = view.m[0][2];
        col.y = view.m[1][2];
        col.z = view.m[2][2];
        pos.x = px;
        pos.y = py;
        pos.z = pz;
        projectionRenderer = SetProjectionTranslation(*owner, -pos.DotProduct(col), view.m[3][2]);
    }
    Mat proj = projectionRenderer->projection;
    MatA vp, inv;
    D3DXMatrixMultiply_00ee6de0(&vp, &view, &proj);
    D3DXMatrixInverse_00ee6dda(&inv, 0, &vp);
    D3DXMatrixTranspose_00ee6dd4(&vp, &inv);
    Plane out[6];
    for (int i = 0; i < 6; i++)
    {
        memcpy(&cam, &src[i], sizeof(cam));
        Plane& p = one.plane;
        Plane& t = two.plane;
        p.a = cam.x;
        p.b = cam.y;
        p.c = cam.z;
        p.d = -src[i].d;
        D3DXPlaneNormalize_00ee6dce(&p, &p);
        D3DXPlaneTransform_00ee6dc8(&t, &p, &vp);
        out[i].a = t.a;
        out[i].b = t.b;
        out[i].c = t.c;
        out[i].d = t.d;
    }
    int i = 0;
    PlaneTarget** pt = &DAT_011f4748->target;
    for (; i < 6; i++)
        (*pt)->SetWaterColorParameter(i, &out[i]);
    clip->CopySourceData(out);
    return owner;
}

// Updates shadow rendering state, applies texture stages and matrices, updates frustum planes, and dispatches callbacks based on mode and flags.
// @fnv 0x00bbef90
// src: XBOX_PDB 0x00bbef90
void Shadow::Lighting30Shader_SetupGeometryConstants(Arg* apArgs)
{
    Shadow* pShadow = this;
    Shadow* volatile pShadowVolatile = this;
    unsigned mode = DAT_011f91e4;
    Root* root = DAT_011f91e0;
    Obj* obj = root->obj;
    void* sub = &obj->sub68_000;
    const char* name = obj->name;
    if (!name)
        name = DAT_011f4288;
    int a = obj->b8->v;
    int b = obj->bc;
    P0c* pc = apArgs->pc;
    int p8 = apArgs->p8;
    Mat mat;
    if ((unsigned)(mode - 0x1d3) <= 3 && (apArgs->g0->flags & 1))
        BSRenderState_SetZWriteEnable(0, 1);
    BSUtilities_GetInverseWorldMatrix(sub, b, &mat);
    r18->NiDX9Renderer_SetModelTransform(sub, 0);
    if (mode == 0x1e0 || mode == 0x1e1)
    {
        ApplyTextureStages(pc, DAT_0126f74c);
        Lighting30Shader_UpdateTexEffectConstants(obj, pc, DAT_0126f74c);
        UpdateTransformedPosition(mat, sub);
    }
    else
    {
        if (mode == 0xe || mode == 0xf)
            SetupTextureStages(pc, DAT_0126f74c);
        Lighting30Shader_SetupGeometryConstants_Lights(pc, root, mode, p8, &mat, b, sub);
        Lighting30Shader_SetupGeometryConstants_ObjToCubemap(root, mode, b, sub);
        UpdateShaderMatrices(b, sub);
        if (DAT_012010ac->b)
            DAT_01201350 = (float)(DAT_011f940c / 3600.0 * 6.283180236816406 * pc->ie4);
        UpdatePositionOffset(name);
        UpdateTransformedPosition(mat, sub);
        Lighting30Shader_SetupGeometryConstants_HairTint(pc);
        Lighting30Shader_SetupGeometryConstants_MaterialAlpha(name, pc, apArgs, mode);
        ApplyLightSource(p8, pc);
        Lighting30Shader_SetupGeometryConstants_RefractionPower(pc);
        if (DAT_012010dc->b)
        {
            DAT_01201ba0 = pc->fe8;
            DAT_01201ba4 = pc->fec;
        }
        Lighting30Shader_SetupGeometryConstants_Envmap(pc);
        UpdateFogPlanes();
        if ((unsigned)(mode - 0x1c4) <= 3)
        {
            ClipFull* clip = *DAT_011f91e0->clip;
            if (!clip->flag208 && !BSShaderManager_GetAccumulator()->a && !BSShaderManager_GetAccumulator()->b)
            {
                pShadow = UpdateFrustum(clip, clip->planes, pShadowVolatile);
            }
            else if (!BSShaderManager_GetAccumulator()->a && !BSShaderManager_GetAccumulator()->b)
            {
                Plane(&planes)[6] = clip->planes2;
                int i = 0;
                PlaneTarget** pt = &DAT_011f4748->target;
                for (; i < 6; ++i)
                    (*pt)->SetWaterColorParameter(i, &planes[i]);
            }
        }
    }
    if (pShadow->e30 && DAT_0126f74c->h44)
        DAT_0126f74c->l34->vfn(DAT_0126f74c->h44, obj, b, 0, a, apArgs, 0, sub, name, 0, 1);
    if (pShadow->e34 && DAT_0126f74c->h5c)
        DAT_0126f74c->l48->vfn(DAT_0126f74c->h5c, obj, b, 0, a, apArgs, 0, sub, name, 0, 1);
    Geo* t = apArgs->g10;
    if (t && (t->flags & 1))
        pShadow->s1c->f24(t);
}
}  // namespace fnv_00bbef90

#include <math.h>
namespace fnv_00bbe9c0 {
class SolPosition : public NiMemObject
{
  public:
    float x, y, z;
    inline SolPosition()
    {}
    inline SolPosition(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
// src: GUESS 0x00439ef0 (confidence: high)
    inline SolPosition SubtractIntoVector(const SolPosition& rhs) const
    {
        return SolPosition(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    inline float FUN_00457990() const;
};
class SolColor : public NiMemObject
{
  public:
    float r, g, b;
    inline SolColor(float a = 0.f, float green = 0.f, float blue = 0.f)
    {
        r = a;
        g = green;
        b = blue;
    }
    inline SolColor ScaleTo(float factor) const
    {
        SolColor v = *this;
        v.r *= factor;
        v.g *= factor;
        v.b *= factor;
        return v;
    }
    float ComputeWeightedSum() const;
};
extern "C" double __cdecl sqrt(double);
inline float SolPosition::FUN_00457990() const
{
    return (float)sqrt(x * x + y * y + z * z);
}
struct S00bbe9c0_Coef
{
    float ambient, diffuse, specular, emissive;
};
extern S00bbe9c0_Coef DAT_011a9be0, DAT_01201b60;
extern int DAT_011f91b8;
extern char* DAT_011f91c8;
extern double DAT_0101e568;
extern char* DAT_012010d0;
extern bool DAT_01200bf5;
struct S00bbe9c0_Flags
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned short flags;
    unsigned char strength, other;
};

struct S00bbe9c0_AV
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88;
    SolPosition pos8c;
    int unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    float radC4;
    int unkc8, unkcc, unkd0;
    SolColor posD4;
};
struct S00bbe9c0_Target : S00bbe9c0_AV
{
    float fE0;
};
struct S00bbe9c0_Node
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4;
    S00bbe9c0_Target* target;
};
struct S00bbe9c0_Holder
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    S00bbe9c0_Node* listE0;
};
struct S00bbe9c0_Obj;
struct S00bbe9c0_VT
{
    void* vf000;
    void* vf004;
    void* vf008;
    void* vf00c;
    void* vf010;
    void* vf014;
    void* vf018;
    void* vf01c;
    void* vf020;
    void* vf024;
    void* vf028;
    void* vf02c;
    void* vf030;
    void* vf034;
    void* vf038;
    void* vf03c;
    void* vf040;
    void* vf044;
    void* vf048;
    void* vf04c;
    void* vf050;
    void* vf054;
    void* vf058;
    void* vf05c;
    void* vf060;
    void* vf064;
    void* vf068;
    void* vf06c;
    void* vf070;
    void* vf074;
    void* vf078;
    void* vf07c;
    void* vf080;
    void* vf084;
    void* vf088;
    void* vf08c;
    void* vf090;
    void* vf094;
    void* vf098;
    void* vf09c;
    void* vf0a0;
    void* vf0a4;
    void* vf0a8;
    void* vf0ac;
    void* vf0b0;
    void* vf0b4;
    void* vf0b8;
    void* vf0bc;
    void* vf0c0;
    void* vf0c4;
    void* vf0c8;
    void* vf0cc;
    void* vf0d0;
    void* vf0d4;
    void* vf0d8;
    void* vf0dc;
    void* vf0e0;
    void* vf0e4;
    void* vf0e8;
    void* vf0ec;
    void* vf0f0;
    void* vf0f4;
    void* vf0f8;
    void* vf0fc;
    void* vf100;
    void* vf104;
    void* vf108;
    void* vf10c;
    float(__thiscall* GetActorValueModifierAmount)(S00bbe9c0_Obj*);
};
struct S00bbe9c0_Obj
{
    S00bbe9c0_VT* vtable;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int flags;
    float opacity;
    bool FUN_004a2020(int mode);
    S00bbe9c0_Node* BSShaderLightingProperty_GetFirstActiveNonShadowLight(int* selected);
};
double BSMAX_0068b050(double, float);
double __hkMinD(double, double);
extern double DAT_010ae8b8, DAT_010ae8c0, DAT_010ae8b0;
__declspec(noinline) float SolColor::ComputeWeightedSum() const
{
    return (float)(r * DAT_010ae8b8 + g * DAT_010ae8c0 + b * DAT_010ae8b0);
}
// Computes ambient, diffuse, specular and emissive coefficients into DAT_01201b60 from lighting, state and render mode, and updates the dim flag.
// @fnv 0x00bbe9c0
// src: XBOX_PDB 0x00bbe9c0
void __stdcall Lighting30Shader_SetupGeometryConstants_MaterialAlpha(const SolPosition* original, S00bbe9c0_Obj* lighting, S00bbe9c0_Flags** state,
                            unsigned int renderMode)
{
    DAT_01201b60 = DAT_011a9be0;
    if (DAT_011f91b8 == 8)
    {
        DAT_01201b60.ambient = ((lighting->flags & 0x20000u) > 0u) ? 0.0f : 1.0f;
        S00bbe9c0_Flags* s = *state;
        if (s && (((*(unsigned char*)&s->flags) & 1u) || ((((unsigned char)(s->flags >> 9)) & 1u) != 0)))
        {
            DAT_01201b60.diffuse = 0.0f;
        }
        else
        {
            DAT_01201b60.diffuse = 1.0f;
        }
        return;
    }
    if (DAT_011f91b8 == 10 || renderMode - 0x1bd > 6)
    {
        DAT_01201b60.ambient = lighting->opacity < 1.0f ? lighting->opacity : 1.0f;
    }
    else
    {
        float modifier = lighting->vtable->GetActorValueModifierAmount(lighting);
        float illumination = lighting->opacity * modifier;
        DAT_01201b60.ambient = illumination < 1.0f ? illumination : 1.0f;
        if (((lighting->flags & 0x8000u) > 0u) && !lighting->FUN_004a2020(0x11))
        {
            renderMode = 0;
            illumination = 0.0f;
            S00bbe9c0_Node* node = lighting->BSShaderLightingProperty_GetFirstActiveNonShadowLight((int*)&renderMode);
            S00bbe9c0_Target* __restrict cam = ((S00bbe9c0_Holder*)DAT_011f91c8)->listE0->target;
            float alpha;
            {
                SolColor sun = cam->posD4;
                alpha = sun.ComputeWeightedSum();
            }
            if (node)
            {
                S00bbe9c0_Target* t = node->target;
                SolPosition relative = t->pos8c.SubtractIntoVector(*original);
                SolColor scaledColor = node->target->posD4.ScaleTo(node->target->radC4);
                float distance = relative.FUN_00457990() / t->fE0;
                double d = BSMAX_0068b050(0.0, distance);
                float vfade = 1.0f - (float)__hkMinD(1.0, d);
                float fade = (float)((double)vfade * 1.0);
                illumination = scaledColor.ComputeWeightedSum() * fade;
            }
            DAT_01201b60.ambient *= (illumination > alpha ? illumination : alpha);
        }
    }
    S00bbe9c0_Flags* s = *state;
    if (!(((unsigned char)(s->flags >> 9)) & 1))
    {
        DAT_01201b60.diffuse = 0.0f;
    }
    else
    {
        DAT_01201b60.diffuse = (float)(s->strength / DAT_0101e568);
    }
    DAT_01201b60.specular = 0.0f;
    DAT_01201b60.emissive = 0.0f;
    unsigned int mode = (s->flags >> 5) & 0xf;
    if (mode == 0)
    {
        DAT_01201b60.specular = 1.0f;
    }
    else if (mode == 2)
    {
        DAT_01201b60.emissive = 1.0f;
    }
    bool previouslyDim = DAT_01200bf5;
    bool dim = DAT_01201b60.ambient < 1.0f;
    DAT_01200bf5 = dim;
    DAT_012010d0[8] = (previouslyDim || dim);
}
}  // namespace fnv_00bbe9c0

template <class T> NiPointer<T>::~NiPointer()
{
    T* pkNew = *(T* volatile*)&m_pObject;
    if (pkNew && !InterlockedDecrement((volatile long*)&pkNew->m_uiRefCount))
        pkNew->DeleteThis();
}
template <class T> void ReleaseShaderPointer(NiPointer<T>& p)
{
    T* object = p.m_pObject;
    if (object)
    {
        if (!InterlockedDecrement((volatile long*)&object->m_uiRefCount))
            object->DeleteThis();
        p.m_pObject = 0;
    }
}
struct ShaderStateReference
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, refs;
    void FUN_00e80190();
};
extern NiPointer<NiRefObject> DAT_01200dd8[57];
__if_not_exists(BSPixelShader)
{
    class BSPixelShader
    {
      public:
        virtual ~BSPixelShader();
        virtual void DeleteThis();
        long m_lRefCount;
    };
}
__if_not_exists(BSPixelShaderPtr)
{
    class BSPixelShaderPtr
    {
      public:
        BSPixelShader* m_pObject;
    };
}
inline void ReleaseShaderPointer(BSPixelShaderPtr& p)
{
    BSPixelShader* object = p.m_pObject;
    if (object)
    {
        if (!InterlockedDecrement(&object->m_lRefCount))
            object->DeleteThis();
        p.m_pObject = 0;
    }
}
extern BSPixelShaderPtr DAT_01200c48[50];
extern BSPixelShaderPtr DAT_01200d10[24];
extern ShaderStateReference* shaderStates[112];
extern NiPointer<NiRefObject> shaderResources[17];
extern NiPointer<NiRefObject> shaderSettings[10];
extern Lighting30Packet4 shaderConstants[164];
extern Lighting30Packet4 extraConstants[63];
struct FUN_00bbc9c0 : BSShader
{
    NiPointer<NiD3DShaderConstantMap> m_spFillColorConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spFogConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spFirstPassConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spSecondPassConstantMap;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration1;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration2;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration3;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration4;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration5;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration6;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration7;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration8;
    NiGeometryBufferData* volatile m_pGeometryBufferData;
    UInt32 m_uiShaderOptions;
    virtual ~FUN_00bbc9c0();
};
// Releases shader pointers, states, resources, settings, and vertex declarations, resets constant arrays, and clears the geometry buffer pointer.
// @fnv 0x00bbc9c0
FUN_00bbc9c0::~FUN_00bbc9c0()
{
    for (int i = 0; i < 57; ++i)
        ReleaseShaderPointer(DAT_01200dd8[i]);
    for (int i = 0; i < 50; ++i)
    {
        ReleaseShaderPointer(DAT_01200c48[i]);
        ReleaseShaderPointer(DAT_01200d10[i]);
    }
    for (int i = 0; i < 112; ++i)
    {
        ShaderStateReference* state = shaderStates[i];
        if (state)
        {
            if (!--state->refs)
                state->FUN_00e80190();
            shaderStates[i] = 0;
        }
    }
    for (int i = 0; i < 17; ++i)
        ReleaseShaderPointer(shaderResources[i]);
    for (int i = 0; i < 10; ++i)
        ReleaseShaderPointer(shaderSettings[i]);
    shaderConstants[0] = DAT_011a9bd0;
    memcpy(shaderConstants + 1, shaderConstants, 163 * sizeof(Lighting30Packet4));
    extraConstants[0] = DAT_011a9bd0;
    memcpy(extraConstants + 1, extraConstants, 62 * sizeof(Lighting30Packet4));
    ReleaseShaderPointer(m_spShaderDecl);
    ReleaseShaderPointer(m_pVertexDeclaration1);
    ReleaseShaderPointer(m_pVertexDeclaration2);
    ReleaseShaderPointer(m_pVertexDeclaration3);
    ReleaseShaderPointer(m_pVertexDeclaration4);
    ReleaseShaderPointer(m_pVertexDeclaration5);
    ReleaseShaderPointer(m_pVertexDeclaration6);
    ReleaseShaderPointer(m_pVertexDeclaration7);
    ReleaseShaderPointer(m_pVertexDeclaration8);
    m_pGeometryBufferData = 0;
}
