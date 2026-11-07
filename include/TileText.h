#pragma once

#include "NiPoint3.h"  // before Tile.h, which includes ShadowSceneLight.h inside an __if_exists block
#include "Tile.h"
#include "Tile3D.h"

class TextNode;

class TileText : public Tile
{
  public:
    TileText(Tile3D* parent = 0);
    virtual ~TileText();
    virtual void Init(Tile* parent, const char* name, Tile* replacedChild);
    virtual NiNode* CalculateNode();
    virtual int GetType();
    virtual const char* GetTypeStr();
    virtual Tile* SetTraitValue(int valueID, float floatValue, const char* strValue);

    TextNode* GetNiNode();
    const char* GetTypeName_00a0bbe0();

    void SetPosition(const NiPoint3& p)
    {
        *reinterpret_cast<NiPoint3*>(&unk3c) = p;
    }

    unsigned int unk38;
    int unk3c;
    int unk40;
    int unk44;
    union
    {
        char unk48;
        bool multibyte;
    };
};
