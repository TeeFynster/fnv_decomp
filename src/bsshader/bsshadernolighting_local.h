// Local unit header for bsshader/bsshadernolighting.cpp.
#ifndef FNV_BSSHADERNOLIGHTING_LOCAL_H
#define FNV_BSSHADERNOLIGHTING_LOCAL_H

#include <stddef.h>
#include "NiMemObject.h"
#include "NiObject.h"
#include "NiProperty.h"
#include "NiFixedString.h"
#include "NiRefObject.h"
#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/NiPointer.h"

class NiD3DPass;
template <> inline NiPointer<NiD3DPass>::~NiPointer();

#define FNV_NOLIGHTING_ASSERT_JOIN_(a, b) a##b
#define FNV_NOLIGHTING_ASSERT_JOIN(a, b) FNV_NOLIGHTING_ASSERT_JOIN_(a, b)
#define FNV_NOLIGHTING_ASSERT(condition) typedef char FNV_NOLIGHTING_ASSERT_JOIN(nolighting_assert_, __LINE__)[(condition) ? 1 : -1]

#include "../../include/BSShader.h"
#include "../../include/BSShaderNoLightingProperty.h"
#include "../../include/NiAlphaProperty.h"
#include "../../include/NiBound.h"
#include "../../include/NiD3DDefaultShader.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiD3DShaderDeclaration.h"
#include "../../include/NiD3DShaderInterface.h"
#include "../../include/NiD3DVertexShader.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiGeometryData.h"
#include "../../include/NiPropertyState.h"
#include "../../include/NiShadeProperty.h"
#include "../../include/NiShader.h"
#include "../../include/NiShaderDeclaration.h"
#include "../../include/NiTransform.h"
#include "../../include/NiColorA.h"

class NiRenderer;
extern NiRenderer* DAT_011f9508;
class NiMaterialProperty;
#include "../../include/_D3DXMACRO.h"

struct BSNoLightingShaderConfig
{
    const char* path;
    _D3DXMACRO macros[9];
};
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
template <class T> inline void AssignShader(NiPointer<T>& dest, T* value)
{
    if (dest.m_pObject != value)
    {
        if (dest.m_pObject)
            dest.m_pObject->DecRefCount();
        dest.m_pObject = value;
        if (value)
            value->IncRefCount();
    }
}
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NICONSOLESHADERDECLARATION_H
#define FNV_NICONSOLESHADERDECLARATION_H
#include <stddef.h>
#include "NiObject.h"
class COMUnknownInterface;
class GraphicsRenderer;
class NiD3DVertexDeclaration;
class _D3DVERTEXELEMENT9;
#pragma pack(push, 4)
class NiD3DVertexDeclaration : public NiD3DShaderDeclaration
{
  public:
    static NiD3DVertexDeclaration* Create(NiRenderer*, unsigned int, unsigned int);
    // base NiD3DShaderDeclaration at +0x0, size 44
    _D3DVERTEXELEMENT9* m_pkVertexElements;         // +0x2C, 4 bytes
    COMUnknownInterface* m_pkD3DVertexDeclaration;  // +0x30, 4 bytes
    // void __cdecl NiD3DVertexDeclaration::*()
    // NiD3DVertexDeclaration* __cdecl NiD3DVertexDeclaration::*(NiRenderer*, unsigned int, unsigned int)
    // SetEntry
    // bool __cdecl NiD3DVertexDeclaration::*(unsigned int, unsigned int)
    // bool __cdecl NiD3DVertexDeclaration::*(unsigned int)
    // unsigned int __cdecl NiD3DVertexDeclaration::*()
    // NiVBChip* __cdecl NiD3DVertexDeclaration::*(NiGeometryData*, NiSkinInstance*, NiSkinPartition::Partition*, unsigned short, NiVBChip*, unsigned int, void*)
    // bool __cdecl NiD3DVertexDeclaration::*(COMUnknownInterface*&, unsigned int&)
    // unsigned int __cdecl NiD3DVertexDeclaration::*(unsigned int)
    // COMUnknownInterface* __cdecl NiD3DVertexDeclaration::*()
    // bool __cdecl NiD3DVertexDeclaration::*(_D3DDECLUSAGE, unsigned int, NiShaderDeclaration::ShaderParameter&, NiShaderDeclaration::ShaderParameterType&, NiShaderDeclaration::ShaderParameterUsage&, NiD3DShaderDeclaration::ShaderParameterTesselator&)
    // NiD3DVertexDeclaration
    // NiD3DVertexDeclaration& __cdecl NiD3DVertexDeclaration::*(const NiD3DVertexDeclaration&)
    // void __cdecl NiD3DVertexDeclaration::*()
};
#pragma pack(pop)
FNV_NOLIGHTING_ASSERT(sizeof(NiD3DVertexDeclaration) == 52);
FNV_NOLIGHTING_ASSERT(offsetof(NiD3DVertexDeclaration, m_pkVertexElements) == 44);
FNV_NOLIGHTING_ASSERT(offsetof(NiD3DVertexDeclaration, m_pkD3DVertexDeclaration) == 48);
#endif

// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSSHADERNOLIGHTING_H
#define FNV_BSSHADERNOLIGHTING_H
#include <stddef.h>
#include "NiFixedString.h"
#include "NiRefObject.h"
#include <stddef.h>
class BSShaderNoLighting;
class ShaderPassRenderer;
class GraphicsRenderer;
class NiD3DVertexDeclaration;
#pragma pack(push, 4)
class BSShaderNoLighting : public BSShader
{
  public:
    NiPointer<NiD3DPass> spRenderPass[30];                             // +0x6C, 120 bytes
    NiPointer<NiD3DVertexShader> m_spTreeVertexShader[28];             // +0xE4, 112 bytes
    NiPointer<NiD3DPixelShader> m_spPixelShaderVariants[7];            // +0x154, 28 bytes
    NiShaderConstantMapEntry* m_pFirstShaderConstantMapEntry;          // +0x170, 4 bytes
    NiShaderConstantMapEntry* m_pSecondShaderConstantMapEntry;         // +0x174, 4 bytes
    NiShaderConstantMapEntry* m_pShaderConstantMapEntry3;              // +0x178, 4 bytes
    NiShaderConstantMapEntry* m_pShaderConstantMapEntry4;              // +0x17C, 4 bytes
    NiShaderConstantMapEntry* m_pShaderConstantMapEntry5;              // +0x180, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant1;   // +0x184, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_spVertexDeclaration;           // +0x188, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant3;   // +0x18C, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant4;   // +0x190, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant5;   // +0x194, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant6;   // +0x198, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant7;   // +0x19C, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant8;   // +0x1A0, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant9;   // +0x1A4, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant10;  // +0x1A8, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant11;  // +0x1AC, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant12;  // +0x1B0, 4 bytes
    BSShaderNoLighting(NiD3DVertexDeclaration* d0, NiD3DVertexDeclaration* d1, NiD3DVertexDeclaration* d2,
                       NiD3DVertexDeclaration* d3, NiD3DVertexDeclaration* d4, NiD3DVertexDeclaration* d5,
                       NiD3DVertexDeclaration* d6, NiD3DVertexDeclaration* d7, NiD3DVertexDeclaration* d8,
                       NiD3DVertexDeclaration* d9, NiD3DVertexDeclaration* d10, NiD3DVertexDeclaration* d11);
    ~BSShaderNoLighting();
    static BSShader* CreateShader();
    void BSShaderNoLighting_LoadStagesAndPasses();
    void PrepareShaderPass(const NiPropertyState*);
    void CopyEntriesToGlobalBuffer(NiGeometry*, const NiTransform&);
    void UpdateGlobalMatrix(const NiPropertyState*);
    void BSShaderNoLighting_SetupGeometryConstants_WaterFog();
    void UpdateMaterialColor(BSShaderNoLightingProperty*, NiMaterialProperty*);
    void InitializeShaderData();
    NiD3DShaderDeclaration* SelectVertexDeclaration(NiGeometry* pkGeometry, BSShaderProperty* pkShaderProperty);
    // const NiRTTI* __cdecl BSShaderNoLighting::*()
    // BSShaderNoLighting
    // void __cdecl BSShaderNoLighting::*()
    // unsigned int __cdecl BSShaderNoLighting::*(NiGeometry*, const NiSkinInstance*, const NiSkinPartition::Partition*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // void __cdecl BSShaderNoLighting::*(unsigned int)
    // void __cdecl BSShaderNoLighting::*(unsigned int)
    // void __cdecl BSShaderNoLighting::*(unsigned int)
    // void __cdecl BSShaderNoLighting::*(const NiPropertyState*)
    // void __cdecl BSShaderNoLighting::*(const NiPropertyState*)
    // void __cdecl BSShaderNoLighting::*(const NiPropertyState*)
    // void __cdecl BSShaderNoLighting::*(const NiPropertyState*)
    // void __cdecl BSShaderNoLighting::*(const NiPropertyState*)
    // void __cdecl BSShaderNoLighting::*()
    // void __cdecl BSShaderNoLighting::*(BSShaderNoLightingProperty*, NiMaterialProperty*)
    // void __cdecl BSShaderNoLighting::*(const NiPropertyState*)
    // void __cdecl BSShaderNoLighting::*(NiGeometry*, const NiTransform&)
    // void __cdecl BSShaderNoLighting::*()
    // bool __cdecl BSShaderNoLighting::*()
    // NiD3DShaderDeclaration* __cdecl BSShaderNoLighting::*(NiGeometry*, BSShaderProperty*)
    // void __cdecl BSShaderNoLighting::*()
    // void __cdecl BSShaderNoLighting::*()
    // void __cdecl BSShaderNoLighting::*()
    // bool __cdecl BSShaderNoLighting::*()
    // BSShaderNoLighting& __cdecl BSShaderNoLighting::*(const BSShaderNoLighting&)
};
#pragma pack(pop)
FNV_NOLIGHTING_ASSERT(sizeof(BSShaderNoLighting) == 436);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, spRenderPass) == 108);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_spTreeVertexShader) == 228);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_spPixelShaderVariants) == 340);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pFirstShaderConstantMapEntry) == 368);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pSecondShaderConstantMapEntry) == 372);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pShaderConstantMapEntry3) == 376);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pShaderConstantMapEntry4) == 380);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pShaderConstantMapEntry5) == 384);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant1) == 388);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_spVertexDeclaration) == 392);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant3) == 396);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant4) == 400);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant5) == 404);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant6) == 408);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant7) == 412);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant8) == 416);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant9) == 420);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant10) == 424);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant11) == 428);
FNV_NOLIGHTING_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant12) == 432);
#endif

#endif

extern NiColorA DAT_011a9be0;
extern NiColorA DAT_01202010;

#include "NiPoint3.h"

class NiSkinInstance;
class NiGeometryBufferData;
class NiD3DShaderProgram;

class NiWireframeProperty : public NiProperty
{
  public:
    unsigned short m_uiObjectFlags;
};

class GraphicsRenderer
{
  public:
    void ApplyObjectTransform(const NiTransform&, bool);
};
class ShaderPassRenderer
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void SetWireframeProperty(NiWireframeProperty*);
};

extern NiGeometry** DAT_011f91e0;
extern unsigned int DAT_011f91e4;
extern NiBound DAT_011f4288;
extern NiPoint3 DAT_011f474c;
extern int DAT_0126f74c;
extern NiColorA DAT_01202020;
extern NiColorA DAT_01202030;
void __cdecl BSRenderState_SetZWriteEnable(unsigned int, unsigned int);
void __cdecl BSRenderState_SetZEnable(unsigned int, unsigned int);
