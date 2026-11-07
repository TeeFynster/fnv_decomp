// src/havok/physics/utilities/serialize/display/hkpserializeddisplayrbtransformsclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/display/hkpserializeddisplayrbtransformsclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/BSAudio.h"

struct Allocator
{
    virtual void unknown00() = 0;
    virtual void unknown04() = 0;
    virtual void Release(void* object, unsigned int bytes) = 0;
};
BSAudio* hkMemoryRouter_getInstance();
struct Owner
{
    unsigned int unk00;
    unsigned short size4, unk06;
    void FUN_00e3a3d0();
    Owner* FUN_00dfc490(unsigned int flags);
};
// Calls FUN_00e3a3d0, and if flags has bit 0 set, releases this object through the BSAudio allocator using size4 bytes, then returns this.
// @fnv 0x00dfc490
Owner* Owner::FUN_00dfc490(unsigned int flags)
{
    FUN_00e3a3d0();
    if (flags & 1u)
    {
        BSAudio* audio = hkMemoryRouter_getInstance();
        unsigned int bytes = size4;
        reinterpret_cast<Allocator*>(audio->pListener)->Release(this, bytes);
    }
    return this;
}
