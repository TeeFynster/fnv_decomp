#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/FileEntryList.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESLeveledList.h"
#include "../../include/TESModel.h"


// src/fallout_shared/tesmodel_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x004781e0: the skeleton of src/fallout_shared/tesmodel.cpp
// with declarations corrected to what the original code does (unit: struct TESModel { virtual ~TESModel(); void* FUN_004 -> struct TESModel { virtual ~TESModel(); virtual void ). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/tesmodel.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesmodel.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct BSFileEntry;
struct FileFormCollection;
typedef char _sizecheck_TESTextureList[sizeof(FileEntryList) == 8 ? 1 : -1];
struct FUN_008c1be0_shell
{
    void FUN_008c1be0(int param_1);
};
void FUN_008c1be0_shell::FUN_008c1be0(int param_1)
{}
struct FUN_004898c0_shell
{
    void FUN_004898c0(int param_1);
};
extern bool DAT_011acdf8;
bool FUN_004898e0();
struct FUN_00489860_shell
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    int i4;
    unsigned char* __thiscall FUN_00489860(unsigned char a, unsigned char b, unsigned char c, unsigned char d, int e);
};
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct ContainerItemExtra;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct LeveledObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESContainer;
struct TESFaction;
struct TESGlobal;
struct TESHealthForm;
struct TESNPC;
struct TESObjectREFR;
struct blob8
{
    char b[8];
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
typedef char _sizecheck_TESLeveledList[sizeof(TESLeveledList) == 28 ? 1 : -1];
struct G2
{
    void AddHead(LeveledObject*&);
};
void __cdecl _Deallocate(void*);
struct FUN_004898a0_shell : public FUN_004898c0_shell
{
    int FUN_004898c0(int param_1);
    bool FUN_004898a0();
};
struct FUN_004f9ec0_shell
{
    void CallInnerMethod();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
void __cdecl FUN_00406d30(char* dst, int maxLen, const char* src);
char* __cdecl FUN_0040ab30(const char* s, int ch);
class B479FB0Actor;
class B479FB0Idle
{
  public:
    bool FUN_005ff430(B479FB0Actor* pkActor, int iArg, bool bFlag);
};
class B479FB0Actor
{
  public:
    bool HasIdleInFormArray(B479FB0Idle* pkIdle);
};
class B479FB0IdleList
{
  public:
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    char unk04;
    unsigned char m_ucCount;
    short unk06;
    B479FB0Idle** m_ppkIdles;

    bool FUN_00479fb0(B479FB0Actor* pkActor, int iArg);
};
int __cdecl B489480Stricmp(const char* pcA, const char* pcB);
struct FUN_004898a0_shell;
struct FUN_00489860_shell;
struct Elem
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    int i4;
    int unk08;
    int unk0c;
    unsigned char c0;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
    int i14;
};
struct FUN_00408d60_shell
{
    unsigned char* FUN_00408d60();
};
struct Cls
{
    unsigned char m_00;
    unsigned int* m_04;
    void LoadTextureArchiveEntries(Elem* arr, unsigned int count, TESForm* form, const char* model);
};
extern char DAT_011c5574;
extern char DAT_011c555c;
FUN_004898a0_shell* __cdecl GetFltValue(int);
bool __cdecl FUN_004898e0();
unsigned int __cdecl FindFileEntryInArchives(int, FUN_00489860_shell*, FUN_00489860_shell*, int);
void __cdecl FUN_005b5e40(const char* fmt, ...);

class String;
#include "../../include/BSSimpleList.h"

struct DestructionStage
{
    unsigned char damageStage;
    unsigned char healthPercent;
    unsigned char flags;
    unsigned int selfDamage;
    TESForm* explosion;
    TESForm* debris;
    unsigned int debrisCount;
    TESModel* replacementModel;
    void EnsureB2_4fe();
};
struct DestructibleData
{
    unsigned int health;
    unsigned char stageCount;
    unsigned char flags;
    DestructionStage** stages;
};
struct DestructibleHeader
{
    unsigned int health;
    unsigned char stageCount;
    unsigned char flags;
    unsigned short unused;
    DestructibleHeader();
    void FUN_00503210();
};
struct DestructionStageChunk
{
    unsigned char healthPercent;
    unsigned char index;
    unsigned char damageStage;
    unsigned char flags;
    unsigned int selfDamage;
    TESForm* explosion;
    TESForm* debris;
    unsigned int debrisCount;
    void FUN_00478130();
};
extern "C" void* __cdecl _alloca(unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
void __cdecl FUN_005b5e40(const char*, ...);
void __cdecl FUN_004893e0(TESModel*, TESFile*);

// @fnv 0x004781e0
void __cdecl FUN_004781e0(BGSDestructibleObjectForm* component, TESFile* file)
{
    if (!file || !component)
        return;
    int chunkID = file->GetChunkID();
    component->EnsureCurrentEntry();
    DestructibleData* pkData = component->FUN_00726070();
    switch (chunkID)
    {
    case 0x54534544: {
        DestructibleHeader header;
        if (file->GetChunkSize() != 8)
        {
            TESForm* form = dynamic_cast<TESForm*>(component);
            FUN_005b5e40("MASTERFILE: Old Destruction data found on form %08X %s.  It needs to be resaved.",
                         static_cast<const TESForm*>(form)->GetFormID(), form->GetName());
            component->FUN_00478690();
            return;
        }
        file->GetChunkData(&header, 0);
        if (file->IsEndianConversionRequired())
            header.FUN_00503210();
        pkData->health = header.health;
        pkData->stageCount = header.stageCount;
        pkData->flags = header.flags;
        if (pkData->stageCount)
            pkData->stages = component->AllocateSpawnedItemArray(pkData->stageCount);
        break;
    }
    case 0x44545344: {
        DestructionStageChunk stage;
        memset(&stage, 0, sizeof(stage));
        file->GetChunkData(&stage, sizeof(stage));
        if (file->IsEndianConversionRequired())
            stage.FUN_00478130();
        unsigned char index = stage.index;
        if (index < pkData->stageCount)
        {
            pkData->stages[index]->damageStage = stage.damageStage;
            pkData->stages[index]->healthPercent = stage.healthPercent;
            pkData->stages[index]->flags = stage.flags;
            pkData->stages[index]->selfDamage = stage.selfDamage;
            pkData->stages[index]->explosion = stage.explosion;
            pkData->stages[index]->debris = stage.debris;
            pkData->stages[index]->debrisCount = stage.debrisCount;
            while ((chunkID = file->GetChunkID()) != 0)
            {
                switch (chunkID)
                {
                case 0x4c444d44: {
                    pkData->stages[index]->EnsureB2_4fe();
                    char* path = (char*)_alloca(file->GetChunkSize());
                    file->GetChunkData(path, 0);
                    pkData->stages[index]->replacementModel->SetModelFilePath(path);
                    break;
                }
                case 0x54444d44:
                    pkData->stages[index]->EnsureB2_4fe();
                    FUN_004893e0(pkData->stages[index]->replacementModel, file);
                    break;
                case 0x53444d44: {
                    pkData->stages[index]->EnsureB2_4fe();
                    unsigned int size = file->GetChunkSize();
                    void* pBuffer = _alloca(size);
                    file->GetChunkData(pBuffer, size);
                    pkData->stages[index]->replacementModel->LoadTextureSwapList(pBuffer, size, file->GetFormVersion());
                    break;
                }
                case 0x46545344:
                    return;
                }
                if (!file->NextChunk())
                    break;
            }
        }
        break;
    }
    }
}
