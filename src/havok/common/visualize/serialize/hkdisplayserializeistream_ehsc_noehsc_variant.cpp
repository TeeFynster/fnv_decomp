// Keep the original intrinsic declaration: the CRT's extra byte-array aliases
// cause this /GS unit to acquire a stack cookie absent from the game function.
// Exe 0x00ddada0 FUN_00ddada0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_set_ps1(float a);
#define _INCLUDED_MM2

#include "../../../../../include/BSAudio.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkGeometry.h"
#include "../../../../../include/hkDisplayGeometry.h"
#include "../../../../../include/hkDisplayConvex.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkSphere.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkDisplayCapsule.h"
#include "../../../../../include/hkDisplaySemiCircle.h"
#include "../../../../../include/hkDisplaySerializeIStream.h"
#undef _INCLUDED_MM2

// src/havok/common/visualize/serialize/hkdisplayserializeistream_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/visualize/serialize/hkdisplayserializeistream.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/visualize/serialize/hkdisplayserializeistream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/serialize/hkdisplayserializeistream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
typedef float hkReal;
typedef signed char hkInt8;

BSAudio* __cdecl hkMemoryRouter_getInstance();

// Shared hkMemoryRouter.h is not available; this unit uses its heap pointer at +0x10.
#include "../../../../../include/hkMemoryRouter.h"

__forceinline hkMemoryRouter* getRouter()
{
    return reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
}

__forceinline void* hkGeometry::operator new(size_t nbytes) throw()
{
    return getRouter()->heap().blockAlloc(nbytes);
}

__forceinline void* hkDisplayGeometry::operator new(std::size_t nbytes)
{
    void* b = getRouter()->heap().blockAlloc(nbytes);
    static_cast<hkDisplayGeometry*>(b)->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
    return b;
}

// Havok's default transform constructor leaves its components uninitialized.
__forceinline hkTransform::hkTransform() {}

__forceinline void hkVector4::SetAllComponents(float r)
{
    m_vComponents = _mm_set_ps1(r);
}

// Shared hkDisplaySphere.h is not available; retain the real class declaration here.
struct hkDisplaySphere : hkDisplayGeometry
{
    hkSphere m_pSphere;
    int m_iXResolution;
    int m_iYResolution;
    int unk68;
    int unk6C;
    int unk70;
    hkDisplaySphere(const hkSphere& sphere, int xRes, int yRes);
};

// Shared hkDisplayBox.h is not available; retain the real class declaration here.
struct hkDisplayBox : hkDisplayGeometry
{
    hkVector4 m_vHalfExtents;
    int unk60;
    hkDisplayBox(const hkVector4& halfExtents);
};

// Shared hkDisplayAABB.h is not available; retain the real class declaration here.
struct hkDisplayAABB : hkDisplayGeometry
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
    int unk70;
    hkDisplayAABB(const hkVector4& min, const hkVector4& max);
};

// Shared hkDisplayCone.h is not available; retain the real class declaration here.
struct hkDisplayCone : hkDisplayGeometry
{
    hkVector4 m_kStartPosition;
    hkVector4 m_kAxisEndPoints;
    hkReal m_fConeAngle;
    hkReal m_height;
    int m_iNumSegments;
    int unk7C;
    int unk80;
    hkDisplayCone(hkReal coneAngle, hkReal coneHeight, int numSegments, const hkVector4& coneAxis,
                   const hkVector4& startPos);
};

// Shared hkDisplayPlane.h is not available; retain the real class declaration here.
struct hkDisplayPlane : hkDisplayGeometry
{
    hkVector4 m_vHitNormal;
    hkVector4 m_kPerpendicularToNormal;
    hkVector4 m_kCenterPosition;
    hkVector4 m_fExtents;
    int unk90;
    hkDisplayPlane(const hkVector4& normal, const hkVector4& perpToNormal, const hkVector4& center,
                    const hkVector4& extent);
};

// Shared hkDisplayCapsule.h lacks the constructor and capsule data members used here.

// Shared hkDisplayCylinder.h is not available; retain the real class declaration here.
struct hkDisplayCylinder : hkDisplayGeometry
{
    hkVector4 m_fMinimumV;
    hkVector4 m_fMaximumV;
    hkReal m_fSphereRadius;
    int m_iNumSides;
    int m_iNumHeightSegments;
    int unk7C;
    int unk80;
    hkDisplayCylinder(const hkVector4& top, const hkVector4& bottom, hkReal radius, int numSides,
                       int numHeightSegments);
};

__forceinline hkInt8 hkDisplaySerializeIStream::readInt8()
{
    hkInt8 c;
    hkIArchive_readArrayGeneric(&c, 1, 1);
    return c;
}

