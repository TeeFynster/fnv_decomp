#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiBillboardNode.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiMatrix3.h"

inline NiPoint3::NiPoint3(float fx, float fy, float fz) : x(fx), y(fy), z(fz) {}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& p) const
{
    NiPoint3 result;
    result.x = x - p.x;
    result.y = y - p.y;
    result.z = z - p.z;
    return result;
}
inline NiPoint3 NiPoint3::operator-() const { return NiPoint3(-x,-y,-z); }
inline float NiPoint3::operator*(const NiPoint3& p) const { return x*p.x+y*p.y+z*p.z; }
// Column c of a NiMatrix3 returned by value (inlined here; the shared NiMatrix3 has only GetCol(uiCol, NiPoint3&)).
struct NiMatrix3_ColView : public NiMatrix3
{
    NiPoint3 GetCol(int c) const
    { return NiPoint3((&m_pEntry[0][0])[c], (&m_pEntry[0][0])[3+c], (&m_pEntry[0][0])[6+c]); }
};
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#pragma intrinsic(memcpy)
// The shared stream declarations omit the position and transfer callback fields.
inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int read = (*(ReadFunction volatile*)((char*)this + 8))(this, buffer, bytes, sizes, count);
    *(unsigned int*)((char*)this + 4) += read;
    return read;
}
template <class T> inline void NiBinaryStream::Read(T& value)
{
    unsigned int size = sizeof(T);
    BinaryRead(&value, sizeof(T), &size, 1);
}
inline void AddViewerString(StrArr* array, char* element)
{
    unsigned int index = array->m_usSize;
    if (index >= array->m_usMaxSize) array->SetSize(index + array->m_usGrowBy);
    array->SetAt(index, element);
}

// src/gamebryo2.2/corelibs/nimain/nibillboardnode_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nibillboardnode.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// @fnv 0x00a7da80
void NiBillboardNode::FUN_00a7da80(NiUpdateData& a, unsigned int b)
{
    *(float*)&unkB0 = a.fTime;
    NiNode::UpdateSelectedDownwardPass(a, b);
    UpdateWorldBound();
}

// @fnv 0x00a7dab0
void NiBillboardNode::FUN_00a7dab0(NiUpdateData& data, unsigned int flags)
{
    *(float*)&unkB0 = data.fTime;
    NiNode::UpdateRigidDownwardPass(data, flags);
    UpdateWorldBound();
}

// @fnv 0x00a7e610
void NiBillboardNode::FUN_00a7e610(NiCullingProcess* process)
{
    RotateToCamera(*(NiCullingProcess**)((char*)process + 0xc));
    NiNode::OnVisible(*process);
}

// The shared NiNode lacks the unsigned-int constructor. Initialize its shared
// layout here, retaining the original thiscall entry point without a local NiNode.
inline void* __cdecl operator new(unsigned int, void* storage)
{
    __assume(storage != 0);
    return storage;
}
// The shared child array has no constructor declaration for this entry point.
void __fastcall InitializeChildArray(void* storage, void*, unsigned int count, unsigned int growBy);
extern const void* DAT_0109b5ac[];
// The unused second register lets a free function receive this in ECX.
// @fnv 0x00a5ecb0
__declspec(noinline) NiNode* __fastcall InitializeNiNode(NiNode* node, void*, unsigned int uiNumChildren)
{
    ::new ((void*)node) NiAVObject;
    *(const void***)node = DAT_0109b5ac;
    typedef void (__thiscall* ArrayConstructor)(void*, unsigned int, unsigned int);
    ((ArrayConstructor)InitializeChildArray)(&node->m_kChildren, uiNumChildren, 1);
    return node;
}

// @fnv 0x00a7dae0
void NiBillboardNode::FUN_00a7dae0(NiUpdateData& data, unsigned int flags)
{
    *(float*)&unkB0 = data.fTime;
    unsigned short& billboardFlags = *(unsigned short*)&unkAC;
    if (*(bool*)((char*)&data + 4))
        billboardFlags |= 8;
    else
        billboardFlags &= 0xFFF7;
    NiNode::UpdateDownwardPass(data, flags);
    UpdateWorldBound();
}

// @fnv 0x00a7db30
unsigned char NiBillboardNode::FUN_00a7db30(NiObject* object)
{
    NiBillboardNode* node = (NiBillboardNode*)object;
    if (!NiNode::IsEqual(object))
        return 0;
    return ((((unsigned char*)&node->unkAC)[0] ^ ((unsigned char*)&unkAC)[0]) & 7) == 0;
}

