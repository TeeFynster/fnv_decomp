
// src/gamebryo2.2/corelibs/nicollision/niobbnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/niobbnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiOBBNode.h"
#include "../../../../include/NiPoint3.h"

inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}

inline NiPoint3 NiPoint3::operator+(const NiPoint3& kPt) const
{
    return NiPoint3(x + kPt.x, y + kPt.y, z + kPt.z);
}

inline bool NiPoint3::operator==(const NiPoint3& kPt) const
{
    return x == kPt.x && y == kPt.y && z == kPt.z;
}

// The shared layout leaves the cached bounds ID opaque.
static __forceinline int& boundsId(NiOBBNode* node)
{
    return *(int*)((char*)node + 0x88);
}

// @fnv 0x00eb6b70
bool NiOBBNode::HasChildren()
{
    return m_0x80 || m_0x84;
}

struct QueryContext
{
    int unk00;
    void UpdateWorldBounds(void* detail);
    int IntersectRay(void* a1, void* a2);
};
// Updates the context when a6 differs from m_0x88, rejects via context.IntersectRay, then returns the first child Test result >= 1, else 0.
// @fnv 0x00eb9430
int NiOBBNode::TestChildren(void* a1, void* a2, int a3, int a4, void* a5, int a6)
{
    if (a6 != boundsId(this))
    {
        ((QueryContext*)pad1)->UpdateWorldBounds((char*)a5 + 0x68);
        boundsId(this) = a6;
    }
    if (!((QueryContext*)pad1)->IntersectRay(a1, a2))
        return 0;
    int result;
    if (m_0x80 != 0)
    {
        result = ((NiOBBNode*)m_0x80)->TestChildren(a1, a2, a3, a4, a5, a6);
        if (result >= 1)
            return result;
    }
    if (m_0x84 != 0)
    {
        result = ((NiOBBNode*)m_0x84)->TestChildren(a1, a2, a3, a4, a5, a6);
        if (result >= 1)
            return result;
    }
    return 0;
}

// RunSwapTests - 175 bytes.
//
// The pack's unit file is not usable for this function: the object that is
// swapped is NOT the unit's RayNode (the unit has no 0x38 callback slot and
// no 0x20/0x2c pair of 3-int records), so the object is modelled here with
// its own stand-in structures, laid out from the disassembly.
//
//   [esi+0x00] [esi+0x04] [esi+0x08] [esi+0x0c]  four "shape" pointers
//   [esi+0x1c] of a shape -> the object that owns the callback
//   [esi+0x38] of that object -> the callback (int (*)(Node*))
//   [esi+0x20] and [esi+0x2c] -> two 3-int records that are exchanged
//
// The two records are exchanged with a 12-byte struct copy; MSVC 2008 keeps
// the temporary in three registers, which is what produces the original's
// instruction order (eax/ecx/edx hold the saved halves, ebx is reused for
// the copies).

struct SwapNode;

typedef int(__cdecl* SwapTestFn)(SwapNode*);

// the "shape" object: +0x1c is the object that owns the callback, +0x38 is
// the callback itself (called with the node, returns 0/1/2).
struct SwapShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    SwapShape* m_1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    SwapTestFn m_38;
};

// a 3-int record
struct SwapRecord
{
    int x;
    int y;
    int z;
};

struct SwapNode
{
    SwapShape* m_00;
    SwapShape* m_04;
    SwapShape* m_08;
    SwapShape* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    SwapRecord m_20;
    SwapRecord m_2c;
};

// @fnv 0x00eb9a50
int __stdcall RunSwapTests(SwapNode* pNode)
{
    int iResult0 = 0;
    int iResult1 = 0;

    SwapShape* pShape = pNode->m_00;
    if (pShape)
    {
        SwapShape* t = pShape->m_1c;
        if (!t)
            t = pNode->m_08->m_1c;
        if (t)
        {
            SwapTestFn pfnTest = t->m_38;
            if (pfnTest)
                iResult0 = pfnTest(pNode);
        }
    }

    pShape = pNode->m_04;
    if (pShape)
    {
        SwapShape* t = pShape->m_1c;
        if (!t)
            t = pNode->m_0c->m_1c;
        if (t)
        {
            SwapTestFn pfnTest = t->m_38;
            if (pfnTest)
            {
                // exchange the two shapes and their two records
                SwapShape* a = pNode->m_00;
                SwapShape* b = pNode->m_04;
                pNode->m_00 = b;
                pNode->m_04 = a;
                SwapRecord recordSaved = pNode->m_20;
                pNode->m_20 = pNode->m_2c;
                pNode->m_2c = recordSaved;
                iResult1 = pfnTest(pNode);
            }
        }
    }

    if (iResult0 == 0)
    {
        if (iResult1 == 0)
            return 0;
    }
    else
    {
        if (iResult0 == 2)
            return 2;
    }
    int iResult = 1;
    if (iResult1 == 2)
        iResult = 2;
    return iResult;
}

