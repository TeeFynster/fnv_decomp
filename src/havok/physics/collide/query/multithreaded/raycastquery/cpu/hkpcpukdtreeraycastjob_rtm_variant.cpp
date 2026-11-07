#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"


// src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00e4dd90_shell
{
    void __thiscall hkKdTreeCpuBroadphaseBundleCastCollector_getHitFractions(float* output);
};
struct FUN_00e4dde0
{
    virtual void Vfn0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    FUN_00e4dde0();
};
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct FUN_00e4e3c0
{
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5c;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6c;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7c;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8c;

    FUN_00e4e3c0();

// @fnv 0x00e4e3c0
    virtual ~FUN_00e4e3c0()
    {}

    static void operator delete(void* apMemory)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        reinterpret_cast<hkMemoryAllocator*>(pAllocator)->blockFree(apMemory, sizeof(FUN_00e4e3c0));
    }
};
FUN_00e4e3c0::FUN_00e4e3c0()
{
    m_i04 = 0;
}

// Exe 0x00e2acf0 FUN_00e2acf0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

struct Sub60
{
    LocalM128 v0;
    float f10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;

    Sub60()
    {
        f10 = 1.0f;
        unk14 = -1;
        unk40 = 0;
        unk20 = -1;
        unk50 = 0;
    }

    Sub60& operator=(const Sub60& o)
    {
        v0 = o.v0;
        f10 = o.f10;
        unk14 = o.unk14;
        unk18 = o.unk18;
        unk1C = o.unk1C;
        unk20 = o.unk20;
        unk24 = o.unk24;
        unk28 = o.unk28;
        unk2C = o.unk2C;
        unk30 = o.unk30;
        unk34 = o.unk34;
        unk38 = o.unk38;
        unk3C = o.unk3C;
        unk40 = o.unk40;
        unk50 = o.unk50;
        return *this;
    }
};

struct Sub30
{
    LocalM128 v0;
    LocalM128 v1;
    char c20;
    int i24;

    Sub30()
    {
        c20 = 0;
        i24 = 0;
    }

    Sub30& operator=(const Sub30& o)
    {
        v0 = o.v0;
        v1 = o.v1;
        c20 = o.c20;
        i24 = o.i24;
        return *this;
    }
};

struct InputStruct
{
    Sub30 items30[4];
    int count;
    char cC4;
    Sub60* ptrs[4];
    int unkD8;
    int unkDC;
    int saved[4];
};

struct LocalInput
{
    Sub30 items30[4];
    char flag;
    Sub60* ptr;
    int unkC8;
    int unkCC;
    int saved[4];
};

struct FloatMatrix3
{
    LocalM128 col0;
    LocalM128 col1;
    LocalM128 col2;
};

void __cdecl Object_ProcessAndReturnValue_00e2ab00(InputStruct* input, FloatMatrix3* m1, FloatMatrix3* m2);
void __cdecl hkKdTreeUtils_castRayBundleIterative(unsigned char* out, void* a1, FloatMatrix3* m1, FloatMatrix3* m2, FUN_00e4dde0* obj,
                          int flag);
extern int DAT_011b3830[];

// @fnv 0x00e2acf0
// src: GUESS 0x00e2acf0 (confidence: low)
void hkKdTreeUtils_castRayBundleIterative_ProcessEntries_00e2acf0(void* a1, InputStruct* a2, void* a3, float* a4)
{
    if (!a1)
        return;

    const int count = a2->count;
    Sub60 items60[4];
    for (int j = 0; count > j; ++j)
        items60[j] = *a2->ptrs[j];

    LocalInput local;
    local.flag = a2->cC4;
    local.ptr = items60;
    for (int j = 0; j < a2->count; j++)
    {
        local.items30[j] = a2->items30[j];
        local.ptr[j].f10 = a4[j];
        local.saved[j] = a2->saved[j];
    }

    FUN_00e4dde0 obj;
    obj.unk04 = (int)a3;
    obj.unk08 = (int)a2;
    obj.unk0C = (int)&local;
    obj.unk70 = a2->items30[0].i24;
    obj.unk80 = a2->saved[0];
    obj.unk84 = a2->saved[1];
    obj.unk88 = a2->saved[2];
    obj.unk8C = a2->saved[3];

    FloatMatrix3 m1;
    FloatMatrix3 m2;
    Object_ProcessAndReturnValue_00e2ab00(a2, &m1, &m2);

    unsigned char result;
    hkKdTreeUtils_castRayBundleIterative(&result, a1, &m1, &m2, &obj, DAT_011b3830[a2->count]);

    for (int k = 0; k < a2->count; k++)
    {
        *a2->ptrs[k] = items60[k];
        a2->saved[k] = local.saved[k];
    }

    ((FUN_00e4dd90_shell*)&obj)->hkKdTreeCpuBroadphaseBundleCastCollector_getHitFractions(a4);
}
