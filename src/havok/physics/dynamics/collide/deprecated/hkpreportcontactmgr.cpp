#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form

// src/havok/physics/dynamics/collide/deprecated/hkpreportcontactmgr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/collide/deprecated/hkpreportcontactmgr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00cfc5f0 processContactPoint: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    };
    struct
    {
        unsigned __int64 low, high;
    };
} __m128, LocalM128;

extern "C"
{
    LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
    LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
    void _mm_store_ss(float* p, LocalM128 a);
}

// The intrinsic type is already defined; retain its buffer-free layout for MSVC /GS.
#define _INCLUDED_MM2
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkContactPoint.h"
#include "../../../../../../include/hkpRigidBody.h"


__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::add4(const hkVector4& a)
{
    m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
}

__forceinline void hkVector4::setCross(const hkVector4& a, const hkVector4& b)
{
    const LocalM128 a1 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9);
    const LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2);
    const LocalM128 a2 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2);
    const LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9);
    m_vComponents = _mm_sub_ps(_mm_mul_ps(a1, b1), _mm_mul_ps(a2, b2));
}

__forceinline float hkVector4::dot3scalar(const hkVector4& a) const
{
    const LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    const LocalM128 r = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    float s;
    _mm_store_ss(&s, r);
    return s;
}

#include "../../../../../../include/hkpSimpleConstraintContactMgr.h"

inline const hkVector4& hkContactPoint::getNormal() const
{
    return m_vSeparatingNormal;
}

extern "C" void* DAT_010cc8bc;

struct FUN_00cfca20
{
    void* m_ppVirtualMethodTable;
    unsigned short m_auiShapeKeys;
    unsigned short m_flag;
    void* m_data;
    FUN_00cfca20(void* data);
};

// @fnv 0x00cfca20
FUN_00cfca20::FUN_00cfca20(void* data)
{
    m_flag = 1;
    m_ppVirtualMethodTable = &DAT_010cc8bc;
    m_data = data;
}

struct FUN_00cfcc30_class;

struct FUN_00cfcc30_class
{
    void* m_ppVirtualMethodTable;
    unsigned short m_flag;

    void SetVtable();
    FUN_00cfcc30_class* FUN_00cfcc30(unsigned char flags);
};

struct FUN_00cfcc30_manager
{
    virtual void FUN_00cfcc30_virtual_0();
    virtual void FUN_00cfcc30_virtual_1();
    virtual void FUN_00cfcc30_virtual_2(FUN_00cfcc30_class* object, unsigned short flag);
};

struct FUN_00cfcc30_router
{
    unsigned char m_auiShapeKeys[0x10];
    FUN_00cfcc30_manager* m_manager;
};

FUN_00cfcc30_router* _D1A0E0GetMemoryRouter();

// @fnv 0x00cfcc30
FUN_00cfcc30_class* FUN_00cfcc30_class::FUN_00cfcc30(unsigned char flags)
{
    SetVtable();

    if (flags & 1)
    {
        FUN_00cfcc30_router* router = _D1A0E0GetMemoryRouter();
        router->m_manager->FUN_00cfcc30_virtual_2(this, m_flag);
    }

    return this;
}

struct GameNode
{
    unsigned int unknown00;
    unsigned int unknown04;
    void* payload;

    unsigned short activityFlag() const
    {
        return *reinterpret_cast<const unsigned short*>(reinterpret_cast<const unsigned char*>(this) + 0x204);
    }
};

struct InputRecord
{
    void* header;
    void* member04;
    unsigned int member08;
    GameNode* primary;
    GameNode* secondary;
    void* tertiary;

    void* member18()
    {
        return reinterpret_cast<unsigned char*>(this) + 0x18;
    }
    void* member2c()
    {
        return reinterpret_cast<unsigned char*>(this) + 0x2c;
    }
    void* member50()
    {
        return reinterpret_cast<unsigned char*>(this) + 0x50;
    }
};

struct Descriptor
{
    int type;
    GameNode* primary;
    GameNode* secondary;
    void* tertiary;
    int control;
    void* data50;
    void* data18;
    unsigned char option0;
    unsigned char option1;
    unsigned char option2;
    void* data04;
    void* output;
    void* data2c;
    int result0;
    int result1;
};

