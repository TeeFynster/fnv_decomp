#pragma once

#include "Tile.h"
#include "NiAVObject.h"

class NiTexture;
class TileShaderProperty;

class TileImage : public Tile
{
  public:
    TileImage();
    virtual ~TileImage();
    virtual void Init(Tile* parent, const char* name, Tile* replacedChild);
    virtual NiNode* CalculateNode();
    virtual int GetType();
    virtual const char* GetTypeStr();
    virtual bool Unk_05(float arg0, float arg1);
    virtual Tile* SetTraitValue(int valueID, float floatValue, const char* strValue);
    virtual void ClearTextures();
    virtual TileShaderProperty* GetShaderProperty();
    virtual void SetAlphaAndOverlayColor(NiNode* node, float alpha, NiColorAlpha* color);

    const char* GetImageTag();
    void UpdateTileImage();
    void SetTexture(NiAVObject* texture);
    void SetTexture(NiTexture* texture);

    NiNode* GetNiNode();
    using Tile::FUN_00a011b0;
    float FUN_00a011b0(unsigned int trait, int value);
    void Tile_FinalPostParse(unsigned int trait, float value);

    static void ReadFloatAttribute(const char* name, float& value, float defaultValue, char* buffer);
    static void ReadTextureAttribute(const char* name, float& value, NiPointer<NiTexture>& texture,
                                     float defaultValue, NiPointer<NiTexture> defaultTexture);

    float fScale;
    NiPointer<NiTexture> spTexture;
    NiPointer<TileShaderProperty> m_spShaderProperty;
    bool m_bTextureLoaded;
    unsigned char unk45[3];
};
