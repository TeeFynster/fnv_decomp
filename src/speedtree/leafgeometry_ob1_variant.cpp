// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3/CVec3; this unit's code depends on the stand-in's own overload set and inline bodies (its own NiPoint3/CVec3 bodies differ), so the shared class cannot replace it.
#include "../../include/NiPoint3.h"
class Allocator;
class Elem16;
struct Mat;
struct Matrix4;
class NiPoint3;

struct LocalVec3
{
public:
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };

    LocalVec3();
    // Keep the implicit copy constructor trivial for by-value calls.
    LocalVec3(float x, float y = 0.0f, float z = 0.0f);
    LocalVec3(const float* data);

    __forceinline LocalVec3& operator=(const LocalVec3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    LocalVec3 operator+(const LocalVec3& other) const;
    LocalVec3 operator-(const LocalVec3& other) const;
    NiPoint3 operator-(const NiPoint3& other) const;
    LocalVec3 operator-() const;
    LocalVec3 operator*(float scale) const;
    LocalVec3 operator*(double scale) const;
    LocalVec3& operator+=(const LocalVec3& other);
    LocalVec3& operator*=(float scale);
    LocalVec3& operator/=(float scale);
    bool operator==(const LocalVec3& other) const;
    bool operator!=(const LocalVec3& other) const;
    float& operator[](int index);
    float& operator[](unsigned int index);

    LocalVec3* Self();
    void Set(float x, float y, float z);
    void AssignOutput(const LocalVec3& other);
    LocalVec3 Neg() const;
    LocalVec3 Add(const LocalVec3& other) const;
    LocalVec3 Added(const LocalVec3& other) const;
    LocalVec3& AddTo(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other) const;
    void Subtract(const LocalVec3& other);
    LocalVec3 Scale(float scale) const;
    LocalVec3 ApplyScaled(float scale);
    LocalVec3 ApplyScaled(float scale) const;
    LocalVec3 ScaleSwizzled(float scale);
    LocalVec3 ScaleSwizzled(float scale) const;
    void ScaleByInverse(float scale);
    void Normalize();
    void Unitize();
    LocalVec3 Cross(const LocalVec3& other) const;
    float Dot(const LocalVec3& other) const;
    float DotProduct(const LocalVec3& other);
    float DotProduct(const LocalVec3& other) const;
    float DotProduct(const LocalVec3* other) const;
    float Length() const;
    float LengthSquared() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;
    Elem16& expand(Allocator& allocator);

    void SetComponents(float x, float y, float z);
    bool FUN_00439090(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other) const;
    bool HasEqualComponents(const char* other);
    void ScaleComponents(float scale);
    LocalVec3 FUN_00439e90(const LocalVec3& other);
    LocalVec3 FUN_00439e90(const LocalVec3& other) const;
    void SubtractIntoVector();
    LocalVec3 SubtractIntoVector(const LocalVec3& other);
    LocalVec3 SubtractIntoVector(const LocalVec3& other) const;
    LocalVec3 SubtractIntoVector(LocalVec3* other);
    LocalVec3 SubtractIntoVector(const LocalVec3* other);
    void SubtractIntoVector(LocalVec3* output, const LocalVec3* other);
    LocalVec3* SubtractIntoVector(void* output, void* other);
    void FUN_0043d410(float x, int y, int z);
    void FUN_0043d410(float x, unsigned int y, unsigned int z);
    float FUN_00457910();
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    float FUN_004a7290();
    float FUN_004a7290() const;
    LocalVec3 FUN_004b3800(const LocalVec3& other) const;
    LocalVec3 ProcessAndReturnValue_0053d280(float divisor);
    float NiPoint3_XYLength();
    float NiPoint3_XYLength() const;
    void ComputeValue_0063c8a0(const LocalVec3* other);
    void ComputeValue_0063c8a0(void* other);
    void FUN_006815c0();
    float CVec3_Distance(LocalVec3* other);
    float CVec3_Distance(const LocalVec3& other) const;
    LocalVec3 TransformPointByMatrix4(const Mat& matrix);
    LocalVec3 TransformPointByMatrix4(const Matrix4* matrix);
    void Normalize_00b12790();
    LocalVec3 Diff_00b13040(void* other);
    LocalVec3 Diff_00b13040(const LocalVec3& other) const;
    float FUN_00b2a180(void* other);
    LocalVec3& AddComponents(void* other);
    void ProcessEntries_00ddc870();
    void FUN_00e0f6e0();
};
#include "../../include/CVec3.h"
#include "../../include/NiMatrix3.h"

