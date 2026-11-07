
// Fallout: New Vegas - original source reconstruction.
// Original: platforms/common/code/fallout/ai/actorpackage.cpp
//
// ActorPackageData. The package reference is refcounted through AddRef and
// Release; runtime-created packages are destroyed once the last reference
// goes away. PTYPE enumerators match guardpackage.h.

#include "../../../include/Actor.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESPackage.h"
#include "../../../include/TESDataHandler.h"
#include "../../../include/ActorPackageContext.h"
#include "../../../include/ActorPackageData.h"
#include "../../../include/BGSClipRoundsForm.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSMessageIcon.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/BGSSaveLoadGame.h"
#include "../../../include/BaseFormComponent.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/GuardActorPackageData.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESFullName.h"
#include "../../../include/TESIcon.h"
#include "../../../include/TESSaveLoadGame.h"
#include "../../../include/TESScriptableForm.h"
#include "../../../include/TESTexture.h"

// ---- Local declarations ----

// The original TU reached NULL through the game core headers; this
// standalone reconstruction defines it directly.
#define NULL 0

#include "../../../include/PTYPE.h"

class Calendar
{
  public:
    float GetGameTime();
};

extern PlayerCharacter* g_thePlayer;
extern TESDataHandler* g_dataHandler;
extern Calendar g_calendar;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern TESSaveLoadGame* g_TESSaveLoadGame;
extern const char* g_packageTypeNames[];
void LogWarning(const char* apFormat, ...);

static const char s_kPackageTypeChangedWarning[] =
    "Package '%s' (%08X) changed type from %s to %s, so the actor package data was replaced";

// Clears the stored actor reference if it matches the passed reference.
// @fnv 0x008c5ec0
void GuardActorPackageData::SetReferenceTarget(TESObjectREFR* apReference)
{
    if (apReference == pWarningTarget)
        pWarningTarget = NULL;
}

// @fnv 0x008c5ef0
void ActorPackageContext::Clear()
{
    if (pPackage)
    {
        if (pPackage == g_thePlayer->pCurrentPackage)
            g_thePlayer->pCurrentPackage = NULL;
        if (!pPackage->Release() && pPackage->IsMustComplete())
        {
            TESPackage* pOldPackage = pPackage;
            pPackage = NULL;
            if (g_TESSaveLoadGame->GetLoading())
                g_TESSaveLoadGame->DeleteForm(pOldPackage);
            else
                delete pOldPackage;
        }
        else
        {
            pPackage = NULL;
        }
    }
    if (pData)
    {
        delete pData;
        pData = NULL;
    }
    m_fPackageValue = -1.0F;
    m_iPackageValue = -1;
    iFlags = 0;
    pTarget = NULL;
}

// @fnv 0x008c6080
void ActorPackageContext::SetPackageAndTarget(TESPackage* apPackage, TESObjectREFR* apTarget)
{
    if (apPackage == pPackage)
        return;
    Clear();
    if (apPackage)
    {
        apPackage->AddRef();
        m_fPackageValue = g_calendar.GetGameTime();
        pPackage = apPackage;
        pData = ActorPackageData::CreatePackageData((PTYPE)apPackage->GetPackType());
        m_iPackageValue = 0;
        pTarget = apTarget;
    }
}

