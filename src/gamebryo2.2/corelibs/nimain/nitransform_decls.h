// gamebryo2.2/corelibs/nimain/nitransform_decls.h: declares NiColor, NiBinaryStream, NiStream, NiTransform
#ifndef NITRANSFORM_DECLS_H
#define NITRANSFORM_DECLS_H
class NiStream;
#include "../../../../include/NiMatrix3.h"
class NiColor
{
  public:
    float r, g, b;
    void LoadBinary(NiStream&);
};
struct NiBinaryStream
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* write)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data)
    {
        unsigned int size = 4;
        position += read(this, data, 4, &size, 1);
    }
};
class NiStream
{
  public:
    char pad[0x24c];
    NiBinaryStream* input;
};
class NiTransform
{
  public:
    NiMatrix3 m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
    void ResetToIdentity();
    void LoadBinary(NiStream&);
};
#endif