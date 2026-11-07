#include "../../include/BSStringT.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/FileEntryList.h"
#include "../../include/TESBipedModelForm.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESLeveledList.h"

// src/fallout_shared/tesmodel.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesmodel.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BSFileEntry;
struct FileFormCollection;
typedef char _sizecheck_TESTextureList[sizeof(FileEntryList) == 8 ? 1 : -1];

// @fnv 0x00488ff0
FileEntryList::~FileEntryList()
{
    ClearData();
}

extern void __cdecl _Deallocate(void*);

// Frees the texture offset array if present, nulls it, resets the texture count, and returns whether anything was freed.
// @fnv 0x00489620
bool FileEntryList::ClearData()
{
    bool bresult = false;
    if (m_ppFileEntries)
    {
        BSFileEntry** p = m_ppFileEntries;
        _Deallocate(p);
        m_ppFileEntries = 0;
        bresult = true;
    }
    m_ucFileEntryCount = 0;
    return bresult;
}

struct FUN_008c1be0_shell
{
    void bhkTTNode_TESObjectREFR_GetFlags(int param_1);
};

// src: XBOX_PDB 0x008c1be0
void FUN_008c1be0_shell::bhkTTNode_TESObjectREFR_GetFlags(int param_1)
{}

struct FUN_004898c0_shell
{
    void BSArchive_GetFlag_(int param_1);
};

// @fnv 0x004898c0
// src: COMMUNITY 0x004898c0
void FUN_004898c0_shell::BSArchive_GetFlag_(int param_1)
{
    ((FUN_008c1be0_shell*)((char*)this + 0xc))->bhkTTNode_TESObjectREFR_GetFlags(param_1);
}

extern bool DAT_011acdf8;

// @fnv 0x004898e0
// src: COMMUNITY 0x004898e0
bool ArchiveManager_ArchivesEnabled()
{
    return DAT_011acdf8;
}

struct FUN_004890e0_shell
{
    void ForwardToMember();
};

// @fnv 0x004890e0
void FUN_004890e0_shell::ForwardToMember()
{
    ((FileEntryList*)((char*)this + 0xc))->ClearData();
}

struct FUN_00489860_shell
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    int i4;
    unsigned char* __thiscall BSHash_BSHash_0(unsigned char a, unsigned char b, unsigned char c, unsigned char d, int e);
};

// Stores the four byte arguments into b0..b3 and the int argument into i4, then returns this as an unsigned char pointer.
// @fnv 0x00489860
// src: COMMUNITY 0x00489860
unsigned char* __thiscall FUN_00489860_shell::BSHash_BSHash_0(unsigned char aucByte0, unsigned char aucByte1,
                                                           unsigned char aucByte2, unsigned char aucByte3, int aiValue)
{
    b0 = aucByte0;
    b1 = aucByte1;
    b2 = aucByte2;
    b3 = aucByte3;
    i4 = aiValue;
    return (unsigned char*)this;
}

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

typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
typedef char _sizecheck_TESLeveledList[sizeof(TESLeveledList) == 28 ? 1 : -1];

// @fnv 0x00487a00
void TESLeveledList::AddScriptAddedLeveledObject(TESForm* apOwner, unsigned short asLevel, unsigned short asCount, TESForm* apForm,
                                      ContainerItemExtra* apExtra)
{
    LeveledObject* plev = CreateLeveledObject(asLevel, asCount, apForm, apExtra);
    if (plev)
    {
        m_kLeveledObjects.AddHead(plev);
        apOwner->MarkAsModified(0x80000000);
    }
}

void __cdecl _Deallocate(void*);
// Calls the TESModel destructor and, when flags has bit 0 set, deallocates this; returns this.
// @fnv 0x00489010
void* TESModel::FUN_00489010(unsigned int flags)
{
    this->TESModel::~TESModel();
    if (flags & 1)
        _Deallocate(this);
    return this;
}


struct Flt
{
    operator unsigned int();
};
struct FUN_00489040_shell
{
    char b0;
    char b1;
    char b2;
    char b3;
    ::BSStringT<char> FullNameComponent;
    void ClearString();
};
// If the ::BSStringT<char> member converts to a nonzero value, clears it via Set(0, 0), then zeroes the byte at offset 0x14.
// @fnv 0x00489040
void FUN_00489040_shell::ClearString()
{
    if ((Flt&)FullNameComponent)
        FullNameComponent.Set(0, 0);
    *(unsigned char*)((char*)this + 0x14) = 0;
}

struct FUN_004898a0_shell : public FUN_004898c0_shell
{
    int BSArchive_GetFlag_(int param_1);
    bool BSArchive_HasEmbeddedFileNames();
};

