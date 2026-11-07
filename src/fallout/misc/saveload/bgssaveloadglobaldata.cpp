#include "../../../../include/ProcessLists.h"
// fallout/misc/saveload/bgssaveloadglobaldata.cpp: SaveGameLoader (23 functions)

#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/CombatManager.h"
#include "../../../../include/BSPortal.h"
#include "../../../../include/ImageSpaceModifierInstanceForm.h"
#include "../../../../include/TES.h"
#include "../../../../include/TESWorldSpace.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/TESGlobal.h"
#include "../../../../include/TESDataHandler.h"
#include "../../../../include/NiTimeController.h"
#include "../../../../include/FalloutRadio.h"
#include "../../../../include/BGSSaveLoadGame.h"
#include "../../../../include/BGSReconstructFormsInAllFilesMap.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/ImageSpaceModifierInstance.h"
#include "../../../../include/ImageSpaceModifierInstanceDOF.h"
#include "../../../../include/Sky.h"
#include "../../../../include/TESImageSpaceModifier.h"

// This routine is absent from the shared reconstruct-map interface.
extern "C" void ReconstructGlobal();
// Additional cell helpers absent from the shared interfaces; preserve their thiscall ABI.
extern "C" void WorldSpaceIsFlag8Set();
extern "C" void WorldSpaceContainsPoint();
extern "C" void WorldSpaceCreateCell();
extern "C" void DataHandlerGetOrCreateCell();
extern "C" void DataHandlerCreateCell();

class NiAVObject;
class NiTexture;
class NiNode;
class BGSPerkEntry;
extern TES* g_TES;
class ScreenSplatter
{
  public:
    static void Clear();
};
class ScreenCustomSplatter
{
  public:
    static void Clear();
};
BSPortal* Main_GetMasterParticleSystemManager();
// Exe 0x0084d160: unit-local Interface view; declarations and layout are preserved.
class BgssaveloadglobaldataInterfaceView
{
  public:
    static void ApplyLoadBuffer(BGSLoadGameBuffer*);
    static void Revert(BGSLoadGameBuffer*);
    static void LoadGame(BGSLoadGameBuffer*);
    static void PrintDebugMessage(BGSLoadGameBuffer*);
};

extern float DAT_011c3c08;

class GlobalObject_0096d020
{
};
extern GlobalObject_0096d020 g_011e0e80;
void MiscStatManager_Revert(BGSLoadGameBuffer*);
void ResetRadioGlobals(BGSLoadGameBuffer*);
class MagicItem;

void BGSSaveLoadGlobalData_LoadGlobals(BGSLoadGameBuffer*);
void ReadSavedSettings(BGSLoadGameBuffer*);
void FalloutRadio_LoadGame(BGSLoadGameBuffer*);
class SoundPlaybackManager
{
  public:
    static void LoadGame(BGSLoadGameBuffer*);
};

#include "../../../../include/NiBound.h"
#include "../../../../include/MagicCaster.h"
#include "../../../../include/ActorCause.h"
class TESObjectCELL;



extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;


class SaveGameLoader
{
  public:
    static void LoadGameData(BGSLoadGameBuffer*);
    static void FreeChangeData();
    static void UnloadGameData();
    static bool LoadFormType(unsigned int, BGSLoadGameBuffer*);
    static void LoadEffects(BGSLoadGameBuffer*);
    static bool LoadFormRange(unsigned int, BGSLoadGameBuffer*, bool);
    static bool LoadGlobalDataRange(unsigned int, BGSLoadGameBuffer*);
    static bool LoadGlobalDataType(unsigned int type, BGSLoadGameBuffer* buffer);
};

void __cdecl LogWarning(const char* format, ...);
extern "C" void fnv_call_975af0();
extern "C" void fnv_call_66e810();
extern "C" void fnv_call_836af0();
extern "C" void fnv_call_845cc0();

// @fnv 0x0084d160
void SaveGameLoader::UnloadGameData()
{
    ScreenSplatter::Clear();
    ScreenCustomSplatter::Clear();
    Main_GetMasterParticleSystemManager()->BSPortal::~BSPortal();
    BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* node = (BSSimpleList<NiPointer<ImageSpaceModifierInstance> >*)g_TES->FUN_0043b5d0();
    while (node)
    {
        ImageSpaceModifierInstance* effect =
            (ImageSpaceModifierInstance*)((NiPointer<NiNode>*)&((BSSimpleList<BGSPerkEntry*>*)node)->GetItem())
                ->
                operator->();
        if (effect && !effect->IsFlagSet())
        {
            NiPointer<NiAVObject> ref((NiAVObject*)effect);
            ((BSSimpleList<NiPointer<NiAVObject> >*)node)->Remove(ref);
            continue;
        }
        else
        {
            if (effect)
                ((ImageSpaceModifierInstanceDOF*)effect)->FUN_0063f790(0.0f);
        }
        node = (BSSimpleList<NiPointer<ImageSpaceModifierInstance> >*)((BSSimpleList<BGSPerkEntry*>*)node)->GetNext();
    }
}

