// fallout_shared/tesobjectimod.cpp: TESObjectIMOD (14 functions)

#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSPickupPutdownSounds.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESForm.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/TESFullName.h"
#include "../../include/TESIcon.h"
#include "../../include/TESTexture.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESValueForm.h"
#include "../../include/TESWeightForm.h"
#include "../../include/TESDescription.h"
#include "../../include/TESObjectIMOD.h"

extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)

#include "../../include/ENUM_FORM_ID.h"

// Access to TESForm serialization entry points absent from its shared header.
// This adds declarations only; all layout and virtual slots come from TESForm.
class TESFormSerialization : public TESForm
{
  public:
    unsigned short GetSaveSizeLegacy(unsigned int flags);
    void SaveHeader();
};

class TESModelRecordWriter : public TESModel
{
  public:
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};

class PickupPutdownSoundRecordWriter : public BGSPickupPutdownSounds
{
  public:
    void LogFormIDs();
};

// @fnv 0x00519fc0
void TESObjectIMOD::InitItem()
{
    if (IsFormInitialized())
        return;
    TESScriptableForm::InitItem(this);
    BGSDestructibleObjectForm::InitItem(this);
    TESModelTextureSwap::InitItem(this);
    BGSPickupPutdownSounds::InitItem(this);
    SetInitializationState(true);
}

// Loads a TESObjectIMOD record: reads the header, then dispatches each chunk to its loader until no chunks remain, returning true.
// @fnv 0x0051a030
bool TESObjectIMOD::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunkID;
    while ((chunkID = (int)file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {  // EDID
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:  // FULL
            TESFullName::LoadFullNameChunk(this, file);
            break;
        case 0x4c444f4d:  // MODL
        case 0x44444f4d:  // MODD
        case 0x54444f4d:  // MODT
        case 0x44534f4d:  // MOSD
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {  // MODS
            struct TextureSwapChunk
            {
                unsigned int size;
                void* data;
            } swaps;
            swaps.size = file->GetChunkSize();
            swaps.data = _alloca(swaps.size);
            file->GetChunkData(swaps.data, swaps.size);
            ParseTextureSwapData(swaps.data, swaps.size, file->GetFormVersion());
            break;
        }
        case 0x4e4f4349:  // ICON
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x4f43494d:  // MICO
            BGSMessageIcon::LoadMessageIconChunk(this, file);
            break;
        case 0x49524353: {  // SCRI
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            SetScript(reinterpret_cast<Script*>(scriptID));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x43534544:  // DESC
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 0x54534544:  // DEST
        case 0x44545344:  // DSTD
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case 0x4d414e59: {  // YNAM
            unsigned int soundID = 0;
            file->GetChunkData(&soundID);
            SetPickupSound(reinterpret_cast<TESSound*>(soundID));
            break;
        }
        case 0x4d414e5a: {  // ZNAM
            unsigned int soundID = 0;
            file->GetChunkData(&soundID);
            SetPutdownSound(reinterpret_cast<TESSound*>(soundID));
            break;
        }
        case 0x41544144:  // DATA
            ReadTypedData(file, 0, 0);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x00519cc0
TESObjectIMOD::TESObjectIMOD()
{
    SetFormType(ENUM_FORM_ID_IMOD_ID);
    SetInitializationState(true);
}

// @fnv 0x0051a5d0
void TESObjectIMOD::LoadGameLegacy(unsigned int arg1, unsigned int arg2)
{
    TESForm::LoadGameLegacy(arg1, arg2);
    TESValueForm::LoadGame_0048ea10(arg1, arg2);
}

// @fnv 0x0051a630
void TESObjectIMOD::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    TESValueForm::LoadGame(buffer);
}

extern "C" void __cdecl _Deallocate(void*);

// @fnv 0x00519e40
void* TESObjectIMOD::Destroy(unsigned int flags)
{
    TESObjectIMOD::~TESObjectIMOD();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x0051a550
unsigned short TESObjectIMOD::GetSaveSizeLegacy(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<TESFormSerialization*>(this)->GetSaveSizeLegacy(aiFlags);
    isize += TESValueForm::GetFlaggedDataSize(aiFlags);
    return isize;
}

// @fnv 0x0051a5a0
void TESObjectIMOD::SaveGameLegacy(unsigned int aiFlags)
{
    TESForm::SaveGameLegacy(aiFlags);
    TESValueForm::SaveGame_0048e9e0(aiFlags);
}

// @fnv 0x0051a600
void TESObjectIMOD::SaveGame(BGSSaveFormBuffer* buffer)
{
    TESForm::SaveGame(buffer);
    TESValueForm::SaveGameBGS_0048ea40(buffer);
}

// @fnv 0x0051a420
void TESObjectIMOD::SaveRecord()
{
    TESForm::BeginFormRecord();
    TESFullName::Save_00487010();
    reinterpret_cast<TESModelRecordWriter*>(reinterpret_cast<char*>(this) + 0x3c)->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    TESIcon::Save(0x4e4f4349);
    BGSMessageIcon::Save(0x4f43494d);
    TESScriptableForm::Save();
    TESDescription::Save();
    BGSDestructibleObjectForm::Save();
    reinterpret_cast<PickupPutdownSoundRecordWriter*>(reinterpret_cast<char*>(this) + 0xa4)->LogFormIDs();
    reinterpret_cast<TESFormSerialization*>(this)->SaveHeader();
    TESForm::FinishFormRecord();
}

// @fnv 0x0051a4c0
void TESObjectIMOD::CopyFrom(const TESForm* apCopy)
{
    const TESObjectIMOD* pmisc = dynamic_cast<const TESObjectIMOD*>(apCopy);
    if (!pmisc)
        return;
    TESForm::CopyFrom(apCopy);
}

// @fnv 0x0051a500
bool TESObjectIMOD::Compare(TESForm* apCompare)
{
    TESObjectIMOD* pcomp;
    pcomp = dynamic_cast<TESObjectIMOD*>(apCompare);
    if (!pcomp)
        return true;
    if (TESForm::Compare(pcomp))
        return true;
    return false;
}

// @fnv 0x00519e70
TESObjectIMOD::~TESObjectIMOD()
{
    Shutdown();
}

struct FUN_0051a840 : TESBoundObject,
                      TESFullName,
                      TESModelTextureSwap,
                      TESIcon,
                      TESScriptableForm,
                      TESValueForm,
                      TESWeightForm,
                      BGSDestructibleObjectForm,
                      BGSMessageIcon,
                      BGSPickupPutdownSounds
{
    virtual ~FUN_0051a840();
    void FUN_00483710();
};
// @fnv 0x0051a840
FUN_0051a840::~FUN_0051a840()
{
    FUN_00483710();
}
