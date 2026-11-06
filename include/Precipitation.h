#pragma once

#include "NiAVObject.h"

class NiNode;
class SkyShaderProperty;
struct PrecipQueuedObject;

class Precipitation
{
public:
    Precipitation();
    virtual ~Precipitation();

    void* DestroyIfFlagged(unsigned int flags);
    void InitParent();
    void QueuePrecipitationObject(PrecipQueuedObject* object);

    NiPointer<NiNode> m_pPrecipitationNode;
    NiPointer<NiNode> m_pPreviousNode;
    NiNode* pParent;
    float fEmissionRate;
    const void* m_pPrecipitationData;

    void Load(const char* path);
    NiAVObject* CreateParticleShape(SkyShaderProperty* property, NiAVObject* object);
    void Update(float secondsPassed);
    void FlushAll();
};
