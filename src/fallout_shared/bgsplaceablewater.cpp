// fallout_shared/bgsplaceablewater.cpp: BGSPlaceableWater (21 functions)

#include "bgsplaceablewater_decls.h"
#include "bgsplaceablewater_types_BGSPlaceableWater.h"
#include <malloc.h>

// @fnv 0x004fc1b0
BGSPlaceableWater::BGSPlaceableWater() : TESBoundObject(), TESModel()
{
    Data.FUN_004019f0();
    SetFormType(static_cast<ENUM_FORM_ID>(0x23));
    ResetFormData();
}

// Reinitializes the object returned by FUN_00624700 and calls the FUN_004fc360..FUN_004fc490 helpers with true/false flags.
// @fnv 0x004fc2e0
void BGSPlaceableWater::ResetFormData()
{
    GetExtraPartList()->Reinitialize();
    BGSPlaceableWater_SetReflectionEnabled(true);
    BGSPlaceableWater_SetReflectsLand(true);
    BGSPlaceableWater_SetReflectsLODLand(true);
    BGSPlaceableWater_SetReflectsSky(true);
    BGSPlaceableWater_SetRefractionEnabled(true);
    SetFlag800(true);
    BGSPlaceableWater_SetAutomaticWater(false);
    BGSPlaceableWater_SetObjectTexCoordsEnabled(false);
    BGSPlaceableWater_SetDepthEnabled(true);
    BGSPlaceableWater_SetUnderwaterFog(true);
}

// @fnv 0x004fc4b0
void BGSPlaceableWater::InitItem()
{
    if (GetInitialized())
        return;

    unsigned int formID = reinterpret_cast<unsigned int>(Data.m_pOwningWater);
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        Data.m_pOwningWater = dynamic_cast<TESWaterForm*>(GetFormByID(formID));
    }

    if (!Data.m_pOwningWater)
        Data.m_pOwningWater = DAT_011ca53c;
    SetInitializationState(true);
}

// Loads a BGSPlaceableWater record from a TESFile: validates form type 0x23, clears data, reads EDID/OBND/MODL/MODT/DATA/DNAM chunks, and returns true on success.
// @fnv 0x004fc540
bool BGSPlaceableWater::LoadForm(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x23)
        return false;

    ClearData();
    LoadRecordHeader(file);
    SetInitializationState(false);

    int chunkID;
    char* editorID;
    while ((chunkID = file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this ? reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x30) : 0, file);
            break;
        case 0x41544144: {
            PlaceableWaterData data;
            data.Reset();
            reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(file, &data, 8);
            if (reinterpret_cast<TESFileGetChunkData*>(file)->GetChunkData())
                data.OBJ_WEAP_CRITICAL_Endian();
            Data.m_pOwningWater = data.m_pOwningWater;
            Data.flags = 0;
            BGSPlaceableWater_SetReflectionEnabled(true);
            BGSPlaceableWater_SetReflectsLand(true);
            BGSPlaceableWater_SetReflectsLODLand(true);
            BGSPlaceableWater_SetReflectsSky(true);
            BGSPlaceableWater_SetRefractionEnabled(true);
            SetFlag800(true);
            BGSPlaceableWater_SetAutomaticWater(false);
            break;
        }
        case 0x4d414e44: {
            file->GetChunkData(&Data, 8);
            if (reinterpret_cast<TESFileFormVersion*>(file)->GetFormVersion() < 9)
                BGSPlaceableWater_SetAutomaticWater(false);
            if (reinterpret_cast<TESFileGetChunkData*>(file)->GetChunkData())
                Data.TwoValues_Endian();
            break;
        }
        }

        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_004fc380_shell : public BGSPlaceableWater
{
    void BGSPlaceableWater_SetReflectsLand(bool);
};

struct FUN_004fc990_t
{
    void __thiscall BGSPlaceableWater_SetFlag(int, bool);
};

// @fnv 0x004fc380
// src: COMMUNITY 0x004fc380
void FUN_004fc380_shell::BGSPlaceableWater_SetReflectsLand(bool abValue)
{
    reinterpret_cast<FUN_004fc990_t*>(this)->BGSPlaceableWater_SetFlag(4, abValue);
}

