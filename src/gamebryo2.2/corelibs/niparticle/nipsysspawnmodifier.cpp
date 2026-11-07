#include "NiRefObject_inline.h"

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiPSysBoundUpdateModifier.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiPSysSpawnModifier.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/Mat3.h"
#include "../../../../include/NiPoint3.h"

__forceinline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes,
                                                     unsigned int* sizes, unsigned int count)
{
    unsigned int read = m_pfnRead(this, buffer, bytes, sizes, count);
    m_uiAbsoluteCurrentPos += read;
    return read;
}

__forceinline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes,
                                                      unsigned int* sizes, unsigned int count)
{
    unsigned int written = m_pfnWrite(this, buffer, bytes, sizes, count);
    m_uiAbsoluteCurrentPos += written;
    return written;
}

template <class T>
__forceinline void NiBinaryStreamLoad(NiBinaryStream& stream, T* value, unsigned int count = 1)
{
    unsigned int size = sizeof(T);
    stream.BinaryRead(value, sizeof(T) * count, &size, 1);
}

template <class T> __forceinline void ReadBinaryValue(NiStream& stream, T& value)
{
    NiBinaryStreamLoad(*stream.m_pkIstr, &value, 1);
}

// Calls the base NiPSysModifier::LoadBinary, then loads eight values from kStream via a helper.
// @fnv 0x00c247f0
void NiPSysSpawnModifier::LoadBinary(NiStream& kStream)
{
    NiPSysModifier::LoadBinary(kStream);
    ReadBinaryValue(kStream, m_usSpawnGenerationCount);
    ReadBinaryValue(kStream, m_fSpawnPercentage);
    ReadBinaryValue(kStream, m_usMinimumParticlesToSpawn);
    ReadBinaryValue(kStream, m_usMaximumParticlesToSpawn);
    ReadBinaryValue(kStream, m_fSpawnedSpeedChaos);
    ReadBinaryValue(kStream, m_fSpawnDirectionChaos);
    ReadBinaryValue(kStream, m_fYValue);
    ReadBinaryValue(kStream, m_fLifeSpanVariation);
}

// @fnv 0x00c2d6d0
void NiPSysBoundUpdateModifier::LinkObject(NiStream& kStream)
{
    NiPSysModifier::LinkObject(kStream);
}

// @fnv 0x00c2d6e0
bool NiPSysBoundUpdateModifier::IsEqual(NiObject* pkObject) const
{
    if (!NiPSysModifier::IsEqual(pkObject))
        return false;

    NiPSysBoundUpdateModifier* pkModifier = static_cast<NiPSysBoundUpdateModifier*>(pkObject);
    return pkModifier->m_usUpdateSkip == m_usUpdateSkip ? true : false;
}

// @fnv 0x00c2d710
const NiRTTI* NiPSysBoundUpdateModifier::GetRTTI() const
{
    return &ms_kRTTI;
}

extern "C" const NiRTTI g_01202550;

// @fnv 0x00c23ce0
// src: COMMUNITY 0x00c23ce0
const NiRTTI* __cdecl NiPSysSpawnModifier_GetRTTI()
{
    return &g_01202550;
}

extern "C" void __cdecl __Dummy_00b6fef0(void*, int);
void __cdecl FUN_00c31750();

// The shared spawn header does not declare these entry points yet. The unused
// second register argument keeps the original thiscall ABI without a stand-in class.
// @fnv 0x00c23cf0
NiPSysSpawnModifier* __fastcall DestroySpawnModifier(NiPSysSpawnModifier* modifier, void*, int param)
{
    FUN_00c31750();
    if (param & 1)
        __Dummy_00b6fef0(modifier, 0x34);
    return modifier;
}

// Compares this object with pkObject: checks IsEqual and that eight stored values match, returning true only if all are equal.
// @fnv 0x00c23b70
bool __fastcall SpawnModifiersEqual(const NiPSysSpawnModifier* modifier, void*, NiObject* pkObject)
{
    NiPSysSpawnModifier* pkDest = static_cast<NiPSysSpawnModifier*>(pkObject);
    if (modifier->NiPSysModifier::IsEqual(pkObject) && pkDest->m_usSpawnGenerationCount == modifier->m_usSpawnGenerationCount &&
        pkDest->m_fSpawnPercentage == modifier->m_fSpawnPercentage &&
        pkDest->m_usMinimumParticlesToSpawn == modifier->m_usMinimumParticlesToSpawn &&
        pkDest->m_usMaximumParticlesToSpawn == modifier->m_usMaximumParticlesToSpawn &&
        pkDest->m_fSpawnedSpeedChaos == modifier->m_fSpawnedSpeedChaos &&
        pkDest->m_fSpawnDirectionChaos == modifier->m_fSpawnDirectionChaos && pkDest->m_fYValue == modifier->m_fYValue &&
        pkDest->m_fLifeSpanVariation == modifier->m_fLifeSpanVariation)
        return true;
    return false;
}

