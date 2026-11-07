#include "../../../../../../../include/hkArray.h"
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkSphere.h"
#include "../../../../../../../include/hkOstream.h"
#include "../../../../../../../include/hkError.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpShapeCollection.h"
#include "../../../../../../../include/hkpShapeContainer.h"

// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

#include <xmmintrin.h>
extern float DAT_0104e148;

union __declspec(align(16)) ShapeBuffer338
{
    __m128 alignment;
    char bytes[512];
};

struct FNV_Owner
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    hkpShapeCollection* p20;
    int* p24;
    int n28;
    void ProcessEntries_00e608d0(hkVector4* pA, hkVector4* pOut);
};

// @fnv 0x00e608d0
// src: GUESS 0x00e608d0 (confidence: low)
void FNV_Owner::ProcessEntries_00e608d0(hkVector4* pA, hkVector4* pOut)
{
    ShapeBuffer338 big;
    hkVector4 buf;
    float dot;
    float best = DAT_0104e148;
    int idx = 0;
    for (int i = 0; i < n28; i++)
    {
        const hkpConvexShape* r = static_cast<const hkpConvexShape*>(
            p20->GetShapeForKey(p24[i], reinterpret_cast<hkpShapeBuffer&>(big)));
        r->GetSupportVertex(*pA, reinterpret_cast<Vector4WithInt24W&>(buf));
        __m128 prod = _mm_mul_ps(*(const __m128*)pA, *(const __m128*)&buf);
        __m128 s1 = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
        float d;
        _mm_store_ss(&d, _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), s1));
        if (d > best)
        {
            best = d;
            int t = buf.m_vComponents.m128_i32[3] & 0xc0ffffff;
            idx = t / 16 + i * 3;
            *(__m128*)pOut = *(const __m128*)&buf;
        }
    }
    pOut->m_vComponents.m128_i32[3] = idx | 0x3f000000;
}

extern "C" void __debugbreak();
extern const unsigned int DAT_01017d10[4];
void __cdecl ResizeAudioStream(void* alloc, void* array, int elemSize);

inline void* operator new(unsigned int, void* p)
{
    return p;
}


inline void hkVector4::operator=(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}

inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
}

inline void hkVector4::sub4(const hkVector4& v)
{
    m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
}

inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}

inline void hkVector4::setAbs4(const hkVector4& v)
{
    m_vComponents = _mm_and_ps(v.m_vComponents, *(const __m128*)&DAT_01017d10);
}

inline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
}

inline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x)
{}

inline hkSimdReal::operator float() const
{
    float fLane;
    _mm_store_ss(&fLane, m_vValue);
    return fLane;
}

inline hkSimdReal hkVector4::dot3(const hkVector4& kRhs) const
{
    __m128 vProd = _mm_mul_ps(m_vComponents, kRhs.m_vComponents);
    __m128 vSum01 = _mm_add_ss(_mm_shuffle_ps(vProd, vProd, _MM_SHUFFLE(1, 1, 1, 1)), vProd);
    return _mm_add_ss(_mm_shuffle_ps(vProd, vProd, _MM_SHUFFLE(2, 2, 2, 2)), vSum01);
}

inline hkSimdReal hkVector4::lengthSquared3() const
{
    return this->dot3(*this);
}

inline float& hkVector4::operator()(int a)
{
    return reinterpret_cast<float*>(&m_vComponents)[a];
}

inline const float& hkVector4::operator()(int a) const
{
    return reinterpret_cast<const float*>(&m_vComponents)[a];
}

// The shared sphere exposes its storage; retain the query accessors in this unit.
inline const hkVector4& getSpherePosition(const hkSphere& sphere)
{
    return reinterpret_cast<const hkVector4&>(sphere.m_pos);
}

inline float getSphereRadius(const hkSphere& sphere)
{
    return getSpherePosition(sphere)(3);
}

inline hkAabb::hkAabb()
{}

class S5fb50_PrimitiveInfo
{
  public:
    unsigned int ID;
};

static __forceinline S5fb50_PrimitiveInfo& S5fb50_Array__expandOne(hkArrayBase<S5fb50_PrimitiveInfo>& self, hkMemoryRouter* router);

static __forceinline S5fb50_PrimitiveInfo& S5fb50_Array_AllocatePair(hkArrayBase<S5fb50_PrimitiveInfo>& self);

static __forceinline S5fb50_PrimitiveInfo& S5fb50_Array__expandOne(hkArrayBase<S5fb50_PrimitiveInfo>& self, hkMemoryRouter* router)
{
        if (self.m_iElementCount == self.getCapacity())
        {
            ResizeAudioStream(router->m_heap, (&self), sizeof(S5fb50_PrimitiveInfo));
        }
        for (int i = 0; i < 1; i++)
            ::new (self.m_data + self.m_iElementCount + i) S5fb50_PrimitiveInfo;
        return self.m_data[self.m_iElementCount++];
    }

