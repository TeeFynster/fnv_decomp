#include "../../include/Setting.h"
// 0x00408d60 returns the setting value at +4 (or a fallback byte for null this).

#include "../../include/BSShaderNoLightingProperty.h"
#include "../../include/BSTextureManager.h"
#include "../../include/AutoMemHelper.h"
#include "../../include/ExtraDataList.h"
#include "../../include/GO.h"
#include "../../include/GridArray.h"
#include "../../include/GridCellArray.h"
#include "../../include/NiColor.h"
#include "../../include/NiColorA.h"
#include "../../include/NiDynamicEffect.h"
#include "../../include/NiFrustum.h"
#include "../../include/NiNode.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiUpdateData.h"
#include "../../include/NiPoint3.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/TESObjectLAND.h"
#include "../../include/TESObjectWEAP.h"
// fallout_shared/gridcell.cpp: GridCellArray and helpers (43 functions)

class GridCell
{
  public:
    TESObjectCELL* pCell;
};

// @fnv 0x004ba5e0
void GridCellArray::Init(void)
{
    GridArray::Init();
    TESObjectCELL::InitializeCell();
}

// Returns the grid cell at (gridX, gridY) if both are within the array dimension, otherwise returns null.
// @fnv 0x004ba490
GridCell* GridCellArray::Get(unsigned int gridX, unsigned int gridY)
{
    unsigned int dimension = GetGridDimension();
    if (gridX >= dimension || gridY >= dimension)
        return 0;
    return &m_pGridCells[GetGridDimension() * gridX + gridY];
}

// Detaches the grid cell at (gridX, gridY) if it has a cell, then nulls that grid slot.
// @fnv 0x004ba6b0
void GridCellArray::Detach(unsigned int gridX, unsigned int gridY)
{
    GridCell* gridCell = Get(gridX, gridY);
    if (gridCell->pCell)
    {
        gridCell->pCell->Detach(true);
        ClearTileExtraPair(gridX, gridY);
    }
}

// @fnv 0x004ba8d0
void GridCellArray::ReleaseGridCells(void)
{
    unsigned int dimension = GetGridDimension();
    for (unsigned int gridX = 0; gridX < dimension; ++gridX)
    {
        for (unsigned int gridY = 0; gridY < dimension; ++gridY)
        {
            GridCell* gridCell = Get(gridX, gridY);
            if (gridCell && gridCell->pCell)
            {
                gridCell->pCell->GetLandscape()->ResetFadeOutMultipliers();
            }
        }
    }
}

struct V3
{
    float x, y, z;
};
struct FUN_00440460_S
{
    char pad[0x58];
    V3 t;
    void NiAVObject_SetTranslate(const V3* k);
};
// Copies the V3 pointed to by k into the t member.
// @fnv 0x00440460
// src: XBOX_PDB 0x00440460
void FUN_00440460_S::NiAVObject_SetTranslate(const V3* k)
{
    t = *k;
}

// @fnv 0x004bae00
// src: XBOX_PDB 0x004bae00
bool __fastcall bhkWorld_QDebugDisplay(const char* pThis)
{
    return *(const bool*)(pThis + 0x16);
}

class RenderedTextureString : public BSStringT<char>
{
  public:
    operator const char*() const;
};

extern char DAT_01189184;
void __cdecl BSShaderManager_SetProjectedShadowMaskTexture(int);
BSTextureManager* __stdcall BSShaderManager_GetTextureManager();

// @fnv 0x004baec0
// src: XBOX_PDB 0x004baec0
void GridCellArray::ClearCanopyShadowMaskTexture()
{
    if (reinterpret_cast<RenderedTextureString*>(&spRT)->operator const char*())
    {
        BSShaderManager_SetProjectedShadowMaskTexture(0);
        BSShaderManager_GetTextureManager()->AddRenderedTexture(reinterpret_cast<BSRenderedTexture*>(const_cast<char*>(
            reinterpret_cast<RenderedTextureString*>(&spRT)->operator const char*())));
        reinterpret_cast<NiPointer<NiNode>*>(&spRT)->operator=(0);
        DAT_01189184 = 1;
    }
}

struct FUN_004bc1f0_S
{
    char pad[0x58];
    NiPoint3 t;
    void NiAVObject_SetTranslate_004bc1f0(float x, float y, float z);
};
// Stores the given x, y and z into the t point of this object.
// @fnv 0x004bc1f0
// src: XBOX_PDB 0x004bc1f0
void FUN_004bc1f0_S::NiAVObject_SetTranslate_004bc1f0(float x, float y, float z)
{
    t = NiPoint3(x, y, z);
}

struct C3
{
    float r, g, b;
};

