// gamebryo2.2/corelibs/niparticle/nipsysboxemitter.cpp: NiPSysEmitter, NiPSysBoxEmitter, EmitterHack, BoxViewer and more (13 functions)

// BaseHack_nipsysboxemitter: local type (was include/BaseHack.h, which had no evidence of one real class); its methods are 0x00a57130 NiExtraDataController::SaveBinary, 0x00a6d730 NiTimeController::SaveBinary, 0x00c31b80 NiPSysVolumeEmitter::IsEqual
class NiObject;
struct NiStream;

class BaseHack_nipsysboxemitter
{
public:
    void __thiscall FUN_00a6d730(NiStream&);
    bool FUN_00c31b80(NiObject*);
};
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiPSysBoxEmitter.h"
#include "../../../../include/NiPSysEmitter.h"
#include "../../../../include/NiPSysPositionModifier.h"
#include "../../../../include/NiPSysVolumeEmitter.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiMatrix3.h"

inline NiPoint3::NiPoint3(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}
extern NiColorA DAT_011a9be0;

inline void NiBinaryStream::ReadFloat(float& value)
{
    unsigned int size = 4;
    m_uiAbsoluteCurrentPos += m_pfnRead(this, &value, 4, &size, 1);
}

inline void NiBinaryStream::Write(float* value)
{
    unsigned int size = sizeof(float);
    m_uiAbsoluteCurrentPos += m_pfnWrite(this, value, sizeof(float), &size, 1);
}

// Constructs a NiPSysEmitter, initializing speed, declination, planar angle, color, radius, lifespan and unknown to their defaults.
// @fnv 0x00c21f00
NiPSysEmitter::NiPSysEmitter()
    : m_fEmissionSpeed(0.0f), m_fSpeedVariation(0.0f), m_fEmissionDeclination(0.0f),
      m_fDeclinationVariation(0.0f), m_fEmissionPlanarAngle(0.0f), m_fPlanarAngleVariation(0.0f),
      m_kParticleColor(DAT_011a9be0), m_fEmissionRadius(1.0f), m_fRadiusVariation(0.0f),
      m_fYValue(0.0f), m_fLifeSpanVariation(0.0f), m_fScale(1.0f)
{}
// Loads the box emitter's width, height and depth floats from the stream after the base volume emitter data.
// @fnv 0x00c203b0
void NiPSysBoxEmitter::LoadBinary(NiStream& stream)
{
    NiPSysVolumeEmitter::LoadBinary(stream);
    stream.m_pkIstr->ReadFloat(width);
    stream.m_pkIstr->ReadFloat(height);
    stream.m_pkIstr->ReadFloat(depth);
}

struct GlobalObjectO2_00a7b618
{
};
extern GlobalObjectO2_00a7b618 g_01202518;

// @fnv 0x00c201c0
// src: COMMUNITY 0x00c201c0
GlobalObjectO2_00a7b618* __cdecl NiPSysBoxEmitter_GetRTTI()
{
    return &g_01202518;
}

extern int DAT_010bda2c;
// Allocates a 100-byte BSFadeNode, runs its constructor, zeroes the floats at offsets 0x58-0x60, sets its vtable, and returns it (or null).
// @fnv 0x00c20350
// src: EXE 0x00c20350
BSFadeNode* __cdecl NiPSysBoxEmitter_CreateObject()
{
    BSFadeNode* node = (BSFadeNode*)BSFadeNode::operator new(100);
    if (node)
    {
        node->FUN_00c31af0();
        *(float*)((char*)node + 0x58) = 0.0f;
        *(void**)((char*)node + 0) = &DAT_010bda2c;
        *(float*)((char*)node + 0x5c) = 0.0f;
        *(float*)((char*)node + 0x60) = 0.0f;
        return node;
    }
    return 0;
}

