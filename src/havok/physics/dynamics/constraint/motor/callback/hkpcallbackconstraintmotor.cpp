
// src/havok/physics/dynamics/constraint/motor/callback/hkpcallbackconstraintmotor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/motor/callback/hkpcallbackconstraintmotor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpCallbackConstraintMotor.h"

struct FUN_00e483d0_Class;

struct FUN_00e483d0_Allocator
{
    virtual void unused() = 0;
    virtual void* allocate(unsigned int size) = 0;
};

struct FUN_00e483d0_Router
{
    unsigned char padding[0x10];
    FUN_00e483d0_Allocator* allocator;
};

struct FUN_00e483d0_Object
{
    virtual void unused() = 0;
    unsigned short type;

    void FUN_00e48400(FUN_00e483d0_Class* source);
};

struct FUN_00e483d0_Class
{
    void hkpCallbackConstraintMotor_clone();
};

FUN_00e483d0_Router* __cdecl _D1A0E0GetMemoryRouter();

// Allocates a 0x28-byte object via the memory router's allocator, sets its type to 0x28, and passes this to its FUN_00e48400 method.
// @fnv 0x00e483d0
// src: HAVOK_LIB 0x00e483d0
void FUN_00e483d0_Class::hkpCallbackConstraintMotor_clone()
{
    FUN_00e483d0_Router* router = _D1A0E0GetMemoryRouter();
    FUN_00e483d0_Object* object = static_cast<FUN_00e483d0_Object*>(router->allocator->allocate(0x28));

    object->type = 0x28;
    object->FUN_00e48400(this);
}
