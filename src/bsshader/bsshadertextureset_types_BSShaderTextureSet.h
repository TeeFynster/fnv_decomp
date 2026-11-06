// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSSHADERTEXTURESET_H
#define FNV_BSSHADERTEXTURESET_H

#include "layout_support.h"
#include "NiObject.h"
#include "layout_support.h"
class BSShaderTextureSet;
class BSTextureSet;
#pragma pack(push, 4)
class BSTextureSet : public NiObject
{
  public:
    // slots 0x00-0x88 are the shared NiObject virtuals (LoadBinary 0x4c, SaveBinary 0x58)
    virtual void GetTexture(BSShaderProperty::TextureTypeEnum textureType, NiPointer<NiTexture>& texture);
    virtual const char* GetTexture(BSShaderProperty::TextureTypeEnum textureType);  // MSVC lays overloads out in reverse: this one is slot 0x8c
    virtual void SetTexture(BSShaderProperty::TextureTypeEnum textureType, const char* textureName);
    // base NiObject at +0x0, size 8
    // void __cdecl BSTextureSet::*(NiStream&)
    // void __cdecl BSTextureSet::*(NiStream&)
    // bool __cdecl BSTextureSet::*(NiStream&)
    // void __cdecl BSTextureSet::*(NiStream&)
    // bool __cdecl BSTextureSet::*(NiObject*)
    // const NiRTTI* __cdecl BSTextureSet::*()
    // BSTextureSet
    // void __cdecl BSTextureSet::*()
    // BSTextureSet& __cdecl BSTextureSet::*(const BSTextureSet&)
    // void __cdecl BSTextureSet::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSTextureSet) == 8);
#pragma pack(push, 4)
class BSShaderTextureSet : public BSTextureSet
{
  public:
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual const char* GetTexture(BSShaderProperty::TextureTypeEnum textureType);
    virtual void GetTexture(BSShaderProperty::TextureTypeEnum textureType, NiPointer<NiTexture>& texture);
    virtual void SetTexture(BSShaderProperty::TextureTypeEnum textureType, const char* textureName);
    // base BSTextureSet at +0x0, size 8
    BSStringT<char> m_kTextureNames[7];  // +0x8, 56 bytes
    // void __cdecl BSShaderTextureSet::*(NiStream&)
    // void __cdecl BSShaderTextureSet::*(NiStream&)
    // bool __cdecl BSShaderTextureSet::*(NiStream&)
    // void __cdecl BSShaderTextureSet::*(NiStream&)
    // bool __cdecl BSShaderTextureSet::*(NiObject*)
    // NiObject* __cdecl BSShaderTextureSet::*()
    // const NiRTTI* __cdecl BSShaderTextureSet::*()
    // const char* __cdecl BSShaderTextureSet::*(BSShaderProperty::TextureTypeEnum)
    // void __cdecl BSShaderTextureSet::*(BSShaderProperty::TextureTypeEnum, NiPointer<NiTexture>&)
    // void __cdecl BSShaderTextureSet::*(BSShaderProperty::TextureTypeEnum, const char*)
    // BSShaderTextureSet
    // void __cdecl BSShaderTextureSet::*()
    // BSShaderTextureSet& __cdecl BSShaderTextureSet::*(const BSShaderTextureSet&)
    // void __cdecl BSShaderTextureSet::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSShaderTextureSet) == 64);
FNV_STATIC_ASSERT(offsetof(BSShaderTextureSet, m_kTextureNames) == 8);
#endif
