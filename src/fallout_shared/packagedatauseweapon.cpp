// fallout_shared/packagedatauseweapon.cpp: TESUseWeaponPackageData, UseWeaponActorPackageData and helpers (16 functions)

#include "../../include/TESUseWeaponPackageData.h"
#include "../../include/UseWeaponActorPackageData.h"
#include "../../include/ExtraDataList.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESObjectWEAP.h"
#include "../../include/TESPackageData.h"
#include "../../include/PackageTargetRecord.h"
#include "packagedatauseweapon_decls.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/BGSLoadFormBuffer.h"

// @fnv 0x0067d1c0
void TESUseWeaponPackageData::InitItem(TESForm* item)
{
    LocationDescriptor* package = reinterpret_cast<LocationDescriptor*>(item);
    bool initializeTarget;
    {
        LocationDescriptor* location = reinterpret_cast<LocationDescriptor*>(package->SetLocRef());
        initializeTarget = true;
        if (!m_pUseTarget && location && location->GetLocationType() == 0)
        {
            TESObjectREFR* reference = location->GetLocationReference();
            if (reference)
            {
                TESBoundObject* object = reference->GetObjectReference();
                if (object == DAT_011ca244 || object == DAT_011ca248)
                {
                    ExtraDataList* extra = reference->GetExtraData();
                    if (extra)
                    {
                        TESObjectREFR* target = extra->GetTargetObjectReference();
                        if (target)
                        {
                            m_pUseTarget = new PackageTargetRecord;
                            m_pUseTarget->SetTargetKind(PACK_TARG_TYPE_PTT_REFERENCE);
                            m_pUseTarget->SetTargetObjectReference(target);
                            initializeTarget = false;
                        }
                    }
                }
            }
        }
        if (m_pUseTarget && initializeTarget)
            m_pUseTarget->InitItem(item);
        unsigned int weaponID = reinterpret_cast<unsigned int>(pWeapon);
        pWeapon = dynamic_cast<TESObjectWEAP*>(TESForm::GetFormByID(weaponID));
    }
}

// Clears the stored reference if it equals the passed reference.
// @fnv 0x0067d9e0
void UseWeaponActorPackageData::SetReferenceTarget(TESObjectREFR* reference)
{
    m_pUseTarget = m_pUseTarget == reference ? 0 : m_pUseTarget;
}

