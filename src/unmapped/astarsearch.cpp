
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/CombatTargetTimestamp.h"

struct AlphaColor
{
    void FUN_0052ce20(float);
};
struct FUN_006a7d30_shell
{
    void FUN_006a7d30(float f);
};
// @fnv 0x006a7d30
void FUN_006a7d30_shell::FUN_006a7d30(float afValue)
{
    ((AlphaColor*)((char*)this + 0x1ff4))->FUN_0052ce20(afValue);
}

// @fnv 0x006a7f50
float __fastcall FUN_006a7f50(const CombatTargetTimestamp* timestamp)
{
    return timestamp->fTimeStamp;
}

extern int DAT_0106b660;

struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_006a7f90();
};

// @fnv 0x006a7f90
void GlobalObject_00869f00::FUN_006a7f90()
{
    *(int*)this = (int)&DAT_0106b660;
    this->Clear(true);
}

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
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
    ((AX*)this)->FUN_006b3eb0(0, 0);
}
