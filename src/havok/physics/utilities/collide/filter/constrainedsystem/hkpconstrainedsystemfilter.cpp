
// src/havok/physics/utilities/collide/filter/constrainedsystem/hkpconstrainedsystemfilter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/collide/filter/constrainedsystem/hkpconstrainedsystemfilter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkpCollidable.h"
#include "../../../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../../../include/hkpCollisionFilter.h"
#include "../../../../../../../include/hkpConstraintData.h"
#include "../../../../../../../include/hkpConstraintInstance.h"
#include "../../../../../../../include/hkpEntity.h"

extern int g_unk0126d658;

// @fnv 0x00dffaf0
// src: GUESS 0x00dffaf0 (confidence: low)
void* __cdecl hkpConstrainedSystemFilter_GetUnk0126d658Address()
{
    return &g_unk0126d658;
}

struct FnvCpu_FUN_00dffb00_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00dffb00_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00dffb00_CpuAllocator* allocator;
};
FnvCpu_FUN_00dffb00_CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00dffb00_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void UpdateFields_00e46b80();
    FnvCpu_FUN_00dffb00_CpuObject* FUN_00dffb00(unsigned int flags);
};
// Calls FUN_00e46b80, then if bit 0 of flags is set, invokes the allocator's Invoke on this with size, and returns this.
// @fnv 0x00dffb00
FnvCpu_FUN_00dffb00_CpuObject* FnvCpu_FUN_00dffb00_CpuObject::FUN_00dffb00(unsigned int flags)
{
    UpdateFields_00e46b80();
    if (flags & 1)
    {
        FnvCpu_FUN_00dffb00_CpuAllocatorHolder* pAllocatorHolder = hkMemoryRouter_getInstance();
        pAllocatorHolder->allocator->Invoke(this, size);
    }
    return this;
}

// Keep the original inline owner calculation when using the shared collidable layout.
inline void* hkpCollidable::getOwner() const
{
    return const_cast<char*>(reinterpret_cast<const char*>(this)) + m_iOwnerOffset;
}

class hkpEntity;

inline hkpEntity* getRigidBodyForConstraintFilter(const hkpCollidable* pkCollidable)
{
    if (pkCollidable->m_kBroadPhaseHandle.m_type == 1)
        return static_cast<hkpEntity*>(pkCollidable->getOwner());
    return 0;
}

// The shared hkpEntity header lacks the constraint accessors bound at 0x00c9c380/0x00c9c3c0.

// This entry receives the +0x08 collidable-filter subobject: m_otherFilter is +0x2c here, +0x34 in hkpConstrainedSystemFilter; hkpConstraintCollisionFilter instead derives from hkpPairCollisionFilter.
class ConstrainedSystemCollidableFilterView
{
  public:
    char unk00[0x2c];
    hkpCollisionFilter* m_pChildFilter;

    hkBool IsCollisionEnabled(const hkpCollidable& a, const hkpCollidable& b) const throw();
};

// Returns false if the collidable filter rejects the pair or a non-type-11 constraint links the two rigid bodies; true otherwise.
// @fnv 0x00e46bf0
hkBool ConstrainedSystemCollidableFilterView::IsCollisionEnabled(const hkpCollidable& a,
                                                                const hkpCollidable& b) const throw()
{
    hkpEntity* pkBodyA = getRigidBodyForConstraintFilter(&a);
    hkpEntity* pkBodyB = getRigidBodyForConstraintFilter(&b);

    // The collidable-filter interface follows the referenced-object base at +0x08.
    if (m_pChildFilter &&
        !reinterpret_cast<const hkpCollidableCollidableFilter*>(
            reinterpret_cast<const char*>(m_pChildFilter) + sizeof(hkReferencedObject))->IsCollisionEnabled(a, b))
        return false;

    if (!pkBodyA || !pkBodyB)
        return true;

    const bool bSwapBodies = pkBodyA->getNumConstraints() > pkBodyB->getNumConstraints();
    hkpEntity* pkEntityA = bSwapBodies ? pkBodyB : pkBodyA;
    hkpEntity* pkEntityB = bSwapBodies ? pkBodyA : pkBodyB;

    int numConstraints = pkEntityA->getNumConstraints();
    for (int i = 0; i < numConstraints; i++)
    {
        const hkpConstraintInstance* pkConstraint =
            reinterpret_cast<const hkpConstraintInstance*>(pkEntityA->GetEntryAt(i));
        if (pkConstraint && pkConstraint->m_data->getType() != 11)
        {
            if (pkConstraint->m_kActorEntries[0] == pkEntityB || pkConstraint->m_kActorEntries[1] == pkEntityB)
                return false;
        }
    }
    return true;
}

