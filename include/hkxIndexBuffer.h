#pragma once

#include "hkReferencedObject.h"
#include "hkaAnimation.h"

typedef signed char hkInt8;
typedef short hkInt16;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

class hkxIndexBuffer : public hkReferencedObject
{
public:
    enum IndexType
    {
        INDEX_TYPE_INVALID = 0,
        INDEX_TYPE_TRI_LIST = 1,
        INDEX_TYPE_TRI_STRIP = 2,
        INDEX_TYPE_TRI_FAN = 3,
        INDEX_TYPE_MAX_ID = 4
    };

    hkInt8 m_eIndexType;
    hkInt8 unk09;
    hkInt16 unk0A;
    hkArray<hkUint16> m_kIndices16;
    hkArray<hkUint32> m_kIndices32;
    hkUint32 m_uiVertexBaseOffset;
    hkUint32 m_fRestLength;

    int GetPrimitiveCount() const;
    bool GetTriangleIndices(unsigned int offset, unsigned int& a, unsigned int& b, unsigned int& c) const;
};