// Reads a package form ID, package type and package data from the buffer, then reads flags and target, creating the package if needed.
// @fnv 0x008c6730
void ActorPackageContext::LoadGame(BGSLoadFormBuffer* apBuffer)
{
    unsigned int iFormID = 0;
    bool bResult = apBuffer->ReadFormIdentifier(&iFormID);
    bool bCreated;
    if (iFormID || bResult)
    {
        char cDataType;
        bCreated = false;
        if (g_dataHandler->FormIDExists(iFormID))
        {
            char cPackageType = 0;
            apBuffer->ReadTypedData(&cPackageType, 1u);
            if (cPackageType != -1)
            {
                pPackage = TESPackage::CreatePackageForType((PTYPE)cPackageType);
                g_BGSSaveLoadGame->ChangeFormID(iFormID, pPackage->GetFormID());
                static_cast<TESForm*>(pPackage)->LoadGame(apBuffer);
            }
            else
            {
                pPackage = (TESPackage*)iFormID;
                bCreated = true;
            }
        }
        else
        {
            pPackage = iFormID ? dynamic_cast<TESPackage*>(TESForm::GetFormByID(iFormID)) : NULL;
        }
        cDataType = -1;
        apBuffer->ReadTypedData(&cDataType, 1u);
        if (cDataType != -1)
        {
            pData = ActorPackageData::CreatePackageData((PTYPE)cDataType);
            pData->LoadGame(apBuffer);
        }
        else
        {
            delete pData;
            pData = NULL;
        }
        apBuffer->ReadTypedData(&m_iPackageValue, 4u);
        apBuffer->ReadTypedData(&m_fPackageValue, 4u);
        apBuffer->ReadTypedData(&iFlags, 4u);
        apBuffer->ReadFormIdentifier(&pTarget);
        if (bCreated)
            SetFlag((unsigned char)0, true);
    }
    if (bResult)
        Clear();
}

// @fnv 0x008c6b20
void ActorPackageContext::ApplyLoadBuffer(BGSLoadFormBuffer* apBuffer)
{
    if (IsFlagSet(0))
        SetFlag((unsigned char)0, false);
    else if (pPackage && g_dataHandler->FormIDExists(pPackage->GetFormID()))
        pPackage->Unk_21(apBuffer);
    if (pData && pPackage)
    {
        if (pPackage->GetPackType() != pData->GetPackageType())
        {
            LogWarning(s_kPackageTypeChangedWarning, pPackage->GetName(), pPackage->GetFormID(),
                       g_packageTypeNames[pData->GetPackageType()], g_packageTypeNames[pPackage->GetPackType()]);
            delete pData;
            pData = ActorPackageData::CreatePackageData((PTYPE)pPackage->GetPackType());
        }
    }
}

// @fnv 0x004fd3e0
TESSound* EffectSetting::GetHitSound()
{
    return data.m_pContactSound;
}

extern int DAT_01031fac;

struct FUN_00527770_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_00527770_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00527770
// src: EXE 0x00527770
int* __fastcall NiTMap_unsigned_int_TESObjectREFR_NiTMap(int* self, FUN_00527770_arg a)
{
    FUN_005890c0(self, a);
    *self = (int)&DAT_01031fac;
    return self;
}

// Deletes pData if it is non-null.
// @fnv 0x008c5e70
// ActorPackageContext.h does not declare its destructor. A single fastcall
// parameter preserves the original ECX-only calling convention without a class copy.
void __fastcall DeleteActorPackageData(ActorPackageContext* apContext)
{
    if (apContext->pData)
        delete apContext->pData;
}

unsigned int __cdecl FinishScriptRunLock(void*);

// @fnv 0x008c6030
int TESPackage::Release()
{
    unsigned int newRefCount = FinishScriptRunLock(&unk07C);
    return newRefCount;
}

unsigned int __cdecl InitScriptRunLock(void*);

// Calls InitScriptRunLock on the object at offset 0x7c and returns its result.
// @fnv 0x008c6100
void TESPackage::AddRef()
{
    unsigned int newRefCount = InitScriptRunLock(&unk07C);
    // The original leaves the updated count in EAX, despite the shared void return.
    __asm mov eax, newRefCount
}

// @fnv 0x008c6130
void ActorPackageContext::MovePackageData(ActorPackageContext* apDestPackageInstance)
{
    apDestPackageInstance->pPackage = pPackage;
    apDestPackageInstance->pData = pData;
    apDestPackageInstance->m_iPackageValue = m_iPackageValue;
    apDestPackageInstance->m_fPackageValue = m_fPackageValue;
    pPackage = NULL;
    pData = NULL;
    m_iPackageValue = -1;
    m_fPackageValue = -1.0f;
}

