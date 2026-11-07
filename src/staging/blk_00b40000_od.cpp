
// src/staging/blk_00b40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/CIdvCamera.h"

// @fnv 0x00b402d0
// src: GUESS 0x00b402d0 (confidence: low)
CIdvCamera& CIdvCameraClone::UpdateState_00b402d0(CIdvCamera const& src)
{
    if (&src != this)
    {
        CIdvCamera::AssignFields_00b3f0c0(src);
        unk10 = static_cast<const CIdvCameraClone&>(src).unk10;
        unk14 = static_cast<const CIdvCameraClone&>(src).unk14;
        unk18 = static_cast<const CIdvCameraClone&>(src).unk18;
        unk1C = static_cast<const CIdvCameraClone&>(src).unk1C;
        unk40 = static_cast<const CIdvCameraClone&>(src).unk40;
        unk44 = static_cast<const CIdvCameraClone&>(src).unk44;
        unk48 = static_cast<const CIdvCameraClone&>(src).unk48;
        unk28 = static_cast<const CIdvCameraClone&>(src).unk28;
        unk34 = static_cast<const CIdvCameraClone&>(src).unk34;
    }
    return *this;
}

struct FUN_00ec7c56_t
{
    static void FUN_00ec7c56();
};

struct FUN_00b42980
{
    int a;
    int b;
    FUN_00b42980& Set(unsigned int v, FUN_00b42980 const& src);
};

// Clears a, validates v against src's bounds (calling FUN_00ec7c56 on failure), then copies src.a into a and stores v into b.
// @fnv 0x00b42980
FUN_00b42980& FUN_00b42980::Set(unsigned int v, FUN_00b42980 const& src)
{
    a = 0;
    if (!(&src && ((unsigned int*)&src)[3] <= v && v <= ((unsigned int*)&src)[4]))
    {
        FUN_00ec7c56_t::FUN_00ec7c56();
    }
    a = src.a;
    b = v;
    return *this;
}

void* operator new(unsigned int);

// Allocates a new camera object, copies this camera into it via FUN_00b402d0, and returns the new object by reference.
// @fnv 0x00b403a0
CIdvCamera& CIdvCameraClone::CloneCamera()
{
    CIdvCameraClone* p = new CIdvCameraClone;
    p->UpdateState_00b402d0(*this);
    return *p;
}

void FUN_00ec7c56();

struct FUN_00b40800_t
{
    int pos;
    int pad;
    char GetNextChar();
};

// Returns the character at the current position, advances pos, and calls FUN_00ec7c56 if the index is out of range.
// @fnv 0x00b40800
char FUN_00b40800_t::GetNextChar()
{
    int idx = pos;
    pos = pos + 1;
    int* p = (int*)((char*)this + 4);
    if ((unsigned int)idx >= (unsigned int)(p[4] - p[3]))
        FUN_00ec7c56();
    return *(char*)(p[3] + idx);
}

extern int DAT_010a58fc;

// The shared camera header does not yet declare this parameterized initializer.
// Keep its declarations here while using the shared camera layout.
struct CIdvCameraInitializer : CIdvCameraClone
{
    void FUN_00b3f030();
    CIdvCameraInitializer* __thiscall UpdateState_00b40070(NiPoint3* position, unsigned char value18, unsigned char value10,
                                                float value, int result);
};

// Calls FUN_00b3f030, sets unk00 to &DAT_010a58fc, stores value10, value18, value and result, zeroes three points, and copies position into unk04.
// @fnv 0x00b40070
// src: GUESS 0x00b40070 (confidence: low)
CIdvCameraInitializer* __thiscall CIdvCameraInitializer::UpdateState_00b40070(NiPoint3* position, unsigned char value18,
                                                                unsigned char value10, float value, int result)
{
    NiPoint3* firstPointA;
    NiPoint3* thirdPointA;
    NiPoint3* secondPointA;

    this->FUN_00b3f030();
    *(void**)this = &DAT_010a58fc;
    this->unk10 = value10;
    this->unk14 = -1;
    this->unk18 = value18;

    firstPointA = &this->unk1C;
    firstPointA->z = 0.0f;
    firstPointA->y = 0.0f;
    firstPointA->x = 0.0f;

    thirdPointA = &this->unk28;
    thirdPointA->z = 0.0f;
    thirdPointA->y = 0.0f;
    thirdPointA->x = 0.0f;

    secondPointA = &this->unk34;
    secondPointA->z = 0.0f;
    secondPointA->y = 0.0f;
    secondPointA->x = 0.0f;

    this->unk40 = 0;
    this->unk44 = value;
    this->unk48 = result;
    reinterpret_cast<NiPoint3&>(this->m_kTranslation) = *position;

    return this;
}

