
// src/staging/blk_00c20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/BSMultiBoundNode.h"
#include "../../include/NiObject.h"
#include "../../include/MessageHandler.h"
#include "../../include/QueuedParents.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiStream.h"
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiUpdateData.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct FUN_00c3a090_Class
{
    char __thiscall BSMultiBoundRoom_IsEqual(void* arg);
    char __thiscall IsSameAs(void* arg);
};

// Calls IsSameAs with arg and returns its result unchanged.
// @fnv 0x00c3a090
// src: XBOX_PDB 0x00c3a090
char __thiscall FUN_00c3a090_Class::BSMultiBoundRoom_IsEqual(void* arg)
{
    char result = IsSameAs(arg);
    return result;
}

extern "C" void* g_01202828;

struct FUN_00c3a610_Class
{
    void* __thiscall BSMultiBoundRoom_GetRTTI();
};

// @fnv 0x00c3a610
// src: COMMUNITY 0x00c3a610
void* __thiscall FUN_00c3a610_Class::BSMultiBoundRoom_GetRTTI()
{
    return &g_01202828;
}

extern MemoryManager g_memoryManager;

struct FUN_00c3a640_Class
{
    void* AllocateStorage_00c3a640(unsigned int size);
};

// Allocates size*4 bytes through g_memoryManager and returns the resulting pointer.
// @fnv 0x00c3a640
// src: GUESS 0x00c3a640 (confidence: medium)
void* FUN_00c3a640_Class::AllocateStorage_00c3a640(unsigned int size)
{
    void* result = g_memoryManager.Allocate(size << 2);
    return result;
}

namespace fnv_00c3a670 {
extern MemoryManager g_memoryManager;

struct FUN_00c3a670_Class
{
    void* Reallocate_Thunk(void* old, unsigned int count);
};

// @fnv 0x00c3a670
// src: GUESS 0x00c3a670 (confidence: medium)
void* __thiscall FUN_00c3a670_Class::Reallocate_Thunk(void* apBlock, unsigned int count)
{
    return g_memoryManager.Reallocate(apBlock, count * 4);
}
}  // namespace fnv_00c3a670

extern "C" void* g_012043dc;

struct FUN_00c3b9e0_Class
{
    void* __thiscall GetGlobalPointer();
};

// @fnv 0x00c3b9e0
void* __thiscall FUN_00c3b9e0_Class::GetGlobalPointer()
{
    return &g_012043dc;
}

extern "C" void* g_012043e4;

struct FUN_00c3ba70_Class
{
    void* __thiscall BSNodeReferences_GetRTTI();
};

// @fnv 0x00c3ba70
// src: COMMUNITY 0x00c3ba70
void* __thiscall FUN_00c3ba70_Class::BSNodeReferences_GetRTTI()
{
    return &g_012043e4;
}

// @fnv 0x00c3c200
// src: GUESS 0x00c3c200 (confidence: low)
int __cdecl Object_ComputeValue_00c3c200()
{
    int v = 0;
    return v;
}

extern const void* DAT_010c14e8;
extern void __cdecl SetVtableAndProcessState_00c3d930();

struct FUN_00c3c520_class
{
    const void* vtbl;
    void __thiscall SetVirtualTable_00c3c520();
};

// @fnv 0x00c3c520
// src: GUESS 0x00c3c520 (confidence: low)
void __thiscall FUN_00c3c520_class::SetVirtualTable_00c3c520()
{
    vtbl = &DAT_010c14e8;
    ((void(__thiscall*)(void*))SetVtableAndProcessState_00c3d930)(this);
}

extern int DAT_010c1510;
// @fnv 0x00c3c570
// src: GUESS 0x00c3c570 (confidence: low)
void __thiscall QueuedParents::SetVtableAndProcessState_00c3c570()
{
    *reinterpret_cast<int**>(this) = &DAT_010c1510;
    SetVtableAndProcessState_00c3d930();
}

extern int DAT_010c14fc;

struct FUN_00c3d930_Class
{
    void* vftable;
    void __thiscall BSSimpleArray_NiPointer_QueuedFile_1024_Clear(int);
    void __thiscall SetVtableAndProcessState_00c3d930();
};

// Sets the vftable to DAT_010c14fc and calls FUN_00c3d980 with 1.
// @fnv 0x00c3d930
// src: GUESS 0x00c3d930 (confidence: low)
void __thiscall FUN_00c3d930_Class::SetVtableAndProcessState_00c3d930()
{
    char buf[0x18];
    vftable = &DAT_010c14fc;
    BSSimpleArray_NiPointer_QueuedFile_1024_Clear(1);
}

struct FUN_00c3f6f0_Class
{
    void LockFreeMap_int64_NiPointer_BSTask_int64_IncrementCount();
};

// @fnv 0x00c3f6f0
// src: COMMUNITY 0x00c3f6f0
void FUN_00c3f6f0_Class::LockFreeMap_int64_NiPointer_BSTask_int64_IncrementCount()
{
    InterlockedIncrement((volatile long*)((char*)this + 0x18));
}

struct FUN_00c3f710_Class
{
    void IncrementRefCount();
};

// @fnv 0x00c3f710
void FUN_00c3f710_Class::IncrementRefCount()
{
    InterlockedIncrement((volatile long*)((char*)this + 0xc));
}

struct FUN_00c3f730_Class
{
    void __thiscall DecrementRefCount();
};

// @fnv 0x00c3f730
void __thiscall FUN_00c3f730_Class::DecrementRefCount()
{
    InterlockedDecrement((volatile long*)(this + 0xc));
}

struct FUN_00c3fc80_class
{
    void __thiscall CallSecondVirtualMethod(void* p);
};

// @fnv 0x00c3fc80
void __thiscall FUN_00c3fc80_class::CallSecondVirtualMethod(void* apObject)
{
    ((void(__thiscall*)(void*))(*reinterpret_cast<void***>(apObject))[1])(apObject);
}

struct FUN_00c35980_Class
{
    int BSOcclusionPlane_GetJoinedPlaneType();
};

// Returns 2 if the fields at offsets 0xec or 0xf4 are set, 1 if 0xf0 or 0xf8 are set, otherwise 0.
// @fnv 0x00c35980
// src: COMMUNITY 0x00c35980
int FUN_00c35980_Class::BSOcclusionPlane_GetJoinedPlaneType()
{
    if (*(int*)((char*)this + 0xec) || *(int*)((char*)this + 0xf4))
        return 2;
    if (*(int*)((char*)this + 0xf0) || *(int*)((char*)this + 0xf8))
        return 1;
    return 0;
}

struct FUN_00c3a080_Class
{
    void* __thiscall BSMultiBoundRoom_CreateClone(int arg);
};

// @fnv 0x00c3a080
// src: COMMUNITY 0x00c3a080
void* FUN_00c3a080_Class::BSMultiBoundRoom_CreateClone(int arg)
{
    return 0;
}

void* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);
struct FUN_00c3a0c0_Class
{
    void* __thiscall BSMultiBoundNode_GetViewerStrings(unsigned int a);
    void __thiscall AddFirstEmptyFromGlobal(unsigned int a);
};
// @fnv 0x00c3a0c0
void __thiscall FUN_00c3a0c0_Class::AddFirstEmptyFromGlobal(unsigned int pArray)
{
    struct
    {
        void* p;
        unsigned int u;
    } locals;
    char pad[12];
    BSMultiBoundNode_GetViewerStrings(pArray);
    locals.p = g_01202828;
    locals.u = (unsigned int)NiViewerStrings_NiGetViewerString_Title(locals.p);
    ((NiTPrimitiveArray<unsigned int>*)pArray)->AddFirstEmpty(locals.u);
}

struct FUN_00c3a100_Class
{
    void __thiscall BSMultiBoundRoom_LinkObject(int);
};
// @fnv 0x00c3a100
// src: COMMUNITY 0x00c3a100
void __thiscall FUN_00c3a100_Class::BSMultiBoundRoom_LinkObject(int)
{}

struct FUN_00c3a110_Class
{
    void __thiscall BSMultiBoundRoom_LoadBinary(int arg);
};

// @fnv 0x00c3a110
// src: COMMUNITY 0x00c3a110
void FUN_00c3a110_Class::BSMultiBoundRoom_LoadBinary(int arg)
{}

struct FUN_00c3a120_Class
{
    void __thiscall BSMultiBoundRoom_SaveBinary(int);
};

// @fnv 0x00c3a120
// src: COMMUNITY 0x00c3a120
void __thiscall FUN_00c3a120_Class::BSMultiBoundRoom_SaveBinary(int)
{}

struct FUN_00c3a130_Class
{
    char __thiscall BSMultiBoundRoom_RegisterStreamables(void* arg);
};

// @fnv 0x00c3a130
// src: COMMUNITY 0x00c3a130
char __thiscall FUN_00c3a130_Class::BSMultiBoundRoom_RegisterStreamables(void* arg)
{
    return 1;
}

extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00c3a140_Class
{
    void __thiscall FUN_00c39770();
    void* __thiscall FUN_00c3a140(unsigned int flags);
};
// Calls FUN_00c39770, then deletes this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c3a140
void* FUN_00c3a140_Class::FUN_00c3a140(unsigned int flags)
{
    FUN_00c39770();
    if (flags & 1)
        operator delete(this, 0xec);
    return this;
}

// Calls UpdateDownwardPass with data and flags, then invokes the object's virtual method at vtable slot 47 on this.
// @fnv 0x00c3a5b0
// src: XBOX_PDB 0x00c3a5b0
void __thiscall BSMultiBoundNode::UpdateDownwardPass_00c3a5b0(NiUpdateData& aUpdateData, unsigned int flags)
{
    NiNode::UpdateDownwardPass(aUpdateData, flags);
    UpdateWorldBound();
}

struct FUN_00c3a620_Class
{
    void __thiscall SetVirtualTableAndProcessState_00c3a620();
};
struct FUN_00c3a6a0_Class
{
    void* __thiscall FUN_00c3a6a0(unsigned int flags);
};
// @fnv 0x00c3a6a0
void* __thiscall FUN_00c3a6a0_Class::FUN_00c3a6a0(unsigned int flags)
{
    ((FUN_00c3a620_Class*)this)->SetVirtualTableAndProcessState_00c3a620();
    if (flags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}

extern char DAT_01202c50[260];
extern char DAT_01202fa0[];
// @fnv 0x00c3bb90
// src: COMMUNITY 0x00c3bb90
void MessageHandler_SetAllWarningFileNames(const char* src)
{
    strcpy_s(DAT_01202c50, 260, DAT_01202fa0);
    strcat_s(DAT_01202c50, 260, src);
}

namespace fnv_00c3bbe0 {
extern char DAT_01202b48[260];
extern char DAT_01202fa0;
char* __cdecl _strcpy_s(char* dest, unsigned int size, const char* src);
char* __cdecl _strcat_s(char* dest, unsigned int size, const char* src);
// @fnv 0x00c3bbe0
// src: COMMUNITY 0x00c3bbe0
void __cdecl MessageHandler_SetProgramFlowFileName(const char* pcSuffix)
{
    _strcpy_s(DAT_01202b48, 260, &DAT_01202fa0);
    _strcat_s(DAT_01202b48, 260, pcSuffix);
}
}  // namespace fnv_00c3bbe0

extern char DAT_01202a40[0x104];
extern char DAT_01202fa0[0x104];
// Copies DAT_01202fa0 into DAT_01202a40, then appends p to it.
// @fnv 0x00c3bc30
// src: COMMUNITY 0x00c3bc30
void __cdecl MessageHandler_SetProgrammerOutputFileName(const char* pcSuffix)
{
    strcpy_s(DAT_01202a40, 0x104, DAT_01202fa0);
    strcat_s(DAT_01202a40, 0x104, pcSuffix);
}

namespace fnv_00c3bc80 {
extern char DAT_01202938[256];
extern char DAT_01202fa0[256];
void __cdecl _strcpy_s(char* dst, unsigned int, const char* src);
void __cdecl _strcat_s(char* dst, unsigned int, const char* src);
// Copies DAT_01202fa0 into DAT_01202938, then appends src to that buffer.
// @fnv 0x00c3bc80
// src: COMMUNITY 0x00c3bc80
void __cdecl MessageHandler_SetCrashTraceFileName(const char* pcSuffix)
{
    _strcpy_s(DAT_01202938, 0x104, DAT_01202fa0);
    _strcat_s(DAT_01202938, 0x104, pcSuffix);
}
}  // namespace fnv_00c3bc80

extern const void* DAT_010c14a8;
MessageHandler* MessageHandler::pHandler;
// Calls FUN_00aa4c60, sets the vtable to DAT_010c14a8, stores b in bStatic, sets MessageHandler::pHandler to this and returns this.
// @fnv 0x00c3bcf0
// src: EXE 0x00c3bcf0
MessageHandler* __thiscall MessageHandler::MessageHandler_00c3bcf0(bool abStatic)
{
    BSCoreMessage_BSCoreMessage();
    *(const void**)this = &DAT_010c14a8;
    bStatic = abStatic;
    MessageHandler::pHandler = this;
    return this;
}

struct FUN_00c3c070_Class
{
    void* __thiscall std__Ref_count_base__Get_deleter(int arg);
};

// @fnv 0x00c3c070
// src: COMMUNITY 0x00c3c070
void* __thiscall FUN_00c3c070_Class::std__Ref_count_base__Get_deleter(int arg)
{
    return 0;
}

extern "C" unsigned char DAT_011af49c;

// @fnv 0x00c3c0c0
// src: GUESS 0x00c3c0c0 (confidence: low)
void __cdecl Object_ProcessEntries_00c3c0c0()
{
    for (int i = 0; i < 0x18; ++i)
        ((unsigned char*)0x11f6370)[i] = 0;
    DAT_011af49c = 0;
}

namespace fnv_00c3d380 {
struct FUN_00c3d380_Class : public FUN_00c3c520_class
{
    void* __thiscall FUN_00c3d380(unsigned int flags);
};
// @fnv 0x00c3d380
void* __thiscall FUN_00c3d380_Class::FUN_00c3d380(unsigned int flags)
{
    SetVirtualTable_00c3c520();
    if (flags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}
}  // namespace fnv_00c3d380

namespace fnv_00c3d410 {
struct _Base_00441d20
{
    ~_Base_00441d20();
};
struct FUN_00c3d410_Class : _Base_00441d20
{
    void* __thiscall DestroySelf(unsigned int flags);
};
// Runs the base destructor, frees this via the memory manager when flags has bit 0 set, and returns this.
// @fnv 0x00c3d410
void* __thiscall FUN_00c3d410_Class::DestroySelf(unsigned int flags)
{
    _Base_00441d20::~_Base_00441d20();
    if (flags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}
}  // namespace fnv_00c3d410

namespace fnv_00c3d950 {
struct FUN_00c3d950_Class
{
    void* __thiscall FUN_00c3d950(unsigned int flags);
};
// @fnv 0x00c3d950
void* __thiscall FUN_00c3d950_Class::FUN_00c3d950(unsigned int flags)
{
    ((FUN_00c3d930_Class*)this)->SetVtableAndProcessState_00c3d930();
    if (flags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}
}  // namespace fnv_00c3d950

struct FUN_00c3fca0_Class
{
    void __thiscall BSTaskManager_int64_RemoveTask(void* a);
    void __thiscall ProcessStateTransitionFourToFive_00c3fca0(void* p);
};
// Sets the field at offset 0xc to 4, calls the object's virtual method at vtable index 2, then sets the field to 5 and calls FUN_0044e050.
// @fnv 0x00c3fca0
// src: GUESS 0x00c3fca0 (confidence: low)
void __thiscall FUN_00c3fca0_Class::ProcessStateTransitionFourToFive_00c3fca0(void* apObject)
{
    *(int*)((char*)apObject + 0xc) = 4;
    ((void(__thiscall*)(void*))(*(void***)apObject)[2])(apObject);
    *(int*)((char*)apObject + 0xc) = 5;
    BSTaskManager_int64_RemoveTask(apObject);
}

struct FUN_00c3fe00_Class
{
    void* __thiscall LockFreeMapInterface_LockFreeMapInterface(int a, int b, int c, int d);
};
// Stores the four arguments into the first four fields and zeroes the fields at offsets 0x10 through 0x20, returning this.
// @fnv 0x00c3fe00
// src: COMMUNITY 0x00c3fe00
void* __thiscall FUN_00c3fe00_Class::LockFreeMapInterface_LockFreeMapInterface(int aiField0, int aiField1, int aiField2, int aiField3)
{
    int* p4 = (int*)((char*)this + 0x14);
    *p4 = 0;
    int* p2 = (int*)((char*)this + 0x18);
    *p2 = 0;
    *(int*)this = aiField0;
    *(int*)((char*)this + 4) = aiField1;
    *(int*)((char*)this + 8) = aiField2;
    *(int*)((char*)this + 0xc) = aiField3;
    *(int*)((char*)this + 0x10) = 0;
    *(int*)((char*)this + 0x1c) = 0;
    *(int*)((char*)this + 0x20) = 0;
    return this;
}

void __fastcall BSTask_int64_DecRefCount(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct FUN_00c416a0_Class
{
    bool __thiscall LockFreeMapInterface_Find_0(int a, int b, int c);
};
struct FUN_00c3fe80_Class : FUN_00c416a0_Class
{
    bool __thiscall LockFreeMapInterface_GetAt(int a, int b, int c, void** out);
};
// @fnv 0x00c3fe80
// src: COMMUNITY 0x00c3fe80
bool FUN_00c3fe80_Class::LockFreeMapInterface_GetAt(int aiArg1, int aiArg2, int aiArg3, void** ppOut)
{
    bool result = LockFreeMapInterface_Find_0(aiArg1, aiArg2, aiArg3);
    if (result)
    {
        int padA;
        {
            int padA2[40];
            {
                int padA3;
                {
                    unsigned int* field = (unsigned int*)((char*)this + 0x14);
                    {
                        int padB[3];
                        {
                            char* obj;
                            {
                                void** src = (void**)((*field & ~1u) + 8);
                                if (*ppOut != *src)
                                {
                                    if (*ppOut)
                                        BSTask_int64_DecRefCount(*ppOut);
                                    *ppOut = *src;
                                    if (*ppOut)
                                    {
                                        obj = (char*)*ppOut;
                                        InterlockedIncrement((long volatile*)(obj + 8));
                                    }
                                }
                                {
                                    unsigned int* field2 = (unsigned int*)((char*)this + 0x14);
                                    {
                                        unsigned int node = *field2 & ~1u;
                                        {
                                            unsigned int* flags = (unsigned int*)(node + 0xc);
                                            if ((*flags & 1) ? true : false)
                                                result = false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    **(int**)((char*)this + 4) = 0;
    **(int**)((char*)this + 8) = 0;
    **(int**)((char*)this + 0xc) = 0;
    return result;
}

// @fnv 0x00c33090
// src: XBOX_PDB 0x00c33090
int __cdecl Setting_DataType_00c33090(const char* p)
{
    int result = 9;
    if (p)
    {
        switch (*p)
        {
        case 'b':
            result = 0;
            break;
        case 'c':
            result = 1;
            break;
        case 'f':
            result = 5;
            break;
        case 'h':
            result = 2;
            break;
        case 'i':
            result = 3;
            break;
        case 'u':
            result = 4;
            break;
        case 'S':
        case 's':
            result = 6;
            break;
        case 'r':
            result = 7;
            break;
        case 'a':
            result = 8;
            break;
        }
    }
    return result;
}

typedef void*(__cdecl* PFN_00c3c100)(void*, void*, unsigned int);
extern PFN_00c3c100 DAT_01202d5c;
extern int DAT_01202d70;
void __cdecl MessageHandler_InstallMessageBoxHook();
void __cdecl MessageHandler_RemoveMessageBoxHook();
// @fnv 0x00c3c100
// src: COMMUNITY 0x00c3c100
void* __cdecl MessageHandler_DoMessageBox(void* a, void* b, unsigned int auiFlags)
{
    void* r = 0;
    if (DAT_01202d5c)
    {
        bool bAdjusted = false;
        if (auiFlags & 3)
        {
            MessageHandler_InstallMessageBoxHook();
            if (DAT_01202d70)
            {
                auiFlags &= 0xffffefff;
                auiFlags |= 0x2000;
                bAdjusted = true;
            }
        }
        r = DAT_01202d5c(a, b, auiFlags);
        if (bAdjusted)
            MessageHandler_RemoveMessageBoxHook();
    }
    return r;
}

struct FUN_00c465a0;
struct FUN_00c4fb10_shell;
struct FUN_00c61b10;

typedef NiObject*(__cdecl* PFN_NiObjectLoader)(void);


NiObject* __cdecl BSReference_CreateObject();
NiObject* __cdecl BSNodeReferences_CreateObject();
NiObject* __cdecl NiBSBoneLODController_CreateObject();
NiObject* __cdecl BSBound_CreateObject();
NiObject* __cdecl BSXFlags_CreateObject();
NiObject* __cdecl CreateNamedNode();
FUN_00c465a0* __cdecl BSWindModifier_CreateObject();
NiObject* __cdecl CreatePositionModifierObject();
NiObject* __cdecl BSFurnitureMarker_CreateObject();
FUN_00c61b10* __cdecl BSPSysArrayEmitter_CreateObject();
NiObject* __cdecl BSWArray_CreateObject();
NiObject* __cdecl BSDamageStage_CreateObject();
NiObject* __cdecl BSBlastNode_CreateObject();
NiObject* __cdecl BSValueNode_CreateObject();
NiObject* __cdecl BSPSysMultiTargetEmitterCtlr_CreateObject();
NiObject* __cdecl BSMasterParticleSystem_CreateObject();
NiObject* __cdecl BSMultiBound_CreateObject();
NiObject* __cdecl CreateNewObject();
NiObject* __cdecl CreateNewBodyCls();
NiObject* __cdecl CreateBC36500Object();
NiObject* __cdecl BSMultiBoundCapsule_CreateObject();
FUN_00c4fb10_shell* __cdecl BSMultiBoundSphere_CreateObject();
NiObject* __cdecl BSPSysSimpleColorModifier_CreateObject();
NiObject* __cdecl BSDebrisNode_CreateObject();
NiObject* __cdecl CreatePositionModifierInstance();

extern char const g_012043dc_arg0[];
extern char const g_012043e4_arg0[];
extern char const g_012031b8_arg0[];
extern char const g_012031e8_arg0[];
extern char const g_01202de0_arg0[];
extern char const g_012043d4_arg0[];
extern char const g_01202e60_arg0[];
extern char const g_012043c8_arg0[];
extern char const g_012031c4_arg0[];
extern char const g_012043b0_arg0[];
extern char const g_012043a4_arg0[];
extern char const g_01202e8c_arg0[];
extern char const g_01202e7c_arg0[];
extern char const g_01202de8_arg0[];
extern char const g_01203340_arg0[];
extern char const g_0120436c_arg0[];
extern char const g_01202810_arg0[];
extern char const g_01202e74_arg0[];
extern char const g_01202820_arg0[];
extern char const g_01202818_arg0[];
extern char const g_01204398_arg0[];
extern char const g_01203108_arg0[];
extern char const g_01204390_arg0[];
extern char const g_01202e84_arg0[];
extern char const g_01204388_arg0[];

// @fnv 0x00c3a6d0
// src: COMMUNITY 0x00c3a6d0
void BSStream_InitLoaders()
{
    NiStream::RegisterObjectLoader(g_012043dc_arg0, BSReference_CreateObject);
    NiStream::RegisterObjectLoader(g_012043e4_arg0, BSNodeReferences_CreateObject);
    NiStream::RegisterObjectLoader(g_012031b8_arg0, NiBSBoneLODController_CreateObject);
    NiStream::RegisterObjectLoader(g_012031e8_arg0, BSBound_CreateObject);
    NiStream::RegisterObjectLoader(g_01202de0_arg0, BSXFlags_CreateObject);
    NiStream::RegisterObjectLoader(g_012043d4_arg0, CreateNamedNode);
    NiStream::RegisterObjectLoader(g_01202e60_arg0, reinterpret_cast<PFN_NiObjectLoader>(BSWindModifier_CreateObject));
    NiStream::RegisterObjectLoader(g_012043c8_arg0, CreatePositionModifierObject);
    NiStream::RegisterObjectLoader(g_012031c4_arg0, BSFurnitureMarker_CreateObject);
    NiStream::RegisterObjectLoader(g_012043b0_arg0, reinterpret_cast<PFN_NiObjectLoader>(BSPSysArrayEmitter_CreateObject));
    NiStream::RegisterObjectLoader(g_012043a4_arg0, BSWArray_CreateObject);
    NiStream::RegisterObjectLoader(g_01202e8c_arg0, BSDamageStage_CreateObject);
    NiStream::RegisterObjectLoader(g_01202e7c_arg0, BSBlastNode_CreateObject);
    NiStream::RegisterObjectLoader(g_01202de8_arg0, BSValueNode_CreateObject);
    NiStream::RegisterObjectLoader(g_01203340_arg0, BSPSysMultiTargetEmitterCtlr_CreateObject);
    NiStream::RegisterObjectLoader(g_0120436c_arg0, BSMasterParticleSystem_CreateObject);
    NiStream::RegisterObjectLoader(g_01202810_arg0, BSMultiBound_CreateObject);
    NiStream::RegisterObjectLoader(g_01202e74_arg0, CreateNewObject);
    NiStream::RegisterObjectLoader(g_01202820_arg0, CreateNewBodyCls);
    NiStream::RegisterObjectLoader(g_01202818_arg0, CreateBC36500Object);
    NiStream::RegisterObjectLoader(g_01204398_arg0, BSMultiBoundCapsule_CreateObject);
    NiStream::RegisterObjectLoader(g_01203108_arg0, reinterpret_cast<PFN_NiObjectLoader>(BSMultiBoundSphere_CreateObject));
    NiStream::RegisterObjectLoader(g_01204390_arg0, BSPSysSimpleColorModifier_CreateObject);
    NiStream::RegisterObjectLoader(g_01202e84_arg0, BSDebrisNode_CreateObject);
    NiStream::RegisterObjectLoader(g_01204388_arg0, CreatePositionModifierInstance);
}

extern "C" void __cdecl operator delete(void*, unsigned int);

struct FUN_00c3ba80_Class
{
    void __thiscall FUN_00c3bab0();
    void* __thiscall FUN_00c3ba80(unsigned int flags);
    int a, b, c, d;
};

// Calls FUN_00c3bab0, then deletes this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c3ba80
void* __thiscall FUN_00c3ba80_Class::FUN_00c3ba80(unsigned int flags)
{
    int x, y, z;
    FUN_00c3bab0();
    if (flags & 1)
        operator delete(this, 0x18);
    return this;
}

extern "C" unsigned char DAT_01202d55;
void* __cdecl MessageHandler_DoMessageBox(void*, void*, unsigned int);

// Sets DAT_01202d55 to 1, calls FUN_00c3c100 with a, "Confirm" and 0x2034, then resets DAT_01202d55 to 0 and returns the result.
// @fnv 0x00c3c180
// src: COMMUNITY 0x00c3c180
void* __cdecl MessageHandler_MenuMessageBoxYesNo(void* a)
{
    void* result;
    DAT_01202d55 = 1;
    result = MessageHandler_DoMessageBox(a, "Confirm", 0x2034);
    DAT_01202d55 = 0;
    return result;
}

extern unsigned char DAT_01202d55;

// Sets DAT_01202d55 to 1, calls FUN_00c3c100 with a, "Confirm" and 0x2033, then resets DAT_01202d55 to 0 and returns the result.
// @fnv 0x00c3c1c0
// src: COMMUNITY 0x00c3c1c0
void* __cdecl MessageHandler_MenuMessageBoxYesNoAll(void* a)
{
    DAT_01202d55 = 1;
    void* result = MessageHandler_DoMessageBox(a, "Confirm", 0x2033);
    DAT_01202d55 = 0;
    return result;
}

// @fnv 0x00c3c430
void* MessageHandler::DestroyAndFree(unsigned int flags)
{
    this->MessageHandler::~MessageHandler();
    if (flags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}

extern MemoryManager g_memoryManager;
// Calls FUN_00c3c570, then deallocates this via g_memoryManager when flags has bit 0 set, and returns this.
// @fnv 0x00c3d3b0
void* QueuedParents::FUN_00c3d3b0(unsigned int flags)
{
    SetVtableAndProcessState_00c3c570();
    if (flags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}

struct FUN_00c42f00_Class
{
    void __thiscall DestroyResources();
    void* __thiscall FUN_00c3f130(unsigned int flags);
};
// @fnv 0x00c3f130
void* __thiscall FUN_00c42f00_Class::FUN_00c3f130(unsigned int flags)
{
    this->DestroyResources();
    if (flags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}

int __cdecl FUN_00ec6130(int value);

struct FUN_00c32fb0_cls
{
    int m_00;
    int m_04;
    const char* m_08;
    int GetFormatSize();
};

// Returns a size based on the first character of m_08: 1 for b/c/h, 4 for a/f/i/r/u, and for S/s the result of FUN_00ec6130 on m_04 plus 1, else 0.
// @fnv 0x00c32fb0
int FUN_00c32fb0_cls::GetFormatSize()
{
    int result = 0;
    if (m_08 != 0)
    {
        switch (*m_08)
        {
        case 'b':
        case 'c':
        case 'h':
            result = 1;
            break;
        case 'a':
        case 'f':
        case 'i':
        case 'r':
        case 'u':
            result = 4;
            break;
        case 'S':
        case 's':
            if ((this != 0 ? this->m_04 : 0) != 0)
            {
                result = FUN_00ec6130(this != 0 ? this->m_04 : 0) + 1;
            }
            break;
        default:
            break;
        }
    }
    return result;
}

struct StateVec3
{
    unsigned int x, y, z;
};
struct StateVec2
{
    unsigned int x, y;
};
struct StateMatrix3
{
    unsigned int entries[9];
};

struct FUN_00c337c0_State
{
    unsigned int unk00;
    unsigned int unk04;
    StateVec3 primary;
    StateVec2 secondary;
    StateMatrix3 transform;
    unsigned int scalar;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned char dirtyE4;
    unsigned char dirtyE5;

    void CopyStateTo(FUN_00c337c0_State* destination, unsigned int unused);
};

// @fnv 0x00c337c0
void FUN_00c337c0_State::CopyStateTo(FUN_00c337c0_State* destination, unsigned int unused)
{
    destination->primary = primary;
    destination->dirtyE4 = 1;
    destination->dirtyE5 = 1;

    destination->secondary = secondary;
    destination->dirtyE4 = 1;
    destination->dirtyE5 = 1;

    destination->transform = transform;
    destination->dirtyE4 = 1;
    destination->dirtyE5 = 1;

    unsigned int value = scalar;
    destination->scalar = value;
}

struct FUN_00c347d0_Elem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_00c347d0_Slot
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    int Probe(FUN_00c347d0_Elem* e);
};

struct FUN_00c347d0_Scratch
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
};

struct FUN_00c347d0_Obj
{
    FUN_00c347d0_Slot m_slot[6];
    unsigned int m_uiMask;
};

struct FUN_00c347d0_cls
{
    void Init(FUN_00c347d0_Elem* res);
    bool BSOcclusionPlane_CompletelyWithinFrustum(FUN_00c347d0_Obj* obj);
};

// @fnv 0x00c347d0
// src: COMMUNITY 0x00c347d0
bool FUN_00c347d0_cls::BSOcclusionPlane_CompletelyWithinFrustum(FUN_00c347d0_Obj* obj)
{
    FUN_00c347d0_Scratch b1;
    FUN_00c347d0_Elem res[4];
    int tt = 4;
    FUN_00c347d0_Elem* g1 = res;
    while (--tt >= 0)
    {
        g1 = (FUN_00c347d0_Elem*)((char*)g1 + 12);
    }
    int lst;
    int val;
    Init(res);
    for (lst = 0; lst < 6; lst++)
    {
        if ((bool)((1u << lst) & obj->m_uiMask))
        {
            for (val = 0; val < 4; val++)
            {
                if (obj->m_slot[lst].Probe(&res[val]) == 2)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

class Node
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};

class Sub08
{
  public:
    unsigned int unk00;
    Node* Acquire();
};

class Mid
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    Sub08 m_08;
    void Consume(Node* n);
};

class Scratch18
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
};

class FUN_00c39a80_cls
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74,
        unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4,
        unkb8, unkbc;
    Mid m_c0;
    void BSMultiBoundRoom_AddOccluder(unsigned int a1);
};

// If a1 is nonzero, acquires a Node from m_c0's Sub08, stores a1 in its m_08, and passes it to m_c0.Consume.
// @fnv 0x00c39a80
// src: XBOX_PDB 0x00c39a80
void FUN_00c39a80_cls::BSMultiBoundRoom_AddOccluder(unsigned int auiValue)
{
    Scratch18 scratch;
    Node* n;
    if (auiValue != 0)
    {
        Mid* mid = &m_c0;
        n = mid->m_08.Acquire();
        n->m_08 = auiValue;
        mid->Consume(n);
    }
}

extern "C" int DAT_010c117c;

struct FUN_00c3a220_cls
{
    void* m_vptr;

    void InitBuffer(int a, int b);
    FUN_00c3a220_cls* SetVirtualTable_00c3a220();
};

// Sets the vtable pointer to DAT_010c117c, calls InitBuffer with 0 and 0, and returns this.
// @fnv 0x00c3a220
// src: GUESS 0x00c3a220 (confidence: low)
FUN_00c3a220_cls* FUN_00c3a220_cls::SetVirtualTable_00c3a220()
{
    int unk04;
    int unk08;
    m_vptr = (void*)&DAT_010c117c;
    InitBuffer(0, 0);
    return this;
}

struct FUN_00c3a350_cls
{
    void** m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReserved;

    virtual void v0();
    virtual void* Alloc(unsigned int n);

    void InitBuffer(unsigned int a, unsigned int b);
};

// @fnv 0x00c3a350
void FUN_00c3a350_cls::InitBuffer(unsigned int auiCapacity, unsigned int auiCount)
{
    m_pBuffer = 0;
    m_uiLogicalSize = 0;
    m_iReserved = 0;
    if (auiCount > auiCapacity)
    {
        auiCapacity = auiCount;
    }
    if (auiCapacity > 0)
    {
        m_pBuffer = (void**)Alloc(auiCapacity);
        m_iReserved = auiCapacity;
    }
    if (auiCount > 0)
    {
        for (unsigned int i = 0; i < auiCount; i++)
        {
            void*& r = m_pBuffer[i];
        }
        m_uiLogicalSize = auiCount;
    }
}

struct FUN_00c3a4b0_node
{
    FUN_00c3a4b0_node* m_00;
    void* m_04;
    unsigned int m_08;
};

struct FUN_00c3a4b0_sub
{
    unsigned int m_uiItemCount;
    void __thiscall NiTPointerAllocator_unsigned_int_Deallocate(FUN_00c3a4b0_node* p);
};

struct FUN_00c3a4b0_cls
{
    FUN_00c3a4b0_node* m_00;
    void* m_04;
    FUN_00c3a4b0_sub m_08;
    unsigned int __thiscall UpdateState_00c3a4b0();
};

// @fnv 0x00c3a4b0
// src: GUESS 0x00c3a4b0 (confidence: low)
unsigned int FUN_00c3a4b0_cls::UpdateState_00c3a4b0()
{
    FUN_00c3a4b0_node unusedNode;
    FUN_00c3a4b0_node* pRemoved = this->m_00;
    this->m_00 = this->m_00->m_00;
    if (this->m_00 != 0)
    {
        this->m_00->m_04 = 0;
    }
    else
    {
        this->m_04 = 0;
    }
    unsigned int uiValue = pRemoved->m_08;
    pRemoved->m_08 = 0;
    this->m_08.NiTPointerAllocator_unsigned_int_Deallocate(pRemoved);
    this->m_08.m_uiItemCount = this->m_08.m_uiItemCount - 1;
    return uiValue;
}

struct FUN_00c3a530_node
{
    FUN_00c3a530_node* m_00;
    FUN_00c3a530_node* m_04;
    void* m_08;
};

struct FUN_00c3a530_alloc
{
    unsigned int m_uiCount;
    void FreeNode(FUN_00c3a530_node* node);
};

struct FUN_00c3a530_cls
{
    FUN_00c3a530_node* m_00;
    FUN_00c3a530_node* m_04;
    FUN_00c3a530_alloc m_08;
    void* UpdateState_00c3a530();
};

struct FUN_00c3a530_pad
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

// Removes the head node from a linked list, clears its payload pointer, frees the node, decrements the count and returns the payload.
// @fnv 0x00c3a530
// src: GUESS 0x00c3a530 (confidence: low)
void* FUN_00c3a530_cls::UpdateState_00c3a530()
{
    FUN_00c3a530_pad pad;
    FUN_00c3a530_node* pNode = m_04;
    void* p;
    m_04 = m_04->m_04;
    if (m_04 != 0)
    {
        m_04->m_00 = 0;
    }
    else
    {
        m_00 = 0;
    }
    p = pNode->m_08;
    pNode->m_08 = 0;
    m_08.FreeNode(pNode);
    m_08.m_uiCount -= 1;
    return p;
}

// Calls the base upward pass, then updates the world bound through the shared virtual declaration.
// @fnv 0x00c3a5e0
void BSMultiBoundNode::UpdateUpwardPass()
{
    NiNode::UpdateUpwardPass();
    UpdateWorldBound();
}

namespace fnv_00c3a620 {
extern "C" void* DAT_010c117c;

class SpawnedBase
{
  public:
    void UpdateFields_00b5af80(unsigned int flags);
    int m_vptr;
    int unk04;
};

class FUN_00c3a620_cls : public SpawnedBase
{
  public:
    void SetVirtualTableAndProcessState_00c3a620();
};

// Sets the object's vtable pointer to DAT_010c117c and calls SpawnedBase::FUN_00b5af80 with flags 1.
// @fnv 0x00c3a620
// src: GUESS 0x00c3a620 (confidence: low)
void FUN_00c3a620_cls::SetVirtualTableAndProcessState_00c3a620()
{
    int unk00;
    this->m_vptr = (int)&DAT_010c117c;
    this->SpawnedBase::UpdateFields_00b5af80(1);
}
}  // namespace fnv_00c3a620

extern "C" unsigned int __cdecl strlen(const char*);

extern "C" __declspec(dllimport) unsigned long __stdcall GetPrivateProfileStringA(
    const char* lpAppName, const char* lpKeyName, const char* lpDefault, char* lpReturnedString, unsigned long nSize,
    const char* lpFileName);



PFN_NiObjectLoader __cdecl BSStream_GetCreatorFunction(const char* name);

static const char kLoadersSection[] = "Loaders";
static const char kNoDefault[] = "";
static const char kBackslash[] = "\\";
static const char kIniName[] = "Loaders.ini";
static const char kSpace[] = " ";

// Reads the Loaders section of Loaders.ini next to dir, resolves each key's value to a loader and registers it with NiStream under the key name.
// @fnv 0x00c3b3f0
void __cdecl LoadObjectLoadersFromIni(const char* dir)
{
    char pathX[260];
    unsigned int len4;
    char _keys[0x1000];
    char* key;
    unsigned int nVal;
    char value2[128];
    PFN_NiObjectLoader loader;
    char* copy3;

    strcpy_s(pathX, 260, dir);
    len4 = strlen(pathX);
    if (len4 < 4 || pathX[len4 - 4] != '.')
    {
        if (pathX[len4 - 1] != '\\')
            strcat_s(pathX, 260, kBackslash);
        strcat_s(pathX, 260, kIniName);
    }
    len4 = GetPrivateProfileStringA(kLoadersSection, 0, kSpace, _keys, 0x400, pathX);
    copy3 = 0;
    if (len4 != 0)
    {
        key = _keys;
        while (*key)
        {
            nVal = GetPrivateProfileStringA("Loaders", key, kNoDefault, value2, 128, pathX);
            if (nVal != 0)
            {
                loader = BSStream_GetCreatorFunction(value2);
                if (loader != 0)
                {
                    nVal = strlen(key);
                    {
                        char* tmp = (char*)g_memoryManager.Allocate(nVal + 1);
                        copy3 = tmp;
                    }
                    strcpy_s(copy3, nVal + 1, key);
                    NiStream::RegisterObjectLoader(copy3, loader);
                }
            }
            key += strlen(key) + 1;
        }
    }
}

extern "C" int __cdecl _strnicmp(const char* a, const char* b, unsigned int n);

// Copies path into a buffer, splits off extension and trailing underscore suffix, and writes a DATA\-prefixed or plain path plus suffix and extension to out.
// @fnv 0x00c3b7e0
void __cdecl BuildDataPath(char* outPath, const char* srcPath, const char* suffix)
{
    char buf[260];
    char ext3[10];
    char* dot3;
    char* underscore7;
    char* name;
    char* slash3;

    strcpy_s(buf, 260, srcPath);
    *outPath = 0;
    name = buf;
    dot3 = strrchr(name, '.');
    slash3 = strrchr(name, '\\');
    underscore7 = strrchr(name, '_');
    if (slash3 && underscore7 && underscore7 < slash3)
        underscore7 = 0;
    if (dot3)
    {
        strcpy_s(ext3, 10, dot3);
        if (underscore7)
            *underscore7 = 0;
        *dot3 = 0;
        if (*name != '\\' && name[1] != ':' && _strnicmp(name, "data", 4))
        {
            strcpy_s(outPath, 260, "DATA\\");
            strcat_s(outPath, 260, name);
            strcat_s(outPath, 260, suffix);
            strcat_s(outPath, 260, ext3);
        }
        else
        {
            strcpy_s(outPath, 260, name);
            strcat_s(outPath, 260, suffix);
            strcat_s(outPath, 260, ext3);
        }
    }
}

extern "C" unsigned char DAT_01202b48;

// @fnv 0x00c3bbd0
// src: COMMUNITY 0x00c3bbd0
void* __cdecl GetProgramFlowTextPath()
{
    return &DAT_01202b48;
}

extern char DAT_01202a40[0x104];

// @fnv 0x00c3bc20
// src: COMMUNITY 0x00c3bc20
char* __cdecl MessageHandler_GetProgrammerOutputFileName()
{
    return DAT_01202a40;
}

// FUN_00c3bc70 returns the address of the 0x104-byte scratch buffer that the
// sibling helpers FUN_00c3bc80 (strcpy_s/strcat_s on it) operate on.
extern char DAT_01202938[0x104];

// @fnv 0x00c3bc70
// src: COMMUNITY 0x00c3bc70
char* __cdecl MessageHandler_GetCrashTraceFileName()
{
    return DAT_01202938;
}

// @fnv 0x00c3bcd0
// src: COMMUNITY 0x00c3bcd0
int __cdecl return_0_8()
{
    return 0;
}

extern "C" unsigned char DAT_011af49d;
extern "C" unsigned char DAT_011af49e;
extern "C" unsigned char DAT_011af49f;
extern unsigned char DAT_011f6370[0x18];
extern unsigned int DAT_01202d74;
extern unsigned int DAT_011f6388;
void __cdecl MessageHandler_InitSDM();

// Calls FUN_00c3c460, stores four bytes and a function pointer into globals, clears DAT_011f6370, and copies DAT_01202d74 into DAT_011f6388.
// @fnv 0x00c3bd30
// src: COMMUNITY 0x00c3bd30
void __cdecl MessageHandler_Init(unsigned char ucParam1, unsigned char ucParam2, unsigned char ucParam3,
                          unsigned char ucParam4, unsigned int e)
{
    unsigned int unk04;
    unsigned int unk08;
    int i;
    MessageHandler_InitSDM();
    DAT_011af49c = ucParam1;
    DAT_011af49d = ucParam2;
    DAT_011af49e = ucParam3;
    DAT_011af49f = ucParam4;
    DAT_01202d5c = reinterpret_cast<PFN_00c3c100>(e);
    for (i = 0; i < 0x18; i++)
    {
        DAT_011f6370[i] = 0;
    }
    DAT_011f6388 = DAT_01202d74;
}

int* __cdecl MessageHandler_GetWarningFileName();
int __cdecl BSSystemFile_DeleteFileA(const char* p);
int __cdecl GetFileSize(int* buf, int* out);


// @fnv 0x00c3bda0
MessageHandler::~MessageHandler()
{
    int info[9];
    if (GetFileSize(MessageHandler_GetWarningFileName(), &info[7]) == 0)
    {
        if (info[7] == 0x46 && info[8] == 0)
            BSSystemFile_DeleteFileA((const char*)MessageHandler_GetWarningFileName());
    }
    if (MessageHandler::pHandler == this)
        MessageHandler::pHandler = 0;
}

// @fnv 0x00c3be40
// src: GUESS 0x00c3be40 (confidence: high)
int Object_ReturnZero_00c3be40()
{
    return 0;
}

// @fnv 0x00c3c220
// src: XBOX_PDB 0x00c3c220
int __cdecl MessageHandler_Output()
{
    return 0;
}



extern "C" void __cdecl CbtHookProc(int code, WPARAM wParam, LPARAM lParam);

extern int DAT_01202d70;

// @fnv 0x00c3c250
// src: COMMUNITY 0x00c3c250
void __cdecl MessageHandler_InstallMessageBoxHook()
{
    if (DAT_01202d70 == 0)
    {
        DAT_01202d70 = (int)SetWindowsHookExA(5, (HOOKPROC)CbtHookProc, 0, GetCurrentThreadId());
    }
}



// If the global hook handle DAT_01202d70 is set, unhooks it with UnhookWindowsHookEx and clears the handle.
// @fnv 0x00c3c280
// src: COMMUNITY 0x00c3c280
void __cdecl MessageHandler_RemoveMessageBoxHook()
{
    if (DAT_01202d70 != 0)
    {
        UnhookWindowsHookEx((HHOOK)DAT_01202d70);
        DAT_01202d70 = 0;
    }
}

extern "C" void* fnv_zlib_memset(void* pvDest, int iValue, int iSize);

typedef void* C3C2B0HWND;

extern int(__stdcall* g_pfnC3C2B0GetClassName)(C3C2B0HWND hWnd, char* pcClassName, int m_iMaximumCount);
extern int(__stdcall* g_pfnC3C2B0GetWindowText)(C3C2B0HWND hWnd, char* pcString, int m_iMaximumCount);

int C3C2B0StrCmp(const char* pcA, const char* pcB);

// EnumChildWindows callback: finds the "Cancel" button.
// Searches a window: if it is a Button whose text is non-empty and not "Cancel", stores it through lParam and returns false; otherwise returns true.
// @fnv 0x00c3c2b0
int __stdcall FindFirstNonCancelButton(C3C2B0HWND hWnd, long lParam)
{
    bool bContinueSearch = true;
    if (hWnd)
    {
        char acText[260];
        fnv_zlib_memset(acText, 0, 260);
        if (g_pfnC3C2B0GetClassName(hWnd, acText, 260) && !C3C2B0StrCmp(acText, "Button"))
        {
            fnv_zlib_memset(acText, 0, 260);
            if (g_pfnC3C2B0GetWindowText(hWnd, acText, 260) && acText[0] && !C3C2B0StrCmp(acText, "Cancel"))
            {
                C3C2B0HWND* phFoundButton = (C3C2B0HWND*)lParam;
                *phFoundButton = hWnd;
                bContinueSearch = false;
            }
        }
    }
    return bContinueSearch;
}


int __stdcall FindFirstNonCancelButton(void* hwnd, int lParam);

// @fnv 0x00c3c3a0
int __stdcall CbtHookProc(int code, unsigned int wParam, int lParam)
{
    if (code < 0)
    {
        return CallNextHookEx((HHOOK)DAT_01202d70, code, wParam, lParam);
    }
    switch (code)
    {
    case 5: {
        void* owner = (void*)wParam;
        void* found = 0;
        EnumChildWindows((HWND)owner, (WNDENUMPROC)(int(__stdcall*)(void*, int))FindFirstNonCancelButton, (int)&found);
        if (found != 0)
        {
            SetWindowTextA((HWND)found, "Yes to all");
            MessageHandler_RemoveMessageBoxHook();
        }
        break;
    }
    }
    return CallNextHookEx((HHOOK)DAT_01202d70, code, wParam, lParam);
}

// Sets the vtable to DAT_010c14fc, calls Resize(5, 0), then sets it to DAT_010c1510 and returns this.
// @fnv 0x00c3c540
// src: COMMUNITY 0x00c3c540
int* __thiscall QueuedParents::QueuedParents_00c3c540()
{
    int unused04;
    int unused08;
    int unused0C;
    int unused10;
    int unused14;

    *reinterpret_cast<int**>(this) = &DAT_010c14fc;
    this->Resize(5, 0);
    *reinterpret_cast<int**>(this) = &DAT_010c1510;

    return reinterpret_cast<int*>(this);
}

class C3CAE0Task
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void Notify(int iStatus);
};

struct C3CAE0TaskArray
{
    int unk00;
    C3CAE0Task** m_ppkData;
    unsigned int m_uiSize;
};

class C3CAE0Manager
{
  public:
    void IOManager_RequeueTask(void* pvTask, int iStatus);
};

extern C3CAE0Manager* g_pkC3CAE0Manager;

class C3CAE0Request
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    C3CAE0TaskArray* m_pkTasks;

    void NotifyTasks(int iStatus);
};

// Notifies each task in m_pkTasks with iStatus, then forwards this request and iStatus to g_pkC3CAE0Manager.
// @fnv 0x00c3cae0
void C3CAE0Request::NotifyTasks(int iStatus)
{
    if (m_pkTasks)
    {
        unsigned int uiTaskCount = m_pkTasks->m_uiSize;
        for (unsigned int i = 0; i < uiTaskCount; i++)
        {
            C3CAE0Task*& rpkEntry = m_pkTasks->m_ppkData[i];
            C3CAE0Task* pkTask = rpkEntry;
            if (pkTask)
                pkTask->Notify(iStatus);
        }
    }
    g_pkC3CAE0Manager->IOManager_RequeueTask(this, iStatus);
}

struct C3D3E0Heap
{
    void Deallocate(void* pvMem);
};

extern C3D3E0Heap g_kC3D3E0Heap;

class C3D3E0Palette
{
  public:
    int unk00;

    ~C3D3E0Palette();
    C3D3E0Palette* FUN_00c3d3e0(unsigned int uiFlags);
};

// Scalar deleting destructor.
// Destructs the object, frees it via g_kC3D3E0Heap when uiFlags has bit 0 set, and returns this.
// @fnv 0x00c3d3e0
C3D3E0Palette* C3D3E0Palette::FUN_00c3d3e0(unsigned int uiFlags)
{
    this->C3D3E0Palette::~C3D3E0Palette();
    if (uiFlags & 1)
        g_kC3D3E0Heap.Deallocate(this);
    return this;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct RefObject
{
    void* vtable;
    long unk04;
    volatile long refCount;
};
struct Array
{
    virtual ~Array();
    virtual void* Allocate(unsigned int count);
    RefObject** data;
    unsigned int size;
    unsigned int capacity;
    void __thiscall Resize(unsigned int reserve, unsigned int count);
};
// Resets the array, allocates reserve slots (at least count), zero-initialises count elements and sets size to count.
// @fnv 0x00c3d780
void Array::Resize(unsigned int reserve, unsigned int count)
{
    data = 0;
    size = 0;
    capacity = 0;
    if (count > reserve)
        reserve = count;
    if (reserve > 0)
    {
        data = (RefObject**)Allocate(reserve);
        capacity = reserve;
    }
    if (count > 0)
    {
        unsigned int position;
        RefObject** initializedElement;
        RefObject** destination;
        RefObject* pointer;
        RefObject** array = data;
        for (position = 0; position < count; ++position)
        {
            destination = array + position;
            initializedElement =
                destination ? ((*destination = 0),
                               (*destination && (pointer = *destination, InterlockedIncrement(&pointer->refCount))),
                               destination)
                            : (RefObject**)0;
        }
        size = count;
    }
}

class FUN_00c3d870_cls
{
  public:
    virtual void* v0();
    virtual void* v1(void* a);
    virtual void v2(void* a);
    virtual void* v3(void* a, void* b);
    void Helper(void* a, void* b, void* c);
    void QueuedChildren_SetLength(void* a1, void* a2);

    void* m_04;
    unsigned int unk08;
    void* m_0c;
};

// Rebuilds m_04 from a1 when a2 differs from m_0c, otherwise updates m_04 via v3; caches a1 in m_0c when m_04 is null.
// @fnv 0x00c3d870
// src: COMMUNITY 0x00c3d870
void FUN_00c3d870_cls::QueuedChildren_SetLength(void* a1, void* a2)
{
    void* tmp;
    void* q;
    void* r;
    if (m_04 != 0)
    {
        if (a2 == m_0c)
        {
            m_04 = v3(m_04, a1);
        }
        else
        {
            tmp = v1(a1);
            Helper(tmp, m_04, a2);
            v2(m_04);
            m_04 = 0;
            m_04 = tmp;
        }
    }
    else
    {
        m_04 = v1(a1);
        m_0c = a1;
    }
}

struct S_00c3db60_Item
{
    virtual ~S_00c3db60_Item();
};
struct S_00c3db60_Base
{
    S_00c3db60_Base();
    virtual ~S_00c3db60_Base();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
};
struct FUN_00c3db60 : S_00c3db60_Base
{
    S_00c3db60_Item* unk64;
    virtual ~FUN_00c3db60();
};
// Destructor that deletes the owned item pointer unk64.
// @fnv 0x00c3db60
FUN_00c3db60::~FUN_00c3db60()
{
    delete unk64;
}

struct FUN_00c3df40_Param1
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __int64 unk10;
};

struct FUN_00c3df40_Class
{
    void __thiscall BSTaskManager_int64_RequeueTask(FUN_00c3df40_Param1* a1, __int64 a2);
    void __thiscall IOManager_RequeueTask(FUN_00c3df40_Param1* a1, int a2);
};

// @fnv 0x00c3df40
// src: XBOX_PDB 0x00c3df40
void __thiscall FUN_00c3df40_Class::IOManager_RequeueTask(FUN_00c3df40_Param1* pParam, int iValue)
{
    __int64 val = pParam->unk10;
    val = (val & 0xFFFFFFFFFF00FFFFULL) + ((__int64)iValue << 16);
    this->BSTaskManager_int64_RequeueTask(pParam, val);
}

struct FUN_00c3f650_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_uiModulus;
    unsigned int Modulo(volatile unsigned int value, unsigned int unused);
};
// @fnv 0x00c3f650
unsigned int FUN_00c3f650_cls::Modulo(volatile unsigned int value, unsigned int unused)
{
    return value % m_uiModulus;
}

struct C3F670Timer
{
    unsigned __int64 LockFreeMap_int64_NiPointer_BSTask_int64_GenerateKey(unsigned __int64 uiTicks);
};

// @fnv 0x00c3f670
// src: COMMUNITY 0x00c3f670
unsigned __int64 C3F670Timer::LockFreeMap_int64_NiPointer_BSTask_int64_GenerateKey(unsigned __int64 uiTicks)
{
    return uiTicks;
}

struct FUN_00c3f690_pair
{
    int x;
    int y;
};

struct FUN_00c3f690_cls
{
    int unk00;
    void __thiscall CopyPair(FUN_00c3f690_pair p, FUN_00c3f690_pair* out);
};

// @fnv 0x00c3f690
void FUN_00c3f690_cls::CopyPair(FUN_00c3f690_pair aPair, FUN_00c3f690_pair* out)
{
    *out = aPair;
}

struct S_00c3f6b0_Class
{
    bool IsGreaterOrEqual(__int64 a, __int64 b);
};
// Returns whether a is greater than or equal to b.
// @fnv 0x00c3f6b0
bool S_00c3f6b0_Class::IsGreaterOrEqual(__int64 a, __int64 b)
{
    return a >= b;
}

struct FUN_00c3fa70_elem
{
    virtual int vDtor(int flags);
};

struct DynamicMemoryAllocator
{
    void MemoryManager_Deallocate(void* apPtr);
};

extern "C" DynamicMemoryAllocator DAT_011f6238;

struct TeardownBase
{
    virtual void v00();
    ~TeardownBase();
};

struct FUN_00c3fa70_cls : public TeardownBase
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    unsigned int m_uCount4c;
    FUN_00c3fa70_elem** m_ppItems50;
    void* m_p54;

    virtual ~FUN_00c3fa70_cls();
};

// @fnv 0x00c3fa70
FUN_00c3fa70_cls::~FUN_00c3fa70_cls()
{
    unsigned int i = 0;
    FUN_00c3fa70_elem* item3;
    FUN_00c3fa70_elem* eTmp;
    for (; i < m_uCount4c; i++)
    {
        item3 = m_ppItems50[i];
        eTmp = item3;
        (eTmp != 0) ? eTmp->vDtor(1) : 0;
    }
    void* pItems = m_ppItems50;
    DAT_011f6238.MemoryManager_Deallocate(pItems);
    void* pTail2 = m_p54;
    DAT_011f6238.MemoryManager_Deallocate(pTail2);
}

struct BoundShape
{
    void AddRef();
};
struct TESBoundObjectBounds
{
    int unk00;
    int unk04;
    int iType;
};
struct BoundHolder
{
    int unk00;
    int unk04;
    int unk08;
    TESBoundObjectBounds* pData;
};
struct CullerData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int iCullMode;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    BoundShape* pBound;
};
struct MultiBoundNodeStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    NiAVObject** m_ppObjects;
    unsigned short unkA4;
    unsigned short m_usSize;
    unsigned short m_usElementCount;
    unsigned short unkAA;
    BoundHolder* pHolder;
    int iCullMode;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    BoundShape* pBound;

    void BSMultiBoundRoom_OnVisible(NiCullingProcess& kCuller);
};

// @fnv 0x00c39890
// src: XBOX_PDB 0x00c39890
void MultiBoundNodeStandIn::BSMultiBoundRoom_OnVisible(NiCullingProcess& kCuller)
{
    CullerData* pProcB = 0;
    int bVis;
    int iOldModeB = 0;
    BoundShape* pOldBound;
    BoundShape* pNewBound;
    unsigned int iIndex;
    NiAVObject* pkChild;
    if (m_usElementCount == 0 && (bool)(int)(unkBC == 0))
        return;
    pProcB = (CullerData*)&kCuller;
    {
        BoundHolder* pH = pHolder;
        TESBoundObjectBounds* pD = pH->pData;
        bVis = pD->iType;
    }
    {
        int m1, m2;
        if ((m1 = pProcB->iCullMode) == 3 || (m2 = pProcB->iCullMode) == 1)
            bVis = 1;
    }
    {
        int m3, m4;
        if (bVis != 1 && (m3 = pProcB->iCullMode) != 3 && (m4 = pProcB->iCullMode) != 1)
            return;
    }
    pOldBound = pProcB->pBound;
    pNewBound = 0;
    pNewBound = pBound;
    iOldModeB = pProcB->iCullMode;
    {
        int m5;
        if ((m5 = pProcB->iCullMode) != 3)
        {
            int iMode = iCullMode;
            pProcB->iCullMode = iMode;
        }
    }
    {
        int m6, mB;
        if ((m6 = pProcB->iCullMode) != 3 && (mB = pProcB->iCullMode) != 1)
        {
            if (pNewBound)
                pNewBound->AddRef();
            pProcB->pBound = pNewBound;
            if (pNewBound)
                pNewBound->AddRef();
        }
    }
    for (iIndex = 0; iIndex < m_usSize; iIndex++)
    {
        NiAVObject** ppChild = &m_ppObjects[iIndex];
        pkChild = *ppChild;
        if (pkChild)
            pkChild->Cull(kCuller);
    }
    pProcB->iCullMode = iOldModeB;
    {
        int mA, m9;
        if ((mA = pProcB->iCullMode) != 3 && (m9 = pProcB->iCullMode) != 1)
            pProcB->pBound = pOldBound;
    }
}

// @fnv 0x00c3bce0
// src: COMMUNITY 0x00c3bce0
void __cdecl nullsub_340()
{}

// @fnv 0x00c3c090
// src: COMMUNITY 0x00c3c090
void __cdecl nullsub_342()
{}

// @fnv 0x00c3c0a0
// src: COMMUNITY 0x00c3c0a0
void __cdecl nullsub_343()
{}

// @fnv 0x00c3c0b0
// src: COMMUNITY 0x00c3c0b0
void __cdecl nullsub_344()
{}

// @fnv 0x00c3c240
// src: COMMUNITY 0x00c3c240
void __cdecl nullsub_345()
{}

int __cdecl Setting_DataType_00c33090(const char* p);
unsigned int __cdecl NiGetViewerString(const char* buf, bool v);
unsigned int __cdecl FormatStringAssignment(const char* buf, char v);
unsigned int __cdecl NiGetViewerString_00a7d4d0(const char* buf, int v);
unsigned int __cdecl NiGetViewerString_00a7d510(const char* buf, unsigned int v);
unsigned int __cdecl NiGetViewerString_00a7d550(const char* buf, float v);
char* __cdecl NiGetViewerString_00a7d5e0(const char* buf, const char* v);

union SettingValue
{
    bool boolean;
    unsigned char character;
    int integer;
    unsigned int unsignedInteger;
    float real;
    const char* string;
};
extern SettingValue DAT_01202800;

struct FUN_00c33280_Class
{
    unsigned int m_00;
    SettingValue value;
    const char* m_08;
    void __thiscall Setting_GetViewerStrings(NiTPrimitiveArray<unsigned int>* arr);
};

// Builds two spaces plus m_08 in a 256-byte buffer, formats value by the type from FUN_00c33090(m_08), and adds the helper's result to arr via AddFirstEmpty.
// @fnv 0x00c33280
// src: XBOX_PDB 0x00c33280
void __thiscall FUN_00c33280_Class::Setting_GetViewerStrings(NiTPrimitiveArray<unsigned int>* arr)
{
    char aBuf[256];
    unsigned int ai;
    unsigned int al;
    unsigned int bs;
    unsigned int bu;
    unsigned int* cb;
    unsigned int cl;
    unsigned int d1;
    unsigned int d7;
    unsigned int dx;
    const char* em;
    unsigned int fd;
    float* ff;
    unsigned int gb;
    int* ap;
    unsigned int at;
    unsigned char* by;
    unsigned int ch;
    bool* d4;
    const char* da;
    unsigned int dg;
    unsigned int dt;
    unsigned int eh;
    unsigned int fl;
    unsigned int gf;
    unsigned int bi;

    strcpy_s(aBuf, 256, "  ");
    da = m_08;
    strcat_s(aBuf, 256, da);
    switch (Setting_DataType_00c33090(m_08))
    {
    case 0:
        d4 = this ? &value.boolean : (DAT_01202800.boolean = false, &DAT_01202800.boolean);
        bi = NiGetViewerString(aBuf, *d4);
        arr->AddFirstEmpty(bi);
        break;
    case 1:
    case 2:
        by = this ? &value.character : (DAT_01202800.character = 0, &DAT_01202800.character);
        gf = FormatStringAssignment(aBuf, *by);
        arr->AddFirstEmpty(gf);
    case 3:
        ap = this ? &value.integer : (DAT_01202800.integer = 0, &DAT_01202800.integer);
        fl = NiGetViewerString_00a7d4d0(aBuf, *ap);
        arr->AddFirstEmpty(fl);
        break;
    case 5:
        ff = this ? &value.real : (DAT_01202800.real = 0.0f, &DAT_01202800.real);
        eh = NiGetViewerString_00a7d550(aBuf, *ff);
        arr->AddFirstEmpty(eh);
        break;
    case 6:
        if (this)
            em = value.string;
        else
            em = 0;
        dt = (unsigned int)NiGetViewerString_00a7d5e0(aBuf, em);
        arr->AddFirstEmpty(dt);
        break;
    case 4:
    default:
        cb = this ? &value.unsignedInteger : (DAT_01202800.unsignedInteger = 0, &DAT_01202800.unsignedInteger);
        dg = NiGetViewerString_00a7d510(aBuf, *cb);
        arr->AddFirstEmpty(dg);
        break;
    }
}

struct FUN_00c3a250_Class
{
    void FUN_00c3a250(int& a);
};

struct FUN_00c39ad0_Class
{
    int unk00[0x30];
    FUN_00c3a250_Class m_c0;

    void BSMultiBoundRoom_RemoveOccluder(int a);
};

// If a is non-zero, forwards it to m_c0.FUN_00c3a250.
// @fnv 0x00c39ad0
// src: XBOX_PDB 0x00c39ad0
void FUN_00c39ad0_Class::BSMultiBoundRoom_RemoveOccluder(int a)
{
    int pad0[10];
    int pad1[9];
    if (a)
    {
        m_c0.FUN_00c3a250(a);
    }
}

struct S00c3a2e0_Ptr
{
    void* unk00;
    void FUN_0066b0d0(void* value);
};

struct S00c3a2e0_Node
{
    S00c3a2e0_Node* unk00;
    void* unk04;
    S00c3a2e0_Ptr unk08;
};

struct S00c3a2e0_Alloc
{
    void* unk00;
    void NiTPointerAllocator_unsigned_int_Deallocate(void* value);
};

struct S00c3a2e0_Cls
{
    S00c3a2e0_Node* unk00;
    unsigned int unk04;
    S00c3a2e0_Alloc unk08;

    void ProcessEntries_00c3a2e0();
};

// Walks the list from unk00, calls FUN_0066b0d0(0) on each node and passes it to FUN_0045cee0, then zeroes unk08.unk00, unk00 and unk04.
// @fnv 0x00c3a2e0
// src: GUESS 0x00c3a2e0 (confidence: low)
void S00c3a2e0_Cls::ProcessEntries_00c3a2e0()
{
    S00c3a2e0_Node* pNext;
    S00c3a2e0_Node* p;
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;

    p = this->unk00;
    while (p != 0)
    {
        pNext = p;
        p = p->unk00;
        pNext->unk08.FUN_0066b0d0(0);
        this->unk08.NiTPointerAllocator_unsigned_int_Deallocate(pNext);
    }
    this->unk08.unk00 = 0;
    this->unk00 = 0;
    this->unk04 = 0;
}

// @fnv 0x00c3bcc0
// src: COMMUNITY 0x00c3bcc0
void nullsub_339()
{}

extern int DAT_01202d78;
extern char* DAT_01202d58;
extern bool DAT_01202d90;
extern char DAT_01015890[];
extern char DAT_010c14c0[];
extern char DAT_0101f520[];
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
struct C3BEFile
{
    int m_00, m_04, m_08, m_0c, m_10;
    C3BEFile(const char*, int, int, int);
    ~C3BEFile();
    int BSSystemFile_DoWrite(const char*, unsigned __int64, unsigned __int64*);
    int BSSystemFile_DoFlush();
};
// Returns true immediately; the unreachable code after it writes text to path through a file object, recursing once with a message under a critical section.
// @fnv 0x00c3be50
// src: COMMUNITY 0x00c3be50
bool __cdecl MessageHandler_WriteFile(const char* path, const char* text, bool flush)
{
    return true;
    if (!path)
        return true;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_01202d78);
    if (DAT_01202d58 && !DAT_01202d90)
    {
        DAT_01202d90 = true;
        char* prefix = DAT_01202d58 + 8;
        if (!*prefix)
            prefix = DAT_01015890;
        char buffer[256];
        sprintf_s(buffer, 256, DAT_010c14c0, DAT_01202d58 + 0xe0, prefix);
        MessageHandler_WriteFile(path, buffer, false);
        DAT_01202d90 = false;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_01202d78);
    bool success = false;
    C3BEFile file(path, 1, 1, 0);
    if (file.m_00 == 0)
    {
        unsigned __int64 written = strlen(text);
        unsigned __int64 length;
        file.m_00 = file.BSSystemFile_DoWrite(text, written, &length);
        if (!DAT_01202d90 && success && (text[written - 2] != '\r' || text[written - 1] != '\n'))
        {
            written = 2;
            file.m_00 = file.BSSystemFile_DoWrite(DAT_0101f520, written, &length);
        }
        if (flush)
            file.m_00 = file.BSSystemFile_DoFlush();
        success = file.m_00 == 0;
    }
    return success;
}

// @fnv 0x00c3c080
// src: COMMUNITY 0x00c3c080
void __cdecl nullsub_341()
{}

void __fastcall BSTask_int64_DecRefCount(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

struct Obj090
{
    int unk00;
    int unk04;
    long refs;
};

struct Smart090
{
    Obj090* ptr;
};

struct Node090
{
    int unk00;
    union
    {
        Smart090 smart;
        Node090* next;
    };
};

struct Vtbl090
{
    void* unk00;
    void* unk04;
    void* unk08;
    int limit;
};

struct FUN_00c42b60_class
{
    Vtbl090* vtbl;
    int unk04;
    int unk08;
    int count;
    Node090* head;
    int CopyData_00c42b80();
    void UpdateReferenceState_00c3f090(Node090* node);
};

// Clears node's pointer (via FUN_0044dd60), pushes node onto head, increments count, and calls FUN_00c42b80 when count equals vtbl->limit.
// @fnv 0x00c3f090
// src: GUESS 0x00c3f090 (confidence: low)
void FUN_00c42b60_class::UpdateReferenceState_00c3f090(Node090* node)
{
    int CN2;
    int CN;
    int CNA;
    Obj090* CNX;
    Smart090* Dir3 = &node->smart;
    if (Dir3->ptr != 0)
    {
        if (Dir3->ptr)
            BSTask_int64_DecRefCount(Dir3->ptr);
        Dir3->ptr = 0;
        if (Dir3->ptr)
        {
            CNX = Dir3->ptr;
            InterlockedIncrement(&CNX->refs);
        }
    }
    Node090* CSATmp = head;
    node->next = CSATmp;
    head = node;
    count++;
    int CNVal = vtbl->limit;
    if (count == CNVal)
        CopyData_00c42b80();
}

struct FUN_00c41610_Obj
{
    void* unk00;
    unsigned int unk04;

    int __thiscall SetSlotValue(void* arg);
};

struct FUN_00c3f750_Class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    FUN_00c41610_Obj* unk14;

    int __thiscall LockFreeMap_GetInterface();
};

extern "C" int(__stdcall* DAT_00fdf044)(unsigned int index);

// Calls DAT_00fdf044 with unk14->unk04 and returns the result if nonzero; otherwise returns unk14->SetSlotValue(this).
// @fnv 0x00c3f750
// src: COMMUNITY 0x00c3f750
int __thiscall FUN_00c3f750_Class::LockFreeMap_GetInterface()
{
    int tmp;
    int d2;
    int d3;
    int d0;
    int v;
    int j;
    int found;
    FUN_00c41610_Obj* obj;

    obj = this->unk14;
    v = (int)obj->unk04;
    found = DAT_00fdf044((unsigned int)v);

    if (found)
    {
        j = found;
    }
    else
    {
        j = obj->SetSlotValue(this);
    }

    return j;
}