void __cdecl Deallocate(void*);
// Runs the destructor on this, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0067cb40
void* TESUseWeaponPackageData::DestroyIfFlagged(unsigned int flags)
{
    this->TESUseWeaponPackageData::~TESUseWeaponPackageData();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00670b30
{
    ~FUN_00670b30();
};

// Deletes the target and location objects and clears both pointers.
// @fnv 0x0067ccd0
TESUseWeaponPackageData::~TESUseWeaponPackageData()
{
    delete m_pUseTarget;
    m_pUseTarget = 0;
    delete reinterpret_cast<FUN_00670b30*>(m_pTargetLocation);
    m_pTargetLocation = 0;
}

struct FUN_0067fc50_impl
{
    void __thiscall ResolveObject(BGSLoadFormBuffer*);
};

// Resolves the optional target and location using the load game buffer.
// @fnv 0x0067d8b0
void TESUseWeaponPackageData::LoadForm(BGSLoadFormBuffer* apLoadGameBuffer)
{
    if (m_pUseTarget)
        m_pUseTarget->InitLoadGame(apLoadGameBuffer);
    if (m_pTargetLocation)
        ((FUN_0067fc50_impl*)m_pTargetLocation)->ResolveObject(apLoadGameBuffer);
}

// @fnv 0x0067da20
void UseWeaponActorPackageData::InitLoadGame(BGSLoadFormBuffer* arg)
{
    m_pUseTarget = 0;
}

struct FUN_0067f600_shell
{
    bool IsDifferentFrom(void* target);
};

void* FUN_00ec43fb(void* object, unsigned int flags, char* typeInfo1, char* typeInfo2, int reserved);
float __cdecl fabsf_00408860(float value);

extern char DAT_0119bdec;
extern char DAT_0119bf00;

// Compares this use-weapon package data against apCompare field by field, returning true when any field differs or the cast fails.
// @fnv 0x0067cfc0
// src: XBOX_PDB 0x0067cfc0
bool TESUseWeaponPackageData::Compare_0067cfc0(TESPackageData* apCompare)
{
    TESUseWeaponPackageData* pOtherData =
        static_cast<TESUseWeaponPackageData*>(FUN_00ec43fb(apCompare, 0, &DAT_0119bdec, &DAT_0119bf00, 0));

    if (!pOtherData)
        return true;

    if (this->pWeapon != pOtherData->pWeapon)
        return true;

    if (this->m_pUseTarget)
    {
        if (this->m_pUseTarget->Compare(pOtherData->m_pUseTarget))
            return true;
    }
    else if (pOtherData->m_pUseTarget)
    {
        return true;
    }

    if (this->m_pTargetLocation)
    {
        if (reinterpret_cast<FUN_0067f600_shell*>(this->m_pTargetLocation)
                ->IsDifferentFrom(static_cast<void*>(pOtherData->m_pTargetLocation)))
            return true;
    }
    else if (pOtherData->m_pTargetLocation)
    {
        return true;
    }

    if (this->m_bFlag1 != pOtherData->m_bFlag1)
        return true;

    if (this->m_bFlag2 != pOtherData->m_bFlag2)
        return true;

    if (this->m_bFlag3 != pOtherData->m_bFlag3)
        return true;

    if (this->m_bFlag4 != pOtherData->m_bFlag4)
        return true;

    if (this->m_bFlag5 != pOtherData->m_bFlag5)
        return true;

    if (this->m_bFlag6 != pOtherData->m_bFlag6)
        return true;

    if (this->m_usValue1 != pOtherData->m_usValue1)
        return true;

    if (this->m_usValue2 != pOtherData->m_usValue2)
        return true;

    if (this->m_usValue3 != pOtherData->m_usValue3)
        return true;

    if (fabsf_00408860(this->m_fValue1 - pOtherData->m_fValue1) > 0.01)
        return true;

    if (fabsf_00408860(this->m_fValue2 - pOtherData->m_fValue2) > 0.01)
        return true;

    return false;
}

void* memset(void*, int, unsigned int);
bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl AppendChunk(unsigned int, void*, unsigned int);

struct PackageLocationSave
{
    void Save(int);
};

struct FlaggedValueData
{
    bool m_bFlag1;
    bool m_bFlag2;
    bool m_bFlag3;
    bool m_bFlag4;
    bool m_bFlag5;
    bool m_bFlag6;
    unsigned short m_usValue1;
    unsigned short m_usValue2;
    unsigned short m_usValue3;
    float m_fValue1;
    float m_fValue2;
    unsigned int m_uiIntegerValue;

    void PACK_USE_WEAPON_DATA_PKW2_Endian();
};

// @fnv 0x0067d350
// src: XBOX_PDB 0x0067d350
void TESUseWeaponPackageData::Save_0067d350()
{
    FlaggedValueData saveData;

    memset(&saveData, 0, 0x18);

    saveData.m_bFlag1 = this->m_bFlag1;
    saveData.m_bFlag2 = this->m_bFlag2;
    saveData.m_bFlag3 = this->m_bFlag3;
    saveData.m_bFlag4 = this->m_bFlag4;
    saveData.m_bFlag5 = this->m_bFlag5;
    saveData.m_bFlag6 = this->m_bFlag6;
    saveData.m_usValue1 = this->m_usValue1;
    saveData.m_usValue2 = this->m_usValue2;
    saveData.m_usValue3 = this->m_usValue3;
    saveData.m_fValue1 = this->m_fValue1;
    saveData.m_fValue2 = this->m_fValue2;

    saveData.m_uiIntegerValue = this->pWeapon ? this->pWeapon->GetFormID() : 0;

    if (TESForm_QEndianSwapOnSave())
        saveData.PACK_USE_WEAPON_DATA_PKW2_Endian();

    AppendChunk(0x33574b50, &saveData, 0x18);

    if (TESForm_QEndianSwapOnSave())
        saveData.PACK_USE_WEAPON_DATA_PKW2_Endian();

    if (this->m_pUseTarget)
        this->m_pUseTarget->PackageTarget_Save(0x32445450);

    if (this->m_pTargetLocation)
        reinterpret_cast<PackageLocationSave*>(this->m_pTargetLocation)->Save(0x32444c50);
}

// Initializes the parameter bytes and clears the target, location and weapon pointers.
// @fnv 0x0067cc20
TESUseWeaponPackageData::TESUseWeaponPackageData(Color kColor, Info kInfo, Range kRange, float fStart, float m_fEndValue)
{
    m_pUseTarget = 0;
    m_pTargetLocation = 0;
    pWeapon = 0;
    // Preserve the original parameter bytes without converting them to bool.
    reinterpret_cast<unsigned char*>(&m_bFlag1)[0] = kColor.r;
    reinterpret_cast<unsigned char*>(&m_bFlag1)[1] = kColor.g;
    reinterpret_cast<unsigned char*>(&m_bFlag1)[2] = kColor.b;
    reinterpret_cast<unsigned char*>(&m_bFlag1)[3] = kColor.a;
    reinterpret_cast<unsigned char*>(&m_bFlag1)[4] = kInfo.m_ucType;
    m_bFlag6 = kInfo.m_usElementCount <= 0;
    m_usValue1 = kInfo.m_usElementCount;
    m_usValue2 = kRange.m_usMin;
    m_usValue3 = kRange.m_usMax;
    m_fValue1 = fStart;
    m_fValue2 = m_fEndValue;
}

// Copy the optional extra data from another object: create ours on demand, or drop it when the source is null.

void* __cdecl operator new(unsigned int uiSize);

// @fnv 0x0067d470
void TESUseWeaponPackageData::Copy(TESPackageData* pkSource)
{
    if (pkSource)
    {
        if (!m_pUseTarget)
            m_pUseTarget = new PackageTargetRecord;
        m_pUseTarget->PackageTarget_Copy(reinterpret_cast<PackageTargetRecord*>(pkSource));
    }
    else
    {
        delete m_pUseTarget;
        m_pUseTarget = 0;
    }
}

TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);
struct PackageLocationObj
{
    unsigned int type;
    unsigned int location;
    unsigned int radius;
    PackageLocationObj();
    void PackageLocation_LoadGame_0067fbe0(BGSLoadFormBuffer*);
};
// Reads the use-weapon package data from the buffer: fixed-size fields, a weapon form, and optional target and location objects.
// @fnv 0x0067d6b0
void TESUseWeaponPackageData::LoadUseWeaponData(BGSLoadFormBuffer* buffer)
{
    buffer->LoadData(&m_bFlag1, 1);
    buffer->LoadData(&m_bFlag2, 1);
    buffer->LoadData(&m_bFlag3, 1);
    buffer->LoadData(&m_bFlag4, 1);
    buffer->LoadData(&m_bFlag5, 1);
    buffer->LoadData(&m_bFlag6, 1);
    buffer->LoadData(&m_usValue1, 2);
    buffer->LoadData(&m_usValue2, 2);
    buffer->LoadData(&m_usValue3, 2);
    buffer->LoadData(&m_fValue1, 4);
    buffer->LoadData(&m_fValue2, 4);
    pWeapon = dynamic_cast<TESObjectWEAP*>(TESForm_GetFormByNumericID(buffer->FUN_008648a0()));
    bool hasTarget;
    bool hasLocation = false;
    buffer->LoadData(&hasLocation, 1);
    if (hasLocation)
    {
        m_pUseTarget = new PackageTargetRecord;
        m_pUseTarget->LoadGame(buffer);
    }
    hasTarget = false;
    buffer->LoadData(&hasTarget, 1);
    if (hasTarget)
    {
        m_pTargetLocation = reinterpret_cast<LocationDescriptor*>(new PackageLocationObj);
        reinterpret_cast<PackageLocationObj*>(m_pTargetLocation)->PackageLocation_LoadGame_0067fbe0(buffer);
    }
}

