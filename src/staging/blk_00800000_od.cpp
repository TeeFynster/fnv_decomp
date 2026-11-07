
// src/staging/blk_00800000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/NiPointer.h"
#include "../../include/ActiveEffect.h"
#include "../../include/ConcussionEffect.h"
#include "../../include/ValueModifierEffect.h"
#include "../../include/GO.h"
#include "../../include/GameTimerRecord.h"
#include "../../include/Mat3.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiNode.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/NiMatrix3.h"
#include "../../include/hkVector4.h"
#include "../../include/hkpEntity.h"
#include "../../include/Setting.h"
#include "../../include/bhkWorldObject.h"

struct FUN_008009d0_cls
{
    void FOVATSEffectManager_DisableScan();
};

// If the byte at offset 0x2b4 is set, writes 1 to the byte at offset 0x2b5.
// @fnv 0x008009d0
// src: XBOX_PDB 0x008009d0
void FUN_008009d0_cls::FOVATSEffectManager_DisableScan()
{
    if (*(unsigned char*)((char*)this + 0x2b4))
        *(char*)((char*)this + 0x2b5) = 1;
}

// Exe 0x00800a90: unit-local Interface view; declarations and layout are preserved.
struct BlkInterfaceView
{
    static void __cdecl PrintDebugMessage(const char*);
};

struct FUN_00800a90
{
    void __thiscall SetOcclusionDisabled();
};

// Prints an occlusion-disabled message and clears the byte at offset 0x118 of this object.
// @fnv 0x00800a90
void __thiscall FUN_00800a90::SetOcclusionDisabled()
{
    BlkInterfaceView::PrintDebugMessage("--==OCCLUSION DISABLED==--\n");
    ((char*)this)[0x118] = 0;
}

extern int DAT_01079170;
struct FUN_00802b20_class
{
    int* p;
    void __thiscall InitBuffer(int);
    int __thiscall NiTMap_unsigned_int_IDebugTextPage_NiTMap(int a);
};
// Calls InitBuffer with a, sets p to point at DAT_01079170, and returns this.
// @fnv 0x00802b20
// src: EXE 0x00802b20
int __thiscall FUN_00802b20_class::NiTMap_unsigned_int_IDebugTextPage_NiTMap(int a)
{
    InitBuffer(a);
    p = &DAT_01079170;
    return (int)this;
}

struct FUN_00807770_Class
{
    int __thiscall EvaluateValue_00807770(int);
};

// @fnv 0x00807770
// src: GUESS 0x00807770 (confidence: low)
int __thiscall FUN_00807770_Class::EvaluateValue_00807770(int aiIndex)
{
    return aiIndex * 0x70 + *(int*)this;
}

extern float DAT_011dc778;

// @fnv 0x0080fae0
// src: XBOX_PDB 0x0080fae0
void MagicProjectile_AddTrackedProjectile(float value)
{
    DAT_011dc778 += value;
}

hkVector4& __cdecl NI2HK(hkVector4&, NiPoint3 const&);

struct FUN_00810510_Class
{
    void __thiscall bhkCharacterControllerCinfo_SetPosition(NiPoint3 const&);
};

// @fnv 0x00810510
// src: XBOX_PDB 0x00810510
void __thiscall FUN_00810510_Class::bhkCharacterControllerCinfo_SetPosition(NiPoint3 const& aPoint)
{
    NI2HK(*(hkVector4*)this, aPoint);
}

struct FUN_00810550_class
{
    void bhkCharacterControllerCinfo_SetAcrobatics(float value);
};

// @fnv 0x00810550
// src: XBOX_PDB 0x00810550
void FUN_00810550_class::bhkCharacterControllerCinfo_SetAcrobatics(float value)
{
    *(float*)((char*)this + 0x8c) = value;
}

struct FUN_008105c0_Class
{
    void SetPointer(void* p);
};
// @fnv 0x008105c0
void FUN_008105c0_Class::SetPointer(void* apValue)
{
    ((GO*)((char*)this + 0xa0))->operator=(apValue);
}

struct Dummy629670
{
    void bhkCharacterListener_SetFlag(int, bool);
};
struct FUN_008105e0_Class
{
    char pad[0x410];
    Dummy629670 d;
    void bhkCharacterController_SetProjectile(bool b);
};
// @fnv 0x008105e0
// src: XBOX_PDB 0x008105e0
void FUN_008105e0_Class::bhkCharacterController_SetProjectile(bool b)
{
    d.bhkCharacterListener_SetFlag(0x80000, b);
}

namespace fnv_00810610 {
struct Dummy629670
{
    void bhkCharacterListener_SetFlag(int a, bool b);
};

struct FUN_00810610_Class
{
    void bhkCharacterController_SetQuickSimulate(bool b);
};

// @fnv 0x00810610
// src: XBOX_PDB 0x00810610
void FUN_00810610_Class::bhkCharacterController_SetQuickSimulate(bool b)
{
    ((Dummy629670*)((char*)this + 0x410))->bhkCharacterListener_SetFlag(0x100000, b);
}
}  // namespace fnv_00810610

struct FUN_00810640_class
{
    void __thiscall bhkCharacterController_SetBSReference(int, int);
    void __thiscall bhkCharacterController_SetMOBObject(int a);
};
// @fnv 0x00810640
// src: XBOX_PDB 0x00810640
void __thiscall FUN_00810640_class::bhkCharacterController_SetMOBObject(int aiValue)
{
    bhkCharacterController_SetBSReference(1000, aiValue);
}

struct FUN_008106b0_Class
{
    void bhkCharacterController_SetFallTime(float value);
};

// @fnv 0x008106b0
// src: COMMUNITY 0x008106b0
void FUN_008106b0_Class::bhkCharacterController_SetFallTime(float value)
{
    *(float*)((char*)this + 0x548) = value;
}

struct FUN_008133b0_class
{
    float GetFloatAt144();
};

// @fnv 0x008133b0
float FUN_008133b0_class::GetFloatAt144()
{
    return *(float*)((char*)this + 0x144);
}

struct FUN_00819a70_class
{
    void NiPSysSpawnModifier_SetLifeSpan(float value);
};

// @fnv 0x00819a70
// src: XBOX_PDB 0x00819a70
void FUN_00819a70_class::NiPSysSpawnModifier_SetLifeSpan(float value)
{
    *(float*)((char*)this + 0x2c) = value;
}

extern int DAT_01079190;
extern "C" void* __cdecl NiFreeAlias(void*);

struct FUN_00802c50
{
    void* vft;
    int a;
    int b;
    void Init();
};

// Sets the vtable pointer, clears the map via RemoveAll, and frees the b pointer with NiFreeAlias.
// @fnv 0x00802c50
void FUN_00802c50::Init()
{
    vft = &DAT_01079190;
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    NiFreeAlias((void*)b);
}

struct FUN_00800700_Class
{
    void __thiscall FOVATSEffectManager_TriggerScan();
};
// If the byte at offset 0x2b4 is clear, sets it to 1 and initializes the floats at 0x2b8 to -1.0 and 0x2bc to 0.0.
// @fnv 0x00800700
// src: COMMUNITY 0x00800700
void __thiscall FUN_00800700_Class::FOVATSEffectManager_TriggerScan()
{
    if (!((unsigned char*)this)[0x2b4])
    {
        ((unsigned char*)this)[0x2b4] = 1;
        *(float*)((char*)this + 0x2b8) = -1.0f;
        *(float*)((char*)this + 0x2bc) = 0.0f;
    }
}