static void triangleIndices(unsigned short* indices, int tri, int& a, int& b, int& c)
{
    int offset = tri * 3;
    a = indices[offset++];
    b = indices[offset++];
    c = indices[offset];
}
struct V3
{
    float x, y, z;
    V3()
    {}
    V3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    V3 operator+(const V3& b) const
    {
        return V3(x + b.x, y + b.y, z + b.z);
    }
    V3 operator-(const V3& b) const
    {
        return V3(x - b.x, y - b.y, z - b.z);
    }
    V3 operator*(float f) const
    {
        return V3(x * f, y * f, z * f);
    }
    float Dot(const V3& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
    static float StaticDot(const V3& a, const V3& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }
    V3& operator=(const V3& b)
    {
        x = b.x;
        y = b.y;
        z = b.z;
        return *this;
    }
    V3& operator+=(const V3& b)
    {
        x += b.x;
        y += b.y;
        z += b.z;
        return *this;
    }
};
struct M3
{
    V3 row0, row1, row2;
};
struct LocalObj
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    void FUN_00a86bf0();
};
struct SubObj
{
    int m_00;
    int m_04;
    int m_08;
};
struct WorkObj
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    void GetMatrix(void* a1, void* a2);
};
struct RayNodeW7
{
    void* unk00;
    V3 center;
    M3 matrix;
    V3 extent;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    NiOBBNode* m_0x80;
    NiOBBNode* m_0x84;
    int m_0x88;
    void ComputeWeightedCovariance(void* out, unsigned short* a1, V3* a2, int a3, int a4, int a5, int a6, int* a7);
    void ComputeTriangleBounds(int a0, unsigned short* a1, V3* a2, int a3, int a4, int a5, int a6, int* a7);
};

