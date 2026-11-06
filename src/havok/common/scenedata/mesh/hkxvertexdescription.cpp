
// src/havok/common/scenedata/mesh/hkxvertexdescription.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/mesh/hkxvertexdescription.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkxVertexDescription.h"

// Twelve-byte vertex element: byte offset at 0, type at 4, usage at 6, and byte stride at 8.
class hkxVertexDescriptionElementDecl
{
  public:
    unsigned int m_uiByteOffset;
    unsigned short m_type;
    unsigned short m_eDataUsage;
    unsigned int m_uiByteStride;

    bool operator==(const hkxVertexDescriptionElementDecl& o) const
    {
        return m_type == o.m_type && m_eDataUsage == o.m_eDataUsage && m_uiByteOffset == o.m_uiByteOffset &&
               m_uiByteStride == o.m_uiByteStride;
    }
};

// 0x00e3dee0 compares vertex descriptions; this method-only helper adds no fields to the shared layout.
class VertexDescriptionComparison : public hkxVertexDescription
{
  public:
    bool Equals(const hkxVertexDescription& o) const;
};

// Compares two lists: returns false if their counts differ or any corresponding entry differs, otherwise true.
// @fnv 0x00e3dee0
bool VertexDescriptionComparison::Equals(const hkxVertexDescription& aOther) const
{
    if (m_kElementDeclarations.m_iElementCount == aOther.m_kElementDeclarations.m_iElementCount)
    {
        for (int iIndex = 0; iIndex < m_kElementDeclarations.m_iElementCount; iIndex++)
        {
            if (!(m_kElementDeclarations.m_data[iIndex] == aOther.m_kElementDeclarations.m_data[iIndex]))
                return false;
        }
        return true;
    }
    return false;
}