__forceinline int hkDisplaySerializeIStream::readInt32()
{
    int i;
    hkIArchive_readArrayGeneric(&i, 4, 1);
    return i;
}

__forceinline hkReal hkDisplaySerializeIStream::readFloat32()
{
    hkReal f;
    hkIArchive_readArrayGeneric(&f, 4, 1);
    return f;
}

__forceinline void hkDisplaySerializeIStream::ReadVector4(hkVector4& v)
{
    readQuadVector4(v);
}

__forceinline void hkDisplaySerializeIStream::ReadTransform(hkTransform& t)
{
    ReadTranslationAndRotation(t);
}

__forceinline void hkDisplaySerializeIStream::ReadGeometry(hkGeometry* g)
{
    readGeometry(g);
}

// @fnv 0x00ddada0
// src: GUESS 0x00ddada0 (confidence: low)
void hkDisplaySerializeIStream::UpdateFields_00ddada0(hkDisplayGeometry*& geometry)
{
    hkInt8 type = readInt8();

    switch (type)
    {
    case 6: {
        hkTransform transform;
        ReadTransform(transform);
        hkGeometry* geom = new hkGeometry;
        ReadGeometry(geom);
        geometry = new hkDisplayConvex(geom);
        geometry->m_kMotionTransform = transform;
        break;
    }
    case 1: {
        hkTransform transform;
        ReadTransform(transform);
        hkReal radius = readFloat32();
        hkVector4 position;
        ReadVector4(position);
        hkSphere sphere;
        sphere.m_pos.m_vComponents = position.m_vComponents;
        sphere.m_pos.m_vComponents.m128_f32[3] = radius;
        int xRes = readInt32();
        int yRes = readInt32();
        geometry = new hkDisplaySphere(sphere, xRes, yRes);
        geometry->m_kMotionTransform = transform;
        break;
    }
    case 8: {
        hkTransform transform;
        ReadTransform(transform);
        hkReal radius = readFloat32();
        hkVector4 top;
        ReadVector4(top);
        hkVector4 bottom;
        ReadVector4(bottom);
        int numSides = readInt32();
        int numHeightSegments = readInt32();
        geometry = new hkDisplayCapsule(top, bottom, radius, numSides, numHeightSegments);
        geometry->m_kMotionTransform = transform;
        break;
    }
    case 9: {
        hkTransform transform;
        ReadTransform(transform);
        hkReal radius = readFloat32();
        hkVector4 top;
        ReadVector4(top);
        hkVector4 bottom;
        ReadVector4(bottom);
        int numSides = readInt32();
        int numHeightSegments = readInt32();
        geometry = new hkDisplayCylinder(top, bottom, radius, numSides, numHeightSegments);
        geometry->m_kMotionTransform = transform;
        break;
    }
    case 2: {
        hkTransform transform;
        ReadTransform(transform);
        hkVector4 halfExtents;
        ReadVector4(halfExtents);
        geometry = new hkDisplayBox(halfExtents);
        geometry->m_kMotionTransform = transform;
        break;
    }
    case 3: {
        hkVector4 minExtent;
        ReadVector4(minExtent);
        hkVector4 maxExtent;
        ReadVector4(maxExtent);
        geometry = new hkDisplayAABB(minExtent, maxExtent);
        break;
    }
    case 4: {
        hkVector4 startPos;
        ReadVector4(startPos);
        hkVector4 axis;
        ReadVector4(axis);
        hkReal angle = readFloat32();
        hkReal height = readFloat32();
        int numSegments = readInt32();
        geometry = new hkDisplayCone(angle, height, numSegments, axis, startPos);
        break;
    }
    case 5: {
        hkVector4 center;
        ReadVector4(center);
        hkVector4 normal;
        ReadVector4(normal);
        hkVector4 perp;
        ReadVector4(perp);
        hkReal radius = readFloat32();
        hkReal thetaMin = readFloat32();
        hkReal thetaMax = readFloat32();
        int numSegments = readInt32();
        geometry = new hkDisplaySemiCircle(center, normal, perp, thetaMin, thetaMax, radius, numSegments);
        break;
    }
    case 7: {
        hkVector4 center;
        ReadVector4(center);
        hkVector4 normal;
        ReadVector4(normal);
        hkVector4 perpToNormal;
        ReadVector4(perpToNormal);
        hkReal e = readFloat32();
        hkVector4 extent;
        extent.SetAllComponents(e);
        geometry = new hkDisplayPlane(normal, perpToNormal, center, extent);
        break;
    }
    default:
        break;
    }
}