void __cdecl hkpWorldCallbackUtil_fireContactPointCallback(void* payload, Descriptor* descriptor);
void __cdecl hkpEntityCallbackUtil_fireContactPointCallbackInternal(GameNode* node, int* index);

// @fnv 0x00cfc960
void __stdcall ProcessInputRecord(InputRecord* record, void* output, unsigned int unused)
{
    Descriptor descriptor;
    descriptor.type = 2;
    descriptor.tertiary = record->tertiary;
    descriptor.secondary = record->secondary;
    descriptor.primary = record->primary;
    descriptor.control = 0;
    descriptor.data50 = record->member50();
    descriptor.data18 = record->member18();
    descriptor.option0 = 0;
    descriptor.option1 = 0;
    descriptor.option2 = 0;
    descriptor.data04 = &record->member04;
    descriptor.output = &output;
    descriptor.data2c = record->member2c();
    descriptor.result0 = 0;
    descriptor.result1 = 0;

    hkpWorldCallbackUtil_fireContactPointCallback(record->primary->payload, &descriptor);

    descriptor.type = 0;
    if (record->primary->activityFlag() != 0)
        hkpEntityCallbackUtil_fireContactPointCallbackInternal(record->primary, &descriptor.type);

    descriptor.type = 1;
    if (record->secondary->activityFlag() != 0)
        hkpEntityCallbackUtil_fireContactPointCallbackInternal(record->secondary, &descriptor.type);
}

struct CFCA90Shape
{
    int m_type, m_flags, m_uiContentCount, m_kSmartReference;
    signed char m_subshapeOffset;
};
struct CFCA90Range
{
    char* m_kRayEnd;
};
struct CFCA90Object;
struct CFCA90Work
{
    CFCA90Shape* m_firstShape;
    CFCA90Shape* m_secondShape;
    int m_flags;
    CFCA90Range* m_range;
    int m_scratchIndices[256];
    CFCA90Object* m_pOwnerObject;
};
void __cdecl NotifyShapeSetListeners(void*, void*);
void __cdecl hkpEntityCallbackUtil_fireContactProcessInternal(void*, void*);
struct CFCA90Object
{
    int m_type, m_uiContentCount, m_flags;
    void* m_controller;
    int m_pOwnerObject, m_detail;
    unsigned short m_remainingCount, m_ucUnknownByte;
    void ProcessShapePair(CFCA90Shape*, CFCA90Shape*, void*, CFCA90Range*);
};
// @fnv 0x00cfca90
void CFCA90Object::ProcessShapePair(CFCA90Shape* shapeA, CFCA90Shape* shapeB, void* unusedInput, CFCA90Range* range)
{
    if (m_remainingCount-- != 0)
        return;
    char* partA = (char*)shapeA + shapeA->m_subshapeOffset;
    char* partB = (char*)shapeB + shapeB->m_subshapeOffset;
    unsigned short countB = *(unsigned short*)(partB + 0xaa);
    unsigned short countA = *(unsigned short*)(partA + 0xaa);
    unsigned short nextCount = countA < countB ? countA : countB;
    CFCA90Work work;
    work.m_firstShape = shapeA;
    work.m_secondShape = shapeB;
    work.m_range = range;
    m_remainingCount = nextCount;
    int entries = (int)(range->m_kRayEnd - ((char*)range + 16)) / 48;
    work.m_pOwnerObject = this;
    for (int iIndex = entries - 1; iIndex >= 0; --iIndex)
        work.m_scratchIndices[iIndex] = 0;
    NotifyShapeSetListeners(m_controller, &work);
    if (*(unsigned short*)(partA + 0x204))
        hkpEntityCallbackUtil_fireContactProcessInternal(partA, &work);
    if (*(unsigned short*)(partB + 0x204))
        hkpEntityCallbackUtil_fireContactProcessInternal(partB, &work);
}

// Contact-dispatch reconstruction; incorporates earlier contributor's event-callback analysis (2026-10-25).
struct ContactRecord
{
    void* m_ppVirtualMethodTable;
    void* m_unknown04;
    void* m_kCollidable;
};
struct ContactEvent;
void __cdecl hkpWorldCallbackUtil_fireContactPointRemoved(void* collidable, ContactEvent* eventData);
void __cdecl hkpEntityCallbackUtil_fireContactPointRemovedInternal(ContactRecord* record, ContactEvent* eventData);

