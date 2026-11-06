#pragma once

#include "TileRect.h"

class Menu;

class TileMenu : public TileRect
{
  public:
    TileMenu();
    virtual ~TileMenu();
    virtual void Init(Tile* parent, const char* name, Tile* replacedChild);
    virtual NiNode* CalculateNode();
    virtual int GetType();
    virtual const char* GetTypeStr();
    virtual bool Unk_05(float arg0, float arg1);
    virtual Tile* SetTraitValue(int valueID, float floatValue, const char* strValue);
    virtual void ClearTextures();
    virtual TileShaderProperty* GetShaderProperty();
    virtual void SetAlphaAndOverlayColor(NiNode* node, float alpha, NiColorAlpha* color);

    TileMenu* __thiscall TileMenuConstructor(int aiUnused1, int aiUnused2);
    float GetTraitFloat(int id);
    void FUN_00a20610(int iValue);

    union
    {
        Menu* unk3c;
        Menu* pMenu;
        Menu* menu;
    };
};
