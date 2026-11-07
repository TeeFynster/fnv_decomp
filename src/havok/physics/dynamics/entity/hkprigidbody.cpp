#include "../../../../../include/hkArray.h"
// src/havok/physics/dynamics/entity/hkprigidbody.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/entity/hkprigidbody.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkStringPtr.h"
#include "../../../../../include/hkpEntity.h"
#include "../../../../../include/hkpMotion.h"
#include "../../../../../include/hkpCollidable.h"
#include "../../../../../include/hkpRigidBody.h"
#include "../../../../../include/NiPoint3.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkRotation.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkpShape.h"
#include "../../../../../include/hkpShapeContainer.h"
#include "../../../../../include/hkpShapeCollection.h"
#include "../../../../../include/hkpWorld.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"

// The approved router header declares heap() out of line. Preserve the inline accessor here.
__forceinline hkMemoryAllocator& heapAllocator(hkMemoryRouter& router)
{
    return *router.m_heap;
}

// Some shared motion virtuals are still declared without their argument types.
template <typename Function>
__forceinline Function motionVirtual(hkpMotion& motion, unsigned int slot)
{
    return reinterpret_cast<Function>((*reinterpret_cast<void***>(&motion))[slot]);
}


// The approved rigid-body header does not yet declare the remaining local entry points.
struct FUN_00ca86c0_class
{
    unsigned int __thiscall hkpRigidBody_getStoredDynamicMotion_00ca86c0();
};
// @fnv 0x00ca86c0
// src: XBOX_PDB 0x00ca86c0
unsigned int __thiscall FUN_00ca86c0_class::hkpRigidBody_getStoredDynamicMotion_00ca86c0()
{
    unsigned char m_0xe8 = *(unsigned char*)((char*)this + 0xe8);
    if (m_0xe8 != 4 && m_0xe8 != 5)
        return 0;
    return *(unsigned int*)((char*)this + 0x1f8);
}

struct FUN_00ca88c0_Class
{
    void hkpRigidBody_setMass(float f);
};

// @fnv 0x00ca88c0
// src: HAVOK_LIB 0x00ca88c0
void FUN_00ca88c0_Class::hkpRigidBody_setMass(float afValue)
{
    ((void(__thiscall*)(void*, float))(*(void**)(*(int*)((char*)this + 0xe0) + 12)))((char*)this + 0xe0, afValue);
}

struct FUN_00ca80c0_Class
{
    int __fastcall hkpRigidBody_isDeactivationEnabled();
};
// @fnv 0x00ca80c0
// src: COMMUNITY 0x00ca80c0
int __fastcall FUN_00ca80c0_Class::hkpRigidBody_isDeactivationEnabled()
{
    return *(unsigned char*)(this + 0xe9) != 0xff;
}

struct FUN_00ca8900_Class
{
    void hkpRigidBody_setFriction(float f, int i);
};

// @fnv 0x00ca8900
// src: HAVOK_LIB 0x00ca8900
void FUN_00ca8900_Class::hkpRigidBody_setFriction(float f, int i)
{
    *(float*)((char*)this + 0x90) = f;
}

struct FUN_00ca8910_class
{
    void hkpRigidBody_setRestitution(float v);
};
// @fnv 0x00ca8910
// src: HAVOK_LIB 0x00ca8910
void FUN_00ca8910_class::hkpRigidBody_setRestitution(float v)
{
    *(float*)((char*)this + 0x94) = v;
}

// @fnv 0x00ca80b0
const hkTransform& hkpRigidBody::getTransform() const
{
    return m_pMotionState.m_kMotionState.m_kMotionTransform;
}

extern float DAT_01016248;

inline float lowerPair(float left, float right)
{
    return left < right ? left : right;
}
inline float lowerPairReversed(float left, float right)
{
    return left > right ? right : left;
}
// Computes the minimum of the three components of values and stores 0.2 times it in result->m_fAllowedPenetrationDepth if below DAT_01016248, otherwise 0.1.
// @fnv 0x00ca80d0
void __fastcall ComputeScaledMinimum(const NiPoint3* values, hkpCollidable* result)
{
    float firstMinimum = lowerPair(values->x, values->y);
    float minimum = lowerPair(firstMinimum, values->z);
    if (DAT_01016248 > minimum)
        result->m_fAllowedPenetrationDepth = 0.2 * minimum;
    else
        result->m_fAllowedPenetrationDepth = 0.1f;
}

