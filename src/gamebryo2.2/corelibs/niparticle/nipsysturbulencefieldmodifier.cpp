#include "../../../../include/NiTArray.h"

// src/gamebryo2.2/corelibs/niparticle/nipsysturbulencefieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysturbulencefieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPSysData.h"
#include "../../../../include/NiPSysFieldModifier.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/NiMatrix3.h"
#include <string.h>

inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}

inline NiPoint3 NiPoint3::operator-(const NiPoint3& point) const
{
    return NiPoint3(x - point.x, y - point.y, z - point.z);
}

inline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}

inline float NiPoint3::SqrLength()
{
    return x * x + y * y + z * z;
}

inline float NiPoint3::SqrLength() const
{
    return x * x + y * y + z * z;
}

inline NiTransform::NiTransform()
{}

inline const NiTransform& NiAVObject::GetWorldTransform() const
{
    return m_kWorld;
}

inline NiPoint3* NiPSysData::GetVertices() const
{
    return m_pkVertex;
}

inline unsigned short NiPSysData::GetShaderParticleCount() const
{
    return m_usActive;
}

inline Point3ParameterData* NiPSysData::GetParticleInfo()
{
    return m_pkParticleInfo;
}

struct Point3ParameterData
{
    NiPoint3 m_kValue;
    float unk0c;
    float unk10;
    float unk14;
    unsigned short unk18;
    unsigned short unk1a;
};

extern const void* const g_01202698;

// @fnv 0x00c273c0
// src: COMMUNITY 0x00c273c0
const void* __cdecl NiPSysTurbulenceFieldModifier_GetRTTI()
{
    return &g_01202698;
}

struct C27A30RTTI;
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    return SetAtGrow(m_usSize, element);
}

typedef NiTArray<char*, NiTMallocInterface<char*> > C27A30StringArray;

struct NiPSysTurbulenceFieldModifier : NiPSysFieldModifier
{
    float m_fFrequency;
    float m_fFieldMagnitude;
    float m_fFieldDistance;
    bool __thiscall IsEqual_00c27390(NiObject* pkObject);
    static C27A30RTTI ms_kRTTI;
    void FieldViewerStrings(C27A30StringArray* pkStrings);
    void GetViewerStrings_00c27a30(C27A30StringArray* pkStrings);
    void __thiscall ReadFloatAndComputeInverse(void* object);
    void UpateNoAttenuation(float fTime, NiPSysData* pkData);
    void __thiscall UpdateTurbulence(float fTime, NiPSysData* pkData);
    void __thiscall ApplyRandomOffset(float fTime, NiPSysData* pkData);

    float ReadScalar() const
    {
        return m_fInfluence;
    }
};

// @fnv 0x00c27390
// src: XBOX_PDB 0x00c27390
bool __thiscall NiPSysTurbulenceFieldModifier::IsEqual_00c27390(NiObject* pkObject)
{
    NiPSysTurbulenceFieldModifier* pkDest;
    if (!NiPSysFieldModifier::IsEqual(pkObject))
        return false;
    pkDest = (NiPSysTurbulenceFieldModifier*)pkObject;
    if (pkDest->m_fFrequency != m_fFrequency)
        return false;
    return true;
}

struct CloningProcess
{
    void* m_pCloneMap;
};
extern float DAT_01015f5c;
extern float DAT_01022958;
extern double DAT_01032980;
extern int DAT_010be774;
// @fnv 0x00c27670
NiPSysTurbulenceFieldModifier* __fastcall CloneFieldModifier(NiPSysTurbulenceFieldModifier* self, int,
                                                            CloningProcess* kCloning)
{
    NiPSysTurbulenceFieldModifier* pkObject = (NiPSysTurbulenceFieldModifier*)BSFadeNode::operator new(0x3c);
    if (pkObject)
    {
        pkObject->NiPSysFieldModifier::NiPSysFieldModifier();
        pkObject->m_fFrequency = 0.0f;
        *(int**)pkObject = &DAT_010be774;
        pkObject->m_fFieldDistance = DAT_01015f5c;
        pkObject->m_fFieldMagnitude = DAT_01022958;
    }
    else
        pkObject = 0;
    self->NiPSysFieldModifier::CopyMemberData(pkObject, *kCloning);
    pkObject->m_fFrequency = self->m_fFrequency;
    if (pkObject->m_fFrequency < DAT_01032980)
        pkObject->m_fFieldMagnitude = DAT_01022958;
    else
        pkObject->m_fFieldMagnitude = 1.0f / pkObject->m_fFrequency;
    return pkObject;
}

