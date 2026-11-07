// fallout_shared/pathfinding/pathingrequest.cpp: PathingRequest, PathingAvoidNodeArray, PathingRequestDebugView (24 functions)

#include "../../../include/PathingLocation.h"
// The unit type header also includes an older local PathingLocation header.
#define FNV_PATHINGLOCATION_H
#include "pathingrequest_types_PathingRequest.h"
#include "pathingrequest_types_TESPackage.h"
#include "TESObjectREFR.h"
#include "pathingrequest_decls.h"
#include "../../../include/BGSSaveGameBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"

// @fnv 0x006e38d0
void PathingRequest::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    if (reinterpret_cast<BGSLoadFormBufferView*>(buffer)->GetVersion() < 14)
    {
        m_bCanWalk = false;
        Actor* actor = reinterpret_cast<BGSLoadFormBufferView*>(buffer)->GetActor();
        if (actor)
        {
            TESPackage* package = reinterpret_cast<MobileObject*>(actor)->GetCurrentPackage();
            if (package &&
                reinterpret_cast<Calendar*>(package)->GetDaysPassed() ==
                    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_ESCORT_ACTOR &&
                package->GetTargetForActor(actor, false) == reinterpret_cast<TESObjectREFR*>(g_thePlayer))
                m_bCanWalk = true;
        }
    }
}

// Loads a PathingRequest from a BGSLoadFormBuffer, reading origin/destination, flags, and version-gated fields, then a count-driven array of avoid nodes.
// @fnv 0x006e34f0
void PathingRequest::LoadGame(BGSLoadFormBuffer* buffer)
{
    Origin.LoadGame(buffer);
    Destination.LoadGame(buffer);
    buffer->ReadTypedData(static_cast<void*>(&m_fFirstValueAfterActorData), 4u);
    buffer->ReadTypedData(static_cast<void*>(&m_fSecondValueAfterActorData), 4u);
    buffer->ReadTypedData(static_cast<void*>(&PathingActorSpatialData), 4u);
    buffer->ReadTypedData(static_cast<void*>(&fWeaponSpread), 4u);
    buffer->ReadTypedData(static_cast<void*>(&m_fCenterRadius), 4u);
    buffer->ReadTypedData(static_cast<void*>(&m_fFloatAfterCenter), 4u);
    buffer->ReadTypedData(static_cast<void*>(&m_fPathingRadius), 4u);
    buffer->ReadTypedData(static_cast<void*>(&bFaceTargetAtGoal), 1u);
    buffer->ReadTypedData(static_cast<void*>(&bCantOpenDoors), 1u);
    buffer->ReadTypedData(static_cast<void*>(&PathingOptions), 1u);
    buffer->ReadTypedData(static_cast<void*>(&bAllowIncompletePath), 1u);
    buffer->ReadTypedData(static_cast<void*>(&m_bAllowDoorTraversal), 1u);
    buffer->ReadTypedData(static_cast<void*>(&bCanSwim), 1u);
    if (buffer->GetVersion() >= 13)
    {
        buffer->ReadTypedData(static_cast<void*>(&m_bCanWalk), 1u);
    }
    if (buffer->GetVersion() >= 15)
    {
        buffer->ReadTypedData(static_cast<void*>(&m_fAvoidanceRadius), 4u);
        buffer->ReadTypedData(static_cast<void*>(&m_bCanJump), 1u);
        buffer->ReadTypedData(static_cast<void*>(&m_bCanClimb), 1u);
    }
    if (buffer->GetVersion() >= 18)
    {
        buffer->ReadTypedData(static_cast<void*>(&Center), 12u);
        buffer->ReadTypedData(static_cast<void*>(&m_bCanUseDoors), 1u);
        buffer->ReadTypedData(static_cast<void*>(&m_bCanRun), 1u);
        buffer->ReadTypedData(static_cast<void*>(&bIgnoreLocks), 1u);
        buffer->ReadTypedData(static_cast<void*>(&m_iRequestType), 4u);
    }
    if (buffer->GetVersion() >= 20)
    {
        buffer->ReadTypedData(static_cast<void*>(&bCanFly), 1u);
    }
    if (buffer->GetVersion() >= 21)
    {
        buffer->ReadTypedData(static_cast<void*>(&m_bCanOpenDoors), 1u);
    }
    unsigned int count = buffer->ReadElementCount();
    if (count)
    {
        reinterpret_cast<PathingAvoidPointerView*>(&m_pPathingAvoidNodeArray)->Assign(reinterpret_cast<PathingAvoidNodeArray*>(new PathingAvoidNodeArrayStorage));
        reinterpret_cast<PathingAvoidPointerView*>(&m_pPathingAvoidNodeArray)->Get()->SetSize(count, true);
        for (unsigned int i = 0; i < count; ++i)
        {
            PathingAvoidNode* node =
                reinterpret_cast<PathingAvoidPointerView*>(&m_pPathingAvoidNodeArray)->Get()->BSSimpleArray_PathingAvoidNode_1024_GetAt(i);
            node->LoadPathingAvoidNode(buffer);
        }
    }
}

