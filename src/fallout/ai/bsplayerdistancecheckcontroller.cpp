
// src/fallout/ai/bsplayerdistancecheckcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/bsplayerdistancecheckcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/NiRTTI.h"
#include "../../../include/BSPlayerDistanceCheckController.h"

extern "C" const NiRTTI* const g_011dfeac;

struct FUN_00a6d290
{
    virtual void v00();
    ~FUN_00a6d290();
};

// The shared controller header does not yet declare these methods or the callback at 0x38.

// @fnv 0x008d1610
const NiRTTI* const* BSPlayerDistanceCheckController::GetNiRTTI()
{
    return &g_011dfeac;
}

// Runs the destructor and, when bit 0 of flags is set, frees this with operator delete; returns this.
// @fnv 0x008d1620
void* __thiscall BSPlayerDistanceCheckController::ScalarDeletingDestructor(unsigned int flags)
{
    this->BSPlayerDistanceCheckController::~BSPlayerDistanceCheckController();
    if (flags & 1)
        BSPlayerDistanceCheckController::operator delete(this, 0x3c);
    return this;
}

struct TESObjectDoorController
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
    TESObjectDoorController();
    void* vtable;
    unsigned int references;
    void* next;
    unsigned short flags;
    unsigned short state;
    float frequency;
    float phase;
    float startTime;
    float stopTime;
    float lastTime;
    float weightedTime;
    float scaledTime;
    void* target;
    void* interpolation;
    void* door;
    void* animation;
};
struct ControllerFactory
{
    void BSPlayerDistanceCheckController_CopyMembers(TESObjectDoorController*, void*);
    TESObjectDoorController* CreateController(void*);
};
// @fnv 0x008d1740
TESObjectDoorController* ControllerFactory::CreateController(void* context)
{
    TESObjectDoorController* result = new TESObjectDoorController;
    BSPlayerDistanceCheckController_CopyMembers(result, context);
    return result;
}

extern "C" const double DAT_01012060;
extern char DAT_011f4280;

struct DoorSpawnRequest
{
    unsigned int unk00;
    void* NiAVObject_GetWorldTranslate();
};
struct ItemHandle
{
    unsigned int raw;
    unsigned int unk04;
    unsigned int unk08;
    double FUN_00457990();
};
struct ItemRef
{
    void SubtractIntoVector();
};

struct Manager
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual ItemRef* v1f4(ItemHandle* out, void* h);
};
extern Manager* DAT_011dea3c;
DoorSpawnRequest* __cdecl NiObject_DynamicCast(char* tag, void* owner);

// @fnv 0x008d1670
void BSPlayerDistanceCheckController::UpdateDoorSpawn(unsigned int unkArg)
{
    DoorSpawnRequest* req;
    ItemHandle handle;
    if (NiControllerSequence_GetLastTime() < DAT_01012060 || !GetField38() || DAT_011dea3c == 0)
    {
    }
    else
    {
        req = NiObject_DynamicCast((char*)&DAT_011f4280, m_pkTarget);
        if (req != 0)
        {
            DAT_011dea3c->v1f4(&handle, req->NiAVObject_GetWorldTranslate())->SubtractIntoVector();
            if (handle.FUN_00457990() < NiControllerSequence_GetLastTime())
            {
                m_callback(req);
            }
        }
    }
}

namespace fnv_008d1720 {
extern int DAT_011f4280;

void __cdecl NiObject_IsKindOf(int* apTarget, void* apValue);

}  // namespace fnv_008d1720

// @fnv 0x008d1720
// src: XBOX_PDB 0x008d1720
void BSPlayerDistanceCheckController::TargetIsRequiredType()
{
    fnv_008d1720::NiObject_IsKindOf(&fnv_008d1720::DAT_011f4280, m_pkTarget);
}

// @fnv 0x008d1650
BSPlayerDistanceCheckController::~BSPlayerDistanceCheckController()
{}
