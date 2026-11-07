
// src/gamebryo2.2/corelibs/nimain/nitexturetransform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nitexturetransform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiPoint2.h"

inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int totalBytes,
                                               unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int bytesRead = m_pfnRead(this, buffer, totalBytes, componentSizes, componentCount);
    m_uiAbsoluteCurrentPos += bytesRead;
    return bytesRead;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int totalBytes,
                                                unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int bytesWritten = m_pfnWrite(this, buffer, totalBytes, componentSizes, componentCount);
    m_uiAbsoluteCurrentPos += bytesWritten;
    return bytesWritten;
}

template <class T> inline unsigned int NiBinaryStream::BinaryRead(T* value, unsigned int count)
{
    unsigned int size = sizeof(T);
    return BinaryRead(value, sizeof(T) * count, &size, 1);
}

template <class T> inline unsigned int WriteBinaryValue(NiBinaryStream* stream, const T* value)
{
    unsigned int size = sizeof(T);
    return stream->BinaryWrite(value, sizeof(T), &size, 1);
}

template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    stream.m_pkIstr->BinaryRead(&value);
}

struct FUN_00a88f00_Class
{
    NiPoint2 point00;
    unsigned int unk08;
    NiPoint2 point0c;
    NiPoint2 point14;
    bool loaded;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    unsigned int unk44;
    void NiTextureTransform_LoadBinary(NiStream& stream);
};

// Reads point00, point0c, unk08, a value into unk44 and point14 from the stream, then sets loaded to true.
// @fnv 0x00a88f00
// src: COMMUNITY 0x00a88f00
void FUN_00a88f00_Class::NiTextureTransform_LoadBinary(NiStream& stream)
{
    point00.LoadBinary(&stream);
    point0c.LoadBinary(&stream);
    ReadBinaryValue(stream, unk08);
    unsigned int value;
    ReadBinaryValue(stream, value);
    unk44 = value;
    point14.LoadBinary(&stream);
    loaded = true;
}

class FUN_00a88f80_cls
{
  public:
    NiPoint2 point00;
    unsigned int unk08;
    NiPoint2 point0c;
    NiPoint2 point14;
    bool loaded;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    unsigned int unk44;
    void NiTextureTransform_SaveBinary(NiStream& stream);
};

// Writes point00, point0c, unk08, unk44 and point14 to the stream in that order.
// @fnv 0x00a88f80
// src: COMMUNITY 0x00a88f80
void FUN_00a88f80_cls::NiTextureTransform_SaveBinary(NiStream& stream)
{
    point00.SaveBinary(&stream);
    point0c.SaveBinary(&stream);
    WriteBinaryValue(stream.m_pkOstr, &unk08);
    WriteBinaryValue(stream.m_pkOstr, &unk44);
    point14.SaveBinary(&stream);
}