// Dispatches loading of global game data by type to the matching loader, logging an error for unknown types.
// @fnv 0x0084c190
bool SaveGameLoader::LoadFormType(unsigned int type, BGSLoadGameBuffer* buffer)
{
    switch (type)
    {
    case 1:
        return false;
    case 2:
        g_TES->ProcessItems(buffer);
        return true;
    case 3:
        return false;
    case 4:
        return false;
    case 5:
        ((CombatManager*)BGSSaveLoadGlobalDataWorldspacePtr)->ApplyLoadBuffer(buffer);
        return true;
    case 6:
        BgssaveloadglobaldataInterfaceView::ApplyLoadBuffer(buffer);
        return true;
    case 7:
        return false;
    case 0:
        return false;
    case 8:
        return false;
    case 9:
        return false;
    case 10:
        FalloutRadio::ApplyLoadBuffer(buffer);
        return true;
    case 11:
        return false;
    case 1000:
        return false;
    default:
        LogWarning("DEFAULT: Unknown global data type %i in FinishLoadGlobalData()", type);
        return false;
    }
}

// @fnv 0x0084d070
void SaveGameLoader::LoadEffects(BGSLoadGameBuffer* buffer)
{
    unsigned int count = buffer->ReadElementCount();
    for (unsigned int i = 0; i < count; ++i)
    {
        float strength = 0.0f;
        buffer->ReadDataBlock(&strength, 4);
        TESImageSpaceModifier* modifier;
        {
            float age = 0.0f;
            if (buffer->GetVersion() >= 14)
                buffer->ReadDataBlock(&age, 4);
            modifier = 0;
            modifier = dynamic_cast<TESImageSpaceModifier*>(TESForm::GetFormByID(buffer->ReadFormIdentifier()));
            if (modifier)
            {
                ImageSpaceModifierInstanceForm* instance =
                    ImageSpaceModifierInstanceForm::Trigger(modifier, strength, 0);
                if (instance)
                    instance->SetPad5(DAT_011c3c08 - age);
            }
        }
    }
}

// Dispatches on a global data type to revert the matching subsystem from the load buffer, returning false for unsupported types.
// @fnv 0x0084c330
bool SaveGameLoader::LoadFormRange(unsigned int type, BGSLoadGameBuffer* buffer, bool globals)
{
    switch (type)
    {
    case 1:
        return false;
    case 2:
        g_TES->TES_Revert(buffer);
        return true;
    case 3:
        if (globals)
        {
            FreeChangeData();
            return true;
        }
        return false;
    case 4:
        ((FalloutRadio*)&g_011e0e80)->Revert(buffer);
        return true;
    case 5:
        ((CombatManager*)BGSSaveLoadGlobalDataWorldspacePtr)->FUN_00993800(buffer);
        return true;
    case 6:
        BgssaveloadglobaldataInterfaceView::Revert(buffer);
        return true;
    case 7:
        UnloadGameData();
        return true;
    case 0:
        MiscStatManager_Revert(buffer);
        return true;
    case 8:
        return false;
    case 9:
        ActorCause::ClearActorCauseList(buffer);
        return true;
    case 10:
        ResetRadioGlobals(buffer);
        return true;
    case 11:
        BgssaveloadglobaldataInterfaceView::PrintDebugMessage(buffer);
        return true;
    case 1000:
        ((ProcessLists*)&g_011e0e80)->Revert(buffer);
        return true;
    default:
        LogWarning("DEFAULT: Unknown global data type %i in RevertGlobalData()", type);
        return false;
    }
}

// Dispatches loading of global game data to the handler for the given type, returning false and logging an error for unknown types.
// @fnv 0x0084be40
bool SaveGameLoader::LoadGlobalDataRange(unsigned int type, BGSLoadGameBuffer* buffer)
{
    switch (type)
    {
    case 1:
        LoadGameData(buffer);
        return true;
    case 2:
        g_TES->LoadGame(buffer);
        return true;
    case 3:
        BGSSaveLoadGlobalData_LoadGlobals(buffer);
        return true;
    case 4:
        ((FalloutRadio*)&g_011e0e80)->LoadGame(buffer);
        return true;
    case 5:
        ((CombatManager*)BGSSaveLoadGlobalDataWorldspacePtr)->LoadGame(buffer);
        return true;
    case 6:
        BgssaveloadglobaldataInterfaceView::LoadGame(buffer);
        return true;
    case 7:
        LoadEffects(buffer);
        return true;
    case 0:
        ReadSavedSettings(buffer);
        return true;
    case 8:
        Sky::GetInstance()->LoadGame(buffer);
        return true;
    case 9:
        ActorCause::LoadReferencesFromBuffer(buffer);
        return true;
    case 10:
        FalloutRadio_LoadGame(buffer);
        return true;
    case 11:
        SoundPlaybackManager::LoadGame(buffer);
        return true;
    case 1000:
        ((MagicCaster*)&g_011e0e80)->MagicCaster::SetSelectedMagicItem((MagicItem*)buffer);
        return true;
    default:
        LogWarning("SAVELOAD: Unknown global data type %i in LoadGlobalData()", type);
        return false;
    }
}

