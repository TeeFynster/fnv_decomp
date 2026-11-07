#include "../../include/NiPointer.h"
// bsshader/shadowlightshader.cpp: ShadowLightShader, ShaderS, ShaderAdapter, ObjectArray and more (59 functions)

#include <stdlib.h>
#include <stdio.h>
#include "../../include/NiPointer.h"
#include "../../include/NiPoint2.h"
#include "../../include/NiTransform.h"
// NiRefObj_shadowlightshader: local type (was include/NiRefObj.h, which had no evidence of one real class); no method of it is bound to a named game function
#include <windows.h>

class NiRefObj_shadowlightshader
{
public:
    unsigned int unk00;
    union
    {
        unsigned int m_uiRefCount;
        long m_iObjectReferenceCount;
        long m_ref;
    };

    ~NiRefObj_shadowlightshader();
    void vfn_00();
    void v00();
    void v04();
    void v0();
    void DeleteThis() throw();

    void IncRefCount() throw()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }

    void DecRefCount() throw()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};
// The legacy declarations below use these shared base and container definitions.
#define FNV_LAYOUT_SUPPORT_H
#define FNV_NIREFOBJECT_H
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#include "../../include/NiAVObject.h"
#include "NiMemObject.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

inline unsigned int NiAtomicIncrement(unsigned int& value)
{
    return InterlockedIncrement(reinterpret_cast<volatile long*>(&value));
}
inline unsigned int NiAtomicSubtract(unsigned int& value)
{
    return InterlockedDecrement(reinterpret_cast<volatile long*>(&value));
}
inline void NiRefObject::IncRefCount()
{
    NiAtomicIncrement(m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (NiAtomicSubtract(m_uiRefCount) == 0)
        DeleteThis();
}
inline NiRefObject::NiRefObject() : m_uiRefCount(0)
{
    NiAtomicIncrement(ms_lObjectCount);
}

template <class T> inline NiPointer<T>::NiPointer()
{
    m_pObject = 0;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew)
{
    m_pObject = pkNew;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(const NiPointer& kSrc)
{
    m_pObject = kSrc.m_pObject;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
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
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& kSrc)
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
template <class T> inline NiPointer<T>::operator T*() const { return m_pObject; }
template <class T> inline T* NiPointer<T>::operator->() const { return m_pObject; }

#include "shadowlightshader_decls.h"

// These shared declarations use the same reference-count operations as NiRefObject.
inline void NiD3DShaderConstantMap::IncRefCount() { NiRefObject::IncRefCount(); }
inline void NiD3DShaderConstantMap::DecRefCount() { NiRefObject::DecRefCount(); }
inline void NiShaderConstantMapEntry::IncRefCount() { NiRefObject::IncRefCount(); }
inline void NiShaderConstantMapEntry::DecRefCount() { NiRefObject::DecRefCount(); }
#include "../../include/BSFaceGenMorphData.h"
#include "../../include/BSShader.h"
#include "../../include/BSShaderAccumulator.h"
#include "../../include/GO.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DVertexShader.h"
#include "../../include/NiShaderConstantMapEntry.h"
#include "../../include/Vec4.h"
class D3DRenderStateGroup
{
public:
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();
    void SetRenderState(unsigned int state, unsigned int value, bool save);
};

inline void NiD3DPass::IncRefCount() { ++m_uiRefCount; }
inline void NiD3DPass::DecRefCount()
{
    if (--m_uiRefCount == 0)
        DestroyPass();
}
inline D3DRenderStateGroup* NiD3DPass::GetRenderStateGroup()
{
    if (!m_pkRenderStateGroup)
        m_pkRenderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    return m_pkRenderStateGroup;
}
#include "../../include/MemoryManager.h"
#include "../../include/NiBound.h"
#include "../../include/NiPoint3.h"

// The shared GetEntry overloads currently place the string overload at 0x74.
// This unit calls the game's string lookup at vtable offset 0x70.
inline NiShaderConstantMapEntry* GetConstantMapEntry(NiD3DShaderConstantMap* map, const char* name)
{
    typedef NiShaderConstantMapEntry* (__thiscall* LookupFunction)(NiD3DShaderConstantMap*, const char*);
    return (*reinterpret_cast<LookupFunction**>(map))[0x70 / sizeof(void*)](map, name);
}

// Lazily creates the four NiD3DShaderConstantMap objects, registers their shader constants and caches the resulting handles in globals.
// @fnv 0x00b7e430
void ShadowLightShader::UpdateShaderConstants()
{
    if (!m_spSecondShaderConstantMap.m_pObject)
    {
        m_spSecondShaderConstantMap = new NiD3DShaderConstantMap(m_pShaderObject, 0u);
        m_spSecondShaderConstantMap.m_pObject->AddConstant8(DAT_010A1E50, 0x20000009, 0, DAT_01011584, 0x0, 0, 0, false);
        m_spSecondShaderConstantMap.m_pObject->AddConstant8("SkinWorldViewProjTranspose", 0x20000009, 1, DAT_01011584, 0x0, 0,
                                                      0, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("ShadowProj", 0x10000009, 0, 18, 4, DAT_01011584, 0x40, 4,
                                                        DAT_011fd968, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("SkinWorldTranspose", 0x10000009, 0, 9, 4, DAT_01011584, 0x40,
                                                        4, DAT_011fec88, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("WorldTranspose", 0x10000009, 0, 8, 4, DAT_01011584, 0x40, 4,
                                                        DAT_011fecc8, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("ShadowProjData", 0x10000007, 0, 22, 1, DAT_01011584, 0x10, 4,
                                                        DAT_011fd874, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("ShadowProjTransform", 0x10000007, 0, 23, 1, DAT_01011584, 0x10,
                                                        4, DAT_011fd884, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("HighDetailRange", 0x10000007, 0, 12, 1, DAT_01011584, 0x10, 4,
                                                        DAT_011fa2e0, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("LightData", 0x10000009, 0, 25, 10, DAT_01011584, 0xa0, 4,
                                                        DAT_011fd9a8, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant(DAT_010AF60C, 0x10000007, 0, 14, 1, DAT_01011584, 0x10, 4,
                                                        DAT_011FA280, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant(DAT_010AF5E4, 0x10000007, 0, 15, 1, DAT_01011584, 0x10, 4,
                                                        DAT_011FA290, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("EyePosition", 0x10000007, 0, 16, 1, DAT_01011584, 0x10, 4,
                                                        DAT_011fd894, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("BoundCenter", 0x10000007, 0, 24, 1, DAT_01011584, 0x10, 4,
                                                        DAT_011fd8b4, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("LODLandParams", 0x10000007, 0, 19, 1, DAT_01011584, 0x10, 4,
                                                        DAT_011fa0b0, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("DepthData", 0x10000007, 0, 17, 1, DAT_01011584, 0x10, 4,
                                                        DAT_011fd954, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("PrevWorldViewPT", 0x10000009, 0, 35, 4, DAT_01011584, 0x40, 4,
                                                        DAT_011fed08, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("PrevWorldViewT", 0x10000009, 0, 39, 4, DAT_01011584, 0x40, 4,
                                                        DAT_011fed48, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("BoneMatrix3", 0x20000009, 1179648, 44, 54, 0, 0x0, 0, 0,
                                                        false);
        m_spSecondShaderConstantMap.m_pObject->AddConstant8("WorldViewTranspose", 0x20000009, 4, DAT_01011584, 0x0, 0, 0,
                                                      false);
        m_spSecondShaderConstantMap.m_pObject->AddConstant8("SkinWorldViewTranspose", 0x20000009, 5, DAT_01011584, 0x0, 0, 0,
                                                      false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("Time", 0x10000004, 0, 13, 1, DAT_01011584, 0x4, 4,
                                                        DAT_011fd868, false);
        m_spSecondShaderConstantMap.m_pObject->SetConstant("PrevBoneMatrix3", 0x10000009, 0, 98, 54, DAT_01011584, 0x360,
                                                        4, DAT_011fa580, false);
        DAT_011febd8 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, DAT_010A1E50);
        DAT_011febdc = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "WorldTranspose");
        DAT_011fec08 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "SkinWorldTranspose");
        DAT_011febe0 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "SkinWorldViewProjTranspose");
        DAT_011febe4 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "ShadowProj");
        DAT_011febe8 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "ShadowProjData");
        DAT_011febec = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "ShadowProjTransform");
        DAT_011fec18 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "HighDetailRange");
        DAT_011febf0 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "LightData");
        DAT_011febf4 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, DAT_010AF60C);
        DAT_011febf8 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, DAT_010AF5E4);
        DAT_011febfc = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "EyePosition");
        DAT_011fec00 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "BoneMatrix3");
        DAT_011fec0c = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "WorldViewTranspose");
        DAT_011fec10 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "SkinWorldViewTranspose");
        DAT_011fec14 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "Time");
        DAT_011fec1c = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "BoundCenter");
        DAT_011fec2c = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "LODLandParams");
        DAT_011fec20 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "DepthData");
        DAT_011fec24 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "PrevWorldViewPT");
        DAT_011fec28 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "PrevWorldViewT");
        DAT_011fec04 = GetConstantMapEntry(m_spSecondShaderConstantMap.m_pObject, "PrevBoneMatrix3");
        m_spSecondPassConstantMap = m_spSecondShaderConstantMap;
    }
    if (!m_spFirstShaderConstantMap.m_pObject)
    {
        m_spFirstShaderConstantMap = new NiD3DShaderConstantMap(m_pShaderObject, 2u);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("eye dir", 0x10000007, 0, 0, 1, DAT_01011584, 0x10, 4,
                                                       DAT_011fd8a4, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant(DAT_010AF568, 0x10000007, 0, 1, 1, DAT_01011584, 0x10, 4,
                                                       DAT_011FA0C0, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("LightColors", 0x10000009, 0, 3, 10, DAT_01011584, 0xa0, 4,
                                                       DAT_011FA0D0, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("Light Direction", 0x10000007, 0, 18, 1, DAT_01011584, 0x10, 4,
                                                       DAT_011fd9a8, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("Light Position0", 0x10000007, 0, 19, 1, DAT_01011584, 0x10, 4,
                                                       DAT_011fd9b8, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("Light Position1", 0x10000007, 0, 20, 1, DAT_01011584, 0x10, 4,
                                                       DAT_011fd9c8, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("Light Position2", 0x10000007, 0, 21, 1, DAT_01011584, 0x10, 4,
                                                       DAT_011fd9d8, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("Light Position3", 0x10000007, 0, 22, 1, DAT_01011584, 0x10, 4,
                                                       DAT_011fd9e8, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("Emittance Color", 0x10000007, 0, 2, 1, DAT_01011584, 0x10, 4,
                                                       DAT_011fa270, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("EyePosition", 0x10000007, 0, 17, 1, DAT_01011584, 0x10, 4,
                                                       DAT_011fd894, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("Toggles", 0x10000007, 0, 27, 1, DAT_01011584, 0x10, 4,
                                                       DAT_011fa2d0, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("HairTint", 0x10000007, 0, 28, 1, DAT_01011584, 0x10, 4,
                                                       DAT_011fa090, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("STBBColorConstants", 0x10000007, 0, 30, 1, DAT_01011584, 0x10,
                                                       4, DAT_011fa2f0, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("LODTEXPARAMS", 0x10000007, 0, 31, 1, DAT_01011584, 0x10, 4,
                                                       DAT_011fa300, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("RefractionParams", 0x10000004, 0, 29, 1, DAT_01011584, 0x4, 4,
                                                       DAT_011fd944, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("FogParams", 0x10000004, 0, 14, 1, DAT_01011584, 0x4, 4,
                                                       DAT_011fd8c4, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("FogColor", 0x10000004, 0, 15, 1, DAT_01011584, 0x4, 4,
                                                       DAT_011fd8d4, false);
        m_spFirstShaderConstantMap.m_pObject->SetConstant("FogPlane", 0x10000004, 0, 16, 1, DAT_01011584, 0x4, 4,
                                                       DAT_011fd8e4, false);
        DAT_011fec6c = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "HairTint");
        DAT_011fec30 = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "eye dir");
        DAT_011fec34 = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, DAT_010AF568);
        DAT_011fec38 = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "LightColors");
        DAT_011fec48 = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "Light Direction");
        DAT_011fec4c = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "Light Position0");
        DAT_011fec50 = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "Light Position1");
        DAT_011fec54 = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "Light Position2");
        DAT_011fec58 = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "Light Position3");
        DAT_011fec3c = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "Emittance Color");
        DAT_011fec44 = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "EyePosition");
        DAT_011fec40 = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "Toggles");
        DAT_011fec70 = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "RefractionParams");
        DAT_011fec74 = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "FogParams");
        DAT_011fec78 = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "FogColor");
        DAT_011fec7c = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "FogPlane");
        DAT_011fec80 = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "LODTEXPARAMS");
        DAT_011fec84 = GetConstantMapEntry(m_spFirstShaderConstantMap.m_pObject, "STBBColorConstants");
        m_spFirstPassConstantMap = m_spFirstShaderConstantMap;
    }
    if (!m_spFogConstantMap.m_pObject)
    {
        m_spFogConstantMap = new NiD3DShaderConstantMap(m_pShaderObject, 0u);
        m_spFogConstantMap.m_pObject->AddConstant8(DAT_010A1E50, 0x20000009, 0, DAT_01011584, 0x0, 0, 0, false);
        m_spFogConstantMap.m_pObject->AddConstant8("SkinWorldViewProjTranspose", 0x20000009, 4, DAT_01011584, 0x0, 0, 0,
                                             false);
        m_spFogConstantMap.m_pObject->SetConstant("BoneMatrix3", 0x20000009, 1179648, 14, 54, 0, 0x0, 0, 0, false);
        m_spFogConstantMap.m_pObject->SetConstant("EyePosition", 0x10000007, 0, 8, 1, DAT_01011584, 0x10, 4, DAT_011fd894,
                                               false);
        m_spFogConstantMap.m_pObject->SetConstant("U Offset", 0x10000004, 0, 9, 1, DAT_01011584, 0x4, 4, DAT_011fd85c,
                                               false);
        m_spFogConstantMap.m_pObject->SetConstant("V Offset", 0x10000004, 0, 10, 1, DAT_01011584, 0x4, 4, DAT_011fd860,
                                               false);
        m_spFogConstantMap.m_pObject->SetConstant("Z scaler", 0x10000004, 0, 11, 1, DAT_01011584, 0x4, 4, DAT_011fd864,
                                               false);
        m_spFogConstantMap.m_pObject->SetConstant("FogParam", 0x10000007, 0, 12, 1, DAT_01011584, 0x10, 4, DAT_011fd934,
                                               false);
        m_spFogConstantMap.m_pObject->SetConstant("FogColor", 0x10000007, 0, 13, 1, DAT_01011584, 0x10, 4, DAT_011fd924,
                                               false);
    }
    if (!m_spFillColorConstantMap.m_pObject)
    {
        m_spFillColorConstantMap = new NiD3DShaderConstantMap(m_pShaderObject, 2u);
        m_spFillColorConstantMap.m_pObject->SetConstant("Fill Color", 0x10000007, 0, 0, 1, DAT_01011584, 0x10, 4,
                                                     DAT_011fd8f4, false);
        m_spFillColorConstantMap.m_pObject->SetConstant("Rim Color", 0x10000007, 0, 1, 1, DAT_01011584, 0x10, 4,
                                                     DAT_011fd904, false);
        m_spFillColorConstantMap.m_pObject->SetConstant("fVars", 0x10000007, 0, 2, 1, DAT_01011584, 0x10, 4, DAT_011fd914,
                                                     false);
    }
}

void* __cdecl memcpy(void*, const void*, unsigned int);
#pragma function(memcpy)

struct __declspec(align(16)) Mat16
{
    float m[4][4];
};

// If the global at DAT_011fec08 has a nonzero byte at offset 8 and param_1 is nonzero, copies an identity 4x4 matrix into DAT_011fec88.
// @fnv 0x00b79050
void __stdcall ResetTransform(int param_1)
{
    if ((*(char**)&DAT_011fec08)[8] != 0 && param_1 != 0)
    {
        Mat16 identityMat;
        identityMat.m[0][1] = identityMat.m[0][2] = identityMat.m[0][3] = identityMat.m[1][0] = identityMat.m[1][2] =
            identityMat.m[1][3] = identityMat.m[2][0] = identityMat.m[2][1] = identityMat.m[2][3] =
                identityMat.m[3][0] = identityMat.m[3][1] = identityMat.m[3][2] = 0.0f;
        identityMat.m[0][0] = identityMat.m[1][1] = identityMat.m[2][2] = identityMat.m[3][3] = 1.0f;
        memcpy((void*)DAT_011fec88, &identityMat, 0x40);
    }
}

extern float _DAT_011f940c;
extern const double _DAT_01012640;
extern const double _DAT_0104eea0;

// If the byte at offset 8 of DAT_011fec14.m_pObject is non-zero, writes a scaled value derived from param_1's int at offset 0xe4 to DAT_011fd868.
// @fnv 0x00b790d0
void __stdcall UpdateScaledValue(const char* param_1)
{
    if (*((const char*)DAT_011fec14.m_pObject + 8) != 0)
    {
        *(float*)DAT_011fd868 = (_DAT_011f940c / _DAT_01012640) * _DAT_0104eea0 * *(const int*)(param_1 + 0xe4);
    }
}


inline Vec4::Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}

extern Vec4 _DAT_011FA0C0[];

// For message 0x93/0x1f1-0x1f5 sets an object field from param_2[9]+2, then writes two Vec4 flag vectors into _DAT_011FA0C0 based on param_2[11].
// @fnv 0x00b79410
// src: COMMUNITY 0x00b79410
void __stdcall ShadowLightShader_SetupGeometryConstants_LandTextureMask(unsigned int uiMessageId, unsigned char* pucPayload)
{
    int iSlotA;
    int iSlotB;

    switch (uiMessageId)
    {
    case 0x93:
    case 0x1f1:
    case 0x1f2:
    case 0x1f3:
    case 0x1f4:
    case 0x1f5: {
        iSlotA = 2;
        iSlotB = 3;
        int iValue = pucPayload[9] + 2;
        if (iValue <= 3)
            iValue = 3;
        *(int*)((char*)DAT_011fec38.m_pObject + 0x20) = iValue;
        break;
    }
    case 0x1f6:
        iSlotA = 0;
        iSlotB = 27;
        break;
    default:
        return;
    }

    int c = pucPayload[11];
    _DAT_011FA0C0[iSlotA] =
        Vec4(c == 1 ? 1.0f : 0.0f, c == 2 ? 1.0f : 0.0f, c == 3 ? 1.0f : 0.0f, c == 4 ? 1.0f : 0.0f);
    _DAT_011FA0C0[iSlotB] =
        Vec4(c == 5 ? 1.0f : 0.0f, c == 6 ? 1.0f : 0.0f, c == 7 ? 1.0f : 0.0f, c == 8 ? 1.0f : 0.0f);
}

extern const float g_011c3bb8_arg1;
extern float DAT_011fd948;

// @fnv 0x00b796f0
// src: COMMUNITY 0x00b796f0
void __stdcall ShadowLightShader_SetupGeometryConstants_RefractionPower(const char* param_1)
{
    if (*((const char*)DAT_011fec70.m_pObject + 8) != 0)
    {
        *const_cast<float*>(DAT_011fd944) = *(const float*)(param_1 + 0xe0);
        if ((*(const unsigned int*)(param_1 + 0x24) & 0x10) > 0)
            DAT_011fd948 = g_011c3bb8_arg1;
        else
            DAT_011fd948 = 1.0f;
    }
}

extern float DAT_011fa304;
extern float DAT_011fa308;
extern float DAT_011fa30c;

struct Float4
{
    float x, y, z, w;
};

// If the byte at offset 8 of DAT_011fec80.m_pObject is non-zero, copies four floats from param_1[0x3c..0x3f] into DAT_011fa300 as a Float4.
// @fnv 0x00b798c0
// src: COMMUNITY 0x00b798c0
void __stdcall ShadowLightShader_SetupGeometryConstants_LODTexParams(const float* afSource)
{
    if (*reinterpret_cast<const char*>(reinterpret_cast<const char*>(DAT_011fec80.m_pObject) + 8) != 0)
    {
        Float4 v;
        v.x = afSource[0x3c];
        v.y = afSource[0x3d];
        v.w = afSource[0x3e];
        v.z = afSource[0x3f];

        *reinterpret_cast<Float4*>(const_cast<float*>(DAT_011fa300)) = v;
    }
}

// Assigns pObj to the NiPointer at pThis+0x5c, releasing the old object and incrementing the new one's reference count.
// @fnv 0x00b79950
// src: GAMEBRYO_LIB 0x00b79950
void __fastcall NiD3DPass_SetVertexShader(char* pThis, int, NiRefObject* pObj)
{
    NiPointer<NiRefObject>& spMember = *(NiPointer<NiRefObject>*)(pThis + 0x5c);
    if (spMember.m_pObject != pObj)
    {
        if (spMember.m_pObject)
            spMember.m_pObject->DecRefCount();

        spMember.m_pObject = pObj;

        if (spMember.m_pObject)
            spMember.m_pObject->IncRefCount();
    }
}

class NiMatrix3;
class NiPoint3;

void __cdecl BuildTransformMatrix(float*, NiMatrix3 const&, NiPoint3 const&, float);

// @fnv 0x00b799a0
// src: COMMUNITY 0x00b799a0
void __cdecl NiD3DUtility_GetD3DFromNi_(float* pDest, const char* pTransform)
{
    BuildTransformMatrix(pDest, *(const NiMatrix3*)pTransform, *(const NiPoint3*)(pTransform + 0x24),
                         *(const float*)(pTransform + 0x30));
}

// @fnv 0x00b79db0
void __fastcall SetField60And64(char* thisPtr, int, int aiValue, char b)
{
    *(int*)(thisPtr + 0x60) = aiValue;
    *(thisPtr + 0x64) = b;
}

// @fnv 0x00b7a6f0
// src: COMMUNITY 0x00b7a6f0
int __fastcall ShadowLightShader_GetShaderDeclaration(unsigned char* _this, int, unsigned char* a1, unsigned char* pFlagsSource)
{
    if (*reinterpret_cast<int*>(a1 + 0xbc) != 0)
        return *reinterpret_cast<int*>(_this + 0x70);
    if (pFlagsSource && (*reinterpret_cast<unsigned int*>(pFlagsSource + 0x20) & 0x1000) > 0)
        return *reinterpret_cast<int*>(_this + 0x74);
    if ((*reinterpret_cast<unsigned int*>(pFlagsSource + 0x20) & 0x4000) > 0)
        return *reinterpret_cast<int*>(_this + 0x78);
    return *reinterpret_cast<int*>(_this + 0x6c);
}

extern int DAT_011fdff8[];
extern int DAT_011febd4;

typedef void(__thiscall* Fn128)(void*, int);

// Calls the virtual function at offset 0x128 on self for each int in DAT_011fdff8 up to &DAT_011febd4.
// @fnv 0x00b78a40
// src: COMMUNITY 0x00b78a40
void __fastcall ShadowLightShader_ClearPassStages(void** self)
{
    int* p = DAT_011fdff8;
    do
    {
        reinterpret_cast<Fn128*>(*self)[0x128 / 4](self, *p);
        ++p;
    } while (reinterpret_cast<int>(p) < reinterpret_cast<int>(&DAT_011febd4));
}

extern float DAT_012023e0;
extern float DAT_011fd958;

// @fnv 0x00b78a70
// src: COMMUNITY 0x00b78a70
void ShadowLightShader_UpdateFarNear()
{
    const_cast<float*>(DAT_011fd954)[0] = 1.0f / DAT_012023e0;
    DAT_011fd958 = 0.0f;
}

extern const double runtimeInitializationDouble5;
extern float DAT_011f474c;
extern float DAT_011f4750;
extern float DAT_011f95f4;
extern float DAT_011f95f8;
extern float DAT_011f95fc;
extern float DAT_011f9600;



// @fnv 0x00b79100
// src: COMMUNITY 0x00b79100
void __stdcall ShadowLightShader_SetupGeometryConstants_HighDetailRange(int unused)
{
    if ((*reinterpret_cast<char**>(&DAT_011fec18))[8])
    {
        Vec4 v;
        v.x = DAT_011f95f4 - DAT_011f474c;
        v.y = DAT_011f95f8 - DAT_011f4750;
        v.z = DAT_011f95fc - runtimeInitializationDouble5;
        v.w = DAT_011f9600 - runtimeInitializationDouble5;
        *reinterpret_cast<Vec4*>(const_cast<float*>(DAT_011fa2e0)) = v;
    }
}

extern NiBound DAT_011f4288;
extern float DAT_011f474c;
extern float DAT_011f4750;
extern float DAT_011f4754;
extern float DAT_011fd8b8;
extern float DAT_011fd8bc;

// @fnv 0x00b79180
// src: COMMUNITY 0x00b79180
void __stdcall ShadowLightShader_SetupGeometryConstants_WorldBoundCenter(void* param_1)
{
    NiShaderConstantMapEntry* p = *(NiShaderConstantMapEntry**)(void*)&DAT_011fec1c;
    if (*(unsigned char*)((unsigned char*)p + 8) != 0)
    {
        float* pFloats = *(float**)((unsigned char*)param_1 + 0x20);
        if (pFloats == 0)
            pFloats = (float*)&DAT_011f4288;

        float vals[3];
        vals[0] = pFloats[0] - DAT_011f474c;
        vals[1] = pFloats[1] - DAT_011f4750;
        vals[2] = pFloats[2] - DAT_011f4754;
        *(float*)DAT_011fd8b4 = vals[0];
        DAT_011fd8b8 = vals[1];
        DAT_011fd8bc = vals[2];
    }
}


// @fnv 0x00b79930
// src: GUESS 0x00b79930 (confidence: high)
void __fastcall NiD3DPass_ReleasePassReference(NiD3DPass** slot)
{
    NiD3DPass* p = *slot;
    if (p && --p->m_uiRefCount == 0)
        p->DestroyPass();
}

extern MemoryManager g_memoryManager;
inline void* GO::operator new[](std::size_t size)
{
    return g_memoryManager.Allocate(size);
}


// Allocates an array of count GO objects via GO::operator new[] and returns the pointer.
// @fnv 0x00b79a60
GO* __cdecl AllocateGOArray(unsigned int count)
{
    return new GO[count];
}

struct FUN_00b79d80_obj
{
    char pad[0x24];
    bool flag;
};

// @fnv 0x00b79d80
// src: COMMUNITY 0x00b79d80
bool __fastcall NiD3DShader_SetUsesNiRenderState(FUN_00b79d80_obj* self, int edx, bool value)
{
    self->flag = value;
    return true;
}

struct FUN_00b79da0_obj
{
    char pad[0x20];
    bool flag;
};

// Stores the given boolean value into the flag field of the object.
// @fnv 0x00b79da0
// src: XBOX_PDB 0x00b79da0
void __fastcall NiD3DShaderInterface_SetIsBestImplementation(FUN_00b79da0_obj* self, int edx, bool value)
{
    self->flag = value;
}

extern const char g_012022b4_arg1[];

// @fnv 0x00b79dd0
// src: COMMUNITY 0x00b79dd0
const char* __cdecl ShadowLightShader_GetRTTI()
{
    return g_012022b4_arg1;
}

extern int _fnv_particle_shader_renderer_level;

struct FUN_00b78980_shell
{
    void __thiscall ShadowLightShader_PresetZOnlyPasses_1x();
    void __thiscall ShadowLightShader_PresetAmbientPasses_1x();
    void __thiscall ConfigureRenderPasses();
    void __thiscall InitGraphicsResources();
    void __thiscall ShadowLightShader_PresetDiffuseDirPasses_1x();
    void __thiscall ShadowLightShader_PresetTexturePasses_1x();
    void __thiscall ShadowLightShader_PresetSpecularPasses_1x();
    void __thiscall ShadowLightShader_PresetEnvMapPasses_1x();
    void __thiscall ShadowLightShader_PresetFogPasses_1x();
    void __thiscall ConfigureBeamPasses();
    void __thiscall InitDefaultShaderPasses();
    void __thiscall ShadowLightShader_PresetADTPasses_2x();
    void __thiscall SetupRenderPasses();
    void __thiscall ShadowLightShader_PresetADPasses_2x();
    void __thiscall ShadowLightShader_PresetDiffusePasses_2x();
    void __thiscall ShadowLightShader_PresetSpecularPasses_2x();
    void __thiscall ShadowLightShader_PresetEnvMapPasses_2x();
    void __thiscall InitializeBeamPasses();
    void __thiscall InitializeGraphicsSystems();
    void __thiscall InitStageObjects();
    void __thiscall ShadowLightShader_PresetDepthPasses_2x();
    void __thiscall InitShaderConfigs();
    void __thiscall ShadowLightShader_PresetLocalMapPasses_2x();
    void __thiscall ShadowLightShader_PresetWaterFogPasses_2x();
    void __thiscall InitializeParticleShaderRenderer();
};

// @fnv 0x00b78980
void __thiscall FUN_00b78980_shell::InitializeParticleShaderRenderer()
{
    ((void(__thiscall*)(void*))(*(void***)this)[0x51])(this);
    ShadowLightShader_PresetZOnlyPasses_1x();
    ShadowLightShader_PresetAmbientPasses_1x();
    ConfigureRenderPasses();
    InitGraphicsResources();
    ShadowLightShader_PresetDiffuseDirPasses_1x();
    ShadowLightShader_PresetTexturePasses_1x();
    ShadowLightShader_PresetSpecularPasses_1x();
    ShadowLightShader_PresetEnvMapPasses_1x();
    ShadowLightShader_PresetFogPasses_1x();
    ConfigureBeamPasses();
    if (_fnv_particle_shader_renderer_level >= 2)
    {
        ShadowLightShader_PresetADPasses_2x();
        ShadowLightShader_PresetADTPasses_2x();
        SetupRenderPasses();
        ShadowLightShader_PresetDiffusePasses_2x();
        ShadowLightShader_PresetSpecularPasses_2x();
        ShadowLightShader_PresetEnvMapPasses_2x();
        InitializeBeamPasses();
        InitStageObjects();
        ShadowLightShader_PresetDepthPasses_2x();
        InitShaderConfigs();
        ShadowLightShader_PresetLocalMapPasses_2x();
        InitializeGraphicsSystems();
        ShadowLightShader_PresetWaterFogPasses_2x();
    }
    else
    {
        InitDefaultShaderPasses();
    }
}

namespace fnv_00b78ef0 {
struct Matrix_b78ef0
{
    float m[16];
};
void* __stdcall D3DXVec3TransformCoord_00ee6df8(NiPoint3* out, const NiPoint3* v, const Matrix_b78ef0* m);
extern float DAT_011f474c;
extern float DAT_011f4750;
extern float DAT_011f4754;
extern float DAT_011fa2a0;
extern float DAT_011fa2a4;
extern float DAT_011fa2a8;

// @fnv 0x00b78ef0
void __stdcall UpdateEyePosition(unsigned int type, char* geom, Matrix_b78ef0 matrix)
{
    if ((*(char**)&DAT_011febfc)[8] || (*(char**)&DAT_011fec44)[8])
    {
        float* eyePos = (float*)DAT_011fd894;
        float* eyeDir = (float*)DAT_011fd8a4;
        switch (type)
        {
        case 0x244:
        case 0x245:
        case 0x246:
        case 0x247:
        case 0x248:
        case 0x249:
        case 0x24a:
        case 0x24b: {
            NiPoint3& pos = *(NiPoint3*)matrix.m;
            pos.x = DAT_011fa2a0;
            pos.y = DAT_011fa2a4;
            pos.z = DAT_011fa2a8;
            NiPoint3 dir;
            dir.x = pos.x - *(float*)(geom + 0x24);
            dir.y = pos.y - *(float*)(geom + 0x28);
            dir.z = pos.z - *(float*)(geom + 0x2c);
            dir.ComputeMagnitude();
            eyeDir[0] = dir.x;
            eyeDir[1] = dir.y;
            eyeDir[2] = dir.z;
            eyeDir[3] = 0.0f;
            pos.x -= DAT_011f474c;
            pos.y -= DAT_011f4750;
            pos.z -= DAT_011f4754;
            eyePos[0] = pos.x;
            eyePos[1] = pos.y;
            eyePos[2] = pos.z;
            eyePos[3] = 1.0f;
            break;
        }
        default: {
            NiPoint3 out;
            NiPoint3 pos;
            pos.x = DAT_011fa2a0;
            pos.y = DAT_011fa2a4;
            pos.z = DAT_011fa2a8;
            D3DXVec3TransformCoord_00ee6df8(&out, &pos, &matrix);
            eyePos[0] = out.x;
            eyePos[1] = out.y;
            eyePos[2] = out.z;
            eyePos[3] = *(float*)(geom + 0x30);
            break;
        }
        }
    }
}
}  // namespace fnv_00b78ef0

struct BSFogProperty;
BSFogProperty* __cdecl BSShaderManager_GetFogProperty(int);
extern unsigned char DAT_011f91c4;
extern float DAT_010af2f0;
extern float DAT_011fa2d4;
extern float DAT_011fa2d8;
extern float DAT_011fa2dc;
struct GeomS
{
    virtual void Gb0();
    virtual void Gb1();
    virtual void Gb2();
    virtual void Gb3();
    virtual void Gb4();
    virtual void Gb5();
    virtual void Gb6();
    virtual void Gb7();
    virtual void Gb8();
    virtual void Gb9();
    virtual void Gb10();
    virtual void Gb11();
    virtual void Gb12();
    virtual void Gb13();
    virtual void Gb14();
    virtual void Gb15();
    virtual void Gb16();
    virtual void Gb17();
    virtual void Gb18();
    virtual void Gb19();
    virtual void Gb20();
    virtual void Gb21();
    virtual void Gb22();
    virtual void Gb23();
    virtual void Gb24();
    virtual void Gb25();
    virtual void Gb26();
    virtual void Gb27();
    virtual void Gb28();
    virtual void Gb29();
    virtual void Gb30();
    virtual void Gb31();
    virtual void Gb32();
    virtual void Gb33();
    virtual void Gb34();
    virtual void Gb35();
    virtual void Gb36();
    virtual void Gb37();
    virtual void Gb38();
    virtual void Gb39();
    virtual void Gb40();
    virtual void Gb41();
    virtual void Gb42();
    virtual void Gb43();
    virtual void Gb44();
    virtual void Gb45();
    virtual void Gb46();
    virtual void Gb47();
    virtual void Gb48();
    virtual void Gb49();
    virtual void Gb50();
    virtual void Gb51();
    virtual void Gb52();
    virtual void Gb53();
    virtual void Gb54();
    virtual void Gb55();
    virtual void Gb56();
    virtual void Gb57();
    virtual void Gb58();
    virtual void Gb59();
    virtual void Gb60();
    virtual int GetFlag(int, int);
};
struct GeomData
{
    char pad[0x20];
    unsigned int uiFlags;
    char pad24[0xc];
    float fAlpha;
};
struct PropS
{
    char pad[8];
    unsigned char bFlag;
};
struct MatS
{
    char pad[0x18];
    unsigned short usFlags;
    unsigned char ucAlpha;
    unsigned short GetField(unsigned short usMask, unsigned short usPos) const
    {
        return (unsigned short)((usFlags & usMask) >> usPos);
    }
    bool GetBit(unsigned short usMask) const
    {
        return (usFlags & usMask) != 0;
    }
};
struct ShaderS
{
    virtual void Va0();
    virtual void Va1();
    virtual void Va2();
    virtual void Va3();
    virtual void Va4();
    virtual void Va5();
    virtual void Va6();
    virtual void Va7();
    virtual void Va8();
    virtual void Va9();
    virtual void Va10();
    virtual void Va11();
    virtual void Va12();
    virtual void Va13();
    virtual void Va14();
    virtual void Va15();
    virtual void Va16();
    virtual void Va17();
    virtual void Va18();
    virtual void Va19();
    virtual void Va20();
    virtual void Va21();
    virtual void Va22();
    virtual void Va23();
    virtual void Va24();
    virtual void Va25();
    virtual void Va26();
    virtual void Va27();
    virtual void Va28();
    virtual void Va29();
    virtual void Va30();
    virtual void Va31();
    virtual void Va32();
    virtual void Va33();
    virtual void Va34();
    virtual void Va35();
    virtual void Va36();
    virtual void Va37();
    virtual void Va38();
    virtual void Va39();
    virtual void Va40();
    virtual void Va41();
    virtual void Va42();
    virtual void Va43();
    virtual void Va44();
    virtual void Va45();
    virtual void Va46();
    virtual void Va47();
    virtual void Va48();
    virtual void Va49();
    virtual void Va50();
    virtual void Va51();
    virtual void Va52();
    virtual void Va53();
    virtual void Va54();
    virtual void Va55();
    virtual void Va56();
    virtual void Va57();
    virtual void Va58();
    virtual void Va59();
    virtual void Va60();
    virtual void Va61();
    virtual void Va62();
    virtual void Va63();
    virtual void Va64();
    virtual void Va65();
    virtual void Va66();
    virtual void Va67();
    virtual void Va68();
    virtual void Va69();
    virtual void Va70();
    virtual void Va71();
    virtual void Va72();
    virtual void Va73();
    virtual void Va74();
    virtual void Va75();
    virtual void Va76();
    virtual void Va77();
    virtual void Va78();
    virtual void Va79();
    virtual void Va80();
    virtual void Va81();
    virtual void Va82();
    virtual void Va83();
    virtual void Va84();
    virtual void SetFog(void*, BSFogProperty*, void*);
    void ShadowLightShader_UpdateTogglesConstantLand(void*, int, GeomS*, int);
    void ApplyFogAndAlpha(unsigned int uiPass, void* pArg2, GeomS* pGeom, void* pArg4, PropS* pProp, MatS* pMatrix);
};

// Sets fog or pass-specific state, then updates DAT_011fa2dc/DAT_011fa2d8 alpha values from the geometry and material flags.
// @fnv 0x00b795b0
void ShaderS::ApplyFogAndAlpha(unsigned int uiPass, void* pArg2, GeomS* pGeom, void* pArg4, PropS* pProp, MatS* pMatrix)
{
    if (!(*(char**)&DAT_011fec40)[8])
        return;
    if (uiPass - 0x1f7 <= 0x37)
        ShadowLightShader_UpdateTogglesConstantLand(pArg2, 0, pGeom, 0);
    else
        SetFog(pArg2, BSShaderManager_GetFogProperty(DAT_011f91c4), pArg4);
    if (pProp && !pProp->bFlag)
        DAT_011fa2d4 = 0.0f;
    if (!((((GeomData*)pGeom)->uiFlags & 0x4000) > 0) && (uiPass < 0x248 || uiPass > 0x24b))
    {
        if ((unsigned char)(pMatrix->usFlags >> 9) & 1)
        {
            float fRef = pMatrix->ucAlpha;
            float fAlpha = 1.0 > fRef ? 1.0f : fRef;
            DAT_011fa2dc = fAlpha / 255.0;
        }
        else
        {
            DAT_011fa2dc = pMatrix->GetBit(1) ? DAT_010af2f0 : 0.0f;
        }
        return;
    }
    if (uiPass - 0x248 <= 3)
    {
        DAT_011fa2dc = pGeom->GetFlag(5, 0) ? 1.0f : 0.0f;
        DAT_011fa2d8 = ((GeomData*)pGeom)->fAlpha;
    }
}

namespace fnv_00b7a170 {
void* _fnv_zlib_memset(void*, int, unsigned int);
extern NiPointer<NiShaderConstantMapEntry> DAT_011fdd88[156];
extern NiPointer<NiShaderConstantMapEntry> DAT_011fda48[208];
extern NiD3DPass* DAT_011fdff8[759];
extern int DAT_011fcc80[759];
extern int DAT_011fc0a0[759];
extern int DAT_011fb4c0[759];
extern int DAT_011fa8e0[759];

// Initializes the shader system, clears constant map entries and pass arrays, releases stored passes, and zeroes the shader state buffers.
// @fnv 0x00b7a170
bool __fastcall ResetShaderState(BSShader* shader)
{
    shader->BSShader::Initialize();
    int i;
    for (i = 0; i < 156; i++)
        DAT_011fdd88[i] = 0;
    for (i = 0; i < 208; i++)
        DAT_011fda48[i] = 0;
    for (i = 0; i < 759; i++)
    {
        NiD3DPass* pPass = DAT_011fdff8[i];
        if (pPass)
        {
            if (--pPass->m_uiRefCount == 0)
                pPass->DestroyPass();
            DAT_011fdff8[i] = 0;
        }
    }
    for (i = 0; i < 22; i++)
        (&DAT_011febd8)[i] = 0;
    for (i = 0; i < 22; i++)
        (&DAT_011fec30)[i] = 0;
    _fnv_zlib_memset(DAT_011fcc80, 0, 0xbdc);
    _fnv_zlib_memset(DAT_011fc0a0, 0, 0xbdc);
    _fnv_zlib_memset(DAT_011fb4c0, 0, 0xbdc);
    _fnv_zlib_memset(DAT_011fa8e0, 0, 0xbdc);
    return true;
}
}  // namespace fnv_00b7a170

namespace fnv_00b7a730 {
extern NiPointer<NiD3DPass> DAT_011fdff8[0x2f7];
extern NiD3DVertexShader* DAT_011fdd88;
extern int _fnv_particle_shader_renderer_level;
struct FUN_00b78980_shell
{
    void ShadowLightShader_PresetAmbientPasses_1x();
    void ConfigureRenderPasses();
    void InitGraphicsResources();
    void ShadowLightShader_PresetDiffuseDirPasses_1x();
    void ShadowLightShader_PresetTexturePasses_1x();
    void ShadowLightShader_PresetSpecularPasses_1x();
    void ShadowLightShader_PresetEnvMapPasses_1x();
    void ShadowLightShader_PresetFogPasses_1x();
    void InitDefaultShaderPasses();
    void ConfigureBeamPasses();
    void ShadowLightShader_PresetZOnlyPasses_1x();
    void ShadowLightShader_PresetConstAlphaPasses_1x();
    void ShadowLightShader_PresetADTPasses_2x();
    void SetupRenderPasses();
    void ShadowLightShader_PresetADPasses_2x();
    void ShadowLightShader_PresetDiffusePasses_2x();
    void ShadowLightShader_PresetSpecularPasses_2x();
    void ShadowLightShader_PresetEnvMapPasses_2x();
    void InitializeBeamPasses();
    void InitializeGraphicsSystems();
    void InitStageObjects();
    void ShadowLightShader_PresetDepthPasses_2x();
    void InitShaderConfigs();
    void ShadowLightShader_PresetLocalMapPasses_2x();
    void ShadowLightShader_PresetWaterFogPasses_2x();
    bool InitializePasses();
};

// Resets all 0x2f7 NiD3DPass entries to DAT_011fdd88, then runs the base pass setup and, at particle shader level >= 2, the extra setup routines; returns true.
// @fnv 0x00b7a730
bool FUN_00b78980_shell::InitializePasses()
{
    for (unsigned int i = 0; i < 0x2f7; i++)
    {
        NiD3DPass::CreateD3DPass(DAT_011fdff8[i]);
        DAT_011fdff8[i]->m_spVertexShader = DAT_011fdd88;
    }
    ShadowLightShader_PresetZOnlyPasses_1x();
    ShadowLightShader_PresetConstAlphaPasses_1x();
    ShadowLightShader_PresetAmbientPasses_1x();
    ConfigureRenderPasses();
    InitGraphicsResources();
    ShadowLightShader_PresetDiffuseDirPasses_1x();
    ShadowLightShader_PresetTexturePasses_1x();
    ShadowLightShader_PresetSpecularPasses_1x();
    ShadowLightShader_PresetEnvMapPasses_1x();
    ShadowLightShader_PresetFogPasses_1x();
    ConfigureBeamPasses();
    if (_fnv_particle_shader_renderer_level >= 2)
    {
        ShadowLightShader_PresetADPasses_2x();
        ShadowLightShader_PresetADTPasses_2x();
        SetupRenderPasses();
        ShadowLightShader_PresetDiffusePasses_2x();
        ShadowLightShader_PresetSpecularPasses_2x();
        ShadowLightShader_PresetEnvMapPasses_2x();
        InitializeBeamPasses();
        InitStageObjects();
        ShadowLightShader_PresetDepthPasses_2x();
        InitShaderConfigs();
        ShadowLightShader_PresetLocalMapPasses_2x();
        InitializeGraphicsSystems();
        ShadowLightShader_PresetWaterFogPasses_2x();
    }
    else
    {
        InitDefaultShaderPasses();
    }
    return true;
}
}  // namespace fnv_00b7a730

extern "C" void* _fnv_zlib_memset(void*, int, unsigned int);
void __cdecl FUN_00be0c00(const char* param_1, char* param_2);
int __cdecl sprintf_s(char* buf, unsigned int size, const char* fmt, ...);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
struct RefObj
{
    virtual void Va0();
    virtual void Release();
    long refCount;
};
extern RefObj* DAT_011fdd88[];
extern RefObj* DAT_011fde04[];
extern RefObj* DAT_011fde5c[];
extern int DAT_011f91c0;
struct ShaderEntry
{
    const char* f00;
    const char* f01;
    const char* f02;
    const char* f03;
    const char* f04;
    const char* f05;
    const char* f06;
    const char* f07;
    const char* f08;
    const char* f09;
    const char* f10;
    const char* f11;
    const char* f12;
    const char* f13;
    const char* f14;
    const char* f15;
    const char* f16;
    const char* f17;
    const char* f18;
};
struct B71
{
    void CreateVertexShaders();
    void* FUN_00be0fe0(char* bufA, const char** field, const char* profile, char* bufB);
};
// Fills a shader-entry table and creates/refreshes the vertex shader objects in three global arrays, releasing replaced ones.
// @fnv 0x00b71bf0
void B71::CreateVertexShaders()
{
    ShaderEntry shaderEntries[156];
    char pathBuffers[2][260];
    shaderEntries[125].f00 = "lighting\\1x\\v\\base.v.hlsl";
    shaderEntries[125].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[125].f02, 0, 0x44);
    shaderEntries[126].f00 = 0;
    shaderEntries[126].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[126].f02, 0, 0x44);
    shaderEntries[127].f00 = 0;
    shaderEntries[127].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[127].f02, 0, 0x44);
    shaderEntries[128].f00 = "lighting\\1x\\v\\diffusePt.v.hlsl";
    shaderEntries[128].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[128].f02, 0, 0x44);
    shaderEntries[129].f00 = "lighting\\1x\\v\\diffuseDir.v.hlsl";
    shaderEntries[129].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[129].f02, 0, 0x44);
    shaderEntries[130].f00 = "lighting\\1x\\v\\base.v.hlsl";
    shaderEntries[130].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[130].f02, 0, 0x44);
    shaderEntries[131].f00 = "lighting\\1x\\v\\base.v.hlsl";
    shaderEntries[131].f01 = "VC";
    shaderEntries[131].f02 = "";
    shaderEntries[131].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[131].f04, 0, 0x3c);
    shaderEntries[132].f00 = "lighting\\1x\\v\\base.v.hlsl";
    shaderEntries[132].f01 = "FACEGENBLEND";
    shaderEntries[132].f02 = "";
    shaderEntries[132].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[132].f04, 0, 0x3c);
    shaderEntries[133].f00 = "lighting\\1x\\v\\specularPt.v.hlsl";
    shaderEntries[133].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[133].f02, 0, 0x44);
    shaderEntries[134].f00 = "lighting\\1x\\v\\specularDir.v.hlsl";
    shaderEntries[134].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[134].f02, 0, 0x44);
    shaderEntries[135].f00 = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl";
    shaderEntries[135].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[135].f02, 0, 0x44);
    shaderEntries[136].f00 = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl";
    shaderEntries[136].f01 = "FOG";
    shaderEntries[136].f02 = "";
    shaderEntries[136].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[136].f04, 0, 0x3c);
    shaderEntries[137].f00 = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl";
    shaderEntries[137].f01 = "VC";
    shaderEntries[137].f02 = "";
    shaderEntries[137].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[137].f04, 0, 0x3c);
    shaderEntries[138].f00 = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl";
    shaderEntries[138].f01 = "FOG";
    shaderEntries[138].f02 = "";
    shaderEntries[138].f03 = "VC";
    shaderEntries[138].f04 = "";
    shaderEntries[138].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[138].f06, 0, 0x34);
    shaderEntries[139].f00 = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl";
    shaderEntries[139].f01 = "FACEGENBLEND";
    shaderEntries[139].f02 = "";
    shaderEntries[139].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[139].f04, 0, 0x3c);
    shaderEntries[140].f00 = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl";
    shaderEntries[140].f01 = "FACEGENBLEND";
    shaderEntries[140].f02 = "";
    shaderEntries[140].f03 = "FOG";
    shaderEntries[140].f04 = "";
    shaderEntries[140].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[140].f06, 0, 0x34);
    shaderEntries[141].f00 = "lighting\\1x\\v\\ambDiffuseDirAndPt.v.hlsl";
    shaderEntries[141].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[141].f02, 0, 0x44);
    shaderEntries[142].f00 = "lighting\\1x\\v\\base.v.hlsl";
    shaderEntries[142].f01 = "FOG";
    shaderEntries[142].f02 = "";
    shaderEntries[142].f03 = "NO_TEX";
    shaderEntries[142].f04 = "";
    shaderEntries[142].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[142].f06, 0, 0x34);
    shaderEntries[143].f00 = "lighting\\1x\\v\\base.v.hlsl";
    shaderEntries[143].f01 = "FOG";
    shaderEntries[143].f02 = "";
    shaderEntries[143].f03 = "TEX";
    shaderEntries[143].f04 = "";
    shaderEntries[143].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[143].f06, 0, 0x34);
    shaderEntries[144].f00 = "lighting\\1x\\v\\envmap.v.hlsl";
    shaderEntries[144].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[144].f02, 0, 0x44);
    shaderEntries[145].f00 = "lighting\\1x\\v\\vertDir.v.hlsl";
    shaderEntries[145].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[145].f02, 0, 0x44);
    shaderEntries[146].f00 = "lighting\\1x\\v\\vertDir.v.hlsl";
    shaderEntries[146].f01 = "VC";
    shaderEntries[146].f02 = "";
    shaderEntries[146].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[146].f04, 0, 0x3c);
    shaderEntries[147].f00 = "lighting\\1x\\v\\vertDirAndPt.v.hlsl";
    shaderEntries[147].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[147].f02, 0, 0x44);
    shaderEntries[148].f00 = "lighting\\1x\\v\\vertDirAndPt.v.hlsl";
    shaderEntries[148].f01 = "VC";
    shaderEntries[148].f02 = "";
    shaderEntries[148].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[148].f04, 0, 0x3c);
    shaderEntries[149].f00 = "lighting\\1x\\v\\base.v.hlsl";
    shaderEntries[149].f01 = "SI";
    shaderEntries[149].f02 = "";
    shaderEntries[149].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[149].f04, 0, 0x3c);
    shaderEntries[150].f00 = "lighting\\1x\\v\\land.v.hlsl";
    shaderEntries[150].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[150].f02, 0, 0x44);
    shaderEntries[151].f00 = "lighting\\1x\\v\\land.v.hlsl";
    shaderEntries[151].f01 = "LANDALPHA";
    shaderEntries[151].f02 = "";
    shaderEntries[151].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[151].f04, 0, 0x3c);
    shaderEntries[152].f00 = "lighting\\1x\\v\\land.v.hlsl";
    shaderEntries[152].f01 = "LANDALPHA";
    shaderEntries[152].f02 = "";
    shaderEntries[152].f03 = "SI";
    shaderEntries[152].f04 = "";
    shaderEntries[152].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[152].f06, 0, 0x34);
    shaderEntries[153].f00 = "lighting\\1x\\v\\land.v.hlsl";
    shaderEntries[153].f01 = "PTLIGHT";
    shaderEntries[153].f02 = "";
    shaderEntries[153].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[153].f04, 0, 0x3c);
    shaderEntries[154].f00 = "lighting\\1x\\v\\land.v.hlsl";
    shaderEntries[154].f01 = "LANDALPHA";
    shaderEntries[154].f02 = "";
    shaderEntries[154].f03 = "PTLIGHT";
    shaderEntries[154].f04 = "";
    shaderEntries[154].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[154].f06, 0, 0x34);
    shaderEntries[155].f00 = 0;
    shaderEntries[155].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[155].f02, 0, 0x44);
    shaderEntries[103].f00 = "lighting\\1x\\v\\base.v.hlsl";
    shaderEntries[103].f01 = "SKIN";
    shaderEntries[103].f02 = "";
    shaderEntries[103].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[103].f04, 0, 0x3c);
    shaderEntries[104].f00 = "lighting\\1x\\v\\base.v.hlsl";
    shaderEntries[104].f01 = "SKIN";
    shaderEntries[104].f02 = "";
    shaderEntries[104].f03 = "FOG";
    shaderEntries[104].f04 = "";
    shaderEntries[104].f05 = "NO_TEX";
    shaderEntries[104].f06 = "";
    shaderEntries[104].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[104].f08, 0, 0x2c);
    shaderEntries[105].f00 = "lighting\\1x\\v\\base.v.hlsl";
    shaderEntries[105].f01 = "SKIN";
    shaderEntries[105].f02 = "";
    shaderEntries[105].f03 = "FOG";
    shaderEntries[105].f04 = "";
    shaderEntries[105].f05 = "TEX";
    shaderEntries[105].f06 = "";
    shaderEntries[105].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[105].f08, 0, 0x2c);
    shaderEntries[106].f00 = "lighting\\1x\\v\\diffusePt.v.hlsl";
    shaderEntries[106].f01 = "SKIN";
    shaderEntries[106].f02 = "";
    shaderEntries[106].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[106].f04, 0, 0x3c);
    shaderEntries[107].f00 = "lighting\\1x\\v\\diffuseDir.v.hlsl";
    shaderEntries[107].f01 = "SKIN";
    shaderEntries[107].f02 = "";
    shaderEntries[107].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[107].f04, 0, 0x3c);
    shaderEntries[108].f00 = "lighting\\1x\\v\\base.v.hlsl";
    shaderEntries[108].f01 = "SKIN";
    shaderEntries[108].f02 = "";
    shaderEntries[108].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[108].f04, 0, 0x3c);
    shaderEntries[109].f00 = "lighting\\1x\\v\\base.v.hlsl";
    shaderEntries[109].f01 = "SKIN";
    shaderEntries[109].f02 = "";
    shaderEntries[109].f03 = "VC";
    shaderEntries[109].f04 = "";
    shaderEntries[109].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[109].f06, 0, 0x34);
    shaderEntries[110].f00 = "lighting\\1x\\v\\base.v.hlsl";
    shaderEntries[110].f01 = "SKIN";
    shaderEntries[110].f02 = "";
    shaderEntries[110].f03 = "FACEGENBLEND";
    shaderEntries[110].f04 = "";
    shaderEntries[110].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[110].f06, 0, 0x34);
    shaderEntries[111].f00 = "lighting\\1x\\v\\specularPt.v.hlsl";
    shaderEntries[111].f01 = "SKIN";
    shaderEntries[111].f02 = "";
    shaderEntries[111].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[111].f04, 0, 0x3c);
    shaderEntries[112].f00 = "lighting\\1x\\v\\specularDir.v.hlsl";
    shaderEntries[112].f01 = "SKIN";
    shaderEntries[112].f02 = "";
    shaderEntries[112].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[112].f04, 0, 0x3c);
    shaderEntries[113].f00 = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl";
    shaderEntries[113].f01 = "SKIN";
    shaderEntries[113].f02 = "";
    shaderEntries[113].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[113].f04, 0, 0x3c);
    shaderEntries[114].f00 = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl";
    shaderEntries[114].f01 = "SKIN";
    shaderEntries[114].f02 = "";
    shaderEntries[114].f03 = "VC";
    shaderEntries[114].f04 = "";
    shaderEntries[114].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[114].f06, 0, 0x34);
    shaderEntries[115].f00 = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl";
    shaderEntries[115].f01 = "SKIN";
    shaderEntries[115].f02 = "";
    shaderEntries[115].f03 = "FOG";
    shaderEntries[115].f04 = "";
    shaderEntries[115].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[115].f06, 0, 0x34);
    shaderEntries[116].f00 = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl";
    shaderEntries[116].f01 = "SKIN";
    shaderEntries[116].f02 = "";
    shaderEntries[116].f03 = "FOG";
    shaderEntries[116].f04 = "";
    shaderEntries[116].f05 = "VC";
    shaderEntries[116].f06 = "";
    shaderEntries[116].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[116].f08, 0, 0x2c);
    shaderEntries[117].f00 = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl";
    shaderEntries[117].f01 = "SKIN";
    shaderEntries[117].f02 = "";
    shaderEntries[117].f03 = "FACEGENBLEND";
    shaderEntries[117].f04 = "";
    shaderEntries[117].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[117].f06, 0, 0x34);
    shaderEntries[118].f00 = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl";
    shaderEntries[118].f01 = "SKIN";
    shaderEntries[118].f02 = "";
    shaderEntries[118].f03 = "FACEGENBLEND";
    shaderEntries[118].f04 = "";
    shaderEntries[118].f05 = "FOG";
    shaderEntries[118].f06 = "";
    shaderEntries[118].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[118].f08, 0, 0x2c);
    shaderEntries[119].f00 = "lighting\\1x\\v\\ambDiffuseDirAndPt.v.hlsl";
    shaderEntries[119].f01 = "SKIN";
    shaderEntries[119].f02 = "";
    shaderEntries[119].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[119].f04, 0, 0x3c);
    shaderEntries[120].f00 = "lighting\\1x\\v\\envmap.v.hlsl";
    shaderEntries[120].f01 = "SKIN";
    shaderEntries[120].f02 = "";
    shaderEntries[120].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[120].f04, 0, 0x3c);
    shaderEntries[121].f00 = 0;
    shaderEntries[121].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[121].f02, 0, 0x44);
    shaderEntries[122].f00 = 0;
    shaderEntries[122].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[122].f02, 0, 0x44);
    shaderEntries[123].f00 = "lighting\\1x\\v\\base.v.hlsl";
    shaderEntries[123].f01 = "SKIN";
    shaderEntries[123].f02 = "";
    shaderEntries[123].f03 = "SI";
    shaderEntries[123].f04 = "";
    shaderEntries[123].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[123].f06, 0, 0x34);
    shaderEntries[124].f00 = 0;
    shaderEntries[124].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[124].f02, 0, 0x44);
    shaderEntries[0].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[0].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[0].f02, 0, 0x44);
    shaderEntries[1].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[1].f01 = "LOD";
    shaderEntries[1].f02 = "";
    shaderEntries[1].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[1].f04, 0, 0x3c);
    shaderEntries[2].f00 = "lighting\\2x\\v\\landlod.v.hlsl";
    shaderEntries[2].f01 = "MODELSPACENORM";
    shaderEntries[2].f02 = "";
    shaderEntries[2].f03 = "LODLANDCLIP";
    shaderEntries[2].f04 = "";
    shaderEntries[2].f05 = "GEOMORPH";
    shaderEntries[2].f06 = "";
    shaderEntries[2].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[2].f08, 0, 0x2c);
    shaderEntries[3].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[3].f01 = "SKIN";
    shaderEntries[3].f02 = "";
    shaderEntries[3].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[3].f04, 0, 0x3c);
    shaderEntries[4].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[4].f01 = "PROJ_SHADOW";
    shaderEntries[4].f02 = "";
    shaderEntries[4].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[4].f04, 0, 0x3c);
    shaderEntries[5].f00 = "lighting\\2x\\v\\landlod.v.hlsl";
    shaderEntries[5].f01 = "MODELSPACENORM";
    shaderEntries[5].f02 = "";
    shaderEntries[5].f03 = "PROJ_SHADOW";
    shaderEntries[5].f04 = "";
    shaderEntries[5].f05 = "LODLANDCLIP";
    shaderEntries[5].f06 = "";
    shaderEntries[5].f07 = "GEOMORPH";
    shaderEntries[5].f08 = "";
    shaderEntries[5].f09 = 0;
    shaderEntries[5].f10 = 0;
    shaderEntries[5].f11 = 0;
    shaderEntries[5].f12 = 0;
    shaderEntries[5].f13 = 0;
    shaderEntries[5].f14 = 0;
    shaderEntries[5].f15 = 0;
    shaderEntries[5].f16 = 0;
    shaderEntries[5].f17 = 0;
    shaderEntries[5].f18 = 0;
    shaderEntries[6].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[6].f01 = "SKIN";
    shaderEntries[6].f02 = "";
    shaderEntries[6].f03 = "PROJ_SHADOW";
    shaderEntries[6].f04 = "";
    shaderEntries[6].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[6].f06, 0, 0x34);
    shaderEntries[7].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[7].f01 = "STBB";
    shaderEntries[7].f02 = "";
    shaderEntries[7].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[7].f04, 0, 0x3c);
    shaderEntries[8].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[8].f01 = "LIGHTS";
    shaderEntries[8].f02 = "2";
    shaderEntries[8].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[8].f04, 0, 0x3c);
    shaderEntries[9].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[9].f01 = "LIGHTS";
    shaderEntries[9].f02 = "2";
    shaderEntries[9].f03 = "SKIN";
    shaderEntries[9].f04 = "";
    shaderEntries[9].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[9].f06, 0, 0x34);
    shaderEntries[10].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[10].f01 = "LIGHTS";
    shaderEntries[10].f02 = "2";
    shaderEntries[10].f03 = "PROJ_SHADOW";
    shaderEntries[10].f04 = "";
    shaderEntries[10].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[10].f06, 0, 0x34);
    shaderEntries[11].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[11].f01 = "LIGHTS";
    shaderEntries[11].f02 = "2";
    shaderEntries[11].f03 = "SKIN";
    shaderEntries[11].f04 = "";
    shaderEntries[11].f05 = "PROJ_SHADOW";
    shaderEntries[11].f06 = "";
    shaderEntries[11].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[11].f08, 0, 0x2c);
    shaderEntries[12].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[12].f01 = "SPECULAR";
    shaderEntries[12].f02 = "";
    shaderEntries[12].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[12].f04, 0, 0x3c);
    shaderEntries[13].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[13].f01 = "SPECULAR";
    shaderEntries[13].f02 = "";
    shaderEntries[13].f03 = "SKIN";
    shaderEntries[13].f04 = "";
    shaderEntries[13].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[13].f06, 0, 0x34);
    shaderEntries[14].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[14].f01 = "SPECULAR";
    shaderEntries[14].f02 = "";
    shaderEntries[14].f03 = "PROJ_SHADOW";
    shaderEntries[14].f04 = "";
    shaderEntries[14].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[14].f06, 0, 0x34);
    shaderEntries[15].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[15].f01 = "SPECULAR";
    shaderEntries[15].f02 = "";
    shaderEntries[15].f03 = "SKIN";
    shaderEntries[15].f04 = "";
    shaderEntries[15].f05 = "PROJ_SHADOW";
    shaderEntries[15].f06 = "";
    shaderEntries[15].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[15].f08, 0, 0x2c);
    shaderEntries[16].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[16].f01 = "SPECULAR";
    shaderEntries[16].f02 = "";
    shaderEntries[16].f03 = "LIGHTS";
    shaderEntries[16].f04 = "2";
    shaderEntries[16].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[16].f06, 0, 0x34);
    shaderEntries[17].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[17].f01 = "SPECULAR";
    shaderEntries[17].f02 = "";
    shaderEntries[17].f03 = "LIGHTS";
    shaderEntries[17].f04 = "2";
    shaderEntries[17].f05 = "SKIN";
    shaderEntries[17].f06 = "";
    shaderEntries[17].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[17].f08, 0, 0x2c);
    shaderEntries[18].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[18].f01 = "SPECULAR";
    shaderEntries[18].f02 = "";
    shaderEntries[18].f03 = "LIGHTS";
    shaderEntries[18].f04 = "2";
    shaderEntries[18].f05 = "PROJ_SHADOW";
    shaderEntries[18].f06 = "";
    shaderEntries[18].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[18].f08, 0, 0x2c);
    shaderEntries[19].f00 = "lighting\\2x\\v\\ADTS.v.hlsl";
    shaderEntries[19].f01 = "SPECULAR";
    shaderEntries[19].f02 = "";
    shaderEntries[19].f03 = "LIGHTS";
    shaderEntries[19].f04 = "2";
    shaderEntries[19].f05 = "SKIN";
    shaderEntries[19].f06 = "";
    shaderEntries[19].f07 = "PROJ_SHADOW";
    shaderEntries[19].f08 = "";
    shaderEntries[19].f09 = 0;
    shaderEntries[19].f10 = 0;
    shaderEntries[19].f11 = 0;
    shaderEntries[19].f12 = 0;
    shaderEntries[19].f13 = 0;
    shaderEntries[19].f14 = 0;
    shaderEntries[19].f15 = 0;
    shaderEntries[19].f16 = 0;
    shaderEntries[19].f17 = 0;
    shaderEntries[19].f18 = 0;
    shaderEntries[20].f00 = "lighting\\2x\\v\\ADTS10.v.hlsl";
    shaderEntries[20].f01 = "LIGHTS";
    shaderEntries[20].f02 = "9";
    shaderEntries[20].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[20].f04, 0, 0x3c);
    shaderEntries[21].f00 = "lighting\\2x\\v\\ADTS10.v.hlsl";
    shaderEntries[21].f01 = "LIGHTS";
    shaderEntries[21].f02 = "9";
    shaderEntries[21].f03 = "SKIN";
    shaderEntries[21].f04 = "";
    shaderEntries[21].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[21].f06, 0, 0x34);
    shaderEntries[22].f00 = "lighting\\2x\\v\\ADTS10.v.hlsl";
    shaderEntries[22].f01 = "LIGHTS";
    shaderEntries[22].f02 = "4";
    shaderEntries[22].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[22].f04, 0, 0x3c);
    shaderEntries[23].f00 = "lighting\\2x\\v\\ADTS10.v.hlsl";
    shaderEntries[23].f01 = "OPT";
    shaderEntries[23].f02 = "";
    shaderEntries[23].f03 = "LIGHTS";
    shaderEntries[23].f04 = "4";
    shaderEntries[23].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[23].f06, 0, 0x34);
    shaderEntries[24].f00 = "lighting\\2x\\v\\ADTS10.v.hlsl";
    shaderEntries[24].f01 = "LIGHTS";
    shaderEntries[24].f02 = "4";
    shaderEntries[24].f03 = "SKIN";
    shaderEntries[24].f04 = "";
    shaderEntries[24].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[24].f06, 0, 0x34);
    shaderEntries[25].f00 = "lighting\\2x\\v\\ADTS10.v.hlsl";
    shaderEntries[25].f01 = "SPECULAR";
    shaderEntries[25].f02 = "";
    shaderEntries[25].f03 = "LIGHTS";
    shaderEntries[25].f04 = "4";
    shaderEntries[25].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[25].f06, 0, 0x34);
    shaderEntries[26].f00 = "lighting\\2x\\v\\ADTS10.v.hlsl";
    shaderEntries[26].f01 = "OPT";
    shaderEntries[26].f02 = "";
    shaderEntries[26].f03 = "SPECULAR";
    shaderEntries[26].f04 = "";
    shaderEntries[26].f05 = "LIGHTS";
    shaderEntries[26].f06 = "4";
    shaderEntries[26].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[26].f08, 0, 0x2c);
    shaderEntries[27].f00 = "lighting\\2x\\v\\ADTS10.v.hlsl";
    shaderEntries[27].f01 = "SPECULAR";
    shaderEntries[27].f02 = "";
    shaderEntries[27].f03 = "LIGHTS";
    shaderEntries[27].f04 = "4";
    shaderEntries[27].f05 = "SKIN";
    shaderEntries[27].f06 = "";
    shaderEntries[27].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[27].f08, 0, 0x2c);
    shaderEntries[28].f00 = "lighting\\2x\\v\\AD.v.hlsl";
    shaderEntries[28].f01 = "LIGHTS";
    shaderEntries[28].f02 = "2";
    shaderEntries[28].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[28].f04, 0, 0x3c);
    shaderEntries[29].f00 = "lighting\\2x\\v\\AD.v.hlsl";
    shaderEntries[29].f01 = "LIGHTS";
    shaderEntries[29].f02 = "2";
    shaderEntries[29].f03 = "SKIN";
    shaderEntries[29].f04 = "";
    shaderEntries[29].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[29].f06, 0, 0x34);
    shaderEntries[30].f00 = "lighting\\2x\\v\\AD.v.hlsl";
    shaderEntries[30].f01 = "LIGHTS";
    shaderEntries[30].f02 = "2";
    shaderEntries[30].f03 = "PROJ_SHADOW";
    shaderEntries[30].f04 = "";
    shaderEntries[30].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[30].f06, 0, 0x34);
    shaderEntries[31].f00 = "lighting\\2x\\v\\AD.v.hlsl";
    shaderEntries[31].f01 = "LIGHTS";
    shaderEntries[31].f02 = "2";
    shaderEntries[31].f03 = "SKIN";
    shaderEntries[31].f04 = "";
    shaderEntries[31].f05 = "PROJ_SHADOW";
    shaderEntries[31].f06 = "";
    shaderEntries[31].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[31].f08, 0, 0x2c);
    shaderEntries[32].f00 = "lighting\\2x\\v\\AD.v.hlsl";
    shaderEntries[32].f01 = "LIGHTS";
    shaderEntries[32].f02 = "3";
    shaderEntries[32].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[32].f04, 0, 0x3c);
    shaderEntries[33].f00 = "lighting\\2x\\v\\AD.v.hlsl";
    shaderEntries[33].f01 = "LIGHTS";
    shaderEntries[33].f02 = "3";
    shaderEntries[33].f03 = "SKIN";
    shaderEntries[33].f04 = "";
    shaderEntries[33].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[33].f06, 0, 0x34);
    shaderEntries[34].f00 = "lighting\\2x\\v\\AD.v.hlsl";
    shaderEntries[34].f01 = "LIGHTS";
    shaderEntries[34].f02 = "3";
    shaderEntries[34].f03 = "PROJ_SHADOW";
    shaderEntries[34].f04 = "";
    shaderEntries[34].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[34].f06, 0, 0x34);
    shaderEntries[35].f00 = "lighting\\2x\\v\\AD.v.hlsl";
    shaderEntries[35].f01 = "LIGHTS";
    shaderEntries[35].f02 = "3";
    shaderEntries[35].f03 = "SKIN";
    shaderEntries[35].f04 = "";
    shaderEntries[35].f05 = "PROJ_SHADOW";
    shaderEntries[35].f06 = "";
    shaderEntries[35].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[35].f08, 0, 0x2c);
    shaderEntries[36].f00 = "lighting\\2x\\v\\DiffusePt.v.hlsl";
    shaderEntries[36].f01 = "LIGHTS";
    shaderEntries[36].f02 = "2";
    shaderEntries[36].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[36].f04, 0, 0x3c);
    shaderEntries[37].f00 = "lighting\\2x\\v\\DiffusePt.v.hlsl";
    shaderEntries[37].f01 = "LIGHTS";
    shaderEntries[37].f02 = "2";
    shaderEntries[37].f03 = "SKIN";
    shaderEntries[37].f04 = "";
    shaderEntries[37].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[37].f06, 0, 0x34);
    shaderEntries[38].f00 = "lighting\\2x\\v\\DiffusePt.v.hlsl";
    shaderEntries[38].f01 = "LIGHTS";
    shaderEntries[38].f02 = "3";
    shaderEntries[38].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[38].f04, 0, 0x3c);
    shaderEntries[39].f00 = "lighting\\2x\\v\\DiffusePt.v.hlsl";
    shaderEntries[39].f01 = "LIGHTS";
    shaderEntries[39].f02 = "3";
    shaderEntries[39].f03 = "SKIN";
    shaderEntries[39].f04 = "";
    shaderEntries[39].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[39].f06, 0, 0x34);
    shaderEntries[40].f00 = "lighting\\2x\\v\\Specular.v.hlsl";
    shaderEntries[40].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[40].f02, 0, 0x44);
    shaderEntries[41].f00 = "lighting\\2x\\v\\Specular.v.hlsl";
    shaderEntries[41].f01 = "SKIN";
    shaderEntries[41].f02 = "";
    shaderEntries[41].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[41].f04, 0, 0x3c);
    shaderEntries[42].f00 = "lighting\\2x\\v\\Specular.v.hlsl";
    shaderEntries[42].f01 = "PROJ_SHADOW";
    shaderEntries[42].f02 = "";
    shaderEntries[42].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[42].f04, 0, 0x3c);
    shaderEntries[43].f00 = "lighting\\2x\\v\\Specular.v.hlsl";
    shaderEntries[43].f01 = "SKIN";
    shaderEntries[43].f02 = "";
    shaderEntries[43].f03 = "PROJ_SHADOW";
    shaderEntries[43].f04 = "";
    shaderEntries[43].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[43].f06, 0, 0x34);
    shaderEntries[44].f00 = "lighting\\2x\\v\\Specular.v.hlsl";
    shaderEntries[44].f01 = "POINT";
    shaderEntries[44].f02 = "";
    shaderEntries[44].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[44].f04, 0, 0x3c);
    shaderEntries[45].f00 = "lighting\\2x\\v\\Specular.v.hlsl";
    shaderEntries[45].f01 = "SKIN";
    shaderEntries[45].f02 = "";
    shaderEntries[45].f03 = "POINT";
    shaderEntries[45].f04 = "";
    shaderEntries[45].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[45].f06, 0, 0x34);
    shaderEntries[46].f00 = "lighting\\2x\\v\\Specular.v.hlsl";
    shaderEntries[46].f01 = "NUM_PT_LIGHTS";
    shaderEntries[46].f02 = "2";
    shaderEntries[46].f03 = "POINT";
    shaderEntries[46].f04 = "";
    shaderEntries[46].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[46].f06, 0, 0x34);
    shaderEntries[47].f00 = "lighting\\2x\\v\\Specular.v.hlsl";
    shaderEntries[47].f01 = "NUM_PT_LIGHTS";
    shaderEntries[47].f02 = "2";
    shaderEntries[47].f03 = "SKIN";
    shaderEntries[47].f04 = "";
    shaderEntries[47].f05 = "POINT";
    shaderEntries[47].f06 = "";
    shaderEntries[47].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[47].f08, 0, 0x2c);
    shaderEntries[48].f00 = "lighting\\2x\\v\\Specular.v.hlsl";
    shaderEntries[48].f01 = "NUM_PT_LIGHTS";
    shaderEntries[48].f02 = "3";
    shaderEntries[48].f03 = "POINT";
    shaderEntries[48].f04 = "";
    shaderEntries[48].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[48].f06, 0, 0x34);
    shaderEntries[49].f00 = "lighting\\2x\\v\\Specular.v.hlsl";
    shaderEntries[49].f01 = "NUM_PT_LIGHTS";
    shaderEntries[49].f02 = "3";
    shaderEntries[49].f03 = "SKIN";
    shaderEntries[49].f04 = "";
    shaderEntries[49].f05 = "POINT";
    shaderEntries[49].f06 = "";
    shaderEntries[49].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[49].f08, 0, 0x2c);
    shaderEntries[50].f00 = "lighting\\2x\\v\\EnvMap.v.hlsl";
    shaderEntries[50].f01 = "ENVMAP";
    shaderEntries[50].f02 = "";
    shaderEntries[50].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[50].f04, 0, 0x3c);
    shaderEntries[51].f00 = "lighting\\2x\\v\\EnvMap.v.hlsl";
    shaderEntries[51].f01 = "SKIN";
    shaderEntries[51].f02 = "";
    shaderEntries[51].f03 = "ENVMAP";
    shaderEntries[51].f04 = "";
    shaderEntries[51].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[51].f06, 0, 0x34);
    shaderEntries[52].f00 = "lighting\\2x\\v\\EnvMap.v.hlsl";
    shaderEntries[52].f01 = "ENVMAP";
    shaderEntries[52].f02 = "";
    shaderEntries[52].f03 = "EYE";
    shaderEntries[52].f04 = 0;
    shaderEntries[52].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[52].f06, 0, 0x34);
    shaderEntries[53].f00 = "lighting\\2x\\v\\land.v.hlsl";
    shaderEntries[53].f01 = "PROJ_SHADOW";
    shaderEntries[53].f02 = "";
    shaderEntries[53].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[53].f04, 0, 0x3c);
    shaderEntries[54].f00 = "lighting\\2x\\v\\land.v.hlsl";
    shaderEntries[54].f01 = "LANDALPHA";
    shaderEntries[54].f02 = "";
    shaderEntries[54].f03 = "PROJ_SHADOW";
    shaderEntries[54].f04 = "";
    shaderEntries[54].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[54].f06, 0, 0x34);
    shaderEntries[55].f00 = "lighting\\2x\\v\\landlighting.v.hlsl";
    shaderEntries[55].f01 = "DIFF";
    shaderEntries[55].f02 = "";
    shaderEntries[55].f03 = "PTLIGHT";
    shaderEntries[55].f04 = "";
    shaderEntries[55].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[55].f06, 0, 0x34);
    shaderEntries[56].f00 = "lighting\\2x\\v\\landlighting.v.hlsl";
    shaderEntries[56].f01 = "SPECULAR";
    shaderEntries[56].f02 = "";
    shaderEntries[56].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[56].f04, 0, 0x3c);
    shaderEntries[57].f00 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[57].f01, 0, 0x48);
    shaderEntries[58].f00 = "lighting\\2x\\v\\landlighting.v.hlsl";
    shaderEntries[58].f01 = "LANDALPHA";
    shaderEntries[58].f02 = "";
    shaderEntries[58].f03 = "DIFF";
    shaderEntries[58].f04 = "";
    shaderEntries[58].f05 = "PTLIGHT";
    shaderEntries[58].f06 = "";
    shaderEntries[58].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[58].f08, 0, 0x2c);
    shaderEntries[59].f00 = "lighting\\2x\\v\\landlighting.v.hlsl";
    shaderEntries[59].f01 = "LANDALPHA";
    shaderEntries[59].f02 = "";
    shaderEntries[59].f03 = "SPECULAR";
    shaderEntries[59].f04 = "";
    shaderEntries[59].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[59].f06, 0, 0x34);
    shaderEntries[60].f00 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[60].f01, 0, 0x48);
    shaderEntries[61].f00 = "lighting\\2x\\v\\landlighting.v.hlsl";
    shaderEntries[61].f01 = "SPECULAR";
    shaderEntries[61].f02 = "";
    shaderEntries[61].f03 = "PROJ_SHADOW";
    shaderEntries[61].f04 = "";
    shaderEntries[61].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[61].f06, 0, 0x34);
    shaderEntries[62].f00 = "lighting\\2x\\v\\landlighting.v.hlsl";
    shaderEntries[62].f01 = "LANDALPHA";
    shaderEntries[62].f02 = "";
    shaderEntries[62].f03 = "SPECULAR";
    shaderEntries[62].f04 = "";
    shaderEntries[62].f05 = "PROJ_SHADOW";
    shaderEntries[62].f06 = "";
    shaderEntries[62].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[62].f08, 0, 0x2c);
    shaderEntries[63].f00 = "lighting\\2x\\v\\depthmap.v.hlsl";
    shaderEntries[63].f01 = "DEPTHMAP";
    shaderEntries[63].f02 = "";
    shaderEntries[63].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[63].f04, 0, 0x3c);
    shaderEntries[64].f00 = "lighting\\2x\\v\\depthmap.v.hlsl";
    shaderEntries[64].f01 = "DEPTHMAP";
    shaderEntries[64].f02 = "";
    shaderEntries[64].f03 = "ALPHATEST";
    shaderEntries[64].f04 = "";
    shaderEntries[64].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[64].f06, 0, 0x34);
    shaderEntries[65].f00 = "lighting\\2x\\v\\depthmap.v.hlsl";
    shaderEntries[65].f01 = "DEPTHMAP";
    shaderEntries[65].f02 = "";
    shaderEntries[65].f03 = "SKIN";
    shaderEntries[65].f04 = "";
    shaderEntries[65].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[65].f06, 0, 0x34);
    shaderEntries[66].f00 = "lighting\\2x\\v\\depthmap.v.hlsl";
    shaderEntries[66].f01 = "DEPTHMAP";
    shaderEntries[66].f02 = "";
    shaderEntries[66].f03 = "SKIN";
    shaderEntries[66].f04 = "";
    shaderEntries[66].f05 = "ALPHATEST";
    shaderEntries[66].f06 = "";
    shaderEntries[66].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[66].f08, 0, 0x2c);
    shaderEntries[67].f00 = "lighting\\2x\\v\\depthmap.v.hlsl";
    shaderEntries[67].f01 = "DEPTHMAP";
    shaderEntries[67].f02 = "";
    shaderEntries[67].f03 = "WATERDEPTH";
    shaderEntries[67].f04 = "";
    shaderEntries[67].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[67].f06, 0, 0x34);
    shaderEntries[68].f00 = "lighting\\2x\\v\\renderNormals.v.hlsl";
    shaderEntries[68].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[68].f02, 0, 0x44);
    shaderEntries[69].f00 = "lighting\\2x\\v\\renderNormals.v.hlsl";
    shaderEntries[69].f01 = "SKIN";
    shaderEntries[69].f02 = "";
    shaderEntries[69].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[69].f04, 0, 0x3c);
    shaderEntries[70].f00 = "lighting\\2x\\v\\renderNormals.v.hlsl";
    shaderEntries[70].f01 = "FIRE";
    shaderEntries[70].f02 = "";
    shaderEntries[70].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[70].f04, 0, 0x3c);
    shaderEntries[71].f00 = "lighting\\2x\\v\\renderNormals.v.hlsl";
    shaderEntries[71].f01 = "CLEAR";
    shaderEntries[71].f02 = "";
    shaderEntries[71].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[71].f04, 0, 0x3c);
    shaderEntries[72].f00 = "lighting\\2x\\v\\renderNormals.v.hlsl";
    shaderEntries[72].f01 = "CLEAR";
    shaderEntries[72].f02 = "";
    shaderEntries[72].f03 = "SKIN";
    shaderEntries[72].f04 = "";
    shaderEntries[72].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[72].f06, 0, 0x34);
    shaderEntries[73].f00 = "lighting\\2x\\v\\renderDepth.v.hlsl";
    shaderEntries[73].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[73].f02, 0, 0x44);
    shaderEntries[74].f00 = "lighting\\2x\\v\\renderDepth.v.hlsl";
    shaderEntries[74].f01 = "SKIN";
    shaderEntries[74].f02 = "";
    shaderEntries[74].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[74].f04, 0, 0x3c);
    shaderEntries[75].f00 = "lighting\\2x\\v\\renderDepth.v.hlsl";
    shaderEntries[75].f01 = "MODELSPACENORM";
    shaderEntries[75].f02 = "";
    shaderEntries[75].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[75].f04, 0, 0x3c);
    shaderEntries[76].f00 = "lighting\\2x\\v\\renderVelocity.v.hlsl";
    shaderEntries[76].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[76].f02, 0, 0x44);
    shaderEntries[77].f00 = "lighting\\2x\\v\\renderVelocity.v.hlsl";
    shaderEntries[77].f01 = "SKIN";
    shaderEntries[77].f02 = "";
    shaderEntries[77].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[77].f04, 0, 0x3c);
    shaderEntries[78].f00 = "lighting\\2x\\v\\land.v.hlsl";
    shaderEntries[78].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[78].f02, 0, 0x44);
    shaderEntries[79].f00 = "lighting\\2x\\v\\land.v.hlsl";
    shaderEntries[79].f01 = "LANDALPHA";
    shaderEntries[79].f02 = "";
    shaderEntries[79].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[79].f04, 0, 0x3c);
    shaderEntries[80].f00 = "lighting\\2x\\v\\land.v.hlsl";
    shaderEntries[80].f01 = "LANDLO";
    shaderEntries[80].f02 = "";
    shaderEntries[80].f03 = "FOG";
    shaderEntries[80].f04 = "";
    shaderEntries[80].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[80].f06, 0, 0x34);
    shaderEntries[81].f00 = "lighting\\2x\\v\\land.v.hlsl";
    shaderEntries[81].f01 = "LANDALPHA";
    shaderEntries[81].f02 = "";
    shaderEntries[81].f03 = "SI";
    shaderEntries[81].f04 = "";
    shaderEntries[81].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[81].f06, 0, 0x34);
    shaderEntries[82].f00 = "lighting\\2x\\v\\land.v.hlsl";
    shaderEntries[82].f01 = "PTLIGHT";
    shaderEntries[82].f02 = "";
    shaderEntries[82].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[82].f04, 0, 0x3c);
    shaderEntries[83].f00 = "lighting\\2x\\v\\land.v.hlsl";
    shaderEntries[83].f01 = "LANDALPHA";
    shaderEntries[83].f02 = "";
    shaderEntries[83].f03 = "PTLIGHT";
    shaderEntries[83].f04 = "";
    shaderEntries[83].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[83].f06, 0, 0x34);
    shaderEntries[84].f00 = "lighting\\2x\\v\\localMap.v.hlsl";
    shaderEntries[84].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[84].f02, 0, 0x44);
    shaderEntries[85].f00 = "lighting\\2x\\v\\localMap.v.hlsl";
    shaderEntries[85].f01 = "SKIN";
    shaderEntries[85].f02 = "";
    shaderEntries[85].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[85].f04, 0, 0x3c);
    shaderEntries[86].f00 = "lighting\\2x\\v\\localMap.v.hlsl";
    shaderEntries[86].f01 = "CLEAR";
    shaderEntries[86].f02 = "";
    shaderEntries[86].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[86].f04, 0, 0x3c);
    shaderEntries[87].f00 = "lighting\\1x\\v\\texEffect.v.hlsl";
    shaderEntries[87].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[87].f02, 0, 0x44);
    shaderEntries[88].f00 = "lighting\\1x\\v\\texEffect.v.hlsl";
    shaderEntries[88].f01 = "SKIN";
    shaderEntries[88].f02 = "";
    shaderEntries[88].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[88].f04, 0, 0x3c);
    shaderEntries[89].f00 = "lighting\\2x\\v\\SimpleShadow.v.hlsl";
    shaderEntries[89].f01 = "SHADOWMAP";
    shaderEntries[89].f02 = "";
    shaderEntries[89].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[89].f04, 0, 0x3c);
    shaderEntries[90].f00 = "lighting\\2x\\v\\SimpleShadow.v.hlsl";
    shaderEntries[90].f01 = "SHADOWMAP";
    shaderEntries[90].f02 = "";
    shaderEntries[90].f03 = "SKIN";
    shaderEntries[90].f04 = "";
    shaderEntries[90].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[90].f06, 0, 0x34);
    shaderEntries[91].f00 = "lighting\\2x\\v\\SimpleShadow.v.hlsl";
    shaderEntries[91].f01 = "SHADOWMAP";
    shaderEntries[91].f02 = "";
    shaderEntries[91].f03 = "LAND";
    shaderEntries[91].f04 = "";
    shaderEntries[91].f05 = "VC";
    shaderEntries[91].f06 = "";
    shaderEntries[91].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[91].f08, 0, 0x2c);
    shaderEntries[92].f00 = "lighting\\2x\\v\\WaterFog.v.hlsl";
    shaderEntries[92].f01 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[92].f02, 0, 0x44);
    shaderEntries[93].f00 = "lighting\\2x\\v\\WaterFog.v.hlsl";
    shaderEntries[93].f01 = "SKIN";
    shaderEntries[93].f02 = "";
    shaderEntries[93].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[93].f04, 0, 0x3c);
    shaderEntries[94].f00 = "lighting\\2x\\v\\WaterFog.v.hlsl";
    shaderEntries[94].f01 = "TEXCOORD";
    shaderEntries[94].f02 = "";
    shaderEntries[94].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[94].f04, 0, 0x3c);
    shaderEntries[95].f00 = "lighting\\2x\\v\\WaterFog.v.hlsl";
    shaderEntries[95].f01 = "SKIN";
    shaderEntries[95].f02 = "";
    shaderEntries[95].f03 = "TEXCOORD";
    shaderEntries[95].f04 = "";
    shaderEntries[95].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[95].f06, 0, 0x34);
    shaderEntries[96].f00 = "lighting\\2x\\v\\WaterFog.v.hlsl";
    shaderEntries[96].f01 = "VC";
    shaderEntries[96].f02 = "";
    shaderEntries[96].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[96].f04, 0, 0x3c);
    shaderEntries[97].f00 = "lighting\\2x\\v\\WaterFog.v.hlsl";
    shaderEntries[97].f01 = "VC";
    shaderEntries[97].f02 = "";
    shaderEntries[97].f03 = "SKIN";
    shaderEntries[97].f04 = "";
    shaderEntries[97].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[97].f06, 0, 0x34);
    shaderEntries[98].f00 = "lighting\\2x\\v\\WaterFog.v.hlsl";
    shaderEntries[98].f01 = "VC";
    shaderEntries[98].f02 = "";
    shaderEntries[98].f03 = "TEXCOORD";
    shaderEntries[98].f04 = "";
    shaderEntries[98].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[98].f06, 0, 0x34);
    shaderEntries[99].f00 = "lighting\\2x\\v\\WaterFog.v.hlsl";
    shaderEntries[99].f01 = "VC";
    shaderEntries[99].f02 = "";
    shaderEntries[99].f03 = "SKIN";
    shaderEntries[99].f04 = "";
    shaderEntries[99].f05 = "TEXCOORD";
    shaderEntries[99].f06 = "";
    shaderEntries[99].f07 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[99].f08, 0, 0x2c);
    shaderEntries[100].f00 = "lighting\\2x\\v\\LandO.v.hlsl";
    shaderEntries[100].f01 = "FOG";
    shaderEntries[100].f02 = "";
    shaderEntries[100].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[100].f04, 0, 0x3c);
    shaderEntries[101].f00 = "lighting\\2x\\v\\LandO.v.hlsl";
    shaderEntries[101].f01 = "FOG";
    shaderEntries[101].f02 = "";
    shaderEntries[101].f03 = "PROJ_SHADOW";
    shaderEntries[101].f04 = "";
    shaderEntries[101].f05 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[101].f06, 0, 0x34);
    shaderEntries[102].f00 = "lighting\\2x\\v\\adts.v.hlsl";
    shaderEntries[102].f01 = "LIGHTS";
    shaderEntries[102].f02 = "0";
    shaderEntries[102].f03 = 0;
    _fnv_zlib_memset((void*)&shaderEntries[102].f04, 0, 0x3c);
    {
        int i = 0;
        ShaderEntry* e = &shaderEntries[125];
        for (; i < 31; i++, e++)
        {
            if (e->f00 != 0)
            {
                FUN_00be0c00(e->f00, pathBuffers[0]);
                sprintf_s(pathBuffers[1], 0x104, "SLS1%03i.vso", i);
                RefObj* pNewShader = (RefObj*)FUN_00be0fe0(pathBuffers[0], &e->f01, "vs_2_0", pathBuffers[1]);
                RefObj* pOldShader = DAT_011fdd88[i];
                if (pOldShader != pNewShader)
                {
                    if (pOldShader != 0)
                    {
                        if (InterlockedDecrement(&pOldShader->refCount) == 0)
                            pOldShader->Release();
                    }
                    DAT_011fdd88[i] = pNewShader;
                    if (pNewShader != 0)
                        InterlockedIncrement(&pNewShader->refCount);
                }
            }
        }
    }
    {
        int i = 0;
        ShaderEntry* e = &shaderEntries[103];
        for (; i < 22; i++, e++)
        {
            if (e->f00 != 0)
            {
                FUN_00be0c00(e->f00, pathBuffers[0]);
                sprintf_s(pathBuffers[1], 0x104, "SLS1S%03i.vso", i);
                RefObj* pNewShader = (RefObj*)FUN_00be0fe0(pathBuffers[0], &e->f01, "vs_2_0", pathBuffers[1]);
                RefObj* pOldShader = DAT_011fde04[i];
                if (pOldShader != pNewShader)
                {
                    if (pOldShader != 0)
                    {
                        if (InterlockedDecrement(&pOldShader->refCount) == 0)
                            pOldShader->Release();
                    }
                    DAT_011fde04[i] = pNewShader;
                    if (pNewShader != 0)
                        InterlockedIncrement(&pNewShader->refCount);
                }
            }
        }
    }
    if (DAT_011f91c0 >= 2)
    {
        {
            int i = 0;
            ShaderEntry* e = &shaderEntries[0];
            for (; i < 103; i++, e++)
            {
                if (e->f00 == 0)
                {
                    RefObj* pOldShader = DAT_011fde5c[i];
                    if (pOldShader != 0)
                    {
                        if (InterlockedDecrement(&pOldShader->refCount) == 0)
                            pOldShader->Release();
                        DAT_011fde5c[i] = 0;
                    }
                }
                else
                {
                    FUN_00be0c00(e->f00, pathBuffers[0]);
                    sprintf_s(pathBuffers[1], 0x104, "SLS2%03i.vso", i);
                    RefObj* pNewShader = (RefObj*)FUN_00be0fe0(pathBuffers[0], &e->f01, "vs_2_0", pathBuffers[1]);
                    RefObj* pOldShader = DAT_011fde5c[i];
                    if (pOldShader != pNewShader)
                    {
                        if (pOldShader != 0)
                        {
                            if (InterlockedDecrement(&pOldShader->refCount) == 0)
                                pOldShader->Release();
                        }
                        DAT_011fde5c[i] = pNewShader;
                        if (pNewShader != 0)
                            InterlockedIncrement(&pNewShader->refCount);
                    }
                }
            }
        }
    }
}

inline void NiD3DPixelShader::IncRefCount()
{
    NiAtomicIncrement(m_uiRefCount);
}
inline void NiD3DPixelShader::DecRefCount()
{
    if (NiAtomicSubtract(m_uiRefCount) == 0)
        DeleteThis();
}
inline void NiD3DVertexShader::IncRefCount()
{
    NiAtomicIncrement(m_uiRefCount);
}
inline void NiD3DVertexShader::DecRefCount()
{
    if (NiAtomicSubtract(m_uiRefCount) == 0)
        DeleteThis();
}

inline unsigned int NiD3DPass::GetStageCount() const
{
    return m_uiStageCount;
}
inline void NiD3DPass::AppendStage(BeamStage* stage)
{
    NiD3DPass_SetStage(m_uiCurrentStage, stage);
}
inline void NiD3DPass::SetRenderState(unsigned int state, unsigned int value, bool save)
{
    GetRenderStateGroup()->SetRenderState(state, value, save);
}
inline void NiD3DPass::SetVertexShader(NiD3DVertexShader* shader)
{
    m_spVertexShader = shader;
}
inline void NiD3DPass::SetPixelShader(NiD3DPixelShader* shader)
{
    m_spPixelShader = shader;
}

namespace fnv_00bebd20 {
typedef bool SAVETYPE;

class NiD3DBaseTexture;

class D3DRenderStateGroup
{
  public:
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();
    void SetRenderState(unsigned int uiState, unsigned int uiValue, SAVETYPE bSave);
};

class BeamStage
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    NiD3DBaseTexture* m_pkTexture;
    unsigned int m_uiTextureFormat;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
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
    unsigned int m_uiRefCount;

    static void CreateNewStage(NiPointer<BeamStage>& spNewStage);
    void ReturnStageToPool();
    void SetTexture(NiD3DBaseTexture* pkTexture)
    {
        m_pkTexture = pkTexture;
    }
    void SetTextureFlags(unsigned int uiFlags)
    {
        m_uiTextureFormat = uiFlags;
    }
    bool SetClampMode(unsigned int eMode);
    void IncRefCount()
    {
        m_uiRefCount++;
    }
    void DecRefCount()
    {
        m_uiRefCount--;
        if (m_uiRefCount == 0)
            ReturnStageToPool();
    }
};

class D3DPassObj
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int m_uiStageMask;
    unsigned int m_uiNumberOfStages;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    D3DRenderStateGroup* m_pRenderStateGroup;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    NiPointer<NiD3DVertexShader> m_spVertexShaderObject;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    NiPointer<NiD3DPixelShader> m_spPixelShaderObject;
    unsigned int unk60;
    unsigned int m_uiRefCount;

    void DestroyPass();
    unsigned int GetStageCount() const
    {
        return m_uiNumberOfStages;
    }
    unsigned int GetStageMask() const
    {
        return m_uiStageMask;
    }
    bool SetStage(unsigned int uiStageNum, BeamStage* pkStage);
    void IncRefCount()
    {
        m_uiRefCount++;
    }
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
            DestroyPass();
    }
    void SetPixelShader(NiD3DPixelShader* pkShader)
    {
        m_spPixelShaderObject = pkShader;
    }
    void SetVertexShader(NiD3DVertexShader* pkShader)
    {
        m_spVertexShaderObject = pkShader;
    }
    void SetRenderState(unsigned int uiState, unsigned int uiValue, SAVETYPE bSave)
    {
        if (!m_pRenderStateGroup)
            m_pRenderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
        m_pRenderStateGroup->SetRenderState(uiState, uiValue, bSave);
    }
    D3DRenderStateGroup* GetRSGroup()
    {
        if (!m_pRenderStateGroup)
            m_pRenderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
        return m_pRenderStateGroup;
    }
    void SetRenderState3(unsigned int uiState, unsigned int uiValue, SAVETYPE bSave)
    {
        SetRenderState(uiState, uiValue, bSave);
    }
    bool SetDestructibleData(unsigned int uiStageNum, BeamStage* pkStage)
    {
        return SetStage(uiStageNum, pkStage);
    }
    void SetPS2(NiD3DPixelShader* pkShader)
    {
        SetPixelShader(pkShader);
    }
    void SetVS2(NiD3DVertexShader* pkShader)
    {
        SetVertexShader(pkShader);
    }
    void SetRenderState2(unsigned int uiState, unsigned int uiValue, SAVETYPE bSave)
    {
        GetRSGroup()->SetRenderState(uiState, uiValue, bSave);
    }
};

void SetupStage(BeamStage* pkStage, unsigned int uiStage, unsigned int a, unsigned int b, unsigned int c);

inline void CreateStage(NiPointer<BeamStage>& spStage, unsigned int uiStage, unsigned int a, unsigned int b,
                        unsigned int c)
{
    BeamStage::CreateNewStage(spStage);
    SetupStage(spStage, uiStage, a, b, c);
}
inline void SetFlag(unsigned int& ruiFlag, unsigned int uiValue)
{
    ruiFlag = uiValue;
}
inline void SetFlag2(unsigned int& ruiFlag, unsigned int uiValue)
{
    SetFlag(ruiFlag, uiValue);
}

extern NiD3DBaseTexture* DAT_011f9534;
extern unsigned int DAT_011faccc;
extern unsigned int DAT_011facd0;
extern unsigned int DAT_011facd4;
extern unsigned int DAT_011facd8;
extern unsigned int DAT_011facdc;
extern unsigned int DAT_011facf0;
extern unsigned int DAT_011facf8;
extern unsigned int DAT_011fad04;
extern unsigned int DAT_011fad08;
extern unsigned int DAT_011fad0c;
extern unsigned int DAT_011fad10;
extern unsigned int DAT_011fad20;
extern unsigned int DAT_011fad24;
extern unsigned int DAT_011fad28;
extern unsigned int DAT_011fad34;
extern unsigned int DAT_011fad38;
extern unsigned int DAT_011fad3c;
extern unsigned int DAT_011fad4c;
extern unsigned int DAT_011fad50;
extern unsigned int DAT_011fad54;
extern unsigned int DAT_011fad60;
extern unsigned int DAT_011fad64;
extern unsigned int DAT_011fad68;
extern unsigned int DAT_011fad78;
extern unsigned int DAT_011fad7c;
extern unsigned int DAT_011fad80;
extern unsigned int DAT_011fb1b4;
extern unsigned int DAT_011fb8ac;
extern unsigned int DAT_011fb8b0;
extern unsigned int DAT_011fb8b4;
extern unsigned int DAT_011fb8b8;
extern unsigned int DAT_011fb8bc;
extern unsigned int DAT_011fb8d0;
extern unsigned int DAT_011fb8d4;
extern unsigned int DAT_011fb8d8;
extern unsigned int DAT_011fb8e4;
extern unsigned int DAT_011fb8e8;
extern unsigned int DAT_011fb8ec;
extern unsigned int DAT_011fb8f0;
extern unsigned int DAT_011fb900;
extern unsigned int DAT_011fb904;
extern unsigned int DAT_011fb908;
extern unsigned int DAT_011fb914;
extern unsigned int DAT_011fb918;
extern unsigned int DAT_011fb91c;
extern unsigned int DAT_011fb92c;
extern unsigned int DAT_011fb930;
extern unsigned int DAT_011fb934;
extern unsigned int DAT_011fb940;
extern unsigned int DAT_011fb944;
extern unsigned int DAT_011fb948;
extern unsigned int DAT_011fb958;
extern unsigned int DAT_011fb95c;
extern unsigned int DAT_011fb960;
extern unsigned int DAT_011fbd94;
extern unsigned int DAT_011fc0e0;
extern unsigned int DAT_011fc0e4;
extern unsigned int DAT_011fc0e8;
extern unsigned int DAT_011fc0ec;
extern unsigned int DAT_011fc48c;
extern unsigned int DAT_011fc490;
extern unsigned int DAT_011fc494;
extern unsigned int DAT_011fc498;
extern unsigned int DAT_011fc49c;
extern unsigned int DAT_011fc4b0;
extern unsigned int DAT_011fc4b4;
extern unsigned int DAT_011fc4b8;
extern unsigned int DAT_011fc4c4;
extern unsigned int DAT_011fc4c8;
extern unsigned int DAT_011fc4cc;
extern unsigned int DAT_011fc4d0;
extern unsigned int DAT_011fc4e0;
extern unsigned int DAT_011fc4e4;
extern unsigned int DAT_011fc4e8;
extern unsigned int DAT_011fc4f4;
extern unsigned int DAT_011fc4f8;
extern unsigned int DAT_011fc4fc;
extern unsigned int DAT_011fc50c;
extern unsigned int DAT_011fc510;
extern unsigned int DAT_011fc514;
extern unsigned int DAT_011fc520;
extern unsigned int DAT_011fc524;
extern unsigned int DAT_011fc528;
extern unsigned int DAT_011fc538;
extern unsigned int DAT_011fc53c;
extern unsigned int DAT_011fc540;
extern unsigned int DAT_011fc974;
extern unsigned int DAT_011fccc0;
extern unsigned int DAT_011fccc4;
extern unsigned int DAT_011fccc8;
extern unsigned int DAT_011fcccc;
extern unsigned int DAT_011fd06c;
extern unsigned int DAT_011fd070;
extern unsigned int DAT_011fd074;
extern unsigned int DAT_011fd078;
extern unsigned int DAT_011fd07c;
extern unsigned int DAT_011fd090;
extern unsigned int DAT_011fd094;
extern unsigned int DAT_011fd098;
extern unsigned int DAT_011fd0a4;
extern unsigned int DAT_011fd0a8;
extern unsigned int DAT_011fd0ac;
extern unsigned int DAT_011fd0b0;
extern unsigned int DAT_011fd0c0;
extern unsigned int DAT_011fd0c4;
extern unsigned int DAT_011fd0c8;
extern unsigned int DAT_011fd0d4;
extern unsigned int DAT_011fd0d8;
extern unsigned int DAT_011fd0dc;
extern unsigned int DAT_011fd0ec;
extern unsigned int DAT_011fd0f0;
extern unsigned int DAT_011fd0f4;
extern unsigned int DAT_011fd100;
extern unsigned int DAT_011fd104;
extern unsigned int DAT_011fd108;
extern unsigned int DAT_011fd118;
extern unsigned int DAT_011fd11c;
extern unsigned int DAT_011fd120;
extern unsigned int DAT_011fd554;
extern NiPointer<NiD3DVertexShader> DAT_011fdb08;
extern NiPointer<NiD3DVertexShader> DAT_011fdb0c;
extern NiPointer<NiD3DVertexShader> DAT_011fdb10;
extern NiPointer<NiD3DVertexShader> DAT_011fdb14;
extern NiPointer<NiD3DVertexShader> DAT_011fdb18;
extern NiPointer<NiD3DVertexShader> DAT_011fdb1c;
extern NiPointer<NiD3DVertexShader> DAT_011fdb20;
extern NiPointer<NiD3DVertexShader> DAT_011fdb24;
extern NiPointer<NiD3DVertexShader> DAT_011fdb28;
extern NiPointer<NiD3DVertexShader> DAT_011fdb2c;
extern NiPointer<NiD3DVertexShader> DAT_011fdb30;
extern NiPointer<NiD3DVertexShader> DAT_011fdb34;
extern NiPointer<NiD3DVertexShader> DAT_011fdb38;
extern NiPointer<NiD3DVertexShader> DAT_011fdb3c;
extern NiPointer<NiD3DVertexShader> DAT_011fdb40;
extern NiPointer<NiD3DVertexShader> DAT_011fdb44;
extern NiPointer<NiD3DVertexShader> DAT_011fdb48;
extern NiPointer<NiD3DVertexShader> DAT_011fdc20;
extern NiPointer<NiD3DVertexShader> DAT_011fdc24;
extern NiPointer<NiD3DVertexShader> DAT_011fdc28;
extern NiPointer<NiD3DVertexShader> DAT_011fdc2c;
extern NiPointer<NiD3DPixelShader> DAT_011fde5c;
extern NiPointer<NiD3DPixelShader> DAT_011fde60;
extern NiPointer<NiD3DPixelShader> DAT_011fde64;
extern NiPointer<NiD3DPixelShader> DAT_011fde68;
extern NiPointer<NiD3DPixelShader> DAT_011fde6c;
extern NiPointer<NiD3DPixelShader> DAT_011fde70;
extern NiPointer<NiD3DPixelShader> DAT_011fde74;
extern NiPointer<NiD3DPixelShader> DAT_011fde78;
extern NiPointer<NiD3DPixelShader> DAT_011fde7c;
extern NiPointer<NiD3DPixelShader> DAT_011fde80;
extern NiPointer<NiD3DPixelShader> DAT_011fde84;
extern NiPointer<NiD3DPixelShader> DAT_011fde88;
extern NiPointer<NiD3DPixelShader> DAT_011fdf58;
extern NiPointer<NiD3DPixelShader> DAT_011fdf5c;
extern NiPointer<NiD3DPixelShader> DAT_011fdf60;
extern NiPointer<NiD3DPixelShader> DAT_011fdf64;
extern NiPointer<D3DPassObj> DAT_011fe038;
extern NiPointer<D3DPassObj> DAT_011fe03c;
extern NiPointer<D3DPassObj> DAT_011fe040;
extern NiPointer<D3DPassObj> DAT_011fe044;
extern NiPointer<D3DPassObj> DAT_011fe3e4;
extern NiPointer<D3DPassObj> DAT_011fe3e8;
extern NiPointer<D3DPassObj> DAT_011fe3ec;
extern NiPointer<D3DPassObj> DAT_011fe3f0;
extern NiPointer<D3DPassObj> DAT_011fe3f4;
extern NiPointer<D3DPassObj> DAT_011fe408;
extern NiPointer<D3DPassObj> DAT_011fe40c;
extern NiPointer<D3DPassObj> DAT_011fe410;
extern NiPointer<D3DPassObj> DAT_011fe41c;
extern NiPointer<D3DPassObj> DAT_011fe420;
extern NiPointer<D3DPassObj> DAT_011fe424;
extern NiPointer<D3DPassObj> DAT_011fe428;
extern NiPointer<D3DPassObj> DAT_011fe438;
extern NiPointer<D3DPassObj> DAT_011fe43c;
extern NiPointer<D3DPassObj> DAT_011fe440;
extern NiPointer<D3DPassObj> DAT_011fe44c;
extern NiPointer<D3DPassObj> DAT_011fe450;
extern NiPointer<D3DPassObj> DAT_011fe454;
extern NiPointer<D3DPassObj> DAT_011fe464;
extern NiPointer<D3DPassObj> DAT_011fe468;
extern NiPointer<D3DPassObj> DAT_011fe46c;
extern NiPointer<D3DPassObj> DAT_011fe478;
extern NiPointer<D3DPassObj> DAT_011fe47c;
extern NiPointer<D3DPassObj> DAT_011fe480;
extern NiPointer<D3DPassObj> DAT_011fe490;
extern NiPointer<D3DPassObj> DAT_011fe494;
extern NiPointer<D3DPassObj> DAT_011fe498;
extern NiPointer<D3DPassObj> DAT_011fe8cc;

// For each global D3DPassObj, creates up to 8 stages via SetupStage, assigns shaders and render states, and sets render flags.
// @fnv 0x00bebd20
// src: COMMUNITY 0x00bebd20
void ShadowLightShader_PresetADTPasses_2x()
{
    NiPointer<D3DPassObj> spRenderPass;
    NiPointer<BeamStage> spStage;
    spRenderPass = DAT_011fe3e4;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde5c);
    spRenderPass->SetVertexShader(DAT_011fdb08);
    spRenderPass->SetRenderState(0x1b, 0, true);
    spRenderPass->SetRenderState(0xf, 0, true);
    spRenderPass->SetRenderState(7, 1, true);
    spRenderPass->SetRenderState(0x17, 4, true);
    spRenderPass->SetRenderState(0xe, 1, true);
    SetFlag(DAT_011fd06c, 0x380);
    SetFlag(DAT_011fc48c, 0x2c);
    SetFlag(DAT_011fb8ac, 0x300);
    SetFlag(DAT_011faccc, 0);
    spRenderPass = DAT_011fe3e8;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde5c);
    spRenderPass->SetVertexShader(DAT_011fdb0c);
    SetFlag(DAT_011fd070, 0x380);
    SetFlag(DAT_011fc490, 0x2c);
    SetFlag(DAT_011fb8b0, 0x300);
    SetFlag(DAT_011facd0, 0x24);
    spRenderPass = DAT_011fe3ec;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde60);
    spRenderPass->SetVertexShader(DAT_011fdb10);
    SetFlag(DAT_011fd074, 0x380);
    SetFlag(DAT_011fc494, 0x2c);
    SetFlag(DAT_011fb8b4, 0x300);
    SetFlag(DAT_011facd4, 0x24);
    spRenderPass = DAT_011fe8cc;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 3, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 3, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde78);
    spRenderPass->SetVertexShader(DAT_011fdb28);
    spRenderPass->SetRenderState(0x1b, 0, true);
    spRenderPass->SetRenderState(7, 1, true);
    spRenderPass->SetRenderState(0x17, 4, true);
    spRenderPass->SetRenderState(0xe, 1, true);
    SetFlag(DAT_011fd554, 0x380);
    SetFlag(DAT_011fc974, 0x40002c);
    SetFlag(DAT_011fbd94, 0x300);
    SetFlag(DAT_011fb1b4, 0x400028);
    spRenderPass = DAT_011fe3f0;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spStage->SetClampMode(0);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spStage->SetClampMode(0);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 1, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde64);
    spRenderPass->SetVertexShader(DAT_011fdb14);
    spRenderPass->SetRenderState(0x1b, 0, true);
    spRenderPass->SetRenderState(0xf, 0, true);
    spRenderPass->SetRenderState(7, 1, true);
    spRenderPass->SetRenderState(0x17, 4, true);
    spRenderPass->SetRenderState(0xe, 1, true);
    SetFlag(DAT_011fd078, 0x420384);
    SetFlag(DAT_011fc498, 0x20002c);
    SetFlag(DAT_011fb8b8, 0x20380);
    SetFlag(DAT_011facd8, 0x2c);
    spRenderPass = DAT_011fe3f4;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde5c);
    spRenderPass->SetVertexShader(DAT_011fdb18);
    spRenderPass->SetRenderState(0x1b, 0, true);
    spRenderPass->SetRenderState(0xf, 0, true);
    spRenderPass->SetRenderState(7, 1, true);
    spRenderPass->SetRenderState(0x17, 4, true);
    spRenderPass->SetRenderState(0xe, 1, true);
    SetFlag(DAT_011fd07c, 0x380);
    SetFlag(DAT_011fc49c, 0x3c);
    SetFlag(DAT_011fb8bc, 0x300);
    SetFlag(DAT_011facdc, 0xc);
    spRenderPass = DAT_011fe408;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde5c);
    spRenderPass->SetVertexShader(DAT_011fdb2c);
    spRenderPass->SetRenderState(0x1b, 0, true);
    spRenderPass->SetRenderState(0xf, 0, true);
    spRenderPass->SetRenderState(7, 1, true);
    spRenderPass->SetRenderState(0x17, 4, true);
    spRenderPass->SetRenderState(0xe, 1, true);
    SetFlag(DAT_011fd090, 0x380);
    SetFlag(DAT_011fc4b0, 0x3c);
    SetFlag(DAT_011fb8d0, 0x300);
    SetFlag(DAT_011facf0, 0xc);
    spRenderPass = DAT_011fe40c;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde68);
    spRenderPass->SetVertexShader(DAT_011fdb08);
    spRenderPass->SetRenderState(0x1b, 0, true);
    spRenderPass->SetRenderState(0xf, 0, true);
    spRenderPass->SetRenderState(7, 1, true);
    spRenderPass->SetRenderState(0x17, 4, true);
    spRenderPass->SetRenderState(0xe, 1, true);
    SetFlag(DAT_011fd094, 0xb80);
    SetFlag(DAT_011fc4b4, 0x2c);
    SetFlag(DAT_011fb8d4, 0x308);
    spRenderPass = DAT_011fe410;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde68);
    spRenderPass->SetVertexShader(DAT_011fdb18);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd098, 0xb80);
    SetFlag(DAT_011fc4b8, 0x3c);
    SetFlag(DAT_011fb8d8, 0x300);
    SetFlag(DAT_011facf8, 0xc);
    spRenderPass = DAT_011fe41c;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde68);
    spRenderPass->SetVertexShader(DAT_011fdb2c);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd0a4, 0xb80);
    SetFlag(DAT_011fc4c4, 0x3c);
    SetFlag(DAT_011fb8e4, 0x300);
    SetFlag(DAT_011fad04, 0xc);
    spRenderPass = DAT_011fe420;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde6c);
    spRenderPass->SetVertexShader(DAT_011fdb1c);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd0a8, 0x3f0);
    SetFlag(DAT_011fc4c8, 0x2c);
    SetFlag(DAT_011fb8e8, 0x360);
    SetFlag(DAT_011fad08, 8);
    spRenderPass = DAT_011fe424;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde70);
    spRenderPass->SetVertexShader(DAT_011fdb20);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd0ac, 0x4203f0);
    SetFlag(DAT_011fc4cc, 0x2c);
    SetFlag(DAT_011fb8ec, 0x20360);
    SetFlag(DAT_011fad0c, 8);
    spRenderPass = DAT_011fe428;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde6c);
    spRenderPass->SetVertexShader(DAT_011fdb24);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd0b0, 0x3f0);
    SetFlag(DAT_011fc4d0, 0x3c);
    SetFlag(DAT_011fb8f0, 0x360);
    SetFlag(DAT_011fad10, 0xc);
    spRenderPass = DAT_011fe438;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde6c);
    spRenderPass->SetVertexShader(DAT_011fdb30);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd0c0, 0x3f0);
    SetFlag(DAT_011fc4e0, 0x3c);
    SetFlag(DAT_011fb900, 0x360);
    SetFlag(DAT_011fad20, 0xc);
    spRenderPass = DAT_011fe43c;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde74);
    spRenderPass->SetVertexShader(DAT_011fdb1c);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd0c4, 0xbf0);
    SetFlag(DAT_011fc4e4, 0x2c);
    SetFlag(DAT_011fb904, 0x360);
    SetFlag(DAT_011fad24, 8);
    spRenderPass = DAT_011fe440;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde74);
    spRenderPass->SetVertexShader(DAT_011fdb24);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd0c8, 0xbf0);
    SetFlag(DAT_011fc4e8, 0x3c);
    SetFlag(DAT_011fb908, 0x360);
    SetFlag(DAT_011fad28, 0xc);
    spRenderPass = DAT_011fe44c;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde74);
    spRenderPass->SetVertexShader(DAT_011fdb30);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd0d4, 0xbf0);
    SetFlag(DAT_011fc4f4, 0x3c);
    SetFlag(DAT_011fb914, 0x360);
    SetFlag(DAT_011fad34, 0xc);
    spRenderPass = DAT_011fe450;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde7c);
    spRenderPass->SetVertexShader(DAT_011fdb34);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd0d8, 0x380);
    SetFlag(DAT_011fc4f8, 0x2c);
    SetFlag(DAT_011fb918, 0x300);
    SetFlag(DAT_011fad38, 0);
    spRenderPass = DAT_011fe454;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde7c);
    spRenderPass->SetVertexShader(DAT_011fdb38);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd0dc, 0x380);
    SetFlag(DAT_011fc4fc, 0x3c);
    SetFlag(DAT_011fb91c, 0x300);
    SetFlag(DAT_011fad3c, 4);
    spRenderPass = DAT_011fe464;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde7c);
    spRenderPass->SetVertexShader(DAT_011fdb3c);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd0ec, 0x380);
    SetFlag(DAT_011fc50c, 0x3c);
    SetFlag(DAT_011fb92c, 0x300);
    SetFlag(DAT_011fad4c, 4);
    spRenderPass = DAT_011fe468;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde80);
    spRenderPass->SetVertexShader(DAT_011fdb34);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd0f0, 0xb80);
    SetFlag(DAT_011fc510, 0x2c);
    SetFlag(DAT_011fb930, 0x300);
    SetFlag(DAT_011fad50, 0);
    spRenderPass = DAT_011fe46c;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde80);
    spRenderPass->SetVertexShader(DAT_011fdb38);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd0f4, 0xb80);
    SetFlag(DAT_011fc514, 0x3c);
    SetFlag(DAT_011fb934, 0x300);
    SetFlag(DAT_011fad54, 4);
    spRenderPass = DAT_011fe478;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde80);
    spRenderPass->SetVertexShader(DAT_011fdb3c);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd100, 0xb80);
    SetFlag(DAT_011fc520, 0x3c);
    SetFlag(DAT_011fb940, 0x300);
    SetFlag(DAT_011fad60, 4);
    spRenderPass = DAT_011fe47c;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde84);
    spRenderPass->SetVertexShader(DAT_011fdb40);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd104, 0x3f0);
    SetFlag(DAT_011fc524, 0x2c);
    SetFlag(DAT_011fb944, 0x360);
    SetFlag(DAT_011fad64, 0);
    spRenderPass = DAT_011fe480;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde84);
    spRenderPass->SetVertexShader(DAT_011fdb44);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd108, 0x3f0);
    SetFlag(DAT_011fc528, 0x3c);
    SetFlag(DAT_011fb948, 0x360);
    SetFlag(DAT_011fad68, 4);
    spRenderPass = DAT_011fe490;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde84);
    spRenderPass->SetVertexShader(DAT_011fdb48);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd118, 0x3f0);
    SetFlag(DAT_011fc538, 0x3c);
    SetFlag(DAT_011fb958, 0x360);
    SetFlag(DAT_011fad78, 4);
    spRenderPass = DAT_011fe494;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde88);
    spRenderPass->SetVertexShader(DAT_011fdb40);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd11c, 0xbf0);
    SetFlag(DAT_011fc53c, 0x2c);
    SetFlag(DAT_011fb95c, 0x360);
    SetFlag(DAT_011fad7c, 0);
    spRenderPass = DAT_011fe498;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde88);
    spRenderPass->SetVertexShader(DAT_011fdb44);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd120, 0xbf0);
    SetFlag(DAT_011fc540, 0x3c);
    SetFlag(DAT_011fb960, 0x360);
    SetFlag(DAT_011fad80, 4);
    spRenderPass = DAT_011fe498;
    if (spRenderPass->GetStageCount() < 8)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(0, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 1, 1, 2, 1);
        spRenderPass->SetStage(1, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 2, 1, 2, 1);
        spRenderPass->SetStage(2, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 3, 1, 2, 1);
        spRenderPass->SetStage(3, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 4, 1, 2, 1);
        spRenderPass->SetStage(4, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 5, 3, 0, 1);
        spStage->m_pkTexture = DAT_011f9534;
        spStage->m_uiTextureFormat = 1;
        spRenderPass->SetStage(5, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 6, 1, 2, 1);
        spRenderPass->SetStage(6, spStage);
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 7, 3, 0, 1);
        spRenderPass->SetStage(7, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fde88);
    spRenderPass->SetVertexShader(DAT_011fdb44);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fd120, 0xbf0);
    SetFlag(DAT_011fc540, 0x3c);
    SetFlag(DAT_011fb960, 0x360);
    SetFlag(DAT_011fad80, 4);
    spRenderPass = DAT_011fe038;
    if (spRenderPass->GetStageCount() < 1)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(spRenderPass->m_uiStageMask, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fdf58);
    spRenderPass->SetVertexShader(DAT_011fdc20);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fccc0, 0x4080);
    SetFlag(DAT_011fc0e0, 0);
    spRenderPass = DAT_011fe03c;
    if (spRenderPass->GetStageCount() < 1)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(spRenderPass->m_uiStageMask, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fdf5c);
    spRenderPass->SetVertexShader(DAT_011fdc24);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 1, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fccc4, 0x4080);
    SetFlag(DAT_011fc0e4, 0);
    spRenderPass = DAT_011fe040;
    if (spRenderPass->GetStageCount() < 1)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(spRenderPass->m_uiStageMask, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fdf60);
    spRenderPass->SetVertexShader(DAT_011fdc28);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 0, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fccc8, 0x8880);
    SetFlag(DAT_011fc0e8, 0);
    spRenderPass = DAT_011fe044;
    if (spRenderPass->GetStageCount() < 1)
    {
        BeamStage::CreateNewStage(spStage);
        SetupStage(spStage, 0, 1, 2, 1);
        spRenderPass->SetStage(spRenderPass->m_uiStageMask, spStage);
    }
    spRenderPass->SetPixelShader(DAT_011fdf64);
    spRenderPass->SetVertexShader(DAT_011fdc2c);
    spRenderPass->SetRenderState2(0x1b, 0, true);
    spRenderPass->SetRenderState2(0xf, 1, true);
    spRenderPass->SetRenderState2(7, 1, true);
    spRenderPass->SetRenderState2(0x17, 4, true);
    spRenderPass->SetRenderState2(0xe, 1, true);
    SetFlag(DAT_011fcccc, 0x8880);
    SetFlag(DAT_011fc0ec, 0);
}
}  // namespace fnv_00bebd20

struct GraphicsResource
{
    virtual void UnknownMethod();
    virtual void ReleaseSelf();
    volatile long refCount;
    void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            ReleaseSelf();
    }
};
struct GraphicsManager
{
    void SetNodeValue(unsigned int setting, unsigned int mode, unsigned int enabled);
};
struct RefSlot
{
    GraphicsResource* m_pObject;
    RefSlot& operator=(GraphicsResource* object)
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
struct GraphicsSystem
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int device14;
    unsigned int version18;
    unsigned int GetVersion() const
    {
        return version18;
    }
    unsigned int unk1c, unk20, unk24, unk28, unk2c;
    GraphicsManager* manager30;
    unsigned int unk34, unk38, unk3c, unk40;
    RefSlot material44;
    unsigned int unk48, unk4c, unk50, unk54, unk58;
    RefSlot material5c;
    unsigned int unk60;
    unsigned int strongCount64;
    void NiD3DPass_SetStage(unsigned int device, unsigned int value);
    void FUN_00e80190();
};
struct TemporaryResource
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int strongCount60;
    void NiD3DTextureStage_ReturnStageToPool();
    void DecRefCount()
    {
        if (--strongCount60 == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
struct ScopedSystem
{
    GraphicsSystem* ptr;
    ScopedSystem() : ptr(0)
    {}
    explicit ScopedSystem(GraphicsSystem* p) : ptr(p)
    {
        if (ptr)
            ++ptr->strongCount64;
    }
    ~ScopedSystem()
    {
        if (ptr && --ptr->strongCount64 == 0)
            ptr->FUN_00e80190();
    }
    void reset(GraphicsSystem* p)
    {
        if (p != ptr)
        {
            if (ptr && --ptr->strongCount64 == 0)
                ptr->FUN_00e80190();
            ptr = p;
            if (ptr)
                ++ptr->strongCount64;
        }
    }
    void resetFromGlobal(GraphicsSystem* const& p)
    {
        if (ptr != p)
        {
            if (ptr && --ptr->strongCount64 == 0)
                ptr->FUN_00e80190();
            ptr = p;
            if (ptr)
                ++ptr->strongCount64;
        }
    }
    GraphicsSystem* operator->() const
    {
        return ptr;
    }
};
struct ScopedTemporary
{
    TemporaryResource* ptr;
    ScopedTemporary() : ptr(0)
    {}
    ~ScopedTemporary()
    {
        if (ptr)
            ptr->DecRefCount();
    }
};
extern GraphicsSystem* DAT_011fe938;
extern GraphicsSystem* DAT_011fe93c;
extern GraphicsResource* DAT_011fdfb8;
extern GraphicsResource* DAT_011fdfbc;
extern GraphicsResource* DAT_011fdc6c;
extern int DAT_011fd5c0, DAT_011fc9e0, DAT_011fd5c4, DAT_011fc9e4;
extern "C" void __cdecl AssignStageFromPool(ScopedTemporary* out);
extern "C" void __cdecl ConfigureBeamStage(TemporaryResource* res, unsigned int a, unsigned int b, unsigned int c,
                                           unsigned int d);
extern "C" GraphicsManager* __cdecl FUN_00e7f5d0();
// For each of two global graphics systems, creates temporary resources when version < 2, assigns materials, and applies a fixed list of manager settings.
// @fnv 0x00c00be0
void __cdecl InitializeGraphicsSystems()
{
    ScopedSystem systemScope;
    ScopedTemporary temporary;
    systemScope.reset(DAT_011fe938);
    if (systemScope->GetVersion() < 2)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        systemScope->NiD3DPass_SetStage(systemScope->device14, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        systemScope->NiD3DPass_SetStage(systemScope->device14, (unsigned int)temporary.ptr);
    }
    systemScope->material5c = DAT_011fdfb8;
    systemScope->material44 = DAT_011fdc6c;
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(0x1b, 1, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(0x13, 5, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(0x14, 6, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(0xab, 1, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(0xf, 0, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(7, 1, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(0x17, 3, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(0xe, 0, 1);
    DAT_011fd5c0 = DAT_011fc9e0 = 0;
    systemScope.resetFromGlobal(DAT_011fe93c);
    if (systemScope->GetVersion() < 2)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        systemScope->NiD3DPass_SetStage(systemScope->device14, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        systemScope->NiD3DPass_SetStage(systemScope->device14, (unsigned int)temporary.ptr);
    }
    systemScope->material5c = DAT_011fdfbc;
    systemScope->material44 = DAT_011fdc6c;
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(0x1b, 1, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(0x13, 5, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(0x14, 6, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(0xab, 1, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(0xf, 0, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(7, 1, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(0x17, 3, 1);
    if (!systemScope->manager30)
        systemScope->manager30 = FUN_00e7f5d0();
    systemScope->manager30->SetNodeValue(0xe, 0, 1);
    DAT_011fd5c4 = DAT_011fc9e4 = 0;
}

inline NiPoint2 NiPoint2::operator-(const NiPoint2& b) const
{
    NiPoint2 r = *this;
    r.x -= b.x;
    r.y -= b.y;
    return r;
}
inline NiPoint2 NiPoint2::operator*(float s) const
{
    NiPoint2 r = *this;
    r.x *= s;
    r.y *= s;
    return r;
}
inline NiPoint2 NiPoint2::operator+(const NiPoint2& b) const
{
    NiPoint2 r = b;
    r.x += x;
    r.y += y;
    return r;
}
// Exe 0x00b791f0: unit-local Vector4f view; declarations and layout are preserved.
struct ShadowlightshaderVector4fView
{
    float x, y, z, w;
    ShadowlightshaderVector4fView(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
struct Params
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    float value80, value84, value88, x, y, z, w, a, b;
};
struct Gate
{
    int unk00, unk04;
    bool enabled;
};

extern float DAT_011f940c, DAT_011f94ac;
extern float DAT_011ad838;
extern const float DAT_011ad808;
extern NiPoint2 DAT_011f962c, DAT_011f9634;
extern bool DAT_011f94aa;
float __cdecl BSMAX_00404010(float, float);
float __cdecl BSMIN(float, float);
// @fnv 0x00b791f0
// src: COMMUNITY 0x00b791f0
void __stdcall ShadowLightShader_SetupGeometryConstants_LODLandParams(unsigned int mode, Params* first, Params* second)
{
    if (!reinterpret_cast<Gate*>(DAT_011fec2c.m_pObject)->enabled)
        return;
    if (mode == 254)
    {
        (*reinterpret_cast<ShadowlightshaderVector4fView*>(const_cast<float*>(DAT_011fa0b0))) =
            ShadowlightshaderVector4fView(first->value80, DAT_011ad808, 0.0f, 0.0f);
        return;
    }
    if (mode == 97)
    {
        (*reinterpret_cast<ShadowlightshaderVector4fView*>(const_cast<float*>(DAT_011fa0b0))) = ShadowlightshaderVector4fView(1.0f, 0.0f, 0.0f, 0.0f);
        return;
    }
    if (mode == 560)
    {
        struct Triple
        {
            float x, y, z;
        };
        Triple pos = *reinterpret_cast<Triple*>(&second->x);
        float ratio = (DAT_011f940c - DAT_011f94ac) / (DAT_011ad838 * 5.0);
        ratio = BSMIN(1.0f, BSMAX_00404010(0.0f, ratio));
        NiPoint2 uv = (DAT_011f962c - DAT_011f9634) * ratio + DAT_011f9634;
        if (ratio == 1.0f)
            DAT_011f94aa = false;
        (*reinterpret_cast<ShadowlightshaderVector4fView*>(const_cast<float*>(DAT_011fa0b0))) = *reinterpret_cast<ShadowlightshaderVector4fView*>(&first->z);
        reinterpret_cast<ShadowlightshaderVector4fView*>(const_cast<float*>(DAT_011fa0b0))->z = uv.x - pos.x;
        reinterpret_cast<ShadowlightshaderVector4fView*>(const_cast<float*>(DAT_011fa0b0))->w = uv.y - pos.y;
    }
}

struct NLPt3
{
    float x, y, z;
    NLPt3()
    {}
    NLPt3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    float Dot(const NLPt3& p) const
    {
        const float& rz = z;
        return x * p.x + y * p.y + rz * p.z;
    }
};

struct NLPlane
{
    NLPt3 normal;
    float constant;
    NLPlane()
    {}
    NLPlane(float a, float b, float c, float d) : normal(a, b, c), constant(d)
    {}
};

extern NLPt3 DAT_011fa2a0;
extern NLPlane DAT_011f9604;
extern float DAT_011f9614;
extern float DAT_011f9618;

// @fnv 0x00b79730
void __cdecl UpdatePlaneFromPoint()
{
    if (reinterpret_cast<char*>(DAT_011fec7c.m_pObject)[8])
    {

        NLPt3 pt(DAT_011fa2a0.x, DAT_011fa2a0.y, DAT_011fa2a0.z);
        NLPlane plane;
        plane = DAT_011f9604;
        NLPt3 normal = DAT_011f9604.normal;
        float i = plane.normal.Dot(pt);
        NLPlane outPlane(normal.x, normal.y, normal.z, i - plane.constant);
        *(NLPlane*)DAT_011fd8e4 = outPlane;

        float m_fEndValue = DAT_011f9618;
        float dot = DAT_011f9614;
        if (m_fEndValue == 0.0f && dot == 0.0f)
        {
            *(NLPlane*)DAT_011fd8c4 = NLPlane(0.0f, 0.0f, -1.0f, 0.0f);
        }
        else
        {
            *(NLPlane*)DAT_011fd8c4 = NLPlane(m_fEndValue, m_fEndValue - dot, 1.0f, 1.0f);
        }
    }
}

struct ShaderBase
{
    ShaderBase();
    virtual ~ShaderBase();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    NiPointer<NiRefObject> resource28;
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
};
struct ShaderVector
{
    float x, y, z, w;
    ShaderVector(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
extern ShaderVector shaderConstant;
extern float DAT_012023e0;
struct FUN_00b79b00 : ShaderBase
{
    int mode;
    NiPointer<NiRefObject> resource6c, resource70, resource74, resource78;
    NiPointer<NiRefObject> resource7c, resource80, resource84, resource88;
    virtual ~FUN_00b79b00();
    FUN_00b79b00(NiRefObject*, NiRefObject*, NiRefObject*, NiRefObject*);
};
// @fnv 0x00b79b00
FUN_00b79b00::FUN_00b79b00(NiRefObject* apResourceA, NiRefObject* apResourceB, NiRefObject* apResourceC,
                           NiRefObject* apResourceD)
{
    mode = 1;
    resource28 = apResourceA;
    resource6c = apResourceA;
    resource70 = apResourceB;
    resource74 = apResourceC;
    resource78 = apResourceD;
    resource80 = 0;
    resource7c = 0;
    resource88 = 0;
    resource84 = 0;
    shaderConstant = ShaderVector(1.0f / DAT_012023e0, 0, 0, 0);
    unk60 = 0;
}

namespace fnv_00b7a380 {

struct FUN_00e76700_desc
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035(int a0, int a1, int a2, int a3, int a4);
    virtual void v036();
    virtual void v037(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
};
extern void* DAT_011f9508;
FUN_00e76700_desc* __cdecl NiDX9ShaderDeclaration_Create(void* apRenderer, int aiType, int aiFlag);

class FUN_00b79b00
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048(FUN_00e76700_desc* apDesc);
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    static void* operator new(unsigned int size)
    {
        return BSFaceGenMorphData::operator new(size);
    }
    FUN_00b79b00(FUN_00e76700_desc* ap0, FUN_00e76700_desc* ap1, FUN_00e76700_desc* ap2, FUN_00e76700_desc* ap3);
    char pad[0x88];
};

// Builds four morph descriptors via FUN_00e76700, fills them with v035/v037 entries, creates a FUN_00b79b00 from them, runs its setup calls and returns it.
// @fnv 0x00b7a380
// src: COMMUNITY 0x00b7a380
FUN_00b79b00* __cdecl ShadowLightShader_CreateShader()
{
    FUN_00e76700_desc* pDesc0 = NiDX9ShaderDeclaration_Create(DAT_011f9508, 6, 1);
    FUN_00e76700_desc* pDesc1 = NiDX9ShaderDeclaration_Create(DAT_011f9508, 8, 1);
    FUN_00e76700_desc* pDesc2 = NiDX9ShaderDeclaration_Create(DAT_011f9508, 3, 1);
    FUN_00e76700_desc* pDesc3 = NiDX9ShaderDeclaration_Create(DAT_011f9508, 8, 1);
    pDesc0->v035(0, 0, 0, 2, 0);
    pDesc0->v035(1, 3, 3, 2, 0);
    pDesc0->v035(2, 5, 4, 3, 0);
    pDesc0->v035(3, 7, 5, 1, 0);
    pDesc0->v035(4, 14, 13, 2, 0);
    pDesc0->v035(5, 15, 14, 2, 0);
    pDesc0->v045();
    pDesc1->v035(0, 0, 0, 2, 0);
    pDesc1->v035(1, 1, 1, 3, 0);
    pDesc1->v035(2, 2, 2, 4, 0);
    pDesc1->v035(3, 3, 3, 2, 0);
    pDesc1->v035(4, 5, 4, 3, 0);
    pDesc1->v035(5, 7, 5, 1, 0);
    pDesc1->v035(6, 14, 13, 2, 0);
    pDesc1->v035(7, 15, 14, 2, 0);
    pDesc1->v045();
    pDesc2->v035(0, 0, 0, 2, 0);
    pDesc2->v035(1, 3, 5, 1, 0);
    pDesc2->v037(0, 2, 5, (int)0x80000000, 0, 5, 1, 0);
    pDesc2->v045();
    pDesc3->v035(0, 0, 0, 2, 0);
    pDesc3->v035(1, 3, 3, 2, 0);
    pDesc3->v035(2, 5, 4, 3, 0);
    pDesc3->v035(3, 7, 5, 1, 0);
    pDesc3->v035(4, 14, 13, 2, 0);
    pDesc3->v035(5, 15, 14, 2, 0);
    pDesc3->v037(0, 6, 8, (int)0x80000000, 3, 5, 1, 0);
    pDesc3->v037(0, 7, 9, (int)0x80000001, 3, 5, 2, 0);
    pDesc3->v045();
    FUN_00b79b00* pShader = new FUN_00b79b00(pDesc0, pDesc1, pDesc2, pDesc3);
    pShader->v019();
    pShader->v081();
    pShader->v084();
    pShader->v071();
    pShader->v048(pDesc0);
    return pShader;
}
}  // namespace fnv_00b7a380

inline void NiRefObj_shadowlightshader::DeleteThis() throw()
{
    typedef void (__thiscall* DeleteFunction)(NiRefObj_shadowlightshader*);
    (*reinterpret_cast<DeleteFunction**>(this))[1](this);
}
struct Counter
{
    unsigned int v;
    Counter& operator--()
    {
        --v;
        return *this;
    }
    operator unsigned int() const
    {
        return v;
    }
};
struct TmpA
{
    int unk00[24];
};
struct Tmp : TmpA, Counter
{
    void NiD3DTextureStage_ReturnStageToPool();
    void DecRef()
    {
        if (--*(Counter*)this == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
struct State
{
    void SetNodeValue(int s, int v, int f);
};
struct Pass
{
    int unk00[5];
    int m_14;
    unsigned int m_18;
    int unk1c[5];
    State* m_30;
    int unk34[4];
    NiRefObj_shadowlightshader* m_44;
    int unk48[5];
    NiRefObj_shadowlightshader* m_5c;
    int unk60;
    unsigned int m_ref;
    __forceinline void IncRefCount() { ++m_ref; }
    __forceinline void DecRefCount() { if (--m_ref == 0) FUN_00e80190(); }
    void FUN_00e80190();
    void NiD3DPass_SetStage(int a, Tmp* t);
    State* GetState()
    {
        if (!m_30)
            m_30 = (State*)FUN_00e7f5d0();
        return m_30;
    }
    static void Assign(NiRefObj_shadowlightshader*& d, NiRefObj_shadowlightshader* s)
    {
        NiRefObj_shadowlightshader* old = d;
        if (old != s)
        {
            if (old && InterlockedDecrement(&old->m_ref) == 0)
                old->DeleteThis();
            d = s;
            if (s)
                InterlockedIncrement(&s->m_ref);
        }
    }
    void SetTex0x5c(NiRefObj_shadowlightshader* p)
    {
        Assign(m_5c, p);
    }
    void SetTex0x44(NiRefObj_shadowlightshader* p)
    {
        Assign(m_44, p);
    }
};
using ::NiPointer;
template <class T> struct NiPtr2
{
    T* p;
    NiPtr2() : p(0)
    {}
    ~NiPtr2()
    {
        if (p)
            p->DecRef();
    }
    operator T*()
    {
        return p;
    }
};
void AssignStageFromPool(NiPtr2<Tmp>* out);
void ConfigureBeamStage(Tmp* t, bool a, bool b, int c, bool d);
extern NiPointer<Pass> DAT_011fe01c;
extern NiPointer<Pass> DAT_011fe048;
extern NiPointer<Pass> DAT_011fe04c;
extern NiPointer<Pass> DAT_011fe158;
extern NiPointer<Pass> DAT_011fe15c;
extern NiPointer<Pass> DAT_011fe160;
extern NiPointer<Pass> DAT_011fe164;
extern NiPointer<Pass> DAT_011fe168;
extern NiPointer<Pass> DAT_011fe16c;
extern NiPointer<Pass> DAT_011fe170;
extern NiPointer<Pass> DAT_011fe174;
extern NiPointer<Pass> DAT_011fe17c;
extern NiPointer<Pass> DAT_011fe180;
extern NiPointer<Pass> DAT_011fe184;
extern NiPointer<Pass> DAT_011feb50;
extern NiPointer<Pass> DAT_011feb54;
extern NiRefObj_shadowlightshader* DAT_011fda48;
extern NiRefObj_shadowlightshader* DAT_011fdad8;
extern NiRefObj_shadowlightshader* DAT_011fdadc;
extern NiRefObj_shadowlightshader* DAT_011fdae0;
extern NiRefObj_shadowlightshader* DAT_011fdd5c;
extern NiRefObj_shadowlightshader* DAT_011fdd60;
extern NiRefObj_shadowlightshader* DAT_011fdd64;
extern NiRefObj_shadowlightshader* DAT_011fddcc;
extern NiRefObj_shadowlightshader* DAT_011fdde8;
extern NiRefObj_shadowlightshader* DAT_011fde54;
extern NiRefObj_shadowlightshader* DAT_011fde64;
extern NiRefObj_shadowlightshader* DAT_011fdff4;
extern unsigned int DAT_011fa930;
extern unsigned int DAT_011fa934;
extern unsigned int DAT_011faa44;
extern unsigned int DAT_011faa4c;
extern unsigned int DAT_011faa54;
extern unsigned int DAT_011faa5c;
extern unsigned int DAT_011fb438;
extern unsigned int DAT_011fb43c;
extern unsigned int DAT_011fb644;
extern unsigned int DAT_011fc0c4;
extern unsigned int DAT_011fc0f0;
extern unsigned int DAT_011fc0f4;
extern unsigned int DAT_011fc200;
extern unsigned int DAT_011fc204;
extern unsigned int DAT_011fc208;
extern unsigned int DAT_011fc20c;
extern unsigned int DAT_011fc210;
extern unsigned int DAT_011fc214;
extern unsigned int DAT_011fc218;
extern unsigned int DAT_011fc21c;
extern unsigned int DAT_011fc224;
extern unsigned int DAT_011fc228;
extern unsigned int DAT_011fc22c;
extern unsigned int DAT_011fcbf8;
extern unsigned int DAT_011fcbfc;
extern unsigned int DAT_011fcca4;
extern unsigned int DAT_011fccd0;
extern unsigned int DAT_011fccd4;
extern unsigned int DAT_011fcde0;
extern unsigned int DAT_011fcde4;
extern unsigned int DAT_011fcde8;
extern unsigned int DAT_011fcdec;
extern unsigned int DAT_011fcdf0;
extern unsigned int DAT_011fcdf4;
extern unsigned int DAT_011fcdf8;
extern unsigned int DAT_011fcdfc;
extern unsigned int DAT_011fce04;
extern unsigned int DAT_011fce08;
extern unsigned int DAT_011fce0c;
extern unsigned int DAT_011fd7d8;
extern unsigned int DAT_011fd7dc;

// @fnv 0x00be22b0
// src: COMMUNITY 0x00be22b0
void ShadowLightShader_PresetAmbientPasses_1x()
{
    NiPointer<Pass> pass;
    NiPtr2<Tmp> tmp;
    pass = DAT_011fe01c;
    unsigned int n = pass->m_18;
    if (n < 1)
    {
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
    }
    pass->SetTex0x5c((NiRefObj_shadowlightshader*)DAT_011fdd88[0]);
    pass->SetTex0x44(DAT_011fda48);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 2, 1);
    pass->GetState()->SetNodeValue(0xe, 0, 1);
    pass->GetState()->SetNodeValue(0x16, 1, 1);
    DAT_011fcca4 = 0x800;
    DAT_011fc0c4 = 4;
    pass = DAT_011fe158;
    if (pass->m_18 < 1)
    {
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
    }
    pass->SetTex0x5c((NiRefObj_shadowlightshader*)DAT_011fdd88[0]);
    pass->SetTex0x44(DAT_011fda48);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 1, 1);
    DAT_011fcde0 = 0;
    DAT_011fc200 = 4;
    pass = DAT_011fe17c;
    if (pass->m_18 < 1)
    {
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
    }
    pass->SetTex0x5c(DAT_011fde64);
    pass->SetTex0x44(DAT_011fdd5c);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 1, 1);
    DAT_011fce04 = 0x420304;
    DAT_011fc224 = 4;
    DAT_011fb644 = 0x20304;
    pass = DAT_011fe180;
    if (pass->m_18 < 1)
    {
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
    }
    pass->SetTex0x5c(DAT_011fddcc);
    pass->SetTex0x44(DAT_011fdd60);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 1, 1);
    DAT_011fce08 = 0x300;
    DAT_011fc228 = 4;
    pass = DAT_011fe184;
    if (pass->m_18 < 1)
    {
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
    }
    pass->SetTex0x5c(DAT_011fdff4);
    pass->SetTex0x44(DAT_011fdd64);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 1, 1);
    DAT_011fce0c = 0x300;
    DAT_011fc22c = 4;
    pass = DAT_011fe15c;
    if (pass->m_18 < 1)
    {
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
    }
    pass->SetTex0x5c(DAT_011fdde8);
    pass->SetTex0x44(DAT_011fdad8);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 1, 1);
    DAT_011fcde4 = 0;
    DAT_011fc204 = 0x14;
    DAT_011faa44 = 4;
    pass = DAT_011fe160;
    if (pass->m_18 < 1)
    {
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
    }
    pass->SetTex0x5c((NiRefObj_shadowlightshader*)DAT_011fdd88[0]);
    pass->SetTex0x44(DAT_011fda48);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 1, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 1, 1);
    DAT_011fcde8 = 0;
    DAT_011fc208 = 4;
    pass = DAT_011fe164;
    if (pass->m_18 < 2)
    {
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
    }
    pass->SetTex0x5c(DAT_011fdde8);
    pass->SetTex0x44(DAT_011fdad8);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 1, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 1, 1);
    DAT_011fcdec = 0;
    DAT_011fc20c = 0x14;
    DAT_011faa4c = 4;
    pass = DAT_011fe168;
    if (pass->m_18 < 1)
    {
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
    }
    pass->SetTex0x5c((NiRefObj_shadowlightshader*)DAT_011fde04[0]);
    pass->SetTex0x44(DAT_011fda48);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 1, 1);
    DAT_011fcdf0 = 0x800;
    DAT_011fc210 = 4;
    pass = DAT_011fe16c;
    if (pass->m_18 < 1)
    {
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
    }
    pass->SetTex0x5c(DAT_011fde54);
    pass->SetTex0x44(DAT_011fdad8);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 1, 1);
    DAT_011fcdf4 = 0x800;
    DAT_011fc214 = 0x14;
    DAT_011faa54 = 4;
    pass = DAT_011fe170;
    if (pass->m_18 < 1)
    {
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
    }
    pass->SetTex0x5c((NiRefObj_shadowlightshader*)DAT_011fde04[0]);
    pass->SetTex0x44(DAT_011fda48);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 1, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 1, 1);
    DAT_011fcdf8 = 0x800;
    DAT_011fc218 = 4;
    pass = DAT_011fe174;
    if (pass->m_18 < 2)
    {
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 1, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
    }
    pass->SetTex0x5c(DAT_011fde54);
    pass->SetTex0x44(DAT_011fdad8);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 1, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 1, 1);
    DAT_011fcdfc = 0x800;
    DAT_011fc21c = 0x14;
    DAT_011faa5c = 4;
    pass = DAT_011feb50;
    if (pass->m_18 < 1)
    {
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
    }
    pass->SetTex0x5c(DAT_011fdde8);
    pass->SetTex0x44(DAT_011fdadc);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 1, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 0, 1);
    DAT_011fd7d8 = 0;
    DAT_011fcbf8 = 0x14;
    DAT_011fb438 = 4;
    pass = DAT_011feb54;
    if (pass->m_18 < 1)
    {
        AssignStageFromPool(&tmp);
        ConfigureBeamStage(tmp, 0, 1, 2, 1);
        pass->NiD3DPass_SetStage(pass->m_14, tmp);
    }
    pass->SetTex0x5c(DAT_011fde54);
    pass->SetTex0x44(DAT_011fdadc);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 1, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 0, 1);
    DAT_011fd7dc = 0x800;
    DAT_011fcbfc = 0x14;
    DAT_011fb43c = 4;
    pass = DAT_011fe048;
    pass->SetTex0x5c(DAT_011fdde8);
    pass->SetTex0x44(DAT_011fdae0);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 1, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 0, 1);
    DAT_011fccd0 = 0;
    DAT_011fc0f0 = 0x14;
    DAT_011fa930 = 4;
    pass = DAT_011fe04c;
    pass->SetTex0x5c(DAT_011fde54);
    pass->SetTex0x44(DAT_011fdae0);
    pass->GetState()->SetNodeValue(0x1b, 0, 1);
    pass->GetState()->SetNodeValue(0xf, 1, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(0x17, 4, 1);
    pass->GetState()->SetNodeValue(0xe, 0, 1);
    DAT_011fccd4 = 0x800;
    DAT_011fc0f4 = 0x14;
    DAT_011fa934 = 4;
}

extern GraphicsSystem* DAT_011fe1e8;
extern GraphicsSystem* DAT_011fe1ec;
extern GraphicsResource* DAT_011fddc8;
extern GraphicsResource* DAT_011fdabc;
extern GraphicsResource* DAT_011fde44;
extern unsigned int DAT_011f9534;
extern unsigned int DAT_011f9538;
extern unsigned int DAT_011f950c;
extern unsigned int DAT_011fce70, DAT_011fc290, DAT_011fce74, DAT_011fc294;

// Configures two graphics systems: sets materials and manager entries, and for version < 4 creates and registers four temporary resources per system.
// @fnv 0x00be7420
void __cdecl InitGraphicsResources()
{
    ScopedSystem system;
    ScopedTemporary temporary;
    system.reset(DAT_011fe1e8);

    if (system->GetVersion() < 4)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temporary.ptr);

        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 3, 2, 1);
        *(unsigned int*)((char*)temporary.ptr + 8) = DAT_011f9534;
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temporary.ptr);

        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 3, 2, 1);
        *(unsigned int*)((char*)temporary.ptr + 8) = DAT_011f9538;
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temporary.ptr);

        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        *(unsigned int*)((char*)temporary.ptr + 8) = DAT_011f950c;
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fddc8;
    system->material44 = DAT_011fdabc;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fce70 = 128;
    DAT_011fc290 = 12;

    system.resetFromGlobal(DAT_011fe1ec);
    if (system->GetVersion() < 4)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 3, 2, 1);
        *(unsigned int*)((char*)temporary.ptr + 8) = DAT_011f9534;
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 3, 2, 1);
        *(unsigned int*)((char*)temporary.ptr + 8) = DAT_011f9538;
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        *(unsigned int*)((char*)temporary.ptr + 8) = DAT_011f950c;
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fde44;
    system->material44 = DAT_011fdabc;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fce74 = 0x880;
    DAT_011fc294 = 12;
}

extern GraphicsSystem* DAT_011fe4a8;
extern GraphicsSystem* DAT_011fe4b0;
extern GraphicsSystem* DAT_011fe4ac;
extern GraphicsSystem* DAT_011fe4b4;
extern GraphicsResource* DAT_011fdd98;
extern GraphicsResource* DAT_011fde14;
extern GraphicsResource* DAT_011fdd94;
extern GraphicsResource* DAT_011fde10;
extern GraphicsResource* DAT_011fda50;
extern GraphicsResource* DAT_011fda4c;
extern unsigned int DAT_011fd130;
extern unsigned int DAT_011fd138;
extern unsigned int DAT_011fd134;
extern unsigned int DAT_011fd13c;
extern unsigned int DAT_011fc550;
extern unsigned int DAT_011fc558;
extern unsigned int DAT_011fc554;
extern unsigned int DAT_011fc55c;
extern unsigned int DAT_011fad90;
extern unsigned int DAT_011fad98;
extern unsigned int DAT_011fad94;
extern unsigned int DAT_011fad9c;
extern unsigned int DAT_011f9534;
extern unsigned int DAT_011f9538;
extern unsigned int DAT_011f950c;
// @fnv 0x00be78e0
// src: COMMUNITY 0x00be78e0
void __cdecl ShadowLightShader_PresetDiffuseDirPasses_1x()
{
    ScopedSystem system;
    ScopedTemporary temp;
    system.resetFromGlobal(DAT_011fe4a8);
    if (system->GetVersion() < 1)
    {
        AssignStageFromPool(&temp);
        ConfigureBeamStage(temp.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temp.ptr);
    }
    system->material5c = DAT_011fdd98;
    system->material44 = DAT_011fda50;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(20, 2, 1);
    DAT_011fd130 = 128;
    DAT_011fc550 = 8;
    DAT_011fad90 = 8;
    system.resetFromGlobal(DAT_011fe4b0);
    if (system->GetVersion() < 1)
    {
        AssignStageFromPool(&temp);
        ConfigureBeamStage(temp.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temp.ptr);
    }
    system->material5c = DAT_011fde14;
    system->material44 = DAT_011fda50;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(20, 2, 1);
    DAT_011fd138 = 2176;
    DAT_011fc558 = 8;
    DAT_011fad98 = 8;
    system.resetFromGlobal(DAT_011fe4ac);
    if (system->GetVersion() < 4)
    {
        AssignStageFromPool(&temp);
        ConfigureBeamStage(temp.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temp.ptr);
        AssignStageFromPool(&temp);
        ConfigureBeamStage(temp.ptr, 1, 3, 2, 1);
        temp.ptr->unk08 = DAT_011f9534;
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temp.ptr);
        AssignStageFromPool(&temp);
        ConfigureBeamStage(temp.ptr, 2, 3, 2, 1);
        temp.ptr->unk08 = DAT_011f9538;
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temp.ptr);
        AssignStageFromPool(&temp);
        ConfigureBeamStage(temp.ptr, 3, 1, 2, 1);
        temp.ptr->unk08 = DAT_011f950c;
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temp.ptr);
    }
    system->material5c = DAT_011fdd94;
    system->material44 = DAT_011fda4c;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(20, 2, 1);
    DAT_011fd134 = 128;
    DAT_011fc554 = 8;
    DAT_011fad94 = 8;
    system.resetFromGlobal(DAT_011fe4b4);
    if (system->GetVersion() < 4)
    {
        AssignStageFromPool(&temp);
        ConfigureBeamStage(temp.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temp.ptr);
        AssignStageFromPool(&temp);
        ConfigureBeamStage(temp.ptr, 1, 3, 2, 1);
        temp.ptr->unk08 = DAT_011f9534;
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temp.ptr);
        AssignStageFromPool(&temp);
        ConfigureBeamStage(temp.ptr, 2, 3, 2, 1);
        temp.ptr->unk08 = DAT_011f9538;
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temp.ptr);
        AssignStageFromPool(&temp);
        ConfigureBeamStage(temp.ptr, 3, 1, 2, 1);
        temp.ptr->unk08 = DAT_011f950c;
        system->NiD3DPass_SetStage(system->device14, (unsigned int)temp.ptr);
    }
    system->material5c = DAT_011fde10;
    system->material44 = DAT_011fda4c;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(20, 2, 1);
    DAT_011fd13c = 2176;
    DAT_011fc55c = 8;
    DAT_011fad9c = 8;
}

namespace ShaderVariants {
struct RefObject
{
    virtual void slot0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ShaderRefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->m_iObjectReferenceCount);
        }
    }
};
struct RenderStateBlock
{
    void SetNodeValue(unsigned int, unsigned int, bool);
};
RenderStateBlock* FUN_00e7f5d0();
struct ShaderStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
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
    int references;
    void NiD3DTextureStage_ReturnStageToPool();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
struct ShaderStagePointer
{
    ShaderStage* object;
    ShaderStagePointer() : object(0)
    {}
    ~ShaderStagePointer()
    {
        if (object)
            object->Release();
    }
};
void AssignStageFromPool(ShaderStagePointer*);
void ConfigureBeamStage(ShaderStage*, unsigned int, unsigned int, unsigned int, bool);
extern unsigned int DAT_011f9534;
struct ShaderPass
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStateBlock* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    ShaderRefPointer pixelShader;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ShaderRefPointer vertexShader;
    unsigned int unk60;
    int references;
    __forceinline unsigned int Count()
    {
        return stageCount;
    }
    void FUN_00e80190();
    void NiD3DPass_SetStage(unsigned int, ShaderStage*);
    __forceinline RenderStateBlock* GetState()
    {
        if (!state)
            state = FUN_00e7f5d0();
        return state;
    }
};
struct ShaderPassPointer
{
    ShaderPass* object;
    ShaderPassPointer() : object(0)
    {}
    ~ShaderPassPointer()
    {
        if (object && --object->references == 0)
            object->FUN_00e80190();
    }
    __forceinline void operator=(ShaderPass* const& value)
    {
        if (object != value)
        {
            if (object && --object->references == 0)
                object->FUN_00e80190();
            object = value;
            if (object)
                ++object->references;
        }
    }
    __forceinline ShaderPass* operator->()
    {
        return object;
    }
};
extern RefObject* DAT_011fda54;
extern RefObject* DAT_011fda58;
extern RefObject* DAT_011fda5c;
extern RefObject* DAT_011fda60;
extern RefObject* DAT_011fdd9c;
extern RefObject* DAT_011fdda0;
extern RefObject* DAT_011fdda4;
extern RefObject* DAT_011fde18;
extern RefObject* DAT_011fde1c;
extern RefObject* DAT_011fde20;
extern ShaderPass* DAT_011fe520;
extern ShaderPass* DAT_011fe524;
extern ShaderPass* DAT_011fe528;
extern ShaderPass* DAT_011fe52c;
extern ShaderPass* DAT_011fe530;
extern ShaderPass* DAT_011fe534;
extern ShaderPass* DAT_011fe538;
extern ShaderPass* DAT_011fe540;
extern unsigned int DAT_011fc5c8;
extern unsigned int DAT_011fc5cc;
extern unsigned int DAT_011fc5d0;
extern unsigned int DAT_011fc5d4;
extern unsigned int DAT_011fc5d8;
extern unsigned int DAT_011fc5dc;
extern unsigned int DAT_011fc5e0;
extern unsigned int DAT_011fc5e8;
extern unsigned int DAT_011fd1a8;
extern unsigned int DAT_011fd1ac;
extern unsigned int DAT_011fd1b0;
extern unsigned int DAT_011fd1b4;
extern unsigned int DAT_011fd1b8;
extern unsigned int DAT_011fd1bc;
extern unsigned int DAT_011fd1c0;
extern unsigned int DAT_011fd1c8;
// @fnv 0x00be7f40
// src: COMMUNITY 0x00be7f40
void ShadowLightShader_PresetTexturePasses_1x()
{
    ShaderPassPointer pass;
    ShaderStagePointer stage;
    pass = DAT_011fe520;
    if (pass->Count() < 1)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fdd9c;
    pass->pixelShader = DAT_011fda54;
    pass->GetState()->SetNodeValue(19, 9, 1);
    pass->GetState()->SetNodeValue(20, 1, 1);
    DAT_011fd1a8 = 0;
    DAT_011fc5c8 = 0;
    pass = DAT_011fe524;
    if (pass->Count() < 3)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fdda4;
    pass->pixelShader = DAT_011fda5c;
    pass->GetState()->SetNodeValue(19, 9, 1);
    pass->GetState()->SetNodeValue(20, 1, 1);
    DAT_011fd1ac = 0;
    DAT_011fc5cc = 0;
    pass = DAT_011fe528;
    if (pass->Count() < 2)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fdda0;
    pass->pixelShader = DAT_011fda60;
    pass->GetState()->SetNodeValue(19, 9, 1);
    pass->GetState()->SetNodeValue(20, 1, 1);
    DAT_011fd1b0 = 0;
    DAT_011fc5d0 = 16;
    pass = DAT_011fe52c;
    if (pass->Count() < 1)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fde18;
    pass->pixelShader = DAT_011fda54;
    pass->GetState()->SetNodeValue(19, 9, 1);
    pass->GetState()->SetNodeValue(20, 1, 1);
    DAT_011fd1b4 = 2048;
    DAT_011fc5d4 = 0;
    pass = DAT_011fe530;
    if (pass->Count() < 1)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fdda0;
    pass->pixelShader = DAT_011fda58;
    pass->GetState()->SetNodeValue(19, 9, 1);
    pass->GetState()->SetNodeValue(20, 1, 1);
    DAT_011fd1b8 = 0;
    DAT_011fc5d8 = 0;
    pass = DAT_011fe534;
    if (pass->Count() < 1)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fde1c;
    pass->pixelShader = DAT_011fda58;
    pass->GetState()->SetNodeValue(19, 9, 1);
    pass->GetState()->SetNodeValue(20, 1, 1);
    DAT_011fd1bc = 2048;
    DAT_011fc5dc = 0;
    pass = DAT_011fe538;
    if (pass->Count() < 3)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fde20;
    pass->pixelShader = DAT_011fda5c;
    pass->GetState()->SetNodeValue(19, 9, 1);
    pass->GetState()->SetNodeValue(20, 1, 1);
    DAT_011fd1c0 = 2048;
    DAT_011fc5e0 = 0;
    pass = DAT_011fe540;
    if (pass->Count() < 2)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fde1c;
    pass->pixelShader = DAT_011fda60;
    pass->GetState()->SetNodeValue(19, 9, 1);
    pass->GetState()->SetNodeValue(20, 1, 1);
    DAT_011fd1c8 = 2048;
    DAT_011fc5e8 = 16;
}

}

namespace fnv_00be8960 {
struct RefObject
{
    virtual void slot0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ShaderRefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->m_iObjectReferenceCount);
        }
    }
};
struct RenderStateBlock
{
    void SetNodeValue(unsigned int, unsigned int, bool);
};
RenderStateBlock* FUN_00e7f5d0();
struct ShaderStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
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
    int references;
    void NiD3DTextureStage_ReturnStageToPool();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
struct ShaderStagePointer
{
    ShaderStage* object;
    ShaderStagePointer() : object(0)
    {}
    ~ShaderStagePointer()
    {
        if (object)
            object->Release();
    }
};
void AssignStageFromPool(ShaderStagePointer*);
void ConfigureBeamStage(ShaderStage*, unsigned int, unsigned int, unsigned int, bool);
extern unsigned int DAT_011f9534;
struct ShaderPass
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStateBlock* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    ShaderRefPointer pixelShader;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ShaderRefPointer vertexShader;
    unsigned int unk60;
    int references;
    __forceinline unsigned int Count()
    {
        return stageCount;
    }
    void FUN_00e80190();
    void NiD3DPass_SetStage(unsigned int, ShaderStage*);
    __forceinline RenderStateBlock* GetState()
    {
        if (!state)
            state = FUN_00e7f5d0();
        return state;
    }
};
struct ShaderPassPointer
{
    ShaderPass* object;
    ShaderPassPointer() : object(0)
    {}
    ~ShaderPassPointer()
    {
        if (object && --object->references == 0)
            object->FUN_00e80190();
    }
    __forceinline void operator=(ShaderPass* const& value)
    {
        if (object != value)
        {
            if (object && --object->references == 0)
                object->FUN_00e80190();
            object = value;
            if (object)
                ++object->references;
        }
    }
    __forceinline ShaderPass* operator->()
    {
        return object;
    }
};
extern ShaderPass* DAT_011fe548;
extern ShaderPass* DAT_011fe54c;
extern ShaderPass* DAT_011fe550;
extern ShaderPass* DAT_011fe554;
extern RefObject* DAT_011fddac;
extern RefObject* DAT_011fda68;
extern RefObject* DAT_011fdda8;
extern RefObject* DAT_011fda64;
extern RefObject* DAT_011fde28;
extern RefObject* DAT_011fde24;
extern unsigned int DAT_011f9538;
extern unsigned int DAT_011f950c;
extern unsigned int DAT_011fd1d0;
extern unsigned int DAT_011fc5f0;
extern unsigned int DAT_011fd1d4;
extern unsigned int DAT_011fc5f4;
extern unsigned int DAT_011fd1d8;
extern unsigned int DAT_011fc5f8;
extern unsigned int DAT_011fd1dc;
extern unsigned int DAT_011fc5fc;
// @fnv 0x00be8960
// src: COMMUNITY 0x00be8960
void ShadowLightShader_PresetSpecularPasses_1x()
{
    ShaderPassPointer pass;
    ShaderStagePointer stage;
    pass = DAT_011fe548;
    if (pass->Count() < 1)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fddac;
    pass->pixelShader = DAT_011fda68;
    pass->GetState()->SetNodeValue(19, 2, 1);
    pass->GetState()->SetNodeValue(20, 2, 1);
    DAT_011fd1d0 = 0x480;
    DAT_011fc5f0 = 8;
    pass = DAT_011fe54c;
    if (pass->Count() < 4)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 3, 2, true);
        stage.object->texture = DAT_011f9534;
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 3, 2, true);
        stage.object->texture = DAT_011f9538;
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 3, 1, 2, true);
        stage.object->texture = DAT_011f950c;
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fdda8;
    pass->pixelShader = DAT_011fda64;
    pass->GetState()->SetNodeValue(19, 2, 1);
    pass->GetState()->SetNodeValue(20, 2, 1);
    DAT_011fd1d4 = 0x480;
    DAT_011fc5f4 = 8;
    pass = DAT_011fe550;
    if (pass->Count() < 1)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fde28;
    pass->pixelShader = DAT_011fda68;
    pass->GetState()->SetNodeValue(19, 2, 1);
    pass->GetState()->SetNodeValue(20, 2, 1);
    DAT_011fd1d8 = 0xc80;
    DAT_011fc5f8 = 8;
    pass = DAT_011fe554;
    if (pass->Count() < 4)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 3, 2, true);
        stage.object->texture = DAT_011f9534;
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 3, 2, true);
        stage.object->texture = DAT_011f9538;
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 3, 1, 2, true);
        stage.object->texture = DAT_011f950c;
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fde24;
    pass->pixelShader = DAT_011fda64;
    pass->GetState()->SetNodeValue(19, 2, 1);
    pass->GetState()->SetNodeValue(20, 2, 1);
    DAT_011fd1dc = 0xc80;
    DAT_011fc5fc = 8;
}
}  // namespace fnv_00be8960

extern GraphicsSystem* DAT_011fe908;
extern GraphicsSystem* DAT_011fe90c;
extern GraphicsSystem* DAT_011fe910;
extern GraphicsSystem* DAT_011fe914;
extern GraphicsResource* DAT_011fddd4;
extern GraphicsResource* DAT_011fde48;
extern GraphicsResource* DAT_011fdac8;
extern GraphicsResource* DAT_011fdacc;
extern unsigned int DAT_011fd58c;
extern unsigned int DAT_011fd590;
extern unsigned int DAT_011fd594;
extern unsigned int DAT_011fd598;
extern unsigned int DAT_011fc9ac;
extern unsigned int DAT_011fc9b0;
extern unsigned int DAT_011fc9b4;
extern unsigned int DAT_011fc9b8;
extern unsigned int DAT_011fb1ec;
extern unsigned int DAT_011fb1f0;
extern unsigned int DAT_011fb1f4;
extern unsigned int DAT_011fb1f8;

// @fnv 0x00be8fb0
// src: COMMUNITY 0x00be8fb0
void __cdecl ShadowLightShader_PresetEnvMapPasses_1x()
{
    ScopedSystem system;
    ScopedTemporary temporary;

    system.resetFromGlobal(DAT_011fe908);
    if (system->GetVersion() < 4)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_011fddd4;
    system->material44 = DAT_011fdac8;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(20, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 3, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 0, 1);
    DAT_011fd58c = 1028;
    DAT_011fc9ac = 36;
    DAT_011fb1ec = 4;

    system.resetFromGlobal(DAT_011fe90c);
    if (system->GetVersion() < 4)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_011fddd4;
    system->material44 = DAT_011fdacc;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(20, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 3, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 0, 1);
    DAT_011fd590 = 1028;
    DAT_011fc9b0 = 36;
    DAT_011fb1f0 = 4;

    system.resetFromGlobal(DAT_011fe910);
    if (system->GetVersion() < 4)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_011fde48;
    system->material44 = DAT_011fdac8;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(20, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 3, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 0, 1);
    DAT_011fd594 = 3076;
    DAT_011fc9b4 = 36;
    DAT_011fb1f4 = 4;

    system.resetFromGlobal(DAT_011fe914);
    if (system->GetVersion() < 4)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(system->device14, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_011fde48;
    system->material44 = DAT_011fdacc;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(20, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 3, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 0, 1);
    DAT_011fd598 = 3076;
    DAT_011fc9b8 = 36;
    DAT_011fb1f8 = 4;
}

namespace fnv_00beb070 {
struct RefObject
{
    virtual void slot0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ShaderRefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->m_iObjectReferenceCount);
        }
    }
};
struct RenderStateBlock
{
    void SetNodeValue(unsigned int, unsigned int, bool);
};
RenderStateBlock* FUN_00e7f5d0();
struct ShaderStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
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
    int references;
    void NiD3DTextureStage_ReturnStageToPool();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
struct ShaderStagePointer
{
    ShaderStage* object;
    ShaderStagePointer() : object(0)
    {}
    ~ShaderStagePointer()
    {
        if (object)
            object->Release();
    }
};
void AssignStageFromPool(ShaderStagePointer*);
void ConfigureBeamStage(ShaderStage*, unsigned int, unsigned int, unsigned int, bool);
extern unsigned int DAT_011f9534;
struct ShaderPass
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStateBlock* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    ShaderRefPointer pixelShader;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ShaderRefPointer vertexShader;
    unsigned int unk60;
    int references;
    __forceinline unsigned int Count()
    {
        return stageCount;
    }
    void FUN_00e80190();
    void NiD3DPass_SetStage(unsigned int, ShaderStage*);
    __forceinline void SetState(unsigned int key, unsigned int value, bool save)
    {
        if (!state)
            state = FUN_00e7f5d0();
        state->SetNodeValue(key, value, save);
    }
    __forceinline RenderStateBlock* GetState()
    {
        if (!state)
            state = FUN_00e7f5d0();
        return state;
    }
};
struct ShaderPassPointer
{
    ShaderPass* object;
    ShaderPassPointer() : object(0)
    {}
    ~ShaderPassPointer()
    {
        if (object && --object->references == 0)
            object->FUN_00e80190();
    }
    __forceinline void operator=(ShaderPass* const& value)
    {
        if (object != value)
        {
            if (object && --object->references == 0)
                object->FUN_00e80190();
            object = value;
            if (object)
                ++object->references;
        }
    }
    __forceinline ShaderPass* operator->()
    {
        return object;
    }
};
extern ShaderPass* DAT_011fdffc;
extern ShaderPass* DAT_011fe000;
extern ShaderPass* DAT_011fe004;
extern ShaderPass* DAT_011fe008;
extern ShaderPass* DAT_011fe00c;
extern RefObject* DAT_011fdd88;
extern RefObject* DAT_011fde04;
extern RefObject* DAT_011fda48;
extern float DAT_01200458;
extern unsigned int DAT_011fcc84;
extern unsigned int DAT_011fcc88;
extern unsigned int DAT_011fcc8c;
extern unsigned int DAT_011fcc90;
extern unsigned int DAT_011fcc94;
extern unsigned int DAT_011fc0a4;
extern unsigned int DAT_011fc0a8;
extern unsigned int DAT_011fc0ac;
extern unsigned int DAT_011fc0b0;
extern unsigned int DAT_011fc0b4;
// @fnv 0x00beb070
// src: COMMUNITY 0x00beb070
void ShadowLightShader_PresetZOnlyPasses_1x()
{
    ShaderPassPointer pass;
    ShaderStagePointer stage;
    pass = DAT_011fdffc;
    pass->vertexShader = DAT_011fdd88;
    pass->pixelShader = DAT_011fda48;
    pass->GetState()->SetNodeValue(27, 0, 1);
    pass->GetState()->SetNodeValue(15, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(23, 4, 1);
    pass->GetState()->SetNodeValue(14, 1, 1);
    pass->GetState()->SetNodeValue(168, 0, 1);
    DAT_011fcc84 = 0;
    DAT_011fc0a4 = 0;
    pass = DAT_011fe000;
    pass->vertexShader = DAT_011fdd88;
    pass->pixelShader = DAT_011fda48;
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 1, 2, true);
    pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    pass->GetState()->SetNodeValue(27, 0, 1);
    pass->GetState()->SetNodeValue(15, 1, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(23, 4, 1);
    pass->GetState()->SetNodeValue(14, 1, 1);
    pass->GetState()->SetNodeValue(168, 0, 1);
    DAT_011fcc88 = 0;
    DAT_011fc0a8 = 0;
    pass = DAT_011fe004;
    pass->vertexShader = DAT_011fde04;
    pass->pixelShader = DAT_011fda48;
    pass->GetState()->SetNodeValue(27, 0, 1);
    pass->GetState()->SetNodeValue(15, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(23, 4, 1);
    pass->GetState()->SetNodeValue(14, 1, 1);
    pass->GetState()->SetNodeValue(168, 0, 1);
    DAT_011fcc8c = 2048;
    DAT_011fc0ac = 0;
    pass = DAT_011fe008;
    if (pass->Count() < 1)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fdd88;
    pass->pixelShader = DAT_011fda48;
    pass->GetState()->SetNodeValue(27, 0, 1);
    pass->GetState()->SetNodeValue(15, 1, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(23, 4, 1);
    pass->GetState()->SetNodeValue(14, 1, 1);
    pass->GetState()->SetNodeValue(168, 0, 1);
    {
        float bias = DAT_01200458;
        pass->SetState(195, *(unsigned int*)&bias, 1);
    }
    DAT_011fcc90 = 0;
    DAT_011fc0b0 = 0;
    pass = DAT_011fe00c;
    if (pass->Count() < 1)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
    }
    pass->vertexShader = DAT_011fde04;
    pass->pixelShader = DAT_011fda48;
    pass->GetState()->SetNodeValue(27, 0, 1);
    pass->GetState()->SetNodeValue(15, 1, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(23, 4, 1);
    pass->GetState()->SetNodeValue(14, 1, 1);
    pass->GetState()->SetNodeValue(168, 0, 1);
    {
        float bias = DAT_01200458;
        pass->SetState(195, *(unsigned int*)&bias, 1);
    }
    DAT_011fcc94 = 2048;
    DAT_011fc0b4 = 0;
}
}  // namespace fnv_00beb070

struct BfPass : GraphicsSystem
{
    void NiD3DPass_SetVertexShader(GraphicsResource*);
    void NiD3DPass_SetPixelShader(GraphicsResource*);
    __forceinline GraphicsManager* Manager()
    {
        if (!manager30)
            manager30 = FUN_00e7f5d0();
        return manager30;
    }
};
struct BfTemp : TemporaryResource
{
    void ApplyPairToState(unsigned int);
};
struct BfRenderState
{
    void NiD3DTextureStage_SetFilterMode(unsigned int);
};
struct BfRenderer
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    BfRenderState* state18;
};
struct BfResourcePair
{
    GraphicsResource* first;
    GraphicsResource* second;
    GraphicsResource* First() const
    {
        return first;
    }
};
extern BfResourcePair DAT_011fdd68[];
extern unsigned int DAT_011f91b0, DAT_011f948c, DAT_011f9534;
extern float DAT_01200458;
extern GraphicsSystem *DAT_011fe24c, *DAT_011fe250, *DAT_011fe254, *DAT_011fe264, *DAT_011fe268, *DAT_011fe26c,
    *DAT_011fe278, *DAT_011fe27c, *DAT_011fe280, *DAT_011fe290, *DAT_011fe294, *DAT_011fe298, *DAT_011fe2a4,
    *DAT_011fe2a8, *DAT_011fe2ac, *DAT_011fe2bc, *DAT_011fe2c0, *DAT_011fe2c4, *DAT_011fe2d0, *DAT_011fe2d4,
    *DAT_011fe2d8, *DAT_011fe2e8, *DAT_011fe2ec, *DAT_011fe2f0, *DAT_011fe304, *DAT_011fe308, *DAT_011fe310,
    *DAT_011fe314, *DAT_011fe31c, *DAT_011fe320, *DAT_011fe324, *DAT_011fe32c, *DAT_011fe330, *DAT_011fe338,
    *DAT_011fe33c, *DAT_011fe340, *DAT_011fe348, *DAT_011fe34c, *DAT_011fe8bc, *DAT_011fe8c0, *DAT_011fe8c4;
extern GraphicsResource *DAT_011fde8c, *DAT_011fdb4c, *DAT_011fdb50, *DAT_011fdb54, *DAT_011fde90, *DAT_011fde94,
    *DAT_011fdb58, *DAT_011fdb5c, *DAT_011fdb60, *DAT_011fde98, *DAT_011fde9c, *DAT_011fdb64, *DAT_011fdb68,
    *DAT_011fdb6c, *DAT_011fdea0, *DAT_011fdea4, *DAT_011fdb70, *DAT_011fdb74, *DAT_011fdb78, *DAT_011fdea8,
    *DAT_011fdeac, *DAT_011fdb7c, *DAT_011fdb80, *DAT_011fdeb0, *DAT_011fdeb4, *DAT_011fdb84, *DAT_011fdeb8,
    *DAT_011fdb88, *DAT_011fdb8c, *DAT_011fdebc, *DAT_011fdec0, *DAT_011fdb90, *DAT_011fdec4, *DAT_011fdb94,
    *DAT_011fdb98, *DAT_011fdec8, *DAT_011fdfc0, *DAT_011fdfc4, *DAT_011fdfc8;
extern unsigned int DAT_011fced4, DAT_011fc2f4, DAT_011fb714, DAT_011fab34, DAT_011fced8, DAT_011fc2f8, DAT_011fb718,
    DAT_011fab38, DAT_011fcedc, DAT_011fc2fc, DAT_011fb71c, DAT_011fab3c, DAT_011fceec, DAT_011fc30c, DAT_011fb72c,
    DAT_011fab4c, DAT_011fcef0, DAT_011fc310, DAT_011fb730, DAT_011fab50, DAT_011fcef4, DAT_011fc314, DAT_011fb734,
    DAT_011fab54, DAT_011fcf00, DAT_011fc320, DAT_011fb740, DAT_011fab60, DAT_011fcf04, DAT_011fc324, DAT_011fb744,
    DAT_011fab64, DAT_011fcf08, DAT_011fc328, DAT_011fb748, DAT_011fab68, DAT_011fcf18, DAT_011fc338, DAT_011fb758,
    DAT_011fab78, DAT_011fcf1c, DAT_011fc33c, DAT_011fb75c, DAT_011fab7c, DAT_011fcf20, DAT_011fc340, DAT_011fb760,
    DAT_011fab80, DAT_011fcf2c, DAT_011fc34c, DAT_011fb76c, DAT_011fab8c, DAT_011fcf30, DAT_011fc350, DAT_011fb770,
    DAT_011fab90, DAT_011fcf34, DAT_011fc354, DAT_011fb774, DAT_011fab94, DAT_011fcf44, DAT_011fc364, DAT_011fb784,
    DAT_011faba4, DAT_011fcf48, DAT_011fc368, DAT_011fb788, DAT_011faba8, DAT_011fcf4c, DAT_011fc36c, DAT_011fb78c,
    DAT_011fabac, DAT_011fcf58, DAT_011fc378, DAT_011fb798, DAT_011fabb8, DAT_011fcf5c, DAT_011fc37c, DAT_011fb79c,
    DAT_011fabbc, DAT_011fcf60, DAT_011fc380, DAT_011fb7a0, DAT_011fabc0, DAT_011fcf70, DAT_011fc390, DAT_011fb7b0,
    DAT_011fabd0, DAT_011fcf74, DAT_011fc394, DAT_011fb7b4, DAT_011fabd4, DAT_011fcf78, DAT_011fc398, DAT_011fb7b8,
    DAT_011fabd8, DAT_011fcf8c, DAT_011fc3ac, DAT_011fb7cc, DAT_011fabec, DAT_011fcf90, DAT_011fc3b0, DAT_011fb7d0,
    DAT_011fabf0, DAT_011fcf98, DAT_011fc3b8, DAT_011fb7d8, DAT_011fabf8, DAT_011fcf9c, DAT_011fc3bc, DAT_011fb7dc,
    DAT_011fabfc, DAT_011fcfa4, DAT_011fc3c4, DAT_011fb7e4, DAT_011fac04, DAT_011fcfa8, DAT_011fc3c8, DAT_011fb7e8,
    DAT_011fac08, DAT_011fcfac, DAT_011fc3cc, DAT_011fb7ec, DAT_011fac0c, DAT_011fcfb4, DAT_011fc3d4, DAT_011fb7f4,
    DAT_011fac14, DAT_011fcfb8, DAT_011fc3d8, DAT_011fb7f8, DAT_011fac18, DAT_011fcfc0, DAT_011fc3e0, DAT_011fb800,
    DAT_011fac20, DAT_011fcfc4, DAT_011fc3e4, DAT_011fb804, DAT_011fac24, DAT_011fcfc8, DAT_011fc3e8, DAT_011fb808,
    DAT_011fac28, DAT_011fcfd0, DAT_011fc3f0, DAT_011fb810, DAT_011fac30, DAT_011fcfd4, DAT_011fc3f4, DAT_011fb814,
    DAT_011fac34, DAT_011fd544, DAT_011fc964, DAT_011fbd84, DAT_011fd548, DAT_011fc968, DAT_011fbd88, DAT_011fd54c,
    DAT_011fc96c, DAT_011fbd8c;
struct BfRef
{
    GraphicsSystem* ptr;
    BfRef() : ptr(0)
    {}
    ~BfRef()
    {
        if (ptr && --ptr->strongCount64 == 0)
            ptr->FUN_00e80190();
    }
    GraphicsSystem* operator->() const
    {
        return ptr;
    }
    __declspec(noinline) BfRef& AssignNiD3DPass(GraphicsSystem* const& other)
    {
        if (ptr != other)
        {
            if (ptr && --ptr->strongCount64 == 0)
                ptr->FUN_00e80190();
            ptr = other;
            if (ptr)
                ++ptr->strongCount64;
        }
        return *this;
    }
    __forceinline BfRef& Reset(GraphicsSystem* const& other)
    {
        if (ptr != other)
        {
            if (ptr && --ptr->strongCount64 == 0)
                ptr->FUN_00e80190();
            ptr = other;
            if (ptr)
                ++ptr->strongCount64;
        }
        return *this;
    }
};
// @fnv 0x00bf0720
void __cdecl SetupRenderPasses()
{
    BfRef p;
    ScopedTemporary t;
    p.Reset(DAT_011fe24c);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde8c);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb4c);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fced4 = 0x780;
    DAT_011fc2f4 = 0x2c;
    DAT_011fb714 = 0x300;
    DAT_011fab34 = 0x8;
    p.Reset(DAT_011fe250);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde8c);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb50);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fced8 = 0x780;
    DAT_011fc2f8 = 0x3c;
    DAT_011fb718 = 0x300;
    DAT_011fab38 = 0xc;
    p.Reset(DAT_011fe254);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde8c);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb54);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcedc = 0x780;
    DAT_011fc2fc = 0x3c;
    DAT_011fb71c = 0x300;
    DAT_011fab3c = 0xc;
    p.Reset(DAT_011fe264);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde90);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb4c);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fceec = 0xf80;
    DAT_011fc30c = 0x2c;
    DAT_011fb72c = 0x300;
    DAT_011fab4c = 0x8;
    p.Reset(DAT_011fe268);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde90);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb50);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcef0 = 0xf80;
    DAT_011fc310 = 0x3c;
    DAT_011fb730 = 0x300;
    DAT_011fab50 = 0xc;
    p.Reset(DAT_011fe26c);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde90);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb54);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcef4 = 0xf80;
    DAT_011fc314 = 0x3c;
    DAT_011fb734 = 0x300;
    DAT_011fab54 = 0xc;
    p.Reset(DAT_011fe278);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde94);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb58);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf00 = 0x7f0;
    DAT_011fc320 = 0x2c;
    DAT_011fb740 = 0x360;
    DAT_011fab60 = 0x8;
    p.Reset(DAT_011fe27c);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde94);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb5c);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf04 = 0x7f0;
    DAT_011fc324 = 0x3c;
    DAT_011fb744 = 0x360;
    DAT_011fab64 = 0xc;
    p.Reset(DAT_011fe280);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde94);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb60);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf08 = 0x7f0;
    DAT_011fc328 = 0x3c;
    DAT_011fb748 = 0x360;
    DAT_011fab68 = 0xc;
    p.Reset(DAT_011fe290);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde98);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb58);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf18 = 0xff0;
    DAT_011fc338 = 0x2c;
    DAT_011fb758 = 0x360;
    DAT_011fab78 = 0x8;
    p.Reset(DAT_011fe294);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde98);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb5c);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf1c = 0xff0;
    DAT_011fc33c = 0x3c;
    DAT_011fb75c = 0x360;
    DAT_011fab7c = 0xc;
    p.Reset(DAT_011fe298);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde98);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb60);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf20 = 0xff0;
    DAT_011fc340 = 0x3c;
    DAT_011fb760 = 0x360;
    DAT_011fab80 = 0xc;
    p.Reset(DAT_011fe2a4);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde9c);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb64);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf2c = 0x780;
    DAT_011fc34c = 0x2c;
    DAT_011fb76c = 0x300;
    DAT_011fab8c = 0x0;
    p.Reset(DAT_011fe2a8);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde9c);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb68);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf30 = 0x780;
    DAT_011fc350 = 0x3c;
    DAT_011fb770 = 0x300;
    DAT_011fab90 = 0x4;
    p.Reset(DAT_011fe2ac);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fde9c);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb6c);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf34 = 0x780;
    DAT_011fc354 = 0x3c;
    DAT_011fb774 = 0x300;
    DAT_011fab94 = 0x4;
    p.Reset(DAT_011fe2bc);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdea0);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb64);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf44 = 0xf80;
    DAT_011fc364 = 0x2c;
    DAT_011fb784 = 0x300;
    DAT_011faba4 = 0x0;
    p.Reset(DAT_011fe2c0);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdea0);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb68);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf48 = 0xf80;
    DAT_011fc368 = 0x3c;
    DAT_011fb788 = 0x300;
    DAT_011faba8 = 0x4;
    p.Reset(DAT_011fe2c4);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdea0);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb6c);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf4c = 0xf80;
    DAT_011fc36c = 0x3c;
    DAT_011fb78c = 0x300;
    DAT_011fabac = 0x4;
    p.Reset(DAT_011fe2d0);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdea4);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb70);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf58 = 0x7f0;
    DAT_011fc378 = 0x2c;
    DAT_011fb798 = 0x360;
    DAT_011fabb8 = 0x8;
    p.Reset(DAT_011fe2d4);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdea4);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb74);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf5c = 0x7f0;
    DAT_011fc37c = 0x3c;
    DAT_011fb79c = 0x360;
    DAT_011fabbc = 0xc;
    p.Reset(DAT_011fe2d8);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdea4);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb78);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf60 = 0x7f0;
    DAT_011fc380 = 0x3c;
    DAT_011fb7a0 = 0x360;
    DAT_011fabc0 = 0xc;
    p.Reset(DAT_011fe2e8);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdea8);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb70);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf70 = 0xff0;
    DAT_011fc390 = 0x2c;
    DAT_011fb7b0 = 0x360;
    DAT_011fabd0 = 0x8;
    p.Reset(DAT_011fe2ec);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdea8);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb74);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf74 = 0xff0;
    DAT_011fc394 = 0x3c;
    DAT_011fb7b4 = 0x360;
    DAT_011fabd4 = 0xc;
    p.Reset(DAT_011fe2f0);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdea8);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb78);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf78 = 0xff0;
    DAT_011fc398 = 0x3c;
    DAT_011fb7b8 = 0x360;
    DAT_011fabd8 = 0xc;
    p.AssignNiD3DPass(DAT_011fe304);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdeac);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb7c);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf8c = 0x80380;
    DAT_011fc3ac = 0x13c;
    DAT_011fb7cc = 0x300;
    DAT_011fabec = 0x0;
    p.AssignNiD3DPass(DAT_011fe308);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdeac);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb80);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf90 = 0x80380;
    DAT_011fc3b0 = 0x13c;
    DAT_011fb7d0 = 0x300;
    DAT_011fabf0 = 0x0;
    p.AssignNiD3DPass(DAT_011fe310);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdeb0);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb7c);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf98 = 0x80b80;
    DAT_011fc3b8 = 0x13c;
    DAT_011fb7d8 = 0x300;
    DAT_011fabf8 = 0x0;
    p.AssignNiD3DPass(DAT_011fe314);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdeb0);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb80);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcf9c = 0x80b80;
    DAT_011fc3bc = 0x13c;
    DAT_011fb7dc = 0x300;
    DAT_011fabfc = 0x0;
    p.AssignNiD3DPass(DAT_011fe31c);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdeb4);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb84);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcfa4 = 0x80380;
    DAT_011fc3c4 = 0x13c;
    DAT_011fb7e4 = 0x300;
    DAT_011fac04 = 0x0;
    p.AssignNiD3DPass(DAT_011fe320);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdeb8);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb88);
    DAT_011fcfa8 = 0x80380;
    DAT_011fc3c8 = 0x13c;
    DAT_011fb7e8 = 0x300;
    DAT_011fac08 = 0x0;
    p.AssignNiD3DPass(DAT_011fe324);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdeb4);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb8c);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcfac = 0x80380;
    DAT_011fc3cc = 0x13c;
    DAT_011fb7ec = 0x300;
    DAT_011fac0c = 0x0;
    p.AssignNiD3DPass(DAT_011fe32c);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdebc);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb84);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcfb4 = 0x80b80;
    DAT_011fc3d4 = 0x13c;
    DAT_011fb7f4 = 0x300;
    DAT_011fac14 = 0x0;
    p.AssignNiD3DPass(DAT_011fe330);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdebc);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb8c);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcfb8 = 0x80b80;
    DAT_011fc3d8 = 0x13c;
    DAT_011fb7f8 = 0x300;
    DAT_011fac18 = 0x0;
    p.AssignNiD3DPass(DAT_011fe338);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdec0);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb90);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcfc0 = 0x80780;
    DAT_011fc3e0 = 0x13c;
    DAT_011fb800 = 0x300;
    DAT_011fac20 = 0x0;
    p.AssignNiD3DPass(DAT_011fe33c);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdec4);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb94);
    DAT_011fcfc4 = 0x80780;
    DAT_011fc3e4 = 0x13c;
    DAT_011fb804 = 0x300;
    DAT_011fac24 = 0x0;
    p.AssignNiD3DPass(DAT_011fe340);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdec0);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb98);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcfc8 = 0x80780;
    DAT_011fc3e8 = 0x13c;
    DAT_011fb808 = 0x300;
    DAT_011fac28 = 0x0;
    p.AssignNiD3DPass(DAT_011fe348);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdec8);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb90);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcfd0 = 0x80f80;
    DAT_011fc3f0 = 0x13c;
    DAT_011fb810 = 0x300;
    DAT_011fac30 = 0x0;
    p.AssignNiD3DPass(DAT_011fe34c);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdec8);
    ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdb98);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(15, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(7, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(23, 4, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 1, 1);
    DAT_011fcfd4 = 0x80f80;
    DAT_011fc3f4 = 0x13c;
    DAT_011fb814 = 0x300;
    DAT_011fac34 = 0x0;
    p.AssignNiD3DPass(DAT_011fe8bc);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    if (DAT_011f91b0 == 1 || DAT_011f91b0 == 2)
        ((BfRenderer*)p->unk24)->state18->NiD3DTextureStage_SetFilterMode(0);
    else
        ((BfRenderer*)p->unk24)->state18->NiD3DTextureStage_SetFilterMode(1);
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdfc0);
    if (DAT_011f91b0 == 3)
        ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdd68[DAT_011f948c].First());
    else
        ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdd68[0].First());
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(19, 9, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(20, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 0, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(152, 63, 1);
    {
        union
        {
            float f;
            unsigned int u;
        } value;
        value.f = DAT_01200458;
        ((BfPass*)p.ptr)->Manager()->SetNodeValue(195, value.u, 1);
    }
    DAT_011fd544 = 0x184;
    DAT_011fc964 = 0x8;
    DAT_011fbd84 = 0x100;
    p.AssignNiD3DPass(DAT_011fe8c0);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    if (DAT_011f91b0 == 1 || DAT_011f91b0 == 2)
        ((BfRenderer*)p->unk24)->state18->NiD3DTextureStage_SetFilterMode(0);
    else
        ((BfRenderer*)p->unk24)->state18->NiD3DTextureStage_SetFilterMode(1);
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdfc4);
    if (DAT_011f91b0 == 3)
        ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdd68[DAT_011f948c].First());
    else
        ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdd68[0].First());
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(19, 9, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(20, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 0, 1);
    {
        union
        {
            float f;
            unsigned int u;
        } value;
        value.f = DAT_01200458;
        ((BfPass*)p.ptr)->Manager()->SetNodeValue(195, value.u, 1);
    }
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(152, 63, 1);
    DAT_011fd548 = 0x984;
    DAT_011fc968 = 0x8;
    DAT_011fbd88 = 0x100;
    p.AssignNiD3DPass(DAT_011fe8c4);
    if (p->GetVersion() < 8)
    {
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 0, 1, 2, 1);
        p->NiD3DPass_SetStage(0, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 1, 1, 2, 1);
        p->NiD3DPass_SetStage(1, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 2, 1, 2, 1);
        p->NiD3DPass_SetStage(2, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 3, 1, 2, 1);
        p->NiD3DPass_SetStage(3, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 4, 1, 2, 1);
        p->NiD3DPass_SetStage(4, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 5, 3, 0, 1);
        t.ptr->unk08 = DAT_011f9534;
        t.ptr->unk0c = 1;
        p->NiD3DPass_SetStage(5, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 6, 1, 2, 1);
        ((BfTemp*)t.ptr)->ApplyPairToState(0);
        p->NiD3DPass_SetStage(6, (unsigned int)t.ptr);
        AssignStageFromPool(&t);
        ConfigureBeamStage(t.ptr, 7, 3, 0, 1);
        p->NiD3DPass_SetStage(7, (unsigned int)t.ptr);
    }
    if (DAT_011f91b0 == 1 || DAT_011f91b0 == 2)
        ((BfRenderer*)p->unk24)->state18->NiD3DTextureStage_SetFilterMode(0);
    else
        ((BfRenderer*)p->unk24)->state18->NiD3DTextureStage_SetFilterMode(1);
    ((BfPass*)p.ptr)->NiD3DPass_SetVertexShader(DAT_011fdfc8);
    if (DAT_011f91b0 == 3)
        ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdd68[DAT_011f948c].First());
    else
        ((BfPass*)p.ptr)->NiD3DPass_SetPixelShader(DAT_011fdd68[0].First());
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(27, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(19, 9, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(20, 1, 1);
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(14, 0, 1);
    {
        union
        {
            float f;
            unsigned int u;
        } value;
        value.f = DAT_01200458;
        ((BfPass*)p.ptr)->Manager()->SetNodeValue(195, value.u, 1);
    }
    ((BfPass*)p.ptr)->Manager()->SetNodeValue(152, 63, 1);
    DAT_011fd54c = 0x184;
    DAT_011fc96c = 0x8;
    DAT_011fbd8c = 0x100;
}

extern unsigned int DAT_011f9534;
extern unsigned int DAT_011fac3c;
extern unsigned int DAT_011fac40;
extern unsigned int DAT_011fac50;
extern unsigned int DAT_011fac54;
extern unsigned int DAT_011fac60;
extern unsigned int DAT_011fac64;
extern unsigned int DAT_011fac78;
extern unsigned int DAT_011fac84;
extern unsigned int DAT_011fac88;
extern unsigned int DAT_011fac98;
extern unsigned int DAT_011fac9c;
extern unsigned int DAT_011faca8;
extern unsigned int DAT_011facac;
extern unsigned int DAT_011facbc;
extern unsigned int DAT_011facc0;
extern unsigned int DAT_011fb840;
extern unsigned int DAT_011fb844;
extern unsigned int DAT_011fb858;
extern unsigned int DAT_011fb888;
extern unsigned int DAT_011fb88c;
extern unsigned int DAT_011fb89c;
extern unsigned int DAT_011fb8a0;
extern unsigned int DAT_011fc3fc;
extern unsigned int DAT_011fc400;
extern unsigned int DAT_011fc410;
extern unsigned int DAT_011fc414;
extern unsigned int DAT_011fc420;
extern unsigned int DAT_011fc424;
extern unsigned int DAT_011fc438;
extern unsigned int DAT_011fc444;
extern unsigned int DAT_011fc448;
extern unsigned int DAT_011fc458;
extern unsigned int DAT_011fc45c;
extern unsigned int DAT_011fc468;
extern unsigned int DAT_011fc46c;
extern unsigned int DAT_011fc47c;
extern unsigned int DAT_011fc480;
extern unsigned int DAT_011fcfdc;
extern unsigned int DAT_011fcfe0;
extern unsigned int DAT_011fcff0;
extern unsigned int DAT_011fcff4;
extern unsigned int DAT_011fd000;
extern unsigned int DAT_011fd004;
extern unsigned int DAT_011fd014;
extern unsigned int DAT_011fd018;
extern unsigned int DAT_011fd024;
extern unsigned int DAT_011fd028;
extern unsigned int DAT_011fd038;
extern unsigned int DAT_011fd03c;
extern unsigned int DAT_011fd048;
extern unsigned int DAT_011fd04c;
extern unsigned int DAT_011fd05c;
extern unsigned int DAT_011fd060;
extern GraphicsResource* DAT_011fdb9c;
extern GraphicsResource* DAT_011fdba0;
extern GraphicsResource* DAT_011fdba4;
extern GraphicsResource* DAT_011fdba8;
extern GraphicsResource* DAT_011fdbac;
extern GraphicsResource* DAT_011fdbb0;
extern GraphicsResource* DAT_011fdbb4;
extern GraphicsResource* DAT_011fdbb8;
extern GraphicsResource* DAT_011fdecc;
extern GraphicsResource* DAT_011fded0;
extern GraphicsResource* DAT_011fded4;
extern GraphicsResource* DAT_011fded8;
extern GraphicsResource* DAT_011fdedc;
extern GraphicsResource* DAT_011fdee0;
extern GraphicsResource* DAT_011fdee4;
extern GraphicsResource* DAT_011fdee8;
extern GraphicsSystem* DAT_011fe354;
extern GraphicsSystem* DAT_011fe358;
extern GraphicsSystem* DAT_011fe368;
extern GraphicsSystem* DAT_011fe36c;
extern GraphicsSystem* DAT_011fe378;
extern GraphicsSystem* DAT_011fe37c;
extern GraphicsSystem* DAT_011fe38c;
extern GraphicsSystem* DAT_011fe390;
extern GraphicsSystem* DAT_011fe39c;
extern GraphicsSystem* DAT_011fe3a0;
extern GraphicsSystem* DAT_011fe3b0;
extern GraphicsSystem* DAT_011fe3b4;
extern GraphicsSystem* DAT_011fe3c0;
extern GraphicsSystem* DAT_011fe3c4;
extern GraphicsSystem* DAT_011fe3d4;
extern GraphicsSystem* DAT_011fe3d8;

// @fnv 0x00bf66c0
// src: COMMUNITY 0x00bf66c0
void ShadowLightShader_PresetADPasses_2x()
{
    ScopedSystem system;
    ScopedTemporary temporary;
    system.resetFromGlobal(DAT_011fe354);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fdecc;
    system->material44 = DAT_011fdb9c;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fcfdc = 0x480;
    DAT_011fc3fc = 0xc;
    DAT_011fac3c = 0;

    system.resetFromGlobal(DAT_011fe358);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fdecc;
    system->material44 = DAT_011fdba0;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fcfe0 = 0x480;
    DAT_011fc400 = 0x1c;
    DAT_011fac40 = 4;

    system.resetFromGlobal(DAT_011fe368);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fded0;
    system->material44 = DAT_011fdb9c;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fcff0 = 0xc80;
    DAT_011fc410 = 0xc;
    DAT_011fac50 = 0;

    system.resetFromGlobal(DAT_011fe36c);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fded0;
    system->material44 = DAT_011fdba0;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fcff4 = 0xc80;
    DAT_011fc414 = 0x1c;
    DAT_011fac54 = 4;

    system.resetFromGlobal(DAT_011fe378);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fded4;
    system->material44 = DAT_011fdba4;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fd000 = 0x4f0;
    DAT_011fc420 = 0xc;
    DAT_011fb840 = 0x60;
    DAT_011fac60 = 0;

    system.resetFromGlobal(DAT_011fe37c);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fded4;
    system->material44 = DAT_011fdba8;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fd004 = 0x4f0;
    DAT_011fc424 = 0x1c;
    DAT_011fb844 = 0x60;
    DAT_011fac64 = 4;

    system.resetFromGlobal(DAT_011fe38c);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fded8;
    system->material44 = DAT_011fdba4;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fd014 = 0xcf0;
    DAT_011fc424 = 0xc;
    DAT_011fb844 = 0x60;
    DAT_011fac64 = 0;

    system.resetFromGlobal(DAT_011fe390);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fded8;
    system->material44 = DAT_011fdba8;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fd018 = 0xcf0;
    DAT_011fc438 = 0x1c;
    DAT_011fb858 = 0x60;
    DAT_011fac78 = 4;

    system.resetFromGlobal(DAT_011fe39c);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fdedc;
    system->material44 = DAT_011fdbac;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fd024 = 0x480;
    DAT_011fc444 = 0xc;
    DAT_011fac84 = 0;

    system.resetFromGlobal(DAT_011fe3a0);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fdedc;
    system->material44 = DAT_011fdbb0;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fd028 = 0x480;
    DAT_011fc448 = 0x1c;
    DAT_011fac88 = 4;

    system.resetFromGlobal(DAT_011fe3b0);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fdee0;
    system->material44 = DAT_011fdbac;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fd038 = 0xc80;
    DAT_011fc458 = 0xc;
    DAT_011fac98 = 0;

    system.resetFromGlobal(DAT_011fe3b4);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fdee0;
    system->material44 = DAT_011fdbb0;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fd03c = 0xc80;
    DAT_011fc45c = 0x1c;
    DAT_011fac9c = 4;

    system.resetFromGlobal(DAT_011fe3c0);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fdee4;
    system->material44 = DAT_011fdbb4;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fd048 = 0x4f0;
    DAT_011fc468 = 0xc;
    DAT_011fb888 = 0x60;
    DAT_011faca8 = 0;

    system.resetFromGlobal(DAT_011fe3c4);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fdee4;
    system->material44 = DAT_011fdbb8;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fd04c = 0x4f0;
    DAT_011fc46c = 0x1c;
    DAT_011fb88c = 0x60;
    DAT_011facac = 4;

    system.resetFromGlobal(DAT_011fe3d4);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fdee8;
    system->material44 = DAT_011fdbb4;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fd05c = 0xcf0;
    DAT_011fc47c = 0xc;
    DAT_011fb89c = 0x60;
    DAT_011facbc = 0;

    system.resetFromGlobal(DAT_011fe3d8);
    if (system->GetVersion() < 7)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 3, 1, 2, 1);
        system->NiD3DPass_SetStage(3, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 4, 3, 0, 1);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        system->NiD3DPass_SetStage(4, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 5, 1, 2, 1);
        system->NiD3DPass_SetStage(5, (unsigned int)temporary.ptr);
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 6, 3, 0, 1);
        system->NiD3DPass_SetStage(6, (unsigned int)temporary.ptr);
    }
    system->material5c = DAT_011fdee8;
    system->material44 = DAT_011fdbb8;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(27, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(15, 0, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(7, 1, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(23, 4, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(14, 1, 1);
    DAT_011fd060 = 0xcf0;
    DAT_011fc480 = 0x1c;
    DAT_011fb8a0 = 0x60;
    DAT_011facc0 = 4;
}

extern GraphicsSystem* DAT_011fe4c0;
extern GraphicsSystem* DAT_011fe4cc;
extern GraphicsSystem* DAT_011fe4f0;
extern GraphicsSystem* DAT_011fe4fc;
extern GraphicsResource* DAT_011fdeec;
extern GraphicsResource* DAT_011fdef0;
extern GraphicsResource* DAT_011fdef4;
extern GraphicsResource* DAT_011fdef8;
extern GraphicsResource* DAT_011fdbbc;
extern GraphicsResource* DAT_011fdbc0;
extern unsigned int DAT_011f9534;
extern unsigned int DAT_011fd148, DAT_011fc568;
extern unsigned int DAT_011fd154, DAT_011fc574;
extern unsigned int DAT_011fd178, DAT_011fc598;
extern unsigned int DAT_011fd184, DAT_011fc5a4;
// @fnv 0x00bf8f70
// src: COMMUNITY 0x00bf8f70
void FUN_00b78980_shell::ShadowLightShader_PresetDiffusePasses_2x()
{
    ScopedSystem system;
    ScopedTemporary temporary;
    system.resetFromGlobal(DAT_011fe4c0);
    if (system->GetVersion() < 4)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        ConfigureBeamStage(temporary.ptr, 3, 3, 0, 1);
        system->NiD3DPass_SetStage(3, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_011fdeec;
    system->material44 = DAT_011fdbbc;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(20, 2, 1);
    DAT_011fd148 = 128;
    DAT_011fc568 = 8;
    system.resetFromGlobal(DAT_011fe4cc);
    if (system->GetVersion() < 4)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        ConfigureBeamStage(temporary.ptr, 3, 3, 0, 1);
        system->NiD3DPass_SetStage(3, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_011fdef0;
    system->material44 = DAT_011fdbbc;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(20, 2, 1);
    DAT_011fd154 = 2176;
    DAT_011fc574 = 8;
    system.resetFromGlobal(DAT_011fe4f0);
    if (system->GetVersion() < 4)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        temporary.ptr->unk08 = DAT_011f9534;
        temporary.ptr->unk0c = 1;
        ConfigureBeamStage(temporary.ptr, 3, 3, 0, 1);
        system->NiD3DPass_SetStage(3, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_011fdef4;
    system->material44 = DAT_011fdbc0;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(20, 2, 1);
    DAT_011fd178 = 128;
    DAT_011fc598 = 8;
    system.resetFromGlobal(DAT_011fe4fc);
    if (system->GetVersion() < 4)
    {
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 0, 1, 2, 1);
        system->NiD3DPass_SetStage(0, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 1, 1, 2, 1);
        system->NiD3DPass_SetStage(1, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        ConfigureBeamStage(temporary.ptr, 2, 1, 2, 1);
        system->NiD3DPass_SetStage(2, reinterpret_cast<unsigned int>(temporary.ptr));
        AssignStageFromPool(&temporary);
        temporary.ptr->unk08 = DAT_011f9534;
        ConfigureBeamStage(temporary.ptr, 3, 3, 0, 1);
        system->NiD3DPass_SetStage(3, reinterpret_cast<unsigned int>(temporary.ptr));
    }
    system->material5c = DAT_011fdef8;
    system->material44 = DAT_011fdbc0;
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(19, 2, 1);
    if (!system->manager30)
        system->manager30 = FUN_00e7f5d0();
    system->manager30->SetNodeValue(20, 2, 1);
    DAT_011fd184 = 2176;
    DAT_011fc5a4 = 8;
}

namespace fnv_00bf96b0 {
struct RefObject
{
    virtual void slot0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ShaderRefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->m_iObjectReferenceCount);
        }
    }
};
struct RenderStateBlock
{
    void SetNodeValue(unsigned int, unsigned int, bool);
};
RenderStateBlock* FUN_00e7f5d0();
struct ShaderStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
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
    int references;
    void NiD3DTextureStage_ReturnStageToPool();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
struct ShaderStagePointer
{
    ShaderStage* object;
    ShaderStagePointer() : object(0)
    {}
    ~ShaderStagePointer()
    {
        if (object)
            object->Release();
    }
};
void AssignStageFromPool(ShaderStagePointer*);
void ConfigureBeamStage(ShaderStage*, unsigned int, unsigned int, unsigned int, bool);
extern unsigned int DAT_011f9534;
struct ShaderPass
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStateBlock* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    ShaderRefPointer pixelShader;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ShaderRefPointer vertexShader;
    unsigned int unk60;
    int references;
    __forceinline unsigned int Count()
    {
        return stageCount;
    }
    void FUN_00e80190();
    void NiD3DPass_SetVertexShader(RefObject*);
    void NiD3DPass_SetPixelShader(RefObject*);
    void NiD3DPass_SetStage(unsigned int, ShaderStage*);
    __forceinline RenderStateBlock* GetState()
    {
        if (!state)
            state = FUN_00e7f5d0();
        return state;
    }
};
struct ShaderPassPointer
{
    ShaderPass* object;
    ShaderPassPointer() : object(0)
    {}
    ~ShaderPassPointer()
    {
        if (object && --object->references == 0)
            object->FUN_00e80190();
    }
    __forceinline void operator=(ShaderPass* const& value)
    {
        if (object != value)
        {
            if (object && --object->references == 0)
                object->FUN_00e80190();
            object = value;
            if (object)
                ++object->references;
        }
    }
    __forceinline ShaderPass* operator->()
    {
        return object;
    }
};
extern ShaderPass* DAT_011fe560;
extern RefObject* DAT_011fdefc;
extern RefObject* DAT_011fdbc4;
extern unsigned int DAT_011fd1e8;
extern unsigned int DAT_011fc608;
extern ShaderPass* DAT_011fe564;
extern RefObject* DAT_011fdbc8;
extern unsigned int DAT_011fd1ec;
extern unsigned int DAT_011fc60c;
extern ShaderPass* DAT_011fe56c;
extern RefObject* DAT_011fdf00;
extern unsigned int DAT_011fd1f4;
extern unsigned int DAT_011fc614;
extern ShaderPass* DAT_011fe570;
extern unsigned int DAT_011fd1f8;
extern unsigned int DAT_011fc618;
extern ShaderPass* DAT_011fe578;
extern RefObject* DAT_011fdf04;
extern RefObject* DAT_011fdbcc;
extern unsigned int DAT_011fd200;
extern unsigned int DAT_011fc620;
extern unsigned int DAT_011fba40;
extern ShaderPass* DAT_011fe57c;
extern RefObject* DAT_011fdbd0;
extern unsigned int DAT_011fd204;
extern unsigned int DAT_011fc624;
extern ShaderPass* DAT_011fe584;
extern RefObject* DAT_011fdf08;
extern unsigned int DAT_011fd20c;
extern unsigned int DAT_011fc62c;
extern unsigned int DAT_011fba4c;
extern ShaderPass* DAT_011fe588;
extern unsigned int DAT_011fd210;
extern unsigned int DAT_011fc630;
extern ShaderPass* DAT_011fe590;
extern RefObject* DAT_011fdf0c;
extern RefObject* DAT_011fdbd4;
extern unsigned int DAT_011fd218;
extern unsigned int DAT_011fc638;
extern ShaderPass* DAT_011fe594;
extern RefObject* DAT_011fdbd8;
extern unsigned int DAT_011fd21c;
extern unsigned int DAT_011fc63c;
extern ShaderPass* DAT_011fe59c;
extern RefObject* DAT_011fdf10;
extern unsigned int DAT_011fd224;
extern unsigned int DAT_011fc644;
extern ShaderPass* DAT_011fe5a0;
extern unsigned int DAT_011fd228;
extern unsigned int DAT_011fc648;
extern ShaderPass* DAT_011fe5a8;
extern RefObject* DAT_011fdf14;
extern RefObject* DAT_011fdbdc;
extern unsigned int DAT_011fd230;
extern unsigned int DAT_011fc650;
extern ShaderPass* DAT_011fe5ac;
extern RefObject* DAT_011fdbe0;
extern unsigned int DAT_011fd234;
extern unsigned int DAT_011fc654;
extern ShaderPass* DAT_011fe5b4;
extern RefObject* DAT_011fdf18;
extern unsigned int DAT_011fd23c;
extern unsigned int DAT_011fc65c;
extern ShaderPass* DAT_011fe5b8;
extern unsigned int DAT_011fd240;
extern unsigned int DAT_011fc660;
extern ShaderPass* DAT_011fe5c0;
extern RefObject* DAT_011fdf1c;
extern RefObject* DAT_011fdbe4;
extern unsigned int DAT_011fd248;
extern unsigned int DAT_011fc668;
extern ShaderPass* DAT_011fe5c4;
extern RefObject* DAT_011fdbe8;
extern unsigned int DAT_011fd24c;
extern unsigned int DAT_011fc66c;
extern ShaderPass* DAT_011fe5cc;
extern RefObject* DAT_011fdf20;
extern unsigned int DAT_011fd254;
extern unsigned int DAT_011fc674;
extern ShaderPass* DAT_011fe5d0;
extern unsigned int DAT_011fd258;
extern unsigned int DAT_011fc678;
// @fnv 0x00bf96b0
// src: COMMUNITY 0x00bf96b0
void ShadowLightShader_PresetSpecularPasses_2x()
{
    ShaderPassPointer pass;
    ShaderStagePointer stage;
    pass = DAT_011fe560;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 3, 0, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdefc;
    pass->pixelShader = DAT_011fdbc4;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd1e8 = 0x480;
    DAT_011fc608 = 0x28;
    pass = DAT_011fe564;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 3, 0, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdefc;
    pass->pixelShader = DAT_011fdbc8;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd1ec = 0x480;
    DAT_011fc60c = 0x28;
    pass = DAT_011fe56c;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 3, 0, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf00;
    pass->pixelShader = DAT_011fdbc4;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd1f4 = 0xc80;
    DAT_011fc614 = 0x28;
    pass = DAT_011fe570;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 3, 0, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf00;
    pass->pixelShader = DAT_011fdbc8;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd1f8 = 0xc80;
    DAT_011fc618 = 0x28;
    pass = DAT_011fe578;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 3, 0, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf04;
    pass->pixelShader = DAT_011fdbcc;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd200 = 0x4f0;
    DAT_011fc620 = 0x28;
    DAT_011fba40 = 0x60;
    pass = DAT_011fe57c;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 3, 0, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf04;
    pass->pixelShader = DAT_011fdbd0;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd204 = 0x4f0;
    DAT_011fc624 = 0x28;
    DAT_011fba40 = 0x60;
    pass = DAT_011fe584;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 3, 0, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf08;
    pass->pixelShader = DAT_011fdbcc;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd20c = 0xcf0;
    DAT_011fc62c = 0x28;
    DAT_011fba4c = 0x60;
    pass = DAT_011fe588;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 3, 0, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf08;
    pass->pixelShader = DAT_011fdbd0;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd210 = 0xcf0;
    DAT_011fc630 = 0x28;
    DAT_011fba4c = 0x60;
    pass = DAT_011fe590;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 1, 2, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf0c;
    pass->pixelShader = DAT_011fdbd4;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd218 = 0x480;
    DAT_011fc638 = 0x28;
    pass = DAT_011fe594;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 1, 2, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf0c;
    pass->pixelShader = DAT_011fdbd8;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd21c = 0x480;
    DAT_011fc63c = 0x28;
    pass = DAT_011fe59c;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 1, 2, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf10;
    pass->pixelShader = DAT_011fdbd4;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd224 = 0xc80;
    DAT_011fc644 = 0x28;
    pass = DAT_011fe5a0;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 1, 2, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf10;
    pass->pixelShader = DAT_011fdbd8;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd228 = 0xc80;
    DAT_011fc648 = 0x28;
    pass = DAT_011fe5a8;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 1, 2, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf14;
    pass->pixelShader = DAT_011fdbdc;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd230 = 0x480;
    DAT_011fc650 = 0x28;
    pass = DAT_011fe5ac;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 1, 2, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf14;
    pass->pixelShader = DAT_011fdbe0;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd234 = 0x480;
    DAT_011fc654 = 0x28;
    pass = DAT_011fe5b4;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 1, 2, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf18;
    pass->pixelShader = DAT_011fdbdc;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd23c = 0xc80;
    DAT_011fc65c = 0x28;
    pass = DAT_011fe5b8;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 1, 2, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf18;
    pass->pixelShader = DAT_011fdbe0;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd240 = 0xc80;
    DAT_011fc660 = 0x28;
    pass = DAT_011fe5c0;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 1, 2, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf1c;
    pass->pixelShader = DAT_011fdbe4;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd248 = 0x480;
    DAT_011fc668 = 0x28;
    pass = DAT_011fe5c4;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 1, 2, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf1c;
    pass->pixelShader = DAT_011fdbe8;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd24c = 0x480;
    DAT_011fc66c = 0x28;
    pass = DAT_011fe5cc;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 1, 2, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->vertexShader = DAT_011fdf20;
    pass->pixelShader = DAT_011fdbe4;
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd254 = 0xc80;
    DAT_011fc674 = 0x28;
    pass = DAT_011fe5d0;
    if (pass->Count() < 6)
    {
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        pass->NiD3DPass_SetStage(pass->unk14, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 1, 1, 2, true);
        pass->NiD3DPass_SetStage(1, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 2, 1, 2, true);
        pass->NiD3DPass_SetStage(2, stage.object);
        AssignStageFromPool(&stage);
        stage.object->texture = DAT_011f9534;
        stage.object->unk0c = 1;
        ConfigureBeamStage(stage.object, 3, 3, 0, true);
        pass->NiD3DPass_SetStage(3, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 4, 1, 2, true);
        pass->NiD3DPass_SetStage(4, stage.object);
        AssignStageFromPool(&stage);
        ConfigureBeamStage(stage.object, 5, 1, 2, true);
        pass->NiD3DPass_SetStage(5, stage.object);
    }
    pass->NiD3DPass_SetVertexShader(DAT_011fdf20);
    pass->NiD3DPass_SetPixelShader(DAT_011fdbe8);
    pass->GetState()->SetNodeValue(19, 2, true);
    pass->GetState()->SetNodeValue(20, 2, true);
    DAT_011fd258 = 0xc80;
    DAT_011fc678 = 0x28;
}
}  // namespace fnv_00bf96b0

namespace fnv_00be39e0 {
struct StageReturn
{
    int unk00;
    long unk04;
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
    int refs;
    void __thiscall ReturnToPool();
    __forceinline void IncRefCount()
    {
        ++refs;
    }
    __forceinline void DecRefCount()
    {
        --refs;
        if (refs == 0)
            ReturnToPool();
    }
};
void __cdecl AssignStageFromPool(StageReturn*&);
typedef NiPointer<StageReturn> StagePtr;
int __cdecl ConfigureBeamStage(void* a, int b, int c, int d, int e);
struct RendObj;
struct StageSub
{
    void __thiscall SetNodeValue(int a, int b, int c);
};
void* __cdecl FUN_00e7f5d0();
struct RendVtbl
{
    void* f0;
    void(__thiscall* release)(RendObj*);
};
typedef long(__stdcall* ImpFn)(volatile long*);
struct RendObj
{
    RendVtbl* vtbl;
    long unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* f14;
    int f18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    StageSub* f30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    RendObj* f44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    RendObj* f5c;
    int unk60;
    int refs;
    __forceinline void SetPixelShader(RendObj* replacement, ImpFn decrement)
    {
        RendObj* old = f5c;
        if (old != replacement)
        {
            if (old && !decrement(&old->unk04))
                old->vtbl->release(old);
            f5c = replacement;
            if (replacement)
                InterlockedIncrement(&replacement->unk04);
        }
    }
    __forceinline void SetVertexShader(RendObj* replacement, ImpFn decrement)
    {
        RendObj* old = f44;
        if (old != replacement)
        {
            if (old && !decrement(&old->unk04))
                old->vtbl->release(old);
            f44 = replacement;
            if (replacement)
                InterlockedIncrement(&replacement->unk04);
        }
    }
    void FUN_00e80190();
    __forceinline void IncRefCount()
    {
        ++refs;
    }
    __forceinline void DecRefCount()
    {
        if (--refs == 0)
            FUN_00e80190();
    }
    __forceinline unsigned int GetStageCount() const
    {
        return f18;
    }
    __forceinline void SetState(int state, int value, int enabled)
    {
        if (!f30)
            f30 = (StageSub*)FUN_00e7f5d0();
        f30->SetNodeValue(state, value, enabled);
    }
};

struct RendObj2
{
    void __thiscall NiD3DPass_SetStage(void* a, void* b);
    void __thiscall FUN_00e80190();
    void __thiscall NiD3DPass_SetPixelShader(RendObj* a);
    void __thiscall NiD3DPass_SetVertexShader(RendObj* a);
};
typedef NiPointer<RendObj> SPtr;
struct PassObj : RendObj
{
    __forceinline void DecRefCount()
    {
        int& r = refs;
        if (--r == 0)
            FUN_00e80190();
    }
};
typedef NiPointer<PassObj> PassPtr;

extern SPtr DAT_011fe188;
extern SPtr DAT_011fe18c;
extern RendObj* DAT_011fddb0;
extern RendObj* DAT_011fda6c;
extern int DAT_011fce10;
extern int DAT_011fc230;
extern SPtr DAT_011fe1f4;
extern RendObj* DAT_011fddb8;
extern RendObj* DAT_011fda7c;
extern RendObj* DAT_011fddb4;
extern RendObj* DAT_011fda70;
extern int DAT_011fce14;
extern int DAT_011fc234;
extern int DAT_011fce7c;
extern int DAT_011fc29c;
extern int DAT_011fb6bc;
extern SPtr DAT_011fe1f8;
extern RendObj* DAT_011fddbc;
extern RendObj* DAT_011fda80;
extern int DAT_011fce80;
extern int DAT_011fc2a0;
extern int DAT_011fb6c0;
extern SPtr DAT_011fe190;
extern RendObj* DAT_011fda9c;
extern int DAT_011fce18;
extern int DAT_011fc238;
extern int DAT_011faa78;
extern SPtr DAT_011fe194;
extern RendObj* DAT_011fdaac;
extern int DAT_011fce1c;
extern int DAT_011fc23c;
extern int DAT_011faa7c;
extern SPtr DAT_011fe1fc;
extern RendObj* DAT_011fdaa0;
extern int DAT_011fce84;
extern int DAT_011fc2a4;
extern int DAT_011fb6c4;
extern SPtr DAT_011fe200;
extern SPtr DAT_011fe198;
extern SPtr DAT_011fe19c;
extern SPtr DAT_011fe1a0;
extern SPtr DAT_011fe1a4;
extern RendObj* DAT_011fdaa4;
extern int DAT_011fce2c;
extern int DAT_011fc24c;
extern int DAT_011faa8c;
extern RendObj* DAT_011fda84;
extern int DAT_011fce28;
extern int DAT_011fc248;
extern SPtr DAT_011fe204;
extern RendObj* DAT_011fda78;
extern int DAT_011fce8c;
extern int DAT_011fc2ac;
extern int DAT_011fb6cc;
extern SPtr DAT_011fe208;
extern RendObj* DAT_011fda88;
extern int DAT_011fce90;
extern int DAT_011fc2b0;
extern int DAT_011fb6d0;
extern RendObj* DAT_011fda74;
extern int DAT_011fce24;
extern int DAT_011fc244;
extern RendObj* DAT_011fddc0;
extern SPtr DAT_011fe1bc;
extern int DAT_011fce44;
extern int DAT_011fc264;
extern int DAT_011faaa4;
extern SPtr DAT_011fe224;
extern SPtr DAT_011fe228;
extern SPtr DAT_011fe1c4;
extern RendObj* DAT_011fde3c;
extern int DAT_011fce4c;
extern int DAT_011fc26c;
extern int DAT_011fceac;
extern int DAT_011fc2cc;
extern int DAT_011fb6ec;
extern int DAT_011fab0c;
extern SPtr DAT_011fe1b4;
extern RendObj* DAT_011fde2c;
extern int DAT_011fce3c;
extern int DAT_011fc25c;
extern SPtr DAT_011fe1b8;
extern RendObj* DAT_011fde30;
extern int DAT_011fce40;
extern int DAT_011fc260;
extern SPtr DAT_011fe21c;
extern RendObj* DAT_011fde34;
extern int DAT_011fcea4;
extern int DAT_011fc2c4;
extern int DAT_011fb6e4;
extern SPtr DAT_011fe220;
extern RendObj* DAT_011fde38;
extern int DAT_011fcea8;
extern int DAT_011fc2c8;
extern int DAT_011fb6e8;
extern SPtr DAT_011fe1a8;
extern RendObj* DAT_011fdab4;
extern int DAT_011fce30;
extern int DAT_011fc250;
extern int DAT_011faa90;
extern SPtr DAT_011fe20c;
extern RendObj* DAT_011fddc4;
extern RendObj* DAT_011fda90;
extern int DAT_011fce94;
extern int DAT_011fc2b4;
extern int DAT_011fb6d4;
extern SPtr DAT_011fe1ac;
extern RendObj* DAT_011fda94;
extern int DAT_011fce34;
extern int DAT_011fc254;
extern PassPtr DAT_011fe1b0;
extern PassPtr DAT_011fe218;
extern RendObj* DAT_011fda8c;
extern int DAT_011fce20;
extern int DAT_011fc240;
extern RendObj* DAT_011fdab0;
extern int DAT_011fce88;
extern int DAT_011fc2a8;
extern int DAT_011fb6c8;
extern ImpFn DAT_00fdf1c4_ptr;
extern ImpFn DAT_00fdf1c0_ptr;
extern SPtr DAT_11FE234;
extern RendObj* DAT_11FDE40;
extern RendObj* DAT_11FDA90;
extern int DAT_11FCEBC;
extern int DAT_11FC2DC;
extern int DAT_11FB6FC;
extern SPtr DAT_11FE1C8;
extern RendObj* DAT_11FDE2C;
extern RendObj* DAT_11FDA74;
extern int DAT_11FCE50;
extern int DAT_11FC270;
extern SPtr DAT_11FE1CC;
extern RendObj* DAT_11FDE30;
extern RendObj* DAT_11FDA84;
extern int DAT_11FCE54;
extern int DAT_11FC274;
extern SPtr DAT_11FE22C;
extern RendObj* DAT_11FDE34;
extern RendObj* DAT_11FDA78;
extern int DAT_11FCEB4;
extern int DAT_11FC2D4;
extern int DAT_11FB6F4;
extern SPtr DAT_11FE230;
extern RendObj* DAT_11FDE38;
extern RendObj* DAT_11FDA88;
extern int DAT_11FCEB8;
extern int DAT_11FC2D8;
extern int DAT_11FB6F8;
extern SPtr DAT_11FE1D0;
extern RendObj* DAT_11FDAA4;
extern int DAT_11FCE58;
extern int DAT_11FC278;
extern int DAT_11FAAB8;
extern SPtr DAT_11FE1D4;
extern RendObj* DAT_11FDAB4;
extern int DAT_11FCE5C;
extern int DAT_11FC27C;
extern int DAT_11FAABC;
extern SPtr DAT_11FE1D8;
extern RendObj* DAT_11FDE3C;
extern RendObj* DAT_11FDA94;
extern int DAT_11FCE60;
extern int DAT_11FC280;
extern int DAT_11FAAC0;
extern SPtr DAT_11FE238;
extern RendObj* DAT_11FDAA8;
extern int DAT_11FCEC0;
extern int DAT_11FC2E0;
extern int DAT_11FB700;
extern int DAT_11FAB20;
extern SPtr DAT_11FE23C;
extern RendObj* DAT_11FDAB8;
extern int DAT_11FAB24;
extern int DAT_11FCEC4;
extern int DAT_11FC2E4;
extern int DAT_11FB704;
extern PassPtr DAT_011fe1dc;
extern PassPtr DAT_011fe240;
struct FUN_00b78980_shell
{
    void __thiscall ConfigureRenderPasses();
};
// Configures each render pass: builds missing stages, assigns shaders and render objects, sets render states, and writes per-pass constants.
// @fnv 0x00be39e0
void __thiscall FUN_00b78980_shell::ConfigureRenderPasses()
{
    SPtr pPass;
    StagePtr aLocal;
    pPass = DAT_011fe188;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ImpFn imp4 = InterlockedDecrement;
    pPass->SetPixelShader(DAT_011fddb0, imp4);
    pPass->SetVertexShader(DAT_011fda6c, imp4);
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce10 = 0x80;
    DAT_011fc230 = 0xc;
    pPass = DAT_011fe18c;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    RendObj* pNewObj = DAT_011fddb8;
    RendObj* pOldObj = pPass->f5c;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f5c = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pNewObj = DAT_011fda7c;
    pOldObj = pPass->f44;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f44 = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce14 = 0x80;
    DAT_011fc234 = 0xc;
    pPass = DAT_011fe1f4;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    pNewObj = DAT_011fddb4;
    pOldObj = pPass->f5c;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f5c = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pNewObj = DAT_011fda70;
    pOldObj = pPass->f44;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f44 = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    int g380 = 0x380;
    DAT_011fce7c = g380;
    DAT_011fc29c = 0xc;
    DAT_011fb6bc = 0x300;
    pPass = DAT_011fe1f8;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    pNewObj = DAT_011fddbc;
    pOldObj = pPass->f5c;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f5c = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pNewObj = DAT_011fda80;
    pOldObj = pPass->f44;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f44 = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce80 = g380;
    DAT_011fc2a0 = 0xc;
    DAT_011fb6c0 = 0x300;
    pPass = DAT_011fe190;
    if (pPass->GetStageCount() < 3)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    pNewObj = DAT_011fddb0;
    pOldObj = pPass->f5c;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f5c = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pNewObj = DAT_011fda9c;
    pOldObj = pPass->f44;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f44 = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce18 = 0x80;
    DAT_011fc238 = 0x1c;
    DAT_011faa78 = 4;
    pPass = DAT_011fe194;
    if (pPass->GetStageCount() < 3)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    pNewObj = DAT_011fddb8;
    pOldObj = pPass->f5c;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f5c = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pNewObj = DAT_011fdaac;
    pOldObj = pPass->f44;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f44 = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce1c = 0x80;
    DAT_011fc23c = 0x1c;
    DAT_011faa7c = 4;
    pPass = DAT_011fe1fc;
    if (pPass->GetStageCount() < 3)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    pNewObj = DAT_011fddb4;
    pOldObj = pPass->f5c;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f5c = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pNewObj = DAT_011fdaa0;
    pOldObj = pPass->f44;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f44 = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce84 = g380;
    DAT_011fc2a4 = 0xc;
    DAT_011fb6c4 = 0x300;
    pPass = DAT_011fe200;
    if (pPass->GetStageCount() < 3)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    pNewObj = DAT_011fddbc;
    pOldObj = pPass->f5c;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f5c = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pNewObj = DAT_011fdab0;
    pOldObj = pPass->f44;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f44 = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce88 = g380;
    DAT_011fc2a8 = 0xc;
    DAT_011fb6c8 = 0x300;
    pPass = DAT_011fe198;
    if (pPass->GetStageCount() < 4)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 3, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    pNewObj = DAT_011fddc0;
    pOldObj = pPass->f5c;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f5c = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pNewObj = DAT_011fda8c;
    pOldObj = pPass->f44;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f44 = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce20 = 0x80;
    DAT_011fc240 = 0xc;
    pPass = DAT_011fe19c;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    pNewObj = DAT_011fddb0;
    pOldObj = pPass->f5c;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f5c = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pNewObj = DAT_011fda74;
    pOldObj = pPass->f44;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f44 = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pPass->SetState(0x1b, 0x1, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce24 = 0x80;
    DAT_011fc244 = 0xc;
    pPass = DAT_011fe1a0;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    pNewObj = DAT_011fddb8;
    pOldObj = pPass->f5c;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f5c = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pNewObj = DAT_011fda84;
    pOldObj = pPass->f44;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f44 = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pPass->SetState(0x1b, 0x1, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce28 = 0x80;
    DAT_011fc248 = 0xc;
    pPass = DAT_011fe204;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    pNewObj = DAT_011fddb4;
    pOldObj = pPass->f5c;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f5c = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pNewObj = DAT_011fda78;
    pOldObj = pPass->f44;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f44 = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce8c = g380;
    DAT_011fc2ac = 0xc;
    DAT_011fb6cc = 0x300;
    pPass = DAT_011fe208;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    pNewObj = DAT_011fddbc;
    pOldObj = pPass->f5c;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f5c = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pNewObj = DAT_011fda88;
    pOldObj = pPass->f44;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f44 = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce90 = g380;
    DAT_011fc2b0 = 0xc;
    DAT_011fb6d0 = 0x300;
    pPass = DAT_011fe1a4;
    if (pPass->GetStageCount() < 3)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    pNewObj = DAT_011fddb0;
    pOldObj = pPass->f5c;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f5c = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pNewObj = DAT_011fdaa4;
    pOldObj = pPass->f44;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f44 = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    pPass->SetState(0x1b, 0x1, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce2c = 0x80;
    DAT_011fc24c = 0x1c;
    DAT_011faa8c = 4;
    pPass = DAT_011fe1a8;
    if (pPass->GetStageCount() < 3)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    pNewObj = DAT_011fddb8;
    pOldObj = pPass->f5c;
    if (pOldObj != pNewObj)
    {
        if (pOldObj != 0)
        {
            if (!InterlockedDecrement(&pOldObj->unk04))
                pOldObj->vtbl->release(pOldObj);
        }
        pPass->f5c = pNewObj;
        if (pNewObj != 0)
            InterlockedIncrement(&pNewObj->unk04);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_011fdab4);
    pPass->SetState(0x1b, 0x1, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce30 = 0x80;
    DAT_011fc250 = 0x1c;
    DAT_011faa90 = 4;
    pPass = DAT_011fe20c;
    if (pPass->GetStageCount() < 4)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 3, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_011fddc4);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_011fda90);
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce94 = g380;
    DAT_011fc2b4 = 0xc;
    DAT_011fb6d4 = 0x300;
    pPass = DAT_011fe1ac;
    if (pPass->GetStageCount() < 4)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 3, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_011fddc0);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_011fda94);
    pPass->SetState(0x1b, 0x1, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce34 = 0x80;
    DAT_011fc254 = 0xc;
    {
        DAT_011fe1b0 = (PassObj*)0;
        DAT_011fe218 = (PassObj*)0;
    }
    pPass = DAT_011fe1b4;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_011fde2c);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_011fda6c);
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce3c = 0x880;
    DAT_011fc25c = 0xc;
    pPass = DAT_011fe1b8;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_011fde30);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_011fda7c);
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce40 = 0x880;
    DAT_011fc260 = 0xc;
    pPass = DAT_011fe21c;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_011fde34);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_011fda70);
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fcea4 = 0xb80;
    DAT_011fc2c4 = 0xc;
    DAT_011fb6e4 = 0x300;
    pPass = DAT_011fe220;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_011fde38);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_011fda80);
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fcea8 = 0xb80;
    DAT_011fc2c8 = 0xc;
    DAT_011fb6e8 = 0x300;
    pPass = DAT_011fe1bc;
    if (pPass->GetStageCount() < 3)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_011fde2c);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_011fda9c);
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce44 = 0x880;
    DAT_011fc264 = 0x1c;
    DAT_011faaa4 = 4;
    pPass = DAT_011fe224;
    if (pPass->GetStageCount() < 3)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_011fde34);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_011fdaa0);
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fceac = 0xb80;
    DAT_011fc2cc = 0x1c;
    DAT_011fb6ec = 0x300;
    DAT_011fab0c = 0x4;
    pPass = DAT_011fe228;
    if (pPass->GetStageCount() < 3)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_011fde38);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_011fdab0);
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fceac = 0xb80;
    DAT_011fc2cc = 0x1c;
    DAT_011fb6ec = 0x300;
    DAT_011fab0c = 0x4;
    pPass = DAT_011fe1c4;
    if (pPass->GetStageCount() < 4)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 3, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_011fde3c);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_011fda8c);
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_011fce4c = 0x880;
    DAT_011fc26c = 0xc;
    pPass = DAT_11FE234;
    if (pPass->GetStageCount() < 4)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 3, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_11FDE40);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_11FDA90);
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0xf, 0x0, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_11FCEBC = 0xb80;
    DAT_11FC2DC = 0xc;
    DAT_11FB6FC = 0x300;
    pPass = DAT_11FE1C8;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_11FDE2C);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_11FDA74);
    pPass->SetState(0x1b, 0x1, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_11FCE50 = 0x880;
    DAT_11FC270 = 0xc;
    pPass = DAT_11FE1CC;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_11FDE30);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_11FDA84);
    pPass->SetState(0x1b, 0x1, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_11FCE54 = 0x880;
    DAT_11FC274 = 0xc;
    pPass = DAT_11FE22C;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_11FDE34);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_11FDA78);
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_11FCEB4 = 0xb80;
    DAT_11FC2D4 = 0xc;
    DAT_11FB6F4 = 0x300;
    pPass = DAT_11FE230;
    if (pPass->GetStageCount() < 2)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_11FDE38);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_11FDA88);
    pPass->SetState(0x1b, 0x0, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_11FCEB8 = 0xb80;
    DAT_11FC2D8 = 0xc;
    DAT_11FB6F8 = 0x300;
    pPass = DAT_11FE1D0;
    if (pPass->GetStageCount() < 3)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_11FDE2C);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_11FDAA4);
    pPass->SetState(0x1b, 0x1, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_11FCE58 = 0x880;
    DAT_11FC278 = 0x1c;
    DAT_11FAAB8 = 4;
    pPass = DAT_11FE1D4;
    if (pPass->GetStageCount() < 3)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_11FDE30);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_11FDAB4);
    pPass->SetState(0x1b, 0x1, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_11FCE5C = 0x880;
    DAT_11FC27C = 0x1c;
    DAT_11FAABC = 4;
    pPass = DAT_11FE1D8;
    if (pPass->GetStageCount() < 3)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 3, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_11FDE3C);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_11FDA94);
    pPass->SetState(0x1b, 0x1, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_11FCE60 = 0x880;
    DAT_11FC280 = 0xc;
    DAT_11FAAC0 = 4;
    pPass = DAT_11FE238;
    if (pPass->GetStageCount() < 3)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_11FDE34);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_11FDAA8);
    pPass->SetState(0x1b, 0x1, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_11FCEC0 = 0xb80;
    DAT_11FC2E0 = 0x1c;
    DAT_11FB700 = 0x300;
    DAT_11FAB20 = 4;
    pPass = DAT_11FE23C;
    if (pPass->GetStageCount() < 3)
    {
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 1, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
        AssignStageFromPool(aLocal.m_pObject);
        ConfigureBeamStage(aLocal.m_pObject, 2, 1, 2, 1);
        ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetStage(pPass->f14, aLocal.m_pObject);
    }
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetVertexShader(DAT_11FDE38);
    ((RendObj2*)pPass.m_pObject)->NiD3DPass_SetPixelShader(DAT_11FDAB8);
    pPass->SetState(0x1b, 0x1, 0x1);
    pPass->SetState(0x13, 0x5, 0x1);
    pPass->SetState(0x14, 0x6, 0x1);
    pPass->SetState(0xf, 0x1, 0x1);
    pPass->SetState(0x7, 0x1, 0x1);
    pPass->SetState(0x17, 0x4, 0x1);
    pPass->SetState(0xe, 0x1, 0x1);
    DAT_11FAB24 = 4;
    DAT_11FCEC4 = 0xb80;
    DAT_11FC2E4 = 0x1c;
    DAT_11FB704 = 0x300;
    {
        DAT_011fe1dc = (PassObj*)0;
        DAT_011fe240 = (PassObj*)0;
    }
}
}  // namespace fnv_00be39e0

namespace fnv_00c01020 {
struct StageReturn
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    void ReturnToPool();
    void Release60()
    {
        if (--m_60 == 0)
            ReturnToPool();
    }
};
void AssignStageFromPool(StageReturn*& sr);
class Sub30
{
  public:
    void SetNodeValue(int a, int b, int c);
};
Sub30* FUN_00e7f5d0();
void ConfigureBeamStage(StageReturn* sr, int a, int b, int c, int d);
class NIPtr
{
  public:
    NiRefObject* m_pObject;
    NIPtr() : m_pObject(0)
    {}
    NIPtr& operator=(NiRefObject* p)
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
class ObjC
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    unsigned int m_18;
    unsigned int GetM18()
    {
        return m_18;
    }
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    Sub30* m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    NIPtr m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    NIPtr m_5c;
    int m_60;
    int m_64;
    void FUN_00e80190();
    inline void IncRefCount() { m_64++; }
    inline void DecRefCount() { if (--m_64 == 0) FUN_00e80190(); }
    void NiD3DPass_SetStage(int a, StageReturn* sr);
};
// Exe ObjC ownership uses its reference counter at +0x64.
typedef NiPointer<ObjC> ObjPtr;
class SRPtr
{
  public:
    StageReturn* m_pObject;
    SRPtr() : m_pObject(0)
    {}
    ~SRPtr()
    {
        if (m_pObject)
            m_pObject->Release60();
    }
};

extern ObjC* DAT_011fe780;
extern ObjC* DAT_011fe784;
extern ObjC* DAT_011fe788;
extern ObjC* DAT_011fe78c;
extern ObjC* DAT_011fe790;
extern NiRefObject* DAT_011fdf6c;
extern NiRefObject* DAT_011fdf70;
extern NiRefObject* DAT_011fdf74;
extern NiRefObject* DAT_011fdf78;
extern NiRefObject* DAT_011fdf7c;
extern NiRefObject* DAT_011fdc34;
extern NiRefObject* DAT_011fdc38;
extern NiRefObject* DAT_011fdc3c;
extern int DAT_011fd408;
extern int DAT_011fc828;
extern int DAT_011fd40c;
extern int DAT_011fc82c;
extern int DAT_011fd410;
extern int DAT_011fc830;
extern int DAT_011fd414;
extern int DAT_011fc834;
extern int DAT_011fd418;
extern int DAT_011fc838;

class FUN_00b78980_shell
{
  public:
    void InitStageObjects();
};
// @fnv 0x00c01020
void FUN_00b78980_shell::InitStageObjects()
{
    ObjPtr pObj;
    SRPtr sr;

    if (pObj.m_pObject != DAT_011fe780)
    {
        if (pObj.m_pObject)
        {
            if (--pObj.m_pObject->m_64 == 0)
                pObj.m_pObject->FUN_00e80190();
        }
        pObj.m_pObject = DAT_011fe780;
        if (pObj.m_pObject)
            pObj.m_pObject->m_64++;
    }
    if (pObj->GetM18() < 1)
    {
        AssignStageFromPool(sr.m_pObject);
        ConfigureBeamStage(sr.m_pObject, 0, 1, 2, 1);
        pObj->NiD3DPass_SetStage(pObj->m_14, sr.m_pObject);
    }
    pObj->m_5c = DAT_011fdf6c;
    pObj->m_44 = DAT_011fdc34;
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(27, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(15, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(7, 1, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(23, 4, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(14, 1, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(168, 15, 1);
    DAT_011fd408 = 16384;
    DAT_011fc828 = 131072;
    if (pObj.m_pObject != DAT_011fe784)
    {
        if (pObj.m_pObject)
        {
            if (--pObj.m_pObject->m_64 == 0)
                pObj.m_pObject->FUN_00e80190();
        }
        pObj.m_pObject = DAT_011fe784;
        if (pObj.m_pObject)
            pObj.m_pObject->m_64++;
    }
    if (pObj->GetM18() < 1)
    {
        AssignStageFromPool(sr.m_pObject);
        ConfigureBeamStage(sr.m_pObject, 0, 1, 2, 1);
        pObj->NiD3DPass_SetStage(pObj->m_14, sr.m_pObject);
    }
    pObj->m_5c = DAT_011fdf70;
    pObj->m_44 = DAT_011fdc34;
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(27, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(15, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(7, 1, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(23, 4, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(14, 1, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(168, 15, 1);
    DAT_011fd40c = 34816;
    DAT_011fc82c = 131072;
    if (pObj.m_pObject != DAT_011fe788)
    {
        if (pObj.m_pObject)
        {
            if (--pObj.m_pObject->m_64 == 0)
                pObj.m_pObject->FUN_00e80190();
        }
        pObj.m_pObject = DAT_011fe788;
        if (pObj.m_pObject)
            pObj.m_pObject->m_64++;
    }
    if (pObj->GetM18() < 1)
    {
        AssignStageFromPool(sr.m_pObject);
        ConfigureBeamStage(sr.m_pObject, 0, 1, 2, 1);
        pObj->NiD3DPass_SetStage(pObj->m_14, sr.m_pObject);
    }
    pObj->m_5c = DAT_011fdf74;
    pObj->m_44 = DAT_011fdc38;
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(27, 1, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(19, 5, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(20, 6, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(15, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(7, 1, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(23, 4, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(14, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(168, 15, 1);
    DAT_011fd410 = 82944;
    DAT_011fc830 = 131072;
    if (pObj.m_pObject != DAT_011fe78c)
    {
        if (pObj.m_pObject)
        {
            if (--pObj.m_pObject->m_64 == 0)
                pObj.m_pObject->FUN_00e80190();
        }
        pObj.m_pObject = DAT_011fe78c;
        if (pObj.m_pObject)
            pObj.m_pObject->m_64++;
    }
    pObj->m_5c = DAT_011fdf78;
    pObj->m_44 = DAT_011fdc3c;
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(27, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(15, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(7, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(14, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(168, 15, 1);
    DAT_011fd414 = 0;
    DAT_011fc834 = 0;
    if (pObj.m_pObject != DAT_011fe790)
    {
        if (pObj.m_pObject)
        {
            if (--pObj.m_pObject->m_64 == 0)
                pObj.m_pObject->FUN_00e80190();
        }
        pObj.m_pObject = DAT_011fe790;
        if (pObj.m_pObject)
            pObj.m_pObject->m_64++;
    }
    pObj->m_5c = DAT_011fdf7c;
    pObj->m_44 = DAT_011fdc3c;
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(27, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(15, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(7, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(14, 0, 1);
    if (pObj->m_30 == 0)
        pObj->m_30 = FUN_00e7f5d0();
    pObj->m_30->SetNodeValue(168, 15, 1);
    DAT_011fd418 = 2048;
    DAT_011fc838 = 0;
}
}  // namespace fnv_00c01020

struct P3_bbb890
{
    float x, y, z;
};
struct M_bbb890
{
    float m[4][4];
};
struct Quad119
{
    float x, y, z, w;
    Quad119& operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;
        w *= f;
        return *this;
    }
};
struct Light119
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
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
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned char kind;
};
struct Property119
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int flags;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
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
    float time;
    Light119* __thiscall FUN_00b70590(void*&);
};
struct Pass119
{
    unsigned int unk0;
    unsigned short type;
    unsigned short unk6;
    unsigned char unk8;
    unsigned char count;
    unsigned short unka;
    Light119** lights;
};
struct Scale119
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    float scale;
};
struct Scene119
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
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
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    P3_bbb890 position;
};

extern unsigned int DAT_011f91b8;
extern Scene119* DAT_011f91c8;
extern bool DAT_011f941e;
extern float DAT_011f9184;
extern const float DAT_01016248;
extern Quad119 DAT_011fa170[];
extern float DAT_011fa1f0[];
// 0x00b4f5d0 returns DAT_011f95f0; its +0x154 color is BSShaderAccumulator::kSilhouetteColor.
BSShaderAccumulator* __cdecl BSShaderManager_GetCurrentAccumulator();
void __cdecl UpdateWaterTint(unsigned int, Light119*, float);
P3_bbb890* __stdcall D3DXVec3TransformCoord_00ee6df8(P3_bbb890*, const P3_bbb890*, const M_bbb890*);
P3_bbb890* __stdcall D3DXVec3TransformNormal_00ee6df2(P3_bbb890*, const P3_bbb890*, const M_bbb890*);
P3_bbb890* __stdcall D3DXVec3Normalize_00ee6dec(P3_bbb890*, const P3_bbb890*);
static inline void Scl(P3_bbb890& v, float f)
{
    v.x *= f;
    v.y *= f;
    v.z *= f;
}
static inline Quad119 QMul(const Quad119& v, float f)
{
    Quad119 r = v;
    r *= f;
    return r;
}
// Updates shader light constants for a pass: writes light positions/radii or directions, adjusts diffuse color, and handles the id 0x24b case.
// @fnv 0x00b78a90
void __stdcall UpdateLightPass(Property119* pProperty, Pass119* pass, M_bbb890 matrix, Scale119* scale, unsigned int id,
                               unsigned int world)
{
    float time = pProperty->time;
    if (DAT_011f91b8 == 15)
    {
        BSShaderAccumulator* renderer = BSShaderManager_GetCurrentAccumulator();
        unsigned int* color = reinterpret_cast<unsigned int*>(const_cast<unsigned char*>(DAT_011FA0C0));
        color[0] = reinterpret_cast<const unsigned int*>(&renderer->kSilhouetteColor)[0];
        color[1] = reinterpret_cast<const unsigned int*>(&renderer->kSilhouetteColor)[1];
        color[2] = reinterpret_cast<const unsigned int*>(&renderer->kSilhouetteColor)[2];
        color[3] = reinterpret_cast<const unsigned int*>(&renderer->kSilhouetteColor)[3];
        return;
    }
    if (*reinterpret_cast<unsigned char*>(&DAT_011febf0.m_pObject->unk08))
    {
        if (pass->type >= 16 && pass->type <= 19)
            DAT_011febf0.m_pObject->m_uiValue4 = 1;
        else
            DAT_011febf0.m_pObject->m_uiValue4 = pass->count;
    }
    if (*reinterpret_cast<unsigned char*>(&DAT_011fec38.m_pObject->unk08))
        DAT_011fec38.m_pObject->m_uiValue4 = pass->count;
    if (*reinterpret_cast<unsigned char*>(&DAT_011fec4c.m_pObject->unk08))
        DAT_011fec4c.m_pObject->m_uiValue4 = pass->count - 1;
    for (unsigned char i = 0; i < pass->count; ++i)
    {
        if (i >= 10)
            break;
        Light119* light = pass->lights[i];
        UpdateWaterTint(i, light, time);
        unsigned int index = i;
        if (pass->type >= 16 && pass->type <= 19)
        {
            reinterpret_cast<Quad119*>(const_cast<float*>(DAT_011fd9a8))[index] = DAT_011fa170[index];
            reinterpret_cast<Quad119*>(const_cast<float*>(DAT_011fd9a8))[index].w =
                reinterpret_cast<const Quad119*>(DAT_011fa1f0)[index].x;
        }
        else if (light)
        {
            if (light->kind)
            {
                P3_bbb890 position;
                position.x = DAT_011fa170[index].x;
                position.y = DAT_011fa170[index].y;
                position.z = DAT_011fa170[index].z;
                P3_bbb890 sceneOffset = DAT_011f91c8->position;
                position.x = sceneOffset.x + position.x;
                position.y = sceneOffset.y + position.y;
                position.z = sceneOffset.z + position.z;
                P3_bbb890 transformedPos;
                D3DXVec3TransformCoord_00ee6df8(&transformedPos, &position, &matrix);
                float radius = reinterpret_cast<const Quad119*>(DAT_011fa1f0)[index].x;
                if (!world)
                {
                    if (pass->type >= 0x231 && pass->type <= 0x233)
                    {
                        Scl(transformedPos, scale->scale);
                    }
                    else
                        radius /= scale->scale;
                }
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_011fd9a8))[index].x = transformedPos.x;
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_011fd9a8))[index].y = transformedPos.y;
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_011fd9a8))[index].z = transformedPos.z;
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_011fd9a8))[index].w = radius;
            }
            else
            {
                P3_bbb890 lightDirection;
                lightDirection.x = -reinterpret_cast<const Quad119*>(DAT_011fa1f0)[index].x;
                lightDirection.y = -reinterpret_cast<const Quad119*>(DAT_011fa1f0)[index].y;
                lightDirection.z = -reinterpret_cast<const Quad119*>(DAT_011fa1f0)[index].z;
                P3_bbb890 transformedPos;
                D3DXVec3TransformNormal_00ee6df2(&transformedPos, &lightDirection, &matrix);
                D3DXVec3Normalize_00ee6dec(&lightDirection, &transformedPos);
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_011fd9a8))[index].x = lightDirection.x;
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_011fd9a8))[index].y = lightDirection.y;
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_011fd9a8))[index].z = lightDirection.z;
                reinterpret_cast<Quad119*>(const_cast<float*>(DAT_011fd9a8))[index].w =
                    reinterpret_cast<const Quad119*>(DAT_011fa1f0)[index].w;
            }
        }
    }
    Quad119& diffuseColor = *reinterpret_cast<Quad119*>(const_cast<unsigned char*>(DAT_011FA0D0));
    if (DAT_011f941e && (pProperty->flags & 0x400) > 0 && pass->count > 0 && !pass->lights[0]->kind)
    {
        diffuseColor = QMul(diffuseColor, DAT_011f9184);
    }
    if (id == 0x24b)
    {
        scale = 0;
        if (DAT_011f91b8 != 10)
        {
            Light119* light = pProperty->FUN_00b70590(reinterpret_cast<void*&>(scale));
            if (!light || !light->kind)
                diffuseColor = *reinterpret_cast<const Quad119*>(DAT_011FA0C0);
        }
        else
        {
            Light119* light = pProperty->FUN_00b70590(reinterpret_cast<void*&>(scale));
            if (!light || !light->kind)
            {
                Quad119 color;
                color.x = DAT_01016248;
                color.y = DAT_01016248;
                color.z = DAT_01016248;
                color.w = 1.0f;
                diffuseColor = color;
            }
        }
    }
}

// 0x00b79d70  mov al,[ecx+0x10]; ret
struct C00b79d70
{
    char pad00[0x10];
    unsigned char m10;
    unsigned char NiShader_IsInitialized();
};

// @fnv 0x00b79d70
// src: COMMUNITY 0x00b79d70
unsigned char C00b79d70::NiShader_IsInitialized()
{
    return m10;
}

// 0x00b79d90  mov al,[ecx+0x20]; ret
struct C00b79d90
{
    char pad00[0x20];
    unsigned char m20;
    unsigned char NiD3DShaderInterface_GetIsBestImplementation();
};

// @fnv 0x00b79d90
// src: COMMUNITY 0x00b79d90
unsigned char C00b79d90::NiD3DShaderInterface_GetIsBestImplementation()
{
    return m20;
}

namespace fnv_00bfbf60 {
struct StageReturn
{
    char m_acPad00[0x8];
    unsigned int m_uiUnk08;
    unsigned int m_uiUnk0c;
    char m_acPad10[0x50];
    unsigned int m_uiRefCount;
    void ReturnToPool();
    void DecRefCount()
    {
        --m_uiRefCount;
        if (m_uiRefCount == 0)
            ReturnToPool();
    }
};
void AssignStageFromPool(StageReturn*& rpkStage);
void ConfigureBeamStage(StageReturn* pkStage, unsigned int uiIndex, unsigned int ui, unsigned int uiB,
                        unsigned int uiC);

struct StagePtr_bfbf60
{
    StageReturn* m_pObject;
    StagePtr_bfbf60() : m_pObject(0)
    {}
    ~StagePtr_bfbf60()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
};

extern NiPointer<NiD3DPass> DAT_011fe918;
extern NiPointer<NiD3DPass> DAT_011fe91c;
extern NiPointer<NiD3DPass> DAT_011fe920;
extern NiPointer<NiD3DPass> DAT_011fe924;
extern NiD3DVertexShader* DAT_011fdf24;
extern NiD3DVertexShader* DAT_011fdf28;
extern NiD3DVertexShader* DAT_011fdf2c;
extern NiD3DPixelShader* DAT_011fdbec;
extern NiD3DPixelShader* DAT_011fdbf0;
extern NiD3DPixelShader* DAT_011fdbf4;
extern unsigned int DAT_011fd5a0;
extern unsigned int DAT_011fd5a4;
extern unsigned int DAT_011fd5a8;
extern unsigned int DAT_011fd5ac;
extern unsigned int DAT_011fc9c0;
extern unsigned int DAT_011fc9c4;
extern unsigned int DAT_011fc9c8;
extern unsigned int DAT_011fc9cc;
extern unsigned int DAT_011f9544;

// For each of four global passes, fills missing stages, assigns shader programs, sets render states and writes per-pass constants.
// @fnv 0x00bfbf60
// src: COMMUNITY 0x00bfbf60
void ShadowLightShader_PresetEnvMapPasses_2x()
{
    NiPointer<NiD3DPass> spRenderPass;
    StagePtr_bfbf60 spStage;

    spRenderPass = DAT_011fe918;
    unsigned int uiStageCount = spRenderPass->m_uiStageCount;
    if (uiStageCount < 4)
    {
        AssignStageFromPool(spStage.m_pObject);
        ConfigureBeamStage(spStage.m_pObject, 0, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->m_uiCurrentStage, reinterpret_cast<::BeamStage*>(spStage.m_pObject));
        AssignStageFromPool(spStage.m_pObject);
        ConfigureBeamStage(spStage.m_pObject, 1, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->m_uiCurrentStage, reinterpret_cast<::BeamStage*>(spStage.m_pObject));
        AssignStageFromPool(spStage.m_pObject);
        ConfigureBeamStage(spStage.m_pObject, 2, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->m_uiCurrentStage, reinterpret_cast<::BeamStage*>(spStage.m_pObject));
        AssignStageFromPool(spStage.m_pObject);
        ConfigureBeamStage(spStage.m_pObject, 3, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->m_uiCurrentStage, reinterpret_cast<::BeamStage*>(spStage.m_pObject));
    }
    spRenderPass->m_spVertexShader = DAT_011fdf24;
    spRenderPass->m_spPixelShader = DAT_011fdbec;
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x1b, 1, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x13, 2, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x14, 2, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0xf, 0, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(7, 1, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x17, 3, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0xe, 0, true);
    DAT_011fd5a0 = 0x704;
    DAT_011fc9c0 = 0x24;

    spRenderPass = DAT_011fe91c;
    if (spRenderPass->m_uiStageCount < 4)
    {
        AssignStageFromPool(spStage.m_pObject);
        ConfigureBeamStage(spStage.m_pObject, 0, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->m_uiCurrentStage, reinterpret_cast<::BeamStage*>(spStage.m_pObject));
        AssignStageFromPool(spStage.m_pObject);
        ConfigureBeamStage(spStage.m_pObject, 1, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->m_uiCurrentStage, reinterpret_cast<::BeamStage*>(spStage.m_pObject));
        AssignStageFromPool(spStage.m_pObject);
        ConfigureBeamStage(spStage.m_pObject, 2, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->m_uiCurrentStage, reinterpret_cast<::BeamStage*>(spStage.m_pObject));
        AssignStageFromPool(spStage.m_pObject);
        ConfigureBeamStage(spStage.m_pObject, 3, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->m_uiCurrentStage, reinterpret_cast<::BeamStage*>(spStage.m_pObject));
    }
    spRenderPass->m_spVertexShader = DAT_011fdf28;
    spRenderPass->m_spPixelShader = DAT_011fdbec;
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x1b, 1, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x13, 2, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x14, 2, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0xf, 0, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(7, 1, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x17, 3, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0xe, 0, true);
    DAT_011fd5a4 = 0x2f00;
    DAT_011fc9c4 = 0x24;

    spRenderPass = DAT_011fe920;
    if (spRenderPass->m_uiStageCount < 4)
    {
        AssignStageFromPool(spStage.m_pObject);
        ConfigureBeamStage(spStage.m_pObject, 0, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->m_uiCurrentStage, reinterpret_cast<::BeamStage*>(spStage.m_pObject));
        AssignStageFromPool(spStage.m_pObject);
        ConfigureBeamStage(spStage.m_pObject, 1, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->m_uiCurrentStage, reinterpret_cast<::BeamStage*>(spStage.m_pObject));
        AssignStageFromPool(spStage.m_pObject);
        ConfigureBeamStage(spStage.m_pObject, 2, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->m_uiCurrentStage, reinterpret_cast<::BeamStage*>(spStage.m_pObject));
        AssignStageFromPool(spStage.m_pObject);
        ConfigureBeamStage(spStage.m_pObject, 3, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->m_uiCurrentStage, reinterpret_cast<::BeamStage*>(spStage.m_pObject));
    }
    spRenderPass->m_spVertexShader = DAT_011fdf24;
    spRenderPass->m_spPixelShader = DAT_011fdbf0;
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x1b, 1, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x13, 2, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x14, 2, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0xf, 0, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(7, 1, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x17, 3, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0xe, 0, true);
    DAT_011fd5a8 = 0x704;
    DAT_011fc9c8 = 0x24;

    spRenderPass = DAT_011fe924;
    if (spRenderPass->m_uiStageCount < 2)
    {
        AssignStageFromPool(spStage.m_pObject);
        ConfigureBeamStage(spStage.m_pObject, 0, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->m_uiCurrentStage, reinterpret_cast<::BeamStage*>(spStage.m_pObject));
        AssignStageFromPool(spStage.m_pObject);
        ConfigureBeamStage(spStage.m_pObject, 1, 1, 2, 1);
        spStage.m_pObject->m_uiUnk08 = DAT_011f9544;
        spStage.m_pObject->m_uiUnk0c = 1;
        spRenderPass->NiD3DPass_SetStage(spRenderPass->m_uiCurrentStage, reinterpret_cast<::BeamStage*>(spStage.m_pObject));
    }
    spRenderPass->m_spVertexShader = DAT_011fdf2c;
    spRenderPass->m_spPixelShader = DAT_011fdbf4;
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x1b, 1, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x13, 2, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x14, 2, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0xf, 0, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(7, 1, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x17, 3, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0xe, 0, true);
    DAT_011fd5ac = 0x40704;
    DAT_011fc9cc = 0x2c;
}
}  // namespace fnv_00bfbf60

namespace fnv_00c01c20 {
class FNVConfigMap
{
  public:
    void SetNodeValue(unsigned int id, unsigned int value, unsigned int enabled);
};
FNVConfigMap* __cdecl FUN_00e7f5d0();
struct FNVConfigObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    FNVConfigMap* m_pConfig;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    NiPointer<NiD3DShaderConstantMap> m_spAlpha;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    NiPointer<NiD3DShaderConstantMap> m_spBeta;
    unsigned int unk60;
    unsigned int m_uiReferences;
    void FUN_00e80190();
    void IncRefCount()
    {
        ++m_uiReferences;
    }
    void DecRefCount()
    {
        if (--m_uiReferences == 0)
            FUN_00e80190();
    }
};
extern NiPointer<FNVConfigObject> DAT_011fe7a0;
extern NiPointer<FNVConfigObject> DAT_011fe7a4;
extern NiD3DShaderConstantMap* DAT_011fdf8c;
extern NiD3DShaderConstantMap* DAT_011fdf90;
extern NiD3DShaderConstantMap* DAT_011fdc44;
extern unsigned int DAT_011fd428;
extern unsigned int DAT_011fd42c;
extern unsigned int DAT_011fc848;
extern unsigned int DAT_011fc84c;
extern const float DAT_01200458;

// Assigns shader constant maps and config values to two FNVConfigObject instances and sets four global constants.
// @fnv 0x00c01c20
void __cdecl InitShaderConfigs()
{
    NiPointer<FNVConfigObject> p;
    NiPointer<FNVConfigObject> unused;
    p = DAT_011fe7a0;
    p->m_spBeta = DAT_011fdf8c;
    p->m_spAlpha = DAT_011fdc44;
    if (!p->m_pConfig)
        p->m_pConfig = FUN_00e7f5d0();
    p->m_pConfig->SetNodeValue(27, 0, 1);
    if (!p->m_pConfig)
        p->m_pConfig = FUN_00e7f5d0();
    p->m_pConfig->SetNodeValue(15, 0, 1);
    if (!p->m_pConfig)
        p->m_pConfig = FUN_00e7f5d0();
    p->m_pConfig->SetNodeValue(7, 1, 1);
    if (!p->m_pConfig)
        p->m_pConfig = FUN_00e7f5d0();
    p->m_pConfig->SetNodeValue(23, 4, 1);
    if (!p->m_pConfig)
        p->m_pConfig = FUN_00e7f5d0();
    p->m_pConfig->SetNodeValue(14, 1, 1);
    union FNVBits
    {
        float f;
        unsigned int u;
    } floatBits;
    floatBits.f = DAT_01200458;
    if (!p->m_pConfig)
        p->m_pConfig = FUN_00e7f5d0();
    p->m_pConfig->SetNodeValue(195, floatBits.u, 1);
    if (!p->m_pConfig)
        p->m_pConfig = FUN_00e7f5d0();
    p->m_pConfig->SetNodeValue(22, 1, 1);
    DAT_011fd428 = 0x384000;
    DAT_011fc848 = 0;
    p = DAT_011fe7a4;
    {
        p->m_spBeta = DAT_011fdf90;
        p->m_spAlpha = DAT_011fdc44;
        if (!p->m_pConfig)
            p->m_pConfig = FUN_00e7f5d0();
        p->m_pConfig->SetNodeValue(27, 0, 1);
        if (!p->m_pConfig)
            p->m_pConfig = FUN_00e7f5d0();
        p->m_pConfig->SetNodeValue(15, 0, 1);
        if (!p->m_pConfig)
            p->m_pConfig = FUN_00e7f5d0();
        p->m_pConfig->SetNodeValue(7, 1, 1);
        if (!p->m_pConfig)
            p->m_pConfig = FUN_00e7f5d0();
        p->m_pConfig->SetNodeValue(23, 4, 1);
        if (!p->m_pConfig)
            p->m_pConfig = FUN_00e7f5d0();
        p->m_pConfig->SetNodeValue(14, 1, 1);
        union FNVBits
        {
            float f;
            unsigned int u;
        } floatBits;
        floatBits.f = DAT_01200458;
        if (!p->m_pConfig)
            p->m_pConfig = FUN_00e7f5d0();
        p->m_pConfig->SetNodeValue(195, floatBits.u, 1);
        if (!p->m_pConfig)
            p->m_pConfig = FUN_00e7f5d0();
        p->m_pConfig->SetNodeValue(22, 1, 1);
    }
    DAT_011fd42c = 0x389800;
    DAT_011fc84c = 0;
}
}  // namespace fnv_00c01c20

namespace fnv_00c01f60 {





class StageReturn
{
  public:
    int unk00;
    void ReturnToPool();
};

class DummyStage
{
  public:
    StageReturn* m_pObject;
    DummyStage() : m_pObject(0)
    {}
    __forceinline ~DummyStage()
    {
        if (m_pObject)
        {
            m_pObject->ReturnToPool();
        }
    }
};

extern NiPointer<NiD3DPass> DAT_011fe7a8;
extern NiPointer<NiD3DPass> DAT_011fe7ac;
extern NiPointer<NiD3DPass> DAT_011fe7b0;

extern NiD3DVertexShader* DAT_011fdfac;
extern NiD3DVertexShader* DAT_011fdfb0;
extern NiD3DVertexShader* DAT_011fdfb4;

extern NiD3DPixelShader* DAT_011fdc64;
extern NiD3DPixelShader* DAT_011fdc68;

extern unsigned int DAT_011fd430;
extern unsigned int DAT_011fd434;
extern unsigned int DAT_011fd438;

extern unsigned int DAT_011fc850;
extern unsigned int DAT_011fc854;
extern unsigned int DAT_011fc858;

// @fnv 0x00c01f60
// src: COMMUNITY 0x00c01f60
void ShadowLightShader_PresetLocalMapPasses_2x()
{
    NiPointer<NiD3DPass> spRenderPass;
    DummyStage spStage;

    spRenderPass = DAT_011fe7a8;
    spRenderPass->m_spVertexShader = DAT_011fdfac;
    spRenderPass->m_spPixelShader = DAT_011fdc64;
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x1b, 0, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0xf, 0, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(7, 1, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x17, 4, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0xe, 1, true);
    DAT_011fd430 = 0x4000;
    DAT_011fc850 = 0;

    spRenderPass = DAT_011fe7ac;
    spRenderPass->m_spVertexShader = DAT_011fdfb0;
    spRenderPass->m_spPixelShader = DAT_011fdc64;
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x1b, 0, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0xf, 0, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(7, 1, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x17, 4, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0xe, 1, true);
    DAT_011fd434 = 0x8800;
    DAT_011fc854 = 0;

    spRenderPass = DAT_011fe7b0;
    spRenderPass->m_spVertexShader = DAT_011fdfb4;
    spRenderPass->m_spPixelShader = DAT_011fdc68;
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x1b, 0, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0xf, 0, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(7, 1, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0x17, 8, true);
    spRenderPass->GetRenderStateGroup()->SetRenderState(0xe, 1, true);
    DAT_011fd438 = 0;
    DAT_011fc858 = 0;
}
}  // namespace fnv_00c01f60

struct LightManager
{
    void NiDX9Renderer_CalculateBoneMatrices(void* geometry, int transform, int flag0, int pass, int enabled);
};
extern LightManager* DAT_011f9508;
extern void* DAT_0126f74c;
extern "C" const char DAT_010A1CAC[];

struct ShaderVirtualObject
{
    void** vtable;
};
typedef void*(__thiscall* FindConstantFn)(void*, const char*, void*, unsigned short, int, void*);
typedef void(__thiscall* ApplyConstantFn)(void*, void*);
typedef void(__thiscall* ApplyConstantDataFn)(void*, void*, void*, unsigned short, int, void*);

struct ShaderAdapter : ShadowLightShader
{
    int ApplyShaderConstants(int a1, void* geometry, void* constantData, int a4, int a5, int a6, int transform, int a8);
};

// Applies shader constants to a geometry pass using fog or second shader constant maps when specific layout and object conditions are met.
// @fnv 0x00b7a2c0
int ShaderAdapter::ApplyShaderConstants(int a1, void* geometry, void* constantData, int a4, int a5, int a6,
                                        int transform, int a8)
{
    if ((constantData && *reinterpret_cast<int*>(layoutPadding38) == 0 && DAT_011fec00.m_pObject &&
         *reinterpret_cast<char*>(reinterpret_cast<char*>(DAT_011fec00.m_pObject) + 8)) ||
        m_spSecondShaderConstantMap.m_pObject == m_spFogConstantMap.m_pObject)
    {
        DAT_011f9508->NiDX9Renderer_CalculateBoneMatrices(geometry, transform, 0, 3, 1);
        void* geometryData = *reinterpret_cast<void**>(reinterpret_cast<char*>(geometry) + 0x28);
        if (m_spSecondShaderConstantMap.m_pObject == m_spFogConstantMap.m_pObject)
        {
            ShaderVirtualObject* pass =
                *reinterpret_cast<ShaderVirtualObject**>(reinterpret_cast<char*>(DAT_0126f74c) + 0x5c);
            ShaderVirtualObject* map = reinterpret_cast<ShaderVirtualObject*>(m_spFogConstantMap.m_pObject);
            void** applySlot = pass->vtable + 30;
            void* result = reinterpret_cast<FindConstantFn>(reinterpret_cast<void* volatile*>(map->vtable)[28])(
                map, DAT_010A1CAC, geometryData,
                *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(constantData) + 0x20), 3,
                *reinterpret_cast<void**>(reinterpret_cast<char*>(constantData) + 4));
            reinterpret_cast<ApplyConstantFn>(*applySlot)(pass, result);
        }
        else
        {
            ShaderVirtualObject* pass =
                *reinterpret_cast<ShaderVirtualObject**>(reinterpret_cast<char*>(DAT_0126f74c) + 0x5c);
            reinterpret_cast<ApplyConstantDataFn>(pass->vtable[30])(
                pass, DAT_011fec00.m_pObject, geometryData,
                *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(constantData) + 0x20), 3,
                *reinterpret_cast<void**>(reinterpret_cast<char*>(constantData) + 4));
        }
    }
    return 0;
}

namespace fnv_00beac70 {
struct StageReturn : public NiMemObject
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
    int m_uiRefCount;
    void ReturnToPool();
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
        {
            ReturnToPool();
        }
    }
};

class StageReturnHolder
{
  public:
    StageReturn* m_pObject;
    StageReturnHolder() : m_pObject(0)
    {}
    ~StageReturnHolder()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
        }
    }
};

class PassSubObject
{
  public:
    void SetNodeValue(unsigned int a, unsigned int b, unsigned int c);
};

class Pass : public NiMemObject
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* unk14;
    unsigned int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    PassSubObject* unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    NiPointer<NiD3DShaderConstantMap> unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    NiPointer<NiD3DShaderConstantMap> unk5c;
    int unk60;
    unsigned int m_uiRefCount;

    void NiD3DPass_SetStage(void* a, StageReturn* b);
    void Release();
};

class PassPointer
{
  public:
    Pass* m_pObject;
    PassPointer() : m_pObject(0)
    {}
    ~PassPointer()
    {
        if (m_pObject)
        {
            if (--m_pObject->m_uiRefCount == 0)
            {
                m_pObject->Release();
            }
        }
    }
    PassPointer& operator=(const PassPointer& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
            {
                if (--m_pObject->m_uiRefCount == 0)
                {
                    m_pObject->Release();
                }
            }
            m_pObject = other.m_pObject;
            if (m_pObject)
            {
                ++m_pObject->m_uiRefCount;
            }
        }
        return *this;
    }
    operator Pass*() const
    {
        return m_pObject;
    }
    Pass* operator->() const
    {
        return m_pObject;
    }
};

extern PassPointer DAT_011fe930;
extern PassPointer DAT_011fe934;
extern NiD3DShaderConstantMap* DAT_011fde00;
extern NiD3DShaderConstantMap* DAT_011fde58;
extern NiD3DShaderConstantMap* DAT_011fdb00;
extern int DAT_011fd5b8;
extern int DAT_011fd5bc;
extern int DAT_011fc9d8;
extern int DAT_011fc9dc;

extern void AssignStageFromPool(StageReturn*&);
extern int ConfigureBeamStage(void*, int, int, int, int);
extern PassSubObject* FUN_00e7f5d0();

// Configures two beam render passes by assigning stages, setting shader constant maps, and updating sub-object node values.
// @fnv 0x00beac70
void ConfigureBeamPasses()
{
    PassPointer spRenderPass;
    StageReturnHolder stageReturn;

    spRenderPass = DAT_011fe930;

    unsigned int type = spRenderPass->unk18;
    if (type < 2)
    {
        AssignStageFromPool(stageReturn.m_pObject);
        ConfigureBeamStage(stageReturn.m_pObject, 0, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->unk14, stageReturn.m_pObject);
        AssignStageFromPool(stageReturn.m_pObject);
        ConfigureBeamStage(stageReturn.m_pObject, 1, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->unk14, stageReturn.m_pObject);
    }

    spRenderPass->unk5c = DAT_011fde00;
    spRenderPass->unk44 = DAT_011fdb00;

    if (!spRenderPass->unk30)
    {
        spRenderPass->unk30 = FUN_00e7f5d0();
    }
    spRenderPass->unk30->SetNodeValue(0x1b, 1, 1);

    if (!spRenderPass->unk30)
    {
        spRenderPass->unk30 = FUN_00e7f5d0();
    }
    spRenderPass->unk30->SetNodeValue(0x13, 5, 1);

    if (!spRenderPass->unk30)
    {
        spRenderPass->unk30 = FUN_00e7f5d0();
    }
    spRenderPass->unk30->SetNodeValue(0x14, 6, 1);

    if (!spRenderPass->unk30)
    {
        spRenderPass->unk30 = FUN_00e7f5d0();
    }
    spRenderPass->unk30->SetNodeValue(0xf, 0, 1);

    if (!spRenderPass->unk30)
    {
        spRenderPass->unk30 = FUN_00e7f5d0();
    }
    spRenderPass->unk30->SetNodeValue(7, 1, 1);

    if (!spRenderPass->unk30)
    {
        spRenderPass->unk30 = FUN_00e7f5d0();
    }
    spRenderPass->unk30->SetNodeValue(0x17, 3, 1);

    if (!spRenderPass->unk30)
    {
        spRenderPass->unk30 = FUN_00e7f5d0();
    }
    spRenderPass->unk30->SetNodeValue(0xe, 0, 1);

    DAT_011fd5b8 = 0;
    DAT_011fc9d8 = 0;

    spRenderPass = DAT_011fe934;

    if (spRenderPass->unk18 < 2)
    {
        AssignStageFromPool(stageReturn.m_pObject);
        ConfigureBeamStage(stageReturn.m_pObject, 0, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->unk14, stageReturn.m_pObject);
        AssignStageFromPool(stageReturn.m_pObject);
        ConfigureBeamStage(stageReturn.m_pObject, 1, 1, 2, 1);
        spRenderPass->NiD3DPass_SetStage(spRenderPass->unk14, stageReturn.m_pObject);
    }

    spRenderPass->unk5c = DAT_011fde58;
    spRenderPass->unk44 = DAT_011fdb00;

    if (!spRenderPass->unk30)
    {
        spRenderPass->unk30 = FUN_00e7f5d0();
    }
    spRenderPass->unk30->SetNodeValue(0x1b, 1, 1);

    if (!spRenderPass->unk30)
    {
        spRenderPass->unk30 = FUN_00e7f5d0();
    }
    spRenderPass->unk30->SetNodeValue(0x13, 5, 1);

    if (!spRenderPass->unk30)
    {
        spRenderPass->unk30 = FUN_00e7f5d0();
    }
    spRenderPass->unk30->SetNodeValue(0x14, 6, 1);

    if (!spRenderPass->unk30)
    {
        spRenderPass->unk30 = FUN_00e7f5d0();
    }
    spRenderPass->unk30->SetNodeValue(0xf, 0, 1);

    if (!spRenderPass->unk30)
    {
        spRenderPass->unk30 = FUN_00e7f5d0();
    }
    spRenderPass->unk30->SetNodeValue(7, 1, 1);

    if (!spRenderPass->unk30)
    {
        spRenderPass->unk30 = FUN_00e7f5d0();
    }
    spRenderPass->unk30->SetNodeValue(0x17, 3, 1);

    if (!spRenderPass->unk30)
    {
        spRenderPass->unk30 = FUN_00e7f5d0();
    }
    spRenderPass->unk30->SetNodeValue(0xe, 0, 1);

    DAT_011fd5bc = 0;
    DAT_011fc9dc = 0;
}
}  // namespace fnv_00beac70

namespace fnv_00bfc860 {
class BeamStage
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int m_uiRefCount;
    void NiD3DTextureStage_ReturnStageToPool();
    void ApplyPairToState(unsigned int mode);
    void IncRefCount()
    {
        ++m_uiRefCount;
    }
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
extern "C" void __cdecl AssignStageFromPool(NiPointer<BeamStage>& stage);
extern "C" void __cdecl ConfigureBeamStage(BeamStage* stage, unsigned int index, unsigned char a, unsigned int b,
                                           unsigned char c);
extern unsigned char DAT_011ad80c;
extern unsigned int DAT_011f953c, DAT_011f9540, DAT_011f9534;
extern unsigned int DAT_011fab2c;
extern unsigned int DAT_011fab30;
extern unsigned int DAT_011fb09c;
extern unsigned int DAT_011fb0a0;
extern unsigned int DAT_011fb0a8;
extern unsigned int DAT_011fb0ac;
extern unsigned int DAT_011fb0b4;
extern unsigned int DAT_011fb0b8;
extern unsigned int DAT_011fb0bc;
extern unsigned int DAT_011fb0c0;
extern unsigned int DAT_011fb0c4;
extern unsigned int DAT_011fb0c8;
extern unsigned int DAT_011fb0cc;
extern unsigned int DAT_011fb0d0;
extern unsigned int DAT_011fb0d4;
extern unsigned int DAT_011fb0d8;
extern unsigned int DAT_011fb0dc;
extern unsigned int DAT_011fb0e0;
extern unsigned int DAT_011fb0e4;
extern unsigned int DAT_011fb0e8;
extern unsigned int DAT_011fb0ec;
extern unsigned int DAT_011fb0f0;
extern unsigned int DAT_011fb0f4;
extern unsigned int DAT_011fb0f8;
extern unsigned int DAT_011fb0fc;
extern unsigned int DAT_011fb100;
extern unsigned int DAT_011fb104;
extern unsigned int DAT_011fb108;
extern unsigned int DAT_011fb10c;
extern unsigned int DAT_011fb110;
extern unsigned int DAT_011fb114;
extern unsigned int DAT_011fb118;
extern unsigned int DAT_011fb11c;
extern unsigned int DAT_011fb120;
extern unsigned int DAT_011fb124;
extern unsigned int DAT_011fb128;
extern unsigned int DAT_011fb12c;
extern unsigned int DAT_011fb130;
extern unsigned int DAT_011fb134;
extern unsigned int DAT_011fb138;
extern unsigned int DAT_011fb13c;
extern unsigned int DAT_011fb140;
extern unsigned int DAT_011fb144;
extern unsigned int DAT_011fb148;
extern unsigned int DAT_011fb14c;
extern unsigned int DAT_011fb150;
extern unsigned int DAT_011fb154;
extern unsigned int DAT_011fb158;
extern unsigned int DAT_011fb15c;
extern unsigned int DAT_011fb160;
extern unsigned int DAT_011fb164;
extern unsigned int DAT_011fb168;
extern unsigned int DAT_011fb16c;
extern unsigned int DAT_011fb170;
extern unsigned int DAT_011fb174;
extern unsigned int DAT_011fb178;
extern unsigned int DAT_011fb17c;
extern unsigned int DAT_011fb180;
extern unsigned int DAT_011fb184;
extern unsigned int DAT_011fb188;
extern unsigned int DAT_011fb18c;
extern unsigned int DAT_011fb190;
extern unsigned int DAT_011fb194;
extern unsigned int DAT_011fb198;
extern unsigned int DAT_011fb19c;
extern unsigned int DAT_011fb1a0;
extern unsigned int DAT_011fb70c;
extern unsigned int DAT_011fb710;
extern unsigned int DAT_011fbc88;
extern unsigned int DAT_011fbc8c;
extern unsigned int DAT_011fbc9c;
extern unsigned int DAT_011fbca0;
extern unsigned int DAT_011fbca4;
extern unsigned int DAT_011fbca8;
extern unsigned int DAT_011fbcac;
extern unsigned int DAT_011fbcb0;
extern unsigned int DAT_011fbcb4;
extern unsigned int DAT_011fbcb8;
extern unsigned int DAT_011fbcbc;
extern unsigned int DAT_011fbcc0;
extern unsigned int DAT_011fbcc4;
extern unsigned int DAT_011fbcc8;
extern unsigned int DAT_011fbccc;
extern unsigned int DAT_011fbcd0;
extern unsigned int DAT_011fbcd4;
extern unsigned int DAT_011fbcd8;
extern unsigned int DAT_011fbcdc;
extern unsigned int DAT_011fbce0;
extern unsigned int DAT_011fbce4;
extern unsigned int DAT_011fbce8;
extern unsigned int DAT_011fbcec;
extern unsigned int DAT_011fbcf0;
extern unsigned int DAT_011fbcf4;
extern unsigned int DAT_011fbcf8;
extern unsigned int DAT_011fbcfc;
extern unsigned int DAT_011fbd00;
extern unsigned int DAT_011fbd04;
extern unsigned int DAT_011fbd08;
extern unsigned int DAT_011fbd0c;
extern unsigned int DAT_011fbd10;
extern unsigned int DAT_011fbd14;
extern unsigned int DAT_011fbd18;
extern unsigned int DAT_011fbd1c;
extern unsigned int DAT_011fbd20;
extern unsigned int DAT_011fbd24;
extern unsigned int DAT_011fbd28;
extern unsigned int DAT_011fbd2c;
extern unsigned int DAT_011fbd30;
extern unsigned int DAT_011fbd34;
extern unsigned int DAT_011fbd38;
extern unsigned int DAT_011fbd3c;
extern unsigned int DAT_011fbd40;
extern unsigned int DAT_011fbd44;
extern unsigned int DAT_011fbd48;
extern unsigned int DAT_011fbd4c;
extern unsigned int DAT_011fbd50;
extern unsigned int DAT_011fbd54;
extern unsigned int DAT_011fbd58;
extern unsigned int DAT_011fbd5c;
extern unsigned int DAT_011fbd60;
extern unsigned int DAT_011fbd64;
extern unsigned int DAT_011fbd68;
extern unsigned int DAT_011fbd6c;
extern unsigned int DAT_011fbd70;
extern unsigned int DAT_011fbd74;
extern unsigned int DAT_011fbd78;
extern unsigned int DAT_011fbd7c;
extern unsigned int DAT_011fbd80;
extern unsigned int DAT_011fc2ec;
extern unsigned int DAT_011fc2f0;
extern unsigned int DAT_011fc85c;
extern unsigned int DAT_011fc860;
extern unsigned int DAT_011fc864;
extern unsigned int DAT_011fc868;
extern unsigned int DAT_011fc86c;
extern unsigned int DAT_011fc870;
extern unsigned int DAT_011fc874;
extern unsigned int DAT_011fc878;
extern unsigned int DAT_011fc87c;
extern unsigned int DAT_011fc880;
extern unsigned int DAT_011fc884;
extern unsigned int DAT_011fc888;
extern unsigned int DAT_011fc88c;
extern unsigned int DAT_011fc890;
extern unsigned int DAT_011fc894;
extern unsigned int DAT_011fc898;
extern unsigned int DAT_011fc89c;
extern unsigned int DAT_011fc8a0;
extern unsigned int DAT_011fc8a4;
extern unsigned int DAT_011fc8a8;
extern unsigned int DAT_011fc8ac;
extern unsigned int DAT_011fc8b0;
extern unsigned int DAT_011fc8b4;
extern unsigned int DAT_011fc8b8;
extern unsigned int DAT_011fc8bc;
extern unsigned int DAT_011fc8c0;
extern unsigned int DAT_011fc8c4;
extern unsigned int DAT_011fc8c8;
extern unsigned int DAT_011fc8cc;
extern unsigned int DAT_011fc8d0;
extern unsigned int DAT_011fc8d4;
extern unsigned int DAT_011fc8d8;
extern unsigned int DAT_011fc8dc;
extern unsigned int DAT_011fc8e0;
extern unsigned int DAT_011fc8e4;
extern unsigned int DAT_011fc8e8;
extern unsigned int DAT_011fc8ec;
extern unsigned int DAT_011fc8f0;
extern unsigned int DAT_011fc8f4;
extern unsigned int DAT_011fc8f8;
extern unsigned int DAT_011fc8fc;
extern unsigned int DAT_011fc900;
extern unsigned int DAT_011fc904;
extern unsigned int DAT_011fc908;
extern unsigned int DAT_011fc90c;
extern unsigned int DAT_011fc910;
extern unsigned int DAT_011fc914;
extern unsigned int DAT_011fc918;
extern unsigned int DAT_011fc91c;
extern unsigned int DAT_011fc920;
extern unsigned int DAT_011fc924;
extern unsigned int DAT_011fc928;
extern unsigned int DAT_011fc92c;
extern unsigned int DAT_011fc930;
extern unsigned int DAT_011fc934;
extern unsigned int DAT_011fc938;
extern unsigned int DAT_011fc93c;
extern unsigned int DAT_011fc940;
extern unsigned int DAT_011fc944;
extern unsigned int DAT_011fc948;
extern unsigned int DAT_011fc94c;
extern unsigned int DAT_011fc950;
extern unsigned int DAT_011fc954;
extern unsigned int DAT_011fc958;
extern unsigned int DAT_011fc95c;
extern unsigned int DAT_011fc960;
extern unsigned int DAT_011fcecc;
extern unsigned int DAT_011fced0;
extern unsigned int DAT_011fd43c;
extern unsigned int DAT_011fd440;
extern unsigned int DAT_011fd444;
extern unsigned int DAT_011fd448;
extern unsigned int DAT_011fd44c;
extern unsigned int DAT_011fd450;
extern unsigned int DAT_011fd454;
extern unsigned int DAT_011fd458;
extern unsigned int DAT_011fd45c;
extern unsigned int DAT_011fd460;
extern unsigned int DAT_011fd464;
extern unsigned int DAT_011fd468;
extern unsigned int DAT_011fd46c;
extern unsigned int DAT_011fd470;
extern unsigned int DAT_011fd474;
extern unsigned int DAT_011fd478;
extern unsigned int DAT_011fd47c;
extern unsigned int DAT_011fd480;
extern unsigned int DAT_011fd484;
extern unsigned int DAT_011fd488;
extern unsigned int DAT_011fd48c;
extern unsigned int DAT_011fd490;
extern unsigned int DAT_011fd494;
extern unsigned int DAT_011fd498;
extern unsigned int DAT_011fd49c;
extern unsigned int DAT_011fd4a0;
extern unsigned int DAT_011fd4a4;
extern unsigned int DAT_011fd4a8;
extern unsigned int DAT_011fd4ac;
extern unsigned int DAT_011fd4b0;
extern unsigned int DAT_011fd4b4;
extern unsigned int DAT_011fd4b8;
extern unsigned int DAT_011fd4bc;
extern unsigned int DAT_011fd4c0;
extern unsigned int DAT_011fd4c4;
extern unsigned int DAT_011fd4c8;
extern unsigned int DAT_011fd4cc;
extern unsigned int DAT_011fd4d0;
extern unsigned int DAT_011fd4d4;
extern unsigned int DAT_011fd4d8;
extern unsigned int DAT_011fd4dc;
extern unsigned int DAT_011fd4e0;
extern unsigned int DAT_011fd4e4;
extern unsigned int DAT_011fd4e8;
extern unsigned int DAT_011fd4ec;
extern unsigned int DAT_011fd4f0;
extern unsigned int DAT_011fd4f4;
extern unsigned int DAT_011fd4f8;
extern unsigned int DAT_011fd4fc;
extern unsigned int DAT_011fd500;
extern unsigned int DAT_011fd504;
extern unsigned int DAT_011fd508;
extern unsigned int DAT_011fd50c;
extern unsigned int DAT_011fd510;
extern unsigned int DAT_011fd514;
extern unsigned int DAT_011fd518;
extern unsigned int DAT_011fd51c;
extern unsigned int DAT_011fd520;
extern unsigned int DAT_011fd524;
extern unsigned int DAT_011fd528;
extern unsigned int DAT_011fd52c;
extern unsigned int DAT_011fd530;
extern unsigned int DAT_011fd534;
extern unsigned int DAT_011fd538;
extern unsigned int DAT_011fd53c;
extern unsigned int DAT_011fd540;
extern NiD3DPixelShader* DAT_011fdbf8;
extern NiD3DPixelShader* DAT_011fdbfc;
extern NiD3DPixelShader* DAT_011fdc00;
extern NiD3DPixelShader* DAT_011fdc0c;
extern NiD3DPixelShader* DAT_011fdc48;
extern NiD3DPixelShader* DAT_011fdc4c;
extern NiD3DPixelShader* DAT_011fdc50;
extern NiD3DPixelShader* DAT_011fdc54;
extern NiD3DPixelShader* DAT_011fdc58;
extern NiD3DPixelShader* DAT_011fdc5c;
extern NiD3DPixelShader* DAT_011fdc60;
extern NiD3DPixelShader* DAT_011fdc78;
extern NiD3DPixelShader* DAT_011fdc7c;
extern NiD3DPixelShader* DAT_011fdc80;
extern NiD3DPixelShader* DAT_011fdc84;
extern NiD3DPixelShader* DAT_011fdc88;
extern NiD3DPixelShader* DAT_011fdc8c;
extern NiD3DPixelShader* DAT_011fdc90;
extern NiD3DPixelShader* DAT_011fdc94;
extern NiD3DPixelShader* DAT_011fdc98;
extern NiD3DPixelShader* DAT_011fdc9c;
extern NiD3DPixelShader* DAT_011fdca0;
extern NiD3DPixelShader* DAT_011fdca4;
extern NiD3DPixelShader* DAT_011fdca8;
extern NiD3DPixelShader* DAT_011fdcac;
extern NiD3DPixelShader* DAT_011fdcb0;
extern NiD3DPixelShader* DAT_011fdcb4;
extern NiD3DPixelShader* DAT_011fdcb8;
extern NiD3DPixelShader* DAT_011fdcbc;
extern NiD3DPixelShader* DAT_011fdcc0;
extern NiD3DPixelShader* DAT_011fdcc4;
extern NiD3DPixelShader* DAT_011fdcc8;
extern NiD3DPixelShader* DAT_011fdccc;
extern NiD3DPixelShader* DAT_011fdcd0;
extern NiD3DPixelShader* DAT_011fdcd4;
extern NiD3DPixelShader* DAT_011fdcd8;
extern NiD3DPixelShader* DAT_011fdcdc;
extern NiD3DPixelShader* DAT_011fdce0;
extern NiD3DPixelShader* DAT_011fdce4;
extern NiD3DPixelShader* DAT_011fdce8;
extern NiD3DPixelShader* DAT_011fdcec;
extern NiD3DPixelShader* DAT_011fdcf0;
extern NiD3DPixelShader* DAT_011fdcf4;
extern NiD3DPixelShader* DAT_011fdcf8;
extern NiD3DPixelShader* DAT_011fdcfc;
extern NiD3DPixelShader* DAT_011fdd00;
extern NiD3DPixelShader* DAT_011fdd04;
extern NiD3DPixelShader* DAT_011fdd08;
extern NiD3DPixelShader* DAT_011fdd0c;
extern NiD3DPixelShader* DAT_011fdd10;
extern NiD3DPixelShader* DAT_011fdd14;
extern NiD3DPixelShader* DAT_011fdd18;
extern NiD3DPixelShader* DAT_011fdd1c;
extern NiD3DPixelShader* DAT_011fdd20;
extern NiD3DPixelShader* DAT_011fdd24;
extern NiD3DPixelShader* DAT_011fdd28;
extern NiD3DPixelShader* DAT_011fdd2c;
extern NiD3DPixelShader* DAT_011fdd30;
extern NiD3DPixelShader* DAT_011fdd34;
extern NiD3DPixelShader* DAT_011fdd38;
extern NiD3DPixelShader* DAT_011fdd3c;
extern NiD3DPixelShader* DAT_011fdd40;
extern NiD3DPixelShader* DAT_011fdd44;
extern NiD3DPixelShader* DAT_011fdd48;
extern NiD3DPixelShader* DAT_011fdd4c;
extern NiD3DPixelShader* DAT_011fdd50;
extern NiD3DPixelShader* DAT_011fdd54;
extern NiD3DPixelShader* DAT_011fdd58;
extern NiD3DVertexShader* DAT_011fdf30;
extern NiD3DVertexShader* DAT_011fdf34;
extern NiD3DVertexShader* DAT_011fdf38;
extern NiD3DVertexShader* DAT_011fdf44;
extern NiD3DVertexShader* DAT_011fdf94;
extern NiD3DVertexShader* DAT_011fdf98;
extern NiD3DVertexShader* DAT_011fdf9c;
extern NiD3DVertexShader* DAT_011fdfa0;
extern NiD3DVertexShader* DAT_011fdfa4;
extern NiD3DVertexShader* DAT_011fdfa8;
extern NiD3DVertexShader* DAT_011fdfec;
extern NiD3DVertexShader* DAT_011fdff0;
extern NiPointer<NiD3DPass> DAT_011fe244;
extern NiPointer<NiD3DPass> DAT_011fe248;
extern NiPointer<NiD3DPass> DAT_011fe7b4;
extern NiPointer<NiD3DPass> DAT_011fe7b8;
extern NiPointer<NiD3DPass> DAT_011fe7bc;
extern NiPointer<NiD3DPass> DAT_011fe7c0;
extern NiPointer<NiD3DPass> DAT_011fe7c4;
extern NiPointer<NiD3DPass> DAT_011fe7c8;
extern NiPointer<NiD3DPass> DAT_011fe7cc;
extern NiPointer<NiD3DPass> DAT_011fe7d0;
extern NiPointer<NiD3DPass> DAT_011fe7d4;
extern NiPointer<NiD3DPass> DAT_011fe7d8;
extern NiPointer<NiD3DPass> DAT_011fe7dc;
extern NiPointer<NiD3DPass> DAT_011fe7e0;
extern NiPointer<NiD3DPass> DAT_011fe7e4;
extern NiPointer<NiD3DPass> DAT_011fe7e8;
extern NiPointer<NiD3DPass> DAT_011fe7ec;
extern NiPointer<NiD3DPass> DAT_011fe7f0;
extern NiPointer<NiD3DPass> DAT_011fe7f4;
extern NiPointer<NiD3DPass> DAT_011fe7f8;
extern NiPointer<NiD3DPass> DAT_011fe7fc;
extern NiPointer<NiD3DPass> DAT_011fe800;
extern NiPointer<NiD3DPass> DAT_011fe804;
extern NiPointer<NiD3DPass> DAT_011fe808;
extern NiPointer<NiD3DPass> DAT_011fe80c;
extern NiPointer<NiD3DPass> DAT_011fe810;
extern NiPointer<NiD3DPass> DAT_011fe814;
extern NiPointer<NiD3DPass> DAT_011fe818;
extern NiPointer<NiD3DPass> DAT_011fe81c;
extern NiPointer<NiD3DPass> DAT_011fe820;
extern NiPointer<NiD3DPass> DAT_011fe824;
extern NiPointer<NiD3DPass> DAT_011fe828;
extern NiPointer<NiD3DPass> DAT_011fe82c;
extern NiPointer<NiD3DPass> DAT_011fe830;
extern NiPointer<NiD3DPass> DAT_011fe834;
extern NiPointer<NiD3DPass> DAT_011fe838;
extern NiPointer<NiD3DPass> DAT_011fe83c;
extern NiPointer<NiD3DPass> DAT_011fe840;
extern NiPointer<NiD3DPass> DAT_011fe844;
extern NiPointer<NiD3DPass> DAT_011fe848;
extern NiPointer<NiD3DPass> DAT_011fe84c;
extern NiPointer<NiD3DPass> DAT_011fe850;
extern NiPointer<NiD3DPass> DAT_011fe854;
extern NiPointer<NiD3DPass> DAT_011fe858;
extern NiPointer<NiD3DPass> DAT_011fe85c;
extern NiPointer<NiD3DPass> DAT_011fe860;
extern NiPointer<NiD3DPass> DAT_011fe864;
extern NiPointer<NiD3DPass> DAT_011fe868;
extern NiPointer<NiD3DPass> DAT_011fe86c;
extern NiPointer<NiD3DPass> DAT_011fe870;
extern NiPointer<NiD3DPass> DAT_011fe874;
extern NiPointer<NiD3DPass> DAT_011fe878;
extern NiPointer<NiD3DPass> DAT_011fe87c;
extern NiPointer<NiD3DPass> DAT_011fe880;
extern NiPointer<NiD3DPass> DAT_011fe884;
extern NiPointer<NiD3DPass> DAT_011fe888;
extern NiPointer<NiD3DPass> DAT_011fe88c;
extern NiPointer<NiD3DPass> DAT_011fe894;
extern NiPointer<NiD3DPass> DAT_011fe898;
extern NiPointer<NiD3DPass> DAT_011fe89c;
extern NiPointer<NiD3DPass> DAT_011fe8a0;
extern NiPointer<NiD3DPass> DAT_011fe8a4;
extern NiPointer<NiD3DPass> DAT_011fe8a8;
extern NiPointer<NiD3DPass> DAT_011fe8ac;
extern NiPointer<NiD3DPass> DAT_011fe8b0;
extern NiPointer<NiD3DPass> DAT_011fe8b4;
extern NiPointer<NiD3DPass> DAT_011fe8b8;
// Ensures stage counts, configures beam stages and render states on many pass objects, and assigns global values.
// @fnv 0x00bfc860
void InitializeBeamPasses()
{
    NiPointer<NiD3DPass> system;
    NiPointer<BeamStage> temporary;
    system = DAT_011fe244;
    if (system->GetStageCount() < 2)
    {
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 0, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 1, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
    }
    system->SetVertexShader(DAT_011fdf94);
    system->SetPixelShader(DAT_011fdc48);
    system->SetRenderState(27, 0, true);
    system->SetRenderState(15, 0, true);
    system->SetRenderState(7, 1, true);
    system->SetRenderState(23, 4, true);
    system->SetRenderState(14, 1, true);
    DAT_011fcecc = 128;
    DAT_011fc2ec = 12;
    DAT_011fb70c = 128;
    DAT_011fab2c = 4;
    system = DAT_011fe7c0;
    if (system->GetStageCount() < 2)
    {
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 0, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 1, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
    }
    system->SetVertexShader(DAT_011fdf98);
    system->SetPixelShader(DAT_011fdc4c);
    system->SetRenderState(27, 1, true);
    system->SetRenderState(19, 5, true);
    system->SetRenderState(20, 6, true);
    system->SetRenderState(15, 1, true);
    system->SetRenderState(25, 5, true);
    system->SetRenderState(24, 0, true);
    system->SetRenderState(7, 1, true);
    system->SetRenderState(23, 4, true);
    system->SetRenderState(14, 0, true);
    DAT_011fd448 = 128;
    DAT_011fc868 = 12;
    DAT_011fbc88 = 128;
    DAT_011fb0a8 = 4;
    system = DAT_011fe8b8;
    if (system->GetStageCount() < 2)
    {
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 0, 1, 2, 1);
        temporary->ApplyPairToState(0);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 1, 1, 2, 1);
        temporary->ApplyPairToState(0);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 2, 1, 2, 1);
        unsigned int source = *(DAT_011ad80c ? &DAT_011f953c : &DAT_011f9540);
        temporary->unk08 = source;
        temporary->unk0c = 1;
        temporary->ApplyPairToState(3);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
    }
    system->SetVertexShader(DAT_011fdf9c);
    system->SetPixelShader(DAT_011fdc50);
    system->SetRenderState(27, 1, true);
    system->SetRenderState(19, 5, true);
    system->SetRenderState(20, 6, true);
    system->SetRenderState(15, 1, true);
    system->SetRenderState(25, 5, true);
    system->SetRenderState(24, 0, true);
    system->SetRenderState(7, 1, true);
    system->SetRenderState(23, 4, true);
    system->SetRenderState(14, 0, true);
    DAT_011fd540 = 4195200;
    DAT_011fc960 = 12;
    DAT_011fbd80 = 128;
    DAT_011fb1a0 = 772;
    system = DAT_011fe7bc;
    if (system->GetStageCount() < 2)
    {
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 0, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 1, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
    }
    system->SetVertexShader(DAT_011fdfa0);
    system->SetPixelShader(DAT_011fdc54);
    system->SetRenderState(19, 5, true);
    system->SetRenderState(20, 2, true);
    system->SetRenderState(15, 1, true);
    system->SetRenderState(25, 5, true);
    system->SetRenderState(24, 0, true);
    system->SetRenderState(7, 1, true);
    system->SetRenderState(23, 4, true);
    system->SetRenderState(14, 0, true);
    DAT_011fd444 = 0;
    DAT_011fc864 = 8;
    system = DAT_011fe7c8;
    if (system->GetStageCount() < 2)
    {
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 0, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 1, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
    }
    system->SetVertexShader(DAT_011fdfa0);
    system->SetPixelShader(DAT_011fdc58);
    system->SetRenderState(27, 1, true);
    system->SetRenderState(19, 5, true);
    system->SetRenderState(20, 2, true);
    system->SetRenderState(15, 1, true);
    system->SetRenderState(25, 5, true);
    system->SetRenderState(24, 0, true);
    system->SetRenderState(7, 1, true);
    system->SetRenderState(23, 4, true);
    system->SetRenderState(14, 0, true);
    DAT_011fd450 = 0;
    DAT_011fc870 = 8;
    system = DAT_011fe7b4;
    if (system->GetStageCount() < 2)
    {
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 0, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 1, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
    }
    system->SetVertexShader(DAT_011fdfa4);
    system->SetPixelShader(DAT_011fdc5c);
    system->SetRenderState(19, 5, true);
    system->SetRenderState(20, 2, true);
    system->SetRenderState(15, 1, true);
    system->SetRenderState(25, 5, true);
    system->SetRenderState(24, 0, true);
    system->SetRenderState(7, 1, true);
    system->SetRenderState(23, 4, true);
    system->SetRenderState(14, 0, true);
    DAT_011fd43c = 128;
    DAT_011fc85c = 8;
    DAT_011fb09c = 0;
    system = DAT_011fe7cc;
    if (system->GetStageCount() < 2)
    {
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 0, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 1, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
    }
    system->SetVertexShader(DAT_011fdfa8);
    system->SetPixelShader(DAT_011fdc60);
    system->SetRenderState(27, 1, true);
    system->SetRenderState(19, 5, true);
    system->SetRenderState(20, 2, true);
    system->SetRenderState(15, 1, true);
    system->SetRenderState(25, 5, true);
    system->SetRenderState(24, 0, true);
    system->SetRenderState(7, 1, true);
    system->SetRenderState(23, 4, true);
    system->SetRenderState(14, 0, true);
    DAT_011fd454 = 128;
    DAT_011fc874 = 28;
    DAT_011fb0b4 = 0;
    system = DAT_011fe248;
    if (system->GetStageCount() < 4)
    {
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 0, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 1, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 2, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 3, 3, 0, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
    }
    system->SetVertexShader(DAT_011fdf30);
    system->SetPixelShader(DAT_011fdbf8);
    system->SetRenderState(27, 0, true);
    system->SetRenderState(15, 0, true);
    system->SetRenderState(7, 1, true);
    system->SetRenderState(23, 4, true);
    system->SetRenderState(14, 1, true);
    DAT_011fced0 = 240;
    DAT_011fc2f0 = 12;
    DAT_011fb710 = 224;
    DAT_011fab30 = 4;
    system = DAT_011fe7d4;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdfec);
    system->SetPixelShader(DAT_011fdc78);
    DAT_011fd45c = 768;
    DAT_011fc87c = 172;
    DAT_011fbc9c = 768;
    DAT_011fb0bc = 132;
    system = DAT_011fe7dc;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdfec);
    system->SetPixelShader(DAT_011fdc80);
    DAT_011fd464 = 768;
    DAT_011fc884 = 172;
    DAT_011fbca4 = 768;
    DAT_011fb0c4 = 132;
    system = DAT_011fe7d8;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdff0);
    system->SetPixelShader(DAT_011fdc7c);
    DAT_011fd460 = 880;
    DAT_011fc880 = 172;
    DAT_011fbca0 = 864;
    DAT_011fb0c0 = 132;
    system = DAT_011fe7e0;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdff0);
    system->SetPixelShader(DAT_011fdc84);
    DAT_011fd468 = 880;
    DAT_011fc888 = 172;
    DAT_011fbca8 = 864;
    DAT_011fb0c8 = 132;
    system = DAT_011fe7e4;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdfec);
    system->SetPixelShader(DAT_011fdc88);
    DAT_011fd46c = 768;
    DAT_011fc88c = 4012;
    DAT_011fbcac = 768;
    DAT_011fb0cc = 132;
    system = DAT_011fe7ec;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdfec);
    system->SetPixelShader(DAT_011fdc90);
    DAT_011fd474 = 768;
    DAT_011fc894 = 4012;
    DAT_011fbcb4 = 768;
    DAT_011fb0d4 = 132;
    system = DAT_011fe7e8;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdff0);
    system->SetPixelShader(DAT_011fdc8c);
    DAT_011fd470 = 880;
    DAT_011fc890 = 1964;
    DAT_011fbcb0 = 864;
    DAT_011fb0d0 = 132;
    system = DAT_011fe7f0;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdff0);
    system->SetPixelShader(DAT_011fdc94);
    DAT_011fd478 = 880;
    DAT_011fc898 = 1964;
    DAT_011fbcb8 = 864;
    DAT_011fb0d8 = 132;
    system = DAT_011fe7f4;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdfec);
    system->SetPixelShader(DAT_011fdc98);
    DAT_011fd47c = 768;
    DAT_011fc89c = 172;
    DAT_011fbcbc = 768;
    DAT_011fb0dc = 132;
    system = DAT_011fe7fc;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdfec);
    system->SetPixelShader(DAT_011fdca0);
    DAT_011fd484 = 768;
    DAT_011fc8a4 = 172;
    DAT_011fbcc4 = 768;
    DAT_011fb0e4 = 132;
    system = DAT_011fe7f8;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdff0);
    system->SetPixelShader(DAT_011fdc9c);
    DAT_011fd480 = 880;
    DAT_011fc8a0 = 172;
    DAT_011fbcc0 = 864;
    DAT_011fb0e0 = 132;
    system = DAT_011fe800;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdff0);
    system->SetPixelShader(DAT_011fdca4);
    DAT_011fd488 = 880;
    DAT_011fc8a8 = 172;
    DAT_011fbcc8 = 864;
    DAT_011fb0e8 = 132;
    system = DAT_011fe804;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdfec);
    system->SetPixelShader(DAT_011fdca8);
    DAT_011fd48c = 768;
    DAT_011fc8ac = 4012;
    DAT_011fbccc = 768;
    DAT_011fb0ec = 132;
    system = DAT_011fe80c;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdfec);
    system->SetPixelShader(DAT_011fdcb0);
    DAT_011fd494 = 768;
    DAT_011fc8b4 = 4012;
    DAT_011fbcd4 = 768;
    DAT_011fb0f4 = 132;
    system = DAT_011fe808;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdff0);
    system->SetPixelShader(DAT_011fdcac);
    DAT_011fd490 = 880;
    DAT_011fc8b0 = 1964;
    DAT_011fbcd0 = 864;
    DAT_011fb0f0 = 132;
    system = DAT_011fe810;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdff0);
    system->SetPixelShader(DAT_011fdcb4);
    DAT_011fd498 = 880;
    DAT_011fc8b8 = 1964;
    DAT_011fbcd8 = 864;
    DAT_011fb0f8 = 132;
    system = DAT_011fe814;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdfec);
    system->SetPixelShader(DAT_011fdcb8);
    DAT_011fd49c = 768;
    DAT_011fc8bc = 172;
    DAT_011fbcdc = 768;
    DAT_011fb0fc = 132;
    system = DAT_011fe81c;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdfec);
    system->SetPixelShader(DAT_011fdcc0);
    DAT_011fd4a4 = 768;
    DAT_011fc8c4 = 172;
    DAT_011fbce4 = 768;
    DAT_011fb104 = 132;
    system = DAT_011fe818;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdff0);
    system->SetPixelShader(DAT_011fdcbc);
    DAT_011fd4a0 = 880;
    DAT_011fc8c0 = 172;
    DAT_011fbce0 = 864;
    DAT_011fb100 = 132;
    system = DAT_011fe820;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdff0);
    system->SetPixelShader(DAT_011fdcc4);
    DAT_011fd4a8 = 880;
    DAT_011fc8c8 = 172;
    DAT_011fbce8 = 864;
    DAT_011fb108 = 132;
    system = DAT_011fe824;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdfec);
    system->SetPixelShader(DAT_011fdcc8);
    DAT_011fd4ac = 768;
    DAT_011fc8cc = 4012;
    DAT_011fbcec = 768;
    DAT_011fb10c = 132;
    system = DAT_011fe82c;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdfec);
    system->SetPixelShader(DAT_011fdcd0);
    DAT_011fd4b4 = 768;
    DAT_011fc8d4 = 4012;
    DAT_011fbcf4 = 768;
    DAT_011fb114 = 132;
    system = DAT_011fe828;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdff0);
    system->SetPixelShader(DAT_011fdccc);
    DAT_011fd4b0 = 880;
    DAT_011fc8d0 = 1964;
    DAT_011fbcf0 = 864;
    DAT_011fb110 = 132;
    system = DAT_011fe830;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdff0);
    system->SetPixelShader(DAT_011fdcd4);
    DAT_011fd4b8 = 880;
    DAT_011fc8d8 = 1964;
    DAT_011fbcf8 = 864;
    DAT_011fb118 = 132;
    system = DAT_011fe834;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdfec);
    system->SetPixelShader(DAT_011fdcd8);
    DAT_011fd4bc = 768;
    DAT_011fc8dc = 172;
    DAT_011fbcfc = 768;
    DAT_011fb11c = 132;
    system = DAT_011fe83c;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdfec);
    system->SetPixelShader(DAT_011fdce0);
    DAT_011fd4c4 = 768;
    DAT_011fc8e4 = 172;
    DAT_011fbd04 = 768;
    DAT_011fb124 = 132;
    system = DAT_011fe838;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->SetVertexShader(DAT_011fdff0);
    // These shader setters remain calls, as in the original pass initialization.
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdcdc));
    DAT_011fd4c0 = 880;
    DAT_011fc8e0 = 172;
    DAT_011fbd00 = 864;
    DAT_011fb120 = 132;
    system = DAT_011fe840;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdce4));
    DAT_011fd4c8 = 880;
    DAT_011fc8e8 = 172;
    DAT_011fbd08 = 864;
    DAT_011fb128 = 132;
    system = DAT_011fe844;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdce8));
    DAT_011fd4cc = 768;
    DAT_011fc8ec = 4012;
    DAT_011fbd0c = 768;
    DAT_011fb12c = 132;
    system = DAT_011fe84c;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdcf0));
    DAT_011fd4d4 = 768;
    DAT_011fc8f4 = 4012;
    DAT_011fbd14 = 768;
    DAT_011fb134 = 132;
    system = DAT_011fe848;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdcec));
    DAT_011fd4d0 = 880;
    DAT_011fc8f0 = 1964;
    DAT_011fbd10 = 864;
    DAT_011fb130 = 132;
    system = DAT_011fe850;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdcf4));
    DAT_011fd4d8 = 880;
    DAT_011fc8f8 = 1964;
    DAT_011fbd18 = 864;
    DAT_011fb138 = 132;
    system = DAT_011fe854;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdcf8));
    DAT_011fd4dc = 768;
    DAT_011fc8fc = 172;
    DAT_011fbd1c = 768;
    DAT_011fb13c = 132;
    system = DAT_011fe85c;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd00));
    DAT_011fd4e4 = 768;
    DAT_011fc904 = 172;
    DAT_011fbd24 = 768;
    DAT_011fb144 = 132;
    system = DAT_011fe858;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdcfc));
    DAT_011fd4e0 = 880;
    DAT_011fc900 = 172;
    DAT_011fbd20 = 864;
    DAT_011fb140 = 132;
    system = DAT_011fe860;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd04));
    DAT_011fd4e8 = 880;
    DAT_011fc908 = 172;
    DAT_011fbd28 = 864;
    DAT_011fb148 = 132;
    system = DAT_011fe864;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd08));
    DAT_011fd4ec = 768;
    DAT_011fc90c = 4012;
    DAT_011fbd2c = 768;
    DAT_011fb14c = 132;
    system = DAT_011fe86c;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd10));
    DAT_011fd4f4 = 768;
    DAT_011fc914 = 4012;
    DAT_011fbd34 = 768;
    DAT_011fb154 = 132;
    system = DAT_011fe868;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd0c));
    DAT_011fd4f0 = 880;
    DAT_011fc910 = 1964;
    DAT_011fbd30 = 864;
    DAT_011fb150 = 132;
    system = DAT_011fe870;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd14));
    DAT_011fd4f8 = 880;
    DAT_011fc918 = 1964;
    DAT_011fbd38 = 864;
    DAT_011fb158 = 132;
    system = DAT_011fe874;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd18));
    DAT_011fd4fc = 768;
    DAT_011fc91c = 172;
    DAT_011fbd3c = 768;
    DAT_011fb15c = 132;
    system = DAT_011fe87c;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd20));
    DAT_011fd504 = 768;
    DAT_011fc924 = 172;
    DAT_011fbd44 = 768;
    DAT_011fb164 = 132;
    system = DAT_011fe878;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd1c));
    DAT_011fd500 = 880;
    DAT_011fc920 = 172;
    DAT_011fbd40 = 864;
    DAT_011fb160 = 132;
    system = DAT_011fe880;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd24));
    DAT_011fd508 = 880;
    DAT_011fc928 = 172;
    DAT_011fbd48 = 864;
    DAT_011fb168 = 132;
    system = DAT_011fe884;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd28));
    DAT_011fd50c = 768;
    DAT_011fc92c = 4012;
    DAT_011fbd4c = 768;
    DAT_011fb16c = 132;
    system = DAT_011fe88c;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd30));
    DAT_011fd514 = 768;
    DAT_011fc934 = 4012;
    DAT_011fbd54 = 768;
    DAT_011fb174 = 132;
    system = DAT_011fe888;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd2c));
    DAT_011fd510 = 880;
    DAT_011fc930 = 1964;
    DAT_011fbd50 = 864;
    DAT_011fb170 = 132;
    system = DAT_011fe888;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd34));
    DAT_011fd518 = 880;
    DAT_011fc938 = 1964;
    DAT_011fbd58 = 864;
    DAT_011fb178 = 132;
    system = DAT_011fe894;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd38));
    DAT_011fd51c = 768;
    DAT_011fc93c = 172;
    DAT_011fbd5c = 768;
    DAT_011fb17c = 132;
    system = DAT_011fe89c;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd40));
    DAT_011fd524 = 768;
    DAT_011fc944 = 172;
    DAT_011fbd64 = 768;
    DAT_011fb184 = 132;
    system = DAT_011fe898;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd3c));
    DAT_011fd520 = 880;
    DAT_011fc940 = 172;
    DAT_011fbd60 = 864;
    DAT_011fb180 = 132;
    system = DAT_011fe8a0;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd44));
    DAT_011fd528 = 880;
    DAT_011fc948 = 172;
    DAT_011fbd68 = 864;
    DAT_011fb188 = 132;
    system = DAT_011fe8a4;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd48));
    DAT_011fd52c = 768;
    DAT_011fc94c = 4012;
    DAT_011fbd6c = 768;
    DAT_011fb18c = 132;
    system = DAT_011fe8ac;
    if (system->GetStageCount() < 14)
    {
        for (int stage = 0; stage < 14; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd50));
    DAT_011fd534 = 768;
    DAT_011fc954 = 4012;
    DAT_011fbd74 = 768;
    DAT_011fb194 = 132;
    system = DAT_011fe8a8;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd4c));
    DAT_011fd530 = 880;
    DAT_011fc950 = 1964;
    DAT_011fbd70 = 864;
    DAT_011fb190 = 132;
    system = DAT_011fe8b0;
    if (system->GetStageCount() < 16)
    {
        for (int stage = 0; stage < 16; ++stage)
        {
            AssignStageFromPool(temporary);
            ConfigureBeamStage(temporary, stage, 1, 2, 1);
            system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        }
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdff0));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd54));
    DAT_011fd538 = 880;
    DAT_011fc958 = 1964;
    DAT_011fbd78 = 864;
    DAT_011fb198 = 132;
    system = DAT_011fe8b4;
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdfec));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdd58));
    system->SetRenderState(27, 0, true);
    system->SetRenderState(15, 0, true);
    system->SetRenderState(7, 1, true);
    system->SetRenderState(23, 4, true);
    system->SetRenderState(14, 1, true);
    DAT_011fd53c = 768;
    DAT_011fc95c = 4;
    DAT_011fbd7c = 768;
    DAT_011fb19c = 4;
    system = DAT_011fe7c4;
    if (system->GetStageCount() < 4)
    {
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 0, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 1, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 2, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 3, 3, 0, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdf34));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdbfc));
    system->SetRenderState(27, 1, true);
    system->SetRenderState(19, 5, true);
    system->SetRenderState(20, 6, true);
    system->SetRenderState(15, 1, true);
    system->SetRenderState(25, 5, true);
    system->SetRenderState(24, 0, true);
    system->SetRenderState(7, 1, true);
    system->SetRenderState(23, 4, true);
    system->SetRenderState(14, 0, true);
    DAT_011fd44c = 240;
    DAT_011fc86c = 12;
    DAT_011fbc8c = 224;
    DAT_011fb0ac = 4;
    system = DAT_011fe7b8;
    if (system->GetStageCount() < 3)
    {
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 0, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 1, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 2, 3, 0, 1);
        temporary->unk08 = DAT_011f9534;
        temporary->unk0c = 1;
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdf38));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdc00));
    system->SetRenderState(19, 5, true);
    system->SetRenderState(20, 2, true);
    system->SetRenderState(15, 0, true);
    system->SetRenderState(7, 1, true);
    system->SetRenderState(23, 4, true);
    system->SetRenderState(14, 0, true);
    DAT_011fd440 = 128;
    DAT_011fc860 = 12;
    DAT_011fb0a0 = 4;
    system = DAT_011fe7d0;
    if (system->GetStageCount() < 3)
    {
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 0, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 1, 1, 2, 1);
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
        AssignStageFromPool(temporary);
        ConfigureBeamStage(temporary, 2, 3, 0, 1);
        temporary->unk08 = DAT_011f9534;
        temporary->unk0c = 1;
        system->AppendStage(reinterpret_cast<::BeamStage*>(temporary.m_pObject));
    }
    system->NiD3DPass_SetVertexShader(reinterpret_cast<NiD3DPixelShader*>(DAT_011fdf44));
    system->NiD3DPass_SetPixelShader(reinterpret_cast<NiD3DVertexShader*>(DAT_011fdc0c));
    system->SetRenderState(27, 1, true);
    system->SetRenderState(19, 5, true);
    system->SetRenderState(20, 2, true);
    system->SetRenderState(15, 1, true);
    system->SetRenderState(25, 5, true);
    system->SetRenderState(24, 0, true);
    system->SetRenderState(7, 1, true);
    system->SetRenderState(23, 4, true);
    system->SetRenderState(14, 0, true);
    DAT_011fd458 = 128;
    DAT_011fc878 = 28;
    DAT_011fb0b8 = 0;
}
}  // namespace fnv_00bfc860

class ObjectArray : public NiTObjectArray<NiPointer<NiRefObject> >
{
  public:
    void NiTObjectArray_NiPointer_NiShaderConstantMapEntry_RemoveAll();
};

// Clears each active pointer entry, then sets the array's size and ESize fields to zero.
// @fnv 0x00b799c0
// src: COMMUNITY 0x00b799c0
void ObjectArray::NiTObjectArray_NiPointer_NiShaderConstantMapEntry_RemoveAll()
{
    for (unsigned short i = 0; i < m_usSize; i++)
    {
        m_pBase[i] = NiPointer<NiRefObject>();
    }
    m_usSize = 0;
    m_usESize = 0;
}

namespace fnv_00b79de0 {
struct FUN_00be0f10
{
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    NiPointer<NiRefObject> resource28;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    int unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    virtual ~FUN_00be0f10();
};
struct RendObj;
struct RendVtbl
{
    void* f0;
    void(__thiscall* release)(RendObj*);
};
struct RendObj
{
    RendVtbl* vtbl;
    long unk04;
    int unk08, unk0c, unk10;
    void* f14;
    int f18, unk1c, unk20, unk24, unk28, unk2c;
    void* f30;
    int unk34, unk38, unk3c, unk40;
    RendObj* f44;
    int unk48, unk4c, unk50, unk54, unk58;
    RendObj* f5c;
    int unk60;
    int refs;
    void FUN_00e80190();
    void IncRefCount()
    {
        ++refs;
    }
    void DecRefCount()
    {
        if (--refs == 0)
            FUN_00e80190();
    }
};
extern void* DAT_010af2f8;
extern NiPointer<NiRefObject> DAT_011fdd88[156];
extern NiPointer<NiRefObject> DAT_011fda48[208];
extern NiPointer<RendObj> DAT_011fdff8[759];
struct FUN_00b79de0 : FUN_00be0f10
{
    int mode;
    NiPointer<NiRefObject> resource6c, resource70, resource74, resource78;
    NiPointer<NiRefObject> resource7c, resource80, resource84, resource88;
    ~FUN_00b79de0();
};
// Destructor that zeroes global NiPointer arrays and member resource pointers.
// @fnv 0x00b79de0
FUN_00b79de0::~FUN_00b79de0()
{
    for (int i = 0; i < 156; ++i)
        DAT_011fdd88[i] = 0;
    for (int i = 0; i < 208; ++i)
        DAT_011fda48[i] = 0;
    for (int i = 0; i < 759; ++i)
        DAT_011fdff8[i] = 0;
    for (int i = 0; i < 22; ++i)
        reinterpret_cast<NiPointer<NiRefObject>*>(&DAT_011febd8)[i] = 0;
    for (int i = 0; i < 22; ++i)
        reinterpret_cast<NiPointer<NiRefObject>*>(&DAT_011fec30)[i] = 0;
    resource28 = 0;
    resource6c = 0;
    resource70 = 0;
    resource74 = 0;
    resource78 = 0;
    resource80 = 0;
    resource7c = 0;
    resource88 = 0;
    resource84 = 0;
}
}  // namespace fnv_00b79de0

namespace ShaderBias {
struct RefObject
{
    virtual void slot0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct ShaderRefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->m_iObjectReferenceCount);
        }
    }
};
struct RenderStateBlock
{
    void SetNodeValue(unsigned int, unsigned int, bool);
};
RenderStateBlock* FUN_00e7f5d0();
struct ShaderStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
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
    int references;
    void NiD3DTextureStage_ReturnStageToPool();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
struct ShaderStagePointer
{
    ShaderStage* object;
    ShaderStagePointer() : object(0)
    {}
    ~ShaderStagePointer()
    {
        if (object)
            object->Release();
    }
};
void AssignStageFromPool(ShaderStagePointer*);
void ConfigureBeamStage(ShaderStage*, unsigned int, unsigned int, unsigned int, bool);
extern unsigned int DAT_011f9534;
struct ShaderPass
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStateBlock* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    ShaderRefPointer pixelShader;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ShaderRefPointer vertexShader;
    unsigned int unk60;
    int references;
    __forceinline unsigned int Count()
    {
        return stageCount;
    }
    void FUN_00e80190();
    void NiD3DPass_SetStage(unsigned int, ShaderStage*);
    __forceinline RenderStateBlock* const& GetState()
    {
        if (!state)
            state = FUN_00e7f5d0();
        return state;
    }
};
struct ShaderPassPointer
{
    ShaderPass* object;
    ShaderPassPointer() : object(0)
    {}
    ~ShaderPassPointer()
    {
        if (object && --object->references == 0)
            object->FUN_00e80190();
    }
    __forceinline void operator=(ShaderPass* const& value)
    {
        if (object != value)
        {
            if (object && --object->references == 0)
                object->FUN_00e80190();
            object = value;
            if (object)
                ++object->references;
        }
    }
    __forceinline ShaderPass* operator->()
    {
        return object;
    }
};
extern float DAT_01200458;
extern RefObject* DAT_011fdc40;
extern ShaderPass* DAT_011fe794;
extern RefObject* DAT_011fdf80;
extern unsigned int DAT_011fd41c, DAT_011fc83c;
extern ShaderPass* DAT_011fe798;
extern RefObject* DAT_011fdf84;
extern unsigned int DAT_011fd420, DAT_011fc840;
extern ShaderPass* DAT_011fe79c;
extern RefObject* DAT_011fdf88;
extern unsigned int DAT_011fd424, DAT_011fc844;
// Returns the 32-bit value read from the address of the float parameter as an unsigned integer.
// @fnv 0x00c017c0
inline unsigned int FloatBits(float value)
{
    return *(unsigned int*)&value;
}
// src: COMMUNITY 0x00c017c0
void ShadowLightShader_PresetDepthPasses_2x()
{
    ShaderPassPointer pass;
    ShaderStagePointer stage;
    pass = DAT_011fe794;
    pass->vertexShader = DAT_011fdf80;
    pass->pixelShader = DAT_011fdc40;
    pass->GetState()->SetNodeValue(27, 0, 1);
    pass->GetState()->SetNodeValue(15, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(23, 4, 1);
    pass->GetState()->SetNodeValue(14, 1, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd41c = 540672;
    DAT_011fc83c = 0;
    pass = DAT_011fe798;
    pass->vertexShader = DAT_011fdf84;
    pass->pixelShader = DAT_011fdc40;
    pass->GetState()->SetNodeValue(27, 0, 1);
    pass->GetState()->SetNodeValue(15, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(23, 4, 1);
    pass->GetState()->SetNodeValue(14, 1, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd420 = 559104;
    DAT_011fc840 = 0;
    pass = DAT_011fe79c;
    pass->vertexShader = DAT_011fdf88;
    pass->pixelShader = DAT_011fdc40;
    pass->GetState()->SetNodeValue(27, 0, 1);
    pass->GetState()->SetNodeValue(15, 0, 1);
    pass->GetState()->SetNodeValue(7, 1, 1);
    pass->GetState()->SetNodeValue(23, 4, 1);
    pass->GetState()->SetNodeValue(14, 1, 1);
    pass->GetState()->SetNodeValue(195, FloatBits(DAT_01200458), 1);
    DAT_011fd424 = 540672;
    DAT_011fc844 = 0;
}
}

struct CompileShaderObject
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long refs;
    void AddRef()
    {
        InterlockedIncrement(&refs);
    }
    void Release()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};

struct CompileShaderPointer
{
    CompileShaderObject* object;
    CompileShaderPointer& operator=(CompileShaderObject* value)
    {
        if (object != value)
        {
            if (object)
                object->Release();
            object = value;
            if (object)
                object->AddRef();
        }
        return *this;
    }
};

extern CompileShaderPointer shaderModel1Programs[48], shaderModel2Programs[160];

extern float shaderToneA, shaderToneB;

extern int shaderModel, shaderMode, shaderPassCount;

void ResolveShaderPath(const char*, char*);

struct ShaderCompiler
{
    CompileShaderObject* Compile(const char*, const char* const*, const char*, const char*);
    void ShadowLightShader_LoadPixelShaders();
};

extern const char shader_lighting_2x_p_ADTS_p_hlsl[];  // "lighting\\2x\\p\\ADTS.p.hlsl"

extern const char shader_OPT[];  // "OPT"

extern const char shader_empty[];  // ""

extern const char shader_LOD[];  // "LOD"

extern const char shader_lighting_2x_p_landlod_p_hlsl[];  // "lighting\\2x\\p\\landlod.p.hlsl"

extern const char shader_MODELSPACENORM[];  // "MODELSPACENORM"

extern const char shader_LODLANDCLIP[];  // "LODLANDCLIP"

extern const char shader_LODLANDNOISE[];  // "LODLANDNOISE"

extern const char shader_SI[];  // "SI"

extern const char shader_PROJ_SHADOW[];  // "PROJ_SHADOW"

extern const char shader_STBB[];  // "STBB"

extern const char shader_HAIR[];  // "HAIR"

extern const char shader_LIGHTS[];  // "LIGHTS"

extern const char shader_2[];  // "2"

extern const char shader_SPECULAR[];  // "SPECULAR"

extern const char shader_lighting_2x_p_ADTS10_p_hlsl[];  // "lighting\\2x\\p\\ADTS10.p.hlsl"

extern const char shader_9[];  // "9"

extern const char shader_4[];  // "4"

extern const char shader_lighting_2x_p_AD_p_hlsl[];  // "lighting\\2x\\p\\AD.p.hlsl"

extern const char shader_3[];  // "3"

extern const char shader_lighting_2x_p_DiffusePt_p_hlsl[];  // "lighting\\2x\\p\\DiffusePt.p.hlsl"

extern const char shader_lighting_2x_p_Specular_p_hlsl[];  // "lighting\\2x\\p\\Specular.p.hlsl"

extern const char shader_POINT[];  // "POINT"

extern const char shader_NUM_PT_LIGHTS[];  // "NUM_PT_LIGHTS"

extern const char shader_lighting_2x_p_EnvMap_p_hlsl[];  // "lighting\\2x\\p\\EnvMap.p.hlsl"

extern const char shader_WINDOW[];  // "WINDOW"

extern const char shader_EYE[];  // "EYE"

extern const char shader_lighting_2x_p_land_p_hlsl[];  // "lighting\\2x\\p\\land.p.hlsl"

extern const char shader_LANDALPHA[];  // "LANDALPHA"

extern const char shader_lighting_2x_p_landlighting_p_hlsl[];  // "lighting\\2x\\p\\landlighting.p.hlsl"

extern const char shader_DIFF[];  // "DIFF"

extern const char shader_PTLIGHT[];  // "PTLIGHT"

extern const char shader_lighting_2x_p_depthmap_p_hlsl[];  // "lighting\\2x\\p\\depthmap.p.hlsl"

extern const char shader_DEPTHMAP[];  // "DEPTHMAP"

extern const char shader_SHADOWMODE[];  // "SHADOWMODE"

extern const char shader_ALPHATEST[];  // "ALPHATEST"

extern const char shader_SKIN[];  // "SKIN"

extern const char shader_WATERDEPTH[];  // "WATERDEPTH"

extern const char shader_lighting_2x_p_renderNormals_p_hlsl[];  // "lighting\\2x\\p\\renderNormals.p.hlsl"

extern const char shader_FIRE[];  // "FIRE"

extern const char shader_CLEAR[];  // "CLEAR"

extern const char shader_lighting_2x_p_renderDepth_p_hlsl[];  // "lighting\\2x\\p\\renderDepth.p.hlsl"

extern const char shader_lighting_2x_p_renderVelocity_p_hlsl[];  // "lighting\\2x\\p\\renderVelocity.p.hlsl"

extern const char shader_LANDLO[];  // "LANDLO"

extern const char shader_FOG[];  // "FOG"

extern const char shader_lighting_2x_p_localMap_p_hlsl[];  // "lighting\\2x\\p\\localMap.p.hlsl"

extern const char shader_lighting_1x_p_texEffect_p_hlsl[];  // "lighting\\1x\\p\\texEffect.p.hlsl"

extern const char shader_HQ[];  // "HQ"

extern const char shader_lighting_2x_p_WaterFog_p_hlsl[];  // "lighting\\2x\\p\\WaterFog.p.hlsl"

extern const char shader_ALPHATESTING[];  // "ALPHATESTING"

extern const char shader_lighting_2x_p_LandO_p_hlsl[];  // "lighting\\2x\\p\\LandO.p.hlsl"

extern const char shader_TEXCOUNT[];  // "TEXCOUNT"

extern const char shader_1[];  // "1"

extern const char shader_HIGHQUAL[];  // "HIGHQUAL"

extern const char shader_IGNORE_NORMALS[];  // "IGNORE_NORMALS"

extern const char shader_PTLIGHTS[];  // "PTLIGHTS"

extern const char shader_5[];  // "5"

extern const char shader_6[];  // "6"

extern const char shader_7[];  // "7"

extern const char shader_lighting_2x_p_Lando_p_hlsl[];  // "lighting\\2x\\p\\Lando.p.hlsl"

extern const char shader_SILHOUETTE[];  // "SILHOUETTE"

extern const char shader_lighting_1x_p_base_p_hlsl[];  // "lighting\\1x\\p\\base.p.hlsl"

extern const char shader_FOGANDAMBIENT[];  // "FOGANDAMBIENT"

extern const char shader_lighting_2x_p_adts_p_hlsl[];  // "lighting\\2x\\p\\adts.p.hlsl"

extern const char shader_0[];  // "0"

extern const char shader_lighting_2x_p_SimpleShadow_p_hlsl[];  // "lighting\\2x\\p\\SimpleShadow.p.hlsl"

extern const char shader_SHADOWMAP[];  // "SHADOWMAP"

extern const char shader_DEPTHBIAS[];  // "DEPTHBIAS"

extern const char shader_0_1[];  // "-0.1"

extern const char shader_SAMPLE[];  // "SAMPLE"

extern const char shader_PASSES[];  // "PASSES"

extern const char shader_SRT_EYE[];  // "SRT_EYE"

extern const char shader_SRT_HEIGHT[];  // "SRT_HEIGHT"

extern const char shader_lighting_1x_p_diffusePt_p_hlsl[];  // "lighting\\1x\\p\\diffusePt.p.hlsl"

extern const char shader_lighting_1x_p_diffuseDir_p_hlsl[];  // "lighting\\1x\\p\\diffuseDir.p.hlsl"

extern const char shader_TEX[];  // "TEX"

extern const char shader_VC[];  // "VC"

extern const char shader_FACEGENBLEND[];  // "FACEGENBLEND"

extern const char shader_lighting_1x_p_specularPt_p_hlsl[];  // "lighting\\1x\\p\\specularPt.p.hlsl"

extern const char shader_SPECMULT[];  // "SPECMULT"

extern const char shader_lighting_1x_p_specularDir_p_hlsl[];  // "lighting\\1x\\p\\specularDir.p.hlsl"

extern const char shader_lighting_1x_p_ambDiffDirTexture_p_hlsl[];  // "lighting\\1x\\p\\ambDiffDirTexture.p.hlsl"

extern const char shader_ALPHA[];  // "ALPHA"

extern const char shader_lighting_1x_p_ambDiffDirAndPt_p_hlsl[];  // "lighting\\1x\\p\\ambDiffDirAndPt.p.hlsl"

extern const char shader_lighting_1x_p_envmap_p_hlsl[];  // "lighting\\1x\\p\\envmap.p.hlsl"

extern const char shader_lighting_1x_p_vertDir_p_hlsl[];  // "lighting\\1x\\p\\vertDir.p.hlsl"

extern const char shader_lighting_1x_p_vertDirAndPt_p_hlsl[];  // "lighting\\1x\\p\\vertDirAndPt.p.hlsl"

extern const char shader_lighting_1x_p_SI_p_hlsl[];  // "lighting\\1x\\p\\SI.p.hlsl"

extern const char shader_AMBIENT[];  // "AMBIENT"

extern const char shader_EMMITMULT[];  // "EMMITMULT"

extern const char shader_SIBLOCK[];  // "SIBLOCK"

extern const char shader_lighting_1x_p_land_p_hlsl[];  // "lighting\\1x\\p\\land.p.hlsl"

extern const char shader_CONSTALPHA[];  // "CONSTALPHA"

// Builds shader definition tables, resolves source paths, and calls Compile with index-based .pso filenames for selected entries.
// @fnv 0x00b74210
// src: COMMUNITY 0x00b74210
void ShaderCompiler::ShadowLightShader_LoadPixelShaders()

{

    char toneA[349];
    char toneB[349];

    _gcvt(shaderToneA, 12, toneA);

    _gcvt(shaderToneB, 12, toneB);

    const char* shaderModel1Defs[48][19] = {

        {shader_lighting_1x_p_base_p_hlsl, 0},

        {shader_lighting_1x_p_diffusePt_p_hlsl, 0},

        {shader_lighting_1x_p_diffuseDir_p_hlsl, 0},

        {shader_lighting_1x_p_base_p_hlsl, shader_TEX, shader_empty, 0},

        {shader_lighting_1x_p_base_p_hlsl, shader_TEX, shader_empty, shader_VC, shader_empty, 0},

        {shader_lighting_1x_p_base_p_hlsl, shader_TEX, shader_empty, shader_FACEGENBLEND, shader_empty, 0},

        {shader_lighting_1x_p_base_p_hlsl, shader_TEX, shader_empty, shader_HAIR, shader_empty, 0},

        {shader_lighting_1x_p_specularPt_p_hlsl, shader_SPECMULT, toneA, 0},

        {shader_lighting_1x_p_specularDir_p_hlsl, shader_SPECMULT, toneA, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_FOG, shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_ALPHA, shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_ALPHA, shader_empty, shader_FOG, shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_VC, shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_VC, shader_empty, shader_FOG, shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_VC, shader_empty, shader_ALPHA, shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_VC, shader_empty, shader_ALPHA, shader_empty, shader_FOG,
         shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_FACEGENBLEND, shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_FACEGENBLEND, shader_empty, shader_FOG, shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_FACEGENBLEND, shader_empty, shader_ALPHA, shader_empty,
         0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_FACEGENBLEND, shader_empty, shader_FOG, shader_empty,
         shader_ALPHA, shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_SI, shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_SI, shader_empty, shader_FOG, shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_SI, shader_empty, shader_ALPHA, shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_SI, shader_empty, shader_ALPHA, shader_empty, shader_FOG,
         shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_SI, shader_empty, shader_VC, shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_SI, shader_empty, shader_VC, shader_empty, shader_FOG,
         shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_SI, shader_empty, shader_VC, shader_empty, shader_ALPHA,
         shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirTexture_p_hlsl, shader_SI, shader_empty, shader_VC, shader_empty, shader_ALPHA,
         shader_empty, shader_FOG, shader_empty, 0},

        {shader_lighting_1x_p_ambDiffDirAndPt_p_hlsl, 0},

        {shader_lighting_1x_p_base_p_hlsl, shader_FOG, shader_empty, 0},

        {shader_lighting_1x_p_base_p_hlsl, shader_FOG, shader_empty, shader_TEX, shader_empty, 0},

        {shader_lighting_1x_p_envmap_p_hlsl, 0},

        {shader_lighting_1x_p_envmap_p_hlsl, shader_VC, shader_empty, 0},

        {shader_lighting_1x_p_vertDir_p_hlsl, 0},

        {shader_lighting_1x_p_vertDirAndPt_p_hlsl, 0},

        {shader_lighting_1x_p_SI_p_hlsl, shader_AMBIENT, shader_empty, shader_EMMITMULT, toneB, 0},

        {shader_lighting_1x_p_SI_p_hlsl, shader_EMMITMULT, toneB, 0},

        {shader_lighting_1x_p_SI_p_hlsl, shader_SIBLOCK, 0, 0},

        {shader_lighting_1x_p_base_p_hlsl, 0},

        {shader_lighting_1x_p_land_p_hlsl, 0},

        {shader_lighting_1x_p_land_p_hlsl, shader_LANDALPHA, shader_empty, 0},

        {shader_lighting_1x_p_land_p_hlsl, shader_SI, shader_empty, 0},

        {shader_lighting_1x_p_land_p_hlsl, shader_LANDALPHA, shader_empty, shader_SI, shader_empty, 0},

        {shader_lighting_1x_p_land_p_hlsl, shader_PTLIGHT, shader_empty, 0},

        {shader_lighting_1x_p_land_p_hlsl, shader_LANDALPHA, shader_empty, shader_PTLIGHT, shader_empty, 0},

        {0},

        {shader_lighting_1x_p_base_p_hlsl, shader_CONSTALPHA, shader_empty, 0},

    };

    const char* shaderModel2Defs[160][19] = {

        {shader_lighting_2x_p_ADTS_p_hlsl, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_OPT, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_OPT, shader_empty, shader_LOD, shader_empty, 0},

        {shader_lighting_2x_p_landlod_p_hlsl, shader_MODELSPACENORM, shader_empty, shader_LODLANDCLIP, shader_empty,
         shader_LODLANDNOISE, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_SI, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_landlod_p_hlsl, shader_MODELSPACENORM, shader_empty, shader_PROJ_SHADOW, shader_empty,
         shader_LODLANDCLIP, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_SI, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_STBB, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_HAIR, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_HAIR, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_LIGHTS, shader_2, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_LIGHTS, shader_2, shader_SI, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_LIGHTS, shader_2, shader_HAIR, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_LIGHTS, shader_2, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_LIGHTS, shader_2, shader_SI, shader_empty, shader_PROJ_SHADOW,
         shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_LIGHTS, shader_2, shader_HAIR, shader_empty, shader_PROJ_SHADOW,
         shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_SPECULAR, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_SPECULAR, shader_empty, shader_SI, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_SPECULAR, shader_empty, shader_HAIR, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_SPECULAR, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_SPECULAR, shader_empty, shader_SI, shader_empty, shader_PROJ_SHADOW,
         shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_SPECULAR, shader_empty, shader_HAIR, shader_empty, shader_PROJ_SHADOW,
         shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_SPECULAR, shader_empty, shader_LIGHTS, shader_2, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_SPECULAR, shader_empty, shader_LIGHTS, shader_2, shader_SI,
         shader_empty, 0},

        {0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_SPECULAR, shader_empty, shader_LIGHTS, shader_2, shader_PROJ_SHADOW,
         shader_empty, 0},

        {shader_lighting_2x_p_ADTS_p_hlsl, shader_SPECULAR, shader_empty, shader_LIGHTS, shader_2, shader_SI,
         shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {0},

        {shader_lighting_2x_p_ADTS10_p_hlsl, shader_LIGHTS, shader_9, 0},

        {shader_lighting_2x_p_ADTS10_p_hlsl, shader_LIGHTS, shader_9, shader_SI, 0, 0},

        {shader_lighting_2x_p_ADTS10_p_hlsl, shader_LIGHTS, shader_4, 0},

        {shader_lighting_2x_p_ADTS10_p_hlsl, shader_OPT, shader_empty, shader_LIGHTS, shader_4, 0},

        {shader_lighting_2x_p_ADTS10_p_hlsl, shader_LIGHTS, shader_4, shader_SI, 0, 0},

        {shader_lighting_2x_p_ADTS10_p_hlsl, shader_SPECULAR, shader_empty, shader_LIGHTS, shader_4, 0},

        {shader_lighting_2x_p_ADTS10_p_hlsl, shader_OPT, shader_empty, shader_SPECULAR, shader_empty, shader_LIGHTS,
         shader_4, 0},

        {shader_lighting_2x_p_ADTS10_p_hlsl, shader_SPECULAR, shader_empty, shader_LIGHTS, shader_4, shader_SI, 0, 0},

        {shader_lighting_2x_p_AD_p_hlsl, shader_LIGHTS, shader_2, 0},

        {shader_lighting_2x_p_AD_p_hlsl, shader_LIGHTS, shader_2, shader_SI, shader_empty, 0},

        {shader_lighting_2x_p_AD_p_hlsl, shader_LIGHTS, shader_2, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_AD_p_hlsl, shader_LIGHTS, shader_2, shader_SI, shader_empty, shader_PROJ_SHADOW,
         shader_empty, 0},

        {shader_lighting_2x_p_AD_p_hlsl, shader_LIGHTS, shader_3, 0},

        {shader_lighting_2x_p_AD_p_hlsl, shader_LIGHTS, shader_3, shader_SI, shader_empty, 0},

        {shader_lighting_2x_p_AD_p_hlsl, shader_LIGHTS, shader_3, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_AD_p_hlsl, shader_LIGHTS, shader_3, shader_SI, shader_empty, shader_PROJ_SHADOW,
         shader_empty, 0},

        {shader_lighting_2x_p_DiffusePt_p_hlsl, shader_LIGHTS, shader_2, 0},

        {shader_lighting_2x_p_DiffusePt_p_hlsl, shader_LIGHTS, shader_3, 0},

        {shader_lighting_2x_p_Specular_p_hlsl, 0},

        {shader_lighting_2x_p_Specular_p_hlsl, shader_HAIR, shader_empty, 0},

        {shader_lighting_2x_p_Specular_p_hlsl, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_Specular_p_hlsl, shader_PROJ_SHADOW, shader_empty, shader_HAIR, shader_empty, 0},

        {shader_lighting_2x_p_Specular_p_hlsl, shader_POINT, shader_empty, 0},

        {shader_lighting_2x_p_Specular_p_hlsl, shader_POINT, shader_empty, shader_HAIR, shader_empty, 0},

        {shader_lighting_2x_p_Specular_p_hlsl, shader_NUM_PT_LIGHTS, shader_2, shader_POINT, shader_empty, 0},

        {shader_lighting_2x_p_Specular_p_hlsl, shader_NUM_PT_LIGHTS, shader_2, shader_POINT, shader_empty, shader_HAIR,
         shader_empty, 0},

        {shader_lighting_2x_p_Specular_p_hlsl, shader_NUM_PT_LIGHTS, shader_3, shader_POINT, shader_empty, 0},

        {shader_lighting_2x_p_Specular_p_hlsl, shader_NUM_PT_LIGHTS, shader_3, shader_POINT, shader_empty, shader_HAIR,
         shader_empty, 0},

        {shader_lighting_2x_p_EnvMap_p_hlsl, 0},

        {shader_lighting_2x_p_EnvMap_p_hlsl, shader_WINDOW, shader_empty, 0},

        {shader_lighting_2x_p_EnvMap_p_hlsl, shader_EYE, shader_empty, 0},

        {shader_lighting_2x_p_land_p_hlsl, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_land_p_hlsl, shader_PROJ_SHADOW, shader_empty, shader_LANDALPHA, shader_empty, 0},

        {shader_lighting_2x_p_landlighting_p_hlsl, shader_DIFF, shader_empty, shader_PTLIGHT, shader_empty, 0},

        {shader_lighting_2x_p_landlighting_p_hlsl, shader_SPECULAR, shader_empty, 0},

        {0},

        {shader_lighting_2x_p_landlighting_p_hlsl, shader_LANDALPHA, shader_empty, shader_DIFF, shader_empty,
         shader_PTLIGHT, shader_empty, 0},

        {shader_lighting_2x_p_landlighting_p_hlsl, shader_LANDALPHA, shader_empty, shader_SPECULAR, shader_empty, 0},

        {0},

        {shader_lighting_2x_p_landlighting_p_hlsl, shader_SPECULAR, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_landlighting_p_hlsl, shader_LANDALPHA, shader_empty, shader_SPECULAR, shader_empty,
         shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_depthmap_p_hlsl, shader_DEPTHMAP, shader_empty, shader_SHADOWMODE, shader_3, 0},

        {shader_lighting_2x_p_depthmap_p_hlsl, shader_DEPTHMAP, shader_empty, shader_SHADOWMODE, shader_3,
         shader_ALPHATEST, shader_empty, 0},

        {shader_lighting_2x_p_depthmap_p_hlsl, shader_DEPTHMAP, shader_empty, shader_SHADOWMODE, shader_3, shader_SKIN,
         shader_empty, 0},

        {shader_lighting_2x_p_depthmap_p_hlsl, shader_DEPTHMAP, shader_empty, shader_SHADOWMODE, shader_3, shader_SKIN,
         shader_empty, shader_ALPHATEST, shader_empty, 0},

        {shader_lighting_2x_p_depthmap_p_hlsl, shader_DEPTHMAP, shader_empty, shader_WATERDEPTH, shader_empty, 0},

        {shader_lighting_2x_p_renderNormals_p_hlsl, 0},

        {shader_lighting_2x_p_renderNormals_p_hlsl, shader_FIRE, shader_empty, 0},

        {shader_lighting_2x_p_renderNormals_p_hlsl, shader_CLEAR, shader_empty, 0},

        {shader_lighting_2x_p_renderDepth_p_hlsl, 0},

        {shader_lighting_2x_p_renderVelocity_p_hlsl, 0},

        {shader_lighting_2x_p_land_p_hlsl, 0},

        {shader_lighting_2x_p_land_p_hlsl, shader_LANDALPHA, shader_empty, 0},

        {shader_lighting_2x_p_land_p_hlsl, shader_LANDLO, shader_empty, shader_FOG, shader_empty, 0},

        {shader_lighting_2x_p_land_p_hlsl, shader_SI, shader_empty, 0},

        {shader_lighting_2x_p_land_p_hlsl, shader_LANDALPHA, shader_empty, shader_SI, shader_empty, 0},

        {shader_lighting_2x_p_land_p_hlsl, shader_PTLIGHT, shader_empty, 0},

        {shader_lighting_2x_p_land_p_hlsl, shader_LANDALPHA, shader_empty, shader_PTLIGHT, shader_empty, 0},

        {shader_lighting_2x_p_localMap_p_hlsl, 0},

        {shader_lighting_2x_p_localMap_p_hlsl, shader_CLEAR, shader_empty, 0},

        {shader_lighting_1x_p_texEffect_p_hlsl, shader_HQ, shader_empty, 0},

        {shader_lighting_2x_p_WaterFog_p_hlsl, 0},

        {shader_lighting_2x_p_WaterFog_p_hlsl, shader_ALPHATESTING, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_1, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_1, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_1, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_IGNORE_NORMALS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_1, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_IGNORE_NORMALS, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_1, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_1, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_1, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_IGNORE_NORMALS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_1, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_IGNORE_NORMALS, shader_empty, shader_PROJ_SHADOW,
         shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_2, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_2, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_2, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_IGNORE_NORMALS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_2, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_IGNORE_NORMALS, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_2, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_2, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_2, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_IGNORE_NORMALS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_2, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_IGNORE_NORMALS, shader_empty, shader_PROJ_SHADOW,
         shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_3, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_3, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_3, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_IGNORE_NORMALS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_3, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_IGNORE_NORMALS, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_3, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_3, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_3, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_IGNORE_NORMALS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_3, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_IGNORE_NORMALS, shader_empty, shader_PROJ_SHADOW,
         shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_4, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_4, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_4, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_IGNORE_NORMALS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_4, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_IGNORE_NORMALS, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_4, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_4, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_4, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_IGNORE_NORMALS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_4, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_IGNORE_NORMALS, shader_empty, shader_PROJ_SHADOW,
         shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_5, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_5, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_5, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_IGNORE_NORMALS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_5, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_IGNORE_NORMALS, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_5, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_5, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_5, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_IGNORE_NORMALS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_5, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_IGNORE_NORMALS, shader_empty, shader_PROJ_SHADOW,
         shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_6, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_6, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_6, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_IGNORE_NORMALS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_6, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_IGNORE_NORMALS, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_6, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_6, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_6, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_IGNORE_NORMALS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_6, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_IGNORE_NORMALS, shader_empty, shader_PROJ_SHADOW,
         shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_7, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_7, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_7, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_IGNORE_NORMALS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_7, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_IGNORE_NORMALS, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_7, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_7, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_PROJ_SHADOW, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_7, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_IGNORE_NORMALS, shader_empty, 0},

        {shader_lighting_2x_p_LandO_p_hlsl, shader_TEXCOUNT, shader_7, shader_FOG, shader_empty, shader_HIGHQUAL,
         shader_empty, shader_PTLIGHTS, shader_empty, shader_IGNORE_NORMALS, shader_empty, shader_PROJ_SHADOW,
         shader_empty, 0},

        {shader_lighting_2x_p_Lando_p_hlsl, shader_FOG, shader_empty, shader_SILHOUETTE, shader_empty},

        {shader_lighting_2x_p_landlod_p_hlsl, shader_MODELSPACENORM, shader_empty, shader_LODLANDCLIP, shader_empty,
         shader_LODLANDNOISE, shader_empty, shader_SILHOUETTE, shader_empty, 0},

        {shader_lighting_1x_p_base_p_hlsl, shader_FOG, shader_empty, shader_FOGANDAMBIENT, shader_empty, 0},

        {shader_lighting_2x_p_adts_p_hlsl, shader_LIGHTS, shader_0, shader_SILHOUETTE, shader_empty, 0},

        {shader_lighting_2x_p_SimpleShadow_p_hlsl, shader_SHADOWMAP, shader_empty, shader_DEPTHBIAS, shader_0_1,
         shader_SAMPLE, shader_1, shader_PASSES, shader_1, shader_SHADOWMODE, shader_3, 0},

        {shader_lighting_2x_p_SimpleShadow_p_hlsl, shader_SHADOWMAP, shader_empty, shader_DEPTHBIAS, shader_0_1,
         shader_SAMPLE, shader_1, shader_PASSES, shader_1, shader_ALPHATEST, shader_empty, shader_SHADOWMODE, shader_3,
         0},

        {shader_lighting_2x_p_SimpleShadow_p_hlsl, shader_SHADOWMAP, shader_empty, shader_DEPTHBIAS, shader_0_1,
         shader_SAMPLE, shader_4, shader_PASSES, shader_1, shader_SHADOWMODE, shader_3, 0},

        {shader_lighting_2x_p_SimpleShadow_p_hlsl, shader_SHADOWMAP, shader_empty, shader_DEPTHBIAS, shader_0_1,
         shader_SAMPLE, shader_4, shader_PASSES, shader_1, shader_ALPHATEST, shader_empty, shader_SHADOWMODE, shader_3,
         0},

        {shader_lighting_2x_p_SimpleShadow_p_hlsl, shader_SHADOWMAP, shader_empty, shader_DEPTHBIAS, shader_0_1,
         shader_SAMPLE, shader_4, shader_PASSES, shader_2, shader_SHADOWMODE, shader_3, 0},

        {shader_lighting_2x_p_SimpleShadow_p_hlsl, shader_SHADOWMAP, shader_empty, shader_DEPTHBIAS, shader_0_1,
         shader_SAMPLE, shader_4, shader_PASSES, shader_2, shader_ALPHATEST, shader_empty, shader_SHADOWMODE, shader_3,
         0},

        {shader_lighting_2x_p_WaterFog_p_hlsl, shader_SRT_EYE, shader_empty, 0},

        {shader_lighting_2x_p_WaterFog_p_hlsl, shader_SRT_HEIGHT, shader_empty, 0},

    };

    char fileName[260];
    char sourcePath[260];

    for (int i = 0; i < 48; ++i)
    {

        if (shaderModel1Defs[i][0])
        {

            ResolveShaderPath(shaderModel1Defs[i][0], sourcePath);

            sprintf_s(fileName, 260, "SLS1%03i.pso", i);

            shaderModel1Programs[i] = Compile(sourcePath, &shaderModel1Defs[i][1], "ps_2_0", fileName);
        }
    }

    int iShaderModel = shaderModel;

    if (iShaderModel >= 2)
    {

        char depthBias[] = "-0.6";

        if (shaderMode == 6 || shaderMode == 4)
        {

            shaderModel2Defs[152][4] = depthBias;
            shaderModel2Defs[153][4] = depthBias;
            shaderModel2Defs[154][4] = depthBias;

            shaderModel2Defs[155][4] = depthBias;
            shaderModel2Defs[156][4] = depthBias;
            shaderModel2Defs[157][4] = depthBias;
        }

        char passes[4];
        sprintf(passes, "%i", shaderPassCount);

        shaderModel2Defs[152][10] = passes;
        shaderModel2Defs[153][12] = passes;

        shaderModel2Defs[70][4] = passes;
        shaderModel2Defs[71][4] = passes;
        shaderModel2Defs[72][4] = passes;
        shaderModel2Defs[73][4] = passes;

        for (int i = 0; i < 160; ++i)
        {

            if (!shaderModel2Defs[i][0])
                shaderModel2Programs[i] = 0;

            else if (i <= 153 || iShaderModel >= 5)
            {

                ResolveShaderPath(shaderModel2Defs[i][0], sourcePath);

                sprintf_s(fileName, 260, "SLS2%03i.pso", i);

                if ((i >= 152 && i <= 152) || (i >= 70 && i <= 73))
                    sprintf_s(fileName, 260, "SLS2%03is%01i.pso", i, shaderPassCount);

                shaderModel2Programs[i] = Compile(sourcePath, &shaderModel2Defs[i][1], "ps_2_0", fileName);
            }
        }
    }
}

namespace fnv_00b7dab0 {
struct MatX
{
    float _11, _12, _13, _14, _21, _22, _23, _24, _31, _32, _33, _34, _41, _42, _43, _44;
};
struct Flg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char f;
};
struct PropX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int m20;
};
struct ArgX
{
    Flg* m0;
    int m4;
    int m8;
    PropX* mC;
    Flg* m10;
};
struct Sub
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
    int m34;
};

struct GeoX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m20;
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
    NiTransform m68;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    Sub* mB8;
    void* mBC;
};
struct StX
{
    GeoX* m0;
};
extern StX* DAT_011f91e0;
extern int DAT_011f91e4;
extern char DAT_011f4288;
struct GX
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
    void* m44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    void* m5c;
};
extern GX* DAT_0126f74c;
class LstX
{
  public:
    virtual void a0(), a1(), a2(), a3(), a4(), a5(), a6(), a7(), a8(), a9(), a10(), a11(), a12(), a13(), a14(), a15(),
        a16(), a17(), a18(), a19(), a20(), a21(), a22(), a23(), a24(), a25(), a26(), a27(), a28(), a29();
    virtual void Fn(void* p, GeoX* g, void* q, int z0, int c, ArgX* a, int z1, void* t, void* n, int z2, int one);
};
class OutX
{
  public:
    virtual void b0(), b1(), b2(), b3(), b4(), b5(), b6(), b7(), b8();
    virtual void Fn(Flg* f);
};
void __cdecl BSUtilities_GetInverseWorldMatrix(void* t, void* p, MatX* out);
void __cdecl BSRenderState_SetZWriteEnable(int a, int b);
void __cdecl FUN_00b98380(int a, int b);
void __cdecl UpdatePlaneFromPoint();
class RX
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    OutX* m1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    LstX* m30;
    LstX* m34;
    void ShadowLightShader_SetupGeometryOpt_WorldViewProj(GeoX* g, void* t);
    void SetupPass(GeoX* g, PropX* p, StX* s);
    void ShadowLightShader_UpdatePipelineZOnlyTexEffect(GeoX* g, PropX* p, StX* s);
    void UpdateLightPass(PropX* p, StX* s, MatX m, void* t, int type, void* q);
    void ShadowLightShader_SetupGeometryConstants_AmbientEmittance(PropX* p, StX* s, GeoX* g, int c);
    void ShadowLightShader_SetupGeometryConstants_ObjToCube(StX* s, int type, void* q, void* t);
    void UpdateWorldMatrix(ArgX* a, void* q, void* t);
    void UpdateEyePosition(int type, void* t, MatX m);
    void ResetTransform(void* q);
    void UpdateScaledValue(PropX* p);
    void ShadowLightShader_SetupGeometryConstants_WorldBoundCenter(GeoX* g);
    void ShadowLightShader_SetupGeometryConstants_HighDetailRange(GeoX* g);
    void ShadowLightShader_SetupGeometryConstants_LODLandParams(int type, PropX* p, GeoX* g);
    void ShadowLightShader_SetupGeometryConstants_LandTextureMask(int type, StX* s);
    void ApplyFogAndAlpha(int type, GeoX* g, PropX* p, int c, StX* s, Flg* f);
    void ShadowLightShader_SetupGeometryConstants_RefractionPower(PropX* p);
    void ShadowLightShader_SetupGeometryConstants_SimpleShadowClipPlanes(int type);
    void ShadowLightShader_SetupGeometryConstants_LODTexParams(PropX* p);
    void UpdateRenderPass(ArgX* a);
};
// @fnv 0x00b7dab0
void RX::UpdateRenderPass(ArgX* apArg)
{
    StX* s = DAT_011f91e0;
    GeoX* g = s->m0;
    int type = DAT_011f91e4;
    NiTransform* t = &g->m68;
    void* n = g->m20;
    if (!n)
        n = &DAT_011f4288;
    int c18 = g->mB8->m34;
    void* q = g->mBC;
    PropX* p = apArg->mC;
    int c = apArg->m8;
    Flg* f = apArg->m0;
    if ((type == 6 || type == 8) && (p->m20 & 0x40000) > 0 && (f->f & 1))
    {
        BSRenderState_SetZWriteEnable(0, 1);
        FUN_00b98380(0, 1);
    }
    MatX m;
    BSUtilities_GetInverseWorldMatrix(t, q, &m);
    if (!q)
        ShadowLightShader_SetupGeometryOpt_WorldViewProj(g, t);
    if (type == 0x250 || type == 0x251)
    {
        SetupPass(g, p, s);
    }
    else if (type == 4 || type == 5)
    {
        ShadowLightShader_UpdatePipelineZOnlyTexEffect(g, p, s);
    }
    else
    {
        UpdateLightPass(p, s, m, t, type, q);
        ShadowLightShader_SetupGeometryConstants_AmbientEmittance(p, s, g, c);
        ShadowLightShader_SetupGeometryConstants_ObjToCube(s, type, q, t);
        UpdateWorldMatrix(apArg, q, t);
        UpdateEyePosition(type, t, m);
        ResetTransform(q);
        UpdateScaledValue(p);
        ShadowLightShader_SetupGeometryConstants_WorldBoundCenter(g);
        ShadowLightShader_SetupGeometryConstants_HighDetailRange(g);
        ShadowLightShader_SetupGeometryConstants_LODLandParams(type, p, g);
        ShadowLightShader_SetupGeometryConstants_LandTextureMask(type, s);
        ApplyFogAndAlpha(type, g, p, c, s, f);
        ShadowLightShader_SetupGeometryConstants_RefractionPower(p);
        UpdatePlaneFromPoint();
        ShadowLightShader_SetupGeometryConstants_SimpleShadowClipPlanes(type);
        ShadowLightShader_SetupGeometryConstants_LODTexParams(p);
    }
    LstX* l30 = m30;
    if (l30)
    {
        void* d = DAT_0126f74c->m44;
        if (d)
            l30->Fn(d, g, q, 0, c18, apArg, 0, t, n, 0, 1);
    }
    LstX* l34 = m34;
    if (l34)
    {
        void* d = DAT_0126f74c->m5c;
        if (d)
            l34->Fn(d, g, q, 0, c18, apArg, 0, t, n, 0, 1);
    }
    if (apArg->m10 && (apArg->m10->f & 1))
        m1c->Fn(apArg->m10);
}
}  // namespace fnv_00b7dab0

namespace fnv_00be9920 {
struct StageReturn
{
    int unk00;
    long unk04;
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
    int refs;
    void __thiscall ReturnToPool();
    __forceinline void IncRefCount()
    {
        ++refs;
    }
    __forceinline void DecRefCount()
    {
        --refs;
        if (refs == 0)
            ReturnToPool();
    }
};
void __cdecl AssignStageFromPool(StageReturn*&);
typedef NiPointer<StageReturn> StagePtr;
int __cdecl ConfigureBeamStage(void* a, int b, int c, int d, int e);
struct RendObj;
struct StageSub
{
    void __thiscall SetNodeValue(int a, int b, int c);
};
void* __cdecl FUN_00e7f5d0();
struct RendVtbl
{
    void* f0;
    void(__thiscall* release)(RendObj*);
};
typedef long(__stdcall* ImpFn)(volatile long*);
struct RendObj
{
    RendVtbl* vtbl;
    long unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* f14;
    int f18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    StageSub* f30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    RendObj* f44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    RendObj* f5c;
    int unk60;
    int refs;
    __forceinline void SetPixelShader(RendObj* replacement, ImpFn decrement)
    {
        RendObj* old = f5c;
        if (old != replacement)
        {
            if (old && !decrement(&old->unk04))
                old->vtbl->release(old);
            f5c = replacement;
            if (replacement)
                InterlockedIncrement(&replacement->unk04);
        }
    }
    __forceinline void SetVertexShader(RendObj* replacement, ImpFn decrement)
    {
        RendObj* old = f44;
        if (old != replacement)
        {
            if (old && !decrement(&old->unk04))
                old->vtbl->release(old);
            f44 = replacement;
            if (replacement)
                InterlockedIncrement(&replacement->unk04);
        }
    }
    void FUN_00e80190();
    __forceinline void IncRefCount()
    {
        ++refs;
    }
    __forceinline void DecRefCount()
    {
        if (--refs == 0)
            FUN_00e80190();
    }
    __forceinline unsigned int GetStageCount() const
    {
        return f18;
    }
    __forceinline void SetState(int state, int value, int enabled)
    {
        if (!f30)
            f30 = (StageSub*)FUN_00e7f5d0();
        f30->SetNodeValue(state, value, enabled);
    }
};

struct RendObj2
{
    void __thiscall NiD3DPass_SetStage(void* a, void* b);
    void __thiscall FUN_00e80190();
    void __thiscall NiD3DPass_SetPixelShader(RendObj* a);
    void __thiscall NiD3DPass_SetVertexShader(RendObj* a);
};
typedef NiPointer<RendObj> SPtr;
struct PassObj : RendObj
{
    __forceinline void DecRefCount()
    {
        int& r = refs;
        if (--r == 0)
            FUN_00e80190();
    }
};
typedef NiPointer<PassObj> PassPtr;

extern SPtr DAT_011fe940;
extern SPtr DAT_011fe944;
extern SPtr DAT_011fe948;
extern SPtr DAT_011fe94c;
extern RendObj* DAT_011fddcc;
extern RendObj* DAT_011fddd0;
extern RendObj* DAT_011fde08;
extern RendObj* DAT_011fde0c;
extern RendObj* DAT_011fdac0;
extern RendObj* DAT_011fdac4;
extern int DAT_011fd5c8, DAT_011fc9e8, DAT_011fbe08;
extern int DAT_011fd5cc, DAT_011fc9ec, DAT_011fbe0c;
extern int DAT_011fd5d0, DAT_011fc9f0, DAT_011fbe10;
extern int DAT_011fd5d4, DAT_011fc9f4, DAT_011fbe14;

// Configures four global render objects by adding a stage if needed, setting pixel/vertex shaders, render states, and associated global values.
// @fnv 0x00be9920
// src: COMMUNITY 0x00be9920
void __cdecl ShadowLightShader_PresetFogPasses_1x()
{
    SPtr pRendObj;
    StagePtr stage;
    pRendObj = DAT_011fe940;
    if (pRendObj->GetStageCount() < 1)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage(stage.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pRendObj.m_pObject)->NiD3DPass_SetStage(pRendObj->f14, stage.m_pObject);
    }
    pRendObj->SetPixelShader(DAT_011fddcc, InterlockedDecrement);
    pRendObj->SetVertexShader(DAT_011fdac0, InterlockedDecrement);
    pRendObj->SetState(27, 1, 1);
    pRendObj->SetState(19, 5, 1);
    pRendObj->SetState(20, 6, 1);
    pRendObj->SetState(15, 0, 1);
    pRendObj->SetState(7, 1, 1);
    pRendObj->SetState(23, 3, 1);
    pRendObj->SetState(14, 0, 1);
    DAT_011fd5c8 = 768;
    DAT_011fc9e8 = 0;
    DAT_011fbe08 = 0x300;

    pRendObj = DAT_011fe944;
    if (pRendObj->GetStageCount() < 1)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage(stage.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pRendObj.m_pObject)->NiD3DPass_SetStage(pRendObj->f14, stage.m_pObject);
    }
    pRendObj->SetPixelShader(DAT_011fddd0, InterlockedDecrement);
    pRendObj->SetVertexShader(DAT_011fdac4, InterlockedDecrement);
    pRendObj->SetState(27, 1, 1);
    pRendObj->SetState(19, 5, 1);
    pRendObj->SetState(20, 6, 1);
    pRendObj->SetState(15, 0, 1);
    pRendObj->SetState(7, 1, 1);
    pRendObj->SetState(23, 3, 1);
    pRendObj->SetState(14, 0, 1);
    DAT_011fd5cc = 768;
    DAT_011fc9ec = 0;
    DAT_011fbe0c = 0x300;

    pRendObj = DAT_011fe948;
    if (pRendObj->GetStageCount() < 1)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage(stage.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pRendObj.m_pObject)->NiD3DPass_SetStage(pRendObj->f14, stage.m_pObject);
    }
    pRendObj->SetPixelShader(DAT_011fde08, InterlockedDecrement);
    pRendObj->SetVertexShader(DAT_011fdac0, InterlockedDecrement);
    pRendObj->SetState(27, 1, 1);
    pRendObj->SetState(19, 5, 1);
    pRendObj->SetState(20, 6, 1);
    pRendObj->SetState(15, 0, 1);
    pRendObj->SetState(7, 1, 1);
    pRendObj->SetState(23, 3, 1);
    pRendObj->SetState(14, 0, 1);
    DAT_011fd5d0 = 2816;
    DAT_011fc9f0 = 0;
    DAT_011fbe10 = 0x300;

    pRendObj = DAT_011fe94c;
    if (pRendObj->GetStageCount() < 1)
    {
        AssignStageFromPool(stage.m_pObject);
        ConfigureBeamStage(stage.m_pObject, 0, 1, 2, 1);
        ((RendObj2*)pRendObj.m_pObject)->NiD3DPass_SetStage(pRendObj->f14, stage.m_pObject);
    }
    pRendObj->SetPixelShader(DAT_011fde0c, InterlockedDecrement);
    pRendObj->SetVertexShader(DAT_011fdac4, InterlockedDecrement);
    pRendObj->SetState(27, 1, 1);
    pRendObj->SetState(19, 5, 1);
    pRendObj->SetState(20, 6, 1);
    pRendObj->SetState(15, 0, 1);
    pRendObj->SetState(7, 1, 1);
    pRendObj->SetState(23, 3, 1);
    pRendObj->SetState(14, 0, 1);
    DAT_011fd5d4 = 2816;
    DAT_011fc9f4 = 0;
    DAT_011fbe14 = 0x300;
}
}  // namespace fnv_00be9920
