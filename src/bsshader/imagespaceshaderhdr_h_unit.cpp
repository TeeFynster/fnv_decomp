// bsshader/imagespaceshaderhdr_h_unit.cpp: Derived, StandIn, Candidate, Target and more (26 functions)

#include "imagespaceshaderhdr.h"

extern int DAT_010b3574;
extern int DAT_010b3598;
struct H00b90150
{
    void FUN_00c03a20();
};
void __cdecl _delete(void*, unsigned int);
struct S00b90150
{
    void* FUN_00b90150(unsigned int);
};
// @fnv 0x00b90150
void* S00b90150::FUN_00b90150(unsigned int auiFlags)
{
    *(void**)this = (void*)&DAT_010b3598;
    *(void**)((char*)this + 0x6c) = (void*)&DAT_010b3574;
    ((H00b90150*)this)->FUN_00c03a20();
    if (auiFlags & 1)
        _delete(this, 0xd0);
    return this;
}

extern int vftable_ImageSpaceShaderHDRBlendInShaderCinematicAlphamask;
extern int DAT_010B3934;
struct Helper00c03a20
{
    void FUN_00c03a20();
};
void __cdecl _delete(void*, unsigned int);
struct StandIn00b904e0
{
    void* DestroyImageSpaceShader(unsigned int);
};
// @fnv 0x00b904e0
void* StandIn00b904e0::DestroyImageSpaceShader(unsigned int auiFlags)
{
    *(void**)this = (void*)&vftable_ImageSpaceShaderHDRBlendInShaderCinematicAlphamask;
    *(void**)((char*)this + 0x6c) = (void*)&DAT_010B3934;
    ((Helper00c03a20*)this)->FUN_00c03a20();
    if (auiFlags & 1)
        _delete(this, 0xd0);
    return this;
}

extern int vftable_ImageSpaceShaderHDRBrightPassFilter;
extern int DAT_010b3c58;
void __cdecl _delete(void*, unsigned int);
struct Caller
{
    void FUN_00c03a20();
};
struct StandIn
{
    void* FUN_00b907f0(unsigned int);
};
// @fnv 0x00b907f0
void* StandIn::FUN_00b907f0(unsigned int auiFlags)
{
    *(void**)this = (void*)&DAT_010b3c58;
    *(void**)((char*)this + 0x6c) = (void*)&vftable_ImageSpaceShaderHDRBrightPassFilter;
    ((Caller*)this)->FUN_00c03a20();
    if (auiFlags & 1)
        _delete(this, 0xd0);
    return this;
}

extern int vftable_ImageSpaceShaderHDRLightAdapt;
extern int DAT_010B42A4;
void _delete(void*, unsigned int);
struct C00c03a20
{
    void FUN_00c03a20();
};
struct S00b90e30
{
    void* DestroyImageSpaceShaderHDRLightAdapt(unsigned int);
};
// Sets the vtable and a field, calls FUN_00c03a20, and if flags bit 0 is set frees this with size 0xd0; returns this.
// @fnv 0x00b90e30
void* S00b90e30::DestroyImageSpaceShaderHDRLightAdapt(unsigned int flags)
{
    *(void**)this = (void*)&vftable_ImageSpaceShaderHDRLightAdapt;
    *(void**)((char*)this + 0x6c) = (void*)&DAT_010B42A4;
    ((C00c03a20*)this)->FUN_00c03a20();
    if (flags & 1)
        _delete(this, 0xd0);
    return this;
}

extern void* vftable_ImageSpaceShaderHDRDownSample16;
extern void* DAT_010B3DF4;
void __cdecl _delete(void*, unsigned int);
struct FUN_00b90980_shell
{
    void FUN_00c03a20();
    void* DestroyImageSpaceShaderHDRDownSample16(unsigned int);
};
// @fnv 0x00b90980
void* FUN_00b90980_shell::DestroyImageSpaceShaderHDRDownSample16(unsigned int auiFlags)
{
    *(void**)this = &vftable_ImageSpaceShaderHDRDownSample16;
    *(void**)((char*)this + 0x6c) = &DAT_010B3DF4;
    FUN_00c03a20();
    if (auiFlags & 1)
        _delete(this, 0xd0);
    return this;
}

