// fallout_shared/containeritemextra.cpp: ContainerItemExtra, TESLeveledList (9 functions)

#include "layout_support.h"
#include "../../include/TESLeveledList.h"
#include "../../include/TESForm.h"
#include "TESGlobal.h"

enum
{
    kContainerItemExtraChunk = 0x44454F43
};

// Raw image of the ownership chunk. Plain data so Load can fill it with
// GetChunkData; Endian is provided by the engine for byteswapped files.
struct ContainerItemExtraFileData
{
    TESForm* m_pForm;
    unsigned int m_cRank;
    float m_fHealth;

    void Endian();
};

// members without the member functions matched in this unit.
#pragma pack(push, 4)
class ContainerItemExtra
{
  public:
    TESForm* m_pForm;
    union
    {
        TESGlobal* m_pGlobal;
        int m_cRank;
        unsigned int m_uiRankFlags;
    };
    float m_fHealth;

    ContainerItemExtra();
    bool Load(TESFile* file);
    bool Compare(ContainerItemExtra* other);
    void Copy(ContainerItemExtra* other);
    bool IsDefault();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ContainerItemExtra) == 12);
FNV_STATIC_ASSERT(offsetof(ContainerItemExtra, m_pForm) == 0);
FNV_STATIC_ASSERT(offsetof(ContainerItemExtra, m_pGlobal) == 4);
FNV_STATIC_ASSERT(offsetof(ContainerItemExtra, m_cRank) == 4);
FNV_STATIC_ASSERT(offsetof(ContainerItemExtra, m_uiRankFlags) == 4);
FNV_STATIC_ASSERT(offsetof(ContainerItemExtra, m_fHealth) == 8);

// Initializes the form pointer and union member to null and sets the float value to 1.0.
// @fnv 0x0040e690
ContainerItemExtra::ContainerItemExtra()
{
    m_pForm = 0;
    m_pGlobal = 0;
    m_fHealth = 1.0f;
}

// @fnv 0x0040e780
bool ContainerItemExtra::Load(TESFile* file)
{
    bool loaded = false;
    if (file)
    {
        if (file->GetChunkID() == kContainerItemExtraChunk)
        {
            ContainerItemExtraFileData fileData;
            file->GetChunkData(&fileData, sizeof(fileData));
            if (file->IsEndianConversionRequired())
                fileData.Endian();
            m_pForm = fileData.m_pForm;
            m_uiRankFlags = fileData.m_cRank;
            m_fHealth = fileData.m_fHealth;
            loaded = true;
        }
    }
    return loaded;
}

// Returns true if other is null or if any of the three Id fields differ from other's; otherwise returns false.
// @fnv 0x0040e920
bool ContainerItemExtra::Compare(ContainerItemExtra* other)
{
    if (!other)
        return true;
    if (m_pForm != other->m_pForm)
        return true;
    if (m_pGlobal != other->m_pGlobal)
        return true;
    if (m_fHealth != other->m_fHealth)
        return true;
    return false;
}

// Copies the three fields from other into this object when other is non-null.
// @fnv 0x0040e980
void ContainerItemExtra::Copy(ContainerItemExtra* other)
{
    if (other)
    {
        m_pForm = other->m_pForm;
        m_pGlobal = other->m_pGlobal;
        m_fHealth = other->m_fHealth;
    }
}

// @fnv 0x0040e9c0
bool ContainerItemExtra::IsDefault()
{
    if (m_pForm)
        return false;
    if (m_fHealth != 1.0)
        return false;
    return true;
}

// @fnv 0x0042e680
// src: XBOX_PDB 0x0042e680
void TESLeveledList::ExtraWeaponModFlags_SetWeaponModFlags(unsigned char chance)
{
    m_pChanceGlobal = chance;
}

// Returns whether the absolute difference between aX and aY is less than afPrecision, or false if afPrecision is negative.
// @fnv 0x0040eb10
// src: XBOX_PDB 0x0040eb10
bool __cdecl FloatEQ(float aX, float aY, float afPrecision)
{
    if (afPrecision < 0.0)
        return false;
    if (aX > aY)
        return aX - aY < afPrecision;
    else
        return aY - aX < afPrecision;
}

struct FUN_0040eb90_shell : public ContainerItemExtra
{
    void ContainerItemExtra_AdjustHealthPercent(float);
};

float __cdecl BSMAX_00404010(float, float);
float __cdecl BSMIN(float, float);

// @fnv 0x0040eb90
// src: COMMUNITY 0x0040eb90
void FUN_0040eb90_shell::ContainerItemExtra_AdjustHealthPercent(float afHealthPerc)
{
    m_fHealth = BSMAX_00404010(0.0f, BSMIN(1.0f, afHealthPerc));
}

struct Holder0040e9f0
{
    TESForm* m_pForm;
    int m_cRank;
    float m_fHealth;

    void* GetValueIfFormType42();
    void WriteToChunk();
};

bool TESForm_QEndianSwapOnSave();
void AppendChunk(int, void*, int);

// @fnv 0x0040e6c0
void Holder0040e9f0::WriteToChunk()
{
    if (reinterpret_cast<ContainerItemExtra*>(this)->IsDefault())
        return;

    void* m_pGlobal;
    ContainerItemExtraFileData fileData;

    if (this->m_pForm != 0)
    {
        fileData.m_pForm = reinterpret_cast<TESForm*>(this->m_pForm->GetFormID());

        m_pGlobal = this->GetValueIfFormType42();
        if (m_pGlobal != 0)
            fileData.m_cRank = reinterpret_cast<TESForm*>(m_pGlobal)->GetFormID();
        else
            fileData.m_cRank = this->m_cRank;
    }
    else
    {
        fileData.m_pForm = 0;
        fileData.m_cRank = 0;
    }

    fileData.m_fHealth = this->m_fHealth;

    if (TESForm_QEndianSwapOnSave())
        fileData.Endian();

    AppendChunk(kContainerItemExtraChunk, &fileData, 0xc);

    if (TESForm_QEndianSwapOnSave())
        fileData.Endian();
}