// @fnv 0x00eb94e0
void RayNodeW7::ComputeTriangleBounds(int a0, unsigned short* ausIndices, V3* apVertices, int a3, int a4, int a5,
                                      int aiEndTri, int* apiTriMap)
{
    V3& origin = center;
    M3& mat = matrix;
    float* pfMatrixEntries = (float*)&matrix;
    SubObj sub;
    WorkObj work;
    LocalObj detail;
    ComputeWeightedCovariance(&work, ausIndices, apVertices, a3, a4, a5, aiEndTri, apiTriMap);
    work.GetMatrix(&sub, &mat);
    V3 vLower(0, 0, 0), vUpper(0, 0, 0);
    unsigned short index = (unsigned short)a5;
    if ((int)(unsigned short)index <= aiEndTri)
    {
        do
        {
            int first, second, third;
            triangleIndices(ausIndices, apiTriMap[(unsigned short)index], first, second, third);
            const V3* p0 = &apVertices[first];
            const V3* p1 = &apVertices[second];
            const V3* p2 = &apVertices[third];
            V3 vDelta0, vDelta1, vDelta2;
            float fProjX, fProjY, fProjZ;
            vDelta0 = *p0 - origin;
            fProjX = vDelta0.x * pfMatrixEntries[0] + vDelta0.y * pfMatrixEntries[1] + vDelta0.z * pfMatrixEntries[2];
            fProjY = vDelta0.Dot(mat.row1);
            fProjZ = vDelta0.x * pfMatrixEntries[6] + vDelta0.y * pfMatrixEntries[7] + vDelta0.z * pfMatrixEntries[8];

            if (fProjX < vLower.x)
                vLower.x = fProjX;
            else if (fProjX > vUpper.x)
                vUpper.x = fProjX;
            if (fProjY < vLower.y)
                vLower.y = fProjY;
            else if (fProjY > vUpper.y)
                vUpper.y = fProjY;
            if (fProjZ < vLower.z)
                vLower.z = fProjZ;
            else if (fProjZ > vUpper.z)
                vUpper.z = fProjZ;
            vDelta1 = *p1 - origin;
            fProjX = vDelta1.x * pfMatrixEntries[0] + vDelta1.y * pfMatrixEntries[1] + vDelta1.z * pfMatrixEntries[2];
            fProjY = vDelta1.Dot(mat.row1);
            fProjZ = vDelta1.x * pfMatrixEntries[6] + vDelta1.y * pfMatrixEntries[7] + vDelta1.z * pfMatrixEntries[8];

            if (fProjX < vLower.x)
                vLower.x = fProjX;
            else if (fProjX > vUpper.x)
                vUpper.x = fProjX;
            if (fProjY < vLower.y)
                vLower.y = fProjY;
            else if (fProjY > vUpper.y)
                vUpper.y = fProjY;
            if (fProjZ < vLower.z)
                vLower.z = fProjZ;
            else if (fProjZ > vUpper.z)
                vUpper.z = fProjZ;
            vDelta2 = *p2 - origin;
            fProjX = vDelta2.x * pfMatrixEntries[0] + vDelta2.y * pfMatrixEntries[1] + vDelta2.z * pfMatrixEntries[2];
            fProjY = vDelta2.Dot(mat.row1);
            fProjZ = vDelta2.x * pfMatrixEntries[6] + vDelta2.y * pfMatrixEntries[7] + vDelta2.z * pfMatrixEntries[8];

            if (fProjX < vLower.x)
                vLower.x = fProjX;
            else if (fProjX > vUpper.x)
                vUpper.x = fProjX;
            if (fProjY < vLower.y)
                vLower.y = fProjY;
            else if (fProjY > vUpper.y)
                vUpper.y = fProjY;
            if (fProjZ < vLower.z)
                vLower.z = fProjZ;
            else if (fProjZ > vUpper.z)
                vUpper.z = fProjZ;
            ++index;
        } while ((int)(unsigned short)index <= aiEndTri);
    }
    extent = (vUpper - vLower) * 0.5;
    V3 vMidpoint = (vUpper + vLower) * 0.5;
    origin += mat.row0 * vMidpoint.x + mat.row1 * vMidpoint.y + mat.row2 * vMidpoint.z;
    detail.FUN_00a86bf0();
    ((QueryContext*)&origin)->UpdateWorldBounds(&detail);
    unk7c = a0;
}

// Plain point with the implicit (bitwise) copy assignment of the game's NiPoint3; the pack's V3
// declares its own operator=, which copies through the FPU instead of with integer moves.
struct PlainPoint3
{
    float x, y, z;
    PlainPoint3()
    {}
    PlainPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
};

// Accumulates weighted centroid and covariance over triangles a7[a5..a6], stores the centroid in center and the covariance matrix in out.
// @fnv 0x00eb8ae0
void RayNodeW7::ComputeWeightedCovariance(void* pCovariance, unsigned short* pIndices, V3* pVertices, int pWeights,
                                          int pCentroids, int iStart, int iEnd, int* pTriList)
{
    V3 vSum(0.0f, 0.0f, 0.0f);
    float fTotalWeight = 0.0f;
    float cov[6];
    for (int k = 0; k < 6; k++)
        cov[k] = 0.0f;

    for (unsigned short i = (unsigned short)iStart; i <= iEnd; i++)
    {
        int tri = pTriList[i];
        int i0, i1, i2;
        triangleIndices(pIndices, tri, i0, i1, i2);
        const V3& p0 = pVertices[i0];
        const V3& p1 = pVertices[i1];
        const V3& p2 = pVertices[i2];
        const V3& c = ((V3*)pCentroids)[tri];
        float w = ((float*)pWeights)[tri];

        fTotalWeight += w;
        vSum += c * w;

        cov[0] += (c.x * c.x + p0.x * p0.x + p1.x * p1.x + p2.x * p2.x) * w;
        cov[1] += (c.x * c.y + p0.x * p0.y + p1.x * p1.y + p2.x * p2.y) * w;
        cov[2] += (c.x * c.z + p0.x * p0.z + p1.x * p1.z + p2.x * p2.z) * w;
        cov[3] += (c.y * c.y + p0.y * p0.y + p1.y * p1.y + p2.y * p2.y) * w;
        cov[4] += (c.y * c.z + p0.y * p0.z + p1.y * p1.z + p2.y * p2.z) * w;
        cov[5] += (c.z * c.z + p0.z * p0.z + p1.z * p1.z + p2.z * p2.z) * w;
    }

    float fInvWeight = 1.0f / fTotalWeight;
    float factor = fInvWeight * 0.25;

    *(PlainPoint3*)&center = PlainPoint3(vSum.x * fInvWeight, vSum.y * fInvWeight, vSum.z * fInvWeight);

    M3* pMatrix = (M3*)pCovariance;
    pMatrix->row0.x = factor * cov[0] - center.x * center.x;
    float m01 = factor * cov[1] - center.x * center.y;
    pMatrix->row0.y = m01;
    float m02 = factor * cov[2] - center.x * center.z;
    pMatrix->row0.z = m02;
    pMatrix->row1.y = factor * cov[3] - center.y * center.y;
    float m12 = factor * cov[4] - center.y * center.z;
    pMatrix->row1.z = m12;
    pMatrix->row2.z = factor * cov[5] - center.z * center.z;
    pMatrix->row1.x = m01;
    pMatrix->row2.x = m02;
    pMatrix->row2.y = m12;
}

