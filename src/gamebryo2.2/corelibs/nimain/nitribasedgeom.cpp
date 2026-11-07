// gamebryo2.2/corelibs/nimain/nitribasedgeom.cpp: BSTextureSet, NiGeometry, NiTriBasedGeom (5 functions)
#include "nitribasedgeom_decls.h"
// NiPointer's default constructor is inline in Gamebryo (it only nulls the pointer).
template <class T> __forceinline NiPointer<T>::NiPointer() : m_pObject(0) {}
#pragma optimize("", off)
// @fnv 0x0051d190
BSTextureSet::BSTextureSet()
{
}
#pragma optimize("", on)
// Initializes the NiGeometry object by setting model, skin and shader pointers to null.
// @fnv 0x00a80540
NiGeometry::NiGeometry()
{
    m_spShader = 0;
}

#pragma optimize("", off)
// @fnv 0x0051d020
void FUN_0051d020_FlagsAtAC::SetBitfield(unsigned short value, unsigned short mask, unsigned short shift)
{
    flags = (flags & ~mask) | (value << shift);
}

struct DummyClass
{
    void __thiscall FUN_0051d080_mem(unsigned char a1, int a2);
};

struct StackByte
{
    unsigned char v;
};

// @fnv 0x0051d060
// src: COMMUNITY 0x0051d060
void __fastcall NiBillboardNode_SetUpdateControllers(DummyClass* _this, StackByte aByteValue)
{
    _this->FUN_0051d080_mem(aByteValue.v, 8);
}

#include "../../../../include/NiMemObject.h"

void __fastcall FUN_0051d1c0(void* pThis);

struct Dummy_0051d160
{
    // Calls FUN_0051d1c0 on this, then frees this (0x38 bytes) via NiMemObject::operator delete when bit 0 of flags is set, returning this.
// @fnv 0x0051d160
    void* __thiscall FUN_0051d160(unsigned int flags)
    {
        FUN_0051d1c0(this);
        if ((flags & 1) != 0)
        {
            NiMemObject::operator delete(this, 0x38);
        }
        return this;
    }
};

static void* (__thiscall Dummy_0051d160::*p_0051d160)(unsigned int) = &Dummy_0051d160::FUN_0051d160;
