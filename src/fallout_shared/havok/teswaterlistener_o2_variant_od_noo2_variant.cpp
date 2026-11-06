#include "../../../include/ExtraDataList.h"
#include "../../../include/BSOcclusionPlane.h"
#include "../../../include/BSThread.h"
#include "../../../include/TESDataHandler.h"

// src/fallout_shared/havok/teswaterlistener_o2_variant_od_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /GS /EHsc /Gy /Od (unit src/fallout_shared/havok/teswaterlistener_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/havok/teswaterlistener_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/havok/teswaterlistener.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout_shared/havok/teswaterlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/teswaterlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_0062e750_shell
{
    void* __thiscall FUN_0062e750(unsigned int flags);
    void __thiscall FUN_0062e860();
};
void __cdecl _Deallocate(void* p);
extern int DAT_011c7a3c;
void FUN_0062f310(int value);
extern unsigned char DAT_011c7a5a;
void FUN_0062f8e0(unsigned char value);
extern float _DAT_011c7a5c;
void FUN_0062f8f0(float value);
unsigned int __cdecl GetOcclusionPlaneThreadID(BSOcclusionPlane* pPlane);
extern "C" float __cdecl ExpFloat(float);
float FUN_00630aa0(float value);
extern "C" double __cdecl _exp(double);
float ExpFloat(float value);
extern float _gModifierZero;
float __cdecl SignOfFloat(float a);
struct FUN_005631e0_shell
{
    int __thiscall MaskWithField(int a);
    bool __thiscall IsNonZero(int a);
};
float __cdecl FUN_004a3e90(float);
struct FUN_0062e710_shell
{
    void __thiscall SetValueAt(float f, int a, int b);
};
struct FUN_006310c0_shell
{
    void __thiscall FUN_006310c0();
};
struct FUN_00c9a460_shell
{
    void __thiscall AddObject(int a);
    void __thiscall FUN_00c9a600(int a);
};