// Creates and returns a new pathing request object matching the given type, warning and returning null for unknown types.
// @fnv 0x006e2f80
PathingRequest* PathingRequest::CreateRequestForType(PATHING_REQUEST_TYPE type)
{
    switch (type)
    {
    case 0:
        return new PathingRequest;
    case 1:
        return new FUN_006e4080;
    case 2:
        return new PathingRequestClosePoint;
    case 3:
        return new PathingRequestFlee;
    case 4:
        return new PathingRequestHide;
    case 5:
        return new PathingRequestLOS;
    case 7:
        return new PathingRequestOptimalLocation;
    case 8:
        return new FUN_006e4a50;
    default:
        Warning("PATHFINDING: Unknown pathing request type %i", type);
        return 0;
    }
}

// Copies origin, destination, radii, smoothing and flag fields from this PathingRequest into the given request.
// @fnv 0x006e2750
void PathingRequest::CopyTo(PathingRequest* request)
{
    request->SetOrigin(GetOrigin());
    request->SetDestination(NiAVObject_GetRotate_006a9540());
    request->SetActorRadius(GetActorRadius());
    request->FUN_006d3ae0(GetFloatAtOffset68());
    request->SetActorLockData(GetActorLockData());
    request->SetCenterRadius(GetCenterRadius());
    NiPoint3 center = GetTargetPoint();
    request->PathingRequest_SetCenterRadius(center, GetTargetRadius());
    request->SetSmoothingRandomness(GetSmoothingRandomness());
    request->SetAvoidNodeArray(GetString());
    request->SetSmoothingRandomness(GetSmoothingRandomness());
    request->SetGoalZDelta(GetGoalZDelta());
    request->bCantOpenDoors = bCantOpenDoors;
    request->m_fPathingRadius = m_fPathingRadius;
    request->m_fAvoidanceRadius = m_fAvoidanceRadius;
    request->bFaceTargetAtGoal = bFaceTargetAtGoal;
    request->bAllowIncompletePath = bAllowIncompletePath;
    request->m_bAllowDoorTraversal = m_bAllowDoorTraversal;
    request->bCanSwim = bCanSwim;
    request->bCanFly = bCanFly;
    request->m_bCanWalk = m_bCanWalk;
    request->m_bCanJump = m_bCanJump;
    request->m_bCanClimb = m_bCanClimb;
    request->m_bCanUseDoors = m_bCanUseDoors;
    request->m_bCanRun = m_bCanRun;
    request->bIgnoreLocks = bIgnoreLocks;
    request->m_iRequestType = m_iRequestType;
    request->m_bCanOpenDoors = m_bCanOpenDoors;
}

// @fnv 0x006e2420
PathingRequest::PathingRequest() : m_pPathingAvoidNodeArray(0)
{
    m_fFirstValueAfterActorData = runtimeFloatSettingDefault65;
    m_fSecondValueAfterActorData = 1.0f;
    PathingActorSpatialData = 180.0f;
    fWeaponSpread = TESPackage::GetPackageDefaultFloat();
    m_fCenterRadius = 0.0f;
    static_cast<NiPoint3&>(Center) = pathingrequestZero;
    m_fPathingRadius = 0.0f;
    m_fAvoidanceRadius = 0.0f;
    bCantOpenDoors = false;
    bFaceTargetAtGoal = false;
    PathingOptions = false;
    bAllowIncompletePath = true;
    m_bAllowDoorTraversal = true;
    bCanSwim = true;
    bCanFly = false;
    m_bCanWalk = false;
    m_bCanJump = false;
    m_bCanClimb = false;
    m_bCanUseDoors = false;
    m_bCanRun = false;
    bIgnoreLocks = false;
    m_iRequestType = 3;
    m_bCanOpenDoors = false;
    m_fFloatAfterCenter = 0.0f;
}

