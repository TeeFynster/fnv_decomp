#include "../../../../../include/hkArray.h"

// src/havok/physics/dynamics/action/hkpunaryaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/action/hkpunaryaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkpEntity.h"
#include "../../../../../include/hkpWorld.h"
#include "../../../../../include/hkpUnaryAction.h"

// The shared world header does not yet declare the action-removal operation.
class UnaryActionWorld : public hkpWorld
{
public:
    void RemoveAction(hkpAction* action);
};

struct FUN_00d2b1f0
{
    char m0[8];
    hkpWorld* m1;
    void EntityRemovedCallback(int);
};

// @fnv 0x00d2b1f0
void FUN_00d2b1f0::EntityRemovedCallback(int)
{
    if (m1)
        static_cast<UnaryActionWorld*>(m1)->RemoveAction(reinterpret_cast<hkpAction*>(this));
}

extern int DAT_010cc2fc;
extern int DAT_010ce528;
extern int _DAT_0102e388;

struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};

struct FUN_00d2b2b0_class
{
    void* vptr;
    unsigned char padding[0x10];
    S_00d49310_Lock lock;
    hkpEntity* entity;

    void ReleaseReference_00d2b2b0();
};

// Resets the vtable, releases the entity reference if present, then destroys the lock and resets the vtable again.
// @fnv 0x00d2b2b0
// src: GUESS 0x00d2b2b0 (confidence: medium)
void FUN_00d2b2b0_class::ReleaseReference_00d2b2b0()
{
    vptr = &DAT_010ce528;

    if (entity)
    {
        entity->removeReference();
        entity = 0;
    }

    vptr = &DAT_010cc2fc;
    lock.~S_00d49310_Lock();
    vptr = &_DAT_0102e388;
}

void ReleaseReference_00d2b2b0();
hkMemoryRouter* _D1A0E0GetMemoryRouter();

struct Action
{
    virtual void FUN_00d4d950_2() = 0;
    unsigned short size;

    Action* FUN_00d4d950(unsigned char flags);
};

// Calls FUN_00d2b2b0, then if flags bit 0 is set frees this via the memory router's memory manager, and returns this.
// @fnv 0x00d4d950
Action* Action::FUN_00d4d950(unsigned char flags)
{
    ReleaseReference_00d2b2b0();

    if (flags & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        router->m_heap->blockFree(this, size);
    }

    return this;
}

class UnaryActionHelper : public hkpUnaryAction
{
  public:
    void SetEntity(hkpEntity* entity);
};

// @fnv 0x00d2b210
void UnaryActionHelper::SetEntity(hkpEntity* entity)
{
    if (m_pEntity)
    {
        if (hkpWorld* world = m_pOwningWorld)
        {
            world->RemoveActionFromEntity(this, m_pEntity);
        }
        m_pEntity->removeReference();
        m_pEntity = 0;
    }
    m_pEntity = entity;
    m_pEntity->RetainReference();
    if (hkpWorld* world = m_pOwningWorld)
    {
        world->hkpWorld_attachActionToEntity(this, m_pEntity);
    }
}

struct FUN_00cb0a60_Field
{
    unsigned int value;
    void initialize();
};
struct FUN_00d2b260
{
    void* vptr;
    unsigned short memSizeAndFlags;
    short referenceCount;
    void* world;
    void* island;
    unsigned int userData;
    FUN_00cb0a60_Field name;
    hkpEntity* entity;
    FUN_00d2b260(hkpEntity* entity, unsigned int userData);
};
// @fnv 0x00d2b260
FUN_00d2b260::FUN_00d2b260(hkpEntity* apEntity, unsigned int auiUserData)
{
    referenceCount = 1;
    userData = auiUserData;
    vptr = &DAT_010cc2fc;
    world = 0;
    island = 0;
    name.initialize();
    vptr = &DAT_010ce528;
    entity = apEntity;
    if (apEntity)
        apEntity->RetainReference();
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T> __forceinline void constructWithCopyXd2b2f0(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
static __forceinline void hkArrayXd2b2f0_AddBack(hkArrayBase<T>& self, const T& t)
{
        hkMemoryRouter& router = hkMemoryRouter_getInstance();
        if (self.m_iElementCount == self.getCapacity())
            ResizeAudioStream(router.m_heap, (&self), sizeof(T));
        constructWithCopyXd2b2f0(self.m_data + self.m_iElementCount, 1, t);
        self.m_iElementCount++;
    }

class hkObjXd2b2f0
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_uiFilterValue;

    void AppendPointer(hkArrayBase<void*>& kArray);
};

// Appends the object's stored pointer to the given array.
// @fnv 0x00d2b2f0
void hkObjXd2b2f0::AppendPointer(hkArrayBase<void*>& kArray)
{
    hkArrayXd2b2f0_AddBack(kArray, m_uiFilterValue);
}