struct FUN_004bc280_S
{
    char pad[0xc8];
    C3 c;
    void NiLight_SetAmbientColor(const C3* k);
};
// Copies the C3 value pointed to by k into c, then calls IncRevisionID.
// @fnv 0x004bc280
// src: COMMUNITY 0x004bc280
void FUN_004bc280_S::NiLight_SetAmbientColor(const C3* apColor)
{
    c = *apColor;
    reinterpret_cast<NiDynamicEffect*>(this)->IncRevisionID();
}

// Stores the given NiColor at offset 0xD4 of this object and increments the revision ID.
// @fnv 0x004bc2e0
void NiDynamicEffect::SetEffectColor(const NiColor& color)
{
    *reinterpret_cast<NiColor*>(reinterpret_cast<char*>(this) + 0xD4) = color;
    IncRevisionID();
}



extern Setting g_011c75a4;

// @fnv 0x004bc400
// src: COMMUNITY 0x004bc400
unsigned char TESRenderer_GetDoCanopyShadowPass()
{
    return *g_011c75a4.FUN_00408d60();
}

namespace fnv_004bc450 {
struct C3
{
    float r, g, b;
};
struct FUN_004bc450_S
{
    char pad[0x28];
    C3 c;
    void NiMaterialProperty_SetChanged(int);
    void NiMaterialProperty_SetEmittance(const C3* k);
};
// Copies the C3 value pointed to by k into the c member and calls FUN_004bc480 with 1.
// @fnv 0x004bc450
// src: XBOX_PDB 0x004bc450
void FUN_004bc450_S::NiMaterialProperty_SetEmittance(const C3* apColor)
{
    c = *apColor;
    NiMaterialProperty_SetChanged(1);
}
}  // namespace fnv_004bc450

class _Dummy_004bc4a0
{
  public:
    char _pad[0x84];
    bool m_bAccumulate;
    void SetAccumulate(bool abTF);
};

// @fnv 0x004bc4a0
void _Dummy_004bc4a0::SetAccumulate(bool abTF)
{
    m_bAccumulate = abTF;
}

// @fnv 0x004ba5a0
bool GridCellArray::IsOutdoorCell(unsigned int aiX, unsigned int aiY)
{
    GridCell* pgridcell = Get(aiX, aiY);
    if (pgridcell->pCell)
        return pgridcell->pCell->IsOutdoorCell();
    return false;
}

extern int DAT_011f91d8;

// @fnv 0x004bc3d0
// src: COMMUNITY 0x004bc3d0
void BSShaderManager_SetEnabledPasses(int aiEnabledPasses)
{
    DAT_011f91d8 = aiEnabledPasses;
}

extern int DAT_011f91d8;

// @fnv 0x004bc3e0
// src: COMMUNITY 0x004bc3e0
int __cdecl BSShaderManager_GetEnabledPasses()
{
    return DAT_011f91d8;
}

struct Flt
{
    operator unsigned int(void) const;
};

extern Flt g_011c73b4;

// @fnv 0x004bc3f0
// src: XBOX_PDB 0x004bc3f0
unsigned int Renderer_GetNIRenderer()
{
    return g_011c73b4.operator unsigned int();
}

extern float DAT_011fd874;
extern float DAT_011fd878;

// @fnv 0x004bc420
// src: COMMUNITY 0x004bc420
void __cdecl ShadowLightShader_SetProjectedShadowMaskLL(float afValue1, float afValue2)
{
    DAT_011fd874 = afValue1;
    DAT_011fd878 = afValue2;
}

extern float DAT_011fd880;

// @fnv 0x004bc440
// src: COMMUNITY 0x004bc440
void ShadowLightShader_SetProjectedShadowMaskWidth(float value)
{
    DAT_011fd880 = value;
}

// Clears the grid cell at (aiX, aiY) by nulling its pCell and the byte at offset 0x20 of this.
// @fnv 0x004ba700
void GridCellArray::ClearTileExtraPair(unsigned int aiX, unsigned int aiY)
{
    GridCell* pgridcell = Get(aiX, aiY);
    pgridcell->pCell = 0;
    *reinterpret_cast<char*>(&unk20) = 0;
}

void _Deallocate(void*);
// Stores apCell into the grid cell at (aiX, aiY), or clears that cell when apCell is null.
// @fnv 0x004ba550
void GridCellArray::SetCellAt(unsigned int aiX, unsigned int aiY, TESObjectCELL* apCell)
{
    GridCell* pgridcell;
    if (apCell)
    {
        pgridcell = Get(aiX, aiY);
        pgridcell->pCell = apCell;
    }
    else
    {
        ClearTileExtraPair(aiX, aiY);
    }
}