// Calls Destruct on this, frees the object with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006e3880
PathingAvoidNodeArrayStorage* PathingAvoidNodeArrayStorage::Destroy(unsigned int flags)
{
    reinterpret_cast<PathingAvoidNodeArrayDestructionView*>(this)->Destruct();
    if (flags & 1)
        PathingAvoidNodeArrayStorage::operator delete(this, 24);
    return this;
}
// @fnv 0x006e3850
PathingAvoidNodeArrayStorage::PathingAvoidNodeArrayStorage()
{
    FUN_006e3960();
    *reinterpret_cast<void**>(data) = &DAT_0106d1e4;
    *reinterpret_cast<void**>(data + 16) = &DAT_0106d1d8;
}
// @fnv 0x006e38b0
PathingAvoidNodeArrayStorage::~PathingAvoidNodeArrayStorage()
{
    FUN_006e39d0();
}

void __cdecl Deallocate(void*);

struct FUN_006db090_shell
{
    void FreeBuffer(void* apBuffer);
};

// @fnv 0x006db090
void FUN_006db090_shell::FreeBuffer(void* apBuffer)
{
    Deallocate(apBuffer);
}

void __fastcall FUN_006e2620(void*);
void __cdecl FUN_00aa1460(void*, unsigned int);

struct FUN_006e25e0_impl
{
    void* FUN_006e25e0(unsigned int flags);
};

// Calls FUN_006e2620 on this, then if bit 0 of flags is set calls FUN_00aa1460 with size 0xb0, and returns this.
// @fnv 0x006e25e0
void* FUN_006e25e0_impl::FUN_006e25e0(unsigned int flags)
{
    FUN_006e2620(this);
    if (flags & 1)
        FUN_00aa1460(this, 0xb0);
    return this;
}

struct FUN_006e2980_shell : public PathingRequest
{
    void PathingRequest_SetCenterRadius(NiPoint3*, float);
};

// Stores arCenter at offset 0x7c and afOriginRadius at offset 0x78 of this object.
// @fnv 0x006e2980
// src: XBOX_PDB 0x006e2980
void FUN_006e2980_shell::PathingRequest_SetCenterRadius(NiPoint3* apCenter, float afOriginRadius)
{
    *(NiPoint3*)((char*)this + 0x7c) = *apCenter;
    *(float*)((char*)this + 0x78) = afOriginRadius;
}

struct FUN_006e2b50_shell : public PathingRequest
{
    void SetCantOpenDoors(bool);
};

// @fnv 0x006e2b50
void FUN_006e2b50_shell::SetCantOpenDoors(bool abCantOpenDoors)
{
    *((bool*)((char*)this + 0x98)) = abCantOpenDoors;
}

struct FUN_006e2b70_shell : public PathingRequest
{
    void SetCanSwim(bool);
};

// @fnv 0x006e2b70
void FUN_006e2b70_shell::SetCanSwim(bool abCanSwim)
{
    *((bool*)((char*)this + 0x9d)) = abCanSwim;
}

struct FUN_006e2bb0_shell : public PathingRequest
{
    void SetInitialPathHeading(float);
};

// Stores afInitialPathHeading at offset 0x90 and sets the bool at offset 0xa0 to true.
// @fnv 0x006e2bb0
void FUN_006e2bb0_shell::SetInitialPathHeading(float afInitialPathHeading)
{
    *(float*)((char*)this + 0x90) = afInitialPathHeading;
    *(bool*)((char*)this + 0xa0) = true;
}

struct FUN_006e3a80
{
    virtual void va();
    char pad[12];
    FUN_006e3a80();
    ~FUN_006e3a80();
};
struct FUN_006e3960 : public FUN_006e3a80, public NiRefObject
{
    FUN_006e3960();
    ~FUN_006e3960();
};
// @fnv 0x006e3960
FUN_006e3960::FUN_006e3960()
{}