struct MyContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;

    void UpdateWorldBounds(void* detail);
    int NiOBBox_TestIntersection(void* other);
};

// Recursively compares this node's context with another node's, refreshing cached ids, and descends into child nodes up to the given depths.
// @fnv 0x00eb9180
bool NiOBBNode::CompareTreeRecursive(NiOBBNode* other, char* apThisData, char* apOtherData, int depthA, int depthB, int idA,
                                  int idB)
{
    if (!other)
        return false;

    if (idA != boundsId(this))
    {
        (*(MyContext*)this->pad1).UpdateWorldBounds(apThisData + 0x68);
        boundsId(this) = idA;
    }

    if (idB != boundsId(other))
    {
        (*(MyContext*)other->pad1).UpdateWorldBounds(apOtherData + 0x68);
        boundsId(other) = idB;
    }

    if (!(*(MyContext*)this->pad1).NiOBBox_TestIntersection(&(*(MyContext*)other->pad1)))
        return false;

    if (!depthA || !depthB)
        return true;

    if (this->IsTerminalNode())
    {
        if (other->IsTerminalNode())
            return true;

        if (!((NiOBBNode*)other)->HasChildren())
            return true;

        return this->CompareTreeRecursive(((NiOBBNode*)other->m_0x80), apThisData, apOtherData, depthA, depthB - 1, idA, idB) ||
               this->CompareTreeRecursive(((NiOBBNode*)other->m_0x84), apThisData, apOtherData, depthA, depthB - 1, idA, idB);
    }

    if (other->IsTerminalNode())
    {
        if (!((NiOBBNode*)this->m_0x80) || !((NiOBBNode*)this->m_0x84))
            return true;

        return ((NiOBBNode*)this->m_0x80)->CompareTreeRecursive(other, apThisData, apOtherData, depthA - 1, depthB, idA, idB) ||
               ((NiOBBNode*)this->m_0x84)->CompareTreeRecursive(other, apThisData, apOtherData, depthA - 1, depthB, idA, idB);
    }

    if (!((NiOBBNode*)this->m_0x80) || !((NiOBBNode*)this->m_0x84))
        return true;

    int iChildDepthA = depthA - 1;
    int iChildDepthB = depthB - 1;
    return ((NiOBBNode*)this->m_0x80)->CompareTreeRecursive(((NiOBBNode*)other->m_0x80), apThisData, apOtherData, iChildDepthA, iChildDepthB, idA,
                                              idB) ||
           ((NiOBBNode*)this->m_0x80)->CompareTreeRecursive(((NiOBBNode*)other->m_0x84), apThisData, apOtherData, iChildDepthA, iChildDepthB, idA,
                                              idB) ||
           ((NiOBBNode*)this->m_0x84)->CompareTreeRecursive(((NiOBBNode*)other->m_0x80), apThisData, apOtherData, iChildDepthA, iChildDepthB, idA,
                                              idB) ||
           ((NiOBBNode*)this->m_0x84)->CompareTreeRecursive(((NiOBBNode*)other->m_0x84), apThisData, apOtherData, iChildDepthA, iChildDepthB, idA,
                                              idB);
}

