
// NiPixelFormat: Gamebryo pixel format description.
#include "layout_support.h"
#include "../../../../include/NiPixelFormat.h"


FNV_STATIC_ASSERT(sizeof(NiPixelFormat) == 0x44);

// Initializes the pixel format to an 8-bit palettized format with an index component and three empty components.
// @fnv 0x00a7cca0
NiPixelFormat::NiPixelFormat()
{
    m_ucBitsPerPixel = 8;
    m_eFormat = FORMAT_PAL;
    m_uiRendererHint = 0xffffffff;
    m_uiExtraData = 0;
    m_uiObjectFlags = 1;
    m_eTiling = TILE_NONE;
    m_akComponents[0].m_eComponent = COMP_INDEX;
    m_akComponents[0].m_eRepresentation = REP_INDEX;
    m_akComponents[0].m_ucBits = 8;
    m_akComponents[0].m_bSigned = true;
    m_akComponents[1].m_eComponent = COMP_EMPTY;
    m_akComponents[1].m_eRepresentation = REP_UNKNOWN;
    m_akComponents[1].m_ucBits = 0;
    m_akComponents[1].m_bSigned = true;
    m_akComponents[2].m_eComponent = COMP_EMPTY;
    m_akComponents[2].m_eRepresentation = REP_UNKNOWN;
    m_akComponents[2].m_ucBits = 0;
    m_akComponents[2].m_bSigned = true;
    m_akComponents[3].m_eComponent = COMP_EMPTY;
    m_akComponents[3].m_eRepresentation = REP_UNKNOWN;
    m_akComponents[3].m_ucBits = 0;
    m_akComponents[3].m_bSigned = true;
}

struct NiPixelFormatMasks : public NiPixelFormat
{
    static unsigned int CountBits(unsigned int uiMask)
    {
        unsigned int uiBits = 0;
        while (uiMask)
        {
            uiBits += uiMask & 1;
            uiMask >>= 1;
        }
        return uiBits;
    }

    static NiPixelFormatMasks CreateFromMasks(unsigned char ucBitsPerPixel, unsigned int uiRedMask,
                                              unsigned int uiGreenMask, unsigned int uiBlueMask,
                                              unsigned int uiAlphaMask);
};

// @fnv 0x00a7cd20
NiPixelFormatMasks NiPixelFormatMasks::CreateFromMasks(unsigned char ucBitsPerPixel, unsigned int uiRedMask,
                                                       unsigned int uiGreenMask, unsigned int uiBlueMask,
                                                       unsigned int uiAlphaMask)
{
    NiPixelFormatMasks kFormat;
    kFormat.m_ucBitsPerPixel = ucBitsPerPixel;
    kFormat.m_eFormat = (Format)(uiAlphaMask != 0);
    kFormat.m_uiObjectFlags |= 1;
    kFormat.m_uiRendererHint = 0xffffffff;
    kFormat.m_eTiling = TILE_NONE;

    unsigned int auiMasks[NUM_COMPS];
    unsigned char aucBits[NUM_COMPS];
    Component aeComps[NUM_COMPS];
    auiMasks[0] = uiRedMask;
    aeComps[0] = COMP_RED;
    aucBits[0] = CountBits(uiRedMask);
    auiMasks[1] = uiGreenMask;
    aeComps[1] = COMP_GREEN;
    aucBits[1] = CountBits(uiGreenMask);
    auiMasks[2] = uiBlueMask;
    aeComps[2] = COMP_BLUE;
    aucBits[2] = CountBits(uiBlueMask);
    auiMasks[3] = uiAlphaMask;
    aeComps[3] = COMP_ALPHA;
    aucBits[3] = CountBits(uiAlphaMask);

    int i;
    for (i = 0; i < 3; i++)
    {
        if (auiMasks[i] == 0)
            continue;
        for (int iInner = i + 1; iInner < 3; iInner++)
        {
            unsigned int uiMaskOuter = auiMasks[i];
            unsigned int uiMaskInner = auiMasks[iInner];
            if (uiMaskOuter > uiMaskInner)
            {
                unsigned char ucBitsInner = aucBits[iInner];
                Component eCompInner = aeComps[iInner];
                auiMasks[iInner] = uiMaskOuter;
                aucBits[iInner] = aucBits[i];
                aeComps[iInner] = aeComps[i];
                aeComps[i] = eCompInner;
                auiMasks[i] = uiMaskInner;
                aucBits[i] = ucBitsInner;
            }
        }
    }

    unsigned int uiComponentIndex, uiMaskIndex;
    for (uiComponentIndex = 0, uiMaskIndex = 0; uiMaskIndex < NUM_COMPS; uiMaskIndex++)
    {
        if (auiMasks[uiMaskIndex] != 0)
        {
            kFormat.m_akComponents[uiComponentIndex].m_bSigned = true;
            kFormat.m_akComponents[uiComponentIndex].m_ucBits = aucBits[uiMaskIndex];
            kFormat.m_akComponents[uiComponentIndex].m_eRepresentation = REP_FIXED;
            kFormat.m_akComponents[uiComponentIndex].m_eComponent = aeComps[uiMaskIndex];
            uiComponentIndex++;
        }
    }
    for (; uiComponentIndex < NUM_COMPS; uiComponentIndex++)
    {
        NiComponentSpec& kSpec = kFormat.m_akComponents[uiComponentIndex];
        kSpec.m_bSigned = true;
        kSpec.m_ucBits = 0;
        kSpec.m_eRepresentation = REP_UNKNOWN;
        kSpec.m_eComponent = COMP_EMPTY;
    }
    return kFormat;
}

