#pragma once

#include "NiMemObject.h"

// RTTI (.?AVNiRefObject@@): base NiMemObject, which supplies operator new (0x00aa13e0) and the sized delete (0x00aa1460).
class NiRefObject : public NiMemObject
{
  public:
    unsigned int m_uiRefCount;

    NiRefObject();
    virtual ~NiRefObject();
    virtual void DeleteThis();

    void IncRefCount();
    void DecRefCount();
    void AcquireReference();
    void DecRef();
    unsigned int GetRefCount() const
    {
        return m_uiRefCount;
    }
    void IncrementReferenceCount();
    void DecrementReferenceCount();

    static unsigned int ms_lObjectCount;
};