// @fnv 0x0067d9c0
UseWeaponActorPackageData::~UseWeaponActorPackageData()
{
}

void* FUN_00ec43fb(void* object, unsigned int flags, char* typeInfo1, char* typeInfo2, int reserved);
extern char DAT_0119bdec;
extern char DAT_0119bf00;

struct TargetLocation_Stub
{
    int unk00;
    int unk04;
    int unk08;
    TargetLocation_Stub();
    ~TargetLocation_Stub();
    void CopyFrom(LocationDescriptor*, bool);
};

// Copies a TESUseWeaponPackageData obtained from apSource into this, deep-copying its two sub-objects and copying the remaining fields.
// @fnv 0x0067cd90
// src: XBOX_PDB 0x0067cd90
void TESUseWeaponPackageData::Copy_0067cd90(TESPackageData* apSource)
{
    TESUseWeaponPackageData* target =
        (TESUseWeaponPackageData*)FUN_00ec43fb(apSource, 0, &DAT_0119bdec, &DAT_0119bf00, 0);
    if (!target)
    {
        return;
    }

    delete this->m_pUseTarget;
    this->m_pUseTarget = 0;

    if (target->m_pUseTarget)
    {
        this->m_pUseTarget = new PackageTargetRecord();
        this->m_pUseTarget->PackageTarget_Copy(target->m_pUseTarget);
    }

    this->pWeapon = target->pWeapon;

    delete (TargetLocation_Stub*)this->m_pTargetLocation;
    this->m_pTargetLocation = 0;

    if (target->m_pTargetLocation)
    {
        this->m_pTargetLocation = (LocationDescriptor*)new TargetLocation_Stub();
        ((TargetLocation_Stub*)this->m_pTargetLocation)->CopyFrom(target->m_pTargetLocation, false);
    }

    this->m_bFlag1 = target->m_bFlag1;
    this->m_bFlag2 = target->m_bFlag2;
    this->m_bFlag3 = target->m_bFlag3;
    this->m_bFlag4 = target->m_bFlag4;
    this->m_bFlag5 = target->m_bFlag5;
    this->m_bFlag6 = target->m_bFlag6;
    this->m_usValue1 = target->m_usValue1;
    this->m_usValue2 = target->m_usValue2;
    this->m_usValue3 = target->m_usValue3;
    this->m_fValue1 = target->m_fValue1;
    this->m_fValue2 = target->m_fValue2;
}

