
// src/gamebryo2.2/corelibs/nimain/nibillboardnode_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nibillboardnode.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

class NiRTTI;
class NiBillboardNode
{
  public:
    static const NiRTTI ms_kRTTI;
    virtual const NiRTTI* GetRTTI() const;
};

struct NiUpdateData
{
    float m_fTime;
};
struct NiNode
{
    virtual void UpdateSelectedDownwardPass(NiUpdateData&, unsigned int);
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
};
struct UnkBoard : NiNode
{
    void FUN_00a7da80(NiUpdateData&, unsigned int);
};
// @fnv 0x00a7da80
void UnkBoard::FUN_00a7da80(NiUpdateData& a, unsigned int b)
{
    *(float*)((char*)this + 0xB0) = a.m_fTime;
    NiNode::UpdateSelectedDownwardPass(a, b);
    f47();
}

namespace fnv_00a7dab0 {
struct NiUpdateData
{
    float m_fTime;
};
struct BaseNode
{
    void FUN_00a5e1f0(NiUpdateData&, unsigned int);
};
struct StandIn
{
    void FUN_00a7dab0(NiUpdateData&, unsigned int);
};
// @fnv 0x00a7dab0
void StandIn::FUN_00a7dab0(NiUpdateData& UpdateData, unsigned int uFlags)
{
    *(float*)((char*)this + 0xb0) = UpdateData.m_fTime;
    ((BaseNode*)this)->FUN_00a5e1f0(UpdateData, uFlags);
    ((void(__thiscall**)(void*)) * (void***)this)[47](this);
}
}  // namespace fnv_00a7dab0

class NiCullingProcess;
struct DummyNode
{
    void FUN_00a5dbe0(NiCullingProcess*);
};
struct FUN_00a7de40_shell
{
    void RotateToCamera(NiCullingProcess*);
};
struct FUN_00a7e610_shell : NiBillboardNode
{
    void FUN_00a7e610(NiCullingProcess* process);
};
// @fnv 0x00a7e610
void FUN_00a7e610_shell::FUN_00a7e610(NiCullingProcess* process)
{
    ((FUN_00a7de40_shell*)this)->RotateToCamera(*(NiCullingProcess**)((char*)process + 0xc));
    ((DummyNode*)this)->FUN_00a5dbe0(process);
}

struct NiAVObject
{
    virtual void Dummy()
    {}
    NiAVObject();
    char _pad[0x98];
};
struct GlobalObject_004aff00
{
    GlobalObject_004aff00(int, int);
};
struct FUN_00a5ecb0 : NiAVObject
{
    GlobalObject_004aff00 m;
    FUN_00a5ecb0(unsigned int uiNumChildren);
};
// @fnv 0x00a5ecb0
FUN_00a5ecb0::FUN_00a5ecb0(unsigned int uiNumChildren) : m(uiNumChildren, 1)
{}

