
// src/havok/physics/utilities/visualdebugger/viewer/utilities/hkpmousepickingviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/utilities/hkpmousepickingviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkProcessFactory.h"
#include "../../../../../../../include/hkpCollidable.h"
#include "../../../../../../../include/hkpEntity.h"
#include "../../../../../../../include/hkpUnaryAction.h"
#include "../../../../../../../include/hkpWorld.h"
#include "../../../../../../../include/hkpMouseSpringAction.h"
#include "../../../../../../../include/hkpWorldViewerBase.h"

// Aligned scratch storage avoids calling hkVector4's out-of-line constructor.
typedef __declspec(align(16)) double VectorStorage[2];

extern "C" void* DAT_011b5ff0;

// @fnv 0x00d66bd0
// src: HAVOK_LIB 0x00d66bd0
void __stdcall hkpMousePickingViewer_getConsumableCommands(void** pOut, void** pCount)
{
    *pOut = &DAT_011b5ff0;
    *pCount = (void*)3;
}

struct FUN_00d66c10_class
{
    void RemoveAmbientLight();
};

struct FUN_00d66cb0_class
{
    int m0;
    int m4;
    int m8;
    void hkpMousePickingViewer_worldRemovedCallback(int a);
};

// @fnv 0x00d66cb0
// src: HAVOK_LIB 0x00d66cb0
void FUN_00d66cb0_class::hkpMousePickingViewer_worldRemovedCallback(int aiValue)
{
    if (aiValue == *(int*)((char*)this + 8))
        ((FUN_00d66c10_class*)((char*)this - 0x20))->RemoveAmbientLight();
}

extern int DAT_010d1cb4;
extern int DAT_010d1cc4;
extern int DAT_010d1ce4;
// The approved base header does not yet declare its context constructor.
extern "C" void ConstructWorldViewerBase();
typedef void (__thiscall* WorldViewerBaseConstructor)(hkpWorldViewerBase*, const void*);

namespace FUN_00d66cd0 {
class hkpMousePickingViewer : public hkpWorldViewerBase
{
  public:
    virtual ~hkpMousePickingViewer() throw();
    __declspec(noinline) hkpMousePickingViewer* Initialize(int contexts);
    void hkpMousePickingViewer_releaseObject() throw();

    hkpPhysicsContext* m_iValueAtOffset0C;
    unsigned int unk20;
    float m_fMaxRelativeForce;
};

// @fnv 0x00d66b90
hkpMousePickingViewer* hkpMousePickingViewer::Initialize(int contexts)
{
    reinterpret_cast<WorldViewerBaseConstructor>(&ConstructWorldViewerBase)(this, (const void*)contexts);
    m_fMaxRelativeForce = 1000.0f;
    m_iValueAtOffset0C = 0;
    unk20 = 0;
    *(int*)this = (int)&DAT_010d1ce4;
    *(int*)((char*)this + 8) = (int)&DAT_010d1cc4;
    *(int*)((char*)this + 0x20) = (int)&DAT_010d1cb4;
    return this;
}
}

extern int DAT_01269cd0;
extern int DAT_01268ff8;
void __cdecl hkpMousePickingViewer_create();
// @fnv 0x00d66c90
void* __cdecl RegisterMousePicking()
{
    DAT_01268ff8 = (int)((hkProcessFactory*)DAT_01269cd0)->RegisterProcess("Mouse Picking", (void*)hkpMousePickingViewer_create);
    return (void*)DAT_01268ff8;
}

extern int DAT_01268ff8;

// @fnv 0x00d66ed0
// src: GUESS 0x00d66ed0 (confidence: low)
int __cdecl Hkpmousepickingviewer_GetDAT01268ff8()
{
    return DAT_01268ff8;
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
// @fnv 0x00d66c50
// src: XBOX_PDB 0x00d66c50
void* __cdecl hkpMousePickingViewer_create(unsigned int value)
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    FUN_00d66cd0::hkpMousePickingViewer* block = static_cast<FUN_00d66cd0::hkpMousePickingViewer*>(
        holder->m_heap->blockAlloc(sizeof(FUN_00d66cd0::hkpMousePickingViewer)));
    block->m_usMemSizeAndFlags = sizeof(FUN_00d66cd0::hkpMousePickingViewer);
    block = block->Initialize(value);
    if (block)
        return reinterpret_cast<char*>(block) + 8;
    return 0;
}

