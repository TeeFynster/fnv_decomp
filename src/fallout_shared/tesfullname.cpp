#include "../../include/BSStringT.h"

// src/fallout_shared/tesfullname.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesfullname.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "layout_support.h"
#include "../../include/TESFullName.h"

#include "../../include/TESDescription.h"
#include "../../include/TESForm.h"
#include "../../include/TESIcon.h"
#include "../../include/TESTexture.h"

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESObjectREFR;
struct blob8
{
    char b[8];
};
struct FUN_004870f0_shell : public TESFullName
{
    void CopyFullNameFrom(BaseFormComponent*);
};


struct FNStub
{
    char const* GetFullName(void);
};

// Casts apCopyFC to TESFullName and, if successful, copies its full name into this object's ::BSStringT<char> at offset 4.
// @fnv 0x004870f0
void FUN_004870f0_shell::CopyFullNameFrom(BaseFormComponent* apCopyFC)
{
    TESFullName* pCopy = dynamic_cast<TESFullName*>(apCopyFC);
    if (!pCopy)
        return;
    ((::BSStringT<char>*)((char*)this + 4))->Set(((FNStub*)pCopy)->GetFullName(), 0);
}

// Casts apObj to TESFullName and returns its full name, or an empty string if the cast fails.
// @fnv 0x00482720
// src: XBOX_PDB 0x00482720
const char* TESFullName_GetFullName(TESForm* apObj)
{
    TESFullName* pFullName = dynamic_cast<TESFullName*>(apObj);
    return pFullName ? ((FNStub*)pFullName)->GetFullName() : "";
}

class StringShell487 : public BSStringT<char>
{
  public:
    int StrCmp(const char* pcOther, bool bCaseSensitive) const;
};

class FullNameShell487 : public TESFullName
{
  public:
    unsigned int GetLength() const;
    const char* GetName() const;

    bool CompareFullName(BaseFormComponent* pkComponent);
};

// Compares this full name with another TESFullName component: returns true if lengths differ or names differ case-insensitively, false if equal.
// @fnv 0x00487140
bool FullNameShell487::CompareFullName(BaseFormComponent* pkComponent)
{
    TESFullName* pkOther = dynamic_cast<TESFullName*>(pkComponent);
    if (!pkOther)
        return true;
    if (GetLength() || static_cast<FullNameShell487*>(pkOther)->GetLength())
    {
        if (GetLength() != static_cast<FullNameShell487*>(pkOther)->GetLength())
            return true;
        else if (static_cast<StringShell487*>(&m_kName)->StrCmp(static_cast<FullNameShell487*>(pkOther)->GetName(),
                                                                false))
            return true;
    }
    return false;
}

struct TESFullNameSetter : public TESFullName
{
    void SetName(const char* text);
};

// Reads the FULL chunk from apFile and sets the name on apName via TESFullNameSetter::SetName.
// @fnv 0x00487050
void ReadFullName(TESFullName* apName, TESFile* apFile)
{
    if (!apFile || !apName)
    {
        return;
    }
    unsigned int id = apFile->GetChunkID();
    switch (id)
    {
    case CHUNK_ID_FULL_ID: {
        void* pChunkData;
        if (apFile->GetChunkSize())
        {
            pChunkData = _alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pChunkData, 0);
            ((TESFullNameSetter*)apName)->SetName((const char*)pChunkData);
        }
        else
        {
            ((TESFullNameSetter*)apName)->SetName(0);
        }
    }
    break;
    }
}