// src/speedtree/leafgeometry_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/leafgeometry.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/leafgeometry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/leafgeometry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct LeafLod
{
    char b[0x44];
};
struct SpeedTreeLodData
{
    char m_auiShapeKeys[0x28];
    unsigned short m_usValueAt28;
    char m_pAuxiliaryObject[2];
    LeafLod* m_pLeafLod;
    void CLeafGeometry_Invalidate();
};
struct FUN_00b27870_Class
{
    unsigned char m_bValueAt00;
    unsigned char m_auiShapeKeys[7];
    unsigned short m_usValueAt08;
    unsigned char m_pAuxiliaryObject[6];
    float** m_ppFloatData;
    unsigned char m_pad3[4];
    float* m_pCopiedLodData;
    unsigned short m_usValue;

    const float* CopyLodData(unsigned int& aiFloatCount);
};
void* __cdecl _memmove(void* dest, const void* src, unsigned int count);
extern "C" bool CSpeedTreeRT_GetTextureFlip();
extern const float DAT_01012054;
struct FUN_00b28720_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float* m_pLeafTable;

    void SetLeafTableEntry(int nLeaf, const float* pSrc);
};
struct LodB28
{
    char pad[0x10];
    char *p10, *p14, *p18, *p1c, *p20, *p24, *p28, *p2c, *p30, *p34, *p38;
    int pad3c;
    char* p40;
};
struct CB28
{
    char pad[0x28];
    unsigned short count;
    char pad2[2];
    LodB28* lods;
    void FreeLodBuffers();
};