struct FUN_00800740_Class
{
    void FOVATSEffectManager_UpdateBurst(float f);
};
// @fnv 0x00800740
// src: COMMUNITY 0x00800740
void FUN_00800740_Class::FOVATSEffectManager_UpdateBurst(float f)
{
    float v = f - *(float*)((char*)this + 0x29c);
    float r;
    if (v > *(float*)((char*)this + 0x2a0))
        *(char*)((char*)this + 0x298) = 0;
    else
    {
        r = 1.0f - v / *(float*)((char*)this + 0x2a0);
        *(float*)((char*)this + 0x2a8) = *(float*)((char*)this + 0x2a4) * r;
    }
}

struct GlobalObject_0044f440
{
    float* Float();
};
extern GlobalObject_0044f440 g_011db6c8;
extern GlobalObject_0044f440 g_011db7c4;
extern GlobalObject_0044f440 g_011db7d8;
float __cdecl ApplyNoise(float);

struct FUN_008007b0_Class
{
    void __thiscall SetScaledValues(float value);
};

// @fnv 0x008007b0
void __thiscall FUN_008007b0_Class::SetScaledValues(float value)
{
    float result = ApplyNoise(value * *g_011db7d8.Float()) * 2.0f;
    *(float*)((char*)this + 0x2ac) = result * *g_011db7c4.Float();
    *(float*)((char*)this + 0x2b0) = result * *g_011db6c8.Float();
}

struct FUN_00800d10_class
{
    void __thiscall AppendValue(int value);
};
// Stores value into the int array at offset 0x244 using the count at offset 0x240 as index, then increments that count.
// @fnv 0x00800d10
void FUN_00800d10_class::AppendValue(int value)
{
    ((int*)((char*)this + 0x244))[*(int*)((char*)this + 0x240)] = value;
    *(int*)((char*)this + 0x240) += 1;
}

void __cdecl operator delete(void*);

struct FUN_00802bf0_Class
{
    void __thiscall FUN_00802bf0();
};

struct FUN_00802b50_Class
{
    void* __thiscall Destroy(unsigned int flags);
};