extern int _data_011c16bc;
class SaveLoadFile;
void __cdecl ReadFileIntoBuffer(SaveLoadFile*, unsigned int*, unsigned int);

// Reads count entries from file, each a type followed by a buffer, and loads each global data range.
// @fnv 0x0084bc20
void __cdecl LoadGlobalDataRanges(SaveLoadFile* file, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        BGSLoadGameBuffer buffer;
        {
            unsigned int type = 0;
            ReadFileIntoBuffer(file, &type, 4);
            buffer.ReadAndVerifySize(file);
            SaveGameLoader::LoadGlobalDataRange(type, &buffer);
        }
    }
}

// @fnv 0x0084bfb0
// src: XBOX_PDB 0x0084bfb0
void __cdecl BGSSaveLoadGlobalData_InitGlobalDataRange(unsigned int start, unsigned int end)
{
    BGSLoadGameBuffer buffer;
    for (unsigned int i = start; i < end; ++i)
    {
        SaveGameLoader::LoadGlobalDataType(i, &buffer);
    }
}

struct G975
{
    void fnv_call_975af0(BGSLoadGameBuffer*);
};
// @fnv 0x0084c030
// src: XBOX_PDB 0x0084c030
bool __cdecl BGSSaveLoadGlobalData_InitGlobalDataRange_0084c030(unsigned int type, BGSLoadGameBuffer* buffer)
{
    switch (type)
    {
    case 1:
        return false;
    case 2:
        return false;
    case 3:
        return false;
    case 4:
        ((G975*)&g_011e0e80)->fnv_call_975af0(buffer);
        return true;
    case 5:
        ((CombatManager*)BGSSaveLoadGlobalDataWorldspacePtr)->InitLoadGame_00993600(buffer);
        return true;
    case 6:
        return false;
    case 7:
        return false;
    case 0:
        return false;
    case 8:
        return false;
    case 9:
        ((void(__cdecl*)(BGSLoadGameBuffer*))fnv_call_66e810)(buffer);
        return true;
    case 10:
        ((void(__cdecl*)(BGSLoadGameBuffer*))fnv_call_836af0)(buffer);
        return true;
    case 11:
        return false;
    case 1000:
        return false;
    }
    ((void(__cdecl*)(const char*, unsigned int))fnv_call_845cc0)(
        "DEFAULT: Unknown global data type %i in InitGlobalData()", type);
    return false;
}

namespace fnv_0084c110 {

// @fnv 0x0084c110
// src: XBOX_PDB 0x0084c110
void __cdecl BGSSaveLoadGlobalData_FinishLoadGlobalDataRange(unsigned int aiStart, unsigned int aiEnd)
{
    BGSLoadGameBuffer loadGameBuffer;
    for (unsigned int i = aiStart; i < aiEnd; ++i)
        SaveGameLoader::LoadFormType(i, &loadGameBuffer);
}
}  // namespace fnv_0084c110

struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveLoadChangesMap;
struct SaveLoadFile;
struct FormIDConverter;
struct SaveLoadChangeHistory;
struct LoadGameSubBufferQueue;
struct BGSSaveLoadReferencesMap;
struct IDebugText;
struct TESObjectCELL;
struct blob4
{
    char b[4];
};

typedef char _sizecheck_BGSSaveLoadGame[sizeof(BGSSaveLoadGame) == 588 ? 1 : -1];

// Sets or clears bit 0x40 in the flags field according to abValue.
// @fnv 0x0084cc40
// src: XBOX_PDB 0x0084cc40
void BGSSaveLoadGame::SetPlayerLocationInvalid_0084cc40(bool abValue)
{
    if (abValue)
        iGlobalFlags |= 0x40;
    else
        iGlobalFlags &= ~0x40;
}

// @fnv 0x0084d050
bool ImageSpaceModifierInstance::IsFlagSet()
{
    return (iFlags & 1) ? true : false;
}

// @fnv 0x0084c580
unsigned int __fastcall GetDataHandlerField208(TESDataHandler* handler)
{
    return *(unsigned int*)((char*)handler + 0x208);
}


extern TESDataHandler* g_dataHandler;

// @fnv 0x0084cc90
// src: COMMUNITY 0x0084cc90
void BGSSaveLoadGlobalData_SaveGlobals(BGSSaveFormBuffer* apBuffer)
{
    BSSimpleList<TESGlobal*>* pList = g_dataHandler->GetTESGlobalList();
    int iCount = 0;
    unsigned int uiStart = apBuffer->StartVariableSizedValue();
    BSSimpleList<TESGlobal*>* pIter = pList;
    while (pIter)
    {
        TESGlobal* pGlobalForm = pIter->GetItem();
        if (pGlobalForm && !pGlobalForm->IsConstantGlobal())
        {
            apBuffer->SerializeFormData(pGlobalForm, 0);
            float fValue = pGlobalForm->GetValue();
            apBuffer->SaveData(&fValue, 4, 0);
            ++iCount;
        }
        pIter = pIter->GetNext();
    }
    apBuffer->SaveVariableSizedValue_00865ff0(iCount, uiStart);
}