// @fnv 0x00a7e850
void NiBillboardNode::FUN_00a7e850(NiStream& stream)
{
    NiNode::SaveBinary(stream);
    NiBinaryStream* __restrict output = *(NiBinaryStream**)((char*)&stream + 0x250);
    unsigned int size = 2;
    *(unsigned int*)((char*)output + 4) += (*(NiBinaryStream::WriteFunction*)((char*)output + 12))(output, &unkAC, 2, &size, 1);
}

float NiACos(float f);
inline float SqrLength3(float a, float b, float c)
{
    return a * a + b * b + c * c;
}

// @fnv 0x00a7dc40
bool __stdcall FUN_00a7dc40(const NiAVObject* pkCamera, const NiPoint3& kPos, NiPoint3& kWorldPosition, NiPoint3& kUp,
                            NiPoint3& kRight)
{
    NiPoint3 kDelta = pkCamera->m_kWorld.m_Translate - kPos;
    float fLenSq = SqrLength3(kDelta.x, kDelta.y, kDelta.z);
    if (fLenSq < 0.001f)
        return false;

    kDelta.Unitize();
    kWorldPosition = -((const NiMatrix3_ColView&)pkCamera->m_kWorld.m_Rotate).GetCol(0);
    kUp = ((const NiMatrix3_ColView&)pkCamera->m_kWorld.m_Rotate).GetCol(1);
    kRight = ((const NiMatrix3_ColView&)pkCamera->m_kWorld.m_Rotate).GetCol(2);

    float fDot = kWorldPosition * kDelta;
    if (fDot < (double)0.999999f)
    {
        float rotationStorage[sizeof(NiMatrix3) / sizeof(float)];
        NiMatrix3& kRot = *(NiMatrix3*)rotationStorage;
        {
            NiPoint3 kAxis = kDelta.FUN_0053d1a0(kWorldPosition);
            kRot.MakeRotation(NiACos(fDot), kAxis.x, kAxis.y, kAxis.z);
        }
        kWorldPosition = kDelta;
        kUp = ((const NiMatrix3&)kRot) * kUp;
        kRight = ((const NiMatrix3&)kRot) * kRight;
    }
    return true;
}

template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    NiBinaryStream* __restrict input = *(NiBinaryStream**)((char*)&stream + 0x24c);
    input->Read(value);
}

