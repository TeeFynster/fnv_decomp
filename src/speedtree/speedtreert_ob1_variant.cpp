#include "../../include/MemoryManager.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; this unit defines inline bodies for both NiPoint3 and the stand-in in different forms (constructor/temporary, operand order), so one NiPoint3 cannot carry both.
#include "../../include/NiPoint3.h"
class Allocator;
class Elem16;
struct Mat;
struct Matrix4;
class NiPoint3;

struct LocalVec3
{
public:
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };

    LocalVec3();
    // Keep the implicit copy constructor trivial for by-value calls.
    LocalVec3(float x, float y = 0.0f, float z = 0.0f);
    LocalVec3(const float* data);

    __forceinline LocalVec3& operator=(const LocalVec3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    LocalVec3 operator+(const LocalVec3& other) const;
    LocalVec3 operator-(const LocalVec3& other) const;
    NiPoint3 operator-(const NiPoint3& other) const;
    LocalVec3 operator-() const;
    LocalVec3 operator*(float scale) const;
    LocalVec3 operator*(double scale) const;
    LocalVec3& operator+=(const LocalVec3& other);
    LocalVec3& operator*=(float scale);
    LocalVec3& operator/=(float scale);
    bool operator==(const LocalVec3& other) const;
    bool operator!=(const LocalVec3& other) const;
    float& operator[](int index);
    float& operator[](unsigned int index);

    LocalVec3* Self();
    void Set(float x, float y, float z);
    void AssignOutput(const LocalVec3& other);
    LocalVec3 Neg() const;
    LocalVec3 Add(const LocalVec3& other) const;
    LocalVec3 Added(const LocalVec3& other) const;
    LocalVec3& AddTo(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other) const;
    void Subtract(const LocalVec3& other);
    LocalVec3 Scale(float scale) const;
    LocalVec3 ApplyScaled(float scale);
    LocalVec3 ApplyScaled(float scale) const;
    LocalVec3 ScaleSwizzled(float scale);
    LocalVec3 ScaleSwizzled(float scale) const;
    void ScaleByInverse(float scale);
    void Normalize();
    void Unitize();
    LocalVec3 Cross(const LocalVec3& other) const;
    float Dot(const LocalVec3& other) const;
    float DotProduct(const LocalVec3& other);
    float DotProduct(const LocalVec3& other) const;
    float DotProduct(const LocalVec3* other) const;
    float Length() const;
    float LengthSquared() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;
    Elem16& expand(Allocator& allocator);

    void SetComponents(float x, float y, float z);
    bool FUN_00439090(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other) const;
    bool HasEqualComponents(const char* other);
    void ScaleComponents(float scale);
    LocalVec3 FUN_00439e90(const LocalVec3& other);
    LocalVec3 FUN_00439e90(const LocalVec3& other) const;
    void SubtractIntoVector();
    LocalVec3 SubtractIntoVector(const LocalVec3& other);
    LocalVec3 SubtractIntoVector(const LocalVec3& other) const;
    LocalVec3 SubtractIntoVector(LocalVec3* other);
    LocalVec3 SubtractIntoVector(const LocalVec3* other);
    void SubtractIntoVector(LocalVec3* output, const LocalVec3* other);
    LocalVec3* SubtractIntoVector(void* output, void* other);
    void FUN_0043d410(float x, int y, int z);
    void FUN_0043d410(float x, unsigned int y, unsigned int z);
    float FUN_00457910();
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    float FUN_004a7290();
    float FUN_004a7290() const;
    LocalVec3 FUN_004b3800(const LocalVec3& other) const;
    LocalVec3 ProcessAndReturnValue_0053d280(float divisor);
    float NiPoint3_XYLength();
    float NiPoint3_XYLength() const;
    void ComputeValue_0063c8a0(const LocalVec3* other);
    void ComputeValue_0063c8a0(void* other);
    void FUN_006815c0();
    float CVec3_Distance(LocalVec3* other);
    float CVec3_Distance(const LocalVec3& other) const;
    LocalVec3 TransformPointByMatrix4(const Mat& matrix);
    LocalVec3 TransformPointByMatrix4(const Matrix4* matrix);
    void Normalize_00b12790();
    LocalVec3 Diff_00b13040(void* other);
    LocalVec3 Diff_00b13040(const LocalVec3& other) const;
    float FUN_00b2a180(void* other);
    LocalVec3& AddComponents(void* other);
    void ProcessEntries_00ddc870();
    void FUN_00e0f6e0();
};
#include "../../include/CVec3.h"

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#pragma intrinsic(memcpy)

inline LocalVec3::LocalVec3()
{
    z = 0.0f;
    y = 0.0f;
    x = 0.0f;
}

inline LocalVec3 LocalVec3::operator-() const
{
    return LocalVec3(-x, -y, -z);
}

inline LocalVec3::LocalVec3(float a, float b, float c)
{
    x = a;
    y = b;
    z = c;
}

inline float& LocalVec3::operator[](int i)
{
    return (&x)[i];
}

inline const float& CVec3::operator[](int i) const
{
    return (&x)[i];
}

inline CVec3::CVec3(float fx, float fy, float afDepth)
{
    x = fx;
    y = fy;
    z = afDepth;
}


// src/speedtree/speedtreert_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/speedtreert.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/speedtreert.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/speedtreert.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00b02e00_class
{
    void UpdateFields_00b02e00();
};
struct FUN_00b2bcf0_shell
{
    void CTreeEngine_GetSize(float*, float*);
    void CSpeedTreeRT_GetTreeSize(float* a, float* b);
};
struct FUN_00b071c0_Class
{
    void __thiscall SetField14(int param);
};
struct FUN_00b07390_class
{
    void* m_p;
    void SetField9C(float f);
};
struct FUN_00b073c0_class
{
    void* m_p;
    void SetField98(float f);
};
struct FUN_00b07490
{
    void* m_p;
    void Set(float f);
};
struct FUN_00b074c0_class
{
    void* m_p;  // +0x0
    void SetFieldD0(float f);
};
struct FUN_00b074f0_obj
{
    void* GetNestedPointer();
};
struct FUN_00b076c0_Class
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    void* m20;
    void* m24;
    void* m28;
    void* m2c;
    void* m30;
    void* m34;
    void* m38;
    void* m3c;
    void* m40;
    void* m44;
    void* m48;
    void* m4c;
    void* m50;
    void* m54;
    void* m58;
    void* m5c;
    void* m60;
    void* m64;
    void* m68;
    void* m6c;
    void* m70;
    void* m74;
    void* m78;
    void* m7c;
    void* m80;
    void* m84;
    void* m88;
    void* m8c;
    void* m90;
    void* m94;
    void* m98;
    void* m9c;
    void* ma0;
    void* ma4;
    void* ma8;
    void* mac;
    void* mb0;
    void* mb4;
    void* mb8;
    void* mbc;
    void* mc0;
    void* mc4;
    void* mc8;
    void* mcc;
    void* md0;
    void* md4;
    void* md8;
    void* mdc;
    void* me0;
    void* me4;
    void* me8;
    void* mec;
    void* mf0;
    void* mf4;
    void* mf8;
    void* mfc;
    void* fun_00b076c0();
};
struct FUN_00b078e0_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* GetFieldAt0C();
};
struct FUN_00b2bdc0_shell
{
    void UpdateFields_00b2bdc0(float, float);
};
struct FUN_00b08500_shell
{
    void CSpeedTreeRT_SetNearFarDists(float a, float b);
};
struct FUN_00b086f0_class
{
    unsigned short __thiscall GetLowWordAtOffset0x78();
};
struct CSpeedTreeRT
{
    void* m_pFirstPointer;
    unsigned short GetNumLeafLodLevels();
};
struct FUN_00b0d5d0_Class
{
    int m_unk_00;
    int m_unk_04;
    int m_unk_08;
    int m_unk_0c;
    int m_unk_10;
    int m_unk_14;
    int m_unk_18;
    int m_unk_1c;
    int m_unk_20;
    int m_unk_24;
    int m_unk_28;
    int m_unk_2c;
    int m_unk_30;
    int m_unk_34;
    int m_unk_38;
    int m_unk_3c;
    int m_unk_40;
    int m_unk_44;
    int m_unk_48;
    int m_unk_4c;
    int m_unk_50;
    int m_unk_54;
    int m_unk_58;
    int m_unk_5c;
    int m_unk_60;
    int m_unk_64;
    int m_unk_68;
    int GetUnk68();
};
struct FUN_00b051e0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* CSpeedTreeRT_InstanceOf();
};
struct FUN_0065f2b0_class
{
    void std_vector_float_std_allocator_float_Destroy(int, int);
};
struct FUN_0064df10_helper
{
    void deallocate(void*, unsigned int);
};
struct FUN_00657f60_class
{
    int a;
    int b;
    int c;
    void* d;
    void* e;
    void* f;
    void ReleaseStorage_00657f60();
};
struct FUN_00b02e20
{
    void* p0;
    void* p4;
    void* p8;
    void* pc;
    void* p10;
    void* p14;
    void* p18;
    FUN_00b02e20();
};
struct GlobalObject_00b3f100
{
    char data[0x18];
    ~GlobalObject_00b3f100();
};
struct FUN_00b050d0_class
{
    GlobalObject_00b3f100 a;
    GlobalObject_00b3f100 b;
    ~FUN_00b050d0_class();
};
struct FUN_00b08440_shell
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    float CSpeedTreeRT_GetLodLevel();
};
extern unsigned char DAT_011f8b78;
void CSpeedTreeRT_SetDropToBillboard(unsigned char param_1);
void __cdecl _memmove(void* dst, const void* src, unsigned int size);
void __cdecl AssignString(const char* s);
struct CSpeedTreeRT_GetBoundingBox
{
    void __thiscall CSpeedTreeRT_GetBoundingBox_00b08c80(float* dst);
};
struct FUN_00b0a260_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    void* m_40;
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    int __thiscall GetEntryCount();
};
extern unsigned char DAT_011f8b79;
void CSpeedTreeRT_SetFlipTextures(unsigned char param_1);
struct FUN_00b02b70_shell
{
    int m_iWordAt00;
    unsigned short m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    unsigned short m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    FUN_00b02b70_shell();
};
struct FUN_00b02c10_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void ClearPointers();
};
struct FUN_00b02c90_class
{
    char m_iWordAt00;
    float m_iWordAt04;
    int m_8;
    unsigned short m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    FUN_00b02c90_class();
};
struct FUN_00b02d40_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void __thiscall ClearFields();
};
extern MemoryManager g_memoryManager;
struct FUN_00b02e80
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* m10;
    int m14;
    int m18;
    ~FUN_00b02e80();
};
extern int DAT_011f8e9c;
extern int DAT_011f8ea0;
extern int DAT_011f8ea4;
extern int DAT_011f8eac;
extern int DAT_011f8eb0;
extern int DAT_011f8eb4;
void __cdecl CSpeedTreeRT_GetCamera(float* pPosition, float* pDirection);
struct FUN_00b08480_shell
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void CSpeedTreeRT_SetLodLevel(float f);
};
struct FUN_00b02dc0_class
{
    char m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    float m_iThirdValue;
    unsigned short m_10;
    FUN_00b02dc0_class();
};
struct FUN_00b2b940_class
{
    unsigned char m_bFlag;  // +0x21
    void FUN_00b2b940();
};
struct FUN_00b053e0_shell
{
    void CSpeedTreeRT_DeleteTransientData();
};
struct FUN_00b073f0_class
{
    void* m_p;  // +0x0
    float GetNestedFloatOrZero();
};
struct FUN_00b07440_Class
{
    void* m_p;
    float __thiscall GetNestedFloatOrZero_00b07440();
};
namespace std {
template <class _CharT> struct char_traits
{
};

template <class _CharT> struct allocator
{
};

template <class _CharT, class _Traits, class _Alloc> class basic_string
{
  public:
    void __thiscall _Tidy(bool, unsigned int);
};
}

struct FUN_0044d6f0_This
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void __thiscall FUN_00ec79a1();
};
extern int DAT_010a307c;
struct FUN_00b09780_class : FUN_0044d6f0_This
{
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_iThirdValue;

    void __thiscall UpdateFields_00b09780();
};
extern int DAT_010a51e0;
struct FUN_00b097b0_class
{
    void* m_p;
    char pad[0x60];
    void FUN_00aca270(int a);
    int* IdvFileError_IdvFileError(int a);
};
struct FUN_00b09f70_Class
{
    void ProcessState_00b09f70();
    void _Tidy(bool, unsigned int);
};
extern MemoryManager _g_memoryManager;
unsigned int _strlen(const char* s);
char* DuplicateString(const char* pOrig);
extern unsigned char DAT_011f8b79;
unsigned char __cdecl CSpeedTreeRT_GetTextureFlip();
struct BoundingBlock
{
    FUN_00b02c10_class contained;
    int extra38;
    __forceinline ~BoundingBlock()
    {
        contained.ClearPointers();
    }
};
struct BranchBlock
{
    FUN_00b02d40_class contained;
    __forceinline ~BranchBlock()
    {
        contained.ClearFields();
    }
};
struct LeafBlock
{
    FUN_00b02e00_class contained;
    int extra04, extra08, extra0c, extra10;
    __forceinline ~LeafBlock()
    {
        contained.UpdateFields_00b02e00();
    }
};
struct FUN_00b02ac0
{
    BoundingBlock root;
    BoundingBlock bounds;
    BranchBlock limbA;
    BranchBlock limbB;
    LeafBlock leafA;
    LeafBlock leafB;
    LeafBlock leafC;
    ~FUN_00b02ac0();
};
extern double _DAT_0101a6b0;
struct FUN_00b08610_shell
{
    unsigned short __thiscall CSpeedTreeRT_GetDiscreteLeafLodLevel(float fLodLevel);
};
struct std_string
{
    void assign(const char*, unsigned int);
};
extern std_string DAT_011f8ba4;
unsigned int _strlen(const char*);
void __cdecl AssignString(const char* s);
extern unsigned char DAT_011f8b78;
void __cdecl AssignString(const char* s);
void __cdecl CSpeedTreeRT_GetTransitionValues(float a, unsigned short n, float b, float c, float d, float e, float* pf1, float* pf2,
                          short* ps1, short* ps2);
struct FUN_00b0b920_geo
{
    char m_00[0xc];
    float* m_0c;
    float* m_10;
};
struct FUN_00b0b920_engine
{
    char m_00[0x88];
    FUN_00b0b920_geo m_geo;
    int FUN_00b4b0();
    int FUN_00b530();
    int FUN_00b5b0();
    int FUN_00b630();
    int FUN_00b6b0();
    int FUN_00b730();
    int FUN_00b7b0();
    int FUN_00b830();
    int FUN_00b8b0();
    unsigned short CIndexedGeometry_GetNumStrips(unsigned short i);
    int CIndexedGeometry_GetStripLengthsPointer(unsigned short i);
    int CIndexedGeometry_GetStripsPointer(unsigned short i);
};
struct FUN_00b0b920_arg
{
    char m_00[0x3c];
    FUN_00b02b70_shell m_sub;
    float m_74;
};
struct FUN_00b0b920_self
{
    char m_00[0x1c];
    float m_1c;
    float m_20;
    int m_24;
    float m_28;
    char m_2c[0x18];
    unsigned char m_44;
    char m_45[0x1b];
    FUN_00b0b920_engine* m_60;
    unsigned short GetNumLeafLodLevels();
    short CSpeedTreeRT_GetDiscreteFrondLodLevel(float f);
    float CSpeedTreeRT_GetLodLevel();
    void FillFrondGeometry(FUN_00b0b920_arg* arg, short type);
};
struct HelperC780
{
    void* CSimpleBillboard_GetBillboardCoords(float, float);
};
void __cdecl CSpeedTreeRT_GetTransitionValues(float, unsigned short, float, float, float, float, float*, float*, short*, short*);
extern "C" char DAT_011ad124;
struct BlockC4
{
    char pad[20];
    float a, b;
};
typedef float EntryC4;
struct ListC4
{
    char pad[8];
    int count;
    EntryC4* data;
};
struct OutC4
{
    char pad[0xf0];
    unsigned char active;
    char p1[3];
    EntryC4* data;
    void* value;
    float weight;
    unsigned short n;
    char p2[2];
    unsigned char active2;
    char p3[15];
    unsigned short n2;
    char p4[2];
    unsigned char active3;
    char p5[3];
    EntryC4* last;
    void* ptr;
    float weight2;
    unsigned short n3;
};
struct TreeC4
{
    char pad[0x14];
    HelperC780* helper;
    int p18;
    float x;
    float y;
    int p24;
    float z;
    char p2c[0x14];
    BlockC4* block;
    unsigned char mode;
    char p45[7];
    ListC4* list;
    char p50[0x1d];
    unsigned char enabled;
    char p6e[2];
    int data;
    void FillSpeedTreeOutput(OutC4* out);
};
struct P8
{
    int c0, b, fB, d, e, f, g, h;
};
struct S0cf90
{
    LocalVec3* AddVector(LocalVec3* fDist, LocalVec3* dst, LocalVec3* fB, float f);
};
struct T3ea10
{
    void CProjectedShadow_ComputeTexCoords(void* c0, LocalVec3 fB, float b0, void* p);
};
struct B0cdd0
{
    char pad[0x34];
    int v;
};
struct FUN_00b0cdd0_cls
{
    int m0;
    void* m4;
    char pad8[0x38];
    float* m40;
    int m44, m48;
    B0cdd0* m4c;
    T3ea10* m50;
    int m54, m58, m5c;
    void* m60;
    void CSpeedTreeRT_ComputeSelfShadowTexCoords();
};
struct StringRecord
{
    int metadata;
    union
    {
        char* allocated;
        char inlineChars[16];
    };
    unsigned int length, capacity;
    int extra1, extra2, extra3, extra4;
};
struct RecordVector
{
    int metadata0, metadata4, metadata8;
    StringRecord *first, *last;
};
void __cdecl FUN_00ec7c56();
struct FUN_00b0d490_Class
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    RecordVector records;
    char* GetRecordStringDataChecked(unsigned int index);
};
struct Vec2
{
    float x;
    float y;
};
struct FUN_00b0d5f0_Class
{
    int m_unk_00;
    int m_unk_04;
    int m_unk_08;
    int m_unk_0c;
    int m_unk_10;
    int m_unk_14;
    int m_unk_18;
    int m_unk_1c;
    int m_unk_20;
    int m_unk_24;
    int m_unk_28;
    int m_unk_2c;
    int m_unk_30;
    int m_unk_34;
    int m_unk_38;
    int m_unk_3c;
    float* m_pBoundingBox;
    int m_unk_44;
    int m_unk_48;
    int m_unk_4c;
    int m_unk_50;
    int m_unk_54;
    int m_unk_58;
    int m_unk_5c;
    int m_unk_60;
    int m_unk_64;
    int m_unk_68;
    char m_unk_6c;
    unsigned char m_bFlag;
    char m_unk_6e;
    char m_unk_6f;
    float m_point00;
    float m_point01;
    float m_point02;
    float m_point03;
    float m_point04;
    float m_point05;
    float m_point06;
    float m_point07;
    float m_point08;
    float m_point09;
    float m_point10;
    float m_point11;

    void InitBoundingBoxCorners();
};
void __cdecl FUN_00ec7c56();
struct FUN_00b0eca0_t
{
    int a;
    int b;
    bool ProcessEntries_00b0eca0(FUN_00b0eca0_t* p);
};
void __cdecl FUN_00ec7c56(void);
struct FUN_00b10430_Arg
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0C;
    unsigned int unk10;
};
struct FUN_00b10430_Class
{
    int unk00;
    int unk04;

    FUN_00b10430_Class* __thiscall SetCheckedRangeIndex(unsigned int index, FUN_00b10430_Arg* range);
};

struct Mat
{
    float f0;
    float f4[4];
    float f14;
    float f18[4];
    float f28;
};
struct Elem
{
    int type;
    float x;
    float y;
    float z;
    float f10;
    float f14;
    float f18;
};
struct Cont;
struct FUN_00b10430
{
    Elem* p;
    Cont* c;
    FUN_00b10430(Elem* q, Cont* cc);
};
struct It : FUN_00b10430
{
    inline It(Elem* q, Cont* cc) : FUN_00b10430(q, cc)
    {}
    bool ProcessEntries_00b0eca0(const It& r);
    It& ProcessEntries_00b0eb30();
    Elem& ProcessEntries_00b0ebb0();
    inline bool operator!=(const It& r)
    {
        return !ProcessEntries_00b0eca0(r);
    }
    inline Elem* operator->()
    {
        return &ProcessEntries_00b0ebb0();
    }
};
inline void Dead3()
{
    int d0;
    int d1;
    int d2;
}
struct Cont
{
    int i0;
    int i4;
    int i8;
    Elem* pFirst;
    Elem* pLast;
    inline It Begin()
    {
        return It(pFirst, this);
    }
    inline It End()
    {
        return It(pLast, this);
    }
    void SCollisionObjects_TransformAll(const Mat& m);
};
// @fnv 0x00b04db0
// src: COMMUNITY 0x00b04db0
void Cont::SCollisionObjects_TransformAll(const Mat& m)
{
    for (It it = Begin(); it != End(); it.ProcessEntries_00b0eb30())
    {
        LocalVec3 pos(it->x, it->y, it->z);
        memcpy(&pos, &pos.TransformPointByMatrix4(m), sizeof(pos));
        it.ProcessEntries_00b0ebb0().x = pos[0];
        it.ProcessEntries_00b0ebb0().y = pos[1];
        it.ProcessEntries_00b0ebb0().z = pos[2];
        Dead3();
        if (it->type == 0)
        {
            it.ProcessEntries_00b0ebb0().f10 *= m.f0;
        }
        else if (it->type == 1)
        {
            Dead3();
            it.ProcessEntries_00b0ebb0().f10 *= m.f0;
            it.ProcessEntries_00b0ebb0().f14 *= m.f0;
        }
        else if (it->type == 2)
        {
            Dead3();
            it.ProcessEntries_00b0ebb0().f10 *= m.f0;
            it.ProcessEntries_00b0ebb0().f14 *= m.f14;
            it.ProcessEntries_00b0ebb0().f18 *= m.f28;
        }
    }
}

extern "C" int* __cdecl FUN_00ec85e3();
extern "C" char* __cdecl FUN_00ecdb42(int e);
inline void Dead8()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
}
struct FUN_0044a4c0
{
    int aBuf[7];
    FUN_0044a4c0(const char* s);
    ~FUN_0044a4c0()
    {
        Dead8();
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool b, unsigned n);
};
FUN_0044a4c0 __cdecl TESObject_ConcatenateStrings(const FUN_0044a4c0& l, const char* r);
FUN_0044a4c0 __cdecl Object_ProcessAndReturnValue_00ad42e0(const FUN_0044a4c0& l, const FUN_0044a4c0& r);
struct FUN_00b096a0
{
    int iBase;
    FUN_00b096a0(const FUN_0044a4c0& s);
    virtual ~FUN_00b096a0();
};
struct FUN_00b09480 : FUN_00b096a0
{
    FUN_00b09480(const FUN_0044a4c0& msg, bool bErrno);
    virtual ~FUN_00b09480();
};
// @fnv 0x00b09480
FUN_00b09480::FUN_00b09480(const FUN_0044a4c0& msg, bool bErrno)
    : FUN_00b096a0(TESObject_ConcatenateStrings(Object_ProcessAndReturnValue_00ad42e0(TESObject_ConcatenateStrings(msg, " ["),
                                             bErrno ? FUN_0044a4c0(FUN_00ecdb42(*FUN_00ec85e3())) : FUN_0044a4c0("")),
                                "]"))
{}

void FUN_00ec7c56();

struct MyVector
{
    int unk00, unk04, unk08;
    int* _Myfirst;
    int* _Mylast;
    int* _Myend;

    inline bool empty() const
    {
        return (_Mylast - _Myfirst) == 0;
    }

    inline int* operator[](unsigned int idx)
    {
        if ((_Mylast - _Myfirst) <= idx)
        {
            FUN_00ec7c56();
        }
        do
        {
        } while (0);
        return &_Myfirst[idx];
    }
};

struct MyClass
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    MyVector m_vec;

    int* CIndexedGeometry_GetVertexColors();
};

// @fnv 0x00b0b4b0
// src: COMMUNITY 0x00b0b4b0
int* MyClass::CIndexedGeometry_GetVertexColors()
{
    return m_vec.empty() ? 0 : m_vec[0];
}

void FUN_00ec7c56();

namespace std {
template <typename T> class vector
{
  public:
    void* m00;
    void* m04;
    void* m08;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;

    inline bool empty() const
    {
        return size() == 0;
    }

    inline unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }

    inline T& operator[](unsigned int i)
    {
        if (size() <= i)
        {
            FUN_00ec7c56();
        }
        do
        {
        } while (0);
        return _Myfirst[i];
    }
};
}

struct FUN_00b0b830_Class
{
    void* m_000;
    void* m_004;
    void* m_008;
    void* m_00c;
    void* m_010;
    void* m_014;
    void* m_018;
    void* m_01c;
    void* m_020;
    void* m_024;
    void* m_028;
    void* m_02c;
    void* m_030;
    void* m_034;
    void* m_038;
    void* m_03c;
    void* m_040;
    void* m_044;
    void* m_048;
    void* m_04c;
    void* m_050;
    void* m_054;
    void* m_058;
    void* m_05c;
    void* m_060;
    void* m_064;
    void* m_068;
    void* m_06c;
    void* m_070;
    void* m_074;
    void* m_078;
    void* m_07c;
    void* m_080;
    void* m_084;
    void* m_088;
    void* m_08c;
    void* m_090;
    void* m_094;
    void* m_098;
    void* m_09c;
    void* m_0a0;
    void* m_0a4;
    void* m_0a8;
    void* m_0ac;
    void* m_0b0;
    void* m_0b4;
    void* m_0b8;
    void* m_0bc;
    void* m_0c0;
    void* m_0c4;
    void* m_0c8;
    void* m_0cc;
    void* m_0d0;
    void* m_0d4;
    void* m_0d8;
    void* m_0dc;
    void* m_0e0;
    void* m_0e4;
    void* m_0e8;
    void* m_0ec;
    void* m_0f0;
    void* m_0f4;
    void* m_0f8;
    void* m_0fc;
    void* m_100;
    void* m_104;
    void* m_108;
    void* m_10c;
    void* m_110;
    void* m_114;
    void* m_118;
    void* m_11c;
    void* m_120;
    void* m_124;
    void* m_128;
    void* m_12c;
    void* m_130;
    void* m_134;
    void* m_138;
    void* m_13c;
    void* m_140;
    void* m_144;
    void* m_148;
    void* m_14c;
    void* m_150;
    void* m_154;
    void* m_158;
    void* m_15c;

    std::vector<float> m_vec;

    float* CIndexedGeometry_GetVertexWindWeights();
};

// @fnv 0x00b0b830
// src: COMMUNITY 0x00b0b830
float* FUN_00b0b830_Class::CIndexedGeometry_GetVertexWindWeights()
{
    return m_vec.empty() ? 0 : &m_vec[0];
}

