#pragma once

#include "NiObjectNET.h"
#include "NiTexturingProperty.h"

class TextureAccessor;
class ExtraName;

class NiTexture : public NiObjectNET
{
  public:
    struct TextureFormatPreferences
    {
        enum PixelLayout
        {
            PALETTIZED_8,
            HIGH_COLOR_16,
            TRUE_COLOR_32,
            COMPRESSED,
            BUMPMAP,
            PALETTIZED_4,
            PIX_DEFAULT,
            SINGLE_COLOR_8,
            SINGLE_COLOR_16,
            SINGLE_COLOR_32,
            DOUBLE_COLOR_32,
            DOUBLE_COLOR_64,
            FLOAT_COLOR_32,
            FLOAT_COLOR_64,
            FLOAT_COLOR_128
        };

        enum AlphaFormat
        {
            NONE,
            BINARY,
            SMOOTH,
            ALPHA_DEFAULT
        };

        enum MipFlag
        {
            NO,
            YES,
            MIP_DEFAULT
        };

        PixelLayout m_ePreferredPixelLayout;
        AlphaFormat m_eAlphaFormat;
        MipFlag m_eMipFlag;
    };

    class RendererData;

    typedef NiTexturingProperty::FilterMode FilterMode;
    typedef NiTexturingProperty::ClampMode ClampMode;

    NiTexture();
    virtual ~NiTexture();
    virtual void DeleteThis();
    virtual void LoadBinary(NiStream&);
    virtual bool RegisterStreamables(NiStream&);

    virtual void Unk_23();
    virtual void Unk_24();
    virtual unsigned int GetWidth();
    virtual unsigned int GetHeight();
    virtual const NiFixedString& GetPath() const;
    virtual void vf40();

    void IncRefCount();
    void DecRefCount();
    void SetFilterMode(FilterMode mode);
    void SetClampMode(ClampMode mode);
    void SetFlag4000(unsigned int flags);
    void SetApply(unsigned int value);
    void SetFilter(unsigned int value);
    void Apply(unsigned int);
    void* Destroy(unsigned int);
    const NiFixedString& GetFilename();
    unsigned int GetRenderedWidth();
    unsigned int GetRenderedHeight();

    NiFixedString* FUN_00413f40();
    TextureAccessor* FUN_0059bb30();
    int NiTexture_GetTextureQualityLevel();
    int FUN_00726070();
    NiTexture* FUN_0055b980();
    NiTexture* BSFaceGenImage_GetCompressedImage(float lo, float hi, float scale, void* srcv);
    const ExtraName& GetFilename_00a62660();

    TextureFormatPreferences m_kFormatPrefs;
    RendererData* m_pkRendererData;
    NiTexture* m_pkPrev;
    NiTexture* m_pkNext;
};
