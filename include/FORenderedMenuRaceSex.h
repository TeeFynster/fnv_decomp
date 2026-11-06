#pragma once

#include "FORenderedMenu.h"

class MenuTile;
class PickCamera;

class FORenderedMenuRaceSex : public FORenderedMenu
{
public:
    struct NodePtr
    {
        NiNode* m_pObject;
        operator NiNode*() const;
    };

    virtual bool v6(bool abDown, int a2, int a3);
    virtual void vf21(float now);

    MenuTile* GetMenuTile();
    PickCamera* GetPickCamera();
    bool HandleRaceSexMenuInput(bool abDown, int a2, int a3);

    NodePtr unkD8[4];
    NodePtr unkE8[4];
};
