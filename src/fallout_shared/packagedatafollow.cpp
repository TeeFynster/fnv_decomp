
// src/fallout_shared/packagedatafollow.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedatafollow.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/TESFollowPackageData.h"

extern "C" void __cdecl Deallocate(void*);

// @fnv 0x0067c010
void* __thiscall TESFollowPackageData::DestroyIfFlagged(unsigned int flags)
{
    FUN_0067c080();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_01068988;
// Calls FUN_0067ad20, sets vtbl to &DAT_01068988, stores a in m2, zeroes m1, and returns this.
// @fnv 0x0067c040
TESFollowPackageData* TESFollowPackageData::Construct(float afValue)
{
    ((TESPackageData*)this)->TESPackageData::TESPackageData();
    *reinterpret_cast<void**>(this) = &DAT_01068988;
    m_08 = afValue;
    m_04 = 0;
    return this;
}

extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" bool __cdecl TESForm_QEndianSwapOnSave();
extern "C" void __cdecl AppendChunk(int, void*, int);
struct BipedModelForm
{
    void Endian();
};
struct LocationDescriptor
{
    void Save(int);
};
// @fnv 0x0067c2b0
void TESFollowPackageData::SaveFloatRecord()
{
    float fValue;
    memset(&fValue, 0, 4);
    fValue = m_08;
    if (TESForm_QEndianSwapOnSave())
        ((BipedModelForm*)&fValue)->Endian();
    AppendChunk(0x44464b50, &fValue, 4);
    if (TESForm_QEndianSwapOnSave())
        ((BipedModelForm*)&fValue)->Endian();
    if (m_04)
        ((LocationDescriptor*)m_04)->Save(0x32444c50);
}

struct FUN_00670b30_Object
{
    ~FUN_00670b30_Object();
};
// Destructor that deletes the follow package field.
// @fnv 0x0067c080
TESFollowPackageData::~TESFollowPackageData()
{
    delete reinterpret_cast<FUN_00670b30_Object*>(m_04);
}

class FollowPackageField
{
  public:
    int unk00;
    bool Cmp(FollowPackageField* p);
};
// @fnv 0x0067c220
// src: XBOX_PDB 0x0067c220
bool TESFollowPackageData::Compare_0067c220(TESPackageData* apData)
{
    TESFollowPackageData* other = dynamic_cast<TESFollowPackageData*>(apData);
    if (other == 0)
    {
        return true;
    }
    if (m_08 != other->m_08)
    {
        return true;
    }
    if (m_04 != 0)
    {
        if (m_04->Cmp(other->m_04))
        {
            return true;
        }
    }
    else
    {
        if (other->m_04 != 0)
        {
            return true;
        }
    }
    return false;
}

struct FUN_0067f030
{
    void* vtbl;
    int unk04;
    int unk08;
    FUN_0067f030();
    void FUN_0067f4d0(FollowPackageField* other, bool flag);
};

// For a compatible source, copies m_08, deletes the old m_04, and allocates and initializes m_04 when the source has one.
// @fnv 0x0067c110
// src: XBOX_PDB 0x0067c110
void __thiscall TESFollowPackageData::Copy_0067c110(TESPackageData* other)
{
    TESFollowPackageData* source = dynamic_cast<TESFollowPackageData*>(other);
    if (source)
    {
        m_08 = source->m_08;
        if (m_04)
        {
            delete reinterpret_cast<FUN_00670b30_Object*>(m_04);
            m_04 = 0;
        }
        if (source->m_04)
        {
            m_04 = reinterpret_cast<FollowPackageField*>(new FUN_0067f030);
            reinterpret_cast<FUN_0067f030*>(m_04)->FUN_0067f4d0(source->m_04, false);
        }
    }
}
