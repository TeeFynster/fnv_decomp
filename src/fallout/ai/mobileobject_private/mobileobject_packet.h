// fallout/ai/mobileobject_private/mobileobject_packet.h: declares ExtraDismemberedLimbs, bhkCharacterController, MobileObjectRemovalState

#include "../../../../include/ExtraDataList.h"
#define _ULARGE_INTEGER FNV64_ULARGE_INTEGER_Unused
#include "../../../../include/ExtraDismemberedLimbs.h"
#include "../../../../include/bhkCharacterController.h"
#undef _ULARGE_INTEGER
bhkCharacterController* CopyCharacterControllerVector(bhkCharacterController*, const NiPoint3&);

#pragma pack(push, 1)
struct MobileObjectRemovalState
{
    unsigned char padding0, padding1, padding2;
    bool removed;
    bhkCharacterController* controller;
};
#pragma pack(pop)