static __forceinline S5fb50_PrimitiveInfo& S5fb50_Array_AllocatePair(hkArrayBase<S5fb50_PrimitiveInfo>& self)
{
        return S5fb50_Array__expandOne(self, hkMemoryRouter_getInstance());
    }

struct S5fb50_Query
{
    unsigned int m_uiPropertyCount;
    unsigned int m_kProperties[1];
    int m_offset[3];
    int m_iIndex;
};

class S5fb50_MoppVm
{
  public:
    hkArrayBase<S5fb50_PrimitiveInfo>* m_pPrimitiveInfoArray;
    int unk04;
    int unk08;
    int unk0c;
    static inline int read24(const unsigned char* PC)
    {
        int v = (PC[0] << 16) + (PC[1] << 8) + PC[2];
        return v;
    }
    inline void AddHit(unsigned int key, const unsigned int properties[1])
    {
        S5fb50_Array_AllocatePair((*(m_pPrimitiveInfoArray))).ID = key;
    }
};

class S5fb50_SphereQueryObject : public S5fb50_MoppVm
{
  public:
    hkSphere m_pSphere;
    void hkpMoppFindAllVirtualMachine_queryOnTreeLeft(const S5fb50_Query* query, const unsigned char* PC);
    void hkpMoppFindAllVirtualMachine_queryOnTreeRight(const S5fb50_Query* query, const unsigned char* PC);
    __forceinline int checkCollision(const hkAabb& aabb, const S5fb50_Query* query, const unsigned char* PC)
    {
        hkVector4 center;
        center.setAdd4(aabb.m_kMinimumCorner, aabb.m_kMaximumCorner);
        hkVector4 extent;
        extent.setSub4(aabb.m_kMaximumCorner, aabb.m_kMinimumCorner);
        center.sub4(getSpherePosition(m_pSphere));
        center.setAbs4(center);
        hkVector4 nearest;
        nearest.setMin4(center, extent);
        hkVector4 diff;
        diff.setSub4(nearest, center);
        float distance = diff.lengthSquared3();
        float radius2 = getSphereRadius(m_pSphere) * getSphereRadius(m_pSphere);
        if (distance > radius2)
        {
            return 0;
        }
        hkVector4 farthest;
        farthest.setAdd4(center, extent);
        if (farthest.lengthSquared3() < radius2)
        {
            hkpMoppFindAllVirtualMachine_queryOnTreeLeft(query, PC);
            hkpMoppFindAllVirtualMachine_queryOnTreeRight(query, PC);
            return 1;
        }
        return 2;
    }
};

class S5fb50_FloatAabbVm : public S5fb50_MoppVm
{
  public:
    struct TempAabb : public hkAabb
    {
        TempAabb()
        {}
    };
    float m_vRayDirectionVector;
    int unk14;
    int unk18;
    int unk1c;
    S5fb50_SphereQueryObject m_kSphereQueryObject;

    void ProcessEntries_00e5fb50(const S5fb50_Query* query, const unsigned char* PC, TempAabb& aabb);
};

