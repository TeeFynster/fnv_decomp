#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "hkProcess.h"
#include "hkpPhysicsContextWorldListener.h"

#include "hkArray.h"
class hkProcessContext;
class hkpPhysicsContext;
class ContactArray;

class hkpWorldViewerBase : public hkReferencedObject,
                           public hkProcess,
                           public hkpPhysicsContextWorldListener
{
public:
    hkpWorldViewerBase(const hkArray<hkProcessContext*>& contexts) throw();
    hkpWorldViewerBase(const void* contexts) throw();
    virtual ~hkpWorldViewerBase() throw();

    static void* __cdecl operator new(std::size_t nbytes);

    void FUN_00ddcc60() throw();

    union
    {
        hkpPhysicsContext* m_iValueAtOffset0C;
        ContactArray* contacts;
    };
};
