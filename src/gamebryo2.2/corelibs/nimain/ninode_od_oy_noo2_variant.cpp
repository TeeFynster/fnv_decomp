
// src/gamebryo2.2/corelibs/nimain/ninode_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/nimain/ninode.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPointLight.h"
#include "../../../../include/NiPropertyState.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTStringPointerMap.h"
#include "../../../../include/NiUpdateData.h"
#include "ninode_packet_decls.h"
#pragma optimize("", off)
#pragma optimize("", on)

namespace s005468d0 {

struct Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int m_iValue;

    void BSMultiBoundNode_SetCullingMode(int iValue);
};

// @fnv 0x005468d0
// src: COMMUNITY 0x005468d0
void Owner::BSMultiBoundNode_SetCullingMode(int iValue)
{
    m_iValue = iValue;
}

}
