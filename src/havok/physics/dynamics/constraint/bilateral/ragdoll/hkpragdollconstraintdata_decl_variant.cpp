#include <xmmintrin.h>
typedef ::__m128 LocalM128;

// src/havok/physics/dynamics/constraint/bilateral/ragdoll/hkpragdollconstraintdata_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00cdf090: the skeleton of src/havok/physics/dynamics/constraint/bilateral/ragdoll/hkpragdollconstraintdata.cpp
// with declarations corrected to what the original code does (hkBase.h: typedef char hkBool; -> class hkBool { public: __forceinline hkBool() {} _; hkpRagdollConstraintData.h: hkpRagdollConstraintData += hkBool FUN_00cdf090() const;; hkBase.h: struct hkRotation : hkMatrix3 {}; -> struct hkRotation : hkMatrix3 { hkBool FUN_00cb2e7). Move the function to its real unit once
// that unit declares it this way.

// src/havok/physics/dynamics/constraint/bilateral/ragdoll/hkpragdollconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/ragdoll/hkpragdollconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpRagdollConstraintData_decl_hkpragdollconstraintdata.h"
void __stdcall hkpRagdollConstraintData_getRuntimeInfo(int* a, int* b);
struct FUN_00cde980_cls
{
    void __thiscall FUN_00cde980(int a);
};
struct FUN_00cde960_cls
{
    void __thiscall FUN_00cde960(float a);
};
void* __cdecl hkpConstraintData_getConstraintInfoUtil(void* a, int b, int c);
struct FUN_00cde9b0_cls
{
    char* FUN_00cde9b0(int a);
};
extern int DAT_010cb71c;
extern int _DAT_0102e388;
struct DDCC60World
{
    void __thiscall removeReference(void);
};
struct FUN_00cdf1f0
{
    void* m_ppVirtualMethodTable;          // +0x00
    char pad[0xdc];          // +0x04 .. +0xdf
    DDCC60World* m_refs[3];  // +0xe0
    ~FUN_00cdf1f0();
};
struct FUN_00cde970_cls
{
    int unk00;
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
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    float m_13c;
    float FUN_00cde970();
};
// FUN_00cde9a0
//   movzx eax, byte ptr [ecx + 0x13a]
//   shr   eax, 1
//   ret
//
// The unit file does not declare this function, so it is modelled here from the
// disassembly.  The object is an hkpRagdollConstraintData (m_kBridgeAtoms at +0x10);
// inside m_kBridgeAtoms the hkpBallSocketConstraintAtom sits at +0x128, so its
// The getter returns that byte shifted right by one bit.
struct RagdollBodiesToNotify : public hkpRagdollConstraintData
{
    int __thiscall FUN_00cde9a0();
};
int __cdecl hkpRagdollConstraintData_ReturnConstant_7();
typedef ::__m128 LocalM128;
struct __declspec(align(16)) FUN_00cdf190_Vec
{
    float x;
    float y;
    float z;
    float w;
};
struct FUN_00cdf190_Out
{
    FUN_00cdf190_Vec a;
    FUN_00cdf190_Vec b;
    FUN_00cdf190_Vec c;
};
struct FUN_00cdf190_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    FUN_00cdf190_Vec v20;
    FUN_00cdf190_Vec v30;
    FUN_00cdf190_Vec v40;
    void CopyVectorsToOut(FUN_00cdf190_Out* out);
};
struct FnvCpu_FUN_00cdf530_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00cdf530_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00cdf530_CpuAllocator* allocator;
};
FnvCpu_FUN_00cdf530_CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00cdf530_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00cdf1f0();
    FnvCpu_FUN_00cdf530_CpuObject* FUN_00cdf530(unsigned int flags);
};

// @fnv 0x00cdf090
// src: HAVOK_LIB 0x00cdf090
hkBool hkpRagdollConstraintData::isValid_00cdf090() const
{
    hkBool valid = true;
    valid = valid && m_kBridgeAtoms.m_kTransforms.m_kBodyALocalFrame.m_rotation.IsOrthonormal(0.001f);
    valid = valid && m_kBridgeAtoms.m_kTransforms.m_kBodyBLocalFrame.m_rotation.IsOrthonormal(0.001f);
    valid = valid && m_kBridgeAtoms.m_kConeLimit.m_fMinAngle == -100.0;
    valid = valid && m_kBridgeAtoms.m_kConeLimit.m_fMaxAngle >= 0.0f;
    valid = valid && m_kBridgeAtoms.m_kConeLimit.m_fMaxAngle < 3.1415927410125732;
    valid = valid && m_kBridgeAtoms.m_kPlaneLimit.m_fMinAngle <= m_kBridgeAtoms.m_kPlaneLimit.m_fMaxAngle;
    valid = valid && m_kBridgeAtoms.m_kTwistLimit.m_fMinAngle <= m_kBridgeAtoms.m_kTwistLimit.m_fMaxAngle;
    return valid;
}
