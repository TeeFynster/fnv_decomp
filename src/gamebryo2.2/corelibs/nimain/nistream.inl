#include "../../../../include/NiStream.h"

void __cdecl FUN_0044adf0(NiStream& stream, const unsigned int& value);

// @fnv 0x0043d050
void NiStream::SaveLinkID(const NiObject* object)
{
    unsigned int linkID = GetLinkIDFromObject(object);
    FUN_0044adf0(*this, linkID);
}

