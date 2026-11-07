#include "../../include/IOManager.h"
#include "../../include/ExteriorCellLoaderTask.h"
#include "../../include/NiPoint2.h"
#include "../../include/NiNode.h"
#include "../../include/TES.h"
#include "../../include/TESWorldSpace.h"
#include "../../include/TESObjectCELL.h"

// src/fallout_shared/exteriorcellloader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/exteriorcellloader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00527ce0
// src: XBOX_PDB 0x00527ce0
void __thiscall ExteriorCellLoaderTask::Finish_00527ce0()
{
    ((IOManager*)this)->SubmitTask();
}

struct IntPoint2D
{
    int iX;
    int iY;
};


extern "C" char* __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

// Formats the cell coordinates of the task's cell into apDescription using _sprintf_s and returns true.
// @fnv 0x00527df0
bool ExteriorCellLoaderTask::GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    _sprintf_s(apDescription, aiBufferSize, "ExteriorCellLoaderTask for cell ( %i, %i )",
               ((IntPoint2D*)*(int*)((char*)this + 0x1c))->iX, ((IntPoint2D*)*(int*)((char*)this + 0x1c))->iY);
    return true;
}

// TES.h exposes the flag but does not declare this accessor.
// @fnv 0x00528790
char __fastcall GetTESRegionState(TES* tes)
{
    return (char)tes->m_bHasCurrentRegion;
}

struct FUN_005287e0_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    bool BSTask_IsCompleted();
};

// @fnv 0x005287e0
// src: COMMUNITY 0x005287e0
bool FUN_005287e0_shell::BSTask_IsCompleted()
{
    return m_0c == 5;
}

extern int DAT_0102d078;

struct FUN_00528800_shell
{
    int m_val;
    void UpdateFields_00528800();
};

// @fnv 0x00528800
// src: GUESS 0x00528800 (confidence: low)
void FUN_00528800_shell::UpdateFields_00528800()
{
    m_val = (int)&DAT_0102d078;
}

struct FUN_00528820_shell
{
    void ClearField();
};

// @fnv 0x00528820
void FUN_00528820_shell::ClearField()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 8) = 0;
}

extern "C" void __cdecl _Deallocate(void*);

// @fnv 0x00527c70
ExteriorCellLoaderTask::~ExteriorCellLoaderTask()
{
    char* p = *(char**)((char*)this + 0x1c);
    _Deallocate(p);
}

extern int g_TES;

struct FUN_005287b0_shell
{
    void ExteriorCellLoader_AttachLoadedCell(TESObjectCELL* apCell);
};

// If the cell has a node, add it to the TES cell buffer.
// @fnv 0x005287b0
// src: XBOX_PDB 0x005287b0
void FUN_005287b0_shell::ExteriorCellLoader_AttachLoadedCell(TESObjectCELL* apCell)
{
    if (apCell)
    {
        if (apCell->Get3D_00545cb0())
        {
            ((TES*)g_TES)->AddToBuffer(apCell);
        }
    }
}

struct DH
{
    void DeleteObject(TESObjectCELL* apCell);
};
extern DH* g_dataHandler;
// @fnv 0x00527d80
void ExteriorCellLoaderTask::Cancel(BS_TASK_STATE, void*)
{
    if (*(int*)(*(char**)((char*)this + 0x1c) + 0xc) && ((TES*)g_TES)->IsCellBuffered((TESObjectCELL*)*(int*)(*(char**)((char*)this + 0x1c) + 0xc), false))
        g_dataHandler->DeleteObject((TESObjectCELL*)*(int*)(*(char**)((char*)this + 0x1c) + 0xc));
    (*(TESWorldSpace**)((char*)this + 0x18))->GetCellAtGridCoord(((IntPoint2D*)*(void**)((char*)this + 0x1c))->iX, ((IntPoint2D*)*(void**)((char*)this + 0x1c))->iY);
}

struct FUN_00528840_shell : public FUN_00528800_shell
{
    void* FUN_00528840(unsigned int flags);
};

