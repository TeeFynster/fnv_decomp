#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiPSysBoundUpdateModifier.h"
#include "../../../../include/NiPSysData.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiPSysPositionModifier.h"
#include "../../../../include/NiParticleSystem.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiRTTI.h"

#include <new>
#include <string.h>

// Supplementary methods absent from the shared modifier declaration. All storage
// and inherited interfaces come from NiPSysBoundUpdateModifier.
class BoundUpdateOperations : public NiPSysBoundUpdateModifier
{
public:
    void SetTargetSystem(NiParticleSystem* system);
    void GetViewerStrings(NiViewerStringsArray* strings);
    void UpdateBounds(float time, NiPSysData* data);
    void UpdateMeshBounds(float time, NiPSysData* data);
    void UpdateMultiVertexBounds(float time, NiPSysData* data);
    void SetUpdateSkip(short count);
};

class MultiVertexParticleData : public NiPSysData
{
public:
    unsigned short GetVertexCount(unsigned short particle);
    NiPoint3* GetSlotData(unsigned short particle, unsigned short vertex);
    float GetVertexSize(unsigned short particle, unsigned short vertex);
    float GetInnerValue(unsigned short particle, unsigned short vertex);
};

inline NiBinaryStream& NiStream::Istr()
{
    return **reinterpret_cast<NiBinaryStream**>((char*)this + 0x24c);
}
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>((char*)this + 0x250);
}
inline unsigned int NiStream::GetFileVersion() const
{
    return *reinterpret_cast<const unsigned int*>((const char*)this + 0xd8);
}
inline unsigned int NiBinaryStream::BinaryRead(void* data, unsigned int bytes,
    unsigned int* sizes, unsigned int count)
{
    unsigned int read = (*reinterpret_cast<ReadFunction*>((char*)this + 8))(this, data, bytes, sizes, count);
    *reinterpret_cast<unsigned int*>((char*)this + 4) += read;
    return read;
}

extern "C" double __cdecl sqrt(double);
inline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c) {}
inline NiPoint3 NiPoint3::operator*(float f) const
{
    return NiPoint3(x * f, y * f, z * f);
}
inline float NiPoint3::Length() const
{
    float sq = x * x + y * y + z * z;
    return (float)sqrt(sq);
}
// Temporaries call the non-const overload: same inline body.
inline float NiPoint3::Length()
{
    float sq = x * x + y * y + z * z;
    return (float)sqrt(sq);
}
inline NiBound::NiBound() {}
inline NiBound::NiBound(const NiBound& bound)
{
    memcpy(this, &bound, sizeof(NiBound));
}
inline void CopyBoundCenter(NiPoint3& destination, const NiPoint3& source)
{
    memcpy(&destination, &source, sizeof(NiPoint3));
}
inline bool NiPSysData::IsKindOfType(const NiRTTI* type) const
{
    const NiRTTI* iter = GetRTTI();
    while (iter)
    {
        if (iter == type)
            return true;
        iter = iter->m_pBaseRTTI;
    }
    return false;
}

// src/gamebryo2.2/corelibs/niparticle/nipsysboundupdatemodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysboundupdatemodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Clears the bound-update flag on the previous system and sets it on the new target.
// @fnv 0x00c2dc70
void BoundUpdateOperations::SetTargetSystem(NiParticleSystem* system)
{
    NiParticleSystem* pOldSystem = m_pkTarget;
    if (pOldSystem)
        ((char*)pOldSystem)[0xd9] = 0;
    if (system)
        ((char*)system)[0xd9] = 1;
    NiPSysModifier::SetTargetSystem(system);
}

struct MM
{
    void _DeallocateAlias(void* p);
};
extern MM g_memoryManager;
extern int DAT_010c0134;
void __cdecl _delete(void* p, unsigned int s);

// Restores the vtable, releases the bounds, destroys the base, and optionally deletes this.
// @fnv 0x00c2dca0
void* NiPSysBoundUpdateModifier::Destroy(unsigned int auiFlags)
{
    void* p = m_pkBounds;
    *(void**)this = (void*)&DAT_010c0134;
    g_memoryManager._DeallocateAlias(p);
    reinterpret_cast<NiPSysPositionModifier*>(this)->NiPSysPositionModifier::~NiPSysPositionModifier();
    if (auiFlags & 1)
        _delete(this, 0x20);
    return this;
}

