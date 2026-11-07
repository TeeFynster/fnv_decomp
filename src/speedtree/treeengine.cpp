#include "../../include/CTreeEngine.h"

// src/speedtree/treeengine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/treeengine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00b2bcf0_shell
{
    void CTreeEngine_GetSize(float* a, float* b);
};

// Reads two floats at offsets 0x4c and 0x50 from this and writes them to the two output pointers.
// @fnv 0x00b2bcf0
// src: COMMUNITY 0x00b2bcf0
void FUN_00b2bcf0_shell::CTreeEngine_GetSize(float* a, float* b)
{
    *a = *(float*)((char*)this + 0x4c);
    *b = *(float*)((char*)this + 0x50);
}


// @fnv 0x00b2bd20
// src: COMMUNITY 0x00b2bd20
void CTreeEngine::SetSize_00b2bd20(float afValue, float fVariance)
{
    *(float*)((char*)this + 0x4c) = afValue;
    *(float*)((char*)this + 0x50) = fVariance;
}

struct FUN_00b2bdc0_shell
{
    void UpdateFields_00b2bdc0(float a, float b);
};

// @fnv 0x00b2bdc0
// src: GUESS 0x00b2bdc0 (confidence: low)
void FUN_00b2bdc0_shell::UpdateFields_00b2bdc0(float afValue44, float afValue40)
{
    *(float*)(this + 0x44) = afValue44;
    *(float*)(this + 0x40) = afValue40;
}