extern int vftable_ImageSpaceShaderHDRDownSample16LightAdapt;
extern int DAT_010B4914;
void __cdecl _delete(void*, unsigned int);
struct Unk914
{
    void FUN_00c03a20();
    void* FUN_00b914a0(unsigned int);
};
// Sets the vtable and a member pointer, calls FUN_00c03a20, and if flags bit 0 is set deletes this with size 0xd0, returning this.
// @fnv 0x00b914a0
void* Unk914::FUN_00b914a0(unsigned int flags)
{
    *(void**)this = &vftable_ImageSpaceShaderHDRDownSample16LightAdapt;
    *(void**)((char*)this + 0x6c) = &DAT_010B4914;
    this->FUN_00c03a20();
    if (flags & 1)
        _delete(this, 0xd0);
    return this;
}

void __cdecl FUN_00c03a20(void);
extern int vftable_ImageSpaceShaderHDRDownSample9;
extern int vftable_ImageSpaceShaderHDRDownSample9_2;

struct FUN_00b90b10_shell
{
    void* DestroyImageSpaceShaderHDRDownSample9(unsigned int flags);
};

// @fnv 0x00b90b10
void* FUN_00b90b10_shell::DestroyImageSpaceShaderHDRDownSample9(unsigned int flags)
{
    *(int*)this = (int)&vftable_ImageSpaceShaderHDRDownSample9;
    *(int*)((char*)this + 0x6c) = (int)&vftable_ImageSpaceShaderHDRDownSample9_2;
    FUN_00c03a20();
    if (flags & 1)
        _delete(this, 0xd0);
    return this;
}

extern int DAT_010b37a8;
extern int DAT_010b3788;
struct Candidate : ImageSpaceShaderHDRVariantFour
{
    void* FUN_00b902f0(unsigned int flags);
};
// Sets two vtable pointers, calls FUN_00c03a20, and if flags bit 0 is set frees this with size 0xd0; returns this.
// @fnv 0x00b902f0
void* Candidate::FUN_00b902f0(unsigned int flags)
{
    *reinterpret_cast<void**>(this) = &DAT_010b37a8;
    *reinterpret_cast<void**>(static_cast<ImageSpaceShaderHDRSecondary*>(this)) = &DAT_010b3788;
    reinterpret_cast<H00b90150*>(this)->FUN_00c03a20();
    if (flags & 1)
        _delete(this, 0xd0);
    return this;
}

extern int DAT_010b3af0;
extern int DAT_010b3ad0;
void __cdecl FUN_00aa1460(void*, unsigned int);
struct Target
{
    void* table;
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
    void* secondary;
    void FUN_00c03a20();
    Target* FUN_00b90670(unsigned int flags);
};
// @fnv 0x00b90670
Target* Target::FUN_00b90670(unsigned int flags)
{
    table = &DAT_010b3af0;
    secondary = &DAT_010b3ad0;
    FUN_00c03a20();
    if (flags & 1)
        FUN_00aa1460(this, 0xd0);
    return this;
}

extern int DAT_010b47a0;
extern int DAT_010b477c;

struct FUN_00b91300_cls
{
    void* table;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
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
    void* secondary;

    void FUN_00c03a20();
    FUN_00b91300_cls* FUN_00b91300(unsigned int flags);
};

// @fnv 0x00b91300
FUN_00b91300_cls* FUN_00b91300_cls::FUN_00b91300(unsigned int flags)
{
    table = reinterpret_cast<void*>(&DAT_010b47a0);
    secondary = reinterpret_cast<void*>(&DAT_010b477c);
    FUN_00c03a20();
    if (flags & 1)
    {
        FUN_00aa1460(this, 0xd0);
    }
    return this;
}

// Primary base sized 0x6C (vptr + stand-in ints) so the secondary base
// lands at offset 0x6C in ThkDerived.
struct ThkPrim
{
    virtual void* FUN_00b90180(unsigned int flags);
    int p04, p08, p0C, p10, p14, p18, p1C;
    int p20, p24, p28, p2C, p30, p34, p38;
    int p3C, p40, p44, p48, p4C, p50, p54;
    int p58, p5C, p60, p64, p68;
};

struct ThkSec
{
    virtual void* FUN_00b90180(unsigned int flags);
};

