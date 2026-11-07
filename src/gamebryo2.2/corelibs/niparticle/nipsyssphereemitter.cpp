// gamebryo2.2/corelibs/niparticle/nipsyssphereemitter.cpp: NiPSysSphereEmitter, PSysSphereEmitter (10 functions)

#include "nipsyssphereemitter_decls.h"
#include "../../../../include/BSFadeNode.h"
// Calls the base LoadBinary, then reads a 4-byte value from the stream into a member and advances the stream position.
// @fnv 0x00c20040
void NiPSysSphereEmitter::LoadBinary(NiStream& stream)
{
    NiPSysVolumeEmitter::LoadBinary(stream);
    NiBinaryStream* __restrict input = stream.m_pkIstr;
    unsigned int size = 4;
    input->m_uiAbsoluteCurrentPos += input->m_pfnRead(input, &m_fBoundRadius, 4, &size, 1);
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_01202510;

// @fnv 0x00c1fe10
// src: COMMUNITY 0x00c1fe10
GlobalObjectO2_00a7b610* __cdecl NiPSysSphereEmitter_GetRTTI()
{
    return &g_01202510;
}

extern int DAT_010bd974;
// @fnv 0x00c1fff0
// src: EXE 0x00c1fff0
BSFadeNode* __cdecl NiPSysSphereEmitter_CreateObject()
{
    BSFadeNode* p = static_cast<BSFadeNode*>(BSFadeNode::operator new(0x5c));
    if (p)
    {
        p->FUN_00c31af0();
        *reinterpret_cast<float*>(reinterpret_cast<char*>(p) + 0x58) = 0.0f;
        *reinterpret_cast<void**>(p) = &DAT_010bd974;
        return p;
    }
    return 0;
}

struct Holder31750
{
    void FUN_00c31750();
};
void __cdecl _delete(void*, unsigned int);
struct Holder20020
{
    void* FUN_00c20020(unsigned int);
};
// Calls FUN_00c31750 on this, then deletes this with size 0x5c when bit 0 of f is set, and returns this.
// @fnv 0x00c20020
void* Holder20020::FUN_00c20020(unsigned int auiFlags)
{
    ((Holder31750*)this)->FUN_00c31750();
    if (auiFlags & 1)
        _delete(this, 0x5c);
    return this;
}

// The shared class does not yet declare this IsEqual override.
extern "C" bool __cdecl NiPSysVolumeEmitter_IsEqual();
struct Holder00c1fde0 : NiPSysVolumeEmitter
{
    float m_fCylinderRadius;
    bool __thiscall NiPSysSphereEmitter_IsEqual(void* pkObject);
};
// @fnv 0x00c1fde0
// src: XBOX_PDB 0x00c1fde0
bool __thiscall Holder00c1fde0::NiPSysSphereEmitter_IsEqual(void* pkObject)
{
    Holder00c1fde0* pkDest = (Holder00c1fde0*)pkObject;
    if (!reinterpret_cast<bool (__thiscall*)(const NiPSysVolumeEmitter*, NiObject*)>(
            &NiPSysVolumeEmitter_IsEqual)(this, static_cast<NiObject*>(pkObject)))
        return false;
    if (m_fCylinderRadius != pkDest->m_fCylinderRadius)
        return false;
    return true;
}

struct SphereEmitterCloneView
{
    void* NiPSysVolumeEmitter_CopyMembers(BSFadeNode* pkObject, void* pkCloningProcess);
    BSFadeNode* CreateFadeNode(void* pkCloningProcess);
};

// @fnv 0x00c1ffa0
BSFadeNode* SphereEmitterCloneView::CreateFadeNode(void* pkCloningProcess)
{
    BSFadeNode* pkObject = static_cast<BSFadeNode*>(BSFadeNode::operator new(0x5c));
    if (pkObject)
    {
        pkObject->FUN_00c31af0();
        *reinterpret_cast<float*>(reinterpret_cast<char*>(pkObject) + 0x58) = 0.0f;
        *reinterpret_cast<void**>(pkObject) = &DAT_010bd974;
    }
    else
    {
        pkObject = 0;
    }
    NiPSysVolumeEmitter_CopyMembers(pkObject, pkCloningProcess);
    *reinterpret_cast<float*>(reinterpret_cast<char*>(pkObject) + 0x58) =
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x58);
    return pkObject;
}

// The shared class does not yet declare this SaveBinary override.
extern "C" void __cdecl NiPSysVolumeEmitter_SaveBinary();