struct OBBShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    NiPoint3 m_kValue;
};

struct OBBContext
{
    int unk00;
    int NiOBBox_FindIntersection(OBBContext* pkOther, float* pfTime, NiPoint3* pkPoint);
    void ProjectOntoAxes(NiPoint3* pkPoint, NiPoint3* pkNormal);
};

struct OBBCollisionRecord
{
    int m_iA;
    int m_iB;
    int m_iC;
    int m_iD;
    float m_fTime;
    NiPoint3 m_kPoint;
    NiPoint3 m_kNormal0;
    NiPoint3 m_kNormal1;
    int m_iE;
    int m_iF;
};

struct OBBLeaf
{
    void* unk00;
    OBBContext m_kContext;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    NiPoint3 m_kCenter;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    OBBShape* m_pkShape;

    int NiOBBNode_BoxBoxCollision(OBBLeaf* pkOther, int iA, int iB, int iC, int iD, bool* pbHit);
    int RunSwapTests(OBBCollisionRecord* pkRecord);
};

// On a collision, sets pbHit, projects the contact point onto both contexts' axes, and runs swap tests.
// @fnv 0x00eb9b00
// src: GAMEBRYO_LIB 0x00eb9b00
int OBBLeaf::NiOBBNode_BoxBoxCollision(OBBLeaf* pkOther, int iA, int iB, int iC, int iD, bool* pbHit)
{
    OBBCollisionRecord kRecord;
    kRecord.m_iE = 0;
    kRecord.m_iF = 0;
    kRecord.m_iA = iA;
    kRecord.m_iB = iB;
    kRecord.m_iC = iC;
    kRecord.m_iD = iD;

    OBBShape* pkShape0 = m_pkShape;
    NiPoint3 kV0 = pkShape0->m_kValue;
    OBBShape* pkShape1 = pkOther->m_pkShape;
    NiPoint3 kV1 = pkShape1->m_kValue;
    int iCollide;
    if ((const NiPoint3&)kV0 == NiPoint3::ZERO && (const NiPoint3&)kV1 == NiPoint3::ZERO)
    {
        kRecord.m_fTime = 0.0f;
        NiPoint3 kSum = m_kCenter + pkOther->m_kCenter;
        kRecord.m_kPoint = NiPoint3(kSum.x * 0.5, kSum.y * 0.5, kSum.z * 0.5);
        iCollide = 1;
    }
    else
    {
        iCollide = m_kContext.NiOBBox_FindIntersection(&pkOther->m_kContext, &kRecord.m_fTime, &kRecord.m_kPoint);
    }
    if (iCollide)
    {
        *pbHit = true;
        m_kContext.ProjectOntoAxes(&kRecord.m_kPoint, &kRecord.m_kNormal0);
        pkOther->m_kContext.ProjectOntoAxes(&kRecord.m_kPoint, &kRecord.m_kNormal1);
        return RunSwapTests(&kRecord);
    }
    return 0;
}

extern "C" void _ReadWriteBarrier(void);
struct Depth
{
    int value;
    operator int() const
    {
        return value;
    }
    Depth& operator--()
    {
        --value;
        return *this;
    }
};

struct RayTree
{
    virtual void Slot00();
    virtual bool Slot04();
    virtual void Slot08();
    virtual int Intersect(RayTree* pOther, void* a2, void* a3, void* a4, void* a5, int depth1, Depth depth2, int id1,
                          int id2, void* a10);
    MyContext context;
    RayTree* m_0x80;
    RayTree* m_0x84;
    int m_0x88;
    bool FUN_00eb6b70();
    int NiOBBNode_BoxBoxCollision(RayTree* pOther, void* a2, void* a3, void* a4, void* a5, void* a10);
};