namespace fnv_00866200 {
struct SaveLoadFile
{
    void WriteToFile(const void* apData, unsigned int auiSize);
};

struct PackedFormID
{
    unsigned char m_ucIDByte0;
    unsigned char m_ucIDByte1;
    unsigned char m_ucIDByte2;
    void WriteFormIDBytes(unsigned int auiFormID);
};

struct BGSSaveLoadChangeFlags
{
    unsigned char cFlags1;
    unsigned char cFlags2;
    unsigned char cFlags3;
    unsigned char cFlags4;
};

struct BGSSaveLoadFormType
{
    unsigned char m_ucFormType;
    int BGSSaveLoadFormInfo_GetSizeType();
};

struct FormLoadContext
{
    PackedFormID iFormID;
    BGSSaveLoadChangeFlags m_pDeathItem;
    BGSSaveLoadFormType m_ucFormType;
    unsigned char cVersion;
    FormLoadContext();
};

int __cdecl ReadValueBySizeType(const char* apBuffer, unsigned int* apValue, int aiSize);
void __cdecl WriteValueByType(SaveLoadFile* apFile, unsigned int auiValue, int aiSize);

struct FUN_00866200_owner
{
    char* pBuffer;
    void BGSUnloadedFormBuffer_Save(SaveLoadFile* apFile, unsigned int auiFormID, BGSSaveLoadChangeFlags aChangeFlags);
};

// @fnv 0x00866200
// src: COMMUNITY 0x00866200
void FUN_00866200_owner::BGSUnloadedFormBuffer_Save(SaveLoadFile* apFile, unsigned int auiFormID, BGSSaveLoadChangeFlags aChangeFlags)
{
    char* pData = pBuffer;
    char* pCurrent = pBuffer + 2;
    FormLoadContext header;
    header.iFormID.WriteFormIDBytes(auiFormID);
    header.m_pDeathItem = aChangeFlags;
    header.m_ucFormType.m_ucFormType = pData[0];
    header.cVersion = pData[1];
    apFile->WriteToFile(&header, 9);
    int iSize = header.m_ucFormType.BGSSaveLoadFormInfo_GetSizeType();
    unsigned int uiValue = 0;
    pCurrent += ReadValueBySizeType(pCurrent, &uiValue, iSize);
    WriteValueByType(apFile, uiValue, iSize);
    if (uiValue)
        apFile->WriteToFile(pCurrent, uiValue);
}
}  // namespace fnv_00866200

namespace fnv_00975840 {

struct SavedItem
{
    void SaveToStream(BGSSaveFormBuffer* apBuffer);
};

struct ItemListNode
{
    SavedItem*& FUN_006815c0();
    ItemListNode* FUN_00726070();
};

struct FUN_00975840_owner
{
    void ProcessLists_SaveGame(BGSSaveFormBuffer* apBuffer);
};

// @fnv 0x00975840
// src: COMMUNITY 0x00975840
void FUN_00975840_owner::ProcessLists_SaveGame(BGSSaveFormBuffer* apBuffer)
{
    apBuffer->SaveData((char*)this + 0x154, 4, 0);
    apBuffer->SaveData((char*)this + 0x158, 4, 0);
    apBuffer->SaveData((char*)this + 0x103b4, 4, 0);
    apBuffer->SaveData((char*)this + 0x103b8, 4, 0);
    for (unsigned int i = 0; i < 5; ++i)
    {
        unsigned int ItemUpdateArray = 0;
        unsigned int uiStart = apBuffer->StartVariableSizedValue();
        ItemListNode* pIter = ((ItemListNode**)((char*)this + 0x44))[i];
        while (pIter)
        {
            SavedItem* pSavedItem = pIter->FUN_006815c0();
            if (pSavedItem)
            {
                pSavedItem->SaveToStream(apBuffer);
                ++ItemUpdateArray;
            }
            pIter = pIter->FUN_00726070();
        }
        apBuffer->SaveVariableSizedValue_00865ff0(ItemUpdateArray, uiStart);
    }
}
}  // namespace fnv_00975840

// Sets or clears bit 0x20 in the flags word at offset 0x244 based on the set argument.
// @fnv 0x0084cbf0
void BGSSaveLoadGame::SetPositioningPlayerCharacter(bool set)
{
    if (set)
        ((unsigned int*)((char*)this + 0x244))[0] |= 0x20;
    else
        ((unsigned int*)((char*)this + 0x244))[0] &= 0xffffffdf;
}

