#pragma once

#include "NiTask.h"
#include <stddef.h>

class MorphController;
class FakeGeo;

class NiGeomMorpherUpdateTask : public NiTask
{
public:
    NiGeomMorpherUpdateTask();
    virtual ~NiGeomMorpherUpdateTask();
    virtual const NiRTTI* GetRTTI() const;
    virtual void vf35();
    virtual bool vf37();

    void FUN_00a56bb0();
    static void* operator new[](size_t size, unsigned int count);

    MorphController* m_pkMorphController;
    FakeGeo* m_spReferencedObject;
};
