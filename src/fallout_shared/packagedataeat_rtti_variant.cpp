
// src/fallout_shared/packagedataeat_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESEatPackageData). The skeleton of src/fallout_shared/packagedataeat.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

// src/fallout_shared/packagedataeat.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedataeat.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/TESEatPackageData.h"

extern "C" int __cdecl FUN_00ec43fb(int, int, int*, int*, int);
extern int DAT_0119bdec;
extern int DAT_0119be3c;

struct FUN_0067f030
{
    int unk00;
    int unk04;
    int unk08;
    FUN_0067f030();
    ~FUN_0067f030();
    void __thiscall FUN_0067f4d0(void* location, int flags);
};

struct FUN_0067ba40_Result
{
    int unk00;
    void* location;
};

// @fnv 0x0067ba40
// src: XBOX_PDB 0x0067ba40
void __thiscall TESEatPackageData::Copy_0067ba40(int flags)
{
    FUN_0067ba40_Result* result = (FUN_0067ba40_Result*)FUN_00ec43fb(flags, 0, &DAT_0119bdec, &DAT_0119be3c, 0);
    if (result)
    {
        if (m_pPackageTarget)
        {
            delete (FUN_0067f030*)m_pPackageTarget;
            m_pPackageTarget = 0;
        }
        if (result->location)
        {
            m_pPackageTarget = (LocationDescriptor*)new FUN_0067f030;
            ((FUN_0067f030*)m_pPackageTarget)->FUN_0067f4d0(result->location, 0);
        }
    }
}
