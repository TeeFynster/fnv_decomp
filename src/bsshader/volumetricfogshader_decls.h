#ifndef VOLUMETRICFOGSHADER_DECLS_H
#define VOLUMETRICFOGSHADER_DECLS_H


#include <stddef.h>

#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiRefObject.h"

#include "../../include/NiMemObject.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

__forceinline void NiD3DShaderConstantMap::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

__forceinline void NiD3DShaderConstantMap::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

template <class T> __forceinline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

template <class T> __forceinline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

template <class T> __forceinline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
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

class NiD3DVertexDeclaration
{
  public:
    static NiD3DVertexDeclaration* Create(NiRenderer* renderer, unsigned int first, unsigned int second);
};

class NiConsoleShaderDeclarationVTable
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
};

class BSShader;
class VolumetricFogShader;

class VolumetricFogShader : public NiMemObject
{
  public:
    VolumetricFogShader();
    unsigned char layoutPadding0[0x18];
    GraphicsRenderer* m_pShaderObject;
    unsigned char layoutPadding1[0x14];
    NiPointer<NiD3DShaderConstantMap> m_spFirstShaderConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spSecondShaderConstantMap;
    unsigned char layoutPadding2[0x50];
    unsigned char m_data88[0x10];
    unsigned char m_data98[0x10];

    BSShader* CreateShader();
    void UpdateShaderConstants();
};

class VolumetricFogShaderVTable
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0(NiD3DVertexDeclaration* declaration);
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
};

extern NiRenderer* DAT_011f9508;
extern const char g_emptyTopicInfoPrompt[];
extern const char DAT_010babec[];
extern const char DAT_010bb0ac[];
extern "C" const char DAT_010A1E50[];

typedef char NiD3DShaderConstantMap_must_be_68_bytes[(sizeof(NiD3DShaderConstantMap) == 0x44) ? 1 : -1];
typedef char VolumetricFogShader_must_be_168_bytes[(sizeof(VolumetricFogShader) == 0xa8) ? 1 : -1];
typedef char
    VolumetricFogShader_pixel_map_at_30[(offsetof(VolumetricFogShader, m_spFirstShaderConstantMap) == 0x30) ? 1 : -1];
typedef char
    VolumetricFogShader_vertex_map_at_34[(offsetof(VolumetricFogShader, m_spSecondShaderConstantMap) == 0x34) ? 1 : -1];
typedef char VolumetricFogShader_renderer_at_18[(offsetof(VolumetricFogShader, m_pShaderObject) == 0x18) ? 1 : -1];
typedef char VolumetricFogShader_data_at_88[(offsetof(VolumetricFogShader, m_data88) == 0x88) ? 1 : -1];
typedef char VolumetricFogShader_data_at_98[(offsetof(VolumetricFogShader, m_data98) == 0x98) ? 1 : -1];

#endif
