#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSLoadGameBuffer.h"
#include "../../include/BGSSaveGameBuffer.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint3.h"
#include "../../include/TES.h"
#include "../../include/TESCombatStyle.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/BGSSaveFormBuffer.h"

// src/fallout_shared/bgsworldlocation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgsworldlocation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CoordinateTriple
{
    bool BGSWorldLocation_IsLocationLoaded();
    TESObjectCELL* BGSWorldLocation_GetCell();
};
extern TES* g_TES;

// @fnv 0x00527a00
// src: XBOX_PDB 0x00527a00
bool CoordinateTriple::BGSWorldLocation_IsLocationLoaded()
{
    TESObjectCELL* pcell = BGSWorldLocation_GetCell();
    if (!pcell)
        return false;
    return g_TES->IsCellBuffered(pcell, false);
}

namespace fnv_00527a40 {

struct CoordinateTriple
{
    NiPoint3 pos;
    // +0x0c
    void* m_pPathingCell;
    float BGSWorldLocation_GetDistanceSquared(const CoordinateTriple& arWorldLocation);
};

// @fnv 0x00527a40
// src: XBOX_PDB 0x00527a40
float CoordinateTriple::BGSWorldLocation_GetDistanceSquared(const CoordinateTriple& arWorldLocation)
{
    if (this->m_pPathingCell != arWorldLocation.m_pPathingCell)
    {
        return 3.4028234663852886e+38f;
    }
    return (arWorldLocation.pos - this->pos).UpdateCombatStyle();
}
}  // namespace fnv_00527a40

struct Pt
{
    float x, y, z;
    float Length() const;
};
struct FUN_00527a80_shell
{
    NiPoint3 pos;
    int cell;
    float DistanceTo(FUN_00527a80_shell*);
};
// Returns the distance between this position and p's position if both are in the same cell, otherwise returns FLT_MAX.
// @fnv 0x00527a80
float FUN_00527a80_shell::DistanceTo(FUN_00527a80_shell* apOther)
{
    if (cell != apOther->cell)
        return 3.4028234663852886e+38F;
    return (apOther->pos - pos).Length();
}

struct FUN_00527b70_shell
{
    char _pad[12];
    void* m_pPathingCell;
    void BGSWorldLocation_SaveGame(BGSSaveGameBuffer*);
};
// @fnv 0x00527b70
// src: COMMUNITY 0x00527b70
void FUN_00527b70_shell::BGSWorldLocation_SaveGame(BGSSaveGameBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData(this, 0xC, 0);
    apSaveGameBuffer->SerializeFormData(m_pPathingCell, 0);
}

void* __cdecl _ref_004839c0(unsigned int);
bool __cdecl TESForm_ProcessAndReturnValue_00527b20(void*);
struct FUN_00527ba0_This
{
    char _pad[12];
    void* m_pPathingCell;
    void BGSLoadGameBuffer_LoadBGSWorldLocation(BGSLoadGameBuffer* apLoadGameBuffer);
};
// @fnv 0x00527ba0
// src: COMMUNITY 0x00527ba0
void FUN_00527ba0_This::BGSLoadGameBuffer_LoadBGSWorldLocation(BGSLoadGameBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData(this, 12);
    m_pPathingCell = _ref_004839c0(apLoadGameBuffer->ReadFormIdentifier());
    if (!TESForm_ProcessAndReturnValue_00527b20(m_pPathingCell))
        m_pPathingCell = 0;
}

struct FUN_00527990_shell
{
    char _pad[12];
    TESForm* pForm;
    bool BGSWorldLocation_GetCellOrWorld(int* apID, int* apType);
};
// @fnv 0x00527990
// src: XBOX_PDB 0x00527990
bool FUN_00527990_shell::BGSWorldLocation_GetCellOrWorld(int* apID, int* apType)
{
    if (!pForm)
        return false;
    int iType = pForm->FNV_GetFormType();
    if (iType == 0x41)
    {
        *apType = (int)pForm;
        *apID = 0;
        return true;
    }
    else if (iType == 0x39)
    {
        *apID = (int)pForm;
        *apType = 0;
        return true;
    }
    return false;
}


struct FUN_00527ac0_shell
{
    char _pad[12];
    float ComputeWeightedDistance(FUN_00527ac0_shell* apOther, NiPoint3* apDir);
};

// @fnv 0x00527ac0
float FUN_00527ac0_shell::ComputeWeightedDistance(FUN_00527ac0_shell* apOther, NiPoint3* apDir)
{
    if (*(int*)((char*)this + 0xc) != *(int*)((char*)apOther + 0xc))
        return 3.4028234663852886e+38f;
    NiPoint3 diff = ((NiPoint3*)apOther)->operator-(*(NiPoint3*)this);
    diff.x = diff.x * apDir->x;
    diff.y = diff.y * apDir->y;
    diff.z = diff.z * apDir->z;
    return ((TESCombatStyle*)&diff)->UpdateCombatStyle();
}

struct FUN_00425fd0_shell
{
    bool FUN_00425fd0();
};

// Returns true if form is null, has form type 0x41, or is a cell whose FUN_00425fd0 check succeeds; otherwise false.
// @fnv 0x00527b20
// src: GUESS 0x00527b20 (confidence: low)
bool __cdecl TESForm_ProcessAndReturnValue_00527b20(TESForm* form)
{
    if (form == 0)
        return true;

    switch (form->FNV_GetFormType())
    {
    case 0x41:
        return true;
    case 0x39: {
        FUN_00425fd0_shell* cell = (FUN_00425fd0_shell*)form;
        if (cell->FUN_00425fd0())
            return true;
        break;
    }
    }
    return false;
}

int _TruncateFloatToInt(float value);

struct FUN_00527900_Cell
{
    TESObjectCELL* FUN_005875a0(int cellX, int y);
};

struct FUN_00527900_shell
{
    float m_f0;
    float m_f4;
    int unk8;
    TESForm* pForm;

    TESObjectCELL* BGSWorldLocation_GetCell();
};

// Returns pForm for type 0x39, resolves type 0x41 using m_f0 and m_f4, and otherwise returns null.
// @fnv 0x00527900
// src: XBOX_PDB 0x00527900
TESObjectCELL* FUN_00527900_shell::BGSWorldLocation_GetCell()
{
    if (pForm == 0)
        return 0;

    int type = pForm->FNV_GetFormType();
    if (type == 0x39)
        return (TESObjectCELL*)pForm;
    else if (type == 0x41)
    {
        TESObjectCELL* pCell = (TESObjectCELL*)pForm;
        int cellX = _TruncateFloatToInt(m_f0) >> 12;
        int y = _TruncateFloatToInt(m_f4) >> 12;
        return ((FUN_00527900_Cell*)pCell)->FUN_005875a0(cellX, y);
    }
    return 0;
}