void __cdecl operator delete(void*);
struct FUN_00b2ae60_shell
{
    void __thiscall FUN_00b2ae90();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_00b2ae90, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x00b2ae60
void* __thiscall FUN_00b2ae60_shell::DestroyIfFlagged(unsigned int flags)
{
    char stack[0x58];
    FUN_00b2ae90();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct RandomNumberGenerator
{
    void SeedRandomGenerator(long);
    float GenerateRandomFloat(float, float);
};
extern float DAT_0108cb00;
extern float _DAT_010162c0;
struct FUN_00b2c0c0_shell
{
    void InitSeed(unsigned int seed);
};
// @fnv 0x00b2c0c0
void FUN_00b2c0c0_shell::InitSeed(unsigned int seed)
{
    if (seed == 0)
    {
        const int c_nMaxSeed = 1000000;
        ((RandomNumberGenerator*)((char*)this + 0x20))->SeedRandomGenerator(-1);
        *(unsigned int*)((char*)this + 0x48) = (unsigned int)(long)(((RandomNumberGenerator*)((char*)this + 0x20))
                                                                        ->GenerateRandomFloat(2.0f, DAT_0108cb00));
    }
    else if (seed == 1)
    {
    }
    else
        *(unsigned int*)((char*)this + 0x48) = seed;
}

struct ElementIterator
{
    int __thiscall GetNextElement();
};
struct FUN_00b2daf0_shell : CTreeEngine
{
    void __thiscall CTreeEngine_ParseFlareSeed(ElementIterator* a);
};
// @fnv 0x00b2daf0
// src: COMMUNITY 0x00b2daf0
void __thiscall FUN_00b2daf0_shell::CTreeEngine_ParseFlareSeed(ElementIterator* a)
{
    *(int*)((char*)this + 0x54) = a->GetNextElement();
}

namespace std {
template <class C> struct char_traits
{
};

template <class C> struct allocator
{
};

template <class C, class T, class A> class basic_string
{
  public:
    void _Tidy(bool, unsigned int) throw();
    basic_string& assign(const basic_string&, unsigned int, unsigned int);
};
}

extern unsigned int DAT_010173f0;

struct NarrowString : std::basic_string<char, std::char_traits<char>, std::allocator<char> >
{
    NarrowString& AssignFromString(const NarrowString& rhs);
};

// @fnv 0x00b2b8d0
NarrowString& NarrowString::AssignFromString(const NarrowString& aString)
{
    unsigned char unused[92];

    _Tidy(false, 0);
    assign(aString, 0, DAT_010173f0);
    return *this;
}

struct FUN_00b04d40_Obj
{
    float CVec3_Distance(int a);
};

extern FUN_00b04d40_Obj DAT_011f8e9c;
extern double DAT_01012060;
extern double DAT_01012070;

struct FUN_00b2bd40_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float unk14;
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
    float unk40;
    float unk44;

    float __thiscall GetNormalizedValue();
};

// Computes 1 - (v - unk44)/(unk40 - unk44) from DAT_011f8e9c.FUN_00b04d40, sets 1 or 0 past the two thresholds, stores it in unk14 and returns it.
// @fnv 0x00b2bd40
float __thiscall FUN_00b2bd40_Obj::GetNormalizedValue()
{
    float local;
    float fUnused;
    float value = DAT_011f8e9c.CVec3_Distance((int)((char*)this + 4));

    unk14 = 1.0f - (value - unk44) / (unk40 - unk44);

    if (unk14 > DAT_01012070)
    {
        unk14 = 1.0f;
    }
    else if (unk14 < DAT_01012060)
    {
        unk14 = 0.0f;
    }

    return unk14;
}

struct FUN_00b3d720_String
{
    void __thiscall fopen_0044a730(bool a, unsigned int b);
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct FUN_00b3d720_Class
{
    bool unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    FUN_00b3d720_String unk14;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
    float unk50;

    FUN_00b3d720_Class* __thiscall SIdvLeafTexture_SIdvLeafTexture();
};

extern float DAT_01030ff0;
extern float DAT_0101df44;
extern float DAT_01016248;
extern float DAT_010a587c;
extern float DAT_01017b78;

// Sets unk00 false, fills float triples at unk04, unk30, unk3C, unk48 from globals/constants, sets unk10, and calls FUN_0044a730(false, 0) on unk14.
// @fnv 0x00b3d720
// src: XBOX_PDB 0x00b3d720
FUN_00b3d720_Class* __thiscall FUN_00b3d720_Class::SIdvLeafTexture_SIdvLeafTexture()
{
    int unused01;
    int unused02;
    int unused03;
    int unused04;
    int unused05;
    int unused06;
    char buffer_;
    char* bufferPointer;
    float* colorPtr2;
    {
        float* color42Pointer;
        float* color33Pointer5;
        float* color24Pointer9;
        FUN_00b3d720_String* stringlPointer;

        this->unk00 = false;

        colorPtr2 = &this->unk04;
        colorPtr2[0] = DAT_01030ff0;
        colorPtr2[1] = DAT_01030ff0;
        colorPtr2[2] = DAT_01030ff0;

        this->unk10 = DAT_0101df44;

        stringlPointer = &this->unk14;
        bufferPointer = &buffer_;
        stringlPointer->fopen_0044a730(false, 0);

        color24Pointer9 = &this->unk30;
        color24Pointer9[0] = DAT_01016248;
        color24Pointer9[1] = 1.0f;
        color24Pointer9[2] = 0.0f;

        color33Pointer5 = &this->unk3C;
        color33Pointer5[0] = DAT_010a587c;
        color33Pointer5[1] = DAT_010a587c;
        color33Pointer5[2] = 0.0f;

        color42Pointer = &this->unk48;
        color42Pointer[0] = DAT_01017b78;
        color42Pointer[1] = DAT_01017b78;
        color42Pointer[2] = 0.0f;
    }

    return this;
}

extern int DAT_010a5670;
extern const float DAT_01012054;
extern float DAT_01016248;
extern const float DAT_01017870;
extern float DAT_010181bc;
extern const float runtimeFloatSettingDefault1000;

struct FUN_00b3f030
{
    FUN_00b3f030();
    ~FUN_00b3f030();
    void* vfptr;
    int unk04;
    int unk08;
    int unk0c;
};

struct GlobalObject_00b3f100
{
    GlobalObject_00b3f100();
    ~GlobalObject_00b3f100();
};
struct FUN_00b40a60
{
    FUN_00b40a60();
    ~FUN_00b40a60();
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
};

struct FUN_00b17db0
{
    FUN_00b17db0();
    ~FUN_00b17db0();
    int unk00, unk04, unk08, unk0c, unk10, unk14;
};

struct FUN_00b3cd60
{
    FUN_00b3cd60();
    ~FUN_00b3cd60();
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54;
};

struct FUN_00b40850
{
    FUN_00b40850();
    int unk00;
};

struct FUN_00b2ac80
{
    FUN_00b3f030 base00;
    float f10;
    float f14;
    float f18;
    float f1c;
    GlobalObject_00b3f100 go20;
    char b21;
    FUN_00b40a60 s24;
    int i58;
    int i5c;
    FUN_00b17db0 s60;
    int i78;
    FUN_00b17db0 s7c;
    FUN_00b3cd60 s94;
    int iec;
    char bf0;
    float ff4;
    float ff8;
    float ffc;
    float f100;
    float f104;
    int i108;
    FUN_00b40850 s10c;
    void SetWind(float v);
    FUN_00b2ac80(int param);
};

// @fnv 0x00b2ac80
FUN_00b2ac80::FUN_00b2ac80(int param)
    : base00(), f10((base00.vfptr = &DAT_010a5670, 1.0f)), f14(1.0f), f18(DAT_01012054), f1c(0.0f), go20(), b21(1),
      s24(), i58(0), i5c(0), s60(), i78(6), s7c(), s94(), iec(0), bf0(0), ff4(DAT_01016248), ff8(1.0f),
      ffc(DAT_01017870), f100(0.0f), f104(DAT_010181bc), i108(1), s10c()
{
    int d01;
    int d02;
    int d03;
    int d04;
    int d05;
    int d06;
    int d07;
    int d08;
    int d09;
    int d10;
    int d11;
    int d12;
    int d13;
    int d14;
    int d15;
    int d16;
    int d17;
    int d18;
    int d19;
    int d20;
    int d21;
    int d22;
    int d23;
    int d24;
    int d25;
    int d26;
    int d27;
    int d28;
    int d29;
    int d30;
    int d31;
    int d32;
    int d33;
    int d34;
    int d35;
    int d36;
    int d37;
    int d38;
    int d39;
    int d40;
    int d41;
    int d42;
    int d43;
    int d44;
    int d45;
    int d46;
    int d47;
    int d48;
    int d49;
    int d50;
    int d51;
    int d52;
    int d53;
    int d54;
    int d55;
    int d56;
    int d57;
    int d58;
    int d59;
    int d60;
    i5c = param;
    SetWind(runtimeFloatSettingDefault1000);
}
