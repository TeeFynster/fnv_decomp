// fallout_shared/pathfinding/navmeshobstacletask.cpp: ObstacleTaskData, BSTaskletData (15 functions)

#include "navmeshobstacletask_decls.h"
#include "../../../include/BSTaskletData.h"
// Validates the operation against existing entries by type, then appends it to Operations if the navmesh is available.
// @fnv 0x006c7a30
bool ObstacleTaskData::AddOperation(const NiPointer<ObstacleData>& obstacle, OBSTACLE_TASK_TYPE type)
{
    switch (type)
    {
    case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_OBSTACLE:
    case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_OBSTACLE_FOR_UPDATE: {
        bool bCanAdd = true;
        for (unsigned int i = 0; i < Operations.GetSize(); ++i)
        {
            if (reinterpret_cast<const NiPointer<NiAVObject>&>(OPERATION_AT(Operations, i).m_spRegisteredObstacle) ==
                reinterpret_cast<const NiPointer<NiAVObject>&>(obstacle))
            {
                if ((OPERATION_AT(Operations, i).eType & 0x30) == OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_OBSTACLE)
                {
                    reinterpret_cast<void(__cdecl*)(const char*, ...)>(&Interface::PrintDebugMessage)(
                        "Removing previous operation ADD for Task on Navmesh 0x%08x (srcptr = 0x%08x)", pInfo->m_uiNavMeshID,
                        m_spSourceNavMesh.m_pObject);
                    Operations.Remove(i, true);
                    --i;
                }
                else
                    bCanAdd = false;
            }
        }
        if (!bCanAdd)
            return false;
        break;
    }
    case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_OBSTACLE:
    case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_OBSTACLE_FOR_UPDATE: {
        for (unsigned int i = 0; i < Operations.GetSize(); ++i)
        {
            if (reinterpret_cast<const NiPointer<NiAVObject>&>(OPERATION_AT(Operations, i).m_spRegisteredObstacle) ==
                reinterpret_cast<const NiPointer<NiAVObject>&>(obstacle))
            {
                if ((OPERATION_AT(Operations, i).eType & 0x30) == OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_OBSTACLE)
                    return false;
            }
        }
        break;
    }
    case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_DOOR: {
        for (unsigned int i = 0; i < Operations.GetSize(); ++i)
        {
            if (reinterpret_cast<const NiPointer<NiAVObject>&>(OPERATION_AT(Operations, i).m_spRegisteredObstacle) ==
                reinterpret_cast<const NiPointer<NiAVObject>&>(obstacle))
            {
                if (OPERATION_AT(Operations, i).eType == OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_DOOR)
                    return false;
            }
        }
        break;
    }
    case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_DOOR: {
        for (unsigned int i = 0; i < Operations.GetSize(); ++i)
        {
            if (reinterpret_cast<const NiPointer<NiAVObject>&>(OPERATION_AT(Operations, i).m_spRegisteredObstacle) ==
                reinterpret_cast<const NiPointer<NiAVObject>&>(obstacle))
            {
                if (OPERATION_AT(Operations, i).eType == OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_DOOR)
                    return false;
            }
        }
        break;
    }
    default:
        return false;
    }
    NavMeshPtr navMesh;
    if (pInfo->ResolveNavMesh(navMesh))
    {
        Operations.AppendValue(ObstacleTask(obstacle, type, navMesh));
        return true;
    }
    else
    {
        return false;
    }
}