// Calls FUN_00528800, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00528840
void* FUN_00528840_shell::FUN_00528840(unsigned int flags)
{
    UpdateFields_00528800();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct LoaderDummy
{
    void ExteriorCellLoader_LoadCellData(IntPoint2D* p);
};
struct MyCellEx
{
    char _pad[0xC];
    TESObjectCELL* pObj;
};
// @fnv 0x00527cb0
void ExteriorCellLoaderTask::Run()
{
    (*(LoaderDummy**)((char*)this + 0x18))->ExteriorCellLoader_LoadCellData(*(IntPoint2D**)((char*)this + 0x1c));
    ((MyCellEx*)*(void**)((char*)this + 0x1c))->pObj->QueueReferences(1);
}

// @fnv 0x00527d00
void ExteriorCellLoaderTask::Finish()
{
    if (!IOTask::BSTask_int64_GetTaskCanceled())
    {
        if (*(int*)(*(char**)((char*)this + 0x1c) + 0xc) != 0)
        {
            if (*(unsigned char*)(*(char**)((char*)this + 0x1c) + 0x10) != 0)
            {
                (*(FUN_005287b0_shell**)((char*)this + 0x18))->ExteriorCellLoader_AttachLoadedCell((TESObjectCELL*)*(int*)(*(char**)((char*)this + 0x1c) + 0xc));
            }
        }
    }
    *(char*)(*(char**)((char*)this + 0x1c) + 0x10) = 0;
    (*(TESWorldSpace**)((char*)this + 0x18))->GetCellAtGridCoord(*(int*)*(void**)((char*)this + 0x1c), *(int*)(*(char**)((char*)this + 0x1c) + 4));
}

struct CellEffects;
struct WorldSpaceAccess : TESWorldSpace
{
    CellEffects* __thiscall TESWorldSpace_LoadCell(int x, int y);
};
// FUN_00546fb0 returns landscape data, not a scene node.
struct LandscapeEffects
{
    void __thiscall TESObjectLAND_LoadVertices(bool value);
    void __thiscall TESObjectLAND_DrawLandBorder(unsigned char value);
    void __thiscall TESObjectLAND_GetMinMaxLandHeight();
};
// Supplemental method declarations absent from the shared TESObjectCELL header.
// This adds no fields or virtual functions to the shared cell layout.
struct CellEffects : TESObjectCELL
{
    void __thiscall GetOrCreateWidget();
    LandscapeEffects* __thiscall TESObjectCELL_GetLand();
    LandscapeEffects* __thiscall TESObjectCELL_GetLand(NiPoint2* outPosition);
    bool __thiscall TESClimate_GetVolatilityIndex();
    float __thiscall TESObjectCELL_GetWaterHeight();
    void __thiscall SetFlag2(bool value);
    bool __thiscall FUN_004518e0();
    void __thiscall SetByteAt54(bool value);
};
struct GameWorld : TES
{
    CellEffects* __thiscall FUN_00461330(int mode, int x, int y, WorldSpaceAccess* worldSpace);
};
extern GameWorld* DAT_011c3f2c;
extern TES* DAT_011dea10;
struct GlobalSettings
{
    unsigned char* __thiscall FUN_00408d60();
};
extern GlobalSettings DAT_011c7adc;
void __cdecl BGSAutoWater_GeneratePlaceableWaterForCell(CellEffects* cell);
struct CellLoadData : IntPoint2D
{
    WorldSpaceAccess* worldSpace;
    CellEffects* cell;
    bool loaded;
};
struct CellLoader
{
    void __thiscall ExteriorCellLoader_LoadCellData(CellLoadData* data);
};
// @fnv 0x00528620
// src: XBOX_PDB 0x00528620
void CellLoader::ExteriorCellLoader_LoadCellData(CellLoadData* pLoadData)
{
    if (pLoadData != 0)
    {
        if (pLoadData->cell == 0)
            pLoadData->cell = pLoadData->worldSpace->TESWorldSpace_LoadCell(pLoadData->iX, pLoadData->iY);
        if (pLoadData->cell == 0)
            pLoadData->cell = DAT_011c3f2c->FUN_00461330(0, pLoadData->iX, pLoadData->iY, pLoadData->worldSpace);
        pLoadData->cell->GetOrCreateWidget();
        LandscapeEffects* pLandscape = pLoadData->cell->TESObjectCELL_GetLand();
        if (pLandscape != 0)
        {
            pLandscape->TESObjectLAND_LoadVertices(true);
            pLandscape->TESObjectLAND_DrawLandBorder(GetTESRegionState(DAT_011dea10));
        }
        if (!pLoadData->cell->TESClimate_GetVolatilityIndex())
        {
            // Avoid invoking NiPoint2's out-of-line default constructor.
            float position[2];
            pLoadData->cell->TESObjectCELL_GetLand((NiPoint2*)position)->TESObjectLAND_GetMinMaxLandHeight();
            pLoadData->cell->SetFlag2(position[0] < pLoadData->cell->TESObjectCELL_GetWaterHeight());
            if (*DAT_011c7adc.FUN_00408d60() && pLoadData->cell->FUN_004518e0() && !pLoadData->cell->TESClimate_GetVolatilityIndex())
            {
                BGSAutoWater_GeneratePlaceableWaterForCell(pLoadData->cell);
            }
            pLoadData->cell->SetByteAt54(true);
        }
        pLoadData->loaded = true;
    }
}

void BSSleep(unsigned long ulMilliseconds);
struct QueuedTask
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Run(int eState, void* pArg);
    int m_04;
    int m_08;
    int m_eAnimationState;
    bool SetState(int eExpected, int eNew);
    void Model_IncManualRefCount();
    void BSTask_int64_DecRefCount();
};
struct FUN_00528870_shell
{
    void BSTaskManager_int64_RemoveTask(QueuedTask* pTask);
    bool RunQueuedTask(QueuedTask* pTask, void* pArg);
};

// @fnv 0x00528870
bool FUN_00528870_shell::RunQueuedTask(QueuedTask* pTask, void* pArg)
{
    while (true)
    {
        int eState = pTask->m_eAnimationState;
        switch (eState)
        {
        case 0:
            if (pTask->SetState(eState, 6))
            {
                pTask->Run(eState, pArg);
                return true;
            }
            break;
        case 1:
            if (pTask->SetState(eState, 6))
            {
                pTask->Model_IncManualRefCount();
                BSTaskManager_int64_RemoveTask(pTask);
                pTask->Run(eState, pArg);
                pTask->BSTask_int64_DecRefCount();
                return true;
            }
            break;
        case 2:
            while (pTask->m_eAnimationState == 3)
                BSSleep(0);
            break;
        case 3:
        case 4:
            return false;
        case 5:
            if (pTask->SetState(eState, 6))
            {
                pTask->Run(eState, pArg);
                return true;
            }
            break;
        case 6:
            return true;
        default:
            return true;
        }
    }
    return true;
}