struct ContactDispatcher
{
    void* m_unknown00;
    void* m_unknown04;
    void* m_unknown08;
    void* m_unknown0c;
    ContactRecord* m_pHeadNode;
    ContactRecord* m_iSecondInteger;
    void DispatchContact(void* arg1, void* arg2);
};
struct ContactEvent
{
    unsigned short m_eventType;
    unsigned short m_unknown02;
    void* m_arg2;
    ContactRecord* m_pHeadNode;
    ContactRecord* m_iSecondInteger;
    void* m_unknown10;
    ContactDispatcher* m_pCollisionDispatcher;
    void* m_arg1;
};
// Fills a ContactEvent with the dispatcher and two contact records, then calls FUN_00d01900 and optionally FUN_00d001c0 on each record.
// @fnv 0x00cfc860
void ContactDispatcher::DispatchContact(void* arg1, void* arg2)
{
    ContactRecord* first = m_pHeadNode;
    void* collidable = first->m_kCollidable;
    ContactEvent data;
    data.m_eventType = 0xffff;
    data.m_arg2 = arg2;
    ContactRecord* second = m_iSecondInteger;
    data.m_pCollisionDispatcher = this;
    data.m_pHeadNode = first;
    data.m_iSecondInteger = second;
    data.m_arg1 = arg1;
    hkpWorldCallbackUtil_fireContactPointRemoved(collidable, &data);
    if (*(unsigned short*)((char*)first + 0x204) != 0)
        hkpEntityCallbackUtil_fireContactPointRemovedInternal(first, &data);
    if (*(unsigned short*)((char*)second + 0x204) != 0)
        hkpEntityCallbackUtil_fireContactPointRemovedInternal(second, &data);
}

struct Entity
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned short active;
};
struct World;
struct Owner;
struct Contact
{
    unsigned short flags;
    unsigned short unk002;
    unsigned int unk004;
    Entity* entityA;
    Entity* entityB;
    unsigned int unk010;
    Owner* owner;
    unsigned int state;
};
void __cdecl hkpWorldCallbackUtil_fireContactPointRemoved(World*, Contact*);
void __cdecl hkpEntityCallbackUtil_fireContactPointRemovedInternal(Entity*, Contact*);
struct Owner
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    World* world;
    Entity* a;
    Entity* b;
    void NotifyContact(unsigned short flags, unsigned int state);
};
// Builds a Contact from the owner's entities and state, calls FUN_00d01900 on the world, then calls FUN_00d001c0 on each active entity.
// @fnv 0x00cfc8e0
void Owner::NotifyContact(unsigned short flags, unsigned int state)
{
    Entity* const entityA = a;
    Entity* const entityB = b;
    Contact contact;
    contact.flags = flags;
    contact.unk004 = 0;
    contact.entityA = entityA;
    contact.entityB = entityB;
    contact.owner = this;
    contact.state = state;
    hkpWorldCallbackUtil_fireContactPointRemoved(world, &contact);
    if (entityA->active != 0)
        hkpEntityCallbackUtil_fireContactPointRemovedInternal(entityA, &contact);
    if (entityB->active != 0)
        hkpEntityCallbackUtil_fireContactPointRemovedInternal(entityB, &contact);
}

struct S_Cfca40_AdjustedSource
{
    void* m_type;
    void* m_pOwnerObject;
    void* m_data;
    void* m_iValueAtOffset0C;
    signed char m_offset;
    void* GetAdjustedData()
    {
        return reinterpret_cast<char*>(this) + m_offset;
    }
};
struct S_Cfca40_Manager
{
    virtual void Deallocate();
    virtual void* Allocate(unsigned int bytes);
};
struct S_Cfca40_Router
{
    void* m_allocatorState;
    void* m_parent;
    void* m_reserved;
    void* m_iValueAtOffset0C;
    S_Cfca40_Manager* m_manager;
    S_Cfca40_Manager& heap()
    {
        return *m_manager;
    }
};
S_Cfca40_Router* hkMemoryRouter_getInstance();
struct S_Cfca40_Element
{
    void* m_ppVirtualMethodTable;
    unsigned short m_allocatedBytes;
    void FUN_00cfc5a0(void* context, void* first, void* second);
};
struct S_Cfca40_Factory
{
    void* m_type;
    unsigned short m_reserved;
    unsigned short m_flags;
    void* m_iValueAtOffset0C;
    void CreateElement(S_Cfca40_AdjustedSource* first, S_Cfca40_AdjustedSource* second,
                       S_Cfca40_AdjustedSource* unused);
};
// @fnv 0x00cfca40
void S_Cfca40_Factory::CreateElement(S_Cfca40_AdjustedSource* apFirstSource, S_Cfca40_AdjustedSource* apSecondSource,
                                     S_Cfca40_AdjustedSource* unused)
{
    void* firstData = apFirstSource->GetAdjustedData();
    void* secondData = apSecondSource->GetAdjustedData();
    S_Cfca40_Element* pElement = static_cast<S_Cfca40_Element*>(hkMemoryRouter_getInstance()->heap().Allocate(28));
    pElement->m_allocatedBytes = 28;
    pElement->FUN_00cfc5a0(m_iValueAtOffset0C, firstData, secondData);
}

