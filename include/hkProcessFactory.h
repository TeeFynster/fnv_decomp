#pragma once

#include "hkReferencedObject.h"
#include "hkSingleton.h"

class hkInspectProcess;
class hkProcess;

class hkProcessFactory : public hkReferencedObject, public hkSingleton<hkProcessFactory>
{
public:
    hkInspectProcess* __thiscall RegisterProcess(const char*, void (__cdecl*)(hkProcess*));
    void* RegisterProcess(const char*, void*);
};
