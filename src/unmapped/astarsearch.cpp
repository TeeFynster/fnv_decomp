
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/CombatTargetTimestamp.h"

struct AlphaColor
{
    void TESRegionPoint_SetX(float);
};
struct FUN_006a7d30_shell
{
    void AStarSearch_NavMeshSearchNode_NavMeshSearchLink_SetMaxFitness(float f);
};
// @fnv 0x006a7d30
// src: COMMUNITY 0x006a7d30
void FUN_006a7d30_shell::AStarSearch_NavMeshSearchNode_NavMeshSearchLink_SetMaxFitness(float afValue)
{
    ((AlphaColor*)((char*)this + 0x1ff4))->TESRegionPoint_SetX(afValue);
}

// @fnv 0x006a7f50
// src: GUESS 0x006a7f50 (confidence: low)
float __fastcall AStarSearch_EvaluateValue_006a7f50(const CombatTargetTimestamp* timestamp)
{
    return timestamp->fTimeStamp;
}

extern int DAT_0106b660;

struct GlobalObject_00869f00
{
    void Clear(bool);
    void SetVtableAndProcessState_006a7f90();
};

// @fnv 0x006a7f90
// src: GUESS 0x006a7f90 (confidence: low)
void GlobalObject_00869f00::SetVtableAndProcessState_006a7f90()
{
    *(int*)this = (int)&DAT_0106b660;
    this->Clear(true);
}

struct AX
{
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
};
struct FUN_006a7f60
{
    int* vtable;
    FUN_006a7f60();
};
// Sets the vtable pointer to DAT_0106b660 and calls FUN_006b3eb0 with 0 and 0 on this object.
// @fnv 0x006a7f60
FUN_006a7f60::FUN_006a7f60()
{
    vtable = &DAT_0106b660;
    ((AX*)this)->BSSimpleArray_float_1024_InitialSetup(0, 0);
}