struct CheckInterface
{
    virtual void unused();
    virtual unsigned char* evaluate(int*, int, int, int, int, int);
};
struct FilterDelegate
{
    int unk00;
    int unk04;
    int unk08;
    CheckInterface callback;
};
struct ConstraintFilter
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    FilterDelegate* delegate;
    hkBool Evaluate(int, int, int, int, int);
};
// @fnv 0x00e46cf0
hkBool ConstraintFilter::Evaluate(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5)
{
    FilterDelegate* const& ref = delegate;
    return hkBool(ref == 0 || *delegate->callback.evaluate(&aiArg5, aiArg1, aiArg2, aiArg3, aiArg4, aiArg5) != 0);
}

class hkFilterE46D
{
  public:
    virtual void V0();
    virtual hkBool IsCollisionEnabled(void* a, void* b);
};

struct hkWorldE46D
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkFilterE46D m_iFilter;
};

class hkObjE46D
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkWorldE46D* m_pOwningWorld;

    hkBool IsInWorldFilter(void* a, void* b);
};

// Returns true if the object has no world or its world's filter accepts the two arguments.
// @fnv 0x00e46df0
hkBool hkObjE46D::IsInWorldFilter(void* a, void* b)
{
    return !m_pOwningWorld || m_pOwningWorld->m_iFilter.IsCollisionEnabled(a, b).m_cBooleanValue;
}

class hkBase0E46C
{
  public:
    virtual ~hkBase0E46C();
    int unk04[2];
};

class hkFilterE46C
{
  public:
    virtual hkBool IsCollisionEnabled(const void* a, const void* b, const void* c, const void* d, const void* e,
                                          const void* f, const void* g) const;
};

class hkFilterImplE46C : public hkBase0E46C, public hkFilterE46C
{
};

class hkListE46C
{
  public:
    int unk00[10];
    hkFilterImplE46C* m_iFilter;

    hkBool hkpConstrainedSystemFilter_isCollisionEnabled(const void* a, const void* b, const void* c, const void* d, const void* e, const void* f,
                            const void* g) const;
};

// Returns true when m_iFilter is null or when m_iFilter->IsCollisionEnabled(a, b, c, d, e, f, g) is true.
// @fnv 0x00e46d40
// src: HAVOK_LIB 0x00e46d40
hkBool hkListE46C::hkpConstrainedSystemFilter_isCollisionEnabled(const void* a, const void* b, const void* c, const void* d, const void* e,
                                    const void* f, const void* g) const
{
    return !m_iFilter || m_iFilter->IsCollisionEnabled(a, b, c, d, e, f, g);
}

namespace fnv_00e46da0 {
class hkBase0E46D
{
  public:
    virtual ~hkBase0E46D();
    int unk04[3];
};

class hkFilterE46D
{
  public:
    virtual hkBool IsCollisionEnabled(const void* a, const void* b, const void* c, const void* d) const;
};

class hkFilterImplE46D : public hkBase0E46D, public hkFilterE46D
{
};

class hkListE46D
{
  public:
    int unk00[9];
    hkFilterImplE46D* m_iFilter;

    hkBool hkpConstrainedSystemFilter_isCollisionEnabled_00e46da0(const void* a, const void* b, const void* c, const void* d) const;
};

// Returns true when m_iFilter is null or when m_iFilter->IsCollisionEnabled(a, b, c, d) is true.
// @fnv 0x00e46da0
// src: HAVOK_LIB 0x00e46da0
hkBool hkListE46D::hkpConstrainedSystemFilter_isCollisionEnabled_00e46da0(const void* a, const void* b, const void* c, const void* d) const
{
    return !m_iFilter || m_iFilter->IsCollisionEnabled(a, b, c, d);
}
}  // namespace fnv_00e46da0