// Checks bounds, then tests this node or recursively tests its children, returning a positive result or 0.
// @fnv 0x00eb9cc0
int RayTree::Intersect(RayTree* pOther, void* a2, void* a3, void* a4, void* a5, int aiDepthA, Depth adDepthB,
                       int aiBoundsIdA, int aiBoundsIdB, void* a10)
{
    if (pOther == 0)
        return 0;

    if (aiBoundsIdA != m_0x88)
    {
        context.UpdateWorldBounds((char*)a4 + 0x68);
        m_0x88 = aiBoundsIdA;
    }
    if (aiBoundsIdB != pOther->m_0x88)
    {
        pOther->context.UpdateWorldBounds((char*)a5 + 0x68);
        pOther->m_0x88 = aiBoundsIdB;
    }
    if (!context.NiOBBox_TestIntersection(&pOther->context))
        goto fail;

    if (!aiDepthA || !adDepthB)
        return NiOBBNode_BoxBoxCollision(pOther, a2, a3, a4, a5, a10);

    if (Slot04())
    {
        if (!pOther->Slot04() && pOther->FUN_00eb6b70())
        {
            --adDepthB;
            int b = Intersect(pOther->m_0x80, a2, a3, a4, a5, aiDepthA, adDepthB, aiBoundsIdA, aiBoundsIdB, a10);
            if (b >= 1)
                return b;
            b = Intersect(pOther->m_0x84, a2, a3, a4, a5, aiDepthA, adDepthB, aiBoundsIdA, aiBoundsIdB, a10);
            if (1 <= b)
                return b;
            goto fail;
        }
        int b;
        b = NiOBBNode_BoxBoxCollision(pOther, a2, a3, a4, a5, a10);
        if (b >= 1)
            return b;
        goto fail;
    }
    else
    {

        if (pOther->Slot04())
        {
            RayTree* child = m_0x80;
            if (!child || !m_0x84)
            {
                int result = NiOBBNode_BoxBoxCollision(pOther, a2, a3, a4, a5, a10);
                _ReadWriteBarrier();
                return result;
            }
            static_cast<volatile int&>(aiDepthA) = aiDepthA - 1;
            int b = child->Intersect(pOther, a2, a3, a4, a5, aiDepthA, adDepthB, aiBoundsIdA, aiBoundsIdB, a10);
            if (1 <= b)
                return b;
            b = m_0x84->Intersect(pOther, a2, a3, a4, a5, aiDepthA, adDepthB, aiBoundsIdA, aiBoundsIdB, a10);
            if (1 <= b)
                return b;
            goto fail;
        }
        else
        {
            RayTree* child = m_0x80;

            static_cast<volatile int&>(aiDepthA) = aiDepthA - 1;
            if (!child || !m_0x84)
                return NiOBBNode_BoxBoxCollision(pOther, a2, a3, a4, a5, a10);
            int b = child->Intersect(pOther, a2, a3, a4, a5, aiDepthA, adDepthB, aiBoundsIdA, aiBoundsIdB, a10);
            if (b >= 1)
                return b;
            b = m_0x84->Intersect(pOther, a2, a3, a4, a5, aiDepthA, adDepthB, aiBoundsIdA, aiBoundsIdB, a10);
            if (1 <= b)
                return b;
        }
    }
fail:
    return 0;
}

static __forceinline float dotProduct(const V3& a, const V3& b)
{
    return a.y * b.y + a.x * b.x + a.z * b.z;
}
struct RayNodeW7_Derived : RayNodeW7
{
    void NiOBBNode_DivideTriangles(const V3* vertices, int first, int last, const int* srcIndices, int* outLeft, int* outRight,
                      int* dstIndices);
};

// @fnv 0x00eb8dc0
// src: GAMEBRYO_LIB 0x00eb8dc0
void RayNodeW7_Derived::NiOBBNode_DivideTriangles(const V3* vertices, int first, int last, const int* srcIndices, int* outLeft,
                                     int* outRight, int* dstIndices)
{

    int axes = (first + last) / 2;
    *outLeft = first - 1;
    *outRight = last + 1;

    const V3* mid = &matrix.row0;
    int axis = 0;
    do
    {
        if (*outLeft >= first && *outRight <= last)
        {
            break;
        }
        *outLeft = first - 1;
        *outRight = 1 + last;
        __assume(first <= last);
        for (int k = first; k <= last; ++k)
        {
            int idx = srcIndices[k];
            const V3& point = vertices[idx];
            V3 diff;
            diff = point - center;
            float proj = dotProduct(diff, mid[axis]);
            if (proj > 0.0f)
            {
                dstIndices[++*outLeft] = idx;
            }
            else if (proj < 0.0f)
            {
                dstIndices[--*outRight] = idx;
            }
            else if (k <= axes)
            {
                dstIndices[++*outLeft] = idx;
            }
            else
            {
                dstIndices[--*outRight] = idx;
            }
        }
        axis += 1;
    } while (axis < 3);

    if (axis == 3)
    {
        if (*outLeft < first || *outRight > last)
        {
            *outLeft = axes;
            *outRight = 1 + axes;
            for (int k = first; k <= last; ++k)
            {
                dstIndices[k] = srcIndices[k];
            }
        }
    }
}

