
// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Object
{
};
void __cdecl Hkpinertiatensorcomputer_CopyAndScalePropertyBlock(float* source, float value, Object* destination);
void __cdecl hkpInertiaTensorComputer_setAndScaleToDensity(float* source, float scale, Object* destination);
struct Receiver
{
    void SetScalarAndRescaleVector(float value);
};
struct State
{
    int first;
    int count;
    int context;
};
void hkpInertiaTensorComputer_computeConvexHullMassProperties(void* state, float zero, void* receiver);
int __cdecl ApplyLimitToReceiver(int owner, int context, int count, float limit, Receiver* receiver, float value);
struct FUN_00cebe80_Struct
{
    float unk00;
    float unk04;
    float unk08;
};
void __cdecl hkpInertiaTensorComputer_shiftInertiaToCom(FUN_00cebe80_Struct* pThis, float fParam2, float* pOut);
void __cdecl AddInertiaTensor(float* param_1, float param_2, float* param_3);
struct FUN_00cec6b0_cls
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
    float m_64;
    float m_68;
    float m_6C;
    float m_70;
    float m_74;
    float m_78;
    float m_7C;
    float m_80;
    float m_84;
    float m_88;

    void InternalInertiaTensorComputer_computeInertialTensorInternal(float a1, float b, float* p, float* M);
};
struct CECCD0Value
{
    float m_uiFilterValue;

    void set(float v);
    void ScaleValue(float scale);
};
struct S_00ced230_T
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
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
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    float unk64;
    float unk68;
    float unk6c;
    float unk70;
    float unk74;
    float unk78;
};
static inline float S_MaxGT(float x, float y)
{
    return (x > y) ? x : y;
}
static inline float S_MaxLT(float x, float y)
{
    return (x < y) ? y : x;
}
void __cdecl hkpInertiaTensorComputer_clipInertia(float d, S_00ced230_T* p);
struct S_00cee1c0_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Free(void* p, unsigned int size);
};
struct S_00cee1c0_Router
{
    unsigned int cursor;
    int unk04;
    int unk08;
    int unk0C;
    S_00cee1c0_Heap* heap;
};
struct S_00cee1c0_Arr
{
    unsigned int* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    unsigned int* m_pTrailingData;
};
S_00cee1c0_Router* hkMemoryRouter_getInstance();
float __cdecl hkInertiaTensorComputer_optimizeInertiasOfConstraintTreeInt(S_00cee1c0_Arr* arr, int unk, float value);
void __cdecl ProcessArrayWithValue(unsigned int* source, int count, int unk, float value);

#include <xmmintrin.h>
// FUN_00cf07a0 - 120 bytes
//
// The function builds a 0x50-byte aggregate in its frame (two floats followed
// by four 16-byte vectors), hands the aggregate to a helper which writes a
// float into its first member, and then copies the four vectors plus one
// float into the destination object.
//
// The sibling copy routine at 0x00cf0820 shows the aggregate layout:
//   +0x00 float, +0x04 float, +0x10/+0x20/+0x30/+0x40  __m128
// and the destination object carries the same four vectors at
// +0x50/+0x60/+0x70/+0x80 plus a float at +0x90.
//
// NOTE: the module this function lives in was built WITHOUT /GS - the
// original re-reads the destination pointer straight out of its stack slot
// after the call (no $GSCopy) and has no security-cookie prologue even
// though the aggregate's address is taken.  The packet's /GS flag is wrong
// for this module; the byte-exact build needs /GS-.

struct Src
{
    float f0;  // +0x00 - out parameter of the helper
    float f1;  // +0x04 - copied into Dest::f90
    int unk08;
    int unk0c;
    __m128 m10;  // +0x10
    __m128 m20;  // +0x20
    __m128 m30;  // +0x30
    __m128 m40;  // +0x40
};

struct Dest
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c;
    __m128 m50;  // +0x50
    __m128 m60;  // +0x60
    __m128 m70;  // +0x70
    __m128 m80;  // +0x80
    float f90;   // +0x90
};

// helper at 0x00cf0690 - writes a float through its third argument
void __cdecl hkpInertiaTensorComputer_computeShapeVolumeMassProperties(void* a, float b, float* out);

// @fnv 0x00cf07a0
// src: XBOX_PDB 0x00cf07a0
void hkpInertiaTensorComputer_setShapeVolumeMassProperties(void* a, float b, Dest* c)
{
    Src s;
    s.f0 = 0.0f;
    s.f1 = 0.0f;
    s.m10 = _mm_setzero_ps();
    s.m20 = _mm_setzero_ps();
    s.m30 = _mm_setzero_ps();
    s.m40 = _mm_setzero_ps();
    hkpInertiaTensorComputer_computeShapeVolumeMassProperties(a, b, &s.f0);
    c->f90 = s.f1;
    c->m80 = s.m10;
    c->m50 = s.m20;
    c->m60 = s.m30;
    c->m70 = s.m40;
}
