// gamebryo2.2/corelibs/niparticle/nipsyscylinderemitter.cpp: NiPSysCylinderEmitter (7 functions)

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiPSysCylinderEmitter.h"
#include "../../../../include/NiPSysVolumeEmitter.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiMatrix3.h"
#include "../../../../include/NiTransform.h"

inline void NiBinaryStream::ReadFloat(float& value)
{
    unsigned int size = sizeof(float);
    m_uiAbsoluteCurrentPos += m_pfnRead(this, &value, sizeof(float), &size, 1);
}

inline void NiBinaryStream::Write(float* value)
{
    unsigned int size = sizeof(float);
    m_uiAbsoluteCurrentPos += m_pfnWrite(this, value, sizeof(float), &size, 1);
}

// @fnv 0x00c1fc40
void NiPSysCylinderEmitter::LoadBinary(NiStream& stream)
{
    NiPSysVolumeEmitter::LoadBinary(stream);
    stream.m_pkIstr->ReadFloat(m_fCylinderRadius);
    stream.m_pkIstr->ReadFloat(m_fCylinderHeight);
}

extern void* DAT_010bd8b4;

// @fnv 0x00c1fbf0
// src: EXE 0x00c1fbf0
void* __cdecl NiPSysCylinderEmitter_CreateObject()
{
    BSFadeNode* pFadeNode = (BSFadeNode*)BSFadeNode::operator new(0x60);
    if (pFadeNode)
    {
        pFadeNode->FUN_00c31af0();
        *(float*)((char*)pFadeNode + 0x58) = 0.0f;
        *(void**)pFadeNode = &DAT_010bd8b4;
        *(float*)((char*)pFadeNode + 0x5c) = 0.0f;
        return pFadeNode;
    }
    return 0;
}

void __cdecl FUN_00c31750();
void __cdecl _delete(void*, unsigned int);
// Calls FUN_00c31750, frees this with _delete when bit 0 of a1 is set, and returns this.
// @fnv 0x00c1fc20
void* NiPSysCylinderEmitter::DestroyIfFlagged(unsigned int auiFlags)
{
    FUN_00c31750();
    if (auiFlags & 1)
        _delete(this, 0x60);
    return this;
}

// @fnv 0x00c1fba0
BSFadeNode* NiPSysCylinderEmitter::CloneFadeNode(CloningProcess& kCloning)
{
    BSFadeNode* pkObject = (BSFadeNode*)BSFadeNode::operator new(0x60);
    if (pkObject)
    {
        pkObject->FUN_00c31af0();
        *(float*)((char*)pkObject + 0x58) = 0.0f;
        *(void**)((char*)pkObject) = &DAT_010bd8b4;
        *(float*)((char*)pkObject + 0x5c) = 0.0f;
    }
    else
    {
        pkObject = 0;
    }
    NiPSysVolumeEmitter::CopyMemberData(reinterpret_cast<NiPSysVolumeEmitter*>(pkObject), kCloning);
    *(float*)((char*)pkObject + 0x58) = *(float*)((char*)this + 0x58);
    *(float*)((char*)pkObject + 0x5c) = *(float*)((char*)this + 0x5c);
    return pkObject;
}

extern void* g_01202508;

void __stdcall FUN_00c31db0(StrArr*);
char* __cdecl _FUN_00a7d330(void*);
char* __cdecl NiGetViewerString_00a7d550(char const*, float);

// @fnv 0x00c1fd00
void NiPSysCylinderEmitter::AppendShapeParams(StrArr* pkStrings)
{
    FUN_00c31db0(pkStrings);

    char* string = _FUN_00a7d330(g_01202508);
    unsigned int index = pkStrings->m_usSize;
    if (!(index < pkStrings->m_usMaxSize))
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, string);

    string = NiGetViewerString_00a7d550("Radius", m_fCylinderRadius);
    index = pkStrings->m_usSize;
    if (!(index < pkStrings->m_usMaxSize))
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, string);

    string = NiGetViewerString_00a7d550("Height", m_fCylinderHeight);
    index = pkStrings->m_usSize;
    if (!(index < pkStrings->m_usMaxSize))
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, string);
}

// Saves the volume emitter base stream, then writes the cylinder dimensions.
// @fnv 0x00c1fca0
void NiPSysCylinderEmitter::SaveBinary(NiStream& stream)
{
    NiPSysVolumeEmitter::SaveBinary(stream);
    stream.m_pkOstr->Write(&m_fCylinderRadius);
    stream.m_pkOstr->Write(&m_fCylinderHeight);
}

namespace fnv_00c1fa50 {
extern "C" int __cdecl rand(void);

extern float NI_TWO_PI_F;
extern float g_afSinTable[512];
extern float g_afCosTable[512];

inline float RandomFloat0To1()
{
    return (float)(rand() / 32767.0);
}

inline void NiSinCos(float fAngleDifference, float& fSin, float& fCos)
{
    int i = (int)(fAngleDifference * (512.0 / NI_TWO_PI_F)) & 0x1ff;
    fSin = g_afSinTable[i];
    fCos = g_afCosTable[i];
}

}  // namespace fnv_00c1fa50

// Fills kPosition with a random point inside the cylinder and rotates both kPosition and kMotionVelocity by kRotate.
// @fnv 0x00c1fa50
// src: XBOX_PDB 0x00c1fa50
void NiPSysCylinderEmitter::ComputeVolumeInitialPositionAndVelocity(NiTransform& kEmitterToPSys, NiPoint3& kPosition, NiPoint3& kMotionVelocity)
{
    using namespace fnv_00c1fa50;
    float fRadius = m_fCylinderRadius * RandomFloat0To1();
    float fAngleDifference = NI_TWO_PI_F * RandomFloat0To1();
    float fSin, fCos;
    NiSinCos(fAngleDifference, fSin, fCos);
    kPosition.x = fRadius * fCos;
    kPosition.y = fRadius * fSin;
    kPosition.z = (RandomFloat0To1() - 0.5) * m_fCylinderHeight;
    kPosition = static_cast<const NiTransform&>(kEmitterToPSys).ComputeValue_00524c40(kPosition);
    const NiMatrix3& kRotate = kEmitterToPSys.m_Rotate;
    NiPoint3 kResult;
    kResult.x = kRotate.m_pEntry[0][0] * kMotionVelocity.x + kRotate.m_pEntry[0][1] * kMotionVelocity.y +
                kRotate.m_pEntry[0][2] * kMotionVelocity.z;
    kResult.y = kRotate.m_pEntry[1][0] * kMotionVelocity.x + kRotate.m_pEntry[1][1] * kMotionVelocity.y +
                kRotate.m_pEntry[1][2] * kMotionVelocity.z;
    kResult.z = kRotate.m_pEntry[2][0] * kMotionVelocity.x + kRotate.m_pEntry[2][1] * kMotionVelocity.y +
                kRotate.m_pEntry[2][2] * kMotionVelocity.z;
    kMotionVelocity = kResult;
}
