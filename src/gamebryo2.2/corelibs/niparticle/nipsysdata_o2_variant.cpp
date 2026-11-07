
// src/gamebryo2.2/corelibs/niparticle/nipsysdata_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/niparticle/nipsysdata.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiGeometryData.h"
#include "../../../../include/NiPSysData.h"
#include "../../../../include/NiParticlesData.h"
#include "../../../../include/NiQuaternion.h"
// NiStream.h supplies BSStreamHeader too; BSStreamHeader.h currently redeclares it.
#include "../../../../include/NiStream.h"
#include "nipsysdata_types_NiParticleInfo.h"
#include "MemoryManager.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiColorA.h"
extern MemoryManager g_memoryManager;
void* _NiMalloc(unsigned int size);
extern "C" void* fnv_zlib_memset(void* dst, int value, unsigned long size);

// The default geometry constructor is not declared by the shared header.
// Its no-argument thiscall ABI also accepts the object in ECX here.
void __fastcall ConstructGeometryData(NiGeometryData* data);
extern char* DAT_010a05e4;

// @fnv 0x00a963f0
NiParticlesData* __fastcall ConstructParticlesData(NiParticlesData* data)
{
    ConstructGeometryData(data);
    *(void**)data = (void*)&DAT_010a05e4;
    data->m_pfRadii = 0;
    data->m_usActive = 0;
    data->m_pfSizes = 0;
    data->m_pkRotations = 0;
    data->m_pfRotationAngles = 0;
    data->m_pkRotationAxes = 0;
    data->m_pucTextureIndices = 0;
    data->m_pkSubTextureOffsets = 0;
    data->m_ucSubTextureOffsetCount = 0;
    data->m_bHasRadii = false;
    data->SetDataConsistency(0);
    data->m_bSaveVertexData = false;
    return data;
}

// @fnv 0x00a967e0
void __fastcall SetActiveParticleCount(NiParticlesData* data, void*, unsigned short usActive)
{
    unsigned short active = data->m_usVertices;
    if (usActive <= active)
        data->m_usActive = usActive;
    else
        data->m_usActive = active;
}

// @fnv 0x00c24cc0
void NiPSysData::vf41(unsigned short usParticle)
{
    unsigned short usLastParticle = m_usActive - 1;
    NiParticlesData::vf41(usParticle);
    if (usParticle != usLastParticle)
    {
        m_pkParticleInfo[usParticle] = m_pkParticleInfo[usLastParticle];
        if (m_pfRotationSpeeds)
            m_pfRotationSpeeds[usParticle] = m_pfRotationSpeeds[usLastParticle];
    }
}

extern const char* const g_01202680_arg1;

// @fnv 0x00c24e90
// src: COMMUNITY 0x00c24e90
const char* const* __cdecl NiPSysData_GetRTTI()
{
    return &g_01202680_arg1;
}

extern int DAT_010be254;
void _NiFreeAlias(void*);
void _delete(void*, unsigned int);
// Destruction adapters avoid adding exception cleanup absent from the original
// routines; all object storage comes from the shared declarations.
void __fastcall DestroyParticlesData(NiParticlesData* data);

// @fnv 0x00c25280
void* __fastcall DeleteParticleData(NiPSysData* data, void*, unsigned int flags)
{
    *(void**)data = (void*)&DAT_010be254;
    g_memoryManager.Deallocate(data->m_pkParticleInfo);
    _NiFreeAlias(data->m_pfRotationSpeeds);
    DestroyParticlesData(data);
    if (flags & 1)
        _delete(data, sizeof(NiPSysData));
    return data;
}

// @fnv 0x00c24ef0
void __fastcall DestroyParticleData(NiPSysData* data)
{
    *(void**)data = (void*)&DAT_010be254;
    g_memoryManager.Deallocate(data->m_pkParticleInfo);
    _NiFreeAlias(data->m_pfRotationSpeeds);
    DestroyParticlesData(data);
}

