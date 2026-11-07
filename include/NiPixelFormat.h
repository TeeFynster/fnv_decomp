#pragma once

class NiStream;

class NiPixelFormat
{
public:
    enum Format  // values: Xbox PDB NiPixelFormat::Format
    {
        FORMAT_RGB = 0,
        FORMAT_RGBA = 1,
        FORMAT_PAL = 2,
        FORMAT_PALALPHA = 3,
        FORMAT_DXT1 = 4,
        FORMAT_DXT3 = 5,
        FORMAT_DXT5 = 6,
        FORMAT_RGB24NONINTERLEAVED = 7,
        FORMAT_BUMP = 8,
        FORMAT_BUMPLUMA = 9,
        FORMAT_RENDERERSPECIFIC = 10,
        FORMAT_ONE_CHANNEL = 11,
        FORMAT_TWO_CHANNEL = 12,
        FORMAT_THREE_CHANNEL = 13,
        FORMAT_FOUR_CHANNEL = 14,
        FORMAT_DEPTH_STENCIL = 15,
        FORMAT_UNKNOWN = 16,
        FORMAT_MAX = 17
    };

    enum Component
    {
        COMP_RED = 0,
        COMP_GREEN = 1,
        COMP_BLUE = 2,
        COMP_ALPHA = 3,
        COMP_COMPRESSED = 4,
        COMP_OFFSET_U = 5,
        COMP_OFFSET_V = 6,
        COMP_OFFSET_W = 7,
        COMP_OFFSET_Q = 8,
        COMP_LUMA = 9,
        COMP_HEIGHT = 10,
        COMP_VECTOR_X = 11,
        COMP_VECTOR_Y = 12,
        COMP_VECTOR_Z = 13,
        COMP_PADDING = 14,
        COMP_INTENSITY = 15,
        COMP_INDEX = 16,
        COMP_DEPTH = 17,
        COMP_STENCIL = 18,
        COMP_EMPTY = 19,
        COMP_MAX = 20,
        NUM_COMPS = 4
    };

    enum TextureTileMode
    {
        TILE_NONE = 0,
        TILE_CONSOLE = 1,
        TILE_MAX = 2
    };

    enum Representation
    {
        REP_FIXED = 0,
        REP_HALF = 1,
        REP_FLOAT = 2,
        REP_INDEX = 3,
        REP_COMPRESSED = 4,
        REP_UNKNOWN = 5,
        REP_MAX = 6,
        NORM_INT = 0,
        HALF = 1,
        FLOAT = 2,
        INDEX = 3,
        COMPRESSED = 4,
        UNKNOWN = 5,
        INT = 6,
        COUNT = 7
    };

    struct NiComponentSpec
    {
        union
        {
            Component m_eComponent;
            int kind;
        };
        union
        {
            Representation m_eRepresentation;
            int representation;
        };
        union
        {
            unsigned char m_ucBits;
            unsigned char m_ucBitsPerComponent;
            unsigned char m_ucBPC;
            unsigned char bits;
        };
        union
        {
            bool m_bSigned;
            bool sign;
        };
        union
        {
            unsigned short unk0a;
            unsigned short padding;
        };
    };

    NiPixelFormat() throw();
    bool operator==(const NiPixelFormat& other) const throw();
    bool operator!=(const NiPixelFormat& other) const;

    void SetField(unsigned char, unsigned char, unsigned char);
    unsigned char GetField(unsigned char, unsigned char);
    void SetBit(bool, unsigned char);
    bool GetBit(unsigned char);
    static NiPixelFormat BuildPixelFormat(unsigned char, unsigned int, unsigned int,
                                   unsigned int, unsigned int);
    Format GetFormat();
    Format GetFormat() const throw() { return m_eFormat; }
    unsigned char GetBitsPerPixel();
    unsigned char GetBitsPerPixel() const throw() { return m_ucBitsPerPixel; }
    unsigned int GetRendererHint();
    unsigned int GetExtraData();
    int GetTiling();
    bool GetLittleEndian();
    bool GetLittleEndian() const throw() { return (m_uiObjectFlags & 1) != 0; }
    void SetFormat(int);
    void SetFormat(Format);
    void SetBitsPerPixel(unsigned char);
    void SetRendererHint(unsigned int);
    void SetExtraData(unsigned int);
    void SetTiling(int);
    void SetLittleEndian(bool);
    bool GetComponent(unsigned int, int*, int*, unsigned char*, bool*);
    bool GetComponent(unsigned int, Component&, Representation&, unsigned char&, bool&);
    void SetComponent(unsigned int, int, int, unsigned char, bool);
    void SetComponent(unsigned int, Component, Representation, unsigned char, bool);
    unsigned int GetNumComponents();
    bool GetPalettized();
    bool GetPaletteHasAlpha();
    bool GetCompressed();
    bool IsCompressed() const throw()
    {
        return m_eFormat >= FORMAT_DXT1 && m_eFormat <= FORMAT_DXT5;
    }
    bool IsField4InRange() const;
    unsigned int GetMask(int);
    unsigned int GetMask(int) const;
    unsigned int __thiscall GetMask(Component) const;
    unsigned char GetPixelBitData(int);
    unsigned char __thiscall GetPixelBitData(Component) const;
    unsigned char GetShift(int);
    unsigned char GetShift(Component);
    unsigned char QBitsPerPixel();
    void LoadBinary(NiStream*);
    void LoadBinary(NiStream&);
    void SaveBinary(NiStream*);
    void SaveBinary(NiStream&);
    void InitPixelFormat(int, unsigned char, int, bool, unsigned int,
                         int, int, unsigned char, bool,
                         int, int, unsigned char, bool,
                         int, int, unsigned char, bool,
                         int, int, unsigned char, bool);
    void SetComponentFormat(int, unsigned char, unsigned int*);
    void SetComponentFormat(Format, unsigned char, unsigned int*);
    void NiPixelFormat_ConvertOldPixelFormat(Format, unsigned char, unsigned int*);
    static unsigned int CalcMaskSize(unsigned int);

    union
    {
        struct
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
            unsigned int unk30;
            unsigned int unk34;
            unsigned int unk38;
            unsigned int unk3c;
            unsigned int unk40;
        };
        struct
        {
            unsigned char m_uiObjectFlags;
            unsigned char m_ucBitsPerPixel;
            union
            {
                unsigned short unk02;
                unsigned short m_ucUnknownByte;
            };
            Format m_eFormat;
            TextureTileMode m_eTiling;
            unsigned int m_uiRendererHint;
            unsigned int m_uiExtraData;
            NiComponentSpec m_akComponents[NUM_COMPS];
        };
        struct
        {
            unsigned char flags;
            unsigned char bits;
            unsigned short pad;
            unsigned int data[16];
        };
    };
};
