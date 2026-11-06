#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "hkProcessContext.h"
#include "hkpWorldDeletionListener.h"
#include "hkpEntityListener.h"
#include "hkpPhantomListener.h"
#include "hkpConstraintListener.h"
#include "hkpActionListener.h"

class hkVisualDebugger;
class hkpWorld;

typedef std::size_t hk_size_t;

class hkpPhysicsContext :
    public hkReferencedObject,
    public hkProcessContext,
    public hkpWorldDeletionListener,
    public hkpEntityListener,
    public hkpPhantomListener,
    public hkpConstraintListener,
    public hkpActionListener
{
public:
    hkpWorld** m_ppWorlds;
    int m_numWorlds;

    static void* __cdecl operator new(hk_size_t nbytes);

    void SetOwnerPointer(hkVisualDebugger* vdb);

    int getNumWorlds() const;
    hkpWorld* getWorld(int i) const;

protected:
    virtual ~hkpPhysicsContext() throw();
};
