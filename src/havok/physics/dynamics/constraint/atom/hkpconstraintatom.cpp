
// src/havok/physics/dynamics/constraint/atom/hkpconstraintatom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/atom/hkpconstraintatom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/Transform.h"
#include "../../../../../../include/hkContactPoint.h"
#include "../../../../../../include/hkpModifierConstraintAtom.h"
#include "../../../../../../include/hkVector4q.h"
#include "../../../../../../include/hkSimdRealq.h"
#include <string.h>




__forceinline void hkVector4q::add4(const hkVector4q& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
}

struct FUN_00d21ce0_cls
{
    void* m_base;
    void* m_pBridge;
    void* m_pConstraintData;
    void hkpBridgeConstraintAtom_init(void* data);
};

// @fnv 0x00d21ce0
// src: XBOX_PDB 0x00d21ce0
void FUN_00d21ce0_cls::hkpBridgeConstraintAtom_init(void* data)
{
    m_pConstraintData = data;
    m_pBridge = (void*)0xd21cc0;
}

// Unlike the four-field hkpConstraintInfo, 0x00d21a60 writes this six-field atom-info record (hkpconstraintdata.cpp).
struct GenericConstraintAtomScheme
{
    int maxSizeOfSchema;
    int sizeOfSchemas;
    int numSolverResults;
    int numSolverElemTemps;
    const hkpModifierConstraintAtom* atoms;
    unsigned int sizeOfAllAtoms;
};

// Walks a linked list from self while the node's first ushort is at least 0x17, OR-ing each node's FUN_00d22090(a, b) result and returning it.
// @fnv 0x00d22120
// src: HAVOK_LIB 0x00d22120
int __cdecl hkpModifierConstraintAtom_addAllModifierDataToConstraintInfo(void* pNode, void* a, void* b)
{
    int result = 0;
    if (*(unsigned short*)pNode >= 0x17)
    {
        void* p = pNode;
        do
        {
            result |= ((hkpModifierConstraintAtom*)p)->addModifierDataToConstraintInfo(*(GenericConstraintAtomScheme*)a, *(unsigned char*)b);
            p = *(void**)((char*)p + 0x14);
        } while (*(unsigned short*)p >= 0x17);
    }
    return result;
}

// @fnv 0x00d21d00
// src: COMMUNITY 0x00d21d00
void __stdcall nullsub_31(int, int, int, int, int, int)
{}

struct FUN_00d21de0_cls
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    FUN_00d21de0_cls* __thiscall hkpSimpleContactConstraintAtom_hkpSimpleContactConstraintAtom(int a);
};

// @fnv 0x00d21de0
// src: HAVOK_LIB 0x00d21de0
FUN_00d21de0_cls* FUN_00d21de0_cls::hkpSimpleContactConstraintAtom_hkpSimpleContactConstraintAtom(int a)
{
    if (a != 0)
    {
        unk0A = (unsigned char)((unk09 + unk08 + 5) * 4);
    }
    return this;
}

// TYPE_MODIFIER_IGNORE_CONSTRAINT (0x1b) calls this method at 0x00d22030.
class hkpIgnoreModifierConstraintAtom : public hkpModifierConstraintAtom
{
public:
    int getConstraintInfo_00d22030(GenericConstraintAtomScheme* info);
};
void __cdecl hkpConstraintData_getConstraintInfoUtil(const hkpModifierConstraintAtom* atom, unsigned int count, GenericConstraintAtomScheme* result);