struct hkpCdBody;
struct GskAgentInput;
struct ConvexFeaturePairCache;

struct WorldOperationEntry
{
    int unk00;
    void* m_pConstraintOwner;
};

struct ContactPointProcessingData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_iResultCode;  // 0x20
    int unk24;
    int unk28;
    int unk2C;
    unsigned short unk30;
    unsigned short m_nextProcessCollideDelay;  // 0x32

    ContactPointProcessingData(int contactPointId, hkpSimpleConstraintContactMgr* mgr, const GskAgentInput* input,
                               WorldOperationEntry* output, const hkpCdBody* a, const hkpCdBody* b, hkContactPoint* cp,
                               const ConvexFeaturePairCache* gskCache, void* transformedContact, float projectedVelocity);
};

struct hkpWorld;
void hkpWorldCallbackUtil_fireContactPointAdded(hkpWorld* world, ContactPointProcessingData& event);
void hkpEntityCallbackUtil_fireContactPointAddedInternal(hkpRigidBody* entity, ContactPointProcessingData& event);



// Computes projected velocity at the contact point, dispatches a ContactPointProcessingData event, and removes the contact point if the result code is 1.
// @fnv 0x00cfc5f0
unsigned int hkpSimpleConstraintContactMgr::processContactPoint(const hkpCdBody& a, const hkpCdBody& b,
                                                         const GskAgentInput& input, WorldOperationEntry& output,
                                                         const ConvexFeaturePairCache* contactCache, hkContactPoint& cp)
{
    hkpRigidBody* rbA = m_pEntityA;
    hkpRigidBody* rbB = m_pEntityB;

    float fProjectedVelocity;
    {
        LocalM128 point = cp.m_vContactPosition.m_vComponents;
        LocalM128 comA = rbA->m_pMotionState.m_kMotionState.m_kSweptTransform.m_vCenterOfMass1.m_vComponents;
        LocalM128 offsetA = _mm_sub_ps(point, comA);
        LocalM128 angularA = rbA->m_pMotionState.m_kAngularVelocity.m_vComponents;
        LocalM128 angularB = rbB->m_pMotionState.m_kMotionState.m_kSweptTransform.m_vCenterOfMass1.m_vComponents;
        LocalM128 offsetB = _mm_sub_ps(point, angularB);
        angularB = rbB->m_pMotionState.m_kAngularVelocity.m_vComponents;
        LocalM128 firstB = _mm_shuffle_ps(offsetB, offsetB, 0xc9);
        LocalM128 secondB = _mm_shuffle_ps(angularB, angularB, 0xd2);
        LocalM128 thirdB = _mm_shuffle_ps(offsetB, offsetB, 0xd2);
        LocalM128 fourthB = _mm_shuffle_ps(angularB, angularB, 0xc9);
        firstB = _mm_mul_ps(firstB, secondB);
        thirdB = _mm_mul_ps(thirdB, fourthB);
        hkVector4 vVelocityB;
        vVelocityB.m_vComponents = _mm_add_ps(_mm_sub_ps(thirdB, firstB), rbB->m_pMotionState.m_kTranslationalVelocity.m_vComponents);
        LocalM128 firstA = _mm_shuffle_ps(angularA, angularA, 0xc9);
        LocalM128 secondA = _mm_shuffle_ps(offsetA, offsetA, 0xd2);
        LocalM128 thirdA = _mm_shuffle_ps(angularA, angularA, 0xd2);
        LocalM128 fourthA = _mm_shuffle_ps(offsetA, offsetA, 0xc9);
        firstA = _mm_mul_ps(firstA, secondA);
        thirdA = _mm_mul_ps(thirdA, fourthA);
        hkVector4 vVelocityA;
        vVelocityA.m_vComponents = _mm_add_ps(_mm_sub_ps(firstA, thirdA), rbA->m_pMotionState.m_kTranslationalVelocity.m_vComponents);
        hkVector4 vDeltaVelocity;
        vDeltaVelocity.setSub4(vVelocityB, vVelocityA);
        fProjectedVelocity = vDeltaVelocity.dot3scalar(cp.getNormal());
    }

    ContactPointProcessingData event(0, this, &input, &output, &a, &b, &cp, contactCache, 0, fProjectedVelocity);
    hkpWorldCallbackUtil_fireContactPointAdded(m_pOwningWorld, event);

    if (rbA->m_kContactListeners.m_iElementCount != 0)
    {
        hkpEntityCallbackUtil_fireContactPointAddedInternal(rbA, event);
    }
    if (rbB->m_kContactListeners.m_iElementCount != 0)
    {
        hkpEntityCallbackUtil_fireContactPointAddedInternal(rbB, event);
    }
    if (event.m_iResultCode == 1)
    {
        removeContactPoint(0, output.m_pConstraintOwner);
        return 0xffff;
    }
    m_nextProcessCollideDelay = event.m_nextProcessCollideDelay;
    return 0;
}

