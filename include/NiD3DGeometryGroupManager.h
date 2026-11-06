#pragma once

#include "NiGeometryGroupManager.h"

class Direct3DDeviceInterface;
class NiGeometryGroup;
class VertexDeclarationLayout;

class NiD3DGeometryGroupManager : public NiGeometryGroupManager
{
public:
    void Initialize();
    void SetFlag(bool flag);
    NiGeometryGroup* CreateGroup(NiGeometryGroupManager::RepackingBehavior);
    static NiD3DGeometryGroupManager* Create(Direct3DDeviceInterface*, VertexDeclarationLayout*);

    unsigned int* m_04;
    unsigned int m_08;
    unsigned int m_0c;
    Direct3DDeviceInterface* m_10;
    VertexDeclarationLayout* m_14;
    bool m_18;
};