struct Owner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
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
    hkpMotion subobjectE0;
    void hkpRigidBody_updateCachedShapeInfo(unsigned int value, hkVector4* result);
    void hkpRigidBody_setCenterOfMassLocal(unsigned int value);
};
// @fnv 0x00ca85f0
// src: HAVOK_LIB 0x00ca85f0
void Owner::hkpRigidBody_setCenterOfMassLocal(unsigned int value)
{
    motionVirtual<void(__thiscall*)(hkpMotion*, unsigned int)>(subobjectE0, 11)(&subobjectE0, value);
    unsigned int source = unk10;
    hkVector4 result;
    hkpRigidBody_updateCachedShapeInfo(source, &result);
}

struct CA86E0Object
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char unkE8;
    unsigned char unkE9;
    unsigned char unkEA;
    unsigned char unkEB;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    void* unk1F8;

    void* ComputeValue_00ca86e0();
};

// @fnv 0x00ca86e0
// src: GUESS 0x00ca86e0 (confidence: low)
void* CA86E0Object::ComputeValue_00ca86e0()
{
    if (unkE8 == 4 || unkE8 == 5)
        return unk1F8;
    return 0;
}

struct FUN_00ca8800_Class
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    hkpMotion interfaceE0;
    void hkpRigidBody_setPosition(int value);
};
extern "C" void __cdecl hkpRigidBody_updateBroadphaseAndResetCollisionInformationOfWarpedBody(FUN_00ca8800_Class* self);
// Calls the interface's dispatch with value, then invokes FUN_00ca8700 on this object.
// @fnv 0x00ca8800
// src: HAVOK_LIB 0x00ca8800
void FUN_00ca8800_Class::hkpRigidBody_setPosition(int value)
{
    motionVirtual<void(__thiscall*)(hkpMotion*, int)>(interfaceE0, 12)(&interfaceE0, value);
    hkpRigidBody_updateBroadphaseAndResetCollisionInformationOfWarpedBody(this);
}

struct CA8830Object;

void __cdecl hkpRigidBody_updateBroadphaseAndResetCollisionInformationOfWarpedBody(CA8830Object* obj);

struct CA8830Object
{
    char unk000[0xe0];
    hkpMotion m_kMemberDescriptor;

    void hkpRigidBody_setRotation(int value);
};

// Calls setValue on the member with value, then passes this to FUN_00ca8700.
// @fnv 0x00ca8830
// src: HAVOK_LIB 0x00ca8830
void CA8830Object::hkpRigidBody_setRotation(int value)
{
    motionVirtual<void(__thiscall*)(hkpMotion*, int)>(m_kMemberDescriptor, 13)(&m_kMemberDescriptor, value);
    hkpRigidBody_updateBroadphaseAndResetCollisionInformationOfWarpedBody(this);
}

void __cdecl hkpRigidBody_updateBroadphaseAndResetCollisionInformationOfWarpedBody(void* apOwner);

struct FUN_00ca8860_cls
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
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    hkpMotion m_sub;
    void hkpRigidBody_setPositionAndRotation(int aiFirst, int aiSecond);
};

// Calls the sub-object's Do virtual with aiFirst and aiSecond, then invokes FUN_00ca8700 on this.
// @fnv 0x00ca8860
// src: HAVOK_LIB 0x00ca8860
void FUN_00ca8860_cls::hkpRigidBody_setPositionAndRotation(int aiFirst, int aiSecond)
{
    motionVirtual<void(__thiscall*)(hkpMotion*, int, int)>(m_sub, 14)(&m_sub, aiFirst, aiSecond);
    hkpRigidBody_updateBroadphaseAndResetCollisionInformationOfWarpedBody(this);
}

struct CA8B80Command
{
    unsigned char m_type;
    void* m_pOwnerObject;
    float x;
    float y;
    float z;
};

// The approved hkpWorld header lacks the pending-operation queue entry point (0x00c91160).
struct CA8B80Queue
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
    void* m_bSlotEnabled;

    void Push(CA8B80Command* pkCommand);
};

struct CA8B80Object
{
    int unk00;
    int unk04;
    CA8B80Queue* m_queue;
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    hkpMotion m_handler;

    void Update();
    void hkpRigidBody_applyAngularImpulseAsCriticalOperation(const hkVector4& kPos);
};

