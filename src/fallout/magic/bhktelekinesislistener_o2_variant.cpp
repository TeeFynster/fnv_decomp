// src/fallout/magic/bhktelekinesislistener_o2_variant.cpp - optimized listener thunks.

#include "../../../include/bhkTelekinesisListener.h"

// These secondary-vtable entries forward to the complete object's deleting destructor.
// Keep the original SUB encoding: C++ pointer subtraction optimizes to ADD instead.
// @fnv 0x00807df0
__declspec(naked) void* __fastcall DestroyTelekinesisEntityListener(hkpEntityListener*, void*, unsigned int)
{
    __asm {
        sub ecx, 4
        jmp bhkTelekinesisListener::Destroy
    }
}

// @fnv 0x00807e00
__declspec(naked) void* __fastcall DestroyTelekinesisActivationListener(hkpEntityActivationListener*, void*, unsigned int)
{
    __asm {
        sub ecx, 8
        jmp bhkTelekinesisListener::Destroy
    }
}