extern float DAT_01016248;
struct FUN_00b40850
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C[3];
    float unk18;
    FUN_00b40850();
};
// Initialises the object's fields: unk00 and unk04 to DAT_01016248, unk08, unk0C's x/y/z and unk18 to 0.0f.
// @fnv 0x00b40850
FUN_00b40850::FUN_00b40850()
{
    unk00 = DAT_01016248;
    unk04 = DAT_01016248;
    unk08 = 0.0f;
    NiPoint3* p = (NiPoint3*)unk0C;
    p->x = 0.0f;
    p->y = 0.0f;
    p->z = 0.0f;
    unk18 = 0.0f;
}

extern float DAT_0107d9a0;
extern float DAT_01016410;
extern float DAT_0101b268;

class FUN_00b40a60_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    float m_1c;
    float m_20;
    unsigned int m_24;
    float m_28;
    float m_2c;
    unsigned int m_30;

    void InitBase(int a, int b);
    FUN_00b40a60_cls* InitializeFields_00b40a60();
};

struct FUN_00b40a60_loc
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
};

// @fnv 0x00b40a60
// src: GUESS 0x00b40a60 (confidence: low)
FUN_00b40a60_cls* FUN_00b40a60_cls::InitializeFields_00b40a60()
{
    unsigned int pad;
    unsigned char* pFlag;
    unsigned char isSet;
    pFlag = &isSet;
    {
        FUN_00b40a60_loc loc;
    }
    InitBase(0, 0);
    m_1c = DAT_0107d9a0;
    m_20 = DAT_01016410;
    m_24 = 0x4b0;
    m_28 = DAT_0101b268;
    m_2c = 0.0f;
    m_30 = 0x1bc;
    return this;
}

struct FUN_00b40ad0_Frame
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
    int unk64;
    int unk68;
    int unk6C;
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
};

struct FUN_00b40ad0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_18;
    float m_1c;
    int m_20;
    float m_24;
    void FUN_00b416d0();
    FUN_00b40ad0_cls* Init(int a, float b, float c, float d);
};

// Calls FUN_00b416d0, then stores the three floats and the int into m_18, m_1c, m_24 and m_20, and returns this.
// @fnv 0x00b40ad0
FUN_00b40ad0_cls* FUN_00b40ad0_cls::Init(int a, float b, float c, float d)
{
    FUN_00b40ad0_Frame frame;
    this->FUN_00b416d0();
    m_18 = b;
    m_1c = c;
    m_20 = a;
    m_24 = d;
    return this;
}

// Stand-in for the class that owns ReserveEntries.
// Offsets are taken from the original code:
//   +0x0c  buffer pointer, +0x10 buffer start, +0x14 buffer end.
struct FnvCamera
{
    int unk00;
    int unk04;
    int unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    bool ReserveEntries(unsigned int count);
};

// The original reserves 0x90 bytes of frame for one local aggregate;
// only its last dword is touched by this function.
struct FnvScratch
{
    unsigned int unk00;
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
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
};

// The allocator the original calls with (count, 0); it hands out count * 8 bytes.
void* Runtime_UpdateState_00b42df0(unsigned int count, void* allocator);

// The out-of-range reporter the original calls when the count is too large.
void BxLengthError_Thunk();

// @fnv 0x00b41c80
bool FnvCamera::ReserveEntries(unsigned int count)
{
    FnvScratch scratch;

    unk0c = 0;
    unk10 = 0;
    unk14 = 0;

    if (count == 0)
    {
        return false;
    }
    else
    {
        scratch.unk8c = 0x1fffffff;
        if ((scratch.unk8c > 0 ? scratch.unk8c : 1) < count)
        {
            BxLengthError_Thunk();
        }
        else
        {
            unk0c = Runtime_UpdateState_00b42df0(count, 0);
            unk10 = unk0c;
            unk14 = (char*)unk0c + count * 8;
        }
    }
    return true;
}

struct FUN_00b42be0_cls
{
    unsigned int* m_00;
    unsigned int m_04;
    unsigned int m_08;

    FUN_00b42be0_cls* InitializeFields_00b42be0(FUN_00b42be0_cls* src);
};

// @fnv 0x00b42be0
// src: GUESS 0x00b42be0 (confidence: low)
FUN_00b42be0_cls* FUN_00b42be0_cls::InitializeFields_00b42be0(FUN_00b42be0_cls* src)
{
    unsigned int* x8;
    unsigned int* y;
    unsigned int* r;
    unsigned int _q;
    unsigned int s;

    if (src->m_00 != 0)
    {
        x8 = src->m_00;
        r = y;
        r = (unsigned int*)*x8;
    }
    else
    {
        r = 0;
    }
    s = src->m_08;
    _q = src->m_04;
    m_00 = 0;
    m_04 = _q;
    m_08 = s;
    if (r == 0)
    {
        FUN_00ec7c56_t::FUN_00ec7c56();
    }
    m_00 = (unsigned int*)*r;
    return this;
}