namespace fnv_0084ced0 {
extern BGSSaveLoadGame* g_BGSSaveLoadGame;

extern TESDataHandler* g_dataHandler;

// Iterates the data handler's TESGlobal list and calls FUN_00843630 on each global through the save-load reconstruct map.
// @fnv 0x0084ced0
void ReconstructAllGlobals()
{
    BSSimpleList<TESGlobal*>* pGlobalList;
    BGSReconstructFormsInAllFilesMap* pReconstructMap;
    pReconstructMap = g_BGSSaveLoadGame->_FNV_GetObjectReference();
    pGlobalList = g_dataHandler->GetTESGlobalList();
    while (pGlobalList)
    {
        TESGlobal* pglobal;
        pglobal = pGlobalList->GetItem();
        ((void (__thiscall*)(BGSReconstructFormsInAllFilesMap*, TESGlobal*, int))ReconstructGlobal)(pReconstructMap, pglobal, 0);
        pGlobalList = pGlobalList->GetNext();
    }
}
}  // namespace fnv_0084ced0

union LLD_SettingValue
{
    bool b;
    float f;
    const char* s;
};
class LLD_INISettingCollection;
template <class T> class LLD_SettingT
{
  public:
    LLD_SettingValue* Bool();
    const char* String();
};
extern LLD_SettingT<LLD_INISettingCollection> g_011e08e0;
extern LLD_SettingT<LLD_INISettingCollection> g_011de25c;
struct LLD_Point3
{
    float x;
    float y;
    float z;
    LLD_Point3();
};
struct LLD_FullName
{
    const char* GetFullName();
};
struct LLD_FullNameLen
{
    unsigned int GetModelLength();
};
class LLD_Cell;

class LLD_Quest : public TESForm
{
  public:
    unsigned int GetFormID();
};
class LLD_PlayerCharacter : public TESObjectREFR
{
  public:
    void PlayerCharacter_PositionPlayer(LLD_Point3, LLD_Point3, LLD_Cell*, bool);
    void PlayerCharacter_PositionPlayerExterior(LLD_Point3, LLD_Point3, TESWorldSpace*, bool);
    void PlayerCharacter_CenterOnCell(int, LLD_Cell*);
    void SetCameraPathEnabled(bool, unsigned int);
};
class LLD_Cell
{
  public:
    NiNode* Get3D_00545cb0();
    void RemoveReference(TESObjectREFR*);
};

// This TES cell helper is absent from the shared interface; preserve its thiscall ABI.
extern "C" void TESUpdateCellPosition();

class LLD_LoadingMenu
{
  public:
    static void LoadGame(BGSLoadGameBuffer*);
};
int __fastcall FNV_GetFormType(TESForm*);
int __cdecl TruncateFloatToInt(float);
void __cdecl BSprintf(const char*, ...);
char* __cdecl FUN_00ec7750(const char*, const char*);
unsigned int __cdecl FUN_00ec8d08(const char*, char**, int);
void __cdecl GarbageCollector_ClearAll(int);
void __cdecl NiObjectGarbage_ClearAll(int);
class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
extern TESDataHandler* g_dataHandler;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;