// @fnv 0x00ca8b80
// src: HAVOK_LIB 0x00ca8b80
void CA8B80Object::hkpRigidBody_applyAngularImpulseAsCriticalOperation(const hkVector4& kPos)
{
    if (m_queue && m_queue->m_bSlotEnabled)
    {
        CA8B80Command kCommand;
        kCommand.m_type = 0x1d;
        kCommand.x = kPos.x;
        kCommand.m_pOwnerObject = this;
        kCommand.y = kPos.y;
        kCommand.z = kPos.z;
        m_queue->Push(&kCommand);
        return;
    }
    Update();
    motionVirtual<void(__thiscall*)(hkpMotion*, const hkVector4&)>(m_handler, 21)(&m_handler, kPos);
}

struct FUN_00ca9240_Base
{
    int unk04;
    unsigned char type;
    FUN_00ca9240_Base(int a, int b, int c);
    virtual void unk00();
};

struct FUN_00ca9240 : FUN_00ca9240_Base
{
    FUN_00ca9240(int a, int b);
    virtual void unk04();
};

// Constructs the base with a and b and a zero, then sets type to 7.
// @fnv 0x00ca9240
FUN_00ca9240::FUN_00ca9240(int aiValueA, int aiValueB) : FUN_00ca9240_Base(aiValueA, aiValueB, 0)
{
    type = 7;
}

struct BaseRecord
{
    virtual void v00();

    int m_i04;
    char m_c08;

    BaseRecord(void* apFirst, void* apSecond, int aiFlag);
};

struct FUN_00ca9270 : BaseRecord
{
    FUN_00ca9270(void* apFirst, void* apSecond);
};

// Constructs the object by forwarding apFirst and apSecond to BaseRecord with flag 0, then sets m_c08 to 2.
// @fnv 0x00ca9270
FUN_00ca9270::FUN_00ca9270(void* apFirst, void* apSecond) : BaseRecord(apFirst, apSecond, 0)
{
    m_c08 = 2;
}

struct FUN_00ca80a0_cls : hkpEntity
{
    virtual ~FUN_00ca80a0_cls();
};

// @fnv 0x00ca80a0
FUN_00ca80a0_cls::~FUN_00ca80a0_cls()
{}

// The approved hkpMotion header lacks the three-argument helper at 0x00c90ed0.
struct S_00ca8630_Sub
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned short unk0a;
    unsigned short unk0c;
    void SetFlagBits(int a, int b, int c);
    __forceinline void Set(unsigned char v, int a, int b, int c)
    {
        unk09 = v;
        SetFlagBits(a, b, c);
    }
};
struct S_00ca8630_Class
{
    unsigned int unk00;
    unsigned int unk04;
    hkpWorld* unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
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
    unsigned char unkd4;
    unsigned char unkd5;
    unsigned char unkd6;
    unsigned char unkd7;
    unsigned int unkd8;
    unsigned int unkdc;
    S_00ca8630_Sub unke0;
    void hkpRigidBody_enableDeactivation(bool f);
};
// @fnv 0x00ca8630
// src: HAVOK_LIB 0x00ca8630
void S_00ca8630_Class::hkpRigidBody_enableDeactivation(bool f)
{
    if (f)
    {
        if (unk08)
        {
            hkpWorld* volatile* pv = (hkpWorld* volatile*)&unk08;
            hkpWorld* o = *pv;
            int c = reinterpret_cast<unsigned char*>(o)[0x307];
            int b = reinterpret_cast<unsigned char*>(o)[0x306];
            int a = reinterpret_cast<unsigned char*>(o)[0x305];
            unke0.Set(unkd4 & 0xf, a, b, c);
        }
        else
        {
            unke0.Set(unkd4 & 0xf, 0, 0, 0);
        }
    }
    else
    {
        unke0.unk09 = 0xff;
        unke0.unk0a = 0;
        unke0.unk0c = 0;
    }
}

struct CA8890Object;

void __cdecl hkpRigidBody_updateBroadphaseAndResetCollisionInformationOfWarpedBody(CA8890Object* obj);

struct CA8890Object
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    hkpMotion m_kMemberDescriptor;

    void hkpRigidBody_setTransform(int value);
};

