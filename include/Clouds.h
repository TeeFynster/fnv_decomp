#pragma once

#include "SkyObject.h"
#include "NiColor.h"

class NiGeometry;
class NiTexture;

class Clouds : public SkyObject
{
public:
    virtual ~Clouds();
    virtual void Initialize(NiNode*);
    virtual void Update(Sky*, float);

    int GetOffset58();
    NiColor& GetPointAt(int);
    void SetCloudCount(int);
    void ClearCloudLayers();
    void ForceTransTextureUpdate();

    NiPointer<NiGeometry> m_pCloudLayerGeometry[4];
    NiPointer<NiTexture> m_pCloudLayerTexture[4];
    NiColor pColors[4];
    unsigned short m_usCloudCount;
    bool bForceUpdate;
};