struct DH
{
    bool TESDataHandler_GetClearingData();
};
extern DH* g_dataHandler;
struct FUN_004b9e90_shell
{
    void CallVirtualMethod2();
};
void TESObjectCELL_KillStatics();
// Calls CallVirtualMethod2 on this, then calls FUN_00541c00 if g_dataHandler->FUN_004226e0() returns true.
// @fnv 0x004ba600
// src: XBOX_PDB 0x004ba600
void GridCellArray::KillAll()
{
    ((FUN_004b9e90_shell*)this)->CallVirtualMethod2();
    if (g_dataHandler->TESDataHandler_GetClearingData())
        TESObjectCELL_KillStatics();
}

extern "C" void TESObjectCELL_MoveExteriorWorld(float*);

// @fnv 0x004ba630
bool GridCellArray::SetGridCellPosition(int aiX, int aiY)
{
    bool bretval = false;
    if (GridArray::SetGridPosition(aiX, aiY))
    {
        fX = static_cast<float>(aiX << 12);
        fY = static_cast<float>(aiY << 12);
        *reinterpret_cast<float*>(&unk1c) = 0.0f;
        TESObjectCELL_MoveExteriorWorld(&fX);
        bretval = true;
        *reinterpret_cast<char*>(&unk20) = 0;
    }
    return bretval;
}

// @fnv 0x004ba740
void GridCellArray::SetFrom(unsigned int aiX1, unsigned int aiY1, unsigned int aiX2, unsigned int aiY2)
{
    SetCellAtXY(aiX2, aiY2, Get(aiX1, aiY1));
}

// Copies the cell at (aiX1, aiY1) into a temporary, then swaps the cells at the two coordinate pairs via SetCellAtXY.
// @fnv 0x004ba770
void GridCellArray::SwapCells(unsigned int aiX1, unsigned int aiY1, unsigned int aiX2, unsigned int aiY2)
{
    GridCell tempgridcell;
    GridCell* pgc;
    pgc = Get(aiX1, aiY1);
    tempgridcell = *pgc;
    SetCellAtXY(aiX1, aiY1, Get(aiX2, aiY2));
    SetCellAtXY(aiX2, aiY2, &tempgridcell);
}

struct FUN_00552970_Call
{
    void UpdateCellScene(NiNode* apRoot);
};
// Gets the grid cell at (aiX, aiY) and, if it has a cell, forwards apRoot to that cell's UpdateCellScene.
// @fnv 0x004ba960
// src: COMMUNITY 0x004ba960
void GridCellArray::AttachToWorld(NiNode* apRoot, unsigned int aiX, unsigned int aiY)
{
    GridCell* pgridcell;
    pgridcell = Get(aiX, aiY);
    if (pgridcell->pCell)
        ((FUN_00552970_Call*)pgridcell->pCell)->UpdateCellScene(apRoot);
}

struct Arr
{
    unsigned int* GetAt(int);
};
struct KFModel
{
    void* GetControllerSequence();
};
struct CLS_004bc240
{
    char _pad[0x1c];
    Arr arr;
    void* NiTexturingProperty_GetBaseTexture();
};
// @fnv 0x004bc240
// src: COMMUNITY 0x004bc240
void* CLS_004bc240::NiTexturingProperty_GetBaseTexture()
{
    KFModel* p = *(KFModel**)arr.GetAt(0);
    if (p)
        return p->GetControllerSequence();
    else
        return 0;
}

struct FUN_004bc480_shell
{
    unsigned char pad_00_44[0x44];
    unsigned int m_44;
    void NiMaterialProperty_SetChanged(int arg);
};

// @fnv 0x004bc480
// src: XBOX_PDB 0x004bc480
void FUN_004bc480_shell::NiMaterialProperty_SetChanged(int arg)
{
    ++m_44;
}

struct bhkWorld;
bool __fastcall bhkWorld_QDebugDisplay(char const*);
// @fnv 0x004bad40
// src: COMMUNITY 0x004bad40
void GridCellArray::ToggleCollisionGeometry_004bad40()
{
    bhkWorld* pWorld = TESObjectCELL::GetExteriorbhkWorld();
    if (pWorld)
    {
        bool b = !bhkWorld_QDebugDisplay((const char*)pWorld);
        for (unsigned int i = 0; i < GetGridDimension(); ++i)
            for (unsigned int j = 0; j < GetGridDimension(); ++j)
            {
                GridCell* cell = Get(i, j);
                if (cell->pCell && cell->pCell->IsOutdoorCell())
                    ((ExtraDataList*)cell->pCell)->TESObjectCELL_SetCollisionGeometryDisplay(b);
            }
    }
}

struct FUN_005549d0_shell
{
    void TESObjectCELL_TogglePrimitives(bool);
};
// @fnv 0x004bae20
// src: COMMUNITY 0x004bae20
void GridCellArray::TogglePrimitives_004bae20(bool detach)
{
    bhkWorld* world = TESObjectCELL::GetExteriorbhkWorld();
    if (world)
    {
        for (unsigned int x = 0; x < GetGridDimension(); ++x)
        {
            for (unsigned int y = 0; y < GetGridDimension(); ++y)
            {
                GridCell* cell = Get(x, y);
                if (cell->pCell && cell->pCell->IsOutdoorCell())
                    ((FUN_005549d0_shell*)cell->pCell)->TESObjectCELL_TogglePrimitives(detach);
            }
        }
    }
}

