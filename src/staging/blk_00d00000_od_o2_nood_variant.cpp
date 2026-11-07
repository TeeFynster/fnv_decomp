
// src/staging/blk_00d00000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00d00000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d00000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct Sub1C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct BigState
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    __m128 unk10;
    __m128 unk20;
    __m128 unk30;
    __m128 unk40;
    float unk50;
    float unk54;
    float unk58;
    float unk5C;
    float unk60;
    Sub1C unk64;
    Sub1C unk80;
    Sub1C unk9C;
    Sub1C unkB8;
    Sub1C unkD4;
    Sub1C unkF0;
    float unk10C;
    float unk110;
    int unk114;
    int unk118;
    float unk11C;
    float unk120;
    char unk124;
    char unk125;
    char unk126;
    char unk127;
    float unk128;

    BigState& UpdateState_00d105b0(const BigState& o);
};

// @fnv 0x00d105b0
// src: GUESS 0x00d105b0 (confidence: low)
BigState& BigState::UpdateState_00d105b0(const BigState& o)
{
    unk00 = o.unk00;
    unk04 = o.unk04;
    unk08 = o.unk08;
    unk0C = o.unk0C;
    unk10 = o.unk10;
    unk20 = o.unk20;
    unk30 = o.unk30;
    unk40 = o.unk40;
    unk50 = o.unk50;
    unk54 = o.unk54;
    unk58 = o.unk58;
    unk5C = o.unk5C;
    unk60 = o.unk60;
    unk64 = o.unk64;
    unk80 = o.unk80;
    unk9C = o.unk9C;
    unkB8 = o.unkB8;
    unkD4 = o.unkD4;
    unkF0 = o.unkF0;
    unk10C = o.unk10C;
    unk110 = o.unk110;
    unk114 = o.unk114;
    unk118 = o.unk118;
    unk11C = o.unk11C;
    unk120 = o.unk120;
    unk124 = o.unk124;
    unk125 = o.unk125;
    unk126 = o.unk126;
    unk127 = o.unk127;
    unk128 = o.unk128;
    return *this;
}

struct W
{
    int x;
};
struct __declspec(align(16)) FUN_00c9ce00_cls
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
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    void FUN_00c9ce00(int);
};
// @fnv 0x00d1f1a0
// src: HAVOK_LIB 0x00d1f1a0
int getVtablehkpEntity()
{
    FUN_00c9ce00_cls holder;
    holder.FUN_00c9ce00(W().x);
    return *(int*)&holder;
}
