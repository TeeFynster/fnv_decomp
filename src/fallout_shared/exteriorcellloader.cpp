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
void __thiscall ExteriorCellLoaderTask::FUN_00527ce0()
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
    bool FUN_005287e0();
};

// @fnv 0x005287e0
bool FUN_005287e0_shell::FUN_005287e0()
{
    return m_0c == 5;
}

extern int DAT_0102d078;

struct FUN_00528800_shell
{
    int m_val;
    void FUN_00528800();
};

// @fnv 0x00528800
void FUN_00528800_shell::FUN_00528800()
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
    void FUN_005287b0(TESObjectCELL* apCell);
};

// If the cell has a node, add it to the TES cell buffer.
// @fnv 0x005287b0
void FUN_005287b0_shell::FUN_005287b0(TESObjectCELL* apCell)
{
    if (apCell)
    {
        if (apCell->FUN_00545cb0())
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
    FUN_00528800();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct LoaderDummy
{
    void FUN_00528620(IntPoint2D* p);
};
struct MyCellEx
{
    char _pad[0xC];
    TESObjectCELL* pObj;
};
// @fnv 0x00527cb0
void ExteriorCellLoaderTask::Run()
{
    (*(LoaderDummy**)((char*)this + 0x18))->FUN_00528620(*(IntPoint2D**)((char*)this + 0x1c));
    ((MyCellEx*)*(void**)((char*)this + 0x1c))->pObj->FUN_005571a0(1);
}

// @fnv 0x00527d00
void ExteriorCellLoaderTask::Finish()
{
    if (!IOTask::FUN_00449130())
    {
        if (*(int*)(*(char**)((char*)this + 0x1c) + 0xc) != 0)
        {
            if (*(unsigned char*)(*(char**)((char*)this + 0x1c) + 0x10) != 0)
            {
                (*(FUN_005287b0_shell**)((char*)this + 0x18))->FUN_005287b0((TESObjectCELL*)*(int*)(*(char**)((char*)this + 0x1c) + 0xc));
            }
        }
    }
    *(char*)(*(char**)((char*)this + 0x1c) + 0x10) = 0;
    (*(TESWorldSpace**)((char*)this + 0x18))->GetCellAtGridCoord(*(int*)*(void**)((char*)this + 0x1c), *(int*)(*(char**)((char*)this + 0x1c) + 4));
}

struct CellEffects;
struct WorldSpaceAccess : TESWorldSpace
{
    CellEffects* __thiscall FUN_00585b30(int x, int y);
};
// FUN_00546fb0 returns landscape data, not a scene node.
struct LandscapeEffects
{
    void __thiscall FUN_00535b90(bool value);
    void __thiscall FUN_0053fa40(unsigned char value);
    void __thiscall FUN_0053f440();
};
// Supplemental method declarations absent from the shared TESObjectCELL header.
// This adds no fields or virtual functions to the shared cell layout.
struct CellEffects : TESObjectCELL
{
    void __thiscall GetOrCreateWidget();
    LandscapeEffects* __thiscall FUN_00546fb0();
    LandscapeEffects* __thiscall FUN_00546fb0(NiPoint2* outPosition);
    bool __thiscall FUN_00451cd0();
    float __thiscall FUN_005471e0();
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
void __cdecl FUN_0049c860(CellEffects* cell);
struct CellLoadData : IntPoint2D
{
    WorldSpaceAccess* worldSpace;
    CellEffects* cell;
    bool loaded;
};
struct CellLoader
{
    void __thiscall FUN_00528620(CellLoadData* data);
};
// @fnv 0x00528620
void CellLoader::FUN_00528620(CellLoadData* pLoadData)
{
    if (pLoadData != 0)
    {
        if (pLoadData->cell == 0)
            pLoadData->cell = pLoadData->worldSpace->FUN_00585b30(pLoadData->iX, pLoadData->iY);
        if (pLoadData->cell == 0)
            pLoadData->cell = DAT_011c3f2c->FUN_00461330(0, pLoadData->iX, pLoadData->iY, pLoadData->worldSpace);
        pLoadData->cell->GetOrCreateWidget();
        LandscapeEffects* pLandscape = pLoadData->cell->FUN_00546fb0();
        if (pLandscape != 0)
        {
            pLandscape->FUN_00535b90(true);
            pLandscape->FUN_0053fa40(GetTESRegionState(DAT_011dea10));
        }
        if (!pLoadData->cell->FUN_00451cd0())
        {
            // Avoid invoking NiPoint2's out-of-line default constructor.
            float position[2];
            pLoadData->cell->FUN_00546fb0((NiPoint2*)position)->FUN_0053f440();
            pLoadData->cell->SetFlag2(position[0] < pLoadData->cell->FUN_005471e0());
            if (*DAT_011c7adc.FUN_00408d60() && pLoadData->cell->FUN_004518e0() && !pLoadData->cell->FUN_00451cd0())
            {
                FUN_0049c860(pLoadData->cell);
            }
            pLoadData->cell->SetByteAt54(true);
        }
        pLoadData->loaded = true;
    }
}

void FUN_0040fca0(unsigned long ulMilliseconds);
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
    void FUN_0092c870();
    void FUN_0044dd60();
};
struct FUN_00528870_shell
{
    void FUN_0044e050(QueuedTask* pTask);
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
                pTask->FUN_0092c870();
                FUN_0044e050(pTask);
                pTask->Run(eState, pArg);
                pTask->FUN_0044dd60();
                return true;
            }
            break;
        case 2:
            while (pTask->m_eAnimationState == 3)
                FUN_0040fca0(0);
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