// Calls FUN_00802bf0 on this, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x00802b50
void* __thiscall FUN_00802b50_Class::Destroy(unsigned int flags)
{
    ((FUN_00802bf0_Class*)this)->FUN_00802bf0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
struct FUN_00802b80_t
{
    void* __thiscall InitBuffer(int a);
};
// Sets the vtable, stores a count, allocates count*4 bytes, zeroes them, and returns this.
// @fnv 0x00802b80
void* __thiscall FUN_00802b80_t::InitBuffer(int aiCount)
{
    *(int*)this = (int)&DAT_01079190;
    *(int*)((char*)this + 4) = aiCount;
    *(int*)((char*)this + 12) = 0;
    int s = *(int*)((char*)this + 4) * 4;
    *(int*)((char*)this + 8) = (int)NiMalloc(s);
    memset(*(void**)((char*)this + 8), 0, *(int*)((char*)this + 4) * 4);
    return this;
}

// These physics wrappers call bhkWorldObject's Havok-object accessor at 0x004ae750.
struct FUN_008078b0_Class
{
    void __thiscall bhkEntity_AddContactListener(void* listener);
};
// @fnv 0x008078b0
// src: XBOX_PDB 0x008078b0
void __thiscall FUN_008078b0_Class::bhkEntity_AddContactListener(void* listener)
{
    void* entity = ((bhkWorldObject*)this)->Bipedanim_GetReferenceFlagsOrZero();
    if (entity)
        ((hkpEntity*)entity)->AddContactListener(listener);
}

void __cdecl Deallocate(void*);
struct FUN_00825740_Class
{
    void __thiscall FUN_00825740();
};
struct FUN_0080c490_Class
{
    void* __thiscall FUN_0080c490(unsigned int flags);
};
// Calls FUN_00825740 on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0080c490
void* __thiscall FUN_0080c490_Class::FUN_0080c490(unsigned int flags)
{
    ((FUN_00825740_Class*)this)->FUN_00825740();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_0080fb00 {
struct FUN_00cac960_class
{
    void __thiscall hkpCharacterProxy_setLinearVelocity(int a);
};
struct FUN_0080fb00_Class
{
    void __thiscall bhkCharacterProxy_SetLinearVelocity(int a);
};
// @fnv 0x0080fb00
// src: XBOX_PDB 0x0080fb00
void __thiscall FUN_0080fb00_Class::bhkCharacterProxy_SetLinearVelocity(int a)
{
    void* r = ((bhkWorldObject*)this)->Bipedanim_GetReferenceFlagsOrZero();
    if (r)
        ((FUN_00cac960_class*)r)->hkpCharacterProxy_setLinearVelocity(a);
}
}  // namespace fnv_0080fb00

void __cdecl Deallocate(void*);
struct FUN_0081c240_class
{
    void __thiscall FUN_0081c240();
};
struct FUN_0080fcc0_class
{
    void* __thiscall FUN_0080fcc0(unsigned int flags);
};
// Calls FUN_0081c240 on this, then frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0080fcc0
void* __thiscall FUN_0080fcc0_class::FUN_0080fcc0(unsigned int flags)
{
    ((FUN_0081c240_class*)this)->FUN_0081c240();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct Flt
{
    operator unsigned int();
};
struct FUN_00c85c80_Class
{
    unsigned int bhkWorldObject_GetAVObject(int);
};
struct FUN_00810660_Class
{
    char pad[0x594];
    Flt f;
    unsigned int __thiscall bhkCharacterController_GetNiObject();
};
// @fnv 0x00810660
// src: XBOX_PDB 0x00810660
unsigned int FUN_00810660_Class::bhkCharacterController_GetNiObject()
{
    return f ? reinterpret_cast<FUN_00c85c80_Class*>(f.operator unsigned int())->bhkWorldObject_GetAVObject(0) : 0;
}

struct FUN_00813370_class
{
    char pad[0x78];
    int f78;
    int f7c;
    unsigned char pad2[0x174 - 0x80];
    unsigned char f174;
    char TestFlagAndFloatRange();
};
// Returns 1 when f174 is zero and f78 is greater than or equal to f7c, otherwise 0.
// @fnv 0x00813370
// src: GUESS 0x00813370 (confidence: medium)
char FUN_00813370_class::TestFlagAndFloatRange()
{
    return !f174 && f78 >= f7c ? 1 : 0;
}

namespace fnv_0081dcd0 {
extern "C" void __cdecl Deallocate(void*);

struct FUN_0081de70_shell
{
    void __thiscall FUN_0081de70();
    void* __thiscall FUN_0081dcd0(unsigned int flags);
};

// Calls FUN_0081de70, then frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0081dcd0
void* __thiscall FUN_0081de70_shell::FUN_0081dcd0(unsigned int flags)
{
    FUN_0081de70();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_0081dcd0

struct FUN_00800e50_Class
{
    void* vft;
    int f04;
    int f08;
    int f0c;
    int f10;
    void __thiscall FOVATSEffectManager_SetMultiTarget(int a);
    void __thiscall FOVATSEffectManager_SetSelectedMultiTarget(int a);
};
// @fnv 0x00800e50
// src: COMMUNITY 0x00800e50
void __thiscall FUN_00800e50_Class::FOVATSEffectManager_SetSelectedMultiTarget(int aiValue)
{
    int result = -1;
    for (int i = 0; i < f0c; i++)
    {
        if (*(int*)((char*)this + 0x14 + i * 8) == aiValue)
            result = i;
    }
    if (result != -1)
        f10 = result;
    else if (f0c < 0x20)
    {
        f10 = f0c;
        FOVATSEffectManager_SetMultiTarget(aiValue);
    }
}


void* __cdecl operator new(unsigned int);

// Allocates and constructs a ConcussionEffect from the given MagicCaster, MagicItem and EffectItem.
// @fnv 0x0080bff0
ConcussionEffect* CreateConcussionEffect(MagicCaster* a, MagicItem* pItem, EffectItem* pEffect)
{
    return new ConcussionEffect(a, pItem, pEffect);
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct FUN_0080d6b0_t
{
    char pad[0x48];
    FUN_0080d6b0_t(int a, int b, int c);
    ~FUN_0080d6b0_t();
};
// Allocates a new FUN_0080d6b0_t object, forwarding the three arguments to its constructor, and returns the pointer.
// @fnv 0x0080d880
// src: GUESS 0x0080d880 (confidence: low)
FUN_0080d6b0_t* __cdecl Object_ForwardCall_0080d880(int a, int b, int c)
{
    return new FUN_0080d6b0_t(a, b, c);
}

class AnimIdle;
template <> NiPointer<AnimIdle>::NiPointer(AnimIdle* p);
template <> NiPointer<AnimIdle>::~NiPointer();
template <> NiPointer<AnimIdle>& NiPointer<AnimIdle>::operator=(AnimIdle* p);
struct FUN_008133d0_shell
{
    void MagicBoltProjectile_SetState(int);
};
struct P0_0081dbb0
{
    virtual void f0();
    unsigned int unk04, unk08, unk0C, unk10, unk14;
};
struct P1_0081dbb0
{
    virtual void f1();
};
struct FUN_0081dbb0 : P0_0081dbb0, P1_0081dbb0
{
    FUN_0081dbb0();
    ~FUN_0081dbb0();
    unsigned int unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84;
    float f88;
    unsigned int unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4;
};
struct FUN_008117d0 : FUN_0081dbb0
{
    NiPointer<AnimIdle> spA8;
    int iAC;
    int iB0;
    NiPointer<AnimIdle> spB4;
    NiPointer<AnimIdle> spB8;
    NiPointer<AnimIdle> spBC;
    NiPointer<AnimIdle> spC0;
    int iC4;
    BSSoundHandle kSound;
    float fD4;
    FUN_008117d0();
};

// @fnv 0x008117d0
FUN_008117d0::FUN_008117d0() : spA8(0), spB4(0), spB8(0), spBC(0), spC0(0)
{
    ((FUN_008133d0_shell*)this)->MagicBoltProjectile_SetState(0);
    f88 = 4096.0f;
    iB0 = 0;
    iC4 = 0;
    spA8 = 0;
    spB4 = 0;
    spB8 = 0;
    spBC = 0;
    fD4 = 0.0f;
}

extern GameTimerRecord g_timeGlobal;
struct FUN_00800650_Class
{
    char pad[0x298];
    bool bFlag;
    char pad2[0x29c - 0x299];
    float fTime;
    float fA;
    float fB;
    float fC;
    void __thiscall FOVATSEffectManager_TriggerBurst(float a, float b, float c);
};
// @fnv 0x00800650
// src: XBOX_PDB 0x00800650
void __thiscall FUN_00800650_Class::FOVATSEffectManager_TriggerBurst(float a, float b, float c)
{
    bFlag = true;
    fA = a;
    fC = b;
    fB = b;
    fTime = g_timeGlobal.GetTime();
}

namespace fnv_008006b0 {
extern GameTimerRecord g_timeGlobal;
struct FUN_008006b0_Class
{
    char pad[0x284];
    unsigned char f284;
    float f288;
    float f28c;
    void FOVATSEffectManager_TriggerDistort();
};
// Sets f284 to 1, stores the current time from g_timeGlobal into f288, and resets f28c to 0.0f.
// @fnv 0x008006b0
// src: COMMUNITY 0x008006b0
void FUN_008006b0_Class::FOVATSEffectManager_TriggerDistort()
{
    f284 = 1;
    f288 = g_timeGlobal.GetTime();
    f28c = 0.0f;
}
}  // namespace fnv_008006b0

extern Setting g_011db78c;
extern double DAT_01011588;
float __cdecl FUN_004e44d0(float);
struct FUN_00800820_Class
{
    void __thiscall FOVATSEffectManager_UpdateTargetPulse(float a);
};
// Computes (FUN_004e44d0(a * g_011db78c.Float()[0]) + 1.0) * DAT_01011588 and stores the result at this+0x2c0.
// @fnv 0x00800820
// src: COMMUNITY 0x00800820
void __thiscall FUN_00800820_Class::FOVATSEffectManager_UpdateTargetPulse(float afValue)
{
    float f = (FUN_004e44d0(afValue * g_011db78c.Float()[0]) + 1.0) * DAT_01011588;
    *(float*)((char*)this + 0x2c0) = f;
}

struct FUN_0080a900
{
    char pad[0x4c];
    FUN_0080a900(void*, void*, void*);
};
// Allocates and constructs a new FUN_0080a900 object from the three arguments and returns it.
// @fnv 0x0080ac70
// src: COMMUNITY 0x0080ac70
FUN_0080a900* CalmEffect_Create(void* apArg1, void* apArg2, void* apArg3)
{
    return new FUN_0080a900(apArg1, apArg2, apArg3);
}


struct FUN_0080c070 : ActiveEffect
{
    int f48;
    int f4c;
    FUN_0080c070(MagicCaster* a, MagicItem* b, EffectItem* c, int d);
};
// @fnv 0x0080c070
FUN_0080c070::FUN_0080c070(MagicCaster* a, MagicItem* pItem, EffectItem* pEffect, int d)
    : ActiveEffect(a, pItem, pEffect)
{
    f48 = d;
    f4c = -1;
}

struct FUN_0080cd30_t
{
    char pad[0x4c];
    FUN_0080cd30_t(int a, int b, int c);
    ~FUN_0080cd30_t();
};
// Allocates and constructs a FUN_0080cd30_t from three int arguments, returning the new object.
// @fnv 0x0080d120
// src: COMMUNITY 0x0080d120
FUN_0080cd30_t* __cdecl DetectLifeEffect_Create(int aiArg1, int aiArg2, int aiArg3)
{
    return new FUN_0080cd30_t(aiArg1, aiArg2, aiArg3);
}

struct FUN_0080d1a0 : ActiveEffect
{
    int f48;
    FUN_0080d1a0(MagicCaster*, MagicItem*, EffectItem*);
    ~FUN_0080d1a0();
};

// Allocates and constructs a FUN_0080d1a0 object from the three arguments and returns the new pointer.
// @fnv 0x0080d430
FUN_0080d1a0* CreateFUN_0080d1a0(MagicCaster* aiArg1, MagicItem* aiArg2, EffectItem* aiArg3)
{
    return new FUN_0080d1a0(aiArg1, aiArg2, aiArg3);
}

struct FUN_0080d900
{
    char data[0x44];
    FUN_0080d900(int, int, int);
    virtual ~FUN_0080d900();
};
// Allocates and constructs a FUN_0080d900 object from the three arguments and returns it.
// @fnv 0x0080db30
FUN_0080d900* CreateFUN_0080d900(int aiArg1, int aiArg2, int aiArg3)
{
    return new FUN_0080d900(aiArg1, aiArg2, aiArg3);
}

struct FUN_0080f390
{
    int m0, m4, m8, mc, m10, m14, m18, m1c, m20, m24, m28, m2c, m30, m34, m38, m3c, m40, m44;
    FUN_0080f390(int a, int b, int c);
};
// Allocates and constructs a FUN_0080f390 object from the three arguments, returning the new instance.
// @fnv 0x0080f660
FUN_0080f390* CreateFUN0080f390(int aiFirst, int aiSecond, int aiThird)
{
    return new FUN_0080f390(aiFirst, aiSecond, aiThird);
}

struct FUN_0080c0b0 : ActiveEffect
{
    int f48;
    int f4c;
    FUN_0080c0b0(MagicCaster* a, MagicItem* b, EffectItem* c, int d);
};

// @fnv 0x0080c0b0
FUN_0080c0b0::FUN_0080c0b0(MagicCaster* apCaster, MagicItem* apItem, EffectItem* apEffect, int d)
    : ActiveEffect(apCaster, apItem, apEffect)
{
    f48 = 0;
    f4c = d;
}

struct FUN_00802c80 : FUN_00802c50
{
    void* __thiscall DeleteThis(unsigned int flags);
};
// Calls Init, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00802c80
void* FUN_00802c80::DeleteThis(unsigned int flags)
{
    Init();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct S_0080b3a0_Obj
{
    char pad[0x48];
    S_0080b3a0_Obj(int, int, int);
};

// Allocates a new S_0080b3a0_Obj, forwarding the three integer arguments to its constructor, and returns the pointer.
// @fnv 0x0080b4e0
// src: COMMUNITY 0x0080b4e0
S_0080b3a0_Obj* CommandCreatureEffect_Create(int aiArg1, int aiArg2, int aiArg3)
{
    return new S_0080b3a0_Obj(aiArg1, aiArg2, aiArg3);
}

struct EffectStorage
{
    EffectStorage(MagicCaster*, MagicItem*, EffectItem*);
};
extern int DAT_01079b3c;
struct FUN_0080ba90 : EffectStorage
{
    FUN_0080ba90(MagicCaster* a, MagicItem* b, EffectItem* c);
};
// Constructs the EffectStorage base from the caster, item and effect item, then sets the object's vtable pointer to DAT_01079b3c.
// @fnv 0x0080ba90
FUN_0080ba90::FUN_0080ba90(MagicCaster* a, MagicItem* pItem, EffectItem* pEffectItem)
    : EffectStorage(a, pItem, pEffectItem)
{
    *(int*)this = (int)&DAT_01079b3c;
}

struct S_0080bac0_Obj
{
    char pad[0x48];
    S_0080bac0_Obj(int, int, int);
};

extern unsigned int _data_011c16bc;

// Allocates and constructs an S_0080bac0_Obj with the three given int arguments, returning the new object.
// @fnv 0x0080bbf0
// src: COMMUNITY 0x0080bbf0
S_0080bac0_Obj* __cdecl CommandHumanoidEffect_Create(int aiArg1, int aiArg2, int aiArg3)
{
    return new S_0080bac0_Obj(aiArg1, aiArg2, aiArg3);
}

// @fnv 0x0080c260
// src: COMMUNITY 0x0080c260
FUN_0080c070* __cdecl CureEffect_Create(MagicCaster* apCaster, MagicItem* apMagicItem, EffectItem* apEffectItem)
{
    return new FUN_0080c070(apCaster, apMagicItem, apEffectItem, 1);
}

// @fnv 0x0080c2e0
// src: COMMUNITY 0x0080c2e0
FUN_0080c0b0* CureParalysis_Create(MagicCaster* apCaster, MagicItem* apMagicItem, EffectItem* apEffectItem)
{
    return new FUN_0080c0b0(apCaster, apMagicItem, apEffectItem, 0x18);
}

// @fnv 0x0080c360
// src: COMMUNITY 0x0080c360
FUN_0080c070* __cdecl CureAddition_Create(MagicCaster* apCaster, MagicItem* apMagicItem, EffectItem* apEffectItem)
{
    return new FUN_0080c070(apCaster, apMagicItem, apEffectItem, 10);
}

// Allocates and returns a new FUN_0080c070 constructed from the caster, magic item and effect item with a value of 5.
// @fnv 0x0080c3e0
// src: COMMUNITY 0x0080c3e0
FUN_0080c070* __cdecl CurePoision_CurePoision(MagicCaster* apCaster, MagicItem* apMagicItem, EffectItem* apEffectItem)
{
    return new FUN_0080c070(apCaster, apMagicItem, apEffectItem, 5);
}

struct FUN_00803ed0
{
    ~FUN_00803ed0();
};
struct FUN_0080d930 : FUN_00803ed0
{
    ~FUN_0080d930();
};
// @fnv 0x0080d930
FUN_0080d930::~FUN_0080d930()
{}

struct FUN_00622290_cls
{
    void __thiscall SetPackedValue(int a, int b, int c);
};
struct FUN_00810590_Class
{
    char pad[0x84];
    FUN_00622290_cls sub;
    void bhkCharacterControllerCinfo_SetColFilter(int a, int b);
};
// Calls the sub-object's method with the two arguments and a zero third argument.
// @fnv 0x00810590
// src: XBOX_PDB 0x00810590
void FUN_00810590_Class::bhkCharacterControllerCinfo_SetColFilter(int aiArg1, int aiArg2)
{
    sub.SetPackedValue(aiArg1, aiArg2, 0);
}

struct FUN_008192a0 : FUN_0081dbb0
{
    char pad[0x14];
    BSSoundHandle sound;
    unsigned int fC8;
    unsigned int fCC;

    FUN_008192a0();
};

// Initializes fCC and fC8 to zero.
// @fnv 0x008192a0
FUN_008192a0::FUN_008192a0()
{
    fCC = 0;
    fC8 = 0;
}

#include "../../include/ENUM_LOD_MULT.h"


struct ModelLoader
{
    NiNode* __thiscall LoadFile(char const*, ENUM_LOD_MULT, bool, bool, bool, bool);
};

struct Loader_S
{
    ModelLoader* m_pModelLoader;
};

extern Loader_S g_modelLoader;

struct CloningProcess
{
    unsigned int pad[7];
    CloningProcess(float);
    ~CloningProcess();
};

struct Calendar
{
    int GetDaysPassed();
};

struct FUN_0050f5a0_struct
{
    void NiAVObject_DetachParent();
};

extern char DAT_011a9448;
extern NiPoint3 _NiPoint3_ZERO;

// @fnv 0x0081e460
NiAVObject* LoadAndCloneModel(char const* path)
{
    NiAVObject* scale = 0;
    NiNode* loaded = 0;
    float result;

    if (path && path[0])
        loaded = g_modelLoader.m_pModelLoader->LoadFile(path, (ENUM_LOD_MULT)0, true, false, false, false);

    if (loaded)
    {
        result = 1.0f;
        CloningProcess cloningProcess(result);
        scale = loaded->CloneObject(cloningProcess);

        if (scale)
        {
            scale->NiAVObject_SetScale(1.0f);
            scale->SetAppCulled(false);
            scale->SetLocalRotation(reinterpret_cast<NiMatrix3 const&>(DAT_011a9448));
            scale->NiAVObject_SetTranslate(_NiPoint3_ZERO);

            if (reinterpret_cast<Calendar*>(scale)->GetDaysPassed())
                reinterpret_cast<FUN_0050f5a0_struct*>(scale)->NiAVObject_DetachParent();

            scale->UpdateSceneObject();
        }
    }

    return scale;
}

struct FUN_00800170_sub
{
    int unk00;
    void Init(int flag);
};

class FUN_00800170_cls
{
  public:
    int unk00;
    FUN_00800170_sub m_04;
    FUN_00800170_cls* VATSEffectTarget_VATSEffectTarget();
};

// @fnv 0x00800170
// src: COMMUNITY 0x00800170
FUN_00800170_cls* FUN_00800170_cls::VATSEffectTarget_VATSEffectTarget()
{
    m_04.Init(0);
    return this;
}

struct Owned_8001b0
{
    ~Owned_8001b0();
};

struct Slot_8001b0
{
    int unk00;
    NiPointer<AnimIdle> spRetainedObject;
    ~Slot_8001b0();
};

class FUN_008001b0
{
  public:
    int unk00;
    Slot_8001b0 kSlot;
    int unk0C;
    int unk10;
    Slot_8001b0 kSlots[32];
    NiPointer<AnimIdle> sp114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    Owned_8001b0* pOwnedA[16];
    Owned_8001b0* pOwnedB[16];
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int iValuesA[16];
    int iValuesB[16];
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    NiPointer<AnimIdle> sp2C4;
    int unk2C8;
    NiPointer<AnimIdle> sp2CC;
    void Cleanup();
    ~FUN_008001b0();
};

// Clears the slot, zeroes both 16-entry value arrays, deletes and nulls the owned pointers, releases sp2C4, then calls Cleanup.
// @fnv 0x008001b0
FUN_008001b0::~FUN_008001b0()
{
    kSlot.unk00 = 0;
    kSlot.spRetainedObject = 0;
    for (int i = 0; i < 16; i++)
    {
        iValuesA[i] = 0;
        iValuesB[i] = 0;
        if (pOwnedB[i])
        {
            delete pOwnedB[i];
        }
        pOwnedB[i] = 0;
        if (pOwnedA[i])
        {
            delete pOwnedA[i];
        }
        pOwnedA[i] = 0;
    }
    sp2C4 = 0;
    Cleanup();
}

// Stand-in for the settings object that owns the float used as a divisor.
extern GlobalObject_0044f440 b4225_g_011db730;
extern GlobalObject_0044f440 b4225_g_011db7b4;
extern GlobalObject_0044f440 b4225_g_011db750;
extern GlobalObject_0044f440 b4225_g_011db6d8;

// Constant the current value is compared against, and the delta added to the
// second setting before the final comparison.
extern double b4225_kCompareConst;
extern double b4225_kDelta;

struct FUN_00800900_cls
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    unsigned char m_b2B4;
    unsigned char m_b2B5;
    unsigned short m_w2B6;
    float m_f2B8;
    float m_f2BC;
    void Notify(float a, float b, int c);
    void FOVATSEffectManager_UpdateScan(float value);
};

// @fnv 0x00800900
// src: COMMUNITY 0x00800900
void FUN_00800900_cls::FOVATSEffectManager_UpdateScan(float value)
{
    if (this->m_f2B8 == b4225_kCompareConst)
        this->m_f2B8 = value;

    float delta = value - this->m_f2B8;
    this->m_f2BC = delta / *b4225_g_011db730.Float();

    if (this->m_b2B5)
    {
        if (*b4225_g_011db7b4.Float() + b4225_kDelta < this->m_f2BC)
        {
            this->m_b2B4 = 0;
            this->m_b2B5 = 0;
            this->Notify(*b4225_g_011db6d8.Float(), *b4225_g_011db750.Float(), 1);
        }
    }
}

extern float DAT_01012054;

class FUN_00800a00_cls
{
  public:
    bool GetRatioByIndex(unsigned int idx, float* out);
};

// @fnv 0x00800a00
bool FUN_00800a00_cls::GetRatioByIndex(unsigned int uiIndex, float* pfOut)
{
    if (*((unsigned char*)this + uiIndex + 0x1ac) != 0)
    {
        *pfOut = (float)(*(unsigned int*)((char*)this + uiIndex * 4 + 0x1bc) > 0
                             ? (double)*(unsigned int*)((char*)this + uiIndex * 4 + 0x1fc) /
                                   (double)*(unsigned int*)((char*)this + uiIndex * 4 + 0x1bc)
                             : 0.0);
        return true;
    }
    else
    {
        *pfOut = DAT_01012054;
        return false;
    }
}

void __cdecl Warning_005b5e40(const char* value);
void __cdecl BSShaderProperty_SetFlagRecurse(void* value, int a, const void* b);
typedef NiNode*(__thiscall* FUN_00800d50_getter)(NiNode*);
extern char DAT_01078e78;

// Clears a flag, returns if a is already in the list, else appends a and its getter result, sets f04 if empty, and calls FUN_00ba91a0.
// @fnv 0x00800d50
// src: XBOX_PDB 0x00800d50
void FUN_00800e50_Class::FOVATSEffectManager_SetMultiTarget(int pNode)
{
    ((char*)this)[0x2b4] = 0;
    for (int i = 0; i < this->f0c; ++i)
    {
        if (*(int*)((char*)this + i * 8 + 0x14) == pNode)
        {
            return;
        }
    }
    if (this->f0c + 1 >= 0x20)
    {
        Warning_005b5e40(&DAT_01078e78);
        return;
    }
    *(int*)((char*)this + this->f0c * 8 + 0x14) = pNode;
    ((NiPointer<NiNode>*)((char*)this + this->f0c * 8 + 0x18))
        ->operator=(((FUN_00800d50_getter)(*(unsigned int*)(*(unsigned int*)pNode + 0x1d0)))((NiNode*)pNode));
    this->f0c++;
    if (this->f04 == 0)
    {
        this->f04 = pNode;
        ((NiPointer<NiNode>*)((char*)this + 8))
            ->operator=(((FUN_00800d50_getter)(*(unsigned int*)(*(unsigned int*)pNode + 0x1d0)))((NiNode*)pNode));
    }
    BSShaderProperty_SetFlagRecurse((NiNode*)*((NiPointer<NiNode>*)((char*)this + this->f0c * 8 + 0x18)), 0x31, 0);
}

struct FnvBase
{
    virtual ~FnvBase();
};
struct FUN_00802bf0 : FnvBase
{
    virtual ~FUN_00802bf0();
    void __thiscall FUN_00438af0();
};
// Destructor that calls FUN_00438af0 before the object is destroyed.
// @fnv 0x00802bf0
FUN_00802bf0::~FUN_00802bf0()
{
    FUN_00438af0();
}

class B9277Node;

class B9277Holder
{
  public:
    B9277Node* m_node;
};

class B9277Node
{
  public:
    virtual int v00(int a);
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30(void* a);

    B9277Holder* FUN_006815c0();
    B9277Node* FUN_00726070();
    void FUN_00470470();
};

// Walks the node chain from a2, calls v30(a1) on each node's holder node, then calls FUN_00470470 on a2.
// @fnv 0x00806ba0
// src: XBOX_PDB 0x00806ba0
void ActiveEffect_RevertActiveEffectList(void* a1, B9277Node* pNode)
{
    B9277Node* cur = pNode;
    while (cur != 0)
    {
        B9277Node* obj5 = cur->FUN_006815c0()->m_node;
        if (obj5 != 0)
        {
            obj5->v30(a1);
            B9277Node* x4 = obj5;
            B9277Node* t5 = x4;
            int res5;
            if (t5 != 0)
            {
                res5 = t5->v00(1);
            }
            else
            {
                res5 = 0;
            }
        }
        cur = cur->FUN_00726070();
    }
    pNode->FUN_00470470();
}

struct FUN_0080f6e0_sub
{
    char pad[0xc];
    FUN_0080f6e0_sub();
};
struct FUN_0080f6e0 : FUN_0081dbb0
{
    char pad[0xc];
    FUN_0080f6e0_sub m_b4;
    unsigned int m_c0;
    FUN_0080f6e0();
    virtual ~FUN_0080f6e0();
};

// Initializes the object: constructs the m_b4 sub-object and sets m_c0 to 0.
// @fnv 0x0080f6e0
FUN_0080f6e0::FUN_0080f6e0() : m_b4()
{
    m_c0 = 0;
}

struct EffectActor
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual Actor* f11();
};
struct SoundLocal
{
    unsigned int unk0, unk4, unk8;
    bool FUN_00ad8ce0();
    void FUN_00ad88f0();
    void FUN_00ad8d10();
    ~SoundLocal();
};
struct DBase1
{
    virtual void f0();
    unsigned int unk04, unk08, unk0C, unk10, unk14;
};
struct DBase2
{
    virtual void f1();
};
struct DestructorBase : DBase1, DBase2
{
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    ~DestructorBase();
};
struct FUN_0080fb30 : DestructorBase
{
    SoundLocal sound;
    FUN_0080fcc0_class* controller;
    EffectActor* FUN_009185e0();
    ~FUN_0080fb30();
};
extern Actor* g_thePlayer;
extern GlobalObject_0044f440 g_011d1c28;
void _11DC778_Subtract(float);
// @fnv 0x0080fb30
FUN_0080fb30::~FUN_0080fb30()
{
    Actor* actor = FUN_009185e0() ? FUN_009185e0()->f11() : 0;
    if (actor != g_thePlayer)
        _11DC778_Subtract(*g_011d1c28.Float());
    if (sound.FUN_00ad8ce0())
    {
        sound.FUN_00ad88f0();
        if (sound.FUN_00ad8ce0())
            sound.FUN_00ad8d10();
    }
    if (controller)
    {
        FUN_0080fcc0_class* previous = controller;
        FUN_0080fcc0_class* old = previous;
        old ? old->FUN_0080fcc0(1) : 0;
    }
    controller = 0;
}



struct SceneObj
{
    NiPoint3* GetPos();
    void GetTransformScale(const NiPoint3& p);
    void SetLocalRotation(const Mat3& m);
};

struct Emitter
{
    void Fire(float a, float len, float f, bool b);
};

extern Setting g_011d1b14;

float NiATan2(float, float);

struct EffectParams
{
    NiPointer<Emitter> spEmitter;
    NiPointer<SceneObj> m_pController;
    NiPoint3 pos;
    NiPointer<SceneObj> aspObstacleData;
    NiPointer<SceneObj> m_spTargetObject;
};

struct EffectBase
{
    void* vtbl;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84;
    float f88;
    int unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4;
    int unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    int unkC8, unkCC, unkD0;
    float fD4;
    float GetTime();
    void MagicBoltProjectile_UpdateBranch(float a, EffectParams* p);
};

// @fnv 0x00812700
// src: COMMUNITY 0x00812700
void EffectBase::MagicBoltProjectile_UpdateBranch(float a, EffectParams* pParams)
{
    SceneObj* node5 = pParams->m_pController;
    if (pParams->aspObstacleData)
    {
        pParams->pos = *pParams->aspObstacleData->GetPos();
    }
    node5->GetTransformScale(pParams->pos);
    NiPoint3 dir = *pParams->m_spTargetObject->GetPos() - pParams->pos;
    bool bFar = GetTime() - fD4 > *g_011d1b14.Float();
    pParams->spEmitter->Fire(a, dir.Length(), f88, bFar);
    Mat3 rot2;
    float z4 = dir.z;
    dir.z = 0.0f;
    float len = dir.Length();
    rot2.FromAngles(NiATan2(dir.x, dir.y), 0.0f, -NiATan2(z4, len));
    node5->SetLocalRotation(rot2);
}

struct FUN_00813ea0_Sub
{
    int unk00;

    FUN_00813ea0_Sub(int a);
    ~FUN_00813ea0_Sub();
};

struct FUN_00813ea0_Mid
{
    int unk00;
    int unk04;
    int unk08;

    FUN_00813ea0_Mid();
};

struct FUN_00813ea0_Leaf
{
    int unk00;

    FUN_00813ea0_Leaf(int a);
};

struct FUN_00813ea0_cls
{
    FUN_00813ea0_Sub m_00;
    FUN_00813ea0_Sub m_04;
    FUN_00813ea0_Mid m_08;
    FUN_00813ea0_Sub m_14;
    FUN_00813ea0_Leaf m_18;

    FUN_00813ea0_cls();
};

// Initializes the members m_00, m_04, m_08, m_14 and m_18 with zero or default values.
// @fnv 0x00813ea0
FUN_00813ea0_cls::FUN_00813ea0_cls() : m_00(0), m_04(0), m_08(), m_14(0), m_18(0)
{}

class FUN_00815360_cls
{
  public:
    virtual void vSlot00();
    virtual void vSlot01();
    virtual void vSlot02();
    virtual void vSlot03();
    virtual void vSlot04();
    virtual void vSlot05();
    virtual void vSlot06();
    virtual void vSlot07();
    virtual void vSlot08();
    void CallSlot08();
};

// @fnv 0x00815360
void FUN_00815360_cls::CallSlot08()
{
    this->vSlot08();
}

// Virtual target with 117 slots; the called one is at vftable offset 0x1D0.
struct VTableTarget116
{
    virtual void v000() = 0;
    virtual void v001() = 0;
    virtual void v002() = 0;
    virtual void v003() = 0;
    virtual void v004() = 0;
    virtual void v005() = 0;
    virtual void v006() = 0;
    virtual void v007() = 0;
    virtual void v008() = 0;
    virtual void v009() = 0;
    virtual void v010() = 0;
    virtual void v011() = 0;
    virtual void v012() = 0;
    virtual void v013() = 0;
    virtual void v014() = 0;
    virtual void v015() = 0;
    virtual void v016() = 0;
    virtual void v017() = 0;
    virtual void v018() = 0;
    virtual void v019() = 0;
    virtual void v020() = 0;
    virtual void v021() = 0;
    virtual void v022() = 0;
    virtual void v023() = 0;
    virtual void v024() = 0;
    virtual void v025() = 0;
    virtual void v026() = 0;
    virtual void v027() = 0;
    virtual void v028() = 0;
    virtual void v029() = 0;
    virtual void v030() = 0;
    virtual void v031() = 0;
    virtual void v032() = 0;
    virtual void v033() = 0;
    virtual void v034() = 0;
    virtual void v035() = 0;
    virtual void v036() = 0;
    virtual void v037() = 0;
    virtual void v038() = 0;
    virtual void v039() = 0;
    virtual void v040() = 0;
    virtual void v041() = 0;
    virtual void v042() = 0;
    virtual void v043() = 0;
    virtual void v044() = 0;
    virtual void v045() = 0;
    virtual void v046() = 0;
    virtual void v047() = 0;
    virtual void v048() = 0;
    virtual void v049() = 0;
    virtual void v050() = 0;
    virtual void v051() = 0;
    virtual void v052() = 0;
    virtual void v053() = 0;
    virtual void v054() = 0;
    virtual void v055() = 0;
    virtual void v056() = 0;
    virtual void v057() = 0;
    virtual void v058() = 0;
    virtual void v059() = 0;
    virtual void v060() = 0;
    virtual void v061() = 0;
    virtual void v062() = 0;
    virtual void v063() = 0;
    virtual void v064() = 0;
    virtual void v065() = 0;
    virtual void v066() = 0;
    virtual void v067() = 0;
    virtual void v068() = 0;
    virtual void v069() = 0;
    virtual void v070() = 0;
    virtual void v071() = 0;
    virtual void v072() = 0;
    virtual void v073() = 0;
    virtual void v074() = 0;
    virtual void v075() = 0;
    virtual void v076() = 0;
    virtual void v077() = 0;
    virtual void v078() = 0;
    virtual void v079() = 0;
    virtual void v080() = 0;
    virtual void v081() = 0;
    virtual void v082() = 0;
    virtual void v083() = 0;
    virtual void v084() = 0;
    virtual void v085() = 0;
    virtual void v086() = 0;
    virtual void v087() = 0;
    virtual void v088() = 0;
    virtual void v089() = 0;
    virtual void v090() = 0;
    virtual void v091() = 0;
    virtual void v092() = 0;
    virtual void v093() = 0;
    virtual void v094() = 0;
    virtual void v095() = 0;
    virtual void v096() = 0;
    virtual void v097() = 0;
    virtual void v098() = 0;
    virtual void v099() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual int v116() = 0;
};

struct FUN_0081c4a0_cls
{
    void MagicLight_Transfer_0081c4e0(int a);
    void MagicLight_Transfer(VTableTarget116* p);
};

// @fnv 0x0081c4a0
// src: XBOX_PDB 0x0081c4a0
void FUN_0081c4a0_cls::MagicLight_Transfer(VTableTarget116* pTarget)
{
    if (pTarget->v116() != 0)
        this->MagicLight_Transfer_0081c4e0(pTarget->v116());
}

struct FUN_0081c4e0_Helper
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55(void* a, int b);
};

struct FUN_0081c4e0_Sub
{
    int m_00;
    FUN_0081c4e0_Helper* __thiscall GetHelper();
};

struct FUN_0081c4e0_cls
{
    int m_00;
    int m_04;
    FUN_0081c4e0_Sub m_08;
    void __thiscall FUN_0066b0d0(int a);
    FUN_0081c4e0_Helper* __thiscall GetHelper();
    void __thiscall MagicLight_Transfer_0081c4e0(int a1);
};

// If m_04 is nonzero, calls FUN_0066b0d0 with a1 and then invokes v55 on the helper with the sub-helper and 1.
// @fnv 0x0081c4e0
// src: XBOX_PDB 0x0081c4e0
void __thiscall FUN_0081c4e0_cls::MagicLight_Transfer_0081c4e0(int a1)
{
    if (m_04 != 0)
    {
        FUN_0066b0d0(a1);
        GetHelper()->v55(m_08.GetHelper(), 1);
    }
}

NiAVObject* __cdecl LoadAndCloneModel(const char* value);

struct FUN_0081e440_Embedded
{
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}
    virtual NiAVObject* vf14()
    {
        return 0;
    }
};

struct FUN_0081e440_Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_0081e440_Embedded embedded;
};

// @fnv 0x0081e440
// src: XBOX_PDB 0x0081e440
void __cdecl MagicProjectile_Clone3D(FUN_0081e440_Object* object)
{
    LoadAndCloneModel(reinterpret_cast<const char*>(object->embedded.vf14()));
}

struct FUN_0081f1e0_Virtual
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50(int, int);
};

struct FUN_0081f1e0_Class
{
    void __thiscall activate_00c9c1d0();
    FUN_0081f1e0_Virtual* __thiscall CombatGroup_GetLastSearchAreaUpdateTimer();
    void __thiscall ApplyVirtualCall(int, int);
};

// Calls FUN_00c9c1d0 on this, then forwards arg1 and arg2 to vf50 on the object returned by FUN_009d9f40.
// @fnv 0x0081f1e0
void FUN_0081f1e0_Class::ApplyVirtualCall(int arg1, int arg2)
{
    this->activate_00c9c1d0();
    this->CombatGroup_GetLastSearchAreaUpdateTimer()->vf50(arg1, arg2);
}

struct EquipObject;
struct EquipGeometry
{
    void* NiGeometry_GetSkinInstance();
};
struct EquipNode;
struct EquipSlot
{
    const char* SkyObject_GetNiNode();
};
struct EquipBase;
struct EquipTable
{
    EquipSlot* GetValueByIndex(int);
};
struct EquipObject
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual EquipNode* AsNode();
    virtual void V004();
    virtual void V005();
    virtual EquipGeometry* AsGeometry();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual EquipObject* Find(const NiFixedString&);
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual bool IsActor();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual EquipObject* GetRoot();
    EquipBase* FUN_004181e0();
    void FUN_00450f90(int);
};
struct EquipBase
{
    virtual void W000();
    virtual void W001();
    virtual void W002();
    virtual void W003();
    virtual void W004();
    virtual void W005();
    virtual void W006();
    virtual void W007();
    virtual void W008();
    virtual void W009();
    virtual void W010();
    virtual void W011();
    virtual void W012();
    virtual void W013();
    virtual void W014();
    virtual void W015();
    virtual void W016();
    virtual void W017();
    virtual void W018();
    virtual void W019();
    virtual void W020();
    virtual void W021();
    virtual void W022();
    virtual void W023();
    virtual void W024();
    virtual void W025();
    virtual void W026();
    virtual void W027();
    virtual void W028();
    virtual void W029();
    virtual void W030();
    virtual void W031();
    virtual void W032();
    virtual void W033();
    virtual void W034();
    virtual void W035();
    virtual void W036();
    virtual void W037();
    virtual void W038();
    virtual void W039();
    virtual void W040();
    virtual void W041();
    virtual void W042();
    virtual void W043();
    virtual void W044();
    virtual void W045();
    virtual void W046();
    virtual void W047();
    virtual void W048();
    virtual void W049();
    virtual void W050();
    virtual void W051();
    virtual void W052();
    virtual void W053();
    virtual void W054();
    virtual void W055();
    virtual void W056();
    virtual void W057();
    virtual void W058();
    virtual void W059();
    virtual void W060();
    virtual void W061();
    virtual void W062();
    virtual void W063();
    virtual void W064();
    virtual void W065();
    virtual void W066();
    virtual void W067();
    virtual void W068();
    virtual void W069();
    virtual void W070();
    virtual void W071();
    virtual void W072();
    virtual void W073();
    virtual void W074();
    virtual void W075();
    virtual void W076();
    virtual void W077();
    virtual void W078();
    virtual void W079();
    virtual void W080();
    virtual void W081();
    virtual void W082();
    virtual void W083();
    virtual void W084();
    virtual void W085();
    virtual void W086();
    virtual void W087();
    virtual void W088();
    virtual void W089();
    virtual void W090();
    virtual void W091();
    virtual void W092();
    virtual void W093();
    virtual void W094();
    virtual void W095();
    virtual EquipTable* GetEquipment();
};
struct EquipNode
{
    unsigned int FUN_0043b480();
    EquipObject* FUN_0043b4a0(unsigned int);
};
extern char DAT_011f49d8;
bool __cdecl Animation_FindSkinnedNode(EquipObject*);
void* __cdecl NiObject_DynamicCast(const void*, const void*);
struct EquipVisibility
{
    int unk00;
    EquipObject* owner;
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
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int current;
    int extraCount;
    int extraSlots[15];
    void VATSEffect_SetBodyPartEnabled(void*, int, bool);
    void FOVATSEffectManager_ShowBipedObjectOnActor(EquipObject*, int, int);
    void UpdateEquipmentVisibility();
};
// Toggles shader visibility for the owner's equipment slots based on the current slot, hiding non-selected slots and showing extras.
// @fnv 0x00801da0
void EquipVisibility::UpdateEquipmentVisibility()
{
    if (!owner->IsActor())
        return;
    if (current == 14 || current == 15)
        return;
    EquipObject* actor = owner;
    int selected = current;
    EquipNode* root = (EquipNode*)owner->GetRoot();
    for (unsigned int i = 0; i < root->FUN_0043b480(); i++)
    {
        EquipObject* object = root->FUN_0043b4a0(i);
        if (object)
        {
            if (Animation_FindSkinnedNode(object))
            {
                EquipNode* node9 = object->AsNode();
                EquipGeometry* geometry = object->AsGeometry();
                unsigned int child = 0;
                while (geometry || (node9 && child < node9->FUN_0043b480()))
                {
                    if (node9)
                    {
                        geometry = node9->FUN_0043b4a0(child) ? node9->FUN_0043b4a0(child)->AsGeometry() : 0;
                        child++;
                    }
                    void* property = geometry ? geometry->NiGeometry_GetSkinInstance() : 0;
                    void* shader1 = NiObject_DynamicCast(&DAT_011f49d8, property);
                    if (shader1)
                    {
                        for (int slot = 0; slot < 15; slot++)
                        {
                            VATSEffect_SetBodyPartEnabled(shader1, slot, slot == current);
                            for (int extra = 0; extra < extraCount; extra++)
                            {
                                if (slot == extraSlots[extra])
                                    VATSEffect_SetBodyPartEnabled(shader1, slot, 1);
                            }
                        }
                    }
                    geometry = 0;
                }
            }
            else
            {
                object->FUN_00450f90(1);
            }
        }
    }
    if (actor && current == 0)
    {
        for (int slotIndex = 0; slotIndex < 15; slotIndex++)
        {
            EquipTable* table = actor->FUN_004181e0()->GetEquipment();
            EquipSlot* entry3 = table->GetValueByIndex(current);
            if (entry3)
            {
                EquipObject* node9 = actor->GetRoot()->Find(NiFixedString(entry3->SkyObject_GetNiNode()));
                if (node9 && slotIndex == current)
                    node9->FUN_00450f90(0);
                else if (node9)
                    node9->FUN_00450f90(1);
            }
        }
    }
    if (current != 3 && current != 4)
        FOVATSEffectManager_ShowBipedObjectOnActor(actor, 3, 0);
    if (current != 5 && current != 6)
        FOVATSEffectManager_ShowBipedObjectOnActor(actor, 4, 0);
    if (current != 1 && current != 2)
    {
        FOVATSEffectManager_ShowBipedObjectOnActor(actor, 10, 0);
        FOVATSEffectManager_ShowBipedObjectOnActor(actor, 11, 0);
        FOVATSEffectManager_ShowBipedObjectOnActor(actor, 12, 0);
        FOVATSEffectManager_ShowBipedObjectOnActor(actor, 13, 0);
        FOVATSEffectManager_ShowBipedObjectOnActor(actor, 9, 0);
        FOVATSEffectManager_ShowBipedObjectOnActor(actor, 14, 0);
        FOVATSEffectManager_ShowBipedObjectOnActor(actor, 15, 0);
        FOVATSEffectManager_ShowBipedObjectOnActor(actor, 16, 0);
        FOVATSEffectManager_ShowBipedObjectOnActor(actor, 1, 0);
        FOVATSEffectManager_ShowBipedObjectOnActor(actor, 0, 0);
    }
}

