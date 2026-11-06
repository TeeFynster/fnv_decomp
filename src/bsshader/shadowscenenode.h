#ifndef FNV_SHADOWSCENENODE_H
#define FNV_SHADOWSCENENODE_H

#include "shadowscenenode_fog_decls.h"

// @fnv 0x00b54110
void ShadowSceneNode::SetFogPropertyForIndex(BSFogProperty* property)
{
    if (!property)
    {
        spFog = new BSFogProperty;
        spFog->SetFog(500000.0f, 500000.0f);
        spFog->SetPower(1.0f);
        spFog->SetWaterFog(500000.0f, 500000.0f);
        spFog->color = NiColor(0.5f, 0.5f, 0.5f);
        spFog->SetWaterColor(NiColor(0.5f, 0.5f, 0.5f));
    }
    else
    {
        spFog = property;
    }
}
#endif