// Reconstruction of FUN_00c24d20.
//
// thiscall member of a NiPSysData-derived class (the game's vtable for the
// class has 44 slots; slot 41 is the particle callback the body calls with
// the running particle index, and slot 43 is this function itself).
//
// Shape of the body:
//   * read the two 16-bit counters: the live particle count at +0x50
//     (m_usActive) and the base index at +0x7a (m_usNumParticles);
//   * if the count has already reached the base, the count is bumped by the
//     number of added particles and the function is done;
//   * otherwise the count is set to base + added, and the callback is run
//     for every particle index from the old count upwards while the count
//     stays above the base - the callback itself adds particles;
//   * if the loop stopped early the count and the base are both set to the
//     current index, otherwise the base is set to the count;
//   * in both cases the "added particles" counter at +0x78 is cleared.

// @fnv 0x00c24d20
// src: XBOX_PDB 0x00c24d20
void NiPSysData::ResolveAddedParticles()
{
    if (m_usActive < m_usNumParticles)
    {
        unsigned short i = m_usActive;
        m_usActive = m_usNumActive + m_usNumParticles;

        while (i < m_usNumParticles)
        {
            if (m_usActive <= m_usNumParticles)
                break;
            vf41(i);
            ++i;
        }

        if (i < m_usNumParticles)
        {
            m_usActive = i;
        }
    }
    else
    {
        m_usActive = m_usNumActive + m_usActive;
    }

    m_usNumActive = 0;
    m_usNumParticles = m_usActive;
}

NiPSysData::NiPSysData() throw()
    : m_pkParticleInfo(0), m_pfRotationSpeeds(0), m_usNumActive(0), m_usNumParticles(0)
{}

// @fnv 0x00c24da0
// src: EXE 0x00c24da0
NiPSysData* __cdecl NiPSysData_CreateObject()
{
    return new NiPSysData;
}

// @fnv 0x00c24de0
bool NiPSysData::IsEqual(NiObject* object) const
{
    const NiPSysData* other = static_cast<const NiPSysData*>(object);
    if (!NiParticlesData::IsEqual(object))
    {
        return false;
    }
    if (m_pfRotationSpeeds != 0 && other->m_pfRotationSpeeds == 0)
    {
        return false;
    }
    if (m_pfRotationSpeeds == 0 && other->m_pfRotationSpeeds != 0)
    {
        return false;
    }
    unsigned short i = 0;
    while (i < m_usActive)
    {
        if (!m_pkParticleInfo[i].Equals(&other->m_pkParticleInfo[i]))
        {
            return false;
        }
        if (m_pfRotationSpeeds != 0)
        {
            if (m_pfRotationSpeeds[i] != other->m_pfRotationSpeeds[i])
            {
                return false;
            }
        }
        i++;
    }
    if (m_usNumActive != other->m_usNumActive || m_usNumParticles != other->m_usNumParticles)
    {
        return false;
    }
    return true;
}

// Keep the original 32-bit result; the shared GetParticleVertexCount returns 16 bits.
// @fnv 0x00c24ea0
unsigned int __fastcall GetAvailableParticleIndex(NiPSysData* data)
{
    unsigned short count = data->m_usNumActive;
    if (count == 0)
    {
        unsigned short first = data->m_usActive;
        data->m_usNumParticles = first;
        if (first < data->m_usVertices)
        {
            return (unsigned short)(first + data->m_usNumActive++);
        }
    }
    else
    {
        unsigned short base = data->m_usNumParticles;
        if (data->m_usNumParticles + data->m_usNumActive < data->m_usVertices)
        {
            return (unsigned short)(base + data->m_usNumActive++);
        }
    }
    return 0xffff;
}

// @fnv 0x00c25560
void NiPSysData::SaveBinary(NiStream& stream)
{
    NiParticlesData::SaveBinary(stream);
    bool hasRotationSpeeds = m_pfRotationSpeeds != 0;
    NiBinaryStream* output = stream.m_pkOstr;
    unsigned int(__cdecl * writer)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int) =
        output->m_pfnWrite;
    unsigned int count = 1;
    output->m_uiAbsoluteCurrentPos += writer(output, &hasRotationSpeeds, 1, &count, 1);
}

// FUN_00c25850 : initialiser of a small (0x14 byte) engine object.
//
// The original code calls the immediate-base routine with `this` in ecx, then
// clears the two integer members at +8 and +0xc, installs the class vtable
// pointer (the extern data object DAT_010be45c) at +0 and stores 0.0f in the
// float member at +0x10, finally returning the object itself.
//
// The volatile qualifiers only pin the order of the four member stores
// (int +8, vtable, int +0xc, float +0x10); they do not change the semantics.