struct C27A30RTTI
{
    const char* m_pcName;
    const C27A30RTTI* m_pBaseRTTI;

    const char* GetName() const
    {
        return m_pcName;
    }
};

typedef NiTArray<char*, NiTMallocInterface<char*> > C27A30StringArray;

extern "C" char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcText);
char* __cdecl NiGetViewerString_00a7d550(const char* pcPrefix, float fValue);

// Appends the RTTI name and a formatted "Frequency" string for m_fFrequency to pkStrings after calling the base handler.
// @fnv 0x00c27a30
// src: XBOX_PDB 0x00c27a30
void NiPSysTurbulenceFieldModifier::GetViewerStrings_00c27a30(C27A30StringArray* pkStrings)
{
    FieldViewerStrings(pkStrings);
    char* pcString = NiViewerStrings_NiGetViewerString_Title(ms_kRTTI.GetName());
    pkStrings->Add(pcString);
    pcString = NiGetViewerString_00a7d550("Frequency", m_fFrequency);
    pkStrings->Add(pcString);
}

struct FieldReadState;
typedef unsigned int(__cdecl* ReadFunction)(FieldReadState*, float*, unsigned int, unsigned int*, unsigned int);
struct FieldReadState
{
    int unk00;
    unsigned int bytesRead;
    ReadFunction read;
    void ReadFloat(float* value)
    {
        unsigned int readSize = 4;
        bytesRead += read(this, value, 4, &readSize, 1);
    }
};
extern double DAT_01032980;
extern float DAT_01022958;
// Reads a float from the stream at object+0x24c and stores its reciprocal, or a fallback constant when the value is below DAT_01032980.
// @fnv 0x00c27700
void __thiscall NiPSysTurbulenceFieldModifier::ReadFloatAndComputeInverse(void* object)
{
    NiPSysFieldModifier::LoadBinary(*static_cast<NiStream*>(object));
    FieldReadState* stream = *(FieldReadState**)((char*)object + 0x24c);
    stream->ReadFloat(&m_fFrequency);
    if (m_fFrequency < DAT_01032980)
        m_fFieldMagnitude = DAT_01022958;
    else
        m_fFieldMagnitude = 1.0f / m_fFrequency;
}

// FUN_00c274c0: NiPSysTurbulenceFieldModifier::Update - random velocity kick
// for every particle within the field's maximum distance.
int __cdecl FUN_00ecadb8();
extern double DAT_01029790;

inline float SymmetricRandom()
{
    return (float)(2.0 * FUN_00ecadb8() / DAT_01029790 - 1.0);
}

// Applies a random offset scaled by m_fInfluence to particle values whose squared distance from the transformed field position is at most m_fFieldStrength.
// @fnv 0x00c274c0
// src: XBOX_PDB 0x00c274c0
void NiPSysTurbulenceFieldModifier::UpateNoAttenuation(float fTime, NiPSysData* pkData)
{
    NiTransform kFieldXform;
    memcpy(&kFieldXform, &m_spFieldObject->m_kWorld, sizeof(kFieldXform));
    NiTransform kInvPSys;
    {
        NiTransform kPSysXform;
        memcpy(&kPSysXform, &((NiAVObject*)m_pkTarget)->m_kWorld, sizeof(kPSysXform));
        kPSysXform.FUN_004b4880(kInvPSys);
    }

    {
        NiTransform kFieldToPSys = kInvPSys * kFieldXform;
        for (unsigned short i = 0; i < pkData->m_usActive; i++)
        {
            Point3ParameterData* pkInfo = &pkData->GetParticleInfo()[i];
            NiPoint3 kPos = pkData->GetVertices()[i];
            NiPoint3 kDiff = kPos - kFieldToPSys.m_Translate;
            if (kDiff.SqrLength() <= m_fFieldStrength)
            {
                NiPoint3 kRand;
                kRand.x = SymmetricRandom();
                kRand.y = SymmetricRandom();
                kRand.z = SymmetricRandom();
                NiPoint3 kOffset = kRand * m_fInfluence;
                pkInfo->m_kValue.x = pkInfo->m_kValue.x + kOffset.x;
                pkInfo->m_kValue.y = pkInfo->m_kValue.y + kOffset.y;
                pkInfo->m_kValue.z = pkInfo->m_kValue.z + kOffset.z;
            }
        }
    }
}

