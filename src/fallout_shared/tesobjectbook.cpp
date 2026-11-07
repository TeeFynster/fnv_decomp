// fallout_shared/tesobjectbook.cpp: TESObjectBOOK, TESObjectMISC, Actor and more (16 functions)

#include "../../include/TESObjectBOOK.h"
#include "../../include/TESForm.h"
#include "../../include/TESValueForm.h"
#include "../../include/Actor.h"
#include "../../include/BookData.h"
#include "../../include/TESDescription.h"
#include "../../include/TESObjectMISC.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/BaseProcess.h"
#include "../../include/FormChangeMask.h"
#include "../../include/TESObjectWEAP.h"

// Unit-specific declarations; game class layouts come from the shared headers.

// TESForm's legacy I/O at 0x00484c20/0x00484c50/0x00484d60/0x00484da0 has no shared declarations.
// Inherit its checked layout and declare only the missing entry points.
struct BookLegacyFormIO : public TESForm
{
    void TESForm_SaveGame(unsigned int);
    void TESForm_LoadGame(unsigned int, unsigned int);
    void SaveIfChanged(BGSSaveFormBuffer*);
    void FUN_00484da0(BGSLoadFormBuffer*);
};

#include <malloc.h>
#include "../../include/ENUM_FORM_ID.h"
#include "../../include/ActorValue.h"
#include "../../include/TESSaveLoadGame.h"
namespace ActorValue {
Index __cdecl GetActorValueForSectionIndex(Section section, unsigned char index);
}
extern "C" void* __cdecl memset(void*, int, unsigned int);
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESFileChunkData16
{
  public:
    bool GetChunkData(unsigned short*);
};

// Zeroes the two bytes at offset 0xc0, sets the byte at 0xc1 to 0xff, and calls the MagicCaster at offset 0x74 with 0.
// @fnv 0x00514830
void TESObjectBOOK::ResetFormData()
{
    memset(&Data, 0, 2);
    Data.m_cCharacterAfterFlags = 0xff;
    reinterpret_cast<MagicCaster*>(reinterpret_cast<char*>(this) + 0x74)->SetSelectedMagicItem(0);
}

// @fnv 0x00514870
void TESObjectBOOK::InitItem()
{
    if (TESForm::IsFormInitialized())
        return;
    reinterpret_cast<TESScriptableForm*>(reinterpret_cast<char*>(this) + 0x68)
        ->InitItem(reinterpret_cast<TESForm*>(this));
    reinterpret_cast<TESEnchantableForm*>(reinterpret_cast<char*>(this) + 0x74)
        ->InitItem(reinterpret_cast<TESForm*>(this));
    reinterpret_cast<BGSDestructibleObjectForm*>(reinterpret_cast<char*>(this) + 0x9c)
        ->InitItem(reinterpret_cast<TESForm*>(this));
    reinterpret_cast<TESModelTextureSwap*>(reinterpret_cast<char*>(this) + 0x3c)
        ->InitItem(reinterpret_cast<TESForm*>(this));
    reinterpret_cast<BGSPickupPutdownSounds*>(reinterpret_cast<char*>(this) + 0xb4)
        ->InitItem(reinterpret_cast<TESForm*>(this));

    if (static_cast<signed char>(Data.m_cCharacterAfterFlags) != -1)
    {
        int actorValue = static_cast<int>(ActorValue::GetActorValueForSectionIndex(
            ActorValue::SKILL, Data.m_cCharacterAfterFlags));
        if (actorValue < 0x20 || actorValue > 0x2e)
            Data.m_cCharacterAfterFlags = 0xff;
    }
    reinterpret_cast<TESForm*>(this)->SetInitializationState(true);
}

