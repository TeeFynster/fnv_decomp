// src/havok/physics/utilities/serialize/hkpphysicsdata_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/serialize/hkpphysicsdata.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/utilities/serialize/hkpphysicsdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkpphysicsdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkpPhysicsData.h"
#include "../../../../../include/hkpPhysicsSystem.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkThreadMemory.h"
#include "../../../../../include/hkpWorld.h"
int __cdecl CompareStringsCaseInsensitive(int, int);
struct FUN_00d4c000
{
    int m_00;
    int m_04;
    int m_08;
    int* m_0c;
    int m_10;
    int Method(int a);
};
extern int DAT_010cf9a4;
struct FUN_00d4c220_s
{
    int* m_00;
    unsigned short m_04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    FUN_00d4c220_s();
};
int __cdecl CompareStringsCaseInsensitive(int, int);
struct FUN_00d4c050_obj
{
    int m_00;
    int m_04;
    int m_08;
    int* m_0c;
    int m_10;
    int FindMatchingEntry(int a);
};
extern int DAT_0102f0ec;
void* hkMemoryRouter_getInstance() throw();
void __cdecl InitializeWorld(void*) throw();
void __cdecl RunWithLocalContext(void*, void*, void*) throw();
struct FUN_00d1df70
{
    void removeReference() throw();
};
template <typename T> struct ReferenceCountedPointer
{
    T* m_pRetainedObject;
    __forceinline ReferenceCountedPointer() throw()
    {}
    __forceinline ~ReferenceCountedPointer() throw()
    {
        if (m_pRetainedObject)
        {
            ((FUN_00d1df70*)m_pRetainedObject)->removeReference();
        }
        m_pRetainedObject = 0;
    }
};
struct BoolResult
{
    char val;
    __forceinline BoolResult() throw()
    {}
};
class __declspec(align(16)) FUN_00553540
{
  public:
    void* vtable;
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
    ReferenceCountedPointer<void> m_pCollisionFilter;  // 0x58
    ReferenceCountedPointer<void> m_pConvexListCollisionFilter;  // 0x5c
    int unk60;
    int unk64;
    int unk68;
    ReferenceCountedPointer<void> m_pMemoryWatchDog;  // 0x6c
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;

    void FUN_00c90b80() throw();
    __forceinline FUN_00553540() throw()
    {
        FUN_00c90b80();
    }
    __forceinline ~FUN_00553540() throw()
    {
        vtable = &DAT_0102f0ec;
    }
};
struct ContactOptions
{
    char m_00;
    char m_01;
    char m_02;
    char m_03;
    int m_04;
    char m_08;
    char m_09;
    char m_0a;
    char m_0b;
};
struct PhysicsDataExt : public hkpPhysicsData
{
    hkpWorld* CreateWorld(char bRegisterWithMemoryManager) throw();
};
extern void* __cdecl hkMemoryRouter_getInstance(void);
extern int DAT_010d07f4;
extern void __cdecl ProcessCollisionRecords(void*, void*, void*);
extern void __cdecl ResizeAudioStream(void*, void*, int);
struct D4C2Place
{
};
inline void* operator new(unsigned int, void* p, D4C2Place)
{
    __assume(p != 0);
    return p;
}
inline void operator delete(void*, void*, D4C2Place)
{}
struct BigType
{
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
    void* FUN_00c90b80(void);
};
struct ArrayField
{
    int m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline ArrayField() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct SmallType
{
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    unsigned char m_40;
    unsigned char m_41;
    unsigned char m_42;
    unsigned char m_43;
    ArrayField m_ppData;
    void FUN_00d065e0(void);
};
struct AllocType
{
    virtual void vf00(void);
    virtual void* vf04(int);
};
struct HolderType
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    AllocType* m_10;
};
struct ClientType
{
    void hkpWorld_getCinfo(void*);
    void AddPhysicsSystem(void*);
};
struct ArrayType
{
    SmallType** m_data;
    int m_iElementCount;
    int m_cap;
};
struct HostType
{
    int m_00;
    int m_04;
    void* m_08;
    ArrayType m_0c;
    void hkpPhysicsData_populateFromWorld(ClientType*, unsigned char);
};
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct Value
{
    BoolResult isActive_00c9bff0();
};
struct Owner
{
    int unk00;
    int unk04;
    int** m_08;
    int m_0c;
    void hkpPhysicsSystem_removeRigidBody(int index);
};
struct Entity
{
    int unk00;
    int unk04;
    int** m_08;
    int m_0c;
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
    unsigned char m_40;
    void AddShape(int value);
};
struct OwnerArg
{
    Owner* p;
};
struct ValueArg
{
    Value* p;
};
template <class T> __forceinline int findValue(T* self, Value* value)
{
    int count = ((volatile T*)self)->m_0c;
    for (int i = 0; i < count; ++i)
    {
        if (self->m_08[i] == (int*)value)
            return i;
    }
    return -1;
}
typedef int Owner::*MemberPtr;
static void tryMoveEntity(Owner* owner, Entity* volatile entityArg, MemberPtr valueArg);
Owner* volatile probeOwner;
Value* volatile probeValue;
Entity* volatile probeEntity;
void probeCaller();