// Calls setValue on the member with value, then calls FUN_00ca8700 on this object.
// @fnv 0x00ca8890
// src: HAVOK_LIB 0x00ca8890
void CA8890Object::hkpRigidBody_setTransform(int value)
{
    motionVirtual<void(__thiscall*)(hkpMotion*, int)>(m_kMemberDescriptor, 15)(&m_kMemberDescriptor, value);
    hkpRigidBody_updateBroadphaseAndResetCollisionInformationOfWarpedBody(this);
}

struct FUN_00ca88e0_cls
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    hkpMotion m_sub;

    void hkpRigidBody_setMassInv(float f);
};

// @fnv 0x00ca88e0
// src: HAVOK_LIB 0x00ca88e0
void FUN_00ca88e0_cls::hkpRigidBody_setMassInv(float afValue)
{
    motionVirtual<void(__thiscall*)(hkpMotion*, float)>(m_sub, 4)(&m_sub, afValue);
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* array, int numElements, int sizeElem);

struct CA92A0Element
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
};

static __forceinline void CA92A0Array_reserve(hkArrayBase<CA92A0Element>& self, hkMemoryAllocator& alloc, int n);

static __forceinline hkArrayBase<CA92A0Element>& CA92A0Array_assign(hkArrayBase<CA92A0Element>& self, const hkArrayBase<CA92A0Element>& a);

static __forceinline void CA92A0Array_reserve(hkArrayBase<CA92A0Element>& self, hkMemoryAllocator& alloc, int n)
{
        const int cap = self.getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, (&self), newSize, sizeof(CA92A0Element));
        }
    }

static __forceinline hkArrayBase<CA92A0Element>& CA92A0Array_assign(hkArrayBase<CA92A0Element>& self, const hkArrayBase<CA92A0Element>& a)
{
        hkMemoryAllocator& alloc = heapAllocator(hkMemoryRouter_getInstance());
        const int oldSize = self.m_iElementCount;
        const int newSize = a.m_iElementCount;
        const int copiedSize = newSize > oldSize ? oldSize : newSize;
        CA92A0Array_reserve(self, alloc, newSize);
        {
            const CA92A0Element* src = a.m_data;
            CA92A0Element* dst = self.m_data;
            for (int i = 0; i < copiedSize; i++)
                dst[i] = src[i];
        }
        {
            const CA92A0Element* src = a.m_data + copiedSize;
            CA92A0Element* dst = self.m_data + copiedSize;
            for (int i = 0; i < newSize - copiedSize; i++)
                new (dst + i) CA92A0Element(src[i]);
        }
        self.m_iElementCount = newSize;
        return *(&self);
    }

struct CA92A0ArrayPolicy
{
    static __forceinline void destroy(hkArrayBase<CA92A0Element>& self) { }
    static __forceinline void assign(hkArrayBase<CA92A0Element>& self, const hkArrayBase<CA92A0Element>& other) { CA92A0Array_assign(self, other); }
};

struct CA92A0Object
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
    hkArray<CA92A0Element, CA92A0ArrayPolicy> m_entries;

    void CopyEntriesFrom(const CA92A0Object* other);
};

// Copies the m_entries array from other into this object's m_entries via the array assignment operator.
// @fnv 0x00ca92a0
void CA92A0Object::CopyEntriesFrom(const CA92A0Object* other)
{
    m_entries = other->m_entries;
}

extern int DAT_010c6c64;

static __forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    do
    {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d += 4;
        s += 4;
    } while (--numQuads > 0);
}

__declspec(align(16)) struct FnvScratch
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    void InitializePhysicsFields();
};

struct FnvThing
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* v0C(void* pOwner);
};

struct FUN_00ca90c0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    FUN_00ca90c0_cls* Clone();
    void WriteToInfo(FnvScratch* pScratch);
    FUN_00ca90c0_cls* AllocateStorage_00ca8c90(FnvScratch* pScratch);
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual int v10();
    void CopyEntriesFrom(FUN_00ca90c0_cls* pSrc);
};

