// src/gamebryo2.2/corelibs/nimain/niddsreader_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00a8c6e0: the skeleton of src/gamebryo2.2/corelibs/nimain/niddsreader.cpp
// with declarations corrected to what the original code does (niddsreader_decls.h: NiPixelFormat += bool operator!=(const NiPixelFormat& other) const;). Move the function to its real unit once
// that unit declares it this way.

#include "../../../../include/NiBMPReader.h"
#include "../../../../include/NiImageReader.h"
#include "../../../../include/NiPixelFormat.h"

struct ReadCtx
{
    int unk00;
    int m04;
    int(__cdecl* m08)(ReadCtx* ctx, void* dst, unsigned int n, int* flag, int one);
};

struct ImgObj
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
    int unk44;
    int unk48;
    int unk4c;
    unsigned int m50;
    unsigned int* m54;
    unsigned int* m58;
    unsigned int* m5c;
    unsigned int m60;
};

class FUN_00a779b0_info
{
  public:
    unsigned int mask0, mask1, mask2, mask3;
    unsigned char bits0, bits1, bits2, bits3, unk14, unk15, unk16, unk17;
    void build(const NiPixelFormat* fmt);
};

// @fnv 0x00a8c6e0
// src: GAMEBRYO_LIB 0x00a8c6e0
void __cdecl NiDDSReader_Read24Bit(ReadCtx* ctx, ImgObj* self, NiPixelFormat fmtA, NiPixelFormat fmtB, unsigned int idx,
                          unsigned int scale)
{
    unsigned char* base = (unsigned char*)(self->m5c[self->m60] * scale + self->m50 + self->m5c[idx]);
    {
        unsigned int n = self->m5c[idx + 1] - self->m5c[idx];
        volatile int flag = 1;
        ctx->m04 += ctx->m08(ctx, base, n, (int*)&flag, 1);
    }
    FUN_00a779b0_info info;
    info.build(&fmtA);
    unsigned int w = self->m54[idx];
    unsigned int h = self->m58[idx];
    if (fmtA != fmtB && info.mask0 == 0xff0000u)
    {
        unsigned char* src = base;
        for (unsigned int y = 0; y < h; y++)
        {
            for (unsigned int x = 0; x < w; x++)
            {
                unsigned char b2 = src[2];
                unsigned char b1 = src[1];
                unsigned char b0 = src[0];
                *base++ = b2;
                *base++ = b1;
                *base++ = b0;
                src += 3;
            }
        }
    }
}