int __cdecl CallA(void*, void*);
void __cdecl CallB(void*);
// If the owner at +0xc has type other than 11, calls CallA with the +0x10 offsets of the pointers at +0x14 and +0x18, and passes a nonzero result to CallB.
// @fnv 0x00e46e30
// src: HAVOK_LIB 0x00e46e30
void __stdcall hkpConstrainedSystemFilter_constraintAddedCallback(void* p)
{
    hkpConstraintData* owner = *reinterpret_cast<hkpConstraintData**>(reinterpret_cast<char*>(p) + 0xc);
    if (owner->getType() != 11)
    {
        void* b = *reinterpret_cast<void**>(reinterpret_cast<char*>(p) + 0x18);
        void* a = *reinterpret_cast<void**>(reinterpret_cast<char*>(p) + 0x14);
        void* obj =
            reinterpret_cast<char*>(CallA(reinterpret_cast<char*>(a) + 0x10, reinterpret_cast<char*>(b) + 0x10));
        if (obj)
            CallB(obj);
    }
}

// @fnv 0x00e46e70
// src: COMMUNITY 0x00e46e70
void __stdcall nullsub_88(int a)
{}

// Adjustor thunk for FUN_00dffb30: "sub ecx, 8; jmp FUN_00dffb00".
//
// MSVC "this adjusting thunk" emitted for a virtual inherited from a secondary
// base: it moves the secondary-base sub-object pointer back to the derived
// object pointer (sub ecx, 8) and tail jumps to the final overrider.
//
// The subtracted offset is the size of the primary base, so the primary base is
// a vtable pointer plus one int member (4 + 4 = 8). Both bases declare the same
// virtual function; the derived class redeclares it and defines only its
// constructor, which is what makes the compiler emit the vtables and the thunk.
struct PrimaryBase
{
    virtual void FUN_00dffb30();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00dffb30();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dffb30
    virtual void FUN_00dffb30();
};

Derived::Derived()
{}

namespace fnv_00dffb40 {
// sub ecx,0xc; jmp target  ==  MSVC adjustor thunk for FUN_00dffb40.
// PrimaryBase is vptr + two int fields (size 0xc); SecondaryBase only declares the virtual.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00dffb40();
    int unk04;
    int unk08;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00dffb40();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dffb40
// src: GUESS 0x00dffb40 (confidence: low)
    virtual void AdjustThisAndForward_00dffb40();
};

Derived::Derived()
{}
}  // namespace fnv_00dffb40

// Adjustor thunk: the secondary-base (+0x10) vtable entry for an override defined on the derived class.

class DFFB50Primary
{
  public:
    virtual void FUN_00dffb50();
    int unk04;
    int unk08;
    int unk0C;
};

class DFFB50Secondary
{
  public:
    virtual void FUN_00dffb50();
};

class DFFB50Listener : public DFFB50Primary, public DFFB50Secondary
{
  public:
    DFFB50Listener();
// @fnv 0x00dffb50
    virtual void FUN_00dffb50();
};

DFFB50Listener::DFFB50Listener()
{}

// FUN_00dffb60 : MSVC this-adjusting thunk  (sub ecx, 0x30 ; jmp <impl>)
struct A1_00dffb60
{
    A1_00dffb60();
    virtual void AdjustThisAndForward_00dffb60();
    char pad[0x2c];
};
struct A2_00dffb60
{
    A2_00dffb60();
    virtual void AdjustThisAndForward_00dffb60();
};
struct Own_00dffb60 : A1_00dffb60, A2_00dffb60
{
    Own_00dffb60();
    virtual void key_fn();
// @fnv 0x00dffb60
// src: GUESS 0x00dffb60 (confidence: low)
    void AdjustThisAndForward_00dffb60();
};
Own_00dffb60::Own_00dffb60()
{}
void Own_00dffb60::key_fn()
{}
Own_00dffb60* make_00dffb60()
{
    static Own_00dffb60 o;
    return &o;
}

namespace fnv_00dffb70 {
// sub ecx,0x14; jmp FUN_00dffb00
// MSVC adjustor thunk: a class derives from two bases that both declare the same
// virtual, so the secondary base's vtable entry is an adjustor thunk that moves
// `this` back by the size of the primary base (0x14 = vptr + four int fields).
struct PrimaryBase
{
    virtual void FUN_00dffb70();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00dffb70();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dffb70
    virtual void FUN_00dffb70();
};

Derived::Derived()
{}
}  // namespace fnv_00dffb70
