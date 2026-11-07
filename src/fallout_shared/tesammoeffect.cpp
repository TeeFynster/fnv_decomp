// fallout_shared/tesammoeffect.cpp: TESAmmoEffect, AmmoEffectDesc (8 functions)

#include "../../include/BGSAmmoForm.h"
#include "../../include/TESAmmoEffect.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectWEAP.h"
#include "../../include/TESRegionDataSound.h"
#include "../../include/BSShaderNoLightingProperty.h"

#include "../../include/ENUM_FORM_ID.h"

class ContainerItemExtraFileData
{
  public:
    void Endian();
};

extern "C" void __cdecl _alloca_probe_16();
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" unsigned int __security_cookie;

extern "C" void* __cdecl memset(void*, int, unsigned int);

// Constructs a TESAmmoEffect: zeroes effectData and sets the form type to ENUM_FORM_ID_AMEF_ID.
// @fnv 0x00599c40
TESAmmoEffect::TESAmmoEffect() : TESForm(), TESFullName()
{
    memset(effectData, 0, 12);
    SetFormType(ENUM_FORM_ID_AMEF_ID);
}

class NiTexture;


extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

extern "C" void* __cdecl _alloca(unsigned int);

// @fnv 0x00599d70
bool TESAmmoEffect::Load(TESFile* apFile)
{
    unsigned char formid = apFile->GetTESForm();
    if (formid != 0x72)
        return false;

    LoadRecordHeader(apFile);
    SetInitializationState(false);

    int chunkid;
    while ((chunkid = apFile->GetChunkID()) != 0)
    {
        switch (chunkid)
        {
        case 0x44494445: {
            char* pMessage = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pMessage, 0x200);
            SetEditorID_AtRuntime(pMessage);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4c4c5546:
            TESFullName::LoadFullNameChunk(static_cast<TESFullName*>(this), apFile);
            break;
        case 0x41544144:
            ReadTypedData(apFile, effectData, 0xc);
            if (apFile->IsEndianConversionRequired())
                ((ContainerItemExtraFileData*)effectData)->Endian();
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

// Calls FUN_00599d00, then deletes this object if bit 0 of flags is set, and returns this.
// @fnv 0x00599cd0
void* TESAmmoEffect::DestroyIfFlagged(unsigned int flags)
{
    FUN_00599d00();
    if (flags & 1)
        operator delete(this);
    return this;
}

bool __cdecl TESForm_QEndianSwapOnSave();
// @fnv 0x00599ef0
void TESAmmoEffect::SaveAmmoEffect()
{
    TESForm::BeginFormRecord();
    TESFullName::Save_00487010();
    if (TESForm_QEndianSwapOnSave())
        ((ContainerItemExtraFileData*)((char*)this + 0x24))->Endian();
    TESForm::TESForm___SaveData((char*)this + 0x24, 0xc);
    if (TESForm_QEndianSwapOnSave())
        ((ContainerItemExtraFileData*)((char*)this + 0x24))->Endian();
    TESForm::FinishFormRecord();
}

void* __memcpy(void*, const void*, unsigned int);
// @fnv 0x00599f60
void TESAmmoEffect::CopyFromAmmoEffect(TESForm* apCopy)
{
    TESAmmoEffect* pmisc = dynamic_cast<TESAmmoEffect*>(apCopy);
    if (pmisc == 0)
        return;
    __memcpy(effectData, pmisc->effectData, 12);
    TESForm::CopyFrom(apCopy);
}

struct AmmoEffectValue
{
    int FUN_0045cd60();
    int FUN_0059bb30();
    float NiPSysSpawnModifier_GetLifeSpan();
};
struct AmmoEffectList
{
    AmmoEffectValue* value;
    AmmoEffectList* next;
    AmmoEffectList();
    ~AmmoEffectList();
    AmmoEffectValue*& FUN_006815c0();
    AmmoEffectList* FUN_00726070();
    void FUN_005ae3d0(AmmoEffectValue*&);
    void FUN_00905820(AmmoEffectValue*&);
};
// @fnv 0x0059a030
float ComputeAmmoEffectValue(int iEffectType, AmmoEffectList* pEffectList, float fBaseValue)
{
    float fResult = fBaseValue;
    if (!pEffectList)
        return fResult;
    AmmoEffectList* sorted = new AmmoEffectList;
    while (pEffectList && pEffectList->FUN_006815c0())
    {
        if (pEffectList->FUN_006815c0()->FUN_0045cd60() == 1)
            sorted->FUN_005ae3d0(pEffectList->FUN_006815c0());
        else
            sorted->FUN_00905820(pEffectList->FUN_006815c0());
        pEffectList = pEffectList->FUN_00726070();
    }
    while (sorted && sorted->FUN_006815c0())
    {
        AmmoEffectValue* effect = sorted->FUN_006815c0();
        sorted = sorted->FUN_00726070();
        int effectType = effect->FUN_0059bb30();
        int iOperation = effect->FUN_0045cd60();
        float magnitude = effect->NiPSysSpawnModifier_GetLifeSpan();
        if (effectType != iEffectType)
            continue;
        switch (iOperation)
        {
        case 0:
            fResult += magnitude;
            break;
        case 1:
            fResult *= magnitude;
            break;
        case 2:
            fResult -= magnitude;
            break;
        }
    }
    delete sorted;
    return fResult;
}

extern "C" int __cdecl memcmp(const void* pvA, const void* pvB, unsigned int ItemUpdateArray);

// @fnv 0x00599fc0
bool TESAmmoEffect::CompareAmmoEffect(TESForm* pkForm)
{
    TESAmmoEffect* pkOther = dynamic_cast<TESAmmoEffect*>(pkForm);
    if (!pkOther)
        return true;
    if (memcmp(effectData, pkOther->effectData, sizeof(effectData)))
        return true;
    if (TESForm::Compare(pkOther))
        return true;
    return false;
}

// The game uses its own C++ string-copy wrapper rather than the CRT import.
namespace AmmoEffectCRT
{
int strcpy_s(char* dst, unsigned int size, const char* src);
}
int _sprintf_s(char* dst, unsigned int size, const char* fmt, ...);

class AmmoEffectSetting
{
  public:
    const char* String();
};

extern AmmoEffectSetting g_011caa94;
extern AmmoEffectSetting g_011caa84;
extern AmmoEffectSetting g_011caaa0;
extern AmmoEffectSetting g_011caa78;
extern AmmoEffectSetting g_011caaac;
extern AmmoEffectSetting g_011caab8;

class AmmoEffectDesc
{
  public:
    unsigned int GetOperation();
    unsigned int GetEffectType();
    float GetValue();
    void FormatDescription(char* buffer, int bufferSize);
};

// Formats the ammo effect description into buffer using the effect name, operation symbol, and value.
// @fnv 0x0059a1e0
void AmmoEffectDesc::FormatDescription(char* buffer, int bufferSize)
{
    char nameText_2[64];
    char opText[2];

    opText[0] = 0;
    switch (GetOperation())
    {
    case 0:
        AmmoEffectCRT::strcpy_s(opText, 2, "+");
        break;
    case 1:
        AmmoEffectCRT::strcpy_s(opText, 2, "x");
        break;
    case 2:
        AmmoEffectCRT::strcpy_s(opText, 2, "-");
        break;
    }
    switch (GetEffectType())
    {
    case 0:
        AmmoEffectCRT::strcpy_s(nameText_2, 64, g_011caa94.String());
        break;
    case 1:
        AmmoEffectCRT::strcpy_s(nameText_2, 64, g_011caa84.String());
        break;
    case 2:
        AmmoEffectCRT::strcpy_s(nameText_2, 64, g_011caaa0.String());
        break;
    case 3:
        AmmoEffectCRT::strcpy_s(nameText_2, 64, g_011caa78.String());
        break;
    case 4:
        AmmoEffectCRT::strcpy_s(nameText_2, 64, g_011caaac.String());
        break;
    case 5:
        AmmoEffectCRT::strcpy_s(nameText_2, 64, g_011caab8.String());
        break;
    }
    _sprintf_s(buffer, bufferSize, "%s %s %.2f", nameText_2, opText, (double)GetValue());
}
