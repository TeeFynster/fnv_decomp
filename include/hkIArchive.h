#pragma once

#include "hkReferencedObject.h"

class hkIArchive : public hkReferencedObject
{
public:
    virtual ~hkIArchive();

    void ReleaseArchiveReader();
    void hkIArchive_readArrayGeneric(void* destination, int componentSize, int components);

    hkReferencedObject* m_streamReader;
};
