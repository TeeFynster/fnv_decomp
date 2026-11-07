
// src/fallout_shared/packagedataambush.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedataambush.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/TESAmbushPackageData.h"

void __cdecl _Deallocate(void*);
// Destroys the package data, then frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0067ad90
void* __thiscall TESAmbushPackageData::Destroy(unsigned int flags)
{
    this->TESAmbushPackageData::~TESAmbushPackageData();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl TESForm_AddChunk(int);
struct LocationDescriptor
{
    void __thiscall Save(int);
};
// @fnv 0x0067afc0
void __thiscall TESAmbushPackageData::SaveWithTag()
{
    TESForm_AddChunk(0x4d414b50);
    if (m_pkLocation)
        reinterpret_cast<LocationDescriptor*>(m_pkLocation)->Save(0x32444c50);
}

class Sub_0067adc0
{
  public:
    unsigned int m_00;
    int Release(unsigned int flags);
};

// Destructor releases the location by calling Release(1) if it is non-null.
// @fnv 0x0067adc0
TESAmbushPackageData::~TESAmbushPackageData()
{
    Sub_0067adc0* copy;
    Sub_0067adc0* tmp;
    copy = reinterpret_cast<Sub_0067adc0*>(m_pkLocation);
    tmp = copy;
    tmp != 0 ? tmp->Release(1) : 0;
}

extern int DAT_0119bdec;
extern int DAT_0119bdc8;
void* __cdecl operator new(unsigned int size);
struct PackageRecord
{
    int unk00;
    void* location04;
};
PackageRecord* __cdecl FUN_00ec43fb(int id, int flags, const int* name, const int* type, int option);
struct AmbushLocation
{
    int unk00, unk04, unk08;
    AmbushLocation();
    void* FUN_00670b30(int release);
    void FUN_0067f4d0(void* source, int flags);
};
// Looks up a package record by id; if found, releases the current location and creates a new AmbushLocation from the record's location.
// @fnv 0x0067ae50
void TESAmbushPackageData::SetLocationFromPackage(int aiPackageId)
{
    PackageRecord* record = FUN_00ec43fb(aiPackageId, 0, &DAT_0119bdec, &DAT_0119bdc8, 0);
    if (record)
    {
        if (m_pkLocation)
        {
            AmbushLocation* pAllocatedPath = reinterpret_cast<AmbushLocation*>(m_pkLocation);
            AmbushLocation* pOldLocation = pAllocatedPath;
            pOldLocation ? pOldLocation->FUN_00670b30(1) : 0;
            m_pkLocation = 0;
        }
        if (record->location04)
        {
            m_pkLocation = reinterpret_cast<AF50Location*>(new AmbushLocation());
            reinterpret_cast<AmbushLocation*>(m_pkLocation)->FUN_0067f4d0(record->location04, 0);
        }
    }
}

// TESAmbushPackageData: report whether another package's data differs from ours (location only).

class AF50Location
{
  public:
    bool IsDifferent(AF50Location* pkOther);
};

// Casts pkOtherData to TESAmbushPackageData and returns true if the cast fails or the two m_pkLocation values differ, otherwise false.
// @fnv 0x0067af50
// src: XBOX_PDB 0x0067af50
bool TESAmbushPackageData::Compare_0067af50(TESPackageData* pkOtherData)
{
    TESAmbushPackageData* pkOther = dynamic_cast<TESAmbushPackageData*>(pkOtherData);
    if (!pkOther)
        return true;

    if (m_pkLocation)
    {
        if (m_pkLocation->IsDifferent(pkOther->m_pkLocation))
            return true;
    }
    else if (pkOther->m_pkLocation)
    {
        return true;
    }
    return false;
}
