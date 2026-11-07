
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/NiPoint3.h"
#include "../../../../../include/NiTriShapeData.h"

// Preserve the original noalias contract, absent from the shared static method declaration.
__declspec(noalias) void __cdecl NiPoint3_UnitizeVector(NiPoint3& kPt);

inline NiPoint3::NiPoint3(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}

inline NiPoint3 NiPoint3::operator-(const NiPoint3& pt) const
{
    return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
}

inline NiPoint3 NiPoint3::Cross(const NiPoint3& pt) const
{
    return NiPoint3(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
}

class NiTriShapeData__SharedNormalArray
{
  public:
    unsigned short m_usNormalCount;
    unsigned short* m_pusNormalIndices;
};

// @fnv 0x00a8ed40
void NiTriShapeData::RecalculateNormals()
{
    EnsureNormals(true);
    unsigned short* pusTriList = m_pusTriList;
    // Slot 42 returns the triangle count; the shared declaration currently returns void.
    typedef unsigned short (__thiscall *TriangleCountQuery)(NiTriShapeData*);
    unsigned short usTriangleCount =
        reinterpret_cast<TriangleCountQuery>((*reinterpret_cast<void***>(this))[42])(this);
    for (unsigned short i = 0; i < usTriangleCount; i++)
    {
        unsigned short usIndex0 = *pusTriList++;
        unsigned short usIndex1 = *pusTriList++;
        unsigned short usIndex2 = *pusTriList++;
        NiPoint3 kEdge1 = m_pkVertex[usIndex1] - m_pkVertex[usIndex0];
        NiPoint3 kEdge2 = m_pkVertex[usIndex2] - m_pkVertex[usIndex1];
        NiPoint3 kFaceNormal = kEdge1.Cross(kEdge2);
        NiPoint3_UnitizeVector(kFaceNormal);
        m_pkNormal[usIndex0] += kFaceNormal;
        m_pkNormal[usIndex1] += kFaceNormal;
        m_pkNormal[usIndex2] += kFaceNormal;
        if (m_pkSharedNormals && m_usSharedNormalsArraySize == m_usVertices)
        {
            unsigned short* pusSharedIndices = m_pkSharedNormals[usIndex0].m_pusNormalIndices;
            unsigned short usSharedCount = m_pkSharedNormals[usIndex0].m_usNormalCount;
            while (usSharedCount)
            {
                usSharedCount--;
                m_pkNormal[pusSharedIndices[usSharedCount]] += kFaceNormal;
            }
            pusSharedIndices = m_pkSharedNormals[usIndex1].m_pusNormalIndices;
            usSharedCount = m_pkSharedNormals[usIndex1].m_usNormalCount;
            while (usSharedCount)
            {
                usSharedCount--;
                m_pkNormal[pusSharedIndices[usSharedCount]] += kFaceNormal;
            }
            pusSharedIndices = m_pkSharedNormals[usIndex2].m_pusNormalIndices;
            usSharedCount = m_pkSharedNormals[usIndex2].m_usNormalCount;
            while (usSharedCount)
            {
                usSharedCount--;
                m_pkNormal[pusSharedIndices[usSharedCount]] += kFaceNormal;
            }
        }
    }
    NiPoint3::NormalizePoints(m_pkNormal, GetVertexCount(), sizeof(NiPoint3));
    SetDirtyFlags(2);
}