namespace fnv_004fc450 {
struct FUN_004fc450_shell : public BGSPlaceableWater
{
    void BGSPlaceableWater_SetAutomaticWater(bool);
};

struct FUN_004fc990_t
{
    void BGSPlaceableWater_SetFlag(int arg1, bool arg2);
};

// @fnv 0x004fc450
// src: COMMUNITY 0x004fc450
void FUN_004fc450_shell::BGSPlaceableWater_SetAutomaticWater(bool abValue)
{
    ((FUN_004fc990_t*)this)->BGSPlaceableWater_SetFlag(0x40000000, abValue);
}
}  // namespace fnv_004fc450

struct FUN_004fc790_shell
{
    unsigned short m0;
    unsigned int m4;
    FUN_004fc790_shell* Reset();
};

// Sets m0 and m4 to zero and returns this.
// @fnv 0x004fc790
FUN_004fc790_shell* FUN_004fc790_shell::Reset()
{
    m0 = 0;
    m4 = 0;
    return this;
}

struct FUN_004fc420_shell : public BGSPlaceableWater
{
    void BGSPlaceableWater_SetUnderwaterFog(bool);
};

// @fnv 0x004fc420
// src: COMMUNITY 0x004fc420
void FUN_004fc420_shell::BGSPlaceableWater_SetUnderwaterFog(bool abValue)
{
    ((FUN_004fc990_t*)this)->BGSPlaceableWater_SetFlag(0x80000000, abValue == 0);
}

struct FUN_005e78f0_t
{
    void __thiscall TESForm_CopyAllComponents(TESForm*);
};
void* __cdecl __memcpy(void*, const void*, unsigned int);
struct FUN_004fc860_shell : public BGSPlaceableWater
{
    void BGSPlaceableWater_Copy(TESForm* apCopy);
};
// @fnv 0x004fc860
// src: XBOX_PDB 0x004fc860
void FUN_004fc860_shell::BGSPlaceableWater_Copy(TESForm* apCopy)
{
    BGSPlaceableWater* pcopy;
    pcopy = dynamic_cast<BGSPlaceableWater*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents(pcopy);
    __memcpy(GetExtraPartList(), pcopy->GetExtraPartList(), 8);
}

// Sets or clears aiFlag in the flags of the object returned by FUN_00624700, depending on abSet.
// @fnv 0x004fc990
// src: COMMUNITY 0x004fc990
void FUN_004fc990_t::BGSPlaceableWater_SetFlag(int aiFlag, bool abSet)
{
    if (abSet)
        ((BGSPlaceableWater*)this)->GetExtraPartList()->flags |= aiFlag;
    else
        ((BGSPlaceableWater*)this)->GetExtraPartList()->flags &= ~aiFlag;
}

struct FUN_004fc360_shell : public BGSPlaceableWater
{
    void BGSPlaceableWater_SetReflectionEnabled(bool);
};

// @fnv 0x004fc360
// src: COMMUNITY 0x004fc360
void FUN_004fc360_shell::BGSPlaceableWater_SetReflectionEnabled(bool abValue)
{
    ((FUN_004fc990_t*)this)->BGSPlaceableWater_SetFlag(1, abValue);
}

struct FUN_004fc3a0_shell : public BGSPlaceableWater
{
    void BGSPlaceableWater_SetReflectsLODLand(bool);
};

// @fnv 0x004fc3a0
// src: COMMUNITY 0x004fc3a0
void FUN_004fc3a0_shell::BGSPlaceableWater_SetReflectsLODLand(bool abValue)
{
    ((FUN_004fc990_t*)this)->BGSPlaceableWater_SetFlag(8, abValue);
}

struct FUN_004fc3c0_shell : public BGSPlaceableWater
{
    void BGSPlaceableWater_SetReflectsSky(bool);
};

// @fnv 0x004fc3c0
// src: COMMUNITY 0x004fc3c0
void FUN_004fc3c0_shell::BGSPlaceableWater_SetReflectsSky(bool abValue)
{
    ((FUN_004fc990_t*)this)->BGSPlaceableWater_SetFlag(0x40, abValue);
}

struct FUN_004fc3e0_shell : public BGSPlaceableWater
{
    void BGSPlaceableWater_SetRefractionEnabled(bool);
};

// @fnv 0x004fc3e0
// src: COMMUNITY 0x004fc3e0
void FUN_004fc3e0_shell::BGSPlaceableWater_SetRefractionEnabled(bool abValue)
{
    ((FUN_004fc990_t*)this)->BGSPlaceableWater_SetFlag(0x200, abValue);
}

