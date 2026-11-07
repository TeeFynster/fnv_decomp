
// src/gamebryo2.2/corelibs/nimain/nitexturecodec.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nitexturecodec.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiPixelFormat;
struct PixelData
{
    char unk00[0x50];
    unsigned char* base;
    unsigned int* widths;
    unsigned int* heights;
    unsigned int* offsets;
    unsigned int mips;
    int unk64;
    int unk68;
    unsigned int faces;
    int unk70;
    static void* operator new(unsigned int n);
    PixelData(unsigned int w, unsigned int h, const NiPixelFormat& f, unsigned int m, unsigned int n) throw();
};
extern NiPixelFormat DAT_011aa2a0;

struct SrcData
{
    char unk00[0x0c];
    int format;
    char unk10[0x40];
    unsigned char* base;
    unsigned int* widths;
    unsigned int* heights;
    unsigned int* offsets;
    unsigned int mips;
    int unk64;
    int unk68;
    unsigned int faces;
    unsigned int GetWidth(unsigned int mip = 0) const
    {
        return widths[mip];
    }
    unsigned int GetHeight(unsigned int mip = 0) const
    {
        return heights[mip];
    }
    unsigned int GetNumMipmapLevels() const
    {
        return mips;
    }
    unsigned int GetFaceTotal() const
    {
        return faces;
    }
};

struct Row
{
    unsigned int a, b, c, d;
};

struct Conv
{
    typedef void (Conv::*Fn)(unsigned char*);
    Fn decodeA;
    Fn decodeB;
    unsigned char* cur;
    unsigned int stride;

    void DecodeAlphaBlock(unsigned char*);
    void DecodeBlockColors(unsigned char*);
    void DecodeToOutput(unsigned char*);
    void DecodePaletteBlock(unsigned char*);
    int CopyGeneratedRows(unsigned char* p, unsigned int n, unsigned int m);
    PixelData* ConvertTexture(SrcData* src);
};

// Selects decode functions by source format, allocates a PixelData and converts each face/mipmap block into it, returning the result or null.
// @fnv 0x00a8be70
PixelData* Conv::ConvertTexture(SrcData* src)
{
    switch (src->format)
    {
    case 4:
        decodeA = 0;
        decodeB = &Conv::DecodePaletteBlock;
        break;
    case 5:
        decodeA = &Conv::DecodeToOutput;
        decodeB = &Conv::DecodeBlockColors;
        break;
    case 6:
        decodeA = &Conv::DecodeAlphaBlock;
        decodeB = &Conv::DecodeBlockColors;
        break;
    default:
        return 0;
    }

    PixelData* out =
        new PixelData(src->GetWidth(), src->GetHeight(), DAT_011aa2a0, src->GetNumMipmapLevels(), src->GetFaceTotal());
    unsigned int mips = src->GetNumMipmapLevels();
    unsigned int faces = src->GetFaceTotal();
    {
        unsigned int face = 0;
        while (face < faces)
        {
            for (unsigned int mip = 0; mips > mip; mip++)
            {
                cur = src->base + src->offsets[mip] + src->offsets[src->mips] * face;
                unsigned char* dst = out->base + out->offsets[mip] + out->offsets[out->mips] * face;
                unsigned int uiWidth = src->widths[mip];
                unsigned int h = src->heights[mip];
                unsigned int w = uiWidth >> 2;
                unsigned int uiBlocksH = h >> 2;
                unsigned int uiRemW = uiWidth & 3;
                unsigned int uiRemH = h & 3;
                stride = uiWidth * 4;
                for (unsigned int uiBlockY = 0; uiBlockY < uiBlocksH; uiBlockY++)
                {
                    for (unsigned int uiBlockX = 0; uiBlockX < w; uiBlockX++)
                    {
                        Row* d = (Row*)dst;
                        unsigned char rowBuf[64];
                        Row* pRowSrc = (Row*)rowBuf;
                        if (decodeA)
                            (this->*decodeA)(rowBuf + 3);
                        (this->*decodeB)(rowBuf);
                        for (int iRow = 4; iRow != 0; iRow--)
                        {
                            *d = *pRowSrc;
                            d = (Row*)((unsigned char*)d + stride);
                            pRowSrc++;
                        }
                        dst += 16;
                    }
                    if (uiRemW)
                    {
                        CopyGeneratedRows(dst, uiRemW, 4);
                        dst += uiRemW * 4;
                    }
                    dst += uiWidth * 3 * 4;
                }
                if (uiRemH)
                {
                    for (unsigned int uiBlockX = 0; uiBlockX < w; uiBlockX++)
                    {
                        CopyGeneratedRows(dst, 4, uiRemH);
                        dst += 16;
                    }
                    if (uiRemW)
                        CopyGeneratedRows(dst, uiRemW, uiRemH);
                }
            }
            face++;
        }
    }
    return out;
}