// @fnv 0x00514930
bool TESObjectBOOK::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x19)
        return false;

    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
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
        case 0x54444f4d:  // MODT
        case 0x44444f4d:  // MODD
        case 0x44534f4d:  // MOSD
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d:  // MODS
        {
            unsigned int chunkSize = file->GetChunkSize();
            void* swaps = _alloca(chunkSize);
            file->GetChunkData(swaps, chunkSize);
            ParseTextureSwapData(swaps, chunkSize, reinterpret_cast<TESFileFormVersion*>(file)->GetFormVersion());
            break;
        }
        case 0x4e4f4349:  // ICON
            TESTexture::ReadTextureData(static_cast<TESIcon*>(this), file);
            break;
        case 0x4f43494d:  // MICO
            BGSMessageIcon::LoadMessageIconChunk(this, file);
            break;
        case 0x49524353:  // SCRI
        {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            SetScript(reinterpret_cast<Script*>(scriptID));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x4d544945:  // EITM
        case 0x4d414e45:  // ENAM
        {
            unsigned int enchantmentID = 0;
            file->GetChunkData(&enchantmentID);
            SetFormEnchanting(reinterpret_cast<EnchantmentItem*>(enchantmentID));
            break;
        }
        case 0x544d4145:  // EAMT
        case 0x4d414e41:  // ANAM
        {
            unsigned short enchantmentAmount = 0;
            reinterpret_cast<TESFileChunkData16*>(file)->GetChunkData(&enchantmentAmount);
            SetFormEnchantmentAmount(enchantmentAmount);
            break;
        }
        case 0x43534544:  // DESC
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 0x54534544:  // DEST
        case 0x44545344:  // DSTD
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case 0x4d414e59:  // YNAM
        {
            unsigned int pickupID = 0;
            file->GetChunkData(&pickupID);
            SetPickupSound(reinterpret_cast<TESSound*>(pickupID));
            break;
        }
        case 0x4d414e5a:  // ZNAM
        {
            unsigned int putdownID = 0;
            file->GetChunkData(&putdownID);
            SetPutdownSound(reinterpret_cast<TESSound*>(putdownID));
            break;
        }
        case 0x41544144:  // DATA
            ReadTypedData(file, &Data, 2);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0051a6a0
TESObjectMISC::TESObjectMISC()
{
    TESForm::SetFormType(ENUM_FORM_ID_MISC_ID);
    ResetFormData();
    SetInitializationState(true);
}

// @fnv 0x00514500
TESObjectBOOK::TESObjectBOOK()
{
    SetFormType((ENUM_FORM_ID)0x19);
    ResetFormData();
}


// Sums the save sizes of the base and the sub-object at offset 0x84, adding 1 when flags bit 0x20 is set, and returns the total.
// @fnv 0x00515220
// src: XBOX_PDB 0x00515220
unsigned short __thiscall TESObjectBOOK::GetSaveSize_00515220(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += static_cast<unsigned short>(TESForm::GetSaveSize(aiFlags));
    isize += TESValueForm::GetFlaggedDataSize(aiFlags);
    if (aiFlags & 0x20)
        isize += 1;
    return isize;
}

// Preserve the buffer accessor's trivially destructible result ABI while the
// working shared FormChangeMask declaration has an unapproved destructor.
struct BookSaveFlagsResult
{
    unsigned int flags;
    BookSaveFlagsResult(const BookSaveFlagsResult&);
    operator bool() const { return flags != 0; }
};
struct BookSaveBufferFlags
{
    BookSaveFlagsResult GetChangeFlags(unsigned int flags);
};

// @fnv 0x00515340
// src: XBOX_PDB 0x00515340
void TESObjectBOOK::SaveGame_00515340(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<BookLegacyFormIO*>(this)->SaveIfChanged(buffer);
    TESValueForm::SaveGameBGS_0048ea40(buffer);
    if (reinterpret_cast<BookSaveBufferFlags*>(buffer)->GetChangeFlags(0x20).operator bool())
        buffer->SaveData(&Data.m_cCharacterAfterFlags, 1, 0);
}

extern TESSaveLoadGame* g_TESSaveLoadGame;
// @fnv 0x00515290
// src: XBOX_PDB 0x00515290
void TESObjectBOOK::SaveGame_00515290(unsigned int aiFlags)
{
    reinterpret_cast<BookLegacyFormIO*>(this)->TESForm_SaveGame(aiFlags);
    TESValueForm::SaveGame_0048e9e0(aiFlags);
    if (aiFlags & 0x20)
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&Data.m_cCharacterAfterFlags, 1);
}