// @fnv 0x0084c5a0
void LoadPlayerLocation(BGSLoadGameBuffer* apLoadGameBuffer)
{
    TESForm* plocation;
    TESWorldSpace* ptesWorldSpace;
    int icurrentGridY;
    unsigned int inextID;
    int icurrentGridX;
    bool bvalidPlayerLocation;

    apLoadGameBuffer->ReadDataBlock(&inextID, 4);
    ptesWorldSpace = dynamic_cast<TESWorldSpace*>(TESForm::GetFormByID(apLoadGameBuffer->ReadFormIdentifier()));
    apLoadGameBuffer->ReadDataBlock(&icurrentGridX, 4);
    apLoadGameBuffer->ReadDataBlock(&icurrentGridY, 4);
    plocation = TESForm::GetFormByID(apLoadGameBuffer->ReadFormIdentifier());
    LLD_Point3 playerLocation;
    apLoadGameBuffer->ReadDataBlock(&playerLocation, 12);
    LLD_LoadingMenu::LoadGame(apLoadGameBuffer);
    bvalidPlayerLocation = true;

    if (plocation)
    {
        if (FNV_GetFormType(plocation) == 0x39)
        {
            LLD_Cell* pcell = (LLD_Cell*)plocation;
            if (((LLD_PlayerCharacter*)g_thePlayer)->GetParentCell() != (TESObjectCELL*)pcell)
                ((LLD_PlayerCharacter*)g_thePlayer)
                    ->PlayerCharacter_PositionPlayer(playerLocation, ((LLD_PlayerCharacter*)g_thePlayer)->GetAngle(), pcell, false);
            if (ptesWorldSpace)
                g_TES->AssignWorldSpace(ptesWorldSpace);
            g_TES->SetCurrentGridX(icurrentGridX);
            g_TES->SetCurrentGridY(icurrentGridY);
        }
        else if (FNV_GetFormType(plocation) == 0x41)
        {
            if (ptesWorldSpace)
                g_TES->AssignWorldSpace(ptesWorldSpace);
            TESWorldSpace* pworld = (TESWorldSpace*)plocation;
            if (((bool (__thiscall*)(TESWorldSpace*))WorldSpaceIsFlag8Set)(pworld) && g_011e08e0.Bool()->b &&
                !((bool (__thiscall*)(TESWorldSpace*, LLD_Point3*))WorldSpaceContainsPoint)(pworld, &playerLocation))
                bvalidPlayerLocation = false;
            if (bvalidPlayerLocation)
            {
                LLD_Point3 centerGridLocation;
                int icellX;
                LLD_Cell* pcell;
                int icellY;
                centerGridLocation.x = (float)(icurrentGridX << 12);
                centerGridLocation.y = (float)(icurrentGridY << 12);
                centerGridLocation.z = 0.0f;
                g_TES->FindCellAtPosition((const NiPoint3*)&centerGridLocation, false);
                g_TES->RefreshWorldState(1, plocation, 0);
                icellX = TruncateFloatToInt(playerLocation.x) >> 12;
                icellY = TruncateFloatToInt(playerLocation.y) >> 12;
                pcell = ((LLD_Cell* (__thiscall*)(TESDataHandler*, int, int, TESWorldSpace*, bool))DataHandlerGetOrCreateCell)(g_dataHandler, icellX, icellY, pworld, false);
                if (!pcell || !pcell->Get3D_00545cb0())
                {
                    if (((LLD_PlayerCharacter*)g_thePlayer)->GetParentCell())
                        ((LLD_Cell*)((LLD_PlayerCharacter*)g_thePlayer)->GetParentCell())->RemoveReference((LLD_PlayerCharacter*)g_thePlayer);
                    ((void (__thiscall*)(TES*, LLD_Point3*))TESUpdateCellPosition)(g_TES, &centerGridLocation);
                    pcell = ((LLD_Cell* (__thiscall*)(TESDataHandler*, int, int, TESWorldSpace*, bool))DataHandlerGetOrCreateCell)(g_dataHandler, icellX, icellY, pworld, true);
                }
                if (pcell)
                {
                    g_BGSSaveLoadGame->SetPositioningPlayerCharacter(true);
                    ((LLD_PlayerCharacter*)g_thePlayer)
                        ->PlayerCharacter_PositionPlayer(playerLocation, ((LLD_PlayerCharacter*)g_thePlayer)->GetAngle(), pcell, false);
                    g_BGSSaveLoadGame->SetPositioningPlayerCharacter(false);
                }
                else
                    bvalidPlayerLocation = false;
            }
        }
        else
            bvalidPlayerLocation = false;
    }
    else
        bvalidPlayerLocation = false;

    if (!bvalidPlayerLocation)
    {
        unsigned int isafeMarkerID;
        TESObjectREFR* pref;
        g_BGSSaveLoadGame->SetPlayerLocationInvalid_0084cc40(true);
        BSSimpleList<LLD_Quest*>* pIter = (BSSimpleList<LLD_Quest*>*)g_dataHandler->GetTESQuestList();
        while (pIter && pIter->GetItem())
        {
            BSprintf("Quest %s (%08x) compared to Patch04Debug\n",
                         ((LLD_FullName*)((char*)pIter->GetItem() + 0x30))->GetFullName(),
                         pIter->GetItem()->GetFormID());
            if (((LLD_FullNameLen*)((char*)pIter->GetItem() + 0x30))->GetModelLength() > 8 &&
                FUN_00ec7750(((LLD_FullName*)((char*)pIter->GetItem() + 0x30))->GetFullName(), "Patch04Debug"))
            {
                *(LLD_Quest**)((char*)g_thePlayer + 0xe4c) = pIter->GetItem();
                break;
            }
            pIter = pIter->GetNext();
        }
        ((LLD_PlayerCharacter*)g_thePlayer)->SetCameraPathEnabled(false, 0xff);
        isafeMarkerID = FUN_00ec8d08(g_011de25c.String(), 0, 16);
        pref = dynamic_cast<TESObjectREFR*>(TESForm::GetFormByID(isafeMarkerID));
        if (pref)
        {
            LLD_Point3 loc = *(const LLD_Point3*)static_cast<const TESObjectREFR*>(pref)->GetPos();
            LLD_Point3 angle = pref->GetAngle();
            LLD_Cell* pcell = (LLD_Cell*)pref->GetParentCell();
            TESWorldSpace* pworld = pref->GetParentWorldSpace();
            bvalidPlayerLocation = true;
            if (pworld)
                ((LLD_PlayerCharacter*)g_thePlayer)->PlayerCharacter_PositionPlayerExterior(loc, angle, pworld, true);
            else if (pcell)
                ((LLD_PlayerCharacter*)g_thePlayer)->PlayerCharacter_PositionPlayer(loc, angle, pcell, true);
            else
                bvalidPlayerLocation = false;
        }
        if (!bvalidPlayerLocation)
        {
            TESWorldSpace* pworld = dynamic_cast<TESWorldSpace*>(TESForm::GetFormByID(0xda726));
            if (pworld)
            {
                LLD_Cell* pcell = (LLD_Cell*)pworld->GetCellAtGridPosition(-18, 0);
                if (!pcell)
                    pcell = ((LLD_Cell* (__thiscall*)(TESWorldSpace*, int, int))WorldSpaceCreateCell)(pworld, -18, 0);
                if (!pcell)
                    pcell = (LLD_Cell*)pworld->GetCellAtGridPosition(0, 0);
                if (!pcell)
                    pcell = ((LLD_Cell* (__thiscall*)(TESWorldSpace*, int, int))WorldSpaceCreateCell)(pworld, 0, 0);
                if (!pcell)
                    pcell = ((LLD_Cell* (__thiscall*)(TESDataHandler*, int, int, int, TESWorldSpace*))DataHandlerCreateCell)(g_dataHandler, 0, 0, 0, pworld);
                if (pcell)
                    ((LLD_PlayerCharacter*)g_thePlayer)->PlayerCharacter_CenterOnCell(0, pcell);
            }
        }
    }

    g_TES->TES_ClearAllCells(true, 0);
    GarbageCollector_ClearAll(0);
    NiObjectGarbage_ClearAll(0);
}

