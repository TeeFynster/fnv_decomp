// fallout_shared/teshair.cpp: TESHair, HairComparisonEntry (10 functions)

#include "../../include/TESRaceForm.h"
// Use the shared base instead of the generated unit-local definition.
#define FNV_BASEFORMCOMPONENT_H

#include "teshair_types_TESHair.h"
#include "teshair_decls.h"
#include <malloc.h>

// @fnv 0x005fdaa0
TESHair::TESHair() : TESForm(), TESFullName(), TESModel(), TESTexture()
{
    SetFormType((ENUM_FORM_ID)10);
    ResetFormData();
}

// Loads a hair record: verifies form type 10, reads the record header, then dispatches EDID, OBND, FULL, MODL/MODD, ICON and DATA chunks until no chunks remain.
// @fnv 0x005fdcb0
bool TESHair::LoadForm(TESFile* file)
{
    if (((TESFileFormInt_teshair_decls*)file)->GetTESForm() != 10)
        return false;
    TESForm::LoadRecordHeader(file);
    unsigned int chunkID;
    while ((chunkID = file->GetChunkID()) != 0)
    {
        switch ((int)chunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x4e4f4349:
            TESTextureLoader::ReadTextureData(this, file);
            break;
        case 0x41544144:
            file->GetChunkData(&cFlags, 1);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_005fdf60_shell : public TESHair
{
    bool TESHair_CanBeMale();
};

// @fnv 0x005fdf60
// src: COMMUNITY 0x005fdf60
bool FUN_005fdf60_shell::TESHair_CanBeMale()
{
    if (*((char*)this + 0x48) & 2)
        return false;
    return true;
}

typedef char _sizecheck_TESRaceForm[sizeof(TESRaceForm) == 8 ? 1 : -1];
struct FUN_005fdfa0_shell : public TESHair
{
    bool IsHairValidForNPC(TESNPC*);
};

// @fnv 0x005fdfa0
bool FUN_005fdfa0_shell::IsHairValidForNPC(TESNPC* apNPC)
{
    bool bretval = false;
    BGSQuestObjective* hair;
    if (apNPC && ((TESHairCanBeNPCData_teshair_decls*)apNPC)->TESNPC_GetRace() != 0)
    {
        hair = (BGSQuestObjective*)this;
        if (((TESHairCanBeNPCData_teshair_decls*)apNPC)->TESNPC_GetRace()->NiAVObject_GetWorldTranslate()->IsInList(hair))
        {
            switch (((TESActorBase*)apNPC)->GetSex())
            {
            case SEX_SEX_MALE:
                if (TESHair_CanBeMale())
                {
                    bretval = true;
                }
                break;
            case SEX_SEX_FEMALE:
                if (IsFlag4Clear())
                {
                    bretval = true;
                }
                break;
            }
        }
    }
    return bretval;
}

struct FUN_005fdf40_shell
{
// @fnv 0x005fdf40
    virtual ~FUN_005fdf40_shell()
    {}
    bool TESHair_GetPlayable();
};

// src: COMMUNITY 0x005fdf40
bool FUN_005fdf40_shell::TESHair_GetPlayable()
{
    return (bool)((*(signed char*)((char*)this + 0x48) & 1) != 0);
}

struct FUN_005fdf80_shell
{
    bool IsFlag4Clear();
};

// @fnv 0x005fdf80
bool FUN_005fdf80_shell::IsFlag4Clear()
{
    if (((char*)this)[0x48] & 0x4)
        return false;
    return true;
}

struct FUN_005e78f0_t
{
    void __thiscall TESForm_CopyAllComponents(TESForm* apCopy);
};

struct FUN_005fde80_shell
{
    void __thiscall CopyFromHair(TESForm* apCopy);
};

// @fnv 0x005fde80
void __thiscall FUN_005fde80_shell::CopyFromHair(TESForm* apCopy)
{
    TESHair* pcopy = dynamic_cast<TESHair*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents(apCopy);
    ((char*)this)[0x48] = ((char*)pcopy)[0x48];
}

struct S
{
    void FUN_005fdb90();
    void* FUN_005fdb60(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_005fdb90, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x005fdb60
void* S::FUN_005fdb60(unsigned int flags)
{
    FUN_005fdb90();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct S_00487010
{
    void Save_00487010();
};
struct FUN_0048e370_obj
{
    void TESTexture_Save(unsigned int);
};
struct FUN_004891d0_holder
{
    void __thiscall WriteToBuffer(unsigned int a, unsigned int b);
};
void __cdecl TESForm_AddChunk_3(unsigned int, unsigned char);

struct FUN_005fdc50_shell
{
    void TESHair_Save();
};

// @fnv 0x005fdc50
// src: XBOX_PDB 0x005fdc50
void FUN_005fdc50_shell::TESHair_Save()
{
    reinterpret_cast<FUN_004855a0*>(this)->M();
    reinterpret_cast<S_00487010*>(reinterpret_cast<char*>(this) + 0x18)->Save_00487010();
    reinterpret_cast<FUN_004891d0_holder*>(reinterpret_cast<char*>(this) + 0x24)->WriteToBuffer(0x4c444f4d, 0x54444f4d);
    reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x3c)->TESTexture_Save(0x4e4f4349);
    TESForm_AddChunk_3(0x41544144, reinterpret_cast<char*>(this)[0x48]);
    reinterpret_cast<FUN_00485680*>(this)->M();
}

struct HairComparisonEntry : public TESHair
{
    bool TESForm_CompareAllComponents(TESForm*);
    bool TESHair_Compare(TESForm*);
};
// Returns true if apCompare is not a TESHair, differs per FUN_00485270, or has a different cFlags value.
// @fnv 0x005fded0
// src: XBOX_PDB 0x005fded0
bool HairComparisonEntry::TESHair_Compare(TESForm* apCompare)
{
    TESHair* pCompare = dynamic_cast<TESHair*>(apCompare);
    if (!pCompare)
        return true;
    if (TESForm_CompareAllComponents(pCompare))
        return true;
    if (pCompare->cFlags != cFlags)
        return true;
    return false;
}
