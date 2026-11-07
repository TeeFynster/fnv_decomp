
// src/havok/common/base/types/geometry/localframe/hklocalframeclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/geometry/localframe/hklocalframeclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/BSAudio.h"

struct FUN_00df67d0_Base
{
    virtual void v0();
    void FUN_00df67d0();
};
struct FUN_00da0860_manager
{
    virtual void v0();
    virtual void v1();
    virtual void FUN_00da0860_release(void*, unsigned short);
};
BSAudio* hkMemoryRouter_getInstance();
struct FUN_00da0860_class : FUN_00df67d0_Base
{
    unsigned short unk04;
    FUN_00da0860_class* FUN_00da0860(unsigned int flags);
};
// @fnv 0x00da0860
FUN_00da0860_class* FUN_00da0860_class::FUN_00da0860(unsigned int flags)
{
    FUN_00df67d0_Base::FUN_00df67d0();
    if (flags & 1)
    {
        BSAudio* audio = hkMemoryRouter_getInstance();
        ((FUN_00da0860_manager*)audio->pListener)->FUN_00da0860_release(this, unk04);
    }
    return this;
}

struct DA0890Object
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
    unsigned int m_taggedPointer;

    void* GetUntaggedPointer() const;
};

// Returns m_taggedPointer with its low bit cleared, as a void pointer.
// @fnv 0x00da0890
void* DA0890Object::GetUntaggedPointer() const
{
    return (void*)(m_taggedPointer & ~1u);
}

extern int DAT_0102e388;

struct FUN_00cb0c00_class
{
    void Object_UpdateFields_00cb0c00();
};


struct SomeClass
{
    void* vptr;
    unsigned short unk04;
    void* FUN_00da0800(unsigned int flags);
};

// Calls a virtual method on the object at offset 8, sets the vtable, and if flags bit 0 is set releases this via the audio manager using unk04.
// @fnv 0x00da0800
void* SomeClass::FUN_00da0800(unsigned int flags)
{
    ((FUN_00cb0c00_class*)((char*)this + 8))->Object_UpdateFields_00cb0c00();
    this->vptr = (void*)&DAT_0102e388;
    if (flags & 1)
    {
        BSAudio* a = hkMemoryRouter_getInstance();
        unsigned short d = this->unk04;
        ((FUN_00da0860_manager*)a->pListener)->FUN_00da0860_release(this, d);
    }
    return this;
}

struct DA0850Object
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
    int m_uiFilterValue;

    void hkSimpleLocalFrame_setParentFrame(int value);
};

// @fnv 0x00da0850
// src: HAVOK_LIB 0x00da0850
void DA0850Object::hkSimpleLocalFrame_setParentFrame(int value)
{
    m_uiFilterValue = value;
}

struct FUN_00da0840_Obj
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

    int GetUnk5C_00da0840();
};

// @fnv 0x00da0840
// src: GUESS 0x00da0840 (confidence: low)
int FUN_00da0840_Obj::GetUnk5C_00da0840()
{
    return unk5C;
}
