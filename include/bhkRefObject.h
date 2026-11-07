#pragma once

#include <cstddef>
#include "NiObject.h"

class hkReferencedObject;

class bhkRefObject : public NiObject
{
public:
    bhkRefObject();
    virtual ~bhkRefObject();

    virtual void* GetReferencedData();
    virtual void* GetReferencedDataSafe();

    int Initialize();
    bhkRefObject* InitializeFields_00ccd100();
    void Destroy();
    void UpdateReference(bool);

    hkReferencedObject* m_pHavokObject;
};