struct FUN_00553820_shell
{
    void TESObjectCELL_RunAnimations();
};
// Iterates every grid cell and calls FUN_00553820 on each cell's pCell when it is non-null.
// @fnv 0x004baba0
// src: COMMUNITY 0x004baba0
void GridCellArray::RunAnimations_004baba0()
{
    unsigned int i;
    for (i = 0; i < GetGridDimension(); i++)
    {
        unsigned int j;
        for (j = 0; j < GetGridDimension(); j++)
        {
            GridCell* cell = Get(i, j);
            if (cell->pCell)
                reinterpret_cast<FUN_00553820_shell*>(cell->pCell)->TESObjectCELL_RunAnimations();
        }
    }
}

struct CellOwner
{
    void PlayCellSoundEffects();
};
// Iterates every grid cell and calls PlayCellSoundEffects on each cell's pCell when both the cell and its pCell are non-null.
// @fnv 0x004bac20
// src: COMMUNITY 0x004bac20
void GridCellArray::UpdateRefSounds_004bac20()
{
    for (unsigned int x = 0; x < GetGridDimension(); ++x)
    {
        for (unsigned int y = 0; y < GetGridDimension(); ++y)
        {
            GridCell* cell = Get(x, y);
            if (cell && cell->pCell)
                ((CellOwner*)cell->pCell)->PlayCellSoundEffects();
        }
    }
}

struct LAND_x
{
    void TESObjectLAND_DrawLandBorder(bool);
};

// Iterates every grid cell and, for cells whose cell has a LAND, calls FUN_0053fa40 with abShow.
// @fnv 0x004baca0
// src: COMMUNITY 0x004baca0
void GridCellArray::ShowLandBorders(bool abShow)
{
    for (unsigned int x = 0; x < GetGridDimension(); ++x)
    {
        for (unsigned int y = 0; y < GetGridDimension(); ++y)
        {
            GridCell* pgridcell = Get(x, y);
            if (pgridcell->pCell && pgridcell->pCell->IsOutdoorCell())
            {
                TESObjectLAND* pland = pgridcell->pCell->GetLandscape();
                if (pland)
                    reinterpret_cast<LAND_x*>(pland)->TESObjectLAND_DrawLandBorder(abShow);
            }
        }
    }
}

typedef AutoMemHelper AutoMemContext;

struct FUN_005535f0_shell
{
    void SetupMopp();
};

extern char const str_010206c0[];

void __fastcall TESObjectLAND_Attach3D(TESObjectLAND* land);

// @fnv 0x004ba7d0
// src: COMMUNITY 0x004ba7d0
void GridCellArray::AttachAllLand3D()
{
    if (*reinterpret_cast<bool*>(&unk20))
        return;

    unsigned int idim;
    AutoMemContext tempMemContext(0x1b, true, str_010206c0, 0x10d);

    idim = this->GetGridDimension();
    for (unsigned int ix = 0; ix < idim; ++ix)
    {
        for (unsigned int iy = 0; iy < idim; ++iy)
        {
            GridCell* pgc = Get(ix, iy);
            if (pgc && pgc->pCell)
            {
                TESObjectLAND_Attach3D(pgc->pCell->GetLandscape());

                reinterpret_cast<FUN_005535f0_shell*>(pgc->pCell)->SetupMopp();
            }
        }
    }

    *reinterpret_cast<bool*>(&unk20) = true;
}

void __cdecl CallIfPresent(float value);

extern bool DAT_011c642c;

struct Zt5Cell
{
    void TESObjectCELL_UpdateManagedNodes(float value, bool flag);
};

// @fnv 0x004ba9a0
void GridCellArray::UpdateCellGrid(float value)
{
    GridCell* idim;
    unsigned int idimedge;
    unsigned int x;
    unsigned int y;
    bool bupdate;
    unsigned int pgridcell;

    CallIfPresent(value);

    y = GetGridDimension();
    pgridcell = y - 1;

    DAT_011c642c = !DAT_011c642c;

    for (x = 0; x < y; ++x)
    {
        for (idimedge = 0; idimedge < y; ++idimedge)
        {
            bupdate = true;

            if (x == 0 || idimedge == 0 || x == pgridcell || idimedge == pgridcell)
            {
                if ((x ^ idimedge) & 1)
                    bupdate = false;

                if (DAT_011c642c)
                    bupdate = !bupdate;
            }

            idim = Get(x, idimedge);

            if (idim->pCell != 0)
            {
                reinterpret_cast<Zt5Cell*>(idim->pCell)->TESObjectCELL_UpdateManagedNodes(value, !bupdate);
            }
        }
    }
}

