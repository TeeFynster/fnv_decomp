// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/Pair.h"

struct Out
{
    int res;
    int val;
};
struct Updater
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int update(int x, int y);
};
static void extractChildShapes_00da4a50(Updater* self, int flag, Pair* dest, Pair* src, Updater* other, int y, Out* out2, Out* out1);
void S00da4a50_Wrap(Updater* self, int flag, Pair* dest, Pair* src, Updater* other, int y, Out* out2, Out* out1);

#include <xmmintrin.h>
struct S00da4920_Sub
{
    void hkTransform_setInverse(void* arg);
};

struct S00da4920_Blob
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    __m128 m_v70;
};

extern char DAT_010c4c00;

// @fnv 0x00da4920
// src: XBOX_PDB 0x00da4920
static __declspec(noinline) void hkAgent1nMachine_flipInput(S00da4920_Blob* src, S00da4920_Blob* dst)
{
    dst->unk00 = src->unk04;
    dst->unk04 = src->unk00;
    dst->unk0C = src->unk0C;
    dst->unk10 = src->unk10;
    dst->m_v70 = _mm_xor_ps(src->m_v70, *(const __m128*)&DAT_010c4c00);
    ((S00da4920_Sub*)((char*)dst + 0x20))->hkTransform_setInverse((char*)src + 0x20);
}

void S00da4920_entry(S00da4920_Blob* src, S00da4920_Blob* dst)
{
    hkAgent1nMachine_flipInput(src, dst);
}