namespace fnv_00a7dae0 {
struct NiUpdateData
{
    float m_fTime;
    bool m_bUpdate;
};
struct NiNode
{
    virtual void F00() = 0;
    virtual void F01() = 0;
    virtual void F02() = 0;
    virtual void F03() = 0;
    virtual void F04() = 0;
    virtual void F05() = 0;
    virtual void F06() = 0;
    virtual void F07() = 0;
    virtual void F08() = 0;
    virtual void F09() = 0;
    virtual void F10() = 0;
    virtual void F11() = 0;
    virtual void F12() = 0;
    virtual void F13() = 0;
    virtual void F14() = 0;
    virtual void F15() = 0;
    virtual void F16() = 0;
    virtual void F17() = 0;
    virtual void F18() = 0;
    virtual void F19() = 0;
    virtual void F20() = 0;
    virtual void F21() = 0;
    virtual void F22() = 0;
    virtual void F23() = 0;
    virtual void F24() = 0;
    virtual void F25() = 0;
    virtual void F26() = 0;
    virtual void F27() = 0;
    virtual void F28() = 0;
    virtual void F29() = 0;
    virtual void F30() = 0;
    virtual void F31() = 0;
    virtual void F32() = 0;
    virtual void F33() = 0;
    virtual void F34() = 0;
    virtual void F35() = 0;
    virtual void F36() = 0;
    virtual void F37() = 0;
    virtual void F38() = 0;
    virtual void F39() = 0;
    virtual void F40() = 0;
    virtual void F41() = 0;
    virtual void F42() = 0;
    virtual void F43() = 0;
    virtual void F44() = 0;
    virtual void F45() = 0;
    virtual void F46() = 0;
    virtual void F47() = 0;
    char _pad[0xA8];
    unsigned short m_flags;
    char _pad2[2];
    float m_uiCommandId;
    void UpdateDownwardPass(NiUpdateData&, unsigned int);
    void FUN_00a7dae0(NiUpdateData&, unsigned int);
};
// @fnv 0x00a7dae0
void NiNode::FUN_00a7dae0(NiUpdateData& UpdateData, unsigned int uFlags)
{
    m_uiCommandId = UpdateData.m_fTime;
    if (UpdateData.m_bUpdate)
        m_flags |= 8;
    else
        m_flags &= 0xFFF7;
    NiNode::UpdateDownwardPass(UpdateData, uFlags);
    F47();
}
}  // namespace fnv_00a7dae0

class NiObject;
struct BaseForCall
{
    bool FUN_00a5e600(NiObject* pkObject);
};
struct MyNode
{
    char _pad[0xAD];
    unsigned char FUN_00a7db30(NiObject* pkObject);
};
// @fnv 0x00a7db30
unsigned char MyNode::FUN_00a7db30(NiObject* pkObject)
{
    NiBillboardNode* pkNode = (NiBillboardNode*)pkObject;
    if (!((BaseForCall*)this)->FUN_00a5e600(pkObject))
        return 0;
    return ((((unsigned char*)pkNode)[0xAC] ^ ((unsigned char*)this)[0xAC]) & 7) == 0;
}

struct NiBinaryStream
{
    int _m0;
    int m_pos;
    void* m_pfnRead;
    int(__cdecl* m_pfnWrite)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
};
struct NiStream
{
    char _pad[592];
    NiBinaryStream* m_pBackingStream;
};
struct NiNodeBase
{
    void FUN_00a5e880(NiStream&);
};
struct StandIn
{
    char _pad[172];
    short m_field;
    void FUN_00a7e850(NiStream&);
};
// @fnv 0x00a7e850
void StandIn::FUN_00a7e850(NiStream& kStream)
{
    ((NiNodeBase*)this)->FUN_00a5e880(kStream);
    NiBinaryStream* __restrict pkOstr = kStream.m_pBackingStream;
    unsigned int size = 2;
    pkOstr->m_pos += pkOstr->m_pfnWrite(pkOstr, &m_field, 2, &size, 1);
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float fx, float fy, float afDepth) : x(fx), y(fy), z(afDepth)
    {}
    NiPoint3 operator-(const NiPoint3& p) const
    {
        return NiPoint3(x - p.x, y - p.y, z - p.z);
    }
    NiPoint3 operator-() const
    {
        return NiPoint3(-x, -y, -z);
    }
    float operator*(const NiPoint3& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    float SqrLength() const
    {
        return y * y + x * x + z * z;
    }
    void Unitize();
    NiPoint3 Cross(const NiPoint3& p) const;
};

struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
    NiPoint3 GetCol(int c) const
    {
        return NiPoint3(m_afEntries[0][c], m_afEntries[1][c], m_afEntries[2][c]);
    }
    void MakeAxisAngleRotation(float angle, float x, float y, float z);
    NiPoint3 operator*(const NiPoint3& p) const;
};

float NiACos(float f);
inline float SqrLength3(float a, float b, float c)
{
    return a * a + b * b + c * c;
}

struct NiCameraStandIn
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
    ThreeByThreeMatrix m_kWorldRotate;
    NiPoint3 m_kWorldTranslate;
};