// Override in both vftables; declared only, never defined, so the generated
// [thunk] is the unique defined symbol containing FUN_00b90180.
struct ThkDerived : ThkPrim, ThkSec
{
// @fnv 0x00b90180
    virtual void* FUN_00b90180(unsigned int flags);
};

// Forces vftable emission -> VC9 emits the 0x6C adjustor thunk
// "sub ecx,0x6C; jmp <override>".
static ThkDerived g_thunk;

// sub ecx,0x6c; jmp target == MSVC adjustor thunk for a second base's virtual.
// PrimaryBase = vptr (4) + 26 named ints (104) = 0x6c.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00b90320();
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
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00b90320();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b90320
// src: GUESS 0x00b90320 (confidence: low)
    virtual void AdjustThisAndForward_00b90320();
};

Derived::Derived()
{}

namespace fnv_00b90510 {
// Adjustor thunk: sub ecx,0x6c ; jmp <base implementation>
struct PrimaryBase
{
    virtual void* FUN_00b90510(unsigned int);
    char unk04[0x68];
};

struct SecondaryBase
{
    virtual void* FUN_00b90510(unsigned int);
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b90510
    virtual void* FUN_00b90510(unsigned int);
};

Derived::Derived()
{}

Derived g_derived;
}  // namespace fnv_00b90510

namespace fnv_00b90820 {
// Adjustor thunk: sub ecx,0x6c; jmp <base implementation>
// The derived class overrides a virtual that both of its bases declare, so the
// secondary base's vtable holds a thunk that moves `this` back by the size of
// the primary base (vptr 4 + 26 int fields 104 = 0x6c) before jumping.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00b90820();
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
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00b90820();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b90820
// src: GUESS 0x00b90820 (confidence: low)
    virtual void AdjustThisAndForward_00b90820();
};

Derived::Derived()
{}
}  // namespace fnv_00b90820

namespace fnv_00b909b0 {
// sub ecx,0x6c; jmp target  ==  MSVC adjustor thunk for a virtual overridden through the second base.
struct PrimaryBase
{
    virtual void FUN_00b909b0();
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
};

struct SecondaryBase
{
    virtual void FUN_00b909b0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b909b0
    virtual void FUN_00b909b0();
};

Derived::Derived()
{}
}  // namespace fnv_00b909b0

namespace fnv_00b90b40 {
struct Base1
{
    virtual void AdjustThisAndForward_00b90b40();
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
};
struct Base2
{
    virtual void AdjustThisAndForward_00b90b40();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x00b90b40
// src: GUESS 0x00b90b40 (confidence: low)
    virtual void AdjustThisAndForward_00b90b40();
};
Derived::Derived()
{}
}  // namespace fnv_00b90b40

#include "../../include/NiMemObject.h"
struct FUN_00b90ca0_BaseA : NiMemObject
{
    virtual ~FUN_00b90ca0_BaseA();
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
};
struct FUN_00b90ca0_BaseB
{
    virtual void unk00();
};
struct FUN_00b90ca0_Base : FUN_00b90ca0_BaseA, FUN_00b90ca0_BaseB
{
    ~FUN_00b90ca0_Base();
};
struct FUN_00b90ca0 : FUN_00b90ca0_Base
{
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
    virtual ~FUN_00b90ca0();
};

// @fnv 0x00b90ca0
FUN_00b90ca0::~FUN_00b90ca0()
{}

// Adjustor thunk: this-adjusting thunk that converts a secondary-base pointer
// back into the most-derived pointer before tail-jumping to the implementation.
struct ThunkPrimaryBase
{
    virtual void FUN_00b90cd0();
    int m_i00;
    int m_i01;
    int m_i02;
    int m_i03;
    int m_i04;
    int m_i05;
    int m_i06;
    int m_i07;
    int m_i08;
    int m_i09;
    int m_i10;
    int m_i11;
    int m_i12;
    int m_i13;
    int m_i14;
    int m_i15;
    int m_i16;
    int m_i17;
    int m_i18;
    int m_i19;
    int m_i20;
    int m_i21;
    int m_i22;
    int m_i23;
    int m_i24;
    int m_i25;
};

struct ThunkSecondaryBase
{
    virtual void FUN_00b90cd0();
};

