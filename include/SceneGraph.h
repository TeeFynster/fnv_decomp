#pragma once

#include "BSSceneGraph.h"

class NiCamera;

class SceneGraph : public BSSceneGraph
{
  public:
    SceneGraph(const char* name, bool menuSceneGraph, NiCamera* camera);

    virtual const NiRTTI* GetRTTI() const;

    NiCamera* GetCamera();
    static const NiRTTI ms_kRTTI;

    char _pad_ac[0x14];
};
