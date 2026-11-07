#pragma once

#include "hkpWorldViewerBase.h"
#include "hkpWorldPostSimulationListener.h"

class Cont;
class hkpSimulationIsland;

class hkpContactPointViewer : public hkpWorldViewerBase,
                              public hkpWorldPostSimulationListener
{
public:
    hkpContactPointViewer(void* owner, void* userData);
    __forceinline virtual ~hkpContactPointViewer() throw();
    virtual void vf03() = 0;

    virtual void init();
    virtual void postSimulationCallback(hkpWorld* world);

    void DestroyContactPointViewer() throw();
    void ProcessSpawnedList();
    void drawAllContactPointsInIsland_00de2da0(Cont* island);
    void drawAllContactPointsInIsland_00de2da0(void* island);
    void drawAllContactPointsInIsland(hkpSimulationIsland* island);

    float m_uiFilterValue;
    void* m_ulUserData;
};