struct FUN_006e3ab0
{
    virtual void va();
    char pad[12];
    ~FUN_006e3ab0();
};
struct FUN_00496910
{
    virtual void vb();
    ~FUN_00496910();
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_006e39d0 : public FUN_006e3ab0, public FUN_00496910
{
    ~FUN_006e39d0();
};
// Destructor that calls Clear(true) on the object at this address.
// @fnv 0x006e39d0
FUN_006e39d0::~FUN_006e39d0()
{
    ((GlobalObject_00869f00*)this)->Clear(true);
}

struct EBase
{
    unsigned char ebasePad[8];
    virtual void vfn0();
    ~EBase();
};
struct PathingRequestMember94
{
    unsigned char data[4];
    ~PathingRequestMember94();
};
class FUN_006e2620 : public EBase
{
  public:
    PathingLocation m0c;
    PathingLocation m34;
    unsigned char pad5c[0x38];
    PathingRequestMember94 m94;
    ~FUN_006e2620();
};
// @fnv 0x006e2620
FUN_006e2620::~FUN_006e2620()
{}

struct BSSimpleArray_PathingAvoidNode_1024
{
    PathingAvoidNode* AllocateBuffer(unsigned int aiSizeInItem);
};

// Allocates a buffer of aiSizeInItem elements of 0x24 bytes each and returns the pointer.
// @fnv 0x006e3c10
PathingAvoidNode* BSSimpleArray_PathingAvoidNode_1024::AllocateBuffer(unsigned int aiSizeInItem)
{
    PathingAvoidNode* pBuffer = static_cast<PathingAvoidNode*>(operator new(aiSizeInItem * 0x24));
    return pBuffer;
}

extern "C" void* __cdecl Reallocate(void*, unsigned int);

struct FUN_006e3c40_shell
{
    void* __thiscall Reallocate_Thunk_006e3c40(void* apBuffer, unsigned int aiNewSizeInItem);
};

// @fnv 0x006e3c40
// src: GUESS 0x006e3c40 (confidence: medium)
void* __thiscall FUN_006e3c40_shell::Reallocate_Thunk_006e3c40(void* apBuffer, unsigned int aiNewSizeInItem)
{
    return Reallocate(apBuffer, aiNewSizeInItem * 0x24);
}

struct FUN_006dad70_shell : public PathingRequest
{
    void DestroyPathingRequest();
};

// @fnv 0x006dad70
void __thiscall FUN_006dad70_shell::DestroyPathingRequest()
{
    PathingRequest::~PathingRequest();
}

struct FUN_006e2b90
{
    void SetFlag(unsigned char value);
};

// @fnv 0x006e2b90
void FUN_006e2b90::SetFlag(unsigned char value)
{
    ((unsigned char*)this)[0x9e] = value;
}



// Exe 0x006e3230: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct PathingrequestOffset08View
{
    unsigned int GetFlags();
};

struct FUN_006dc890_Class
{
    void PathingAvoidNode_SaveGame(BGSSaveFormBuffer*);
};

struct FUN_006e3230_shell
{
    void PathingRequest_SaveGame(BGSSaveFormBuffer*);
};

// Serializes this object's fields and two embedded pathing locations into the save buffer, then saves each avoid node referenced at offset 0x94.
// @fnv 0x006e3230
// src: XBOX_PDB 0x006e3230
void FUN_006e3230_shell::PathingRequest_SaveGame(BGSSaveFormBuffer* buffer)
{
    unsigned int i;
    unsigned int isaveGameCount;
    PathingAvoidNode* avoidNode;

    reinterpret_cast<PathingLocation*>(reinterpret_cast<char*>(this) + 0x0c)->SaveGame(buffer);
    reinterpret_cast<PathingLocation*>(reinterpret_cast<char*>(this) + 0x34)->SaveGame(buffer);

    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x68), 4, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x6c), 4, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x70), 4, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x74), 4, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x78), 4, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x88), 4, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x8c), 4, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x99), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x98), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9a), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9b), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9c), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9d), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9f), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x90), 4, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa0), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa1), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x7c), 12, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa2), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa3), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa4), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa8), 4, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9e), 1, 0);
    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xac), 1, 0);

    i = reinterpret_cast<PathingAvoidPointerView*>(reinterpret_cast<char*>(this) + 0x94)->Get()
            ? reinterpret_cast<PathingrequestOffset08View*>(
                  reinterpret_cast<PathingAvoidPointerView*>(reinterpret_cast<char*>(this) + 0x94)->Get())
                  ->GetFlags()
            : 0;

    buffer->SaveVariableSizedValue(i);

    for (isaveGameCount = 0; isaveGameCount < i; ++isaveGameCount)
    {
        avoidNode = reinterpret_cast<PathingAvoidPointerView*>(reinterpret_cast<char*>(this) + 0x94)
                        ->Get()
                        ->BSSimpleArray_PathingAvoidNode_1024_GetAt(isaveGameCount);
        reinterpret_cast<FUN_006dc890_Class*>(avoidNode)->PathingAvoidNode_SaveGame(buffer);
    }
}