struct ThunkDerived : ThunkPrimaryBase, ThunkSecondaryBase
{
    ThunkDerived();
// @fnv 0x00b90cd0
    virtual void FUN_00b90cd0();
};

ThunkDerived::ThunkDerived()
{}

namespace fnv_00b90e60 {
// MSVC adjustor thunk: the primary base occupies 0x6c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00b90e60();
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
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00b90e60();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b90e60
// src: GUESS 0x00b90e60 (confidence: low)
    virtual void AdjustThisAndForward_00b90e60();
};

Derived::Derived()
{}
}  // namespace fnv_00b90e60

struct FUN_00b90fc0_BaseA : NiMemObject
{
    virtual ~FUN_00b90fc0_BaseA();
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
};
struct FUN_00b90fc0_BaseB
{
    virtual void unk00();
};
struct FUN_00b90fc0_Base : FUN_00b90fc0_BaseA, FUN_00b90fc0_BaseB
{
    ~FUN_00b90fc0_Base();
};
struct FUN_00b90fc0 : FUN_00b90fc0_Base
{
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
    virtual ~FUN_00b90fc0();
};

// @fnv 0x00b90fc0
FUN_00b90fc0::~FUN_00b90fc0()
{}

namespace fnv_00b90ff0 {
// sub ecx,0x6c; jmp target == MSVC adjustor thunk for a second base virtual.
// PrimaryBase = vptr (4) + 26 named ints (104) = 0x6c.
struct PrimaryBase
{
    virtual void FUN_00b90ff0();
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
};

struct SecondaryBase
{
    virtual void FUN_00b90ff0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b90ff0
    virtual void FUN_00b90ff0();
};

Derived::Derived()
{}
}  // namespace fnv_00b90ff0

extern "C" void __cdecl operator_delete_sized(void* pvMem, unsigned int uiSize);

class B91160Primary
{
  public:
    B91160Primary();
    virtual ~B91160Primary();

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
};

class B91160Secondary
{
  public:
    virtual void vfn00();
};

class FUN_00b91160 : public B91160Primary, public B91160Secondary
{
    // The constructor body is empty.
// @fnv 0x00b91160
  public:
    FUN_00b91160()
    {}
    virtual ~FUN_00b91160()
    {}

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
    static void operator delete(void*, void*)
    {}
    static void operator delete(void* pvMem, unsigned int uiSize)
    {
        operator_delete_sized(pvMem, uiSize);
    }

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
};

void* B91160Construct(void* pvMem)
{
    return new (pvMem) FUN_00b91160;
}

namespace fnv_00b91190 {
// sub ecx,0x6c; jmp target == MSVC adjustor thunk (multiple inheritance, primary base sizeof 0x6c).
struct PrimaryBase
{
    virtual void FUN_00b91190();
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
};

struct SecondaryBase
{
    virtual void FUN_00b91190();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b91190
    virtual void FUN_00b91190();
};

Derived::Derived()
{}
}  // namespace fnv_00b91190

namespace fnv_00b91330 {
// Adjustor thunk for FUN_00b91330: sub ecx,0x6c; jmp FUN_00b91300.
// Primary base = vptr + 26 ints (4 + 26*4 = 0x6c); both bases declare the
// claimed virtual, the derived class redeclares it and defines only its ctor.
struct PrimaryBase
{
    virtual void FUN_00b91330();
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
};

struct SecondaryBase
{
    virtual void FUN_00b91330();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b91330
    virtual void FUN_00b91330();
};

Derived::Derived()
{}
}  // namespace fnv_00b91330

namespace fnv_00b914d0 {
struct Base1
{
    virtual void FUN_00b914d0();
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
};
struct Base2
{
    virtual void FUN_00b914d0();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x00b914d0
    virtual void FUN_00b914d0();
};
Derived::Derived()
{}
}  // namespace fnv_00b914d0

struct B906A0Primary : ThkPrim
{
    virtual void* FUN_00b906a0(unsigned int flags);
};

struct B906A0Secondary
{
    virtual void* FUN_00b906a0(unsigned int flags);
};

struct B906A0Derived : B906A0Primary, B906A0Secondary
{
    B906A0Derived();
// @fnv 0x00b906a0
    virtual void* FUN_00b906a0(unsigned int flags);
};

B906A0Derived::B906A0Derived()
{}

static B906A0Derived g_b906a0;