struct SplitPlace
{
};
inline void* operator new(unsigned int, void* p, SplitPlace)
{
    return p;
}
inline void operator delete(void*, void*, SplitPlace)
{}
struct SplitRef
{
    virtual ~SplitRef();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class SplitBool
{
    char value;

  public:
    inline SplitBool()
    {}
    inline SplitBool(bool b)
    {
        value = (char)b;
    }
    inline operator bool() const
    {
        return value != 0;
    }
    inline SplitBool& operator=(bool b)
    {
        value = (char)b;
        return *this;
    }
    inline SplitBool operator==(bool b) const
    {
        return (int)value == (int)b;
    }
    inline SplitBool operator!=(bool b) const
    {
        return (int)value != (int)b;
    }
};

struct SplitAllocator
{
    virtual void vf00();
    virtual void* alloc(int);
    virtual void vf08();
    virtual void vf0c();
    virtual void freeBuffer(void*, int);
    template <class T> inline void freeItems(void* p, int count)
    {
        freeBuffer(p, count * sizeof(T));
    }
};
struct SplitRouter
{
    int unk00, unk04, unk08, unk0c;
    SplitAllocator* heap;
    inline SplitAllocator& allocator()
    {
        return *heap;
    }
};
struct SplitHeap
{
    inline SplitAllocator& get(const void*)
    {
        return ((SplitRouter*)hkMemoryRouter_getInstance())->allocator();
    }
};
template <class T> static __forceinline void copyItems(T* dest, int count, const T& item)
{
    for (int i = 0; i < count; ++i)
        dest[i] = item;
}
template <class T> struct SplitArrayBase
{
    T* data;
    int size;
    int capacity;
    __forceinline SplitArrayBase() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline void clearWith(SplitAllocator& alloc)
    {
        size = 0;
        if (!(capacity & 0x80000000))
            alloc.freeItems<T>(data, getCapacity());
        data = 0;
        capacity = 0x80000000;
    }
    __forceinline int GetLogicalSize() const
    {
        return size;
    }
    __forceinline int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline int indexOf(const T& item, int start = 0, int end = -1) const
    {
        if (end < 0)
            end = size;
        for (int i = start; i < end; ++i)
            if (data[i] == item)
                return i;
        return -1;
    }
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline void appendWith(SplitAllocator& alloc, const T& item)
    {
        if (size == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        copyItems(data + size, 1, item);
        ++size;
    }
};
template <class T> struct SplitArray : SplitArrayBase<T>
{
    __forceinline SplitArray()
    {}
    __forceinline ~SplitArray()
    {
        clearWith(SplitHeap().get(this));
    }
    __forceinline void AddBack(const T& item)
    {
        appendWith(SplitHeap().get(this), item);
    }
};
struct SplitName
{
    char* text;
    SplitName& UpdateState_00cb0c10(const char*);
    __forceinline SplitName& operator=(const char* str)
    {
        return UpdateState_00cb0c10(str);
    }
};
struct SplitBody;
struct SplitEntity;
struct SplitConstraint
{
    int unk00, unk04, unk08, unk0c, unk10;
    SplitEntity* bodyA;
    SplitEntity* bodyB;
    __forceinline SplitEntity* getEntityA() const
    {
        return bodyA;
    }
    __forceinline SplitEntity* getEntityB() const
    {
        return bodyB;
    }
    __forceinline SplitEntity* getOtherEntity(const SplitEntity* item) const
    {
        return (SplitEntity*)((unsigned int)bodyA ^ (unsigned int)bodyB ^ (unsigned int)item);
    }
};
struct SplitAction
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void GetEntities(SplitArray<SplitEntity*>&);
};
struct SplitSystem : SplitRef
{
    virtual ~SplitSystem() throw();
    SplitArray<SplitBody*> bodies;
    SplitArray<SplitConstraint*> constraints;
    SplitArray<SplitAction*> actions;
    SplitArray<void*> phantoms;
    SplitName name;
    unsigned long userData;
    SplitBool active;
    static __forceinline void* operator new(unsigned int bytes)
    {
        SplitRef* p = (SplitRef*)((SplitRouter*)hkMemoryRouter_getInstance())->allocator().alloc(bytes);
        p->m_usMemSizeAndFlags = (unsigned short)bytes;
        return p;
    }