void __cdecl SaveLoadScreenData(BGSSaveFormBuffer* pkBuffer);

extern TESDataHandler* g_pkB84C490DataHandler;
extern TES* g_pkB84C490TES;
extern TESObjectREFR* g_pkB84C490Player;

// @fnv 0x0084c490
void __cdecl SavePlayerLocation(BGSSaveFormBuffer* pkBuffer)
{
    unsigned int ItemUpdateArray = GetDataHandlerField208(g_pkB84C490DataHandler);
    pkBuffer->SaveData(&ItemUpdateArray, 4, 0);
    pkBuffer->SerializeFormData(g_pkB84C490TES->GetParentWorldSpace(), 0);
    unsigned int uiGridX = g_pkB84C490TES->GetCurrentGridX();
    int iGridY = g_pkB84C490TES->GetCurrentGridY();
    pkBuffer->SaveData(&uiGridX, 4, 0);
    pkBuffer->SaveData(&iGridY, 4, 0);
    TESForm* pkWorldSpace2 = (TESForm*)g_pkB84C490Player->GetParentWorldSpace();
    if (!pkWorldSpace2)
        pkWorldSpace2 = (TESForm*)g_pkB84C490Player->GetParentCell();
    pkBuffer->SerializeFormData(pkWorldSpace2, 0);
    LLD_Point3 kPos = *(const LLD_Point3*)g_pkB84C490Player->GetPos();
    pkBuffer->SaveData(&kPos, 12, 0);
    SaveLoadScreenData(pkBuffer);
}

void __cdecl SavePlayerLocation(BGSSaveFormBuffer*);
void __cdecl Interface_SaveGame(BGSSaveFormBuffer*);
void __cdecl SaveImageSpaceModifierInstances(BGSSaveFormBuffer*);
void __cdecl SaveMiscStats(BGSSaveFormBuffer*);
void __cdecl SaveE6D0Items(BGSSaveFormBuffer*);
void __cdecl FalloutRadio_SaveGame(BGSSaveFormBuffer*);
void __cdecl TESAudio_SaveGame(BGSSaveFormBuffer*);
void __cdecl SaveGameWarning(const char*, ...);
struct Manager84
{
    void ProcessLists_SaveGame(BGSSaveFormBuffer*);
    void FUN_004534f0(BGSSaveFormBuffer*);
};
// Sky saving is absent from the shared interface; preserve the thiscall ABI.
extern "C" void SaveSkyGame();
// Dispatches saving of global data to a handler based on the type id, logging an error and returning false for unknown types.
// @fnv 0x0084bcd0
// src: COMMUNITY 0x0084bcd0
bool __cdecl BGSSaveLoadGlobalData_SaveGlobalData(unsigned int type, BGSSaveFormBuffer* buffer)
{
    switch (type)
    {
    case 1:
        SavePlayerLocation(buffer);
        return true;
    case 2:
        g_TES->SaveGame(buffer);
        return true;
    case 3:
        BGSSaveLoadGlobalData_SaveGlobals(buffer);
        return true;
    case 4:
        ((Manager84*)&g_011e0e80)->ProcessLists_SaveGame(buffer);
        return true;
    case 5:
        ((CombatManager*)BGSSaveLoadGlobalDataWorldspacePtr)->SaveGame(buffer);
        return true;
    case 6:
        Interface_SaveGame(buffer);
        return true;
    case 7:
        SaveImageSpaceModifierInstances(buffer);
        return true;
    case 0:
        SaveMiscStats(buffer);
        return true;
    case 8:
        ((void (__thiscall*)(Sky*, BGSSaveFormBuffer*))SaveSkyGame)(Sky::GetInstance(), buffer);
        return true;
    case 9:
        SaveE6D0Items(buffer);
        return true;
    case 10:
        FalloutRadio_SaveGame(buffer);
        return true;
    case 11:
        TESAudio_SaveGame(buffer);
        return true;
    case 1000:
        ((Manager84*)&g_011e0e80)->FUN_004534f0(buffer);
        return true;
    default:
        SaveGameWarning("SAVELOAD: Unknown global data type %i in SaveGlobalData()", type);
        return false;
    }
}