// NiPSysModifier's viewer-string entry point is not declared by its shared header.
void __cdecl FUN_00c319e0();

char* __cdecl _FUN_00a7d330(void* value);
char* __cdecl NiGetViewerString_00a7d490(char const* name, unsigned short value);
char* __cdecl NiGetViewerString_00a7d550(char const* name, float value);

// Appends formatted spawn-setting name/value strings to the StrArr, growing it when full.
// @fnv 0x00c24a50
void __fastcall AppendSpawnSettingsStrings(NiPSysSpawnModifier* modifier, void*, StrArr* strings)
{
    typedef void (__thiscall* ViewerStrings)(NiPSysModifier*, StrArr*);
    reinterpret_cast<ViewerStrings>(&FUN_00c319e0)(modifier, strings);

    {
        char* value = _FUN_00a7d330(*reinterpret_cast<void* const*>(&g_01202550));
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usMaxSize)
            strings->SetSize(index + strings->m_usGrowBy);
        strings->SetAt(index, value);
    }

    {
        char* value = NiGetViewerString_00a7d490("Num Spawn Generations", modifier->m_usSpawnGenerationCount);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usMaxSize)
            strings->SetSize(index + strings->m_usGrowBy);
        strings->SetAt(index, value);
    }

    {
        char* value = NiGetViewerString_00a7d550("Percentage Spawned", modifier->m_fSpawnPercentage);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usMaxSize)
            strings->SetSize(index + strings->m_usGrowBy);
        strings->SetAt(index, value);
    }

    {
        char* value = NiGetViewerString_00a7d490("Min Num to Spawn", modifier->m_usMinimumParticlesToSpawn);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usMaxSize)
            strings->SetSize(index + strings->m_usGrowBy);
        strings->SetAt(index, value);
    }

    {
        char* value = NiGetViewerString_00a7d490("Max Num to Spawn", modifier->m_usMaximumParticlesToSpawn);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usMaxSize)
            strings->SetSize(index + strings->m_usGrowBy);
        strings->SetAt(index, value);
    }

    {
        char* value = NiGetViewerString_00a7d550("Spawn Speed Chaos", modifier->m_fSpawnedSpeedChaos);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usMaxSize)
            strings->SetSize(index + strings->m_usGrowBy);
        strings->SetAt(index, value);
    }

    {
        char* value = NiGetViewerString_00a7d550("Spawn Dir Chaos", modifier->m_fSpawnDirectionChaos);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usMaxSize)
            strings->SetSize(index + strings->m_usGrowBy);
        strings->SetAt(index, value);
    }

    {
        char* value = NiGetViewerString_00a7d550("Life Span", modifier->m_fYValue);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usMaxSize)
            strings->SetSize(index + strings->m_usGrowBy);
        strings->SetAt(index, value);
    }

    {
        char* value = NiGetViewerString_00a7d550("Life Span Variation", modifier->m_fLifeSpanVariation);
        unsigned int index = strings->m_usSize;
        if (index >= strings->m_usMaxSize)
            strings->SetSize(index + strings->m_usGrowBy);
        strings->SetAt(index, value);
    }
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_010be124;

