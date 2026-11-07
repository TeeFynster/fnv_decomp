
// src/havok/physics/utilities/deprecated/disableentity/hkpdisableentitycollisionfilter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/deprecated/disableentity/hkpdisableentitycollisionfilter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkpCollidable.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../../include/hkpShapeCollectionFilter.h"
#include "../../../../../../include/hkpRayShapeCollectionFilter.h"
#include "../../../../../../include/hkpRayCollidableFilter.h"
#include "../../../../../../include/hkpEntity.h"
#include "../../../../../../include/hkpEntityListener.h"
#include "../../../../../../include/hkpRigidBody.h"

// Retained locally: the shared header omits the +0x24..+0x2f storage, so
// MSVC places a derived entity-listener base at +0x24 instead of +0x30.
// local form of hkpCollisionFilter: 0x00e467d0/0x00e46820 need the post-type padding so derived filter members retain their exe offsets (shared form differs by 2/5 bytes).
class __declspec(align(16)) CollisionFilterBaseLocal_00e467d0 : public hkReferencedObject,
                                             public hkpCollidableCollidableFilter,
                                             public hkpShapeCollectionFilter,
                                             public hkpRayShapeCollectionFilter,
                                             public hkpRayCollidableFilter
{
  public:
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& input,
                                      const hkpCdBody& a, const hkpCdBody& b,
                                      const hkpShapeContainer& bContainer,
                                      hkpShapeKey bKey) const = 0;
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& input,
                                      const hkpCdBody& a, const hkpCdBody& b,
                                      const hkpShapeContainer& aContainer,
                                      const hkpShapeContainer& bContainer,
                                      hkpShapeKey aKey, hkpShapeKey bKey) const = 0;

    unsigned int m_prepad0;
    unsigned int m_prepad1;
    unsigned int m_type;
    unsigned int m_uiPostTypePadding[3];
};

// No approved include/ header exists for this class yet.
class hkpDisableEntityCollisionFilter : public CollisionFilterBaseLocal_00e467d0, public hkpEntityListener
{
  public:
    virtual ~hkpDisableEntityCollisionFilter() throw();
    virtual hkBool IsCollisionEnabled(const hkpCollidable& a, const hkpCollidable& b) const;
    virtual void EntityRemovedCallback(hkpEntity* entity);
    hkBool removeEntity(hkpEntity* entity);
    void* DeleteInstance(unsigned char flags);

    hkArray<hkpEntity*> m_kDisabledEntities;
};

// @fnv 0x00e467b0
// src: GUESS 0x00e467b0 (confidence: low)
void __stdcall hkpDisableEntityCollisionFilter_UpdateState_00e467b0(char* flag, int a, int b)
{
    *flag = 1;
}

// @fnv 0x00e46780
// src: GUESS 0x00e46780 (confidence: low)
void __stdcall Object_UpdateFields_00e46780(unsigned char* flag, int p2, int p3, int p4, int p5, int p6)
{
    *flag = 1;
}

// @fnv 0x00e46790
// src: GUESS 0x00e46790 (confidence: low)
void __stdcall hkpDisableEntityCollisionFilter_UpdateState_00e46790(char* flag, int a, int b, int c, int d)
{
    *flag = 1;
}

// @fnv 0x00e467a0
// src: GUESS 0x00e467a0 (confidence: low)
void __stdcall Object_UpdateFields_00e467a0(char* flag, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    *flag = 1;
}

void* __cdecl hkMemoryRouter_getInstance(void);

struct FUN_00dff930_Alloc
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08(void* p, int n);
};

struct FUN_00dff930_Mgr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00dff930_Alloc* m_10;
};

// @fnv 0x00dff930
void* hkpDisableEntityCollisionFilter::DeleteInstance(unsigned char uiFlags)
{
    this->hkpDisableEntityCollisionFilter::~hkpDisableEntityCollisionFilter();
    if (uiFlags & 1)
    {
        FUN_00dff930_Mgr* mgr = reinterpret_cast<FUN_00dff930_Mgr*>(hkMemoryRouter_getInstance());
        mgr->m_10->slot08(this, m_usMemSizeAndFlags);
    }
    return this;
}