extern unsigned int _data_011c16bc;

struct FUN_004bc320_shell
{
    unsigned char _pad_0[0x30];
    GO m_textures[1];

    unsigned int BSRenderedTexture_GetTexture(int aiIndex);
};

// Returns the unsigned int value of the texture at aiIndex, or 0 when this is null.
// @fnv 0x004bc320
// src: COMMUNITY 0x004bc320
unsigned int FUN_004bc320_shell::BSRenderedTexture_GetTexture(int aiIndex)
{
    return (this ? m_textures[aiIndex] : GO(0)).operator unsigned int();
}

void _Deallocate(void*);

// Calls FUN_004ba600 and FUN_004baec0, then deallocates the grid cell storage.
// @fnv 0x004ba400
GridCellArray::~GridCellArray()
{
    KillAll();
    ClearCanopyShadowMaskTexture();
    void* p = m_pGridCells;
    _Deallocate(p);
}

// Stores the cell pointer from apCell into the grid at (aiX, aiY) if in bounds, or clears that grid slot when apCell is null.
// @fnv 0x004ba4e0
void GridCellArray::SetCellAtXY(unsigned int aiX, unsigned int aiY, GridCell* apCell)
{
    unsigned int dim = GetGridDimension();
    if (aiX >= dim || aiY >= dim)
    {
        return;
    }
    if (apCell != 0)
    {
        m_pGridCells[GetGridDimension() * aiX + aiY].pCell = apCell->pCell;
    }
    else
    {
        ClearTileExtraPair(aiX, aiY);
    }
}

struct FUN_00552840_cell
{
    void TESObjectCELL_UpdateManagedNodeTransforms();
};

extern bool DAT_011c642d;

// Flips DAT_011c642d, then for each grid cell on the border whose checkerboard parity matches, calls FUN_00552840 on the cell's pCell if non-null.
// @fnv 0x004baab0
// src: COMMUNITY 0x004baab0
void GridCellArray::UpdateManagedNodeTransforms()
{
    unsigned int dim = this->GetGridDimension();
    unsigned int last = dim - 1;
    DAT_011c642d = !DAT_011c642d;
    for (unsigned int i = 0; i < dim; i++)
    {
        for (unsigned int j = 0; j < dim; j++)
        {
            bool flag = true;
            if (i == 0 || j == 0 || i == last || j == last)
            {
                if (((i ^ j) & 1) != 0)
                {
                    flag = false;
                }
                if (DAT_011c642d)
                {
                    flag = !flag;
                }
            }
            if (flag)
            {
                GridCell* cell = this->Get(i, j);
                if (cell->pCell != 0)
                {
                    reinterpret_cast<FUN_00552840_cell*>(cell->pCell)->TESObjectCELL_UpdateManagedNodeTransforms();
                }
            }
        }
    }
}

struct InventoryItem
{
    bool FUN_00418750();
    short ExtraDataList_GetCount();
};
struct LinkedEntry
{
    InventoryItem** FUN_006815c0();
    LinkedEntry* FUN_00726070();
};
struct FUN_004bcc30_List
{
    LinkedEntry* first;
    int ItemChange_NumberLeveledExtra();
};
// Walks the linked entries and sums the short value of each item whose check returns true, stopping at the first null entry or null item pointer.
// @fnv 0x004bcc30
// src: XBOX_PDB 0x004bcc30
int FUN_004bcc30_List::ItemChange_NumberLeveledExtra()
{
    LinkedEntry* pEntry = first;
    int total = 0;
    while (pEntry && *pEntry->FUN_006815c0())
    {
        InventoryItem* item = *pEntry->FUN_006815c0();
        if (item && item->FUN_00418750())
        {
            total += item->ExtraDataList_GetCount();
        }
        pEntry = pEntry->FUN_00726070();
    }
    return total;
}