// @fnv 0x00c23d10
NiPSysSpawnModifier* __fastcall CloneSpawnModifier(NiPSysSpawnModifier* modifier, void*, CloningProcess& process)
{
    NiPSysSpawnModifier* pkNew = (NiPSysSpawnModifier*)Object_DispatchCommandFour(0x34);
    if (pkNew != 0)
    {
        pkNew->NiPSysModifier::NiPSysModifier();
        pkNew->m_fSpawnPercentage = 1.0f;
        pkNew->m_fSpawnedSpeedChaos = 0.0f;
        pkNew->m_fSpawnDirectionChaos = 0.0f;
        *(int*)pkNew = (int)&DAT_010be124;
        pkNew->m_fYValue = 0.0f;
        pkNew->m_usSpawnGenerationCount = 1;
        pkNew->m_fLifeSpanVariation = 0.0f;
        pkNew->m_usMinimumParticlesToSpawn = 1;
        pkNew->m_usMaximumParticlesToSpawn = 1;
    }
    else
    {
        pkNew = 0;
    }
    modifier->NiPSysModifier::CopyMemberData(pkNew, process);
    pkNew->m_usSpawnGenerationCount = modifier->m_usSpawnGenerationCount;
    pkNew->m_fSpawnPercentage = modifier->m_fSpawnPercentage;
    pkNew->m_usMinimumParticlesToSpawn = modifier->m_usMinimumParticlesToSpawn;
    pkNew->m_usMaximumParticlesToSpawn = modifier->m_usMaximumParticlesToSpawn;
    pkNew->m_fSpawnedSpeedChaos = modifier->m_fSpawnedSpeedChaos;
    pkNew->m_fSpawnDirectionChaos = modifier->m_fSpawnDirectionChaos;
    pkNew->m_fYValue = modifier->m_fYValue;
    pkNew->m_fLifeSpanVariation = modifier->m_fLifeSpanVariation;
    return pkNew;
}

template <class T> __forceinline void BinaryStreamSave(NiBinaryStream& stream, const T* value, unsigned int count = 1)
{
    unsigned int size = sizeof(T);
    stream.BinaryWrite(value, sizeof(T) * count, &size, 1);
}

template <class T> __forceinline void StreamSaveBinary(NiStream& stream, const T& value)
{
    BinaryStreamSave(*stream.m_pkOstr, &value, 1);
}

// Saves the spawn modifier fields after calling the base class save routine.
// @fnv 0x00c24920
void __fastcall SaveSpawnModifier(NiPSysSpawnModifier* modifier, void*, NiStream& stream)
{
    modifier->NiPSysModifier::SaveBinary(stream);
    StreamSaveBinary(stream, modifier->m_usSpawnGenerationCount);
    StreamSaveBinary(stream, modifier->m_fSpawnPercentage);
    StreamSaveBinary(stream, modifier->m_usMinimumParticlesToSpawn);
    StreamSaveBinary(stream, modifier->m_usMaximumParticlesToSpawn);
    StreamSaveBinary(stream, modifier->m_fSpawnedSpeedChaos);
    StreamSaveBinary(stream, modifier->m_fSpawnDirectionChaos);
    StreamSaveBinary(stream, modifier->m_fYValue);
    StreamSaveBinary(stream, modifier->m_fLifeSpanVariation);
}

#include <string.h>
// Adds the corresponding elements of two matrices.
// @fnv 0x00c23c00
__declspec(noinline) Mat3 Mat3::operator+(const Mat3& other) const
{
    Mat3 result = *this;
    result.m00 += other.m00;
    result.m01 += other.m01;
    result.m02 += other.m02;
    result.m10 += other.m10;
    result.m11 += other.m11;
    result.m12 += other.m12;
    result.m20 += other.m20;
    result.m21 += other.m21;
    result.m22 += other.m22;
    return result;
}

// Subtracts the corresponding elements of two matrices.
// @fnv 0x00c23c70
__declspec(noinline) Mat3 Mat3::operator-(const Mat3& other) const
{
    Mat3 result = *this;
    result.m00 -= other.m00;
    result.m01 -= other.m01;
    result.m02 -= other.m02;
    result.m10 -= other.m10;
    result.m11 -= other.m11;
    result.m12 -= other.m12;
    result.m20 -= other.m20;
    result.m21 -= other.m21;
    result.m22 -= other.m22;
    return result;
}

#include <stdlib.h>
#include <math.h>
struct ParticleInfoX
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
};

struct PSysDataX
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
    ParticleInfoX* m_pkParticleInfo;
};

struct ParticleSystemX
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
    PSysDataX* m_spGeometryData;
};

inline float RandomFloat0To1()
{
    return (float)(rand() / (double)RAND_MAX);
}