struct S00eb9fa0_Pool
{
    void* Game_DoHeapAlloc(unsigned int s);
};
extern S00eb9fa0_Pool DAT_011f6238;
struct BuildBox
{
    MyContext context;
    BuildBox()
    {
        context.unk78 = 0;
    }
};
struct S00eb9fa0_Node
{
    BuildBox box;
    S00eb9fa0_Node* m_0x80;
    S00eb9fa0_Node* m_0x84;
    int m_0x88;
    virtual ~S00eb9fa0_Node();
    static void* operator new(unsigned int s)
    {
        return DAT_011f6238.Game_DoHeapAlloc(s);
    }
    S00eb9fa0_Node()
    {
        m_0x80 = 0;
        m_0x84 = 0;
        m_0x88 = 0;
    }
    void ComputeTriangleBounds(void* a0, const unsigned short* a1, const V3* a2, float* a3, V3* a4, int iStart,
                               int iEnd, int* a7);
    __declspec(noalias) void NiOBBNode_DivideTriangles(V3* a5, int iStart, int iEnd, int* a7, int* piMid, int* piRight, int* a8);
    void BuildNode(void* a0, const unsigned short* a1, const V3* a2, const V3* a3, float* a4, V3* a5, int iStart,
                   int iEnd, int* a7, int* a8, int iMin);
};
struct S00eb9fa0_Leaf : S00eb9fa0_Node
{
    int unk8c;
    int unk90;
    int unk94;
    S00eb9fa0_Leaf(void* a0, const unsigned short* a1, const V3* a2, const V3* a3, unsigned short tri) throw();
};
// Recursively partitions the inclusive range [iStart, iEnd] into child nodes or leaves stored in m_0x80 and m_0x84.
// @fnv 0x00eb9fa0
void S00eb9fa0_Node::BuildNode(void* a0, const unsigned short* apIndices, const V3* apVertices, const V3* a3, float* a4,
                               V3* a5, int iStart, int iEnd, int* a7, int* apOrder, int iMin)
{
    ComputeTriangleBounds(a0, apIndices, apVertices, a4, a5, iStart, iEnd, a7);
    if (iEnd - iStart < iMin)
    {
        m_0x80 = 0;
        m_0x84 = 0;
        return;
    }
    {
        int iSplit, iNext;
        {
            int iMid, iRight;
            NiOBBNode_DivideTriangles(a5, iStart, iEnd, a7, &iMid, &iRight, apOrder);
            iSplit = iMid;
            iNext = iRight;
        }
        if (iStart < iSplit)
        {
            S00eb9fa0_Node* pLeft = new S00eb9fa0_Node;
            m_0x80 = pLeft;
            pLeft->BuildNode(a0, apIndices, apVertices, a3, a4, a5, iStart, iSplit, apOrder, a7, iMin);
        }
        else if (iStart == iSplit)
        {
            m_0x80 = new S00eb9fa0_Leaf(a0, apIndices, apVertices, a3, (unsigned short)apOrder[iStart]);
        }
        if (iNext < iEnd)
        {
            if (m_0x80)
            {
                S00eb9fa0_Node* child = new S00eb9fa0_Node;
                m_0x84 = child;
                child->BuildNode(a0, apIndices, apVertices, a3, a4, a5, iNext, iEnd, apOrder, a7, iMin);
            }
            else
            {
                S00eb9fa0_Node* child = new S00eb9fa0_Node;
                m_0x84 = child;
                child->BuildNode(a0, apIndices, apVertices, a3, a4, a5, iNext, iEnd, apOrder, a7, iMin);
            }
        }
        else if (iNext == iEnd)
        {
            m_0x84 = new S00eb9fa0_Leaf(a0, apIndices, apVertices, a3, (unsigned short)apOrder[iEnd]);
        }
    }
}
