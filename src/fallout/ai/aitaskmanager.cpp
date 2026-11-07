// fallout/ai/aitaskmanager.cpp: MovementTaskData, PackageUpdateTaskData, Owner, ActorsScriptTaskData and more (87 functions)

#include <stddef.h>
#include "../../../include/BSSimpleList.h"
#include "../../../include/Actor.h"
#include "../../../include/ActorTaskManager.h"
#include "../../../include/ActorUpdateTaskData.h"
#include "../../../include/ActorsScriptTaskData.h"
#include "../../../include/AnimationTaskData.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/ExtraFollower.h"
#include "../../../include/ExtraDataList.h"
#include "../../../include/HighProcess.h"
#include "../../../include/MobileObjectTaskletData.h"
#include "../../../include/MovementTaskData.h"
#include "../../../include/PackageUpdateTaskData.h"
#include "../../../include/PathingTaskData.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/Script.h"
#include "../../../include/TESQuest.h"
#include "../../../include/RecursiveLock.h"
#include "../../../include/BSThread.h"
#include "../../../include/CountingSemaphore.h"
#include "../../../include/GameTimerRecord.h"
#include "../../../include/hkMemoryRouter.h"
#include "../../../include/SL.h"
#include "../../../include/TESSaveLoadGame.h"

// Migration limit: the lifetime views for AnimationTaskData,
// ActorUpdateTaskData, PackageUpdateTaskData, ActorsScriptTaskData and
// MovementTaskData remain because their shared declarations lack constructors.
// The MobileObjectTaskletData destructor view also remains: using the shared
// virtual destructor changes the code at 0x008c83a0. Its constructor and message
// processing implementations below use the shared class.

// The rendering wait helper forwards the lock at the start of this object.
// @fnv 0x004538c0
void ActorTaskManager::WaitForTasksDuringRendering()
{
    reinterpret_cast<RecursiveLock*>(this)->Leave();
}


// @fnv 0x008c8bb0
// PlayerCharacter.h has no bool-taking setter for this flag.
struct PlayerTaskMethods : PlayerCharacter
{
    void SetUpdateFlag(bool);
};
void PlayerTaskMethods::SetUpdateFlag(bool abValue)
{
    *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x5f8) = abValue;
}


// @fnv 0x008c8fd0
// src: XBOX_PDB 0x008c8fd0
void BaseProcess::HighProcess_SetSkippedLastUpdate(bool abVal)
{
    reinterpret_cast<HighProcess*>(this)->m_kFirstAdditionalHighProcessField = abVal;
}

struct WeatherEntry;
struct SoundListView
{
    void AddTail(char* const&);
};
extern SoundListView g_011d970c;
int __cdecl QuestUpdateManager_SortQuestNamesByPriorityFunction(WeatherEntry*, WeatherEntry*);
// Appends name to g_011d970c and re-sorts the list using FUN_0076bb00 as the comparison.
// @fnv 0x0076bad0
// src: XBOX_PDB 0x0076bad0
void QuestUpdateManager_AddQuestNamesTail(char* name)
{
    g_011d970c.AddTail(name);
    ((BSSimpleList<WeatherEntry*>*)&g_011d970c)->Sort(QuestUpdateManager_SortQuestNamesByPriorityFunction);
}

struct FUN_008c8190_shell
{
    int a;
    int b;
    int c;
    FUN_008c8190_shell* InitializeFields_008c8190();
};
// Sets the object's a field to 2 and clears b and c, then returns this.
// @fnv 0x008c8190
// src: GUESS 0x008c8190 (confidence: low)
FUN_008c8190_shell* FUN_008c8190_shell::InitializeFields_008c8190()
{
    a = 2;
    b = 0;
    c = 0;
    return this;
}