// @fnv 0x006c8170
void ObstacleTaskData::Process()
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_NAVMESH, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\NavMeshObstacleTask.c",
                           357);
    NavMeshObstacleManager::GetSingleton()->GetCharPtrAtOffset()->Lock();
    if (pInfo->ResolveNavMesh(m_spSourceNavMesh))
    {
        m_spWorkingNavMesh = reinterpret_cast<NavMeshPtr(__cdecl*)(NavMesh*)>(&MakeNavMeshPointer)(new NavMesh);
        NAVMESH_FROM(m_spSourceNavMesh)->CopyNavMeshDataTo(m_spWorkingNavMesh);
        SortOperations();
        for (unsigned int i = 0; i < Operations.GetSize(); ++i)
        {
            switch (OPERATION_AT(Operations, i).eType)
            {
            case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_OBSTACLE:
            case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_OBSTACLE_FOR_UPDATE:
                if (NAVMESH_FROM(m_spWorkingNavMesh)
                        ->Search(OPERATION_AT(Operations, i).m_spRegisteredObstacle, m_kParentChildLinks))
                    OPERATION_AT(Operations, i).m_kResult = 0;
                else
                    OPERATION_AT(Operations, i).m_kResult = 1;
                break;
            case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_OBSTACLE:
            case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_OBSTACLE_FOR_UPDATE:
                if (NAVMESH_FROM(m_spWorkingNavMesh)
                        ->RemoveObstacleAndUpdateLinks(OPERATION_AT(Operations, i).m_spRegisteredObstacle, m_kParentChildLinks))
                    OPERATION_AT(Operations, i).m_kResult = 0;
                else
                    OPERATION_AT(Operations, i).m_kResult = 1;
                break;
            case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_DOOR:
                if (NAVMESH_FROM(m_spWorkingNavMesh)
                        ->RemoveDoorObstacle(OBSTACLE_FROM(OPERATION_AT(Operations, i).m_spRegisteredObstacle)->source->id))
                    OPERATION_AT(Operations, i).m_kResult = 0;
                else
                    OPERATION_AT(Operations, i).m_kResult = 1;
                break;
            case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_DOOR:
                if (NAVMESH_FROM(m_spWorkingNavMesh)
                        ->AddDoorObstacle(OBSTACLE_FROM(OPERATION_AT(Operations, i).m_spRegisteredObstacle)->source->id,
                                          OBSTACLE_FROM(OPERATION_AT(Operations, i).m_spRegisteredObstacle)))
                    OPERATION_AT(Operations, i).m_kResult = 0;
                else
                    OPERATION_AT(Operations, i).m_kResult = 1;
                break;
            }
        }
        for (unsigned int i = 0; i < m_kParentChildLinks.parents.GetSize(); ++i)
            EDGE_AT(m_kParentChildLinks.parents, i).pInfo = pInfo;
        for (unsigned int i = 0; i < m_kParentChildLinks.children.GetSize(); ++i)
            EDGE_AT(m_kParentChildLinks.children, i).pInfo = pInfo;
    }
    else
    {
        for (unsigned int i = 0; i < Operations.GetSize(); ++i)
            OPERATION_AT(Operations, i).m_kResult = 1;
    }
    NavMeshObstacleManager::GetSingleton()->AddProcessedTask(this);
    NavMeshObstacleManager::GetSingleton()->GetCharPtrAtOffset()->Lock();
}

// @fnv 0x006c79a0
ObstacleTaskData::~ObstacleTaskData()
{}

struct FUN_006c7e00
{
    NiPointer<ObstacleData> node;
    int pad[2];
    NavMeshPtr mesh;
    ~FUN_006c7e00();
};
// @fnv 0x006c7e00
FUN_006c7e00::~FUN_006c7e00()
{}

void __cdecl CompareObstacleEntries();

struct Helper_006c8980
{
    void BSSimpleArray_Sort_0(void(__cdecl*)());
};

// @fnv 0x006c8150
// src: COMMUNITY 0x006c8150
void ObstacleTaskData::SortOperations()
{
    ((Helper_006c8980*)((char*)this + 0x24))->BSSimpleArray_Sort_0(CompareObstacleEntries);
}

struct Elem16
{
    int a[4];
    void AssignFrom(int v);
};
struct Arr16
{
    int pad;
    Elem16* data;
    unsigned int BSSimpleArray_TeleportLink_1024_AddUninitialized();
    void InitializeArray(Elem16* e, int f);
    unsigned int AppendValue(int value);
};
// Appends a new element at the end of the array, initializes it with the given value, and returns its index.
// @fnv 0x006c8810
unsigned int Arr16::AppendValue(int value)
{
    unsigned int index = BSSimpleArray_TeleportLink_1024_AddUninitialized();
    InitializeArray(&data[index], 1);
    data[index].AssignFrom(value);
    return index;
}

void __cdecl operator delete(void*);