// @fnv 0x004898a0
// src: COMMUNITY 0x004898a0
bool FUN_004898a0_shell::BSArchive_HasEmbeddedFileNames()
{
    return BSArchive_GetFlag_(256) != 0;
}

namespace fnv_004898f0 {
struct Flt
{
    operator unsigned int();
    int v;
};
extern Flt DAT_011f8190[];
extern Flt DAT_011f81b4[];
// Returns the value at index param_1 from DAT_011f8190 if nonzero, otherwise from DAT_011f81b4.
// @fnv 0x004898f0
unsigned int GetFltValue(int aiIndex)
{
    Flt* b;
    {
        Flt* a;
        if ((unsigned int)DAT_011f8190[aiIndex])
            a = &DAT_011f8190[aiIndex];
        else
            a = &DAT_011f81b4[aiIndex];
        b = a;
    }
    return (unsigned int)*b;
}
}  // namespace fnv_004898f0

struct BSFile;
struct TESBitArrayFile;
struct TESObjectCELL;
struct _FILETIME;
struct _SYSTEMTIME;
struct _WIN32_FIND_DATAA;

extern "C" void* __cdecl _alloca(unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
// @fnv 0x00489940
void FileEntryList::Load(TESFile* file, TESForm* form, char* name)
{
    unsigned int isize = file->GetChunkSize();
    if (isize % 24)
        return;
    unsigned int icount = isize / 24;
    int iusablesize = icount * 24;
    if (icount)
    {
        FileFormCollection* pdata = (FileFormCollection*)_alloca(iusablesize);
        memset(pdata, 0, iusablesize);
        file->GetChunkData(pdata, iusablesize);
        WriteFileEntryToBuffer(pdata, icount, form, name);
    }
}

struct FUN_004f9ec0_shell
{
    void CallInnerMethod();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
// Calls CallInnerMethod, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x004f9ec0
void* FUN_004f9ec0_shell::DestroyIfFlagged(unsigned int flags)
{
    CallInnerMethod();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct SpawnedBase
{
    virtual void unk00();
    SpawnedBase();
};

struct SubObjA
{
    int unk00;
    int unk04;
    SubObjA();
    ~SubObjA();
};

struct SubObjB
{
    int unk00;
    int unk04;
    SubObjB();
    ~SubObjB();
};

struct FUN_00488f50_cls : SpawnedBase
{
    SubObjA m_04;
    SubObjB m_0c;

    FUN_00488f50_cls();
    virtual void unk00();
    void ClearString();
};

// @fnv 0x00488f50
FUN_00488f50_cls::FUN_00488f50_cls()
{
    ClearString();
}

struct FUN_00489120_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char* GetPath();
    void SetFarPath(char* path);
};

void __cdecl FUN_00406d30(char* dst, int maxLen, const char* src);
char* __cdecl strrchr_0040ab30(const char* s, int ch);

// @fnv 0x00489120
void FUN_00489120_cls::SetFarPath(char* path)
{
    char* ext;
    FUN_00406d30(path, 0x104, GetPath());
    ext = strrchr_0040ab30(path, 0x2e);
    if (ext != 0)
    {
        FUN_00406d30(ext, 0x104 - (ext - path), "_far.NIF");
    }
}

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

    bool BGSIdleCollection_HasIdleForActor(B479FB0Actor* pkActor, int iArg);
};

// @fnv 0x00479fb0
// src: COMMUNITY 0x00479fb0
bool B479FB0IdleList::BGSIdleCollection_HasIdleForActor(B479FB0Actor* pkActor, int iArg)
{
    if (pkActor)
    {
        for (int i = 0; i < m_ucCount; i++)
        {
            B479FB0Idle* pkIdle = m_ppkIdles[i];
            if (pkIdle && pkActor->HasIdleInFormArray(pkIdle) && pkIdle->FUN_005ff430(pkActor, iArg, true))
                return true;
        }
    }
    return false;
}

// @fnv 0x00488fd0
FileEntryList::FileEntryList()
{
    m_ucFileEntryCount = 0;
    m_ppFileEntries = 0;
}

// Destructor: clear the entries; the entry list and the name string are destroyed afterwards.

class B9070String
{
  public:
    ~B9070String();
    char* m_pString;
    unsigned short m_usLen;
    unsigned short m_usMax;
};

class B9070List
{
  public:
    ~B9070List();
    void* m_pkHead;
    void* m_pkNext;
};

class FUN_00489070
{
  public:
    virtual ~FUN_00489070();
    void Clear();

    B9070String m_kName;
    B9070List m_kEntries;
};

// @fnv 0x00489070
FUN_00489070::~FUN_00489070()
{
    Clear();
}

int __cdecl B489480Stricmp(const char* pcA, const char* pcB);

struct FUN_00489480_shell : public TESModel
{

    bool IsModelPathDifferent(BaseFormComponent* pkComponent);
};

// @fnv 0x00489480
bool FUN_00489480_shell::IsModelPathDifferent(BaseFormComponent* pkComponent)
{
    FUN_00489480_shell* pkOther = static_cast<FUN_00489480_shell*>(dynamic_cast<TESModel*>(pkComponent));
    if (!pkOther)
        return true;
    const char* pcPath = GetModelFilePath();
    {
        const char* pcOtherPath = pkOther->GetModelFilePath();
        if (pcPath && pcOtherPath)
        {
            if (B489480Stricmp(pcPath, pcOtherPath))
                return true;
        }
        else if (!pcPath || !pcOtherPath)
        {
            if (pcPath && *pcPath)
                return true;
            if (pcOtherPath && *pcOtherPath)
                return true;
        }
    }
    return false;
}

struct FUN_004898a0_shell;
struct FUN_00489860_shell;
struct FileFormCollection
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
extern char DAT_011c5574;
extern char DAT_011c555c;
FUN_004898a0_shell* __cdecl GetFltValue(int);
bool __cdecl ArchiveManager_ArchivesEnabled();
unsigned int __cdecl FindFileEntryInArchives(int, FUN_00489860_shell*, FUN_00489860_shell*, int);
void __cdecl Warning_005b5e40(const char* fmt, ...);

// Stores the count and allocates an array, then for each Elem builds two keys, looks up an archive entry, and logs a warning when the lookup fails.
// @fnv 0x00489670
void FileEntryList::WriteFileEntryToBuffer(FileFormCollection* aElems, unsigned int count, TESForm* form, char* model)
{
    FUN_004898a0_shell* s = GetFltValue(1);
    if (!(s != 0 && ((FUN_004898a0_shell*)((char*)s + 0x160))->BSArchive_HasEmbeddedFileNames() &&
          *((FUN_00408d60_shell*)&DAT_011c5574)->FUN_00408d60() != 0))
        return;
    m_ucFileEntryCount = (unsigned char)count;
    m_ppFileEntries = (BSFileEntry**)new unsigned int[count];
    for (unsigned int i = 0; i < count; i++)
    {
        FUN_00489860_shell key0;
        key0.BSHash_BSHash_0(aElems[i].b0, aElems[i].b1, aElems[i].b2, aElems[i].b3, aElems[i].i4);
        FUN_00489860_shell key1;
        key1.BSHash_BSHash_0(aElems[i].c0, aElems[i].c1, aElems[i].c2, aElems[i].c3, aElems[i].i14);
        m_ppFileEntries[i] = (BSFileEntry*)FindFileEntryInArchives(1, &key1, &key0, 0);
        if (*((FUN_00408d60_shell*)&DAT_011c555c)->FUN_00408d60() != 0)
        {
            if (ArchiveManager_ArchivesEnabled())
            {
                if (m_ppFileEntries[i] == 0)
                {
                    if (form != 0 && model != 0)
                    {
                        Warning_005b5e40(
                            "MASTERFILE: Failed to find archive file entry for texture on model '%s' for form %s (%08X).",
                            model, form->GetName(), form->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
                    }
                    else if (model != 0)
                    {
                        Warning_005b5e40(
                            "MASTERFILE: Failed to find archive file entry for texture on model '%s' on UNKNOWN form.",
                            model);
                    }
                    else
                    {
                        Warning_005b5e40("MASTERFILE: Failed to find archive file entry for texture on UNKNOWN Model");
                    }
                }
            }
        }
    }
}

void __cdecl TESForm_AddChunkArray(char* pcDest, const char* pcSrc, unsigned int uiSize);

struct FUN_004891d0_hash
{
    void FUN_008d0600(void* pkOut, const char* pcPath);
};

struct FUN_004891d0_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char* GetPath();
    int unk04;
    int unk08;
    FUN_004891d0_hash m_kObjectMap;
    unsigned int FUN_0048cee0();
    void WriteToBuffer(char* pcBuffer, void* pkOut);
};

// When FUN_0048cee0() is nonzero, copies GetPath() to pcBuffer and passes pkOut and GetPath() to m_kObjectMap.FUN_008d0600.
// @fnv 0x004891d0
void FUN_004891d0_cls::WriteToBuffer(char* pcBuffer, void* pkOut)
{
    if (FUN_0048cee0())
    {
        if (pcBuffer)
            TESForm_AddChunkArray(pcBuffer, GetPath(), FUN_0048cee0() + 1);
        if (pkOut)
            m_kObjectMap.FUN_008d0600(pkOut, GetPath());
    }
}

struct FUN_004895b0_model
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* v5();
};