// @fnv 0x00e5fb50
// src: GUESS 0x00e5fb50 (confidence: low)
void S5fb50_FloatAabbVm::ProcessEntries_00e5fb50(const S5fb50_Query* query, const unsigned char* PC, TempAabb& aabb)
{
    S5fb50_Query localQuery;
    while (1)
    {
        int command = PC[0];
        TempAabb tempAabb;
        int offsetR;
        int offsetL;
        switch (command)
        {
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c: {
            offsetR = PC[3];
            PC += 4;
            tempAabb.m_kMinimumCorner = aabb.m_kMinimumCorner;
            tempAabb.m_kMaximumCorner = aabb.m_kMaximumCorner;
            ProcessEntries_00e5fb50(query, PC, tempAabb);
            PC += offsetR;
            continue;
        }
        case 0x10:
        case 0x11:
        case 0x12: {
            const int dim = command - 0x10;
            tempAabb.m_kMinimumCorner = aabb.m_kMinimumCorner;
            tempAabb.m_kMaximumCorner = aabb.m_kMaximumCorner;
            offsetR = PC[1];
            offsetL = PC[2];
            aabb.m_kMaximumCorner(dim) =
                float((offsetR << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
            tempAabb.m_kMinimumCorner(dim) =
                float((offsetL << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
            offsetL = 0;
            offsetR = PC[3];
            PC += 4;
            goto do_compare;
        }
        case 0x20:
        case 0x21:
        case 0x22: {
            const int dim = command - 0x20;
            tempAabb.m_kMinimumCorner = aabb.m_kMinimumCorner;
            tempAabb.m_kMaximumCorner = aabb.m_kMaximumCorner;
            offsetL = PC[1];
            offsetR = offsetL + 1;
            offsetL <<= query->m_iIndex;
            offsetR <<= query->m_iIndex;
            offsetL += query->m_offset[dim];
            offsetR += query->m_offset[dim];
            tempAabb.m_kMinimumCorner(dim) = float(offsetL) * m_vRayDirectionVector;
            aabb.m_kMaximumCorner(dim) = float(offsetR) * m_vRayDirectionVector;
            offsetL = 0;
            offsetR = PC[2];
            PC += 3;
            goto do_compare;
        }
        case 0x23:
        case 0x24:
        case 0x25: {
            const int dim = command - 0x23;
            tempAabb.m_kMinimumCorner = aabb.m_kMinimumCorner;
            tempAabb.m_kMaximumCorner = aabb.m_kMaximumCorner;
            offsetR = PC[1];
            offsetL = PC[2];
            aabb.m_kMaximumCorner(dim) =
                float((offsetR << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
            tempAabb.m_kMinimumCorner(dim) =
                float((offsetL << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
            offsetL = (PC[3] << 8) + PC[4];
            offsetR = (PC[5] << 8) + PC[6];
            PC += 7;
        }
        do_compare: {
            while (1)
            {
                const int command2 = PC[offsetL];
                if (command2 < 0x26 || command2 > 0x2b)
                {
                    break;
                }
                if (command2 >= 0x29)
                {
                    const int dim = command2 - 0x29;
                    aabb.m_kMinimumCorner(dim) = float(read24(PC + offsetL + 1)) * m_vRayDirectionVector;
                    aabb.m_kMaximumCorner(dim) = float(read24(PC + offsetL + 4)) * m_vRayDirectionVector;
                    offsetL += 7;
                }
                else
                {
                    const int dim = command2 - 0x26;
                    aabb.m_kMinimumCorner(dim) =
                        float(((PC + offsetL)[1] << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
                    aabb.m_kMaximumCorner(dim) =
                        float(((PC + offsetL)[2] << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
                    offsetL += 3;
                }
            }
            while (1)
            {
                const int command2 = PC[offsetR];
                if (command2 < 0x26 || command2 > 0x2b)
                {
                    break;
                }
                if (command2 >= 0x29)
                {
                    const int dim = command2 - 0x29;
                    tempAabb.m_kMinimumCorner(dim) = float(read24(PC + offsetR + 1)) * m_vRayDirectionVector;
                    tempAabb.m_kMaximumCorner(dim) = float(read24(PC + offsetR + 4)) * m_vRayDirectionVector;
                    offsetR += 7;
                }
                else
                {
                    const int dim = command2 - 0x26;
                    tempAabb.m_kMinimumCorner(dim) =
                        float(((PC + offsetR)[1] << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
                    tempAabb.m_kMaximumCorner(dim) =
                        float(((PC + offsetR)[2] << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
                    offsetR += 3;
                }
            }
            const int hitR = m_kSphereQueryObject.checkCollision(tempAabb, query, PC + offsetR);
            const int hitL = m_kSphereQueryObject.checkCollision(aabb, query, PC + offsetL);
            if (hitR != 2)
            {
                if (hitL != 2)
                {
                    return;
                }
                PC += offsetL;
                continue;
            }
            if (hitL != 2)
            {
                aabb.m_kMinimumCorner = tempAabb.m_kMinimumCorner;
                aabb.m_kMaximumCorner = tempAabb.m_kMaximumCorner;
                PC += offsetR;
                continue;
            }
            ProcessEntries_00e5fb50(query, PC + offsetR, tempAabb);
            PC += offsetL;
            continue;
        }
        case 0x29:
        case 0x2a:
        case 0x2b: {
            const int dim = command - 0x29;
            aabb.m_kMinimumCorner(dim) = float(read24(PC + 1)) * m_vRayDirectionVector;
            aabb.m_kMaximumCorner(dim) = float(read24(PC + 4)) * m_vRayDirectionVector;
            PC += 7;
            goto doCut;
        }
        case 0x26:
        case 0x27:
        case 0x28: {
            const int dim = command - 0x26;
            aabb.m_kMinimumCorner(dim) =
                float((PC[1] << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
            aabb.m_kMaximumCorner(dim) =
                float((PC[2] << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
            PC += 3;
        }
        doCut: {
            if (PC[0] >= 0x26 && PC[0] <= 0x2b)
            {
                continue;
            }
            const int hit = m_kSphereQueryObject.checkCollision(aabb, query, PC);
            if (hit == 2)
            {
                continue;
            }
            return;
        }
        case 5: {
            offsetL = PC[1];
            PC += 2;
            PC += offsetL;
            continue;
        }
        case 6: {
            offsetR = PC[1];
            offsetL = PC[2];
            PC += 3;
            PC += (offsetR << 8) + offsetL;
            continue;
        }
        case 7: {
            offsetR = PC[1];
            const int mid = PC[2];
            offsetL = PC[3];
            PC += 4;
            PC += (offsetR << 16) + (mid << 8) + offsetL;
            continue;
        }
        case 1:
        case 2:
        case 3:
        case 4: {
            const int shift = command;
            localQuery.m_offset[0] = (PC[1] << query->m_iIndex) + query->m_offset[0];
            localQuery.m_offset[1] = (PC[2] << query->m_iIndex) + query->m_offset[1];
            localQuery.m_offset[2] = (PC[3] << query->m_iIndex) + query->m_offset[2];
            localQuery.m_iIndex = query->m_iIndex - shift;
            for (int i = 0; i < 1; i++)
            {
                localQuery.m_kProperties[i] = query->m_kProperties[i];
            }
            localQuery.m_uiPropertyCount = query->m_uiPropertyCount;
            query = &localQuery;
            PC += 4;
            continue;
        }
        case 9: {
            const unsigned int offset = PC[1];
            if (query != &localQuery)
            {
                localQuery = *query;
                query = &localQuery;
            }
            localQuery.m_uiPropertyCount += offset;
            PC += 2;
            continue;
        }
        case 10: {
            const unsigned int offset = (PC[1] << 8) + PC[2];
            if (query != &localQuery)
            {
                localQuery = *query;
                query = &localQuery;
            }
            localQuery.m_uiPropertyCount += offset;
            PC += 3;
            continue;
        }
        case 11: {
            const unsigned int offset = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            if (query != &localQuery)
            {
                localQuery = *query;
                query = &localQuery;
            }
            localQuery.m_uiPropertyCount = offset;
            PC += 5;
            continue;
        }
        case 0:
            return;
        case 0x50:
            offsetL = PC[1];
            goto add_Terminal;
        case 0x51:
            offsetR = PC[1];
            offsetR <<= 8;
            offsetL = PC[2];
            offsetL += offsetR;
            goto add_Terminal;
        case 0x52:
            offsetL = PC[1];
            offsetL <<= 16;
            offsetR = PC[2];
            offsetR <<= 8;
            offsetR += PC[3];
            offsetL += offsetR;
            goto add_Terminal;
        case 0x53:
            offsetL = PC[1];
            offsetL <<= 24;
            offsetR = PC[2];
            offsetR <<= 16;
            offsetL += offsetR;
            offsetR = PC[3];
            offsetL += PC[4];
            offsetR <<= 8;
            offsetL += offsetR;
            goto add_Terminal;
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4a:
        case 0x4b:
        case 0x4c:
        case 0x4d:
        case 0x4e:
        case 0x4f:
            offsetL = command - 0x30;
        add_Terminal:
            offsetL += query->m_uiPropertyCount;
            AddHit(offsetL, query->m_kProperties);
            return;
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63: {
            const int property = PC[0] - 0x60;
            const unsigned int value = PC[1];
            PC += 2;
            localQuery.m_kProperties[property] = value;
        }
        propertyCopy: {
            const unsigned int prop = localQuery.m_kProperties[0];
            if (query != &localQuery)
            {
                localQuery = *query;
                query = &localQuery;
            }
            localQuery.m_kProperties[0] = prop;
            continue;
        }
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67: {
            const int property = PC[0] - 0x64;
            const unsigned int value = (PC[1] << 8) + PC[2];
            localQuery.m_kProperties[property] = value;
            PC += 3;
            goto propertyCopy;
        }
        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b: {
            const int property = PC[0] - 0x68;
            const unsigned int value = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            localQuery.m_kProperties[property] = value;
            PC += 5;
            goto propertyCopy;
        }
        default:
            do
            {
                char buf[512];
                // Keep the original explicit stream lifetime without automatic unwinding.
                void* streamStorage[sizeof(hkOstream) / sizeof(void*)];
                hkOstream& ostr = *reinterpret_cast<hkOstream*>(streamStorage);
                ostr.FUN_00cb1600(buf, sizeof(buf));
                ostr.ProcessAndReturnValue_00cc01c0(
                    "Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");
                if (hkError::s_instance->message(
                        3, 0x1298fedd, buf,
                        "d:\\build\\20091222_000100_AiAnBeClDePh\\Source\\Physics/Internal/Collide/Mopp/Machine/hkpMoppUsingFloatAabbVirtualMachine.inl",
                        301))
                {
                    __debugbreak();
                }
                ostr.FUN_00cc00e0();
            } while (0);
            continue;
        }
    }
}