// @fnv 0x00a7dc40
bool __stdcall FUN_00a7dc40(NiCameraStandIn* pkCamera, const NiPoint3& kPos, NiPoint3& kWorldPosition, NiPoint3& kUp,
                            NiPoint3& kRight)
{
    NiPoint3 kDelta = pkCamera->m_kWorldTranslate - kPos;
    float fLenSq = SqrLength3(kDelta.x, kDelta.y, kDelta.z);
    if (fLenSq < 0.001f)
        return false;

    kDelta.Unitize();
    kWorldPosition = -pkCamera->m_kWorldRotate.GetCol(0);
    kUp = pkCamera->m_kWorldRotate.GetCol(1);
    kRight = pkCamera->m_kWorldRotate.GetCol(2);

    float fDot = kWorldPosition * kDelta;
    if (fDot < (double)0.999999f)
    {
        ThreeByThreeMatrix kRot;
        {
            NiPoint3 kAxis = kDelta.Cross(kWorldPosition);
            kRot.MakeAxisAngleRotation(NiACos(fDot), kAxis.x, kAxis.y, kAxis.z);
        }
        kWorldPosition = kDelta;
        kUp = kRot * kUp;
        kRight = kRot * kRight;
    }
    return true;
}

struct NiBinaryStreamStandIn
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void SetEndianSwap(bool bSwap);

    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamStandIn* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
    template <class T> unsigned int Read(T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryRead(pValue, sizeof(T), &uiSize, 1);
    }
};

struct NiStreamImpl
{
    char pad[0xd8];
    unsigned int m_uiFileVersion;
    char pad2[0x24c - 0xdc];
    NiBinaryStreamStandIn* m_pUnderlyingStream;
    char pad3[0x284 - 0x250];
    unsigned short m_usOldFlags;
    unsigned int GetFileVersion() const
    {
        return m_uiFileVersion;
    }
};

template <class T> inline void ReadBinaryValue(NiStreamImpl& stream, T& value)
{
    stream.m_pUnderlyingStream->Read(&value);
}

class Prop
{
  public:
    char unk00[0xac];
    unsigned short m_usFlags;

    void FUN_00a5dd40(NiStreamImpl& stream);
    void FUN_00a7e7b0(NiStreamImpl& stream);
};

// @fnv 0x00a7e7b0
void Prop::FUN_00a7e7b0(NiStreamImpl& stream)
{
    FUN_00a5dd40(stream);
    if (stream.GetFileVersion() < 0x0a000102)
    {
        m_usFlags = stream.m_usOldFlags;
        if (stream.GetFileVersion() < 0x04020003)
        {
            unsigned short us = m_usFlags;
            m_usFlags = (m_usFlags & 0xe000) << 1;
            m_usFlags |= us & 0x1fff;
        }
        m_usFlags >>= 6;
    }
    else
    {
        ReadBinaryValue(stream, m_usFlags);
    }
    m_usFlags |= 8;
}

extern "C" double __cdecl sqrt(double x);

class NiMemManagerA7E
{
  public:
    void* Allocate(unsigned int uiSize);
};

extern NiMemManagerA7E g_kMemManagerA7E;

class NiPoint3A7E
{
  public:
    float x, y, z;

    static const NiPoint3A7E ZERO;

    NiPoint3A7E operator-(const NiPoint3A7E& pt) const
    {
        NiPoint3A7E kResult;
        kResult.x = x - pt.x;
        kResult.y = y - pt.y;
        kResult.z = z - pt.z;
        return kResult;
    }

    float Length() const;
};

inline float NiSqrtA7E(float fValue)
{
    return (float)sqrt(fValue);
}

inline float NiPoint3A7E::Length() const
{
    return NiSqrtA7E(x * x + (y * y) + z * z);
}

