
// src/fallout_shared/packagedataescort.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedataescort.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/TESEscortPackageData.h"

void _Deallocate(void*);
// Calls FUN_0067bca0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0067bc30
void* TESEscortPackageData::DestroyIfFlagged(unsigned int flags)
{
    FUN_0067bca0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_01068960;

// Calls the base constructor, sets the vtable to DAT_01068960, clears m_pPackageTarget, stores *pForm into m_iValue and returns this.
// @fnv 0x0067bc60
TESEscortPackageData* __thiscall TESEscortPackageData::ConstructFromForm(TESForm** pForm)
{
    ((TESPackageData*)this)->TESPackageData::TESPackageData();
    *(void**)this = &DAT_01068960;
    m_pPackageTarget = 0;
    m_iValue = reinterpret_cast<int>(*pForm);
    return this;
}

namespace fnv_0067bec0 {
struct IntegerData
{
    int m_iValue;
};
bool TESForm_QEndianSwapOnSave();
void AppendChunk(int, void*, int);
struct BipedModelForm
{
    void Endian();
};
struct LocationDescriptor
{
    void Save(int);
};
void* memset(void*, int, unsigned int);
}  // namespace fnv_0067bec0

// @fnv 0x0067bec0
// src: XBOX_PDB 0x0067bec0
void TESEscortPackageData::Save_0067bec0()
{
    using namespace fnv_0067bec0;
    IntegerData valueBlock;
    memset(&valueBlock, 0, 4);
    valueBlock.m_iValue = m_iValue;
    if (TESForm_QEndianSwapOnSave())
        ((BipedModelForm*)&valueBlock)->Endian();
    AppendChunk(0x32454b50, &valueBlock, 4);
    if (TESForm_QEndianSwapOnSave())
        ((BipedModelForm*)&valueBlock)->Endian();
    if (m_pPackageTarget)
        reinterpret_cast<fnv_0067bec0::LocationDescriptor*>(m_pPackageTarget)->Save(0x32444c50);
}

namespace fnv_0067bf40 {
struct FUN_0067fb60_holder
{
    void PackageLocation_SaveGame(void*);
};
}  // namespace fnv_0067bf40

// @fnv 0x0067bf40
// src: COMMUNITY 0x0067bf40
void TESEscortPackageData::SaveGame_0067bf40(BGSSaveFormBuffer* buffer)
{
    buffer->SaveData(reinterpret_cast<char*>(&m_iValue), 4, 0);
    bool hasLocation = (m_pPackageTarget != 0) ? true : false;
    buffer->SaveData(reinterpret_cast<char*>(&hasLocation), 1, 0);
    if (hasLocation)
        reinterpret_cast<fnv_0067bf40::FUN_0067fb60_holder*>(m_pPackageTarget)->PackageLocation_SaveGame(buffer);
}

struct LocationDescriptor
{
    void* m_vtbl;
    int m_flags;
    ~LocationDescriptor();
};
// @fnv 0x0067bca0
TESEscortPackageData::~TESEscortPackageData()
{
    delete m_pPackageTarget;
}

namespace fnv_0067c330 {
void* __cdecl operator new(unsigned int);
struct LocationDescriptor
{
    LocationDescriptor();
    ~LocationDescriptor();
    void PackageLocation_LoadGame_0067fbe0(BGSLoadFormBuffer*);
    int pad[3];
};
}  // namespace fnv_0067c330

// @fnv 0x0067c330
// src: COMMUNITY 0x0067c330
void TESEscortPackageData::TESFollowPackageData_LoadGame(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData((void*)&m_iValue, 4u);
    unsigned char hasLocation = 0;
    buffer->ReadTypedData((bool*)&hasLocation, 1u);
    if (hasLocation)
    {
        m_pPackageTarget = reinterpret_cast<LocationDescriptor*>(new fnv_0067c330::LocationDescriptor);
        reinterpret_cast<fnv_0067c330::LocationDescriptor*>(m_pPackageTarget)->PackageLocation_LoadGame_0067fbe0(buffer);
    }
}

struct FUN_0067f030 : LocationDescriptor
{
    int unk08;
    FUN_0067f030();
    ~FUN_0067f030();
    void FUN_0067f4d0(LocationDescriptor* pSource, int flags);
};

extern const int DAT_0119bdec;
extern const int DAT_0119be60;
extern TESPackageData* __cdecl FUN_00ec43fb(BGSLoadFormBuffer* pBuffer, int arg2, const void* arg3, const void* arg4,
                                            int arg5);

// @fnv 0x0067bd30
void TESEscortPackageData::LoadPackageData(BGSLoadFormBuffer* pBuffer)
{
    TESEscortPackageData* pData = static_cast<TESEscortPackageData*>(
        FUN_00ec43fb(pBuffer, 0, &DAT_0119bdec, &DAT_0119be60, 0));
    if (pData != 0)
    {
        if (m_pPackageTarget != 0)
        {
            delete m_pPackageTarget;
            m_pPackageTarget = 0;
        }
        if (pData->m_pPackageTarget != 0)
        {
            m_pPackageTarget = new FUN_0067f030();
            ((FUN_0067f030*)m_pPackageTarget)->FUN_0067f4d0(pData->m_pPackageTarget, 0);
        }
        m_iValue = pData->m_iValue;
    }
}