extern int DAT_010be45c;

struct FUN_00c25850_cls
{
    void* m_pVTable;
    int m_iValue04;
    volatile int m_iValue08;
    volatile int m_iValue0c;
    volatile float m_fValue10;

    void BaseCtor();
    FUN_00c25850_cls* NiPSysUpdateTask_NiPSysUpdateTask();
};

// @fnv 0x00c25850
// src: EXE 0x00c25850
FUN_00c25850_cls* FUN_00c25850_cls::NiPSysUpdateTask_NiPSysUpdateTask()
{
    BaseCtor();
    m_iValue08 = 0;
    m_pVTable = (void*)&DAT_010be45c;
    m_iValue0c = 0;
    m_fValue10 = 0.0f;
    return this;
}

inline void StrArr::AppendInline(char* value)
{
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    SetAt(index, value);
}
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString_00a7d5a0(const char*, void*);
char* __cdecl NiGetViewerString_00a7d490(const char*, unsigned short);
extern const char* const g_01202680_arg1;
extern const char DAT_010be340[];
extern const char DAT_010be32c[];
extern const char DAT_010be318[];
extern const char DAT_010be304[];
// @fnv 0x00c255b0
void NiPSysData::GetViewerStrings(NiViewerStringsArray* viewerStrings)
{
    StrArr* strings = reinterpret_cast<StrArr*>(viewerStrings);
    NiParticlesData::GetViewerStrings(viewerStrings);
    strings->AppendInline(NiViewerStrings_NiGetViewerString_Title(g_01202680_arg1));
    strings->AppendInline(NiGetViewerString_00a7d5a0(DAT_010be340, m_pkParticleInfo));
    strings->AppendInline(NiGetViewerString_00a7d5a0(DAT_010be32c, m_pfRotationSpeeds));
    strings->AppendInline(NiGetViewerString_00a7d490(DAT_010be318, m_usNumActive));
    strings->AppendInline(NiGetViewerString_00a7d490(DAT_010be304, m_usNumParticles));
}

__declspec(noinline) Point3ParameterData::Point3ParameterData() throw()
{
    m_kValue = NiPoint3::ZERO;
    m_fXValue = 0.0f;
    m_fYValue = 0.0f;
    m_fZValue = 0.0f;
    m_usFirstValue = 0;
    m_usSecondValue = 0;
}

extern MemoryManager g_memoryManager;
void* _NiMalloc(unsigned int size) throw();
void _NiFreeAlias(void*) throw();
extern "C" void* __cdecl _fnv_zlib_memcpy(void* dst, const void* src, unsigned int size) throw();

__forceinline void* operator new[](size_t size) throw()
{
    return g_memoryManager.Allocate(size);
}

// Preserve the nonthrowing array construction used by this unit.
struct ParticleColor : NiColorA
{
    ParticleColor() throw()
    {}
    static void* operator new[](size_t size) throw()
    {
        return g_memoryManager.Allocate(size);
    }
};

struct ParticlePoint : NiPoint3
{
    ParticlePoint() throw()
    {}
};
inline NiQuaternion::NiQuaternion()
{}

struct ParticleRotation : NiQuaternion
{
    ParticleRotation() throw()
    {}
};

// Extra replacement helpers absent from the shared headers; no additional storage.
struct ParticleDataOperations : NiPSysData
{
    void Replace(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal, NiColorA* pkColor, void* pkTexture,
                 unsigned short usNumTextureSets, void* pkNormalBuffer) throw();
    void ReplaceSizes(float* pfSizes) throw();
    void ReplaceRadii(float* pfRadii) throw();
    void ReplaceRotationAngles(float* pfRotationAngles) throw();
    void ReplaceRotationAxes(NiPoint3* pkRotationAxes) throw();
    void ReplaceTextureIndices(unsigned char* pucTextureIndices) throw();
    void ReplaceSubTextureOffsets(NiColorA* pkOffsets, unsigned char ucCount) throw();

