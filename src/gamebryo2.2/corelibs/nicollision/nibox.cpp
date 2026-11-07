
// src/gamebryo2.2/corelibs/nicollision/nibox.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nibox.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiColor.h"
#include "../../../../include/NiStream.h"

struct StreamBuffer;
typedef int(__cdecl* StreamWrite)(StreamBuffer*, const void*, unsigned int, unsigned int*, int);
struct StreamBuffer
{
    int unk00;
    unsigned int position;
    int unk08;
    StreamWrite write;
};
struct ColorContainer
{
    NiColor firstColor;
    NiColor secondColor;
    NiColor thirdColor;
    NiColor fourthColor;
    struct
    {
        float x;
        float y;
        float z;
    } extraVector;
    void NiBox_SaveBinary(NiStream* stream);
};
// Saves the four colors and the extra vector to the stream, writing the vector as 12 bytes through the buffer's write function.
// @fnv 0x00eae630
// src: XBOX_PDB 0x00eae630
void ColorContainer::NiBox_SaveBinary(NiStream* stream)
{
    firstColor.SaveBinary(*stream);
    NiColor* color = &secondColor;
    int remaining = 3;
    do
    {
        color->SaveBinary(*stream);
        ++color;
        --remaining;
    } while (remaining != 0);
    StreamBuffer* writer = reinterpret_cast<StreamBuffer*&>(stream->m_pkOstr);
    {
        int stream = 4;
        writer->position += writer->write(writer, &extraVector, 12, (unsigned int*)&stream, 1);
    }
}

struct Buf
{
    int unk00;
    unsigned int position;
    StreamWrite write;
};

struct FUN_00eae5d0_cls : ColorContainer
{
    void WriteToStream(NiStream* stream);
};

// @fnv 0x00eae5d0
void FUN_00eae5d0_cls::WriteToStream(NiStream* stream)
{
    firstColor.LoadBinary(*stream);
    NiColor* p = &secondColor;
    int n = 3;
    do
    {
        p->LoadBinary(*stream);
        p++;
    } while (--n != 0);
    Buf* buffer = reinterpret_cast<Buf*&>(stream->m_pkIstr);
    {
        // `count` is address taken and the stream argument is dead by now, so
        // MSVC puts it in the incoming argument slot - exactly like the original
        // (lea eax,[esp+0x18] / mov [esp+0x28],4).
        unsigned int count = 4;
        int written = buffer->write((StreamBuffer*)buffer, &extraVector, 0xc, &count, 1);
        buffer->position += written;
    }
}
