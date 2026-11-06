// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIQUATERNION_H
#define FNV_NIQUATERNION_H

#include "layout_support.h"
class NiQuaternion;
class NiMatrix3_Xbox360;
#pragma pack(push, 4)
class NiQuaternion
{
  public:
    float m_fVectorX;     // +0x0, 4 bytes
    float m_fVectorY;     // +0x4, 4 bytes
    float m_fVectorZ;     // +0x8, 4 bytes
    float m_fScalarPart;  // +0xC, 4 bytes
    void EnsureCanonicalSign();
    void ToRotationMatrix(NiMatrix3_Xbox360&);
    // NiQuaternion
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // float __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*()
    // void __cdecl NiQuaternion::*(float, float, float, float)
    // void __cdecl NiQuaternion::*(float&, float&, float&, float&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // operator-
    // operator*
    // operator*=
    // bool __cdecl NiQuaternion::*(const NiQuaternion&)
    // bool __cdecl NiQuaternion::*(const NiQuaternion&)
    // float __cdecl NiQuaternion::*(const NiQuaternion&, const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // void __cdecl NiQuaternion::*(float, const NiQuaternion&, const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&, const NiQuaternion&, const NiQuaternion&)
    // void __cdecl NiQuaternion::*(float, const NiQuaternion&, const NiQuaternion&, const NiQuaternion&, const NiQuaternion&)
    // void __cdecl NiQuaternion::*(float&, NiPoint3&)
    // void __cdecl NiQuaternion::*(float, const NiPoint3&)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float, float, float)
    // void __cdecl NiQuaternion::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl NiQuaternion::*(const char*)
    // void __cdecl NiQuaternion::*()
    // void __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*(float)
    // float __cdecl NiQuaternion::*(float, float, float)
    // float __cdecl NiQuaternion::*(float, float)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiQuaternion) == 16);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorX) == 0);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorY) == 4);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorZ) == 8);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fScalarPart) == 12);
#endif
