// fallout_shared/bgsstaticcollection.cpp: BGSStaticCollection, StaticCollectionComparison (8 functions)

#include "bgsstaticcollection_decls.h"
#include <malloc.h>

// Reads the record header and iterates chunks, handling EDID, OBND, model and texture-swap subrecords until no chunk remains, then returns true.
// @fnv 0x004fe390
bool BGSStaticCollection::LoadForm(TESFile* file)
{
    LoadRecordHeader(file);
    CHUNK_ID chunk;
    while ((chunk = static_cast<CHUNK_ID>(file->GetChunkID())) != CHUNK_ID_NO_CHUNK)
    {
        switch (chunk)
        {
        case CHUNK_ID_EDID_ID: {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case CHUNK_ID_OBND_ID:
            readOBNDSubRecord(file);
            break;
        case CHUNK_ID_MODL_ID:
        case CHUNK_ID_MODD_ID:
        case CHUNK_ID_MOSD_ID:
        case CHUNK_ID_MODT_ID:
            TESModel::LoadModelData(this, file);
            break;
        case CHUNK_ID_MODS_ID: {
            struct TextureSwapChunk
            {
                unsigned int size;
                void* data;
            } textureSwapChunk;
            textureSwapChunk.size = file->GetChunkSize();
            textureSwapChunk.data = _alloca(textureSwapChunk.size);
            file->GetChunkData(textureSwapChunk.data, textureSwapChunk.size);
            ParseTextureSwapData(textureSwapChunk.data, textureSwapChunk.size,
                                 reinterpret_cast<TESFileFormVersion*>(file)->GetFormVersion());
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Returns early if the item is already initialized; otherwise calls TESModelTextureSwap::InitItem and marks the item initialized.
// @fnv 0x004fe560
void BGSStaticCollection::InitItem()
{
    if (IsFormInitialized())
        return;
    TESModelTextureSwap::InitItem(this);
    SetInitializationState(true);
}

struct B1_4fe
{
    char d[0x2c];
    B1_4fe();
    ~B1_4fe();
    virtual void v1();
    void SetFormType(int);
};
struct B2_4fe
{
    char d[0x10];
    B2_4fe();
    ~B2_4fe();
    virtual void v2();
};
struct FUN_004fe260 : B1_4fe, B2_4fe
{
    FUN_004fe260();
};
// Constructs the object and sets its form type to 0x21 via SetFormType.
// @fnv 0x004fe260
FUN_004fe260::FUN_004fe260()
{
    SetFormType(0x21);
}

struct FUN_004855a0
{
    void M(void);
};
struct FUN_00485680
{
    void M(void);
};
struct S_0048a520
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};

struct FUN_004fe520_shell
{
    void BGSStaticCollection_Save(void);
};

// Calls M on this, then ProcessAndFreeData on the object at offset 0x30 with three tags, then M on this again.
// @fnv 0x004fe520
// src: XBOX_PDB 0x004fe520
void __thiscall FUN_004fe520_shell::BGSStaticCollection_Save(void)
{
    ((FUN_004855a0*)this)->M();
    ((S_0048a520*)((char*)this + 0x30))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    ((FUN_00485680*)this)->M();
}

struct Dummy
{
    void FUN_004fe310();
    void* FUN_004fe2e0(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_004fe310, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004fe2e0
void* Dummy::FUN_004fe2e0(unsigned int flags)
{
    FUN_004fe310();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm*);
};
struct FUN_004fe5a0_t
{
    void BGSStaticCollection_Copy(TESForm*);
};
// Casts apCopy to BGSStaticCollection and, if the cast succeeds, forwards it to FUN_004851b0.
// @fnv 0x004fe5a0
// src: XBOX_PDB 0x004fe5a0
void FUN_004fe5a0_t::BGSStaticCollection_Copy(TESForm* apCopy)
{
    BGSStaticCollection* pcopy = dynamic_cast<BGSStaticCollection*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents(pcopy);
}

struct FUN_004fe310 : B1_4fe, B2_4fe
{
    void BGSStaticCollection_ClearData();
    ~FUN_004fe310();
};

// @fnv 0x004fe310
FUN_004fe310::~FUN_004fe310()
{
    BGSStaticCollection_ClearData();
}

class FormComponentComparison : public TESForm
{
  public:
    bool TESForm_CompareAllComponents(TESForm* other);
};

class StaticCollectionComparison : public BGSStaticCollection
{
  public:
    bool BGSStaticCollection_Compare(TESForm* other);
};

// Returns true if other is not a BGSStaticCollection or FUN_00485270 returns true for the collection.
// @fnv 0x004fe5e0
// src: XBOX_PDB 0x004fe5e0
bool StaticCollectionComparison::BGSStaticCollection_Compare(TESForm* other)
{
    BGSStaticCollection* collection = dynamic_cast<BGSStaticCollection*>(other);
    if (!collection)
        return true;
    if (static_cast<FormComponentComparison*>(static_cast<TESForm*>(this))->TESForm_CompareAllComponents(collection))
        return true;
    return false;
}