// Walks the atom chain while type >= 23, then subtracts the partial solver temps, results and schema size from info unless the atom type is 22 or 1.
// @fnv 0x00d22030
// src: HAVOK_LIB 0x00d22030
int hkpIgnoreModifierConstraintAtom::getConstraintInfo_00d22030(GenericConstraintAtomScheme* info)
{
    hkpModifierConstraintAtom* atom = this;
    unsigned int count = 0;
    while (atom->m_type >= 23)
    {
        count = atom->m_iChildSize;
        atom = atom->m_pChildAtom;
    }
    if (atom->m_type != 22 && atom->m_type != 1)
    {
        GenericConstraintAtomScheme partialInfo;
        hkpConstraintData_getConstraintInfoUtil(atom, count, &partialInfo);
        info->numSolverElemTemps -= partialInfo.numSolverElemTemps;
        info->numSolverResults -= partialInfo.numSolverResults;
        info->sizeOfSchemas -= partialInfo.sizeOfSchemas;
    }
    return 0;
}
#include "../../../../../../include/hkMatrix3.h"
__forceinline float& hkMatrix3::operator()(int r, int c) { return reinterpret_cast<hkVector4q*>(&m_kColumn0)[c](r); }



namespace constraint_atom_simd {
// Raw SIMD scratch storage avoids the SDK union's /GS buffer classification.
// Exe 0x00d21e00 ScaleInverseInertia: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float lanes[4];
    unsigned __int64 bits[2];
} __m128, LocalM128;

extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" LocalM128 _mm_load_ps(float const* p);

static __forceinline LocalM128& quad(hkVector4q& v)
{
    return reinterpret_cast<LocalM128&>(v.m_vComponents);
}

static __forceinline const LocalM128& quad(const hkVector4q& v)
{
    return reinterpret_cast<const LocalM128&>(v.m_vComponents);
}

struct ScratchMatrix
{
    LocalM128 column0;
    LocalM128 column1;
    LocalM128 column2;
};



struct hkpSimpleConstraintInfoInitInputq
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMatrix3 m_kInverseInertiaMatrix;
    hkVector4q m_vInverseInertiaAndMass;
    const hkMatrix3* m_rotation;
};

class hkpMassChangerModifierConstraintAtomq
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4q m_kFactorA;
    hkVector4q m_kFactorB;

    void ScaleInverseInertia(const void* cp, intptr_t inA, void* velA,
                             hkpSimpleConstraintInfoInitInputq& inB, void* velB);
};

// Scales the inverse inertia matrix and mass of two constraint inputs by m_kFactorA and m_kFactorB, handling isotropic and anisotropic cases.
// @fnv 0x00d21e00
void hkpMassChangerModifierConstraintAtomq::ScaleInverseInertia(const void* cp, intptr_t inA,
                                                                void* velA, hkpSimpleConstraintInfoInitInputq& inB,
                                                                void* velB)
{
    LocalM128 factorStorage;
    memcpy(&factorStorage, &m_kFactorA, sizeof(factorStorage));
    hkVector4q& factor = reinterpret_cast<hkVector4q&>(factorStorage);
    hkpSimpleConstraintInfoInitInputq* in = (hkpSimpleConstraintInfoInitInputq*)*(volatile intptr_t*)&inA;
    for (int i = 0; i < 2; i++)
    {
        in->m_vInverseInertiaAndMass.mul4(factor);
        if (factor(0) == factor(1) && factor(1) == factor(2))
        {
            LocalM128 scaleStorage = quad(factor);
            in->m_kInverseInertiaMatrix.Multiply(reinterpret_cast<const hkSimdReal&>(scaleStorage));
        }
        else
        {
            const hkMatrix3& rot = *in->m_rotation;
            ScratchMatrix localStorage;
            hkMatrix3& local = reinterpret_cast<hkMatrix3&>(localStorage);
            local.SetTransposeProduct((char*)&rot, (char*)&in->m_kInverseInertiaMatrix);
            ScratchMatrix scaledStorage;
            hkMatrix3& scaled = reinterpret_cast<hkMatrix3&>(scaledStorage);
            scaled.SetProduct(local, rot);
            scaled(0, 0) *= factor(0);
            scaled(1, 1) *= factor(1);
            scaled(2, 2) *= factor(2);
            local._setMul(scaled, rot);
            in->m_kInverseInertiaMatrix.SetProduct(rot, local);
        }
        factor = m_kFactorB;
        in = &inB;
    }
}

}  // namespace constraint_atom_simd