class NiBoundA7E
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return g_kMemManagerA7E.Allocate(uiSize);
    }

    NiPoint3A7E m_kCenter;
    float m_fBoundRadius;

    void SetCenterAndRadius(const NiPoint3A7E& kTargetCenter, float fRadius)
    {
        m_kCenter = kTargetCenter;
        m_fBoundRadius = fRadius;
    }
};

class NiNodeA7E
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6C();
    virtual void vfn70();
    virtual void vfn74();
    virtual void SetWorldBound(NiBoundA7E* pkBound);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NiBoundA7E* m_pkWorldBound;
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
    NiPoint3A7E m_kWorldTranslate;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    unsigned short m_usChildCount;

    void FUN_00a7e630();
};

// @fnv 0x00a7e630
void NiNodeA7E::FUN_00a7e630()
{
    if (!m_usChildCount)
        return;

    if (!m_pkWorldBound)
    {
        SetWorldBound(new NiBoundA7E);
        m_pkWorldBound->SetCenterAndRadius(NiPoint3A7E::ZERO, 0.0f);
    }

    NiPoint3A7E kDiff = m_pkWorldBound->m_kCenter - m_kWorldTranslate;
    float fRadius = m_pkWorldBound->m_fBoundRadius;
    m_pkWorldBound->SetCenterAndRadius(m_kWorldTranslate, kDiff.Length() + fRadius);
}

struct StrArr
{
    int unk;
    int unkCur;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short unk0c;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, char*& element);
    void Add(char* element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
    }
};

struct FUN_00a5ea70_t
{
    void FUN_00a5ea70(StrArr* array);
};

class GlobalObjectO2_00a7b610
{
  public:
    char* m_pString;
};
extern GlobalObjectO2_00a7b610 g_011f4aa0;
char* __cdecl FUN_00a7d330(char* value);
char* __cdecl FUN_00a7db60(const char* pName, unsigned int uiValue);

struct PropTarget : Prop
{
    void FUN_00a7e890(StrArr* array);
};

// @fnv 0x00a7e890
void PropTarget::FUN_00a7e890(StrArr* array)
{
    ((FUN_00a5ea70_t*)this)->FUN_00a5ea70(array);
    array->Add(FUN_00a7d330(g_011f4aa0.m_pString));
    unsigned int uiFlags = m_usFlags & 7;
    array->Add(FUN_00a7db60("m_eMode", uiFlags));
}

extern "C" unsigned int __cdecl strlen(const char* s);

void* __cdecl FUN_00aa1070(unsigned int size);
int __cdecl FUN_00a305b0(char* buffer, unsigned int size, const char* format, ...);

// @fnv 0x00a7db60
char* __cdecl FUN_00a7db60(const char* name, int type)
{
    unsigned int size = strlen(name) + 0x16;
    char* buffer = (char*)FUN_00aa1070(size);
    switch (type)
    {
    case 0:
        FUN_00a305b0(buffer, size, "%s = ALWAYS_FACE_CAMERA", name);
        break;
    case 1:
        FUN_00a305b0(buffer, size, "%s = ROTATE_ABOUT_UP", name);
        break;
    case 2:
        FUN_00a305b0(buffer, size, "%s = RIGID_FACE_CAMERA", name);
        break;
    case 3:
        FUN_00a305b0(buffer, size, "%s = ALWAYS_FACE_CENTER", name);
        break;
    case 4:
        FUN_00a305b0(buffer, size, "%s = RIGID_FACE_CENTER", name);
        break;
    case 5:
        FUN_00a305b0(buffer, size, "%s = BSROTATE_ABOUT_UP", name);
        break;
    }
    return buffer;
}

