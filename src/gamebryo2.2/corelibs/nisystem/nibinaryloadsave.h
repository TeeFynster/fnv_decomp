
#include "nibinaryloadsave_decls.h"
// @fnv 0x00a29580
void BooleanKey::LoadBinary(NiStream& stream)
{
    NiBinaryStreamLoad(*stream.m_pkIstr, &m_fTime);
    unsigned char value;
    NiBinaryStreamLoad(*stream.m_pkIstr, &value);
    m_bValue = value != 0;
}