struct Word
{
    int value;
};
struct CollisionBody
{
    float unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    unsigned short unk204;
};

struct CollisionStateData
{
    int unk000;
    int unk004;
    int unk008;
    bool unk00C;
    bool unk00D;
    bool unk00E;
    bool unk00F;
};

struct CollisionPoint
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    void* unk018;
    float unk01C;
    int unk020;
    void* unk024;
    int unk028;
    void* unk02C;
    float unk030;
    CollisionPoint(int a1, int a2, int a3, CollisionStateData* a4, float a5, int a6, int a7, CollisionBody* a8,
                   CollisionStateData* a9, void* owner)
        : unk000(a1), unk004(a2), unk008(0), unk010(a6), unk014(a7), unk018(a9), unk01C(a8->unk000), unk024(owner),
          unk028(a3), unk02C(a4), unk030(a5)
    {
        unk020 = 0;
    }
};

void hkpWorldCallbackUtil_fireContactPointAdded(int a, void* b);
void hkpEntityCallbackUtil_fireContactPointAddedInternal(void* a, void* b);

struct CollisionOwner
{
    int unk004;
    int unk008;
    int unk00C;
    CollisionBody* unk010;
    CollisionBody* unk014;

    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20(int a, void* b);

    int hkpReportContactMgr_addToiImpl(Word a1, int a2, int a3, CollisionStateData* a4, float a5, int a6, int a7, CollisionBody* a8,
                     CollisionStateData* a9);
};

// Builds a CollisionPoint, passes it to FUN_00d01850 and to FUN_00d00110 for bodies with unk204 set; calls vf20 if unk020 is 1, else sets a8->unk000.
// @fnv 0x00cfc760
// src: HAVOK_LIB 0x00cfc760
int CollisionOwner::hkpReportContactMgr_addToiImpl(Word a1, int a2, int a3, CollisionStateData* apStateData, float a5, int a6, int a7,
                                 CollisionBody* apBody, CollisionStateData* apOutState)
{
    apOutState->unk00C = false;
    apOutState->unk00E = false;
    apOutState->unk00D = false;
    apOutState->unk00F = true;
    CollisionPoint pObj(a1.value, a2, a3, apStateData, a5, a6, a7, apBody, apOutState, this);
    CollisionBody* y = this->unk010;
    CollisionBody* pBodyB = this->unk014;
    hkpWorldCallbackUtil_fireContactPointAdded(this->unk00C, &pObj);

    if ((bool)y->unk204)
        hkpEntityCallbackUtil_fireContactPointAddedInternal(y, &pObj);

    if (!!pBodyB->unk204)
        hkpEntityCallbackUtil_fireContactPointAddedInternal(pBodyB, &pObj);

    if (1 == pObj.unk020)
    {
        this->vf20(apStateData->unk004, apOutState);
        return pObj.unk020;
    }

    apBody->unk000 = pObj.unk01C;
    return pObj.unk020;
}