struct FUN_004fc400_shell : public BGSPlaceableWater
{
    void SetFlag800(bool);
};

// @fnv 0x004fc400
void FUN_004fc400_shell::SetFlag800(bool abValue)
{
    ((FUN_004fc990_t*)this)->BGSPlaceableWater_SetFlag(0x800, abValue);
}

struct FUN_004fc470_shell : public BGSPlaceableWater
{
    void BGSPlaceableWater_SetObjectTexCoordsEnabled(bool);
};

// @fnv 0x004fc470
// src: COMMUNITY 0x004fc470
void FUN_004fc470_shell::BGSPlaceableWater_SetObjectTexCoordsEnabled(bool abValue)
{
    ((FUN_004fc990_t*)this)->BGSPlaceableWater_SetFlag(0x20000000, abValue);
}

struct FUN_004fc490_shell : public BGSPlaceableWater
{
    void BGSPlaceableWater_SetDepthEnabled(bool);
};

// @fnv 0x004fc490
// src: COMMUNITY 0x004fc490
void FUN_004fc490_shell::BGSPlaceableWater_SetDepthEnabled(bool abValue)
{
    ((FUN_004fc990_t*)this)->BGSPlaceableWater_SetFlag(0x10000000, abValue);
}

struct FUN_005e79a0_t
{
    bool TESForm_CompareAllComponents(TESForm*);
};
extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);
extern char DAT_01183028;
struct FUN_004fc8c0_shell : public BGSPlaceableWater
{
    bool BGSPlaceableWater_Compare(TESForm* apCompare);
};
// @fnv 0x004fc8c0
// src: XBOX_PDB 0x004fc8c0
bool FUN_004fc8c0_shell::BGSPlaceableWater_Compare(TESForm* apCompare)
{
    BGSPlaceableWater* pcomp = dynamic_cast<BGSPlaceableWater*>(apCompare);
    if (!pcomp)
        return true;
    if (((FUN_005e79a0_t*)this)->TESForm_CompareAllComponents(pcomp))
        return true;
    if (memcmp((char*)this + 0x48, pcomp->GetExtraPartList(), 8))
        return true;
    return false;
}

struct FUN_005802d0_shell : public FUN_004fc990_t
{
    void BGSPlaceableWater_SetReflectsLODBuildings(bool flag);
};

// @fnv 0x005802d0
// src: COMMUNITY 0x005802d0
void FUN_005802d0_shell::BGSPlaceableWater_SetReflectsLODBuildings(bool flag)
{
    BGSPlaceableWater_SetFlag(0x10, flag);
}

class ModelCallees
{
  public:
    void WriteToBuffer(unsigned int chunkA, unsigned int chunkB);
};

class WaterFormCallees
{
  public:
    void* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

class FUN_004fc7b0_cls : public BGSPlaceableWater
{
  public:
    void BeginFormRecord();
    void FinishFormRecord();
    void BGSPlaceableWater_SaveAlt();
};

bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl FUN_00401460(void* dst, void* src, unsigned int size);
void __cdecl AppendChunk(unsigned int chunkId, void* data, unsigned int size);

// @fnv 0x004fc7b0
// src: COMMUNITY 0x004fc7b0
void FUN_004fc7b0_cls::BGSPlaceableWater_SaveAlt()
{
    BeginFormRecord();
    ((ModelCallees*)((char*)this + 0x30))->WriteToBuffer(0x4c444f4d, 0x54444f4d);
    PlaceableWaterData waterFormData;
    waterFormData.FUN_004019f0();
    FUN_00401460(&waterFormData, &Data, 8);
    waterFormData.m_pOwningWater =
        (TESWaterForm*)((Data.m_pOwningWater != 0) ? ((WaterFormCallees*)Data.m_pOwningWater)->GetHavokWorldObjectCountInSceneGraph_0084e3a0() : 0);
    if (TESForm_QEndianSwapOnSave())
    {
        waterFormData.TwoValues_Endian();
    }
    AppendChunk(0x4d414e44, &waterFormData, 8);
    if (TESForm_QEndianSwapOnSave())
    {
        waterFormData.TwoValues_Endian();
    }
    FinishFormRecord();
}

// @fnv 0x004fc240
struct FUN_004fc240 : public BGSPlaceableWater
{
    virtual ~FUN_004fc240();
};
FUN_004fc240::~FUN_004fc240()
{}