#include <math.h>
inline float BoardRootFloat(float v)
{
    return (float)sqrt(v);
}
struct XY
{
    float x, y;
};
struct BoardVector : XY
{
    float z;
    void Negate(BoardVector& out) const
    {
        out.x = -x;
        out.y = -y;
        out.z = -z;
    }
    __declspec(noalias) void FUN_0053d280(BoardVector&, float) const;
};
inline float LengthPair(float a, float b)
{
    return (float)sqrt((double)(float)(a * a + b * b));
}
struct BoardMatrix : ThreeByThreeMatrix
{
    void GetColumn(unsigned int column, BoardVector& v) const
    {
        v.x = m_afEntries[0][column];
        v.y = m_afEntries[1][column];
        v.z = m_afEntries[2][column];
    }
    void SetColumn(unsigned int column, const BoardVector& v)
    {
        m_afEntries[0][column] = v.x;
        m_afEntries[1][column] = v.y;
        m_afEntries[2][column] = v.z;
    }
    void Identity()
    {
        float& e00 = m_afEntries[0][0];
        float& e01 = m_afEntries[0][1];
        float& e02 = m_afEntries[0][2];
        float& e10 = m_afEntries[1][0];
        float& e11 = m_afEntries[1][1];
        float& e12 = m_afEntries[1][2];
        float& e20 = m_afEntries[2][0];
        float& e21 = m_afEntries[2][1];
        float& e22 = m_afEntries[2][2];
        e00 = 1.0f;
        e10 = 0.0f;
        e20 = 0.0f;
        e01 = 0.0f;
        e21 = 0.0f;
        e11 = 1.0f;
        e02 = 0.0f;
        e12 = 0.0f;
        e22 = 1.0f;
    }
    BoardMatrix* FUN_0043f8d0(BoardMatrix*, const BoardMatrix&) const;
};
__declspec(noalias) BoardVector* FUN_004b3ae0(BoardVector*, const BoardVector&, const BoardMatrix&);
struct BoardTransform
{
    BoardMatrix rotate;
    BoardVector translate;
    float scale;
    void FUN_00a86bf0();
    BoardTransform* FUN_0062c250(BoardTransform*, const BoardTransform&) const;
};
extern const BoardMatrix DAT_011a9448;
extern const float DAT_010959f4 = 1.0e-6f;
extern const float DAT_0109deb8 = 1.0e-12f;
struct BoardUpdate
{
    float time;
    bool updateControllers, dirty, unk06, unk07, unk08;
};
struct BillboardResults
{
    BoardUpdate update;
    BoardVector up03, dir24, right03, dir5, right24, dir03, dir1, up24;
};
struct DirectionLength
{
    BoardVector kWorldPosition;
    union
    {
        float fScaleMultiplier, fInvLength, fSin;
    };
};
inline void LengthInPlace(float& value, float a, float b)
{
    value = a * a + b * b;
    value = (float)sqrt((double)value);
    static_cast<volatile float&>(value) = static_cast<const volatile float&>(value);
}
inline float RoundTo(float& out, float value)
{
    out = value;
    return out;
}
inline float CopyScalar(float value)
{
    return value;
}
union CompositionResult
{
    BoardTransform composed;
    BoardMatrix product;
};
struct BoardObject
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Update(BoardUpdate&, unsigned int);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    BoardObject* parent;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    BoardTransform local, world;
    unsigned int unk9C;
    BoardObject** children;
    unsigned short capacity, count;
    unsigned int unkA8;
    unsigned short flags, unkAE;
    float time;
    __declspec(noalias) bool FUN_00a7dc40(const BoardObject*, const BoardVector&, BoardVector&, BoardVector&,
                                          BoardVector&);
    void RotateToCamera(const BoardObject*);
};
// @fnv 0x00a7de40
void BoardObject::RotateToCamera(const BoardObject* camera)
{
    CompositionResult composition;
    BillboardResults results;
    BoardTransform kParentWorld;
    if (parent)
        kParentWorld = parent->world;
    else
        kParentWorld.FUN_00a86bf0();
    world = *kParentWorld.FUN_0062c250(&composition.composed, local);
    unsigned int mode = flags & 7;
    BoardMatrix kRot = DAT_011a9448;
    DirectionLength work;
    BoardVector& kWorldPosition = work.kWorldPosition;
    float& fScaleMultiplier = work.fScaleMultiplier;
    BoardVector kRight, kUp, kTmp;
    switch (mode)
    {
    case 0:
    case 3:
        if (mode == 3)
        {
            if (!FUN_00a7dc40(camera, world.translate, kWorldPosition, kUp, kRight))
                break;
        }
        else
        {
            camera->world.rotate.GetColumn(0, kWorldPosition);
            kWorldPosition.Negate(kUp);
            kWorldPosition = kUp;
            camera->world.rotate.GetColumn(1, kRight);
            kUp = kRight;
            camera->world.rotate.GetColumn(2, kTmp);
            kRight = kTmp;
        }
        kWorldPosition = (*FUN_004b3ae0(&results.dir03, kWorldPosition, world.rotate));
        kUp = (*FUN_004b3ae0(&results.up03, kUp, world.rotate));
        kRight = (*FUN_004b3ae0(&results.right03, kRight, world.rotate));
        LengthInPlace(fScaleMultiplier, kUp.y, kRight.y);
        if (fScaleMultiplier > DAT_010959f4)
        {
            float& fInvLength = work.fInvLength;
            fInvLength = 1.0f / fScaleMultiplier;
            float fCos;
            fCos = fInvLength * kUp.y;
            float fSin = (work.fSin = fInvLength * -kRight.y);
            kRot.m_afEntries[0][0] = fSin * kUp.x + fCos * kRight.x;
            kRot.m_afEntries[1][0] = fSin * kUp.y + fCos * kRight.y;
            kRot.m_afEntries[2][0] = fSin * kUp.z + fCos * kRight.z;
            kRot.m_afEntries[0][1] = fCos * kUp.x - fSin * kRight.x;
            kRot.m_afEntries[1][1] = fCos * kUp.y - fSin * kRight.y;
            kRot.m_afEntries[2][1] = fCos * kUp.z - fSin * kRight.z;
        }
        else
        {
            kTmp.x = -kRight.x;
            kTmp.y = -kRight.y;
            kTmp.z = -kRight.z;
            kRot.SetColumn(0, kTmp);
            kTmp.x = -kUp.x;
            kTmp.y = -kUp.y;
            kTmp.z = -kUp.z;
            kRot.SetColumn(1, kTmp);
        }
        kRot.SetColumn(2, kWorldPosition);
        break;
    case 1:
        kTmp.x = camera->world.translate.x - world.translate.x;
        kTmp.y = camera->world.translate.y - world.translate.y;
        kTmp.z = camera->world.translate.z - world.translate.z;
        (*FUN_004b3ae0(&results.dir1, kTmp, world.rotate)).FUN_0053d280(kWorldPosition, world.scale);
        fScaleMultiplier = BoardRootFloat(kWorldPosition.x * kWorldPosition.x + kWorldPosition.z * kWorldPosition.z);
        if (!(fScaleMultiplier < DAT_0109deb8))
        {
            fScaleMultiplier = 1.0f / fScaleMultiplier;
            kWorldPosition.x = fScaleMultiplier * static_cast<const volatile float&>(kWorldPosition.x);
            kWorldPosition.z = fScaleMultiplier * kWorldPosition.z;
            kRot.m_afEntries[0][0] = kWorldPosition.z;
            kRot.m_afEntries[1][0] = 0;
            kRot.m_afEntries[2][0] = -kWorldPosition.x;
            kRot.m_afEntries[0][1] = 0;
            kRot.m_afEntries[1][1] = 1;
            kRot.m_afEntries[2][1] = 0;
            kRot.m_afEntries[1][2] = 0;
            kRot.m_afEntries[0][2] = kWorldPosition.x;
            kRot.m_afEntries[2][2] = kWorldPosition.z;
        }
        break;
    case 2:
    case 4:
        if (mode == 4)
        {
            if (!FUN_00a7dc40(camera, world.translate, kRight, kUp, kWorldPosition))
                break;
        }
        else
        {
            camera->world.rotate.GetColumn(0, kTmp);
            kTmp.Negate(kWorldPosition);
            kRight = kWorldPosition;
            camera->world.rotate.GetColumn(1, kTmp);
            kUp = kTmp;
            camera->world.rotate.GetColumn(2, kTmp);
            kWorldPosition = kTmp;
        }
        kRight = (*FUN_004b3ae0(&results.right24, kRight, world.rotate));
        kUp = (*FUN_004b3ae0(&results.up24, kUp, world.rotate));
        kWorldPosition = (*FUN_004b3ae0(&results.dir24, kWorldPosition, world.rotate));
        kRot.SetColumn(0, kWorldPosition);
        kRot.SetColumn(1, kUp);
        kRot.SetColumn(2, kRight);
        break;
    case 5:
        world.rotate.Identity();
        kTmp.x = camera->world.translate.x - world.translate.x;
        kTmp.y = camera->world.translate.y - world.translate.y;
        kTmp.z = camera->world.translate.z - world.translate.z;
        (*FUN_004b3ae0(&results.dir5, kTmp, world.rotate)).FUN_0053d280(kWorldPosition, world.scale);
        double vy = kWorldPosition.y;
        double vx = kWorldPosition.x;
        fScaleMultiplier = BoardRootFloat((float)(vx * vx + vy * vy));
        if (!(fScaleMultiplier < DAT_0109deb8))
        {
            fScaleMultiplier = 1.0f / fScaleMultiplier;
            kWorldPosition.x = fScaleMultiplier * static_cast<const volatile float&>(kWorldPosition.x);
            kWorldPosition.y = fScaleMultiplier * kWorldPosition.y;
            kRot.m_afEntries[0][0] = -kWorldPosition.y;
            kRot.m_afEntries[1][0] = kWorldPosition.x;
            kRot.m_afEntries[2][0] = 0;
            kRot.m_afEntries[2][1] = 0;
            kRot.m_afEntries[0][2] = 0;
            kRot.m_afEntries[1][2] = 0;
            kRot.m_afEntries[0][1] = kWorldPosition.x;
            kRot.m_afEntries[1][1] = kWorldPosition.y;
            kRot.m_afEntries[2][2] = 1;
        }
        break;
    }
    world.rotate = *world.rotate.FUN_0043f8d0(&composition.product, kRot);
    BoardUpdate& kUpdate = results.update;
    kUpdate.time = time;
    kUpdate.updateControllers = (flags & 8) != 0;
    kUpdate.dirty = false;
    kUpdate.unk06 = false;
    kUpdate.unk07 = false;
    kUpdate.unk08 = false;
    for (unsigned int i = 0; i < count; ++i)
    {
        BoardObject* child = children[i];
        if (child)
            child->Update(kUpdate, 0);
    }
}