__forceinline void LocalVec3::Set(float a, float b, float c)
{
    x = a;
    y = b;
    z = c;
}
__forceinline LocalVec3::LocalVec3(float a, float b, float c)
{
    Set(a, b, c);
}
__forceinline LocalVec3::LocalVec3(const float* p)
{
    Set(p[0], p[1], p[2]);
}
__forceinline float& LocalVec3::operator[](int n)
{
    return (&x)[n];
}
// src: COMMUNITY 0x00b04d40
inline float LocalVec3::CVec3_Distance(const LocalVec3& other) const
{
    float squared = (other.x - x) * (other.x - x) + (other.y - y) * (other.y - y) +
                    (other.z - z) * (other.z - z);
    int bits = (*reinterpret_cast<int*>(&squared) >> 1) + 0x1fc00000;
    return *reinterpret_cast<float*>(&bits);
}
struct GlobalObject_00b3f100
{
    float values[5];
    int count;
    ~GlobalObject_00b3f100();
};
// SpeedTree idv CRegion: min/max as variable-length CVec (float[5] + size; dtor 0x00b3f100); FUN_00b3caa0 grows it
// by a point, FUN_00b3c9a0 by another region. Not the shared 16-byte-aligned Bounds.
struct CRegion
{
    GlobalObject_00b3f100 lo, hi;
    CRegion();
// src: GUESS 0x00b3caa0 (confidence: low)
    inline CRegion ComputeValue_00b3caa0(const LocalVec3& p) const
    {
        CRegion result = *this;
        if (p.x < result.lo.values[0])
            result.lo.values[0] = p.x;
        if (p.y < result.lo.values[1])
            result.lo.values[1] = p.y;
        if (p.z < result.lo.values[2])
            result.lo.values[2] = p.z;
        if (p.x > result.hi.values[0])
            result.hi.values[0] = p.x;
        if (p.y > result.hi.values[1])
            result.hi.values[1] = p.y;
        if (p.z > result.hi.values[2])
            result.hi.values[2] = p.z;
        return result;
    }
// src: GUESS 0x00b3c9a0 (confidence: low)
    inline CRegion ProcessEntries_00b3c9a0(const CRegion& b) const
    {
        CRegion result = *this;
        for (int i = 0; i < 3; ++i)
        {
            if (b.lo.values[i] < lo.values[i])
                result.lo.values[i] = b.lo.values[i];
            if (b.hi.values[i] > hi.values[i])
                result.hi.values[i] = b.hi.values[i];
        }
        return result;
    }
};
struct Allocator
{
    void* p;
    inline void deallocate(void* value)
    {
        ::operator delete(value);
    }
    inline ~Allocator()
    {
        deallocate(p);
    }
};
struct AllocatorTag
{
    AllocatorTag();
    AllocatorTag(const AllocatorTag&);
};
struct FloatIterator
{
    float* current;
    void* owner;
};
struct FloatDerivedIterator : FloatIterator
{
};
struct VectorStorage
{
    Allocator allocator;
    int unk04, unk08;
    float *first, *last, *end;
    void initializeProxy(AllocatorTag tag);
    void copyAllocator(const AllocatorTag& tag);
    inline VectorStorage(AllocatorTag tag)
    {
        AllocatorTag copied(tag);
        initializeProxy(copied);
        copyAllocator(tag);
    }
};
struct FUN_00449fd0 : VectorStorage
{
    unsigned int maxSize() const;
    float* acquire(unsigned int n);
    void overflow();
    inline bool allocate(unsigned int n)
    {
        first = last = end = 0;
        if (!n)
            return false;
        if (maxSize() < n)
            overflow();
        else
        {
            float* storage = acquire(n);
            first = last = storage;
            end = first + n;
        }
        return true;
    }
    inline FUN_00449fd0() : VectorStorage(AllocatorTag())
    {
        float* initial = 0;
        first = initial;
        last = initial;
        end = initial;
    }
    void destroyRange(float* begin, float* finish);
    void releaseStorage(float* begin, unsigned int capacity);
    void releaseBytes(float* begin, unsigned int bytes);
    __forceinline void destroyElement(float* value)
    {
        typedef float Element;
        value->~Element();
    }
    inline void FUN_0065f240()
    {
        float* begin = first;
        float* finish = last;
        float* limit = end;
        if (begin)
        {
            unsigned int count = (unsigned int)(finish - begin);
            float* current = begin;
            while (count--)
            {
                destroyElement(current);
                ++current;
            }
            unsigned int capacity = (unsigned int)(limit - begin);
            unsigned int bytes = capacity * sizeof(float);
            releaseBytes(begin, bytes);
        }
        first = last = end = 0;
    }
    unsigned int size() const;
    unsigned int capacity() const;
    float* construct(float* where, unsigned int n, const float& value);
    FloatDerivedIterator endIter();
    FloatIterator insert(FloatIterator where, const float& value);
    inline void PushBack(const float& f)
    {
        unsigned int length = size();
        unsigned int space = capacity();
        if (length < space)
            last = construct(last, 1, f);
        else
        {
            FloatIterator where = endIter();
            insert(where, f);
        }
    }
    inline ~FUN_00449fd0()
    {
        FUN_0065f240();
    }
    inline float& operator[](unsigned int n);
};
void __cdecl FUN_00ec7c56();
inline float& FUN_00449fd0::operator[](unsigned int n)
{
    if (n >= (unsigned int)(last - first))
        FUN_00ec7c56();
    return first[n];
}
struct LeafRecord
{
    int unk00, unk04, unk08;
    unsigned short vertexCount, unk0e;
    unsigned char* textures;
    int unk14;
    float* vertices;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
};
struct LeafGeometry
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned short textureCount, unk1e;
    LocalVec3* sizes;
    LocalVec3* origins;
    unsigned short lodCount, unk2a;
    LeafRecord* lods;
    void CLeafGeometry_ComputeExtents(CRegion& output);
};
// @fnv 0x00b27910
// src: COMMUNITY 0x00b27910
void LeafGeometry::CLeafGeometry_ComputeExtents(CRegion& output)
{
    if (origins && sizes && lods)
    {
        FUN_00449fd0 radii;
        for (int i = 0; i < textureCount; ++i)
        {
            LocalVec3 center(origins[i][0] * sizes[i][0], origins[i][1] * sizes[i][1], 0);
            float radius = 0;
            if (radius < center.CVec3_Distance(LocalVec3(0, 0, 0)))
                radius = center.CVec3_Distance(LocalVec3(0, 0, 0));
            if (radius < center.CVec3_Distance(LocalVec3(sizes[i][0], 0, 0)))
                radius = center.CVec3_Distance(LocalVec3(sizes[i][0], 0, 0));
            if (radius < center.CVec3_Distance(LocalVec3(sizes[i][0], sizes[i][1], 0)))
                radius = center.CVec3_Distance(LocalVec3(sizes[i][0], sizes[i][1], 0));
            if (radius < center.CVec3_Distance(LocalVec3(0, sizes[i][1], 0)))
                radius = center.CVec3_Distance(LocalVec3(0, sizes[i][1], 0));
            radii.PushBack(radius);
        }
        for (int j = 0; j < lodCount; ++j)
        {
            LeafRecord* lod = &lods[j];
            for (unsigned int k = 0; k < lod->vertexCount; ++k)
            {
                CRegion bounds;
                const float* vertex5 = &lod->vertices[k * 3];
                LocalVec3 position(vertex5);
                float radius = radii[lod->textures[k] / 2];
                bounds = bounds.ComputeValue_00b3caa0(LocalVec3(position.x + radius, position.y, position.z));
                bounds = bounds.ComputeValue_00b3caa0(LocalVec3(position.x - radius, position.y, position.z));
                bounds = bounds.ComputeValue_00b3caa0(LocalVec3(position.x, position.y + radius, position.z));
                bounds = bounds.ComputeValue_00b3caa0(LocalVec3(position.x, position.y - radius, position.z));
                bounds = bounds.ComputeValue_00b3caa0(LocalVec3(position.x, position.y, position.z + radius));
                bounds = bounds.ComputeValue_00b3caa0(LocalVec3(position.x, position.y, position.z - radius));
                output = output.ProcessEntries_00b3c9a0(bounds);
            }
        }
    }
}