extern MemoryManager DAT_011f6238;
inline void* operator new(unsigned int n)
{
    return DAT_011f6238.Allocate(n);
}
inline void* operator new[](unsigned int n)
{
    return DAT_011f6238.Allocate(n);
}
inline void operator delete(void* p)
{
    DAT_011f6238.Deallocate(p);
}
inline void operator delete[](void* p)
{
    DAT_011f6238.Deallocate(p);
}
struct CritSecQ
{
    int a, b, c, d, e, f;
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CritSecQ*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CritSecQ*);
extern CritSecQ DAT_011f8bc4;
struct InstListQ
{
    void std_vector_push_back(void* const& v);
};
extern InstListQ DAT_011f8bdc;
extern int DAT_011f8b7c;
extern void* DAT_011f8bf8;
struct StrQ : std::basic_string<char, std::char_traits<char>, std::allocator<char> >
{
    int al;
    union
    {
        char buf[16];
        char* ptr;
    } bx;
    unsigned int size, res;
    const char* c_str() const
    {
        return 16 <= res ? bx.ptr : bx.buf;
    }
    ~StrQ()
    {
        _Tidy(true, 0);
    }
};
StrQ __cdecl IdvFormatString(const char* fmt, ...);
inline void SetCurQ(void* p)
{
    int pad[24];
    DAT_011f8bf8 = p;
}
inline void Dead5Q()
{
    int pad[5];
}
struct ExcQ
{
    virtual ~ExcQ();
    virtual const char* what() const;
};
struct O44
{
    char d[0x44];
    O44();
};
struct O190
{
    char d[0x190];
    O190(void* p, int f);
};
struct O128
{
    char d[0x128];
    O128(void* p);
};
struct Ob0
{
    char d[0xb0];
    Ob0();
};
struct O30
{
    char d[0x30];
    O30(void* p);
};
struct O34
{
    char d[0x34];
    O34();
};
struct O18
{
    int d[6];
    void FUN_00b0dce0();
    O18()
    {
        FUN_00b0dce0();
    }
};
struct O84
{
    char d[0x84];
    O84();
};
struct FUN_00b02ef0
{
    O128* m00;
    O190* m04;
    O30* m08;
    Ob0* m0c;
    O44* m10;
    O34* m14;
    int m18;
    float m1c, m20, m24, m28;
    int m2c;
    int* m30;
    int m34;
    O18* m38;
    int m3c;
    float* m40;
    char m44;
    char m45;
    int m48;
    int m4c;
    int m50;
    unsigned short m54;
    int m58;
    O84* m5c;
    O190* m60;
    unsigned short m64;
    int m68;
    char m6c;
    char m6d;
    float m70[12];
    FUN_00b02ef0();
};
// @fnv 0x00b02ef0
FUN_00b02ef0::FUN_00b02ef0()
    : m00(0), m04(0), m08(0), m0c(0), m10(0), m14(0), m18(1), m1c(0.07f), m20(0.7f), m24(0.5f), m28(0.0f), m2c(0),
      m30(0), m34(0), m3c(-1), m40(0), m44('T'), m45(0), m48(-1), m4c(0), m50(0), m54(0), m58(0), m5c(0), m64(0),
      m68(0), m6c(0), m6d(0)
{
    try
    {
        m10 = new O44;
        m04 = new O190(m10, 0);
        m00 = new O128(m04);
        m0c = new Ob0;
        m08 = new O30(m10);
        m14 = new O34;
        m40 = new float[7];
        m30 = new int;
        *m30 = 1;
        m38 = new O18;
        m5c = new O84;
        m60 = new O190(m10, 1);
        EnterCriticalSection(&DAT_011f8bc4);
        DAT_011f8bdc.std_vector_push_back(this);
        DAT_011f8b7c++;
        LeaveCriticalSection(&DAT_011f8bc4);
        SetCurQ(m0c);
        m40[0] = 0.0f;
        m40[1] = 0.0f;
        m40[2] = 0.0f;
        m40[3] = 1.0f;
        m40[4] = 1.0f;
        m40[5] = 1.0f;
        m40[6] = 1.0f;
        for (int i = 0; i < 12; i++)
            m70[i] = 0.0f;
    }
    catch (ExcQ& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::CSpeedTreeRT( )", e.what()).c_str());
        Dead5Q();
    }
    catch (...)
    {
        AssignString(IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::CSpeedTreeRT( )").c_str());
        Dead5Q();
    }
}

namespace fnv_00b044a0 {
inline void Dead1()
{
    int aiQ[1];
}
inline void Dead2()
{
    int aiQ[2];
}
inline void Dead21()
{
    int aiQ[21];
}
struct StrF
{
    int iAl;
    union
    {
        char acBuf[16];
        char* pPtr;
    } kBx;
    unsigned uiSize;
    unsigned uiRes;
    ~StrF()
    {
        int aiD[4];
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool b, unsigned n);
    const char* c_str() const
    {
        return 16 <= uiRes ? kBx.pPtr : kBx.acBuf;
    }
};
StrF __cdecl IdvFormatString(const char* pFmt, ...);
void __cdecl AssignString(const char* s);
void* __cdecl FUN_00ec44d0(void*, const void*, unsigned);
namespace std {
class exception
{
  public:
    exception(const char* const& p);
    virtual ~exception();
    virtual const char* what() const;
    const char* w;
    int f;
};
}
struct BVecQ
{
    float x, y, z;
    int pad[3];
    ~BVecQ();
};
struct BoxQ
{
    BVecQ min;
    BVecQ max;
    BoxQ();
};
struct V3Q
{
    float x, y, z;
    V3Q(float fx, float fy)
    {
        x = fx;
        y = fy;
        z = 0.0f;
    }
};
struct V3B
{
    float x, y, z;
    float CVec3_Distance(const V3Q& v) const;
    float Dist(const V3Q& v) const
    {
        Dead2();
        return CVec3_Distance(v);
    }
};
inline void CopyV(V3Q& d, const BVecQ& s)
{
    FUN_00ec44d0(&d, &s, 0xc);
}
struct ExtQ
{
    V3Q min;
    V3Q max;
    float f18;
};
struct MatQ
{
    float m[16];
    MatQ()
    {
        FUN_00b3ccb0();
    }
    void FUN_00b3ccb0();
};
struct LeafVQ
{
    int m0, m4, m8;
    char* first;
    char* last;
    unsigned size() const
    {
        return (last - first) / 0x54;
    }
};
struct O94Q
{
    void Init(unsigned n);
};
struct TreeCQ
{
    int a[0x94 / 4];
    O94Q o94;
    int b[(0xa4 - 0x98) / 4];
    LeafVQ leaves;
    int c[(0xd8 - 0xb8) / 4];
    int iD8;
    int d[(0xec - 0xdc) / 4];
    int mEC;
    int e[(0x10c - 0xf0) / 4];
    int o10c;
    O94Q* GetO94()
    {
        return &o94;
    }
    int GetEC()
    {
        return mEC;
    }
    int GetD8()
    {
        return iD8;
    }
    void InitSeed(int);
    void CTreeEngine_Compute(float);
};
struct GeoQ
{
    void CIndexedGeometry_CombineStrips(int);
    void CIndexedGeometry_Transform(const MatQ&);
    void CIndexedGeometry_ComputeExtents(BoxQ&);
    unsigned short pad[16];
    unsigned short w20;
    unsigned short GetW20()
    {
        return w20;
    }
};
struct BrQ
{
    void CLeafGeometry_Init(unsigned short, int, O94Q*);
    void SetLeafTableEntry(int, int*);
    void ProcessEntries_00b28280(const MatQ&);
    void CLeafGeometry_ComputeExtents(BoxQ&);
};
struct Cfg0cQ
{
    int a[14];
    int m38;
    int Get38()
    {
        return m38;
    }
};
struct M10Q
{
    void SetFromSource(int*);
};
struct El20
{
    int a[8];
};
struct M4cQ
{
    int n0;
    int* p4;
    int a[2];
    int n10;
    int* p14;
};
struct M58Q
{
    void SCollisionObjects_TransformAll(const MatQ&);
};
struct M5cQ
{
    void CFrondEngine_Compute(GeoQ*, Cfg0cQ*);
    void CFrondEngine_SetTextureCoords(GeoQ*, int, int*, unsigned char);
};
extern unsigned char DAT_011f8b79;
extern M5cQ* DAT_011f8c00;
struct SpdCompQ
{
    TreeCQ* m_p0;
    GeoQ* m_p4;
    BrQ* m_p8;
    Cfg0cQ* m_pC;
    M10Q* m_p10;
    int a[4];
    float m_f24;
    int b[6];
    ExtQ* m_p40;
    char c[1];
    bool m_b45;
    char d[2];
    char e[4];
    M4cQ* m_p4c;
    void* m_p50;
    int f;
    M58Q* m_p58;
    M5cQ* m_p5c;
    GeoQ* m_p60;
    unsigned short m_w64;
    void ComputeLeafStaticLighting();
    void CSpeedTreeRT_ComputeSelfShadowTexCoords();
    void InitBoundingBoxCorners();
    bool CSpeedTreeRT_Compute(const float* pTransform, int nSeed, bool bStrips);
};
inline void SetCur(M5cQ* p)
{
    DAT_011f8c00 = p;
}
inline void InitLeaves(TreeCQ* t)
{
    t->o94.Init(t->leaves.size());
}
inline void InitBr(BrQ* b, O94Q* o, int ec, unsigned short d8)
{
    b->CLeafGeometry_Init(d8, ec, o);
}
// @fnv 0x00b044a0
// src: EXE 0x00b044a0
bool SpdCompQ::CSpeedTreeRT_Compute(const float* pTransform, int nSeed, bool bStrips)
{
    try
    {
        if (!m_b45)
        {
            SetCur(m_p5c);
            m_p0->InitSeed(nSeed);
            m_p0->CTreeEngine_Compute(m_f24);
            m_p5c->CFrondEngine_Compute(m_p60, m_pC);
            m_w64 = m_p60->GetW20();
            InitLeaves(m_p0);
            if (m_pC->Get38() == 1)
                ComputeLeafStaticLighting();
            int* p10c_iipp = &m_p0->o10c;
            m_p10->SetFromSource(p10c_iipp);
            m_p8->CLeafGeometry_Init(m_p0->GetD8(), m_p0->GetEC(), m_p0->GetO94());
            if (m_p4c)
            {
                for (int i = 0; i < m_p4c->n0; ++i)
                    m_p8->SetLeafTableEntry(i, &m_p4c->p4[i * 8]);
                for (int j = 0; j < m_p4c->n10; ++j)
                    m_p5c->CFrondEngine_SetTextureCoords(m_p60, j, &m_p4c->p14[j * 8], DAT_011f8b79);
            }
            if (bStrips)
            {
                m_p4->CIndexedGeometry_CombineStrips(0);
                m_p60->CIndexedGeometry_CombineStrips(0);
            }
            if (pTransform)
            {
                MatQ mat;
                FUN_00ec44d0(&mat, pTransform, 0x40);
                m_p4->CIndexedGeometry_Transform(mat);
                m_p8->ProcessEntries_00b28280(mat);
                m_p60->CIndexedGeometry_Transform(mat);
                if (m_p58)
                    m_p58->SCollisionObjects_TransformAll(mat);
            }
            BoxQ box_pktk;
            m_p4->CIndexedGeometry_ComputeExtents(box_pktk);
            m_p8->CLeafGeometry_ComputeExtents(box_pktk);
            m_p60->CIndexedGeometry_ComputeExtents(box_pktk);
            Dead21();
            CopyV(m_p40->min, box_pktk.min);
            CopyV(m_p40->max, box_pktk.max);
            V3B center_nrc;
            center_nrc.x = 0.0f;
            center_nrc.y = 0.0f;
            center_nrc.z = 0.0f;
            float fMax_jdjgrg;
            fMax_jdjgrg = center_nrc.Dist(V3Q(m_p40->min.x, m_p40->min.y));
            fMax_jdjgrg = ((fMax_jdjgrg) > (center_nrc.Dist(V3Q(m_p40->min.x, m_p40->max.y))))
                              ? (fMax_jdjgrg)
                              : (center_nrc.Dist(V3Q(m_p40->min.x, m_p40->max.y)));
            fMax_jdjgrg = ((fMax_jdjgrg) > (center_nrc.Dist(V3Q(m_p40->max.x, m_p40->min.y))))
                              ? (fMax_jdjgrg)
                              : (center_nrc.Dist(V3Q(m_p40->max.x, m_p40->min.y)));
            fMax_jdjgrg = ((fMax_jdjgrg) > (center_nrc.Dist(V3Q(m_p40->max.x, m_p40->max.y))))
                              ? (fMax_jdjgrg)
                              : (center_nrc.Dist(V3Q(m_p40->max.x, m_p40->max.y)));
            m_p40->f18 = fMax_jdjgrg * 2.0f;
            if (m_p50)
                CSpeedTreeRT_ComputeSelfShadowTexCoords();
            InitBoundingBoxCorners();
            m_b45 = true;
        }
        else
        {
            AssignString("Compute() called more than once for single tree model (ignored)");
        }
    }
    catch (std::exception& exc)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::Compute", exc.what()).c_str());
    }
    catch (...)
    {
        AssignString(IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::Compute").c_str());
        Dead1();
    }
    return m_b45;
}
}  // namespace fnv_00b044a0

struct CharAllocB05130
{
    CharAllocB05130()
    {}
    CharAllocB05130(const CharAllocB05130&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB05130
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB05130
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB05130(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB05130)
{
    return CharTraitsB05130::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB05130 CharTraitsCatB05130()
{
    SecureTagB05130 kTag;
    return kTag;
}
inline char* CopySB05130(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB05130(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB05130());
}
struct TraitsB05130
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB05130
{
    StringValB05130(CharAllocB05130 kAl = CharAllocB05130()) : m_kAlval(kAl)
    {}
    CharAllocB05130 m_kAlval;
};
struct StringB05130 : public StringValB05130
{
    StringB05130()
    {
        Tidy();
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB05130::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB05130(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
struct FUN_00b05130
{
    FUN_00b05130();
    int m_iValue00;
    int m_iValue04;
    int m_iValue08;
    int m_iValue0C;
    int m_iValue10;
    int m_iValue14;
    StringB05130 m_kName;
    float m_fValue34;
    float m_fValue38;
    float m_fValue3C;
    float m_fValue40;
    float m_fValue44;
    float m_fValue48;
    float m_fValue4C;
    float m_fValue50;
};

// @fnv 0x00b05130
FUN_00b05130::FUN_00b05130() : m_iValue00(0), m_iValue04(0), m_iValue08(0), m_iValue0C(0), m_iValue10(0), m_iValue14(0)
{
    m_fValue34 = 1.0f;
    m_fValue38 = 1.0f;
    m_fValue3C = 0.0f;
    m_fValue40 = 1.0f;
    m_fValue44 = 0.0f;
    m_fValue48 = 0.0f;
    m_fValue4C = 1.0f;
    m_fValue50 = 0.0f;
}

namespace fnv_00b05210 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}
struct CharAllocB05210
{
    CharAllocB05210()
    {}
    CharAllocB05210(const CharAllocB05210&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB05210
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB05210
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB05210(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB05210)
{
    return CharTraitsB05210::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB05210 CharTraitsCatB05210()
{
    SecureTagB05210 kTag;
    return kTag;
}
inline char* CopySB05210(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB05210(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB05210());
}
struct TraitsB05210
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB05210
{
    StringValB05210(CharAllocB05210 kAl = CharAllocB05210()) : m_kAlval(kAl)
    {}
    CharAllocB05210 m_kAlval;
};
struct StringB05210 : public StringValB05210
{
    StringB05210()
    {
        Tidy();
    }
    ~StringB05210()
    {
        Tidy(true, 0);
    }
    const char* c_str() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB05210::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB05210(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
StringB05210 __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcMessage);
extern MemoryManager g_kMemoryB05210;
struct SpeedTreeRTB05210
{
    static void* operator new(unsigned int uiSize)
    {
        return g_kMemoryB05210.Allocate(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        g_kMemoryB05210.Deallocate(pvMem);
    }
    SpeedTreeRTB05210(const SpeedTreeRTB05210* pOriginal);
    SpeedTreeRTB05210* CSpeedTreeRT_MakeInstance();
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
    int unk98;
    int unk9C;
};

// @fnv 0x00b05210
// src: EXE 0x00b05210
SpeedTreeRTB05210* SpeedTreeRTB05210::CSpeedTreeRT_MakeInstance()
{
    SpeedTreeRTB05210* pInstance = 0;
    try
    {
        pInstance = new SpeedTreeRTB05210(this);
    }
    catch (std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::MakeInstance", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::MakeInstance").c_str());
    }
    return pInstance;
}
}  // namespace fnv_00b05210

namespace fnv_00b05420 {
int __cdecl FUN_00ec7c66(void*, unsigned, const void*, unsigned);
// src: COMMUNITY 0x0044e440
inline char* __cdecl std_char_traits_char_Copy_s(char* d, unsigned z, const char* s, unsigned n)
{
    FUN_00ec7c66(d, z, s, n);
    return d;
}
struct StringCopyTag
{
};
// src: COMMUNITY 0x0065e750
inline StringCopyTag __cdecl std_Move_cat_unsigned_char()
{
    StringCopyTag tag;
    return tag;
}
char* __cdecl std_char_traits_char_Copy_s(char*, unsigned, const char*, unsigned);
// src: COMMUNITY 0x0044e420
inline char* __cdecl std_Traits_helper_copy_s_std_char_traits_char_0044e420(char* d, unsigned z, const char* s, unsigned n, StringCopyTag)
{
    return std_char_traits_char_Copy_s(d, z, s, n);
}
// src: COMMUNITY 0x0044ccd0
inline char* __cdecl std_Traits_helper_copy_s_std_char_traits_char(char* d, unsigned z, const char* s, unsigned n)
{
    return std_Traits_helper_copy_s_std_char_traits_char_0044e420(d, z, s, n, std_Move_cat_unsigned_char());
}

struct StrF
{
    int iAl;
    union
    {
        char acBuf[16];
        char* pPtr;
    } kBx;
    unsigned uiSize;
    unsigned uiRes;
    ~StrF()
    {
        fopen_0044a730(true, 0);
    }
// src: XBOX_PDB 0x0044a730
    void fopen_0044a730(bool b, unsigned n)
    {
        if (!b)
        {
        }
        else if (16 <= uiRes)
        {
            char* p = kBx.pPtr;
            if (0 < n)
                std_Traits_helper_copy_s_std_char_traits_char(kBx.acBuf, 16, p, n);
            FUN_0064df10(p, uiRes + 1);
        }
        uiRes = 15;
        ResizeString(n);
    }
    void FUN_0064df10(void* p, unsigned)
    {
        ::operator delete(p);
    }
    void ResizeString(unsigned n)
    {
        char zero = 0;
        uiSize = n;
        std_char_traits_char_assign(Myptr() + n, &zero);
    }
// src: COMMUNITY 0x0044a8c0
    static void std_char_traits_char_assign(char* d, const char* s)
    {
        *d = *s;
    }
    char* Myptr()
    {
        return 16 <= uiRes ? kBx.pPtr : kBx.acBuf;
    }
    const char* c_str() const
    {
        return 16 <= uiRes ? kBx.pPtr : kBx.acBuf;
    }
};
StrF __cdecl IdvFormatString(const char* pFmt, ...);
void __cdecl AssignString(const char* s);
extern "C" int* __cdecl FUN_00ec85e3();
extern "C" char* __cdecl FUN_00ecdb42(int);
void __stdcall FUN_00ec7894(void* p, void* t);
extern char DAT_0116f904;
struct CIdvException
{
    virtual ~CIdvException();
    virtual const char* what() const;
};
namespace std {
class exception
{
  public:
    exception(const char* const& p);
    virtual ~exception();
    virtual const char* what() const;
    const char* w;
    int f;
};
}
struct TreeFileQ
{
    virtual ~TreeFileQ();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual int GetLength();
    unsigned position;
    unsigned(__cdecl* pRead)(TreeFileQ*, void*, unsigned, unsigned*, unsigned);
    unsigned Read(void* p, unsigned n)
    {
        unsigned mode_c = 1;
        unsigned res_l;
        unsigned r_odw = pRead(this, p, n, &mode_c, 1);
        position += r_odw;
        res_l = r_odw;
        return res_l;
    }
};
TreeFileQ* __cdecl FUN_00afdf20(const char*, int, int, int);
struct TreeHeapQ
{
    char* Game_DoHeapAlloc(unsigned);
    void MemoryManager_Deallocate(void*);
};
extern TreeHeapQ DAT_011f6238;
inline void* operator new[](unsigned n)
{
    return DAT_011f6238.Game_DoHeapAlloc(n);
}
inline void operator delete[](void* p)
{
    DAT_011f6238.MemoryManager_Deallocate(p);
}
struct SpdLoadQ
{
    bool CSpeedTreeRT_LoadTree_00b059e0(const char*, int);
    bool CSpeedTreeRT_LoadTree(const char*);
};
// @fnv 0x00b05420
// src: EXE 0x00b05420
bool SpdLoadQ::CSpeedTreeRT_LoadTree(const char* path)
{
    bool bOk_dt = false;
    char* contents_lmol = 0;
    TreeFileQ* file_cswij = 0;

    try
    {
        if (path)
        {
            file_cswij = FUN_00afdf20(path, 0, 0x2800, 1);
            if (file_cswij)
            {
                int length = file_cswij->GetLength();
                int a = 0;
                if (length > 0 && a >= 0)
                {
                    contents_lmol = new char[length];
                    int count = file_cswij->Read(contents_lmol, length);
                    if (count == length)
                    {
                        bOk_dt = CSpeedTreeRT_LoadTree_00b059e0(contents_lmol, length);
                        delete[] contents_lmol;
                        contents_lmol = 0;
                    }
                    else
                    {
                        throw std::exception(IdvFormatString("only read %d of %d from %s [%s]", count, length, path,
                                                          FUN_00ecdb42(*FUN_00ec85e3()))
                                                 .c_str());
                    }
                    delete file_cswij;
                    file_cswij = 0;
                }
                else
                {
                    throw std::exception(
                        IdvFormatString("file seek failed on '%s' [%s]", path, FUN_00ecdb42(*FUN_00ec85e3())).c_str());
                }
            }
            else
            {
                throw std::exception(
                    IdvFormatString("failed to load file '%s' [%s]", path, FUN_00ecdb42(*FUN_00ec85e3())).c_str());
            }
        }
    }
    catch (std::exception& e_jzu)
    {
        if (file_cswij)
        {
            delete file_cswij;
            file_cswij = 0;
        }
        contents_lmol = 0;
        AssignString(IdvFormatString("CSpeedTreeRT::Load Tree - %s", e_jzu.what()).c_str());
    }
    catch (...)
    {
        if (file_cswij)
        {
            delete file_cswij;
            file_cswij = 0;
        }
        contents_lmol = 0;
        AssignString(IdvFormatString("CSpeedTreeRT::LoadTree - threw an unknown system exception").c_str());
    }
    return bOk_dt;
}
}  // namespace fnv_00b05420

namespace fnv_00b059e0 {
// src: COMMUNITY 0x0044a8c0
inline void __cdecl std_char_traits_char_assign(char& destination, const char& source)
{
    destination = source;
}

void __cdecl FUN_00ec7c56();
void __cdecl operator delete(void*);
struct Alloc59;

struct Global59
{
    void MemoryManager_Deallocate(int allocation);
};
extern Global59 DAT_011f6238;
struct Proxy59
{
    __forceinline ~Proxy59()
    {}
};
struct AuxBase59
{
    Proxy59* a;
    __forceinline ~AuxBase59()
    {}
};
struct Alloc59
{
    int state;
    __forceinline void deallocate(Proxy59* allocation, unsigned int count)
    {
        DAT_011f6238.MemoryManager_Deallocate((int)allocation);
    }
};
struct ScalarTag59
{
};
inline ScalarTag59 pointerCategory(char* const&, char* const&)
{
    return ScalarTag59();
}
inline void destroyScalarRange(char*, char*, Alloc59&, ScalarTag59)
{}
inline void CallInterfaceWithResult(char* first, char* last, Alloc59& allocator)
{
    destroyScalarRange(first, last, allocator, pointerCategory(first, last));
}
struct AuxOwner59 : AuxBase59
{
    Alloc59 b;
    __forceinline ~AuxOwner59()
    {
        b.deallocate(a, 1);
    }
};
struct VectorValue59 : AuxOwner59
{
    Alloc59 c;
    __forceinline ~VectorValue59()
    {}
};
struct Inner59 : VectorValue59
{
    char* d;
    char* e;
    char* f;
    void ProcessState_00b0e200(int, unsigned char);
    void destroyRange(char* first, char* last)
    {
        CallInterfaceWithResult(first, last, c);
    }
    void deallocateChars(char* allocation, unsigned int count)
    {
        operator delete(allocation);
    }
// src: GUESS 0x00657f60 (confidence: medium)
    void ReleaseStorage_00657f60()
    {
        if (d != 0)
        {
            destroyRange(d, e);
            deallocateChars(d, f - d);
        }
        d = 0;
        e = 0;
        f = 0;
    }
    __forceinline unsigned int size() const
    {
        return e - d;
    }
    char& at(unsigned int index)
    {
        if (index >= size())
            FUN_00ec7c56();
        return d[index];
    }
    __forceinline ~Inner59()
    {
        ReleaseStorage_00657f60();
    }
};
extern unsigned char DAT_011f8c04;
__forceinline void setFlag(unsigned char value)
{
    DAT_011f8c04 = value;
}
extern unsigned short DAT_011f8d84;
extern float DAT_01016248;

struct FUN_00b06090
{
    unsigned int m_pos;
    Inner59 m_in;
    FUN_00b06090(int p1, int p2) : m_pos(0)
    {
        m_in.ProcessState_00b0e200(p2, 0);
        for (int index = 0; index < p2; ++index)
        {
            if ((unsigned int)index >= (unsigned int)(m_in.e - m_in.d))
                FUN_00ec7c56();
            m_in.d[index] = ((const char*)p1)[index];
        }
    }
    int GetNextElement();
    float CTreeFileAccess_ParseFloat();
// src: GUESS 0x00b06180 (confidence: low)
    bool ProcessAndTransformResult_00b06180()
    {
        return m_in.at(m_pos++) != 0;
    }
    __forceinline bool atEnd() const
    {
        return m_pos >= m_in.size();
    }
    __forceinline ~FUN_00b06090()
    {}
};
struct Sub0
{
    int unk00;
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
    int unk6c;
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
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int f108;
    __forceinline int count() const
    {
        return f108;
    }
    bool Parse_00b2b550(FUN_00b06090* r);
    void ParseTextureControls(FUN_00b06090* r);
    void ParseFlareInfo(FUN_00b06090* r);
    void CTreeEngine_ParseFlareSeed(FUN_00b06090* r);
};
struct SubC
{
    int m_00;
    __forceinline int first() const
    {
        return m_00;
    }
    __forceinline int second() const
    {
        return f38;
    }
    __forceinline int third() const
    {
        return f78;
    }
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
    int f38;
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
    int unk6c;
    int unk70;
    int unk74;
    int f78;
    void CLightingEngine_Parse(FUN_00b06090* r);
};
struct Sub5c
{
    void CFrondEngine_Parse(FUN_00b06090* r);
    int CFrondEngine_GetLevel();
};
struct Sub10
{
    int unk00;
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
    float f3c;
    float f40;
    __forceinline void setFirst(float value)
    {
        f3c = value;
    }
    __forceinline void setSecond(float value)
    {
        f40 = value;
    }
    void SetMatrixRange(int a, unsigned short b);
};
struct Tree59
{
    Sub0* m_p00;
    int unk04;
    int unk08;
    SubC* m_p0c;
    Sub10* m_p10;
    int unk14;
    int m_18;
    int unk1c;
    int unk20;
    int unk24;
    float m_28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int m_3c;
    int unk40;
    int unk44;
    int m_48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    Sub5c* m_p5c;
    bool CSpeedTreeRT_LoadTree_00b059e0(int p1, int p2);
    __forceinline SubC* engine()
    {
        return m_p0c;
    }
    void CSpeedTreeRT_ParseLodInfo(FUN_00b06090* r);
    void CSpeedTreeRT_ParseWindInfo(FUN_00b06090* r);
    void CSpeedTreeRT_ParseTextureCoordInfo(FUN_00b06090* r);
    void CSpeedTreeRT_ParseCollisionObjects(FUN_00b06090* r);
    void CSpeedTreeRT_ParseShadowProjectionInfo(FUN_00b06090* r);
    void CSpeedTreeRT_ParseUserData(FUN_00b06090* r);
    void CSpeedTreeRT_ParseSupplementalTexCoordInfo(FUN_00b06090* r);
    void CSpeedTreeRT_SetBranchLightingMethod(int x);
    void CSpeedTreeRT_SetLeafLightingMethod(int x);
    void CSpeedTreeRT_SetFrondLightingMethod(int x);
};
struct Exc59
{
    virtual void pad0();
    virtual const char* Msg();
};
struct TraitsTag59
{
};
inline TraitsTag59 traitsCategory()
{
    TraitsTag59 category;
    return category;
}
int __cdecl FUN_00ec7c66(void*, unsigned int, const void*, unsigned int);
// src: COMMUNITY 0x0044e440
inline char* __cdecl std_char_traits_char_Copy_s(char* destination, unsigned int capacity, const char* source, unsigned int count)
{
    FUN_00ec7c66(destination, capacity, source, count);
    return destination;
}
// src: COMMUNITY 0x0044e420
inline char* __cdecl std_Traits_helper_copy_s_std_char_traits_char_0044e420(char* destination, unsigned int capacity, const char* source, unsigned int count,
                                  TraitsTag59)
{
    return std_char_traits_char_Copy_s(destination, capacity, source, count);
}
// src: COMMUNITY 0x0044ccd0
inline char* std_Traits_helper_copy_s_std_char_traits_char(char* destination, unsigned int capacity, const char* source, unsigned int count)
{
    return std_Traits_helper_copy_s_std_char_traits_char_0044e420(destination, capacity, source, count, traitsCategory());
}
struct CharAllocator59
{
    int state;
    void deallocate(char* allocation, unsigned int count)
    {
        ::operator delete(allocation);
    }
};
struct Str59
{
    CharAllocator59 allocator;
    char buf[16];
    unsigned int size;
    unsigned int res;
    void deallocateChars(char* allocation, unsigned int count)
    {
        operator delete(allocation);
    }
// src: COMMUNITY 0x0044a970
    char* std_string__Myptr()
    {
        return res >= 16 ? *(char**)buf : buf;
    }
    void ResizeString(unsigned int newSize)
    {
        std_char_traits_char_assign(std_string__Myptr()[size = newSize], char());
    }
// src: XBOX_PDB 0x0044a730
    void fopen_0044a730(bool built, unsigned int newSize)
    {
        if (!built)
        {
        }
        else if (res >= 16)
        {
            char* allocation = *(char**)buf;
            if (newSize > 0)
                std_Traits_helper_copy_s_std_char_traits_char(buf, 16, allocation, newSize);
            allocator.deallocate(allocation, res + 1);
        }
        res = 15;
        ResizeString(newSize);
    }
    __forceinline ~Str59()
    {
        fopen_0044a730(true, 0);
    }
    __forceinline const char* c_str() const
    {
        return res >= 16 ? *(const char**)buf : buf;
    }
    __forceinline operator const char*() const
    {
        return c_str();
    }
};
Str59 __cdecl IdvFormatString(const char* fmt, ...);
void __cdecl AssignString(const char* s);
struct StrCalls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void fopen_0044a730(bool b, unsigned int n);
};

// @fnv 0x00b059e0
// src: EXE 0x00b059e0
bool Tree59::CSpeedTreeRT_LoadTree_00b059e0(int p1, int p2)
{
    bool result5 = false;
    try
    {
        FUN_00b06090 reader8(p1, p2);
        if (m_p00->Parse_00b2b550(&reader8))
        {
            if (!reader8.atEnd())
            {
                bool done4 = false;
                int cur = reader8.GetNextElement();
                do
                {
                    switch (cur)
                    {
                    case 8000:
                        m_p0c->CLightingEngine_Parse(&reader8);
                        break;
                    case 9000:
                        CSpeedTreeRT_ParseLodInfo(&reader8);
                        break;
                    case 11000:
                        CSpeedTreeRT_ParseWindInfo(&reader8);
                        break;
                    case 10000:
                        CSpeedTreeRT_ParseTextureCoordInfo(&reader8);
                        break;
                    case 12000:
                        CSpeedTreeRT_ParseCollisionObjects(&reader8);
                        break;
                    case 13000:
                        m_p5c->CFrondEngine_Parse(&reader8);
                        break;
                    case 15000:
                        m_p00->ParseTextureControls(&reader8);
                        break;
                    case 16000:
                        m_p00->ParseFlareInfo(&reader8);
                        break;
                    case 16013:
                        m_p00->CTreeEngine_ParseFlareSeed(&reader8);
                        break;
                    case 16014: {
                        m_28 = reader8.CTreeFileAccess_ParseFloat();
                        break;
                    }
                    case 18000:
                        CSpeedTreeRT_ParseShadowProjectionInfo(&reader8);
                        break;
                    case 19000:
                        CSpeedTreeRT_ParseUserData(&reader8);
                        break;
                    case 20000:
                        CSpeedTreeRT_ParseSupplementalTexCoordInfo(&reader8);
                        break;
                    case 21000: {
                        m_p10->setFirst(reader8.CTreeFileAccess_ParseFloat());
                        break;
                    }
                    case 21001: {
                        m_p10->setSecond(reader8.CTreeFileAccess_ParseFloat());
                        break;
                    }
                    case 22000: {
                        setFlag(reader8.ProcessAndTransformResult_00b06180());
                        break;
                    }
                    default:
                        done4 = true;
                        break;
                    }
                    {
                        if (reader8.atEnd())
                        {
                            done4 = true;
                        }
                        else
                        {
                            cur = reader8.GetNextElement();
                        }
                    }
                } while (!done4);
            }
            CSpeedTreeRT_SetBranchLightingMethod(engine()->first());
            CSpeedTreeRT_SetLeafLightingMethod(m_p0c->second());
            CSpeedTreeRT_SetFrondLightingMethod(m_p0c->third());
            m_48 = m_p00->count();
            m_3c = m_p5c->CFrondEngine_GetLevel();
            if (m_18 == 2)
            {
                m_18 = 1;
                m_28 = DAT_01016248;
            }
            m_p10->SetMatrixRange(0, DAT_011f8d84);
            result5 = true;
        }
    }
    catch (Exc59& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::LoadTree", e.Msg()));
    }
    catch (...)
    {
        AssignString(IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::LoadTree"));
    }
    return result5;
}
}  // namespace fnv_00b059e0

extern MemoryManager g_kMemoryB061E0;
struct ProxyB061E0
{
    void* m_pkContainer;
};
template <class T> struct AllocatorB061E0
{
    AllocatorB061E0()
    {}
    ~AllocatorB061E0()
    {}
    void deallocate(T* pkPtr, unsigned int)
    {
        g_kMemoryB061E0.Deallocate(pkPtr);
    }
    void destroy(T* pkPtr)
    {
        pkPtr->~T();
    }
};
struct ScalarTagB061E0
{
};
struct NonscalarTagB061E0
{
};
inline ScalarTagB061E0 PtrCatB061E0(char*&, char*&)
{
    ScalarTagB061E0 kCat;
    return kCat;
}
template <class T, class A> inline void DestroyRangeB061E0(T*, T*, A&, ScalarTagB061E0)
{}
template <class T, class A> inline void DestroyRangeB061E0(T* pFirst, T* pLast, A& kAl)
{
    DestroyRangeB061E0(pFirst, pLast, kAl, PtrCatB061E0(pFirst, pLast));
}
struct AuxBaseB061E0
{
    ~AuxBaseB061E0()
    {
        m_kAlAux.destroy(m_pkAux);
        m_kAlAux.deallocate(m_pkAux, 1);
    }
    ProxyB061E0* m_pkAux;
    AllocatorB061E0<ProxyB061E0> m_kAlAux;
};
struct CharBufferStorage : public AuxBaseB061E0
{
    AllocatorB061E0<char> m_kAlval;
    char* m_pcFirst;
    char* m_pcLast;
    char* m_pcEnd;
    void Destroy(char* pcFirst, char* pcLast)
    {
        DestroyRangeB061E0(pcFirst, pcLast, m_kAlval);
    }
    void Tidy()
    {
        if (m_pcFirst != 0)
        {
            Destroy(m_pcFirst, m_pcLast);
            m_kAlval.deallocate(m_pcFirst, m_pcEnd - m_pcFirst);
        }
        m_pcFirst = 0;
        m_pcLast = 0;
        m_pcEnd = 0;
    }
};
// STL-style char container: allocator/proxy state and three buffer pointers, unlike SIMD Vector.
struct OwnedCharBuffer : public CharBufferStorage
{
    ~OwnedCharBuffer()
    {
        Tidy();
    }
};
struct FUN_00b061e0
{
    ~FUN_00b061e0();
    int unk00;
    OwnedCharBuffer m_kBuffer;
};

// @fnv 0x00b061e0
FUN_00b061e0::~FUN_00b061e0()
{}

namespace fnv_00b06280 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}
struct CharAllocB06280
{
    CharAllocB06280()
    {}
    CharAllocB06280(const CharAllocB06280&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB06280
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB06280
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB06280(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB06280)
{
    return CharTraitsB06280::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB06280 CharTraitsCatB06280()
{
    SecureTagB06280 kTag;
    return kTag;
}
inline char* CopySB06280(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB06280(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB06280());
}
struct TraitsB06280
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB06280
{
    StringValB06280(CharAllocB06280 kAl = CharAllocB06280()) : m_kAlval(kAl)
    {}
    CharAllocB06280 m_kAlval;
};
struct StringB06280 : public StringValB06280
{
    StringB06280()
    {
        Tidy();
    }
    ~StringB06280()
    {
        Tidy(true, 0);
    }
    const char* c_str() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB06280::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB06280(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
StringB06280 __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcMessage);
struct EngineB06280
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char unk20;
    bool m_bTransientDataOk;
    char unk22;
    char unk23;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int m_iTreeSize;
    bool TransientDataOk() const
    {
        return m_bTransientDataOk;
    }
    unsigned int GetTreeSize() const
    {
        return m_iTreeSize;
    }
    void SetSize_00b2bd20(float fSize, float fVariance);
};
struct SpeedTreeRTB06280
{
    EngineB06280* m_pFirstPointer;
    void CSpeedTreeRT_SetTreeSize(float fSize, float fVariance);
};

// @fnv 0x00b06280
// src: COMMUNITY 0x00b06280
void SpeedTreeRTB06280::CSpeedTreeRT_SetTreeSize(float fSize, float fVariance)
{
    try
    {
        if (m_pFirstPointer->TransientDataOk())
        {
            if (fSize > 0.0)
                m_pFirstPointer->SetSize_00b2bd20(fSize, fVariance);
            else
                AssignString("SetTreeSize() is only valid for size values greater than 0.0");
        }
        else
        {
            AssignString("SetTreeSize() has no effect after DeleteTransientData() has been called");
        }
    }
    catch (std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::SetTreeSize", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::SetTreeSize").c_str());
    }
}
}  // namespace fnv_00b06280

namespace fnv_00b06440 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}
struct CharAllocB06440
{
    CharAllocB06440()
    {}
    CharAllocB06440(const CharAllocB06440&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB06440
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB06440
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB06440(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB06440)
{
    return CharTraitsB06440::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB06440 CharTraitsCatB06440()
{
    SecureTagB06440 kTag;
    return kTag;
}
inline char* CopySB06440(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB06440(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB06440());
}
struct TraitsB06440
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB06440
{
    StringValB06440(CharAllocB06440 kAl = CharAllocB06440()) : m_kAlval(kAl)
    {}
    CharAllocB06440 m_kAlval;
};
struct StringB06440 : public StringValB06440
{
    StringB06440()
    {
        Tidy();
    }
    ~StringB06440()
    {
        Tidy(true, 0);
    }
    const char* c_str() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB06440::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB06440(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
StringB06440 __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcMessage);
struct EngineB06440
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char unk20;
    bool m_bTransientDataOk;
    char unk22;
    char unk23;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int m_iTreeSize;
    bool TransientDataOk() const
    {
        return m_bTransientDataOk;
    }
    unsigned int GetTreeSize() const
    {
        return m_iTreeSize;
    }
};
struct SpeedTreeRTB06440
{
    EngineB06440* m_pFirstPointer;
    int CSpeedTreeRT_GetSeed();
};

// @fnv 0x00b06440
// src: COMMUNITY 0x00b06440
int SpeedTreeRTB06440::CSpeedTreeRT_GetSeed()
{
    int iResult = 0;
    try
    {
        if (m_pFirstPointer->TransientDataOk())
            iResult = m_pFirstPointer->GetTreeSize();
        else
            AssignString("SetTreeSize() has no effect after DeleteTransientData() has been called");
    }
    catch (std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::SetTreeSize", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::SetTreeSize").c_str());
    }
    return iResult;
}
}  // namespace fnv_00b06440

namespace fnv_00b06660 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}
struct CharAllocB06660
{
    CharAllocB06660()
    {}
    CharAllocB06660(const CharAllocB06660&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB06660
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB06660
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB06660(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB06660)
{
    return CharTraitsB06660::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB06660 CharTraitsCatB06660()
{
    SecureTagB06660 kTag;
    return kTag;
}
inline char* CopySB06660(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB06660(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB06660());
}
struct TraitsB06660
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB06660
{
    StringValB06660(CharAllocB06660 kAl = CharAllocB06660()) : m_kAlval(kAl)
    {}
    CharAllocB06660 m_kAlval;
};
struct StringB06660 : public StringValB06660
{
    StringB06660()
    {
        Tidy();
    }
    ~StringB06660()
    {
        Tidy(true, 0);
    }
    const char* c_str() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB06660::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB06660(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
StringB06660 __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcMessage);
struct EngineB06660
{
    int unk00;
    int unk04;
    char unk08;
    bool m_bStaticLighting;
    void SetStaticLighting(bool bStatic)
    {
        m_bStaticLighting = bStatic;
    }
};
struct LightingB06660
{
    int m_eTransformMethod;
    void SetMethod(int eMethod)
    {
        m_eTransformMethod = eMethod;
    }
};
struct SpeedTreeRTB06660
{
    int unk00;
    EngineB06660* m_pBranchEngine;
    int unk08;
    LightingB06660* m_pBranchLighting;
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
    char unk44;
    bool m_bComputed;
    void CSpeedTreeRT_SetBranchLightingMethod(int eMethod);
};

// @fnv 0x00b06660
// src: EXE 0x00b06660
void SpeedTreeRTB06660::CSpeedTreeRT_SetBranchLightingMethod(int eMethod)
{
    try
    {
        if (!m_bComputed)
        {
            m_pBranchEngine->SetStaticLighting(eMethod == 1);
            m_pBranchLighting->SetMethod(eMethod);
        }
        else
        {
            AssignString("SetBranchLightingMethod() has no effect after Compute() has been called");
        }
    }
    catch (std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::SetBranchLightingMethod", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(
            IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::SetBranchLightingMethod").c_str());
    }
}
}  // namespace fnv_00b06660

namespace fnv_00b06810 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}
struct CharAllocB06810
{
    CharAllocB06810()
    {}
    CharAllocB06810(const CharAllocB06810&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB06810
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB06810
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB06810(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB06810)
{
    return CharTraitsB06810::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB06810 CharTraitsCatB06810()
{
    SecureTagB06810 kTag;
    return kTag;
}
inline char* CopySB06810(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB06810(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB06810());
}
struct TraitsB06810
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB06810
{
    StringValB06810(CharAllocB06810 kAl = CharAllocB06810()) : m_kAlval(kAl)
    {}
    CharAllocB06810 m_kAlval;
};
struct StringB06810 : public StringValB06810
{
    StringB06810()
    {
        Tidy();
    }
    ~StringB06810()
    {
        Tidy(true, 0);
    }
    const char* c_str() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB06810::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB06810(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
StringB06810 __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcMessage);
struct LeafLightingB06810
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
    int m_eTransformMethod;
    void SetMethod(int e)
    {
        m_eTransformMethod = e;
    }
};
struct LeafFlagsB06810
{
    bool m_bIsStatic;
    void SetStatic(bool b)
    {
        m_bIsStatic = b;
    }
};

struct SpeedTreeRTB06810
{
    int unk00;
    int unk04;
    LeafFlagsB06810* m_pLeafFlags;
    LeafLightingB06810* m_pLeafLighting;
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
    char unk44;
    bool m_bComputed;
    void CSpeedTreeRT_SetLeafLightingMethod(int eMethod);
};

// @fnv 0x00b06810
// src: EXE 0x00b06810
void SpeedTreeRTB06810::CSpeedTreeRT_SetLeafLightingMethod(int eMethod)
{
    try
    {
        if (!m_bComputed)
        {
            m_pLeafLighting->SetMethod(eMethod);
            m_pLeafFlags->SetStatic(eMethod == 1);
        }
        else
        {
            AssignString("SetLeafLightingMethod() has no effect after Compute() has been called");
        }
    }
    catch (std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::SetLeafLightingMethod", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(
            IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::SetLeafLightingMethod").c_str());
    }
}
}  // namespace fnv_00b06810

namespace fnv_00b069c0 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}
struct CharAllocB069C0
{
    CharAllocB069C0()
    {}
    CharAllocB069C0(const CharAllocB069C0&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB069C0
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB069C0
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB069C0(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB069C0)
{
    return CharTraitsB069C0::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB069C0 CharTraitsCatB069C0()
{
    SecureTagB069C0 kTag;
    return kTag;
}
inline char* CopySB069C0(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB069C0(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB069C0());
}
struct TraitsB069C0
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB069C0
{
    StringValB069C0(CharAllocB069C0 kAl = CharAllocB069C0()) : m_kAlval(kAl)
    {}
    CharAllocB069C0 m_kAlval;
};
struct StringB069C0 : public StringValB069C0
{
    StringB069C0()
    {
        Tidy();
    }
    ~StringB069C0()
    {
        Tidy(true, 0);
    }
    const char* c_str() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB069C0::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB069C0(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
StringB069C0 __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcMessage);
struct FrondFlagsB069C0
{
    int unk00;
    int unk04;
    char unk08;
    bool m_bStaticLighting;
    void SetStaticLighting(bool b)
    {
        m_bStaticLighting = b;
    }
};
struct FrondLightingB069C0
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
    int m_eTransformMethod;
    void SetMethod(int e)
    {
        m_eTransformMethod = e;
    }
};

struct SpeedTreeRTB069C0
{
    int unk00;
    int unk04;
    int unk08;
    FrondLightingB069C0* m_pFrondLighting;
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
    char unk44;
    bool m_bComputed;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    FrondFlagsB069C0* m_pFrondFlags;
    void CSpeedTreeRT_SetFrondLightingMethod(int eMethod);
};

// @fnv 0x00b069c0
// src: EXE 0x00b069c0
void SpeedTreeRTB069C0::CSpeedTreeRT_SetFrondLightingMethod(int eMethod)
{
    try
    {
        if (!m_bComputed)
        {
            m_pFrondFlags->SetStaticLighting(eMethod == 1);
            m_pFrondLighting->SetMethod(eMethod);
        }
        else
        {
            AssignString("SetFrondLightingMethod() has no effect after Compute() has been called");
        }
    }
    catch (std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::SetFrondLightingMethod", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(
            IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::SetFrondLightingMethod").c_str());
    }
}
}  // namespace fnv_00b069c0

namespace fnv_00b06c10 {
struct V3
{
    float x;
    float y;
    float z;
};
struct StrF
{
    int iAl;
    union
    {
        char acBuf[16];
        char* pPtr;
    } kBx;
    unsigned uiSize;
    unsigned uiRes;
    ~StrF()
    {
        int aiD[5];
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool b, unsigned n);
    const char* c_str() const
    {
        return 16 <= uiRes ? kBx.pPtr : kBx.acBuf;
    }
};
StrF __cdecl IdvFormatString(const char* pFmt, ...);
void __cdecl AssignString(const char* pMsg);
struct CIdvException
{
    virtual ~CIdvException();
    virtual const char* what() const;
};
struct CamV
{
    float x;
    float y;
    float z;
    CamV()
    {
        z = 0.0f;
        y = 0.0f;
        x = 0.0f;
    }
    CamV(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    bool operator!=(const CamV& o) const
    {
        return x != o.x || y != o.y || z != o.z;
    }
};
struct CamR
{
    float v[3];
    CamR()
    {
        v[2] = 0.0f;
        v[1] = 0.0f;
        v[0] = 0.0f;
    }
    CamR& operator=(const CamV& o)
    {
        v[0] = o.x;
        v[1] = o.y;
        v[2] = o.z;
        return *this;
    }
    float& operator[](int i)
    {
        return v[i];
    }
};
extern float DAT_011ad11c;
extern float DAT_011ad120;
extern const float DAT_010a4d88;
extern const float DAT_01023cd8;
void __cdecl CSpeedTreeRT_NotifyAllTreesOfEvent(int i);
void __cdecl FUN_00b27080(const CamV* p);
float __cdecl FUN_00ec9610(double d);
inline float RadToDeg(float fRad)
{
    return fRad * (double)57.29578f;
}
inline float VAsin(float f)
{
    return FUN_00ec9610(f);
}
struct SpdTreeQ
{
    static void __cdecl CSpeedTreeRT_SetCamera(const float* pPos, const float* pDir);
};
// @fnv 0x00b06c10
// src: EXE 0x00b06c10
void __cdecl SpdTreeQ::CSpeedTreeRT_SetCamera(const float* pPos, const float* pDir)
{
    try
    {
        if (pPos && pDir)
        {
            CamV c;
            CamV kOldPos;
            c = *(CamV*)&DAT_011f8e9c;
            kOldPos = *(CamV*)&DAT_011f8eac;
            CamV kPos(pPos[0], pPos[1], pPos[2]);
            CamV kWorldPosition(pDir[0], pDir[1], pDir[2]);
            if (c != kPos || kOldPos != kWorldPosition)
            {
                *(CamV*)&DAT_011f8e9c = kPos;
                *(CamV*)&DAT_011f8eac = kWorldPosition;
                CSpeedTreeRT_NotifyAllTreesOfEvent(1);
                FUN_00b27080(&kWorldPosition);
                CSpeedTreeRT_NotifyAllTreesOfEvent(1);
                CamR x;
                x = kWorldPosition;
                float s;
                float kOldDir;
                s = RadToDeg(VAsin(x[2]));
                kOldDir = 1.0f - (s - DAT_011ad11c) / (DAT_011ad120 - DAT_011ad11c);
                kOldDir = kOldDir < 0.0 ? 0.0f : kOldDir;
                kOldDir = kOldDir > 1.0 ? 1.0f : kOldDir;
                *(float*)&DAT_011ad124 = DAT_010a4d88 + (DAT_01023cd8 - DAT_010a4d88) * kOldDir;
            }
        }
        else
        {
            AssignString("SetCamera() requires non-NULL position and direction values");
        }
    }
    catch (CIdvException& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::SetCamera", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::SetCamera").c_str());
    }
}
}  // namespace fnv_00b06c10

namespace fnv_00b07060 {
extern "C" int __cdecl memcpy_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
namespace stdb07 {
struct _Secure_char_traits_tag
{
};
template <class _Elem> struct char_traits
{
    typedef _Elem char_type;
    typedef _Secure_char_traits_tag _Secure_char_traits;
    static void assign(_Elem& _Left, const _Elem& _Right)
    {
        _Left = _Right;
    }
    static _Elem* _Copy_s(_Elem* _First1, unsigned int _Dest_size, const _Elem* _First2, unsigned int _Count)
    {
        memcpy_s(_First1, _Dest_size, _First2, _Count);
        return _First1;
    }
};
template <class _Traits> struct _Char_traits_category
{
    typedef typename _Traits::_Secure_char_traits _Secure_char_traits;
};
template <class _Traits> inline typename _Char_traits_category<_Traits>::_Secure_char_traits _Char_traits_cat()
{
    typename _Char_traits_category<_Traits>::_Secure_char_traits _Secure;
    return (_Secure);
}
namespace _Traits_helper {
template <class _Traits>
inline typename _Traits::char_type* copy_s(typename _Traits::char_type* _First1, unsigned int _Size,
                                           const typename _Traits::char_type* _First2, unsigned int _Count,
                                           _Secure_char_traits_tag)
{
    return _Traits::_Copy_s(_First1, _Size, _First2, _Count);
}
template <class _Traits>
inline typename _Traits::char_type* copy_s(typename _Traits::char_type* _First1, unsigned int _Size,
                                           const typename _Traits::char_type* _First2, unsigned int _Count)
{
    return copy_s<_Traits>(_First1, _Size, _First2, _Count, _Char_traits_cat<_Traits>());
}
}

void __cdecl operator delete(void*);
template <class _Ty> class allocator
{
  public:
    allocator() throw()
    {}
    allocator(const allocator<_Ty>&) throw()
    {}
    void deallocate(_Ty* _Ptr, unsigned int)
    {
        ::operator delete(_Ptr);
    }
};
template <class _Ty, class _Alloc> class _String_val
{
  protected:
    _String_val(_Alloc _Al = _Alloc()) : _Alval(_Al)
    {}
    _Alloc _Alval;
};
template <class _Elem, class _Traits, class _Ax> class basic_string : public _String_val<_Elem, _Ax>
{
  public:
    basic_string(const basic_string& _Right);
    const _Elem* c_str() const
    {
        return (_Myptr());
    }
    ~basic_string()
    {
        _Tidy(true);
    }
    union
    {
        _Elem _Buf[16];
        _Elem* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;

  protected:
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
            ;
        else if (16 <= _Myres)
        {
            _Elem* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
                _Traits_helper::copy_s<_Traits>(_Bx._Buf, 16, _Ptr, _Newsize);
            this->_Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Eos(unsigned int _Newsize)
    {
        _Traits::assign(_Myptr()[_Mysize = _Newsize], _Elem());
    }
    _Elem* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const _Elem* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

class ExceptionB07
{
  public:
    virtual ~ExceptionB07();
    virtual const char* what() const;
};

extern float g_fSpeedTreeTimeB07;
void __cdecl CSpeedTreeRT_NotifyAllTreesOfEvent(int iValue);
stdb07::string __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcError);

// @fnv 0x00b07060
// src: XBOX_PDB 0x00b07060
void __cdecl CSpeedTreeRT_SetTime(float fTime)
{
    try
    {
        g_fSpeedTreeTimeB07 = fTime;
        CSpeedTreeRT_NotifyAllTreesOfEvent(0);
    }
    catch (ExceptionB07& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::SetTime", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::SetTime").c_str());
    }
}
}  // namespace fnv_00b07060

namespace fnv_00b071f0 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}
struct CharAllocB071F0
{
    CharAllocB071F0()
    {}
    CharAllocB071F0(const CharAllocB071F0&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB071F0
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB071F0
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB071F0(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB071F0)
{
    return CharTraitsB071F0::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB071F0 CharTraitsCatB071F0()
{
    SecureTagB071F0 kTag;
    return kTag;
}
inline char* CopySB071F0(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB071F0(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB071F0());
}
struct TraitsB071F0
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB071F0
{
    StringValB071F0(CharAllocB071F0 kAl = CharAllocB071F0()) : m_kAlval(kAl)
    {}
    CharAllocB071F0 m_kAlval;
};
struct StringB071F0 : public StringValB071F0
{
    StringB071F0()
    {
        Tidy();
    }
    ~StringB071F0()
    {
        Tidy(true, 0);
    }
    const char* c_str() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB071F0::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB071F0(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
StringB071F0 __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcMessage);
struct EngineB071F0
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
    int unkD0;
    int m_iNumLeafRockingGroups;
    void SetNumLeafRockingGroups(int iGroups)
    {
        m_iNumLeafRockingGroups = iGroups;
    }
};
struct SpeedTreeRTB071F0
{
    EngineB071F0* m_pFirstPointer;
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
    char unk44;
    bool m_bComputed;
    void CSpeedTreeRT_SetLeafRockingState(int iGroups);
};

// @fnv 0x00b071f0
// src: EXE 0x00b071f0
void SpeedTreeRTB071F0::CSpeedTreeRT_SetLeafRockingState(int iGroups)
{
    try
    {
        if (!m_bComputed)
        {
            if (iGroups == 0)
                iGroups = 1;
            m_pFirstPointer->SetNumLeafRockingGroups(iGroups);
        }
        else
        {
            AssignString("SetNumLeafRockingGroups() has no effect after Compute() has been called");
        }
    }
    catch (std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::SetLeafRockingState", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(
            IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::SetLeafRockingState").c_str());
    }
}
}  // namespace fnv_00b071f0

namespace fnv_00b07510 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}
struct CharAllocB07510
{
    CharAllocB07510()
    {}
    CharAllocB07510(const CharAllocB07510&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB07510
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB07510
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB07510(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB07510)
{
    return CharTraitsB07510::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB07510 CharTraitsCatB07510()
{
    SecureTagB07510 kTag;
    return kTag;
}
inline char* CopySB07510(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB07510(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB07510());
}
struct TraitsB07510
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB07510
{
    StringValB07510(CharAllocB07510 kAl = CharAllocB07510()) : m_kAlval(kAl)
    {}
    CharAllocB07510 m_kAlval;
};
struct StringB07510 : public StringValB07510
{
    StringB07510()
    {
        Tidy();
    }
    ~StringB07510()
    {
        Tidy(true, 0);
    }
    const char* c_str() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB07510::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB07510(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
StringB07510 __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcMessage);
struct Part007510
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_uiFilterValue;
    void Set(int v)
    {
        m_uiFilterValue = v;
    }
};
struct Part107510
{
    char unk00;
    bool m_uiFilterValue;
    void Set(bool v)
    {
        m_uiFilterValue = v;
    }
};

struct SpeedTreeRTB07510
{
    int unk00;
    int unk04;
    Part107510* m_p1;
    int unk0C;
    Part007510* m_p0;
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
    char unk44;
    bool m_bComputed;
    void CSpeedTreeRT_SetLeafWindMethod(int eMode);
};

// @fnv 0x00b07510
// src: EXE 0x00b07510
void SpeedTreeRTB07510::CSpeedTreeRT_SetLeafWindMethod(int eMode)
{
    try
    {
        if (!m_bComputed)
        {
            m_p0->Set(eMode);
            m_p1->Set(eMode != 2);
        }
        else
        {
            AssignString("SetLeafWindMethod() has no effect after Compute() has been called");
        }
    }
    catch (std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::SetLeafWindMethod", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::SetLeafWindMethod").c_str());
    }
}
}  // namespace fnv_00b07510

namespace fnv_00b076e0 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}
struct CharAllocB076E0
{
    CharAllocB076E0()
    {}
    CharAllocB076E0(const CharAllocB076E0&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB076E0
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB076E0
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB076E0(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB076E0)
{
    return CharTraitsB076E0::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB076E0 CharTraitsCatB076E0()
{
    SecureTagB076E0 kTag;
    return kTag;
}
inline char* CopySB076E0(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB076E0(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB076E0());
}
struct TraitsB076E0
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB076E0
{
    StringValB076E0(CharAllocB076E0 kAl = CharAllocB076E0()) : m_kAlval(kAl)
    {}
    CharAllocB076E0 m_kAlval;
};
struct StringB076E0 : public StringValB076E0
{
    StringB076E0()
    {
        Tidy();
    }
    ~StringB076E0()
    {
        Tidy(true, 0);
    }
    const char* c_str() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB076E0::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB076E0(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
StringB076E0 __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcMessage);
struct WindB076E0
{
    int unk00;
    int unk04;
    int m_eMode;
    int GetMode() const
    {
        return m_eMode;
    }
    void SetMode(int e)
    {
        m_eMode = e;
    }
};
struct LeafB076E0
{
    int unk00;
    int unk04;
    bool m_bFlag08;
    char unk09;
    char unk0A;
    char unk0B;
    int unk0C;
    char unk10;
    char unk11;
    bool m_bFlag12;
    char unk13;
    int m_eMode14;
    void SetFlag12(bool b)
    {
        m_bFlag12 = b;
    }
    void SetFlag08(bool b)
    {
        m_bFlag08 = b;
    }
    void SetMode14(int e)
    {
        m_eMode14 = e;
    }
    void CIndexedGeometry_ComputeWindEffect(int i);
};

struct SpeedTreeRTB076E0
{
    int unk00;
    LeafB076E0* m_pLeafData;
    int unk08;
    int unk0C;
    WindB076E0* m_pWind;
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
    char unk44;
    bool m_bComputed;
    void CSpeedTreeRT_SetBranchWindMethod(int eMode);
};

// @fnv 0x00b076e0
// src: EXE 0x00b076e0
void SpeedTreeRTB076E0::CSpeedTreeRT_SetBranchWindMethod(int eMode)
{
    try
    {
        if (!m_bComputed)
        {
            if (eMode == 2 && m_pWind->GetMode() == 1)
            {
                m_pLeafData->SetFlag12(false);
                m_pLeafData->CIndexedGeometry_ComputeWindEffect(0);
            }
            m_pWind->SetMode(eMode);
            m_pLeafData->SetFlag08(eMode != 2);
            m_pLeafData->SetMode14(eMode);
        }
        else
        {
            AssignString("SetBranchWindMethod() has no effect after Compute() has been called");
        }
    }
    catch (std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::SetBranchWindMethod", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(
            IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::SetBranchWindMethod").c_str());
    }
}
}  // namespace fnv_00b076e0

namespace fnv_00b07900 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}
struct CharAllocB07900
{
    CharAllocB07900()
    {}
    CharAllocB07900(const CharAllocB07900&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB07900
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB07900
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB07900(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB07900)
{
    return CharTraitsB07900::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB07900 CharTraitsCatB07900()
{
    SecureTagB07900 kTag;
    return kTag;
}
inline char* CopySB07900(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB07900(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB07900());
}
struct TraitsB07900
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB07900
{
    StringValB07900(CharAllocB07900 kAl = CharAllocB07900()) : m_kAlval(kAl)
    {}
    CharAllocB07900 m_kAlval;
};
struct StringB07900 : public StringValB07900
{
    StringB07900()
    {
        Tidy();
    }
    ~StringB07900()
    {
        Tidy(true, 0);
    }
    const char* c_str() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB07900::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB07900(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
StringB07900 __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcMessage);
struct WindB07900
{
    int unk00;
    int unk04;
    int unk08;
    int m_eMode;
    int GetMode() const
    {
        return m_eMode;
    }
    void SetMode(int e)
    {
        m_eMode = e;
    }
};
struct LeafB07900
{
    int unk00;
    int unk04;
    bool m_bFlag08;
    char unk09;
    char unk0A;
    char unk0B;
    int unk0C;
    char unk10;
    char unk11;
    bool m_bFlag12;
    char unk13;
    int m_eMode14;
    void SetFlag12(bool b)
    {
        m_bFlag12 = b;
    }
    void SetFlag08(bool b)
    {
        m_bFlag08 = b;
    }
    void SetMode14(int e)
    {
        m_eMode14 = e;
    }
    void CIndexedGeometry_ComputeWindEffect(int i);
};

struct SpeedTreeRTB07900
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    WindB07900* m_pWind;
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
    char unk44;
    bool m_bComputed;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    LeafB07900* m_pLeafData;
    void CSpeedTreeRT_SetFrondWindMethod(int eMode);
};

// @fnv 0x00b07900
// src: EXE 0x00b07900
void SpeedTreeRTB07900::CSpeedTreeRT_SetFrondWindMethod(int eMode)
{
    try
    {
        if (!m_bComputed)
        {
            if (eMode == 2 && m_pWind->GetMode() == 1)
            {
                m_pLeafData->SetFlag12(false);
                m_pLeafData->CIndexedGeometry_ComputeWindEffect(0);
            }
            m_pWind->SetMode(eMode);
            m_pLeafData->SetFlag08(eMode != 2);
            m_pLeafData->SetMode14(eMode);
        }
        else
        {
            AssignString("SetFrondWindMethod() has no effect after Compute() has been called");
        }
    }
    catch (std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::SetFrondWindMethod", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(
            IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::SetFrondWindMethod").c_str());
    }
}
}  // namespace fnv_00b07900

namespace fnv_00b07b00 {
struct V3
{
    float x;
    float y;
    float z;
};
struct StrF
{
    int iAl;
    union
    {
        char acBuf[16];
        char* pPtr;
    } kBx;
    unsigned uiSize;
    unsigned uiRes;
    ~StrF()
    {
        int aiD[5];
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool b, unsigned n);
    const char* c_str() const
    {
        return 16 <= uiRes ? kBx.pPtr : kBx.acBuf;
    }
};
StrF __cdecl IdvFormatString(const char* pFmt, ...);
void __cdecl AssignString(const char* pMsg);
struct CIdvException
{
    virtual ~CIdvException();
    virtual const char* what() const;
};
struct WindQ
{
    float f0;
    float f4;
    int ai[3];
    bool b14;
    float GetF0() const
    {
        return f0;
    }
    float SetStrength(float a, float b, float c);
};
struct GeomQ
{
    char ac[0x12];
    bool b12;
    void SetB12(bool b)
    {
        b12 = b;
    }
};
struct WindTgt
{
    void CLeafGeometry_Invalidate();
};
struct SpdTreeQ
{
    int i0;
    GeomQ* pBranch;
    WindTgt* pWind8;
    int iC;
    WindQ* pWind;
    int ai[19];
    GeomQ* pFrond;
    int FUN_00b076c0();
    int GetFieldAt0C();
    int GetNestedPointer();
    bool WindB14() const
    {
        return pWind->b14;
    }
    float CSpeedTreeRT_SetWindStrength(float fWaterLevelItem, float fLeaf, float fBranch);
};
// @fnv 0x00b07b00
// src: EXE 0x00b07b00
float SpdTreeQ::CSpeedTreeRT_SetWindStrength(float fWaterLevelItem, float fLeaf, float fBranch)
{
    float fResult = 0.0f;
    try
    {
        if (fWaterLevelItem >= 0.0)
        {
            if (fLeaf == -1.0)
                fLeaf = pWind->f4;
            if (fBranch == -1.0)
                fBranch = pWind->GetF0();
            fResult = pWind->SetStrength(fWaterLevelItem, fLeaf, fBranch);
            if (FUN_00b076c0() == 1 && pBranch)
                pBranch->SetB12(false);
            if (GetFieldAt0C() == 1 && pFrond)
                pFrond->SetB12(false);
            if (GetNestedPointer() == 1 || WindB14())
                pWind8->CLeafGeometry_Invalidate();
        }
        else
        {
            AssignString("SetWindStrength() expects new wind strength >= 0.0");
        }
    }
    catch (CIdvException& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::SetWindStrength", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::SetWindStrength").c_str());
    }
    return fResult;
}
}  // namespace fnv_00b07b00

namespace fnv_00b07db0 {
extern "C" int __cdecl memcpy_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
namespace stdb07 {
struct _Secure_char_traits_tag
{
};
template <class _Elem> struct char_traits
{
    typedef _Elem char_type;
    typedef _Secure_char_traits_tag _Secure_char_traits;
    static void assign(_Elem& _Left, const _Elem& _Right)
    {
        _Left = _Right;
    }
    static _Elem* _Copy_s(_Elem* _First1, unsigned int _Dest_size, const _Elem* _First2, unsigned int _Count)
    {
        memcpy_s(_First1, _Dest_size, _First2, _Count);
        return _First1;
    }
};
template <class _Traits> struct _Char_traits_category
{
    typedef typename _Traits::_Secure_char_traits _Secure_char_traits;
};
template <class _Traits> inline typename _Char_traits_category<_Traits>::_Secure_char_traits _Char_traits_cat()
{
    typename _Char_traits_category<_Traits>::_Secure_char_traits _Secure;
    return (_Secure);
}
namespace _Traits_helper {
template <class _Traits>
inline typename _Traits::char_type* copy_s(typename _Traits::char_type* _First1, unsigned int _Size,
                                           const typename _Traits::char_type* _First2, unsigned int _Count,
                                           _Secure_char_traits_tag)
{
    return _Traits::_Copy_s(_First1, _Size, _First2, _Count);
}
template <class _Traits>
inline typename _Traits::char_type* copy_s(typename _Traits::char_type* _First1, unsigned int _Size,
                                           const typename _Traits::char_type* _First2, unsigned int _Count)
{
    return copy_s<_Traits>(_First1, _Size, _First2, _Count, _Char_traits_cat<_Traits>());
}
}

void __cdecl operator delete(void*);
template <class _Ty> class allocator
{
  public:
    allocator() throw()
    {}
    allocator(const allocator<_Ty>&) throw()
    {}
    void deallocate(_Ty* _Ptr, unsigned int)
    {
        ::operator delete(_Ptr);
    }
};
template <class _Ty, class _Alloc> class _String_val
{
  protected:
    _String_val(_Alloc _Al = _Alloc()) : _Alval(_Al)
    {}
    _Alloc _Alval;
};
template <class _Elem, class _Traits, class _Ax> class basic_string : public _String_val<_Elem, _Ax>
{
  public:
    basic_string(const basic_string& _Right);
    const _Elem* c_str() const
    {
        return (_Myptr());
    }
    ~basic_string()
    {
        _Tidy(true);
    }
    union
    {
        _Elem _Buf[16];
        _Elem* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;

  protected:
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
            ;
        else if (16 <= _Myres)
        {
            _Elem* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
                _Traits_helper::copy_s<_Traits>(_Bx._Buf, 16, _Ptr, _Newsize);
            this->_Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Eos(unsigned int _Newsize)
    {
        _Traits::assign(_Myptr()[_Mysize = _Newsize], _Elem());
    }
    _Elem* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const _Elem* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

class ExceptionB07
{
  public:
    virtual ~ExceptionB07();
    virtual const char* what() const;
};

extern MemoryManager g_kMemoryManagerB07;

inline void* operator new[](unsigned int uiSize)
{
    return g_kMemoryManagerB07.Allocate(uiSize);
}

inline void operator delete[](void* pvMem)
{
    g_kMemoryManagerB07.Deallocate(pvMem);
}

class WindMatrixB07
{
  public:
    WindMatrixB07();
    void SetIdentity();
    float m_afEntry[16];
};

class WindMatricesB07
{
  public:
    void SetNumWindMatrices(unsigned short usNum)
    {
        if (m_usNum != usNum)
        {
            delete[] m_pkMatrices;
            m_usNum = usNum;
            m_pkMatrices = new WindMatrixB07[usNum];
        }
        for (int i = 0; i < usNum; i++)
            m_pkMatrices[i].SetIdentity();
    }
    unsigned short m_usNum;
    WindMatrixB07* m_pkMatrices;
};
extern WindMatricesB07 g_kWindMatricesB07;
stdb07::string __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcError);

// @fnv 0x00b07db0
// src: EXE 0x00b07db0
void __cdecl CSpeedTreeRT_SetNumWindMatrices(unsigned short usMode)
{
    try
    {
        g_kWindMatricesB07.SetNumWindMatrices(usMode);
    }
    catch (ExceptionB07& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::SetNumWindMatrices", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(
            IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::SetNumWindMatrices").c_str());
    }
}
}  // namespace fnv_00b07db0

namespace fnv_00b08050 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}
struct CharAllocB08050
{
    CharAllocB08050()
    {}
    CharAllocB08050(const CharAllocB08050&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB08050
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB08050
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB08050(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB08050)
{
    return CharTraitsB08050::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB08050 CharTraitsCatB08050()
{
    SecureTagB08050 kTag;
    return kTag;
}
inline char* CopySB08050(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB08050(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB08050());
}
struct TraitsB08050
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB08050
{
    StringValB08050(CharAllocB08050 kAl = CharAllocB08050()) : m_kAlval(kAl)
    {}
    CharAllocB08050 m_kAlval;
};
struct StringB08050 : public StringValB08050
{
    StringB08050()
    {
        Tidy();
    }
    ~StringB08050()
    {
        Tidy(true, 0);
    }
    const char* c_str() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB08050::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB08050(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
StringB08050 __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcMessage);
struct WindGroupsB08050
{
    unsigned short m_usNumGroups;
};
extern WindGroupsB08050 g_kWindGroupsB08050;
struct LeafWindB08050
{
    void SetMatrixRange(unsigned int uiStart, unsigned int ItemUpdateArray);
};

struct SpeedTreeRTB08050
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LeafWindB08050* m_pLeafWind;
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
    char unk44;
    bool m_bComputed;
    void CSpeedTreeRT_SetLocalMatrices(unsigned int uiStart, unsigned int ItemUpdateArray);
};

// @fnv 0x00b08050
// src: EXE 0x00b08050
void SpeedTreeRTB08050::CSpeedTreeRT_SetLocalMatrices(unsigned int uiStart, unsigned int ItemUpdateArray)
{
    try
    {
        if (!m_bComputed)
        {
            if (uiStart + ItemUpdateArray - 1 < g_kWindGroupsB08050.m_usNumGroups)
                m_pLeafWind->SetMatrixRange(uiStart, ItemUpdateArray);
            else
                AssignString("SetLocalMatrices() parameters exceed available wind matrices");
        }
        else
        {
            AssignString("SetLocalMatrices() has no effect after Compute() has been called");
        }
    }
    catch (std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::SetLocalMatrices", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::SetLocalMatrices").c_str());
    }
}
}  // namespace fnv_00b08050

namespace fnv_00b08200 {
struct V3
{
    float x;
    float y;
    float z;
};
struct StrF
{
    int iAl;
    union
    {
        char acBuf[16];
        char* pPtr;
    } kBx;
    unsigned uiSize;
    unsigned uiRes;
    ~StrF()
    {
        int aiD[5];
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool b, unsigned n);
    const char* c_str() const
    {
        return 16 <= uiRes ? kBx.pPtr : kBx.acBuf;
    }
};
StrF __cdecl IdvFormatString(const char* pFmt, ...);
void __cdecl AssignString(const char* pMsg);
struct CIdvException
{
    virtual ~CIdvException();
    virtual const char* what() const;
};
struct TreeEngine
{
    int i0;
    V3 kPos;
    float f10;
    float f14;
    void SetPos(const V3& v)
    {
        kPos = v;
    }
    void SetF14(float f)
    {
        f14 = f;
    }
    float GetNormalizedValue();
};
struct LodInfo
{
    int i0;
    V3 kPos;
    float f10;
};
struct SpdTreeQ
{
    TreeEngine* pEngine;
    int ai[12];
    LodInfo* pLod;
    void CSpeedTreeRT_ComputeLodLevel();
};
// @fnv 0x00b08200
// src: EXE 0x00b08200
void SpdTreeQ::CSpeedTreeRT_ComputeLodLevel()
{
    try
    {
        if (pLod)
        {
            V3 kSavePos = pEngine->kPos;
            float fSave = pEngine->f14;
            pEngine->SetPos(pLod->kPos);
            pLod->f10 = pEngine->GetNormalizedValue();
            pEngine->SetF14(fSave);
            pEngine->SetPos(kSavePos);
        }
        else
        {
            pEngine->GetNormalizedValue();
        }
    }
    catch (CIdvException& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::ComputeLodLevel", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::ComputeLodLevel").c_str());
    }
}
}  // namespace fnv_00b08200

struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
struct PT;
struct OwnerB087
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    vectorS<PT*> m_kFirst;
    vectorS<int> m_kSecond;
    void ClearLists()
    {
        m_kFirst.clear();
        m_kSecond.clear();
    }
};
class ListOwnerRefB087
{
  public:
    void ProcessState_00b08780();
    void* m_pVTable;
    OwnerB087* m_pkOwnerManager;
};
// @fnv 0x00b08780
// src: GUESS 0x00b08780 (confidence: low)
void ListOwnerRefB087::ProcessState_00b08780()
{
    if (m_pkOwnerManager)
        m_pkOwnerManager->ClearLists();
}

namespace fnv_00b088d0 {
extern "C" int __cdecl memcpy_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
namespace stdb07 {
struct _Secure_char_traits_tag
{
};
template <class _Elem> struct char_traits
{
    typedef _Elem char_type;
    typedef _Secure_char_traits_tag _Secure_char_traits;
    static void assign(_Elem& _Left, const _Elem& _Right)
    {
        _Left = _Right;
    }
    static _Elem* _Copy_s(_Elem* _First1, unsigned int _Dest_size, const _Elem* _First2, unsigned int _Count)
    {
        memcpy_s(_First1, _Dest_size, _First2, _Count);
        return _First1;
    }
};
template <class _Traits> struct _Char_traits_category
{
    typedef typename _Traits::_Secure_char_traits _Secure_char_traits;
};
template <class _Traits> inline typename _Char_traits_category<_Traits>::_Secure_char_traits _Char_traits_cat()
{
    typename _Char_traits_category<_Traits>::_Secure_char_traits _Secure;
    return (_Secure);
}
namespace _Traits_helper {
template <class _Traits>
inline typename _Traits::char_type* copy_s(typename _Traits::char_type* _First1, unsigned int _Size,
                                           const typename _Traits::char_type* _First2, unsigned int _Count,
                                           _Secure_char_traits_tag)
{
    return _Traits::_Copy_s(_First1, _Size, _First2, _Count);
}
template <class _Traits>
inline typename _Traits::char_type* copy_s(typename _Traits::char_type* _First1, unsigned int _Size,
                                           const typename _Traits::char_type* _First2, unsigned int _Count)
{
    return copy_s<_Traits>(_First1, _Size, _First2, _Count, _Char_traits_cat<_Traits>());
}
}

void __cdecl operator delete(void*);
template <class _Ty> class allocator
{
  public:
    allocator() throw()
    {}
    allocator(const allocator<_Ty>&) throw()
    {}
    void deallocate(_Ty* _Ptr, unsigned int)
    {
        ::operator delete(_Ptr);
    }
};
template <class _Ty, class _Alloc> class _String_val
{
  protected:
    _String_val(_Alloc _Al = _Alloc()) : _Alval(_Al)
    {}
    _Alloc _Alval;
};
template <class _Elem, class _Traits, class _Ax> class basic_string : public _String_val<_Elem, _Ax>
{
  public:
    basic_string(const basic_string& _Right);
    const _Elem* c_str() const
    {
        return (_Myptr());
    }
    ~basic_string()
    {
        _Tidy(true);
    }
    union
    {
        _Elem _Buf[16];
        _Elem* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;

  protected:
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
            ;
        else if (16 <= _Myres)
        {
            _Elem* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
                _Traits_helper::copy_s<_Traits>(_Bx._Buf, 16, _Ptr, _Newsize);
            this->_Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Eos(unsigned int _Newsize)
    {
        _Traits::assign(_Myptr()[_Mysize = _Newsize], _Elem());
    }
    _Elem* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const _Elem* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

class ExceptionB07
{
  public:
    virtual ~ExceptionB07();
    virtual const char* what() const;
};

extern MemoryManager g_kMemoryManagerB08;

class BranchGeometryB08
{
  public:
    ~BranchGeometryB08();
    static void operator delete(void* pvMem)
    {
        g_kMemoryManagerB08.Deallocate(pvMem);
    }
    char m_acData[0x10];
};

class TreeInfoB08
{
  public:
    void ClearBranchVertices()
    {
        m_pvBranchVertices = 0;
    }
    char m_acPad[0x5c];
    void* m_pvBranchVertices;
};

class LodB08
{
  public:
    int m_iArrayLength;
};

stdb07::string __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcError);

// Local CSpeedTreeRT definition retained: include/CSpeedTreeRT.h is not available.
class CSpeedTreeRT
{
  public:
    void DeleteBranchGeometry();
    TreeInfoB08* m_pkTreeInfo;
    BranchGeometryB08* m_pkBranchGeometry;
    char m_acPad[0x30 - 8];
    LodB08* m_pkLod;
    void* m_pvBranchBuffer;
    char m_acPad2[0x45 - 0x38];
    bool m_bBranchesActive;
};

// @fnv 0x00b088d0
// src: EXE 0x00b088d0
void CSpeedTreeRT::DeleteBranchGeometry()
{
    try
    {
        if (m_bBranchesActive && m_pkBranchGeometry && !m_pvBranchBuffer && m_pkLod->m_iArrayLength == 1)
        {
            delete m_pkBranchGeometry;
            m_pkBranchGeometry = 0;
            if (m_pkTreeInfo)
                m_pkTreeInfo->ClearBranchVertices();
        }
    }
    catch (ExceptionB07& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::DeleteBranchGeometry", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(
            IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::DeleteBranchGeometry").c_str());
    }
}
}  // namespace fnv_00b088d0

namespace fnv_00b08af0 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}
struct CharAllocB08AF0
{
    CharAllocB08AF0()
    {}
    CharAllocB08AF0(const CharAllocB08AF0&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB08AF0
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB08AF0
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB08AF0(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB08AF0)
{
    return CharTraitsB08AF0::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB08AF0 CharTraitsCatB08AF0()
{
    SecureTagB08AF0 kTag;
    return kTag;
}
inline char* CopySB08AF0(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB08AF0(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB08AF0());
}
struct TraitsB08AF0
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB08AF0
{
    StringValB08AF0(CharAllocB08AF0 kAl = CharAllocB08AF0()) : m_kAlval(kAl)
    {}
    CharAllocB08AF0 m_kAlval;
};
struct StringB08AF0 : public StringValB08AF0
{
    StringB08AF0()
    {
        Tidy();
    }
    ~StringB08AF0()
    {
        Tidy(true, 0);
    }
    const char* c_str() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB08AF0::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB08AF0(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
StringB08AF0 __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcMessage);
struct LeafGeometryB08AF0
{
    const float* CopyLodData(int iIndex);
};
struct SpeedTreeRTB08AF0
{
    int unk00;
    int unk04;
    LeafGeometryB08AF0* m_pLodData;
    const float* CSpeedTreeRT_GetLeafBillboardTable(int iIndex);
};

// @fnv 0x00b08af0
// src: EXE 0x00b08af0
const float* SpeedTreeRTB08AF0::CSpeedTreeRT_GetLeafBillboardTable(int iIndex)
{
    const float* pSearchEntries = 0;
    try
    {
        pSearchEntries = m_pLodData->CopyLodData(iIndex);
    }
    catch (std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::GetLeafBillboardTable", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(
            IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::GetLeafBillboardTable").c_str());
    }
    return pSearchEntries;
}
}  // namespace fnv_00b08af0

struct S00b092a0_Str
{
    int m00;
    union
    {
        char buf[16];
        char* ptr;
    } m04;
    unsigned int m14;
    unsigned int m18;
    S00b092a0_Str(const char* s);
    ~S00b092a0_Str()
    {
        Tidy(true, 0);
    }
    void Tidy(bool built, unsigned int newsize);
};

struct S00b092a0_Exc
{
    void* vtbl;
    S00b092a0_Str m04;
    int m20;
    int m24;
    S00b092a0_Exc(const S00b092a0_Str& msg, int code);
    S00b092a0_Exc(const S00b092a0_Exc& o);
    ~S00b092a0_Exc();
};

struct S00b092a0_PadA
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    int m70;
    int m74;
    int m78;
    int m7c;
    int m80;
    int m84;
    int m88;
    int m8c;
    int m90;
    int m94;
    int m98;
    int m9c;
    int ma0;
    int ma4;
    int ma8;
    int mac;
    int mb0;
    int mb4;
    int mb8;
    int mbc;
    int mc0;
    int mc4;
    int mc8;
    int mcc;
};

struct S00b092a0_PadC
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    int m70;
    int m74;
    int m78;
    int m7c;
    int m80;
    int m84;
    int m88;
    int m8c;
    int m90;
    int m94;
    int m98;
    int m9c;
    int ma0;
    int ma4;
    int ma8;
    int mac;
    int mb0;
    int mb4;
    int mb8;
    int mbc;
    int mc0;
    int mc4;
    int mc8;
    int mcc;
    int md0;
};

struct S00b092a0_Buf
{
    int m00;
    int m04;
    int m08;
    char* m0c;
    char* m10;
    unsigned int size() const
    {
        return m10 - m0c;
    }
};

struct S00b092a0_Reader
{
    unsigned int pos;
    S00b092a0_Buf buf;
    int ReadInt();
    int Next()
    {
        S00b092a0_PadC scratch;
        return ReadInt();
    }
    void Begin()
    {
        S00b092a0_PadA st;
        st.m20 = 0;
    }
    float ReadFloat();
    bool AtEnd() const
    {
        return pos >= buf.size();
    }
};

struct S00b092a0_Child
{
    void Parse(S00b092a0_Reader* r);
};

struct S00b092a0_cls
{
    S00b092a0_Child* m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    float m1c;
    float m20;
    float m24;
    void CSpeedTreeRT_ParseLodInfo(S00b092a0_Reader* r);
};

// @fnv 0x00b092a0
// src: XBOX_PDB 0x00b092a0
void S00b092a0_cls::CSpeedTreeRT_ParseLodInfo(S00b092a0_Reader* r)
{
    r->Begin();
    int tok = r->ReadInt();
    do
    {
        switch (tok)
        {
        case 0x232a:
            m18 = r->ReadInt();
            break;
        case 0x232b:
            m1c = r->ReadFloat();
            break;
        case 0x232c:
            m20 = r->ReadFloat();
            break;
        case 0x2331:
            m24 = r->ReadFloat();
            break;
        case 0x232d:
            m00->Parse(r);
            break;
        default:
            throw S00b092a0_Exc("malformed lod info", 0);
        }
        if (r->AtEnd())
            throw S00b092a0_Exc("premature end of file reached parsing new lod info", 0);
        else
            tok = r->Next();
    } while (tok != 0x2329);
}

unsigned int __cdecl _strlen(const char* s);
void* __cdecl memcpy(void*, const void*, unsigned int);
void* __cdecl memmove(void*, const void*, unsigned int);
int __cdecl memcpy_s(void*, unsigned int, const void*, unsigned int);
int __cdecl memmove_s(void*, unsigned int, const void*, unsigned int);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct SpdCharTraits
{
    static void assign(char& a, const char& b)
    {
        a = b;
    }
    static unsigned int length(const char* p)
    {
        return _strlen(p);
    }
    static char* copy(char* dst, unsigned int size, const char* src, unsigned int count)
    {
        memcpy_s(dst, size, src, count);
        return dst;
    }
    static char* move(char* dst, unsigned int size, const char* src, unsigned int count)
    {
        memmove_s(dst, size, src, count);
        return dst;
    }
};
struct SpdSecureTag
{
};
inline SpdSecureTag SpdTraitsCategory()
{
    SpdSecureTag secure;
    return secure;
}
inline char* SpdCopy(char* dst, unsigned int size, const char* src, unsigned int count, SpdSecureTag)
{
    return SpdCharTraits::copy(dst, size, src, count);
}
inline char* SpdCopy(char* dst, unsigned int size, const char* src, unsigned int count)
{
    return SpdCopy(dst, size, src, count, SpdTraitsCategory());
}
inline char* SpdMove(char* dst, unsigned int size, const char* src, unsigned int count, SpdSecureTag)
{
    return SpdCharTraits::move(dst, size, src, count);
}
inline char* SpdMove(char* dst, unsigned int size, const char* src, unsigned int count)
{
    return SpdMove(dst, size, src, count, SpdTraitsCategory());
}
struct SpdAllocator
{
    SpdAllocator()
    {}
    SpdAllocator(const SpdAllocator&)
    {}
    char* allocate(unsigned int n)
    {
        return (char*)operator new(n);
    }
    void deallocate(char* p, unsigned int)
    {
        operator delete(p);
    }
    unsigned int max_size() const
    {
        unsigned int n = (unsigned int)-1;
        return 0 < n ? n : 1;
    }
};
struct SpdStringBase
{
    SpdAllocator m_pThreadAllocator;
    SpdStringBase(SpdAllocator a = SpdAllocator()) : m_pThreadAllocator(a)
    {}
    static void _Xlen();
    static void _Xran();
};
struct SpdString : SpdStringBase
{
    union
    {
        char m_buffer[16];
        char* m_pShaderConstantMap;
    } m_kStorage;
    unsigned int m_fRestLength;
    unsigned int m_pRayCursor;
    static const unsigned int npos;
    SpdString(const char* s) : SpdStringBase()
    {
        m_pRayCursor = 15;
        m_fRestLength = 0;
        m_kStorage.m_buffer[0] = 0;
        if (s)
            assign(s);
    }
    SpdString(const SpdString& s) : SpdStringBase(s)
    {
        _Tidy(false, 0);
        assign(s, 0, npos);
    }
    ~SpdString()
    {
        _Tidy(true, 0);
    }
    char* _Myptr()
    {
        return 16 <= m_pRayCursor ? m_kStorage.m_pShaderConstantMap : m_kStorage.m_buffer;
    }
    const char* _Myptr() const
    {
        return 16 <= m_pRayCursor ? m_kStorage.m_pShaderConstantMap : m_kStorage.m_buffer;
    }
    unsigned int size() const
    {
        return m_fRestLength;
    }
    unsigned int max_size() const
    {
        unsigned int n = m_pThreadAllocator.max_size();
        return n <= 1 ? 1 : n - 1;
    }
    void _Eos(unsigned int n)
    {
        char* ptr = _Myptr();
        SpdCharTraits::assign(ptr[m_fRestLength = n], char());
    }
    void _Tidy(bool built, unsigned int n)
    {
        if (!built)
            ;
        else if (16 <= m_pRayCursor)
        {
            char* p = m_kStorage.m_pShaderConstantMap;
            if (0 < n)
                SpdCopy(m_kStorage.m_buffer, 16, p, n);
            m_pThreadAllocator.deallocate(p, m_pRayCursor + 1);
        }
        m_pRayCursor = 15;
        _Eos(n);
    }
    void _Copy(unsigned int n, unsigned int oldlen)
    {
        unsigned int res = n | 15;
        if (max_size() < res)
            res = n;
        else if (res / 3 < m_pRayCursor / 2 && m_pRayCursor <= max_size() - m_pRayCursor / 2)
            res = m_pRayCursor + m_pRayCursor / 2;
        char* p = 0;
        try
        {
            p = m_pThreadAllocator.allocate(res + 1);
        }
        catch (...)
        {
            res = n;
            try
            {
                p = m_pThreadAllocator.allocate(res + 1);
            }
            catch (...)
            {
                _Tidy(true, 0);
                throw;
            }
        }
        if (0 < oldlen)
            SpdCopy(p, res + 1, _Myptr(), oldlen);
        _Tidy(true, 0);
        m_kStorage.m_pShaderConstantMap = p;
        m_pRayCursor = res;
        _Eos(oldlen);
    }
    bool _Grow(unsigned int n, bool trim = false)
    {
        if (max_size() < n)
            _Xlen();
        if (m_pRayCursor < n)
            _Copy(n, m_fRestLength);
        else if (trim && n < 16)
            _Tidy(true, n < m_fRestLength ? n : m_fRestLength);
        else if (n == 0)
            _Eos(0);
        return 0 < n;
    }
    bool _Inside(const char* p)
    {
        if (p == 0 || p < _Myptr() || _Myptr() + m_fRestLength <= p)
            return false;
        else
            return true;
    }
    SpdString& erase(unsigned int off = 0, unsigned int count = npos)
    {
        if (m_fRestLength < off)
            _Xran();
        if (m_fRestLength - off < count)
            count = m_fRestLength - off;
        if (0 < count)
        {
            SpdMove(_Myptr() + off, m_pRayCursor - off, _Myptr() + off + count, m_fRestLength - off - count);
            unsigned int n = m_fRestLength - count;
            _Eos(n);
        }
        return *this;
    }
    SpdString& assign(const SpdString& s, unsigned int off, unsigned int count)
    {
        if (s.size() < off)
            _Xran();
        unsigned int n = s.size() - off;
        if (count < n)
            n = count;
        if (this == &s)
            erase(off + n), erase(0, off);
        else if (_Grow(n))
        {
            SpdCopy(_Myptr(), m_pRayCursor, s._Myptr() + off, n);
            _Eos(n);
        }
        return *this;
    }
    SpdString& assign(const char* p, unsigned int n)
    {
        if (_Inside(p))
            return assign(*this, p - _Myptr(), n);
        if (_Grow(n))
        {
            SpdCopy(_Myptr(), m_pRayCursor, p, n);
            _Eos(n);
        }
        return *this;
    }
    SpdString& assign(const char* p)
    {
        return assign(p, SpdCharTraits::length(p));
    }
    SpdString& append(const char*, unsigned int);
    SpdString& append(const SpdString&, unsigned int, unsigned int);
    SpdString& operator+=(const char* p)
    {
        return append(p, SpdCharTraits::length(p));
    }
    SpdString& operator+=(const SpdString& s)
    {
        return append(s, 0, (unsigned int)-1);
    }
};
inline SpdString operator+(const SpdString& s, const char* p)
{
    return SpdString(s) += p;
}
inline SpdString operator+(const SpdString& s, const SpdString& r)
{
    return SpdString(s) += r;
}

int* __cdecl _errno();
char* __cdecl strerror(int nError);

struct SpdException
{
    int unk04;
    int unk08;
    SpdException();
    SpdException(const SpdException& cOther);
    virtual ~SpdException();
};

struct SpdRuntimeError : SpdException
{
    SpdString m_strMessage;
    explicit SpdRuntimeError(const SpdString& strMessage) : m_strMessage(strMessage)
    {}
    SpdRuntimeError(const SpdRuntimeError& cOther);
    virtual ~SpdRuntimeError();
};

struct SpdParseError : SpdRuntimeError
{
    SpdParseError(const SpdString& strMessage, bool bUseErrno)
        : SpdRuntimeError(strMessage + " [" + (bUseErrno ? SpdString(strerror(*_errno())) : SpdString("")) + "]")
    {}
};

struct SpdByteVector
{
    int unk00;
    int unk04;
    int unk08;
    char* m_pFirst;
    char* m_pLast;
    int unk14;
    unsigned int size() const
    {
        return m_pLast - m_pFirst;
    }
};

struct SpdParser
{
    unsigned int m_nPos;
    SpdByteVector m_vData;
    int ParseToken();
    bool AtEnd() const
    {
        return m_nPos >= m_vData.size();
    }
};

struct SpdWindInfo
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int m_nWindMatrixCount;
    void SetWindMatrixCount(int nCount)
    {
        m_nWindMatrixCount = nCount;
    }
};

struct SpdWindReader
{
    SpdWindInfo* m_pWind;
    void CSpeedTreeRT_ParseWindInfo(SpdParser* pParser);
};

// @fnv 0x00b097e0
// src: XBOX_PDB 0x00b097e0
void SpdWindReader::CSpeedTreeRT_ParseWindInfo(SpdParser* pParser)
{
    int nToken = pParser->ParseToken();
    do
    {
        switch (nToken)
        {
        case 0x2afa:
            m_pWind->SetWindMatrixCount(pParser->ParseToken());
            break;
        default:
            throw SpdParseError("malformed new wind info", false);
        }
        if (pParser->AtEnd())
            throw SpdParseError("premature end of file reached parsing new wind info", false);
        else
            nToken = pParser->ParseToken();
    } while (nToken != 0x2af9);
}

extern "C" unsigned int __cdecl strlen(const char* pcString);
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
extern "C" int __cdecl memmove_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
void* __cdecl operator new(unsigned int uiSize);
void __cdecl FUN_00ec7c56();
namespace std {
class bad_alloc
{
  public:
    bad_alloc(const char* pcMessage = "bad allocation") throw();
    virtual ~bad_alloc() throw();

  private:
    const char* m_pcWhat;
    int m_iDoFree;
};
}
struct SecureCharTag
{
};
struct CharTraits
{
    static unsigned int length(const char* pcFirst)
    {
        return strlen(pcFirst);
    }
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static char* _Move_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memmove_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct TraitsHelper
{
    static SecureCharTag CharTraitsCat()
    {
        SecureCharTag kTag;
        return kTag;
    }
    static char* CopySHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* CopyS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return CopySHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
    static char* MoveSHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Move_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* MoveS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return MoveSHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
};
inline char* AllocateChars(unsigned int ItemUpdateArray, char*)
{
    if (ItemUpdateArray <= 0)
        ItemUpdateArray = 0;
    else if (((unsigned int)(-1) / ItemUpdateArray) < sizeof(char))
        throw std::bad_alloc(0);
    return (char*)::operator new(ItemUpdateArray * sizeof(char));
}
struct CharAllocator
{
    CharAllocator()
    {}
    void deallocate(char* pcPtr, unsigned int)
    {
        ::operator delete(pcPtr);
    }
    char* allocate(unsigned int ItemUpdateArray)
    {
        return AllocateChars(ItemUpdateArray, (char*)0);
    }
    unsigned int max_size() const
    {
        unsigned int ItemUpdateArray = (unsigned int)(-1) / sizeof(char);
        return 0 < ItemUpdateArray ? ItemUpdateArray : 1;
    }
};
struct StringBase
{
    static void _Xlen();
    static void _Xran();
};
struct StringVal : public StringBase
{
    StringVal(CharAllocator kAl = CharAllocator()) : m_kAlval(kAl)
    {}
    CharAllocator m_kAlval;
};
struct String : public StringVal
{
    static const unsigned int npos;
    String(const char* pcPtr) : StringVal()
    {
        _Tidy();
        assign(pcPtr);
    }
    String(const String& kRight) : StringVal(kRight.m_kAlval)
    {
        _Tidy();
        assign(kRight, 0, npos);
    }
    ~String()
    {
        _Tidy(true);
    }
    String& assign(const String& kRight, unsigned int uiRoff, unsigned int ItemUpdateArray)
    {
        if (kRight.size() < uiRoff)
            _Xran();
        unsigned int uiElementCount = kRight.size() - uiRoff;
        if (ItemUpdateArray < uiElementCount)
            uiElementCount = ItemUpdateArray;
        if (this == &kRight)
            erase((unsigned int)(uiRoff + uiElementCount)), erase(0, uiRoff);
        else if (_Grow(uiElementCount))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, kRight._Myptr() + uiRoff, uiElementCount);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& assign(const char* pcPtr, unsigned int ItemUpdateArray)
    {
        if (_Inside(pcPtr))
            return assign(*this, pcPtr - _Myptr(), ItemUpdateArray);
        if (_Grow(ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, pcPtr, ItemUpdateArray);
            _Eos(ItemUpdateArray);
        }
        return *this;
    }
    String& assign(const char* pcPtr)
    {
        return assign(pcPtr, CharTraits::length(pcPtr));
    }
    String& erase(unsigned int uiOff = 0, unsigned int ItemUpdateArray = npos)
    {
        if (m_uiSize < uiOff)
            _Xran();
        if (m_uiSize - uiOff < ItemUpdateArray)
            ItemUpdateArray = m_uiSize - uiOff;
        if (0 < ItemUpdateArray)
        {
            TraitsHelper::MoveS(_Myptr() + uiOff, m_uiRes - uiOff, _Myptr() + uiOff + ItemUpdateArray,
                                m_uiSize - uiOff - ItemUpdateArray);
            unsigned int uiNewsize = m_uiSize - ItemUpdateArray;
            _Eos(uiNewsize);
        }
        return *this;
    }
    const char* c_str() const
    {
        if (16 <= m_uiRes)
            return m_kBx.m_pcPtr;
        return m_kBx.m_acBuf;
    }
    unsigned int size() const
    {
        return m_uiSize;
    }
    unsigned int length() const
    {
        return m_uiSize;
    }
    unsigned int max_size() const
    {
        unsigned int uiElementCount = m_kAlval.max_size();
        return uiElementCount <= 1 ? 1 : uiElementCount - 1;
    }
    const char& operator[](unsigned int uiOff) const
    {
        if (!(uiOff <= m_uiSize))
            FUN_00ec7c56();
        do
        {
        } while (0);
        return _Myptr()[uiOff];
    }
    void _Copy(unsigned int uiNewsize, unsigned int uiOldlen)
    {
        unsigned int uiNewres = uiNewsize | 15;
        if (max_size() < uiNewres)
            uiNewres = uiNewsize;
        else if (uiNewres / 3 < m_uiRes / 2 && m_uiRes <= max_size() - m_uiRes / 2)
            uiNewres = m_uiRes + m_uiRes / 2;
        char* pcPtr = 0;
        try
        {
            pcPtr = m_kAlval.allocate(uiNewres + 1);
        }
        catch (...)
        {
            uiNewres = uiNewsize;
            try
            {
                pcPtr = m_kAlval.allocate(uiNewres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < uiOldlen)
            TraitsHelper::CopyS(pcPtr, uiNewres + 1, _Myptr(), uiOldlen);
        _Tidy(true);
        m_kBx.m_pcPtr = pcPtr;
        m_uiRes = uiNewres;
        _Eos(uiOldlen);
    }
    void _Eos(unsigned int uiNewsize)
    {
        CharTraits::assign(_Myptr()[m_uiSize = uiNewsize], char());
    }
    bool _Grow(unsigned int uiNewsize, bool bTrim = false)
    {
        if (max_size() < uiNewsize)
            _Xlen();
        if (m_uiRes < uiNewsize)
            _Copy(uiNewsize, m_uiSize);
        else if (bTrim && uiNewsize < 16)
            _Tidy(true, uiNewsize < m_uiSize ? uiNewsize : m_uiSize);
        else if (uiNewsize == 0)
            _Eos(0);
        return 0 < uiNewsize;
    }
    bool _Inside(const char* pcPtr)
    {
        if (pcPtr == 0 || pcPtr < _Myptr() || _Myptr() + m_uiSize <= pcPtr)
            return false;
        else
            return true;
    }
    char* _Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    const char* _Myptr() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void _Tidy(bool bBuilt = false, unsigned int uiNewsize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewsize)
                TraitsHelper::CopyS(m_kBx.m_acBuf, 16, pcPtr, uiNewsize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        _Eos(uiNewsize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
extern "C" char* __cdecl strcpy(char* pcDst, const char* pcSrc);
struct FUN_00b09ef0 : public String
{
    FUN_00b09ef0(String strName);
};

// @fnv 0x00b09ef0
FUN_00b09ef0::FUN_00b09ef0(String strName) : String(strName)
{}

namespace fnv_00b09f90 {
extern "C" unsigned int __cdecl strlen(const char* pcString);
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
extern "C" int __cdecl memmove_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
void* __cdecl operator new(unsigned int uiSize);
void __cdecl FUN_00ec7c56();
namespace std {
class bad_alloc
{
  public:
    bad_alloc(const char* pcMessage = "bad allocation") throw();
    virtual ~bad_alloc() throw();

  private:
    const char* m_pcWhat;
    int m_iDoFree;
};
}
struct SecureCharTag
{
};
struct CharTraits
{
    static unsigned int length(const char* pcFirst)
    {
        return strlen(pcFirst);
    }
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static char* _Move_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memmove_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct TraitsHelper
{
    static SecureCharTag CharTraitsCat()
    {
        SecureCharTag kTag;
        return kTag;
    }
    static char* CopySHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* CopyS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return CopySHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
    static char* MoveSHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Move_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* MoveS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return MoveSHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
};
inline char* AllocateChars(unsigned int ItemUpdateArray, char*)
{
    if (ItemUpdateArray <= 0)
        ItemUpdateArray = 0;
    else if (((unsigned int)(-1) / ItemUpdateArray) < sizeof(char))
        throw std::bad_alloc(0);
    return (char*)::operator new(ItemUpdateArray * sizeof(char));
}
struct CharAllocator
{
    CharAllocator()
    {}
    void deallocate(char* pcPtr, unsigned int)
    {
        ::operator delete(pcPtr);
    }
    char* allocate(unsigned int ItemUpdateArray)
    {
        return AllocateChars(ItemUpdateArray, (char*)0);
    }
    unsigned int max_size() const
    {
        unsigned int ItemUpdateArray = (unsigned int)(-1) / sizeof(char);
        return 0 < ItemUpdateArray ? ItemUpdateArray : 1;
    }
};
struct StringBase
{
    static void _Xlen();
    static void _Xran();
};
struct StringVal : public StringBase
{
    StringVal(CharAllocator kAl = CharAllocator()) : m_kAlval(kAl)
    {}
    CharAllocator m_kAlval;
};
struct String : public StringVal
{
    static const unsigned int npos;
    String(const char* pcPtr) : StringVal()
    {
        _Tidy();
        assign(pcPtr);
    }
    String(const String& kRight) : StringVal()
    {
        _Tidy();
        assign(kRight, 0, npos);
    }
    ~String()
    {
        _Tidy(true);
    }
    String& assign(const String& kRight, unsigned int uiRoff, unsigned int ItemUpdateArray)
    {
        if (kRight.size() < uiRoff)
            _Xran();
        unsigned int uiElementCount = kRight.size() - uiRoff;
        if (ItemUpdateArray < uiElementCount)
            uiElementCount = ItemUpdateArray;
        if (this == &kRight)
            erase((unsigned int)(uiRoff + uiElementCount)), erase(0, uiRoff);
        else if (_Grow(uiElementCount))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, kRight._Myptr() + uiRoff, uiElementCount);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& assign(const char* pcPtr, unsigned int ItemUpdateArray)
    {
        if (_Inside(pcPtr))
            return assign(*this, pcPtr - _Myptr(), ItemUpdateArray);
        if (_Grow(ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, pcPtr, ItemUpdateArray);
            _Eos(ItemUpdateArray);
        }
        return *this;
    }
    String& assign(const char* pcPtr)
    {
        return assign(pcPtr, CharTraits::length(pcPtr));
    }
    String& erase(unsigned int uiOff = 0, unsigned int ItemUpdateArray = npos)
    {
        if (m_uiSize < uiOff)
            _Xran();
        if (m_uiSize - uiOff < ItemUpdateArray)
            ItemUpdateArray = m_uiSize - uiOff;
        if (0 < ItemUpdateArray)
        {
            TraitsHelper::MoveS(_Myptr() + uiOff, m_uiRes - uiOff, _Myptr() + uiOff + ItemUpdateArray,
                                m_uiSize - uiOff - ItemUpdateArray);
            unsigned int uiNewsize = m_uiSize - ItemUpdateArray;
            _Eos(uiNewsize);
        }
        return *this;
    }
    const char* c_str() const
    {
        if (16 <= m_uiRes)
            return m_kBx.m_pcPtr;
        return m_kBx.m_acBuf;
    }
    unsigned int size() const
    {
        return m_uiSize;
    }
    unsigned int length() const
    {
        return m_uiSize;
    }
    unsigned int max_size() const
    {
        unsigned int uiElementCount = m_kAlval.max_size();
        return uiElementCount <= 1 ? 1 : uiElementCount - 1;
    }
    const char& operator[](unsigned int uiOff) const
    {
        if (!(uiOff <= m_uiSize))
            FUN_00ec7c56();
        do
        {
        } while (0);
        return _Myptr()[uiOff];
    }
    void _Copy(unsigned int uiNewsize, unsigned int uiOldlen)
    {
        unsigned int uiNewres = uiNewsize | 15;
        if (max_size() < uiNewres)
            uiNewres = uiNewsize;
        else if (uiNewres / 3 < m_uiRes / 2 && m_uiRes <= max_size() - m_uiRes / 2)
            uiNewres = m_uiRes + m_uiRes / 2;
        char* pcPtr = 0;
        try
        {
            pcPtr = m_kAlval.allocate(uiNewres + 1);
        }
        catch (...)
        {
            uiNewres = uiNewsize;
            try
            {
                pcPtr = m_kAlval.allocate(uiNewres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < uiOldlen)
            TraitsHelper::CopyS(pcPtr, uiNewres + 1, _Myptr(), uiOldlen);
        _Tidy(true);
        m_kBx.m_pcPtr = pcPtr;
        m_uiRes = uiNewres;
        _Eos(uiOldlen);
    }
    void _Eos(unsigned int uiNewsize)
    {
        CharTraits::assign(_Myptr()[m_uiSize = uiNewsize], char());
    }
    bool _Grow(unsigned int uiNewsize, bool bTrim = false)
    {
        if (max_size() < uiNewsize)
            _Xlen();
        if (m_uiRes < uiNewsize)
            _Copy(uiNewsize, m_uiSize);
        else if (bTrim && uiNewsize < 16)
            _Tidy(true, uiNewsize < m_uiSize ? uiNewsize : m_uiSize);
        else if (uiNewsize == 0)
            _Eos(0);
        return 0 < uiNewsize;
    }
    bool _Inside(const char* pcPtr)
    {
        if (pcPtr == 0 || pcPtr < _Myptr() || _Myptr() + m_uiSize <= pcPtr)
            return false;
        else
            return true;
    }
    char* _Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    const char* _Myptr() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void _Tidy(bool bBuilt = false, unsigned int uiNewsize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewsize)
                TraitsHelper::CopyS(m_kBx.m_acBuf, 16, pcPtr, uiNewsize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        _Eos(uiNewsize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
extern "C" char* __cdecl strcpy(char* pcDst, const char* pcSrc);
struct IdvFilename : public String
{
    IdvFilename(String strName) : String(strName)
    {}
    IdvFilename ProcessEntries_00b09f90() const;
};

// @fnv 0x00b09f90
// src: GUESS 0x00b09f90 (confidence: low)
IdvFilename IdvFilename::ProcessEntries_00b09f90() const
{
    char szBuffer[1024];
    strcpy(szBuffer, c_str());
    int nLength = length();
    for (int i = nLength - 1; i >= 0; --i)
    {
        if ((*this)[i] == '/' || (*this)[i] == '\\')
        {
            int j = i + 1;
            int k = 0;
            for (; j < nLength; ++j, ++k)
                szBuffer[k] = (*this)[j];
            szBuffer[k] = 0;
            break;
        }
    }
    return String(szBuffer);
}
}  // namespace fnv_00b09f90

namespace fnv_00b0a2a0 {
struct CharAllocB0A2A0
{
    CharAllocB0A2A0()
    {}
    CharAllocB0A2A0(const CharAllocB0A2A0&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB0A2A0
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB0A2A0
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB0A2A0(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB0A2A0)
{
    return CharTraitsB0A2A0::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB0A2A0 CharTraitsCatB0A2A0()
{
    SecureTagB0A2A0 kTag;
    return kTag;
}
inline char* CopySB0A2A0(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB0A2A0(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB0A2A0());
}
struct TraitsB0A2A0
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB0A2A0
{
    StringValB0A2A0(CharAllocB0A2A0 kAl = CharAllocB0A2A0()) : m_kAlval(kAl)
    {}
    CharAllocB0A2A0 m_kAlval;
};
struct StringB0A2A0 : public StringValB0A2A0
{
    StringB0A2A0()
    {
        Tidy();
    }
    ~StringB0A2A0()
    {
        Tidy(true, 0);
    }
    const char* c_str() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB0A2A0::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB0A2A0(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
StringB0A2A0 __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcMessage);
void __cdecl FUN_00ec7c56();
void* __cdecl memcpy(void* pvDst, const void* pvSrc, unsigned int ItemUpdateArray);
inline void CopyFloat3B0A2A0(float* pDst, const float* pSrc)
{
    memcpy(pDst, pSrc, 12);
}
struct CollisionObjectB0A2A0
{
    int m_eRequestType;
    float m_afFirstVector[3];
    float m_afSecondVector[3];
};
struct CollisionVectorB0A2A0
{
    void* m_pkProxy;
    int m_iAux;
    int m_iAlval;
    CollisionObjectB0A2A0* m_pkFirst;
    CollisionObjectB0A2A0* m_pkLast;
    CollisionObjectB0A2A0* m_pkEnd;
    unsigned int size() const
    {
        return m_pkLast - m_pkFirst;
    }
    CollisionObjectB0A2A0& operator[](unsigned int uiPos)
    {
        if (!(uiPos < size()))
            FUN_00ec7c56();
        do
        {
        } while (0);
        return *(m_pkFirst + uiPos);
    }
};
struct SpeedTreeRTB0A2A0
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
    CollisionVectorB0A2A0* m_pCollisionVectors;
    void CSpeedTreeRT_GetCollisionObject(unsigned int uiIndex, int& eType, float* pPosition, float* pDimensions);
};

// @fnv 0x00b0a2a0
// src: XBOX_PDB 0x00b0a2a0
void SpeedTreeRTB0A2A0::CSpeedTreeRT_GetCollisionObject(unsigned int uiIndex, int& eType, float* pPosition, float* pDimensions)
{
    if (m_pCollisionVectors)
    {
        if (uiIndex >= m_pCollisionVectors->size())
            AssignString(IdvFormatString("collision object index (%d) exceeds maximum index (%d)", uiIndex,
                                      m_pCollisionVectors->size())
                             .c_str());
        else
        {
            eType = (*m_pCollisionVectors)[uiIndex].m_eRequestType;
            CopyFloat3B0A2A0(pPosition, (*m_pCollisionVectors)[uiIndex].m_afFirstVector);
            CopyFloat3B0A2A0(pDimensions, (*m_pCollisionVectors)[uiIndex].m_afSecondVector);
        }
    }
    else
        AssignString("no collision objects are stored with this tree");
}
}  // namespace fnv_00b0a2a0

namespace fnv_00b0a7a0 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}
struct CharAllocB0A7A0
{
    CharAllocB0A7A0()
    {}
    CharAllocB0A7A0(const CharAllocB0A7A0&)
    {}
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct SecureTagB0A7A0
{
};
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
struct CharTraitsB0A7A0
{
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
};
inline char* __cdecl CopySHelperB0A7A0(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                                       SecureTagB0A7A0)
{
    return CharTraitsB0A7A0::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
inline SecureTagB0A7A0 CharTraitsCatB0A7A0()
{
    SecureTagB0A7A0 kTag;
    return kTag;
}
inline char* CopySB0A7A0(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CopySHelperB0A7A0(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCatB0A7A0());
}
struct TraitsB0A7A0
{
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct StringValB0A7A0
{
    StringValB0A7A0(CharAllocB0A7A0 kAl = CharAllocB0A7A0()) : m_kAlval(kAl)
    {}
    CharAllocB0A7A0 m_kAlval;
};
struct StringB0A7A0 : public StringValB0A7A0
{
    StringB0A7A0()
    {
        Tidy();
    }
    ~StringB0A7A0()
    {
        Tidy(true, 0);
    }
    const char* c_str() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    char* Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void Eos(unsigned int uiNewSize)
    {
        TraitsB0A7A0::assign(Myptr()[m_uiSize = uiNewSize], char());
    }
    void Tidy(bool bBuilt = false, unsigned int uiNewSize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewSize)
                CopySB0A7A0(m_kBx.m_acBuf, 16, pcPtr, uiNewSize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        Eos(uiNewSize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
StringB0A7A0 __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcMessage);
extern MemoryManager g_kMemoryB0A7A0;
struct FrondGeometryB0A7A0
{
    ~FrondGeometryB0A7A0();
    static void operator delete(void* pvMem)
    {
        g_kMemoryB0A7A0.Deallocate(pvMem);
    }
};
struct BranchGeometryB0A7A0
{
    int m_eRequestType;
};
struct SpeedTreeRTB0A7A0
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
    BranchGeometryB0A7A0* m_pFrondSource;
    void* m_pFrondData;
    int unk38;
    int unk3C;
    int unk40;
    char unk44;
    bool m_bFrondsEnabled;
    char unk46;
    char unk47;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    FrondGeometryB0A7A0* m_pFrondGeometryData;
    void CSpeedTreeRT_DeleteFrondGeometry();
};

// @fnv 0x00b0a7a0
// src: EXE 0x00b0a7a0
void SpeedTreeRTB0A7A0::CSpeedTreeRT_DeleteFrondGeometry()
{
    try
    {
        if (m_bFrondsEnabled && m_pFrondGeometryData && !m_pFrondData && m_pFrondSource &&
            m_pFrondSource->m_eRequestType == 1)
        {
            delete m_pFrondGeometryData;
            m_pFrondGeometryData = 0;
        }
    }
    catch (std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::DeleteFrondGeometry", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(
            IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::DeleteFrondGeometry").c_str());
    }
}
}  // namespace fnv_00b0a7a0

namespace fnv_00b0a9a0 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
class FUN_00b0a9a0_Tree
{
  public:
    short CIndexedGeometry_GetNumStrips(short m_sIndex);
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
    vectorS<vectorS<int> > m_kLists;
};

// @fnv 0x00b0a9a0
// src: XBOX_PDB 0x00b0a9a0
short FUN_00b0a9a0_Tree::CIndexedGeometry_GetNumStrips(short m_sIndex)
{
    return (m_sIndex > -1) ? (short)m_kLists[m_sIndex].size() : (short)0;
}
}  // namespace fnv_00b0a9a0

void __cdecl FUN_00ec7c56();
// STL-style checked array: three pointers after allocator state; elements include nested strip arrays.
template <class T> struct CheckedLodArray
{
    void* m_pkProxy;
    int m_iAux;
    int m_iAlval;
    T* m_pFirst;
    T* m_pLast;
    T* m_pRecordEnd;
    unsigned int size() const
    {
        return m_pLast - m_pFirst;
    }
    bool empty() const
    {
        return size() == 0;
    }
    const T& operator[](unsigned int uiPos) const
    {
        if (!(uiPos < size()))
            FUN_00ec7c56();
        do
        {
        } while (0);
        return *(m_pFirst + uiPos);
    }
};
struct SpeedTreeRTB0AA20
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short m_usValueAt28;
    unsigned short unk22;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    CheckedLodArray<CheckedLodArray<short> > m_vLodStrips;
    const short* CIndexedGeometry_GetStripLengthsPointer(short nLod) const;
};

// @fnv 0x00b0aa20
// src: XBOX_PDB 0x00b0aa20
const short* SpeedTreeRTB0AA20::CIndexedGeometry_GetStripLengthsPointer(short nLod) const
{
    return nLod >= 0 && nLod < m_usValueAt28 && !m_vLodStrips[nLod].empty() ? &m_vLodStrips[nLod][0] : 0;
}

struct Eng28
{
    void __thiscall SetLeafLodGeometry(void* block, unsigned short idx, float a, float b, float c);
};
struct OutAd00
{
    int unk00;
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
    float m38;
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
    int unk6c;
    int unk70;
    int unk74;
    bool m78;
    char unk79;
    char unk7a;
    char unk7b;
    float m7c;
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
    bool mb4;
    char unkb5;
    char unkb6;
    char unkb7;
    float mb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    bool mf0;
    char unkf1;
    char unkf2;
    char unkf3;
    int unkf4;
    int unkf8;
    float mfc;
};
struct Vec3f
{
    union
    {
        struct
        {
            float x;
            float y;
            float z;
        };
        float f[3];
    };
    float& operator[](int i)
    {
        return f[i];
    }
};
extern "C" double atan2(double y, double x);
double FUN_00ec9610(double v);
struct SelfAd00
{
    int m00;
    int m04;
    Eng28* m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    float m1c;
    float m20;
    float m24;
    float m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    unsigned char m44;
    void __thiscall CSpeedTreeRT_GetBSGeometryLODData(OutAd00* out, float param);
};
// @fnv 0x00b0ad00
// src: XBOX_PDB 0x00b0ad00
void __thiscall SelfAd00::CSpeedTreeRT_GetBSGeometryLODData(OutAd00* out, float param)
{
    float asinRad;
    float t2;
    float angRad4;
    float t7;
    float t9;
    unsigned short tfbk;
    float fPf1;
    float pf9;
    unsigned short savedQ;
    float negDeg8;
    short sZ;
    Vec3f vc7;
    short _s1;
    unsigned short nW;
    Vec3f vaTmp;
    Vec3f vbC;
    float deg4;
    savedQ = ((CSpeedTreeRT*)this)->GetNumLeafLodLevels();
    nW = savedQ + (DAT_011f8b78 != 0);
    fPf1 = -1.0f;
    pf9 = -1.0f;
    _s1 = -1;
    sZ = -1;
    CSpeedTreeRT_GetTransitionValues(param, nW, m1c, m28, m20, (float)m44, &fPf1, &pf9, &_s1, &sZ);
    if (DAT_011f8b78)
    {
        out->mfc = -1.0f;
        if (_s1 == nW - 1)
        {
            out->mfc = fPf1;
        }
        else if (sZ == nW - 1)
        {
            out->mfc = pf9;
        }
        out->mf0 = (out->mfc != -1.0);
    }
    else
    {
        out->mf0 = 0;
    }
    if (param < 0.0)
    {
    }
    else
    {
        if (DAT_011f8b78)
        {
            if (_s1 == nW - 2)
            {
                out->m38 = fPf1;
            }
            else if (_s1 == nW - 1)
            {
                out->m38 = 255.0f;
            }
            else
            {
                out->m38 = (float)m44;
            }
        }
        else
        {
            out->m38 = (float)m44;
        }
        vaTmp.z = 0.0f;
        vaTmp.y = 0.0f;
        vaTmp.x = 0.0f;
        vbC.z = 0.0f;
        vbC.y = 0.0f;
        vbC.x = 0.0f;
        vc7.z = 0.0f;
        vc7.y = 0.0f;
        vc7.x = 0.0f;
        vaTmp = *(Vec3f*)&DAT_011f8e9c;
        vbC = *(Vec3f*)&DAT_011f8eac;
        vc7.x = vbC.x;
        vc7.y = vbC.y;
        vc7.z = vbC.z;
        t7 = vc7[1];
        t9 = vc7[0];
        angRad4 = (float)(double)(float)atan2(t7, t9);
        deg4 = angRad4 * 57.295780181884766;
        t2 = vc7[2];
        asinRad = (float)(double)(float)FUN_00ec9610(t2);
        negDeg8 = -(float)(asinRad * 57.295780181884766);
        if (m18 == 1)
        {
            m08->SetLeafLodGeometry(&out->m78, 0, deg4, negDeg8, m24);
            out->m78 = (_s1 != -1 && _s1 < savedQ);
            if (out->m78)
            {
                m08->SetLeafLodGeometry(&out->m78, _s1, deg4, negDeg8, m24);
                out->m7c = fPf1;
            }
            out->mb4 = (sZ != -1 && sZ < savedQ);
            if (out->mb4)
            {
                m08->SetLeafLodGeometry(&out->mb4, sZ, deg4, negDeg8, m24);
                out->mb8 = pf9;
            }
        }
        else if (m18 == 3)
        {
            m08->SetLeafLodGeometry(&out->m78, 0, deg4, negDeg8, m24);
            out->m78 = 1;
            out->m7c = (float)m44;
            out->mb4 = 0;
        }
        else
        {
            tfbk = ((FUN_00b08610_shell*)this)->CSpeedTreeRT_GetDiscreteLeafLodLevel(-1.0f);
            if (tfbk < ((CSpeedTreeRT*)this)->GetNumLeafLodLevels())
            {
                m08->SetLeafLodGeometry(&out->m78, tfbk, deg4, negDeg8, m24);
                out->m78 = 1;
                out->m7c = (float)m44;
            }
            out->mb4 = 0;
        }
    }
}

inline void DeadB()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
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
}
struct G0b
{
    char pad[0xc];
    float* pFirst;
    float* pLast;
    unsigned int Count()
    {
        return (unsigned int)(pLast - pFirst) / 3;
    }
};
struct E0b
{
    char pad[0x88];
    G0b geo;
    int CIndexedGeometry_GetVertexColors();
    int CIndexedGeometry_GetVertexCoords();
    int CIndexedGeometry_GetVertexNormals();
    int CIndexedGeometry_GetVertexBinormals();
    int CIndexedGeometry_GetVertexTangents();
    int CIndexedGeometry_GetVertexTexCoords0();
    int CIndexedGeometry_GetVertexTexCoords1();
    int CIndexedGeometry_GetVertexWindWeights();
    int CIndexedGeometry_GetVertexWindMatrixIndices();
    unsigned short CIndexedGeometry_GetNumStrips(unsigned short i);
    int CIndexedGeometry_GetStripLengthsPointer(unsigned short i);
    int CIndexedGeometry_GetStripsPointer(unsigned short i);
};
struct I0b
{
    int iLod;
    unsigned short usA;
    int i8;
    int ic;
    unsigned short m_usPassCountLocal;
    int i14, i18, i1c, i20, i24, i28, i2c, i30, i34;
    float fAlpha;
};
struct S0b
{
    int i0;
    E0b* pEngine;
    char p8[0x14];
    float f1c;
    float f20;
    int i24;
    float f28;
    char p2c[0x18];
    unsigned char ucMin;
    short GetIndexFromLevel(float f);
    unsigned short GetNumLeafLodLevels();
    float CSpeedTreeRT_GetLodLevel();
    void CSpeedTreeRT_GetBranchGeometry(I0b* pArg, short sLod);
};
// @fnv 0x00b0b1d0
// src: XBOX_PDB 0x00b0b1d0
void S0b::CSpeedTreeRT_GetBranchGeometry(I0b* pArg, short sLod)
{
    if (pEngine)
    {
        I0b* pInfo = pArg;
        pInfo->m_usPassCountLocal = pEngine->geo.Count();
        DeadB();
        pInfo->i14 = pEngine->CIndexedGeometry_GetVertexColors();
        pInfo->i24 = pEngine->CIndexedGeometry_GetVertexCoords();
        pInfo->i18 = pEngine->CIndexedGeometry_GetVertexNormals();
        pInfo->i1c = pEngine->CIndexedGeometry_GetVertexBinormals();
        pInfo->i20 = pEngine->CIndexedGeometry_GetVertexTangents();
        pInfo->i28 = pEngine->CIndexedGeometry_GetVertexTexCoords0();
        pInfo->i2c = pEngine->CIndexedGeometry_GetVertexTexCoords1();
        pInfo->i30 = pEngine->CIndexedGeometry_GetVertexWindWeights();
        pInfo->i34 = pEngine->CIndexedGeometry_GetVertexWindMatrixIndices();
        short sLevel7 = sLod == -1 ? GetIndexFromLevel(-1.0f) : sLod;
        pInfo->iLod = sLevel7;
        pInfo->usA = pEngine->CIndexedGeometry_GetNumStrips(sLevel7);
        pInfo->i8 = pEngine->CIndexedGeometry_GetStripLengthsPointer(sLevel7);
        pInfo->ic = pEngine->CIndexedGeometry_GetStripsPointer(sLevel7);
        if (DAT_011f8b78)
        {
            unsigned short usN5 = GetNumLeafLodLevels() + 1;
            float fW1 = -1.0f;
            float fW3 = -1.0f;
            short s5 = -1;
            short s2 = -1;
            CSpeedTreeRT_GetTransitionValues(CSpeedTreeRT_GetLodLevel(), usN5, f1c, f28, f20, ucMin, &fW1, &fW3, &s5, &s2);
            if (s5 == usN5 - 2)
                pArg->fAlpha = fW1;
            else if (s5 == usN5 - 1)
            {
                pArg->fAlpha = 255.0f;
                pInfo->iLod = -1;
            }
            else
                pArg->fAlpha = ucMin;
        }
        else
            pArg->fAlpha = ucMin;
    }
    else
        AssignString("no branch geometry exists, possible prior call to DeleteBranchGeometry");
}

void __cdecl InvalidParameterNoInfoB530();
struct GeometryArrayProxy;
class GeometryArrayAllocatorState
{
  public:
    GeometryArrayProxy* m_pkMyownedaux;
    int m_iAlaux;
};
class GeometryArrayStorage : public GeometryArrayAllocatorState
{
  public:
    int m_iAlval;
};
// STL-style checked geometry array: allocator state plus begin/end/capacity pointers, not four SIMD floats.
template <class T> class CheckedGeometryArray : public GeometryArrayStorage
{
  public:
    unsigned int size() const
    {
        return (unsigned int)(m_pMylast - m_pMyfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    T& operator[](unsigned int uiPos)
    {
        if (!(uiPos < size()))
            InvalidParameterNoInfoB530();
        do
        {
        } while (0);
        return *(m_pMyfirst + uiPos);
    }
    T* m_pMyfirst;
    T* m_pMylast;
    T* m_pMyend;
};
class FUN_00b0b530_Tree
{
  public:
    float* CIndexedGeometry_GetVertexCoords();
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
    CheckedGeometryArray<float> m_kValues;
};

// @fnv 0x00b0b530
// src: COMMUNITY 0x00b0b530
float* FUN_00b0b530_Tree::CIndexedGeometry_GetVertexCoords()
{
    return m_kValues.empty() ? 0 : &m_kValues[0];
}

class FUN_00b0b5b0_Tree
{
  public:
    float* CIndexedGeometry_GetVertexNormals();
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
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    CheckedGeometryArray<float> m_kValues;
};

// @fnv 0x00b0b5b0
// src: COMMUNITY 0x00b0b5b0
float* FUN_00b0b5b0_Tree::CIndexedGeometry_GetVertexNormals()
{
    return m_kValues.empty() ? 0 : &m_kValues[0];
}

class FUN_00b0b630_Tree
{
  public:
    float* CIndexedGeometry_GetVertexBinormals();
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
    CheckedGeometryArray<float> m_kValues;
};

// @fnv 0x00b0b630
// src: COMMUNITY 0x00b0b630
float* FUN_00b0b630_Tree::CIndexedGeometry_GetVertexBinormals()
{
    return m_kValues.empty() ? 0 : &m_kValues[0];
}

class FUN_00b0b6b0_Tree
{
  public:
    float* CIndexedGeometry_GetVertexTangents();
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
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    CheckedGeometryArray<float> m_kValues;
};

// @fnv 0x00b0b6b0
// src: COMMUNITY 0x00b0b6b0
float* FUN_00b0b6b0_Tree::CIndexedGeometry_GetVertexTangents()
{
    return m_kValues.empty() ? 0 : &m_kValues[0];
}

class FUN_00b0b730_Tree
{
  public:
    float* CIndexedGeometry_GetVertexTexCoords0();
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
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    CheckedGeometryArray<float> m_kValues;
};

// @fnv 0x00b0b730
// src: COMMUNITY 0x00b0b730
float* FUN_00b0b730_Tree::CIndexedGeometry_GetVertexTexCoords0()
{
    return m_kValues.empty() ? 0 : &m_kValues[0];
}

class FUN_00b0b7b0_Tree
{
  public:
    float* CIndexedGeometry_GetVertexTexCoords1();
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
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    CheckedGeometryArray<float> m_kValues;
};

// @fnv 0x00b0b7b0
// src: COMMUNITY 0x00b0b7b0
float* FUN_00b0b7b0_Tree::CIndexedGeometry_GetVertexTexCoords1()
{
    return m_kValues.empty() ? 0 : &m_kValues[0];
}

class FUN_00b0b8b0_Tree
{
  public:
    unsigned char* CIndexedGeometry_GetVertexWindMatrixIndices();
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
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    CheckedGeometryArray<unsigned char> m_kValues;
};

// @fnv 0x00b0b8b0
// src: COMMUNITY 0x00b0b8b0
unsigned char* FUN_00b0b8b0_Tree::CIndexedGeometry_GetVertexWindMatrixIndices()
{
    return m_kValues.empty() ? 0 : &m_kValues[0];
}

extern "C" double __cdecl atan2(double, double);

double __cdecl FUN_00ec9610(double);
inline int IndexZero()
{
    return 0;
}
inline int IndexOne()
{
    return 1;
}
inline int IndexTwo()
{
    return 2;
}
struct TreeGeometry
{
    bool active;
    float alpha;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
};
struct TreeOutput
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74;
    TreeGeometry first;
    TreeGeometry second;
};
struct TreeEngine
{
    void CLeafGeometry_Update_(TreeGeometry*, unsigned short, float, float, float);
    void SetLeafLodGeometry(TreeGeometry*, unsigned short, float, float, float);
};
void __cdecl CSpeedTreeRT_GetTransitionValues(float, unsigned short, float, float, float, float, float*, float*, short*, short*);
struct TreeRuntime : CSpeedTreeRT
{
    int unk04;
    TreeEngine* geometry;
    int unk0c, unk10, unk14;
    int lodMode;
    float lodNear, lodFar, scale, lodTransition;
    int unk2c, unk30, unk34, unk38, unk3c, unk40;
    unsigned char alpha;
    unsigned short CSpeedTreeRT_GetDiscreteLeafLodLevel(float);
    void CSpeedTreeRT_GetLeafGeometry(TreeOutput*, short);
};

// @fnv 0x00b0bc00
// src: COMMUNITY 0x00b0bc00
void TreeRuntime::CSpeedTreeRT_GetLeafGeometry(TreeOutput* output, short forcedLod)
{
    float resultVal;
    float pointX;
    float angle7;
    float posTmp;
    float result7;
    unsigned short indexVal;
    float aAngle;
    float angle3;
    short indexX;
    short index6;
    unsigned short index_;
    unsigned short count4;
    float angle5;
    float pos1[3];
    unsigned short count2;
    float position[3];
    float pos2[3];
    float angleVal;

    count4 = GetNumLeafLodLevels();
    count2 = count4 + (DAT_011f8b78 != 0);
    position[2] = 0.0f;
    position[1] = 0.0f;
    position[0] = 0.0f;
    pos2[2] = 0.0f;
    pos2[1] = 0.0f;
    pos2[0] = 0.0f;
    pos1[2] = 0.0f;
    pos1[1] = 0.0f;
    pos1[0] = 0.0f;
    *reinterpret_cast<CVec3*>(position) = *reinterpret_cast<const CVec3*>(&DAT_011f8e9c);
    *reinterpret_cast<CVec3*>(pos2) = *reinterpret_cast<const CVec3*>(&DAT_011f8eac);
    pos1[0] = pos2[0];
    pos1[1] = pos2[1];
    pos1[2] = pos2[2];
    posTmp = reinterpret_cast<float*>(&pos1)[IndexOne()];
    result7 = reinterpret_cast<float*>(&pos1)[IndexZero()];
    angle7 = (double)(float)atan2((double)posTmp, (double)result7);
    angleVal = angle7 * 57.295780181884766;
    pointX = reinterpret_cast<float*>(&pos1)[IndexTwo()];
    resultVal = (double)(float)FUN_00ec9610(pointX);
    angle5 = -(float)(resultVal * 57.295780181884766);
    index_ = 0;
    while (index_ < GetNumLeafLodLevels())
    {
        geometry->CLeafGeometry_Update_(&output->first, index_, angleVal, angle5, scale);
        ++index_;
    }
    if (forcedLod > -1)
    {
        geometry->SetLeafLodGeometry(&output->first, (unsigned short)forcedLod, angleVal, angle5, scale);
        output->first.active = true;
        output->first.alpha = (float)alpha;
        output->second.active = false;
    }
    else if (lodMode == 1)
    {
        aAngle = -1.0f;
        angle3 = -1.0f;
        index6 = -1;
        indexX = -1;
        CSpeedTreeRT_GetTransitionValues(reinterpret_cast<FUN_00b08440_shell*>(this)->CSpeedTreeRT_GetLodLevel(), count2, lodNear, lodTransition,
                     lodFar, (float)alpha, &aAngle, &angle3, &index6, &indexX);
        output->first.active = index6 != -1 && index6 < count4;
        if (output->first.active)
        {
            geometry->SetLeafLodGeometry(&output->first, (unsigned short)index6, angleVal, angle5, scale);
            output->first.alpha = aAngle;
        }
        output->second.active = indexX != -1 && indexX < count4;
        if (output->second.active)
        {
            geometry->SetLeafLodGeometry(&output->second, (unsigned short)indexX, angleVal, angle5, scale);
            output->second.alpha = angle3;
        }
    }
    else if (lodMode == 3)
    {
        geometry->SetLeafLodGeometry(&output->first, 0, angleVal, angle5, scale);
        output->first.active = true;
        output->first.alpha = (float)alpha;
        output->second.active = false;
    }
    else
    {
        indexVal = CSpeedTreeRT_GetDiscreteLeafLodLevel(-1.0f);
        if (indexVal < GetNumLeafLodLevels())
        {
            geometry->SetLeafLodGeometry(&output->first, indexVal, angleVal, angle5, scale);
            output->first.active = true;
            output->first.alpha = (float)alpha;
        }
        output->second.active = false;
    }
}

extern float DAT_01023cd8;
float __cdecl ComputeAzimuth(const float* v);
inline void Dead6()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
}
inline float Lerp0c(float t, float a, float b)
{
    return a + (b - a) * t;
}
inline float Lerp1c(float t, float fBase)
{
    return Lerp0c(t, fBase, 255.0f);
}
struct L0c
{
    char pad[0xc];
    int* data;
};
struct O0c
{
    char pad[0xf0];
    unsigned char bActive;
    char p1[3];
    int* pData;
    int iValue;
    float fWeight;
    short m_sIndex;
    char p2[2];
    unsigned char bBlend;
    char p3[3];
    int* pData2;
    int iValue2;
    float fWeight2;
    short sIndex2;
};
struct T0c
{
    char pad[0x20];
    float f20;
    int i24;
    float f28;
    char p2c[0x18];
    unsigned char ucMin;
    char p45[7];
    L0c* pList;
    char p50[4];
    unsigned short m_usPassCountLocal;
    void FillSpeedTreeOutput(O0c* out);
    void CSpeedTreeRT_Get360BillboardGeometry(O0c* pOut, unsigned int uiFlags);
};
// @fnv 0x00b0c050
// src: COMMUNITY 0x00b0c050
void T0c::CSpeedTreeRT_Get360BillboardGeometry(O0c* pOut, unsigned int uiFlags)
{
    FillSpeedTreeOutput(pOut);
    if (pOut->bActive && m_usPassCountLocal)
    {
        float fScale2 = (pOut->fWeight - ucMin) / (255.0 - ucMin);
        LocalVec3 vA3;
        LocalVec3 vB9;
        memcpy(&vA3, &DAT_011f8e9c, sizeof(vA3));
        memcpy(&vB9, &DAT_011f8eac, sizeof(vB9));
        memcpy(&vB9, &(-vB9), sizeof(vB9));
        Dead6();
        float fAngleTmp = ComputeAzimuth(&vB9.x);
        if (fAngleTmp < 0.0)
            fAngleTmp += 360.0;
        float fW3 = -1.0f;
        float fWTmp = -1.0f;
        short sA = -1;
        short s3 = -1;
        unsigned short usN = m_usPassCountLocal;
        float fHalf3 = 0.5 / usN;
        float fTVal = Lerp0c(fAngleTmp / 360.0, fHalf3, 1.0f - fHalf3);
        CSpeedTreeRT_GetTransitionValues(fTVal, usN, (float)(0.5 / usN), f28, f20, ucMin, &fW3, &fWTmp, &sA, &s3);
        sA = m_usPassCountLocal - 1 - sA;
        s3 = m_usPassCountLocal - 1 - s3;
        while (sA >= usN)
            sA = sA - usN;
        while (s3 >= usN)
            s3 = s3 - usN;
        if (uiFlags & 0x20)
        {
            pOut->bActive = 1;
            if (fW3 < fWTmp)
            {
                pOut->pData = pList->data + sA * 8;
                pOut->fWeight = Lerp1c(fScale2, ucMin);
                pOut->bBlend = 0;
            }
            else
            {
                pOut->pData = pList->data + s3 * 8;
                pOut->fWeight = Lerp1c(fScale2, ucMin);
                pOut->bBlend = 0;
            }
        }
        else
        {
            if (pList)
                pOut->pData = pList->data + sA * 8;
            else
                pOut->pData = 0;
            pOut->fWeight = Lerp0c(fScale2, fW3, 255.0f);
            pOut->m_sIndex = sA;
            pOut->iValue2 = pOut->iValue;
            if (pList)
                pOut->pData2 = pList->data + s3 * 8;
            else
                pOut->pData2 = 0;
            pOut->sIndex2 = s3;
            pOut->bBlend = 1;
            pOut->fWeight2 = Lerp0c(fScale2, fWTmp, 255.0f);
        }
    }
}

extern const double DAT_010a4d90;


// @fnv 0x00b0c470
// src: COMMUNITY 0x00b0c470
float __cdecl ComputeAzimuth(const float* p)
{
    float local_z[3];
    local_z[2] = 0.0f;
    local_z[1] = 0.0f;
    local_z[0] = 0.0f;

    local_z[0] = p[0];
    local_z[1] = p[1];
    local_z[2] = p[2];

    float y = (*reinterpret_cast<const CVec3*>(local_z))[1];
    float x = (*reinterpret_cast<const CVec3*>(local_z))[0];

    float result = (float)atan2((double)y, (double)x);
    float copy = result;
    {
        float scaled = (float)(copy * DAT_010a4d90);

        return scaled;
    }
}

extern const CVec3 g_akBasisC780[4];
struct FrameC780
{
    CVec3 m_akRows[4];
    bool m_bBuilt;
    bool IsBuilt() const
    {
        return m_bBuilt;
    }
    FrameC780* CSimpleBillboard_GetBillboardCoords(float fScale, float m_fProjectionDepth);
};

// @fnv 0x00b0c780
// src: COMMUNITY 0x00b0c780
FrameC780* FrameC780::CSimpleBillboard_GetBillboardCoords(float fScale, float m_fProjectionDepth)
{
    if (!IsBuilt())
    {
        CVec3 kScale(fScale, fScale, m_fProjectionDepth);
        m_akRows[0].x = kScale.x * g_akBasisC780[0][0];
        m_akRows[0].y = kScale.y * g_akBasisC780[0][1];
        m_akRows[0].z = kScale.z * g_akBasisC780[0][2];
        m_akRows[1].x = kScale.x * g_akBasisC780[1][0];
        m_akRows[1].y = kScale.y * g_akBasisC780[1][1];
        m_akRows[1].z = kScale.z * g_akBasisC780[1][2];
        m_akRows[2].x = kScale.x * g_akBasisC780[2][0];
        m_akRows[2].y = kScale.y * g_akBasisC780[2][1];
        m_akRows[2].z = kScale.z * g_akBasisC780[2][2];
        m_akRows[3].x = kScale.x * g_akBasisC780[3][0];
        m_akRows[3].y = kScale.y * g_akBasisC780[3][1];
        m_akRows[3].z = kScale.z * g_akBasisC780[3][2];
        m_bBuilt = true;
    }
    return this;
}

namespace fnv_00b0c8d0 {
static const float k255 = 255.0f;
inline float Lerp0c(float t, float a, float b)
{
    return a + (b - a) * t;
}
extern "C" double __cdecl FUN_00ec6cde(double);
extern "C" double __cdecl FUN_00ec9ac0(double, double);
// @fnv 0x00b0c8d0
// src: XBOX_PDB 0x00b0c8d0
void __cdecl CSpeedTreeRT_GetTransitionValues(float a, unsigned short n, float fLimit, float fMin, float fExp, float fBase, float* pOut1,
                          float* pOut2, short* pIdx1, short* pIdx2)
{
    unsigned short _us;
    {
        float f6;
        float fStep4;
        float fB;
        float fTmp;
        {
            float f4;
            int i_;
            float fFrac;
            float fPos4;
            float f5;
            {
                float f2c5;
                fPos4 = (1.0f - a) / (fStep4 = 1.0f / n);
                i_ = (int)fPos4;
                fFrac = fPos4 - i_;
                if (fFrac >= 0.5)
                    i_++;
                _us = (unsigned short)i_;
                f6 = (1.0f - a) - _us * fStep4;
                if (_us == 0 || _us == n || (float)FUN_00ec6cde(f6) > fLimit)
                {
                    *pOut1 = fBase;
                    *pIdx1 = (short)((1.0f - a) * n);
                    *pIdx1 = *pIdx1 < (short)(n - 1) ? *pIdx1 : (short)(n - 1);
                    *pOut2 = 255.0f;
                    *pIdx2 = -1;
                    return;
                }
                fB = 1.0f - (fLimit - f6) / (2.0 * fLimit);
                f4 = 1.0f - (fB - fMin) / (1.0f - fMin);
                f4 = f4 < 1.0 ? f4 : 1.0f;
                *pIdx1 = _us - 1;
                f5 = (float)(double)(float)FUN_00ec9ac0((float)(1.0f - f4), fExp);
                *pOut1 = Lerp0c(f5, fBase, 255.0f);
                fTmp = fB / (1.0f - fMin);
                fTmp = fTmp < 1.0 ? fTmp : 1.0f;
                *pIdx2 = _us;
                f2c5 = (float)(double)(float)FUN_00ec9ac0((float)(1.0f - fTmp), fExp);
                *pOut2 = Lerp0c(f2c5, fBase, 255.0f);
            }
        }
    }
}
}  // namespace fnv_00b0c8d0

namespace fnv_00b0cb10 {
struct V3
{
    float x;
    float y;
    float z;
};
struct StrF
{
    int iAl;
    union
    {
        char acBuf[16];
        char* pPtr;
    } kBx;
    unsigned uiSize;
    unsigned uiRes;
    ~StrF()
    {
        int aiD[5];
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool b, unsigned n);
    const char* c_str() const
    {
        return 16 <= uiRes ? kBx.pPtr : kBx.acBuf;
    }
};
StrF __cdecl IdvFormatString(const char* pFmt, ...);
void __cdecl AssignString(const char* pMsg);
struct CIdvException
{
    virtual ~CIdvException();
    virtual const char* what() const;
};
struct Pool
{
    void* Game_DoHeapAlloc(unsigned n);
};
extern Pool DAT_011f6238;
inline void* __cdecl operator new[](unsigned n)
{
    return DAT_011f6238.Game_DoHeapAlloc(n);
}
struct SpdTreeQ
{
    int ai[9];
    float f24;
    int i28;
    float* pafLodSizes;
    unsigned short GetNumLeafLodLevels();
    const float* CSpeedTreeRT_GetLeafLodSizeAdjustments();
};
// @fnv 0x00b0cb10
// src: EXE 0x00b0cb10
const float* SpdTreeQ::CSpeedTreeRT_GetLeafLodSizeAdjustments()
{
    try
    {
        if (!pafLodSizes)
        {
            int nLods = GetNumLeafLodLevels();
            pafLodSizes = new float[nLods];
            for (int i = 0; i < nLods; i++)
                pafLodSizes[i] = nLods > 0 ? 1.0 + f24 * i : 1.0;
        }
    }
    catch (CIdvException& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::GetLeafLodSizeAdjustments", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(
            IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::GetLeafLodSizeAdjustments").c_str());
    }
    return pafLodSizes;
}
}  // namespace fnv_00b0cb10

struct Pool_b0cd
{
    void* Game_DoHeapAlloc(unsigned int uiSize);
    void MemoryManager_Deallocate(void* pvBlock);
};
extern Pool_b0cd g_kPoolB0CD;

class Track_b0cd
{
  public:
    Track_b0cd();
    void ProcessEntries_00b3e750(int iValue);
    static void* operator new(unsigned int uiSize)
    {
        return g_kPoolB0CD.Game_DoHeapAlloc(uiSize);
    }
    static void operator delete(void* pvBlock)
    {
        g_kPoolB0CD.MemoryManager_Deallocate(pvBlock);
    }

    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};

class TrackOwner_b0cd
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    Track_b0cd* m_pkTrack;

    void CSpeedTreeRT_ParseShadowProjectionInfo(int iValue);
};

// @fnv 0x00b0cd40
// src: COMMUNITY 0x00b0cd40
void TrackOwner_b0cd::CSpeedTreeRT_ParseShadowProjectionInfo(int iValue)
{
    m_pkTrack = new Track_b0cd;
    m_pkTrack->ProcessEntries_00b3e750(iValue);
}

inline void Dead8_acad60()
{
    int a[8];
}
inline void Dead11_acad60()
{
    int a[11];
}
struct AlQ_acad60
{
};
struct CatQ_acad60
{
};
struct TagQ_acad60
{
};
inline CatQ_acad60 PtrCat_acad60(int*&, int*&)
{
    CatQ_acad60 c;
    return c;
}
void __cdecl Runtime_ProcessState_00b36b10(int* _First, unsigned int _Count, const int& _Val);
inline void UFill2_acad60(int* _First, unsigned int _Count, const int& _Val, AlQ_acad60& _Al, CatQ_acad60, TagQ_acad60)
{
    Dead8_acad60();
    Runtime_ProcessState_00b36b10(_First, _Count, _Val);
}
inline void UFillN_acad60(int* _First, unsigned int _Count, const int& _Val, AlQ_acad60& _Al)
{
    UFill2_acad60(_First, _Count, _Val, _Al, PtrCat_acad60(_First, _First), TagQ_acad60());
}
struct VecQ_acad60;
struct CItQ_acad60
{
    void* _Myaux;
    int* _Myptr;
    CItQ_acad60()
    {}
    CItQ_acad60(int* _Ptr, const VecQ_acad60* _Pvector);
};
struct ItQ_acad60 : CItQ_acad60
{
    ItQ_acad60()
    {}
    ItQ_acad60(int* _Ptr, const VecQ_acad60* _Pvector) : CItQ_acad60(_Ptr, _Pvector)
    {}
};
struct VecQ_acad60
{
    void* _Myownedaux;
    int m04;
    AlQ_acad60 _Alval;
    char p09[3];
    int* _Myfirst;
    int* _Mylast;
    int* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_acad60 end()
    {
        return ItQ_acad60(_Mylast, this);
    }
    int* _Ufill(int* _Ptr, unsigned int _Count, const int& _Val)
    {
        UFillN_acad60(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_acad60 ProcessAndReturnValue_00b0e600(CItQ_acad60 _Where, const int& _Val);
    void std_vector_push_back(const int& _Val);
};
inline CItQ_acad60::CItQ_acad60(int* _Ptr, const VecQ_acad60* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    do
    {
    } while (0);
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00b0ddc0
// src: COMMUNITY 0x00b0ddc0
void VecQ_acad60::std_vector_push_back(const int& _Val)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, _Val);
    else
    {
        ProcessAndReturnValue_00b0e600(end(), _Val);
        Dead11_acad60();
    }
}

namespace fnv_00b0df00 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
class FUN_00b0df00_Vector : public vectorS<int>
{
  public:
    iterator std_vector_erase(const_iterator _Where);
};

// @fnv 0x00b0df00
// src: COMMUNITY 0x00b0df00
FUN_00b0df00_Vector::iterator FUN_00b0df00_Vector::std_vector_erase(const_iterator _Where)
{
    unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
    _Destroy(_Mylast - 1, _Mylast);
    --_Mylast;
    return (_Make_iter(_Where));
}
}  // namespace fnv_00b0df00

struct ElQ_acda90
{
    int m[7];
};
struct AlQ_acda90
{
};
struct CatQ_acda90
{
};
struct TagQ_acda90
{
};
struct ElQ_acda90;
inline CatQ_acda90 PtrCat_acda90(ElQ_acda90*&, ElQ_acda90*&)
{
    CatQ_acda90 c;
    return c;
}
void __cdecl Speedtreert_ProcessEntries_00b10990(ElQ_acda90* _First, unsigned int _Count, const ElQ_acda90& _Val, AlQ_acda90& _Al, CatQ_acda90,
                          TagQ_acda90);
inline void UFillN_acda90(ElQ_acda90* _First, unsigned int _Count, const ElQ_acda90& _Val, AlQ_acda90& _Al)
{
    Speedtreert_ProcessEntries_00b10990(_First, _Count, _Val, _Al, PtrCat_acda90(_First, _First), TagQ_acda90());
}
struct VecQ_acda90;
struct CItQ_acda90
{
    void* _Myaux;
    ElQ_acda90* _Myptr;
    CItQ_acda90()
    {}
    CItQ_acda90(ElQ_acda90* _Ptr, const VecQ_acda90* _Pvector);
};
struct ItQ_acda90 : CItQ_acda90
{
    ItQ_acda90()
    {}
    ItQ_acda90(ElQ_acda90* _Ptr, const VecQ_acda90* _Pvector) : CItQ_acda90(_Ptr, _Pvector)
    {}
};
struct VecQ_acda90
{
    void* _Myownedaux;
    int m04;
    AlQ_acda90 _Alval;
    char p09[3];
    ElQ_acda90* _Myfirst;
    ElQ_acda90* _Mylast;
    ElQ_acda90* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_acda90 end()
    {
        return ItQ_acda90(_Mylast, this);
    }
    ElQ_acda90* _Ufill(ElQ_acda90* _Ptr, unsigned int _Count, const ElQ_acda90& _Val)
    {
        UFillN_acda90(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_acda90 ProcessAndReturnValue_00b0e880(CItQ_acda90 _Where, const ElQ_acda90& _Val);
    void UpdateState_00b0e090(const ElQ_acda90& _Val);
};
inline CItQ_acda90::CItQ_acda90(ElQ_acda90* _Ptr, const VecQ_acda90* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    do
    {
    } while (0);
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
inline void Dead12_acda90()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
}
// @fnv 0x00b0e090
// src: GUESS 0x00b0e090 (confidence: low)
void VecQ_acda90::UpdateState_00b0e090(const ElQ_acda90& _Val)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, _Val);
    else
    {
        ProcessAndReturnValue_00b0e880(end(), _Val);
        Dead12_acda90();
    }
}

namespace fnv_00b0ebb0 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
struct ElemEBB0
{
    int unk00;
};
class FUN_00b0ebb0_Iterator : public _Vector_const_iteratorS<ElemEBB0>
{
  public:
    ElemEBB0& ProcessEntries_00b0ebb0() const;
};

// @fnv 0x00b0ebb0
// src: GUESS 0x00b0ebb0 (confidence: low)
ElemEBB0& FUN_00b0ebb0_Iterator::ProcessEntries_00b0ebb0() const
{
    if (!(this->_Has_container()))
        InvalidParameterNoInfoS();
    do
    {
    } while (0);
    if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
        InvalidParameterNoInfoS();
    do
    {
    } while (0);
    return (*_Myptr);
}
}  // namespace fnv_00b0ebb0

inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}
struct ElQ
{
    int m[7];
};
__forceinline void Del(ElQ* p, unsigned int f)
{
    p->~ElQ();
}
inline void Construct(ElQ* p, const ElQ& v)
{
    void* vp = p;
    ::new (vp) ElQ(v);
}
// @fnv 0x00b10990
// src: GUESS 0x00b10990 (confidence: low)
void Speedtreert_ProcessEntries_00b10990(ElQ* first, unsigned int n, const ElQ& val)
{
    ElQ* next = first;
    try
    {
        for (; n > 0; --n, ++first)
            Construct(first, val);
    }
    catch (...)
    {
        for (; next != first; ++next)
            Del(next, 0);
        throw;
    }
}

namespace fnv_00b06180 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        do
        {
        } while (0);
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
class FUN_00b06180_Reader
{
  public:
    bool ProcessAndTransformResult_00b06180();
    unsigned int m_uiPosition;
    vectorS<unsigned char> m_kFlags;
};

// @fnv 0x00b06180
// src: GUESS 0x00b06180 (confidence: low)
bool FUN_00b06180_Reader::ProcessAndTransformResult_00b06180()
{
    return m_kFlags[m_uiPosition++] != 0;
}
}  // namespace fnv_00b06180

namespace fnv_00b06090 {
void __cdecl operator delete(void* _Ptr) throw();
namespace bufb060 {
void FUN_00ec7c56();
template <class T> inline void GvDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
extern "C" unsigned int __cdecl strlen(const char* _Str);
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static unsigned int length(const char* _First)
    {
        return strlen(_First);
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline BxSecureTag BxCharTraitsCat()
{
    BxSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct BxTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
    template <class T>
    static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Move_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return move_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
};
struct BxException;
struct BxBadAlloc;
template <class T> inline T* BxAllocate(unsigned int count, T*);
template <class T> struct BxAllocT
{
    typedef T* pointer;
    BxAllocT() throw()
    {}
    BxAllocT(const BxAllocT<T>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    pointer allocate(unsigned int _Count, const void*)
    {
        return allocate(_Count);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
typedef BxAllocT<char> BxCharAlloc;
struct BxStringVal
{
    BxCharAlloc _Alval;
    BxStringVal(BxCharAlloc _Al = BxCharAlloc()) : _Alval(_Al)
    {}
    BxStringVal(const BxStringVal& _Right) : _Alval(_Right._Alval)
    {}
};
struct BxString : public BxStringVal
{
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    BxString(const char* _Ptr) : BxStringVal()
    {
        _Tidy();
        assign(_Ptr);
    }
    BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, (unsigned int)-1);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    static void _Xlen();
    static void _Xran();
    unsigned int size() const
    {
        return _Mysize;
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        BxStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    BxString& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (_Mysize < _Off)
        {
            _Xran();
        }
        if (_Mysize - _Off < _Count)
        {
            _Count = _Mysize - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                                _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }
    bool _Inside(const char* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                BxTraitsHelper::copy_s<BxStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
        {
            _Newres = _Myres + _Myres / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        }
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            _Xlen();
        }
        if (_Myres < _Newsize)
        {
            _Copy(_Newsize, _Mysize);
        }
        else if (_Trim && _Newsize < 16)
        {
            _Tidy(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        }
        else if (_Newsize == 0)
        {
            _Eos(0);
        }
        return 0 < _Newsize;
    }
    BxString& assign(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
        {
            _Num = _Count;
        }
        if (this == &_Right)
        {
            erase((unsigned int)(_Roff + _Num)), erase(0, _Roff);
        }
        else if (_Grow(_Num))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return assign(*this, _Ptr - _Myptr(), _Count);
        }
        if (_Grow(_Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
struct BxException
{
    const char* _m_what;
    int _m_doFree;
    BxException();
    BxException(const char* const& _What);
    BxException(const BxException& _That);
    virtual ~BxException();
    virtual const char* what() const;
};
struct BxBadAlloc : public BxException
{
    BxBadAlloc(const char* _Message = "bad allocation") throw() : BxException(_Message)
    {}
    virtual ~BxBadAlloc() throw()
    {}
};
template <class T> inline T* BxAllocate(unsigned int count, T*)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (((unsigned int)(-1) / count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)operator new(count * sizeof(T));
}
struct BxLogicError : public BxException
{
    BxString _Str;
    explicit BxLogicError(const BxString& _Message) : _Str(_Message)
    {}
    virtual ~BxLogicError()
    {}
    virtual const char* what() const
    {
        return _Str._Myptr();
    }
};
struct BxLengthError : public BxLogicError
{
    explicit BxLengthError(const BxString& _Message) : BxLogicError(_Message)
    {}
    virtual ~BxLengthError()
    {}
};

template <class T> struct GvAlloc
{
    typedef T* pointer;
    GvAlloc() throw()
    {}
    GvAlloc(const GvAlloc<T>&) throw()
    {}
    template <class O> GvAlloc(const GvAlloc<O>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    void destroy(pointer _Ptr)
    {
        GvDestroyOne(_Ptr);
    }
    void construct(pointer _Ptr, const T& _Val)
    {
        GvConstruct(_Ptr, _Val);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
struct GvNonscalarTag
{
};
struct GvScalarTag
{
};
struct GvRangeCheckedTag
{
};
template <class T1, class T2> struct GvPtrCatHelper
{
    typedef GvNonscalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<char*, char*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T1, class T2> inline typename GvPtrCatHelper<T1, T2>::_Ptr_cat GvPtrCat(T1&, T2&)
{
    typename GvPtrCatHelper<T1, T2>::_Ptr_cat _Cat;
    return _Cat;
}
template <class A> inline void GvDestroyRange(typename A::pointer, typename A::pointer, A&, GvScalarTag)
{}
template <class T, class A>
void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al, GvNonscalarTag, GvRangeCheckedTag);
template <class T, class A> inline void GvUncheckedFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al)
{
    GvUninitFillN(_First, _Count, _Val, _Al, GvPtrCat(_First, _First), GvRangeCheckedTag());
}
template <class A>
inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, GvNonscalarTag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class A> inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    GvDestroyRange<A>(_First, _Last, _Al, GvPtrCat(_First, _Last));
}
struct GvInputTag
{
};
struct GvForwardTag : GvInputTag
{
};
struct GvBidiTag : GvForwardTag
{
};
struct GvRandomTag : GvBidiTag
{
};
struct GvUnchangedTag
{
};
template <class I1, class I2> inline GvRandomTag GvIterRandom(const I1&, const I2&)
{
    GvRandomTag _Cat;
    return _Cat;
}
struct GvBaseTag
{
};
template <class T> struct GvConstIterator;
template <class I> struct GvCheckedHelper
{
    typedef GvUnchangedTag _Tag;
    typedef I _Base;
};
template <class T> struct GvCheckedHelper<GvConstIterator<T> >
{
    typedef GvBaseTag _Tag;
    typedef const T* _Base;
};
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I, class O, class C>
inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    for (; _First != _Last; ++_Dest, ++_First)
    {
        *_Dest = *_First;
    }
    return _Dest;
}
template <class I, class O>
inline O GvCopyOpt(I _First, I _Last, O _Dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O _Result = _Dest + (_Last - _First);
    GvCopyOpt(_First, _Last, GvCheckedBase(_Dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return _Result;
}
template <class I, class O, class C> inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvScalarTag, GvRangeCheckedTag)
{
    int _Off = _Last - _First;
    O _Result = _Dest + _Off;
    if (_Off > 0)
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class I, class O> inline O GvUncheckedCopy(I _First, I _Last, O _Dest)
{
    return GvCopyOpt(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, GvIterRandom(_First, _Dest),
                     GvPtrCat(_First, _Dest), GvRangeCheckedTag());
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A& _Al, GvNonscalarTag, GvRangeCheckedTag)
{
    F _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
        {
            _Al.construct(_Dest, *_First);
        }
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
        {
            _Al.destroy(_Next);
        }
        throw;
    }
    return _Dest;
}
template <class I, class F, class A> inline F GvUncheckedUninitCopy(I _First, I _Last, F _Dest, A& _Al)
{
    return GvUninitCopy(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, _Al, GvPtrCat(_First, _Dest),
                        GvRangeCheckedTag());
}
template <class T1, class T2> inline void GvConstruct(T1* _Ptr, const T2& _Val)
{
    void* _Vptr = _Ptr;
    ::new (_Vptr) T1(_Val);
}
struct GvContainer;
struct GvAuxCont
{
    const GvContainer* _Mycontainer;
    GvAuxCont(const GvContainer* _Pcont) : _Mycontainer(_Pcont)
    {}
    const GvContainer* _Getcont() const
    {
        return _Mycontainer;
    }
};
struct GvContainer
{
    GvAuxCont* _Myownedaux;
    GvContainer()
    {}
    GvContainer(const GvContainer&)
    {}
    GvContainer& operator=(const GvContainer&)
    {
        return *this;
    }
    ~GvContainer()
    {}
};
template <class A> struct GvAuxBase : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit GvAuxBase(A _Al) : _Alaux(_Al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    GvAuxBase(const GvAuxBase& _Right) : _Alaux(_Right._Alaux)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    ~GvAuxBase()
    {
        _Myownedaux->~GvAuxCont();
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
struct GvIterBase
{
    GvAuxCont* _Myaux;
    GvIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const GvIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    void _Set_container(const GvContainer* _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const GvContainer* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
};
template <class T> struct GvVector;
template <class T> struct GvConstIterator : GvIterBase
{
    T* _Myptr;
    const T* _Checked_iterator_base() const
    {
        return _Myptr;
    }
    GvConstIterator(T* _Ptr, const GvContainer* _Pvector)
    {
        {
            if (!(_Pvector != 0 && ((GvVector<T>*)_Pvector)->_Myfirst <= _Ptr &&
                  _Ptr <= ((GvVector<T>*)_Pvector)->_Mylast))
            {
                FUN_00ec7c56();
            }
        }
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    GvConstIterator& operator+=(int _Off)
    {
        {
            if (!this->_Has_container())
            {
                FUN_00ec7c56();
            }
        }
        {
            if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
                  _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            {
                FUN_00ec7c56();
            }
        }
        _Myptr += _Off;
        return *this;
    }
    bool operator==(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
        }
        do
        {
        } while (0);
        return _Myptr == _Right._Myptr;
    }
    bool operator!=(const GvConstIterator& _Right) const
    {
        return !(*this == _Right);
    }
    int operator-(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
        }
        return _Myptr - _Right._Myptr;
    }
};
template <class T> struct GvIterator : GvConstIterator<T>
{
    GvIterator(T* _Ptr, const GvContainer* _Pvector) : GvConstIterator<T>(_Ptr, _Pvector)
    {}
    GvIterator& operator+=(int _Off)
    {
        (*(GvConstIterator<T>*)this) += _Off;
        return *this;
    }
    GvIterator operator+(int _Off) const
    {
        GvIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
template <class T> struct GvVectorVal : GvAuxBase<GvAlloc<T> >
{
    GvAlloc<T> _Alval;
    GvVectorVal(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase<GvAlloc<T> >(_Al), _Alval(_Al)
    {}
};
template <class T> struct GvVector : GvVectorVal<T>
{
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    GvVector() : GvVectorVal<T>()
    {
        _Buy(0);
    }
    GvVector(const GvVector& _Right) : GvVectorVal<T>(_Right._Alval)
    {
        if (_Buy(_Right.size()))
        {
            try
            {
                _Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    ~GvVector()
    {
        _Tidy();
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return this->_Alval.max_size();
    }
    GvIterator<T> begin()
    {
        return GvIterator<T>(_Myfirst, this);
    }
    GvIterator<T> end()
    {
        return GvIterator<T>(_Mylast, this);
    }
    GvConstIterator<T> begin() const
    {
        return GvConstIterator<T>(_Myfirst, this);
    }
    GvConstIterator<T> end() const
    {
        return GvConstIterator<T>(_Mylast, this);
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
        {
            return false;
        }
        else if (max_size() < _Capacity)
        {
            _Xlen();
        }
        else
        {
            _Myfirst = this->_Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    void _Destroy(T* _First, T* _Last)
    {
        GvDestroyRange(_First, _Last, this->_Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
    }
    T* _Ufill(T* _Ptr, unsigned int _Count, const T& _Val)
    {
        GvUncheckedFillN(_Ptr, _Count, _Val, this->_Alval);
        return _Ptr + _Count;
    }
    GvIterator<T> _Make_iter(GvConstIterator<T> _Where) const
    {
        return GvIterator<T>(_Where._Myptr, this);
    }
    GvIterator<T> erase(GvConstIterator<T> _First_arg, GvConstIterator<T> _Last_arg)
    {
        GvIterator<T> _First = _Make_iter(_First_arg);
        GvIterator<T> _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            T* _Ptr = GvUncheckedCopy(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void clear()
    {
        erase(begin(), end());
    }
    void resize(unsigned int _Newsize, T _Val)
    {
        if (size() < _Newsize)
            _Insert_n(end(), _Newsize - size(), _Val);
        else if (_Newsize < size())
            erase(begin() + _Newsize, end());
    }
    void resize(unsigned int _Newsize)
    {
        resize(_Newsize, T());
    }
    T& operator[](unsigned int _Pos)
    {
        {
            if (!(_Pos < size()))
            {
                FUN_00ec7c56();
            }
        }
        do
        {
        } while (0);
        return *(_Myfirst + _Pos);
    }
    template <class I> T* _Ucopy(I _First, I _Last, T* _Ptr)
    {
        return GvUncheckedUninitCopy(_First, _Last, _Ptr, this->_Alval);
    }
    GvVector& operator=(const GvVector& _Right)
    {
        if (this != &_Right)
        {
            if (_Right.size() == 0)
            {
                clear();
            }
            else if (_Right.size() <= size())
            {
                T* _Ptr = GvUncheckedCopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                _Destroy(_Ptr, _Mylast);
                _Mylast = _Myfirst + _Right.size();
            }
            else if (_Right.size() <= capacity())
            {
                T* _Ptr = _Right._Myfirst + size();
                GvUncheckedCopy(_Right._Myfirst, _Ptr, _Myfirst);
                _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
            }
            else
            {
                if (_Myfirst != 0)
                {
                    _Destroy(_Myfirst, _Mylast);
                    this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
                }
                if (_Buy(_Right.size()))
                {
                    _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                }
            }
        }
        return *this;
    }
    void _Insert_n(GvConstIterator<T> _Where, unsigned int _Count, const T& _Val);
    GvIterator<T> insert(GvConstIterator<T> _Where, const T& _Val)
    {
        unsigned int _Off = size() == 0 ? 0 : _Where - begin();
        _Insert_n(_Where, 1, _Val);
        return begin() + _Off;
    }
    void push_back(const T& _Val)
    {
        if (size() < capacity())
        {
            _Mylast = _Ufill(_Mylast, 1, _Val);
        }
        else
        {
            insert(end(), _Val);
        }
    }
};
}
using namespace bufb060;
struct FUN_00b06090
{
    int unk00;
    GvVector<char> kData;
    FUN_00b06090(const char* data, int size);
};
// @fnv 0x00b06090
FUN_00b06090::FUN_00b06090(const char* data, int size) : unk00(0)
{
    int p;
    int s0, s1, s2, s3, s4, s5;
    kData.resize(size, 0);
    for (p = 0; p < size; ++p)
    {
        kData[p] = data[p];
    }
}
}  // namespace fnv_00b06090

namespace fnv_00b09960 {
extern int DAT_010173f0;
extern unsigned char DAT_011f8b79;
typedef unsigned int size_t;
struct HeapQ
{
    void* Game_DoHeapAlloc(size_t n);
};
extern HeapQ DAT_011f6238;
inline void* operator new[](size_t n)
{
    return DAT_011f6238.Game_DoHeapAlloc(n);
}
struct FUN_0044a4c0
{
    int iAl;
    char acBuf[16];
    int iSize;
    int iRes;
    FUN_0044a4c0(const char* s);
    FUN_0044a4c0(const FUN_0044a4c0& r);
    ~FUN_0044a4c0()
    {
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool b, unsigned n);
    FUN_0044a4c0& AssignSubstring(const FUN_0044a4c0& r, unsigned o, unsigned n);
    FUN_0044a4c0& operator=(const FUN_0044a4c0& r)
    {
        return AssignSubstring(r, 0, *(unsigned*)&DAT_010173f0);
    }
};
struct FUN_00b096a0
{
    int aiBase[9];
    FUN_00b096a0(const FUN_0044a4c0& s);
    virtual ~FUN_00b096a0();
};
struct FUN_00b09480 : FUN_00b096a0
{
    FUN_00b09480(const FUN_0044a4c0& msg, bool bErrno) : FUN_00b096a0(bErrno ? FUN_0044a4c0("e") : msg)
    {
        int dq[44];
        dq[0] = 0;
    }
    virtual ~FUN_00b09480();
};
struct PathQ : FUN_0044a4c0
{
    PathQ(FUN_0044a4c0 s);
    FUN_0044a4c0 ProcessEntries_00b09f90();
};
struct ByteVec
{
    int i0;
    int i4;
    int i8;
    char* pFirst;
    char* pLast;
    unsigned size() const
    {
        return pLast - pFirst;
    }
};
struct Parser
{
    unsigned uiPos;
    ByteVec kData;
    int GetNextElement();
    float CTreeFileAccess_ParseFloat();
    FUN_0044a4c0 CTreeFileAccess_ParseString();
    bool ProcessAndTransformResult_00b06180();
    bool AtEnd()
    {
        int aK[9];
        return uiPos >= kData.size();
    }
};
struct TexCoordQ
{
    int iA;
    float* pA;
    int iB;
    float* pB;
    int iC;
    float* pC;
    FUN_0044a4c0 strName;
    int aiPad[8];
    TexCoordQ();
    static void* operator new(size_t n)
    {
        return DAT_011f6238.Game_DoHeapAlloc(n);
    }
};
inline void DeadTop()
{
    int aiD[67];
    aiD[4] = 0;
}
inline void Gap1()
{
    int aH[1];
}
inline void Gap4()
{
    int aG[4];
}
inline void GapBig()
{
    int aB[62];
}
inline void Z0()
{
    int a[63];
    a[0] = 0;
}
inline void DeadEnd()
{
    int aiE[6];
}
struct Tree
{
    int ai[19];
    TexCoordQ* pTileTexture;
    int aj[7];
    bool b6c;
    bool b6d;
    void CSpeedTreeRT_ParseTextureCoordInfo(Parser* p);
};
// @fnv 0x00b09960
// src: COMMUNITY 0x00b09960
void Tree::CSpeedTreeRT_ParseTextureCoordInfo(Parser* p)
{
    pTileTexture = new TexCoordQ;
    int iToken = p->GetNextElement();
    do
    {
        switch (iToken)
        {
        case 0x2712:
            Gap4();
            pTileTexture->iA = p->GetNextElement();
            if (pTileTexture->iA > 0)
            {
                pTileTexture->pA = new float[pTileTexture->iA * 8];
                for (int i = 0; i < pTileTexture->iA; i++)
                    for (int j = 0; j < 8; j++)
                        pTileTexture->pA[i * 8 + j] = p->CTreeFileAccess_ParseFloat();
            }
            break;
        case 0x2713:
            pTileTexture->iB = p->GetNextElement();
            if (pTileTexture->iB > 0)
            {
                pTileTexture->pB = new float[pTileTexture->iB * 8];
                for (int i = 0; i < pTileTexture->iB; i++)
                    for (int j = 0; j < 8; j++)
                    {
                        pTileTexture->pB[i * 8 + j] = p->CTreeFileAccess_ParseFloat();
                        if (j % 2 && DAT_011f8b79)
                            pTileTexture->pB[i * 8 + j] = -pTileTexture->pB[i * 8 + j];
                    }
            }
            break;
        case 0x2714:
            pTileTexture->iC = p->GetNextElement();
            if (pTileTexture->iC > 0)
            {
                pTileTexture->pC = new float[pTileTexture->iC * 8];
                for (int i = 0; i < pTileTexture->iC; i++)
                    for (int j = 0; j < 8; j++)
                        pTileTexture->pC[i * 8 + j] = p->CTreeFileAccess_ParseFloat();
            }
            break;
        case 0x2715: {
            Gap1();

            PathQ kPath(p->CTreeFileAccess_ParseString());
            pTileTexture->strName = kPath.ProcessEntries_00b09f90();
            break;
        }
        case 0x2716:
            b6d = p->ProcessAndTransformResult_00b06180();
            break;
        case 0x2717:
            b6c = p->ProcessAndTransformResult_00b06180();
            break;
        default:
            throw FUN_00b09480("malformed texture coord info", false);
        }
        if (p->AtEnd())
            throw FUN_00b09480("premature end of file reached parsing texture coordinate info", false);
        else
            iToken = p->GetNextElement();
    } while (iToken != 0x2711);
    DeadEnd();
}
}  // namespace fnv_00b09960

namespace fnv_00b0a490 {
struct FUN_0044a4c0
{
    int iAl;
    char acBuf[16];
    int iSize;
    int iRes;
    FUN_0044a4c0(const char* s);
    FUN_0044a4c0(const FUN_0044a4c0& r);
    ~FUN_0044a4c0()
    {
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool b, unsigned n);
};
struct FUN_00b096a0
{
    int aiBase[9];
    FUN_00b096a0(const FUN_0044a4c0& s);
    virtual ~FUN_00b096a0();
};
struct FUN_00b09480 : FUN_00b096a0
{
    FUN_00b09480(const FUN_0044a4c0& msg, bool bErrno);
    virtual ~FUN_00b09480();
};
struct Pool
{
    void* Game_DoHeapAlloc(unsigned n);
    void Free(void* p);
};
extern Pool DAT_011f6238;
struct V3
{
    float x;
    float y;
    float z;
};
struct Shape
{
    int iType;
    V3 a;
    V3 b;
};
struct FUN_00b0dfb0
{
    int ai[6];
    FUN_00b0dfb0()
    {
        Init();
    }
    void Init();
    static void* operator new(unsigned n)
    {
        int aiA[41];
        aiA[0] = 0;
        return DAT_011f6238.Game_DoHeapAlloc(n);
    }
    static void operator delete(void* p)
    {
        DAT_011f6238.Free(p);
    }
    void UpdateState_00b0e090(const Shape& s);
};
inline void Dead40()
{
    int aiE[40];
}
struct ByteVec
{
    int i0;
    int i4;
    int i8;
    char* pFirst;
    char* pLast;
    inline unsigned size() const
    {
        int aiD[49];
        return pLast - pFirst;
    }
};
struct Parser
{
    unsigned uiPos;
    ByteVec kData;
    int GetNextElement();
    float CTreeFileAccess_ParseFloat();
};
inline void* DeadNew(void* q)
{
    return q;
}
struct Tree
{
    int ai[22];
    FUN_00b0dfb0* pColl;
    void CSpeedTreeRT_ParseCollisionObjects(Parser* p);
};
// @fnv 0x00b0a490
// src: XBOX_PDB 0x00b0a490
void Tree::CSpeedTreeRT_ParseCollisionObjects(Parser* p)
{
    pColl = new FUN_00b0dfb0;
    int iToken3 = p->GetNextElement();
    V3 kPos2;
    do
    {
        Shape s;
        s.iType = 0;
        s.a.z = 0.0f;
        s.a.y = 0.0f;
        s.a.x = 0.0f;
        s.b.z = 0.0f;
        s.b.y = 0.0f;
        s.b.x = 0.0f;
        switch (iToken3)
        {
        case 0x2ee2:
            s.iType = 0;
            break;
        case 0x2ee3:
            s.iType = 1;
            break;
        case 0x2ee4:
            s.iType = 2;
            break;
        default:
            throw FUN_00b09480("malformed collision object info", false);
        }
        kPos2.x = p->CTreeFileAccess_ParseFloat();
        kPos2.y = p->CTreeFileAccess_ParseFloat();
        kPos2.z = p->CTreeFileAccess_ParseFloat();
        s.a.x = kPos2.x;
        s.a.y = kPos2.y;
        s.a.z = kPos2.z;
        switch (s.iType)
        {
        case 0:
            s.b.x = p->CTreeFileAccess_ParseFloat();
            break;
        case 1:
            s.b.x = p->CTreeFileAccess_ParseFloat();
            s.b.y = p->CTreeFileAccess_ParseFloat();
            break;
        case 2:
            s.b.x = p->CTreeFileAccess_ParseFloat();
            s.b.y = p->CTreeFileAccess_ParseFloat();
            s.b.z = p->CTreeFileAccess_ParseFloat();
            break;
        default:
            throw FUN_00b09480("unknown collision object type", false);
        }
        pColl->UpdateState_00b0e090(s);
        if ((bool)(int)(p->uiPos >= p->kData.size()))
            throw FUN_00b09480("premature end of file reached parsing collision object info", false);
        else
            iToken3 = p->GetNextElement();
    } while (iToken3 != 0x2ee1);
    Dead40();
}
}  // namespace fnv_00b0a490

namespace fnv_00b0d810 {
extern int DAT_010173f0;
struct FUN_0044a4c0
{
    int iAl;
    char acBuf[16];
    int iSize;
    int iRes;
    FUN_0044a4c0(const char* s);
    FUN_0044a4c0(const FUN_0044a4c0& r);
    ~FUN_0044a4c0()
    {
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool b, unsigned n);
    FUN_0044a4c0& AssignSubstring(const FUN_0044a4c0& r, unsigned o, unsigned n);
    FUN_0044a4c0& operator=(const FUN_0044a4c0& r)
    {
        return AssignSubstring(r, 0, *(unsigned*)&DAT_010173f0);
    }
};
struct FUN_00b096a0
{
    int aiBase[9];
    FUN_00b096a0(const FUN_0044a4c0& s);
    virtual ~FUN_00b096a0();
};
struct FUN_00b09480 : FUN_00b096a0
{
    FUN_00b09480(const FUN_0044a4c0& msg, bool bErrno) : FUN_00b096a0(bErrno ? FUN_0044a4c0("e") : msg)
    {
        int dq[39];
        dq[0] = 0;
    }
    virtual ~FUN_00b09480();
};
struct FUN_0044a500 : FUN_0044a4c0
{
    FUN_0044a500(const FUN_0044a4c0& r);
    FUN_0044a4c0 ProcessEntries_00b09f90();
};
struct KP : FUN_0044a500
{
    KP(FUN_0044a4c0 s) : FUN_0044a500(s)
    {}
};
struct ByteVec
{
    int i0;
    int i4;
    int i8;
    char* pFirst;
    char* pLast;
    inline unsigned size() const
    {
        int aK[4];
        return pLast - pFirst;
    }
};
struct Parser
{
    unsigned uiPos;
    ByteVec kData;
    int GetNextElement();
    float CTreeFileAccess_ParseFloat();
    FUN_0044a4c0 CTreeFileAccess_ParseString();
    bool ProcessAndTransformResult_00b06180();
};
struct TexQ
{
    int ai[6];
    FUN_0044a4c0 strName;
    float af[8];
};
inline void DeadEnd()
{
    int aiE[6];
}
inline void DeadTop()
{
    int aiD[106];
    aiD[58] = 0;
}
struct Tree
{
    int ai[19];
    TexQ* pTileTexture;
    int aj[7];
    bool b6c;
    bool b6d;
    void CSpeedTreeRT_ParseSupplementalTexCoordInfo(Parser* p);
};
// @fnv 0x00b0d810
// src: COMMUNITY 0x00b0d810
void Tree::CSpeedTreeRT_ParseSupplementalTexCoordInfo(Parser* p)
{
    if (pTileTexture)
    {
        int iToken = p->GetNextElement();
        do
        {
            switch (iToken)
            {
            case 0x4e22: {
                KP kPath(p->CTreeFileAccess_ParseString());
                pTileTexture->strName = kPath.ProcessEntries_00b09f90();
                break;
            }
            case 0x4e23:
                b6d = p->ProcessAndTransformResult_00b06180();
                break;
            case 0x4e24:
                b6c = p->ProcessAndTransformResult_00b06180();
                break;
            case 0x4e25:
                for (int i = 0; i < 8; i++)
                    pTileTexture->af[i] = p->CTreeFileAccess_ParseFloat();
                break;
            default:
                throw FUN_00b09480("malformed texture coord info", false);
            }
            if ((bool)(int)(p->uiPos >= p->kData.size()))
                throw FUN_00b09480("premature end of file reached parsing texture coordinate info", false);
            else
                iToken = p->GetNextElement();
        } while (iToken != 0x4e21);
    }
    DeadEnd();
}
}  // namespace fnv_00b0d810

namespace fnv_00b0dfb0 {
void __cdecl operator delete(void* _Ptr) throw();
namespace vct0dfb0 {
void FUN_00ec7c56();
template <class T> inline void GvDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
extern "C" unsigned int __cdecl strlen(const char* _Str);
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static unsigned int length(const char* _First)
    {
        return strlen(_First);
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline BxSecureTag BxCharTraitsCat()
{
    BxSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct BxTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
    template <class T>
    static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Move_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return move_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
};
struct BxException;
struct BxBadAlloc;
template <class T> inline T* BxAllocate(unsigned int count, T*);
template <class T> struct BxAllocT
{
    typedef T* pointer;
    BxAllocT() throw()
    {}
    BxAllocT(const BxAllocT<T>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    pointer allocate(unsigned int _Count, const void*)
    {
        return allocate(_Count);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
typedef BxAllocT<char> BxCharAlloc;
struct BxStringVal
{
    BxCharAlloc _Alval;
    BxStringVal(BxCharAlloc _Al = BxCharAlloc()) : _Alval(_Al)
    {}
    BxStringVal(const BxStringVal& _Right) : _Alval(_Right._Alval)
    {}
};
struct BxString : public BxStringVal
{
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    BxString(const char* _Ptr) : BxStringVal()
    {
        _Tidy();
        assign(_Ptr);
    }
    BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, (unsigned int)-1);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    static void _Xlen();
    static void _Xran();
    unsigned int size() const
    {
        return _Mysize;
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        BxStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    BxString& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (_Mysize < _Off)
        {
            _Xran();
        }
        if (_Mysize - _Off < _Count)
        {
            _Count = _Mysize - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                                _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }
    bool _Inside(const char* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                BxTraitsHelper::copy_s<BxStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
        {
            _Newres = _Myres + _Myres / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        }
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            _Xlen();
        }
        if (_Myres < _Newsize)
        {
            _Copy(_Newsize, _Mysize);
        }
        else if (_Trim && _Newsize < 16)
        {
            _Tidy(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        }
        else if (_Newsize == 0)
        {
            _Eos(0);
        }
        return 0 < _Newsize;
    }
    BxString& assign(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
        {
            _Num = _Count;
        }
        if (this == &_Right)
        {
            erase((unsigned int)(_Roff + _Num)), erase(0, _Roff);
        }
        else if (_Grow(_Num))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return assign(*this, _Ptr - _Myptr(), _Count);
        }
        if (_Grow(_Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
struct BxException
{
    const char* _m_what;
    int _m_doFree;
    BxException();
    BxException(const char* const& _What);
    BxException(const BxException& _That);
    virtual ~BxException();
    virtual const char* what() const;
};
struct BxBadAlloc : public BxException
{
    BxBadAlloc(const char* _Message = "bad allocation") throw() : BxException(_Message)
    {}
    virtual ~BxBadAlloc() throw()
    {}
};
template <class T> inline T* BxAllocate(unsigned int count, T*)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (((unsigned int)(-1) / count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)operator new(count * sizeof(T));
}
struct BxLogicError : public BxException
{
    BxString _Str;
    explicit BxLogicError(const BxString& _Message) : _Str(_Message)
    {}
    virtual ~BxLogicError()
    {}
    virtual const char* what() const
    {
        return _Str._Myptr();
    }
};
struct BxLengthError : public BxLogicError
{
    explicit BxLengthError(const BxString& _Message) : BxLogicError(_Message)
    {}
    virtual ~BxLengthError()
    {}
};

template <class T> struct GvAlloc
{
    typedef T* pointer;
    GvAlloc() throw()
    {}
    GvAlloc(const GvAlloc<T>&) throw()
    {}
    template <class O> GvAlloc(const GvAlloc<O>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    void destroy(pointer _Ptr)
    {
        GvDestroyOne(_Ptr);
    }
    void construct(pointer _Ptr, const T& _Val)
    {
        GvConstruct(_Ptr, _Val);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
struct GvNonscalarTag
{
};
struct GvScalarTag
{
};
struct GvRangeCheckedTag
{
};
template <class T1, class T2> struct GvPtrCatHelper
{
    typedef GvNonscalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<char*, char*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<unsigned short*, unsigned short*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T> struct GvPtrCatHelper<T**, T**>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T1, class T2> inline typename GvPtrCatHelper<T1, T2>::_Ptr_cat GvPtrCat(T1&, T2&)
{
    typename GvPtrCatHelper<T1, T2>::_Ptr_cat _Cat;
    return _Cat;
}
template <class A> inline void GvDestroyRange(typename A::pointer, typename A::pointer, A&, GvScalarTag)
{}
template <class T, class A>
void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al, GvNonscalarTag, GvRangeCheckedTag);
template <class T, class A> inline void GvUncheckedFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al)
{
    GvUninitFillN(_First, _Count, _Val, _Al, GvPtrCat(_First, _First), GvRangeCheckedTag());
}
template <class A>
inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, GvNonscalarTag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class A> inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    GvDestroyRange<A>(_First, _Last, _Al, GvPtrCat(_First, _Last));
}
struct GvInputTag
{
};
struct GvForwardTag : GvInputTag
{
};
struct GvBidiTag : GvForwardTag
{
};
struct GvRandomTag : GvBidiTag
{
};
struct GvUnchangedTag
{
};
template <class I1, class I2> inline GvRandomTag GvIterRandom(const I1&, const I2&)
{
    GvRandomTag _Cat;
    return _Cat;
}
struct GvBaseTag
{
};
template <class T> struct GvConstIterator;
template <class I> struct GvCheckedHelper
{
    typedef GvUnchangedTag _Tag;
    typedef I _Base;
};
template <class T> struct GvCheckedHelper<GvConstIterator<T> >
{
    typedef GvBaseTag _Tag;
    typedef const T* _Base;
};
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class O, class D, class T> inline void GvFillN(O _First, D _Count, const T& _Val, GvRangeCheckedTag)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class O, class D, class T, class C>
inline void GvFillN(O _First, D _Count, const T& _Val, C, GvRangeCheckedTag)
{
    GvFillN(_First, _Count, _Val, GvRangeCheckedTag());
}
template <class O, class D, class T>
inline void GvFillN(O _First, D _Count, const T& _Val, GvRandomTag, GvRangeCheckedTag)
{
    O _Last = _First + _Count;
    (void)_Last;
    GvFillN(GvCheckedBase(_First), _Count, _Val, GvRangeCheckedTag());
}
template <class I> inline GvRandomTag GvIterCat(const I&)
{
    GvRandomTag _Cat;
    return _Cat;
}
template <class O, class D, class T> inline void GvUncheckedFillValues(O _First, D _Count, const T& _Val)
{
    GvFillN(_First, _Count, _Val, GvIterCat(_First), GvRangeCheckedTag());
}
template <class T, class A>
inline void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A&, GvScalarTag, GvRangeCheckedTag)
{
    GvUncheckedFillValues(_First, _Count, _Val);
}
template <class I, class O, class C>
inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    for (; _First != _Last; ++_Dest, ++_First)
    {
        *_Dest = *_First;
    }
    return _Dest;
}
template <class I, class O>
inline O GvCopyOpt(I _First, I _Last, O _Dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O _Result = _Dest + (_Last - _First);
    GvCopyOpt(_First, _Last, GvCheckedBase(_Dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return _Result;
}
template <class I, class O, class C> inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvScalarTag, GvRangeCheckedTag)
{
    int _Off = _Last - _First;
    O _Result = _Dest + _Off;
    if (_Off > 0)
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class I, class O> inline O GvUncheckedCopy(I _First, I _Last, O _Dest)
{
    return GvCopyOpt(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, GvIterRandom(_First, _Dest),
                     GvPtrCat(_First, _Dest), GvRangeCheckedTag());
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A& _Al, GvNonscalarTag, GvRangeCheckedTag)
{
    F _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
        {
            _Al.construct(_Dest, *_First);
        }
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
        {
            _Al.destroy(_Next);
        }
        throw;
    }
    return _Dest;
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A&, GvScalarTag, GvRangeCheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    F _Result = _Dest + _Count;
    if (_Count > 0)
        FUN_00ec7c6b(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return _Result;
}
template <class I, class F, class A> inline F GvUncheckedUninitCopy(I _First, I _Last, F _Dest, A& _Al)
{
    return GvUninitCopy(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, _Al, GvPtrCat(_First, _Dest),
                        GvRangeCheckedTag());
}
template <class T1, class T2> inline void GvConstruct(T1* _Ptr, const T2& _Val)
{
    void* _Vptr = _Ptr;
    ::new (_Vptr) T1(_Val);
}
struct GvContainer;
struct GvAuxCont
{
    const GvContainer* _Mycontainer;
    GvAuxCont(const GvContainer* _Pcont) : _Mycontainer(_Pcont)
    {}
    const GvContainer* _Getcont() const
    {
        return _Mycontainer;
    }
};
struct GvContainer
{
    GvAuxCont* _Myownedaux;
    GvContainer()
    {}
    GvContainer(const GvContainer&)
    {}
    GvContainer& operator=(const GvContainer&)
    {
        return *this;
    }
    ~GvContainer()
    {}
};
template <class A> struct GvAuxBase : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit GvAuxBase(A _Al) : _Alaux(_Al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    GvAuxBase(const GvAuxBase& _Right) : _Alaux(_Right._Alaux)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    ~GvAuxBase()
    {
        _Myownedaux->~GvAuxCont();
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
struct GvIterBase
{
    GvAuxCont* _Myaux;
    GvIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const GvIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    void _Set_container(const GvContainer* _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const GvContainer* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
};
template <class T> struct GvVector;
template <class T> struct GvConstIterator : GvIterBase
{
    T* _Myptr;
    const T* _Checked_iterator_base() const
    {
        return _Myptr;
    }
    GvConstIterator(T* _Ptr, const GvContainer* _Pvector)
    {
        {
            if (!(_Pvector != 0 && ((GvVector<T>*)_Pvector)->_Myfirst <= _Ptr &&
                  _Ptr <= ((GvVector<T>*)_Pvector)->_Mylast))
            {
                FUN_00ec7c56();
            }
        }
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    GvConstIterator& operator+=(int _Off)
    {
        {
            if (!this->_Has_container())
            {
                FUN_00ec7c56();
            }
        }
        {
            if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
                  _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            {
                FUN_00ec7c56();
            }
        }
        _Myptr += _Off;
        return *this;
    }
    bool operator==(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
        }
        do
        {
        } while (0);
        return _Myptr == _Right._Myptr;
    }
    bool operator!=(const GvConstIterator& _Right) const
    {
        return !(*this == _Right);
    }
    int operator-(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
        }
        return _Myptr - _Right._Myptr;
    }
};
template <class T> struct GvIterator : GvConstIterator<T>
{
    GvIterator(T* _Ptr, const GvContainer* _Pvector) : GvConstIterator<T>(_Ptr, _Pvector)
    {}
    GvIterator& operator+=(int _Off)
    {
        (*(GvConstIterator<T>*)this) += _Off;
        return *this;
    }
    GvIterator operator+(int _Off) const
    {
        GvIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
template <class T> struct GvVectorVal : GvAuxBase<GvAlloc<T> >
{
    GvAlloc<T> _Alval;
    GvVectorVal(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase<GvAlloc<T> >(_Al), _Alval(_Al)
    {}
};
template <class T> struct GvVector : GvVectorVal<T>
{
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    GvVector() : GvVectorVal<T>()
    {
        _Buy(0);
    }
    explicit GvVector(unsigned int _Count) : GvVectorVal<T>()
    {
        _Construct_n(_Count, T());
    }
    void _Construct_n(unsigned int _Count, const T& _Val)
    {
        if (_Buy(_Count))
        {
            try
            {
                _Mylast = _Ufill(_Myfirst, _Count, _Val);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    GvVector(const GvVector& _Right) : GvVectorVal<T>(_Right._Alval)
    {
        if (_Buy(_Right.size()))
        {
            try
            {
                _Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    ~GvVector()
    {
        _Tidy();
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return this->_Alval.max_size();
    }
    GvIterator<T> begin()
    {
        return GvIterator<T>(_Myfirst, this);
    }
    GvIterator<T> end()
    {
        return GvIterator<T>(_Mylast, this);
    }
    GvConstIterator<T> begin() const
    {
        return GvConstIterator<T>(_Myfirst, this);
    }
    GvConstIterator<T> end() const
    {
        return GvConstIterator<T>(_Mylast, this);
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
            return false;
        else if (max_size() < _Capacity)
            _Xlen();
        else
        {
            _Myfirst = this->_Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    void _Destroy(T* _First, T* _Last)
    {
        GvDestroyRange(_First, _Last, this->_Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
    }
    T* _Ufill(T* _Ptr, unsigned int _Count, const T& _Val)
    {
        GvUncheckedFillN(_Ptr, _Count, _Val, this->_Alval);
        return _Ptr + _Count;
    }
    GvIterator<T> _Make_iter(GvConstIterator<T> _Where) const
    {
        return GvIterator<T>(_Where._Myptr, this);
    }
    GvIterator<T> erase(GvConstIterator<T> _First_arg, GvConstIterator<T> _Last_arg)
    {
        GvIterator<T> _First = _Make_iter(_First_arg);
        GvIterator<T> _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            T* _Ptr = GvUncheckedCopy(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void clear()
    {
        erase(begin(), end());
    }
    void resize(unsigned int _Newsize, T _Val)
    {
        if (size() < _Newsize)
            _Insert_n(end(), _Newsize - size(), _Val);
        else if (_Newsize < size())
            erase(begin() + _Newsize, end());
    }
    void resize(unsigned int _Newsize)
    {
        resize(_Newsize, T());
    }
    T& operator[](unsigned int _Pos)
    {
        {
            if (!(_Pos < size()))
            {
                FUN_00ec7c56();
            }
        }
        return *(_Myfirst + _Pos);
    }
    template <class I> T* _Ucopy(I _First, I _Last, T* _Ptr)
    {
        return GvUncheckedUninitCopy(_First, _Last, _Ptr, this->_Alval);
    }
    GvVector& operator=(const GvVector& _Right)
    {
        if (this != &_Right)
        {
            if (_Right.size() == 0)
            {
                clear();
            }
            else if (_Right.size() <= size())
            {
                T* _Ptr = GvUncheckedCopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                _Destroy(_Ptr, _Mylast);
                _Mylast = _Myfirst + _Right.size();
            }
            else if (_Right.size() <= capacity())
            {
                T* _Ptr = _Right._Myfirst + size();
                GvUncheckedCopy(_Right._Myfirst, _Ptr, _Myfirst);
                _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
            }
            else
            {
                if (_Myfirst != 0)
                {
                    _Destroy(_Myfirst, _Mylast);
                    this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
                }
                if (_Buy(_Right.size()))
                {
                    _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                }
            }
        }
        return *this;
    }
    void _Insert_n(GvConstIterator<T> _Where, unsigned int _Count, const T& _Val);
    GvIterator<T> insert(GvConstIterator<T> _Where, const T& _Val)
    {
        unsigned int _Off = size() == 0 ? 0 : _Where - begin();
        _Insert_n(_Where, 1, _Val);
        return begin() + _Off;
    }
    void push_back(const T& _Val)
    {
        if (size() < capacity())
        {
            _Mylast = _Ufill(_Mylast, 1, _Val);
        }
        else
        {
            insert(end(), _Val);
        }
    }
};
struct GvItem;
template <class T> struct GvVectorStore : GvAuxBase<GvAlloc<T> >
{
    GvAlloc<T> _Alval;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    GvVectorStore(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase<GvAlloc<T> >(_Al), _Alval(_Al)
    {}
    unsigned int max_size() const
    {
        return this->_Alval.max_size();
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
            return false;
        else if (max_size() < _Capacity)
            _Xlen();
        else
        {
            _Myfirst = this->_Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
};
}
using namespace vct0dfb0;
struct FUN_00b0dfb0 : GvVectorStore<BxString>
{
    FUN_00b0dfb0();
};
// @fnv 0x00b0dfb0
FUN_00b0dfb0::FUN_00b0dfb0() : GvVectorStore<BxString>()
{
    _Buy(0);
}
}  // namespace fnv_00b0dfb0

struct TreeResource
{
    static __forceinline void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
struct BranchResource : TreeResource
{
    void FUN_00b2e9c0();
    __forceinline ~BranchResource()
    {
        FUN_00b2e9c0();
    }
};
struct LeafResource : TreeResource
{
    void Reset();
    __forceinline ~LeafResource()
    {
        Reset();
    }
};
struct VirtualResource
{
    virtual ~VirtualResource();
};
struct LodResource : TreeResource
{
    void ReleaseStorage_00b04420();
    __forceinline ~LodResource()
    {
        ReleaseStorage_00b04420();
    }
};
struct BillboardResource : TreeResource
{
    void FUN_00b181b0();
    __forceinline ~BillboardResource()
    {
        FUN_00b181b0();
    }
};
struct StringResource : TreeResource
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    void* m20;
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > name;
    __forceinline ~StringResource()
    {
        name._Tidy(true, 0);
    }
};
struct Registry;
struct RegCIt
{
    void* owner;
    void** current;
    bool ProcessEntries_00b0eca0(const RegCIt&) const;
    __forceinline bool operator!=(const RegCIt& r) const
    {
        return !(ProcessEntries_00b0eca0(r));
    }
    __forceinline void setCur(void** p)
    {
        current = p;
    }
    __forceinline void** base() const
    {
        return current;
    }
};
struct RegistryIterator : RegCIt
{
    RegistryIterator(void** p, Registry* r);
};
template <class T> __forceinline void releaseMemory(T* p)
{
    g_memoryManager.Deallocate(p);
}
struct ProxyRoot : TreeResource
{
    __forceinline ~ProxyRoot()
    {}
};
struct RegistryProxy : ProxyRoot
{
    void* proxy;
    __forceinline ~RegistryProxy()
    {
        releaseMemory(proxy);
    }
};
struct RegMid : RegistryProxy
{
    __forceinline ~RegMid()
    {}
};
struct Registry : RegMid
{
    void* m04;
    void* m08;
    void** first;
    void** last;
    void** limit;
    void Clear();
    RegistryIterator std_vector_erase(RegCIt);
    __forceinline RegistryIterator begin()
    {
        void** p = first;
        return RegistryIterator(p, this);
    }
    __forceinline RegistryIterator end()
    {
        void** p = last;
        return RegistryIterator(p, this);
    }
    __forceinline ~Registry()
    {
        Clear();
    }
};
struct OtherRegistryProxy : ProxyRoot
{
    void* proxy;
    __forceinline ~OtherRegistryProxy()
    {
        releaseMemory(proxy);
    }
};
struct OtherMid : OtherRegistryProxy
{
    __forceinline ~OtherMid()
    {}
};
struct OtherRegistry : OtherMid
{
    void ReleaseEntries_00b0ea80();
    __forceinline ~OtherRegistry()
    {
        ReleaseEntries_00b0ea80();
    }
};
void CIdvBezierSpline_ClearCache();
static __forceinline void Pad5()
{
    int dq[5];
}
static __forceinline void Pad8()
{
    int dq[8];
}

template <class T> __forceinline void deleteResource(T* p)
{
    delete p;
}
__forceinline void** findPointer(void** first, void** last, void* const& value)
{
    for (; first != last; ++first)
    {
        if (*first == value)
            break;
    }
    return first;
}
__forceinline void** checkedBase(const RegistryIterator& it)
{
    int hq;
    return it.base();
}
__forceinline void helperAssign(RegistryIterator& it, void** p)
{
    it.setCur(p);
}
__forceinline void assignFromBase(RegistryIterator& it, void** const& src)
{
    helperAssign(it, src);
}
__forceinline RegistryIterator findResource(RegistryIterator first, RegistryIterator last, void* const& value)
{
    assignFromBase(first, findPointer(checkedBase(first), checkedBase(last), value));
    return first;
}
struct SpeedTreeRelease
{
    VirtualResource* geometry;
    BranchResource* branches;
    LeafResource* leaves;
    void* m0c;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    void* m20;
    void* m24;
    void* m28;
    void* m2c;
    int* references;
    void* instance;
    Registry* instances;
    void* m3c;
    void* m40;
    void* m44;
    void* m48;
    LodResource* lod;
    StringResource* strings;
    void* m54;
    OtherRegistry* other;
    BillboardResource* billboards;
    BranchResource* extraBranches;
    void* m64;
    void* m68;
    void CSpeedTreeRT_DeleteTransientData();
    void ReleaseStorage_00b03b30();
};
// @fnv 0x00b03b30
// src: GUESS 0x00b03b30 (confidence: low)
void SpeedTreeRelease::ReleaseStorage_00b03b30()
{
    if (instance == 0)
    {
        EnterCriticalSection(&DAT_011f8bc4);
        RegistryIterator found = findResource(reinterpret_cast<Registry&>(DAT_011f8bdc).begin(),
                                              reinterpret_cast<Registry&>(DAT_011f8bdc).end(), this);
        if (found != reinterpret_cast<Registry&>(DAT_011f8bdc).end())
            reinterpret_cast<Registry&>(DAT_011f8bdc).std_vector_erase(found);
        Pad5();
        LeaveCriticalSection(&DAT_011f8bc4);
    }
    --*references;
    if (instance != 0)
    {
        RegistryIterator found = findResource(instances->begin(), instances->end(), this);
        instances->std_vector_erase(found);
        Pad5();
        delete (TreeResource*)instance;
        instance = 0;
    }
    if (*references == 0)
    {
        CSpeedTreeRT_DeleteTransientData();
        delete branches;
        delete (TreeResource*)m0c;
        delete (TreeResource*)m10;
        delete leaves;
        delete (TreeResource*)m14;
        delete geometry;
        delete (TreeResource*)references;
        delete instances;
        delete (TreeResource*)m40;
        delete other;
        delete lod;
        delete billboards;
        delete extraBranches;
        delete (TreeResource*)m2c;
        delete strings;
        delete (TreeResource*)m68;
    }
    branches = 0;
    m0c = 0;
    m10 = 0;
    leaves = 0;
    m14 = 0;
    geometry = 0;
    references = 0;
    m40 = 0;
    instances = 0;
    other = 0;
    lod = 0;
    billboards = 0;
    extraBranches = 0;
    m2c = 0;
    strings = 0;
    m68 = 0;
    if (--DAT_011f8b7c == 0)
        CIdvBezierSpline_ClearCache();
    Pad8();
}

extern "C" void __cdecl _invalid_parameter_noinfo();

struct TreeContainer;
struct TreeAux
{
    const TreeContainer* container;
    const TreeContainer* Get() const
    {
        return container;
    }
};
struct TreeContainer
{
    TreeAux* ownedAux;
};
struct TreeIteratorBase
{
    TreeAux* aux;
    TreeIteratorBase() : aux(0)
    {}
    void SetContainer(const TreeContainer* container)
    {
        aux = container->ownedAux;
    }
    const TreeContainer* GetContainer() const
    {
        return aux == 0 ? 0 : aux->Get();
    }
    bool IsContainerSet() const
    {
        return aux != 0;
    }
    bool SameContainer(const TreeIteratorBase& other) const
    {
        return aux == other.aux;
    }
};
struct TreeFloatVector;
struct TreeConstIterator : TreeIteratorBase
{
    float* ptr;
    TreeConstIterator(float* p, const TreeContainer* container);
    bool operator==(const TreeConstIterator& other) const
    {
        if (!(IsContainerSet() && SameContainer(other)))
        {
            _invalid_parameter_noinfo();
        }
        return ptr == other.ptr;
    }
    bool operator!=(const TreeConstIterator& other) const
    {
        return !(*this == other);
    }
};
struct TreeIterator : TreeConstIterator
{
    TreeIterator(float* p, const TreeContainer* container) : TreeConstIterator(p, container)
    {}
};
struct TreeScalarTag
{
};
struct TreeRandomTag
{
};
struct TreeCheckedTag
{
};
struct TreeUnchangedTag
{
};
template <class T, class U> inline TreeScalarTag TreePointerCategory(T&, U&)
{
    TreeScalarTag category;
    return category;
}
template <class T, class U> inline TreeRandomTag TreeIteratorCategory(const T&, const U&)
{
    TreeRandomTag category;
    return category;
}
template <class T> inline T TreeCheckedBase(T& iterator, TreeUnchangedTag)
{
    return iterator;
}
template <class T> inline T TreeCheckedBase(T& iterator)
{
    TreeUnchangedTag tag;
    return TreeCheckedBase(iterator, tag);
}
extern "C" int __cdecl memmove_s(void*, unsigned int, const void*, unsigned int);
template <class In, class Out, class Category>
inline Out TreeCopyOpt(In first, In last, Out destination, Category, TreeScalarTag, TreeCheckedTag)
{
    int offset = last - first;
    Out result = destination + offset;
    if (offset > 0)
        memmove_s(&*destination, offset * sizeof(*first), &*first, offset * sizeof(*first));
    return result;
}
template <class In, class Out> inline Out TreeUncheckedCopy(In first, In last, Out destination)
{
    return TreeCopyOpt(TreeCheckedBase(first), TreeCheckedBase(last), destination,
                       TreeIteratorCategory(first, destination), TreePointerCategory(first, destination),
                       TreeCheckedTag());
}
template <class Allocator> inline void TreeDestroyRange(float* first, float* last, Allocator& allocator, TreeScalarTag)
{}
template <class Allocator> inline void TreeDestroyRange(float* first, float* last, Allocator& allocator)
{
    TreeDestroyRange(first, last, allocator, TreePointerCategory(first, last));
}
struct TreeAuxAllocator : TreeContainer
{
    std::allocator<TreeAux> auxAllocator;
};
struct TreeFloatAllocator : TreeAuxAllocator
{
    std::allocator<float> allocator;
};
struct TreeFloatVector : TreeFloatAllocator
{
    float* first;
    float* last;
    float* end;
    TreeIterator Begin()
    {
        return TreeIterator(first, this);
    }
    TreeIterator End()
    {
        return TreeIterator(last, this);
    }
    TreeIterator MakeIterator(TreeConstIterator where) const
    {
        return TreeIterator(where.ptr, this);
    }
    void Destroy(float* first, float* last)
    {
        TreeDestroyRange(first, last, allocator);
    }
    TreeIterator Erase(TreeConstIterator firstArg, TreeConstIterator lastArg)
    {
        TreeIterator first = MakeIterator(firstArg);
        TreeIterator last = MakeIterator(lastArg);
        if (first != last)
        {
            float* next = TreeUncheckedCopy(last.ptr, this->last, first.ptr);
            Destroy(next, this->last);
            this->last = next;
        }
        return first;
    }
// src: COMMUNITY 0x0044a0a0
    void std_vector_float_std_allocator_float_clear()
    {
        Erase(Begin(), End());
    }
};
inline TreeConstIterator::TreeConstIterator(float* p, const TreeContainer* container)
{
    if (!(container != 0 && ((const TreeFloatVector*)container)->first <= p &&
          p <= ((const TreeFloatVector*)container)->last))
    {
        _invalid_parameter_noinfo();
    }
    SetContainer(container);
    ptr = p;
}

extern "C" int __cdecl memcpy_s(void*, unsigned int, const void*, unsigned int);
void __cdecl operator delete(void*);
struct TreeCharAllocator
{
    void deallocate(char* p, unsigned int count)
    {
        ::operator delete(p);
    }
};
struct TreeSecureTraitsTag
{
};
template <class Traits> inline TreeSecureTraitsTag TreeTraitsCategory()
{
    TreeSecureTraitsTag secure;
    return secure;
}
struct TreeCharTraits
{
    typedef char char_type;
    static char* Copy(char* destination, unsigned int size, const char* source, unsigned int count)
    {
        memcpy_s(destination, size, source, count);
        return destination;
    }
    static void Assign(char& destination, const char& value)
    {
        destination = value;
    }
};
template <class Traits>
inline char* TreeStringCopy(char* destination, unsigned int size, const char* source, unsigned int count,
                            TreeSecureTraitsTag)
{
    return Traits::Copy(destination, size, source, count);
}
template <class Traits>
inline char* TreeStringCopy(char* destination, unsigned int size, const char* source, unsigned int count)
{
    return TreeStringCopy<Traits>(destination, size, source, count, TreeTraitsCategory<Traits>());
}
struct TreeString
{
    TreeCharAllocator allocator;
    union Storage
    {
        char chars[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
    char* Data()
    {
        return 16 <= capacity ? storage.pointer : storage.chars;
    }
    void EndString(unsigned int count)
    {
        TreeCharTraits::Assign(Data()[length = count], char());
    }
// src: XBOX_PDB 0x0044a730
    void fopen_0044a730(bool built = false, unsigned int count = 0)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            char* pointer = storage.pointer;
            if (0 < count)
                TreeStringCopy<TreeCharTraits>(storage.chars, 16, pointer, count);
            allocator.deallocate(pointer, capacity + 1);
        }
        capacity = 15;
        EndString(count);
    }
    ~TreeString()
    {
        fopen_0044a730(true, 0);
    }
};

struct TreeGeomQ
{
    int u000, u004, u008, u00c, u010, u014, u018, u01c, u020, u024, u028, u02c, u030, u034, u038, u03c, u040, u044,
        u048, u04c, u050, u054, u058, u05c, u060, u064, u068, u06c, u070, u074, u078, u07c, u080, u084, u088, u08c,
        u090, u094, u098, u09c, u0a0, u0a4, u0a8, u0ac, u0b0, u0b4, u0b8, u0bc, u0c0, u0c4, u0c8, u0cc, u0d0, u0d4,
        u0d8, u0dc, u0e0, u0e4, u0e8, u0ec, u0f0, u0f4, u0f8, u0fc, u100, u104, u108, u10c, u110, u114, u118, u11c,
        u120, u124, u128, u12c, u130, u134, u138, u13c, u140, u144;
    TreeFloatVector vec;
    void Release()
    {
        vec.std_vector_float_std_allocator_float_clear();
    }
};


struct EmbeddedTex
{
    int u000, u004, u008, u00c, u010, u014, u018, u01c, u020;
    TreeString value;
    void operator delete(void* p)
    {
        ((MemoryManager*)&DAT_011f6238)->Deallocate(p);
    }
};

struct TreeRuntimeQ
{
    int unk00;
    TreeGeomQ* unk04;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44,
        unk48, unk4c;
    EmbeddedTex* unk50;
    int unk54, unk58, unk5c;
    TreeGeomQ* unk60;
    void __thiscall ReleaseStorage_00b087d0();
};

// @fnv 0x00b087d0
// src: GUESS 0x00b087d0 (confidence: low)
void __thiscall TreeRuntimeQ::ReleaseStorage_00b087d0()
{
    if (this->unk50 != 0)
    {
        delete this->unk50;
        this->unk50 = 0;
    }
    if (this->unk04 != 0)
    {
        this->unk04->Release();
    }
    if (this->unk60 != 0)
    {
        this->unk60->Release();
    }
}

namespace fnv_00b08cc0 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}

inline void __cdecl AssignString(const char* s)
{
    int d0, d1, d2, d3;
    for (int i = 0; i < 1; ++i)
    {
        d0 = d1 + d2 + d3;
    }
    d1 = d0 + d2 + d3;
    d2 = d1 + d3 + d0;
    d3 = d2 + d0 + d1;
    d0 = d3 + d1 + d2;
    d1 = d0 + d2 + d3;
    d2 = d1 + d3 + d0;
    d3 = d2 + d0 + d1;
    d0 = d3 + d1 + (int)s;
}

namespace st {
struct TreeEngine
{
    int unk00;
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
    int unk6c;
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
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int m_ec;
};
struct LightingEngine
{
    void CLightingEngine_ComputeLeafStaticLighting(const CVec3& center, int a, unsigned short n);
};
struct CSpeedTreeRT
{
    TreeEngine* m_pFirstPointer;
    void* m_04;
    void* m_08;
    LightingEngine* m_pLighting;
    void CSpeedTreeRT_GetBoundingBox_00b08c80(float* box);
    unsigned short GetNumLeafLodLevels();
    void ComputeLeafStaticLighting();
};

// @fnv 0x00b08cc0
// src: EXE 0x00b08cc0
void CSpeedTreeRT::ComputeLeafStaticLighting()
{
    int a;
    try
    {
        float box2[6];
        CSpeedTreeRT_GetBoundingBox_00b08c80(box2);
        CVec3 center5((box2[0] + box2[3]) * 0.5, (box2[1] + box2[4]) * 0.5, (box2[2] + box2[5]) * 0.5);
        a = m_pFirstPointer->m_ec;
        m_pLighting->CLightingEngine_ComputeLeafStaticLighting(center5, a, GetNumLeafLodLevels());
    }
    catch (std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::ComputeLeafStaticLighting", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(
            IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::ComputeLeafStaticLighting").c_str());
    }
}
}
}  // namespace fnv_00b08cc0

namespace fnv_00b0ab20 {
namespace std {
class exception
{
  public:
    exception();
    virtual ~exception();
    virtual const char* what() const;
};
}

// FUN_00b09270 is defined in this translation unit (error logger); under /Ob1
// the compiler attempts to inline it at both catch sites and declines the
// expansion, which is what reserves the dead slots the original frame shows.
inline void AssignString(const char* s)
{
    int d0, d1, d2, d3;
    d0 = (int)(s != 0);
    d1 = d0;
    d2 = d1;
    d3 = d2;
    for (int i = 0; i < 1; ++i)
    {
        d0 = d1 + d2 + d3;
    }
    d1 = d0;
    d2 = d1;
    d3 = d2;
    d0 = d3;
    d1 = d0;
    d2 = d1;
    d3 = d2;
    d0 = d1;
}

struct SpeedTreeImpl
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68;
    unsigned char unk6c;

    void CSpeedTreeRT_GetBranchGeometry(void* m_pShaderGeometry, unsigned short nBranchLodLevel);
    void FillFrondGeometry(void* m_pShaderGeometry, unsigned short nFrondLodLevel);
    void CSpeedTreeRT_GetLeafGeometry(void* m_pShaderGeometry, unsigned short nLeafLodLevel);
    void CSpeedTreeRT_Get360BillboardGeometry(void* m_pShaderGeometry, unsigned long ulGeometryFlags);
    void FillSpeedTreeOutput(void* m_pShaderGeometry);

    void CSpeedTreeRT_GetGeometry(void* m_pShaderGeometry, unsigned long ulGeometryFlags, unsigned short nBranchLodLevel,
                      unsigned short nFrondLodLevel, unsigned short nLeafLodLevel);
};

// @fnv 0x00b0ab20
// src: EXE 0x00b0ab20
void SpeedTreeImpl::CSpeedTreeRT_GetGeometry(void* m_pShaderGeometry, unsigned long ulGeometryFlags, unsigned short nBranchLodLevel,
                                 unsigned short nFrondLodLevel, unsigned short nLeafLodLevel)
{
    try
    {
        if (ulGeometryFlags & 1)
        {
            this->CSpeedTreeRT_GetBranchGeometry(m_pShaderGeometry, nBranchLodLevel);
        }
        if (ulGeometryFlags & 2)
        {
            this->FillFrondGeometry(m_pShaderGeometry, nFrondLodLevel);
        }
        if (ulGeometryFlags & 4)
        {
            this->CSpeedTreeRT_GetLeafGeometry(m_pShaderGeometry, nLeafLodLevel);
        }
        if (ulGeometryFlags & 8)
        {
            if (this->unk6c && !(ulGeometryFlags & 0x10))
            {
                this->CSpeedTreeRT_Get360BillboardGeometry(m_pShaderGeometry, ulGeometryFlags);
            }
            else
            {
                this->FillSpeedTreeOutput(m_pShaderGeometry);
            }
        }
    }
    catch (const std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::GetGeometry", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::GetGeometry").c_str());
    }
}
}  // namespace fnv_00b0ab20

struct TreeFileReader
{
    int GetNextElement();
    StrQ CTreeFileAccess_ParseString();
};

struct UserDataOwner : FUN_00b0d5d0_Class
{
    void CSpeedTreeRT_ParseUserData(TreeFileReader* pFile);
};

// @fnv 0x00b0d500
// src: COMMUNITY 0x00b0d500
void UserDataOwner::CSpeedTreeRT_ParseUserData(TreeFileReader* pFile)
{
    int token = pFile->GetNextElement();
    do
    {
        switch (token)
        {
        case 0x4a3a:
            m_unk_68 = (int)DuplicateString(pFile->CTreeFileAccess_ParseString().c_str());
            Dead5Q();
            break;
        }
        token = pFile->GetNextElement();
    } while (token != 0x4a39);
}

namespace fnv_00b08ec0 {
namespace std {
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
};
}

void std_Traits_helper_copy_s_std_char_traits_char(char*, unsigned, const char*, unsigned);

struct ErrorStringView
{
    int m_pContainerProxy;
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;

    bool std_basic_string_char_std_char_traits_char_std_allocator_char_Grow(unsigned count, bool trim = false);
    void ResizeString(unsigned count);
    ErrorStringView& AssignSubstring(const ErrorStringView& other, unsigned offset, unsigned count);
    char* myptr()
    {
        return _Myres >= 16 ? _Bx._Ptr : _Bx._Buf;
    }
    bool inside(const char* p)
    {
        if (!p || p < myptr() || myptr() + _Mysize <= p)
            return false;
        else
            return true;
    }
    const char* c_str() const
    {
        return _Myres >= 16 ? _Bx._Ptr : _Bx._Buf;
    }
};

extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);
extern int DAT_011f8be8;
extern int DAT_011f8bec;

struct BranchModeView
{
    void* GetFieldAt0C();
};
struct LeafModeView
{
    void* GetNestedPointer();
};

struct FUN_00b10430_class
{
    void __thiscall SetCheckedRangeIndex(unsigned int node, void* tree);
};

struct FUN_00b0ec20_class
{
    void __thiscall ProcessEntries_00b0ec20();
};

struct FUN_00b0eca0_class
{
    bool __thiscall ProcessEntries_00b0eca0(void* other);
};

struct FUN_00b0ebb0_class
{
    FUN_00b076c0_Class** __thiscall ProcessEntries_00b0ebb0();
};

struct TreeUpdateRecord
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    bool dirty;
    int unk40;
    void reset()
    {
        dirty = false;
    }
};

struct FUN_00b27820_class
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24;
    unsigned short count;
    unsigned short unk2a;
    TreeUpdateRecord* records;
// src: COMMUNITY 0x00b27820
    void CLeafGeometry_Invalidate()
    {
        if (records)
        {
            for (int index = 0; index < count; ++index)
            {
                if (records[index].dirty)
                    records[index].dirty = false;
            }
        }
    }
};

struct UnkSub04
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    short unk10;
    unsigned char byte12;
};

struct UnkSub60
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    short unk10;
    unsigned char byte12;
};

struct UnkSub10
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    bool byte14;
};

struct UnkSub14
{
    int unk00;
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
    unsigned char byte30;
};

__forceinline UnkSub04* field_m04(FUN_00b076c0_Class* obj)
{
    return (UnkSub04*)obj->m04;
}

__forceinline UnkSub60* field_m60(FUN_00b076c0_Class* obj)
{
    return (UnkSub60*)obj->m60;
}

__forceinline UnkSub14* field_m14(FUN_00b076c0_Class* obj)
{
    return (UnkSub14*)obj->m14;
}

__forceinline unsigned char field_byte14(FUN_00b076c0_Class* obj)
{
    unsigned char c = ((UnkSub10*)obj->m10)->byte14;
    return c;
}

struct Iterator
{
    int m_node;
    int m_uiEdgeIndex;

    __forceinline Iterator(unsigned int node, void* tree)
    {
        ((FUN_00b10430_class*)this)->SetCheckedRangeIndex(node, tree);
    }

    __forceinline void operator++()
    {
        ((FUN_00b0ec20_class*)this)->ProcessEntries_00b0ec20();
    }

    __forceinline bool operator!=(const Iterator& other) const
    {
        return !((FUN_00b0eca0_class*)this)->ProcessEntries_00b0eca0((void*)&other);
    }

    __forceinline FUN_00b076c0_Class** operator*() const
    {
        return ((FUN_00b0ebb0_class*)this)->ProcessEntries_00b0ebb0();
    }
};

inline void AssignString(const char* s)
{
    ErrorStringView& target = *(ErrorStringView*)&DAT_011f8ba4;
    unsigned count = _strlen(s);
    if (target.inside(s))
    {
        target.AssignSubstring(target, s - target.myptr(), count);
    }
    else if (target.std_basic_string_char_std_char_traits_char_std_allocator_char_Grow(count))
    {
        char* destination = target.myptr();
        for (unsigned index = 0; index < count; ++index)
            destination[index] = s[index];
        target.ResizeString(count);
    }
}

// @fnv 0x00b08ec0
// src: EXE 0x00b08ec0
void CSpeedTreeRT_NotifyAllTreesOfEvent(int param_1)
{
    try
    {
        DAT_00fdf05c(&DAT_011f8bc4);
        for (Iterator it(DAT_011f8be8, &DAT_011f8bdc); it != Iterator(DAT_011f8bec, &DAT_011f8bdc); ++it)
        {
            if (param_1 == 0)
            {
                if ((**it)->fun_00b076c0() == (void*)1)
                {
                    field_m04(**it)->byte12 = 0;
                }
                if (((BranchModeView*)(**it))->GetFieldAt0C() == (void*)1)
                {
                    field_m60(**it)->byte12 = 0;
                }
                if (((LeafModeView*)(**it))->GetNestedPointer() == (void*)1 || field_byte14(**it))
                {
                    ((FUN_00b27820_class*)(**it)->m08)->CLeafGeometry_Invalidate();
                }
            }
            else if (param_1 == 1)
            {
                ((FUN_00b27820_class*)(**it)->m08)->CLeafGeometry_Invalidate();
                field_m14(**it)->byte30 = 0;
            }
        }
        DAT_00fdf100(&DAT_011f8bc4);
    }
    catch (const std::exception& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::NotifyAllTreesOfEvent", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(
            IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::NotifyAllTreesOfEvent").c_str());
    }
}
}  // namespace fnv_00b08ec0

namespace CloneFormatting {
struct String
{
    CharAllocB05130 allocator;
    union
    {
        char chars[16];
        char* pointer;
    } storage;
    unsigned length, capacity;
    char* data()
    {
        return 16 <= capacity ? storage.pointer : storage.chars;
    }
    void end(unsigned n)
    {
        TraitsB05130::assign(data()[length = n], char());
    }
    const char* c_str() const
    {
        return 16 <= capacity ? storage.pointer : storage.chars;
    }
    ~String()
    {
        fopen_0044a730(true, 0);
    }
// src: XBOX_PDB 0x0044a730
    void fopen_0044a730(bool built, unsigned n)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            char* pointer = storage.pointer;
            if (0 < n)
                CopySB05130(storage.chars, 16, pointer, n);
            allocator.deallocate(pointer, capacity + 1);
        }
        capacity = 15;
        end(n);
    }
};
String __cdecl IdvFormatString(const char* format, ...);
}

void* __cdecl FUN_00ec44d0(void*, const void*, unsigned int);
void __cdecl AssignString(const char* s);
struct IdvException
{
    virtual ~IdvException();
    virtual const char* what() const;
};
extern int DAT_011f8b7c;

struct InnerQ
{
    int i0;
    LocalVec3 v;
};
struct FUN_00b036d0;
struct WrapQ
{
    static void* operator new(unsigned int n, MemoryManager& h)
    {
        return h.Allocate(n);
    }
    static void operator delete(void*, MemoryManager&)
    {}
    FUN_00b036d0* pTree;
    LocalVec3 kPos;
    float fScale;
    WrapQ() : pTree(0)
    {
        fScale = 1.0f;
    }
};
struct ListQ : VecQ_acad60
{
// src: COMMUNITY 0x00b0ddc0
    void std_vector_push_back(void* const& value)
    {
        unsigned count = size();
        if (count < capacity())
        {
            int* destination = _Mylast;
            Runtime_ProcessState_00b36b10(destination, 1, reinterpret_cast<const int&>(value));
            _Mylast = destination + 1;
        }
        else
        {
            ItQ_acad60 where = end();
            ProcessAndReturnValue_00b0e600(where, reinterpret_cast<const int&>(value));
        }
    }
};
struct FUN_00b036d0
{
    InnerQ* m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    float f1c, f20, f24, f28;
    int m2c;
    int* m30;
    WrapQ* m34;
    ListQ* m38;
    int m3c;
    int m40;
    bool b44, b45;
    int m48;
    int m4c;
    int m50;
    short s54;
    int m58;
    int m5c;
    int m60;
    short s64;
    int m68;
    bool b6c, b6d;
    int a70[12];
    float CSpeedTreeRT_GetLodLevel();
    FUN_00b036d0(FUN_00b036d0* pNewInstance);
};
// @fnv 0x00b036d0
FUN_00b036d0::FUN_00b036d0(FUN_00b036d0* pNewInstance)
    : m00(pNewInstance->m00), m04(pNewInstance->m04), m08(pNewInstance->m08), m0c(pNewInstance->m0c), m10(pNewInstance->m10), m14(pNewInstance->m14),
      m18(pNewInstance->m18), f1c(pNewInstance->f1c), f20(pNewInstance->f20), f24(pNewInstance->f24), f28(pNewInstance->f28), m2c(pNewInstance->m2c),
      m30(pNewInstance->m30), m38(pNewInstance->m38), m3c(pNewInstance->m3c), m40(pNewInstance->m40), b44(pNewInstance->b44), b45(pNewInstance->b45),
      m48(pNewInstance->m48), m4c(pNewInstance->m4c), m50(pNewInstance->m50), s54(pNewInstance->s54), m58(pNewInstance->m58), m5c(pNewInstance->m5c),
      m60(pNewInstance->m60), s64(pNewInstance->s64), m68(pNewInstance->m68), b6c(pNewInstance->b6c), b6d(pNewInstance->b6d)
{
    try
    {
        m38->std_vector_push_back(this);
        FUN_00ec44d0(a70, pNewInstance->a70, 0x30);
        *m30 = *m30 + 1;
        m34 = new (DAT_011f6238) WrapQ;
        m34->pTree = pNewInstance;
        memcpy(&m34->kPos, &pNewInstance->m00->v, sizeof(m34->kPos));
        m34->fScale = pNewInstance->CSpeedTreeRT_GetLodLevel();
        DAT_011f8b7c++;
    }
    catch (IdvException& e)
    {
        AssignString(
            CloneFormatting::IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::CSpeedTreeRT(CSpeedTreeRT*)", e.what())
                .c_str());
    }
    catch (...)
    {
        AssignString(CloneFormatting::IdvFormatString("%s - threw an unknown system exception",
                                                   "CSpeedTreeRT::CSpeedTreeRT(CSpeedTreeRT*)")
                         .c_str());
    }
}

namespace fnv_00b0d040 {
extern "C" int __cdecl memcpy_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
namespace stdb07 {
struct _Secure_char_traits_tag
{
};
template <class _Elem> struct char_traits
{
    typedef _Elem char_type;
    typedef _Secure_char_traits_tag _Secure_char_traits;
    static void assign(_Elem& _Left, const _Elem& _Right)
    {
        _Left = _Right;
    }
    static _Elem* _Copy_s(_Elem* _First1, unsigned int _Dest_size, const _Elem* _First2, unsigned int _Count)
    {
        memcpy_s(_First1, _Dest_size, _First2, _Count);
        return _First1;
    }
};
template <class _Traits> struct _Char_traits_category
{
    typedef typename _Traits::_Secure_char_traits _Secure_char_traits;
};
template <class _Traits> inline typename _Char_traits_category<_Traits>::_Secure_char_traits _Char_traits_cat()
{
    typename _Char_traits_category<_Traits>::_Secure_char_traits _Secure;
    return (_Secure);
}
namespace _Traits_helper {
template <class _Traits>
inline typename _Traits::char_type* copy_s(typename _Traits::char_type* _First1, unsigned int _Size,
                                           const typename _Traits::char_type* _First2, unsigned int _Count,
                                           _Secure_char_traits_tag)
{
    return _Traits::_Copy_s(_First1, _Size, _First2, _Count);
}
template <class _Traits>
inline typename _Traits::char_type* copy_s(typename _Traits::char_type* _First1, unsigned int _Size,
                                           const typename _Traits::char_type* _First2, unsigned int _Count)
{
    return copy_s<_Traits>(_First1, _Size, _First2, _Count, _Char_traits_cat<_Traits>());
}
}

void __cdecl operator delete(void*);
template <class _Ty> class allocator
{
  public:
    allocator() throw()
    {}
    allocator(const allocator<_Ty>&) throw()
    {}
    void deallocate(_Ty* _Ptr, unsigned int)
    {
        ::operator delete(_Ptr);
    }
};
template <class _Ty, class _Alloc> class _String_val
{
  protected:
    _String_val(_Alloc _Al = _Alloc()) : _Alval(_Al)
    {}
    _Alloc _Alval;
};
template <class _Elem, class _Traits, class _Ax> class basic_string : public _String_val<_Elem, _Ax>
{
  public:
    basic_string(const basic_string& _Right);
    const _Elem* c_str() const
    {
        return (_Myptr());
    }
    ~basic_string()
    {
        _Tidy(true);
    }
    union
    {
        _Elem _Buf[16];
        _Elem* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;

  protected:
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
            ;
        else if (16 <= _Myres)
        {
            _Elem* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
                _Traits_helper::copy_s<_Traits>(_Bx._Buf, 16, _Ptr, _Newsize);
            this->_Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Eos(unsigned int _Newsize)
    {
        _Traits::assign(_Myptr()[_Mysize = _Newsize], _Elem());
    }
    _Elem* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const _Elem* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern "C" void __cdecl _invalid_parameter_noinfo(void);
namespace stdb07 {
template <class _Ty> class vector
{
  public:
    unsigned int size() const
    {
        return (_Mylast - _Myfirst);
    }
    _Ty& operator[](unsigned int _Pos)
    {
        {
            if (!(_Pos < size()))
            {
                ((void)0);
                ::_invalid_parameter_noinfo();
            }
            do
            {
            } while (0);
        }
        return (*(_Myfirst + _Pos));
    }
    void* _Myownedaux;
    int _Alaux;
    char _Alval;
    _Ty* _Myfirst;
    _Ty* _Mylast;
    _Ty* _Myend;
};
}

class ExceptionB07
{
  public:
    virtual ~ExceptionB07();
    virtual const char* what() const;
};

extern MemoryManager g_kMemoryManagerD04;

inline void* operator new[](unsigned int uiSize)
{
    return g_kMemoryManagerD04.Allocate(uiSize);
}

stdb07::string __cdecl IdvFormatString(const char* pcFormat, ...);
void __cdecl AssignString(const char* pcError);

struct SLeafTextureD04
{
    char m_acPad[0x14];
    stdb07::string m_kLeafTextureFilename;
    char m_acPad2[0x54 - 0x30];
};

// Local 0x2c-byte frond texture definition retained: include/SFrondTexture.h is not available.
struct SFrondTexture
{
    stdb07::string m_kLeafTextureFilename;
    char m_acPad[0x2c - 0x1c];
};

class FrondsD04
{
  public:
    const char* GetTextureResourceName(unsigned int uiIndex)
    {
        return m_kFrondTextures[uiIndex].m_kLeafTextureFilename.c_str();
    }
    char m_acPad[0x50];
    stdb07::vector<SFrondTexture> m_kFrondTextures;
};

class TreeD04
{
  public:
    char m_acPad[0x24];
    stdb07::string m_strBranchTexture;
    char m_acPad2[0xa4 - 0x40];
    stdb07::vector<SLeafTextureD04> m_kLeafTextureList;
};

class SelfShadowD04
{
  public:
    char m_acPad[0x18];
    stdb07::string m_kLeafTextureFilename;
};

class CompositeD04
{
  public:
    char m_acPad[0x24];
    stdb07::string m_kLeafTextureFilename;
};

struct STexturesD04
{
    const char* m_pBranchTextureFile;
    unsigned int m_uiLeafTextureFilenameCount;
    const char** m_ppLeafTextureFilenames;
    unsigned int m_uiFrondTextureFilenameCount;
    const char** m_ppFrondTextureFilenames;
    const char* m_pCompositeTextureFilename;
    const char* m_pSelfShadowTextureFilename;
};

// Local CSpeedTreeRT definition retained: include/CSpeedTreeRT.h is not available.
class CSpeedTreeRT
{
  public:
    void GetTextures_00b0d040(STexturesD04& sTextures);
    TreeD04* m_pLeafTreeRuntime;
    char m_acPad[0x4c - 4];
    SelfShadowD04* m_pSelfShadow;
    CompositeD04* m_pComposite;
    char m_acPad2[0x5c - 0x54];
    FrondsD04* m_pFronds;
};

// @fnv 0x00b0d040
// src: EXE 0x00b0d040
void CSpeedTreeRT::GetTextures_00b0d040(STexturesD04& sTextures)
{
    try
    {
        sTextures.m_pBranchTextureFile = m_pLeafTreeRuntime->m_strBranchTexture.c_str();
        stdb07::vector<SLeafTextureD04>& vLeafTextures = m_pLeafTreeRuntime->m_kLeafTextureList;
        sTextures.m_uiLeafTextureFilenameCount = vLeafTextures.size();
        if (sTextures.m_uiLeafTextureFilenameCount > 0)
        {
            sTextures.m_ppLeafTextureFilenames = new const char*[sTextures.m_uiLeafTextureFilenameCount];
            for (unsigned int i = 0; i < vLeafTextures.size(); ++i)
                sTextures.m_ppLeafTextureFilenames[i] = vLeafTextures[i].m_kLeafTextureFilename.c_str();
        }
        else
        {
            sTextures.m_ppLeafTextureFilenames = 0;
        }
        sTextures.m_uiFrondTextureFilenameCount = m_pFronds->m_kFrondTextures.size();
        if (sTextures.m_uiFrondTextureFilenameCount > 0)
        {
            sTextures.m_ppFrondTextureFilenames = new const char*[sTextures.m_uiFrondTextureFilenameCount];
            for (unsigned int i = 0; i < sTextures.m_uiFrondTextureFilenameCount; ++i)
                sTextures.m_ppFrondTextureFilenames[i] = m_pFronds->GetTextureResourceName(i);
        }
        else
        {
            sTextures.m_ppFrondTextureFilenames = 0;
        }
        if (m_pComposite)
            sTextures.m_pSelfShadowTextureFilename = m_pComposite->m_kLeafTextureFilename.c_str();
        if (m_pSelfShadow)
            sTextures.m_pCompositeTextureFilename = m_pSelfShadow->m_kLeafTextureFilename.c_str();
    }
    catch (ExceptionB07& e)
    {
        AssignString(IdvFormatString("%s - failed [%s]", "CSpeedTreeRT::GetTextures", e.what()).c_str());
    }
    catch (...)
    {
        AssignString(IdvFormatString("%s - threw an unknown system exception", "CSpeedTreeRT::GetTextures").c_str());
    }
}
}  // namespace fnv_00b0d040
