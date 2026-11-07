
// src/fallout_shared/havok/foislandactivationlistener_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/havok/foislandactivationlistener.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/havok/foislandactivationlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/foislandactivationlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../include/hkpIslandActivationListener.h"
#include "../../../include/NiPoint3.h"

extern "C" void __cdecl _Deallocate(void*);
extern int DAT_0104de10;
extern int DAT_011f942c;
void BSShaderManager_ResetMotionBluredObject();
struct hkVector4;
struct NiTransform;
struct TopicH
{
    NiPoint3* GetAddTopicList();
    NiPoint3& _ref_006815c0();
};
void HK2NI_00624b10(NiTransform*, NiPoint3*);
NiPoint3& SetNiPoint3FromHkVector4(NiPoint3&, const hkVector4&);
NiTransform* HK2NI_00624ad0(NiTransform* arNiTran, TopicH* arTopicH);

// FUN_00624be0 : 8-byte MSVC this-adjusting (virtual) thunk.
//     sub ecx, 0x4 ; jmp FUN_00624190
//
// MSVC emits such a stub in the vtable of a class that inherits the same
// virtual slot through two bases: the slot of the second base holds a tiny
// stub that moves `this` back onto the complete object (sub ecx, size of the
// primary base) and tail-jumps to the implementation.
//
// The subtracted offset is therefore the size of the primary base, which here
// is just a vtable pointer (4 bytes).  Both bases declare the same virtual
// function; the derived class redeclares it and defines only its
// constructor, which is what makes the compiler emit the vtables and the
// adjusting thunk.
struct IslandPrimaryBase
{
    virtual void AdjustThisAndForward_00624be0();
};

struct IslandSecondaryBase
{
    virtual void AdjustThisAndForward_00624be0();
};

struct IslandDerived : IslandPrimaryBase, IslandSecondaryBase
{
    IslandDerived();
// @fnv 0x00624be0
// src: GUESS 0x00624be0 (confidence: low)
    virtual void AdjustThisAndForward_00624be0();
};

IslandDerived::IslandDerived()
{}
