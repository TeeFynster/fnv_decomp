// imagespaceshaderblur_h_unit.cpp: Derived, FNVObjectToDispose (12 functions)

#include "imagespaceshaderblur.h"

extern int DAT_010b1640;
extern int DAT_010b1620;
void __cdecl FUN_00c03a20();
void __cdecl _delete(void* p, int size);

struct FUN_00b8e420_shell
{
    int m_vft;
    int m_06c;
    FUN_00b8e420_shell* FUN_00b8e420(int);
};

// Sets two vtable pointers, calls FUN_00c03a20, and if f has bit 1 set, deletes this with size 0xd0.
// @fnv 0x00b8e420
FUN_00b8e420_shell* FUN_00b8e420_shell::FUN_00b8e420(int aiFlags)
{
    m_vft = (int)&DAT_010b1640;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010b1620;
    FUN_00c03a20();
    if (aiFlags & 1)
        _delete(this, 0xd0);
    return this;
}

extern int DAT_010b17f8;
extern int DAT_010b17d8;
extern void __cdecl FUN_00aa1460(void* object, unsigned int size);

struct FUN_00b8e5c0_class
{
    void FUN_00c03a20();
    void* FUN_00b8e5c0(unsigned int flags);
};

// @fnv 0x00b8e5c0
void* FUN_00b8e5c0_class::FUN_00b8e5c0(unsigned int flags)
{
    *reinterpret_cast<int**>(this) = &DAT_010b17f8;
    *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x6c) = &DAT_010b17d8;
    FUN_00c03a20();
    if (flags & 1)
    {
        FUN_00aa1460(this, 0xd0);
    }
    return this;
}

extern char DAT_010b1c90;
extern char DAT_010b1c70;
void __cdecl FUN_00c03a20();
void __cdecl FUN_00aa1460(void* object, unsigned int size);

struct FNVObjectToDispose
{
    void* m_primaryVtable;
    unsigned int m_unknown04;
    unsigned int m_unknown08;
    unsigned int m_unknown0c;
    unsigned int m_unknown10;
    unsigned int m_unknown14;
    unsigned int m_unknown18;
    unsigned int m_unknown1c;
    unsigned int m_unknown20;
    unsigned int m_unknown24;
    unsigned int m_unknown28;
    unsigned int m_unknown2c;
    unsigned int m_unknown30;
    unsigned int m_unknown34;
    unsigned int m_unknown38;
    unsigned int m_unknown3c;
    unsigned int m_unknown40;
    unsigned int m_unknown44;
    unsigned int m_unknown48;
    unsigned int m_unknown4c;
    unsigned int m_unknown50;
    unsigned int m_unknown54;
    unsigned int m_unknown58;
    unsigned int m_unknown5c;
    unsigned int m_unknown60;
    unsigned int m_unknown64;
    unsigned int m_unknown68;
    void* m_secondaryVtable;
    FNVObjectToDispose* FUN_00b8eaa0(unsigned char flags);
};

// @fnv 0x00b8eaa0
FNVObjectToDispose* FNVObjectToDispose::FUN_00b8eaa0(unsigned char flags)
{
    m_primaryVtable = &DAT_010b1c90;
    m_secondaryVtable = &DAT_010b1c70;
    FUN_00c03a20();
    if (flags & 1)
        FUN_00aa1460(this, 208);
    return this;
}

extern int DAT_010b1e20;
extern int DAT_010b1dfc;
extern void __cdecl FUN_00c03a20();
extern void __cdecl FUN_00aa1460(void* object, unsigned int size);

struct FUN_00b8ec40_cls
{
    void* m_primaryVtable;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1c;
    unsigned int m_unk20;
    unsigned int m_unk24;
    unsigned int m_unk28;
    unsigned int m_unk2c;
    unsigned int m_unk30;
    unsigned int m_unk34;
    unsigned int m_unk38;
    unsigned int m_unk3c;
    unsigned int m_unk40;
    unsigned int m_unk44;
    unsigned int m_unk48;
    unsigned int m_unk4c;
    unsigned int m_unk50;
    unsigned int m_unk54;
    unsigned int m_unk58;
    unsigned int m_unk5c;
    unsigned int m_unk60;
    unsigned int m_unk64;
    unsigned int m_unk68;
    void* m_secondaryVtable;

    FUN_00b8ec40_cls* FUN_00b8ec40(unsigned int flags);
};

// @fnv 0x00b8ec40
FUN_00b8ec40_cls* FUN_00b8ec40_cls::FUN_00b8ec40(unsigned int flags)
{
    m_primaryVtable = (void*)&DAT_010b1e20;
    m_secondaryVtable = (void*)&DAT_010b1dfc;
    FUN_00c03a20();
    if (flags & 1)
    {
        FUN_00aa1460(this, 0xd0);
    }
    return this;
}


