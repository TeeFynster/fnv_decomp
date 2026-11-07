// fallout_shared/bgsmenuicon.cpp: BGSMenuIcon (6 functions)

#include "TESFile.h"
#include "../../include/BGSMenuIcon.h"
#include <malloc.h>

struct ChunkLoadState
{
    char* chunkData;
    unsigned int chunkID;
};

// Checks the form type is 5, loads the record header, then reads EDID, OBND and ICON chunks until no chunk remains.
// @fnv 0x00590350
bool BGSMenuIcon::Load(TESFile* file)
{
    unsigned char formType;
    ChunkLoadState chunkState;

    formType = file->GetTESForm();
    if (formType != 5)
        return false;

    LoadRecordHeader(file);
    while ((chunkState.chunkID = file->GetChunkID()) != 0)
    {
        switch (chunkState.chunkID)
        {
        case 0x44494445:
            chunkState.chunkData = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(chunkState.chunkData, 0x200);
            SetEditorID_AtRuntime(chunkState.chunkData);
            break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4e4f4349:
            TESTexture::ReadTextureData(static_cast<TESTexture*>(this), file);
            break;
        }

        if (!file->NextChunk())
            break;
    }
    return true;
}

void __fastcall FUN_00483710(void* p);

// Clears this form before destroying its icon and form bases.
// @fnv 0x005902d0
BGSMenuIcon::~BGSMenuIcon()
{
    FUN_00483710(this);
}

// @fnv 0x00590470
void BGSMenuIcon::SaveForm()
{
    TESForm::BeginFormRecord();
    TESTexture::Save(0x4e4f4349);
    TESForm::FinishFormRecord();
}

// Copies the base form data when the source is a menu icon.
// @fnv 0x005904a0
void BGSMenuIcon::CopyFrom(const TESForm* form)
{
    const BGSMenuIcon* icon = dynamic_cast<const BGSMenuIcon*>(form);
    if (!icon)
        return;
    TESForm::CopyFrom(icon);
}

// Returns true if apCompare is not a BGSMenuIcon or the base comparison returns true.
// @fnv 0x005904e0
bool BGSMenuIcon::Compare(TESForm* apCompare)
{
    BGSMenuIcon* pcomp = dynamic_cast<BGSMenuIcon*>(apCompare);
    if (!pcomp)
        return true;
    if (TESForm::Compare(pcomp))
        return true;
    return false;
}
