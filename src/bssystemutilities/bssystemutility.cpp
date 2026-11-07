// bssystemutilities/bssystemutility.cpp: BSSystemUtility (12 functions)

#include "../../include/BSSystemUtility.h"
#include "bssystemutility_private.h"
#include "../../include/CountingSemaphore.h"
#include "../../include/MemoryManager.h"
#include <string.h>

// @fnv 0x00af3250
void BSSystemUtility::Destroy()
{
    DownloadableContentManager::GetRandomGenerator();
    Object_ClearGlobalObject();
    NetworkSystemUtility::GetRandomGenerator();
    Runtime_DoNothing();
    IdleSystem::GetRandomGenerator();
    FUN_00af2370();

    BSSysInfoSystemUtility_GetSingleton()->vfn_08();
    GetStaticSlot()->vfn_08();
    BSSaveDataSystemUtility_GetSingleton()->vfn_08();
    GetVTableSlot8()->vfn_08();
    BSGameDataSystemUtility_GetSingleton()->vfn_08();
    GetInitObj()->vfn_08();

    fnv_zlib_memset((char*)this + 4, 0, 0x80);
    *((unsigned char*)((char*)this + 0x94)) = 0;
    *((unsigned int*)((char*)this + 0x90)) = 0;
    *((unsigned int*)((char*)this + 0x84)) = 0;
    *((unsigned int*)((char*)this + 0x88)) = 0;
}

// Calls vfn_08, copies fileName (capped at 0x7f chars) into this+4, then invokes vfn_04 on several subsystems and runs further init calls.
// @fnv 0x00af3140
void BSSystemUtility::Initialize(const char* pcFilePath, const char* pcArg, unsigned int arg2)
{
    unsigned int count;
    unsigned int length;

    this->Destroy();
    if (pcFilePath != 0)
    {
        count = (unsigned int)strlen(pcFilePath);
        if (count > 0x7f)
            length = 0x7f;
        else
            length = count;
        fnv_CopyFilePath((char*)this + 4, length + 1, pcFilePath, length);
    }

    BSSysInfoSystemUtility_GetSingleton()->vfn_04();
    GetStaticSlot()->vfn_04(pcArg, arg2);
    BSSaveDataSystemUtility_GetSingleton()->vfn_04();
    GetVTableSlot8()->vfn_04();
    BSGameDataSystemUtility_GetSingleton()->vfn_04();
    GetInitObj()->vfn_04();

    IdleSystem::GetRandomGenerator();
    FUN_00af2360();
    NetworkSystemUtility::GetRandomGenerator();
    IdleSystem::Initialize();
    DownloadableContentManager::GetRandomGenerator();
    Runtime_EvaluateValue_00af2750();
}

// If the byte at offset 0x49 is set, clears the byte at 0x48 and signals the object at offset 0x30.
// @fnv 0x0078d570
void BSSystemUtility::Update()
{
    if (*((unsigned char*)((char*)this + 0x49)) != 0)
    {
        *((unsigned char*)((char*)this + 0x48)) = 0;
        ((CountingSemaphore*)((char*)this + 0x30))->Signal();
    }
}

// Calls Idle, UpdateSteamRunningFlag and FUN_00af2c80 on the three system utility singletons.
// @fnv 0x00af3340
// src: COMMUNITY 0x00af3340
void BSSystemUtility::Update_00af3340()
{
    IdleSystem::GetRandomGenerator().Idle();
    NetworkSystemUtility::GetRandomGenerator().UpdateSteamRunningFlag();
    DownloadableContentManager::GetRandomGenerator().DoNothing_00af2c80();
}

// If the new byte differs from the stored one, calls the callback at _f88 with it, then stores the byte in _f94.
// @fnv 0x00af3370
void BSSystemUtility::SetValue(unsigned char ucValue)
{
    if (ucValue != storage[0x90])
    {
        if (*reinterpret_cast<void(__cdecl**)(unsigned char)>(storage + 0x84) != 0)
        {
            (*reinterpret_cast<void(__cdecl**)(unsigned char)>(storage + 0x84))(ucValue);
        }
    }
    storage[0x90] = ucValue;
}

extern MemoryManager g_memoryManager;

// Calls FUN_00af3120, then deallocates this via g_memoryManager._DeallocateAlias when flags has bit 1 set, and returns this.
// @fnv 0x00af33c0
void* BSSystemUtility::DestroyIfFlagged(unsigned int flags)
{
    SetVirtualTable_00af3120();
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

struct FUN_00af2ed0_T : FNVVTableSlot8
{
    FUN_00af2ed0_T();
    ~FUN_00af2ed0_T();
};
// @fnv 0x00af2e50
// src: COMMUNITY 0x00af2e50
FNVVTableSlot8* BSSaveDataSystemUtility_GetSingleton()
{
    static FUN_00af2ed0_T s_instance;
    return &s_instance;
}

struct _InitObj
{
    _InitObj();
    ~_InitObj();
};

// Returns the address of the static _InitObj instance as an FNVVTableSlot8 pointer.
// @fnv 0x00af3470
FNVVTableSlot8* GetInitObj()
{
    static _InitObj s_obj;
    return (FNVVTableSlot8*)&s_obj;
}

struct FUN_00af3980 : FNVVTableSlot8
{
    FUN_00af3980();
    ~FUN_00af3980();
};

// Returns the address of a function-local static object.
// @fnv 0x00af34f0
// src: COMMUNITY 0x00af34f0
FNVVTableSlot8* BSGameDataSystemUtility_GetSingleton()
{
    static FUN_00af3980 instance;
    return &instance;
}

struct _obj_00af35e0
{
    _obj_00af35e0();
    ~_obj_00af35e0();
};

// Returns a pointer to a static _obj_00af35e0 instance cast to FNVVTableSlot8.
// @fnv 0x00af35e0
FNVVTableSlot8* GetVTableSlot8()
{
    static _obj_00af35e0 s_obj;
    return (FNVVTableSlot8*)&s_obj;
}

struct FUN_00af37d0_obj
{
    FUN_00af37d0_obj();
    ~FUN_00af37d0_obj();
};

// Returns a pointer to a static FUN_00af37d0_obj instance cast as FNVVTableSlot8Args.
// @fnv 0x00af37d0
FNVVTableSlot8Args* GetStaticSlot()
{
    static FUN_00af37d0_obj s_obj;
    return (FNVVTableSlot8Args*)&s_obj;
}

int _atexit(void(__cdecl*)());

struct FUN_00af3850_Stat
{
    FUN_00af3850_Stat();
    ~FUN_00af3850_Stat();
};

// Returns a pointer to a function-local static object cast to FNVVTableSlot8.
// @fnv 0x00af3850
// src: COMMUNITY 0x00af3850
FNVVTableSlot8* BSSysInfoSystemUtility_GetSingleton(void)
{
    static FUN_00af3850_Stat s_obj;
    return reinterpret_cast<FNVVTableSlot8*>(&s_obj);
}