inline NiPSysBoundUpdateModifier* InitializeBoundUpdateModifier(void* memory) throw()
{
    // Preserve the original position-modifier initialization before installing
    // the bound-update vtable and initializing the shared extension fields.
    ::new (memory) NiPSysPositionModifier;
    NiPSysBoundUpdateModifier* object = static_cast<NiPSysBoundUpdateModifier*>(memory);
    *(void**)object = (void*)&DAT_010c0134;
    object->m_usUpdateSkip = 0;
    object->m_usUpdateSkipCounter = 0;
    object->m_pkBounds = 0;
    return object;
}

// @fnv 0x00c2dec0
NiObject* NiPSysBoundUpdateModifier::MakeClone(CloningProcess& kCloning)
{
    void* memory = BSFadeNode::operator new(sizeof(NiPSysBoundUpdateModifier));
    NiPSysBoundUpdateModifier* pkObject = memory ? InitializeBoundUpdateModifier(memory) : 0;
    CopyMemberData(pkObject, kCloning);
    pkObject->SetUpdateSkipCounter(static_cast<unsigned short>(m_usUpdateSkip));
    return (NiObject*)pkObject;
}

// @fnv 0x00c2e3f0
void NiPSysBoundUpdateModifier::SaveBinary(NiStream& stream)
{
    NiPSysModifier::SaveBinary(stream);
    NiBinaryStream* __restrict out = stream.GetBinaryStream();
    unsigned int size = 2;
    *reinterpret_cast<unsigned int*>((char*)out + 4) +=
        (*reinterpret_cast<NiBinaryStream::WriteFunction*>((char*)out + 12))(out, &m_usUpdateSkip, 2, &size, 1);
}

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void LoadBoundUpdateValue(NiStream& kStream, T& value)
{
    NiBinaryStreamLoad(kStream.Istr(), &value);
}

// Loads the modifier base data, reads the update skip, and rebuilds the bounds array.
// @fnv 0x00c2e370
void NiPSysBoundUpdateModifier::LoadBinary(NiStream& kStream)
{
    NiPSysModifier::LoadBinary(kStream);
    if (kStream.GetFileVersion() <= 0x0A010064)
    {
        unsigned short usFlags;
        LoadBoundUpdateValue(kStream, usFlags);
        static_cast<BoundUpdateOperations*>(this)->SetUpdateSkip(usFlags);
    }
    else
    {
        LoadBoundUpdateValue(kStream, m_usUpdateSkip);
        static_cast<BoundUpdateOperations*>(this)->SetUpdateSkip(m_usUpdateSkip);
    }
}

extern "C" void* g_01202788;

struct NiStrTable
{
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    void SetSize(unsigned int n);
    void SetAt(unsigned int i, char*& v);
    void Add(char* v)
    {
        unsigned int n = unk0A;
        if (n >= unk08)
        {
            SetSize(n + unk0E);
        }
        SetAt(n, v);
    }
};

// The shared base does not yet declare its viewer-string override.
class ModifierViewerStrings : public NiPSysModifier
{
public:
    void GetViewerStrings(NiViewerStringsArray* strings);
};

extern "C" char* __cdecl NiViewerStrings_NiGetViewerString_Title(char* s);
extern "C" char* __cdecl NiGetViewerString_00a7d450(const char* key, unsigned short value);

// @fnv 0x00c2e430
void BoundUpdateOperations::GetViewerStrings(NiViewerStringsArray* strings)
{
    reinterpret_cast<ModifierViewerStrings*>(this)->ModifierViewerStrings::GetViewerStrings(strings);
    reinterpret_cast<NiStrTable*>(strings)->Add(NiViewerStrings_NiGetViewerString_Title((char*)g_01202788));
    reinterpret_cast<NiStrTable*>(strings)->Add(NiGetViewerString_00a7d450("Update Skip", m_usUpdateSkip));
}

extern NiBound DAT_011f4288;

struct Particle
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NiBound* m_pkBound;
};

struct BoundDataBlock
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NiBound* m_pkBound;
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
    Particle** m_pkParticles;
};

