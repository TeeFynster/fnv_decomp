
// src/fallout/ai/backuppackage.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/backuppackage.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BackUpPackage.h"
#include "../../../include/TESPackage.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/TESSound.h"
#include "../../../include/PackageTargetRecord.h"
#include "../../../include/Actor.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/TESActorBase.h"
#include "../../../include/TESSaveLoadGame.h"

// These nonvirtual serialization and data-access declarations are not yet in TESPackage.h.
struct TESPackageUnitSupport : TESPackage
{
    void DispatchToSubobjects(void* buffer);
    void SaveToBuffer(void* buffer);
    void WriteTypedData(void* data, unsigned int size);
    void ReadTypedData(void* data, unsigned int size);
    PackageTargetRecord* GetData();
};

// @fnv 0x009ed010
void __thiscall BackUpPackage::ForwardToBase(void* apBuffer)
{
    ((TESPackageUnitSupport*)this)->DispatchToSubobjects(apBuffer);
}

void __thiscall BackUpPackage::FUN_009ed330()
{}

// Calls FUN_009ed330, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x009ed0a0
void* __thiscall BackUpPackage::DestroyOrFree(unsigned int flags)
{
    FUN_009ed330();
    if (flags & 1)
        operator delete(this);
    return this;
}

// @fnv 0x009edb60
// src: XBOX_PDB 0x009edb60
void __thiscall BackUpPackage::SaveGame_009edb60(BGSSaveFormBuffer* apBuffer)
{
    ((TESPackageUnitSupport*)this)->SaveToBuffer(apBuffer);
    apBuffer->SaveData((char*)this + 0x80, 0xc, 0);
}

// Calls TESPackage::LoadGame on the buffer, then reads 12 bytes from the buffer into the object at offset 0x80.
// @fnv 0x009edb90
void __thiscall BackUpPackage::LoadGameWithBackup(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESPackage::LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0x80), 12u);
}

struct GlobalObject_0045cf30
{
    unsigned char* __thiscall Bool();
};

struct HeaderProxy
{
    unsigned int id;
    unsigned char unk04, unk05, unk06, unk07, unk08;
};

// Exe 0x009ed5f0: unit-local Interface view; declarations and layout are preserved.
struct BackuppackageInterfaceView
{
    static void __cdecl PrintDebugMessage(const char* format, ...);
};

TESSaveLoadGame* DAT_011de45c;
GlobalObject_0045cf30 g_011de4e8;

TESForm* __cdecl _ref_004839c0(unsigned int formID);

// @fnv 0x009ed5f0
// src: XBOX_PDB 0x009ed5f0
unsigned short __thiscall BackUpPackage::GetSaveSize_009ed5f0()
{
    unsigned short usSaveSize = 0;
    unsigned short usOldSize;

    usSaveSize += TESPackage::GetSaveSize();
    usOldSize = usSaveSize;

    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        usSaveSize += 4;
        usSaveSize += 2;
    }

    usSaveSize += 0xC;

    if (*g_011de4e8.Bool())
    {
        HeaderProxy* header = (HeaderProxy*)DAT_011de45c->FUN_004fd3e0();
        if (header)
        {
            TESForm* pForm = _ref_004839c0(header->id);
            BackuppackageInterfaceView::PrintDebugMessage(
                "GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                usSaveSize - usOldSize, header->id, pForm->GetName(),
                *reinterpret_cast<unsigned int*>(&header->unk05), 0xD3,
                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BackUpPackage.cpp");
        }
        else
        {
            BackuppackageInterfaceView::PrintDebugMessage("GetSaveSize(): %-5i ending at line %i in file %s", usSaveSize - usOldSize,
                                         0xD3,
                                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BackUpPackage.cpp");
        }
    }

    return usSaveSize;
}

// Initializes the base package and the backup position.
// @fnv 0x009ed030
BackUpPackage::BackUpPackage()
{
    reinterpret_cast<NiPoint3*>(&unk80)->FUN_006815c0();
}

void ProgramFlow(const char*, ...);
void Warning_005b5e40(const char*, ...);
// @fnv 0x009ed700
void BackUpPackage::SaveBackupPackage()
{
    TESPackage::SaveGameTESAlt();
    unsigned short a = 0;
    unsigned short* p = 0;
    char* i = (char*)DAT_011de45c->FUN_00825c00();
    if (*g_011de4e8.Bool())
        i = (char*)DAT_011de45c->FUN_00825c00();
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int tag = 0x424c4f4b;
        DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&tag, 4u);
        p = (unsigned short*)DAT_011de45c->FUN_00825c00();
        DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&a, 2u);
    }
    unsigned short s = 0;
    char* h = (char*)DAT_011de45c->FUN_00825c00();
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&s, 2u);
    ((TESPackageUnitSupport*)this)->WriteTypedData(&unk80, 12);
    if (*g_011de4e8.Bool())
    {
        char* header = (char*)DAT_011de45c->FUN_00825c00();
        HeaderProxy* end = (HeaderProxy*)DAT_011de45c->FUN_004fd3e0();
        if (end)
        {
            TESForm* form = _ref_004839c0(end->id);
            ProgramFlow("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s", header - i,
                         end->id, form->GetName(), *(unsigned int*)&end->unk05, 262,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BackUpPackage.cpp");
        }
        else
        {
            ProgramFlow("SaveGame(): %-5i ending at line %i in file %s", header - i, 262,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BackUpPackage.cpp");
        }
    }
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        char* finalend = (char*)DAT_011de45c->FUN_00825c00();
        char* saved = (char*)p;
        if (finalend > saved + 65535)
            Warning_005b5e40("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BackUpPackage.cpp", 262);
        *p = (unsigned short)(finalend - saved);
    }
}