struct FUN_008c8370_shell
{
    void FUN_008c83a0();
    FUN_008c8370_shell* FUN_008c8370(unsigned int flags);
};
// Calls FUN_008c83a0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x008c8370
FUN_008c8370_shell* FUN_008c8370_shell::FUN_008c8370(unsigned int flags)
{
    FUN_008c83a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_008c8400_shell
{
    void SetVtableAndProcessState_008c8430();
    FUN_008c8400_shell* FUN_008c8400(unsigned int flags);
};
// Calls FUN_008c8430, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008c8400
FUN_008c8400_shell* FUN_008c8400_shell::FUN_008c8400(unsigned int flags)
{
    SetVtableAndProcessState_008c8430();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_01085728;
struct FUN_008c8430_shell
{
    int* vtbl;
    void FUN_008c83a0();
    void SetVtableAndProcessState_008c8430();
};
// @fnv 0x008c8430
// src: GUESS 0x008c8430 (confidence: low)
void FUN_008c8430_shell::SetVtableAndProcessState_008c8430()
{
    vtbl = &DAT_01085728;
    FUN_008c83a0();
}

extern PlayerCharacter* g_thePlayer;
void __fastcall PlayerCharacter_UpdateAutoAimActor(void*);
extern ActorTaskManager g_011dfbe8;
extern ActorTaskManager g_011dfc04;
struct FUN_008c8490_shell
{
    void DetectionTaskData_HandleEndMessage(unsigned int);
};
// Calls FUN_00964260 on g_thePlayer, then waits for rendering tasks on g_011dfc04 and g_011dfbe8.
// @fnv 0x008c8490
// src: XBOX_PDB 0x008c8490
void FUN_008c8490_shell::DetectionTaskData_HandleEndMessage(unsigned int)
{
    PlayerCharacter_UpdateAutoAimActor(g_thePlayer);
    g_011dfc04.WaitForTasksDuringRendering();
    g_011dfbe8.WaitForTasksDuringRendering();
}

extern int DAT_01085768;
struct FUN_008c8830_shell
{
    int* vtable;
    void FUN_008c82e0(int);
    FUN_008c8830_shell* Construct(int p);
};
// Calls FUN_008c82e0 with p, sets the vtable to DAT_01085768, and returns this.
// @fnv 0x008c8830
FUN_008c8830_shell* FUN_008c8830_shell::Construct(int p)
{
    FUN_008c82e0(p);
    vtable = &DAT_01085768;
    return this;
}

void __cdecl operator delete(void*);
struct FUN_008c8860_shell
{
    void SetVtableAndProcessState_008c8890();
    void* FUN_008c8860(unsigned int flags);
};
// Calls FUN_008c8890, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008c8860
void* FUN_008c8860_shell::FUN_008c8860(unsigned int flags)
{
    SetVtableAndProcessState_008c8890();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_01085768;
struct FUN_008c8890_shell
{
    int* vtbl;
    void FUN_008c83a0();
    void SetVtableAndProcessState_008c8890();
};
// @fnv 0x008c8890
// src: GUESS 0x008c8890 (confidence: low)
void FUN_008c8890_shell::SetVtableAndProcessState_008c8890()
{
    vtbl = &DAT_01085768;
    FUN_008c83a0();
}

namespace fnv_008c88b0 {
extern ActorTaskManager g_011dfc38;
extern ActorTaskManager g_011dfc04;
struct FUN_008c88b0_shell
{
    void QueryPerformanceCounters(int);
};
// Calls QueryPerformanceCounter on g_011dfc38 and g_011dfc04 with argument 0.
// @fnv 0x008c88b0
void FUN_008c88b0_shell::QueryPerformanceCounters(int)
{
    g_011dfc38.QueryPerformanceCounter(0);
    g_011dfc04.QueryPerformanceCounter(0);
}
}  // namespace fnv_008c88b0

namespace fnv_008c88e0 {
extern ActorTaskManager g_011dfc04;
extern ActorTaskManager g_011dfc38;
struct FUN_008c88e0_shell
{
    void AnimationTaskData_HandleEndMessage(int a);
};
// Calls WaitForTasksDuringRendering on g_011dfc04 and g_011dfc38.
// @fnv 0x008c88e0
// src: XBOX_PDB 0x008c88e0
void FUN_008c88e0_shell::AnimationTaskData_HandleEndMessage(int aiUnused)
{
    g_011dfc04.WaitForTasksDuringRendering();
    g_011dfc38.WaitForTasksDuringRendering();
}
}  // namespace fnv_008c88e0

struct FUN_008c82e0
{
    int pad[13];
    FUN_008c82e0(int a);
    virtual void Run();
};
struct FUN_008c89a0 : FUN_008c82e0
{
    int field38;
    FUN_008c89a0(int a);
    virtual void Run();
};
// Initializes the base class with a and sets field38 to 0.
// @fnv 0x008c89a0
FUN_008c89a0::FUN_008c89a0(int aiValue) : FUN_008c82e0(aiValue)
{
    field38 = 0;
}

void __cdecl operator delete(void*);
struct FUN_008c89d0_shell
{
    void SetVirtualTableAndProcessState_008c8a00();
    void* Destroy(unsigned int flags);
};
// @fnv 0x008c89d0
void* FUN_008c89d0_shell::Destroy(unsigned int flags)
{
    SetVirtualTableAndProcessState_008c8a00();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_01085788;
struct FUN_008c8a00_shell
{
    int* vtbl;
    void FUN_008c83a0();
    void SetVirtualTableAndProcessState_008c8a00();
};
// @fnv 0x008c8a00
// src: GUESS 0x008c8a00 (confidence: low)
void FUN_008c8a00_shell::SetVirtualTableAndProcessState_008c8a00()
{
    vtbl = &DAT_01085788;
    FUN_008c83a0();
}

namespace fnv_008c8a20 {
extern ActorTaskManager g_011dfc38;
struct FUN_008c8a20_shell
{
    void ActorUpdateTaskData_HandleCountMessage(int);
};
// Clears the int at offset 0x38 and calls QueryPerformanceCounter on g_011dfc38.
// @fnv 0x008c8a20
// src: XBOX_PDB 0x008c8a20
void FUN_008c8a20_shell::ActorUpdateTaskData_HandleCountMessage(int)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x38) = 0;
    g_011dfc38.QueryPerformanceCounter(0);
}
}  // namespace fnv_008c8a20

namespace fnv_008c8a50 {
extern ActorTaskManager g_011dfc38;
struct FUN_008c8a50_shell
{
    void ActorUpdateTaskData_HandleEndMessage(int a);
};
// @fnv 0x008c8a50
// src: XBOX_PDB 0x008c8a50
void FUN_008c8a50_shell::ActorUpdateTaskData_HandleEndMessage(int aiUnused)
{
    g_011dfc38.WaitForTasksDuringRendering();
}
}  // namespace fnv_008c8a50

void __cdecl operator delete(void*);
struct FUN_008c8b20_shell
{
    void SetVtableAndProcessState_008c8b50();
    void* DestroyOrReturnSelf(unsigned int flags);
};
// @fnv 0x008c8b20
void* FUN_008c8b20_shell::DestroyOrReturnSelf(unsigned int flags)
{
    SetVtableAndProcessState_008c8b50();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_010857a8;
struct FUN_008c8b50_shell
{
    int* vtbl;
    void FUN_008c83a0();
    void SetVtableAndProcessState_008c8b50();
};
// @fnv 0x008c8b50
// src: GUESS 0x008c8b50 (confidence: low)
void FUN_008c8b50_shell::SetVtableAndProcessState_008c8b50()
{
    vtbl = &DAT_010857a8;
    FUN_008c83a0();
}

extern "C" unsigned char DAT_011e01dd;

// @fnv 0x008c8bd0
// src: XBOX_PDB 0x008c8bd0
void HighProcess_ClearWanderStarted()
{
    DAT_011e01dd = 0;
}

namespace fnv_008c8ff0 {
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct PkgObj
{
    void ProcessLists_DisableExcessDeadActors(float f);
};
extern Twin_0084d030 g_timeGlobal;
extern PkgObj DAT_011e0e80;
extern ActorTaskManager g_011dfbe8;

// @fnv 0x008c8ff0
}  // namespace fnv_008c8ff0
void PackageUpdateTaskData::RunPackageUpdateTask(unsigned int aiThread)
{
    using namespace fnv_008c8ff0;
    fnv_008c8ff0::DAT_011e0e80.ProcessLists_DisableExcessDeadActors(fnv_008c8ff0::g_timeGlobal.GetStoredFloatValue());
    fnv_008c8ff0::g_011dfbe8.WaitForTasksDuringRendering();
}


namespace fnv_008c9020 {
struct FUN_008c82e0
{
    int pad[14];
    FUN_008c82e0(int a);
    virtual void Run();
};
struct FUN_008c9020 : FUN_008c82e0
{
    int field;
    FUN_008c9020(int a);
    virtual void Run();
};
// Constructs the object by forwarding a to the base constructor and initializing field to 0.
// @fnv 0x008c9020
FUN_008c9020::FUN_008c9020(int a) : FUN_008c82e0(a)
{
    field = 0;
}
}  // namespace fnv_008c9020

void __cdecl operator delete(void*);
struct FUN_008c9050_shell
{
    void SetVirtualTableAndProcessState_008c9080();
    void* FUN_008c9050(unsigned int flags);
};
// Calls FUN_008c9080, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008c9050
void* FUN_008c9050_shell::FUN_008c9050(unsigned int flags)
{
    SetVirtualTableAndProcessState_008c9080();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_010857c8;
struct FUN_008c9080_shell
{
    int* vtbl;
    void FUN_008c83a0();
    void SetVirtualTableAndProcessState_008c9080();
};
// @fnv 0x008c9080
// src: GUESS 0x008c9080 (confidence: low)
void FUN_008c9080_shell::SetVirtualTableAndProcessState_008c9080()
{
    vtbl = &DAT_010857c8;
    FUN_008c83a0();
}

namespace fnv_008c90e0 {
extern ActorTaskManager g_011dfbe8;
extern ActorTaskManager g_011dfc04;
extern ActorTaskManager g_011dfc38;
struct FUN_008c90e0_shell
{
    void ActorsScriptTaskData_HandleEndMessage(unsigned int);
};
// Calls WaitForTasksDuringRendering on three global ActorTaskManager instances to wait for their tasks during rendering.
// @fnv 0x008c90e0
// src: XBOX_PDB 0x008c90e0
void FUN_008c90e0_shell::ActorsScriptTaskData_HandleEndMessage(unsigned int)
{
    g_011dfbe8.WaitForTasksDuringRendering();
    g_011dfc04.WaitForTasksDuringRendering();
    g_011dfc38.WaitForTasksDuringRendering();
}
}  // namespace fnv_008c90e0

namespace fnv_008c9170 {
struct FUN_008c82e0
{
    int pad[13];
    FUN_008c82e0(int a);
    virtual void Run();
};
struct FUN_008c9170 : FUN_008c82e0
{
    int field;
    FUN_008c9170(int a);
    virtual void Run();
};
// Constructs the object by forwarding a to the base constructor and initializing field to 0.
// @fnv 0x008c9170
FUN_008c9170::FUN_008c9170(int a) : FUN_008c82e0(a)
{
    field = 0;
}
}  // namespace fnv_008c9170

void __cdecl operator delete(void*);
struct FUN_008c91a0_shell
{
    void UpdateState_008c91d0();
    void* FUN_008c91a0(unsigned int flags);
};
// Calls FUN_008c91d0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x008c91a0
void* FUN_008c91a0_shell::FUN_008c91a0(unsigned int flags)
{
    UpdateState_008c91d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern int DAT_010857e8;

struct FUN_008c91d0_shell
{
    void* m_vft;
    void FUN_008c83a0();
    void UpdateState_008c91d0();
};

// @fnv 0x008c91d0
// src: GUESS 0x008c91d0 (confidence: low)
void FUN_008c91d0_shell::UpdateState_008c91d0()
{
    m_vft = &DAT_010857e8;
    FUN_008c83a0();
}

namespace fnv_008c91f0 {
extern ActorTaskManager g_011dfbe8;
extern ActorTaskManager g_011dfc04;

// Clears field and queries the performance counter on both g_011dfc04 and g_011dfbe8.
// @fnv 0x008c91f0
}  // namespace fnv_008c91f0
void MovementTaskData::SetMobileObjectCount(unsigned int auiCount)
{
    using namespace fnv_008c91f0;
    uiRunCount = 0;
    fnv_008c91f0::g_011dfc04.QueryPerformanceCounter(0);
    fnv_008c91f0::g_011dfbe8.QueryPerformanceCounter(0);
}


namespace fnv_008c9300 {
extern ActorTaskManager g_011dfbe8;
extern ActorTaskManager g_011dfc04;
struct FUN_008c9300_shell
{
    void MovementTaskData_HandleEndMessage(int a);
};
// Calls WaitForTasksDuringRendering on g_011dfbe8 and g_011dfc04.
// @fnv 0x008c9300
// src: XBOX_PDB 0x008c9300
void FUN_008c9300_shell::MovementTaskData_HandleEndMessage(int aiUnused)
{
    g_011dfbe8.WaitForTasksDuringRendering();
    g_011dfc04.WaitForTasksDuringRendering();
}
}  // namespace fnv_008c9300

struct FUN_008c9a50_shell
{
    int m_uiContentCount;
    int m_auiShapeKeys;
    int m_uiFilterValue;
    FUN_008c9a50_shell* MobileObjectMessage_MobileObjectMessage_008c9a50(int value);
};
// Sets the first field to 1 and stores value in the third field, then returns this.
// @fnv 0x008c9a50
// src: XBOX_PDB 0x008c9a50
FUN_008c9a50_shell* FUN_008c9a50_shell::MobileObjectMessage_MobileObjectMessage_008c9a50(int value)
{
    m_uiContentCount = 1;
    m_uiFilterValue = value;
    return this;
}

struct Obj_008c9a80
{
    char pad[0x18];
    int m_items[10];
    int m_40;
    int m_44;
    void PushItem(int a);
};

// Stores a into m_items at a circular index derived from m_44 and m_40, then increments m_40, if m_40 is below 10.
// @fnv 0x008c9a80
void Obj_008c9a80::PushItem(int aiValue)
{
    if (m_40 < 10)
    {
        int iIndex = m_44 + m_40;
        if (iIndex >= 10)
            iIndex -= 10;
        m_items[iIndex] = aiValue;
        m_40 = m_40 + 1;
    }
}

void __cdecl operator delete(void*);
struct FUN_008c9ec0_shell
{
    void FUN_008c9ef0();
    void* FUN_008c9ec0(unsigned int flags);
};
// @fnv 0x008c9ec0
void* FUN_008c9ec0_shell::FUN_008c9ec0(unsigned int flags)
{
    FUN_008c9ef0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct GlobalObject_0078d3b0
{
    char d[0xc];
    ~GlobalObject_0078d3b0();
};
struct FUN_0052d240_obj
{
    char d[0x10];
    ~FUN_0052d240_obj();
};
struct FUN_00aa63c0_base
{
    char d[0x30];
    ~FUN_00aa63c0_base();
};
extern int _data_011c16bc;
struct FUN_008c9ef0 : FUN_00aa63c0_base
{
    GlobalObject_0078d3b0 a;
    GlobalObject_0078d3b0 b;
    char pad[8];
    FUN_0052d240_obj c;
    ~FUN_008c9ef0();
};
// Destructor for FUN_008c9ef0; the body is empty.
// @fnv 0x008c9ef0
FUN_008c9ef0::~FUN_008c9ef0()
{}

struct FUN_008c9fb0_shell
{
    void SignalAtOffset30();
};
// @fnv 0x008c9fb0
void FUN_008c9fb0_shell::SignalAtOffset30()
{
    ((CountingSemaphore*)((char*)this + 0x30))->Signal();
}

namespace fnv_008ca2e0 {
struct FUN_008c9fb0_shell
{
    void SignalAtOffset30();
};
struct FUN_008ca2e0_shell
{
    void CallAt(int a);
};
// @fnv 0x008ca2e0
void FUN_008ca2e0_shell::CallAt(int iIndex)
{
    ((FUN_008c9fb0_shell**)this)[iIndex]->SignalAtOffset30();
}
}  // namespace fnv_008ca2e0

struct GlobalObject_008caae0
{
    void __thiscall AITaskThreadManager_WaitForThread(int a);
};
extern GlobalObject_008caae0 g_011dfc24;

struct FUN_008ca300_shell
{
    void __thiscall AITaskManager_WaitForTasksDuringRendering();
};

// @fnv 0x008ca300
// src: COMMUNITY 0x008ca300
void __thiscall FUN_008ca300_shell::AITaskManager_WaitForTasksDuringRendering()
{
    if (*(unsigned char*)((char*)this + 0x10180))
    {
        g_011dfc24.AITaskThreadManager_WaitForThread(2);
        *(unsigned char*)((char*)this + 0x10180) = 0;
    }
}

void __fastcall AITaskThread_WaitForCompletion(void* p);
struct FUN_008ca330_shell
{
    void AITaskThreadManager_WaitForThread(int a);
};
// @fnv 0x008ca330
// src: COMMUNITY 0x008ca330
void FUN_008ca330_shell::AITaskThreadManager_WaitForThread(int aiIndex)
{
    AITaskThread_WaitForCompletion(((void**)this)[aiIndex]);
}

extern int DAT_0108583c;

// @fnv 0x008ca3c0
// src: GUESS 0x008ca3c0 (confidence: low)
void __fastcall Object_SetVirtualTable_008ca3c0(void* thisPtr)
{
    *static_cast<void**>(thisPtr) = &DAT_0108583c;
}

void __cdecl operator delete(void*);
struct FUN_008ca3e0_shell
{
    void Object_SetVirtualTable_008ca3c0();
    void* FUN_008ca3e0(unsigned int flags);
};
// Calls FUN_008ca3c0, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008ca3e0
void* FUN_008ca3e0_shell::FUN_008ca3e0(unsigned int flags)
{
    Object_SetVirtualTable_008ca3c0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl operator delete(void*);
struct FUN_008ca410_shell
{
    void FUN_008ca350();
    void* FUN_008ca410(unsigned int flags);
};
// @fnv 0x008ca410
void* FUN_008ca410_shell::FUN_008ca410(unsigned int flags)
{
    FUN_008ca350();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_008ca740
{
    int m_pad4;
    FUN_008ca740();
    virtual void vfn0();
};

struct FUN_008ca440 : FUN_008ca740
{
    int m_08;
    int m_0c;
    int* m_10;
    FUN_008ca440(int a);
    virtual void vfn0();
};

// Stores the constructor argument in m_08, zeroes m_0c, and points m_10 at m_0c.
// @fnv 0x008ca440
FUN_008ca440::FUN_008ca440(int aiValue)
{
    m_08 = aiValue;
    m_0c = 0;
    m_10 = &m_0c;
}

struct FUN_008ca520_shell
{
    void __thiscall InitVtbl();
};
extern int DAT_01085864;

// @fnv 0x008ca500
// src: GUESS 0x008ca500 (confidence: low)
void __fastcall Object_UpdateFields_008ca500(void* this_ptr)
{
    *(void**)this_ptr = &DAT_01085864;
    ((FUN_008ca520_shell*)this_ptr)->InitVtbl();
}

namespace fnv_008ca520 {
extern int DAT_01085884;
struct FUN_008ca520_shell
{
    int* vtbl;
    void InitVtbl();
};
// @fnv 0x008ca520
void FUN_008ca520_shell::InitVtbl()
{
    vtbl = &DAT_01085884;
}
}  // namespace fnv_008ca520

void __cdecl operator delete(void*);
struct FUN_008ca540_shell
{
    void Object_UpdateFields_008ca500();
    void* FUN_008ca540(unsigned int flags);
};
// Calls FUN_008ca500, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008ca540
void* FUN_008ca540_shell::FUN_008ca540(unsigned int flags)
{
    Object_UpdateFields_008ca500();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl operator delete(void*);
struct FUN_008ca570_shell
{
    void InitVtbl();
    void* FUN_008ca570(unsigned int flags);
};
// Calls InitVtbl, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008ca570
void* FUN_008ca570_shell::FUN_008ca570(unsigned int flags)
{
    InitVtbl();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_008ca5a0_node
{
    int a;
    int b;
    int c;
    FUN_008ca5a0_node* next;
};
struct FUN_008ca5a0_pool
{
    bool BSTFreeList_Allocate(FUN_008ca5a0_node** out, unsigned int arg);
};
struct FUN_008ca5a0_mgr
{
    int f0;
    int f4;
    FUN_008ca5a0_pool* pool;
    FUN_008ca5a0_node* head;
    FUN_008ca5a0_node** tail;
    bool AppendNode(unsigned int arg);
};
// @fnv 0x008ca5a0
bool FUN_008ca5a0_mgr::AppendNode(unsigned int arg)
{
    bool result;
    FUN_008ca5a0_node* node;
    if (pool && pool->BSTFreeList_Allocate(&node, arg))
    {
        if (!head)
            tail = &head;
        *tail = node;
        node->next = 0;
        tail = &node->next;
        result = true;
    }
    else
    {
        result = false;
    }
    return result;
}

struct List_009e03e0
{
    void RemoveAll();
};

// If the new value differs from reinterpret_cast<int&>(m_pCurrentQuest), stores it and, when it becomes zero, clears the m_6c4 list.
// @fnv 0x009529d0
// src: XBOX_PDB 0x009529d0
void PlayerCharacter::SetActiveQuest(int a)
{
    if (a != reinterpret_cast<int&>(m_pCurrentQuest))
    {
        reinterpret_cast<int&>(m_pCurrentQuest) = a;
        if (reinterpret_cast<int&>(m_pCurrentQuest))
        {
        }
        else
        {
            reinterpret_cast<List_009e03e0*>(layoutPadding6C4)->RemoveAll();
        }
    }
}

struct BaseT
{
    int m_auiShapeKeys[7];
    ~BaseT();
};

struct FUN_008ca480
{
    int m_v;
    ~FUN_008ca480();
};

struct FUN_008c83a0 : BaseT
{
    FUN_008ca480 m_1c;
    ~FUN_008c83a0();
};

// Destructor for FUN_008c83a0; the body is empty and the base and member destructors run implicitly.
// @fnv 0x008c83a0
FUN_008c83a0::~FUN_008c83a0()
{}

struct FUN_008c8430_base
{
    char d[0x40];
    ~FUN_008c8430_base();
};
struct FUN_008c8890_m
{
    char d[0x38];
    ~FUN_008c8890_m();
};
struct FUN_008c8b50_m
{
    char d[0x44];
    ~FUN_008c8b50_m();
};
struct FUN_008c8a00_m
{
    char d[0x3c];
    ~FUN_008c8a00_m();
};
struct FUN_008c9080_m
{
    char d[0x40];
    ~FUN_008c9080_m();
};
struct FUN_008c91d0_m
{
    char d[0x3c];
    ~FUN_008c91d0_m();
};
struct FUN_008ca350_m
{
    char d[0x20];
    ~FUN_008ca350_m();
};
struct FUN_008c9430 : FUN_008c8430_base
{
    FUN_008c8890_m a;
    FUN_008c8b50_m b;
    FUN_008c8a00_m c;
    FUN_008c9080_m d;
    FUN_008c91d0_m e;
    FUN_008ca350_m f;
    ~FUN_008c9430();
};
// @fnv 0x008c9430
FUN_008c9430::~FUN_008c9430()
{}

struct FUN_008c9a20_shell
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    FUN_008c9a20_shell* MobileObjectMessage_MobileObjectMessage(unsigned int v);
};
// Initialises the object's fields: sets a and c to 0 and stores v in b, then returns this.
// @fnv 0x008c9a20
// src: XBOX_PDB 0x008c9a20
FUN_008c9a20_shell* FUN_008c9a20_shell::MobileObjectMessage_MobileObjectMessage(unsigned int v)
{
    a = 0;
    b = v;
    c = 0;
    return this;
}

void* __cdecl operator new(unsigned int);
struct FUN_008c9bd0 : BSThread
{
    char e[0x48];
    FUN_008c9bd0(unsigned int aiThread);
};
struct FUN_008c9ae0_mgr
{
    FUN_008c9bd0* threads[3];
    int count;
    void CreateThread(unsigned int aiThread);
};
// @fnv 0x008c9ae0
void FUN_008c9ae0_mgr::CreateThread(unsigned int aiThread)
{
    if (count < 3)
    {
        threads[count] = new FUN_008c9bd0(aiThread);
        threads[count]->Initialize(0x10000, 0, false);
        threads[count]->SetSchedulingPriority(aiThread);
        threads[count]->SetName("AI Task Thread");
        count = count + 1;
    }
}

namespace fnv_008c9bd0 {
struct FUN_008c9bd0 : BSThread
{
    CountingSemaphore start;
    CountingSemaphore finish;
    unsigned char quit;
    unsigned int arg;
    hkMemoryRouter router;
    FUN_008c9bd0(unsigned int aiThread);
    virtual void v0();
};
// Initializes the thread's start and finish objects, stores the thread argument in arg, and clears quit.
// @fnv 0x008c9bd0
FUN_008c9bd0::FUN_008c9bd0(unsigned int aiThread) : start(0, 10), finish(0, 10)
{
    arg = aiThread;
    quit = 0;
}
}  // namespace fnv_008c9bd0

struct FUN_008c8190
{
    char data[12];
    FUN_008c8190();
};
struct Mid
{
    virtual void _a();
    virtual void _b(const FUN_008c8190&);
};
struct Owner
{
    void CallMidVirtualB();
};
// Constructs a FUN_008c8190 temporary and invokes the virtual _b on the Mid subobject at offset 0x1c of this.
// @fnv 0x008ca040
void Owner::CallMidVirtualB()
{
    reinterpret_cast<Mid*>(reinterpret_cast<char*>(this) + 0x1c)->_b(FUN_008c8190());
}

struct Date
{
    int m_v[4];
    ~Date();
};
struct FUN_008ca3c0
{
    int m_auiShapeKeys[2];
    virtual ~FUN_008ca3c0();
};
struct FUN_008ca350 : FUN_008ca3c0
{
    Date m_items[0x1000];
    virtual ~FUN_008ca350();
};
// Destructs the array of Date elements held by the object.
// @fnv 0x008ca350
FUN_008ca350::~FUN_008ca350()
{}

namespace fnv_008ca480 {
struct Tmp_008ca480
{
    int a, b, c;
    Tmp_008ca480();
};
struct FUN_008ca500
{
    int m_auiShapeKeys;
    virtual ~FUN_008ca500();
};
struct FUN_008ca480 : FUN_008ca500
{
    bool BSTCommonMessageQueue_MobileObjectMessage_TryPop(Tmp_008ca480* t);
    virtual ~FUN_008ca480();
};
// Destructor that repeatedly calls FUN_006ec390 with a temporary Tmp_008ca480 until it returns false.
// @fnv 0x008ca480
FUN_008ca480::~FUN_008ca480()
{
    Tmp_008ca480 t;
    while (BSTCommonMessageQueue_MobileObjectMessage_TryPop(&t))
    {
    }
}
}  // namespace fnv_008ca480

struct Node_008ca620;
struct Arg_008ca620
{
    void InitializeFields_008caa70(void* p);
};
struct List_008ca620
{
    void ProcessState_008ca770(Node_008ca620** pp);
};
struct Node_008ca620
{
    int m_auiShapeKeys[3];
    Node_008ca620* m_0c;
    void* _ref_006815c0();
};
struct Obj_008ca620
{
    int m_auiShapeKeys[2];
    List_008ca620* m_08;
    Node_008ca620* m_0c;
    bool PopNode(Arg_008ca620* a);
};

// @fnv 0x008ca620
bool Obj_008ca620::PopNode(Arg_008ca620* a)
{
    bool bPopped;
    Node_008ca620* node = m_0c;
    if (node)
    {
        a->InitializeFields_008caa70(node->_ref_006815c0());
        m_0c = node->m_0c;
        m_08->ProcessState_008ca770(&node);
        bPopped = true;
    }
    else
    {
        bPopped = false;
    }
    return bPopped;
}

namespace fnv_008ca680 {
struct GlobalObject_008caae0
{
    char d[0x10];
    GlobalObject_008caae0();
    ~GlobalObject_008caae0();
};
struct FUN_008ca800_base
{
    virtual void v0();
    char d[8];
    FUN_008ca800_base();
    ~FUN_008ca800_base();
};
struct FUN_008ca680 : FUN_008ca800_base
{
    GlobalObject_008caae0 items[0x1000];
    FUN_008ca680();
    virtual void v0();
    void InitFreeList(unsigned int n, GlobalObject_008caae0* p);
};
// Constructs the object and calls InitFreeList with 0x1000 and the items array.
// @fnv 0x008ca680
FUN_008ca680::FUN_008ca680()
{
    InitFreeList(0x1000, items);
}
}  // namespace fnv_008ca680

void __cdecl operator delete(void*);
struct FUN_008ca710_shell
{
    void FUN_008ca480();
    void* FUN_008ca710(unsigned int flags);
};
// @fnv 0x008ca710
void* FUN_008ca710_shell::FUN_008ca710(unsigned int flags)
{
    FUN_008ca480();
    if (flags & 1)
        operator delete(this);
    return this;
}


// If apMob is an actor with a flag at offset 0xbc set, or a talking activator, calls Unk_9A with 0.0f.
// @fnv 0x008c8910
void AnimationTaskData::ProcessMobileObject(MobileObject* apMob)
{
    MobileObject* pmob = apMob;
    if (pmob && pmob->IsActor())
    {
        Actor* pact = (Actor*)pmob;
        if (*(bool*)((char*)pact + 0xbc))
        {
            pact->Unk_9A(0.0f);
        }
    }
    else if (pmob && pmob->IsTalkingActivator())
    {
        pmob->Unk_9A(0.0f);
    }
}

// @fnv 0x008c8240
void MobileObjectTaskletData::ProcessMessages(int eType)
{
    this->eType = eType;
    // Raw storage preserves the original constructor-only lifetime.
    struct { unsigned int word0, word1; void* word2; } msg;
    reinterpret_cast<MobileObjectTaskletContext*>(&msg)->MobileObjectTaskletContext::MobileObjectTaskletContext();
    while (kMessageQueue.Pop(*reinterpret_cast<MobileObjectTaskletContext*>(&msg)))
    {
        if (!ProcessMessage(&msg, eType))
            break;
    }
}


struct MobileObjectExt
{
    void TESObjectREFR_RunScript();
};

// If apMob is an actor and the script check passes, calls FUN_00565870 on it and increments m_3C.
// @fnv 0x008c9110
// File-local extension for a method absent from the shared declaration.
struct ProcessActorScriptMethods : ActorsScriptTaskData
{
    void Run(MobileObject* apMob);
};
void ProcessActorScriptMethods::Run(MobileObject* apMob)
{
    MobileObject* pmob = apMob;
    if (pmob && pmob->IsActor() && Script::IsConsolePlatform())
    {
        ((MobileObjectExt*)pmob)->TESObjectREFR_RunScript();
        uiRunCount++;
    }
}


// @fnv 0x008c81c0
bool MobileObjectTaskletData::ProcessMessage(void* aMessage, int aThread)
{
    bool bResult = true;
    switch (static_cast<const MobileObjectTaskletContext*>(aMessage)->eType)
    {
    case 0:
        MobileObjectTaskletState = static_cast<const MobileObjectTaskletContext*>(aMessage)->uiObjectCount;
        SetMobileObjectCount(static_cast<const MobileObjectTaskletContext*>(aMessage)->uiObjectCount);
        break;
    case 1:
        ProcessMobileObject(static_cast<MobileObject*>(static_cast<const MobileObjectTaskletContext*>(aMessage)->pObject));
        break;
    case 2:
        SetThreadNumber(aThread);
        bResult = false;
        break;
    }
    return bResult;
}

void MobileObjectTaskletData::Process()
{
    // Raw storage preserves the original constructor-only lifetime.
    struct { unsigned int word0, word1; void* word2; } msg;
    reinterpret_cast<MobileObjectTaskletContext*>(&msg)->MobileObjectTaskletContext::MobileObjectTaskletContext();
    while (kMessageQueue.TryPop(*reinterpret_cast<MobileObjectTaskletContext*>(&msg)))
    {
        if (!ProcessMessage(&msg, eType))
            return;
    }
    ((PathingTaskData*)this)->SetTaskYielded();
}


namespace fnv_008c82a0 {
struct FUN_008c82e0
{
    int pad[13];
    FUN_008c82e0(int a);
    virtual void Run();
};
struct FUN_008c82a0 : FUN_008c82e0
{
    float f38;
    int f3c;
    FUN_008c82a0(int a);
    virtual void Run();
};
// Initializes the derived object's f38 to 0.0f and f3c to 0 after constructing the base with a.
// @fnv 0x008c82a0
FUN_008c82a0::FUN_008c82a0(int a) : FUN_008c82e0(a)
{
    f38 = 0.0f;
    f3c = 0;
}
}  // namespace fnv_008c82a0

// @fnv 0x008c82e0
MobileObjectTaskletData::MobileObjectTaskletData(BSTFreeList<MobileObjectTaskletContext>* arg)
    : pMobList(0), kMessageQueue(arg), MobileObjectTaskletState(0), eType(0)
{}


namespace fnv_008c8450 {
extern ActorTaskManager g_011dfbe8;
extern ActorTaskManager g_011dfc04;

// Clears f38 and f3c, then calls QueryPerformanceCounter on g_011dfc04 and g_011dfbe8.
// @fnv 0x008c8450
// File-local extension for a method absent from the shared declaration.
struct ResetMovementTaskMethods : MovementTaskData
{
    void Run(unsigned int auUnused);
};
void ResetMovementTaskMethods::Run(unsigned int auUnused)
{
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x38) = 0.0f;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3c) = 0;
    g_011dfc04.QueryPerformanceCounter(0);
    g_011dfbe8.QueryPerformanceCounter(0);
}
}  // namespace fnv_008c8450

namespace fnv_008c8ae0 {
struct FUN_008c82e0
{
    int pad[14];
    FUN_008c82e0(int a);
    virtual void Run();
};
struct FUN_008c8ae0 : FUN_008c82e0
{
    int f3c;
    int f40;
    FUN_008c8ae0(int a);
    virtual void Run();
};
// Initializes the two derived-class fields f3c and f40 to zero after constructing the base class.
// @fnv 0x008c8ae0
FUN_008c8ae0::FUN_008c8ae0(int a) : FUN_008c82e0(a)
{
    f3c = 0;
    f40 = 0;
}
}  // namespace fnv_008c8ae0

namespace fnv_008c8b70 {

extern ActorTaskManager g_011dfbe8;
extern Actor* g_thePlayer;
void HighProcess_ClearWanderStarted();

// @fnv 0x008c8b70
// File-local extension for a method absent from the shared declaration.
struct ResetPackageTaskMethods : PackageUpdateTaskData
{
    void Run(unsigned int auiUnused);
};
void ResetPackageTaskMethods::Run(unsigned int auiUnused)
{
    uiUpdatedCount = 0;
    uiSkippedCount = 0;
    HighProcess_ClearWanderStarted();
    g_thePlayer->FUN_008c8bb0(0);
    g_011dfbe8.QueryPerformanceCounter(0);
}
}  // namespace fnv_008c8b70

namespace fnv_008c90a0 {
extern ActorTaskManager g_011dfbe8;
extern ActorTaskManager g_011dfc04;
extern ActorTaskManager g_011dfc38;

// Clears f3c and queries the three performance counters with argument 0.
// @fnv 0x008c90a0
// File-local extension for a method absent from the shared declaration.
struct ResetActorScriptTaskMethods : ActorsScriptTaskData
{
    void Run(unsigned int a);
};
void ResetActorScriptTaskMethods::Run(unsigned int a)
{
    uiRunCount = 0;
    g_011dfc38.QueryPerformanceCounter(0);
    g_011dfc04.QueryPerformanceCounter(0);
    g_011dfbe8.QueryPerformanceCounter(0);
}
}  // namespace fnv_008c90a0

namespace fnv_008c9c70 {

struct GlobalObject_008caab0
{
    MobileObjectTaskletData* AITaskQueue_Dequeue();
};
extern GlobalObject_008caab0 g_011dfb98;
struct FUN_008c9c70_cls
{
    char pad0[0x30];
    CountingSemaphore start;
    CountingSemaphore finish;
    unsigned char quit;
    char pad1[3];
    int arg;
    void InitMemory();
    void DispatchTask();
    unsigned int RunTaskletLoop();
};
// Waits on start, processes tasklet data via g_011dfb98 until none remain, signals finish, and exits when quit is set.
// @fnv 0x008c9c70
unsigned int FUN_008c9c70_cls::RunTaskletLoop()
{
    MobileObjectTaskletData* pTaskletData;
    InitMemory();
    while (1)
    {
        start.Wait();
        if (quit)
            break;
        pTaskletData = 0;
        do
        {
            pTaskletData = g_011dfb98.AITaskQueue_Dequeue();
            if (pTaskletData)
                pTaskletData->ProcessMessages(arg);
        } while (pTaskletData);
        finish.Signal();
    }
    DispatchTask();
    return 0;
}
}  // namespace fnv_008c9c70

struct Elem
{
    void SignalAtOffset30();
};
struct FUN_008c9f70_this
{
    int pad[3];
    int count;
    void CallAllElements();
};
// Iterates over count elements and calls SignalAtOffset30 on each one.
// @fnv 0x008c9f70
void FUN_008c9f70_this::CallAllElements()
{
    for (int i = 0; i < count; i++)
        ((Elem**)this)[i]->SignalAtOffset30();
}

struct FUN_008c7490_this;
void __fastcall AITaskThread_WaitForCompletion(FUN_008c7490_this*);
struct FUN_008c9fd0_this
{
    int pad[3];
    int count;
    void AITaskThreadManager_WaitForThreads();
};
// Calls FUN_008c7490 on each of the count pointers stored in the array starting at this.
// @fnv 0x008c9fd0
// src: XBOX_PDB 0x008c9fd0
void FUN_008c9fd0_this::AITaskThreadManager_WaitForThreads()
{
    for (int i = 0; i < count; i++)
        AITaskThread_WaitForCompletion(((FUN_008c7490_this**)this)[i]);
}

struct S008ca010
{
    virtual void f0();
    virtual void f1(int);
};
struct H008ca010
{
    char pad[0x1C];
    S008ca010 inner;
    void ForwardToInner(int);
};
// Calls f1 on the inner object, passing the given int through.
// @fnv 0x008ca010
void H008ca010::ForwardToInner(int aiValue)
{
    inner.f1(aiValue);
}


// If apMob is a valid mobile object with v100 set, resets the actor's v2f8 to 0 when byte 0xbc is nonzero and increments m_unk38.
// @fnv 0x008c8a70
void ActorUpdateTaskData::UpdateActorTask(MobileObject* apMob)
{
    MobileObject* pmob = apMob;
    Actor* pact;
    if (pmob != 0 && pmob->IsActor())
    {
        pact = (Actor*)pmob;
        if (*((unsigned char*)pact + 0xbc) != 0)
        {
            static_cast<MobileObject*>(pact)->Update(0.0f);
        }
        uiRunCount++;
    }
}

struct M0
{
    char pad[0x40];
    M0(void*);
    ~M0();
};
struct M1
{
    char pad[0x38];
    M1(void*);
    ~M1();
};
struct M2
{
    char pad[0x44];
    M2(void*);
    ~M2();
};
struct M3
{
    char pad[0x3c];
    M3(void*);
    ~M3();
};
struct M4
{
    char pad[0x40];
    M4(void*);
    ~M4();
};
struct M5
{
    char pad[0x3c];
    M5(void*);
    ~M5();
};
struct M6
{
    char pad[0x1000c];
    void FUN_008ca680();
};

// ActorTaskManager.h lacks the constructor at 0x008c9330.
// Retain this lifetime view until that constructor can be declared there.
struct FUN_008c9330
{
    M0 m0;
    M1 m1;
    M2 m2;
    M3 m3;
    M4 m4;
    M5 m5;
    M6 m6;
    char m_flag;

    FUN_008c9330();
};

// Constructs the object, initializing m0 through m5 with a pointer to m6, calling m6.FUN_008ca680(), and setting m_flag to 0.
// @fnv 0x008c9330
FUN_008c9330::FUN_008c9330() : m0(&m6), m1(&m6), m2(&m6), m3(&m6), m4(&m6), m5(&m6)
{
    m6.FUN_008ca680();
    m_flag = 0;
}

namespace fnv_0077a480 {

extern GameTimerRecord g_timeGlobal;





void __cdecl QuestUpdateManager_AddQuestNamesTail(char*);

extern int DAT_011d96ac;
extern int _pme;
extern ActorTaskManager g_011d96cc;
extern PlayerCharacter* _g_thePlayer;

struct Task
{
    void* quest;
    int state;
    unsigned char padding[0x31c];
};

// @fnv 0x0077a480
// src: XBOX_PDB 0x0077a480
void __cdecl HUDMainMenu_ShowQuestName(TESQuest* quest)
{
    g_011d96cc.QueryPerformanceCounter(0);

    if (quest == 0 || _pme == 0)
        return;

    DAT_011d96ac = g_timeGlobal.GetTime();

    Task* task = new Task;
    task->quest = quest;

    if (quest->HasFlag40())
    {
        task->state = 2;
        if (_g_thePlayer->PlayerCharacter_GetActiveQuest() == quest)
            _g_thePlayer->SetActiveQuest(0);
    }
    else if (quest->GetCompleted())
    {
        task->state = 1;
        if (_g_thePlayer->PlayerCharacter_GetActiveQuest() == quest)
            _g_thePlayer->SetActiveQuest(0);
    }
    else
    {
        task->state = 0;
        if (_g_thePlayer->PlayerCharacter_GetActiveQuest() == 0)
            _g_thePlayer->SetActiveQuest(reinterpret_cast<int>(quest));
    }

    QuestUpdateManager_AddQuestNamesTail(reinterpret_cast<char*>(task));

    g_011d96cc.WaitForTasksDuringRendering();
}
}  // namespace fnv_0077a480

struct ResourceHandle
{
    virtual void Unused0();
    virtual void Unused1();
    virtual void Dispatch(void* object, unsigned int flags);
};
struct Completion
{
    void hkStackMemory_initMemory();
};
struct ContextBlock
{
    unsigned int unk00;
    ResourceHandle* TESMain_GetThread();
    Completion* FUN_006815c0(int first, int second);
};
struct TaskToken
{
    unsigned int value;
    TaskToken(unsigned int initialValue);
    TaskToken(const TaskToken& other);
};
struct DispatchQueue
{
    virtual void Unused0();
    virtual void Unused1();
    virtual void Unused2();
    virtual void AdvanceFade();
    virtual void Queue(ContextBlock* context, TaskToken token);
};
void hkBaseSystem_quitThread();
DispatchQueue* hkMemorySystem_getInstance();
struct TaskOwner
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c;
    ContextBlock context;
    unsigned int unk54, unk58, unk5c, unk60;
    unsigned int unk64, unk68, unk6c, unk70;
    void* payload;
    void DispatchTask();
};
// @fnv 0x008c9e40
void TaskOwner::DispatchTask()
{
    context.TESMain_GetThread()->Dispatch(payload, 0x16800);
    hkBaseSystem_quitThread();
    hkMemorySystem_getInstance()->Queue(&context, TaskToken(1));
    context.FUN_006815c0(0, 0)->hkStackMemory_initMemory();
}

// Stand-in for the game's PlayerCharacter.  The unit file only
// forward-declares it (as PC7d), so a separate class is needed to
// reach the IsSleepingOrResting() member.


// Advances the task counter and, depending on the mob's state, calls Unk_D2, FUN_009bec10 or FUN_009ae580 with 0.0f.
// @fnv 0x008c9220
void __fastcall UpdateProjectileMovement(MobileObject*, float);
void __fastcall UpdateExplosionMovement(MobileObject*, float);
void MovementTaskData::UpdateMovementTask(HighProcess* apMob)
{
    MobileObject* pCurrentObject = reinterpret_cast<MobileObject*>(apMob);
    if (pCurrentObject && pCurrentObject->IsActor())
    {
        Actor* pActor = static_cast<Actor*>(pCurrentObject);
        if (pActor->m_bFirstActorFlag)
        {
            pActor->Virtual_348(0.0f, g_thePlayer->IsSleepingOrResting());
        }
    }
    else
    {
        if (pCurrentObject->IsProjectile())
        {
            MobileObject* pObj = pCurrentObject;
            UpdateProjectileMovement(pObj, 0.0f);
        }
        else if (pCurrentObject->IsExplosion())
        {
            MobileObject* pTarget = pCurrentObject;
            UpdateExplosionMovement(pTarget, 0.0f);
        }
    }
    uiRunCount++;
}

struct CountTask
{
    unsigned state, kind, value;
    CountTask* MobileObjectMessage_MobileObjectMessage(unsigned);
};
struct ActorTask
{
    unsigned state, kind;
    Actor* value;
    ActorTask* MobileObjectMessage_MobileObjectMessage_008c9a50(Actor*);
};
struct WorkQueue
{
    unsigned state;
    void ForwardToInner(const CountTask&);
    void ForwardToInner(const ActorTask&);
    void CallMidVirtualB();
    void FUN_008c8240(int);
};
struct BoolSettingView
{
    bool* Bool();
};
struct IntSettingView
{
    int* Int();
};
extern bool DAT_011a34e7, DAT_011f1220;
extern BoolSettingView DAT_011dfb68, DAT_011dfc70, DAT_011dfb88;
extern IntSettingView DAT_011c3ea4, DAT_011d10d4;
struct ThreadManagerView
{
    void CreateThread(unsigned);
    void CallAllElements();
    void AITaskThreadManager_WaitForThreads();
};
extern ThreadManagerView DAT_011dfc24;
struct QueueManagerView
{
    void PushItem(WorkQueue*);
};
extern QueueManagerView DAT_011dfb98;
struct ActorListView
{
    unsigned ProcessArray_GetProcessLevelTail();
    Actor* ProcessArray_GetItem();
};
struct ActorManagerView
{
    ActorListView* FUN_00717e50(int);
};
extern ActorManagerView DAT_011e0e80;
void __cdecl FUN_007034c0(int);
void __cdecl FUN_00703490();
struct TaskOwnerTarget
{
    WorkQueue first;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    WorkQueue second;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    WorkQueue third;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    WorkQueue fourth;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    WorkQueue fifth;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    WorkQueue sixth;
    void AITaskManager_UpdateTasks();
};
// If enabled, queues count and actor tasks into the six work queues, dispatches or clears them, and runs the int-setting callbacks.
// @fnv 0x008c94e0
// src: XBOX_PDB 0x008c94e0
void TaskOwnerTarget::AITaskManager_UpdateTasks()
{
    unsigned count, uiActorCount;

    if (DAT_011a34e7)
    {
        if (*DAT_011dfb68.Bool())
        {
            DAT_011dfc24.CreateThread(1);
            DAT_011dfc24.CreateThread(3);
            DAT_011dfc24.CreateThread(5);
        }
        DAT_011a34e7 = false;
    }
    if (DAT_011f1220 && DAT_011e0e80.FUN_00717e50(0)->ProcessArray_GetProcessLevelTail() > 0)
    {
        uiActorCount = DAT_011e0e80.FUN_00717e50(0)->ProcessArray_GetProcessLevelTail();
        if (!*DAT_011dfc70.Bool())
        {
            CountTask a;
            first.ForwardToInner((a.MobileObjectMessage_MobileObjectMessage(uiActorCount), a));
        }
        {
            CountTask b;
            third.ForwardToInner((b.MobileObjectMessage_MobileObjectMessage(uiActorCount), b));
        }
        if (*DAT_011c3ea4.Int() == 1)
        {
            {
                CountTask c;
                fourth.ForwardToInner((c.MobileObjectMessage_MobileObjectMessage(uiActorCount), c));
            }
            {
                CountTask d;
                second.ForwardToInner((d.MobileObjectMessage_MobileObjectMessage(uiActorCount), d));
            }
        }
        {
            CountTask e;
            fifth.ForwardToInner((e.MobileObjectMessage_MobileObjectMessage(uiActorCount), e));
        }
        if (!*DAT_011dfb88.Bool())
        {
            CountTask f;
            sixth.ForwardToInner((f.MobileObjectMessage_MobileObjectMessage(uiActorCount), f));
        }
        count = 0;
        do
        {
            if (!*DAT_011dfc70.Bool())
            {
                ActorTask g;
                first.ForwardToInner((g.MobileObjectMessage_MobileObjectMessage_008c9a50(DAT_011e0e80.FUN_00717e50(count)->ProcessArray_GetItem()), g));
            }
            {
                ActorTask h;
                third.ForwardToInner((h.MobileObjectMessage_MobileObjectMessage_008c9a50(DAT_011e0e80.FUN_00717e50(count)->ProcessArray_GetItem()), h));
            }
            if (*DAT_011c3ea4.Int() == 1)
            {
                {
                    ActorTask j;
                    fourth.ForwardToInner((j.MobileObjectMessage_MobileObjectMessage_008c9a50(DAT_011e0e80.FUN_00717e50(count)->ProcessArray_GetItem()), j));
                }
                {
                    ActorTask k;
                    second.ForwardToInner((k.MobileObjectMessage_MobileObjectMessage_008c9a50(DAT_011e0e80.FUN_00717e50(count)->ProcessArray_GetItem()), k));
                }
            }
            {
                ActorTask l;
                fifth.ForwardToInner((l.MobileObjectMessage_MobileObjectMessage_008c9a50(DAT_011e0e80.FUN_00717e50(count)->ProcessArray_GetItem()), l));
            }
            if (!*DAT_011dfb88.Bool())
            {
                ActorTask m;
                sixth.ForwardToInner((m.MobileObjectMessage_MobileObjectMessage_008c9a50(DAT_011e0e80.FUN_00717e50(count)->ProcessArray_GetItem()), m));
            }
            ++count;
        } while (count < DAT_011e0e80.FUN_00717e50(0)->ProcessArray_GetProcessLevelTail());
        if (!*DAT_011dfc70.Bool())
            first.CallMidVirtualB();
        third.CallMidVirtualB();
        if (*DAT_011c3ea4.Int() == 1)
        {
            second.CallMidVirtualB();
            fourth.CallMidVirtualB();
        }
        fifth.CallMidVirtualB();
        if (!*DAT_011dfb88.Bool())
            sixth.CallMidVirtualB();
        if (*DAT_011dfb68.Bool())
        {
            if (*DAT_011c3ea4.Int() == 1)
                DAT_011dfb98.PushItem(&fourth);
            DAT_011dfb98.PushItem(&third);
            DAT_011dfb98.PushItem(&fifth);
            if (!*DAT_011dfc70.Bool())
                DAT_011dfb98.PushItem(&first);
            if (!*DAT_011dfb88.Bool())
            {
                DAT_011dfb98.PushItem(&sixth);
                DAT_011dfb98.PushItem(&second);
            }
            DAT_011dfc24.CallAllElements();
            DAT_011dfc24.AITaskThreadManager_WaitForThreads();
        }
        else
        {
            if (!*DAT_011dfc70.Bool())
                first.FUN_008c8240(0);
            third.FUN_008c8240(0);
            fifth.FUN_008c8240(0);
            if (*DAT_011c3ea4.Int() == 1)
            {
                second.FUN_008c8240(0);
                fourth.FUN_008c8240(0);
            }
            if (!*DAT_011dfb88.Bool())
                sixth.FUN_008c8240(0);
        }
    }
    if (*DAT_011c3ea4.Int() == 1)
    {
        FUN_007034c0(*DAT_011d10d4.Int());
        FUN_00703490();
    }
}

namespace fnv_008c84c0 {
// ---- shell declarations ----
class ActorProjectileMethods;

class V20SP
{
  public:
    virtual void a00();
    virtual void a04();
    virtual void a08();
    virtual void a0c();
    virtual void a10();
    virtual void a14();
    virtual void a18();
    virtual void a1c();
    virtual unsigned char a20();
};

class ABSP
{
  public:
    unsigned char IsDone();
    unsigned int GetTimeStamp();
};

class PROJ
{
  public:
    char pad0[0x30];
    V20SP m30;
    char pad1[0x90 - 0x34];
    ABSP m90;
};


// Additional operations absent from Actor.h; the layout is inherited.
class ActorProjectileMethods : public Actor
{
public:
    PROJ* GetProjectileBase();
    unsigned char Actor_IsInCombatWithActor(ActorProjectileMethods* a);
    int Actor_GetDetectionLevelAgainstActor(int a, ActorProjectileMethods* b, unsigned char* c, unsigned char d, int e, int f, unsigned char* g);
    void PlayerCharacter_InsertPerceivedActor(ActorProjectileMethods* a, unsigned char b, int c);
    void PlayerCharacter_RemovePerceivedActor(ActorProjectileMethods* a);
};

class TG
{
  public:
    float GetTime();
};

class FS
{
  public:
    float* Float();
};

class S3
{
  public:
    float FUN_007014e0(int a);
};

class S4
{
  public:
    void ProcessLists_InsertActorCloseToPlayer(ActorProjectileMethods* a);
};

extern ActorProjectileMethods* DAT_011dea3c;
extern S3* DAT_011d8804;
// 0x011de45c holds the TESSaveLoadGame singleton; its GetLoading() is 0x0047c850 (xor al, al; ret: folded return false).
extern TESSaveLoadGame* DAT_011de45c;
extern TG DAT_011f6394;
extern FS DAT_011ccf94;
extern FS DAT_011d13c8;
extern S4 DAT_011e0e80;


float BSMIN(float a, float b);
float _RandomFloat(float a, float b);

class Owner
{
  public:
    char pad30[0x30];
    unsigned int m30;
    char pad34[8];
    int m3c;

    void UpdateProjectile(ActorProjectileMethods* arg);
};

// @fnv 0x008c84c0
void Owner::UpdateProjectile(ActorProjectileMethods* arg)
{
    float v6 = (double)m30 * DAT_011f6394.GetTime();
    v6 = BSMIN(v6, 5.0f);
    v6 = _RandomFloat(0.0f, v6);
    ActorProjectileMethods* p = NULL;
    if (arg && static_cast<MobileObject*>(arg)->IsActor())
    {
        p = arg;
        ActorProjectileMethods* aQ = p;
        if (aQ->m_bFirstActorFlag && !aQ->GetProjectileBase()->m30.a20())
        {
            float v3 = aQ->TESObjectREFR_GetDistanceFromReference(DAT_011dea3c, 0, 0);
            if (aQ != DAT_011dea3c && !DAT_011de45c->GetLoading())
            {
                if (reinterpret_cast<float (__thiscall*)(ActorProjectileMethods*)>((*reinterpret_cast<void***>(p))[0xad])(p) < 0.0 && !aQ->Actor_IsUnConscious() && !reinterpret_cast<unsigned char (__thiscall*)(ActorProjectileMethods*, int)>((*reinterpret_cast<void***>(p))[0x8b])(p, 0))
                {
                    if (DAT_011d8804->FUN_007014e0(1) <= 0.0)
                    {
                        reinterpret_cast<void (__thiscall*)(ActorProjectileMethods*, float)>((*reinterpret_cast<void***>(p))[0xac])(p, v6);
                        if (static_cast<const MobileObject*>(aQ)->FUN_008d8520()->CanUsePlayerAction(aQ))
                        {
                            unsigned char v16 = 0;
                            unsigned char v1e2 = p->Actor_IsInCombat();
                            unsigned char v1d = 0;
                            int aV14 = DAT_011dea3c->Actor_GetDetectionLevelAgainstActor(1, p, &v16, v1e2, 0, 0, &v1d);
                            unsigned char v15 = 0;
                            int v1c2 = 0;
                            if (p->IsHostileToActor(DAT_011dea3c, 0, &v1c2, false) || p->Actor_IsInCombatWithActor(DAT_011dea3c))
                            {
                                v15 = 1;
                            }
                            else if (v1c2 == 0 || v1c2 == 1)
                            {
                                if (p->GetProjectileBase()->m90.IsDone() &&
                                    p->GetProjectileBase()->m90.GetTimeStamp() > 0)
                                    v15 = 1;
                            }
                            if (p)
                            {
                                if (v3 < *DAT_011ccf94.Float())
                                    DAT_011e0e80.ProcessLists_InsertActorCloseToPlayer(aQ);
                            }
                            if ((double)aV14 >= *DAT_011d13c8.Float())
                            {
                                DAT_011dea3c->PlayerCharacter_InsertPerceivedActor(p, v15, 0);
                            }
                            else if (v1d || v16)
                            {
                                DAT_011dea3c->PlayerCharacter_InsertPerceivedActor(p, v15, 1);
                            }
                            else
                            {
                                DAT_011dea3c->PlayerCharacter_RemovePerceivedActor(p);
                            }
                        }
                    }
                }
                else
                {
                    if (reinterpret_cast<float (__thiscall*)(ActorProjectileMethods*)>((*reinterpret_cast<void***>(p))[0xad])(p) < 0.0)
                        DAT_011dea3c->PlayerCharacter_RemovePerceivedActor(p);
                    p->Unk_AE();
                }
            }
        }
        m3c++;
    }
}
}  // namespace fnv_008c84c0

namespace fnv_008c8be0 {
bool __fastcall ShouldUpdateActor(Actor*);
void __fastcall ApplyFatigueDamage(Actor*, float);
// Additional Actor operation absent from Actor.h; no layout is duplicated.
struct FollowerActorMethods : Actor
{
    bool IsFollowerOf(Actor*);
};


struct FollowerExtra : ExtraDataList
{
    ExtraFollower* ExtraDataList_GetFollowerExtra();
    void ExtraDataList_RemoveFollower(Actor* actor);
    void ExtraDataList_RemoveFollowerExtra();
};
// This view supplies the float-taking update slot at vtable index 0x97.


extern PlayerCharacter* g_thePlayer;
class UpdateManager
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    int pending;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    unsigned int updatedObjects;
    unsigned int updatedActors;
    void UpdateMobileObject(MobileObject* object);
};
// @fnv 0x008c8be0
void UpdateManager::UpdateMobileObject(MobileObject* object)
{
    MobileObject* current = object;
    Actor* actorTmp;
    bool allowedTmp;
    ExtraFollower* otherList3;
    BSSimpleList<Actor*>* list_;
    BSSimpleList<Actor*>* listVal;
    BSSimpleList<Actor*>* otherListA;
    BSSimpleList<Actor*>* nodeVal;
    if (current && !current->IsStillLoading() && !current->GetDeleted() && !static_cast<const TESForm*>(current)->GetDisabled() &&
        static_cast<const MobileObject*>(current)->FUN_008d8520() && !current->FUN_00931850())
    {
        actorTmp = 0;
        allowedTmp = true;
        if (current && current->IsActor())
            actorTmp = reinterpret_cast<Actor*>(current);
        if (actorTmp && !actorTmp->m_bFirstActorFlag)
            return;
        if (actorTmp && ShouldUpdateActor(actorTmp))
        {
            static_cast<const MobileObject*>(actorTmp)->FUN_008d8520()->CheckForNewPackage(actorTmp, false);
            allowedTmp = false;
            ++updatedActors;
            static_cast<const MobileObject*>(actorTmp)->FUN_008d8520()->HighProcess_SetSkippedLastUpdate(true);
        }
        else
        {
            // The shared declaration of slot 0x97 lacks its float argument.
            reinterpret_cast<void (__thiscall*)(MobileObject*, float)>((*reinterpret_cast<void***>(current))[0x97])(current, 0.0f);
            ++updatedObjects;
        }
        if (actorTmp && g_thePlayer->IsSleepingOrResting())
        {
            actorTmp->RestoreHealth(2.0f);
            ApplyFatigueDamage(actorTmp, 2.0f);
        }
        if (current->FUN_00931850())
            pending = 0;
        if (allowedTmp)
        {
            otherList3 =
                current->GetExtraData() ? static_cast<FollowerExtra*>(current->GetExtraData())->ExtraDataList_GetFollowerExtra() : 0;
            if (otherList3)
            {
                listVal = new BSSimpleList<Actor*>;
                otherListA = new BSSimpleList<Actor*>;
                nodeVal = otherListA;
                list_ = otherList3->list;
                while (list_ && list_->GetItem())
                {
                    otherListA->AddTail(list_->GetItem());
                    list_ = list_->GetNext();
                }
                while (nodeVal && nodeVal->GetItem())
                {
                    Actor* actorA = nodeVal->GetItem();
                    if (actorA && actorA != g_thePlayer && !static_cast<FollowerActorMethods*>(actorA)->IsFollowerOf(actorTmp))
                        listVal->AddHead(actorA);
                    nodeVal = nodeVal->GetNext();
                }
                nodeVal = listVal;
                while (nodeVal && nodeVal->GetItem())
                {
                    Actor* targetB = nodeVal->GetItem();
                    static_cast<FollowerExtra*>(current->GetExtraData())->ExtraDataList_RemoveFollower(targetB);
                    nodeVal = nodeVal->GetNext();
                }
                listVal->RemoveAll();
                delete listVal;
                otherListA->RemoveAll();
                delete otherListA;
                if (otherList3->list->IsEmpty())
                    static_cast<FollowerExtra*>(current->GetExtraData())->ExtraDataList_RemoveFollowerExtra();
            }
        }
    }
}
}  // namespace fnv_008c8be0

namespace fnv_008ca070 {
struct IntSetting
{
    int* Setting_Int();
};
struct BoolSetting
{
    unsigned char* FUN_00408d60();
};
struct Values
{
    unsigned ProcessArray_GetProcessLevelTail();
    void* ProcessArray_GetItem();
};
struct Container
{
    Values* FUN_00717e50(unsigned);
};
struct Temp
{
    int unk00, unk04, unk08;
    Temp* MobileObjectMessage_MobileObjectMessage(unsigned);
    Temp* MobileObjectMessage_MobileObjectMessage_008c9a50(void*);
};
struct Store
{
    void PushItem(void*);
};
struct Mode
{
    void CallAt(int);
};
extern IntSetting DAT_011c3ea4;
extern BoolSetting DAT_011dfc70, DAT_011dfb88, DAT_011dfb68;
extern unsigned char DAT_011f1220;
extern Container DAT_011e0e80;
extern Store DAT_011dfb98;
extern Mode DAT_011dfc24;
struct Obj
{
    void AITaskManager_StartTasksDuringRendering();
    void ForwardToInner(Temp*);
    void CallMidVirtualB();
    void FUN_008c8240(int);
};
// @fnv 0x008ca070
// src: COMMUNITY 0x008ca070
void Obj::AITaskManager_StartTasksDuringRendering()
{
    if (*DAT_011c3ea4.Setting_Int() == 1)
    {
        if (!*DAT_011dfc70.FUN_00408d60() && !*DAT_011dfb88.FUN_00408d60())
            return;
        if (DAT_011f1220)
        {
            unsigned aVal = DAT_011e0e80.FUN_00717e50(0)->ProcessArray_GetProcessLevelTail();
            if (aVal > 0)
            {
                unsigned b_2 = DAT_011e0e80.FUN_00717e50(0)->ProcessArray_GetProcessLevelTail();
                unsigned i;
                if (*DAT_011dfc70.FUN_00408d60())
                {
                    Temp t2;
                    t2.MobileObjectMessage_MobileObjectMessage(b_2);
                    ForwardToInner(&t2);
                }
                if (*DAT_011dfb88.FUN_00408d60())
                {
                    Temp u9;
                    u9.MobileObjectMessage_MobileObjectMessage(b_2);
                    ((Obj*)((char*)this + 0x138))->ForwardToInner(&u9);
                }
                for (i = 0; i < b_2; ++i)
                {
                    if (*DAT_011dfc70.FUN_00408d60())
                    {
                        Temp v5;
                        v5.MobileObjectMessage_MobileObjectMessage_008c9a50(DAT_011e0e80.FUN_00717e50(i)->ProcessArray_GetItem());
                        ForwardToInner(&v5);
                    }
                    if (*DAT_011dfb88.FUN_00408d60())
                    {
                        Temp w2;
                        w2.MobileObjectMessage_MobileObjectMessage_008c9a50(DAT_011e0e80.FUN_00717e50(i)->ProcessArray_GetItem());
                        ((Obj*)((char*)this + 0x138))->ForwardToInner(&w2);
                    }
                }
                if (*DAT_011dfc70.FUN_00408d60())
                    CallMidVirtualB();
                if (*DAT_011dfb88.FUN_00408d60())
                    ((Obj*)((char*)this + 0x138))->CallMidVirtualB();
                if (*DAT_011dfb68.FUN_00408d60())
                {
                    if (*DAT_011dfc70.FUN_00408d60())
                        DAT_011dfb98.PushItem(this);
                    if (*DAT_011dfb88.FUN_00408d60())
                        DAT_011dfb98.PushItem((char*)this + 0x138);
                    DAT_011dfc24.CallAt(2);
                    *((bool*)this + 0x10180) = true;
                }
                else
                {
                    if (*DAT_011dfc70.FUN_00408d60())
                        FUN_008c8240(0);
                    if (*DAT_011dfb88.FUN_00408d60())
                        ((Obj*)((char*)this + 0x138))->FUN_008c8240(0);
                }
            }
        }
    }
}
}  // namespace fnv_008ca070

namespace fnv_008c9d70 {
struct FUN_008c71b0
{
    int a;
    FUN_008c71b0(int i);
    FUN_008c71b0(const FUN_008c71b0&);
};
struct MemQ;
struct FacQ
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Create(MemQ* p, const char* pName, FUN_008c71b0 k);
};
FacQ* hkMemorySystem_getInstance();
void __cdecl hkBaseSystem_initThread(MemQ* p);
struct HeapQ
{
    virtual void v0();
    virtual int Alloc(int n);
};
struct BufQ
{
    void hkStackMemory_initMemory(int p, int n);
};
struct MemQ
{
    HeapQ* TESMain_GetThread();
    void FUN_0041fd00(HeapQ* p);
    void FUN_00984f60(HeapQ* p);
    BufQ* FUN_006815c0();
};
struct GQ
{
    void FUN_00462ee0();
};
extern GQ* DAT_011c3f2c;
struct OwnQ
{
    char pad[0x50];
    MemQ kMem;
    char pad2[0x20];
    int unk74;
    void InitMemory();
};
// @fnv 0x008c9d70
void OwnQ::InitMemory()
{
    hkMemorySystem_getInstance()->Create(&kMem, "AITaskThread", FUN_008c71b0(1));
    hkBaseSystem_initThread(&kMem);
    kMem.FUN_0041fd00(kMem.TESMain_GetThread());
    kMem.FUN_00984f60(kMem.TESMain_GetThread());
    unk74 = kMem.TESMain_GetThread()->Alloc(0x16800);
    kMem.FUN_006815c0()->hkStackMemory_initMemory(unk74, 0x16800);
    DAT_011c3f2c->FUN_00462ee0();
}
}  // namespace fnv_008c9d70

struct Obj_008c9cf0
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_items[10];
    int m_uiItemCount;
    int m_next;
    void QueryPerformanceCounter(int a);
    int AITaskQueue_Dequeue();
};

// Pops the next task from a circular buffer of 10 items, wrapping the index, then calls WaitForTasksDuringRendering.
// @fnv 0x008c9cf0
// src: XBOX_PDB 0x008c9cf0
int Obj_008c9cf0::AITaskQueue_Dequeue()
{
    QueryPerformanceCounter(0);
    int result = 0;
    if (m_uiItemCount > 0)
    {
        result = m_items[m_next];
        m_uiItemCount = m_uiItemCount - 1;
        m_next = m_next + 1;
        if (m_next >= 10)
            m_next = 0;
    }
    reinterpret_cast<ActorTaskManager*>(this)->WaitForTasksDuringRendering();
    return result;
}


