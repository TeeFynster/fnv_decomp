// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPSYSPLANARCOLLIDER_H
#define FNV_NIPSYSPLANARCOLLIDER_H

#include "layout_support.h"
#include "NiObject.h"
#include "NiPoint3.h"
#include "layout_support.h"
class NiStream;
class NiAVObject;
class CloningProcess;
class NiMatrix3_Xbox360;
class NiPSysCollider;
class NiPSysColliderManager;
class NiPSysPlanarCollider;
class NiPSysSpawnModifier;
class NiPlane;
class NiPoint4;
class NiTransform;
class FourComponentNumericValue;
#pragma pack(push, 4)
class NiPSysCollider : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    float m_fBounceFactor;     // +0x8, 4 bytes
    bool m_bSpawnOnCollision;  // +0xC, 1 bytes
    bool m_bDieOnCollision;    // +0xD, 1 bytes
    unsigned char layoutPaddingE[2];
    NiPSysSpawnModifier* m_pSpawnModifier;         // +0x10, 4 bytes
    NiPoint3 m_kCollisionPosition;                 // +0x14, 12 bytes
    float m_fSpawnRate;                            // +0x20, 4 bytes
    NiPSysColliderManager* m_pColliderManager;     // +0x24, 4 bytes
    NiPointer<NiPSysCollider> m_spNextController;  // +0x28, 4 bytes
    // const NiRTTI* __cdecl NiPSysCollider::*()
    // void __cdecl NiPSysCollider::*(NiPSysCollider*, CloningProcess&)
    // void __cdecl NiPSysCollider::*(NiStream&)
    // void __cdecl NiPSysCollider::*(NiStream&)
    // bool __cdecl NiPSysCollider::*(NiStream&)
    // void __cdecl NiPSysCollider::*(NiStream&)
    // bool __cdecl NiPSysCollider::*(NiObject*)
    // void __cdecl NiPSysCollider::*(NiTPrimitiveArray<char *>*)
    // float __cdecl NiPSysCollider::*()
    // void __cdecl NiPSysCollider::*(float)
    // bool __cdecl NiPSysCollider::*()
    // void __cdecl NiPSysCollider::*(bool)
    // bool __cdecl NiPSysCollider::*()
    // void __cdecl NiPSysCollider::*(bool)
    // NiPSysSpawnModifier* __cdecl NiPSysCollider::*()
    // void __cdecl NiPSysCollider::*(NiPSysSpawnModifier*)
    // NiPSysColliderManager* __cdecl NiPSysCollider::*()
    // NiPSysCollider* __cdecl NiPSysCollider::*()
    // void __cdecl NiPSysCollider::*(NiPSysCollider*)
    // void __cdecl NiPSysCollider::*(NiPSysColliderManager*)
    // void __cdecl NiPSysCollider::*(CloningProcess&)
    // NiPSysCollider
    // void __cdecl NiPSysCollider::*()
    // NiPSysCollider& __cdecl NiPSysCollider::*(const NiPSysCollider&)
    // void __cdecl NiPSysCollider::*()
    void CreateVertexBufferSet(NiPSysCollider*, CloningProcess&);
    // the other slots are the shared NiObject virtuals; Clone is NiObject::MakeClone (0x48)
    virtual void LoadBinary(NiStream&);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysCollider) == 44);