struct FloatSetting;
struct IntegerSetting;
extern FloatSetting DAT_011db6e4;
extern IntegerSetting DAT_011db75c;
extern double DAT_01012070;
extern "C" float* __fastcall Setting_Float_00403e20(FloatSetting* setting);
extern "C" int* __fastcall Setting_Int(IntegerSetting* setting);
extern "C" int __cdecl FUN_00ecadb8();

struct FUN_00800870_Class
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned char active, unk285, unk286, unk287;
    float previous, progress, duration, next;
    void __thiscall UpdateProgress(float value);
};

// Sets progress to (value - previous) / duration; if a global threshold is below progress, clears active and sets next to value plus a random remainder.
// @fnv 0x00800870
void __thiscall FUN_00800870_Class::UpdateProgress(float value)
{
    float delta = value - previous;
    progress = delta / duration;
    if (*Setting_Float_00403e20(&DAT_011db6e4) + DAT_01012070 < progress)
    {
        active = 0;
        next = (float)(FUN_00ecadb8() % *Setting_Int(&DAT_011db75c)) + value;
    }
}


struct FUN_0080cd30_Class : ValueModifierEffect
{
    FUN_0080cd30_Class(MagicCaster*, MagicItem*, EffectItem*);
};

// Constructs the ValueModifierEffect base and installs the derived vtable.
// @fnv 0x0080cd30
FUN_0080cd30_Class::FUN_0080cd30_Class(MagicCaster* apCaster, MagicItem* apMagicItem,
                                                   EffectItem* apEffectItem)
    : ValueModifierEffect(apCaster, apMagicItem, apEffectItem)
{
}