    void AddShape(SplitBody*);
    void hkpPhysicsSystem_addPhantom(void*);
    void hkpPhysicsSystem_addConstraint(SplitConstraint*);
    void hkpPhysicsSystem_addAction(SplitAction*);
    void hkpPhysicsSystem_removeRigidBody(int);
    void hkpPhysicsSystem_removeConstraint(int);
    void hkpPhysicsSystem_removeAction(int);
    __forceinline const SplitArray<SplitBody*>& getRigidBodies() const
    {
        return bodies;
    }
    __forceinline const SplitArray<SplitConstraint*>& getConstraints() const
    {
        return constraints;
    }
    __forceinline const SplitArray<SplitAction*>& getActions() const
    {
        return actions;
    }
    __forceinline const SplitArray<void*>& getPhantomArray() const
    {
        return phantoms;
    }
    __forceinline void SetParentObject(const char* str)
    {
        name = str;
    }
    __forceinline unsigned long getUserData() const
    {
        return userData;
    }
    __forceinline void setUserData(unsigned long p)
    {
        userData = p;
    }
    __forceinline SplitBool isActive() const
    {
        return active;
    }
    __forceinline void setActive(SplitBool b)
    {
        active = b;
    }
};
struct SplitOutput
{
    SplitSystem* m_pFirstSplitSystem;
    SplitSystem* m_pSecondSplitSystem;
    SplitSystem* m_pThirdSplitSystem;
    SplitSystem* m_kPhantoms;
    SplitArray<SplitSystem*> m_kSplitSystemArray;
};

struct FUN_00d065e0 : SplitSystem
{
    FUN_00d065e0();
};

enum SplitMotionKind
{
    SplitMotionInvalid,
    SplitMotionDynamic,
    SplitMotionSphere,
    SplitMotionBox,
    SplitMotionKeyframed,
    SplitMotionFixed
};
class SplitMotionByte
{
    unsigned char value;