struct LocationSave
{
    void PackageLocation_SaveGame(BGSSaveFormBuffer*);
};
// @fnv 0x0067d550
// src: XBOX_PDB 0x0067d550
void TESUseWeaponPackageData::SaveGame_0067d550(BGSSaveFormBuffer* buffer)
{
    buffer->SaveData(&m_bFlag1, 1, 0);
    buffer->SaveData(&m_bFlag2, 1, 0);
    buffer->SaveData(&m_bFlag3, 1, 0);
    buffer->SaveData(&m_bFlag4, 1, 0);
    buffer->SaveData(&m_bFlag5, 1, 0);
    buffer->SaveData(&m_bFlag6, 1, 0);
    buffer->SaveData(&m_usValue1, 2, 0);
    buffer->SaveData(&m_usValue2, 2, 0);
    buffer->SaveData(&m_usValue3, 2, 0);
    buffer->SaveData(&m_fValue1, 4, 0);
    buffer->SaveData(&m_fValue2, 4, 0);
    buffer->FUN_00865df0(pWeapon, 0);
    bool p = m_pUseTarget;
    buffer->SaveData(&p, 1, 0);
    if (p)
        m_pUseTarget->SaveGame(buffer);
    bool bHasLocation = m_pTargetLocation;
    buffer->SaveData(&bHasLocation, 1, 0);
    if (bHasLocation)
        ((LocationSave*)m_pTargetLocation)->PackageLocation_SaveGame(buffer);
}

// Copies the raw parameter fields, clears target/location, and stores the weapon value.
// @fnv 0x0067cb70
TESUseWeaponPackageData::TESUseWeaponPackageData(Parameters kData, int iParam)
{
    m_pUseTarget = 0;
    m_pTargetLocation = 0;
    pWeapon = reinterpret_cast<TESObjectWEAP*>(iParam);
    // The serialized parameters retain their raw byte values.
    reinterpret_cast<Parameters*>(&m_bFlag1)->m_c00 = kData.m_c00;
    reinterpret_cast<Parameters*>(&m_bFlag1)->m_c01 = kData.m_c01;
    reinterpret_cast<Parameters*>(&m_bFlag1)->m_c02 = kData.m_c02;
    reinterpret_cast<Parameters*>(&m_bFlag1)->m_c03 = kData.m_c03;
    reinterpret_cast<Parameters*>(&m_bFlag1)->m_c04 = kData.m_c04;
    reinterpret_cast<Parameters*>(&m_bFlag1)->m_c05 = kData.m_c05;
    reinterpret_cast<Parameters*>(&m_bFlag1)->m_s06 = kData.m_s06;
    reinterpret_cast<Parameters*>(&m_bFlag1)->m_s08 = kData.m_s08;
    reinterpret_cast<Parameters*>(&m_bFlag1)->m_s0A = kData.m_s0A;
    reinterpret_cast<Parameters*>(&m_bFlag1)->m_f0C = kData.m_f0C;
    reinterpret_cast<Parameters*>(&m_bFlag1)->m_f10 = kData.m_f10;
}