// @fnv 0x00a7e7b0
void NiBillboardNode::FUN_00a7e7b0(NiStream& stream)
{
    NiNode::LoadBinary(stream);
#define m_usFlags (*(unsigned short*)&unkAC)
    if (*(const unsigned int*)((const char*)&stream + 0xd8) < 0x0a000102)
    {
        m_usFlags = *(unsigned short*)((char*)&stream + 0x284);
        if (*(const unsigned int*)((const char*)&stream + 0xd8) < 0x04020003)
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
#undef m_usFlags
}

extern "C" double __cdecl sqrt(double x);

// Allocate at 0x00aa3e40 and the singleton at 0x011f6238 bind to MemoryManager in bscore/memorymanager.cpp.
extern MemoryManager g_memoryManager;

inline float BoundRootFloat(float value)
{
    return (float)sqrt(value);
}

inline float NiPoint3::Length() const
{
    return BoundRootFloat(x * x + (y * y) + z * z);
}

inline void NiBound::SetCenterAndRadius(const NiPoint3& center, float radius)
{
    m_kCenter = center;
    m_fRadius = radius;
}

// @fnv 0x00a7e630
void NiBillboardNode::FUN_00a7e630()
{
#define m_pkWorldBound (*(NiBound**)&m_kWorldBound)
#define m_kWorldTranslate m_kWorld.m_Translate
    if (!m_kChildren.m_usESize)
        return;

    if (!m_pkWorldBound)
    {
        NiBound* bound = (NiBound*)g_memoryManager.Allocate(sizeof(NiBound));
        SetObjectBound(bound);
        m_pkWorldBound->SetCenterAndRadius(NiPoint3::ZERO, 0.0f);
    }

    NiPoint3 kDiff = m_pkWorldBound->m_kCenter - m_kWorldTranslate;
    float fRadius = m_pkWorldBound->m_fBoundRadius;
    m_pkWorldBound->SetCenterAndRadius(m_kWorldTranslate, ((const NiPoint3&)kDiff).Length() + fRadius);
#undef m_pkWorldBound
#undef m_kWorldTranslate
}

class GlobalObjectO2_00a7b610
{
  public:
    char* m_pString;
};
extern GlobalObjectO2_00a7b610 g_011f4aa0;
char* __cdecl FUN_00a7d330(char* value);
char* __cdecl FUN_00a7db60(const char* pName, unsigned int uiValue);

// @fnv 0x00a7e890
void NiBillboardNode::FUN_00a7e890(StrArr* array)
{
    NiNode::GetViewerStrings((NiViewerStringsArray*)array);
    AddViewerString(array, FUN_00a7d330(g_011f4aa0.m_pString));
    unsigned int uiFlags = *(unsigned short*)&unkAC & 7;
    AddViewerString(array, FUN_00a7db60("m_eMode", uiFlags));
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
struct BoardMatrix : NiMatrix3
{
    void GetColumn(unsigned int column, BoardVector& v) const
    {
        v.x = (&m_pEntry[0][0])[0 + column];
        v.y = (&m_pEntry[0][0])[3 + column];
        v.z = (&m_pEntry[0][0])[6 + column];
    }
    void SetColumn(unsigned int column, const BoardVector& v)
    {
        (&m_pEntry[0][0])[0 + column] = v.x;
        (&m_pEntry[0][0])[3 + column] = v.y;
        (&m_pEntry[0][0])[6 + column] = v.z;
    }
    void Identity()
    {
        float& e00 = m_pEntry[0][0];
        float& e01 = m_pEntry[0][1];
        float& e02 = m_pEntry[0][2];
        float& e10 = m_pEntry[1][0];
        float& e11 = m_pEntry[1][1];
        float& e12 = m_pEntry[1][2];
        float& e20 = m_pEntry[2][0];
        float& e21 = m_pEntry[2][1];
        float& e22 = m_pEntry[2][2];
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
__forceinline NiUpdateData::NiUpdateData() {}
struct BillboardResults
{
    NiUpdateData update;
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
struct CompositionResult
{
    float storage[sizeof(BoardTransform) / sizeof(float)];
};
// @fnv 0x00a7de40
void NiBillboardNode::RotateToCamera(const BoardObject* cameraObject)
{
    const NiAVObject* camera = (const NiAVObject*)cameraObject;
#define world (*(BoardTransform*)&m_kWorld)
#define local (*(BoardTransform*)&m_kLocal)
#define flags (*(unsigned short*)&unkAC)
    CompositionResult composition;
    BillboardResults results;
    float parentStorage[sizeof(BoardTransform) / sizeof(float)];
    BoardTransform& kParentWorld = *(BoardTransform*)parentStorage;
    if (m_pkParent)
        kParentWorld = *(BoardTransform*)&m_pkParent->m_kWorld;
    else
        kParentWorld.FUN_00a86bf0();
    world = *kParentWorld.FUN_0062c250((BoardTransform*)&composition, local);
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
            if (!FUN_00a7dc40(cameraObject, world.translate, kWorldPosition, kUp, kRight))
                break;
        }
        else
        {
            ((const BoardTransform&)camera->m_kWorld).rotate.GetColumn(0, kWorldPosition);
            kWorldPosition.Negate(kUp);
            kWorldPosition = kUp;
            ((const BoardTransform&)camera->m_kWorld).rotate.GetColumn(1, kRight);
            kUp = kRight;
            ((const BoardTransform&)camera->m_kWorld).rotate.GetColumn(2, kTmp);
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
            kRot.m_pEntry[0][0] = fSin * kUp.x + fCos * kRight.x;
            kRot.m_pEntry[1][0] = fSin * kUp.y + fCos * kRight.y;
            kRot.m_pEntry[2][0] = fCos * kRight.z + fSin * kUp.z;
            kRot.m_pEntry[0][1] = fCos * kUp.x - fSin * kRight.x;
            kRot.m_pEntry[1][1] = fCos * kUp.y - fSin * kRight.y;
            kRot.m_pEntry[2][1] = fCos * kUp.z - fSin * kRight.z;
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
        kTmp.x = camera->m_kWorld.m_Translate.x - world.translate.x;
        kTmp.y = camera->m_kWorld.m_Translate.y - world.translate.y;
        kTmp.z = camera->m_kWorld.m_Translate.z - world.translate.z;
        (*FUN_004b3ae0(&results.dir1, kTmp, world.rotate)).FUN_0053d280(kWorldPosition, world.scale);
        fScaleMultiplier = BoardRootFloat(kWorldPosition.x * kWorldPosition.x + kWorldPosition.z * kWorldPosition.z);
        if (!(fScaleMultiplier < DAT_0109deb8))
        {
            fScaleMultiplier = 1.0f / fScaleMultiplier;
            kWorldPosition.x = fScaleMultiplier * static_cast<const volatile float&>(kWorldPosition.x);
            kWorldPosition.z = fScaleMultiplier * kWorldPosition.z;
            kRot.m_pEntry[0][0] = kWorldPosition.z;
            kRot.m_pEntry[1][0] = 0;
            kRot.m_pEntry[2][0] = -kWorldPosition.x;
            kRot.m_pEntry[0][1] = 0;
            kRot.m_pEntry[1][1] = 1;
            kRot.m_pEntry[2][1] = 0;
            kRot.m_pEntry[1][2] = 0;
            kRot.m_pEntry[0][2] = kWorldPosition.x;
            kRot.m_pEntry[2][2] = kWorldPosition.z;
        }
        break;
    case 2:
    case 4:
        if (mode == 4)
        {
            if (!FUN_00a7dc40(cameraObject, world.translate, kRight, kUp, kWorldPosition))
                break;
        }
        else
        {
            ((const BoardTransform&)camera->m_kWorld).rotate.GetColumn(0, kTmp);
            kTmp.Negate(kWorldPosition);
            kRight = kWorldPosition;
            ((const BoardTransform&)camera->m_kWorld).rotate.GetColumn(1, kTmp);
            kUp = kTmp;
            ((const BoardTransform&)camera->m_kWorld).rotate.GetColumn(2, kTmp);
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
        kTmp.x = camera->m_kWorld.m_Translate.x - world.translate.x;
        kTmp.y = camera->m_kWorld.m_Translate.y - world.translate.y;
        kTmp.z = camera->m_kWorld.m_Translate.z - world.translate.z;
        (*FUN_004b3ae0(&results.dir5, kTmp, world.rotate)).FUN_0053d280(kWorldPosition, world.scale);
        double vy = kWorldPosition.y;
        double vx = kWorldPosition.x;
        fScaleMultiplier = BoardRootFloat((float)(vx * vx + vy * vy));
        if (!(fScaleMultiplier < DAT_0109deb8))
        {
            fScaleMultiplier = 1.0f / fScaleMultiplier;
            kWorldPosition.x = fScaleMultiplier * static_cast<const volatile float&>(kWorldPosition.x);
            kWorldPosition.y = fScaleMultiplier * kWorldPosition.y;
            kRot.m_pEntry[0][0] = -kWorldPosition.y;
            kRot.m_pEntry[1][0] = kWorldPosition.x;
            kRot.m_pEntry[2][0] = 0;
            kRot.m_pEntry[2][1] = 0;
            kRot.m_pEntry[0][2] = 0;
            kRot.m_pEntry[1][2] = 0;
            kRot.m_pEntry[0][1] = kWorldPosition.x;
            kRot.m_pEntry[1][1] = kWorldPosition.y;
            kRot.m_pEntry[2][2] = 1;
        }
        break;
    }
    world.rotate = *world.rotate.FUN_0043f8d0((BoardMatrix*)&composition, kRot);
    NiUpdateData& kUpdate = results.update;
    kUpdate.fTime = *(float*)&unkB0;
    *(bool*)((char*)&kUpdate + 4) = (flags & 8) != 0;
    *(bool*)((char*)&kUpdate + 5) = false;
    *(bool*)((char*)&kUpdate + 6) = false;
    *(bool*)((char*)&kUpdate + 7) = false;
    *(bool*)((char*)&kUpdate + 8) = false;
    for (unsigned int i = 0; i < m_kChildren.m_usSize; ++i)
    {
        NiAVObject* child = m_kChildren.m_pBase[i].m_pObject;
        if (child)
            child->UpdateDownwardPass(kUpdate, 0);
    }
#undef world
#undef local
#undef flags
}

void* __cdecl FUN_00aa13e0(unsigned int bytes);

extern const void* DAT_0102bf44[];

inline NiBillboardNode* InitializeBillboardClone(void* storage)
{
    NiBillboardNode* clone = (NiBillboardNode*)storage;
    typedef NiNode* (__thiscall* NodeConstructor)(NiNode*, unsigned int);
    ((NodeConstructor)InitializeNiNode)(clone, 0);
    *(float*)&clone->unkB0 = 0.0f;
    *(const void***)clone = DAT_0102bf44;
    *(short*)&clone->unkAC = 9;
    return clone;
}

// @fnv 0x00a7e710
BillboardClone* NiBillboardNode::FUN_00a7e710(void* context)
{
    void* storage = FUN_00aa13e0(sizeof(NiBillboardNode));
    NiBillboardNode* clone = storage ? InitializeBillboardClone(storage) : 0;
    NiNode::CopyMemberData(clone, *(CloningProcess*)context);
    *(short*)&clone->unkAC = *(short*)&unkAC;
    return (BillboardClone*)clone;
}
