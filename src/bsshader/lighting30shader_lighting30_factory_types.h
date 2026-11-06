// Unit-private C++03 declaration closure. No authored helper bodies.
// PC layout and ordered virtual declarations: see NOTES and community_virtual_declarations.json.
#ifndef LIGHTING30_FACTORY_TYPES_H
#define LIGHTING30_FACTORY_TYPES_H

#include <stddef.h>
#include "../../include/NiPoint4.h"
#include "../../include/BSShader.h"
#include "../../include/BSShaderManager.h"
#include "../../include/NiAlphaProperty.h"
#include "../../include/NiD3DDefaultShader.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiD3DShaderDeclaration.h"
#include "../../include/NiD3DShaderInterface.h"
#include "../../include/NiObject.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiShader.h"
#include "../../include/NiShaderDeclaration.h"
#include "../../include/NiSkinPartition.h"
#include "../../include/NiColorA.h"
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
class NiD3DPass;
class NiD3DShaderConstantMap;
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
#endif
