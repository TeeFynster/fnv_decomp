#include "../../../../include/NiStream.h"

void __cdecl NiStreamSaveBinary_unsigned_int(NiStream& stream, const unsigned int& value);

// @fnv 0x0043d050
void NiStream::SaveLinkID(const NiObject* object)
{
    unsigned int linkID = GetLinkIDFromObject(object);
    NiStreamSaveBinary_unsigned_int(*this, linkID);
}