  public:
    inline SplitMotionByte()
    {}
    inline SplitMotionByte(SplitMotionKind k)
    {
        value = (unsigned char)k;
    }
    inline operator SplitMotionKind() const
    {
        return (SplitMotionKind)value;
    }
    inline void operator=(SplitMotionKind k)
    {
        value = (unsigned char)k;
    }
    inline SplitBool operator==(SplitMotionKind k) const
    {
        return value == (unsigned char)k;
    }
    inline SplitBool operator!=(SplitMotionKind k) const
    {
        return value != (unsigned char)k;
    }
};
struct SplitMotion
{
    int unk00, unk04;
    SplitMotionByte type;
    inline SplitMotionKind getType() const
    {
        return type;
    }
};
struct SplitEntity
{
    int unk00;
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
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    void* island;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    SplitMotion motion;
    SplitBool isActive_00c9bff0() const;
    inline SplitBool isFixed() const
    {
        return motion.type == SplitMotionFixed;
    }
    __forceinline void* GetSimulationIsland() const
    {
        return island;
    }
};
struct SplitBody : SplitEntity
{
    inline SplitMotion* getRigidMotion() const
    {
        return const_cast<SplitMotion*>(&motion);
    }
    inline SplitMotionKind getMotionType() const
    {
        return getRigidMotion()->getType();
    }
};

static __forceinline SplitSystem* makeSystem()
{
    return new FUN_00d065e0;
}
typedef int SplitSystem::*MoveMember;
// src: HAVOK_LIB 0x00d4bf70
static __declspec(noinline) void tryMoveEntity(SplitSystem* from, SplitSystem* volatile toArg, MoveMember encoded)
{
    SplitSystem* to = toArg;
    SplitBody* body;
    memcpy(&body, &encoded, 4);
    int fromIndex = from->getRigidBodies().indexOf(body);
    int toIndex = to->getRigidBodies().indexOf(body);
    if (toIndex == -1 && fromIndex != -1)
    {
        to->setActive(to->isActive() || body->isActive_00c9bff0());
        to->AddShape(body);
        from->hkpPhysicsSystem_removeRigidBody(fromIndex);
    }
}
static __forceinline void moveConnected(SplitSystem* from, SplitSystem* to, SplitEntity* item)
{
    MoveMember encoded;
    memcpy(&encoded, &item, 4);
    tryMoveEntity(from, to, encoded);
}

// @fnv 0x00d4c3b0
// src: HAVOK_LIB 0x00d4c3b0
void hkpPhysicsData_splitPhysicsSystems(const SplitSystem* source, SplitOutput& output)
{
    SplitSystem* remaining = makeSystem();
    for (int i = 0; i < source->getRigidBodies().GetLogicalSize(); ++i)
        remaining->AddShape(source->getRigidBodies()[i]);
    for (int i = 0; i < source->getActions().GetLogicalSize(); ++i)
        remaining->hkpPhysicsSystem_addAction(source->getActions()[i]);
    for (int i = 0; i < source->getConstraints().GetLogicalSize(); ++i)
        remaining->hkpPhysicsSystem_addConstraint(source->getConstraints()[i]);
    for (int i = 0; i < source->getPhantomArray().GetLogicalSize(); ++i)
        remaining->hkpPhysicsSystem_addPhantom(source->getPhantomArray()[i]);

    const SplitArray<SplitBody*>& bodies = remaining->getRigidBodies();
    SplitSystem* moving = makeSystem();
    moving->SetParentObject("Unconstrained Rigid Bodies");
    moving->setUserData(remaining->getUserData());
    moving->setActive(false);
    SplitSystem* fixed = makeSystem();
    fixed->SetParentObject("Fixed Rigid Bodies");
    fixed->setUserData(remaining->getUserData());
    fixed->setActive(false);
    SplitSystem* keyframed = makeSystem();
    keyframed->SetParentObject("Keyframed Rigid Bodies");
    keyframed->setUserData(remaining->getUserData());
    keyframed->setActive(false);

    const SplitArray<SplitConstraint*>& constraints = remaining->getConstraints();
    const SplitArray<SplitAction*>& actions = remaining->getActions();
    while (bodies.GetLogicalSize() > 0)
    {
        SplitSystem* component = makeSystem();
        component->SetParentObject("Constrained System");
        component->setUserData(remaining->getUserData());
        component->setActive(bodies[0]->isActive_00c9bff0());
        component->AddShape(bodies[0]);
        remaining->hkpPhysicsSystem_removeRigidBody(0);
        bool changed = true;
        while (changed)
        {
            changed = false;
            for (int j = 0; j < component->getRigidBodies().GetLogicalSize(); ++j)
            {
                SplitBody* current = component->getRigidBodies()[j];
                int i = 0;
                while (i < constraints.GetLogicalSize())
                {
                    if (constraints[i]->getEntityA() == current || constraints[i]->getEntityB() == current)
                    {
                        changed = true;
                        component->hkpPhysicsSystem_addConstraint(constraints[i]);
                        SplitEntity* other = constraints[i]->getOtherEntity(current);
                        if (other && !other->isFixed())
                            moveConnected(remaining, component, other);
                        remaining->hkpPhysicsSystem_removeConstraint(i);
                    }
                    else
                        ++i;
                }
                i = 0;
                while (i < actions.GetLogicalSize())
                {
                    SplitArray<SplitEntity*> participants;
                    actions[i]->GetEntities(participants);
                    bool moved = false;
                    for (int k = 0; k < participants.GetLogicalSize(); ++k)
                    {
                        if (participants[k] == current)
                        {
                            changed = true;
                            component->hkpPhysicsSystem_addAction(actions[i]);
                            remaining->hkpPhysicsSystem_removeAction(i);
                            moved = true;
                            for (int l = 0; l < participants.GetLogicalSize(); ++l)
                            {
                                if (participants[l] != current)
                                    if (!participants[l]->isFixed())
                                        moveConnected(remaining, component, participants[l]);
                            }
                        }
                    }
                    if (!moved)
                        ++i;
                }
            }
        }
        if (component->getConstraints().GetLogicalSize() == 0 && component->getActions().GetLogicalSize() == 0)
        {
            SplitBody* body = component->getRigidBodies()[0];
            bool active = !body->GetSimulationIsland() || body->isActive_00c9bff0();
            if (body->getMotionType() == 4)
            {
                keyframed->setActive(keyframed->isActive() || active);
                keyframed->AddShape(body);
            }
            else if (body->getMotionType() == 5)
                fixed->AddShape(body);
            else
            {
                moving->setActive(moving->isActive() || active);
                moving->AddShape(body);
            }
            delete component;
        }
        else
            output.m_kSplitSystemArray.AddBack(component);
    }
    if (keyframed->getRigidBodies().GetLogicalSize())
        output.m_pSecondSplitSystem = keyframed;
    else
    {
        delete keyframed;
        output.m_pSecondSplitSystem = 0;
    }
    if (fixed->getRigidBodies().GetLogicalSize())
        output.m_pFirstSplitSystem = fixed;
    else
    {
        delete fixed;
        output.m_pFirstSplitSystem = 0;
    }
    if (moving->getRigidBodies().GetLogicalSize())
        output.m_pThirdSplitSystem = moving;
    else
    {
        delete moving;
        output.m_pThirdSplitSystem = 0;
    }
    const SplitArray<void*>& phantoms = remaining->getPhantomArray();
    if (phantoms.GetLogicalSize() > 0)
    {
        SplitSystem* phantomGroup = makeSystem();
        phantomGroup->SetParentObject("Phantoms");
        phantomGroup->setUserData(remaining->getUserData());
        output.m_kPhantoms = phantomGroup;
        for (int i = 0; i < phantoms.GetLogicalSize(); ++i)
            phantomGroup->hkpPhysicsSystem_addPhantom(phantoms[i]);
    }
    else
        output.m_kPhantoms = 0;
    delete remaining;
}
