#pragma once

#include <cstddef>
#include "CodeInfo.h"
#include "hkReferencedObject.h"
#include "hkVector4_X.h"
#include "hkaAnimation.h"
#include "hkpShape.h"

typedef unsigned char hkUint8;
typedef signed char hkInt8;

class hkpMoppCode : public hkReferencedObject
{
public:
    enum BuildType
    {
        BUILT_WITH_CHUNK_SUBDIVISION = 0,
        BUILT_WITHOUT_CHUNK_SUBDIVISION = 1,
        BUILD_NOT_SET = 2
    };

    typedef ::CodeInfo CodeInfo;

    hkpMoppCode() throw();
    virtual ~hkpMoppCode() throw();

    static void* __cdecl operator new(std::size_t nbytes);

    unsigned char unk08[8];
    CodeInfo m_info;
    hkArray<hkUint8> m_data;
    hkEnum<BuildType, hkInt8> m_eBuildType;
    unsigned char unk2D[3];
};