namespace fnv_005152e0 {
extern TESSaveLoadGame* g_TESSaveLoadGame;
}  // namespace fnv_005152e0
// @fnv 0x005152e0
// src: XBOX_PDB 0x005152e0
void TESObjectBOOK::LoadGame_005152e0(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    reinterpret_cast<BookLegacyFormIO*>(this)->TESForm_LoadGame(aiFlags, aiCurrentFlags);
    TESValueForm::LoadGame_0048ea10(aiFlags, aiCurrentFlags);
    if (aiFlags & 0x20)
        fnv_005152e0::g_TESSaveLoadGame->ReadTypedData(&Data.m_cCharacterAfterFlags, 1);
}

struct S_00487010
{
    void Save_00487010();
};
struct S_0048a520
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct FUN_0048e370_obj
{
    void TESTexture_Save(unsigned int);
};
struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};
struct S_0048cca0
{
    void Save_0048cca0();
};
struct FUN_0047bd70_shell
{
    void FUN_0047bd70();
};
struct FUN_00482cb0_shell
{
    void Save_00482cb0();
};
struct S_00477f20
{
    void FUN_00477f20();
};
struct FUN_0047b560_holder
{
    void LogFormIDs();
};
struct Date
{
    ~Date();
};
bool __cdecl TESForm_QEndianSwapOnSave();

// @fnv 0x00514de0
void TESObjectBOOK::Destroy()
{
    TESForm::BeginFormRecord();
    ((S_00487010*)((char*)this + 0x30))->Save_00487010();
    ((S_0048a520*)((char*)this + 0x3c))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    ((FUN_0048e370_obj*)((char*)this + 0x5c))->TESTexture_Save(0x4e4f4349);
    ((FUN_0047a240_shell*)((char*)this + 0xa4))->FUN_0047a240(0x4f43494d);
    ((S_0048cca0*)((char*)this + 0x68))->Save_0048cca0();
    ((FUN_0047bd70_shell*)((char*)this + 0x74))->FUN_0047bd70();
    ((FUN_00482cb0_shell*)((char*)this + 0x94))->Save_00482cb0();
    ((S_00477f20*)((char*)this + 0x9c))->FUN_00477f20();
    ((FUN_0047b560_holder*)((char*)this + 0xb4))->LogFormIDs();
    if (TESForm_QEndianSwapOnSave())
        ((Date*)((char*)this + 0xc0))->Date::~Date();
    TESForm::TESForm___SaveData((Date*)((char*)this + 0xc0), 2);
    if (TESForm_QEndianSwapOnSave())
        ((Date*)((char*)this + 0xc0))->Date::~Date();
    TESForm::FinishFormRecord();
}

// Destructor of the object; the body is empty.
// @fnv 0x005146d0
TESObjectBOOK::~TESObjectBOOK()
{}

struct FUN_005153a0_arg;
struct FUN_005153a0_ret
{
    bool FUN_004280f0();
};
struct FUN_005153a0_arg
{
    FUN_005153a0_ret* FUN_00428110(unsigned int* out, int size);
    void LoadData(void* p, int n);
};
// @fnv 0x005153a0
// src: XBOX_PDB 0x005153a0
void TESObjectBOOK::LoadGame_005153a0(BGSLoadFormBuffer* buffer)
{
    unsigned int local;
    reinterpret_cast<BookLegacyFormIO*>(this)->FUN_00484da0(buffer);
    TESValueForm::LoadGame(buffer);
    if (reinterpret_cast<FUN_005153a0_arg*>(buffer)->FUN_00428110(&local, 0x20)->FUN_004280f0())
    {
        reinterpret_cast<FUN_005153a0_arg*>(buffer)->LoadData(&Data.m_cCharacterAfterFlags, 1);
    }
}

