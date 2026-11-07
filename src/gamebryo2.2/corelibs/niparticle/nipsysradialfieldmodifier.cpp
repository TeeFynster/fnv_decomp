#include <string.h>
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiPSysData.h"
#include "../../../../include/NiPSysPositionModifier.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiPSysFieldModifier.h"
#include "../../../../include/NiPSysRadialFieldModifier.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTransform.h"

// src/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_012026b0;

// @fnv 0x00c285c0
// src: COMMUNITY 0x00c285c0
void* __cdecl NiPSysRadialFieldModifier_GetRTTI()
{
    return &g_012026b0;
}

// The shared stream declarations keep their storage opaque.
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}

inline NiBinaryStream& NiStream::Istr()
{
    return **reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

// @fnv 0x00c27770
// src: XBOX_PDB 0x00c27770
void NiPSysRadialFieldModifier::SaveBinary_00c27770(NiStream& kStream)
{
    NiPSysFieldModifier::SaveBinary(kStream);
    NiBinaryStream* __restrict output = kStream.GetBinaryStream();
    unsigned int size = 4;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(output) + 4) +=
        (*reinterpret_cast<NiBinaryStream::WriteFunction*>(reinterpret_cast<char*>(output) + 12))(
            output, &m_fBoundRadius, 4, &size, 1);
}

// @fnv 0x00c28760
// src: XBOX_PDB 0x00c28760
void NiPSysRadialFieldModifier::LoadBinary_00c28760(NiStream& stream)
{
    NiPSysFieldModifier::LoadBinary(stream);
    NiBinaryStream* __restrict input = &stream.Istr();
    unsigned int size = 4;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(input) + 4) +=
        (*reinterpret_cast<NiBinaryStream::ReadFunction*>(reinterpret_cast<char*>(input) + 8))(
            input, &m_fBoundRadius, 4, &size, 1);
}

extern int DAT_010c0b5c;
// The shared modifier base has no constructor declaration. Keep its original
// initialization call through the existing position-modifier constructor.
// @fnv 0x00c31ff0
NiPSysFieldModifier* __fastcall ConstructFieldModifier(NiPSysFieldModifier* modifier)
{
    reinterpret_cast<NiPSysPositionModifier*>(modifier)->NiPSysPositionModifier::NiPSysPositionModifier();
    modifier->m_spFieldObject = 0;
    modifier->m_fInfluence = 0.0f;
    modifier->m_fFieldAttenuation = 0.0f;
    modifier->m_bEnableMaxDistance = false;
    modifier->m_fDistanceLimit = 0.0f;
    modifier->m_fFieldStrength = 0.0f;
    *(int*)modifier = (int)&DAT_010c0b5c;
    return modifier;
}

extern "C" char __stdcall FUN_00c32060(void*);

// @fnv 0x00c285a0
// src: XBOX_PDB 0x00c285a0
unsigned char __stdcall NiPSysRadialFieldModifier_IsEqual(void* p)
{
    return FUN_00c32060(p) != 0;
}

struct S_00c28a90_Arr
{
    int unk00;
    int unk04;
    unsigned short size;
    unsigned short esize;
    unsigned short unk0c;
    unsigned short growBy;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char*&);
};
// The shared field header does not declare its viewer-string override yet.
// This method-only adapter preserves that direct base call without class storage.
struct FieldModifierViewerStrings
{
    void GetViewerStrings(NiViewerStringsArray* strings);
};
extern const char* DAT_012026b0;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* s);
char* __cdecl NiGetViewerString_00a7d550(const char* name, float value);
__forceinline void S_00c28a90_Add(S_00c28a90_Arr* a, char* s)
{
    unsigned int i = a->esize;
    if (i >= a->size)
        a->FUN_0096ad30(i + a->growBy);
    a->FUN_0096ae90(i, s);
}
// @fnv 0x00c28a90
void NiPSysRadialFieldModifier::GetViewerStrings(NiViewerStringsArray* strings)
{
    reinterpret_cast<FieldModifierViewerStrings*>(this)->GetViewerStrings(strings);
    S_00c28a90_Arr* pArray = reinterpret_cast<S_00c28a90_Arr*>(strings);
    S_00c28a90_Add(pArray, NiViewerStrings_NiGetViewerString_Title(DAT_012026b0));
    S_00c28a90_Add(pArray, NiGetViewerString_00a7d550("RadialType", m_fBoundRadius));
}

inline NiPoint3::NiPoint3(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}

inline NiPoint3 NiPoint3::operator-(const NiPoint3& pt) const
{
    return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
}

inline NiPoint3 NiPoint3::operator*(float fScalar) const
{
    return NiPoint3(fScalar * x, fScalar * y, fScalar * z);
}

__forceinline void NiPoint3::Accumulate(NiPoint3 point)
{
    x += point.x;
    y += point.y;
    z += point.z;
}

// The shared transform declaration lacks the original product's noalias
// annotation. Keep just that call contract here, with no duplicated storage.
struct FieldTransformProduct
{
    __declspec(noalias) NiTransform Multiply(const NiTransform& field) const;
};

struct Point3ParameterData
{
    NiPoint3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
};
// Applies a time-scaled field influence to each active particle's position using the delta between the field object and target transforms.
// @fnv 0x00c28620
void NiPSysRadialFieldModifier::Update(float fTime, NiPSysData* data)
{
    NiPSysData* pkData = data;
    // These temporaries were uninitialized POD storage in the original unit.
    // Copy their bytes directly so shared matrix constructors are not invoked.
    float fieldStorage[sizeof(NiTransform) / sizeof(float)];
    NiTransform& kField = *reinterpret_cast<NiTransform*>(fieldStorage);
    memcpy(&kField, &m_spFieldObject->m_kWorld, sizeof(kField));
    float inverseStorage[sizeof(NiTransform) / sizeof(float)];
    NiTransform& kInv = *reinterpret_cast<NiTransform*>(inverseStorage);
    {
        float previousStorage[sizeof(NiTransform) / sizeof(float)];
        NiTransform& kPrev = *reinterpret_cast<NiTransform*>(previousStorage);
        memcpy(&kPrev, &reinterpret_cast<NiAVObject*>(m_pkTarget)->m_kWorld, sizeof(kPrev));
        kPrev.FUN_004b4880(kInv);
    }
    {
        NiTransform kDelta = reinterpret_cast<const FieldTransformProduct*>(&kInv)->Multiply(kField);
        NiPoint3* pkPos = pkData->m_pkVertex;
        float fMag = m_fInfluence;
        for (unsigned short i = 0; i < pkData->m_usActive; i++)
        {
            Point3ParameterData* pkInfo = &pkData->m_pkParticleInfo[i];
            float fDt = fTime - pkInfo->m_fZValue;
            if (fDt != 0.0f)
            {
                NiPoint3 kWorldPosition = *pkPos++ - kDelta.m_Translate;
                float fS = fDt * fMag;
                kWorldPosition = kWorldPosition * fS;
                pkInfo->m_kValue.Accumulate(kWorldPosition);
            }
        }
    }
}