// @fnv 0x00ca90c0
FUN_00ca90c0_cls* FUN_00ca90c0_cls::Clone()
{
    FnvScratch cinfo;
    cinfo.InitializePhysicsFields();
    WriteToInfo(&cinfo);
    FUN_00ca90c0_cls* pBlock = (FUN_00ca90c0_cls*)heapAllocator(hkMemoryRouter_getInstance()).blockAlloc(0x220);
    *(unsigned short*)((char*)pBlock + 4) = 0x220;
    FUN_00ca90c0_cls* pCopy = pBlock->AllocateStorage_00ca8c90(&cinfo);
    memCpy16NonEmpty((char*)pCopy + 0xe0, (char*)this + 0xe0, 0x12);
    if (*(char**)((char*)this + 0x1f8))
    {
        char* pObj = (char*)heapAllocator(hkMemoryRouter_getInstance()).blockAlloc(0x120);
        *(unsigned short*)(pObj + 4) = 0x120;
        *(int*)(pObj + 0x118) = 0;
        *(int*)pObj = (int)&DAT_010c6c64;
        *(char**)((char*)pCopy + 0x1f8) = pObj;
        memCpy16NonEmpty(pObj, *(char**)((char*)this + 0x1f8), 0x12);
    }
    *(int*)((char*)pCopy + 0x18) = pCopy->v10();
    pCopy->CopyEntriesFrom(this);
    ((hkStringPtr*)((char*)pCopy + 0x74))->Assign(reinterpret_cast<const char*>(*(unsigned int*)((char*)this + 0x74) & 0xfffffffe));
    *(int*)((char*)pCopy + 0xc) = *(int*)((char*)this + 0xc);
    if (*(void**)((char*)this + 0xa0))
        *(void**)((char*)pCopy + 0xa0) = ((FnvThing*)*(void**)((char*)this + 0xa0))->v0C(pCopy);
    return pCopy;
}

class HostCA8B
{
  public:
    int unk00, unk04, unk08, unk0C;
    const hkpShape* m_pCollisionShape;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC;
    int unkD0, unkD4, unkD8, unkDC, unkE0, unkE4;
    unsigned char m_bFlag;

    hkBool CheckShapeTypeAndChildLimit() const;
};

// Returns false for a null shape, type 0xf, or types 7, 8, 9, 10, 0x17 with over 100 child shapes (8 and 10 are skipped when m_bFlag is 4 or 5); else true.
// @fnv 0x00ca8bf0
// src: GUESS 0x00ca8bf0 (confidence: medium)
hkBool HostCA8B::CheckShapeTypeAndChildLimit() const
{
    const hkpShape* shape = m_pCollisionShape;
    if (!shape)
        return false;

    bool bOk = true;
    int type = *reinterpret_cast<const int*>(&shape->m_type);
    if (m_bFlag != 5 && m_bFlag != 4 && (type == 10 || type == 8))
    {
        if (shape->GetShapeContainer()->GetNumChildShapes() > 100)
            bOk = false;
    }

    if (type == 0x17)
    {
        if (static_cast<const hkpShapeCollection*>(m_pCollisionShape)->GetNumChildShapes() > 100)
            bOk = false;
    }
    else if (type == 7)
    {
        if (static_cast<const hkpShapeCollection*>(m_pCollisionShape)->GetNumChildShapes() > 100)
            bOk = false;
    }
    else if (type == 0xf)
    {
        bOk = false;
    }
    else if (type == 9)
    {
        if (static_cast<const hkpShapeCollection*>(shape)->GetNumChildShapes() > 100)
            bOk = false;
    }
    return bOk;
}

struct S_00ca84b0_Entity;

struct S_00ca84b0_Op
{
    unsigned char m_type;
    S_00ca84b0_Entity* m_pEntity;
    hkpShape* m_pCollisionShape;
};

struct S_00ca84b0_World
{
    void hkpWorld_queueOperation(const S_00ca84b0_Op& op);
    void FUN_00c91120();
    void UpdateFields_00c91140();

    __forceinline void lockCriticalOperations()
    {
        unk94++;
    }
    __forceinline void unlockAndAttemptToExecutePendingOperations()
    {
        unk94--;
        if (unk94 == 0 && !unk9c)
        {
            if (unk8c)
                FUN_00c91120();
            if (unka4 == 1 && unk90)
                UpdateFields_00c91140();
        }
    }

    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
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
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    unsigned char unk9c;
    int unka0;
    int unka4;
};

// Using the shared SIMD union for this stack temporary adds a /GS cookie in 0x00ca84b0.
struct S_00ca84b0_Vector4
{
    float x, y, z, w;
};

