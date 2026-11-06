#pragma once

#include "hkReferencedObject.h"
#include "hkSingleton.h"

class hkClass;

class hkVtableClassRegistry : public hkReferencedObject, public hkSingleton<hkVtableClassRegistry>
{
public:
    virtual void RegisterVtable(const void*, const hkClass*);
    virtual const hkClass* GetClassFromVirtualInstance(const void*) const;
    virtual void vf05();

    unsigned long LookupClassByVtable(const unsigned long* p);
};