struct S_00b8e450_B2
{
    virtual void FUN_00b8e450();
};

struct S_00b8e450 : BSShader, S_00b8e450_B2
{
    S_00b8e450();
// @fnv 0x00b8e450
    virtual void FUN_00b8e450();
};

S_00b8e450::S_00b8e450()
{}


struct ThunkBaseSecondary
{
    virtual void* FUN_00b8e5f0(unsigned int flags);
};

struct FUN_00b8e5c0_host : BSShader, ThunkBaseSecondary
{
// @fnv 0x00b8e5f0
    void* FUN_00b8e5f0(unsigned int flags);
};

static FUN_00b8e5c0_host s_thunkInst;

extern int DAT_010b1960;

struct BlurShaderBase : BSShader
{
    int* effectVft;
    bool bIsActive;
    bool bParamsChanged;
    unsigned short unk72;
    NiTPrimitiveArray<ImageSpaceEffect*> pEffectList;
    NiTPrimitiveArray<ImageSpaceEffectParam*> pEffectParamList;
    NiTPrimitiveArray<ImageSpaceTexture*> pTextures;
    NiTPrimitiveArray<ImageSpaceEffect::ImageSpaceEffectInput*> pEffectInputs;
    NiTPrimitiveArray<int> pEffectOutput;
    int unkC4;
    int unkC8;
    int unkCC;
    virtual ~BlurShaderBase();
};

struct FUN_00b8e760 : BlurShaderBase
{
    virtual ~FUN_00b8e760();
    static void operator delete(void* object, unsigned int size);
};

// Destructor that sets effectVft to the address of DAT_010b1960.
// @fnv 0x00b8e760
FUN_00b8e760::~FUN_00b8e760()
{
    effectVft = &DAT_010b1960;
}

// FUN_00b8e790 : MSVC this-adjusting thunk  (sub ecx, 0x6c ; jmp <impl>)
struct A2_00b8e790
{
    A2_00b8e790();
    virtual void FUN_00b8e790();
};
struct Own_00b8e790 : BSShader, A2_00b8e790
{
    Own_00b8e790();
    virtual void key_fn();
// @fnv 0x00b8e790
    void FUN_00b8e790();
};
Own_00b8e790::Own_00b8e790()
{}
void Own_00b8e790::key_fn()
{}
Own_00b8e790* make_00b8e790()
{
    static Own_00b8e790 o;
    return &o;
}

extern int DAT_010b1ae8;

struct FUN_00b8e900 : BlurShaderBase
{
    virtual ~FUN_00b8e900();
    static void operator delete(void* object, unsigned int size);
};

// Destructor that sets effectVft to the address of DAT_010b1ae8.
// @fnv 0x00b8e900
FUN_00b8e900::~FUN_00b8e900()
{
    effectVft = &DAT_010b1ae8;
}

// Adjustor thunk for FUN_00b8e930: "sub ecx, 0x6c; jmp FUN_00b8e900".
// Derived overrides a virtual inherited from a secondary base; the thunk moves this back by the BSShader primary base size (0x6c).

struct SecondaryBase
{
    virtual void FUN_00b8e930();
};

struct Derived : BSShader, SecondaryBase
{
    Derived();
// @fnv 0x00b8e930
    virtual void FUN_00b8e930();
};

Derived::Derived()
{}

namespace fnv_00b8ead0 {
// This-call adjustor thunk (MSVC "this adjusting thunk"):
//     sub ecx, 0x6c
//     jmp  <implementation of the secondary base virtual>
//
// The derived shader class inherits the virtual from a secondary base, so the
// thunk moves `this` back to the primary base sub-object before tail jumping
// to the final overrider.  0x6c is the size of the primary base: the vtable
// pointer and inherited BSShader storage (0x6c).

struct SecondaryBase
{
    virtual void FUN_00b8ead0();
};

struct Derived : BSShader, SecondaryBase
{
    Derived();
// @fnv 0x00b8ead0
    virtual void FUN_00b8ead0();
};

Derived::Derived()
{}
}  // namespace fnv_00b8ead0

namespace fnv_00b8ec70 {
// Adjustor thunk for FUN_00b8ec70: "sub ecx, 0x6c; jmp FUN_00b8ec40".
//
// MSVC "this adjusting thunk": the derived class inherits a virtual function
// from a secondary base, so the thunk converts the secondary base sub-object
// pointer back to the derived object pointer (sub ecx, 0x6c) and tail jumps
// to the final overrider.  The subtracted offset is the size of the primary
// BSShader base (0x6c).

struct SecondaryBase
{
    virtual void FUN_00b8ec70();
};

struct Derived : BSShader, SecondaryBase
{
    Derived();
// @fnv 0x00b8ec70
    virtual void FUN_00b8ec70();
};

Derived::Derived()
{}
}  // namespace fnv_00b8ec70