    void ReplaceParticleInfo(Point3ParameterData* pkInfo) throw()
    {
        g_memoryManager.Deallocate(m_pkParticleInfo);
        m_pkParticleInfo = pkInfo;
    }
    void ReplaceParticleRotationSpeeds(float* pfSpeeds) throw()
    {
        _NiFreeAlias(m_pfRotationSpeeds);
        m_pfRotationSpeeds = pfSpeeds;
    }

};

static inline void SetCenterAndRadius(NiBound& kBound, const NiPoint3& kTargetCenter, float fRadius)
{
    kBound.m_kCenter = kTargetCenter;
    kBound.m_fBoundRadius = fRadius;
}
// @fnv 0x00c24f20
void NiPSysData::CopyMemberData(NiPSysData* destination, CloningProcess& kCloning)
{
    ParticleDataOperations* pkDest = static_cast<ParticleDataOperations*>(destination);
    NiObject::CopyMembersStream(pkDest, (void*)&kCloning);

    NiPoint3* pkVertex = new ParticlePoint[m_usVertices];
    unsigned int uiVertexSize = sizeof(NiPoint3) * m_usVertices;
    _fnv_zlib_memcpy(pkVertex, m_pkVertex, uiVertexSize);

    NiPoint3* pkNormal = 0;
    if (m_pkNormal)
    {
        pkNormal = new ParticlePoint[m_usVertices];
        _fnv_zlib_memcpy(pkNormal, m_pkNormal, uiVertexSize);
    }

    NiColorA* pkColor = 0;
    if (m_pkColor)
    {
        pkColor = new ParticleColor[m_usVertices];
        _fnv_zlib_memcpy(pkColor, m_pkColor, sizeof(NiColorA) * m_usVertices);
    }

    pkDest->Replace(m_usVertices, pkVertex, pkNormal, pkColor, 0, 0, 0);

    NiQuaternion* pkRotations = 0;
    if (m_pkRotations)
    {
        pkRotations = new ParticleRotation[m_usVertices];
        _fnv_zlib_memcpy(pkRotations, m_pkRotations, sizeof(NiQuaternion) * m_usVertices);
    }
    pkDest->SetRotations(pkRotations);

    float* pfSizes = (float*)_NiMalloc(sizeof(float) * m_usVertices);
    unsigned int uiFloatSize = sizeof(float) * m_usVertices;
    _fnv_zlib_memcpy(pfSizes, m_pfSizes, uiFloatSize);
    pkDest->ReplaceSizes(pfSizes);

    float* pfRadii = (float*)_NiMalloc(sizeof(float) * m_usVertices);
    _fnv_zlib_memcpy(pfRadii, m_pfRadii, uiFloatSize);
    pkDest->ReplaceRadii(pfRadii);

    pkDest->m_usActive = m_usActive;

    if (m_pfRotationAngles)
    {
        float* pfRotationAngles = (float*)_NiMalloc(sizeof(float) * m_usVertices);
        _fnv_zlib_memcpy(pfRotationAngles, m_pfRotationAngles, uiFloatSize);
        pkDest->ReplaceRotationAngles(pfRotationAngles);
    }

    if (m_pkRotationAxes)
    {
        NiPoint3* pkRotationAxes = new ParticlePoint[m_usVertices];
        _fnv_zlib_memcpy(pkRotationAxes, m_pkRotationAxes, sizeof(NiPoint3) * m_usVertices);
        pkDest->ReplaceRotationAxes(pkRotationAxes);
    }

    if (m_pucTextureIndices)
    {
        unsigned char* pucTextureIndices = (unsigned char*)_NiMalloc(sizeof(unsigned char) * m_usVertices);
        _fnv_zlib_memcpy(pucTextureIndices, m_pucTextureIndices, sizeof(unsigned char) * m_usVertices);
        pkDest->ReplaceTextureIndices(pucTextureIndices);
    }

    if (m_pkSubTextureOffsets)
    {
        NiColorA* pkSubTextureOffsets = (NiColorA*)_NiMalloc(sizeof(NiColorA) * m_ucSubTextureOffsetCount);
        _fnv_zlib_memcpy(pkSubTextureOffsets, m_pkSubTextureOffsets, sizeof(NiColorA) * m_ucSubTextureOffsetCount);
        pkDest->ReplaceSubTextureOffsets(pkSubTextureOffsets, m_ucSubTextureOffsetCount);
    }

    Point3ParameterData* pkParticleInfo = 0;
    if (m_pkParticleInfo)
    {
        pkParticleInfo = new Point3ParameterData[m_usVertices];
        _fnv_zlib_memcpy(pkParticleInfo, m_pkParticleInfo, sizeof(Point3ParameterData) * m_usVertices);
    }
    pkDest->ReplaceParticleInfo(pkParticleInfo);

    float* pfRotationSpeeds = 0;
    if (m_pfRotationSpeeds)
    {
        pfRotationSpeeds = (float*)_NiMalloc(sizeof(float) * m_usVertices);
        _fnv_zlib_memcpy(pfRotationSpeeds, m_pfRotationSpeeds, sizeof(float) * m_usVertices);
    }
    pkDest->ReplaceParticleRotationSpeeds(pfRotationSpeeds);

    pkDest->m_usNumActive = m_usNumActive;
    pkDest->m_usNumParticles = m_usNumParticles;

    SetCenterAndRadius(pkDest->m_kBound, m_kBound.m_kCenter, m_kBound.m_fBoundRadius);
}