// @fnv 0x00514ed0
void TESObjectBOOK::CopyBookData(TESForm* source)
{
    TESObjectBOOK* book = dynamic_cast<TESObjectBOOK*>(source);
    if (!book)
        return;
    TESForm::CopyFrom(source);
    Data = *book->Sky_GetSunLightSpecularColor();
}

#include <stdio.h>
struct InventoryItem
{
    TESBoundObject* GetObject();
    void* FUN_004bdcc0();
};
struct InventoryMenuSetting
{
    const char* FUN_00403df0();
};
extern InventoryMenuSetting g_011d2748;
extern InventoryMenuSetting g_011d2814;
extern InventoryMenuSetting g_011d38b8;
extern InventoryMenuSetting g_011d4e94;
extern InventoryMenuSetting g_011d34f8;
extern InventoryMenuSetting g_011d3684;
extern const char DAT_0108b3b4[];
void __cdecl PlayerCharacter_PoisonWeapon();
void __cdecl Interface_CreateMessageMenu(const char*, int, int, void(__cdecl*)(), int, int, float, float, ...);
// Checks the inventory item and weapon type, displays messages on failure, and stores action before formatting the final prompt.
// @fnv 0x0095e6f0
// src: XBOX_PDB 0x0095e6f0
void Actor::PlayerCharacter_CheckPoisonWeapon(int action)
{
    if (!action)
        return;
    InventoryItem* item = reinterpret_cast<InventoryItem*>(GetProcess()->GetActiveWeapon());
    {
        TESObjectWEAP* weapon = item ? dynamic_cast<TESObjectWEAP*>(item->GetObject()) : 0;
        if (!weapon)
        {
            Interface_CreateMessageMenu(g_011d2748.FUN_00403df0(), 0, 0, PlayerCharacter_PoisonWeapon, 1, 23, 0.0f, 0.0f, g_011d38b8.FUN_00403df0(),
                         0);
            return;
        }
        if (weapon->GetUnk15C() != 45 && weapon->GetUnk15C() != 38)
        {
            Interface_CreateMessageMenu(g_011d2748.FUN_00403df0(), 0, 0, PlayerCharacter_PoisonWeapon, 1, 23, 0.0f, 0.0f, g_011d38b8.FUN_00403df0(),
                         0);
            return;
        }
        if (item->FUN_004bdcc0())
        {
            Interface_CreateMessageMenu(g_011d2814.FUN_00403df0(), 0, 0, PlayerCharacter_PoisonWeapon, 1, 23, 0.0f, 0.0f, g_011d38b8.FUN_00403df0(),
                         0);
            return;
        }
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x758) = action;
        char szPrompt[256];
        sprintf(szPrompt, DAT_0108b3b4, g_011d4e94.FUN_00403df0(), weapon->TESFullName::GetFullName());
        Interface_CreateMessageMenu(szPrompt, 0, 0, PlayerCharacter_PoisonWeapon, 2, 23, 0.0f, 0.0f, g_011d34f8.FUN_00403df0(),
                     g_011d3684.FUN_00403df0(), 0);
    }
}

extern "C" int __cdecl _memcmp(const void*, const void*, unsigned int);

// Returns true if other is not a TESObjectBOOK or if FUN_00485270 or the BookData comparison is nonzero.
// @fnv 0x00514f50
// src: XBOX_PDB 0x00514f50
bool TESObjectBOOK::Compare_00514f50(TESForm* other)
{
    TESObjectBOOK* book = dynamic_cast<TESObjectBOOK*>(other);
    if (!book)
        return true;
    if (TESForm::Compare(book))
        return true;
    if (_memcmp(&Data, book->Sky_GetSunLightSpecularColor(), sizeof(BookData)))
        return true;
    return false;
}
