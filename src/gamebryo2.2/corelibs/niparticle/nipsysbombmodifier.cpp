#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/NiPSysBombModifier.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPSysData.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiMatrix3.h"


// src/gamebryo2.2/corelibs/niparticle/nipsysbombmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysbombmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CloningProcess
{
    // Object-pointer clone lookup; GetAt is 0x00a53c30, as in nitimecontroller.cpp.
    NiTPointerMap<void*, void*>* m_pCloneMap;
};
// @fnv 0x00c2e610
// src: XBOX_PDB 0x00c2e610
void NiPSysBombModifier::ProcessClone_00c2e610(CloningProcess& kCloning)
{
    bool bFound;
    NiObject* pkClone;
    NiPSysBombModifier* pkDest;
    NiPSysModifier::ProcessClone(kCloning);
    pkClone = 0;
    kCloning.m_pCloneMap->GetAt(this, (void*&)pkClone);
    pkDest = (NiPSysBombModifier*)pkClone;
    bFound = kCloning.m_pCloneMap->GetAt(m_pkBombObject, (void*&)pkClone);
    if (bFound)
        pkDest->m_pkBombObject = pkClone;
    else
        pkDest->m_pkBombObject = m_pkBombObject;
}

// @fnv 0x00c2eaf0
// src: XBOX_PDB 0x00c2eaf0
bool NiPSysBombModifier::IsEqual_00c2eaf0(NiObject* pkObject)
{
    if (!FUN_00c31830(pkObject))
        return false;

    NiPSysBombModifier* pkDest = (NiPSysBombModifier*)pkObject;

    if ((m_pkBombObject && !pkDest->m_pkBombObject) || (!m_pkBombObject && pkDest->m_pkBombObject) ||
        (m_pkBombObject && pkDest->m_pkBombObject &&
         !((const NiObject*)m_pkBombObject)->IsEqual(pkDest->m_pkBombObject)))
    {
        return false;
    }

    if (m_kBombDirection != pkDest->m_kBombDirection || m_fDistanceDecay != pkDest->m_fDistanceDecay ||
        m_fDeltaVelocity != pkDest->m_fDeltaVelocity || m_eBombDecayType != pkDest->m_eBombDecayType ||
        m_eSymmetryType != pkDest->m_eSymmetryType)
    {
        return false;
    }

    return true;
}

static inline void AddBombString(StrArr* strings, char* str)
{
    unsigned int index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, str);
}

namespace fnv_00c2ed00 {
struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610* g_01202790;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(GlobalObjectO2_00a7b610*);
char* __cdecl NiGetViewerString_00a7d5e0(const char*, const char*);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);

}  // namespace fnv_00c2ed00

inline const char* NiPSysBombModifier::GetDecayTypeName(int e)
{
    switch (e)
    {
    case 0:
        return "NONE";
    case 1:
        return "LINEAR";
    case 2:
        return "EXPONENTIAL";
    default:
        return "Unknown";
    }
}

inline const char* NiPSysBombModifier::GetSymmTypeName(int e)
{
    switch (e)
    {
    case 0:
        return "SPHERICAL";
    case 1:
        return "CYLINDRICAL";
    case 2:
        return "PLANAR";
    default:
        return "Unknown";
    }
}

