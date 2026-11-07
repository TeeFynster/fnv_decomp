
// src/havok/physics/collide/shape/convex/cylinder/hkpcylindershape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/convex/cylinder/hkpcylindershape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/convex/cylinder/hkpcylindershape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/cylinder/hkpcylindershape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkpCylinderShape.h"
int __cdecl hkpCylinderShape_ReturnConstant_0x12();
extern char DAT_01268940[];
void __cdecl hkReferencedObject_calcContentStatistics(void* item, const char* type);
void __cdecl hkpCylinderShape_calcContentStatistics(void* item, const char*);
struct C00d573e0 {
    char  pad00[0x10];
    volatile float f10;
    float f14;
    char  pad18[0x2c - 0x18];
    float f2c;
    char  pad30[0x3c - 0x30];
    float f3c;
    void SetValue(float v);
};
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
extern char DAT_010305a8;
extern char DAT_010d0f1c;
extern float DAT_011b5be8;
// src: HAVOK_LIB 0x00d571d0
static __declspec(noinline) float minValueRoundedUpTo1()
{
    return 0.0f;
}
struct S00d57b20_Obj {
    void* unk00;
    int unk04;
    int unk08;
    int unk0C;

    S00d57b20_Obj* __thiscall hkpCylinderShape_hkpCylinderShape_00d57b20(int condition);
};

#include <xmmintrin.h>
namespace fnv_00d57aa0 {
extern int DAT_010d0f1c;
extern float DAT_011b5be8;
extern float DAT_01030ff0;

// src: HAVOK_LIB 0x00d571d0
static __declspec(noinline) float minValueRoundedUpTo1()
{
    return DAT_01030ff0;
}

static __declspec(noinline) void __stdcall SetValue(float value)
{
    DAT_011b5be8 = value;
}

static __declspec(noinline) void InitPerpendiculars()
{
    DAT_011b5be8 = DAT_01030ff0;
}

struct S00d57aa0_Obj {
    void* vft;
    short unk04;
    short unk06;
    int unk08;
    int unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;

    void* __thiscall hkpCylinderShape_hkpCylinderShape(
        const float* a,
        const float* b,
        float c,
        float d
    );
};

// @fnv 0x00d57aa0
// src: XBOX_PDB 0x00d57aa0
void* __thiscall S00d57aa0_Obj::hkpCylinderShape_hkpCylinderShape(
    const float* a,
    const float* b,
    float c,
    float d
) {
    unk10 = d;
    unk06 = 1;
    unk08 = 0;
    unk0c = 2;
    vft = &DAT_010d0f1c;

    if (DAT_011b5be8 < 0.0f) {
        DAT_011b5be8 = 1.0f - minValueRoundedUpTo1();
    }

    _mm_store_ps(&unk20, _mm_load_ps(a));
    _mm_store_ps(&unk30, _mm_load_ps(b));

    SetValue(c);
    InitPerpendiculars();

    unk18 = DAT_01030ff0;
    return this;
}
}  // namespace fnv_00d57aa0