// @fnv 0x0080d1a0
FUN_0080d1a0::FUN_0080d1a0(MagicCaster* a, MagicItem* b, EffectItem* c)
    : ActiveEffect(a, b, c)
{
    f48 = 0;
}

// FUN_0080d6b0: constructor-like member that forwards its three arguments to
// the base routine using `this`, installs the class vtable pointer into the
// object and returns itself.

struct FUN_0080d6b0_cls : ActiveEffect
{
    FUN_0080d6b0_cls(MagicCaster*, MagicItem*, EffectItem*);
};

// Constructs the ActiveEffect base and installs the derived vtable.
// @fnv 0x0080d6b0
FUN_0080d6b0_cls::FUN_0080d6b0_cls(MagicCaster* a, MagicItem* b, EffectItem* c)
    : ActiveEffect(a, b, c)
{
}

struct FUN_0080d900_cls : ActiveEffect
{
    FUN_0080d900_cls(MagicCaster*, MagicItem*, EffectItem*);
};

// Constructs the ActiveEffect base and installs the derived vtable.
// @fnv 0x0080d900
FUN_0080d900_cls::FUN_0080d900_cls(MagicCaster* a1, MagicItem* a2, EffectItem* a3)
    : ActiveEffect(a1, a2, a3)
{
}