// @fnv 0x00c20080
void NiPSysSphereEmitter::SaveBinary(NiStream& stream)
{
    reinterpret_cast<void (__thiscall*)(NiPSysVolumeEmitter*, NiStream&)>(&NiPSysVolumeEmitter_SaveBinary)(this, stream);
    NiBinaryStream* input = stream.m_pkOstr;
    {
        unsigned int size = 4;
        input->m_uiAbsoluteCurrentPos += input->m_pfnWrite(input, &m_fBoundRadius, 4, &size, 1);
    }
}

struct FUN_00c200c0_Arr
{
    int unk00;
    int unk04;
    unsigned short m_usMax;
    unsigned short m_usSize;
    unsigned short unk0c;
    unsigned short m_usGrow;
    void __thiscall FUN_0096ad30(unsigned int n);
    void __thiscall FUN_0096ae90(unsigned int n, unsigned int* p);
};

extern "C" void __stdcall FUN_00c31db0(FUN_00c200c0_Arr* p);
extern "C" unsigned int __cdecl NiViewerStrings_NiGetViewerString_Title(unsigned int v);
extern "C" unsigned int __cdecl NiGetViewerString_00a7d550(const void* p, float f);
extern "C" unsigned int DAT_01202510;
extern "C" int UNK_01015a9c;

struct Emitter00c200c0
{
    char pad[0x58];
    float m_f58;
    void __thiscall AppendTwoValues(FUN_00c200c0_Arr* p);
};

// Appends a value derived from DAT_01202510 and a value computed from m_f58 into the array p, growing it when full.
// @fnv 0x00c200c0
void __thiscall Emitter00c200c0::AppendTwoValues(FUN_00c200c0_Arr* p)
{
    FUN_00c31db0(p);
    unsigned int uiValue = NiViewerStrings_NiGetViewerString_Title(DAT_01202510);
    unsigned int n = p->m_usSize;
    if (n >= p->m_usMax)
    {
        p->FUN_0096ad30(p->m_usGrow + n);
    }
    p->FUN_0096ae90(n, &uiValue);
    uiValue = NiGetViewerString_00a7d550(&UNK_01015a9c, m_f58);
    n = p->m_usSize;
    if (n >= p->m_usMax)
    {
        p->FUN_0096ad30(p->m_usGrow + n);
    }
    p->FUN_0096ae90(n, &uiValue);
}

// @fnv 0x00c31af0
NiPSysVolumeEmitter::NiPSysVolumeEmitter() : NiPSysEmitter()
{
    m_pkEmitterObject = 0;
}

extern "C" int __cdecl rand();
extern float DAT_011f4ae0[];  // sin table, 512 entries
extern float DAT_011f52e0[];  // cos table, 512 entries
extern float g_fTwoPi;

struct SpherePoint3
{
    float x, y, z;
};

struct SphereMatrix3
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    SpherePoint3 Multiply(const SpherePoint3& p) const;
};

struct SphereEmitter00c1fe20 : NiPSysSphereEmitter
{
    void GenerateSpherePoint(SphereMatrix3& kRotate, SpherePoint3& kPosition, SpherePoint3& kMotionVelocity);
};

static inline float UnitRandom()
{
    return (float)(rand() / 32767.0);
}

// @fnv 0x00c1fe20
void SphereEmitter00c1fe20::GenerateSpherePoint(SphereMatrix3& kRotate, SpherePoint3& kPosition,
                                                SpherePoint3& kMotionVelocity)
{
    float fRadius = m_fBoundRadius * UnitRandom();
    float fAngle1 = g_fTwoPi * UnitRandom();
    float fAngle2 = g_fTwoPi * UnitRandom();
    int i1 = (int)(fAngle1 * (512.0 / g_fTwoPi)) & 0x1ff;
    float fCos1 = DAT_011f52e0[i1];
    int i2 = (int)(fAngle2 * (512.0 / g_fTwoPi)) & 0x1ff;
    float fCos2 = DAT_011f52e0[i2];
    float fSin2 = DAT_011f4ae0[i2];
    float fSin1 = DAT_011f4ae0[i1];

    kPosition.x = fRadius * fCos2 * fSin1;
    kPosition.y = fRadius * fCos2 * fCos1;
    kPosition.z = fRadius * fSin2;

    kPosition = kRotate.Multiply(kPosition);

    SpherePoint3 v;
    v.x = kRotate.m00 * kMotionVelocity.x + kRotate.m01 * kMotionVelocity.y + kRotate.m02 * kMotionVelocity.z;
    v.y = kRotate.m10 * kMotionVelocity.x + kRotate.m11 * kMotionVelocity.y + kRotate.m12 * kMotionVelocity.z;
    v.z = kRotate.m20 * kMotionVelocity.x + kRotate.m21 * kMotionVelocity.y + kRotate.m22 * kMotionVelocity.z;
    kMotionVelocity = v;
}