// Empty function that takes an unsigned int argument and does nothing.
// @fnv 0x00e467c0
// src: COMMUNITY 0x00e467c0
void __stdcall nullsub_87(unsigned int a1)
{}

// 0x00e467d0 uses this at the +0x08 collidable-filter base: its +0x2c array is the complete object's +0x34 disabled entities.
// @fnv 0x00e467d0
hkBool hkpDisableEntityCollisionFilter::IsCollisionEnabled(const hkpCollidable& kA, const hkpCollidable& kB) const
{
    for (int i = 0; i < m_kDisabledEntities.GetLogicalSize(); i++)
    {
        const hkpCollidable* pkCollidable = &m_kDisabledEntities[i]->m_kCollidable;
        if (pkCollidable == &kA || pkCollidable == &kB)
            return false;
    }
    return true;
}

// Remove the entity by swapping in the last element; return whether it was found.
// @fnv 0x00e46820
hkBool hkpDisableEntityCollisionFilter::removeEntity(hkpEntity* entity)
{
    if (!entity)
    {
        return false;
    }
    for (int index = 0; index < m_kDisabledEntities.m_iElementCount; ++index)
    {
        if (m_kDisabledEntities.m_data[index] == entity)
        {
            volatile int& count = m_kDisabledEntities.m_iElementCount;
            --count;
            int last = count;
            if (last != index)
                m_kDisabledEntities.m_data[index] = m_kDisabledEntities.m_data[last];
            return true;
        }
    }
    return false;
}

// Remove the disabled entity, then unregister this entity listener.
// @fnv 0x00e46880
void hkpDisableEntityCollisionFilter::EntityRemovedCallback(hkpEntity* entity)
{
    if (entity)
    {
        removeEntity(entity);
        entity->removeEntityListener(this);
    }
}

// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00dff960();
    int unk04;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00dff960();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dff960
// src: GUESS 0x00dff960 (confidence: low)
    virtual void AdjustThisAndForward_00dff960();
};

Derived::Derived()
{}

namespace fnv_00dff970 {
// sub ecx,0xc; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0xc).
struct PrimaryBase
{
    virtual void FUN_00dff970();
    int unk04;
    int unk08;
};

struct SecondaryBase
{
    virtual void FUN_00dff970();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dff970
    virtual void FUN_00dff970();
};

Derived::Derived()
{}
}  // namespace fnv_00dff970

namespace fnv_00dff980 {
struct Base1
{
    virtual void AdjustThisAndForward_00dff980();
    int unk04;
    int unk08;
    int unk0C;
};
struct Base2
{
    virtual void AdjustThisAndForward_00dff980();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x00dff980
// src: GUESS 0x00dff980 (confidence: low)
    virtual void AdjustThisAndForward_00dff980();
};
Derived::Derived()
{}
}  // namespace fnv_00dff980

namespace fnv_00dff990 {
// sub ecx,0x30; jmp target == MSVC adjustor thunk (Derived overrides a virtual both bases declare).
struct PrimaryBase
{
    virtual void FUN_00dff990();
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
};

struct SecondaryBase
{
    virtual void FUN_00dff990();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dff990
    virtual void FUN_00dff990();
};

Derived::Derived()
{}
}  // namespace fnv_00dff990

namespace fnv_00dff9a0 {
// Adjustor thunk for FUN_00dff9a0: "sub ecx, 0x14; jmp FUN_00dff930".
//
// This is the MSVC "this adjusting thunk" emitted for a virtual function
// inherited from a secondary base: it moves the secondary-base sub-object
// pointer back to the derived object pointer (sub ecx, 0x14) and tail jumps to
// the final overrider.
//
// The subtracted offset is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 4 int members (4 + 4 * 4 = 0x14).
// Both bases declare the same virtual function; the derived class redeclares
// it and defines only its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00dff9a0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00dff9a0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dff9a0
// src: GUESS 0x00dff9a0 (confidence: low)
    virtual void AdjustThisAndForward_00dff9a0();
};

Derived::Derived()
{}
}  // namespace fnv_00dff9a0
