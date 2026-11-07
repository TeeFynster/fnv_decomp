
// src/gamebryo2.2/corelibs/nimain/niextradata_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niextradata.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/NiAccumulator.h"
#include "../../../../include/NiBinaryExtraData.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiStream.h"

#include "niextradata_packet.h"

extern "C" void* __fastcall NiRTTI_UpdateState_00c6b910(void*);
extern void* DAT_0103046c;

struct FUN_0066b640
{
    void* m_vft;
    FUN_0066b640();
};

// @fnv 0x0066b640
FUN_0066b640::FUN_0066b640()
{
    NiRTTI_UpdateState_00c6b910(this);
    m_vft = &DAT_0103046c;
}

class FUN_00539f50 : public NiExtraData
{
  public:
    void Init(int iA, int iB);

    FUN_00539f50(int iA, int iB);
    virtual ~FUN_00539f50();
};

// @fnv 0x00539f50
FUN_00539f50::FUN_00539f50(int iA, int iB)
{
    Init(iA, iB);
}
