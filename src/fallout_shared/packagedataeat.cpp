
// src/fallout_shared/packagedataeat.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedataeat.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/TESEatPackageData.h"

void __cdecl _FUN_004856d0(int);
struct LocationDescriptor
{
    LocationDescriptor();
    char pad[12];
    void __thiscall PackageLocation_Save(int);
    void ResolveObject(BGSLoadFormBuffer*);
    void PackageLocation_LoadGame_0067fbe0(BGSLoadFormBuffer*);
    void* FUN_00670b30(int aFlags);
    unsigned char __thiscall IsDifferentFrom(int a1);
};

// @fnv 0x0067bbb0
// src: XBOX_PDB 0x0067bbb0
void __thiscall TESEatPackageData::Save_0067bbb0()
{
    _FUN_004856d0(0x44454b50);
    if (this->m_pPackageTarget != 0)
    {
        m_pPackageTarget->PackageLocation_Save(0x32444c50);
    }
}

// @fnv 0x0067bfa0
// src: GUESS 0x0067bfa0 (confidence: low)
void TESEatPackageData::ProcessState_0067bfa0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    if (m_pPackageTarget != 0)
    {
        m_pPackageTarget->ResolveObject(apLoadGameBuffer);
    }
}

// @fnv 0x0067b050
void __thiscall TESEatPackageData::Load(BGSLoadFormBuffer* apLoadGameBuffer)
{
    bool bhasLocation = false;
    apLoadGameBuffer->ReadTypedData((void*)&bhasLocation, 1u);
    if (bhasLocation)
    {
        m_pPackageTarget = new LocationDescriptor;
        m_pPackageTarget->PackageLocation_LoadGame_0067fbe0(apLoadGameBuffer);
    }
}

// @fnv 0x0067b9b0
TESEatPackageData::~TESEatPackageData()
{
    LocationDescriptor* a = m_pPackageTarget;
    LocationDescriptor* p = a;
    (p != 0) ? p->FUN_00670b30(1) : 0;
}

extern "C" int __cdecl FUN_00ec43fb(int a1, int a2, int* a3, int* a4, int a5);

extern int DAT_0119bdec;
extern int DAT_0119be3c;

struct FUN_0067bb40_Result
{
    int unk00;
    int unk04;
};

// @fnv 0x0067bb40
// src: XBOX_PDB 0x0067bb40
unsigned char __thiscall TESEatPackageData::Compare_0067bb40(int arg)
{
    FUN_0067bb40_Result* result = (FUN_0067bb40_Result*)FUN_00ec43fb(arg, 0, &DAT_0119bdec, &DAT_0119be3c, 0);

    if (result == 0)
    {
        return 1;
    }

    if (m_pPackageTarget != 0)
    {
        if (m_pPackageTarget->IsDifferentFrom(result->unk04) != 0)
        {
            return 1;
        }
    }
    else if (result->unk04 != 0)
    {
        return 1;
    }

    return 0;
}
