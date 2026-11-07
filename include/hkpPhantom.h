#pragma once

#include "hkpWorldObject.h"
#include "hkaAnimation.h"

class hkpPhantomOverlapListener;
struct OverlapCollidable;
struct OverlapResult;

class hkpPhantom : public hkpWorldObject
{
public:
    virtual ~hkpPhantom() throw();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual int getType() const;
    virtual void vf06();
    virtual void add(OverlapCollidable* collidable);
    virtual OverlapResult overlaps(OverlapCollidable* collidable);
    virtual void remove(OverlapCollidable* collidable);
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void FreeListenerArrays() throw();

    void vfunc04();
    void vfunc08();
    void vfunc0C();
    void* vfunc10();
    void vf0C();
    void firePhantomAdded();
    void addPhantomOverlapListener_00d07de0(hkpPhantomOverlapListener* listener);
    void removePhantomOverlapListener_00d07c80(hkpPhantomOverlapListener* listener) throw();

    void addPhantomOverlapListener(hkpPhantomOverlapListener* listener);
    void removePhantomOverlapListener(hkpPhantomOverlapListener* listener) throw();
    void firePhantomRemoved();

    hkArray<void*> m_kPhantomOverlapListeners;
    hkArray<void*> m_kPhantomListeners;
};