struct HealthForm4bcdb0
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual int GetHealth();
};
HealthForm4bcdb0* GetHealthForm(TESBoundObject* pkForm);
struct HealthExtra4bcdb0
{
    float ExtraDataList_GetHealth();
};
struct HealthList4bcdb0
{
    HealthExtra4bcdb0*& FUN_006815c0();
};
float BSMIN(float a, float b);
extern const float g_011c7294_arg1;
extern const float DAT_01012054;
extern double DAT_01017a40;
struct FUN_004bcdb0_shell
{
    HealthList4bcdb0* m_pkExtendData;
    int m_iArrayLength;
    TESBoundObject* m_pkForm;
    bool HasEffect(int iFlag);
    float ItemChange_GetItemHealth(bool bPercent);
};
// @fnv 0x004bcdb0
// src: XBOX_PDB 0x004bcdb0
float FUN_004bcdb0_shell::ItemChange_GetItemHealth(bool bPercent)
{
    HealthForm4bcdb0* pkHealth = GetHealthForm(m_pkForm);
    if (pkHealth)
    {
        TESObjectWEAP* pkWeapon5 = dynamic_cast<TESObjectWEAP*>(m_pkForm);
        int m_uiHealthValue = pkHealth->GetHealth();
        if (pkWeapon5)
            m_uiHealthValue = pkWeapon5->GetModdedValue(HasEffect(10));
        HealthList4bcdb0* pkList2 = m_pkExtendData;
        if (pkList2 && pkList2->FUN_006815c0())
        {
            HealthExtra4bcdb0* pkExtra = pkList2->FUN_006815c0();
            if (pkExtra && pkExtra->ExtraDataList_GetHealth() != -1.0)
            {
                if (!bPercent)
                    return pkExtra->ExtraDataList_GetHealth();
                else
                    return BSMIN(g_011c7294_arg1, pkExtra->ExtraDataList_GetHealth() / m_uiHealthValue) * DAT_01017a40;
            }
            else
            {
                if (!bPercent)
                    return m_uiHealthValue;
                else
                    return g_011c7294_arg1;
            }
        }
        else
        {
            if (!bPercent)
                return m_uiHealthValue;
            else
                return g_011c7294_arg1;
        }
    }
    return DAT_01012054;
}

struct Pt2
{
    float x, y;
    Pt2();
    Pt2(float, float);
};

struct IDev
{
    virtual void __stdcall v00();
    virtual void __stdcall v01();
    virtual void __stdcall v02();
    virtual void __stdcall v03();
    virtual void __stdcall v04();
    virtual void __stdcall v05();
    virtual void __stdcall v06();
    virtual void __stdcall v07();
    virtual void __stdcall v08();
    virtual void __stdcall v09();
    virtual void __stdcall v10();
    virtual void __stdcall v11();
    virtual void __stdcall v12();
    virtual void __stdcall v13();
    virtual void __stdcall v14();
    virtual void __stdcall v15();
    virtual void __stdcall v16();
    virtual void __stdcall v17();
    virtual void __stdcall v18();
    virtual void __stdcall v19();
    virtual long __stdcall SetFoo(int);
};

struct Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual IDev* GetDev();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void SetBackground(const void*);
    virtual void v44();
    virtual void GetBackground(void*);
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void SetFlag(int);
    virtual void v53();
    virtual void v54();

    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);

    Obj* GetTex();
    void GetTransformScale(const NiPoint3*);
    void Update(NiUpdateData*);
    void SetTarget(void*, void*);
    void UpdateViewFrustum(NiFrustum*);
    void SetAmbient(void*);
    void SetDiffuse(void*);
    void AttachAffected(Obj*);
    void SetColA(void*);
    void SetColB(void*);
    void SetEmit(void*);
    void SetMode(int);
    void SetEnabled(bool);
    unsigned int GetRT();
    unsigned int GetTexIdx(int);
};

struct TriData : Obj
{
    unsigned int unk04[(0x50 - 4) / 4];
    TriData(unsigned int, NiPoint3*, NiPoint3*, void*, Pt2*, unsigned int, unsigned int, unsigned int, unsigned int,
            unsigned short*, unsigned short*);
};
struct TriStrips : Obj
{
    unsigned int unk04[(0xc4 - 4) / 4];
    TriStrips(Obj*);
};
struct Camera : Obj
{
    unsigned int unk04[(0x114 - 4) / 4];
    Camera();
};
struct Light : Obj
{
    unsigned int unk04[(0xfc - 4) / 4];
    Light();
};
struct MatProp : Obj
{
    unsigned int unk04[(0x4c - 4) / 4];
    MatProp();
};
struct StencilProp : Obj
{
    unsigned int unk04[(0x24 - 4) / 4];
    StencilProp();
};
struct RTex : Obj
{
    unsigned int unk04[(0x280 - 4) / 4];
    RTex(unsigned int, unsigned int, unsigned int);
};

struct VisArray
{
    unsigned int unk00[0xc4 / 4];
    VisArray(int);
    ~VisArray();
    void SetCamera(Obj*);
};

struct TexMgr
{
    Obj* Create(void*);
};
TexMgr* __stdcall GetTexMgr();
void* __stdcall MakeFormat(int, int, int, int);
Obj* GetSys();
void RenderA(int, unsigned int);
void RenderB(Obj*, Obj*, VisArray*);
void RenderC(Obj*, Obj*, int);
void RenderD();
extern char DAT_011a9bd0;

struct LoadInfo
{
    int a;
    int iFlag;
};

struct Cell
{
    int GetTexInfo(Obj** apTex, LoadInfo** apInfo);
};

struct Holder
{
    unsigned int GetObj();
};
Holder* GetHolder();