struct FUN_0080f390_shell : ActiveEffect
{
    FUN_0080f390_shell(MagicCaster* a, MagicItem* b, EffectItem* c);
};
// Constructs a FUN_0080f390_shell ActiveEffect, passing a, b, c to the base and setting the vtable to DAT_0107a4ac.
// @fnv 0x0080f390
FUN_0080f390_shell::FUN_0080f390_shell(MagicCaster* apCaster, MagicItem* apItem, EffectItem* apEffect)
    : ActiveEffect(apCaster, apItem, apEffect)
{
}

namespace fnv_0081de70 {
class FUN_0081de70_cls;

struct Obj68
{
    int Get();
};

struct GlobalGate
{
    void Enter(FUN_0081de70_cls* self, int r);
};

struct GlobalMgr
{
    bool Query();
};

struct Logger
{
    void Log(int v);
};

extern GlobalGate g_gate;
extern Logger* g_logger;
extern GlobalMgr* g_mgr;

class SecondaryBase
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(int a, int b);
    unsigned int Check();
};

class PrimaryBase
{
  public:
    virtual ~PrimaryBase();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

class FUN_0081de70_cls : public PrimaryBase, public SecondaryBase
{
  public:
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
    Obj68* m_68;
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
    char* m_a0;

    void Flush(int x);
    virtual ~FUN_0081de70_cls();
};

// If m_68 is set calls g_gate.Enter(this, m_68->Get()); logs v5(0, 1) of m_a0+0x18 if its Check() > 0; calls Flush(0) when g_mgr->Query() is false.
// @fnv 0x0081de70
FUN_0081de70_cls::~FUN_0081de70_cls()
{
    if (m_68 != 0)
    {
        g_gate.Enter(this, m_68->Get());
    }
    if (m_a0 != 0)
    {
        if (((SecondaryBase*)(m_a0 + 0x18))->Check() > 0)
        {
            g_logger->Log(((SecondaryBase*)(m_a0 + 0x18))->v5(0, 1));
        }
    }
    if (!g_mgr->Query())
    {
        Flush(0);
    }
}
}  // namespace fnv_0081de70

struct WeaponEffectDeletion : public FUN_0080d930
{
    void* __thiscall FUN_0080d6e0(unsigned int flags);
};
// Destroys the WeaponEffectDeletion object and frees its memory if the flags argument has bit 0 set.
// @fnv 0x0080d6e0
void* WeaponEffectDeletion::FUN_0080d6e0(unsigned int flags)
{
    FUN_0080d930::~FUN_0080d930();
    if (flags & 1)
        operator delete(this);
    return this;
}