void hkpWorldOperationUtil_removeEntityBP(S_00ca84b0_World* world, S_00ca84b0_Entity* entity);
void hkpWorldOperationUtil_addEntityBP(S_00ca84b0_World* world, S_00ca84b0_Entity* entity);
void NotifyShapeSet(S_00ca84b0_World* world, S_00ca84b0_Entity* entity);
void hkpEntityCallbackUtil_fireEntityShapeSet(S_00ca84b0_Entity* entity);
// Same-unit static helper (0x00ca80d0): the allowed penetration depth is a fifth of the
// smallest extent, or 0.1 once that extent reaches 0.5.
static __declspec(noinline) void ComputeScaledMinimum(void* pvCollidable, const S_00ca84b0_Vector4& kExtent)
{
    const float* pfExtent = (const float*)&kExtent;
    float fMin = pfExtent[0];
    if (pfExtent[1] < fMin)
        fMin = pfExtent[1];
    if (pfExtent[2] < fMin)
        fMin = pfExtent[2];
    float* pfDepth = (float*)((char*)pvCollidable + 0x4c);
    if (fMin < 0.5f)
        *pfDepth = (float)(fMin * 0.2);
    else
        *pfDepth = 0.1f;
}

struct S_00ca84b0_Entity
{
    virtual void vf0();
    int unk4;
    S_00ca84b0_World* m_pOwningWorld;
    int unkc;
    hkpShape* m_pCollisionShape;
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
    float m_fAllowedPenetrationDepth;  // 0x5c

    void hkpRigidBody_updateCachedShapeInfo(hkpShape* shape, S_00ca84b0_Vector4* extentOut);
    void UpdateBoundingVolume(S_00ca84b0_World* world, hkpShape* shape);
    int hkpRigidBody_setShape(hkpShape* shape);
};

// Sets the entity's collision shape, updating penetration depth and notifying the owning world of the change.
// @fnv 0x00ca84b0
// src: HAVOK_LIB 0x00ca84b0
int S_00ca84b0_Entity::hkpRigidBody_setShape(hkpShape* shape)
{
    if (m_pOwningWorld && m_pOwningWorld->unk94)
    {
        S_00ca84b0_Op op;
        op.m_type = 5;
        op.m_pEntity = this;
        op.m_pCollisionShape = shape;
        m_pOwningWorld->hkpWorld_queueOperation(op);
        return 0;
    }

    if (m_pOwningWorld)
    {
        m_pOwningWorld->lockCriticalOperations();
        hkpWorldOperationUtil_removeEntityBP(m_pOwningWorld, this);
    }

    hkpShape* oldShape = m_pCollisionShape;
    m_pCollisionShape = shape;
    shape->addReference();
    if (oldShape)
        oldShape->removeReference();

    {
        __declspec(align(16)) S_00ca84b0_Vector4 extent;
        hkpRigidBody_updateCachedShapeInfo(shape, &extent);

        if (oldShape && m_fAllowedPenetrationDepth != 3.40282e38f)
            m_fAllowedPenetrationDepth = -1.0f;
        if (m_fAllowedPenetrationDepth <= 0.0f)
            ComputeScaledMinimum(&m_pCollisionShape, extent);
    }

    if (m_pOwningWorld)
        UpdateBoundingVolume(m_pOwningWorld, shape);
    if (m_pOwningWorld)
        NotifyShapeSet(m_pOwningWorld, this);
    hkpEntityCallbackUtil_fireEntityShapeSet(this);
    if (m_pOwningWorld)
    {
        hkpWorldOperationUtil_addEntityBP(m_pOwningWorld, this);
        m_pOwningWorld->unlockAndAttemptToExecutePendingOperations();
    }
    return 1;
}

#include <xmmintrin.h>
namespace fnv_00ca8af0 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct EventBlock
{
    unsigned char m_type;
    void* m_pSender;
    void* m_pData;
};

struct EventDispatcher
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
    int m_94;

    void hkpWorld_queueOperation(EventBlock* ev);
};

struct FUN_00ca8af0_cls
{
    int unk00;
    int unk04;
    EventDispatcher* m_08;
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    hkpMotion m_e0;

    void DispatchEvent(void* a1, void* a2);
    void activate_00c9c1d0();
};