FNV_STATIC_ASSERT(offsetof(NiPSysCollider, m_fBounceFactor) == 8);
FNV_STATIC_ASSERT(offsetof(NiPSysCollider, m_bSpawnOnCollision) == 12);
FNV_STATIC_ASSERT(offsetof(NiPSysCollider, m_bDieOnCollision) == 13);
FNV_STATIC_ASSERT(offsetof(NiPSysCollider, m_pSpawnModifier) == 16);
FNV_STATIC_ASSERT(offsetof(NiPSysCollider, m_kCollisionPosition) == 20);
FNV_STATIC_ASSERT(offsetof(NiPSysCollider, m_fSpawnRate) == 32);
FNV_STATIC_ASSERT(offsetof(NiPSysCollider, m_pColliderManager) == 36);
FNV_STATIC_ASSERT(offsetof(NiPSysCollider, m_spNextController) == 40);
#pragma pack(push, 4)
class NiPlane
{
  public:
    NiPoint3 m_kPlaneNormal;  // +0x0, 12 bytes
    float m_fPlaneConstant;   // +0xC, 4 bytes
    // NiPlane
    // bool __cdecl NiPlane::*(const NiPlane&)
    // bool __cdecl NiPlane::*(const NiPlane&)
    // NiPlane __cdecl NiPlane::*()
    // void __cdecl NiPlane::*(const NiPoint3&)
    // const NiPoint3& __cdecl NiPlane::*()
    // void __cdecl NiPlane::*(float)
    // float __cdecl NiPlane::*()
    // float __cdecl NiPlane::*(const NiPoint3&)
    // int __cdecl NiPlane::*(const NiPoint3&)
    // void __cdecl NiPlane::*(NiStream&)
    // void __cdecl NiPlane::*(NiStream&)
    // char* __cdecl NiPlane::*(const char*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPlane) == 16);
FNV_STATIC_ASSERT(offsetof(NiPlane, m_kPlaneNormal) == 0);
FNV_STATIC_ASSERT(offsetof(NiPlane, m_fPlaneConstant) == 12);
#pragma pack(push, 4)
class FourComponentNumericValue
{
  public:
    union
    {                                     // overlapping CodeView storage
        float m_afComponents[4];          // +0x0, 16 bytes
        unsigned int m_auiComponents[4];  // +0x0, 16 bytes
        struct
        {
            float x;  // +0x0, 4 bytes
            float y;  // +0x4, 4 bytes
            float z;  // +0x8, 4 bytes
            float w;  // +0xC, 4 bytes
        };
        float v[4];         // +0x0, 16 bytes
        unsigned int u[4];  // +0x0, 16 bytes
    };
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FourComponentNumericValue) == 16);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, m_afComponents) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, m_auiComponents) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, x) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, y) == 4);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, z) == 8);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, w) == 12);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, v) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, u) == 0);
#pragma pack(push, 4)
class NiPoint4
{
  public:
    union
    {                                             // overlapping CodeView storage
        FourComponentNumericValue m_kComponents;  // +0x0, 16 bytes
        float m_afExtents[4];                     // +0x0, 16 bytes
    };
    // NiPoint4
    // bool __cdecl NiPoint4::*(const NiPoint4&)
    // void __cdecl NiPoint4::*()
    // Set
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // NiPoint4 __cdecl NiPoint4::*(const NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(const NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(float)
    // NiPoint4 __cdecl NiPoint4::*(NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(NiPoint4*, unsigned int, NiPoint3*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPoint4) == 16);
FNV_STATIC_ASSERT(offsetof(NiPoint4, m_kComponents) == 0);
FNV_STATIC_ASSERT(offsetof(NiPoint4, m_afExtents) == 0);
#pragma pack(push, 4)
// Xbox 360 layout of Gamebryo's NiMatrix3 (Fallout_Release_Beta.pdb: size 0x30, m_pEntry = three NiPoint4 rows) from this
// CodeView dump; the PC game's NiMatrix3 is include/NiMatrix3.h (float[3][3], 36 bytes).
class NiMatrix3_Xbox360
{
  public:
    NiPoint4 m_afEntries[3];  // +0x0, 48 bytes
    // GetRow
    // SetRow
    // GetCol
    // SetCol
    // operator*
    // Inverse
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiMatrix3_Xbox360) == 48);
FNV_STATIC_ASSERT(offsetof(NiMatrix3_Xbox360, m_afEntries) == 0);
#pragma pack(push, 4)
class NiTransform
{
  public:
    NiMatrix3_Xbox360 m_kOrientation;  // +0x0, 48 bytes
    NiPoint3 m_kTranslation;   // +0x30, 12 bytes
    float m_fScale;            // +0x3C, 4 bytes
    // void __cdecl NiTransform::*()
    // bool __cdecl NiTransform::*(const NiTransform&)
    // operator*
    // void __cdecl NiTransform::*(NiTransform&)
    // void __cdecl NiTransform::*(NiTransform&)
    // bool __cdecl NiTransform::*()
    // void __cdecl NiTransform::*(NiStream&)
    // void __cdecl NiTransform::*(NiStream&)
    // void __cdecl NiTransform::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTransform) == 64);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_kOrientation) == 0);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_kTranslation) == 48);
FNV_STATIC_ASSERT(offsetof(NiTransform, m_fScale) == 60);
#pragma pack(push, 4)
class NiPSysPlanarCollider : public NiPSysCollider
{
  public:
    // base NiPSysCollider at +0x0, size 44
    NiAVObject* m_pkColliderObject;  // +0x2C, 4 bytes
    float m_fOriginX;                // +0x30, 4 bytes
    float m_fOriginZ;                // +0x34, 4 bytes
    NiPoint3 m_kFirstVector;         // +0x38, 12 bytes
    NiPoint3 m_kSecondPlaneVector;               // +0x44, 12 bytes
    float m_fWidthSquared;           // +0x50, 4 bytes
    float m_fHeightSquared;          // +0x54, 4 bytes
    NiPlane m_kHalfSpacePlane;       // +0x58, 16 bytes
    NiPoint3 m_kPathOffset;          // +0x68, 12 bytes
    unsigned char layoutPadding74[12];
    NiMatrix3_Xbox360 m_kRotationMatrix;     // +0x80, 48 bytes
    NiTransform m_kFirstTransform;   // +0xB0, 64 bytes
    NiTransform m_kSecondTransform;  // +0xF0, 64 bytes
    virtual void LoadBinary(NiStream&);
    void CopyMemberData(NiPSysPlanarCollider*, CloningProcess&);
    // const NiRTTI* __cdecl NiPSysPlanarCollider::*()
    // NiObject* __cdecl NiPSysPlanarCollider::*(CloningProcess&)
    // void __cdecl NiPSysPlanarCollider::*(NiPSysPlanarCollider*, CloningProcess&)
    // void __cdecl NiPSysPlanarCollider::*(NiStream&)
    // void __cdecl NiPSysPlanarCollider::*(NiStream&)
    // bool __cdecl NiPSysPlanarCollider::*(NiStream&)
    // void __cdecl NiPSysPlanarCollider::*(NiStream&)
    // bool __cdecl NiPSysPlanarCollider::*(NiObject*)
    // NiObject* __cdecl NiPSysPlanarCollider::*()
    // void __cdecl NiPSysPlanarCollider::*(NiTPrimitiveArray<char *>*)
    // NiPSysPlanarCollider
    // NiPSysCollider* __cdecl NiPSysPlanarCollider::*(float, float&, NiPSysData*, unsigned short)
    // void __cdecl NiPSysPlanarCollider::*(float, NiPSysData*, unsigned short)
    // void __cdecl NiPSysPlanarCollider::*()
    // NiAVObject* __cdecl NiPSysPlanarCollider::*()
    // void __cdecl NiPSysPlanarCollider::*(NiAVObject*)
    // float __cdecl NiPSysPlanarCollider::*()
    // void __cdecl NiPSysPlanarCollider::*(float)
    // float __cdecl NiPSysPlanarCollider::*()
    // void __cdecl NiPSysPlanarCollider::*(float)
    // const NiPoint3& __cdecl NiPSysPlanarCollider::*()
    // void __cdecl NiPSysPlanarCollider::*(const NiPoint3&)
    // const NiPoint3& __cdecl NiPSysPlanarCollider::*()
    // void __cdecl NiPSysPlanarCollider::*(const NiPoint3&)
    // void __cdecl NiPSysPlanarCollider::*(CloningProcess&)
    // void __cdecl NiPSysPlanarCollider::*()
    // NiPSysPlanarCollider& __cdecl NiPSysPlanarCollider::*(const NiPSysPlanarCollider&)
    // void __cdecl NiPSysPlanarCollider::*()
    // void __cdecl NiPSysPlanarCollider::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPSysPlanarCollider) == 304);
FNV_STATIC_ASSERT(offsetof(NiPSysPlanarCollider, m_pkColliderObject) == 44);
FNV_STATIC_ASSERT(offsetof(NiPSysPlanarCollider, m_fOriginX) == 48);
FNV_STATIC_ASSERT(offsetof(NiPSysPlanarCollider, m_fOriginZ) == 52);
FNV_STATIC_ASSERT(offsetof(NiPSysPlanarCollider, m_kFirstVector) == 56);
FNV_STATIC_ASSERT(offsetof(NiPSysPlanarCollider, m_kSecondPlaneVector) == 68);
FNV_STATIC_ASSERT(offsetof(NiPSysPlanarCollider, m_fWidthSquared) == 80);
FNV_STATIC_ASSERT(offsetof(NiPSysPlanarCollider, m_fHeightSquared) == 84);
FNV_STATIC_ASSERT(offsetof(NiPSysPlanarCollider, m_kHalfSpacePlane) == 88);
FNV_STATIC_ASSERT(offsetof(NiPSysPlanarCollider, m_kPathOffset) == 104);
FNV_STATIC_ASSERT(offsetof(NiPSysPlanarCollider, m_kRotationMatrix) == 128);
FNV_STATIC_ASSERT(offsetof(NiPSysPlanarCollider, m_kFirstTransform) == 176);
FNV_STATIC_ASSERT(offsetof(NiPSysPlanarCollider, m_kSecondTransform) == 240);
#endif