// Moving-surface modifier: velocity at 0x20; its callback is bound to 0x00d21f50.
class hkpMovingSurfaceModifierConstraintAtom : public hkpModifierConstraintAtom
{
  public:
    void CopyMemory_00d21f50(const hkContactPoint& kCp, void* pvA, void* pvB, void* pvC, intptr_t kVelOut);

    hkVector4 m_fVelocity;
};

// Subtracts a copy of m_fVelocity scaled by its dot product with the separating normal from that copy, and adds the result to kVelOut.
// @fnv 0x00d21f50
// src: GUESS 0x00d21f50 (confidence: low)
void hkpMovingSurfaceModifierConstraintAtom::CopyMemory_00d21f50(const hkContactPoint& kCp, void* pvA, void* pvB,
                                                              void* pvC, intptr_t kVelOut)
{
    using namespace constraint_atom_simd;
    using constraint_atom_simd::LocalM128;
    hkVector4q kVel;
    memcpy(&kVel, &m_fVelocity, sizeof(kVel));
    const LocalM128 product = _mm_mul_ps(quad(reinterpret_cast<const hkVector4q&>(kCp.m_vSeparatingNormal)), quad(kVel));
    hkVector4q* out = (hkVector4q*)*(volatile intptr_t*)&kVelOut;
    const LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    const LocalM128 dot = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    quad(kVel) = _mm_sub_ps(quad(kVel),
                                   _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), quad(kVel)));
    out->add4(kVel);
}

// @fnv 0x00d22090
// src: HAVOK_LIB 0x00d22090
int hkpModifierConstraintAtom::addModifierDataToConstraintInfo(GenericConstraintAtomScheme& kInfo, unsigned char& ucUsedFlagsOut)
{
    int iCallbackRequest = 0;
    switch (m_type)
    {
    case 0x19:
        ucUsedFlagsOut |= 0x10;
        break;
    case 0x17:
        ucUsedFlagsOut |= 8;
        break;
    case 0x18:
        kInfo.sizeOfSchemas += 0x50;
        ucUsedFlagsOut |= 1;
        break;
    case 0x1a:
        kInfo.sizeOfSchemas += 0x50;
        ucUsedFlagsOut |= 4;
        break;
    case 0x1b:
        iCallbackRequest = static_cast<hkpIgnoreModifierConstraintAtom*>(this)->getConstraintInfo_00d22030(&kInfo);
        break;
    case 0x1c:
        kInfo.sizeOfSchemas += 0xd0;
        ucUsedFlagsOut |= 2;
        break;
    }
    return iCallbackRequest;
}


namespace constraint_atom_simd {

// hkRotation layout (three hkVector4q columns) of the motion transform and inverse inertia; the shared hkRotation uses hkVector4.
struct AtomRotation
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
};

static __forceinline void SetRotatedDirection(hkVector4q& out, const AtomRotation& a, const hkVector4q& b)
{
    const __m128 b0 = _mm_shuffle_ps(quad(b), quad(b), 0x00);
    const __m128 b1 = _mm_shuffle_ps(quad(b), quad(b), 0x55);
    const __m128 b2 = _mm_shuffle_ps(quad(b), quad(b), 0xAA);
    const __m128 r1 = _mm_mul_ps(b1, quad(a.m_kColumn1));
    const __m128 r0 = _mm_mul_ps(b0, quad(a.m_kColumn0));
    const __m128 r2 = _mm_mul_ps(b2, quad(a.m_kColumn2));
    quad(out) = _mm_add_ps(_mm_add_ps(r1, r0), r2);
}

static __forceinline __m128 crossq(const __m128& v1, const __m128& v2)
{
    const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xC9), _mm_shuffle_ps(v2, v2, 0xD2));
    const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xD2), _mm_shuffle_ps(v2, v2, 0xC9));
    return _mm_sub_ps(cross0, cross1);
}
struct InitInput
{
    hkVector4q m_kFirstVector;
    AtomRotation m_kInverseInertiaMatrix;
    hkVector4q m_vInverseInertiaAndMass;
    const Transform* m_kMotionTransform;
};