// Appends the base strings plus the bomb object name, axis, decay, deltaV, decay type and symmetry type to pkStrings.
// @fnv 0x00c2ed00
void NiPSysBombModifier::AppendToStrings(StrArr* pkStrings)
{
    using namespace fnv_00c2ed00;
    FUN_00c319e0(pkStrings);

    AddBombString(pkStrings, NiViewerStrings_NiGetViewerString_Title(g_01202790));
    AddBombString(pkStrings, NiGetViewerString_00a7d5e0("Bomb Object", m_pkBombObject ? ((NiAVObject*)m_pkBombObject)->m_kName.m_kHandle : "None"));
    AddBombString(pkStrings, m_kBombDirection.GetViewerString_00a59af0("Bomb Axis"));
    AddBombString(pkStrings, NiGetViewerString_00a7d550("Decay", m_fDistanceDecay));
    AddBombString(pkStrings, NiGetViewerString_00a7d550("DeltaV", m_fDeltaVelocity));
    AddBombString(pkStrings, NiGetViewerString_00a7d5e0("Decay Type", GetDecayTypeName(m_eBombDecayType)));
    AddBombString(pkStrings, NiGetViewerString_00a7d5e0("Symmetry Type", GetSymmTypeName(m_eSymmetryType)));
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
{
    unsigned int written = m_pfnWrite(this, p, n, sizes, count);
    m_uiAbsoluteCurrentPos += written;
    return written;
}

static inline void ReadBombFloat(NiBinaryStream& input, float& value)
{
    unsigned int size = 4;
    input.m_uiAbsoluteCurrentPos += input.m_pfnRead(&input, &value, 4, &size, 1);
}

template <class Enum> static inline void ReadBombEnum(NiBinaryStream& input, Enum& value)
{
    unsigned int temp;
    unsigned int size = 4;
    input.m_uiAbsoluteCurrentPos += input.m_pfnRead(&input, &temp, 4, &size, 1);
    value = (Enum)temp;
}

// Loads the base data, then the bomb parameters from the stream's input.
// @fnv 0x00c2eb80
void __fastcall LoadBombBinary(NiPSysBombModifier* modifier, void*, NiStream& stream)
{
    modifier->NiPSysModifier::LoadBinary(stream);
    stream.ReadLinkID();
    modifier->m_kBombDirection.LoadBinary(stream);
    ReadBombFloat(*stream.m_pkIstr, modifier->m_fDistanceDecay);
    ReadBombFloat(*stream.m_pkIstr, modifier->m_fDeltaVelocity);
    ReadBombEnum(*stream.m_pkIstr, modifier->m_eBombDecayType);
    ReadBombEnum(*stream.m_pkIstr, modifier->m_eSymmetryType);
}

template <class T>
inline void BombBinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void SaveBombValue(NiStream& kStream, const T& value)
{
    BombBinaryStreamSave(*kStream.m_pkOstr, &value);
}

// Saves the modifier base, bomb object link, direction, and decay parameters.
// @fnv 0x00c2ec40
void __fastcall SaveBombBinary(NiPSysBombModifier* modifier, void*, NiStream& kStream)
{
    modifier->NiPSysModifier::SaveBinary(kStream);
    kStream.SaveLinkID(modifier->m_pkBombObject);
    ((NiColor&)modifier->m_kBombDirection).SaveBinary(kStream);
    SaveBombValue(kStream, modifier->m_fDistanceDecay);
    SaveBombValue(kStream, modifier->m_fDeltaVelocity);
    SaveBombValue(kStream, modifier->m_eBombDecayType);
    SaveBombValue(kStream, modifier->m_eSymmetryType);
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_010c01ec;
extern int DAT_011a946c;
extern int DAT_011a9470;
extern int DAT_011a9474;
// Calls the modifier base constructor for the manually allocated clone.
struct ParticleModifierConstructor
{
    void FUN_00c31720() throw();
};
// Creates a bomb modifier and copies the base and derived state.
// @fnv 0x00c2e570
NiObject* NiPSysBombModifier::MakeClone(CloningProcess& process)
{
    void* memory = Object_DispatchCommandFour(sizeof(NiPSysBombModifier));
    NiPSysBombModifier* clone;
    if (memory)
    {
        clone = (NiPSysBombModifier*)memory;
        ((ParticleModifierConstructor*)clone)->FUN_00c31720();
        *(void**)clone = &DAT_010c01ec;
        clone->m_pkBombObject = 0;
        *(int*)&clone->m_kBombDirection.x = DAT_011a946c;
        *(int*)&clone->m_kBombDirection.y = DAT_011a9470;
        *(int*)&clone->m_kBombDirection.z = DAT_011a9474;
        clone->m_fDistanceDecay = 0.0f;
        clone->m_fDeltaVelocity = 0.0f;
        clone->m_eBombDecayType = 0;
        clone->m_eSymmetryType = 0;
    }
    else
        clone = 0;
    NiPSysModifier::CopyMemberData(clone, process);
    clone->m_kBombDirection = m_kBombDirection;
    clone->m_fDistanceDecay = m_fDistanceDecay;
    clone->m_fDeltaVelocity = m_fDeltaVelocity;
    clone->m_eBombDecayType = m_eBombDecayType;
    clone->m_eSymmetryType = m_eSymmetryType;
    return clone;
}

#include <string.h>
#include <math.h>
extern NiPoint3 NiPoint3_ZERO;

struct BombPoint
{
    float x, y, z;
    BombPoint()
    {}
    BombPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    BombPoint(const NiPoint3& p)
    {
        memcpy(this, &p, sizeof(*this));
    }
    __declspec(noalias) void Unitize_004a0c10();
    float Dot(const BombPoint& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    float Length() const
    {
        return sqrtf(x * x + y * y + z * z);
    }
    BombPoint operator-(const BombPoint& p) const
    {
        return BombPoint(x - p.x, y - p.y, z - p.z);
    }
    BombPoint operator-() const
    {
        return BombPoint(-x, -y, -z);
    }
    BombPoint operator*(float f) const
    {
        return BombPoint(x * f, y * f, z * f);
    }
    BombPoint operator/(float f) const
    {
        float r = 1.0f / f;
        return BombPoint(x * r, y * r, z * r);
    }
    BombPoint& operator/=(float f)
    {
        float r = 1.0f / f;
        x *= r;
        y *= r;
        z *= r;
        return *this;
    }
    BombPoint& operator+=(BombPoint p)
    {
        x += p.x;
        float* dest = &y;
        *dest += p.y;
        z += p.z;
        return *this;
    }
};
inline BombPoint operator*(float f, const BombPoint& p)
{
    return BombPoint(f * p.x, f * p.y, f * p.z);
}
struct NiPoint3Helper
{
    __declspec(noalias) void Unitize();
};

struct Point3ParameterData
{
    BombPoint m_kValue;
    float unk0c;
    float unk10;
    float m_fZValue;
    int unk18;
};

// Applies velocity impulses to particles based on bomb direction, symmetry type, and distance decay over the elapsed time step.
// @fnv 0x00c2e670
// src: XBOX_PDB 0x00c2e670
void NiPSysBombModifier::Update_00c2e670(float fTime, NiPSysData* pkData)
{
    Point3ParameterData* pkInfo;
    (void)pkInfo;
    float fDist;
    (void)fDist;
    BombPoint kTargetCenter = NiPoint3_ZERO;
    BombPoint kBombAxis = m_kBombDirection;
    BombPoint kDiff;
    float fDeltaT;
    BombPoint kRadial;
    BombPoint kDirection;

    (void)kBombAxis.x;
    if (pkData->m_usActive > 0 && m_pkBombObject)
    {
        float kBombWorldStorage[sizeof(NiTransform) / sizeof(float)];
        NiTransform& kBombWorld = *(NiTransform*)kBombWorldStorage;
        memcpy(&kBombWorld, &((NiAVObject*)m_pkBombObject)->m_kWorld, sizeof(kBombWorld));
        float kBombToTargetStorage[sizeof(NiTransform) / sizeof(float)];
        NiTransform& kBombToTarget = *(NiTransform*)kBombToTargetStorage;
        memcpy(&kBombToTarget, &((NiAVObject*)m_pkTarget)->m_kWorld, sizeof(kBombToTarget));
        float kTargetInvStorage[sizeof(NiTransform) / sizeof(float)];
        NiTransform& kTargetInv = *(NiTransform*)kTargetInvStorage;
        ((const NiTransform&)kBombToTarget).FUN_004b4880(kTargetInv);
        ((const NiTransform&)kTargetInv).FUN_0062c250(&kBombToTarget, kBombWorld);

        kTargetCenter = kBombToTarget.m_Translate;
        kBombAxis = ((const NiMatrix3&)kBombToTarget.m_Rotate).operator*(m_kBombDirection);
        kBombAxis.Unitize_004a0c10();
    }

    for (unsigned short i = 0; i < pkData->m_usActive; ++i)
    {
        pkInfo = &pkData->m_pkParticleInfo[i];
        float ActorConditionAndAnimationState = pkInfo->m_fZValue;
        if (fTime > ActorConditionAndAnimationState)
        {
            fDeltaT = fTime - ActorConditionAndAnimationState;

            kDiff = ((BombPoint*)pkData->m_pkVertex)[i] - kTargetCenter;

            fDist = kDiff.Length();

            if (m_eBombDecayType != 0 && !(fDist <= m_fDistanceDecay))
                continue;

            switch (m_eSymmetryType)
            {
            case 0: {
                kDirection = kDiff / fDist;
                break;
            }
            case 1: {
                fDist = kBombAxis.Dot(kDiff);
                BombPoint kTemp = kBombAxis * fDist;
                kRadial = kDiff - kTemp;
                kDirection = kRadial;
                fDist = kRadial.Length();
                if (fDist != 0.0f)
                {
                    kDirection /= fDist;
                }
                break;
            }
            case 2: {
                fDist = kBombAxis.Dot(kDiff);
                if (fDist < 0.0f)
                {
                    fDist = -fDist;
                    kDirection = -kBombAxis;
                }
                else
                {
                    kDirection = kBombAxis;
                }
                break;
            }
            }

            float fVolumeScale = 1.0f;
            if (m_eBombDecayType == 1)
            {
                fVolumeScale = (m_fDistanceDecay - fDist) / m_fDistanceDecay;
            }
            else if (m_eBombDecayType == 2)
            {
                fVolumeScale = expf(-fDist / m_fDistanceDecay);
            }

            pkInfo->m_kValue += (m_fDeltaVelocity * fVolumeScale * fDeltaT) * kDirection;
        }
    }
}