struct Base_006e26a0
{
    virtual void v00();
    int unk04;
    int unk08;

    Base_006e26a0();
    ~Base_006e26a0();
};


struct Member20_006e26a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    Member20_006e26a0();
};

struct Member18_006e26a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    Member18_006e26a0();
};

struct Member4_006e26a0
{
    int unk00;

    Member4_006e26a0(int aValue);
    ~Member4_006e26a0();
};

struct Owner_006e26a0
{
    void Attach(struct FUN_006e26a0* pChild);
};

struct FUN_006e26a0 : Base_006e26a0
{
    PathingLocation m_0C;
    PathingLocation m_34;
    Member20_006e26a0 m_5C;
    Member18_006e26a0 m_7C;
    Member4_006e26a0 m_94;

    FUN_006e26a0(Owner_006e26a0* owner);
    virtual void v00();
};

// Constructs the object with m_94 set to 0 and attaches it to the given owner.
// @fnv 0x006e26a0
FUN_006e26a0::FUN_006e26a0(Owner_006e26a0* owner) : m_94(0)
{
    owner->Attach(this);
}

struct PathingDebugOutput
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void __cdecl Print(unsigned int, unsigned int, const char*, ...);
};
struct PathingRequestDebugView : PathingRequest
{
    void PrintDebugInfo(PathingDebugOutput* output);
};
// Formats the request's origin, destination and pathing parameters into text and prints each line through the debug output.
// @fnv 0x006e2be0
void PathingRequestDebugView::PrintDebugInfo(PathingDebugOutput* output)
{
    char text[256];
    Origin.WriteDebugString(text, 256);
    output->Print(0, 1, "Origin: %s", text);
    Destination.WriteDebugString(text, 256);
    output->Print(0, 1, "Destination: %s", text);
    output->Print(0, 1, "Actor Radius: %f", m_fFirstValueAfterActorData);
    output->Print(0, 1, "Goal Z Delta: %f", PathingActorSpatialData);
    output->Print(0, 1, "Target Radius: %f", fWeaponSpread);
    output->Print(0, 1, "Allow Incomplete Path: %s", bAllowIncompletePath ? "true" : "false");
    if (m_fCenterRadius != 0.0)
        output->Print(0, 1, "Center Radius: (%.2f,%.2f,%.2f) %f", Center.x, Center.y, Center.z, m_fCenterRadius);
    output->Print(0, 1, "Face Target at Goal: %s", bFaceTargetAtGoal ? "true" : "false");
    if (bFaceTargetAtGoal)
        output->Print(0, 1, "Goal Angle: %f", m_fPathingRadius);
    if (m_bCanJump)
        output->Print(0, 1, "Initial Path Heading: %f", m_fAvoidanceRadius);
    output->Print(0, 1, "Allow Direct Path If Pathing Fails: %s", m_bCanClimb ? "true" : "false");
    output->Print(0, 1, "Using Curved path: %s", m_bCanUseDoors ? "true" : "false");
    output->Print(0, 1, "Ignoring Locks: %s", bIgnoreLocks ? "true" : "false");
    output->Print(0, 1, "Pathsmoothing retry count: %i", m_iRequestType);
}