extern "C" void* __cdecl FNV_DynamicCast(void* inptr, long vfDelta, void* srcType, void* targetType, int isReference);
extern "C" char FNV_RTTI_TESForm;
extern "C" char FNV_RTTI_TESObjectREFR;
extern unsigned char DAT_011831e8;

FUN_004895b0_model* TESBipedModelForm_GetWorldTESModel(TESForm* form, TESObjectREFR* ref);

// Calls FNV_DynamicCast and FUN_00481010, then returns v5() or an empty string.
// @fnv 0x004895b0
// src: XBOX_PDB 0x004895b0
const char* TESModel_GetModel_004895b0(TESForm* apForm)
{
    FUN_004895b0_model* m = (FUN_004895b0_model*)FNV_DynamicCast(apForm, 0, &FNV_RTTI_TESForm, &DAT_011831e8, 0);
    if (m == 0)
    {
        m = TESBipedModelForm_GetWorldTESModel(apForm,
                         (TESObjectREFR*)FNV_DynamicCast(apForm, 0, &FNV_RTTI_TESForm, &FNV_RTTI_TESObjectREFR, 0));
    }
    if (m != 0)
    {
        return m->v5();
    }
    return "";
}

struct DistantModelView : TESModel
{
    void SetFarPath(char*);
};
// If apForm is a TESModel, cast it to DistantModelView and call FUN_00489120 with apModelName.
// @fnv 0x00489190
// src: XBOX_PDB 0x00489190
void TESModel_GetDistantModelName(char* apModelName, TESForm* apForm)
{
    TESModel* pmodel;
    if (apForm)
    {
        pmodel = dynamic_cast<TESModel*>(apForm);
        if (pmodel)
        {
            static_cast<DistantModelView*>(pmodel)->SetFarPath(apModelName);
        }
    }
}