#include <xmmintrin.h>
struct PhysicsVector
{
    __m128 m_vComponents;
    void FUN_006815c0();
    void FUN_004a3c90(const PhysicsVector*);
    void FUN_005dbf20(float);
    void FUN_005532a0(float, float, float, float);
    float& FUN_00560d30(int);
    PhysicsVector* FUN_00458700(PhysicsVector*, int);
    float FUN_004586d0();
    void FUN_00630ae0(const PhysicsVector*, const PhysicsVector*);
    void FUN_00458a10(const PhysicsVector*, const PhysicsVector*);
    void FUN_00630bb0(const PhysicsVector*, const PhysicsVector*);
    void FUN_00553f70(const PhysicsVector*);
    void FUN_004a3f10(const PhysicsVector*);
    PhysicsVector* FUN_00630b40(PhysicsVector*);
    void FUN_00627920(const PhysicsVector*);
    void FUN_006240d0();
};
struct PhysicsBounds
{
    PhysicsVector minimum, maximum;
    void FUN_00437c10();
};
struct FUN_005dbf20 : PhysicsVector
{
    FUN_005dbf20(float);
};
struct PhysicsBody
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void GetRotation(PhysicsVector*);
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void GetBounds(PhysicsBounds*);
    bool IsNonZero(int);
    void SetFlag(int, bool);
    void GetAabb(PhysicsBounds*);
};
struct PhysicsReference
{
    const PhysicsVector* FUN_004b4ec0();
    int FUN_00517670();
    PhysicsReference* FUN_0044ddc0();
    void FUN_00483710();
    const PhysicsVector* FUN_00460140();
    const PhysicsVector* FUN_00560dc0();
    float FUN_004b4ea0();
    int FUN_00c9c380();
    const PhysicsVector* FUN_006310c0();
    void FUN_00631140(float, const PhysicsVector*, const PhysicsVector*);
    void FUN_00631100(float, const PhysicsVector*);
    void OnTrigger(const PhysicsVector*);
    const PhysicsVector* FUN_00560e50();
    void FUN_00561800(const PhysicsVector*);
};
PhysicsBody* FUN_004b5a80(PhysicsReference*);
bool FUN_00c8cce0(int*);
float GetObjectMass(PhysicsBody*);
float FUN_00408840(float);
float FUN_004587d0(float);
extern float DAT_0119af4c, DAT_0119af48, DAT_0119af44;
extern float DAT_0119af40, DAT_011cc5e4, DAT_011cc5e0, DAT_0119af3c, DAT_0119af38;
struct RuntimeFloatSetting
{
    float* FUN_00403e20();
};
extern RuntimeFloatSetting DAT_011d0478, DAT_011d0cf0, DAT_011d0ee8, DAT_011d0580;
struct ReferenceMap
{
    void FUN_0084d310(PhysicsReference*, bool);
};
extern ReferenceMap DAT_011cc584;
struct PhysicsController
{
    int FUN_00630170(PhysicsReference*, float, float, bool);
    void SpawnWaterSplash(PhysicsBody*, float);
};
// @fnv 0x00630170
int PhysicsController::FUN_00630170(PhysicsReference* reference, float height, float deltaTime, bool alternate)
{
    int result = 0;
    PhysicsVector position;
    position.FUN_004a3c90(reference->FUN_004b4ec0());
    PhysicsBody* body = FUN_004b5a80(reference);
    PhysicsBounds bounds;
    bounds.FUN_00437c10();
    body->GetBounds(&bounds);
    if (bounds.minimum.FUN_00560d30(2) <= height)
    {
        int handle = reference->FUN_00517670();
        if (FUN_00c8cce0(&handle))
        {
            PhysicsReference* state = reference->FUN_0044ddc0();
            if (state)
            {
                state->FUN_00483710();
                PhysicsVector direction;
                direction.FUN_004a3c90(state->FUN_00460140());
                PhysicsVector velocity;
                velocity.FUN_004a3c90(reference->FUN_00560dc0());
                float mass = reference->FUN_004b4ea0();
                float extent = bounds.maximum.FUN_00560d30(2) - bounds.minimum.FUN_00560d30(2);
                float lower = extent * 0.25 + bounds.minimum.FUN_00560d30(2);
                float upper = extent * 0.8500000238418579 + bounds.minimum.FUN_00560d30(2);
                float amount = (height - lower) / (upper - lower);
                if (amount <= 0.0)
                {
                    state->FUN_00483710();
                    return result;
                }
                float strength = GetObjectMass(body);
                bool dampVertical = true;
                if (amount < DAT_0119af4c && strength > 0.0)
                {
                    if (amount > DAT_0119af48)
                        strength = DAT_0119af44;
                    else if (amount > DAT_0119af40)
                        strength = DAT_011cc5e4;
                    else if (amount > DAT_011cc5e0)
                        strength = DAT_0119af3c;
                    PhysicsVector component;
                    if (DAT_0119af38 > FUN_00408840(velocity.FUN_00458700(&component, 2)->FUN_004586d0()))
                        dampVertical = false;
                }
                strength = -strength;
                PhysicsVector force;
                force.FUN_006815c0();
                FUN_005dbf20 multiplier(strength * mass);
                force.FUN_00630ae0(&multiplier, &direction);
                PhysicsVector torque;
                torque.FUN_006815c0();
                if (!reference->FUN_00c9c380())
                {
                    PhysicsBounds inertiaBounds;
                    inertiaBounds.FUN_00437c10();
                    body->GetAabb(&inertiaBounds);
                    PhysicsVector localTorque;
                    localTorque.FUN_005532a0(0, 0, 0, 0);
                    PhysicsVector sizes;
                    sizes.FUN_006815c0();
                    sizes.FUN_00458a10(&inertiaBounds.maximum, &inertiaBounds.minimum);
                    int smallest = sizes.FUN_00560d30(0) < sizes.FUN_00560d30(1)
                                       ? (sizes.FUN_00560d30(1) < sizes.FUN_00560d30(2) ? 2 : 1)
                                       : (sizes.FUN_00560d30(0) < sizes.FUN_00560d30(2) ? 2 : 0);
                    int largest = sizes.FUN_00560d30(0) > sizes.FUN_00560d30(1)
                                      ? (sizes.FUN_00560d30(1) > sizes.FUN_00560d30(2) ? 2 : 1)
                                      : (sizes.FUN_00560d30(0) > sizes.FUN_00560d30(2) ? 2 : 0);
                    if (sizes.FUN_00560d30(smallest) > sizes.FUN_00560d30(largest) * 1.5f)
                    {
                        localTorque.FUN_00560d30(largest) =
                            sizes.FUN_00560d30(smallest) / sizes.FUN_00560d30(largest) * 0.1f * SignOfFloat(strength);
                        PhysicsVector rotation;
                        rotation.FUN_006240d0();
                        body->GetRotation(&rotation);
                        torque.FUN_00630bb0(&rotation, &localTorque);
                        torque.FUN_00553f70(reference->FUN_006310c0());
                    }
                    else
                        torque.FUN_004a3f10(reference->FUN_006310c0());
                }
                else
                    torque.FUN_004a3f10(reference->FUN_006310c0());
                state->FUN_00483710();
                reference->FUN_00631140(deltaTime, &force, &torque);
                PhysicsVector secondForce;
                secondForce.FUN_006815c0();
                FUN_005dbf20 secondMultiplier(mass * -1.0);
                secondForce.FUN_00630ae0(&secondMultiplier, &direction);
                reference->FUN_00631100(deltaTime, &secondForce);
                state->FUN_00483710();
                PhysicsVector linear;
                linear.FUN_004a3c90(reference->FUN_00560dc0());
                float vertical = linear.FUN_00560d30(2);
                linear.FUN_00560d30(2) = 0;
                if (dampVertical)
                {
                    vertical *= FUN_00630aa0(*DAT_011d0478.FUN_00403e20() * -1.0 * deltaTime);
                }
                PhysicsVector magnitude;
                if (linear.FUN_00630b40(&magnitude)->FUN_004586d0() > *DAT_011d0cf0.FUN_00403e20())
                {
                    FUN_005dbf20 factor(FUN_00630aa0(*DAT_011d0ee8.FUN_00403e20() * -1.0 * deltaTime));
                    linear.FUN_00627920(&factor);
                }
                linear.FUN_00560d30(2) = vertical;
                reference->OnTrigger(&linear);
                PhysicsVector angular;
                angular.FUN_004a3c90(reference->FUN_00560e50());
                FUN_005dbf20 factor(FUN_00630aa0(*DAT_011d0580.FUN_00403e20() * -1.0 * deltaTime));
                angular.FUN_00627920(&factor);
                reference->FUN_00561800(&angular);
                state->FUN_00483710();
            }
        }
        int flag = alternate ? 128 : 8;
        if (!body->IsNonZero(flag))
        {
            body->SetFlag(flag, true);
            SpawnWaterSplash(body, FUN_004587d0(height));
            result = 1;
        }
        DAT_011cc584.FUN_0084d310(reference, true);
    }
    else
    {
        int flag = alternate ? 128 : 8;
        if (body->IsNonZero(flag))
        {
            SpawnWaterSplash(body, FUN_004587d0(height));
            result = 2;
        }
        body->SetFlag(flag, false);
    }
    return result;
}