struct Matrix4f
{
    float m_afMatrix[16];
};

inline CVec3::CVec3()
{
    z = 0.0f;
    y = 0.0f;
    x = 0.0f;
}

inline CVec3::CVec3(float a, float b, float c)
{
    (this->*static_cast<void (CVec3::*)(float, float, float)>(&CVec3::Set))(a, b, c);
}

inline void CVec3::Set(float a, float b, float c)
{
    x = a;
    y = b;
    z = c;
}

inline float& CVec3::operator[](int nIndex)
{
    return (&x)[nIndex];
}

// src: GUESS 0x00b05000 (confidence: medium)
inline CVec3 CVec3::TransformPointByMatrix4(const Matrix4f& cTransform)
{
    CVec3 result;
    result.x =
        cTransform.m_afMatrix[12] +
        (cTransform.m_afMatrix[8] * z +
         (cTransform.m_afMatrix[4] * y + cTransform.m_afMatrix[0] * x));
    result.y =
        cTransform.m_afMatrix[13] +
        (cTransform.m_afMatrix[9] * z +
         (cTransform.m_afMatrix[5] * y + cTransform.m_afMatrix[1] * x));
    result.z =
        cTransform.m_afMatrix[14] +
        (cTransform.m_afMatrix[10] * z +
         (cTransform.m_afMatrix[6] * y + cTransform.m_afMatrix[2] * x));
    return result;
}

// src: GUESS 0x00b05000 (confidence: medium)
inline CVec3 CVec3::TransformPointByMatrix4(const Matrix4f& cTransform) const
{
    float fX = cTransform.m_afMatrix[12] + cTransform.m_afMatrix[8] * z +
               cTransform.m_afMatrix[4] * y + cTransform.m_afMatrix[0] * x;
    float fY = cTransform.m_afMatrix[13] + cTransform.m_afMatrix[9] * z +
               cTransform.m_afMatrix[5] * y + cTransform.m_afMatrix[1] * x;
    float fZ = cTransform.m_afMatrix[14] + cTransform.m_afMatrix[10] * z +
               cTransform.m_afMatrix[6] * y + cTransform.m_afMatrix[2] * x;
    return CVec3(fX, fY, fZ);
}

struct S00b28280_Lod
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usNumLeaves;
    short unk0e;
    int unk10;
    int unk14;
    float* m_ppFloatData;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    float* m_pLeafNormals;
};