// @fnv 0x00c23db0
void __fastcall SpawnParticles(NiPSysSpawnModifier* modifier, void*, float afTime, float fTime,
                               unsigned short usOldIndex, ParticleSystemX* pkSystem)
{
    PSysDataX* pkData = pkSystem->m_spGeometryData;
    if (pkData->m_pkParticleInfo[usOldIndex].m_usFirstValue < modifier->m_usSpawnGenerationCount &&
        !(RandomFloat0To1() > modifier->m_fSpawnPercentage))
    {
        float fNumToSpawn = (modifier->m_usMaximumParticlesToSpawn - modifier->m_usMinimumParticlesToSpawn) * RandomFloat0To1();
        unsigned short usExtra = (unsigned short)fNumToSpawn;
        if (fmod(fNumToSpawn, 1.0f) > 0.5f)
            usExtra++;
        unsigned short usNumToSpawn = modifier->m_usMinimumParticlesToSpawn + usExtra;
        if (usNumToSpawn == 0)
            usNumToSpawn = 1;
        for (unsigned short us = 0; us < usNumToSpawn; us++)
            modifier->UpdateSpawning(afTime, fTime, usOldIndex, pkSystem);
    }
}

extern "C" int __cdecl rand();
extern "C" const double DAT_01029790;
extern "C" const double DAT_01012070;
extern "C" const double DAT_0101ff40;
extern "C" const double DAT_01028338;
extern "C" const double DAT_01012060;
extern "C" const double DAT_01011588;
extern "C" const float DAT_011aeb34;
extern "C" const float DAT_010c09c0;
extern "C" const float DAT_01012054;
extern "C" const float DAT_011f52e0[];
extern "C" const float DAT_011f4ae0[];
extern "C" const unsigned short DAT_010be248;


inline NiPoint3::NiPoint3(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}

inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}

struct ColA
{
    float r, g, b, a;
};

inline Mat3::Mat3()
{}

__declspec(noinline) Mat3 Mat3::operator*(float f) const
{
    Mat3 result;
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            (&result.m00)[row * 3 + col] = (&m00)[row * 3 + col] * f;
    return result;
}
__declspec(noinline) Mat3 Mat3::operator*(const Mat3 & o) const
{
    Mat3 result;
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            (&result.m00)[row * 3 + col] = (&m00)[row * 3 + 0] * (&o.m00)[0 * 3 + col] + (&m00)[row * 3 + 1] * (&o.m00)[1 * 3 + col] + (&m00)[row * 3 + 2] * (&o.m00)[2 * 3 + col];
    return result;
}

struct Xform
{
    Mat3 m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
    NiPoint3 operator*(const NiPoint3& p) const;
    void Invert(Xform& dst) const;
};

struct PInfo
{
    NiPoint3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
};

struct PSysData
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual unsigned short GetParticleVertexCount();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    NiPoint3* m_pkVertex;
    int unk24;
    ColA* m_pkColor;
    int unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48;
    float* m_pfRadii;
    int unk50;
    float* m_pfSizes;
    int unk58;
    float* m_pfRotationAngles;
    NiPoint3* m_pkRotationAxes;
    int unk64, unk68, unk6C;
    PInfo* m_pkParticleInfo;
    float* m_pfRotationSpeeds;
};

struct PSys
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
    Xform m_kWorldSpaceTransform;
    int unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4;
    PSysData* m_spGeometryData;
    void InitializeSpawnedParticle(unsigned short usNewParticle);
};

static inline float UnitRandom()
{
    return (float)(rand() / DAT_01029790);
}

static inline void FastSinCos(float f, float& sine, float& cosine)
{
    int index = (int)(f * (DAT_01028338 / DAT_011aeb34)) & 0x1ff;
    sine = DAT_011f52e0[index];
    cosine = DAT_011f4ae0[index];
}

static inline NiPoint3 MulMV(Mat3 m, const NiPoint3& p)
{
    NiPoint3 r;
    r.x = m.m00 * p.x + m.m01 * p.y + m.m02 * p.z;
    r.y = m.m10 * p.x + m.m11 * p.y + m.m12 * p.z;
    // Preserve the original x87 intermediate precision and evaluation order.
    r.z = m.m20 * p.x + (double)(m.m21 * p.y) + m.m22 * p.z;
    return r;
}

static inline NiPoint3 InverseMulMV(Mat3 m, const NiPoint3& p)
{
    NiPoint3 r;
    r.x = (double)(m.m00 * p.x) + m.m01 * p.y + m.m02 * p.z;
    r.y = (double)(m.m10 * p.x) + m.m11 * p.y + m.m12 * p.z;
    r.z = (double)(m.m20 * p.x) + m.m21 * p.y + m.m22 * p.z;
    return r;
}

