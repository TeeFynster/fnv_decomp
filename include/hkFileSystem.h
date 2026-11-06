#pragma once

#include "hkReferencedObject.h"
#include "hkSingleton.h"

class hkStreamWriter;

class hkFileSystem : public hkReferencedObject, public hkSingleton<hkFileSystem>
{
public:
    virtual ~hkFileSystem();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual void v0c();
    virtual hkStreamWriter* OpenWriter(const char* pcName) throw();
    virtual int FUN_00624e70(const char*, void*);
};