struct S00b28280_Leaf
{
    char unk00;
    unsigned char m_bValueAt00;
    short unk02;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_usValueAt08;
    short unk1e;
    CVec3* m_pRockingGroups;
    int unk24;
    unsigned short m_usValueAt28;
    short unk2a;
    S00b28280_Lod* m_pLeafLod;

    void ProcessEntries_00b28280(const Matrix4f& cTransform);
};

// @fnv 0x00b28280
// src: GUESS 0x00b28280 (confidence: low)
void S00b28280_Leaf::ProcessEntries_00b28280(const Matrix4f& cTransform)
{
    if (m_pLeafLod && m_pRockingGroups)
    {
        float fScale5;
        int i;
        S00b28280_Lod* pLodA;
        int j_;
        float* pLeafVertex4;

        for (i = 0; i < m_usValueAt28; ++i)
        {
            pLodA = &m_pLeafLod[i];
            for (j_ = 0; j_ < pLodA->m_usNumLeaves; ++j_)
            {
                pLeafVertex4 = pLodA->m_ppFloatData + j_ * 3;
                CVec3 cCoord6(pLeafVertex4[0], pLeafVertex4[1], pLeafVertex4[2]);
                cCoord6 = cCoord6.TransformPointByMatrix4(cTransform);
                _memmove(pLeafVertex4, &cCoord6, 12);

                if (m_bValueAt00)
                {
                    float* kPLeafNormal = pLodA->m_pLeafNormals + j_ * 3;
                    CVec3 cNormal5(kPLeafNormal[0], kPLeafNormal[1], kPLeafNormal[2]);
                    cNormal5 = cNormal5.TransformPointByMatrix4(cTransform);
                    _memmove(kPLeafNormal, &cNormal5, 12);
                }
            }
        }

        fScale5 = *(const float*)&cTransform;
        for (int k = 0; k < m_usValueAt08; ++k)
        {
            m_pRockingGroups[k].Scale(fScale5);
        }
    }
}

void __cdecl FUN_00ec7c56();
struct LeafB28480
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
    CVec3 m_kFirstVector;
    int unk3C;
    int unk40;
    int unk44;
    CVec3 m_kTranslation;
};
struct LeafVectorB28480
{
    void* m_pkProxy;
    int m_iAux;
    int m_iAlval;
    LeafB28480* m_pkFirst;
    LeafB28480* m_pkLast;
    LeafB28480* m_pkEnd;
    unsigned int size() const
    {
        return m_pkLast - m_pkFirst;
    }
    const LeafB28480& operator[](unsigned int uiPos) const
    {
        if (!(uiPos < size()))
            FUN_00ec7c56();
        return *(m_pkFirst + uiPos);
    }
};
struct LeafSourceB28480
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LeafVectorB28480 m_vLeaves;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    unsigned short m_usValueAt28;
    unsigned short unk42;
    int unk44;
    int unk48;
    int m_nTextureWidth;
    int m_nTextureHeight;
    int m_nStyle;
};
struct LeafGeometryB28480
{
    int unk00;
    int unk04;
    unsigned short m_usValueAt28;
    unsigned short unk0A;
    int m_nStyle;
    int m_nTextureWidth;
    int m_nTextureHeight;
    float* m_pfTexCoords;
    unsigned short m_usNumLeaves;
    unsigned short unk1E;
    CVec3* m_pPositions;
    CVec3* m_pLeafVectors;
    void CLeafGeometry_InitLods(unsigned short usLod, int nSeed);
    void CLeafGeometry_Init(unsigned short usLod, int nSeed, const LeafSourceB28480* pSource);
};

// @fnv 0x00b28480
// src: COMMUNITY 0x00b28480
void LeafGeometryB28480::CLeafGeometry_Init(unsigned short usLod, int nSeed, const LeafSourceB28480* pSource)
{
    m_usValueAt28 = pSource->m_usValueAt28;
    m_nStyle = pSource->m_nStyle;
    m_nTextureWidth = pSource->m_nTextureWidth;
    m_nTextureHeight = pSource->m_nTextureHeight;
    m_usNumLeaves = pSource->m_vLeaves.size();
    m_pPositions = new CVec3[m_usNumLeaves];
    m_pLeafVectors = new CVec3[m_usNumLeaves];
    for (int i = 0; i < m_usNumLeaves; ++i)
    {
        m_pPositions[i] = pSource->m_vLeaves[i].m_kTranslation;
        m_pLeafVectors[i] = pSource->m_vLeaves[i].m_kFirstVector;
    }
    int nNumTexCoords = m_usNumLeaves * m_usValueAt28 * 2 * 4 * 4;
    m_pfTexCoords = new float[nNumTexCoords];
    CLeafGeometry_InitLods(usLod, nSeed);
}