struct S00c25340_Pt3
{
    float x, y, z;
    S00c25340_Pt3()
    {}
    static void* operator new[](unsigned int size, MemoryManager& mm)
    {
        return mm.Allocate(size);
    }
};

struct S00c25340_Info : Point3ParameterData
{
    static void* operator new[](unsigned int size, MemoryManager& mm)
    {
        return mm.Allocate(size);
    }
};

inline void NiBinaryStream::ReadComp(void* destination, unsigned int size, unsigned int elementSize)
{
    m_uiAbsoluteCurrentPos += m_pfnRead(this, destination, size, &elementSize, 1);
}

static inline void ReadParticleStream(NiBinaryStream* input, void* destination, unsigned int size,
                                      unsigned int elementSize)
{
    input->ReadComp(destination, size, elementSize);
}

// @fnv 0x00c25340
void NiPSysData::LoadBinary(NiStream& stream)
{
    NiParticlesData::LoadBinary(stream);
    if (stream.m_uiNifFileVersion < 0x0a030005 && m_pkRotations)
    {
        m_pfRotationAngles = (float*)_NiMalloc(m_usVertices * 4);
        m_pkRotationAxes = (NiPoint3*)new (g_memoryManager) S00c25340_Pt3[m_usVertices];
        for (unsigned short i = 0; i < m_usVertices; ++i)
            m_pkRotations[i].GetAngleAxis(m_pfRotationAngles[i], m_pkRotationAxes[i]);
        SetRotations(0);
    }
    m_pkParticleInfo = (Point3ParameterData*)new (g_memoryManager) S00c25340_Info[m_usVertices];
    if (stream.m_kHeader.m_uiVersion < 0x13)
        for (unsigned short i = 0; i < m_usVertices; ++i)
            m_pkParticleInfo[i].LoadBinary(stream);
    if (stream.m_uiNifFileVersion >= 0x14000002)
    {
        unsigned char res;
        ReadParticleStream(stream.m_pkIstr, &res, 1, 1);
        if (res)
        {
            m_pfRotationSpeeds = (float*)_NiMalloc(m_usVertices * 4);
            if (stream.m_kHeader.m_uiVersion < 0x13)
                ReadParticleStream(stream.m_pkIstr, m_pfRotationSpeeds, m_usVertices * 4, 4);
        }
    }
    else if (m_pfRotationAngles)
    {
        m_pfRotationSpeeds = (float*)_NiMalloc(m_usVertices * 4);
        fnv_zlib_memset(m_pfRotationSpeeds, 0, m_usVertices * 4);
    }
    if (stream.m_kHeader.m_uiVersion < 0x13)
    {
        ReadParticleStream(stream.m_pkIstr, &m_usNumActive, 2, 2);
        ReadParticleStream(stream.m_pkIstr, &m_usNumParticles, 2, 2);
    }
}

extern int DAT_010be254;

// @fnv 0x00c252d0
NiPSysData* __fastcall CloneParticleData(NiPSysData* source, void*, CloningProcess& kCloning)
{
    NiPSysData* pkClone = new NiPSysData;
    source->CopyMemberData(pkClone, kCloning);
    return pkClone;
}
