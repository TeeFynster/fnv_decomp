
// src/havok/common/base/memory/system/hkmemorysystem_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/havok/common/base/memory/system/hkmemorysystem.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

int __stdcall hkMemorySystem_debugTagAddress(int a, int b);
extern int DAT_01268418;
int hkMemorySystem_getInstance();
extern int g_CBBFD0Value;
int __cdecl hkMemorySystem_GetCBBFD0Value();
extern int DAT_010c8efc;
struct FUN_00cbbfe0_This
{
    int unk00;
    void __thiscall SetVirtualTable_00cbbfe0();
};
// FUN_00cbc450 - 10 bytes
//   call 0xcbbfe0
//   mov eax, ecx
//   ret 4
//
// The callee FUN_00cbbfe0 is DEFINED here (stand-in) because MSVC must be able
// to see that it leaves ECX untouched: the original returns `this` in EAX right
// after the call, so `this` has to stay live in ECX across it.  Declaring the
// helper only would make MSVC spill `this` to a callee-saved register.
//
// The stand-in body is behaviourally equivalent to the original callee
// (0x00cbbfe0 = "mov dword ptr [ecx], 0x010c8efc ; ret"): it stores the class
// vtable pointer into the object and returns, never touching ECX.
struct VTable
{
    void* entries[4];
};
extern void FUN_00cbbfe0_dummy();
static const VTable g_vtbl = {
    {(void*)&FUN_00cbbfe0_dummy, (void*)&FUN_00cbbfe0_dummy, (void*)&FUN_00cbbfe0_dummy, (void*)&FUN_00cbbfe0_dummy}};
struct MyCls
{
    const VTable* m_vtbl;
    __declspec(noinline) void SetVirtualTable_00cbbfe0();
    MyCls* EvaluateValue_00cbc450(int arg);
};
// src: GUESS 0x00cbbfe0 (confidence: low)
void MyCls::SetVirtualTable_00cbbfe0()
{
    m_vtbl = &g_vtbl;
}

struct Quantity
{
    unsigned int m_quantity;
    void SetQuantity(unsigned int q);
};
unsigned int __cdecl hkAddByteOffset_005e0b50(void* p, int v);
struct QuantitySet
{
    Quantity m_kPointA;
    Quantity m_kPointB;
    Quantity m_iThirdValue;
    void hkStackMemory_initMemory(unsigned int q, int v);
};
// @fnv 0x008c70c0
// src: XBOX_PDB 0x008c70c0
void QuantitySet::hkStackMemory_initMemory(unsigned int q, int v)
{
    m_kPointB.SetQuantity(q);
    m_kPointA.SetQuantity(q);
    m_iThirdValue.SetQuantity(hkAddByteOffset_005e0b50((void*)q, v));
}