namespace LeafMatrices {

struct LeafPoint
{
    float x, y, z;
};

struct LeafRows
{
    CVec3 akRow[4];
    LeafRows()
    {}
};

struct LeafData
{
    bool bValid;
    char pad01[7];
    int iIndex;
    char pad0C[0x30];
};

struct LeafEntry
{
    LeafData kData;
    bool bComputed;
    char pad3D[7];
    bool IsComputed() const
    {
        return bComputed;
    }
};

struct LeafSettings
{
    char pad00[0x10];
    int iMode;
    int GetMode() const
    {
        return iMode;
    }
};

void* __cdecl FUN_00ec44d0(void* apDest, const void* apSrc, unsigned int auiSize);

struct LeafBuilder
{
    int iUnk00;
    LeafSettings* pSettings;
    unsigned short usRowCount;
    unsigned short usUnk0A;
    void* pUnk0C;
    float** ppMatrices;
    int iUnk14;
    int iUnk18;
    unsigned short usLeafCount;
    unsigned short usUnk1E;
    CVec3* pDirections;
    CVec3* pPositions;
    unsigned short usEntryCount;
    unsigned short usUnk2A;
    LeafEntry* pEntries;

    void CLeafGeometry_ComputeWindEffect(unsigned short ausIndex);
    void CLeafGeometry_Update_(LeafData* apOut, unsigned short ausIndex, int aiUnused1, int aiUnused2, float afScale);
};

// @fnv 0x00b288f0
// src: COMMUNITY 0x00b288f0
void LeafBuilder::CLeafGeometry_Update_(LeafData* apOut, unsigned short ausIndex, int aiUnused1, int aiUnused2, float afScale)
{
    if (pEntries && ausIndex < usEntryCount && ppMatrices && pPositions && pDirections && pSettings && pUnk0C)
    {
        LeafEntry* pEntry = &pEntries[ausIndex];
        if (!pEntry->IsComputed())
        {
            if (pSettings->GetMode() == 1)
                CLeafGeometry_ComputeWindEffect(ausIndex);
            float fFactor = 1.0f;
            if (ausIndex > 0)
                fFactor = 1.0f + ausIndex * afScale;
            CVec3 akRows[4];
            CVec3 akCopyCur[4];
            for (int i = 0; i < usLeafCount * 2; ++i)
            {
                CVec3 kPos = pPositions[i / 2];
                if (i % 2 == 0)
                    kPos[0] = 1.0f - kPos[0];
                CVec3* pDir = &pDirections[i / 2];
                // Every component is assigned below. Float-aligned raw storage avoids
                // the shared constructor's extra Set argument temporaries under /Ob1.
                float kMatIn[sizeof(NiMatrix3) / sizeof(float)];
                reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[0][0] = 0.0f;
                reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[0][1] = (1.0f - kPos[0]) * fFactor * pDir->x;
                reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[0][2] = (1.0f - kPos[1]) * fFactor * pDir->y;
                reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[1][0] = 0.0f;
                reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[1][1] = -(kPos[0] * pDir->x) * fFactor;
                reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[1][2] = reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[0][2];
                reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[2][0] = 0.0f;
                reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[2][1] = reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[1][1];
                reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[2][2] = -(kPos[1] * pDir->y) * fFactor;
                LeafPoint kTransVal;
                kTransVal.x = 0.0f;
                kTransVal.y = reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[0][1];
                kTransVal.z = reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[2][2];
                akRows[0].x = reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[0][0];
                akRows[0].y = reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[0][1];
                akRows[0].z = reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[0][2];
                (akRows[1].*static_cast<void (CVec3::*)(float, float, float)>(&CVec3::Set))(reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[1][0],
                              reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[1][1],
                              reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[1][2]);
                (akRows[2].*static_cast<void (CVec3::*)(float, float, float)>(&CVec3::Set))(reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[2][0],
                              reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[2][1],
                              reinterpret_cast<NiMatrix3&>(kMatIn).m_pEntry[2][2]);
                (akRows[3].*static_cast<void (CVec3::*)(float, float, float)>(&CVec3::Set))(kTransVal.x, kTransVal.y, kTransVal.z);
                for (int j = 0; j < usRowCount; ++j)
                {
                    akCopyCur[0] = akRows[0];
                    akCopyCur[1] = akRows[1];
                    akCopyCur[2] = akRows[2];
                    akCopyCur[3] = akRows[3];
                    float* pDest = ppMatrices[ausIndex] + usRowCount * 16 * i + j * 16;
                    FUN_00ec44d0(pDest, &akCopyCur[0], 0xc);
                    pDest += 4;
                    FUN_00ec44d0(pDest, &akCopyCur[1], 0xc);
                    pDest += 4;
                    FUN_00ec44d0(pDest, &akCopyCur[2], 0xc);
                    pDest += 4;
                    FUN_00ec44d0(pDest, &akCopyCur[3], 0xc);
                    pDest += 4;
                }
            }
            pEntry->bComputed = true;
        }
        *apOut = pEntry->kData;
        apOut->bValid = true;
        apOut->iIndex = ausIndex;
    }
}

}