struct BodyVelocity
{
    hkVector4q m_kTranslationalVelocity;
    hkVector4q m_kAngularVelocity;
};

struct ComChangerAtom
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4q m_kDisplacementA;
    hkVector4q m_kDisplacementB;

    void UpdateFields_00d22160(const void* cp, InitInput& inA, BodyVelocity& velA, InitInput& inB, BodyVelocity& velB);
};

// @fnv 0x00d22160
// src: GUESS 0x00d22160 (confidence: low)
void ComChangerAtom::UpdateFields_00d22160(const void* cp, InitInput& inA, BodyVelocity& velA, InitInput& inB,
                                  BodyVelocity& velB)
{
    hkVector4q vRotatedDisplacementA;
    SetRotatedDirection(vRotatedDisplacementA, *reinterpret_cast<const AtomRotation*>(inA.m_kMotionTransform->r), m_kDisplacementA);
    hkVector4q vRotatedDisplacementB;
    SetRotatedDirection(vRotatedDisplacementB, *reinterpret_cast<const AtomRotation*>(inB.m_kMotionTransform->r), m_kDisplacementB);
    quad(inA.m_kFirstVector) = _mm_sub_ps(quad(inA.m_kFirstVector), quad(vRotatedDisplacementA));
    quad(inB.m_kFirstVector) = _mm_sub_ps(quad(inB.m_kFirstVector), quad(vRotatedDisplacementB));
    __m128 vAngularCorrectionA = crossq(quad(vRotatedDisplacementA), quad(velA.m_kAngularVelocity));
    __m128 vAngularCorrectionB = crossq(quad(vRotatedDisplacementB), quad(velB.m_kAngularVelocity));
    quad(velA.m_kTranslationalVelocity) =
        _mm_sub_ps(quad(velA.m_kTranslationalVelocity), vAngularCorrectionA);
    quad(velB.m_kTranslationalVelocity) =
        _mm_sub_ps(quad(velB.m_kTranslationalVelocity), vAngularCorrectionB);
}

extern __m128 DAT_012689a0;
extern __m128 DAT_012689b0;
extern __m128 DAT_012689c0;
extern __m128 DAT_012689d0;

// Copies two pairs of __m128 values from source1 and source2 into the global DAT_012689a0 through DAT_012689d0.
// @fnv 0x00d21f10
void __stdcall SetGlobalVectors(int, int, const __m128* source1, int, const __m128* source2)
{
    DAT_012689a0 = source1[0];
    DAT_012689b0 = source1[1];
    DAT_012689c0 = source2[0];
    DAT_012689d0 = source2[1];
}

struct Cls_00d21fc0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4q m_uiValueCount;
    void __thiscall CopyData_00d21fc0(__m128* a, int b, int c, int d, int e, int out);
};
// Computes d = dot3(quad(a.m_kColumn1), m_uiValueCount), then subtracts (m_uiValueCount - d * m_uiValueCount) from the vector at out.
// @fnv 0x00d21fc0
// src: GUESS 0x00d21fc0 (confidence: medium)
void __thiscall Cls_00d21fc0::CopyData_00d21fc0(__m128* a, int b, int c, int d, int e, int out)
{
    hkVector4q n;
    memcpy(&n, &m_uiValueCount, sizeof(n));
    __m128 nv = _mm_load_ps(&n(0));
    __m128 p = _mm_mul_ps(a[1], nv);
    int iOut = *(volatile int*)&out;
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    __m128 r = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    __m128 t = _mm_sub_ps(nv, _mm_mul_ps(_mm_shuffle_ps(r, r, 0), nv));
    __m128* pOut = (__m128*)iOut;
    *pOut = _mm_sub_ps(*pOut, t);
}

}  // namespace constraint_atom_simd
