#pragma once

#include <stddef.h>
#include "NiProperty.h"


class NiTexture;
class NiStream;
class TextureMapTransform;
class NiPixelData;
struct TextureFormatPreferences;

#include "NiTMallocInterface.h"
#include "NiTPrimitiveArray.h"

class NiTexturingProperty : public NiProperty
{
  public:
    enum ApplyMode  // values: Xbox PDB NiTexturingProperty::ApplyMode
    {
        APPLY_REPLACE = 0,
        APPLY_DECAL = 1,
        APPLY_MODULATE = 2,
        APPLY_DEPRECATED = 3,
        APPLY_DEPRECATED2 = 4,
        APPLY_MAX_MODES = 5
    };

    enum ClampMode  // values: Xbox PDB NiTexturingProperty::ClampMode
    {
        CLAMP_S_CLAMP_T = 0,
        CLAMP_S_WRAP_T = 1,
        WRAP_S_CLAMP_T = 2,
        WRAP_S_WRAP_T = 3,
        CLAMP_MAX_MODES = 4
    };

    enum FilterMode  // values: Xbox PDB NiTexturingProperty::FilterMode
    {
        FILTER_NEAREST = 0,
        FILTER_BILERP = 1,
        FILTER_TRILERP = 2,
        FILTER_NEAREST_MIPNEAREST = 3,
        FILTER_NEAREST_MIPLERP = 4,
        FILTER_BILERP_MIPNEAREST = 5,
        FILTER_ANISO = 6,
        FILTER_MAGLERP_MINANISO = 7,
        FILTER_MAX_MODES = 8
    };

    class Map;
    class BumpMap;
    class ParallaxMap;
    class ShaderMap;

    unsigned short m_uiObjectFlags;
    unsigned char unk1A[2];
    NiTPrimitiveArray<Map*> m_kStringArray;
    NiTPrimitiveArray<ShaderMap*>* m_pShaderMaps;

    NiTexturingProperty();
    NiTexturingProperty(NiPixelData* pixelData, const NiFixedString& name, TextureFormatPreferences& preferences);
    virtual ~NiTexturingProperty();
    virtual void LoadBinary(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);

    static NiPointer<NiTexturingProperty> ms_pDefaultProperty;
    static NiFixedString ms_kTextureMapNames[10];
    static void InitializePoint3();

    unsigned int UpdateState_00a46410();
    void SetBaseTexture(void*);
    void FUN_004f3200(int);
    void NiStencilProperty_SetStencilFailAction(int);
    void SetBaseMap(Map*);

    void SetApplyMode(ApplyMode mode);
    void SetMultiTexture(bool multi);
    void UpdateMultiTexture();
    void SetBaseMapFilterMode(FilterMode mode);
    void SetBaseMapClampMode(ClampMode mode);
    void SetBaseMapClampMode(int mode);

    Map* GetBaseMap() const;
    Map* GetDarkMap() const;
    Map* GetDetailMap() const;
    Map* GetGlossMap() const;
    Map* GetGlowMap() const;
    BumpMap* GetBumpMap() const;
    Map* GetNormalMap() const;
    ParallaxMap* GetParallaxMap() const;
    Map* GetDecalMap(unsigned int index) const;
    ShaderMap* GetShaderMap(unsigned int index) const;
};

// A texture map: vftable 0x0109c4c4 (4 slots), 0x10 bytes; its flags hold the texture index (bits 0-7), the filter
// mode (bits 8-11) and the clamp mode (bits 12-13).
class NiTexturingProperty::Map
{
  public:
    // NiPointer<NiTexture> in the original. Its template (NiAVObject.h) cannot be included by this header's users, so
    // the smart pointer is spelled out here; units define the operations they inline.
    class TexturePtr
    {
      public:
        TexturePtr(NiTexture* pkTexture = 0);
        TexturePtr(const TexturePtr& kPtr);
        NiTexture* m_pObject;
    };

    Map();
    Map(const Map& kMap);
    virtual ~Map();
    virtual void LoadBinary(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual unsigned int GetClassID();

    void SetClampMode(ClampMode eMode);
    void SetFilterMode(FilterMode eMode);
    void SetTextureIndex(unsigned int uiIndex);
    static void* operator new(size_t uiSize);

    unsigned short m_usFlags;
    TexturePtr m_spTexture;
    TextureMapTransform* m_pTextureTransform;
};

// vftable 0x0109c4d8, 0x28 bytes.
class NiTexturingProperty::BumpMap : public Map
{
  public:
    BumpMap() throw();

    float m_fLumaScale;
    float m_fLumaOffset;
    float m_fBumpMat00;
    float m_fBumpMat01;
    float m_fBumpMat10;
    float m_fBumpMat11;
};

// vftable 0x0109c500, 0x14 bytes.
class NiTexturingProperty::ParallaxMap : public Map
{
  public:
    ParallaxMap() throw();

    float m_fParallaxOffset;
};

// vftable 0x0109c4ec.
class NiTexturingProperty::ShaderMap : public Map
{
  public:
    ShaderMap(unsigned int uiID = 0);
    virtual ~ShaderMap();
    virtual void LoadBinary(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual unsigned int GetClassID();

    unsigned int m_uiID;
};
typedef char NiTexturingProperty_Map_size_check[(sizeof(NiTexturingProperty::Map) == 0x10) ? 1 : -1];
typedef char NiTexturingProperty_BumpMap_size_check[(sizeof(NiTexturingProperty::BumpMap) == 0x28) ? 1 : -1];
typedef char NiTexturingProperty_ParallaxMap_size_check[(sizeof(NiTexturingProperty::ParallaxMap) == 0x14) ? 1 : -1];
