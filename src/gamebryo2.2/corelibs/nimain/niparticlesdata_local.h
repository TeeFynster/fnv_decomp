// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPARTICLESDATA_H
#define FNV_NIPARTICLESDATA_H

#include "layout_support.h"
#include "NiObject.h"
#include "NiPoint3.h"
#include "layout_support.h"
class NiAdditionalGeometryData;
class NiBound;
class NiColorA;
class NiGeometryData;
class NiGeometryData__RendererData;
class NiParticlesData;
class NiPoint2;
class NiQuaternion;
#pragma pack(push, 4)
class NiBound
{
  public:
    NiPoint3 m_kCenter;  // +0x0, 12 bytes
    union
    {                          // overlapping CodeView storage
        float m_fBoundRadius;  // +0xC, 4 bytes
        int m_iRadius;         // +0xC, 4 bytes
    };
    // void __cdecl NiBound::*()
    // const NiPoint3& __cdecl NiBound::*()
    // void __cdecl NiBound::*(float)
    // float __cdecl NiBound::*()
    // void __cdecl NiBound::*(const NiPoint3&, float)
    // bool __cdecl NiBound::*(const NiBound&)
    // bool __cdecl NiBound::*(const NiBound&)
    // void __cdecl NiBound::*(int, const NiPoint3*)
    // Update
    // void __cdecl NiBound::*(NiTPrimitiveArray<NiBound const *>&)
    // void __cdecl NiBound::*(const NiBound*)
    // int __cdecl NiBound::*(const NiPlane&)
    // bool __cdecl NiBound::*(float, const NiBound&, const NiPoint3&, const NiBound&, const NiPoint3&)
    // bool __cdecl NiBound::*(float, const NiBound&, const NiPoint3&, const NiBound&, const NiPoint3&, float&, NiPoint3&, bool, NiPoint3&, NiPoint3&)
    // void __cdecl NiBound::*(NiStream&)
    // void __cdecl NiBound::*(NiStream&)
    // char* __cdecl NiBound::*(const char*)
    // const NiBound& __cdecl NiBound::*(const NiBound&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBound) == 16);
FNV_STATIC_ASSERT(offsetof(NiBound, m_kCenter) == 0);
FNV_STATIC_ASSERT(offsetof(NiBound, m_fBoundRadius) == 12);
FNV_STATIC_ASSERT(offsetof(NiBound, m_iRadius) == 12);
#pragma pack(push, 4)
class NiGeometryData : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    unsigned short m_usVertices;                                 // +0x8, 2 bytes
    unsigned short m_usGeometryFlags;                            // +0xA, 2 bytes
    unsigned short m_usTrianglePoints;                           // +0xC, 2 bytes
    unsigned short m_usDirtyFlags;                               // +0xE, 2 bytes
    NiBound m_kBound;                                            // +0x10, 16 bytes
    NiPoint3* m_pkVertex;                                        // +0x20, 4 bytes
    NiPoint3* m_pkNormal;                                        // +0x24, 4 bytes
    NiColorA* m_pkColor;                                        // +0x28, 4 bytes
    NiPoint2* m_pkTexture;                                       // +0x2C, 4 bytes
    NiPointer<NiAdditionalGeometryData> m_spAdditionalGeomData;  // +0x30, 4 bytes
    NiGeometryData__RendererData* m_pkGeometryRendererData;      // +0x34, 4 bytes
    unsigned char m_ucKeepFlags;                                 // +0x38, 1 bytes
    unsigned char m_ucCompressFlags;                             // +0x39, 1 bytes
    bool m_bIsDynamic;                                           // +0x3A, 1 bytes
    bool m_bBoundDirty;                                          // +0x3B, 1 bytes
    bool m_bVerticesDirty;                                       // +0x3C, 1 bytes
    unsigned char layoutPadding3D[3];
    // const NiRTTI* __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(NiStream&)
    // void __cdecl NiGeometryData::*(NiStream&)
    // bool __cdecl NiGeometryData::*(NiStream&)
    // void __cdecl NiGeometryData::*(NiStream&)
    // bool __cdecl NiGeometryData::*(NiObject*)
    // void __cdecl NiGeometryData::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(bool)
    // unsigned short __cdecl NiGeometryData::*()
    // GetVertices
    // void __cdecl NiGeometryData::*(bool)
    // GetNormals
    // NiGeometryData::DataFlags __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(NiGeometryData::DataFlags)
    // GetBound
    // void __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(bool)
    // GetColors
    // void __cdecl NiGeometryData::*(bool, unsigned short)
    // unsigned short __cdecl NiGeometryData::*()
    // GetTextures
    // GetTextureSet
    // void __cdecl NiGeometryData::*(NiPoint2*)
    // void __cdecl NiGeometryData::*(unsigned short, NiPoint3*, NiPoint3*, NiColorA*, NiPoint2*, unsigned short, NiGeometryData::DataFlags)
    // bool __cdecl NiGeometryData::*(bool)
    // void __cdecl NiGeometryData::*()
    // NiGeometryData::Consistency __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(NiGeometryData::Consistency)
    // void __cdecl NiGeometryData::*(unsigned short)
    // unsigned int __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(unsigned int)
    // NiGeometryData::RendererData* __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(NiGeometryData::RendererData*)
    // unsigned int __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(unsigned int)
    // NiAdditionalGeometryData* __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(NiAdditionalGeometryData*)
    // unsigned int __cdecl NiGeometryData::*()
    // NiObjectGroup* __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(NiObjectGroup*)
    // unsigned short __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*()
    // unsigned short __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(unsigned short, NiPoint3*, NiPoint3*, NiColorA*, NiPoint2*, unsigned short, NiGeometryData::DataFlags)
    // void __cdecl NiGeometryData::*(unsigned short, NiPoint3*, NiPoint3*, NiColorA*, NiPoint2*, unsigned short, NiGeometryData::DataFlags)
    // void __cdecl NiGeometryData::*(unsigned short*&, unsigned short*&, unsigned char)
    // int __cdecl NiGeometryData::*(unsigned short, unsigned short, unsigned char)
    // NiGeometryData
    // void __cdecl NiGeometryData::*(unsigned short*, unsigned char, int, int)
    // int __cdecl NiGeometryData::*(unsigned short*, unsigned char, int, int)
    // void __cdecl NiGeometryData::*(unsigned short)
    // void __cdecl NiGeometryData::*(NiGeometryData::DataFlags)
    // NiGeometryData& __cdecl NiGeometryData::*(const NiGeometryData&)
    // void __cdecl NiGeometryData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiGeometryData) == 64);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_usVertices) == 8);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_usGeometryFlags) == 10);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_usTrianglePoints) == 12);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_usDirtyFlags) == 14);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_kBound) == 16);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkVertex) == 32);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkNormal) == 36);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkColor) == 40);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkTexture) == 44);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_spAdditionalGeomData) == 48);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkGeometryRendererData) == 52);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_ucKeepFlags) == 56);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_ucCompressFlags) == 57);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_bIsDynamic) == 58);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_bBoundDirty) == 59);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_bVerticesDirty) == 60);
#pragma pack(push, 4)
class NiParticlesData : public NiGeometryData
{
  public:
    // base NiGeometryData at +0x0, size 64
    bool m_bHasRadii;  // +0x40, 1 bytes
    unsigned char layoutPadding41[3];
    unsigned short* m_pusParticleIndices;  // +0x44, 4 bytes
    float* m_pfSortValues;                 // +0x48, 4 bytes
    float* m_pfRadii;                      // +0x4C, 4 bytes
    unsigned short m_usActive;             // +0x50, 2 bytes
    unsigned char layoutPadding52[2];
    float* m_pfSizes;                         // +0x54, 4 bytes
    NiQuaternion* m_pkRotations;              // +0x58, 4 bytes
    float* m_pfRotationAngles;                // +0x5C, 4 bytes
    NiPoint3* m_pkRotationAxes;               // +0x60, 4 bytes
    unsigned char* m_pucTextureIndices;       // +0x64, 4 bytes
    NiColorA* m_pkSubTextureOffsets;         // +0x68, 4 bytes
    unsigned char m_ucSubTextureOffsetCount;  // +0x6C, 1 bytes
    unsigned char layoutPadding6D[3];
    // Authored declaration for this unit's covered function (layout unchanged).
    void SetRotations(NiQuaternion* pkRotations);
    // const NiRTTI* __cdecl NiParticlesData::*()
    // void __cdecl NiParticlesData::*(NiStream&)
    // void __cdecl NiParticlesData::*(NiStream&)
    // bool __cdecl NiParticlesData::*(NiStream&)
    // void __cdecl NiParticlesData::*(NiStream&)
    // bool __cdecl NiParticlesData::*(NiObject*)
    // NiObject* __cdecl NiParticlesData::*()
    // void __cdecl NiParticlesData::*(NiTPrimitiveArray<char *>*)
    // NiParticlesData
    // void __cdecl NiParticlesData::*()
    // GetRadii
    // GetSizes
    // GetTextureIndices
    // GetSubTextureOffsets
    // GetSubTextureOffsetCount
    // GetRotations
    // GetRotationAngles
    // GetRotationAxes
    // void __cdecl NiParticlesData::*(unsigned short)
    // unsigned short __cdecl NiParticlesData::*()
    // void __cdecl NiParticlesData::*(float*)
    // void __cdecl NiParticlesData::*(float*)
    // void __cdecl NiParticlesData::*(NiQuaternion*)
    // void __cdecl NiParticlesData::*(float*)
    // void __cdecl NiParticlesData::*(NiPoint3*)
    // void __cdecl NiParticlesData::*(unsigned char*)
    // void __cdecl NiParticlesData::*(NiColorA*, unsigned char)
    // void __cdecl NiParticlesData::*(float*)
    // void __cdecl NiParticlesData::*(float*)
    // void __cdecl NiParticlesData::*(NiQuaternion*)
    // void __cdecl NiParticlesData::*(float*)
    // void __cdecl NiParticlesData::*(NiPoint3*)
    // void __cdecl NiParticlesData::*(unsigned char*)
    // void __cdecl NiParticlesData::*(NiColorA*, unsigned char)
    // void __cdecl NiParticlesData::*()
    // NiObject* __cdecl NiParticlesData::*()
    // unsigned short* __cdecl NiParticlesData::*()
    // void __cdecl NiParticlesData::*(const NiCamera*)
    // void __cdecl NiParticlesData::*(int, int)
    // NiParticlesData& __cdecl NiParticlesData::*(const NiParticlesData&)
    // void __cdecl NiParticlesData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiParticlesData) == 112);
FNV_STATIC_ASSERT(offsetof(NiParticlesData, m_bHasRadii) == 64);
FNV_STATIC_ASSERT(offsetof(NiParticlesData, m_pusParticleIndices) == 68);
FNV_STATIC_ASSERT(offsetof(NiParticlesData, m_pfSortValues) == 72);
FNV_STATIC_ASSERT(offsetof(NiParticlesData, m_pfRadii) == 76);
FNV_STATIC_ASSERT(offsetof(NiParticlesData, m_usActive) == 80);
FNV_STATIC_ASSERT(offsetof(NiParticlesData, m_pfSizes) == 84);
FNV_STATIC_ASSERT(offsetof(NiParticlesData, m_pkRotations) == 88);
FNV_STATIC_ASSERT(offsetof(NiParticlesData, m_pfRotationAngles) == 92);
FNV_STATIC_ASSERT(offsetof(NiParticlesData, m_pkRotationAxes) == 96);
FNV_STATIC_ASSERT(offsetof(NiParticlesData, m_pucTextureIndices) == 100);
FNV_STATIC_ASSERT(offsetof(NiParticlesData, m_pkSubTextureOffsets) == 104);
FNV_STATIC_ASSERT(offsetof(NiParticlesData, m_ucSubTextureOffsetCount) == 108);
#endif