namespace fnv_00d66d00 {
typedef unsigned __int64 hkUint64D66D;

extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

// These entry points are absent from the shared class declarations.
extern "C" void ConstructMouseSpringAction();
extern "C" void SetMouseSpringMaxRelativeForce();
extern "C" void AddMouseSpringAction();

typedef hkpMouseSpringAction* (__thiscall* MouseSpringConstructor)(hkpMouseSpringAction*, const hkVector4&,
    const hkVector4&, float, float, float, hkpEntity*, void*);
typedef void (__thiscall* MouseSpringForceSetter)(hkpMouseSpringAction*, float);
typedef void (__thiscall* WorldActionAdder)(hkpWorld*, hkpMouseSpringAction*);

static __forceinline hkMemoryAllocator& MouseSpringHeap(hkMemoryRouter* holder)
{
    return *holder->m_heap;
}

static __forceinline void* AllocateMouseSpringStorage(unsigned int size)
{
    void* memory = MouseSpringHeap(hkMemoryRouter_getInstance()).blockAlloc(size);
    static_cast<unsigned short*>(memory)[2] = static_cast<unsigned short>(size);
    return memory;
}

struct MousePickD66D
{
    char m_acUnk00[0x28];
    hkpWorld* m_pkWorld;
    hkpMouseSpringAction* m_pkMouseSpring;
    float m_fMaxRelativeForce;
    hkBool PickEntity(hkUint64D66D uiUserData, const hkVector4& kPositionInWorld);
};

// Validates the user data as a collidable, stores its entity's world, and creates and adds a mouse spring action for the entity.
// @fnv 0x00d66d00
hkBool MousePickD66D::PickEntity(hkUint64D66D uiCollidableUserData, const hkVector4& kPositionInWorld)
{
    hkUint64D66D uiUserDataTag = uiCollidableUserData & 3;
    if (uiUserDataTag == 3)
        uiCollidableUserData &= ~(hkUint64D66D)3;
    else if (uiUserDataTag != 0)
        return false;
    hkpCollidable* pkCollidable = (hkpCollidable*)(unsigned int)uiCollidableUserData;
    if (pkCollidable->m_kBroadPhaseHandle.m_type == 1)
    {
        hkpEntity* pkEntity = (hkpEntity*)((char*)pkCollidable + pkCollidable->m_iOwnerOffset);
        if (pkEntity)
        {
            m_pkWorld = static_cast<hkpWorld*>(pkEntity->m_pOwningWorld);
            if (*reinterpret_cast<const unsigned char*>(&pkEntity->m_pMotionState.m_type) != 5 && pkEntity->m_pOwningWorld == m_pkWorld)
            {
                VectorStorage positionStorage;
                hkVector4& kPositionInRbLocal = *reinterpret_cast<hkVector4*>(&positionStorage);
                kPositionInRbLocal.hkVector4_setTransformedInversePos(pkEntity->m_pMotionState.m_kMotionState.m_kMotionTransform, kPositionInWorld);
                hkpMouseSpringAction* spring = static_cast<hkpMouseSpringAction*>(
                    AllocateMouseSpringStorage(sizeof(hkpMouseSpringAction)));
                m_pkMouseSpring = reinterpret_cast<MouseSpringConstructor>(&ConstructMouseSpringAction)(
                    spring, kPositionInRbLocal, kPositionInWorld, 0.5f, 0.3f, 0.95f, pkEntity, 0);
                reinterpret_cast<MouseSpringForceSetter>(&SetMouseSpringMaxRelativeForce)(m_pkMouseSpring, m_fMaxRelativeForce);
                reinterpret_cast<WorldActionAdder>(&AddMouseSpringAction)(m_pkWorld, m_pkMouseSpring);
            }
        }
    }
    return true;
}
}  // namespace fnv_00d66d00

struct Derived;

struct Stream
{
    void readQuadVector4(void* vec);
    int hkIArchive_readArrayGeneric(void* buf, int size, int count);
    char* GetStreamResult(char* buf);
};

