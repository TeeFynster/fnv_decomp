
// src/havok/physics/dynamics/motion/rigid/hkpfixedrigidmotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpfixedrigidmotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpFixedRigidMotion.h"

extern int DAT_010c6cdc;
struct FUN_00d1e160_t
{
    int* vtbl;
    unsigned char m_auiShapeKeys[7];
    unsigned char m_type;
    void FUN_00d1dfa0(int a, int b);
    void* InitFixedRigidMotion(int a, int b);
};
// Calls FUN_00d1dfa0, sets vtbl to &DAT_010c6cdc, writes 5 to byte offset 8, and returns this.
// @fnv 0x00d1e160
void* FUN_00d1e160_t::InitFixedRigidMotion(int a, int b)
{
    FUN_00d1dfa0(a, b);
    vtbl = &DAT_010c6cdc;
    ((unsigned char*)this)[8] = 5;
    return this;
}

// @fnv 0x00d1e130
// src: COMMUNITY 0x00d1e130
void __stdcall nullsub_51(int, int)
{}

// @fnv 0x00d1e140
// src: COMMUNITY 0x00d1e140
void __stdcall nullsub_49(void* a)
{}

// 0x00d1e150  /MT /O2 /GS /EHsc /Gy   target: C2 04 00  (ret 4, empty thiscall with one stack arg)
struct C00d1e150
{
    int unk00;
    void nullsub_50(int arg);
};

// @fnv 0x00d1e150
// src: COMMUNITY 0x00d1e150
void C00d1e150::nullsub_50(int arg)
{}

#include <xmmintrin.h>
struct FUN_00c86660_Obj
{
    void hkMotionState_Copy(int* a);
};

struct FUN_00d1e190_Obj
{
    void hkpFixedRigidMotion_getPositionAndVelocities(int* motion);
};

// Calls FUN_00c86660 on motion's sub-object at offset 0x10 with this+0x10, then zeroes two 16-byte vectors at float offsets 0x34 and 0x38 of motion.
// @fnv 0x00d1e190
// src: HAVOK_SRC 0x00d1e190
void FUN_00d1e190_Obj::hkpFixedRigidMotion_getPositionAndVelocities(int* motion)
{
    reinterpret_cast<FUN_00c86660_Obj*>(reinterpret_cast<char*>(motion) + 0x10)
        ->hkMotionState_Copy(reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10));

    __m128 zero = _mm_setzero_ps();
    _mm_store_ps(reinterpret_cast<float*>(motion) + 0x34, zero);
    _mm_store_ps(reinterpret_cast<float*>(motion) + 0x38, zero);
}