void* __cdecl FUN_00aa13e0(unsigned int bytes);

struct BillboardCloneBaseCall
{
    void FUN_00a5ecb0(unsigned int childCount);
};

extern const void* DAT_0102bf44[];

struct BillboardCloneVptr
{
    const void** vtable;
};

struct BillboardClone : StandIn
{
    float m_uiFilterValue;

    static void* __cdecl operator new(unsigned int, void* storage)
    {
        return storage;
    }

    __forceinline BillboardClone()
    {
        ((BillboardCloneBaseCall*)this)->FUN_00a5ecb0(0);
        m_uiFilterValue = 0.0f;
        ((BillboardCloneVptr*)this)->vtable = DAT_0102bf44;
        m_field = 9;
    }
};

struct BillboardCloneSource : StandIn
{
    void FUN_00a5dc80(BillboardClone* dest, void* context);
    BillboardClone* FUN_00a7e710(void* context);
};

// @fnv 0x00a7e710
BillboardClone* BillboardCloneSource::FUN_00a7e710(void* context)
{
    void* storage = FUN_00aa13e0(sizeof(BillboardClone));
    BillboardClone* clone = storage ? new (storage) BillboardClone() : 0;
    FUN_00a5dc80(clone, context);
    clone->m_field = m_field;
    return clone;
}
