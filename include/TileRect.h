#pragma once

#include "Tile.h"

class NiAVObject;

class TileRect : public Tile
{
  public:
    TileRect();
    virtual ~TileRect();
    virtual void Init(Tile* parent, const char* name, Tile* replacedChild);
    virtual NiNode* CalculateNode();
    virtual int GetType();
    virtual const char* GetTypeStr();
    virtual Tile* SetTraitValue(int valueID, float floatValue, const char* strValue);

    const char* GetTypeName();
    NiNode* GetAttachModel() const;
    NiAVObject* GetExtraDataModel() const;
    const char* FUN_00709970();

    bool m_bTextureLoaded;
    unsigned char layoutPadding39[3];
};
