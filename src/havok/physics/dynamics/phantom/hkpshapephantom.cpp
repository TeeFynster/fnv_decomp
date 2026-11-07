
// src/havok/physics/dynamics/phantom/hkpshapephantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpshapephantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkpCollidable.h"

typedef unsigned short hkUint16;
typedef short hkInt16;
typedef unsigned int hkUint32;
typedef unsigned long hkUlong;

struct FUN_00c9ea00__VirtualObject
{
    virtual void FUN_00c9ea00__M0();
    virtual void FUN_00c9ea00__M1();
    virtual void FUN_00c9ea00__M2();
    virtual void FUN_00c9ea00__M3();
    virtual void FUN_00c9ea00__M4();
    virtual void FUN_00c9ea00__M5();
    virtual void FUN_00c9ea00__M6();
    virtual void FUN_00c9ea00__M7(void*, float, void*);
};

// @fnv 0x00c9ea00
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M0()
{}
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M1()
{}
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M2()
{}
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M3()
{}
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M4()
{}
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M5()
{}
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M6()
{}
inline void FUN_00c9ea00__VirtualObject::FUN_00c9ea00__M7(void*, float, void*)
{}

double DAT_01011588 = 0.5;

struct FUN_00c9ea00__Class
{
    void hkpShapePhantom_calcAabb(void*);
};

// src: HAVOK_LIB 0x00c9ea00
void FUN_00c9ea00__Class::hkpShapePhantom_calcAabb(void* arg)
{
    unsigned char* this_base = reinterpret_cast<unsigned char*>(this);
    unsigned char* outer = *reinterpret_cast<unsigned char**>(this_base + 8);
    unsigned char* inner = *reinterpret_cast<unsigned char**>(outer + 0x78);
    float value = *reinterpret_cast<float*>(inner + 8);
    float scaled = static_cast<float>(DAT_01011588 * value);
    FUN_00c9ea00__VirtualObject* object = *reinterpret_cast<FUN_00c9ea00__VirtualObject**>(this_base + 0x10);

    object->FUN_00c9ea00__M7(reinterpret_cast<void*>(this_base + 0xb0), scaled, arg);
}

struct CpuObject
{
    char* hkpShapePhantom_getMotionState();
};
// @fnv 0x00c9e810
// src: HAVOK_SRC 0x00c9e810
char* CpuObject::hkpShapePhantom_getMotionState()
{
    return reinterpret_cast<char*>(this) + 176;
}

void FreeListenerArrays();
// @fnv 0x00c9e820
// src: HAVOK_SRC 0x00c9e820
void hkpShapePhantom_deallocateInternalArrays()
{
    FreeListenerArrays();
}

class FUN_00c9ea40
{
  public:
    virtual ~FUN_00c9ea40() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    void* m_pOwningWorld;
    hkUlong m_ulUserData;
    hkpCollidable m_kCollidable;
    // The remaining world-object, phantom, and motion-state fields start at +0x60.
    char m_pad60[0x100];

    FUN_00c9ea40(const hkpShape* pkShape, const hkTransform& kTransform) throw();
};

struct hkpCollisionDetailD4CE
{
    void* m_kCollidable;
    void* m_pCollisionAgent;
};

class FUN_00d4ce10 : public FUN_00c9ea40
{
  public:
    hkArray<hkpCollisionDetailD4CE> m_kCollisionDetails;
    hkBool m_bOrderDirty;

    FUN_00d4ce10(const hkpShape* pkShape, const hkTransform& kTransform,
                 hkUint32 uiCollisionFilterInfo) throw();
    virtual ~FUN_00d4ce10() throw();
};

typedef char fnv_check_d4ce10[(sizeof(FUN_00d4ce10) == 0x170) ? 1 : -1];

// Constructs the object from a shape and transform, clears the bool flag, and stores the collision filter info in the collidable.
// @fnv 0x00d4ce10
FUN_00d4ce10::FUN_00d4ce10(const hkpShape* pkShape, const hkTransform& kTransform,
                           hkUint32 uiCollisionFilterInfo) throw()
    : FUN_00c9ea40(pkShape, kTransform)
{
    m_bOrderDirty = false;
    m_kCollidable.m_kBroadPhaseHandle.m_uiCollisionFilterData = uiCollisionFilterInfo;
}

struct S00c9e830_Operation
{
    unsigned char type;
    void* object;
    unsigned int parameter;
};

struct S00c9e830_Owner
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    int unk94;
    unsigned char unk98;
    unsigned char unk99;
    unsigned char unk9A;
    unsigned char unk9B;
    unsigned char unk9C;
    unsigned char unk9D;
    unsigned char unk9E;
    unsigned char unk9F;
    unsigned char unkA0;
    unsigned char unkA1;
    unsigned char unkA2;
    unsigned char unkA3;
    int unkA4;

    void hkpWorld_queueOperation(S00c9e830_Operation* operation);
    void FUN_00c91120();
    void UpdateFields_00c91140();
    __forceinline void unlockAndAttemptToExecutePendingOperations()
    {
        --unk94;
        if (unk94 == 0 && unk9C == 0)
        {
            if (unk8C != 0)
                FUN_00c91120();
            if (unkA4 == 1 && unk90 != 0)
                UpdateFields_00c91140();
        }
    }
};

struct S00c9e830_Shape
{
    void FUN_00c90510();
    void FUN_00c905b0();
};