// @fnv 0x00ca8af0
void FUN_00ca8af0_cls::DispatchEvent(void* a1, void* a2)
{
    if (m_08 != 0)
    {
        if (m_08->m_94 != 0)
        {
            EventBlock ev;
            ev.m_type = 0x1c;
            ev.m_pSender = this;
            hkMemoryRouter* holder = hkMemoryRouter_getInstance();
            ev.m_pData = holder->m_heap->blockAlloc(0x20);
            *(__m128*)ev.m_pData = *(__m128*)a2;
            *(__m128*)((char*)ev.m_pData + 0x10) = *(__m128*)a1;
            m_08->hkpWorld_queueOperation(&ev);
            return;
        }
    }
    activate_00c9c1d0();
    motionVirtual<void(__thiscall*)(hkpMotion*, void*, void*)>(m_e0, 20)(&m_e0, a1, a2);
}
}  // namespace fnv_00ca8af0

extern float DAT_010c7948[];
struct S_00ca8f50_Info
{
    int m0;
    int m4;
    int m8;
    unsigned char mC;
    unsigned char unkD;
    short mE;
    hkVector4 m10;
    hkVector4 m20;
    hkVector4 m30;
    hkVector4 m40;
    hkRotation m50;
    hkVector4 m80;
    float m90;
    float m94;
    float m98;
    float m9C;
    float mA0;
    float mA4;
    float mA8;
    float mAC;
    float mB0;
    unsigned char mB4;
    unsigned char mB5;
    unsigned char mB6;
    unsigned char mB7;
    unsigned char mB8;
    unsigned char mB9;
    unsigned char mBA;
    unsigned char mBB;
    int unkBC;
};

struct S_00ca8f50_Src
{
    bool hkpRigidBody_isDeactivationEnabled();
    void WriteToInfo(S_00ca8f50_Info* info);
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int m10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char unk20;
    unsigned char m21;
    unsigned char unk22;
    unsigned char unk23;
    int unk24;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char m2A;
    unsigned char unk2B;
    int m2C;
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
    float m5C;
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
    unsigned char m8C;
    unsigned char unk8D;
    unsigned char unk8E;
    unsigned char unk8F;
    float m90;
    float m94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    unsigned char unkA8;
    unsigned char unkA9;
    short mAA;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    unsigned char mD0;
    unsigned char mD1;
    unsigned char unkD2;
    unsigned char unkD3;
    int unkD4;
    int unkD8;
    int unkDC;
    hkpMotion mE0;
    char pad200[0x10];
    int m210;
    int unk214;
    int unk218;
    int unk21C;
};

// Copies fields from this S_00ca8f50_Src into the given S_00ca8f50_Info, including vectors, a transform, and lookup-table values.
// @fnv 0x00ca8f50
void S_00ca8f50_Src::WriteToInfo(S_00ca8f50_Info* info)
{
    info->mBB = m21 & 1;
    info->mB8 = mD0;
    info->mBA = mD1;
    info->mE = mAA;
    info->mB5 = hkpRigidBody_isDeactivationEnabled();
    info->m8 = m210;
    info->mA0 = m90;
    info->mC = m8C;
    info->mA4 = m94;
    info->m94 = mE0.m_kMotionState.m_fLinearDamping;
    info->m98 = mE0.m_kMotionState.m_fAngularDamping;
    info->m30.m_vComponents = mE0.m_kTranslationalVelocity.m_vComponents;
    info->m40.m_vComponents = mE0.m_kAngularVelocity.m_vComponents;
    info->m90 = mE0.GetMassValue();
    motionVirtual<void(__thiscall*)(hkpMotion*, hkRotation&)>(mE0, 5)(&mE0, info->m50);
    info->mB4 = *reinterpret_cast<unsigned char*>(&mE0.m_type);
    info->mB6 = mE0.m_kMotionState.m_uiDeactivationClass;
    info->mA8 = DAT_010c7948[*reinterpret_cast<const unsigned char*>(&mE0.m_kMotionState.m_fSurfaceFriction)];
    info->mAC = DAT_010c7948[*reinterpret_cast<const unsigned char*>(&mE0.m_kMotionState.m_fRestitution)];
    info->m10.m_vComponents = mE0.m_kMotionState.m_kMotionTransform.m_row3;
    info->m20.m_vComponents = *reinterpret_cast<const __m128*>(&mE0.m_kMotionState.m_kSweptTransform.m_qRotation1);
    info->m80.m_vComponents = mE0.m_kMotionState.m_kSweptTransform.m_vCenterOfMassLocal.m_vComponents;
    info->m4 = m10;
    info->m0 = m2C;
    info->mB0 = m5C;
    info->mB7 = m2A;
    int gravityBits = ((int)mE0.m_fGravityFactor.m_value) << 16;
    info->m9C = *reinterpret_cast<float*>(&gravityBits);
}