struct PixelBinaryStream
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(PixelBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    typedef unsigned int(__cdecl* Reader)(PixelBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data, unsigned int size)
    {
        unsigned int elementSize;
        unsigned int bytesRead = read(this, data, size, &(elementSize = size), 1);
        position += bytesRead;
    }
};
struct PixelStream
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
    unsigned int version;
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
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    PixelBinaryStream* binary;
};
template <class T> inline void LoadPixelValue(PixelStream& stream, T& value)
{
    stream.binary->Read(&value, sizeof(T));
}
template <class T> inline void LoadPixelEnum(PixelStream& stream, T& value)
{
    unsigned int temporary;
    LoadPixelValue(stream, temporary);
    value = (T)temporary;
}
class PixelFormatReader : public NiPixelFormat
{
  public:
    void NiPixelFormat_ConvertOldPixelFormat(Format format, unsigned char bits, unsigned int* masks);
    void ReadFromStream(PixelStream& stream);
};
// @fnv 0x00a7ced0
void PixelFormatReader::ReadFromStream(PixelStream& stream)
{
    if (stream.version < 0x0A030003)
    {
        LoadPixelEnum(stream, m_eFormat);
        unsigned int masks[4];
        for (unsigned int i = 0; i < 4; ++i)
            LoadPixelValue(stream, masks[i]);
        unsigned int bits;
        LoadPixelValue(stream, bits);
        m_ucBitsPerPixel = (unsigned char)bits;
        unsigned int fastCompare;
        LoadPixelValue(stream, fastCompare);
        LoadPixelValue(stream, fastCompare);
        if (stream.version >= 0x0A00010B)
        {
            unsigned int fastCompare2;
            LoadPixelValue(stream, fastCompare2);
        }
        NiPixelFormat_ConvertOldPixelFormat(m_eFormat, m_ucBitsPerPixel, masks);
    }
    else
    {
        LoadPixelEnum(stream, m_eFormat);
        LoadPixelValue(stream, m_ucBitsPerPixel);
        LoadPixelValue(stream, m_uiRendererHint);
        LoadPixelValue(stream, m_uiExtraData);
        LoadPixelValue(stream, m_uiObjectFlags);
        LoadPixelEnum(stream, m_eTiling);
        for (unsigned int i = 0; i < 4; ++i)
        {
            LoadPixelEnum(stream, m_akComponents[i].m_eComponent);
            LoadPixelEnum(stream, m_akComponents[i].m_eRepresentation);
            LoadPixelValue(stream, m_akComponents[i].m_ucBits);
            unsigned char isSigned;
            LoadPixelValue(stream, isSigned);
            m_akComponents[i].m_bSigned = isSigned > 0;
        }
    }
}

extern const NiPixelFormat kBGR888;
extern const NiPixelFormat kRGB888;
extern const NiPixelFormat kRGB565;
extern const NiPixelFormat kRGBA32;
extern const NiPixelFormat kBGRA32;
extern const NiPixelFormat kRGBA5551;
extern const NiPixelFormat kBGRA5551;
extern const NiPixelFormat kRGBA4444;
extern const NiPixelFormat kPAL8;
extern const NiPixelFormat kPALA8;
extern const NiPixelFormat kDXT1;
extern const NiPixelFormat kDXT3;
extern const NiPixelFormat kDXT5;
extern const NiPixelFormat kBUMP16;
extern const NiPixelFormat kBUMPLUMA32;