// Merges particle bounds into the current bound slot, resets the remaining slots, and advances m_usUpdateSkipCounter cyclically.
// @fnv 0x00c2dce0
void BoundUpdateOperations::UpdateMeshBounds(float fTime, NiPSysData* pkTarget)
{
    unsigned short usNumParticles = pkTarget->m_usActive;
    BoundDataBlock* pkData = *reinterpret_cast<BoundDataBlock**>((char*)pkTarget + 0x7c);

    if (m_usUpdateSkip == -1)
    {
        SetUpdateSkip((short)(pkTarget->m_usVertices / 20 + 1));
    }

    int iCount = usNumParticles;
    int iMaxUpdateSkip = iCount / 20 + 1;
    int iSkip = m_usUpdateSkip < iMaxUpdateSkip ? m_usUpdateSkip : iMaxUpdateSkip;
    if (iSkip <= 1)
    {
        iSkip = 1;
    }

    Particle* pFirstParticle = pkData->m_pkParticles[0];
    NiBound* pkFirstBound = pFirstParticle->m_pkBound ? pFirstParticle->m_pkBound : &DAT_011f4288;
    NiBound kBound = *pkFirstBound;
    for (int i = m_usUpdateSkipCounter; i < iCount; i += iSkip)
    {
        Particle* pkParticle = pkData->m_pkParticles[i];
        NiBound* pkParticleBound = pkParticle->m_pkBound;
        if (!pkParticleBound)
        {
            pkParticleBound = &DAT_011f4288;
        }
        kBound.Merge(pkParticleBound);
    }

    CopyBoundCenter(m_pkBounds[m_usUpdateSkipCounter].m_kCenter, kBound.m_kCenter);
    m_pkBounds[m_usUpdateSkipCounter].m_fRadius = kBound.m_fRadius;

    for (int i = iSkip; i < m_usUpdateSkip; ++i)
    {
        CopyBoundCenter(m_pkBounds[i].m_kCenter, NiPoint3::ZERO);
        m_pkBounds[i].m_fRadius = 0.0f;
    }

    for (int i = 1; i < iSkip; ++i)
    {
        if (m_pkBounds[i].m_fRadius != 0.0f)
        {
            kBound.Merge(&m_pkBounds[i]);
        }
    }

    if (kBound.m_fRadius == 0.0f)
    {
        kBound.m_fRadius = (*pkTarget->m_pfSizes) * (*pkTarget->m_pfRadii);
    }
    float fRadius = kBound.m_fRadius;
    NiBound* pkDest = pkData->m_pkBound;
    CopyBoundCenter(pkDest->m_kCenter, kBound.m_kCenter);
    pkDest->m_fRadius = fRadius;
    m_usUpdateSkipCounter++;
    if ((int)m_usUpdateSkipCounter >= iSkip)
    {
        m_usUpdateSkipCounter = 0;
    }
}

template <class T> inline T kFirstBoundsPointEntry(const T& a, const T& b)
{
    return a < b ? a : b;
}
template <class T> inline T kBoundsMaximum(const T& a, const T& b)
{
    return a > b ? a : b;
}