extern "C" void __cdecl hkpWorldOperationUtil_removePhantomBP(S00c9e830_Owner* owner, void* object);
extern "C" void __cdecl hkpWorldCallbackUtil_firePhantomShapeSet(S00c9e830_Owner* owner, void* object);
extern "C" void __cdecl QueryEntityIntoBuffer(S00c9e830_Owner* owner, void* object);

struct S00c9e830_Obj
{
    void* unk00;
    void* unk04;
    S00c9e830_Owner* unk08;
    void* unk0C;
    S00c9e830_Shape* unk10;

    void NotifyListeners();
    unsigned int hkpShapePhantom_setShape(S00c9e830_Shape* parameter);
};

// Sets the object's shape to the given parameter, notifying listeners and the owner, or queues the operation if the owner is locked.
// @fnv 0x00c9e830
// src: HAVOK_LIB 0x00c9e830
unsigned int S00c9e830_Obj::hkpShapePhantom_setShape(S00c9e830_Shape* apShape)
{
    S00c9e830_Operation operation;

    if (unk08 != 0 && unk08->unk94 != 0)
    {
        operation.type = 5;
        operation.object = this;
        operation.parameter = reinterpret_cast<unsigned int>(apShape);
        unk08->hkpWorld_queueOperation(&operation);
        return 0;
    }

    if (unk08 != 0)
    {
        ++unk08->unk94;
        hkpWorldOperationUtil_removePhantomBP(unk08, this);
    }

    apShape->FUN_00c90510();

    if (unk10 != 0)
        unk10->FUN_00c905b0();

    unk10 = apShape;

    if (unk08 != 0)
        hkpWorldCallbackUtil_firePhantomShapeSet(unk08, this);

    this->NotifyListeners();

    if (unk08 != 0)
    {
        QueryEntityIntoBuffer(unk08, this);
        unk08->unlockAndAttemptToExecutePendingOperations();
    }

    return 1;
}

#include <xmmintrin.h>
struct FUN_00c9e910_Inner
{
    int unk00;
    int unk04;
    float unk08;
};

struct FUN_00c9e910_Outer
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
    FUN_00c9e910_Inner* m_pInner;
};

struct __declspec(align(16)) FUN_00c9e910_Temporary
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class FUN_00c9e910_Class
{
  public:
    void* m_pVtable;
    int unk04;
    FUN_00c9e910_Outer* unk08;
    int unk0C;
    FUN_00c9ea00__VirtualObject* unk10;
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
    __m128 unkB0;
    __m128 unkC0;
    __m128 unkD0;
    __m128 unkE0;

    void hkpPhantom_updateBroadPhase(void* value);
    void hkpShapePhantom_setTransform(int value);
};

// Copies 16 floats from value into unkB0..unkE0; if unk08 is set, calls unk10's method with value and a scaled factor, then passes the result to FUN_00d07ec0.
// @fnv 0x00c9e910
// src: XBOX_PDB 0x00c9e910
void FUN_00c9e910_Class::hkpShapePhantom_setTransform(int value)
{
    const float* pMatrixData = reinterpret_cast<const float*>(value);

    _mm_store_ps(reinterpret_cast<float*>(&unkB0), _mm_load_ps(pMatrixData));
    _mm_store_ps(reinterpret_cast<float*>(&unkC0), _mm_load_ps(pMatrixData + 4));
    _mm_store_ps(reinterpret_cast<float*>(&unkD0), _mm_load_ps(pMatrixData + 8));
    _mm_store_ps(reinterpret_cast<float*>(&unkE0), _mm_load_ps(pMatrixData + 12));

    if (unk08)
    {
        float scaled = unk08->m_pInner->unk08 * DAT_01011588;
        FUN_00c9e910_Temporary temporary;

        unk10->FUN_00c9ea00__M7(reinterpret_cast<void*>(value), scaled, &temporary);
        hkpPhantom_updateBroadPhase(&temporary);
    }
}

struct FUN_00c9e990_Local
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct FUN_00c9e990_Inner
{
    int unk00;
    int unk04;
    float unk08;
};
struct FUN_00c9e990_Outer
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
    FUN_00c9e990_Inner* unk78;
};
struct FUN_00c9e990_VO
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void M7(void* a, float b, void* c);
};
struct FUN_00c9e990_cls
{
    int unk00;
    int unk04;
    FUN_00c9e990_Outer* m_08;
    int unk0C;
    FUN_00c9e990_VO* m_10;
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
    __m128 unkE0;
    void hkpShapePhantom_setPosition(__m128* a, float b);
    void hkpPhantom_updateBroadPhase(void* a1);
};
// Stores *a in unkE0 and, if m_08 is set, calls m_10->M7 with &unkB0, b plus half of m_08->unk78->unk08, and a local buffer, then FUN_00d07ec0 on it.
// @fnv 0x00c9e990
// src: XBOX_PDB 0x00c9e990
void FUN_00c9e990_cls::hkpShapePhantom_setPosition(__m128* a, float b)
{
    unkE0 = *a;
    if (m_08 != 0)
    {
        float scaled = m_08->unk78->unk08 * 0.5;
        float sum = scaled + b;
        FUN_00c9e990_Local local;
        m_10->M7(&unkB0, sum, &local);
        hkpPhantom_updateBroadPhase(&local);
    }
}