// Constructor 0x0067f030 and setter 0x0067f3c0 identify LocationDescriptor; no include/ header exists yet.
class LocationDescriptor
{
public:
    int kind;
    int radius;
    TESObjectREFR* reference;
    LocationDescriptor();
    ~LocationDescriptor();
    void PackageLocation_SetLocReference(TESObjectREFR*);
};

// Actor.h does not yet declare this nonvirtual backup-package entry point.
struct BackupPackageActorSupport : Actor
{
    void InstallBackupPackage(void* unused);
};
// Builds a package with location and target data, applies it to the actor's process context, then starts it on the actor.
// @fnv 0x00897bd0
void BackupPackageActorSupport::InstallBackupPackage(void* unused)
{
    TESPackage* value = TESPackage::CreatePackageForType(14);
    value->SetPackageType(14);
    value->SetMustReachLocation(false);
    value->SetMustComplete(false);
    LocationDescriptor* location = new LocationDescriptor;
    location->PackageLocation_SetLocReference(this);
    value->SetPackageLocation(location);
    delete location;
    PackageTargetRecord* target = new PackageTargetRecord;
    value->SetPackageTarget((PackageTargetRecord*)target);
    value->SetProcedureType(41);
    ((TESPackageUnitSupport*)value)->GetData()->SetTargetKind(0);
    ((TESPackageUnitSupport*)value)->GetData()->SetTargetObjectReference((TESObjectREFR*)this);
    void* contextTmp = GetProcess()->GetCurrentPackage();
    if (contextTmp)
        value->CopyAllFlags(contextTmp);
    ((TESPackageUnitSupport*)value)->GetData()->SetTargValue(GetActorBase()->GetAggroRadius());
    delete target;
    GetProcess()->ResetPackageState();
    // MobileObject::Unk_BD is slot 0xBD, but its shared declaration lacks these arguments.
    typedef void (__thiscall* StartPackageFunction)(Actor*, TESPackage*, int, int);
    ((StartPackageFunction)(*(void***)this)[0xBD])(this, value, 1, 1);
}

struct LoadHeader
{
    unsigned int formID;
    unsigned char version;
    unsigned char flags0, flags1, flags2, flags3;
    unsigned char type;
};
// Reads a 4-byte block marker and a 2-byte size, then reports block header, overrun and underrun errors against the loaded buffer.
// @fnv 0x009ed8d0
void BackUpPackage::LoadPackageBlock()
{
    TESPackage::LoadGameTESAlt();
    unsigned short usBlockSize = 0;
    char* pBlockStart = 0;
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int uiBlockMarker;
        DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&uiBlockMarker, 4);
        if (uiBlockMarker != 0x424c4f4b)
        {
            LoadHeader* header = (LoadHeader*)DAT_011de45c->BGSProjectile_GetExplosion();
            if (header)
            {
                TESForm* form = _ref_004839c0(header->formID);
                Warning_005b5e40(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BackUpPackage.cpp", 270, header->formID,
                    form->GetName(), header->type, *(unsigned int*)&header->flags0);
            }
            else
            {
                Warning_005b5e40(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BackUpPackage.cpp", 270,
                    DAT_011de45c->FUN_008df040());
            }
        }
        pBlockStart = (char*)DAT_011de45c->FUN_00825c00();
        DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&usBlockSize, 2);
    }
    ((TESPackageUnitSupport*)this)->ReadTypedData(&unk80, 12);
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        char* header = (char*)DAT_011de45c->FUN_00825c00();
        LoadHeader* pBlockHeader = (LoadHeader*)DAT_011de45c->BGSProjectile_GetExplosion();
        if (pBlockHeader)
        {
            TESForm* form = _ref_004839c0(pBlockHeader->formID);
            if (header > pBlockStart + usBlockSize)
            {
                Warning_005b5e40(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    header - (pBlockStart + usBlockSize),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BackUpPackage.cpp", 310, pBlockHeader->formID,
                    form->GetName(), pBlockHeader->type, *(unsigned int*)&pBlockHeader->flags0);
            }
            else if (header < pBlockStart + usBlockSize)
            {
                Warning_005b5e40(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    (pBlockStart + usBlockSize) - header,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BackUpPackage.cpp", 310, pBlockHeader->formID,
                    form->GetName(), pBlockHeader->type, *(unsigned int*)&pBlockHeader->flags0);
            }
        }
        else
        {
            if (header > pBlockStart + usBlockSize)
            {
                Warning_005b5e40(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                    header - (pBlockStart + usBlockSize),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BackUpPackage.cpp", 310,
                    DAT_011de45c->FUN_008df040());
            }
            else if (header < pBlockStart + usBlockSize)
            {
                Warning_005b5e40(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                    (pBlockStart + usBlockSize) - header,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BackUpPackage.cpp", 310,
                    DAT_011de45c->FUN_008df040());
            }
        }
    }
}