// Stores the format, bits per pixel, and renderer hint, then maps the format and color masks to a NiPixelFormat constant or marks it unknown.
// @fnv 0x00a7c9f0
// src: COMMUNITY 0x00a7c9f0
void PixelFormatReader::NiPixelFormat_ConvertOldPixelFormat(Format eFormat, unsigned char ucBitsPerPixel, unsigned int* apuiMasks)
{
    m_ucBitsPerPixel = ucBitsPerPixel;
    m_eFormat = eFormat;
    m_uiRendererHint = 0xffffffff;
    m_uiExtraData = 0;
    m_uiObjectFlags = 1;
    m_eTiling = TILE_NONE;

    switch (eFormat)
    {
    case FORMAT_RGB:
        switch (ucBitsPerPixel)
        {
        case 16:
            if (apuiMasks[0] == 0xf800 && apuiMasks[1] == 0x7e0 && apuiMasks[2] == 0x1f && apuiMasks[3] == 0)
                *(NiPixelFormat*)this = kRGB565;
            else
                m_eFormat = FORMAT_UNKNOWN;
            break;
        case 24:
            if (apuiMasks[0] == 0xff && apuiMasks[1] == 0xff00 && apuiMasks[2] == 0xff0000 && apuiMasks[3] == 0)
                *(NiPixelFormat*)this = kBGR888;
            else if (apuiMasks[0] == 0xff0000 && apuiMasks[1] == 0xff00 && apuiMasks[2] == 0xff && apuiMasks[3] == 0)
                *(NiPixelFormat*)this = kRGB888;
            else
                m_eFormat = FORMAT_UNKNOWN;
            break;
        default:
            m_eFormat = FORMAT_UNKNOWN;
            break;
        }
        break;
    case FORMAT_RGBA:
        switch (ucBitsPerPixel)
        {
        case 16:
            if (apuiMasks[0] == 0x1f && apuiMasks[1] == 0x3e0 && apuiMasks[2] == 0x7c00 && apuiMasks[3] == 0x8000)
                *(NiPixelFormat*)this = kBGRA5551;
            else if (apuiMasks[0] == 0x7c00 && apuiMasks[1] == 0x3e0 && apuiMasks[2] == 0x1f && apuiMasks[3] == 0x8000)
                *(NiPixelFormat*)this = kRGBA5551;
            else if (apuiMasks[0] == 0xf00 && apuiMasks[1] == 0xf0 && apuiMasks[2] == 0xf && apuiMasks[3] == 0xf000)
                *(NiPixelFormat*)this = kRGBA4444;
            else
                m_eFormat = FORMAT_UNKNOWN;
            break;
        case 32:
            if (apuiMasks[0] == 0xff0000 && apuiMasks[1] == 0xff00 && apuiMasks[2] == 0xff &&
                apuiMasks[3] == 0xff000000)
                *(NiPixelFormat*)this = kRGBA32;
            else
                *(NiPixelFormat*)this = kBGRA32;
            break;
        default:
            m_eFormat = FORMAT_UNKNOWN;
            break;
        }
        break;
    case FORMAT_PAL:
        switch (ucBitsPerPixel)
        {
        case 8:
            *(NiPixelFormat*)this = kPAL8;
            break;
        default:
            m_eFormat = FORMAT_UNKNOWN;
            break;
        }
        break;
    case FORMAT_PALALPHA:
        switch (ucBitsPerPixel)
        {
        case 8:
            *(NiPixelFormat*)this = kPALA8;
            break;
        default:
            m_eFormat = FORMAT_UNKNOWN;
            break;
        }
        break;
    case FORMAT_DXT1:
        *(NiPixelFormat*)this = kDXT1;
        break;
    case FORMAT_DXT3:
        *(NiPixelFormat*)this = kDXT3;
        break;
    case FORMAT_DXT5:
        *(NiPixelFormat*)this = kDXT5;
        break;
    case FORMAT_BUMP:
        *(NiPixelFormat*)this = kBUMP16;
        break;
    case FORMAT_BUMPLUMA:
        *(NiPixelFormat*)this = kBUMPLUMA32;
        break;
    default:
        m_eFormat = FORMAT_UNKNOWN;
        break;
    }
}
