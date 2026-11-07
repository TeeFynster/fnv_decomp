#pragma once

#include "hkpBvTreeShape.h"
#include "hkVector4_X.h"

class hkpMoppCode;

class hkMoppBvTreeShapeBase : public hkpBvTreeShape
{
public:
    static const ClassMemberDescriptor Members[];

    virtual ~hkMoppBvTreeShapeBase() throw();

    int queryAabbImpl(const hkAabb& aabbIn, unsigned int* hits, int maxNumKeys) const;

    const hkpMoppCode* m_pMoppCode;
    unsigned char* m_pMoppData;
    int m_uiMoppDataSize;
    hkVector4_X m_kMoppCodeInfo;
};
