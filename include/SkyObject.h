#pragma once

#include "NiNode.h"

class Sky;

class SkyObject
{
public:
    SkyObject();
    virtual ~SkyObject();
    virtual NiNode* GetRoot();
    virtual void Initialize(NiNode* pRoot);
    virtual void Update(Sky* pWeatherSky, float fSeconds);

    NiNode* GetRoot() const;
    void SetDisplayObject(bool bDisplay);
    void Update(unsigned int, unsigned int);
    void __thiscall Update(Sky*, int);
    template <class SkyType> void __thiscall Update(SkyType*, int);
    void Update(float, int);
    void __thiscall Update(int, int);

    NiPointer<NiNode> m_pRootNode;
};