class FUN_00b420a0_cls
{
  public:
    FUN_00b42980 m_obj;
    int CompareAndGetDelta(FUN_00b42980 const& arg);
};

// If m_obj.a is nonzero and equals arg.a, returns (m_obj.b - arg.b) >> 2; otherwise calls FUN_00ec7c56 first.
// @fnv 0x00b420a0
int FUN_00b420a0_cls::CompareAndGetDelta(FUN_00b42980 const& arg)
{
    if (!((bool)(int)(m_obj.a != 0) && (bool)(int)(m_obj.a == arg.a)))
        FUN_00ec7c56();
    return (m_obj.b - arg.b) >> 2;
}

void* operator new(unsigned int);

extern char DAT_010176f8[];
extern char DAT_01140ef8[];

struct FnvThrowObj
{
    void* vptr;
    const char* what;
    bool dofree;

    void FUN_00ec78f1(int* value);
};

// @fnv 0x00b42df0
// src: GUESS 0x00b42df0 (confidence: low)
void* __cdecl Runtime_UpdateState_00b42df0(unsigned int count, void* allocator)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (0xFFFFFFFFu / count < 8u)
    {
        int value = 0;
        FnvThrowObj kObj;
        kObj.FUN_00ec78f1(&value);
        kObj.vptr = DAT_010176f8;
        _CxxThrowException(&kObj, (_ThrowInfo*)DAT_01140ef8);
    }
    return operator new(count << 3);
}

struct S_00b41ae0_Pad
{
    unsigned int a[18];
};
struct S_00b41ae0_Bits
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;

    unsigned int* EvaluateValue_00b420f0();
    S_00b41ae0_Bits* SetBit(bool bSet);
};

// Sets or clears the bit at index unk08 in the word returned by FUN_00b420f0, then returns this.
// @fnv 0x00b41ae0
S_00b41ae0_Bits* S_00b41ae0_Bits::SetBit(bool bSet)
{
    S_00b41ae0_Pad pad;
    if (bSet)
    {
        *EvaluateValue_00b420f0() |= (1u << unk08);
    }
    else
    {
        *EvaluateValue_00b420f0() &= ~(1u << unk08);
    }
    return this;
}

// Divides the three low bytes of unk14 by 255.0, low byte first, writes them to pOut[0], pOut[1] and pOut[2], and returns pOut.
// @fnv 0x00b40430
// src: COMMUNITY 0x00b40430
float* CIdvCamera::CBillboardLeaf_GetColor(float* pOut)
{
    float fGr = (static_cast<unsigned int>(static_cast<CIdvCameraClone*>(this)->unk14) & 0xff) / 255.0;
    float fRed = ((static_cast<unsigned int>(static_cast<CIdvCameraClone*>(this)->unk14) & 0xff00) >> 8) / 255.0;
    float fBl = ((static_cast<unsigned int>(static_cast<CIdvCameraClone*>(this)->unk14) & 0xff0000) >> 16) / 255.0;
    pOut[0] = fGr;
    pOut[1] = fRed;
    pOut[2] = fBl;
    return pOut;
}

struct RandomGen
{
    const char* GetName();
};

// @fnv 0x00b43d60
const char* RandomGen::GetName()
{
    return "Random";
}

struct Gen
{
    const char* GetConstantString();
};

// @fnv 0x00b43d70
// src: GUESS 0x00b43d70 (confidence: high)
const char* Gen::GetConstantString()
{
    return "Uniform";
}

namespace fnv_00b43d80 {
struct Gen
{
    const char* ComputeValue_00b43d80();
};

// @fnv 0x00b43d80
// src: GUESS 0x00b43d80 (confidence: low)
const char* Gen::ComputeValue_00b43d80()
{
    return "Normal";
}
}  // namespace fnv_00b43d80

namespace fnv_00b43d90 {
struct Gen
{
    const char* GetConstantString();
};

// @fnv 0x00b43d90
// src: GUESS 0x00b43d90 (confidence: high)
const char* Gen::GetConstantString()
{
    return "PosGen";
}
}  // namespace fnv_00b43d90

namespace fnv_00b43da0 {
struct Gen
{
    const char* ComputeValue_00b43da0();
};

// @fnv 0x00b43da0
// src: GUESS 0x00b43da0 (confidence: low)
const char* Gen::ComputeValue_00b43da0()
{
    return "SymGen";
}
}  // namespace fnv_00b43da0
