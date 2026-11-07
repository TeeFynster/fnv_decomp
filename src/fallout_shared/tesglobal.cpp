// fallout_shared/tesglobal.cpp: TESGlobal, TESImageSpace (8 functions)

#include "../../include/BSStringT.h"
#include "tesglobal_layout.h"
#include "../../include/TESFile.h"
#include "../../include/TESGlobal.h"
#include "../../include/TESImageSpace.h"
#include "../../include/BSFaceGenModelMap.h"
#include <malloc.h>

#define FNV_FOURCC(a, b, c, d)                                                                                         \
    ((unsigned int)(a) | ((unsigned int)(b) << 8) | ((unsigned int)(c) << 16) | ((unsigned int)(d) << 24))

// Reads a TESGlobal record from the file, handling EDID, OBND, FNAM and FLTV chunks until the chunk list ends.
// @fnv 0x005a64b0
bool TESGlobal::Load(TESFile* file)
{
    // This caller compares the full return register, as in the original unsigned-int declaration.
    if ((file->*reinterpret_cast<unsigned int (TESFile::*)()>(&TESFile::GetTESForm))() != 6)
        return false;

    LoadRecordHeader(file);

    int chunkID;
    while ((chunkID = (int)file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case FNV_FOURCC('E', 'D', 'I', 'D'): {
            char* buffer = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(buffer, 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case FNV_FOURCC('O', 'B', 'N', 'D'):
            readOBNDSubRecord(file);
            break;
        case FNV_FOURCC('F', 'N', 'A', 'M'):
            file->GetChunkData(&cType, 1);
            break;
        case FNV_FOURCC('F', 'L', 'T', 'V'):
            file->GetChunkData((unsigned int*)&fValue);
            break;
        }
        if (!file->NextChunk())
            break;
    }

    return true;
}


// @fnv 0x0052b310
TESImageSpace::TESImageSpace()
{
    SetFormType((ENUM_FORM_ID)0x53);
    TESImageSpace::ResetFormData();
}

// Sets the global's editor ID, then returns true.
// @fnv 0x005a63a0
bool TESGlobal::SetEditorID_AtRuntime(char const* apString)
{
    cGlobalEditorID.Set(apString, 0);
    return 1;
}

void __cdecl TESForm_AddChunk_3(unsigned int, unsigned char);
void __cdecl _FUN_00485910(unsigned int, float);

// Writes the global's type and value chunks.
// @fnv 0x005a6460
void TESGlobal::SaveForm()
{
    TESForm::BeginFormRecord();
    TESForm_AddChunk_3(0x4D414E46, cType);
    _FUN_00485910(0x56544C46, fValue);
    TESForm::FinishFormRecord();
}

// @fnv 0x005a65e0
void TESGlobal::CopyFrom(const TESForm* apCopy)
{
    TESGlobal* pCopy = dynamic_cast<TESGlobal*>(const_cast<TESForm*>(apCopy));
    if (!pCopy)
        return;
    TESForm::CopyFrom(apCopy);
    cType = reinterpret_cast<BSFaceGenModelMap*>(pCopy)->HasModels();
    fValue = pCopy->GetValue();
}

// Returns true when the other form is not a global or its base data, type or value differs.
// @fnv 0x005a6640
bool TESGlobal::Compare(TESForm* apCompare)
{
    TESGlobal* pComp = dynamic_cast<TESGlobal*>(apCompare);
    if (!pComp)
        return true;
    if (TESForm::Compare(pComp))
        return true;
    if (((char)((BSFaceGenModelMap*)this)->HasModels()) != ((char)((BSFaceGenModelMap*)pComp)->HasModels()))
        return true;
    if (GetValue() != pComp->GetValue())
        return true;
    return false;
}

// @fnv 0x005a63f0
TESGlobal::~TESGlobal()
{
    TESForm::ClearData();
}