void* AllocShort(unsigned int);
void SetRenderFlags(int);
int GetRenderFlags();
Obj* GetRenderer();
unsigned char IsRenderReady();
void SetOrigin(Pt2);
void SetScale(float);
void SetTexture(unsigned int);
void Prep(Obj*, int, int);

extern char DAT_01189184;
extern NiPoint3 DAT_011a9484;
extern char DAT_011a9478;
extern char DAT_011f426c;
extern char DAT_011a9b7c;

// Builds a grid of textured cell meshes, sets up an orthographic camera and light, and renders the scene into a render target texture.
// @fnv 0x004baf10
// src: COMMUNITY 0x004baf10
void GridCellArray::RecreateCanopyShadowMaskTexture()
{
    Obj* pStencil4;
    Obj* pMat8;
    IDev* pDev4;
    Obj* pTailB;
    NiPoint3* pValueVal;
    unsigned short* pTrisA;
    Pt2* puVal;
    unsigned short* _pLens;
    NiPoint3* pNewA;
    unsigned int uiDimVal;
    bool bAllEmpty7;
    float fHalf5;
    AutoMemContext ctx(0x20, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\GridCell.cpp", 0x220);
    int iResult;
    LoadInfo* pInfo9;
    BSShaderNoLightingProperty* PPTmp = 0;
    NiPointer<NiNode> m_pMenuLightParameters(0);
    unsigned int i;
    unsigned int julietz59_2;
    NiPointer<NiNode> sp5_2(0);
    GridCellObjectRefView spCamera4(0);
    float aFHalfDim;
    GridCellObjectRefView spData3(0);
    GridCellObjectRefView spData_(0);
    float fSize6;
    NiFrustum kFrustumVal;
    kFrustumVal.Init(false);
    bool bAllLoaded7;
    GridCellObjectRefView spCameraVal(0);
    Obj* pTexVal;
    NiPoint3 kPos3;
    NiColorA kColorA(0.0f, 0.0f, 0.0f, 0.0f);
    Cell* pCam9;
    uiDimVal = GetGridDimension();
    bAllEmpty7 = true;
    bAllLoaded7 = true;
    DAT_01189184 = 0;
    if (!IsRenderReady())
        return;
    fSize6 = (float)(GetGridDimension() << 12);
    fHalf5 = 2048.0 - fSize6 / 2.0;
    SetOrigin(Pt2(fX + fHalf5, fY + fHalf5));
    SetScale(fSize6);
    SetRenderFlags(GetRenderFlags() | 0x20);
    if (uiDimVal == 0 || GetRenderer() == 0)
    {
        SetRenderFlags(GetRenderFlags() & ~0x20);
        SetTexture(0);
        return;
    }
    aFHalfDim = uiDimVal / 2.0;
    kPos3.y = aFHalfDim * -1.0;
    kPos3.x = kPos3.y;
    kPos3.z = 0.0f;
    m_pMenuLightParameters = new NiNode(0);

    pValueVal = new NiPoint3[4];
    pValueVal[0] = NiPoint3(0.0f, 0.0f, 0.0f);
    pValueVal[1] = NiPoint3(1.0f, 0.0f, 0.0f);
    pValueVal[2] = NiPoint3(1.0f, 1.0f, 0.0f);
    pValueVal[3] = NiPoint3(0.0f, 1.0f, 0.0f);

    pNewA = new NiPoint3[4];
    pNewA[0] = pNewA[1] = pNewA[2] = pNewA[3] = DAT_011a9484;

    puVal = new Pt2[4];
    puVal[0] = Pt2(0.0f, 0.0f);
    puVal[1] = Pt2(1.0f, 0.0f);
    puVal[2] = Pt2(1.0f, 1.0f);
    puVal[3] = Pt2(0.0f, 1.0f);

    pTrisA = (unsigned short*)AllocShort(8);
    pTrisA[0] = 1;
    pTrisA[1] = 0;
    pTrisA[2] = 2;
    pTrisA[3] = 3;
    _pLens = (unsigned short*)AllocShort(2);
    _pLens[0] = 4;

    spData3 = new TriData(4, pValueVal, pNewA, 0, puVal, 1, 0, 2, 1, _pLens, pTrisA);

    for (i = 0; i < uiDimVal; i++)
    {
        for (julietz59_2 = 0; julietz59_2 < uiDimVal; julietz59_2++)
        {
            PPTmp = 0;
            pCam9 = reinterpret_cast<Cell*>(Get(i, julietz59_2)->pCell);
            if (pCam9)
            {
                iResult = pCam9->GetTexInfo(&pTexVal, &pInfo9);
                if (pTexVal && pInfo9 && pInfo9->iFlag)
                {
                    pTailB = pTexVal->GetTex();
                    pDev4 = pTailB->GetDev();
                    pDev4->SetFoo(0);
                    pInfo9->iFlag = 0;
                }
                if (iResult == 1 && pTexVal)
                {
                    PPTmp = new BSShaderNoLightingProperty();
                    PPTmp->BSShaderNoLightingProperty_SetBaseMap(reinterpret_cast<NiTexture*>(pTexVal));
                    reinterpret_cast<Obj*>(PPTmp)->SetFlag(0);
                    bAllEmpty7 = bAllLoaded7 = false;
                }
                else if (iResult == 2)
                {
                    bAllLoaded7 = false;
                }
            }
            if (!PPTmp)
            {
                kPos3.y += 1.0;
                bAllEmpty7 = false;
                continue;
            }
            spCamera4 = new TriStrips(spData3.operator->());
            spCamera4->GetTransformScale(&kPos3);
            reinterpret_cast<NiAVObject*>(spCamera4.operator->())->AttachProperty(PPTmp);
            Prep(spCamera4.operator->(), 0, 0);
            m_pMenuLightParameters->AttachChildInAvailableSlot(reinterpret_cast<NiAVObject*>(spCamera4.operator->()), true);
            kPos3.y += 1.0;
        }
        kPos3.x += 1.0;
        kPos3.y = aFHalfDim * -1.0;
    }

    if (bAllEmpty7)
    {
        SetTexture(GetHolder()->GetObj());
        return;
    }
    else if (bAllLoaded7)
    {
        SetRenderFlags(GetRenderFlags() & ~0x20);
        SetTexture(0);
        return;
    }

    sp5_2 = new NiNode(0);
    spData_ = new Camera();
    sp5_2->AttachChildInAvailableSlot(reinterpret_cast<NiAVObject*>(spData_.operator->()), true);
    sp5_2->SetLocalTranslate(0.0f, 0.0f, 1.0f);
    NiUpdateData kUninitB(0.0f, false, false);
    sp5_2->Update(&kUninitB);
    spData_->SetTarget(&DAT_011f426c, &DAT_011a9478);
    NiUpdateData kUnlock(0.0f, false, false);
    spData_->Update(&kUnlock);
    NiUpdateData kUiCopy1(0.0f, false, false);
    sp5_2->Update(&kUiCopy1);

    kFrustumVal.ortho = true;
    kFrustumVal.bottom = kFrustumVal.left = aFHalfDim * -1.0;
    kFrustumVal.top = kFrustumVal.right = aFHalfDim;
    kFrustumVal.nearPlane = 1.0f;
    kFrustumVal.farPlane = 2.0f;
    spData_->UpdateViewFrustum(&kFrustumVal);

    spCameraVal = new Light();
    spCameraVal->SetAmbient(&DAT_011a9b7c);
    spCameraVal->SetDiffuse(&DAT_011a9b7c);
    spCameraVal->AttachAffected(reinterpret_cast<Obj*>(m_pMenuLightParameters.operator->()));

    pMat8 = new MatProp();
    pMat8->SetColA(&DAT_011a9b7c);
    pMat8->SetColA(&DAT_011a9b7c);
    pMat8->SetEmit(&DAT_011a9b7c);
    m_pMenuLightParameters->AttachProperty(reinterpret_cast<NiObject*>(pMat8));

    pStencil4 = new StencilProp();
    pStencil4->SetMode(3);
    m_pMenuLightParameters->AttachProperty(reinterpret_cast<NiObject*>(pStencil4));

    if (spRT.Check(0))
    {
        spRT = GetTexMgr()->Create(MakeFormat(0x17, 0, 0, 0));
    }
    GetRenderer()->GetBackground(&kColorA);
    GetRenderer()->SetBackground(&DAT_011a9bd0);
    m_pMenuLightParameters->UpdateSceneObject();
    NiUpdateData kUiMaxRow(0.0f, false, false);
    m_pMenuLightParameters->Update(&kUiMaxRow);
    NiUpdateData kUiLock1(0.0f, false, false);
    sp5_2->Update(&kUiLock1);
    NiUpdateData kUiCopy2(0.0f, false, false);
    spData_->Update(&kUiCopy2);
    VisArray kVis(0);
    GridCellObjectRefView spMeshB(new RTex(0x63, 1, 0x2f7));
    kVis.SetCamera(spMeshB.operator->());
    spMeshB->SetEnabled(false);
    RenderA(7, spRT->GetRT());
    RenderB(spData_.operator->(), reinterpret_cast<Obj*>(m_pMenuLightParameters.operator->()), &kVis);
    RenderC(spData_.operator->(), spMeshB.operator->(), 0);
    RenderD();
    kVis.SetCamera(0);
    spMeshB = 0;
    SetTexture(spRT->GetTexIdx(0));
    GetSys()->SetEnabled(true);
    GetRenderer()->SetBackground(&kColorA);
}