// Runs the destructor, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x006c7910
void* BSTaskletData::DestroyIfFlagged(unsigned int flags)
{
    BSTaskletData::~BSTaskletData();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_006c7940 {
struct BaseT
{
    virtual ~BaseT();
};
struct FUN_006c7940_shell : BaseT
{
    void* FUN_006c7940(unsigned int flags);
};
// Runs the base destructor, frees this when bit 0 of flags is set, and returns this.
// @fnv 0x006c7940
void* FUN_006c7940_shell::FUN_006c7940(unsigned int flags)
{
    BaseT::~BaseT();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_006c7940

struct FUN_006c85c0_shell
{
    char* GetCharPtrAtOffset();
};

// @fnv 0x006c85c0
char* FUN_006c85c0_shell::GetCharPtrAtOffset()
{
    return reinterpret_cast<char*>(this) + 0x1A1;
}

extern int DAT_0106c8d4;
struct S_006c87c0
{
    int BSSimpleArray_ObstacleTaskNavMeshOperation_1024_InitialSetup(int, int);
    S_006c87c0* InitializeFields_006c87c0();
};
// Sets the object's vtable pointer to DAT_0106c8d4, calls FUN_006c8c70(0, 0), and returns this.
// @fnv 0x006c87c0
// src: GUESS 0x006c87c0 (confidence: low)
S_006c87c0* S_006c87c0::InitializeFields_006c87c0()
{
    *(int*)this = (int)&DAT_0106c8d4;
    BSSimpleArray_ObstacleTaskNavMeshOperation_1024_InitialSetup(0, 0);
    return this;
}

extern int DAT_0106c8d4;
struct FUN_006c87f0_shell
{
    void* vftable;
    void __thiscall BSSimpleArray_ObstacleTaskNavMeshOperation_1024_Clear(int a);
    void __thiscall SetVtableAndProcessState_006c87f0();
};
// @fnv 0x006c87f0
// src: GUESS 0x006c87f0 (confidence: low)
void __thiscall FUN_006c87f0_shell::SetVtableAndProcessState_006c87f0()
{
    vftable = &DAT_0106c8d4;
    BSSimpleArray_ObstacleTaskNavMeshOperation_1024_Clear(1);
}

// @fnv 0x006c7e60
int __cdecl CompareObstacleEntries(const void* apEntryA, const void* apEntryB)
{
    const ObstacleTask* a = (const ObstacleTask*)apEntryA;
    const ObstacleTask* b = (const ObstacleTask*)apEntryB;
    switch (a->eType)
    {
    case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_DOOR:
        if (b->eType == OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_DOOR)
            return 0;
        else
            return -1;
        break;
    case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_DOOR:
        if (b->eType == OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_DOOR)
            return 0;
        else
            return 1;
        break;
    case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_OBSTACLE:
    case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_OBSTACLE_FOR_UPDATE:
        switch (b->eType)
        {
        case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_DOOR:
            return 1;
            break;
        case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_DOOR:
            return -1;
            break;
        case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_OBSTACLE:
        case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_OBSTACLE_FOR_UPDATE:
            return a->m_spRegisteredObstacle->source->id - b->m_spRegisteredObstacle->source->id;
            break;
        case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_OBSTACLE:
        case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_OBSTACLE_FOR_UPDATE:
            return 1;
            break;
        }
        break;
    case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_OBSTACLE:
    case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_OBSTACLE_FOR_UPDATE:
        switch (b->eType)
        {
        case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_DOOR:
            return 1;
            break;
        case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_DOOR:
            return -1;
            break;
        case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_OBSTACLE:
        case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_ADD_OBSTACLE_FOR_UPDATE:
            return -1;
            break;
        case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_OBSTACLE:
        case OBSTACLE_TASK_TYPE_OBSTACLE_TASK_TYPE_REMOVE_OBSTACLE_FOR_UPDATE: {
            NavMeshPtr mesh(a->apSearchNavMesh);
            if (mesh.AnimatingText_GetFullText())
            {
                int ia = static_cast<const NavMeshPtr&>(mesh)->FindEntryIndex((void*)a);
                int ib = static_cast<const NavMeshPtr&>(mesh)->FindEntryIndex((void*)b);
                return ib - ia;
            }
            else
            {
                return 0;
            }
        }
        }
        break;
    }
    return 0;
}

struct Element16
{
    int a;
    int b;
    int c;
    int d;
};
class FUN_006c8860_Class
{
  public:
    virtual void v0();
    virtual Element16* Allocate(unsigned int);
    Element16* data;
    unsigned int size;
    unsigned int capacity;
    bool BSSimpleArray_HasSufficientCapacity();
    unsigned int BSSimpleArray_GetOptimalCapacity();
    void BSSimpleArray_NiColorA_1024_CopyItems(Element16*, const Element16*, unsigned int);
    void BSSimpleArray_ObstacleTaskNavMeshOperation_1024_DestructItems(Element16*, unsigned int);
    void FUN_006a8500();
    void RemoveAt(unsigned int index, bool shrink);
};
// Removes the element at index, optionally reallocating a smaller buffer first, then shifts the remaining elements down and decrements size.
// @fnv 0x006c8860
void FUN_006c8860_Class::RemoveAt(unsigned int index, bool shrink)
{
    if (shrink && BSSimpleArray_HasSufficientCapacity())
    {
        unsigned int uiNewCapacity = BSSimpleArray_GetOptimalCapacity();
        Element16* pNewData = Allocate(uiNewCapacity);
        BSSimpleArray_NiColorA_1024_CopyItems(pNewData, data, index);
        BSSimpleArray_ObstacleTaskNavMeshOperation_1024_DestructItems(data + index, 1);
        BSSimpleArray_NiColorA_1024_CopyItems(pNewData + index, data + index + 1, size - 1);
        FUN_006a8500();
        data = pNewData;
        capacity = uiNewCapacity;
    }
    else
    {
        BSSimpleArray_ObstacleTaskNavMeshOperation_1024_DestructItems(data + index, 1);
        BSSimpleArray_NiColorA_1024_CopyItems(data + index, data + index + 1, size - index - 1);
    }
    size = size - 1;
}

struct ObstacleCellChild
{
    void NavMeshArray_AddNavMesh(NavMeshPtr);
    void NavMeshArray_RemoveNavMesh(NavMeshPtr);
};
struct ObstacleCell
{
    ObstacleCellChild* DetailedActorPathHandler_GetCurrentNodeIndex();
};
struct ObstacleInfo
{
    void SetField54(NavMesh*);
};
// The shared task has no declaration for this bool-returning commit routine.
// A single fastcall argument preserves its original this-in-ECX calling convention.
// @fnv 0x006c85e0
bool __fastcall CommitObstacleTask(ObstacleTaskData* task)
{
    if (!(NavMesh*)task->m_spSourceNavMesh)
        return false;
    if (!(NavMesh*)task->m_spWorkingNavMesh)
        return false;
    bool bFound = false;
    if (!task->bForce)
    {
        for (unsigned int i = 0; i < task->Operations.GetSize(); i++)
        {
            if (task->Operations.GetAt(i).m_kResult == 0)
            {
                bFound = true;
                break;
            }
        }
    }
    else
    {
        bFound = true;
    }
    if (bFound)
    {
        unsigned int formID = ((NavMesh*)task->m_spSourceNavMesh)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        ObstacleCell* pCell = reinterpret_cast<ObstacleCell*>(((NavMesh*)task->m_spSourceNavMesh)->GetParentCell());
        if (pCell)
        {
            pCell->DetailedActorPathHandler_GetCurrentNodeIndex()->NavMeshArray_AddNavMesh(task->m_spWorkingNavMesh);
            pCell->DetailedActorPathHandler_GetCurrentNodeIndex()->NavMeshArray_RemoveNavMesh(task->m_spSourceNavMesh);
        }
        ((NavMesh*)task->m_spSourceNavMesh)->ForceSetFormID(0);
        ((NavMesh*)task->m_spSourceNavMesh)->PathingRequestCoveredMove_SetCombatCoverLocation((NavMeshInfo*)0);
        ((NavMesh*)task->m_spWorkingNavMesh)->ForceSetFormID(formID);
        ((NavMesh*)task->m_spWorkingNavMesh)->PathingRequestCoveredMove_SetCombatCoverLocation((NavMeshInfo*)task->pInfo);
        reinterpret_cast<ObstacleInfo*>(task->pInfo)->SetField54(task->m_spWorkingNavMesh.AnimatingText_GetFullText());
        return true;
    }
    else
    {
        return false;
    }
}