// Computes the bounding sphere for the current bound slot from position and radius data, merges it into the overall bound, and advances the current bound index.
// @fnv 0x00c2d880
void BoundUpdateOperations::UpdateMultiVertexBounds(float time, NiPSysData* apBounds)
{
    unsigned short count = apBounds->m_usActive;
    if (m_usUpdateSkip == -1)
        SetUpdateSkip(apBounds->m_usVertices / 10 + 1);
    int stride = kFirstBoundsPointEntry((int)m_usUpdateSkip, count / 10 + 1);
    stride = kBoundsMaximum(stride, 1);
    float lx = apBounds->m_pkVertex[0].x;
    float ly = apBounds->m_pkVertex[0].y;
    float fMinZ = apBounds->m_pkVertex[0].z;
    float hx = lx;
    float hy = ly;
    float fMaxZ = fMinZ;
    for (int i = m_usUpdateSkipCounter; i < count; i += stride)
    {
        unsigned short n = static_cast<MultiVertexParticleData*>(apBounds)->GetVertexCount((unsigned short)i);
        for (unsigned short j = 0; j < n; ++j)
        {
            NiPoint3* p = static_cast<MultiVertexParticleData*>(apBounds)->GetSlotData((unsigned short)i, j);
            float r = static_cast<MultiVertexParticleData*>(apBounds)->GetVertexSize((unsigned short)i, j) *
                      static_cast<MultiVertexParticleData*>(apBounds)->GetInnerValue((unsigned short)i, j);
            double fTemp;
            fTemp = p->x - r;
            lx = kFirstBoundsPointEntry(lx, (float)fTemp);
            fTemp = p->x + r;
            hx = kBoundsMaximum(hx, (float)fTemp);
            fTemp = p->y - r;
            ly = kFirstBoundsPointEntry(ly, (float)fTemp);
            fTemp = p->y + r;
            hy = kBoundsMaximum(hy, (float)fTemp);
            fTemp = p->z - r;
            fMinZ = kFirstBoundsPointEntry(fMinZ, (float)fTemp);
            fTemp = p->z + r;
            fMaxZ = kBoundsMaximum(fMaxZ, (float)fTemp);
        }
    }
    NiPoint3 center = NiPoint3(hx + lx, hy + ly, fMaxZ + fMinZ) * 0.5f;
    CopyBoundCenter(m_pkBounds[m_usUpdateSkipCounter].m_kCenter, *reinterpret_cast<NiPoint3*>(&center));
    float rad = NiPoint3(hx - lx, hy - ly, fMaxZ - fMinZ).Length() * 0.5;
    m_pkBounds[m_usUpdateSkipCounter].m_fRadius = rad;
    for (int k = stride; k < m_usUpdateSkip; ++k)
    {
        CopyBoundCenter(m_pkBounds[k].m_kCenter, NiPoint3::ZERO);
        m_pkBounds[k].m_fRadius = 0;
    }
    NiBound kMergedBound;
    CopyBoundCenter(kMergedBound.m_kCenter, m_pkBounds[m_usUpdateSkipCounter].m_kCenter);
    kMergedBound.m_fRadius = m_pkBounds[m_usUpdateSkipCounter].m_fRadius;
    for (int k = 1; k < stride; ++k)
        if (m_pkBounds[k].m_fRadius != 0)
            kMergedBound.Merge(&m_pkBounds[k]);
    CopyBoundCenter(apBounds->m_kBound.m_kCenter, kMergedBound.m_kCenter);
    apBounds->m_kBound.m_fRadius = kMergedBound.m_fRadius;
    if (apBounds->m_kBound.m_fRadius == 0)
        apBounds->m_kBound.m_fRadius = apBounds->m_pfSizes[0] * apBounds->m_pfRadii[0];
    ++m_usUpdateSkipCounter;
    if (m_usUpdateSkipCounter >= stride)
        m_usUpdateSkipCounter = 0;
}

// Plain arithmetic temporaries retain the original floating-point evaluation.
struct LocalPoint3
{
    float x;
    float y;
    float z;
    LocalPoint3 operator+(const LocalPoint3& p) const
    {
        return LocalPoint3(x + p.x, y + p.y, z + p.z);
    }
    LocalPoint3 operator-(const LocalPoint3& p) const
    {
        return LocalPoint3(x - p.x, y - p.y, z - p.z);
    }
    LocalPoint3()
    {}
    LocalPoint3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
    {}
    LocalPoint3 operator*(double d) const
    {
        return LocalPoint3((float)(x * d), (float)(y * d), (float)(z * d));
    }
};

template<class T> inline void CopyBoundCenter(NiPoint3& destination, const T& source)
{
    memcpy(&destination, &source, sizeof(NiPoint3));
}

extern NiRTTI g_012027c0;
extern NiRTTI g_01202680;

