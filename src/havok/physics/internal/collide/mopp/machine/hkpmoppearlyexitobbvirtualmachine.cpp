
// src/havok/physics/internal/collide/mopp/machine/hkpmoppearlyexitobbvirtualmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/machine/hkpmoppearlyexitobbvirtualmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkBool.h"
extern char DAT_0126efba;
void ValidateHavokKeyCode(char* pKey);
struct S_00e647e0_Shape;
struct S_00e647e0_Input { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; S_00e647e0_Shape* m_pCollisionShape; };
struct S_00e647e0_Local { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; };
struct S_00e647e0 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    hkBool m_bHasHit; char unk41; char unk42; char unk43;
    S_00e647e0_Input* m_pRayCastInput;
    void ComputeValues_00e645b0(const void* a, const void* b, const void* c, S_00e647e0_Local* out);
    void queryOBBOnTree(S_00e647e0_Local* l, S_00e647e0_Shape* shape);
    hkBool SetupAndProcessShape(S_00e647e0_Input* input, const void* b, const void* c, const void* d);
};
// @fnv 0x00e647e0
hkBool S_00e647e0::SetupAndProcessShape(S_00e647e0_Input* input, const void* b, const void* c, const void* d) {
    if (!DAT_0126efba) {
        ValidateHavokKeyCode(&DAT_0126efba);
        if (!DAT_0126efba) return false;
    }
    m_pRayCastInput = input;
    S_00e647e0_Shape* shape = input->m_pCollisionShape;
    __declspec(align(16)) S_00e647e0_Local localData;
    ComputeValues_00e645b0(c, b, d, &localData);
    localData.unk44 = 0;
    m_bHasHit = false;
    queryOBBOnTree(&localData, shape);
    return m_bHasHit;
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