#include <math.h>
extern "C" int __cdecl rand();

inline float NiPoint3::Length()
{
    return sqrtf(x * x + y * y + z * z);
}

inline float NiPoint3::Length() const
{
    return sqrtf(x * x + y * y + z * z);
}

// Applies random turbulence offsets to particle values based on distance from the field object, scaling by influence and attenuation.
// @fnv 0x00c277b0
void __thiscall NiPSysTurbulenceFieldModifier::UpdateTurbulence(float fTime, NiPSysData* pkData)
{
    if (fTime >= m_fFieldDistance && fTime < m_fFieldDistance + m_fFieldMagnitude)
        return;

    m_fFieldDistance = fTime;

    if (ReadScalar() == 0.0f || pkData->GetShaderParticleCount() == 0 || !m_spFieldObject)
        return;

    if (m_fFieldAttenuation == 0.0f)
    {
        if (m_bEnableMaxDistance)
            UpateNoAttenuation(fTime, pkData);
        else
            ApplyRandomOffset(fTime, pkData);
    }
    else
    {
        NiTransform kField;
        memcpy(&kField, &m_spFieldObject->GetWorldTransform(), sizeof(kField));
        NiTransform kInv;
        {
            NiTransform kTarget;
            memcpy(&kTarget, &((NiAVObject*)m_pkTarget)->GetWorldTransform(), sizeof(kTarget));
            kTarget.FUN_004b4880(kInv);
        }
        {
            NiTransform kPos = kInv * kField;

            for (unsigned short i = 0; i < pkData->GetShaderParticleCount(); ++i)
            {
                Point3ParameterData* pkInfo = &pkData->GetParticleInfo()[i];
                NiPoint3 kPt = pkData->GetVertices()[i];
                NiPoint3 kDiff = kPt - kPos.m_Translate;

                float fDist = kDiff.Length();

                if (!m_bEnableMaxDistance || fDist <= m_fDistanceLimit)
                {
                    NiPoint3 kRandom;
                    kRandom.x = (float)((rand() * 2.0 / 32767.0) - 1.0);
                    kRandom.y = (float)((rand() * 2.0 / 32767.0) - 1.0);
                    kRandom.z = (float)((double)((double)((rand() * 2.0 / 32767.0) - 1.0)));

                    float fFactor = ReadScalar() / (1.0f + m_fFieldAttenuation * fDist);

                    kRandom *= fFactor;
                    pkInfo->m_kValue += kRandom;
                }
            }
        }
    }
}

extern double g_C273D0RandMax;

inline float C273D0SymmetricRandom()
{
    return (float)(rand() * 2.0 / g_C273D0RandMax - 1.0);
}

// Adds a random 3D offset scaled by m_fInfluence to each particle's m_kValue in pkData.
// @fnv 0x00c273d0
void NiPSysTurbulenceFieldModifier::ApplyRandomOffset(float fTime, NiPSysData* pkData)
{
    for (unsigned short us = 0; us < pkData->m_usActive; us++)
    {
        Point3ParameterData* pkInfo = &pkData->m_pkParticleInfo[us];
        NiPoint3 kWorldPosition;
        kWorldPosition.x = C273D0SymmetricRandom();
        kWorldPosition.y = C273D0SymmetricRandom();
        kWorldPosition.z = C273D0SymmetricRandom();
        pkInfo->m_kValue += kWorldPosition * m_fInfluence;
    }
}