namespace fnv_00ca9210 {

hkMemoryRouter* hkMemoryRouter_getInstance();

struct FUN_00ca9210 : hkReferencedObject
{
    FUN_00ca9210();
    virtual ~FUN_00ca9210() throw();
    static void operator delete(void* p)
    {
        hkReferencedObject* b = static_cast<hkReferencedObject*>(p);
        heapAllocator(*hkMemoryRouter_getInstance()).blockFree(p, b->m_usMemSizeAndFlags);
    }
};

// @fnv 0x00ca9210
FUN_00ca9210::FUN_00ca9210()
{}
}  // namespace fnv_00ca9210

struct Entity;
struct World;

struct Manager
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
    virtual void v8(void* ents, int count, World* world, int flags);
};

struct Holder5c
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void v5(int x);
};

struct World
{
    int unk00;
    int unk04;
    Manager* m_8;
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
    Holder5c* m_5c;
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
    int m_8c;
    int m_90;
    int m_94;
    int unk98;
    unsigned char m_9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
    int unk_a0;
    int m_a4;
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
    unsigned char unk_d4;
    unsigned char unk_d5;
    unsigned char m_d6;
    void __thiscall hkpWorld_queueOperation(void* op);
    void __thiscall FUN_00c91120();
    void __thiscall UpdateFields_00c91140();
};

struct Entity
{
    int unk00;
    int unk04;
    World* m_8;
    int unk0c;
    int m_10;
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
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    unsigned char m_e8;
    unsigned char* __thiscall isActive_00c9bff0(unsigned char* out);
    void __thiscall activate_00c9c1d0();
};

struct Op
{
    unsigned char type;
    void* entity;
};

extern void __cdecl hkpSimulation_collideEntitiesBroadPhaseDiscrete(void* ents, int count, World* world);
extern void __cdecl NotifyEntityRemoved(World* world, Entity* entity);

// Processes an entity by dispatching an operation, updating the world manager, and handling post-processing callbacks based on world state.
// @fnv 0x00ca8700
// src: HAVOK_LIB 0x00ca8700
void __cdecl hkpRigidBody_updateBroadphaseAndResetCollisionInformationOfWarpedBody(Entity* apEntity)
{
    Op op;
    World* world = apEntity->m_8;

    if (!world)
        return;

    if (world->m_94 != 0)
    {
        op.type = 0x16;
        op.entity = apEntity;
        world->hkpWorld_queueOperation(&op);
        return;
    }

    world->m_94 = 1;
    {
        Entity* ents[1];
        Manager* pManager = world->m_8;
        ents[0] = apEntity;
        pManager->v8(ents, 1, world, 7);

        if (apEntity->m_10 != 0)
            hkpSimulation_collideEntitiesBroadPhaseDiscrete(ents, 1, world);
    }

    unsigned char flag;
    if (!*apEntity->isActive_00c9bff0(&flag))
    {
        if (world->m_d6 != 0 && apEntity->m_e8 != 5)
            apEntity->activate_00c9c1d0();
        NotifyEntityRemoved(world, apEntity);
    }

    if (world->m_5c != 0)
        world->m_5c->v5(0);

    world->m_94 -= 1;
    if (world->m_94 == 0 && world->m_9c == 0)
    {
        if (world->m_8c != 0)
            world->FUN_00c91120();
        if (world->m_a4 == 1 && world->m_90 != 0)
            world->UpdateFields_00c91140();
    }
}

// @fnv 0x00ca8920
// src: HAVOK_LIB 0x00ca8920
void __fastcall hkpRigidBody_setInertiaLocal(FUN_00ca8860_cls* body, void*, int inertia)
{
    hkpMotion* motion = &body->m_sub;
    typedef void(__thiscall * SetInertia)(hkpMotion*, int);
    SetInertia set = motionVirtual<SetInertia>(*motion, 7);
    set(motion, inertia);
}



template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    __if_exists(A::destroy) { A::destroy(*this); }
    __if_not_exists(A::destroy) { clearAndDeallocate(); }
}

template <class T, class A> __forceinline hkArray<T, A>& hkArray<T, A>::operator=(const hkArray<T, A>& other)
{
    A::assign(*this, other);
    return *this;
}
