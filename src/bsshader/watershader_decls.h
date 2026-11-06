// MSVC9 SP1 layout check: PASS
// CodeView tag codeview-tag-layout:sha256:36e0a9263f6adaa82628844d2452e2877a9895682d5dc437b88709308025b9f0; PC corrections inherited from generate_headers.py.
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef WATERSHADER_DECLS_H
#define WATERSHADER_DECLS_H

#include "../../include/NiTexture.h"
#include "../../include/NiPointer.h"
#include "../../include/BSShader.h"
#include "../../include/NiD3DDefaultShader.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiD3DShaderDeclaration.h"
#include "../../include/NiD3DShaderInterface.h"
#include "../../include/NiD3DShaderProgram.h"
#include "../../include/NiD3DVertexShader.h"
#include "../../include/NiGPUProgram.h"
#include "../../include/NiShader.h"
#include "../../include/NiShaderConstantMapEntry.h"
#include "../../include/NiColorA.h"
#include <stddef.h>
#define WATER_JOIN_IMPL(a, b) a##b
#define WATER_JOIN(a, b) WATER_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char WATER_JOIN(water_layout_check_, __LINE__)[(condition) ? 1 : -1]

template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
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

class BeamStage;
class Direct3DDeviceInterface;
class WaterShader;
#include "../../include/_D3DXMACRO.h"
class D3DRenderStateGroup;
class NiDynamicEffectState;
class NiScreenElements;
class ShaderPassRenderer;
class GraphicsRenderer;

#pragma pack(push, 4)
class WaterShader : public BSShader
{
  public:
    NiPointer<NiD3DPass> spRenderPass[74];              // +0x6C, 296 bytes
    NiPointer<NiD3DVertexShader> m_spVertexShader1;     // +0x194, 4 bytes
    NiPointer<NiD3DVertexShader> m_spVertexShader2;     // +0x198, 4 bytes
    NiPointer<NiD3DVertexShader> m_spVertexShader3;     // +0x19C, 4 bytes
    NiPointer<NiD3DPixelShader> m_aspPixelShaders[38];  // +0x1A0, 152 bytes
    NiPointer<NiTexture> m_spFirstTexture;              // +0x238, 4 bytes
    NiPointer<NiTexture> m_spSecondTexture;             // +0x23C, 4 bytes
    NiPointer<NiTexture> m_spThirdTexture;              // +0x240, 4 bytes
    NiPointer<NiTexture> m_spTexture4;                  // +0x244, 4 bytes
    NiPointer<NiTexture> WaterShaderTextures;           // +0x248, 4 bytes
    NiPointer<NiTexture> m_spFourthWaterTexture;        // +0x24C, 4 bytes
    WaterShader();
    static BSShader* CreateShader();
    void InitializeShaderData();
    void UpdateShaderConstants();
    void InitWaterPasses();
    virtual ~WaterShader();
    // const NiRTTI* __cdecl WaterShader::*()
    // WaterShader
    // void __cdecl WaterShader::*()
    // WaterShader* __cdecl WaterShader::*()
    // void __cdecl WaterShader::*(unsigned int)
    // void __cdecl WaterShader::*(unsigned int)
    // void __cdecl WaterShader::*(unsigned int)
    // void __cdecl WaterShader::*(const NiPropertyState*)
    // void __cdecl WaterShader::*(const NiPropertyState*)
    // void __cdecl WaterShader::*(const NiPropertyState*)
    // void __cdecl WaterShader::*()
    // bool __cdecl WaterShader::*()
    // void __cdecl WaterShader::*()
    // void __cdecl WaterShader::*(unsigned int, bool)
    // void __cdecl WaterShader::*(NiTexture*)
    // void __cdecl WaterShader::*(NiTexture*)
    // void __cdecl WaterShader::*(NiTexture*)
    // void __cdecl WaterShader::*(NiTexture*)
    // void __cdecl WaterShader::*(NiTexture*)
    // NiTexture* __cdecl WaterShader::*()
    // void __cdecl WaterShader::*(NiTexture*)
    // void __cdecl WaterShader::*()
    // void __cdecl WaterShader::*()
    // bool __cdecl WaterShader::*()
    // WaterShader& __cdecl WaterShader::*(const WaterShader&)
    // void __cdecl WaterShader::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(WaterShader) == 592);
FNV_STATIC_ASSERT(offsetof(WaterShader, spRenderPass) == 108);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spVertexShader1) == 404);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spVertexShader2) == 408);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spVertexShader3) == 412);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_aspPixelShaders) == 416);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spFirstTexture) == 568);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spSecondTexture) == 572);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spThirdTexture) == 576);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spTexture4) == 580);
FNV_STATIC_ASSERT(offsetof(WaterShader, WaterShaderTextures) == 584);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spFourthWaterTexture) == 588);

class NiRenderer;

class NiD3DVertexDeclaration : public NiD3DShaderDeclaration
{
  public:
    static NiD3DVertexDeclaration* Create(NiRenderer*, unsigned int, unsigned int);
};
extern NiRenderer* DAT_011f9508;

struct WaterShaderThreadState
{
    unsigned char precedingThreadState[0x2b4];
    int m_uiMemoryContext;
};
extern "C" volatile unsigned int _tls_index;
extern "C" unsigned long __readfsdword(unsigned long);
#pragma intrinsic(__readfsdword)
inline WaterShaderThreadState* WaterShaderGetThreadState()
{
    unsigned int index = _tls_index;
    return reinterpret_cast<WaterShaderThreadState**>(__readfsdword(0x2c))[index];
}
class WaterShaderMemContext
{
    // Valid MEM_CONTEXT values are nonnegative; -1 marks an already-restored guard.
    int previous;

  public:
    WaterShaderMemContext(WaterShaderThreadState* state, int m_uiMemoryContext) : previous(state->m_uiMemoryContext)
    {
        state->m_uiMemoryContext = m_uiMemoryContext;
    }
    void Restore(WaterShaderThreadState* state)
    {
        state->m_uiMemoryContext = previous;
        previous = -1;
    }
    ~WaterShaderMemContext()
    {
        if (previous != -1)
            WaterShaderGetThreadState()->m_uiMemoryContext = previous;
    }
};
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" int fnv_particle_shader_renderer_level;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4a0;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4a4;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4a8;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4ac;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4b0;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4b4;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4b8;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4bc;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4c0;
extern float DAT_011ff548[12];
extern float DAT_011ff588[28];
extern float DAT_011ff5f8[4];
extern float DAT_011ff608[8];
extern float DAT_011ff628[4];
extern float DAT_011ff638[8];
extern float DAT_011ff658[68];

extern WaterShader* DAT_011ff370;
extern NiColorA DAT_011ff458;
extern bool DAT_011ff100;
extern bool DAT_011ff102;
extern bool DAT_011ff103;
extern bool DAT_011ff104;
struct WaterShaderFrameState
{
    unsigned int frame;
    short flags;
};
extern WaterShaderFrameState DAT_011ff110;
struct WaterShaderUpdateState
{
    unsigned short count;
    unsigned char active;
};
extern WaterShaderUpdateState DAT_011ff118;
#endif