namespace leafwind {

struct Matrix4f
{
    float m_fComponents[4][4];
};

inline float Interpolate(float fStart, float m_fEndValue, float fNormalizedPosition)
{
    return fStart + (m_fEndValue - fStart) * fNormalizedPosition;
}

extern Matrix4f* DAT_011f8d88;

struct WindEngine
{
    static const Matrix4f& GetWindMatrix(unsigned short usIndex)
    {
        return DAT_011f8d88[usIndex];
    }
};

struct SLeafLod
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usValueAt0C;
    unsigned short unk0e;
    int unk10;
    int unk14;
    float* m_pFloatArrayAt18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    float* m_pFloatArrayAt34;
    unsigned char* m_pByteArrayAt38;
    int unk3c;
    float* m_pOrigCoordCenterCoords;
};

void* memcpy(void* pDest, const void* pSrc, unsigned int uiSize);

class CLeafGeometryWind
{
  public:
    unsigned char unk00;
    unsigned char m_bWindEnabled;
    unsigned short unk02;
    void* m_pLeafTreeRuntime;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    unsigned short m_usValueAt28;
    unsigned short unk2a;
    SLeafLod* m_pLeafLod;

    void CLeafGeometry_ComputeWindEffect(unsigned short usLod);
};

// @fnv 0x00b29190
// src: COMMUNITY 0x00b29190
void CLeafGeometryWind::CLeafGeometry_ComputeWindEffect(unsigned short usLod)
{
    SLeafLod* pLod;

    if (m_pLeafTreeRuntime && usLod < m_usValueAt28 && m_bWindEnabled && m_pLeafLod && (pLod = m_pLeafLod + usLod) &&
        pLod->m_pOrigCoordCenterCoords && pLod->m_pFloatArrayAt18)
    {
        CVec3 cPos;
        CVec3 cNewPos;

        for (int i = 0; i < pLod->m_usValueAt0C; ++i)
        {
            float fWeight = pLod->m_pFloatArrayAt34[i];
            const float* pOrigCoord = pLod->m_pOrigCoordCenterCoords + i * 3;
            (cPos.*static_cast<void (CVec3::*)(float, float, float)>(&CVec3::Set))(
                pOrigCoord[0], pOrigCoord[1], pOrigCoord[2]);
            unsigned char ucWindMatrix = pLod->m_pByteArrayAt38[i];
            cPos = static_cast<const CVec3&>(cPos).TransformPointByMatrix4(
                reinterpret_cast<const ::Matrix4f&>(WindEngine::GetWindMatrix(ucWindMatrix)));
            (cNewPos.*static_cast<void (CVec3::*)(float, float, float)>(&CVec3::Set))(
                Interpolate(pOrigCoord[0], cPos[0], fWeight), Interpolate(pOrigCoord[1], cPos[1], fWeight),
                Interpolate(pOrigCoord[2], cPos[2], fWeight));
            memcpy(pLod->m_pFloatArrayAt18 + i * 3, &cNewPos, 12);
        }
    }
}

}