// Returns true if the bit for aeFlag is set in the 32-bit flags field at offset 0x14 of this object.
// @fnv 0x008c6b00
bool ActorPackageContext::GetFlag(int aeFlag)
{
    return ((1 << aeFlag) & iFlags) ? true : false;
}

// @fnv 0x008c6060
void ActorPackageContext::NullInstanceData()
{
    pData = NULL;
}

// @fnv 0x008c65a0
void ActorPackageContext::Revert(unsigned int aiFlags)
{
    if ((aiFlags & 0) && pPackage)
        Clear();
}

int __cdecl Procedure_GetProcedureCount(int);

// @fnv 0x008c6970
void ActorPackageContext::InitLoadGame(BGSLoadFormBuffer* apBuffer)
{
    if (IsFlagSet(0))
    {
        unsigned int uiPackageFormID = g_BGSSaveLoadGame->GetNewFormID((unsigned int)pPackage);
        pPackage = uiPackageFormID ? dynamic_cast<TESPackage*>(TESForm::GetFormByID(uiPackageFormID)) : 0;
    }
    else if (pPackage && g_dataHandler->FormIDExists(pPackage->GetFormID()))
    {
        pPackage->Unk_19(apBuffer);
    }
    if (pPackage)
    {
        if (pPackage->GetProcedureType() == -1)
            pPackage->SetTargetFromReference(0);
        pPackage->AddRef();
        int iCount = Procedure_GetProcedureCount(pPackage->GetProcedureType());
        if (m_iPackageValue >= iCount)
            m_iPackageValue = iCount - 1;
    }
    if (pData)
        pData->InitLoadGame(apBuffer);
    pTarget = pTarget ? dynamic_cast<TESObjectREFR*>(TESForm::GetFormByID((unsigned int)pTarget)) : 0;
    if (pTarget)
        pTarget->TESObjectREFR_SetTargeted(true);
}

// @fnv 0x008c61a0
unsigned short ActorPackageContext::GetSaveSize(unsigned int aiFlags)
{
    int total = 0;
    total += 4;
    if (pPackage != 0)
    {
        unsigned int uiValue = pPackage->GetFormID();
        if ((aiFlags & 0) != 0)
        {
            if (g_dataHandler->FormIDExists(uiValue))
            {
                // Preserve the original byte-sized result at this legacy call site.
                typedef bool (TESPackage::*PackageTypeCheck)();
                bool b = (pPackage->*reinterpret_cast<PackageTypeCheck>(static_cast<int (TESPackage::*)()>(&TESPackage::GetPackType)))();
                total += 1;
                if ((aiFlags & 0) == 0)
                {
                    total += pPackage->GetSaveSize();
                }
            }
        }
        total += 4;
    }
    total += 4;
    return (unsigned short)total;
}


// Saves the package's type, data, flags and target to the buffer, writing -1 for the type when the package data is invalid for the buffer version.
// @fnv 0x008c65d0
void ActorPackageContext::SaveGame(BGSSaveFormBuffer* apBuffer)
{
    // The original save path calls virtual slot 2 and consumes the full EAX result.
    int iVersion = reinterpret_cast<int>(apBuffer->GetActor());
    apBuffer->SerializeFormData(pPackage, 0);
    if (pPackage)
    {
        if (g_dataHandler->FormIDExists(pPackage->GetFormID()))
        {
            char cType = pPackage->GetPackType();
            // The shared declaration types this virtual slot as an actor query;
            // this save path passes the buffer version in the same argument slot.
            if (!pPackage->IsPackageDoneForActor((Actor*)iVersion))
                cType = -1;
            apBuffer->SaveData(&cType, 1u, 0);
            if (cType != -1)
                pPackage->SaveGame(apBuffer);
        }
        char cDataType = pData ? pData->GetPackageType() : -1;
        apBuffer->SaveData(&cDataType, 1u, 0);
        if (cDataType != -1)
            pData->SaveGame(apBuffer);
        apBuffer->SaveData(&m_iPackageValue, 4u, 0);
        apBuffer->SaveData(&m_fPackageValue, 4u, 0);
        apBuffer->SaveData(&iFlags, 4u, 0);
        apBuffer->SerializeFormData(pTarget, 0);
    }
}