struct Base2
{
    void* vptr;
    int unk04;
    Stream* stream;
    Derived* getDerived()
    {
        return (Derived*)((char*)this - 8);
    }
    void hkpMousePickingViewer_consumeCommand(unsigned char type);
};

struct Derived
{
    void hkpMousePickingViewer_releaseObject();
    void DispatchToChild(void* vec);
    void PickEntity(char* str, int a, int b, void* vec);
};

struct Buf4
{
    char b0, b1, b2, b3;
};

// @fnv 0x00d66e10
// src: HAVOK_LIB 0x00d66e10
void Base2::hkpMousePickingViewer_consumeCommand(unsigned char type)
{
    Buf4 buf;
    union
    {
        VectorStorage b1_vec;
        struct
        {
            int pair0;
            int pair1;
            VectorStorage vec;
        } b0;
    } u;

    switch (type)
    {
    case 0xb2:
        getDerived()->hkpMousePickingViewer_releaseObject();
        return;
    case 0xb1: {
        stream->readQuadVector4(&u.b1_vec);
        if (stream->GetStreamResult(&buf.b1)[0])
        {
            getDerived()->DispatchToChild(&u.b1_vec);
        }
        return;
    }
    case 0xb0: {
        stream->readQuadVector4(&u.b0.vec);
        stream->hkIArchive_readArrayGeneric(&u.b0.pair0, 8, 1);
        if (stream->GetStreamResult(&buf.b2)[0])
        {
            getDerived()->PickEntity(&buf.b3, u.b0.pair0, u.b0.pair1, &u.b0.vec);
        }
        break;
    }
    default:
        break;
    }
}

namespace fnv_00d66f00 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00d66f00_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00d66cd0();
    FnvCpu_FUN_00d66f00_CpuObject* FUN_00d66f00(unsigned int flags);
};
// Calls FUN_00d66cd0, then if flags bit 0 is set, invokes the allocator from FUN_00c85750 on this with size, and returns this.
// @fnv 0x00d66f00
FnvCpu_FUN_00d66f00_CpuObject* FnvCpu_FUN_00d66f00_CpuObject::FUN_00d66f00(unsigned int flags)
{
    FUN_00d66cd0();
    if (flags & 1)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        holder->m_heap->blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00d66f00

extern "C" void RemoveMouseSpringAction();
typedef void (__thiscall* WorldActionRemover)(hkpWorld*, hkpUnaryAction*);

class FUN_00d66c10_cls
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    hkpWorld* m_pOwningWorld;
    hkpUnaryAction* m_pEntity;

    void hkpMousePickingViewer_releaseObject();
};

// @fnv 0x00d66c10
// src: HAVOK_LIB 0x00d66c10
void FUN_00d66c10_cls::hkpMousePickingViewer_releaseObject()
{
    if (m_pEntity)
    {
        if (m_pEntity->m_pOwningWorld)
        {
            reinterpret_cast<WorldActionRemover>(&RemoveMouseSpringAction)(m_pOwningWorld, m_pEntity);
            m_pEntity->m_pEntity->activate_00c9c1d0();
            m_pEntity->removeReference();
        }
        else
        {
            m_pEntity->removeReference();
        }
        m_pEntity = 0;
    }
    m_pOwningWorld = 0;
}

namespace FUN_00d66cd0 {
// @fnv 0x00d66cd0
hkpMousePickingViewer::~hkpMousePickingViewer() throw()
{
    hkpMousePickingViewer_releaseObject();
}
}

namespace fnv_00d66ee0 {
// sub ecx,0x20; jmp target: MSVC adjustor thunk for the secondary base (PrimaryBase is 0x20 bytes).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00d66ee0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00d66ee0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d66ee0
// src: GUESS 0x00d66ee0 (confidence: low)
    virtual void AdjustThisAndForward_00d66ee0();
};

Derived::Derived()
{}
}  // namespace fnv_00d66ee0

namespace fnv_00d66ef0 {
// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00d66ef0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d66ef0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d66ef0
    virtual void FUN_00d66ef0();
};

Derived::Derived()
{}
}  // namespace fnv_00d66ef0