// Computes the particle system's bounding sphere from sampled positions and radii, merging previous samples and storing the result in pkData->m_kBound.
// @fnv 0x00c2df20
void BoundUpdateOperations::UpdateBounds(float fTime, NiPSysData* pkData)
{
    unsigned short usNumParticles = pkData->m_usActive;
    if (usNumParticles <= 0)
    {
        CopyBoundCenter(pkData->m_kBound.m_kCenter, NiPoint3::ZERO);
        pkData->m_kBound.m_fRadius = 0.0f;
        m_usUpdateSkipCounter = 0;
        return;
    }
    if (pkData->IsKindOfType(&g_012027c0))
    {
        UpdateMeshBounds(fTime, pkData);
        return;
    }
    if (pkData->IsKindOfType(&g_01202680))
    {
        UpdateMultiVertexBounds(fTime, pkData);
        return;
    }
    if (m_usUpdateSkip == -1)
    {
        SetUpdateSkipCounter(pkData->m_usVertices / 50 + 1);
    }
    int pkPositions = usNumParticles / 50 + 1;
    int iStride = m_usUpdateSkip;
    if (iStride >= pkPositions)
        iStride = pkPositions;
    if (iStride <= 1)
        iStride = 1;
    LocalPoint3* j = reinterpret_cast<LocalPoint3*>(pkData->m_pkVertex);
    float* pkPositionArray = (float*)j;
    float m_fGridOriginX = j[0].x;
    float kDiff = j[0].y;
    float fMinZ = j[0].z;
    float kPointArrayBench;
    kPointArrayBench = m_fGridOriginX;
    float m_fWorldTransformCoefficient4 = kDiff;
    float fMaxZ = fMinZ;
    float* pkBoundEntry = pkData->m_pfRadii;
    float* y = pkData->m_pfSizes;
    int i = m_usUpdateSkipCounter;
    int k = i * 3;
    if (i < usNumParticles)
    {
        for (; i < usNumParticles;)
        {
            float fRadius = y[i] * pkBoundEntry[i];
            float lo = pkPositionArray[k] - fRadius;
            if (!(lo > m_fGridOriginX))
                m_fGridOriginX = lo;
            float hi = pkPositionArray[k] + fRadius;
            if (!(kPointArrayBench > hi))
                kPointArrayBench = hi;
            lo = pkPositionArray[k + 1] - fRadius;
            if (!(lo > kDiff))
                kDiff = lo;
            hi = pkPositionArray[k + 1] + fRadius;
            if (!(m_fWorldTransformCoefficient4 > hi))
                m_fWorldTransformCoefficient4 = hi;
            lo = pkPositionArray[k + 2] - fRadius;
            if (!(fMinZ < lo))
                fMinZ = lo;
            hi = pkPositionArray[k + 2] + fRadius;
            if (!(fMaxZ > hi))
                fMaxZ = hi;
            k += iStride * 3;
            i += iStride;
        }
    }
    LocalPoint3 res =
        LocalPoint3(kPointArrayBench, m_fWorldTransformCoefficient4, fMaxZ) + LocalPoint3(m_fGridOriginX, kDiff, fMinZ);
    CopyBoundCenter(m_pkBounds[m_usUpdateSkipCounter].m_kCenter, res * 0.5);
    LocalPoint3 afWorldOriginY;
    afWorldOriginY =
        LocalPoint3(kPointArrayBench, m_fWorldTransformCoefficient4, fMaxZ) - LocalPoint3(m_fGridOriginX, kDiff, fMinZ);
    float fExtentSq =
        afWorldOriginY.x * afWorldOriginY.x + afWorldOriginY.y * afWorldOriginY.y + afWorldOriginY.z * afWorldOriginY.z;
    float fExtent = (float)sqrt(fExtentSq);
    float fRadius = (float)(fExtent * 0.5);
    m_pkBounds[m_usUpdateSkipCounter].m_fRadius = fRadius;
    for (int k = iStride; k < m_usUpdateSkip; ++k)
    {
        CopyBoundCenter(m_pkBounds[k].m_kCenter, NiPoint3::ZERO);
        // Reload the array pointer for the radius store, preserving the original
        // indexed-address encoding after the center copy.
        (*reinterpret_cast<NiBound* volatile*>(&m_pkBounds))[k].m_fRadius = 0.0f;
    }
    NiBound kBound;
    CopyBoundCenter(kBound.m_kCenter, m_pkBounds[m_usUpdateSkipCounter].m_kCenter);
    kBound.m_fRadius = m_pkBounds[m_usUpdateSkipCounter].m_fRadius;
    if (1 < iStride)
    {
        for (int pkPositions = 1; pkPositions < iStride; ++pkPositions)
        {
            if (m_pkBounds[pkPositions].m_fRadius != 0.0f)
            {
                kBound.Merge(&m_pkBounds[pkPositions]);
            }
        }
    }
    pkData->m_kBound.m_fRadius = kBound.m_fRadius;
    CopyBoundCenter(pkData->m_kBound.m_kCenter, kBound.m_kCenter);
    if (kBound.m_fRadius == 0.0f)
    {
        pkData->m_kBound.m_fRadius = *(volatile float*)pkData->m_pfRadii * pkData->m_pfSizes[0];
    }
    if (++m_usUpdateSkipCounter >= iStride)
    {
        m_usUpdateSkipCounter = 0;
    }
}