__declspec(noinline) NiPoint3 Xform::operator*(const NiPoint3 & p) const
{
    NiPoint3 result = MulMV(m_kOrientation, p);
    result.x = result.x * m_fScale + m_kTranslation.x;
    result.y = result.y * m_fScale + m_kTranslation.y;
    result.z = result.z * m_fScale + m_kTranslation.z;
    return result;
}

struct Element
{
    float value;
    Element& operator=(float f)
    {
        value = f;
        return *this;
    }
    operator float() const
    {
        return value;
    }
};
struct LocalPoint
{
    float x;
    Element y;
    float z;
};

// @fnv 0x00c23ee0
void NiPSysSpawnModifier::UpdateSpawning(float afTime, float fTimeDelta, unsigned short usOldIndex,
                                        ParticleSystemX* pkOldSystem)
{
    PSys* pkOldPSystem = reinterpret_cast<PSys*>(pkOldSystem);
    NiPoint3 kMotionVelocity;
    (void)kMotionVelocity.x;
    PSysData* pkOldData = pkOldPSystem->m_spGeometryData;
    PInfo* pkOldInfo = &pkOldData->m_pkParticleInfo[usOldIndex];
    NiPoint3* pkOldVerts = pkOldData->m_pkVertex;
    ColA* pkOldColors = pkOldData->m_pkColor;
    float* pfOldRadii = pkOldData->m_pfRadii;
    float* pfOldSizes = pkOldData->m_pfSizes;
    float* pfOldRotAngles = pkOldData->m_pfRotationAngles;
    NiPoint3* pkOldRotAxes = pkOldData->m_pkRotationAxes;
    float* pfOldRotSpeeds = pkOldData->m_pfRotationSpeeds;

    NiPoint3 kPosition = pkOldVerts[usOldIndex];
    kMotionVelocity = pkOldInfo->m_kValue;

    PSys* pkTarget = (PSys*)m_pkTarget;
    if (pkOldPSystem != pkTarget)
    {
        Xform kOldWorld = pkOldPSystem->m_kWorldSpaceTransform;
        (void)kOldWorld.m_kOrientation.m00;
        kPosition = kOldWorld * kPosition;
        kMotionVelocity = MulMV(kOldWorld.m_kOrientation, kMotionVelocity);
        Xform kTargetWorld = pkTarget->m_kWorldSpaceTransform;
        kTargetWorld.Invert(kOldWorld);
        kPosition = kOldWorld * kPosition;
        kMotionVelocity = InverseMulMV(kOldWorld.m_kOrientation, kMotionVelocity);
    }

    PSysData* pkData = ((PSys*)m_pkTarget)->m_spGeometryData;
    unsigned short usNewIndex = pkData->GetParticleVertexCount();
    if (usNewIndex == DAT_010be248)
        return;

    float fPreviousTime = afTime - fTimeDelta;
    PInfo* pkNewInfo = &pkData->m_pkParticleInfo[usNewIndex];
    NiPoint3* pkNewVerts = pkData->m_pkVertex;
    ColA* pkNewColors = pkData->m_pkColor;
    float* pfNewRadii = pkData->m_pfRadii;
    float* pfNewSizes = pkData->m_pfSizes;
    float* pfNewRotAngles = pkData->m_pfRotationAngles;
    NiPoint3* pkNewRotAxes = pkData->m_pkRotationAxes;
    float* pfNewRotSpeeds = pkData->m_pfRotationSpeeds;

    float fLenSq = (double)(kMotionVelocity.x * kMotionVelocity.x + kMotionVelocity.y * kMotionVelocity.y +
                            kMotionVelocity.z * kMotionVelocity.z);
    float fLen = sqrtf(fLenSq);

    float fSpeedVar = m_fSpawnedSpeedChaos * UnitRandom();
    float fSpeed = (fSpeedVar + DAT_01012070) * fLen;

    float fDecl = (float)(m_fSpawnDirectionChaos * UnitRandom() * DAT_0101ff40);
    float fRand = UnitRandom();
    float fSinDecl, fCosDecl;
    FastSinCos(fDecl, fSinDecl, fCosDecl);
    float fPlanar = fRand * DAT_011aeb34;
    float fSinPlanar, fCosPlanar;
    FastSinCos(fPlanar, fSinPlanar, fCosPlanar);
    NiPoint3 kWorldPosition;
    kWorldPosition.x = fSinDecl * fCosPlanar;
    kWorldPosition.y = fSinDecl * fSinPlanar;
    kWorldPosition.z = fCosDecl;

    Mat3 kRot = Mat3::IDENTITY;

    {
        NiPoint3 kNeg = -kMotionVelocity;
        Mat3 kSkew;
        kSkew.m00 = 0.0f;
        kSkew.m10 = 0.0f;
        kSkew.m01 = 0.0f;
        kSkew.m11 = 0.0f;
        kSkew.m20 = kMotionVelocity.x;
        kSkew.m21 = kMotionVelocity.y;
        kSkew.m02 = kNeg.x;
        kSkew.m12 = kNeg.y;
        kSkew.m22 = 0.0f;
        NiPoint3 kAxis(kMotionVelocity.y, -kMotionVelocity.x, 0.0f);

        LocalPoint kCross;
        kCross.x = kWorldPosition.y * kMotionVelocity.z - kWorldPosition.z * kMotionVelocity.y;
        kCross.y = kWorldPosition.z * kMotionVelocity.x - kWorldPosition.x * kMotionVelocity.z;
        kCross.z = kWorldPosition.x * kMotionVelocity.y - kWorldPosition.y * kMotionVelocity.x;
        float fDot = (float)((double)(kCross.x * kAxis.x) + kAxis.y * kCross.y + kCross.z * DAT_01012060);

        if (fDot > DAT_010c09c0)
        {
            kRot = kRot + kSkew *
                              (kRot + kSkew * ((fLen - kMotionVelocity.z) / (kMotionVelocity.x * kMotionVelocity.x +
                                                                             kMotionVelocity.y * kMotionVelocity.y))) *
                              (1.0f / fLen);
        }
        else if (-fDot > DAT_010c09c0)
        {
            kRot = kRot - kSkew *
                              (kRot - kSkew * ((fLen - kMotionVelocity.z) / (kMotionVelocity.x * kMotionVelocity.x +
                                                                             kMotionVelocity.y * kMotionVelocity.y))) *
                              (1.0f / fLen);
        }
        else if (kMotionVelocity.z < kAxis.z)
        {
            kRot = Mat3(NiPoint3(DAT_01012054, 0.0f, 0.0f), NiPoint3(0.0f, DAT_01012054, 0.0f), NiPoint3(0.0f, 0.0f, DAT_01012054));
        }
    }

    Mat3 kScaled;
    kScaled.m00 = kRot.m00 * fSpeed;
    kScaled.m01 = kRot.m01 * fSpeed;
    kScaled.m02 = kRot.m02 * fSpeed;
    kScaled.m10 = kRot.m10 * fSpeed;
    kScaled.m11 = kRot.m11 * fSpeed;
    kScaled.m12 = kRot.m12 * fSpeed;
    kScaled.m20 = kRot.m20 * fSpeed;
    kScaled.m21 = kRot.m21 * fSpeed;
    kScaled.m22 = kRot.m22 * fSpeed;
    kWorldPosition = MulMV(kScaled, kWorldPosition);
    pkNewInfo->m_kValue = kWorldPosition;
    pkNewInfo->m_fXValue = fPreviousTime;
    pkNewInfo->m_fYValue = (float)((UnitRandom() - DAT_01011588) * m_fLifeSpanVariation + m_fYValue);
    pkNewInfo->m_usFirstValue = pkOldInfo->m_usFirstValue + 1;

    pkNewVerts[usNewIndex] = kPosition;

    if (pkOldColors && pkNewColors)
        pkNewColors[usNewIndex] = pkOldColors[usOldIndex];
    if (pfOldRadii && pfNewRadii)
        pfNewRadii[usNewIndex] = pfOldRadii[usOldIndex];
    if (pfOldSizes && pfNewSizes)
        pfNewSizes[usNewIndex] = pfOldSizes[usOldIndex];
    if (pfOldRotAngles && pfNewRotAngles)
    {
        pfNewRotAngles[usNewIndex] = pfOldRotAngles[usOldIndex];
        pfNewRotSpeeds[usNewIndex] = pfOldRotSpeeds[usOldIndex];
    }
    if (pkOldRotAxes && pkNewRotAxes)
        pkNewRotAxes[usNewIndex] = pkOldRotAxes[usOldIndex];

    pkNewInfo->m_fZValue = afTime - pkNewInfo->m_fXValue;
    ((PSys*)m_pkTarget)->InitializeSpawnedParticle(usNewIndex);
}
