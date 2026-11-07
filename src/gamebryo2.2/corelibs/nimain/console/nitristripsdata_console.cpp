
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/NiPoint3.h"
#include "../../../../../include/NiTriStripsData.h"

// Preserve the original noalias contract, absent from the shared static method declaration.
__declspec(noalias) void __cdecl NiPoint3_UnitizeVector(NiPoint3& kPt);

inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}

inline NiPoint3 NiPoint3::operator-(const NiPoint3& pt) const
{
    return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
}

inline NiPoint3 NiPoint3::Cross(const NiPoint3& pt) const
{
    return NiPoint3(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
}

// @fnv 0x00a8ab40
void NiTriStripsData::GenerateNormals()
{
    EnsureNormals(1);

    unsigned short* pusStripList = m_pusStripLists;
    for (unsigned short usStrip = 0; usStrip < m_usStrips; usStrip++)
    {
        for (unsigned short usIndex = 2; usIndex < m_pusStripLengths[usStrip]; usIndex++)
        {
            unsigned short usIndex0, usIndex1, usIndex2;
            if (usIndex % 2 == 0)
            {
                usIndex0 = pusStripList[usIndex - 2];
                usIndex1 = pusStripList[usIndex - 1];
                usIndex2 = pusStripList[usIndex];
            }
            else
            {
                usIndex0 = pusStripList[usIndex - 2];
                usIndex1 = pusStripList[usIndex];
                usIndex2 = pusStripList[usIndex - 1];
            }

            if (usIndex0 == usIndex1 || usIndex1 == usIndex2 || usIndex2 == usIndex0)
                continue;

            const NiPoint3& kVertex0 = m_pkVertex[usIndex0];
            const NiPoint3& kVertex1 = m_pkVertex[usIndex1];
            const NiPoint3& kVertex2 = m_pkVertex[usIndex2];
            NiPoint3 kEdge1 = kVertex1 - kVertex0;
            NiPoint3 kEdge2 = kVertex2 - kVertex1;
            NiPoint3 kNormal = kEdge1.Cross(kEdge2);
            NiPoint3_UnitizeVector(kNormal);

            m_pkNormal[usIndex0] += kNormal;
            m_pkNormal[usIndex1] += kNormal;
            m_pkNormal[usIndex2] += kNormal;
        }
        pusStripList += m_pusStripLengths[usStrip];
    }

    NiPoint3::NormalizePoints(m_pkNormal, m_usVertices, sizeof(NiPoint3));
    SetDirtyFlags(2);
}