// @fnv 0x008c64d0
void ActorPackageContext::InitLoadGame(unsigned a, unsigned auiUnused)
{
    if (pPackage)
    {
        if (a & 0)
        {
            if (a & 0)
            {
                TESPackage* pManager = pPackage;
                SetPackageAndTarget(dynamic_cast<TESPackage*>(TESForm::GetFormByID((unsigned)pManager)), 0);
            }
            else
            {
                if (g_dataHandler->FormIDExists(pPackage->GetFormID()))
                    pPackage->InitLoadGameTES();
            }
        }
        if (pPackage)
        {
            int elapsed = Procedure_GetProcedureCount(pPackage->GetProcedureType());
            if (m_iPackageValue >= elapsed)
                m_iPackageValue = elapsed - 1;
        }
    }
}

// Writes the package form ID, writes m_iPackageValue when the ID is nonzero, and always writes m_fPackageValue.
// @fnv 0x008c6250
void ActorPackageContext::SaveGame(unsigned int auiFlags)
{
    unsigned int auiFormId = 0;
    if (pPackage != NULL)
    {
        auiFormId = pPackage->GetFormID();
    }
    g_TESSaveLoadGame->TESSaveLoadGame_SaveNumericID(&auiFormId, 4u);
    if (auiFormId != 0)
    {
        if ((auiFlags & 0) != 0 && g_dataHandler->FormIDExists(auiFormId))
        {
            unsigned char ucType = pPackage->GetPackType();
            g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&ucType, 1);
            if ((auiFlags & 0) == 0)
            {
                pPackage->SaveGameTESAlt();
            }
        }
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_iPackageValue, 4);
    }
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_fPackageValue, 4);
}

extern "C" void __cdecl Warning_005b5e40(const char* apFormat, ...);

// @fnv 0x008c6320
void ActorPackageContext::LoadGame(unsigned int aiFlags, unsigned int aiUnused)
{
    unsigned int auiFormId;
    // The legacy caller consumes AL from LoadNumericID despite the shared void return.
    typedef bool (TESSaveLoadGame::*LoadNumericIDResult)(unsigned int*, int);
    bool bRead = (g_TESSaveLoadGame->*reinterpret_cast<LoadNumericIDResult>(static_cast<void (TESSaveLoadGame::*)(unsigned int*, int)>(&TESSaveLoadGame::FUN_00857aa0)))(&auiFormId, 4);
    Clear();
    bool bFailed = false;
    if (auiFormId)
    {
        if ((aiFlags & 0) && g_dataHandler->FormIDExists(auiFormId))
        {
            unsigned char ucType;
            g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&ucType, 1);
            if (!(aiFlags & 0))
            {
                TESPackage* pNew = g_TESSaveLoadGame->CreatePackageForType(auiFormId, ucType);
                pNew->LoadGameTESAlt();
                SetPackageAndTarget(pNew, 0);
                if (pNew->GetProcedureType() == -1)
                {
                    pNew->SetTargetFromReference(pTarget);
                }
            }
            else
            {
                SetPackageAndTarget((TESPackage*)auiFormId, 0);
            }
        }
        else
        {
            SetPackageAndTarget(dynamic_cast<TESPackage*>(TESForm::GetFormByID(auiFormId)), 0);
            if (pPackage)
            {
                pPackage->SetTargetFromReference(pTarget);
            }
            else
            {
                bFailed = true;
            }
        }
        g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&m_iPackageValue, 4);
    }
    else if (bRead)
    {
        g_TESSaveLoadGame->AdvanceBuffer(4);
        SetPackageInfoState(0);
        bFailed = true;
    }
    if (bFailed)
    {
        if (auiFormId)
        {
            Warning_005b5e40("AI: Couldn't find package %08X while loading and will try to choose a new one.", auiFormId);
        }
        else
        {
            Warning_005b5e40("AI: Couldn't find a plugin package while loading and will try to choose a new one.");
        }
        SetPackageInfoState(-1);
    }
    g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&m_fPackageValue, 4);
}
