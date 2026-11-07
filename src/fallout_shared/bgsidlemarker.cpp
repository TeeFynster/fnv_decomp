// fallout_shared/bgsidlemarker.cpp: BGSIdleMarker, FakeMarker, BGSIdleMarkerImpl, IdleMarkerComparison (9 functions)

#include "../../include/BSSoundHandle.h"
#include "../../include/TESBoundObject.h"
#include "../../include/BGSIdleCollection.h"
#include "../../include/TESFile.h"
#include "../../include/BGSIdleMarker.h"
#include "../../include/BGSQuestPerkEntry.h"

class TESFile;
class TESIdleForm;

class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};



class ChunkPayload16
{
  public:
    unsigned int data[4];
    void OBJ_WEAP_VATS_SPECIAL_Endian();
};

class ChunkPayloadWrapper16
{
  public:
    unsigned int data[4];
    void LoadFromPTFile(ChunkPayload16* payload);
};

template <int N> struct EndianSizeTag
{
};

void BSEndian(unsigned int* value, EndianSizeTag<4> tag);
void* __cdecl operator new[](unsigned int size);
void __cdecl operator delete[](void* pointer);
extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);
extern "C" void* __cdecl _alloca(unsigned int size);
#pragma intrinsic(_alloca)

// @fnv 0x005e9800
BGSQuestPerkEntry::BGSQuestPerkEntry()
{
    Data.pQuest = 0;
    Data.stage = 0;
}

// If the form is not yet initialized, initializes the BGSIdleCollection at offset 0x30 and marks the form as initialized.
// @fnv 0x005e7bb0
void BGSIdleMarker::InitItem()
{
    if (IsFormInitialized())
    {
    }
    else
    {
        BGSIdleCollection::InitItem(this);
        SetInitializationState(true);
    }
}

// Constructs the object and sets its form type to 0x30.
// @fnv 0x005e7a90
BGSIdleMarker::BGSIdleMarker()
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x30));
}

// 0x005e7b10 is the compiler's scalar deleting destructor of BGSIdleMarker (vftable 0x0104664c slot 4).

struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct FUN_004799f0_shell
{
    void FUN_004799f0();
};
struct FUN_005e7ed0_shell
{
    void BGSIdleMarker_SaveAlt();
};
// @fnv 0x005e7ed0
// src: COMMUNITY 0x005e7ed0
void FUN_005e7ed0_shell::BGSIdleMarker_SaveAlt()
{
    ((FUN_004855a0*)this)->M();
    ((FUN_004799f0_shell*)((char*)this + 0x30))->FUN_004799f0();
    ((FUN_00485680*)this)->M();
}

struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm*);
};
struct FUN_005e7f00_t
{
    void CopyFrom(TESForm* apCopy);
};
// Casts apCopy to BGSIdleMarker and, if the cast succeeds, forwards it to FUN_004851b0 on this object.
// @fnv 0x005e7f00
void FUN_005e7f00_t::CopyFrom(TESForm* apCopy)
{
    BGSIdleMarker* pcopy = dynamic_cast<BGSIdleMarker*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents((TESForm*)pcopy);
}

// @fnv 0x005e7b40
BGSIdleMarker::~BGSIdleMarker()
{}

void BSEndian(int* value, EndianSizeTag<4> tag);

struct IdlePayloadWrapper : public ChunkPayloadWrapper16
{
    IdlePayloadWrapper(ChunkPayload16* payload);
    ~IdlePayloadWrapper() throw();
};

struct BGSIdleMarkerImpl : public TESForm
{
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    unsigned char unk34;
    unsigned char unk35;
    unsigned short unk36;
    TESIdleForm** unk38;
    unsigned int unk3c;

    bool BGSIdleMarker_Load(TESFile* file);
};

// Reads record chunks from the file, updates fields for handled chunks, and constructs a wrapper for the payload chunk.
// @fnv 0x005e7bf0
// src: COMMUNITY 0x005e7bf0
bool BGSIdleMarkerImpl::BGSIdleMarker_Load(TESFile* file)
{
    this->LoadRecordHeader(file);
    this->SetInitializationState(false);
    while (int chunkID = file->GetChunkID())
    {
        switch (chunkID)
        {
        case 0x44494445: {  // 'EDID'
            char* pEditorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(pEditorID, 0x200);
            this->SetEditorID_AtRuntime(pEditorID);
            break;
        }
        case 0x444E424F: {  // 'OBND'
            this->readOBNDSubRecord(file);
            break;
        }
        case 0x464C4449: {  // 'IDLF'
            file->GetChunkData(&this->unk34, 1);
            break;
        }
        case 0x434C4449: {  // 'IDLC'
            if (file->GetChunkSize() == 1)
            {
                file->GetChunkData(&this->unk35, 1);
            }
            else
            {
                unsigned int val = 0;
                file->GetChunkData(&val);
                this->unk35 = (unsigned char)val;
            }
            if (this->unk35 != 0)
            {
                if (this->unk38 != 0)
                {
                    delete[] this->unk38;
                }
                this->unk38 = new TESIdleForm*[this->unk35];
                memset(this->unk38, 0, this->unk35 * sizeof(TESIdleForm*));
            }
            break;
        }
        case 0x414C4449: {  // 'IDLA'
            if (this->unk38 != 0)
            {
                unsigned int size = this->unk35 * sizeof(TESIdleForm*);
                if (file->GetChunkSize() == size)
                {
                    file->GetChunkData(this->unk38, size);
                    if (file->IsEndianConversionRequired())
                    {
                        for (int i = 0; i < this->unk35; ++i)
                        {
                            BSEndian((int*)&this->unk38[i], EndianSizeTag<4>());
                        }
                    }
                }
            }
            break;
        }
        case 0x544C4449: {  // 'IDLT'
            file->GetChunkData(&this->unk3c);
            goto def_label;
            goto def_label;
            goto def_label;
        }
        case 0x54445450: {  // 'PTDT'
            ChunkPayload16 payload;
            memset(&payload, 0, sizeof(payload));
            file->GetChunkData(&payload, sizeof(payload));
            if (file->IsEndianConversionRequired())
            {
                payload.OBJ_WEAP_VATS_SPECIAL_Endian();
            }
            IdlePayloadWrapper wrapper(&payload);
            break;
        }
        default:
        def_label:
            break;
        }
        if (!file->NextChunk())
        {
            break;
        }
    }

    return true;
}

class FormComponentComparison : public TESForm
{
  public:
    bool TESForm_CompareAllComponents(TESForm* compare);
};

class IdleMarkerComparison : public BGSIdleMarker
{
  public:
    bool BGSIdleMarker_Compare(TESForm* apCompare);
};

// Returns true if apCompare is not a BGSIdleMarker or if the base form component comparison against it succeeds.
// @fnv 0x005e7f40
// src: XBOX_PDB 0x005e7f40
bool IdleMarkerComparison::BGSIdleMarker_Compare(TESForm* apCompare)
{
    BGSIdleMarker* pIdleMarker = dynamic_cast<BGSIdleMarker*>(apCompare);
    if (!pIdleMarker)
        return true;
    if (((FormComponentComparison*)this)->TESForm_CompareAllComponents((TESForm*)pIdleMarker))
        return true;
    return false;
}
