#include "../../../include/CombatWorldStateListNode.h"
#include "../../../include/bhkTrapListener.h"
#include "../../../include/TESTrapListener.h"
#include "../../../include/hkpCdBodyPairCollector.h"

// src/fallout_shared/havok/testraplistener_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/havok/testraplistener.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/havok/testraplistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/testraplistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_0062d2f0_shell
{
    void* GetOffset160();
};
extern int DAT_0104e328;
void* __cdecl _Deallocate(void*);
extern int DAT_0104e3d0;
struct FUN_0062d740_shell
{
    int m_field;
    void UpdateFields_0062d740();
};
struct FUN_0062dee0_shell
{
    CombatWorldStateListNode* m_kNode;
    bool ProcessEntries_0062dee0(int arg);
};
extern int DAT_0104e3f4;
struct FUN_0062e040_shell
{
    void SetVirtualTable_0062e040();
};
struct FUN_0062c700_shell
{
    void ForwardCall_0062c700();
};
struct FUN_0062dfe0_shell
{
    void FUN_0062dfe0();
};
struct FUN_0062d710_shell : FUN_0062d740_shell
{
    void* FUN_0062d710(unsigned int flags);
};
struct FUN_0062e200_shell
{
    void* FUN_0062e200(unsigned int);
};
struct FUN_0062e230_shell
{
    void* hkArrayBase_hkpWorldRayCastOutput_hkArrayBase_hkpWorldRayCastOutput(unsigned int a, unsigned int b, unsigned int c);
    void* hkArray_hkpWorldRayCastOutput_hkContainerHeapAllocator_hkArray_hkpWorldRayCastOutput_hkContainerHeapAllocator(unsigned int a, unsigned int b, unsigned int c);
};

// Adjustor (this-adjusting) thunk for FUN_0062e3a0: "sub ecx, 0x1c; jmp FUN_0062d870".
// PrimaryBase is the first base (vptr + six int fields = 0x1c bytes); SecondaryBase
// declares the same virtual; Derived derives from both, redeclares the virtual and
// defines only its constructor, so the compiler emits the adjusting thunk.
struct PrimaryBase
{
    virtual void* FUN_0062e3a0(unsigned int flags);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct SecondaryBase
{
    virtual void* FUN_0062e3a0(unsigned int flags);
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0062e3a0
    virtual void* FUN_0062e3a0(unsigned int flags);
};

Derived::Derived()
{}

namespace fnv_0062e3b0 {
// Adjustor thunk for FUN_0062e3b0: "sub ecx, 8; jmp FUN_0062d870".
//
// MSVC emits a "this adjusting thunk" in the vtable of a class that inherits
// the same virtual from two bases: the thunk converts the secondary base
// sub-object pointer back to the derived object pointer (sub ecx, 8) and then
// tail jumps to the final overrider.
//
// The subtracted offset is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus one int member (4 + 4 = 8 bytes). Both
// bases declare the same virtual function; the derived class redeclares it and
// defines only its constructor, which is what makes the compiler emit the
// vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_0062e3b0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_0062e3b0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0062e3b0
    virtual void FUN_0062e3b0();
};

Derived::Derived()
{}
}  // namespace fnv_0062e3b0

namespace fnv_0062e3c0 {
// sub ecx,0x14; jmp FUN_00dffb00
// MSVC adjustor thunk: a class derives from two bases that both declare the same
// virtual, so the secondary base's vtable entry is an adjustor thunk that moves
// `this` back by the size of the primary base (0x14 = vptr + four int fields).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_0062e3c0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_0062e3c0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0062e3c0
// src: GUESS 0x0062e3c0 (confidence: low)
    virtual void AdjustThisAndForward_0062e3c0();
};

Derived::Derived()
{}
}  // namespace fnv_0062e3c0