void __cdecl FUN_00c31750();
void __cdecl _delete(void*, unsigned int);
struct S
{
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// @fnv 0x00c20390
void* __thiscall S::DestroyIfFlagged(unsigned int uiFlags)
{
    FUN_00c31750();
    if (uiFlags & 1)
        _delete(this, 0x64);
    return this;
}

struct EmitterHack : NiPSysBoxEmitter
{
    bool IsEqual(NiObject* pkObject);
};
// Calls FUN_00c31b80 on pkObject and returns true only if that succeeds and the three floats at offsets 0x58, 0x5c and 0x60 match the other object's.
// @fnv 0x00c20170
bool EmitterHack::IsEqual(NiObject* pkObject)
{
    EmitterHack* pkDest = (EmitterHack*)pkObject;
    if (((BaseHack_nipsysboxemitter*)this)->FUN_00c31b80(pkObject) && width == pkDest->width &&
        height == pkDest->height && depth == pkDest->depth)
        return true;
    return false;
}


// Additional clone entry points are not declared by the shared emitter headers.
struct VolumeEmitterCloneData : NiPSysVolumeEmitter
{
    void CopyTo(NiPSysVolumeEmitter*, CloningProcess&);
};

struct BoxEmitterClone : NiPSysBoxEmitter
{
    NiObject* Clone(CloningProcess& kCloning);
};

// @fnv 0x00c202f0
NiObject* BoxEmitterClone::Clone(CloningProcess& kCloning)
{
    BSFadeNode* pkObject = (BSFadeNode*)NiObject::operator new(0x64);
    if (pkObject)
    {
        pkObject->FUN_00c31af0();
        *(float*)((char*)pkObject + 0x58) = 0.0f;
        *(void**)pkObject = (void*)&DAT_010bda2c;
        *(float*)((char*)pkObject + 0x5c) = 0.0f;
        *(float*)((char*)pkObject + 0x60) = 0.0f;
    }
    else
    {
        pkObject = 0;
    }
    static_cast<VolumeEmitterCloneData*>(static_cast<NiPSysVolumeEmitter*>(this))->CopyTo(
        reinterpret_cast<NiPSysVolumeEmitter*>(pkObject), kCloning);
    *(float*)((char*)pkObject + 0x58) = width;
    *(float*)((char*)pkObject + 0x5c) = height;
    *(float*)((char*)pkObject + 0x60) = depth;
    return (NiObject*)pkObject;
}

// The shared headers do not declare these emitter-specific save overrides.
struct VolumeEmitterSerialization : NiPSysVolumeEmitter
{
    void SaveBinary(NiStream& stream);
};

struct BoxEmitterSerialization : NiPSysBoxEmitter
{
    void SaveBinary(NiStream& stream);
};

// Saves the volume emitter base stream, then writes width, height and depth.
// @fnv 0x00c20440
void BoxEmitterSerialization::SaveBinary(NiStream& stream)
{
    static_cast<VolumeEmitterSerialization*>(static_cast<NiPSysVolumeEmitter*>(this))
        ->VolumeEmitterSerialization::SaveBinary(stream);
    stream.m_pkOstr->Write(&width);
    stream.m_pkOstr->Write(&height);
    stream.m_pkOstr->Write(&depth);
}

inline void StrArr::AppendInline(char* value)
{
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    SetAt(index, value);
}
extern const char* DAT_01202518;
extern const char DAT_0109dc8c[];
extern const char DAT_0109dc84[];
extern const char DAT_010a0eb4[];
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);
struct VolumeViewer : NiPSysVolumeEmitter
{
    void FUN_00c31db0(StrArr*);
};
struct BoxViewer : NiPSysBoxEmitter
{
    void NiPSysBoxEmitter_GetViewerStrings(StrArr*);
};
// Appends the base volume emitter's debug strings, then the box emitter's width, height and depth values to the string array.
// @fnv 0x00c204d0
// src: XBOX_PDB 0x00c204d0
void BoxViewer::NiPSysBoxEmitter_GetViewerStrings(StrArr* strings)
{
    ((VolumeViewer*)this)->FUN_00c31db0(strings);
    strings->AppendInline(NiViewerStrings_NiGetViewerString_Title(DAT_01202518));
    strings->AppendInline(NiGetViewerString_00a7d550(DAT_0109dc8c, width));
    strings->AppendInline(NiGetViewerString_00a7d550(DAT_0109dc84, height));
    strings->AppendInline(NiGetViewerString_00a7d550(DAT_010a0eb4, depth));
}

struct FUN_00c61f60_class
{
    void NiPSysAirFieldModifier_RegisterStreamables(int);
};
struct FUN_00c1fdd0
{
    void NiPSysAirFieldModifier_RegisterStreamables(int);
};
// @fnv 0x00c1fdd0
// src: XBOX_PDB 0x00c2f4f0
void FUN_00c1fdd0::NiPSysAirFieldModifier_RegisterStreamables(int a)
{
    ((FUN_00c61f60_class*)this)->NiPSysAirFieldModifier_RegisterStreamables(a);
}

void __cdecl FUN_00c31c90();
// @fnv 0x00c20150
// src: XBOX_PDB 0x00c20150
void __cdecl NiPSysBoxEmitter_ProcessClone()
{
    FUN_00c31c90();
}

extern void __cdecl FUN_00c31b40();

// @fnv 0x00c20160
// src: XBOX_PDB 0x00c20160
void __cdecl NiPSysBoxEmitter_LinkObject()
{
    FUN_00c31b40();
}

namespace fnv_00c201d0 {
int __cdecl rand();
extern double DAT_01029790;

struct BoxEmitterInit : NiPSysBoxEmitter
{
    void NiPSysBoxEmitter_ComputeVolumeInitialPositionAndVelocity(const NiTransform& kTransform, NiPoint3& kPos, NiPoint3& kWorldPosition);
};

// Generates a random point from the box dimensions, transforms it, and rotates kWorldPosition.
// @fnv 0x00c201d0
// src: XBOX_PDB 0x00c201d0
void BoxEmitterInit::NiPSysBoxEmitter_ComputeVolumeInitialPositionAndVelocity(const NiTransform& kTransform, NiPoint3& kPos, NiPoint3& kWorldPosition)
{
    const NiMatrix3& kRot = kTransform.m_Rotate;
    float fX = rand() / DAT_01029790;
    float fY = rand() / DAT_01029790;
    float fZ = rand() / DAT_01029790;
    kPos = NiPoint3((fZ - 0.5f) * width, (fY - 0.5f) * height, (fX - 0.5f) * depth);
    kPos = kTransform.ComputeValue_00524c40(kPos);
    kWorldPosition = NiPoint3(reinterpret_cast<const NiPoint3*>(&kRot.m_pEntry[0][0])->Dot(kWorldPosition),
                              kRot.m_pEntry[1][0] * kWorldPosition.x + kRot.m_pEntry[1][1] * kWorldPosition.y +
                                  kRot.m_pEntry[1][2] * kWorldPosition.z,
                              reinterpret_cast<const NiPoint3*>(&kRot.m_pEntry[2][0])->Dot(kWorldPosition));
}
}  // namespace fnv_00c201d0