struct SaveLoadChangeHistory
{
    void AddGlobal(TESGlobal* global, int flags);
};

struct GlobalSeenMap
{
    GlobalSeenMap(int hashSize);
    ~GlobalSeenMap();
    void SetAt(TESGlobal* key, bool value);
    bool RemoveAt(TESGlobal* key);
    void* GetFirstPos();
    void GetNext(void*& pos, TESGlobal*& key, bool& value);
    int vtbl;
    int hashSize;
    int buckets;
    int count;
};

// @fnv 0x0084cd40
// src: COMMUNITY 0x0084cd40
void BGSSaveLoadGlobalData_LoadGlobals(BGSLoadGameBuffer* pLoadBuffer)
{
    SaveLoadChangeHistory* history5 = g_BGSSaveLoadGame->GetHistory();
    GlobalSeenMap unchanged2(37);
    BSSimpleList<TESGlobal*>* node2 = g_dataHandler->GetTESGlobalList();
    while (node2)
    {
        TESGlobal* globalVal = node2->GetItem();
        if (globalVal)
            unchanged2.SetAt(globalVal, true);
        node2 = node2->GetNext();
    }
    {
        unsigned int count8 = pLoadBuffer->ReadElementCount();
        for (unsigned int aI = 0; aI < count8; aI++)
        {
            TESGlobal* loaded =
                dynamic_cast<TESGlobal*>(TESForm::GetFormByID(pLoadBuffer->ReadFormIdentifier()));
            float value9 = 0.0f;
            pLoadBuffer->ReadDataBlock(&value9, 4);
            if (loaded)
            {
                if (!loaded->IsConstantGlobal())
                    loaded->SetValue(value9);
                unchanged2.RemoveAt(loaded);
            }
        }
    }
    void* pos2 = unchanged2.GetFirstPos();
    while (pos2)
    {
        TESGlobal* key3 = 0;
        bool seen4 = false;
        unchanged2.GetNext(pos2, key3, seen4);
        if (!key3->IsConstantGlobal())
            history5->AddGlobal(key3, 0);
    }
}

// These double-returning time helpers are absent from the shared interfaces.
extern "C" double __cdecl GetImageSpaceModifierSaveTime();
extern "C" void GetImageSpaceModifierStartTime();

// @fnv 0x0084cf30
void __cdecl SaveImageSpaceModifierInstances(int pBuffer)
{
    int aV11;
    BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* i6;
    int v3;
    ImageSpaceModifierInstance* v8_2;
    void* v2;
    float aV6;
    float v5;

    v3 = 0;
    aV11 = ((BGSSaveFormBuffer*)pBuffer)->StartVariableSizedValue();
    i6 = (BSSimpleList<NiPointer<ImageSpaceModifierInstance> >*)g_TES->FUN_0043b5d0();
    while (i6 != 0)
    {
        v8_2 = i6->GetItem().operator->();
        if (v8_2 != 0 && !v8_2->IsFlagSet())
        {
            v2 = v8_2->GetInstanceForm();
            if (v2 != 0)
            {
                aV6 = ((NiBound*)v2)->FUN_0084d030();
                ((BGSSaveFormBuffer*)pBuffer)->SaveData(&aV6, 4, 0);
                v5 = (float)(GetImageSpaceModifierSaveTime() -
                    ((double (__thiscall*)(ImageSpaceModifierInstanceForm*))GetImageSpaceModifierStartTime)(
                        (ImageSpaceModifierInstanceForm*)v2));
                ((BGSSaveFormBuffer*)pBuffer)->SaveData(&v5, 4, 0);
                ((BGSSaveFormBuffer*)pBuffer)->FUN_00865df0((void*)((NiTimeController*)v2)->FUN_00441110(), 0);
                ++v3;
            }
        }
        i6 = i6->GetNext();
    }
    ((BGSSaveFormBuffer*)pBuffer)->SaveVariableSizedValue_00865ff0(v3, aV11);
}

#include <stdarg.h>
void __cdecl FUN_00ecbe60(const char* fmt, va_list args);

// @fnv 0x0084cbd0
// src: COMMUNITY 0x0084cbd0
void __cdecl BSprintf(const char* apFormat, ...)
{
    va_list args;
    va_start(args, apFormat);
    FUN_00ecbe60(apFormat, args);
}