// Loads texture file entries into the model's texture list from the given file, using the model's path and form context.
// @fnv 0x004893e0
// src: XBOX_PDB 0x004893e0
void TESModel_LoadModelTextureChunk(TESModel* model, TESFile* file)
{
    if (model && file)
        model->m_pTextureSwapData.Load(file, dynamic_cast<TESForm*>(model), model->GetModelFilePath());
}

// Copies the model path from a BaseFormComponent cast to TESModel.
// @fnv 0x00489430
void TESModel::BaseFormRecord(BaseFormComponent* component)
{
    TESModel* copy = dynamic_cast<TESModel*>(component);
    if (copy == 0)
        return;
    SetModelFilePath(copy->GetModelFilePath());
}

// @fnv 0x00489540
// src: XBOX_PDB 0x00489540
unsigned int __cdecl TESModel_GetModelLength(void* apForm)
{
    void* result;

    result = ::FNV_DynamicCast(apForm, 0, &::FNV_RTTI_TESForm, &::DAT_011831e8, 0);
    if (result == 0)
    {
        result = ::TESBipedModelForm_GetWorldTESModel((::TESForm*)apForm, (::TESObjectREFR*)::FNV_DynamicCast(apForm, 0, &::FNV_RTTI_TESForm,
                                                                                        &::FNV_RTTI_TESObjectREFR, 0));
    }
    if (result != 0)
    {
        return ((::FUN_004891d0_cls*)result)->FUN_0048cee0();
    }
    return 0;
}

struct ReferenceOwnerView481010
{
    TESForm* TESObjectREFR_GetOwner();
};

struct ActorSexView481010
{
    int FUN_005f0cc0();
};

int __fastcall _FNV_GetFormType(TESForm*);

// Returns the biped model for a TESBipedModelForm, selecting the male or female variant based on the owner actor's sex when a reference is provided.
// @fnv 0x00481010
// src: XBOX_PDB 0x00481010
FUN_004895b0_model* __cdecl TESBipedModelForm_GetWorldTESModel(TESForm* apBipedModelForm, TESObjectREFR* apReference)
{
    TESBipedModelForm* sex = dynamic_cast<TESBipedModelForm*>(apBipedModelForm);
    TESForm* biped;
    int iOwnerSex;

    if (sex == 0)
        return 0;
    if (apReference == 0)
        return reinterpret_cast<FUN_004895b0_model*>(&sex->groundModel[0]);

    biped = reinterpret_cast<ReferenceOwnerView481010*>(apReference)->TESObjectREFR_GetOwner();
    iOwnerSex = 0;
    if (biped != 0 && _FNV_GetFormType(biped) == 0x2a)
        iOwnerSex = reinterpret_cast<ActorSexView481010*>(biped)->FUN_005f0cc0();
    return reinterpret_cast<FUN_004895b0_model*>(sex->GetWorldModel(iOwnerSex));
}
